import os
import pickle
from collections import Counter

import common.Logger as CommonLogger
import common.Utils as CommonUtils
import common.Discretizer as Discretizer

from common.Transaction import TransactionItemset

def get_F1(transactions, min_support):
    item_counts = Counter()

    for t in transactions:
        for item in t['itemset']:
            item_counts[item] += 1

    sorted_items = sorted(item_counts.items(), key=lambda x: str(x[0]))
    return {TransactionItemset([item]): count for item, count in sorted_items if (count / len(transactions)) >= min_support}

def generate_candidates(F_prev_keys, k):
    candidates = set()

    # Convert itemsets to sorted lists for prefix comparison
    # items inside TransactionItemset are already unique, sort them for a stable prefix
    list_of_itemsets = []

    for f in F_prev_keys:
        list_of_itemsets.append(sorted(list(f.items), key=lambda x: str(x)))

    list_of_itemsets.sort(key=lambda x: [str(item) for item in x])

    infostr = "Iterating through previous frequent itemsets... "

    n = len(list_of_itemsets)

    for i in range(n):

        if i % 500 == 0:
            CommonLogger.logger.log(infostr + f"{i}/{n}")
            yield
            CommonLogger.logger.backtrack(1)

        for j in range(i + 1, n):

            # only join if the first k-2 items are the same
            # if the prefix doesn't match, stop the inner loop
            if list_of_itemsets[i][:k-2] == list_of_itemsets[j][:k-2]:
                # Join the two sets
                new_item = list_of_itemsets[j][k-2]
                candidate = TransactionItemset(list_of_itemsets[i])
                candidate.add(new_item)

                if len(candidate) == k:
                    candidates.add(candidate)
            else:
                # prefixes will never match again for this i
                # because itemsets are sorted
                break

    return candidates

def prune_candidates(candidates, F_prev_keys):
    # create a lookup of frozensets for O(1) membership testing
    # F_prev.keys() contains TransactionItemsets; we extract their internal item sets
    lookup_set = {frozenset(f.items) for f in F_prev_keys}
    pruned = set()

    candidate_list = list(candidates)
    n = len(candidate_list)

    infostr = "Iterating through candidates... "

    for i, candidate in enumerate(candidate_list):
        items = list(candidate.items)

        is_valid = True

        # every subset of size k-1 must be frequent
        for j in range(len(items)):
            # generates all possible subsets with size k-1 while the loop progresses
            subset = frozenset(items[:j] + items[j+1:])
            if subset not in lookup_set:
                is_valid = False
                break

        if is_valid:
            pruned.add(candidate)

        if i % 100 == 0:
            CommonLogger.logger.log(infostr + f"{i}/{n}")
            yield
            CommonLogger.logger.backtrack(1)

    return pruned

# counts of candidate itemsets in the transactions list
def calc_candidate_counts(candidates, vertical_index, pos_indices, transaction_count, min_support):
    results = {}

    infostr = "Iterating through candidates... "

    n = len(candidates)

    for i, candidate in enumerate(candidates):
        if i % 500 == 0:
            CommonLogger.logger.log(infostr + f"{i}/{n}")
            yield
            CommonLogger.logger.backtrack(1)

        item_list = list(candidate.items)
        if not item_list: continue

        # start with the first item's row set
        running_rows = vertical_index.get(item_list[0], set())

        # intersecting with subsequent items returns the set that 
        # contains all the transaction ID's that contain this itemset
        # because its a vertical index
        for j in range(1, len(item_list)):
            running_rows = running_rows & vertical_index.get(item_list[j], set())
            if not running_rows: break

        count = len(running_rows)

        if (count / transaction_count) >= min_support:
            # pos indices contain all the transactions IDs that have a 'true' label
            pos_count = len(running_rows & pos_indices)

            results[candidate] = {
                "total": count,
                "pos": pos_count,
                "neg": count - pos_count
            }

    return results

def apriori(transactions, min_support, max_k):
    vertical_index = {}

    # instead of having to iterate through transactions every time
    # build a TID list instead to instantly know how many transactions
    # contain a given item
    for i, t in enumerate(transactions):
        for item in t["itemset"].items:
            if item not in vertical_index:
                vertical_index[item] = set()
            vertical_index[item].add(i)

    # pre-calculate positive indices for the rule-counting optimization
    pos_indices = {i for i, t in enumerate(transactions) if t["label"]}

    CommonLogger.logger.log("Collecting frequent itemsets with size 1")
    yield

    F = [get_F1(transactions, min_support)]

    # F[0] currently just has counts. reformat so generate_rules can use it later.
    for itemset in F[0]:
        items = list(itemset.items)
        rows = vertical_index.get(items[0], set())
        pos_count = len(rows & pos_indices)
        F[0][itemset] = {"total": len(rows), "pos": pos_count, "neg": len(rows) - pos_count}

    k = 2

    infostr = f"Collecting frequent itemsets with size"

    while F[k - 2] and k <= max_k:
        CommonLogger.logger.update_last(infostr + f" {k} : generating candidates")
        yield
        candidates_k = yield from generate_candidates(F[k - 2].keys(), k)

        CommonLogger.logger.update_last(infostr + f" {k} : pruning candidates")
        yield
        candidates_k = yield from prune_candidates(candidates_k, F[k - 2].keys())

        CommonLogger.logger.update_last(infostr + f" {k} : counting candidate occurances in transactions")
        yield
        Fk = yield from calc_candidate_counts(candidates_k, vertical_index, pos_indices, len(transactions), min_support)

        if not Fk: break
        F.append(Fk)
        k += 1

    return F, vertical_index

def generate_rules(all_frequent_itemsets, transactions, min_support, min_confidence, min_lift, m_estimate_weights):
    rules = []

    label_supports = {
        True:  sum(1 for t in transactions if t["label"]) / len(transactions),
        False: sum(1 for t in transactions if not t["label"]) / len(transactions)
    }

    infostr = "Generating CARs..."
    CommonLogger.logger.log(infostr)

    for i, Fk in enumerate(all_frequent_itemsets):
        sorted_Fk = sorted(Fk.items(), key=lambda x: str(x[0]))
        CommonLogger.logger.update_last(infostr + f" processing {i+1}-item frequent itemsets, count: {len(Fk)} itemsets")
        yield

        # for every itemset in the current frequent itemset
        for k, (frequent_itemset, counts) in enumerate(sorted_Fk):
            if k % 500 == 0:
                CommonLogger.logger.log(f"Iterating through frequent itemsets... {k+1}/{len(Fk)}")
                yield
                CommonLogger.logger.backtrack(1)

            # get the counts from supplied dict to save time
            count_X = counts["total"]
            counts_X_y = {True: counts["pos"], False: counts["neg"]}

            max_conf = max(counts_X_y[True], counts_X_y[False]) / count_X

            if max_conf < min_confidence:
                continue

            for label, count_X_y in counts_X_y.items():
                # |transactions with itemset X and label y| / |transactions|
                support    = count_X_y / len(transactions)

                # |transactions with itemset X and label y| / |transactions with itemset X|
                confidence = count_X_y / count_X

                lift = confidence / label_supports[label]

                # laplace smoothing using label probability ratios
                p = label_supports[label]
                m = (1 - label_supports[label]) / label_supports[label]
                m_estimate = (count_X_y + (m * p)) / (count_X + m)

                current_rule = {
                    "itemset":    frequent_itemset,
                    "label":      label,
                    "lift":       confidence / label_supports[label],
                    "m_estimate": m_estimate,
                    "confidence": confidence,
                    "support":    support
                }

                if current_rule["lift"] <= min_lift:
                    continue

                will_skip = False
                for j, label in enumerate(label_supports):
                    # the rule's m-estimate must exceed the random guess baseline (label support)
                    # multiplied by the label-specific weight.
                    if (current_rule["m_estimate"] < (label_supports[label] * m_estimate_weights[j])):
                        will_skip = True

                if will_skip:
                    continue

                rules.append(current_rule)

    return rules, label_supports

# M1 algorithm for building the classifier.
def build_classifier(rules, transactions, vertical_index, error_weights):
    N = len(transactions)

    # track which transactions haven't been covered yet
    remaining_idx = set(range(N))

    # maintain running counts of labels in the remaining set
    rem_true = sum(1 for t in transactions if t["label"])
    rem_false = N - rem_true

    rule_list         = []
    total_errors      = []
    cumulative_errors = 0

    infostr = "Iterating through rules... "
    CommonLogger.logger.log(infostr)

    # data covering
    for idx, rule in enumerate(rules):
        if idx % 100 == 0:
            CommonLogger.logger.update_last(infostr + f"{idx}/{len(rules)}")
            yield

        #  use vertical index to find transactions containing the itemset
        items = list(rule["itemset"].items)
        if not items:
            covered_tids = set(range(N))
        else:
            # intersect TID-sets of all items in the rule
            covered_tids = vertical_index.get(items[0], set()).copy()
            for i in range(1, len(items)):
                covered_tids &= vertical_index.get(items[i], set())
                if not covered_tids: break

        # filter by transactions that are still available
        actually_covered = covered_tids & remaining_idx

        if not actually_covered:
            continue

        # determine how many transactions are correctly/incorrectly classified by the rule
        # only scan the 'actually_covered' subset
        correct_tids = {i for i in actually_covered if transactions[i]["label"] == rule["label"]}
        wrong_tids = actually_covered - correct_tids

        len_correct = len(correct_tids)
        len_wrong = len(wrong_tids)

        # skip rules that don't help (more wrong than right or not right at all)
        if not len_correct or len_wrong >= len_correct: 
            continue

        # accept the rule
        rule_list.append(rule)

        # calculate cost of errors introduced by this rule
        # (transactions that are covered incorrectly)
        weight = error_weights[0] if rule["label"] else error_weights[1]
        cumulative_errors += len_wrong * weight

        # remove covered instances and update running label totals
        for tid in actually_covered:
            remaining_idx.remove(tid)
            if transactions[tid]["label"]:
                rem_true -= 1
            else:
                rem_false -= 1

        # calculate cost of stopping here (making everything else a default label)
        if rem_true >= rem_false:
            # default true, errors are the remaining False instances
            default_errors = rem_false * error_weights[0]
        else:
            # default false, errors are the remaining True instances
            default_errors = rem_true * error_weights[1]

        total_errors.append(cumulative_errors + default_errors)

        if not remaining_idx:
            break

    if not rule_list:
        # no rules were chosen, return global majority default rule
        count_true = sum(1 for t in transactions if t["label"])
        count_false = N - count_true
        return [], {"itemset": set(), "label": count_true >= count_false, "default": True}

    # find the rule index that minimized total errors (Rule + Default)
    best_idx = total_errors.index(min(total_errors))
    pruned_rules = rule_list[:best_idx + 1]

    # re-run coverage for pruned rules to see what's left for the default class
    final_remaining = set(range(N))
    for rule in pruned_rules:
        items = list(rule["itemset"].items)
        cov = vertical_index.get(items[0], set()).copy() if items else set(range(N))
        for i in range(1, len(items)):
            cov &= vertical_index.get(items[i], set())

        final_remaining -= cov

    # determine default label
    if final_remaining:
        final_true = sum(1 for i in final_remaining if transactions[i]["label"])
        final_false = len(final_remaining) - final_true
        default_label = (final_true >= final_false)
    else:
        # nothing left, use global majority label
        total_true = sum(1 for t in transactions if t["label"])
        default_label = total_true >= (N - total_true)

    default_rule = {"itemset": set(), "label": default_label, "default": True}

    return pruned_rules, default_rule
