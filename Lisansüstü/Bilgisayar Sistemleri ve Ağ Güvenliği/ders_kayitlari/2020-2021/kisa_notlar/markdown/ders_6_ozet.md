# Ders 6 Çalışma Özeti

## Genel Konular

- Web güvenliğine giriş ve web güvenlik modelinin amacı (ekrandan, 00:05:00)
  - Ders, işletim sistemi güvenlik modellerinden (Unix/Linux, Windows, izolasyon, en az yetki ilkesi) web tarafına geçer. Bölüm başlıkları: Web Security Model, Web Vulnerabilities and Attacks, HTTPS/TLS/Certificates, User Authentication and Session Management.
  - Web bugün standart kullanıcı arayüzüdür ve büyük kitlelere hizmet veren uygulamaların arka ucu da web teknolojisiyle çalışır. Bu yüzden en çok saldırıya açık ve saldırıda en çok etki yaratan ortamlardan biridir.
  - Amaç: ziyaret edilen bir site cihazdan veri çalamamalı, kötü amaçlı yazılım yükleyememeli, kameraya ve mikrofona izinsiz erişememeli. Bir sekmedeki A sitesi, başka sekmedeki ya da aynı sayfada frame/iframe ile yüklenmiş B sitesini etkileyememeli, onunla yapılan haberleşmeyi dinleyememeli.
  - Zoom gibi web protokolleri üzerine kurulu uygulamalar da aynı modelle güvenli olmalıdır.
- Dört saldırı modeli (ekrandan, 00:10:00 ve 00:15:00)
  - Malicious Website: kullanıcı doğrudan kötü niyetli bir siteye girer. Bu site başka sekmedeki banka oturumuyla etkileşememeli, Facebook/Gmail gibi oturumların kimlik bilgilerini (credential) çalamamalı, yerel dosyalara erişememeli, yerel ağda port taraması yapamamalı.
  - Malicious External Resource: güvenilir sanılan bir site ele geçirilmiş ya da kötü içerik dolaylı yoldan gelir. Örnekler: SQL injection ile ele geçirilip zararlı kod yerleştirilen siteler, kullanıcı forumlarındaki linkler ve aktif içerik, sayfadaki üçüncü taraf reklam alanları.
  - Network Attacker: aradaki router ya da DNS sunucusu ele geçirilir; saldırgan trafiği dinler, değiştirir ya da kullanıcıyı aynı görünüşlü sahte bir siteye yönlendirir.
  - Malware Attacker: tarayıcıdaki ve işletim sistemindeki izolasyon önlemleri aşılır, zararlı yazılım tarayıcının içinde çalışmaya başlar ve sistemi ele geçirir.
- HTTP protokolü (ekrandan, 00:20:00 ve 00:25:00)
  - 1989'da CERN'de, araştırma sonuçlarının hızla paylaşılması için geliştirildi. Öncülleri FTP ve Gopher'dı.
  - Durumsuz (stateless) tasarlandı: istek (request) ve cevap (response) olmak üzere iki mesaja dayanır. Oturum (session) için durumun sonradan başka yolla tutulması gerekir.
  - URL bileşenleri: scheme (protokol), domain (sunucu), port, path, query string ve fragment ID.
  - HTTP düz metindir (temelde ASCII). İstek örneği karede: `GET /index.html HTTP/1.1`, `Accept`, `Accept-Language: en`, `Connection: Keep-Alive`, `User-Agent`, `Host`, `Referer` başlıkları. Gövde boş olsa da bu kadarı bir istek için yeterlidir.
  - Cevapta durum kodu gelir (100, 200, 300, 400, 500 aileleri); 200 "OK" demektir. Başlıklarda tarih, sunucu, içerik tipi ve içerik uzunluğu bulunur.
- HTTP metotları (ekrandan, 00:25:00)
  - GET: verilen URL'deki kaynağı alır, mesaj gövdesi kabul etmez. POST: URL'de yükle (payload) yeni kaynak oluşturur, parametre taşıdığı için dinamiktir. PUT: hedef kaynağı yükle değiştirir. PATCH: kaynağın bir kısmını günceller. DELETE: URL'yi siler.
  - GET sunucuda durum değişikliğine yol açmamalıdır; ama gerçekleştirmelerdeki hatalar yüzünden açabiliyor. Eski tarayıcılar PUT/PATCH/DELETE'i neredeyse hiç desteklemez; bugün isteklerin çoğu POST ile yapılır.
- Kaynak yükleme, frame/iframe ve JavaScript (ekrandan, 00:30:00 ve 00:35:00)
  - Kök HTML sayfası resim, video, font gibi ek kaynaklar içerir; tarayıcı HTML'i ayrıştırıp bunlar için ayrı istek yapar (`GET /img/usr.jpg`).
  - Başka alan adından resim yüklemeyi engelleyen bir kural yoktur.
  - Frame: katı, sınırları görünür bölümleme. iFrame: floating inline frame, sınırı görünmeyebilir. Kullanım nedenleri: içeriği başka sitelerle zenginleştirmek, reklam yüklemek, yükü farklı kaynaklara dağıtmak.
  - JavaScript tarayıcının içinde yorumlanarak çalışır. Ek web isteği yapabilir, sayfayı değiştirebilir, tarayıcı verisini ve yerel donanımı okuyabilir; bugün son derece güçlüdür.
- Document Object Model (DOM) (ekrandan, 00:40:00)
  - Tarayıcı HTML'i yapılandırılmış veriye (DOM ağacına) dönüştürür: document, html, head, title, body, h1, a (href özniteliği) gibi düğümler.
  - JavaScript DOM'u nesne yönelimli bir arayüzle okur ve yazar. Örnek: `document.getElementById('demo').innerHTML = Date()`.
  - Tarayıcı kök sayfadan başlar, HTML'i ayrıştırır, JavaScript'i çalıştırır, alt kaynakları (resim, CSS, script, iframe) yükleyip aynı işlemi onlara da uygular ve klavye, fare, yükleme, zamanlayıcı olaylarını yakalar.
- HTTP/2 (ekrandan, 00:45:00)
  - 2015'te yayımlandı, Google'ın SPDY protokolüne dayanır. Uygulamaların yapısını değiştirmez, değişiklikler çoğunlukla performans içindir.
  - Birden çok nesne için isteklerin ardışık iletimi (pipelining), tek TCP bağlantısı üzerinde çoğullama (multiplexing), başlık sıkıştırma ve server push.
- HTTP çerezleri (cookies) (ekrandan, 00:50:00 ve 00:55:00)
  - Çerez, sunucunun tarayıcıya gönderdiği küçük bir veridir; tarayıcı onu saklayıp sonraki isteklerde geri gönderebilir ("may").
  - Kullanım: oturum yönetimi (login, alışveriş sepeti, oyun skoru), kişiselleştirme (tema, tercihler), izleme (kullanıcı davranışını kaydetme).
  - Çerezi sunucu başlatır (`Set-Cookie`); geri gönderip göndermemeye tarayıcı karar verir. Gönderilmeye karar verildiyse o alan adına yapılan her istekte gönderilir.
  - Login oturumu: GET ile login formu, POST ile kullanıcı adı/şifre; başarılı girişten sonra sunucu bir session ID üretir ve sonraki her istekte bu çerez gönderilir.
  - "...for better or worse": başka bir sayfadaki `<img src="https://bank.com/transfer?fromAccount=X&toAccount=Y&amount=1000">` isteği de bank.com çerezleriyle gider.
- Modern web sitesi (Los Angeles Times örneği)
  - LA Times ana sayfası yaklaşık 270 IP adresinden, 58 ağdan ve 8 ülkeden 540 kaynak yükler; CNN 361 kaynak yükler. Bunların çoğu ana sitenin denetiminde değildir; sayfadan 51 çerez gelir.
- Aynı köken politikası (Same Origin Policy, SOP) (ekrandan, 01:15:00 ve 01:20:00)
  - Unix modeliyle eşleme: subject (kim) = origin, yani scheme + domain + port; object (ne) = DOM ağacı, yerel depolama, çerezler, donanım izinleri, JavaScript isim alanları; how = GET/POST gibi erişimler.
  - Hedef: gizlilik (confidentiality, okuma) ve bütünlük (integrity, değiştirme).
  - Her pencere (window) ve çerçevenin (frame) bir kökeni vardır; kökenler başka kökenlerin nesnelerine erişemez. Köken, JavaScript için işletim sistemindeki kullanıcı kimliğinin (user ID) karşılığıdır.
  - BroadcastChannel API: aynı kökenli script'ler pencereler, sekmeler, iframe'ler ve worker'lar arasında yayın/abone (pub/sub) mesajlaşması yapabilir (ekrandan, 01:25:00).
  - Ebeveyn-çocuk ilişkili pencere/çerçeveler `postMessage` ile mesajlaşabilir; mesajlaşmak, içeriğe erişmekle aynı şey değildir.
- SOP'nin HTTP cevaplarına, resimlere, CSS/fontlara, çerçevelere ve script'lere uygulanışı (ekrandan, 01:30:00 ve 01:35:00)
  - Sayfalar başka kökenlere istek yapabilir; SOP isteği engellemez, cevabın incelenmesini engeller (resmin piksellerine erişilemez, yalnız boyutu ve yüklenip yüklenmediği bilinir).
  - CSS ve fontlar başka kökenden yüklenip kullanılabilir ama içeriği incelenemez. Başka kökenli HTML frame'e yüklenebilir, içeriği incelenemez ve değiştirilemez.
  - Script'ler başka kökenden yüklenebilir ve yüklendikleri pencere/çerçevenin kökeninin yetkileriyle çalışır. Kaynak kodu görülemez ama fonksiyonları çağrılabilir. Kötü niyetli bir kütüphane yüklenirse çerez gibi verileri çalabilir.
- Domain relaxation ve Public Suffix List (ekrandan, 01:40:00 ve 01:45:00)
  - Facebook'un kendi CDN alt alan adından frame yüklemesi gibi meşru durumlar için `document.domain` ile kısıt gevşetilebilir.
  - `com` gibi bir üst sonek seçmek uygun değildir; altında milyonlarca alan adı olabilir. Hangi soneklerin kamuya açık olduğu Mozilla'nın başlattığı Public Suffix List'te tutulur (süper çerezleri önlemek, alan adının önemli kısmını vurgulamak, geçmişi siteye göre sıralamak).
  - Relaxation saldırısı: cs155.stanford.edu kendini stanford.edu'ya gevşetirse Stanford girişini çalabilir. Çözüm: veri paylaşımı için iki taraf da `document.domain` ayarlamalıdır.
- JavaScript istekleri ve CORS (ekrandan, 01:50:00 ve 01:55:00)
  - JavaScript XHR (`XMLHttpRequest`) ya da jQuery ile ağ isteği yapabilir (form göndermek, ek içerik yüklemek).
  - Kural: hedef köken izin vermedikçe başka kökene istek yapılamaz; cevap yalnız aynı kökenden geliyorsa ya da hedef izin verdiyse okunabilir.
  - CORS okuma izni: sunucu `Access-Control-Allow-Origin` (ACAO) başlığı ekler. Gönderme izni: tarayıcı önce OPTIONS ile "pre-flight" denetimi yapar, sunucu kabul ederse asıl POST'u gönderir, etmezse tarayıcı hata döndürür.
  - Joker köken (`*`): içerik her kökenden okunabilir, SOP'nin anlamı kalmaz.
  - Basit istekler pre-flight yapmaz: yöntem GET, HEAD ya da POST; içerik tipi `application/x-www-form-urlencoded`, `multipart/form-data` ya da `text/plain`; özel HTTP başlığı yok.
- Çerezlerde SOP (ekrandan, 02:00:00 ve 02:05:00)
  - Çerezlerde köken scheme + domain + port değil, domain + path ile tanımlanır.
  - Çerez gönderilir ⟺ çerezin domain'i URL domain'inin soneki ve çerezin path'i URL path'inin önekidir.
  - Siteler kapsamı kendi domain'inin bir soneki ve path'in bir öneki olarak ayarlayabilir; üst alan adı alt alan adı için çerez ayarlayamaz. Domain ayarlanmazsa çerez yalnız alındığı host'a bağlanır, alt alan adlarına gönderilmez.
  - Policy collision: cs.stanford.edu/zakir, cs.stanford.edu/dabo çerezlerini path kuralıyla göremez; ama dabo sayfasını iframe olarak ekleyip `iframe.contentWindow.document.cookie` ile okuyabilir.
  - Bankanın yüklediği Google Analytics script'i bankanın kimlik çerezine erişebilir; önlem: böyle script yüklememek ya da çerezi HttpOnly yapmak.
  - Ağ saldırganı HTTP üzerinden giden çerezleri görebilir; `Secure` özniteliği çerezin yalnız HTTPS ile şifreli istekte gönderilmesini sağlar (ekrandan, 02:10:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Web güvenlik modeli işletim sistemi modelinin aynısıdır
  - Subject/object/erişim üçlüsü web'de origin/DOM-çerez-depolama/HTTP metotları olarak karşılık bulur. Script, yüklendiği pencerenin kökeni adına çalışır; işletim sistemindeki süreç sahibi gibi.
- Bu kuralları tarayıcı uygular
  - SOP kendiliğinden işlemez; tarayıcıda gerçekleştirilmiş güvenlik denetimleri sayesinde işler.
- Durum değiştiren işlem GET ile yapılmamalı
  - GET var olanı olduğu gibi almak içindir. Durum değiştiren ya da yetkilendirme gerektiren istek POST ile yapılmalıdır.
- İstek yapmak ile cevabı okumak farklıdır
  - SOP başka kökene istek yapılmasını ve resim/CSS/font/frame yüklenmesini engellemez; JavaScript'in cevabın içini incelemesini engeller.
- Başka kökenden script yüklemek tehlikelidir
  - Dahil edilen script, dahil edildiği sayfanın yetkileriyle çalışır. Bankalar Google Analytics gibi script'leri yüklememeli ya da çerezleri HttpOnly yapmalıdır.
- Çerezlerde köken domain + path'tir
  - Diğer nesnelerdeki scheme + domain + port tanımıyla karıştırılmamalıdır.
- Secure çerez
  - Kimlik çerezleri HTTPS üzerinden alınıp yalnız HTTPS ile gönderilmelidir; aksi halde ağ saldırganı HTTP isteğinden çerezi alıp kullanıcının yerine giriş yapabilir.

## Kısa Tekrar Notları

- Dört saldırı modeli: kötü niyetli site, kötü niyetli dış kaynak, ağ saldırganı, zararlı yazılım saldırganı.
- HTTP: 1989, CERN, durumsuz, istek/cevap, düz metin.
- URL: scheme, domain, port, path, query, fragment.
- GET gövde almaz ve durum değiştirmemeli; POST yükle kaynak oluşturur; PUT değiştirir, PATCH kısmen günceller, DELETE siler.
- DOM: tarayıcının HTML'den kurduğu nesne ağacı; JavaScript onu okur ve yazar.
- HTTP/2: 2015, SPDY tabanlı; pipelining, tek TCP üzerinde multiplexing, başlık sıkıştırma, server push.
- Çerez: sunucu `Set-Cookie` ile gönderir, tarayıcı saklayıp aynı alan adına her istekte geri gönderir. Kullanım: oturum, kişiselleştirme, izleme.
- SOP: köken = scheme + domain + port; her pencere/çerçevenin kökeni var; başka kökenin nesnesine erişilemez.
- Aynı köken arası mesaj: BroadcastChannel; ebeveyn-çocuk arası: `postMessage`.
- Başka kökenden istek yapılabilir, cevap incelenemez; script başka kökenden yüklenir ama sayfanın kökeniyle çalışır.
- `document.domain` gevşetmesi iki tarafça yapılmalı; kamuya açık sonekler Public Suffix List'te.
- CORS: okuma için ACAO başlığı, gönderme için OPTIONS pre-flight; basit istekler (GET/HEAD/POST, standart içerik tipi, özel başlık yok) pre-flight yapmaz.
- Çerez kapsamı: domain soneki ve path öneki. HttpOnly → `document.cookie` ile okunamaz; Secure → yalnız HTTPS.

## Detaylı Açıklamalar

- Web güvenliğinin çıkış noktası, işletim sistemi derslerindeki izolasyon düşüncesidir. Kullanıcı bir sitede gezinirken o site hem kullanıcının sisteminden hem de aynı anda açık olan diğer sitelerden yalıtılmalıdır. Yalıtım sınırının birimi "köken"dir (origin): scheme, domain ve port üçlüsü. Bir sayfa ya da script, hangi kökenden yüklendiyse o kökenin "kullanıcısı" gibi çalışır ve yalnız o kökenin nesnelerine (DOM, çerezler, yerel depolama) erişebilir. Bu, Unix'teki süreç sahibine göre yetkilendirmenin web'deki karşılığıdır.
- HTTP'nin durumsuz olması oturum kavramını zorlaştırır. Çerezler bu boşluğu doldurur: sunucu `Set-Cookie` ile bir değer gönderir, tarayıcı bunu saklarsa aynı alan adına yaptığı her isteğe ekler. Login senaryosunda ilk GET'te çerez yoktur, kullanıcı adı ve şifre POST ile gider, sunucu bir session ID üretip çerez olarak döndürür; sonraki resim ve hesap sayfası istekleri bu çerezle gider ve yeniden giriş gerekmez. Çerezin her istekte otomatik gitmesi aynı zamanda bir risktir: başka bir sitedeki `<img>` etiketi bank.com'a para transferi isteği yaptırırsa tarayıcı bank.com çerezlerini de ekler.
- SOP'nin ince noktası, isteği değil cevabın okunmasını engellemesidir. attacker.com bank.com'daki bir resmi yükleyebilir ve istek çerezlerle gider; ama attacker.com'daki JavaScript resmin piksellerine erişemez, yalnız boyutunu ve yüklenip yüklenmediğini öğrenir. Aynı mantık CSS, font ve frame için geçerlidir. Script'te durum terstir: başka kökenden yüklenen script, kendisini yükleyen sayfanın kökeniyle çalışır. CDN'den güvenilir bir kütüphane yüklemek sayfayı değiştirmek için kullanışlıdır; ama kötü niyetli bir kütüphane aynı yetkiyle çerezleri çalabilir.
- JavaScript'in yaptığı ağ istekleri için CORS (Cross-Origin Resource Sharing) devreye girer. Okuma izni sunucunun `Access-Control-Allow-Origin` başlığıyla verilir. Basit olmayan istekler için tarayıcı önce bir OPTIONS isteği göndererek sunucunun bu kökenden istek kabul edip etmediğini sorar (pre-flight); izin gelirse asıl isteği gönderir, gelmezse hata döndürür. Form gönderme, resim ya da sayfa yükleme gibi JavaScript olmadan da yapılabilen "basit" istekler pre-flight yapmaz.
- Çerezler için köken farklı tanımlanır: domain ve path. Çerez, domain'i URL'nin domain'inin soneki ve path'i URL'nin path'inin öneki olduğunda gönderilir. Bu path ayrımı tek başına koruma sağlamaz: cs.stanford.edu/zakir sayfası cs.stanford.edu/dabo sayfasını iframe olarak ekleyince iki sayfa aynı kökendedir (scheme + domain + port aynı) ve `iframe.contentWindow.document.cookie` ile dabo'nun çerezleri okunur. Aynı nedenle bankanın sayfasına eklenmiş üçüncü taraf bir analiz script'i bankanın kimlik çerezini okuyabilir; HttpOnly çerezler `document.cookie` ile okunamaz. Ağ saldırganına karşı ise `Secure` özniteliği kullanılır: çerez yalnız HTTPS üzerinden gönderilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
