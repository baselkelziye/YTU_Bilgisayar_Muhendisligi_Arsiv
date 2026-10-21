from evalplus.data import get_human_eval_plus, get_mbpp_plus, write_jsonl
import pandas as pd
import json
import argparse


def get_merged_df(df_problems: pd.DataFrame, path_samples: str) -> pd.DataFrame:
    """
    Merge the dataset with the generated samples and the results of the evaluation
    :param df_problems: dataframe with the problems - humaneval+ or mbpp+
    :param path_samples: path to the generated samples .jsonl
    :return: dataframe with the problems and the generated samples
    """
    df = df_problems.copy()

    with open(path_samples, "r") as f:
        samples = [json.loads(line) for line in f.readlines()]
        df["generated_solution"] = [sample["solution"] for sample in samples]

    return df


def get_samples_different_entry_point(df: pd.DataFrame) -> bool:
    """
    Check if the entry point is different in the generated solution, return the different samples
    :param df: dataframe with the problems and the generated samples
    :return: True if the entry point is correct, False otherwise
    """
    df["entry_point_in_solution"] = df.apply(
        lambda row: row["entry_point"] in row["generated_solution"], axis=1
    )
    # print(df["entry_point_in_solution"].value_counts())
    return df[df["entry_point_in_solution"] == False]


def replace_entry_point(
    df: pd.DataFrame, df_entry_point_different: pd.DataFrame
) -> pd.DataFrame:
    """
    Replace the function name within the generated solution with entry point
    :param df: dataframe with the problems and the generated samples
    :return: dataframe with the problems and the generated samples
    """

    for index, row in df_entry_point_different.iterrows():
        # get the generated solution
        generated_solution = row["generated_solution"]
        entry_point = row["entry_point"]
        # print(row["task_id"])
        # print(f"Replace {entry_point} -> {generated_solution}")
        # replace the function name with entry point
        # find and replace after 'def' and before '('
        generated_solution = generated_solution.replace(
            generated_solution.split("def ")[1].split("(")[0], entry_point
        )
        # print(row["task_id"])
        # print(f"Replaced: {generated_solution}")

        # update the generated solution
        df.at[index, "generated_solution"] = generated_solution
    return df


def write_jsonl_with_df(df: pd.DataFrame, path_samples: str) -> None:
    """
    Write the new samples to jsonl
    :param df: dataframe with the problems and the generated samples
    :param path_samples: path to the generated samples .jsonl
    :return: None
    """
    samples = [
        dict(task_id=task_id, solution=sample["generated_solution"])
        for task_id, sample in df.iterrows()
    ]

    write_jsonl(path_samples, samples)


def main():
    # argparse
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--sample_path",
        type=str,
        required=True,
        help="Path to the generated samples .jsonl",
    )
    parser.add_argument(
        "--dataset",
        type=str,
        required=True,
        help="Dataset type, must be mbpp or humaneval",
    )
    args = parser.parse_args()
    # get arguments from kwargs
    sample_path = args.sample_path
    dataset_type = args.dataset

    if dataset_type == "mbpp":
        dataset = get_mbpp_plus()
    elif dataset_type == "humaneval":
        dataset = get_human_eval_plus()
    else:
        raise ValueError("--dataset must be mbpp or humaneval")

    df_problems = pd.DataFrame(dataset).transpose()
    df = get_merged_df(df_problems, sample_path)

    # find entry point differences
    df_entry_point_different = get_samples_different_entry_point(df)
    print(
        f"Entry point is different in: {df_entry_point_different[['task_id', 'entry_point', 'generated_solution']]}"
    )
    print(f"Fixing {len(df_entry_point_different)} samples")

    df_replaced = replace_entry_point(df, df_entry_point_different)
    # print(
    # f"Entry point replaced: {df_entry_point_different[['task_id', 'generated_solution']]}"
    # )

    # df_entry_point_different = get_samples_different_entry_point(df)
    # print(f"Entry point is different: {df_entry_point_different}")

    # write the new samples to jsonl
    output_path = sample_path.split(".jsonl")[0] + "_fixed_entry_point.jsonl"
    print(f"Writing to {output_path}")
    write_jsonl_with_df(df, output_path)


if __name__ == "__main__":
    main()
