# Ders 4 Genişletilmiş Notu: E-posta, DNS, P2P, Video Akışı ve CDN

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Uygulama Katmanında Kaldığımız Yer
- 2. E-posta Sisteminin Bileşenleri
- 3. Alice'ten Bob'a Bir E-postanın Yolculuğu
- 4. SMTP Protokolü
- 5. SMTP ile HTTP Karşılaştırması ve Mesaj Biçimi
- 6. Posta Erişim Protokolleri
- 7. DNS: Neden ve Ne?
- 8. DNS'in Dağıtık ve Hiyerarşik Yapısı
- 9. Ad Çözümleme: Yinelemeli ve Özyinelemeli Sorgu
- 10. Önbellekleme, Kayıtlar ve DNS Mesajları
- 11. DNS Güvenliği
- 12. Eşler Arası (P2P) Uygulamalar ve Dosya Dağıtımı
- 13. BitTorrent
- 14. Video Akışı
- 15. İçerik Dağıtım Ağları (CDN)
- Örnek Sorular

## 1. Uygulama Katmanında Kaldığımız Yer

Ders, önceki haftada başlanan uygulama katmanı bölümünün devamıdır. Uygulama katmanı katmanlı mimarinin en üst katmanıdır ve kullanıcının gördüğü, ağla etkileşime girdiği katmandır. Geçen hafta ağ uygulamalarının ilkeleri, Web ve HTTP işlenmişti. Bu derste sırasıyla e-posta (SMTP ve IMAP), DNS, eşler arası (P2P) uygulamalar ve son olarak video akışı ile içerik dağıtım ağları (CDN) işlendi; böylece bölümün bütün uygulama başlıkları tamamlandı (ekrandan, 01:25:00).

## 2. E-posta Sisteminin Bileşenleri

E-posta, İnternet'in en eski uygulamalarındandır. Hoca, giriş dersinde söylediğini hatırlattı: İnternet'in kurulma amacı zaten kullanıcılar ya da makineler arasında mesaj alışverişiydi.

Sistemin üç ana bileşeni vardır:

- **Kullanıcı aracısı (user agent):** "mail reader" olarak da bilinir. Mesaj yazmak (compose), düzenlemek ve okumak için kullanılır. Yaygın örnekler Outlook ve telefonlarda hazır yüklü gelen iPhone e-posta istemcisidir. Gelen ve giden mesajlar sunucuda saklanır, kullanıcı aracısı bu mesajlara erişmek için kullanılır.
- **Posta sunucusu (mail server):** Kullanıcıların posta kutularını (mailbox) tutar; posta kutusu kullanıcıya gelen mesajları içerir. Sunucuda ayrıca giden mesajların bekletildiği bir **mesaj kuyruğu** (message queue) vardır. Slayttaki şekilde yeşil kutular giden mesaj kuyruğunu, sarı kutular kullanıcı posta kutularını gösterir (ekrandan, 00:15:00). Kuyruktaki mesajlar bir sonraki sorumlu posta sunucusuna iletilir.
- **SMTP (Simple Mail Transfer Protocol):** Posta sunucuları arasında e-posta mesajlarını gönderen protokoldür. Bu alışverişte gönderen posta sunucusu istemci, alan posta sunucusu "sunucu" rolündedir (ekrandan, 00:15:00).

## 3. Alice'ten Bob'a Bir E-postanın Yolculuğu

Hoca, slayttaki senaryoyu adım adım anlattı. Solda Alice, arkadaşı Bob'a e-posta göndermek istiyor; Bob'un adresi bob@someschool.edu biçimindedir.

1. Alice, kullanıcı aracısını kullanarak Bob'un adresine mesajını yazar.
2. Alice'in kullanıcı aracısı mesajı Alice'in posta sunucusuna gönderir. Mesaj sunucudaki mesaj kuyruğuna yerleştirilir.
3. Alice'in posta sunucusunun istemci tarafı, Bob'un posta sunucusuna bir TCP bağlantısı açar.
4. Mesaj bu TCP bağlantısı üzerinden SMTP ile gönderilir.
5. Bob'un posta sunucusu gelen mesajı Bob'un posta kutusuna koyar.
6. Bob, kullanıcı aracısını çalıştırarak mesajı okur.

Hoca burada "Neden TCP bağlantısı açıyoruz?" diye sordu ve cevapladı: e-posta güvenilir aktarım gerektirir. Bir mesajın bir kısmının kaybolması kabul edilemez, bu yüzden güvenilir taşıma hizmeti veren TCP kullanılır.

<!-- BELİRSİZ: 00:17:02-00:17:29 arası altyazı yalnız rakamlardan oluşuyor; adımların tam söylenişi buradan okunamıyor, sıra slayttaki standart senaryoya göre yazıldı. -->

## 4. SMTP Protokolü

### 4.1 Temel özellikler

SMTP açık bir uygulama katmanı protokolüdür. Açık olduğu için standardı bir RFC belgesinde, RFC 5321'de tanımlanmıştır (ekrandan, 00:20:00). Slayttaki özellikler şunlardır (ekrandan, 00:20:00):

- E-posta mesajını istemciden (bağlantıyı başlatan posta sunucusu) sunucuya güvenilir biçimde aktarmak için TCP kullanır; port 25'tir.
- Aktarım doğrudandır: gönderen sunucu (istemci gibi davranarak) alan sunucuya bağlanır.
- Aktarımın üç aşaması vardır: el sıkışma (selamlaşma, greeting), mesajların aktarımı ve kapanış.
- HTTP'deki gibi komut/yanıt etkileşimi vardır: komutlar ASCII metindir, yanıt bir durum kodu ve bir açıklama ifadesinden (phrase) oluşur.
- Mesajlar 7 bit ASCII olmalıdır.

TCP kullanıldığı için önce üç yönlü el sıkışma yapılır; ardından kalıcı bağlantı üzerinden e-posta gönderen sunucudan alan sunucuya aktarılır; son aşama bağlantının kapatılmasıdır. Komutlar ASCII olduğu için protokol insan tarafından okunabilir.

> **Ders sonrası not:** Altyazıda mesajların "3 bit ASCII" olması gerektiği geçiyor; bu büyük olasılıkla bir Whisper hatasıdır. Slaytta ve hocanın sonraki anlatımında doğrusu 7 bit ASCII'dir (ekrandan, 00:20:00).

### 4.2 Örnek SMTP etkileşimi

Hoca, sunucu (S) ve istemci (C) arasındaki örnek bir diyaloğu satır satır okudu. Burada S alan sunucu, C ise gönderen sunucudur; hocanın dediği gibi "ikisi de aslında sunucudur". Sunucunun adı hamburger.edu, istemcinin alan adı crepes.fr'dir (Fransa). Anlatılan akış şöyledir:

```text
S: 220 hamburger.edu
C: HELO crepes.fr
S: 250 Hello crepes.fr, pleased to meet you
C: MAIL FROM: <alice@crepes.fr>
S: 250 alice@crepes.fr... Sender ok
C: RCPT TO: <bob@hamburger.edu>
S: 250 bob@hamburger.edu ... Recipient ok
C: DATA
S: 354 Enter mail, end with "." on a line by itself
C: Do you like ketchup?
C: How about pickles?
C: .
S: 250 Message accepted for delivery
C: QUIT
S: 221 hamburger.edu closing connection
```

<!-- BELİRSİZ: Bu slayt karelerde yok (00:21-00:24 arası). Diyalog altyazıdaki anlatımdan ve kitaptaki standart örnekten kuruldu. RCPT TO yanıtı ve DATA sonrası 354 yanıtı altyazıda okunamıyor (00:21:59-00:22:29). -->

Açıklamalar:

- Bağlantı kurulunca sunucu bir durum koduyla (220) kendini tanıtır.
- İstemci HELO ile selam verir; sunucu 250 ve "pleased to meet you" gibi çok okunabilir bir ifadeyle yanıt verir.
- MAIL FROM ile gönderen, RCPT TO ile alıcı bildirilir; sunucu ikisini de onaylar ("Sender ok" gibi).
- DATA komutundan sonra sunucu, mesajın nasıl gönderileceğini söyler: tek başına bir nokta içeren satırla bitir. İstemci mesajı satır satır yollar ("Do you like ketchup?", "How about pickles?") ve sonunda tek başına "." içeren bir satır gönderir.
- Sunucu mesajın teslim için kabul edildiğini bildirir; Bob'un posta sunucusu mesajı Bob'un posta kutusuna koyar.
- İstemci QUIT ile TCP bağlantısının kapatılmasını başlatır; sunucu 221 ve "closing connection" ifadesiyle yanıt verir.

> **Ders sonrası not:** Altyazıda mesaj kabul yanıtı "350" olarak geçiyor (00:23:14). Standart örnekte bu yanıt 250'dir; 3xx sınıfındaki kod (354) DATA komutuna verilen "mesajı girin" yanıtıdır. Bu büyük olasılıkla bir söyleyiş ya da Whisper karışıklığıdır.

### 4.3 SMTP'yi kendiniz deneyin

Slayttaki yönerge şöyledir (ekrandan, 00:25:00):

```text
telnet <servername> 25
```

- Sunucudan 220 yanıtı görülür; bu bağlantının kurulduğunu gösterir.
- Ardından HELO, MAIL FROM:, RCPT TO:, DATA, QUIT komutları girilir.
- Bu yöntem, e-posta istemcisi (reader) kullanmadan e-posta göndermeyi sağlar.

Hoca, bunun yalnız sunucu 25 numaralı porta telnet bağlantısına izin veriyorsa çalıştığını vurguladı. Slayttaki notta da güvenlik kaygıları nedeniyle bunun giderek nadirleştiği yazıyor (ekrandan, 00:25:00).

## 5. SMTP ile HTTP Karşılaştırması ve Mesaj Biçimi

### 5.1 Karşılaştırma

İki protokol de açıktır, ASCII tabanlıdır ve insan tarafından okunabilir. Hoca farkları ve benzerlikleri şöyle sıraladı:

- **Çekme ve itme:** HTTP çoğunlukla sunucudan mesaj çekme (pull) mantığıyla çalışır; SMTP ise mesajı sunucuya iter (push).
- **Komut/yanıt:** İkisinde de ASCII komut/yanıt etkileşimi ve durum kodları vardır.
- **Nesneler:** HTTP'de her nesne kendi yanıt mesajında kapsüllenir; SMTP'de birden çok nesne çok parçalı (multipart) bir mesajla gönderilebilir.
- **Bağlantı:** SMTP kalıcı (persistent) bağlantı kullanır.
- **Kodlama:** SMTP, mesajın (başlık ve gövde) 7 bit ASCII olmasını ister.
- **Mesaj sonu:** SMTP sunucusu mesajın sonunu belirlemek için CRLF.CRLF dizisini, yani tek başına nokta içeren satırı kullanır.

> **Ders sonrası not:** Hoca "HTTP kalıcı olmayan bağlantı kullanır, SMTP kalıcı bağlantı kullanır" dedi (00:26:54). HTTP'nin iki türü de vardır: HTTP/1.0 kalıcı olmayan, HTTP/1.1 ise varsayılan olarak kalıcı bağlantı kullanır. Bu karşılaştırma büyük olasılıkla kalıcı olmayan HTTP için geçerlidir.

### 5.2 E-posta mesaj biçimi

SMTP, e-posta mesajlarının alışverişini tanımlayan protokoldür (RFC 5321). Mesajın kendi sözdizimi ise ayrı bir belgede tanımlanır; hoca bu belgeyi RFC 822 olarak andı ve ilişkiyi HTTP ile HTML arasındaki ilişkiye benzetti: HTTP aktarımı, HTML ise Web belgesinin sözdizimini tanımlar.

Mesajın yapısı şöyledir:

- **Başlık (header):** `To:`, `From:` ve `Subject:` satırları.
- **Boş satır:** Başlığı gövdeden ayırır.
- **Gövde (body):** Yalnız ASCII karakterlerden oluşan mesaj metni.

Hoca, bu yapının HTTP'ye çok benzediği için kolay anlaşıldığını söyledi.

> **Ders sonrası not:** Hoca HTTP'nin tanımlandığı belgeyi "RFC 531" olarak andı (00:28:06); bu büyük olasılıkla bir söyleme ya da Whisper hatasıdır. HTTP/1.1, RFC 7230-7231 gibi belgelerde tanımlanmıştır. E-posta biçimini tanımlayan RFC 822'nin güncel sürümleri büyük olasılıkla RFC 2822 ve RFC 5322'dir.

## 6. Posta Erişim Protokolleri

Slayttaki şekilde akış şöyledir: Alice'in kullanıcı aracısı → SMTP → gönderenin e-posta sunucusu → SMTP → alıcının e-posta sunucusu → e-posta erişim protokolü (ör. IMAP, HTTP) → Bob'un kullanıcı aracısı (ekrandan, 00:30:00).

- **SMTP:** E-posta mesajının alıcının sunucusuna teslim edilmesi ve orada saklanması için kullanılır. Hem kullanıcı aracısından gönderenin sunucusuna, hem de sunucular arasında SMTP kullanılır.
- **Posta erişim protokolü:** Mesajın sunucudan alınması içindir.
  - **IMAP** (Internet Mail Access Protocol, RFC 3501): Açık bir protokoldür. Mesajlar sunucuda saklanır; IMAP, sunucudaki mesajların alınmasını, silinmesini ve klasörlerde düzenlenmesini sağlar (ekrandan, 00:30:00).
  - **HTTP:** Gmail, Hotmail, Yahoo! Mail gibi servisler, göndermek için SMTP, almak için IMAP (ya da POP) üzerine Web tabanlı bir arayüz sağlar (ekrandan, 00:30:00).

Yani posta kutusuna erişim için kullanılan tek protokol IMAP değildir; Web tabanlı servislerde HTTP de kullanılır.

## 7. DNS: Neden ve Ne?

### 7.1 Benzetme: insanların ve makinelerin kimlikleri

Hoca DNS'e bir benzetmeyle girdi. İnsanların kendilerini tanımlayan birçok benzersiz tanımlayıcısı vardır: TC kimlik numarası, ad, pasaport numarası, sigorta numarası gibi (ekrandan, 00:35:00). İnternet'te de çok sayıda uç cihaz (host, yönlendirici, köprü vb.) vardır ve bunları tanımlamak için benzersiz adresler gerekir. Uygulamaları ayırt etmek için de benzersiz tanımlayıcılar gerekir: sunucuda port numaraları uygulamayı, IP adresi ise uç cihazı tanımlar.

IP adreslerinin iki sürümü vardır; IPv4'te 32 bitlik adresler kullanılır. Slayta göre hostlar ve yönlendiriciler için IP adresi (32 bit) datagramları adreslemek için kullanılır; "hasanbalik.com" gibi "ad" ise insanlar tarafından kullanılır (ekrandan, 00:35:00).

Slayttaki soru şudur: IP adresi ile ad arasında, ve tersi yönde, nasıl eşleme yapılır? Bir sunucunun adını bilip IP adresini öğrenmek ya da bir IP adresini bilip adını öğrenmek isteyebiliriz. Bunun için bir mekanizma gerekir: Domain Name System.

### 7.2 DNS'in tanımı

Slayttaki tanım şöyledir (ekrandan, 00:35:00):

- DNS, birçok ad sunucusundan oluşan bir hiyerarşi biçiminde uygulanmış **dağıtık bir veritabanıdır**. Veritabanında IP adresi ve ad çiftleri tutulur.
- **Uygulama katmanı protokolüdür:** Hostlar ve ad sunucuları adları çözmek (adres/ad çevirisi) için haberleşir.
  - DNS İnternet'in çekirdek bir işlevidir, ama uygulama katmanı protokolü olarak gerçeklenmiştir.
  - Karmaşıklık ağın "kenarında"dır, yani uç cihazlarda ve istemcilerdedir.

> **Hocanın vurgusu:** DNS taşıma ya da ağ katmanı protokolü değil, uygulama katmanı protokolüdür; bu not edilmelidir.

### 7.3 DNS'in hizmetleri

Hoca, DNS'in ad-adres çevirisinin yanı sıra yük paylaşımı (load distribution) için de kullanıldığını anlattı. Arkada birçok Web sunucusu olabilir; tek bir ada karşılık birçok IP adresi gelir ve DNS bu tek adı farklı IP adreslerine çevirerek yükü dağıtır.

<!-- BELİRSİZ: 00:35:27-00:36:09 arasında altyazı boşluğu var; slayttaki diğer DNS hizmetleri (ör. takma ad, posta sunucusu takma adı) burada anlatılmış olabilir, ancak altyazıdan doğrulanamıyor. -->

### 7.4 Neden merkezi bir DNS yok?

Hoca "Her şeyi neden tek bir merkezi veritabanında tutmuyoruz?" diye sordu ve nedenleri sıraladı:

- **Tek hata noktası (single point of failure):** En önemli neden budur. Merkezi veritabanı çökerse bütün ağ çöker.
- **Trafik hacmi:** Ad-IP çevirisi için çok sayıda istek gelir; hepsi tek merkeze gider ve muazzam bir trafik oluşur.
- **Uzak merkezi veritabanı:** Bu kadar büyük bir veritabanını tek yerde tutmak ayrı bir sorundur.
- **Bakım:** Merkezi veritabanının bakımı zordur.
- **Ölçeklenemez.**

Ölçeği göstermek için hoca şu örneği verdi: ABD'deki bir ISP olan Comcast'in DNS sunucuları tek başına günde 600 milyar, yani $600 \times 10^9$ DNS sorgusu karşılamaktadır.

> **Hocanın vurgusu:** "600 milyar, milyon değil." Bu yalnız ABD'deki tek bir firmanın rakamıdır; bütün İnternet'teki günlük istek sayısını düşünmek bile zordur.

## 8. DNS'in Dağıtık ve Hiyerarşik Yapısı

### 8.1 Hiyerarşi

Slayttaki ağaç şöyledir (ekrandan, 00:40:00):

```text
                       Root DNS Servers                  (Root)
          /                   |                  \
  .com DNS servers     .org DNS servers     .edu DNS servers   (Top Level Domain)
   /          \              |               /          \
yahoo.com   amazon.com    pbs.org         nyu.edu     umass.edu  (Authoritative)
DNS servers DNS servers   DNS servers     DNS servers DNS servers
```

En üstte kök (root) DNS sunucuları, ikinci katmanda üst düzey alan (TLD, top level domain) sunucuları, üçüncü katmanda yetkili (authoritative) sunucular yer alır. Hoca, Türk alan adları için de ayrı bir TLD sunucusu olduğunu örnek verdi.

**Birinci yaklaşım (slayttaki örnek):** İstemci www.amazon.com için IP adresi istiyor (ekrandan, 00:40:00):

1. İstemci, .com DNS sunucusunu bulmak için kök sunucuya sorar.
2. İstemci, amazon.com DNS sunucusunu almak için .com DNS sunucusuna sorar.
3. İstemci, www.amazon.com'un IP adresini almak için amazon.com DNS sunucusuna sorar.

Bu yaklaşımda isteği yapmaktan istemci sorumludur.

### 8.2 Kök ad sunucuları

Kök ad sunucuları, adı çözemeyen ad sunucularının başvurduğu resmi, son başvuru noktasıdır. Kök ad sunucularını ayakta tutmak İnternet için inanılmaz derecede önemli bir işlevdir. DNSSEC (DNS güvenliği) kimlik doğrulama ve mesaj bütünlüğü sağlar.

Kök DNS alanını ICANN (Internet Corporation for Assigned Names and Numbers) yönetir. Dünyada 13 mantıksal kök ad sunucusu vardır ve her biri birçok kez çoğaltılmıştır. Hoca, örneğin ABD'de kök ad sunucularını çoğaltan yaklaşık 300 sunucu olduğunu, başka ülkelerde de pek çok kopya bulunduğunu söyledi.

> **Ders sonrası not:** Kitaptaki slaytta ABD'deki kopya sayısı büyük olasılıkla "yaklaşık 200" olarak verilir; hoca yaklaşık 300 dedi. Bu sayı kare ile doğrulanamadı.

### 8.3 TLD ve yetkili sunucular

TLD sunucuları .com, .org, .net, .edu gibi alanlardan ve ülke alanlarından sorumludur; hoca .fr (Fransa), .jp (Japonya) ve .tr (Türkiye) örneklerini verdi. Yetkili DNS sunucuları, kurumun kendi host adlarının IP eşlemelerini tutar; kurumun kendisi ya da bir servis sağlayıcı tarafından işletilebilir.

<!-- BELİRSİZ: 00:42:44-00:43:47 arasında altyazı kesik; TLD slaytındaki kuruluş adları (ör. .com'u işleten firma) okunamıyor. -->

### 8.4 Yerel DNS ad sunucuları

Slayttaki maddeler şunlardır (ekrandan, 00:45:00):

- Yerel DNS sunucusu hiyerarşiye tam olarak ait değildir.
- Her ISP'nin (ev ISP'si, şirket, üniversite) bir tane yerel DNS sunucusu vardır; buna "varsayılan ad sunucusu" (default name server) da denir.
- Bir host DNS sorgusu yaptığında sorgu kendi yerel DNS sunucusuna gönderilir.
  - Yerel sunucuda yakın zamandaki ad-adres çeviri çiftlerinin yerel önbelleği vardır (ama bunlar güncel olmayabilir).
  - Yerel sunucu vekil (proxy) gibi davranır ve sorguyu hiyerarşiye iletir.

Yani yerel DNS sunucusu istenen kaydı önbelleğinde bulamazsa sorguyu hiyerarşiye iletir. Bunun için iki yöntem vardır.

## 9. Ad Çözümleme: Yinelemeli ve Özyinelemeli Sorgu

### 9.1 Yinelemeli sorgu (iterated query)

Örnek: engineering.nyu.edu'daki bir host, gaia.cs.umass.edu'nun IP adresini istiyor.

1. Soldaki istekte bulunan host (engineering.nyu.edu) isteği yerel DNS sunucusuna (dns.nyu.edu) gönderir.
2. Yerel DNS sunucusu kök sunucuya umass.edu için TLD sunucusunu sorar; kök sunucu .edu TLD sunucusunun adresini döndürür.
3. Yerel sunucu TLD sunucusuna sorar; TLD sunucusu yetkili sunucunun (dns.cs.umass.edu) adresini döndürür.
4. Yerel sunucu yetkili DNS sunucusuna sorar; yetkili sunucu gaia.cs.umass.edu'nun IP adresini döndürür.
5. Yerel DNS sunucusu bu yanıtı engineering.nyu.edu'daki istemciye gönderir.

Bu yöntemde her sunucu "ben bilmiyorum, şu sunucuya sor" diye yanıt verir; soruları sırayla soran yerel DNS sunucusudur.

<!-- BELİRSİZ: 00:46:34-00:47:03 arası altyazıda yok; 2. ve 3. adımların ayrıntısı slayttaki standart akışa göre yazıldı. -->

### 9.2 Özyinelemeli sorgu (recursive query)

İstekte bulunan host, gaia.cs.umass.edu için yerel DNS sunucusuna sorar. Bu mesaj kök DNS sunucusuna iletilir; kök sunucu TLD DNS sunucusuna sorar; TLD sunucusu yetkili DNS sunucusuna sorar ve yanıt aynı yoldan geri döner.

Bu yöntem ad çözümleme yükünü sorgulanan ad sunucusuna bindirir ve özellikle hiyerarşinin üst seviyesindeki sunuculara ağır yük getirir; çünkü özyinelemeli sorguda soruları sormaktan üst sunucu sorumludur.

## 10. Önbellekleme, Kayıtlar ve DNS Mesajları

### 10.1 Önbellekleme ve kayıt güncelleme

Slayttaki maddeler şunlardır (ekrandan, 00:50:00):

- Herhangi bir ad sunucusu bir eşlemeyi öğrendiğinde bu eşlemeyi önbelleğe alır.
  - Önbellek kayıtları bir süre (TTL) sonra zaman aşımına uğrar ve silinir.
  - TLD sunucularının adresleri genellikle yerel ad sunucularının önbelleğindedir; bu yüzden kök ad sunucularına sık gidilmez.
- Önbellekteki kayıtlar güncel olmayabilir (en iyi çaba ile, best-effort, ad-adres çevirisi).
  - Bir host IP adresini değiştirirse, bütün TTL'ler dolana kadar bu değişiklik İnternet çapında bilinmeyebilir.
- Güncelleme/bildirim mekanizmaları IETF standardı olarak önerilmiştir: RFC 2136.

Hoca TLD sunucularının önbellekte tutulma nedenini, bu sunucuların yetkili sunucuların IP adreslerini tutmaktan sorumlu olmasıyla açıkladı.

> **Ders sonrası not:** Altyazıda TTL "TLL, time to leave" olarak geçiyor (00:48:45, 00:49:34). Doğrusu TTL, yani "time to live"dır.

### 10.2 DNS kaynak kayıtları (RR)

DNS, kaynak kayıtlarını (resource record, RR) saklayan dağıtık bir veritabanıdır. RR biçiminde host adı (name), değer (value, örneğin IP adresi), kaydın türü (type) ve sonda TTL bulunur: (name, value, type, ttl).

- **type = A:** name bir host adı, value o hostun IP adresidir.
- **TTL:** Kaydın geçerli olduğu belirli bir süre.

<!-- BELİRSİZ: 00:50:50-00:52:21 arasında altyazı yok; slayttaki diğer kayıt türleri (NS, CNAME, MX) bu aralıkta anlatılmış olabilir, doğrulanamıyor. -->

### 10.3 DNS protokol mesajları

DNS sorgu ve yanıt mesajları aynı biçimdedir:

- **Tanımlama (identification):** 16 bitlik bir alandır; sorgu için kullanılan numara, yanıtta da aynıdır. Böylece yanıt sorguyla eşlenir.
- **Bayraklar (flags):** Mesajın sorgu mu yanıt mı olduğunu ayırt eder; ayrıca özyineleme isteniyor (recursion desired), özyineleme mevcut (recursion available) ve yanıtın yetkili (authoritative) olup olmadığını belirtir.
- **Sorular ve cevaplar:** Sorgu için ad ve tür alanları, yanıtta ise kayıtlar (RR) bulunur.

<!-- BELİRSİZ: DNS veritabanına yeni kayıt ekleme örneği (00:53:29) altyazıda okunamıyor. -->

## 11. DNS Güvenliği

Hoca, DNS'in İnternet'te çok önemli bir rol oynadığı için saldırıların hedefi olduğunu söyledi. Slayttaki sınıflandırma şöyledir (ekrandan, 00:55:00):

- **DDoS saldırıları**
  - Kök sunucuları trafikle bombardıman etmek: Bugüne kadar başarılı olmadı. Bunun nedenleri trafik filtreleme ve yerel DNS sunucularının TLD sunucularının IP adreslerini önbellekte tutmasıdır; bu sayede kök sunucu atlanabilir.
  - TLD sunucularını bombardıman etmek: Potansiyel olarak daha tehlikelidir.
- **Yönlendirme (redirect) saldırıları**
  - Ortadaki adam (man-in-the-middle): DNS sorgularını yakalamak ve değiştirmek.
  - DNS zehirleme (poisoning): Önbellek tutan DNS sunucusuna sahte yanıtlar göndermek.
- **DNS'i DDoS için kullanmak**
  - Kaynak adresi hedef IP olacak biçimde sahtelenmiş (spoofed) sorgular göndermek. DNS sunucularının yanıtları hedefe gider ve hedef sistemin bütün kaynaklarını tüketir.
  - Yükseltme (amplification) gerektirir.

Hoca bu saldırı türlerinin DNSSEC belgesinde açıklandığını söyledi ve belgeyi "RFC 4032" olarak andı.

> **Ders sonrası not:** DNSSEC'e giriş belgesi büyük olasılıkla RFC 4033'tür; altyazıdaki "4032" söyleyiş ya da Whisper hatası olabilir. Bu numara karede görünmüyor.

## 12. Eşler Arası (P2P) Uygulamalar ve Dosya Dağıtımı

### 12.1 P2P mimarisi

Bölümün başında iki paradigma tanıtılmıştı: istemci-sunucu ve eşler arası. P2P mimaride sunucu bulunması gerekmez. Rastgele uç sistemler doğrudan haberleşir; eşler diğer eşlerden hizmet ister ve karşılığında diğer eşlere hizmet verir. Eşler aralıklı bağlanır ve IP adreslerini değiştirebilir; bu nedenle P2P mimarinin yönetimi karmaşıktır.

### 12.2 Dosya dağıtımı: istemci-sunucu ve P2P

Slayttaki soru şudur: $F$ boyutlu bir dosyayı bir sunucudan $N$ eşe dağıtmak ne kadar sürer? Eşlerin yükleme/indirme kapasitesi sınırlı bir kaynaktır (ekrandan, 01:15:00).

- $u_s$: sunucunun yükleme kapasitesi
- $u_i$: $i$. eşin yükleme kapasitesi
- $d_i$: $i$. eşin indirme kapasitesi
- Ağın bant genişliğinin bol olduğu (darboğaz olmadığı) kabul edilir.

**İstemci-sunucu yaklaşımı:**

- Sunucu iletimi: Sunucu dosyayı ağa sırayla göndermelidir. Bir kopya göndermek $F/u_s$ sürer. $N$ istemci dosyayı istediğinde $N$ kopya yüklemek $NF/u_s$ sürer.
- İstemci: Her istemci kendi kopyasını indirmelidir. En düşük istemci indirme hızı $d_{min}$ ise en uzun indirme süresi $F/d_{min}$'dir.
- Dağıtım süresi:

$$D_{c\text{-}s} \ge \max\left\{\frac{NF}{u_s},\ \frac{F}{d_{min}}\right\}$$

$N$ büyüdükçe $NF/u_s$ terimi baskın olur ve süre doğrusal artar.

**P2P yaklaşımı:**

- Sunucu iletimi: Sunucu en az bir kopya yüklemelidir: $F/u_s$.
- İstemci: Her istemci bir kopya indirmelidir; en düşük indirme süresi $F/d_{min}$.
- İstemciler toplu olarak $NF$ bit indirmelidir; en yüksek toplam yükleme hızı $u_s + \sum u_i$'dir.
- Dağıtım süresi:

$$D_{P2P} \ge \max\left\{\frac{F}{u_s},\ \frac{F}{d_{min}},\ \frac{NF}{u_s + \sum_{i=1}^{N} u_i}\right\}$$

Son terimde pay $N$ ile doğrusal artar, ama payda da $N$ ile artar; çünkü her eş beraberinde hizmet kapasitesi getirir. Bu nedenle $N$ arttığında P2P dağıtım süresi istemci-sunucuya göre çok daha az artar.

### 12.3 Sayısal örnek

Slayttaki örneğin varsayımları: istemci yükleme hızı $u$, $F/u = 1$ saat, $u_s = 10u$, $d_{min} \ge u_s$ (ekrandan, 01:20:00). Grafikte yatay eksen $N$ (0-35), dikey eksen en düşük dağıtım süresidir (saat).

Çözüm (ara adımlar eklendi):

- $F/u_s = F/(10u) = 0{,}1$ saat.
- $d_{min} \ge u_s$ olduğundan $F/d_{min} \le 0{,}1$ saat.
- İstemci-sunucu: $D_{c\text{-}s} = \max\{N \cdot 0{,}1,\ 0{,}1\} = 0{,}1N$ saat ($N \ge 1$ için).
- P2P: $\sum u_i = Nu$ olduğundan $\dfrac{NF}{10u + Nu} = \dfrac{N}{10+N}$ saat; $D_{P2P} = \max\{0{,}1,\ N/(10+N)\}$.

| $N$ | İstemci-sunucu (saat) | P2P (saat) |
|---|---|---|
| 1 | 0,1 | 0,1 |
| 5 | 0,5 | 0,333 |
| 10 | 1,0 | 0,5 |
| 20 | 2,0 | 0,667 |
| 32 | 3,2 | 0,762 |

Değerler python ile hesaplandı ve slayttaki grafikle uyumludur: istemci-sunucu eğrisi 32 eşte 3,2 saate ulaşan bir doğrudur; P2P eğrisi ise 0,8 saatin altında kalan, giderek yataylaşan bir eğridir (ekrandan, 01:20:00).

Hoca grafiği yorumlarken istemci-sunucu modelinin istemci sayısıyla doğrusal arttığını, P2P modelinin ise doğrusal artmadığını vurguladı; $N$ arttıkça P2P'nin verimliliği istemci-sunucu modelinden daha iyidir.

> **Ders sonrası not:** Hoca dikey eksenin "0'dan 5'e" gittiğini söyledi (01:19:22); karede dikey eksen 0 ile 3,5 arasındadır (ekrandan, 01:20:00).

## 13. BitTorrent

En yaygın P2P dosya dağıtım sistemi BitTorrent'tir.

- Dosya 256 Kb'lik parçalara (chunk) bölünür.
- **Torrent**, tüm dosyayı değil dosyanın parçalarını değiş tokuş eden eşler grubudur.
- **Tracker**, torrente katılan eşlerin kaydını tutar.

Örnek: Alice sisteme yeni gelen bir kullanıcıdır. Tracker'dan eş listesi alır ve dosya parçaları bu eşler arasında P2P bağlantılarla değiş tokuş edilir.

Torrente katılan eş başta hiçbir parçaya sahip değildir, ama zamanla diğer eşlerden parça biriktirir. Tracker'a kaydolarak eş listesini alır ve diğer eşlere bağlanır. Dosyanın tamamını aldıktan sonra gruptan bencilce ayrılabilir ya da grupta kalıp parçaları diğer eşlere dağıtmayı sürdürebilir.

<!-- BELİRSİZ: 01:21:59-01:22:26 arası altyazı bozuk; bu aralıkta eşin parça yüklerken indirmesi ve komşu eşlerin değişmesi gibi ayrıntılar anlatılmış olabilir. -->

**Parça isteme:** Herhangi bir anda farklı eşler dosya parçalarının farklı alt kümelerine sahiptir. Eş (Alice) düzenli olarak her eşten sahip olduğu parçaların listesini ister ve eksik parçaları ister.

**Parça gönderme (tit-for-tat):** Alice, kendisine o anda en yüksek hızla parça gönderen dört eşe parça gönderir. Ayrıca her 30 saniyede rastgele başka bir eş seçip ona parça göndermeye başlar; buna "iyimser olarak engeli kaldırma" (optimistically unchoke) denir. Yeni seçilen eş ilk dörde katılabilir.

Slayttaki senaryo: Alice, Bob'un engelini iyimser olarak kaldırır; Alice Bob'un en iyi dört sağlayıcısından biri olur, Bob da karşılık verir ve Alice'in en iyi dört sağlayıcısından biri olur. Daha yüksek yükleme hızına sahip eş daha iyi ticaret ortakları bulur ve dosyayı daha hızlı alır.

<!-- BELİRSİZ: 01:23:12-01:23:39 arası altyazı bozuk; ilk dört eşin ne sıklıkla yeniden değerlendirildiği bu aralıkta söylenmiş olabilir. -->

> **Ek bilgi (derste anlatılmadı):** Kurose-Ross kitabında en iyi dört eşin büyük olasılıkla her 10 saniyede bir yeniden değerlendirildiği belirtilir. Diğer eşler "engellenmiş" (choked) durumdadır ve bu eşlerden parça istenmez.

## 14. Video Akışı

### 14.1 Sorunun büyüklüğü

Akış videosu trafiği İnternet'in en büyük tüketicisidir; hoca pandemiyle bunun daha da yaygınlaştığını söyledi. 2020'de ev ISP trafiğinin yaklaşık %80'ini Netflix, YouTube ve Amazon Prime tüketiyordu. Kullanıcı sayısı yaklaşık 1 milyara ulaşabilir. Bu içeriği 1 milyar kullanıcıya nasıl dağıtacağız?

Tek bir dev video sunucusu çözüm değildir; ağ kapasitesi buna yetmez. Ayrıca kullanıcılar Wi-Fi, mobil gibi farklı kapasitedeki erişim ağlarındadır. Çözüm, DNS'te olduğu gibi merkezi olmayan, dağıtık ve uygulama seviyesinde bir altyapıdır.

<!-- BELİRSİZ: 01:26:17-01:26:38 arası altyazı bozuk; heterojenlik vurgusu (farklı kullanıcı kapasiteleri) yalnız "Wi-Fi" ve "mobile" kelimelerinden çıkarıldı. -->

### 14.2 Video ve kodlama

Video, sabit bir hızda gösterilen görüntüler (kareler) dizisidir; örneğin saniyede 24 kare. Hoca koşan bir adam resmiyle anlattı: kare $i$ ve kare $i+1$ art arda gösterildiğinde beynimiz bunları birleştirir ve adamın koştuğunu algılarız. Dijital görüntü bir piksel dizisidir; her piksel bitlerle temsil edilir ve değeri o pikselin rengini gösterir.

Kodlama, dosya ya da video boyutunu küçültmek için görüntü içindeki ve görüntüler arasındaki fazlalığı (redundancy) kullanarak bit sayısını azaltır. İki tür kodlama vardır ve ikisi birlikte kullanılabilir (ekrandan, 01:30:00):

- **Uzamsal (spatial) kodlama:** Görüntü içinde yapılır. Slayttaki örnek: aynı renkteki (tamamı mor) $N$ değeri tek tek göndermek yerine yalnız iki değer gönderilir: renk değeri (mor) ve tekrar sayısı ($N$).
- **Zamansal (temporal) kodlama:** Bir görüntüden sonrakine yapılır. Slayttaki örnek: kare $i+1$'in tamamını göndermek yerine yalnız kare $i$'den farklar gönderilir.

Bit hızına göre iki yöntem vardır (ekrandan, 01:30:00):

- **CBR (constant bit rate, sabit bit hızı):** Video kodlama hızı sabittir.
- **VBR (variable bit rate, değişken bit hızı):** Uzamsal ve zamansal kodlama miktarı değiştikçe kodlama hızı da değişir.

Örnekler (ekrandan, 01:30:00):

| Standart | Kullanım | Hız |
|---|---|---|
| MPEG-1 | CD-ROM | 1,5 Mbps |
| MPEG-2 | DVD | 3-6 Mbps |
| MPEG-4 | Sıklıkla İnternet'te | 64 Kbps - 12 Mbps |

### 14.3 Depolanmış video akışı

Senaryoda solda video sunucusu, ortada İnternet, sağda evdeki istemci vardır. Video sunucuda depolanmıştır. Temel zorluk, sunucudan istemciye bant genişliğinin zamanla değişmesidir (ağ tıkanıklığı nedeniyle).

<!-- BELİRSİZ: 01:30:33-01:31:00 arası altyazı halüsinasyonla dolu; bant genişliğinin neden değiştiğine dair açıklama okunamıyor. -->

Video dijital olduğu için adım adım kaydedilebilir: örneğin her saniyede 30 kare olacak şekilde sunucuya kaydedilir. Gönderim sırasında video, kaydedildiği hızla (saniyede 30 kare) ağa verilir. Örnekte ağın videoyu aynı hızda aktarmaya yettiği varsayılır.

Akışta (streaming) istemci, sunucu videonun sonraki kısımlarını göndermeye devam ederken erken kısmı oynatmaya başlar. Örneğin 10. saniyedeki video hâlâ ağdayken 2. saniye oynatılıyor olabilir. İstemci, gönderilen kısmın zamanında geleceğini varsayar.

**Sürekli oynatma kısıtı:** İstemci oynatmaya başladıktan sonra oynatma, orijinal kayıt zamanlamasıyla eşleşmelidir. Ancak ağ gecikmesi değişkendir; buna **jitter** denir. Bu nedenle istemci tarafında bir tampon (buffer) gerekir: ağ tamponu doldurur, uygulama tampondan oynatır.

**İstemci etkileşimi:** Film izlerken durdurabilir, ileri sarabilir, geri sarabilir ya da videonun başka bir yerine atlayabiliriz. Bu durumda tampondaki veri kullanılamaz hâle gelebilir; geri sarınca alınan paketlerin yeniden gönderilmesi gerekebilir.

### 14.4 Oynatma tamponu

Slayttaki grafikte yatay eksen zaman, dikey eksen kümülatif veridir (ekrandan, 01:35:00):

- Kırmızı merdiven: sabit bit hızında video iletimi (sunucu tarafı).
- Siyah merdiven: istemcide video alımı. Değişken ağ gecikmesi nedeniyle bazı kareler diğerlerinden daha geç gelir; basamaklar düzensizdir.
- Mavi merdiven: istemcide sabit bit hızında oynatma. İstemci oynatmayı bir süre geciktirir (client playout delay); alım eğrisi ile oynatma eğrisi arasındaki fark tamponda bekleyen videodur (buffered video).

Slayttaki sonuç: istemci tarafında tamponlama ve oynatma gecikmesi, ağın eklediği gecikmeyi ve gecikme değişimini (delay jitter) telafi eder (ekrandan, 01:35:00). Oynatma, iletildiği ya da kaydedildiği zamanlamayla aynı olmalıdır.

### 14.5 DASH

Hoca, tamponlamanın her durumda çözüm olmadığını (ileri-geri sarma, durdurma gibi durumlar) ve başka bir çözüm olarak DASH'i anlattı. DASH, Dynamic Adaptive Streaming over HTTP'nin kısaltmasıdır.

**Sunucu tarafı:**

- Video dosyası birden çok parçaya (chunk) bölünür; hoca bunu BitTorrent'teki parçalara benzetti.
- Her parça farklı hızlarda kodlanıp saklanır, çünkü farklı ağ hızları farklı kalite gerektirir. Farklı hızlardaki kodlamalar farklı dosyalarda tutulur.
- **Manifest dosyası** farklı parçaların URL'lerini verir.

**İstemci tarafı:**

- İstemci düzenli aralıklarla sunucu-istemci bant genişliğini ölçer.
- Manifest dosyasına bakarak ölçtüğü bant genişliğine uygun parçayı ister. Her seferinde o anki bant genişliğinde sürdürülebilir en yüksek kodlama hızını seçer.
- Farklı zamanlarda, ölçtüğü bant genişliğine göre farklı kodlama hızları seçebilir.

> **Hocanın vurgusu:** DASH'te bütün zekâ istemcidedir. Bant genişliğini ölçen ve sunucudan ilgili URL'yi, yani uygun kodlanmış video parçasını isteyen istemcidir.

İstemcinin verdiği kararlar:

- **Ne zaman parça istenecek:** Tampon ne boşalacak (starvation) ne taşacak (overflow) şekilde.
- **Hangi kodlama hızı istenecek:** Daha çok bant genişliği varken daha yüksek kalite, daha az bant genişliği varken daha düşük kalite.
- **Nereden istenecek:** İstemciye yakın ve URL'yi tutan sunucudan.

Özetle akış medyasında kodlama, DASH ve tampon birlikte kullanılır.

## 15. İçerik Dağıtım Ağları (CDN)

Slayttaki zorluk şudur: milyonlarca video arasından seçilen içerik, yüz binlerce eş zamanlı kullanıcıya nasıl aktarılır (ekrandan, 01:40:00)?

Birinci seçenek, başta da söylenen tek dev sunucudur; ancak bu tek hata noktası ve tıkanıklık yaratır ve ölçeklenmez. İkinci seçenek CDN'dir: videoların birden çok kopyasını coğrafi olarak dağıtılmış birden çok sitede saklamak ve sunmak. İki yaklaşım vardır (ekrandan, 01:40:00):

- **Enter deep:** CDN sunucularını birçok erişim ağının derinlerine yerleştirmek; kullanıcılara yakındır. Örnek Akamai: 2015'te 120'den fazla ülkede 240.000 sunucu. Hoca bugün bu sayının daha da büyük olduğunu ekledi.
- **Bring home:** Erişim ağlarının yakınındaki (ama içinde olmayan) POP'larda daha az sayıda (onlarca) büyük küme. Limelight bu yaklaşımı kullanır.

### 15.1 CDN'de içerik erişimi

Slayttaki şekilde ağ çekirdeğinde yönlendiriciler, bir tarafta Netflix ve dağınık CDN düğümleri vardır. CDN, içeriğin kopyalarını CDN düğümlerinde saklar; örneğin Netflix "Mad Men" dizisinin kopyalarını dünyanın birçok yerinde tutar.

1. Evdeki abone "Mad Men"i ister.
2. Netflix bir manifest dosyası gönderir.
3. İstemci manifeste bakarak parçaları en yakın (ya da en uygun) CDN sunucusundan alır.
4. Ağ hızı değişirse istemci zamanla başka bir kopyaya ya da sunucuya geçebilir.

### 15.2 OTT (over the top)

En üstte, İnternet'in host'tan host'a iletişimi bir hizmet olarak kullanılır; içerik bir tür buluttan gelir. OTT'nin zorlukları, tıkanık bir ağla başa çıkmaktır:

- Hangi CDN düğümünden içerik alınacak?
- Tıkanıklık varken izleyicinin davranışı ne olacak?
- Hangi içerik hangi CDN düğümüne konacak?

## Örnek Sorular

**Soru 1** (ekrandan, 00:35:00): IP adresi ile ad arasında, ve tersi yönde, eşleme nasıl yapılır?

> **Cevap (derste verildi):** Domain Name System (DNS) ile. DNS, birçok ad sunucusundan oluşan hiyerarşik ve dağıtık bir veritabanıdır; hostlar ve ad sunucuları uygulama katmanı protokolüyle haberleşerek adları çözer.

**Soru 2** (ekrandan, 00:40:00): İstemci www.amazon.com'un IP adresini istiyor. Birinci yaklaşımda hangi sunuculara, hangi sırayla sorulur?

> **Cevap (derste verildi):** (1) .com DNS sunucusunu bulmak için kök sunucuya, (2) amazon.com DNS sunucusunu almak için .com DNS sunucusuna, (3) www.amazon.com'un IP adresini almak için amazon.com DNS sunucusuna.

**Soru 3** (derste sözlü, 00:45:48): engineering.nyu.edu'daki bir host gaia.cs.umass.edu'nun IP adresini istiyor. Yinelemeli ve özyinelemeli sorguda mesajlar nasıl akar?

> **Cevap (derste verildi):** Yinelemelide host yerel DNS sunucusuna (dns.nyu.edu) sorar; yerel sunucu sırayla kök, TLD ve yetkili sunucuya (dns.cs.umass.edu) kendisi sorar, her biri bir sonrakinin adresini verir, son yanıt hosta iletilir. Özyinelemelide sorgu yerel sunucudan köke, kökten TLD'ye, TLD'den yetkili sunucuya iletilir ve yanıt aynı yoldan döner; yük üst seviyedeki sunuculara biner.

**Soru 4** (derste sözlü, 00:16:45): Posta sunucuları arasında neden TCP bağlantısı açılır?

> **Cevap (derste verildi):** E-posta güvenilir aktarım gerektirdiği için; SMTP bu yüzden TCP üzerinde, 25 numaralı portta çalışır.

**Soru 5** (ekrandan, 01:15:00): $F$ boyutlu bir dosyayı bir sunucudan $N$ eşe dağıtmak, istemci-sunucu ve P2P yaklaşımlarında en az ne kadar sürer?

> **Cevap (derste verildi):** $D_{c\text{-}s} \ge \max\{NF/u_s,\ F/d_{min}\}$ ve $D_{P2P} \ge \max\{F/u_s,\ F/d_{min},\ NF/(u_s + \sum u_i)\}$.

**Soru 6** (ekrandan, 01:20:00): İstemci yükleme hızı $u$, $F/u = 1$ saat, $u_s = 10u$, $d_{min} \ge u_s$ iken $N = 10$ ve $N = 32$ için en düşük dağıtım süreleri nedir?

> **Çözüm (derste verilmedi):** İstemci-sunucu: $D = 0{,}1N$ saat, yani $N=10$ için 1 saat, $N=32$ için 3,2 saat. P2P: $D = \max\{0{,}1,\ N/(10+N)\}$, yani $N=10$ için 0,5 saat, $N=32$ için $32/42 \approx 0{,}762$ saat. Değerler python ile hesaplandı; derste yalnız grafik gösterildi.

## Dersin Toparlaması

Bu derste uygulama katmanının kalan uygulamaları tamamlandı. E-postada kullanıcı aracısı, posta sunucusu ve SMTP'den oluşan yapı, Alice'ten Bob'a giden bir mesajın altı adımlık yolculuğu, SMTP'nin TCP üzerinde 25 numaralı portta çalışan ASCII komut/yanıt protokolü olması ve mesajı almak için IMAP ya da HTTP kullanıldığı görüldü. DNS'in ad ile IP adresi arasında çeviri yapan, kök, TLD ve yetkili sunuculardan oluşan dağıtık ve hiyerarşik bir veritabanı olduğu; yerel sunucunun vekil gibi davrandığı; yinelemeli ve özyinelemeli sorgu farkı; önbellek, TTL, kaynak kayıtları, mesaj biçimi ve DNS'e yönelik saldırılar işlendi.

Dersin ikinci yarısında P2P mimarinin ölçeklenme avantajı, dağıtım süresi formülleri ve sayısal grafikle gösterildi; BitTorrent'in parça, tracker ve tit-for-tat mekanizması anlatıldı. Son olarak video kodlama, istemci tamponu, DASH ve CDN ile milyonlarca kullanıcıya video akışının nasıl sağlandığı ele alındı. Hoca bunun uygulama katmanının son uygulaması olduğunu belirtti; böylece bölümdeki bütün uygulama başlıkları tamamlandı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
