import os
import sys
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from PIL import Image
import numpy as np
from tqdm import tqdm
import random

# Add src to path
sys.path.append(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))

def perform_eda(dataset_dir="dataset"):
    print("Performing Enhanced EDA on CUB-200-2011 Dataset...")
    
    cub_root = os.path.join(dataset_dir, "CUB_200_2011")
    if not os.path.exists(cub_root):
        print(f"Error: Dataset not found at {cub_root}")
        return

    plots_dir = "plots"
    os.makedirs(plots_dir, exist_ok=True)
    
    # --- 1. Load Metadata ---
    print("Loading metadata...")
    try:
        images = pd.read_csv(os.path.join(cub_root, 'images.txt'), sep=' ', names=['img_id', 'filepath'])
        image_class_labels = pd.read_csv(os.path.join(cub_root, 'image_class_labels.txt'), sep=' ', names=['img_id', 'class_id'])
        train_test_split = pd.read_csv(os.path.join(cub_root, 'train_test_split.txt'), sep=' ', names=['img_id', 'is_training_image'])
        classes = pd.read_csv(os.path.join(cub_root, 'classes.txt'), sep=' ', names=['class_id', 'class_name'])
    except Exception as e:
        print(f"Error loading metadata files: {e}")
        return

    # Merge into single DataFrame
    df = images.merge(image_class_labels, on='img_id')
    df = df.merge(train_test_split, on='img_id')
    df = df.merge(classes, on='class_id')
    
    print(f"Total images in metadata: {len(df)}")
    
    # --- 2. Missing Data / Integrity Check ---
    print("\n--- Integrity Check ---")
    
    # Check for missing values in DataFrame
    missing_vals = df.isnull().sum().sum()
    print(f"Missing values in metadata: {missing_vals}")
    
    # Check file existence
    print("Checking file existence (this may take a moment)...")
    missing_files = []
    for _, row in tqdm(df.iterrows(), total=len(df), desc="Verifying files"):
        full_path = os.path.join(cub_root, 'images', row['filepath'])
        if not os.path.exists(full_path):
            missing_files.append(row['filepath'])
            
    if missing_files:
        print(f"WARNING: {len(missing_files)} images are missing from disk!")
        # Save missing list
        with open(os.path.join(plots_dir, 'missing_files.txt'), 'w') as f:
            for p in missing_files:
                f.write(f"{p}\n")
    else:
        print("All image files exist on disk.")

    # --- 3. Class Distribution ---
    print("\n--- Class Distribution Analysis ---")
    class_counts = df['class_name'].value_counts()
    print(f"Number of classes: {len(class_counts)}")
    print(f"Min samples per class: {class_counts.min()}")
    print(f"Max samples per class: {class_counts.max()}")
    print(f"Mean samples per class: {class_counts.mean():.2f}")
    
    # Train/Test Split Analysis
    train_df = df[df['is_training_image'] == 1]
    test_df = df[df['is_training_image'] == 0]
    
    print(f"Training samples: {len(train_df)}")
    print(f"Test samples: {len(test_df)}")
    
    # Plot Class Distribution
    plt.figure(figsize=(20, 8))
    # Get top 20 and bottom 20 classes for visualization if too many
    top_classes = class_counts.head(20)
    plt.bar(top_classes.index, top_classes.values)
    plt.xticks(rotation=90)
    plt.title("Top 20 Classes by Sample Count")
    plt.tight_layout()
    plt.savefig(os.path.join(plots_dir, 'class_distribution_top20.png'))
    plt.close()

    # Plot Train/Test balance per class (Sample first 50 classes)
    subset_classes = classes['class_name'].iloc[:50]
    subset_df = df[df['class_name'].isin(subset_classes)]
    
    plt.figure(figsize=(20, 10))
    sns.countplot(data=subset_df, x='class_name', hue='is_training_image')
    plt.xticks(rotation=90)
    plt.title("Train (1) vs Test (0) Distribution for First 50 Classes")
    plt.tight_layout()
    plt.savefig(os.path.join(plots_dir, 'train_test_split_subset.png'))
    plt.close()

    # --- 4. Image Size Analysis ---
    print("\n--- Image Size Analysis ---")
    # Sample 1000 images to check dimensions
    sample_size = min(1000, len(df))
    sample_df = df.sample(sample_size, random_state=42)
    
    widths = []
    heights = []
    
    for _, row in tqdm(sample_df.iterrows(), total=sample_size, desc="Checking image sizes"):
        try:
            full_path = os.path.join(cub_root, 'images', row['filepath'])
            with Image.open(full_path) as img:
                w, h = img.size
                widths.append(w)
                heights.append(h)
        except Exception:
            pass
            
    if widths:
        plt.figure(figsize=(10, 6))
        plt.scatter(widths, heights, alpha=0.5)
        plt.title(f"Image Dimensions (Sample of {sample_size})")
        plt.xlabel("Width")
        plt.ylabel("Height")
        plt.grid(True)
        plt.savefig(os.path.join(plots_dir, 'image_sizes_scatter.png'))
        plt.close()
        
        print(f"Average Width: {np.mean(widths):.2f}")
        print(f"Average Height: {np.mean(heights):.2f}")
    
    # --- 5. Visual Samples ---
    print("\n--- Generating Visual Samples ---")
    # Plot 16 random images
    fig, axes = plt.subplots(4, 4, figsize=(16, 16))
    axes = axes.flatten()
    
    sample_viz = df.sample(16, random_state=123)
    
    for ax, (_, row) in zip(axes, sample_viz.iterrows()):
        full_path = os.path.join(cub_root, 'images', row['filepath'])
        try:
            img = Image.open(full_path)
            ax.imshow(img)
            ax.set_title(row['class_name'][:20]) # Truncate long names
            ax.axis('off')
        except Exception as e:
            ax.text(0.5, 0.5, "Error loading", ha='center')
            
    plt.tight_layout()
    plt.savefig(os.path.join(plots_dir, 'sample_images.png'))
    plt.close()
    
    print(f"\nEDA Complete. Plots saved to '{plots_dir}/' directory.")

if __name__ == "__main__":
    perform_eda()
