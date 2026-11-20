# Ders 7 Genişletilmiş Notu: Web Saldırıları: CSRF, SQL Enjeksiyonu ve XSS

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersin Tekrarı: SOP, CORS ve Çerezler
- 2. Oturum Ele Geçirme (Session Hijacking)
- 3. Cross-Site Request Forgery (CSRF)
- 4. CSRF'e Karşı Dört Savunma
- 5. Kimliği Doğrulanmış Oturumların Ötesi: Router Örneği
- 6. Web Saldırılarının Sıralaması
- 7. Komut Enjeksiyonu
- 8. SQL Enjeksiyonu
- 9. SQL Enjeksiyonunu Önleme: Prepared SQL ve ORM
- 10. Cross-Site Scripting (XSS)
- 11. XSS Filtrelemenin Zorluğu
- 12. Content Security Policy (CSP)
- 13. Subresource Integrity (SRI)
- Örnek Sorular
- Dersin Toparlaması

## 1. Önceki Dersin Tekrarı: SOP, CORS ve Çerezler

Ders, bir önceki haftada başlanan web güvenliği konusunun devamıdır. Hoca, doğrudan web üzerinden yapılan saldırılara geçmeden önce geçen haftanın slaytlarını kısaca hatırlattı ve bu slaytlarda yeni bir şey anlatmayacağını belirtti. Slaytlar Stanford CS155 web güvenliği sunumudur; örneklerde geçen "Zakir" ve "Dabo" adları slayttaki örnek kullanıcılardır.

### 1.1 DOM Same Origin Policy

Same Origin Policy (SOP) farklı nesneler için farklı kriterlerle çalışır; web isteklerinin yüklenmesinde ve çerezlerde kurallar ayrıdır. DOM tarafındaki temel kural slaytta şöyledir: web siteleri her kökenden (origin) kaynak yükleyebilir, ama istekte bulunan sitedeki JavaScript başka kökenden gelen içeriğin kendisini inceleyemez (ekrandan, 00:55:00). Slayttaki örnekte `attacker.com` sayfası `<img src="bank.com/img/usr.jpg">` ile bankadan resim ister; `GET /img/usr.jpg` isteği bankanın çerezleriyle birlikte gider ve resim gelip ekranda görüntülenir, ama `attacker.com`'daki JavaScript bu resmin içeriğine bakamaz.

### 1.2 CORS ve ön kontrol (pre-flight)

`Access-Control-Allow-Origin` başlığını sunucu belirler. Sunucu bununla "bu içeriğe şu kökenden erişilebilir" der; aslında bir beyaz liste (whitelist) koyar ve yalnız listedeki kökenler erişebilir. Buna bağlı olarak iki tür istek vardır: doğrudan yapılan istekler ve ön kontrollü (pre-flight) istekler. Sunucu bir isteğe izin vermiyorsa ve o isteğin arka tarafta hazırlanması uzun sürecekse tarayıcı önce HTTP `OPTIONS` yöntemiyle içeriğe erişip erişemeyeceğini sorar. Erişebiliyorsa asıl GET ya da POST'u yapar, erişemiyorsa hatayı kullanıcıya döndürür. Basit istekler için ön kontrol yapılmaz, çünkü o zaman iki kat trafik oluşur; ön kontrol yalnız daha fazla yük getirecek istekler içindir.

### 1.3 Çerezlerin gönderilmesi ve kapsamı

Çerezi başlangıçta sunucu gönderir, tarayıcı onu yerelde saklar. Daha sonra erişilen adrese göre, çerezin domain ve path alanları kapsamı tutuyorsa, kaç tane uygun çerez varsa hepsi birden istisnasız gönderilir. Slayttaki örnekte path'i `/classes` olan bir çerez `stanford.edu/classes` ve `stanford.edu/classes/cs155` adreslerine gönderilir, `stanford.edu`'ya gönderilmez. Domain alanı boşsa çerez yalnız onu gönderen host'a döner: `stanford.edu`'dan alınmış böyle bir çerez `www.stanford.edu`'ya gitmez, çünkü `www` ayrı bir host'tur. Domain `stanford.edu` ve path `/` ise `stanford.edu` altındaki her şeyi kapsar; `cs155.stanford.edu` da bunun altında olduğu için çerez oraya da gider.

Çerez ayarlama kuralı ise şöyledir (ekrandan, 01:00:00): web siteleri kapsamı domain ya da path'in herhangi bir öneki olacak şekilde ayarlayabilir.

- `cs155.stanford.edu`, `cs155.stanford.edu` için çerez ayarlayabilir.
- `cs155.stanford.edu`, `stanford.edu` için çerez ayarlayabilir.
- `stanford.edu`, `cs155.stanford.edu` için çerez ayarlayamaz.
- `website.com/`, `website.com/` için ayarlayabilir; `website.com/login`, `website.com/` için ayarlayabilir; `website.com`, `website.com/login` için ayarlayamaz.

Yani alt domain kendisini kapsayan üst domain için çerez ayarlayabilir, üst domain alt domain için ayarlayamaz; istek `stanford.edu`'dan geldiği için `cs155` adına çerez koyamaz.

### 1.4 Path ayrımı DOM'da koruma sağlamaz

Geçen haftaki örnekte `cs.stanford.edu/zakir` adresindeki kullanıcı, `cs.stanford.edu/dabo` path'ine ait çerezleri sunucuya gönderemez. Peki "dabo" kullanıcısının çerezleri "zakir"den korunmuş mudur? Hayır. DOM'da, yani tarayıcıdaki belge nesne modelinde, SOP path diye bir şeye bakmaz. Bu yüzden JavaScript üzerinden aynı domaindeki diğer path'in çerez içeriği alınabilir, işlenebilir, kullanılabilir.

Benzer bir sorun dışarıdan yüklenen betiklerdedir. Bir bankanın sayfasına bir analiz betiği (slayttaki örnekte Google Analytics) ya da başka domainden bir JavaScript kütüphanesi yüklenirse, özel bir kontrol yapılmadığında sonuç felaket olabilir: JavaScript her zaman pencerenin kökeninin yetkisiyle çalışır. Kütüphane kötü niyetli kod içeriyorsa sayfanın çerezlerine erişir.

### 1.5 HttpOnly ve Secure

`HttpOnly` çerezler JavaScript ile okunamaz, yalnız HTTP istek ve yanıtlarında gidip gelir. Bu kez de saldırgan ağ trafiğini dinler ve kullanıcıyı çerezi şifresiz HTTP üzerinden göndermeye zorlar ya da kandırırsa çerez ele geçer. Bunu önlemek için çerez tanımının sonuna `Secure` eklenir; böyle bir çerez yalnız HTTPS bağlantısında gönderilir.

## 2. Oturum Ele Geçirme (Session Hijacking)

Hoca sınıfa çerezlerin ele geçirilmesinin ne diye adlandırıldığını sordu; cevap "session hijacking" oldu. Slayttaki tanım: kullanıcının oturumunu çalmak için çerezleri yakalamak, bu ister ağ dinlemeyle (network sniffing), ister kötü niyetli JavaScript'le, ister başka bir yolla olsun, Session Hijacking Attack olarak bilinir (ekrandan, 01:05:00).

Hoca bunu daha önce görülen saldırılarla karşılaştırdı. Buffer overflow ve integer overflow konularında görülen saldırılar "control hijacking", yani kontrolün ele geçirilmesiydi. Burada da bir ele geçirme vardır, ama ele geçirilen oturumdur. Çerezler, birbirinden bağımsız istek ve yanıtları birbiriyle ilişkili bir bütün, yani oturum (session) hâline getirmek için vardır. Başkasına ait çerezleri ele geçirip başka yerde kullanmak, o kişinin oturumunu ele geçirmek demektir.

## 3. Cross-Site Request Forgery (CSRF)

CSRF, hocanın deyişiyle en çok yapılan saldırılardan biridir. Tanımı: bir web uygulamasına, o uygulamanın kimliğini doğrulamış ve güvendiği bir kullanıcı olarak istek göndermek. Bunun aracı çerezdir. Web uygulamaları bir kullanıcıyı bir kez doğrulayıp yetkisini belirledikten sonra, aynı kullanıcı her geldiğinde kullanıcı adı ve parola sormamak için çerez gönderir; çerezin varlık nedeni oturum oluşturmaktır. Kötü niyetli bir site bu çerezin kullanılmasını sağlayıp uygulamaya bir istek gönderirse, uygulama isteğin kendi onayladığı ve güvendiği kullanıcıdan geldiğini düşünür ve isteği gerçekleştirir.

Slayttaki ikinci cümle: CSRF saldırısında kullanıcı, istemediği ve çoğu zaman fark etmediği bir web isteğini bir siteye göndermeye kandırılır. Bizim işimiz bunu durdurmaktır.

### 3.1 Çerez tabanlı kimlik doğrulama neden yetmez?

Yan etkisi olan isteklerde (side effect) yalnız çerez tabanlı kimlik doğrulama yeterli değildir. Bankacılıkta yan etki para transferi ya da para çekmedir; genel olarak veriyi eksilten, değiştiren, güncelleyen bir işlemdir. Slayttaki örnekte `POST /transfer` isteği hesaptaki parayı başka bir hesaba aktarır. Çerez ele geçirildiğinde ya da kullanıcının tarayıcısı kandırılıp istek gönderdiğinde uygulama gelen çerez yüzünden isteği geçerli sayar.

> **Hocanın vurgusu:** Domain ve path tuttuğu zaman çerezler istisnasız gönderilir. O domain ve path yapısına uyan kaç çerez varsa hepsi, bütün isteklerde gider; bir istekte gönderilip diğerinde gönderilmemesi söz konusu değildir.

Slaytta da şöyle yazar: çerezler kapsamdaki her isteğe eklendiği için isteği yetkili bir uygulamanın gönderip göndermediğini göstermez; isteğin güvenilir bir sayfadan geldiğinden emin olmak için başka bir mekanizma gerekir (ekrandan, 01:10:00). Hoca burada bir "tavuk-yumurta" ilişkisi gördü: çerez, kullanıcının gerçek olduğunu anlamak için kullanılan yöntemdir; ama saldırgan bu yöntemi kötü niyetli bir senaryoda kullandığında uygulama kullanıcıdan gelmeyen bir isteği onaylı kullanıcıdan gelmiş sayar.

## 4. CSRF'e Karşı Dört Savunma

Slaytta dört yaygın teknik sayılır (ekrandan, 01:10:00): Referer Validation, Secret Validation Token, Custom HTTP Header ve sameSite Cookies.

> **Hocanın vurgusu:** Bunları bir arada uygulamak en doğrusudur. Tek bir savunma hattı olmamalı; o hat delindiğinde arkaya geçilir. Savunma bir yüzey gibi, birbirini tamamlayan ve güçlendiren birden fazla teknikle kurulmalıdır.

### 4.1 Referer doğrulama

`Referer` istek başlığı, istenen sayfaya bağlantının izlendiği önceki web sayfasının adresini taşır; böylece sunucu insanların nereden geldiğini anlayabilir (ekrandan, 01:15:00). Örneğin Google'da arama yapıp sonuç listesindeki bir bağlantıya tıkladığınızda istek ilgili sunucuya gider ve isteğin Referer alanında normal şartlarda Google olur.

Slayttaki üç durum şunlardır:

| Referer | Hedef | Karar |
|---|---|---|
| `https://bank.com` | `https://bank.com` | kabul |
| `https://attacker.com` | `https://bank.com` | ret |
| (yok) | `https://bank.com` | belirsiz ("??") |

Para transferi gibi bir işlemde sunucu mutlaka Referer alanını kontrol etmelidir. Kullanıcının doldurup geri göndereceği formları zaten banka vermiştir, dolayısıyla istekler bankanın sunucusundan çıkmış bir sayfadan gelmelidir; yani birinci satırdaki durum gerçekleşmiş olmalıdır. İkinci satır açıktır. Üçüncü satır sıkıntılıdır: Referer yoksa kullanıcı adres çubuğuna gitmek istediği yeri yazıp isteği sıfırdan mı başlattı, yoksa başka bir şey mi oldu, bilinemez. <!-- BELİRSİZ: 01:12:51-01:14:13 arasında altyazı boşluğu var; hocanın ikinci ve üçüncü satır üzerine söyledikleri kısmen kayıp. -->

### 4.2 Gizli doğrulama jetonu

Değişiklikler ancak uygulamaya bir girdi verildiğinde, yani bir form gönderildiğinde gerçekleşir. Banka bu yüzden her formun içine HTML tipi `hidden` olan, sayfada görünmeyen ama formla birlikte gidip gelen bir jeton (token) koyar. Slayttaki form şudur (ekrandan, 01:20:00):

```html
<form action="https://bank.com/transfer" method="post">
  <input type="hidden" name="csrf_token" value="434ec7e838ec3167ef5">
  <input type="text" name="to">
  <button type="submit">Transfer!</button>
</form>
```

Alanın adının ne olduğu önemli değildir, önemli olan değeridir ve bu değer tahmin edilemez olmalıdır. Saldırgan bu değeri bilmediği için göndereceği formda alan eksik olur ve banka isteğin kendisinden gelmediğini anlar. Böylece Referer alanı boşken bile uygulama formun içinde kendi yerleştirdiği jetonun bulunup bulunmadığına bakarak karar verebilir.

Slayttaki soru: kullanıcının erişebildiği ama saldırganın erişemediği bir jetonu nasıl üretiriz?

- Formda statik jeton kullanmak yanlıştır: saldırgan transfer sayfasını "out of band", yani kullanıcının bankayla etkileşiminden bağımsız olarak kendi tarafında yükler, jetonun hem adını hem değerini öğrenir. Bütün formlarda aynı değer kullanıldığı için bunu kendi kötü niyetli işleminin içine koyar.
- Doğrusu oturuma özgü (session-specific) jetonu sayfanın parçası olarak göndermektir. Kullanıcı çıkıp yeniden bağlandığında yeni bir jeton üretilir.

Dinamik jetonun güzelliği SOP'tan gelir. SOP içeriğin gelmesine ve ekranda görüntülenmesine izin verir, ama düzgün ayarlandıysa JavaScript tarafından okunmasını engeller. Saldırgan kullanıcının tarayıcısına kötü niyetli JavaScript sokmuş olsa bile bankadan gelen jeton değerini okuyamaz. Jeton statik olsaydı, az önce anlatıldığı gibi dışarıdan ele geçirilebilirdi.

### 4.3 Özel HTTP başlığı

Üçüncü yöntem ön kontrol mekanizmasına dayanır. Normalde sıradan GET ve POST'lar, JavaScript'ten `XMLHttpRequest` ile yapılsa bile ön kontrolden geçmez. HTTP standardı başlık alanlarını tanımlar, ama aynı zamanda istenirse kendi adınızla özel (custom) bir başlık eklemenize de izin verir. `XMLHttpRequest` içine özel bir başlık eklendiğinde tarayıcı ön kontrol yapmak zorunda kalır. Hoca bunu "tarayıcıyı ön kontrole zorlamak" diye anlattı: saldırganın yüklediği JavaScript de isteğini `XMLHttpRequest` ile yapacağı için saldırının yöntemi ön kontrolü zorunlu kılar. Normal GET ve POST'ta bu başlık alanları bulunmaz. Bu başlıkların başına genellikle `X` konur; "X-Requested-By" ya da "X-Requested-With" gibi adlar yaygındır, arkasına başka şeyler de eklenebilir.

> **Ek bilgi (derste anlatılmadı):** Saldırganın sitesinden gelen siteler arası `XMLHttpRequest`, özel başlık nedeniyle önce `OPTIONS` ön kontrolüne takılır. Sunucu bu kökene CORS izni vermediği sürece tarayıcı asıl isteği göndermez. Sunucu da özel başlığı taşımayan istekleri reddederek düz HTML formlarıyla yapılan sahte istekleri ayıklar.

### 4.4 sameSite çerezleri

sameSite, tarayıcının çerezi siteler arası (cross-site) isteklerle göndermesini engelleyen bir çerez seçeneğidir (ekrandan, 01:25:00). `Secure` eklenince çerezin yalnız HTTPS üzerinden gitmesi gibi, burada da çerezin siteler arası isteklerde gönderilip gönderilmeyeceği belirtilir. İki mod vardır:

- **Strict:** hiçbir siteler arası tarama bağlamında, sıradan bir bağlantı izlenirken bile çerez gönderilmez. "Sıradan bağlantı", HTML'e gömülü, `href` ile verilmiş, JavaScript içermeyen ve isteği tarayıcının kendisinin oluşturduğu bağlantıdır. Slayttaki örnek: oturum açmış bir kullanıcı e-postadaki bir bağlantıdan özel bir GitHub projesine giderse GitHub oturum çerezini almaz ve kullanıcı projeye erişemez. Strict olmasaydı tarayıcı çerezi gönderir, GitHub kullanıcıyı tanıyıp içeri alırdı; Strict modda kullanıcı yeniden kullanıcı adı ve parolayla giriş yapmak zorundadır.
- **Lax:** sıradan bir bağlantı izlenirken oturum çerezine izin verir, ama CSRF'e açık istek yöntemlerinde (ör. POST) engeller.

Böylece çerez tanımına `Secure` dışında bir de `SameSite` eklenmiş olur.

## 5. Kimliği Doğrulanmış Oturumların Ötesi: Router Örneği

Slayt şunu hatırlatır (ekrandan, 01:30:00): önceki saldırılar CSRF ile oturum açmış kullanıcının çerezlerini kötüye kullanıyordu, ama her saldırı kimliği doğrulanmış kullanıcıyı kötüye kullanmaya çalışmaz. Senaryo: yerel router'ınıza varsayılan parolayla giren ve trafiği kaçırmak için DNS ayarlarını değiştiren bir betik düşünün. Bir siteye giriş yapmak da yan etkisi olan bir istektir.

Hoca senaryoyu adım adım bağladı. Evden ya da ofisten dışarı çıkarken yerel router'ınızdaki DNS ayarına güvenirsiniz. Router'ın parolasını değiştirmemişsinizdir, çünkü ona yalnız yerel ağdan erişildiğini, internete kapalı olduğunu düşünürsünüz. Saldırgan ise tarayıcınıza, router'a yerelden erişip DNS ayarlarını değiştirecek betiği gönderir ve varsayılan parolayı zaten bilir. Bunlar bir araya gelince internete kapalı router'ınızın ayarı sizin tarayıcınızda çalışan JavaScript tarafından yerelden değiştirilir. Bundan sonra yaptığınız DNS istekleri saldırganın hayal gücüyle sınırlıdır: sizi ekran görüntüsünü kopyaladığı herhangi bir servise, örneğin bir bankanın sahte sayfasına yönlendirebilir.

Ders çıkarımı: yan etki yalnız para transferi değildir. Router da web arayüzü üzerinden giriş yapılan bir sitedir ve oraya giriş yapmak da yan etkisi olan bir işlemdir.

## 6. Web Saldırılarının Sıralaması

SQL enjeksiyonuna geçmeden önce hoca 2013 ve 2017 yıllarının web zafiyet istatistiklerini karşılaştıran bir slayt gösterdi ve işlerin çok değişmediğini söyledi. Birinci sırada iki yılda da Injection, ikinci sırada Broken Authentication and Session Management vardır. 2013'te üçüncü sırada olan Cross-Site Scripting 2017'de yedinci sıraya düşmüştür. 2013'te ayrı değerlendirilen Insecure Direct Object References ve Missing Function Level Access Control, 2017'de "Broken Access Control" adıyla birleştirilmiştir. Hoca bu yüzden bu saldırıların yöntemini iyice anlamanın ve tedbirleri ona göre almanın önemli olduğunu söyledi. <!-- BELİRSİZ: tablonun karesi yok; sıralar altyazıdan alındı. -->

> **Ek bilgi (derste anlatılmadı):** Bu karşılaştırma büyük olasılıkla OWASP Top 10 listesinin 2013 ve 2017 sürümleridir.

## 7. Komut Enjeksiyonu

SQL enjeksiyonundan önce komut enjeksiyonunun nasıl olduğu gösterildi. Slayttaki tanım: komut enjeksiyonu saldırılarının amacı sistemde keyfi bir komut çalıştırmaktır; bu genelde geliştirici güvenli olmayan kullanıcı verisini bir kabuğa (shell) aktardığında mümkün olur (ekrandan, 01:35:00).

Hoca bunun işletim sisteminden değil, araçların sunduğu kolaylıklardan kaynaklandığını vurguladı. Örneğin kabukta aynı satıra birden fazla komut noktalı virgülle ayrılarak yazılabilir; enter'a bir kez basılır, kabuk bunları sırayla yorumlayıp çalıştırır.

Örnek program `head100`, bir dosyanın ilk 100 satırını basar (ekrandan, 01:35:00):

```c
int main(int argc, char **argv) {
    char *cmd = malloc(strlen(argv[1]) + 100);
    strcpy(cmd, "head -n 100 ");
    strcat(cmd, argv[1]);
    system(cmd);
}
```

Program, gelen dosya adının uzunluğuna 100 bayt ekleyip `malloc` ile yer ayırır. `strcpy` ile `cmd` alanına `head -n 100 ` yazılır, `strcat` ile arkasına `argv[1]` eklenir (`argv[0]` programın adı, `argv[1]` ilk argümandır). Sonra `system(cmd)` ile sistem çağrısı yapılır. Normal kullanımda `head100 myfile.txt`, `head -n 100 myfile.txt` komutunu çalıştırır ve dosyanın ilk 100 satırı listelenir.

Saldırgan ise argümanı çift tırnak içinde verdi. Kabukta çift tırnak, içindekilerin tek parça olarak değerlendirilmesini sağlar; böylece dosya adının arkasına noktalı virgülle bir başka komut eklenip programa tek argüman olarak aktarıldı ve kabuk ikinci komutu da çalıştırdı. <!-- BELİRSİZ: saldırganın girdiği tam komut karelerde yok. -->

Sorun, programın girdiyi temizlememesidir; buna sanitization (kelime anlamıyla temizlik) denir. Gelen girdinin doğru mu, kirli mi, programın ihtiyacı dışında bir şey içeriyor mu diye kontrolü yapılmaz, `argv[1]` olduğu gibi kullanılır.

Ajan notu: Slayttaki kod başlık dosyaları (`stdio.h`, `stdlib.h`, `string.h`) eklenerek `gcc -Wall` ile uyarısız derlendi. 150 satırlık bir dosyada tam 100 satır bastı. Argüman olarak `"myfile.txt; echo ENJEKTE_KOMUT_CALISTI"` verildiğinde 100 satırın ardından `echo` komutu da çalıştı. Bu deneme derste yapılmadı.

## 8. SQL Enjeksiyonu

Kabuk enjeksiyonu kabuğun bir özelliğinden yararlanıyordu; aynı fikir SQL'e taşınır. Basit bir giriş formunda login ve password alanları vardır. Slayttaki kod (ekrandan, 01:40:00):

```php
$u = $_POST['login'];      // zakir
$pp = $_POST['password'];  // 123'

$sql = "SELECT id FROM users WHERE uid = '$u' AND pwd = '$p'";
//      "SELECT id FROM users WHERE uid = 'zakir' AND pwd = '123''"
$rs = $db->executeQuery($sql);
//      SQL Syntax Error
if $rs.count > 0 {
   // success
}
```

Sonuç kümesinin satır sayısı sıfırdan büyükse, yani hem kullanıcı adı hem parola eşleşen bir satır döndüyse giriş başarılı sayılır. Hoca bunu binlerce web uygulamasında karşılaşılabilecek kadar tipik, ama SQL enjeksiyonu açısından felaket bir senaryo olarak niteledi.

> **Ders sonrası not:** Slayttaki kodda parola değişkeni ilk satırda `$pp`, sorguda `$p` diye geçer. Bu slayttaki bir yazım tutarsızlığıdır; anlatılan senaryo iki adın aynı değişken olduğunu varsayar.

Hocanın gösterdiği girdiler sırayla şöyledir:

- **Doğru girdi:** kullanıcı `zakir`, parola `123`. Yerlerine konur, sorgu sorunsuz çalışır.
- **Parola `123'`:** kullanıcı adı ve parola tek tırnak içinde sorguya konduğu için fazladan tırnak sözdizimini bozar ve SQL hatası oluşur. Sorgu çalışmaz; saldırgan "kenardan döner", ama burada girdinin temizlenmediği anlaşılmış olur.
- **Kullanıcı adı `zakir'--`:** SQL'de yan yana iki eksi işaretinden sonrası açıklama (yorum) satırı sayılır. Sorgu `zakir`'de biter, `AND pwd = ...` kısmı yorum olur. Saldırgan "zakir" kullanıcısının var olduğunu bilir ama parolasını bilmez; hata oluşmaz ve parolasız giriş yapılır.
- **Kullanıcı adı `' or 1=1 --`:** SQL'de eşitlik kontrolü C'deki gibi değil, tek `=` ile yapılır. Koşul "uid boş mu veya 1=1 mi" olur, geri kalanı yorumdur. Boş kullanıcı adı veritabanında yoktur ama 1=1 her zaman doğrudur. Böylece ne kullanıcı adı ne parola verilmeden giriş yapılır.
- **`'; DROP TABLE users --`:** SQL'de birden fazla deyim noktalı virgülle ayrılarak tek satırda çalıştırılabilir. Kullanıcı adı alanı tırnakla kapatılır, ardından `DROP TABLE users` gelir, geri kalanı yorum olur. Kullanıcı tablosu genelde `user` ya da `users` adındadır; uygulama açık kaynaksa tablo yapısı da bilinir. Giriş formundan veritabanındaki bir tablo silinmiş olur.
- **MS SQL `xp_cmdshell`:** Microsoft SQL Server, SQL içinden komut satırında komut çalıştırmayı destekler ve çıktıyı satır satır metin olarak bir tabloda döndürür. Slayttaki girdi `'; exec xp_cmdshell 'net user add usr pwd123' --` biçimindedir; `net` komutu Windows'ta kullanıcı eklemek, parola değiştirmek gibi işler için kullanılır. Sonuçta adı `usr` olan bir yerel hesap sisteme eklenir. SQL Server Windows'ta yerel sistem hesabıyla çalıştığı için komut da onun yetkisiyle çalışır; açılan kullanıcı da bu yetkide olur. <!-- BELİRSİZ: xp_cmdshell satırının karesi yok; komut altyazıdan kuruldu, parolanın "pwd123" mü "pwd 123" mü olduğu belli değil. -->

Ajan notu: Dört girdi Python'un `sqlite3` modülüyle bellekte kurulan tek satırlık bir `users` tablosunda denendi. `123'` "unrecognized token" sözdizimi hatası verdi; `zakir'--` ve `' or 1=1 --` parola bilinmeden satır döndürdü. Aynı `' or 1=1 --` girdisi `?` parametresiyle verildiğinde hiçbir satır dönmedi. Bu deneme derste yapılmadı.

## 9. SQL Enjeksiyonunu Önleme: Prepared SQL ve ORM

Slaytın ilk kuralı: kullanıcı girdisine asla güvenme, özellikle bir komut oluştururken; SQL komutlarını asla kendin elle kurma (ekrandan, 01:45:00). SQL sorguları uygulama içinde az önceki örnekteki gibi dinamik olarak birleştirilmemelidir. Girdiyi veritabanına güvenle aktarmanın araçları vardır:

- **Parametreli (prepared) SQL:** SQL önceden belirlenmiştir, hazır durur, ona yalnız parametre aktarılır. Gelen parametrelerin kontrolünü (doğru mu, fazlalık var mı) sistem yapar.
- **ORM (Object Relational Mapper):** nesneleri veritabanı tablolarına eşler; get ve set işlemleriyle tablo güncellenir. ORM de içeride prepared SQL kullanır, dolayısıyla arada fark yoktur. Bu iki yöntemden biri kullanılmalıdır.

Slayttaki prepared SQL örneklerinde `INSERT INTO users (name, email) VALUES (?, ?)` ve `SELECT * FROM users WHERE email = ?` vardır; soru işaretli yerlere parametreler aktarılır (birinde örnek kullanıcının adı ve e-postası, diğerinde başka bir örnek e-posta). Böylece güvenilmeyen kullanıcı verisinin temizlenmesi ve onaylanması bu işten sorumlu katmanda yapılır; `--`, tek tırnak, `1=1` gibi parçaların hepsi etkisiz kalır.

İkinci kazanç hızdır. SQL sunucusu bir sorguyu analiz edip adımlara böler ve mümkünse paralel çalıştıracak bir sorgu planı (query plan) oluşturur. Prepared SQL sürekli çalıştırıldığı için plan önbelleğe alınmıştır ve sorgu daha hızlı çalışır.

ORM örneğinde `User` sınıfı bir veritabanı nesnesinden türetilir; `id` integer, `name` ve `email` 255 uzunluğunda string alanlardır. Sorgu bu sınıf üzerinden, e-postaya göre arama yapan bir `query` çağrısıyla yapılır; arka tarafta yine temizlik ve kontrol gerçekleşir. <!-- BELİRSİZ: prepared SQL ve ORM slaytlarının karesi yok; sözdizimi altyazıdan kuruldu. -->

## 10. Cross-Site Scripting (XSS)

Sırayla CSRF ve SQL enjeksiyonundan sonra üçüncü saldırı XSS'tir. Slayttaki tanım: uygulama güvenilmeyen veriyi alıp uygun doğrulama ya da temizlik (sanitization) yapmadan bir web tarayıcısına gönderdiğinde saldırı oluşur (ekrandan, 01:50:00).

Slayt iki saldırı ailesini yan yana koyar: komut/SQL enjeksiyonunda saldırganın kötü niyetli kodu uygulamanın sunucusunda çalışır; XSS'te ise kurbanın tarayıcısında çalışır.

> **Hocanın vurgusu:** Cross-site scripting'de kod tarayıcıda çalışır; bunu unutmayın.

### 10.1 Arama kutusu örneği

Bir arama sayfası düşünün: `?q=` parametresiyle gelen arama terimi, en basit hâliyle PHP'de `echo $_GET[...]` ile "Results for ..." biçiminde sayfaya geri yazılır. `apple` aranırsa tarayıcıya giden şey "Results for apple" olur; dinamik yapı statik bir içeriğe dönüşür. Girdi tarayıcıda doldurulur, sunucuya gider, sunucu sonucu tarayıcıya geri döndürür. Arama kutusuna `<script>alert("hello")</script>` yazılırsa sunucu bunu olduğu gibi sayfaya koyar, tarayıcı da sayfayı ayrıştırırken betiği çalıştırır ve ekranda "hello" yazan bir uyarı penceresi açılır. Uyarı penceresi yerine çerezi başka bir yere gönderen bir betik konursa bu açıkça çerez hırsızlığıdır. <!-- BELİRSİZ: arama örneği slaytlarının karesi yok; kod altyazıdan kuruldu. -->

### 10.2 Reflected ve stored XSS

XSS zafiyeti, saldırgan bir web uygulamasının ürettiği sayfalara betik kodu enjekte edebildiğinde vardır. Arama örneğinde arama alanı değiştirilmiş ve bir anda aktif hâle gelmiştir. İki tür vardır:

- **Reflected:** saldırı betiği, kurban siteden gelen bir sayfanın parçası olarak kullanıcıya geri yansıtılır. Arama örneği reflected'dır: bir girdi alanına girilen şey tarayıcıya geri döner.
- **Stored:** saldırgan kötü niyetli kodu web uygulamasının yönettiği bir kaynakta, örneğin veritabanında saklar. Sayfa oluşturulurken kod sorguyla oradan çekilir ve kullanıcıya gönderilir.

Reflected için yaşanmış bir örnek PayPal'dır. Saldırganlar PayPal kullanıcılarına e-posta gönderip onları gerçek PayPal sitesinde barındırılan bir URL'ye erişmeye kandırdı. Kullanıcılara güvenlik nedeniyle parolalarını değiştirmeleri gerektiği söylendi; gidilen site gerçekten PayPal'dı. Enjekte edilen kod ziyaretçileri hesaplarının ele geçirildiğini söyleyen bir uyarı sayfasına, oradan da hassas finansal bilgilerini girmelerinin istendiği bir oltalama (phishing) sitesine yönlendirdi. Mantık, gerçek sitedeki bir boşluğun yakalanmasıdır.

Stored için örnek PHP tabanlı bir bülten panosudur (bulletin board): saldırgan kodu panonun veritabanına koyarsa sayfa oluşturulurken kötü niyetli kod da otomatik olarak gelir.

### 10.3 Samy Worm

Samy Worm, MySpace'te yayılan XSS tabanlı bir solucandır. Kurbanın MySpace profil sayfasında "but most of all, samy is my hero" yazısını gösteriyor ve Samy'ye bir arkadaşlık isteği gönderiyordu. 20 saatte bir milyon kullanıcıya yayıldı (ekrandan, 01:55:00). Hoca, bunun bir günden bile kısa sürede bir milyon kullanıcıya ulaştığını ve oradan oraya atladığı için tıpkı ilk derslerde görülen internet solucanı gibi bir solucan olduğunu vurguladı.

Neden mümkün oldu? MySpace kullanıcı gönderilerinde `script`, `body`, `onclick` ve `href` içindeki javascript'i filtrelemişti. Ama `div` öğelerinin style özelliğindeki background alanını filtrelemeyi atlamıştı; oraya JavaScript yerleştirilebiliyordu. Sonradan düzeltildi, ama iş işten geçmişti.

## 11. XSS Filtrelemenin Zorluğu

Samy örneği şunu gösterir: kötü niyetli etiketler filtrelenmelidir, ama filtrelemek çok zordur. Başlıklar, çerezler, query string'ler, form alanları, gizli alanlar, akla gelebilecek her girdi tek tek kontrol edilip temizlenmelidir.

Google'ın XSS filtresinin bile atlatıldığı bir olay gösterildi: saldırgan bir `img` öğesinin kaynağını kodlaya kodlaya (encode ederek) yazmıştı. Filtre bunu bir resim gibi görüyordu, ama tarayıcı açtığında içinde bir betik olduğunu fark edip çalıştırıyordu. Kodlanmış içerik aslında `javascript:alert(document.cookie)` idi. Hoca bunu "çılgınca" diye niteledi. Filtrelenmesi gereken yalnız olay işleyicileri (onsubmit, onerror ve benzerleri) en az 105 tanedir ve başka noktalar da vardır. Ayrıca içeriği bozan filtreler de olabilir: "script'i filtrele" dendiğinde içerik başka bir şeye dönüşebilir.

Web çatıları (örneğin WordPress) bu filtrelemeyi düzgün yapmaya çalışır, ama zaman zaman onlarda da açık çıkar. Hoca bunun için 26 Mart 2019 tarihli bir açık örneğini gösterdi.

> **Hocanın vurgusu:** "WordPress kullanıyorum, onlar bu işi çözmüştür" demenin anlamı yok; yüzde yüz güvenmemek gerekir. Ama filtreyi kendiniz yazmak da çok tehlikelidir. Bütün durumları düşünmediğiniz sürece filtre yaptığınızı sanırken büyük bir açıkla karşı karşıya kalırsınız.

## 12. Content Security Policy (CSP)

Slaytın ilk cümlesi: beyaz listeye dayalı yaklaşım, kara listeye dayalı yaklaşımdan her zaman daha güvenlidir (ekrandan, 02:00:00). Yani her şeyi yasaklayıp yalnız izin verilmesi gerekenlere izin vermek gerekir. CSP, betiklerin ve diğer kaynakların güvenilir kaynağı olan kökenleri beyaz listeye alarak XSS saldırılarını ortadan kaldırmayı sağlar. Tarayıcı yalnız beyaz listedeki domainlerden gelen betikleri çalıştırır; satır içi betikler ve olay işleyen HTML öznitelikleri dahil diğer bütün betikleri yokmuş sayar.

Hocanın okuduğu örnekler:

- `Content-Security-Policy: default-src 'self'`: içerik yalnız sayfanın geldiği domainden yüklenebilir. Satır içi betikler ve satır içi stiller çalıştırılmaz; bu domainden include edilen betikler çalışır.
- `Content-Security-Policy: default-src 'self'; img-src *; script-src cdn.jquery.com`: resimler herhangi bir yerden, betikler yalnız bu CDN'den yüklenebilir. Satır içi betik ve stil çalışmaz, geri kalan içerik yalnız sayfayı yükleyen domainden gelebilir.

<!-- BELİRSİZ: CSP örnek satırlarının karesi yok; satırlar altyazıdan kuruldu. -->

## 13. Subresource Integrity (SRI)

CSP ile bir CDN'e izin verildiğini düşünelim. Site o CDN'i güvenli saydığı için oradan içerik yüklenmesine izin verir. Peki CDN ele geçirilirse? Hoca bunun yaşanmış bir örneğini anlattı: Bootstrap CDN ele geçirildi ve Bootstrap JavaScript'i değiştirildi; Bootstrap'i kullanan bütün uygulamalar bundan anında etkilendi. Neden: işten çıkarılan bir mühendisin hesabı kapatılmamıştı ve saldırganlar bu hesapla CDN'e erişip dosyayı değiştirdi.

SRI'da sayfa, yüklenecek dosyanın (örnekte `https://code.jquery.com/jquery-3.4.0.min.js`) yanında onun güvenli özet değerini de belirtir: "bu dosyanın SHA-256 değeri budur". Tarayıcı inen içeriğin SHA-256'sını kendisi hesaplar ve iki değeri karşılaştırır. Eşitse sorun yoktur ve dosya çalıştırılır; eşit değilse çalıştırılmaz. <!-- BELİRSİZ: SRI slaytının karesi yok; jQuery sürümü altyazıda "340" diye geçiyor, öz değeri okunamadı. -->

> **Ders sonrası not:** Altyazıda karşılaştırmanın sonunda "Eşit değilse çalıştırılır" diye geçer; bağlamdan ve SRI'ın tanımından doğrusu "eşit değilse çalıştırılmaz" olmalıdır (büyük olasılıkla Whisper ya da konuşma hatası).

> **Ek bilgi (derste anlatılmadı):** HTML'de SRI, `<script src="..." integrity="sha256-..." crossorigin="anonymous">` biçiminde `integrity` özniteliğiyle verilir. Özet değeri base64 olarak yazılır.

## Örnek Sorular

**Soru 1** (ekrandan, 01:00:00): Aşağıdaki çerez ayarlama isteklerinden hangileri geçerlidir? (a) `cs155.stanford.edu`, `stanford.edu` için; (b) `stanford.edu`, `cs155.stanford.edu` için; (c) `website.com/login`, `website.com/` için; (d) `website.com`, `website.com/login` için.

> **Çözüm:** Kapsam, domain ya da path'in herhangi bir öneki olabilir. (a) geçerli, (b) geçersiz, (c) geçerli, (d) geçersiz. Alt domain/alt path kendisini kapsayan üst düzey için ayarlayabilir, tersi olmaz.

**Soru 2** (derste sözlü, 01:03:40): Ağ dinleme ya da kötü niyetli JavaScript yoluyla çerezlerin ele geçirilmesine ne ad verilir ve buffer overflow saldırılarından farkı nedir?

> **Çözüm:** Session hijacking (oturum ele geçirme). Buffer/integer overflow saldırılarında ele geçirilen programın kontrolüdür (control hijacking); burada ele geçirilen, çerezlerle kurulan oturumdur.

**Soru 3** (ekrandan, 01:15:00): Referer doğrulamasında (1) `https://bank.com` → `https://bank.com`, (2) `https://attacker.com` → `https://bank.com`, (3) Referer yok → `https://bank.com` durumlarında sunucu nasıl karar verir?

> **Çözüm:** (1) kabul, (2) ret. (3) belirsizdir: kullanıcı adresi elle yazmış olabilir. Bu durumda formdaki oturuma özgü gizli jetona bakılır.

**Soru 4** (ekrandan, 01:20:00): Kullanıcının erişebildiği ama saldırganın erişemediği bir CSRF jetonu nasıl üretilir?

> **Çözüm:** Formda statik jeton kullanmak yanlıştır, çünkü saldırgan transfer sayfasını kendi tarafında (out of band) yükleyip jetonu öğrenebilir. Doğrusu oturuma özgü jetonu sayfanın parçası olarak göndermektir; saldırganın betiği bu değeri okuyamaz, çünkü SOP başka kökenden gelen içeriğin okunmasını engeller.

**Soru 5** (ekrandan, 01:40:00): `SELECT id FROM users WHERE uid = '$u' AND pwd = '$p'` sorgusunda (a) parola `123'`, (b) kullanıcı adı `zakir'--`, (c) kullanıcı adı `' or 1=1 --` verilirse ne olur?

> **Çözüm:** (a) Fazladan tırnak nedeniyle SQL sözdizimi hatası. (b) `--` sonrası yorum olur, parola koşulu düşer; "zakir" parolasız girer. (c) `1=1` her zaman doğru olduğu için hiçbir kullanıcı adı ve parola bilinmeden giriş yapılır. Üç durum `sqlite3` ile doğrulandı (ajan testi).

**Soru 6** (ekrandan, 01:50:00): Komut/SQL enjeksiyonu ile XSS arasındaki temel fark nedir?

> **Çözüm:** Komut ve SQL enjeksiyonunda saldırganın kodu uygulama sunucusunda, XSS'te kurbanın tarayıcısında çalışır.

## Dersin Toparlaması

Ders, geçen haftanın Same Origin Policy, CORS ve çerez kurallarını hızla tekrar ettikten sonra üç temel web saldırısını ve savunmalarını inceledi. Çerezlerin kapsam tuttuğu her istekte otomatik gönderilmesi, hem session hijacking'in hem de CSRF'in temelidir. CSRF'e karşı Referer doğrulama, oturuma özgü gizli jeton, ön kontrolü zorlayan özel HTTP başlığı ve sameSite (Strict/Lax) çerezleri birlikte, katmanlı olarak kullanılmalıdır. Router örneği, yan etkili isteklerin yalnız para transferi olmadığını gösterdi.

SQL enjeksiyonu kabuk enjeksiyonundan yola çıkılarak anlatıldı: temizlenmemiş girdiyle elle kurulan sorgular tırnak, yorum (`--`), `1=1`, `DROP TABLE` ve `xp_cmdshell` gibi girdilerle kötüye kullanılabilir. Çözüm prepared SQL ya da ORM'dir. XSS'te kod kurbanın tarayıcısında çalışır; reflected (PayPal) ve stored (Samy Worm) türleri vardır. Filtreleme şarttır ama zordur; kendi filtrenizi yazmamalı, hazır filtrelere de körü körüne güvenmemelisiniz. Son olarak beyaz listeye dayanan Content Security Policy ve CDN'den gelen dosyaların SHA-256 özetini doğrulayan Subresource Integrity ile ders kapandı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
