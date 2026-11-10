# Ders 2 Genişletilmiş Notu: Derse Giriş: Web Verisi, Bilgi Erişimi ve Arama Motorlarına Genel Bakış

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Kapsamı ve Ders Kitabı
- 2. Web Verisi ve Derste Öğrenilecek Teknikler
- 3. Web'in Kısa Tarihi
- 4. Web'in Yapısı: Papyon (Bow-Tie) Modeli
- 5. Web Verisine Farklı Açılardan Bakış
- 6. Statik, Dinamik, Gizli ve Anlamsal Web
- 7. Web'in Büyüklüğü
- 8. Web Verisini Neden İnceliyoruz?
- 9. Kalabalıkların Bilgeliği (Wisdom of Crowds)
- 10. Bilgi Erişimi ve Veri, Enformasyon, Bilgi, Bilgelik
- 11. Bilgi Erişimi ile Veritabanı Erişimi; Web Aramasının Zorlukları
- 12. Bilgi Erişimi Modelleri
- 13. Arama Kalitesi: Recall, Precision ve Çeşitlilik
- 14. Kelime Torbası (Bag of Words) Gösterimi
- 15. Sık Karıştırılan Temel Terimler
- 16. Bir Arama Motoru Nasıl Çalışır?
- 17. Sosyal Ağlar ve Bu Dersi Neden Almalı?
- 18. Sonraki Konular
- Örnek Sorular

## 1. Dersin Kapsamı ve Ders Kitabı

Hoca derse izlenceyi (syllabus) göstererek başladı. Bu ders kapsamında bilgi erişimi (information retrieval) ve web arama motorları (web search engines) konuşulacak. Bu ilk derste amaç, önümüzdeki haftalarda neler işleneceğini ve üzerinde çalışılacak verinin nasıl bir veri olduğunu görmek. Hoca dersi İngilizce işleyeceğini, sınıfın durumuna göre zaman zaman Türkçeye geçebileceğini söyledi.

Ders bir kitabı bölüm bölüm izleyecek: Bing Liu'nun *Web Data Mining* kitabı. Hoca kitabın adını aratınca PDF'ine ve her bölüm için hazırlanmış sunum slaytlarına web'de ulaşılabileceğini söyledi. Kendi slaytlarını ve ders materyallerini de ayrıca paylaşacak.

<!-- BELİRSİZ: İzlencedeki ders planı ve kitabın tam künyesi yalnız ekranda; altyazıda yalnızca "Web Data Mining by Bing Leo" geçiyor. Kısa nottaki bölüm listesi altyazıdan doğrulanamadı. -->

## 2. Web Verisi ve Derste Öğrenilecek Teknikler

Bu derste üzerinde çalışılacak veri web verisidir (web data). Amaç, yapısız (unstructured) ve yarı yapılı (semi-structured) bilgiyi anlamak ve web verisinden bilgi çıkarmaktır.

Hoca web verisinin veritabanı verisinden, yani ilişkisel veritabanlarındaki (relational databases) veriden farklı olduğunu vurguladı. Web verisi dört özellik taşır:

- **Yapısız (unstructured):** Tablo, sütun gibi sabit bir yapısı yoktur.
- **Yarı yapılı (semi-structured):** HTML etiketleri gibi kısmi bir yapı vardır.
- **Hiper metin (hypertextual):** Sayfalar birbirine bağlantı verir.
- **Dağıtık (distributed):** Veri, dünyanın farklı yerlerindeki uygulama sunucularında (application servers), HTTP sunucularında durur.

Ders boyunca bu veri üzerinde şu işler öğrenilecek:

- **Tarama (crawling):** Dağıtık sunuculardaki veriyi yerel bir veritabanına çekmek. Ancak böyle işlenebilir.
- **İndeksleme (indexing):** Bu veriden bir tablo oluşturmak. Böylece veri üzerinde hızlı arama yapılabilir.
- **Sıralama (ranking):** Web'den getirilen sonuçları sıralamak.
- **Filtreleme:** Metin ve bağlantı analizi (text and link analysis) kullanan farklı filtreleme algoritmaları.

Bu konuların birçok uygulama alanı vardır. Hoca arama (search) uygulamalarını saydı; ders boyunca arama motorlarının nasıl çalıştığı öğrenilecek. Diğer alanlar: sınıflandırma (classification), takip (tracking), izleme (monitoring) ve web zekâsı (web intelligence).

## 3. Web'in Kısa Tarihi

Üzerinde çalışılacak veri World Wide Web'den geldiği için hoca web'in nasıl başladığına baktı. Web 1990'da CERN adlı araştırma merkezinde, orada çalışan Tim Berners-Lee tarafından başlatıldı.

Tim Berners-Lee önce bir uygulama sunucusu, yani bir HTTP sunucusu ve basit bir işaretleme dili (markup language) yazdı. Amacı, dahil olduğu projenin diğer üyeleriyle bilgi paylaşmaktı. Komut satırını kullanarak işaretleme dilindeki metni HTTP protokolüyle bu sunucuya gönderiyordu. Böylece ekibin diğer üyeleri de paylaşmak istediklerini yayımlayabiliyor, başkalarının paylaştıklarını görebiliyordu.

HTTP protokolünün ve ilk HTTP sunucusunun ardından, birkaç yıl içinde işaretlenmiş metni görüntülemek (render) için ilk tarayıcılar, ilk grafik kullanıcı arayüzleri çıktı. Web'i yaygın olarak kullanılır hâle getiren ise 1993'te çıkan Mosaic oldu. Mosaic, X Window System için yazılmış bir hiper metin tarayıcısıydı. HTML işaretleme dilini görüntüleyebiliyor ve HTTP ile HTML sayfası isteği gönderebiliyordu. Mosaic'ten sonra web, 1993'ten itibaren üniversitelerde ve araştırma kurumlarında birçok kişi tarafından kullanılmaya başladı.

> **Ders sonrası not:** Altyazıda "hypertext query for X1 window system" geçiyor. Kastedilen büyük olasılıkla X Window System için yazılmış Mosaic sürümüdür. Ayrıca Tim Berners-Lee'nin web önerisini büyük olasılıkla 1989'da yazdığı, ilk sunucu ve tarayıcının 1990 sonunda çalıştığı bilinir; hocanın verdiği 1990 tarihi bu anlamda uyumludur.

## 4. Web'in Yapısı: Papyon (Bow-Tie) Modeli

Hoca slaytta 2000 yılında çizilmiş bir resim gösterdi. Resim, web'in genel yapısını gösteren bir makaleden alınmıştı. Yapının görünüşü bir papyona (bow tie) benzer.

Bu araştırmada, dünyanın farklı yerlerindeki uygulama sunucularında duran HTML sayfaları üzerinde çalışılmıştı. Araştırmacılar erişilebilen bütün sayfaları taradı, ardından bu sayfaların bağlantı yapısına (link structure) baktı. Ortaya çıkan parçalar şunlardır:

- **Çekirdek (core):** Ortadaki dairedir. Birbirine yoğun biçimde bağlı çok sayıda sayfa içerir. Sayfalar birbirine karşılıklı, ileri geri bağlantı verir.
- **Giriş tarafı:** Hiç gelen bağlantısı (in-link) olmayan, başka hiçbir sayfadan bağlantı almayan, ama çekirdekteki sayfalara bağlantı veren çok sayıda sayfa.
- **Çıkış tarafı:** Çekirdekteki sayfalardan bağlantı alan, ama dışarıya hiç bağlantı vermeyen çok sayıda sayfa.
- **Kopuk bileşenler (disconnected components):** Web'deki "adacıklar". Kendi aralarında birbirine bağlantı veren, ama web'deki başka hiçbir sayfadan bağlantı almayan ve vermeyen sayfa grupları.
- **Dallar:** Hoca bunları "dendrites" diye andı. Kopuk bileşenler gibi kendi aralarında bağlantı verirler. Bir kısmı yalnızca giriş tarafındaki (yalnız dışarıya bağlantı veren) sayfalardan bağlantı alır. Diğer bir kısmı ise çıkış tarafındaki sayfalara bağlantı verir.

Hoca bu yapının bugün kullandığımız web'in yapısına benzediğini, yani değişmediğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Bu resim büyük olasılıkla Broder ve arkadaşlarının 2000 tarihli "Graph structure in the Web" makalesinden alınmıştır. Makalede çekirdek SCC (strongly connected component, güçlü bağlı bileşen), giriş tarafı IN, çıkış tarafı OUT, dallar ise tendrils diye adlandırılır. IN'den doğrudan OUT'a giden yollara da tubes denir.

## 5. Web Verisine Farklı Açılardan Bakış

Hoca ardından veriyi farklı açılardan karşılaştıran bir resim gösterdi. Resimde beş veri kaynağı vardı:

- **Web:** Bütün web verisi.
- **İntranet:** Her kurumun kendi yerel ağı vardır. Bu ağda web sayfaları, PDF dosyaları, HTML dosyaları gibi veriler bulunur.
- **Disk:** Kişisel bilgisayarınızdaki bütün veri.
- **Dijital kütüphane:** IEEE ya da ACM gibi dijital kütüphaneler. Hoca, Davutpaşa kampüsündeki kütüphanenin de bir dizi dijital belgesi olduğunu, bunun yerel bir dijital kütüphane sayılabileceğini söyledi.
- **E-posta:** E-postalarınızdaki bütün veri.

Bu kaynaklar dört açıdan karşılaştırıldı:

- **Karmaşıklık (complexity):** İnternetteki veri diğerlerinden çok daha karmaşıktır. Çünkü orada müşteri ilişkileri yönetimi (CRM) verisi ya da ERP yazılımı verisi de olabilir. Bu tür veri yapılı (structured) veridir ve genellikle ilişkisel veritabanlarında tutulur. En az karmaşık olan e-postalardır. Diğerleri ortadadır.
- **Hacim (volume):** En yüksek hacim web verisindedir. Ardından intranet gelir. Hoca, slaytta kişisel diskler için gigabayt yazdığını, bunun eskidiğini, bugün dizüstü bilgisayarların terabaytlarca depolama alanı olduğunu söyledi. Dijital kütüphanelerin boyutu da terabayt düzeyindedir. En az hacimli veri e-postadır.
- **Gizlilik (privacy):** Web'deki veriyi çok sayıda kişi görür ve paylaşır, bu yüzden gizlilik düşüktür. Dijital kütüphanede yalnızca erişimi olanlar görebilir. Aşağı inildikçe e-posta ve intranette gizlilik yüksektir.
- **Düşmanca içerik (adversarial):** Web'de bu özellik yüksektir. İntranet, e-posta ve diskte ise düşüktür. Çünkü bunlarda yalnızca ilgilendiğiniz türden veriyi tutarsınız. Web'de ise veri herkesten gelir.

> **Ders sonrası not:** Hoca "adversarial nedir?" diye sorup bunu "çeşitlilik" diye çevirdi. Adversarial'ın karşılığı çeşitlilik değil, "düşmanca" ya da "hasmane"dir. Burada kastedilen, içeriğin bir kısmının arama motorunu ya da kullanıcıyı yanıltmak için kasıtlı üretilmesidir (bkz. Bölüm 11'deki spam sayfalar). Hocanın verdiği gerekçe (web'de veri herkesten gelir) bu anlamla uyumludur. Altyazıda "internet has low adversarial" geçiyor; bağlama göre kastedilen büyük olasılıkla intranettir.

## 6. Statik, Dinamik, Gizli ve Anlamsal Web

Hoca web'i bambaşka bir açıdan gösteren bir resme geçti. Web'de HTML sayfaları vardır ve bunların URL'leri vardır. URL bir kaynağın adresidir. Hocanın örneğindeki URL bir PDF dosyasını gösteriyordu.

> **Ders sonrası not:** Hoca URL'yi "universal resource locator" diye açtı. Doğrusu Uniform Resource Locator'dır.

### 6.1 Statik Web

Resimdeki kırmızı elips statik web'i (static web) gösterir. Bunlar bir URL ile erişilebilen web sayfalarının bütünüdür. Statik sayfalarda içerik genellikle seyrek değişir. Hocanın örneği Wikipedia'ydı: içeriği sık değişmez.

Statik URL'li sayfalar indekslenmiş sayfalardır. Arama motorları statik sayfaların içeriğini tarar ve ters indeks tablosu (inverted index table) adı verilen bir tablo oluşturur. Arama yaparken bu tabloyu kullanırlar. Yani arama bir tablo üzerinde yapılır. Bu tablonun içeriği, web'den taranmış HTML sayfalarından toplanır.

### 6.2 Dinamik Web

Mavi elips dinamik web'i (dynamic web) gösterir. Dinamik web'e de bir URL ile erişilir. Ancak bu türde web sayfası önceden var olmaz. Bağlantıya tıkladığınızda, HTTP sunucusu isteği aldığı anda sayfayı oluşturur. Sayfanın içeriği veritabanlarından gelir. Bu işi genellikle betikler (scripts) yapar; bir JavaScript ya da bir CGI betiği olabilir. Tıkladığınızda sayfanın içeriği sunucu tarafındaki veritabanlarından toplanır.

Bu yüzden bugün gidip bağlantıya tıklarsanız içerik dünkünden farklı olabilir; yarın gittiğinizde yine farklı olabilir. Özellikle haber siteleri ve e-ticaret siteleri içeriklerini sürekli değiştirir. Hoca Türkiye'deki e-ticaret sitelerini örnek verdi (altyazıda biri "Hepsi Boroda" diye geçiyor, büyük olasılıkla Hepsiburada). Bu siteler içeriklerini veritabanından topladıkları için içerik değişir.

Statik web ile dinamik web birlikte açık web'i (public web) oluşturur. Açık web, herkesin bir URL kullanarak erişebildiği web'dir.

### 6.3 Gizli Web

Açık web alanının dışında gizli web (hidden web) vardır. Gizli web'e yalnızca belirli bir web sitesinin içinden erişilebilir. Hocanın örneği Amazon'du: Ana sayfanın altında çok sayıda alt sayfa, iç sayfa vardır. Ama bu iç sayfalara yalnızca Amazon'un ana sayfasına gidip Amazon sitesinde arama yaparak ulaşabilirsiniz. Yani web'de bazı sayfalar ancak belirli bir site üzerinden erişilebilir. Bu sayfalar arama motorlarınca indekslenmediği için "gizli" diye anılır.

### 6.4 Anlamsal Web

Web'in bir başka kısmı anlamsal web'dir (semantic web). Erişilebilen her web sayfasının bir HTML sayfası vardır. Anlamsal web'de HTML sayfasına ek olarak başka türden bir dosya da bulunabilir: RDF ya da OWL dosyası. Bunlar dosya uzantılarının adıdır.

Peki HTML sayfasına ek olarak neden başka dosyalara ihtiyaç var? Anlamsal web, akıllı ajan (intelligent agent) uygulamalarının çalışmasını sağlar. Bu ajanlar web sayfalarıyla etkileşime girip bizim için yararlı bilgileri çıkarabilir.

Hocanın örneği bir doktorun web sitesiydi. Sitede HTML sayfasına ek olarak bir anlamsal web dosyası, bir OWL dosyası olabilir. Bu dosya doktorun belirli alanlara odaklandığını, örneğin perşembe sabahları müsait olduğunu belirtebilir. Telefonunuzda bu akıllı ajan uygulaması çalışıyorsa, telefon bölgenizdeki doktorların web sayfalarıyla etkileşime girebilir. Ajan bu OWL dosyalarına erişip doktorun size yakın olup olmadığını, ilgilendiğiniz alanda çalışıp çalışmadığını ve sizin uygun olduğunuz saatlerde müsait olup olmadığını öğrenir. Sonra size sormadan doktorun web sayfası üzerinden randevu alabilir.

Anlamsal web dosyalarını bugünkü web'den ayıran budur. Bu dosyalar, akıllı ajanların web sayfalarıyla etkileşebilmesi için vardır.

> **Ders sonrası not:** Altyazıda dosya türü "OVL" diye geçiyor. Doğrusu OWL'dir (Web Ontology Language).

### 6.5 Bir OWL Örneği

Bir öğrenci anlamsal veriye örnek istedi. Hoca bir OWL dosyası gösterdi.

**Soru:** Anlamsal veriye (semantic data) bir örnek verebilir misiniz?

**Cevap:** Hocanın gösterdiği OWL dosyasında yapılı (structured) bir yapı vardı. Dosyada "profesör" (Professor) adlı bir kaynak (resource) tanımlanmıştı. Profesörün ait olduğu bir başka kategori vardı: Faculty. Onun dahil olduğu başka bir kategori vardı: Employee. Onun da dahil olduğu bir kategori daha vardı: Person. Böylece bir taksonomi oluşur:

$$\text{Professor} \rightarrow \text{Faculty} \rightarrow \text{Employee} \rightarrow \text{Person}$$

Aynı şekilde profesörle ilgili kısıtlar (restriction) da tanımlanabilir. Örneğin "bu profesör bir organizasyon için çalışır" kısıtı. Ya da profesörün bir dersin hocası olduğu, bir dersi öğrettiği belirtilebilir.

Bu, bir OWL dosyasının yalnızca bir parçasıydı. Dosyada profesör, faculty, collection, person, employee, course gibi öğeler vardı; bunların hepsi birer kaynaktır. Hoca bu kaynakları bir araya getiren bir şema da gösterdi: person, professor, student, university gibi kaynaklar ve aralarında az önceki örnekteki özellikler (property).

Bu yapıya göre oluşturulmuş OWL dosyaları üzerinde anlamsal ajanlar akıl yürütme (reasoning) yapabilir. Hoca bunu kendi üzerinden anlattı: Bu bir şablondur (template). Kendisi için bir OWL dosyası yaratsa, üniversite yerine Yıldız Teknik Üniversitesi, person yerine kendi adı, profesör yerine unvanı yazar; hangi dersi verdiği kısmına da "information retrieval" yazılır. Bu şablona göre oluşturulmuş veriyi inceleyen bir anlamsal ajan, hocanın hangi dersleri verdiğini, haftanın hangi saatlerinde ofis saati (office hour) olduğunu, hangi saatlerde ders verdiğini çıkarabilir. Bunu ona sormadan, sayfasındaki HTML'i ayrıştırıp (parse) doğal dil işleme (natural language processing) teknikleriyle anlamaya çalışmadan, yalnızca bu veriye bakarak yapar. Anlamsal web'in sağladığı avantaj budur.

## 7. Web'in Büyüklüğü

Hoca slayttaki bilginin eskidiğini söyleyerek web'in büyüklüğünü canlı olarak gösteren bir siteyi açtı. Site, web'in boyutunu herkesin kullandığı arama motorlarının indeks büyüklüklerine göre hesaplıyor. Bunlardan biri Google, diğeri Bing. Bunlara ek olarak başka arama motorları da kullanılabiliyor. Site, web'de görüntülenebilen toplam sayfa sayısını sürekli gösteriyor.

<!-- BELİRSİZ: Sitenin adı ve gösterdiği sayfa sayısı altyazıda geçmiyor. -->

Bunu göstermenin amacı şuydu: Burada büyük ölçekli veriden (large scale data) söz ediyoruz. Bu veri tek bir makineye (node) sığmaz. Bu veriyi taramak çok zordur. Arama yapılabilmesi için indeksini oluşturmak çok zordur. Bu yüzden küresel arama motorları binlerce bilgisayardan oluşan çok sayıda veri merkezi (data center) kullanır. Bu bilgisayarlar web verisini taramak, indekslemek ve aramayı yürütmek için çalışır.

## 8. Web Verisini Neden İnceliyoruz?

Hoca web verisinin farklı yönlerini gösterdikten sonra, bunu neden incelediğimizi anlattı. Web'i bir nesne gibi düşünebiliriz. Web'i günlük hayatta sık kullanıyoruz; yalnız bilgisayar bilimi okuyan bizler değil, çok sayıda insan.

Web verisini ve web veri madenciliği (web data mining) tekniklerini inceleyerek amaçlananlar şunlardır:

- Kullanıcı odaklı daha iyi web tasarımları (user-driven web design) yapmak. Böylece web'i kullananlar bu teknolojilerden yararlanıp daha iyi, daha kullanıcı dostu uygulamalar kullanabilir.
- Web uygulamalarının başarımını (performance) ve kalitesini artıran teknikleri öğrenmek.
- Sosyal ağlarda neler olduğunu anlamak. Derste sosyal ağ teknikleri de öğrenilecek.

Kısacası öğrenilecek tekniklerin hepsi ve web'deki veriyi anlamak, daha iyi web uygulamaları yapmamızı sağlayacak.

## 9. Kalabalıkların Bilgeliği (Wisdom of Crowds)

Web'de yaptığımız şeylerden biri kalabalıkların bilgeliğini (wisdom of crowds) kullanmaktır. Yani çok sayıda kişiden, hem de birbirini tanımayan kişilerden veri toplarız. Bu kişilerden bilgi çıkarırız. Bu bilgiyi kullanarak tek tek her birey için yararlı olabilecek uygulamalar yaparız. Kalabalıkların bilgeliği budur. Hoca kavramı örneklerle anlattı.

### 9.1 Flickr Etiketleri: Jaguar Örneği

Flickr, birçok kişinin fotoğraf paylaşmak için kullandığı bir web sitesidir. Bir fotoğraf çekersiniz, beğenirseniz Flickr'da paylaşırsınız. Flickr'a benzer başka birçok site vardır; Flickr yalnızca bir örnektir.

Slayttaki fotoğrafların hepsi "Jaguar" fotoğrafı sayılabilir. Ama Jaguar bir otomobil markasıdır, aynı zamanda vahşi bir hayvandır, bir gitar türüdür ve bir savaş uçağıdır. Bu fotoğraflara bakıp onları anlaşılır ve anlamlı biçimde gruplamaya çalışırsanız bu çok zordur. Fotoğrafların metnini, etiketlerini bilmiyorsanız mevcut teknolojilerle sınıflandırmak çok güçtür. Çünkü fotoğrafın içeriğini işlemek zordur. Bugün görüntü işleme (image processing) teknikleri vardır, ama bu fotoğraflardan bazılarını işleyip "bunun içeriğinde vahşi hayvan var" ya da "bunun içeriğinde savaş uçağı var" demek çok zordur.

Bu yüzden fotoğrafı yükleyen kişiden gelen etiketlere ihtiyaç vardır. Bu etiketler fotoğraf paylaşan bütün kişilerden gelir. Bu kişilerin etiketlerini kullanarak fotoğrafları sınıflandırabilir, anlamlı biçimde gruplayabilirsiniz. Flickr'ın bu fotoğrafları hiç karıştırmadan, düzgünce kategorilere ayıran bir uygulaması vardır.

Hocanın vurguladığı nokta şuydu: Birbirini tanımayan çok sayıda kişiden gelen etiketleri, yani kalabalığın bilgeliğini kullanarak, fotoğrafın içeriğine bakmadan yalnızca etiketine bakarak fotoğrafları akıllıca kümeleyen (cluster) böyle bir uygulama yapılabilir.

### 9.2 Flickr Konum Haritası

Flickr'ın bir başka uygulaması akıllı telefonlarla çekilen fotoğraflar üzerinde çalışır. Akıllı telefonunuzla her fotoğraf çektiğinizde telefon, fotoğrafın içine bir dosya ekler (altyazıda "exit file" geçiyor; kastedilen EXIF). Bu dosyada çekim yerinin GPS konumu ve çekim zamanı bulunur. Yani bir arkadaşınızla fotoğraf paylaştığınızda, fotoğrafı ne zaman ve nerede çektiğinizin bilgisini de gönderirsiniz. Fotoğrafı alan kişi bunu anlayabilir, çünkü bu bilgi fotoğraf dosyasının içine yazılmıştır.

Flickr bu bilgiyi kullanır. Belirli bir yeri ziyaret eden turistlerin hepsi fotoğraf çeker ve Flickr'da paylaşır. Slayttaki haritada kırmızı noktalar, çok sayıda kişinin belirli bir zamanda fotoğraf çekip Flickr'da paylaştığı konumlardır. Uygulama size güzel manzaralı yerlerin bunlar olduğunu söyler. Bir yeri ziyaret etmek istiyorsanız ve zamanınız kısıtlıysa, gezmeniz gereken yerler bunlardır, çünkü birçok kişi bu yerleri ziyaret etmeyi tercih ediyor. Flickr bu uygulamayı çok sayıda başka kişiden bilgi toplayarak yapar. Bu da bir kalabalıkların bilgeliği uygulamasıdır.

> **Ek bilgi (derste anlatılmadı):** EXIF (Exchangeable Image File Format), dijital fotoğraf dosyalarına gömülen bir üst veri (metadata) biçimidir. Kamera modeli, çekim ayarları, tarih-saat ve cihaz izin veriyorsa GPS koordinatları gibi bilgileri taşır. Bu yüzden konum bilgisi taşıyan bir fotoğrafı paylaşmak, çekim yerini de paylaşmak anlamına gelebilir.

### 9.3 Uzun Kuyruk ve Diğer Kullanımlar

Bu uygulamalar popülerliğe, çeşitliliğe (diversity), kaliteye ve kapsamaya (coverage) bakar. Hoca bunların bütününe uzun kuyruk (long tail) kavramı dendiğini söyledi.

Kalabalıkların bilgeliği şu yerlerde kullanılabilir:

- Arama sıralamasında (search ranking).
- Web yazarları ve editörleri tarafından.
- Web yayıncıları ve web etiketleyicileri (web taggers) tarafından.
- Sorgularda. Örneğin Google her ay eğilim (trend) raporları üretir. Bu eğilim bilgisi, dünyanın dört bir yanındaki farklı kullanıcıların girdiği sorgulardan gelir. Google burada kalabalığın bilgeliğini, yani çok sayıda kişinin sık yaptığı sorguları toplar ve güncel eğilimleri içeren raporlar oluşturur.

<!-- BELİRSİZ: "Long tail" kavramının popülerlik, çeşitlilik, kalite ve kapsama ile ilişkisi altyazıda yalnızca bir cümlede geçiyor; slayttaki tam ifade okunamadı. -->

## 10. Bilgi Erişimi ve Veri, Enformasyon, Bilgi, Bilgelik

Hoca, şimdiye kadar gösterdiği slaytların aslında ders boyunca işlenecek konuların bir ön izlemesi olduğunu söyledi. Amaç, web veri madenciliğinde nasıl bir veriyle karşılaşılacağını ve hangi yöntemlerin öğrenileceğini görmekti.

Bu derste bilgi erişimi (information retrieval, IR) öğrenilecek. Bilgi erişimi, bir belge koleksiyonundan veri getirme işidir. Belgeler PDF belgeleri, HTML belgeleri ya da ofis uygulamalarıyla kullandığımız her türlü belge olabilir. Bilgi erişimi anahtar sözcükler (keywords) vererek arama yapmamızı sağlar. Anahtar sözcükleri belgelerle eşleştiren tekniklere odaklanır ve aramanın sonucu olarak bir belge listesi getirir.

Bugün arama için kullandığımız Google ve Bing gibi uygulamalar bilgi erişiminin örnekleridir. Ancak bunlar bütün web verisini çözümleyebilen ileri düzey bilgi erişimi motorlarıdır. Yani Google ya da Bing bilgi erişimi yapar, ama bunu büyük ölçekli veri üzerinde yapar.

### 10.1 Veri, Enformasyon, Bilgi ve Bilgelik

Hoca web verisinden öğrenmeye çalıştığımız şeyleri dört basamakta sınıflandırdı:

- **Veri (data):** Ham web sayfaları. Bu ders kapsamında HTML sayfalarına veri diyoruz.
- **Enformasyon (information):** Bir sorgunun sonucu. Arama motoruna bir anahtar sözcük girip arama düğmesine bastığınızda sonuçlar gelir. İlk sonuç sayfasında genellikle 10 farklı web sayfasına bağlantı vardır. Bu sonuç listesine enformasyon diyoruz.
- **Bilgi (knowledge):** Bir kullanıcı olarak sonuç listesindeki her sayfanın içine bakıp her sayfayı tek tek işlerseniz, bütün bu sonuçlardan elde ettiğiniz şeye bilgi denir. Yani enformasyon sonuç listesinin kendisidir; bilgi ise listedeki bütün sayfaları işlemenin sonucudur. Hoca bunu Türkçe şöyle anlattı: Listedeki her bağlantıya tıklayıp sitenin size söylediklerini kafanızda işlerseniz ve bunu 10 farklı sayfa için yaparsanız, bu sonuçları işlemenin sonucunda o anahtar sözcükle ilgili kafanızda oluşan şekil budur.
- **Bilgelik (wisdom):** Az önceki bilgiyi yalnızca bir kullanıcı çıkarmıştır. Aynı sonuç listesinden çok sayıda kişi aynı bilgiyi çıkarırsa bu bilgelik olur. Hocanın örneği: 100 farklı kişi bu anahtar sözcüğü arama motoruna girip bu süreci yapmışsa ve herkesin kafasında aynı resim oluşmuşsa, bu resim çok sayıda kişide oluştuğu için ona bilgelik denir. Hoca bunu Türkçeye "bilgelik" diye çevirdi.

<!-- BELİRSİZ: Hocanın "knowledge" için önerdiği Türkçe karşılık altyazıda bozuk ("ne oluş diyelim"); burada "bilgi" kullanıldı. -->

## 11. Bilgi Erişimi ile Veritabanı Erişimi; Web Aramasının Zorlukları

### 11.1 İki Dünya Arasındaki Fark

Veritabanlarında (ilişkisel ya da NoSQL) veri tablolarda, yapılı biçimde tutulur. Tablolar arasında ilişki kurmak için birincil anahtarlar (primary keys) ve yabancı anahtarlar (foreign keys) kullanılır. Her tablonun bir dizi sütunu vardır ve her sütun bir niteliğe (attribute) karşılık gelir. Arama yapmak istediğinizde `SELECT` ifadesi de yapılıdır. Her türlü sorguyu yazamazsınız; sorgu da bir yapıya dayanmalıdır. Kısacası veritabanı dünyasında her şey yapılıdır.

Bilgi erişiminde ise veri belgelerde tutulur ve belgelerin türleri farklıdır: metin dosyası, PDF dosyası ya da HTML dosyası olabilir. Arama anahtar sözcüklerle yapılır; tek bir anahtar sözcük ya da bir sözcük grubu girersiniz. Bu yüzden ne anahtar sözcüklerde ne de belgelerde bir yapı vardır. Bu nedenle bilgi erişimi, veritabanları üzerinde erişime göre çok daha zordur.

| Veritabanı erişimi | Bilgi erişimi |
| --- | --- |
| Veri tablolarda, yapılı | Veri belgelerde (metin, PDF, HTML) |
| Birincil ve yabancı anahtarlarla ilişki; her sütun bir nitelik | Belge türleri farklı, ortak bir yapı yok |
| Sorgu yapılı (`SELECT`) | Sorgu anahtar sözcüklerle, yapısız |
| Daha kolay | Çok daha zor |

### 11.2 Web Araması: Bilgi Erişiminin Zor Bir Hâli

Hoca web aramasının bilgi erişiminin özel bir hâli olduğunu, birçok sorun ve zorluk taşıdığını söyledi:

- **Toplama ve güncelleme:** Çok sayıda web sayfası vardır ve hepsi dağıtık HTTP sunucularında durur. İşleyebilmek için önce hepsini merkezî bir yere toplamanız gerekir. Belgeleri toplamak, saklamak ve güncellemek son derece zordur.
- **Ölçeklenebilirlik (scalability):** Arama motorunu kullanan kişi sayısı çok yüksektir; herkes aynı anda arama yapar. Yalnızca web'in boyutuna göre değil, arama motorunu kullananların sayısına göre de ölçeklenmeniz gerekir.
- **Spam:** Web'de kendilerini temsil etmeyen anahtar sözcükler kullanan çok sayıda sayfa vardır. Bu sayfalar arama sonuçlarında ilk 10 sonuç arasında olmak ister. Bu yüzden görünür olmak için çok sayıda anahtar sözcük kullanırlar. Bunlar spam sayfalardır.

Web arama motorları bütün bu sorunlara çözüm bulmak zorundadır.

## 12. Bilgi Erişimi Modelleri

Aradan sonra hoca bilgi erişimi modelleriyle (information retrieval models) devam etti. Her bilgi erişimi motoru, işlevini yürütmek, yani arama yapmak için bir bilgi erişimi modeli kullanır. Bir bilgi erişimi modeli şunları tanımlar:

- Bir sorgu dili (query language).
- Sorguların bir gösterimi (representation).
- Belgelerin bir gösterimi. Yani hem belge hem sorgu temsil edilir.
- Bu sorguları belgelerle eşleştirip bir sonuç listesi bulan bir fonksiyon.

Bilgi erişimi motoru ayrıca sonuçları sıralayan bir sıralama mekanizması (ranking mechanism) da getirir. Her bilgi erişimi motorunun belirli bir bilgi erişimi modeli vardır.

Farklı bilgi erişimi modelleri vardır: Boolean modeli, vektör uzayı (vector space) modeli, istatistik tabanlı modeller vb. Bu derste Boolean ve vektör uzayı modellerine bakılacak.

## 13. Arama Kalitesi: Recall, Precision ve Çeşitlilik

Derste yalnızca bilgi erişimi motorlarının nasıl çalıştığı değil, bu motorların başarısının, kalitesinin nasıl çözümleneceği de öğrenilecek.

### 13.1 Kümelerle Bir Örnek

Hoca slaytta bir web sayfası koleksiyonu çizdi. Örnek gereği koleksiyonun tamamı yereldeydi, yani içinde ne olduğu biliniyordu. Bir bilgi erişimi motoruna bir sorgu verildiğinde motor bir sonuç kümesi döndürür. Slayttaki yeşil elips bu sonuç kümesini gösteriyordu. Birçok bilgi erişimi motoru sonuç kümesinde en yüksek puanlı 10 sonucu gösterir; burada da sonuç kümesi sorguyla eşleşen ilk 10 sonuç olarak düşünülebilir. Diğer elips ise bu sorguyla ilgili (relevant) olan belgeleri gösteriyordu.

Motor ilk 10 sonucu getirmişti. Sonuçların bir kısmı sorguyla ilgiliydi, geri kalanı ilgisizdi. Yani motor sonuç kümesinde bazı ilgili sonuçları göstermeyi başarmış, ama bazıları ilgili değil. Bu bilgiyi kullanarak kalite ölçütleri tanımlanabilir. İlgili belgeler kümesine $A$, getirilen belgeler kümesine $B$ diyelim.

- **Recall:** İlgili ve getirilmiş belgelerin, toplam ilgili belgelere oranıdır.

$$\text{Recall} = \frac{|A \cap B|}{|A|}$$

- **Precision:** İlgili ve getirilmiş belgelerin, toplam getirilen belgelere oranıdır.

$$\text{Precision} = \frac{|A \cap B|}{|B|}$$

Hoca precision'ı Türkçe de anlattı: Bir arama motoruna sorgu girdiğinizde size verdiği ilk 10 sonuç içinde ilgili olanların sayısını 10'a bölerseniz precision'ı bulursunuz. Birçok yayın bunu "tutturma" diye çevirir.

> **Ders sonrası not:** Hoca recall'u tanımlarken önce "getirilen belgeler arasında" dedi, ardından kendini düzeltti. Doğru tanım yukarıdaki gibidir: recall, ilgili belgelerin ne kadarının getirildiğini ölçer ($|A \cap B|/|A|$). "Getirilen belgelerin ne kadarı ilgili" sorusu precision'ın tanımıdır.

<!-- BELİRSİZ: 01:25:34 ile 01:26:20 arasındaki recall açıklaması altyazıda bozuk İngilizceye çevrilmiş; hocanın Türkçe cümleleri tam okunamıyor. -->

### 13.2 Web'de Neden Precision?

Normal web arama motorlarında bir sorgu için ilgili bütün belgeleri bilmeyiz. Ama ilk 10 sonuca bakıp bunların ne kadarının ilgili olduğunu görebiliriz. Bu yüzden web arama motorlarının kalitesini ölçerken ağırlıklı olarak precision ölçütlerini kullanırız. Ancak kullandığımız bilgi erişimi sistemi web üzerinde değilse, örneğin bir kurum için kurulmuş, belirli bir ağ üzerinde çalışan bir sistemse ve kaliteyi onun üzerinde ölçüyorsak, recall ölçütlerini de kullanabiliriz.

> **Hocanın vurgusu:** Web'de bir sorguyla ilgili bütün belgelerin sayısı bilinmediği için web arama motorlarının kalitesi ağırlıklı olarak precision ile ölçülür.

Precision ölçütünün farklı türleri vardır: ilk 10 için precision, ilk 20 için, ilk 30 için vb. En yaygın kullanılanı ilk 10 için precision'dır (precision@10).

### 13.3 Çeşitlilik (Diversity)

Recall ve precision iki kalite ölçütüdür, ama arama kalitesinin başka yönleri de vardır. Bunlardan biri çeşitliliktir. Hoca slaytta bir arama sonucu gösterdi: Birkaç anahtar sözcük girilip arama düğmesine basılmış ve sonuçların hepsi aynı web sitesinden gelmişti. Yani çeşitlilik yoktu. Bu, arama motorunun bilgiyi belirli bir siteden topladığı ve bu sorgu için yalnızca o sitenin bakış açısını gösterdiği anlamına gelir.

Bir arama motorundan beklenen bu değildir; farklı web sitelerinden gelen sonuçlar görmeyi bekleriz. Bu yüzden arama motoru çeşitliliğe de dikkat etmekle yükümlüdür. Kaliteden söz ederken yalnızca precision'a değil, çeşitliliğe de bakmalıyız.

## 14. Kelime Torbası (Bag of Words) Gösterimi

Bilgi erişimi kapsamında belgelerin nasıl temsil edileceği de öğrenilecek. Bunlardan biri kelime torbası (bag of words) gösterimidir.

### 14.1 Örnek Cümle

Hocanın slayttaki örnek cümlesi şuydu:

"That's one small step for a man, a giant leap for mankind."

Bu cümle şöyle gösterilebilir: Her sözcük alınıp gösterime konur; bir sözcük tekrar ediyorsa sayısı da belirtilir.

$$\{\text{that's},\ \text{one},\ \text{small},\ \text{step},\ \text{for}\ (2),\ \text{a}\ (2),\ \text{man},\ \text{giant},\ \text{leap},\ \text{mankind}\}$$

Cümlede 12 sözcük, 10 farklı sözcük vardır. "for" ve "a" ikişer kez geçer, diğerleri birer kez. Bu, bir belgeyi ya da cümleyi temsil etmenin bir yoludur.

### 14.2 Dezavantajlar ve Avantajlar

Bu gösterimin dezavantajları şunlardır:

- **Sözcük sırası kaybolur.** Cümleyi görmeden yalnızca bu kümeye bakarsanız, size cümle hakkında pek bir şey söylemez.
- **Belge yapısı kaybolur.** Farklı belgelerin farklı yapıları vardır. Örneğin HTML belgelerinde farklı etiketler vardır: head, meta etiketi, body; body içinde de kalın (bold), italik ve başlık (header) için farklı etiketler kullanılır. Bu etiketler, bir sözcüğün o HTML sayfasındaki önemi hakkında bilgi verir. Örneğin bir sözcüğün etrafında başlık etiketi varsa, o sözcük sayfadaki diğer sözcüklerden daha önemlidir. Kelime torbası gösterimi sözcüğün bu önemini ve belge yapısını yakalamaz.

> **Ders sonrası not:** Hoca dezavantajı anlatırken önce "sözcüklerin sırasını kullanıyoruz" dedi, hemen ardından "sözcük sırasını kaybediyoruz" diye düzeltti. Doğrusu: Bu gösterimde sözcük sırası kaybolur.

Avantajları ise şunlardır:

- Gösterim son derece basittir.
- Depolama ve erişim (storage and retrieval) için verimlidir.
- Basit olduğu için kelime torbası kullanan bilgi erişimi modelleri genellikle iyi sonuç verir. Ancak motorların çok daha iyi çalışması için bazı ek iyileştirmelere ihtiyaç duyar.

### 14.3 Vektör Gösterimi

Kelime torbası gösterimi kullanılırken bu gösterimi belirten bir sayı vektörü de oluşturulabilir. Hoca slayttaki örnekte, cümledeki her sözcük için bir sözcük dağarcığı uzayı (vocabulary space) oluşturduğunu anlattı. Bu, belgelerde geçen bütün sözcüklerin uzayıdır ve vektörün sütunlarını oluşturur. Sözcük cümlede varsa 1, yoksa 0 yazılır. Sözcük birden fazla geçiyorsa, örneğin iki kez, 2 yazılır.

Aynı gösterim ikinci bir cümle için de kullanılabilir. Yani iki farklı cümle varsa, ikisinden birlikte tek bir sözcük dağarcığı uzayı oluşturulur. Sonra her sözcüğün her cümlede kaç kez geçtiğine bakılır ve ilgili yere o sayı yazılır. Böylece her cümle bir sayı vektörüyle temsil edilir. Bu vektörleri kullanmak işimizi biraz kolaylaştırır.

<!-- BELİRSİZ: Slayttaki ikinci örnek cümle ve vektörlerin tam değerleri altyazıda geçmiyor. -->

## 15. Sık Karıştırılan Temel Terimler

Hoca ders boyunca kullanılacak ve sık karıştırılan bazı terimleri açıkladı.

### 15.1 Internet ve Web

Birçok kişi bu iki sözcüğü ayırt etmez, ama farklıdırlar. Internet, sunucuların birbiriyle, dizüstü bilgisayarlarımızın ve telefonlarımızın birbiriyle iletişim kurması için kullandığımız altyapıdır. Web ise internetin üzerindeki bir yazılım katmanıdır. Altında bir internet ağı olmadan web çalışamaz. Web, birbirine bağlantı veren çok sayıda web sayfasından oluşur. Bu sayfalar dünyanın farklı yerlerindeki uygulama sunucularında durur. Internet, web'in altındaki fiziksel ağı sağlar. Internet'i web'i kullanmamızı sağlayan ağ teknolojisi olarak düşünebiliriz.

### 15.2 Link ve Hyperlink

Link, bir sayfadan diğerine gitmek için kullandığımız URL'dir. Hoca ekranda bir örnek gösterdi. URL, yani link, bağlantının açık hâlidir; tarayıcının adres kısmına yazılarak bir HTTP isteği yapılabilir. Hyperlink ise ekranda yalnızca bir metin olarak görünür, ama tıklanabilir bir metindir. Tıklarsanız sizi bir yerden başka bir yere götürür. Link metnin arkasındadır. Yani gerçek bağlantı ile hyperlink arasında fark vardır.

### 15.3 Diğer Terimler

- **Hypertext ve hypermedia:** İkisi aynı şeydir. Tıkladığınızda sizi başka bir yere götüren bir metin (hypertext) ya da çoklu ortam öğesi (hypermedia) olabilir.
- **HTTP ve HTML:** HTTP iletişim protokolüdür. HTML ise tarayıcıların görüntüleyip içeriği bize gösterdiği hiper metindir.
- **URL:** Az önce gösterilen, bir kaynağın adresidir.
- **Anchor text:** Bir hyperlink'in, yani tıklanabilir bir URL'nin üzerinde görünen metindir. Hocanın ekrandaki örneğinde tıklanabilir metin "master chief" içeriğiydi.

## 16. Bir Arama Motoru Nasıl Çalışır?

Derste büyük arama motorlarının nasıl çalıştığı konuşulacak: veriyi nasıl taradıkları, aramalara nasıl cevap verdikleri, çok sayıda kullanıcıya nasıl ölçeklendikleri. Tarayıcılara (crawler) odaklanan bir bölüm de olacak.

### 16.1 Arama Bir Tablo Üzerinde Yapılır

Bir anahtar sözcük girip arama yaptığınızda arama sonuçlarını görürsünüz. Ama bu arama gerçek web sayfaları üzerinde değil, ters indeks (inverted index) üzerinde yapılır. Yani arayabildiğiniz bütün web sayfaları önceden taranmış, yerel merkezî bir depoya (repository) indirilmiş ve bir tabloya indekslenmiştir. Arama yaptığınızda bu tablo üzerinde arama yaparsınız.

> **Hocanın vurgusu:** Arama, web sayfalarının kendisinde değil, önceden taranıp oluşturulmuş ters indeks tablosunda yapılır.

> **Ek bilgi (derste anlatılmadı):** Ters indeks, her sözcükten o sözcüğün geçtiği belgelerin listesine giden bir eşlemedir. "Ters" denmesinin sebebi, belgeden sözcüklere giden doğal gösterimin tersine, sözcükten belgelere gitmesidir. Böylece bir sorgu sözcüğü için bütün belgeleri taramak yerine yalnızca o sözcüğün listesine bakmak yeterli olur.

Hoca yıllar önceki bir Google ekranını gösterdi. Bugünkü sürümden farklıydı: Sonuçların altında "Cached" ve "Similar pages" bağlantıları vardı. Google'ın önceki sürümlerinde bir sitenin önbellekteki (cache) önceki sürümünü ve ona benzer sayfaları görebiliyordunuz. Ama arama motorları kendilerini geliştiriyor ve işlevlerini pazara ve müşterilerinin isteklerine göre değiştiriyor.

### 16.2 Tarayıcı (Crawler)

Farklı dağıtık HTTP sunucularındaki bütün içeriği indirmek için tarayıcı kullanılır. Tarayıcı şöyle çalışır: Birkaç sayfa indirilir. Bu sayfalardan diğer bağlantılar çıkarılır. Sonra tarayıcı başka HTTP sunucularına erişip başka belgeler indirir, o belgelerden de bağlantıları çıkarır ve başka HTTP sunucularına gider. Arama motorları web'i temelde böyle, bir sayfadan diğerine atlayarak tarar. Bütün sayfalar indirildikten sonra bir ters indeks, bir katalog oluşturulur ve arama bu katalog üzerinde yapılır.

Her arama motorunun kendi tarayıcısı vardır. Google'ın tarayıcısının adı Googlebot'tur. Hoca Bing'in tarayıcısını MSNBot olarak andı. Bu tarayıcıların hepsi web'i her gün tarar.

> **Ders sonrası not:** MSNBot, Bing'in tarayıcısının eski adıdır. Bugünkü adı büyük olasılıkla Bingbot'tur.

Hoca bütün internetin bant genişliği düşünüldüğünde, toplam bant genişliğinin yüzde 60'tan fazlasının arama motorlarınca kullanıldığını düşündüğünü söyledi. Gerekçesi, arama motorlarının web'i sürekli taraması ve kullanıcıların bu motorların indeksinde sürekli arama yapmasıydı.

> **Ders sonrası not:** Hoca bunu "sanırım" diyerek söyledi. Bu oran büyük olasılıkla güncel trafik ölçümleriyle desteklenmiyor; internet trafiğinin büyük kısmını bugün büyük olasılıkla video akışı oluşturuyor.

### 16.3 Metin ve Bağlantı Analizi, Sorgu

Tarayıcı web'i dolaşıp sayfaları indirdikten sonra bu sayfalar üzerinde metin ve bağlantı analizi yapılır. Ters indeks oluşturulur. Ayrıca bağlantı analizi yapılarak, web sayfasının popülerliğine dayalı bir sıralama mekanizması oluşturulur. Derste PageRank, bağlantı analizi ve ters indeksin nasıl kurulduğu konuşulacak.

Ters indeks oluşturulduktan sonra bir anahtar sözcük girdiğinizde arama motoru şunları yapar:

1. Anahtar sözcüğü alır ve indeks tablosuna bakar.
2. İndeks tablosunda o sözcüğe karşılık gelen kayıttan sonuçları bulur.
3. Sonuçları, PageRank veritabanından gelen popülerlik bilgisine göre yeniden sıralar (re-rank).
4. Yeniden sıralanmış sonuçlar arama sonuçları sayfasında gösterilir.

## 17. Sosyal Ağlar ve Bu Dersi Neden Almalı?

Derste sosyal ağlar da konuşulacak: Facebook, Twitter, Instagram gibi sosyal ağların nasıl çalıştığı. Sosyal medya ve sosyal ağ ölçütleri (social network metrics) de işlenecek; örneğin sosyal medyadaki bir aktörü diğer aktörlerden daha önemli yapan şeyin ne olduğu.

Hoca son olarak "Bilgi erişimi ve web arama motorlarını neden bilmeliyim, bu dersi neden almalıyım?" sorusunu kendisi sordu ve cevapladı:

- Bölümden mezun olduğunuzda, bugün işletmelerin çoğunun yapısız bilgi kullandığını göreceksiniz. İlişkisel veritabanında kullanılan veri artık bütün verinin küçük bir yüzdesidir. Bu yüzden çalışacağınız işlerde öyle ya da böyle bilgi erişimi motorları kullanacaksınız.
- Bugün arama optimizasyonu, arama motoru optimizasyonu (search engine optimization) ve sosyal ağ optimizasyonu yapmaya çalışan çok sayıda iş var. Bilgisayar mühendisleri ve bilgisayar bilimciler şu anda bu alanlarla ilgili sorunlarla uğraşıyor.

> **Ek bilgi (derste anlatılmadı):** Arama motoru optimizasyonu (SEO), bir sayfanın arama sonuçlarında daha üst sıralarda görünmesi için içeriğini, yapısını ve aldığı bağlantıları düzenleme işidir. Bölüm 11'deki spam sayfalar bu işin kötüye kullanılan ucudur; arama motorlarının sıralama yöntemleri bu yüzden hem içerik hem bağlantı analizine dayanır.

## 18. Sonraki Konular

Hoca bu dersin konularını toparladı: Giriş yapıldı ve ders boyunca öğrencilerden beklentiler anlatıldı. Sonraki dersten itibaren kitabın 2. bölümüyle başlanacak: web verisi üzerinde ilişkilendirme kuralı madenciliği (association rule mining) ve sıralı örüntü madenciliği (sequential pattern mining). Ardından bazı makine öğrenmesi teknikleri, yani gözetimli öğrenme (supervised learning) ve gözetimsiz öğrenme (unsupervised learning) hatırlatılacak. Hoca buraya çok zaman ayırmayacağını, ama bu tekniklerin ne olduğunu hatırlatması gerektiğini söyledi. Sonra bilgi erişiminden başlayarak web madenciliğinin zor konularına geçilecek.

Ders sonunda bir öğrenci, web madenciliğiyle ilgili yalnızca slaytların mı anlatılacağını, yoksa kod ve algoritma da gösterilip gösterilmeyeceğini sordu. Hoca konunun teorisinin de konuşulacağını, uygulama örneklerinin de yapılacağını söyledi.

<!-- BELİRSİZ: Altyazıda "chapter two, which is not here" geçiyor; ilişkilendirme kuralı madenciliği bölümünün izlencedeki listede yer almadığı kastediliyor olabilir. -->

## Örnek Sorular

**1. (derste sözlü, 00:45:33)** Anlamsal veriye (semantic data) bir örnek verebilir misiniz?

Hocanın cevabı: Bir OWL dosyasında Professor kaynağı, Faculty, Employee ve Person kategorileriyle bir taksonomi oluşturur ($\text{Professor} \rightarrow \text{Faculty} \rightarrow \text{Employee} \rightarrow \text{Person}$). Profesöre "bir organizasyonda çalışır" ve "bir dersi öğretir" gibi kısıtlar tanımlanır. Bu şablona göre doldurulmuş veriden bir anlamsal ajan, HTML'i ayrıştırmadan ve doğal dil işleme kullanmadan, kişinin hangi dersleri hangi saatlerde verdiğini ve ofis saatlerini çıkarabilir (ayrıntı için Bölüm 6.5).

**2. (derste sözlü, 00:32:11)** Veri kaynaklarını karşılaştırırken "adversarial" açısından bakmak ne demektir? Hangi kaynakta yüksek, hangisinde düşüktür?

Hocanın cevabı: Web'de yüksek, intranet, e-posta ve diskte düşüktür. Çünkü kişisel kaynaklarda yalnızca ilgilendiğiniz türden veriyi tutarsınız; web'de ise veri herkesten gelir.

> **Çözüm (derste verilmedi):** Hoca terimi "çeşitlilik" diye çevirdi; doğru karşılık "düşmanca" ya da "hasmane"dir. Kastedilen, içeriğin bir kısmının arama sonuçlarını ya da kullanıcıyı yanıltmak için kasıtlı üretilmesidir; web'deki spam sayfalar buna örnektir (Bölüm 11.2).

**3. (derste sözlü, 01:45:11)** Bilgi erişimi ve web arama motorlarını neden bilmeliyim?

Hocanın cevabı: İşletmelerdeki verinin çoğu artık yapısızdır ve ilişkisel veritabanındaki veri bütün verinin küçük bir kısmıdır; bu yüzden işte bilgi erişimi motorları kullanılacaktır. Ayrıca arama motoru optimizasyonu ve sosyal ağ optimizasyonu gibi alanlarda bu konularla uğraşan çok sayıda iş vardır.

## Dersin Toparlaması

Bu giriş dersinde önce üzerinde çalışılacak verinin doğası görüldü: Web verisi yapısız, yarı yapılı, hiper metin ve dağıtık bir veridir ve ilişkisel veritabanı verisinden farklıdır. Web'in 1990'da CERN'de doğuşu ve 1993'te Mosaic ile yaygınlaşması, 2000 tarihli papyon yapısı, veri kaynaklarının karmaşıklık, hacim, gizlilik ve düşmanca içerik açısından karşılaştırılması ile statik, dinamik, gizli ve anlamsal web ayrımı anlatıldı. Kalabalıkların bilgeliği Flickr etiketleri, Flickr konum haritası ve Google Trends ile örneklendi. Veri, enformasyon, bilgi ve bilgelik basamakları arama sonuçları üzerinden tanımlandı.

İkinci oturumda bilgi erişiminin temelleri öne çıktı: bir bilgi erişimi modelinin dört bileşeni, Boolean ve vektör uzayı modellerinin derste işleneceği, recall ve precision tanımları ve web'de neden precision@10'un kullanıldığı, çeşitliliğin önemi, kelime torbası gösterimi ve vektöre dönüştürülmesi. Son olarak bir arama motorunun genel mimarisi (tarayıcı, ters indeks, PageRank ile yeniden sıralama) gösterildi. Sonraki derste kitabın 2. bölümü olan ilişkilendirme kuralı madenciliği ve sıralı örüntü madenciliğine, ardından gözetimli ve gözetimsiz öğrenmenin kısa bir hatırlatmasına geçilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
