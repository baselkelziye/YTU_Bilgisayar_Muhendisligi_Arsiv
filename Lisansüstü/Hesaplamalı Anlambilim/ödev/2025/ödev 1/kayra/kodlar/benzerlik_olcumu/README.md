# GSM8K TR Semantik Benzerlik Analizi

Bu klsör, farklı dil modellerinin metin gömme (embedding) performansını karşılaştırmak için geliştirilmiş bir araçtır. Soru-cevap veri kümeleri üzerinde çeşitli transformers modellerinin gömme performansını değerlendirmeye yarar.

## 📋 İçerik

- [Genel Bakış](#genel-bakış)
- [Gereksinimler](#gereksinimler)
- [Kurulum](#kurulum)
- [Kullanım](#kullanım)
- [Proje Yapısı](#proje-yapısı)
- [Sonuçların Yorumlanması](#sonuçların-yorumlanması)

## 🔍 Genel Bakış

Bu proje, farklı dil modellerinin (özellikle çok dilli modellerin) Türkçe metinlerde gömme vektörlerini ne kadar iyi oluşturduğunu karşılaştırmayı amaçlar. Soru ve cevaplar arasındaki kosinüs benzerliğini hesaplayarak, bir sorunun doğru cevapla eşleştirilme başarısını ölçer.

Proje şu ana bileşenleri içerir:
- Metin gömme hesaplama
- t-SNE ile boyut indirgeme ve görselleştirme
- Kosinüs benzerliği hesaplama
- Top-1 ve Top-5 doğruluk skorları değerlendirme

## 📦 Gereksinimler

Projenin çalışması için aşağıdaki kütüphanelere ihtiyaç vardır:

```bash
transformers
pandas
scikit-learn
torch
matplotlib
```


## 🚀 Kurulum

### 1. Projeyi indirin

```bash
git clone https://github.com/kaayra2000/gsm8k-tr-semantik-analiz.git
cd gsm8k-tr-semantik-analiz
```

### 2. Sanal ortam oluşturun (isteğe bağlı ama önerilir)
  
```bash
python3 -m venv .venv
```

### 3. Sanal ortamı etkinleştirin

Windows için:

```bash
.venv\Scripts\activate
```

Linux için:

```bash
source .venv/bin/activate
```


### 4. Gereksinimleri yükleyin

```bash
pip install -r gereksinimler.txt
```


## 💻 Kullanım

Projeyi çalıştırmak için iki yöntem vardır:

### 1. Jupyter Notebook Kullanımı (Önerilen)

`main.ipynb` dosyasını Jupyter Notebook veya JupyterLab ile açın ve adım adım çalıştırın:

```bash
jupyter notebook main.ipynb
```

### 2. Colab Kullanımı

`main.ipynb` dosyasını Google Colab üzerinde açın ve adım adım çalıştırın.


## 📊 Veri Akışı

Proje aşağıdaki adımları takip eder:

1. **Model ve Veri Yükleme**: 
    - Türkçe metinlerde gömme vektörleri oluşturmak için farklı dil modelleri yüklenir.
    - GSM8K veri kümesi yüklenir.


2. **Gömme Vektörlerinin Hesaplanması**:
    - Soru ve cevaplar için gömme vektörleri oluşturulur.


3. **t-SNE ile Görselleştirme**:
    - Gömme vektörleri t-SNE ile 2 boyuta indirgenir ve görselleştirilir.


4. **Benzerlik Skorlarının Hesaplanması**:
    - Soru ve cevaplar arasındaki kosinüs benzerliği hesaplanır.


5. **Top-1 ve Top-5 Sonuçlarının Hesaplanması**: 
    - Her soru için en yakın cevapların doğruluğu hesaplanır.

6. **Sonuçların Görselleştirilmesi**:
    - Benzerlik skorları ve doğruluk sonuçları görselleştirilir.

## 📂 Proje Yapısı

Proje aşağıdaki dosya ve klasörlerden oluşur:

- `main.ipynb`: Ana çalışma akışı
- `gomme_islemleri.py`: Gömme hesaplama işlemleri
- `benzerlik_islemleri.py`: Benzerlik hesaplama işlemleri
- `dosya_islemleri.py`: Dosya işleme yardımcıları
- `top_islemleri.py`: Top-1 ve Top-5 hesaplama
- `gorsellestir.py`: Görselleştirme işlevleri
- `gereksinimler.txt`: Gerekli kütüphaneler
- `.gitignore`: Git tarafından yok sayılacak dosyalar

## 📊 Sonuç Klasörleri

Proje çalıştırıldığında, aşağıdaki klasörler otomatik olarak oluşturulur:

- `embeddings/`: Hesaplanan gömme vektörleri
- `tsne_results/`: t-SNE görselleştirme sonuçları
- `probabilities/`: Benzerlik skorları
- `top1_top5_results/`: Top-1 ve Top-5 sonuçları

## 🔄 Test Edilen Modeller

Projede varsayılan olarak aşağıdaki modeller test edilir:

1. `intfloat/multilingual-e5-base` (278M parametre)
2. `ibm-granite/granite-embedding-107m-multilingual` (107M parametre)
3. `intfloat/multilingual-e5-small` (118M parametre)
4. `sentence-transformers/paraphrase-multilingual-MiniLM-L12-v2` (118M parametre)
5. `shibing624/text2vec-base-multilingual` (118M parametre)
6. `ytu-ce-cosmos/turkish-colbert`

## 📝 Sonuçların Yorumlanması

- **t-SNE Görselleri**: Gömme vektörlerinin 2 boyutlu gösterimini sağlar. Benzer soru-cevap çiftlerinin uzayda birbirine yakın olması beklenir.
  
- **Top-1 Skor**: Bir sorunun/cevabın, doğru eşiyle en yüksek benzerliğe sahip olma yüzdesi. Bu skor yükseldikçe model performansı iyileşir.

- **Top-5 Skor**: Bir sorunun/cevabın, doğru eşinin ilk 5 en benzer sonuç içinde yer alma yüzdesi.

## ⚠️ Notlar

- Büyük veri kümeleriyle çalışırken GPU kullanımı önerilir.
- Varsayılan olarak veri kümesindeki ilk 70 örnek kullanılır. Bu değeri `dosya_islemleri.py` dosyasından değiştirebilirsiniz.
- t-SNE parametreleri `gomme_islemleri.py` dosyasından ayarlanabilir.

## 🤔 Sorun Giderme

1. **Bellek Hatası Alıyorsanız**:
   - Veri kümesinin boyutunu azaltın
   - Daha küçük batch_size kullanın
   - Daha küçük modeller seçin

2. **CUDA Hatası Alıyorsanız**:
   - `device_type="cpu"` ayarını kullanın

3. **Dosya Bulunamadı Hatası**:
   - Doğru çalışma dizininde olduğunuzdan emin olun
   - Veri kümesi dosyasının doğru konumda olduğunu kontrol edin

Bu README, projenin nasıl kullanılacağını ve işleyişini açıklamaktadır. Sorularınız veya sorunlarınız için iletişime geçmekten çekinmeyin.