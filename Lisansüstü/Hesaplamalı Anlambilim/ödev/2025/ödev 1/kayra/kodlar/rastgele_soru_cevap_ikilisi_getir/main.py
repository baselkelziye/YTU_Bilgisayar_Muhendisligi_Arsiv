# Gerekli kütüphaneleri içe aktaralım
from datasets import load_dataset
import pandas as pd
import numpy as np
import random
import os
import argparse

# Argüman ayrıştırıcı oluştur
parser = argparse.ArgumentParser(description='GSM8K Türkçe veri kümesinden rastgele soru-cevap çiftleri seçer')
parser.add_argument('-s', '--seed', type=int, default=42, help='Rastgelelik değeri (varsayılan: 42)')
args = parser.parse_args()

# Rastgelelik değerini ayarla
SEED = args.seed
random.seed(SEED)
np.random.seed(SEED)

print(f"Kullanılan seed değeri: {SEED}")

# Veri kümesini HuggingFace'ten yükleyelim
print("GSM8K Türkçe veri kümesi indiriliyor...")
dataset = load_dataset("ytu-ce-cosmos/gsm8k_tr")

# Veri kümesinin yapısını kontrol edelim
print(f"Veri kümesi yapısı: {dataset}")

# Uygun bölümü alalım (train ya da test)
split = list(dataset.keys())[0]  # Mevcut ilk bölümü kullan
full_dataset = dataset[split]

# Veri kümesi hakkında bilgi verelim
print(f"Veri kümesindeki sütunlar: {full_dataset.column_names}")
print(f"Toplam örnek sayısı: {len(full_dataset)}")

# 1000 rastgele soru-cevap çifti seçelim
if len(full_dataset) > 1000:
    # 1000 rastgele indeks örnekleyelim
    indices = random.sample(range(len(full_dataset)), 1000)
    selected_data = full_dataset.select(indices)
else:
    # Eğer veri kümesinde 1000'den az örnek varsa, tümünü kullanalım
    selected_data = full_dataset
    print(f"Uyarı: Veri kümesinde 1000'den az örnek var. Tüm örnekler kullanılacak ({len(selected_data)}).")

# Pandas DataFrame'e dönüştürelim
df = pd.DataFrame({
    "question": selected_data["question"],
    "answer": selected_data["answer"]
})

# Kod dosyasının bulunduğu dizini alalım
current_dir = os.path.dirname(os.path.abspath(__file__))

# Uygun bir dosya adı oluşturalım
filename = os.path.join(current_dir, '..', f"gsm8k_tr_1000_soru_cevap.csv")

# DataFrame'i CSV dosyasına kaydedelim
df.to_csv(filename, index=False)

print(f"Veri başarıyla '{filename}' dosyasına kaydedildi.")
print(f"Toplam seçilen soru-cevap çifti sayısı: {len(df)}")

# İlk 5 örneği gösterelim
print("\nİlk 5 örnek:")
print(df.head())