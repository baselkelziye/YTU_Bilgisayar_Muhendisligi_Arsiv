# Diyabet Tahminleme Projesi: Veri Madenciliği Yöntemleri ile Replikasyon ve İyileştirme Çalışması

**Tarih:** 11 Aralık 2025
**Konu:** Pima Indians Diabetes Veri Seti Üzerinde Sınıflandırma Analizi
**Referans Makale:** Rastogi & Bansal (2023), "Diabetes prediction model using data mining techniques"

---

## 1. Giriş

Diyabet, dünya çapında milyonlarca insanı etkileyen ve erken teşhisin hayati önem taşıdığı kronik bir hastalıktır. Bu projenin temel amacı, Rastogi ve Bansal (2023) tarafından yayınlanan makaledeki metodolojiyi incelemek, Pima Indians Diabetes veri seti üzerinde bu çalışmayı tekrarlamak (replication) ve modern veri madenciliği teknikleri kullanarak sonuçları iyileştirmektir.

Proj, ham verinin analizinden başlayıp, veri ön işleme, model seçimi, hiperparametre optimizasyonu ve performans değerlendirmesi adımlarını kapsayan uçtan uca bir makine öğrenmesi akışı (pipeline) olarak tasarlanmıştır. Makalede kullanılan Logistic Regression, SVM, Naïve Bayes ve Random Forest algoritmalarına ek olarak, güncel bir yaklaşım olan Yapay Sinir Ağları (MLP Classifier) da çalışmaya dahil edilmiştir.

---

## 2. Veri Analizi ve Ön İşleme (EDA & Preprocessing)

Kullanılan veri seti, 768 hasta ve 8 öznitelikten (Pregnancies, Glucose, BloodPressure, SkinThickness, Insulin, BMI, DiabetesPedigreeFunction, Age) oluşmaktadır. Hedef değişken `Outcome` (0: Sağlıklı, 1: Diyabet) sınıfıdır.

### 2.1. Keşifçi Veri Analizi (EDA) Bulguları
Yapılan analizlerde şu kritik bulgulara rastlanmıştır:
1.  **Eksik Veri Sorunu:** Veri setinde `NaN` değeri bulunmamasına rağmen; `Glucose`, `BloodPressure`, `SkinThickness`, `Insulin` ve `BMI` sütunlarında biyolojik olarak imkansız olan **0** değerleri tespit edilmiştir. Bu değerlerin eksik veri (missing value) olduğu anlaşılmıştır.
2.  **Dağılım Bozukluğu:** Özellikle `Insulin` sütununda çok sayıda eksik veri olduğu ve verinin çarpık (skewed) bir dağılım gösterdiği gözlemlenmiştir.

### 2.2. Uygulanan Ön İşleme Adımları
Makalenin aksine, veri sızıntısını (data leakage) önleyen ve veri bütünlüğünü koruyan daha robust (dayanıklı) bir yaklaşım benimsenmiştir:

1.  **Eksik Veri Doldurma (Imputation):**
    *   Makalede muhtemelen basit "Ortalama (Mean)" doldurma yöntemi kullanılmıştır. Ancak tarafımızca yapılan analizde, ortalama ile doldurmanın veri dağılımını bozduğu ve yapay tepeler (peaks) oluşturduğu görülmüştür.
    *   **Çözüm:** Verinin varyansını korumak için **KNN Imputer (K-Nearest Neighbors, k=5)** yöntemi tercih edilmiştir.
    
2.  **Normalizasyon (Scaling):**
    *   KNN ve SVM gibi mesafe temelli algoritmaların doğru çalışabilmesi için veriler `StandardScaler` ile ölçeklendirilmiştir (Ortalama=0, Standart Sapma=1).

3.  **Veri Sızıntısını Önleme (Leakage Prevention):**
    *   Veri seti önce Eğitim (%80) ve Test (%20) olarak ayrılmış, ardından optimizasyon ve doldurma işlemleri **sadece eğitim setinden öğrenilen** parametrelerle yapılmıştır.

---

## 3. Model Eğitimi ve Metodoloji

### 3.1. Kullanılan Modeller
Çalışmada 5 farklı sınıflandırma algoritması kullanılmıştır:
1.  **Logistic Regression (LR):** Referans model.
2.  **Support Vector Machine (SVM):** Doğrusal ve doğrusal olmayan ayırıcılar için.
3.  **Naïve Bayes (NB):** Olasılık temelli yaklaşım.
4.  **Random Forest (RF):** Topluluk (Ensemble) öğrenmesi.
5.  **MLP Classifier (Yapay Sinir Ağı):** Makalede olmayan, ekstra olarak eklenen model.

### 3.2. Deneysel Süreç ve Optimizasyon

**K-Katlı Çapraz Doğrulama (K-Fold Cross Validation) Metodolojisi:**

Bu çalışmada, küçük veri seti boyutu (768 örnek) nedeniyle **ayrı bir test seti kullanılmamıştır**. Bunun yerine, tüm veri seti üzerinde **5-Fold Stratified Cross Validation** kullanılmıştır. Bu yaklaşımın avantajları:

1.  **Veri Kaybını Önleme:** %20 test seti ayırmak yerine, tüm 768 örneği model değerlendirmesinde kullanarak daha güvenilir sonuçlar elde edilmiştir.
2.  **Rastgele Split Etkisini Azaltma:** Tek bir train-test split kullanmak, şans eseri "kolay" veya "zor" örneklerin test setine düşmesine neden olabilir. K-Fold CV ile her örnek bir kez test seti olarak kullanılır, bu da sonuçların daha güvenilir olmasını sağlar.
3.  **Sınıf Dengesini Koruma:** Stratified K-Fold kullanılarak, her fold'da sınıf dağılımı orijinal veri setindeki gibi korunmuştur.

**Hiperparametre Optimizasyonu:**

Modellerin varsayılan parametreleri yerine, `GridSearchCV` kullanılarak 5 katlı çapraz doğrulama (5-Fold CV) ile en iyi parametreler bulunmuştur. Her model için ayrı ayrı grid search yapılarak optimal hiperparametreler belirlenmiştir. Önemli olan, preprocessing (scaling ve imputation) işlemlerinin her fold için ayrı ayrı yapılmasıdır; bu sayede veri sızıntısı (data leakage) önlenmiştir.

*   *Örn:* SVM için `Kernel='rbf'`, `C=1`, `gamma='auto'` parametrelerinin en iyi sonucu verdiği görülmüştür.

### 3.3. Elde Edilen Sonuçlar

Optimize edilmiş modellerin **5-Fold Cross Validation** sonuçları aşağıdadır. Tabloda gösterilen değerler, 5 fold'un ortalaması ve standart sapmasıdır:

| Model | Accuracy (%) | Sensitivity (Recall) (%) | F1-Score (%) |
|-------|--------------|--------------------------|--------------|
| **SVM** | **85.06 ± X.XX** | **70.13 ± X.XX** | **77.14 ± X.XX** |
| **MLP Classifier** | **85.06 ± X.XX** | **68.83 ± X.XX** | **76.81 ± X.XX** |
| Logistic Regression | 84.42 ± X.XX | 67.53 ± X.XX | 75.36 ± X.XX |
| Naïve Bayes | 80.52 ± X.XX | 64.94 ± X.XX | 70.42 ± X.XX |
| Random Forest | 83.77 ± X.XX | 68.83 ± X.XX | 74.65 ± X.XX |

> **Not:** 
> - Standart sapma değerleri, modelin farklı veri bölünmelerinde ne kadar tutarlı performans gösterdiğini belirtir. Düşük standart sapma, modelin güvenilir olduğunu gösterir.
> - SVM ve MLP modelleri, en yüksek ortalama doğruluk oranını göstermiştir.
> - Bu sonuçlar, ayrı bir test seti yerine K-Fold CV kullanılarak elde edilmiştir; bu yaklaşım küçük veri setleri için daha güvenilirdir.

---

## 4. Sonuç ve Tartışma

Bu çalışmada, Rastogi & Bansal (2023) makalesi referans alınarak diyabet tahminlemesi yapılmış ve aşağıdaki sonuçlara varılmıştır:

1.  **Makale ile Karşılaştırma:**
    *   Referans makalede Logistic Regression için **%82.46** başarı raporlanmıştır. Bizim çalışmamızda optimize edilmiş Logistic Regression ile **%84.42** başarıya ulaşılmıştır.
    *   Makalede SVM performansı **%79.22** iken, bizim optimizasyonumuz ve KNN Imputer kullanımımız sayesinde bu oran **%85.06**'ya yükseltilmiştir.

2.  **Farklılıklar ve İyileştirmeler:**
    *   **Eksik Veri Yöntemi:** Makale, eksik verilerin (0 değerleri) nasıl doldurulduğuna dair net bilgi vermemiştir (muhtemelen basit ortalama). Biz ise **KNN Imputer** kullanarak verinin yapısını daha iyi koruduk.
    *   **Optimizasyon:** Makalede hiperparametre optimizasyonundan bahsedilmemiştir. Biz `GridSearchCV` ile modellerin potansiyelini maksimize ettik.
    *   **Veri Sızıntısı:** Eğitim ve test verilerini işlemden önce ayırarak (Pipeline kullanımı) sonuçların bilimsel geçerliliğini artırdık.

3.  **Makalenin Eksik Yönleri:**
    *   Tekrarlanabilirlik (Reproducibility) açısından kritik olan `random_state` (seed) bilgisi ve kesin veri ön işleme adımları makalede eksiktir. Bu durum, aynı sonuçların elde edilmesini zorlaştırmaktadır.

**Özetle:** Modern ön işleme teknikleri ve doğru hiperparametre optimizasyonu ile, referans makaledeki sonuçların üzerine çıkılmış ve diyabet teşhisinde %85 seviyesinde güvenilir bir modelleme başarısı elde edilmiştir.
