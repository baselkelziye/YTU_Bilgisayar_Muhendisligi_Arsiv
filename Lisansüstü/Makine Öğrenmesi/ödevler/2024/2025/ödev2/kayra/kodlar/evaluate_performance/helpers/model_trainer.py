"""
Model Trainer Module
====================
Bu modül, Lojistik Regresyon modeli eğitimi ve cross-validation işlemlerini içerir.
"""

import numpy as np
import pandas as pd
import time
from typing import Dict, Tuple, List, Optional
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import cross_val_score, StratifiedKFold
from sklearn.preprocessing import StandardScaler


def create_logistic_regression_model(
    C: float = 1.0, 
    max_iter: int = 1000, 
    solver: str = 'lbfgs',
    random_state: int = 42
) -> LogisticRegression:
    """
    Lojistik Regresyon modeli oluştur.
    
    Args:
        C: Regularization strength (küçük C = güçlü regularization)
        max_iter: Maksimum iterasyon sayısı
        solver: Optimizasyon algoritması
        random_state: Rastgelelik için seed değeri
    
    Returns:
        LogisticRegression: Oluşturulan model
    """
    model = LogisticRegression(
        C=C,
        max_iter=max_iter,
        solver=solver,
        random_state=random_state,
        n_jobs=-1  # Paralel işlem
    )
    
    return model


def cross_validate_model(
    model: LogisticRegression,
    X: pd.DataFrame,
    y: pd.Series,
    cv: int = 5,
    return_train_score: bool = True
) -> Dict:
    """
    K-fold cross validation ile model değerlendir.
    
    Args:
        model: Eğitilecek model
        X: Özellikler
        y: Hedef değişken
        cv: Fold sayısı (default: 5)
        return_train_score: Eğitim skorlarını da döndür
    
    Returns:
        Dict: Cross-validation sonuçları
            - 'train_scores': Eğitim skorları
            - 'val_scores': Validasyon skorları
            - 'train_mean': Eğitim ortalaması
            - 'val_mean': Validasyon ortalaması
            - 'train_std': Eğitim std
            - 'val_std': Validasyon std
    """
    # Veriyi ölçeklendir
    scaler = StandardScaler()
    X_scaled = scaler.fit_transform(X)
    
    # Stratified K-Fold
    skf = StratifiedKFold(n_splits=cv, shuffle=True, random_state=42)
    
    train_scores = []
    val_scores = []
    
    for train_idx, val_idx in skf.split(X_scaled, y):
        X_train_fold = X_scaled[train_idx]
        X_val_fold = X_scaled[val_idx]
        y_train_fold = y.iloc[train_idx]
        y_val_fold = y.iloc[val_idx]
        
        # Model kopyası oluştur ve eğit
        model_clone = create_logistic_regression_model(
            C=model.C, 
            max_iter=model.max_iter,
            solver=model.solver
        )
        model_clone.fit(X_train_fold, y_train_fold)
        
        # Skorları hesapla
        train_score = model_clone.score(X_train_fold, y_train_fold)
        val_score = model_clone.score(X_val_fold, y_val_fold)
        
        train_scores.append(train_score)
        val_scores.append(val_score)
    
    results = {
        'train_scores': np.array(train_scores),
        'val_scores': np.array(val_scores),
        'train_mean': np.mean(train_scores),
        'val_mean': np.mean(val_scores),
        'train_std': np.std(train_scores),
        'val_std': np.std(val_scores)
    }
    
    return results


def detect_overfitting(
    train_scores: np.ndarray, 
    val_scores: np.ndarray, 
    threshold: float = 0.05
) -> Tuple[bool, float]:
    """
    Aşırı öğrenme (overfitting) tespit et.
    
    Eğitim ve validasyon skorları arasındaki fark threshold'dan büyükse
    aşırı öğrenme var kabul edilir.
    
    Args:
        train_scores: Eğitim skorları
        val_scores: Validasyon skorları
        threshold: Kabul edilebilir maksimum fark (default: 0.05 = %5)
    
    Returns:
        Tuple[bool, float]: (Aşırı öğrenme var mı?, Skor farkı)
    """
    train_mean = np.mean(train_scores)
    val_mean = np.mean(val_scores)
    
    gap = train_mean - val_mean
    
    is_overfitting = gap > threshold
    
    return is_overfitting, gap


def find_best_regularization(
    X: pd.DataFrame,
    y: pd.Series,
    cv: int = 5,
    C_values: Optional[List[float]] = None
) -> Tuple[float, Dict]:
    """
    En iyi regularization parametresini bul.
    
    Args:
        X: Özellikler
        y: Hedef değişken
        cv: Fold sayısı
        C_values: Denenecek C değerleri listesi
    
    Returns:
        Tuple[float, Dict]: (En iyi C değeri, Tüm sonuçlar)
    """
    if C_values is None:
        C_values = [0.001, 0.01, 0.1, 1.0, 10.0, 100.0]
    
    results = {}
    best_C = None
    best_val_score = -np.inf
    
    print("\n🔍 Regularization Parametresi Aranıyor...")
    print("-" * 50)
    print(f"{'C Değeri':>12} | {'Eğitim':>10} | {'Validasyon':>10} | {'Fark':>8}")
    print("-" * 50)
    
    for C in C_values:
        model = create_logistic_regression_model(C=C)
        cv_results = cross_validate_model(model, X, y, cv=cv)
        
        train_mean = cv_results['train_mean']
        val_mean = cv_results['val_mean']
        gap = train_mean - val_mean
        
        results[C] = cv_results
        
        # En iyi C'yi güncelle
        if val_mean > best_val_score:
            best_val_score = val_mean
            best_C = C
        
        print(f"{C:>12.4f} | {train_mean:>10.4f} | {val_mean:>10.4f} | {gap:>8.4f}")
    
    print("-" * 50)
    print(f"✓ En iyi C değeri: {best_C} (Validasyon: {best_val_score:.4f})")
    
    return best_C, results


def apply_regularization(
    X: pd.DataFrame,
    y: pd.Series,
    cv: int = 5
) -> Tuple[LogisticRegression, Dict]:
    """
    Aşırı öğrenme varsa regularization uygula.
    
    Args:
        X: Özellikler
        y: Hedef değişken
        cv: Fold sayısı
    
    Returns:
        Tuple: (En iyi model, Sonuçlar)
    """
    # Önce varsayılan model ile dene
    default_model = create_logistic_regression_model(C=1.0)
    default_cv = cross_validate_model(default_model, X, y, cv=cv)
    
    is_overfitting, gap = detect_overfitting(
        default_cv['train_scores'], 
        default_cv['val_scores']
    )
    
    if is_overfitting:
        print(f"\n⚠️ Aşırı öğrenme tespit edildi! (Eğitim-Validasyon farkı: {gap:.4f})")
        print("Regularization parametresi ayarlanıyor...")
        
        best_C, reg_results = find_best_regularization(X, y, cv=cv)
        best_model = create_logistic_regression_model(C=best_C)
        best_cv = reg_results[best_C]
        
        return best_model, {
            'overfitting_detected': True,
            'original_gap': gap,
            'best_C': best_C,
            'cv_results': best_cv,
            'regularization_search': reg_results
        }
    else:
        print(f"\n✓ Aşırı öğrenme tespit edilmedi. (Fark: {gap:.4f})")
        return default_model, {
            'overfitting_detected': False,
            'original_gap': gap,
            'best_C': 1.0,
            'cv_results': default_cv
        }


def train_final_model(
    model: LogisticRegression,
    X_train: pd.DataFrame,
    y_train: pd.Series
) -> Tuple[LogisticRegression, StandardScaler, float]:
    """
    Final modeli eğit.
    
    Args:
        model: Eğitilecek model
        X_train: Eğitim özellikleri
        y_train: Eğitim hedef değişkeni
    
    Returns:
        Tuple: (Eğitimli model, Scaler, Eğitim süresi saniye)
    """
    # Veriyi ölçeklendir
    scaler = StandardScaler()
    X_train_scaled = scaler.fit_transform(X_train)
    
    # Eğitim zamanını ölç
    start_time = time.time()
    model.fit(X_train_scaled, y_train)
    training_time = time.time() - start_time
    
    print(f"  Eğitim süresi: {training_time:.4f} saniye")
    
    return model, scaler, training_time
