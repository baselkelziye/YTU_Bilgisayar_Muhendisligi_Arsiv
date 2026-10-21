class TransactionItem:
    def __init__(self, feature_name, rule_format):
        self.feature_name = feature_name
        self.rule_format  = rule_format

    def __repr__(self):
        return f"TransactionItem(\"{self.feature_name}\", \"{self.rule_format}\")"

    def compact_repr(self):
        return f"({self.rule_format})"

    def __eq__(self, other):
        if isinstance(other, type(self)):
            return (self.feature_name == other.feature_name) and (self.rule_format == other.rule_format)
        return False

    def __hash__(self):
        return hash((self.feature_name, self.rule_format))
    
    def __lt__(self, other):
        return self.feature_name < other.feature_name

class TransactionItemset:
    def __init__(self, items=None):
        if items:
            self.items = set(items)
        else:
            self.items = set()

    def __iter__(self):
        return iter(self.items)

    def __repr__(self):
        sorted_items = sorted(list(self.items), key=lambda x: str(x))
        ret = "TransactionItemset([" + ", ".join(str(item) for item in sorted_items) + "])"
        return ret

    def compact_repr(self):
        sorted_items = sorted(list(self.items), key=lambda x: str(x) if type(x) != TransactionItem else x.compact_repr())
        str_items = []

        for item in sorted_items:
            str_items.append(str(item) if type(item) != TransactionItem else item.compact_repr())

        return ", ".join(str_items)

    def add(self, item):
        if item not in self.items:
            if isinstance(item, TransactionItem):
                if not any(i.feature_name == item.feature_name for i in self.items):
                    self.items.add(item)
            else:
                self.items.add(item)

        return self

    def __or__(self, other):
        out = {item.feature_name: item for item in self.items}

        if isinstance(other, type(self)):
            for item in other.items:
                out[item.feature_name] = item

        elif isinstance(other, set):
            for item in other:
                out[item.feature_name] = item

        else:
            raise TypeError(f"unsupported operand type(s) for |: '{type(self).__name__}' and '{type(other).__name__}'")

        return TransactionItemset(out.values())

    def __contains__(self, item):
        return item in self.items

    def issubset(self, other):
        if isinstance(other, type(self)):
            return self.items.issubset(other.items)
        elif isinstance(other, set):
            return self.items.issubset(other)
        else:
            raise TypeError(f"unsupported operand type(s) for issubset(): '{type(self).__name__}' and '{type(other).__name__}'")

    def __eq__(self, other):
        if isinstance(other, type(self)):
            return self.items == other.items

        elif isinstance(other, set):
            return self.items == other

        return False

    def __sub__(self, other):
        out = TransactionItemset()

        if isinstance(other, type(self)):
            out.items = self.items - other.items

        elif isinstance(other, set):
            out.items = self.items - other

        else:
            raise TypeError(f"unsupported operand type(s) for -: '{type(self).__name__}' and '{type(other).__name__}'")

        return out

    def __len__(self):
        return len(self.items)

    def __hash__(self):
        return hash(frozenset(self.items))

def apply_thresholds(dataset, threshold_map):
    transactions = []

    for instance in dataset.instances:
        items = []
        feature_types = list(dataset.feature_types.values())
        label = feature_types[dataset.label_idx]

        feature_types.pop(dataset.label_idx)

        for i, feature_type in enumerate(feature_types):
            feature_name = feature_type.name
            value = getattr(instance, feature_name)

            if feature_type.is_numeric:
                tmap = threshold_map[feature_name]
                is_placed = False

                for j in range(len(tmap)):
                    if value <= tmap[j]:
                        rule_str = f"{feature_name} <= {tmap[j]}" if j == 0 else f"{tmap[j - 1]} < {feature_name} <= {tmap[j]}"
                        items.append(TransactionItem(feature_name, rule_str))
                        is_placed = True
                        break

                if not is_placed:
                    items.append(TransactionItem(feature_name, f"{feature_name} > {tmap[-1]}"))

            else:
                items.append(TransactionItem(feature_name, f"{feature_name} = {value}"))

        itemset = TransactionItemset(items)
        transactions.append( {"itemset": itemset, "label": getattr(instance, label.name)} )

    return transactions
