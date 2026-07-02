"""
Reduce embedding dimensions using PCA or other dimensionality reduction methods.
This allows embeddings with different dimensions to be summed together.
"""

import torch
import argparse
import os
import numpy as np
from sklearn.decomposition import PCA, IncrementalPCA
from sklearn.preprocessing import StandardScaler
import json
from datetime import datetime
import sys
import traceback
import gc

def load_embeddings(path, map_location=None):
    """Load embeddings from file."""
    if map_location is None:
        data = torch.load(path)
    else:
        data = torch.load(path, map_location=map_location)
    return data['embeddings'], data['labels']

def save_embeddings(embeddings, labels, path):
    """Save embeddings to file."""
    os.makedirs(os.path.dirname(path), exist_ok=True)
    torch.save({'embeddings': embeddings, 'labels': labels}, path)
    print(f"Saved {embeddings.shape[0]} embeddings with shape {embeddings.shape} to {path}")

def reduce_dimensions(embeddings_train, embeddings_test, target_dim, method='pca', batch_size=10000, random_state=42):
    """
    Reduce embedding dimensions using specified method with memory-efficient batch processing.
    
    Args:
        embeddings_train: Training embeddings (N x D)
        embeddings_test: Test embeddings (M x D)
        target_dim: Target dimensionality
        method: Method to use ('pca', 'incremental_pca', 'truncated_svd')
        batch_size: Batch size for incremental processing (default: 10000)
        random_state: Random state for reproducibility
        
    Returns:
        Reduced train and test embeddings
    """
    if embeddings_train.shape[1] <= target_dim:
        print(f"Warning: Embeddings already have dimension {embeddings_train.shape[1]} <= target {target_dim}. Returning original embeddings.")
        return embeddings_train, embeddings_test, {}
    
    original_dim = embeddings_train.shape[1]
    print(f"Reducing dimensions from {original_dim} to {target_dim} using {method.upper()}...")
    print(f"Train size: {embeddings_train.shape[0]}, Test size: {embeddings_test.shape[0]}")
    
    # Convert to numpy for sklearn (do this in chunks to save memory)
    print("Converting to numpy...")
    train_np = embeddings_train.numpy()
    test_np = embeddings_test.numpy()
    
    # Free GPU memory if any
    del embeddings_train, embeddings_test
    gc.collect()
    if torch.cuda.is_available():
        torch.cuda.empty_cache()
    
    if method == 'pca' or method == 'incremental_pca':
        # For large datasets, use IncrementalPCA
        use_incremental = (train_np.shape[0] > 100000) or (method == 'incremental_pca')
        
        if use_incremental:
            print(f"Using IncrementalPCA with batch_size={batch_size} for memory efficiency...")
            
            # Fit scaler in batches (compute mean and std incrementally)
            print("Fitting StandardScaler in batches...")
            scaler = StandardScaler()
            n_batches = (train_np.shape[0] + batch_size - 1) // batch_size
            
            # Partial fit for mean/std calculation
            for i in range(n_batches):
                start_idx = i * batch_size
                end_idx = min((i + 1) * batch_size, train_np.shape[0])
                scaler.partial_fit(train_np[start_idx:end_idx])
                if (i + 1) % 10 == 0:
                    print(f"  Processed {end_idx}/{train_np.shape[0]} samples for scaler fitting...")
            
            # Transform train in batches
            print("Transforming train embeddings (standardizing)...")
            train_scaled = np.zeros_like(train_np, dtype=np.float32)
            for i in range(n_batches):
                start_idx = i * batch_size
                end_idx = min((i + 1) * batch_size, train_np.shape[0])
                train_scaled[start_idx:end_idx] = scaler.transform(train_np[start_idx:end_idx])
                if (i + 1) % 10 == 0:
                    print(f"  Processed {end_idx}/{train_np.shape[0]} samples...")
            
            # Transform test
            print("Transforming test embeddings (standardizing)...")
            test_scaled = scaler.transform(test_np)
            
            # Free original arrays
            del train_np, test_np
            gc.collect()
            
            # Apply IncrementalPCA
            print("Fitting IncrementalPCA...")
            ipca = IncrementalPCA(n_components=target_dim, batch_size=batch_size)
            
            # Fit in batches
            for i in range(n_batches):
                start_idx = i * batch_size
                end_idx = min((i + 1) * batch_size, train_scaled.shape[0])
                ipca.partial_fit(train_scaled[start_idx:end_idx])
                if (i + 1) % 10 == 0:
                    print(f"  Partial fit on {end_idx}/{train_scaled.shape[0]} samples...")
            
            # Transform train in batches
            print("Transforming train embeddings (PCA)...")
            train_reduced = np.zeros((train_scaled.shape[0], target_dim), dtype=np.float32)
            for i in range(n_batches):
                start_idx = i * batch_size
                end_idx = min((i + 1) * batch_size, train_scaled.shape[0])
                train_reduced[start_idx:end_idx] = ipca.transform(train_scaled[start_idx:end_idx])
                if (i + 1) % 10 == 0:
                    print(f"  Transformed {end_idx}/{train_scaled.shape[0]} samples...")
            
            # Transform test
            print("Transforming test embeddings (PCA)...")
            test_reduced = ipca.transform(test_scaled)
            
            # Free intermediate arrays
            del train_scaled, test_scaled
            gc.collect()
            
            # Calculate explained variance (approximate for IncrementalPCA)
            explained_variance = ipca.explained_variance_ratio_.sum() if hasattr(ipca, 'explained_variance_ratio_') else None
            
        else:
            # Standard PCA for smaller datasets
            print("Using standard PCA...")
            
            # Standardize features (important for PCA)
            scaler = StandardScaler()
            train_scaled = scaler.fit_transform(train_np)
            test_scaled = scaler.transform(test_np)
            
            # Free original arrays
            del train_np, test_np
            gc.collect()
            
            # Apply PCA
            pca = PCA(n_components=target_dim, random_state=random_state)
            train_reduced = pca.fit_transform(train_scaled)
            test_reduced = pca.transform(test_scaled)
            
            # Calculate explained variance
            explained_variance = pca.explained_variance_ratio_.sum()
            
            # Free intermediate arrays
            del train_scaled, test_scaled
            gc.collect()
        
        explained_variance_str = f"{explained_variance:.4f} ({explained_variance*100:.2f}%)" if explained_variance else "N/A (IncrementalPCA)"
        print(f"Explained variance ratio: {explained_variance_str}")
        
        # Convert back to torch tensors
        train_reduced_torch = torch.from_numpy(train_reduced).float()
        test_reduced_torch = torch.from_numpy(test_reduced).float()
        
        del train_reduced, test_reduced
        gc.collect()
        
        return (train_reduced_torch, 
                test_reduced_torch, 
                {'method': 'incremental_pca' if use_incremental else 'pca', 
                 'explained_variance_ratio': float(explained_variance) if explained_variance else None,
                 'original_dim': int(original_dim),
                 'target_dim': int(target_dim)})
    
    elif method == 'truncated_svd':
        from sklearn.decomposition import TruncatedSVD
        
        # Standardize features
        scaler = StandardScaler()
        train_scaled = scaler.fit_transform(train_np)
        test_scaled = scaler.transform(test_np)
        
        # Apply TruncatedSVD
        svd = TruncatedSVD(n_components=target_dim, random_state=random_state)
        train_reduced = svd.fit_transform(train_scaled)
        test_reduced = svd.transform(test_scaled)
        
        # Calculate explained variance
        explained_variance = svd.explained_variance_ratio_.sum()
        print(f"Explained variance ratio: {explained_variance:.4f} ({explained_variance*100:.2f}%)")
        
        return (torch.from_numpy(train_reduced).float(), 
                torch.from_numpy(test_reduced).float(),
                {'method': 'truncated_svd',
                 'explained_variance_ratio': float(explained_variance),
                 'original_dim': int(embeddings_train.shape[1]),
                 'target_dim': int(target_dim)})
    
    else:
        raise ValueError(f"Unknown method: {method}. Choose 'pca' or 'truncated_svd'.")

def main():
    parser = argparse.ArgumentParser(
        description="Reduce embedding dimensions using PCA or other methods"
    )
    parser.add_argument("--embedding_dir", required=True,
                       help="Directory containing train.pt and test.pt")
    parser.add_argument("--target_dim", type=int, required=True,
                       help="Target dimensionality (e.g., 1024 to match dinov2/dinov3)")
    parser.add_argument("--output_dir", default=None,
                       help="Output directory for reduced embeddings (default: <embedding_dir>_reduced_<target_dim>)")
    parser.add_argument("--method", default='pca', choices=['pca', 'incremental_pca', 'truncated_svd'],
                       help="Dimensionality reduction method (default: pca). Use 'incremental_pca' for large datasets (>100k samples)")
    parser.add_argument("--batch_size", type=int, default=10000,
                       help="Batch size for incremental processing (default: 10000)")
    parser.add_argument("--random_state", type=int, default=42,
                       help="Random state for reproducibility (default: 42)")
    parser.add_argument("--device", default="cpu",
                       help="Device for loading embeddings (default: cpu)")
    
    args = parser.parse_args()
    
    try:
        # Load embeddings
        print(f"Loading embeddings from {args.embedding_dir}...")
        train_path = os.path.join(args.embedding_dir, "train.pt")
        test_path = os.path.join(args.embedding_dir, "test.pt")
        
        if not os.path.exists(train_path):
            raise FileNotFoundError(f"Train embeddings not found: {train_path}")
        if not os.path.exists(test_path):
            raise FileNotFoundError(f"Test embeddings not found: {test_path}")
        
        train_emb, train_labels = load_embeddings(train_path, map_location=args.device)
        test_emb, test_labels = load_embeddings(test_path, map_location=args.device)
        
        print(f"Original shapes - Train: {train_emb.shape}, Test: {test_emb.shape}")
        
        # Check if reduction is needed
        if train_emb.shape[1] == args.target_dim:
            print(f"Embeddings already have target dimension {args.target_dim}. No reduction needed.")
            return
        
        if train_emb.shape[1] < args.target_dim:
            print(f"Warning: Original dimension {train_emb.shape[1]} is smaller than target {args.target_dim}.")
            print("Cannot increase dimensions. Consider using a larger target_dim or different method.")
            return
        
        # Reduce dimensions
        train_reduced, test_reduced, reduction_info = reduce_dimensions(
            train_emb, test_emb, args.target_dim, 
            method=args.method, batch_size=args.batch_size, random_state=args.random_state
        )
        
        print(f"Reduced shapes - Train: {train_reduced.shape}, Test: {test_reduced.shape}")
        
        # Determine output directory
        if args.output_dir is None:
            base_name = os.path.basename(args.embedding_dir.rstrip('/'))
            args.output_dir = f"{args.embedding_dir}_reduced_{args.target_dim}"
        
        os.makedirs(args.output_dir, exist_ok=True)
        
        # Save reduced embeddings
        train_output_path = os.path.join(args.output_dir, "train.pt")
        test_output_path = os.path.join(args.output_dir, "test.pt")
        
        save_embeddings(train_reduced, train_labels, train_output_path)
        save_embeddings(test_reduced, test_labels, test_output_path)
        
        # Save reduction metadata
        metadata = {
            'original_embedding_dir': args.embedding_dir,
            'target_dim': args.target_dim,
            'method': args.method,
            'random_state': args.random_state,
            'reduction_info': reduction_info,
            'created_at': datetime.now().isoformat()
        }
        
        metadata_path = os.path.join(args.output_dir, "reduction_metadata.json")
        with open(metadata_path, 'w') as f:
            json.dump(metadata, f, indent=4)
        
        print(f"\nReduced embeddings saved to: {args.output_dir}")
        print(f"Reduction metadata saved to: {metadata_path}")
        print(f"Explained variance: {reduction_info['explained_variance_ratio']*100:.2f}%")
        
    except Exception as e:
        print(f"ERROR: {e}", file=sys.stderr)
        traceback.print_exc(file=sys.stderr)
        sys.exit(1)

if __name__ == "__main__":
    main()

