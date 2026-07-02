"""Compare PCA+KMeans vs PCA+GMM with optimal n_comp/n_clusters."""
import pandas as pd
import numpy as np
from sklearn.decomposition import PCA
from sklearn.preprocessing import StandardScaler
from sklearn.cluster import KMeans
from sklearn.mixture import GaussianMixture
from sklearn.metrics import silhouette_score
import time

df = pd.read_parquet('artifacts/phase1/features_set_a.parquet')

meta = {'book_id','chunk_id','chunk_index','split','chunk_size_chars','source_text_length'}
feature_cols = [c for c in df.columns if c not in meta]
X = df[feature_cols].to_numpy(dtype=float)
X_scaled = StandardScaler().fit_transform(X)

rng = np.random.RandomState(42)
idx = rng.choice(len(X_scaled), size=min(10000, len(X_scaled)), replace=False)
X_sub = X_scaled[idx]

# PCA 3 bileşen
pca = PCA(n_components=3, random_state=42)
X_pca = pca.fit_transform(X_sub)
print(f"PCA 3 components: variance_explained={pca.explained_variance_ratio_.sum():.3f}")

candidate_k = list(range(5, 31))

print("\n=== PCA + KMeans ===")
for k in candidate_k:
    km = KMeans(n_clusters=k, random_state=42, n_init=5)
    labels = km.fit_predict(X_pca)
    sil = silhouette_score(X_pca, labels, random_state=42)
    print(f"  k={k}: silhouette={sil:.4f}")

print("\n=== PCA + GMM (GaussianMixture) ===")
for k in candidate_k:
    gm = GaussianMixture(n_components=k, random_state=42, n_init=3)
    labels = gm.fit_predict(X_pca)
    sil = silhouette_score(X_pca, labels, random_state=42)
    print(f"  k={k}: silhouette={sil:.4f}")

# BIC/AIC de GMM için
print("\n=== GMM BIC/AIC ===")
for k in candidate_k:
    gm = GaussianMixture(n_components=k, random_state=42, n_init=3)
    gm.fit(X_pca)
    print(f"  k={k}: BIC={gm.bic(X_pca):.0f} AIC={gm.aic(X_pca):.0f}")
