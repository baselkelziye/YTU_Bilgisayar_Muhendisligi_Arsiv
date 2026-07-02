import torch
import os
import argparse
from tqdm import tqdm
from torch.utils.data import DataLoader
from data.dataset import CUB200Dataset, iNaturalist2021Dataset
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
    parser = argparse.ArgumentParser()
    parser.add_argument("--dataset_dir", default="dataset", help="Path to dataset root")
    parser.add_argument("--dataset_type", default="cub", choices=['cub', 'inaturalist'], 
                       help="Dataset type: 'cub' for CUB-200-2011 or 'inaturalist' for iNaturalist 2021")
    parser.add_argument("--model", required=True, choices=['dinov2', 'dinov3', 'openclip', 'siglip', 'convnext'], help="Model to use")
    parser.add_argument("--batch_size", type=int, default=32)
    parser.add_argument("--device", default="cuda" if torch.cuda.is_available() else "cpu")
    parser.add_argument("--use_mini", action="store_true", 
                       help="Use train_mini for iNaturalist (only applies to iNaturalist dataset)")
    parser.add_argument("--extract_val", action="store_true",
                       help="Also extract validation set embeddings (for iNaturalist)")
    args = parser.parse_args()
    
    print(f"Loading model {args.model}...")
    extractor = get_extractor(args.model, args.device)
    
    # Transforms
    transform = extractor.get_transform()
    
    # Datasets
    print(f"Loading {args.dataset_type} datasets...")
    if args.dataset_type == 'cub':
        train_ds = CUB200Dataset(args.dataset_dir, split='train', transform=transform)
        test_ds = CUB200Dataset(args.dataset_dir, split='test', transform=transform)
        val_ds = None
    elif args.dataset_type == 'inaturalist':
        train_ds = iNaturalist2021Dataset(args.dataset_dir, split='train', 
                                         use_mini=args.use_mini, transform=transform)
        test_ds = iNaturalist2021Dataset(args.dataset_dir, split='test', transform=transform)
        if args.extract_val:
            val_ds = iNaturalist2021Dataset(args.dataset_dir, split='val', transform=transform)
        else:
            val_ds = None
    else:
        raise ValueError(f"Unknown dataset type: {args.dataset_type}")
    
    train_loader = DataLoader(train_ds, batch_size=args.batch_size, shuffle=False, num_workers=4)
    test_loader = DataLoader(test_ds, batch_size=args.batch_size, shuffle=False, num_workers=4)
    
    # Paths - include dataset type in path
    dataset_suffix = f"_{args.dataset_type}"
    if args.dataset_type == 'inaturalist' and args.use_mini:
        dataset_suffix += "_mini"
    save_dir = os.path.join("embeddings", args.model + dataset_suffix)
    
    print("Extracting train embeddings...")
    extract_and_save(extractor, train_loader, os.path.join(save_dir, "train.pt"), args.device)
    
    print("Extracting test embeddings...")
    extract_and_save(extractor, test_loader, os.path.join(save_dir, "test.pt"), args.device)
    
    if val_ds is not None:
        val_loader = DataLoader(val_ds, batch_size=args.batch_size, shuffle=False, num_workers=4)
        print("Extracting validation embeddings...")
        extract_and_save(extractor, val_loader, os.path.join(save_dir, "val.pt"), args.device)

if __name__ == "__main__":
    main()

