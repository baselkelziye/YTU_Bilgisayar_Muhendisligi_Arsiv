"""Debug lzw roundtrip issue."""
from src.codecs import lzw_codec

text = "The quick brown fox jumps over the lazy dog. " * 50
block = text[:512].encode('utf-8')

# Compress with default params
r1 = lzw_codec.compress(block)
print(f"Default compress: valid={r1.valid}, compressed_size={len(r1.compressed)}, bpb={r1.bpb:.2f}")
d1 = lzw_codec.decompress(r1.compressed)
print(f"Default decompress: valid={d1.valid}, size={len(d1.compressed)}, match={d1.compressed == block}")
if d1.compressed != block:
    print(f"First 50 bytes original: {block[:50]}")
    print(f"First 50 bytes decoded: {d1.compressed[:50]}")
    print(f"Lengths: orig={len(block)}, decoded={len(d1.compressed)}")

# Compress with lzw_bits12 params
r2 = lzw_codec.compress(block, max_bits=12)
print(f"\nmax_bits=12 compress: valid={r2.valid}, compressed_size={len(r2.compressed)}, bpb={r2.bpb:.2f}")
d2 = lzw_codec.decompress(r2.compressed, max_bits=12)
print(f"max_bits=12 decompress: valid={d2.valid}, size={len(d2.compressed)}, match={d2.compressed == block}")
if d2.compressed != block:
    print(f"First 50 bytes original: {block[:50]}")
    print(f"First 50 bytes decoded: {d2.compressed[:50]}")
