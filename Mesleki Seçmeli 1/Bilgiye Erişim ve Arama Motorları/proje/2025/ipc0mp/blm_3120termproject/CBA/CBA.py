import math
import common.Utils as CommonUtils
import common.Logger as CommonLogger

import common.Helpers as CommonHelpers
import common.Discretizer as Discretizer

from common.Transaction import TransactionItemset, apply_thresholds

import CBA.CBAHelpers as CBAHelpers

def generate_CARs(args):
    trainset  = CommonUtils.load_dataset(args.trainset_infile, args.entropy_weights)

    if not trainset:
        return None

    try:
        threshold_map = yield from Discretizer.best_thresholds_for_features(trainset, args.max_split_count, args.min_bin_frac, args.delta_cost)

        if not threshold_map:
            return

        transactions = apply_thresholds(trainset, threshold_map)
        
        max_k              = args.max_k
        min_support        = args.min_support
        min_confidence     = args.min_confidence
        min_lift           = args.min_lift
        error_weights      = args.error_weights
        m_estimate_weights = args.m_estimate_weights

        CommonLogger.logger.log(f"Running apriori algorithm... (max_k: {max_k}, min_support: {min_support}, min_confidence: {min_confidence}, min_lift: {min_lift})")
        yield

        # apriori returns all Fk where k in range (0, max_k)
        all_frequent_itemsets, vertical_index = yield from CBAHelpers.apriori(transactions, min_support, max_k)

        CommonLogger.logger.backtrack(2)
        CommonLogger.logger.log(f"Collected frequent itemsets up to size {len(all_frequent_itemsets)}. (max_k: {max_k}, min_support: {min_support}, min_confidence: {min_confidence}), min_lift: {min_lift}\n")
        yield

        all_rules, label_distribution = yield from CBAHelpers.generate_rules(all_frequent_itemsets, transactions, min_support, min_confidence, min_lift, m_estimate_weights)

        all_rules.sort(key = lambda r : (
            -r["confidence"],     # Accuracy first
            -r["support"],        # General trends over hyper-specific flukes
            -r["lift"],           # Strength of association
            -(r["label"] == True),# Prioritize finding subscribers
            len(r["itemset"]),    # Simple rules over complex ones
            str(r["itemset"])     # Deterministic tie-break
        ))

        CommonLogger.logger.update_last(f"Building the classifier... ")
        rules, default_rule = yield from CBAHelpers.build_classifier(all_rules, transactions, vertical_index, error_weights)
        rules.append( default_rule )
        CommonLogger.logger.backtrack(2)
        CommonLogger.logger.log(f"Generated {len(all_rules)} rules. Down to {len(rules)} after building the classifier.\n")
        yield

        out = {"rules": rules, "threshold_map": threshold_map, "trainset_label_ratios": label_distribution}

        yield from CommonUtils.save_pickle(out, args.pickle_path, "class association rules and treshold map")

    except KeyboardInterrupt:
        CommonLogger.logger.log("Received KeyboardInterrupt, exiting.")
        return None

def predict(transaction, rules):
    for rule in rules:
        # if rule has default: True, then return its label
        if rule.get("default", False):
            return rule["label"]

        # its not a default rule
        if rule["itemset"].issubset(transaction["itemset"]):
            return rule["label"]

# calculate the probability that a given transaction's label is true based on the rules
def predict_prob_transaction(rules, transaction, label_ratios):
    # 1. Filter for matching rules (excluding default)
    matching = [r for r in rules if not r.get("default") and r["itemset"].issubset(transaction["itemset"])]

    if not matching:
        return label_ratios[True]

    best_rule = matching[0]

    if best_rule["label"] == True:
        return best_rule["confidence"]
    else:
        # if the best rule predicts false with 0.8 conf, probability of true is 0.2
        return 1.0 - best_rule["confidence"]

def evaluate_CARs(args):
    try:
        testset        = CommonUtils.load_dataset(args.testset_infile)

        if not testset:
            return None

        pickled_data   = CommonUtils.load_pickle(args.pickle_path)

        if not pickled_data:
            return None

        rules                 = pickled_data["rules"]
        threshold_map         = pickled_data["threshold_map"]
        trainset_label_ratios = pickled_data["trainset_label_ratios"]

        if not threshold_map:
            return

        transactions   = apply_thresholds(testset, threshold_map)

        predictions =   CommonHelpers.predict_dataset(
                            transactions, None, 
                            rules, predict
                        )

        if not predictions:
            return None

        metrics_data = yield from CommonHelpers.get_metrics(
                    predictions, [t["label"] for t in transactions], rules, transactions,
                    None, lambda transaction: transaction["label"],
                    predict_prob_transaction, trainset_label_ratios
                )
        CommonLogger.logger.log("")

        return metrics_data

    except KeyboardInterrupt:
        CommonLogger.logger.log("Received KeyboardInterrupt, exiting.")
        return

def visualize_CARs(args):
    pickled_data   = CommonUtils.load_pickle(args.pickle_path)

    if not pickled_data:
        return None

    rules = pickled_data["rules"]

    # last rule is the default rule
    for i, rule in enumerate(rules[:-1]):
        rule_str = f"| [ {TransactionItemset(rule["itemset"]).compact_repr():<155} ] | "
        rule_str += f"label: {str(rule['label']):<5} | "
        rule_str += f"confidence: {str(round(rule['confidence'], 4)):<6} | "
        rule_str += f"support: {str(round(rule['support'], 4)):<6} | "
        CommonLogger.logger.log(rule_str)
