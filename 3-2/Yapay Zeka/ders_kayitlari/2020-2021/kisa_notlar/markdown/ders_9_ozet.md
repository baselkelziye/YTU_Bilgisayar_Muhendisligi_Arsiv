# Ders 9 Çalışma Özeti

## Genel Konular

- Makine öğrenmesi bölümünün akışı
  - Slayttaki akış (ekrandan, 00:05:00): makine öğrenmesi nedir, günlük hayattaki uygulamalar, verilerin sayısallaştırılması; ardından özellik belirleme (bilgi kazancı, sinyalin gürültüye oranı, alt küme seçiciler; temel bileşen analizi, doğrusal ayırtaç analizi), sınıflandırma metotları (doğrusal regresyon, karar ağaçları, yapay sinir ağları, k en yakın komşu, öğrenmeli vektör kuantalama), kümeleme algoritmaları (hiyerarşik kümeleme, k-means, SOM, DBSCAN), regresyon algoritmaları, çok boyutlu verilerle çalışmak, veri sızıntısı, pekiştirmeli öğrenme.
  - Bu derste ilk üç başlık işlendi; algoritmalara sonraki derslerde geçilecek, en sonda pekiştirmeli öğrenme ve yapay zekanın etikle ilişkisi ele alınacak.
- Makine öğrenmesi nedir
  - Veri miktarı arttıkça veriyi elle işlemek mümkün olmaz. Makine öğrenmesi, geçmiş veriden veriye en uygun modeli bulmaya çalışan yöntemler bütünüdür.
  - Model, veriyi çok daha küçük bir alana sıkıştırmak gibi düşünülebilir. Yeni gelen veriler bu modele göre analiz edilir.
  - Yöntemler, uygulamanın beklentisine göre sınıflandırılır: sınıflandırma, kümeleme, regresyon, pekiştirmeli öğrenme, birliktelik kurallarının keşfi.
- Sınıflandırma (ekrandan, 00:10:00 ve 00:15:00)
  - Veride özellikler ($x_1, x_2, \dots$) ve her örneğin sınıf etiketi vardır. İki boyutlu örnekte mavi ve siyah noktaları ayıran bir çizgi model olarak kullanılır; sınıfı bilinmeyen kırmızı nokta çizginin üstünde kaldığı için mavi sınıfa atanır.
  - Slayttaki tabloda 5 özellik ($x_1$–$x_5$) ve iki sınıf (A, B) vardır; yeni satır (7, 3, 2, 7, 3) için sınıf "?" olarak bırakılmıştır.
  - Kredi örneği: Bankaya başvuran müşterinin form cevapları özellikler, krediyi ödeyip ödemediği sınıftır. Banka geçmiş müşteri verisinden model kurar, yeni müşterinin sınıfını tahmin eder.
  - Özellik sayısı ve sınıf sayısı ikiyle sınırlı değildir.
- Kümeleme (ekrandan, 00:20:00)
  - Veride sınıf bilgisi yoktur; amaç örnekleri kümelere ayırmaktır. Aynı kümedeki elemanlar, diğer kümelerdeki elemanlara göre birbirine daha çok benzer.
  - Slayttaki örnekte 5 örnek 3 kümeye ayrılmıştır (küme numaraları 1, 2, 3, 1, 2). Küme sayısı örnek sayısından azdır.
  - Renk azaltma örneği: 256 renkli bir resim, RGB değerleri kümelenerek 16 renge indirilir. 256 renk için piksel başına 8 bit, 16 renk için 4 bit gerekir ($n$ bit $= 2^n$ farklı değer). Ara renkler kaybolduğu için geçişler sertleşir.
- Regresyon (eğri uydurma) (ekrandan, 00:25:00)
  - Sınıflandırmadaki çıkışlar arasında büyüklük-küçüklük ilişkisi yoktur; regresyonda çıkış sayısaldır ve büyüklük-küçüklük ilişkisi vardır.
  - Örnek: arabaların motor gücünden maksimum hızını tahmin etmek (tablo: 1500→230, 2500→280, 1600→210, 3500→290, 1200→210).
  - Veriye yakın geçen mavi doğru, uzak geçen turuncu doğrudan daha iyi modeldir; çünkü tahminle gerçek değer arasındaki farklar (hatalar) daha küçüktür.
  - Hava sıcaklığı, döviz, altın fiyatı gibi sayısal değerlerin tahmini regresyon problemidir.
- Pekiştirmeli öğrenme
  - Modele doğru çıkışın ne olması gerektiği söylenmez; yalnızca yaptığının doğru ya da yanlış olduğu söylenir.
- Birliktelik kurallarının keşfi (ekrandan, 00:30:00)
  - Sepet analizi (hangi ürünler birlikte satılıyor), raf düzenlemesi (hangi ürünler yan yana konmalı), promosyonlar (neyin yanında ne verilmeli).
  - Web sitelerinde "bunu alan bunu da aldı" önerileri de aynı mantığa dayanır. Apriori gibi algoritmalara bu derste girilmedi.
- Günlük hayattaki uygulamalar
  - Dolar kuru tahmini (ekrandan, 00:35:00): Bir günün kurunun yalnızca önceki 3 günün kuruna bağlı olduğu varsayılır. Kayan pencereyle seriden 3 girişli, 1 çıkışlı örnekler üretilir. Bu bir regresyon problemidir.
  - El yazısı / kitap yazısı tanıma (HCR/OCR) (ekrandan, 00:40:00): Her harf şeklinin hangi harf olduğunu tahmin etmek bir sınıflandırma problemidir. Rakam tanımada sınıf adlarının 0–9 olması bir şeyi değiştirmez, çünkü sınıflar arasında büyüklük-küçüklük yoktur.
  - Sınıf içi / sınıflar arası benzerlik (ekrandan, 00:45:00 ve 00:50:00).
  - E-ticaret: kitapları konularına, yazarlarına, birlikte satışlarına göre kümeleyip müşteriye öneri yapmak (ekrandan, 01:05:00).
  - Gen mikrodizilimleri: 100 kişinin gen verisinden (örneğin 10 bin özellik) kişinin hasta olup olmadığını ya da hastalık türünü tahmin etmek (ekrandan, 01:10:00). Uzaktan tıp ve e-sağlık uygulamaları.
  - Biyometri: iris (ekrandan, 01:15:00), yüz, parmak izi, ses, imza. Kişiyi tanımlama (çok sınıflı sınıflandırma) ile kişiyi doğrulama (iki sınıflı probleme indirgenir) farklıdır.
  - Ses tanıma ve konuşmayı metne çevirme (ekrandan, 01:20:00); spam tespiti (ekrandan, 01:30:00); güvenlik kamerası kayıtlarının analizi; işaret dili tanıma; sürücüsüz arabalar; mahkeme kararları; beyin aktiviteleri (ekrandan, 01:50:00).
  - Uygulamalardaki boyut ve örnek sayıları: bazı alanlarda (biyoinformatik gibi) örnek sayısı az, özellik sayısı çoktur; görüntü işlemede ikisi de fazladır (100×100'lük bir resim 10 bin boyut demektir).
- Verilerin sayısallaştırılması (ekrandan, 02:15:00 ve 02:20:00)
  - Kategorik veriler (cinsiyet, şehir, A/B/C seçenekleri) 1, 2, 3 gibi sayılarla kodlanmaz; çünkü gerçekte olmayan bir sıralama bilgisi eklenir.
  - One-hot encoding: $k$ seçenekli bir özellik $k$ ayrı özelliğe dönüştürülür. A → 1 0 0, B → 0 1 0, C → 0 0 1.
  - Resim: renkli resimde her pikselin R, G, B değerleri (3 matris), siyah-beyaz resimde gri seviyesi (1 matris).
  - Metin: harf, hece ve kelimeler genelde frekanslarına göre kodlanır (kelime frekansı tablosu).
  - Hareketli görüntü: resim bilgisine ek olarak zaman bilgisi içerir. Ses: genlik ve frekansın zaman içindeki değişimiyle kodlanır.
- Örnek sınıflandırma uygulaması: OCR (ekrandan, 02:25:00)
  - Her harf resmi 60 boyutlu bir vektöre dönüştürülür. 10 rakamın her biri için 10 farklı fontta resim varsa veri kümesi 100 örnek × 60 özellik (sınıf sütunuyla 61 sütun) olur.
  - Matris eğitim ve test kümesine bölünür; eğitim kümesi sınıflandırıcıya verilir, model oluşur; başarı, modelin hiç görmediği test kümesindeki tahminlerle gerçek sınıfların uyuşmasıyla ölçülür.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sınıflandırma ile regresyonun farkı
  - Sınıf etiketleri arasında büyüklük-küçüklük ilişkisi yoktur (A sınıfı B'den büyük değildir; "0" sınıfı "1" sınıfından küçük değildir). Regresyon çıktısında ise vardır (6.2 < 6.5).
- Kolay ve zor problem: sınıf içi ve sınıflar arası benzerlik
  - Sınıf içi benzerliğin fazla olması iyidir: aynı sınıfın örnekleri birbirine çok benziyorsa sınıfı karakterize etmek kolaydır. Kitap yazısı (OCR) bu yüzden el yazısından (HCR) kolaydır.
  - Sınıflar arası farkın fazla olması iyidir: sınıfların ortalamaları birbirinden uzaksa örnekler daha az iç içe geçer.
- Tahmin hatalarının maliyeti eşit değildir
  - Spam olan bir maili gelen kutusuna koymak yalnızca zaman kaybettirir; önemli bir maili spam diye etiketlemek çok daha zararlıdır. Sağlıkta hasta birine "sağlamsın" demek, sağlam birine "hastasın" demekten çok daha kötüdür. Algoritmalara bu tür ek bilgiler verilebilir.
- One-hot yerine ikili (binary) kodlama neden kullanılmaz
  - 5 seçenek 3 bitle kodlanabilir, ama bu durumda bazı seçenekler bazı bitlerde ortak çıkar ve aralarında gerçekte olmayan benzerlik varsayımları oluşur. One-hot kodlamada her seçenek diğerlerine eşit uzaklıktadır.
- Eğitim kümesindeki performans bir şey ifade etmez
  - Tahminleyici eğitim örneklerini ezberleyebilir (örneğin her örneği hash'leyip sınıfını bir look-up tablosunda tutarak). Asıl önemli olan, modelin daha önce görmediği test kümesindeki başarısıdır; çünkü gerçek hayatta karşılaşacağı örnekleri de daha önce görmemiş olacaktır.
- Veri miktarı
  - Konuşma tanıma bazı dillerde daha iyi çalışır; bunun önemli bir sebebi o diller için daha çok eğitim verisi olmasıdır. Örnek sayısı arttıkça tahminler güçlenir.
- Eğitim verisinin kültüre/yöreye bağlılığı
  - İngiltere havaalanı görüntüleriyle eğitilmiş bir kavga tespit sistemi, insanların birbirine daha yakın durduğu bir kültürde sarılan iki kişiyi kavga ediyor sanabilir.

## Kısa Tekrar Notları

- Makine öğrenmesi = geçmiş veriden model kurup yeni verinin çıkışını tahmin etmek.
- Sınıflandırma: ayrık etiket. Regresyon: sayısal çıkış. Kümeleme: etiket yok, gruplama. Pekiştirmeli öğrenme: yalnızca doğru/yanlış geri bildirimi. Birliktelik kuralları: sepet analizi.
- Renk azaltma: 256 renk = 8 bit, 16 renk = 4 bit.
- Dolar kuru: kayan pencereyle (D-3, D-2, D-1 → D) zaman serisinden regresyon veri kümesi.
- Sınıf içi benzerlik yüksek, sınıflar arası benzerlik düşük → kolay problem.
- Tanımlama: çok sınıflı. Doğrulama: kişi kim olduğunu beyan eder, iki sınıflı probleme iner.
- Yanlış pozitif ve yanlış negatifin maliyeti farklı olabilir.
- Kategorik veri → one-hot encoding; metin → kelime frekansları; resim → piksel matrisi.
- OCR örneği: 100 örnek × 60 özellik + 1 sınıf sütunu.
- Veri eğitim ve test kümesine bölünür; başarı test kümesinde ölçülür.

## Detaylı Açıklamalar

- **Model ve tahmin.** Sınıflandırmada model, iki boyutlu bir veride sınıfları ayıran bir çizgi kadar basit olabilir. Çizginin üstündekilere mavi, altındakilere siyah denir; sınıfı bilinmeyen bir nokta geldiğinde çizginin hangi tarafında kaldığına bakılır. Veri farklı olsaydı model de farklı olurdu; modeli belirleyen veridir. Kredi örneğinde bankanın elindeki milyonlarca geçmiş müşteri kaydı (form cevapları ve kredinin ödenip ödenmediği) eğitim verisidir. Yeni müşterinin cevapları tabloya yeni bir satır olarak eklenir ve sınıf sütunundaki "?" yerine A mı B mi yazılacağı tahmin edilir.
- **Kümelemenin bir uygulaması.** Renk azaltmada resimdeki her farklı renk RGB değerleriyle bir satırdır (256 satır, 3 sütun). Bu satırlar 16 kümeye ayrılır ve her renk kendi kümesinin rengiyle değiştirilir. Piksel başına bit sayısı 8'den 4'e iner. Bedeli görsel bozulmadır: yeşilin birçok tonu tek bir yeşile düştüğü için geçişler sertleşir. 200 renge indirmek az, 8 renge indirmek çok daha fazla bozulma yaratırdı.
- **Regresyonda "en uygun" model.** Motor gücü-maksimum hız grafiğinde her nokta için modelin tahmini ile gerçek değer arasındaki dikey fark hatadır. Veriye yakın geçen doğruda bu farklar küçük, ters eğimli turuncu doğruda büyüktür. Regresyon yöntemleri, veriye en uygun, yani hatası en küçük modeli bulmaya çalışır. Giriş tek olmak zorunda değildir.
- **Dolar kuru tahmini adım adım (ekrandan, 00:35:00).** Seri: 6.1, 6.2, 6.3, 6.3, 6.3, 6.2, 6.4, 6.1. Bir günün kurunun yalnızca önceki üç güne bağlı olduğu varsayılır (gerçekte ekonomik ve siyasi pek çok etken vardır). Üç günlük pencere birer gün kaydırılarak satırlar üretilir:
  - 6.1, 6.2, 6.3 → 6.3
  - 6.2, 6.3, 6.3 → 6.3
  - 6.3, 6.3, 6.3 → 6.2
  - 6.3, 6.3, 6.2 → 6.4
  - 6.3, 6.2, 6.4 → 6.1
  - Çıkış sayısal olduğu için bu bir regresyon problemidir. Bu kaba varsayım bile "üç gündür düşüyorsa düşmeye devam eder" gibi örüntüleri yakalayabilir.
- **Sınıf içi ve sınıflar arası benzerlik (ekrandan, 00:50:00).** Hoca tek boyutlu üç histogram çizdi. Üstteki ve ortadakinde sınıf ortalamaları arasındaki mesafe aynıdır, ama ortadakinde dağılımlar daha geniştir (standart sapma büyüktür); örnekler iç içe geçer, üstteki daha kolaydır. Ortadaki ve alttakinde dağılımların genişliği aynıdır, ama alttakinde ortalamalar daha uzaktır; alttaki daha kolaydır. Sonuçta en kolay problem, hem dar dağılımlı hem de iyi ayrılmış olan üstteki problemdir.
- **Tanımlama ve doğrulama.** Bir resmin kime ait olduğunu bulmak, elimizdeki her kişinin bir sınıf olduğu çok sınıflı bir sınıflandırmadır. Doğrulamada kişi önce kim olduğunu beyan eder (kod, isim, sicil numarası), sonra iris, parmak izi ya da ses örneği verir; sistem yalnızca "bu o kişi mi değil mi" sorusunu cevaplar. Bin kişinin sesini birbirinden ayırmak zordur; doğrulama ise problemi kolaylaştırır. İris kişiler arasında çok ayırt edicidir (hocaya göre yaklaşık milyarda bir eşleşme), parmak izi daha düşük doğruluktadır (milyonda bir), ama irisi uzaktan okumak çok zordur. Hangi verinin erişilebilir olduğu uygulamayı belirler. Yüz tanımada farklı açılar, fotoğrafın eskiliği, sakal, gözlük, şapka ve maske işi zorlaştırır.
- **İmza.** Yalnızca imzanın şekli taklit edilebilir; ama imzanın atılma süreci (çizgilerin sırası, kalemin baskısı) kişiye özgüdür ve taklit edilmesi daha zordur. Tablette attırılan imza bu süreci de kaydeder.
- **Spam tespiti.** E-posta sunucularında çalışan iki sınıflı sınıflandırıcılardır. Spamciler de sınıflandırıcıları kandırmak için makine öğrenmesi kullanır (mesajı resme koymak, görünmez karakterler eklemek, anti spam'den kaçmak için gereken kelimeleri eklemek). Dedektörler mükemmel olmadığı için spam kutusu hâlâ vardır.
- **Etik ve sorumluluk.** Sürücüsüz bir araç kaza yaptığında hatanın sensörde, donanımda ya da yazılımda olabileceği ve her birinin sorumlusunun farklı olduğu tartışıldı. Mahkeme kararlarında kuralları çok belirgin, sayısı çok fazla dava türleri için otomatik sistemler geliştirilmektedir. Beyin aktivitesinden suç tahmini, kişiyi suç işlemeden kapatmak gibi büyük bir etik sorun doğurur. Sağlık ve konum gibi verilerin paylaşılması, karşılığında elde edilen fayda büyüdükçe daha kabul edilebilir hale gelir.
- **Kategorik verinin sayısallaştırılması (ekrandan, 02:15:00).** 15. özellik A, B, C seçeneklerinden biriyse bu özellik üç ayrı özelliğe dönüştürülür: A → 1 0 0, B → 0 1 0, C → 0 0 1 (one-hot encoding; slaytta "One-hat" diye yazılmış). Seçenek sayısı 5 olsaydı 5 özellik oluşurdu. Bazı algoritmalar kategorik veriyle doğrudan çalışabilir, çoğu ise sayı bekler.
- **Metnin sayısallaştırılması (ekrandan, 02:20:00).** Her sütun bir kelimeyi, her hücre o kelimenin metinde kaç kez geçtiğini gösterir. Örnekte üç metin vardır; sınıf sütunu spam / değil bilgisini taşır. <!-- BELİRSİZ: Tablonun değerleri karede okunamadı; birinci örneğin kelime listesi küçük slayt önizlemesinden ve anlatımdan çıkarıldı. -->
  - Ör1: w1 w2 w1 w4 w5 → (2, 1, 0, 1, 1), spam
  - Ör2: w1 w3 w5 w3 → (1, 0, 2, 0, 1), değil
  - Ör3: w2 w4 w2 → (0, 2, 0, 1, 0), değil
- **OCR uygulaması (ekrandan, 02:25:00).** Kitap fotokopisinde satırların ve harflerin bulunduğu varsayılır. Her harfin siyah-beyaz resmi 60 boyutlu bir vektöre çevrilir (gri seviyede değerler 0–255 olurdu). Her örnek 60 boyutlu uzayda bir noktadır ve satırın sonunda sınıf bilgisi (örneğin "2") yer alır. 10 rakam × 10 font = 100 örnek; matris 100 × 61 olur. Örneğin 50 örnekle model kurulur, kalan 50 örnek test için ayrılır; model test örnekleri için "bu 3", "bu 7" gibi tahminler yapar ve bunların gerçek sınıflarla uyuşma oranı başarı ölçüsüdür.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
