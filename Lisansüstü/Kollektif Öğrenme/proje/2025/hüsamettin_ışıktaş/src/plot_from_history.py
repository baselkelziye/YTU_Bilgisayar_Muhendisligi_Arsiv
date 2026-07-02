"""
Utility script to regenerate plots from saved training history.
This allows you to recreate plots even if plotting failed during training.
"""

import os
import json
import argparse
import matplotlib.pyplot as plt
from train_mlp import plot_training_history

def load_training_history(history_path):
    """Load training history from JSON file."""
    with open(history_path, 'r') as f:
        history = json.load(f)
    return history

def recreate_plots(model_dir, history_path=None):
    """
    Recreate plots from saved training history.
    
    Args:
        model_dir: Directory containing the model files
        history_path: Path to training_history.json (default: model_dir/training_history.json)
    """
    if history_path is None:
        history_path = os.path.join(model_dir, 'training_history.json')
    
    if not os.path.exists(history_path):
        raise FileNotFoundError(f"Training history file not found: {history_path}")
    
    print(f"Loading training history from {history_path}...")
    history = load_training_history(history_path)
    
    # Convert back to lists for plotting
    plot_history = {
        'train_loss': history['train_loss'],
        'train_acc': history['train_acc'],
        'val_loss': history['val_loss'],
        'val_acc': history['val_acc']
    }
    
    print("Recreating plots...")
    try:
        plot_training_history(plot_history, model_dir)
        print("✓ Training history plots recreated successfully.")
    except Exception as e:
        print(f"✗ Failed to recreate training history plots: {e}")
        import traceback
        traceback.print_exc()
        return False
    
    return True

def main():
    parser = argparse.ArgumentParser(description="Recreate plots from saved training history")
    parser.add_argument("model_dir", help="Directory containing the model files")
    parser.add_argument("--history", help="Path to training_history.json (default: model_dir/training_history.json)")
    args = parser.parse_args()
    
    try:
        recreate_plots(args.model_dir, args.history)
        print(f"\nAll plots recreated in {args.model_dir}")
    except Exception as e:
        print(f"ERROR: {e}")
        return 1
    
    return 0

if __name__ == "__main__":
    exit(main())

