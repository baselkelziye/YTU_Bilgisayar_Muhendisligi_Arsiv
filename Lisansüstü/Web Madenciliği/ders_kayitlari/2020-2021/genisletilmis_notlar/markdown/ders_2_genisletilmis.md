# Ders 2 Genişletilmiş Notu: Web Verisi, Bilgi Erişimi ve Değerlendirme Ölçütleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Kapsamı ve Kaynağı
- 2. Web'in Kısa Tarihi
- 3. Web'in Papyon Yapısı
- 4. Web Verisini Diğer Veri Türleriyle Karşılaştırmak
- 5. Erişilebilirliğe Göre Web Türleri
- 6. Web'in Büyüklüğü
- 7. Neden Web Madenciliği? Kalabalığın Bilgeliği
- 8. Veri Çekme ve Bilgi Erişimi
- 9. Ham Veriden Bilgeliğe
- 10. Web'de Bilgi Erişiminin Zorlukları
- 11. Arama Motorunun Arka Planı: Tarayıcı, Ters İndeks, TF-IDF
- 12. Bilgi Erişim Modelleri
- 13. Başarı Ölçütleri: Precision ve Recall
- 14. Çeşitlilik
- 15. Doküman Gösterimi: Kelime Torbası
- 16. İnternet ve Web Farkı
- 17. Karıştırılan Kavramlar

## 1. Dersin Kapsamı ve Kaynağı

Hoca kendini tanıtırken çalışma alanlarını büyük veri işleme ve analizi, bulut bilişim, web madenciliği (web mining), ölçeklenebilir makine öğrenmesi algoritmaları ve yazılım mühendisliği olarak saydı. Ders bir kitabı takip ediyor: Bing Liu'nun "Web Data Mining" kitabı. Kitabın PDF'i internette bulunabiliyor. Yazarın hazırladığı slaytlar da internette var. Dolayısıyla dersteki içerik kitaptan da izlenebilir.

### 1.1 Üzerinde Çalışılacak Veri

Bu dersin verisi web verisidir. Hoca bu veriyi dört özellikle niteledi: yapısız (unstructured), yarı yapılı (semi-structured), hipermetin yapısında (hypertextual) ve dağıtık ortamda konuşlanmış. Bu veri üzerinde sorulacak sorular dersin de omurgasıdır:

- Bu veri internetten kendi bilgisayarımıza nasıl indirilir?
- İndirilen veri nasıl indekslenir?
- Üzerinde arama yapılmak istenirse sonuçlar önem derecesine göre nasıl sıralanır (ranking)?
- Arama motorları, girilen birkaç kelimeden kafamızdaki şeyi nasıl anlamaya çalışıp istediğimiz sayfaları buluyor?
- Elde edilen sayfalarda metin madenciliği (text mining) nasıl yapılır? Kelimeler ve kelime grupları hakkında istatistiksel bilgi nasıl çıkarılır?
- Bir sayfanın içeriğine bakarak duygu analizi yapılabilir mi?

### 1.2 Hipermetin ve Link Analizi

Hoca, çalışılan verinin normal metinden farkını şöyle açıkladı: Normal metinden farklı olarak bir metin başka bir metni işaret eder. Yani aralarında bir link vardır. Böyle olunca bu veriye hipermetin (hypertext) verisi denir.

Bu türden veriler bir araya getirildiğinde bir graf oluşur. Her metin başka metinleri işaret ettiği için yönlü (directed) linklerden oluşan bir ağ ortaya çıkar. Bu ağ üzerinde link analizi (link analysis) yapılabilir. Link analiziyle sayfalar içinde en önemli olanlar bulunabilir ve bunlardan yola çıkarak çeşitli metrikler oluşturulabilir. Hocanın örneği, herkesin duyduğu PageRank metriğiydi. Bunun nasıl çalıştığı derste ayrıca konuşulacak.

### 1.3 Makine Öğrenmesi ve Sosyal Ağ Analizi

Derste makine öğrenmesi tekniklerinin web verisi üzerinde kullanımı işlenecek. Bu yüzden bu tekniklerin bilinmesi gerekiyor. Ancak temel teknikler yalnızca dersin başında, giriş düzeyinde hatırlatılacak. Amaç, bir makine öğrenmesi dersi kadar derine inmek değil, bu tekniklerin web verisine nasıl ve hangi uygulamalarda uygulandığını göstermektir.

Kapsamdaki bir başka konu sosyal ağ analizidir (social network analysis). Facebook, LinkedIn, Instagram veya Twitter gibi ortamlarda insanlar birbirini takip eder. Her takip, iki kişi arasında sembolik bir link demektir. Bu ağlar üzerinde analizlerin nasıl yapıldığı ve bunlarla ilgili metrikler de derste konuşulacak.

## 2. Web'in Kısa Tarihi

Hoca, çalışılan veriyi tanımak için önce bu verinin oluştuğu ortamı tanımak gerektiğini söyledi ve web'in tarihine kısaca değindi.

Web'in ilk sürümü 1990'da ortaya çıktı. Bu çok basit bir sürümdü. O yıl CERN'de araştırmacı olan Tim Berners-Lee, dahil olduğu araştırma grubunda bilgi paylaşımı için dağıtık bir uygulama geliştirdi. Bunun için basit bir HTTP web sunucusu yazdı. Yaptığı şey, bir işaretleme dili (markup language) olan HTML'in çok basit bir sürümünü, bir aktarım protokolü kullanarak istemciden (client) sunucuya göndermekti. Grubun diğer üyeleri de sunucuya gönderilmiş bu bilgiye ulaşabiliyordu. Bütün bunlar projenin bilgi paylaşımı ihtiyacından doğmuştu. Hoca, uygulamanın tamamen komut satırı (command line) üzerinden çalıştığını söyledi.

> **Ders sonrası not:** Hoca uygulamanın tamamen komut satırından çalıştığını ve ilk tarayıcıların 1992-93'te yazıldığını söyledi; doğrusu büyük olasılıkla Berners-Lee'nin 1990'da grafik arayüzlü bir tarayıcı-düzenleyici de yazmış olmasıdır. Komut satırı tarayıcısı da büyük olasılıkla biraz daha sonra geliştirilmiştir.

Web'in gerçek anlamda kullanımı ise tarayıcıların (browser) yazılmasıyla başladı. Tarayıcı, HTML denen hipermetin verisini işleyip (render) ekranda okunur biçimde gösteren uygulamadır. Hocaya göre farklı tarayıcılar 1992 ve 1993'te yazıldı, ama yaygın kullanımı sağlayan örnek 1993'te NCSA'da geliştirilen Mosaic oldu. Mosaic'in kullanıcı arayüzüyle hipermetin verisi görüntülenebiliyordu. Tarayıcı, HTTP protokolüyle sunucudan hipermetin verisi istiyor, sunucudan aldığı HTML'i de işleyip gösteriyordu.

1993'ten 2000'e kadar geçen yaklaşık 7 yılda çok sayıda kurum ve birim verisini web'de paylaşmaya başladı. Bu paylaşımın önemli bir özelliği vardır: İnsanlar merkezi bir kontrolden bağımsız olarak birbirlerinin sayfalarına link verir. Tamamen otonom bir şekilde, kimsenin zorlaması olmadan, istediğiniz sayfalara link vererek kendi sayfanızı oluşturursunuz. Web'in graf yapısı işte bu şekilde kendiliğinden oluşur.

## 3. Web'in Papyon Yapısı

2000 yılında yapılan bir çalışmada web'in o anki verisinin resmi çekilmiş, sayfaların birbirine link verme şekline bakılmış ve bu yapı bir papyona (bow-tie) benzetilmiştir.

<!-- BELİRSİZ: Çalışmayı yapanların adı altyazıda bozuk ("Guleme ve Latepi"). Büyük olasılıkla Broder ve arkadaşlarının 2000 tarihli "Graph Structure in the Web" makalesidir; kareden doğrulanmadı. -->

Yapının parçaları şunlardır:

- **Çekirdek (core):** Papyonun tam ortası. Birbirine çok fazla link vermiş, birbiriyle çok bağlı (highly connected) sayfa grubu. Slaytta bu grup için 56 milyon yazıyordu.
- **IN:** Sol taraftaki grup. Link veren ama link almayan sayfalar. Çekirdek tarafındaki sayfalara link vermişler, dışarıdan link almamışlar.
- **OUT:** Diğer taraftaki grup. Link alan ama dışarıya link vermeyen sayfalar.
- **Kopuk bileşenler (disconnected components):** Kendi içinde birbirine link vermiş, dış dünyaya link vermemiş sayfa grupları. Hoca bunları izole adalara (isolated islands) benzetti. Bunlar genellikle kendi içlerinde birbirine link veren intranetlerdir.
- **Tendrils:** Bunlar da kopuk bileşenler gibi ana yapıya bağlanmayan sayfalardır. Tek farkları şudur: Dışarıya link veriyorlarsa yalnızca OUT bölümündeki sayfalara verirler. Link alıyorlarsa yalnızca IN bölümündeki sayfalardan alırlar.

Hoca, 2000'den 2020'ye gelindiğinde bu yapının değişmediğini vurguladı. Ortada çok bağlı bir çekirdek, bir yanında yalnız link veren sayfalar, öbür yanında yalnız link alan sayfalar hâlâ vardır.

> **Ders sonrası not:** Hoca IN sayfalarını "link almayan", OUT sayfalarını "link vermeyen" diye tanımladı; doğrusu büyük olasılıkla bunun çekirdeğe göre geçerli olmasıdır. IN sayfaları çekirdekten link almaz, OUT sayfaları çekirdeğe link vermez. Kendi aralarında linkleşmeleri bu tanımı bozmaz.

> **Ek bilgi (derste anlatılmadı):** Graf teorisinde bu çekirdeğe güçlü bağlı bileşen (strongly connected component) denir. Böyle bir bileşendeki her sayfadan diğer her sayfaya, linkleri izleyerek gidilebilir. IN'den çekirdeğe gidilebilir ama çekirdekten IN'e dönülemez. OUT'ta ise durum tersidir.

## 4. Web Verisini Diğer Veri Türleriyle Karşılaştırmak

Hoca, web verisinin özelliklerini görmek için farklı veri türlerini aynı şekil üzerinde karşılaştıran bir slayt gösterdi. Karşılaştırılan türler şunlardı: e-posta verisi, dijital kütüphane, kişisel bilgisayarınızın diskindeki veri, çalıştığınız kurumun intranet verisi ve web verisi. Karşılaştırma dört açıdan yapıldı.

- **Büyüklük:** Sıralamanın alt ucunda e-posta verisi, üst ucunda web verisi vardır. Hoca, diskin kapasitesini 100 GB'ler, artık terabayt mertebesinde diye örnekledi. Web verisi ise bunlardan ölçek olarak çok farklı bir yerdedir.
- **Karmaşıklık (complexity):** En düşük karmaşıklık, e-posta uygulamanızın tuttuğu e-postalardadır. En yüksek karmaşıklık ise CRM ve ERP gibi eski (legacy) uygulamaların çalıştığı intranet verisindedir.
- **Mahremiyet (privacy):** Web ortamındaki veriye herkes ulaşabildiği için mahremiyet en düşük burada. Kişisel e-posta, disk ve intranet tarafına indikçe mahremiyet artar.
- **Çelişkili bilgi (adversarial):** Web'de herkes bilgi paylaştığı için birbirine muhalif, çelişen bilgiler daha fazladır. Intranet, e-posta ve disk ortamlarında bu daha düşüktür.

<!-- BELİRSİZ: Karşılaştırma şekli yalnızca sözlü anlatılıyor. Mahremiyet ekseninde intranet, e-posta ve disk arasındaki tam sıra altyazıdan net çıkmıyor. -->

> **Ders sonrası not:** Hoca "adversarial" sözcüğünü "muhalif, birbiriyle çelişen" diye açıkladı; bilgi erişimi bağlamında büyük olasılıkla, sayfa sahiplerinin arama motorunu kasıtlı olarak yanıltmaya çalıştığı ortamı da anlatır. Dersin ilerleyen kısmındaki spam konusu bununla ilgilidir.

## 5. Erişilebilirliğe Göre Web Türleri

Hoca, web'i bir de erişilebilirlik açısından değerlendiren bir şekil gösterdi. Şekilde her tür bir "yumurta" ile çizilmişti.

### 5.1 Statik Web

Tarayıcıdaki metin kutusuna bir URL yazdığınızda karşıdaki HTTP sunucusu bu isteğe (request) karşılık ne yapacağını bilir. Karşılığında bir HTML sayfası varsa onu, bir PDF dosyası varsa onu gönderir. Yani statik URL adresinin karşılığı olan dosya değişmez. Statik web (static web), bu URL'lerin oluşturduğu web'dir.

### 5.2 Dinamik Web

Dinamik web'de (dynamic web) URL'nin ucunda bir PDF yerine bir betik (script) vardır. Hocanın saydığı örnekler CGI betiği, Java betiği ve Python betiğidir. Bu durumda isteği gönderdiğiniz anda sayfanın içeriği oluşturulur.

Hocanın örneği haber siteleridir. Aynı URL'yi girmenize rağmen bugün farklı, yarın farklı içerik görürsünüz. Çünkü orada bir betik çalışır. İstek geldiğinde bu betik farklı veritabanlarından verileri alır, bir sayfa oluşturur, sayfayı HTML'e dönüştürür ve bir HTTP yanıtı (response) içinde size gönderir.

Hem statik hem dinamik web'in birleşimi (union) genel erişime açık (public) alandır. Burası web ortamındaki herkesin ulaşabildiği içeriklerin oluşturduğu web'dir.

### 5.3 İndeksli Web

Hocaya göre statik web, indeksli alandır. İndeksli demek aranabilir demektir. Arama motoruna kelimeler girerek bu kelimeleri en iyi temsil eden sayfalara ulaşırız. Arama motorları bu sayfaları kendi indekslerinden bulur ve aramayı bu indeksler üzerinde gerçekleştirir. Bu yüzden hoca statik web'e indeksli web (indexed web) de denebileceğini söyledi.

> **Ders sonrası not:** Hoca statik web'i indeksli web ile eşitledi; doğrusu büyük olasılıkla bu eşitliğin kesin olmamasıdır. Hocanın dinamik web örneği olan haber siteleri de arama motorlarında çıkar. Yani indekslenebilirlik yalnızca statik sayfalara özgü değildir.

### 5.4 Gizli Web

Şekildeki beyaz bölge gizli web'dir (hidden web). Bu sayfalar ancak belli bir sayfanın arkasında gizlenmiştir ve yalnızca o sayfanın üzerindeki arama kutusundan aranabilir. Yani herkesin doğrudan ulaşabildiği genel web'den söz etmiyoruz.

<!-- BELİRSİZ: 00:44:14-00:44:42 arasında altyazı yok. Hocanın gizli web için verdiği örnek bu boşlukta kalmış olabilir. -->

Hoca bunun yanında karanlık web (dark web) denen ortamlardan da kısaca söz etti. Bunların tarayıcıları farklıdır ve bildiğimiz HTTP isteğinden farklı protokollerle oradaki web sunucularına ulaşırlar.

> **Ders sonrası not:** Hoca karanlık web'in HTTP'den farklı protokoller kullandığını söyledi; doğrusu büyük olasılıkla farkın Tor gibi anonim yönlendirme ağlarında olmasıdır. Sayfalar çoğu zaman yine HTTP ile, ama bu ağın üzerinden istenir.

### 5.5 Anlamsal Web

Şekildeki sarı yumurta anlamsal web'dir (semantic web). Bu dünyadaki dosyalar RDF ve OWL gibi dosyalardır. HTML'den farklıdırlar ve XML tabanlıdırlar.

Kullanım amaçları da farklıdır. Her HTML sayfası bir kurumu, bir kişiyi veya bir bilgiyi tanımlar. Anlamsal web dosyaları ise, web'e koyan kurum hakkında bazı uygulamaların çıkarım (inference) yapabilmesi için kullanılır.

Hoca çıkarımın ne demek olduğunu diş doktoru örneğiyle anlattı. Diş doktorundan randevu almak istiyorsunuz. Mahallenizde çok sayıda diş doktoru var ve hepsinin bir web sayfası var. Hepsi sayfalarına HTML'in yanı sıra bir OWL dosyası koymuş. Bu dosyada hangi günler randevu verebileceklerini belirtmişler. Cep telefonunuzda da bir anlamsal web uygulaması var. Uygulamaya "bana en yakın diş doktorundan randevu al, tarihini ve saatini bildir" diyorsunuz.

Uygulama, diş doktorlarının sitelerindeki OWL dosyalarını okur ve bunlar üzerinden çıkarım yapar. Sizin programınızla onların programının çakışıp çakışmadığını, yaptırmak istediğiniz özel tedaviyi yapıp yapmadıklarını bu dosyalardaki bilgilerden kontrol eder.

## 6. Web'in Büyüklüğü

Hoca, web'in büyüklüğü için yaygın kullanılan bir sayfayı açtı. Bu sayfa, indeksli dünyanın yani aranabilir web'in büyüklüğü hakkında sürekli bilgi paylaşıyor. O gün gördükleri değerler şunlardı:

- İndekslenmiş dünya: 5,47 milyar sayfa.
- Google indeksinden alınan bilgiye dayalı sayfa sayısı: 60 milyara yakın.

Sayfa bu değerleri Google ve Bing'in indeks bilgilerinden çıkarıyor. Ayrıca indeksin zaman içinde nasıl değiştiğini gösteriyor. Hocanın gösterdiği grafik son 3 aylık, 15 Temmuz'dan o güne kadarki dönemi kapsıyordu. Aynı şey Bing için de vardı. Farklı ülkelerin sahip olduğu sayfa sayıları da görülebiliyordu.

<!-- BELİRSİZ: Sayfanın adı altyazıda geçmiyor (büyük olasılıkla worldwidewebsize). 5,47 milyar ile 60 milyar arasındaki farkın nasıl açıklandığı da altyazıda yok. -->

## 7. Neden Web Madenciliği? Kalabalığın Bilgeliği

Buraya kadar verinin yapısına, büyüklüğüne, mahremiyetine, karmaşıklığına, çelişkili bilgi durumuna ve erişilebilirliğine bakıldı. Hoca sonra şu soruyu sordu: Bu veriyi neden çalışıyoruz, ne işimize yarayacak?

Web, günlük hayatta önemli bir bilgi kaynağıdır ve kullanmayan neredeyse kimse kalmamıştır. Bu veri işlenerek mevcut web uygulamalarının tasarımı, performansı ve doğruluğu iyileştirilebilir. Web madenciliği teknikleriyle sosyal ağ madenciliği yapılabilir. İnsanların sosyal medyada paylaştıklarından ne gibi çıkarımlar yapılabileceği öğrenilebilir. Bu nedenle web madenciliği, uygulama tarafı çok yoğun bir araştırma alanıdır.

### 7.1 Kalabalığın Bilgeliği Nedir?

Bu yaklaşıma kalabalığın bilgeliği (wisdom of crowds) deniyor. Çok sayıda insan birbirinden habersiz olarak web siteleri yaratır ve bunlar birbirine link verir. Sosyal ağlarda veri paylaşır, paylaştıklarını etiketler. Örneğin bir fotoğraf paylaşırken içindeki insanları etiketleriz. Belli bir merkezi kontrol noktasına danışmadan yapılan bütün bu paylaşımlardan bilgi çıkarılabilir. Çıkarılan bilgi de insanların hayatını kolaylaştıran uygulamalara dönüşebilir. Hoca, web madenciliğinde yaptığımız şeyin aslında bu olduğunu söyledi.

### 7.2 Örnek: Trafik Tahmini

Yandex veya Google Maps kullandığınızda GPS'iniz açıktır. Uygulama, siz trafikte giderken konumunuzu ve hızınızı merkeze sürekli gönderir. Sistem, sizin ve aynı noktadaki çok sayıda insanın gönderdiği bilgiye bakarak o yoldaki trafiği belli algoritmalarla tahmin eder. Bu çıkarımı başka insanlara iletir. Aynı şeyi sizin için de başkalarının gönderdiği bilgiyle yapar. Yani siz hem bilgi ağının katılımcısı hem de yararlanıcısısınız.

### 7.3 Örnek: Flickr'da "Jaguar" Etiketli Resimler

Flickr, insanların çektikleri resimleri etiketleyerek paylaştığı bir ortamdır. "Jaguar" etiketiyle paylaşılan resimlerin bir kısmı araba markası, bir kısmı doğada yaşayan hayvan, bir kısmı gitar markası, bir kısmı savaş uçağıdır.

Bu resimleri ayırmanın iki yolu vardır. Birincisi, hesaplama maliyeti çok yüksek görüntü işleme algoritmalarıyla sınıflandırmaktır. İkincisi, insanların resimleri etiketleriyle paylaşmasını istemektir. Çok sayıda insan etiketle paylaştığı için, bu paylaşımlardan yola çıkarak kümeleme yapılabilir. Slayttaki sonuçta ilk satırda araba, ikinci satırda hayvan, üçüncü satırda gitar, dördüncü satırda uçak kümesi güzelce ayrılmıştı. Flickr bunu tamamen etikete dayalı olarak yapmıştı. Hocaya göre görüntü işleme teknikleriyle böylesine sağlıklı ve düzenli bir kümeleme yapmak çok zordur.

### 7.4 Örnek: Turistlerin Fotoğrafları

Hocanın "sanırım Barselona" dediği bir haritada, Flickr'ın turistlerin paylaştığı resimlerden geliştirdiği bir uygulama gösterildi. Günümüzdeki telefonlar resmi GPS etiketiyle çeker. Turist resmi arkadaşlarıyla paylaşmak için Flickr'a koyduğunda, resim zaman damgası ve konumuyla birlikte haritada yerini alır. Haritadaki renkli yuvarlaklar bu resimleri gösterir.

Bu uygulamaya bakarak günün belli bir saatinde turistlerin yoğunlukla hangi noktalarda olduğu görülebilir. Buradan şöyle bir çıkarım yapılabilir: Zamanım sınırlı, nereye gideyim? İnsanlar yoğunlukla şu caddeyi tercih etmişse, oraya gidersem kısa zamanda daha fazla şey görme imkânım olur.

### 7.5 Bu Verinin Nitelikleri ve Kullanım Yerleri

Hoca, bu tür veride aranan nitelikleri de saydı. Popüler verinin peşindeyiz. Veride çeşitlilik vardır. Verinin kaliteli olmasını isteriz, bu yüzden kontrol edilmiş, özellikle enstrümante edilmiş (instrumented) uygulamalardan gelen verilerle çalışırız. Ayrıca verinin olabildiğince çok sayıda insandan gelmesini isteriz.

<!-- BELİRSİZ: 01:02:39'da altyazı "yüksek kavrışta" diyor. Büyük olasılıkla "yüksek kapsamda" (high coverage); kareden doğrulanmadı. -->

Bu bilgi en çok arama motorlarının sıralamalarında kullanılır. Hoca bilginin geldiği üç kaynak saydı:

- **Linkler:** Web'de sayfa yayımlayan yazarlardan ve editörlerden gelir.
- **Etiketler (tags):** Paylaşılan resimleri etiketleyen çok sayıda insandan gelir.
- **Sorgular (queries):** Bing veya Google'da arama yapan çok sayıda insandan gelir.

Google Trends sonuncusuna bir örnektir. Çok sayıda insanın yaptığı aramalardan yola çıkarak insanların yılın belli dönemlerinde nelere daha yoğun ilgi gösterdiğini yakalar.

## 8. Veri Çekme ve Bilgi Erişimi

Web'den bilgi çıkarırken kullanılan yöntem bilgi erişimidir (information retrieval, IR). Hoca, bunun veritabanı dünyasındaki veri çekmeden (data retrieval) farklı olduğunu slayttaki karşılaştırmayla anlattı.

Veritabanı dünyasında verinin nasıl saklanacağı iyi tanımlıdır (well-defined). Tablolar, birincil anahtarlar (primary key), yabancı anahtarlar (foreign key) ve tablolar arası ilişkiler vardır. Kolonların tipleri bellidir. Sorguların sözdizimi (syntax) de bellidir. Yani hem saklama hem de sorgulama için bütün kurallar tanımlıdır.

Bilgi erişiminde durum farklıdır. Veri, dosya sistemi üzerinde HTML, PDF veya düz metin gibi farklı tiplerde olabilir ve metin biçiminde tutulur. Ararken de belli bir sözdizimi yoktur. Yalnızca bir kelime veya kelime grubu girilir.

- **Veri çekme:** Yapılı (structured) dünya. Saklama ve sorgulama kuralları tanımlı.
- **Bilgi erişimi:** Yapısız dünya. Veri yapısız tutulur, arama da yapısız yapılır.

İki durumda da veriden bilgi çıkarılır. Fark, birinin tamamen yapılı, diğerinin tamamen yapısız dünyada çalışmasıdır. Bu yapısız dünyada aradığımız bilgiye arama sistemleriyle ulaşırız.

## 9. Ham Veriden Bilgeliğe

Bu derste ham verimiz web sayfalarıdır. Bunların en yaygın tipi HTML sayfalarıdır. Bu sayfaların oluşturduğu ortamda bilgiye ulaşmak için arama motorları (search engine) kullanırız. Arama motoru, bilgi erişimin web için bir örneğidir. Google ve Bing bunun örnekleridir. Bilgi erişimin yalnızca bir kurumun sayfaları üzerinde, intranette arama yapan tipleri de vardır.

Hoca, kavramları ayırmak için canlı bir örnek üzerinden gitti. "Information retrieval" sözcükleriyle bir arama yaptı. Karşısına gelen sonuç listesi (list of results) üzerinden şu sırayı anlattı:

- **Veri (raw data):** Buradaki her bir sayfa ham sayfadır. Anahtar kelime, bu ham sayfalardan oluşturulmuş indeks üzerinde aranır.
- **Enformasyon (information):** Arama motorunun anahtar kelimeye karşılık getirdiği sonuçların listesi. Hocanın gösterdiği örnekte ekranda 10 sonuç vardı.
- **Kavrayış (knowledge):** Hoca bu 10 sonuca teker teker girip çıktı, sayfaları okudu. Bu enformasyonu kullanıcı olarak işledi. Sonunda kafasında bilgi erişimin ne olduğuna dair bir bilgi oluştu. İşte bu knowledge'dır.
- **Bilgelik (wisdom):** Aynı knowledge'ı çok sayıda insan elde ederse bu wisdom'a dönüşür.

Hocanın özetine göre, web dünyasında HTML'lerden yola çıkarak, herkesin üzerinde hemfikir olduğu gerçeklere ulaşmak için bu sırayı izliyoruz.

> **Hocanın vurgusu:** Kavramları birbirinden ayırabilmek gerekiyor. Sonuç listesi tek başına information'dır. Kullanıcı onu işleyip öğrenince knowledge olur.

## 10. Web'de Bilgi Erişiminin Zorlukları

Google veya Bing gibi uygulamalar bilgi erişimin bir tipidir, ama web ortamı kendine özgü zorluklar getirir. Hoca üç zorluk saydı.

- **Dağıtık ve çok büyük veri:** HTML dokümanları dağıtık HTTP sunucuları üzerindedir. Hocanın az önceki sorgusu 91.600 sonuç bulmuştu ve bunların hepsi dünyanın farklı yerlerindeki sunucularda duran dosyalardı. Bu kadar veriyi toplamak ve saklamak oldukça zordur.
- **Çok sayıda eş zamanlı kullanıcı:** Dosyaları yaratan kullanıcı sayısı da, arama motorunu kullanan kullanıcı sayısı da çok fazladır. Google gibi bir uygulama yazacak olursanız veriyi toplayıp indekslemek problemin yalnızca bir kısmıdır. Çok sayıda kullanıcıya eş zamanlı olarak yüksek performansla arama yaptırmak da gerekir.
- **Spam:** İnsanlar sayfalarının sonuç listesinde üst sıralarda çıkması için onları, sayfayı temsil etmeyen kelimelerle doldurur. Bu yüzden sonuçlarda gelen sayfalar gerçekten aradığımız sayfalar olmayabilir.

## 11. Arama Motorunun Arka Planı: Tarayıcı, Ters İndeks, TF-IDF

Hoca bilgi erişim modellerine geçmek üzereyken bir öğrenci spam konusuna döndü.

**Soru:** Spam aramaları artık kalkmadı mı? Arama motorları artık anahtar kelimelere bakmıyor mu?

**Cevap:** Hâlâ anahtar kelimelere bakılıyor. Popülerliğe bakıldığı gibi anahtar kelimelere de bakılıyor. Hoca bunu göstermek için ileride işlenecek bir şekli açtı.

### 11.1 Tarayıcı (Crawler)

Şekilde bir arama motorunun arka planda kullandığı tarayıcı (crawler) görülüyordu. Tarayıcı, web'deki sayfaları arama motoru adına önceden bulup indiren, içindeki anahtar kelimeleri çıkaran ve bu kelimelere dayalı olarak sayfaları indeksleyen uygulamadır. Her arama motorunun kendine ait bir tarayıcısı vardır. Hocanın örnekleri Google için Googlebot, MSN için MSNbot'tur. Bu uygulamalar sürekli sayfa indirir. Hoca, dünya genelindeki internet bant genişliğinin en yüksek bölümünü bunların kullandığını söyledi.

> **Ders sonrası not:** Hoca bant genişliğinin en yüksek bölümünü arama motorlarının kullandığını söyledi; doğrusu büyük olasılıkla en büyük payın video akışı gibi son kullanıcı trafiğinde olmasıdır. Tarayıcılar sürekli çalışır ve önemli bir yük oluşturur, ama en büyük pay onların değildir.

### 11.2 Ters İndeks (Inverted Index)

Tarayıcı, sayfalardan çıkardığı kelimelerle bir ters indeks (inverted index) oluşturur. Hoca bunu iki kolonlu bir tablo olarak anlattı. Birinci kolon anahtar kelimelerden oluşur. İkinci kolon ise o kelimeyi içeren sayfaların bağlı listesidir (linked list). Bir sayfa o kelimeyi içeriyorsa, o sayfayı temsil eden bir liste düğümü o kelimenin satırında yer alır.

```
anahtar kelime  |  o kelimeyi içeren sayfalar (bağlı liste)
----------------+------------------------------------------
kelime          |  sayfa -> sayfa -> sayfa -> ...
```

Gerçek zamanlı arama yaparken arama ham veri üzerinde yapılmaz, indeks üzerinde yapılır. Hocanın örneğiyle, "informatics" kelimesini girdiğinizde arama motoru ters indekste bu kelimenin satırını bulur ve karşısındaki sayfa listesini alır. Bulunan sayfalar sonra PageRank denen, popülerlik tabanlı bir sıralama algoritmasıyla yeniden sıralanır. Yani sonuçları sıralayan ayrı bir modül vardır. Size bu sıralanmış sonuçlar gösterilir.

### 11.3 Meta Etiketi ve TF-IDF

Öğrenci sorusunu netleştirdi.

**Soru:** Web sayfası hazırlarken HTML'de anahtar kelime girilen bir kısım vardı. Arama motorları artık bu alana bakmıyor, kendi analizine bakıyor değil mi?

**Cevap:** Hoca, kastedilenin meta etiketi (meta tag) kısmı olduğunu belirtti. Tarayıcıların çalışması kitabın 8. bölümünde ayrıca işlenecek. Tarayıcılar sayfayı indekslerken çok farklı alanlara bakar. Bunların içinde en çok kullanılan şey TF-IDF denen skordur.

TF-IDF, bir sayfayı temsil eden anahtar kelimeleri bulurken bu kelimelerin sayfa içindeki önem değerini gösteren metriktir. Bu metriğe dayanarak sayfayı en iyi temsil eden kelime ve kelime grupları bulunur.

Kelimeler bulunurken sayfanın tümüne bakılır. Ancak yazarlar HTML'in olanaklarını kullanarak anahtar kelimeleri gövdeye (body), başlığa (header) veya farklı alanlara koyabilir. Bir kelimenin önem derecesi bulunduğu yere göre artabilir.

TF-IDF skorlarının ters indekste de görevi vardır. "Informatics" satırındaki bağlı listede birinci düğümün hangi sayfa olacağına karar verilirken bu skorlara bakılır.

Hoca, TF-IDF'nin en temel metrik olduğunu, günümüz arama motorlarının bunun çok daha gelişmiş sürümlerini kullandığını, ama temelde yine TF-IDF'nin bulunduğunu ekledi.

> **Ek bilgi (derste anlatılmadı):** Yaygın tanımda bir $t$ terimi ve $d$ dokümanı için skor $\text{tf-idf}(t,d) = \text{tf}(t,d) \cdot \log \dfrac{N}{\text{df}(t)}$ biçimindedir. Burada $\text{tf}(t,d)$ terimin dokümandaki tekrar sayısı, $N$ toplam doküman sayısı, $\text{df}(t)$ ise terimi içeren doküman sayısıdır. Yani bir kelime o dokümanda sık, koleksiyonda seyrek geçiyorsa skoru yüksek olur.

## 12. Bilgi Erişim Modelleri

Hoca kaldığı yere döndü. Bilgi erişim motorları bilgi erişim modelleri kullanır. Birden fazla model vardır. Boolean model ve vektör uzayı modeli (vector space model) bunların örnekleridir. Bunlar derste teker teker işlenecek.

Bir model şunları tanımlar:

- Girilecek sorgunun ne olacağını ve nasıl tanımlanacağını, yani sorgu dilini (query language).
- Sistemdeki dokümanların nasıl tanımlanacağını.
- Dokümanlarla sorguların nasıl eşleştirileceğini.

Slayttaki şekil bu akışı gösteriyordu:

```
dokümanlar  --> doküman gösterimi --+
                                    +--> eşleştirme algoritması --> sonuç listesi --> kullanıcı
sorgular    --> sorgu gösterimi   --+
```

Dokümanlar ve sorgular belli bir modele göre tanımlanır. Karşılaştırma (comparison) algoritması belirlenir. Sonuçta bir sonuç listesi çıkar ve son kullanıcıya gösterilir.

## 13. Başarı Ölçütleri: Precision ve Recall

Bilgi erişim sistemlerinin başarısı neye göre ölçülür? Hoca iki temel metrik verdi: kesinlik (precision) ve duyarlılık (recall). Hoca Türkçe olarak precision için "tutturma", recall için "bulma" karşılıklarını önerdi.

### 13.1 Tanımlar

Slayttaki şekilde büyük mavi çerçeveli kare, toplamdaki bütün dokümanları gösteriyor. Diyelim ki "informatics" kelimesi için arama yaptınız ve sonuçlar geldi. Şekilde iki küme var:

- $A$ (mor yumurta): Bu sorguyla gerçekten ilgili (relevant) dokümanlar.
- $B$ (yeşil yumurta): Motorun size gösterdiği, yani getirilen (retrieved) dokümanlar. Genelde ilk 10 sonuç gösterilir.

Precision, bana gösterilen sayfalar içinde kaçının doğru sayfa olduğunu ölçer:

$$\text{precision} = \frac{|A \cap B|}{|B|}$$

Recall, bana gösterilen doğru sayfaların, toplamdaki doğru sayfaların ne kadarı olduğunu ölçer:

$$\text{recall} = \frac{|A \cap B|}{|A|}$$

Hocanın sözlü örneği şuydu: Motor 10 sonuç göstermiş, 5 tanesi gerçekten doğru. Precision burada doğrudan bulunur (ara adım eklendi):

$$\text{precision} = \frac{5}{10} = 0{,}5$$

Recall için ise hoca, bu 5 sayfanın toplamdaki doğru sayfaların yüzde kaçı olduğu sorusunu sordu. Toplam verilmediği için bu örnekte recall hesaplanamaz.

### 13.2 Avuç Benzetmesi

Hoca farkı şöyle somutlaştırdı: Elimde çok sayıda doküman var ve içinden bir avuç doküman çıkarıyorum.

- **Precision:** Avucumdaki dokümanların kaçı doğru doküman?
- **Recall:** Avucuma düşen doğru dokümanlar, toplamdaki doğru dokümanların ne kadarı?

> **Ek bilgi (derste anlatılmadı):** İki ölçüt genellikle birlikte değerlendirilir, çünkü tek başına biri yanıltabilir. Motor bütün dokümanları getirirse recall en yüksek değerini alır, ama precision düşer. Çok az ve emin olduğu sonucu getirirse precision yükselebilir, ama recall düşer.

### 13.3 Web'de Recall Neden Hesaplanamaz?

Hoca olası itirazı kendisi dile getirdi: Web'de toplam kaç doğru doküman olduğunu bilmiyorum ki. Precision'ı bilebilirim. Bana gösterilen 10 dokümana gözle bakar, kaçının ilgilendiğim konuyla ilgili olduğunu görürüm. Ama recall'ı nasıl hesaplayacağım?

> **Hocanın vurgusu:** Bu yüzden web ortamında bilgi erişimin başarısını ölçmede ağırlıklı olarak kullanılan metrik precision'dır. Recall daha çok, toplamdaki doğru sayfa sayısının bilindiği kontrollü veri kümelerinde ek olarak kullanılır.

### 13.4 Jaguar Örneği

**Soru:** Az önceki jaguar örneğini düşünelim. Araba markası da var, hayvan da var. Benim aradığım ise hayvan. Buna göre bir yüzde çıkarılabilir mi?

**Cevap:** Jaguar sözcüğünü girdiniz ve size 10 resim geldi. Resimleri incelediniz. Bunların 3 tanesi doğadaki vahşi hayvan jaguar, yani aradığınız şey.

- Verilen: $|B| = 10$, $|A \cap B| = 3$.
- Precision: $\dfrac{|A \cap B|}{|B|} = \dfrac{3}{10} = 0{,}3$.
- Recall: $\dfrac{3}{|A|}$. Burada $|A|$, veritabanındaki toplam vahşi hayvan resmi sayısıdır. Bu biliniyorsa recall hesaplanabilir. Bilinmiyorsa hesaplamak imkânsızdır.

### 13.5 İlk $k$ Sonuçta Precision

Arama motorlarını değerlendirirken kullanılan precision'ın farklı tipleri vardır: ilk 10'da, ilk 20'de, ilk 30'da precision. Kapsamlı bir karşılaştırma analizi yapıyorsanız bunların hepsini denemeniz gerekir. Yaygın kullanılan ise ilk 10 sonuçtaki precision'dır (precision at 10). Jaguar örneğindeki $3/10$ değeri de ilk 10 resim üzerinden hesaplanmıştır.

## 14. Çeşitlilik

Günümüzde arama motorlarının başarısı yalnızca aranan bilgiyi doğru getirmekle ölçülmüyor. Başka ölçütlere de yanıt vermesi gerekiyor. Bunlardan biri çeşitliliktir (diversity).

Diyelim ki "informatics" sorgusu için 10 sonuç geldi. Bu 10 sonucun aynı alan adındaki (domain) sayfalardan gelmesini istemeyiz. Böyle olursa arama motoru o alan adının bakış açısını bize dayatmış olur.

Slayttaki örnekte Google'a bir kelime grubu girilmiş ve gelen sonuçların hepsi aynı alan adından gelmişti. Hoca, sayfalar aradığımız şeyle ilgili olsa bile bunun arama motorunun başarılı olduğunu göstermediğini söyledi. İlk 10 sonuç hem doğru hem de çeşitli olmalıdır.

<!-- BELİRSİZ: Slayttaki sorgu altyazıda bozuk geçiyor ("Christopher Jagmin Plates"). Sorgunun aslı ve sonuçların geldiği alan adı anlaşılmıyor. -->

## 15. Doküman Gösterimi: Kelime Torbası

Modellerin her biri dokümanları ve sorguları farklı şekilde tanımlar. Hoca bir tanımlama yöntemi gösterdi. Bir doküman, içindeki kelimelerle tanımlanabilir. Bu gösterim modeline kelime torbası (bag of words) denir. Kelimeler yan yana konularak bir vektöre dönüştürülür ve bu vektör dokümanı tanımlar.

### 15.1 Örnek Cümle

Slayttaki cümle şuydu: "That's one small step for a man, a giant leap for mankind."

Hoca, cümledeki kelimeleri teker teker aldığını, birden fazla geçenleri tek olarak yazıp yanına sayısını eklediğini anlattı. Cümleden çıkan sonuç şudur (ara adım eklendi):

| Kelime | Tekrar | Kelime | Tekrar |
|:-------|-------:|:-------|-------:|
| that's | 1 | man | 1 |
| one | 1 | giant | 1 |
| small | 1 | leap | 1 |
| step | 1 | mankind | 1 |
| for | 2 | a | 2 |

Cümlede 12 kelime geçer. Bunların 10'u farklıdır. Yalnızca "for" ve "a" ikişer kez geçer.

<!-- BELİRSİZ: Slayttaki tablo altyazıda okunmuyor. Yukarıdaki tablo, hocanın anlattığı yöntem cümleye uygulanarak kuruldu; slaytta kelime sırası veya yazımı farklı olabilir. -->

### 15.2 Dezavantajlar ve Avantajlar

Her doküman tanımlama yönteminin avantajları ve dezavantajları vardır. Bu yöntemin dezavantajları şunlardır:

- **Kelime sırası kaybolur (word order gets lost).** Cümledeki kelimelerin yerleri ve sıraları bu gösterimde yoktur.
- **Çok farklı dokümanlar benzer gösterime sahip olabilir (very different documents could have similar representations).**
- **Doküman yapısı ve üst veri yok sayılır (document structure and metadata is ignored).** Bu cümle bir HTML içinde olsaydı bazı kısımları kalın (bold), bazıları italik olabilirdi. Yazar farklı kelimelere farklı önem vermiş olabilirdi. Bu gösterim bunu yakalayamaz, her kelimeyi aynı öneme sahipmiş gibi ifade eder.

> **Ders sonrası not:** Hoca bu maddeleri okurken "avantajları" dedi; doğrusu bunların dezavantaj olmasıdır. Hoca avantajları hemen ardından ayrıca saydı.

Avantajları ise şunlardır:

- Kelime torbası kullanan bilgi erişim modelleri anlamlı sonuçlar verir.
- Doküman çok daha küçük bir alan kullanılarak tanımlanabilir.
- Kolay bir tanımlama yöntemidir.

Hoca bunların daha ayrıntılı görüleceğini söyledi.

### 15.3 Vektör Olarak Gösterim

Aynı doküman 0 ve 1'lerden oluşan bir vektörle de ifade edilebilir. Bu gösterimde dokümanlarda bulunabilecek bütün kelimeler bir indekse oturtulur. Vektörün her elemanı, indeksteki ilgili kelime dokümanda varsa 1, yoksa 0 olur:

$$d = (x_1, x_2, \dots, x_n), \qquad x_i \in \{0, 1\}$$

Hoca, 0 ve 1 yerine kelimenin tekrar sayısının da yazılabileceğini ekledi. Bu durumda $x_i$, indeksteki $i$. kelimenin dokümandaki tekrar sayısı olur. Örnek cümlede "for" ve "a" için ilk gösterimde 1, ikinci gösterimde 2 yazılır (ara adım eklendi). Demek ki aynı kelime torbası modelini kullanan farklı tanımlama yöntemleri vardır.

## 16. İnternet ve Web Farkı

Hoca, web üzerinde sıkça karıştırılan kavramlar olduğunu söyledi: internet, web, link, hyperlink, hypertext, hypermedia, HTTP, HTML, anchor text, URL. İlk olarak internet ile web'i sınıfa sordu.

**Soru:** İnterneti ve web'i birbirinden nasıl ayırırız?

**Öğrenci cevapları:** Birinci cevap: İnternet "ağların ağıdır" (network of networks), web ise bir bilgi koleksiyonudur (information collection). İnternet altyapı, web servistir. İkinci cevap: Ulaşmak istediğimiz hedef web'dir, bunu sağlayan internettir.

**Cevap:** Hoca her iki cevabın da çoğunlukla doğru olduğunu ama eksikleri bulunduğunu söyledi. Altyapıda kullanılan ağ altyapısı internettir. Web ise kendi içinde ağ yapısı olan bir veri kümesidir. İçinde birbirine link veren hipermetin dokümanları vardır. Hoca bu sayfalara gömülü linklere "soft link" de denebileceğini söyledi. İnternet ise dağıtık sunuculardaki bu dokümanlara insanların fiziksel ağ ile ulaşmasını sağlayan altyapıdır.

Kısacası:

- **İnternet:** Ağ katmanı (network layer).
- **Web:** Bu ağın üzerindeki doküman ağı. Yazılım ve veri katmanı.

Web'in çalışması için gereken yazılım kümesinde hocanın saydıkları şunlardır: HTTP sunucuları, tarayıcılar, DNS sunucuları, gelen istekleri yönlendiren ve artık yazılımdan oluşan sanal anahtarlar (switch) ve arama uygulamaları. Arama motorlarıyla, internet üzerinde konuşlanmış bu dağıtık dosyalarda aradığımızı buluruz.

> **Ders sonrası not:** Hoca web sayfalarının "farklı DNS sunucuları üzerinde" tutulduğunu ve anahtarların istekleri DNS sunucularına aktardığını söyledi; dersin önceki kısmında kendisi de dağıtık HTTP sunucularından söz etmişti. Doğrusu büyük olasılıkla sayfaların HTTP sunucularında tutulması ve isteklerin bu sunuculara yönlendirilmesidir. DNS sunucuları alan adlarını IP adreslerine çevirir.

## 17. Karıştırılan Kavramlar

Hoca kalan kavramları teker teker açıkladı.

- **Hyperlink:** Metne gömülmüş ve arka planda bir URL ile eşleştirilmiş bağlantı. Son kullanıcı orada bir metin görür. Metne bastığında tarayıcı onu karşılık gelen URL'ye yönlendirir.
- **Link:** Tarayıcıya girildiğinde tarayıcının tanıdığı ve ilgili HTTP sunucusuna HTTP isteği olarak gönderdiği adres.
- **Hypertext, hypermedia:** Sayfa içindeki bir metnin veya bir çoklu ortam içeriğinin arka planda bir URL ile eşleştirilmesi.
- **HTML:** Tarayıcıların işleyip gösterdiği hipermetin.
- **HTTP:** Bir protokol. Tarayıcılar bir HTTP sunucusundan HTML dokümanını bu protokolle ister.
- **URL:** Hocaya göre link ile aynı şeydir. Tarayıcının HTTP isteğiyle sunucudan istediği doküman için kullandığı adres.
- **Çapa metni (anchor text):** URL'ye karşılık gelen, bize görünen metin.

> **Ders sonrası not:** Hoca URL ile linkin aynı şey olduğunu söyledi; doğrusu büyük olasılıkla URL'nin adresin kendisi, linkin ise o adrese verilen gönderme olmasıdır. Günlük kullanımda ikisi sık sık eş anlamlı kullanılır.

> **Ek bilgi (derste anlatılmadı):** HTML'de hyperlink, URL ve çapa metni tek bir etikette bir arada görülür: `<a href="URL">çapa metni</a>`. Tarayıcı kullanıcıya yalnızca çapa metnini gösterir. Tıklanınca `href` içindeki URL'ye HTTP isteği gönderir.

Hoca tarayıcı konusunu az önce konuştukları için ayrıntıya girmedi.

## Dersin Toparlaması

Bu derste çalışılacak veri tanındı. Web'in tarihi, papyon yapısı ve erişilebilirliğe göre türleri görüldü. Web verisi büyüklük, karmaşıklık, mahremiyet ve çelişkili bilgi açısından diğer veri türleriyle karşılaştırıldı. Web madenciliğinin amacı kalabalığın bilgeliği örnekleriyle anlatıldı. Sonra bilgi erişimin veri çekmeden farkı, veriden bilgeliğe uzanan sıra, web'e özgü zorluklar, tarayıcı, ters indeks ve TF-IDF ele alındı. Başarı ölçütü olarak precision ve recall tanımlandı. Web'de recall bilinemediği için precision'ın, özellikle ilk 10 sonuçtaki precision'ın öne çıktığı görüldü. Doğruluğun yanında çeşitliliğin de gerektiği vurgulandı. Doküman gösterimi olarak kelime torbası incelendi.

Hocaya göre bu slayt seti, derste işlenecek konuların önemli bir kısmının özetidir. Gelecek hafta kitabın 2. bölümü işlenecek: birliktelik kuralları (association rules) ve sıralı örüntüler (sequential patterns). Bunlar, web madenciliğinde yaygın kullanılan, veriden birliktelik kuralı ve sıralı kural çıkarma teknikleridir. Hangi algoritmaların ve veri kümelerinin kullanıldığı ayrıntılı konuşulacak. Sonra kitabın bölümleri aynı sırayla izlenecek. Hocanın hedefi, dönem sonunda fikir madenciliği (opinion mining) ve duygu analizine (sentiment analysis) kadar gelmektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
