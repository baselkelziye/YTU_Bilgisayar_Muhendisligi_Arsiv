from evalplus.data import write_jsonl
import json
import argparse


def get_code_from_solution(solution: str, style: str = "alpaca") -> str:
    """
    Get the code from the solution
    :param solution: solution
    :return: code
    """
    if style == "alpaca":
        response_tag = "### Response:"
        return solution.split(response_tag)[1].strip()

    elif style == "mistral":
        pass  # not a problem now

    return solution  # no change


def fix_solutions(samples: list) -> list:
    """
    Fix the solutions in the samples
    :param samples: samples
    :return: samples
    """
    for sample in samples:
        sample["solution"] = get_code_from_solution(sample["solution"])
    return samples


def main():
    # argparse
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--sample_path",
        type=str,
        required=True,
        help="Path to the generated samples .jsonl",
    )
    args = parser.parse_args()
    # get arguments from kwargs
    sample_path = args.sample_path

    # read the samples from jsonl
    samples = []
    with open(sample_path, "r") as f:
        for line in f:
            samples.append(json.loads(line))

    # fix the entry point
    samples = fix_solutions(samples)

    # write the new samples to jsonl
    output_path = sample_path.split(".jsonl")[0] + "_fixed_solution_code.jsonl"
    print(f"Writing to {output_path}")
    write_jsonl(output_path, samples)


if __name__ == "__main__":
    main()
