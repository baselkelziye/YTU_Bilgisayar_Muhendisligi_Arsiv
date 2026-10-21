from common.Dataset import Dataset

import common.Logger as CommonLogger

from decision_tree.TreeNode import TreeNode

import decision_tree.DecisionTreeHelpers as helpers

MAX_DEPTH         = None
MIN_SAMPLES_SPLIT = None
MIN_GAIN          = None
MIN_LEAF          = None
USE_GINI          = None

def build_tree(dataset, depth = 0):
    infostr = ""
    infostr += f"curdepth: {depth}\n"
    infostr += dataset.value_domains_repr() + '\n'

    CommonLogger.logger.log(infostr)
    yield
    CommonLogger.logger.backtrack(1)

    if dataset.is_empty:
        return TreeNode(is_leaf=True, prediction=False, n_samples=0, n_pred=0)

    if (
        (dataset.is_pure) or
        ((depth >= MAX_DEPTH and MAX_DEPTH != 0) or dataset.size < MIN_SAMPLES_SPLIT)
    ):
        pred, count = dataset.majority_label
        return TreeNode(is_leaf=True, prediction=pred, n_samples=dataset.size, n_pred=count)

    best_gain, best_split = helpers.evaluate_info_gains(dataset, USE_GINI)

    if best_split is None or best_gain < MIN_GAIN:
        pred, count = dataset.majority_label
        return TreeNode(is_leaf=True, prediction=pred, n_samples=dataset.size, n_pred=count)

    subtree = yield from subtree_for_split(dataset, depth, best_split)
    return subtree

def subtree_for_split(dataset, depth, best_split):
    split_kind, feature_type, threshold = best_split

    if split_kind == "numeric":
        _filter = (feature_type > threshold)
        right_split = Dataset.subset_with_feature_filter(dataset, [_filter])
        left_split = Dataset.subset_with_feature_filter(dataset, [_filter._not()])

        # if something went wrong and one side is empty
        if right_split.is_empty or left_split.is_empty:
            pred, count = dataset.majority_label
            return TreeNode(is_leaf=True, prediction=pred, n_samples=dataset.size, n_pred=count)

        left_child = yield from build_tree(left_split, depth + 1)
        right_child = yield from build_tree(right_split, depth + 1)

        return TreeNode(
            is_leaf=False,
            feature_type=feature_type,
            is_categorical=False,
            threshold=threshold,
            children={"left": left_child, "right": right_child},
            n_samples=dataset.size
        )

    else:
        # categorical
        if dataset.value_domains is not None:
            values = dataset.value_domains[feature_type.name]
        else:
            values = feature_type.value_domain

        children = {}
        for val in values:
            subset = Dataset.subset_with_feature_filter(dataset, [feature_type == val])
            if subset.is_empty:
                continue
            children[val] = yield from build_tree(subset, depth + 1)

        if not children:
            pred, count = dataset.majority_label
            return TreeNode(is_leaf=True, prediction=pred, n_samples=dataset.size, n_pred=count)

        return TreeNode(
            is_leaf=False,
            feature_type=feature_type,
            is_categorical=True,
            children=children,
            n_samples=dataset.size
        )

def collapse_pure_subtrees(node):
    if node.is_leaf:
        return {node.prediction}

    child_labels = set()

    if node.is_categorical:
        for val, child in list(node.children.items()):
            preds = yield from collapse_pure_subtrees(child)
            child_labels.update(preds)
    else:
        for key in ("left", "right"):
            child = node.children.get(key)
            if child is not None:
                preds = yield from collapse_pure_subtrees(child)
                child_labels.update(preds)

    if len(child_labels) != 1:
        return child_labels

    pred = list(child_labels)[0]

    node.is_leaf = True
    node.prediction = pred
    node.feature_type = None
    node.threshold = None
    node.is_categorical = None
    node.children = {}

    # all samples in scope have the same label
    node.n_pred = node.n_samples

    return {pred}
