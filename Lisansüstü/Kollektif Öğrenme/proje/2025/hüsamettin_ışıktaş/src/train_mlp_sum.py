import torch
import torch.nn as nn
from torch.utils.data import TensorDataset, DataLoader, random_split
import argparse
import os
from tqdm import tqdm
from models.mlp import MLPClassifier
from sklearn.metrics import classification_report, accuracy_score, f1_score, precision_score, recall_score, confusion_matrix
import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd
import json
from datetime import datetime
import numpy as np
import sys
import traceback
import gc

def load_embeddings(path, map_location=None):
    """
    Load embeddings from file.
    
    Args:
        path: Path to the .pt file
        map_location: Device to load tensors to (None for default, 'cpu' to force CPU)
    """
    if map_location is None:
        data = torch.load(path)
    else:
        data = torch.load(path, map_location=map_location)
    return data['embeddings'], data['labels']

def evaluate_metrics(model, loader, device, class_names=None):
    model.eval()
    all_preds = []
    all_targets = []
    
    with torch.no_grad():
        for inputs, targets in loader:
            inputs, targets = inputs.to(device), targets.to(device)
            outputs = model(inputs)
            _, predicted = torch.max(outputs.data, 1)
            
            all_preds.extend(predicted.cpu().numpy())
            all_targets.extend(targets.cpu().numpy())
    
    # Calculate metrics
    acc = accuracy_score(all_targets, all_preds)
    precision = precision_score(all_targets, all_preds, average='weighted', zero_division=0)
    recall = recall_score(all_targets, all_preds, average='weighted', zero_division=0)
    f1 = f1_score(all_targets, all_preds, average='weighted', zero_division=0)
    
    report = classification_report(all_targets, all_preds, target_names=class_names, output_dict=True, zero_division=0)
    
    return {
        'accuracy': acc,
        'precision': precision,
        'recall': recall,
        'f1': f1,
        'report': report,
        'predictions': all_preds,
        'targets': all_targets
    }

def plot_confusion_matrix(targets, predictions, save_path, class_names=None):
    cm = confusion_matrix(targets, predictions)
    plt.figure(figsize=(20, 20))
    sns.heatmap(cm, annot=False, fmt='d', cmap='Blues')
    plt.xlabel('Predicted')
    plt.ylabel('True')
    plt.title('Confusion Matrix')
    plt.savefig(save_path)
    plt.close()

def plot_training_history(history, save_dir):
    epochs = range(1, len(history['train_loss']) + 1)
    
    # Loss Plot
    plt.figure(figsize=(10, 5))
    plt.plot(epochs, history['train_loss'], label='Train Loss')
    plt.plot(epochs, history['val_loss'], label='Val Loss')
    plt.title('Training and Validation Loss')
    plt.xlabel('Epochs')
    plt.ylabel('Loss')
    plt.legend()
    plt.savefig(os.path.join(save_dir, 'loss_plot.png'))
    plt.close()
    
    # Accuracy Plot
    plt.figure(figsize=(10, 5))
    plt.plot(epochs, history['train_acc'], label='Train Acc')
    plt.plot(epochs, history['val_acc'], label='Val Acc')
    plt.title('Training and Validation Accuracy')
    plt.xlabel('Epochs')
    plt.ylabel('Accuracy')
    plt.legend()
    plt.savefig(os.path.join(save_dir, 'accuracy_plot.png'))
    plt.close()

def train(args):
    device = args.device
    
    # Helper function to convert numpy types to Python native types for JSON serialization
    def convert_to_serializable(obj):
        if isinstance(obj, (np.integer, np.floating)):
            return float(obj)
        elif isinstance(obj, np.ndarray):
            return obj.tolist()
        elif isinstance(obj, dict):
            return {k: convert_to_serializable(v) for k, v in obj.items()}
        elif isinstance(obj, (list, tuple)):
            return [convert_to_serializable(item) for item in obj]
        return obj
    
    # Determine timestamp
    if args.batch_timestamp:
        timestamp = args.batch_timestamp
    else:
        timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")

    # Determine model name - for summed embeddings
    if len(args.embedding_dirs) == 1:
        embedding_name = os.path.basename(args.embedding_dirs[0])
        if not embedding_name: # Handle trailing slash
            embedding_name = os.path.basename(os.path.dirname(args.embedding_dirs[0]))
        embedding_name = f"{embedding_name}_sum"
    else:
        # Create name from embedding directory names
        dir_names = [os.path.basename(d.rstrip('/')) for d in args.embedding_dirs]
        embedding_name = "_plus_".join(dir_names)
        
    output_dir = os.path.join("models", timestamp, embedding_name)
    os.makedirs(output_dir, exist_ok=True)
    
    print(f"Output directory: {output_dir}")
    
    # Save training config
    with open(os.path.join(output_dir, 'config.json'), 'w') as f:
        json.dump(vars(args), f, indent=4)
    
    # Load Embeddings with element-wise summation (instead of concatenation)
    print("Loading embeddings for summation...")
    train_emb = None
    test_emb = None
    train_labels_ref = None
    test_labels_ref = None
    embedding_dim = None
    
    # Force CPU loading to avoid GPU memory issues, then move to device later if needed
    load_device = 'cpu'
    
    for idx, emb_dir in enumerate(args.embedding_dirs):
        print(f"  Loading from {emb_dir}... ({idx+1}/{len(args.embedding_dirs)})")
        try:
            train_path = os.path.join(emb_dir, "train.pt")
            test_path = os.path.join(emb_dir, "test.pt")
            
            if not os.path.exists(train_path):
                raise FileNotFoundError(f"Train embeddings file not found: {train_path}")
            if not os.path.exists(test_path):
                raise FileNotFoundError(f"Test embeddings file not found: {test_path}")
            
            # Load embeddings to CPU to save memory
            train_e, train_l = load_embeddings(train_path, map_location=load_device)
            test_e, test_l = load_embeddings(test_path, map_location=load_device)
            
            # Verify alignment and dimensions
            if train_labels_ref is None:
                train_labels_ref = train_l
                test_labels_ref = test_l
                # First embedding - initialize
                train_emb = train_e.clone()
                test_emb = test_e.clone()
                embedding_dim = train_e.shape[1]
                print(f"    Initialized with shape: {train_emb.shape}, embedding dim: {embedding_dim}")
            else:
                # Verify label alignment
                if not torch.equal(train_labels_ref, train_l):
                    raise ValueError(f"Train labels mismatch in {emb_dir}")
                if not torch.equal(test_labels_ref, test_l):
                    raise ValueError(f"Test labels mismatch in {emb_dir}")
                
                # Verify dimension compatibility
                if train_e.shape[1] != embedding_dim:
                    raise ValueError(
                        f"Dimension mismatch! Expected embedding dim {embedding_dim}, "
                        f"but got {train_e.shape[1]} from {emb_dir}. "
                        f"Embeddings must have the same dimension for summation."
                    )
                if test_e.shape[1] != embedding_dim:
                    raise ValueError(
                        f"Dimension mismatch! Expected embedding dim {embedding_dim}, "
                        f"but got {test_e.shape[1]} from {emb_dir} (test set). "
                        f"Embeddings must have the same dimension for summation."
                    )
                
                # Sum element-wise instead of concatenate
                print(f"    Summing... (current shape: {train_emb.shape}, adding shape: {train_e.shape})")
                train_emb = train_emb + train_e
                test_emb = test_emb + test_e
                
                # Free memory immediately after summation
                del train_e, test_e
                gc.collect()  # Force garbage collection
                if torch.cuda.is_available():
                    torch.cuda.empty_cache()
                
        except Exception as e:
            print(f"ERROR: Failed to load embeddings from {emb_dir}: {e}", file=sys.stderr)
            traceback.print_exc(file=sys.stderr)
            raise
    
    train_labels = train_labels_ref
    test_labels = test_labels_ref
    
    print(f"Final Train Shape: {train_emb.shape} (after summation)")
    print(f"Final Test Shape: {test_emb.shape} (after summation)")
    
    # Calculate approximate memory usage
    train_memory_gb = train_emb.numel() * train_emb.element_size() / (1024**3)
    test_memory_gb = test_emb.numel() * test_emb.element_size() / (1024**3)
    print(f"Approximate memory usage - Train: {train_memory_gb:.2f} GB, Test: {test_memory_gb:.2f} GB")

    
    # Split train set into train and validation
    print(f"\nSplitting train set into train ({1-args.val_split:.1%}) and validation ({args.val_split:.1%})...")
    train_ds = TensorDataset(train_emb, train_labels)
    test_ds = TensorDataset(test_emb, test_labels)
    
    # Calculate split sizes
    total_train_size = len(train_ds)
    val_size = int(total_train_size * args.val_split)
    train_size = total_train_size - val_size
    
    # Split the dataset
    train_subset, val_subset = random_split(train_ds, [train_size, val_size])
    
    print(f"Train samples: {train_size}, Validation samples: {val_size}, Test samples: {len(test_ds)}")
    
    # Create DataLoaders
    train_loader = DataLoader(train_subset, batch_size=args.batch_size, shuffle=True)
    val_loader = DataLoader(val_subset, batch_size=args.batch_size, shuffle=False)
    test_loader = DataLoader(test_ds, batch_size=args.batch_size, shuffle=False)
    
    # Initialize Model
    input_dim = train_emb.shape[1]
    num_classes = len(torch.unique(train_labels)) 
    print(f"Input Dim: {input_dim}, Classes: {num_classes}")
    
    model = MLPClassifier(input_dim=input_dim, num_classes=num_classes).to(device)
    optimizer = torch.optim.Adam(model.parameters(), lr=args.lr)
    criterion = nn.CrossEntropyLoss()
    
    best_val_f1 = 0.0
    history = {'train_loss': [], 'train_acc': [], 'val_loss': [], 'val_acc': [], 'val_f1': []}
    
    print("Starting training...")
    for epoch in range(args.epochs):
        model.train()
        running_loss = 0.0
        correct = 0
        total = 0
        
        for inputs, targets in train_loader:
            inputs, targets = inputs.to(device), targets.to(device)
            
            optimizer.zero_grad()
            outputs = model(inputs)
            loss = criterion(outputs, targets)
            loss.backward()
            optimizer.step()
            
            running_loss += loss.item()
            _, predicted = torch.max(outputs.data, 1)
            total += targets.size(0)
            correct += (predicted == targets).sum().item()
            
        train_loss = running_loss / len(train_loader)
        train_acc = correct / total
        
        # Validation (using validation set, not test set)
        model.eval()
        val_running_loss = 0.0
        val_correct = 0
        val_total = 0
        all_val_preds = []
        all_val_targets = []
        
        with torch.no_grad():
            for inputs, targets in val_loader:
                inputs, targets = inputs.to(device), targets.to(device)
                outputs = model(inputs)
                loss = criterion(outputs, targets)
                
                val_running_loss += loss.item()
                _, predicted = torch.max(outputs.data, 1)
                val_total += targets.size(0)
                val_correct += (predicted == targets).sum().item()
                
                all_val_preds.extend(predicted.cpu().numpy())
                all_val_targets.extend(targets.cpu().numpy())
        
        val_loss = val_running_loss / len(val_loader)
        val_acc = val_correct / val_total
        val_f1 = f1_score(all_val_targets, all_val_preds, average='weighted', zero_division=0)
        
        history['train_loss'].append(train_loss)
        history['train_acc'].append(train_acc)
        history['val_loss'].append(val_loss)
        history['val_acc'].append(val_acc)
        history['val_f1'].append(val_f1)
        
        print(f"Epoch {epoch+1}/{args.epochs} - "
              f"Train Loss: {train_loss:.4f} Acc: {train_acc:.4f} - "
              f"Val Loss: {val_loss:.4f} Acc: {val_acc:.4f} F1: {val_f1:.4f}")
        
        if val_f1 > best_val_f1:
            best_val_f1 = val_f1
            torch.save(model.state_dict(), os.path.join(output_dir, "best_model.pt"))
            
    # Final Evaluation with Best Model
    print("\nEvaluating best model...")
    try:
        best_model_path = os.path.join(output_dir, "best_model.pt")
        if not os.path.exists(best_model_path):
            raise FileNotFoundError(f"Best model file not found: {best_model_path}")
        model.load_state_dict(torch.load(best_model_path))
    except Exception as e:
        print(f"ERROR: Failed to load best model: {e}", file=sys.stderr)
        traceback.print_exc(file=sys.stderr)
        raise
    
    try:
        metrics = evaluate_metrics(model, test_loader, device)
    except Exception as e:
        print(f"ERROR: Failed to evaluate model: {e}", file=sys.stderr)
        traceback.print_exc(file=sys.stderr)
        raise
    
    print(f"\nTest Results:")
    print(f"Accuracy:  {metrics['accuracy']:.4f}")
    print(f"Precision: {metrics['precision']:.4f}")
    print(f"Recall:    {metrics['recall']:.4f}")
    print(f"F1 Score:  {metrics['f1']:.4f}")
    
    # Save training history
    try:
        history_file = os.path.join(output_dir, 'training_history.json')
        with open(history_file, 'w') as f:
            serializable_history = {
                'train_loss': convert_to_serializable(history['train_loss']),
                'train_acc': convert_to_serializable(history['train_acc']),
                'val_loss': convert_to_serializable(history['val_loss']),
                'val_acc': convert_to_serializable(history['val_acc']),
                'val_f1': convert_to_serializable(history['val_f1']),
                'best_val_f1': convert_to_serializable(best_val_f1),
                'num_epochs': len(history['train_loss']),
                'val_split': args.val_split
            }
            json.dump(serializable_history, f, indent=4)
        print("Training history saved successfully.")
    except Exception as e:
        print(f"ERROR: Failed to save training history: {e}", file=sys.stderr)
        traceback.print_exc()
    
    # Save metrics
    try:
        with open(os.path.join(output_dir, 'metrics.json'), 'w') as f:
            # Convert NumPy types to Python types for JSON serialization
            serializable_metrics = {
                'accuracy': convert_to_serializable(metrics['accuracy']),
                'precision': convert_to_serializable(metrics['precision']),
                'recall': convert_to_serializable(metrics['recall']),
                'f1': convert_to_serializable(metrics['f1']),
                'report': convert_to_serializable(metrics['report'])
            }
            json.dump(serializable_metrics, f, indent=4)
        print("Metrics saved successfully.")
    except Exception as e:
        print(f"ERROR: Failed to save metrics: {e}", file=sys.stderr)
        traceback.print_exc()
        
    # Plots
    try:
        plot_training_history(history, output_dir)
        print("Training history plots saved successfully.")
    except Exception as e:
        print(f"ERROR: Failed to save training history plots: {e}", file=sys.stderr)
        traceback.print_exc()
    
    try:
        plot_confusion_matrix(metrics['targets'], metrics['predictions'], 
                             os.path.join(output_dir, 'confusion_matrix.png'))
        print("Confusion matrix plot saved successfully.")
    except Exception as e:
        print(f"ERROR: Failed to save confusion matrix: {e}", file=sys.stderr)
        traceback.print_exc()
    
    print(f"\nAll results saved to {output_dir}")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Train MLP with summed embeddings (element-wise addition instead of concatenation)"
    )
    parser.add_argument("--embedding_dirs", nargs='+', required=True, 
                       help="Directories containing train.pt and test.pt. Embeddings must have the same dimension.")
    parser.add_argument("--batch_timestamp", help="Timestamp to use for output directory")
    parser.add_argument("--epochs", type=int, default=150)
    parser.add_argument("--batch_size", type=int, default=128)
    parser.add_argument("--lr", type=float, default=1e-3)
    parser.add_argument("--val_split", type=float, default=0.2, 
                       help="Fraction of train set to use for validation (default: 0.2)")
    parser.add_argument("--device", default="cuda" if torch.cuda.is_available() else "cpu")
    args = parser.parse_args()
    
    # Validate val_split
    if args.val_split <= 0 or args.val_split >= 1:
        print("ERROR: --val_split must be between 0 and 1", file=sys.stderr)
        sys.exit(1)
    
    # Validate that we have at least 2 embeddings for summation (though 1 would work too)
    if len(args.embedding_dirs) < 1:
        print("ERROR: At least 1 embedding directory must be provided", file=sys.stderr)
        sys.exit(1)
    
    try:
        train(args)
        sys.exit(0)
    except KeyboardInterrupt:
        print("\nTraining interrupted by user.", file=sys.stderr)
        sys.exit(130)
    except Exception as e:
        print(f"\nERROR: Training failed with error: {e}", file=sys.stderr)
        print("\nFull traceback:", file=sys.stderr)
        traceback.print_exc(file=sys.stderr)
        sys.exit(1)

