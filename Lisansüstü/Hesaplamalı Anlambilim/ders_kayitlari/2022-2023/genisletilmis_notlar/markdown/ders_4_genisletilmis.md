# Ders 4 Genişletilmiş Notu: Dil Modellerini Değerlendirme ve Kelimelerin Anlamsal Benzerliği

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Geçen Haftanın Sorusu: 20 Kelimeden Cümle Kurmak
- 2. Dil Modellerini Değerlendirmek
- 3. Test Kümesi Seçmenin Zorluğu
- 4. Dil Modelleriyle Dizi Üretmek
- 5. Ekonomi ve Magazin Haberleriyle Üretim Örnekleri
- 6. Ardışık Geçme Yerine Aynı Dokümanda Geçme
- 7. Kelime Benzerliği: Karakter ve Anlam
- 8. Saklı Anlam İndeksleme (LSI)
- 9. Latent Dirichlet Allocation (LDA)
- 10. Kavramsal Ağaçlarla Anlamsal Benzerlik
- 11. Birbiri Yerine Kullanılan Kelimeler
- 12. Anlamsal Uzay
- 13. Birlikte Geçme Matrisleri ve Çok Boyutlu Ölçekleme
- 14. Anlamsal Uzayların Metin Sınıflandırmada Kullanımı
- 15. Sabit Koordinatların Sorunu: Çok Anlamlı Kelimeler
- Örnek Sorular
- Dersin Toparlaması

## 1. Geçen Haftanın Sorusu: 20 Kelimeden Cümle Kurmak

Geçen ders, Markov varsayımı, bigram modeliyle cümle olasılığı, bir ekleyerek yumuşatma ve üç kelimenin en olası dizilişini bulma örneğiyle bitmişti. Hoca son olarak bir soru bırakmıştı: elinizde 20 kelimelik bir kelime torbası var (aslında karıştırılmış 20 kelimelik bir cümle) ve istediğiniz $k$ değerine sahip bir istatistiksel dil modeliniz var. Bu kelimelerin hepsini kullanarak makineye anlamlı bir cümleyi nasıl kurdurursunuz?

Ders bu sorunun tartışmasıyla açıldı. Hoca önce problemi netleştirdi: üç kelime için $3! = 6$ sıralamanın her birini dil modeliyle puanlayıp en yüksek log olasılıklı olanı seçebilmiştik. $20!$ sıralama için bunu yapmak pek mümkün değildir.

Öğrencilerden gelen öneriler şunlardı:

- **Açgözlü ilerleme:** Önce kelime ikililerinin frekansları sayılır. Cümle başında en sık geçen kelime ilk kelime olarak konur; sonra birinciden sonra en sık gelen kelime eklenir ve böyle ilerlenir. Hoca bunun Markov varsayımında $k=1$ kullanmak olduğunu belirtti.
- **Farklı uzunlukta parçalar:** Büyük bir derlem üzerinde eğitilmiş bir model ile kelimelerin yan yana gelme olasılıklarına bakılır; yalnız tek tek kelimeler değil, ikili ve üçlü gibi farklı uzunluktaki parçalar da yan yana getirilmeye çalışılır.
- **Sıralama ve ağaç yapısı:** Bir başka öneri, olasılıkları bir sıralama algoritmasıyla (merge sort gibi) kullanmak ya da "bu kelimeden sonra şu veya şunlar gelebilir" diye ağaç yapısında ilerlemekti. Hoca, $20!$ olası durumun her birinin modele verilip verilmeyeceğini sordu; bu kısım netleşmedi. Öneriyi yapan öğrenci daha sonra bunu bir başlangıç değerinden başlayıp her kelimeyi uygun olduğu yere (sağına ya da soluna) ekleme diye açıkladı.
- **Cümle başı sembolünden genişleyen arama:** Cümle başı sembolüyle başlanır ve bigram istatistikleri kullanılır. Cümle başından sonra en olası 100 belirteç (token) içinde eldeki kelimelerden hangisi geçiyorsa ondan biri alınır. Hiçbiri geçmiyorsa liste ilk 200'e genişletilir; bulununca içlerinden biri rastgele seçilir. Aynı işlem eklenen her kelime için, eldeki kelimeler tükenene kadar tekrarlanır.
- **Kelime türleri:** Kelimeler önce isim, sıfat, fiil diye ayrılır; sonra kullanım istatistiğine göre sıralanır ("önemli bir hareket" ile "bir önemli hareket" karşılaştırması gibi). Hoca, 20 kelimede çok sayıda isim, sıfat ve fiil olacağını, orada ne yapılacağını sordu; cevap yine istatistiğe dayanmaktı.
- **Bağlaçlarla bölmek:** 20 kelimelik bir cümle zaten çok uzundur, büyük olasılıkla 2-3 cümlenin birleşimidir. Önce "ve", "veya" gibi bağlaçlar bulunup küçük cümleler ayrılır, sonra her biri için özne, nesne, yüklem gibi düşünülerek $k$ değeri 3-4 gibi seçilir.

Hoca tartışmayı şöyle bağladı: önerilerin çoğunda ortak fikir, belli varsayımlar yapıp arama uzayını epey daraltmaktır. Arama uzayı bu kadar büyük olduğunda her yere bakmak mümkün değildir; ama "şu kelimeler başlarda olur, şunlar sonlarda olur" ya da "ikili, üçlüleri birleştirip büyütelim" gibi varsayımlar yapılabilir. Varsayım eldeki probleme ne kadar uygunsa hızlandırma etkisi o kadar yüksek, doğru sonucu bulma olasılığı o kadar fazladır. Ancak bu varsayımları bulmak kafa yormayı gerektirir. Geçen haftaki basit soru biraz ölçeklendirildiğinde işler hemen karmaşıklaşır: kısa diziler için kolay olan şey, uzun diziler için hiç kolay değildir.

## 2. Dil Modellerini Değerlendirmek

Elimizde iki dil modeli (A ve B) olsun ve hangisinin daha iyi olduğunu bulmak isteyelim (ekrandan, 00:30:00). Şu ana kadar yalnız istatistiksel dil modellerinden söz ediliyor, sinirsel yapılara henüz geçilmedi. Ancak burada anlatılan iki yaklaşım, sinirsel olanlar da dahil herhangi iki dil modelini karşılaştırmak için de kullanılır.

### 2.1 Harici yöntem

Harici yöntemde iki model de farklı görevlerde kullanılır ve o görevlerdeki performanslarına göre karşılaştırılır. Dil modeli kendi başına değil, bir temsil yöntemi olarak başka bir uygulamanın içinde kullanılır. Slayttaki görevler makine çevirisi, yazım düzeltme ve konuşmadan metne çevirmedir.

### 2.2 Dahili yöntem

Dahili yöntemde derlem eğitim ve test kümesi olarak ayrılır; A ve B eğitim kümesi üzerinden oluşturulur. Dil modelleri temelde bir cümlenin olasılığını, yani bu cümlenin bu derlemde geçme olasılığını bulabilir. Hoca, bunun sinirsel dil modellerindeki karşılığının perplexity olduğunu söyledi.

Test kümesindeki cümleler gerçek cümlelerdir. Bir modelin gerçek bir cümleye yüksek olasılık vermesini isteriz. Dolayısıyla:

- Test kümesindeki cümlelere hangisi daha yüksek olasılık veriyorsa o daha iyidir.
- Tersinden de bakılabilir: gerçek olmayan cümlelere hangisi daha düşük olasılık veriyorsa o daha iyidir. Gerçek olmayan cümle elle oluşturulabilir: var olan cümleler karıştırılır, iki cümle ortadan kesilip birinin başı ötekinin sonuyla birleştirilir ya da bu dörtlü, beşli yapılır. Model böyle bir şeye "böyle cümle mi olur" demelidir; her şeye "tamam" dememelidir.
- Bir cümlenin başı verildiğinde sonunu hangisi doğru tahmin ediyorsa o daha iyidir.

Cümle olasılığını bulmak ile bir diziden sonrasını tahmin etmek aynı mekanizmayla ve aynı verilerle çalışır. "Bu diziden sonra ne gelir?" sorusunun cevabı aslında sözlük boyutlu bir olasılık dağılımıdır: 40 bin kelimelik bir sözlükte, o diziden sonra 40 bin kelimenin her birinin gelme olasılığı bulunur.

Slaytta bir soru daha vardı: bu görevlerde Markov varsayımında $k=0$ seçimi nasıldır? Hoca kısaca, $k=0$ kullanılırsa pek iyi bir şey elde edilemeyeceğini söyledi (bkz. Örnek Sorular).

> **Ek bilgi (derste anlatılmadı):** Perplexity, bir modelin test kümesine verdiği olasılığın kelime başına geometrik ortalamasının tersidir: $PP(W) = P(w_1,\dots,w_N)^{-1/N}$. Düşük perplexity, modelin test metnine yüksek olasılık verdiği anlamına gelir. Bu ölçü sinirsel modellerde yaygın olduğu gibi n-gram modellerinin karşılaştırılmasında da büyük olasılıkla standart ölçüdür.

## 3. Test Kümesi Seçmenin Zorluğu

Hoca, derlem çok büyük olduğunda ve özellikle webden toplandığında, içinden iyi bir test kümesi seçmenin hiç kolay olmadığını vurguladı ve nedenini sordu.

Öğrenciler önce cümle uzunluklarının ve içeriklerin farklı olabileceğini, rastgele seçilen parçanın kalite olarak kötü bir yere denk gelebileceğini söyledi. Hoca bunların olabileceğini ama aradığı cevap olmadığını belirtti. Bir öğrenci bir kez değil birden çok kez örnek seçmeyi, yani çapraz geçerlemeyi önerdi. Hoca birden çok test kümesi kullanmanın iyi olabileceğini kabul etti, ama burada standart çapraz geçerlemenin pratikte zor olduğunu açıkladı: 1 GB metin 10 parçaya bölünürse her seferinde 900 MB ile eğitim yapılıp 100 MB üzerinde test edilir. Metin verisinde bu boyutta sıfırdan eğitim çok uzun sürer; bunu 10 kez yapmak kolay değildir.

Asıl sorun ise içeriklerin aynı olabilmesidir. Test kümesi diye seçilen içeriğin eğitim kümesinde de yer alması kesinlikle istenmeyen bir durumdur, çünkü model "kopya çeker". Webden toplanan veride bundan emin olmak zordur:

- Bir haber 30 haber sitesinde aynı şekilde, ya da kırpılmış ve çok benzer biçimde geçer.
- Bir ürünü birçok satıcı aynı metinle satar.

Webde tekrarlı veri çok fazladır. Bu yüzden derlemi ve test kümesini oluştururken buna çok dikkat etmek gerekir.

> **Hocanın vurgusu:** Bu durum hocanın ekibinin başına daha önce çok gelmiş. Test kümesinde mükemmel sonuçlar alınır, "nasıl bu kadar mükemmel olur" diye bakılır ve test verisinin aslında eğitim kümesinde de bulunduğu görülür. Bu, modele çok büyük ve haksız bir performans artışı sağlar.

## 4. Dil Modelleriyle Dizi Üretmek

İstatistiksel dil modelleriyle cümle ya da dizi üretilebilir. $k$ değerine göre ayrıntılar değişir, ama genel fikir şudur: bir ilk kelime seçilir, sonraki kelimeler dil modeliyle belirlenir. Örneğin A'dan sonra B seçilir; sonra AB verilip ardından ne geleceği tahmin edilir, diyelim C; sonra ABC verilip devam edilir. Model kendi tahminini girdisine ekler; hoca bunun için "otoregresif" terimini kullandı.

### 4.1 Hep en olasıyı seçmenin sorunu

$k=0$ için her zaman en yüksek olasılıklı kelime seçilirse aynı kelime sürekli tekrar eder. $k=0$'da hiçbir kelime kendinden öncekilere bağlı değildir; her kelimenin yalnız kendi tek başına olasılığı vardır ve bu, önceki kelimelere göre değişmez. Dolayısıyla en olası kelime hep aynıdır. $k=1$ için de benzer şekilde, bir kelimeden sonra hep aynı kelime gelir.

### 4.2 İki çözüm

Hoca bunu aşmanın iki yolunu anlattı ve bir tablo üzerinde gösterdi (ekrandan, 00:37:50). Sözlükte 100 kelime olsun; derlemin kendisi çok uzun ama tekil kelime sayısı 100. $W_1 W_2 W_3$ dizisinden sonra gelecek kelimenin olasılıkları tabloda şöyledir:

| kelime | P |
|---|---|
| $W_1$ | 0.001 |
| $W_2$ | 0.002 |
| $w_3$ | 0.001 |
| … | … |
| $w_{99}$ | 0.02 |
| $W_{100}$ | 0.00003 |

- **En olası $t$ taneden rastgele seçmek:** 100 kelime olasılıklarına göre sıralanır, en yüksek $t$ tanesi alınır ve bunların içinden rastgele biri seçilir.
- **Olasılıklarla seçmek:** Hoca öğrencilere tablodaki P'lerin toplamını sordu; cevap 1'dir. Demek ki bu bir olasılık dağılımıdır ve seçim doğrudan bu olasılıklarla yapılabilir: en yüksek 5 taneden rastgele seçmek yerine her kelime kendi olasılığıyla seçilir.

İkisinin de kendine göre avantajları vardır. Üretim, istenen sayıda kelime ya da cümle üretildiğinde veya cümle sonunu ifade eden bir belirteç varsa ona ulaşıldığında durdurulur.

## 5. Ekonomi ve Magazin Haberleriyle Üretim Örnekleri

### 5.1 Bigram ($k=1$) ile ekonomi haberi

Örneğin kodu dersin sitesindedir (`dil_modeli.m`) (ekrandan, 00:40:00). Model bigramdır ($k=1$): her kelime yalnız kendinden bir öncekine bağlıdır. Her adımda en olası $t$ kelimeden biri rastgele seçilir; burada $t=5$'tir. $t$ ne kadar küçültülürse metinlerden kopya çekme, yani derlemdeki aynı diziyi üretme olasılığı o kadar artar; çok büyütülürse anlamlı şey üretme olasılığı o kadar azalır. Derlem yalnız 1000 ekonomi haberinden (gazete haber metinlerinden) oluşmuştur. Üretilen örnekler:

- "fonların yüzde 5 de bu konuda son 10 ın da çok sayıda türk telekom gibi çok önemli olduğunu belirten bakan şimşek 2012 nin."
- "mesleki eğitim ve ticaret bakanlığı ın piyasa ile ilgili olarak belirlendi bu nedenle bir önceki yıla da en fazla artış oranı ise lira oldu bu."
- "akademik araştırmalar sonucunda yer aldığı bilgiye göre bir şekilde diyen ve yüzde 10 yılda bir süre içerisinde türkiye istatistik verilerine borsa seçimlerinin dikkati çekti türkiye."

Hoca şunu sordu: size böyle metinler verip "bunlar istatistiksel bir dil modeliyle üretildi, modelin $k$ değeri nedir?" desem söyleyebilir misiniz? $k=1$ olduğunun güzel kanıtı şudur: ardışık kelimeler (ikililer) anlamlıdır, ama ardışık üçlüler anlamlı değildir. Örneğin "yüzde 10" kendi başına anlamlıdır, "10 yılda" da anlamlıdır, ama "yüzde 10 yılda" anlamsızdır. Model "yüzde"den sonra "10"u, "10"dan sonra "yılda"yı seçer; ama "yüzde 10"dan sonra "yılda" gelmez. Benzer biçimde "yer aldığı" ve "aldığı bilgiye" anlamlı, "yer aldığı bilgiye" anlamsızdır. Slayt bunu "first order ($k=1$) yapının problemi bariz görünüyor" diye özetler.

### 5.2 Trigram ($k=2$) ile ekonomi ve magazin haberi

İkinci örnekte (`dil_modeli_second.m`) trigram ($k=2$) modeli ve $t=5$ kullanılır (ekrandan, 00:42:15). 1000 ekonomi haberiyle üretilen cümleler:

- "yaşanan sıkıntıları için devamlı ucuz bilet satıyoruz 100 90 ı aslında biz bu bitireceğiz inşallah yıl sonuna kadar türkiyede üretilen fazlasını belirterek geçen yıl kasım ayı ihracatını"
- "birlikte fiyatlardaki üzerindeki etkileri takip edilecek gerek halinde düzenlemede birtakım yeni getirilecek talepler daha önceki bir açıklamasında 2012 yılının ilk 2 ihaleyi 500 adet olacak satış faaliyet"

Ardışık üçlüler artık daha anlamlıdır ("ucuz bilet satıyoruz", "Türkiye'de üretilen fazlasını belirterek"). Mükemmel bir şey beklemek doğru değildir, ama metin biraz ekonomi haberine benzemeye başlamıştır. Yine de ortada yalnız ardışık anlamlı üçlüler vardır; bir haber, bir cümle yoktur.

> **Hocanın vurgusu:** Cümle bir birlikteliktir: bir cümlenin bütün parçaları birbirine bağlıdır ve hepsi birlikte bir anlam oluşturur. Burada ise en iyi ihtimalle üç kelimenin anlamlı birliktelikleri vardır. İçinde şans eseri güzel ifadeler geçebilir, ama cümle demek mümkün değildir. Bunu elde etmek için $k$'nın çok daha fazla artırılması gerekir.

Aynı mekanizma 1000 magazin haberiyle çalıştırıldığında, örneğin "oyuncuların eğitimi yoktu ama hep başka şeyler yapmak için burada bu arkadaşlar benim dönüş ve benim gibi tabii ki oldu ama devam çok bir adam alman sevgilisiyle" gibi magazin havasında diziler üretilir. Mekanizma tamamen aynıdır; değişen yalnız derlemdir.

## 6. Ardışık Geçme Yerine Aynı Dokümanda Geçme

Üçüncü örnekte (`dil_modeli_term_doc.m`) farklı bir şey yapılır (ekrandan, 00:44:50): olasılık hesabında ardışık geçme yerine aynı dokümanda geçme kullanılır. Yani "şu kelimeden sonra şu kelimenin gelme olasılığı" iki kelimenin arka arkaya geçişiyle değil, kaç dokümanda bir arada bulunduklarıyla hesaplanır. Aynı dokümanın farklı yerlerinde geçseler bile birlikte geçmiş sayılırlar.

Burada frekansı çok yüksek kelimeleri (stop word) atmak gerekir. Bu kelimeler bütün metinlerde geçtiği için atılmazsa her kelimeye en benzer kelimeler onlar olur.

$k=1$ ve $t=15$ ile üretilen cümle şöyledir: "faiz oranı yüksek yönetim kurumsal yönetim kurulu genel 2 satış 5 enflasyon merkez cari kredi yapı nın türk türkiyenin ancak cari büyüme merkez bankası merkez cari." Cümle üretimi için bu hiç iyi değildir; yalnız birlikte geçen kelimeleri sıralar. Hoca bunun bir anahtar kelime çıkarımına (keyword extraction), yani bir metnin ana noktalarını çıkarmaya benzediğini söyledi.

Buna karşılık "faiz"e en benzeyen kelimeler "merkez", "kredi", "bankası", "oranı" ve "cari"dir. Bunlar faizden önce ya da sonra gelmeye göre değil, faizle aynı dokümanda en çok geçmeye göre hesaplanmıştır ve anlamca gayet makul görünür. Aynı dokümanda geçme fikri, ileride benzer anlamlı kelimeleri bulmak için kullanılacaktır.

## 7. Kelime Benzerliği: Karakter ve Anlam

Bu noktadan sonra ders kelime benzerliğine geçti. İstatistiksel dil modelleri, şu anki hâlleriyle, bir kelimenin başka bir kelimeye benzerliği konusunda pek bir şey söylemez; kabaca ardışık olma üzerinden, "şu diziden sonra ne gelir" sorusu üzerinden çalışırlar. Peki iki kelimenin benzerliğini bulmak için neler yapılabilir, bugüne kadar neler yapılmıştır?

### 7.1 Karakter benzerliği

İlk ve standart yaklaşım karakter benzerliğidir, yani edit distance: bir kelimeyi diğer kelimeye dönüştürmek için kaç kez klavye tuşuna dokunmak gerekir? Hoca Levenshtein distance'ı bunun biraz ağırlıklandırılmış hâli olarak tanıttı: karakter silmenin, eklemenin ya da yanlış karakteri düzeltmenin ağırlıkları farklı verilebilir. Örnekler dersin sayfasındadır.

> **Ders sonrası not:** Hoca Levenshtein distance'ı edit distance'ın ağırlıklandırılmış hâli olarak anlattı. Yaygın tanımda Levenshtein distance, ekleme, silme ve değiştirme işlemlerinin her birine 1 maliyet veren standart edit distance'tır; işlemlere farklı ağırlık veren biçimler büyük olasılıkla bunun genellemeleri (ağırlıklı edit distance) olarak anılır.

### 7.2 Anlam benzerliği

Asıl ilgilenilen şey anlamsal benzerliktir. Burada karakter benzerliği hiçbir işe yaramaz. "Cimbom" ile "Galatasaray" arasında bir ilişki olduğunu biliriz, ama karakter düzeyinde aralarında hiçbir benzerlik yoktur; Levenshtein uzaklığına bakılırsa birbirlerinden çok uzaktırlar. Bunun gibi pek çok örnek verilebilir.

## 8. Saklı Anlam İndeksleme (LSI)

Aradan sonra hoca, anlatacağı yöntemlerin bir açıdan tarihçe olduğunu söyledi: bugünkü yöntemlere gelinceye kadar hangi problem nasıl çözülmeye çalışılmış, getirilen çözüm neyi kapatmış, neyi kapatamamış? Bu tür işler bir öncekinin eksiklikleri üzerine bina edilerek ilerler. Anlatılan yöntemlerin sırası birebir tarihsel sıra değildir, ama ona yakındır.

İlk yöntem Saklı Anlam İndeksleme'dir (Latent Semantic Indexing, LSI). Slayttaki tanım: kelimelerin ardındaki saklı kavramları ortaya çıkarıp dokümanları bu kavramlar uzayında temsil etmek (ekrandan, 01:20:00).

### 8.1 Terim-doküman matrisi

Hoca terim-doküman matrisinin her hücresinin ne anlama geldiğini sordu; cevap gelmeyince bir örnek kurdu (ekrandan, 01:10:00). Elimizde metinler olsun ve bunlar belirteçlere (token) bölünmüş olsun. Belirteçler kelime, alt kelime ya da karakter olabilir; burada $W$ ile gösterilir. Dört doküman:

- D1: W1 w3 w5 w4
- D2: W2 w4 w5
- D3: W6 w8 w3
- D4: w7 w3 w4

Sözlük: W1 w2 w3 w4 w5 w6 w7 w8. Her dokümanda geçen kelimeler işaretlenince şu matris çıkar:

| | D1 | D2 | D3 | D4 |
|---|---|---|---|---|
| W1 | 1 | | | |
| W2 | | 1 | | |
| W3 | 1 | | 1 | 1 |
| W4 | 1 | 1 | | 1 |
| W5 | 1 | 1 | | |
| W6 | | | 1 | |
| W7 | | | | 1 |
| W8 | | | 1 | |

Bu tablo terim-doküman matrisidir. $i,j$ hücresinin değeri, $i$. terimin $j$. dokümanda geçip geçmediğidir (1/0) ya da kaç kez geçtiğidir; iki yaklaşım da kullanılır.

**Soru:** Dört haber metniyle bir sözlük oluşturup bu matrisi kursak nasıl bir matris olur? **Cevap:** Öğrenciler matrisin boyutunun büyük olacağını, kelime sayısının çok fazla olacağını söyledi (dört haber metninde 500 farklı kelime geçerse $500 \times 4$'lük bir matris) ve matrisin seyrek (sparse) olacağını ekledi. Hoca bunu onayladı: sözlük boyutu kolaylıkla binlere, on binlere çıkar; her dokümanda ise bu on binlerce kelimenin çok azı, belki iki-üç yüz tekil kelime bulunur. Seyrek matris, bol miktarda sıfır içeren matris demektir.

### 8.2 Kelimeler ve dokümanlar birer noktadır

Bu matriste her kelime dört boyutlu bir uzayda bir noktadır. Örneğin birinci kelimenin birinci boyutu 1, diğer boyutları 0'dır; ikinci kelimenin yalnız ikinci boyutu 1'dir. Hepsi aynı uzaydadır. Matrisin transpozu alınırsa bu kez dokümanlar, sözlük boyutlu (burada 8 boyutlu) bir uzayda noktalar olur.

Gerçek bir derlemde, yüz binlerce haber metni ya da web sayfası düşünülürse, hem doküman sayısı hem sözlük boyutu korkunç boyutlara ulaşır. Dokümanları temsil eden uzay da, kelimeleri temsil eden uzay da çok büyük boyutlu ve (özellikle frekansı düşük kelimeler için) seyrek olur.

### 8.3 Tekil değer ayrıştırması (SVD)

Hoca LSI'ın kendisinin doğal dil işlemeyle doğrudan bir ilgisi olmadığını, aslında tekil değer ayrıştırmasının (Singular Value Decomposition, SVD) NLP'ye uygulanması olduğunu söyledi. LSI bir NLP kavramıdır, ama kullandığı yöntem tamamen matematikseldir: bir matrisi çarpanlarına ayırmak.

Slayttaki şema (ekrandan, 01:20:00):

$$A_{m\times n} = U_{m\times r}\; D_{r\times r}\; V^T_{r\times n} \;\Rightarrow\; U_k\,(m\times k)\;\; D_k\,(k\times k)\;\; V^T_k\,(k\times n) = \hat{A}_k\,(m\times n)$$

Burada $A$ terim-doküman matrisidir (satırlar terimler, sütunlar dokümanlar), $D$ ise slaytta $\Sigma$ ile de gösterilen köşegen matristir. SVD'nin güzel tarafı kare olmayan matrisleri de çarpanlarına ayırabilmesidir; yalnız kare matrisler için çalışan ayrıştırma yöntemleri de vardır.

Amaç, matrisin içindeki bütün değişkenliği ifade edebilecek çok daha alt boyutlu bir temsil bulmaktır: terimleri doküman sayısı boyutlu bir uzaydan çok daha küçük bir boyuta indirgemek. $r \times r$'lik orta kısım terimlerin yer aldığı uzayı temsil eder. $r$, çok daha küçük bir $k$'ya indirgenebilir; böylece hem dokümanlar hem terimler, doküman sayısı ya da sözlük boyutu boyutlu dev uzaylar yerine çok daha küçük uzaylarda temsil edilir (yeterli veri varsa).

Orta matris köşegendir: iki yanı sıfırlarla doludur, sol üst köşede en büyük değer bulunur ve aşağı doğru küçülür. Köşegenin sonlarında bir sürü sıfır olabilir. Örneğin $k=100$ iken son 30 değer sıfırsa, aynı şey 70 boyutlu bir uzayda temsil edilebilir. Hoca bunu PCA'ya benzetti ve buradaki değerleri önce tekil değerler, sonra "daha doğrusu öz değerler (eigenvalues)" diye andı.

> **Ders sonrası not:** Hoca köşegendeki değerleri "daha doğrusu eigenvalue'lar" diye düzeltti. SVD'de bu değerler tekil değerlerdir; $A^TA$ (ya da $AA^T$) matrisinin öz değerlerinin karekökleridir. PCA ile bağlantı bu ilişkiden gelir.

### 8.4 Kedi/köpek örneği

Hoca küçük bir örneği kodla gösterdi (ekrandan, 01:18:15). İki sınıfa ait dokümanlar vardır: 1. sınıf kedi, 2. sınıf köpek. Sütunlardaki kelimeler: kedi, miyav, süt, fare, köpek, havla, kemik, hayvan, tüy. Satırlar dokümanlardır:

```text
% kedi miyav süt fare köpek havla kemik hayvan tüy
D=[ 1    1    0   0    0     0     0     0     0 ; % kedi sinifi
    1    0    1   0    0     0     0     0     0 ; % kedi sinifi
    0    0    1   0    0     0     0     1     0 ; % kedi sinifi
    1    0    0   0    0     0     0     0     1 ; % kedi sinifi
    0    0    0   0    1     1     0     0     1 ; % köpek sinifi
    0    0    0   0    1     0     0     1     0 ; % köpek sinifi
    0    0    0   0    0     1     1     0     0 ; % köpek sinifi
    0    0    0   0    1     0     1     1     0 ]; % köpek sinifi

D=D';          % matrisin kelime*dokuman olmasi gerek
[U,S,V] = svd(D);
%D = U*S*V'
%D 9*8 kelime*dokuman
%U 9*9 kelime*kavram
%S 9*8 singular values
%V 8*8 dokuman*kavram
```

Örneğin birinci dokümanda "kedi" ve "miyav", ikincide "kedi" ve "süt" geçer; dört kedi, dört köpek dokümanı vardır. Sınıf bilgisi yalnız yorum olarak yazılmıştır; SVD gözetimsiz (unsupervised) bir yöntemdir ve sınıf bilgisine hiç ihtiyacı yoktur.

Doküman-terim matrisi transpoz edilip terim-doküman (kelime-doküman) matrisine çevrilir ve SVD'ye verilir. SVD üç çarpanı verir. NLP'deki yorumlarıyla: $D$ $9\times 8$'lik kelime-doküman matrisidir, $U$ kelime-kavram matrisini, $S$ tekil değerleri, $V$ ise doküman-kavram ilişkisini ifade eder.

SVD'nin kendisi doğrudan kullanılabilir ya da daha düşük bir boyuta indirgenebilir. Örneğin $r=5$ seçmek, $U$, $S$ ve $V$'nin yalnız gerekli ilk kısımlarını işe katmak demektir. Bu örnekte yalnız ilk beş tekil değer alınmış ve yeni doküman matrisi yine bu çarpımlarla oluşturulmuştur. Sonra dokümanların birbirine uzaklıkları bir ağaç (dendrogram) üzerinde gösterilmiştir.

Orijinal uzaydaki ağaçta (ekrandan, 01:21:10) 6 ve 8 numaralı dokümanlar ilk birleşir, diğerlerinin çoğu aynı yükseklikte birleşir; yani gruplar belirgin değildir. 9 boyuttan 5 boyuta indirgendiğinde aradaki benzerlikler çok daha iyi görülür: 1, 4, 2, 3 bir arada, 5, 7, 8, 6 bir arada toplanır. 1-2-3-4 kedi, 5-6-7-8 köpek sınıfıdır. Sisteme "bunlar kedi, bunlar köpek" diye hiçbir bilgi verilmemiştir; buna rağmen yöntem bu ayrımı fena olmayan bir şekilde bulur.

### 8.5 Büyük ölçekte LSI

Aynı işlem 8 kelime, 9 doküman yerine iri bir veri kümesine uygulanınca (kod: `lsi_modeli.m`) kelimelerin koordinatları elde edilir. Hoca kelimelerin ilk iki koordinatını çizdirdi. Büyütülen bölgelerden birinde "başrol", "demet", "intikam", "duygu", "aksu" gibi magazinsel kelimeler, mavi bölgede ise "enerji", "gaz", "şirket" gibi ekonomiyle ilgili kelimeler vardı. Derlem büyük olasılıkla yine haber metinleriydi. Magazin haberlerindeki kelimelerin koordinatları, ekonomi haberlerindekilerden belli bir miktar ayrılır.

Burada olan şudur: kelimeler koordinatlara dönüşmüştür. Aslında terim-doküman matrisinde de kelimeler bir koordinat sistemindedir; ama bu sistem aşırı seyrektir, belki yalnız 1 ve 0'lardan oluşur ve çok büyük boyutludur. Orada iki kelimenin benzerliğini hesaplamak makul değildir. Belirteçlerin temsil uzayı 20-30 bin boyuttan çok daha küçük bir uzaya (hoca bu örnekte belki 50 boyut olduğunu, kesin sayının kodda görülebileceğini söyledi) sıkıştırılınca, yalnız ilk iki koordinata bakıldığında bile anlamsal yakınlıklar göze çarpmaya başlar.

## 9. Latent Dirichlet Allocation (LDA)

LSI'a çok benzeyen bir başka yöntem Latent Dirichlet Allocation'dır (LDA), yani konu modelleme (topic modelling) (ekrandan, 01:25:15). Slayttaki iki ilke:

- Konular kelimelerin karışımıdır.
- Dokümanlar konuların karışımıdır.

Hoca bunu SVD'nin üçlü, iç içe geçmiş bir hâli gibi düşünmeyi önerdi. Bir metnin içinde belli konular vardır; her konu belli kelimelerden oluşur ve her kelimenin o konuya ait olma olasılığı vardır. Slayttaki şekilde solda konular ve her konunun en olası kelimeleri (örneğin gene, dna, genetic; life, evolve, organism; brain, neuron, nerve; data, number, computer), ortada bu konulardan oluşan bir doküman, sağda ise dokümanın konu oranları gösterilir. Fark şudur: SVD'de dokümanlar yalnız kelimelerin birlikteliklerinden oluşur; LDA'da ise kelimeler konuları, konular dokümanları oluşturur. Bir kelime bir ya da birden fazla konuya ait olabilir.

LDA çalıştırıldığında (kod: `lda_modeli.m`) konular ve her konuyu en iyi temsil eden kelimeler görülür. Hocanın gösterdiği örnekte bir konu magazinle, bir konu ekonomiyle, bir başkası otomobil ve şirketle ilgiliydi. LDA bir dönem çok popüler olmuş, ama sonra pek iyi gitmemiştir.

<!-- BELİRSİZ: 01:25:29-01:25:52 arasında hocanın LDA'nın neden iyi gitmediğine ve hızlı işlemeye dair cümlesi altyazıda bozuk; yalnız "bir ara popüler olmuştu, sonra iyi gitmedi" kısmı net. -->

> **Ek bilgi (derste anlatılmadı):** LDA üretici (generative) bir olasılık modelidir: her doküman için konu oranları ($\theta$) bir Dirichlet dağılımından çekilir; dokümandaki her kelime için önce bir konu ($z$), sonra o konunun kelime dağılımından ($\beta$) bir kelime seçilir. Slayttaki $\theta_{dk}$, $z_{dn}$ ve $\beta_{ki}=p(w \mid z)$ gösterimleri bu üç bileşene karşılık gelir.

Hoca bu yaklaşımların ortak noktasını şöyle özetledi: terimler çok büyük boyutlu seyrek uzaylardan daha yoğun (dense) uzaylara taşınır. Bir kelimenin bir koordinat sistemindeki bir noktayla temsil edilmesi konusuna tekrar dönülecektir; ama önce tarihsel olarak daha eski yöntemlere bakılır.

## 10. Kavramsal Ağaçlarla Anlamsal Benzerlik

### 10.1 Kavramsal ağaç

Eskiden kavramsal ağaçlar kullanılmıştır. Kavramsal ağaç, bütün kavramların "şu bir tür şudur" (IS-A) ilişkisiyle birbirine bağlandığı bir ağaçtır. En tepede belki "şey" vardır, altında somut şeyler ve soyut şeyler, onların altında alt kategoriler. Kedi, köpek, kuş, televizyon, bilgisayar, her şey bu ağacın içindedir: hayvanların altında alt kategorileri, eşyaların altında alt kategorileri vardır. Böyle bir ağaç elimizde olsa, iki kelime arasındaki anlamsal benzerliği bulabilir miyiz?

Geçmişte iki yaklaşım geliştirilmiştir: yalnız ağacı kullanmak; ağaçla birlikte harici bir derlem kullanmak. Hoca derlemlerin öneminin geçmişten beri bilindiğini de ekledi.

### 10.2 WordNet ve synset

Formüllerde geçen "synset" kavramı WordNet'ten gelir. WordNet bir sözlüktür, ama bilgisayarlarca daha kolay işlenebilen bir sözlüktür. Önceki haftalarda konuşulan "şu kavramla şu kavram arasında şöyle bir ilişki vardır" üçlüleri WordNet'te de bulunur. Ancak kavramlar tek başlarına değil, synset (synonym set, eş anlamlı küme) denen kümeler içinde bulunur: birbiriyle aynı anlama sahip kelimeler bir küme oluşturur ve kümelerin kimlikleri (id) vardır.

İlişkiler synset'ler arasında kurulur. Bu, yerden kazandırır: kümenin içindeki her kelimenin, öteki kümedeki her kelimeyle o ilişkiye sahip olduğunu ayrı ayrı yazmak gerekmez. Öte yandan bir kelime birden fazla anlamı varsa, her anlamını ifade eden kümede yer alır; yani birden fazla synset'te bulunabilir.

### 10.3 Leacock & Chodorow (1998)

Leacock ve Chodorow'un iki kavram ($c_1$, $c_2$) arasındaki anlamsal benzerlik için önerdiği formül (ekrandan, 01:30:00):

$$sim_{LC}(c_1,c_2) = -\log \frac{len(c_1,c_2)}{2L}$$

- $len(c_1,c_2)$: iki synset arasındaki en kısa yolun uzunluğu, yani ağaç üzerinde bir noktadan ötekine en az kaç adımda gidilebildiği. Benzerlik değeriyle ters orantılıdır.
- $L$: bütün taksonominin (ağacın) derinliği.

<!-- BELİRSİZ: Slaytta kesrin paydası açılan yazı tipi araç çubuğunun altında kaldı; $2L$ yöntemin bilinen tanımından yazıldı. Hoca "L tüm taksonominin derinliği, bu aşağıya gidiyor" dedi. -->

Önündeki eksi işareti benzerliği verir; eksi kullanılmazsa bu bir uzaklık olur. Fikir şudur: ağaç üzerinde bir noktadan ötekine ne kadar hızlı gidilebiliyorsa aralarındaki anlamsal bağ o kadar güçlüdür. Kedi ile köpeğin ağaçtaki yerlerini, bir de kedi ile anahtarınkini düşünün. Kedi ile köpek, çok fazla yukarı çıkmadan birleştirilebilir; kedi ile anahtar için çok yukarı çıkmak gerekir.

### 10.4 Wu & Palmer (1994)

Wu ve Palmer'ın 1994'te önerdiği yaklaşım buna çok benzer (ekrandan, 01:33:00):

$$sim_{WP}(c_1,c_2) = \frac{2 \times N_3}{N_1 + N_2 + 2 \times N_3}$$

- $N_1$ ve $N_2$: $c_1$ ve $c_2$'nin en yakın ortak üst synset'lerine ($lcs(c_1,c_2)$) IS-A bağlarıyla uzaklıkları (benzerlik değeriyle ters orantılı).
- $N_3$: en yakın ortak üst synset'in kök synset'e IS-A bağlarıyla uzaklığı. Büyüklüğü ortak üst synset'in spesifikliğini gösterir; benzerlikle doğru orantılıdır.

$lcs$ (least common subsumer), iki kavramın en yakın ortak üst synset'idir. Ağaçta daha yukarıdaki düğümler de bu ikisinin ortak üst kavramıdır (hepsi zaten bir şeyin türüdür), ama en yakını şekildeki kırmızı düğümdür.

**Soru:** En yakın ortak üst synset köke yakın olursa mı iki kavramın anlamları birbirine yakın olur, kökten uzak olursa mı? **Cevap:** Bir öğrenci "kökten uzak olursa" dedi; hoca onayladı. Ortak üst kavram kökten ne kadar uzaksa o kadar spesifik bir anlamdan söz edilir; köke ne kadar yakınsa o kadar büyük bir kavram kümesinden söz edilir. Bu yüzden $N_3$ benzerlikle doğru orantılıdır. $N_1$ ve $N_2$ ise paydada normalizasyon için yer alır ve küçük olmaları gerekir: kavramlar ortak üst synset'e yakın olmalıdır. Ne kadar uzak bir yerde birleşirlerse anlamca o kadar uzaktırlar.

### 10.5 Jiang-Conrath (1997) ve Lin (1998)

Hoca bu iki yaklaşımı birbirine çok yakın oldukları için birlikte anlattı. Önceki iki yaklaşım (1994 ve 1998) yalnız ağaçtan söz eder ve ağacın dışında hiçbir bilgi kullanmaz. Bu ikisi ise bir derlem kullanır ve bir kavramın derlemdeki olasılığından söz eder. Bu, bir kelimenin derlemde geçme olasılığına benzer, ama olasılık ağaç da kullanılarak hesaplanır:

$$p(c) = \frac{freq(c)}{freq(root)}$$

Buradaki $freq(x)$, derlemde $x$ synset'inin tepesinde bulunduğu bütün synset'lerin frekanslarının toplamıdır: $x$'in kendisinin ve altındaki bütün alt synset'lerdeki kavramların derlemde kaç kez tekrar ettiğinin toplamı ($F_x + F_{x_1} + F_{x_2} + F_{x_{21}} + F_{x_{22}} + \dots$ gibi). Örneğin "eşya" kavramının frekansı, altındaki çanak, çömlek, kaşık, televizyon, araç gibi her şeyin frekanslarının toplamıyla bulunur. Yani yalnız kelimenin kendi geçme sayısı değil, altındaki her şeyin geçme sayısı birlikte düşünülür.

**Soru:** Kökün frekansı nedir? **Cevap:** Bir öğrenci, bütün ağaçtaki kelimelerin frekanslarının toplamı olduğunu söyledi; hoca onayladı ve derlemle ağaç aşağı yukarı birbirini karşılıyorsa bunun derlemdeki bütün kelime sayısına yakın olacağını ekledi.

Böylece bir kavram ne kadar genelse olasılığı o kadar yüksek olur. Bu olasılıkla iki formül tanımlanır (ekrandan, 01:40:00):

$$sim_{JC}(c_1,c_2) = 2\log\big(p(lcs(c_1,c_2))\big) - \big(\log p(c_1) + \log p(c_2)\big)$$

$$sim_{L}(c_1,c_2) = \frac{2\log\big(p(lcs(c_1,c_2))\big)}{\log p(c_1) + \log p(c_2)}$$

Slayttaki gösterimle $A = 2\log p(lcs(c_1,c_2))$ ve $B = \log p(c_1)+\log p(c_2)$ olmak üzere Jiang-Conrath $A-B$, Lin $A/B$ kullanır. Slayttaki açıklama:

- $A$, her iki kavramı da içeren en spesifik kavramı kullanır (iki kavramın beraber geçtiği doküman sayısına benzer).
- $B$, iki kavramdan herhangi birini içeren doküman sayısına benzer.

> **Ders sonrası not:** Slayttaki $sim_{JC}$ ifadesi $2\log p(lcs) - \log p(c_1) - \log p(c_2)$, bilgi içeriği $IC(c) = -\log p(c)$ ile yazılırsa $IC(c_1) + IC(c_2) - 2\,IC(lcs)$ olur. Bu büyük olasılıkla Jiang-Conrath'ın uzaklık tanımıdır: değer büyüdükçe kavramlar birbirinden uzaklaşır. Benzerlik olarak kullanılırken genellikle bu uzaklığın tersi alınır. Lin'in oranı ise 0 ile 1 arasında bir benzerliktir.

### 10.6 Karşılaştırma

Bu yöntemler üzerinde çeşitli ölçümler yapılmıştır (ekrandan, 01:40:30). Bütün yöntemler İngilizce 38 kelime çiftine uygulanmış ve bulunan benzerlik değerlerinin insan yargılarıyla korelasyonuna bakılmıştır. O zamanlar insanlara "bununla bunun arasında ne kadar benzerlik görüyorsun" diye sorulmuş, sistemlerin bulduğu değerlerle bu cevaplar karşılaştırılmıştır.

| Yöntem | Tür | Korelasyon |
|---|---|---|
| Wu & Palmer 1994 | Edge Counting | 0.74 |
| Li 2003 | Edge Counting | 0.82 |
| Leacock & Chodorow 1998 | Edge Counting | 0.82 |
| Resnik 1999 | Info. Content | 0.79 |
| Lin 1998 | Info. Content | 0.82 |
| Lord 2003 | Info. Content | 0.79 |
| Jiang & Conrath 1998 | Info. Content | 0.83 |
| Tversky 1977 | Feature Based | 0.73 |
| Adapted Lesk 2002 | Feature Based | 0.37* |
| Rodriguez 2003 | Hybrid | 0.71 |

Hoca Jiang-Conrath'ın 0.83, Lin'in 0.82 civarında çıktığını, yöntemler arasında çok büyük farklar olmadığını, ama ölçümlerin çok küçük veri kümeleri üzerinde yapıldığını vurguladı. Kavramsal ağaç elinizdeyse bu tür benzerlik hesapları yapılabilir.

## 11. Birbiri Yerine Kullanılan Kelimeler

2009 tarihli bir çalışmada (slaytta Deniz Yüret, 2009) birbiri yerine kullanılan kelimeler bulunmuştur. Hoca bunun ileride girilecek daha eski bir fikrin uygulaması olduğunu söyledi. İki metin düşünün:

```text
W1 W2 X1 W3 W4
W1 W2 X2 W3 W4
```

X1 ve X2'nin her ikisinin de önceki iki kelimesi ve sonraki iki kelimesi aynıdır. Kendilerinden önceki iki ve sonraki iki kelimenin aynı olduğu böyle kelimeler, aynı bağlamda (kendileri dışındaki çevrede) kullanılmıştır. Demek ki aralarında anlamsal bir ilişki vardır. X1 ve X2 ne kadar çok farklı bağlamda birbirinin yerine kullanılmışsa aralarındaki bağ o kadar güçlüdür, birbirlerine o kadar benzerdirler.

Bir bitirme projesinde bulunan örnekler (format: kelime1, kelime2, kaç farklı bağlamda birbirinin yerine kullanıldığı) (ekrandan, 01:42:45):

| Çift | Bağlam sayısı | Çift | Bağlam sayısı |
|---|---|---|---|
| dolar - ytl | 939 | meclis - tbmm | 219 |
| bulun - olmak | 619 | belir - kaydet | 194 |
| avro - euro | 459 | futbol - oyun | 189 |
| kanun - yasa | 350 | art - azal | 187 |
| avro - dolar | 344 | avro - ytl | 182 |
| oyna - yap | 309 | alan - saha | 177 |
| dolar - lira | 251 | gerek - iste | 176 |
| dolar - euro | 249 | lira - ytl | 173 |
| milyar - milyon | 241 | haziran - nisan | 161 |

Örneğin "dolar" ve "ytl", 939 farklı dörtlü bağlamda (W1 W2 _ W3 W4) birbirinin yerine kullanılmıştır.

Bu yöntem her zaman aynı türden bir anlamsal ilişkiyi ortaya koymaz:

- Dolar ve YTL, "para" gibi bir üst kavramın altındaki iki kardeş kavramdır. (YTL, Türk lirasından 6 sıfır atıldığında geçilen Yeni Türk Lirası'dır; sonra yeniden TL'ye dönülmüştür.) Avro ve dolar da kardeş kavramlardır.
- Kanun ve yasa eş anlamlıdır.
- Dolar-euro ya da milyar-milyon eş anlamlı değildir.
- Art ve azal (artmak, azalmak) zıt anlamlıdır. Aralarında ilişki vardır, ama bu ilişki ötekilerle aynı türden değildir.

Aynı durum, bu yapıyı kullanan word2vec'te de görülür; word2vec'ten bahsederken buna yeniden dönülecektir.

## 12. Anlamsal Uzay

Kümeleme de yapılabilecek şeylerden biridir: kelimeler, aynı kümeye düşenler benzer anlamlara sahip olacak şekilde, belli kriterler kullanılarak kümelenebilir. Ama kümelemede küme sayısının ne olacağı sorusu vardır.

Biraz daha tepeden bakınca **anlamsal uzay** kavramına gelinir. Anlamsal uzay, kelimelerin anlamsal benzerliklerinin bir temsilidir: kavramların (kelimelerin ya da belirteçlerin) anlamsal yakınlıklarına göre yer aldıkları bir koordinat sistemi. Her kavram bu sistemde bir noktaya karşılık getirilmeye çalışılır. İstenen şey, koordinat sisteminde birbirine yakın olanların anlamca da birbirine yakın olmasıdır.

Burada hep anlamsal yakınlıktan söz edilir. Aradaki anlamsal ilişkinin türünün ne olduğu daha güç bir konudur. Artmak ve azalmak kesinlikle anlamsal olarak ilişkilidir, ama bu ilişki kanun ile yasa arasındakiyle aynı değildir.

Koordinatları oluşturmanın yolları: LSI ve LDA (anlatıldı), birlikte geçme matrisleri (birazdan) ve sinirsel dil modelleri. Hoca sinirsel dil modellerini, kelimeleri anlamca yakın olanlar koordinat sisteminde de yakın olacak şekilde koordinatlara çevirme probleminin çok büyük derlemlerde çalışan, ölçeklenebilir bir çözümü olarak tanıttı; bunlara büyük olasılıkla sonraki hafta gelinecektir.

## 13. Birlikte Geçme Matrisleri ve Çok Boyutlu Ölçekleme

### 13.1 Harris'in fikri

Birlikte geçme matrisleri her şeyin temelidir. Dil bilimci Harris'e göre birlikte kullanılan kavramlar birbirlerine anlamsal olarak benzer. "Birlikte kullanılmak" şunlardan biri olabilir:

- aynı cümlenin içinde kullanılmak,
- aynı metnin, aynı dokümanın içinde kullanılmak,
- aynı paragrafın içinde kullanılmak,
- sabit bir kelime penceresinde kullanılmak (örneğin 10 kelimelik bir pencerede birlikte geçmek).

Bu birliktelikler sayılır.

### 13.2 Örnek çalışma: arama motoru sonuç sayıları (2006)

Hoca, 2006 yılında kendi ekiplerinin yaptığı bir çalışmayı anlattı (ekrandan, 02:00:00). İki kelimenin anlamsal benzerliği, İnternet'teki sayfaların kaçında yan yana kullanıldıkları bulunarak belirlenmiştir. "Aynı metin" burada "aynı web sayfası" olarak alınmıştır. Bunun için arama motoruna "kelime1 kelime2" sorgusu gönderilip sonuç sayfasındaki sonuç sayısı alınmıştır. Google'a (ya da o zamanlar Yahoo'ya) bir sorgu gönderildiğinde "şu kadar sonuç" yazar. Bu sayı, yazdığınız şeyin kaç web sayfasında bulunduğunu söyler; arama motoru bunlardan yalnız 10 tanesini sıralayıp gösterir.

Önce elle üç veri kümesi hazırlanmıştır:

- Veri kümesi 1: yer isimleri (berber, bakkal, kuaför, hastane, otel, okul ve diğer iş yerleri), hayvan isimleri, taşıt isimleri.
- Veri kümesi 2: ev eşyaları, hayvanlar, giyecekler.
- Veri kümesi 3: bunların hepsinden çeşitli sayılarda örnekler.

Her kelime her kelimeyle birleştirilip Google'a sorgu olarak gönderilmiştir. Örneğin 78 gelirse bu iki kelime 78 web sayfasında birlikte geçmiştir; 0 gelirse hiç birlikte geçmemiştir.

**Soru:** Bu birlikte geçme matrisinin boyutları ne olur? **Cevap:** Kelime sayısı çarpı kelime sayısı. Veri kümesi 1'de 30 kelime olduğu için $30 \times 30$'luk bir matristir. Matristeki büyük değerler kelimelerin çok birlikte geçtiğini, küçük değerler pek birlikte geçmediğini gösterir.

### 13.3 Çok Boyutlu Ölçekleme (MDS)

Bu $n \times n$'lik matrisi kullanmak için matematikte Multidimensional Scaling (MDS, çok boyutlu ölçekleme) yöntemi vardır. Elinizde belli nesneler ve bunların birbirine uzaklıklarını veren bir uzaklık matrisi olsun. MDS, bu uzaklık matrisiyle uyumlu olan nesne koordinatlarını döndürür. Hoca bunun da PCA'ya benzeyen bir yöntem olduğunu ve döndürmeye karşı tek bir sonuç vermediğini söyledi; temelde verilen mesafe matrisine uygun koordinatları döndürür.

Birlikte geçme matrisi bir benzerlik matrisidir. Önce bir uzaklık matrisine çevrilmiştir: bir ekleyip (yumuşatıp) değerin bir bölüsü alınarak. Sonra MDS'e verilmiştir.

> **Ek bilgi (derste anlatılmadı):** Klasik MDS, uzaklık matrisini çift merkezleyerek bir iç çarpım (Gram) matrisi elde eder ve bunun öz değer ayrıştırmasıyla koordinatları bulur. Bu yüzden PCA'ya benzer. Uzaklıklar döndürme, yansıtma ve ötelemeyle değişmediği için bulunan koordinatlar ancak bu dönüşümlere kadar belirlidir.

### 13.4 Sonuçlar

Veri kümesi 1 için Google ile bulunan benzerlik matrisinden hesaplanan iki boyutlu koordinatlarda (ekrandan, 02:05:00) hayvan isimleri (balina, akbaba, aslan, akrep, bit, arı, bizon, at), yer isimleri (dershane, park, okul, hastane, kuaför, otel, bakkal, büfe, berber) ve taşıt isimleri (cip, ambulans, traktör, otomobil, sedan, limuzin, tren, araba, taksi, otobüs) ayrı bölgelerde toplanır. İlginç yakınlıklar da vardır:

- "ahır", bizon ve ata biraz daha yakın durur.
- "bakkal" ile "büfe" birbirine çok yakındır.
- "limuzin" ile "tren" birbirine çok yakındır, ama "tren" ile "otomobil" o kadar yakın değildir.

**Soru:** Limuzin ile tren neden birbirine yakın çıktı? **Cevap:** Hoca, bir yerlerde birilerinin "tren gibi limuzin gördüm" gibi şeyler yazmış olabileceğini, yani bu iki kelimenin metinlerde sık birlikte geçtiğini söyledi.

Sisteme "bunlar yer ismidir, bunlar hayvan ismidir, bunlar taşıt ismidir" diye hiçbir bilgi verilmemiştir. Verilen yalnız 30 kelimedir; dönen de bu koordinat sistemidir (burada yalnız birinci ve ikinci koordinat görülüyor; koordinatlar 13., 14., 15. boyuta kadar gider).

Veri kümesi 2'de de hayvanlar, eşyalar ve kıyafetler bir arada bulunur. Burada "bit" ile "divan" yakın çıkar; hoca bunu eskiden divanlarda bit olmasıyla ilişkilendirdi. Veri kümesi 3'te de fena olmayan sonuçlar alınmıştır. Bu iş gözetimli bir yapıya, yani sınıflandırmaya dönüştürüldüğünde, veri kümesi 1'de gözetimli yaklaşımlarla yüzde 90'ın üstünde sonuçlar elde edilebiliyordu.

### 13.5 Ölçeği büyütmek: 967 terim

Sonra iş 967 terime büyütülmüştür. Bu kez benzerlik matrisi Google ile değil, web kazıma (web scraping) ile toplanan 15 bin web sitesi üzerinden hesaplanmıştır.

**Soru:** Google kullanılsaydı daha iyi sonuç alınacağı bilindiği hâlde neden bu yol seçildi? **Cevap:** Bir öğrenci sayı artarken belki niteliğin düşeceğini söyledi; hoca bunun sebep olmadığını belirtti. Bir başka öğrenci Google'ın bu kadar çok istek atılmasına izin vermeyeceğini söyledi; hoca onayladı. 967 terimin her biri her biriyle sorgulanacaktır; bu yaklaşık bine binlik bir matristir. (A, B) gönderilip (B, A) gönderilmese bile yaklaşık 500 bin sorgu eder ($967 \times 966 / 2 = 467\,061$; ara adım eklendi). 30-40 kelime için bu mümkündür, 1000 kelime için değildir. Çözüm kendi derlemini oluşturmaktır; burada bu derlem yalnız 15 bin web sitesidir.

Sonuç grafiğinde her nokta, artı ya da yuvarlak bir kavramdır ve ilk iki koordinatı gösterilir (ekrandan, 02:10:00). Lejantta on alan vardır: Medicine, Literature, Zoology, Economy, History, Sport, Sociology, Psychology, Music, Chemistry. Renkler ve işaretler koordinatlar bulunduktan sonra eklenmiştir ("tıp terimlerini siyah artıyla göster", "edebiyat terimlerini yeşil noktayla göster" gibi). Bu bilgi ne web sitelerini sorgulayan sisteme ne de MDS'e verilmiştir.

Hoca sonuçların iyi görünüp görünmediğini sordu. Bir öğrenci iyi göründüğünü, ama terimlerin daha çok teknik olduğunu söyledi. Hoca da sınıf bilgisi kullanılmadan bile terimlerin sınıfları içinde epey iyi temsil edildiğini, 30-40 kelimede yapılanın 1000 kelimede de iyi sonuç verdiğini söyledi. Ancak bunun bu kadar iyi olmasının sebebi, öğrencinin dediği gibi, terimlerin hepsinin teknik terim olmasıdır. Sosyoloji terimiyle zooloji teriminin birlikte geçme olasılığı epey düşüktür; dolayısıyla birbirlerinden uzakta olurlar. Zooloji terimlerinin kendi içinde birlikte geçme olasılığı ise çok daha yüksektir. Daha genel kelimelerle bu kadar iyi sonuç alınamayabilir, ama yine de epey işe yarayan sonuçlar elde edilir.

## 14. Anlamsal Uzayların Metin Sınıflandırmada Kullanımı

Teknik terimler yerine haber metinleriyle küçük bir örnek de gösterildi (ekrandan, 02:13:40). Beş haber sınıfı (ekonomi, magazin, sağlık, politika, spor) kullanılmış, kelimelerin kökleri alınmış ve yaklaşık 4500 kavram elde edilmiştir. Bu kavramların birlikte geçme sayıları yine 15 bin siteden elde edilmiş, uzaklık yakınlığa (benzerliğe) dönüştürülmüş ve MDS'in ilk 100 ve ilk 10 boyutu kullanılmıştır.

<!-- BELİRSİZ: 02:11:49 civarında "5 tane haber sınıfında 230'lar tane terim, PC, Kimole" ifadesi bozuk. Büyük olasılıkla her sınıftan 230'ar haber metni ve kök bulmak için kullanılan bir morfolojik çözümleyici kastediliyor; hedefli karede bu slayt yalnız küçük resim olarak görüldü. -->

Buraya kadar bulunanlar kelimelerin koordinatlarıdır. Bu yaklaşım metin sınıflandırmada kullanılmak istenirse haberlerin koordinatları gerekir. En basit yol şudur: bir metnin içindeki kelimelerin koordinatları biliniyorsa, bu koordinatların ortalaması o metnin koordinatıdır. Metindeki kelimelerin birinci boyutlarının ortalaması metnin birinci boyutu, ikinci boyutlarının ortalaması ikinci boyutudur. Böylece metinler kelimelerle aynı boyutlu olur. Metinde az ya da çok kelime olması fark etmez; ortalama alındığı için hepsi aynı sayıda boyutla ifade edilir.

Slayttaki grafikte metinlerin birinci ve ikinci boyutları çizilmiştir; ekonomi, magazin, sağlık, politika ve spor haberleri kısmen ayrışır. Burada da renkler sonradan eklenmiştir; koordinatlar sınıf bilgisi kullanılmadan, yalnız metinler kullanılarak elde edilmiştir. Hoca sınıflandırma başarılarının da hiç fena olmadığını söyledi. Yaklaşımın güzel bir tarafı da dilden bağımsız olmasıdır.

## 15. Sabit Koordinatların Sorunu: Çok Anlamlı Kelimeler

**Soru:** Eş sesli (çok anlamlı) kelimelerin durumu kötü mü? **Cevap:** Hoca evet dedi. Şu ana kadar görülen yöntemler ve ileride görülecek FastText, word2vec gibi yöntemler kelimelere sabit koordinatlar verir. Oysa bazı kelimelerin birden fazla anlamı vardır. Olması gereken iki anlam vardır, ama kullanılabilecek tek bir yer vardır; kelimenin koordinatı aşağı yukarı iki anlamın ortasına denk gelir. Kelimenin koordinatı etrafındaki kelimelere göre değişmez. Bu sorunun nasıl çözüldüğü ileride bağlam farkında modellere gelindiğinde görülecektir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:09:52; geçen dersin sorusu): Size 20 kelimelik bir kelime torbası veriliyor ve istediğiniz $k$ değerine sahip bir istatistiksel dil modeliniz var. Bu kelimelerin hepsini kullanarak makineye anlamlı bir cümleyi nasıl kurdurursunuz?

> **Cevap (derste verildi):** Bütün $20!$ sıralamayı puanlamak mümkün değildir. Önerilen çözümlerin ortak noktası, varsayımlarla arama uzayını daraltmaktır: cümle başında en sık geçen kelimeyle başlayıp her adımda en olası devamı seçmek ($k=1$), cümle başı sembolünden sonra en olası 100 (gerekirse 200) bigram içinde eldeki kelimeleri aramak, kelime türlerine ya da bağlaçlara göre önce yapı kurmak. Varsayım probleme ne kadar uygunsa hızlanma ve doğru sonuca ulaşma olasılığı o kadar yüksektir.

**Soru 2** (ekrandan, 00:30:00): Dil modellerini dahili yöntemle değerlendirirken (test cümlelerine verilen olasılık, cümle başı verildiğinde sonunu tahmin etme) Markov varsayımında $k=0$ seçimi nasıldır?

> **Cevap (derste kısmen verildi):** Hoca $k=0$ ile pek iyi bir şey elde edilemeyeceğini söyledi. Gerekçe derste metin üretimi kısmında açıklandı: $k=0$'da hiçbir kelime öncekilere bağlı değildir; cümle olasılığı tek kelime olasılıklarının çarpımı olur ve kelime sırasından bağımsızdır. Bir cümlenin başı ne olursa olsun sonraki kelime için hep aynı dağılım bulunur; bu yüzden cümle sonunu tahmin etmede başarısızdır.

**Soru 3** (derste sözlü, 00:24:12): Webden toplanmış çok büyük bir derlemden rastgele bir parçayı test kümesi seçmek neden iyi olmayabilir?

> **Cevap (derste verildi):** Webde tekrarlı veri çok fazladır (aynı haber 30 sitede, aynı ürün metni birçok satıcıda). Test kümesi olarak seçilen içerik eğitim kümesinde de bulunabilir; model kopya çeker ve sonuçlar gerçek dışı derecede iyi çıkar. Ayrıca büyük metin derlemlerinde 10 katlı çapraz geçerleme her eğitim çok uzun sürdüğü için pratik değildir.

**Soru 4** (derste sözlü, 00:33:15): İstatistiksel dil modeliyle metin üretirken $k=0$ (ya da $k=1$) için her zaman en yüksek olasılıklı kelime seçilirse ne olur? Bu nasıl aşılır?

> **Cevap (derste verildi):** $k=0$'da en olası kelime hiç değişmediği için aynı kelime sürekli tekrar eder; $k=1$'de bir kelimeden sonra hep aynı kelime gelir. Çözüm ya en olası $t$ kelimeden birini rastgele seçmek ya da seçimi doğrudan sonraki kelimenin olasılık dağılımına göre yapmaktır (olasılıkların toplamı 1'dir).

**Soru 5** (ekrandan, 00:40:00; derste sözlü, 00:40:30): Aşağıdaki metinler istatistiksel bir dil modeliyle üretilmiştir. Modelin $k$ değeri nedir? "fonların yüzde 5 de bu konuda son 10 ın da çok sayıda türk telekom gibi çok önemli olduğunu belirten bakan şimşek 2012 nin." / "akademik araştırmalar sonucunda yer aldığı bilgiye göre bir şekilde diyen ve yüzde 10 yılda bir süre içerisinde türkiye istatistik verilerine borsa seçimlerinin dikkati çekti türkiye."

> **Cevap (derste verildi):** $k=1$. Ardışık ikililer anlamlıdır ("yüzde 10", "10 yılda", "yer aldığı", "aldığı bilgiye") ama ardışık üçlüler anlamsızdır ("yüzde 10 yılda", "yer aldığı bilgiye"). Model her kelimeyi yalnız bir öncekine bakarak seçmiştir.

**Soru 6** (derste sözlü, 01:10:01): Dört haber metninden bir sözlük oluşturup terim-doküman matrisini kursak nasıl bir matris olur?

> **Cevap (derste verildi):** Satır sayısı (kelime sayısı) çok büyük, sütun sayısı 4 olur; örneğin 500 farklı kelime geçerse $500 \times 4$. Her dokümanda sözlüğün çok küçük bir kısmı geçtiği için matris çok seyrektir (sparse), yani bol miktarda sıfır içerir.

**Soru 7** (derste sözlü, 01:34:06; ekrandan, 01:33:00): Wu & Palmer benzerliğinde iki kavramın en yakın ortak üst synset'i köke yakın olursa mı kavramlar anlamca daha yakın olur, kökten uzak olursa mı?

> **Cevap (derste verildi):** Kökten uzak olursa. Ortak üst kavram kökten ne kadar uzaksa o kadar spesifiktir; köke yakınsa çok büyük bir kavram kümesini kapsar. Bu yüzden $N_3$ (ortak üst synset'in köke uzaklığı) formülde benzerlikle doğru orantılıdır; $N_1$ ve $N_2$ ise küçük olmalıdır.

**Soru 8** (derste sözlü, 01:37:52; ekrandan, 01:40:00): Jiang-Conrath ve Lin yöntemlerinde $p(c) = freq(c)/freq(root)$ tanımındaki $freq(root)$ nedir? Genel bir kavramın olasılığı yüksek mi düşük mü olur?

> **Cevap (derste verildi):** $freq(root)$, bütün ağaçtaki kavramların frekanslarının toplamıdır; derlemle ağaç birbirini karşılıyorsa bu, derlemdeki toplam kelime sayısına yakındır. Bir kavramın frekansı altındaki bütün kavramların frekanslarını da içerdiği için, kavram ne kadar genelse olasılığı o kadar yüksek olur.

**Soru 9** (derste sözlü, 02:02:05): 30 kelimelik bir veri kümesinde her kelime çifti için arama motoru sonuç sayısı alınarak oluşturulan birlikte geçme matrisinin boyutu nedir? Matristeki büyük değerler neyi ifade eder?

> **Cevap (derste verildi):** Kelime sayısı çarpı kelime sayısı, yani $30 \times 30$. Büyük değerler iki kelimenin çok sayıda web sayfasında birlikte geçtiğini, küçük değerler pek birlikte geçmediğini gösterir.

**Soru 10** (derste sözlü, 02:05:19; ekrandan, 02:05:00): MDS ile bulunan koordinatlarda "limuzin" ile "tren" neden birbirine yakın çıkmıştır?

> **Cevap (derste verildi):** Yöntem yalnız birlikte geçmeye dayanır. Web'de bu iki kelimenin birlikte geçtiği sayfalar çoktur (örneğin "tren gibi limuzin" gibi ifadeler); bu yüzden anlamca aynı alt grupta olmasalar da yakın düşmüşlerdir.

**Soru 11** (derste sözlü, 02:07:19): 967 terim için birlikte geçme matrisi oluştururken Google'dan daha iyi sonuç alınacağı bilindiği hâlde neden 15 bin web sitesinden oluşan kendi derlemimiz kullanıldı?

> **Cevap (derste verildi):** Her terim her terimle sorgulanacağı için (A, B) gönderilip (B, A) gönderilmese bile yaklaşık 500 bin sorgu gerekir; $967 \times 966 / 2 = 467\,061$ (python ile hesaplandı). Google bu kadar çok otomatik isteğe izin vermez. 30-40 kelime için mümkün olan şey 1000 kelime için mümkün değildir; bu yüzden kendi derlemimiz oluşturulur.

**Soru 12** (ekrandan, 02:20:00; derste sözlü, 02:16:28; ödevin akademik metni): Anlamsal uzayların karşılaştırılması. En az 4 anlamsal uzay yöntemini (ikisi BERT, GPT gibi sinirsel dil modeli olmak üzere) 1 konu sınıflandırma ve 2 konu sınıflandırma dışı, toplam 3 metin veri kümesi üzerinde sınıflandırma performansı açısından karşılaştırın. Karşılaştırmaya klasik TF ve TF-IDF'i (2-6 karakter gram) dahil edin. 6 yöntemi 3 veri kümesinde 5'er kez tekrarlayıp ortalama ve standart sapmaları raporlayın. Anlamsal uzayların ikili birleştirilmesi (yan yana ya da önereceğiniz başka bir yöntemle) üzerine 3 birleştirme için deneme yapıp sonuçları aynı şekilde raporlayın ve yorumlayın.

> **Cevap (derste verilen açıklamalar):** Bu bir ödevdir; çözüm derste verilmedi. Sorulara verilen cevaplar: (1) Karşılaştırma, dersin başındaki ayrımla harici yöntemdir, yani sınıflandırma performansı üzerinden yapılır. (2) Konu sınıflandırma dışı veri kümesi, olumlu ve olumsuz yorumları ayırmak ya da nefret söylemi var/yok gibi başka bir metin sınıflandırma görevi olabilir. (3) Karakter n-gramı istenmektedir, kelime n-gramı değil. (4) Yan yana birleştirme, örneğin word2vec'in 300 boyutlu temsili ile BERT'in 768 boyutlu temsilini art arda ekleyip (concatenate) yaklaşık 1000 boyutlu bir temsil elde etmek ve bunu SVM ya da bir yapay sinir ağı gibi bir sınıflandırıcıya vermektir; BERT ve GPT temsilleri de böyle birleştirilebilir. (5) Hazır (pretrained) modellerin eğitildiği metinleri test verisi olarak kullanmaktan tamamen kaçmak zordur; tamamen kaçmak için modelin yayın tarihinden sonra yayınlanmış veriler kullanılabilir, ama bunun da garantisi yoktur. Elden geleni yapıp ne yapıldığını anlatmak yeterlidir. (6) Metinlerin dili önemli değildir.

## Dersin Toparlaması

Ders, geçen haftanın 20 kelimelik kelime torbası sorusuyla açıldı. Bütün sıralamaları denemek mümkün olmadığından, probleme uygun varsayımlarla arama uzayını daraltmak gerektiği görüldü. Ardından dil modellerini karşılaştırmanın harici (başka görevlerdeki başarı) ve dahili (test cümlelerine verilen olasılık) yolları anlatıldı. Webden toplanan derlemlerde test verisinin eğitim kümesine sızması özellikle vurgulandı. İstatistiksel dil modelleriyle otoregresif metin üretimi, en olası $t$ taneden ya da dağılımdan örnekleme ile gösterildi. Bigram ve trigram örnekleri, ardışık grupların anlamlı olabileceğini ama cümle bütünlüğünün oluşmadığını ortaya koydu. Ardışıklık yerine aynı dokümanda birlikte geçmenin kullanılması ise anlamca benzer kelimeleri bulmaya kapı açtı.

Dersin ikinci yarısı kelimelerin anlamsal benzerliğine ayrıldı. Karakter benzerliğinin (edit distance) anlamı yakalayamadığı görüldü. Tarihsel bir akış içinde LSI (terim-doküman matrisine SVD), LDA (konu modelleme), WordNet ağacına dayanan Leacock & Chodorow, Wu & Palmer, Jiang-Conrath ve Lin ölçüleri, aynı bağlamda birbirinin yerine kullanılan kelimeler ve Harris'in fikrine dayanan birlikte geçme matrisleriyle MDS anlatıldı. Bu yöntemler sınıf bilgisi kullanmadan kelimeleri ve metinleri (kelime koordinatlarının ortalamasıyla) anlamlı biçimde ayrıştıran bir anlamsal uzay kurar. Ancak her kelimeye sabit bir koordinat verdikleri için çok anlamlı kelimelerde sorun yaşarlar. Hoca, bu problemin ölçeklenebilir çözümü olan sinirsel dil modellerine (word2vec vb.) büyük olasılıkla sonraki hafta, çok anlamlılık sorununun çözümüne ise bağlam farkında modellerle geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
