"""
Hiperparametre Optimizasyonu Scripti

Bu script:
1. Bagging, Random Subspace ve Random Forest için hiperparametre optimizasyonu yapar
2. Her yöntem için 2 hiperparametre optimize edilir
3. En iyi parametreleri ve performansı raporlar
"""

import argparse
import json
import os
import sys
import time
from datetime import datetime

import numpy as np

# Paralel işlemlerde stdout buffering sorununu önlemek için
# stdout'u unbuffered yapıyoruz (tee ile kullanım için önemli)
# Python 3.7+ için reconfigure, eski versiyonlar için flush kullanıyoruz
if hasattr(sys.stdout, 'reconfigure'):
    sys.stdout.reconfigure(line_buffering=True)
else:
    # Eski Python versiyonları için: her print'ten sonra flush yapılacak
    # Bunu print fonksiyonunu override ederek yapabiliriz ama şimdilik bu yeterli
    pass
from sklearn.ensemble import BaggingClassifier, RandomForestClassifier
from sklearn.metrics import accuracy_score, f1_score
from sklearn.model_selection import GridSearchCV
from sklearn.tree import DecisionTreeClassifier

RANDOM_SEED = 42
DATASET_DIR = "dataset"
ARTIFACTS_DIR = "artifacts"
DEFAULT_CV_FOLDS = 3  # Cross-validation varsayılanı
N_JOBS = 10

# Decision Tree parametreleri (ağaç derinliğini sınırlamak için - performans için kritik!)
# NOT: max_depth=30 çok yüksek olabilir, optimizasyon için 20'ye düşürüldü
MAX_DEPTH = 20          # Maksimum ağaç derinliği (optimizasyon için düşürüldü)
MIN_SAMPLES_SPLIT = 2   # Bir node'u split etmek için minimum örnek sayısı
MIN_SAMPLES_LEAF = 1    # Bir leaf node'da minimum örnek sayısı

EMBED_TYPES = ['title', 'abstract', 'concat']
EMBED_NAMES = {'title': 'Başlık', 'abstract': 'Özet', 'concat': 'Birleştirilmiş'}

DEFAULT_PARAM_GRIDS = {
    'random_forest': {
        'n_estimators': [50, 100, 200],
        'max_depth': [10, 20, 30]
    },
    'bagging': {
        'n_estimators': [50, 100, 200],
        'max_samples': [0.5, 0.7, 1.0]
    },
    'random_subspace': {
        'n_estimators': [50, 100, 200],
        'max_features': [0.3, 0.5, 0.7]
    }
}

QUICK_PARAM_GRIDS = {
    'random_forest': {
        'n_estimators': [50, 100],
        'max_depth': [10, 20]
    },
    'bagging': {
        'n_estimators': [50, 100],
        'max_samples': [0.5, 0.7]
    },
    'random_subspace': {
        'n_estimators': [50, 100],
        'max_features': [0.3, 0.5]
    }
}


def parse_args():
    """Komut satırı argümanlarını okur."""
    parser = argparse.ArgumentParser(
        description="Bagging, Random Subspace ve Random Forest için hiperparametre optimizasyonu"
    )
    parser.add_argument(
        "--mode",
        choices=["full", "quick"],
        default="full",
        help="quick: daha küçük grid ve varsayılan olarak daha az CV fold'u kullanır"
    )
    parser.add_argument(
        "--cv-folds",
        type=int,
        default=DEFAULT_CV_FOLDS,
        help="Grid Search için fold sayısı. quick modda belirtilmezse 2'ye düşer."
    )
    parser.add_argument(
        "--datasets",
        nargs="+",
        choices=EMBED_TYPES,
        default=EMBED_TYPES,
        help="Hangi embedding setleri üzerinde çalışılacağını seçer"
    )
    parser.add_argument(
        "--methods",
        nargs="+",
        choices=["random_forest", "bagging", "random_subspace"],
        default=["random_forest", "bagging", "random_subspace"],
        help="Çalıştırılacak optimizasyon yöntemleri"
    )
    parser.add_argument(
        "--dataset-dir",
        default=DATASET_DIR,
        help="Embedding .npz dosyalarının bulunduğu dizin"
    )
    parser.add_argument(
        "--artifacts-dir",
        default=ARTIFACTS_DIR,
        help="Çıktı dosyalarının kaydedileceği dizin"
    )
    return parser.parse_args()


def load_embedding_data(embed_type, dataset_dir):
    """Embedding verisetini yükler."""
    train_file = os.path.join(dataset_dir, f"train_{embed_type}_embeddings.npz")
    test_file = os.path.join(dataset_dir, f"test_{embed_type}_embeddings.npz")
    train_data = np.load(train_file)
    test_data = np.load(test_file)
    return (train_data['embeddings'], train_data['years'],
            test_data['embeddings'], test_data['years'])


def optimize_random_forest(X_train, y_train, X_test, y_test, cv_folds, param_grid):
    """
    Random Forest hiperparametre optimizasyonu.
    Optimize edilen parametreler: n_estimators, max_depth
    """
    print("\n" + "="*50)
    print("RANDOM FOREST OPTİMİZASYONU")
    print("="*50)
    
    model = RandomForestClassifier(random_state=RANDOM_SEED, n_jobs=N_JOBS)
    
    print(f"Grid Search başlatılıyor... (CV={cv_folds})")
    print(f"Parametre alanı: {param_grid}")
    
    # verbose=1: sadece tamamlanan işlemleri gösterir (paralel işlemlerde daha temiz çıktı)
    # verbose=2: her fit işlemini gösterir ama paralel işlemlerde çıktılar karışabilir
    grid_search = GridSearchCV(
        model, param_grid, cv=cv_folds, scoring='accuracy',
        verbose=1, n_jobs=-1  # GridSearchCV seviyesinde paralelleştirme
    )
    
    start_time = time.time()
    grid_search.fit(X_train, y_train)
    elapsed_time = time.time() - start_time
    print(f"\n⏱️  Optimizasyon süresi: {elapsed_time:.1f} saniye ({elapsed_time/60:.1f} dakika)")
    
    # En iyi model ile test
    best_model = grid_search.best_estimator_
    y_pred = best_model.predict(X_test)
    test_acc = accuracy_score(y_test, y_pred)
    test_f1 = f1_score(y_test, y_pred, average='macro')
    
    results = {
        'best_params': grid_search.best_params_,
        'best_cv_score': grid_search.best_score_,
        'test_accuracy': test_acc,
        'test_f1_macro': test_f1,
        'all_results': []
    }
    
    # Tüm sonuçları kaydet
    for params, mean_score, std_score in zip(
        grid_search.cv_results_['params'],
        grid_search.cv_results_['mean_test_score'],
        grid_search.cv_results_['std_test_score']
    ):
        results['all_results'].append({
            'params': params,
            'mean_cv_score': mean_score,
            'std_cv_score': std_score
        })
    
    print(f"\n✓ En İyi Parametreler: {grid_search.best_params_}")
    print(f"✓ En İyi CV Skoru: {grid_search.best_score_:.4f}")
    print(f"✓ Test Accuracy: {test_acc:.4f}")
    print(f"✓ Test F1-Macro: {test_f1:.4f}")
    
    return results


def optimize_bagging(X_train, y_train, X_test, y_test, cv_folds, param_grid):
    """
    Bagging hiperparametre optimizasyonu.
    Optimize edilen parametreler: n_estimators, max_samples
    """
    print("\n" + "="*50)
    print("BAGGING OPTİMİZASYONU")
    print("="*50)
    
    # ÖNEMLİ: max_depth parametresi olmadan ağaçlar çok derin olur ve optimizasyon çok uzun sürer!
    # Nested parallelism'i önlemek için base estimator'da n_jobs kullanmıyoruz
    base = DecisionTreeClassifier(
        max_depth=MAX_DEPTH,
        min_samples_split=MIN_SAMPLES_SPLIT,
        min_samples_leaf=MIN_SAMPLES_LEAF,
        random_state=RANDOM_SEED
    )
    # GridSearchCV seviyesinde paralelleştirme yapacağız, bu yüzden BaggingClassifier'da n_jobs=1
    # Aksi halde nested parallelism sorunu olur ve performans düşer
    model = BaggingClassifier(estimator=base, random_state=RANDOM_SEED, n_jobs=1)
    
    print(f"Grid Search başlatılıyor... (CV={cv_folds})")
    print(f"Parametre alanı: {param_grid}")
    print(f"max_depth={MAX_DEPTH} ile DecisionTree kullanılıyor")
    
    # GridSearchCV seviyesinde paralelleştirme yapıyoruz
    # n_jobs=-1 tüm CPU'ları kullanır, ama nested parallelism'i önlemek için dikkatli olmalıyız
    # verbose=1: paralel işlemlerde daha temiz çıktı (verbose=2 çıktıları karıştırabilir)
    grid_search = GridSearchCV(
        model, param_grid, cv=cv_folds, scoring='accuracy', verbose=1, n_jobs=-1
    )
    
    import time
    start_time = time.time()
    grid_search.fit(X_train, y_train)
    elapsed_time = time.time() - start_time
    print(f"\n⏱️  Optimizasyon süresi: {elapsed_time:.1f} saniye ({elapsed_time/60:.1f} dakika)")
    
    best_model = grid_search.best_estimator_
    y_pred = best_model.predict(X_test)
    test_acc = accuracy_score(y_test, y_pred)
    test_f1 = f1_score(y_test, y_pred, average='macro')
    
    results = {
        'best_params': grid_search.best_params_,
        'best_cv_score': grid_search.best_score_,
        'test_accuracy': test_acc,
        'test_f1_macro': test_f1,
        'all_results': []
    }
    
    for params, mean_score, std_score in zip(
        grid_search.cv_results_['params'],
        grid_search.cv_results_['mean_test_score'],
        grid_search.cv_results_['std_test_score']
    ):
        results['all_results'].append({
            'params': {k: v for k, v in params.items()},
            'mean_cv_score': mean_score,
            'std_cv_score': std_score
        })
    
    print(f"\n✓ En İyi Parametreler: {grid_search.best_params_}")
    print(f"✓ En İyi CV Skoru: {grid_search.best_score_:.4f}")
    print(f"✓ Test Accuracy: {test_acc:.4f}")
    print(f"✓ Test F1-Macro: {test_f1:.4f}")
    
    return results


def optimize_random_subspace(X_train, y_train, X_test, y_test, cv_folds, param_grid):
    """
    Random Subspace hiperparametre optimizasyonu.
    Optimize edilen parametreler: n_estimators, max_features
    """
    print("\n" + "="*50)
    print("RANDOM SUBSPACE OPTİMİZASYONU")
    print("="*50)
    
    # ÖNEMLİ: max_depth parametresi olmadan ağaçlar çok derin olur ve optimizasyon çok uzun sürer!
    base = DecisionTreeClassifier(
        max_depth=MAX_DEPTH,
        min_samples_split=MIN_SAMPLES_SPLIT,
        min_samples_leaf=MIN_SAMPLES_LEAF,
        random_state=RANDOM_SEED
    )
    # GridSearchCV seviyesinde paralelleştirme yapacağız, bu yüzden BaggingClassifier'da n_jobs=1
    model = BaggingClassifier(
        estimator=base, bootstrap=False, bootstrap_features=True,
        random_state=RANDOM_SEED, n_jobs=1
    )
    
    print(f"Grid Search başlatılıyor... (CV={cv_folds})")
    print(f"Parametre alanı: {param_grid}")
    print(f"max_depth={MAX_DEPTH} ile DecisionTree kullanılıyor")
    
    # GridSearchCV seviyesinde paralelleştirme yapıyoruz
    # verbose=1: paralel işlemlerde daha temiz çıktı (verbose=2 çıktıları karıştırabilir)
    grid_search = GridSearchCV(
        model, param_grid, cv=cv_folds, scoring='accuracy', verbose=1, n_jobs=-1
    )
    
    start_time = time.time()
    grid_search.fit(X_train, y_train)
    elapsed_time = time.time() - start_time
    print(f"\n⏱️  Optimizasyon süresi: {elapsed_time:.1f} saniye ({elapsed_time/60:.1f} dakika)")
    
    best_model = grid_search.best_estimator_
    y_pred = best_model.predict(X_test)
    test_acc = accuracy_score(y_test, y_pred)
    test_f1 = f1_score(y_test, y_pred, average='macro')
    
    results = {
        'best_params': grid_search.best_params_,
        'best_cv_score': grid_search.best_score_,
        'test_accuracy': test_acc,
        'test_f1_macro': test_f1,
        'all_results': []
    }
    
    for params, mean_score, std_score in zip(
        grid_search.cv_results_['params'],
        grid_search.cv_results_['mean_test_score'],
        grid_search.cv_results_['std_test_score']
    ):
        results['all_results'].append({
            'params': {k: v for k, v in params.items()},
            'mean_cv_score': mean_score,
            'std_cv_score': std_score
        })
    
    print(f"\n✓ En İyi Parametreler: {grid_search.best_params_}")
    print(f"✓ En İyi CV Skoru: {grid_search.best_score_:.4f}")
    print(f"✓ Test Accuracy: {test_acc:.4f}")
    print(f"✓ Test F1-Macro: {test_f1:.4f}")
    
    return results


def save_optimization_results(all_results, output_dir, cv_folds, selected_methods, selected_datasets):
    """Optimizasyon sonuçlarını kaydeder."""
    os.makedirs(output_dir, exist_ok=True)
    
    # JSON kaydet
    json_results = {}
    for method, datasets in all_results.items():
        json_results[method] = {}
        for dataset, results in datasets.items():
            json_results[method][dataset] = {
                'best_params': {k: (v if v is not None else "None") 
                               for k, v in results['best_params'].items()},
                'best_cv_score': float(results['best_cv_score']),
                'test_accuracy': float(results['test_accuracy']),
                'test_f1_macro': float(results['test_f1_macro'])
            }
    
    with open(os.path.join(output_dir, "optimization_results.json"), "w") as f:
        json.dump(json_results, f, indent=2)
    
    # Markdown rapor oluştur
    report = """# Hiperparametre Optimizasyonu Sonuçları

## Özet

Bu rapor, Bagging, Random Subspace ve Random Forest algoritmaları için yapılan 
hiperparametre optimizasyonunun sonuçlarını içermektedir.

### Optimize Edilen Parametreler

| Algoritma | Parametre 1 | Parametre 2 |
|-----------|-------------|-------------|
| Random Forest | n_estimators | max_depth |
| Bagging | n_estimators | max_samples |
| Random Subspace | n_estimators | max_features |

---

"""
    
    for method in selected_methods:
        if method not in all_results:
            continue
        method_name = method.replace('_', ' ').title()
        report += f"## {method_name}\n\n"
        report += "| Veriseti | En İyi Parametreler | CV Skoru | Test Acc | Test F1 |\n"
        report += "|----------|---------------------|----------|----------|--------|\n"
        
        for dataset in selected_datasets:
            dataset_results = all_results.get(method, {})
            if dataset not in dataset_results:
                continue
            r = dataset_results[dataset]
            params_str = ", ".join([f"{k}={v}" for k, v in r['best_params'].items()])
            report += f"| {dataset} | {params_str} | {r['best_cv_score']:.4f} | {r['test_accuracy']:.4f} | {r['test_f1_macro']:.4f} |\n"
        
        report += "\n"
    
    report += """---

## Sonuç ve Öneriler

Bu optimizasyon sonuçlarına göre, her algoritma için önerilen hiperparametreler 
ilgili run scriptlerinde kullanılabilir.

**Not**: Grid Search ile {}-fold cross-validation kullanılmıştır.
""".format(cv_folds)
    
    with open(os.path.join(output_dir, "optimization_report.md"), "w", encoding="utf-8") as f:
        f.write(report)
    
    print(f"\n✓ Sonuçlar kaydedildi: {output_dir}/")


def main():
    args = parse_args()
    selected_methods = args.methods
    selected_datasets = args.datasets
    param_grids = QUICK_PARAM_GRIDS if args.mode == "quick" else DEFAULT_PARAM_GRIDS
    
    cv_folds = args.cv_folds
    if args.mode == "quick" and args.cv_folds == DEFAULT_CV_FOLDS:
        cv_folds = 2
    
    print("=" * 60)
    print("HİPERPARAMETRE OPTİMİZASYONU")
    print("=" * 60)
    print(f"Mod: {args.mode} | CV folds: {cv_folds} | Yöntemler: {', '.join(selected_methods)}")
    print(f"Veri setleri: {', '.join(selected_datasets)}")
    
    timestamp = datetime.now().strftime("%Y-%m-%d_%H%M%S")
    output_dir = os.path.join(args.artifacts_dir, f"{timestamp}_optimization")
    
    method_functions = {
        'random_forest': optimize_random_forest,
        'bagging': optimize_bagging,
        'random_subspace': optimize_random_subspace
    }
    
    all_results = {method: {} for method in selected_methods}
    
    for embed_type in selected_datasets:
        print(f"\n{'#'*60}")
        print(f"# VERİSETİ: {EMBED_NAMES[embed_type].upper()}")
        print(f"{'#'*60}")
        
        print("\nVeri yükleniyor...")
        X_train, y_train, X_test, y_test = load_embedding_data(embed_type, args.dataset_dir)
        print(f"{embed_type.upper()} - Train: {X_train.shape}, Test: {X_test.shape}")
        
        for method in selected_methods:
            print(f"\n>>> {method.replace('_', ' ').title()} ({embed_type})")
            func = method_functions[method]
            all_results[method][embed_type] = func(
                X_train, y_train, X_test, y_test, cv_folds, param_grids[method]
            )
    
    # Sonuçları kaydet
    save_optimization_results(
        all_results, output_dir, cv_folds, selected_methods, selected_datasets
    )
    
    # Özet yazdır
    print("\n" + "=" * 60)
    print("OPTİMİZASYON SONUÇLARI ÖZETİ")
    print("=" * 60)
    
    for method in selected_methods:
        print(f"\n{method.upper().replace('_', ' ')}:")
        print("-" * 50)
        for dataset in selected_datasets:
            if dataset not in all_results[method]:
                continue
            r = all_results[method][dataset]
            params = ", ".join([f"{k}={v}" for k, v in r['best_params'].items()])
            print(f"  {EMBED_NAMES[dataset]:<15}: {params}")
            print(f"                   Test Acc: {r['test_accuracy']:.4f}, F1: {r['test_f1_macro']:.4f}")


if __name__ == "__main__":
    main()

