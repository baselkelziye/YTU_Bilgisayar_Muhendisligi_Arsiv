# Ders 4 Genişletilmiş Notu: Güvenlik Prensipleri ve İşletim Sistemi Güvenliği

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Amacı ve Zafiyetlerin Kaçınılmazlığı
- 2. Derinlemesine Savunma (Defense in Depth)
- 3. En Az Yetki (Least Privilege)
- 4. Yetki Ayrımı (Privilege Separation)
- 5. Güvenlik Politikaları: Subject, Object, Operation
- 6. UNIX Güvenlik Modeli: Kullanıcılar ve Gruplar
- 7. Dosya Sahipliği ve İzinler
- 8. Erişim Kontrol Listeleri ve Rol Tabanlı Erişim Kontrolü
- 9. Süreçler ve Kullanıcı Kimlikleri
- 10. Apache ve SSH Örnekleri
- 11. SETUID Biti: Yetki Yükseltme
- 12. Linux Yetenekleri (Capabilities) ve UNIX Modelinin Değerlendirmesi
- 13. Windows Güvenlik Modeli
- 14. ACL ile Yetenek (Capability) Karşılaştırması
- 15. Masaüstlerinde Zayıf Koruma
- 16. Chrome'un Süreç Mimarisi ve Yetki Ayrımı
- 17. macOS ve Android'de İzolasyon
- 18. Açık Tasarım ve Basitlik
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Amacı ve Zafiyetlerin Kaçınılmazlığı

Bu ders, önceki haftalarda görülen saldırı ve savunma mekanizmalarının üzerine kurulur. Soru şudur: güvenli sistemler oluşturmak için tasarımda, gerçeklemede ve kullanımda hangi prensiplere dikkat etmeliyiz? Önce bu temel prensipler tanımlanıp neden önemli oldukları anlatıldı, ardından işletim sistemi güvenliğine geçildi. Slayt seti Stanford CS155 "Computer and Network Security" dersinin "Security Principles and OS Security" sunumudur (ekrandan, 02:00:00).

Başlangıç noktası "Vulnerabilities are Inevitable" slaytıdır (ekrandan, 00:05:00). Tek bir buffer overflow, use-after-free ya da null pointer dereference (ilklendirilmemiş, sıfır değerli bir işaretçi üzerinden veriye erişme) saldırgana kötü niyetli kod çalıştırma fırsatı verebilir. Önceki derslerde görüldüğü gibi savunma mekanizmaları uygulandığında bile başarısız bir buffer overflow saldırısı hizmet engelleme (denial of service) saldırısına dönüşür. Hataları bulma ve önlemede daha iyi hâle gelsek de zafiyetler hâlâ yaygındır ve slaytın vurguladığı gibi her zaman hata olacaktır. Bu yüzden sistemler zafiyetler ve kötü niyetli kullanıcılar karşısında dayanıklı (resilient) olacak şekilde tasarlanmalıdır.

Hoca, daha önce önerilen bir çözümü yeniden ele aldı: tip güvenli diller (type safe language). Bu diller tip uyuşmazlığı olan atamalara izin vermez ve böyle bir kod için çıktı üretmez. Java, Go ve Python bu dillere örnektir. Ancak bu dillerin kendisi ya da çalışma ortamları (runtime) C/C++ ile yazılmış kütüphanelere dayanır. Python bugün veri bilimi ve yapay zekâ alanında çok popülerdir, ama Python'ın kendisi C ile yazılmıştır. Slaytta Python için 2016 yılına ait bir CVE (Common Vulnerabilities and Exposures) kaydı gösterildi. Yani dil güvenli sınıflandırılsa bile onu oluşturan modüllerde şimdiye kadar görülen zafiyetler bulunabilir ve saldırgan bunları inceleyerek saldırabilir.

> **Hocanın vurgusu:** Hatalar var ve bu hatalarla yaşamayı öğreneceğiz. "Bundan sonra hiç hata olmayacak" diyebileceğimiz bir seçenek yok.

> **Ders sonrası not:** Altyazıda CVE açılımı "Common Vulnerability and Exploit" olarak geçiyor; doğru açılım büyük olasılıkla "Common Vulnerabilities and Exposures"dır.

## 2. Derinlemesine Savunma (Defense in Depth)

Hoca bu prensibi her zaman söylediği bir benzetmeyle anlattı: savunma bir hat şeklinde değil, bir yüzey (satıh) şeklinde kurulmalıdır; "hattı müdafaa değil, sathı müdafaa". Birden fazla güvenlik tedbiri olmalıdır; bir noktadaki zafiyet, başka bir noktada alınmış tedbirle en aza indirilebilir ya da tamamen bertaraf edilebilir.

Slayt: "Systems should be built with security protections at multiple layers" (ekrandan, 00:10:00). Örnek soru: Chrome'un JavaScript yorumlayıcısında bir zafiyet varsa ve saldırgan bunu kullanmanın bir yolunu bulduysa ne olur?

- **Chrome** kötü niyetli web sitesinin diğer sekmelere erişmesini engellemelidir. Bir sekmede kötü niyetli kod çalışırken diğer sekmelerdeki verilere ulaşamamalıdır. Bu, işletim sistemindeki süreç tabanlı izolasyonun aynısıdır.
- **İşletim sistemi** diğer süreçlere (ör. parola yöneticisine) erişimi engellemelidir. Chrome sekmeleri iş parçacığı (thread) olarak değil süreç olarak gerçeklerse ve işletim sistemi süreçlerin izin olmadan birbiriyle veri alışverişi yapmasını engellerse, bir sekmedeki sorun diğerlerini etkilemez.
- **Donanım** aygıt firmware'ine kalıcı zararlı yazılım kurulmasını engellemelidir. Anakarttaki BIOS (UEFI ya da standart BIOS) ya da anakart üzerindeki kontrolörlerin firmware'i güncellenirken kötü niyetli kod enjekte edilmeye çalışılabilir.
- **Ağ** zararlı yazılımın yakındaki bilgisayarlara bulaşmasını engellemelidir.

Firmware örneğinin arkasındaki prensip şudur: bir aygıtın kontrolünü ele geçiren, üzerinden akan veriyi istediği yere yönlendirebilir. Hoca bir disk kontrolörü düşünmeyi önerdi: firmware güncellenirken kötü niyetli bir firmware yüklendiyse ve farkına bile varılmadıysa, diske yazılan ve okunan her verinin bir kopyası başka bir yere gönderilebilir. Üst katmanda kullanıcı ve süreç seviyesinde ne kadar izolasyon yapılmış olursa olsun, hepsi alt tarafta tek bir noktada birleşir. Oradaki bir zafiyet en yetkilisinden en yetkisizine kadar her kullanıcının verisini ifşa edebilir.

Ağ örneğinde, zararlı kodlar bir sistemi ele geçirdiklerinde ağda başka hangi sistemlerin olduğuna bakar. Hoca bunun özellikle kurumsal kullanıcılar için geçerli olduğunu söyledi: kurumsal bir bilgisayarda bir açık varsa, uygulanan ortak güvenlik politikası yüzünden aynı ağdaki diğer sistemlerde de aynı açığın olma olasılığı çok yüksektir. Saldırgan bir makineyi atlama taşı gibi kullanıp diğerlerine geçer.

Sonuç olarak derinlemesine savunmada tek bir noktada tedbir alınmaz; o noktadaki zafiyetle başlayan saldırının devamında kullanılabilecek bütün noktalarda da tedbir alınır ve yapı bunun üzerine kurulur.

## 3. En Az Yetki (Least Privilege)

Slayt tanımı: "Users should only have access to the data and resources needed to perform routine, authorized tasks" (ekrandan, 00:15:00). Hoca bunu şöyle formüle etti: bir kullanıcının günlük olarak yapmakla yetkili ve sorumlu olduğu işler için ihtiyaç duyduğu minimum güvenlik seviyesi, aslında o kullanıcının sahip olması gereken maksimum güvenlik seviyesidir. Daha fazlası verilirse kullanıcı bunu hatalı, amaç dışı ya da kötü niyetli kullanabilir.

Slayttaki gerçek hayat örnekleri:

- Öğretim üyesi yalnız kendi verdiği derslerin notlarını verebilir veya değiştirebilir. Diğer öğretim üyelerinin derslerindeki notlar, aynı unvana sahip olunsa bile onun sınırları dışındadır.
- Yalnız güvenlik soruşturması (background check) yapılmış çalışanlar gizli belgelere erişebilir. Herkes erişirse bilginin yayılımı kontrol edilemez.

Aynı mantık süreçler için de geçerlidir. Bir sürece yapması gereken iş için gerekenden fazla yetki verilirse, bu süreç saldırıya uğrayıp saldırganın kontrolüne geçtiğinde çok ciddi bir güvenlik açığı oluşur.

## 4. Yetki Ayrımı (Privilege Separation)

Bu prensibe "compartmentalization" (bölümlendirme) da denir. Hoca kelimeyi trendeki kompartımanla açıkladı: özellikle uzun yol trenlerinde herkes aynı trende seyahat eder, ama yolcular birbirinden bölümlerle ayrılmıştır. Bu bazen mantıksal, bazen fiziksel bir bölümlemedir.

Slayt (ekrandan, 00:20:00): en az yetki prensibi, sistemin erişimi sınırlanabilen parçalara bölünmesini gerektirir; buna yetki ayrımı denir. Sistemi gereken en az yetkiye sahip bileşenlere bölmek, saldırganın bütün sistemi ele geçirmesini engelleyebilir.

Arkasındaki motivasyon basittir. Saldırgan bir buffer overflow, use-after-free ya da null pointer dereference saldırısını başarıyla gerçekleştirebilir. Ama ele geçirdiği bileşen hem işi için gereken minimum yetkiye sahipse hem de diğer bileşenlerden yetki açısından izole edilmişse, saldırgan yalnız o bileşeni ele geçirmiş olur. Bu durumda hatalı ya da kötü niyetli çalışan bileşeni bulmak, izole etmek ve düzeltmek kolaylaşır; saldırganın o bileşen üzerinden başka yerlere atlaması da engellenir.

Bu prensipler yalnız kullanıcılar için geçerli değildir (Least Privilege and Privilege Separation apply to more than just users):

- **UNIX:** Bir kullanıcı yalnız kendi dosyalarını okuyabilmelidir. Hoca burada "read"in okuma, yazma ve çalıştırma olarak geniş düşünülmesini istedi. Bu örnekler Windows ve genel olarak işletim sistemleri için de düşünülebilir.
- **UNIX:** Bir süreç başka bir sürecin belleğini okuyamamalıdır. İzin verilmediği ya da işletim sisteminin tanımladığı düzgün mekanizmalar kullanılmadığı sürece bunun bir anlamı yoktur.
- **Mobil:** Bir uygulama başka bir uygulamanın verisini düzenleyememelidir. Telefon ve tabletlerdeki uygulamaların izin verilmeden birbirlerinin verilerine erişmesi bir güvenlik tehdididir.
- **Web:** Bir alan adı (domain) yalnız kendi çerezlerini (cookie) okuyabilmelidir.

Çerez örneğinde hoca şunu açıkladı: Google, Yahoo, üniversite sitesi ya da Zoom gibi sitelere erişildiğinde sunucu, daha sonra kullanıcıyı hatırlayıp kaldığı yerden devam ettirebilmek için tarayıcıya çerezler gönderir. Google'ın gönderdiği çerezi Zoom okuyamamalı, Zoom'unkini başka bir site okuyamamalıdır. Buradaki domain, arka tarafta o domaine hizmet veren web ve uygulama sunucusudur. Hangi domainin hangi çerezi okuyabileceğine karar veren merkezi bir otorite yoktur; çerezi gönderen sunucu, gönderirken çerezin izolasyon seviyesini de belirtir. Normal şartlarda gönderilen çerezi yalnız gönderen domain okuyabilir ya da değiştirebilir.

Hoca ardından en az yetkinin yalnız kullanıcılar için değil, kullanıcıların eriştiği varlıklar için de geçerli olması gerektiğini söyledi: "Subjects should only have access to data and resources needed to perform routine authorized tasks." Gerekçesi, bu varlıkların pasif olmak zorunda olmaması, aktif de olabilmesidir.

> **Ders sonrası not:** Hoca bu kısımda (00:23:42) "kullanıcıların eriştiği kaynaklara subject diyoruz" dedi. Bir sonraki slaytta kendisinin de anlattığı gibi subject, erişimi yapan taraftır (kullanıcı, uygulama, süreç); erişilen kaynak ise object'tir. Buradaki "subject" kelimesini kullanıcılar dahil bütün aktif varlıklar olarak anlamak gerekir.

## 5. Güvenlik Politikaları: Subject, Object, Operation

Güvenlik politikaları oluşturulurken, değerlendirilirken, incelenirken ve uygulanırken üç temel soru sorulur (ekrandan, 00:25:00):

- **Subject (Kim?):** Sistemde eylemde bulunan özneler (acting system principals); ör. kullanıcı, uygulama, süreç.
- **Object (Ne?):** Korunan kaynaklar; ör. bellek, dosyalar, donanım aygıtları (disk kontrolörü, ağ kontrolörü gibi).
- **Operation (Nasıl?):** Subject'in object üzerinde yaptığı işlem; ör. okuma, silme.

Slayttaki örnek politikalarda subject mavi, operation kırmızı, object yeşil renkle işaretlenmişti:

- UNIX: Bir **kullanıcı**, diğer kullanıcıların **dosyalarını** **silememeli**.
- UNIX: Bir **süreç**, başka bir sürecin **belleğini** **okuyamamalı**.
- Mobil: Bir **uygulama** yalnız kendi **verisini** **düzenleyebilmeli**.
- Web: Bir **domain**, başka bir domainin **çerezlerini** **okuyamamalı**.

Politikalar, yani kurallar bütünü, bu üç sorunun net cevapları üzerine kurulur. Daha sonra da bu kuralların uygulanıp uygulanmadığı denetlenmelidir: bir saldırı başarılı olduysa, hangi kural eksik olduğu ya da hangi kuralın kontrolü atlandığı için başarılı olduğunun analizi yapılabilmelidir.

## 6. UNIX Güvenlik Modeli: Kullanıcılar ve Gruplar

UNIX'te üç soru şöyle cevaplanır:

- **Subject:** kullanıcılar ve süreçler.
- **Object:** sıradan dosyalar ve dizinler; ayrıca UNIX'in yapısı gereği ağ haberleşmesinde kullanılan soketler, süreçler arası haberleşmede kullanılan pipe'lar, donanım aygıtları, çekirdekteki işletim sistemi verileri, süreçleri tanımlayan yapılar ve süreçlerin işlediği veriler.
- **Operation:** üç temel erişim işlemi: okuma (read), yazma (write), çalıştırma (execute).

### 6.1 Hesap türleri ve UID

Slayt (ekrandan, 00:30:00): UNIX sistemlerinde çok sayıda hesap vardır.

- **Servis hesapları:** arka plan süreçlerini çalıştırmak için kullanılır (ör. web sunucusu). Apache kullanılıyorsa genelde `apache`, Nginx kullanılıyorsa `nginx` ya da her ikisi için de `httpd` gibi bir kullanıcı açılır. Bu adı gören, bunun sıradan bir kullanıcı değil web sunucusu hizmeti veren bir hesap olduğunu anlar.
- **Kullanıcı hesapları:** genellikle belirli bir insana bağlıdır.

Servis ya da gerçek kişi fark etmeksizin her kullanıcının tekil, tekrar etmeyen bir tamsayı kimliği vardır: User ID, UID. UID 0, her şeye kısıtsız erişebilen özel `root` kullanıcısına ayrılmıştır. Birçok sistem işlemi yalnız root olarak çalıştırılabilir.

### 6.2 /etc/passwd

Kullanıcı tanımları `/etc/passwd` dosyasındadır. Hoca örnek bir dosya üzerinden satırları okudu. En üstteki `root` satırında UID 0, grup ID'si 0, kullanıcı adı root, ev dizini `/root` ve oturum açınca çalışacak komut satırı yorumlayıcısı (kabuk) yer alır. <!-- BELİRSİZ: /etc/passwd örneğinin karesi yok; altyazıda kabuk yolu "1005" diye bozulmuş, büyük olasılıkla /bin/bash. -->

Diğer örnek satırlar:

- Web sunucusu kullanıcısı (`www-data`). Hoca, web sunucusunun çalıştırılabilir dosyası değişmese de sunduğu sayfaların içeriğinin değişebileceğini (dosya yükleme, dinamik içerik) belirtti.
- `backup` kullanıcısı. Satırın sonundaki `nologin` dikkat çekicidir: bu hesapla sisteme giriş yapılamaz, giriş denendiğinde sistem kullanıcıyı dışarı atar. Root ile giriş yapıldığında ise bir kabuk açılır.
- Alan adlarını adreslere dönüştüren DNS çözümleme servisine ait bir kullanıcı. <!-- BELİRSİZ: altyazıda "risol" diye geçiyor, büyük olasılıkla systemd-resolve. -->
- Slaytın sahibi dersin öğretim üyelerine ait iki gerçek kullanıcı hesabı (`zakir` ve `dabo`).

### 6.3 Gruplar ve /etc/group

Benzer sorumluluk, yetki ve özelliklere sahip kullanıcılar gruplanır; böylece onlarla ilgili işlemler bir seferde yapılabilir. Slayttaki tanım: "Collection of users who can share files and other system resources", yani dosya ve bazı sistem kaynaklarını ortak kullanabilen kullanıcı toplulukları. Her grubun tekil bir ID'si (GID) vardır. Grup bilgisi `/etc/group` dosyasında tutulur: `root` 0 numaralı gruptur, ardından `daemon`, `bin`, `sys`, `adm`, `tty` gibi gruplar ve numaraları gelir. <!-- BELİRSİZ: /etc/group karesi yok; altyazıda "Daemon 1, 1002, ss3, adm4 ... TTY 5" diye bozuk geçiyor, büyük olasılıkla daemon:1, bin:2, sys:3, adm:4, tty:5. -->

## 7. Dosya Sahipliği ve İzinler

Slayt (ekrandan, 00:35:00): Linux'ta soketler, aygıtlar ve dosyalar gibi bütün kaynaklar dosya olarak yönetilir. Bütün dosya ve dizinlerin tek bir kullanıcı sahibi (user owner) ve tek bir grup sahibi (group owner) vardır. Örnek `ls -l` çıktısı (ekrandan, 00:35:00):

```text
zakir@scratch-01:~$ ls -l
total 8
d rwx rwx ---   5 zakir cs155-tas    4096 Apr  2 15:56 homework
d rwx rwx ---   5 zakir cs155-instr  4096 Apr  2 15:56 grades
d rwx rwx r-x  11 zakir cs155-tas    4096 Dec 28 21:09 lectures
- rwx r-x r--   1 zakir dabo         0    Apr 11 04:15 test.py
```

İlk üç girdi dizindir (`d`), sonuncusu dosyadır (`-`). Dördünün de kullanıcı sahibi `zakir`'dir; grup sahipleri sırasıyla `cs155-tas`, `cs155-instr`, `cs155-tas` ve `dabo`'dur.

Erişim kuralları:

- Bir dosyaya üç subject erişebilir: kullanıcı sahibi (user owner), grup sahibi (group owner) ve diğerleri (other).
- Subject'ler üç işlem yapabilir: okuma, yazma, çalıştırma.
- Sahip (user owner) izinleri değiştirebilir.
- Sahipliği (dosyanın kime ait olduğunu) yalnız root değiştirebilir.

İzin dizgesi üçlü gruplar hâlinde okunur: ilk üçlü kullanıcı sahibinin, ikinci üçlü grubun, üçüncü üçlü diğerlerinin izinleridir (ekrandan, 00:40:00). Örneğin `homework` için kullanıcı ve grup `rwx` ile erişebilir, ama sistemdeki diğer bütün kullanıcılar kesinlikle erişemez.

Hoca önemli bir ayrıntıya dikkat çekti: bir dizine `x` (execute) izni verildiğinde o dizin çalıştırılmaz; `x`, o dizinin içine `cd` ile girebilmek demektir.

Derste bu çıktı üzerinden üç soru çözüldü; çözümleri "Örnek Sorular" bölümündedir. Erişim kararını veren mantık (önce sahip mi, sonra grup üyesi mi, değilse other) python ile de kontrol edildi ve sonuçlar hocanın cevaplarıyla aynı çıktı.

## 8. Erişim Kontrol Listeleri ve Rol Tabanlı Erişim Kontrolü

### 8.1 Access Control List (ACL)

Subject, object ve aradaki işlem (access) arasındaki etkileşimi yönetmek için UNIX'te uygulanan yapıya erişim kontrol listesi (Access Control List, ACL) denir. Slayt: "UNIX permission model is a simple implementation of a generic access control strategy known as Access Control Lists." UNIX'teki (dolayısıyla Linux'taki) model, genel ACL stratejisinin basitleştirilmiş bir uygulamasıdır; ama bu basit hâliyle bile bugün yeterince etkili kullanılmaktadır.

- Her nesnenin, hangi subject'in hangi işlemleri yapabileceğini belirten bir ACL'i vardır ("Every object has an ACL that identifies what operations subjects can perform").
- Bir nesneye yapılan her erişim, nesnenin ACL'indeki girdilerle karşılaştırılır ve buna göre izin verilir ya da verilmez ("Each access to an object is checked against the object's ACL").

Slayttaki örnekte bir dizinin ACL'inde üç kullanıcı vardı; ikisi okuma, yazma ve çalıştırma, üçüncüsü yalnız okuma hakkına sahipti. <!-- BELİRSİZ: ACL örnek slaytının karesi yok; kullanıcı adları ve haklar altyazıdan tam okunamıyor. -->

### 8.2 Role-Based Access Control (RBAC)

RBAC, mevcut yapıyı daha derli toplu hâle getirmek için ortaya atılmış iyileştirilmiş bir yapıdır. Özünde yetki gruplara verilir; aynı rolü paylaşanlar bir araya getirilir. Yapı "grup" yerine "rol" diye adlandırıldığı için rol tabanlı erişim kontrolü denir.

Slayt (ekrandan, 00:45:00): "Access control matrices can grow complex as number of subjects, objects, and possible operations grow." Erişim kontrolünü bir matris olarak düşünürsek, kullanıcı sayısı, erişilebilen kaynak sayısı ve olası işlem sayısı (şimdiye kadar read, write, execute; başka işlemler de tanımlanabilir) arttıkça matrisin boyutu ciddi biçimde büyür. Bunun iki dezavantajı vardır: bellekte çok yer kaplar ve büyüdüğü için arama süresi uzar, performans düşer.

Slayttaki gözlem: "Users change more often than roles." Kullanıcılar sık sık rol değiştirir. Hocanın örneği: öğrencisiniz, mezun oluyorsunuz, asistanlığa başvurup asistan olarak devam ediyorsunuz. Öğrenciyken erişemediğiniz kaynaklar asistanken erişilebilir hâle gelir. Kullanıcıyı değiştirmeden yalnız ait olduğu grubu, yani rolü değiştirerek yeni yetkiler çok daha kolay, en az güvenlik açığıyla ve en az insan hatasıyla verilebilir. RBAC'nin ana fikri budur.

Slayttaki rol matrisi (ekrandan, 00:45:00):

| Rol | hw/ | exams/ | grades/ | lectures/ |
|---|---|---|---|---|
| cs155-instr | r/w | r/w | r/w | r/w |
| cs155-tas | r/w | read | — | r/w |
| cs155-students | read | — | — | read |
| cs-students | — | — | — | read |

Öğretim üyeleri her yere kısıtsız erişir. Asistanlar ödevlere okuma-yazma, sınavlara okuma hakkına sahiptir, notlara erişemez. Dersin öğrencileri ödevleri okuyabilir. Genel bilgisayar mühendisliği öğrencilerinin ödev, sınav ve notlara erişimi yoktur. Ders materyallerine öğretim üyeleri ve asistanlar okuma-yazma ile, her iki öğrenci grubu yalnız okuma ile erişir.

## 9. Süreçler ve Kullanıcı Kimlikleri

### 9.1 Süreçlerin izolasyonu

Slayt (ekrandan, 00:50:00):

- Süreçler izoledir: birbirlerinin belleğine erişemezler. Bu, UNIX'in tasarımının doğal sonucudur.
- Süreçler belirli bir kullanıcı olarak çalışır. Bu bir sistem kullanıcısı olabilir, ama çoğunlukla süreci başlatan kullanıcıdır.
  - Bir süreç çalıştırıldığında, çalıştıranın UID'inin izinleriyle çalışır.
  - Süreç, o UID'in erişebildiği bütün dosyalara erişebilir.
  - Aynı UID ile çalışan süreçler, bellekleri izole olsa da aynı erişim haklarına sahiptir.
- Root tarafından başlatılan süreçler, daha az yetkili bir UID'e geçerek yetkilerini azaltabilir.

Root olarak başlatmanın nedeni şudur: süreç başlangıçta bazı ilklendirmeler yapmalı, belirli soketlere ve dosyalara erişmeli, yani yapılandırmasını tamamlamalıdır. Bu işler bittikten sonra kendini kısıtlayıp daha güvenli çalışmayı seçebilir. Örneğin web sunucusu root olarak başlar, ilklendirme ve yapılandırmayı tamamladıktan sonra kendini `www-data` kullanıcısına dönüştürür.

### 9.2 Komut çalıştırma ve fork

Slayttaki cümle: "When you run a command, it runs with all your privileges because your shell runs as your user account and forks to start the command." Örnekte `zakir` kullanıcısı `ls` komutunu çalıştırdığında, komut onun kabuğundan `fork` ile başlatıldığı için `zakir`'in yetkileriyle çalışır. `fork` mevcut sürecin bir kopyasını oluşturur, sonra bu kopyanın içinde adı verilen çalıştırılabilir dosya çalıştırılır. Bu yüzden son cümle önemlidir: "When any process forks, it inherits its parent's UID." Fork sonunda yaşamaya devam eden ebeveyn ve yeni oluşan çocuk vardır; çocuk, ebeveynin UID'ini ve izinlerini devralır.

### 9.3 EUID, RUID ve SUID

Bir sürecin çalışması ve kaynaklara erişmesiyle ilgili arka planda üç kullanıcı kimliği vardır:

- **Effective User ID (EUID):** sürecin erişim izinlerini belirler.
- **Real User ID (RUID):** süreci kimin başlattığını belirler.
- **Saved User ID (SUID):** geçici bir tampon değerdir. Root olarak başlayan bir süreç UID'ini değiştirirken, gerekirse eski değere geri dönebilmek için eski değer burada saklanır.

Normal şartlarda üç değer birbirine eşittir ve süreci başlatan kullanıcının UID'idir: $EUID = RUID = SUID$.

Slayt "Changing User IDs" (ekrandan, 00:55:00):

- `root`, EUID/RUID/SUID değerlerini herhangi bir değere kısıtsız değiştirebilir.
- Yetkisiz kullanıcılar EUID'yi yalnız RUID ya da SUID değerine değiştirebilir.
- `setuid(x)` çağrısı: EUID ⇒ x, RUID ⇒ x, SUID ⇒ x.

> **Ders sonrası not:** Slayttaki `setuid(x)` davranışı (üç değerin de `x` olması), çağıran sürecin ayrıcalıklı (root) olduğu durum içindir. Ayrıcalıksız bir süreç `setuid(x)` çağırdığında büyük olasılıkla yalnız EUID değişir ve `x` ancak RUID ya da SUID'e eşitse çağrı başarılı olur.

## 10. Apache ve SSH Örnekleri

### 10.1 Apache

Hoca, dersin başında anlattığı "root olarak başla, sonra yetkini düşür" fikrinin gerçek hayat karşılığını gösterdi. Apache web sunucusu root olarak başlamak zorundadır, çünkü 80 numaralı portu dinleyen soketi yalnız root oluşturabilir. 1024'ün altındaki bütün portlar özel yetki gerektirir. Yetki düşürülmezse Apache'deki herhangi bir hata ya da açık saldırgana sunucuda sınırsız (root) erişim verir.

Bunun yerine Apache çocuk süreçleri şu şemayla oluşturur: `fork` sonucu 0 olan dal çocuk süreçtir. Çocuk, zaten var olan 80 numaralı port soketini alır, bağlantıyı kurup soket verisine erişimi sağladıktan sonra kendi UID'ini daha düşük yetkili bir kullanıcıya indirir. <!-- BELİRSİZ: Apache kod slaytının karesi yok; çocuğun hangi çağrıyla ve hangi kullanıcıya geçtiği altyazıdan tam çıkmıyor. -->

> **Ders sonrası not:** Hoca (00:56:32) `fork`'un 0 döndürmesinin çağrının başarıyla sonuçlandığını gösterdiğini söyledi. Daha doğrusu, büyük olasılıkla `fork` başarılı olduğunda çocuk süreçte 0, ebeveyn süreçte çocuğun PID'ini döndürür; hata durumunda ebeveyne -1 döner. Yani 0, "bu kod çocukta çalışıyor" anlamına gelir.

### 10.2 Geçici yetki değişimi

Yetkisiz kullanıcıların EUID'yi yalnız RUID ya da SUID'e geri çekebildiği kuralı geçici yetki değişimine izin verir. Hocanın örneği: başlangıçta $EUID = RUID = SUID = 0$ olsun.

1. `seteuid(100)` çağrılır: RUID ve SUID değişmez, 0 kalır; EUID 100 olur. Süreç artık 100 numaralı kullanıcının erişim haklarıyla çalışır.
2. Ardından EUID yeniden 0 yapılabilir, çünkü EUID RUID'e ya da SUID'e eşitlenebilir ve ikisi de 0'dır.

Yani `setuid` üç değeri birden değiştirir, `seteuid` ise yalnız EUID'yi değiştirir, diğerleri aynı kalır.

### 10.3 Zafiyetli SSH örneği

Sisteme güvenli erişim sağlayan SSH (Secure Shell) sunucusu root olarak çalışır. Slayttaki (SSH kodundan alınmış, basitleştirilmiş) kod (ekrandan, 01:00:00):

```c
if (authenticate(uid, pwd) == S_SUCCESS) {
    if (fork() == 0) {
        seteuid(uid);
        exec("/bin/bash");
    }
}
```

Kimlik doğrulama başarılıysa ve çocuk süreç oluşturulduysa, çocuk EUID'yi kullanıcının UID'ine ayarlar ve bir kabuk çalıştırır. Hoca bunun basitleştirilmiş olduğunu, gerçekte kullanıcının `/etc/passwd`'de tanımlı kabuğunun bulunup çalıştırılması gerektiğini belirtti.

Slayttaki açıklama: `seteuid(uid)` sonrasında EUID := uid olur, RUID ve SUID değişmez. Saldırı: kullanıcı `setuid(0)` çağırarak root olabilir, çünkü SUID == 0'dır. Yetkisiz bir süreç EUID'yi RUID ya da SUID'e geri çekebildiği için, kabuktaki saldırgan bu kabuğu bir anda root yetkilerine dönüştürebilir.

Doğrusu `setuid(uid)` çağırmaktır. Bu durumda EUID, RUID ve SUID'in üçü de uid olur ve saldırgan UID'ini hiçbir şekilde root'a döndüremez.

> **Hocanın vurgusu:** `seteuid` ile yalnız EUID'yi değiştirip SUID'i 0 bırakmak bir zafiyettir; root yetkisini kalıcı bırakmak için `setuid` kullanılmalıdır.

> **Ek bilgi (derste anlatılmadı):** Slayttaki `exec("/bin/bash")` gösterim amaçlı bir sözde çağrıdır; C standart kütüphanesinde bu imzada bir `exec` fonksiyonu yoktur, gerçek kodda `execl`, `execv` ya da `execve` ailesinden bir çağrı kullanılır.

### 10.4 pstree

`pstree` komutu süreç ağacını gösterir: hangi kullanıcı hangi süreci başlatmış, hangi süreç hangisinin altında. Slayttaki renkli örnekte sistemde iki `sshd` süreci vardı; biri slaytın sahibi iki öğretim üyesinden birine, diğeri öbürüne aitti. İkisi de sisteme SSH ile girip birer kabuk açmıştı ve biri bu çıktıyı almak için `pstree` çalıştırmıştı. Ayrıca systemd altında başlatılmış bir hafif web sunucusu (lighttpd), kendinden kopyalar çıkarmış bir uzak sistem günlüğü servisi (rsyslogd), systemd-resolve ve terminal üzerinden yerel bağlantıyı gösteren bir `screen` oturumu görülüyordu. <!-- BELİRSİZ: pstree slaytının karesi yok; süreç adları altyazıdan kısmen tahmin edildi. -->

## 11. SETUID Biti: Yetki Yükseltme

Önceki örnekler, root olarak başlayıp yetkisini düşüren süreçlerdi. Bu bölümde tam tersi bir yaklaşım görülür. Slayt (ekrandan, 01:05:00):

- `passwd` aracı, parolanızı `/etc/shadow` dosyasını güncelleyerek değiştirmenizi sağlar. Bu dosyayı yalnız root okuyup yazabilir.
- Normalde bu mümkün olmazdı: çalıştırılabilir dosyalar onları çalıştıran kullanıcının yetkisiyle çalışır ve sizin hesabınız bu dosyaya erişemez.
- UNIX, bir çalıştırılabilir dosyanın EUID'sinin çalıştıran kullanıcı yerine dosya sahibi olmasına izin verir.

Kullanıcı tanımları `/etc/passwd`'de, parolalar `/etc/shadow`'dadır. Hoca iki kritik soru sordu (çözümleri "Örnek Sorular"da): okuma ve yazmaya kapalı bir dosyaya parola değiştirmek için nasıl erişilecek, ve aynı dosya diğer kullanıcıların parolalarını da tuttuğuna göre başka bir kullanıcının parolasını değiştirmeyeceğimiz nasıl garanti edilecek?

Mekanizma şöyle çalışır: bir kullanıcı, sahibi root olan setuid bir programı çalıştırdığında RUID ve SUID bu kullanıcının UID'i olarak kalır, ama EUID root olur. Yani yetkiler kontrollü biçimde yükseltilmiştir. Yükseltilmiş yetkiden dönüldüğünde EUID ya RUID'e ya SUID'e çekilebildiği ve ikisi de kullanıcının UID'i olduğu için, iş bitince yine kullanıcının kendi yetkilerine dönülür.

Böyle bir dosyanın izin dizgesinde `x` yerine `s` görünür. Bu, programı kim çalıştırırsa çalıştırsın EUID'nin dosya sahibi olacağı anlamına gelir. Hocanın gösterdiği `/usr/bin/passwd` dosyasının sahibi root'tur ve kullanıcı üçlüsünde `s` vardır. <!-- BELİRSİZ: passwd dosyasının ls -l satırının karesi yok; tam izin dizgesi okunamadı. -->

`passwd`, RUID'in çağıran kullanıcı olduğunu bilir; root olarak çalışırken `/etc/shadow`'da yalnız RUID'e karşılık gelen satırın değişmesine izin verir, diğer satırlara dokunmaz. Kodun o kısmı böyle yazılmıştır. Sonra yetkiler yeniden kullanıcınınkine döner.

Hoca bu yaklaşımı sorguladı: bu, şimdiye kadar karşılaşılmış en kötü yetki bölümlendirme yöntemi olabilir mi? Standart UNIX ve türevleri yalnız EUID'nin sıfır olup olmadığına bakar. EUID'si 0 olan süreçler bütün denetimlerden muaftır ve her erişimi doğrudan yapabilir; EUID 0 değilse ACL ve izin denetimleri uygulanır. `passwd` dışında, uzaktaki bir makinenin açık olup olmadığını ve IP bağlantısı olup olmadığını sınamak için kullanılan `ping` komutu da aynı setuid mekanizmasına dayanır.

> **Hocanın vurgusu:** Bu yaklaşım çok tehlikelidir. Böyle çalışması öngörülen uygulamalardan herhangi birindeki bir hata (buffer overflow, use-after-free, null pointer dereference) saldırgana doğrudan en yetkili kullanıcı olma hakkı verir.

## 12. Linux Yetenekleri (Capabilities) ve UNIX Modelinin Değerlendirmesi

### 12.1 Capabilities

Modern UNIX'lerde, klasik ACL ve yetki ayrımının modernleşmiş hâllerinde yeteneklerden (capability) söz edilir. Slayt (ekrandan, 01:25:00): "Capabilities segment root powers into components, such that if a program that has one or more capabilities is compromised, damage is limited." Her şeye yetkili root kullanıcısının yetkisi kendi içinde parçalara bölünmüştür.

- **`CAP_KILL`:** sinyal gönderme izin denetimlerini atlar (Bypass permission checks for sending signals). Hoca adın tarihsel olduğunu açıkladı: süreci durdurmak için `kill` ile ona bir sinyal gönderiliyordu; sonra süreçlere sinyal göndermenin genel adı `kill` oldu ve süreci durdurmak bunun özel bir sinyali hâline geldi. Bu yüzden bu yetenek, süreci durdurmak değil, ona sinyal (kesme) göndermek olarak düşünülmelidir.
- **`CAP_NET_BIND_SERVICE`:** bir soketi ayrıcalıklı portlara (port < 1024) bağlar. Apache root olmaya yalnız 80 ya da 443 numaralı porta bağlanabilmek için ihtiyaç duyar; bunun dışında root olması gerekmez. O hâlde Apache'ye yalnız bu yeteneği vermek yeterlidir.
- **`CAP_SYS_PTRACE`:** `ptrace` ile herhangi bir süreci izler (trace). Çalışan bir süreci hata ayıklamak için izlemek isteyen birinin root'un bütün yetkilerine sahip olmasına gerek yoktur.

### 12.2 UNIX güvenlik modelinin artı ve eksileri

Artıları: çoğu durum için yeterli ve basit uygulanabilir bir koruma sağlar, esnektir ve bugün de rahatlıkla kullanılmaktadır.

Eksileri:

- ACL çözünürlüğü ince değil kabadır; alt seviyelere yeterince inmez ve kurumsal yapıların karmaşıklığına denk gelen bir yetkilendirme sunmaz.
- ACL'ler tek bir kullanıcı hesabı içindeki farklı uygulamaları ayırt edemez ("ACLs do not handle different applications within a single user account"). Erişim kontrolü kullanıcı seviyesindedir.
- Neredeyse bütün sistem işlemleri root olmayı gerektirir; bu da insanların hata yapma olasılığını sistemi zafiyetli hâle getiren bir etkene çevirir.

## 13. Windows Güvenlik Modeli

### 13.1 Esnek ACL'ler

Slayt "Flexible ACLs" (ekrandan, 01:30:00):

- Windows'un karmaşık erişim kontrol seçenekleri vardır.
- Nesnelerin tam ACL'leri vardır; ince taneli (fine grained) izin vermek mümkündür.
- Kullanıcılar birden çok grubun üyesi olabilir, gruplar iç içe (nested) olabilir.
- ACL'ler Allow (izin ver) ve Deny (reddet) kurallarını destekler.

Slaytta bir dosyanın izin penceresi gösteriliyordu: "Permissions for ..." başlıklı pencerede kullanıcı/grup listesi ve seçilen kullanıcı için Full control, Modify, Read & execute, Read, Write satırları, her satırda Allow ve Deny onay kutuları vardı (örnekte Read & execute ve Read için Allow işaretliydi). Hoca, UNIX'teki "var ya da yok" mantığından farklı olarak burada "şunlara izin ver, bunlara verme" yaklaşımı uygulandığını söyledi. Ayrıca Windows'ta birincil grup (primary group) kavramı vardır ve bazı erişim kararları bu grup üzerinden verilir. Esneklik karmaşıklığı, karmaşıklık da hata riskini beraberinde getirir.

> **Ders sonrası not:** Hoca (01:29:57) UNIX'te bir kullanıcının yalnız tek bir grubun üyesi olabildiğini söyledi. UNIX'te bir kullanıcının büyük olasılıkla bir birincil grubu ve birden çok ek (supplementary) grubu olabilir; tek olan, bir dosyanın grup sahibidir.

### 13.2 Security Descriptor

Nesnelerin (erişilen kaynakların) bir güvenlik tanımlayıcısı (security descriptor) vardır. Bu tanımlayıcı, hangi subject'lerin hangi işlemleri yapabileceğini ve bunlar hakkında hangi denetim kayıtlarının (audit log) oluşturulacağını söyler. İçeriği:

- **Sahip ve birincil grup için Security Identifier (SID).** Hocaya göre SID nesnenin adından bağımsızdır; bir SID silinip yeniden oluşturulursa, ad aynı kalsa bile SID farklı olur. Bu bazı noktalarda güvenliği artırır, bazı durumlarda can sıkıcı senaryolar oluşturur.
- **Discretionary ACL (DACL):** kullanıcı ya da gruplara verilen erişim hakları. Hiçbir hak verilmezse nesneye kimse erişemez. Hakları verip vermemek nesnenin sahibinin takdirine bağlı olduğu için "discretionary" denir.
- **System ACL (SACL):** sistemin zorunlu tuttuğu, denetim kaydı (log) için kullanılan kurallar; hangi tür erişimin (başarısız okuma/yazma, başarılı okuma/yazma, çalıştırma, silme) kayıt üreteceğini belirler. Bunlar kullanıcının keyfine bırakılmaz, işletim sistemince tanımlanır; bu yüzden zorunlu (mandatory) ACL olarak da anılır.

> **Ders sonrası not:** Hoca SID'in kriptografik olarak üretilmiş bir hash değeri olduğunu söyledi. SID büyük olasılıkla daha doğru biçimde, bir yetki alanı (authority) değeri ve alt yetki (sub-authority) numaralarından oluşan yapılandırılmış bir tanımlayıcı olarak tarif edilir; kriptografik bir hash değildir. Yeniden oluşturulan hesabın farklı SID alması bu yapının tekilliğinden gelir.

### 13.3 Tokens

Slayt (ekrandan, 01:35:00): her sürecin bir token kümesi, yani "güvenlik bağlamı" (security context) vardır. Amacı sürecin güvenlik derecesini belirlemektir. İçeriği:

- kullanıcı hesabının ID'si,
- grupların ID'leri,
- oturum (login session) ID'si,
- kullanıcı/grupların sahip olduğu işletim sistemi ayrıcalıklarının listesi,
- kısıtlamaların listesi.

Impersonation token, geçici olarak farklı bir bağlamı benimsemek için kullanılabilir: süreç, mevcut güvenlik bağlamının dışında başka bir güvenlik bağlamında davranabilir. Hocanın örneği bir dosya sunucusudur. Sunucuya yüzlerce farklı kullanıcıdan okuma-yazma isteği gelir; en güvenli çözüm, sunucunun kendini isteğin sahibine dönüştürerek erişimi yapmasıdır. Hoca bunun UNIX'teki setuid mekanizmasının birebir karşılığı gibi düşünülebileceğini söyledi.

Bir süreç bir nesneye erişmek istediğinde güvenlik token'larını sunar ("presents its set of security tokens"): "Elimdeki token'lar bunlar, şu erişimi yapmak istiyorum." Windows, güvenlik bağlamının nesneye erişip erişemeyeceğini nesnenin security descriptor'ına göre denetler.

### 13.4 Deny önceliği: Mark ve Poets örneği

Örnek: Access token'da kullanıcı Mark, grup 1 Administrators (birincil grup olduğu için grup 1), grup 2 Poets. Nesnenin security descriptor'ında Poets grubu için okuma ve yazma Deny, Mark kullanıcısı için okuma ve yazma Allow vardır. Çözümü "Örnek Sorular" bölümündedir. <!-- BELİRSİZ: Mark/Poets slaytının karesi yok; kural sırası altyazıdan alındı. -->

> **Hocanın vurgusu:** Windows'un tasarımı gereği Deny'ın önceliği Allow'dan yüksektir. Listede erişimi reddeden bir kural varsa o kural geçerli olur.

## 14. ACL ile Yetenek (Capability) Karşılaştırması

Bu noktada iki yaklaşım karşılaştırıldı:

- **Capability:** Subject, sahte üretilemeyen (unforgeable) ve içeriği değiştirilemeyen bir bilet (ticket, token) sunar; bu bilet nesneye erişim verir. Sistem subject'in kim olduğuyla ilgilenmez, yalnız erişim hakkı olup olmadığına bakar ("System doesn't care who the subject is, just that they have access"). Hocanın benzetmesi: sinemaya gidip biletinizi gösterirsiniz; yer gösterici kim olduğunuzla ilgilenmez, bilet geçerliyse sizi koltuğunuza oturtur.
- **ACL:** Sistem, subject'in nesneye erişimi olan kullanıcılar listesinde olup olmadığını ve hangi yetkilerle yer aldığını denetler. Burada kullanıcının kim olduğu önemlidir. Benzetme: bir davetli listesi; kapıda "ben geldim, davetliyim" dersiniz ve adınız listede aranır.

## 15. Masaüstlerinde Zayıf Koruma

Slayt (ekrandan, 01:40:00):

- Kullanıcı izinlerine dayanmak, kullanıcıyı kötü niyetli uygulamalara karşı pek korumaz.
- Sizin adınıza çalışan kötü niyetli bir uygulama bütün dosyalarınıza erişebilir.
- Adobe Acrobat bütün verilerinizi düzenleyebilir, silebilir ve şifreleyip fidye isteyebilir.

Hoca bunu, masaüstlerinin kişisel kullanımdan gelen, ilk tasarımdan miras kalmış bir zafiyeti olarak açıkladı. Masaüstünde kendi kullanıcınız olarak oturum açmışsınızdır; bütün süreçler ve dosyalar sizindir. Bilerek ya da bilmeyerek çalıştırdığınız kötü niyetli kodun dosyalarınıza erişmemesi diye bir şey söz konusu değildir. Örneğin Acrobat ile birlikte gelen bir fidye yazılımı (ransomware), açtığınız bir Acrobat dosyasıyla etkinleşip dosyalarınızı şifrelemeye başlayabilir. Yapı gereği kişi, kendine ait şeyleri dışarıdan müdahale olmadan bu modelle koruyamaz. Linux/UNIX ve Windows tarafı görüldükten sonra masaüstü son kullanıcı tarafında yaşanan açmaz budur.

## 16. Chrome'un Süreç Mimarisi ve Yetki Ayrımı

### 16.1 Tek süreçten çok sürece

Hoca, tarayıcıların eskiden tek bir süreç olarak çalıştığını anlattı: bu süreç ağa ve diske erişiyor, grafik çizimini (rendering) yapıyor, müzik çalıyor ve JavaScript çalıştırıyordu; bütün bu parçalar sürecin altındaki iş parçacıklarıydı. Sonrasında ağ, depolama, aygıt, tarayıcı, renderer, kullanıcı arayüzü, GPU ve eklentiler birbirinden bağımsız ayrı süreçlere bölündü. Birden çok sekme olduğu için birden çok renderer, birden çok eklenti yüklü olduğu için birden çok eklenti süreci vardır.

> **Ders sonrası not:** Altyazıda bu geçiş "2006 öncesi/sonrası" diye geçiyor. Chrome büyük olasılıkla 2008'de ilk sürümünden itibaren çok süreçli mimariyle çıktı; slayttaki tarih büyük olasılıkla genel tarayıcı mimarisindeki geçişe ya da tasarım çalışmalarının başlangıcına işaret ediyor.

### 16.2 Süreçlerin görevleri

Slayt "Chrome Processes" (ekrandan, 01:45:00):

- **Browser Process:** uygulamanın "chrome" kısmını (adres çubuğu, yer imleri) kontrol eder; ayrıca ağ istekleri gibi görünmeyen, ayrıcalıklı kısımları yönetir.
- **Renderer Process:** web sitesinin gösterildiği sekmenin içindeki her şeyi kontrol eder.
- **Plugin Process:** web sitesinin kullandığı eklentileri (ör. Flash) kontrol eder.
- **GPU Process:** GPU işlerini diğer süreçlerden izole biçimde yürütür. Ayrı bir süreçtir, çünkü GPU birden çok uygulamanın isteğini işler ve hepsini aynı yüzeye çizer.

Hoca GPU sürecinin özelliğini açıkladı: farklı sekmelerden gelen çizilmiş içerikler aynı ekranda gösterilmek zorundadır. Bu yüzden süreçleri birbiriyle doğrudan etkileştirmek yerine GPU süreci üzerinden kontrollü biçimde etkileştirmek daha anlamlıdır.

### 16.3 Sekme ve iframe izolasyonu

A, B ve C sitelerinin renderer'ları ayrıdır; birbirlerinden tamamen izoledirler. Bedeli, her biri ayrı süreç olduğu için bellek kullanımının çok artması ve bir noktadan sonra sistemin sekmeler arasında gezinirken ya da bir sekmenin içeriğini yüklerken yeterince hızlı tepki verememesidir. Hoca burada "responsive" kelimesinin sistemin cevap süresini kastettiğini, "responsive tasarım" ile karıştırılmaması gerektiğini belirtti. Bir sayfanın kaynak kodu (HTTP, HTML, JavaScript) yüklenirken içine bir iframe gömülmüşse onun için de ayrı süreç başlar.

Süreçler arasındaki geçişi bir **broker** kontrol eder. Bu, ileride görülecek bir referans monitörüdür (reference monitor): süreçler arasındaki etkileşimin geçerli, izin verilebilir bir etkileşim mi yoksa olmaması gereken bir etkileşim mi olduğuna karar verir. Slayttaki ifade: "Renderer's only access to the network is via its parent browser process and file system access can be restricted." Renderer'ın ağa tek erişimi ebeveyn tarayıcı süreci üzerindendir ve dosya sistemi erişimi kısıtlanabilir. Şemadaki politika motoru (policy engine), A hedefinin B hedefiyle konuşup konuşamayacağına karar verir.

### 16.4 Windows'taki kısıtlamalar

Windows, Chrome'un en çok çalıştığı ve tarayıcı ortamı açısından en sıkıntılı işletim sistemidir; bu yüzden yapısal değişiklikler önce orada yapılır.

- **Restricted token:** Chrome, `CreateRestrictedToken` ile kullanıcının yetkilerinin alt kümesi olan bir token oluşturur. Bu token'ı "Nobody" grubu ve "Nobody" kullanıcısıyla eşler ve neredeyse bütün sistem kaynaklarına erişimi iptal eder. Biri diskteki dosyaların ACL'lerini herkesin güvenlik denetimi olmadan erişebileceği şekilde ayarlamadıkça bu token'la hiçbir yere erişilemez. Hocaya göre Vista ve sonrasında bu token ağ erişiminde de kullanılır.
- **Job object (ekrandan, 01:50:00):** Renderer, etkileşimli bir süreç yerine bir "Job" nesnesi olarak çalışır. Windows'ta zamanlanmış işler ya da ekrana ihtiyacı olmayan SQL Server gibi arka plan çalıştırılabilirleri bu türdendir. Job nesnesi şunlara erişimi ortadan kaldırır: masaüstü ve görüntü ayarları, pano (clipboard; kopyala-yapıştır içeriği), alt süreç oluşturma, global atom tablosu. Bu, renderer'daki kötü niyetli kodun parola çalmaya, tuş vuruşlarını okumaya ya da diğer sekmelerden bilgi çalmaya çalışmasının neredeyse tamamen önüne geçer.
- **Ayrı masaüstü:** Windows birden çok masaüstünü (desktop) destekler; bir masaüstünü ekranla ilişkilendirip ilişkilendirmemek kullanıcıya kalmıştır. Chrome bundan da yararlanır: farklı masaüstleri arasında mesajlaşma yapılamaz ve süreçleri kopyala-yapıştır açısından da birbirinden izoledir.
- **Integrity level:** Windows Vista ile gelen bütünlük seviyeleri: Untrusted, Low, Medium, High, System. Çoğu süreç Medium seviyesinde çalışır. Chrome Low Integrity Level'dan yararlanır: bu seviyedeki süreç okuyabilir ama yazma yetkisi kısıtlanmıştır. Security descriptor izin verse bile bütünlük seviyesi düşük olduğu için yazma hakkı elinden alınmış olur.

> **Ders sonrası not:** Hoca bütünlük seviyelerinin geliştirme sürecini kolaylaştırmak, imzasız çalıştırılabilirlere izin vermek için oluşturulduğunu ve Windows'un normalde sertifikasız çalıştırılabilire izin vermediğini söyledi. Bütünlük seviyeleri (Mandatory Integrity Control) büyük olasılıkla daha doğru biçimde, düşük bütünlüklü bir sürecin daha yüksek bütünlüklü nesnelere yazmasını engelleyen zorunlu bir erişim katmanı olarak tanımlanır; Windows da genel olarak imzasız çalıştırılabilirlerin çalışmasına izin verir.

Hoca sonuçta Chrome'un güvenlik modelinin de tek bir hat üzerine değil bir satıh üzerine kurulu olduğunu, içinde birden fazla güvenlik özelliği barındırdığını vurguladı.

## 17. macOS ve Android'de İzolasyon

### 17.1 macOS sandbox

Sandbox, izolasyon yapmak, sınırları belirlemek, bir hücrenin içine yerleştirmek demektir; ilerideki haftalarda ayrıntılı görülecektir. macOS'ta uygulamalar sandbox yapısıyla sınırlandırılır. Sınırlanan erişim türleri:

- donanım: kamera, mikrofon, USB, yazıcı;
- ağ: gelen ve giden bağlantılar;
- uygulama verisi: takvim, konum, kişiler;
- kullanıcı dosyaları: Downloads, Pictures, Music, Movies, kullanıcının seçtiği dosyalar.

Slayt: "Access to any resource not explicitly requested in the project definition is rejected by the system at runtime." Projeyi oluştururken, kodla birlikte dağıtılacak uygulamanın nelere erişmeye ihtiyacı olduğu açıkça belirtilmelidir (ör. Downloads ve Movies'e erişim, dışarı ağ bağlantısı). Belirtilmezse sistem bunları reddeder. Kullanıcı izin verirse erişim sürdürülebilir, ama varsayılan politika reddetmektir.

### 17.2 Android süreç izolasyonu

Slayt (ekrandan, 01:55:00):

- Android, izolasyon için Linux'u ve kendi çekirdek uygulama sandbox'ını kullanır.
- Her uygulama kendi UID'iyle, kendi VM'inde çalışır.
  - Uygulamalar birbiriyle etkileşemez.
  - Sistem kaynaklarına erişim sınırlıdır ve kurulum sırasında belirlenir (kamera, mikrofon, takvim vb.).
- Referans monitörü bileşenler arası iletişimdeki izinleri denetler.

Hoca, Android uygulamalarının Java üzerine kurulu olduğunu ve bu yüzden bir sanal makine olduğunu açıkladı. Bütün uygulamaları tek bir sanal makine altında çalıştırmak çok güvensiz olurdu: her biri o VM'de bir iş parçacığı olur ve biri diğerlerinin verisine erişebilirdi. Bu yüzden her uygulama kendine ait bağımsız bir VM'de, bir süreç olarak çalışır. Referans monitörü, Chrome'daki broker gibi, bileşenler arası iletişimin izin verilebilir olup olmadığına karar verir.

## 18. Açık Tasarım ve Basitlik

### 18.1 Prensiplerin özeti

Hoca dersin sonunda prensipleri topladı: hattı müdafaa yok, sathı müdafaa var; en düşük yetki prensibi uygulanır; yetkiler birbirinden ayrılır. Bunların yanında iki prensip daha vardır.

### 18.2 Açık tasarım (Open Design)

"The security of a mechanism should not depend on the secrecy of its design or implementation." Hoca bunun yapılabilecek en büyük hata olduğunu söyledi, çünkü tasarım ele geçtiğinde sistem tamamen açığa çıkar.

- Mekanizmanın ayrıntıları tersine mühendislik (reverse engineering), çöp karıştırma (dumpster diving) ya da sosyal mühendislik yoluyla sızarsa bu, bütün kullanıcılar için aynı anda felaket niteliğinde bir başarısızlıktır.
- Sırlar mekanizmadan ayrılırsa (ör. bir anahtar), anahtarın sızması yalnız bir kullanıcıyı etkiler.

Hocanın örneği: bir uygulama bir veri tabanına erişecekse, veri tabanının kullanıcı adı ve parolasının uygulamanın içine gömülmesi çok kötüdür. Güvenlik mekanizmaları uygulamanın kendi mekanizmalarından ayrılmalıdır.

Bu prensip kriptografiden gelir ve Auguste Kerckhoffs'a dayanır: bir kripto sistem, anahtarı dışında her türlü bilgisi, yapısı ve tasarımı herkesçe bilinirken de güvenliyse güvenli bir kripto sistemdir. Hocanın ifadesiyle: "AES kullanıyorum, RSA kullanıyorum, eliptik eğri kriptografisi (ECC) kullanıyorum; bütün matematiği, bütün yapısı, mesajlaşma ayrıntıları burada. Ama sistem, kullandığım anahtarın bilinmemesi sayesinde güvenlidir." Bu sağlanabiliyorsa düzgün bir tasarım yapılmış demektir.

> **Ek bilgi (derste anlatılmadı):** Kerckhoffs bu ilkeyi büyük olasılıkla 1883'te askeri kriptografi üzerine yayımladığı makalelerde ortaya koymuştur. Claude Shannon'ın "düşman sistemi bilir" (the enemy knows the system) özdeyişi aynı fikrin sonraki bir ifadesidir.

### 18.3 Basit tut (Keep It Simple)

Hocaya göre hayatın her yerinde uygulanması gereken bir prensiptir. Yapı ne kadar basitse o kadar kolay anlaşılır; hatalar o kadar kolay ortaya çıkar ve düzeltilir. Karmaşık yapılar her zaman sıkıntı içerir. Esneklik karmaşıklığı beraberinde getirir ve bu güvenliği zayıflatır; bu yüzden esneklik ile güvenlik arasındaki denge çok dikkatli kurulmalıdır. (Windows ACL'lerinde de aynı gözlem yapılmıştı: esneklik karmaşıklığı, karmaşıklık hata riskini artırır.)

## Örnek Sorular

**Soru 1** (ekrandan, 00:40:00): Aşağıdaki `ls -l` çıktısına göre bu sunucuya erişimi olan bir öğrenci hangi dosyalara erişebilir? (Öğrenci `zakir` değildir; `cs155-tas`, `cs155-instr` ve `dabo` gruplarının üyesi değildir.)

```text
d rwx rwx ---   5 zakir cs155-tas    4096 Apr  2 15:56 homework
d rwx rwx ---   5 zakir cs155-instr  4096 Apr  2 15:56 grades
d rwx rwx r-x  11 zakir cs155-tas    4096 Dec 28 21:09 lectures
- rwx r-x r--   1 zakir dabo         0    Apr 11 04:15 test.py
```

**Çözüm (derste verildi, 00:39:18):** Öğrenci ne sahip ne de grup üyesidir, bu yüzden "other" üçlüsüne (son üç karakter) bakılır.

- `homework`: other `---` → erişemez.
- `grades`: other `---` → erişemez.
- `lectures`: other `r-x` → dizine girebilir (`x`) ve içeriğini okuyabilir (`r`).
- `test.py`: other `r--` → dosyayı okuyabilir, ama çalıştıramaz ve yazamaz.

**Soru 2** (derste sözlü, 00:38:11): Andrew adlı kullanıcı `cs155-tas` grubunun üyesidir. Andrew `homework`'ü okuyabilir mi?

**Çözüm (derste verildi):** `homework`'ün grup sahibi `cs155-tas`'tır. Andrew bu grubun üyesidir ve grup üçlüsü `rwx`'tir. Dolayısıyla okuyabilir (yazabilir ve dizine girebilir de).

**Soru 3** (derste sözlü, 00:40:29): Dan, `dabo` grubunun üyesidir. Dan `test.py` ile ne yapabilir?

**Çözüm (derste verildi):** `test.py`'nin grup sahibi `dabo`'dur ve grup üçlüsü `r-x`'tir. Dan dosyayı okuyabilir ve çalıştırabilir, ama yazamaz.

**Soru 4** (ekrandan, 01:00:00 ve derste sözlü, 01:00:39): Root olarak çalışan SSH sunucusu, kimlik doğrulamasından sonra çocuk süreçte `seteuid(uid); exec("/bin/bash");` çalıştırıyor. Saldırgan bu kabukta nasıl root olabilir ve kodun doğrusu ne olmalıdır?

**Çözüm (derste verildi):** `seteuid(uid)` yalnız EUID'yi değiştirir; RUID ve SUID 0 kalır. Yetkisiz bir süreç EUID'yi RUID ya da SUID değerine çekebildiği için kullanıcı `setuid(0)` çağırarak EUID'yi yeniden 0 yapar ve root olur. Doğrusu `setuid(uid)` çağırmaktır: EUID, RUID ve SUID'in üçü de uid olur, artık geri dönülecek bir 0 değeri kalmaz.

**Soru 5** (derste sözlü, 01:17:38 ve 01:18:05): `/etc/shadow` yalnız root tarafından okunup yazılabiliyorsa, sıradan bir kullanıcı `passwd` ile kendi parolasını nasıl değiştirir? Aynı dosyada başka kullanıcıların parolaları da olduğuna göre, başka birinin parolasını değiştirmeyeceği nasıl garanti edilir?

**Çözüm (derste verildi):** `passwd` dosyasının sahibi root'tur ve SETUID biti açıktır (izin dizgesinde `x` yerine `s`). Kullanıcı programı çalıştırınca RUID ve SUID kendi UID'i olarak kalır, EUID root olur; böylece program `/etc/shadow`'u okuyup yazabilir. İkinci sorunun cevabı programın kendi mantığındadır: `passwd` RUID'e bakarak çağıranın kim olduğunu bilir ve dosyada yalnız o kullanıcıya ait satırın değişmesine izin verir. İş bitince EUID yeniden kullanıcının UID'ine döner.

**Soru 6** (derste sözlü, 01:36:37): Bir sürecin access token'ında kullanıcı Mark, grup 1 Administrators, grup 2 Poets vardır. Nesnenin security descriptor'ında "Poets: Deny read, write" ve "Mark: Allow read, write" kuralları bulunur. Mark nesneyi okuyabilir ya da yazabilir mi?

**Çözüm (derste verildi):** Hayır. İlk bakışta Mark için Allow kuralı yüzünden erişebileceği düşünülebilir, ama Windows'ta Deny'ın önceliği Allow'dan yüksektir. Mark, Poets grubunun üyesi olduğu için Poets'e uygulanan Deny kuralı geçerli olur ve Mark okuyamaz, yazamaz.

## Dersin Toparlaması

Bu derste, zafiyetlerin hiçbir zaman tamamen ortadan kalkmayacağı kabulünden yola çıkılarak güvenli sistem tasarımının beş prensibi işlendi: derinlemesine savunma, en az yetki, yetki ayrımı, açık tasarım ve basitlik. Güvenlik politikalarının subject, object ve operation üçlüsüyle ifade edildiği gösterildi. Ardından bu prensiplerin işletim sistemlerindeki karşılıkları incelendi: UNIX'te UID/GID, `rwx` izinleri ve ACL; RBAC ile rollere yetki verme; süreçlerin EUID, RUID ve SUID değerleri; yetki düşürme (Apache, SSH) ve SETUID biti ile yetki yükseltme (`passwd`); root gücünü bölen Linux yetenekleri. Windows tarafında security descriptor, DACL/SACL, token'lar ve Deny önceliği; ACL ile capability yaklaşımlarının farkı ele alındı.

Masaüstlerinde kullanıcı tabanlı izinlerin kötü niyetli uygulamalara karşı yetersiz kaldığı görüldükten sonra, Chrome'un süreçlere bölünmüş mimarisi, restricted token, job object, ayrı masaüstü ve düşük bütünlük seviyesiyle kendi içinde nasıl yetki ayrımı yaptığı; macOS ve Android'in uygulamaları sandbox içinde nasıl izole ettiği incelendi. Hoca, ileriki derslerde sandbox ve referans monitörü (reference monitor) kavramlarının ayrıntılı işleneceğini belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
