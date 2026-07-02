"""Statistical significance testing for method comparison results.

Provides:
- Mann-Whitney U test for pairwise method comparison across seeds.
- Bootstrap confidence intervals for Hits@50.
- Helper functions for reporting formatted results as LaTeX table rows.
"""

from __future__ import annotations

import math
from typing import Any

from src.experiments.results import aggregate_results


def collect_hits_by_method_scale(
    results: list[dict[str, Any]],
    split: str = "test",
    metric_key: str = "hits_at_50",
) -> dict[tuple[str, float], list[float]]:
    """Group Hits@50 values by (method, scale) across seeds."""
    groups: dict[tuple[str, float], list[float]] = {}
    for row in aggregate_results(results):
        if row.get("split") != split:
            continue
        method = str(row.get("method_name", "?"))
        scale = float(row.get("dataset_scale", 0))
        value = row.get(metric_key)
        if value is not None:
            key = (method, scale)
            groups.setdefault(key, []).append(float(value))
    return groups


def mann_whitney_u(
    sample_a: list[float],
    sample_b: list[float],
) -> dict[str, float]:
    """Compute Mann-Whitney U test between two independent samples.

    Returns U statistic and p-value (normal approximation for n > 20,
    exact otherwise). Uses a straightforward implementation without
    external dependencies beyond math.
    """
    n1, n2 = len(sample_a), len(sample_b)
    if n1 == 0 or n2 == 0:
        return {"u_statistic": 0.0, "p_value": 1.0, "n1": n1, "n2": n2}

    # Combine and rank all observations
    combined = [(val, 0) for val in sample_a] + [(val, 1) for val in sample_b]
    combined.sort(key=lambda x: x[0])

    # Assign ranks (handling ties with average rank)
    ranks = [0.0] * len(combined)
    i = 0
    while i < len(combined):
        j = i
        # Find all tied values
        while j < len(combined) and combined[j][0] == combined[i][0]:
            j += 1
        # Average rank for tied group
        avg_rank = (i + 1 + j) / 2.0
        for k in range(i, j):
            ranks[k] = avg_rank
        i = j

    # Sum ranks for sample_a (group 0)
    r1 = sum(rank for rank, (_, group) in zip(ranks, combined) if group == 0)
    u1 = r1 - n1 * (n1 + 1) / 2.0
    u2 = n1 * n2 - u1
    u_stat = min(u1, u2)

    # Normal approximation for p-value
    mu = n1 * n2 / 2.0
    # Tie correction
    tie_counts = {}
    for val, _ in combined:
        tie_counts[val] = tie_counts.get(val, 0) + 1
    tie_correction = sum(t**3 - t for t in tie_counts.values() if t > 1) / (
        12.0 * (n1 + n2) * (n1 + n2 - 1)
    )
    sigma = math.sqrt((n1 * n2 / 12.0) * ((n1 + n2 + 1) - tie_correction))

    if sigma > 0:
        z = (u_stat - mu) / sigma
        # Two-tailed p-value using normal CDF approximation
        p_value = 2.0 * (1.0 - _normal_cdf(abs(z)))
    else:
        p_value = 1.0

    return {
        "u_statistic": float(u_stat),
        "p_value": min(1.0, p_value),
        "n1": n1,
        "n2": n2,
    }


def _normal_cdf(x: float) -> float:
    """Approximate the standard normal CDF using the Abramowitz & Stegun formula."""
    if x < 0:
        return 1.0 - _normal_cdf(-x)
    # Constants
    b0, b1, b2 = 0.2316419, 0.319381530, -0.356563782
    b3, b4, b5 = 1.781477937, -1.821255978, 1.330274429
    t = 1.0 / (1.0 + b0 * x)
    phi = (1.0 / math.sqrt(2.0 * math.pi)) * math.exp(-0.5 * x * x)
    poly = b1 * t + b2 * t**2 + b3 * t**3 + b4 * t**4 + b5 * t**5
    return 1.0 - phi * poly


def bootstrap_ci(
    sample: list[float],
    n_resamples: int = 10_000,
    ci_level: float = 0.95,
    seed: int = 42,
) -> dict[str, float]:
    """Compute bootstrap confidence interval for the mean of a sample."""
    import random

    if not sample:
        return {"mean": 0.0, "ci_lower": 0.0, "ci_upper": 0.0, "n": 0}

    rng = random.Random(seed)
    n = len(sample)
    means: list[float] = []

    for _ in range(n_resamples):
        resample = [rng.choice(sample) for _ in range(n)]
        means.append(sum(resample) / n)

    means.sort()
    alpha = 1.0 - ci_level
    lower_idx = int(n_resamples * alpha / 2.0)
    upper_idx = int(n_resamples * (1.0 - alpha / 2.0))

    return {
        "mean": sum(sample) / n,
        "ci_lower": means[lower_idx],
        "ci_upper": means[upper_idx],
        "n": n,
        "std": (sum((v - sum(sample) / n) ** 2 for v in sample) / max(n - 1, 1)) ** 0.5,
    }


def compare_methods(
    results: list[dict[str, Any]],
    split: str = "test",
    metric_key: str = "hits_at_50",
) -> list[dict[str, Any]]:
    """Compare all pairs of methods at each scale with significance tests."""
    groups = collect_hits_by_method_scale(results, split=split, metric_key=metric_key)
    comparisons: list[dict[str, Any]] = []

    methods = sorted({k[0] for k in groups})
    scales = sorted({k[1] for k in groups})

    for scale in scales:
        scale_methods = {m: groups.get((m, scale), []) for m in methods}

        # Bootstrap CI for each method
        for method, vals in scale_methods.items():
            if len(vals) >= 2:
                ci = bootstrap_ci(vals, seed=42)
                comparisons.append({
                    "comparison": f"{method} (scale={scale})",
                    "type": "bootstrap_ci",
                    "method": method,
                    "scale": scale,
                    "mean": ci["mean"],
                    "ci_lower": ci["ci_lower"],
                    "ci_upper": ci["ci_upper"],
                    "std": ci["std"],
                    "n": ci["n"],
                })

        # Pairwise Mann-Whitney U tests
        for i in range(len(methods)):
            for j in range(i + 1, len(methods)):
                m1, m2 = methods[i], methods[j]
                v1, v2 = scale_methods[m1], scale_methods[m2]
                if len(v1) >= 2 and len(v2) >= 2:
                    test = mann_whitney_u(v1, v2)
                    comparisons.append({
                        "comparison": f"{m1} vs {m2} (scale={scale})",
                        "type": "mann_whitney",
                        "method_a": m1,
                        "method_b": m2,
                        "scale": scale,
                        "u_statistic": test["u_statistic"],
                        "p_value": test["p_value"],
                        "significant": test["p_value"] < 0.05,
                        "n1": test["n1"],
                        "n2": test["n2"],
                    })

    return comparisons


def format_significance_table(comparisons: list[dict[str, Any]]) -> str:
    """Format significance test results as a LaTeX table."""
    lines = [
        r"\begin{table}[H]",
        r"\centering",
        r"\caption{Statistical Significance Test Results (Mann-Whitney U, $\alpha=0.05$)}",
        r"\label{tab:significance}",
        r"\small",
        r"\begin{tabular}{lcccc}",
        r"\toprule",
        r"\textbf{Comparison} & \textbf{Scale} & \textbf{U} & \textbf{p-value} & \textbf{Significant} \\",
        r"\midrule",
    ]

    for comp in comparisons:
        if comp["type"] != "mann_whitney":
            continue
        sig = r"\checkmark" if comp.get("significant") else "---"
        lines.append(
            f"  {comp['method_a']} vs {comp['method_b']} & "
            f"{comp['scale']} & "
            f"{comp['u_statistic']:.0f} & "
            f"{comp['p_value']:.4f} & "
            f"{sig} \\\\"
        )

    lines.extend([
        r"\bottomrule",
        r"\end{tabular}",
        r"\end{table}",
    ])
    return "\n".join(lines)


def format_bootstrap_table(comparisons: list[dict[str, Any]]) -> str:
    """Format bootstrap CI results as a LaTeX table."""
    lines = [
        r"\begin{table}[H]",
        r"\centering",
        r"\caption{Bootstrap Confidence Intervals for Hits@50 (95\%, 10,000 resamples)}",
        r"\label{tab:bootstrap}",
        r"\small",
        r"\begin{tabular}{lcccc}",
        r"\toprule",
        r"\textbf{Method} & \textbf{Scale} & \textbf{Mean} & \textbf{95\% CI} & \textbf{Std} \\",
        r"\midrule",
    ]

    for comp in comparisons:
        if comp["type"] != "bootstrap_ci":
            continue
        lines.append(
            f"  {comp['method']} & {comp['scale']} & "
            f"{comp['mean']:.4f} & "
            f"[{comp['ci_lower']:.4f}, {comp['ci_upper']:.4f}] & "
            f"{comp['std']:.4f} \\\\"
        )

    lines.extend([
        r"\bottomrule",
        r"\end{tabular}",
        r"\end{table}",
    ])
    return "\n".join(lines)
