import os
import math
import pickle

from common.Dataset import Dataset
from common.Helpers import calc_candidate_thresholds
import common.Logger as CommonLogger

MIN_SAMPLES_LEAF = None
MIN_SAMPLES_LEAF_KARY = None

def calc_info_gain_on_kary_split(parentset, feature_type, use_gini=False):
    value_domain = None

    if parentset.value_domains is not None:
        value_domain = parentset.value_domains[feature_type.name]
    else:
        value_domain = feature_type.value_domain

    subsets = []

    weighted_child_values = 0.0

    if type(feature_type.value_domain) == set:
        for value in value_domain:
            subset = Dataset.subset_with_feature_filter(parentset, [feature_type == value])

            if subset.size == 0:
                continue

            if subset.size < MIN_SAMPLES_LEAF_KARY:
                return 0.0

            if use_gini:
                weighted_child_values += (subset.size / parentset.size) * subset.gini
            else:
                weighted_child_values += (subset.size / parentset.size) * subset.entropy
    else:
        raise ValueError(f"calc_info_gain_on_kary_split called with a non-set value domain: {feature_type}")

    gain = None

    if use_gini:
        gain = parentset.entropy - weighted_child_values
    else:
        gain = parentset.gini - weighted_child_values

    return gain

def calculate_gain_from_counts(l_pos, l_neg, r_pos, r_neg, parent_score, use_gini):
    n_l = l_pos + l_neg
    n_r = r_pos + r_neg
    total = n_l + n_r

    if n_l == 0 or n_r == 0: return 0.0

    def get_score(pos, neg, n):
        if n == 0: return 0.0
        p_pos = pos / n
        p_neg = neg / n
        if use_gini:
            return 1.0 - (p_pos**2 + p_neg**2)
        else:
            # entropy
            ent = 0
            if p_pos > 0: ent -= p_pos * math.log2(p_pos)
            if p_neg > 0: ent -= p_neg * math.log2(p_neg)
            return ent

    weighted_child_score = (n_l / total) * get_score(l_pos, l_neg, n_l) + \
                           (n_r / total) * get_score(r_pos, r_neg, n_r)

    return parent_score - weighted_child_score

def evaluate_info_gains(dataset, use_gini=False):
    best_gain = 0.0
    best_split = None

    feature_names = list(dataset.feature_types.keys())

    feature_names_nolabel = list(feature_names)
    feature_names_nolabel.pop(dataset.label_idx)

    dataset.calc_positive_counts()

    count_pos = None

    if dataset.majority_label[0] == True :
        count_pos = dataset.majority_label[1]
    else:
        count_pos = dataset.size - dataset.majority_label[1]

    count_neg = dataset.size - count_pos

    for fname in feature_names_nolabel:
        ftype = dataset.feature_types[fname]

        if ftype.is_numeric:
            sorted_instances = sorted(dataset.instances, key=lambda x: getattr(x, fname))
            l_pos, l_neg = 0, 0
            r_pos, r_neg = count_pos, count_neg

            for i in range(dataset.size - 1):
                # update counters while moving split point to the right
                if sorted_instances[i].label == True:
                    l_pos += 1
                    r_pos -= 1
                else:
                    l_neg += 1
                    r_neg -= 1

                val_curr = getattr(sorted_instances[i], fname)
                val_next = getattr(sorted_instances[i+1], fname)

                if sorted_instances[i].label != sorted_instances[i+1].label and val_curr < val_next:
                    # calculate gain using pos,neg counts from left of the split and right of the split
                    gain = calculate_gain_from_counts(
                        l_pos, l_neg, r_pos, r_neg,
                        dataset.entropy if not use_gini else dataset.gini,
                        use_gini
                    )

                    if gain > best_gain:
                        best_gain = gain
                        best_split = ("numeric", ftype, (val_curr + val_next) / 2)

        else:
            # categorical
            gain = calc_info_gain_on_kary_split(dataset, ftype, use_gini)
            if gain > best_gain:
                best_gain = gain
                best_split = ("categorical", ftype, None)

    return (best_gain, best_split)

def export_tree_to_dot(root, dot_outfile):
    lines = []
    lines.append("digraph DecisionTree {")
    lines.append("  rankdir=TB;")  # vertical layout
    lines.append("  node [shape=box, fontsize=10, height=0.3, width=0.3];")
    lines.append("  edge [fontsize=9];")

    node_id_counter = [0]

    def next_id():
        node_id_counter[0] += 1
        return f"n{node_id_counter[0]}"

    def escape(text):
        return text.replace('"', '\\"')

    def add_node(node):
        node_id = next_id()

        if node.is_leaf:
            pred = escape(str(node.prediction))
            label = f"{pred}\\n({node.n_pred}/{node.n_samples})"
            lines.append(f'  {node_id} [label="{label}", shape=ellipse];')
            return node_id

        feat_name = escape(node.feature_type.name)
        label = f"{feat_name}\\nn = {node.n_samples}"

        lines.append(f'  {node_id} [label="{label}"];')

        if node.is_categorical:
            for val, child in node.children.items():
                child_id = add_node(child)
                lines.append(
                    f'  {node_id} -> {child_id} [label="{escape(str(val))}"];'
                )

        else:  # numeric
            thr = node.threshold
            left = node.children.get("left")
            right = node.children.get("right")

            if left:
                left_id = add_node(left)
                lines.append(
                    f'  {node_id} -> {left_id} [label="≤ {thr}"];'
                )
            if right:
                right_id = add_node(right)
                lines.append(
                    f'  {node_id} -> {right_id} [label="> {thr}"];'
                )

        return node_id

    add_node(root)
    lines.append("}")

    out_path = os.path.normpath(dot_outfile)
    directory, filename = os.path.split(out_path)
 
    if directory != '' and not os.path.exists(directory):
        os.makedirs(directory)
 
    with open(out_path, "w") as f:
        f.write("\n".join(lines))

    CommonLogger.logger.log(f"Exported tree as DOT to {out_path}")
    yield
