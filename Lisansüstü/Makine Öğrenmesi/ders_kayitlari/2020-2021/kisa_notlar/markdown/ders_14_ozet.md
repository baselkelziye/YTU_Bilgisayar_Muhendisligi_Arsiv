# Ders 14 Çalışma Özeti

## Genel Konular

- Tavsiye sistemleri (recommender systems) ve önemi.
- İçerik tabanlı (content-based) tavsiye sistemleri.
- İşbirlikçi filtreleme (collaborative filtering): bellek tabanlı (memory-based) ve model tabanlı (model-based).
- Kullanıcı tabanlı filtreleme (user-based): Pearson benzerliği, en benzer K kullanıcı, puan tahmini.
- Ürün tabanlı filtreleme (item-based): kosinüs benzerliği (cosine similarity).
- İşbirlikçi filtrelemenin sorunları: ölçek, seyreklik (sparsity), soğuk başlangıç (cold start), hep aynı önerileri yapma, az bilinen ürünler, ortak hesap kullanımı.
- Model tabanlı yöntemler: kümeleme tabanlı, matris ayrıştırma (matrix factorization), tekil değer ayrışımı (Singular Value Decomposition, SVD), derin öğrenme tabanlı.
- Makine öğrenmesinin bugünü ve lisansüstü öğrencilere kapanış tavsiyeleri.
- Değerlendirme, üçüncü ödev, final sınavı ve ikinci ödevle ilgili sorular.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bu dönemin son dersi. Hoca kısa tutacağını söyledi.
- Klasik makine öğrenmesi programlarında tavsiye sistemleri yoktu. Son yıllarda makine öğrenmesinin en başarılı uygulama alanlarından biri oldu. Hoca son 3-4 yıldır derste anlatıyor.
- Öncü kullanıcı Netflix, bugün Amazon, YouTube, Pinterest, Google gibi firmalar kullanıyor.
- Önemli olan kişiselleştirilmiş öneri. Kişiye uygun öneri gelirse satın alma olasılığı artar.
- İnsanların zevkleri kaba değil. Komedi izleyen herkes her komediyi sevmez. İşbirlikçi filtreleme bu alt seçimleri yakalamaya çalışır.
- Ürün tabanlı yaklaşım kullanıcı tabanlıdan daha çok kullanılıyor. Kullanıcı tabanlı yöntem gerçek dünyada milyonlarca kullanıcı yüzünden pek kullanılmıyor.
- Ürün tabanlı filtrelemede en çok kullanılan ve başarılı benzerlik ölçüsü kosinüs benzerliği.
- Şu an en popüler yaklaşım derin öğrenme tabanlı tavsiye sistemleri.
- Derin öğrenme her şeyin çözümü değil. Çok örnek ister. Ör. 100 hasta verisiyle derin öğrenme iyi değil. Hoca GAN ile veri çoğaltmayı da çok etkili bulmuyor.
- Klasik yöntemlerle derin öğrenmeyi karşılaştırın, hangisi etkiliyse onu kullanın. Çoğu zaman SVM ya da basit bir karar ağacı daha iyi sonuç verebiliyor.
- Lisansüstü öğrenci olarak "Lego gibi" hazır kütüphaneleri birleştirmeye takılmayın. Asıl problemlere (cold start, seyreklik vb.) odaklanın.
- "Bir veri kümesine A yöntemi %80, B yöntemi %90 verdi" türü çalışmalar 15-20 yıl önce kaldı.
- Denediğiniz bir yöntem işe yaramadıysa bunu da yazın. Diğer araştırmacılara o yöne gitmemelerini gösterir.

## Kısa Tekrar Notları

- **Tavsiye sistemi türleri:**
  - İçerik tabanlı: kişinin ya da ürünün özelliklerine bakar (yaş, mezuniyet, spor, film türü).
  - İşbirlikçi filtreleme: kullanıcıların seçimlerine ve verdikleri puanlara bakar.
    - Bellek tabanlı: kullanıcı-ürün puan matrisini doğrudan kullanır. Kullanıcı tabanlı ya da ürün tabanlı.
    - Model tabanlı: makine öğrenmesi modeli kurar (kümeleme, matris ayrıştırma, derin öğrenme).
- **Puan matrisi:** satırlar kullanıcılar (user), sütunlar ürünler (item). Ör. Netflix'te 1-5 arası puan.
- **Pearson benzerliği (A ve U kullanıcıları, ortak puanlanan ürünler üzerinden):**
  $\operatorname{sim}(a,u) = \dfrac{\sum_{i} (r_{a,i} - \bar{r}_a)(r_{u,i} - \bar{r}_u)}{\sqrt{\sum_{i} (r_{a,i} - \bar{r}_a)^2}\ \sqrt{\sum_{i} (r_{u,i} - \bar{r}_u)^2}}$
- **Puan tahmini (kullanıcı tabanlı):**
  $p_{a,p} = \bar{r}_a + \dfrac{\sum_{b \in N} \operatorname{sim}(a,b)\,(r_{b,p} - \bar{r}_b)}{\sum_{b \in N} \lvert\operatorname{sim}(a,b)\rvert}$, $N$: $p$ ürününü puanlamış en benzer $K$ kullanıcı.
- **Kosinüs benzerliği (ürün tabanlı, düzeltilmiş hâli):**
  $\operatorname{sim}(a,b) = \dfrac{\sum_{u \in U} (r_{u,a} - \bar{r}_u)(r_{u,b} - \bar{r}_u)}{\sqrt{\sum_{u \in U} (r_{u,a} - \bar{r}_u)^2}\ \sqrt{\sum_{u \in U} (r_{u,b} - \bar{r}_u)^2}}$, $U$: hem $a$ hem $b$ ürününü puanlayan kullanıcılar.
- **Matris ayrıştırma:** seyrek $R$ ($N \times M$) matrisi, dolu iki matrisin çarpımıyla yaklaşık temsil edilir: $R \approx U V$, $U$: $N \times D$, $V$: $D \times M$.
- **Dirsek yöntemi (elbow method):** K arttıkça hata (küme içi kare hata toplamı) düşer. Düşüşün yavaşladığı dönüm noktası seçilir.

## Detaylı Açıklamalar

### Tavsiye Sistemi Nedir?

- En basit tavsiye: çok satan ya da popüler ürünleri göstermek. Bu genel bir tavsiye.
- Asıl hedef kişiselleştirilmiş tavsiye: kişinin zevkine uygun ürünü önerip satın almayı artırmak.

### İçerik Tabanlı Tavsiye

- Klasik makine öğrenmesi yöntemleriyle kişilerin özelliklerine bakar.
- Ör. üniversite mezunu, belli yaşın üstünde, spor yapan, sanatla ilgilenen kişilere ne önerilebilir?
- Ya da kişinin önceki seçimlerine bakar: romantik film izliyorsa romantik film önerir.
- İlk sistemler böyleydi. Aşırı bir kişiselleştirme yok.

### İşbirlikçi Filtreleme

- Ana türe bakmaz (komedi izliyor, komedi göster demez).
- Kişinin daha önce seçtiği ürünlere bakar, bunları diğer kişilerin seçimleriyle eşleştirir.
- İki yol:
  - Kişiye benzeyen kişilerin seçtiklerini önermek (kullanıcı tabanlı).
  - Kişinin beğendiği ürünlere benzeyen ürünleri önermek (ürün tabanlı).

### Kullanıcı Tabanlı Filtreleme

**Adımlar:**

1. A kullanıcısının matristeki bütün kullanıcılara benzerliğini tek tek ölç (Pearson ya da kosinüs).
2. Benzerliği ölçerken yalnız iki kullanıcının ortak puanladığı ürünleri kullan.
3. Benzerlikleri büyükten küçüğe sırala, en benzer $K$ kullanıcıyı seç (k-NN mantığı).
4. A'nın izlemediği her ürün için, o ürünü izlemiş benzer kullanıcıların puanlarından tahmin hesapla.
5. Tahmini puanı en yüksek ürünleri (ya da bir eşiğin üstündekileri) öner.

**Örnek: ortak ürün kuralı.**

| | Movie 1 | Movie 2 | Movie 3 | Movie 4 |
| :---: | :---: | :---: | :---: | :---: |
| A | 4 | 2 | | 5 |
| B | | 5 | | 3 |

- B, Movie 1'i izlememiş. A-B benzerliği yalnız Movie 2 ve Movie 4 üzerinden hesaplanır.

**Örnek: öneri seçimi.**

- A için tahminler: Movie 3 → 4,2; Movie 7 → 4,9; Movie 12 → 2,8.
- Önce Movie 7 önerilir. Eşik uygunsa Movie 3 de önerilebilir. Movie 12 önerilmez.

- Bu yöntem bellek tabanlıdır. Ürünün içeriğine (tür, festival filmi vb.) ya da kişinin diğer özelliklerine bakmaz. Yalnız puan matrisindeki benzerliği kullanır. Hocaya göre burada makine öğrenmesi tabanlı bir tahmin yok, yalnız matematiksel benzerlik var.

### Ürün Tabanlı Filtreleme

- Ürünler arasındaki benzerlik bulunur.
- Ör. A kullanıcısının Movie 4'e ne puan vereceğini bulmak için Movie 4'e en çok benzeyen ürünlere bakılır. Örnekte Movie 1 ile Movie 4 benziyordu.
- Netflix gibi sistemler bu mantığı kullanıyor: "şu filmi izlediğine göre şundan da hoşlanırsın".
- Milyonlarca kullanıcı arasından benzer kişi aramak yerine, izlenen ürünlere benzeyen ürünler aranır.
- Kosinüs benzerliği iki vektör arasındaki açıyı ölçer. Açı küçükse vektörler birbirine yakındır.
- Burada da en benzer $K$ ürün üzerinden ilerlemek önemli.

### İşbirlikçi Filtrelemenin Sorunları

Hoca öğrencilere sordu, şu sorunlar konuşuldu:

- **Ölçek ve hız:** milyonlarca kullanıcı ve on binlerce ürün. Kullanıcı tabanlı yöntemde milyonlarca kişiyle karşılaştırma çok yavaş.
- **Seyreklik (sparsity):** bir kişi on binlerce ürünün ancak 50-100'ünü alır ya da izler. Matris çok büyük ve büyük ölçüde boş. Hem kullanıcı hem ürün tabanlı yöntem bundan etkilenir.
- **Soğuk başlangıç (cold start):** yeni kullanıcıya ne önereceğiz? Yeni ürünü kime önereceğiz? Önce bir süre veri birikmesi gerekir.
- **Hep aynı önerileri yapmak:** bir öğrenci bunu "sömürü ve keşif" (exploitation-exploration) olarak adlandırdı. Hoca doğru buldu.
- **Az bilinen ürünler:** kıyıda köşede kalmış bir ürünü kimse puanlamaz. Kimse puanlamayınca kimseye önerilmez. Hoca bunu farklı bir tür soğuk başlangıç olarak gördü.
- **Sıra dışı zevkler:** çok özel zevki olan kişiye benzer kişi bulmak zor olabilir. Hoca bunu büyük bir sorun saymıyor; kullanıcı çok olunca mutlaka benzer biri çıkıyor.
- **Ortak hesap:** Netflix'te kullanıcı profili bu yüzden tanımlatılıyor. Ama insanlar profil değiştirmezse 3-4 kişinin zevki aynı hesapta karışıyor.
- **Puan yerine beğeni:** Netflix başta puan alıyordu, şimdi yalnız beğendim/beğenmedim alıyor. Hoca bunun etkisini bilmediğini söyledi.

### Model Tabanlı Yöntemler

- Yalnız puan matrisine değil, başka özelliklere de bakarak makine öğrenmesi modeli kurulur.
- Genelde önce boyut azaltılır: PCA, SVD, sinir ağı, matris ayrıştırma. Böylece seyreklik sorunu çözülmeye çalışılır.
- Türler:
  - **Kümeleme tabanlı:** hocaya göre aslında en benzer $K$ örneği kullanan (k-NN) bir yaklaşım. Kümeler benzer örneklerden oluşur.
  - **Matris ayrıştırma tabanlı:** SVD ya da olasılıksal matris ayrıştırma (probabilistic matrix factorization).
  - **Derin öğrenme tabanlı:** çok katmanlı sinir ağları (multi-layer neural network). Şu an en popüleri.

**Matris ayrıştırma:**

```
        R (N x M, seyrek)   ~   U (N x D, dolu)   x   V (D x M, dolu)
 satır: kullanıcı           satır: kullanıcı       sütun: ürün (film)
```

- $U$ ve $V$ çarpılınca orijinal $R$ elde edilir (yaklaşık). Fark: $R$ seyrek, $U$ ve $V$ tamamen dolu.
- Ana matristen üretilen azaltılmış özelliklerle çalışılır.

### Tavsiye Sistemlerinin Bugünü

- Her şey internet ve e-ticaret üzerinden yürüyor. Spotify, YouTube gibi platformlar da kimin neyi izlediğine göre reklam koyuyor ve öneri yapıyor.
- YouTube'da milyarlarca video var. Kullanıcının kendi başına araması imkânsız. Öneri sistemi izlenenlere bakarak yardımcı oluyor.
- Hoca, sistemlerin arada popülerliği artırmak için kişiye pek uygun olmayan ürünleri de "azıcık" önerdiğini düşündüğünü söyledi.

### Makine Öğrenmesinin Bugünü ve Kapanış Tavsiyeleri

- Başlangıçta makine öğrenmesi, yapay zekânın alt dalı olarak insan gibi davranan sistemlere odaklıydı: yüz, parmak izi tanıma, sürücüsüz araç, doğal dil işleme.
- Bugün büyük veriye kaydı. Büyük veriden anlam çıkarmak gerekiyor.
- Ör. saldırı tespit sistemleri eskiden dizgi eşleme (string matching) ile çalışıyordu. Saldırgan farklı bir saldırıyla gelince yakalanmıyordu. Bugün anomali tespitiyle (anomaly detection) normale uymayan durumlar aranıyor.
- İlk yöntemler tamamen istatistiğe dayalıydı. Derin öğrenmeyle daha sezgisel çözümlere gidiliyor.
- Tez yaparken veriyi alma aşamasından başlayan iyileştirmelerle fark yaratın. Ör. derin öğrenmeye vermeden önce yapılacak bir ön işlemin başarıyı nasıl değiştirdiğini araştırın. Müdahale edin ama modeli şartlandırmayın (bias katmayın).

### Değerlendirme ve Ödevler

- **Notlandırma:**
  - Genel kural: vizeler %60, final %40. Hoca bunu değiştiremediğini söyledi.
  - Vize 1 kendi başına sayılıyor. İki ödev birlikte vize 2 olarak sayılıyor.
  - Finalin %40'ı üçüncü ödev, %60'ı final sınavı.
- **Üçüncü ödev:**
  - Çok basit bir tavsiye sistemi (kullanıcı tabanlı işbirlikçi filtreleme).
  - Eskiden MovieDB veri tabanıyla yaptırılıyordu, öğrenciler günlerce uğraşıyordu. Uzaktan eğitim nedeniyle basitleştirildi.
  - Hoca bunun bir günde yapılabileceğini ama uzun süre vereceğini, finallerin sonuna kadar süre tanıyacağını söyledi.
  - Kullanıcı tabanlı yöntemin gerçekte kullanılmadığını, ama temel mantığı görmek için verildiğini belirtti.
  - Varyans gibi basit hesapları kendiniz yapın. Bazı hesaplar için hazır fonksiyonlar kullanılabilir.
  - Not girişi için bir son tarih olduğundan ek süre veremeyeceğini söyledi.
- **İkinci ödev (Spotify şarkıları, k-means):**
  - Son teslim ayın 12'si. Bir öğrenci aynı gün sınav olduğu için uzatma istedi. Hoca, zamanında yapanlara haksızlık olacağı için uzatmadı. Zaten var olan 3 günlük geç teslim hakkını hatırlattı, bunu 5 güne çıkarabileceğini söyledi (puan kırılarak).
  - Kategorik özellik sorusu: şarkı adı ve ID gibi her örnekte farklı (unique) özellikler kullanılmamalı.
  - Sanatçı adı unique değil, bir özellik olabilir. Ama yaklaşık 34 bin farklı sanatçı var. One-hot ile 34 bin yeni özellik eklenir, bu genelde başarıyı düşürür. Hem ekleyip hem çıkarıp deneyin. Kararı rapora göre değerlendirecek.
  - "Key" (müzik anahtarı) kategorik bir özellik, kullanılabilir.
  - Spotify gerçekten kümeleme kullanıyor ve kümeler üzerinden öneri yapıyor.
  - Dirsek yöntemi: k-means'in hazır "inertia" değeri (küme içi kare hata toplamı) kullanılabilir. Önemli olan dönüm noktasını doğru bulmak. K artınca hata hep düşer; her örnek ayrı küme olursa hata sıfır olur. Amaç en düşük hata değil, düşüşün yavaşladığı nokta.
- **Final sınavı:**
  - Bir öğrencinin bildirdiğine göre haftaya Salı saat 10:00'da. Ders 5 Ocak 2021 Salı olduğuna göre 12 Ocak 2021 Salı.
  - Sınav programını bölümde bir görevli hazırlıyor.
  - Format ara sınava benzer: soruları çözüp cevap yazmak. Ezber yok, dersi dinleyip anlayan rahatça yapabilir.
- **Ara sınav değerlendirmesi:**
  - Online sınav sisteminin dizgi eşlemesi doğru çalışmamış. İlk bakışta en yüksek not 100 üzerinden 30 görünmüş.
  - Hoca bütün cevapları tek tek okuyup puanlamış.
  - Sayısal cevap istenen soruda uzun açıklama yazıp sonucu yazmayanlara puan verilmedi.
  - SVM sorusunda (kaç örnek kaldırılırsa sınır değişir) iki mantıklı cevap da kabul edildi. Sınır y eksenine paraleldir, çapraz olmaz.
  - Doğru cevaplar finalden sonra açıklanacak.

### Ders sonrası notlar

- **Yarışma bilgisi:** hoca matris ayrıştırma yaklaşımının "Amazon'un 2009-2010'daki bir yarışmasında" önerildiğini söyledi. Bu yarışma Netflix Prize'dır (2006-2009). Ödülü 2009'da BellKor's Pragmatic Chaos ekibi kazandı. Matris ayrıştırma yöntemleri bu yarışmayla yaygınlaştı.
- **Tahmin formülü:** hoca formülde "B'nin varyansı" dedi. Formülde varyans değil, B'nin ortalama puanı ($\bar{r}_b$) çıkarılır. Paydada benzerliklerin mutlak değerlerinin toplamı kullanılır.
- **Kullanıcı tabanlı yöntem ve makine öğrenmesi:** hoca bu yöntemde "makine öğrenmesi tabanlı bir tahmin yok" dedi. Yöntem aslında k-NN'nin bir uygulamasıdır. Ama ayrı bir model eğitilmez, tembel öğrenme (lazy learning) gibi çalışır.
- **Kümeleme tabanlı yöntem:** hoca "cluster oluşturmakla ilgisi yok, aslında k-NN" dedi. Literatürde kümeleme tabanlı tavsiye, kullanıcıları ya da ürünleri önce kümelere ayırıp (ör. k-means) benzer kişileri küme içinde aramayı da kapsar.
- **Altyazı yanlış okumaları:** "Cosine Simulator" = cosine similarity, "metric spektronizasyon" = matrix factorization, "Osman K" = optimum K, "inertiye" = inertia, "Aygürtme / Aygertman" = online sınav sistemi (adı altyazıdan net değil).
- **Ders yapılmayan gün:** bu derste geçmiyor. Canlı ders sekmesi başta açılmadı, hoca bunu "dönem bitti" işareti olarak yorumladı.

Gemini Notebook gibi bir araca altyazı dosyasını yükleyerek bu ders hakkında daha ayrıntılı soru-cevap yapabilirsiniz.
