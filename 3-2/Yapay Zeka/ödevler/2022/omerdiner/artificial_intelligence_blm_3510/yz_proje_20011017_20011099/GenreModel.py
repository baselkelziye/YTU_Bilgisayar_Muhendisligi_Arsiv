import pandas as pd
from sklearn.compose import ColumnTransformer
from sklearn.pipeline import FunctionTransformer, Pipeline
from sklearn.preprocessing import LabelEncoder
from sklearn.model_selection import GridSearchCV
from sklearn.linear_model import LogisticRegression
from sklearn.svm import SVC
from sklearn.neural_network import MLPClassifier
from sklearn.neighbors import KNeighborsClassifier
from sklearn.ensemble import RandomForestClassifier, GradientBoostingClassifier
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score
from sklearn.feature_extraction.text import TfidfVectorizer
import numpy as np
import re
from nltk.corpus import stopwords
from nltk.stem import WordNetLemmatizer
from nltk.tokenize import word_tokenize
import nltk
import time
from scipy.sparse import vstack

nltk.download('stopwords')
nltk.download('punkt')
nltk.download('wordnet')

# Metin ön işleme fonksiyonu
def preprocess_text(text):
    # Küçük harfe dönüştür
    text = text.lower()
    # Sayıları kaldır
    text = re.sub(r'\d+', '', text)
    # Noktalama işaretlerini kaldır
    text = re.sub(r'\W+', ' ', text)
    # Satır sonu karakterlerini kaldır
    text = text.replace('\n', ' ')
    # Tokenizasyon
    words = word_tokenize(text)
    # Stopwords'leri kaldır
    words = [word for word in words if word not in stopwords.words('english')]
    # Lemmatization
    lemmatizer = WordNetLemmatizer()
    words = [lemmatizer.lemmatize(word) for word in words]
    return ' '.join(words)

# Verileri oku
real_data_train = pd.read_excel('kaggleset500.xlsx')
real_data_test = pd.read_excel('kaggleset250.xlsx')
synthetic_data = pd.read_excel('CleanedSyntheticData.xlsx')

# Gerçek ve sentetik verileri ayır
X_real_train = real_data_train['Lyrics']
y_real_train = real_data_train['Genre']
X_real_test = real_data_test['Lyrics']
y_real_test = real_data_test['Genre']
X_synthetic = synthetic_data['Lyrics']
y_synthetic = synthetic_data['Genre']

# LabelEncoder kullanarak türleri sayısal değerlere çevir
label_encoder = LabelEncoder()
y_real_train = label_encoder.fit_transform(y_real_train)
y_real_test = label_encoder.transform(y_real_test)
y_synthetic = label_encoder.transform(y_synthetic)

# Metin ön işleme ve TF-IDF dönüştürücü
preprocessor = ColumnTransformer(
    transformers=[
        ('lyrics', Pipeline([
            ('preprocess', FunctionTransformer(lambda x: x.apply(preprocess_text))),
            ('tfidf', TfidfVectorizer(max_features=15000, ngram_range=(1, 3)))
        ]), 'Lyrics')
    ],
    remainder='drop'
)

# Tüm eğitim verilerini birleştir ve TF-IDF vektörleştiricisi ile dönüştür
all_train_lyrics = pd.concat([X_real_train, X_synthetic])
preprocessor.fit(all_train_lyrics.to_frame(name='Lyrics'))

# Test seti oluştur (250 gerçek veri)
X_test = preprocessor.transform(X_real_test.to_frame(name='Lyrics'))
y_test = y_real_test

# Eğitim setleri oluştur
synthetic_sizes = [100, 200, 500, 1000]
train_sets = []

genres = synthetic_data['Genre'].unique()

for size in synthetic_sizes:
    X_train = X_real_train.copy()
    y_train = y_real_train.copy()
    
    samples_per_genre = size // len(genres)
    
    for genre in genres:
        genre_data = synthetic_data[synthetic_data['Genre'] == genre]
        X_train = pd.concat([X_train, genre_data['Lyrics'][:samples_per_genre]])
       
       
        y_train = np.concatenate([y_train, label_encoder.transform(genre_data['Genre'][:samples_per_genre])])
    
    X_train_tfidf = preprocessor.transform(X_train.to_frame(name='Lyrics'))
    train_sets.append((X_train_tfidf, y_train))

# Modelleri tanımla
models = {
    'Logistic Regression': LogisticRegression(max_iter=1000),
    'SVM': SVC(),
    'MLP': MLPClassifier(max_iter=1000),
    'K-Neighbors': KNeighborsClassifier(),
    'Random Forests': RandomForestClassifier(),
}

param_grids = {
    'Logistic Regression': {'C': [0.1, 1, 10]},
    'SVM': {'C': [0.1, 1,10, 100], 'kernel': ['linear', 'rbf','poly','sigmoid']},
    'MLP': {'hidden_layer_sizes': [(50,), (100,),(150,),(200,)], 'activation': ['tanh', 'relu','logistic']},
    'K-Neighbors': {'n_neighbors': np.arange(1, 51,5)},
    'Random Forests': {'n_estimators': [50, 100, 200, 500], 'max_features': [2, 3, 'auto'],"min_samples_split": [2, 5, 10, 20]}
    }

results=[]

# Eğitim ve değerlendirme
for (X_train, y_train), size in zip(train_sets, synthetic_sizes):
    print(f"Training with {size} synthetic data samples")
    for model_name, model in models.items():
        start_time = time.time()
        grid_search = GridSearchCV(model, param_grids[model_name], cv=10, n_jobs=-1)
        grid_search.fit(X_train, y_train)
        best_model = grid_search.best_estimator_
        
        # Test seti üzerinde değerlendirme
        y_pred = best_model.predict(X_test)
        
        end_time = time.time()
        total_time = end_time - start_time
        
        accuracy = accuracy_score(y_test, y_pred)
        precision=precision_score(y_test, y_pred, average='weighted')
        recall=recall_score(y_test, y_pred, average='weighted')
        f1=f1_score(y_test, y_pred, average='weighted')
        
        results.append({
            'Model': model_name,
            'Synthetic Size': size,
            'Best Params': grid_search.best_params_,
            'Accuracy': accuracy,
            'Precision': precision,
            'Recall': recall,
            'F1 Score': f1,
            'CV Time': total_time
        })
        
        
        
        
        print(f"{model_name} Accuracy: {accuracy:.4f} with {size} synthetic samples")
        
        print()
        
results_df = pd.DataFrame(results)
results_df.to_excel('results.xlsx', index=False)
results_df.to_csv('results.csv', index=False)
