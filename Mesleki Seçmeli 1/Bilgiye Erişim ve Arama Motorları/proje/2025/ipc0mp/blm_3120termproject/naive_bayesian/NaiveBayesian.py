import math

import common.Utils as CommonUtils
import common.Helpers as CommonHelpers
import common.Discretizer as Discretizer
from common.Transaction import apply_thresholds

import common.Logger as CommonLogger

def get_prediction_scores(transaction, probability_table, label_counts, initial_scores):
    scores = initial_scores

    for label in scores.keys():
        for item in transaction["itemset"]:
            fname = item.feature_name
            fval  = item.rule_format

            feature_dict = probability_table[fname][fval]
            count = feature_dict[label]

            num_bins = len(probability_table[fname])

            # laplace smoothing
            prob = (count + 1) / (label_counts[label] + num_bins)

            scores[label] += math.log(prob)

    return scores

def predict(transaction, probability_table, label_counts):
    scores = get_prediction_scores(transaction, probability_table, label_counts, {True: 0, False: 0})
    return max(scores, key=scores.get)

def prediction_probability_true(probability_table, transaction, label_counts):
    scores = get_prediction_scores(transaction, probability_table, label_counts, {label: math.log(label_counts[label] / sum([label_counts[label] for label in label_counts.keys()])) for label in label_counts.keys()} )

    max_score = max(scores.values())

    # probability of True = exp(log_true) / (exp(log_true) + exp(log_false))
    # subtract max_score to prevent overflow,
    # because exponents get large quick
    exp_true = math.exp(scores[True] - max_score)
    exp_false = math.exp(scores[False] - max_score)

    return exp_true / (exp_true + exp_false)

def build_naive_bayesian_classifier(args):
    try:
        trainset = CommonUtils.load_dataset(args.trainset_infile, args.entropy_weights)

        if not trainset:
            return

        threshold_map = yield from Discretizer.best_thresholds_for_features(trainset, args.max_split_count, args.min_bin_frac, args.delta_cost)

        if not threshold_map:
            return

        transactions = apply_thresholds(trainset, threshold_map)

        probability_table = {}
        label_counts = {True: 0, False: 0}

        for t in transactions:
            label = t["label"]
            label_counts[label] += 1
            
            for item in t["itemset"]:
                fname = item.feature_name
                fval  = item.rule_format
                
                if fname not in probability_table:
                    probability_table[fname] = {}
                if fval not in probability_table[fname]:
                    probability_table[fname][fval] = {True: 0, False: 0}
                    
                probability_table[fname][fval][label] += 1

        out = {"probability_table" : probability_table, "threshold_map": threshold_map, "label_counts": label_counts}
        yield from CommonUtils.save_pickle(out, args.pickle_path, "naive bayesian classifier probability table and threshold map")

    except KeyboardInterrupt:
        CommonLogger.logger.log("Received KeyboardInterrupt, exiting.")
        return

def evaluate_naive_bayesian_classifier(args):
    try:
        testset           = CommonUtils.load_dataset(args.testset_infile)

        if not testset:
            return

        pickled_data      = CommonUtils.load_pickle(args.pickle_path)

        if not pickled_data:
            return

        probability_table = pickled_data["probability_table"]
        threshold_map     = pickled_data["threshold_map"]
        label_counts      = pickled_data["label_counts"]

        if not threshold_map:
            return

        transactions =  apply_thresholds(testset, threshold_map)

        predictions  =  CommonHelpers.predict_dataset (
                            transactions, None,
                            probability_table, predict,
                            label_counts
                        )

        if not predictions:
            return None

        metrics_data = yield from CommonHelpers.get_metrics(
                predictions, [t["label"] for t in transactions], probability_table, transactions,
                None, lambda transaction: transaction["label"], prediction_probability_true, label_counts)


        CommonLogger.logger.log("")

        return metrics_data

    except KeyboardInterrupt:
        CommonLogger.logger.log("Received KeyboardInterrupt, exiting.")
        return

def visualize_naive_bayesian_classifier(args):
    pickled_data      = CommonUtils.load_pickle(args.pickle_path)

    if not pickled_data:
        return

    probability_table = pickled_data["probability_table"]
    label_counts      = pickled_data["label_counts"]

    total = sum([label_counts[label] for label in label_counts])

    prob_table_arr = []

    for fname in probability_table:
        for fval in probability_table[fname]:
            for label in probability_table[fname][fval]:
                prob_table_arr.append({"fname": fname, "fval": fval, "label": label, "prob": probability_table[fname][fval][label] / label_counts[label]})

    prob_table_arr.sort(key=lambda x: (-x["prob"], x["fval"], x["label"])) 

    for entry in prob_table_arr:
        fname = entry["fname"]
        fval  = entry["fval"]
        label = entry["label"]
        prob  = entry["prob"]
        CommonLogger.logger.log(f"| Feature: {fname:<25} | Value: {str(fval):<40} | Label: {str(label):<5} | P(feature | label): {str(round(prob, 6)):<8} | ")
