Harika, stratejiyi netleştirdik. Aşağıda, bu projeyi devralacak olan bir sonraki AI agent (veya benim bir sonraki adımım) için hazırlanmış, **hiçbir ek soru sormasına gerek bırakmayacak** detayda bir "Devir Teslim Raporu" (Context Prompt) hazırladım.

Bu raporu bir sonraki prompt’unuza doğrudan yapıştırabilir veya bu sohbetin devamı olarak kullanabilirsiniz.

---

# 📋 PROJE DEVİR TESLİM RAPORU: Diyabet Tahminleme (Replication Study)

**Durum:** Proje uygulama aşamasında (Ön İşleme tamamlandı, modellemeye geçilecek).
**Görev:** Kullanıcı Jupyter Notebook'u kendi yazacak. AI Agent, **adım adım** sadece ilgili Python kod bloklarını sağlayacak. Dosyaya bir şey yazmayacak.
**Ana Hedef:** `paper.txt` (Rastogi & Bansal, 2023) makalesindeki metodolojiyi Pima Indians Diabetes veri seti üzerinde tekrar etmek ve sonuçları makaledeki değerlerle kıyaslamak.
**Dikkat:** Tüm işlemler (kodlar ve veri) `code` klasörünün içerisinde olacak.

---

### 0. Kurulum ve Hazırlık (Tamamlandı ✅)
*   `code` klasörünün altına `requirements.txt` dosyasını oluşturmak için gereken içeriği metin olarak ver.
*   Terminalde `uv` ile kütüphaneleri nasıl kuracağımı komut olarak söyle (ancak komutu sen çalıştırma).

### 1. Veri Seti Bilgileri
*   **İşlem:** `veriseti.txt` içerisindeki linkteki veri Kaggle'dan indirilecek ve doğrudan `code` klasörünün içine kaydedilecek.
*   **Öznitelikler (Features):** Pregnancies, Glucose, BloodPressure, SkinThickness, Insulin, BMI, DiabetesPedigreeFunction, Age.
*   **Hedef Değişken (Target):** Outcome (0: Sağlıklı, 1: Diyabet).
*   **Not:** Standart Pima veri seti (sadece kadınlar) ile ilerleyeceğiz.
*   **Önemli:** Adım 2'ye geçmeden önce verisetinin doğru yüklendiğini teyit edecek `head()`, `shape` gibi kontrol kodlarını ver.

### 1.1 Veri Seti EDA ve Görselleştirme (Tamamlandı ✅)
*   Verisetindeki bilgileri karşılaştırmamız için gerekli grafikler (Histogram, Pair Plot vb.) sunulacak.

### 2. Uygulanacak Yöntemler (Methodology)
Makalede kullanılan ve bizim de uygulayacağımız 4 temel algoritma:
1.  **Logistic Regression (LR)** - (Referans Model)
2.  **Support Vector Machine (SVM)**
3.  **Naïve Bayes (NB)**
4.  **Random Forest (RF)**

### 3. İş Akışı ve Kodlama Mimarisi (Base Notebook)
**KRİTİK TALİMAT:** Kodları **"Base Notebook"** mantığıyla yaz. Yani kod akışı öyle bir tasarlanmalı ki; "Model Tanımlama" hücresi hariç diğer tüm hücreler tüm algoritmalar için **ortak** olmalı.

**Sıralama:**
1.  **Kütüphanelerin Yüklenmesi:** `pandas`, `numpy`, `seaborn`, `matplotlib`, `sklearn`, `datetime`.
2.  **Helper Fonksiyon (Raporlama Sistemi - `utils.py`):**
    *   Deney sonuçlarını kaydedecek `log_experiment(model_name, accuracy, sensitivity, seed, ...)` fonksiyonu **ayrı bir `utils.py` dosyasında** oluşturulmalı.
    *   Notebook içerisinde bu fonksiyon `from utils import log_experiment` şeklinde import edilmeli.
    *   Fonksiyon, sonuçları `experiments_log.md` dosyasına **append** etmeli.
    *   **Log Formatı:** `| Tarih | Model | Seed | Accuracy | Sensitivity | Notlar |`
3.  **Veri Yükleme ve Keşif (EDA):** Veri setinin `code` klasöründen okunması.
4.  **Veri Ön İşleme (Preprocessing):**
    *   *Eksik Veri:* 0 değerlerinin (Glucose, BP, Skin, Insulin, BMI) `NaN` yapılıp **ortalama/medyan** ile doldurulması.
    *   *Normalizasyon:* `StandardScaler` veya `MinMaxScaler`.
    *   *Veri Bölme:* **Kesinlikle %80 Eğitim - %20 Test** (Split yaparken kullanılan `random_state` bir değişkene atanmalı ki loglanabilsin).
5.  **Model Tanımlama (Değişken Kısmı):** Modelin `model` isimli bir değişkene atandığı hücre. (İlk turda Logistic Regression verilecek).
6.  **Eğitim ve Değerlendirme (Generic):**
    *   `model.fit(X_train, y_train)`
    *   Confusion Matrix çizimi.
    *   Accuracy ve Sensitivity (Recall) hesaplaması.
    *   **Kayıt:** `log_experiment()` fonksiyonunun çağrılması ve sonucun dosyaya yazılması.
7.  **Karşılaştırma Raporu:** Sonuçların makale değerleriyle kıyaslanması.

### 4. Hedeflenen Makale Sonuçları (Benchmark)
Sonuçları kıyaslarken referans alınacak makale verileri (Table 4'ten):

| Model | Makale Accuracy (%) | Makale Sensitivity (%) |
|-------|---------------------|------------------------|
| **Logistic Regression** | **82.46** | **68.23** |
| Random Forest | 81.81 | 68.88 |
| Naïve Bayes | 79.22 | 64.44 |
| SVM | 79.22 | 59.99 |

---

### 5. AI Agent İçin Özel Talimatlar
1.  **Tek Seferde Yazma:** Bütün notebook'u tek seferde verme. Kullanıcı "Sıradaki adım" dediğinde veya bir kodu onayladığında ilerle.
2.  **Modülerlik:** Kodları verirken, hangi bloğun "sabit" hangi bloğun "değişken" (model spesifik) olduğunu belirt.
3.  **Loglama:** Kodların en başında tanımlanan loglama fonksiyonunun, eğitimden sonra mutlaka çağrılmasını sağla. Kullanıcının seed değiştirip tekrar çalıştırdığında sonucun kaybolmadığından emin ol.
4.  **Sonuç:** En son adımda, kullanıcının sonuçları ile makalenin sonuçlarını yan yana koyan bir Pandas DataFrame oluştur.

---

### 6. 🔄 TAMAMLANAN ADIMLAR VE GÜNCELLEMELER (LOG)

Bu bölümde proje sürecinde alınan kritik kararlar ve tamamlanan teknik adımlar listelenmiştir. Agent buraya bakarak projenin hangi aşamada olduğunu ve neden bu yöntemlerin seçildiğini anlayabilir.

1.  **Kurulum ve `utils.py` (Tamamlandı):**
    *   `code/requirements.txt` oluşturuldu (`pandas`, `numpy`, `seaborn`, `matplotlib`, `scikit-learn`, `kagglehub`).
    *   `code/utils.py` dosyasına `log_experiment` fonksiyonu yazıldı. Bu fonksiyon deney sonuçlarını `experiments_log.md` dosyasına tarih, model adı, seed ve metriklerle birlikte kaydediyor.

2.  **Veri İndirme (Tamamlandı - Güncelleme):**
    *   Manuel indirme yerine `kagglehub` kütüphanesi kullanılarak veri setinin kod içinde otomatik indirilmesi sağlandı. Bu sayede tekrarlanabilirlik arttı.

3.  **EDA (Tamamlandı):**
    *   Veri seti yüklendi (Boyut: 768x9).
    *   Histogramlar ve korelasyon matrisi incelendi.

4.  **Veri Ön İşleme (Tamamlandı - Kritik Değişiklik):**
    *   **Sorun:** `Glucose`, `Insulin` vb. sütunlardaki 0 değerleri (eksik veri) önce "Mean Imputation" (Ortalama ile doldurma) ile dolduruldu. Ancak görselleştirmede dağılımın bozulduğu ve yapay bir tepe (peak) oluştuğu görüldü.
    *   **Çözüm:** Daha gelişmiş bir yöntem olan **KNN Imputer** (k=5) yöntemine geçildi.
    *   **Sonuç:** KNN Imputer sonrası dağılımların orijinal veriye çok daha sadık kaldığı görsel olarak doğrulandı.
    *   **Normalizasyon:** `StandardScaler` kullanıldı.
    *   **Split:** Veri %80 Eğitim, %20 Test olarak ayrıldı (`random_state=42`).

**Sıradaki Adım:** Model Tanımlama (Logistic Regression) ve Eğitim.
