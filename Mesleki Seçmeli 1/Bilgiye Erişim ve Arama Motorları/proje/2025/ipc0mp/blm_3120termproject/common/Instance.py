class Instance:
    def __init__(self, features, label_idx):
        self.field_names = list(features.keys())
        self.label_idx = label_idx

        for key in features:
            setattr(self, key, features[key])

    @property
    def features(self):
        cpy = list(self.field_names)
        cpy.pop(self.label_idx)
        return [getattr(self, name) for name in cpy]

    @property
    def label(self):
        return getattr(self, self.field_names[self.label_idx])

    def __repr__(self):
        str = ""

        for name in self.field_names:
            str += f"{name}: {getattr(self, name)}\n"

        return str[:-1]
