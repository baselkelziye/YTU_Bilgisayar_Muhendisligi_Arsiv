import json
import nltk
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer
import re
import random
import joblib
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.feature_extraction.text import CountVectorizer, TfidfVectorizer
from sklearn.naive_bayes import MultinomialNB
from sklearn.model_selection import GridSearchCV, cross_val_score
from sklearn.ensemble import RandomForestClassifier
from sklearn.svm import SVC
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.feature_selection import RFE
from sklearn.linear_model import LogisticRegression
import numpy as np
from scipy.stats import f_oneway
from sklearn.feature_selection import SelectKBest, chi2

param_grid_KNN = {'n_neighbors': [3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41]}
param_grid_SVM = {'C': [0.1, 1, 10, 100],
              'kernel': ['linear', 'poly', 'rbf', 'sigmoid'],
              'gamma': [0.1, 1, 10, 100]}
param_grid_NB = {
    'alpha': [0.01, 0.1, 0.5, 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000]
}
param_grid_DT = {
    'max_depth': [5, 10, 15, None],
    'min_samples_split': [2, 5, 10],
    'min_samples_leaf': [1, 2, 4],
    'criterion': ['gini', 'entropy']
}
param_grid_RF = {
    'n_estimators': [50, 100, 200],
    'max_depth': [None, 5, 10, 20],
    'min_samples_split': [2, 5, 10],
    'min_samples_leaf': [1, 2, 4],
}









def plot_and_save_figure(cross_val_scores, model_name):
    fig, ax = plt.subplots(figsize=(8, 6))
    ax.bar(range(1, 11), cross_val_scores)
    ax.set_title(f"{model_name} Cross Validation Scores")
    ax.set_xlabel('K-fold Cross Validation')
    ax.set_ylabel('Score')
    ax.set_ylim([0, 1])
    plt.tight_layout()
    plt.savefig(f"{model_name}_cv_scores_bar_plot.png")
    plt.close()


stop_words = set(stopwords.words('english'))
ps = PorterStemmer()


def find_label_counts(y):
    label_counts = {}
    for label in y:
        if label not in label_counts:
            label_counts[label] = 1
        else:
            label_counts[label] += 1
    return label_counts

def predict_result(knn, text):
    result = knn.predict(text)
    return str(list(result))
    

def calculate_accuracy_with_distance(model):
    # Test setindeki her bir örnek için tahminler yapın ve başarı ölçümünü hesaplayın
    total_distance = 0
    for i in range(len(X_test)):
        # Örnek metni vektöre dönüştürün
        test_text = vectorizer.transform([X_test[i]])
        # Tahmin yapın
        predicted = model.predict(test_text)[0]
        # Gerçek değeri alın
        true_label = y_test[i]
        # Tahmin ve gerçek değer arasındaki farkı hesaplayın
        distance = abs(predicted - true_label)
        # Toplam uzaklığa ekleyin
        total_distance += distance
    
    # Başarı ölçümünü hesaplayın
    return 1 - (total_distance / (4 * len(X_test)))

def preprocess_text(pattern):
    # lowercase
    pattern = pattern.lower()
    # remove punctuation and special characters
    pattern = re.sub(r'\W', ' ', pattern)
    # remove digits
    pattern = re.sub(r'\d', '', pattern)
    # remove extra spaces
    pattern = re.sub(r'\s+', ' ', pattern).strip()
    # remove stop words and stemming
    pattern = [ps.stem(word) for word in pattern.split() if word not in stop_words]
    # join stemmed words into a string
    pattern = ' '.join(pattern)
    return pattern

def preprocess_intent(intent):
    pattern = intent["comment"]
    pattern = preprocess_text(pattern)
    return {'text': pattern, 'label': intent['star']}

def preproccess_json(intents):
    data = []
    for intent in intents['intents']:
        # append preprocessed text and label to data list
        data.append(preprocess_intent(intent))
    return data

def calculate_results(model):
    global accuracy, scores
    accuracy = model.score(X_test_counts, y_test)
    scores = cross_val_score(model, X, y, cv=10)
    return accuracy, scores
def print_results_for_intput_model(model_name):
    print("="*50)
    print("FOR " + model_name + " MODEL")
    print("Real accuraccy is -> " + str(accuracy))
    print("Cross val score is-> "+ str(scores))
    print("="*50)

def save_model(model_name, model):
    joblib.dump(model,model_name+"_model.joblib")
    print(model_name + " model saved...")
with open('intents.json', encoding= "utf-8-sig") as f:
    data = preproccess_json(json.load(f))

random.shuffle(data)
# Verileri özellikler ve hedef değişken olarak ayırma
X = [d['text'] for d in data]
y = [d['label'] for d in data]

# Verileri eğitim ve test setlerine ayırma
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42, stratify=y)

# CountVectorizer'ı ayarlayın
vectorizer = TfidfVectorizer()
# X_train'deki metin verilerini sıfırlardan oluşan bir matris formatına dönüştürün
X_train_counts = vectorizer.fit_transform(X_train)
# X_test'teki metin verilerini sıfırlardan oluşan bir matris formatına dönüştürün
X_test_counts = vectorizer.transform(X_test)
X = TfidfVectorizer().fit_transform(X)

# Eğitim ve test setlerinin boyutlarını kontrol etme
print("Training set size:", len(X_train))
print("Test set size:", len(X_test))
print("All label Counts:", find_label_counts(y))
print("Train label Counts:", find_label_counts(y_train))
print("Test label Counts:", find_label_counts(y_test))





# KNN için en iyi parametreleri buluyoruz
param_grid_KNN = {'n_neighbors': [3, 5, 7, 9, 11]}
grid_search_KNN = GridSearchCV(KNeighborsClassifier(), param_grid_KNN, cv=10, scoring='accuracy', verbose=1)
grid_search_KNN.fit(X_train_counts, y_train)
print(grid_search_KNN.best_params_)
knn = KNeighborsClassifier(n_neighbors=grid_search_KNN.best_params_['n_neighbors'])

# Select top 5 features based on chi-squared test
selector = SelectKBest(chi2, k=35)
X_train_kbest = selector.fit_transform(X_train_counts, y_train)
X_test_kbest = selector.transform(X_test_counts)

# KNN modelini eğitiyoruz ve test ediyoruz
knn.fit(X_train_kbest, y_train)
accuracy_knn = knn.score(X_test_kbest, y_test)
print(f"KNN accuracy with RFE feature selection: {accuracy_knn}")



# SVM için en iyi parametreleri buluyoruz
grid_search_SVM = GridSearchCV(SVC(), param_grid_SVM, cv=10)
grid_search_SVM.fit(X_train_counts, y_train)
print("Best parameters for SVM: ", grid_search_SVM.best_params_)

# RFE ile en önemli öznitelikleri seçiyoruz
svm = SVC(**grid_search_SVM.best_params_)
svm.fit(X_train_kbest, y_train)
accuracy_svm = svm.score(X_test_kbest, y_test)

# Naive Bayes için
grid_search_NB = GridSearchCV(MultinomialNB(), param_grid_NB, cv=10, n_jobs=-1, verbose=1)
grid_search_NB.fit(X_train_counts, y_train)
print("Best parameters for NB: ", grid_search_NB.best_params_)
nb = MultinomialNB(**grid_search_NB.best_params_)
nb.fit(X_train_kbest, y_train)
accuracy_nb = nb.score(X_test_kbest, y_test)

# DT için
grid_search_DT = GridSearchCV(DecisionTreeClassifier(), param_grid_DT, cv=10)
grid_search_DT.fit(X_train_counts, y_train)
print("Best parameters for DT: ", grid_search_DT.best_params_)
dt = DecisionTreeClassifier(**grid_search_DT.best_params_)
dt.fit(X_train_kbest, y_train)
accuracy_dt = dt.score(X_test_kbest, y_test)

# RF için
grid_search_RF = GridSearchCV(RandomForestClassifier(), param_grid_RF, cv=10)
grid_search_RF.fit(X_train_counts, y_train)
print("Best parameters for RF:", grid_search_RF.best_params_)
rf = RandomForestClassifier(**grid_search_RF.best_params_)
rf.fit(X_train_kbest, y_train)
accuracy_rf = rf.score(X_test_kbest, y_test)



# Elde ettiğiniz sonuçları bir sözlükte toplayın
results = {'model': ['KNN', 'SVM', 'NB', 'DT', 'RF'],
           'accuracy': [accuracy_knn, accuracy_svm, accuracy_nb, accuracy_dt, accuracy_rf]}

# Sözlüğü bir veri çerçevesine dönüştürün
df_results = pd.DataFrame.from_dict(results)

# Accuracy'leri yan yana gösteren bar plot'u oluşturun ve kaydedin
fig, ax = plt.subplots(figsize=(10,5))
ax.bar(df_results['model'], df_results['accuracy'])
ax.set_ylabel('Accuracy')
ax.set_ylim([0, 1])
plt.xticks(rotation=45)
plt.tight_layout()
plt.savefig("models_accuracy_bar_plot.png")




