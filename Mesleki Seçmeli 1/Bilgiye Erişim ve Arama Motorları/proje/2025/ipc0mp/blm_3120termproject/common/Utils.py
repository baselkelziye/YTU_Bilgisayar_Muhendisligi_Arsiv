import os
import re
import csv
import json
import pickle
import builtins

from common.Dataset import DatasetSchema, Dataset
from sklearn.model_selection import train_test_split

import common.Logger as CommonLogger

def pop_ignored_indices(_data, _ignore_indices, label_idx_ref = None):
    ignore_indices = sorted(_ignore_indices)
    data = list(_data)

    for i in range(len(ignore_indices)):
        if label_idx_ref and label_idx_ref[0] > ignore_indices[i]:
            label_idx_ref[0] -= 1

        for j in range(i + 1, len(ignore_indices)):
            if ignore_indices[j] > ignore_indices[i]:
                ignore_indices[j] -= 1

        data.pop(ignore_indices[i])

    return data

def process_dataset(args):
    field_types = []
    ignore_indices = []
    label_idx_ref = [args.label_idx]

    supported_types = frozenset([str, bool, int, float])

    if len(args.ignore_indices) > len(args.field_types):
        CommonLogger.logger.log(f"[ERROR] ignored indices length must be smaller than field types length")
        return None

    field_types_init = None

    if type(args.field_types) != list:
        field_types_init = args.field_types.split(',')
    else:
        field_types_init = args.field_types

    if type(args.ignore_indices) != list:
        ignore_indices = [int(i) for i in args.ignore_indices.split(',')]
    else:
        ignore_indices = args.ignore_indices

    for t in field_types_init:
        try:
            ftype = getattr(builtins, t)
            if ftype not in supported_types:
                CommonLogger.logger.log(f"[ERROR] unsupported dataset field type: {ftype}, supported types are: {[t.__name__ for t in supported_types]}")
                return None

            field_types.append(ftype)
        except AttributeError:
            CommonLogger.logger.log(f"[ERROR] invalid field type: {t}")
            return None

    if args.label_idx in ignore_indices:
        CommonLogger.logger.log(f"[ERROR] label idx can't ignored, label idx: {args.label_idx}, ignored_indices: {args.ignore_indices}")
        return None

    if -1 in ignore_indices and len(ignore_indices) > 1:
        CommonLogger.logger.log(f"[ERROR] ignore indices length should be 1 if it contains -1.")
        return None

    if ignore_indices != [-1]:
        field_types = pop_ignored_indices(field_types, ignore_indices, label_idx_ref)

    dataset = load_dataset(args.dataset, preprocess=True, field_types=field_types, label_idx=label_idx_ref[0], ignore_indices=ignore_indices)

    if not dataset:
        return None

    if args.ratio <= 0 or args.ratio >= 1:
        CommonLogger.logger.log(f"[ERROR] Invalid testset to dataset ratio supplied: {args.ratio}, must be in range (0,1)")
        return None

    testset, trainset = create_test_and_train_set(dataset, args.ratio, field_types)

    save_dataset(args.testset_outfile, testset)
    save_dataset(args.trainset_outfile, trainset)

    CommonLogger.logger.log("[INFO] Test and Train datasets successfully created")

def save_dataset(file_path, dataset):
    out_path = os.path.normpath(file_path)
    directory, filename = os.path.split(out_path)

    if directory != '' and not os.path.exists(directory):
        os.makedirs(directory)

    with open(out_path, "w+") as outfile:
        json.dump(dataset, outfile)

def field_exists_in_dict(_dict, field):
    if (
        (not field in _dict) or
        (_dict[field] == None) or
        (len(_dict[field]) == 0)
    ):
        return False

    return True

def verify_dataset_format(dataset_contents):
    return (field_exists_in_dict(dataset_contents, "instances") and
            field_exists_in_dict(dataset_contents, "field_descriptions"))

def load_dataset(dataset_filepath, entropy_weights = [1.0, 1.0], preprocess=False, field_types=None, label_idx=None, ignore_indices=None):
    if not dataset_filepath:
        CommonLogger.logger.log("[ERROR] load_dataset: dataset_filepath cannot be None")
        return None

    norm_path = os.path.normpath(dataset_filepath)
    directory, filename = os.path.split(norm_path)

    filename_noext, file_ext = os.path.splitext(filename)

    if preprocess and file_ext != '.csv':
        CommonLogger.logger.log("[ERROR] Dataset supplied to preprocess_dataset should be a csv file")
        return None
    elif not preprocess and file_ext != '.json':
        CommonLogger.logger.log("[ERROR] Dataset supplied to an algorithm should be a json file")
        return None

    dataset_contents = None

    try:
        if file_ext == '.csv':
            if label_idx == None or field_types == None or ignore_indices == None:
                CommonLogger.logger.log("[ERROR] Label idx, field_types and ignore_indices cannot be None during dataset preprocessing")
                return None

            with open(dataset_filepath) as csvfile:
                reader = csv.reader(csvfile, delimiter=',')
                dataset_contents = list(reader)

                if not dataset_contents:
                    CommonLogger.logger.log("[ERROR] Empty dataset file")
                    return None
                elif len(dataset_contents) <= 1:
                    CommonLogger.logger.log("[ERROR] Dataset doesn't have more than a single line")
                    return None
                elif len(dataset_contents[1]) < len(field_types):
                    CommonLogger.logger.log("[ERROR] Dataset instance length doesn't match field types")
                    return None

                dataset_instances = None

                if ignore_indices != [-1]:
                    dataset_instances = [pop_ignored_indices(inst, ignore_indices) for inst in dataset_contents]
                else:
                    dataset_instances = dataset_contents

                DatasetSchema.configure_schema(dataset_instances, field_types, entropy_weights, label_idx)

                first_instance = dataset_instances[1]

                for i, field in enumerate(first_instance):
                    try:
                        field_types[i](field)
                    except:
                        CommonLogger.logger.log("[ERROR] Dataset isn't compatible with the supplied field types")
                        return None

                dataset = Dataset(dataset_instances[1:])

        elif file_ext == '.json':
            dataset_contents = json.load(open(dataset_filepath))

            if not verify_dataset_format(dataset_contents):
                CommonLogger.logger.log("[ERROR] Malformed dataset")
                return None

            DatasetSchema.configure_schema(dataset_contents, field_types, entropy_weights, label_idx)

            dataset = Dataset(dataset_contents['instances'])

        elif file_ext == '':
            CommonLogger.logger.log(f"[ERROR] Dataset file extension should be '.json' or '.csv'")
            return None

        else:
            CommonLogger.logger.log(f"[ERROR] Supplied dataset file has unsupported extension: {filename}")
            return None

    except FileNotFoundError as e:
        CommonLogger.logger.log(f"[ERROR]{re.sub(r'\[Errno [0-9]+\]', '', str(e))}")
        return None

    return dataset

def create_test_and_train_set(dataset, ratio, field_types):
    x = []

    label_idx   = dataset.label_idx
    field_names = list(dataset.feature_types.keys())

    field_descriptions = dict(zip(field_names, [t.__name__ for t in field_types]))

    for i in dataset.instances:
        x.append([getattr(i, name) for j, name in enumerate(field_names) if j != label_idx])


    y = [getattr(i, field_names[label_idx]) for i in dataset.instances]

    # returns -> x train, x test, y train, y test
    # 1186 active, 414 churned in test instances (25.9%) churned
    # 4743 active, 1657 churned in training instances (25.6%) churned
    split = train_test_split(x, y, train_size = 1 - ratio, test_size = ratio, stratify=y)

    trainset = { "instances": [], "field_descriptions": field_descriptions, "label_idx": label_idx }
    testset = { "instances": [], "field_descriptions": field_descriptions, "label_idx": label_idx }

    for i in range(len(split[0])):
        trainset["instances"].append( split[0][i] + [split[2][i]] )

    for i in range(len(split[1])):
        testset["instances"].append( split[0][i] + [split[2][i]] )

    return (testset, trainset)

def save_pickle(data, pickle_outfile, datatype):
    out_path = os.path.normpath(pickle_outfile)
    directory, filename = os.path.split(out_path)

    if directory != '' and not os.path.exists(directory):
        os.makedirs(directory)

    with open(out_path, "wb+") as f:
        pickle.dump(data, f)

    CommonLogger.logger.log(f"Pickled {datatype} into file: {out_path}")
    yield

def load_pickle(pickle_infile):
    data = None

    try:
        with open(pickle_infile, "rb") as f:
            data = pickle.load(f)
    except FileNotFoundError as e:
        CommonLogger.logger.log(f"[ERROR]{re.sub(r'\[Errno [0-9]+\]', '', str(e))}")
        return None

    return data
