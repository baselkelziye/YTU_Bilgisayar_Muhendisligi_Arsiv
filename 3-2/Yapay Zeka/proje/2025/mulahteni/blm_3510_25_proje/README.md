# 📀 Yapay Sinir Ağları ile Görsel Tahminleme Projesi (BLM3510 - 2025 Bahar)

Bu proje Yıldız Teknik Üniversitesi Bilgisayar Mühendisliği bölümü `BLM3510 - Yapay Zeka` dersi için geliştirilmiştir.

Projede, 25x25 boyutlarında ikili matrisler (binary matrix) üzerinden çalışan yapay sinir ağı modelleri ile çeşitli görevlerin çözümü amaçlanmaktadır. Her görev, farklı bir regresyon veya sınıflandırma problemine odaklanmakta ve bu problemlere farklı mimariler (MLP, CNN) ile çözüm sunulmaktadır.

## 🔍 Proje Görevleri

### Görev 1: İki nokta arası mesafe

* Matriste rastgele yerleştirilmiş 2 nokta
* Model bu iki nokta arasındaki Öklid mesafesini tahmin eder

### Görev 2: En yakın iki nokta arası mesafe

* 3 ila 10 arası rastgele yerleştirilmiş noktalar
* Model, en yakın iki nokta arasındaki mesafeyi tahmin eder

### Görev 3: En uzak iki nokta arası mesafe

* Yapı olarak Görev 2 ile aynı, ancak model bu kez en uzak iki nokta arasındaki mesafeyi tahmin eder

### Görev 4: Nokta sayısı (sınıflandırma)

* 1 ila 10 arası rastgele noktalar
* Model, kaç tane nokta olduğunu sınıflandırır

### Görev 5: Kare sayısı (sınıflandırma)

* Değişken büyüklükte ve sayıda kare (1-10 adet), çakışabilirler
* Model, kare sayısını sınıflandırır

## 🧠 Kullanılan Modeller

* **MLP (Multi-Layer Perceptron):** 1D vektörle çalışan, gizli katmanlarda dropout içeren yapı
* **CNN (Convolutional Neural Network):** Görsel temsillerle çalışan evrişimli yapı

Model seçimi görevler için MLP ve CNN olarak belirlenmiş ve hepsi eğitilmiştir.

## 🧪 Eğitim ve Test Verisi

* Her görev için:

  * 8000 örnek eğitim verisi
  * 2000 örnek test verisi
* Eğitim, %25 / %50 / %100 oranlarında veriyle yapılmış ve test seti sabit tutulmuştur

## ⚙️ Hiperparametre Ayarları

Her model için şu hiperparametreler denenmiştir:

* `Dropout` oranı
* `Weight Decay`
* `Öğrenme Oranı (LR)`

Hiperparametrelerin karşılaştırması `compare_hyperparamters.py` ile yapılmış, doğruluk analizleri ise `accuracy_for_4n5.py` ile değerlendirilmiştir.

## 📈 En İyi Sonuçlar ve Görselleştirme

Aşağıda her görev için en iyi hiperparametre kombinasyonu ve karşılık gelen başarı görselleri sunulmuştur:

### Görev 1

* Model: `CNN`, Veri: `%100`, Dropout: `0.0`, Weight Decay: `0.0`, LR: `0.001`\\

### Görev 2

* Model: `CNN`, Veri: `%100`, Dropout: `0.0`, Weight Decay: `0.0`, LR: `0.001`\\

### Görev 3

* Model: `CNN`, Veri: `%100`, Dropout: `0.0`, Weight Decay: `0.0`, LR: `0.001`\\

### Görev 4

* Model: `MLP`, Veri: `%100`, Dropout: `0.0`, Weight Decay: `0.0`, LR: `0.001`\\

### Görev 5

* Model: `CNN`, Veri: `%50`, Dropout: `0.5`, Weight Decay: `0.001`, LR: `0.001`\\

## 📊 Değerlendirme ve Görselleştirme

* Her modelin **MSE (Mean Squared Error)** veya **Accuracy** değeri görevlere uygun olarak analiz edilmiştir
* Başarılı tahminler ve hatalı örnekler `visualize_bests.py` ile görselleştirilmiştir
* Her eğitimden sonra tahmin ve gerçek değerler `.csv` olarak `outputs/` klasörüne kaydedilmiştir
* `plot.py` ile bu csv dosyalarından çizim otomasyonu yapılmıştır

## 🗂️ Klasör Yapısı

```
.
├── draw.py                    # Veri üretimi (5 görev için)
├── train.py                   # Eğitim betiği
├── train_utils.py             # Eğitim yardımcıları (model, loss, train loop)
├── compare_hyperparamters.py  # Hiperparametre kıyaslama ve görselleştirme
├── accuracy_for_4n5.py        # Sınıflandırma görevleri için accuracy analizleri
├── plot.py                    # CSV -> Grafik dönüşümü
├── visualize_bests.py         # En iyi tahminlerin görsel karşılaştırması
├── tasks/                     # Görevlere ait eğitim verileri
├── testing/                   # Test sonrası en iyi model ile görsel çıktı
├── outputs/                   # Eğitim çıktıları, tahminler ve grafikler
└── best_models/               # Her görev için en iyi model
```

## ▶️ Kullanım

### Eğitim

```bash
python train.py --task 2 --model cnn --portion 100 --dropout 0.2 --wd 0.0001 --epochs 50 --lr 0.001
```

### Hiperparametre Karşılaştırması ve En İyi Modellerin Seçimi

```bash
python compare_hyperparamters.py
```

### Görev 4 ve 5 için Doğruluk (Accuracy) Analizi

```bash
python accuracy_for_4n5.py
```

### Tahmin-Gerçek Değer Görsel Karşılaştırmaları

```bash
python visualize_bests.py
```

---
