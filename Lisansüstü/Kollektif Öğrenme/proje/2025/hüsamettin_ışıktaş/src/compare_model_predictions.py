import torch
import torch.nn as nn
from torch.utils.data import TensorDataset, DataLoader
import argparse
import os
import json
from tqdm import tqdm
import numpy as np
from sklearn.metrics import classification_report, accuracy_score, f1_score, confusion_matrix, cohen_kappa_score
import matplotlib.pyplot as plt
import seaborn as sns
from datetime import datetime
import sys
import traceback
from models.mlp import MLPClassifier
import pandas as pd

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
        embedding_dir: Embedding directory path
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
    
    # Get input_dim and num_classes from checkpoint state_dict
    # This is more reliable for concatenated models
    checkpoint = torch.load(model_path, map_location='cpu')
    
    # Extract input_dim from first layer weights
    # MLPClassifier has Sequential model with first layer at 'model.0.weight'
    if 'model.0.weight' in checkpoint:
        input_dim = checkpoint['model.0.weight'].shape[1]
    else:
        # Fallback: try to load from embeddings if checkpoint structure is different
        embedding_dir = config['embedding_dirs'][0]  # Use first embedding dir
        test_path = os.path.join(embedding_dir, "test.pt")
        
        if not os.path.exists(test_path):
            raise FileNotFoundError(f"Test embeddings not found: {test_path}")
        
        test_emb, test_labels = load_embeddings(test_path, map_location='cpu')
        input_dim = test_emb.shape[1]
        if len(config['embedding_dirs']) > 1:
            # Concatenated model - sum up dimensions
            for emb_dir in config['embedding_dirs'][1:]:
                emb_path = os.path.join(emb_dir, "test.pt")
                if os.path.exists(emb_path):
                    emb, _ = load_embeddings(emb_path, map_location='cpu')
                    input_dim += emb.shape[1]
                    del emb
        del test_emb, test_labels
        torch.cuda.empty_cache() if device == 'cuda' else None
    
    # Get num_classes from last layer weights
    # Last layer is 'model.X.weight' where X is the last linear layer index
    # MLPClassifier: Linear layers are at even indices (0, 2, 4, ...)
    # We need to find the last Linear layer
    num_classes = None
    for key in sorted(checkpoint.keys(), reverse=True):
        if 'weight' in key and 'model.' in key:
            # Check if this is a linear layer (has both weight and bias)
            layer_idx = key.split('.')[1]
            bias_key = f'model.{layer_idx}.bias'
            if bias_key in checkpoint:
                num_classes = checkpoint[bias_key].shape[0]
                break
    
    if num_classes is None:
        # Fallback: load from embeddings
        embedding_dir = config['embedding_dirs'][0]
        test_path = os.path.join(embedding_dir, "test.pt")
        if os.path.exists(test_path):
            _, test_labels = load_embeddings(test_path, map_location='cpu')
            num_classes = len(torch.unique(test_labels))
        else:
            raise ValueError("Could not determine num_classes from checkpoint or embeddings")
    
    # Determine embedding_dir for loading embeddings later
    # For concatenated models, we'll need to handle multiple dirs in main()
    embedding_dir = config['embedding_dirs'][0] if len(config['embedding_dirs']) == 1 else None
    
    # Initialize and load model
    model = MLPClassifier(input_dim=input_dim, num_classes=num_classes).to(device)
    model.load_state_dict(torch.load(model_path, map_location=device))
    model.eval()
    
    return model, config, metrics, embedding_dir

def get_predictions(model, embedding_loader, device):
    """
    Get predictions from a model.
    
    Args:
        model: Trained model
        embedding_loader: DataLoader for embeddings
        device: Device to run model on
    
    Returns:
        predictions: Array of predicted labels
        correct_mask: Boolean array indicating correct predictions
    """
    predictions = []
    
    with torch.no_grad():
        for batch_embeddings, batch_labels in tqdm(embedding_loader, desc="Getting predictions", leave=False):
            batch_embeddings = batch_embeddings.to(device)
            batch_labels = batch_labels.cpu().numpy()
            
            logits = model(batch_embeddings)
            batch_preds = torch.argmax(logits, dim=1).cpu().numpy()
            
            predictions.extend(batch_preds)
    
    return np.array(predictions)

def analyze_model_agreement(pred1, pred2, labels, model1_name, model2_name):
    """
    Analyze agreement between two models' predictions.
    
    Args:
        pred1: Predictions from model 1
        pred2: Predictions from model 2
        labels: Ground truth labels
        model1_name: Name of model 1
        model2_name: Name of model 2
    
    Returns:
        Dictionary with analysis results
    """
    # Convert to numpy if needed
    if isinstance(pred1, torch.Tensor):
        pred1 = pred1.numpy()
    if isinstance(pred2, torch.Tensor):
        pred2 = pred2.numpy()
    if isinstance(labels, torch.Tensor):
        labels = labels.numpy()
    
    n_samples = len(labels)
    
    # Correct/incorrect masks
    correct1 = (pred1 == labels)
    correct2 = (pred2 == labels)
    
    # Agreement analysis
    both_correct = np.sum(correct1 & correct2)
    both_wrong = np.sum(~correct1 & ~correct2)
    model1_correct_model2_wrong = np.sum(correct1 & ~correct2)
    model1_wrong_model2_correct = np.sum(~correct1 & correct2)
    
    # Prediction agreement (same prediction regardless of correctness)
    same_predictions = np.sum(pred1 == pred2)
    different_predictions = np.sum(pred1 != pred2)
    
    # Agreement on correct predictions
    agreement_on_correct = both_correct / np.sum(labels == pred1) if np.sum(correct1) > 0 else 0
    
    # Agreement on wrong predictions
    agreement_on_wrong = both_wrong / np.sum(pred1 != labels) if np.sum(~correct1) > 0 else 0
    
    # Overall prediction agreement (Cohen's Kappa)
    kappa = cohen_kappa_score(pred1, pred2)
    
    # Accuracy of each model
    acc1 = accuracy_score(labels, pred1)
    acc2 = accuracy_score(labels, pred2)
    
    results = {
        'n_samples': n_samples,
        'model1_accuracy': acc1,
        'model2_accuracy': acc2,
        'both_correct': int(both_correct),
        'both_wrong': int(both_wrong),
        'model1_correct_model2_wrong': int(model1_correct_model2_wrong),
        'model1_wrong_model2_correct': int(model1_wrong_model2_correct),
        'same_predictions': int(same_predictions),
        'different_predictions': int(different_predictions),
        'both_correct_ratio': both_correct / n_samples,
        'both_wrong_ratio': both_wrong / n_samples,
        'model1_correct_model2_wrong_ratio': model1_correct_model2_wrong / n_samples,
        'model1_wrong_model2_correct_ratio': model1_wrong_model2_correct / n_samples,
        'same_predictions_ratio': same_predictions / n_samples,
        'different_predictions_ratio': different_predictions / n_samples,
        'agreement_on_correct': agreement_on_correct,
        'agreement_on_wrong': agreement_on_wrong,
        'cohen_kappa': kappa,
        'prediction_agreement_rate': same_predictions / n_samples
    }
    
    return results, correct1, correct2, (pred1 == pred2)

def plot_agreement_matrix(correct1, correct2, same_pred, save_path, model1_name, model2_name):
    """
    Plot agreement matrix visualization.
    """
    fig, axes = plt.subplots(1, 2, figsize=(14, 6))
    
    # Agreement matrix: Correct/Incorrect
    agreement_data = np.zeros((2, 2), dtype=int)
    agreement_data[0, 0] = int(np.sum(correct1 & correct2))  # Both correct
    agreement_data[0, 1] = int(np.sum(correct1 & ~correct2))  # Model1 correct, Model2 wrong
    agreement_data[1, 0] = int(np.sum(~correct1 & correct2))  # Model1 wrong, Model2 correct
    agreement_data[1, 1] = int(np.sum(~correct1 & ~correct2))  # Both wrong
    
    sns.heatmap(agreement_data, annot=True, fmt='d', cmap='Blues', 
                xticklabels=[f'{model2_name}\nCorrect', f'{model2_name}\nWrong'],
                yticklabels=[f'{model1_name}\nCorrect', f'{model1_name}\nWrong'],
                ax=axes[0])
    axes[0].set_title('Correct/Wrong Agreement Matrix')
    axes[0].set_ylabel('Model 1')
    axes[0].set_xlabel('Model 2')
    
    # Prediction agreement (same/different predictions)
    pred_agreement_data = np.zeros((2, 2), dtype=int)
    pred_agreement_data[0, 0] = int(np.sum(same_pred & correct1))  # Same pred, Model1 correct
    pred_agreement_data[0, 1] = int(np.sum(same_pred & ~correct1))  # Same pred, Model1 wrong
    pred_agreement_data[1, 0] = int(np.sum(~same_pred & correct1))  # Diff pred, Model1 correct
    pred_agreement_data[1, 1] = int(np.sum(~same_pred & ~correct1))  # Diff pred, Model1 wrong
    
    sns.heatmap(pred_agreement_data, annot=True, fmt='d', cmap='Greens',
                xticklabels=['Same\nPrediction', 'Different\nPrediction'],
                yticklabels=[f'{model1_name}\nCorrect', f'{model1_name}\nWrong'],
                ax=axes[1])
    axes[1].set_title('Prediction Agreement vs Correctness')
    axes[1].set_ylabel('Model 1')
    axes[1].set_xlabel('')
    
    plt.tight_layout()
    plt.savefig(save_path, dpi=150, bbox_inches='tight')
    plt.close()

def analyze_class_level_agreement(pred1, pred2, labels, model1_name, model2_name):
    """
    Analyze agreement at the class level.
    """
    unique_classes = np.unique(labels)
    class_results = []
    
    for cls in unique_classes:
        mask = (labels == cls)
        n_class_samples = np.sum(mask)
        
        if n_class_samples == 0:
            continue
        
        pred1_cls = pred1[mask]
        pred2_cls = pred2[mask]
        labels_cls = labels[mask]
        
        correct1 = (pred1_cls == labels_cls)
        correct2 = (pred2_cls == labels_cls)
        
        both_correct = np.sum(correct1 & correct2)
        both_wrong = np.sum(~correct1 & ~correct2)
        same_pred = np.sum(pred1_cls == pred2_cls)
        
        class_results.append({
            'class': int(cls),
            'n_samples': int(n_class_samples),
            'model1_accuracy': float(np.sum(correct1) / n_class_samples),
            'model2_accuracy': float(np.sum(correct2) / n_class_samples),
            'both_correct': int(both_correct),
            'both_wrong': int(both_wrong),
            'both_correct_ratio': float(both_correct / n_class_samples),
            'both_wrong_ratio': float(both_wrong / n_class_samples),
            'same_predictions': int(same_pred),
            'same_predictions_ratio': float(same_pred / n_class_samples),
        })
    
    return pd.DataFrame(class_results)

def main():
    parser = argparse.ArgumentParser(description='Compare predictions from two trained models')
    parser.add_argument('--model1_dir', required=True,
                       help='Directory of first model (e.g., models/20260106_001352/dinov3)')
    parser.add_argument('--model2_dir', required=True,
                       help='Directory of second model (e.g., models/20260106_001352/dinov2)')
    parser.add_argument('--batch_size', type=int, default=128,
                       help='Batch size for inference')
    parser.add_argument('--device', default='cuda' if torch.cuda.is_available() else 'cpu',
                       help='Device to use')
    parser.add_argument('--output_dir', default=None,
                       help='Output directory for results')
    parser.add_argument('--split', default='test', choices=['test', 'train'],
                       help='Which split to evaluate on (test or train)')
    
    args = parser.parse_args()
    
    device = args.device
    print(f"Using device: {device}")
    
    # Load models
    print("Loading models...")
    print(f"  Loading model 1 from {args.model1_dir}...")
    model1, config1, metrics1, embedding_dir1 = load_model(args.model1_dir, device)
    model1_name = os.path.basename(args.model1_dir.rstrip('/'))
    
    print(f"  Loading model 2 from {args.model2_dir}...")
    model2, config2, metrics2, embedding_dir2 = load_model(args.model2_dir, device)
    model2_name = os.path.basename(args.model2_dir.rstrip('/'))
    
    # Load embeddings
    print(f"\nLoading {args.split} embeddings...")
    
    # Load embeddings for model 1 (handle concatenated models)
    if embedding_dir1 is not None:
        # Single embedding model
        print(f"  Loading embeddings for {model1_name} from {embedding_dir1}...")
        emb1_path = os.path.join(embedding_dir1, f"{args.split}.pt")
        if not os.path.exists(emb1_path):
            raise FileNotFoundError(f"Embeddings file not found: {emb1_path}")
        embeddings1, labels = load_embeddings(emb1_path, map_location='cpu')
    else:
        # Concatenated model - load and concatenate
        print(f"  Loading and concatenating embeddings for {model1_name}...")
        embeddings1 = None
        labels = None
        for idx, emb_dir in enumerate(config1['embedding_dirs']):
            print(f"    Loading from {emb_dir}... ({idx+1}/{len(config1['embedding_dirs'])})")
            emb_path = os.path.join(emb_dir, f"{args.split}.pt")
            if not os.path.exists(emb_path):
                raise FileNotFoundError(f"Embeddings file not found: {emb_path}")
            emb, lab = load_embeddings(emb_path, map_location='cpu')
            
            if embeddings1 is None:
                embeddings1 = emb
                labels = lab
            else:
                # Verify labels match
                if not torch.equal(labels, lab):
                    raise ValueError(f"Label mismatch in {emb_dir}")
                # Concatenate embeddings
                embeddings1 = torch.cat([embeddings1, emb], dim=1)
                del emb, lab
    
    # Load embeddings for model 2 (handle concatenated models)
    if embedding_dir2 is not None:
        # Single embedding model
        print(f"  Loading embeddings for {model2_name} from {embedding_dir2}...")
        emb2_path = os.path.join(embedding_dir2, f"{args.split}.pt")
        if not os.path.exists(emb2_path):
            raise FileNotFoundError(f"Embeddings file not found: {emb2_path}")
        embeddings2, labels2 = load_embeddings(emb2_path, map_location='cpu')
    else:
        # Concatenated model - load and concatenate
        print(f"  Loading and concatenating embeddings for {model2_name}...")
        embeddings2 = None
        labels2 = None
        for idx, emb_dir in enumerate(config2['embedding_dirs']):
            print(f"    Loading from {emb_dir}... ({idx+1}/{len(config2['embedding_dirs'])})")
            emb_path = os.path.join(emb_dir, f"{args.split}.pt")
            if not os.path.exists(emb_path):
                raise FileNotFoundError(f"Embeddings file not found: {emb_path}")
            emb, lab = load_embeddings(emb_path, map_location='cpu')
            
            if embeddings2 is None:
                embeddings2 = emb
                labels2 = lab
            else:
                # Verify labels match
                if not torch.equal(labels2, lab):
                    raise ValueError(f"Label mismatch in {emb_dir}")
                # Concatenate embeddings
                embeddings2 = torch.cat([embeddings2, emb], dim=1)
                del emb, lab
    
    # Verify labels match between models
    if labels is None or labels2 is None:
        raise ValueError("Failed to load labels")
    if not torch.equal(labels, labels2):
        raise ValueError("Labels from two embedding files do not match!")
    
    labels = labels.numpy()
    print(f"Loaded {len(labels)} samples")
    print(f"Model 1 embedding shape: {embeddings1.shape}")
    print(f"Model 2 embedding shape: {embeddings2.shape}")
    
    # Get predictions
    print(f"\nGetting predictions from {model1_name}...")
    dataset1 = TensorDataset(embeddings1, torch.from_numpy(labels))
    loader1 = DataLoader(dataset1, batch_size=args.batch_size, shuffle=False)
    pred1 = get_predictions(model1, loader1, device)
    
    print(f"\nGetting predictions from {model2_name}...")
    dataset2 = TensorDataset(embeddings2, torch.from_numpy(labels))
    loader2 = DataLoader(dataset2, batch_size=args.batch_size, shuffle=False)
    pred2 = get_predictions(model2, loader2, device)
    
    # Analyze agreement
    print("\nAnalyzing model agreement...")
    results, correct1, correct2, same_pred = analyze_model_agreement(
        pred1, pred2, labels, model1_name, model2_name
    )
    
    # Print results
    print("\n" + "="*60)
    print("MODEL COMPARISON RESULTS")
    print("="*60)
    print(f"\nModel 1: {model1_name}")
    print(f"  Accuracy: {results['model1_accuracy']:.4f}")
    print(f"\nModel 2: {model2_name}")
    print(f"  Accuracy: {results['model2_accuracy']:.4f}")
    
    print(f"\n--- Agreement Analysis ---")
    print(f"Total samples: {results['n_samples']}")
    print(f"\nBoth models correct: {results['both_correct']} ({results['both_correct_ratio']:.2%})")
    print(f"Both models wrong: {results['both_wrong']} ({results['both_wrong_ratio']:.2%})")
    print(f"{model1_name} correct, {model2_name} wrong: {results['model1_correct_model2_wrong']} ({results['model1_correct_model2_wrong_ratio']:.2%})")
    print(f"{model1_name} wrong, {model2_name} correct: {results['model1_wrong_model2_correct']} ({results['model1_wrong_model2_correct_ratio']:.2%})")
    
    print(f"\n--- Prediction Agreement ---")
    print(f"Same predictions: {results['same_predictions']} ({results['same_predictions_ratio']:.2%})")
    print(f"Different predictions: {results['different_predictions']} ({results['different_predictions_ratio']:.2%})")
    print(f"Cohen's Kappa (agreement metric): {results['cohen_kappa']:.4f}")
    
    print(f"\n--- Detailed Agreement ---")
    print(f"Agreement on correct predictions (when {model1_name} is correct): {results['agreement_on_correct']:.2%}")
    print(f"Agreement on wrong predictions (when {model1_name} is wrong): {results['agreement_on_wrong']:.2%}")
    
    # Class-level analysis
    print(f"\nPerforming class-level analysis...")
    class_df = analyze_class_level_agreement(pred1, pred2, labels, model1_name, model2_name)
    
    # Save results
    if args.output_dir is None:
        timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
        output_dir = os.path.join("models", "comparisons", timestamp, f"{model1_name}_vs_{model2_name}")
    else:
        output_dir = args.output_dir
    
    os.makedirs(output_dir, exist_ok=True)
    print(f"\nSaving results to {output_dir}")
    
    # Save overall results
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
    
    results_serializable = convert_to_serializable(results)
    results_serializable['model1_name'] = model1_name
    results_serializable['model2_name'] = model2_name
    results_serializable['split'] = args.split
    
    with open(os.path.join(output_dir, 'comparison_results.json'), 'w') as f:
        json.dump(results_serializable, f, indent=4)
    
    # Save class-level results
    class_df.to_csv(os.path.join(output_dir, 'class_level_agreement.csv'), index=False)
    
    # Save plots
    try:
        plot_agreement_matrix(correct1, correct2, same_pred,
                            os.path.join(output_dir, 'agreement_matrix.png'),
                            model1_name, model2_name)
        print("Agreement matrix plot saved.")
    except Exception as e:
        print(f"WARNING: Failed to save agreement matrix: {e}", file=sys.stderr)
        traceback.print_exc(file=sys.stderr)
    
    # Summary statistics
    summary_stats = {
        'mean_class_agreement': float(class_df['same_predictions_ratio'].mean()),
        'mean_both_correct_ratio': float(class_df['both_correct_ratio'].mean()),
        'mean_both_wrong_ratio': float(class_df['both_wrong_ratio'].mean()),
        'std_class_agreement': float(class_df['same_predictions_ratio'].std()),
    }
    
    with open(os.path.join(output_dir, 'summary_stats.json'), 'w') as f:
        json.dump(summary_stats, f, indent=4)
    
    print(f"\nClass-level statistics:")
    print(f"  Mean class agreement rate: {summary_stats['mean_class_agreement']:.2%}")
    print(f"  Mean both correct ratio: {summary_stats['mean_both_correct_ratio']:.2%}")
    print(f"  Mean both wrong ratio: {summary_stats['mean_both_wrong_ratio']:.2%}")
    
    print(f"\nAll results saved to {output_dir}")

if __name__ == "__main__":
    try:
        main()
        sys.exit(0)
    except KeyboardInterrupt:
        print("\nComparison interrupted by user.", file=sys.stderr)
        sys.exit(130)
    except Exception as e:
        print(f"\nERROR: Comparison failed with error: {e}", file=sys.stderr)
        print("\nFull traceback:", file=sys.stderr)
        traceback.print_exc(file=sys.stderr)
        sys.exit(1)

