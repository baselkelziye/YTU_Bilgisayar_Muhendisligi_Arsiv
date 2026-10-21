default_trainset_path = "dataset/spotify_churn_dataset/default_trainset.json"
default_testset_path = "dataset/spotify_churn_dataset/default_testset.json"

# process dataset
default_testset_trainset_ratio = 0.2

# decision_tree
default_max_depth             = 24
default_min_samples_split     = 4
default_min_info_gain         = 1e-4
default_min_samples_leaf      = 2
default_min_samples_leaf_kary = 0

default_use_gini              = False
default_entropy_weights       = [3.0, 1.0]

default_dot_outfile = "dotfiles/spotify_churn_dataset/default_decision_tree.dot"
default_decision_tree_pickle_path = "pickles/spotify_churn_dataset/default_decision_tree.pickle"

# CBA
default_max_k           = 6
default_min_support     = 2e-4
default_min_confidence  = 0.2
default_min_lift        = 1.05
default_error_weights   = [1.0, 1.5] # a false negative is 1.5 times worse than a false positive
default_m_estimate_weights = [2.0, 0.0]

default_CBA_pickle_path = "pickles/spotify_churn_dataset/default_rules.pickle"

# naive bayesian
default_naive_bayesian_pickle_path = "pickles/spotify_churn_dataset/default_probability_table.pickle"

# CBA/naive bayesian (discretizer)
default_max_split_count = 3
default_min_bin_frac    = 0.1
default_delta_cost      = 1e-3

# all
default_entropy_weights = [3.0, 1.0]
default_dataset_path = "dataset/spotify_churn_dataset/spotify_churn_dataset.csv"
default_field_types = [t.__name__ for t in [int, str, int, str, str, int, int, float, str, int, bool, bool]]
default_label_idx = len(default_field_types) - 1
default_ignore_indices = [0]
