from defaults import *

from GUI.decision_tree_visualizer import decision_tree_visualizer_js

DISCRETIZER_FIELDS = [
    {"id": "entropy_weights", "label": "Entropy Weights", "info":"Entropy weights for true and false labels respectively", "value":','.join((str(default_entropy_weights)[1:-1]).split(", "))},
    {"id": "max_split_count", "label": "Max Split Count", "type": "number", "value": default_max_split_count, "info": "Max split count to consider while discretizing numeric features"},
    {"id": "min_bin_frac", "label": "Minimum Bin Fraction", "type": "number", "value": default_min_bin_frac, "info": "Minimum fraction of the training dataset a threshold bin should cover while discretizing numeric features into multiple bins"},
    {"id": "delta_cost", "label": "Delta Cost", "type": "number", "value": default_delta_cost, "info":"Minimum cost difference adding a new bin should make while discretizing numeric features into multiple bins"}
]

PREPROCESS_DATASET = {
    "title": "Preprocess Dataset",
    "tab_id": "process_dataset",
    "handler": "process_dataset",
    "sections": [
        {
            "layout": "row",
            "sections": [
                {
                    "layout": "group",
                    "fields": [
                        {"id": "dataset", "label": "Dataset", "type": "path", "value": default_dataset_path},
                        {"id": "testset_outfile", "label": "Testset Output Path", "type": "path", "value": default_testset_path},
                        {"id": "trainset_outfile", "label": "Trainset Output Path", "type": "path", "value": default_trainset_path},
                        {
                            "id": "ratio", "label": "Testset/Dataset Ratio", "type": "number", "value": default_testset_trainset_ratio, "info": f"({default_testset_trainset_ratio} corresponds to trainset with {1 - default_testset_trainset_ratio} ratio)"
                        },
                    ]
                },
                {
                    "layout": "group",
                    "fields": [
                        {"id": "field_types", "label": "Dataset Field Types", "info":"the sequential data types that instances in the dataset consist of", "value": ','.join((str(default_field_types)[1:-1]).replace("'", "").split(", "))},
                        {"id": "ignore_indices", "label": "Ignored Field Indices", "info":"Comma seperated field indices to exclude from the resulting datasets (-1 to include everything)", "value": ','.join((str(default_ignore_indices)[1:-1]).split(", "))},
                        {"id": "label_idx", "label": "Label Index", "info":"Field idx of the target class", "type": "number", "value": default_label_idx},
                    ]
                }
            ]
        }
    ]
}

DECISION_TREE = {
    "title": "Decision Tree Classifier",
    "tab_id": "decision_tree",
    "subtabs": [
        {
            "title": "Build",
            "handler": "decision_tree.build",
            "sections": [
                {
                    "layout": "row",
                    "sections": [
                        {
                            "layout": "column",
                            "sections": [
                                {
                                    "layout": "group",
                                    "fields": [
                                        {"id": "trainset_infile", "label": "Trainset Path", "type": "path", "value": default_trainset_path},
                                        {"id": "pickle_path", "label": "Pickle Path", "type": "path", "value": default_decision_tree_pickle_path, "info":"Path to pickle the decision tree into"},
                                        {"id": "dot_outfile", "label": "Dot Export Path", "type": "path", "value": default_dot_outfile, "info":"Path to write the dotfile of the decision tree to"},
                                        {"id": "use_gini", "label": "Use Gini", "info":"Use gini impurity instead of entropy", "type": "dropdown", "choices": [True, False], "value":False},
                                        {"id": "entropy_weights", "label": "Entropy Weights", "info":"Entropy weights for true and false labels respectively (useless if using gini)", "value":','.join((str(default_entropy_weights)[1:-1]).split(", "))}
                                    ]
                                }
                            ]
                        },
                        {
                            "layout": "column",
                            "sections": [
                                {
                                    "layout": "group",
                                    "fields": [
                                        {"id": "max_depth", "label": "Max Tree Depth", "type":"number", "value":default_max_depth, "info":"Max decision tree depth"},
                                        {"id": "min_info_gain", "label": "Minimum Split Info Gain", "type":"number", "value":default_min_info_gain, "info":"Minimum info gain for a split to qualify"},
                                        {"id": "min_samples_split", "label":"Minimum Split Sample Size", "type":"number", "value":default_min_samples_split, "info":"Minimum samples a meaningful split should have"},
                                        {"id": "min_samples_leaf", "label": "Minimum Leaf Sample Size", "type":"number", "value":default_min_samples_leaf, "info":"Minimum samples a leaf node should have"},
                                        {"id": "min_samples_leaf_kary", "label": "Minimum K-ary Leaf Sample Size", "type":"number", "value":default_min_samples_leaf_kary, "info":"Minimum samples a leaf node of a k-ary node should have"},
                                    ]
                                }
                            ]
                        }
                    ]
                }
            ]
        },
        {
            "title": "Evaluate",
            "handler": "decision_tree.evaluate",
            "sections": [
                {
                    "layout": "group",
                    "fields": [
                        {"id": "testset_infile", "label": "Testset Path", "type": "path", "value": default_testset_path},
                        {"id": "pickle_path", "label": "Pickle Path", "type": "path", "value": default_decision_tree_pickle_path, "info":"Path to read pickled decision tree from"},
                    ]
                }
            ]
        },
        {
            "title": "Visualize",
            "handler": "decision_tree.visualize",
            "hide_output_group": True,
            "outputs_to": ["viz_out"],
            "btn_on_top": True,
            "sections": [
                {
                    "layout": "column",
                    "fields": [
                        {"id": "dotfile", "label": "Dotfile Path", "type": "path", "value": default_dot_outfile, "info":"Path to read decision tree dotfile from"},
                        {"id": "viz_out", "label": "Output", "type": "html", "js_on_load": decision_tree_visualizer_js, "interactive": False, "not_an_input": True},
                    ]
                }
            ]
        }
    ]
}

CBA = {
    "title": "CBA Classifier",
    "tab_id": "CBA",
    "subtabs": [
        {
            "title": "Generate",
            "handler": "CBA.generate",
            "sections": [
                {
                    "layout": "row",
                    "sections": [
                        {
                            "layout": "column",
                            "sections": [
                                {
                                    "layout": "group",
                                    "fields": [
                                        {"id": "trainset_infile", "label": "Trainset Path", "type": "path", "value": default_trainset_path},
                                        {"id": "pickle_path", "label": "Pickle Path", "type": "path", "value": default_CBA_pickle_path, "info":"Path to pickle the classifier rules into"},
                                    ]
                                },
                                {
                                    "layout": "accordion",
                                    "label": "Discretization Params",
                                    "fields": DISCRETIZER_FIELDS
                                }
                            ]
                        },
                        {
                            "layout": "column",
                            "sections": [
                                {
                                    "layout": "group",
                                    "fields": [
                                        {"id": "max_k", "label": "Max K", "type":"number", "value":default_max_k, "info":"Max K value for apriori"},
                                        {"id": "min_support", "label": "Minimum Support", "type":"number", "value":default_min_support, "info":"Minimum support for the CARs"},
                                        {"id": "min_confidence", "label": "Minimum Confidence", "type":"number", "value":default_min_confidence, "info":"Minimum confidence for the CARs"},
                                        {"id": "min_lift", "label": "Minimum Lift", "type":"number", "value":default_min_lift, "info":"Minimum lift for the CARs"},
                                        {"id": "error_weights", "label": "Error Weights", "value": ','.join((str(default_error_weights)[1:-1]).split(", ")), "info":"The weights to use for penalizing rules that incorrectly cover instances while building CAR classifier"},
                                        {"id": "m_estimate_weights", "label": "M-Estimate Weights", "value": ','.join((str(default_m_estimate_weights)[1:-1]).split(", ")), "info":"The weights to decide how more likely it should be that a rule's prediction is correct than its label's random guess baseline"},
                                    ]
                                }
                            ]
                        }
                    ]
                }
            ]
        },
        {
            "title": "Evaluate",
            "handler": "CBA.evaluate",
            "sections": [
                {
                    "layout": "group",
                    "fields": [
                        {"id": "testset_infile", "label": "Testset Path", "type": "path", "value": default_testset_path},
                        {"id": "pickle_path", "label": "Pickle Path", "type": "path", "value": default_CBA_pickle_path, "info":"Path to read pickled rules from"},
                    ]
                }
            ]
        },
        {
            "title": "Visualize",
            "handler": "CBA.visualize",
            "hide_output_group": True,
            "outputs_to": ["viz_out"],
            "btn_on_top": True,
            "sections": [
                {
                    "layout": "column",
                    "fields": [
                        {"id": "pickle_path", "label": "Pickle Path", "type": "path", "value": default_CBA_pickle_path, "info":"Path to read pickled rules from"},
                        {"id": "viz_out", "label": "Output", "type": "code", "interactive": False, "not_an_input": True},
                    ]
                }
            ]
        }
    ]
}

NAIVE_BAYESIAN = {
    "title": "Naive Bayesian Classifier",
    "tab_id": "naive_bayesian",
    "subtabs": [
        {
            "title": "Build",
            "handler": "naive_bayesian.build",
            "sections": [
                {
                    "layout": "row",
                    "sections": [
                        {
                            "layout": "column",
                            "sections": [
                                {
                                    "layout": "group",
                                    "fields": [
                                        {"id": "trainset_infile", "label": "Trainset Path", "type": "path", "value": default_trainset_path},
                                        {"id": "pickle_path", "label": "Pickle Path", "type": "path", "value": default_naive_bayesian_pickle_path, "info":"Path to pickle the probability table into"},
                                    ]
                                }
                            ]
                        },
                        {
                            "layout": "column",
                            "sections": [
                                {
                                    "layout": "accordion",
                                    "label": "Discretization Params",
                                    "fields": DISCRETIZER_FIELDS
                                }
                            ]
                        }
                    ]
                }
            ]
        },
        {
            "title": "Evaluate",
            "handler": "naive_bayesian.evaluate",
            "sections": [
                {
                    "layout": "group",
                    "fields": [
                        {"id": "testset_infile", "label": "Testset Path", "type": "path", "value": default_testset_path},
                        {"id": "pickle_path", "label": "Pickle Path", "type": "path", "value": default_naive_bayesian_pickle_path, "info":"Path to read pickled probability table from"},
                    ]
                }
            ]
        },
        {
            "title": "Visualize",
            "handler": "naive_bayesian.visualize",
            "hide_output_group": True,
            "outputs_to": ["viz_out"],
            "btn_on_top": True,
            "sections": [
                {
                    "layout": "column",
                    "fields": [
                        {"id": "pickle_path", "label": "Pickle Path", "type": "path", "value": default_naive_bayesian_pickle_path, "info":"Path to read pickled probability table from"},
                        {"id": "viz_out", "label": "Output", "type": "code", "interactive": False, "not_an_input": True},
                    ]
                }
            ]
        }
    ]
}

PLOT_PERFORMANCES = {
    "title": "Plot Performances",
    "tab_id": "plot_performances",
    "handler": "plot_performances",
    #"hide_output_group": True,
    "forwarder": "forward_plot",
    "outputs_to": ["common_log_out", "plot_accuracy", "plot_precision", "plot_recall", "plot_f1", "plot_roc_auc", "plot_roc_curve"],
    "btn_on_top": True,
    "sections": [
        {
            "layout": "column",
            "sections": [
                {
                    "layout": "row",
                    "sections": [
                        {
                            "layout": "group",
                            "fields": [
                                {"id": "testset_infile", "label": "Testset Path", "type": "path", "value": default_testset_path},
                                {"id": "pickle_path_decision_tree", "label": "Decision Tree Pickle Path", "type": "path", "value": default_decision_tree_pickle_path},
                            ]
                        },
                        {
                            "layout": "group",
                            "fields": [
                                {"id": "pickle_path_CBA", "label": "CBA Pickle Path", "type": "path", "value": default_CBA_pickle_path},
                                {"id": "pickle_path_naive_bayesian", "label": "Naive Bayesian Pickle Path", "type": "path", "value": default_naive_bayesian_pickle_path},
                            ]
                        }
                    ]
                },
                {
                    "layout": "column",
                    "sections": [
                        {
                            "layout": "row",
                            "fields": [
                                {"id": "plot_accuracy", "label": "Accuracy", "type": "plot", "not_an_input": True},
                                {"id": "plot_precision", "label": "Precision", "type": "plot", "not_an_input": True},
                                {"id": "plot_recall", "label": "Recall", "type": "plot", "not_an_input": True},
                            ]
                        },
                        {
                            "layout": "row",
                            "fields": [
                                {"id": "plot_f1", "label": "F1-Score", "type": "plot", "not_an_input": True},
                                {"id": "plot_roc_auc", "label": "ROC-AUC Score", "type": "plot", "not_an_input": True},
                            ]
                        },
                        {
                            "layout": "row",
                            "fields": [
                                {"id": "plot_roc_curve", "label": "ROC (Receiver-Operating Characteristic) Curve", "type": "plot", "not_an_input": True},
                            ]
                        }
                    ]
                }
            ]
        }
    ]
}

layout_definition = [PREPROCESS_DATASET, DECISION_TREE, CBA, NAIVE_BAYESIAN, PLOT_PERFORMANCES]
