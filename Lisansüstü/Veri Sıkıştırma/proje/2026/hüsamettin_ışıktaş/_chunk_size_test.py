"""Quick test: different chunk sizes -> algorithm dominance pattern."""
import pandas as pd
import numpy as np
from pathlib import Path
import sys

sys.path.insert(0, '.')
from src.codecs import huffman_codec, lzw_codec, arithmetic_codec, bwt_codec, rle_codec

CODECS = {
    'bwt_mtf': bwt_codec,
    'lzw': lzw_codec,
    'huffman': huffman_codec,
    'arithmetic': arithmetic_codec,
    'rle_huffman': rle_codec,
}

CHUNK_SIZES = [256, 512, 1024, 2048, 4096, 8192, 10240]

df = pd.read_parquet('artifacts/phase1/filtered_dataset.parquet')
train_df = df[df['split'] == 'train']
profiles = sorted(train_df['profile_id'].unique())

project_root = Path('.')
books_dir = project_root / 'data' / 'processed' / 'books'
book_cache = {}

results = []

for pid in profiles:
    profile_train = train_df[train_df['profile_id'] == pid]
    sample = profile_train.sample(n=min(5, len(profile_train)), random_state=42)
    for _, row in sample.iterrows():
        book_id = str(row['book_id'])
        if book_id not in book_cache:
            book_cache[book_id] = (books_dir / f'{book_id}.txt').read_text(encoding='utf-8')
        full_text = book_cache[book_id]
        orig_cs = int(row.get('chunk_size_chars', 10240) or 10240)
        start = int(row['chunk_index']) * orig_cs
        
        for cs in CHUNK_SIZES:
            text = full_text[start:start + cs] if start + cs <= len(full_text) else full_text[start:]
            if len(text) < 50:
                continue
            chunk_bytes = text.encode('utf-8')
            
            for algo_name, codec in CODECS.items():
                r = codec.compress(chunk_bytes)
                if r.valid:
                    results.append({
                        'profile_id': pid,
                        'chunk_size': cs,
                        'algorithm': algo_name,
                        'bpb': r.bpb,
                    })

results_df = pd.DataFrame(results)

# Best algorithm per (profile, chunk_size)
best = results_df.loc[results_df.groupby(['profile_id', 'chunk_size'])['bpb'].idxmin()]

print("=== BEST ALGORITHM PER PROFILE BY CHUNK SIZE ===")
for cs in CHUNK_SIZES:
    subset = best[best['chunk_size'] == cs]
    counts = subset['algorithm'].value_counts()
    avg_bpb = subset.groupby('algorithm')['bpb'].mean()
    print(f"\nchunk_size={cs:>5}:")
    for algo in counts.index:
        print(f"  {algo}: {counts[algo]} profiles, avg_bpb={avg_bpb[algo]:.2f}")

print("\n=== OVERALL AVERAGE BPB ===")
avg = results_df.groupby(['chunk_size', 'algorithm'])['bpb'].mean().unstack()
print(avg.round(2).to_string())
