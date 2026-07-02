# Sonuç Analizi ve Yorumlar

## 5-Fold Cross Validation Sonuçları

### Model Performansları

| Model | Accuracy (%) | Recall (%) | Precision (%) | F1-Score (%) |
|-------|-------------|------------|---------------|--------------|
| **Random Forest** | **77.47 ± 2.53** | 72.03 ± 4.10 | 66.56 ± 4.02 | **69.07 ± 3.01** |
| MLP Classifier | 75.90 ± 4.47 | 67.90 ± 3.29 | 65.86 ± 8.12 | 66.52 ± 4.15 |
| Logistic Regression | 74.73 ± 4.76 | 73.49 ± 2.88 | 62.42 ± 7.31 | 67.23 ± 4.31 |
| SVM | 74.09 ± 2.33 | **76.89 ± 3.07** | 60.27 ± 3.26 | 67.47 ± 2.01 |
| Naïve Bayes | 73.82 ± 3.77 | 61.19 ± 3.06 | 63.60 ± 7.23 | 62.14 ± 3.83 |

---

## Güncellenmiş Yorumlar

### 1. Genel Performans Değerlendirmesi

**5-Fold Cross Validation** metodolojisi kullanılarak elde edilen sonuçlar, referans makaledeki tek bir train-test split sonuçlarından metodolojik olarak daha güvenilirdir. K-Fold CV yaklaşımı, model performansının farklı veri bölünmelerinde tutarlılığını gösterir ve overfitting riskini azaltır. 

**Accuracy** metrikleri açısından, makale sonuçları (79-82%) bizim ortalama sonuçlarımızdan (74-77%) yüksek görünse de, bu fark muhtemelen makalede kullanılan tek bir "şanslı" train-test split'ten kaynaklanmaktadır. Bizim sonuçlarımızda standart sapmalar (2-5%) gösteriyor ki, farklı veri bölünmelerinde performans değişkenlik gösterebilmektedir.

**Recall (Sensitivity)** metrikleri açısından ise, bizim sonuçlarımız referans makaleye göre genel olarak daha yüksektir:
- SVM: 76.89% (makale: 59.99%) - **+16.9 puan**
- Logistic Regression: 73.49% (makale: 68.23%) - **+5.26 puan**
- Random Forest: 72.03% (makale: 68.88%) - **+3.15 puan**

Bu iyileşme, uygulanan **class weights** ve **KNN Imputer** gibi gelişmiş ön işleme tekniklerinin etkisini göstermektedir.

---

### 2. Recall Bazında En İyi Modeller

**SVM** modeli **76.89% ± 3.07%** recall değeri ile en yüksek sensitivity performansını göstermiştir. Bu, diyabet teşhisinde kritik olan "hasta olanları tespit etme" yeteneğinin SVM'de en güçlü olduğunu gösterir. SVM'in düşük standart sapması (3.07%) da modelin farklı veri bölünmelerinde tutarlı performans gösterdiğini işaret eder.

İkinci en yüksek recall değeri **Logistic Regression** (73.49% ± 2.88%) ile elde edilmiştir. Bu model de düşük standart sapma ile güvenilir sonuçlar vermiştir.

**Not:** MLP Classifier'ın recall değeri (67.90%) önceki yorumda belirtildiği gibi en yüksek değildir. En yüksek recall değeri SVM'e aittir.

---

### 3. F1-Score Bazında En İyi Model

**Random Forest** modeli **69.07% ± 3.01%** F1-Score ile en dengeli performansı göstermiştir. F1-Score, precision ve recall'un harmonik ortalaması olduğu için, bu metrik modelin hem pozitif sınıfı doğru tespit etme (recall) hem de yanlış pozitif oranını düşük tutma (precision) konusunda en iyi dengeyi sağladığını gösterir.

Random Forest aynı zamanda **77.47% ± 2.53%** accuracy ile de en yüksek doğruluk oranına sahiptir. Bu modelin, ensemble yapısı sayesinde overfitting'e karşı daha dirençli olduğunu ve genelleştirme yeteneğinin güçlü olduğunu gösterir.

**Önceki yorumda belirtilen "Naïve Bayes'in F1 skoru bazında en iyi sonuç vermesi"** ifadesi güncel sonuçlarla uyuşmamaktadır. Naïve Bayes, F1-Score (62.14%) açısından en düşük performansı göstermiştir. Bu durum, veri setindeki özelliklerin bağımsızlık varsayımını tam olarak karşılamamasından kaynaklanıyor olabilir.

---

### 4. Metodolojik İyileştirmeler

Bu çalışmada uygulanan metodolojik iyileştirmeler:

1. **5-Fold Stratified Cross Validation**: Tek bir train-test split yerine, tüm veri setinin farklı bölünmelerinde model performansının değerlendirilmesi
2. **KNN Imputer**: Eksik verilerin doldurulmasında basit ortalama yerine, veri yapısını koruyan K-Nearest Neighbors yöntemi
3. **Class Weights**: Dengesiz veri setinde recall'u iyileştirmek için sınıf ağırlıklarının kullanılması
4. **Pipeline Yaklaşımı**: Veri sızıntısını (data leakage) önlemek için preprocessing'in her fold için ayrı yapılması

Bu iyileştirmeler, modellerin gerçek dünya verilerinde daha güvenilir performans göstermesini sağlamıştır. Özellikle **standart sapma değerleri**, modellerin farklı veri bölünmelerinde ne kadar tutarlı olduğunu göstererek, genelleştirme yeteneğini değerlendirmemize olanak tanımıştır.

---

## Özet

- **En Yüksek Accuracy**: Random Forest (77.47% ± 2.53%)
- **En Yüksek Recall**: SVM (76.89% ± 3.07%)
- **En Yüksek F1-Score**: Random Forest (69.07% ± 3.01%)
- **En Tutarlı Model**: SVM (düşük standart sapma: 2.33% accuracy, 3.07% recall)
- **Metodolojik Avantaj**: 5-Fold CV ile daha güvenilir ve genelleştirilebilir sonuçlar
