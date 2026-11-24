# Ders 4 Çalışma Özeti

## Genel Konular

- Ödev problemi: tez yayın yılının tahmini
  - Türkçe akademik tezlerin başlık (title) ve özet (abstract) metinlerinden tezin yayın yılı tahmin edilir. Bu derste öğrenciler aynı ödevin çözümlerini sunmuş, hoca her sunum üzerine sorular sormuş ve yorum yapmıştır.
  - Ortak deney düzeni (ekrandan, 00:20:00 ve 00:50:00): 2001-2024 arasındaki her yıl için 500 tez, bunun 250'si eğitim, 250'si test. 2025 yılına ait veri olmadığı için toplam $24 \times 500 = 12000$ tez kullanılmıştır.
  - Metin temsilleri `ytu-ce-cosmos/turkish-e5-large` modeliyle çıkarılmıştır: başlık için 1024 boyutlu, özet için 1024 boyutlu ve ikisinin uç uca eklenmesiyle (concat) 2048 boyutlu vektör.
  - 24 sınıflı bir sınıflandırmada rastgele tahminin doğruluğu $1/24 \approx 0.042$, yani yaklaşık %4'tür. Bütün sunumlarda sonuçlar bu taban değerle karşılaştırılmıştır.
- Kullanılan üç kollektif öğrenme yöntemi (ekrandan, 00:05:00)
  - Bagging: ana veri setinden yerine koymalı (aynı örnek tekrar seçilebilir) örneklemlerle çok sayıda alt veri seti oluşturur, her birine bir karar ağacı eğitir, sonunda çoğunluk oylamasıyla karar verir.
  - Random Subspace: bütün örnekleri (satırları) kullanır, ama her ağaç özelliklerin yalnız rastgele seçilmiş bir kısmını (örneğin %50'sini) görür.
  - Random Forest: Bagging'e ek olarak her düğümde özelliklerin rastgele bir alt kümesine bakar. Böylece ağaçlar daha çeşitli olur ve aralarındaki korelasyon azalır.
- Hiperparametre optimizasyonu
  - Optimize edilen parametreler: ağaç sayısı (`n_estimators`), Bagging'de örnek oranı (`max_samples`), Random Subspace'te özellik oranı (`max_features`), Random Forest'ta ağaç derinliği (`max_depth`), bazı çalışmalarda `min_samples_leaf`, `ccp_alpha`, `min_impurity_decrease`.
  - Kullanılan arama yöntemleri: Grid Search CV, Randomized Search CV ve Bayesçi optimizasyon (Optuna kütüphanesi). Eğitim çok uzun sürdüğü için çoğu çalışmada 3 katlı çapraz doğrulama kullanılmıştır.
- Problemin tanımı: sınıflandırma mı regresyon mu?
  - Öğrencilerin çoğu problemi 24 sınıflı bir sınıflandırma olarak kurmuştur. Bir kısmı regresyon olarak kurup MAE, RMSE ve $R^2$ ile ölçmüştür. Bir grup sınıflandırıcı kullanıp sonuçları regresyon metrikleriyle de ölçmüştür.
  - Karışıklık matrislerinde hataların köşegen çevresinde, yani yakın yıllarda toplandığı görülmüştür. Hoca bu gözlemin problemin aslında bir regresyon problemi olduğunu gösterdiğini vurgulamıştır.
- Sunumlardaki ortak bulgular
  - Özet temsili her yöntemde başlıktan daha iyi sonuç vermiştir. Başlık kısa olduğu için yılı ayırt edecek bilgi taşımamaktadır.
  - Başlık ve özetin birleştirilmesi (2048 boyut) çoğu zaman özetten daha iyi olmamıştır. Öğrenciler bunu başlığın özete gürültü katması ve boyutun artmasıyla açıklamıştır.
  - Doğruluk %4'lük rastgele tabanın üzerine çıkmış ama genelde %5-8 aralığında kalmıştır. Regresyonda MAE yaklaşık 6 yıl çıkmıştır.
  - Ağaç sayısını ya da derinliği artırmak her zaman başarıyı artırmamıştır. Random Subspace'te özelliklerin yaklaşık %30-50'sini kullanmak daha iyi sonuç vermiştir.
- Karar ağacı dışındaki taban öğreniciler ve ek denemeler
  - Taban öğrenici olarak MLP ya da lojistik regresyon kullanan çalışmalarda doğruluk %11-14 düzeyine çıkmıştır (ekrandan, 00:45:00 ve 01:25:00).
  - Tek başına lojistik regresyon özet temsilinde 0.1307 doğruluk vermiştir (ekrandan, 01:25:00).
  - Yılları 3 döneme (erken, orta, geç) toplayan bir çalışmada doğruluk yaklaşık %65'e, yılları K-means ile 8 kümeye toplayan bir çalışmada yaklaşık %35'e çıkmıştır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Problemi regresyon olarak kurmak
  - Hoca, "2001 yerine 2002 demekle 2001 yerine 2012 demek arasında fark yok mu?" diye sormuştur. Yıl sıralı bir değişkendir; sınıflandırma bütün yanlışları aynı sayar, regresyon ise ne kadar uzak düşüldüğünü ölçer.
  - Sınıflandırıcıyla sapma (yıl farkı) ölçmeye çalışan bir öğrenciye, regresyon kullanılsaydı buna gerek kalmayacağını söylemiştir.
- Ağaç derinliği ve boyut
  - 1024 boyutlu bir girdi için 10 derinliğin az olabileceğini, daha derin ağaçların denenmesi gerektiğini belirtmiştir.
- Taban öğrenici seçimi
  - Karar ağacı yerine SVM ya da MLP gibi başka bir taban öğrenici kullanılsaydı daha başarılı sonuçlar alınabileceğini söylemiştir.
- Test verisinin optimizasyona girmemesi
  - Hiperparametre optimizasyonunda yalnız eğitim kümesinin (çapraz doğrulamayla) kullanılmasının doğru olduğunu, test verisinin optimizasyon sürecine hiçbir şekilde girmemesi gerektiğini onaylamıştır.
- Regresörde "doğruluk" kavramı
  - Regresyon modeli için doğruluk değeri raporlayan bir gruba, bu doğruluğun nasıl hesaplandığını sormuştur. Aynı tabloda regresörün MAE ve RMSE'si sınıflandırıcıdan daha iyiyken "daha iyi değil" denmesini sorgulamıştır.
- Sonuçların sunumu
  - Farklı ayarların sonuçlarını üç ayrı tablo yerine tek bir tabloda yan yana göstermenin yorumu kolaylaştıracağını önermiştir.

## Kısa Tekrar Notları

- Bagging: yerine koymalı örnekleme + her örneklemde ağaç + çoğunluk oylaması.
- Random Subspace: bütün örnekler, rastgele özellik alt kümesi (ağaç başına).
- Random Forest: Bagging + her düğümde rastgele özellik alt kümesi.
- 24 sınıfta rastgele doğruluk yaklaşık %4; sonuçlar bu tabana göre okunur.
- Özet > başlık + özet ≥ başlık. Başlık kısa ve az bilgili.
- Karışıklık matrisinde köşegen çevresi yoğun: yakın yıllar karışıyor. Bu, problemin regresyon doğasını gösterir.
- Ağaç sayısını artırmak başarıyı garanti etmez; Random Subspace'te özelliklerin bir kısmını görmek çeşitliliği artırır.
- Bagging'de `bootstrap=False` yapılınca ağaçlar aynı veriyi görür, çeşitlilik ve başarı düşer.
- Hiperparametre araması yalnız eğitim kümesinde, çapraz doğrulamayla yapılır.
- RMSE hiçbir zaman MAE'den küçük olamaz; tabloda tersi görülürse hesapta hata vardır.

## Detaylı Açıklamalar

- Ödevin amacı, aynı metin temsilleri üzerinde üç kollektif öğrenme yöntemini karşılaştırmaktır. Temsil modeli sabittir (turkish-e5-large). Değişenler temsil türü (başlık, özet, birleşik) ve yöntemle hiperparametrelerdir. Toplam 3 temsil × 3 yöntem = 9 deney yapılmıştır.
- Sınıflandırma sonuçları (ekrandan, 00:15:00): bir öğrencinin tablosunda en iyi sonuç Random Subspace + özet (`n_estimators=100`, `max_features=0.3`) ile test doğruluğu 0.0750, test F1 0.0702 olmuştur. Başlıkta en iyi doğruluk 0.0498 (Random Forest) ile rastgele tabana çok yakındır.
- Bagging'de örnek oranı (ekrandan, 00:20:00): başlık + özet temsilinde `n_estimators=400`, `max_samples=0.6` ayarı doğrulamada 0.0725 doğruluk vermiş, `max_samples=1.0` ise 0.0575'te kalmıştır. Sunan öğrenci bunu çeşitlilikle açıklamıştır: her ağaç örneklerin yalnız %60'ını görünce ağaçlar birbirinden daha farklı olur ve oylama daha etkili hale gelir.
- Regresyon sonuçları (ekrandan, 01:50:00): sınıflandırıcıyla eğitilip regresyon metrikleriyle de ölçülen bir çalışmada en iyi sonuç Random Forest + özet olmuştur: doğruluk 0.0838, MAE 5.88, RMSE 7.81. Yani model ortalamada yaklaşık 6 yıl sapmaktadır.
- Tabloda tutarsızlık (ekrandan, 00:55:00): bir sunumda MAE değerleri 5.9-6.7, RMSE değerleri ise 5.0-5.7 görünmektedir.
  - Ders sonrası not: RMSE her zaman MAE'den büyük ya da ona eşittir ($\mathrm{RMSE} \ge \mathrm{MAE}$). Bu tablodaki değerler büyük olasılıkla yanlış hesaplanmış ya da sütunlar karışmıştır. Derste bu konu konuşulmamıştır.
- $R^2$ ile ölçülen bir regresyon çalışmasında varsayılan ayarlarda $R^2$ negatif ve sıfır çıkmış, ağaç sayısı artırılınca 0.23 düzeyine gelmiştir (ekrandan, 01:00:00). PCA ile 256 boyuta indirmek sonuçları bozmuş, budama parametreleri (`ccp_alpha`, `min_impurity_decrease`) küçük bir iyileşme sağlamıştır.
- Taban öğreniciyi değiştirmek: Bagging, Random Subspace ve Random Forest içinde MLP kullanan bir çalışmada (Adam optimizasyonu, öğrenme oranı $10^{-3}$) özet temsilinde doğruluk 0.14 düzeyine çıkmıştır (ekrandan, 00:45:00). Hoca karar ağacı yerine başka taban öğrenicilerin denenmesinin doğru yol olduğunu söylemiştir.
- Çeşitlilik ve rastgelelik: Bagging'de `bootstrap=False` yapıldığında her ağaç aynı veriyi gördüğü için ağaçlar birbirine benzemiş ve başarı düşmüştür (ekrandan, 02:15:00). Random Subspace'te özellik oranını 0.8'e çıkaran bir öğrenci de ağaçların birbirine benzemesi nedeniyle başarının düştüğünü gözlemlemiştir.
- Sınıf sayısını azaltmak: yıllar arasındaki geçiş keskin olmadığı için yılları dönemlere toplamak sınıf içi varyansı azaltır. 3 dönemde doğruluk yaklaşık %65'e, K-means ile 8 kümede yaklaşık %35'e çıkmıştır. Ancak bu artık 24 yıllık asıl problem değildir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
