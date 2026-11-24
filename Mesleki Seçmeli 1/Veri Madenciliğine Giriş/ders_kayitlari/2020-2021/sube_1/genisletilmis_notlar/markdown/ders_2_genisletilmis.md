# Ders 2 Genişletilmiş Notu: Veri Ön İşleme: Normalizasyon, Veri Yumuşatma ve Eksik Veri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Amacı: Veri Ön İşleme
- 2. Ham Verinin Temsili ve Veri Türleri
- 3. Sürekli ve Ayrık Değişkenler
- 4. Ham Verinin Özellikleri
- 5. Normalizasyon ve Neden Gerekli Olduğu
- 6. Ondalık Ölçekleme
- 7. Min-Max Normalizasyonu
- 8. Standart Sapma (Z-Score) Normalizasyonu
- 9. Derste Çözülen Normalizasyon Örneği
- 10. Veri Yumuşatma ve Kovalama
- 11. Farklar ve Oranlar: Öz Nitelik Çıkarımı
- 12. Eksik Veri
- 13. Örnek Sorular

## 1. Dersin Amacı: Veri Ön İşleme

Dersin ikinci haftasının konusu veri ön işlemedir (data preprocessing). Ders büyük ölçüde İngilizce anlatıldı; slaytların ortak başlığı "Data Mining: Preparing the Data" idi. Hoca dersin hedeflerini şöyle sıraladı: önce verinin yapısını ve veri türlerini incelemek, sonra normalizasyon tekniklerini (ondalık ölçekleme, min-max ve z-score) görmek, ardından eksik değerlerin giderilmesi ve aykırı değer analizi gibi veri hazırlama işlemlerine geçmek ve en sonunda zamana bağlı verinin (zaman serilerinin) veri madenciliği için nasıl hazırlanacağını konuşmak. Bu derste normalizasyon, veri yumuşatma, farklar ve oranlar ile eksik veri konuları işlendi; zamana bağlı veri ve aykırı değer analizi bir sonraki derse kaldı.

## 2. Ham Verinin Temsili ve Veri Türleri

Hoca, önceki haftada verilen tıbbi veri seti örneğini hatırlattı: hastalar ve onlara sorulan sorular. Veri madenciliğinde verinin yapısı hep aynıdır. Veri bir tablo, yani bir matris olarak düşünülür. Tablonun satırları örneklerdir (sample; kaynaklarda case ya da tuple da denir), sütunları öz niteliklerdir (feature; attribute ya da variable da denir). Matrisin her hücresi, o örneğin o öz nitelikteki değeridir.

Slaytta en yaygın iki veri türünün sayısal (numeric) ve kategorik (categorical) veri olduğu yazıyordu (ekrandan, 00:15:00).

### 2.1 Sayısal veri

Sayısal değerli bir öz niteliğin iki önemli özelliği vardır:

- **Sıra ilişkisi (order relation):** Değerler küçükten büyüğe sıralanabilir.
- **Uzaklık ilişkisi (distance relation):** İki değer arasındaki uzaklık ölçülebilir.

### 2.2 Kategorik veri

Kategorik veriye göz rengi, cinsiyet ya da vatandaşlık ülkesi örnek verilebilir. Müşterilerin gelir aralığını "düşük, orta, yüksek" diye vermek de kategorik bir öz nitelik üretir. Kategorik veride yalnız **eşitlik ilişkisi** kullanılabilir: İki kişinin göz rengi aynı ya da farklıdır, bir arabanın rengi diğerininkine eşittir ya da değildir. Yani sayısal veride sıra ve uzaklık ilişkisi, kategorik veride yalnız eşitlik ilişkisi vardır.

Bazı veri setleri kategorik değerleri temsil etmek için sahte değişkenler (dummy variables) kullanır. Örneğin bir arabanın renk öz niteliği, her renk için bir ikili (0/1) sütunla gösterilebilir. Bu ikili sütunlar kategorik değeri sayısal kodla ifade eden sahte değişkenlerdir.

## 3. Sürekli ve Ayrık Değişkenler

Sürekli değişkenler nicel (quantitative) ya da metrik değişkenler olarak da anılır ve aralık (interval) ya da oran (ratio) ölçeğiyle ölçülür. Hoca bu kısmın çok önemli olmadığını söyleyip geçti.

Ayrık değişkenler (discrete variables) nitel (qualitative) değişkenler olarak da anılır ve metrik olmayan iki ölçekten biriyle ölçülür: nominal ya da ordinal (ekrandan, 00:20:00).

### 3.1 Nominal ölçek

Nominal ölçek sırasız bir ölçektir; değişkenin farklı durumlarını göstermek için farklı semboller, karakterler ya da sayılar kullanır. Slayttaki örnek bir müşteri tipi öz niteliğidir: değerleri residential (konut), commercial (ticari) ve industrial (sanayi). Bu değerler A, B, C ya da 1, 2, 3 diye kodlanabilir, ama sayısal kodların diğer sayısal verilerdeki gibi metrik bir anlamı yoktur. Posta kodu da nominal bir öz niteliktir: kullanılan sayıların belirli bir sırası ya da birbirleriyle zorunlu bir ilişkisi yoktur.

### 3.2 Ordinal ölçek

Ordinal ölçek sıralı ayrık kademelerden oluşur. Örnekler: bir öğrencinin sınıftaki sıralaması, bir yarışmadaki altın, gümüş ve bronz madalya. Altın birinciyi, gümüş ikinciyi, bronz üçüncüyü gösterdiği için yarışmacılar sıralanabilir, ama aralarındaki uzaklık ölçülemez. Dördüncü ile beşinci arasındaki sıra bilinir, fakat aradaki farkın ne kadar olduğu bilinmez. Hoca, bu farkın belki testi ya da yarışı tamamlama süresiyle ölçülebileceğini, ama sıralama bilgisinin tek başına bunu vermediğini ekledi.

## 4. Ham Verinin Özellikleri

Slayttaki "Characteristics of Raw Data" maddeleri şunlardı (ekrandan, 00:25:00):

- Veri madenciliği için hazırlanan ham veri setleri genelde büyüktür; çoğu insanlarla ilgilidir ve dağınık (messy) olma eğilimindedir.
- Baştan eksik değerler, bozulmalar (distortion), yanlış kayıtlar (misrecording), yetersiz örnekleme (inadequate sampling) gibi sorunlar beklenmelidir.
- Bu sorunların hiçbirini göstermeyen ham veri hemen şüphe uyandırmalıdır.
- Verinin bu kadar kaliteli olmasının tek gerçek nedeni, analist görmeden önce temizlenmiş ve ön işlenmiş olması olabilir; örneğin doğru tasarlanmış bir veri ambarındaki veri.

Hoca yetersiz örneklemeyi hava sıcaklığı tahminiyle açıkladı. Yarının sıcaklığını tahmin etmek için bugünden ve dünden ölçümler gerekir. Peki örnekleme sıklığı ne olmalı? Sabah, öğleden sonra ve akşam alınan üç ölçüm yeterli olmayabilir; daha sık ölçüm gerekebilir. Veri setindeki eksik ya da yanlış kaydedilmiş değerlerin kaynağı farklı olabilir; önemli olan bu sorunları çözmek, eksik veriyi tamamlamak ve veriyi bozulmalardan temizlemektir.

## 5. Normalizasyon ve Neden Gerekli Olduğu

Normalizasyon, verinin ilk dönüşüm adımıdır. Sonunda veri setindeki bütün sayısal değerler $[-1,1]$ ya da $[0,1]$ gibi sabit bir aralığa taşınır.

Hoca gerekçeyi bir banka veri setiyle anlattı. Birinci sütunda müşterinin yaşı, başka bir sütunda yıllık geliri olsun. Yaş dar bir aralıkta değişir, yıllık gelir ise çok geniş bir ölçekte. Müşteriler arasındaki uzaklığı ölçtüğümüzde, büyük ölçekli öz nitelik uzaklığı belirler; yaşın etkisi, aralığı küçük olduğu için çok düşük kalır. Bu yüzden her sütunun sabit bir aralığa ölçeklenmesi gerekir.

Slayttaki ifadeler de bunu söylüyordu (ekrandan, 00:30:00): $n$ boyutlu uzayda noktalar arası uzaklık hesabına dayanan veri madenciliği yöntemleri en iyi sonuç için normalize veriye ihtiyaç duyabilir; değerler normalize edilmezse uzaklık ölçüleri ortalamada daha büyük değerli öz niteliklere fazla ağırlık verir. Veriyi normalize etmenin birçok yolu vardır; derste üç basit ve etkili teknik görüldü:

- Ondalık ölçekleme (decimal scaling)
- Min-max normalizasyonu
- Standart sapma normalizasyonu

**Soru:** Aralık $[-1,1]$ yerine $[-10,10]$ olsa ne değişir? **Cevap:** Pek bir şey değişmez. Önemli olan bütün öz niteliklerin (yaş, yıllık gelir vb.) aynı aralığa getirilmesidir. Ondalıklı sayıların hassasiyetiyle her iki aralıkta da aynı uzaklıklar ölçülebilir; aralığın $-10$–$10$ ya da $-100$–$100$ olması bu açıdan fark yaratmaz.

## 6. Ondalık Ölçekleme

Slayttaki tanım şöyleydi (ekrandan, 00:35:00): Ondalık ölçekleme ondalık noktayı kaydırır ama özgün rakam değerinin çoğunu korur. Tipik ölçek değerleri $-1$ ile $1$ arasında tutar. $v(i)$, $v$ öz niteliğinin $i$. örnekteki değeri ve $v'(i)$ ölçeklenmiş değer olmak üzere:

$$v'(i) = \frac{v(i)}{10^k}$$

Burada $k$, $\max_i |v'(i)| < 1$ koşulunu sağlayan en küçük tam sayıdır. Önce veri setindeki en büyük mutlak değer bulunur, sonra ondalık nokta ölçeklenmiş en büyük mutlak değer 1'den küçük olana kadar kaydırılır; bulunan bölen bütün değerlere uygulanır.

### 6.1 Örnek

Veri setindeki en büyük değer 455, en küçük değer $-834$ olsun. En büyük mutlak değer 834'tür. Bunu 1'den küçük yapmak için 1000'e bölmek gerekir, yani $k = 3$. Hoca dönüşümü sayı doğrusu üzerinde çizdi (ekrandan, 00:40:00):

- $-834 \to -0.834$
- $455 \to 0.455$

**Soru:** Koşul "1'den küçük" mü, "1'den küçük ya da eşit" mi? **Cevap:** Slaytta "küçük" yazıyor; ama örneğin değer 100 ise sonuç 1'e eşit de olabilir, eşitlik bir sorun yaratmaz.

### 6.2 Ondalık ölçeklemenin sorunu

Hoca bir sorun olduğunu söyledi: Hedef $[-1,1]$ aralığıydı, ama dönüşümden sonra yalnız $-0.834$ ile $0.455$ arası kullanılıyor. Negatif tarafta $-1$'e kadar, pozitif tarafta $+1$'e kadar olan bölgeler hiç kullanılmıyor. Yani verilen ölçeğin yalnız küçük bir bölümü kullanılıyor ve sayıların ayırt ediciliği azalıyor; değerler dar bir aralığa sıkıştırılıyor.

Bunu daha iyi görmek için hoca ikinci bir durum verdi. Verinin çoğu aynı aralıkta olsun, ama belki aykırı değer olan tek bir büyük değer, 1050, bulunsun. En büyük mutlak değer artık 1050 olduğu için 1000'e bölmek yetmez, 10000'e bölmek gerekir ($k=4$). Bu durumda $-834 \to -0.0834$ ve $455 \to 0.0455$ olur. Kullanılan aralık iyice daralır; $[-1,1]$ ölçeği verimli kullanılmaz.

**Soru:** Bir öğrenci sorunu tekrar açıklamasını istedi: Ondalık ölçeklemeyi neden kullanmak istemiyoruz? **Cevap:** Başka bir öğrencinin cevabı: $[-1,1]$ aralığının çok küçük bir kısmı kullanılıyor; 1050 örneğinde 10000'e bölüneceği için değerler sıfıra iyice yaklaşıyor. Ayrıca yöntem dağılımı değiştirmiyor ve aykırı değerleri ortadan kaldırmıyor. Hoca bunu onayladı ve yukarıdaki açıklamayı Türkçe olarak tekrar etti.

Slaytta bir sonraki yönteme geçerken aynı sorun başka bir sayıyla da gösteriliyordu (ekrandan, 00:45:00): Bir öz niteliğin değerleri 150 ile 250 arasındaysa ondalık ölçekleme bütün değerleri $0.15$ ile $0.25$ arasına koyar; değerler bütün aralığın küçük bir alt aralığında birikir.

## 7. Min-Max Normalizasyonu

Değerleri normalize aralığın tamamına daha iyi dağıtmak için min-max formülü kullanılır (ekrandan, 00:45:00):

$$v'(i) = \frac{v(i) - \min(v(i))}{\max(v(i)) - \min(v(i))}$$

Burada $v$ öz niteliğinin en küçük ve en büyük değerleri veri setinden otomatik hesaplanır ya da alanın uzmanı tarafından tahmin edilir. Benzer bir dönüşüm $[-1,1]$ aralığı için de kullanılabilir. Slayta göre min ve max'ın otomatik hesabı veri setinin tamamında bir tarama daha gerektirir ama hesaplama olarak basittir; uzman tahmini ise min ve max değerlerinde istenmeyen bir birikime yol açabilir. <!-- BELİRSİZ: slayttaki son cümle karede kesik; devamı okunmuyor. -->

### 7.1 Doğru denklemi olarak min-max

Hoca bu dönüşümün doğrusal olduğunu ve bir doğru denklemiyle gösterilebileceğini çizerek anlattı. Koordinat düzleminde x ekseni girdi değeri $v$, y ekseni çıktı yani normalize değer $v'$'dir. $[0,1]$ normalizasyonunda en küçük değer çıktıda 0'a, en büyük değer 1'e taşınır. Böylece doğrunun iki noktası bilinir:

- $(x_1, y_1) = (\min, 0)$
- $(x_2, y_2) = (\max, 1)$

İki noktası bilinen doğrunun denklemi yazılır ve bütün girdi değerleri bu denklemle ölçeklenmiş değere dönüştürülür. $[-1,1]$ aralığı istenirse aynı yöntem kullanılır; yalnız en küçük değer $-1$'e taşınır, yani ilk nokta $(\min, -1)$ olur.

## 8. Standart Sapma (Z-Score) Normalizasyonu

> **Hocanın vurgusu:** Slaytta yazmasa da bu yöntemin diğer adının **z-score normalization** olduğunu not alın; literatürde bu ad daha çok kullanılıyor.

Bir öz nitelik $v$ seçilir. Önce ortalaması, sonra standart sapması hesaplanır. Dönüşümde bu iki parametre kullanılır: her $v$ değerinden ortalama çıkarılır ve sonuç standart sapmaya bölünür (ekrandan, 01:10:00):

$$v' = \frac{v - \text{mean}}{\text{std}}$$

Hoca bunu çizimle anlattı. Ortalaması $m$ olan bir dağılım düşünelim. Her değerden ortalamayı çıkarmak, dağılımı orijine kaydırmak demektir. Sonra standart sapmaya bölünce, dağılım standart sapma birimleriyle ($s$, $2s$, $3s$) bölümlere ayrılmış olur; dağılımın büyük bölümü yaklaşık $-3s$ ile $+3s$ arasındadır. Böylece dönüştürülmüş bir değere bakarak dağılımın hangi bölümünde olduğumuzu, yani ortalamadan kaç standart sapma uzakta olduğumuzu anlayabiliriz.

Hoca bu yöntemin min-max normalizasyonundan ve ondalık ölçeklemeden daha iyi bir çözüm olduğunu ve derste görülen üç yöntem içinde z-score ile daha iyi sonuçlar elde edildiğini söyledi.

### 8.1 Standart sapmanın hesabı

Örneği çözerken hoca standart sapmanın nasıl hesaplandığını sordu ve öğrencilerden hatırlamalarını istedi. Hesap şöyledir:

$$s = \sqrt{\frac{1}{n-1}\sum_{i=1}^{n}(x_i - \bar{x})^2}$$

Her değerden ortalama çıkarılır, farkların kareleri alınıp toplanır, toplam $n-1$'e bölünerek varyans bulunur; varyansın karekökü standart sapmadır. Popülasyon değil de bir örneklem, yani küçük bir alt küme üzerinde çalışılıyorsa $n$'e değil $n-1$'e bölünür.

> **Hocanın vurgusu:** Standart sapmanın ve varyansın ne işe yaradığını ve nasıl hesaplandığını unutmayın. Çok önemli bir istatistiksel parametredir, birçok yerde işinize yarar; her mühendisin bilmesi gereken bir şeydir ve mülakat sorusudur.

## 9. Derste Çözülen Normalizasyon Örneği

Hoca bir metin belgesinde şu örneği gösterdi (ekrandan, 01:15:00):

> Bir boyutlu veri seti $X = \{3, 1, 0, 2, 7, 6, 4, -2, 10, 12\}$ veriliyor. Veri setini normalize edin ve $v = 0$ ile $v = 6$ için yeni değerleri bulun: (a) $[0,1]$ aralığında min-max normalizasyonu, (b) $[-1,1]$ aralığında min-max normalizasyonu, (c) standart sapma normalizasyonu.

Veri setinde 10 değer var. En küçük değer $-2$, en büyük değer $12$'dir (belgede kırmızıyla işaretliydi).

### 9.1 (a) $[0,1]$ aralığında min-max

Belgedeki çözüm (ekrandan, 01:15:00):

$$v' = \frac{v - \min}{\max - \min} = \frac{v + 2}{12 - (-2)} = \frac{v+2}{14}$$

Buna $v = 0$ ve $v = 6$ konur (ara adım eklendi):

- $v = 0$: $v' = 2/14 = 1/7 \approx 0.143$
- $v = 6$: $v' = 8/14 = 4/7 \approx 0.571$

> **Ders sonrası not:** Altyazıda paydanın "12" diye geçtiği bir yer var; belgede ve formülde doğrusu $12-(-2) = 14$'tür. Sonuçlar python ile kontrol edildi.

### 9.2 (b) $[-1,1]$ aralığında min-max

Hoca bu kez denklemi öğrencilerin bulmasını istedi ve tahtaya iki noktayı çizdi (ekrandan, 01:25:00): $(x_1, y_1) = (-2, -1)$ ve $(x_2, y_2) = (12, 1)$. İki noktadan geçen doğrunun denklemi:

$$\frac{x - x_1}{x_1 - x_2} = \frac{y - y_1}{y_1 - y_2}$$

Değerler konunca (ara adım eklendi):

$$\frac{x + 2}{-14} = \frac{y + 1}{-2} \;\Rightarrow\; y + 1 = \frac{x+2}{7} \;\Rightarrow\; y = \frac{x - 5}{7}$$

Bir öğrenci sonucu doğru buldu; hoca sonucun "$y = \dots$" biçiminde ve parantezle, $y = (x-5)/7$ olarak yazılmasını istedi. Belgede de $v' = (v-5)/7$ yazıyordu. Dönüştürülen değerler (ekrandan, 01:30:00):

- $x = 0$: $y = -5/7 \approx -0.714$
- $x = 6$: $y = 1/7 \approx 0.143$

### 9.3 (c) Standart sapma normalizasyonu

Hoca ortalamanın $4.3$, standart sapmanın yaklaşık $4.44$ olduğunu verdi. Python ile kontrol: ortalama $43/10 = 4.3$, $n-1$ ile standart sapma $\approx 4.448$. Dönüşüm $v' = (v - 4.3)/4.448$ olur:

- $v = 0$: $v' = -4.3/4.448 \approx -0.967$
- $v = 6$: $v' = 1.7/4.448 \approx 0.382$

<!-- BELİRSİZ: (c) şıkkının sonuç değerleri altyazıda söylenmiyor ve kareye düşmüyor; yukarıdaki iki sonuç python ile hesaplandı. -->

## 10. Veri Yumuşatma ve Kovalama

Normalizasyondan sonra ikinci dönüşüm veri yumuşatmadır (data smoothing). Slayttaki açıklama şöyleydi (ekrandan, 01:35:00): Sayısal bir öz nitelik bazen eğitim örneği sayısı kadar çok farklı değer alabilir. Birçok veri madenciliği tekniği için bu değerler arasındaki küçük farklar anlamlı değildir; yöntemin başarısını ve sonuçları bozabilir. Bu farklar aynı temel değerin rastgele sapmaları olarak düşünülebilir, bu yüzden değişkenin değerlerini yumuşatmak bazen yararlıdır.

### 10.1 Yuvarlama ile basit yumuşatma

Benzer ölçülen değerlerin ortalamasını alan birçok basit yumuşatıcı tanımlanabilir. Değerler birkaç ondalık basamaklı gerçel sayılarsa, verilen hassasiyete yuvarlamak basit bir yumuşatma algoritması olabilir. Slayt örneği:

$$F = \{0.93,\ 1.01,\ 1.001,\ 3.02,\ 2.99,\ 5.03,\ 5.01,\ 4.98\}$$

$$F_{\text{smoothed}} = \{1.0,\ 1.0,\ 1.0,\ 3.0,\ 3.0,\ 5.0,\ 5.0,\ 5.0\}$$

İlk üç değer 1'e, sonraki ikisi 3'e, son üçü 5'e çok yakındır. Bu basit dönüşüm veri setinde kalite kaybı olmadan yapılır ve öz niteliğin farklı değer sayısını üçe indirir. Fakat hoca, her yumuşatma işleminin yuvarlamayla yapılamayacağını, ek çözümler gerektiğini söyledi.

### 10.2 Yumuşatma yöntemleri

- Kovalama (binning)
- Regresyon
- Kümeleme
- Bilgisayar ve insan incelemesinin birlikte kullanılması

Derste kovalama yöntemi görüldü. Hoca "bin" kelimesini Türkçede "sepet" (ya da "sele") gibi düşünmeyi önerdi. Kovalama iki adımdan oluşur:

1. Veriyi sırala ve kovalara böl (partitioning).
2. Her kovayı yumuşat: kovadaki değerleri bir temsilci değerle göster. Temsilci değer olarak kovanın ortalaması ya da kova sınırları kullanılabilir.

### 10.3 Eşit genişlik ve eşit derinlik bölmeleme

Bölmeleme için birbirinin alternatifi olan iki yöntem vardır (ekrandan, 01:40:00):

- **Eşit genişlik (equal-width, distance) bölmeleme:** Aralık, eşit büyüklükte $N$ aralığa bölünür (düzgün ızgara). $N$ başta verilir. $A$ ve $B$ öz niteliğin en küçük ve en büyük değeriyse aralık genişliği $W = (B - A)/N$ olur; sıralı örnekler bu aralıklara göre ayrılır. En basit yöntemdir, ama aykırı değerler gösterime baskın gelebilir ve çarpık veri iyi işlenmez.
- **Eşit derinlik (equal-depth, frequency) bölmeleme:** Aralık, her biri yaklaşık aynı sayıda örnek içeren $N$ aralığa bölünür. Yine kaç kova olacağı baştan bilinir ve bölmeden sonra her kovada eşit sayıda örnek olur. İyi bir veri ölçeklemesi sağlar; kategorik öz niteliklerde uygulaması zor olabilir.

### 10.4 Kovalama örneği

Slayttaki örnek (ekrandan, 01:45:00): fiyat verisi (dolar) sıralı olarak

$$4,\ 8,\ 9,\ 15,\ 21,\ 21,\ 24,\ 25,\ 26,\ 28,\ 29,\ 34$$

12 örnek var ve amaç bunları eşit derinlikte 3 kovaya bölmek. Her kovada $12/3 = 4$ örnek olur. Hoca, örnek sayısı 13 olsaydı 3'e tam bölünmeyeceğini, bu durumda kovalardan birinin bir eleman fazla alabileceğini söyledi. Sıralı veriden ilk 4, ikinci 4 ve üçüncü 4 eleman alınır:

| Kova | Elemanlar | Ortalamayla | Sınırlarla |
|---|---|---|---|
| 1 | 4, 8, 9, 15 | 9, 9, 9, 9 | 4, 4, 4, 15 |
| 2 | 21, 21, 24, 25 | 23, 23, 23, 23 | 21, 21, 25, 25 |
| 3 | 26, 28, 29, 34 | 29, 29, 29, 29 | 26, 26, 26, 34 |

**Ortalamayla yumuşatma (smoothing by bin means):** Her kovanın ortalaması bulunur ve kovadaki bütün değerler bu ortalamayla gösterilir. Örneğin 4, 8, 9 ve 15 yerine dördü de 9 ile gösterilir.

> **Ders sonrası not:** 1. kovanın ortalaması tam 9'dur; 2. ve 3. kovaların gerçek ortalamaları $90/4 = 22.75$ ve $117/4 = 29.25$'tir. Slayttaki 23 ve 29 yuvarlanmış değerlerdir (python ile kontrol edildi).

Yumuşatma bir hata getirir: gerçek değer 4 iken yerine kovanın temsilci değeri kullanılır. Hoca bu hatanın **ortalama mutlak hata** (mean absolute error) ile ölçüleceğini anlattı ve formülü sohbete yazdı: her değer ile temsilci değeri arasındaki fark alınır, fark negatif ya da pozitif olabileceği için mutlak değeri alınır, mutlak farklar toplanır ve eleman sayısına bölünür:

$$\text{MAE} = \frac{1}{n}\sum_{i=1}^{n} |x_i - \hat{x}_i|$$

**Sınırlarla yumuşatma (smoothing by bin boundaries):** Her kovanın iki sınır değeri vardır; birinci kovada sol sınır 4, sağ sınır 15'tir. Aradaki her değer, kendisine **en yakın** sınır değeriyle değiştirilir. 8'in sol sınıra uzaklığı 4, sağ sınıra uzaklığı 7'dir; bu yüzden 4 olur. 9'un sol sınıra uzaklığı 5, sağ sınıra uzaklığı 6'dır; o da 4 olur. Sonuç 4, 4, 4, 15'tir.

**Soru:** Bir değerin iki sınıra uzaklığı eşitse ne yapılır? **Cevap:** İki sınırdan biri seçilebilir; hangisi seçilirse seçilsin hata aynı olur, önemli değildir.

## 11. Farklar ve Oranlar: Öz Nitelik Çıkarımı

Üçüncü dönüşüm yöntemi farklar ve oranlardır (ekrandan, 01:55:00). Slayttaki maddeler:

- Öz niteliklerdeki küçük değişiklikler bile veri madenciliği başarısında önemli iyileşme sağlayabilir.
- Girdi ya da çıktı öz niteliklerindeki görece küçük dönüşümlerin etkisi, özellikle veri madenciliği hedeflerinin belirlenmesinde önemlidir.
- İki basit dönüşüm türü, farklar ve oranlar, özellikle çıktı öz niteliklerine uygulandığında hedef belirlemeyi iyileştirebilir.
- Fark ve oran dönüşümleri yalnız çıktı öz nitelikleri için değil, girdiler için de yararlıdır. Bir öz niteliğin zaman içindeki değişimi olarak ya da farklı girdi öz niteliklerinin birleşimi olarak kullanılabilirler (ekrandan, 02:15:00).

Hoca örneği tıbbi veri setleriyle verdi. Birçok tıbbi veri setinde hastanın boyu ve kilosu ayrı iki öz nitelik olarak bulunur. Boy tek başına kişinin uzun ya da kısa, kilo tek başına kişinin hafif ya da ağır olduğunu söyler. Ama ikisi birlikte değerlendirilip oranlanarak vücut kitle indeksi (body mass index, BMI) adlı yeni bir öz nitelik üretilirse, bu yeni öz nitelik ayrı ayrı boy ve kilodan daha fazla bilgi verir; slayta göre birçok uygulamada bu dönüşümle daha iyi teşhis sonuçları alınmıştır.

Var olan öz niteliklerden yeni bir öz nitelik üretmeye **öz nitelik çıkarımı (feature extraction)** denir. Hoca benzer bir örnek olarak gözlerle ilgili bir tıbbi veri setinde sol ve sağ göz ölçümlerinden fark ve oranlarla ek öz nitelikler üretildiğini gördüğünü anlattı. Alanın uzmanı, farklar ve oranlarla ek öz nitelikler üretmeye karar verebilir. Yani bu yöntem bir dönüşüm yöntemidir, ama aslında öz nitelik çıkarımı için kullanılır.

> **Ek bilgi (derste anlatılmadı):** BMI, kilogram cinsinden kilonun metre cinsinden boyun karesine bölünmesiyle bulunur: $\text{BMI} = \text{kilo}/\text{boy}^2$. Bu yüzden bir oran dönüşümüne iyi bir örnektir.

## 12. Eksik Veri

Ölçümlerdeki sorunlar yüzünden veri setinde eksik değerler olabilir ve bunların giderilmesi gerekir. <!-- BELİRSİZ: 02:17 civarında eksik veriyle ilgili ilk yaklaşım anlatılıyor, altyazı bozuk ve o anın karesi yok. -->

### 12.1 Eksik değerleri sabitlerle otomatik doldurma

Slayta göre ikinci yaklaşım, eksik değerlerin bazı sabitlerle biçimsel, çoğu zaman otomatik olarak doldurulmasıdır (ekrandan, 02:20:00):

- **Bütün eksik değerleri tek bir global sabitle doldurmak.** Global sabitin seçimi büyük ölçüde uygulamaya bağlıdır. Hoca bunun basit ama iyi olmayan bir çözüm olduğunu söyledi.
- **Eksik değeri öz niteliğin ortalamasıyla doldurmak.** Öz niteliğin ortalaması hesaplanır ve eksik yerlere konur. Bir öncekinden daha iyi bir çözümdür.
- **Eksik değeri, verilen sınıf için öz niteliğin ortalamasıyla doldurmak.** Sınıf etiketli bir veri setimiz, yani bir eğitim setimiz varsa her sınıf için ayrı ortalama hesaplanır ve eksik değer o örneğin sınıfının ortalamasıyla doldurulur. Slayta göre bu yalnız örneklerin önceden sınıflandırıldığı sınıflandırma problemlerinde mümkündür.

Hoca, slaytta yazmayan ek bir adım olarak, işin başında eksik veri miktarının ölçülmesinden söz etti. <!-- BELİRSİZ: 02:20 civarında anlatılan ek adımın tam içeriği altyazıda bozuk; aşağıdaki tablo örneği bu ölçümü gösteriyor. -->

### 12.2 Eksik veri tablosu örneği

Slayttaki "Example of Missing Data" tablosu şöyledir (ekrandan, 02:25:00); boş hücreler eksik değerdir:

| Case ID | $V_1$ | $V_2$ | $V_3$ | $V_4$ | $V_5$ | Eksik sayısı | Eksik % |
|---|---|---|---|---|---|---|---|
| 1 | 1.3 | 9.9 | 6.7 | 3.0 | 2.6 | 0 | 0 |
| 2 | 4.1 | 5.7 | | | 2.9 | 2 | 40 |
| 3 | | 9.9 | | 3.0 | | 3 | 60 |
| 4 | .9 | 8.6 | | 2.1 | 1.8 | 1 | 20 |
| 5 | .4 | 8.3 | | 1.2 | 1.7 | 1 | 20 |
| 6 | 1.5 | 6.7 | 4.8 | | 2.5 | 1 | 20 |
| 7 | .2 | 8.8 | 4.5 | 3.0 | 2.4 | 0 | 0 |
| 8 | 2.1 | 8.0 | 3.0 | 3.8 | 1.4 | 0 | 0 |
| 9 | 1.8 | 7.6 | | 3.2 | 2.5 | 1 | 20 |
| 10 | 4.5 | 8.0 | | 3.3 | 2.2 | 1 | 20 |
| 11 | 2.5 | 9.2 | | 3.3 | 3.9 | 1 | 20 |
| 12 | 4.5 | 6.4 | 5.3 | 3.0 | 2.5 | 0 | 0 |
| 13 | | | | | 2.7 | 4 | 80 |
| 14 | 2.8 | 6.1 | 6.4 | | 3.8 | 1 | 20 |
| 15 | 3.7 | | | 3.0 | | 3 | 60 |
| 16 | 1.6 | 6.4 | 5.0 | | 2.1 | 1 | 20 |
| 17 | .5 | 9.2 | | 3.3 | 2.8 | 1 | 20 |
| 18 | 2.8 | 5.2 | 5.0 | | 2.7 | 1 | 20 |
| 19 | 2.2 | 6.7 | | 2.6 | 2.9 | 1 | 20 |
| 20 | 1.8 | 9.0 | 5.0 | 2.2 | 3.0 | 0 | 0 |
| Eksik sayısı | 2 | 2 | 11 | 6 | 2 | Toplam: 23 | |
| Eksik % | 10 | 10 | 55 | 30 | 10 | Toplam: %23 | |

> **Ders sonrası not:** Slayttaki tabloda 12. örneğin eksik yüzdesi "9" gibi okunuyor; eksik sayısı 0 olduğu için doğrusu 0'dır.

Tablo eksik veriyi iki yönden değerlendirir:

- **Örnek bazında (missing data by case):** Birinci örnekte beş değerin hepsi var, eksik sayısı 0, yüzde 0. İkinci örnekte iki değer eksik; beş değerin ikisi eksik olduğu için %40.
- **Değişken bazında (missing data by variable):** Birinci öz nitelikte 20 değerden 2'si eksik, yani %10. $V_3$'te 11 değer (%55), $V_4$'te 6 değer (%30) eksiktir. Toplamda 100 hücreden 23'ü eksiktir.

Hoca bu tablo üzerinden hangi öz niteliğin ya da örneğin silinebileceğini sordu. Bir öz niteliği veri setinden silmek zor bir karardır, ama imkân varsa $V_3$ silinebilir; değerlerinin yarıdan fazlası eksiktir. Hoca gerçek hayattan bir örnek verdi: 200'den fazla öz nitelikli bir müşteri veri setinde "eğitim düzeyi" alanı zorunlu olmadığı için müşterilerin büyük kısmı doldurmamış ve alanın yaklaşık %70'i boş kalmıştı.

Örnekleri silmek de mümkündür: Çok boş hücresi olan örnekler veri setinden çıkarılabilir. 13. örnekte değerlerin %80'i, 15. örnekte %60'ı eksiktir; bu örnekler silinebilir. Kaynaklarda satırlar için "sample" yerine "case" ya da "tuple" da kullanılır. <!-- BELİRSİZ: 02:34 civarında slaytın "practical considerations" kısmında $V_3$ ile birlikte 3., 13. ve 15. örneklerin çıkarıldığı ve kalan eksik veri oranının bir yüzde olarak (altyazıda "7.4%") verildiği anlaşılıyor; slayt karesi yok. -->

### 12.3 18. örneğin eksik $V_4$ değeri

Öz nitelik ve örnek eliminasyonundan sonra kalan boşluklar için doldurma çözümleri gerekir. Hoca 18. örneğin $V_4$ değerinin eksik olduğunu gösterip nasıl doldurulacağını sordu. Bir öğrencinin aynı satırdaki $V_1$, $V_2$ gibi değerlerin ortalamasını kullanma önerisini hoca doğru bulmadı. Doğru cevap: $V_4$ sütunundaki diğer örneklerin değerlerinin ortalaması dikey olarak hesaplanır ve eksik hücreye konur.

Sonra hoca veri setine bir bilgi ekledi: ilk 10 örnek "sağlıklı" (healthy), 11–20 arası örnekler "sağlıksız" (non-healthy) sınıfında olsun. Artık veri sınıf etiketlidir. Bu durumda 18. örnek sağlıksız sınıfta olduğu için, eksik değer 11–20 arası örneklerin $V_4$ değerlerinin ortalamasıyla, yani sınıf içi ortalamayla doldurulur.

## 13. Örnek Sorular

**Soru 1** (derste sözlü, 00:40:12): Ondalık ölçeklemeyi neden kullanmak istemeyiz?

> **Çözüm:** Değerler $[-1,1]$ aralığının yalnız küçük bir bölümüne sıkışır; örnekte yalnız $-0.834$ ile $0.455$ arası kullanılır. Tek bir aykırı değer (örneğin 1050) böleni 10000'e çıkarır ve değerler $-0.0834$ ile $0.0455$ arasına iner. Ayrıca yöntem dağılımı değiştirmez ve aykırı değerleri ortadan kaldırmaz.

**Soru 2** (ekrandan, 01:15:00): $X = \{3, 1, 0, 2, 7, 6, 4, -2, 10, 12\}$ veri setini normalize edin ve $v=0$, $v=6$ için yeni değerleri bulun: (a) $[0,1]$ aralığında min-max, (b) $[-1,1]$ aralığında min-max, (c) standart sapma normalizasyonu.

> **Çözüm:** (a) $v' = (v+2)/14$; $0 \to 1/7 \approx 0.143$, $6 \to 4/7 \approx 0.571$. (b) $y = (x-5)/7$; $0 \to -5/7$, $6 \to 1/7$ (ekrandan, 01:30:00). (c) Ortalama $4.3$, standart sapma $\approx 4.448$; $0 \to \approx -0.967$, $6 \to \approx 0.382$ (c şıkkının sonuçları derste söylenmedi, python ile hesaplandı).

**Soru 3** (derste sözlü, 01:19:25): $(-2,-1)$ ve $(12,1)$ noktalarından geçen doğrunun denklemini yazın.

> **Çözüm:** $\dfrac{x-x_1}{x_1-x_2} = \dfrac{y-y_1}{y_1-y_2}$ formülünden $y = (x-5)/7$ (ekrandan, 01:25:00).

**Soru 4** (derste sözlü, 01:29:19): Standart sapma nasıl hesaplanır?

> **Çözüm:** Her değerden ortalama çıkarılır, farkların kareleri toplanır, örneklem için $n-1$'e bölünerek varyans bulunur, karekökü standart sapmadır.

**Soru 5** (derste sözlü, 01:45:45): Kovalama örneğinde ortalamayla yumuşatmanın ortalama mutlak hatası nasıl hesaplanır?

> **Çözüm (derste verilmedi):** Hoca yöntemi anlattı (mutlak farkları topla, eleman sayısına böl) ama sayıyı vermedi. Slayttaki yuvarlanmış ortalamalarla (9, 23, 29) kova başına mutlak fark toplamları 12, 7 ve 9'dur; $\text{MAE} = 28/12 \approx 2.33$. Gerçek ortalamalarla (9, 22.75, 29.25) toplamlar 12, 7 ve 9.5, $\text{MAE} = 28.5/12 = 2.375$ olur (python ile hesaplandı).

**Soru 6** (derste sözlü, 01:48:40): Sınırlarla yumuşatmada birinci kovadaki 8 hangi sınır değerine taşınır?

> **Çözüm:** Sol sınıra (4) uzaklığı 4, sağ sınıra (15) uzaklığı 7 olduğu için en yakın sınır olan 4'e taşınır. Aynı şekilde 9 da 4'e taşınır (uzaklıklar 5 ve 6).

**Soru 7** (ekrandan, 02:25:00): Eksik veri tablosundaki veri setinde kaç örnek ve kaç öz nitelik vardır, veri sınıf etiketli midir?

> **Çözüm:** 20 örnek, 5 öz nitelik ($V_1$–$V_5$) vardır; sınıf etiketi yoktur, bütün öz nitelikler sayısaldır.

**Soru 8** (derste sözlü, 02:25:28): Bu tabloda hangi öz nitelik ya da örnekler silinebilir?

> **Çözüm:** Değerlerinin %55'i eksik olan $V_3$ öz niteliği ile değerlerinin %80'i ve %60'ı eksik olan 13. ve 15. örnekler.

**Soru 9** (derste sözlü, 02:29:31): 18. örneğin eksik $V_4$ değeri nasıl doldurulur? İlk 10 örnek sağlıklı, 11–20 sağlıksız sınıfındaysa ne değişir?

> **Çözüm:** Sınıf etiketi yoksa $V_4$ sütununun ortalamasıyla; sınıf etiketi varsa 11–20 arası örneklerin $V_4$ ortalamasıyla doldurulur. Sayısal değer derste hesaplanmadı (derste verilmedi): tablodaki 14 dolu $V_4$ değerinin ortalaması $40/14 \approx 2.857$; 11–20 arasındaki 6 dolu değerin (3.3, 3.0, 3.0, 3.3, 2.6, 2.2) ortalaması $17.4/6 = 2.9$'dur (python ile hesaplandı).

## Dersin Toparlaması

Bu derste veri ön işlemenin ilk adımları görüldü. Önce verinin satır-örnek, sütun-öz nitelik yapısı ve veri türleri ele alındı: sayısal veride sıra ve uzaklık ilişkisi, kategorik veride yalnız eşitlik ilişkisi vardır; ayrık değişkenler nominal ya da ordinal ölçekle ölçülür. Ham verinin eksik, bozuk ve yanlış kaydedilmiş değerler içermesinin olağan olduğu, hiç sorun göstermeyen ham verinin ise şüphe uyandırması gerektiği vurgulandı.

Dönüşüm adımlarında, uzaklık temelli yöntemler için öz niteliklerin aynı aralığa getirilmesi gerektiği gösterildi ve üç normalizasyon yöntemi karşılaştırıldı: ondalık ölçekleme aralığı verimsiz kullanır, min-max iki noktadan geçen bir doğru denklemidir, z-score ise dağılımı orijine kaydırıp standart sapma birimine çevirdiği için en iyi sonucu verir. Ardından kovalama ile veri yumuşatma, fark ve oranlarla öz nitelik çıkarımı ve eksik değerlerin silinmesi ya da ortalama veya sınıf içi ortalama ile doldurulması işlendi. Bir sonraki derste zamana bağlı veri ve aykırı değer analizi ile veri ön işleme konusuna devam edilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
