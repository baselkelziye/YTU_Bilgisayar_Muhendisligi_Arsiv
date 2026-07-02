"""Experiment tracking — live status, per-run summaries, cross-run comparisons.

Usage:
    from src.experiments.tracking import show_benchmark_status
    show_benchmark_status()  # prints to console

    # Or from Python:
    status = get_benchmark_status()
    print(json.dumps(status, indent=2))
"""

from __future__ import annotations

import json
import subprocess
import sys
from collections import defaultdict
from datetime import datetime, timezone
from pathlib import Path
from typing import Any

from src.experiments.paths import RAW_RESULTS_DIR
from src.experiments.results import load_results

# ── Helpers ──────────────────────────────────────────────────────────────


def _find_running_benchmarks() -> list[dict[str, Any]]:
    """Detect any running benchmark processes."""
    try:
        result = subprocess.run(
            ["pgrep", "-af", "run_multi_seed"],
            capture_output=True, text=True, timeout=3,
        )
        processes = []
        for line in result.stdout.strip().split("\n"):
            if not line.strip():
                continue
            pid, *cmd = line.split(maxsplit=1)
            cmd_str = " ".join(cmd)
            processes.append({"pid": int(pid), "command": cmd_str[:120]})
        return processes
    except (subprocess.TimeoutExpired, FileNotFoundError):
        return []


def _summarize_results(results: list[dict]) -> dict[str, Any]:
    """Build a compact summary of all completed results."""
    by_method_scale: dict[tuple[str, float], dict] = defaultdict(
        lambda: {"count": 0, "hits": [], "total_time": 0.0, "seeds": []}
    )

    for r in results:
        method = r.get("method_name", "?")
        scale = float(r.get("dataset_scale", 0))
        status = r.get("status", "?")
        key = (method, scale)

        test_metrics = r.get("metrics", {}).get("test", {})
        hits50 = test_metrics.get("hits_at_50", 0)
        runtime = r.get("runtime_seconds", 0)

        if status == "completed" and hits50 > 0.001:  # valid result
            entry = by_method_scale[key]
            entry["count"] += 1
            entry["hits"].append(hits50)
            entry["total_time"] += runtime
            entry["seeds"].append(r.get("seed", "?"))
            entry["method"] = method
            entry["scale"] = scale

    summary = {}
    for key, val in sorted(by_method_scale.items()):
        method, scale = key
        hits = val["hits"]
        avg_hits = sum(hits) / len(hits) if hits else 0
        summary[f"{method}@{scale}"] = {
            "method": method,
            "scale": scale,
            "runs": val["count"],
            "avg_hits@50": round(avg_hits, 4),
            "max_hits@50": round(max(hits), 4) if hits else 0,
            "min_hits@50": round(min(hits), 4) if hits else 0,
            "total_time_s": round(val["total_time"], 1),
            "seeds": val["seeds"],
        }

    return summary


# ── Public API ────────────────────────────────────────────────────────────


def get_benchmark_status() -> dict[str, Any]:
    """Return current benchmark status with running processes + completed results."""
    results = load_results(RAW_RESULTS_DIR)
    running = _find_running_benchmarks()

    return {
        "timestamp": datetime.now(timezone.utc).strftime("%Y-%m-%d %H:%M:%S UTC"),
        "total_runs": len(results),
        "running_benchmarks": running or None,
        "summary": _summarize_results(results),
    }


def show_benchmark_status() -> None:
    """Pretty-print benchmark status to console."""
    status = get_benchmark_status()

    print(f"\n{'='*60}")
    print(f"  ogbl-collab — Experiment Tracking")
    print(f"  {status['timestamp']}")
    print(f"  Total runs: {status['total_runs']}")
    print(f"{'='*60}")

    if status.get("running_benchmarks"):
        print(f"\n  ▶ Running benchmarks: {len(status['running_benchmarks'])}")
        for proc in status["running_benchmarks"]:
            print(f"      PID {proc['pid']}: {proc['command']}")
    else:
        print(f"\n  ⏸ No benchmarks currently running")

    print(f"\n  {'Method':20s} {'Scale':6s} {'Runs':5s} {'Avg H@50':10s} {'Max H@50':10s} {'Time':8s}  Seeds")
    print(f"  {'─'*75}")
    for key, val in status.get("summary", {}).items():
        seeds_str = ",".join(str(s) for s in val["seeds"])
        print(
            f"  {val['method']:20s} {val['scale']:<6.1f} {val['runs']:3d}   "
            f"{val['avg_hits@50']:.4f}    {val['max_hits@50']:.4f}    "
            f"{val['total_time_s']:5.0f}s  [{seeds_str}]"
        )
    print()


def print_latest_results(n: int = 5) -> None:
    """Print the N most recent experiment results."""
    results = load_results(RAW_RESULTS_DIR)
    sorted_results = sorted(
        results,
        key=lambda r: r.get("timestamp", ""),
        reverse=True,
    )[:n]

    print(f"\nLast {n} results:")
    print(f"  {'Timestamp':16s} {'Method':20s} {'Scale':6s} {'Hits@50':8s} {'Hits@100':9s} {'Runtime':8s}")
    print(f"  {'─'*70}")
    for r in sorted_results:
        ts = r.get("timestamp", "")[8:15] if r.get("timestamp") else "?"
        method = r.get("method_name", "?")
        scale = str(r.get("dataset_scale", "?"))
        test = r.get("metrics", {}).get("test", {})
        h50 = test.get("hits_at_50", 0)
        h100 = test.get("hits_at_100", 0)
        runtime = r.get("runtime_seconds", 0)
        print(f"  {ts:16s} {method:20s} {scale:6s} {h50:.4f}    {h100:.4f}    {runtime:5.0f}s")
    print()


if __name__ == "__main__":
    if "--latest" in sys.argv:
        print_latest_results()
    show_benchmark_status()
