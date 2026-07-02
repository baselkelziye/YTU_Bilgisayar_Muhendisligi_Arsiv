import os
import pandas as pd
import json
from PIL import Image
from torch.utils.data import Dataset
import torch

class CUB200Dataset(Dataset):
    def __init__(self, root_dir, split='train', transform=None):
        """
        Args:
            root_dir (string): Root directory of the CUB_200_2011 dataset.
            split (string): 'train' or 'test'.
            transform (callable, optional): Optional transform to be applied on a sample.
        """
        self.root_dir = os.path.join(root_dir, 'CUB_200_2011')
        self.transform = transform
        self.split = split
        
        if not os.path.exists(self.root_dir):
            # Fallback if the folder structure is slightly different (e.g. directly in root)
            if os.path.exists(os.path.join(root_dir, 'images')):
                 self.root_dir = root_dir
            else:
                raise FileNotFoundError(f"CUB dataset not found at {self.root_dir}")

        # Load metadata
        self.images = pd.read_csv(os.path.join(self.root_dir, 'images.txt'), sep=' ', names=['img_id', 'filepath'])
        self.image_class_labels = pd.read_csv(os.path.join(self.root_dir, 'image_class_labels.txt'), sep=' ', names=['img_id', 'target'])
        self.train_test_split = pd.read_csv(os.path.join(self.root_dir, 'train_test_split.txt'), sep=' ', names=['img_id', 'is_training_image'])

        # Merge
        self.data = self.images.merge(self.image_class_labels, on='img_id')
        self.data = self.data.merge(self.train_test_split, on='img_id')
        
        # Ensure deterministic order
        self.data = self.data.sort_values('img_id')

        # Filter by split
        if self.split == 'train':
            self.data = self.data[self.data['is_training_image'] == 1]
        elif self.split == 'test':
            self.data = self.data[self.data['is_training_image'] == 0]
        
        # Targets are 1-indexed in file, make them 0-indexed
        self.data['target'] = self.data['target'] - 1

    def __len__(self):
        return len(self.data)

    def __getitem__(self, idx):
        row = self.data.iloc[idx]
        img_path = os.path.join(self.root_dir, 'images', row['filepath'])
        
        try:
            image = Image.open(img_path).convert('RGB')
        except Exception as e:
            print(f"Error loading image {img_path}: {e}")
            # Return a black image or handle gracefully? 
            # For now, let's assume valid data or crash
            raise e

        label = row['target']

        if self.transform:
            image = self.transform(image)

        return image, label


class iNaturalist2021Dataset(Dataset):
    def __init__(self, root_dir, split='train', use_mini=False, transform=None):
        """
        Args:
            root_dir (string): Root directory containing the iNaturalist 2021 dataset.
            split (string): 'train', 'val', or 'test'.
            use_mini (bool): If True, use train_mini instead of full train (only for split='train').
            transform (callable, optional): Optional transform to be applied on a sample.
        """
        self.root_dir = root_dir
        self.transform = transform
        self.split = split
        self.use_mini = use_mini
        
        # Determine image directory based on split
        if split == 'train':
            if use_mini:
                self.image_dir = os.path.join(root_dir, 'train_mini')
            else:
                self.image_dir = os.path.join(root_dir, 'train')
            json_file = os.path.join(root_dir, 'train_mini.json' if use_mini else 'train.json')
        elif split == 'val':
            self.image_dir = os.path.join(root_dir, 'val')
            json_file = os.path.join(root_dir, 'val.json')
        elif split == 'test':
            self.image_dir = os.path.join(root_dir, 'public_test')
            json_file = os.path.join(root_dir, 'public_test.json')
        else:
            raise ValueError(f"Invalid split: {split}. Must be 'train', 'val', or 'test'")
        
        if not os.path.exists(self.image_dir):
            raise FileNotFoundError(f"Image directory not found: {self.image_dir}")
        if not os.path.exists(json_file):
            raise FileNotFoundError(f"Annotation file not found: {json_file}")
        
        # Load JSON annotations
        print(f"Loading annotations from {json_file}...")
        with open(json_file, 'r') as f:
            data = json.load(f)
        
        # Create mappings
        self.images = {img['id']: img for img in data['images']}
        self.categories = {cat['id']: cat for cat in data['categories']}
        
        # For train and val, we have annotations
        if split in ['train', 'val']:
            # Create image_id -> category_id mapping
            self.image_to_category = {}
            for ann in data['annotations']:
                self.image_to_category[ann['image_id']] = ann['category_id']
            
            # Get all image IDs for this split
            self.image_ids = list(self.image_to_category.keys())
            
            # Create category_id to label index mapping (0-indexed)
            unique_categories = sorted(set(self.image_to_category.values()))
            self.category_to_label = {cat_id: idx for idx, cat_id in enumerate(unique_categories)}
            self.num_classes = len(unique_categories)
        else:
            # For test, we don't have annotations
            self.image_ids = [img['id'] for img in data['images']]
            self.image_to_category = None
            self.category_to_label = None
            self.num_classes = None
        
        print(f"Loaded {len(self.image_ids)} images for {split} split")
        if self.num_classes:
            print(f"Number of classes: {self.num_classes}")
    
    def __len__(self):
        return len(self.image_ids)
    
    def __getitem__(self, idx):
        image_id = self.image_ids[idx]
        image_info = self.images[image_id]
        file_name = image_info['file_name']
        
        # Determine image path based on split
        if self.split == 'test':
            # Test images are directly in public_test directory
            img_path = os.path.join(self.image_dir, file_name)
        else:
            # Train/val images are in category subdirectories
            # file_name format: "split/category/image.jpg" (e.g. "train_mini/category/image.jpg")
            img_path = os.path.join(self.root_dir, file_name)
        
        try:
            image = Image.open(img_path).convert('RGB')
        except Exception as e:
            print(f"Error loading image {img_path}: {e}")
            raise e
        
        # Get label if available
        if self.image_to_category is not None:
            category_id = self.image_to_category[image_id]
            label = self.category_to_label[category_id]
        else:
            # For test set, return -1 as placeholder
            label = -1
        
        if self.transform:
            image = self.transform(image)
        
        return image, label

