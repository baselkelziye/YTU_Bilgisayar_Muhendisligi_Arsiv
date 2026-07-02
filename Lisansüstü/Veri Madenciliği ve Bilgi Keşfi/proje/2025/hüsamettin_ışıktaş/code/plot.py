"""
Grafik görselleştirme fonksiyonları
"""
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd
import os
import math

# Makale sonuçları (Rastogi & Bansal, 2023 - Table 4)
PAPER_RESULTS = {
    "Logistic Regression": {"Accuracy": 82.46, "Sensitivity (Recall)": 68.23},
    "Random Forest": {"Accuracy": 81.81, "Sensitivity (Recall)": 68.88},
    "Naïve Bayes": {"Accuracy": 79.22, "Sensitivity (Recall)": 64.44},
    "SVM": {"Accuracy": 79.22, "Sensitivity (Recall)": 59.99}
}


def _parse_value(value):
    """String değeri parse eder: '74.73% ± 4.76%' -> (74.73, 4.76)"""
    if isinstance(value, str):
        if '±' in value:
            parts = value.split('±')
            mean = float(parts[0].replace('%', '').strip())
            std = float(parts[1].replace('%', '').strip())
            return mean, std
        else:
            mean = float(value.replace('%', '').strip())
            return mean, 0.0
    else:
        return float(value), 0.0


def plot_confusion_matrices(confusion_matrices, output_dir="plots"):
    """
    Tüm modellerin confusion matrix'lerini tek bir figürde gösterir
    
    Args:
        confusion_matrices: Model isimlerini confusion matrix'lere map eden dictionary
        output_dir: Grafiklerin kaydedileceği klasör
    """
    print("\n📊 Confusion Matrix'ler çiziliyor...")
    
    num_models = len(confusion_matrices)
    cols = 3
    rows = math.ceil(num_models / cols)
    
    plt.figure(figsize=(15, 5 * rows))
    
    for i, (name, cm) in enumerate(confusion_matrices.items(), 1):
        plt.subplot(rows, cols, i)
        sns.heatmap(cm, annot=True, fmt='d', cmap='Blues', cbar=False, annot_kws={"size": 14})
        plt.title(name, fontsize=12)
        plt.ylabel('Gerçek')
        plt.xlabel('Tahmin')
    
    plt.tight_layout()
    plt.savefig(os.path.join(output_dir, "all_confusion_matrices.png"))
    plt.close()


def plot_all_models_comparison(results_data, output_dir="plots"):
    """
    Tüm modellerin tüm metriklerini karşılaştıran grafik çizer (Error bar'larla)
    
    Args:
        results_data: Model performans verilerini içeren dictionary listesi
        output_dir: Grafiklerin kaydedileceği klasör
    """
    print("\n📊 Karşılaştırma grafiği çiziliyor...")
    
    # Verileri parse et ve DataFrame'e çevir
    parsed_data = []
    for row in results_data:
        model_name = row["Model"]
        acc_mean, acc_std = _parse_value(row["Accuracy"])
        recall_mean, recall_std = _parse_value(row["Sensitivity (Recall)"])
        precision_mean, precision_std = _parse_value(row["Precision"])
        f1_mean, f1_std = _parse_value(row["F1-Score"])
        
        parsed_data.append({
            "Model": model_name,
            "Metric": "Accuracy",
            "Mean": acc_mean,
            "Std": acc_std
        })
        parsed_data.append({
            "Model": model_name,
            "Metric": "Recall",
            "Mean": recall_mean,
            "Std": recall_std
        })
        parsed_data.append({
            "Model": model_name,
            "Metric": "Precision",
            "Mean": precision_mean,
            "Std": precision_std
        })
        parsed_data.append({
            "Model": model_name,
            "Metric": "F1-Score",
            "Mean": f1_mean,
            "Std": f1_std
        })
    
    df = pd.DataFrame(parsed_data)
    
    # Modern görselleştirme: 2x2 subplot layout
    fig, axes = plt.subplots(2, 2, figsize=(16, 12))
    fig.suptitle('Tüm Modellerin Performans Karşılaştırması (5-Fold Cross Validation)', 
                 fontsize=16, fontweight='bold', y=0.995)
    
    metrics = ["Accuracy", "Recall", "Precision", "F1-Score"]
    colors = ['#2E86AB', '#A23B72', '#F18F01', '#C73E1D']
    
    for idx, metric in enumerate(metrics):
        ax = axes[idx // 2, idx % 2]
        metric_data = df[df["Metric"] == metric]
        
        models = metric_data["Model"].unique()
        x_pos = np.arange(len(models))
        means = [metric_data[metric_data["Model"] == m]["Mean"].values[0] for m in models]
        stds = [metric_data[metric_data["Model"] == m]["Std"].values[0] for m in models]
        
        # Bar plot with error bars
        bars = ax.bar(x_pos, means, yerr=stds, capsize=5, 
                     color=colors[idx], alpha=0.8, edgecolor='black', linewidth=1.5)
        
        # Değerleri çubukların üzerine yaz
        for i, (bar, mean, std) in enumerate(zip(bars, means, stds)):
            height = bar.get_height()
            ax.text(bar.get_x() + bar.get_width()/2., height + std + 1,
                   f'{mean:.2f}%\n±{std:.2f}%',
                   ha='center', va='bottom', fontsize=9, fontweight='bold')
        
        ax.set_xlabel('Model', fontsize=11, fontweight='bold')
        ax.set_ylabel(f'{metric} (%)', fontsize=11, fontweight='bold')
        ax.set_title(f'{metric} Karşılaştırması', fontsize=12, fontweight='bold', pad=10)
        ax.set_xticks(x_pos)
        ax.set_xticklabels(models, rotation=15, ha='right', fontsize=10)
        ax.set_ylim(0, max(means) + max(stds) + 15)
        ax.grid(axis='y', alpha=0.3, linestyle='--', linewidth=0.5)
        ax.set_axisbelow(True)
        
        # En iyi modeli vurgula
        best_idx = np.argmax(means)
        bars[best_idx].set_edgecolor('gold')
        bars[best_idx].set_linewidth(3)
    
    plt.tight_layout(rect=[0, 0, 1, 0.99])
    plt.savefig(os.path.join(output_dir, "all_models_comparison.png"), dpi=300, bbox_inches='tight')
    plt.close()
    
    # Ayrıca tek bir grafikte tüm metrikleri gösteren alternatif görselleştirme
    fig, ax = plt.subplots(figsize=(14, 8))
    
    models = df["Model"].unique()
    x = np.arange(len(models))
    width = 0.2  # Her metrik için bar genişliği
    
    for i, metric in enumerate(metrics):
        metric_data = df[df["Metric"] == metric]
        means = [metric_data[metric_data["Model"] == m]["Mean"].values[0] for m in models]
        stds = [metric_data[metric_data["Model"] == m]["Std"].values[0] for m in models]
        
        offset = (i - 1.5) * width
        bars = ax.bar(x + offset, means, width, yerr=stds, capsize=3,
                     label=metric, color=colors[i], alpha=0.8, edgecolor='black', linewidth=1)
        
        # Değerleri yaz (sadece üst değerleri)
        for bar, mean in zip(bars, means):
            height = bar.get_height()
            if height > 5:  # Sadece görünür olanları yaz
                ax.text(bar.get_x() + bar.get_width()/2., height,
                       f'{mean:.1f}%',
                       ha='center', va='bottom', fontsize=8, fontweight='bold')
    
    ax.set_xlabel('Model', fontsize=12, fontweight='bold')
    ax.set_ylabel('Skor (%)', fontsize=12, fontweight='bold')
    ax.set_title('Tüm Modellerin Performans Karşılaştırması (5-Fold CV)', 
                fontsize=14, fontweight='bold', pad=15)
    ax.set_xticks(x)
    ax.set_xticklabels(models, rotation=15, ha='right', fontsize=10)
    ax.set_ylim(0, 100)
    ax.legend(loc='upper left', fontsize=10, framealpha=0.9)
    ax.grid(axis='y', alpha=0.3, linestyle='--', linewidth=0.5)
    ax.set_axisbelow(True)
    
    plt.tight_layout()
    plt.savefig(os.path.join(output_dir, "all_models_comparison_grouped.png"), dpi=300, bbox_inches='tight')
    plt.close()


def plot_paper_comparison(results_data, output_dir="plots"):
    """
    Makale sonuçları ile bizim sonuçlarımızı karşılaştıran grafik çizer (Error bar'larla)
    
    Args:
        results_data: Model performans verilerini içeren dictionary listesi
        output_dir: Grafiklerin kaydedileceği klasör
    """
    print("\n📊 Makale ile karşılaştırma grafiği çiziliyor...")
    
    # Bizim sonuçlarımızı parse et
    our_parsed_data = []
    for row in results_data:
        model_name = row["Model"]
        acc_mean, acc_std = _parse_value(row["Accuracy"])
        recall_mean, recall_std = _parse_value(row["Sensitivity (Recall)"])
        
        our_parsed_data.append({
            "Model": model_name,
            "Accuracy": acc_mean,
            "Accuracy_Std": acc_std,
            "Sensitivity (Recall)": recall_mean,
            "Recall_Std": recall_std
        })
    
    df_our_results = pd.DataFrame(our_parsed_data)
    
    # Karşılaştırma için sadece makalede bulunan modelleri al (MLP makalede yok)
    models_in_paper = ["Logistic Regression", "Random Forest", "Naïve Bayes", "SVM"]
    df_our_filtered = df_our_results[df_our_results["Model"].isin(models_in_paper)].copy()
    
    # Makale verilerini DataFrame'e çevir
    paper_data = []
    for model_name in models_in_paper:
        if model_name in PAPER_RESULTS:
            paper_data.append({
                "Model": model_name,
                "Accuracy": PAPER_RESULTS[model_name]["Accuracy"],
                "Sensitivity (Recall)": PAPER_RESULTS[model_name]["Sensitivity (Recall)"]
            })
    
    df_paper = pd.DataFrame(paper_data)
    
    # Model sıralamasını makale sırasına göre ayarla
    model_order = models_in_paper
    df_our_filtered["Model"] = pd.Categorical(df_our_filtered["Model"], categories=model_order, ordered=True)
    df_our_filtered = df_our_filtered.sort_values("Model")
    df_paper["Model"] = pd.Categorical(df_paper["Model"], categories=model_order, ordered=True)
    df_paper = df_paper.sort_values("Model")
    
    # İki subplot: Accuracy ve Sensitivity için
    fig, axes = plt.subplots(1, 2, figsize=(18, 7))
    
    # 1. Accuracy Karşılaştırması
    x = np.arange(len(model_order))
    width = 0.35
    
    acc_our = df_our_filtered["Accuracy"].values
    acc_our_std = df_our_filtered["Accuracy_Std"].values
    acc_paper = df_paper["Accuracy"].values
    
    bars1 = axes[0].bar(x - width/2, acc_our, width, yerr=acc_our_std, capsize=5,
                       label='Bizim Çalışma (5-Fold CV)', color='#2E86AB', alpha=0.8,
                       edgecolor='black', linewidth=1.5)
    bars2 = axes[0].bar(x + width/2, acc_paper, width,
                       label='Makale (Rastogi & Bansal, 2023)', color='#A23B72', alpha=0.8,
                       edgecolor='black', linewidth=1.5)
    
    axes[0].set_xlabel('Model', fontsize=12, fontweight='bold')
    axes[0].set_ylabel('Accuracy (%)', fontsize=12, fontweight='bold')
    axes[0].set_title('Accuracy Karşılaştırması', fontsize=13, fontweight='bold', pad=10)
    axes[0].set_xticks(x)
    axes[0].set_xticklabels(model_order, rotation=15, ha='right', fontsize=10)
    axes[0].set_ylim(0, max(max(acc_our) + max(acc_our_std), max(acc_paper)) + 10)
    axes[0].legend(fontsize=10, loc='upper left', framealpha=0.9)
    axes[0].grid(axis='y', alpha=0.3, linestyle='--', linewidth=0.5)
    axes[0].set_axisbelow(True)
    
    # Değerleri çubukların üzerine yaz
    for i, (bar, val) in enumerate(zip(bars1, acc_our)):
        height = bar.get_height()
        std_val = acc_our_std[i]
        axes[0].text(bar.get_x() + bar.get_width()/2., height + std_val + 1,
                    f'{val:.2f}%\n±{std_val:.2f}%' if std_val > 0 else f'{val:.2f}%',
                    ha='center', va='bottom', fontsize=9, fontweight='bold')
    
    for bar, val in zip(bars2, acc_paper):
        height = bar.get_height()
        axes[0].text(bar.get_x() + bar.get_width()/2., height + 1,
                    f'{val:.2f}%',
                    ha='center', va='bottom', fontsize=9, fontweight='bold')
    
    # 2. Sensitivity (Recall) Karşılaştırması
    sens_our = df_our_filtered["Sensitivity (Recall)"].values
    sens_our_std = df_our_filtered["Recall_Std"].values
    sens_paper = df_paper["Sensitivity (Recall)"].values
    
    bars3 = axes[1].bar(x - width/2, sens_our, width, yerr=sens_our_std, capsize=5,
                       label='Bizim Çalışma (5-Fold CV)', color='#2E86AB', alpha=0.8,
                       edgecolor='black', linewidth=1.5)
    bars4 = axes[1].bar(x + width/2, sens_paper, width,
                       label='Makale (Rastogi & Bansal, 2023)', color='#A23B72', alpha=0.8,
                       edgecolor='black', linewidth=1.5)
    
    axes[1].set_xlabel('Model', fontsize=12, fontweight='bold')
    axes[1].set_ylabel('Sensitivity/Recall (%)', fontsize=12, fontweight='bold')
    axes[1].set_title('Sensitivity (Recall) Karşılaştırması', fontsize=13, fontweight='bold', pad=10)
    axes[1].set_xticks(x)
    axes[1].set_xticklabels(model_order, rotation=15, ha='right', fontsize=10)
    axes[1].set_ylim(0, max(max(sens_our) + max(sens_our_std), max(sens_paper)) + 10)
    axes[1].legend(fontsize=10, loc='upper left', framealpha=0.9)
    axes[1].grid(axis='y', alpha=0.3, linestyle='--', linewidth=0.5)
    axes[1].set_axisbelow(True)
    
    # Değerleri çubukların üzerine yaz
    for i, (bar, val) in enumerate(zip(bars3, sens_our)):
        height = bar.get_height()
        std_val = sens_our_std[i]
        axes[1].text(bar.get_x() + bar.get_width()/2., height + std_val + 1,
                    f'{val:.2f}%\n±{std_val:.2f}%' if std_val > 0 else f'{val:.2f}%',
                    ha='center', va='bottom', fontsize=9, fontweight='bold')
    
    for bar, val in zip(bars4, sens_paper):
        height = bar.get_height()
        axes[1].text(bar.get_x() + bar.get_width()/2., height + 1,
                    f'{val:.2f}%',
                    ha='center', va='bottom', fontsize=9, fontweight='bold')
    
    plt.suptitle('Makale ile Performans Karşılaştırması (5-Fold Cross Validation)', 
                 fontsize=15, fontweight='bold', y=1.02)
    plt.tight_layout(rect=[0, 0, 1, 0.98])
    plt.savefig(os.path.join(output_dir, "paper_comparison.png"), dpi=300, bbox_inches='tight')
    plt.close()


def create_all_plots(results_data, confusion_matrices, output_dir="plots"):
    """
    Tüm grafikleri oluşturur
    
    Args:
        results_data: Model performans verilerini içeren dictionary listesi
        confusion_matrices: Model isimlerini confusion matrix'lere map eden dictionary
        output_dir: Grafiklerin kaydedileceği klasör
    """
    plot_confusion_matrices(confusion_matrices, output_dir)
    plot_all_models_comparison(results_data, output_dir)
    plot_paper_comparison(results_data, output_dir)
    
    print(f"\n🎉 Tüm grafikler '{output_dir}' klasörüne kaydedildi!")
