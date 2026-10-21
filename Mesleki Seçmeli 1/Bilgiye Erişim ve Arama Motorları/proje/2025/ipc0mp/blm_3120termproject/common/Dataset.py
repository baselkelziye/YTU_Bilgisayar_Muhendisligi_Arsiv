import math

import builtins
from collections import Counter

from common.Instance import Instance
from common.Features import FeatureType, FeatureFilter

class DatasetSchema:
    feature_types   = None
    entropy_weights = None
    label_idx       = None

    def __init__(self):
        if DatasetSchema.feature_types is None or DatasetSchema.entropy_weights is None or DatasetSchema.label_idx is None:
            raise ValueError("Dataset Schema is not configured")

    @staticmethod
    def configure_schema(dataset_contents, field_types = None, entropy_weights = [1.0, 1.0], label_idx = None):
        DatasetSchema.entropy_weights = entropy_weights
        DatasetSchema.label_idx       = label_idx

        if type(dataset_contents) == list:
            # getting field names from first line,
            # then discarding the first line
            field_descriptions = dict(zip(dataset_contents[0], field_types))

            dataset_contents = dataset_contents[1:]

        elif type(dataset_contents) == dict:
            #field_descriptions = zip(dataset_contents["field_names"], field_types)
            field_descriptions = dataset_contents["field_descriptions"]
            DatasetSchema.label_idx = dataset_contents["label_idx"]

            for i in range(len(field_descriptions)):
                try:
                    key, val = list(field_descriptions.items())[i]
                    field_descriptions[key] = (getattr(builtins, val))

                except AttributeError:
                    CommonLogger.logger.log(f"[ERROR] invalid field description in dataset")
                    return None

            dataset_contents = dataset_contents["instances"]

        else:
            raise ValueError(f"Invalid dataset contents type: {type(dataset_contents)}")

        DatasetSchema.feature_types = {
            name: FeatureType(
                [name, field_descriptions[name]], [i[desc_idx] for i in dataset_contents]
                ) for desc_idx, name in enumerate(field_descriptions.keys())
        }

class Dataset(DatasetSchema):
    def __init__(self, instance_array):
        super().__init__()

        self.majority_label  = None
        self.entropy         = None
        self.gini            = None
        self.value_domains   = None

        # the feature name that the dataset was sorted on,
        # e.g "age", used for numeric feature discretization
        self.sorted_on       = None
        
        # positive_counts[i] means the count of churned instances until that index
        # only meaningful on a sorted dataset to be used for numeric feature discretization
        self.positive_counts = None

        self.instances       = []
        self.size            = 0

        if not instance_array or len(instance_array) == 0:
            return

        if type(instance_array[0]) == Instance:
            self.instances = instance_array
        else:
            field_names = list(self.feature_types.keys())

            for instance in instance_array:
                instance_dict = {}

                for i, f in enumerate(instance):
                    field_name = field_names[i]
                    field_type = self.feature_types[field_name].value

                    as_bool = None

                    if f == 'No' or f == 'no' or f == 'NO' or f == 'False' or f == 'false' or f == 'FALSE' or f == 0 or f == '0':
                        as_bool = False
                    elif f == 'Yes' or f == 'yes' or f == 'YES' or f == 'True' or f == 'true' or f == 'TRUE' or f == 1 or f == '1':
                        as_bool = True
                    elif field_type == bool:
                        raise ValueError("[ERROR] field type was specified bool but data couldn't be interpreted as such")

                    instance_dict[field_name] = field_type(as_bool) if field_type == bool else field_type(f)

                self.instances.append(Instance(instance_dict, self.label_idx))

        self.size = len(self.instances)

        if not self.is_empty:
            # majority label: [0] is value, [1] is count of value
            self.majority_label = self.calc_majority_label()
            self.entropy        = self.calc_binary_label_entropy(self.entropy_weights)
            self.gini           = self.calc_binary_label_gini()
            self.value_domains  = self.compute_value_domains()

    @property
    def is_empty(self):
        return self.size == 0

    @property
    def is_pure(self):
        return True if self.is_empty else (self.majority_label[1] == self.size)
    
    @property
    def count_label_true(self):
        return (self.size - self.majority_label[1]) if self.majority_label[0] == False else self.majority_label[1]
    
    @property
    def count_label_false(self):
        return (self.size - self.count_label_true)

    def compute_value_domains(self):
        domains = {name: set() for name in self.feature_types.keys()}

        for inst in self.instances:
            for name in domains.keys():
                domains[name].add(getattr(inst, name))

        for name in domains.keys():
            if self.feature_types[name].is_numeric:
                domains[name] = sorted(domains[name])

        return domains

    def value_domains_repr(self):
        str = ""

        for feature_name in self.value_domains:
            str += f"{feature_name}: "
            domain = self.value_domains[feature_name]
            if self.feature_types[feature_name].is_numeric:
                str += f"range({domain[0]}, {domain[-1]})"
            else:
                str += repr(domain)
            str += '\n'

        return str[:-1]

    def calc_majority_label(self):
        # majority label: [0] is value, [1] is count of value
        counts = Counter(inst.label for inst in self.instances)
        return counts.most_common()[0]

    def calc_binary_label_entropy(self, weights):
        if self.is_pure:
            return 0

        prob = self.count_label_true / self.size
        return -( (weights[0] * prob * math.log2(prob)) + (weights[1] * (1 - prob) * math.log2(1 - prob)) )
    
    def calc_binary_label_gini(self):
        if self.is_empty:
            return 0.0

        p = self.count_label_true / self.size

        return 2 * p * (1 - p)
    
    def calc_positive_counts(self):
        labels = [1 if instance.label else 0 for instance in self.instances]

        pos = [0] * (len(labels) + 1)

        for i in range(1, len(labels) + 1):
            pos[i] = pos[i - 1] + labels[i - 1]

        self.positive_counts = pos

    def calc_segment_cost(self, i, j):
        seg_size = j - i + 1

        if seg_size == 0 or self.is_empty:
            return 0

        seg_pos_count = self.positive_counts[j + 1] - self.positive_counts[i]
        seg_neg_count = seg_size - seg_pos_count

        seg_entropy = 0

        prob_pos = seg_pos_count / seg_size
        prob_neg = seg_neg_count / seg_size

        if (prob_pos != 0) and (prob_neg != 0):
            seg_entropy = -(
                self.entropy_weights[0] * prob_pos * math.log2(prob_pos) +
                self.entropy_weights[1] * prob_neg * math.log2(prob_neg)
            )

        return (seg_size / self.size) * seg_entropy
    
    @classmethod
    def subset_with_feature_filter(cls, dataset, feature_filters):
        instance_array = []

        if dataset.instances:
            for instance in dataset.instances:
                does_conform = True

                for feature_filter in feature_filters:
                    attrval = getattr(instance, feature_filter.feature_type.name)
                    if not eval(f'attrval {feature_filter.op} feature_filter.value'):
                        does_conform = False

                if does_conform:
                    instance_array.append(instance)

        return cls(instance_array)
    
    @classmethod
    def sort_on_feature(cls, dataset, feature_name):
        ret = cls(sorted(dataset.instances, key = lambda inst : getattr(inst, feature_name)))
        ret.sorted_on = feature_name
        return(ret)

    def __repr__(self):
        str = ""

        for c, i in enumerate(self.instances):
            str += f"Instance: {c}\n{i}\n\n"

        return str[:-2]
