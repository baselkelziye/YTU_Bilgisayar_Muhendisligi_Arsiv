# Phase 3 — MLP Profile Classifier Training Report

## Summary

- **Test Accuracy**: 0.8911 (89.1%)
- **Macro F1**:     0.9186
- **Top-3 Acc**:    0.9995
- **Inference**:    0.018 ms/chunk
- **Classes**:      11 profiles
- **Test Samples**: 60,738

## Training

- **Architecture**: ``Linear(10 → 32) → ReLU → Dropout(0.1) → Linear(32 → 11)``
- **Best epoch**:   50
- **Best val loss**: 0.2730
- **Best val acc**:  0.8904
- **Early stopping**: patience=7, triggered at epoch 57

## Per-Profile Metrics

| Profile | Precision | Recall | F1 | Support |
|---|---:|---:|---:|---:|
| profile_0 | 0.9054 | 0.9377 | 0.9213 | 15522 |
| profile_1 | 0.8710 | 0.8872 | 0.8790 | 14085 |
| profile_2 | 0.8937 | 0.8717 | 0.8826 | 1707 |
| profile_3 | 0.9213 | 0.9590 | 0.9398 | 366 |
| profile_4 | 0.9753 | 0.9293 | 0.9517 | 509 |
| profile_5 | 0.8820 | 0.9009 | 0.8913 | 4197 |
| profile_6 | 0.8620 | 0.8098 | 0.8351 | 13775 |
| profile_7 | 1.0000 | 1.0000 | 1.0000 | 5 |
| profile_9 | 0.9098 | 0.8997 | 0.9047 | 628 |
| profile_10 | 0.9603 | 0.9840 | 0.9720 | 935 |
| profile_11 | 0.9286 | 0.9250 | 0.9268 | 9009 |

## Target vs Achieved

| Metric | Target | Achieved | Status |
|---|---:|---:|---:|
| Accuracy | > 85% | **89.1%** | ✅ |
| Macro F1 | > 82% | **91.9%** | ✅ |
| Top-3 Acc | > 95% | **99.9%** | ✅ |
| Inference | < 2ms | **0.018ms** | ✅ |

## Plots

| Plot | Link |
|---|---|
| Training curves | `plots/training_curves.png` |
| Confusion matrix | `plots/confusion_matrix.png` |
| Per-class metrics | `plots/per_class_metrics.png` |

