import os
import json
import matplotlib.pyplot as plt
import matplotlib.colors as mcolors
import seaborn as sns
import pandas as pd
import argparse

def load_metrics(models_dir):
    results = []
    
    # Iterate over all subdirectories in the models directory
    for model_name in os.listdir(models_dir):
        model_path = os.path.join(models_dir, model_name)
        if not os.path.isdir(model_path):
            continue
            
        metrics_file = os.path.join(model_path, "metrics.json")
        if not os.path.exists(metrics_file):
            print(f"Warning: No metrics.json found for {model_name}")
            continue
            
        with open(metrics_file, 'r') as f:
            metrics = json.load(f)
            
        results.append({
            'Model': model_name,
            'Accuracy': metrics['accuracy'],
            'Precision': metrics['precision'],
            'Recall': metrics['recall'],
            'F1 Score': metrics['f1']
        })
        
    return pd.DataFrame(results)

def plot_comparison(df, save_dir):
    # Melt dataframe for seaborn
    df_melted = df.melt(id_vars="Model", var_name="Metric", value_name="Score")
    
    # Set plot style
    sns.set_theme(style="whitegrid")
    
    # Create comparison plot
    plt.figure(figsize=(15, 8))
    ax = sns.barplot(data=df_melted, x="Model", y="Score", hue="Metric", palette="viridis")
    
    # Add values on top of bars
    for container in ax.containers:
        ax.bar_label(container, fmt='%.3f', padding=3, rotation=90)
        
    plt.title("Model Comparison Metrics", fontsize=16, pad=20)
    # Fix text alignment for rotated labels
    plt.xticks(rotation=45, ha='right')
    plt.ylim(0, 1.1)  # Scores are between 0 and 1, add some headroom for labels
    plt.legend(bbox_to_anchor=(1.05, 1), loc='upper left')
    
    # Adjust layout to prevent label cutoff
    plt.tight_layout()
    plt.subplots_adjust(bottom=0.15, right=0.85)  # Add extra space for rotated labels
    save_path = os.path.join(save_dir, "model_comparison.png")
    plt.savefig(save_path, dpi=300, bbox_inches='tight')
    print(f"Comparison plot saved to {save_path}")
    plt.close()

def categorize_model(model_name):
    """
    Categorize model based on keywords in name.
    Returns: 'ensemble', 'concat', 'sum', or 'single'
    """
    model_lower = model_name.lower()
    if 'ensemble' in model_lower:
        return 'ensemble'
    elif 'concat' in model_lower:
        return 'concat'
    elif 'sum' in model_lower:
        return 'sum'
    else:
        return 'single'

def get_category_colors(df):
    """
    Create color palette based on model categories.
    Returns a list of colors matching the order of models in df.
    """
    # Base colors for each category (using distinct, vibrant colors)
    base_colors = {
        'ensemble': '#E74C3C',      # Red
        'concat': '#3498DB',       # Blue
        'sum': '#2ECC71',          # Green
        'single': '#9B59B6'        # Purple
    }
    
    # Predefined color palettes for each category (darker to lighter)
    category_palettes = {
        'ensemble': ['#C0392B', '#E74C3C', '#EC7063', '#F1948A'],  # Red shades
        'concat': ['#2874A6', '#3498DB', '#5DADE2', '#85C1E9'],    # Blue shades
        'sum': ['#1E8449', '#2ECC71', '#58D68D', '#82E0AA'],        # Green shades
        'single': ['#7D3C98', '#9B59B6', '#BB8FCE', '#D7BDE2']     # Purple shades
    }
    
    # Group models by category
    categories = {}
    for idx, model_name in enumerate(df['Model']):
        category = categorize_model(model_name)
        if category not in categories:
            categories[category] = []
        categories[category].append(idx)
    
    # Create color list
    colors = [''] * len(df)
    
    # Assign colors with shades for each category
    for category, indices in categories.items():
        palette = category_palettes[category]
        n_models = len(indices)
        
        if n_models == 1:
            # Single model in category, use middle shade
            colors[indices[0]] = palette[1] if len(palette) > 1 else palette[0]
        else:
            # Multiple models, distribute across palette shades
            # Use darker shades for better visibility
            n_shades = min(n_models, len(palette))
            
            for i, idx in enumerate(indices):
                # Distribute models across available shades
                shade_idx = int((i / (n_models - 1)) * (n_shades - 1)) if n_models > 1 else 0
                shade_idx = min(shade_idx, len(palette) - 1)
                colors[idx] = palette[shade_idx]
    
    return colors

def plot_f1_comparison(df, save_dir, zoom_f1=False):
    plt.figure(figsize=(12, 6))
    
    # Sort by F1 Score
    df_sorted = df.sort_values('F1 Score', ascending=False).reset_index(drop=True)
    
    # Get category-based colors
    colors = get_category_colors(df_sorted)
    
    # Create barplot with custom colors
    ax = plt.subplot(111)
    bars = ax.bar(range(len(df_sorted)), df_sorted['F1 Score'], color=colors)
    
    # Add values on top of bars
    for i, (bar, value) in enumerate(zip(bars, df_sorted['F1 Score'])):
        height = bar.get_height()
        ax.text(bar.get_x() + bar.get_width()/2., height,
                f'{value:.4f}',
                ha='center', va='bottom', fontsize=9)
    
    # Set x-axis labels
    ax.set_xticks(range(len(df_sorted)))
    ax.set_xticklabels(df_sorted['Model'], rotation=45, ha='right')
    ax.set_ylabel('F1 Score', fontsize=12)
    ax.set_title("F1 Score Comparison (Sorted)", fontsize=16, pad=20)
    
    # Set y-axis limits based on zoom option
    if zoom_f1:
        ax.set_ylim(0.65, 0.85)
    else:
        ax.set_ylim(0, 1.1)
    
    # Adjust layout to prevent label cutoff
    # Use subplots_adjust first, then try tight_layout with padding
    plt.subplots_adjust(bottom=0.25, top=0.95, left=0.1, right=0.95)
    try:
        plt.tight_layout(pad=2.0, h_pad=1.0, w_pad=1.0)
    except:
        # If tight_layout fails, use manual adjustment
        pass
    
    # Set filename based on zoom option
    if zoom_f1:
        filename = "f1_score_ranking_zoom.png"
    else:
        filename = "f1_score_ranking.png"
    
    save_path = os.path.join(save_dir, filename)
    plt.savefig(save_path, dpi=300, bbox_inches='tight')
    print(f"F1 ranking plot saved to {save_path}")
    plt.close()

def main():
    parser = argparse.ArgumentParser(description="Compare model results from metrics.json files")
    parser.add_argument("--models_dir", required=True, help="Path to the directory containing model subdirectories")
    parser.add_argument("--zoom_f1", action="store_true", help="Zoom F1 score plot to 0.6-1.0 range on y-axis")
    args = parser.parse_args()
    
    if not os.path.exists(args.models_dir):
        print(f"Error: Directory {args.models_dir} does not exist")
        return

    print(f"Loading metrics from {args.models_dir}...")
    df = load_metrics(args.models_dir)
    
    if df.empty:
        print("No metrics found.")
        return
        
    print("\nResults Summary:")
    print(df.sort_values('F1 Score', ascending=False).to_string(index=False))
    
    # Save comparison CSV
    csv_path = os.path.join(args.models_dir, "comparison_summary.csv")
    df.sort_values('F1 Score', ascending=False).to_csv(csv_path, index=False)
    print(f"\nSummary CSV saved to {csv_path}")
    
    # Generate plots
    plot_comparison(df, args.models_dir)
    plot_f1_comparison(df, args.models_dir, zoom_f1=args.zoom_f1)

if __name__ == "__main__":
    main()

