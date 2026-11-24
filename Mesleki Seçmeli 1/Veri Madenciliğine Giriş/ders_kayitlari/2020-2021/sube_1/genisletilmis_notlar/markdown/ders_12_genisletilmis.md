# Ders 12 Genişletilmiş Notu: Öneri Sistemleri: İçerik Tabanlı Öneri ve İşbirlikçi Filtreleme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Öneri Sistemlerine Giriş
- 2. Uzun Kuyruk (Long Tail) Olgusu
- 3. Öneri Türleri ve Biçimsel Model
- 4. Temel Problemler: Puan Toplama, Seyreklik ve Soğuk Başlangıç
- 5. İçerik Tabanlı Öneri
- 6. İşbirlikçi Filtreleme ve Benzerlik Ölçüleri
- 7. Puan Tahmini: Kullanıcı-Kullanıcı ve Ürün-Ürün İşbirlikçi Filtreleme
- 8. Güncel Eğilimler
- Örnek Sorular

## 1. Öneri Sistemlerine Giriş

Bir önceki derste birliktelik kuralları ve market sepeti analizi işlenmişti. Bu hafta öneri sistemlerine (recommendation / recommender systems) geçilir. Ders, Stanford Üniversitesi'nin "Mining of Massive Datasets" (Leskovec, Rajaraman, Ullman) kitabına ait slaytlar üzerinden anlatılır (ekrandan, 00:35:00). Slayt dizisinin kapağındaki başlıklar şunlardır:

- Genel bakış (overview)
- İçerik tabanlı sistemler (content-based systems)
- İşbirlikçi filtreleme (collaborative filtering)
- Öneri sistemlerinin değerlendirilmesi

Hoca, üç temel çözüm ailesi olduğunu söyler: içerik tabanlı sistemler, işbirlikçi filtreleme ve matris ayrıştırma (matrix factorization) gibi gizli faktör tabanlı yöntemler. Bu derste ilk ikisi anlatılır; üçüncüsüne girilmez.

Öneri sistemi, kullanıcının bir sitede yaptığı aramalar, tıklamalar ve satın almalar arkasında çalışarak ona yeni ürünler sunar. Önerilen şey bir film, müzik, kitap, CD ya da haber olabilir. Derste verilen örnekler:

- **Google News:** O güne kadar okunan haberlere göre yeni haberler önerir.
- **Spotify:** "Sizin için seçtiklerimiz" gibi bölümler, daha önce dinlenen müziklere göre oluşturulur. Hoca, burada yalnız türe değil müziğin içeriğine (ritim, notalar) de bakıldığını ve müzikten MFCC gibi öz niteliklerin çıkarıldığını belirtir.
- **Amazon:** Bir kitap satın alınırken sayfanın altında başka kitaplar önerilir.
- **Netflix ve MovieLens:** İzlenen filmlere ve bu filmlere verilen puanlara göre film önerir.

## 2. Uzun Kuyruk (Long Tail) Olgusu

### 2.1 Kıtlıktan bolluğa

Fiziksel mağazacılıkta (ör. bir kitapevi ya da bir giyim mağazası) sergilenebilecek ürün sayısı mağazanın büyüklüğü ve rafların kapasitesiyle sınırlıdır. Küçük mağaza az çeşit, büyük mağaza daha çok çeşit getirir. Mağaza sahibi kirayı ve giderleri karşılayabilmek için öncelikle çok satan, popülerliği yüksek ürünleri sergiler.

### 2.2 Uzun kuyruk grafiği

Slayttaki grafik (ekrandan, 00:40:00) şunları gösterir:

- Yatay eksen: popülerliğe göre sıralanmış ürünler (items ranked by popularity). Solda en popüler, sağa doğru daha az satılan ürünler yer alır.
- Dikey eksen: haftalık satış sayısı (number of purchases / week).
- Kırmızı eğri solda çok yüksek, sağa doğru hızla düşen ve çok uzun bir kuyrukla devam eden bir eğridir.
- Dikey mavi çizginin solu "Retail and Online" (hem mağazada hem çevrim içi satılan ürünler), sağı "Items available only online" (yalnız çevrim içi satılan ürünler) olarak işaretlenmiştir.
- Slaytın başlığındaki not: "The economics of abundance" (bolluğun ekonomisi); ürünler kitap, müzik, video ya da haber makalesi olabilir.

Hoca, mavi çizginin solundaki eğri altı alanla sağındaki eğri altı alanın birbirine eşit olduğunu vurgular. Bunun anlamı şudur: fiziksel mağazalar raf kısıtı yüzünden kuyruktaki ürünleri sergileyemez, ama bu ürünlerin toplam satışı popüler ürünlerin satışı kadar olabilir. Çevrim içi ortamda popüler olmayan bir ürünü sergilemenin maliyeti, ürün listesine (veri tabanına) bir satır eklemekten ibarettir. Her bir kuyruk ürünü az satılır, ama kuyruk o kadar uzundur ki bu küçük satışlar toplanınca çok büyük bir miktara ulaşır.

> **Hocanın vurgusu:** Uzun kuyruk grafiği çok çarpıcı bir örnektir; hoca özellikle üzerinde durmak istediğini söyler.

### 2.3 "Touching the Void" örneği

Slayttaki ikinci uzun kuyruk sayfasında (ekrandan, 00:45:00) "Daha fazla seçenek daha iyi filtre gerektirir" (more choice necessitates better filters) denir ve öneri motorları örnek gösterilir: "Into Thin Air", "Touching the Void" kitabını nasıl çok satan yaptı?

Hocanın anlattığı hikâye şöyledir: Bir doğa gezgininin dünyanın ilginç bir köşesindeki doğa gezisinde yaşadıklarını anlatan "Touching the Void" yayımlandığı ilk yıl bir miktar satar, sonra popülerliğini yitirip raflarda bekler. Yıllar sonra başka bir doğa gezgini başka bir bölgedeki deneyimini anlatan "Into Thin Air" kitabını yazar. Çevrim içi satışta bu yeni ve popüler kitapla eski kitap arasında benzerlik kurulur; yeni kitabı seçen kullanıcılara eski kitap da önerilir. Okurlar eski kitabı inceler ve çok beğenir; uzun süre satmayan kitap üst üste haftalarca çok satanlar listesine girer. Bu örnek, öneri sistemlerinin yeni şeyler keşfetmeyi de sağladığını gösterir.

<!-- BELİRSİZ: Hoca kitapların arasındaki süreyi "15 sene", çok satanlar listesinde kalma süresini "10 hafta", ilk yıl satışını "1500-2000" diye söylüyor; bu sayılar slaytta yok, doğrulanamadı. -->

Aynı slaytta kullanım alanları da sayılır: kitaplar, filmler, müzik, haber makaleleri ve insanlar (Facebook, LinkedIn ve Twitter'daki arkadaş önerileri).

## 3. Öneri Türleri ve Biçimsel Model

### 3.1 Öneri türleri

Çevrim içi öneri sistemleri yaygınlaşmadan önce öneriler elle yapılırdı: mağaza sahipleri ya da pazarlamacılar kendi tecrübeleriyle favori ürünler ve temel ürünler listeleri hazırlardı. Basit toplu listeler de bir öneri biçimidir: bir kitap mağazasının girişindeki "en çok satanlar" ve "en son çıkanlar" standları buna örnektir.

Dersin asıl konusu ise kişiye özgü (tailored to individual users) önerilerdir. Hoca "tailored" kelimesini "terzi işi, tam üstünüze oturacak biçimde dikilmiş" diye açıklar ve kuruma özel yazılan "tailored software" kavramıyla karşılaştırır. Amazon, Netflix ve Pandora bu tür önerileri ilk kullanan sistemlerdendir.

### 3.2 Biçimsel model

Slayttaki biçimsel model (ekrandan, 00:50:00):

- $C$: müşteriler kümesi (set of customers).
- $S$: ürünler kümesi (set of items). Netflix için film, Spotify için şarkı, Google News için haber metni olabilir.
- Fayda fonksiyonu (utility function): $u: C \times S \rightarrow R$.
  - $R$: puanlar kümesi (set of ratings).
  - $R$ tam sıralı bir kümedir (totally ordered set).
  - Örnek: 0-5 yıldız ya da $[0,1]$ aralığında bir gerçel sayı.

Bu fonksiyonun değerleri bir matriste tutulur. Satırlar müşteriler, sütunlar ürünler, hücreler puanlardır. Slayttaki adı fayda matrisi (utility matrix, $U$ matrisi) dir; hoca buna daha çok "rate matrisi" der.

Ürün aldıktan sonra genellikle "ürünü beğendiniz mi, puanlar mısınız" diye sorulur. Puanlama 0-5 ya da 1-5 yıldız üzerinden yapılır; bazı sistemlerde yarım yıldız (ör. 3,5) da verilebilir. Uygulamada bu puanların $[0,1]$ aralığına normalize edilmesi ve öyle değerlendirilmesi daha kolaydır.

### 3.3 Fayda matrisi örneği

Hoca, dört kullanıcılı ve dört filmli (Avatar, Lord of the Rings, Matrix ve bir film daha) örnek bir matris gösterir; puanlar 0-5 yıldızdan $[0,1]$ aralığına normalize edilmiştir. Bir kullanıcı Avatar'a 5 yıldız verdiği için hücrede 1, Matrix'e 1 yıldız verdiği için 0.2 görünür. Başka bir kullanıcı bunun tam tersini yapmış, Avatar'a 0.2 (1 yıldız), Matrix'e 1 (5 yıldız) vermiştir. Bu iki kullanıcı verdikleri puanlara göre birbirine en zıt iki kullanıcıdır.

<!-- BELİRSİZ: Bu örnek matrisin karesi yok; dördüncü film altyazıda "Pretz" diye geçiyor ve matrisin diğer hücreleri okunamadı. -->

## 4. Temel Problemler: Puan Toplama, Seyreklik ve Soğuk Başlangıç

Slaytta üç temel problem sayılır: bilinen puanları matrise toplamak, bilinenlerden bilinmeyen puanları tahmin etmek (extrapolating utilities) ve tahmin yöntemlerini değerlendirmek. En büyük zorluk, fayda matrisini nasıl dolduracağımızdır, çünkü ürün alan herkes puan vermez.

### 4.1 Puan toplama: açık ve örtük yöntemler

Slayt (ekrandan, 00:55:00) iki yol verir:

- **Açık (explicit):** İnsanlardan ürünleri puanlamaları istenir. Ölçeklenmez; kullanıcıların yalnız küçük bir kısmı puan ve yorum bırakır. Örnek: alışverişten sonra e-postaya gelen "ürününüzü puanlayın" anketi.
- **Örtük (implicit):** Puanlar kullanıcının eylemlerinden öğrenilir; örneğin satın alma yüksek puan demektir. Peki düşük puanlar ne olacak? (What about low ratings?)

Hoca örtük yöntemi şöyle açar: kullanıcı bir sitede arama yaparken bıraktığı bütün izler kayıtlarda (log) tutulur. Hangi ürüne tıklandığı, ürünün ayrıntı için yeni bir ekranda açılıp açılmadığı ve o ekranın ne kadar süre açık kaldığı (hızlıca kapatmak mı, uzun süre incelemek mi) ayrı ayrı puan anlamı taşır. Sepete eklemek ayrı bir puandır; ama sepete eklenen her ürün satın alınmaz. Satın alma ise ayrı ve daha yüksek ağırlıklı bir puan oluşturur. Böylece kullanıcının ürünle etkileşiminden dolaylı yoldan puan üretilir.

Düşük puanlar konusunda hoca, bu puanlar düzgün toplanamadığı için düşük çıkmış olabileceğini ve bu konuda yapılabilecek pek bir şey olmadığını söyler.

### 4.2 Seyreklik ve soğuk başlangıç

Slayttaki ana problem (ekrandan, 01:00:00): $U$ matrisi seyrektir (sparse); çoğu insan çoğu ürünü puanlamamıştır. Seyrek matris, sıfırdan farklı hücrelerin sayısının çok az olduğu matristir. Bunun nedeni yalnız insanların puan vermemesi değildir; bir kullanıcı her ürünle temas etmez. Örneğin bir film sisteminde kullanıcının izleyebileceği film sayısı sınırlıdır ve yalnız izlediği filmler için puanı olabilir.

Soğuk başlangıç (cold start) problemi:

- **Yeni ürünlerin puanı yoktur:** Matrise yeni eklenen her film, kitap vb. "cold item" olarak geçer.
- **Yeni kullanıcıların geçmişi yoktur:** Sisteme yeni katılan kullanıcı hiçbir ürünle temas etmediği için "cold user" olarak geçer.

Bu iki durum için ayrıca çözüm üretmek gerekir.

Slayttaki üç yaklaşım:

- 1) İçerik tabanlı (content-based)
- 2) İşbirlikçi (collaborative)
- 3) Gizli faktör tabanlı (latent factor based)

## 5. İçerik Tabanlı Öneri

### 5.1 Ana fikir

Slayt (ekrandan, 01:15:00): "$x$ müşterisine, $x$'in daha önce yüksek puan verdiği ürünlere benzeyen ürünleri öner." Örnekler:

- **Filmler:** aynı oyuncu(lar), yönetmen, tür vb.
- **Web siteleri, bloglar, haberler:** "benzer" içerikli makaleler.
- **İnsanlar:** çok sayıda ortak arkadaşı olan kişiler.

Hoca bunu "biraz daha ilkel bir yöntem" diye niteler ve şunu tekrar tekrar vurgular:

> **Hocanın vurgusu:** İçerik tabanlı öneride yalnız $x$ kullanıcısının kendi geçmişi ve kendi puanları kullanılır. Diğer kullanıcıların verdiği puanlar kesinlikle kullanılmaz.

### 5.2 Eylem planı

Slayttaki şema şöyle işler:

```text
Kullanıcının beğendiği ürünler (ör. kırmızı daire, kırmızı üçgen)
  -> Ürün profilleri çıkarılır
  -> Kullanıcı profili oluşturulur ("kırmızıyı, daireyi ve üçgeni seviyor")
  -> Kullanıcı profiliyle eşleşen ürünler bulunur (kırmızı olan, daire ya da üçgen biçimli)
  -> Bu ürünler kullanıcıya önerilir
```

### 5.3 Ürün profili

Her ürün için bir profil oluşturulur; profil bir öz nitelik kümesidir:

- Film için: başrol oyuncusu, yönetmen, senarist ve senaryo, başlık.
- Görüntü ve video için: meta veri ve etiketler (tag). Görüntü ve videolar belirli anahtar kelimelerle etiketlenebildiği için bu etiketler öz nitelik olur.
- Facebook ya da LinkedIn gibi bir yapıda: kişinin arkadaşları.

Profil vektörü ikili (Boolean) ya da gerçel değerli olabilir. Gerçel değerli vektörde kullanıcının ürüne verdiği puan bulunur; ikili vektörde yalnız temas bilgisi (filmi izledi/izlemedi, ürünü inceledi/incelemedi) bulunur.

### 5.4 Metin öz nitelikleri

Slayt (ekrandan, 01:20:00): profil, üründeki (belgedeki) "önemli" kelimelerin kümesidir. Önemli kelimeleri seçmek için metin madenciliğinde kullanılan sezgi TF-IDF'dir (terim frekansı × ters belge frekansı).

Hoca, ürün hakkında yazılmış bir yorumun içeriğinden beğeniyi ölçmek gibi işlerde metin madenciliğinden yararlanıldığını söyler. Terim frekansı için: $j$ belgesinde $i$ teriminin geçiş sayısı, o belgede en sık geçen terimin geçiş sayısına bölünür. Bu frekans daha sonra bütün belgeler üzerinden ters belge frekansıyla birleştirilir ve bir TF-IDF skoru elde edilir; bu skor kelime için bir öz nitelik olur.

> **Hocanın vurgusu:** TF-IDF hesabı bu dersin konusu değildir; hoca bunu anlatmayacağını ve bununla ilgili soru sormayacağını söyler. Yalnız metinden öz nitelik çıkarmaya örnek olarak değinilmiştir.

> **Ek bilgi (derste anlatılmadı):** Ders kitabındaki tanımla terim frekansı $TF_{ij} = f_{ij} / \max_k f_{kj}$, ters belge frekansı $IDF_i = \log(N/n_i)$ biçimindedir; burada $N$ toplam belge sayısı, $n_i$ ise $i$ teriminin geçtiği belge sayısıdır. TF-IDF skoru $TF_{ij} \times IDF_i$ çarpımıdır. Belgede sık geçen ama az belgede bulunan terimler yüksek skor alır.

### 5.5 Kullanıcı profili

Kullanıcı $i = 1, \dots, n$ ürünlerini puanlamıştır. Kullanıcı profili iki yolla oluşturulabilir:

- Basit yol: puanlanan ürün profillerinin ortalaması.
- Kullanıcının ortalama puanına göre normalize edilmiş ağırlıklar.

#### Örnek 1: İkili fayda matrisi

Slayt (ekrandan, 01:25:00):

- Ürünler filmlerdir ve tek öz nitelik "oyuncu"dur. Ürün profili her oyuncu için 0 ya da 1 içeren bir vektördür.
- $x$ kullanıcısı 5 film izlemiştir: 2'sinde A oyuncusu, 3'ünde B oyuncusu oynar.
- Kullanıcı profili = ürün profillerinin ortalaması:
  - A öz niteliğinin ağırlığı $= 2/5 = 0.4$
  - B öz niteliğinin ağırlığı $= 3/5 = 0.6$

Elde yalnız ikili (0-1) değerler varsa kullanılabilecek tek çözüm budur. Bu durumda kullanıcı B'yi biraz daha çok seviyor gibi görünür.

#### Örnek 2: Yıldızlı puanlar

Slayt (ekrandan, 01:30:00), aynı örnek 1-5 yıldızla:

- A'nın filmlerine verilen puanlar: 3 ve 5.
- B'nin filmlerine verilen puanlar: 1, 2 ve 4.

Kullanıcı A'nın filmlerinden daha az izlemiş ama daha yüksek puan vermiştir; B'nin filmlerinden daha çok izlemiş ama düşük puan vermiştir.

Yararlı adım: puanları kullanıcının ortalama puanını çıkararak normalize etmek.

- Ortalama puan: $(3+5+1+2+4)/5 = 15/5 = 3$.
- A'nın normalize puanları: $3-3 = 0$, $5-3 = +2$. Profil ağırlığı $= (0+2)/2 = 1$.
- B'nin normalize puanları: $1-3 = -2$, $2-3 = -1$, $4-3 = +1$. Profil ağırlığı $= (-2-1+1)/3 = -2/3 \approx -0.67$.

Bu normalizasyon sonrasında 0 nötr, sıfırın altındaki puanlar beğenmeme, sıfırın üstündekiler beğenme anlamına gelir. Sonuç artık açıktır: kullanıcı A'nın filmlerini sever (+1), B'nin filmlerini pek beğenmez (-0.67). İkili örnekte B daha ağır çıkarken puanlar kullanılınca tablo tersine döner.

### 5.6 Tahmin: kosinüs benzerliği

Slayt (ekrandan, 01:35:00):

- Kullanıcı profili $\mathbf{x}$, ürün profili $\mathbf{i}$.
- Tahmin: $u(\mathbf{x},\mathbf{i}) = \cos\theta = \dfrac{\mathbf{x}\cdot\mathbf{i}}{\lVert\mathbf{x}\rVert\,\lVert\mathbf{i}\rVert}$

$\mathbf{x}$ vektöründe A, B ve sistemde tanımlı bütün oyuncuların ağırlıkları vardır; ürün vektöründe de filmin oyuncularına ait değerler vardır. İki vektör aynı uzaydadır. Pay iki vektörün skaler (nokta) çarpımı, payda iki vektörün büyüklüklerinin (norm) çarpımıdır.

Hoca açıya göre yorumu şöyle verir:

| Açı $\theta$ | $\cos\theta$ | Yorum |
|---|---|---|
| $0^\circ$ | 1 | Vektörler aynı yönde, en benzer durum |
| $90^\circ$ | 0 | Vektörler dik, benzerlik yok |
| $180^\circ$ | $-1$ | Vektörler tam zıt yönde |

Kosinüs benzerliği $[-1, 1]$ aralığında değer alır; 1'e ne kadar yakınsa iki vektör o kadar benzerdir.

Slaytın alt kısmında teknik bir not vardır: teknik olarak kosinüs uzaklığı açının kendisidir ($\theta$), kosinüs benzerliği ise $180-\theta$ açısıdır; kolaylık için benzerlik ölçüsü olarak $\cos\theta$ kullanılır ve bu bağlamda buna "kosinüs benzerliği" denir.

**Soru:** Kullanıcı profili ile ürün profilleri arasındaki benzerliği ölçüp açısı en küçük olan, yani $\cos\theta$'yı 1'e en yakın veren ürünleri seçip kullanıcıya mı öneriyoruz? **Cevap:** Evet, aynen öyle.

### 5.7 Artılar ve eksiler

Artılar (ekrandan, 01:40:00):

- **Başka kullanıcıların verisine gerek yoktur.** Öneri yalnız kullanıcının kendi verisinden çıkarılır.
- **Özgün zevkleri olan kullanıcılara öneri yapılabilir.** Önerilen ürünler kullanıcının daha önce beğendiklerine benzediği için tutma ihtimali yüksektir.
- **Yeni ve popüler olmayan ürünler önerilebilir.** İlk puanlayan problemi (first-rater problem) yoktur; benzerlik varsa hiç puanlanmamış ürün de önerilebilir.
- **Önerilen ürünler açıklanabilir.** Kullanıcı ve ürün profilleri açık olduğu için, ürünün hangi içerik öz nitelikleri yüzünden önerildiği söylenebilir.

Eksiler:

- **Uygun öz nitelikleri bulmak zordur.** Film için başrol oyuncusu, senarist vb. sayılabilir, ama her ürün için öz nitelik üretmek kolay değildir.
- **Aşırı uzmanlaşma (overspecialization):** Kullanıcının içerik profili dışındaki ürünler hiç önerilmez. Öneriler hep geçmiştekilere benzer olduğu için kullanıcı yeni şeyler deneyimleyemez. Hoca bunu bir müzik uygulaması örneğiyle anlatır: hep aynı tarz müzik dinleyen bir kullanıcıya öneri listesinde hiç farklı bir tarz gelmez; kullanıcı yeni şeyler dinlemek istese de bunları göremez.
- **Yeni kullanıcılar için soğuk başlangıç:** Kullanıcının geçmişi bilinmiyorsa ne önerileceği belli değildir.

Bu sıkıntılar nedeniyle alternatif bir çözüm olan işbirlikçi filtrelemeye geçilir.

## 6. İşbirlikçi Filtreleme ve Benzerlik Ölçüleri

### 6.1 Fikir

İşbirlikçi filtrelemede yine bir $x$ kullanıcısı ve onun puanları vardır. Ama bu kez veri tabanında $x$'e benzeyen yüzlerce, binlerce kullanıcı aranır. Tercihleri $x$'e en çok benzeyen $N$ kullanıcı seçilir ($N$ ör. 50 ya da 100 olabilir). Bu kullanıcıların tercihleri bilinir; aralarından $x$'in hiç temas etmediği ama bu benzer kullanıcıların incelediği ve beğendiği ürünler $x$'e önerilir. Slayttaki ifadeyle: puanları $x$'in puanlarına benzeyen diğer kullanıcılardan oluşan bir $N$ kümesi bulunur ve $x$'in puanları $N$'deki kullanıcıların puanlarından tahmin edilir.

### 6.2 Örnek matris ve sezgi

Slayttaki matris (ekrandan, 02:05:00): dört kullanıcı (A, B, C, D) ve yedi film (Harry Potter 1-3, Twilight, Star Wars 1-3). Satırlar kullanıcılar, sütunlar filmlerdir.

| | HP1 | HP2 | HP3 | TW | SW1 | SW2 | SW3 |
|---|---|---|---|---|---|---|---|
| A | 4 | | | 5 | 1 | | |
| B | 5 | 5 | 4 | | | | |
| C | | | | 2 | 4 | 5 | |
| D | | 3 | | | | | 3 |

A kullanıcısı üç film izlemiştir: HP1'e 4, Twilight'a 5, SW1'e 1 vermiştir; SW1'i beğenmemiştir.

$x$ ve $y$ kullanıcılarının puan vektörleri $r_x$ ve $r_y$ olsun. Bir benzerlik ölçüsü $\text{sim}(x,y)$ gerekir ve bu ölçü şu sezgiyi yakalamalıdır: $\text{sim}(A,B) > \text{sim}(A,C)$.

**Soru (derste sözlü):** A kullanıcısı B'ye mi daha çok benziyor, C'ye mi? **Cevap:** B'ye. A, C'nin beğenmediğini (Twilight) beğenmiş, C'nin beğendiğini (SW1) beğenmemiştir; A ile C'nin zevkleri ters yöndedir. Benzerlik hesabı ortak puan verilen ürünler üzerinden yapılır.

### 6.3 Seçenek 1: Jaccard benzerliği

Slayt (ekrandan, 02:10:00):

$$\text{sim}(A,B) = \frac{|r_A \cap r_B|}{|r_A \cup r_B|}$$

Jaccard benzerliği yalnız ikili matrisle çalışır, puanları kullanmaz. Matris ikiliye çevrilir: boş hücreler 0, dolu hücreler 1 sayılır. Benzerlik, iki kullanıcının ortak izlediği film sayısının birlikte izledikleri toplam film sayısına oranıdır.

- A ile B: kesişim {HP1} → 1 film; birleşim {HP1, HP2, HP3, TW, SW1} → 5 film. $\text{sim}(A,B) = 1/5 = 0.2$.
- A ile C: kesişim {TW, SW1} → 2 film; birleşim {HP1, TW, SW1, SW2} → 4 film. $\text{sim}(A,C) = 2/4 = 0.5$.

Sonuç $\text{sim}(A,B) < \text{sim}(A,C)$ çıkar; sezgiye terstir. Problem: puan değerleri yok sayılır. Elde yalnız ikili bir matris varsa Jaccard kullanmak zorunludur; ama puanlar varsa Jaccard mantıklı bir çözüm değildir.

### 6.4 Seçenek 2: Kosinüs benzerliği

Slayt (ekrandan, 02:15:00): $\text{sim}(A,B) = \cos(r_A, r_B)$. Boş hücreler 0 kabul edilir:

- $r_A = (4, 0, 0, 5, 1, 0, 0)$
- $r_B = (5, 5, 4, 0, 0, 0, 0)$

Hesap (hoca ekranda adım adım yazar):

- Nokta çarpım: karşılıklı elemanlar çarpılıp toplanır. Yalnız HP1 ortaktır: $4 \cdot 5 = 20$; diğer çarpımların hepsi 0'dır.
- $\lVert r_A \rVert = \sqrt{16 + 25 + 1} = \sqrt{42}$
- $\lVert r_B \rVert = \sqrt{25 + 25 + 16} = \sqrt{66}$
- $\text{sim}(A,B) = \dfrac{20}{\sqrt{42}\,\sqrt{66}} \approx 0.38$

Aynı yolla $\text{sim}(A,C) \approx 0.32$ bulunur. (İkisi de python ile doğrulandı: 0.380 ve 0.322.)

Sonuç $\text{sim}(A,B) > \text{sim}(A,C)$ çıkar, ama fark küçüktür (not by much). Oysa tablodan A'nın B'ye bariz biçimde daha çok benzediği görülüyordu. Problem: eksik puanlar negatif gibi ele alınır. Boş hücrelere 0 yazmak, onları en düşük puan gibi değerlendirmek demektir; bu da benzerlik farkını ortaya koymayı zorlaştırır.

### 6.5 Seçenek 3: Merkezlenmiş kosinüs (Pearson korelasyonu)

Fikir: puanlar satır ortalaması çıkarılarak normalize edilir (normalize ratings by subtracting row mean). Her kullanıcının ortalaması yalnız verdiği puanlar üzerinden hesaplanır:

- $\bar r_A = (4+5+1)/3 = 10/3$
- $\bar r_B = (5+5+4)/3 = 14/3$
- $\bar r_C = (2+4+5)/3 = 11/3$
- $\bar r_D = (3+3)/2 = 3$

A satırında normalizasyon:

- HP1: $4 - 10/3 = 12/3 - 10/3 = 2/3$
- TW: $5 - 10/3 = 15/3 - 10/3 = 5/3$
- SW1: $1 - 10/3 = -7/3$

Normalize edilmiş tablo (ekrandan, 02:20:00):

| | HP1 | HP2 | HP3 | TW | SW1 | SW2 | SW3 |
|---|---|---|---|---|---|---|---|
| A | 2/3 | | | 5/3 | -7/3 | | |
| B | 1/3 | 1/3 | -2/3 | | | | |
| C | | | | -5/3 | 1/3 | 4/3 | |
| D | | 0 | | | | | 0 |

Ham tabloda A'nın SW1'e verdiği 1 puan pozitif bir sayı olduğu için beğenmeme anlaşılmıyordu. Normalizasyondan sonra bu değer negatif olur; 0 nötr kabul edilince negatif değerler beğenmeme işareti hâline gelir. Böylece benzerlik daha doğru ölçülür.

Bu tablo üzerinde kosinüs benzerliği hesaplanır (boşlar yine 0, ama artık 0 "ortalama" anlamındadır):

- $\text{sim}(A,B) = \cos(r_A, r_B) = 0.09$
- $\text{sim}(A,C) = -0.56$

Python ile doğrulandı: 0.092 ve $-0.559$. Artık $\text{sim}(A,B) > \text{sim}(A,C)$ ilişkisi belirgin bir farkla elde edilir; A ile C'nin zıt zevklere sahip olduğu negatif değerden (-1'e daha yakın) görülür. $\text{sim}(A,B)$ değeri 1'e çok yakın değildir, ama iki değer arasındaki fark açılmıştır.

Slayttaki yorumlar: bu ölçü sezgiyi daha iyi yakalar; eksik puanlar "ortalama" gibi ele alınır; "zor puan verenler" (tough raters) ile "kolay puan verenler" (easy raters) arasındaki fark dengelenir. "Centered" adı, her puandan ortalamanın çıkarılmasından, yani verinin merkezlenmesinden gelir.

> **Hocanın vurgusu:** Bu merkezlenmiş kosinüs işleminin literatürdeki bilinen adı Pearson korelasyonudur; bunu unutmayın.

> **Ek bilgi (derste anlatılmadı):** Klasik Pearson korelasyonunda ortalamalar ve toplamlar yalnız iki kullanıcının ortak puanladığı ürünler üzerinden alınır. Burada ise her kullanıcının ortalaması kendi bütün puanlarından alınır ve boş hücreler 0 sayılır; bu yüzden sonuçlar ders kitabındaki biçimle aynı, klasik formülle küçük farklar gösterebilir.

## 7. Puan Tahmini: Kullanıcı-Kullanıcı ve Ürün-Ürün İşbirlikçi Filtreleme

### 7.1 Amaç

Ekranda açık olan, öneri yapılacak kullanıcıya etkin kullanıcı (active user) denir; örnekte A kullanıcısı. A'nın izlemediği her film için (HP2, HP3, SW2, ...) "izleseydi kaç puan verirdi" sorusunun cevabı, yani tahmini puan (estimated rate) bulunmalıdır. Örneğin $\hat r_{A,\text{HP2}}$, A'nın HP2'ye vereceği tahmini puandır. Bu tahminlere göre filmler sıralanır ve yüksek puan alacağı tahmin edilenler A'ya önerilir. Tahmin, A'ya en çok benzeyen kullanıcılar (ör. B ve gösterilmeyen başka benzer kullanıcılar) üzerinden yapılır.

### 7.2 Tahmin formülleri

Slayt (ekrandan, 02:25:00):

- $r_x$: $x$ kullanıcısının puan vektörü.
- $N$: $x$'e en çok benzeyen ve $i$ ürününü de puanlamış $k$ kullanıcının kümesi.
- $x$ kullanıcısı ve $i$ ürünü için tahmin:

Seçenek 1 (basit ortalama):

$$\hat r_{xi} = \frac{1}{k}\sum_{y \in N} r_{yi}$$

Seçenek 2 (benzerlikle ağırlıklı ortalama):

$$\hat r_{xi} = \frac{\sum_{y \in N} s_{xy}\, r_{yi}}{\sum_{y \in N} s_{xy}}, \qquad s_{xy} = \text{sim}(x,y)$$

Birinci seçenekte en benzer $k$ kullanıcının $i$ ürününe verdiği puanlar toplanıp kullanıcı sayısına bölünür. Hoca sınıfa ikinci seçeneğin farkını sorar.

**Soru (derste sözlü):** Birinci çözümde eksik olan ne, ikinci çözüm normal ortalama yerine ne yapmış? **Cevap:** Önce $N$ kümesine yalnız $i$ ürününü puanlamış kullanıcılar alınır; boş olanlar sayılmaz. İkinci çözüm ayrıca ağırlıklandırma yapar: $y$ kullanıcısının $i$ ürününe verdiği puan, $y$'nin $x$'e benzerliği ile çarpılır. Ağırlıklı ortalama alabilmek için payda ağırlıkların (benzerliklerin) toplamına bölünür; bu bölme bir normalizasyondur.

Birinci çözüm benzerliği yalnız hangi kullanıcıların hesaba katılacağını seçmek için kullanır, benzerlik değerini hesaba katmaz. İkinci çözüm daha anlamlı ve daha doğrudur, tercih edilen yöntemdir.

Kullanıcılar arasında benzerlik hesaplandığı için bu yönteme kullanıcı tabanlı işbirlikçi filtreleme (user-based collaborative filtering, user-user CF) denir (ekrandan, 02:30:00).

### 7.3 Ürün-ürün işbirlikçi filtreleme

İşbirlikçi filtrelemenin ikinci türü ürün-ürün (item-item) işbirlikçi filtrelemedir. Kullanıcılar yerine ürünler arasında benzerlik hesaplanır:

- $i$ ürünü için benzer ürünler bulunur.
- $i$ ürününün puanı, benzer ürünlere verilen puanlardan tahmin edilir.
- Aynı benzerlik ölçüleri ve tahmin fonksiyonları kullanılabilir:

$$\hat r_{xi} = \frac{\sum_{j \in N(i;x)} s_{ij}\, r_{xj}}{\sum_{j \in N(i;x)} s_{ij}}$$

Burada $s_{ij}$, $i$ ve $j$ ürünlerinin benzerliği; $r_{xj}$, $x$ kullanıcısının $j$ ürününe verdiği puan; $N(i;x)$ ise $x$'in puanladığı ve $i$'ye en çok benzeyen ürünler kümesidir. $x$'in benzer $j$ ürünlerine verdiği puanlar, $i$ ile $j$ arasındaki benzerlikle ağırlıklandırılıp toplanır ve ağırlıklar toplamına bölünür.

<!-- BELİRSİZ: Ürün-ürün formül slaytının karesi yok; formül altyazıdaki anlatımdan ve slayt dizisinin bilinen biçiminden kuruldu. -->

### 7.4 Ürün-ürün örneği ($|N| = 2$)

Slayt (ekrandan, 02:35:00). Bu örnekte matris ters çevrilmiştir: satırlar filmler (1-6), sütunlar kullanıcılardır (1-12). Sarı hücreler 1-5 arası bilinen puanlar, boş hücreler bilinmeyen puanlardır. Amaç, 5. kullanıcının 1. filme vereceği puanı (soru işaretli hücre) ürün-ürün yöntemiyle ve en benzer 2 film üzerinden tahmin etmektir.

| Film \ Kullanıcı | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | sim(1,m) |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| 1 | 1 | | 3 | | ? | 5 | | | 5 | | 4 | | 1.00 |
| 2 | | | 5 | 4 | | | 4 | | | 2 | 1 | 3 | -0.18 |
| 3 | 2 | 4 | | 1 | 2 | | 3 | | 4 | 3 | 5 | | 0.41 |
| 4 | | 2 | 4 | | 5 | | | 4 | | | 2 | | -0.10 |
| 5 | | | 4 | 3 | 4 | 2 | | | | | 2 | 5 | -0.31 |
| 6 | 1 | | 3 | | 3 | | | 2 | | | 4 | | 0.59 |

Komşu seçimi: 1. filme benzeyen ve 5. kullanıcının puanladığı filmler bulunur. Benzerlik olarak Pearson korelasyonu kullanılır:

- 1) Her $i$ filminden ortalama puan $m_i$ çıkarılır. 1. film için $m_1 = (1+3+5+5+4)/5 = 3.6$; 1. satır $[-2.6,\ 0,\ -0.6,\ 0,\ 0,\ 1.4,\ 0,\ 0,\ 1.4,\ 0,\ 0.4,\ 0]$ olur.
- 2) Satırlar arasında kosinüs benzerlikleri hesaplanır.

Filmin kendisiyle benzerliği en yüksektir (1.00). Diğerleri arasından en yüksek iki benzerlik 6. film (0.59) ve 3. filmdir (0.41).

**Soru (derste sözlü):** 1. filme en benzeyen iki film hangileridir? **Cevap:** 6. film (0.59) ve 3. film (0.41).

Tahmin (ağırlıklı ortalama; 5. kullanıcı 3. filme 2, 6. filme 3 vermiştir):

$$\hat r_{1,5} = \frac{0.41 \cdot 2 + 0.59 \cdot 3}{0.41 + 0.59} = \frac{0.82 + 1.77}{1.00} = 2.59 \approx 2.6$$

Hoca bu son adımı derste ayrıntılı çözmez; öğrencilerden hesabı sonuna kadar yapıp 2.6 sonucunu bulmalarını ister (ara adım eklendi). Benzerlikler ve sonuç python ile doğrulandı (yuvarlanmamış benzerliklerle 2.586).

### 7.5 Hangi yönde benzerlik hesaplanmalı?

**Soru (derste sözlü):** Amazon ya da Netflix gibi bir sitede bu matris hangi yönde daha büyüktür; film sayısı mı, kullanıcı sayısı mı daha fazladır? **Cevap:** Kullanıcı sayısı. Kullanıcı sayısı milyonlarca, milyarlarca olabilir.

Bu durumda benzerliği sayının az olduğu tarafta, yani ürünler (filmler) arasında hesaplamak daha etkilidir: daha ölçeklenebilir ve hesaplama maliyeti daha düşüktür. Matrisin hangi yönde daha uzun olduğuna bakarak benzerliği hangi yönde hesaplamanın daha kolay olacağına karar verilebilir.

> **Hocanın vurgusu:** Uygulamada çoğunlukla tercih edilen yöntem ürün-ürün benzerliğidir.

**Soru:** Önce benzerlikleri hesaplayıp yalnız en benzer iki-üç kullanıcıyı tahmine katıyoruz. Hepsini katsak, benzerlik oranı zaten formülde ağırlık olarak bulunduğu için bir değişiklik olur mu, sonuç daha mı iyi olur? **Cevap:** Sistem maliyetini artırır. Bu sistemlerde kullanıcı sayısı çok büyüktür; hepsini katmak çok büyük bir maliyet getirir ve tahminin anlık yapılması gerekir. Benzerlikleri önceden hesaplayıp saklamak ve sonra kullanmak da bir seçenektir; ama o zaman kullanıcının o ana kadar yaptığı güncel değişiklikler hesaba katılmaz. Belirli sayıda en benzer kullanıcıyı seçmek doğru bir tahmin için yeterlidir.

> **Ek bilgi (derste anlatılmadı):** Negatif benzerlikli komşular ağırlıklı ortalamanın paydasını küçültebilir ya da işaretini bozabilir. Bu nedenle uygulamada çoğunlukla yalnız pozitif benzerlikli en yakın komşular seçilir; örnekte seçilen iki film de pozitif benzerliklidir.

## 8. Güncel Eğilimler

Hoca dersin sonunda öneri sistemlerinde güncel konulara değinir:

- **Derin öğrenme tabanlı hibrit çözümler** konuşulmaktadır.
- **Yorumlardan puan üretme:** Kullanıcılar yalnız puan vermez, yorum da yazar. Yorumun içeriğinin olumlu, olumsuz ya da nötr olduğunu anlamaya yönelik çalışmalar yapılmaktadır.
- **Güvenilir kullanıcılar (trusted users):** Her alanda yetkin ve güvenilir yorum yapan kişiler vardır; bunların yorumlarını öne çıkarmak ve daha fazla dikkate almak bir çözümdür. Örneğin 50-100 yorum yapmış bir kullanıcı mı, sisteme bir kez girip yorum yapmış bir kullanıcı mı daha güvenilirdir sorusu sorulur.
- **Manipülasyonun önlenmesi:** Pazar yeri sitelerinde ürün satan bazı firmalar, olumsuz bir yorum geldiğinde sahte müşteriler yaratarak ya da sahte alışveriş göstererek puanları yükseltmeye çalışabilir. Bu tür manipülasyonların önüne geçmek gerekir.

Hoca, öğrencilerin bu sistemleri yoğun kullandığını hatırlatarak sistemin güvenini sarsabilecek aksaklıklar ve bunların nasıl önlenebileceği üzerine düşünmelerini önerir.

## Örnek Sorular

**Soru 1** (derste sözlü, 02:05:28): Bölüm 6.2'deki A, B, C, D kullanıcıları ve HP1-SW3 filmlerinden oluşan puan matrisine bakarak A kullanıcısının B'ye mi, C'ye mi daha çok benzediğini söyleyin.

> **Çözüm (derste verildi):** B'ye. A ile C'nin puanları ters yöndedir: A, C'nin düşük puan verdiği Twilight'a yüksek, C'nin yüksek puan verdiği SW1'e düşük puan vermiştir. İyi bir benzerlik ölçüsü $\text{sim}(A,B) > \text{sim}(A,C)$ vermelidir.

**Soru 2** (ekrandan, 02:10:00 ve 02:15:00): Aynı matris için $\text{sim}(A,B)$ ve $\text{sim}(A,C)$ değerlerini Jaccard ve kosinüs benzerliğiyle hesaplayın.

> **Çözüm (derste verildi):** Jaccard: $\text{sim}(A,B) = 1/5$, $\text{sim}(A,C) = 2/4$; sezgiye ters, çünkü puanlar yok sayılır. Kosinüs (boşlar 0): $\text{sim}(A,B) = 20/(\sqrt{42}\sqrt{66}) \approx 0.38$, $\text{sim}(A,C) \approx 0.32$; sezgiye uyar ama fark küçüktür.

**Soru 3** (ekrandan, 02:20:00): Aynı matrisi satır ortalamalarını çıkararak merkezleyin ve merkezlenmiş kosinüs benzerliklerini bulun.

> **Çözüm (derste verildi):** Ortalamalar A: $10/3$, B: $14/3$, C: $11/3$, D: 3. A satırı $2/3, 5/3, -7/3$; B satırı $1/3, 1/3, -2/3$; C satırı $-5/3, 1/3, 4/3$; D satırı $0, 0$. $\text{sim}(A,B) = 0.09$, $\text{sim}(A,C) = -0.56$. Bu ölçü Pearson korelasyonudur.

**Soru 4** (derste sözlü, 02:26:08): Puan tahmininde birinci seçenek ($\hat r_{xi} = \frac{1}{k}\sum_{y\in N} r_{yi}$) ile ikinci seçenek arasındaki fark nedir?

> **Çözüm (derste verildi):** İkinci seçenek puanları kullanıcı benzerliği $s_{xy}$ ile ağırlıklandırır ve ağırlıklar toplamına böler; benzerliği yalnız komşu seçmek için değil, katkı oranını belirlemek için de kullanır. Bu nedenle daha doğrudur ve tercih edilir.

**Soru 5** (ekrandan, 02:35:00): Bölüm 7.4'teki 6 film × 12 kullanıcı matrisinde ürün-ürün işbirlikçi filtreleme ile ($|N| = 2$, Pearson benzerliği) 5. kullanıcının 1. filme vereceği puanı tahmin edin. 1. filme en benzer iki film hangileridir?

> **Çözüm (derste kısmen verildi):** En benzer iki film 6 (0.59) ve 3 (0.41). 5. kullanıcının bu filmlere puanları 3 ve 2. $\hat r_{1,5} = (0.41\cdot 2 + 0.59\cdot 3)/(0.41+0.59) \approx 2.6$. Son adım ödev olarak bırakıldı; sonuç python ile doğrulandı.

**Soru 6** (derste sözlü, 02:35:50): Aynı matrisi kullanıcı-kullanıcı işbirlikçi filtreleme için kullanıp 5. kullanıcının 1. filme vereceği tahmini puanı hesaplayın.

> **Çözüm (derste verilmedi):** Çözüm python ile hesaplandı. Sütunlar kullanıcı vektörü olarak alınır, her kullanıcının ortalaması kendi puanlarından çıkarılır (5. kullanıcının ortalaması $(2+5+4+3)/4 = 3.5$) ve kullanıcılar arasında merkezlenmiş kosinüs hesaplanır. 1. filmi puanlamış kullanıcılar (1, 3, 6, 9, 11) arasında 5. kullanıcıya en benzer ikisi 9. kullanıcı ($\approx 0.47$, puanı 5) ve 3. kullanıcıdır ($\approx 0.21$, puanı 3). $\hat r_{5,1} = (0.474\cdot 5 + 0.214\cdot 3)/(0.474+0.214) \approx 4.38$. Ürün-ürün yöntemiyle bulunan 2.6'dan farklı bir sonuç çıkması, iki yöntemin farklı komşuluk bilgisi kullanmasından kaynaklanır.

**Soru 7** (derste sözlü, 02:36:18): Amazon ya da Netflix gibi bir sitede fayda matrisi hangi yönde daha büyüktür ve benzerlik hangi yönde hesaplanmalıdır?

> **Çözüm (derste verildi):** Kullanıcı sayısı ürün sayısından çok fazladır. Benzerliği sayının az olduğu ürünler tarafında (ürün-ürün) hesaplamak daha ölçeklenebilir ve ucuzdur; bu yüzden ürün-ürün benzerliği çoğunlukla tercih edilir.

## Dersin Toparlaması

Bu derste öneri sistemlerinin neden gerekli olduğu uzun kuyruk olgusuyla açıklandı: çevrim içi ortam çok sayıda az satan ürünü sunabilir, ama bu bolluk iyi bir filtre gerektirir. Öneri problemi, kullanıcılar ile ürünler arasındaki seyrek bir fayda matrisinin bilinmeyen hücrelerini tahmin etmek olarak tanımlandı; puan toplama (açık ve örtük), seyreklik ve soğuk başlangıç temel zorluklar olarak konuşuldu.

İçerik tabanlı öneride yalnız kullanıcının kendi puanlarından ürün ve kullanıcı profilleri çıkarıldı ve kosinüs benzerliğiyle eşleştirildi; ortalama çıkararak normalizasyonun beğenmeyi negatif değerlerle görünür kıldığı gösterildi. İşbirlikçi filtrelemede Jaccard, kosinüs ve merkezlenmiş kosinüs (Pearson korelasyonu) aynı örnek üzerinde karşılaştırıldı; en iyi sonucu Pearson korelasyonu verdi. Puan tahmini için benzerlikle ağırlıklı ortalama tercih edildi; kullanıcı-kullanıcı ve ürün-ürün türleri anlatıldı ve büyük sistemlerde ürün-ürün benzerliğinin daha ölçeklenebilir olduğu vurgulandı. Slayt dizisindeki gizli faktör (matris ayrıştırma) yöntemlerine bu derste girilmedi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
