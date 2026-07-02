# Phase 1 Chunk Size Decision

Selected chunk size: **512 chars**

## Scoring formula

`final_score = 0.60 * silhouette + 0.25 * coverage + 0.15 * entropy_balance`

## Ranked candidates

| chunk_size | num_chunks | best_k | silhouette | final_score |
|---|---:|---:|---:|---:|
| 512 | 728700 | 8 | 0.3106 | 0.5724 |
| 1024 | 364602 | 10 | 0.3155 | 0.4489 |
| 2048 | 182561 | 8 | 0.3526 | 0.4076 |
| 4096 | 91540 | 8 | 0.3658 | 0.3835 |
| 8192 | 46023 | 8 | 0.3728 | 0.3716 |
| 20480 | 18703 | 8 | 0.3595 | 0.3537 |
| 10240 | 36918 | 14 | 0.3206 | 0.3370 |
| no_chunk | 1000 | 8 | 0.2731 | 0.2947 |
