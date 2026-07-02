import torch
import os
import argparse
from tqdm import tqdm
from torch.utils.data import DataLoader
from data.dataset import iNaturalist2021Dataset
from models.extractors import get_extractor

def extract_and_save(extractor, loader, save_path, device):
    all_embeddings = []
    all_labels = []
    
    with torch.no_grad():
        for images, labels in tqdm(loader, desc=f"Extracting features"):
            images = images.to(device)
            features = extractor(images)
            
            all_embeddings.append(features.cpu())
            all_labels.append(labels)
            
    all_embeddings = torch.cat(all_embeddings, dim=0)
    all_labels = torch.cat(all_labels, dim=0)
    
    os.makedirs(os.path.dirname(save_path), exist_ok=True)
    torch.save({'embeddings': all_embeddings, 'labels': all_labels}, save_path)
    print(f"Saved {all_embeddings.shape[0]} embeddings to {save_path}")

def main():
    parser = argparse.ArgumentParser(description="Extract embeddings for iNaturalist 2021")
    parser.add_argument("--dataset_dir", default="dataset/inaturalist_2021", help="Path to dataset root")
    parser.add_argument("--model", required=True, choices=['dinov2', 'dinov3', 'openclip', 'siglip', 'convnext'], help="Model to use")
    parser.add_argument("--batch_size", type=int, default=32)
    parser.add_argument("--device", default="cuda" if torch.cuda.is_available() else "cpu")
    args = parser.parse_args()
    
    print(f"Loading model {args.model}...")
    extractor = get_extractor(args.model, args.device)
    
    # Transforms
    transform = extractor.get_transform()
    
    # Datasets
    print(f"Loading iNaturalist 2021 datasets from {args.dataset_dir}...")
    
    # Train Mini
    train_ds = iNaturalist2021Dataset(args.dataset_dir, split='train', use_mini=True, transform=transform)
    
    # Validation
    val_ds = iNaturalist2021Dataset(args.dataset_dir, split='val', transform=transform)
    
    # Loaders
    train_loader = DataLoader(train_ds, batch_size=args.batch_size, shuffle=False, num_workers=4)
    val_loader = DataLoader(val_ds, batch_size=args.batch_size, shuffle=False, num_workers=4)
    
    # Output Paths
    save_dir = os.path.join("embeddings/inaturalist_2021", args.model)
    
    print("Extracting train_mini embeddings (saving as train.pt)...")
    extract_and_save(extractor, train_loader, os.path.join(save_dir, "train.pt"), args.device)
    
    print("Extracting val embeddings (saving as test.pt)...")
    extract_and_save(extractor, val_loader, os.path.join(save_dir, "test.pt"), args.device)
    
    print(f"\nAll extractions complete! Results saved to {save_dir}")

if __name__ == "__main__":
    main()

