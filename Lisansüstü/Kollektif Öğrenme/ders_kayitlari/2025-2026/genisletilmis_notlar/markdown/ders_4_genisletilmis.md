# Ders 4 Genişletilmiş Notu: Ödev Sunumları: Tez Yılı Tahmininde Bagging, Random Subspace ve Random Forest

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Ödev problemi ve ortak deney düzeni
- 2. Kullanılan kollektif öğrenme yöntemleri
- 3. Hiperparametre optimizasyonu
- 4. Sınıflandırma olarak kurulan çözümler
- 5. Sınıflandırma mı regresyon mu?
- 6. Regresyon olarak kurulan çözümler
- 7. Karar ağacı dışındaki taban öğreniciler
- 8. Çeşitlilik ve rastgeleliğin etkisi
- 9. Sınıf sayısını azaltan ek denemeler
- 10. Sunumlardan çıkan ortak sonuçlar
- Örnek Sorular

## 1. Ödev problemi ve ortak deney düzeni

Bu ders, dönemin ikinci ödevinin sunumlarına ayrılmıştır. Öğrenciler sırayla ekran paylaşıp raporlarını, slaytlarını ya da Jupyter defterlerini göstermiş, hoca her sunum sırasında ve sonunda sorular sormuştur. Bu notta sunumlar kişi adı verilmeden, konu sırasına göre bir araya getirilmiştir.

Ödevin problemi şudur: bir Türkçe akademik tezin yalnız başlığına ve özetine bakarak tezin hangi yılda yayımlandığını tahmin etmek. Öğrencilerin belirttiği gibi tez konuları yıllara yayılan yavaş trendler izlediği için bu zor bir problemdir; bir yılın tezleri bir önceki yılın tezlerine çok benzer.

### 1.1 Veri

Veri, Hugging Face'teki Türkçe akademik tez veri setinden alınmıştır (ekrandan, 00:20:00). Ortak düzen bir slaytta şöyle özetlenmiştir (ekrandan, 00:50:00):

- 2001-2024 arasındaki her yıl için 500 tez rastgele seçilir (üniversite ya da konu ayrımı yapılmadan).
- Her yılın 250 tezi eğitim, 250 tezi test kümesine ayrılır.
- 2025 yılı için veri olmadığından bu yıl dahil edilmez. Toplam tez sayısı $24 \times 500 = 12000$ olur.

Bazı öğrenciler 25 yıl elde etmek için 2025 yerine 2000 yılını almış ve 12500 tezle çalışmıştır. Bir öğrenci veri setinde 160 farklı konu bulunduğunu, bir yılın içinde çok farklı konular olabileceği için sınıf içi varyansın yüksek olduğunu gözlemlemiştir. Başka bir grup veriyi önce incelemiş: başlık, özet ve yıl alanlarında boş değer olmadığını görmüş, başlık ve özet uzunluklarının yıllara göre anlamlı biçimde farklılaştığını ANOVA ile, yıl ile uzunluk arasındaki ilişkiyi Spearman korelasyonuyla ölçmüştür. Sonuç: metinler yıllar içinde kısmen uzasa da uzunluk tek başına yıl tahmini için yeterli değildir.

### 1.2 Metin temsilleri

Metinler `ytu-ce-cosmos/turkish-e5-large` modeliyle vektörlere dönüştürülmüştür (ekrandan, 00:20:00). Üç temsil kullanılmıştır:

| Temsil | Boyut | Eğitim | Test |
|---|---|---|---|
| Başlık (title) | 1024 | başlık eğitim vektörleri | başlık test vektörleri |
| Özet (abstract) | 1024 | özet eğitim vektörleri | özet test vektörleri |
| Başlık + Özet (concat) | 2048 | birleşik eğitim vektörleri | birleşik test vektörleri |

Birleşik temsil iki vektörün uç uca eklenmesiyle elde edilir. Böylece 3 temsil × (eğitim, test) = 6 veri kümesi oluşur ve her biri 3 yöntemle denenir: toplam 9 deney.

### 1.3 Rastgele taban

24 sınıflı bir sınıflandırmada rastgele bir tahminin doğru çıkma olasılığı

$$\frac{1}{24} \approx 0.042$$

yani yaklaşık %4'tür. Sunumlarda bütün doğruluk değerleri bu tabanla karşılaştırılmıştır; örneğin %7.5 doğruluk tabanın yaklaşık 1.8 katıdır.

## 2. Kullanılan kollektif öğrenme yöntemleri

Bir öğrencinin slaytında üç yöntem şöyle tanımlanmıştır (ekrandan, 00:05:00):

- **Bagging:** Ana veri setinden rastgele ve yerine koymalı (yani aynı örnek tekrar seçilebilir) örneklemler alarak çok sayıda alt veri seti oluşturur. Her alt set için bir karar ağacı eğitir ve sonunda çoğunluk oylamasıyla karar verir.
- **Random Subspace:** Veri satırlarının tamamını kullanır, ancak her ağacı eğitirken özelliklerin yalnız rastgele seçilmiş bir kısmını (örneğin %50'sini) modele verir.
- **Random Forest:** Özelliklerin tamamı yerine rastgele bir kısmına bakarak daha çeşitli ağaçlar elde eder.

Başka bir raporda farklar şöyle karşılaştırılmıştır (ekrandan, 00:25:00): Bagging'de ağaçlar verinin farklı alt parçalarını görür ve farklı karar sınırları öğrenir; oylama tek bir ağacın dengesiz kararlarını törpüler. Random Subspace'te rastgelelik örneklerde değil özelliklerdedir; her ağaç bütün eğitim örneklerini görür ama embedding boyutlarının hepsini görmez. Random Forest ise Bagging'e ek olarak düğüm bazında özellik rastgeleliği kullanır. Bir başka raporda Random Forest'ın amacı "her düğümde rastgele öznitelik seçimiyle ağaçlar arasındaki korelasyonu azaltmak" diye yazılmıştır (ekrandan, 01:10:00).

Bir öğrenci farkı şöyle sezgiselleştirmiştir: Bagging'de bütün tahminleyiciler aynı özellik uzayını gördüğü için birbirine benzer modeller üretir. Random Subspace her tahminleyiciyi farklı bir alt uzaya sokar ama örneklemi değiştirmez. Random Forest ikisini birlikte yapar.

> **Ek bilgi (derste anlatılmadı):** Yerine koymalı örneklemede bir örneğin bir bootstrap örnekleminde hiç seçilmeme olasılığı büyük $n$ için yaklaşık $1/e$'dir. Bu yüzden her ağaç farklı örneklerin yaklaşık %63'ünü görür. `max_samples` gibi bir parametreyle örneklem küçültülürse ağaçlar arasındaki fark daha da artar.

## 3. Hiperparametre optimizasyonu

### 3.1 Optimize edilen parametreler

Sunumlarda optimize edilen başlıca parametreler şunlardır (ekrandan, 00:30:00):

- Üç yöntemde ortak: ağaç (tahminleyici) sayısı `n_estimators`, örneğin 50, 100, 200.
- Random Forest: ağaç derinliği `max_depth`, örneğin 10, 20, 30 ya da sınırsız.
- Bagging: her ağacın gördüğü örnek oranı `max_samples`, örneğin 0.5, 0.7, 1.0.
- Random Subspace: her ağacın gördüğü özellik oranı `max_features`, örneğin 0.3, 0.5, 0.7.
- Bazı çalışmalarda ayrıca yaprak başına en az örnek `min_samples_leaf` ve budama parametreleri `ccp_alpha`, `min_impurity_decrease`.

Bir raporda Bagging için denenen kombinasyonlar şunlardır (ekrandan, 00:20:00):

```python
param_grid = [
    {"n_estimators": 200, "max_samples": 0.6},
    {"n_estimators": 200, "max_samples": 1.0},
    {"n_estimators": 400, "max_samples": 0.6},
    {"n_estimators": 400, "max_samples": 1.0},
]
```

### 3.2 Arama yöntemleri

- **Grid Search CV:** bütün kombinasyonları dener. Bir grup bu yöntemle aramanın saatlerce sürdüğünü ve yarıda kesildiğini anlatmıştır.
- **Randomized Search CV:** verilen aralıklardan rastgele kombinasyonlar dener, daha hızlıdır. Bir grupta Random Forest için aralıklar şöyledir (ekrandan, 01:40:00): `n_estimators` için randint(50, 121), `max_depth` için [10, 20], `min_samples_leaf` için randint(5, 10).
- **Bayesçi optimizasyon:** bir grup Optuna kütüphanesini kullanmıştır. Gerekçeleri, önceki denemelerin sonuçlarından bir model kurup sıradaki denemeyi bu modele göre seçmektir. Deneme sayısını 10 tutmuşlar, en iyi değeri genelde ilk birkaç denemede bulduklarını gözlemlemişlerdir.

Eğitim süreleri çok uzun olduğu için (bir ensemble'ın eğitimi bazı çalışmalarda 40 dakikayı aşmıştır) çoğu öğrenci 5 ya da 10 katlı yerine 3 katlı çapraz doğrulama kullanmıştır.

### 3.3 Optimizasyonda hangi küme kullanılır?

Bayesçi optimizasyon kullanan gruba hoca, optimizasyonda hangi kümeyi kullandıklarını sormuştur.

**Soru:** Hiperparametre optimizasyonunda hangi kümeyi kullandınız? **Cevap:** Eğitim kümesini kullandık. Ayrı bir doğrulama kümesi ayırmadık; çapraz doğrulama eğitim kümesini kendi içinde böldüğü için ona güvendik. Hoca bunu onaylamıştır: test verisi optimizasyon sürecine hiçbir şekilde girmemiştir ve doğrusu budur.

> **Hocanın vurgusu:** Test verisi hiperparametre optimizasyonuna hiçbir şekilde girmemelidir; optimizasyon yalnız eğitim kümesi üzerinde (çapraz doğrulamayla) yapılır.

Bir öğrenci çapraz doğrulama adımlarını şöyle anlatmıştır: her model ve temsil ikilisi için denenecek ayar kombinasyonları belirlenir; eğitim kümesi birkaç eşit parçaya bölünür; her kombinasyon için parçalardan biri doğrulama, kalanlar eğitim olarak kullanılıp hata hesaplanır; parçalar yer değiştirilerek işlem tekrarlanır ve ortalama hata alınır; en iyi kombinasyonun başarısı en sonda test kümesinde ölçülür.

## 4. Sınıflandırma olarak kurulan çözümler

### 4.1 Derinlik sorusu

İlk sunumda Random Forest'ta ağaç derinliği 10 seçilmiştir. Hoca bu seçimi sorgulamıştır.

**Soru:** Niye derinliği 10 seçtin? Elinde 1024 boyutlu bir veri var, 10 çok az bir derinlik değil mi? **Cevap:** 20-30 derinliğe çıkmaya çalıştım ama eğitim çok yavaşladı; 10 derinlikte bile bir ensemble'ın eğitimi yaklaşık 40 dakika sürdü.

Aynı sunumda karışıklık matrisinde tahminlerin rastgele dağılmak yerine gerçek yılın çevresinde kümelendiği gösterilmiştir: model yanlış bilse bile yakın bir yılı söylemektedir.

### 4.2 Ayrıntılı bir sınıflandırma tablosu

Bir öğrencinin en iyi parametrelerle elde ettiği sonuçlar (ekrandan, 00:15:00):

| Model | Temsil | En iyi parametreler | CV F1 | Test Acc | Test F1 |
|---|---|---|---|---|---|
| Bagging | Title | n_est=100, max_samp=0.75 | 0.0436 | 0.0478 | 0.0465 |
| Random Subspace | Title | n_est=30, max_feat=0.3 | 0.0479 | 0.0490 | 0.0474 |
| Random Forest | Title | n_est=100, max_depth=10 | 0.0498 | 0.0498 | 0.0490 |
| Bagging | Abstract | n_est=100, max_samp=1.0 | 0.0632 | 0.0621 | 0.0587 |
| Random Subspace | Abstract | n_est=100, max_feat=0.3 | 0.0683 | 0.0750 | 0.0702 |
| Random Forest | Abstract | n_est=100, max_depth=10 | 0.0660 | 0.0656 | 0.0624 |
| Bagging | Concat | n_est=100, max_samp=0.75 | 0.0584 | 0.0670 | 0.0640 |
| Random Subspace | Concat | n_est=100, max_feat=0.3 | 0.0629 | 0.0683 | 0.0642 |
| Random Forest | Concat | n_est=100, max_depth=20 | 0.0627 | 0.0638 | 0.0629 |

Öğrencinin bu tablodan çıkardığı gözlemler:

- Ağaç sayısını artırmak başarıyı garanti etmez. Başlık temsilinde Random Subspace en iyi sonucu 30 ağaçla vermiştir.
- Random Subspace'te en iyi özellik oranı her temsilde 0.3'tür. 1024 boyutun yaklaşık %30'u, yani 300 civarı boyut yeterli olmuştur. Öğrenci bunu embedding'lerde gereksiz boyutların bulunabileceğiyle açıklamıştır.
- Derinliği 10, 15, 20 diye artırmak da her zaman başarıyı artırmamıştır.
- Optimizasyon, varsayılan ayarlı modellere göre %10-17 arası göreli iyileşme sağlamıştır.
- Yıl bazında F1 skorlarında uç yıllar (ilk ve son yıllar) ortalamanın üzerinde, orta yıllar altında kalmıştır.

### 4.3 Bagging'de örnek oranı

Başka bir öğrenci önce temsili (başlık + özet) sabitleyip her yöntem için hiperparametre araması yapmış, sonra bulduğu ayarları üç temsilde denemiştir. Bagging sonuçları (ekrandan, 00:20:00):

| n_estimators | max_samples | valid_accuracy | valid_macro_f1 |
|---|---|---|---|
| 200 | 0.6 | 0.0600 | 0.059444 |
| 200 | 1.0 | 0.0625 | 0.060217 |
| 400 | 0.6 | 0.0725 | 0.071346 |
| 400 | 1.0 | 0.0575 | 0.052336 |

Raporun yorumu: ağaç sayısını artırmak tek başına yeterli değildir; performans ağaç çeşitliliğiyle birlikte iyileşir. `max_samples=0.6` ile her ağaç eğitim örneklerinin yalnız %60'ıyla eğitildiği için ağaçlar arasında daha fazla çeşitlilik oluşur ve çoğunluk oylaması daha etkili olur. `max_samples=1.0` ile her ağaç bütün örnekleri gördüğünden ağaçlar birbirine benzer ve doğruluk düşer.

Aynı öğrenci Random Subspace'te özelliklerin %30'unu seçmenin daha yüksek çeşitlilik verdiğini, Random Forest'ta ise önceki iki yöntemin tersine daha az ağacın daha iyi sonuç verdiğini bulmuştur. Bütün dokuz karşılaştırmanın en iyisi Random Subspace ile başlık + özet temsilidir. Rapordaki yorum: Random Subspace'in agresif özellik seçimi yüksek boyutlu birleşik temsilde farkını ortaya koymuştur; Random Forest ise temsil boyutu arttığında zorlanmıştır (ekrandan, 00:25:00).

### 4.4 Sonuç tabloları ve yıl bazında doğruluk

Bir öğrencinin Grid Search ile bulduğu en iyi parametreler (ekrandan, 00:30:00):

| | Başlık | Özet | Başlık + Özet |
|---|---|---|---|
| Random Forest | max_depth=20, n_estimators=100 | max_depth=30, n_estimators=200 | max_depth=20, n_estimators=200 |
| Random Subspace | max_features=0.7, n_estimators=100 | max_features=0.3, n_estimators=200 | max_features=0.5, n_estimators=200 |
| Bagging | max_samples=1.0, n_estimators=200 | max_samples=1.0, n_estimators=200 | max_samples=1.0, n_estimators=200 |

Öğrenci, başlık temsilinin daha büyük özellik oranı (0.7), özet temsilinin daha küçük özellik oranı (0.3) istediğini yorumlamıştır. Random Subspace'in yıl bazında doğruluk grafiğinde özet için ortalama 0.080, birleşik temsil için 0.077 görünmektedir (ekrandan, 00:35:00). Karışıklık matrislerinde başlık temsilinde belirgin bir kümelenme yokken özette köşegen çevresinde koyu bölgeler oluşmuştur; örneğin 2004-2007 yıllarının vektörleri birbirine yakın düşmüştür.

## 5. Sınıflandırma mı regresyon mu?

Bu dersteki en önemli tartışma, problemin nasıl kurulması gerektiğidir. Yıl sıralı (ordinal) bir değişkendir. Sınıflandırma ise sınıfları sırasız etiketler olarak görür.

Bir öğrenci karışıklık matrisinde hataların yakın yıllarda toplandığını, literatürün bir önceki yıla benzediğini ve sınıflar arasında örtüşme olduğunu anlatınca hoca araya girmiştir.

**Soru:** Bu gözlem, problemin aslında bir sınıflandırma problemi değil bir regresyon problemi olduğunu göstermiyor mu? 2001'e 2002 demekle 2001'e 2012 demek arasında sence fark yok mu? **Cevap:** Öğrenci problemi baştan sınıflandırma olarak düşündüğünü, farkın olabileceğini kabul etmiştir. Hoca üzerinde düşünülmesini istemiştir.

> **Hocanın vurgusu:** Tahminlerin yakın yıllarda toplanması, yıl tahmininin doğası gereği bir regresyon problemi olduğunu gösterir. Sınıflandırmada 1 yıllık ve 10 yıllık hata aynı sayılır.

Başka bir öğrenci sınıflandırıcıyla eğitip, tahmin edilen yılı sayıya çevirerek "sapma" (tahmin eksi gerçek) ölçmüştür.

**Soru:** Sınıflandırmada 6 yıllık sapmayı nasıl tanımlıyorsun, nasıl hesapladın? **Cevap:** Sınıflar yıl olduğu için tahmini sayıya çevirip gerçek yıldan çıkardım; model sayısal tahmin etmiyor ama sonucu sayıya çevirebiliyorum. Hoca regresyon kullanılsaydı buna hiç gerek kalmayacağını belirtmiştir. Ayrıca grafikte görülen 6 yılın ortalama değil en küçük değer gibi göründüğünü sormuş, öğrenci emin olamamıştır. <!-- BELİRSİZ: grafikteki 6 yıllık değerin ortalama mı başka bir istatistik mi olduğu derste netleşmedi. -->

Öğrencilerin hata analizinde ortalardaki yılların daha az, uçtaki yılların daha fazla hatayla tahmin edildiği konuşulmuştur. Bir öğrenci bunu, ilk yılların daha önceki bir trendin devamı olabileceğiyle açıklamıştır.

Bir öğrenci sunumunun sonunda regresyon olarak bakmanın daha doğru olduğunu kabul etmiştir: trendler keskin bir çizgiyle değişmez, zamanla kayar.

## 6. Regresyon olarak kurulan çözümler

### 6.1 MAE ve RMSE ile ölçülen bir çalışma

Problemi regresyon olarak kuran bir öğrencinin sonuçları (ekrandan, 00:55:00):

| Veri | Model | En iyi parametreler | MAE | RMSE |
|---|---|---|---|---|
| Title Emb. | Bagging | max_samples=0.7, n_estimators=100 | 6.6391 | 5.7087 |
| Title Emb. | Random Subspace | estimator__max_depth=10, max_features=0.5, n_estimators=100 | 6.6423 | 5.7098 |
| Title Emb. | Random Forest | max_depth=None, n_estimators=100 | 6.6598 | 5.7119 |
| Abstract Emb. | Bagging | max_samples=1.0, n_estimators=100 | 5.9475 | 5.0133 |
| Abstract Emb. | Random Subspace | estimator__max_depth=None, max_features=0.7, n_estimators=100 | 5.9875 | 5.0514 |
| Abstract Emb. | Random Forest | max_depth=None, n_estimators=100 | 5.9428 | 5.0035 |
| Concatenated Emb. | Bagging | max_samples=1.0, n_estimators=100 | 6.0178 | 5.0804 |
| Concatenated Emb. | Random Subspace | estimator__max_depth=None, max_features=0.5, n_estimators=100 | 6.0569 | 5.1395 |
| Concatenated Emb. | Random Forest | max_depth=None, n_estimators=100 | 6.0185 | 5.0816 |

Sıralama yine özet, birleşik, başlık şeklindedir. Öğrenci, başlık temsilinde Bagging'in diğer ikisinden biraz iyi olmasını, başlığın anlamı zayıf taşımasıyla açıklamıştır.

> **Ders sonrası not:** Bu tabloda her satırda RMSE, MAE'den küçük görünmektedir. Oysa her hata dizisi için $\mathrm{RMSE} = \sqrt{\tfrac{1}{n}\sum e_i^2} \ge \tfrac{1}{n}\sum |e_i| = \mathrm{MAE}$ olur (karesel ortalama, mutlak ortalamadan küçük olamaz). Değerler büyük olasılıkla yanlış hesaplanmış ya da sütunlar karışmıştır. Bu konu derste konuşulmamıştır.

### 6.2 $R^2$ ile ölçülen bir çalışma

Başka bir öğrenci regresyonu $R^2$ ve RMSE ile değerlendirmiştir. Varsayılan ayarlarda Bagging tarafında negatif, Random Subspace tarafında sıfır $R^2$ görünce hiperparametrelerle oynamış, ağaç sayısını artırınca değerler yükselmiştir. Sonuç grafiğinde en yüksek $R^2$ değerleri özet temsilinde yaklaşık 0.22-0.23, başlıkta 0.07-0.08 düzeyindedir; RMSE ise 6 civarındadır (ekrandan, 01:00:00).

Bu çalışmada denenen diğer adımlar:

- `max_features` için 0.7, 0.6, 0.5 denenmiş, 0.7 en iyi bulunmuştur. Daha küçük oranlarda $R^2$ düşmüştür.
- Random Forest'ta ağaç sayısını 1000'e çıkarmak çok küçük bir artış sağlamış, eğitim süresini uzattığı için 500'de bırakılmıştır.
- PCA ile 256 boyuta indirme sonuçları bozmuştur; öğrenci önemli bilgiyi kaybettiğini düşünüp PCA'yı geri almıştır.
- Budama: `max_depth` belli bir derinlikte büyümeyi durdururken `ccp_alpha` ve `min_impurity_decrease` ağaç tam büyüdükten sonra maliyet hesabına göre budar. `ccp_alpha` 0.1'e çıkarılınca $R^2$ biraz artmış, en iyi değer 0.23'ten 0.236 civarına gelmiştir. <!-- BELİRSİZ: altyazıda "0.2.30" ve "0.2.36" diye geçiyor; değerler büyük olasılıkla 0.230 ve 0.236. -->

### 6.3 Bayesçi optimizasyonlu bir grup

Optuna kullanan grup problemi regresyon olarak kurmuş, taban öğrenici olarak regresyon karar ağacı kullanmıştır. Sınıflandırmayı da denemişler ama %4 civarı doğruluk görünce vazgeçmişlerdir. Ağaç sayısını 300'e kadar denemiş, anlamlı bir fark görmeyince daha küçük aralıkta aramışlardır. Özette $R^2$ 0.177'ye kadar çıkmıştır. Sonuçlarını, tezlerde kullanılan kelimelerin büyük ölçüde ortak olması ve çalışmanın belirli bir alana (örneğin yalnız bilgisayar mühendisliği tezlerine) odaklanmamasıyla açıklamışlardır.

### 6.4 Doğrulukla birlikte regresyon ölçütleri

Bir öğrenci regresyon çıktısını en yakın yıla yuvarlayarak tam doğruluk, ayrıca tahminin gerçek yılın ±2 yıl çevresine düşüp düşmediğine bakarak bir "yakınlık doğruluğu" hesaplamıştır. Tam doğruluk yaklaşık %8 çıkmıştır. Öğrenci 5 yıllık bir pencerenin doğruluğu 5 katın üzerine çıkarmasını beklemiş, ancak yaklaşık 4 katına ulaşmıştır. Bu çalışmada en iyi yöntem Random Subspace olmuştur. <!-- BELİRSİZ: bu öğrencinin Random Subspace'te taban öğrenici olarak hangi regresyon modelini seçtiği altyazıda anlaşılmıyor ("Rigidic Restoration"); büyük olasılıkla Ridge regresyonu. -->

**Soru:** Problemi regresyon olarak mı aldın, sınıflandırma olarak mı? **Cevap:** Regresyon olarak, RMSE'ye göre optimize ettim.

## 7. Karar ağacı dışındaki taban öğreniciler

### 7.1 MLP ile ek deney

Bir öğrenci ödevin dışında, PCA ile 128 ve 256 boyuta indirilmiş vektörlerle hem önceki modelleri hem de basit bir MLP'yi denemiştir (ekrandan, 00:40:00). Özet temsili üzerinde:

| Model | Embedding boyutu | Accuracy | F1 | MAE |
|---|---|---|---|---|
| Bagging | 128 | 0.0717 | 0.0687 | 5.99 |
| Bagging | 256 | 0.0733 | 0.07 | 6.01 |
| Bagging | 1024 | 0.0797 | 0.0756 | 6.05 |
| PyTorch MLP | 128 | 0.0955 | 0.0936 | 5.02 |
| PyTorch MLP | 256 | 0.1056 | 0.104 | 4.82 |

<!-- BELİRSİZ: tablonun alt satırları (MLP 1024 ve Random Forest satırları) karede Zoom araç çubuğunun altında kaldığı için okunamadı. -->

Boyut indirmenin ağaç modellerinde %1-2 düzeyinde fark yarattığı, MLP'nin ise yaklaşık %14'e kadar daha iyi sonuç verdiği söylenmiştir. Hoca bunun MLP'nin ensemble içinde değil, tek başına sınıflandırıcı olarak kullanıldığını teyit etmiş ve şunu eklemiştir: karar ağacı yerine SVM ya da MLP gibi başka bir taban model kullanılsaydı daha başarılı sonuçlar alınabilirdi.

### 7.2 MLP'yi taban öğrenici yapan bir çalışma

Başka bir öğrenci Bagging, Random Subspace ve Random Forest içinde taban öğrenici olarak MLP kullanmış, önce MLP'nin Adam optimizasyonunu ayarlamıştır. Üç temsil (X_train1, X_train2, X_train3) için doğruluklar (ekrandan, 00:45:00):

| Yöntem | Temsil | lr=1e-5, betas=(0.9, 0.999) | lr=1e-3, betas=(0.9, 0.999) | lr=1e-3, betas=(0.7, 0.999) |
|---|---|---|---|---|
| Bagging | X_train1 | 0.0562 | 0.0672 | 0.0693 |
| Bagging | X_train2 | 0.0963 | 0.1403 | 0.1421 |
| Bagging | X_train3 | 0.0758 | 0.1414 | 0.1413 |
| Random Subspace | X_train1 | 0.0538 | 0.0726 | 0.0507 |
| Random Subspace | X_train2 | 0.0664 | 0.1376 | 0.0643 |
| Random Subspace | X_train3 | 0.0659 | 0.1453 | 0.0632 |
| Random Forest | X_train1 | 0.0416 | 0.0458 | 0.0464 |
| Random Forest | X_train2 | 0.0568 | 0.0925 | 0.0581 |
| Random Forest | X_train3 | 0.0586 | 0.0869 | 0.0533 |

<!-- BELİRSİZ: X_train1/2/3'ün hangi temsile karşılık geldiği karede yazmıyor; sunumda başlık, özet ve başlık + özet sırası kullanıldığı için büyük olasılıkla bu sıradadır. -->

Öğrenme oranı $10^{-3}$ genelde daha iyi sonuç vermiştir. Özet ile başlık + özet sonuçları birbirine yakın çıktığı için öğrenci, 2048 boyutun hesaplama maliyetini gerekçe gösterip özetle devam etmiştir. Ardından tahminleyici sayısı (3, 7, 15, 20 ...), batch boyutu (8'den 256'ya) ve epoch sayısı (5, 10, 15) sırayla aranmıştır: Bagging için 7, diğer ikisi için 20 tahminleyici; batch boyutu 8 en iyi olmuş; epoch sayısı sonucu pek değiştirmemiştir. Doğruluk 0.14 civarında kalmıştır.

**Soru:** Burada taban öğrenici sayısı kaç? **Cevap:** Önce sabit tuttum; sonra 3, 7, 15, 20 gibi değerlerle ayrıca aradım.

### 7.3 Lojistik regresyon

Bir öğrenci sınıflandırmada en iyi ensemble sonucunu Random Subspace ile yaklaşık %8 bulmuş, ardından tek başına bir lojistik regresyon denemiştir (ekrandan, 01:25:00):

| Veri temsili | Model | Accuracy | Macro F1 | En iyi parametreler |
|---|---|---|---|---|
| Özet | Random Subspace | 0.0818 | 0.0768 | max_features=0.4, n_estimators=100 |
| Özet | Random Forest | 0.0763 | 0.0732 | max_depth=25, max_features=sqrt, n_estimators=150 |
| Özet | Bagging | 0.0762 | 0.0691 | max_samples=0.7, n_estimators=100 |
| Başlık | Random Subspace | 0.0560 | 0.0544 | max_features=0.7, n_estimators=50 |
| Başlık | Random Forest | 0.0538 | 0.0526 | max_depth=None, n_estimators=150 |
| Başlık | Bagging | 0.0557 | 0.0539 | max_samples=0.7, n_estimators=100 |
| Başlık+Özet | Random Subspace | 0.0730 | 0.0680 | max_features=0.4, n_estimators=100 |
| Başlık+Özet | Random Forest | 0.0708 | 0.0684 | max_depth=25, max_features=sqrt, n_estimators=100 |
| Başlık+Özet | Bagging | 0.0693 | 0.0633 | max_samples=0.7, n_estimators=100 |
| Özet | Lojistik Regresyon | 0.1307 | 0.1297 | C=10.0 |

Hoca bunun taban öğrenici olarak değil, tek başına lojistik regresyon olduğunu teyit etmiştir. Öğrenci bu sonucu, embedding uzayının yoğun ve büyük ölçüde doğrusal ayrılabilir olabileceğine yormuştur.

Başka bir öğrenci PCA ile 256 bileşene indirdiği temsillerde Random Subspace'in taban öğrenicisini karar ağacından lojistik regresyona çevirmiştir. 40 lojistik regresyonla özette %11.1 doğruluk almış; 10 ve 100 taban öğrenicide sonuç düşmüştür.

**Soru:** Random Subspace ile yine karar ağacı mı kullandın? **Cevap:** Hayır, Random Subspace burada taban tahminleyici olarak lojistik regresyon kullanıyor; 40 lojistik regresyonun her biri farklı bir özellik alt kümesini görüyor.

Bu sunumda hoca bir öneri de yapmıştır: farklı ayarların sonuçlarını üç ayrı tablo yerine tek tabloda yan yana göstermek (örneğin Bagging sütununun altına ayarı yazmak) yorumlamayı kolaylaştırır.

## 8. Çeşitlilik ve rastgeleliğin etkisi

Kollektif öğrenmenin temel fikri, birbirinden farklı hatalar yapan modelleri birleştirmektir. Birkaç sunum bunu doğrudan deneyle göstermiştir.

### 8.1 Rastgeleliği kapatmak

Bir öğrenci önce varsayılan sayılabilecek ayarlarla, sonra iki değişiklikle deney yapmıştır (ekrandan, 02:15:00):

1. Ağaç sayısını yarıya indirmek: Bagging için `n_estimators=25`, Random Forest için 50, Random Subspace için 25.
2. Rastgeleliği kapatmak: Bagging'de `bootstrap=False`, Random Forest'ta `max_depth=20` (sınırsız yerine), Random Subspace'te `bootstrap=False, bootstrap_features=False`.

İlk deneyin test doğrulukları:

| Model | Temsil | TestAccuracy |
|---|---|---|
| Bagging | title | 0.048167 |
| RandomForest | title | 0.053833 |
| RandomSubspace | title | 0.055333 |
| Bagging | abstract | 0.074000 |
| RandomForest | abstract | 0.068500 |
| RandomSubspace | abstract | 0.065000 |
| Bagging | concat | 0.062000 |
| RandomForest | concat | 0.074000 |
| RandomSubspace | concat | 0.060333 |

İkinci değişiklikten sonra Bagging'in doğrulukları düşmüştür (örneğin abstract'ta 0.074'ten 0.0565'e). Öğrencinin açıklaması: `bootstrap=False` olunca her ağaç aynı veriyi görür, rastgele örneklemenin avantajı kaybolur ve ağaçlar birbirine benzer. Random Forest'ta derinliği 20'ye sınırlamak çoğu temsilde düşüşe yol açmış, ama özette (0.0685'ten 0.074'e) artış sağlamıştır; öğrenci bunu, çok derin ağaçların gürültülü özet verisinde aşırı öğrenmeye gitmesiyle açıklamıştır. Random Subspace'te rastgeleliği kapatmak özette beklenmedik biçimde başarıyı artırmıştır (0.065'ten 0.0727'ye); öğrenci aşırı çeşitliliğin ortak bir örüntü bırakmadığını öne sürmüştür.

Ağaç sayısını yarıya indirmek beklendiği gibi bütün modellerde doğruluğu düşürmüştür. Öğrenci bunu varyansın artıp genelleme gücünün düşmesiyle açıklamıştır.

### 8.2 Özellik oranı ve ağaçlar arası benzerlik

Regresyonla çalışan bir öğrenci Random Subspace'te özellik oranını 0.3, 0.5 ve 0.8 olarak denemiş, en iyi sonucu 0.5'te almıştır. 0.3'e göre daha iyi olmasını daha çok özellik kullanılmasıyla, 0.8'de kötüleşmesini ise ağaçların birbirinden bağımsız olma durumunun bozulmasıyla açıklamıştır: her ağaç neredeyse bütün özellikleri görünce ağaçlar birbirine benzer.

Bagging'de ağaç sayısını 50'den 100'e çıkarmak ve `max_samples`'ı 0.5'ten 1'e çıkarmak bu öğrencinin çalışmasında hatayı düşürmüştür.

Bir grup Random Subspace'in yüksek boyutlu embedding'lerdeki avantajını şöyle açıklamıştır: her ağaç daha küçük ve farklı bir alt uzay görür, bu daha az gürültülü öğrenmeye yol açar ve ağaçlar arasındaki korelasyon düşer. Aynı grup sınıflandırma deneyinde şu doğrulukları raporlamıştır (ekrandan, 02:30:00):

| Algoritma | Başlık | Özet | Özet + Başlık |
|---|---|---|---|
| Bagging (max_samples: 0.5) | 0.0503 | 0.0690 | 0.0601 |
| Bagging (max_samples: 1.0) | 0.0488 | 0.0583 | 0.0618 |
| Random Subspace (max_features: 0.5) | 0.0466 | 0.0670 | 0.0625 |
| Random Subspace (max_features: 1.0) | 0.0488 | 0.0583 | 0.0618 |
| Random Forest (max_depth: None) | 0.0435 | 0.0615 | 0.0631 |
| Random Forest (max_depth: 10) | 0.0458 | 0.0651 | 0.0663 |

Bu tabloda Bagging'in `max_samples=1.0` satırı ile Random Subspace'in `max_features=1.0` satırı aynıdır. Bu beklenen bir sonuçtur: iki yöntem de bu ayarda bütün özellikleri kullanan aynı türden bir ağaç topluluğuna dönüşür.

> **Ek bilgi (derste anlatılmadı):** scikit-learn'de `BaggingClassifier` varsayılan olarak `bootstrap=True` ile örnekleri yerine koyarak çeker. Random Subspace ise genelde `BaggingClassifier` ile `bootstrap=False` ve `max_features<1.0` verilerek kurulur. İki satırın aynı çıkması, büyük olasılıkla iki deneyde de aynı rastgele tohum ve fiilen aynı ayarın kullanıldığını gösterir.

Aynı grup Random Forest'ta derinliği 10 ile sınırlamanın sınırsız derinliğe göre daha iyi olduğunu, sınırsız derinlikte büyük olasılıkla aşırı öğrenme olduğunu yorumlamıştır.

## 9. Sınıf sayısını azaltan ek denemeler

### 9.1 Dönemlere ayırma

Bir öğrenci yıllar arasında keskin bir değişim olmadığını görünce yılları üç döneme bölmüş ve her dönemde TF-IDF ile öne çıkan kelimelere bakmıştır. Erken dönemde eğitim alanıyla ilgili kelimeler (okul, ilköğretim, müfredat, öğrenci), orta dönemde sosyolojik kelimeler ile mobil, internet ve veri madenciliği gibi teknik kelimeler, geç dönemde ise COVID ve pandemi ile derin öğrenme, yapay zeka gibi kelimeler öne çıkmıştır.

Ardından problemi 24 sınıf yerine 3 sınıfa (erken, orta, geç dönem) indirip yalnız özet temsiliyle model eğitmiştir. Random Forest ile doğruluk yaklaşık %65'e çıkmıştır. En eski ve en yeni tezler iyi ayrılmış, orta dönem daha zor tahmin edilmiştir; çünkü dönemler arası geçiş keskin değildir.

### 9.2 Kümeleme ve diğer öneriler

Bir grup yılları tekil sınıflar yerine beşer yıllık gruplar gibi kümeler olarak almayı önermiştir; böylece sınıf içi varyans azalır. Ek deneylerinde yılları K-means ile 8 kümeye toplamış ve doğruluğun yaklaşık 5 kat artarak %35'e çıktığını görmüşlerdir. Ayrıca embedding'lerde ağırlıklı ortalamaya dayalı farklı bir yöntem denemiş, Bagging'de doğruluğu %9'a çıkarmışlardır. Optuna ile optimizasyon bellek yetersizliği nedeniyle tamamlanamamıştır.

> **Ek bilgi (derste anlatılmadı):** Sınıf sayısı azaldıkça rastgele taban da yükselir: 3 sınıfta taban yaklaşık %33, 8 sınıfta yaklaşık %12.5'tir. Bu yüzden %65 ve %35 gibi değerler 24 sınıflı problemdeki doğruluklarla doğrudan karşılaştırılmamalı, kendi tabanlarına göre okunmalıdır.

## 10. Sunumlardan çıkan ortak sonuçlar

### 10.1 Temsillerin karşılaştırılması

Neredeyse bütün sunumlarda sıralama aynıdır: özet en iyi, başlık en kötü, birleşik temsil ikisinin arasında ve genelde özetin biraz altında. Öğrencilerin açıklamaları:

- Başlık en fazla bir cümledir; kelime çeşitliliği düşük olduğu için yılla ilişkili kalıplar embedding'e yansımaz.
- Özet daha uzun ve açıklayıcıdır; tezin kapsamını ve konusunu daha iyi taşır.
- Birleşik temsil yeni bir özellik eklemek yerine zayıf bir tekrar ve küçük miktarda gürültü ekler, çünkü başlığın bilgisi büyük ölçüde zaten özetin içindedir (ekrandan, 02:05:00). Ayrıca boyut 1024'ten 2048'e çıkar.
- Bir öğrenci başlık ve özeti metin olarak birleştirip tek bir embedding almanın ya da vektörleri toplamanın daha iyi sonuç verebileceğini önermiştir.

Bir öğrenci $R^2$ ısı haritası üzerinden, modeller arasındaki farkların temsiller arasındaki farklardan çok daha küçük olduğunu göstermiştir: bu problemde başarıyı yöntemden çok temsil belirlemektedir.

### 10.2 Bir grubun ayrıntılı sonucu ve regresörde doğruluk sorusu

Randomized Search kullanan bir grubun en iyi Random Forest ayarı özet temsilinde `max_depth=20`, `min_samples_leaf=10`, `n_estimators=113` olmuştur. Toplu performans tablosu (ekrandan, 01:50:00):

| Temsil | Model | Accuracy | MAE | RMSE |
|---|---|---|---|---|
| Title | RandomForest | 0.050833 | 7.465500 | 9.339102 |
| Abstract | RandomForest | 0.083833 | 5.880500 | 7.805714 |
| TaB | RandomForest | 0.078667 | 6.322333 | 8.305159 |
| Title | Bagging | 0.050167 | 7.318167 | 9.181022 |
| Abstract | Bagging | 0.070167 | 6.141500 | 8.036490 |
| TaB | Bagging | 0.076333 | 6.110000 | 7.995999 |
| Title | Random Subspace | 0.055833 | 7.181167 | 9.055045 |
| Abstract | Random Subspace | 0.079667 | 6.007167 | 7.913775 |
| TaB | Random Subspace | 0.068167 | 6.078333 | 7.917828 |

(TaB: başlık + özet.) En iyi model Random Forest, en iyi temsil özet, doğruluk 0.0838 olmuştur. MAE 5.88 yıl, yani model ortalamada yaklaşık 6 yıl sapmaktadır.

Grup ek olarak bir regresör de denemiş, regresörün MAE değerlerinin 5 civarında (en düşük 4.99) olduğunu, ama doğruluğunun %4-5'te kaldığını söylemiştir. Hoca burada şu soruyu sormuştur.

**Soru:** Regresörün MAE ve RMSE değerleri sizin sınıflandırıcılarınızdan (en düşük MAE 5.88) daha iyi değil mi? Regresör için "doğruluk" dediğiniz şey nasıl hesaplanıyor? **Cevap:** Grup yılları sayıya çevirdikleri için böyle bir değer elde edebildiklerini, yaklaşımlarının tam sınıflandırma ya da tam regresyon olmadığını söylemiş; doğruluğun regresörde nasıl hesaplandığı derste netleşmemiştir.

Hocanın tartışmadaki noktası şudur: bir tabloda üç ölçüt (doğruluk, MAE, RMSE) varsa ve regresör MAE ile RMSE'de daha iyiyse, "regresör daha iyi değil" demek için regresördeki doğruluğun ne anlama geldiği açık olmalıdır. Yıl kesikli bir değişkendir; regresörün sürekli çıktısı ancak bir yuvarlama kuralıyla doğruluğa çevrilebilir.

> **Ek bilgi (derste anlatılmadı):** Regresör çıktısı için doğruluk genelde tahminin en yakın tam sayıya yuvarlanıp gerçek yılla karşılaştırılmasıyla hesaplanır (6.4'teki çalışmada olduğu gibi). Bu durumda doğruluk ile MAE farklı şeyleri ölçer: doğruluk yalnız tam isabeti sayar, MAE ise ne kadar uzak düşüldüğünü. Yıl tahmininde MAE daha anlamlı bir ölçüttür.

### 10.3 Yöntemlerin karşılaştırılması

Yöntemler arasında tutarlı bir kazanan çıkmamıştır: bazı çalışmalarda Random Subspace, bazılarında Random Forest, bazılarında Bagging en iyi olmuştur. Farklar genelde birkaç binde birlik doğruluk düzeyindedir. Öğrencilerin ortak gözlemleri:

- Random Subspace yüksek boyutlu temsillerde (özellikle 2048 boyutlu birleşik temsilde) özellik alt kümesi seçtiği için avantajlı olabilir, ama eğitimi yavaştır.
- Random Forest benzer sonuçları daha hızlı verdiği için maliyet açısından daha uygun bulunmuştur.
- Karar ağacının bu problemde yetersiz kaldığı, MLP ya da lojistik regresyon gibi taban öğrenicilerin daha iyi sonuç verdiği görülmüştür.

## Örnek Sorular

1. (derste sözlü, 00:07:51) 1024 boyutlu bir girdiyle Random Forest'ta ağaç derinliğini 10 seçmek uygun mudur? Neden?

   > **Çözüm (derste verilmedi):** Hoca 10'un az olabileceğini belirtmiştir. 1024 boyutlu bir uzayda 10 derinlikteki bir ağaç en fazla 10 özelliğe dayanarak karar verir ve en fazla $2^{10} = 1024$ yaprağa sahip olabilir; 24 sınıfı ve yüksek boyutlu yapıyı yakalamak için bu yetersiz kalabilir. Daha derin ağaçlar denenmeli, aşırı öğrenme çapraz doğrulamayla kontrol edilmelidir.

2. (derste sözlü, 00:08:52 ve 00:18:25) Tez yılı tahmini neden sınıflandırma yerine regresyon problemi olarak kurulmalıdır? 2001 yerine 2002 demekle 2001 yerine 2012 demek arasında fark var mıdır?

   Derste verilen cevap: Yıl sıralı bir değişkendir. Karışıklık matrislerinde hataların yakın yıllarda toplanması bunu gösterir. Sınıflandırma iki hatayı da aynı sayarken regresyon 1 yıllık hatayı 11 yıllık hatadan çok daha az cezalandırır.

3. (derste sözlü, 00:31:19) Sınıflandırıcı kullanan bir modelde "6 yıllık sapma" nasıl tanımlanır?

   Derste verilen cevap: Tahmin edilen sınıf (yıl) sayıya çevrilip gerçek yıldan çıkarılarak. Hoca, problem regresyon olarak kurulsaydı buna gerek kalmayacağını söylemiştir.

4. (derste sözlü, 01:10:53) Hiperparametre optimizasyonunda hangi küme kullanılmalıdır?

   Derste verilen cevap: Yalnız eğitim kümesi; çapraz doğrulama eğitim kümesini kendi içinde böler. Test verisi optimizasyon sürecine hiçbir şekilde girmemelidir.

5. (derste sözlü, 01:48:03 ve 01:51:14) Bir regresör sınıflandırıcıdan daha düşük MAE ve RMSE veriyorsa ama "doğruluğu" daha düşükse hangisi daha iyidir? Regresör için doğruluk nasıl tanımlanır?

   > **Çözüm (derste verilmedi):** Regresörde doğruluk ancak çıktının en yakın yıla yuvarlanmasıyla tanımlanabilir ve yalnız tam isabeti sayar. Yıl gibi sıralı bir hedefte asıl ölçüt tahminin gerçeğe ne kadar uzak olduğudur; bu yüzden MAE ve RMSE'de belirgin olarak daha iyi olan model, tam isabette biraz geride kalsa bile bu problem için daha iyi kabul edilebilir.

6. (ekrandan, 00:55:00) Bir sonuç tablosunda MAE = 6.64 ve RMSE = 5.71 raporlanmıştır. Bu değerler tutarlı mıdır?

   > **Çözüm (derste verilmedi):** Tutarlı değildir. Her hata dizisi için $\mathrm{RMSE} \ge \mathrm{MAE}$ olur, çünkü karelerin ortalamasının karekökü mutlak değerlerin ortalamasından küçük olamaz (eşitlik yalnız bütün $|e_i|$ eşitse sağlanır). Sütunlar karışmış ya da değerlerden biri yanlış hesaplanmış olmalıdır. Rastgele hata dizileriyle python'da yapılan kontrol de her durumda RMSE'nin MAE'den büyük çıktığını göstermiştir.

## Dersin Toparlaması

Bu derste, tez başlığı ve özetinden yayın yılını tahmin etme ödevinin çözümleri sunuldu. Bütün çalışmalarda aynı veri düzeni (2001-2024, yılda 250 eğitim ve 250 test tezi) ve aynı Türkçe embedding modeli kullanıldı; Bagging, Random Subspace ve Random Forest başlık, özet ve birleşik temsil üzerinde karşılaştırıldı. Ortak sonuçlar şunlardı: özet en bilgilendirici temsildir, başlık zayıftır, birleşik temsil özetten pek iyi değildir; 24 sınıflı doğruluk %4'lük tabanın ancak 2 katına çıkabilmiştir; ağaç sayısını ve derinliği artırmak her zaman işe yaramaz, ağaçlar arası çeşitlilik (örnek ya da özellik alt kümeleri) belirleyicidir.

Hocanın sunumlar boyunca dönüp geldiği nokta, problemin doğru tanımıdır: yıl sıralı bir hedef olduğu için hataların yakın yıllarda toplanması regresyonu işaret eder ve başarı MAE/RMSE gibi uzaklığı ölçen metriklerle değerlendirilmelidir. Ayrıca karar ağacı yerine MLP, SVM ya da lojistik regresyon gibi taban öğrenicilerin denenmesi ve hiperparametre optimizasyonunda test verisinin kesinlikle kullanılmaması vurgulandı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
