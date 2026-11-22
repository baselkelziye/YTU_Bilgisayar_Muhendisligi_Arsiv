# Ders 9 Genişletilmiş Notu: Veri Toplama, Örnekleme Yöntemleri, Histogram, Ampirik PDF ve Tahmin Edicilere Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki dersin hatırlatması
- 2. Olasılık ve istatistik
- 3. Veri ve veri toplama adımları
- 4. Sayım, örnekleme çerçevesi ve örnek tasarımı
- 5. Olasılık örneklerinin türleri
- 6. Histogram
- 7. Göreli frekans histogramı
- 8. Ampirik PDF
- 9. İstatistiksel çıkarım: parametreler
- 10. Tahmin ediciler ve tahmin hataları
- 11. Yansız ve tutarlı tahmin ediciler
- Örnek Sorular

## 1. Önceki dersin hatırlatması

Bir önceki derste istatistiğin ne olduğu, istatistiğin iki türü (betimsel, yani descriptive ve çıkarımsal, yani inferential) ve temel terimler görülmüştü. Önce betimsel istatistik öğrenilecektir. Temel terimler şunlardı: popülasyon, örnek (sample), değişken (variable), veri (data), deney (experiment), parametre ve istatistik (statistic). Hoca ders sırasında bu tanımların yazılı olduğu sayfaya geri dönüp değişken tanımını tekrar okudu (ekrandan, 00:20:00):

- **Örnek:** popülasyonun bir alt kümesidir.
- **Değişken:** popülasyonun ya da örneğin her bir elemanı hakkında ilgilenilen bir özelliktir.
- **Veri:** değişken için popülasyonun ya da örneğin her elemanından toplanan değerler kümesidir.
- **Deney:** sonuçları bir veri kümesi veren planlı bir etkinliktir.
- **Parametre:** bütün popülasyonun sayısal bir özelliğidir; Yunan harfleriyle gösterilir.
- **İstatistik:** örneğin sayısal bir özelliğidir; Latin harfleriyle gösterilir.

## 2. Olasılık ve istatistik

Hoca "probability vs. statistics" başlığıyla başladı. Dersin ana sonucu şudur: olasılık teorisi istatistiğin aracıdır (vehicle). Olasılık teorisi çok iyi bilinmezse istatistiksel yöntemler kurulamaz, geliştirilemez; kendi algoritmalarınızı tasarlayıp uygulayamazsınız (ekrandan, 00:10:00).

Olasılık, olasılıklar (yani popülasyon) bilindiğinde bir şeyin (bir örneğin) gerçekleşme şansını sorar (ekrandan, 00:10:00). Hoca burada öğrencilere "possibility" ile "probability" arasındaki farkı sordu. Bir öğrenci "possibility"nin Türkçesini "olabilirlik", "probability"ninkini "olasılık" diye verdi. Hocanın açıklamasına göre possibility, örnek uzayla güçlü bir ilişki içindedir: zar atma deneyinin olası sonuçları gibi, popülasyonun kendisinden söz edilir. Probability ise bu olası sonuçlar (popülasyon) bilindiğinde bir örneğin şansını sorar (ekrandan, 00:15:00).

İstatistik ise sizden bir örnek çekmenizi, onu betimlemenizi ve sonra örnekte bulunan bilgiye dayanarak popülasyon hakkında çıkarım yapmanızı ister (ekrandan, 00:15:00). Bu üç fiil (draw, describe, make inferences) ekranda altı çizilerek vurgulandı.

## 3. Veri ve veri toplama adımları

İstatistik yapmak için veri gerekir. Hoca verinin çok önemli olduğunu, verinin sağlıklı ve güvenli toplanması gerektiğini, bu yüzden veri toplamanın kritik olduğunu vurguladı. "Data" kelimesinin Türkçesi sorulduğunda öğrenciler "veri" dedi; tekil "datum" veri, çoğul "data" veriler olarak düşünülebilir.

Popülasyondan veri toplamanın adımları şunlardır (ekrandan, 00:25:00):

- i) Deneyin amaçlarını tanımlamak.
- ii) Değişkeni ve popülasyonu tanımlamak. Değişken, popülasyonun ya da örneğin her elemanı hakkında ilgilenilen özellik olduğu için önceden tanımlanmalıdır.
- iii) Veri toplama ve ölçme şemalarını tanımlamak. Veri toplama aslında ölçmedir; bu adımda örnekleme prosedürü, örnek büyüklüğü ve ölçme aracı belirlenir.
- iv) Uygun betimsel ya da çıkarımsal veri analizi tekniklerini belirlemek.

## 4. Sayım, örnekleme çerçevesi ve örnek tasarımı

### 4.1 Sayım (census)

Sayım, popülasyonun her elemanını karşılık gelen veriyle birlikte listelemekten oluşan bir prosedürdür (ekrandan, 00:25:00). Popülasyonun çok sayıda elemanı (bireyi) vardır; bu bireyleri tek tek listelemeye census denir.

### 4.2 Örnekleme çerçevesi (sampling frame)

Örnekleme çerçevesi, örneğin çekileceği popülasyona ait elemanların ya da bireylerin listesidir. Bu liste popülasyonu temsil edici (representative) olmalıdır (ekrandan, 00:30:00).

### 4.3 Örnek tasarımı (sampling plan)

Örnek tasarımı ya da örnekleme planı, örnek verisini toplamak için kullanılan prosedürdür. Örnek tasarlamak, aslında popülasyondan verinin nasıl toplanacağının prosedürünü tasarlamaktır. İki tür örnek tasarımı vardır (ekrandan, 00:30:00):

- **Yargısal örnekler (judgement samples):** "tipik" olma esasına göre seçilen örneklerdir. Seçim, veriyi toplayan kişinin yargısının ne kadar sağlam olduğunu yansıtır.
- **Olasılık örnekleri (probability samples):** elemanların olasılık esasına göre seçildiği örneklerdir. İstatistiksel çıkarım bu tür örnekleri gerektirir (ekrandan, 00:35:00).

**Soru:** Judgement ile kastedilen, toplumdaki genel yargı ya da ön yargı gibi bir şey mi? **Cevap:** Hoca soruyu makine öğrenmesindeki eğitim ve doğrulama verisi üzerinden tartışmaya açtı: eğitimde görülmeyen doğrulama örnekleriyle eğitim örnekleri arasındaki ayrımı bu iki örnek türüyle ilişkilendirdi, ancak eşleştirmeyi öğrencilere "böyle mi, yoksa tam tersi mi?" diye sordu. <!-- BELİRSİZ: hocanın hangi örnek türünü eğitim, hangisini doğrulama verisine benzettiği altyazıda net değil (00:33:05-00:34:03). -->

## 5. Olasılık örneklerinin türleri

### 5.1 Rastgele örnek (random sample)

Rastgele örnekte, örnekleme çerçevesinden alınabilecek sabit $n$ büyüklüğündeki her olası örneğin seçilme olasılığı eşittir. Rastgele örnek elde etmek için bir rastgele sayı üreteci kullanılabilir (ekrandan, 00:40:00). Ekranda bu koşul şöyle yazıldı:

$$\Pr(S_i \text{ seçilir}) = \Pr(S_j \text{ seçilir}), \qquad \forall\, i \neq j$$

Burada $S_i$ $i$'inci örneğin, $S_j$ $j$'inci örneğin seçilmesidir.

Hoca bunu üç farklı tür bireyden oluşan bir popülasyonla açıkladı: rastgele örnekleme yaklaşımıyla çok sayıda örnek üretildiğinde, örneklerin yaklaşık üçte biri birinci türden, üçte biri ikinci türden, üçte biri üçüncü türden gelir. <!-- BELİRSİZ: üretilen örnek sayısı altyazıda önce "900", sonra "100" diye geçiyor (00:40:30-00:40:39). -->

### 5.2 Sistematik örnek (systematic sample)

Örnekleme çerçevesindeki her $k$'ıncı eleman seçilir. İlk elemanı belirlemek için bir rastgele sayı üreteci kullanılır. Popülasyon tekrarlıysa (repetitive) sistematik örnek kullanılmamalıdır (ekrandan, 00:45:00).

> **Ek bilgi (derste anlatılmadı):** Popülasyonda $k$ ile aynı periyotta tekrarlanan bir düzen varsa, her $k$'ıncı eleman hep aynı konumdaki elemana denk gelir ve örnek popülasyonu temsil etmez. Yasağın nedeni büyük olasılıkla budur.

### 5.3 Tabakalı örnek (stratified sample)

Tabakalı örnek, örnekleme çerçevesinin bazı özelliklere göre tabakalara ayrılması ve sonra her tabakadan sabit sayıda eleman seçilmesiyle elde edilir. Büyük popülasyonlarda kullanılır (ekrandan, 00:50:00). "Strata" çoğuldur, tekili "stratum"dur; Türkçede katman, tabaka anlamına gelir.

Hoca bunun için karınca yuvası örneğini verdi. Bir karınca yuvasında milyondan fazla karınca olabilir; dünyadaki karınca sayısı belki trilyona yaklaşır. Bir karınca türünün özellikleri incelenecekse karıncalar iri başlı ve küçük başlı, uzun bacaklı ve kısa bacaklı, dişleri büyük ve küçük, antenleri büyük, orta ve küçük gibi gruplara ayrılarak tabakalar oluşturulur. Sonra her tabakadan sabit sayıda karınca seçilir; örneğin uzun bacaklılardan bin tane, antenleri küçük olanlardan yüz tane. İstatistikler bu toplanan örnek üzerinden hesaplanır.

### 5.4 Kota örneği (quota sample)

Kota örneği, örnekleme çerçevesinin tabakalara ayrılması ve sonra her tabakadan, tabakanın büyüklüğüyle orantılı sayıda eleman seçilmesiyle elde edilir (ekrandan, 00:55:00).

Hoca önce sözlü bir örnek verdi: bin elemanlı tabakalı bir çerçevede iki tabaka olsun; birinde 750, diğerinde 250 eleman olsun. Bundan 4 elemanlı bir kota örneği oluşturulursa elemanların 3'ü birinci tabakadan, 1'i ikinci tabakadan gelir ($4 \cdot 750/1000 = 3$, $4 \cdot 250/1000 = 1$).

Ekrandaki örnekte ise üç tabaka vardır: $F_1$ tabakasında 500, $F_2$ ve $F_3$ tabakalarında 250'şer eleman. 4 elemanlı kota örneğinde $F_1$'den 2, $F_2$'den 1, $F_3$'ten 1 eleman alınır; 40 elemanlı kota örneğinde ise sırasıyla 20, 10 ve 10 eleman alınır (ekrandan, 00:55:00).

### 5.5 Küme örneği (cluster sample)

Küme örneği, örnekleme çerçevesinin tabakalara ayrılması ve tabakaların hepsinden değil, yalnız bazılarından eleman seçilmesiyle elde edilir (ekrandan, 00:55:00). Kota örneğine benzer ama bütün özellikler (tabakalar) dikkate alınmaz. Ekrandaki örnekte üç özellikten ikincisi atlanmış, yalnız birinci ve üçüncü özelliğe sahip gruplardan sırasıyla 200 ve 100 eleman alınmıştır. Hoca grupları yaşlılar, gençler, çocuklar gibi düşünmeyi önerdi: örneğin 200 yaşlı ve 100 çocuk alınır.

## 6. Histogram

Hoca öğrencilere histogramın ne olduğunu sordu. Bir öğrenci tablo halinde gösterilebileceğini, başka bir öğrenci belli aralıklarda dikdörtgenler şeklinde gösterilen bir grafik olduğunu söyledi. Hoca iki cevabı da doğru buldu; genelde histogram, yükseklikleri eleman sayısını gösteren dikdörtgen çubuklardan oluşan bir grafiktir. Histogram yaş dağılımına bakmada, görüntü işlemede, haberleşme sistemlerinde, fizikte, kimyada, biyolojide ve bilimin hemen her alanında kullanılır. Kuantum fiziğinde dalga fonksiyonu olasılıksal bir dalgadır; doğrudan ölçülemez ama ölçümlerin histogramları ya da dağılımları elde edilerek sonuçlara varılır.

Tanım (ekrandan, 01:15:00): Histogram, eşit genişlikte dikdörtgen şekillerinden oluşur; her dikdörtgenin yüksekliği, o dikdörtgenin tanımlandığı aralıktaki eleman sayısıyla orantılıdır.

### 6.1 CPU süresi örneği (kitaptan)

Bir uygulamanın CPU süreleri ölçülmüş; örnekteki CPU süreleri 9 saniye ile 139 saniye arasındadır. Aralıklar $[0,14), [14,28), [28,42), \dots$ olarak seçilir; her aralığın genişliği 14'tür (ekrandan, 01:15:00 ve 01:20:00). Ekranda verinin bir kısmı şöyle yazıldı: $9$, $112{,}3$, $15$, $16$, $110{,}4$, $130$, $131$, $78$, $56{,}4$, $65{,}2$, $30{,}9$, $61{,}2$, $77{,}7$, $82{,}6$, $112{,}4$, ... (ekrandan, 01:20:00). <!-- BELİRSİZ: listedeki birkaç değer (40 civarı, 19 civarı ve 113 civarı) el yazısından tam okunamadı; liste derste de eksik bırakıldı ("..."). -->

Aralıklardaki gözlem sayıları sayılır (ekrandan, 01:25:00):

- $[0, 14)$: 1 gözlem
- $[14, 28)$: 5 gözlem
- $[28, 42)$: 9 gözlem
- $[42, 56)$: 7 gözlem
- $[56, 70)$: 4 gözlem

Hoca her aralığın sağ ucunun aralığa dahil olmadığını (ör. 28 dahil değil) özellikle belirtti. Kalan aralıklar için değerler göreli frekans histogramında tamamlandı (ekrandan, 01:35:00):

- $[70, 84)$: 11, $[84, 98)$: 5, $[98, 112)$: 4, $[112, 126)$: 8, $[126, 140)$: 11

Bu sayılar yatay eksende $0, 14, 28, \dots, 140$ noktaları, düşey eksende gözlem sayısı olan çubuklar halinde çizildi. Histogram, her aralıkta kaç örnek bulunduğunu gösterir; bu, CPU süresinin histogramıdır.

## 7. Göreli frekans histogramı

Göreli frekans histogramı aynı çizimdir; yalnız çubuk yükseklikleri sayı yerine oranlardır. Hoca önce toplam örnek sayısını 80 diye varsayıp oranları $1/80$, $5/80$, ... diye yazdı. Sonra öğrencilere sayıları toplattı; toplam 65 çıktı ve hoca paydaları 65 olarak düzeltti: "empirical PDF'e geçince sayıyı salladığım için böyle oldu" dedi.

Toplam örnek sayısı $N = 65$ olduğunda göreli frekanslar şöyledir (ekrandan, 01:35:00):

$$\frac{1}{65},\ \frac{5}{65},\ \frac{9}{65},\ \frac{7}{65},\ \frac{4}{65},\ \frac{11}{65},\ \frac{5}{65},\ \frac{4}{65},\ \frac{8}{65},\ \frac{11}{65}$$

Bunlar olasılıklardır. Örneğin CPU süresinin 70 ile 84 arasında olma olasılığı $11/65$, 84 ile 98 arasında olma olasılığı $5/65$, 98 ile 112 arasında olma olasılığı $4/65$, 112 ile 126 arasında olma olasılığı $8/65$, 126 ile 140 arasında olma olasılığı $11/65$'tir.

Tanım (ekrandan, 01:35:00): Aralığın olasılığını gösteren bu tür histograma **göreli frekans histogramı** (relative frequency histogram) denir.

Bütün olasılıklar toplanırsa:

$$\frac{1}{65}+\frac{5}{65}+\frac{9}{65}+\frac{7}{65}+\frac{4}{65}+\frac{11}{65}+\frac{5}{65}+\frac{4}{65}+\frac{8}{65}+\frac{11}{65} = \frac{65}{65} = 1$$

> **Hocanın vurgusu:** Olasılıkların toplamının 1 olması önemli bir gözlemdir.

**Soru:** Buna olasılık diyoruz, ama gerçek olasılığa çok yakın olmayabilir. Olasılık diyebilmek için yapılan ölçüm sayısının bir alt sınırı olması gerekmez mi? **Cevap:** Burada elimizdeki 65 örnek hakkında konuşuyoruz: o örnekte verinin 98 ile 112 arasında olma olasılığı $4/65$'tir. İstatistik, eldeki veri kümesine göre verilir. Gerçek hayatta bu değer belki $3/65$ civarındadır; onu bulabilmek için 65 değil belki bir trilyon örnek gerekir, o zaman daha az hata yapılır.

## 8. Ampirik PDF

### 8.1 PDF'in temel özelliği

Hoca göreli frekans histogramını kopyalayıp ampirik PDF'e geçmeden önce PDF'in tanımını sordu. Öğrencilerden gelen "0 ile 1 arasında olması" cevabının olasılığın tanımı olduğunu, "sürekli olması" cevabının yetmediğini (her sürekli fonksiyon PDF değildir), "artan fonksiyon olması" cevabının ise CDF'in özelliği olduğunu söyledi. Doğru cevap: PDF negatif olmamalı ve altındaki toplam alan 1 olmalıdır.

Bunun üzerine göreli frekans histogramının altındaki alan soruldu. Her çubuğun genişliği 14 olduğu ve yükseklikler toplamı 1 olduğu için alan $14 \cdot 1 = 14$'tür, 1 değildir. Alanı 1 yapmak için her olasılık 14'e bölünür. $65 \cdot 14 = 910$ olduğundan ampirik PDF'in yükseklikleri şöyledir (ekrandan, 01:45:00):

$$\frac{1}{910},\ \frac{5}{910},\ \frac{9}{910},\ \frac{7}{910},\ \frac{4}{910},\ \frac{11}{910},\ \frac{5}{910},\ \frac{4}{910},\ \frac{8}{910},\ \frac{11}{910}$$

Bu, örnek için elde edildiği için **ampirik PDF** (empirical PDF) adını alır. Bir öğrencinin "örnek için baktığımız için mi empirical diyoruz?" sorusuna hoca "evet" cevabını verdi.

### 8.2 Bir aralığın olasılığı

Sürekli rastgele değişkende bir aralığın olasılığı PDF'in o aralıktaki integralidir. CPU süresinin 56 ile 70 arasında olma olasılığı:

$$\Pr(56 < X < 70) = \int_{56}^{70} \frac{4}{910}\,dx = \frac{4}{910}\,x\Big|_{56}^{70} = \frac{4\,(70-56)}{910} = \frac{4 \cdot 14}{910} = \frac{4}{65}$$

Sonuç, göreli frekans histogramındaki $4/65$ ile aynıdır (ekrandan, 01:45:00).

### 8.3 Birden fazla aralığa yayılan olasılık

Hoca ardından $\Pr(5 < X \le 46)$ olasılığını sordu. Bir öğrenci parçalara ayırıp hesaplanabileceğini söyledi. Alan grafikte yeşille tarandı: 5'ten başlayıp 46'ya kadar giden bölge, dört dikdörtgenin parçalarından oluşur (ekrandan, 01:45:00). Her parçanın alanı taban ile yüksekliğin çarpımıdır (ekrandan, 01:50:00):

$$\Pr(5 < X \le 46) = (14-5)\cdot\frac{1}{910} + (28-14)\cdot\frac{5}{910} + (42-28)\cdot\frac{9}{910} + (46-42)\cdot\frac{7}{910}$$

Ara sonuçlar (ara adım eklendi): $9 + 70 + 126 + 28 = 233$, dolayısıyla

$$\Pr(5 < X \le 46) = \frac{233}{910} \approx 0{,}256 \approx 0{,}26$$

Derste önce hesap makinesiyle yanlış bir değer okundu; hoca sonucun daha küçük olması gerektiğini, şekle bakınca alanın toplamın yaklaşık dörtte biri kadar göründüğünü söyledi ve doğru değer $0{,}26$ olarak bulundu.

### 8.4 Yöntem: verinin olasılık teorisine bağlanması

Ekranda şu akış çizildi ve "olasılık teorisini veri biliminde kullanmanın metodolojisi" olarak adlandırıldı (ekrandan, 01:50:00):

```text
Veri  ->  Histogram  ->  Göreli frekans histogramı  ->  Ampirik PDF
```

PDF bilindiğinde o sürekli dağılımla ilgili her şey elde edilebilir. Buradaki ampirik PDF kutulardan oluşan, kesikli görünen bir fonksiyondur. Her aralığın genişliği küçültülürse (ör. 0,1 ya da 0,001) kutu sayısı artar ve ampirik PDF sürekli bir eğri gibi görünür. Bu ampirik PDF ile olasılık teorisi veri biliminde ve makine öğrenmesi algoritmalarında kullanılabilir. Hoca bu bölümde anlattıklarının kitapta olmadığını, histogramla ilgili kitaptaki kısımların ayrıca okunması gerektiğini söyledi.

## 9. İstatistiksel çıkarım: parametreler

Dersin son bölümünde istatistiksel çıkarıma (statistical inference) başlandı; bu konu kitapta 8. ve 9. bölümlerdedir. Hoca önce "parametre nedir?" diye sordu. Bir öğrencinin "popülasyonun dağılımını bulmamıza yardım eden şeyler" cevabını kabul etmedi; başka bir öğrencinin "dağılımlarda parametre vardı" cevabını doğru buldu.

Şimdiye kadar birçok kesikli ve sürekli dağılım incelendi; bu dağılımların PDF'lerinin birçok parametresi olabilir (ekrandan, 02:10:00). Örneğin Gauss dağılımının PDF'i $-\infty$ ile $+\infty$ arasında tanımlıdır ve parametreleri $\mu$ ile $\sigma^2$'dir:

$$f_X(x) = \frac{1}{\sqrt{2\pi\sigma^2}}\exp\!\left(-\frac{(x-\mu)^2}{2\sigma^2}\right), \qquad -\infty < x < \infty$$

<!-- BELİRSİZ: Gauss PDF'inin derste yazılan hali incelenen karelerde görünmüyor; formül standart biçimde yazıldı. -->

> **Ders sonrası not:** Hoca formülü sözlü olarak "1 bölü 2 sigma kare, exponential x eksi mu bölü 2 sigma kare" diye okudu. Doğrusu yukarıdaki gibidir: katsayı $1/\sqrt{2\pi\sigma^2}$, üs $-(x-\mu)^2/(2\sigma^2)$ (eksi işareti ve kare dahil). Altyazıdaki okuma büyük olasılıkla eksik aktarılmıştır.

> **Hocanın vurgusu:** Hoca, kesikli ve sürekli rastgele değişkenlerin PDF'lerinin çoğunun "adınız gibi" ezbere bilinmesi gerektiğini söyledi. Olasılık ve istatistik mühendisliğin ana dişlisidir; özellikle Gauss dağılımının PDF'ini bilmeyen biri, kod yazabilse de mühendis sayılmaz.

Ekranda şu cümlenin altı çizildi:

> **Hocanın vurgusu:** $\mu$ ve $\sigma^2$, histogramı ya da ampirik PDF'i Gauss dağılımı şeklinde olan veri için bulmamız gereken parametrelerdir.

**Soru:** Bir histogramın ya da ampirik PDF'in hangi dağılımı izlediğini yalnız şekline bakarak mı anlıyoruz? **Cevap:** Evet.

### 9.1 Histogram şekilleri ve parametreler

Hoca üç histogram çizdi (ekrandan, 02:15:00 ve 02:20:00):

- **Çan şeklindeki histogram:** Gauss dağılımına benzer. PDF'indeki $\mu$ ortalama, $\sigma^2$ varyanstır. Soru: bu histogramın ait olduğu veriden $\mu$ ve $\sigma^2$ parametreleri nasıl elde edilir?
- **Sıfırdan başlayıp hızla azalan histogram:** öğrenciler önce geometrik dedi; hoca geometrik dağılımın kesikli olduğunu, bunun sürekli karşılığının üstel dağılım olduğunu söyledi. Sürekli rastgele değişkende üstel dağılım neyse, kesikli rastgele değişkende onun karşılığı geometrik dağılımdır. Üstel dağılımın PDF'i (ekrandan, 02:20:00):

$$f_X(x) = \frac{1}{\lambda}\exp\!\left(-\frac{x}{\lambda}\right), \qquad 0 < x < \infty$$

  Soru: bu histogramın ait olduğu veri için $\lambda$ nedir?
- **Sağa çarpık, tepeli üçüncü histogram:** öğrenciler Poisson dedi; hoca yalnız sürekli dağılımları düşünmeyi istedi ve bunun gama dağılımına benzediğini söyledi. Gama PDF'i derste sözlü olarak şöyle yazıldı:

$$f_X(x) = \frac{1}{\Gamma(m)}\left(\frac{m}{\Omega}\right)^{m} x^{m-1}\exp\!\left(-\frac{m}{\Omega}\,x\right), \qquad x > 0$$

  <!-- BELİRSİZ: gama PDF'i incelenen karelerde görünmüyor; formül altyazıdaki sözlü okumadan (02:21:06-02:21:25) kuruldu. -->

  Burada $m$ şekil parametresi, $\Omega$ ise ortalama güç (ortalama değer) parametresidir. Soru: bu histogramın ait olduğu veriden $m$ ve $\Omega$ nasıl tahmin edilir?

> **Ek bilgi (derste anlatılmadı):** Bu parametreleştirmede üstel dağılımın ortalaması $\lambda$, gama dağılımının ortalaması $\Omega$'dır. Gama PDF'i şekil $m$, ölçek $\Omega/m$ olan standart gama dağılımıyla aynıdır; $m = 1$ için ortalaması $\Omega$ olan üstel dağılıma indirgenir. (İntegrallerin 1 ettiği ve ortalamaların bu değerleri verdiği ajan tarafından python ile sayısal olarak denetlendi.)

Hoca bu dersten itibaren yalnız Gauss durumuna odaklanacaklarını söyledi: eldeki veri Gauss dağılımını izliyor; şimdi parametreleri, yani $\mu$ (ortalama), $\sigma$ (standart sapma) ve $\sigma^2$ (varyans) veri örneklerinden bulunacak (tahmin edilecek) (ekrandan, 02:25:00).

## 10. Tahmin ediciler ve tahmin hataları

### 10.1 Örnek istatistikleri

Popülasyon $X$'ten toplanmış rastgele bir örnek $S = (X_1, X_2, \dots, X_n)$ olsun. Örnek istatistikleri $\bar X$, $s$ ve $s^2$, popülasyon parametreleri $\mu$, $\sigma$ ve $\sigma^2$'nin tahmin edicileridir (estimator) (ekrandan, 02:30:00). Her tahmin edici, rastgele örneği girdi olarak alan bir fonksiyondur:

$$\bar X = f_\mu(S), \qquad s = f_\sigma(S), \qquad s^2 = f_{\sigma^2}(S)$$

Hoca önce üçüncüsünü yanlışlıkla $\sigma^2$ diye yazdığını, doğrusunun $s^2$ olduğunu belirtip düzeltti. Adlandırma şöyledir:

- $\mu$: popülasyon $X$'in kesin ortalaması; $\bar X$: örneklerden tahmin edilen ortalama (örnek ortalaması, sample mean).
- $\sigma$: popülasyonun kesin standart sapması; $s$: örneklerden tahmin edilen standart sapma (örnek standart sapması).
- $\sigma^2$: popülasyonun kesin varyansı; $s^2$: örneklerden tahmin edilen varyans (örnek varyansı, sample variance).

Hocanın örneği: Türkiye'deki ya da dünyadaki insanların boy ortalaması $\mu$'dür. Bütün dünyayı ölçmek gerekmez; Türkiye'den, Almanya'dan, İngiltere'den, Çin'den ve başka ülkelerden yüzer kişi alınarak örnek oluşturulur ve bu kişilerin boy ortalaması hesaplanır. Bu ortalama $\bar X$'tir ve $\mu$'ye yakınsaması beklenir.

### 10.2 Büyük örnek limiti ve hatalar

Örnek büyüklüğü $|S|$ sonsuza giderken örnek varyansı popülasyonun kesin varyansına, örnek ortalaması da popülasyon ortalamasına dönüşür:

$$\lim_{|S|\to\infty} s^2 = \sigma^2, \qquad \lim_{|S|\to\infty} \bar X = \mu$$

Bu, her zaman bir hata olduğu anlamına gelir: $|S|$ küçük bir sayıysa (örnek sayısı küçük, sonlu ise) şu hatalar vardır (ekrandan, 02:40:00):

- $e_1 = \bar X - \mu$: ortalama tahminindeki hata.
- $e_2 = s - \sigma$: standart sapma tahminindeki hata.
- $e_3 = s^2 - \sigma^2$: varyans tahminindeki hata.

**Soru:** Dünyadaki bütün insanların boyunu toplayamıyorsak bu hatayı nasıl bulacağız? **Cevap:** Tam hatayı bilmiyoruz; yalnız böyle bir hata olduğunu biliyoruz. Parametreleri tahmin ettiğinizde sonucun kesin olmadığını, bir hata içerdiğini bilmelisiniz. Tam hata bilinmez, ama olasılık teorisi kullanılarak analiz edilebilir.

## 11. Yansız ve tutarlı tahmin ediciler

### 11.1 Yansız tahmin edici

$\theta$ parametresinin tahmin edicisi $\hat\theta$ olsun. Ancak ve ancak

$$E[\hat\theta] = \theta$$

ise $\hat\theta$ yansızdır (unbiased). Bunun anlamı şudur: tahmin edici, gerçek değer ile bir hatanın toplamı olarak yazılabilir, $\hat\theta = \theta + e$. $\theta$ sabit olduğundan

$$E[\hat\theta] = E[\theta + e] = \theta + E[e]$$

olur. Tahminlerde hata yapılır; ama hataların ortalaması sıfırsa ($E[e] = 0$) tahmin edici iyi çalışıyor demektir ve buna yansız tahmin edici denir.

### 11.2 Tutarlı tahmin edici

Popülasyon parametresi $\theta$ için bir tahmin edici $\hat\theta$, örnek sayısı $n$ sonsuza giderken her $\varepsilon > 0$ için

$$\lim_{n\to\infty} \Pr\big(|\hat\theta - \theta| > \varepsilon\big) = 0$$

sağlanıyorsa tutarlıdır (consistent) (ekrandan, 02:50:00). Buradaki olasılık tümleyeniyle yazılabilir (ekrandan, 02:50:00):

$$\Pr\big(|\hat\theta - \theta| > \varepsilon\big) = 1 - \Pr\big(|\hat\theta - \theta| < \varepsilon\big) = 1 - \Pr\big(-\varepsilon < \hat\theta - \theta < \varepsilon\big) = 1 - \Pr\big(\theta - \varepsilon < \hat\theta < \theta + \varepsilon\big)$$

$\hat\theta$ kesin olarak $\theta - \varepsilon$ ile $\theta + \varepsilon$ arasındaysa sağdaki olasılık 1 olur ve ifade $1 - 1 = 0$ çıkar; tahmin edici tutarlıdır. Yani tahmin edicinin hatasının $-\varepsilon$ ile $+\varepsilon$ arasında kalması güvence altındadır. Başka bir deyişle, $\theta$ büyük bir örnekten tahmin edildiğinde mutlak tahmin hatasının $|\hat\theta - \theta|$ $\varepsilon$'dan büyük olması olası değildir.

> **Ek bilgi (derste anlatılmadı):** Örnek ortalaması $\bar X$ için $\mathrm{Var}(\bar X) = \sigma^2/n$ olduğundan, önceki derslerde görülen Chebyshev eşitsizliği $\Pr(|\bar X - \mu| > \varepsilon) \le \sigma^2/(n\varepsilon^2) \to 0$ verir; yani $\bar X$ tutarlı bir tahmin edicidir. Bu, büyük sayılar yasasının zayıf biçimidir.

## Örnek Sorular

### Soru 1: Kota örneğinin bileşimi

(ekrandan, 00:55:00) Örnekleme çerçevesi büyüklükleri 500, 250 ve 250 olan $F_1$, $F_2$, $F_3$ tabakalarına ayrılmıştır. 4 elemanlı ve 40 elemanlı kota örneklerinde her tabakadan kaç eleman alınır?

**Çözüm (derste verildi):** Kota örneğinde her tabakadan tabaka büyüklüğüyle orantılı sayıda eleman alınır. Toplam 1000 olduğundan oranlar $1/2$, $1/4$, $1/4$'tür. 4 elemanlı örnekte $2, 1, 1$; 40 elemanlı örnekte $20, 10, 10$ eleman alınır. (Sözlü örnekte 750 ve 250 elemanlı iki tabakadan 4 elemanlı kota örneği $3$ ve $1$ eleman içerir.)

### Soru 2: Gözlem sayısı ve göreli frekansların toplamı

(derste sözlü, 01:30:45) CPU süresi histogramındaki gözlem sayıları $1, 5, 9, 7, 4, 11, 5, 4, 8, 11$'dir. Toplam kaç gözlem vardır ve göreli frekansların toplamı nedir?

**Çözüm (derste verildi):** $1+5+9+7+4+11+5+4+8+11 = 65$. Göreli frekanslar $f_i/65$ olduğundan toplamları $65/65 = 1$'dir.

### Soru 3: PDF'in en önemli özelliği

(derste sözlü, 01:36:47) Bir fonksiyonun PDF olabilmesi için gereken en önemli özellik nedir?

**Çözüm (derste verildi):** Fonksiyon negatif olmamalı ve altındaki toplam alan 1 olmalıdır. Süreklilik yeterli değildir; artan olma CDF'in özelliğidir.

### Soru 4: Göreli frekans histogramının altındaki alan

(derste sözlü, 01:39:49) Göreli frekans histogramının altındaki alan 1 midir? Değilse ampirik PDF nasıl elde edilir?

**Çözüm (derste verildi):** Çubuk genişliği 14 ve yükseklikler toplamı 1 olduğundan alan 14'tür. Her yükseklik 14'e bölünür; $65 \cdot 14 = 910$ olduğundan ampirik PDF yükseklikleri $f_i/910$ olur ve toplam alan $\sum 14 \cdot f_i/910 = 1$ çıkar.

### Soru 5: Ampirik PDF ile tek aralığın olasılığı

(derste sözlü ve ekrandan, 01:42:07) Ampirik PDF'e göre CPU süresinin 56 ile 70 arasında olma olasılığı nedir?

**Çözüm (derste verildi):** $\int_{56}^{70} \frac{4}{910}\,dx = \frac{4 \cdot 14}{910} = \frac{4}{65} \approx 0{,}0615$ (ekrandan, 01:45:00).

### Soru 6: Ampirik PDF ile birden fazla aralığa yayılan olasılık

(ekrandan, 01:45:00) $\Pr(5 < X \le 46)$ nedir?

**Çözüm (derste verildi):** (ekrandan, 01:50:00)

$$\Pr(5 < X \le 46) = 9 \cdot \frac{1}{910} + 14 \cdot \frac{5}{910} + 14 \cdot \frac{9}{910} + 4 \cdot \frac{7}{910} = \frac{233}{910} \approx 0{,}26$$

### Soru 7: Gauss histogramından parametre elde etme

(ekrandan, 02:20:00) Histogramı Gauss dağılımına benzeyen bir verinin ait olduğu popülasyonun $\mu$ ve $\sigma^2$ parametreleri veriden nasıl elde edilir?

> **Çözüm (derste verilmedi):** Derste yalnız tahmin edicilerin $\bar X$ ve $s^2$ olduğu söylendi; formüller bir sonraki derse bırakıldı. Standart tahmin ediciler $n$ gözlemli bir örnek için $\bar X = \frac{1}{n}\sum_{i=1}^{n} X_i$ ve $s^2 = \frac{1}{n-1}\sum_{i=1}^{n} (X_i - \bar X)^2$'dir; ikisi de yansızdır. $\sigma$ için $s = \sqrt{s^2}$ kullanılır.

## Dersin Toparlaması

Bu derste istatistiğin olasılık teorisi üzerine kurulduğu vurgulandı ve istatistik için gereken verinin nasıl toplanacağı ele alındı. Veri toplamanın dört adımı, sayım ve örnekleme çerçevesi kavramları, yargısal ve olasılık örnekleri ile olasılık örneklerinin beş türü (rastgele, sistematik, tabakalı, kota, küme) tanımlandı. Ardından kitaptaki CPU süresi örneğiyle histogram, göreli frekans histogramı ve ampirik PDF kuruldu; ampirik PDF'in altındaki alanın 1 olması için göreli frekansların aralık genişliğine bölündüğü gösterildi ve aralık olasılıkları alan hesabıyla bulundu. Veri → histogram → göreli frekans histogramı → ampirik PDF akışı, olasılık teorisini veriye bağlayan yöntem olarak sunuldu.

Son bölümde istatistiksel çıkarıma geçildi: dağılımların PDF'lerindeki parametrelerin (Gauss için $\mu$, $\sigma^2$; üstel için $\lambda$; gama için $m$, $\Omega$) veriden tahmin edilmesi gerektiği, örnek istatistikleri $\bar X$, $s$, $s^2$'nin bu parametrelerin tahmin edicileri olduğu, sonlu örnekte tahmin hatalarının bulunduğu ve yansız ile tutarlı tahmin edici tanımları verildi. Bir sonraki derste ortalama ve varyansın örnekten nasıl tahmin edildiği işlenecektir (kitapta 8. ve 9. bölümler).

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
