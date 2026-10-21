#!/bin/bash
# Example: docker run -v $(pwd):/app ganler/evalplus:latest --dataset [humaneval|mbpp] --samples samples.jsonl
docker run -v $(pwd):/app ganler/evalplus:latest --dataset mbpp --samples phi2-code/mbpp_phi2_samples_fixed_entry_point.jsonl

# to use the local version of evalplus, use the following command
# evalplus.evaluate --dataset [humaneval|mbpp] --samples samples.jsonl