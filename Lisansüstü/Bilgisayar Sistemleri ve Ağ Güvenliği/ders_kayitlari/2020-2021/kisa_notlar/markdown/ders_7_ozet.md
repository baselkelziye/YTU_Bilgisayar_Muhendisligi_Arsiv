# Ders 7 Çalışma Özeti

## Genel Konular

- Önceki dersin tekrarı: Same Origin Policy, CORS ve çerezler (ekrandan, 00:55:00 ve 01:00:00)
  - DOM Same Origin Policy: bir site her kaynaktan içerik yükleyebilir (ör. `attacker.com` sayfasındaki `<img src="bank.com/img/usr.jpg">`), ama istekte bulunan sitedeki JavaScript başka bir kökenden gelen içeriğin kendisini inceleyemez.
  - `Access-Control-Allow-Origin` başlığıyla sunucu, içeriğine hangi kökenlerin erişebileceğini bir beyaz liste olarak bildirir. Basit GET/POST istekleri doğrudan yapılır; sunucuya yük getirecek isteklerde tarayıcı önce HTTP `OPTIONS` ile ön kontrol (pre-flight) yapar, izin varsa asıl isteği gönderir.
  - Çerezler domain ve path üzerinden eşleştirilir. Kapsamı tutan bütün çerezler istisnasız her istekte gönderilir. Domain boşsa çerez yalnız onu gönderen host'a geri gider.
  - Çerez kapsamı ayarı: `cs155.stanford.edu`, hem kendisi hem `stanford.edu` için çerez ayarlayabilir; `stanford.edu` ise `cs155.stanford.edu` için ayarlayamaz. Aynı kural path için de geçerlidir: `website.com/login`, `website.com/` için ayarlayabilir; tersi olmaz (ekrandan, 01:00:00).
  - DOM tarafında SOP path ayrımı yapmaz. Bu yüzden aynı domain altındaki başka bir path'in çerezi JavaScript ile okunabilir. Başka kökenden yüklenen JavaScript (ör. bir analiz betiği ya da kütüphane) sayfanın kökeninin yetkisiyle çalışır.
  - `HttpOnly` çerezler JavaScript ile okunamaz, yalnız HTTP isteklerinde gider. `Secure` çerezler yalnız HTTPS bağlantısında gönderilir.
- Oturum ele geçirme (Session Hijacking) (ekrandan, 01:05:00)
  - Ağ dinleme, kötü niyetli JavaScript ya da başka bir yolla çerezleri yakalayıp kullanıcının oturumunu çalmaya Session Hijacking saldırısı denir.
  - Daha önce görülen buffer overflow ve integer overflow saldırıları "control hijacking" (kontrolün ele geçirilmesi) idi; burada ele geçirilen şey oturumdur. Çerezler, birbirinden bağımsız istek-yanıtları bir oturum hâline getirmek için vardır.
- Cross-Site Request Forgery (CSRF)
  - Tanım: web uygulamasına, uygulamanın kimliğini doğrulamış ve güvendiği bir kullanıcı adına istek göndermek. Kullanıcı, kendi isteği olmayan ve çoğu zaman fark etmediği bir isteği siteye göndermeye kandırılır.
  - Çerez tabanlı kimlik doğrulama tek başına yeterli değildir; özellikle yan etkisi olan (para transferi gibi veriyi değiştiren) isteklerde. Çerezler kapsam tuttuğu her isteğe eklendiği için isteği yetkili bir uygulamanın gönderip göndermediğini göstermez (ekrandan, 01:10:00).
  - Yaygın dört savunma: Referer doğrulama, gizli doğrulama jetonu (secret validation token), özel HTTP başlığı (custom header), sameSite çerezleri. Bunlar birlikte, katmanlı biçimde kullanılmalıdır.
- Referer doğrulama (ekrandan, 01:15:00)
  - `Referer` istek başlığı, istenen sayfaya bağlantının izlendiği önceki sayfanın adresini taşır; sunucu ziyaretçinin nereden geldiğini görür.
  - Slayttaki üç durum: `https://bank.com` → `https://bank.com` kabul; `https://attacker.com` → `https://bank.com` ret; Referer yok → `https://bank.com` belirsiz ("??"). Referer yoksa adres çubuğuna yazılarak mı gelindi, başka bir şey mi oldu bilinemez.
- Gizli jeton üretimi (ekrandan, 01:20:00)
  - Banka her formun içine `type="hidden"` bir alan koyar (slaytta `name="csrf_token"`). Alanın adı değil değeri önemlidir ve tahmin edilemez olmalıdır.
  - Statik jeton işe yaramaz: saldırgan transfer sayfasını kendi tarafında (out of band) yükleyip jetonun adını ve değerini öğrenir.
  - Doğrusu, oturuma özgü jetonu sayfanın parçası olarak göndermektir. Saldırganın tarayıcıya soktuğu JavaScript bu değeri okuyamaz, çünkü SOP başka kökenden gelen içeriğin okunmasını engeller.
- Özel HTTP başlığı
  - `XMLHttpRequest` ile gönderilen isteğe standart dışı bir başlık eklenir (genelde `X-` önekli, örneğin "X-Requested-By"). Özel başlık bulunduğu için tarayıcı ön kontrol (pre-flight) yapmak zorunda kalır, sunucunun izni olmadan istek gitmez. Normal GET/POST formlarında bu başlık yoktur.
- sameSite çerezleri (ekrandan, 01:25:00)
  - Tarayıcının çerezi siteler arası (cross-site) isteklerle göndermesini engelleyen çerez seçeneğidir; `Secure` gibi çerez tanımına eklenir.
  - Strict: hiçbir siteler arası bağlamda, sıradan bir bağlantı izlenirken bile çerez gönderilmez. E-postadaki özel bir GitHub projesi bağlantısına tıklayan kullanıcı oturum çerezi gitmediği için yeniden giriş yapmak zorunda kalır.
  - Lax: sıradan bağlantılar izlenirken oturum çerezine izin verir, ama POST gibi CSRF'e açık istek yöntemlerinde engeller.
- Kimliği doğrulanmış oturumların ötesi (ekrandan, 01:30:00)
  - Her saldırı oturum açmış kullanıcının çerezini kötüye kullanmaz. Örnek: yerel router'a varsayılan parolayla giren ve DNS ayarlarını değiştirerek trafiği kaçıran bir betik. Bir siteye giriş yapmak da yan etkisi olan bir istektir.
- Web saldırılarının sıralaması
  - Hoca 2013 ve 2017 listesini karşılaştırdı: iki yılda da birinci sırada Injection, ikinci sırada Broken Authentication and Session Management var. Cross-Site Scripting üçüncü sıradan yedinciye düşmüş. Insecure Direct Object References ile Missing Function Level Access Control, 2017'de "Broken Access Control" altında birleştirilmiş. <!-- BELİRSİZ: listenin slaytı karelerde yok; sıralar altyazıdan alındı. -->
- Komut enjeksiyonu (Command Injection) (ekrandan, 01:35:00)
  - Amaç sistemde keyfi komut çalıştırmaktır; geliştirici güvenilmeyen kullanıcı verisini kabuğa (shell) aktardığında olur.
  - `head100` örneği: `argv[1]` uzunluğu artı 100 baytlık yer ayrılır, `"head -n 100 "` kopyalanır, arkasına `argv[1]` eklenir ve `system(cmd)` çağrılır. Normal kullanım `head100 myfile.txt` ilk 100 satırı listeler.
  - Saldırgan argümanı çift tırnak içinde, noktalı virgülle ayrılmış ikinci bir komutla verir; kabuk iki komutu da çalıştırır. Sorun, girdinin temizlenmemesidir (sanitization). <!-- BELİRSİZ: saldırganın girdiği tam komut karelerde yok. -->
- SQL enjeksiyonu (ekrandan, 01:40:00)
  - Giriş formu sorgusu: `SELECT id FROM users WHERE uid = '$u' AND pwd = '$p'`; sonuç kümesinde satır varsa giriş başarılı sayılır.
  - Parola `123'` girilirse fazladan tek tırnak SQL sözdizimi hatası verir.
  - Kullanıcı adı `zakir'--`: `--` sonrası yorum olur, parola koşulu düşer; parolayı bilmeden girilir.
  - Kullanıcı adı `' or 1=1 --`: `1=1` her zaman doğru olduğu için hiçbir kullanıcı bilinmeden girilir.
  - `'; DROP TABLE users --` ile tablo silinebilir (SQL'de deyimler noktalı virgülle ayrılır).
  - MS SQL Server'da `xp_cmdshell` ile komut satırı çalıştırılabilir; çıktı satır satır tablo olarak döner. `net user` ile yeni bir kullanıcı eklenebilir. SQL Server Windows'ta yerel sistem hesabıyla çalıştığı için bu komutlar onun yetkisiyle yürür.
- SQL enjeksiyonunu önleme (ekrandan, 01:45:00)
  - Kullanıcı girdisine asla güvenme, SQL komutlarını elle (string birleştirerek) kurma.
  - Parametreli (prepared) SQL: sorgu önceden hazırdır, `?` yerlerine yalnız parametre aktarılır, temizlik ve doğrulama bu işi yapan katmanda yapılır. Sorgu planı önbelleğe alındığı için tekrar çalıştırmada daha hızlıdır.
  - ORM (Object Relational Mapper): nesneleri tablolara eşler; içeride prepared SQL kullanır.
- Cross-Site Scripting (XSS) (ekrandan, 01:50:00)
  - Uygulama güvenilmeyen veriyi doğrulamadan ve temizlemeden tarayıcıya gönderdiğinde olur.
  - Fark: komut/SQL enjeksiyonunda saldırganın kodu uygulama sunucusunda, XSS'te kurbanın tarayıcısında çalışır.
  - Arama örneği: arama terimi sayfaya "Results for ..." diye yazılır. Terim yerine `<script>` girilirse tarayıcı betiği çalıştırır; bu yolla çerez çalınabilir.
  - İki tür: reflected (betik, kurban sitesinden gelen sayfanın parçası olarak kullanıcıya geri yansır) ve stored (betik, uygulamanın yönettiği bir kaynakta, örneğin veritabanında saklanır ve sayfa oluşturulurken gelir).
  - Reflected örnek: PayPal kullanıcıları e-postayla gerçek PayPal sitesindeki bir URL'ye yönlendirildi, enjekte kod hesabın ele geçirildiği uyarısını gösterip kullanıcıyı oltalama sitesine taşıdı.
  - Stored örnek: Samy Worm, MySpace'te yayılan XSS tabanlı solucan; kurban profiline "but most of all, samy is my hero" yazıyor ve Samy'ye arkadaşlık isteği gönderiyordu. 20 saatte bir milyon kullanıcıya yayıldı (ekrandan, 01:55:00). MySpace `script`, `body`, `onclick`, `href` içindeki javascript'i filtrelemişti ama `div` style'ının background alanını atlamıştı.
- XSS filtreleme ve savunmalar
  - Başlıklar, çerezler, query string'ler, form alanları ve gizli alanlar dahil bütün girdiler filtrelenmeli; ama filtreleme çok zordur. Kodlanmış (encode edilmiş) bir `img` kaynağıyla Google'ın XSS filtresi bile atlatılmıştır. Yalnız olay işleyicileri (onsubmit, onerror vb.) 105 kadardır.
  - Kendi filtrenizi yazmak tehlikelidir; web çatılarının filtrelerine de körü körüne güvenilmemelidir.
- Content Security Policy (CSP) (ekrandan, 02:00:00)
  - Beyaz liste, kara listeden her zaman daha güvenlidir. CSP, betik ve diğer kaynakların yüklenebileceği güvenilir kökenleri listeler; tarayıcı yalnız bunlardan gelen betikleri çalıştırır, satır içi betikleri ve olay işleyici HTML özniteliklerini yok sayar.
  - `default-src 'self'`: içerik yalnız sayfanın geldiği domain'den yüklenir; satır içi script ve style çalışmaz. `img-src *` her yerden resme, `script-src` ile yalnız belirtilen CDN'den betiğe izin verilir.
- Subresource Integrity (SRI)
  - CSP ile izin verilen CDN ele geçirilirse sorun çıkar. Gerçek olay: işten ayrılan bir mühendisin hesabı kapatılmadığı için saldırganlar Bootstrap CDN'e erişip Bootstrap JavaScript'ini değiştirdi; onu kullanan uygulamalar hemen etkilendi.
  - SRI'da sayfa, yüklenen dosyanın SHA-256 özetini de belirtir. Tarayıcı inen içeriğin özetini hesaplar; eşitse çalıştırır, değilse çalıştırmaz.

## Hocanın Özellikle Vurguladığı Kısımlar

- Çerezler kapsam tuttuğu sürece her istekte istisnasız gönderilir.
  - Hoca bunu "üzerine basa basa" tekrarladı. CSRF'in kökü budur: çerez, isteğin gerçekten kullanıcıdan geldiğini kanıtlamaz, bu yüzden ek mekanizma gerekir.
- Tek bir savunma hattı yetmez.
  - Dört CSRF savunması bir arada, birbirini tamamlayan katmanlar olarak uygulanmalıdır.
- CSRF jetonu statik değil, oturuma özgü ve dinamik olmalıdır.
  - Statik jeton saldırgan tarafından dışarıdan öğrenilir; dinamik jetonu ise SOP sayesinde saldırganın JavaScript'i okuyamaz.
- XSS'te kod tarayıcıda, enjeksiyonda sunucuda çalışır.
  - Hoca bu ayrımın unutulmamasını özellikle istedi.
- Filtrelemeyi kendiniz yazmayın, hazır filtrelere de körü körüne güvenmeyin.
  - Bütün durumları düşünmeyen bir filtre, korunduğunuz sanısıyla büyük bir açık bırakır.
- Yan etki yalnız para transferi değildir.
  - Router'a giriş yapmak da yan etkisi olan bir istektir; DNS ayarı değişince kullanıcı saldırganın istediği sahte siteye yönlendirilebilir.

## Kısa Tekrar Notları

- Session hijacking: çerezi çalıp oturumu ele geçirmek (ağ dinleme, kötü JavaScript vb.).
- `HttpOnly`: JavaScript okuyamaz. `Secure`: yalnız HTTPS. `SameSite`: siteler arası istekte gönderme kısıtı (Strict / Lax).
- CSRF: kullanıcı farkında olmadan, onun çereziyle siteye istek gönderilir.
- CSRF savunmaları: Referer doğrulama, gizli jeton, özel başlık (pre-flight zorlanır), sameSite çerez.
- Referer yoksa durum belirsizdir; formdaki oturuma özgü gizli jeton kontrol edilir.
- Komut enjeksiyonu: temizlenmemiş girdi `system()` ile kabuğa gider; `;` ile ikinci komut çalışır.
- SQL enjeksiyonu: `'` sözdizimi hatası, `--` yorum, `' or 1=1 --` her zaman doğru, `; DROP TABLE`, MS SQL `xp_cmdshell`.
- Önleme: prepared (parametreli) SQL ya da ORM; sorgu elle kurulmaz.
- XSS: reflected (yansıyan) ve stored (saklanan). Örnekler: PayPal (reflected), Samy Worm (stored, 20 saatte bir milyon kullanıcı).
- CSP: beyaz listeye göre kaynak yükleme; satır içi betik çalışmaz.
- SRI: CDN dosyasının SHA-256 özeti tarayıcıda karşılaştırılır.

## Detaylı Açıklamalar

- Çerez ve SOP tekrarının amacı
  - Ders, saldırılara geçmeden önceki haftanın slaytlarını hızla tekrar etti. Çerez kapsamı slaytında alt domain kendisini kapsayan üst domain için çerez ayarlayabilir, üst domain alt domain için ayarlayamaz. Domain alanı boş bırakılan çerez yalnız onu gönderen host'a döner; bu yüzden `stanford.edu`'dan alınmış böyle bir çerez `www.stanford.edu`'ya gitmez, çünkü `www` ayrı bir host'tur. Path ayrımı ise sunucuya gönderimde işe yarar ama DOM'da SOP path'e bakmadığı için aynı domaindeki başka bir path'teki JavaScript çerezi okuyabilir. Bankanın sayfasına başka kökenden bir JavaScript yüklenirse betik pencerenin kökeninin yetkisiyle çalışır; bu da çerezlerin okunması demektir.
- CSRF'in işleyişi
  - Web uygulaması kullanıcıyı bir kez doğruladıktan sonra her istekte kullanıcı adı ve parola sormamak için çerez gönderir. Kötü niyetli bir site kullanıcının tarayıcısının bu çerezle bankaya bir istek (ör. `POST /transfer`) göndermesini sağlarsa uygulama isteğin güvendiği kullanıcıdan geldiğini düşünür ve işlemi yapar. Hoca burada bir "tavuk-yumurta" ilişkisi görür: çerez kimlik doğrulama için vardır, ama kötü senaryoda tam da bu özelliği saldırıyı mümkün kılar.
- Gizli jeton neden işe yarar?
  - Slayttaki form (ekrandan, 01:20:00):

    ```html
    <form action="https://bank.com/transfer" method="post">
      <input type="hidden" name="csrf_token" value="434ec7e838ec3167ef5">
      <input type="text" name="to">
      <button type="submit">Transfer!</button>
    </form>
    ```

  - Saldırganın gönderdiği sahte formda bu alan yoksa ya da değeri yanlışsa banka isteğin kendi sayfasından gelmediğini anlar. Değer her oturumda yeniden üretilir. SOP, saldırganın betiğinin bankadan gelen sayfanın içeriğini okumasını engellediği için jeton gizli kalır.
- Komut enjeksiyonu kodu
  - Slayttaki kod (ekrandan, 01:35:00) yalnız `main` gövdesidir; başlık dosyaları eklenince `gcc -Wall` ile uyarısız derlendi. 150 satırlık bir dosyada 100 satır bastı; noktalı virgülle eklenen zararsız bir ikinci komut (`echo`) da çalıştı. Bu deneme ajan tarafından yapıldı, derste çalıştırılmadı.

    ```c
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int main(int argc, char **argv) {
        char *cmd = malloc(strlen(argv[1]) + 100);
        strcpy(cmd, "head -n 100 ");
        strcat(cmd, argv[1]);
        system(cmd);
    }
    ```

- SQL enjeksiyonu kodu
  - Slayttaki PHP benzeri kod (ekrandan, 01:40:00): `$u = $_POST['login'];`, parola `$_POST['password']`, `$sql = "SELECT id FROM users WHERE uid = '$u' AND pwd = '$p'";`, `$rs = $db->executeQuery($sql);`, `if $rs.count > 0 { // success }`. Parola `123'` olunca sorgu `... pwd = '123''` olur ve SQL Syntax Error verir. Dört durum sqlite3 ile denendi (ajan testi): doğru sözdizimli sorgu hata vermedi, `123'` sözdizimi hatası verdi, `zakir'--` ve `' or 1=1 --` parolasız satır döndürdü, aynı girdi `?` parametreleriyle verildiğinde hiçbir satır dönmedi.
  - Slayttaki kodda parola değişkeni bir satırda `$pp`, sorguda `$p` diye geçer; bu slayttaki bir yazım tutarsızlığıdır.
- Prepared SQL ve ORM
  - Slayttaki örnekler `INSERT INTO users (name, email) VALUES (?, ?)` ve `SELECT * FROM users WHERE email = ?` biçimindedir; `?` yerlerine ad ve e-posta parametreleri aktarılır. ORM örneğinde `User` sınıfı `id` (integer), `name` ve `email` (string, 255) alanlarıyla tabloya eşlenir ve sorgu `User.query(email=...)` benzeri bir çağrıyla yapılır. <!-- BELİRSİZ: prepared SQL ve ORM slaytları karelerde yok; sözdizimi altyazıdan kuruldu. -->
- CSP ve SRI örnekleri
  - Hocanın okuduğu CSP örneği: `Content-Security-Policy: default-src 'self'; img-src *; script-src cdn.jquery.com` (resimler her yerden, betikler yalnız bu CDN'den, geri kalan içerik yalnız sayfanın domaininden). SRI örneğinde `https://code.jquery.com/jquery-3.4.0.min.js` için bir SHA-256 değeri verilir. <!-- BELİRSİZ: CSP satırı ve SRI etiketi karelerde yok; altyazıdan kuruldu, jQuery sürümü "340" diye okunmuş. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
