import pandas as pd

DATASET_PATH = "../data/with-headers/dataset.csv"

def read_dataset(file_path):
    return pd.read_csv(file_path)

dataset = read_dataset(DATASET_PATH)