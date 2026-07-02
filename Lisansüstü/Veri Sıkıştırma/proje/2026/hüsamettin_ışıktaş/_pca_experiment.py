"""Quick PCA experiment - optimized."""
import pandas as pd
import numpy as np
from sklearn.decomposition import PCA
from sklearn.preprocessing import StandardScaler
from sklearn.cluster import KMeans
from sklearn.metrics import silhouette_score
import time

df = pd.read_parquet('artifacts/phase1/features_set_a.parquet')

meta = {'book_id','chunk_id','chunk_index','split','chunk_size_chars','source_text_length'}
feature_cols = [c for c in df.columns if c not in meta]
X = df[feature_cols].to_numpy(dtype=float)
X_scaled = StandardScaler().fit_transform(X)

# Subsample for speed - use 10K random samples
rng = np.random.RandomState(42)
idx = rng.choice(len(X_scaled), size=min(10000, len(X_scaled)), replace=False)
X_sub = X_scaled[idx]

# Only test a few K values around the expected sweet spot
candidate_k = [8, 10, 12, 15, 18, 20, 25, 30, 35, 40]

results = []

# No PCA baseline
print("=== NO PCA ===")
t0 = time.time()
for k in candidate_k:
    km = KMeans(n_clusters=k, random_state=42, n_init=5)
    labels = km.fit_predict(X_sub)
    sil = silhouette_score(X_sub, labels, random_state=42)
    print(f"  k={k}: silhouette={sil:.4f}")
print(f"  took {time.time()-t0:.1f}s")
print()

# PCA denemeleri
for n_comp in [3, 5, 7, 10, 15]:
    print(f"=== PCA n_comp={n_comp} ===")
    t0 = time.time()
    pca = PCA(n_components=n_comp, random_state=42)
    X_pca = pca.fit_transform(X_sub)
    # variance explained
    vr = pca.explained_variance_ratio_.sum()
    for k in candidate_k:
        km = KMeans(n_clusters=k, random_state=42, n_init=5)
        labels = km.fit_predict(X_pca)
        sil = silhouette_score(X_pca, labels, random_state=42)
        print(f"  k={k}: silhouette={sil:.4f}")
    print(f"  var_explained={vr:.3f}, took {time.time()-t0:.1f}s")
    print()
