"""
Data Loader Module
==================
Bu modül, veri kümesi yükleme ve bölme işlemlerini içerir.
"""

import pandas as pd
import numpy as np
import os
from typing import Tuple, Dict, List
from sklearn.model_selection import train_test_split


def get_dataset_dir() -> str:
    """
    Dataset klasörünün yolunu döndür.
    
    Returns:
        str: dataset_files klasörünün mutlak yolu
    """
    current_dir = os.path.dirname(os.path.abspath(__file__))
    return os.path.join(current_dir, "..", "..", "dataset_files")


def get_dataset_path(filename: str) -> str:
    """
    Veri kümesi dosyasının tam yolunu döndür.
    
    Args:
        filename: Dosya adı (örn: processed_dataset.csv)
    
    Returns:
        str: Dosyanın tam yolu
    
    Raises:
        FileNotFoundError: Dosya bulunamazsa
    """
    dataset_dir = get_dataset_dir()
    filepath = os.path.join(dataset_dir, filename)
    
    if not os.path.exists(filepath):
        raise FileNotFoundError(f"Veri kümesi bulunamadı: {filepath}")
    
    return filepath


def load_dataset(filename: str) -> pd.DataFrame:
    """
    Veri kümesini yükle.
    
    Args:
        filename: Yüklenecek dosyanın adı
    
    Returns:
        pd.DataFrame: Yüklenen veri kümesi
    """
    filepath = get_dataset_path(filename)
    df = pd.read_csv(filepath)
    
    print(f"✓ Veri kümesi yüklendi: {filename}")
    print(f"  Boyut: {df.shape}")
    
    return df


def split_features_target(
    df: pd.DataFrame, 
    target_column: str = "is_popular"
) -> Tuple[pd.DataFrame, pd.Series]:
    """
    Veri kümesini özellikler ve hedef değişken olarak ayır.
    
    Args:
        df: Veri kümesi DataFrame
        target_column: Hedef değişken sütunu adı
    
    Returns:
        Tuple[pd.DataFrame, pd.Series]: (Özellikler X, Hedef y)
    """
    if target_column not in df.columns:
        raise ValueError(f"Hedef sütun '{target_column}' veri kümesinde bulunamadı.")
    
    X = df.drop(columns=[target_column])
    y = df[target_column]
    
    return X, y


def split_train_test(
    X: pd.DataFrame, 
    y: pd.Series, 
    test_size: float = 0.2, 
    random_state: int = 42
) -> Tuple[pd.DataFrame, pd.DataFrame, pd.Series, pd.Series]:
    """
    Veriyi eğitim ve test setlerine böl.
    
    Args:
        X: Özellikler DataFrame
        y: Hedef değişken Series
        test_size: Test setinin oranı (default: 0.2 = %20)
        random_state: Rastgelelik için seed değeri
    
    Returns:
        Tuple: (X_train, X_test, y_train, y_test)
    """
    X_train, X_test, y_train, y_test = train_test_split(
        X, y, 
        test_size=test_size, 
        random_state=random_state,
        stratify=y  # Sınıf dağılımını koru
    )
    
    print(f"  Eğitim seti: {X_train.shape[0]} örnek")
    print(f"  Test seti: {X_test.shape[0]} örnek")
    
    return X_train, X_test, y_train, y_test


def get_all_datasets() -> Dict[str, Dict]:
    """
    Tüm veri kümelerini yükle ve dict olarak döndür.
    
    Returns:
        Dict: Her veri kümesi için ayrı dict
            - 'name': Yöntem adı
            - 'filename': Dosya adı
            - 'df': DataFrame
            - 'X': Özellikler
            - 'y': Hedef
            - 'feature_count': Özellik sayısı
    """
    datasets_config = {
        'all_features': {
            'name': 'Tüm Özellikler',
            'filename': 'processed_dataset.csv'
        },
        'filter_method': {
            'name': 'Filtreleme (Pearson)',
            'filename': 'filter_method_selected_dataset.csv'
        },
        'wrapper_method': {
            'name': 'Sarmalayıcı (RFE)',
            'filename': 'wrapper_method_selected_dataset.csv'
        },
        'embedded_method': {
            'name': 'Gömülü (Random Forest)',
            'filename': 'embedded_method_selected_dataset.csv'
        }
    }
    
    datasets = {}
    
    print("=" * 60)
    print("VERİ KÜMELERİ YÜKLENİYOR")
    print("=" * 60)
    
    for key, config in datasets_config.items():
        print(f"\n📂 {config['name']}")
        
        df = load_dataset(config['filename'])
        X, y = split_features_target(df)
        
        datasets[key] = {
            'name': config['name'],
            'filename': config['filename'],
            'df': df,
            'X': X,
            'y': y,
            'feature_count': X.shape[1],
            'feature_names': list(X.columns)
        }
        
        print(f"  Özellik sayısı: {X.shape[1]}")
        print(f"  Sınıf dağılımı: 0 → {(y == 0).sum()}, 1 → {(y == 1).sum()}")
    
    print("\n" + "=" * 60)
    print(f"✓ Toplam {len(datasets)} veri kümesi yüklendi.")
    print("=" * 60)
    
    return datasets
