# Ders 4 Çalışma Özeti

## Genel Konular

- Zafiyetler kaçınılmazdır (ekrandan, 00:05:00)
  - Tek bir buffer overflow, use-after-free ya da null pointer dereference saldırgana kötü niyetli kod çalıştırma fırsatı verebilir.
  - Hataları bulmada ve önlemede ilerleme olsa da her zaman hata olacaktır. Sistemler zafiyetlere ve kötü niyetli kullanıcılara karşı dayanıklı tasarlanmalıdır.
  - Tip güvenli diller (Java, Go, Python) de tek başına çözüm değildir: bu dillerin kendisi ya da çalışma ortamları C/C++ ile yazılmıştır. Örnek olarak Python için 2016 tarihli bir CVE kaydı gösterildi.
- Güvenli sistem prensibi 1: Derinlemesine savunma (Defense in Depth) (ekrandan, 00:10:00)
  - Güvenlik koruması birden çok katmanda kurulur; hoca bunu "hattı müdafaa değil, sathı müdafaa" diye özetledi.
  - Örnek: Chrome'un JavaScript yorumlayıcısında zafiyet varsa Chrome kötü niyetli sitenin diğer sekmelere erişimini, işletim sistemi diğer süreçlere (ör. parola yöneticisi) erişimi, donanım firmware'e kalıcı zararlı yazılım kurulmasını, ağ da zararlının yakındaki bilgisayarlara bulaşmasını engellemelidir.
  - Firmware örneği: disk kontrolörünün firmware'i kötü niyetli olarak güncellenirse üst katmandaki bütün kullanıcı/süreç izolasyonuna rağmen diske yazılan her veri dışarı kopyalanabilir.
  - Kurumsal ağlarda bir makinedeki açık genellikle diğer makinelerde de vardır; saldırgan bir makineyi atlama taşı olarak kullanır.
- Prensip 2: En az yetki (Least Privilege) (ekrandan, 00:15:00)
  - Kullanıcı yalnız rutin, yetkili işlerini yapmak için gereken veri ve kaynaklara erişebilmelidir.
  - Gerçek hayat örnekleri: öğretim üyesi yalnız kendi derslerinin notlarını değiştirebilir; yalnız güvenlik soruşturması yapılmış çalışanlar gizli belgelere erişebilir.
- Prensip 3: Yetki ayrımı (Privilege Separation, compartmentalization) (ekrandan, 00:20:00)
  - En az yetki, sistemin erişimi sınırlanabilen parçalara bölünmesini gerektirir. Trendeki kompartıman benzetmesi kullanıldı.
  - Ele geçirilen bileşen hem en az yetkiye sahip hem diğerlerinden izole ise saldırgan yalnız o bileşeni ele geçirir; bileşen kolay bulunur, izole edilir ve düzeltilir.
  - Örnekler: kullanıcı yalnız kendi dosyalarını okuyabilir; süreç başka sürecin belleğini okuyamaz; mobil uygulama başka uygulamanın verisini düzenleyemez; bir alan adı (domain) yalnız kendi çerezlerini okuyabilir.
- Güvenlik politikaları: Subject, Object, Operation (ekrandan, 00:25:00)
  - Subject (kim?): kullanıcı, uygulama, süreç. Object (ne?): bellek, dosya, donanım aygıtı gibi korunan kaynaklar. Operation (nasıl?): okuma, silme vb.
  - Örnek politikalar: UNIX'te kullanıcı başka kullanıcının dosyasını silememeli; süreç başka sürecin belleğini okuyamamalı; mobilde uygulama yalnız kendi verisini düzenleyebilmeli; web'de bir domain başka domainin çerezlerini okuyamamalı.
- UNIX güvenlik modeli (ekrandan, 00:30:00)
  - Subject: kullanıcılar ve süreçler. Object: dosyalar, dizinler, soketler, pipe'lar, aygıtlar, çekirdek verisi, süreç tanımları. Operation: read, write, execute.
  - Hesap türleri: servis hesapları (arka plan süreçleri, ör. web sunucusu için `www-data`, `backup`) ve gerçek kişiye bağlı kullanıcı hesapları.
  - Her kullanıcının tekil tamsayı kimliği (UID) vardır. UID 0 her şeye erişebilen `root` kullanıcısına ayrılmıştır; birçok sistem işlemi yalnız root olarak çalışır.
  - Kullanıcılar `/etc/passwd`, gruplar `/etc/group` dosyasında tanımlıdır. `nologin` kabuğu olan hesapla oturum açılamaz.
- Dosya sahipliği ve izinler (ekrandan, 00:35:00 ve 00:40:00)
  - Linux'ta soketler, aygıtlar ve dosyalar dosya olarak yönetilir. Her dosya ve dizinin tek bir kullanıcı sahibi ve tek bir grup sahibi vardır.
  - İzin dizgesi üç üçlüden oluşur: user, group, other; her üçlü `r`, `w`, `x` bitlerinden oluşur. Sahip izinleri değiştirebilir, sahipliği yalnız root değiştirebilir.
  - Dizinde `x` izni, o dizine girebilmek (cd) anlamına gelir.
  - Derste çözülen örnekler: `cs155-tas` grubundaki bir kullanıcı `homework`'ü okuyabilir; sunucuya erişen bir öğrenci (other) yalnız `lectures` dizinine girip okuyabilir ve `test.py`'yi okuyabilir; `dabo` grubundaki kullanıcı `test.py`'yi okuyup çalıştırabilir.
- Erişim kontrol listeleri (ACL) ve rol tabanlı erişim kontrolü (RBAC) (ekrandan, 00:45:00)
  - UNIX izin modeli genel ACL stratejisinin basit bir uygulamasıdır. Her nesnenin, hangi subject'in hangi işlemi yapabileceğini söyleyen bir ACL'i vardır; her erişim bu listeyle karşılaştırılır.
  - Erişim kontrol matrisi subject, object ve işlem sayısıyla büyür; hem bellekte yer kaplar hem arama süresini uzatır.
  - Gözlem: kullanıcılar rollerden daha sık değişir. RBAC'de yetki rollere (gruplara) verilir; kullanıcının rolü değişince (ör. öğrenciyken asistan olmak) yalnız rolü değiştirilir.
- Süreçler ve UID'ler (ekrandan, 00:50:00 ve 00:55:00)
  - Süreçler izoledir, birbirlerinin belleğine erişemez. Süreç onu başlatan kullanıcının UID izinleriyle çalışır; aynı UID ile çalışan süreçler aynı izinlere sahiptir.
  - Kabuk komutu `fork` ile başlatır; çocuk süreç ebeveynin UID'ini devralır.
  - Root olarak başlayan süreç yapılandırmayı bitirdikten sonra yetkisini düşürebilir (ör. web sunucusunun `www-data`'ya geçmesi).
  - Üç UID: Effective UID (EUID) erişim izinlerini, Real UID (RUID) süreci kimin başlattığını belirler; Saved UID (SUID) geri dönüş için saklanan değerdir. Normalde üçü eşittir.
  - Root üç değeri de istediği değere çevirebilir; yetkisiz kullanıcı EUID'yi yalnız RUID ya da SUID değerine çevirebilir. `setuid(x)` (root için) üçünü de `x` yapar; `seteuid(x)` yalnız EUID'yi değiştirir.
- Apache ve SSH örnekleri
  - Apache root olarak başlamak zorundadır, çünkü 80 numaralı portu yalnız root dinleyebilir (1024'ün altındaki portlar ayrıcalıklıdır). Yetki düşürülmezse Apache'deki her hata saldırgana sınırsız erişim verir; bu yüzden çocuk süreçler soketi aldıktan sonra yetkisini düşürür.
  - Zafiyetli SSH örneği (ekrandan, 01:00:00): kimlik doğrulama sonrası çocuk süreçte `seteuid(uid)` çağrılıp `/bin/bash` çalıştırılırsa yalnız EUID değişir, RUID ve SUID 0 kalır; kullanıcı `setuid(0)` çağırarak root olabilir. Doğrusu `setuid(uid)` ile üç değerin de değiştirilmesidir.
  - `pstree` komutuyla hangi kullanıcının hangi süreci başlattığı ve süreç ağacı görülebilir.
- SETUID biti: yetki yükseltme (ekrandan, 01:05:00)
  - `passwd` aracı parolayı yalnız root'un okuyup yazabildiği `/etc/shadow` dosyasını güncelleyerek değiştirir. Normalde bu mümkün olmazdı.
  - UNIX, bir çalıştırılabilir dosyanın EUID'sinin çalıştıran kullanıcı yerine dosya sahibinin UID'i olmasına izin verir. İzin dizgesinde `x` yerine `s` görünür.
  - Çalıştıran kullanıcının RUID ve SUID değeri kendi UID'i kalır, EUID root olur; iş bitince EUID yeniden kullanıcının UID'ine döner.
  - `passwd` RUID'e bakarak yalnız o kullanıcının `/etc/shadow` satırını değiştirir. `ping` de bu mekanizmayı kullanır.
  - Tehlike: setuid root programlardaki tek bir hata (buffer overflow, use-after-free, null pointer dereference) saldırgana doğrudan root yetkisi verir. Klasik UNIX yalnız "EUID sıfır mı?" diye bakar; EUID 0 olan süreç her denetimden muaftır.
- Linux yetenekleri (capabilities) (ekrandan, 01:25:00)
  - Root'un gücü bileşenlere bölünür; bir veya birkaç yeteneği olan program ele geçirilirse zarar sınırlı kalır.
  - `CAP_KILL`: sinyal gönderme izin denetimlerini atlar. `CAP_NET_BIND_SERVICE`: soketi ayrıcalıklı porta (port < 1024) bağlar. `CAP_SYS_PTRACE`: `ptrace` ile herhangi bir süreci izler.
  - Apache'ye root yerine yalnız `CAP_NET_BIND_SERVICE` vermek yeterlidir.
  - UNIX modelinin değerlendirmesi: çoğu durum için yeterli, basit ve esnek; ama ACL kaba taneli, aynı kullanıcı hesabındaki farklı uygulamaları ayırt edemiyor ve neredeyse bütün sistem işlemleri root gerektiriyor.
- Windows güvenlik modeli (ekrandan, 01:30:00 ve 01:35:00)
  - Nesnelerin tam ACL'leri vardır, ince taneli izin verilebilir. Kullanıcılar birden çok grubun üyesi olabilir, gruplar iç içe olabilir. ACL'ler Allow ve Deny kurallarını destekler.
  - Security Descriptor: sahip ve birincil grup için Security Identifier (SID), DACL (isteğe bağlı erişim hakları) ve SACL (sistemin zorunlu tuttuğu denetim/log kuralları).
  - Her sürecin bir token kümesi (güvenlik bağlamı) vardır: kullanıcı hesabı ID'si, grup ID'leri, oturum ID'si, kullanıcı/grubun işletim sistemi ayrıcalıkları, kısıtlamalar. Impersonation token geçici olarak başka bir bağlamı benimsemeyi sağlar (dosya sunucusu örneği, UNIX setuid'e benzer).
  - Örnek: kullanıcı Mark, Poets grubunda; nesnede Poets için Deny read/write, Mark için Allow read/write var. Deny önceliklidir, Mark erişemez.
- ACL ile yetenek (capability) karşılaştırması
  - Capability: subject sahte üretilemeyen bir bilet sunar; sistem kim olduğuna bakmaz (sinema bileti benzetmesi).
  - ACL: sistem subject'in nesnenin listesinde olup olmadığına bakar (davetli listesi benzetmesi).
- Masaüstlerinde zayıf koruma (ekrandan, 01:40:00)
  - Kullanıcı izinlerine dayanmak kötü niyetli uygulamalara karşı az koruma sağlar; kullanıcı olarak çalışan zararlı uygulama bütün dosyalara erişir. Örnek: Adobe Acrobat bütün verileri düzenleyebilir, silebilir, şifreleyip fidye isteyebilir.
- Chrome'un yetki ayrımı (ekrandan, 01:45:00 ve 01:50:00)
  - 2006 öncesi tek tarayıcı süreci ve iş parçacıkları vardı; sonra ağ, depolama, aygıt, tarayıcı, renderer, UI, GPU ve eklenti ayrı süreçlere ayrıldı. Her sekme ve iframe için ayrı renderer süreci başlar; bedeli bellek kullanımıdır.
  - Browser process adres çubuğu, yer imleri ve ağ istekleri gibi ayrıcalıklı kısımları; renderer process sekme içeriğini; plugin process eklentileri (ör. Flash); GPU process GPU işlerini yönetir.
  - Renderer ağa yalnız ebeveyn tarayıcı süreci üzerinden erişir; aradaki etkileşime broker (bir reference monitor) karar verir.
  - Windows'ta: `CreateRestrictedToken` ile kullanıcının yetkilerinin alt kümesi olan, neredeyse hiçbir kaynağa erişemeyen token; renderer'ı "Job" nesnesi olarak çalıştırma (masaüstü/görüntü ayarları, pano, alt süreç oluşturma ve global atom tablosuna erişim yok); ayrı masaüstü (desktop) kullanımı; düşük bütünlük seviyesi (Low Integrity Level, yazma kısıtlı).
- macOS ve Android (ekrandan, 01:55:00)
  - macOS sandbox: donanım, ağ, uygulama verisi ve kullanıcı dosyalarına erişim proje tanımında açıkça istenmezse çalışma anında reddedilir.
  - Android: Linux ve kendi uygulama sandbox'ını kullanır. Her uygulama kendi UID'iyle kendi VM'inde çalışır; uygulamalar birbiriyle etkileşemez, sistem kaynağı erişimi kurulumda belirlenir. Reference monitor bileşenler arası iletişimin izinlerini denetler.
- Prensip 4 ve 5: Açık tasarım ve basitlik
  - Bir mekanizmanın güvenliği tasarımının ya da gerçeklemesinin gizliliğine dayanmamalıdır. Tasarım tersine mühendislik, çöp karıştırma ya da sosyal mühendislikle sızarsa bütün kullanıcılar için felakettir; sır (ör. anahtar) mekanizmadan ayrılırsa sızıntı yalnız bir kullanıcıyı etkiler.
  - Kerckhoffs prensibi: kripto sistem, anahtar dışındaki her şey bilinse de güvenli olmalıdır (AES, RSA, ECC örnekleri).
  - Keep it simple: basit yapı kolay anlaşılır, hatası kolay bulunur ve düzeltilir; esneklik karmaşıklığı, karmaşıklık hatayı getirir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Hatalar her zaman olacak; amaç hatalarla birlikte güvenli kalabilen sistem kurmaktır.
  - Tip güvenli diller de C/C++ ile yazılmış çalışma ortamlarına dayandığı için tek çözüm değildir.
- Savunma bir hat değil bir yüzey (satıh) olmalıdır.
  - Bir noktadaki açığı başka bir noktadaki tedbir sınırlayabilir ya da yok edebilir.
- En az yetki: bir işi yapmak için gereken en düşük yetki, o kullanıcının sahip olması gereken en yüksek yetkidir.
  - Fazlası hatayla, amaç dışında ya da kötü niyetle kullanılabilir.
- Zafiyetli SSH kodu: `seteuid` ile yalnız EUID değişir, SUID 0 kalır.
  - Bu, saldırganın kabuğu bir anda root'a çevirmesine izin verir; doğru çağrı `setuid(uid)`'dir.
- SETUID root programları çok tehlikelidir.
  - Bu programlardaki tek bir bellek hatası saldırgana en yetkili kullanıcı olma hakkı verir.
- Windows'ta Deny kuralı Allow kuralından önceliklidir.
- Güvenliği tasarımın gizliliğine dayandırmak "yapabileceğiniz en büyük hata"dır.
  - Örnek: veri tabanı kullanıcı adı ve parolasını uygulamanın içine gömmek.

## Kısa Tekrar Notları

- Beş prensip: Defense in Depth, Least Privilege, Privilege Separation, Open Design, Keep It Simple.
- Politika üçlüsü: Subject (kim), Object (ne), Operation (nasıl).
- UNIX: UID 0 = root; kullanıcılar `/etc/passwd`, gruplar `/etc/group`, parolalar `/etc/shadow`.
- İzin dizgesi: user/group/other üçlüleri, her biri `rwx`; dizinde `x` = içine girebilme.
- Sahip izinleri değiştirir, sahipliği yalnız root değiştirir.
- ACL: her nesnenin erişim listesi; RBAC: yetki rollere verilir, kullanıcıların rolü değişir.
- EUID erişim izni, RUID başlatan kullanıcı, SUID saklanan değer. Yetkisiz kullanıcı EUID'yi yalnız RUID ya da SUID'e çevirebilir.
- `setuid(x)` (root) üç değeri de değiştirir; `seteuid(x)` yalnız EUID'yi.
- SETUID biti (`s`): program dosya sahibinin yetkisiyle çalışır (`passwd`, `ping`).
- Capabilities: `CAP_KILL`, `CAP_NET_BIND_SERVICE`, `CAP_SYS_PTRACE`.
- Windows: Security Descriptor (SID, DACL, SACL), token, impersonation token, Allow/Deny, Deny öncelikli.
- Capability = bilet; ACL = davetli listesi.
- Chrome: browser, renderer, plugin, GPU süreçleri; restricted token, job object, ayrı desktop, low integrity.
- Android: her uygulama kendi UID'i ve kendi VM'inde.
- Kerckhoffs: anahtar dışında her şey bilinse de sistem güvenli olmalı.

## Detaylı Açıklamalar

Ders, önceki haftalarda görülen bellek zafiyetlerinden yola çıkar: savunma mekanizmaları uygulansa bile başarısız bir buffer overflow saldırısı hizmet engellemeye dönüşür ve hatalar hiçbir zaman tamamen yok olmaz. Bu yüzden asıl soru, zafiyetler varken sistemi nasıl güvenli tutacağımızdır. Cevap, birkaç tasarım prensibine dayanır. Derinlemesine savunma, tek bir savunma hattı yerine birçok katmanda tedbir almayı ister. Chrome örneğinde JavaScript yorumlayıcısındaki bir açık; tarayıcının sekmeleri ayrı süreçlerde çalıştırması, işletim sisteminin süreçleri birbirinden ayırması, donanımın firmware'i koruması ve ağın yayılmayı engellemesiyle katman katman sınırlanır.

En az yetki ve yetki ayrımı birbirini tamamlar. En az yetki, her kullanıcının ve her sürecin yalnız işi için gereken yetkiye sahip olmasını ister; bunu sağlamak için sistem erişimi ayrı ayrı sınırlanabilen bileşenlere bölünür. Böylece saldırgan bir bileşeni ele geçirse bile diğerlerine geçemez. Bu prensipler yalnız kullanıcılar için değil, süreçler, uygulamalar ve web alan adları için de geçerlidir. Her güvenlik politikası kim (subject), neye (object) ve nasıl (operation) sorularıyla ifade edilir.

UNIX bu prensiplerin klasik bir uygulamasıdır. Her kullanıcının tekil bir UID'i, her grubun tekil bir GID'i vardır; UID 0 root'tur. Her dosyanın bir kullanıcı sahibi ve bir grup sahibi bulunur, izinler user/group/other için `rwx` üçlüleriyle verilir. Erişim isteyen kullanıcı önce sahip mi diye, sonra grup üyesi mi diye bakılır, değilse "other" üçlüsü uygulanır. Derste `ls -l` çıktısı üzerinden bir öğrencinin yalnız `lectures` dizinine girip okuyabildiği ve `test.py`'yi okuyabildiği gösterildi. Bu model genel ACL fikrinin basitleştirilmiş hâlidir. Kullanıcı sayısı büyüdükçe matris karmaşıklaştığı için RBAC'de izinler rollere verilir.

Süreçler başlatan kullanıcının UID'iyle çalışır ve `fork` ile oluşan çocuk ebeveynin UID'ini devralır. Her sürecin üç UID'i vardır: EUID erişim kararlarında kullanılır, RUID süreci başlatanı gösterir, SUID geri dönüş için saklanır. Root bunları serbestçe değiştirebilir; yetkisiz kullanıcı EUID'yi yalnız RUID ya da SUID değerine çekebilir. Bu kural, SSH örneğindeki hatanın kaynağıdır: root olarak çalışan sunucu, kullanıcıya kabuk açmadan önce yalnız `seteuid(uid)` çağırırsa SUID 0 olarak kalır ve kullanıcı `setuid(0)` ile yeniden root olabilir. Doğru çözüm `setuid(uid)` ile üç değeri de değiştirmektir.

SETUID biti ters yönde çalışır: normal kullanıcının, dosya sahibi root olan bir programı root yetkisiyle çalıştırmasını sağlar. `passwd` bu sayede yalnız root'un yazabildiği `/etc/shadow` dosyasını günceller ve RUID'e bakarak yalnız çağıranın satırını değiştirir. Ancak bu tür programlardaki her bellek hatası doğrudan root yetkisi demektir. Linux yetenekleri bu sorunu root gücünü parçalara bölerek hafifletir; örneğin 80. porta bağlanması gereken bir web sunucusuna yalnız `CAP_NET_BIND_SERVICE` verilir.

Windows daha esnek ama daha karmaşık bir model kullanır: nesnelerin güvenlik tanımlayıcıları (SID, DACL, SACL) ve süreçlerin token'ları karşılaştırılır, Allow ve Deny kuralları vardır ve Deny önceliklidir. Masaüstü sistemlerde ise kullanıcı olarak çalışan bir zararlı yazılım kullanıcının bütün dosyalarına erişebildiği için kullanıcı tabanlı izinler zayıf kalır. Chrome bu yüzden kendi içinde yetki ayrımı yapar: renderer süreçleri kısıtlı token, job nesnesi, ayrı masaüstü ve düşük bütünlük seviyesiyle neredeyse hiçbir kaynağa erişemez hâle getirilir. macOS ve Android de uygulamaları sandbox içinde çalıştırır. Ders, açık tasarım (Kerckhoffs prensibi) ve basitlik prensipleriyle kapanır: güvenlik sırrın gizliliğine değil anahtarın gizliliğine dayanmalı, yapı mümkün olduğunca basit tutulmalıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
