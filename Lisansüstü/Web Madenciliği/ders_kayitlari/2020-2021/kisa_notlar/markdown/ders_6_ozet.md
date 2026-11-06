# Ders 6 Çalışma Özeti

## Genel Konular

- Ders 10 Kasım 2020 tarihlidir. Hoca dersi Atatürk'ü ölüm yıl dönümünde anarak başlatmıştır.
- Hoca dersin sayfasını (Google Sites) paylaşmıştır. Tüm ders notları ve örnek proje fikirleri bu sayfadadır.
- O ana kadar işlenen bölümler: Bölüm 1 (genel bakış), Bölüm 2 (birliktelik kuralı madenciliği, association rule mining), Bölüm 3 (gözetimli öğrenme), Bölüm 4 (gözetimsiz öğrenme).
- Bu derste kitabın 6. bölümü başlamıştır: bilgi erişimi (information retrieval) ve web araması (web search). Bu konu web içerik madenciliğinin (web content mining) parçasıdır.
- Ana konular:
  - Web içerik madenciliğinin kapsamı
  - Bilgi erişimi ile veri tabanı sorgusu farkı
  - Web arama motorlarının çözmesi gereken problemler
  - Bilgi erişimi modelinin bileşenleri
  - Sorgu tipleri
  - Boolean model ve vektör uzayı modeli (vector space model)
  - TF-IDF ağırlıklandırması
  - Kosinüs benzerliği ve Okapi benzerliği
  - İlgililik geri bildirimi (relevance feedback)
- Dersin ikinci yarısında öğrencilerin dönem projesi önerileri tek tek konuşulmuştur.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bilgi erişiminde dokümanlar da sorgular da yapısızdır (unstructured). Veri tabanında ise hem saklama hem sorgu yapılıdır (SQL).
- Web araması, bilgi erişiminin büyük ölçekli ve dağıtık web dokümanlarına özel bir versiyonudur.
- Bugünkü arama motorlarının başarısı sayfalar arasındaki köprü bağlantıları (hyperlink) kullanmalarından gelir. En bilinen algoritma PageRank'tir.
- Bir bilgi erişimi modelinin dört bileşeni vardır: sorgu dili, sorgunun iç gösterimi, dokümanın iç gösterimi, sıralama fonksiyonu.
- Vektör uzayı modeli bugün en yaygın kullanılan modeldir.
- TF bir kelimenin dokümandaki önemini, IDF ise doküman setindeki ayırt ediciliğini gösterir.
- Kosinüs benzerliği için iki vektörün iç çarpımını (dot product) ve uzunluklarını hesaplamayı bilmek gerekir. "Bununla karşılaşabilirsiniz." demiştir.
- Proje önerileri çok net olmalıdır. Hoca iki ay sonraki demoda öneriye bakarak "bunu söylemiştin, yaptın mı" diye soracaktır. Öğrenci öneriye bakarak alacağı notu tahmin edebilmelidir.
- Güncellenmiş proje önerileri bu hafta Cuma gününe (13 Kasım 2020) kadar e-posta ile gönderilmelidir.

## Kısa Tekrar Notları

- Web içerik madenciliği: crawl edilen dokümanların merkezde toplanmasından aramanın yapılmasına kadar olan tüm işler. Adımlar: toplama, ayrıştırma (parse), kelime çıkarma, indeks tablosu oluşturma, sorguyu dokümanlarla eşleştirme, sıralama.
- Veri, bilgi, bilgi birikimi ve bilgelik:
  - Arama sonuç listesi bilgidir (information).
  - Linkleri okuyunca kafada oluşan resim bilgi birikimidir (knowledge).
  - Aynı sorguyla 100 kişinin kafasında aynı resim oluşuyorsa bu bilgeliktir (wisdom).
- Web aramasının özel problemleri:
  - Köprü bağlantıları (kalite artırmak için kullanılabilir)
  - Verinin dağıtık olması ve crawl zorluğu
  - Çok büyük hacim ve saklama
  - Verinin güncel tutulması
  - Çok sayıda eş zamanlı kullanıcı
  - Web spam
- Sorgu tipleri: anahtar kelime, Boolean, ifade (phrase), yakınlık (proximity), tam doküman, doğal dil soru sorgusu.
- Boolean model: kelime varsa 1, yoksa 0. Yalnız sorguyu tam doğru yapan (exact match) dokümanlar döner. Sıralama yoktur.
- Vektör uzayı modeli: ağırlık olarak TF-IDF kullanılır. Dokümanlar benzerliğe göre sıralanır.
- $tf_{ij} = f_{ij} / \max\{f_{1j}, f_{2j}, \ldots\}$, $idf_i = \log(N / df_i)$, $w_{ij} = tf_{ij} \times idf_i$
- Kosinüs benzerliği: iç çarpım bölü vektör uzunluklarının çarpımı.
- Relevance feedback: kullanıcının ilgili işaretlediği dokümanlardaki sık kelimelerle sorgu genişletilir (query expansion).

## Detaylı Açıklamalar

### Web içerik madenciliğinin kapsamı

- Web, uygulama sunucularında (IIS, Tomcat, HTTP sunucuları) duran HTML dokümanlarından oluşur.
- Dokümanlar birbirine köprü bağlantılarla link verir. Bu linkler sanal bir doküman ağı oluşturur.
- İnsanlar bir otoriteye bağlı olmadan birbirine link verir. Bir sayfaya link vermek o sayfaya "oy vermek", ona önem atfetmek gibidir.
- Fiziksel ağ ise bunun altındadır: fiber optik kablolar, Wi-Fi, Bluetooth gibi kablosuz aktarım.
- Dokümanlar farklı sunucularda olduğu için:
  - Önce merkezi bir ortamda toplanmalıdır (crawling).
  - Sonra aranabilir şekilde indekslenmelidir (indeks tablosu).
  - Kullanıcının kelimeleri indekste aranır.
  - Eşleşen sonuçlar bir sıralama yöntemine göre gösterilir.
- Bu sürecin içinde metin madenciliği (text mining) vardır: dokümanlardan temsil gücü yüksek kelimeler çıkarılıp indeks oluşturulur. Bunun yöntemleri bilgi erişimi (information retrieval) alanında incelenir.
- Hoca, bu bölümün ve crawling bölümünün (8. bölüm) arama motorlarının arka planda nasıl çalıştığına odaklandığını söylemiştir.

### Bilgi erişimi ve veri tabanı farkı

- Veri tabanı:
  - Veriler tablolarda tutulur. Tabloların kolonları, birincil ve yabancı anahtarları vardır.
  - Sorgular SQL tabanlıdır.
  - Saklama da sorgu da yapılıdır.
- Bilgi erişimi:
  - Doküman metinlerinin bir yapısı yoktur.
  - Sorgunun da yapısı yoktur: kelime, kelime grubu, tırnak içinde ifade, bir dokümanın tamamı ya da bir resim ile arama yapılabilir.
- Araçlar:
  - Genel arama motorları: Bing, Google, Yahoo, Yandex.
  - Kurum içi (intranet) arama araçları: Nutch gibi açık kaynak uygulamalar ya da Google Site gibi araçlar.
- Arama motorları sonuçları genellikle onarlı listeler halinde gösterir.

### Web arama motorlarının problemleri

- Köprü bağlantıları: 100 PDF dokümanlık bir koleksiyonda link olmayabilir. HTML dokümanlarında ise linkler vardır ve arama kalitesini artırmak için kullanılabilir.
- Dağıtıklık: her sayfa için ayrı bir sunucuya HTTP isteği gönderilmelidir. Her sayfa başka bir alan adındaki sayfaya link verebilir. Bu yüzden crawling kendi başına zor bir iştir.
- Hacim: çok sayıda HTML sayfası merkezde toplanıp sorgulanabilir şekilde saklanmalıdır.
- Güncellik: bir sayfa bir kez crawl edilip bırakılmaz. Crawler sürekli geri dönüp veriyi güncellemelidir.
- Eş zamanlı kullanıcı: çok sayıda kullanıcıya aynı anda arama hizmeti verilmelidir. Kullanıcı yalnız indekslenmiş veri üzerinde arama yapar. İndeksi hazırlamak için arka planda çok iş yapılır.
- Web spam:
  - Sayfaya kullanıcıya görünmeyen (render edilmeyen) çok sayıda anahtar kelime eklenebilir. Meta etiketlerine (meta tag) de eklenebilir. Böylece sayfa ilgisiz aramalarda çıkar.
  - Birbirine link veren sanal bir sayfa ağı kurulabilir. Böylece bir sayfa olduğundan önemli görünür.
  - Arama motoru optimizasyonu (Search Engine Optimization, SEO) firmaları bunun yasal bir versiyonunu yapar: popüler sayfalarından müşterinin sayfasına link verdirir, sayfa yapısını ve anahtar kelimeleri optimize eder.

### Bilgi erişimi modelinin bileşenleri

- Sorgu dili (query language): kullanıcının yazdığı sorgu, motorun kendi formatına çevrilir.
- Sorgunun iç gösterimi (internal representation of queries): sorgu vektöre çevrilir.
- Dokümanın iç gösterimi: dokümanlar ön işlemeden geçirilip indekslenir ve vektöre çevrilir.
- Sıralama fonksiyonu (ranking function): sorgu ile her doküman arasında benzerlik puanı hesaplanır. Dokümanlar bu puana göre sıralanır.
- Mimari akış:

```
Doküman koleksiyonu --> İndeksleyici --> İndeks
Kullanıcı --> Kullanıcı arayüzü --> Sorgu işlemleri --> Çalıştırılabilir sorgu
Çalıştırılabilir sorgu + İndeks --> Erişim sistemi (sıralama fonksiyonu) --> Sıralı dokümanlar --> Kullanıcı
Kullanıcı geri bildirimi --> Sorgu işlemleri
```

- Çalıştırılabilir sorgu (executable query) örneği: kullanıcı "web data mining" yazarsa motor kelimelerin arasına AND koyabilir (yalnız üçünü de içeren dokümanlar) ya da OR koyabilir (en az birini içeren dokümanlar).
- Çalıştırılabilir sorgu çalıştırılmadan önce kullanıcıya gösterilip geri bildirim alınabilir. Kullanıcı sonuçlar üzerinde ikinci bir arama da yapabilir.
- Hoca ACM ve IEEE gibi dijital kütüphanelerin gelişmiş arama ekranlarını göstermiştir: alan seçimi, tam eşleşme (exact match), birden fazla alan, terimler arasında AND ya da OR gibi mantıksal işlemler. Bunların hepsi arayüzün kullanıcıya sunduğu sorgu dilinin parçasıdır.

### Sorgu tipleri

- Anahtar kelime sorguları (keyword queries): genel arama motorlarının temel özelliği.
- Boolean sorgular: AND, OR, NOT ile parçalar birleştirilir. Örnek: "web AND data NOT mining" sorgusu, içinde web ve data olan ama mining olmayan dokümanları getirir. Yalnız sorguyu doğru yapan dokümanlar döner.
- İfade sorguları (phrase queries): kelimeler tırnak içinde verilir. Dokümanda aynı sırada ve yan yana geçmelidir.
- Yakınlık sorguları (proximity queries): kelimeler dokümanda birbirine yakın olmalıdır ama yan yana olmak zorunda değildir. Kelimeleri aynı paragrafta geçen doküman, kelimeleri dokümana dağılmış olandan daha üstte gösterilir.
- Tam doküman sorguları (full document queries): bir doküman ya da resim verilip benzerleri istenir. Örnek: Google görsel arama.
- Doğal dil soru sorguları (natural language questions): örnek "dolar şu anda kaç TL". Motor normal sonuçları listeler, ayrıca soruya doğrudan cevabı en üstte gösterir.

### Boolean bilgi erişimi modeli

- Dokümanda geçen her kelime ayırt edici değildir. Bağlaçlar, artikeller ve anlamı olmayan, çok sık tekrar eden kelimeler kullanılmaz.
- Doküman setindeki tüm ayırt edici kelimelerin kümesine kelime dağarcığı (vocabulary) denir. Bu bir dilin tüm kelimeleri değil, eldeki doküman setinin kelimeleridir.
- Vocabulary'de $V$ kelime varsa her doküman $V$ elemanlı bir vektörle gösterilir.

$$d_j = (w_{1j}, w_{2j}, \ldots, w_{|V|j})$$

- Boolean modelde $w_{ij}$, kelime dokümanda varsa 1, yoksa 0'dır. Başka ağırlık kullanılmaz.
- Sorgu Boolean operatörlerle verilir. Örnek: "data AND mining AND NOT text".
- Yalnız sorguyu doğru (true) yapan dokümanlar, yani tam eşleşmeler döner.

### Vektör uzayı modeli ve TF-IDF

- Dokümanlar yine kelime uzayında vektördür. Ama ağırlık olarak 1 ya da 0 yerine TF-IDF kullanılır.
- Terim frekansı (term frequency, TF): $i$ kelimesinin $j$ dokümanında kaç kez geçtiği, o dokümanda en sık geçen kelimenin frekansına bölünerek normalize edilir.

$$tf_{ij} = \frac{f_{ij}}{\max\{f_{1j}, f_{2j}, \ldots, f_{|V|j}\}}$$

- Ters doküman frekansı (inverse document frequency, IDF): $N$ toplam doküman sayısı, $df_i$ kelimenin geçtiği doküman sayısıdır.

$$idf_i = \log \frac{N}{df_i}$$

  - Bir kelime 100 dokümanın hepsinde geçiyorsa ayırt edici değildir. Aranınca 100 dokümanın hepsi gelir. IDF düşüktür.
  - Kelime az dokümanda geçiyorsa ayırt edicidir. IDF yüksektir.
- TF-IDF ağırlığı:

$$w_{ij} = tf_{ij} \times idf_i$$

- Bir kelime dokümanda çok tekrar ediyorsa ve doküman setinde nadir geçiyorsa ağırlığı büyür.
- Bazen vektöre yalnız TF de konabilir.

### Sıralama fonksiyonları

- Kosinüs benzerliği:

$$cosine(d_j, q) = \frac{\langle d_j \cdot q \rangle}{\|d_j\| \times \|q\|} = \frac{\sum_{i=1}^{|V|} w_{ij} \times w_{iq}}{\sqrt{\sum_{i=1}^{|V|} w_{ij}^2} \times \sqrt{\sum_{i=1}^{|V|} w_{iq}^2}}$$

- Oyuncak örnek:
  - 3 kelimelik bir uzay ve 9 dokümanlık bir set vardır. Dokümanlar 1 ve 0'lardan oluşan üçlü vektörlerdir.
  - Sorgu "hardware AND software"tır.
  - Boolean AND ile yalnız iki kelimeyi de içeren dokümanlar (A4 ve A7) döner.
  - Boolean OR ile iki kelimenin de 0 olduğu A3 dışındaki tüm dokümanlar döner.
  - Kosinüs benzerliği kullanılırsa sorgu vektörünün tamamı gerekir. Kullanıcı üçüncü kelime hakkında bir şey söylemediyse o eleman 0 kabul edilir. Her doküman için farklı bir benzerlik değeri çıkar. Dokümanlar büyükten küçüğe sıralanır.
- Okapi benzerliği: literatürde önerilmiş başka bir ölçüdür. Hesabı daha karmaşıktır. Deneysel çalışmalar başarılı sonuçlar verdiğini göstermiştir.

### İlgililik geri bildirimi (relevance feedback)

- Kullanıcı sonuçlar üzerinden motora geri bildirim verebilir.
- Kullanıcının ilgili bulduğu dokümanlardan sık geçen yeni kelimeler çıkarılır. Aynı sorgu tekrar girildiğinde sorgu bu kelimelerle genişletilir (query expansion).
- Bir öğrenci itiraz etmiştir: kullanıcı ilk linke tıklayıp aradığını bulamazsa o link ilgili sayılmamalıdır. Hoca haklı olduğunu söyleyip düzeltmiştir:
  - Tıklanan link ilgili demek değildir.
  - Doğru tasarım: her sonucun yanına bir onay kutusu (checkbox) konur. Kullanıcı ilgili sonuçları işaretleyip tekrar aramaya basar. İşaretlenen sayfalardaki ek kelimeler sorguya eklenir. İkinci turun sonuçları daha kaliteli olur.
  - Genel arama motorlarında bu açık (explicit) geri bildirim yoktur. Bunlar yalnız tıklamalardan örtük (implicit) çıkarım yapmaya çalışır.
- Sonraki konu: indekslemeden önce dokümanlara uygulanan metin ön işleme (text preprocessing) adımları.

### Dönem projesi önerileri

- Hoca, kalan öğrencilerin önerilerini bu hafta e-posta ile göndermesini istemiştir.
- Tüm projeler için genel kurallar:
  - Proje, Web Data Mining kitabındaki bir algoritmayı ya da bölümü kullanmalıdır.
  - Hazır, indirilebilir ve istatistikleri bilinen bir veri seti kullanılmalıdır. Kısa süreli bir projede veri toplamak risklidir: Twitter sayfaları bloklayabilir, beklenmedik sorunlar çıkabilir. Yalnız crawler projeleri veriyi anlık toplar.
  - Raporda veri setinin linki ve onu açıklayan bir tablo olmalıdır: veri sayısı, etiket varsa hedef etiket, öznitelik (feature) sayısı, tweet sayısı, toplanma zamanı.
  - Sınıflandırma yapan projeler en az 3 sınıflandırıcı kullanmalıdır. Biri TensorFlow üzerinde Keras ile LSTM olabilir. Diğerleri lojistik regresyon (logistic regression), rastgele orman (random forest) gibi standart yöntemler olabilir. Kullanılacak kütüphaneler (örnek: Spark ML, TensorFlow, Keras) isimleriyle yazılmalıdır.
  - Veri %70-80 eğitim, %20-30 test olarak ayrılmalıdır. Başarı doğruluk (accuracy), kesinlik (precision), duyarlılık (recall) ve F1 ile raporlanmalıdır.
  - Crawler projeleri en az 3 farklı web kaynağından veri toplayıp birleştirmelidir. Bu bir hibrit arama motoru olur.
  - Mutlaka bir kullanıcı arayüzü (GUI) ve demo olmalıdır. Yalnız slaytta confusion matrix ve doğruluk göstermek yetmez. Kod yazılmalıdır.
  - Proje iki ayda bitirilebilecek boyutta olmalıdır. Karmaşıklaştırılmamalıdır.
- 1. öneri: üniversite araştırmacılarının yayınlarında arama.
  - Fikir: bir üniversitenin araştırmacılarının yayınlarında konu bazlı arama yapmak. Google Scholar buna doğrudan izin vermemektedir.
  - Hocanın çerçevesi: hibrit bir akademik yayın arama motoru.
    - Bir açılır menüden üniversite seçilir, bir metin kutusuna anahtar kelimeler girilir.
    - Önce bir kaynaktan o üniversitede yayını olan araştırmacılar bulunur.
    - Sorgu en az 3 dijital kütüphaneye anlık gönderilir: IEEE Xplore, ACM, DBLP, Scopus gibi. Kurum filtresi (affiliation) kullanılır.
    - Gelen sonuçlar birleştirilir. Tekrarlar (duplication) kaldırılır. Aynı yayın tek satırda gösterilir, yanına bulunduğu kaynakların ikonları konur.
    - Üniversite değiştirilebilir (konfigüre edilebilir) olmalıdır.
    - Fiyat karşılaştırma sitelerine benzer bir mantıktır.
  - Öğrenci Google Scholar'da kurum filtresi olmadığını ve çok sayıda istekte Google'ın blokladığını söylemiştir. Hoca bu durumda IEEE Xplore, ACM, DBLP ve Scopus'a geçilmesini söylemiştir.
- 2. öneri: Twitter'da siber güvenlik tehditlerinin tespiti.
  - Fikir: açık kaynak istihbaratı (OSINT) kapsamında tweet'lerden yeni zafiyetleri ve saldırı planlarını yakalamak. NVD (National Vulnerability Database) kaynaklı ve CVSS skorlu tweet veri setleri vardır.
  - Planlanan akış: crawler, mesaj kuyruğu (message queue), sınıflandırıcı, Elasticsearch indeksi, SIEM entegrasyonu.
  - Hocanın istekleri:
    - Veri setinin linki ve istatistikleri (toplam tweet, güvenlikle ilgili ve normal tweet sayıları).
    - Embedding yöntemi yazılmalıdır. Örnek: tweet'teki her kelime Word2Vec ile vektöre çevrilir, vektörlerin ortalaması tweet'i temsil eder.
    - En az 3 sınıflandırıcı (biri LSTM).
    - Arayüzde gelen tweet ve yanında A, B, C modellerinin tahmini gösterilmelidir.
- 3. öneri: e-ticaret ürün yorumlarında fikir madenciliği.
  - Fikir: teknolojik ürün yorumlarını olumlu ya da olumsuz sınıflandırmak. 1-2 yıldızlı yorumlar olumsuz, 4-5 yıldızlı yorumlar olumlu, 3 yıldızlılar alınmayacaktır.
  - Hocanın çerçevesi:
    - Kitabın 11. bölümündeki (opinion mining) özellik tabanlı fikir özeti (feature-based summary of opinions) algoritması çalışılmalıdır.
    - Örnek: dijital kamera yorumlarında resim, batarya, zoom, boyut, ağırlık özellikleri için olumlu ve olumsuz yüzdeler raporlanır. Örneğin 100 yorumun 90'ı resim özelliği için olumludur.
    - Kargo, fiyat gibi ürün özelliği içermeyen yorumlar algoritma tarafından zaten dikkate alınmaz.
    - Veri crawl edilmemeli, hazır yorum veri seti kullanılmalıdır.
    - Arayüz: açılır menüden ürün seçilir, butona basılınca özellik tabanlı sonuçlar grafikle gösterilir.
  - Hoca bu projenin daha önce başka öğrenci gruplarınca başarıyla yapıldığını, zor bir proje istemediğini söylemiştir.
- 4. öneri: kitap siteleri için hibrit arama motoru.
  - Fikir: deneme amaçlı yayınlanmış bir kitap sitesinden (Books to Scrape) başlayıp 3 farklı kitap sitesinden kitap ismi ya da yazar ismiyle arama.
  - Hocanın istekleri:
    - Hangi 3 sitenin kullanılacağı yazılmalıdır. RESTful servisi olan siteler tercih edilmelidir. Yoksa HTML sayfaları ayrıştırılmalıdır.
    - Aynı kitap tek satırda gösterilmelidir. Yanında üç sitenin ikonları ve her sitedeki fiyatı olmalıdır.
- 5. öneri: müzik ile ilgili yorumlarda duygu analizi.
  - Fikir: müzikle ilgili tweet'lerde duygu analizi (TextBlob gibi araçlarla). Twitter'ın ücretsiz API'si yalnız son 7 güne izin vermektedir.
  - Hocanın görüşü:
    - Tweet'leri olumlu ya da olumsuz diye etiketlemek bu ders için anlamlı bir proje değildir. Tweet'lerin karakter sayısı sınırlıdır.
    - Fikir madenciliği yapılacaksa özellik tabanlı fikir madenciliği daha anlamlıdır.
    - Sınıflandırma yapılacaksa 2. öneri gibi en az 3 sınıflandırıcı (biri LSTM) istenecektir.
    - Hazır veri seti bulunmalıdır.
- 6. öneri: YouTube videolarının trend olup olmayacağının tahmini.
  - Hocanın çerçevesi:
    - Bu bir ikili sınıflandırmadır: trend olur ya da olmaz. Kaç kişiye ulaşacağı tahmin edilmeyecektir.
    - Hazır, trend etiketi olan bir veri seti kullanılmalıdır.
    - Demoda önce veri analizi süreci anlatılmalıdır: aykırı değer ayıklama, ki-kare testi ile bağımlı özniteliklerin çıkarılması, normalizasyon, 3 algoritma, %80 eğitim ve %20 test, doğruluk, F-skor ve confusion matrix.
    - Sonra gerçek zamanlı etiketleme gösterilmelidir. Örnek: geçen hafta 5 yeni video için tahmin yapılır, bir hafta sonra tahminin tutup tutmadığına bakılır.
- Bir öğrenci henüz öneri hazırlamamıştır. Bu hafta e-posta ile gönderecektir. Bir öğrenci de e-posta adresini bulamadığını söylemiştir.
- Önerilerin hepsi revizyon almıştır. Hoca revizyonlar geldikten sonra projeleri kabul edecektir. İstenen tarzda gelmeyen önerilere son bir düzeltme şansı verilecektir.
- Teslim: Cuma, 13 Kasım 2020. Gelecek hafta kaldığı yerden devam edilecektir.

### Ders sonrası notlar

- Altyazıda "Natch" diye geçen açık kaynak arama motoru Apache Nutch'tır.
- "Turn frequency" term frequency, "renk fonksiyonu" ranking function, "kosai similarity" cosine similarity demektir.
- "ISS server" Microsoft IIS sunucusudur.
- "DLDB / DBL LP / BBLP" DBLP'dir. "Bing Scholar" diye geçen kaynak muhtemelen Microsoft Academic'tir.
- "Natural Vulnerability Database" NIST'in National Vulnerability Database'idir. "CSS skoru" CVSS skorudur. "CM" SIEM'dir.
- Hoca TF tanımında ilk anda "döküman setindeki maksimum" demiş, sonra düzeltmiştir. Doğrusu: payda, aynı doküman içinde en sık geçen kelimenin frekansıdır.
- Hoca ilgililik geri bildiriminde önce tıklanan linkleri ilgili saymıştır. Öğrencinin itirazı üzerine düzeltmiştir. Doğrusu yukarıda anlatıldığı gibidir.
- Hoca opinion mining bölümünü bir yerde "chapter 11" diye anmıştır. Kitabın baskısına göre bölüm numarası değişebilir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
