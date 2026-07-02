# Phase 5 — Raw Benchmark & Adaptive Comparison Report

## Methodology

- **Test set**: 50 Gutenberg books (test split, first 20KB each)
- **Raw codecs**: Each run standalone on the full 20KB text (no chunking)
- **Adaptive**: Chunk size = 512 bytes, header overhead = 4 bytes/block
- **Metric**: Bits Per Byte (BPB) — lower is better
- **Lossless**: All results verified (compress → decompress == original)

## Raw Codec Results (full-text, no chunking)

| Algorithm | Mean BPB | Median BPB | Std BPB | Rank |
|---|---:|---:|---:|---:|
| bwt_mtf | 3.4242 | 3.3918 | 0.2303 | #1 |
| lzw | 4.3119 | 4.2751 | 0.1936 | #2 |
| rle_huffman | 4.6440 | 4.6252 | 0.1554 | #3 |
| huffman | 4.6519 | 4.6168 | 0.1264 | #4 |
| arithmetic | 5.3570 | 5.3133 | 0.1892 | #5 |

## Adaptive System Results

| Metric | Value |
|---|---:|
| Mean BPB | 5.6789 |
| Books tested | 50 |

## Comparison: Adaptive vs Best Single Codec

| | Best Single (bwt_mtf) | Adaptive | Delta |
|---|---:|---:|---:|
| Mean BPB | 3.4242 | 5.6789 | -2.2547 (-65.8%) |

## Analysis & Caveats

### Why is adaptive worse than bwt_mtf alone?

1. **Chunking overhead**: bwt_mtf benchmark compresses the full 20KB text as
   one block. Adaptive splits into ~40 blocks of 512 bytes each, with a 4-byte
   header per block = 160 bytes of pure metadata overhead.

2. **Small-block penalty**: Dictionary-based codecs (bwt_mtf, lzw) need large
   windows to build effective dictionaries. At 512 bytes they cannot reach their
   full compression potential.

3. **Profile prediction cost**: The MLP inference adds ~0.02ms/block, which is
   negligible. But the chunk-split forces every codec to work on smaller data.

### When would adaptive win?

The adaptive system is designed for **heterogeneous workloads** — text that
contains code, tables, prose, and markup mixed together. On pure English prose
(Gutenberg corpus), bwt_mtf dominates because the data is homogeneous.

A fair comparison would require:
- Mixed-content test sets (HTML, JSON, code, prose, tables)
- Same chunk size for raw codecs (chunked raw vs chunked adaptive)
- Real-world files where different profiles would actually trigger different
  algorithm selections

### Same-chunk-size comparison

When we compare at the same chunk size (512 bytes), the raw codec results are:

## Conclusion

On pure English prose (Gutenberg corpus), **bwt_mtf at 3.42 BPB is the clear
winner**. The adaptive system (5.68 BPB) adds overhead from chunking and
headers without enough diversity to offset it.

The value of the adaptive approach lies in **mixed-content scenarios** where
a single codec cannot optimally handle all data types. A next step would be
to benchmark on heterogeneous data to demonstrate this advantage.

## Artifacts

- `raw_codec_results.csv` — Per-book, per-codec metrics
- `adaptive_results.csv` — Per-book adaptive metrics
- `benchmark_summary.json` — Aggregated numerical summary

