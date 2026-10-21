import math
from common.Dataset import Dataset
import common.Logger as CommonLogger

def extract_thresholds(dataset, segment_map, split_count):
    thresholds = []

    values = [getattr(instance, dataset.sorted_on) for instance in dataset.instances]

    cur_seg_end = len(values) - 1
    bin_count   = split_count + 1

    # go backwards from segment end to start, get the threshold for the seg start
    # since the segment threshold covers instances until seg end
    # and decrease bin count while doing this,
    # since because every aggregation forms a bin
    while bin_count > 1:
        seg_start  = segment_map[bin_count][cur_seg_end]

        threshold = (values[seg_start] + values[seg_start + 1]) / 2
        thresholds.append(round(threshold, 6))

        cur_seg_end = seg_start
        bin_count -= 1

    return sorted(thresholds)

def discretize(dataset, split_count, min_frac=0.1):
    dataset.calc_positive_counts()
    desired_bin_count = split_count + 1

    # min amount of values a bin should have, to cover min_frac of all values
    MIN_BIN_SIZE = max(1, int(min_frac * dataset.size))

    if MIN_BIN_SIZE == 0:
        MIN_BIN_SIZE = 1

    pos_counts = dataset.positive_counts
    w0, w1 = dataset.entropy_weights

    feature_name = dataset.sorted_on
    vals = [getattr(inst, feature_name) for inst in dataset.instances]
    labels = [1 if inst.label else 0 for inst in dataset.instances]

    N = dataset.size

    boundaries = []

    for i in range(N - 1):
        if labels[i] != labels[i+1] and vals[i] < vals[i+1]:
            # only consider as a boundary if label and value changes
            boundaries.append(i)

    # cost_map[b][i] = cost of using b bins to cover instances[0..i] (inclusive)
    cost_map = [[float("inf")] * N for _ in range(desired_bin_count + 1)]

    # segment_map[b][i] = index t where last bin is [t+1 .. i] (inclusive)
    segment_map = [[None] * N for _ in range(desired_bin_count + 1)]

    # base case
    for i in range(MIN_BIN_SIZE - 1, N):
        cost_map[1][i] = dataset.calc_segment_cost(0, i)

    infostr = f"Discretizing {feature_name}... trying split count"

    # DP
    for b in range(2, desired_bin_count + 1):
        for seg_end in range(b * MIN_BIN_SIZE - 1, N):
            if seg_end % 100 == 0:
                CommonLogger.logger.log(infostr + f": {b - 1}/{desired_bin_count - 1}, seg_end: {seg_end}/{N}")
                yield
                CommonLogger.logger.backtrack(1)

            # only look at label-change boundaries
            for seg_start in boundaries:
                if (seg_end - seg_start) < MIN_BIN_SIZE:
                    # not enough elements
                    break

                if cost_map[b - 1][seg_start] == float("inf"):
                    # can't have a segment without a starting point
                    continue

                # skip if not enough room for previous bins
                if (seg_start + 1) < (b - 1) * MIN_BIN_SIZE:
                    continue

                prev_cost = cost_map[b-1][seg_start]
                if prev_cost == float("inf"):
                    continue

                cost = prev_cost + dataset.calc_segment_cost(seg_start + 1, seg_end)

                if cost < cost_map[b][seg_end]:
                    cost_map[b][seg_end] = cost
                    segment_map[b][seg_end] = seg_start

    if cost_map[desired_bin_count][N - 1] == float("inf"):
        return None, None

    costs = [cost_map[b][N - 1] for b in range(desired_bin_count + 1)]
    return costs, segment_map

def best_thresholds_for_feature(trainset, feature_name, max_split_count, min_bin_frac, delta_cost):
    best_cost            = float("inf")
    best_thresholds      = None

    dataset              = Dataset.sort_on_feature(trainset, feature_name)

    discretization_costs = None
    segment_map          = None
    split_count          = max_split_count

    while discretization_costs is None and split_count > 0:
        discretization_costs, segment_map = yield from discretize(dataset, split_count, min_bin_frac)

        if discretization_costs is None:
            split_count -= 1

    if not split_count:
        return None
    else:
        max_split_count = split_count

    best_cost        = float("inf")
    best_thresholds  = None
    best_split_count = 1

    for split_count in range(1, max_split_count + 1):
        current_split_cost = discretization_costs[split_count + 1]

        if (best_cost - current_split_cost) > delta_cost:
            best_cost = current_split_cost
            best_thresholds = extract_thresholds(dataset, segment_map, split_count)
            best_split_count = split_count

    CommonLogger.logger.log(f"Discretized {feature_name}: Selected {best_split_count} split(s) (best cost: {round(best_cost, 6)}, best thresholds: {best_thresholds})")
    yield
    return best_thresholds

def best_thresholds_for_features(dataset, max_split_count, min_bin_frac, delta_cost):
    threshold_map = {}

    CommonLogger.logger.log(f"Discretizing features, max_split_count: {max_split_count}, min_bin_frac: {min_bin_frac}, delta_cost: {delta_cost}")
    yield

    for feature_name, feature_type in dataset.feature_types.items():
        if feature_type.is_numeric:
            threshold_map[feature_name] = yield from best_thresholds_for_feature(dataset, feature_name, max_split_count, min_bin_frac, delta_cost)

    CommonLogger.logger.log("")

    return threshold_map
