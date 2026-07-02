"""Phase 5 — Run all raw codec benchmarks + adaptive comparison.

Usage: source .venv/bin/activate && python3 -m src.benchmark.run_raw_codecs
"""

from __future__ import annotations

import json
import logging
import sys
import time
from pathlib import Path
from typing import Any

import numpy as np
import pandas as pd

logging.basicConfig(
    level=logging.INFO,
    format="%(asctime)s [%(levelname)s] %(name)s: %(message)s",
)
logger = logging.getLogger("benchmark")

PROJECT_ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(PROJECT_ROOT))

from src.codecs import huffman_codec, lzw_codec, arithmetic_codec, bwt_codec, rle_codec
from src.compression.adaptive_compressor import AdaptiveCompressor
from src.compression.adaptive_decompressor import AdaptiveDecompressor
from src.compression.profile_classifier import ProfileClassifier

CODECS = {
    "huffman": huffman_codec,
    "lzw": lzw_codec,
    "arithmetic": arithmetic_codec,
    "bwt_mtf": bwt_codec,
    "rle_huffman": rle_codec,
}

# Default params for each codec (same as grid search defaults)
DEFAULT_PARAMS = {
    "huffman": {"order": 0},
    "lzw": {"max_bits": 12},
    "arithmetic": {"order": 0},
    "bwt_mtf": {"secondary": "huffman", "block_size": 0},
    "rle_huffman": {"min_run": 3},
}


def get_test_books(project_root: Path, max_books: int = 50, chars_per_book: int = 20000) -> list[dict]:
    """Get test books from the processed directory."""
    books_dir = project_root / "data" / "processed" / "books"
    split_path = project_root / "data" / "processed" / "book_splits.csv"

    import csv
    with open(split_path, "r", encoding="utf-8", newline="") as f:
        splits = {r["book_id"]: r["split"] for r in csv.DictReader(f)}

    book_files = sorted(books_dir.glob("*.txt"))
    books = []
    for bf in book_files:
        bid = bf.stem
        split = splits.get(bid, "train")
        if split != "test":
            continue
        text = bf.read_text(encoding="utf-8")[:chars_per_book]
        if len(text) < 100:
            continue
        books.append({"book_id": bid, "text": text, "split": split})
        if len(books) >= max_books:
            break

    return books


def benchmark_raw_codecs(books: list[dict]) -> pd.DataFrame:
    """Run all 5 codecs on all test books, return metrics."""
    rows = []

    for book in books:
        text = book["text"]
        data = text.encode("utf-8")
        original_size = len(data)

        for algo_name, codec in CODECS.items():
            params = DEFAULT_PARAMS[algo_name]

            # Decompress params — only pass what the decompress function accepts
            decompress_params = {}
            if algo_name in ("huffman", "arithmetic"):
                decompress_params = {"order": params.get("order", 0)}
            elif algo_name == "lzw":
                decompress_params = {"max_bits": params.get("max_bits", 12)}
            # bwt_mtf and rle_huffman decompress take no extra params

            # Compress
            t0 = time.perf_counter()
            result = codec.compress(data, **params)
            compress_ms = (time.perf_counter() - t0) * 1000

            if not result.valid:
                rows.append({
                    "book_id": book["book_id"],
                    "algorithm": algo_name,
                    "bpb": float("nan"),
                    "compression_ratio": float("nan"),
                    "compress_ms_per_kb": float("nan"),
                    "decompress_ms_per_kb": float("nan"),
                    "valid": False,
                    "error": result.error,
                })
                continue

            # Decompress
            t0 = time.perf_counter()
            decompress_result = codec.decompress(result.compressed, **decompress_params)
            decompress_ms = (time.perf_counter() - t0) * 1000

            # Verify lossless
            lossless = decompress_result.valid and decompress_result.compressed == data

            rows.append({
                "book_id": book["book_id"],
                "algorithm": algo_name,
                "bpb": result.bpb,
                "compression_ratio": result.compression_ratio,
                "compress_ms_per_kb": compress_ms / (original_size / 1024) if original_size else 0,
                "decompress_ms_per_kb": decompress_ms / (original_size / 1024) if original_size else 0,
                "valid": True,
                "lossless": lossless,
            })

    return pd.DataFrame(rows)


def benchmark_adaptive(books: list[dict], phase3_dir: Path, mapping_path: Path, chunk_size: int = 512) -> pd.DataFrame:
    """Run adaptive compression on all test books, return metrics."""
    compressor = AdaptiveCompressor(phase3_dir, mapping_path, chunk_size=chunk_size)
    decompressor = AdaptiveDecompressor(mapping_path=mapping_path)

    rows = []
    for book in books:
        text = book["text"]
        data = text.encode("utf-8")
        original_size = len(data)

        # Compress
        t0 = time.perf_counter()
        compressed = compressor.compress(text)
        compress_ms = (time.perf_counter() - t0) * 1000

        # Decompress
        t0 = time.perf_counter()
        decompressed = decompressor.decompress(compressed)
        decompress_ms = (time.perf_counter() - t0) * 1000

        lossless = decompressed == text

        rows.append({
            "book_id": book["book_id"],
            "algorithm": "adaptive",
            "bpb": len(compressed) * 8 / original_size if original_size else 0,
            "compression_ratio": len(compressed) / original_size if original_size else 1.0,
            "compress_ms_per_kb": compress_ms / (original_size / 1024) if original_size else 0,
            "decompress_ms_per_kb": decompress_ms / (original_size / 1024) if original_size else 0,
            "valid": True,
            "lossless": lossless,
        })

    return pd.DataFrame(rows)


def main() -> int:
    project_root = PROJECT_ROOT
    artifacts_dir = project_root / "artifacts" / "phase5"
    artifacts_dir.mkdir(parents=True, exist_ok=True)

    phase3_dir = project_root / "artifacts" / "phase3"
    mapping_path = project_root / "artifacts" / "phase2" / "profile_algorithm_mapping.json"

    logger.info("Loading test books...")
    books = get_test_books(project_root, max_books=50)
    logger.info("Found %d test books", len(books))

    # Raw codecs benchmark
    logger.info("Running raw codec benchmarks...")
    raw_df = benchmark_raw_codecs(books)
    raw_df.to_csv(artifacts_dir / "raw_codec_results.csv", index=False)
    raw_df.to_parquet(artifacts_dir / "raw_codec_results.parquet", index=False)
    logger.info("Raw benchmarks done: %d rows", len(raw_df))

    # Adaptive benchmark
    logger.info("Running adaptive compression benchmark...")
    adaptive_df = benchmark_adaptive(books, phase3_dir, mapping_path)
    adaptive_df.to_csv(artifacts_dir / "adaptive_results.csv", index=False)
    logger.info("Adaptive benchmark done: %d rows", len(adaptive_df))

    # Combined comparison
    combined = pd.concat([raw_df, adaptive_df], ignore_index=True)

    # Best single codec analysis
    raw_valid = raw_df[raw_df["valid"]].copy()
    avg_bpb = raw_valid.groupby("algorithm")["bpb"].agg(["mean", "median", "std"])
    avg_bpb.columns = ["mean_bpb", "median_bpb", "std_bpb"]
    avg_bpb = avg_bpb.sort_values("mean_bpb")

    best_algo = avg_bpb.index[0]
    best_bpb = avg_bpb.iloc[0]["mean_bpb"]
    adaptive_avg = adaptive_df["bpb"].mean()

    # Summary
    summary = {
        "raw_codecs": {
            algo: {
                "mean_bpb": float(avg_bpb.loc[algo, "mean_bpb"]),
                "median_bpb": float(avg_bpb.loc[algo, "median_bpb"]),
                "std_bpb": float(avg_bpb.loc[algo, "std_bpb"]),
            }
            for algo in avg_bpb.index
        },
        "adaptive": {
            "mean_bpb": float(adaptive_avg),
            "num_books": len(adaptive_df),
        },
        "best_single_codec": {
            "algorithm": best_algo,
            "mean_bpb": float(best_bpb),
        },
        "adaptive_improvement_vs_best_single": {
            "bpb_delta": float(best_bpb - adaptive_avg),
            "percent_improvement": float((best_bpb - adaptive_avg) / best_bpb * 100) if best_bpb > 0 else 0,
        },
    }

    with open(artifacts_dir / "benchmark_summary.json", "w") as f:
        json.dump(summary, f, indent=2)

    logger.info("=" * 60)
    logger.info("BENCHMARK RESULTS")
    logger.info("=" * 60)
    logger.info("Raw codecs (mean BPB):")
    for algo in avg_bpb.index:
        row = avg_bpb.loc[algo]
        logger.info("  %15s: %.4f (median=%.4f, std=%.4f)", algo, row["mean_bpb"], row["median_bpb"], row["std_bpb"])
    logger.info("")
    logger.info("Adaptive system: %.4f BPB", adaptive_avg)
    logger.info("Best single codec: %s (%.4f BPB)", best_algo, best_bpb)
    logger.info("Adaptive improvement vs best single: %.4f BPB (%.1f%%)",
                summary["adaptive_improvement_vs_best_single"]["bpb_delta"],
                summary["adaptive_improvement_vs_best_single"]["percent_improvement"])
    logger.info("=" * 60)

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
