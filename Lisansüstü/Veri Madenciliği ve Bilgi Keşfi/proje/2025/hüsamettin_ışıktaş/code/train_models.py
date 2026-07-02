import numpy as np
import os
from sklearn.linear_model import LogisticRegression
from sklearn.svm import SVC
from sklearn.naive_bayes import GaussianNB
from sklearn.ensemble import RandomForestClassifier
from sklearn.neural_network import MLPClassifier
from sklearn.metrics import accuracy_score, recall_score, precision_score, f1_score, confusion_matrix
from sklearn.model_selection import StratifiedKFold, cross_validate
from sklearn.preprocessing import StandardScaler
from sklearn.impute import KNNImputer
from sklearn.pipeline import Pipeline
from utils import log_experiment
from data_loader import load_and_preprocess_data
from plot import create_all_plots

# --- KLASÖR AYARLARI ---
output_dir = "plots"
if not os.path.exists(output_dir):
    os.makedirs(output_dir)
    print(f"📁 '{output_dir}' klasörü oluşturuldu.")

# --- AYARLAR ---
SEED = 42  # CV için sabit seed (tekrarlanabilirlik için)
N_FOLDS = 5  # 5-Fold Cross Validation

# --- VERİ YÜKLEME (K-Fold CV için tüm veri seti) ---
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

print(f"\n⚖️  Recall iyileştirmesi için class weights uygulanıyor...")
print(f"🔄 {N_FOLDS}-Fold Stratified Cross Validation kullanılıyor...\n")

# Modeller (optimize_models.py'den gelen en iyi parametreler)
base_models = {
    "Logistic Regression": LogisticRegression(random_state=SEED, max_iter=2000, 
                                             C=0.1, solver='liblinear', class_weight='balanced'),
    "SVM": SVC(kernel='rbf', C=1, gamma='auto', random_state=SEED,
               class_weight='balanced', probability=True),
    "Naïve Bayes": GaussianNB(),
    "Random Forest": RandomForestClassifier(n_estimators=200, min_samples_split=10, max_depth=10,
                                           random_state=SEED, class_weight='balanced'),
    "MLP Classifier": MLPClassifier(hidden_layer_sizes=(50, 50), activation='tanh', solver='adam', 
                                   alpha=0.0001, max_iter=2000, random_state=SEED, early_stopping=True)
}

results_data = []
confusion_matrices = {} 

# Stratified K-Fold (sınıf dağılımını korur)
skf = StratifiedKFold(n_splits=N_FOLDS, shuffle=True, random_state=SEED)

print("\n🚀 Model eğitimi başlıyor (K-Fold Cross Validation ile)...\n")

# --- DÖNGÜ İLE EĞİTİM VE KAYIT ---
for name, base_model in base_models.items():
    print(f"\n🔄 Değerlendiriliyor: {name}...")
    
    pipeline = Pipeline([
        ('scaler', StandardScaler()),
        ('imputer', KNNImputer(n_neighbors=5)),
        ('model', base_model)
    ])
    
    if name == "MLP Classifier":
        # MLP için sample_weight kullanımı (Pipeline içinde desteklenmiyor)
        cv_scores_acc, cv_scores_recall, cv_scores_precision, cv_scores_f1 = [], [], [], []
        fold_cms = []
        
        for train_idx, val_idx in skf.split(X, y):
            X_train_fold, X_val_fold = X.iloc[train_idx], X.iloc[val_idx]
            y_train_fold, y_val_fold = y.iloc[train_idx], y.iloc[val_idx]
            
            prep_pipeline = Pipeline([
                ('scaler', StandardScaler()),
                ('imputer', KNNImputer(n_neighbors=5))
            ])
            X_train_processed = prep_pipeline.fit_transform(X_train_fold)
            X_val_processed = prep_pipeline.transform(X_val_fold)
            
            mlp_sample_weights = np.where(y_train_fold == 1, 1.3, 1.0)
            model = base_model
            model.fit(X_train_processed, y_train_fold, sample_weight=mlp_sample_weights)
            y_pred = model.predict(X_val_processed)
            
            # Metrikler
            cv_scores_acc.append(accuracy_score(y_val_fold, y_pred))
            cv_scores_recall.append(recall_score(y_val_fold, y_pred))
            cv_scores_precision.append(precision_score(y_val_fold, y_pred))
            cv_scores_f1.append(f1_score(y_val_fold, y_pred))
            fold_cms.append(confusion_matrix(y_val_fold, y_pred))
        
        acc_mean = np.mean(cv_scores_acc) * 100
        acc_std = np.std(cv_scores_acc) * 100
        recall_mean = np.mean(cv_scores_recall) * 100
        recall_std = np.std(cv_scores_recall) * 100
        precision_mean = np.mean(cv_scores_precision) * 100
        precision_std = np.std(cv_scores_precision) * 100
        f1_mean = np.mean(cv_scores_f1) * 100
        f1_std = np.std(cv_scores_f1) * 100
        confusion_matrices[name] = np.mean(fold_cms, axis=0).astype(int)
        
    else:
        # Diğer modeller için cross_validate kullan
        scoring = {
            'accuracy': 'accuracy',
            'recall': 'recall',
            'precision': 'precision',
            'f1': 'f1'
        }
        
        cv_results = cross_validate(
            pipeline, X, y,
            cv=skf,
            scoring=scoring,
            return_train_score=False,
            n_jobs=-1
        )
        
        acc_mean = np.mean(cv_results['test_accuracy']) * 100
        acc_std = np.std(cv_results['test_accuracy']) * 100
        recall_mean = np.mean(cv_results['test_recall']) * 100
        recall_std = np.std(cv_results['test_recall']) * 100
        precision_mean = np.mean(cv_results['test_precision']) * 100
        precision_std = np.std(cv_results['test_precision']) * 100
        f1_mean = np.mean(cv_results['test_f1']) * 100
        f1_std = np.std(cv_results['test_f1']) * 100
        
        # Confusion matrix için tüm fold'ların ortalamasını al
        fold_cms = []
        for train_idx, val_idx in skf.split(X, y):
            X_train_fold = X.iloc[train_idx]
            X_val_fold = X.iloc[val_idx]
            y_train_fold = y.iloc[train_idx]
            y_val_fold = y.iloc[val_idx]
            
            pipeline.fit(X_train_fold, y_train_fold)
            y_pred = pipeline.predict(X_val_fold)
            fold_cms.append(confusion_matrix(y_val_fold, y_pred))
        
        confusion_matrices[name] = np.mean(fold_cms, axis=0).astype(int)
    
    results_data.append({
        "Model": name, 
        "Accuracy": f"{acc_mean:.2f} ± {acc_std:.2f}",
        "Sensitivity (Recall)": f"{recall_mean:.2f} ± {recall_std:.2f}",
        "Precision": f"{precision_mean:.2f} ± {precision_std:.2f}",
        "F1-Score": f"{f1_mean:.2f} ± {f1_std:.2f}"
    })
    
    print(f"   ✅ {N_FOLDS}-Fold CV Sonuçları:")
    print(f"      Accuracy: {acc_mean:.2f}% ± {acc_std:.2f}%")
    print(f"      Recall:   {recall_mean:.2f}% ± {recall_std:.2f}%")
    print(f"      Precision: {precision_mean:.2f}% ± {precision_std:.2f}%")
    print(f"      F1-Score: {f1_mean:.2f}% ± {f1_std:.2f}%")
    
    log_experiment(
        model_name=name,
        accuracy=acc_mean/100,
        sensitivity=recall_mean/100,
        seed=SEED,
        notes=f"{N_FOLDS}-Fold CV (Mean ± Std)"
    )

create_all_plots(results_data, confusion_matrices, output_dir)
print(f"\n🎉 Tüm modeller eğitildi. Grafikler '{output_dir}' klasörüne kaydedildi!")
