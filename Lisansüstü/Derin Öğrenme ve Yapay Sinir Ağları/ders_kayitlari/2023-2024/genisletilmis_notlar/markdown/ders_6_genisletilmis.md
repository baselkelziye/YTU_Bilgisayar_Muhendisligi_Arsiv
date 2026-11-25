# Ders 6 Genişletilmiş Notu: Öğrenci Proje Sunumları: Nesne Tespiti, Segmentasyon, Sınıflandırma ve Ses Duygu Analizi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Oturumun Biçimi ve Proje Beklentisi
- 2. Araç Tespiti: Bounding Box ve YOLO
- 3. Şerit Algılama: Piksel Tabanlı İkili Segmentasyon
- 4. Tablo Verisinde Regresyon: Yengeç Yaşı Tahmini
- 5. Obezite Düzeyi Sınıflandırması ve Kategorik Veri Kodlaması
- 6. Tweet Duygu Analizi: Frekans Öznitelikleri ve Lojistik Regresyon
- 7. Banka Müşteri Kaybı Sınıflandırması ve Veri Bölme
- 8. Beyin Tümörü Sınıflandırması: Optimizasyon Algoritmalarının Karşılaştırılması
- 9. Sesten Öfke Tanıma: openSMILE Öznitelikleri ve Pencereleme
- 10. Video Duvarı Arıza Tespiti: CNN mi, Histogram mı?
- Örnek Sorular
- Dersin Toparlaması

## 1. Oturumun Biçimi ve Proje Beklentisi

Bu oturum çevrim içi yapıldı ve tamamı öğrencilerin dönem projesi sunumlarına ayrıldı. Hoca sunumlardan önce beklentisini açıkladı: çok ayrıntılı bir sunum beklenmiyor; görüntü, ses, sinyal gibi tek ya da iki boyutlu bir veri üzerinde ders kapsamında öğrenilen yöntemlerden en azından bazılarının uygulanması ve sonuçların gösterilmesi isteniyor. Her sunumdan sonra hoca, veri setinin yapısı, seçilen yöntemin gerekçesi ve sonuçların nasıl raporlanması gerektiği üzerine sorular sordu. Bu not, sunumlarda geçen teknik içeriği ve hocanın değerlendirmelerini sırasıyla aktarır; sunum yapanlar "bir öğrenci" diye anılır.

Hocanın bütün sunumlarda tekrar ettiği genel ilke, sonuçların iki türde verilmesidir: **nitel** (kalitatif) sonuçlar, yani örnek çıktı görüntüleri; ve **nicel** (kantitatif) sonuçlar, yani doğruluk, mAP, MSE gibi sayısal metrikler, eğitim grafikleri ve karışıklık matrisleri.

> **Hocanın vurgusu:** Raporda yalnız görsel örnek yetmez; sayısal metrikler, eğitim/doğrulama grafikleri ve karışıklık matrisi de bulunmalıdır.

## 2. Araç Tespiti: Bounding Box ve YOLO

### 2.1 Nesne tespiti ve sınırlayıcı kutu

İlk sunumda araç tespiti (Car Object Detection) ele alındı. Nesne tespiti, bir görüntüdeki ya da videodaki nesneleri tanımlamak ve çerçeve içinde nerede bulunduklarını belirtmek için kullanılır. Trafik denetimi, otonom sürüş, kaza önleme, otopark yönetimi ve lojistik gibi alanlarda uygulanır.

Nesnenin konumu dikdörtgen bir **sınırlayıcı kutu** (bounding box) ile gösterilir. Kutunun bilgisi bir vektörle ifade edilir (ekrandan, 00:10:00):

$$y = (p_c,\ b_x,\ b_y,\ b_h,\ b_w,\ c)$$

- $p_c$: güven skoru; kutuda bir nesne bulunduğuna ne kadar emin olunduğu.
- $b_x, b_y$: nesnenin orta noktasının $x$ ve $y$ koordinatları.
- $b_h, b_w$: kutunun yüksekliği ve genişliği.
- $c$: sınıf bilgisi; slayttaki örnekte $p_c = 1$ ve $c = 3$ ("car" sınıfı).

> **Ders sonrası not:** Slaytta $b_h$ "genişlik", $b_w$ "yükseklik" olarak yazılmış ve sunumda da böyle okundu; doğrusu $b_h$ yükseklik (height), $b_w$ genişliktir (width). Slayttaki "Bw: (Weight)" ifadesi de "Width" olmalıdır.

Sınıflandırma (classification) ise bir girdiyi önceden tanımlı kategorilerden birine atar; nesne tespitinde kutunun içindeki nesnenin araba mı, otobüs mü, kamyon mu olduğu bu şekilde belirlenir.

### 2.2 YOLO

Model olarak evrişimli sinir ağı tabanlı YOLO (You Only Look Once) kullanıldı. YOLO görüntüyü bir ızgaraya böler; her hücre için içinde nesne olup olmadığına ve nesnenin merkez noktasına bakar. Nesnenin merkezini içeren hücre, o nesnenin sınıfını, yüksekliğini ve genişliğini tahmin edip kutuyu çizer. Görüntüyü ağdan tek seferde geçirdiği için diğer algoritmalara göre hızlıdır. YOLOv3, v4, v5 ve v8 gibi sürümleri vardır; sunumda YOLOv4'ün Nisan 2020'de yayımlandığı ve COCO veri setinde gerçek zamanlı tespitte iyi sonuç verdiği belirtildi.

Veri seti Kaggle'dan alındı: yolda giderken çekilmiş görüntülerden yaklaşık 1001 eğitim ve 175 test görüntüsü, kutular için `xmin, ymin, xmax, ymax` değerlerini içeren bir CSV dosyası. Eğitimde kayıp fonksiyonu belirlenip Adam ile iteratif olarak minimize edildi; doğrulama kümesinde periyodik olarak performans izlendi. Veri artırma (augmentation) ile sonuçların daha kararlı hale getirilebileceği söylendi.

### 2.3 Hocanın değerlendirmesi: mAP

Hoca, kullanılan makaledeki veri setinin aynı olup olmadığını sordu (aynı değildi; yalnız benzer model kullanılmıştı) ve ardından nicel sonuçları istedi: nesne tespitinde standart ölçüt **mAP** (mean Average Precision), özellikle mAP@0.5 ve mAP@0.5:0.95 değerleridir. Hoca, literatürdeki bir otonom sürüş araç tespiti çalışmasında verilen grafiklerin ve karışıklık matrisinin rapora benzer şekilde eklenmesini önerdi.

> **Ek bilgi (derste anlatılmadı):** mAP, her sınıf için precision–recall eğrisinin altındaki alanın (AP) sınıflar üzerinden ortalamasıdır. mAP@0.5'te tahmin kutusu gerçek kutuyla en az 0,5 IoU (kesişim/birleşim) oranında örtüşürse doğru sayılır; mAP@0.5:0.95 ise 0,5'ten 0,95'e kadar 0,05 adımlı IoU eşiklerinin ortalamasıdır.

## 3. Şerit Algılama: Piksel Tabanlı İkili Segmentasyon

### 3.1 Problem ve veri seti

İkinci sunum şerit algılama (lane detection) üzerineydi. Otonom sürüşte algılama (perception) için kullanılan bu problemde farklı ışık koşulları, kötü hava, virajlar ve kalabalık alanlar zorluk yaratır; örneğin gece görüntüleriyle yeterince eğitilmemiş bir model gece sürüşünde başarısız olur. Bu yüzden doğru veri seçimi önemlidir.

Kullanılan **CULane** veri setinin özellikleri (ekrandan, 00:20:00):

- Pekin'de 6 farklı araca monte edilmiş kameralarla toplandı.
- Toplam 55 saat video ve 133.235 kare (1640 × 590 piksel).
- 4 şerit algılama.
- Etiket türleri: şerit işaret noktaları (lane marking points) ve ikili segmentasyon maskesi.
- Sahne dağılımı: normal %27,7, kalabalık %23,4, gece %20,3, şeritsiz %11,7, gölge %2,7, ok %2,6, kamaşma %1,4, viraj %1,2, kavşak %9,0.

Şerit işaret noktası dosyasında her satır bir şeridi temsil eder; satırdaki sayılar ikişer ikişer $x$ ve $y$ koordinatlarıdır. Öğrenci önce bu noktalarla denedi, iyi sonuç alamayınca ikili segmentasyona (her piksel için "şerit var / yok") geçti. Verinin yaklaşık 5 GB'lık bir kısmı (yaklaşık 15–18 bin görüntü) kullanıldı.

### 3.2 Aktivasyon, kayıp ve optimizasyon seçimi

- **Leaky ReLU:** Normal ReLU'da negatif girişlerin çıkışı 0'dır; bazı nöronlar hiç aktif olamaz ("ölü nöron") ve eğitimde yeniden canlandırılmaları zordur. Leaky ReLU negatif girişlere de küçük bir eğim verdiği için bütün girişlerde gradyan akışı sağlar ve kaybolan gradyan sorununa da yardımcı olur.
- **BCEWithLogitsLoss:** İkili çapraz entropinin logit alan sürümüdür; sigmoid katmanını kayıpla birleştirir. Modele ayrı bir sigmoid katmanı koyup sonra ikili çapraz entropi uygulamaktan sayısal olarak daha kararlıdır. Her pikselde "şerit var mı yok mu" sorusu ikili sınıflandırma olduğu için uygundur.
- **Adam:** Her parametrenin kendi öğrenme oranı vardır; tam yığın gradyan inişine göre hesaplama açısından ucuz, saf stokastik gradyan inişine göre daha hızlı yakınsar.

### 3.3 Modeller

Hazır mimari yerine sıfırdan model tasarlandı. İlk model 5×5 çekirdekli evrişim–ReLU–max pooling bloklarından ve sonda bir evrişim katmanından oluşuyordu; görüntüler 320 × 800 boyutuna küçültüldü. Yaklaşık 7 epoch sonunda görsel olarak şeritler kısmen yakalandı, ancak doğrulama kaybı beklendiği gibi düşmedi.

İkinci model daha küçük çekirdekler, batch normalization ve Leaky ReLU kullanır (ekrandan, 00:25:00):

```text
Giriş: 3 x 320 x 800
Evrişim 3x3, 32 harita            -> 32 x 320 x 800, BatchNorm, Leaky ReLU
Evrişim 3x3, 64 harita            -> 64 x 320 x 800, BatchNorm, Leaky ReLU
Max Pool 2x2                      -> 64 x 160 x 400
Evrişim 3x3, 128 harita           -> 128 x 160 x 400, BatchNorm, Leaky ReLU
Evrişim 3x3, 128 harita           -> 128 x 160 x 400, BatchNorm, Leaky ReLU
Max Pool 2x2                      -> 128 x 80 x 200
Evrişim 1x1, 1 harita (çıkış)     -> 1 x 80 x 200
```

Model önce 3, sonra 15 epoch eğitildi; kayıp yalnız yaklaşık 0,025'ten 0,024'e indi. Gece görüntülerinde başarı düşük, güneşli sahnelerde daha iyiydi. Öğrencinin önerdiği iyileştirmeler: veri setinin tamamıyla eğitim, farklı mimariler, daha fazla gizli katman, aşırı öğrenmeye girmeden daha çok epoch veya hazır mimariler.

### 3.4 Hocanın değerlendirmesi

Hoca birkaç noktaya dikkat çekti:

- Bir modelde renkli (RGB) görüntünün gri tonlamaya çevrilip öyle kullanıldığını fark etti. Gri tonlamada, özellikle gece sahnelerinde, ciddi bilgi kaybı olur.
- Yapılan şey piksel bazında sınıflandırmadır: her pikselin ön planda mı arka planda mı olduğuna karar verilir. Bu yöntem U-Net ve örnek tabanlı (instance-based) segmentasyon yöntemleri yaygınlaşmadan önce kullanılırdı ve yavaştır; sunumdaki 15 epoch'luk eğitim birkaç saat sürmüştü.
- Veri setinde şeritlerin koordinat bilgisi ve maskeler hazır olduğu için Mask R-CNN gibi yöntemlerle bu problem çok daha pratik çözülebilir.

## 4. Tablo Verisinde Regresyon: Yengeç Yaşı Tahmini

### 4.1 Veri seti

Üçüncü sunumda bir regresyon modeli kuruldu. Kaggle'daki **Crab Age** veri seti, yengeçlerin fiziksel özelliklerinden yaşlarını tahmin etmek için hazırlanmıştır (ekrandan, 00:35:00). Öznitelikler: cinsiyet (Sex: M, F, I), uzunluk (Length), çap (Diameter), yükseklik (Height), ağırlık (Weight), kabuksuz ağırlık (Shucked Weight), iç organ ağırlığı (Viscera Weight) ve kabuk ağırlığı (Shell Weight); hedef değişken yaş (Age). Yaklaşık 10.000 örnek vardır.

Hedef değişkenin istatistikleri (`train['Age'].describe()`, ekrandan, 00:35:00): ortalama 9,9442; standart sapma 3,2232; en küçük 1; çeyrekler 8, 10, 11; en büyük 27. Histogram normal dağılıma yakındır.

### 4.2 Modeller ve sonuçlar

- İlk model: tek gizli katmanlı sığ ağ; kayıp MSE, tam yığın (full-batch) gradyan inişi, öğrenme oranı 0,01, 1000 epoch. MSE yaklaşık 3,35.
- 27 birimli ikinci bir gizli katman eklenince MSE yaklaşık 3,14'e indi.
- Kayıp MAE, optimizasyon Adam yapılınca hata yaklaşık 1,27; epoch 500'e düşürülünce değişmedi.
- En iyi model: Adam, MAE kaybı, öğrenme oranı 0,001, 1000 epoch, batch 256; hata yaklaşık 1,05.

<!-- BELİRSİZ: Sunumda "1,27" ve "1,05" değerleri bazen "MSE" bazen "MAE" diye okundu; kayıp MAE olduğundan büyük olasılıkla MAE değerleridir. -->

### 4.3 Korelasyon matrisinin yorumu

Hoca korelasyon matrisinin yorumlanmasını istedi (ekrandan, 00:35:00). Bütün değişkenler birbiriyle yüksek korelasyonludur. Yaşla en yüksek korelasyon kabuk ağırlığındadır (0,66): yaş ilerledikçe kabuk ağırlaşır. Uzunlukla yaş arasında 0,61 vardır. Öznitelikler arasında en yüksek değerler ağırlıklar arasındadır (ör. Weight–Shucked Weight ve Weight–Viscera Weight 0,97, Weight–Shell Weight 0,96; Length–Diameter 0,99). Hoca, cinsiyetin matriste yer almadığını ve ağırlık gibi özniteliklerin cinsiyete bağlı olabileceğini, bu yüzden onun da incelenmesi gerektiğini belirtti.

Hoca ayrıca slaytta 500 epoch denendiği söylendiği halde grafikte 1000 epoch göründüğünü fark etti; yanlış grafiğin konduğu anlaşıldı.

## 5. Obezite Düzeyi Sınıflandırması ve Kategorik Veri Kodlaması

### 5.1 Veri seti

Dördüncü sunumda Kolombiya, Peru ve Meksika'daki bireylerin yeme alışkanlıkları ve fiziksel durumlarına göre obezite düzeyini tahmin eden bir veri seti kullanıldı. Özgün veri bir aylık web anketiyle toplanmış yaklaşık 480 kayıttır; Weka ve SMOTE ile sentetik olarak 2111 kayda, 17 özniteliğe çıkarılmıştır. Kaggle yarışmasında yeniden sentetik artırma yapılmış; eğitimde 20.578 kayıt kullanıldı. Hedef 7 sınıftır: yetersiz kilo, normal kilo, aşırı kilo I, aşırı kilo II ve obezite I, II, III. Anket soruları yaş, cinsiyet, boy, kilo, ailede aşırı kilo, yeme alışkanlıkları, fiziksel aktivite, alkol ve ulaşım türünü kapsar. Veri sınıflandırma, tahmin, segmentasyon ve ilişkilendirme gibi görevlerde kullanılabilir (ekrandan, 00:40:00).

### 5.2 One-hot kodlama tartışması

ID sütunu atıldı ve sözel değişkenler sayısala çevrildi; öznitelik sayısı 17'den 30'a çıktı (ekrandan, 00:45:00). Örneğin `SMOKE_no`, `SMOKE_yes`, `MTRANS_Automobile`, `MTRANS_Bike`, `MTRANS_Motorbike`, `MTRANS_Public_Transportation`, `MTRANS_Walking` ayrı 0/1 sütunlarıdır.

> **Ders sonrası not:** Sunumda bu dönüşüm "label encoding" diye anıldı; ekrandaki sütunlar (her kategori için ayrı 0/1 sütunu) one-hot kodlamadır. Label encoding, kategorileri tek sütunda 0, 1, 2, ... tam sayılarıyla gösterir.

Hoca şu soruyu sordu: sigara içen ve içmeyen için iki ayrı sütun açmak yerine tek sütunda değer vermek neden tercih edilmedi? Hocanın gerekçesi şuydu: 20 bin kişiden 18 bini sigara içmiyorsa `SMOKE_yes` sütununda 18 bin sıfır bulunur; çok fazla sıfır içeren bir öznitelik, ağ derinleştikçe etkisini kaybeder. Ayrıca öznitelik sayısı arttıkça ağın karmaşıklığı artar. Hoca alternatif olarak anket cevaplarının tek sütunda sayısal etiketlenmesini önerdi; örneğin ulaşım türü için bisiklet, otobüs, motor, yürüme cevaplarına 1, 2, 3, 4 verilir.

Öğrenci buna karşı bir risk dile getirdi: aynı sütunda 4 değeri 1'den büyük bir sayı olduğu için ağ "otomobil" kategorisini "yürüme"den daha ağırlıklı algılayabilir; oysa kategoriler arasında böyle bir büyüklük ilişkisi yoktur ve hepsinin eşit katkı yapması istenir. Ayrı sütun açılmasının nedeni budur. Hoca bu görüşün de olabileceğini, hangisinin daha iyi olduğunun denenerek görülmesi gerektiğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Genel uygulamada sırası olmayan (nominal) kategoriler için one-hot kodlama, doğal sırası olan (ordinal) kategoriler için tek sütunda sıralı tam sayı kodlaması tercih edilir. Sıralı kodlamanın nominal veride sahte bir büyüklük ilişkisi yaratması, öğrencinin dile getirdiği sorundur.

### 5.3 Korelasyon

Korelasyon matrisi `df.corr()` ile hesaplanıp Seaborn `heatmap` ile çizildi (ekrandan, 00:50:00). Renk koyulaştıkça ilişki güçlenir; köşegen her değişkenin kendisiyle korelasyonudur (1). Hoca matristen yaşla otomobil kullanımı arasındaki pozitif, yaşla toplu taşıma arasındaki ters ilişkiyi okudu. Obezite düzeyini en çok etkileyen öznitelikler sırasıyla kilo, ailede aşırı kilo, yaş, alkol ve su tüketimiydi.

### 5.4 Normalizasyon

Hoca, öznitelikler farklı aralıklarda olduğunda uygulanan bu ölçeklendirmenin adını sordu; cevap **normalizasyon** idi. Hoca bunu, öznitelikler arasındaki ilişkiyi koruyarak yapılan bir ölçeklendirme olarak özetledi.

### 5.5 Ağ yapısı ve sonuçlar

Model (ekrandan, 00:55:00):

```python
model = Sequential([
  Dense(X.shape[1], activation='softmax', input_shape=(X.shape[1],)),  # Giriş Katmanı
  Dense(128, activation='relu'), Dense(128, activation='relu'), Dense(128, activation='relu'),
  Dense(128, activation='relu'), Dense(128, activation='relu'), Dense(128, activation='relu'),
  Dense(128, activation='relu'), Dense(128, activation='relu'),
  Dense(len(df['NObeyesdad'].unique()), activation='softmax')  # Çıkış Katmanı
])
optimizer = SGD()
model.compile(optimizer=optimizer, loss='sparse_categorical_crossentropy', metrics=['accuracy'])
model.summary()
```

Girişte 30 öznitelik, çıkışta 7 sınıf vardır. Sunumda toplam parametre sayısı 121.385 olarak verildi; bu değer şöyle doğrulanır (ara adım eklendi):

- Giriş katmanı: $30 \cdot 30 + 30 = 930$
- İlk gizli katman: $30 \cdot 128 + 128 = 3968$
- Diğer 7 gizli katman: $7 \cdot (128 \cdot 128 + 128) = 7 \cdot 16512 = 115584$
- Çıkış katmanı: $128 \cdot 7 + 7 = 903$
- Toplam: $930 + 3968 + 115584 + 903 = 121385$

Öğrenci girişte ReLU kullanınca ölçeklenmiş verideki negatif değerlerin sıfırlandığını ve sonucun bozulduğunu, softmax ya da sigmoid ile bu sorunun yaşanmadığını gözlemledi. Kayıp olarak etiketler 0–6 tam sayıları olduğu için `sparse_categorical_crossentropy` seçildi; tek değerli etiketlerde "sparse" sürüm, one-hot etiketlerde kategorik sürüm kullanılır.

> **Ders sonrası not:** Hoca "sparse" kelimesini sıfırları çok olan matris anlamında açıkladı ve öznitelikteki çok sayıda sıfırla ilişkilendirdi. Keras'taki `sparse_categorical_crossentropy` adındaki "sparse" ise etiketlerin one-hot vektör yerine tam sayı sınıf numarası olarak verildiğini belirtir; giriş özniteliklerinin seyrekliğiyle ilgisi yoktur. İki kayıp matematiksel olarak aynı değeri hesaplar.

Eğitimde %80 eğitim / %20 test bölmesi, farklı öğrenme oranı, epoch ve batch kombinasyonları denendi. Adam için en iyi ayar 100 epoch, öğrenme oranı 0,0005, batch 32 oldu (ekrandan, 01:00:00); eğitim doğruluğu yaklaşık 0,89'a, test doğruluğu yaklaşık 0,87'ye çıktı, kayıp yaklaşık 0,35 civarına indi. SGD ile yaklaşık %90 başarı bildirildi. Hoca, SGD'nin genelde daha büyük, Adam'ın ise daha küçük öğrenme oranlarıyla iyi çalıştığını ve sonuçların da bunu gösterdiğini belirtti. Ayrıca karışıklık matrisinin içindeki sayıların (hangi sınıfın kaç örneğinin hangi sınıfa atandığının) yazdırılmasını istedi.

## 6. Tweet Duygu Analizi: Frekans Öznitelikleri ve Lojistik Regresyon

### 6.1 Veri ve öznitelik çıkarımı

Beşinci sunumda tweetleri olumlu ve olumsuz diye ayıran ikili bir duygu analizi modeli geliştirildi. Veri, NLTK'nin `twitter_samples` veri setidir: 5000 olumlu, 5000 olumsuz tweet; her sınıftan 4000'i eğitim, 1000'i test için ayrıldı.

Yöntem:

- Tweetlerdeki kelimelerden bir sözlük kurulur.
- Her kelimenin olumlu (1) ve olumsuz (0) tweetlerde kaç kez geçtiği sayılır.
- Her cümle için vektör: $V = [1,\ \sum \text{olumlu frekans},\ \sum \text{olumsuz frekans}]$. İlk bileşen sapma (bias) terimidir.

### 6.2 Sayısal örnek

Slayttaki örnek sözlük (ekrandan, 01:05:00):

| Kelime | 1 (olumlu) | 0 (olumsuz) |
|---|---|---|
| filmi | 2 | 2 |
| çok | 3 | 3 |
| beğendim | 2 | - |
| beğenmedim | - | 2 |
| oyunculuklar | 1 | 1 |
| iyi | 3 | - |
| senaryo | 1 | 1 |
| kötü | - | 3 |

"Senaryo çok iyi!" cümlesi için:

- Olumlu frekans toplamı: senaryo (1) + çok (3) + iyi (3) $= 7$
- Olumsuz frekans toplamı: senaryo (1) + çok (3) + iyi (0) $= 4$
- Sonuç: $V = [1, 7, 4]$

Hoca, sözlüğün bütün veri setinden mi çıkarıldığını sordu ve en çok olumlu ve en çok olumsuz geçen kelimelerin incelenmesini önerdi; bu vektördeki 7 ve 4 değerleri, sözlükteki 1 ve 0 sütunlarından anlam çıkarılarak verilir. Eklerin ("filmi", "filmden") nasıl ele alındığı sorusuna cevap ön işleme adımlarıydı: gürültü ve durak kelimelerin (stop words) atılması, kök bulma (stemming), parçalama (tokenization) ve normalizasyon.

### 6.3 Model ve hocanın yorumu

Basitlik ve hız nedeniyle lojistik regresyon seçildi; parametreler gradyan inişiyle, log-loss kaybıyla güncellendi; %97'nin üzerinde başarı elde edildi. Hoca, doğru ve yanlış sınıflandırılan örnek cümlelerin de rapora konmasını istedi.

Hoca ayrıca lojistik regresyonun bir regresyon tekniği olduğunu, ancak son katmanda sigmoid kullanıldığında çıkışın %50'nin üstünde ya da altında olmasına göre iki sınıftan birinin atandığını açıkladı; regresyon sonuçları normalde MSE gibi hata ölçüleriyle verilir, sınıf ataması ise bir eşikle yapılır.

> **Ders sonrası not:** Hoca lojistik regresyonun "sınıflandırma değil regresif bir yaklaşım" olduğunu söyledi. Lojistik regresyon adında "regresyon" geçse de standart olarak bir sınıflandırma yöntemidir: doğrusal bir skoru sigmoid ile sınıf olasılığına çevirir ve log-loss (ikili çapraz entropi) ile eğitilir; 0,5 eşiği bu olasılığı sınıfa dönüştürür.

## 7. Banka Müşteri Kaybı Sınıflandırması ve Veri Bölme

### 7.1 Veri ve ön işleme

Altıncı sunumda bir bankanın müşteri verisinden müşterinin bankadan ayrılıp ayrılmayacağı (Exited) tahmin edildi. Veri 10.000 satır ve 18 sütundan oluşur ve boş değer içermez. Sütunlar arasında kredi skoru, ülke, cinsiyet, yaş, müşterilik süresi (Tenure), bakiye, ürün sayısı, kredi kartı sahipliği, aktif üyelik, tahmini maaş, şikayet, memnuniyet puanı, kart türü ve kazanılan puan vardır (ekrandan, 01:10:00).

Ön işleme adımları:

- Kayıt numarası, müşteri kimliği ve soyadı tahmine katkı sağlamayacağı için atıldı.
- Cinsiyet 0/1 olarak kodlandı.
- Kart türü sıralı (ordinal) kabul edildi: Silver 0, Gold 1, Platinum 2, Diamond 3.
- Ülke (Fransa, İspanya, Almanya) one-hot kodlandı; üç sütun eklendi.
- Bakiye gibi büyük değerlerle ürün sayısı gibi küçük değerler aynı ölçekte olsun diye `StandardScaler` ile ölçekleme yapıldı.
- NumPy dizileri PyTorch tensörlerine çevrildi.

### 7.2 Model ve eğitim döngüsü

Sigmoid çıkışlı bir lojistik regresyon modeli kuruldu; kayıp ikili çapraz entropi, optimizasyon SGD, öğrenme oranı 0,01, 1000 epoch. Eğitim döngüsü (ekrandan, 01:15:00):

```python
num_epoch = 1000
losses = []
for epoch in range(num_epoch):
    y_predicted = model(X_train)              # ileri geçiş
    loss = criterion(y_predicted, y_train)    # kayıp
    loss.backward()                           # geri yayılım, gradyan hesabı
    optimizer.step()                          # parametre güncelleme
    optimizer.zero_grad()                     # gradyanları sıfırlama
    if (epoch+1) % 10 == 0:
        print(f"epoch: {epoch+1}, loss: {loss.item():.4f}")
        losses.append(loss.detach().numpy())

with torch.no_grad():
    y_predicted = model(X_test)
    y_predicted_cls = y_predicted.round()
    acc = y_predicted_cls.eq(y_test).sum()/float(y_test.shape[0])
    print(f"accuracy = {acc:.4f}")
```

Sigmoid çıkışı 0–1 arasında bir olasılıktır; `round()` ile 0,5'in üstü 1'e, altı 0'a yuvarlanır. Doğru tahminlerin sayısı test örneği sayısına bölünerek doğruluk bulunur. 10. epoch'ta kayıp 0,7991 idi (ekrandan, 01:15:00); test doğruluğu 0,9975 çıktı (ekrandan, 01:20:00). Karışıklık matrisinde 5 yanlış sınıflandırma vardı (3 tanesi gerçekte 0 iken 1, 2 tanesi gerçekte 1 iken 0); test kümesi 2000 örnek olduğundan $1995/2000 = 0{,}9975$ ile tutarlıdır.

Ardından öğrenme oranları 0,01, 0,1 ve 1 karşılaştırıldı. Her epoch onlu adımında kayıp değerleri (ekrandan, 01:20:00):

| Epoch | lr = 0,01 | lr = 0,1 | lr = 1 |
|---|---|---|---|
| 10 | 0,7536 | 0,1009 | 0,0139 |
| 50 | 0,6407 | 0,0752 | 0,0120 |
| 1000 | 0,1095 | 0,0146 | 0,0071 |

Küçük öğrenme oranında kayıp yüksekten başlayıp yavaş indi; 0,1 ve 1 daha düşük kayba ulaştı. Aynı karşılaştırma tam yığın gradyan inişiyle de yapıldı ve benzer sonuç alındı.

### 7.3 Hocanın değerlendirmesi: dengesizlik, tabakalı bölme ve K-katlı doğrulama

Hoca etiket dağılımını sordu: bir sınıfta yaklaşık 7000, diğerinde yaklaşık 2000 örnek vardı. Bu çok aşırı bir dengesizlik değildir, ancak:

- %80/%20 bölme yapılırken etiket oranının korunup korunmadığı (tabakalı bölme) kontrol edilmelidir.
- Tek bir bölmede şans eseri ayrımı kolay bir %20'lik kesim test kümesine düşmüş olabilir. Bunun için K-katlı çapraz doğrulama yapılır: örneğin 5 katta her seferinde ağ sıfırlanıp bir kat test edilir ve bir karışıklık matrisi elde edilir; 5 katın karışıklık matrisleri toplanınca bütün veri seti üzerinde bir karışıklık matrisi çıkar.
- Hangi özniteliğin öğrenmeye en çok katkı yaptığı incelenmelidir. Muhtemelen tek bir öznitelik sınıflandırmanın büyük kısmını yapıyordur; öznitelik–etiket korelasyonuna bakmak bunu doğrudan gösterebilir.

> **Hocanın vurgusu:** Her şeyi doğrudan makine öğrenmesine bırakmadan önce veriye ve öznitelikler ile örnekler arasındaki korelasyona bakmak gerekir; bazı ilişkiler doğrudan görülebilir.

> **Ek bilgi (derste anlatılmadı):** Bu veri setinde test doğruluğunun bu kadar yüksek çıkması, büyük olasılıkla şikayet (Complain) sütununun hedef değişkenle neredeyse birebir örtüşmesinden kaynaklanır. Hedefle bu kadar ilişkili bir öznitelik, hocanın sözünü ettiği "tek bir özniteliğin sınıflandırmayı yapması" durumuna örnektir.

## 8. Beyin Tümörü Sınıflandırması: Optimizasyon Algoritmalarının Karşılaştırılması

### 8.1 Veri ve model

Yedinci sunumda BR35H veri setiyle MR görüntülerinde tümör var/yok sınıflandırması yapıldı: 1500 tümörlü ve 1500 tümörsüz görüntü. Veri etiket oranı korunarak %60 eğitim, %20 doğrulama, %20 test olarak bölündü. Görüntüler 224 × 224 yerine 128 × 128'e küçültüldü (performans değişmedi); öğrenme oranı $10^{-3}$.

Hoca tümörün alt sınıfları (meningioma, glioma, hipofiz) olup olmadığını sordu; bu veri setinde yalnız var/yok etiketi vardı, alt sınıflar referans makaledeki başka bir veri setine aitti.

Model:

- Evrişim 1: gri tonlamalı tek kanal giriş, 16 çıkış kanalı, 3×3 çekirdek, valid padding: $128 \to 126$.
- Max pooling 2×2: $126 \to 63$.
- Evrişim 2: 32 kanal, 3×3, valid padding: $63 \to 61$.
- Tam bağlı katman: 128 birim; çıkış katmanı: 2 birim.
- Toplam parametre sayısı yaklaşık 3.691.000.

> **Ders sonrası not:** Anlatılan katmanlarla ($32 \cdot 61 \cdot 61$ girişli tam bağlı katman) parametre sayısı yaklaşık 15,2 milyon çıkar. Verilen yaklaşık 3,69 milyon değeri, ikinci evrişimden sonra da bir 2×2 max pooling ($61 \to 30$) bulunduğunda tutar: $160 + 4640 + (32 \cdot 30 \cdot 30 \cdot 128 + 128) + (128 \cdot 2 + 2) = 3.691.586$. Büyük olasılıkla modelde ikinci bir havuzlama katmanı vardır (python ile hesaplandı).

### 8.2 Optimizasyon algoritmaları ve eğri okuma

Adam, Adagrad ve SGD 10'ar epoch eğitildi. ReLU ile kayıp grafiklerinde (ekrandan, 01:25:00) Adam'ın eğitim kaybı yaklaşık 0,64'ten 0,01'e hızla indi, doğrulama kaybı yaklaşık 0,12'de yataylaştı; Adagrad'ın doğrulama kaybı zikzaklı (0,33–0,56 arası) seyretti; SGD'nin kaybı ise 0,69'dan yalnız yaklaşık 0,62'ye doğrusal ve yavaş indi. Leaky ReLU denemesinde belirgin fark çıkmadı; ReLU biraz daha iyiydi.

Hoca, bu grafiklerin epoch sayısına karar vermek için incelendiğini söyledi: Adam için eğitim kesilebilir, ama Adagrad'ın kaybı hâlâ düştüğü için epoch artırılmalıdır; SGD ise 10 epoch'ta henüz yolun başındadır, ileride ne olacağını görmek için daha uzun eğitim gerekir.

> **Hocanın vurgusu:** Kayıp eğrileri, eğitimin daha devam etmesi mi gerektiğine yoksa yeterli mi olduğuna karar vermek için analiz edilir.

### 8.3 Karışıklık matrisleri

Slayttaki karışıklık matrisi karşılaştırması (ekrandan, 01:30:00), satırlar gerçek, sütunlar tahmin:

| Optimizasyon | Tümör yok → yok | Tümör yok → var | Tümör var → yok | Tümör var → var | Doğruluk |
|---|---|---|---|---|---|
| Adam | 292 | 8 | 12 | 288 | 580/600 = %96,7 |
| Adagrad | 256 | 44 | 15 | 285 | 541/600 = %90,2 |
| SGD | 225 | 75 | 105 | 195 | 420/600 = %70,0 |

<!-- BELİRSİZ: Bu matrisler Leaky ReLU sonuçları anlatılırken ekrandaydı; ReLU mu Leaky ReLU mu olduğu kesin değil. Doğruluklar python ile hesaplandı. -->

En iyi sonuç Adam + ReLU ile yaklaşık %97 olarak bildirildi; literatürdeki çalışmaların çoğu %94–95, bir çalışma %99 bulmuştu. Hoca, %99 bulan çalışmanın daha derin bir ağ kullandığını ve sıfırın altını sabit bir negatif değere bağlayan farklı bir aktivasyon önerdiğini belirtti; sunumdaki sonucun kötü olmadığını söyledi.

<!-- BELİRSİZ: Hocanın anlattığı aktivasyonun tanımı ("sıfırın altında yaklaşık -0,5 sabit") altyazıdan tam çıkmıyor. -->

## 9. Sesten Öfke Tanıma: openSMILE Öznitelikleri ve Pencereleme

### 9.1 Problem ve veri

Sekizinci sunumda duygusal olarak etiketlenmiş ses kayıtlarından duygu sınıflandırması yapıldı. Literatürdeki çalışmaların çoğu çok sınıflıdır (öfke, iğrenme, korku, mutluluk, üzüntü, nötr); bu çalışmada yalnız **öfke (sinirlilik)** ele alındı. Gerekçeler: çağrı merkezi uygulamalarında en çok aranan duygu öfkedir; ayrıca duygusal ses veri setleri çoğunlukla aktörlere belirli bir duyguyla okutularak hazırlanır ve öfke, nesnel olarak etiketlemesi en kolay duygudur. Sınıf sayısı arttıkça başarı düşer.

Literatürde çalışmalar iki noktada ayrışır: sesten hangi özniteliklerin çıkarılacağı (maliyet, hız ve ihtiyaca göre) ve hangi sınıflandırıcının kullanılacağı (SVM, karar ağacı, sinir ağı). Her yaklaşımın analiz süresi, maliyet, uygulanabilirlik ve doğruluk açısından avantaj ve dezavantajları vardır (ekrandan, 01:35:00).

Veri seti CREMA-D'dir: 91 konuşmacı, aksanlı İngilizce, altı duygu (öfke, iğrenme, korku, mutluluk, üzüntü, nötr). Çalışmada öfkeli ve nötr kayıtlar seçildi; konuşmacı etiketi kullanılmadı, duygu etiketi dosya adından alındı.

> **Ders sonrası not:** Sunumda kayıt sayısı "744" diye duyuldu; CREMA-D büyük olasılıkla 7442 kayıt içerir.

<!-- BELİRSİZ: Eğitim/test bölme sayıları altyazıda anlaşılmıyor. -->

### 9.2 openSMILE öznitelikleri

openSMILE, betik ya da arayüzle kullanılabilen açık kaynaklı bir ses öznitelik çıkarma yazılımıdır (ekrandan, 01:40:00):

- Ses verisinden güç, ses şiddeti, sıfır geçiş oranı, seslilik olasılığı, MFCC, LPC katsayıları ve F0 başlıklarında öznitelik çıkarır.
- Seçilen 988 öznitelik giriş, duygu etiketi çıkış olacak şekilde veri seti hazırlandı.
- MFCC'ler konuşma tanımada da kullanıldığı için ayrıca 456 MFCC özniteliğinden ve 532 MFCC dışı öznitelikten oluşan iki veri seti daha hazırlandı ($456 + 532 = 988$).

Ses önce kısa çerçevelere (frame) bölünür, her öznitelik için çerçeveler üzerinden ortalama, medyan, standart sapma, üçüncü moment, en küçük ve en büyük gibi istatistikler alınır.

### 9.3 Pencereleme ve ortalama alma tartışması

Hoca şu soruyu sordu: 30 saniyelik ve 1 dakikalık iki kaydın MFCC öznitelik sütun sayısı aynı mıdır? Cevap: kayıt 100 milisaniyelik pencerelere bölünüp her pencerede öznitelikler hesaplanır, sonra pencereler üzerinden istatistikler alınır; böylece kayıt süresinden bağımsız olarak eşit sayıda sütun elde edilir. Konuşma tanımada öznitelikler zaman serisi olarak kullanılır, duygu tanımada ise kaydın tamamı için tek bir karar verilir.

Hoca bunun bir sakıncasını belirtti: örneğin "I am on my way to the meeting" cümlesinde öfke vurgusu belirli bir kelimede olabilir; bütün pencerelerin ortalaması alınınca bu vurgu söner. Öfkeli–nötr ayrımında ortalama bu anlamı kaybettirmeyebilir, çünkü nötr kayıtta ortalama zaten düşüktür; ama iğrenme gibi başka sınıflar girdiğinde sorun çıkabilir. Hoca, segmentlerden çıkarılan özniteliklerin ortalanmak yerine yan yana dizildiği bir alternatiften söz etti. Öğrenci yalnız ortalamanın değil birçok istatistiğin kullanıldığını ve gerçek uygulamada konuşmanın önce cümle benzeri segmentlere bölündüğünü, her segment için tek bir "öfkeli / değil" kararı verildiğini açıkladı. Hoca, iki sınıf olduğu ve sınıflar gerçekten ayrılabildiği için bu yaklaşımın başarılı olmasını doğal buldu.

### 9.4 Sonuçlar

Deneyler scikit-learn ile SVM kullanılarak yapıldı (ekrandan, 01:50:00):

- Öfkeli–nötr, bütün öznitelikler: test başarısı yaklaşık %93.
- Öfkeli–öfkeli değil (nötrlerin bir kısmı yerine rastgele diğer duygular eklendi): yaklaşık %86.
- Yalnız MFCC öznitelikleri: %89,7436.
- Yalnız MFCC dışı öznitelikler: %91,2821.
- Yorum: yalnız konuşma tanımada kullanılan MFCC'lerle de yüksek başarı alınabilir, ancak MFCC dışı öznitelikler de önemli bilgi taşır. Bu, konuşma tanıma için zaten çıkarılmış MFCC'lerin ek maliyet olmadan duygu tanımada da kullanılabileceğini gösterir; ses işlemede en büyük maliyet öznitelik çıkarımıdır.

Hoca, sınıf bazında doğrulukların (karışıklık matrisi) ve örnek dağılımının verilmesini istedi; dağılımın dengeli olduğu gösterildi. Hoca, özgün makalede 6 sınıflı yapıda nötrün yaklaşık %97, öfkenin yaklaşık %74 doğrulukla bulunduğunu hatırlattı. Öneriler arasında öznitelik seçimi analizi, farklı veri setleriyle çapraz test (bir veri setinde eğitilen modelin diğerinde başarısının çok düştüğü gözlendi) ve veri setlerini birleştirerek eğitim vardı.

> **Hocanın vurgusu:** Ders kapsamında en az bir derin öğrenme ağının kurulup eğitilmesi beklenir; öznitelik vektörü üzerinde SVM'in yanında örneğin 1B CNN gibi sinir ağı yapıları da denenmelidir.

## 10. Video Duvarı Arıza Tespiti: CNN mi, Histogram mı?

### 10.1 Problem

Son sunumda bir üretim tesisindeki anlık üretim takibini gösteren dokuz ekranlı bir video duvarı ele alındı. Ekranlardan biri kararınca diğerleri de sırayla kararmaya başlıyor; bunun anında tespit edilip bildirim gönderilmesi gerekiyor. Ekranları sürekli aynı açıyla kaydeden bir güvenlik kamerası vardır; amaç bu görüntüden derin öğrenmeyle arızayı otomatik tespit etmektir.

### 10.2 Veri hazırlığı

Elde biri normal (yaklaşık 506 s), biri arızalı (330 s) iki video vardı; toplam kare sayıları 15.180 ve 9900 (30 FPS). Hazırlık adımları (ekrandan, 02:00:00):

- Videolar yalnız gerekli alan kalacak şekilde kırpıldı; çözünürlük 300 × 600'e düştü.
- Alt örnekleme ile FPS 30'dan 3'e indirildi.
- Her kare bir NumPy dizisine çevrildi.
- Karelere 4 farklı filtre uygulandı: siyah-beyaz, Sobel X, Sobel Y ve gradyan büyüklüğü.

Toplam 2512 görüntü elde edildi: 1520 normal (etiket 0), 992 arızalı (etiket 1). Bu sayı, iki videonun 3 FPS'teki kare sayısıyla tutarlıdır: $(506 + 330) \cdot 3 \approx 2508$. Veri oranlar korunarak 1607 eğitim, 402 doğrulama ve 503 test görüntüsüne bölündü ($1607 + 402 + 503 = 2512$).

### 10.3 Model denemeleri ve sonuçlar

Filtre türü, evrişim katmanı sayısı, filtre sayısı, yoğun katman sayısı ve birim sayısı, epoch, batch (8 ve 32) ve öğrenme oranı (0,1 ve 0,001) değiştirilerek 30 kombinasyon denendi. Tablodaki "Conv2D: 12" gibi değerler bir evrişim katmanının 12 kanallı olduğunu gösterir. Bütün modellerde Adam, çıkış dışındaki katmanlarda ReLU, çıkışta (ikili sınıflandırma için) sigmoid kullanıldı. F-skoru bu problem için daha uygun bir metrik olarak izlendi.

Bulgular:

- Gradyan büyüklüğü filtresi ve 4 evrişim + 4 yoğun katmanla test kümesinde %100 başarıya ulaşıldı; özgün görüntüyle aynı yapı test kümesinde yaklaşık %88 veriyordu.
- Batch büyüklüğünü 8'den 32'ye çıkarmak performansı artırdı.
- Tek yoğun katmanlı ağlarda birim sayısını artırmanın etkisi düşüktü; evrişim ve yoğun katman sayısını artırmak başarıyı artırdı, ama hesaplama süresini de uzattı.
- Öğrenme oranı 0,001 daha iyiydi; 0,1'de modeller yetersiz öğrenmeye (underfitting) meyilliydi.
- Eğitimde ve testte hiç kullanılmamış yeni bir arıza videosunda model, ekranlar kararınca çıkışı anında 1'e, düzelince 0'a çevirdi.

### 10.4 Hocanın değerlendirmesi

Hoca, çalışmanın ders kapsamında iyi bir uygulama olduğunu, ancak bu problem için derin öğrenmeye gerçekten gerek olup olmadığını sordu. Ekran kararınca siyah piksel sayısı artar; görüntünün histogramı çıkarılıp video dizisi içinde siyah piksel oranı yükseldiği anda uyarı gönderilebilir. Bu bir öğrenme değil, anlık görüntü analizidir; ama problem bununla da çözülebilir.

> **Hocanın vurgusu:** Bir problemi derin öğrenmeyle çözmeden önce daha basit, öğrenmesiz bir yöntemin (ör. histogram eşiği) yeterli olup olmadığı düşünülmelidir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:16:35): Nesne tespitinde sınırlayıcı kutu sonuçlarını nicel olarak değerlendirmek için hangi ölçüt kullanılır?

> **Çözüm (derste verilmedi):** mAP (mean Average Precision). mAP@0.5, tahmin kutusunun gerçek kutuyla IoU $\geq 0{,}5$ olduğunda doğru sayıldığı AP'lerin sınıf ortalamasıdır; mAP@0.5:0.95 ise 0,5–0,95 arası IoU eşiklerinin ortalamasıdır.

**Soru 2** (derste sözlü, 00:33:03 ve 00:34:36): Crab Age korelasyon matrisinde yaşla en yüksek ilişki hangi öznitelikte, öznitelikler arasında en yüksek ilişki hangi çiftte görülüyor?

Cevap (ekrandan, 00:35:00): Yaşla en yüksek korelasyon kabuk ağırlığındadır (0,66). Öznitelikler arasında en yüksek değer Length–Diameter (0,99); ağırlıklar arasında Weight–Shucked Weight ve Weight–Viscera Weight 0,97, Weight–Shell Weight 0,96'dır.

**Soru 3** (derste sözlü, 00:42:03): Sigara içme durumu iki ayrı 0/1 sütunuyla (`SMOKE_yes`, `SMOKE_no`) mı, tek sütunda sayısal değerle mi kodlanmalı?

Derste tartışılan cevap: İki ayrı sütunda çoğunluğu sıfır olan bir sütun oluşur ve öznitelik sayısı artar (hocanın görüşü). Tek sütunda sayısal kodlama ise sırası olmayan kategorilere sahte bir büyüklük ilişkisi yükler (öğrencinin görüşü). Hoca hangisinin daha iyi olduğunun denenerek görülmesi gerektiğini söyledi.

**Soru 4** (derste sözlü, 00:52:31): Farklı aralıklardaki öznitelikleri ortak bir ölçeğe getirme işlemine ne denir?

Cevap: Normalizasyon (ölçeklendirme).

**Soru 5** (derste sözlü, 01:07:08): Lojistik regresyon bir sınıflandırma problemi için nasıl kullanılır?

Derste verilen cevap: Son katmandaki sigmoid çıkışı 0–1 arasındadır; 0,5'in üstü bir sınıfa, altı diğer sınıfa atanır. (Lojistik regresyonun bir sınıflandırma yöntemi olduğuna dair düzeltme için Bölüm 6.3'teki ders sonrası nota bakın.)

**Soru 6** (derste sözlü, 01:12:49 ve 01:13:51): Etiketleri yaklaşık 7000'e 2000 dağılmış bir veri setinde %80/%20 bölme yapılırken nelere dikkat edilmeli?

Derste verilen cevap: Bölme etiket oranı korunarak (tabakalı) yapılmalı; tek bölmeye güvenmek yerine K-katlı çapraz doğrulama uygulanmalı ve katların karışıklık matrisleri toplanarak tüm veri üzerindeki karışıklık matrisi elde edilmelidir.

**Soru 7** (derste sözlü, 01:27:18): Adam, Adagrad ve SGD'nin 10 epoch'luk kayıp grafiklerine bakarak epoch sayısı hakkında ne söylenebilir?

Derste verilen cevap (grafikler ekrandan, 01:25:00): Adam'ın kaybı yataylaştığı için eğitim kesilebilir; Adagrad'ın kaybı hâlâ düştüğü için epoch artırılmalıdır; SGD'nin kaybı 0,69'dan yalnız 0,62'ye inmiştir, daha uzun eğitim gerekir.

**Soru 8** (derste sözlü, 01:38:07): 30 saniyelik ve 1 dakikalık iki ses kaydından çıkarılan MFCC öznitelik sütunlarının sayısı nasıl eşit tutulur?

Derste verilen cevap: Kayıt 100 ms'lik pencerelere bölünür, her pencerede öznitelikler hesaplanır ve pencereler üzerinden ortalama, medyan, standart sapma gibi istatistikler alınır; böylece süreden bağımsız sabit sayıda sütun elde edilir. Hoca bu ortalamanın zamansal vurguyu söndürebileceğini belirtti.

**Soru 9** (derste sözlü, 02:04:48): Bir video duvarındaki ekranların kararmasını tespit etmek için derin öğrenme gerekli midir?

Derste verilen cevap: Gerekli olmayabilir. Ekran kararınca siyah piksel sayısı artar; histogramda siyah piksel oranı bir eşiği aştığında uyarı gönderilebilir. Bu öğrenmesiz, anlık görüntü analizidir.

## Dersin Toparlaması

Bu oturumda öğrenci projeleri üzerinden dersin birçok konusu uygulamada görüldü: evrişimli ağlarla nesne tespiti (YOLO) ve piksel tabanlı segmentasyon, tablo verisinde çok katmanlı ağlarla regresyon ve çok sınıflı sınıflandırma, lojistik regresyon ile ikili sınıflandırma, Adam, Adagrad ve SGD'nin yakınsama davranışlarının karşılaştırılması, ReLU ile Leaky ReLU, `BCEWithLogitsLoss` ve `sparse_categorical_crossentropy` gibi kayıp seçimleri, ses verisinden öznitelik çıkarımı ve görüntü filtreleriyle CNN eğitimi.

Hocanın değerlendirmeleri birkaç ortak ilkede toplandı: sonuçlar nitel ve nicel olarak birlikte verilmeli; dengesiz verilerde tabakalı bölme ve K-katlı çapraz doğrulama kullanılmalı; kayıp eğrileri epoch kararında okunmalı; öznitelik ve korelasyon analizi modelden önce yapılmalı; kategorik verinin kodlanması bilinçli seçilmeli; ve basit yöntemlerle çözülebilen problemlerde derin öğrenmenin gerekliliği sorgulanmalıdır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
