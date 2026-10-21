class FeatureType:
    def __init__(self, description, value_domain):
        self.name = description[0]
        self.value = description[1]

        self.value_domain = set(value_domain)

        if self.is_numeric:
            self.value_domain = sorted(self.value_domain)

    @property
    def is_numeric(self):
        return self.value in (int, float)
    
    @property
    def is_categorical(self):
        return self.value in (str, bool)

    def __eq__(self, other):
        return FeatureFilter(self, '==', other)

    def __lt__(self, other):
        return FeatureFilter(self, '<', other)

    def __gt__(self, other):
        return FeatureFilter(self, '>', other)

    def __le__(self, other):
        return FeatureFilter(self, '<=', other)

    def __ge__(self, other):
        return FeatureFilter(self, '>=', other)

    def __ne__(self, other):
        return FeatureFilter(self, '!=', other)

    def __repr__(self):
        return f"FeatureType(name: {self.name}, value: {self.value}, value_domain: {self.value_domain})"
 
class FeatureFilter:
    def __init__(self, feature_type, op, value):
        self.feature_type = feature_type
        self.op = op
        self.value = value

        if (self.feature_type.value != type(self.value) and
            not (self.feature_type.value == int and type(self.value) == float)):
            raise ValueError(f"Incompatible Feature Filter Value used with Feature: {self}")

    def _not(self):
        inverse = {
            '==': '!=',
            '!=': '==',
            '<': '>=',
            '>': '<=',
            '<=': '>',
            '>=': '<'
        }[self.op]

        return FeatureFilter(self.feature_type, inverse, self.value)

    def __repr__(self):
        if self.feature_type.value == str:
            return f"FeatureFilter({self.feature_type.name} {self.op} '{self.value}')"
        else:
            return f"FeatureFilter({self.feature_type.name} {self.op} {self.value})"
