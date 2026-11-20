# Ders 9 Genişletilmiş Notu: Makine Öğrenmesine Giriş ve Verilerin Sayısallaştırılması

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Makine Öğrenmesi Bölümünün Akışı
- 2. Makine Öğrenmesi Nedir
- 3. Problem Türleri
- 4. Dolar Kuru Tahmini: Zaman Serisinden Veri Kümesi
- 5. El Yazısı ve Kitap Yazısı Tanıma
- 6. Kolay ve Zor Problem: Sınıf İçi ve Sınıflar Arası Benzerlik
- 7. Günlük Hayattaki Diğer Uygulamalar
- 8. Etik ve Sorumluluk Tartışmaları
- 9. Uygulamalardaki Boyut ve Örnek Sayıları
- 10. Verilerin Sayısallaştırılması
- 11. Örnek Sınıflandırma Uygulaması: OCR ve Eğitim/Test Ayrımı
- Örnek Sorular

## 1. Makine Öğrenmesi Bölümünün Akışı

Bu ders, yapay zeka dersinin makine öğrenmesi bölümünün ilk dersidir. Hoca bu bölümün yaklaşık üç hafta süreceğini söyledi. Slayttaki akış şöyledir (ekrandan, 00:05:00):

- Makine öğrenmesi nedir?
- Günlük hayatımızdaki uygulamalar
- Verilerin sayısallaştırılması
- Özellik belirleme
  - Özellik seçim metotları: bilgi kazancı (information gain, IG), sinyalin gürültüye oranı (S2N ratio), alt küme seçiciler (wrappers)
  - Yeni özelliklerin çıkarımı: temel bileşen analizi (PCA), doğrusal ayırtaç analizi (LDA)
- Sınıflandırma metotları: doğrusal regresyon, karar ağaçları, yapay sinir ağları, k en yakın komşu (k-NN), öğrenmeli vektör kuantalama (LVQ)
- Kümeleme algoritmaları: hiyerarşik kümeleme, k-means, kendi kendini düzenleyen haritalar (SOM), DBSCAN
- Regresyon algoritmaları
- Çok boyutlu verilerle çalışmak
- Veri sızıntısı
- Pekiştirmeli öğrenme

Bu derste ilk üç başlık (kalın yazılanlar) işlendi. Makine öğrenmesi uygulamalarını kullanabilmek için verilerin sayısallaştırılması gerektiğinden bu konu da bu derse alındı. Algoritmalara bir sonraki dersten itibaren geçilecek. Bölümün son haftasında pekiştirmeli öğrenme ve yapay zekanın etikle ilişkisi ele alınacak; hoca, uygulamalar hayatımızda çoğaldıkça etik konuların öne çıktığını belirtti.

## 2. Makine Öğrenmesi Nedir

Veri miktarı giderek artıyor ve bu veriyi klasik yollarla, elle işlemek mümkün değil. Veriyi analiz etmek, veriden bilgi çıkarmak ve bu bilgiden geleceğe dair tahminlerde bulunmak için geliştirilen yöntemlerin bütününe makine öğrenmesi algoritmaları denir.

Bu metotlar geçmişteki verileri kullanarak veriye en uygun modeli bulmaya çalışır. Hoca modeli bulmayı "veriyi sıkıştırmak", yani veriyi çok daha küçük bir alana sığdırmak olarak da düşünebileceğimizi söyledi. Model bulunduktan sonra yeni gelen veriler bu modele göre analiz edilir ve sonuç üretilir.

Farklı uygulamaların farklı beklentileri vardır; makine öğrenmesi metotları bu beklentilere göre sınıflandırılabilir (slayt: "Metot türleri").

## 3. Problem Türleri

### 3.1 Sınıflandırma

Slayttaki iki boyutlu grafikte iki özellik ($X_1$ ve $X_2$) ve iki sınıf (mavi ve siyah noktalar) vardır (ekrandan, 00:10:00). Her noktanın $X_1$, $X_2$ değerleri ve rengi, yani sınıfı bilinmektedir.

Bu veriden bir model kurulur. Model çok basit olabilir: bir çizgi çizilir, çizginin altında kalanlara siyah, üstünde kalanlara mavi denir. Sonra rengi bilinmeyen yeni bir örnek gelir; slaytta kırmızı ve "?" ile gösterilmiştir. Model kullanılarak bu örneğin sınıfı tahmin edilir; burada çizginin üstünde kaldığı için mavi sınıftandır. Amaç, sınıfı bilinmeyen bir örnek geldiğinde onun sınıfını tahmin edebilen bir model ortaya çıkarmaktır. Model veriden çıkarılır; veri başka türlü olsaydı model de başka türlü olurdu.

Özellik sayısı iki olmak zorunda değildir. Slayttaki tabloda beş özellik ve iki sınıf vardır (ekrandan, 00:10:00; yeni satır 00:15:00'te eklendi):

| $x_1$ | $x_2$ | $x_3$ | $x_4$ | $x_5$ | Sınıf |
|---|---|---|---|---|---|
| 1.2 | 3.4 | 2.3 | 6.7 | 7.8 | A |
| 1 | 2 | 2 | 4 | 5 | A |
| 9 | 8 | 6 | 5 | 3 | B |
| 6 | 7 | 8 | 9 | 1 | B |
| 8 | 8 | 9 | 9 | 9 | B |
| 7 | 3 | 2 | 7 | 3 | ? |

Sınıf sayısı da ikiyle sınırlı değildir; çok daha büyük olabilir.

#### Kredi talebi örneği

Hoca tabloyu bir banka kredi başvurusuyla somutlaştırdı. Bankaya (ya da cep telefonundan) kredi başvurusu yapan bir müşteriden bir form doldurması istenir: yaşı, maaşı, evli olup olmadığı, kaç yıldır aynı iş yerinde çalıştığı, ek gelirleri, ne kadar kredi istediği gibi. Tablodaki $x_1, \dots, x_5$ sütunları bu soruların cevaplarıdır.

Bankanın elinde bugüne kadarki müşterilerinden (muhtemelen milyonlarca) alınmış bu tür veriler ve her müşterinin kredisini ödeyip ödemediği bilgisi vardır. Ödeyenler A, ödemeyenler B sınıfı olsun. Bu, geçmişe dair veridir. Yeni bir müşteri geldiğinde formu doldurur; cevapları tabloya yeni bir satır olarak eklenir, ama sınıfı belli değildir. Problem, bu "?" işaretinin yerine A mı B mi yazılacağıdır. İki boyutta bir çizgiyle yapılan şey burada beş boyutta yapılır: A ve B'yi ayıran bir model bulunur ve yeni müşterinin hangi sınıfa ait olacağı tahmin edilir.

### 3.2 Kümeleme

Kümelemede tabloda yine $x_1, \dots, x_5$ özellikleri vardır, ama bunların karşılığında herhangi bir sınıf bilgisi yoktur. Kümelemenin amacı, adı üstünde, verileri kümelere ayırmaktır. Kümenin temel özelliği şudur: aynı küme içindeki elemanlar birbirine, diğer kümelerdeki elemanlara göre daha çok benzer.

Bunun için farklı yöntemler vardır. Bazıları başlangıçta her örneği ayrı bir küme sayıp küme sayısını giderek azaltır; k-means gibi algoritmalar kümelerin merkezlerini bulmaya çalışır. Çıktı her örneğe bir küme numarası atanmasıdır. Slayttaki örnekte (ekrandan, 00:20:00):

| $x_1$ | $x_2$ | $x_3$ | $x_4$ | $x_5$ | Küme ID |
|---|---|---|---|---|---|
| 1 | 3 | 2 | 6 | 7 | 1 |
| 1 | 2 | 2 | 4 | 5 | 2 |
| 9 | 8 | 6 | 5 | 3 | 3 |
| 6 | 7 | 8 | 9 | 1 | 1 |
| 8 | 8 | 9 | 9 | 9 | 2 |

Beş örnek üç kümeye ayrılmıştır. Kümelemede küme sayısı farklı örnek sayısından azdır; beş örneği beş kümeye ayırmak anlamsız olurdu. Sonuçta farklı örnek sayısı azaltılmış olur (burada beşten üçe).

#### Renk azaltma örneği

Slayttaki soldaki resimde 256 farklı renk vardır; sağdaki resimde bu renkler 16'ya indirilmiştir (ekrandan, 00:20:00). Her renk RGB değerleriyle ifade edilirse veri, her satırı bir renk olan 256 satırlı ve üç sütunlu ($x_1, x_2, x_3$) bir tablodur. Bu 256 renk 16 kümeye ayrılır; yani renkler kümelenir.

Bunun faydası saklama alanıdır. Slayttaki formül: $n$ bit $= 2^n$ farklı değer. 256 renkli bir resimde her pikseli tutmak için 8 bit gerekir ($2^8 = 256$); 16 renk varsa 4 bit yeterlidir ($2^4 = 16$).

Bedeli görsel bozulmadır. Yeşilin birçok tonu tek bir yeşil tonuyla aynı kümeye düştüğü için bozulma gözle fark edilir. Orijinal resimde ara renkler olduğu için geçişler yumuşaktır; 16 renkli resimde geçişler serttir. Hoca, 200 renge indirilseydi bu kadar bozulma olmayacağını, 8 renge indirilseydi çok daha fazla bozulma olacağını söyledi.

### 3.3 Regresyon (eğri uydurma)

Regresyon, sınıflandırmaya çok benzer: yine giriş verisi vardır. Fark çıkıştadır. Sınıflandırmada çıkışlar ayrıktır; birbirleriyle aralarında büyüklük-küçüklük ilişkisi olmayan etiketlerdir. Regresyonda çıkışlar birbiriyle büyüklük-küçüklük ilişkisi olan sayısal değerlerdir. Bir sınıf değil, bir sayı (3, 5, 3.7 gibi) tahmin edilmeye çalışılır.

Slayttaki örnekte arabaların motor güçleri ve maksimum hızları verilmiştir (ekrandan, 00:25:00):

| Motor gücü | Max hız |
|---|---|
| 1500 | 230 |
| 2500 | 280 |
| 1600 | 210 |
| 3500 | 290 |
| 1200 | 210 |

Grafikte veri noktaları mavi yıldızlarla, ayrıca bir mavi doğru ve bir turuncu doğru gösterilmiştir.

**Soru:** Grafikteki mavi çizgi neyi ifade ediyor?
**Cevap:** Bir öğrenci önce "örneklerin bulunabileceği, yakın olduğu yerler" dedi; hoca bunun doğru olmadığını söyledi. Sınıflandırmadaki çizgi nasıl modelse bu çizgi de modeldir. Bir denklemdir ve motor gücü verilen bir arabanın maksimum hızının ne olacağını tahmin eder.

**Soru:** Mavi çizgi mi turuncu çizgi mi daha mantıklı bir model, neden?
**Cevap:** Mavi çizgi, çünkü elimizdeki veriye daha uygundur.

Hoca bunu hata kavramıyla açıkladı. Bir veri noktası için modelin tahmin ettiği değer ile gerçek değer arasındaki fark, modelin o noktadaki hatasıdır. Mavi doğruda bu farklar küçüktür. Aynı noktalar için turuncu doğru model olarak kullanılsaydı hatalar kocaman olurdu. Regresyon yöntemleri veriye en uygun modeli bulmaya çalışır.

Giriş tek olmak zorunda değildir; sınıflandırmadaki gibi beş girişli, tek çıkışlı bir yapı da olabilir. Yarın hava sıcaklığının kaç derece olacağı, doların ya da altının ne kadar olacağı gibi sayısal değerleri tahmin etmek regresyon problemleridir.

Sınıflandırma ve regresyon modellerinin bulunma yöntemleri oldukça farklıdır; bunlar sonraki derslerde görülecek. Ama ikisi de bir model bulur ve bu modeli gelecekte karşılaşılacak örneklerin çıkışını tahmin etmek için kullanır: sınıflandırmada hangi sınıfa girdiğini, regresyonda sayısal karşılığını.

### 3.4 Pekiştirmeli öğrenme

Sınıflandırma ve regresyonda modele hep doğru cevap söylenir: "Bu örnek için 3 dedin ama gerçeği 3.1", "A sınıfı dedin ama C sınıfındandı", "kedi dedin ama köpekti". Yani hem yanlış yaptığı hem de doğrusunun ne olduğu söylenir.

Pekiştirmeli öğrenmede (slayt: "Pekiştirmeli Öğrenme") modele çıkışın ne olması gerektiği söylenmez. Başlangıçta rastgele bir model düşünülebilir. Model bir şey yapar ve ona yalnızca yaptığının doğru ya da yanlış olduğu söylenir; iki değerli bir geri bildirim verilir. Doğrusunun ne olması gerektiğine dair bir şey söylenmez. Örneğin model bir hamle yapar; "doğru" ya da "yanlış" denir, ama doğru hamlenin hangisi olduğu söylenmez.

### 3.5 Birliktelik kurallarının keşfi

Slayttaki başlıklar (ekrandan, 00:30:00):

- Sepet analizi: hangi ürünler birlikte satılıyor?
- Raf düzenlemesi: hangi ürünler yan yana konmalı?
- Promosyonlar: neyin yanında ne verilmeli?

Bir marketteki rafların düzenlenmesi rastgele bir iş değildir. Üretici firmaların da talepleri olabilir (ön tarafta ne olacağı, görüş alanının ne kadarını hangi markanın kapsayacağı gibi). Bir yanda bu kısıtlar, öbür yanda ürünleri satma isteği vardır; bu yüzden raf düzeni kritiktir.

Aynı mantık web sitelerine de uyarlanır: ana sayfada hangi ürünlerin gösterileceği, kişiselleştirmede neyin neyle birlikte gösterileceği, bir müşteri bir ürünü tıkladığında yanında ne önerileceği ("bunu alan bunu da aldı"). Burada önemli olan çoğu zaman tek tek seri numaralı ürünlerin değil, ürün türlerinin birlikte geçmesidir.

"Sepet analizi" adı, markette kasaya gelen sepetten gelir. Veri kümesi, ister gerçek ister elektronik sepet olsun, her sepette hangi ürünlerin birlikte bulunduğudur. Bu tür problemler için Apriori gibi algoritmalar vardır, ama bu derste onlara girilmeyecek.

### 3.6 Beş türün özeti

Böylece beş problem (uygulama) türü görüldü: sınıflandırma, kümeleme, regresyon, pekiştirmeli öğrenme ve birliktelik kurallarının keşfi. Bazı algoritmalar birden fazla türde kullanılabilir, bazıları yalnız birinde. Sonraki derslerde ağırlıklı olarak sınıflandırma, kümeleme ve regresyon algoritmaları görülecek; pekiştirmeli öğrenmeye bölümün sonunda değinilecek.

## 4. Dolar Kuru Tahmini: Zaman Serisinden Veri Kümesi

Makine öğrenmesinde olay, geçmiş verileri kullanarak bir model oluşturmak ve bu modele göre yeni gelenleri tahmin etmektir. Dolar kurunu tahmin etmek için de bir model geliştirilebilir. Slayttaki günlük dolar değerleri serisi şöyledir (ekrandan, 00:35:00):

$$6.1,\ 6.2,\ 6.3,\ 6.3,\ 6.3,\ 6.2,\ 6.4,\ 6.1,\ \dots$$

Gerçek hayatta dolar kuru yalnızca önceki günlerin fiyatına bağlı değildir; ekonomik, siyasi ve daha birçok etken vardır. Hoca işi kolaylaştırmak için bir günün kurunun yalnızca kendisinden önceki üç günün kuruna bağlı olduğunu varsaydı. Bu varsayımla bir veri kümesi oluşturmak mümkün hale gelir: seri üzerinde üç günlük bir pencere birer birer kaydırılır ve her konumda bir satır elde edilir.

| D-3 | D-2 | D-1 | D |
|---|---|---|---|
| 6.1 | 6.2 | 6.3 | 6.3 |
| 6.2 | 6.3 | 6.3 | 6.3 |
| 6.3 | 6.3 | 6.3 | 6.2 |
| 6.3 | 6.3 | 6.2 | 6.4 |
| 6.3 | 6.2 | 6.4 | 6.1 |

Slaytta ilk satır sarı, ikinci satır mavi ile vurgulanmıştır. Pencereyi kaydırmak, tek bir seriden çok sayıda örnek elde etmeyi sağlar. Her örneğin üç girişi ve bir çıkışı vardır.

**Soru:** Bu problem, sayılan beş problem türünden hangisine girer?
**Cevap:** Regresyon. 3.5, 6.2 gibi bir sayı tahmin edilmeye çalışılır.

Hoca çok büyük bir varsayımla hareket edildiğini, başka her şeyin dışarıda bırakıldığını tekrar vurguladı. Ama bu bile fena olmayan sonuçlar verebilir: bu örneklerle eğitilen model büyük olasılıkla "üç gündür düşüyorsa düşmeye devam edecek", "üç gündür sabitse sabit kalacak" gibi örüntüleri yakalar.

## 5. El Yazısı ve Kitap Yazısı Tanıma

Slayt: "El yazısı / Kitap Yazısı Tanıma, HCR / OCR. İşlem: Şekillerin hangi harf olduğunu tahmin etme" (ekrandan, 00:40:00). Solda bir el yazısı mektup, sağda bir kitap sayfasının resmi vardır. Hoca, slayttaki el yazısının Wittgenstein'a ait olduğunu söyledi.

Elimizde içinde harfler, kelimeler, satırlar olan bir resim vardır; amaç bunu bir not defterinde düzenlenebilen metne çevirmektir. Problem basitleştirilirse: resimdeki minik şekillerin hangi harf olduğu tahmin edilir. Örneğin yukarıdan aşağı bir çizgi ve sonra yana doğru bir çizgi "L" harfidir; yukarıdan aşağı bir çizgi ve üstünde bir nokta "i" harfidir. Satırları ve şekilleri bulma kısmı geçilirse, problem şuna indirgenir: içinde tek bir harf olan bir resim gelir ve o resmin hangi harf olduğu tahmin edilir.

**Soru:** Bu problem beş türden hangisidir?
**Cevap:** Sınıflandırma. "Bu A harfi, bu B harfi" denir.

**Soru:** Bir resmin 0–9 rakamlarından hangisi olduğunu tahmin etmek ne tür bir problemdir?
**Cevap:** Yine sınıflandırma. Sınıf adlarının 0, 1, 2, 3 olmasının bir etkisi yoktur, çünkü sınıflar arasında büyüklük-küçüklük ilişkisi yoktur. Sıfırıncı sınıf birinci sınıftan büyük ya da küçük değildir, tıpkı A sınıfının C sınıfından büyük ya da küçük olmaması gibi. Dolar kurunda ise 6.2, 6.5'ten küçüktür.

> **Hocanın vurgusu:** Sınıf etiketleri sayı gibi görünse bile aralarında büyüklük-küçüklük ilişkisi yoksa problem sınıflandırmadır; regresyon değildir.

**Soru:** El yazısını tanımak neden daha zordur?
**Cevap:** Bir öğrenci, herkesin el yazısının farklı olduğunu, kitap yazısında ise yazı tiplerinin belli olduğunu söyledi. Hoca bunu sınıf içi benzerlik kavramına bağladı. Çok sayıda kişiden toplanmış büyük "A" harfleri birbirine benzer, ama kitap yazısındaki kadar değil. Kitaplarda kullanılan belli fontlar vardır; hocaya göre on kadar font kitapların neredeyse hepsini kapsar.

**Soru:** Aynı sınıfın içindeki örneklerin birbirine çok benzemesi iyi bir şey mi kötü bir şey mi?
**Cevap:** İyi bir şey. Aynı sınıfın örnekleri birbirine çok benziyorsa sınıfı karakterize etmek kolaydır; benzemiyorlarsa zordur. Optik karakter tanıma, sınıf içi benzerliğin fazla olduğu; el yazısı tanıma, sınıf içi benzerliğin az olduğu problemdir.

## 6. Kolay ve Zor Problem: Sınıf İçi ve Sınıflar Arası Benzerlik

Hoca, kolay ve zor problemi ayırt etmek için "Sınıf içi / Sınıflar arası benzerlik" başlıklı bir slayta tek boyutlu histogramlar çizdi (ekrandan, 00:45:00 ve 00:50:00). Her çizimde bir kırmızı ve bir mavi sınıfın tek bir $X$ özelliğine göre dağılımı vardır. Üç çizim yapıldı.

**Ortadaki çizim.** İki dağılım geniştir ve birbirinin içine girer. Örneğin $X$ 3'ten büyükse örnekler hep mavi, 1'den küçükse hep kırmızıdır; ama 1 ile 3 arası problemlidir. Bu aralıkta en iyi ayırma noktası seçilmeye çalışılabilir, ama orada iki sınıf birbirinden ayırt edilemez.

**Üstteki ve ortadaki çizimin karşılaştırılması.** Hoca iki sınıfın ortalamalarını işaretledi; ortalamalar arasındaki mesafe iki çizimde de eşittir. Yani sınıflar arası farklılık aynıdır.

**Soru:** Hangisi daha kolay bir problem, üstteki mi alttaki (ortadaki) mi?
**Cevap:** Üstteki. Üstteki çizimde kırmızı örnekler birbirine, mavi örnekler de birbirine daha yakındır; ortadakinde daha fazla yayılmışlardır (standart sapma daha büyüktür). Dağılım arttıkça örnekler birbirinin içine daha çok girer. Sonuç: sınıf içi benzerlik ne kadar fazlaysa o kadar iyidir.

**Ortadaki ve alttaki çizimin karşılaştırılması.** Bu ikisinde dağılımların genişliği (standart sapmalar) aynıdır, ama alttakinde sınıfların ortalamaları birbirinden daha uzaktır.

**Soru:** Bu ikisinden hangisi daha kolay?
**Cevap:** Alttaki. Sınıfların birbirine girdiği alan ortadakinde çok daha büyük, alttakinde çok daha küçüktür. Sınıflar birbirinden ne kadar uzaksa o kadar iyidir.

> **Hocanın vurgusu:** İstenen iki şey vardır: sınıf içi benzerliğin fazla olması (bir sınıfın örnekleri birbirine benzesin) ve sınıflar arası farkın fazla olması (farklı sınıfların örnekleri birbirinden uzak olsun).

Üç problem arasında en kolayı üstteki çizimdir; hem dağılımlar dardır hem de sınıflar arasında belirgin bir fark vardır. Alttaki de iyidir, ama dağılımlar geniş olduğu için iki sınıfın birbirine yaklaştığı bir bölge vardır.

## 7. Günlük Hayattaki Diğer Uygulamalar

### 7.1 Kredi talepleri ve e-ticaret

Kredi taleplerinin değerlendirilmesi sınıflandırma örneği olarak daha önce konuşuldu. E-ticarette slayttaki soru şudur: Birisi Amazon.com'dan bir kitap ya da ürün alıyor; müşteriye alması muhtemel kitapları önerelim, ama nasıl? Kitapları konularına, yazarlarına ve birlikte satışlarına göre kümelemek bir yoldur (ekrandan, 01:05:00). Kullanıcı bir kümeden bir kitap seçerse, aynı kümedeki diğer kitaplar ona önerilebilir. Satıcının daha fazla kâr ettiği ürünleri öne çıkarmak gibi hedefler de olabilir.

### 7.2 Gen mikrodizilimleri

Slayt: "100 kişinin (hasta/sağlam) elimizde gen dizilimleri var. Bu dizilimleri analiz ederek hasta olup olmadığı bilinmeyen birisinin hasta olup olmadığını ya da hastalığının türünü öğrenebilir miyiz? En iyi tedaviyi önerebilir miyiz? Nasıl? Elimizde hangi bilgiler olmalı?" (ekrandan, 01:10:00).

Sınıflar iki (hasta, sağlam) ya da daha fazla (hastalık A, hastalık B, hastalık C, sağlam) olabilir. Gen dizilimi örneğin on bin özellikten oluşsun. Bu durumda veri kümesi on bin sütunlu ve yüz satırlıdır; en sonda sınıf sütunu vardır. Mantık beş özellikli kredi tablosuyla aynıdır: geçmiş veriden model kurulur, yeni bir kişinin genleri çıkarılıp modele verilir ve hasta olup olmadığı ya da hangi hastalığa sahip olduğu tahmin edilir.

Hoca bunu uzaktan tıp (teletıp) ve e-sağlık konusuna bağladı. İnsanlar, bilgilerini paylaşmanın karşılığında elde ettikleri şey önemliyse paylaşmaya daha istekli olurlar. Cebinize konan ve her gittiğiniz yeri takip eden bir cihaz yalnız bu haliyle anlatılsa kimse kabul etmez; ama yol tarifi, en yakın eczane gibi faydalar sunduğunda kabul edilir. Aynı şekilde vücuda takılan biyosensörlerden okunan veriler, örneğin kalp krizini 15 dakika önceden fark edip ambulans göndermeyi sağlarsa kabul edilebilir hale gelir. Hoca pandeminin bu süreçleri hızlandırdığını ve e-sağlık uygulamalarının yaygınlaşacağını öngördü.

### 7.3 İris, yüz ve parmak izi

Slayt: "Bu adam kim? İçeri girsin mi?" (ekrandan, 01:15:00). Slayttaki göz resminde iki pembe çember arasındaki halka biçimli bölge iristir. İris, gözbebeğinin (ortadaki siyah bölge) ışık seviyesine göre büyüyüp küçülmesini sağlayan kaslardır: ışık çoksa gözbebeği küçülür, azsa büyür. Hoca, iki kişinin aynı iris kas desenine sahip olma olasılığının milyarda bir olduğunu, bu yüzden irisin çok yüksek doğruluk verdiğini söyledi. Parmak izinde aynı olma olasılığı milyonda birdir; yani doğruluk daha düşüktür.

Ama veriye erişebilmek de önemlidir. Bir havaalanında bir şüphelinin bulunduğu biliniyor ama yeri bilinmiyorsa, güvenlik kameralarıyla elde ne varsa o kullanılır. Kişinin görüntüsünü almak kolaydır; irisi ise çok yakından okumak gerekir (hocanın hatırladığı kadarıyla en gelişmiş kameralarla yaklaşık bir metreden). Erişilebilen bilgi uygulamayı belirler.

İki tür görev vardır:

- **Tanımlama (sınıflandırma):** Bir resmin kime ait olduğunu bulmak. Elimizdeki her kişi bir sınıftır; problem, resmin bu sınıflardan hangisi olduğunu bulmaktır.
- **Doğrulama (validasyon):** İş yeri girişlerinde kullanılır. Kişi önce kim olduğunu beyan eder (bir kod girer, ismini ya da sicil numarasını yazar), sonra yüzünü, irisini, parmak izini ya da sesini verir. Sistem yalnızca bu kişinin iddia ettiği kişi olup olmadığını kontrol eder. Problem iki sınıflı bir sınıflandırmaya indirgenir.

Bin kişinin çalıştığı bir yerde yalnızca sesten bin kişiyi birbirinden ayırmak kolay değildir. Kişinin önce kim olduğunu beyan etmesi ve sonra yalnızca o kişinin örnekleriyle karşılaştırma yapılması çok daha uygulanabilirdir.

Yüz tanımada kişinin farklı açılardan çekilmiş fotoğrafları varsa iş kolaylaşır. Fotoğrafın eskiliği (20 yıl önce mi, 10 dakika önce mi çekildiği), sakal, yaşlanma, gözlük, şapka gibi etkenler zorlaştırır. Maske de günümüzde işi zorlaştıran bir unsurdur; maskeli yüz tanıma ayrı bir problem haline gelmiştir, çünkü ağız bölgesinden elde edilen bilgi kaybolur.

Parmak izi bilgisayarlardan önce de kullanılıyordu; eskiden bir kişinin parmak izini binlerce suçlunun parmak iziyle karşılaştıran uzmanlar vardı. Bilgisayarlarla bu iş çok hızlandı.

**Soru:** Parmak izi verdiniz mi, nasıl verdiniz?
**Cevap:** Bir öğrenci bir tarayıcıya bastırarak verdiğini söyledi. Hoca, eskiden mürekkeple alındığını, günümüz sistemlerinde her parmağın ayrı ayrı dijital tarayıcıdan okutulduğunu ve parmak izlerinin bir şekilde kayıt altına alındığını belirtti.

### 7.4 Ses: kimin sesi, ne diyor

Slayt: "Bu ses kimin? Bu ses ne diyor?" (ekrandan, 01:20:00). Slaytta sesin sayısallaştırılmış iki hali vardır: üstte tek boyutlu dalga biçimi, altta frekansa göre açılmış hali.

"Bu ses kimin" sorusu için hoca, bir GSM operatörünün müşteriyi sesinden tanıyan uygulamasını örnek verdi: şifre girmek yerine arayıp belirli bir cümleyi söylersiniz. Burada da doğrulama yapılır; arama zaten belli bir numaradan geldiği için o numaranın kime ait olduğu bellidir ve iş kolaylaşır.

"Bu ses ne diyor" kısmı, konuşmayı metne çevirmektir (arama motoruna konuşarak yazmak, sesli mesajı metne çevirip göndermek gibi).

**Soru:** Bu sistemlerle deneyimleriniz nasıl?
**Cevap:** Öğrenciler Türkçe için zayıf olduğunu, söylenen kelimelerin farklı kelimelerle karıştırılabildiğini, araya İngilizce kelime ya da özel isim girdiğinde bulunamadığını söyledi. Hoca, sistemin ses benzerliğine dayanıp anlamsız Türkçe kelimeler üretebildiğini ekledi; bir video sitesinin otomatik altyazısında Türkçe konuşmanın İngilizce altyazısı istenince ortaya çıkan komik sonuçları örnek verdi.

**Soru:** Bu sistemler belli diller için neden daha iyi çalışıyor olabilir?
**Cevap:** Dillerin özellikleriyle ilgili olabilir, ama başka bir sebep daha vardır. Bir öğrenci "daha çok eğitilmiş olabilir" dedi; hoca bunu "ellerinde daha çok eğitim verisi olabilir" diye düzeltti.

> **Hocanın vurgusu:** Örnek sayısı ne kadar fazlaysa tahminler o kadar güçlü olur. Çok az örnekle bir şey tahmin etmek zordur. Bu bütün problemler için geçerlidir.

### 7.5 İmza

Slayt: "Bu imza kimin? Yoksa taklit mi?" Bankada büyük bir işlem yaptırırken atılan imza sistemdeki imzayla karşılaştırılır; bu işi makinelerin yapması amaçlanır. Hoca, elektronik imzaya göre güvenilirliği çok daha zayıf olduğu için ıslak imzanın önümüzdeki yıllarda epey azalacağını tahmin ettiğini söyledi.

İmzada iki tür bilgi vardır. Birincisi imzanın resmidir; resme bakıp taklit etmek mümkündür, bazı insanlar bunda çok becerikli olabilir. İkincisi imzanın atılma sürecidir: çizgilerin hangi sırayla çizildiği, kalemin nerede bastırılıp nerede hafifletildiği (sonlara doğru kuyrukların incelmesi gibi). Bir tablette imza attırılırsa bu süreç de kaydedilir. Kişinin her imzası birbirinin aynısı değildir, ama süreçleri birbirine çok benzer. Bir taklitçi şekil olarak çok benzer bir imza üretebilir, ama süreç olarak aynısını üretmesi zordur; ancak imza atılırken çekilmiş videoyu görmüşse işi kolaylaşır.

### 7.6 Spam tespiti

Slayt: "Bu metnin konusu nedir? Bu mail spam mi? Anti spam yazılımları nasıl çalışır? Spamciler nasıl çalışıyor? Yeni nesil spam mailler: mesaj resimde, metinde ise anti spamlardan kaçmak için gereken kelimeler var. Makine öğrenmesi metotlarını hem spamciler hem anti spamciler kullanıyor." (ekrandan, 01:30:00).

Spam tespiti standart olarak bütün e-posta sunucularında vardır. E-posta göndermek SMS gibi paralı olmadığı için spam e-posta atmak kolaydır ve işin ticari yönü olduğu için ölmeyecek bir sektördür. Spam tespiti kapalı olsaydı hocaya göre her gün en az bir saat spam ayıklamakla uğraşmak gerekirdi. E-posta sunucularında çalışan bu sınıflandırıcılar iki sınıflı bir problem çözer: spam ya da değil.

#### Tahmin hatalarının maliyeti

Tahminlerin yanlış olması her zaman aynı etkiyi doğurmaz. İki tür hata vardır:

- Spam olan bir maile "spam değil" demek: spam gelen kutusuna düşer, okumak zorunda kalınır, biraz zaman kaybedilir.
- Spam olmayan bir maile "spam" demek: gerçekten önemli bir mail spam kutusuna düşer. Spam dedektörüne çok güvenen biri spam kutusuna hiç bakmayıp boşaltır ve önemli maili kaybeder. Bunun etkisi daha büyüktür.

Daha belirgin bir örnek sağlıktır. Hasta olmayan birine "hastasın" demek kötüdür, ama hasta olan birine "hasta değilsin" demek çok daha kötüdür.

> **Hocanın vurgusu:** Her yanlış aynı büyüklükte etkiye sebep olmaz; bazı yanlışlar daha problemlidir. Algoritmalara bu tür ek bilgiler verilebilir.

Spam dedektörleri mükemmel çalışsaydı spam kutusuna erişmeye gerek kalmazdı. Ama mükemmel değillerdir. Örneğin bir üniversitenin e-posta hesabı ele geçirilip oradan spam atılırsa üniversite kara listeye alınabilir; o üniversitedeki herkesin maili başkalarının spam kutusuna düşebilir. Ayrıca spam dedektörleri geliştikçe spamciler de gelişir: mesajı resmin içine koyarlar, görünmez karakterler eklerler; insan mesajı normal görür ama makine metne baktığında anlamsız bir şey görür. Spamciler bu sistemlere erişebildikleri (bir yere mail atıp spam'e düşüp düşmediğini görebildikleri) için dedektörleri kandırmak üzere sistemler eğitirler. Makine öğrenmesini hem spamciler hem de anti spamciler kullanır.

### 7.7 Güvenlik kamerası kayıtları

Slayt: "Olağan dışı bir durum var mı? Güvenlik kamerası kayıtları." Kameraları insanların izlemesi yerine makineler izleyip olağan dışı bir durum olup olmadığına karar verebilir. Hareket algılayıcılar her zaman yeterli değildir. Hoca bir örnek anlattı: geceleri bir camiye birilerinin girmemesi için hareket sensörlü alarm kurulmuş, her gece alarm çalmış, içeri girildiğinde kimse bulunamamış; sonunda alarmı içeride gezinen başka canlıların tetiklediği anlaşılmış. <!-- BELİRSİZ: Altyazıda alarmı neyin tetiklediği bozuk yazılmış ("sansörler ... içeride geziniyorlar"); büyük olasılıkla hayvanlar kastediliyor. --> Hareket algılayıcı, gerçek bir problemle problem olmayan bir durumu ayırt edemez.

Kamera görüntüleri işlenerek yalnızca istenen türden bir olay olduğunda haber veren uygulamalar düşünülebilir (bir yerde kalabalık toplanması, araç plakalarının okunması gibi). Binlerce kamera insanlar tarafından anlık olarak izlenemez; insanlar ancak olay olduktan sonra geriye dönük inceleme yapabilir. Makineler izleyebilirse, örneğin ıssız bir sokakta biri bıçak çektiğinde ekipler anında yönlendirilebilir. Kamerayı koymak sorun değildir; sorun, kameradan gelen bilgiyi işleyecek insandır.

Bu sistemleri eğitmek için video akışının hangi bölgesinde ne olduğunu (örneğin "burada kavga var") gösteren etiketler gerekir.

> **Hocanın vurgusu:** Eğitim verisi kültüre ve yöreye bağlıdır. İngiltere'deki havaalanlarının görüntüleriyle eğitilmiş, iki kişinin kavga ettiğini algılayan bir sistem Türkiye'ye kurulursa sorun çıkabilir. Akdeniz kültürlerinde insanlar arası mesafe daha azdır. Uzun zamandır görmediğiniz bir arkadaşınızla havaalanında karşılaşıp sarıldığınızda, İngiliz verisiyle eğitilmiş sistem kavga ettiğinizi düşünebilir. Kişiye ve yöreye özel verinin gerekli olabileceği akılda tutulmalıdır.

### 7.8 İşaret dili tanıma

Slayt: "Kamera kaydındaki kişi ne anlatıyor? İşaret Dili Tanıma." Birisinin işaret diliyle anlattığını videodan metne dönüştürmek de bir makine öğrenmesi uygulamasıdır.

### 7.9 Sürücüsüz arabalar

Hoca slayta bilerek eski, siyah-beyaz resimler koyduğunu söyledi.

**Soru:** Bu resimlerin ortak özelliği ne, neden konmuş olabilirler?
**Cevap:** Siyah-beyaz ve çok eskiler; bu da sürücüsüz araçlar üzerinde çok uzun zamandır çalışıldığını gösterir. Hâlâ tam geçiş yoktur, ama giderek daha büyük geçişlere yaklaşılmaktadır. Slaytta ALVINN de vardır; bu tür araçlar trafiğe kapalı yerlerde çalıştırılır.

Bu konudaki sorumluluk tartışması 8. bölümde ele alınmıştır. Hoca, metrobüs yolu gibi korunmuş yollarda ya da bütün araçların sürücüsüz olduğu bir ortamda sürücüsüz araçların büyük sorun olmayacağını, asıl zorluğun insanların kullandığı araçlarla aynı yolu paylaşmak ve yayaların trafiğe girebildiği sokaklarda yapay zekaya güvenmek olduğunu söyledi. Kalabalık caddeleri olmayan sakin bölgelerde kullanım daha kolay olabilir. Kullanıma geçeceğini, ama zamanla belli regülasyonların oluşacağını tahmin ettiğini belirtti.

Öte yandan F-16'ların kontrolünün büyük kısmını pilotlar değil arkadaki kontrol yazılımları yapar; araçları da makinelerin kontrol etmesi daha mantıklıdır. Yüksek hızda bir aracı kullanmak insan için uygun bir iş değildir; insanlar uykusuz ya da alkollü araç kullanabilir. Belli zararları olsa da toplam faydası daha baskın olacak, yani makineler büyük olasılıkla insanlardan daha az hatayla araba kullanabilecektir.

### 7.10 Adalet: mahkeme kararları

Slayt başlığı: "Adalet" (Çin'deki bir uygulamaya dair maddeler içerir). Mahkeme kararlarının yapay zekaya verdirilmesi için Türkiye dahil birçok ülkede çalışmalar vardır. Bunun uygun olduğu yer, delil ve suçlamalar belli olduğunda kararın ne olacağının kurallarla çok net belli olduğu, çok fazla değişkenlik göstermeyen dava türleridir (örneğin internet üzerinden hakaret davaları, bazı ticari davalar). Bu davaların sorunu karmaşıklık değil sayılarının çok fazla olmasıdır; binlerce dava adalet sistemini tıkar, süreçler uzar. Ağır suçlar ise bambaşka bir alandır; hakimin düşünmesi gereken çok fazla etken vardır. Hoca, Çin'in hem dava sayısının çokluğu (büyük eğitim kümesi) hem de belki kültürel olarak bu tür sistemlere yatkın olduğunu söyledi.

### 7.11 Beyin aktiviteleri

Slayt: "Beyin Aktiviteleri. İnsanların değişik şeyler düşünürkenki, değişik duygulara sahipkenki, problem çözerken ki beyin aktiviteleri kaydedilir. Görev?" (ekrandan, 01:50:00). Kayıtlar belli bir çözünürlükte yapılabilir, çok yüksek çözünürlükte değil.

**Soru:** Milyonlarca insanın bu tür beyin aktivitesi kayıtları elinizde olsa neler yapabilirsiniz?
**Cevap:** Öğrencilerden gelen cevaplar ve hocanın yorumları:

- Düşünce gücüyle basit görevler yapmak: örneğin yemek yemeyi düşünürken her insanda benzer bölgeler aktif oluyorsa bir yemek sipariş sitesi kendiliğinden açılabilir.
- Felçli insanlar için, beynin kolu oynatmaya yarayan bölgesi aktif olduğunda robot kolu oynatmak; yani yapay uzuvları hareket ettirmek.
- Oyunlarda ekran karakterini yalnızca düşünerek hareket ettirmek; bunun için modüller vardır.
- Suç işlenmeden önceki beyin aktivitelerinden suçu önceden tespit etmek. Hoca bunun bir filmi (Minority Report) hatırlattığını ve sıkıntılı olduğunu söyledi (bkz. 8. bölüm).
- Korkan bir insan için otomatik polis çağırmak; örneğin aile içi şiddet durumlarında. Hoca bunun da insanların izin vermesine bağlı olduğunu, sağlık örneğindeki "karşılıklı fayda" mantığına benzediğini belirtti: "Senin bütün düşüncelerini inceleyeceğiz" denirse kimse kabul etmez, ama böyle bir uygulama için insanlar razı olabilir.
- Beyninde hasar olan birinde hasarın yerini tespit etmek, hatta düzeltmek.
- İnsanların düşüncelerini okumak: Hoca, şu an mümkün olmadığını, gelecekte olup olmayacağının da bilinmediğini, ama her şey girdi olarak temsil edilebiliyorsa prensipte mümkün olduğunu söyledi. Rüyaları kaydedip sonradan izlemek de prensipte mümkün olabilir; kabus görenler için tedavide bir etken olabilir.

## 8. Etik ve Sorumluluk Tartışmaları

### 8.1 Sürücüsüz araçlarda suç kimin

Sürücüsüz bir araç bir yayaya çarparsa (ve bu tür kazalar gerçekten olmaya başladı) suçlu kimdir? Aynı durumda insan sürücü de büyük olasılıkla çarpacak idiyse yaya suçlu sayılabilir. Ama insanın kurtarabileceği bir durumda makine hata yaptıysa suçlu kimdir?

Sistemde birden fazla bileşen vardır: sensörler, bilgisayar donanımı ve yazılım. Hata sensörden, donanımdan ya da yazılımdan çıkmış olabilir ve her birinin sorumlusu başkadır (sensör üreticisi, bilgisayar üreticisi, yazılımcı). Bu sistemlerin kullanımı arttıkça bu tür kazalar ve problemli durumlar artacak, insanlar sistemi suistimal etmeye çalışabilecek (kendi çarptığı bir kazayı "yapay zeka çarptı" diye göstermek gibi). Kayıtların değiştirilebilmesi de bir sorun olarak görünüyor. Bütün büyük araba üreticileri bu araçlara milyarlarca dolar yatırım yaptığı için geri dönüş pek mümkün görünmüyor.

### 8.2 Suç işlemeden önce tespit

Hoca, insanların yaklaşık yüzde birinin psikopat (suç işlemeye meyilli ve suç işlediğinde vicdan azabı duymayan) olduğunu söyledi. Psikopatları tespit etmek mümkün olabilir; ama bir kişiyi suç işlemeden, "işleyebilir" diye hapse atmak ya da bir yere kapatmak büyük bir etik problemdir. Bir yıl önceden bilinse bile kişiyi tutmanın mantıklı olup olmadığı zor bir sorudur.

## 9. Uygulamalardaki Boyut ve Örnek Sayıları

Slayt: "Uygulamalardaki boyut örnek sayıları". Grafiğin yatay ekseninde örnek sayıları, dikey ekseninde boyut (özellik) sayıları vardır; makine görmesi, yüksek enerji fiziği, biyoinformatik gibi uygulama alanları bu düzlemde gösterilmiştir.

Bazı alanlarda (gen verisi gibi) satır sayısı, yani örnek sayısı azdır ama sütun sayısı, yani özellik sayısı çok fazladır. Makine görmesi ve görüntü işleme alanında ise hem örnek sayısı hem de özellik sayısı fazladır. Çünkü resmin özellikleri her piksel kullanılarak hesaplanır; 100×100'lük bir resim bile 10 bin boyut demektir.

Slayttaki son başlık "Öğrenmenin geleceği"dir; hoca burada yalnızca uygulamaların giderek arttığını, hem büyük bir potansiyel hem de birçok problem olduğunu söyleyip geçti.

## 10. Verilerin Sayısallaştırılması

### 10.1 Tablo biçimli veri ve kategorik özellikler

Kredi örneğindeki gibi tablo biçimli (tabular) veriler zaten büyük ölçüde sayısaldır. Ama bazı özellikler sayı değildir. Örneğin cinsiyet (kadın, erkek) bir sayı değildir; birine 1, diğerine 2 yazmak, biri diğerinden küçük ya da büyükmüş gibi bir anlam katar. "Nerelisiniz?" sorusunun cevabı bir şehirdir; şehirleri plaka kodlarıyla sayıya çevirmek de makul değildir, çünkü bir şehrin diğerinden büyük ya da küçük olduğu gibi gerçekte olmayan bir bilgiyi işin içine katar.

Sayısal olmayan ama belli sayıda seçenekten birinin seçildiği durumlarda bunların sayısallaştırılması için özel bir işlem yapılır. Bazı algoritmalar (ileride görülecek) kategorik verilerle doğrudan çalışabilir; A, B, C diye verildiğinde de çalışırlar. Ama büyük bir kısmı sayı bekler.

### 10.2 One-hot encoding

Bir soruya karşılık A, B ve C şıklarından biri seçiliyor olsun ve bu soru veri tablosunun 15. özelliği olsun. 15. özellik üç ayrı özelliğe dönüştürülür (ekrandan, 02:15:00):

- A → 1 0 0
- B → 0 1 0
- C → 0 0 1

Kullanıcı A'yı seçtiyse bu üç özelliğin değerleri 1, 0, 0; B'yi seçtiyse 0, 1, 0; C'yi seçtiyse 0, 0, 1 olur. Buna one-hot encoding denir (slaytta "One-hat encoding" diye yazılmıştır). Oluşan özellik sayısı seçenek sayısına eşittir; A, B, C, D, E'den biri seçiliyor olsaydı özellik beş ayrı özelliğe dönüştürülürdü.

<!-- BELİRSİZ: Altyazıda A için "0, 1, 1" geçiyor; karedeki slayt A → 1 0 0 gösteriyor, karedeki değer kullanıldı. -->

**Soru:** Beş farklı seçeneği neden sadece 3 bitle temsil etmiyoruz?
**Cevap:** Hoca bunu güzel bir soru olarak niteledi. 3 bitle 8 farklı değer temsil edilebilir, bu doğrudur. Ama örneğin A'yı ve B'yi birer 3 bitlik kodla temsil edersek, A ile B birinci bite göre birbirine benziyor, ikinci bite göre benzemiyor gibi görünebilir. Her bit bir sütun, yani ayrı bir özelliktir. Böylece gerçekte olmayan varsayımlar işin içine katılır. Gerçekte A, B'ye ne kadar benziyorsa C'ye de o kadar benzer; ikili kodlama farklı seçenek çiftleri arasına farklı benzerlikler ekler. Slaytta hoca bu sırada metni "A B C D E'den birini seçiyoruz", "8 farklı" ve B için ikili kod deneyerek düzenledi.

> **Ek bilgi (derste anlatılmadı):** One-hot kodlamada her iki farklı seçeneğin vektörleri arasındaki Öklid uzaklığı aynıdır ($\sqrt{2}$). İkili kodlamada ise örneğin 001 ile 011 arasındaki uzaklık 1, 001 ile 110 arasındaki uzaklık $\sqrt{3}$ olur; hocanın sözünü ettiği "gerçekte olmayan benzerlik" budur.

### 10.3 Resim, metin, video ve ses

Slayttaki "Verilerin Sayısallaştırılması" tablosu (ekrandan, 02:20:00):

| Veri | Sayısallaştırma |
|---|---|
| Resim | Resmin her bir pikselinin renkli resimlerde R, G, B değerleri, siyah-beyaz resimlerde 1–255 arası gri seviyesi kullanılarak sayılara çevrilir. Renkli resimler 3 adet, siyah-beyazlar 1 adet en×boy büyüklüğünde matrisle ifade edilir. |
| Metin | Metindeki harfler, heceler ve kelimeler genelde frekanslarına göre kodlanarak sayılara çevrilir. |
| Hareketli görüntü | Resim bilgisine ek olarak resmin hangi resimden sonra geldiğini gösteren zaman bilgisini de içerir. Bu ek bilgi haricinde yapılan işlem resim ile aynıdır. |
| Ses | Ses, genlik ve frekansın zaman içinde değişimiyle kodlanır. |

**Metin.** Kullanıcının bir ürüne yazdığı yorum gibi bir metin özelliği sayıya nasıl çevrilir? Doğal dil işleme derslerinde görülen birçok yöntem vardır; en basiti harflerin, hecelerin ve kelimelerin frekanslarına göre kodlanmasıdır. Hoca üç örnek metin ve bir tablo üzerinde gösterdi. Tabloda her satır bir metin, her sütun bir kelimedir ($w_1, \dots, w_5$); hücre, o kelimenin o metinde kaç kez geçtiğidir. Sona bir sınıf sütunu eklenir; örneğin spam filtresi için metnin spam olup olmadığı.

<!-- BELİRSİZ: Hocanın tablosu karelerde okunur değil; birinci metnin kelime listesi küçük slayt önizlemesinden ve anlatımdan (w1 iki kez, w3 yok) çıkarıldı. İkinci ve üçüncü metnin sayıları altyazıdaki anlatımla uyuşuyor. -->

| | $w_1$ | $w_2$ | $w_3$ | $w_4$ | $w_5$ | Sınıf |
|---|---|---|---|---|---|---|
| Ör1: w1 w2 w1 w4 w5 | 2 | 1 | 0 | 1 | 1 | Spam |
| Ör2: w1 w3 w5 w3 | 1 | 0 | 2 | 0 | 1 | Değil |
| Ör3: w2 w4 w2 | 0 | 2 | 0 | 1 | 0 | Değil |

Örneğin $w_1$ sütunu, $w_1$ kelimesinin her metinde kaç kez geçtiğini gösterir. Böylece metinler içerdikleri kelimelerin frekanslarına göre sayısallaştırılmış olur ve tablo, sınıflandırma için kullanılabilecek bilindik matris biçimine gelir.

**Video.** Videonun resimden tek farkı, birçok resmin arka arkaya gelmesi ve zaman bilgisini taşımasıdır; bunun dışında yapılan işlemler aynıdır.

**Ses.** Ses normalde tek boyutlu bir sinyaldir. Fourier dönüşümü gibi yöntemlerle frekans alanına çevrilir; her frekans bandında ne kadar yükseğe çıkıldığını gösteren bir matrise, yani bir tür resme dönüştürülebilir (ses tanıma slaytındaki alttaki görüntü).

## 11. Örnek Sınıflandırma Uygulaması: OCR ve Eğitim/Test Ayrımı

### 11.1 Veri kümesinin oluşturulması

Örnek bir OCR uygulaması: bir kitap fotokopisinin içindeki yazıların metne dönüştürülmesi. Önce metindeki satırlar, sonra her satırdaki harfler bulunur; bunların yapıldığı varsayılır. Her harfe ait onlarca örnek resimden etiketlenmiş bir veri tabanı oluşturulur.

Slaytta "2" rakamının küçük bir siyah-beyaz piksel resmi ve bunun sayı matrisi gösterilmiştir. Siyah-beyaz alındığı için değerler ikilidir; gri seviyede alınsaydı 0–255 arasında olurdu. Matris tek bir satıra açılarak vektöre dönüştürülür. Slayttaki maddeler (ekrandan, 02:25:00):

- Bu şekilde tanınmak istenen harf için çeşitli fontlarla yazılmış birçok örneği temsil eden 60 boyutlu vektörler elde edilir.
- Bu uygulama için özellik sayısı 60'tır; örnekler 60 boyutlu bir uzayda temsil edilmektedir.
- Elimizde 10 rakama ait farklı fontlarla yazılmış 10'ar resim olursa veri kümemiz 100 örnek × 60 boyutluk bir matris olacaktır.
- Elimizde her örneğin hangi harf olduğunu gösteren sınıf bilgisi de bulunmaktadır.

Yani her resim iki boyutlu uzayda değil, 60 boyutlu uzayda bir noktadır. Her satırın sonunda bir sınıf bilgisi vardır ("bu 2'dir"). 10 rakam × 10 font = 100 satır; 60 özellik sütunu ve 1 sınıf sütunuyla 61 sütunluk bir matris oluşur.

### 11.2 Eğitim ve test kümesi

Slayttaki devam maddeleri (ekrandan, 02:25:00):

- Bu matris eğitim ve test kümesi oluşturmak için 2'ye bölünür.
- Eğitim kümesi bir sınıflandırıcıya verilir.
- Modellenir.
- Modelin başarısını ölçmek için sınıflandırıcının daha önce görmediği, modelini oluşturmakta kullanmadığı test kümesi için tahminde bulunması istenir.
- Bu tahminlerle gerçek sınıfların aynılığının ölçüsü sınıflandırıcının başarı ölçüsüdür.

Örneğin 100 örneğin 50'siyle model kurulur, 50'si test için dışarıda bırakılır. Model test resimleri için "bu 3'tür", "bu 7'dir" gibi tahminler yapar; bu tahminlerin gerçek sınıflarla ne kadar örtüştüğü başarı ölçüsüdür.

Alternatif olarak veri eğitim ve test diye ayrılmadan bütün veriyle model kurulup yine bütün veri üzerinde test edilebilirdi. Ama eğitim kümesi üzerindeki performans bir şey ifade etmez.

**Soru:** Neden modelin daha önce görmediği örnekler üzerindeki tahminler önemlidir?
**Cevap:** Bir öğrenci, gerçek hayatta karşılaşacağı örnekleri de daha önce hiç görmemiş olacağını söyledi; hoca onayladı. Modelin gerçek hayattaki performansı ölçülmelidir; tek bir veri kümesi üzerindeki performansı önemli değildir. Gerçek hayattaki bütün durumları kapsayıp eğitim kümesine koymak mümkün olmadığından veri eğitim ve test diye iki parçaya bölünür.

Hoca bunu kaba bir örnekle açıkladı: tahminleyici eğitim örneklerini ezberleyebilir. Örneğin her örneği hash'leyip hash koduna karşılık sınıf bilgisini bir look-up tablosunda tutabilir. Eğitim kümesinden bir örnek geldiğinde sınıfını çok basit bir kuralla ve çok yüksek doğrulukla söyler ("şöyleyse şudur"). Ama bu hash kodları gerçekte anlamlı bir şey ifade etmez ve yeni örneklere genellenmez.

> **Hocanın vurgusu:** Asıl önemli olan test kümesi üzerindeki performanstır. Eğitim kümesi üzerindeki performans bize hiçbir bilgi vermez.

## Örnek Sorular

**Soru 1** (ekrandan, 00:35:00; derste sözlü, 00:34:54): Günlük dolar kuru serisi 6.1, 6.2, 6.3, 6.3, 6.3, 6.2, 6.4, 6.1'dir. Bir günün kurunun yalnızca önceki üç günün kuruna bağlı olduğu varsayılırsa hangi eğitim örnekleri elde edilir? Bu problem hangi türdendir?

> **Çözüm:** Üç günlük pencere birer kaydırılarak beş örnek elde edilir: (6.1, 6.2, 6.3 → 6.3), (6.2, 6.3, 6.3 → 6.3), (6.3, 6.3, 6.3 → 6.2), (6.3, 6.3, 6.2 → 6.4), (6.3, 6.2, 6.4 → 6.1). Çıkış sayısal olduğu için problem regresyondur (python ile kontrol edildi).

**Soru 2** (derste sözlü, 00:38:38 ve 00:39:02): Bir resimde tek bir harf olduğunda hangi harf olduğunu tahmin etmek, ya da bir resmin 0–9 rakamlarından hangisi olduğunu tahmin etmek hangi tür problemdir?

> **Çözüm:** İkisi de sınıflandırmadır. Sınıf adlarının rakam olması problemi regresyona çevirmez, çünkü sınıflar arasında büyüklük-küçüklük ilişkisi yoktur.

**Soru 3** (ekrandan, 00:50:00; derste sözlü, 00:47:42 ve 00:49:10): İki sınıfın tek boyutlu dağılımları için üç durum çizilmiştir: (a) dar dağılımlar, ortalamalar arası mesafe $d$; (b) geniş dağılımlar, ortalamalar arası mesafe yine $d$; (c) geniş dağılımlar, ortalamalar arası mesafe $d$'den büyük. (a) ile (b), sonra (b) ile (c) karşılaştırıldığında hangisi daha kolay bir sınıflandırma problemidir?

> **Çözüm:** (a), (b)'den kolaydır: sınıflar arası mesafe aynı, ama (a)'da sınıf içi benzerlik daha fazladır (standart sapma küçük). (c), (b)'den kolaydır: dağılım genişliği aynı, ama (c)'de sınıflar birbirinden daha uzaktır. Üçünün en kolayı (a)'dır.

**Soru 4** (ekrandan, 00:20:00): 256 renkli bir resim kümeleme ile 16 renge indirilirse piksel başına gereken bit sayısı nasıl değişir?

> **Çözüm:** $n$ bit $2^n$ farklı değer gösterir. 256 renk için $\log_2 256 = 8$ bit, 16 renk için $\log_2 16 = 4$ bit gerekir; piksel başına bit sayısı yarıya iner.

**Soru 5** (ekrandan, 02:15:00; derste sözlü, 02:14:38): A, B, C, D, E seçeneklerinden birinin seçildiği kategorik bir özellik one-hot encoding ile nasıl kodlanır? Neden bunun yerine 3 bitlik ikili kodlama kullanılmaz?

> **Çözüm:** Özellik beş ayrı özelliğe dönüştürülür: A → 1 0 0 0 0, B → 0 1 0 0 0, C → 0 0 1 0 0, D → 0 0 0 1 0, E → 0 0 0 0 1. 3 bitlik ikili kodlama 8 değeri temsil edebilir, ama her bit ayrı bir özellik olduğundan bazı seçenekler bazı bitlerde ortak çıkar ve aralarında gerçekte olmayan benzerlikler varsayılmış olur. One-hot kodlamada her seçenek diğerlerine eşit uzaklıktadır.

**Soru 6** (ekrandan, 02:20:00; derste sözlü, 02:17:06): Üç metin şunlar olsun: Ör1: w1 w2 w1 w4 w5 (spam), Ör2: w1 w3 w5 w3 (değil), Ör3: w2 w4 w2 (değil). Bu metinleri kelime frekanslarıyla sayısallaştırın.

> **Çözüm:** Sütunlar $w_1, \dots, w_5$ olmak üzere: Ör1 → (2, 1, 0, 1, 1), Ör2 → (1, 0, 2, 0, 1), Ör3 → (0, 2, 0, 1, 0); sınıf sütunu Spam, Değil, Değil (python ile kontrol edildi). <!-- BELİRSİZ: Ör1'in kelime listesi küçük slayt önizlemesinden okundu. -->

**Soru 7** (ekrandan, 02:25:00): Her rakam resmi 60 boyutlu bir vektörle temsil ediliyor. 10 rakamın her biri için 10 farklı fontta resim varsa veri kümesi matrisinin boyutu nedir? Model başarısı nasıl ölçülmelidir?

> **Çözüm:** $10 \times 10 = 100$ örnek; 60 özellik sütunu ve 1 sınıf sütunuyla $100 \times 61$'lik bir matris. Matris eğitim ve test kümesine bölünür (örneğin 50/50); model eğitim kümesiyle kurulur, başarı modelin hiç görmediği test kümesindeki tahminlerin gerçek sınıflarla uyuşma oranıyla ölçülür.

**Soru 8** (derste sözlü, 01:28:20): Bir spam filtresinin yapabileceği iki tür hata nedir? Bunların etkisi aynı mıdır?

> **Çözüm:** Spam olan bir maile "spam değil" demek (kullanıcı biraz zaman kaybeder) ve spam olmayan bir maile "spam" demek (önemli bir mail kaybolabilir). Etkileri aynı değildir; ikincisi daha zararlıdır. Benzer şekilde sağlıkta hasta birine "sağlamsın" demek, sağlam birine "hastasın" demekten daha kötüdür.

## Dersin Toparlaması

Bu derste makine öğrenmesine giriş yapıldı. Makine öğrenmesi, geçmiş veriden veriye en uygun modeli bulup bu modelle yeni örneklerin çıkışını tahmin etmektir. Problemler beklentilere göre beş türe ayrıldı: sınıflandırma (ayrık ve aralarında sıralama olmayan etiketler), regresyon (sayısal çıkış), kümeleme (etiketsiz gruplama), pekiştirmeli öğrenme (yalnızca doğru/yanlış geri bildirimi) ve birliktelik kurallarının keşfi (sepet analizi). Dolar kuru örneğinde bir zaman serisinin kayan pencereyle regresyon veri kümesine nasıl dönüştürüldüğü, el yazısı tanıma örneğinde ise sınıf içi benzerliğin fazla ve sınıflar arası benzerliğin az olmasının problemi kolaylaştırdığı gösterildi.

Günlük hayattan çok sayıda uygulama (gen mikrodizilimleri, iris ve parmak izi, ses, imza, spam, güvenlik kameraları, sürücüsüz araçlar, mahkeme kararları, beyin aktiviteleri) üzerinden tanımlama ile doğrulamanın farkı, hata türlerinin farklı maliyetleri, eğitim verisi miktarının ve kültüre bağlılığının önemi ve etik sorunlar tartışıldı. Son olarak kategorik verilerin one-hot encoding ile, metinlerin kelime frekanslarıyla, resim, video ve sesin matrislerle sayısallaştırılması anlatıldı. OCR örneğinde veri kümesinin nasıl kurulduğu ve modelin başarısının neden eğitim kümesinde değil test kümesinde ölçülmesi gerektiği gösterildi. Bir sonraki dersten itibaren sınıflandırma, kümeleme ve regresyon algoritmalarına geçilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
