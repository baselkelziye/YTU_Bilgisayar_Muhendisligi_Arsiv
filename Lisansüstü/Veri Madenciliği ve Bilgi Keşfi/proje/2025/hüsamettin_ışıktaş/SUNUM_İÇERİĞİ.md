# Pima Indians Diabetes Veri Seti Üzerinde Sınıflandırma Analizi
## Detaylı Sunum İçeriği

---

## SLİDE 1: KAPAK
**Başlık:** Pima Indians Diabetes Veri Seti Üzerinde Sınıflandırma Analizi

**Alt Başlık:** Veri Madenciliği ve Bilgi Keşfi Dönem Projesi

**Bilgiler:**
- Öğrenci: Hüsamettin IŞIKTAŞ
- Öğrenci No: 25501005
- E-posta: husamettin.isiktas@std.yildiz.edu.tr
- Ders: BLM5116 – Veri Madenciliği ve Bilgi Keşfi
- Öğretim Üyesi: Prof. Dr. Songül VARL

**Tarih:** [Sunum Tarihi]

---

## SLİDE 2: İÇİNDEKİLER
1. Giriş ve Problem Tanımı
2. Literatür İncelemesi ve Referans Makale
3. Veri Seti Tanıtımı
4. Keşifsel Veri Analizi (EDA)
5. Veri Ön İşleme Stratejisi
6. Model Seçimi ve Metodoloji
7. Model Eğitimi ve Optimizasyon
8. Sonuçlar ve Performans Analizi
9. Referans Makale ile Karşılaştırma
10. Metodolojik İyileştirmeler
11. Sonuç ve Öneriler

---

## SLİDE 3: GİRİŞ VE PROBLEM TANIMI

### Problem
- **Diyabet:** Dünya çapında milyonlarca insanı etkileyen kronik bir hastalık
- **Erken teşhis:** Hayati önem taşıyor
- **Makine öğrenmesi:** Diyabet teşhisinde yardımcı araç olarak kullanılabilir

### Proje Amacı
1. Rastogi ve Bansal (2023) makalesindeki metodolojiyi incelemek
2. Pima Indians Diabetes veri seti üzerinde çalışmayı tekrarlamak
3. Modern veri madenciliği teknikleri ile sonuçları iyileştirmek
4. Makale sonuçlarını geçmek

### Proje Kapsamı
- 5 farklı sınıflandırma algoritması
- Gelişmiş veri ön işleme teknikleri
- K-Fold Cross Validation ile güvenilir değerlendirme
- Parametre optimizasyonu

---

## SLİDE 4: LİTERATÜR İNCELEMESİ VE REFERANS MAKALE

### Referans Makale
**R. Rastogi and M. Bansal (2023)**
- "Diabetes prediction model using data mining techniques"
- Measurement: Sensors, vol. 25, art. no. 100605
- Elsevier dergisinde yayınlanmış (2023)

### Makalede Kullanılan Modeller
1. **Logistic Regression** - Accuracy: 82.46%, Recall: 68.23%
2. **Random Forest** - Accuracy: 81.81%, Recall: 68.88%
3. **Naïve Bayes** - Accuracy: 79.22%, Recall: 64.44%
4. **SVM** - Accuracy: 79.22%, Recall: 59.99%

### Makalede Tespit Edilen Eksiklikler
- ❌ Confusion matrix yerine correlation matrix gösterilmiş
- ❌ Veri seti referansı eksik
- ❌ Veri seti hakkında yanlış bilgiler (ör. erkek birey bilgisi)
- ❌ Ön işleme adımları net değil
- ❌ Model parametreleri belirtilmemiş

### Bizim Yaklaşımımız
- ✅ Detaylı veri analizi ve EDA
- ✅ Şeffaf ön işleme adımları
- ✅ Parametre optimizasyonu
- ✅ K-Fold Cross Validation
- ✅ MLP Classifier eklenmesi

---

## SLİDE 5: VERİ SETİ TANITIMI

### Pima Indians Diabetes Database
- **Kaynak:** UCI Machine Learning Repository (Kaggle)
- **Örnek Sayısı:** 768 hasta
- **Özellik Sayısı:** 8 öznitelik
- **Hedef Değişken:** Outcome (0: Sağlıklı, 1: Diyabet)

### Özellikler (Features)
1. **Pregnancies** - Hamilelik sayısı
2. **Glucose** - Glikoz seviyesi
3. **BloodPressure** - Kan basıncı
4. **SkinThickness** - Deri kalınlığı
5. **Insulin** - İnsülin seviyesi
6. **BMI** - Vücut Kitle İndeksi
7. **DiabetesPedigreeFunction** - Diyabet soyağacı fonksiyonu
8. **Age** - Yaş

### Veri Seti Özellikleri
- Açık kaynaklı veri seti
- Tıbbi veri seti (gerçek dünya uygulaması)
- Sınıf dengesizliği mevcut
- Eksik veri problemi (0 değerleri)

---

## SLİDE 6: KEŞİFSEL VERİ ANALİZİ (EDA) - 1

### Sınıf Dağılımı Analizi
**Problem: Veri Seti Dengesizdir**

- **Class 0 (Sağlıklı):** ~500 örnek (%65)
- **Class 1 (Diyabet):** ~268 örnek (%35)
- **Dengesizlik Oranı:** ~1.9:1

**Sonuç:**
- Accuracy metriği yeterli değil
- **Precision ve Recall** metrikleri daha önemli
- Sınıf ağırlıklandırması gerekli

### Eksik Veri ve Dağılım Bozukluğu
**Tespit Edilen Problemler:**
- Bazı özelliklerde **0 değerleri** mevcut
- Özellikle etkilenen özellikler:
  - **Glucose** (glikoz)
  - **Insulin** (insülin)
  - **SkinThickness** (deri kalınlığı)
  - **BloodPressure** (kan basıncı)

**Biyolojik Olarak İmkansız:**
- Glikoz seviyesi 0 olamaz
- İnsülin seviyesi 0 olamaz
- Deri kalınlığı 0 olamaz

**Çözüm:** Bu değerler **NaN** olarak işaretlenip doldurulmalı

---

## SLİDE 7: KEŞİFSEL VERİ ANALİZİ (EDA) - 2

### Korelasyon Analizi
- Özellikler arasındaki ilişkiler incelendi
- Korelasyon matrisi ile görselleştirildi
- Hedef değişken ile özellikler arasındaki ilişkiler analiz edildi

### Histogram Dağılımları
- Her özelliğin dağılımı incelendi
- Normalizasyon ihtiyacı belirlendi
- Outlier'lar tespit edildi

### Ön İşleme İhtiyaçları
1. ✅ Eksik veri doldurma (KNN Imputer)
2. ✅ Normalizasyon (StandardScaler)
3. ✅ Sınıf dengesizliği (Class Weights)
4. ✅ Pipeline yaklaşımı (Data Leakage önleme)

---

## SLİDE 8: VERİ ÖN İŞLEME STRATEJİSİ

### Uygulanan Ön İşleme Adımları

#### 1. Eksik Veri İşaretleme
```python
# Biyolojik olarak imkansız 0 değerleri NaN olarak işaretle
- Glucose: 0 → NaN
- BloodPressure: 0 → NaN
- SkinThickness: 0 → NaN
- Insulin: 0 → NaN
- BMI: 0 → NaN
```

#### 2. Normalizasyon
- **StandardScaler** kullanıldı
- Tüm özellikler standart sapma normalizasyonuna tabi tutuldu
- **Neden?** KNN Imputer mesafe bazlı çalıştığı için

#### 3. Eksik Veri Doldurma
- **KNN Imputer** (k=5) kullanıldı
- Basit ortalama yerine, veri yapısını koruyan yöntem
- Her fold için ayrı uygulandı (data leakage önleme)

#### 4. Pipeline Yaklaşımı
```python
Pipeline([
    ('scaler', StandardScaler()),
    ('imputer', KNNImputer(n_neighbors=5)),
    ('model', classifier)
])
```

**Avantaj:** Her cross-validation fold'unda ön işleme ayrı yapılır

---

## SLİDE 9: MODEL SEÇİMİ VE METODOLOJİ

### Seçilen Modeller

#### 1. **Logistic Regression**
- Lineer sınıflandırma
- Makalede kullanılan model
- Parametre: C=0.1, solver='liblinear'

#### 2. **Support Vector Machine (SVM)**
- Kernel trick ile non-lineer sınıflandırma
- RBF kernel kullanıldı
- Parametre: C=1, gamma='auto'

#### 3. **Naïve Bayes**
- Olasılık tabanlı sınıflandırma
- GaussianNB kullanıldı
- Özellik bağımsızlığı varsayımı

#### 4. **Random Forest**
- Ensemble yöntem
- Parametre: n_estimators=200, max_depth=10
- Overfitting'e karşı dirençli

#### 5. **MLP Classifier** ⭐ (YENİ)
- Yapay Sinir Ağları
- Makalede kullanılmamış
- Parametre: hidden_layers=(50,50), activation='tanh'

### Ortak Özellikler
- **Class Weights:** 'balanced' (sınıf dengesizliği için)
- **Random State:** 42 (tekrarlanabilirlik)
- **Grid Search:** Her model için parametre optimizasyonu yapıldı

---

## SLİDE 10: MODEL EĞİTİMİ VE DEĞERLENDİRME METODOLOJİSİ

### 5-Fold Stratified Cross Validation

**Neden K-Fold CV?**
- ✅ Tek bir train-test split yerine tüm veri kullanılır
- ✅ Overfitting riskini azaltır
- ✅ Model performansının tutarlılığını gösterir
- ✅ Standart sapma ile güvenilirlik ölçülür

**Stratified K-Fold:**
- Sınıf dağılımını her fold'da korur
- Dengesiz veri setleri için kritik

### Değerlendirme Metrikleri

1. **Accuracy** - Genel doğruluk oranı
2. **Recall (Sensitivity)** - Hasta olanları tespit etme yeteneği ⭐
3. **Precision** - Pozitif tahminlerin doğruluğu
4. **F1-Score** - Precision ve Recall'un harmonik ortalaması

**Neden Recall Önemli?**
- Diyabet teşhisinde hasta olanları kaçırmamak kritik
- False Negative maliyeti yüksek

### Pipeline Yaklaşımı
- Her fold için ön işleme ayrı yapılır
- Data leakage önlenir
- Gerçek dünya performansı daha iyi tahmin edilir

---

## SLİDE 11: MODEL PERFORMANS SONUÇLARI

### 5-Fold Cross Validation Sonuçları

| Model | Accuracy (%) | Recall (%) | Precision (%) | F1-Score (%) |
|-------|-------------|------------|---------------|--------------|
| **Random Forest** | **77.47 ± 2.53** | 72.03 ± 4.10 | 66.56 ± 4.02 | **69.07 ± 3.01** |
| MLP Classifier | 75.90 ± 4.47 | 67.90 ± 3.29 | 65.86 ± 8.12 | 66.52 ± 4.15 |
| Logistic Regression | 74.73 ± 4.76 | 73.49 ± 2.88 | 62.42 ± 7.31 | 67.23 ± 4.31 |
| **SVM** | 74.09 ± 2.33 | **76.89 ± 3.07** | 60.27 ± 3.26 | 67.47 ± 2.01 |
| Naïve Bayes | 73.82 ± 3.77 | 61.19 ± 3.06 | 63.60 ± 7.23 | 62.14 ± 3.83 |

### Önemli Bulgular

**En Yüksek Accuracy:** Random Forest (77.47% ± 2.53%)
- Ensemble yapısı sayesinde güçlü genelleştirme

**En Yüksek Recall:** SVM (76.89% ± 3.07%) ⭐
- Diyabet teşhisinde kritik olan "hasta tespit etme" yeteneği en güçlü
- Düşük standart sapma (3.07%) → tutarlı performans

**En Yüksek F1-Score:** Random Forest (69.07% ± 3.01%)
- Precision ve Recall arasında en iyi denge

---

## SLİDE 12: REFERANS MAKALE İLE KARŞILAŞTIRMA

### Accuracy Metrikleri Karşılaştırması

| Model | Makale | Bizim Sonuç | Fark |
|-------|--------|-------------|------|
| Logistic Regression | 82.46% | 74.73% ± 4.76% | -7.73% |
| Random Forest | 81.81% | 77.47% ± 2.53% | -4.34% |
| Naïve Bayes | 79.22% | 73.82% ± 3.77% | -5.40% |
| SVM | 79.22% | 74.09% ± 2.33% | -5.13% |

**Yorum:**
- Makale sonuçları daha yüksek görünüyor
- Ancak makale tek bir train-test split kullanmış
- Bizim sonuçlarımız 5 farklı fold'un ortalaması
- Standart sapmalar gösteriyor ki performans değişkenlik gösterebiliyor
- **Bizim yaklaşımımız metodolojik olarak daha güvenilir**

### Recall (Sensitivity) Metrikleri Karşılaştırması ⭐

| Model | Makale | Bizim Sonuç | İyileşme |
|-------|--------|-------------|----------|
| **SVM** | 59.99% | **76.89% ± 3.07%** | **+16.90%** 🎯 |
| Logistic Regression | 68.23% | 73.49% ± 2.88% | +5.26% |
| Random Forest | 68.88% | 72.03% ± 4.10% | +3.15% |
| Naïve Bayes | 64.44% | 61.19% ± 3.06% | -3.25% |

**Önemli Başarı:**
- **SVM'de %16.9 puan iyileşme!**
- Diyabet teşhisinde kritik olan recall metriğinde önemli iyileşme
- Class weights ve KNN Imputer etkisi

---

## SLİDE 13: CONFUSION MATRİX ANALİZİ

### Tüm Modellerin Confusion Matrix'leri

**Gözlem:**
- Tüm modeller **precision** metriğinde zorlanıyor
- Yani modeller "hasta olmayan birini hasta olarak etiketlemeye" meyilli
- Bu, recall'u artırmak için class weights kullanımının bir sonucu

### Model Bazında Analiz

**SVM:**
- En yüksek True Positive oranı
- En düşük False Negative oranı
- Diyabet teşhisi için en uygun model

**Random Forest:**
- En dengeli confusion matrix
- Hem precision hem recall'da iyi performans

**Logistic Regression:**
- İkinci en yüksek recall
- Düşük standart sapma ile güvenilir

---

## SLİDE 14: METODOLOJİK İYİLEŞTİRMELER

### Uygulanan İyileştirmeler

#### 1. 5-Fold Stratified Cross Validation
- ✅ Tek bir train-test split yerine 5 farklı bölünme
- ✅ Model performansının tutarlılığını gösterir
- ✅ Overfitting riskini azaltır
- ✅ Standart sapma ile güvenilirlik ölçülür

#### 2. KNN Imputer
- ✅ Basit ortalama yerine mesafe bazlı doldurma
- ✅ Veri yapısını korur
- ✅ Her fold için ayrı uygulanır (data leakage önleme)

#### 3. Class Weights
- ✅ Dengesiz veri setinde recall'u iyileştirir
- ✅ 'balanced' parametresi ile otomatik ağırlıklandırma
- ✅ Diyabet teşhisinde kritik olan "hasta tespit etme" yeteneğini artırır

#### 4. Pipeline Yaklaşımı
- ✅ Preprocessing her fold için ayrı yapılır
- ✅ Data leakage önlenir
- ✅ Gerçek dünya performansı daha iyi tahmin edilir

#### 5. Parametre Optimizasyonu
- ✅ Grid Search ile her model için optimal parametreler
- ✅ Makalede belirtilmeyen parametreler optimize edildi

#### 6. MLP Classifier Eklendi
- ✅ Makalede kullanılmayan modern bir yöntem
- ✅ Derin öğrenme yaklaşımı

---

## SLİDE 15: SONUÇLAR VE YORUMLAR - 1

### Genel Performans Değerlendirmesi

**Metodolojik Üstünlük:**
- 5-Fold CV yaklaşımı, tek bir split'ten daha güvenilir
- Standart sapmalar (2-5%) performans değişkenliğini gösteriyor
- Makale sonuçları "şanslı" bir split'ten kaynaklanıyor olabilir

**Recall Metriklerinde Başarı:**
- Tüm modellerde (Naïve Bayes hariç) makaleyi geçtik
- Özellikle SVM'de %16.9 puan iyileşme
- Class weights ve KNN Imputer etkisi kanıtlandı

**Accuracy Metriklerinde:**
- Makale sonuçlarından düşük görünüyor
- Ancak bu, metodolojik üstünlüğümüzün bir göstergesi
- Gerçek dünya performansı daha iyi tahmin ediliyor

---

## SLİDE 16: SONUÇLAR VE YORUMLAR - 2

### Model Bazında Detaylı Analiz

#### SVM - En İyi Recall Performansı
- **76.89% ± 3.07%** recall değeri
- Diyabet teşhisinde kritik olan "hasta tespit etme" yeteneği en güçlü
- Düşük standart sapma (3.07%) → tutarlı performans
- **Öneri:** Diyabet taraması için en uygun model

#### Random Forest - En Dengeli Performans
- **77.47% ± 2.53%** accuracy (en yüksek)
- **69.07% ± 3.01%** F1-Score (en yüksek)
- Ensemble yapısı sayesinde overfitting'e dirençli
- **Öneri:** Genel kullanım için en uygun model

#### Logistic Regression - Güvenilir Performans
- **73.49% ± 2.88%** recall (ikinci en yüksek)
- Düşük standart sapma → güvenilir
- Basit ve yorumlanabilir
- **Öneri:** Yorumlanabilirlik önemliyse tercih edilebilir

---

## SLİDE 17: SONUÇLAR VE YORUMLAR - 3

### Precision Problemi

**Gözlem:**
- Tüm modeller precision metriğinde zorlanıyor (60-67%)
- Modeller "hasta olmayan birini hasta olarak etiketlemeye" meyilli
- Bu, recall'u artırmak için class weights kullanımının bir sonucu

**Trade-off:**
- Recall ↑ → Precision ↓
- Diyabet teşhisinde recall daha kritik
- False Negative (hastayı sağlıklı sanmak) maliyeti yüksek

**Çözüm Önerileri:**
- Precision'ı artırmak için threshold tuning yapılabilir
- Farklı class weight değerleri denenebilir
- Ensemble yöntemlerle precision iyileştirilebilir

### Standart Sapma Analizi

**En Tutarlı Modeller:**
1. SVM: 2.33% (accuracy), 3.07% (recall)
2. Random Forest: 2.53% (accuracy), 4.10% (recall)
3. Logistic Regression: 4.76% (accuracy), 2.88% (recall)

**Yorum:**
- Düşük standart sapma → farklı veri bölünmelerinde tutarlı performans
- Yüksek standart sapma → modelin veri bölünmelerine duyarlı olduğunu gösterir

---

## SLİDE 18: ÖZET VE ANA BULGULAR

### Proje Başarıları

✅ **Metodolojik İyileştirmeler:**
- 5-Fold Stratified Cross Validation
- KNN Imputer ile gelişmiş ön işleme
- Pipeline yaklaşımı ile data leakage önleme
- Class weights ile sınıf dengesizliği yönetimi

✅ **Performans İyileştirmeleri:**
- **SVM Recall:** %59.99 → %76.89 (+16.9 puan) 🎯
- **Logistic Regression Recall:** %68.23 → %73.49 (+5.26 puan)
- **Random Forest Recall:** %68.88 → %72.03 (+3.15 puan)

✅ **Model Çeşitliliği:**
- 5 farklı algoritma test edildi
- MLP Classifier eklendi (makalede yok)
- Her model için parametre optimizasyonu yapıldı

### Ana Bulgular

1. **SVM** diyabet teşhisi için en uygun model (en yüksek recall)
2. **Random Forest** genel kullanım için en dengeli model
3. **Class weights** recall'u önemli ölçüde iyileştirdi
4. **K-Fold CV** metodolojik olarak daha güvenilir sonuçlar verdi

---

## SLİDE 19: GELECEK ÇALIŞMALAR VE ÖNERİLER

### Önerilen İyileştirmeler

#### 1. Precision İyileştirme
- Threshold tuning ile precision-recall dengesi optimize edilebilir
- Farklı class weight değerleri denenebilir
- Ensemble yöntemlerle precision artırılabilir

#### 2. Özellik Mühendisliği
- Yeni özellikler türetilebilir (ör. BMI × Age)
- Özellik seçimi yapılabilir
- PCA veya diğer boyut azaltma teknikleri denenebilir

#### 3. Model Geliştirme
- Daha derin sinir ağları denenebilir
- XGBoost, LightGBM gibi gradient boosting yöntemleri eklenebilir
- Stacking veya voting ensemble yöntemleri kullanılabilir

#### 4. Veri Artırma
- SMOTE gibi tekniklerle azınlık sınıf artırılabilir
- Daha fazla veri toplanabilir

#### 5. Model Yorumlanabilirliği
- SHAP değerleri ile özellik önem analizi
- LIME ile lokal açıklamalar
- Tıbbi uygulamalar için kritik

---

## SLİDE 20: KAYNAKÇA VE TEŞEKKÜR

### Kaynakça

[1] R. Rastogi and M. Bansal, "Diabetes prediction model using data mining techniques," Measurement: Sensors, vol. 25, art. no. 100605, 2023. DOI: https://doi.org/10.1016/j.measen.2022.100605.

[2] UCI Machine Learning Repository, "Pima Indians Diabetes Database," Kaggle. [Online]. Erişim Adresi: https://www.kaggle.com/datasets/uciml/pima-indians-diabetes-database. [Erişim Tarihi: 13 Aralık 2025].

### Kullanılan Kütüphaneler
- scikit-learn (modeller, preprocessing, metrics)
- pandas (veri işleme)
- numpy (sayısal hesaplamalar)
- matplotlib/seaborn (görselleştirme)

### Teşekkür
- Prof. Dr. Songül VARL'a danışmanlığı için
- Açık kaynak topluluğuna veri seti ve kütüphaneler için

---

## SLİDE 21: SORULAR VE CEVAPLAR

**Soru-Cevap Bölümü**

**Hazır Cevap Notları:**

**S: Neden accuracy yerine recall'a odaklandınız?**
C: Diyabet teşhisinde hasta olanları kaçırmamak (False Negative) çok kritik. Recall, hasta olanları tespit etme yeteneğini ölçer. Accuracy, dengesiz veri setlerinde yanıltıcı olabilir.

**S: Makale sonuçlarınız neden daha düşük?**
C: Makale tek bir train-test split kullanmış, biz 5-Fold CV kullandık. Bizim sonuçlarımız daha güvenilir çünkü farklı veri bölünmelerinde test edildi. Standart sapmalar bunu gösteriyor.

**S: SVM'de neden bu kadar büyük iyileşme oldu?**
C: Class weights ve KNN Imputer kullanımı SVM'in performansını önemli ölçüde artırdı. Özellikle sınıf dengesizliği yönetimi SVM için kritik.

**S: Precision neden düşük?**
C: Recall'u artırmak için class weights kullandık. Bu, precision'da bir düşüşe neden oldu. Ancak diyabet teşhisinde recall daha kritik. Threshold tuning ile bu denge optimize edilebilir.

---

## EK NOTLAR: SUNUM İPUÇLARI

### Görselleştirme Önerileri
1. **Slide 6-7:** EDA grafiklerini göster (sınıf dağılımı, histogramlar, korelasyon matrisi)
2. **Slide 11:** Model performans tablosunu vurgula
3. **Slide 12:** Makale karşılaştırma grafiğini göster (paper_comparison.png)
4. **Slide 13:** Confusion matrix'leri göster (all_confusion_matrices.png)
5. **Slide 14:** Model karşılaştırma grafiklerini göster (all_models_comparison.png)

### Sunum Süresi Tahmini
- Toplam: ~20-25 dakika
- Her slayt: ~1-1.5 dakika
- Soru-cevap: 5-10 dakika

### Vurgulanması Gereken Noktalar
1. ⭐ **SVM'de %16.9 puan recall iyileştirmesi**
2. ⭐ **Metodolojik üstünlük (K-Fold CV)**
3. ⭐ **Class weights ve KNN Imputer etkisi**
4. ⭐ **Pipeline yaklaşımı ile data leakage önleme**

### Teknik Detaylar (Gerekirse)
- Grid Search parametreleri
- KNN Imputer k değeri (k=5)
- Cross Validation fold sayısı (5)
- Random state (42)

---

## SUNUM HAZIRLIK KONTROL LİSTESİ

- [ ] Tüm grafikler hazır ve kaliteli
- [ ] Tablolar düzenli ve okunabilir
- [ ] Kod örnekleri varsa test edilmiş
- [ ] Kaynakça doğru ve tam
- [ ] Sunum süresi test edilmiş
- [ ] Soru-cevap için hazır cevaplar not edilmiş
- [ ] Görselleştirmeler yüksek çözünürlükte
- [ ] Slayt geçişleri akıcı

---

**Sunum İçeriği Hazır!** 🎉

Bu içerik, raporunuzdaki tüm önemli noktaları kapsar ve akademik bir sunum için uygun yapıdadır. Her slayt için detaylı içerik, görselleştirme önerileri ve sunum ipuçları eklenmiştir.



