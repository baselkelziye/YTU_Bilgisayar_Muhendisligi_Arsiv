"""Inspect decompress result attributes."""
from src.codecs import lzw_codec
r = lzw_codec.compress(b'hello world hello world')
print('compress dir:', [a for a in dir(r) if not a.startswith('_')])
d = lzw_codec.decompress(r.compressed)
print('decompress dir:', [a for a in dir(d) if not a.startswith('_')])
print('valid:', d.valid)
if d.valid:
    print('text attr attempts:')
    for attr in ['decompressed_text', 'text', 'data', 'original_text', 'output', 'decompressed']:
        print(f'  {attr}:', getattr(d, attr, 'NOT_FOUND'))
