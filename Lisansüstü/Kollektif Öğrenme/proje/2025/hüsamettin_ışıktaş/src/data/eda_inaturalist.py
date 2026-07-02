import os
import json
import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd
import numpy as np
from collections import Counter

# Set style
plt.style.use('ggplot')
sns.set_palette("husl")

DATASET_DIR = "dataset/inaturalist_2021"
OUTPUT_DIR = "plots/inaturalist_2021"

os.makedirs(OUTPUT_DIR, exist_ok=True)

def load_json(filename):
    """Load JSON file."""
    filepath = os.path.join(DATASET_DIR, filename)
    print(f"Loading {filepath}...")
    with open(filepath, 'r') as f:
        return json.load(f)

def plot_class_distribution(annotations, dataset_name):
    """Plot top 50 class distribution."""
    print(f"Plotting class distribution for {dataset_name}...")
    
    # Count images per category
    category_counts = Counter(ann['category_id'] for ann in annotations)
    
    # Sort by count
    sorted_counts = sorted(category_counts.items(), key=lambda x: x[1], reverse=True)
    
    # Get top 50
    top_50 = sorted_counts[:50]
    category_ids, counts = zip(*top_50)
    
    plt.figure(figsize=(15, 8))
    plt.bar(range(len(counts)), counts)
    plt.title(f'Top 50 Categories Distribution ({dataset_name})')
    plt.xlabel('Category Rank')
    plt.ylabel('Number of Images')
    plt.tight_layout()
    plt.savefig(os.path.join(OUTPUT_DIR, f'{dataset_name}_top50_distribution.png'))
    plt.close()
    
    # Statistics
    counts_list = list(category_counts.values())
    stats = {
        'total_images': len(annotations),
        'total_categories': len(category_counts),
        'min_images_per_class': int(np.min(counts_list)),
        'max_images_per_class': int(np.max(counts_list)),
        'mean_images_per_class': float(np.mean(counts_list)),
        'median_images_per_class': float(np.median(counts_list))
    }
    
    return stats

def plot_supercategory_distribution(categories, annotations, dataset_name):
    """Plot distribution by supercategory."""
    print(f"Plotting supercategory distribution for {dataset_name}...")
    
    # Map category_id to supercategory
    cat_id_to_super = {cat['id']: cat.get('supercategory', 'Unknown') for cat in categories}
    
    # Count images per supercategory
    supercat_counts = Counter(cat_id_to_super[ann['category_id']] for ann in annotations)
    
    # Sort
    sorted_super = sorted(supercat_counts.items(), key=lambda x: x[1], reverse=True)
    names, counts = zip(*sorted_super)
    
    plt.figure(figsize=(12, 8))
    sns.barplot(x=list(counts), y=list(names))
    plt.title(f'Supercategory Distribution ({dataset_name})')
    plt.xlabel('Number of Images')
    plt.tight_layout()
    plt.savefig(os.path.join(OUTPUT_DIR, f'{dataset_name}_supercategory_distribution.png'))
    plt.close()

def plot_image_sizes(images, dataset_name):
    """Plot scatter plot of image dimensions."""
    print(f"Plotting image sizes for {dataset_name}...")
    
    widths = [img['width'] for img in images]
    heights = [img['height'] for img in images]
    
    plt.figure(figsize=(10, 8))
    plt.hist2d(widths, heights, bins=50, cmap='Blues')
    plt.colorbar(label='Count')
    plt.title(f'Image Dimensions Heatmap ({dataset_name})')
    plt.xlabel('Width')
    plt.ylabel('Height')
    plt.tight_layout()
    plt.savefig(os.path.join(OUTPUT_DIR, f'{dataset_name}_image_sizes.png'))
    plt.close()
    
    # Aspect ratios
    ratios = np.array(widths) / np.array(heights)
    plt.figure(figsize=(10, 6))
    plt.hist(ratios, bins=50)
    plt.title(f'Aspect Ratio Distribution ({dataset_name})')
    plt.xlabel('Aspect Ratio (Width/Height)')
    plt.ylabel('Count')
    plt.axvline(x=1.0, color='r', linestyle='--', label='Square (1:1)')
    plt.legend()
    plt.tight_layout()
    plt.savefig(os.path.join(OUTPUT_DIR, f'{dataset_name}_aspect_ratios.png'))
    plt.close()

def main():
    # Load data
    train_data = load_json('train_mini.json')
    val_data = load_json('val.json')
    
    # Process Train Mini
    print("\nProcessing Train Mini...")
    train_stats = plot_class_distribution(train_data['annotations'], 'train_mini')
    plot_supercategory_distribution(train_data['categories'], train_data['annotations'], 'train_mini')
    plot_image_sizes(train_data['images'], 'train_mini')
    
    # Process Val
    print("\nProcessing Val...")
    val_stats = plot_class_distribution(val_data['annotations'], 'val')
    plot_supercategory_distribution(val_data['categories'], val_data['annotations'], 'val')
    plot_image_sizes(val_data['images'], 'val')
    
    # Save statistics
    stats = {
        'train_mini': train_stats,
        'val': val_stats
    }
    
    with open(os.path.join(OUTPUT_DIR, 'dataset_statistics.json'), 'w') as f:
        json.dump(stats, f, indent=4)
        
    print(f"\nAnalysis complete! Results saved to {OUTPUT_DIR}")
    print("Statistics summary:")
    print(json.dumps(stats, indent=4))

if __name__ == "__main__":
    main()

