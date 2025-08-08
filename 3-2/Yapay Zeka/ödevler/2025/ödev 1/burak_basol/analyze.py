import os
import sys
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.metrics import confusion_matrix, ConfusionMatrixDisplay

prefix = sys.argv[1]  # e.g., "run_pop100_mut0.05_"

fitness_data = pd.read_csv(f"{prefix}fitness_progress.csv")
patterns_data = pd.read_csv(f"{prefix}patterns.csv")
reconstructed_data = pd.read_csv(f"{prefix}reconstructed_images.csv")

# Plot 1: Fitness Progress
plt.figure(figsize=(10, 6))
plt.plot(fitness_data['Generation'], fitness_data['BestFitness'], label='Best Fitness')
plt.plot(fitness_data['Generation'], fitness_data['AvgFitness'], label='Avg Fitness')
plt.xlabel('Generation')
plt.ylabel('Fitness')
plt.title('Fitness Progress')
plt.legend()
plt.grid(True)
plt.savefig(f"{prefix}fitness_progress.png")
plt.close()

# Plot 2: Best Patterns
plt.figure(figsize=(15, 5))
for p in range(7):
    plt.subplot(1, 7, p + 1)
    mat = np.zeros((3, 3))
    data = patterns_data[patterns_data['Pattern'] == p]
    for _, row in data.iterrows():
        mat[int(row['Row']), int(row['Col'])] = row['Value']
    sns.heatmap(mat, cbar=False, cmap='binary', square=True)
    plt.axis('off')
    plt.title(f'Pattern {p}')
plt.tight_layout()
plt.savefig(f"{prefix}patterns.png")
plt.close()

# Plot 3: Pattern Usage Frequency
usage = reconstructed_data['BestPattern'].value_counts().sort_index()
plt.figure()
plt.bar(usage.index, usage.values)
plt.title('Pattern Usage Frequency')
plt.xlabel('Pattern Index')
plt.ylabel('Count')
plt.savefig(f"{prefix}pattern_usage.png")
plt.close()

# Plot 4: Per Image Usage Distribution
plt.figure(figsize=(12, 8))
for img in range(5):
    plt.subplot(2, 3, img + 1)
    subset = reconstructed_data[reconstructed_data['Image'] == img]
    usage = subset['BestPattern'].value_counts().sort_index()
    counts = [usage.get(i, 0) for i in range(7)]
    plt.bar(range(7), counts)
    plt.title(f'Image {img}')
    plt.xlabel('Pattern Index')
    plt.ylabel('Count')
plt.tight_layout()
plt.savefig(f"{prefix}pattern_usage_by_image.png")
plt.close()

# Plot 5: Original vs Reconstructed Images
for img in range(5):
    reconstructed = np.zeros((24, 24))
    original = np.zeros((24, 24))
    subset = reconstructed_data[reconstructed_data['Image'] == img]
    image_matrix = []
    with open("images.txt") as f:
        lines = f.readlines()[img * 24:(img + 1) * 24]
        for line in lines:
            image_matrix.append([int(ch) for ch in line.strip()])
    original = np.array(image_matrix)

    for _, row in subset.iterrows():
        pattern_id = int(row['BestPattern'])
        block_row = int(row['BlockRow'])
        block_col = int(row['BlockCol'])
        pattern = patterns_data[patterns_data['Pattern'] == pattern_id].copy()
        for _, p_row in pattern.iterrows():
            r = int(p_row['Row'])
            c = int(p_row['Col'])
            val = int(p_row['Value'])
            reconstructed[block_row * 3 + r, block_col * 3 + c] = val

    fig, axs = plt.subplots(1, 2, figsize=(10, 5))
    axs[0].imshow(original, cmap='gray')
    axs[0].set_title('Original Image')
    axs[0].axis('off')
    axs[1].imshow(reconstructed, cmap='gray')
    axs[1].set_title('Reconstructed Image')
    axs[1].axis('off')
    plt.tight_layout()
    plt.savefig(f"{prefix}original_vs_reconstructed_{img}.png")
    plt.close()

# Confusion Matrix - Placeholder: using predicted as ground truth for now
y_true = reconstructed_data['BestPattern']
y_pred = reconstructed_data['BestPattern']
cm = confusion_matrix(y_true, y_pred, labels=range(7))
disp = ConfusionMatrixDisplay(confusion_matrix=cm, display_labels=[f"P{i}" for i in range(7)])
disp.plot(cmap='Blues')
plt.title('Confusion Matrix (Pred = GT placeholder)')
plt.savefig(f"{prefix}confusion_matrix.png")
plt.close()

print(f"[✓] Visualizations saved with prefix '{prefix}'")