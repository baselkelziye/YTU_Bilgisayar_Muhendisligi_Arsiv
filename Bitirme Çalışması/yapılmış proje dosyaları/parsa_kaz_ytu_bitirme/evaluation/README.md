# Evaluation

## Models and Samples

Each folder `CodeGen`, `mistral-code` and `phi2-code` contains the notebooks used to generate the results for the corresponding section of the paper. the generated samples and their results are also included in the folders.

## Exploratory Data Analysis

The `evalanalysis.ipynb` is the notebook used to merge the results and do the exploratory analysis.

## Sample Sanitization

Two python scripts `fix_entrypoint.py` and `fix_filter.py` are used to santize the generated samples. To use them, run the following commands:

```bash
python fix_entrypoint.py --sample_path <path_to_sample.jsonl> --dataset [mbpp|humaneval]
# OR
python fix_filter.py --sample_path <path_to_sample.jsonl>
```

## Running the tests without the notebook

evaluate.sh is the standalone version of running the tests on the samples, recommended by EvalPlus. Either choose to run via Docker or locally.
