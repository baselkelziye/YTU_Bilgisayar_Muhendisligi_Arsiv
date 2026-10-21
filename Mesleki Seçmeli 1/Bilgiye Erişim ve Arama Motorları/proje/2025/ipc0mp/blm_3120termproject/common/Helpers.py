import common.Logger as CommonLogger

def calc_candidate_thresholds(dataset, feature_type):
    if not feature_type.is_numeric:
        raise ValueError(f"non-numeric feature type supplied to candidate threshold calculation: {feature_type}")

    unique_values_and_labels = set()

    for instance in dataset.instances:
        unique_values_and_labels.add((getattr(instance, feature_type.name),
                                      instance.label))

    unique_values_and_labels = sorted(unique_values_and_labels, key = lambda x: x[0])

    candidates = []

    for i in range(len(unique_values_and_labels) - 1):
        v1, l1 = unique_values_and_labels[i]
        v2, l2 = unique_values_and_labels[i + 1]

        if l1 != l2 and v1 < v2:
            threshold = round((v1 + v2) / 2, 6)
            candidates.append( threshold )

    return candidates

def predict_dataset(dataset, dataset_property_accessor, learning_output, prediction_function, *fargs):
    if not dataset:
        CommonLogger.logger.log("[ERROR] predict_dataset(): dataset is None")
        return None

    if not learning_output:
        CommonLogger.logger.log("[ERROR] predict_dataset(): learning_output is None")
        return None

    if not prediction_function:
        CommonLogger.logger.log("[ERROR] predict_dataset(): no prediction function supplied")
        return None

    predictions = []

    for data in (dataset_property_accessor(dataset) if dataset_property_accessor else dataset):
        predictions.append(prediction_function(data, learning_output, *fargs))

    return predictions

def get_basic_metrics(labels, predictions):
    confusion_matrix = {"TP": 0, "FN": 0, "FP": 0, "TN": 0}

    for i, label in enumerate(labels):
        if label == predictions[i]:
            if predictions[i] == True:
                confusion_matrix["TP"] += 1
            else:
                confusion_matrix["TN"] += 1
        else:
            if predictions[i] == True:
                confusion_matrix["FP"] += 1
            else:
                confusion_matrix["FN"] += 1

    preds_all_positive = confusion_matrix["TP"] + confusion_matrix["FP"]
    preds_tp_fn = confusion_matrix["TP"] + confusion_matrix["FN"]
    preds_tp_tn = confusion_matrix["TP"] + confusion_matrix["TN"]

    accuracy  = (preds_tp_tn / len(labels))
    precision = None
    recall    = None
    f1_score  = None

    if not confusion_matrix["TP"]:
        precision = recall = f1_score = 0
    else:
        precision = (confusion_matrix["TP"] / preds_all_positive)
        recall    = (confusion_matrix["TP"] / preds_tp_fn)
        f1_score  = 2 * ( (precision * recall) / (precision + recall) )

    CommonLogger.logger.log(f"Accuracy: %{round(accuracy*100, 4)} ({preds_tp_tn}/{len(labels)})")

    CommonLogger.logger.log(f"True Positives: {confusion_matrix['TP']}/{len(labels)}")
    CommonLogger.logger.log(f"True Negatives: {confusion_matrix['TN']}/{len(labels)}")
    CommonLogger.logger.log(f"False Positives: {confusion_matrix['FP']}/{len(labels)}")
    CommonLogger.logger.log(f"False Negatives: {confusion_matrix['FN']}/{len(labels)}")

    CommonLogger.logger.log(f"Precision: %{round(precision * 100, 4)} ({confusion_matrix['TP']}/{preds_all_positive})")
    CommonLogger.logger.log(f"Recall: %{round(recall * 100, 4)} ({confusion_matrix['TP']}/{preds_tp_fn})")
    CommonLogger.logger.log(f"F1-Score: {round(f1_score, 4)}")
    yield

    # maybe return confusion matrix too, if need be
    return (accuracy, precision, recall, f1_score)

def get_label_values_and_probs(learning_output, dataset, dataset_property_accessor, data_label_accessor, probability_function, *fargs):
    y_labels = []
    y_probs = []

    if not dataset:
        CommonLogger.logger.log("[ERROR] get_label_values_and_probs(): dataset is None")
        return None

    if not learning_output:
        CommonLogger.logger.log("[ERROR] get_label_values_and_probs(): learning_output is None")
        return None

    if not probability_function:
        CommonLogger.logger.log("[ERROR] get_label_values_and_probs(): no probability function supplied")
        return None

    for data in (dataset_property_accessor(dataset) if dataset_property_accessor else dataset):
        y_labels.append(1 if (data_label_accessor(data) if data_label_accessor else data) else 0)
        y_probs.append(probability_function(learning_output, data, *fargs))

    return y_labels, y_probs
 
def calc_roc_auc(y_label_values, y_probs):
    pairs = sorted(zip(y_probs, y_label_values), key=lambda x: x[0])

    ranks = range(1, len(pairs) + 1)
    rank_sum = 0
    ctx_label_true = 0

    for rank_val, (_, label_value) in zip(ranks, pairs):
        if label_value == True:
            rank_sum += rank_val
            ctx_label_true += 1

    ctx_label_false = len(pairs) - ctx_label_true

    # all same class
    if ctx_label_true == 0 or ctx_label_false == 0:
        return 0.0

    auc = (rank_sum - ctx_label_true * (ctx_label_true + 1) / 2) / (ctx_label_true * ctx_label_false)
    return auc

def get_metrics(predictions, labels, learning_output, dataset, dataset_property_accessor, data_label_accessor, probability_function, *fargs):
    accuracy, precision, recall, f1_score = yield from get_basic_metrics(labels, predictions)

    values_and_probs =  get_label_values_and_probs(
                            learning_output, dataset,
                            dataset_property_accessor, data_label_accessor,
                            probability_function, *fargs
                        )

    if not values_and_probs:
        return [None] * 5

    roc_auc = calc_roc_auc(*values_and_probs)
    CommonLogger.logger.log(f"ROC-AUC: {round(roc_auc, 4)}")
    yield

    y_labels, y_probs = values_and_probs

    return accuracy, precision, recall, f1_score, roc_auc, y_probs, y_labels
