"""
Random Forest Model Eğitim ve Değerlendirme Scripti

Bu script:
1. 3 farklı embedding verisetini yükler (başlık, özet, birleştirilmiş)
2. Her veriseti için Random Forest modeli eğitir
3. Test setinde performans değerlendirmesi yapar
4. Sonuçları ve grafikleri artifacts/ klasörüne kaydeder
"""

import argparse
import os
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import (
    accuracy_score, 
    classification_report, 
    confusion_matrix,
    f1_score,
    precision_score,
    recall_score
)
from datetime import datetime
import json
import joblib

# Türkçe karakter desteği için
plt.rcParams['font.family'] = 'DejaVu Sans'

# Sabit parametreler
RANDOM_SEED = 42
MODEL_NAME = "Random Forest"
# Embed boyutuna göre optimize edilmiş hiperparametreler
PARAMS_BY_EMBED_SIZE = {
    128: {
        'title': {'n_estimators': 200, 'max_depth': 10},
        'abstract': {'n_estimators': 200, 'max_depth': 10},
        'concat': {'n_estimators': 200, 'max_depth': 30},
    },
    256: {
        'title': {'n_estimators': 200, 'max_depth': 30},
        'abstract': {'n_estimators': 200, 'max_depth': 20},
        'concat': {'n_estimators': 200, 'max_depth': 10},
    },
    1024: {
        'title': {'n_estimators': 100, 'max_depth': 20},
        'abstract': {'n_estimators': 200, 'max_depth': 30},
        'concat': {'n_estimators': 200, 'max_depth': 20},
    },
}
MIN_SAMPLES_SPLIT = 2
MIN_SAMPLES_LEAF = 1
N_JOBS = 11         # Tüm CPU çekirdeklerini kullan

# Dizinler
DATASET_DIR = "dataset"
ARTIFACTS_DIR = "artifacts"

# Görselleştirme renkleri
DATASET_PALETTE = {
    'title': '#1f77b4',
    'abstract': '#ff7f0e',
    'concat': '#2ca02c'
}


def parse_args():
    """Komut satırı argümanlarını okur."""
    parser = argparse.ArgumentParser(
        description="Random Forest ile tez yılı tahmini (hazır embedding setleriyle)."
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
        help="Optimize edilmiş hiperparametrelerin kullanılacağı embed boyutu.",
    )
    return parser.parse_args()


def load_embedding_data(embed_type, dataset_dir):
    """
    Embedding verisetini yükler.
    
    Args:
        embed_type: Embedding türü ('title', 'abstract', 'concat')
    
    Returns:
        tuple: (X_train, y_train, X_test, y_test)
    """
    train_file = os.path.join(dataset_dir, f"train_{embed_type}_embeddings.npz")
    test_file = os.path.join(dataset_dir, f"test_{embed_type}_embeddings.npz")
    
    train_data = np.load(train_file)
    test_data = np.load(test_file)
    
    return (
        train_data['embeddings'],
        train_data['years'],
        test_data['embeddings'],
        test_data['years']
    )


def train_model(X_train, y_train, embed_type, embed_size):
    """
    Random Forest modeli eğitir.
    
    Args:
        X_train: Eğitim özellikleri
        y_train: Eğitim etiketleri
        embed_type: Veri seti türü ('title', 'abstract', 'concat')
    
    Returns:
        RandomForestClassifier: Eğitilmiş model
    """
    # Embed boyutuna özel parametreleri al
    try:
        params = PARAMS_BY_EMBED_SIZE[embed_size][embed_type]
    except KeyError:
        raise ValueError(f"{embed_size} için {embed_type} parametresi tanımlı değil.")
    
    model = RandomForestClassifier(
        n_estimators=params['n_estimators'],
        max_depth=params['max_depth'],
        min_samples_split=MIN_SAMPLES_SPLIT,
        min_samples_leaf=MIN_SAMPLES_LEAF,
        random_state=RANDOM_SEED,
        n_jobs=N_JOBS,
        verbose=1
    )
    
    model.fit(X_train, y_train)
    return model


def evaluate_model(model, X_test, y_test):
    """
    Model performansını değerlendirir.
    
    Args:
        model: Eğitilmiş model
        X_test: Test özellikleri
        y_test: Test etiketleri
    
    Returns:
        dict: Performans metrikleri
    """
    y_pred = model.predict(X_test)
    errors = y_pred - y_test
    abs_errors = np.abs(errors)
    
    metrics = {
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
    
    return metrics


def plot_confusion_matrix(metrics, title, output_path):
    """
    Confusion matrix grafiği oluşturur.
    
    Args:
        metrics: Performans metrikleri
        title: Grafik başlığı
        output_path: Kayıt yolu
    """
    cm = metrics['confusion_matrix']
    labels = sorted(list(set(metrics['y_true'])))
    
    plt.figure(figsize=(16, 14))
    
    # Normalize edilmiş confusion matrix
    cm_normalized = cm.astype('float') / cm.sum(axis=1)[:, np.newaxis]
    
    sns.heatmap(
        cm_normalized, 
        annot=False,  # Çok fazla sınıf olduğu için annotation kapatıldı
        fmt='.2f',
        cmap='Blues',
        xticklabels=labels,
        yticklabels=labels
    )
    
    plt.title(f'{title}\nNormalize Edilmiş Confusion Matrix', fontsize=14)
    plt.xlabel('Tahmin Edilen Yıl', fontsize=12)
    plt.ylabel('Gerçek Yıl', fontsize=12)
    plt.xticks(rotation=45, ha='right')
    plt.yticks(rotation=0)
    plt.tight_layout()
    
    plt.savefig(output_path, dpi=150, bbox_inches='tight')
    plt.close()


def plot_year_accuracy(metrics, title, output_path):
    """
    Yıllara göre doğruluk grafiği oluşturur.
    
    Args:
        metrics: Performans metrikleri
        title: Grafik başlığı
        output_path: Kayıt yolu
    """
    y_true = metrics['y_true']
    y_pred = metrics['y_pred']
    
    years = sorted(list(set(y_true)))
    accuracies = []
    
    for year in years:
        mask = y_true == year
        if mask.sum() > 0:
            acc = accuracy_score(y_true[mask], y_pred[mask])
            accuracies.append(acc)
        else:
            accuracies.append(0)
    
    plt.figure(figsize=(14, 6))
    bars = plt.bar(years, accuracies, color='steelblue', edgecolor='navy')
    
    # Ortalama çizgisi
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
    """
    Tahmin dağılımı grafiği oluşturur.
    
    Args:
        metrics: Performans metrikleri
        title: Grafik başlığı
        output_path: Kayıt yolu
    """
    y_true = metrics['y_true']
    y_pred = metrics['y_pred']
    
    # Hata analizi
    errors = y_pred - y_true
    
    fig, axes = plt.subplots(1, 2, figsize=(14, 5))
    
    # Hata dağılımı
    axes[0].hist(errors, bins=50, color='steelblue', edgecolor='navy', alpha=0.7)
    axes[0].axvline(x=0, color='red', linestyle='--', linewidth=2)
    axes[0].set_title('Tahmin Hatası Dağılımı', fontsize=12)
    axes[0].set_xlabel('Hata (Tahmin - Gerçek)', fontsize=10)
    axes[0].set_ylabel('Frekans', fontsize=10)
    axes[0].grid(axis='y', alpha=0.3)
    
    # MAE ve RMSE
    mae = np.mean(np.abs(errors))
    rmse = np.sqrt(np.mean(errors**2))
    axes[0].text(0.95, 0.95, f'MAE: {mae:.2f}\nRMSE: {rmse:.2f}', 
                 transform=axes[0].transAxes, fontsize=10,
                 verticalalignment='top', horizontalalignment='right',
                 bbox=dict(boxstyle='round', facecolor='wheat', alpha=0.5))
    
    # Scatter plot: Gerçek vs Tahmin
    axes[1].scatter(y_true, y_pred, alpha=0.3, s=10, c='steelblue')
    axes[1].plot([y_true.min(), y_true.max()], [y_true.min(), y_true.max()], 
                 'r--', linewidth=2, label='İdeal')
    axes[1].set_title('Gerçek vs Tahmin', fontsize=12)
    axes[1].set_xlabel('Gerçek Yıl', fontsize=10)
    axes[1].set_ylabel('Tahmin Edilen Yıl', fontsize=10)
    axes[1].legend()
    axes[1].grid(alpha=0.3)
    
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
    """
    Hata profili, yıl bazlı MAE ve en fazla karıştırılan sınıfları gösteren detaylı grafik.
    """
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
    
    # Yıllara göre MAE
    axes[0, 0].plot(years, year_mae, color=color, marker='o')
    axes[0, 0].fill_between(years, year_mae, color=color, alpha=0.15)
    axes[0, 0].set_title('Yıllara Göre Ortalama Mutlak Hata (MAE)', fontsize=12)
    axes[0, 0].set_xlabel('Yıl')
    axes[0, 0].set_ylabel('MAE')
    axes[0, 0].set_xticks(years[::2])
    axes[0, 0].grid(alpha=0.3)
    
    # Mutlak hata dağılımı
    bins = np.arange(0, max(10, int(abs_errors.max()) + 2))
    axes[0, 1].hist(abs_errors, bins=bins, color=color, edgecolor='black', alpha=0.75)
    axes[0, 1].set_title('Mutlak Hata Dağılımı', fontsize=12)
    axes[0, 1].set_xlabel('|Tahmin - Gerçek|')
    axes[0, 1].set_ylabel('Frekans')
    axes[0, 1].grid(axis='y', alpha=0.3)
    
    # Kümülatif hata eğrisi
    axes[1, 0].plot(sorted_abs, cum_ratio, color=color, linewidth=2)
    axes[1, 0].set_title('Kümülatif Mutlak Hata Eğrisi', fontsize=12)
    axes[1, 0].set_xlabel('|Hata|')
    axes[1, 0].set_ylabel('Kümülatif Oran')
    axes[1, 0].grid(alpha=0.3)
    
    # En sık karıştırılan yıllar
    if top_confusions:
        pairs = [f"{item['actual']} → {item['predicted']}" for item in top_confusions]
        counts = [item['count'] for item in top_confusions]
        axes[1, 1].barh(pairs[::-1], counts[::-1], color=color, alpha=0.8)
        axes[1, 1].set_title('En Çok Karıştırılan Yıl Çiftleri', fontsize=12)
        axes[1, 1].set_xlabel('Adet')
        axes[1, 1].grid(axis='x', alpha=0.2)
    else:
        axes[1, 1].text(0.5, 0.5, "Önemli karışıklık yok", ha='center', va='center')
    
    plt.suptitle(title, fontsize=14, y=0.98)
    plt.tight_layout()
    plt.savefig(output_path, dpi=150, bbox_inches='tight')
    plt.close()


def plot_dataset_error_overview(all_results, output_dir, embed_names):
    """Tüm veri setleri için hata profillerini tek grafikte gösterir."""
    datasets = list(all_results.keys())
    mae_values = [all_results[ds]['metrics']['mae'] for ds in datasets]
    rmse_values = [all_results[ds]['metrics']['rmse'] for ds in datasets]
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
    axes[0].set_title('Verisetlerine Göre MAE', fontsize=12)
    axes[0].set_ylabel('MAE')
    axes[0].grid(axis='y', alpha=0.3)
    
    parts = axes[1].violinplot(abs_error_lists, showmeans=True, showmedians=True)
    for idx, body in enumerate(parts['bodies']):
        body.set_facecolor(colors[idx])
        body.set_edgecolor('black')
        body.set_alpha(0.6)
    axes[1].set_xticks(np.arange(1, len(datasets)+1))
    axes[1].set_xticklabels([embed_names[ds] for ds in datasets])
    axes[1].set_title('Mutlak Hata Dağılımı (Violin)', fontsize=12)
    axes[1].set_ylabel('|Tahmin - Gerçek|')
    axes[1].grid(axis='y', alpha=0.3)
    
    plt.suptitle('Verisetleri Hata Özeti', fontsize=14, y=0.98)
    plt.tight_layout()
    plt.savefig(os.path.join(output_dir, "dataset_error_overview.png"), dpi=150, bbox_inches='tight')
    plt.close()

def save_results(all_results, output_dir, embed_size, dataset_dir, timestamp):
    """
    Tüm sonuçları kaydeder.
    
    Args:
        all_results: Tüm model sonuçları
        output_dir: Çıktı dizini
    """
    resolved_dataset_dir = os.path.abspath(dataset_dir)
    # Özet metrikleri kaydet
    summary = {
        "_meta": {
            "model": MODEL_NAME,
            "embed_size": embed_size,
            "dataset_dir": resolved_dataset_dir,
            "output_dir": os.path.abspath(output_dir),
            "timestamp": timestamp,
        }
    }
    for embed_type, results in all_results.items():
        summary[embed_type] = {
            'accuracy': results['metrics']['accuracy'],
            'f1_macro': results['metrics']['f1_macro'],
            'f1_weighted': results['metrics']['f1_weighted'],
            'precision_macro': results['metrics']['precision_macro'],
            'recall_macro': results['metrics']['recall_macro'],
            'mae': results['metrics']['mae'],
            'rmse': results['metrics']['rmse']
        }
    
    with open(os.path.join(output_dir, "metrics_summary.json"), "w") as f:
        json.dump(summary, f, indent=2)
    
    # Karşılaştırma tablosu oluştur
    comparison_text = """# Random Forest Sonuçları

## Deney Bilgileri

| Bilgi | Değer |
|-------|-------|
| dataset_dir | {} |
| embed_size | {} |
| output_dir | {} |
| timestamp | {} |

## Model Parametreleri

| Parametre | Değer |
|-----------|-------|
| n_estimators | Veri setine göre değişir (title: 100, abstract: 200, concat: 200) |
| max_depth | Veri setine göre değişir (title: 20, abstract: 30, concat: 20) |
| min_samples_split | {} |
| min_samples_leaf | {} |
| random_state | {} |

## Performans Karşılaştırması

| Veriseti | Accuracy | F1 (Macro) | F1 (Weighted) | Precision | Recall | MAE | RMSE |
|----------|----------|------------|---------------|-----------|--------|-----|------|
""".format(
        resolved_dataset_dir,
        embed_size,
        os.path.abspath(output_dir),
        timestamp,
        MIN_SAMPLES_SPLIT,
        MIN_SAMPLES_LEAF,
        RANDOM_SEED,
    )
    
    for embed_type in all_results.keys():
        metrics = summary[embed_type]
        comparison_text += "| {} | {:.4f} | {:.4f} | {:.4f} | {:.4f} | {:.4f} | {:.2f} | {:.2f} |\n".format(
            embed_type,
            metrics['accuracy'],
            metrics['f1_macro'],
            metrics['f1_weighted'],
            metrics['precision_macro'],
            metrics['recall_macro'],
            metrics['mae'],
            metrics['rmse']
        )
    
    # Her veriseti için detaylı rapor
    for embed_type, results in all_results.items():
        comparison_text += f"\n## {embed_type.capitalize()} Veriseti Detaylı Rapor\n\n```\n"
        comparison_text += results['metrics']['classification_report']
        comparison_text += "\n```\n"
    
    with open(os.path.join(output_dir, "results_report.md"), "w", encoding="utf-8") as f:
        f.write(comparison_text)


def plot_comparison(all_results, output_dir):
    """
    Tüm modellerin karşılaştırma grafiğini oluşturur.
    
    Args:
        all_results: Tüm model sonuçları
        output_dir: Çıktı dizini
    """
    embed_types = list(all_results.keys())
    metrics_names = ['accuracy', 'f1_macro', 'f1_weighted', 'precision_macro', 'recall_macro']
    metrics_labels = ['Accuracy', 'F1 (Macro)', 'F1 (Weighted)', 'Precision', 'Recall']
    
    x = np.arange(len(embed_types))
    width = 0.15
    
    fig, ax = plt.subplots(figsize=(12, 6))
    
    colors = ['#2ecc71', '#3498db', '#9b59b6', '#e74c3c', '#f39c12']
    
    for i, (metric_name, metric_label, color) in enumerate(zip(metrics_names, metrics_labels, colors)):
        values = [all_results[et]['metrics'][metric_name] for et in embed_types]
        bars = ax.bar(x + i * width, values, width, label=metric_label, color=color)
        
        # Değerleri bar'ların üstüne yaz
        for bar, val in zip(bars, values):
            ax.text(bar.get_x() + bar.get_width()/2, bar.get_height() + 0.01,
                   f'{val:.3f}', ha='center', va='bottom', fontsize=8, rotation=90)
    
    ax.set_xlabel('Veriseti', fontsize=12)
    ax.set_ylabel('Skor', fontsize=12)
    ax.set_title('Random Forest - Veriseti Karşılaştırması', fontsize=14)
    ax.set_xticks(x + width * 2)
    ax.set_xticklabels(['Başlık', 'Özet', 'Birleştirilmiş'])
    ax.legend(loc='upper left', bbox_to_anchor=(1, 1))
    ax.set_ylim(0, 1.15)
    ax.grid(axis='y', alpha=0.3)
    
    plt.tight_layout()
    plt.savefig(os.path.join(output_dir, "comparison.png"), dpi=150, bbox_inches='tight')
    plt.close()


def main():
    """
    Ana fonksiyon - Random Forest deney sürecini yönetir.
    """
    print("=" * 60)
    print("RANDOM FOREST MODEL EĞİTİMİ VE DEĞERLENDİRMESİ")
    print("=" * 60)
    
    args = parse_args()
    dataset_dir = args.dataset
    embed_size = args.embed_size
    print(f"Kullanılan veri dizini: {dataset_dir}")
    print(f"Embed boyutu: {embed_size}")

    # Çıktı dizini oluştur (timestamp ile)
    timestamp = datetime.now().strftime("%Y-%m-%d_%H%M%S")
    output_dir = os.path.join(ARTIFACTS_DIR, f"{timestamp}_random_forest")
    os.makedirs(output_dir, exist_ok=True)
    print(f"\nÇıktı dizini: {output_dir}")
    
    # Embedding türleri
    embed_types = ['title', 'abstract', 'concat']
    embed_names = {
        'title': 'Başlık',
        'abstract': 'Özet', 
        'concat': 'Birleştirilmiş'
    }
    
    all_results = {}
    
    for embed_type in embed_types:
        print(f"\n{'='*60}")
        print(f"{embed_names[embed_type].upper()} VERİSETİ")
        print(f"{'='*60}")
        
        # Veriyi yükle
        print("\n1. Veri yükleniyor...")
        X_train, y_train, X_test, y_test = load_embedding_data(embed_type, dataset_dir)
        print(f"   Train: {X_train.shape}, Test: {X_test.shape}")
        
        # Model eğit
        print("\n2. Model eğitiliyor...")
        model = train_model(X_train, y_train, embed_type, embed_size)
        
        # Değerlendir
        print("\n3. Model değerlendiriliyor...")
        metrics = evaluate_model(model, X_test, y_test)
        print(f"   Accuracy: {metrics['accuracy']:.4f}")
        print(f"   F1 (Macro): {metrics['f1_macro']:.4f}")
        
        # Grafikleri oluştur
        print("\n4. Grafikler oluşturuluyor...")
        
        plot_confusion_matrix(
            metrics, 
            f"Random Forest - {embed_names[embed_type]}",
            os.path.join(output_dir, f"{embed_type}_confusion_matrix.png")
        )
        
        plot_year_accuracy(
            metrics,
            f"Random Forest - {embed_names[embed_type]}",
            os.path.join(output_dir, f"{embed_type}_year_accuracy.png")
        )
        
        plot_prediction_distribution(
            metrics,
            f"Random Forest - {embed_names[embed_type]}",
            os.path.join(output_dir, f"{embed_type}_prediction_dist.png")
        )
        
        plot_error_summary(
            metrics,
            f"Random Forest - {embed_names[embed_type]} Detaylı Hata Profili",
            os.path.join(output_dir, f"{embed_type}_error_summary.png"),
            DATASET_PALETTE[embed_type]
        )
        
        # Modeli kaydet
        model_path = os.path.join(output_dir, f"{embed_type}_model.joblib")
        joblib.dump(model, model_path)
        print(f"   Model kaydedildi: {model_path}")
        
        all_results[embed_type] = {
            'metrics': metrics,
            'model_path': model_path
        }
    
    # Sonuçları kaydet
    print(f"\n{'='*60}")
    print("SONUÇLAR KAYDEDİLİYOR")
    print(f"{'='*60}")
    
    save_results(all_results, output_dir, embed_size, dataset_dir, timestamp)
    plot_comparison(all_results, output_dir)
    plot_dataset_error_overview(all_results, output_dir, embed_names)
    
    print(f"\n✓ Tüm sonuçlar kaydedildi: {output_dir}/")
    
    # Özet tablo
    print("\n" + "=" * 60)
    print("ÖZET")
    print("=" * 60)
    print("\n{:<15} {:>10} {:>10} {:>10} {:>8}".format(
        "Veriseti", "Accuracy", "F1-Macro", "F1-Weight", "MAE"
    ))
    print("-" * 60)
    for embed_type in embed_types:
        m = all_results[embed_type]['metrics']
        print("{:<15} {:>10.4f} {:>10.4f} {:>10.4f} {:>8.2f}".format(
            embed_names[embed_type],
            m['accuracy'],
            m['f1_macro'],
            m['f1_weighted'],
            m['mae']
        ))


if __name__ == "__main__":
    main()

