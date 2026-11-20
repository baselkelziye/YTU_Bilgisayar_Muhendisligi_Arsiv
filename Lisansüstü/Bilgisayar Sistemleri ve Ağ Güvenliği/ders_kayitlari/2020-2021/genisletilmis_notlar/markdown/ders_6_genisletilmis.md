# Ders 6 Genişletilmiş Notu: Web Güvenlik Modeli: HTTP, Çerezler ve Aynı Köken Politikası

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. İşletim Sisteminden Web'e: Neden Web Güvenliği?
- 2. Web İçin Saldırı Modelleri
- 3. HTTP Protokolü
- 4. HTTP Metotları
- 5. Kaynak Yükleme, Frame ve iFrame
- 6. JavaScript ve Document Object Model (DOM)
- 7. HTTP/2
- 8. HTTP Çerezleri ve Oturum Yönetimi
- 9. Modern Web Sitesi: Los Angeles Times Örneği
- 10. Aynı Köken Politikası (Same Origin Policy)
- 11. SOP'nin HTTP Cevaplarına, Kaynaklara ve Script'lere Uygulanışı
- 12. Domain Relaxation ve Public Suffix List
- 13. JavaScript İstekleri ve CORS
- 14. Çerezlerde Aynı Köken Politikası
- 15. Ağ Saldırganı ve Secure Çerezler

## 1. İşletim Sisteminden Web'e: Neden Web Güvenliği?

Hoca, önceki derslerde işletim sistemi tarafına bakıldığını hatırlattı: hem Unix/Linux hem Windows için güvenlik modelleri incelenmiş, ardından izolasyon (isolation), ayırma (separation) ve en az yetki ilkesi (principle of least privilege) üzerinden ilerlenmişti. Bu derste aynı şey web tarafında yapılacaktı: işletim sisteminde temel güvenlik terimleri, yaklaşımları ve bunların birbiriyle etkileşimi nasıl incelendiyse, web'deki güvenlik modeli de aynı biçimde kavramlar üzerinden ele alınacaktı. Hoca bunun hızlı ilerlenebilecek bir ders olması gerektiğini söyledi.

Slaytta dersin yol haritası görülüyordu (ekrandan, 00:05:00): "1. Systems Security" geride kalmıştı; "2. Web Security" başlığı altında sırasıyla Web Security Model, Web Vulnerabilities and Attacks, HTTPS/TLS/Certificates ve User Authentication and Session Management gelecekti; ardından "3. Network and Mobile Security". Bu ders "Web Security Model" kısmıdır.

### 1.1 Web neden önemli?

Hocaya göre web iki yönden önemlidir. Birincisi, web bugün standart kullanıcı arayüzü haline gelmiştir. İkincisi, büyük kitlelere hizmet veren uygulamaların arka tarafı da web teknolojisine uygun, istekleri cevaplayabilen uygulamalar olarak gerçekleştirilir. Bu yüzden web hem en çok saldırıya açık hem de saldırı yapıldığında en büyük etkiyi yaratan ortamlardan biridir. Web güvenlik modelini iyi anlamak bu nedenle gereklidir.

### 1.2 Güvenlik hedefleri

Web güvenliğinin temelindeki amaç diğer uygulamalardan çok farklı değildir: web'de saldırıya uğramadan, bilgilerimiz çalınmadan, istediğimiz sitelere ve bilgilere erişebilmek. Hoca bunu somut garantilere çevirdi:

- Bir siteye eriştiğimde, o site cihazımdan veri çalamamalı.
- Cihazıma kötü amaçlı yazılım (malware, malicious software) yükleyememeli.
- Kamera ve mikrofon gibi donanımlara bizim kontrolümüz dışında erişememeli.
- Tarayıcıda aynı anda birden çok siteyle etkileşim halindeyiz (sekmeler). Bir sekmede A sitesi, diğerinde B sitesi açıkken A sitesi B'yi kontrolsüz biçimde etkileyememeli, B'den veri çalamamalı ve B ile yaptığım haberleşmeyi dinleyip başka yere aktaramamalı.

Hoca, A ve B'nin illa ayrı sekmelerde olması gerekmediğini vurguladı. Frame ve iFrame yapısı sayesinde kullanıcı tek bir yere eriştiğini düşünürken sayfa aslında arka planda çok farklı sitelerden gelen parçaların birleşimi olarak oluşturuluyor olabilir.

Klasik web erişiminin yanında, web protokolleri üzerine kurulu uygulamalar da vardır. Hoca örnek olarak dersin yapıldığı Zoom uygulamasını verdi. Bu tür uygulamaların da güvenli olmasını sağlayacak bir model gerekir.

## 2. Web İçin Saldırı Modelleri

Slaytta dört kutu vardı: Malicious Website, Malicious External Resource, Network Attacker ve Malware Attacker (ekrandan, 00:10:00 ve 00:15:00).

### 2.1 Kötü niyetli web sitesi (Malicious Website)

En basit model budur: kullanıcı web'de dolaşırken farkında olmadan kötü niyetli bir siteyle karşılaşır. Hem kendi sistemimizi hem de o anda etkileşimde olduğumuz diğer siteleri bu siteden izole etmemiz gerekir. Hoca örnekler verdi:

- Başka bir sekmede bankama bağlıyım ve para işlemi yapıyorum. Kötü niyetli site diğer sekmedeki banka bağlantısıyla etkileşime geçememeli, oradan bilgi alamamalı, çaldığı verilerle kendi seçtiği bir hesaba para transfer edememeli.
- Diğer sekmede Facebook, Instagram ya da Gmail'e bağlıyım. Bu bağlantılar için kullanılan, kullanıcı adı ve şifre gibi "credential" denen, kimlik doğrulamayı (authentication) sağlayan özel bilgiler çalınamamalı.
- Site yerel diskten veri alamamalı, dosyalara erişememeli, hatta yerel ağda port taraması yapamamalı.

### 2.2 Kötü niyetli dış kaynak (Malicious External Resource)

Her zaman doğrudan kötü niyetli bir siteyle karşılaşmayız. Düzgün olduğuna, kötü amaçlı yazılım içermediğine inandığımız bir siteye gireriz; ama saldırgan, birinci modelde doğrudan sunduğu kodu burada dolaylı yoldan sunmaktadır, çünkü siteyi ele geçirmiştir. Hoca dersin başında bahsedilen bir yazılımı/servisi hatırlattı: bu araç özellikle SQL injection ve benzeri zafiyetleri kullanarak siteleri ele geçiriyor, oraya kötü niyetli kod yerleştiriyor, böylece siteyi ziyaret eden kullanıcıların bilgisayarlarına da bu kod yayılıyor ve kullanıcılar ele geçiriliyordu. <!-- BELİRSİZ: Altyazıda aracın adı "MPEG" olarak geçiyor (00:11:45); büyük olasılıkla ilk derste anlatılan MPack istismar kitidir. -->

Bu nasıl olabilir? Hoca şu örnekleri verdi:

- **Kullanıcı forumları:** Foruma çok sayıda gönderi yapılır; linkler, aktif içerik ve görüntüler bulunabilir. Kullanıcı ihtiyaç duyduğu bir şeyi ararken birisi "bunun çözümü şu sitededir" diye yazmıştır. Aramanın heyecanıyla linke basılır, oysa link kullanıcıyı kötü niyetli siteye ve zararlı içeriğe götürür.
- **Reklamlar:** Pek çok site Facebook ya da Google reklamları içerir. Reklam alanları her zaman saldırıya açıktır, çünkü oraya konan reklamın kullanıcıyı sonra kötü niyetli bir siteye götürmeyeceğini garanti etmek zordur.

### 2.3 Ağ saldırganı (Network Attacker)

Arada bir router vardır ve ele geçirilmiş olabilir; saldırgan bütün trafiği dinleyebilir, hatta değiştirebilir. Ya da DNS sunucusu ele geçirilir: kullanıcı adresini DNS üzerinden çözdüğü siteye düzgünce bağlandığını düşünürken aslında birebir aynı görünüşe sahip başka bir siteye bağlanır. Güvenlik modeli, router'ın ya da DNS servisinin ele geçirildiği bu senaryoya karşı da güçlü olmalıdır.

### 2.4 Zararlı yazılım saldırganı (Malware Attacker)

Dördüncü ve en ağır model: işletim sistemi seviyesindeki izolasyon ve ayırma gibi bütün tedbirler tarayıcı tarafında aşılır, gönderilen zararlı içerik tarayıcının içinde çalışmaya başlar ve sistemin kontrolü ele geçirilir.

Hoca, güvenlik modelinin bu dört saldırı modeline dayanacak biçimde tasarlanması gerektiğini söyledi: kişisel verilerin gitmesi, bilgilerin çalınması, kamera ve mikrofon gibi mahremiyetle ilgili cihazların ele geçirilmesi ve cihazın uzaktan kontrol edilen bir bota dönüştürülmesi engellenmelidir.

## 3. HTTP Protokolü

Web haberleşmesi ve web uygulamalarının tamamı HTTP protokolü üzerinden gerçekleştiği için önce HTTP'ye bakıldı.

### 3.1 Tarihçe ve temel özellikler

HTTP 1989'da CERN laboratuvarında oluşturuldu. Amaç, laboratuvarda yapılan araştırmaların benzer alanda çalışan araştırmacılara daha hızlı sunulması ve içeriğin paylaşılmasıydı. Öncesinde FTP ve Gopher protokolleri kullanılıyordu; HTTP bu ikisinin kısıtlamalarını ortadan kaldırmak için tasarlandı.

HTTP **durumsuz** (stateless) bir protokoldür: sunucu istemcinin, istemci de sunucunun en son durumuna dair bilgi tutmaz. Başlangıçta böyle tasarlanmıştır; ama bugün oturum (session) mantığını gerçekleştirmek için bu bilginin bir şekilde tutulması ve devamlılığının sağlanması gerekir (bkz. Bölüm 8). Protokol iki mesaja dayanır: **istek** (request) ve **cevap** (response).

### 3.2 URL

HTTP ile erişilen her kaynağın bir "erişim anahtarı" vardır: URL. Hoca bunu "Uniform Resource Location" diye açtı.

> **Ders sonrası not:** Hoca URL'yi "Uniform Resource Location" diye açtı; doğrusu "Uniform Resource Locator"dır.

URL, kaynağın ne olduğunu, nereden ve nasıl erişileceğini net biçimde tarif eder. Parçaları şunlardır:

- **Scheme:** protokolün kendisi (ör. `http`).
- **Domain:** kaynağın hangi sunucudan alınacağı.
- **Port:** erişim TCP/IP üzerinden olduğu için aynı sunucuda birden çok erişim noktası olabilir; hangisinin kullanılacağını belirtir.
- **Path, query string ve fragment ID:** kaynağı sunucu içinde bir seviye daha tekil olarak tanımlayan alt bilgiler.

Slayttaki örnekte cs155.stanford.edu sunucusunun 80 numaralı portuna HTTP ile gidiliyor, "lectures" yolundan ilerleniyor ve 08 numaralı dersin slaytlarına erişiliyordu. <!-- BELİRSİZ: URL örneğinin tam yazımı karede görülmedi; yalnız altyazıdan (00:18:59) aktarıldı. -->

### 3.3 HTTP isteğinin anatomisi

HTTP tamamen düz metindir (plain text): insanın okuyup yazabileceği biçimdedir. Zamanla Unicode'u ve başka dilleri içerecek şekilde güncellense de temelde ASCII (extended ASCII) kullanır. Slayttaki istek şuydu (ekrandan, 00:20:00):

```text
GET  /index.html  HTTP/1.1
Accept: image/gif, image/x-bitmap, image/jpeg, */*
Accept-Language: en
Connection: Keep-Alive
User-Agent: Mozilla/1.22 (compatible; MSIE 2.0; Windows 95)
Host: www.example.com
Referer: http://www.google.com?q=dingbats
```

Hoca satırları tek tek okudu:

- İlk satır yöntem (`GET`), yol (`/index.html`) ve protokol sürümüdür (`HTTP/1.1`); istemci 1.1 konuşur ve buna göre cevap bekler.
- `Accept`: gelen içerikte GIF, X-Bitmap, JPEG kabul edilir; `*/*` ile ne gelirse gelsin kabul edilir ama bir önceliklendirme vardır.
- `Accept-Language: en`: İngilizce içerik kabul edilir.
- `Connection: Keep-Alive`: bağlantı koparılmasın, daha sonra başka istekler için açık tutulsun.
- `User-Agent`: isteği gönderen tarayıcı (Mozilla 1.22 uyumlu, aslında MSIE 2.0, Windows 95).
- `Referer`: isteğe nereden gelindiği; burada bir Google araması.

Alttaki satırlar başlık (header) bölgesidir. Gövde (body) boştur, ama bir istek göndermek için bu kadarı bile yeterlidir.

### 3.4 HTTP cevabı

Cevapta sunucu kullandığı sürümü ve bir durum kodu bildirir; örnekte 200. Durum kodları 100, 200, 300, 400 ve 500 aileleri halinde farklı anlamlar taşır; 200 "OK", yani her şeyin yolunda gittiği anlamına gelir. Cevap başlıklarında cevabın tarihi, sunucunun ne olduğu (örnekte IIS, Internet Information Server), içerik tipi (`text/html`) ve içerik uzunluğu (2543 bayt) bulunur; altında da içeriğin kendisi gelir. <!-- BELİRSİZ: Cevap slaytı karede görülmedi; sürüm, sunucu ve uzunluk değerleri altyazıdan (00:21:50-00:22:28) aktarıldı. -->

## 4. HTTP Metotları

Slayttaki metot listesi şuydu (ekrandan, 00:25:00):

| Metot | Slayttaki tanım |
|---|---|
| GET | Get the resource at the specified URL (does not accept message body) |
| POST | Create new resource at URL with payload |
| PUT | Replace target resource with request payload |
| PATCH | Update part of the resource |
| DELETE | Delete the specified URL |

### 4.1 GET ve POST

GET, yolda verilen şeyin gönderilmesini ister; alma yönlüdür. Mesaj gövdesi yoktur, çünkü ne istendiği doğrudan söylenir. Hoca bunu dosya okumaya benzetti: bir dosyayı `fopen` ile açıp `fread` ile okurken "şu veriyi de al, onu da kullan" diyemezsiniz, doğrudan dosyadan okursunuz. GET de aynı mantıkla çalışır.

POST ise sunucuda yeni bir kaynağın o anda oluşturulmasını ve sonra gönderilmesini sağlar. Esneklik buradan gelir: kaynak oluşturulurken kullanılacak parametreler de gönderilir. Bu yüzden POST dinamik çalışır ve bir yük (payload) içerir.

### 4.2 PUT, PATCH, DELETE

Çok az kullanılan ama HTTP'de tanımlı başka metotlar da vardır:

- **PUT:** karşı taraftaki kaynağı istekteki yükle günceller, yani değiştirir (replace). Hoca PUT'un nispeten daha çok kullanıldığını, çünkü yükleme (upload) için yararlanılabildiğini söyledi; ama yükleme POST ile de yapılabilir. Aslında PUT bu iş için düşünülmüştü.
- **PATCH:** kaynağın yalnız belirli bir kısmını günceller.
- **DELETE:** verilen URL'yi tamamen siler.

### 4.3 GET durum değiştirmemeli

GET, var olanı var olduğu gibi almak üzere kurulu olduğu için sunucuda hiçbir durum değişikliğine yol açmamalıdır. Ancak sunuculardaki GET gerçekleştirmelerine bakıldığında, tamamen gerçekleştirmeden kaynaklanan sorunlar yüzünden bir GET isteğinin sunucuda durum değişikliğine neden olabildiği görülür.

Eski tarayıcılar PUT, PATCH ve DELETE'i neredeyse hiç desteklemez. Günümüzde isteklerin büyük çoğunluğu POST üzerinden yapılır. Hoca, POST'un PUT için de kullanılabileceğini (karşı tarafta o anda bir kaynak oluşturulur), hatta silmek için bile kullanılabileceğini söyledi.

Slaytta "yapma" denen bir GET örneği vardı. Hoca bunu şöyle açıkladı: böyle bir GET'in cevabı varsa, karşı tarafta bu işlem hazır durumda bekliyor demektir; istek hiçbir kimlik doğrulamadan, denetimden ve yetkilendirmeden geçmeyecek, sonuç doğrudan döndürülecektir. Bu, olabilecek en sorunlu şeylerden biridir; böyle bir isteğin GET ile değil, POST ile yapılması gerekir. <!-- BELİRSİZ: "Yapma" denen GET örneğinin kendisi karede görülmedi (00:28:34). -->

> **Hocanın vurgusu:** Sıradan, statik içerik almak için GET kullanılabilir; durum değiştiren ya da yetkilendirme gerektiren istekler GET ile yapılmamalı, POST ile yapılmalıdır.

## 5. Kaynak Yükleme, Frame ve iFrame

### 5.1 Kaynak yükleme

Statik içerik GET ile alınır: tarayıcı stanford.edu'dan `index.html` ister ve cevap gelir. Ama bir HTML sayfası kendi içinde başka kaynakların, başka URL'lerin yüklenmesini tetikleyebilir. Tarayıcı gelen içeriği ayrıştırır (parse) ve ona uygun ek isteklerde bulunur. Slayttaki örnek (ekrandan, 00:30:00):

```html
<img src="/imc/usr.jpg"></img>
```

Bu etiket karşılığında tarayıcı sunucuya `GET /img/usr.jpg` isteği gönderir ve resim gelir. Slaytta "Root HTML page can include additional resources like images, videos, fonts" ve "After parsing page HTML, your browser requests those additional resources" yazıyordu.

> **Ders sonrası not:** Slayttaki etikette yol `/imc/usr.jpg`, istekte `/img/usr.jpg` yazıyor; büyük olasılıkla slayttaki bir yazım hatasıdır, ikisi aynı yol olmalıdır.

Dış kaynaklara da referans verilebilir: içerik stanford.edu'dan gelmiş olsa da sayfa başka bir alan adındaki resmi yükleyebilir. Hoca bunun önemli olduğunu söyledi: resimlerle ilgili bir kısıtlama yoktur, resimler her yerden alınabilir. Slayttaki sorunun cevabı da buydu: "Nothing prevents you from including images on a different domain."

### 5.2 Frame ve iFrame

Bir site yalnız kaynak yüklemekle kalmayıp başka bir siteyi kendi içinde göstermek de isteyebilir; bu iç içe geçmiş biçimde olabilir. Bunun için iki yapı vardır:

- **Frame:** katı, sınırları belirli ve hareket ettirilemeyen bir bölümleme. Slayttaki tanım "rigid, visible division": sınırları kesin ve görünür.
- **iFrame:** "floating inline frame". Hareket edebilir ve sınırlarının her zaman görünmesi gerekmez.

Bu yapıya ihtiyaç şu nedenlerle doğar:

- Bir sitenin içeriğini başka bir sitenin içeriğiyle zenginleştirmek.
- Ticari açıdan, sitenin reklam alabilmesi; başka kaynaklardan reklam ya da benzeri içerik yükleyebilmesi.
- Düzgün yapılırsa, sayfanın yüklenmesinin tek bir kaynaktan değil farklı kaynaklardan gerçekleşmesi.

## 6. JavaScript ve Document Object Model (DOM)

### 6.1 JavaScript

Slaytta şu yazıyordu (ekrandan, 00:35:00): "Historically, HTML content was static or generated by the server and returned to the web browser to simply render to the user. Today, websites also deliver scripts to be run inside of the browser."

Başlangıçta HTML ya tamamen statikti ya da sunucuda (örneğin bir POST sonrasında) oluşturuluyor, tarayıcı da onu yalnız biçimlendirip kullanıcıya gösteriyordu. Bugün ağırlıklı olarak JavaScript kullanılır. JavaScript yorumlanarak çalışan (interpreted) bir dildir ve tarayıcının içinde çalışır: çalıştırılması istenen içerik sunucudan tarayıcıya aktarılır ve sunucuda değil tarayıcıda çalışır.

Slayttaki örnek bir butondu:

```html
<button onclick="alert("The date is" + Date())">
  Click me to display Date and Time.
</button>
```

Buton etiketi "Click me to display Date and Time." olarak görünür. Butona basıldığında (`onclick` olayı) yazılmış JavaScript kodu çalışır; `alert` ekranda bir pencere açar ve o anki tarihi yazar.

JavaScript yüklenip tarayıcıda çalışmaya başladıktan sonra:

- Ek web isteklerinde bulunabilir.
- Mevcut sayfanın görüntüsünü, şeklini, rengini, yapısını değiştirebilir.
- Tarayıcının çalışmasıyla ilgili temel veri yapılarına erişebilir.
- Yerel donanıma da erişebilir.

Slayttaki ifadeyle "exceptionally powerful today". Hoca, JavaScript'in bir yandan çok güçlü bir programlama ortamı, öte yandan web uygulamalarına gereken dinamikliği sağlayan yapı olduğunu söyledi.

### 6.2 DOM

Tarayıcıda görüntülenen ve üzerinde işlem yapılan her şey temelde bir "doküman" olarak adlandırılmış, ama nesne (object) mantığıyla ele alınmıştır: Document Object Model, DOM. Slayttaki ağaç şuydu (ekrandan, 00:40:00):

```text
document
└── Root element: <html>
    ├── Element: <head>
    │   └── Element: <title>
    │       └── Text: "My title"
    └── Element: <body>
        ├── Element: <h1>
        │   └── Text: "A heading"
        └── Element: <a>   (Attribute: href)
            └── Text: "Link text"
```

En tepede document vardır; içinde html, onun içinde head, head'in içinde title, title'ın içinde "My title" metni. Body'de bir h1 başlığı ve bir aktif öğe (`<a>` bağlantısı) vardır; `href` özniteliği referansın gittiği yeri, "Link text" de bağlantı metnini gösterir. Yapı document'ta başlayıp aşağıya doğru bir ağaç olarak ilerler.

Slayttaki maddeler: "Javascript can read and modify page by interacting with DOM", "Object Oriented interface for reading/writing page content", "Browser takes HTML -> structured data (DOM)". Tarayıcı kendisine gelen statik ya da dinamik bütün içeriği DOM'u işleyerek sayfaya dönüştürür. DOM'a erişim tamamen nesne yönelimli bir arayüzle, hem okuma hem yazma yönünde yapılır. Statik HTML'de DOM'u tarayıcı değiştirir; JavaScript yüklendiyse bu işi JavaScript komutları yapar.

Slayttaki script örneği:

```html
<p id="demo"></p>

<script>
  document.getElementById('demo').innerHTML = Date()
</script>
```

`demo` kimlikli öğenin içeriğine `Date()` yazılır. `Date` yerelde çalıştığı için sayfa yüklendiğinde yerel makinedeki tarih `demo` alanının içeriği olur.

### 6.3 Tarayıcının sayfa işleme döngüsü

Her tarayıcı penceresi içeriği bir kök sayfadan (root page) başlayarak yükler:

- HTML'i ayrıştırır (parse), içinde JavaScript varsa çalıştırır.
- Ayrıştırırken karşılaştığı resim, CSS (Cascading Style Sheet), ek JavaScript ve iFrame gibi alt kaynakları yükler ve yüklenen her parça için aynı işlemleri (HTML ayrıştırma, JavaScript çalıştırma) tekrarlar.
- Bu sırada klavye ve fareden gelen olayları yakalar: bir butona basılması, bir alanın üzerine gelinmesi, bir içeriğin yüklenmesi ya da belirli bir sürenin dolması.

## 7. HTTP/2

HTTP/1.1'den sonra bugün en çok kullanılan sürümlerden biri HTTP/2'dir. Slayttaki maddeler (ekrandan, 00:45:00):

- Major revision of HTTP released in 2015
- Based on Google SPDY Protocol
- No major changes in how applications are structured
- Major changes (mostly performance): pipelining requests for multiple objects; multiplexing multiple requests over one TCP connection; header compression; server push

Hoca bunları şöyle açıkladı. HTTP/2 2015'te ilan edildi; Google'ın üzerinde çalıştığı SPDY protokolünün güncellenmesiyle bu adı aldı. Sunucu ve istemci uygulamalarının yapısında değişiklik getirmez, ama özellikle performans açısından büyük değişiklikler içerir:

- **Birden çok nesne için eşzamanlı istek:** Orijinal HTTP tek istek üzerine kuruludur: istek-cevap, istek-cevap. HTTP/2'de birden çok nesne için isteklerin aynı anda yapılmasına izin verilir. Bunun için tek bir TCP bağlantısı üzerinde birden çok isteğin çoğullanması (multiplexing) gerekir.
- **Başlık sıkıştırma:** Başlık tamamen metin (ASCII) tabanlıdır ve gereğinden büyüktür; böyle aktarılması bant genişliğinden ve hızdan kaybettirir. Bu yüzden başlıklar sıkıştırılarak aktarılır; istemci başlığı sıkıştırıp gönderir, sunucu açar. Trafikte önemli bir azalma sağlanır.
- **Server push:** En önemli farklardan biridir. HTTP/2'ye kadar istemci ister, sunucu cevap vermek zorundadır. HTTP/2'de bağlantı uzun soluklu ve kapatılmayan bir bağlantı olarak tasarlanmıştır (Keep-Alive zaten vardı, artı bir bağlantı birden çok isteği yönetir). Bu durumda sunucu istemciye kendiliğinden veri itebilir.

> **Ders sonrası not:** Hoca bir yerde "bir web sayfası aynı sunucuya aynı anda birden fazla bağlantı kurabiliyor" dedi, hemen ardından tek TCP bağlantısı üzerinde çoğullamadan söz etti. HTTP/2'nin amacı birden çok bağlantı açmak değil, istekleri tek bağlantı üzerinde çoğullamaktır. Başlık sıkıştırması için hoca "zip" dedi; HTTP/2 başlıkları büyük olasılıkla genel amaçlı zip/gzip ile değil, bu iş için tasarlanmış HPACK yöntemiyle sıkıştırır.

## 8. HTTP Çerezleri ve Oturum Yönetimi

### 8.1 Durumsuzluk sorunu

HTTP durumsuzdur: soldan bir istek gelir, sağdan bir cevap döner, ama istekler birbiriyle ilişkilendirilmez. Sunucu aynı istek için hep aynı cevabı döndürür. Peki istemci ile sunucu arasında süreklilik, yani oturum (session) nasıl sağlanır? Çerezlerle (cookies).

### 8.2 Çerezin tanımı ve kullanım alanları

Slayttaki tanım (ekrandan, 00:50:00): "HTTP cookie: a small piece of data that a server sends to the web browser. The browser *may* store and send back in future requests to that site."

Çerez, sunucunun tarayıcıya (istemciye) gönderdiği küçük bir bilgidir. Tarayıcı çerezi saklamayı seçebilir ve aynı sunucuya sonraki isteklerinde geri gönderebilir. Böylece sunucu istemcinin kim olduğunu ve aralarındaki haberleşmede en son nerede kalındığını bilerek devam edebilir; bağımsız istekler birbiriyle ilişkili istekler haline gelir.

Kullanım alanları:

- **Oturum yönetimi (session management):** login, alışveriş sepeti, oyun skorları ya da oturum açısından önemli başka herhangi bir durum.
- **Kişiselleştirme (personalization):** kullanıcı tercihleri, temalar ve ayarlar. Hoca örnek verdi: benim hoşuma giden renkler, fontlar, görünüm sizinkiyle aynı olmayabilir; benim tarayıcımın gönderdiği çerezle sayfa bana göre, sizinkinin gönderdiği çerezle size göre biçimlenir.
- **İzleme (tracking):** kullanıcının takip edilmesi ve davranışının kaydedilip analiz edilmesi; kullanıcı buraya gelene kadar nerelerden geçti, en çok hangi sayfaya gitti, nerede daha çok vakit harcadı.

Hoca iki noktaya dikkat çekti. Birincisi, slayttaki "may" kelimesi: istemci çerezi göndermemeyi seçebilir; göndermezse sunucunun istemcinin en son durumunu bilip oradan devam etmesi mümkün olmaz. İkincisi, çerezler kötü niyetli siteler tarafından da kullanılır; istemciye gelen bir çerez her zaman iyi niyetli değildir.

### 8.3 Çerezin ayarlanması ve gönderilmesi

Slayttaki örnekte sunucu 200 OK ile cevap verirken iki çerez göndermişti: biri `trackingID`, diğeri `userID` adlı, yanlarında sayısal değerlerle. Tarayıcı bu iki çerezi saklamaya ve sonraki isteklerine eklemeye karar verirse, sunucu bir sonraki istekte isteğin hangi tarayıcıdan geldiğini anlayabilir. Çerezin gönderilmesini sunucu başlatır; çerezi sunucuya geri gönderip göndermemeye tarayıcı karar verir. <!-- BELİRSİZ: "Setting Cookie" ve "Sending Cookie" slaytları karede yalnız küçük önizleme olarak görüldü (ekrandan, 01:00:00); çerez değerleri okunamadı. -->

### 8.4 Login oturumu

Hoca login sürecini slayttaki akış üzerinden anlattı:

1. İstemci login formunu GET ile ister. Cookie alanı boştur (`[]`); sunucu çerez döndürmez, yalnız login formunu döndürür.
2. Kullanıcı adı ve şifre POST ile gönderilir; cookie alanı hâlâ boştur. İlk istek GET, ikincisi POST'tur, çünkü form düz biçimde GET ile gelir ama içerik POST ile gönderilir.
3. Giriş başarılı olunca sunucu bu kullanıcı için bir oturum oluşturur, bir session ID değeri atar ve bunu istemciye çerez olarak döndürür. <!-- BELİRSİZ: Session ID değeri karede okunamadı; altyazıda "E8-2A-7B-92" gibi okunuyor (00:52:35). -->
4. Bundan sonra istemci her istekte bu session değerini gönderirse sunucunun kullanıcıya tekrar tekrar giriş yaptırmasına gerek kalmaz; sunucuda bu oturumun slayttaki örnek kullanıcıya ait olduğu ve başarılı giriş yapıldığı bilgisi vardır. `user.jpg` alınırken de, hesap sayfası alınırken de session çerezi gönderilir.

Birden çok çerez olsaydı hepsi gönderilirdi.

### 8.5 Çerezler her zaman gönderilir: iyi ya da kötü

Slayttaki kural (ekrandan, 00:55:00): "Cookies set be a domain are always sent for any request to that domain." Tarayıcı çerez göndermeye ayarlandıysa çerezleri hep gönderir; bazen gönderip bazen göndermeme seçeneği yoktur. Bir alan adı için ayarlanmış çerez, o alan adının sunucusundan gelmiş çerez demektir ve o alan adına yapılan her istekte gönderilir. Resim isteğinde bile (`/img/usr.jpg`) çerezler gider.

Hoca bunun faydası olduğu kadar zararı da olabileceğini söyledi. Slaytın "...for better or worse..." başlıklı devamında başka bir sayfaya (`http://example.com`) şu etiket yerleştirilmişti (ekrandan, 00:55:00):

```html
<img src="https://bank.com/transfer?
  fromAccount=X
  &toAccount=Y
  &amount=1000"></img>
```

Tarayıcı bu "resmi" yüklemek için bank.com'a `GET /transfer?...` isteği gönderir ve bank.com'un çerezlerini de ekler.

> **Ek bilgi (derste anlatılmadı):** Bu tür saldırıya genellikle siteler arası istek sahteciliği (Cross-Site Request Forgery, CSRF) denir. Kullanıcının bankada açık bir oturumu varsa istek onun kimliğiyle işlenir. Bölüm 4.3'teki "durum değiştiren işlem GET ile yapılmamalı" kuralı bu yüzden önemlidir. Konu büyük olasılıkla "Web Vulnerabilities and Attacks" bölümünde ayrıntılı ele alınır.

## 9. Modern Web Sitesi: Los Angeles Times Örneği

Slaytta Los Angeles Times'ın analizi vardı. Hoca analizin bizi ilgilendiren sonucunu okudu: LA Times ana sayfası yaklaşık 270 IP adresinden, 58 ağdan ve 8 ülkeden 540 kaynak yükler. En popüler haber sitelerinden CNN ise 361 kaynak yükler. Hoca bunun çok ciddi bir değer olduğunu söyledi.

Slayttaki son cümle önemlidir: "Many of these aren't controlled by the main sites." 540'ın ya da 361'in tamamını LA Times ya da CNN istemez. Onlar bazı kaynakların yüklenmesini başlatır; o kaynaklar da yüklenirken kendi içlerinde başka kaynaklara referans verir. A, B'yi; B, C'yi; C de D'yi yükler. Böylece iç içe geçmiş karmaşık bir yapı oluşur.

Sayfa yüklenince 51 çerez gelir (ekrandan, 01:00:00, slayt önizlemesinde "51 cookies" etiketi); bunların bir kısmı doğrudan LA Times'tan, bir kısmı onun eriştiği sitelerden gelir. Son slaytta sayfanın bölgeleri işaretlenmişti: üçüncü taraf reklamlar (third-party ad), analiz (analytics) bölümü, bir frame içine alınmış reklam, jQuery kütüphanesiyle dinamik çalışan kısım ve yerel script olarak çalışan üst menü.

## 10. Aynı Köken Politikası (Same Origin Policy)

Aradan sonra yeni bölümün kapağı açıldı: "Same Origin Policy (Goals)" (ekrandan, 01:15:00). Soru şuydu: işletim sisteminde görülen güvenlik modeli, şimdiye kadar öğrenilen web kavramlarıyla web tarafında nasıl kurulur? En önemli ilkelerden biri Same Origin Policy (SOP).

### 10.1 Unix modeliyle eşleme

Hoca Unix'teki güvenlik modelini hatırlattı: bir subject (kim), bir object (kaynaklar, ne) ve erişim türleri (nasıl: read, write, execute) vardı. Web güvenlik modelinde bu üç kavramın da karşılığı vardır:

| Unix modeli | Web modeli |
|---|---|
| Subject (who) | Origin: kaynağın istendiği yer; scheme (HTTP, HTTPS), domain ve port |
| Object (what) | DOM ağacı, yerel depolama, çerezler, donanıma erişim izinleri, JavaScript isim alanları |
| How (read, write, execute) | HTTP metotları (GET, PUT, POST, ...) |

JavaScript isim alanları (namespace) bir izolasyon biçimidir: farklı isim alanları oluşturarak aynı yapıları birbirinden ayırabiliriz. İsimler aynı görünse de isim alanı farkı yüzünden tamamen bağımsız hale gelirler; yapılar gruplanıp özel bir isim altında toplanır.

### 10.2 SOP'nin hedefleri

SOP gizliliği (confidentiality) ve bütünlüğü (integrity) sağlamaya çalışır. Gizlilik okuma (read) erişimine, bütünlük ise değiştirme (modify) erişimine karşılık gelir.

### 10.3 Köken sınırları (Bounding Origins)

Slayttaki iki kural (ekrandan, 01:20:00):

- Every Window and Frame has an origin.
- Origins are blocked from accessing other origin's objects.

Bir pencereye ya da çerçeveye hangi kökenden script ve içerik yüklendiyse, o pencere ya da çerçeve başka kökenden gelen nesnelere erişemez. Hoca kökeni, JavaScript'in çalışırken ait olduğu "user ID" gibi düşünmeyi önerdi: işletim sisteminde her sürecin bir sahibi vardır, süreç bir kullanıcıyla ilişkilendirilir ve yetkiler buna göre belirlenir. Burada da JavaScript'in yüklendiği sitenin sahipliğinde çalıştığı varsayılır.

Hoca buradaki "window" kelimesinin işletim sistemiyle karıştırılmaması gerektiğini, frame anlamında kullanıldığını söyledi. Ardından frame olmadan yalnız pencerelerin olduğu ve aynı alan adına ait iki sekmenin bulunduğu bir durumu inceledi. <!-- BELİRSİZ: 01:19:25-01:23:34 arasında altyazıda uzun boşluklar var; köken karşılaştırma örnekleri ve iki sekme senaryosunun sonucu altyazıdan çıkarılamadı. -->

### 10.4 BroadcastChannel API

Slayttaki tanım (ekrandan, 01:25:00): "The BroadcastChannel API allows same-origin scripts to send messages to other browsing contexts. Simple pub/sub message bus between windows/tabs, iframes, web workers, and service workers."

Bu API aynı kökenden yüklenmiş script'lerin aralarında mesaj alışverişi yapmasını sağlar; önemli olan aynı köken olmasıdır. Yayıncı-abone (publisher/subscriber) modelidir: bir taraf yayınlar, diğer taraf abone olur. Pencereler, sekmeler, iframe'ler ve worker'lar arasında çalışabilir. Slayttaki kod:

```javascript
// Connect to the channel named "my_bus".
const channel = new BroadcastChannel('my_bus');

// Send a message on "my_bus".
channel.postMessage('This is a test message.');

// Listen for messages on "my_bus".
channel.onmessage = function(e) {
  console.log('Received', e.data);
};

// Close the channel when you're done.
channel.close();
```

Kanal `new BroadcastChannel` ile bir ad verilerek oluşturulur, `postMessage` ile kanala mesaj gönderilir. Diğer tarafta `onmessage` ile mesaj gelince çalışacak fonksiyon lambda biçiminde yazılmıştır; `e.data` konsola basılır. İş bitince kanal kapatılır.

> **Hocanın vurgusu:** Bütün bunlar kendiliğinden olmaz; tarayıcıda gerçekleştirilmiş güvenlik denetimleri, yani güvenlik modelinin tarayıcıdaki uygulaması sayesinde olur. Kuralları biz tarif ederiz, tarayıcı uygular.

### 10.5 Ebeveyn-çocuk pencereler arasında postMessage

Aralarında ebeveyn-çocuk (parent-child) ilişkisi olan pencere ve çerçeveler mesaj alışverişi yapabilir. Hoca, mesaj alışverişi yapmanın içeriğe erişmekten ayrı bir şey olduğunu vurguladı. Gönderen taraf `targetWindow.postMessage(message, targetOrigin)` çağırır: `targetWindow` hedef pencerenin referansıdır (pencerenin ebeveyni ya da çerçeveleri), `targetOrigin` hedefin kökenidir ve `*` ya da bir URI olabilir. Alıcı tarafta `addEventListener` ile "message" olayına bir `receiveMessage` fonksiyonu bağlanır; mesaj gelince bu fonksiyon çalışır (örnekte bir uyarı penceresi açar). <!-- BELİRSİZ: postMessage slaytı karede görülmedi; kod yalnız altyazıdaki anlatımdan (01:27:37-01:28:13) aktarıldı. -->

## 11. SOP'nin HTTP Cevaplarına, Kaynaklara ve Script'lere Uygulanışı

### 11.1 HTTP cevapları

Slayt (ekrandan, 01:30:00): "Pages can *make requests* across origins." Örnekte attacker.com sayfasında şu etiket vardı:

```html
<img src="https://bank.com/img/usr.jpg"></img>
```

Tarayıcı bank.com'a `GET /img/usr.jpg` isteğini çerezleriyle gönderir ve resim gelir. Slaytın alt yazısı: "SOP prevents Javascript on attacker.com from directly *inspecting* HTTP responses (i.e., pixels in image). It *does not* prevent *making* the request."

Hoca derste sordu: sayfalar farklı kökenlere istekte bulunabilir mi? Evet, hiçbir sorun yoktur. Ama gelen HTTP cevabını inceleyemezler. Dersin başında söylendiği gibi bir resmin yüklenmesini engelleyen bir mekanizma yoktur. Resmi yüklemek ayrı bir şeydir: resim yüklenir ve `img` etiketi nereye konduysa orada görüntülenir. Ama bu JavaScript gelen resmin içini, piksel piksel inceleyemez.

### 11.2 Resimler, CSS ve fontlar

Slayttaki ifade: "Browser renders cross-origin images, but SOP prevents page from inspecting individual pixels. Can check size and if loaded successfully." Sayfa yalnız resmin boyutunu ve doğru yüklenip yüklenmediğini kontrol edebilir.

Aynı mantık CSS ve fontlar için de geçerlidir. Font ve stil sayfası hizmeti veren siteler vardır; buralardan yükleyip kullanabiliriz, çünkü onları tarayıcının kendisi kullanır. Ama yüklenmeyi tetikleyen JavaScript ya da içerik gidip içeriğini inceleyemez.

### 11.3 Frame'ler

Frame'ler için de aynısı geçerlidir: "Can load cross-origin HTML in frames, but not inspect or modify the frame content." Başka kökenli bir HTML çerçeveye yüklenebilir; ama içeriği incelenemez ve değiştirilemez. Hoca, frame yüklendiği andan itibaren onunla bütün bağlantının kopmuş olduğunu söyledi; frame'in doğru mu yüklendiği, ne kadar yüklendiği ya da yüklenemediği bile kontrol edilemez ("Cannot check success for frames").

### 11.4 Script çalıştırma

Slayt (ekrandan, 01:35:00): "Scripts can be loaded from other origins. Scripts execute with the privileges of their parent frame/window's origin. Cannot view source, but can call FNs."

Script'ler başka kökenlerden yüklenebilir ve bağlı bulundukları pencerenin ya da çerçevenin kökeni (user ID'si) kimse onun yetkisiyle çalışır. Kaynak kodları görülemez, ama fonksiyonları çağrılabilir. Slayttaki iki örnek:

```html
<!-- bank.com -->
<script src="/js/jquery.min.js"></script>

<!-- bank.com -->
<script src="jquery.com/jquery.min.js"></script>
```

- Birincisi: "You can load library from CDN and use it to alter your page." (doğru kullanım)
- İkincisi: "If you load a malicious library, it can also steal your data (e.g., cookie)." (tehlikeli)

Hoca alttaki örneğin çok tehlikeli olduğunu, yapılmaması gerektiğini söyledi. Dahil edilen JavaScript, dahil edildiği pencere ya da çerçevenin SOP'sine göre yetkilendirildiği için yerel çerezlere, oturum verisine, doküman içeriğine ve alanlara erişebilir; bu bir zafiyet oluşturur.

## 12. Domain Relaxation ve Public Suffix List

### 12.1 Neden gevşetme gerekir?

"Relaxation", kısıtın rahatlatılması demektir; bazı durumlarda gerekir. Örnek: Facebook bir çerçeveyi kendi başka bir alt alan adından, CDN'sinden (Content Distribution Network) yükler. Bu normalde meşru olması gereken bir yapıdır ve SOP konusunda hafif bir gevşetmeye ihtiyaç duyar. Bu iş `document.domain` ile yapılır: bir sayfa kendi kökenini kendi alan adının bir üst sonekine ayarlayabilir. <!-- BELİRSİZ: Gevşetmenin nasıl çalıştığını anlatan kısım (01:36:57-01:37:57) altyazıda eksik; kural slayt ve sonraki anlatımdan kurulmuştur. -->

Ancak her üst sonek kabul edilemez. Hoca, `a.com` gibi bir alan adının `com`'a gevşetilmesinin uygun olmadığını söyledi: `a` ile `com` arasında milyonlarca farklı alan adı olabilir. Burada DNS'e yapılacak saldırılara karşı bir zafiyet de başlar: DNS ele geçirilip isimlerin çözümü saldırganın kontrolüne geçerse durum çok sorunlu hale gelebilir.

### 12.2 Public Suffix List

Hangi soneklerin gevşetme hedefi olamayacağını belirlemek için Public Suffix List kullanılır (ekrandan, 01:40:00). Sayfadaki tanım: "A 'public suffix' is one under which Internet users can (or historically could) directly register names. Some examples of public suffixes are .com, .co.uk and pvt.k12.ma.us."

Liste Mozilla tarafından başlatılmış, ama topluluk tarafından sürdürülen bir girişimdir. Her yazılımda kullanılabilir, kendi web uygulamanız için de. Başlangıçta tarayıcı üreticilerinin ihtiyaçları için oluşturulmuştur ve tarayıcıların şunları yapmasını sağlar:

- Üst seviye alan adı soneklerine ayarlanan, mahremiyete zarar veren "süper çerezleri" (supercookies) önlemek.
- Kullanıcı arayüzünde bir alan adının en önemli kısmını vurgulamak.
- Geçmiş kayıtlarını siteye göre doğru sıralamak.

Liste https://publicsuffix.org/ adresindedir. Hoca, bunun yalnız Facebook, Google, Instagram, Twitter gibi büyük kurumlar için değil, diğer uygulama geliştiricilerin de yararlanması için oluşturulmuş bir servis olduğunu söyledi.

### 12.3 Relaxation saldırıları

Slayt (ekrandan, 01:45:00): "What about cs155.stanford.edu → stanford.edu? Now Dan and Zakir can steal your Stanford login. Solution: Both sides must set `document.domain` to share data."

Dan ve Zakir, Stanford'da CS155 dersini yürüten iki öğretim üyesidir. cs155.stanford.edu kendi kökenini stanford.edu'ya gevşetirse, alt alan adının yetkisi bir anda üst alan adına çıkarılmış olur. Kullanıcı stanford.edu'ya giriş yapmışsa, giriş sırasında gönderilmiş çerezler alt alan adındaki sayfa tarafından alınabilir; yani dersin hocaları kullanıcının Stanford girişini çalabilir. Çözüm olarak, veri paylaşılacaksa her iki taraf da `document.domain`'i ayarlamak zorundadır; yalnız bir tarafın gevşetmesi yetmez.

<!-- BELİRSİZ: 01:42:51'de hoca bir frame örneğinde cs155.stanford.edu'dan yüklenen çerçevenin document.domain'i stanford.edu'ya ayarlamaya çalıştığını ve bunun "olmadığını" söylüyor; örneğin slaytı karede görülmedi ve anlatım (alt/üst alan adı yönü) altyazıda net değil. -->

## 13. JavaScript İstekleri ve CORS

### 13.1 JavaScript'in ağ istekleri

JavaScript ağ isteğinde bulunabilir: doldurulmuş bir formu göndermek için (form HTML'de doldurulur ama bütün alanlarına ve submit kısmına DOM üzerinden JavaScript ile erişilebilir) ya da ek içerik yüklemek için. Slayttaki örnekte yeni bir `XMLHttpRequest` (XHR) başlatılıp bir makale (article) alınıyor, cevabın durum koduna bakılıyor, 200 ise bir uyarı veriliyordu; aynı iş jQuery ile de yazılmıştı. Sunucu adresi belirtilmediği için yol, bağlı bulunulan sunucuda çözülür. <!-- BELİRSİZ: XHR ve jQuery kod örnekleri karede görülmedi (01:46:10-01:46:53); yalnız anlatımdan aktarıldı. -->

### 13.2 Kurallar

Hoca kuralların çok net olduğunu söyledi:

- "You cannot make requests to a different origin unless you are granted permission by the destination origin." Hedef izin vermedikçe bulunduğunuz kökenin dışındaki bir kökene ağ isteği gönderemezsiniz. Çoğunlukla karşı taraf buna izin verir ya da vermek durumunda kalır.
- "You can only read responses if they are from the same origin" (ya da hedef okumanıza izin verdiyse). İsteğin sonucunda gelen cevabı ancak sizinle aynı kökendeyse okuyabilirsiniz.

İstek yapıp yapamamak ya da isteğin sonucunu görebilmek, kesinlikle karşı tarafın izin vermesine bağlıdır.

### 13.3 Cross-Origin Resource Sharing (CORS)

Kökenler arası kaynak paylaşımının kontrolüne CORS denir. JavaScript ile bir HTTP isteği yapılırken isteğin gerçekleşip gerçekleşmeyeceği ve gelen cevabın okunup okunamayacağı CORS ile belirlenir. Slayt (ekrandan, 01:50:00):

- **Reading Permission:** Servers can add `Access-Control-Allow-Origin` (ACAO) header that tells browser to allow Javascript to allow access.
- **Sending Permission:** Performs "Pre-Flight" permission check to determine whether the server is willing to receive the request from the origin.

Okuma izninde sunucu, ACAO başlığıyla içeriğin okunup okunamayacağını söyler. Gönderme izninde tarayıcı önce bir ön deneme yaparak sunucunun o kökenden istek kabul edip etmediğini öğrenir.

### 13.4 Pre-flight denetimi

Slayttaki örnekte iki taraf aynı kurumun altındaydı (bir uygulama ve bir API alt alan adı). Tarayıcı, asıl POST'tan önce sunucuya bir OPTIONS isteği gönderir. OPTIONS bir sorgudur: sunucuya "bu durumu destekliyor musun?" diye sormaktan başka bir şey değildir. Sunucu kabul ederse tarayıcı "buraya erişebiliyormuşuz" der, bu sefer gerçekten POST gönderir ve asıl veriyi alır. Sunucu kabul etmezse tarayıcı hata döndürür. Hoca pre-flight denetimini tarayıcının yaptığını ve kullanıcının işini kolaylaştırmak için var olduğunu söyledi. <!-- BELİRSİZ: Pre-flight örneğinin alan adları ve başlıkları karede görülmedi (01:51:14-01:52:19). -->

> **Ders sonrası not:** Hoca tarayıcının POST isteğini OPTIONS isteğine "dönüştürdüğünü" ve bunu o alan adına daha önce istek yapılmadıysa yaptığını söyledi. Doğrusu, tarayıcı asıl isteği değiştirmez; asıl istekten önce ayrı bir OPTIONS isteği gönderir. Bu ön denetim, istek "basit" değilse yapılır (Bölüm 13.6). Daha önce istek yapılıp yapılmamasına bağlı değildir; tarayıcı ön denetimin sonucunu büyük olasılıkla bir süre önbellekte tutabilir.

### 13.5 Joker köken

Hoca en tehlikeli durumlardan birinin joker köken (wildcard origin) olduğunu söyledi: istek nereden gelirse gelsin, gönderilen içerik herkes tarafından okunabilir. Bazı içeriklerin paylaşılması sorun değildir ve bu durumlarda kullanılabilir; ama bu durumda yapılan isteklerde SOP'nin pek önemi kalmaz, çünkü içerik her kökenden okunabilir.

### 13.6 Basit istekler (Simple Requests)

Her istek için pre-flight yapmak trafiği artırır; bu yüzden basit isteklerde bu denetim yapılmaz. Slayt (ekrandan, 01:55:00): "Not all requests result in a Pre-Fetch trip. 'Simple' requests do not. Must meet all of the following criteria:"

1. Method: GET, HEAD, POST
2. If sending data, content type is `application/x-www-form-urlencoded` or `multipart/form-data` or `text/plain`
3. No custom HTTP headers (can set a few standardized ones)

"These mimic the types of requests that could be made without Javascript, e.g., submitting form, loading image, or page."

> **Ders sonrası not:** Hoca bir cümlede "GET, HEAD, POST gibi isteklerde bunu (pre-flight) gerçekleştiriyoruz" dedi. Slayta göre doğrusu tersidir: bu üç koşulun hepsini sağlayan basit istekler pre-flight yapmaz; pre-flight yalnız bu koşulların dışındaki istekler için yapılır.

## 14. Çerezlerde Aynı Köken Politikası

### 14.1 Çerezlerde köken tanımı

Hoca çerezlerde köken tanımının biraz daha farklı ve çetrefilli olduğunu söyledi. Diğer nesnelerde köken scheme + domain + port iken, çerezlerde köken **domain + path** üzerinden belirlenir (örneğin cs155.stanford.edu ve /foo/bar).

Tarayıcı bir URL'nin kapsamındaki (scope) bütün çerezleri gönderir. Kapsam şu demektir:

- Çerezin domain'i, URL'nin domain'inin bir sonekidir (suffix). Örnek: stanford.edu, cs155.stanford.edu'nun bir sonekidir.
- Çerezin path'i, URL'nin path'inin bir önekidir (prefix). Örnek: /courses, /courses/cs155'in bir önekidir.

> **Hocanın vurgusu:** Çerezlerde aynı köken değerlendirmesi scheme + domain + port olarak değil, domain + path olarak yapılır; bunu unutmamak gerekir.

### 14.2 Kapsam örneği

Hoca slayttaki tabloyu tek tek yorumladı (ekrandan, 02:00:00). Üç çerez şunlardı:

| Çerez | value | domain | path |
|---|---|---|---|
| cookie1 | a | login.site.com | / |
| cookie2 | b | site.com | / |
| cookie3 | c | site.com | /my/home |

Kural: cookie domain is suffix of URL domain ∧ cookie path is a prefix of URL path. Tablodaki sonuçlar (Yes = çerez gönderilir):

| URL | Cookie 1 | Cookie 2 | Cookie 3 |
|---|---|---|---|
| checkout.site.com | No | Yes | No |
| login.site.com | Yes | Yes | No |
| login.site.com/my/home | Yes | Yes | Yes |
| site.com/account | No | Yes | No |

Hocanın satır satır açıklaması:

- **checkout.site.com:** cookie1'in domain'i (login.site.com) tamamen farklıdır, gönderilmez. cookie2'nin domain'i site.com sonektir, path `/` köktür ve URL yolunu içerir; gönderilir. cookie3'ün domain'i tutar ama path'i `/my/home` daha özeldir, URL yolunun öneki değildir; gönderilmez.
- **login.site.com:** cookie1 ve cookie2 gönderilir; cookie3 yine path yüzünden gönderilmez.
- **login.site.com/my/home:** Üçü de uygundur. cookie1'de domain birebir tutar, path `/` önektir. cookie2'de domain sonektir, path `/` önektir. cookie3'te site.com üst sonektir ve path `/my/home` tutar.
- **site.com/account:** cookie1'in domain'i tutmaz (login.site.com, site.com'un soneki değildir); gönderilmez. cookie2'de domain birebir tutar, `/` önektir; gönderilir. cookie3'te domain birebir tutar ama `/my/home`, `/account`'un öneki değildir; gönderilmez.

> **Ders sonrası not:** Hoca son satırda "/my/home account'un sonekı değil" dedi; kurala göre path için bakılan şey önektir (prefix): `/my/home`, `/account`'un öneki değildir. Tablonun bütün değerleri bu kuralla python'da yeniden hesaplanmış ve slayttaki tabloyla aynı çıkmıştır.

### 14.3 Kapsamı kim ayarlayabilir?

Slayttaki kural: "Websites can set scope to be any prefix of domain and prefix of path." Hoca örnekledi: cs155.stanford.edu, çerezi cs155.stanford.edu için de stanford.edu için de ayarlayabilir; ama stanford.edu, cs155.stanford.edu için ayarlayamaz. Yani bir site, kendi kontrolündeki bir alt alan adı için bile çerez ayarlayamaz. <!-- BELİRSİZ: Slaytta domain için "prefix" yazdığı altyazıdan anlaşılıyor (02:02:03); kurala göre büyük olasılıkla alan adının bir soneki (suffix) kastediliyor, hoca da "prefiks, safiks o demin gördüm" diye düzeltti. -->

Path için de baştaki eğik çizgi önemlidir: hoca bir örnekte `login` yolunun başlangıç noktası (`/`) verilmeden yazıldığı için ayarlanamadığını, bu eğik çizginin can sıkıcı durumlara yol açabileceğini söyledi.

Slayttaki bir başka not: "Most websites do not set domain. In this situation, cookie is scoped to the hostname the cookie was received over and is not sent to subdomains." Çoğu site domain ayarlamaz; bu durumda çerez, alındığı host adına bağlanır ve alt alan adlarına gönderilmez.

### 14.4 Politika çakışmaları (Policy Collisions)

Slayt (ekrandan, 02:05:00):

- Cookie SOP Policy: cs.stanford.edu/zakir cannot see cookies for cs.stanford.edu/dabo (cs.stanford.edu cannot see for cs.stanford.edu/zakir either).
- Are Dan's Cookies safe from Zakir? No.

```javascript
const iframe = document.createElement("iframe");
iframe.src = "https://cs.stanford.edu/dabo";
document.body.appendChild(iframe);
alert(iframe.contentWindow.document.cookie);
```

Çerez SOP'sine göre farklı path'ler yüzünden zakir sayfası dabo'nun çerezlerini göremez. Ama zakir sayfası bir iframe öğesi oluşturur, kaynağını cs.stanford.edu/dabo yapar, kendi doküman gövdesine ekler ve iframe'in penceresindeki `document.cookie`'yi okur. Zakir sayfası da cs.stanford.edu'dan geldiği ve iframe'i kendi dokümanına eklediği için Dan'in çerezlerine erişebilir. Yani çerezlerin path kuralı, DOM'daki scheme + domain + port kuralıyla çakışır.

> **Ek bilgi (derste anlatılmadı):** Bu çakışmanın nedeni, iki sayfanın DOM açısından aynı kökende olmasıdır: scheme (https), domain (cs.stanford.edu) ve port aynıdır. Path yalnız çerezlerin hangi isteğe ekleneceğini belirler; aynı kökenden bir sayfanın diğerinin DOM'una erişmesini engellemez. Bu yüzden path, bir güvenlik sınırı olarak kullanılmamalıdır.

### 14.5 Üçüncü taraf script ve kimlik çerezi

Hoca bunu "en tehlikeli soru" diye sordu: "If your bank includes Google Analytics JavaScript, can it access your bank's authentication cookie?" Cevap: evet. Bir önceki örnekteki gibi, dahil edilen script bankanın sayfasının kökeniyle çalışır ve `document.cookie` ile çerezlere erişebilir. Demek ki bankalar Google Analytics ya da benzeri JavaScript'leri başka yerlerden yüklememelidir.

Önlem olarak, çerezlerin `document.cookie` API'siyle erişilmesini engelleyen bir ayar vardır: HttpOnly çerez. Böylece Google Analytics'in ya da başka bir script'in çerezleri çalması engellenebilir. Hocanın özeti: ya böyle analitik içerik konmayacak ya da çerezler HttpOnly yapılacak. <!-- BELİRSİZ: HttpOnly örnek slaytı karede görülmedi (02:07:02-02:07:50). -->

## 15. Ağ Saldırganı ve Secure Çerezler

Son konu, saldırı modellerinden ağ saldırganıydı. Ağ saldırganı aradaki bağlantıda trafiği görebilir, değiştirebilir ya da düşürebilir. Hoca bunun sunucu tarafındaki ya da kötü niyetli içerik tarafındaki bir saldırgan olmadığını, ağ üzerinden saldırı yaptığını vurguladı.

Senaryo iki slaytın birleşimiyle anlatıldı. Birincisinde kullanıcı bankaya HTTPS ile güvenli bir bağlantı kurar, sorun yoktur; banka kimlik doğrulama çerezini (kimlik ve değeri) gönderir ve çerez tarayıcıda durur. İkincisinde tarayıcı aynı alan adına HTTP üzerinden (http://bank...) bir istek yapar; çerezler bu şifresiz istekle gider. Saldırgan bunları alır ve bankada kullanır, yani kullanıcının yerine giriş yapar. Çerezler tarayıcıya HTTPS üzerinden gönderilmişti, ama tarayıcıdan HTTP üzerinden çıkarıldı. <!-- BELİRSİZ: Ağ saldırganı senaryosunun slaytları karede görülmedi (02:08:18-02:09:16 arası altyazıda boşluk var); saldırganın HTTP isteğini nasıl tetiklediği anlatımdan çıkmıyor. -->

Çözüm, çerezleri güvenli (secure), şifreli biçimde göndermektir. Slayt (ekrandan, 02:10:00):

```text
Set-Cookie: id=a3fWa; Expires=Wed, 21 Oct 2015 07:28:00 GMT; Secure;
```

"A secure cookie is only sent to the server with an encrypted request over the HTTPS protocol." `Set-Cookie` başlığının sonuna `Secure` eklenirse çerez ancak ve ancak HTTPS ile çalışıldığında gönderilir. Önceki senaryodaki istek HTTP olduğu için çerez gönderilmez. Saldırganın bankanın HTTPS bağlantısına sahip olması çok düşük bir olasılık olduğundan, çerezleri elde etmesi de mümkün olmaz.

> **Hocanın vurgusu:** Kimlik çerezleri `Secure` özniteliğiyle gönderilmelidir; secure bir çerez yalnız HTTPS üzerinden alınıp verilebilir.

## Örnek Sorular

**Soru 1 (ekrandan, 00:30:00; derste sözlü, 00:31:38):** stanford.edu'dan gelen bir sayfa, başka bir alan adındaki resmi `<img>` etiketiyle yükleyebilir mi?

> **Cevap (derste verildi):** Evet. "Nothing prevents you from including images on a different domain." Resim yüklemeyi engelleyen bir kural yoktur; ama SOP sayfadaki JavaScript'in resmin piksellerini incelemesini engeller (Bölüm 11.1).

**Soru 2 (ekrandan, 00:55:00):** Kullanıcı bank.com'a giriş yapmışken `http://example.com` sayfasında `<img src="https://bank.com/transfer?fromAccount=X&toAccount=Y&amount=1000">` etiketi varsa ne olur?

> **Cevap (derste verildi):** Tarayıcı resmi yüklemek için bank.com'a `GET /transfer?...` isteği gönderir. Bir alan adı için ayarlanmış çerezler o alan adına yapılan her isteğe eklendiği için bank.com çerezleri de gider; istek kullanıcının oturumuyla işlenebilir. Bu yüzden durum değiştiren işlemler GET ile yapılmamalıdır.

**Soru 3 (derste sözlü, 01:28:53; ekrandan, 01:30:00):** Sayfalar farklı kökenlere istekte bulunabilir mi? SOP tam olarak neyi engeller?

> **Cevap (derste verildi):** Evet, istekte bulunabilir. SOP isteğin yapılmasını engellemez; JavaScript'in gelen HTTP cevabını (örneğin resmin piksellerini) doğrudan incelemesini engeller. Sayfa yalnız resmin boyutunu ve yüklenip yüklenmediğini öğrenebilir.

**Soru 4 (ekrandan, 01:35:00):** bank.com sayfası `<script src="jquery.com/jquery.min.js">` ile başka kökenden bir kütüphane yüklüyor. Bu script hangi yetkiyle çalışır, ne riski vardır?

> **Cevap (derste verildi):** Script, yüklendiği pencerenin kökeninin (bank.com) yetkileriyle çalışır. Kütüphane kötü niyetliyse bank.com'un çerezlerini, oturum verisini ve doküman içeriğini okuyabilir.

**Soru 5 (ekrandan, 01:55:00):** Bir isteğin "basit istek" sayılıp CORS pre-flight denetimi yapılmaması için hangi koşullar sağlanmalıdır?

> **Cevap (derste verildi):** Üç koşulun hepsi: yöntem GET, HEAD ya da POST; veri gönderiliyorsa içerik tipi `application/x-www-form-urlencoded`, `multipart/form-data` ya da `text/plain`; özel HTTP başlığı yok. Bunlar JavaScript olmadan da yapılabilen istekleri (form gönderme, resim ya da sayfa yükleme) taklit eder.

**Soru 6 (ekrandan, 02:00:00):** cookie1 (domain=login.site.com, path=/), cookie2 (domain=site.com, path=/) ve cookie3 (domain=site.com, path=/my/home) verildiğinde checkout.site.com, login.site.com, login.site.com/my/home ve site.com/account adreslerine hangi çerezler gönderilir?

> **Cevap (derste verildi):** Kural: çerezin domain'i URL domain'inin soneki ve çerezin path'i URL path'inin öneki olmalıdır. checkout.site.com: yalnız cookie2. login.site.com: cookie1 ve cookie2. login.site.com/my/home: üçü de. site.com/account: yalnız cookie2. Sonuçlar python ile yeniden hesaplanmış ve slayttaki tabloyla aynı çıkmıştır.

**Soru 7 (ekrandan, 02:05:00):** Çerez SOP'sine göre cs.stanford.edu/zakir, cs.stanford.edu/dabo çerezlerini göremez. Dan'in çerezleri Zakir'den güvende midir?

> **Cevap (derste verildi):** Hayır. Zakir'in sayfası dabo sayfasını bir iframe olarak kendi dokümanına ekler ve `iframe.contentWindow.document.cookie` ile çerezleri okur; iki sayfa aynı kökenden (cs.stanford.edu) geldiği için bu erişim engellenmez.

**Soru 8 (derste sözlü, 02:06:21):** Bankanız Google Analytics JavaScript'ini sayfasına ekliyorsa, bu script bankanın kimlik doğrulama çerezine erişebilir mi?

> **Cevap (derste verildi):** Evet. Eklenen script bankanın sayfasının kökeniyle çalışır ve `document.cookie` ile çerezlere erişebilir. Önlem: böyle üçüncü taraf script'leri yüklememek ya da kimlik çerezini HttpOnly yapmak.

## Dersin Toparlaması

Bu derste işletim sistemi güvenlik modelinin web'deki karşılığı kuruldu. Önce web'in neden kritik olduğu ve dört saldırı modeli (kötü niyetli site, kötü niyetli dış kaynak, ağ saldırganı, zararlı yazılım saldırganı) tanıtıldı. Ardından modelin yapı taşları ele alındı: durumsuz, düz metin HTTP; GET/POST/PUT/PATCH/DELETE metotları ve GET'in durum değiştirmemesi gerektiği; kaynak yükleme, frame/iframe, JavaScript ve DOM; HTTP/2'nin performans yenilikleri; durumsuzluğu aşmak için kullanılan ve her istekte otomatik gönderilen çerezler.

İkinci yarıda modelin merkezindeki Same Origin Policy işlendi. Köken (scheme + domain + port) web'de işletim sistemindeki kullanıcı kimliğinin yerini alır. Kökenler birbirinin nesnelerine erişemez. Ama istek yapmak serbesttir; engellenen, cevabın okunmasıdır. Başka kökenden yüklenen script ise yüklendiği sayfanın yetkisiyle çalışır. `document.domain` gevşetmesi ve Public Suffix List, CORS'un okuma (ACAO) ve gönderme (pre-flight) izinleri ile basit istekler, çerezlerin domain + path kapsam kuralı, bu kuralın DOM SOP'siyle çakışması, HttpOnly ve Secure çerezler bu çerçevede görüldü. Yol haritasına göre sonraki konu web zafiyetleri ve saldırılarıdır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
