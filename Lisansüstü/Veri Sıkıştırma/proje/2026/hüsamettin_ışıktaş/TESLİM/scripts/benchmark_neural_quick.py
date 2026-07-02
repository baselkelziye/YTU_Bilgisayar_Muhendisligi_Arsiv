"""Quick neural compressor benchmark — load trained model, test on sample chunks."""

import sys
import time
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(PROJECT_ROOT))

from src.models.neural_compressor import NeuralCompressor
from src.codecs import bwt_codec

ARTIFACTS_DIR = PROJECT_ROOT / "artifacts" / "v2_neural"

def main():
    print("Loading neural compressor...")
    model_path = ARTIFACTS_DIR / "model" / "best_model.pt"
    
    compressor = NeuralCompressor()
    compressor.load(model_path)
    print(f"  Model loaded: {sum(p.numel() for p in compressor.model.parameters()):,} params")
    
    # Test texts
    test_texts = [
        "Hello, world! This is a test of the neural compressor.",
        "The quick brown fox jumps over the lazy dog. " * 10,
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit. " * 5,
        "def fibonacci(n):\n    if n <= 1:\n        return n\n    return fibonacci(n-1) + fibonacci(n-2)",
        '{"name": "test", "values": [1, 2, 3, 4, 5], "nested": {"key": "value"}}',
    ]
    
    print("\nTesting neural compressor...")
    for text in test_texts:
        data = text.encode("utf-8")
        try:
            result = compressor.compress(data)
            decomp = compressor.decompress(result.compressed)
            
            # Also test bwt_mtf for comparison
            bwt_result = bwt_codec.compress(data, secondary="huffman", block_size=0)
            
            roundtrip_ok = decomp.valid and decomp.compressed == data
            print(f"  Text ({len(data)}B): neural={result.bpb:.2f} BPB, "
                  f"bwt={bwt_result.bpb:.2f} BPB, "
                  f"rt={'✓' if roundtrip_ok else '✗'}")
        except Exception as e:
            print(f"  Error: {e}")
    
    print("\n✅ Done")

if __name__ == "__main__":
    main()
