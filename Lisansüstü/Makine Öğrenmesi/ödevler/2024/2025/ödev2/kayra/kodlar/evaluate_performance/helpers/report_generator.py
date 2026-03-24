"""
Report Generator Module
=======================
Bu modül, sonuç raporları ve görselleştirme fonksiyonlarını içerir.
"""

import os
import numpy as np
import pandas as pd
from typing import Dict, List, Optional
from datetime import datetime
import matplotlib.pyplot as plt
import seaborn as sns


def get_results_dir() -> str:
    """
    Results klasörünün yolunu döndür ve gerekirse oluştur.
    
    Returns:
        str: results klasörünün mutlak yolu
    """
    current_dir = os.path.dirname(os.path.abspath(__file__))
    results_dir = os.path.join(current_dir, "..", "results")
    
    if not os.path.exists(results_dir):
        os.makedirs(results_dir)
        print(f"✓ Klasör oluşturuldu: {results_dir}")
    
    return results_dir


def generate_results_table(results_dict: Dict) -> pd.DataFrame:
    """
    Sonuç tablosu oluştur.
    
    Args:
        results_dict: Her yöntem için sonuçlar
            {
                'method_key': {
                    'name': 'Yöntem Adı',
                    'feature_count': 15,
                    'accuracy': 0.65,
                    'f1_score': 0.64,
                    'training_time': 0.5,
                    'C': 1.0  # optional
                }
            }
    
    Returns:
        pd.DataFrame: Sonuç tablosu
    """
    rows = []
    
    for key, result in results_dict.items():
        row = {
            'Yöntem': result['name'],
            'Özellik Sayısı': result['feature_count'],
            'Doğruluk (Accuracy)': f"{result['accuracy']:.4f}",
            'F1-Skoru': f"{result['f1_score']:.4f}",
            'Eğitim Süresi (s)': f"{result['training_time']:.4f}",
        }
        
        # Regularization bilgisi varsa ekle
        if 'C' in result:
            row['C (Regularization)'] = result['C']
        
        rows.append(row)
    
    df = pd.DataFrame(rows)
    
    return df


def save_results_to_csv(results_dict: Dict, filename: str = "results.csv") -> str:
    """
    Sonuçları CSV dosyasına kaydet.
    
    Args:
        results_dict: Sonuçlar dict'i
        filename: Dosya adı
    
    Returns:
        str: Kaydedilen dosyanın yolu
    """
    results_dir = get_results_dir()
    filepath = os.path.join(results_dir, filename)
    
    df = generate_results_table(results_dict)
    df.to_csv(filepath, index=False, encoding='utf-8')
    
    print(f"✓ Sonuçlar kaydedildi: {filepath}")
    
    return filepath


def generate_markdown_report(
    results_dict: Dict,
    best_method: str,
    confusion_matrix_data: Optional[np.ndarray] = None,
    overfitting_info: Optional[Dict] = None,
    feature_comparison: Optional[Dict] = None
) -> str:
    """
    Detaylı Markdown raporu oluştur.
    
    Args:
        results_dict: Sonuçlar dict'i
        best_method: En başarılı yöntemin anahtarı
        confusion_matrix_data: Karışıklık matrisi (optional)
        overfitting_info: Aşırı öğrenme bilgileri (optional)
        feature_comparison: Özellik karşılaştırma tablosu (optional)
    
    Returns:
        str: Markdown formatında rapor
    """
    report = f"""# 📊 Lojistik Regresyon Performans Değerlendirme Raporu

**Tarih:** {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}
**Yöntem:** Lojistik Regresyon + K-Fold Cross Validation (K=5)
**Test Oranı:** %20

---

## 📈 Sonuç Tablosu

| Yöntem | Özellik Sayısı | Doğruluk (Accuracy) | F1-Skoru | Eğitim Süresi (s) |
|--------|----------------|---------------------|----------|-------------------|
"""
    
    # Tablo satırlarını ekle
    for key, result in results_dict.items():
        best_marker = " ⭐" if key == best_method else ""
        report += f"| {result['name']}{best_marker} | {result['feature_count']} | "
        report += f"{result['accuracy']:.4f} | {result['f1_score']:.4f} | "
        report += f"{result['training_time']:.4f} |\n"
    
    # En başarılı yöntemi vurgula
    best_result = results_dict[best_method]
    report += f"""
> [!NOTE]
> En başarılı yöntem: **{best_result['name']}** (Accuracy: {best_result['accuracy']:.4f}, F1: {best_result['f1_score']:.4f})

---

## 🎯 En Başarılı Yöntem Detayları

**Yöntem:** {best_result['name']}
**Özellik Sayısı:** {best_result['feature_count']}
**Doğruluk:** {best_result['accuracy']:.4f} ({best_result['accuracy']*100:.2f}%)
**F1-Skoru:** {best_result['f1_score']:.4f}
"""
    
    # Aşırı öğrenme bilgisi
    if overfitting_info:
        report += f"""
---

## ⚠️ Aşırı Öğrenme Analizi

"""
        for method, info in overfitting_info.items():
            status = "⚠️ Tespit Edildi" if info.get('detected', False) else "✅ Tespit Edilmedi"
            report += f"- **{method}:** {status}"
            if 'gap' in info:
                report += f" (Fark: {info['gap']:.4f})"
            if info.get('detected', False) and 'best_C' in info:
                report += f", Regularization C={info['best_C']}"
            report += "\n"
    
    # Karışıklık matrisi
    if confusion_matrix_data is not None:
        tn, fp, fn, tp = confusion_matrix_data.ravel()
        report += f"""
---

## 📋 Karışıklık Matrisi ({best_result['name']})

|  | Tahmin: 0 | Tahmin: 1 |
|--|-----------|-----------|
| **Gerçek: 0** | {tn} (TN) | {fp} (FP) |
| **Gerçek: 1** | {fn} (FN) | {tp} (TP) |

**Açıklama:**
- TN (True Negative): Doğru tahmin edilen negatif örnekler
- FP (False Positive): Yanlış pozitif tahminler
- FN (False Negative): Yanlış negatif tahminler
- TP (True Positive): Doğru tahmin edilen pozitif örnekler
"""
    
    return report


def save_markdown_report(report: str, filename: str = "evaluation_report.md") -> str:
    """
    Markdown raporunu dosyaya kaydet.
    
    Args:
        report: Markdown içeriği
        filename: Dosya adı
    
    Returns:
        str: Kaydedilen dosyanın yolu
    """
    results_dir = get_results_dir()
    filepath = os.path.join(results_dir, filename)
    
    with open(filepath, 'w', encoding='utf-8') as f:
        f.write(report)
    
    print(f"✓ Rapor kaydedildi: {filepath}")
    
    return filepath


def plot_confusion_matrix(
    cm: np.ndarray, 
    title: str = "Karışıklık Matrisi",
    labels: List[str] = None,
    figsize: tuple = (8, 6)
) -> plt.Figure:
    """
    Karışıklık matrisini görselleştir.
    
    Args:
        cm: Karışıklık matrisi (2x2 numpy array)
        title: Grafik başlığı
        labels: Sınıf etiketleri
        figsize: Grafik boyutu
    
    Returns:
        plt.Figure: Matplotlib figure objesi
    """
    if labels is None:
        labels = ['Not Popular (0)', 'Popular (1)']
    
    fig, ax = plt.subplots(figsize=figsize)
    
    # Heatmap oluştur
    sns.heatmap(
        cm, 
        annot=True, 
        fmt='d', 
        cmap='Blues',
        xticklabels=labels,
        yticklabels=labels,
        ax=ax,
        annot_kws={'size': 14}
    )
    
    ax.set_xlabel('Tahmin Edilen', fontsize=12)
    ax.set_ylabel('Gerçek', fontsize=12)
    ax.set_title(title, fontsize=14, fontweight='bold')
    
    plt.tight_layout()
    
    return fig


def save_confusion_matrix_plot(
    cm: np.ndarray, 
    filename: str = "confusion_matrix.png",
    title: str = "Karışıklık Matrisi"
) -> str:
    """
    Karışıklık matrisi görselini dosyaya kaydet.
    
    Args:
        cm: Karışıklık matrisi
        filename: Dosya adı
        title: Grafik başlığı
    
    Returns:
        str: Kaydedilen dosyanın yolu
    """
    results_dir = get_results_dir()
    filepath = os.path.join(results_dir, filename)
    
    fig = plot_confusion_matrix(cm, title=title)
    fig.savefig(filepath, dpi=150, bbox_inches='tight')
    plt.close(fig)
    
    print(f"✓ Karışıklık matrisi kaydedildi: {filepath}")
    
    return filepath


def plot_comparison_bar_chart(
    results_dict: Dict,
    metric: str = 'accuracy',
    title: str = "Yöntem Karşılaştırması",
    figsize: tuple = (10, 6)
) -> plt.Figure:
    """
    Yöntem karşılaştırma çubuk grafiği oluştur.
    
    Args:
        results_dict: Sonuçlar dict'i
        metric: Karşılaştırılacak metrik ('accuracy' veya 'f1_score')
        title: Grafik başlığı
        figsize: Grafik boyutu
    
    Returns:
        plt.Figure: Matplotlib figure objesi
    """
    methods = [r['name'] for r in results_dict.values()]
    values = [r[metric] for r in results_dict.values()]
    
    fig, ax = plt.subplots(figsize=figsize)
    
    colors = ['#2ecc71', '#3498db', '#9b59b6', '#e74c3c'][:len(methods)]
    bars = ax.bar(methods, values, color=colors, edgecolor='black')
    
    # Değerleri çubukların üzerine yaz
    for bar, val in zip(bars, values):
        ax.text(
            bar.get_x() + bar.get_width()/2, 
            bar.get_height() + 0.005, 
            f'{val:.4f}', 
            ha='center', 
            va='bottom',
            fontsize=11,
            fontweight='bold'
        )
    
    metric_label = 'Doğruluk (Accuracy)' if metric == 'accuracy' else 'F1-Skoru'
    ax.set_ylabel(metric_label, fontsize=12)
    ax.set_xlabel('Yöntem', fontsize=12)
    ax.set_title(title, fontsize=14, fontweight='bold')
    
    # Y ekseni limitlerini ayarla
    ax.set_ylim([min(values) - 0.05, max(values) + 0.05])
    
    plt.xticks(rotation=15, ha='right')
    plt.tight_layout()
    
    return fig


def save_comparison_plot(
    results_dict: Dict,
    filename: str = "method_comparison.png",
    metric: str = 'accuracy'
) -> str:
    """
    Karşılaştırma grafiğini kaydet.
    
    Args:
        results_dict: Sonuçlar
        filename: Dosya adı
        metric: Metrik türü
    
    Returns:
        str: Dosya yolu
    """
    results_dir = get_results_dir()
    filepath = os.path.join(results_dir, filename)
    
    title = f"Yöntem Karşılaştırması - {'Accuracy' if metric == 'accuracy' else 'F1-Score'}"
    fig = plot_comparison_bar_chart(results_dict, metric=metric, title=title)
    fig.savefig(filepath, dpi=150, bbox_inches='tight')
    plt.close(fig)
    
    print(f"✓ Karşılaştırma grafiği kaydedildi: {filepath}")
    
    return filepath
