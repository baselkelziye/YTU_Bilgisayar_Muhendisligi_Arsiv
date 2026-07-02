import numpy as np
import pandas as pd
from sklearn.model_selection import GridSearchCV, ParameterGrid, StratifiedKFold, cross_validate
from sklearn.linear_model import LogisticRegression
from sklearn.svm import SVC
from sklearn.ensemble import RandomForestClassifier
from sklearn.neural_network import MLPClassifier
from sklearn.metrics import accuracy_score, recall_score, precision_score, f1_score
from sklearn.preprocessing import StandardScaler
from sklearn.impute import KNNImputer
from sklearn.pipeline import Pipeline
from data_loader import load_and_preprocess_data

# --- VERİ YÜKLEME (K-Fold CV için tüm veri seti) ---
SEED = 42  # CV için sabit seed
X, y = load_and_preprocess_data(seed=SEED, split_data=False)

# Sınıf dağılımını kontrol et
class_counts = np.bincount(y)
n_class_0 = class_counts[0]
n_class_1 = class_counts[1]
total = len(y)
print(f"\n📊 Tüm Veri Seti Sınıf Dağılımı:")
print(f"   Class 0 (Sağlıklı): {n_class_0} ({n_class_0/total*100:.1f}%)")
print(f"   Class 1 (Diyabet): {n_class_1} ({n_class_1/total*100:.1f}%)")
print(f"   Dengesizlik Oranı: {n_class_0/n_class_1:.2f}:1")

MLP_BALANCED_WEIGHT = 1.3
N_FOLDS = 5

print("\n🔍 Hiperparametre Optimizasyonu Başlıyor (Class Weights ile)...\n")

# --- PARAMETRE GRIDLERİ (CLASS WEIGHTS İLE) ---
param_grids = {
    "Logistic Regression": {
        'model': LogisticRegression(random_state=SEED, max_iter=2000, class_weight='balanced'),
        'params': {
            'C': [0.01, 0.1, 1, 10, 100],
            'solver': ['liblinear', 'lbfgs']
        },
        'use_sample_weight': False
    },
    "SVM": {
        'model': SVC(random_state=SEED, class_weight='balanced', probability=True),
        'params': {
            'C': [0.1, 1, 10, 100],
            'kernel': ['rbf', 'linear', 'poly'],
            'gamma': ['scale', 'auto']
        },
        'use_sample_weight': False
    },
    "Random Forest": {
        'model': RandomForestClassifier(random_state=SEED, class_weight='balanced'),
        'params': {
            'n_estimators': [50, 100, 200],
            'max_depth': [None, 10, 20, 30],
            'min_samples_split': [2, 5, 10]
        },
        'use_sample_weight': False
    },
    "MLP Classifier": {
        'model': MLPClassifier(random_state=SEED, max_iter=2000, early_stopping=True),
        'params': {
            'hidden_layer_sizes': [(50,), (100,), (50, 50), (100, 50)],
            'activation': ['tanh', 'relu'],
            'solver': ['adam', 'sgd'],
            'alpha': [0.0001, 0.05]
        },
        'use_sample_weight': True  # MLP için sample_weight kullan
    }
}

best_results = []
skf = StratifiedKFold(n_splits=N_FOLDS, shuffle=True, random_state=SEED)


def _create_preprocessing_pipeline():
    """Preprocessing pipeline oluşturur"""
    return Pipeline([
        ('scaler', StandardScaler()),
        ('imputer', KNNImputer(n_neighbors=5))
    ])


def _evaluate_mlp_model(X, y, model, params, skf):
    """MLP modelini sample_weight ile değerlendirir"""
    cv_scores = []
    for train_idx, val_idx in skf.split(X, y):
        X_train_fold, X_val_fold = X.iloc[train_idx], X.iloc[val_idx]
        y_train_fold, y_val_fold = y.iloc[train_idx], y.iloc[val_idx]
        
        prep_pipeline = _create_preprocessing_pipeline()
        X_train_processed = prep_pipeline.fit_transform(X_train_fold)
        X_val_processed = prep_pipeline.transform(X_val_fold)
        
        model.set_params(**params)
        sample_weights = np.where(y_train_fold == 1, MLP_BALANCED_WEIGHT, 1.0)
        model.fit(X_train_processed, y_train_fold, sample_weight=sample_weights)
        y_pred = model.predict(X_val_processed)
        cv_scores.append(f1_score(y_val_fold, y_pred))
    return np.mean(cv_scores)

for name, config in param_grids.items():
    print(f"⚙️  Optimize ediliyor: {name}...")
    
    if config.get('use_sample_weight', False):
        # MLP için manuel grid search (sample_weight kullanımı)
        param_combinations = list(ParameterGrid(config['params']))
        print(f"   🔍 {len(param_combinations)} parametre kombinasyonu test ediliyor...")
        
        best_score, best_params = -np.inf, None
        for params in param_combinations:
            score = _evaluate_mlp_model(X, y, config['model'], params, skf)
            if score > best_score:
                best_score, best_params = score, params
        
        print(f"   🏆 En İyi Parametreler: {best_params}")
        print(f"   📈 En İyi CV F1 Skoru: {best_score:.4f}")
        
        # Final metrikleri hesapla
        cv_scores_acc, cv_scores_recall, cv_scores_precision, cv_scores_f1 = [], [], [], []
        for train_idx, val_idx in skf.split(X, y):
            X_train_fold, X_val_fold = X.iloc[train_idx], X.iloc[val_idx]
            y_train_fold, y_val_fold = y.iloc[train_idx], y.iloc[val_idx]
            
            prep_pipeline = _create_preprocessing_pipeline()
            X_train_processed = prep_pipeline.fit_transform(X_train_fold)
            X_val_processed = prep_pipeline.transform(X_val_fold)
            
            model = config['model']
            model.set_params(**best_params)
            sample_weights = np.where(y_train_fold == 1, MLP_BALANCED_WEIGHT, 1.0)
            model.fit(X_train_processed, y_train_fold, sample_weight=sample_weights)
            y_pred = model.predict(X_val_processed)
            
            cv_scores_acc.append(accuracy_score(y_val_fold, y_pred))
            cv_scores_recall.append(recall_score(y_val_fold, y_pred))
            cv_scores_precision.append(precision_score(y_val_fold, y_pred))
            cv_scores_f1.append(f1_score(y_val_fold, y_pred))
        
        acc_mean = np.mean(cv_scores_acc)
        recall_mean = np.mean(cv_scores_recall)
        precision_mean = np.mean(cv_scores_precision)
        f1_mean = np.mean(cv_scores_f1)
        
    else:
        # Diğer modeller için GridSearchCV
        pipeline = Pipeline([
            ('scaler', StandardScaler()),
            ('imputer', KNNImputer(n_neighbors=5)),
            ('model', config['model'])
        ])
        
        param_grid_pipeline = {f'model__{k}': v for k, v in config['params'].items()}
        grid = GridSearchCV(pipeline, param_grid_pipeline, cv=skf, scoring='f1', 
                          n_jobs=-1, verbose=1)
        grid.fit(X, y)
        
        print(f"   🏆 En İyi Parametreler: {grid.best_params_}")
        print(f"   📈 En İyi CV F1 Skoru: {grid.best_score_:.4f}")
        
        cv_results = cross_validate(grid.best_estimator_, X, y, cv=skf,
                                   scoring=['accuracy', 'recall', 'precision', 'f1'],
                                   return_train_score=False)
        
        acc_mean = np.mean(cv_results['test_accuracy'])
        recall_mean = np.mean(cv_results['test_recall'])
        precision_mean = np.mean(cv_results['test_precision'])
        f1_mean = np.mean(cv_results['test_f1'])
        best_params = grid.best_params_
    
    print(f"   📊 {N_FOLDS}-Fold CV Ortalama Metrikleri:")
    print(f"      Accuracy: %{acc_mean*100:.2f}")
    print(f"      Recall (Sensitivity): %{recall_mean*100:.2f}")
    print(f"      Precision: %{precision_mean*100:.2f}")
    print(f"      F1-Score: %{f1_mean*100:.2f}\n")
    
    best_results.append({
        "Model": name,
        "Best Params": str(best_params),
        "CV F1 Score (Mean)": f1_mean,
        "CV Accuracy (Mean)": acc_mean,
        "CV Recall (Mean)": recall_mean,
        "CV Precision (Mean)": precision_mean
    })

# Sonuçları Kaydet
df_results = pd.DataFrame(best_results)
df_results.to_csv("optimization_results.csv", index=False)
print("✅ Optimizasyon tamamlandı! Sonuçlar 'optimization_results.csv' dosyasına kaydedildi.")
