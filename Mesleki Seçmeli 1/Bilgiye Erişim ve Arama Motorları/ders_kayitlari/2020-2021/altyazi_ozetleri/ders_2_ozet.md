# Ders 2 Çalışma Özeti

## Genel Konular

- Dersin tarihi 15 Ekim 2020 Perşembe. Ders Zoom üzerinden, saat 09:00'da başladı.
  - Asıl anlatım yaklaşık 00:12'de başlar. 01:09 ile 01:19 arasında ara var.
  - Ders büyük ölçüde İngilizce anlatılır. Hoca sınıfın durumuna göre zaman zaman Türkçeye geçer.
- Dersin tanıtımı (syllabus)
  - Ekrandaki izlencede dersin adı "BLM3581 Information Retrieval and Web Search Engines", hoca "Dr. Mehmet Aktaş" olarak geçer.
  - Ders kitabı: Bing Liu, *Web Data Mining: Exploring Hyperlinks, Contents, and Usage Data* (Springer, 2007).
  - Ders Perşembe günleri, iki oturum hâlinde, araya 10 dakikalık mola verilerek işlenir.
  - Değerlendirme: vize, kod yazılan bir dönem projesi ve final.
  - Derse çevrim içi katılım beklenir. Hoca derslerin en az %70'ine katılım ister.
- Web verisinin (web data) özellikleri
  - Web verisi yapısız (unstructured), yarı yapılı (semi-structured), hiper metin (hypertextual) ve dağıtık (distributed) bir veridir.
  - İlişkisel veritabanı verisinden farklıdır.
- Derste öğrenilecek işler
  - Veriyi taramak (crawling), indekslemek (indexing), sıralamak (ranking).
  - Metin ve bağlantı analiziyle (text and link analysis) filtreleme.
  - Uygulama alanları: arama, sınıflandırma (classification), izleme (tracking, monitoring), web zekâsı (web intelligence).
- Web'in kısa tarihi
  - Web 1990'da CERN'de Tim Berners-Lee tarafından başlatıldı: ilk HTTP sunucusu ve basit bir işaretleme dili.
  - 1993'te çıkan Mosaic tarayıcısı web'i yaygınlaştırdı.
- Web'in yapısı: papyon (bow-tie) modeli, 2000 yılında yayımlanmış bir çalışmadan.
- Web verisine farklı bakış açıları: karmaşıklık, hacim, gizlilik, düşmanca içerik (adversarial).
- Statik web, dinamik web, gizli web (hidden web) ve anlamsal web (semantic web).
- Kalabalıkların bilgeliği (wisdom of crowds) ve örnek uygulamalar.
- Veri, enformasyon, bilgi ve bilgelik (data, information, knowledge, wisdom) ayrımı.
- Bilgi erişimi (information retrieval, IR) ile veritabanı erişimi arasındaki fark.
- IR modelleri, kalite ölçütleri (recall, precision), çeşitlilik (diversity).
- Kelime torbası (bag of words) gösterimi.
- Temel terimler: internet ve web, link ve hyperlink, URL, anchor text.
- Arama motorunun genel mimarisi: crawler, ters indeks (inverted index), PageRank.
- Sosyal ağlar ve dersin ileriki konuları.
- Dönem projesi duyurusu.

## Hocanın Özellikle Vurguladığı Kısımlar

- **Dönem projesi:**
  - Grup en fazla 2 kişi olabilir; tek kişi de yapılabilir. 3 kişilik grup kesinlikle olmaz.
  - Proje kod yazmayı gerektirir ve bir demosu olur.
  - Proje notunun etkisi en az vize kadardır.
  - Ödev yok. Değerlendirme yalnız vize, proje ve finalden oluşur.
  - Konuyu öğrenci belirler, hoca onaylar. Örnek konular: web crawling uygulaması, web usage mining, link analizi, hibrit arama uygulaması.
  - 4. ya da 5. haftada bir sayfalık proje öneri formu istenecek.
- **Katılım:** Kayıtlar sonradan izlenebilse de derse çevrim içi katılım isteniyor. Bu aynı zamanda bölümün de şartı.
- **Arama nasıl yapılır:** Arama, web sayfalarının kendisinde değil, önceden taranıp oluşturulmuş ters indeks tablosunda yapılır.
- **Web arama motorunun kalitesi:** Ağırlıklı olarak precision ile ölçülür. Tüm ilgili belgelerin sayısı bilinmediği için web'de recall hesaplanamaz.
- **Çeşitlilik:** İyi bir arama motoru sonuçları tek bir siteden değil, farklı sitelerden getirmelidir.
- **Bu dersi neden almalı:**
  - İşletmelerdeki verinin büyük kısmı artık yapısızdır.
  - Arama motoru optimizasyonu ve sosyal ağ optimizasyonu gibi iş alanlarında bu konular kullanılır.

## Kısa Tekrar Notları

- Web verisi: yapısız, yarı yapılı, hiper metin, dağıtık.
- Bow-tie yapısı:
  - Çekirdek (core / SCC): sayfalar birbirine karşılıklı bağlantı verir.
  - IN: çekirdeğe bağlantı verir ama bağlantı almaz.
  - OUT: çekirdekten bağlantı alır ama dışarı bağlantı vermez.
  - Dallar (tendrils), kopuk bileşenler (disconnected components), adacıklar.
- Statik web, dinamik web ve gizli web
  - Statik web: içeriği seyrek değişir (ör. Wikipedia). Arama motorlarınca indekslenir.
  - Dinamik web: sayfa, istek geldiğinde sunucuda veritabanından üretilir (ör. haber ve e-ticaret siteleri).
  - Statik ve dinamik web birlikte açık web'i (public web) oluşturur.
  - Gizli web: yalnızca bir sitenin kendi araması üzerinden erişilir, arama motorlarınca indekslenmez.
- Anlamsal web: HTML'e ek olarak RDF/OWL dosyaları içerir. Akıllı ajanlar (intelligent agents) bu dosyalardan çıkarım yapar.
- Data, information, knowledge ve wisdom
  - Data: ham HTML sayfaları.
  - Information: bir sorgunun ilk 10 sonucu.
  - Knowledge: bu sonuçları tek tek işleyen kullanıcının vardığı bilgi.
  - Wisdom: aynı bilgiye çok sayıda kişinin varması.
- Recall ve precision
  - $A$: ilgili belgeler, $B$: getirilen belgeler.
  - $\text{Recall} = \frac{|A\cap B|}{|A|}$
  - $\text{Precision} = \frac{|A\cap B|}{|B|}$
  - Yaygın ölçüt: ilk 10 sonuç için precision (precision@10).
- IR modeli dört şey tanımlar:
  - sorgu dili,
  - sorgu gösterimi,
  - belge gösterimi,
  - sorguyu belgelerle eşleştiren ve sonuçları sıralayan bir fonksiyon.
- Derste Boolean ve vektör uzayı (vector space) modelleri işlenecek.
- Bag of words
  - Belge, sözcüklerin çoklu kümesi (multiset) olarak gösterilir.
  - Sözcük sırası ve belge yapısı (HTML etiketleri) kaybolur.
  - Gösterim basittir; depolama ve erişim için verimlidir.
- Internet ve web
  - Internet: fiziksel ağ altyapısı.
  - Web: internet üzerinde çalışan, birbirine bağlantı veren sayfalardan oluşan yazılım katmanı.

## Detaylı Açıklamalar

### Dersin işleyişi

Hoca izlencede dersin kitabı bölüm bölüm izleyeceğini söyler. Kitabın PDF'i ve her bölümün slaytları web'de bulunabilir. Hoca kendi slaytlarını da paylaşacağını söyler.

İzlencedeki ders planı (taslak):
1. Derse giriş.
2. Web madenciliğine giriş (Bölüm 1).
3. Web taraması (Web Crawling) (Bölüm 8).
4. Gözetimli öğrenme (Supervised Learning) (Bölüm 3).
5. Gözetimsiz öğrenme (Unsupervised Learning) (Bölüm 4).
6. Bilgi erişimi ve web araması (Information Retrieval and Web Search) (Bölüm 6).
7. Bağlantı analizi (Link Analysis) (Bölüm 7).
8. Sosyal ağlar (Social Networks).
9. Bilgi yayılımı (Information Diffusion).

Hoca dönem içi çalışmanın notun önemli bir kısmını (söylediğine göre %60'ını) oluşturduğunu belirtir. Not dağılımının üniversitenin çevrim içi eğitim kararlarına göre değişebileceğini de ekler.

### Web'in yapısı (bow-tie)

2000 yılında web'in bağlantı yapısını inceleyen bir çalışmada tüm erişilebilir sayfalar taranmış, aralarındaki bağlantılar incelenmiştir. Ortaya çıkan şekil bir papyona benzer:

- **Çekirdek:** Birbirine karşılıklı bağlantı veren çok sayıda sayfa.
- **Giriş tarafı:** Hiç bağlantı almayan, ama çekirdeğe bağlantı veren çok sayıda sayfa.
- **Çıkış tarafı:** Çekirdekten bağlantı alan, ama dışarı hiç bağlantı vermeyen sayfalar.
- **Kopuk bileşenler:** Yalnız birbirine bağlantı veren, web'in geri kalanıyla bağı olmayan "adacıklar".
- **Dallar (tendrils):** Giriş ya da çıkış tarafına bağlı, kendi aralarında bağlantılı küçük gruplar.

Hoca bu yapının bugün de büyük ölçüde geçerli olduğunu söyler.

### Web verisine farklı açılardan bakış

Veri kaynakları şunlardır: web, kurumun iç ağı (intranet), kişisel disk, dijital kütüphaneler (IEEE, ACM, okulun kütüphanesi) ve e-posta.

| Bakış açısı | En yüksek | En düşük |
| --- | --- | --- |
| Karmaşıklık | Web (CRM, ERP gibi yapılı veriler de içerir) | E-posta |
| Hacim | Web | E-posta |
| Gizlilik | E-posta, intranet | Web |
| Düşmanca içerik (adversarial) | Web | İntranet, disk |

Hoca, kişisel bilgisayarların artık terabaytlarca depolamaya sahip olduğunu, slayttaki gigabayt ölçeğinin eskidiğini belirtir.

Web'in boyutu Google ve Bing'in indeks büyüklüğüne göre tahmin edilir. Hoca bunu canlı olarak gösteren bir siteyi açar. Veri tek bir makineye sığmaz. Arama motorları taramak, indekslemek ve aramak için binlerce bilgisayarlı veri merkezleri kullanır.

### Statik, dinamik, gizli ve anlamsal web

- **Statik web:** Bir URL ile erişilen, içeriği seyrek değişen sayfalar. Arama motorları bu sayfaları tarar ve ters indeks tablosuna ekler.
- **Dinamik web:** Sayfa önceden var olmaz. Kullanıcı bağlantıya tıkladığında sunucu, JavaScript ya da CGI betiği gibi bir betikle içeriği veritabanından üretir. Bugün tıklanan sayfanın içeriği yarın farklı olabilir.
- **Gizli web:** Yalnızca belirli bir sitenin içinden erişilebilen sayfalar. Örneğin Amazon'un iç ürün sayfalarına sitenin kendi aramasıyla ulaşılır. Bu sayfalar arama motorlarınca indekslenmez.
- **Anlamsal web:** Sayfada HTML'e ek olarak RDF ya da OWL dosyası bulunur. Bu dosyalar akıllı ajanların sayfadan bilgi çıkarmasını sağlar.
  - Hocanın örneği: Bir doktorun sitesindeki OWL dosyası, doktorun uzmanlık alanını ve uygun saatlerini tanımlar. Telefondaki bir ajan bu bilgiyi okuyup kullanıcıya sormadan randevu alabilir.
  - Bir öğrencinin sorusu üzerine hoca bir OWL örneği gösterir. Örnekte Professor → Faculty → Employee → Person biçiminde bir taksonomi var. Professor için "bir organizasyonda çalışır" ve "bir dersi verir" gibi kısıtlar (restriction) tanımlı.
  - Ajan bu yapılı veriden, HTML'i ayrıştırıp doğal dil işleme yapmaya gerek kalmadan hangi dersin hangi saatte verildiği gibi bilgileri çıkarabilir.

### Kalabalıkların bilgeliği (wisdom of crowds)

Web'de birbirini tanımayan çok sayıda kişiden veri toplanır. Bu veriden herkesin işine yarayan uygulamalar üretilir.

- **Flickr etiketleri:** "Jaguar" aynı anda bir otomobil markası, vahşi bir hayvan, bir gitar türü ve bir savaş uçağı olabilir. Görüntü içeriğinden bu ayrımı yapmak zordur. Kullanıcıların koyduğu etiketler kullanılarak resimler anlamlı gruplara ayrılabilir.
- **Flickr konum haritası:** Akıllı telefonlar fotoğrafa EXIF verisi olarak çekim yerini (GPS) ve zamanını yazar. Turistlerin paylaştığı fotoğraflardan bir bölgenin en çok fotoğraflanan noktaları bulunur. Böylece zamanı kısıtlı bir ziyaretçiye gezilecek yerler önerilir.
- **Google Trends:** Dünya genelinde girilen sorgulardan aylık eğilim raporları üretilir.
- Bu uygulamalar popülerlik, çeşitlilik, kalite ve kapsama (coverage) özelliklerine bakar. Bunların bütünü uzun kuyruk (long tail) kavramıyla anılır.
- Kalabalıkların bilgeliği arama sıralamasında, web yazarları ve editörleri, yayıncılar ve etiketleyiciler tarafından kullanılır.

### Bilgi erişimi ile veritabanı erişimi

| Veritabanı erişimi | Bilgi erişimi |
| --- | --- |
| Veri tablolarda, yapılı (birincil ve yabancı anahtar, sütun = nitelik) | Veri belgelerde (PDF, HTML, metin vb.) |
| Sorgu da yapılıdır (`SELECT`) | Sorgu anahtar sözcüklerle yapılır, yapısızdır |
| Daha kolay | Çok daha zor |

Web araması, bilgi erişiminin özel ve zor bir hâlidir:
- Sayfalar dağıtık HTTP sunucularında durur. Önce merkezî bir yere toplanmaları gerekir. Toplama, saklama ve güncelleme zordur.
- Kullanıcı sayısı çok yüksektir. Sistem hem web'in boyutuna hem kullanıcı sayısına göre ölçeklenmelidir.
- Spam sayfalar, ilk 10 sonuçta görünmek için kendilerini temsil etmeyen çok sayıda anahtar sözcük kullanır.

### Kalite ölçütleri

Hoca bir belge koleksiyonu üzerinde iki küme çizer: sorguya ilgili olan belgeler ($A$) ve motorun getirdiği belgeler ($B$, örneğin ilk 10 sonuç). Getirilen belgelerin bir kısmı ilgili, bir kısmı ilgisizdir.

- **Recall:** İlgili belgelerin ne kadarı getirildi? $|A\cap B|/|A|$
- **Precision:** Getirilen belgelerin ne kadarı ilgili? $|A\cap B|/|B|$. Türkçe yayınlarda "tutturma" diye çevrilir.
- Web'de bir sorguya ilgili tüm belgelerin sayısı bilinmez. Bu yüzden web arama motorları ağırlıklı olarak precision ile ölçülür.
- Kurum içi bir IR sisteminde ilgili belgeler bilinebilir. Orada recall da kullanılabilir.
- Precision@10, @20, @30 gibi türleri vardır. En yaygını precision@10.
- **Çeşitlilik:** Bir aramada tüm sonuçlar aynı siteden geliyorsa motor tek bir bakış açısı sunar. Bu istenmez.

### Bag of words gösterimi

Slayttaki örnek cümle: "That's one small step for a man, a giant leap for mankind". Gösterimi şöyledir:

`{that's, one, small, step, for (2), a (2), man, giant, leap, mankind}`

- Tüm belgelerdeki sözcüklerden bir sözcük dağarcığı (vocabulary) uzayı oluşturulur. Her belge, her sözcüğün kaç kez geçtiğini tutan bir sayı vektörü olur.
- **Dezavantajlar:**
  - Sözcük sırası kaybolur.
  - Belge yapısı kaybolur. Örneğin HTML'de başlık etiketi içindeki bir sözcük daha önemlidir, ama bu gösterim bunu yansıtmaz.
- **Avantajlar:** Basittir, depolama ve erişim için verimlidir. Bu gösterimi kullanan IR modelleri iyi sonuç verir, ama iyileştirmelere ihtiyaç duyar.

### Temel terimler

- **Internet ve web:** Internet, sunucuları ve cihazları birbirine bağlayan altyapıdır. Web ise internetin üzerinde çalışan, birbirine bağlantı veren sayfalardan oluşan yazılım katmanıdır. Web, internet olmadan çalışamaz.
- **Link ve hyperlink:**
  - Link: bir sayfadan diğerine gitmek için kullanılan URL'nin açık hâli.
  - Hyperlink: arkasında link bulunan, tıklanabilir metin.
- **Hypertext ve hypermedia:** Tıklandığında başka bir yere götüren metin ya da çoklu ortam öğesi.
- **HTTP ve HTML:** HTTP iletişim protokolüdür. HTML ise tarayıcıların işleyip gösterdiği hiper metindir.
- **Anchor text:** Tıklanabilir bağlantı üzerinde görünen metin.

### Arama motoru mimarisi

1. **Crawler:** Birkaç sayfayı indirir ve içlerindeki bağlantıları çıkarır. Sonra bu bağlantıların gösterdiği diğer HTTP sunucularına gidip yeni belgeleri indirir. Web böyle, sayfadan sayfaya atlanarak taranır. Google'ın tarayıcısı Googlebot'tur. Hoca Bing'in tarayıcısını "MSNBot" olarak anar.
2. **Metin ve bağlantı analizi:** İndirilen sayfalardan ters indeks oluşturulur. Bağlantı analiziyle sayfaların popülerliğine dayalı bir sıralama (PageRank) çıkarılır.
3. **Sorgu:** Anahtar sözcük ters indeks tablosunda aranır. Bulunan sonuçlar PageRank veritabanındaki popülerlik bilgisine göre yeniden sıralanır.

Hoca eski bir Google ekranında "Cached" ve "Similar pages" bağlantılarını gösterir. Arama motorlarının işlevlerini pazara ve müşteri isteklerine göre değiştirdiğini söyler.

Derste ayrıca sosyal ağlar (Facebook, Twitter, Instagram vb.) ve sosyal ağ ölçütleri işlenecek. Örneğin bir aktörü diğerlerinden daha önemli yapan şeyin ne olduğuna bakılacak.

Sonraki konu Bölüm 2: ilişkilendirme kuralı madenciliği (association rule mining) ve sıralı örüntü madenciliği (sequential pattern mining). Ardından gözetimli ve gözetimsiz öğrenme kısaca hatırlatılacak.

### Ders sonrası notlar

- **Web'in doğuşu:** Tim Berners-Lee web önerisini 1989'da yazdı. İlk web sunucusu ve tarayıcısı 1990 sonunda CERN'de çalıştı. Hocanın "1990" demesi bu anlamda doğru.
- **Mosaic:** NCSA Mosaic'in X Window System sürümü 1993'te yayımlandı. Altyazıdaki "hypertext query for X1 window system" ifadesi bu sürümü anlatıyor.
- **Bow-tie çalışması:** Hocanın gösterdiği resim Broder ve arkadaşlarının 2000 tarihli "Graph structure in the Web" makalesinden. Makalede bileşenlerin adları SCC (çekirdek), IN, OUT, tendrils, tubes ve disconnected components olarak geçer.
- **OWL:** Altyazıda "OVL" diye geçen dosya türü OWL'dir (Web Ontology Language).
- **URL'nin açılımı:** Hoca "universal resource locator" diyor. Doğrusu Uniform Resource Locator.
- **Bant genişliği iddiası:** Hoca internetin toplam bant genişliğinin %60'tan fazlasını arama motorlarının kullandığını söylüyor. Bu iddia güncel trafik ölçümleriyle desteklenmiyor. Trafiğin büyük kısmını video akışı oluşturuyor.
- **Bing'in tarayıcısı:** MSNBot eski addır. Bing'in bugünkü tarayıcısı Bingbot'tur.
- **Bag of words dezavantajı:** Hoca bir yerde "kelime sırasını kullanıyoruz" der, hemen ardından düzeltir. Doğrusu: bu gösterimde sözcük sırası kaybolur.
- **Recall tanımı:** 01:24 civarında hoca recall'u anlatırken önce "getirilen belgeler arasında" der, sonra düzeltir. Doğru tanım: ilgili belgeler arasından getirilenlerin oranı ($|A\cap B|/|A|$).
- **Ders kitabı:** Kitabın 2011 tarihli ikinci baskısı da vardır.
- **Altyazı hataları:**
  - 00:14 ve 00:16'da tekrar eden "bu tarzıları", "bu metodolosu" satırları anlamsızdır.
  - 01:25–01:26 arasındaki İngilizce cümleler, hocanın Türkçe söylediklerinin bozuk çevirisidir.
  - "Filiqr", "Filikl" Flickr; "Begok words", "Beghoff" bag of words; "online.yelubis.edu" Online Yıldız demektir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
