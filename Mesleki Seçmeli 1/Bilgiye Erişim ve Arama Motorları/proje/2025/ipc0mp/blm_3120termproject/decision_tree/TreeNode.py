class TreeNode:
    def __init__(
        self,
        *,
        is_leaf,
        prediction=None,
        feature_type=None,
        threshold=None,
        is_categorical=None,
        children=None,
        n_samples=0,
        n_pred=0
    ):
        self.is_leaf = is_leaf
        self.prediction = prediction
        self.feature_type = feature_type
        self.threshold = threshold
        self.is_categorical = is_categorical
        self.children = children or {}

        # number of samples this node encompasses
        self.n_samples = n_samples

        # number of samples that share this node's label
        self.n_pred = n_pred            

    def __repr__(self):
        if self.is_leaf:
            return f"<Leaf {self.prediction}>"
        kind = "cat" if self.is_categorical else f"num <= {self.threshold}"
        return f"<Node split={self.feature_type.name} ({kind})>"
