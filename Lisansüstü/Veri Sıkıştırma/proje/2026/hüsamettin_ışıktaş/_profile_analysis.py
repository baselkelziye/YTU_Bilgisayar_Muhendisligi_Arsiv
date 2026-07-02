import pandas as pd
import numpy as np

df = pd.read_parquet('artifacts/phase1/filtered_dataset.parquet')

cr_cols = ['zlib_compression_ratio','bz2_compression_ratio','lzma_compression_ratio']
profiles = df.groupby('profile_id')
cr = profiles[cr_cols].mean()

print("=== COMPRESSION RATIO LENS ===")
for pid in sorted(cr.index):
    n = len(profiles.get_group(pid))
    print(f'{pid} (n={n}): zlib={cr.loc[pid,"zlib_compression_ratio"]:.3f} bz2={cr.loc[pid,"bz2_compression_ratio"]:.3f} lzma={cr.loc[pid,"lzma_compression_ratio"]:.3f}')

print()
key = ['entropy_char','unique_char_ratio','unique_word_ratio','digit_ratio','whitespace_ratio','vowel_ratio','newline_density','avg_word_len','ascii_ratio','longest_repeat_run','mean_line_length']
summ = profiles[key].mean()
print("=== TEXTURE FEATURES ===")
print(summ.round(4).to_string())
