import torch
import torch.nn as nn
from torch.utils.data import TensorDataset, DataLoader
import argparse
import os
import json
from tqdm import tqdm
import numpy as np
from sklearn.metrics import classification_report, accuracy_score, f1_score, precision_score, recall_score, confusion_matrix
import matplotlib.pyplot as plt
import seaborn as sns
from datetime import datetime
import sys
import traceback
from models.mlp import MLPClassifier

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

def load_model(model_dir, device):
    """
    Load a trained MLP model from a model directory.
    
    Args:
        model_dir: Directory containing best_model.pt and config.json
        device: Device to load model to
    
    Returns:
        model: Loaded model
        config: Model configuration
        metrics: Model metrics (if available)
    """
    config_path = os.path.join(model_dir, 'config.json')
    model_path = os.path.join(model_dir, 'best_model.pt')
    metrics_path = os.path.join(model_dir, 'metrics.json')
    
    if not os.path.exists(config_path):
        raise FileNotFoundError(f"Config file not found: {config_path}")
    if not os.path.exists(model_path):
        raise FileNotFoundError(f"Model file not found: {model_path}")
    
    # Load config
    with open(config_path, 'r') as f:
        config = json.load(f)
    
    # Load metrics if available
    metrics = None
    if os.path.exists(metrics_path):
        with open(metrics_path, 'r') as f:
            metrics = json.load(f)
    
    # Load embeddings to get dimensions
    embedding_dir = config['embedding_dirs'][0]  # Use first embedding dir
    test_path = os.path.join(embedding_dir, "test.pt")
    
    if not os.path.exists(test_path):
        raise FileNotFoundError(f"Test embeddings not found: {test_path}")
    
    test_emb, test_labels = load_embeddings(test_path, map_location='cpu')
    input_dim = test_emb.shape[1]
    num_classes = len(torch.unique(test_labels))
    
    # Initialize and load model
    model = MLPClassifier(input_dim=input_dim, num_classes=num_classes).to(device)
    model.load_state_dict(torch.load(model_path, map_location=device))
    model.eval()
    
    return model, config, metrics, embedding_dir

def get_predictions(models, embeddings_loader, device):
    """
    Get logits from all models for given embeddings.
    
    Args:
        models: List of (model, embedding_dir) tuples
        embeddings_loader: DataLoader for embeddings
        device: Device to run models on
    
    Returns:
        all_logits: List of logits from each model (list of tensors)
        labels: Ground truth labels
    """
    all_logits = [[] for _ in models]
    labels = []
    
    with torch.no_grad():
        for batch_embeddings, batch_labels in tqdm(embeddings_loader, desc="Getting predictions"):
            batch_labels = batch_labels.to(device)
            labels.append(batch_labels.cpu())
            
            for idx, (model, embedding_dir) in enumerate(models):
                # Get the corresponding embeddings for this model
                batch_emb = batch_embeddings[idx].to(device)
                logits = model(batch_emb)
                all_logits[idx].append(logits.cpu())
    
    # Concatenate all batches
    all_logits = [torch.cat(logits, dim=0) for logits in all_logits]
    labels = torch.cat(labels, dim=0)
    
    return all_logits, labels

# This function is no longer used (we do batch-by-batch now), but kept for reference
def weighted_ensemble_predict(all_logits, weights=None):
    """
    Compute weighted average of logits from multiple models.
    NOTE: This function is deprecated. We now use batch-by-batch processing in main().
    
    Args:
        all_logits: List of logits tensors from each model
        weights: Weights for each model (if None, equal weights are used)
    
    Returns:
        ensemble_logits: Weighted average logits
        predictions: Final predictions (argmax of ensemble_logits)
    """
    if weights is None:
        weights = [1.0 / len(all_logits)] * len(all_logits)
    
    # Normalize weights
    weights = np.array(weights)
    weights = weights / weights.sum()
    
    # Stack logits and compute weighted average
    stacked_logits = torch.stack(all_logits, dim=0)  # Shape: (n_models, n_samples, n_classes)
    weights_tensor = torch.tensor(weights, dtype=stacked_logits.dtype).view(-1, 1, 1)
    ensemble_logits = (stacked_logits * weights_tensor).sum(dim=0)
    
    predictions = torch.argmax(ensemble_logits, dim=1)
    
    return ensemble_logits, predictions

def evaluate_ensemble(predictions, targets):
    """
    Evaluate ensemble predictions.
    
    Args:
        predictions: Predicted labels
        targets: Ground truth labels
    
    Returns:
        Dictionary of metrics
    """
    if isinstance(predictions, torch.Tensor):
        predictions = predictions.numpy()
    if isinstance(targets, torch.Tensor):
        targets = targets.numpy()
    
    acc = accuracy_score(targets, predictions)
    precision = precision_score(targets, predictions, average='weighted', zero_division=0)
    recall = recall_score(targets, predictions, average='weighted', zero_division=0)
    f1 = f1_score(targets, predictions, average='weighted', zero_division=0)
    
    report = classification_report(targets, predictions, output_dict=True, zero_division=0)
    
    return {
        'accuracy': acc,
        'precision': precision,
        'recall': recall,
        'f1': f1,
        'report': report,
        'predictions': predictions,
        'targets': targets
    }

def plot_confusion_matrix(targets, predictions, save_path, class_names=None):
    cm = confusion_matrix(targets, predictions)
    plt.figure(figsize=(20, 20))
    sns.heatmap(cm, annot=False, fmt='d', cmap='Blues')
    plt.xlabel('Predicted')
    plt.ylabel('True')
    plt.title('Ensemble Confusion Matrix')
    plt.savefig(save_path)
    plt.close()

def main():
    parser = argparse.ArgumentParser(description='Ensemble multiple trained MLP models using weighted averaging')
    parser.add_argument('--model_dirs', nargs='+', required=True,
                       help='List of model directories to ensemble (e.g., models/20260106_001352/dinov3 models/20260106_001352/dinov2)')
    parser.add_argument('--weights', nargs='+', type=float, default=None,
                       help='Weights for each model (must match number of model_dirs). If not provided, will use equal weights or F1-based weights.')
    parser.add_argument('--use_f1_weights', action='store_true',
                       help='Use F1 scores from metrics.json as weights (normalized)')
    parser.add_argument('--batch_size', type=int, default=128,
                       help='Batch size for inference')
    parser.add_argument('--device', default='cuda' if torch.cuda.is_available() else 'cpu',
                       help='Device to use')
    parser.add_argument('--output_dir', default=None,
                       help='Output directory for results (default: models/timestamp/ensemble_<model_names>)')
    parser.add_argument('--split', default='test', choices=['test', 'train'],
                       help='Which split to evaluate on (test or train)')
    
    args = parser.parse_args()
    
    # Validate weights
    if args.weights is not None and len(args.weights) != len(args.model_dirs):
        print(f"ERROR: Number of weights ({len(args.weights)}) must match number of model_dirs ({len(args.model_dirs)})", file=sys.stderr)
        sys.exit(1)
    
    if args.use_f1_weights and args.weights is not None:
        print("WARNING: Both --weights and --use_f1_weights specified. Using --weights.", file=sys.stderr)
    
    device = args.device
    print(f"Using device: {device}")
    
    # Load all models
    print("Loading models...")
    models = []
    model_names = []
    f1_scores = []
    
    for model_dir in args.model_dirs:
        model_dir = model_dir.rstrip('/')
        model_name = os.path.basename(model_dir)
        model_names.append(model_name)
        
        print(f"  Loading {model_name}...")
        try:
            model, config, metrics, embedding_dir = load_model(model_dir, device)
            models.append((model, embedding_dir))
            
            # Store F1 score if available
            if metrics is not None and 'f1' in metrics:
                f1_scores.append(metrics['f1'])
                print(f"    F1 Score: {metrics['f1']:.4f}")
            else:
                f1_scores.append(None)
                print(f"    F1 Score: Not available")
        except Exception as e:
            print(f"ERROR: Failed to load model from {model_dir}: {e}", file=sys.stderr)
            traceback.print_exc(file=sys.stderr)
            sys.exit(1)
    
    # Determine weights
    if args.weights is not None:
        weights = args.weights
        print(f"\nUsing provided weights: {weights}")
    elif args.use_f1_weights and all(f1 is not None for f1 in f1_scores):
        weights = f1_scores
        print(f"\nUsing F1-based weights: {weights}")
    else:
        weights = None
        print(f"\nUsing equal weights")
    
    # Load embeddings for each model
    print(f"\nLoading {args.split} embeddings...")
    embedding_loaders = []
    all_labels = None
    
    for idx, (model, embedding_dir) in enumerate(models):
        print(f"  Loading embeddings for {model_names[idx]} from {embedding_dir}...")
        emb_path = os.path.join(embedding_dir, f"{args.split}.pt")
        
        if not os.path.exists(emb_path):
            raise FileNotFoundError(f"Embeddings file not found: {emb_path}")
        
        embeddings, labels = load_embeddings(emb_path, map_location='cpu')
        
        # Verify labels are consistent across models
        if all_labels is None:
            all_labels = labels
        else:
            if not torch.equal(all_labels, labels):
                raise ValueError(f"Label mismatch for model {model_names[idx]}")
        
        dataset = TensorDataset(embeddings, labels)
        loader = DataLoader(dataset, batch_size=args.batch_size, shuffle=False)
        embedding_loaders.append(loader)
    
    print(f"Loaded {len(all_labels)} samples")
    
    # Memory-efficient batch-by-batch ensemble prediction
    print("\nComputing ensemble predictions (memory-efficient batch-by-batch)...")
    
    # Normalize weights if provided
    if weights is not None:
        weights = np.array(weights)
        weights = weights / weights.sum()
        weights_tensor = torch.tensor(weights, dtype=torch.float32).to(device).view(-1, 1, 1)
    else:
        weights_tensor = None
    
    all_ensemble_predictions = []
    all_predictions_per_model = [[] for _ in models]
    all_individual_accuracies = []
    all_individual_f1s = []
    
    # Process batch by batch to save memory
    with torch.no_grad():
        # Create iterators for all loaders
        loader_iters = [iter(loader) for loader in embedding_loaders]
        
        # Process batches
        n_batches = len(embedding_loaders[0])
        pbar = tqdm(total=n_batches, desc="Ensemble inference")
        
        for batch_idx in range(n_batches):
            batch_logits = []
            batch_labels = None
            
            # Get logits from each model for this batch
            for idx, (model, _) in enumerate(models):
                batch_embeddings, batch_labels = next(loader_iters[idx])
                batch_embeddings = batch_embeddings.to(device)
                
                logits = model(batch_embeddings)  # Shape: (batch_size, n_classes)
                batch_logits.append(logits)
                
                # Store individual predictions for later evaluation
                individual_preds = torch.argmax(logits, dim=1).cpu().numpy()
                all_predictions_per_model[idx].extend(individual_preds)
            
            # Compute weighted ensemble for this batch
            if weights_tensor is not None:
                # Stack: (n_models, batch_size, n_classes)
                stacked = torch.stack(batch_logits, dim=0)
                ensemble_logits = (stacked * weights_tensor).sum(dim=0)
            else:
                # Equal weights
                stacked = torch.stack(batch_logits, dim=0)
                ensemble_logits = stacked.mean(dim=0)
            
            ensemble_preds = torch.argmax(ensemble_logits, dim=1).cpu().numpy()
            all_ensemble_predictions.extend(ensemble_preds)
            
            # Clean up batch tensors
            del batch_logits, stacked, ensemble_logits, ensemble_preds
            torch.cuda.empty_cache() if device == 'cuda' else None
            
            pbar.update(1)
        
        pbar.close()
    
    # Convert to numpy arrays
    ensemble_predictions = np.array(all_ensemble_predictions)
    all_labels_np = all_labels.numpy()
    
    # Evaluate ensemble
    print("\nEvaluating ensemble...")
    metrics = evaluate_ensemble(ensemble_predictions, all_labels_np)
    
    print(f"\nEnsemble Results ({args.split} set):")
    print(f"Accuracy:  {metrics['accuracy']:.4f}")
    print(f"Precision: {metrics['precision']:.4f}")
    print(f"Recall:    {metrics['recall']:.4f}")
    print(f"F1 Score:  {metrics['f1']:.4f}")
    
    # Print individual model results for comparison
    print("\nIndividual Model Results (for comparison):")
    for idx, preds in enumerate(all_predictions_per_model):
        individual_metrics = evaluate_ensemble(np.array(preds), all_labels_np)
        all_individual_accuracies.append(individual_metrics['accuracy'])
        all_individual_f1s.append(individual_metrics['f1'])
        print(f"  {model_names[idx]}: Accuracy={individual_metrics['accuracy']:.4f}, F1={individual_metrics['f1']:.4f}")
    
    # Update metrics with individual results for saving
    metrics['individual_accuracies'] = all_individual_accuracies
    metrics['individual_f1s'] = all_individual_f1s
    
    # Save results
    if args.output_dir is None:
        timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
        ensemble_name = "_".join(model_names)
        output_dir = os.path.join("models", timestamp, f"ensemble_{ensemble_name}")
    else:
        output_dir = args.output_dir
    
    os.makedirs(output_dir, exist_ok=True)
    print(f"\nSaving results to {output_dir}")
    
    # Save configuration
    config = {
        'model_dirs': args.model_dirs,
        'model_names': model_names,
        'weights': weights.tolist() if weights is not None and isinstance(weights, np.ndarray) else weights,
        'use_f1_weights': args.use_f1_weights,
        'batch_size': args.batch_size,
        'device': args.device,
        'split': args.split,
        'individual_f1_scores': f1_scores if all(f1 is not None for f1 in f1_scores) else None
    }
    
    with open(os.path.join(output_dir, 'config.json'), 'w') as f:
        json.dump(config, f, indent=4)
    
    # Save metrics
    def convert_to_serializable(obj):
        if isinstance(obj, (np.integer, np.floating)):
            return float(obj)
        elif isinstance(obj, np.ndarray):
            return obj.tolist()
        elif isinstance(obj, dict):
            return {k: convert_to_serializable(v) for k, v in obj.items()}
        elif isinstance(obj, (list, tuple)):
            return [convert_to_serializable(item) for item in obj]
        elif isinstance(obj, torch.Tensor):
            return obj.tolist()
        return obj
    
    metrics_serializable = {
        'accuracy': convert_to_serializable(metrics['accuracy']),
        'precision': convert_to_serializable(metrics['precision']),
        'recall': convert_to_serializable(metrics['recall']),
        'f1': convert_to_serializable(metrics['f1']),
        'report': convert_to_serializable(metrics['report']),
        'individual_accuracies': convert_to_serializable(metrics.get('individual_accuracies', [])),
        'individual_f1s': convert_to_serializable(metrics.get('individual_f1s', []))
    }
    
    with open(os.path.join(output_dir, 'metrics.json'), 'w') as f:
        json.dump(metrics_serializable, f, indent=4)
    
    
    print(f"\nAll results saved to {output_dir}")

if __name__ == "__main__":
    try:
        main()
        sys.exit(0)
    except KeyboardInterrupt:
        print("\nEnsemble interrupted by user.", file=sys.stderr)
        sys.exit(130)
    except Exception as e:
        print(f"\nERROR: Ensemble failed with error: {e}", file=sys.stderr)
        print("\nFull traceback:", file=sys.stderr)
        traceback.print_exc(file=sys.stderr)
        sys.exit(1)

