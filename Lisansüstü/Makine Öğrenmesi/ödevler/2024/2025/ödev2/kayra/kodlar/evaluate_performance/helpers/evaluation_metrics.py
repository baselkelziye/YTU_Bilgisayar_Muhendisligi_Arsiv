"""
Evaluation Metrics Module
=========================
Bu modül, performans metrikleri hesaplama fonksiyonlarını içerir.
"""

import numpy as np
import pandas as pd
from typing import Dict, Tuple
from sklearn.metrics import (
    accuracy_score,
    f1_score,
    precision_score,
    recall_score,
    confusion_matrix,
    classification_report
)


def calculate_accuracy(y_true: np.ndarray, y_pred: np.ndarray) -> float:
    """
    Doğruluk (Accuracy) hesapla.
    
    Args:
        y_true: Gerçek değerler
        y_pred: Tahmin değerleri
    
    Returns:
        float: Accuracy skoru (0-1 arası)
    """
    return accuracy_score(y_true, y_pred)


def calculate_f1_score(
    y_true: np.ndarray, 
    y_pred: np.ndarray,
    average: str = 'weighted'
) -> float:
    """
    F1-Skoru hesapla.
    
    Args:
        y_true: Gerçek değerler
        y_pred: Tahmin değerleri
        average: Ortalama türü ('binary', 'micro', 'macro', 'weighted')
    
    Returns:
        float: F1 skoru (0-1 arası)
    """
    return f1_score(y_true, y_pred, average=average)


def calculate_precision(
    y_true: np.ndarray, 
    y_pred: np.ndarray,
    average: str = 'weighted'
) -> float:
    """
    Precision (Kesinlik) hesapla.
    
    Args:
        y_true: Gerçek değerler
        y_pred: Tahmin değerleri
        average: Ortalama türü
    
    Returns:
        float: Precision skoru
    """
    return precision_score(y_true, y_pred, average=average)


def calculate_recall(
    y_true: np.ndarray, 
    y_pred: np.ndarray,
    average: str = 'weighted'
) -> float:
    """
    Recall (Duyarlılık) hesapla.
    
    Args:
        y_true: Gerçek değerler
        y_pred: Tahmin değerleri
        average: Ortalama türü
    
    Returns:
        float: Recall skoru
    """
    return recall_score(y_true, y_pred, average=average)


def calculate_metrics(y_true: np.ndarray, y_pred: np.ndarray) -> Dict[str, float]:
    """
    Tüm performans metriklerini hesapla.
    
    Args:
        y_true: Gerçek değerler
        y_pred: Tahmin değerleri
    
    Returns:
        Dict: Tüm metrikler
            - accuracy: Doğruluk
            - f1_score: F1-Skoru
            - precision: Kesinlik
            - recall: Duyarlılık
    """
    metrics = {
        'accuracy': calculate_accuracy(y_true, y_pred),
        'f1_score': calculate_f1_score(y_true, y_pred),
        'precision': calculate_precision(y_true, y_pred),
        'recall': calculate_recall(y_true, y_pred)
    }
    
    return metrics


def create_confusion_matrix(y_true: np.ndarray, y_pred: np.ndarray) -> np.ndarray:
    """
    Karışıklık matrisi (Confusion Matrix) oluştur.
    
    Args:
        y_true: Gerçek değerler
        y_pred: Tahmin değerleri
    
    Returns:
        np.ndarray: 2x2 karışıklık matrisi
            [[TN, FP],
             [FN, TP]]
    """
    return confusion_matrix(y_true, y_pred)


def get_confusion_matrix_values(cm: np.ndarray) -> Dict[str, int]:
    """
    Karışıklık matrisi değerlerini ayrı ayrı al.
    
    Args:
        cm: Karışıklık matrisi
    
    Returns:
        Dict: TN, FP, FN, TP değerleri
    """
    tn, fp, fn, tp = cm.ravel()
    
    return {
        'TN': tn,  # True Negative
        'FP': fp,  # False Positive
        'FN': fn,  # False Negative
        'TP': tp   # True Positive
    }


def get_classification_report(
    y_true: np.ndarray, 
    y_pred: np.ndarray,
    target_names: list = None
) -> str:
    """
    Detaylı sınıflandırma raporu oluştur.
    
    Args:
        y_true: Gerçek değerler
        y_pred: Tahmin değerleri
        target_names: Sınıf isimleri
    
    Returns:
        str: Sınıflandırma raporu
    """
    if target_names is None:
        target_names = ['Not Popular (0)', 'Popular (1)']
    
    return classification_report(y_true, y_pred, target_names=target_names)


def print_metrics_summary(metrics: Dict[str, float], method_name: str = "") -> None:
    """
    Metrikleri özet olarak yazdır.
    
    Args:
        metrics: Metrikler dict'i
        method_name: Yöntem adı
    """
    print(f"\n{'=' * 50}")
    if method_name:
        print(f"📊 {method_name} - Test Sonuçları")
    else:
        print("📊 Test Sonuçları")
    print('=' * 50)
    print(f"  Accuracy:  {metrics['accuracy']:.4f} ({metrics['accuracy']*100:.2f}%)")
    print(f"  F1-Score:  {metrics['f1_score']:.4f}")
    print(f"  Precision: {metrics['precision']:.4f}")
    print(f"  Recall:    {metrics['recall']:.4f}")
    print('=' * 50)
