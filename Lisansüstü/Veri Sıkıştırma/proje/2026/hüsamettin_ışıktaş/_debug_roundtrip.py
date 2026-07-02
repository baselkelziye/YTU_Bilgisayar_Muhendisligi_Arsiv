"""Debug compression roundtrip step by step."""
import sys, json
sys.path.insert(0, '.')
from pathlib import Path
from src.compression.adaptive_compressor import AdaptiveCompressor
from src.compression.adaptive_decompressor import AdaptiveDecompressor
from src.compression.profile_lookup import ProfileLookup

phase3_dir = Path("artifacts/phase3")
mapping_path = Path("artifacts/phase2/profile_algorithm_mapping.json")

lookup = ProfileLookup(mapping_path)
print("All mappings:")
for pid in sorted(lookup._mapping.keys()):
    algo, pset, ai, pi, pk = lookup._mapping[pid]
    print(f"  {pid}: algo={algo}(idx={ai}), param_set={pset}, param_idx={pi}, kwargs={pk}")
    # Test reverse lookup
    rev = lookup.lookup_params_by_index(ai, pi)
    match = "OK" if rev == pk else f"MISMATCH: {rev}"
    print(f"    reverse lookup: {match}")

print()

# Now test actual compress/decompress
text = "The quick brown fox jumps over the lazy dog. " * 50
compressor = AdaptiveCompressor(phase3_dir, mapping_path, chunk_size=512)
decompressor = AdaptiveDecompressor(mapping_path=mapping_path)

# Manually compress first block to see what happens
blocks = [text[i:i+512] for i in range(0, len(text), 512)]
print(f"First block ({len(blocks[0])} chars):")
print(repr(blocks[0][:80]))
print()

preds = compressor.classifier.classify_batch(blocks[:1])
print(f"Prediction: {preds}")

pid, conf = preds[0]
algo, pset = compressor.lookup.lookup(pid)
params = compressor.lookup.lookup_params(pid)
print(f"Lookup: algo={algo}, param_set={pset}, params={params}")

# Direct compress/decompress with those params
from src.codecs import lzw_codec
block_bytes = blocks[0].encode('utf-8')
print(f"Block bytes: {len(block_bytes)}")
r = lzw_codec.compress(block_bytes, **params)
print(f"Compress: valid={r.valid}, size={len(r.compressed)}")

# Decompress with same params
d = lzw_codec.decompress(r.compressed, **params)
print(f"Decompress: valid={d.valid}, size={len(d.compressed)}")
print(f"Match: {d.compressed == block_bytes}")
if d.compressed != block_bytes:
    print(f"Original: {block_bytes[:50]}")
    print(f"Decoded:  {d.compressed[:50]}")
