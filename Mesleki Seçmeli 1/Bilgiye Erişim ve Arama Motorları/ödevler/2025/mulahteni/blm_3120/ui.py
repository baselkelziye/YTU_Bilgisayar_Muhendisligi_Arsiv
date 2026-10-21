import streamlit as st
import joblib
from PIL import Image
import re
import nltk
from nltk.corpus import stopwords
from nltk.stem import WordNetLemmatizer

# NLTK için gerekli indirmeler
nltk.download('stopwords')
nltk.download('wordnet')

# Preprocess için gerekli ayarlar
stop_words = set(stopwords.words('english'))
lemmatizer = WordNetLemmatizer()

labels = ['üzüntü', 'mutluluk', 'aşk', 'sinir', 'korku', 'şaşkınlık']

def preprocess_text(text):
    """Preprocess the input text by removing special characters and stop words, converting to lowercase, and applying lemmatization."""
    text = re.sub(r'[^a-zA-Z\s]', '', text)
    text = text.lower()
    text = ' '.join(word for word in text.split() if word not in stop_words)
    text = ' '.join(lemmatizer.lemmatize(word) for word in text.split())
    return text

# Başlık
st.title("Duygu Analizi Model Sonuçları")

# Modeller ve görselleştirme dosyalarını yükleme
MODELS = {
    "Random Forest": {
        "model_path": "model_weights/random_forest_model.pkl",
        "confusion_matrix": "model_plots/random_forest_confusion_matrix.png",
        "class_predictions": "model_plots/random_forest_metrics_bar_chart.png",
        "roc_curve": "model_plots/random_forest_roc_curve.png",
    },
    "Logistic Regression": {
        "model_path": "model_weights/logistic_regression_model.pkl",
        "confusion_matrix": "model_plots/logistic_regression_confusion_matrix.png",
        "class_predictions": "model_plots/logistic_regression_metrics_bar_chart.png",
        "roc_curve": "model_plots/logistic_regression_roc_curve.png",
    },
    "XGBoost": {
        "model_path": "model_weights/xgboost_model.pkl",
        "confusion_matrix": "model_plots/xgboost_confusion_matrix.png",
        "class_predictions": "model_plots/xgboost_metrics_bar_chart.png",
        "roc_curve": "model_plots/xgboost_roc_curve.png",
    },
    "Naive Bayes": {
        "model_path": "model_weights/naive_bayes_model.pkl",
        "confusion_matrix": "model_plots/naive_bayes_confusion_matrix.png",
        "class_predictions": "model_plots/naive_bayes_metrics_bar_chart.png",
        "roc_curve": "model_plots/naive_bayes_roc_curve.png",
    },
    "K-Nearest Neighbors": {
        "model_path": "model_weights/k-nearest_neighbors_model.pkl",
        "confusion_matrix": "model_plots/k-nearest_neighbors_confusion_matrix.png",
        "class_predictions": "model_plots/k-nearest_neighbors_metrics_bar_chart.png",
        "roc_curve": "model_plots/k-nearest_neighbors_roc_curve.png",
    },
    "Decision Tree": {
        "model_path": "model_weights/decision_tree_model.pkl",
        "confusion_matrix": "model_plots/decision_tree_confusion_matrix.png",
        "class_predictions": "model_plots/decision_tree_metrics_bar_chart.png",
        "roc_curve": "model_plots/decision_tree_roc_curve.png",
    },
}

vec_flag = False

try:
    vectorizer = joblib.load("tfidf_vectorizer.pkl")  # TF-IDF vektörizer dosyasını yükle
    vec_flag = True
except Exception as e:
    st.error(f"TF-IDF vektörizer yüklenirken hata oluştu: {e}")
    
# Kullanıcıdan model seçimi
model_choice = st.selectbox("Bir model seçin:", list(MODELS.keys()))

# Seçilen modelin bilgilerini yükleme
selected_model = MODELS[model_choice]

st.write(f"Seçilen model: {model_choice}")

# Confusion Matrix Görselleştirmesi
st.subheader("Confusion Matrix")
confusion_matrix_img = Image.open(selected_model["confusion_matrix"])
st.image(confusion_matrix_img, caption=f"{model_choice} - Confusion Matrix")

# Precision, Recall, F1-Score Bar Chart Görselleştirmesi
st.subheader("Precision, Recall, and F1-Score")
class_predictions_img = Image.open(selected_model["class_predictions"])
st.image(class_predictions_img, caption=f"{model_choice} - Metrics Bar Chart")

# ROC Curve Görselleştirmesi
st.subheader("ROC Curve")
roc_curve_img = Image.open(selected_model["roc_curve"])
st.image(roc_curve_img, caption=f"{model_choice} - ROC Curve")

# Model Yükleme ve Tahmin Yapma
st.subheader("Metin Analizi")
if vec_flag:
    try:
        # Model ve TF-IDF vektörizeri yükle
        model = joblib.load(selected_model["model_path"])
        st.success(f"{model_choice} modeli ve TF-IDF vektörizeri başarıyla yüklendi.")
        
        # Kullanıcıdan metin girişi al
        user_text = st.text_area("Duygu analizi için bir metin girin:")
        
        # Buton ekleme
        if st.button("Tahmin Yap"):
            if user_text:
                # Kullanıcı girdisini preprocess et
                processed_text = preprocess_text(user_text)
                
                # TF-IDF vektörizer ile dönüştür
                text_tfidf = vectorizer.transform([processed_text])  # Metni TF-IDF vektörüne çevir
                
                # Tahmin yap
                prediction = model.predict(text_tfidf)
                st.write(f"Tahmin edilen duygu: {labels[prediction[0]]}")
            else:
                st.warning("Lütfen bir metin girin!")
    except Exception as e:
        st.error(f"Model yüklenirken hata oluştu: {e}")
else:
    st.write(f"TF-IDF vektörizer yüklenemediği için deneme yapılamamaktadır.")
