"""
File Helper Module
==================
Bu modül, dosya işlemleri ve rapor yazma fonksiyonlarını içerir.
"""

import os
from typing import Optional


def get_feature_selection_dir() -> str:
    """
    Feature selection klasörünün yolunu döndür.
    
    Returns:
        str: feature_selection klasörünün mutlak yolu
    """
    return os.path.dirname(os.path.abspath(__file__))


def write_report(content: str, filename: str) -> str:
    """
    Rapor içeriğini dosyaya yaz.
    
    Args:
        content: Yazılacak içerik
        filename: Dosya adı (örn: filter_analysis_report.md)
    
    Returns:
        str: Kaydedilen dosyanın yolu
    """
    feature_selection_dir = get_feature_selection_dir()
    filepath = os.path.join(feature_selection_dir, filename)
    
    with open(filepath, 'w', encoding='utf-8') as f:
        f.write(content)
    
    print(f"Rapor kaydedildi: {filepath}")
    return filepath


def read_file(filename: str) -> str:
    """
    Dosya içeriğini oku.
    
    Args:
        filename: Okunacak dosya adı
    
    Returns:
        str: Dosya içeriği
    """
    feature_selection_dir = get_feature_selection_dir()
    filepath = os.path.join(feature_selection_dir, filename)
    
    if not os.path.exists(filepath):
        raise FileNotFoundError(f"Dosya bulunamadı: {filepath}")
    
    with open(filepath, 'r', encoding='utf-8') as f:
        return f.read()


def ensure_directory_exists(directory_path: str) -> None:
    """
    Klasörün var olduğundan emin ol, yoksa oluştur.
    
    Args:
        directory_path: Klasör yolu
    """
    if not os.path.exists(directory_path):
        os.makedirs(directory_path)
        print(f"Klasör oluşturuldu: {directory_path}")
