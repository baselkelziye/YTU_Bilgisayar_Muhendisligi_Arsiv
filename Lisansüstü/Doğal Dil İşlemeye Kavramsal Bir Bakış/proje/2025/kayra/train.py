#!/usr/bin/env python
# coding: utf-8

# # Giriş İşlemleri

# In[1]:


get_ipython().run_cell_magic('capture', '', '!pip install kagglehub pandas transformers datasets scikit-learn\n')


# In[2]:


import kagglehub
import pandas as pd
import os
from datasets import Dataset
from sklearn.metrics import accuracy_score, precision_recall_fscore_support
from transformers import AutoModelForSequenceClassification, AutoTokenizer
from transformers import Trainer, TrainingArguments
import numpy as np


# In[ ]:


def is_colab():
    try:
        import google.colab
        return True
    except ImportError:
        return False


# In[ ]:


# Kök dizin belirleme
if is_colab():
    from google.colab import drive
    drive.mount('/content/drive')
    kok_dizin = "/content/drive/MyDrive/spam_message_classifier_tr"
else:
    kok_dizin = os.getcwd()
print(f"Kök dizin: {kok_dizin}\n Not: eğer colab kullanıyorsanız, dizini değiştirmeniz gerekir.")


# # Veri Kümesi Okuma

# ## Veri kümesi okuma fonksiyonu

# In[3]:


def veri_kumesi_oku(veri_kumesi_adi: str) -> pd.DataFrame:
    """
    Kaggle veri kümesini indirir ve döndürür.

    Args:
        veri_kumesi_adi (str): Kaggle veri kümesinin yolu.
        gecici_yol (str): Geçici dosya yolu.
    Returns:
        pd.DataFrame: İndirilen veri kümesi.
    """
    # Kaggle veri kümesini indir
    gecici_yol = os.path.join(kagglehub.dataset_download(veri_kumesi_adi), "TurkishSMSCollection.csv")
    return pd.read_csv(gecici_yol, sep=";", encoding="utf-8")


# ## Veri kümesini oku

# In[4]:


# Veri kümesi bilgileri
dataset_name = "onurkarasoy/turkish-sms-collection"

veri_kumesi = veri_kumesi_oku(dataset_name)
veri_kumesi.head(10)  # İlk 10 satırı göster


# ## Veri kümesinin gereksiz kolonlarını silme

# In[5]:


tohum_degeri = 571
# gereksiz sütunları kaldır
veri_kumesi = veri_kumesi[['Message', 'Group']]
# veri kümesini karıştır
veri_kumesi.head(10)  # İlk 10 satırı göster


# ## Veri kümesini karıştırma

# In[6]:


karismis_veri_kumesi = veri_kumesi.sample(frac=1, random_state=tohum_degeri).reset_index(drop=True)
karismis_veri_kumesi.head(10)  # İlk 10 satırı göster


# ## Veri kümesini eğitim ve sınama olarak parçalama

# In[7]:


def veri_kumesini_oranli_bol(veri_kumesi, test_orani=0.2, tohum_degeri=42):
    """
    Veri kümesini, Group kolonundaki değerlerin oranlarını koruyarak böler.

    Args:
        veri_kumesi (pd.DataFrame): Bölünecek veri kümesi
        test_orani (float): Test veri kümesinin oranı (varsayılan: 0.2)
        tohum_degeri (int): Random state değeri (tekrarlanabilirlik için)

    Returns:
        tuple: (egitim_veri_kumesi, test_veri_kumesi) - Oransal olarak bölünmüş veri kümeleri
    """
    # Benzersiz grup değerlerini bul
    gruplar = veri_kumesi['Group'].unique()

    egitim_liste = []
    test_liste = []

    # Her grup için ayrı ayrı bölme işlemi yap
    for grup in gruplar:
        # Sadece bu gruba ait verileri seç
        grup_verisi = veri_kumesi[veri_kumesi['Group'] == grup]

        # Bu grubu karıştır
        karisik_grup = grup_verisi.sample(frac=1, random_state=tohum_degeri)

        # Bölme noktasını hesapla
        bolme_noktasi = int(len(karisik_grup) * test_orani)

        # Bu gruptan test ve eğitim verilerini ayır
        test_grubu = karisik_grup[:bolme_noktasi]
        egitim_grubu = karisik_grup[bolme_noktasi:]

        # Listelere ekle
        test_liste.append(test_grubu)
        egitim_liste.append(egitim_grubu)

    # Grupları birleştir
    test_veri_kumesi = pd.concat(test_liste).reset_index(drop=True)
    egitim_veri_kumesi = pd.concat(egitim_liste).reset_index(drop=True)

    # Son bir karıştırma işlemi
    test_veri_kumesi = test_veri_kumesi.sample(frac=1, random_state=tohum_degeri).reset_index(drop=True)
    egitim_veri_kumesi = egitim_veri_kumesi.sample(frac=1, random_state=tohum_degeri).reset_index(drop=True)

    return egitim_veri_kumesi, test_veri_kumesi


# In[8]:


egitim_veri, test_veri = veri_kumesini_oranli_bol(karismis_veri_kumesi, tohum_degeri=tohum_degeri)
egitim_veri.head(5)  # İlk 5 satırı göster
test_veri.head(5)  # İlk 5 satırı göster


# ## Veri kümelerini eğitime hazır hale getirme fonksiyonu

# In[9]:


# Veri kümesini hazırla
def verileri_hazirla(df, tokenizer):
    # Group değerlerini 0 ve 1'e dönüştür (Group=1 -> 0, Group=2 -> 1)
    # BERT sınıflandırma için 0-based indeksler kullanır
    labels = df["Group"].apply(lambda x: 0 if x == 1 else 1).tolist()

    # Dataset'e dönüştür
    dataset = Dataset.from_dict({
        "text": df["Message"].tolist(),
        "label": labels
    })

    # Tokenize işlemi
    def tokenize_function(examples):
        return tokenizer(
            examples["text"], 
            padding="max_length", 
            truncation=True, 
            max_length=512,  # BERT için genellikle 512 kullanılır
        )

    tokenized_dataset = dataset.map(tokenize_function, batched=True)
    return tokenized_dataset


# ## Sınama sonucu hesaplama fonksiyonu

# In[10]:


# ölçüt hesaplama fonksiyonu
def compute_metrics(eval_pred):
    predictions, labels = eval_pred
    predictions = np.argmax(predictions, axis=1)
    precision, recall, f1, _ = precision_recall_fscore_support(labels, predictions, average='binary')
    acc = accuracy_score(labels, predictions)
    return {
        'accuracy': acc,
        'f1': f1,
        'precision': precision,
        'recall': recall
    }


# # Model Eğitim işlemleri

# ## Model yükleme

# In[11]:


model_adi = "dbmdz/bert-base-turkish-128k-cased"
model = AutoModelForSequenceClassification.from_pretrained(model_adi)
tokenizer = AutoTokenizer.from_pretrained(model_adi)


# In[ ]:


# Eğitim ve test veri kümelerini hazırla
egitim_dataset = verileri_hazirla(egitim_veri, tokenizer)
test_dataset = verileri_hazirla(test_veri, tokenizer)


# ## Eğitim argümanlarını ve eğiticiyi ayarla

# In[ ]:


# Eğitim argümanlarını tanımla
training_args = TrainingArguments(
    output_dir="./sonuclar",
    num_train_epochs=1,  # 1 epoch
    per_device_train_batch_size=16,
    per_device_eval_batch_size=16,
    warmup_steps=500,
    weight_decay=0.01,
    logging_dir="./logs",
    logging_steps=10,
    evaluation_strategy="epoch",
    save_strategy="epoch",
    load_best_model_at_end=True,
    metric_for_best_model="f1",
)

# Eğiticiyi oluştur
trainer = Trainer(
    model=model,
    args=training_args,
    train_dataset=egitim_dataset,
    eval_dataset=test_dataset,
    compute_metrics=compute_metrics,
)


# ## Eğitim ve sınama işlemleri

# In[ ]:


# Modeli eğit
trainer.train()


# In[ ]:


# Değerlendirme
eval_results = trainer.evaluate()
print(f"Değerlendirme sonuçları: {eval_results}")
sonuc_json_path = os.path.join(kok_dizin, "degerlendirme_sonucu.json")
with open(sonuc_json_path, "w") as f:
    import json
    json.dump(eval_results, f, indent=4)
print(f"Değerlendirme sonuçları {sonuc_json_path} dosyasına kaydedildi.")


# ## Eğitilen modeli kaydetme

# In[ ]:


# Eğitilen modeli kaydet
model_save_path = os.path.join(kok_dizin, "egitilen_model")
if not os.path.exists(model_save_path):
    os.makedirs(model_save_path)
model.save_pretrained(model_save_path)
tokenizer.save_pretrained(model_save_path)

