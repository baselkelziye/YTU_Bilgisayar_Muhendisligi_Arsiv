# Ders 9 Genişletilmiş Notu: Öğrenci Seminer Sunumları: Öneri Sistemleri, Görüntü Manipülasyonu Tespiti ve Çekişmeli Üretici Ağlar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Yapısı
- 2. Sunum 1: Öneri Sistemleri
- 3. Sunum 2: Görüntü Manipülasyonu ve Tespit Yöntemleri
- 4. Sunum 3: Çekişmeli Üretici Ağlar (GAN) ile Sentetik Görüntü Üretme
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Yapısı

Bu ders, dönemin son seminer oturumudur. Üç doktora öğrencisi, doktora çalışmalarına giriş niteliğindeki literatür araştırmalarını sundu. Her sunum yaklaşık yarım saat olarak planlandı: yaklaşık 20 dakika anlatım, kalan süre soru-cevap. Hoca her sunumdan sonra soru sordu, yorum yaptı ve sunucuya ek kaynak önerdi. Bu not sunumların teknik içeriğini ve soru-cevapları aktarır; sunucuların kimliğine ve kişisel çalışma bilgilerine yer verilmez.

## 2. Sunum 1: Öneri Sistemleri

### 2.1 Öneri sistemlerine neden ihtiyaç var?

Sunum, internetteki veri miktarının çok büyük olmasından başladı. Bu kadar verinin içinden ihtiyaç duyulan bilgiye erişmek ayrı bir sorun haline gelmiştir. Arama motorları bilgiye erişimde bir dereceye kadar kullanılsa da doğrudan kişinin ihtiyacı olan bilgiyi bulmakta yetersiz kalır, çünkü kişiselleştirilmiş değildir. Bu yüzden öneri sistemlerinin kullanımı ön plana çıkmaktadır (ekrandan, 00:20:00).

Öneri sistemlerinin kökeni bilgi erişimi (information retrieval) çalışmalarına dayanır ve zamanla ayrı bir araştırma alanına dönüşmüştür. Öneri sistemi, kullanıcının bir çaba göstermesine gerek kalmadan ihtiyaç duyabileceği veriyi ya da ürünü doğrudan önerir. Önemli bir amacı da kullanıcıya daha önce bilmediği şeyleri önererek yeni şeyler keşfetmesini sağlamaktır. Video izleme siteleri, müzik platformları ve alışveriş siteleri en bilinen kullanım alanlarıdır. Günümüzdeki öneri sistemleri makine öğrenmesi ve derin öğrenme gibi yöntemleri kullanır.

Öneri sistemleri temelde üç kategoriye ayrılır ve her birinin alt kırılımları vardır:

- İçerik tabanlı filtreleme
- İşbirlikçi (collaborative) filtreleme
  - Bellek tabanlı: kullanıcı tabanlı ve öğe tabanlı
  - Model tabanlı
  - Hibrit
- Hibrit filtreleme

### 2.2 İçerik tabanlı filtreleme

İçerik tabanlı filtrelemede özellikler kullanılarak öneri yapılır ve makine öğrenmesi yöntemlerinden yararlanılır. Sunumdaki örnekte bir sisteme üye olan kullanıcının belirli özelliklere (örneğin eğitim durumu, cinsiyet, ilgi alanı) sahip olduğu düşünüldü: sistem kullanıcıyı bu özelliklere benzeyen kişilerle eşleştirir ve onların daha önce tercih ettiklerini önerir. Sunucu bu yaklaşımda çok fazla kişiselleştirme olmadığını, önerinin benzerlik üzerinden yapıldığını belirtti.

> Ders sonrası not: Bu örnek büyük olasılıkla daha çok demografik filtrelemeye ya da kullanıcı benzerliğine dayalı bir yaklaşıma uyar. İçerik tabanlı filtreleme, büyük olasılıkla öğelerin özellikleri ile kullanıcının daha önce beğendiği öğelerin özelliklerini karşılaştırarak öneri yapar.

Avantajı, kullanıcının profil bilgileri değişip başka kişilere benzemeye başladığında önerilerin de buna göre güncellenebilmesidir. Dezavantajları şunlardır:

- Kullanıcıyı başkalarına benzetebilmek için onun hakkında yeterli bilgi gerekir; kullanıcı kendine ait özellik belirtmezse öneri yapmak zorlaşır.
- Özellik vektörünü oluşturmak zordur.
- Sistem hep aynı özelliklerden öğrendiği için aşırı uzmanlaşma sorunu ortaya çıkar.

### 2.3 İşbirlikçi filtreleme

İşbirlikçi filtreleme, öneriyi kullanıcıların geçmişteki değerlendirmeleri (puanları) üzerinden yapar. Kullanıcıların yaptığı değerlendirmelerden birbirlerine benzerlikleri bulunur ve kullanıcının bir sonraki aşamada hangi öğeye en yüksek puanı vereceği tahmin edilerek öneride bulunulur.

**Kullanıcı tabanlı filtreleme.** Öneri yapılacak kullanıcıya benzeyen kullanıcılar bulunur ve onların değerlendirmeleri üzerinden öneri yapılır. Önerilen öğenin özelliklerine bakılmaz. Kullanıcılar arasındaki benzerlik, genellikle iki kullanıcının değerlendirme puanlarını gösteren vektörler arasındaki kosinüs benzerliği ya da Pearson korelasyon katsayısı ile hesaplanır (ekrandan, 00:25:00).

> **Ek bilgi (derste anlatılmadı):** İki puan vektörü $u$ ve $v$ için kosinüs benzerliği $\cos(u,v) = \dfrac{u \cdot v}{\lVert u\rVert\,\lVert v\rVert}$ biçimindedir. Pearson korelasyon katsayısı aynı hesabı her kullanıcının ortalama puanını çıkardıktan sonra yapar; böylece hep yüksek ya da hep düşük puan veren kullanıcıların eğilimi dengelenir.

**Öğe tabanlı filtreleme.** Sunucu bir film platformunu örnek verdi: milyonlarca kullanıcı arasındaki benzerlikleri bulmak yerine, sayıca çok daha az olan (on binlerce) film arasındaki benzerlikleri bulmak daha uygundur. Öneri, öğeler arası benzerlik üzerinden yapılır; benzerlik ölçüsü yine kosinüs benzerliği ya da Pearson korelasyon katsayısı olabilir.

**Model tabanlı filtreleme.** Bellek tabanlı yöntemde bütün kullanıcılar ya da bütün ürünler üzerinden işlem yapılırken model tabanlı yöntemde veriden bir model öğrenilir ve hesaplar bu model üzerinden yapılır. Modelin öğrenilmesinde veri madenciliği ve makine öğrenmesi teknikleri kullanılır. Kullanıcı sayısı çok arttığında bellek tabanlı yöntemlerle işlem yapmak zorlaşır; model tabanlı yöntemlerde tekil değer ayrışımı (SVD), boyut indirgeme ve kümeleme gibi işlemlerle işlenecek veri azaltılır ve daha performanslı bir sistem elde edilir.

**Hibrit işbirlikçi filtreleme.** Bellek tabanlı ve model tabanlı teknikler birleştirilir; genel olarak teknikler ayrı ayrı uygulanır, ardından çıktılar birleştirilir.

İşbirlikçi filtrelemenin avantajları:

- İçerik tabanlı filtrelemeye göre performansı genelde daha iyidir ve daha iyi tavsiyeler verir.
- Bellek tabanlı yöntemlerin uygulanması nispeten basittir; yeni kullanıcı ve veriler sisteme artımlı olarak eklenebilir.
- Model tabanlı yöntemlerin performansı bellek tabanlılara göre daha iyidir.

Dezavantajları:

- Hiç değerlendirilmemiş öğelere ya da hiç değerlendirme yapmamış kullanıcılara öneri yapmak zordur (soğuk başlangıç problemi).
- Ürün ve kullanıcı sayısı çok olduğunda ek hesaplama maliyeti doğar.

### 2.4 Hibrit filtreleme

Hibrit yöntemler, en üst düzeydeki iki yaklaşımın (içerik tabanlı ve işbirlikçi) güçlü yönlerini birleştirerek özgün bir öneri sistemi sunar. Avantajı, iki yöntemin dezavantajlarının üstesinden gelmeye çalışmasıdır; dezavantajı karmaşık, uygulamasının zor ve pahalı olmasıdır.

### 2.5 Öneri sistemlerinin sorunları

Sunucu literatürde öneri sistemlerinin sorunlarını sekiz kategoride topladı (ekrandan, 00:30:00):

- **Soğuk başlangıç:** Sisteme yeni katılan kullanıcı ya da yeni eklenen ürün hakkında hiç değerlendirme olmadığı için öneri yapmak zordur. Öğe ve kullanıcı olmak üzere iki türü vardır.
- **Ölçeklenebilirlik:** Kullanıcı ve öğe sayısı arttıkça öneri için gereken işlem sayısı artar ve daha fazla sistem kaynağı gerekir (ekrandan, 00:15:00).
- **Seyreklik (kıtlık):** Örneğin bir film platformunda milyonlarca kullanıcı olsa da herkes değerlendirme yapmaz. Kullanıcıları ve öğeleri bir matrise yerleştirdiğimizde çok fazla boş hücre oluşur (seyrek matris); bu da öneriyi zorlaştırır ve hesaplamayı artırır.
- **Gizlilik:** Daha doğru öneri için yaş, cinsiyet gibi kişisel bilgiler kullanılmak istenebilir; kişiyi daha çok tanımlayan veri kullanıldıkça kullanıcının mahremiyeti ihlal edilmiş olur.
- **Aşırı uzmanlık:** Sistem kullanıcıya sürekli benzer şeyler önerir ve kullanıcının yeni şeyler keşfetmesi engellenir. Oysa öneri sistemlerinin amaçlarından biri yeni şeyler keşfettirmektir.
- **Öngörülebilirlik:** Kullanıcının tercih etmeyeceği bir öneri sürekli tekrarlanırsa sorun olur; kullanıcı onu yine seçmez ve yeni şeylere ulaşamaz.
- **Kullanıcı tercihlerinin değişmesi:** Hep aksiyon filmi izleyen bir kullanıcı artık başka türleri izlemek istiyor olabilir; sistem eski değerlendirmelere dayanarak aksiyon filmi önermeye devam ederse kullanıcı bunları seçmez.
- **Eşanlamlılık:** Özellikle e-ticarette ürünler isim benzerliği üzerinden gruplanırken alakasız ürünler kullanıcılara önerilebilir.

### 2.6 Literatürdeki çalışmalar

Sunucu, literatürdeki çalışmaların çoğunun öneri sistemlerinin performansını iyileştirmeye ve bu sorunlara çözüm getirmeye yönelik olduğunu belirtti (ekrandan, 00:35:00). Dört örnek çalışma anlattı:

- **Soğuk başlangıca karşı bilgi toplama (2017):** Kullanıcıdan açık ve örtük bilgi alma yöntemleri karşılaştırılmıştır. Açık yöntemde kullanıcı sisteme katıldıktan sonra ilgi alanları anketle sorulur ve seçimlerine göre öneri yapılır; dezavantajı herkesin anketi doldurmak istememesidir. Örtük yöntemde kullanıcının sosyal medya hesaplarından ya da kayıt sırasında girdiği yan bilgilerden yararlanılır. Çalışma, hibrit tekniklerin daha doğru sonuç verdiği sonucuna varmıştır.
- **Bağlamsal bilgi kullanımı (2020):** Kullanıcının yaşadığı yer, cinsiyet gibi bağlamsal bilgileri kullanmak önerilmiştir. Bir bağlam kümeleme programı yazılmış, bağlamsal bilgiler k-ortalamalar ile kümelenmiş ve bu kümeler üzerinden işbirlikçi filtrelemeyle öneri yapılmıştır. <!-- BELİRSİZ: programın adı altyazıda "COICI" olarak geçiyor, karelerde görülmedi; "kamis kümeleme" k-ortalamalar (k-means) olarak yorumlandı. -->
- **İşbirlikçi filtreleme ve korelasyon faktörleri (2020):** İki yaklaşım birleştirilerek daha az veriyle daha doğru öneri yapan özgün bir sistem önerilmiştir.
- **Başarı ölçümü (2017):** Bir önerinin başarılı olup olmadığının neye göre ölçüleceği incelenmiştir. Puan tahmini doğruluğunu ölçen ölçütler ve kullanım tahmini doğruluğunu ölçen ölçütler ele alınmış, avantaj ve dezavantajları deneysel sonuçlarla değerlendirilmiştir.

### 2.7 Sonuç

Sunucu, etkin bir öneri sistemi kurmanın birçok faktöre bağlı olduğunu vurguladı: hangi platformda kullanılacağı, kullanıcı sayısı ve eldeki sistem kaynakları model seçimini belirler. Doğru öneriler kullanıcıya zaman kazandırır ve memnuniyetini artırır. Önerilerin kişiselleştirilmiş olması ve hibrit yaklaşımlar öne çıkan bir yön olarak gösterildi (ekrandan, 00:40:00).

Hoca konuyu güzel bulduğunu, ancak doktora düzeyinde bir çalışmanın daha teorik bir katkı da içermesi gerektiğini söyledi. Bu yönde çalışmaları ve sohbete eklediği bir makaleyi incelemeyi önerdi; aksi halde konunun sıkışıp kalabileceğini ve çok ilerleyemeyebileceğini belirtti.

> **Hocanın vurgusu:** Doktora çalışmasında yalnız uygulama yeterli değildir; teorik yönü güçlendiren çalışmalar incelenmelidir.

## 3. Sunum 2: Görüntü Manipülasyonu ve Tespit Yöntemleri

İkinci sunum, görüntü manipülasyonu ve manipülasyon tespit yöntemleri üzerine bir literatür taramasıydı. Konunun sağlık alanında ve uzaktan algılama görüntülerinde ihtiyaç duyulan bir konu olduğu belirtildi. Sunum dört bölümden oluştu: giriş ve tarihçe, manipülasyon tipleri, manipülasyon tespit teknikleri ve tıbbi görüntülerde manipülasyon.

### 3.1 Tarihçe

İlk fotoğraf, Fransız mucit Joseph Nicéphore Niépce tarafından 1826'da çekilmiştir. Fotoğrafın çekimi yaklaşık 8 saat sürmüş; Le Gras'taki evinin penceresinden sokağı gösterir ve "Le Gras'ta pencereden görünüm" adıyla bilinir. Niépce fotoğrafçılığın kurucusu kabul edilir.

> Ders sonrası not: Sunumun bir yerinde ilk fotoğraf için 1824 yılı da söylendi. Le Gras'taki fotoğraf büyük olasılıkla 1826 ya da 1827 yılına tarihlenir; 1824 doğru değildir.

Fotoğraf üzerinde yapılan her türlü değişiklik, küçük ya da büyük olması fark etmeksizin manipülasyondur; tek bir noktayı silmek bile manipülasyon sayılır. Dijital ortamda yapılanına "fotoşop" denir. Manipülasyon birden çok fotoğrafı birleştirme yoluyla olabileceği gibi tek bir fotoğraf üzerindeki deformasyonlar da olabilir. Eskiden insanlar kayıp ve hatta ölmüş akrabalarını fotoğraflarda görmek, sanatsal deneyler yapmak ve siyasi hiciv ifade etmek için manipülasyona başvurmuştur. Günümüzde bunlara ek olarak kurum ve kuruluşları kandırmak, dolandırıcılık ve küçük düşürmek gibi amaçlarla da kullanılmaktadır (ekrandan, 00:45:00).

Tarihsel örnekler:

- **1860'lar:** İlk bilinen manipülasyonlardan biri, Abraham Lincoln'ün başının başka birinin vücuduna yerleştirildiği fotoğraftır; bugün internette Lincoln aratıldığında çıkan ünlü fotoğraflardan biridir.
- **1910'lar:** Fotoğraf firmaları kurulmaya başlanmış; fotoğrafta bulunmasını istediğiniz ama başka şehirde olan bir kişinin fotoğrafı sizin fotoğrafınıza eklenebilir hale gelmiştir. Daha sonra ölen ya da kaybolan yakınların eklenmesi başlamış; literatürde buna "hayalet fotoğraf" denmiştir.
- **Lincoln hayaleti:** Lincoln'ün ölümünden sonra eşinin arkasına onun silüetinin yansıtıldığı fotoğraf, tarihteki ilk hayalet fotoğraflardan biri olarak geçer. <!-- BELİRSİZ: yıl altyazıda 1870 olarak geçiyor; büyük olasılıkla 1870'lerin başına tarihlenir. -->
- **Siyasi hiciv:** Bir fotomontaj sanatçısı, Hitler'i gülünç duruma düşüren fotomontajlar yapmıştır.
- **1932:** Bir fotoğrafçının kendi portresini başka bir yüzle birleştirdiği fotoğraf, günümüzdeki Instagram ve Snapchat filtrelerinin öncüsü olarak gösterildi.
- **1948:** Bir lambanın direğinin bir insan figürüne benzetildiği, döneminin koşullarına göre çok başarılı sayılan bir manipülasyon örneği.

> Ders sonrası not: Siyasi hiciv örneğinde sunucu sanatçının asıl adı ile takma adını ters söyledi. Büyük olasılıkla sanatçının asıl adı Helmut Herzfeld, kullandığı ad John Heartfield'dır ve fotomontajları 1930'larda, Nazi döneminde yayımlanmıştır. 1932 örneği büyük olasılıkla Wanda Wulz'un kendi portresini bir kedi yüzüyle birleştirdiği "Io + gatto" fotoğrafıdır.

Günümüzden örnekler (ekrandan, 00:50:00): iki siyasetçinin yüzlerinin deepfake ile birleştirildiği bir görüntü (yüzü tanınan kişilerde fark edilebilir, ama tanınmayan biri olsa tespit çok daha zor olurdu), Eyfel Kulesi'yle yapılmış bir montaj ve sosyal medyada yayılan komik düğün fotoğrafları.

### 3.2 Manipülasyon tipleri

Sunucu manipülasyon tiplerini beş başlıkta topladı:

- **Görüntü ekleme (splicing):** Aynı ya da farklı kaynaklardan gelen görüntülerde bir kaynaktaki nesne diğerine eklenir. Örnekte piramitlerin üzerine bir balon eklenmişti. Bu yolla insanlar hiç bulunmadıkları bir yerde varmış gibi gösterilebilir.
- **Kopyala-taşı (copy-move):** Aynı görüntüdeki bir nesne alınıp bir ya da birden çok kez çoğaltılır; amaç genelde bir şeyi gizlemek ya da abartmaktır. Kesip taşıma ve görüntüden silme de bu başlık altında toplandı. Örnekte orijinalinde üç füze ateşlenen bir fotoğrafta dördüncü füze eklenmişti. Sunucu, böyle bir görüntünün basına sızdırılmasının askeri güç gösterisi olarak siyasi sonuçları olabileceğini belirtti.
- **Rötuş:** Görüntüde küçük değişiklikler yapılır (yüzdeki leke ya da sivilceyi gizlemek gibi). Asıl görüntü korunduğu için en zararsız manipülasyon türü olarak sınıflandırılır.
- **Dönüştürme (morphing):** Hareketli görüntülerde çeşitli tekniklerle bir kişinin başka birine dönüştürülmesidir. Günümüzdeki en bilinen örneği deepfake'tir: videoda konuşan kişinin yüzü başka birinin yüzüyle değiştirilir ve o kişi söylüyormuş izlenimi yaratılır. Siyasi ve adli sonuçları nedeniyle en tehlikeli manipülasyon türü olarak görüldü.
- **Yeniden renklendirme:** Gri tonlamalı görüntülerin RGB renklerle renklendirilmesidir. Eski siyah-beyaz fotoğraflar günümüzde sık sık renklendirilmektedir. Bu teknik ayrıca nesne tanıma algoritmalarını şaşırtmak ve test etmek için belirli görüntülere kasıtlı olarak uygulanır; akademik çalışmalarda genelde bu amaçla kullanılmıştır (ekrandan, 00:55:00).

### 3.3 Manipülasyon tespit tekniklerinin sınıflandırılması

Sunucu tespit tekniklerini iki ana eksende sınıflandırdı.

**Yöntemin şekline göre:**

- **Aktif yöntemler:** Görüntüye ek bilgi yerleştirilir. Örneğin bir kurum belgelerindeki görüntülere kendi logosunu ya da filigranını ekler; ya da görüntüye benzersiz bir dijital işaret veya kod gömülür. Görüntü üzerinde doğrudan işlem yapıldığı için "aktif" denir.
- **Pasif yöntemler:** Görüntüye hiçbir şey eklenmez ya da çıkarılmaz; görüntünün içine bakılarak, istatistiksel algoritmalarla manipülasyon tespit edilmeye çalışılır.

**Çalışmanın dönemine göre:**

- **Klasik yöntemler:** Görüntü bloklarına dayalı algoritmalar, histogram tabanlı algoritmalar ve görüntü kalitesi ölçümüne dayalı algoritmalar.
- **Güncel yöntemler:** Yapay sinir ağları, derin öğrenme ve transfer öğrenmenin kullanıldığı çalışmalar.

### 3.4 Klasik yöntemler

**Blok tabanlı yöntem.** Elde hem orijinal hem manipüle edilmiş görüntünün bulunduğu varsayılır. Manipüle görüntüden bloklar (örneğin $4\times4$) alınır ve orijinal görüntü üzerinde kaydırılarak eşleştirme yapılır. Görüntü boyutu ve blok boyutu işlem sayısını belirlediği için bu, iki görüntü üzerinde gezinmeyi gerektiren maliyetli bir işlemdir. En önemli kısıt, orijinal görüntünün de elde olmasının gerekmesidir.

**Histogram tabanlı yöntem.** Genelde renklendirme manipülasyonunu tespit etmek için kullanılmıştır. Bu alandaki ilk çalışmada orijinal fotoğraflar ile renklendirilmiş fotoğraflar arasında ton, doygunluk, aydınlık ve karanlık kanallarında istatistiksel fark olduğu görülmüştür. Bütün kanalların histogramı çıkarılmış ve aralarındaki farka odaklanılmıştır; fark varsa manipülasyon olduğuna karar verilmiştir. <!-- BELİRSİZ: çalışmanın yazarı altyazıda "Guava ve arkadaşları" olarak geçiyor, karelerde görülmedi. -->

**Görüntü kalitesi ölçümü** (ekrandan, 01:00:00). Görüntü kalitesi, farklı görüntüleme sistemlerinin bir görüntüyü oluşturan sinyalleri yakaladığı, işlediği, ilettiği ve görüntülediği doğruluk düzeyidir. Bu yöntem bir referansa göre çalışır:

- **Tam referans:** Test görüntüsünün kalitesi, mükemmel kalitede olduğu varsayılan bir referans görüntüyle karşılaştırılarak değerlendirilir.
- **Azaltılmış referans:** Her iki görüntüden çıkarılan özelliklerin karşılaştırılmasına dayanarak test ve referans görüntülerinin kalitesi değerlendirilir.
- **Referanssız:** Orijinal bir görüntü olmadan test görüntüsünün kalitesi değerlendirilmeye çalışılır.

Kalite metriğine göre hesap yapılarak bozulma tespit edilir; buna "görüntü kalite ölçümü" denir.

Sunucu klasik yöntemlerle yapılmış beş çalışma buldu. Hepsi tek bir manipülasyon tipine (kopyala-taşı, yeniden renklendirme, döndürme gibi) odaklanmıştı. Kopyala-taşı çalışmalarında bloklar arası benzerlik ve kaydırma yöntemi kullanılmıştı. Bu çalışmaların ortak özelliği, araştırmacıların orijinal görüntü gerektiği için genelde kendi görüntülerini kendileri manipüle ederek veri oluşturmasıydı.

### 3.5 Veri kümeleri

Güncel yöntemlerde kullanılan başlıca veri kümeleri CASIA 1.0, CASIA 2.0, CoMoFoD ve COVERAGE'dır. Bazı veri kümeleri çok büyük, bazıları çok küçüktür. Büyük bir veri kümesinde videolardan kare kare alınan görüntüler de bulunduğu için görüntü sayısının yüksek çıktığı belirtildi. <!-- BELİRSİZ: veri kümesinin adı altyazıda "Sulfa", görüntü sayısı "45001" ve video sayısı 150 olarak geçiyor; karelerde görülmedi. -->

- **COVERAGE:** En yeni veri kümelerinden biridir; 100 orijinal ve 100 manipüle görüntü içerir. Ayrıntıya çok önem verilmiştir; manipülasyonu gözle görmek çok zordur.
- **CoMoFoD:** Çalışmalarda en sık karşılaşılan veri kümesidir; derste yaklaşık 5200 görüntü içerdiği ve eğitim için yeterli olduğu söylendi.

Örnekler (ekrandan, 01:05:00): CoMoFoD örneklerinde bir kuşun kopyalanıp iki kuş yapıldığı ve büyük bir taşın silindiği görüntüler gösterildi. COVERAGE örneklerinde ise orijinal ile manipüle görüntü neredeyse aynıydı: bir tabelada otobüs durağı numaraları "1, 2" iken manipüle görüntüde "1, 1" olmuştu; diğer örnekte bir harfteki küçük bozulma kopyalama ile ortadan kaldırılmıştı.

### 3.6 Güncel yöntemler

Güncel yöntemler yapay sinir ağlarıyla başlar; derin öğrenme ve transfer öğrenme de yapay sinir ağlarından türemiştir. Yapay sinir ağları biyolojik sinir sistemini taklit eder, çok katmanlı olabilir ve paralel çalışabilir. Örüntü tanıma ve sınıflandırmada başarılıdır ve eksik ya da hatalı veriye karşı hata toleransı vardır. Bir yapay sinir hücresi beş bileşenden oluşur: girdiler, ağırlıklar, toplama fonksiyonu, aktivasyon fonksiyonu ve çıktı. Bu çalışmada girdiler görüntülerdir; ağırlıklar eğitim sırasında hangi özelliğin baskın olacağını belirler; ağırlıklı girdiler toplanıp aktivasyon fonksiyonuna verilir ve çıktı elde edilir.

Derin öğrenme, sonuçları iyileştirmek için her adımda değişiklik yaparak veriden öğrenen bir makine öğrenmesi yaklaşımıdır; sanal asistanlar, sohbet botları, makine çevirisi ve sürücüsüz araçlar örnek verildi. LSTM, tekrarlayan sinir ağlarının (RNN) bir türü olarak anıldı. Transfer öğrenme, bir problem için geliştirilmiş bir modelin başka bir probleme uyarlanmasıdır; ImageNet yarışması için geliştirilen AlexNet gibi modellerin başka görüntü sınıflandırma problemlerinde kullanılması buna örnektir.

Güncel yöntemlerin en önemli avantajı genel bir manipülasyon tespiti yapabilmeleridir: kopyala-taşı, renklendirme, kesme ve silme gibi türlerin hepsini kapsayan bir yöntem geliştirilebilir. Günümüzdeki çalışmaların çoğu da bu yöndedir.

Hoca bu bölümde deepfake tespitiyle ilgili bir veri kümesinin listede olup olmadığını sordu (bkz. Örnek Sorular). Hoca, deepfake tespiti üzerine makale olmasa bile bildiri bulunabileceğini, ayrıca Kaggle'ın bu konuda bir yarışma düzenlediğini ve yarışmada dereceye giren yöntemlerin alanda yaygın kullanılan yöntemler olduğunu söyledi; ilgili bir veri kümesini de sohbetten paylaştı.

> **Hocanın vurgusu:** Bir konuda dergi makalesi az olsa bile konferans bildirileri ve yarışmalar (örneğin Kaggle) güncel yöntemler için önemli kaynaklardır.

### 3.7 Tıbbi görüntülerde manipülasyon

Tıbbi görüntüler de manipüle edilebilir. Görüntülerin merkezi sistemlerde tutulması görece yenidir; daha önce tomografi, MR gibi görüntüler CD ya da film olarak hastanın elinde başka bir kuruma götürülüyordu ve üzerinde değişiklik yapılmadığının garantisi yoktu. Bir kişi örneğin engelli raporu almak (vergi indirimi, ücretsiz ulaşım gibi haklar için) amacıyla görüntüye bir kırık ya da lezyon ekleyebilir. Ekrandaki örneklerde bir karaciğer kesitine ve bir eklem röntgenine eklenmiş bulgular gösterildi (ekrandan, 01:10:00).

Bu alandaki çalışmalar genelde aktif algılama yöntemleriyle yapılmıştır ve en sık kullanılan yöntem filigran eklemektir:

- Bir çalışmada Huffman sıkıştırmasıyla oluşturulmuş bir filigran tersine çevrilebilir şekilde uygulanmıştır.
- Başka bir çalışmada filigran şematik olarak kullanılmış, biçimsel bir model tasarlanarak analizler yapılmıştır.

Güncel (derin öğrenme tabanlı) yöntemlerle yapılmış çalışma azdır.

## 4. Sunum 3: Çekişmeli Üretici Ağlar (GAN) ile Sentetik Görüntü Üretme

### 4.1 Neden sentetik veri?

Çekişmeli üretici ağlar (Generative Adversarial Networks, GAN) ses üretimi, video karesi tahmini ve 3B görüntü üretimi gibi farklı amaçlarla kullanılabilir. Sunum, GAN'ın sentetik görüntü üretme yeteneğine odaklandı.

Derin öğrenme modelleri iyi sonuç vermek için çok fazla veri ister; sınıflandırma, regresyon ya da bölütleme fark etmez. Veri seti hazırlamak ise maliyetlidir ve otomatikleştirilmesi gerekir. GAN'dan önce de veri çoğullama (data augmentation) gibi basit teknikler ve otomatik kodlayıcı (autoencoder), varyasyonel otomatik kodlayıcı (VAE) gibi üretici modeller vardı. Sunucu, bu eski üretici modellerin büyük kısmının Markov zinciri tabanlı olduğunu, bunun karmaşık hesaplamalar gerektirdiğini belirtti. GAN Markov zinciri kullanmaz, öğrenme sırasında çıkarım gerektirmez ve çok karmaşık hesaplamalara ihtiyaç duymaz; bu yüzden daha kullanışlı bir alternatif olarak önerilmiştir.

> **Ek bilgi (derste anlatılmadı):** Markov zincirine dayanan klasik üretici modellere örnek olarak büyük olasılıkla kısıtlı Boltzmann makineleri ve derin inanç ağları gösterilebilir. VAE ise Markov zinciri kullanmaz, varyasyonel çıkarımla eğitilir; bu yüzden sunumdaki genelleme her model için geçerli değildir.

### 4.2 GAN'ın temel yapısı

GAN iki bileşenden oluşur ve ikisi de yapay sinir ağıdır (çok katmanlı algılayıcı ya da daha sık olarak evrişimli ağlar):

- **Üretici (generator, G):** Rastgele bir gizli vektörden (gürültüden) sentetik veri üretmeye çalışır.
- **Ayırıcı (discriminator, D):** Üretilen sentetik verinin gerçek veriden farklı olduğunu, yani hangisinin sahte hangisinin gerçek olduğunu ayırt etmeye çalışır.

İkisi birbiriyle yarışır; bu yapı oyun teorisinden gelir. Nash dengesi denen optimum noktaya ulaşana kadar bir minimax oyunu oynanır. Üretici, ayırıcıdan gelen geri bildirimle ağırlıklarını güncelleyerek gerçeğe benzeyen veri üretmeyi öğrenir; ayırıcı ise üreticinin verilerinin sahte olduğunu yakalamaya çalışır.

GAN kullanımı son yıllarda üstel olarak arttığı için çok sayıda türü vardır. Sunucu, bir sınıflandırmayı esas alarak temel modellerden Vanilla GAN ve DCGAN'ı, uzantılardan Conditional GAN, InfoGAN, AC-GAN ve Pix2Pix'i, ileri modellerden CycleGAN ve Progressive GAN'ı anlattı.

### 4.3 Vanilla GAN

Vanilla GAN, Goodfellow ve arkadaşlarının 2014'te yayımladığı "Generative Adversarial Nets" makalesindeki ilk GAN modelidir. G ve D çok katmanlı algılayıcılarla kurulur. Amaç fonksiyonu şudur (ekrandan, 01:30:00):

$$\min_G \max_D V(D,G) = \mathbb{E}_{x\sim p_{\text{data}}(x)}[\log D(x)] + \mathbb{E}_{z\sim p_z(z)}[\log(1 - D(G(z)))]$$

Burada $x$ gerçek veri, $z$ gürültü, $p_{\text{data}}$ ve $p_z$ bunların dağılımlarıdır. D bu ifadeyi büyütmek, G küçültmek ister. D, üretilmiş bir örnek için $D(G(z))$'yi sıfır olarak tahmin etmek ister; bu durumda $\log(1 - 0) = 0$ olur. Gerçek veri için de $D(x) = 1$ ve $\log 1 = 0$ olur, yani D açısından en iyi değer sıfırdır.

Ekrandaki dört panelli şekilde siyah noktalı eğri gerçek veri dağılımını, yeşil eğri üretilen dağılımı, mor kesikli eğri ayırıcının çıktısını gösterir; alttaki çizgiler $z$ uzayından $x$ uzayına eşlemeyi gösterir. Eğitim ilerledikçe yeşil eğri siyah eğrinin üzerine oturur ve son panelde ayırıcının çıktısı her yerde $1/2$ olur. Yani optimumda ayırıcı üretilen örnekleri gerçek ile yarı yarıya oranında karıştırır.

> **Ek bilgi (derste anlatılmadı):** Sabit bir G için en iyi ayırıcı $D^*(x) = \dfrac{p_{\text{data}}(x)}{p_{\text{data}}(x) + p_g(x)}$ biçimindedir. Üretilen dağılım $p_g$ gerçek dağılıma eşit olduğunda bu ifade $1/2$'ye iner; şekildeki son panel bu durumu gösterir.

Makalede MNIST, Toronto Face Dataset (TFD) ve CIFAR-10 üzerinde çalışılmıştır. Üretilen görüntüler herhangi bir kısıt olmadan rastgele üretildiği için çok başarılı değildir, ama ilk model olduğu düşünülürse bu normaldir. Yazarlar en iyi olduklarını iddia etmez; diğer üretici modellerle kıyaslanabilir bir model önerdiklerini ve geliştirilmeye açık olduğunu söylerler. Yine de bir karşılaştırmada diğer modelleri geçmiş, bir diğerinde ikinci sırada yer almıştır.

### 4.4 DCGAN

Deep Convolutional GAN'da G ve D'deki çok katmanlı algılayıcılar yerine evrişimli ağlar kullanılır. Temel yaklaşım aynıdır; yenilikler şunlardır:

- Havuzlama katmanları yerine adımlı evrişim ve kesirli adımlı evrişim kullanılır.
- Hem G'de hem D'de batch normalizasyon uygulanır.
- Derin mimarilerdeki tam bağlantılı gizli katmanlar kaldırılır.
- G'nin son katmanında tanh, diğer katmanlarında ReLU; D'nin tüm katmanlarında LeakyReLU kullanılır.

> Ders sonrası not: Sunumda "G'de adımlı evrişim, D'de kesirli adımlı evrişim" denildi. DCGAN makalesinde büyük olasılıkla tersidir: ayırıcıda adımlı (strided) evrişim, üreticide kesirli adımlı (fractional-strided, transpoze) evrişim kullanılır.

Batch normalizasyonun bir amacı GAN'ın önemli sorunlarından biri olan mode collapse'ı önlemektir. Mode collapse'ta üretici hep aynı (ya da çok benzer) örneği üretir. Inception Score gibi bir metrikle bakıldığında bu başarı gibi görünebilir, ama hep aynı veriyi üretmek aslında başarısızlıktır.

Karşılaştırma MNIST üzerinde yapılmıştır: üretilen görüntüler en yakın komşu sınıflandırıcısına verilip sonuçlara göre değerlendirilmiştir (ekrandan, 01:35:00).

| Model | Test hatası (50K örnek) | Test hatası (10M örnek) |
|---|---|---|
| AlignMNIST | - | %1,4 |
| InfiMNIST | - | %2,6 |
| Gerçek veri | %3,1 | - |
| GAN | %6,28 | %5,65 |
| DCGAN | %2,98 | %1,48 |

DCGAN'ın hatası GAN'ın yarısından azdır ve 50K örnekte gerçek veriyle eğitilen sınıflandırıcının hatasından bile düşüktür.

### 4.5 Conditional GAN

GAN yapısı gereği denetimsiz (unsupervised) sınıfa girer. Conditional GAN ise onu yarı denetimli hale getiren bir model olarak düşünülebilir. Üretimin istenen yönde olması için girişe bir koşul $y$ (sınıf etiketi ya da başka bir bilgi) verilir ve bu koşul hem G'ye hem D'ye verilir. Amaç fonksiyonundaki terimler $y$ koşuluna bağlı hale gelir: $D(x|y)$ ve $G(z|y)$. MNIST üzerinde başarının arttığı görülmüştür. Örneğin "sıfır" sınıfı koşulu verildiğinde sıfıra benzeyen rakamlar, "bir" koşulu verildiğinde bire benzeyen rakamlar üretilir.

### 4.6 AC-GAN

Auxiliary Classifier GAN, Conditional GAN'a benzer. Ancak Conditional GAN'da ayırıcının çıktısı yalnız görüntünün gerçek mi sahte mi olduğudur. Üretilen görüntünün hangi sınıfa ait olduğunu da bilmek istiyorsak ikinci bir kayıp fonksiyonuna ihtiyaç vardır. AC-GAN'da iki kayıp vardır: kaynağın (gerçek/sahte) doğru tahmin edilmesine ilişkin $L_S$ ve sınıfın doğru tahmin edilmesine ilişkin $L_C$. D, $L_S + L_C$'yi; G ise $L_C - L_S$'yi büyütmeye çalışır.

Makalede vurgulanan bir nokta çözünürlüktür: model daha yüksek çözünürlükte görüntü ürettikçe ayırt edilebilirlik artar. Karşılaştırma için 128'den 256'ya geçiş normal bir bilineer interpolasyonla yapılmış ve bu durumda bir iyileşme görülmemiştir. Bu yaklaşım, bir çalışmada hangi çözünürlükle yeterli başarı elde edilebileceğini belirlemeye yönelik bir ölçüt olarak sunulmuştur. Makalede ayrıca üretilen iki görüntü arasındaki farkı (çeşitliliği) ölçmek için bir metrik önerilmiş; sonraki çalışmalarda MS-SSIM olarak kullanılmıştır.

### 4.7 Residual koşullu GAN ile SAR gemi görüntüsü üretimi

Sunucu, kendilerini "geliştirilmiş residual koşullu GAN" olarak tanımlayan bir çalışmayı da bu başlık altında anlattı (ekrandan, 01:40:00). Problem, sentetik açıklıklı radar (SAR) gemi görüntüleri yüksek çözünürlükte olduğunda mevcut modellerle iyi sonuç alınamamasıydı. Mimari şöyledir:

- **Üretici:** Giriş, gizli vektör ve sınıf vektörüdür. ResNet'teki residual bloklardan (BN, LeakyReLU, Deconv, BN, LeakyReLU, Conv, toplama) oluşan bir dizi blok, sonunda bir çıktı katmanı ve üretilmiş gemi görüntüleri vardır.
- **Ayırıcı:** Giriş gerçek, üretilmiş ya da birleştirilmiş görüntüler ve sınıf vektörüdür. Evrişim, BN ve LeakyReLU katmanlarından sonra iki çıktı vardır: sigmoid ile gerçek/sahte olasılığı, softmax ile sınıf olasılığı (kargo, konteyner, tanker).
- **Görüntü birleştirme:** Gerçek ve sahte görüntülerin yanında bu ikisinin birleşimi de ayırıcıya verilir; birleşim yeni bir görüntü gibi algılanır ve başarıyı artırır.

Bir SAR gemi veri kümesinde üç sınıf üzerinden üretim yapılmış ve AC-GAN ile başka bir GAN türüyle karşılaştırılmıştır. MS-SSIM ile iki ölçüm yapılmıştır: üretilen görüntülerin gerçek veri kümesiyle benzerliği (yüksek olması iyidir) ve üretilen görüntülerin kendi aralarındaki benzerliği (düşük olması iyidir, çünkü çeşitliliği gösterir). Önerilen yöntem, özellikle görüntü birleştirme kullanıldığında en iyi sonucu vermiştir. Ayrıca üretilen görüntüler sınıflandırıcılara verilip tahminlerine bakılarak güvenilirlikleri değerlendirilmiş, yine önerilen modelin daha başarılı olduğu görülmüştür.

### 4.8 InfoGAN

Vanilla GAN'da gürültünün yapısı bilinmez ve kontrol edilemez. InfoGAN'da fikir şudur: gürültünün bir kısmını yorumlanabilir ve şekillendirilebilir bir koda dönüştürürsek başarımı artırabilir miyiz? Örneğin MNIST'te rakam üretirken yalnız gürültü değil, rakamın kendisi, dönme açısı ve kalınlığı gibi bilgiler de girdi olarak verilir.

Bunun için bilgi teorisindeki karşılıklı bilgi (mutual information) kullanılır (ekrandan, 01:45:00):

$$I(X;Y) = H(X) - H(X|Y) = H(Y) - H(Y|X)$$

Bu, bir değişkenin diğeri hakkında ne kadar bilgi taşıdığını ölçer. Amaç fonksiyonuna eklenince şu hal alır:

$$\min_G \max_D V_I(D,G) = V(D,G) - \lambda I(c; G(z,c))$$

Ancak $I(c;G(z,c))$'yi hesaplamak için sonsal dağılım $P(c|x)$'in bilinmesi gerekir ve bu zordur. Bu yüzden ona yaklaşan bir yardımcı dağılım $Q(c|x)$ tanımlanır ve bir alt sınır bulunur:

$$I(c;G(z,c)) = H(c) - H(c|G(z,c)) \ge \mathbb{E}_{x\sim G(z,c)}\big[\mathbb{E}_{c'\sim P(c|x)}[\log Q(c'|x)]\big] + H(c)$$

Aradaki fark KL ıraksamasıdır ($D_{\text{KL}}(P(\cdot|x)\,\|\,Q(\cdot|x)) \ge 0$). Bu alt sınırdan hesaplaması daha kolay bir $L_I$ terimi tanımlanır:

$$L_I(G,Q) = \mathbb{E}_{c\sim P(c),\,x\sim G(z,c)}[\log Q(c|x)] + H(c) \le I(c;G(z,c))$$

Sonuçta InfoGAN'ın amaç fonksiyonu şöyledir:

$$\min_{G,Q} \max_D V_{\text{InfoGAN}}(D,G,Q) = V(D,G) - \lambda L_I(G,Q)$$

Sunucu, buradaki $L_I$'nin L1 normu olmadığını, ayrı tanımlanmış bir değişken olduğunu belirtti.

MNIST sonuçlarında $c_1$ kategorik kodu rakam sınıfını kontrol eder: $c_1$ değiştikçe 0, 1, 2 gibi farklı rakamlar üretilir. Arada yanlışlar da olur (bir rakam yerine başka bir rakam üretilmesi gibi). $c_2$ dönmeyi, $c_3$ kalınlığı kontrol eder: $c_2$ değiştikçe rakamlar giderek döner, $c_3$ değiştikçe kalınlaşır. Aynı kodlar normal GAN formülüne uygulandığında anlamlı bir kontrol elde edilemez, çünkü formül bunu destekleyecek biçimde değildir. Böylece görüntü daha kontrollü üretilir.

Sunucu, InfoGAN yaklaşımını kullanan bir uygulama makalesinden de söz etti: akaryakıt istasyonlarında video gözetimiyle insanları izlemek maliyetli olduğu için denetimsiz bir yöntemle görüntü üretilip tahminleme yapılmıştır. Modelde $z$ yapısı bilinmeyen gürültü, $c$ kontrol edilebilir koddur.

### 4.9 Pix2Pix

Pix2Pix, koşullu GAN tabanlı bir görüntüden görüntüye çeviri (image-to-image translation) modelidir. Yeniliği, cGAN kaybına literatürdeki başka bir kaybı eklemesidir: üretici yalnız ayırıcıyı kandırmakla kalmasın, aynı zamanda gerçek (ground truth) görüntüye yakın bir görüntü üretsin diye L1 kaybı eklenir. L2 kullanan benzer çalışmalar da vardır, ancak L2 daha bulanık sonuç ürettiği için L1 tercih edilmiştir.

> **Ek bilgi (derste anlatılmadı):** Pix2Pix'in amaç fonksiyonu büyük olasılıkla $G^* = \arg\min_G \max_D \mathcal{L}_{cGAN}(G,D) + \lambda \mathcal{L}_{L1}(G)$ biçimindedir; burada $\mathcal{L}_{L1}(G) = \mathbb{E}_{x,y,z}[\lVert y - G(x,z)\rVert_1]$ üretilen görüntü ile gerçek hedef görüntü arasındaki piksel farkıdır.

Yazarlar amaçlarının genelleştirilmiş bir görüntüden görüntüye çeviri modeli olduğunu vurgular: kenar çiziminden görüntü üretme, etiket haritasından görüntü üretme gibi birçok iş aynı modelle yapılabilir. Bölütlenmiş (etiketli) görüntülerden fotoğraf üretme deneyinde farklı kayıplar karşılaştırılmıştır (ekrandan, 01:50:00):

| Kayıp | Piksel doğruluğu | Sınıf doğruluğu | Sınıf IoU |
|---|---|---|---|
| L1 | 0,42 | 0,15 | 0,11 |
| GAN | 0,22 | 0,05 | 0,01 |
| cGAN | 0,57 | 0,22 | 0,16 |
| L1+GAN | 0,64 | 0,20 | 0,15 |
| L1+cGAN | 0,66 | 0,23 | 0,17 |
| Gerçek görüntü | 0,80 | 0,26 | 0,21 |

L1+cGAN üç ölçütte de en iyi sonucu verir. Yalnız L1 bulanık, yalnız GAN ise anlamsız görüntüler üretir; ikisinin birleşimi hem keskin hem doğru sonuç sağlar.

### 4.10 CycleGAN

Pix2Pix'te görüntüden görüntüye çeviri eşli (paired) görüntüler gerektirir; yani her girdi görüntünün karşılığı olan hedef görüntü elde olmalıdır. Çeviri tamamen eşsiz (unpaired) verilerle yapılmak isteniyorsa CycleGAN öne çıkar. CycleGAN'da normal GAN kaybının yanında kendi döngü tutarlılığı kaybı (cycle-consistency loss) vardır: bir görüntü bir alandan diğerine çevrilip geri çevrildiğinde başlangıçtaki görüntüye dönmelidir. Karşılaştırmalarda Pix2Pix dışındaki yöntemlerden daha başarılı sonuçlar elde edilmiştir; Pix2Pix'in dezavantajı eşli görüntüye ihtiyaç duymasıdır.

CycleGAN ile yapılan başka bir çalışmada alan uyarlama (domain adaptation) sorunu ele alınmıştır: bir alandaki görüntüler başka bir alana aktarılıp orada bölütleme ve sınıflandırma doğru yapılmaya çalışılmıştır. U-Net ve evrişimli mimarilerle yapılan deneylerde skorların iyileştiği görülmüştür.

### 4.11 Progressive GAN

Progressive GAN modeli aşamalı olarak büyütür: önce $4\times4$ gibi düşük bir çözünürlük için katman eğitilir, sonra katman katman çözünürlük artırılır. Katmanlar arası geçişler yumuşak yapılır ve burada residual mantığı kullanılır. Sonuçta çok başarılı, yüksek çözünürlüklü görüntüler elde edilmiştir.

Sunumun sonunda en basit Vanilla GAN'ın çok katmanlı algılayıcılarla kurulmuş bir kod örneği kısaca gösterildi: üretici ve ayırıcı ayrı ayrı tanımlanıp GAN modelinde birleştiriliyordu. Kodun içeriği karelerde görülmediği için buraya aktarılmadı.

## Örnek Sorular

**Soru 1** (derste sözlü, 01:03:21): Görüntü manipülasyonu tespiti için listelenen veri kümeleri arasında deepfake veri kümesi var mı?

> **Cevap (derste):** Sunucu, deepfake tespitine yönelik çok az çalışma bulduğunu ve bulduğu çalışmanın teorik düzeyde kaldığını söyledi. Hoca, deepfake tespiti için makale olmasa bile bildiriler bulunabileceğini, Kaggle'ın bu konuda bir yarışma düzenlediğini ve yarışmada dereceye giren yöntemlerin alanda yaygın kullanılan yöntemler olduğunu belirtti; ilgili bir veri kümesine bakılmasını önerdi.

**Soru 2** (derste sözlü, 01:11:43): Tıbbi görüntülerde neden manipülasyon tespitine ihtiyaç var? Bu görüntülerde manipülatif bir amaç ne olabilir?

> **Cevap (derste):** Görüntüler yakın zamana kadar CD ya da film olarak hastanın elinde taşınıyordu. Bir kişi başka bir kurumdan rapor almak için kendi getirdiği görüntüye bir kırık ya da çıkık gibi bulgu ekleyebilir; amaç örneğin engelli raporuyla gelen haklardan yararlanmak olabilir. Adli vakalarda da darp sonrası çekilen bir röntgenin manipüle edilmesi karşı tarafı suçlu ya da suçsuz gösterebilir.

**Soru 3** (derste sözlü, 01:13:50): Görüntüler artık merkezi sağlık sistemlerinde tutulduğuna göre bu tür bir manipülasyon çok zor değil mi?

> **Cevap (derste):** Görüntüler yine aracı firmaların sistemleri üzerinden aktarılmaktadır; bu katmanlarda müdahale olasılığı vardır. Sistem güvenli kabul edilse de ne kadar güvenli olduğu ayrı bir sorudur. Hoca bunu "insanın olduğu her yerde hile olabilir" diye özetledi.

**Soru 4** (derste sözlü, 01:52:57): Deniz üstü hedeflerin sentetik kızılötesi görüntülerini üretmenin amacı nedir, neye hizmet edecek?

> **Cevap (derste):** Normal RGB görüntülerle istenen başarı (örneğin konumlandırma/lokalizasyon) sağlanamazken kızılötesi görüntülerle daha başarılı sonuç alınmaktadır; ancak kızılötesi görüntü elde etmek masraflıdır. Bu yüzden elde bulunan RGB görüntülerden sentetik kızılötesi görüntü üretilmesi hedeflenir. Eşli kızılötesi görüntüler de bulunursa Pix2Pix gibi bir yaklaşım daha kolay ve başarılı olur; bulunamazsa CycleGAN gibi eşsiz veriyle çalışan bir yaklaşım kullanılır.

**Soru 5** (derste sözlü, 01:54:08): SAR gemi görüntüsü çalışmasının slaytındaki iki tablonun farkı nedir? Neyi gösterdikleri yazılmamış.

> **Cevap (derste):** İki tablo da MS-SSIM ile ölçülmüştür. Biri üretilen görüntülerin gerçek veriyle benzerliğini (yüksek olması iyi), diğeri üretilen görüntülerin kendi aralarındaki benzerliğini (düşük olması iyi, çeşitliliği gösterir) verir.

## Dersin Toparlaması

Bu son seminer oturumunda üç farklı alanda literatür taraması dinlendi. İlk sunum öneri sistemlerinin içerik tabanlı, işbirlikçi ve hibrit türlerini, kosinüs ve Pearson benzerliğini, soğuk başlangıç ve seyreklik başta olmak üzere sekiz temel sorunu ve bu sorunlara yönelik çalışmaları ele aldı. İkinci sunum görüntü manipülasyonunun tarihçesini, ekleme, kopyala-taşı, rötuş, dönüştürme ve renklendirme türlerini, aktif/pasif ve klasik/güncel tespit yöntemlerini, CASIA, CoMoFoD ve COVERAGE veri kümelerini ve tıbbi görüntülerde manipülasyon sorununu anlattı. Üçüncü sunum GAN'ın üretici-ayırıcı yapısını ve minimax amacını, ardından DCGAN, Conditional GAN, AC-GAN, InfoGAN, Pix2Pix, CycleGAN ve Progressive GAN'ın her birinin getirdiği yeniliği sonuçlarıyla birlikte inceledi.

Hocanın yorumları üç noktada toplandı: doktora düzeyinde bir çalışma teorik bir katkı da içermelidir; makale az olduğunda bildiriler ve yarışmalar güncel yöntemlerin kaynağıdır; önerilen her yöntemin hangi gerçek ihtiyaca hizmet ettiği ve sunumdaki her tablonun neyi ölçtüğü açıkça söylenebilmelidir. Hoca bu oturumla birlikte iki haftada toplam beş doktora tezi giriş ve literatür çalışmasının dinlendiğini belirterek dönemi kapattı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
