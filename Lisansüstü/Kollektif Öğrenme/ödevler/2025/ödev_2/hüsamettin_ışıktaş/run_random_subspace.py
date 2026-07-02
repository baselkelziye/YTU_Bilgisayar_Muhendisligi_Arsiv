"""
Random Subspace Model Eğitim ve Değerlendirme Scripti

Bu script:
1. 3 farklı embedding verisetini yükler (başlık, özet, birleştirilmiş)
2. Her veriseti için Random Subspace modeli eğitir
3. Test setinde performans değerlendirmesi yapar
4. Sonuçları ve grafikleri artifacts/ klasörüne kaydeder

Not: Random Subspace, Bagging'in max_features < 1.0 ve bootstrap=False versiyonudur.
"""

import argparse
import os
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.ensemble import BaggingClassifier
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import (
    accuracy_score, classification_report, confusion_matrix,
    f1_score, precision_score, recall_score
)
from datetime import datetime
import json
import joblib

plt.rcParams['font.family'] = 'DejaVu Sans'

# Sabit parametreler - Random Subspace için özellik alt kümesi seçimi
RANDOM_SEED = 42
MODEL_NAME = "Random Subspace"
# Optimizasyon sonuçlarına göre embed boyutuna özel parametreler
PARAMS_BY_EMBED_SIZE = {
    128: {
        'title': {'n_estimators': 200, 'max_features': 0.7},
        'abstract': {'n_estimators': 200, 'max_features': 0.7},
        'concat': {'n_estimators': 200, 'max_features': 0.5},  # optimizing.txt verisine göre varsayılan
    },
    256: {
        'title': {'n_estimators': 50, 'max_features': 0.7},
        'abstract': {'n_estimators': 200, 'max_features': 0.7},
        'concat': {'n_estimators': 100, 'max_features': 0.5},
    },
    1024: {
        'title': {'n_estimators': 100, 'max_features': 0.7},
        'abstract': {'n_estimators': 200, 'max_features': 0.3},
        'concat': {'n_estimators': 200, 'max_features': 0.5},
    },
}
MAX_SAMPLES = 1.0       # Tüm örnekleri kullan
BOOTSTRAP = False       # Örnekleme yapma (sadece özellik seçimi)
BOOTSTRAP_FEATURES = True  # Özellik alt kümesi seçimi
N_JOBS = 11

# Decision Tree parametreleri (ağaç derinliğini sınırlamak için - performans için kritik!)
# Optimizasyon sırasında max_depth=20 kullanıldı
MAX_DEPTH = 20          # Maksimum ağaç derinliği
MIN_SAMPLES_SPLIT = 2   # Bir node'u split etmek için minimum örnek sayısı
MIN_SAMPLES_LEAF = 1    # Bir leaf node'da minimum örnek sayısı

DATASET_DIR = "dataset"
ARTIFACTS_DIR = "artifacts"

DATASET_PALETTE = {
    'title': '#7b1fa2',
    'abstract': '#1f3b73',
    'concat': '#ff7043'
}


def parse_args():
    """Komut satırı argümanlarını okur."""
    parser = argparse.ArgumentParser(
        description="Random Subspace ile tez yılı tahmini (hazır embedding setleriyle)."
    )
    parser.add_argument(
        "--dataset",
        default=DATASET_DIR,
        help="`train_*.npz` ve `test_*.npz` dosyalarının bulunduğu dizin (varsayılan: dataset).",
    )
    parser.add_argument(
        "--embed-size",
        type=int,
        default=256,
        choices=sorted(PARAMS_BY_EMBED_SIZE.keys()),
        help="Optimize parametrelerin kullanılacağı embed boyutu.",
    )
    return parser.parse_args()


def load_embedding_data(embed_type, dataset_dir):
    train_file = os.path.join(dataset_dir, f"train_{embed_type}_embeddings.npz")
    test_file = os.path.join(dataset_dir, f"test_{embed_type}_embeddings.npz")
    train_data = np.load(train_file)
    test_data = np.load(test_file)
    return (train_data['embeddings'], train_data['years'],
            test_data['embeddings'], test_data['years'])


def train_model(X_train, y_train, embed_type, embed_size):
    """Random Subspace modeli eğitir (özellik alt kümesi yöntemi)."""
    # Embed boyutuna özel parametreleri al
    try:
        params = PARAMS_BY_EMBED_SIZE[embed_size][embed_type]
    except KeyError:
        raise ValueError(f"{embed_size} için {embed_type} parametresi tanımlı değil.")
    
    # ÖNEMLİ: max_depth parametresi olmadan ağaçlar çok derin olur ve eğitim çok uzun sürer!
    base_estimator = DecisionTreeClassifier(
        max_depth=MAX_DEPTH,
        min_samples_split=MIN_SAMPLES_SPLIT,
        min_samples_leaf=MIN_SAMPLES_LEAF,
        random_state=RANDOM_SEED
    )
    
    model = BaggingClassifier(
        estimator=base_estimator,
        n_estimators=params['n_estimators'],
        max_samples=MAX_SAMPLES,
        max_features=params['max_features'],
        bootstrap=BOOTSTRAP,
        bootstrap_features=BOOTSTRAP_FEATURES,
        random_state=RANDOM_SEED,
        n_jobs=N_JOBS,
        verbose=1
    )
    model.fit(X_train, y_train)
    return model


def evaluate_model(model, X_test, y_test):
    y_pred = model.predict(X_test)
    errors = y_pred - y_test
    abs_errors = np.abs(errors)
    return {
        'accuracy': accuracy_score(y_test, y_pred),
        'f1_macro': f1_score(y_test, y_pred, average='macro'),
        'f1_weighted': f1_score(y_test, y_pred, average='weighted'),
        'precision_macro': precision_score(y_test, y_pred, average='macro'),
        'recall_macro': recall_score(y_test, y_pred, average='macro'),
        'mae': float(np.mean(abs_errors)),
        'rmse': float(np.sqrt(np.mean(errors**2))),
        'classification_report': classification_report(y_test, y_pred),
        'confusion_matrix': confusion_matrix(y_test, y_pred),
        'y_true': y_test,
        'y_pred': y_pred,
        'errors': errors,
        'abs_errors': abs_errors
    }


def plot_confusion_matrix(metrics, title, output_path):
    cm = metrics['confusion_matrix']
    labels = sorted(list(set(metrics['y_true'])))
    plt.figure(figsize=(16, 14))
    cm_normalized = cm.astype('float') / cm.sum(axis=1)[:, np.newaxis]
    sns.heatmap(cm_normalized, annot=False, fmt='.2f', cmap='Purples',
                xticklabels=labels, yticklabels=labels)
    plt.title(f'{title}\nNormalize Edilmiş Confusion Matrix', fontsize=14)
    plt.xlabel('Tahmin Edilen Yıl', fontsize=12)
    plt.ylabel('Gerçek Yıl', fontsize=12)
    plt.xticks(rotation=45, ha='right')
    plt.tight_layout()
    plt.savefig(output_path, dpi=150, bbox_inches='tight')
    plt.close()


def plot_year_accuracy(metrics, title, output_path):
    y_true, y_pred = metrics['y_true'], metrics['y_pred']
    years = sorted(list(set(y_true)))
    accuracies = [accuracy_score(y_true[y_true == y], y_pred[y_true == y]) 
                  if (y_true == y).sum() > 0 else 0 for y in years]
    
    plt.figure(figsize=(14, 6))
    plt.bar(years, accuracies, color='mediumpurple', edgecolor='indigo')
    avg_acc = np.mean(accuracies)
    plt.axhline(y=avg_acc, color='red', linestyle='--', label=f'Ortalama: {avg_acc:.3f}')
    plt.title(f'{title}\nYıllara Göre Doğruluk', fontsize=14)
    plt.xlabel('Yıl', fontsize=12)
    plt.ylabel('Doğruluk', fontsize=12)
    plt.xticks(years, rotation=45, ha='right')
    plt.ylim(0, 1)
    plt.legend()
    plt.grid(axis='y', alpha=0.3)
    plt.tight_layout()
    plt.savefig(output_path, dpi=150, bbox_inches='tight')
    plt.close()


def plot_prediction_distribution(metrics, title, output_path):
    y_true, y_pred = metrics['y_true'], metrics['y_pred']
    errors = y_pred - y_true
    
    fig, axes = plt.subplots(1, 2, figsize=(14, 5))
    axes[0].hist(errors, bins=50, color='mediumpurple', edgecolor='indigo', alpha=0.7)
    axes[0].axvline(x=0, color='red', linestyle='--', linewidth=2)
    axes[0].set_title('Tahmin Hatası Dağılımı', fontsize=12)
    axes[0].set_xlabel('Hata (Tahmin - Gerçek)', fontsize=10)
    axes[0].set_ylabel('Frekans', fontsize=10)
    mae, rmse = np.mean(np.abs(errors)), np.sqrt(np.mean(errors**2))
    axes[0].text(0.95, 0.95, f'MAE: {mae:.2f}\nRMSE: {rmse:.2f}', 
                 transform=axes[0].transAxes, fontsize=10, va='top', ha='right',
                 bbox=dict(boxstyle='round', facecolor='wheat', alpha=0.5))
    
    axes[1].scatter(y_true, y_pred, alpha=0.3, s=10, c='mediumpurple')
    axes[1].plot([y_true.min(), y_true.max()], [y_true.min(), y_true.max()], 
                 'r--', linewidth=2, label='İdeal')
    axes[1].set_title('Gerçek vs Tahmin', fontsize=12)
    axes[1].set_xlabel('Gerçek Yıl', fontsize=10)
    axes[1].set_ylabel('Tahmin Edilen Yıl', fontsize=10)
    axes[1].legend()
    plt.suptitle(title, fontsize=14, y=1.02)
    plt.tight_layout()
    plt.savefig(output_path, dpi=150, bbox_inches='tight')
    plt.close()


def get_top_confusions(metrics, top_n=8):
    """En sık karıştırılan yıl çiftlerini döndürür."""
    cm = metrics['confusion_matrix'].astype(float)
    labels = sorted(list(set(metrics['y_true'])))
    mis_cm = cm.copy()
    np.fill_diagonal(mis_cm, 0)
    
    flat_indices = np.argsort(mis_cm, axis=None)[::-1]
    top_pairs = []
    for idx in flat_indices:
        if len(top_pairs) >= top_n:
            break
        i, j = divmod(idx, mis_cm.shape[1])
        count = mis_cm[i, j]
        if count <= 0:
            break
        top_pairs.append({
            'actual': labels[i],
            'predicted': labels[j],
            'count': int(cm[i, j])
        })
    return top_pairs


def plot_error_summary(metrics, title, output_path, color):
    """Hata dağılımına dair daha detaylı görselleştirme üretir."""
    y_true = metrics['y_true']
    errors = metrics['errors']
    abs_errors = metrics['abs_errors']
    years = sorted(list(set(y_true)))
    
    year_mae = []
    for year in years:
        mask = y_true == year
        year_mae.append(np.mean(np.abs(errors[mask])) if mask.sum() > 0 else 0)
    
    sorted_abs = np.sort(abs_errors)
    cum_ratio = np.linspace(0, 1, len(sorted_abs))
    top_confusions = get_top_confusions(metrics, top_n=6)
    
    fig, axes = plt.subplots(2, 2, figsize=(15, 10))
    
    axes[0, 0].plot(years, year_mae, color=color, marker='o')
    axes[0, 0].fill_between(years, year_mae, color=color, alpha=0.15)
    axes[0, 0].set_title('Yıllara Göre Ortalama Mutlak Hata (MAE)')
    axes[0, 0].set_xlabel('Yıl')
    axes[0, 0].set_ylabel('MAE')
    axes[0, 0].set_xticks(years[::2])
    axes[0, 0].grid(alpha=0.3)
    
    bins = np.arange(0, max(10, int(abs_errors.max()) + 2))
    axes[0, 1].hist(abs_errors, bins=bins, color=color, edgecolor='black', alpha=0.75)
    axes[0, 1].set_title('Mutlak Hata Dağılımı')
    axes[0, 1].set_xlabel('|Tahmin - Gerçek|')
    axes[0, 1].set_ylabel('Frekans')
    axes[0, 1].grid(axis='y', alpha=0.3)
    
    axes[1, 0].plot(sorted_abs, cum_ratio, color=color, linewidth=2)
    axes[1, 0].set_title('Kümülatif Mutlak Hata Eğrisi')
    axes[1, 0].set_xlabel('|Hata|')
    axes[1, 0].set_ylabel('Kümülatif Oran')
    axes[1, 0].grid(alpha=0.3)
    
    if top_confusions:
        pairs = [f"{item['actual']} → {item['predicted']}" for item in top_confusions]
        counts = [item['count'] for item in top_confusions]
        axes[1, 1].barh(pairs[::-1], counts[::-1], color=color, alpha=0.85)
        axes[1, 1].set_title('En Çok Karıştırılan Yıl Çiftleri')
        axes[1, 1].set_xlabel('Adet')
        axes[1, 1].grid(axis='x', alpha=0.2)
    else:
        axes[1, 1].text(0.5, 0.5, "Önemli karışıklık yok", ha='center', va='center')
        axes[1, 1].set_axis_off()
    
    plt.suptitle(title, fontsize=14, y=0.98)
    plt.tight_layout()
    plt.savefig(output_path, dpi=150, bbox_inches='tight')
    plt.close()


def plot_dataset_error_overview(all_results, output_dir, embed_names):
    """Veri setleri arasında hata profili karşılaştırması yapar."""
    datasets = list(all_results.keys())
    mae_values = [all_results[ds]['metrics']['mae'] for ds in datasets]
    abs_error_lists = [all_results[ds]['metrics']['abs_errors'] for ds in datasets]
    
    fig, axes = plt.subplots(1, 2, figsize=(14, 6))
    colors = [DATASET_PALETTE[ds] for ds in datasets]
    
    axes[0].bar(
        [embed_names[ds] for ds in datasets],
        mae_values,
        color=colors,
        edgecolor='black',
        alpha=0.85
    )
    axes[0].set_title('Verisetlerine Göre MAE')
    axes[0].set_ylabel('MAE')
    axes[0].grid(axis='y', alpha=0.3)
    
    parts = axes[1].violinplot(abs_error_lists, showmeans=True, showmedians=True)
    for idx, body in enumerate(parts['bodies']):
        body.set_facecolor(colors[idx])
        body.set_edgecolor('black')
        body.set_alpha(0.6)
    axes[1].set_xticks(np.arange(1, len(datasets)+1))
    axes[1].set_xticklabels([embed_names[ds] for ds in datasets])
    axes[1].set_title('Mutlak Hata Dağılımı (Violin)')
    axes[1].set_ylabel('|Tahmin - Gerçek|')
    axes[1].grid(axis='y', alpha=0.3)
    
    plt.suptitle('Verisetleri Hata Özeti', fontsize=14, y=0.98)
    plt.tight_layout()
    plt.savefig(os.path.join(output_dir, "dataset_error_overview.png"), dpi=150, bbox_inches='tight')
    plt.close()

def save_results(all_results, output_dir, embed_size, dataset_dir, timestamp):
    resolved_dataset_dir = os.path.abspath(dataset_dir)
    summary = {
        "_meta": {
            "model": MODEL_NAME,
            "embed_size": embed_size,
            "dataset_dir": resolved_dataset_dir,
            "output_dir": os.path.abspath(output_dir),
            "timestamp": timestamp,
        }
    }
    summary.update({
        et: {
            'accuracy': r['metrics']['accuracy'],
            'f1_macro': r['metrics']['f1_macro'],
            'f1_weighted': r['metrics']['f1_weighted'],
            'precision_macro': r['metrics']['precision_macro'],
            'recall_macro': r['metrics']['recall_macro'],
            'mae': r['metrics']['mae'],
            'rmse': r['metrics']['rmse']
        }
        for et, r in all_results.items()
    })
    
    with open(os.path.join(output_dir, "metrics_summary.json"), "w") as f:
        json.dump(summary, f, indent=2)
    
    report = f"""# Random Subspace Sonuçları

## Deney Bilgileri
| Bilgi | Değer |
|-------|-------|
| dataset_dir | {resolved_dataset_dir} |
| embed_size | {embed_size} |
| output_dir | {os.path.abspath(output_dir)} |
| timestamp | {timestamp} |

## Model Parametreleri
| Parametre | Değer |
|-----------|-------|
| n_estimators | Veri setine göre değişir (title: 50, abstract: 200, concat: 100) |
| max_samples | {MAX_SAMPLES} |
| max_features | Veri setine göre değişir (title: 0.7, abstract: 0.7, concat: 0.5) |
| bootstrap | {BOOTSTRAP} |
| bootstrap_features | {BOOTSTRAP_FEATURES} |
| base_estimator | DecisionTreeClassifier |
| max_depth | {MAX_DEPTH} |
| min_samples_split | {MIN_SAMPLES_SPLIT} |
| min_samples_leaf | {MIN_SAMPLES_LEAF} |
| random_state | {RANDOM_SEED} |

## Performans Karşılaştırması
| Veriseti | Accuracy | F1 (Macro) | F1 (Weighted) | Precision | Recall | MAE | RMSE |
|----------|----------|------------|---------------|-----------|--------|-----|------|
"""
    for et in all_results.keys():
        m = summary[et]
        report += (
            f"| {et} | {m['accuracy']:.4f} | {m['f1_macro']:.4f} | {m['f1_weighted']:.4f} | "
            f"{m['precision_macro']:.4f} | {m['recall_macro']:.4f} | {m['mae']:.2f} | {m['rmse']:.2f} |\n"
        )
    
    for et, r in all_results.items():
        report += f"\n## {et.capitalize()} Detaylı Rapor\n```\n{r['metrics']['classification_report']}\n```\n"
    
    with open(os.path.join(output_dir, "results_report.md"), "w", encoding="utf-8") as f:
        f.write(report)


def plot_comparison(all_results, output_dir):
    embed_types = list(all_results.keys())
    metrics_names = ['accuracy', 'f1_macro', 'f1_weighted', 'precision_macro', 'recall_macro']
    metrics_labels = ['Accuracy', 'F1 (Macro)', 'F1 (Weighted)', 'Precision', 'Recall']
    colors = ['#2ecc71', '#3498db', '#9b59b6', '#e74c3c', '#f39c12']
    
    x = np.arange(len(embed_types))
    width = 0.15
    fig, ax = plt.subplots(figsize=(12, 6))
    
    for i, (mn, ml, c) in enumerate(zip(metrics_names, metrics_labels, colors)):
        values = [all_results[et]['metrics'][mn] for et in embed_types]
        bars = ax.bar(x + i * width, values, width, label=ml, color=c)
        for bar, val in zip(bars, values):
            ax.text(bar.get_x() + bar.get_width()/2, bar.get_height() + 0.01,
                   f'{val:.3f}', ha='center', va='bottom', fontsize=8, rotation=90)
    
    ax.set_xlabel('Veriseti', fontsize=12)
    ax.set_ylabel('Skor', fontsize=12)
    ax.set_title('Random Subspace - Veriseti Karşılaştırması', fontsize=14)
    ax.set_xticks(x + width * 2)
    ax.set_xticklabels(['Başlık', 'Özet', 'Birleştirilmiş'])
    ax.legend(loc='upper left', bbox_to_anchor=(1, 1))
    ax.set_ylim(0, 1.15)
    ax.grid(axis='y', alpha=0.3)
    plt.tight_layout()
    plt.savefig(os.path.join(output_dir, "comparison.png"), dpi=150, bbox_inches='tight')
    plt.close()


def main():
    print("=" * 60)
    print("RANDOM SUBSPACE MODEL EĞİTİMİ VE DEĞERLENDİRMESİ")
    print("=" * 60)
    
    args = parse_args()
    dataset_dir = args.dataset
    embed_size = args.embed_size
    print(f"Kullanılan veri dizini: {dataset_dir}")
    print(f"Embed boyutu: {embed_size}")

    timestamp = datetime.now().strftime("%Y-%m-%d_%H%M%S")
    output_dir = os.path.join(ARTIFACTS_DIR, f"{timestamp}_random_subspace")
    os.makedirs(output_dir, exist_ok=True)
    print(f"\nÇıktı dizini: {output_dir}")
    
    embed_types = ['title', 'abstract', 'concat']
    embed_names = {'title': 'Başlık', 'abstract': 'Özet', 'concat': 'Birleştirilmiş'}
    all_results = {}
    
    for embed_type in embed_types:
        print(f"\n{'='*60}\n{embed_names[embed_type].upper()} VERİSETİ\n{'='*60}")
        
        print("\n1. Veri yükleniyor...")
        X_train, y_train, X_test, y_test = load_embedding_data(embed_type, dataset_dir)
        print(f"   Train: {X_train.shape}, Test: {X_test.shape}")
        
        print("\n2. Model eğitiliyor...")
        model = train_model(X_train, y_train, embed_type, embed_size)
        
        print("\n3. Model değerlendiriliyor...")
        metrics = evaluate_model(model, X_test, y_test)
        print(f"   Accuracy: {metrics['accuracy']:.4f}, F1 (Macro): {metrics['f1_macro']:.4f}")
        
        print("\n4. Grafikler oluşturuluyor...")
        plot_confusion_matrix(metrics, f"Random Subspace - {embed_names[embed_type]}",
                              os.path.join(output_dir, f"{embed_type}_confusion_matrix.png"))
        plot_year_accuracy(metrics, f"Random Subspace - {embed_names[embed_type]}",
                           os.path.join(output_dir, f"{embed_type}_year_accuracy.png"))
        plot_prediction_distribution(metrics, f"Random Subspace - {embed_names[embed_type]}",
                                     os.path.join(output_dir, f"{embed_type}_prediction_dist.png"))
        plot_error_summary(
            metrics,
            f"Random Subspace - {embed_names[embed_type]} Detaylı Hata Profili",
            os.path.join(output_dir, f"{embed_type}_error_summary.png"),
            DATASET_PALETTE[embed_type]
        )
        
        model_path = os.path.join(output_dir, f"{embed_type}_model.joblib")
        joblib.dump(model, model_path)
        print(f"   Model kaydedildi: {model_path}")
        
        all_results[embed_type] = {'metrics': metrics, 'model_path': model_path}
    
    print(f"\n{'='*60}\nSONUÇLAR KAYDEDİLİYOR\n{'='*60}")
    save_results(all_results, output_dir, embed_size, dataset_dir, timestamp)
    plot_comparison(all_results, output_dir)
    plot_dataset_error_overview(all_results, output_dir, embed_names)
    print(f"\n✓ Tüm sonuçlar kaydedildi: {output_dir}/")
    
    print("\n" + "=" * 60 + "\nÖZET\n" + "=" * 60)
    print("\n{:<15} {:>10} {:>10} {:>10} {:>8}".format(
        "Veriseti", "Accuracy", "F1-Macro", "F1-Weight", "MAE"
    ))
    print("-" * 60)
    for et in embed_types:
        m = all_results[et]['metrics']
        print(f"{embed_names[et]:<15} {m['accuracy']:>10.4f} {m['f1_macro']:>10.4f} "
              f"{m['f1_weighted']:>10.4f} {m['mae']:>8.2f}")


if __name__ == "__main__":
    main()

