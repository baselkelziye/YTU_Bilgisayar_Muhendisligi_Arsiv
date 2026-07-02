import os
import pandas as pd
import numpy as np
import kagglehub
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.impute import KNNImputer
from sklearn.pipeline import Pipeline

def load_and_preprocess_data(seed=506, split_data=True):
    """
    Veriyi indirir, temizler ve ön işleme yapar.
    
    Args:
        seed: Random state için seed değeri (split_data=True ise kullanılır)
        split_data: True ise train-test split yapar, False ise tüm veriyi döner (K-Fold CV için)
    
    Returns:
        split_data=True: X_train, X_test, y_train, y_test
        split_data=False: X, y (tüm veri seti)
    """
    print("⏳ Veri seti hazırlanıyor...")
    
    path = kagglehub.dataset_download("uciml/pima-indians-diabetes-database")
    df = pd.read_csv(os.path.join(path, "diabetes.csv"))
    
    zero_features = ['Glucose', 'BloodPressure', 'SkinThickness', 'Insulin', 'BMI']
    df[zero_features] = df[zero_features].replace(0, np.nan)
    
    X = df.drop('Outcome', axis=1)
    y = df['Outcome']
    
    if split_data:
        X_train, X_test, y_train, y_test = train_test_split(
            X, y, test_size=0.20, random_state=seed, stratify=y)
        
        pipeline = Pipeline([
            ('scaler', StandardScaler()),
            ('imputer', KNNImputer(n_neighbors=5))
        ])
        
        X_train_processed = pipeline.fit_transform(X_train)
        X_test_processed = pipeline.transform(X_test)
        
        print(f"✅ Veri hazır! Eğitim Seti: {X_train_processed.shape}, Test Seti: {X_test_processed.shape}")
        return X_train_processed, X_test_processed, y_train, y_test
    else:
        print(f"✅ Veri hazır! Tüm Veri Seti: {X.shape}")
        return X, y
