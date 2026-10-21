import common.Utils as CommonUtils
import common.Helpers as CommonHelpers
import common.Logger as CommonLogger

import decision_tree.DecisionTreeHelpers as DecisionTreeHelpers
import decision_tree.TreeBuilder as TreeBuilder

from decision_tree.TreeNode import TreeNode

def predict(instance, node):
    if node.is_leaf:
        return node.prediction

    feature_typename = node.feature_type.name

    val = getattr(instance, feature_typename)

    child_node = None

    if node.is_categorical:
        child_node = node.children.get(val)

        # shouldn't happen
        if child_node is None:
            return node.prediction
    else:
        child_node = node.children.get("right")

        if val <= node.threshold:
            child_node = node.children.get("left")

    return predict(instance, child_node)

# probability that an instance label is true
def predict_prob_instance(root_node, instance):
    node = root_node
    while not node.is_leaf:
        val = getattr(instance, node.feature_type.name)

        if node.is_categorical:
            child = node.children.get(val)

            if child is None:
                break

            node = child
        else:
            if val <= node.threshold:
                node = node.children["left"]
            else:
                node = node.children["right"]

    if node.prediction == True:
        npred = node.n_pred 
    else:
        npred = node.n_samples - node.n_pred 
        
    return npred / node.n_samples if node.n_samples > 0 else 0.0

def build_decision_tree(args):
    TreeBuilder.MAX_DEPTH         = args.max_depth
    TreeBuilder.MIN_SAMPLES_SPLIT = args.min_samples_split
    TreeBuilder.MIN_GAIN          = args.min_info_gain
    TreeBuilder.USE_GINI          = args.use_gini

    DecisionTreeHelpers.MIN_SAMPLES_LEAF       = args.min_samples_leaf
    DecisionTreeHelpers.MIN_SAMPLES_LEAF_KARY  = args.min_samples_leaf_kary

    trainset = CommonUtils.load_dataset(args.trainset_infile, args.entropy_weights)

    if not trainset:
        return None

    CommonLogger.logger.log("Building decision tree...", end = '\n\n')
    yield

    try:
        root = yield from TreeBuilder.build_tree(trainset)
        CommonLogger.logger.update_last("Building decision tree... Completed Successfully")
        CommonLogger.logger.log("Collapsing pure subtrees into leaves...")

        yield from TreeBuilder.collapse_pure_subtrees(root)

        CommonLogger.logger.update_last("Collapsing pure subtrees into leaves... Completed Successfully")

        yield from DecisionTreeHelpers.export_tree_to_dot(root, args.dot_outfile)
        yield from CommonUtils.save_pickle(root, args.pickle_path, "decision tree")

    except KeyboardInterrupt:
        CommonLogger.logger.log("Received KeyboardInterrupt, exiting.")
        return None

def evaluate_decision_tree(args):
    testset = CommonUtils.load_dataset(args.testset_infile)

    if not testset:
        return None

    root = CommonUtils.load_pickle(args.pickle_path)

    if not root:
        return None

    predictions =  CommonHelpers.predict_dataset(
                        testset, lambda testset: testset.instances,
                        root, predict
                    )

    if not predictions:
        return None

    feature_names = list(testset.feature_types.keys())

    metrics_data = yield from CommonHelpers.get_metrics(
        predictions,
        [getattr(instance, feature_names[-1]) for instance in testset.instances],
        root, testset,
        lambda testset: testset.instances,
        lambda instance: getattr(instance, feature_names[-1]),
        predict_prob_instance
    )

    CommonLogger.logger.log("")

    return metrics_data

def visualize_decision_tree(args):
    import graphviz
    import GUI.decision_tree_visualizer as visualizer

    # load and convert dot to SVG string
    src = graphviz.Source.from_file(args.dotfile)
    svg_data = src.pipe(format='svg').decode('utf-8')

    html_content = visualizer.get_interactive_tree_html(svg_data)

    CommonLogger.logger.log(html_content)
