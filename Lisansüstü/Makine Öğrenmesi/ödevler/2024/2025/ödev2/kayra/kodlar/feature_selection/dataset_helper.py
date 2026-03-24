"""
Dataset Helper Module
=====================
Bu modül, veri kümesi yükleme, kaydetme ve işleme fonksiyonlarını içerir.
"""

import pandas as pd
import numpy as np
import os
from typing import Tuple, List, Optional


def get_dataset_dir() -> str:
    """
    Dataset klasörünün yolunu döndür.
    
    Returns:
        str: dataset_files klasörünün mutlak yolu
    """
    current_dir = os.path.dirname(os.path.abspath(__file__))
    return os.path.join(current_dir, "..", "dataset_files")


def load_processed_dataset(filename: str = "processed_dataset.csv") -> pd.DataFrame:
    """
    İşlenmiş veri kümesini yükle.
    
    Args:
        filename: Yüklenecek dosyanın adı (default: processed_dataset.csv)
    
    Returns:
        pd.DataFrame: Yüklenen veri kümesi
    
    Raises:
        FileNotFoundError: Dosya bulunamazsa
    """
    dataset_dir = get_dataset_dir()
    filepath = os.path.join(dataset_dir, filename)
    
    if not os.path.exists(filepath):
        raise FileNotFoundError(f"Veri kümesi bulunamadı: {filepath}")
    
    df = pd.read_csv(filepath)
    print(f"Veri kümesi yüklendi: {filepath}")
    print(f"Boyut: {df.shape}")
    
    return df


def split_features_target(df: pd.DataFrame, target_column: str = "is_popular") -> Tuple[pd.DataFrame, pd.Series]:
    """
    Veri kümesini özellikler ve hedef değişken olarak ayır.
    
    Args:
        df: Veri kümesi DataFrame
        target_column: Hedef değişken sütunu adı
    
    Returns:
        Tuple[pd.DataFrame, pd.Series]: (Özellikler, Hedef değişken)
    """
    if target_column not in df.columns:
        raise ValueError(f"Hedef sütun '{target_column}' veri kümesinde bulunamadı.")
    
    X = df.drop(columns=[target_column])
    y = df[target_column]
    
    print(f"Özellik sayısı: {X.shape[1]}")
    print(f"Örnek sayısı: {len(y)}")
    print(f"Sınıf dağılımı: 0 -> {(y == 0).sum()}, 1 -> {(y == 1).sum()}")
    
    return X, y


def save_selected_dataset(
    df: pd.DataFrame,
    selected_features: List[str],
    target_column: str,
    filename: str
) -> str:
    """
    Seçilen özelliklerle birlikte hedef sütunu içeren veri kümesini kaydet.
    
    Args:
        df: Orijinal veri kümesi
        selected_features: Seçilen özellik isimleri listesi
        target_column: Hedef değişken sütunu adı
        filename: Kaydedilecek dosya adı
    
    Returns:
        str: Kaydedilen dosyanın yolu
    """
    dataset_dir = get_dataset_dir()
    filepath = os.path.join(dataset_dir, filename)
    
    # Seçilen sütunları al
    columns_to_save = list(selected_features) + [target_column]
    df_selected = df[columns_to_save].copy()
    
    # Kaydet
    df_selected.to_csv(filepath, index=False)
    
    print(f"\nSeçilen özelliklerle veri kümesi kaydedildi: {filepath}")
    print(f"Boyut: {df_selected.shape}")
    print(f"Sütunlar: {columns_to_save}")
    
    return filepath


def normalize_scores(scores: np.ndarray) -> np.ndarray:
    """
    Skorları 0-1 aralığına normalize et.
    
    Args:
        scores: Ham skorlar
    
    Returns:
        np.ndarray: Normalize edilmiş skorlar
    """
    min_score = np.min(scores)
    max_score = np.max(scores)
    
    if max_score == min_score:
        return np.ones_like(scores)
    
    return (scores - min_score) / (max_score - min_score)


def get_feature_ranking(
    feature_names: List[str],
    scores: np.ndarray,
    top_n: int = 15
) -> pd.DataFrame:
    """
    Özellik skorlarını sıralayarak DataFrame olarak döndür.
    
    Args:
        feature_names: Özellik isimleri
        scores: Özellik skorları (mutlak değer alınacak)
        top_n: Seçilecek özellik sayısı
    
    Returns:
        pd.DataFrame: Sıralı özellik tablosu
    """
    # Mutlak değer al (korelasyon negatif olabilir)
    abs_scores = np.abs(scores)
    
    # Normalize et
    normalized_scores = normalize_scores(abs_scores)
    
    # DataFrame oluştur
    ranking_df = pd.DataFrame({
        'Özellik': feature_names,
        'Ham Skor': scores,
        'Mutlak Skor': abs_scores,
        'Normalize Skor': normalized_scores
    })
    
    # Mutlak skora göre sırala
    ranking_df = ranking_df.sort_values('Mutlak Skor', ascending=False)
    ranking_df = ranking_df.reset_index(drop=True)
    ranking_df['Sıra'] = range(1, len(ranking_df) + 1)
    
    # Sütun sırasını düzenle
    ranking_df = ranking_df[['Sıra', 'Özellik', 'Ham Skor', 'Mutlak Skor', 'Normalize Skor']]
    
    return ranking_df


def get_top_features(ranking_df: pd.DataFrame, top_n: int = 15) -> List[str]:
    """
    Sıralı özellik tablosundan ilk N özelliği seç.
    
    Args:
        ranking_df: Sıralı özellik tablosu
        top_n: Seçilecek özellik sayısı
    
    Returns:
        List[str]: Seçilen özellik isimleri
    """
    return ranking_df.head(top_n)['Özellik'].tolist()
