# Ders 3 Genişletilmiş Notu: Makine Öğrenmesine Giriş: Problem Türleri ve Uygulamalar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Makine Öğrenmesi Nedir?
- 2. Sınıflandırma
- 3. Regresyon
- 4. Kümeleme
- 5. Pekiştirmeli Öğrenme ve Birliktelik Kuralları
- 6. Uygulama: Dolar Kuru Tahmini
- 7. Uygulama: El Yazısı ve Kitap Yazısı Tanıma, Sınıf İçi ve Sınıflar Arası Fark
- 8. Diğer Uygulamalar
- 9. Spam Filtreleri ve Hataların Asimetrisi
- 10. Güvenlik Kameraları, Sürücüsüz Araçlar ve Beyin Aktiviteleri
- 11. Boyut, Örnek Sayısı ve Verilerin Sayısallaştırılması
- 12. Örnek Sınıflandırma Uygulaması: Eğitim ve Test Kümesi
- Örnek Sorular

## 1. Makine Öğrenmesi Nedir?

Makine öğrenmesi konusu üç bölümde işlenecektir. Bu derste ilk bölüm, yani makine öğrenmesinin tanımı, türleri ve günlük hayattaki uygulamaları ele alınır.

Slayttaki tanım şöyledir (ekrandan, 00:10:00): "Çok büyük miktardaki verilerin elle işlenmesi, analizinin yapılması mümkün değildir. Bu tür problemlere çözüm bulmak amacıyla makine öğrenmesi metotları geliştirilmiştir. Bu metotlar **geçmişteki verileri kullanarak** veriye en uygun **modeli** bulmaya çalışırlar. Yeni gelen verileri de bu modele göre analiz edip sonuç üretirler."

Hoca bu süreçte tasarımcının rolünü vurgular. Tasarımcı algoritmaya belirli bir **model ailesi** kullanmasını söyler; model ailesi kabaca bir algoritma demektir. Sonra veriler verilir. Algoritma bu aile içinde verilere en uygun modeli, yani modelin **parametrelerini** bulur. Bu, verilerin modellenmesi işlemidir. Yeni gelen veriler de bulunan modelle analiz edilip sonuç üretilir.

Farklı uygulamaların analizden beklentileri farklıdır. Makine öğrenmesi metotları bu beklentilere göre sınıflandırılabilir. Derste beş tür ele alınır: sınıflandırma, regresyon, kümeleme, pekiştirmeli öğrenme ve birliktelik kurallarının keşfi.

## 2. Sınıflandırma

### 2.1 Problem tanımı

Slaytta iki boyutlu bir düzlemde mavi ve siyah noktalar ile soru işaretli kırmızı bir nokta vardır (ekrandan, 00:15:00). Mavi ve siyah noktaların hem koordinatları hem sınıfları bilinir; bunlar geçmiş verilerdir. Kırmızı nokta yeni gelen veridir: koordinatları ($x_1$ ve $x_2$) bilinir ama sınıfı bilinmez. Amaç bu sınıfı bulmaktır.

Slayttaki tablo beş örneği gösterir (ekrandan, 00:15:00):

| x1 | x2 | x3 | x4 | x5 | Sınıf |
|---|---|---|---|---|---|
| 1.2 | 3.4 | 2.3 | 6.7 | 7.8 | A |
| 1 | 2 | 2 | 4 | 5 | A |
| 9 | 8 | 6 | 5 | 3 | B |
| 6 | 7 | 8 | 9 | 1 | B |
| 8 | 8 | 9 | 9 | 9 | B |

Hoca önce $x_3$, $x_4$, $x_5$ sütunlarının yok sayılmasını ister. Örneğin birinci örneğin $x_1$ özelliği 1.2, $x_2$ özelliği 3.4 ve sınıfı A'dır.

### 2.2 Banka kredisi örneği

Bir bankanın geçmişte kredi verdiği müşteriler olsun. Bunların bir kısmı krediyi ödemiş, bir kısmı ödeyememiştir. Grafikte maviler ödeyenler, siyahlar ödeyemeyenler olabilir. $x_1$ kişinin maaşı, $x_2$ aynı işte kaç yıldır çalıştığı olabilir. Gerçekte $x_3$, $x_4$, $x_5$ gibi çok daha fazla özellik kullanılabilir; burada basitlik için iki boyut alınır.

Kapıdan yeni bir müşteri gelir ve kredi ister. Bir form doldurur, maaşını ve kaç yıldır aynı işte olduğunu yazar. Bu kişi kırmızı noktadır. Soru şudur: bu kişi krediyi ödeme ihtimali olanlardan mı, ödememe ihtimali olanlardan mı?

### 2.3 Model seçimi ve çözümün tek olmaması

Çok basit bir model olarak iki sınıfı ayıran bir doğru seçilebilir. Bu bir **lineer sınıflandırmadır**. "Veriler bir doğruyla ayrılsın" demek aslında bir algoritma seçmektir. Lineer regresyon, SVM ya da perseptron gibi yöntemlerin hepsi temelde bir doğru bulmaya çalışır.

Hoca slayta önce bir doğru çizer: doğrunun üstünde kalanlar krediyi ödeyebilenler, altında kalanlar ödeyemeyenlerdir. Kırmızı nokta üstte kaldığı için bu kişiye kredi verilebilir. Sonra farklı bir yerden geçen ikinci bir doğru çizer. Bu doğru da mavileri ve siyahları tamamen ayırır, ama kırmızı nokta bu kez öbür tarafta kalır ve kredi vermemek daha makul görünür.

**Soru:** Bu iki sınıfı çok iyi ayıran kaç doğru çizilebilir? **Cevap (bir öğrenci):** Sonsuz tane.

Dolayısıyla makine öğrenmesi problemlerinin büyük kısmında **çözüm tek değildir**. Algoritmalar tek bir model verebilir ya da her çalıştırıldıklarında farklı bir model verebilir. Hangi modelin en iyi olduğu konusunda geniş bir literatür vardır. Örneğin SVM sınıflar arasında belirli bir doğruyu bulurken perseptron önce başka bir doğruyu bulabilir.

> **Ek bilgi (derste anlatılmadı):** SVM, iki sınıfa en yakın noktalara olan uzaklığı (marjini) en büyük yapan doğruyu arar. Perseptron ise hatasız ayıran ilk doğruda durabilir. Bu yüzden aynı veride farklı doğrular bulmaları beklenir.

Model bir doğru olmak zorunda da değildir. Hoca eksenlere paralel iki çizgi çizer (ekrandan, 00:20:00): iki çizginin de belirli tarafında kalan bölge mavi sınıf, geri kalan her yer siyah sınıftır. Bu farklı bir model ailesidir ve bir **karar ağacının** ifade ettiği bölgeye benzer. Bu modele göre de kırmızı nokta mavi sınıfa girer. Daha sonra sınıfları bir parabolle ayırmak da gösterilir (ekrandan, 00:45:00). Hangi modelin doğru olduğu, bulunan modellerin karşılaştırılması ayrı bir konudur.

İşlemler iki boyutla sınırlı değildir. İki boyut yalnız görselleştirmek içindir; problem çok daha yüksek boyutlu uzaylarda da aynı şekilde çözülür.

### 2.4 Girdi tipi ve çıktı tipi

Hoca tablodaki $x_2$ sütununu "Evet/Hayır" değerleriyle, sınıf sütununu da "bir" ve "2" etiketleriyle değiştirir (ekrandan, 00:25:00):

| x1 | X2 | x3 | x4 | x5 | Sınıf |
|---|---|---|---|---|---|
| 1.2 | Evet | 2.3 | 6.7 | 7.8 | "bir" |
| 1 | Hayır | 2 | 4 | 5 | "bir" |
| 9 | Evet | 6 | 5 | 3 | "2" |
| 6 | Evet | 8 | 9 | 1 | "2" |
| 8 | Hayır | 9 | 9 | 9 | "2" |

Girdilerin sayı olması gerekmez, kategorik de olabilir. Ama bu algoritma seçimini etkiler. **Karar ağaçları** hem kategorik hem sayısal değişkenlerle çalışabilir. **SVM** ise mutlaka sayısal verilerle çalışır. Kategorik bir girdi sayıya çevrilebilir. Evet/hayır gibi iki değerli bir özellik 0 ve 1 ya da 1 ve -1 yapılabilir. Beş kategorili bir özelliği 1, 2, 3, 4, 5 diye numaralandırmak pek makul değildir. Bunun yerine beş ayrı boyut tanımlanıp **one-hot encoding** ile beş özellik çıkarılabilir.

Bir problemi sınıflandırma yapan şey girdilerin tipi değil, **çıktının tipidir**. Sınıflandırmada çıktı bir **kategoridir**: çıktılar arasında büyüklük-küçüklük ilişkisi yoktur. Örneğin bir resimdeki harfin hangi harf olduğunu bulmaya çalışırken çıkışlar kategoriktir; "büyük A küçük A'dan büyüktür" gibi sayısal bir ilişki yoktur. Çıktılar arasında böyle bir ilişki varsa, yani çıktılar sayısal olarak karşılaştırılabiliyorsa problem sınıflandırma değil **regresyondur**.

Hoca bunu sınıf etiketleriyle gösterir. Sınıflar "1" ve "2" diye yazılmış olabilir. 1 ve 2 sayı olarak yorumlanıp aralarında büyüklük ilişkisi kurulursa problem bir regresyon problemine dönüşür. Ama örneklerin her biri bir şekil ve sınıfları "1" ve "2" ise, bu etiketler yalnız isimdir. "1" yerine "bir" yazmak hiçbir şeyi değiştirmez; problem yine sınıflandırmadır.

## 3. Regresyon

Slayttaki regresyon örneğinde her yıldız bir arabadır. Girdi arabanın motor gücü, çıktı ulaştığı maksimum hızdır. Bu kez tek bir girdi vardır. Çıktı sayısaldır: 210, 230'dan küçük, 280, 230'dan büyüktür. Bu yüzden bu bir regresyon problemidir. <!-- BELİRSİZ: regresyon slaytı okunur bir karede yok; sayılar altyazıdan alındı. -->

Amaç verilere en iyi uyan modeli bulmaktır. Hoca lineer bir model yazar:

$$\text{maksimum hız} = w_1 \cdot \text{motor gücü} + w_0$$

Motor gücü bir katsayıyla çarpılır, üstüne $w_0$ eklenir. $w_0$ doğruyu sıfırdan geçmeye zorlamamak içindir. Bu grafikte bir doğrudur; $w_0$ ve $w_1$ değerleri doğrunun nereden geçeceğini belirler. Temel fikir girdi ile çıktı arasında lineer bir eşleme kurmaktır.

İkinci bir girdi, örneğin motor torku eklenirse model $w_1 \cdot \text{motor gücü} + w_2 \cdot \text{motor torku} + w_0$ olur. Bu hâlâ lineer bir modeldir. İki girdi ve bir çıktı olunca uzay üç boyutlu olur ve model bir doğru değil, bir **düzlem** tanımlar.

### 3.1 Hata

Sınıflandırma örneğinde seçilen doğru verileri mükemmel ayırıyordu. Regresyon örneğinde ise hiçbir lineer model bütün noktaların üstünden geçmez. Her örnek için noktanın gerçek değeri ile modelin değeri arasındaki dikey uzaklık o örnekteki **hatadır**. Bazı örneklerde hata büyük, bazılarında küçüktür.

Bu "sınıflandırmada mükemmel ayrım olur, regresyonda olmaz" demek değildir. Mavilerden biri siyahların ortasında olsaydı, hiçbir lineer model ya da küçük bir karar ağacı iki sınıfı mükemmel ayıramazdı. Tersine, girdi-çıktı noktaları bir doğru üzerinde dizilmişse lineer regresyonla mükemmel sonuç alınabilir.

Model lineer olmak zorunda da değildir. Regresyonda bir eğri uydurulabilir, sınıflandırmada da sınıfları bir parabolle ayırmak mümkündür.

> **Hocanın vurgusu:** Sınıflandırma ve regresyonun temel farkı çıktıların türüdür. Çıktılar kategorikse, aralarında büyüklük-küçüklük ilişkisi yoksa problem sınıflandırmadır. "Yarın dolar kaç olacak?" ya da "bu resimdeki kişi kaç yaşında?" gibi sayısal bir şey tahmin ediliyorsa problem regresyondur.

## 4. Kümeleme

### 4.1 Tanım

Kümelemenin önceki iki türden temel farkı şudur: elimizde girdiler vardır ama **çıktı yoktur**. Bütün $x_1, x_2, x_3$ değerleri bilinir ama karşılarında bir çıktı yoktur. Bunun bir avantajı vardır: bu tür veriler daha kolay ve daha büyük hacimde toplanabilir. Sınıflandırma ya da regresyon verisinde ise her girdinin çıktısını birinin belirlemesi gerekir. Örneğin kişiye kredi verilip verilmeyeceğine karar verilir ya da her araba sürülüp maksimum hızı ölçülür ve tabloya yazılır.

Kümeleme (clustering, öbekleme, gruplandırma) probleminde amaç verileri kümelere ayırmaktır: "elimdeki verileri grupla" ya da "bunları beş kümeye ayır". Küme sayısı verilebilir ya da verilmeyebilir.

### 4.2 Renk indirgeme örneği

Slaytta solda 256 farklı renk içeren bir resim, sağda aynı resmin 16 renge indirilmiş hali vardır (ekrandan, 00:35:00). Slayttaki sorular "256 rengi 16 renge nasıl indiririz?" ve "n bit = 2^n farklı değer" ifadeleridir.

Resimde örneğin 10 bin piksel ve bu piksellerde 256 farklı renk vardır. Her piksel bir RGB üçlüsüdür; bazı piksellerin değerleri aynıdır. Veride 256 farklı üçlü vardır ve amaç bunları 16 farklı üçlüye indirmektir. Bu bir çıktı üretmek demektir: "şu örnek birinci kümeden, şu örnek ikinci kümeden". Burada da kümeler arasında büyüklük-küçüklük ilişkisi yoktur. "A kümesi, B kümesi" adlarını kullanıcı vermez, kümeleri ayırt etmek için algoritma koyar. Sonuç olarak örneğin 1., 4., 32., 45., 128., 768. pikseller birinci kümenin elemanları olur.

Sonuçta birçok farklı kırmızı tonu daha az sayıda kırmızı tonuna, birçok yeşil tonu daha az yeşil tonuna indirgenir.

- **Avantaj:** $n$ bit ile $2^n$ farklı değer tutulabilir. 256 renk için piksel başına $\log_2 256 = 8$ bit gerekirken 16 renk için $\log_2 16 = 4$ bit yeter. Resmi bellekte tutmak için yarı yarıya daha az yer kullanılır.
- **Dezavantaj:** Görsel olarak daha kötü bir resim elde edilir.

### 4.3 GSM operatörü örneği

Bir GSM operatörünün örneğin 35 milyon abonesi olsun ve kampanya düzenlemek istesin. Her kişiye ayrı kampanya düzenlemek, duyurmak ve yönetmek çok zordur. Bu yüzden müşteriler örneğin 20 gruba ayrılır ve her grup için bir kampanya oluşturulur. Gruplara içlerindeki örneklere bakılarak isim de verilebilir.

**Soru:** Bir GSM operatörü müşterilerini kümelemek için hangi özellikleri ($x_1, x_2, \dots$) kullanabilir? **Cevaplar (öğrencilerden):** Kullanım alışkanlıkları. Hoca "kullanım alışkanlığı" diye bir sütun yazılamayacağını, bunun sayısal bir özelliğe çevrilmesi gerektiğini söyler. Önerilen somut özellikler şunlardır (slaytta da listelenir, ekrandan, 00:45:00):

- aylık indirilen veri miktarı (GB/MB)
- yaş
- cinsiyet
- kullanılan telefonun markası
- ödenen para, yani fatura tutarı
- uygulama kullanımı (ne kadar WhatsApp, ne kadar YouTube kullanıldığı)

Bu özelliklerin hepsi aynı ölçüde etkili olmayacaktır; listede olmayan başka özellikler de tasarlanabilir. Bu veriler zaten operatörün elindedir. Kümeleme yapıldıktan sonra belirli kümelere belirli kampanyalar önerilebilir.

Kümeleme algoritmaları arasında küme sayısını isteyenler de, küme sayısı yerine başka bir parametre isteyenler de vardır.

## 5. Pekiştirmeli Öğrenme ve Birliktelik Kuralları

### 5.1 Pekiştirmeli öğrenme

Pekiştirmeli öğrenme sınıflandırmaya ya da regresyona benzer: bir girdi ve bir çıktı vardır. Fark şudur: modele çıkışın ne olması gerektiği söylenmez. Sınıflandırmada "şu girdiye karşılık şunu üret" denir. Pekiştirmeli öğrenmede model bir şey yapar, örneğin "bu A sınıfındandır" der, ve kendisine yalnızca "doğru bildin" ya da "yanlış söyledin" denir. "Yanlış söyledin, doğrusu şudur" bilgisi verilmez. Geri bildirim ikilidir. Bu yöntem genelde oyunlarda kullanılır ve sonraki makine öğrenmesi derslerinde ayrıca işlenecektir.

### 5.2 Birliktelik kurallarının keşfi (sepet analizi)

Sepet analizi, adından da anlaşılacağı gibi, bir alışveriş sepetindeki ürünlerin analizidir. Amaç hangi ürünlerin birlikte satıldığını, yani **birliktelik kurallarını** bulmaktır: bir sepette bir ürün varsa başka hangi ürünlerin bulunma ihtimali yüksektir? Girdi sepet içerikleridir; elde milyonlarca sepet vardır. Çıktı ise "şu ürünle şu ürünün birlikte bulunma ihtimali şudur" gibi kurallar ve hipotezlerdir. Burada bir sınıflandırma ya da regresyon işlemi yoktur.

Böylece derste beş tür görülmüş olur: sınıflandırma, regresyon, kümeleme, pekiştirmeli öğrenme ve birliktelik kurallarının keşfi. Üretici modeller gibi son dönemde ortaya çıkan başka türler de vardır, ama bu dersin kapsamında değildir.

## 6. Uygulama: Dolar Kuru Tahmini

Aradan sonra uygulamalara geçilir ve her uygulamanın hangi türe girdiği tartışılır.

İlk uygulama dolar kurunu yalnız geçmiş kur verilerine bakarak tahmin etmektir. Gerçekte kur başka birçok şeye bağlıdır; bu yalnız bir örnek modeldir. Aynı yaklaşım hava sıcaklığı, hisse senedi ya da kripto para değeri gibi başka dizi tahminlerinde de kullanılabilir.

Uzunluğu 3 olan bir **pencere** tanımlanır: bir günün kuru, ondan önceki üç günün kuruna bakarak tahmin edilir. Slayttaki dizi ve ondan üretilen tablo şöyledir (ekrandan, 01:05:00):

Dizi: 6.1, 6.2, 6.3, 6.3, 6.3, 6.2, 6.4, 6.1, ...

| D-3 | D-2 | D-1 | D |
|---|---|---|---|
| 6.1 | 6.2 | 6.3 | 6.3 |
| 6.2 | 6.3 | 6.3 | 6.3 |
| 6.3 | 6.3 | 6.3 | 6.2 |
| 6.3 | 6.3 | 6.2 | 6.4 |
| 6.3 | 6.2 | 6.4 | 6.1 |

Pencere dizi üzerinde birer adım kaydırılarak her satır elde edilir: ilk üç değer girdi, dördüncü değer çıktıdır (tablonun diziyle tutarlılığı python ile kontrol edildi). D-3, D-2, D-1 girdiler, D çıktıdır. Çıktılar arasında büyüklük-küçüklük ilişkisi olduğu için problem bir **regresyon** problemidir. Girdi burada üç boyutludur; daha eski günler ya da başka özellikler eklenerek genişletilebilir.

### 6.1 Başarının ölçülmesi

Modelin yarını, iki gün sonrasını, üç gün sonrasını ne kadar iyi tahmin ettiği ölçülebilir. Bunun için örneğin model **ocak** ayı verisiyle eğitilir ve **şubat** ayı verisiyle test edilir. Ocak verisinden oluşan tabloyla modelin parametreleri bulunur. Sonra şubat verisinde her satırın girdileri modele verilir. Model örneğin 6.2 tahmin ettiğinde gerçek değer 6.3 ise, aradaki fark modelin hatasıdır. Şubat verisinin tamamı üzerindeki hatalar ortalama gibi bir yöntemle birleştirilerek başarı ölçülür. Ocakta birden fazla model eğitilip şubatta test edilirse hangisinin daha iyi olduğu da karşılaştırılabilir.

Tersini yapmak, yani şubatla eğitip ocakla test etmek, gerçekçi olmaz. Çünkü genelde geleceği tahmin etmeye çalışırız.

Ocak verisinin rastgele bir kısmıyla eğitip kalanıyla test etmek de sorunludur. Dizi verisinde eğitim ve test kümeleri birbirine karışır ve sonuçlar gerçekte olacağından daha **iyimser** çıkar. Geçmiş veriyle eğitip daha sonraki bir zamanın verisiyle test etmek gerçeğe daha yakın sonuç verir.

## 7. Uygulama: El Yazısı ve Kitap Yazısı Tanıma, Sınıf İçi ve Sınıflar Arası Fark

### 7.1 HCR ve OCR

Slaytta "El yazısı / Kitap Yazısı Tanıma, HCR / OCR" başlığı altında solda el yazısıyla yazılmış bir mektup, sağda basılı bir makale sayfası vardır (ekrandan, 01:10:00). Slayttaki işlem: "Şekillerin hangi harf olduğunu tahmin etme." Amaç resmi metne çevirmek, her karakteri ve kelimeyi bulmaktır. El yazısı tanımaya Handwritten Character Recognition (HCR), basılı yazı tanımaya Optical Character Recognition (OCR) denir.

**Soru:** Hangisi daha kolay bir problemdir ve neden? **Cevap (bir öğrenci):** Sağdaki basılı yazı, çünkü harfler standarttır; el yazısında harfler değişebilir.

Hoca cevabı açar. Farklı kişilerin yazdığı küçük "a" harfleri birbirinden farklıdır. Aynı kişinin yazdıkları bile harfin kelimenin başında, ortasında ya da sonunda olmasına göre değişir. Basılı yazıda ise az sayıda font kitapların çok büyük kısmını kapsar. Yani basılı yazıda bir harf sınıfının **varyansı** düşük, el yazısında yüksektir.

### 7.2 Sınıf içi ve sınıflar arası fark

Hoca varyansın etkisini bir çizimle anlatır (ekrandan, 01:15:00). İki boyutlu bir düzlemde yeşil sınıfın örnekleri bir yeşil dairenin, mavi sınıfın örnekleri bir mavi dairenin içinden gelsin.

1. Daireler birbirinden uzaksa iki sınıf tek bir doğruyla ayrılabilir; problem kolaydır.
2. Dağılımı değiştirmeden daireler birbirine yaklaştırılırsa problem zorlaşır. **Soru:** Problem şimdi daha mı zor? **Cevap (bir öğrenci):** Evet, çünkü kesişim var.
3. Daireler birbirinden daha da uzaklaştırılırsa problem daha da kolaylaşır.
4. Merkezler arasındaki uzaklık aynı kalıp daireler küçültülürse, yani her sınıfın örnekleri daha dar bir alana toplanırsa problem yine kolaylaşır. **Soru:** Alttaki problem daha mı kolay, daha mı zor? **Cevap (bir öğrenci):** Daha kolay.

Buna göre istenen durum şudur:

- **Sınıflar arası fark büyük olmalıdır.** Bu, sınıf ortalamaları (orta noktaları) arasındaki farktır.
- **Sınıf içi fark küçük olmalıdır.** Buna varyasyon ya da varyans denir.

En iyi durum, sınıf merkezlerinin uzak ve sınıfların dar olduğu durumdur. El yazısında küçük "a" harfleri çok geniş bir alana dağılmıştır; aynı sınıfın örnekleri birbirine o kadar benzemez. Basılı yazıda ise aynı sınıfın örnekleri birbirine çok benzer ve dar bir alanda toplanır. Bu yüzden diğer sınıflardan ayırt etmek çok daha kolaydır.

## 8. Diğer Uygulamalar

### 8.1 Kredi talepleri ve e-ticaret

Kredi taleplerinin değerlendirilmesi, sınıflandırma bölümünde anlatılan banka örneğidir. E-ticarette kitaplar birlikte satılma durumlarına, yazarlarına ya da konularına göre kümelenebilir. Bir müşteri bir kitap aldığında aynı kümedeki diğer kitaplar ona önerilebilir.

### 8.2 Gen mikrodizilimleri

Elimizde örneğin 100 kişinin DNA dizilimleri olsun; bir kısmı hasta, bir kısmı sağlam. Bu dizilimleri analiz ederek kişinin hasta olup olmadığı anlaşılabilir mi ya da bir tedavi önerilebilir mi?

Hoca bunu bir tabloyla gösterir (ekrandan, 01:20:00). Sütunlar $x_1, x_2, x_3, \dots, x_d$ ve sınıftır. Bir satırın özellikleri dizilimdeki bazlardır (A, A, C, C, G, A, T, ..., T), sınıfı X'tir. Diğer satırların sınıfları Y, S ve X'tir. Yani satırlar kişiler, sınıflar hastalık türleri ya da "sağlam" durumudur. $d$, yani dizilim uzunluğu on binler, yüz binler mertebesinde olabilir. Bu durumda on binlerce boyutlu bir uzayda çalışılır. Yeni bir kişinin dizilimi alınıp sınıfı tahmin edilir. Sınıflar hastalık yerine tedavi türleri (X, Y, S tedavisi) olarak tanımlanırsa aynı yöntemle tedavi önerisi de yapılabilir.

### 8.3 İris tanıma

"Bu adam kim? İçeri girsin mi?" sorusu iris tanımayla cevaplanabilir. İris, gözbebeğini çevreleyen simit şeklindeki bölgedir. Ortadaki siyah bölge boşluktur, iris ise açılıp kapanan kaslardan oluşur. Bu kasların rengi değil şekli kişiden kişiye çok farklıdır: iki kişinin iris kas şeklinin aynı olma olasılığı yaklaşık milyarda birdir. Tanıma sırasında iris bölgesi alınır, simit bir yerden kesilip açılarak dikdörtgen bir resme çevrilir ve bu resimler kişilere göre etiketlenir.

Bir kişinin havaalanında olup olmadığını iristen bulmak ise zordur. En gelişmiş ve pahalı kameralar bile irisi yeterli çözünürlükte en fazla yaklaşık 2 metreden çekebilir. Özellikle saklanmaya çalışan biri için bu yöntem işe yaramaz.

### 8.4 Yüz tanıma

"Bu adam kim? Bu adam havaalanında mı?" sorusu için yüz resimlerinden tanıma daha uygun olabilir. Burada resmin açısı, kaç yıl önce çekildiği ve kişinin kılık değiştirip değiştirmediği sistemin başarısını çok etkiler. Bir kişinin birçok resmi "A kişisi" diye, başka kişilerin resimleri "B kişisi" diye etiketlenir. Havaalanı kameralarından gelen görüntüler bu resimlerle eşleştirilmeye çalışılır.

### 8.5 Parmak izi

"Bu parmak izi kimin? Bu adamı tutuklayalım mı?" (ekrandan, 01:25:00). Parmak izi de kişiye özgüdür. Hocanın hatırladığı kadarıyla iki kişinin parmak izinin aynı olma olasılığı milyonda bir civarındadır; bu da kabul edilebilir bir hata payıdır. Parmak izi bilgisayarlardan önce de kullanılıyordu: defterlerdeki izler olay yerinden alınan izlerle gözle karşılaştırılıyordu. Bugün de doğrulama amaçlı kullanımı mümkündür. Örneğin şüpheli 10 kişinin izleri ile olay yerindeki iz karşılaştırılıp izin bu 10 kişiden birine ait olup olmadığına bakılır. Bütün nüfus içinden sahibini bulmak ise bu anlamda düşünülmemelidir.

### 8.6 Ses ve imza tanıma

"Bu ses kimin? Bu ses ne diyor?" Sesten kişi tanıyan güvenlik adımları ve konuşmayı metne çeviren sistemler (örneğin Google'ın konuşma tanıma servisi) yaygındır. Ses çeşitli dönüşümlerle (mel frekansları gibi) görüntüye benzer bir temsile çevrilir. Bu temsil üzerinde modellerle hangi harfin ya da hecenin söylendiği çıkarılır.

"Bu imza kimin? Yoksa taklit mi?" İmzanın gerçek olup olmadığını anlamada en önemli bilgilerden biri, varsa **zaman bilgisidir**. Taklitçi imzanın şeklini kopyalayabilir, ama asıl sahibi gibi aynı sırayla ve aynı yerlere aynı basıncı uygulayarak atamaz. Bunun için dokunmatik tabletlerde imza attırma uygulamaları vardı. Ama taklidi çok daha zor olan elektronik imzanın yaygınlaşmasıyla bu tür uygulamaların zamanı sona eriyor.

## 9. Spam Filtreleri ve Hataların Asimetrisi

### 9.1 Spam filtreleri

"Bu metnin konusu nedir? Bu mail spam mi?" (ekrandan, 01:35:00). Spam filtresi, e-posta kutusunun önüne konmuş bir güvenlik duvarı gibi düşünülebilir. Gelen bir postanın gerçekten ilgilendiren bir posta mı, yoksa spam mi olduğunu belirleyen bir **sınıflandırma** uygulamasıdır.

### 9.2 Hata tablosu

Hoca gerçek ve tahmini sınıfları karşılaştıran bir tablo kurar (ekrandan, 01:30:00):

| | Tahmini istenen | Tahmini istenmeyen |
|---|---|---|
| Gerçek istenen | X (doğru) | spam'e düşmüş |
| Gerçek istenmeyen | fazladan iş | X (doğru) |

Köşegendeki iki durumda sorun yoktur: istenen posta gelen kutusuna gelir, istenmeyen posta gelmez. Bunların yüksek, köşegen dışındakilerin düşük olması istenir. Ama iki hata türünün etkisi farklıdır:

- **İstenmeyen posta gelen kutusuna düşerse** yalnızca fazladan iş çıkar: kişi bakar, spam olduğunu görür ve siler.
- **İstenen posta spam'e düşerse** sorun daha büyüktür. Örneğin merakla beklenen bir sonuç postası spam'e takılabilir. Spam klasörünün belirli aralıklarla kontrol edilmesi gerekir, üstelik bir süre sonra spam klasöründeki postalar silinebilir.

Daha çarpıcı bir örnek hastalık teşhisidir:

| | Tahmini hasta | Tahmini sağlam |
|---|---|---|
| Gerçek hasta | doğru | çok kötü |
| Gerçek sağlam | kötü (daha az) | doğru |

Gerçekte hasta olan birine "sağlamsın" demek çok kötüdür. Gerçekte sağlam olan birine "hastasın" demek de kötüdür, ama daha az kötüdür.

> **Hocanın vurgusu:** Sınıflandırma problemlerinde A'ya B demek ile B'ye A demek her zaman aynı miktarda hataya sebep olmaz; hatalar simetrik olmayabilir.

Bu durum modele söylenebilir: "A'ya B demene çok kızmam, ama B'ye A dersen bu benim için çok kötü olur." Bu, **kayıp (loss) fonksiyonu** buna göre ayarlanarak yapılır ve model istenmeyen hata türünden daha çok kaçınır. Bunun bir bedeli vardır: bir hata türü çok düşürülmeye çalışılınca diğeri artabilir.

> **Ek bilgi (derste anlatılmadı):** Bu tabloya karışıklık matrisi (confusion matrix) denir. Köşegen dışı hücrelere yanlış pozitif ve yanlış negatif adı verilir. Hataların farklı maliyetlerini kayıp fonksiyonuna yansıtmaya maliyete duyarlı öğrenme denir.

### 9.3 Kararları makinelere bırakmak

Spam sorunu geçmişe göre çok daha iyi çözülmüştür; eskiden spamlerle çok daha fazla uğraşmak gerekiyordu. Spam filtreleri, günlük hayatta kararı uzun süredir makinelere bıraktığımız alanlardan biridir. Kimse postalarını tek tek ayırmaz; makinelerin yeterince iyi çalıştığını varsayıp onlara güveniriz.

Kararlar makinelere bırakıldığı anda makineleri kandırmaya çalışan sistemler de ortaya çıkar. İnsanlar karar verirken nasıl başka insanlar onları kandırmaya çalışıyorsa, makineler karar verirken de insanlar makineleri kandırmaya çalışır, bunu da yine makine kullanarak yaparlar. Slayttaki ifadeyle yeni nesil spam postalarda mesaj resimdedir, metinde ise anti-spam filtrelerinden kaçmak için gereken kelimeler vardır (ekrandan, 01:35:00). Spamciler hangi metnin filtreye takıldığına, hangisinin takılmadığına bakarak yöntemlerini iyileştirir. Yani **makine öğrenmesi metotlarını hem spamciler hem anti-spamciler kullanır**. Kararlar giderek daha çok makinelere bırakıldıkça bu durumla daha sık karşılaşılacaktır.

## 10. Güvenlik Kameraları, Sürücüsüz Araçlar ve Beyin Aktiviteleri

### 10.1 Güvenlik kamerası kayıtları

"Olağan dışı bir durum var mı? Güvenlik kamerası kayıtları" (ekrandan, 01:40:00). Kameraları izlemek insanlar için sıkıcı bir iştir ve genelde bütün kameralar gerçek zamanlı izlenmez. Bir sorun olduğunda kayıtlar geriye dönük incelenir; bu da anında müdahaleyi engeller. Bütün sokaklardaki kameraları gerçek zamanlı izlemek bir insan ordusu gerektirir. Kamera akıllı olsaydı, görüntüde bir sorun olduğunu kendisi fark edip polisi, itfaiyeyi ya da ambulansı çağırabilseydi bu çok faydalı olurdu. Aynı şey binalar ve tek başına yaşayan yaşlıların evleri için de geçerlidir: kalp krizi ya da düşüp kalkamama gibi anomalileri otomatik tespit eden sistemler büyük fayda sağlar. Burada veri tek bir resim değil, bir resim dizisi yani videodur. Bugün bir kişiyi bulmak gibi işler yapılabilmektedir, bir olayın ne olduğunu anlamak ise daha karmaşıktır.

Evde ya da arabada kamera olması mahremiyet konusunu gündeme getirir. Hocanın görüşüne göre bir **kazan-kazan** durumu varsa insanlar verilerini paylaşmaktan pek çekinmez. Örneğin sürekli konum paylaşmak garip gelebilir, ama yol tarifi ya da yakındaki hastane, sinema, restoran gibi bilgileri almak için konum verilir. Hoca, giyilebilir tıbbi sensörler yaygınlaştıkça sağlık verilerinin de benzer şekilde paylaşılacağını düşünür. Örneğin yaklaşan bir kalp krizi için önceden uyarı almak, kişinin kendisi ya da yakını için çok değerlidir.

Kamera kaydından işaret dilinin tanınması, yani videodaki hareketlerden kişinin ne anlattığının çıkarılması da bir uygulamadır.

### 10.2 Sürücüsüz araçlar: ALVINN

Kendi kendine giden araçlar bugün birçok firmanın milyarlarca dolar yatırım yaptığı bir teknolojidir. Slayttaki eski örnek ALVINN'dir (ekrandan, 01:45:00): "Otobanda saatte 70 mil hızla sürücüsüz gidebilen bir otomobil. Bütün denemeler trafiğe kapalı alanlarda gerçekleştirilmiştir." Slayttaki ağ şemasında 30x32'lik bir sensör girdisi (input retina), 4 gizli birim ve "Sharp Left", "Straight Ahead", "Sharp Right" arasında yönleri gösteren 30 çıkış birimi vardır. Slaytta 1988 tarihli bir makaleye bağlantı verilir. Hoca bu örneği, sürücüsüz araç çalışmalarının çok eskiye dayandığını göstermek için verir: yapay sinir ağıyla çalışan bu araç, dönemin bilgisayarlarının işleyebildiği çok düşük çözünürlüklü görüntülerle çalışıyordu.

> **Ek bilgi (derste anlatılmadı):** ALVINN (Autonomous Land Vehicle In a Neural Network), Carnegie Mellon Üniversitesi'nde geliştirilmiş, kamera görüntüsünden doğrudan direksiyon yönünü öğrenen erken bir yapay sinir ağı sistemidir. Slayttaki makale bağlantısı büyük olasılıkla bu sistemi tanıtan 1988 tarihli NIPS makalesine aittir.

Slayttaki sorular şunlardır: "Neden şehir içi değil? Neden otoban? Neden diğer arabalar yok? Araba birine çarparsa suçlu kim?" Hoca, insanların ve araçların bulunduğu ortamlar birbirinden ayrıldığında büyük sorun çıkmayacağını düşünür. Otobanlar yayalardan büyük ölçüde ayrılmış yerlerdir. Mahalle arasında ise daha önce benzeri görülmemiş durumların ortaya çıkma olasılığı çok daha yüksektir; bu da daha önce anlatılan varyasyon konusuyla ilgilidir. Otonom araçların birbirleriyle haberleşmesi geliştikçe başarılı sistemler kurulabilir, ama mahalle araları uzun süre sorunlu kalacaktır.

Sorumluluk sorusu da zordur. Bir insanın suçlu olması ile bir algoritmanın "suçlu" olması farklıdır; algoritma suçlanamaz. Algoritmayı tasarlayanlar suçlanırsa onlar veri kümesini hazırlayanları işaret edebilir, çünkü veri kümeleri de sonucu çok etkiler. Kararlar makinelere bırakıldığında makineler hata yapacaktır. Bu hataların nasıl değerlendirileceği hukukta önemli düzenlemeler gerektirir. Hoca adalet alanında da "hakimleri otomatik yapalım" gibi fikirlerin konuşulduğundan söz eder.

### 10.3 Beyin aktiviteleri

Slayttaki ifadeye göre insanların değişik şeyler düşünürkenki, değişik duygulara sahipkenki ve problem çözerkenki beyin aktiviteleri kaydedilir (ekrandan, 01:50:00). Kayıt, beynin hangi bölgelerinin daha çok oksijen tükettiğini ve aktifleştiğini video gibi gösterir. Matematik problemi çözerken, piyano ya da keman çalarken ya da eski bir anıyı hatırlarken beyin aktivitesi kaydedilebilir. Slayttaki soru: "Görev?"

**Soru:** Böyle büyük bir veri kümesi toplansa ne gibi uygulamalar yapılabilir? **Cevaplar (öğrencilerden):** Düşünceleri okumak. Bazı zihinsel hastalıkların tespiti; hoca bunu sorunun nerede olduğunu ve nereye müdahale etmek gerektiğini görmek olarak açar. Sohbetten gelen bir öneri de konuşamayan birinin konuşmasını sağlamaktır. Hoca rüyaları görselleştirmek ya da kaydetmek ve yalan makinesi gibi uygulamaları da ekler. Bu alandaki potansiyel çok büyüktür, ama işin kolay olmadığı da açıktır.

## 11. Boyut, Örnek Sayısı ve Verilerin Sayısallaştırılması

### 11.1 Uygulamalardaki boyut ve örnek sayıları

Veri tablosunda satır sayısı **örnek sayısını** (training examples), sütun sayısı **girdi (özellik) sayısını** gösterir. Bu sayılar uygulamaya göre çok farklıdır. Makine görmesi ve metin sınıflandırma gibi alanlarda iki sayı da yüksek olabilir. Biyoinformatikte, örneğin gen dizilimlerinde ya da nadir hastalıklarda, örnek sayısı genelde azdır ama sütun sayısı on binler, yüz binler mertebesindedir.

Girdi boyutu ile örnek sayısının orantılı olması iyidir. Az örnek ve çok boyutlu bir uzay varsa güvenilir tahmin yapmak ve güvenilir model kurmak pek mümkün olmaz. Hoca bu konuya sonraki derste değineceğini söyler.

> **Ek bilgi (derste anlatılmadı):** Bu sorun literatürde "boyutluluğun laneti" (curse of dimensionality) olarak bilinir. Boyut arttıkça uzayı yeterli yoğunlukta örneklemek için gereken veri miktarı çok hızlı büyür. Az örnekle kurulan model eğitim verisini ezberleme eğilimi gösterir.

### 11.2 Verilerin sayısallaştırılması

Resim, metin, hareket, video ve ses gibi verilerin makinelerce işlenebilmesi için sayılara dönüştürülmesi gerekir. Metinler genelde harflerin, hecelerin ve kelimelerin frekanslarına göre kodlanır. Son dönemde metinler anlamsal uzaylarda temsil edilmeye başlanmıştır; BERT gibi mimariler bunun örnekleridir. Bunların ayrıntısı bu dersin kapsamında değildir, ama projelerde kullanılabilir. Hareketli görüntünün (videonun) resimden tek farkı bir zaman indeksinin olmasıdır.

## 12. Örnek Sınıflandırma Uygulaması: Eğitim ve Test Kümesi

Örnek uygulama, bir kitap fotokopisindeki resim halindeki yazıların metne dönüştürülmesidir. Önce metindeki satırlar, sonra satırlardaki harfler bulunur (bulunduğu varsayılır). Her harfe ait onlarca örnek resimle etiketlenmiş bir veri tabanı oluşturulur.

Slayttaki örnekte bir rakam resmi 10 satır ve 6 sütundan oluşan bir ızgaraya bölünür; her hücre bir özelliktir. Böylece her rakam resmi $10 \times 6 = 60$ boyutlu bir vektör olur. Slayttaki maddeler şöyledir (ekrandan, 02:15:00):

- Tanınmak istenen harf için çeşitli fontlarla yazılmış birçok örneği temsil eden 60 boyutlu vektörler elde edilir.
- Özellik sayısı 60'tır; örnekler 60 boyutlu bir uzayda temsil edilir. Önceki sınıflandırma örneğindeki noktalar iki boyutlu uzaydaydı, buradakiler 60 boyutlu uzayda birer noktadır.
- 10 rakama ait farklı fontlarla yazılmış 10'ar resim varsa veri kümesi $10 \times 10 = 100$ örnek x 60 boyutluk bir matristir.
- Her örneğin hangi rakam olduğunu gösteren sınıf bilgisi de vardır; her satırın sonuna sınıf sütunu eklenir.
- Bu matris eğitim ve test kümesi oluşturmak için ikiye bölünür. Örneğin 100 örnekten rastgele 50'si eğitim kümesi, kalan 50'si test kümesi olur; iki kümenin kesişimi yoktur.
- Eğitim kümesi bir sınıflandırıcıya verilir ve modellenir, yani modelin parametreleri öğrenilir.
- Modelin başarısını ölçmek için sınıflandırıcıdan, daha önce görmediği ve modeli kurarken kullanmadığı test kümesindeki her örnek için tahmin yapması istenir.
- Tahminlerle gerçek sınıfların ne kadar örtüştüğü sınıflandırıcının başarı ölçüsüdür.

Problem regresyon olsaydı sınıflandırıcı yerine bir regresör kullanılırdı. Birden fazla model varsa test kümesinde daha başarılı olan tercih edilir.

Başarının neden daha önce görülmemiş örneklerde ölçüldüğünü hoca bir benzetmeyle açıklar. Hoca derste çözdüğü soruların aynısını sınavda sorarsa, öğrencilerin konuyu bilerek mi yoksa ezberleyerek mi çözdüğünden emin olamaz. Bunun yerine benzer konularda benzer ama farklı sorular sormalıdır. Böylece öğrencilerin genelleme yapıp yapamadığı ölçülür. Modelde de aynı durum geçerlidir: eğitim kümesindeki başarı ezberi gösterebilir, anlamlı olan test kümesindeki başarıdır.

> **Hocanın vurgusu:** Modelin başarısı, daha önce görmediği örnekler üzerinde ölçüldüğünde anlamlıdır.

## Örnek Sorular

**Soru 1** (ekrandan, 00:15:00; derste sözlü, 00:17:27): Mavi ve siyah noktaları tamamen ayıran kaç farklı doğru çizilebilir?

> **Çözüm:** Sonsuz tane. Bu yüzden makine öğrenmesi problemlerinde çözüm genelde tek değildir; farklı algoritmalar ya da aynı algoritmanın farklı çalıştırmaları farklı modeller verebilir.

**Soru 2** (ekrandan, 00:35:00): 256 rengi 16 renge nasıl indiririz? ($n$ bit $= 2^n$ farklı değer)

> **Çözüm:** Piksellerin RGB üçlüleri 16 kümeye ayrılır ve her küme tek bir renkle temsil edilir. 256 renk için piksel başına $\log_2 256 = 8$ bit, 16 renk için $\log_2 16 = 4$ bit gerekir; bellek yarıya iner, resim kalitesi düşer.

**Soru 3** (derste sözlü, 00:40:11): Bir GSM operatörü müşterilerini kümelemek için hangi özellikleri kullanabilir?

> **Çözüm:** Derste önerilenler: aylık indirilen veri miktarı, yaş, cinsiyet, telefon markası, fatura tutarı, uygulama kullanım süreleri (WhatsApp, YouTube vb.).

**Soru 4** (ekrandan, 01:10:00): El yazısı tanıma (HCR) mı, kitap yazısı tanıma (OCR) mı daha kolaydır? Neden?

> **Çözüm:** OCR daha kolaydır. Basılı yazıda bir harf sınıfının varyansı (sınıf içi farkı) düşüktür; el yazısında aynı harf farklı kişilerde, hatta aynı kişide bile farklı yazılır.

**Soru 5** (ekrandan, 01:15:00): Merkezleri arasındaki uzaklık aynı kalan iki sınıftan, dağılımları küçültülmüş olanı ayırmak daha mı kolaydır, daha mı zor?

> **Çözüm:** Daha kolaydır. Sınıf içi fark azaldıkça (sınıflar arası fark aynı kalırken) sınıflar birbirinden daha kolay ayrılır.

**Soru 6** (ekrandan, 01:05:00): 6.1, 6.2, 6.3, 6.3, 6.3, 6.2, 6.4, 6.1 dizisi için pencere uzunluğu 3 olan eğitim tablosunu kurun. Problem hangi türdendir?

> **Çözüm:** Satırlar (D-3, D-2, D-1 → D): (6.1, 6.2, 6.3 → 6.3), (6.2, 6.3, 6.3 → 6.3), (6.3, 6.3, 6.3 → 6.2), (6.3, 6.3, 6.2 → 6.4), (6.3, 6.2, 6.4 → 6.1). Çıktı sayısal olduğu için problem regresyondur.

**Soru 7** (ekrandan, 01:45:00): ALVINN denemeleri neden şehir içinde değil de otobanda ve diğer arabalar olmadan yapılmıştır? Araba birine çarparsa suçlu kimdir?

> **Çözüm (derste verilen tartışma):** Otoban yayalardan ve beklenmedik durumlardan büyük ölçüde ayrılmış bir ortamdır. Şehir içinde daha önce benzeri görülmemiş durumların ortaya çıkma olasılığı yüksektir. Sorumluluk sorusunun net bir cevabı yoktur: algoritma suçlanamaz; tasarımcılar ve veri kümesini hazırlayanlar arasında sorumluluk belirsizdir ve hukuki düzenleme gerektirir.

**Soru 8** (ekrandan, 01:50:00): Büyük miktarda beyin aktivitesi kaydı toplanırsa hangi görevler tanımlanabilir?

> **Çözüm (derste verilen öneriler):** Düşünceleri okuma, zihinsel hastalıkların tespiti, konuşamayan kişilerin konuşmasını sağlama, rüyaları görselleştirme, yalan makinesi.

## Dersin Toparlaması

Bu derste makine öğrenmesi, geçmiş verilerden bir model öğrenip yeni verilerde tahmin yapma işi olarak tanımlandı. Beş temel problem türü ele alındı. Sınıflandırmada çıktı kategorik, regresyonda sayısaldır. Kümelemede çıktı yoktur, örnekler gruplanır. Pekiştirmeli öğrenmede yalnız doğru/yanlış geri bildirimi verilir. Birliktelik kurallarında birlikte bulunan öğeler aranır. Çözümün genelde tek olmadığı, sınıflar arası farkın büyük ve sınıf içi farkın küçük olmasının problemi kolaylaştırdığı ve hataların her zaman simetrik olmadığı vurgulandı.

Ardından dolar kuru tahmini, HCR/OCR, gen mikrodizilimleri, biyometrik tanıma, spam filtreleri, güvenlik kameraları, sürücüsüz araçlar ve beyin aktiviteleri gibi uygulamalar hangi problem türüne girdikleriyle birlikte tartışıldı. Kararları makinelere bırakmanın getirdiği kandırma ve sorumluluk sorunlarına değinildi. Ders, eğitim ve test kümesi kavramıyla bitti: model eğitim kümesiyle kurulur, başarısı görmediği test kümesinde ölçülür. Sonraki derste yüksek boyut-az örnek sorunu, özellik seçimi, özellik dönüşümü ve normalizasyon gibi konulara geçileceği belirtildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
