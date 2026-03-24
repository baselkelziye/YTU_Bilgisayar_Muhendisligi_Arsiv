"""
Report Helper Module
====================
Bu modül, analiz raporu oluşturma fonksiyonlarını içerir.
"""

import pandas as pd
from typing import List, Optional
from datetime import datetime


def generate_score_comment(normalized_score: float, rank: int) -> str:
    """
    Normalize skor ve sıraya göre yorum oluştur.
    
    Args:
        normalized_score: 0-1 arası normalize edilmiş skor
        rank: Sıralama
    
    Returns:
        str: Yorum
    """
    if rank <= 3:
        return "🥇 En önemli özelliklerden"
    elif rank <= 5:
        return "🥈 Çok yüksek önem"
    elif rank <= 10:
        return "🥉 Yüksek önem"
    elif normalized_score >= 0.5:
        return "Orta-yüksek önem"
    elif normalized_score >= 0.3:
        return "Orta önem"
    else:
        return "Düşük-orta önem"


def generate_feature_table(ranking_df: pd.DataFrame, top_n: int = 15) -> str:
    """
    Özellik sıralaması tablosunu markdown formatında oluştur.
    
    Args:
        ranking_df: Sıralı özellik DataFrame'i (Sıra, Özellik, Normalize Skor sütunları olmalı)
        top_n: Tabloda gösterilecek özellik sayısı
    
    Returns:
        str: Markdown formatında tablo
    """
    table_lines = []
    table_lines.append("| Sıra | Özellik | Normalize Skor | Yorum |")
    table_lines.append("|------|---------|----------------|-------|")
    
    for idx, row in ranking_df.head(top_n).iterrows():
        rank = int(row['Sıra'])
        feature = row['Özellik']
        score = row['Normalize Skor']
        comment = generate_score_comment(score, rank)
        
        table_lines.append(f"| {rank} | {feature} | {score:.4f} | {comment} |")
    
    return "\n".join(table_lines)


def generate_analysis_report(
    method_name: str,
    method_description: str,
    ranking_df: pd.DataFrame,
    top_n: int = 15,
    dataset_info: dict = None,
    additional_notes: str = ""
) -> str:
    """
    Feature selection analiz raporu oluştur.
    
    Args:
        method_name: Yöntem adı (örn: "Filtreleme Yöntemi - Pearson Korelasyonu")
        method_description: Yöntemin açıklaması
        ranking_df: Sıralı özellik DataFrame'i
        top_n: Seçilen özellik sayısı
        dataset_info: Veri kümesi bilgileri dict (name, shape, source)
        additional_notes: Ek notlar
    
    Returns:
        str: Markdown formatında rapor içeriği
    """
    if dataset_info is None:
        dataset_info = {
            "name": "processed_dataset.csv",
            "shape": "(39644, 59)",
            "source": "UCI Online News Popularity"
        }
    
    # Rapor başlığı
    report = f"""# Feature Selection Analiz Raporu

**Yöntem:** {method_name}
**Veri Kümesi:** {dataset_info.get('name', 'processed_dataset.csv')}
**Boyut:** {dataset_info.get('shape', 'N/A')}
**Kaynak:** {dataset_info.get('source', 'UCI Online News Popularity')}
**Tarih:** {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}

---

## 📊 Genel Değerlendirme

{method_description}

**Seçilen Özellik Sayısı:** {top_n}

---

## Özellik Sıralaması

{generate_feature_table(ranking_df, top_n)}

---

## 📋 Seçilen Özellikler Listesi

Seçilen en iyi {top_n} özellik:

"""
    
    # Seçilen özellikleri liste olarak ekle
    selected_features = ranking_df.head(top_n)['Özellik'].tolist()
    for i, feature in enumerate(selected_features, 1):
        report += f"{i}. `{feature}`\n"
    
    # Ek notlar
    if additional_notes:
        report += f"""
---

## 📝 Ek Notlar

{additional_notes}
"""
    
    # Özet istatistikler
    report += f"""
---

## 📈 Skor İstatistikleri

| Metrik | Değer |
|--------|-------|
| Maksimum Normalize Skor | {ranking_df['Normalize Skor'].max():.4f} |
| Minimum Normalize Skor (Top {top_n}) | {ranking_df.head(top_n)['Normalize Skor'].min():.4f} |
| Ortalama Normalize Skor (Top {top_n}) | {ranking_df.head(top_n)['Normalize Skor'].mean():.4f} |
"""
    
    return report
