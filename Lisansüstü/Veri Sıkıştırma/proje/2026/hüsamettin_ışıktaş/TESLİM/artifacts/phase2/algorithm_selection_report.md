# Phase 2 Algorithm Selection Report

Selected best `(algorithm_id, parameter_set_id)` per `profile_id` using:
- primary: **min mean_bpb**
- tie-break: **min mean_ms_per_kb**

## Winners

- **profile_3**: `lzw` / `lzw:f6cdb2b9` (bpb=3.3839, ms/KB=0.3166, valid_rate=1.000, n=300)
- **profile_4**: `bwt_mtf` / `bwt_mtf:f71fe5f5` (bpb=4.0455, ms/KB=0.6445, valid_rate=1.000, n=300)
- **profile_9**: `lzw` / `lzw:f6cdb2b9` (bpb=4.8010, ms/KB=0.3863, valid_rate=1.000, n=300)
- **profile_6**: `huffman` / `huffman:698b2692` (bpb=5.4473, ms/KB=0.2219, valid_rate=1.000, n=300)
- **profile_0**: `huffman` / `huffman:698b2692` (bpb=5.5105, ms/KB=0.2257, valid_rate=1.000, n=300)
- **profile_2**: `lzw` / `lzw:f6cdb2b9` (bpb=5.6075, ms/KB=0.4203, valid_rate=1.000, n=300)
- **profile_1**: `huffman` / `huffman:698b2692` (bpb=5.7989, ms/KB=0.2382, valid_rate=1.000, n=300)
- **profile_11**: `huffman` / `huffman:698b2692` (bpb=5.8244, ms/KB=0.2376, valid_rate=1.000, n=300)
- **profile_10**: `lzw` / `lzw:f6cdb2b9` (bpb=5.9971, ms/KB=0.4359, valid_rate=1.000, n=300)
- **profile_5**: `lzw` / `lzw:9401c600` (bpb=6.3029, ms/KB=0.4519, valid_rate=1.000, n=300)
- **profile_7**: `lzw` / `lzw:513772ed` (bpb=8.1694, ms/KB=0.8312, valid_rate=1.000, n=33)

## Per-Profile Detail

### profile_3

- **Winner**: `lzw` / `lzw:f6cdb2b9`
- **Mean BPB**: 3.3839
- **Median BPB**: 3.4164
- **P95 BPB**: 3.9844
- **Std BPB**: 0.4000
- **Mean ms/KB**: 0.3166
- **Median ms/KB**: 0.3094
- **Samples**: 300
- **Valid Rate**: 1.000

| Algorithm | Params | Mean BPB | Samples |
|---|---|---|---|
| lzw | lzw:5b1cbd79 | 3.3839 | 300  |
| lzw | lzw:9401c600 | 3.3839 | 300  |
| lzw | lzw:dfb0cc29 | 3.3839 | 300  |
| lzw | lzw:c5719257 | 3.3839 | 300  |
| lzw | lzw:513772ed | 3.3839 | 300  |
| lzw | lzw:028a3688 | 3.3839 | 300  |
| lzw | lzw:f6cdb2b9 | 3.3839 | 300 ← **winner** |
| lzw | lzw:3f8f9d68 | 3.3848 | 300  |
| rle_huffman | rle_huffman:f4a08084 | 4.0991 | 300  |
| rle_huffman | rle_huffman:b5e74fdf | 4.1444 | 300  |
| rle_huffman | rle_huffman:f2127aa9 | 4.1746 | 300  |
| huffman | huffman:698b2692 | 4.1780 | 300  |
| rle_huffman | rle_huffman:dd60b8b3 | 4.2130 | 300  |
| bwt_mtf | bwt_mtf:9600795c | 4.4027 | 300  |
| bwt_mtf | bwt_mtf:f71fe5f5 | 4.4027 | 300  |
| huffman | huffman:258695c0 | 7.4322 | 300  |
| bwt_mtf | bwt_mtf:10be2f87 | 11.7154 | 300  |
| bwt_mtf | bwt_mtf:58e08891 | 11.7154 | 300  |
| arithmetic | arithmetic:314eeb03 | 11.9909 | 300  |
| arithmetic | arithmetic:cab31594 | 988.5422 | 300  |
| arithmetic | arithmetic:dc8dce82 | 2039.9069 | 300  |

### profile_4

- **Winner**: `bwt_mtf` / `bwt_mtf:f71fe5f5`
- **Mean BPB**: 4.0455
- **Median BPB**: 3.9844
- **P95 BPB**: 4.8289
- **Std BPB**: 0.3364
- **Mean ms/KB**: 0.6445
- **Median ms/KB**: 0.6184
- **Samples**: 300
- **Valid Rate**: 1.000

| Algorithm | Params | Mean BPB | Samples |
|---|---|---|---|
| bwt_mtf | bwt_mtf:f71fe5f5 | 4.0455 | 300 ← **winner** |
| bwt_mtf | bwt_mtf:9600795c | 4.0455 | 300  |
| huffman | huffman:698b2692 | 4.0458 | 300  |
| rle_huffman | rle_huffman:f4a08084 | 4.1222 | 300  |
| rle_huffman | rle_huffman:b5e74fdf | 4.1438 | 300  |
| lzw | lzw:513772ed | 4.2748 | 300  |
| lzw | lzw:5b1cbd79 | 4.2748 | 300  |
| lzw | lzw:9401c600 | 4.2748 | 300  |
| lzw | lzw:dfb0cc29 | 4.2748 | 300  |
| lzw | lzw:f6cdb2b9 | 4.2748 | 300  |
| lzw | lzw:028a3688 | 4.2748 | 300  |
| lzw | lzw:c5719257 | 4.2748 | 300  |
| lzw | lzw:3f8f9d68 | 4.2927 | 300  |
| rle_huffman | rle_huffman:f2127aa9 | 4.3954 | 300  |
| rle_huffman | rle_huffman:dd60b8b3 | 4.4845 | 300  |
| huffman | huffman:258695c0 | 7.2730 | 300  |
| bwt_mtf | bwt_mtf:10be2f87 | 12.3951 | 300  |
| bwt_mtf | bwt_mtf:58e08891 | 12.3951 | 300  |
| arithmetic | arithmetic:314eeb03 | 12.7153 | 300  |
| arithmetic | arithmetic:cab31594 | 1008.5304 | 300  |
| arithmetic | arithmetic:dc8dce82 | 2050.2802 | 300  |

### profile_9

- **Winner**: `lzw` / `lzw:f6cdb2b9`
- **Mean BPB**: 4.8010
- **Median BPB**: 4.8000
- **P95 BPB**: 5.4157
- **Std BPB**: 0.3823
- **Mean ms/KB**: 0.3863
- **Median ms/KB**: 0.3780
- **Samples**: 300
- **Valid Rate**: 1.000

| Algorithm | Params | Mean BPB | Samples |
|---|---|---|---|
| lzw | lzw:5b1cbd79 | 4.8010 | 300  |
| lzw | lzw:9401c600 | 4.8010 | 300  |
| lzw | lzw:dfb0cc29 | 4.8010 | 300  |
| lzw | lzw:c5719257 | 4.8010 | 300  |
| lzw | lzw:513772ed | 4.8010 | 300  |
| lzw | lzw:028a3688 | 4.8010 | 300  |
| lzw | lzw:f6cdb2b9 | 4.8010 | 300 ← **winner** |
| lzw | lzw:3f8f9d68 | 4.9439 | 300  |
| rle_huffman | rle_huffman:f4a08084 | 5.4074 | 300  |
| rle_huffman | rle_huffman:b5e74fdf | 5.4385 | 300  |
| rle_huffman | rle_huffman:f2127aa9 | 5.4638 | 300  |
| rle_huffman | rle_huffman:dd60b8b3 | 5.4955 | 300  |
| huffman | huffman:698b2692 | 5.5053 | 300  |
| bwt_mtf | bwt_mtf:9600795c | 5.9385 | 300  |
| bwt_mtf | bwt_mtf:f71fe5f5 | 5.9385 | 300  |
| huffman | huffman:258695c0 | 10.4205 | 300  |
| bwt_mtf | bwt_mtf:10be2f87 | 12.8727 | 300  |
| bwt_mtf | bwt_mtf:58e08891 | 12.8727 | 300  |
| arithmetic | arithmetic:314eeb03 | 13.0508 | 300  |
| arithmetic | arithmetic:cab31594 | 1525.5014 | 300  |
| arithmetic | arithmetic:dc8dce82 | 2036.9682 | 300  |

### profile_6

- **Winner**: `huffman` / `huffman:698b2692`
- **Mean BPB**: 5.4473
- **Median BPB**: 5.4297
- **P95 BPB**: 5.7253
- **Std BPB**: 0.1567
- **Mean ms/KB**: 0.2219
- **Median ms/KB**: 0.2180
- **Samples**: 300
- **Valid Rate**: 1.000

| Algorithm | Params | Mean BPB | Samples |
|---|---|---|---|
| huffman | huffman:698b2692 | 5.4473 | 300 ← **winner** |
| rle_huffman | rle_huffman:f4a08084 | 5.5255 | 300  |
| rle_huffman | rle_huffman:b5e74fdf | 5.5269 | 300  |
| rle_huffman | rle_huffman:f2127aa9 | 5.5327 | 300  |
| rle_huffman | rle_huffman:dd60b8b3 | 5.5341 | 300  |
| lzw | lzw:5b1cbd79 | 5.7900 | 300  |
| lzw | lzw:9401c600 | 5.7900 | 300  |
| lzw | lzw:dfb0cc29 | 5.7900 | 300  |
| lzw | lzw:028a3688 | 5.7900 | 300  |
| lzw | lzw:513772ed | 5.7900 | 300  |
| lzw | lzw:c5719257 | 5.7900 | 300  |
| lzw | lzw:f6cdb2b9 | 5.7900 | 300  |
| bwt_mtf | bwt_mtf:9600795c | 6.0029 | 300  |
| bwt_mtf | bwt_mtf:f71fe5f5 | 6.0029 | 300  |
| lzw | lzw:3f8f9d68 | 6.2637 | 300  |
| huffman | huffman:258695c0 | 10.7942 | 300  |
| arithmetic | arithmetic:314eeb03 | 13.5312 | 300  |
| bwt_mtf | bwt_mtf:58e08891 | 13.5389 | 300  |
| bwt_mtf | bwt_mtf:10be2f87 | 13.5389 | 300  |
| arithmetic | arithmetic:cab31594 | 1601.3433 | 300  |
| arithmetic | arithmetic:dc8dce82 | 2050.9568 | 300  |

### profile_0

- **Winner**: `huffman` / `huffman:698b2692`
- **Mean BPB**: 5.5105
- **Median BPB**: 5.4844
- **P95 BPB**: 5.8289
- **Std BPB**: 0.1826
- **Mean ms/KB**: 0.2257
- **Median ms/KB**: 0.2175
- **Samples**: 300
- **Valid Rate**: 1.000

| Algorithm | Params | Mean BPB | Samples |
|---|---|---|---|
| huffman | huffman:698b2692 | 5.5105 | 300 ← **winner** |
| rle_huffman | rle_huffman:f4a08084 | 5.5885 | 300  |
| rle_huffman | rle_huffman:b5e74fdf | 5.5906 | 300  |
| rle_huffman | rle_huffman:f2127aa9 | 5.5940 | 300  |
| rle_huffman | rle_huffman:dd60b8b3 | 5.5947 | 300  |
| lzw | lzw:5b1cbd79 | 5.9072 | 300  |
| lzw | lzw:9401c600 | 5.9072 | 300  |
| lzw | lzw:dfb0cc29 | 5.9072 | 300  |
| lzw | lzw:028a3688 | 5.9072 | 300  |
| lzw | lzw:513772ed | 5.9072 | 300  |
| lzw | lzw:c5719257 | 5.9072 | 300  |
| lzw | lzw:f6cdb2b9 | 5.9072 | 300  |
| bwt_mtf | bwt_mtf:9600795c | 6.1723 | 300  |
| bwt_mtf | bwt_mtf:f71fe5f5 | 6.1723 | 300  |
| lzw | lzw:3f8f9d68 | 6.3909 | 300  |
| huffman | huffman:258695c0 | 11.2142 | 300  |
| arithmetic | arithmetic:314eeb03 | 13.5726 | 300  |
| bwt_mtf | bwt_mtf:58e08891 | 13.6670 | 300  |
| bwt_mtf | bwt_mtf:10be2f87 | 13.6670 | 300  |
| arithmetic | arithmetic:cab31594 | 1678.8965 | 300  |
| arithmetic | arithmetic:dc8dce82 | 2052.0400 | 300  |

### profile_2

- **Winner**: `lzw` / `lzw:f6cdb2b9`
- **Mean BPB**: 5.6075
- **Median BPB**: 5.6339
- **P95 BPB**: 5.9375
- **Std BPB**: 0.2316
- **Mean ms/KB**: 0.4203
- **Median ms/KB**: 0.4158
- **Samples**: 300
- **Valid Rate**: 1.000

| Algorithm | Params | Mean BPB | Samples |
|---|---|---|---|
| lzw | lzw:5b1cbd79 | 5.6075 | 300  |
| lzw | lzw:9401c600 | 5.6075 | 300  |
| lzw | lzw:dfb0cc29 | 5.6075 | 300  |
| lzw | lzw:c5719257 | 5.6075 | 300  |
| lzw | lzw:513772ed | 5.6075 | 300  |
| lzw | lzw:028a3688 | 5.6075 | 300  |
| lzw | lzw:f6cdb2b9 | 5.6075 | 300 ← **winner** |
| huffman | huffman:698b2692 | 5.8015 | 300  |
| rle_huffman | rle_huffman:f4a08084 | 5.8403 | 300  |
| rle_huffman | rle_huffman:b5e74fdf | 5.8802 | 300  |
| rle_huffman | rle_huffman:f2127aa9 | 5.9234 | 300  |
| rle_huffman | rle_huffman:dd60b8b3 | 5.9445 | 300  |
| lzw | lzw:3f8f9d68 | 5.9945 | 300  |
| bwt_mtf | bwt_mtf:9600795c | 6.2995 | 300  |
| bwt_mtf | bwt_mtf:f71fe5f5 | 6.2995 | 300  |
| huffman | huffman:258695c0 | 11.3233 | 300  |
| bwt_mtf | bwt_mtf:10be2f87 | 13.3872 | 300  |
| bwt_mtf | bwt_mtf:58e08891 | 13.3872 | 300  |
| arithmetic | arithmetic:314eeb03 | 13.5089 | 300  |
| arithmetic | arithmetic:cab31594 | 1665.8414 | 300  |
| arithmetic | arithmetic:dc8dce82 | 2045.0832 | 300  |

### profile_1

- **Winner**: `huffman` / `huffman:698b2692`
- **Mean BPB**: 5.7989
- **Median BPB**: 5.7735
- **P95 BPB**: 6.2046
- **Std BPB**: 0.2178
- **Mean ms/KB**: 0.2382
- **Median ms/KB**: 0.2331
- **Samples**: 300
- **Valid Rate**: 1.000

| Algorithm | Params | Mean BPB | Samples |
|---|---|---|---|
| huffman | huffman:698b2692 | 5.7989 | 300 ← **winner** |
| rle_huffman | rle_huffman:f4a08084 | 5.8772 | 300  |
| rle_huffman | rle_huffman:b5e74fdf | 5.8810 | 300  |
| rle_huffman | rle_huffman:f2127aa9 | 5.8869 | 300  |
| rle_huffman | rle_huffman:dd60b8b3 | 5.8980 | 300  |
| lzw | lzw:5b1cbd79 | 6.0451 | 300  |
| lzw | lzw:9401c600 | 6.0451 | 300  |
| lzw | lzw:dfb0cc29 | 6.0451 | 300  |
| lzw | lzw:028a3688 | 6.0451 | 300  |
| lzw | lzw:513772ed | 6.0451 | 300  |
| lzw | lzw:c5719257 | 6.0451 | 300  |
| lzw | lzw:f6cdb2b9 | 6.0451 | 300  |
| bwt_mtf | bwt_mtf:9600795c | 6.4895 | 300  |
| bwt_mtf | bwt_mtf:f71fe5f5 | 6.4895 | 300  |
| lzw | lzw:3f8f9d68 | 6.5199 | 300  |
| huffman | huffman:258695c0 | 11.8311 | 300  |
| arithmetic | arithmetic:314eeb03 | 13.6328 | 300  |
| bwt_mtf | bwt_mtf:58e08891 | 13.7331 | 300  |
| bwt_mtf | bwt_mtf:10be2f87 | 13.7331 | 300  |
| arithmetic | arithmetic:cab31594 | 1775.0403 | 300  |
| arithmetic | arithmetic:dc8dce82 | 2043.4234 | 300  |

### profile_11

- **Winner**: `huffman` / `huffman:698b2692`
- **Mean BPB**: 5.8244
- **Median BPB**: 5.8114
- **P95 BPB**: 6.1822
- **Std BPB**: 0.2245
- **Mean ms/KB**: 0.2376
- **Median ms/KB**: 0.2330
- **Samples**: 300
- **Valid Rate**: 1.000

| Algorithm | Params | Mean BPB | Samples |
|---|---|---|---|
| huffman | huffman:698b2692 | 5.8244 | 300 ← **winner** |
| rle_huffman | rle_huffman:f4a08084 | 5.9022 | 300  |
| rle_huffman | rle_huffman:b5e74fdf | 5.9060 | 300  |
| rle_huffman | rle_huffman:f2127aa9 | 5.9173 | 300  |
| rle_huffman | rle_huffman:dd60b8b3 | 5.9255 | 300  |
| lzw | lzw:5b1cbd79 | 5.9784 | 300  |
| lzw | lzw:9401c600 | 5.9784 | 300  |
| lzw | lzw:dfb0cc29 | 5.9784 | 300  |
| lzw | lzw:028a3688 | 5.9784 | 300  |
| lzw | lzw:513772ed | 5.9784 | 300  |
| lzw | lzw:c5719257 | 5.9784 | 300  |
| lzw | lzw:f6cdb2b9 | 5.9784 | 300  |
| bwt_mtf | bwt_mtf:9600795c | 6.3771 | 300  |
| bwt_mtf | bwt_mtf:f71fe5f5 | 6.3771 | 300  |
| lzw | lzw:3f8f9d68 | 6.4640 | 300  |
| huffman | huffman:258695c0 | 11.5240 | 300  |
| bwt_mtf | bwt_mtf:10be2f87 | 13.5695 | 300  |
| bwt_mtf | bwt_mtf:58e08891 | 13.5695 | 300  |
| arithmetic | arithmetic:314eeb03 | 13.6194 | 300  |
| arithmetic | arithmetic:cab31594 | 1725.7049 | 300  |
| arithmetic | arithmetic:dc8dce82 | 2028.8007 | 300  |

### profile_10

- **Winner**: `lzw` / `lzw:f6cdb2b9`
- **Mean BPB**: 5.9971
- **Median BPB**: 6.0156
- **P95 BPB**: 6.5787
- **Std BPB**: 0.3987
- **Mean ms/KB**: 0.4359
- **Median ms/KB**: 0.4327
- **Samples**: 300
- **Valid Rate**: 1.000

| Algorithm | Params | Mean BPB | Samples |
|---|---|---|---|
| lzw | lzw:5b1cbd79 | 5.9971 | 300  |
| lzw | lzw:9401c600 | 5.9971 | 300  |
| lzw | lzw:dfb0cc29 | 5.9971 | 300  |
| lzw | lzw:c5719257 | 5.9971 | 300  |
| lzw | lzw:513772ed | 5.9971 | 300  |
| lzw | lzw:028a3688 | 5.9971 | 300  |
| lzw | lzw:f6cdb2b9 | 5.9971 | 300 ← **winner** |
| lzw | lzw:3f8f9d68 | 6.4073 | 300  |
| huffman | huffman:698b2692 | 6.6672 | 300  |
| rle_huffman | rle_huffman:f4a08084 | 6.7474 | 300  |
| rle_huffman | rle_huffman:b5e74fdf | 6.7712 | 300  |
| rle_huffman | rle_huffman:f2127aa9 | 6.8119 | 300  |
| bwt_mtf | bwt_mtf:9600795c | 6.8239 | 300  |
| bwt_mtf | bwt_mtf:f71fe5f5 | 6.8239 | 300  |
| rle_huffman | rle_huffman:dd60b8b3 | 6.8612 | 300  |
| huffman | huffman:258695c0 | 12.5851 | 300  |
| bwt_mtf | bwt_mtf:10be2f87 | 13.4916 | 300  |
| bwt_mtf | bwt_mtf:58e08891 | 13.4916 | 300  |
| arithmetic | arithmetic:314eeb03 | 13.9963 | 300  |
| arithmetic | arithmetic:cab31594 | 1912.7036 | 300  |
| arithmetic | arithmetic:dc8dce82 | 2038.0402 | 300  |

### profile_5

- **Winner**: `lzw` / `lzw:9401c600`
- **Mean BPB**: 6.3029
- **Median BPB**: 6.3053
- **P95 BPB**: 6.6258
- **Std BPB**: 0.1872
- **Mean ms/KB**: 0.4519
- **Median ms/KB**: 0.4446
- **Samples**: 300
- **Valid Rate**: 1.000

| Algorithm | Params | Mean BPB | Samples |
|---|---|---|---|
| lzw | lzw:5b1cbd79 | 6.3029 | 300  |
| lzw | lzw:9401c600 | 6.3029 | 300 ← **winner** |
| lzw | lzw:dfb0cc29 | 6.3029 | 300  |
| lzw | lzw:c5719257 | 6.3029 | 300  |
| lzw | lzw:513772ed | 6.3029 | 300  |
| lzw | lzw:028a3688 | 6.3029 | 300  |
| lzw | lzw:f6cdb2b9 | 6.3029 | 300  |
| huffman | huffman:698b2692 | 6.4479 | 300  |
| rle_huffman | rle_huffman:f4a08084 | 6.5267 | 300  |
| rle_huffman | rle_huffman:b5e74fdf | 6.5469 | 300  |
| rle_huffman | rle_huffman:f2127aa9 | 6.5598 | 300  |
| rle_huffman | rle_huffman:dd60b8b3 | 6.6165 | 300  |
| lzw | lzw:3f8f9d68 | 6.7419 | 300  |
| bwt_mtf | bwt_mtf:9600795c | 7.1320 | 300  |
| bwt_mtf | bwt_mtf:f71fe5f5 | 7.1320 | 300  |
| huffman | huffman:258695c0 | 13.0747 | 300  |
| bwt_mtf | bwt_mtf:10be2f87 | 13.8999 | 300  |
| bwt_mtf | bwt_mtf:58e08891 | 13.8999 | 300  |
| arithmetic | arithmetic:314eeb03 | 13.9051 | 300  |
| arithmetic | arithmetic:cab31594 | 1986.4171 | 300  |
| arithmetic | arithmetic:dc8dce82 | 2045.9923 | 300  |

### profile_7

- **Winner**: `lzw` / `lzw:513772ed`
- **Mean BPB**: 8.1694
- **Median BPB**: 8.3077
- **P95 BPB**: 8.8874
- **Std BPB**: 0.5221
- **Mean ms/KB**: 0.8312
- **Median ms/KB**: 0.8354
- **Samples**: 33
- **Valid Rate**: 1.000

| Algorithm | Params | Mean BPB | Samples |
|---|---|---|---|
| lzw | lzw:5b1cbd79 | 8.1694 | 33  |
| lzw | lzw:dfb0cc29 | 8.1694 | 33  |
| lzw | lzw:9401c600 | 8.1694 | 33  |
| lzw | lzw:c5719257 | 8.1694 | 33  |
| lzw | lzw:3f8f9d68 | 8.1694 | 33  |
| lzw | lzw:513772ed | 8.1694 | 33 ← **winner** |
| lzw | lzw:028a3688 | 8.1694 | 33  |
| lzw | lzw:f6cdb2b9 | 8.1694 | 33  |
| huffman | huffman:698b2692 | 10.4238 | 33  |
| rle_huffman | rle_huffman:f4a08084 | 11.1069 | 33  |
| rle_huffman | rle_huffman:b5e74fdf | 11.1177 | 33  |
| rle_huffman | rle_huffman:dd60b8b3 | 11.1496 | 33  |
| rle_huffman | rle_huffman:f2127aa9 | 11.1496 | 33  |
| bwt_mtf | bwt_mtf:9600795c | 14.4165 | 33  |
| bwt_mtf | bwt_mtf:f71fe5f5 | 14.4165 | 33  |
| huffman | huffman:258695c0 | 25.3072 | 33  |
| arithmetic | arithmetic:314eeb03 | 77.4932 | 33  |
| bwt_mtf | bwt_mtf:58e08891 | 79.0247 | 33  |
| bwt_mtf | bwt_mtf:10be2f87 | 79.0247 | 33  |
| arithmetic | arithmetic:cab31594 | 3464.3123 | 33  |
| arithmetic | arithmetic:dc8dce82 | 17915.7235 | 33  |
