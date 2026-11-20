# Ders 5 Genişletilmiş Notu: İzolasyon ve Sınırlama İlkesi: chroot, Jail, System Call Interposition, Sanal Makineler ve Software Fault Isolation

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. En Az Yetkiden İzolasyona
- 2. Güvenilmeyen Kod Çalıştırma
- 3. Sınırlama (Confinement) ve Seviyeleri
- 4. Referans Monitörü
- 5. chroot, Jailkit ve Hücreden Kaçış
- 6. FreeBSD Jail ve chroot/jail'in Sınırları
- 7. Sandbox ve System Call Interposition
- 8. ptrace ile SCI: Janus
- 9. Yarış Durumu ve TOCTOU
- 10. Linux'ta SCI: seccomp-bpf
- 11. Docker ve seccomp-bpf
- 12. Ostia
- 13. Sanal Makineler ve Hypervisor
- 14. Gizli Kanallar (Covert Channels)
- 15. Pratikte VM İzolasyonu
- 16. Hypervisor Tespiti
- 17. Software Fault Isolation
- 18. SFI'nin Performansı ve x86'daki Sınırları
- Örnek Sorular
- Dersin Toparlaması

## 1. En Az Yetkiden İzolasyona

Ders, önceki haftada işlenen en az yetki ilkesinin (principle of least privilege) hatırlatılmasıyla başladı. Bir işlemi yapmak için gereken yetki seviyesi hem yeterli hem de mümkün olan en düşük seviye olmalıdır. Hoca bu ilkenin yanında izolasyonun da geldiğini söyledi: sistemin parçaları birbirinden ayrılmalı, tek bir savunma hattı değil birden fazla seviyeli bir savunma kurulmalıdır. Bu fikir literatürde separation, isolation ve compartmentalization gibi adlarla anılır.

Bu derste izolasyon konusu işlendi. Slaytlar Stanford CS155 dersinin "Isolation: The confinement principle" sunumundan alınmıştı (ekrandan, 00:05:00). Confinement, bir şeyin hareket edebileceği alanı sınırlamak, onu sınırları belirli bir hücrenin içine koymak demektir.

## 2. Güvenilmeyen Kod Çalıştırma

Neden sınırlamaya ihtiyaç var? Hoca iki temel gözlemle başladı: bütün uygulamalarda hata olabilir ve bir uygulamanın güvenli olup olmadığını çoğu zaman kesin olarak bilemeyiz. Slayttaki liste şöyleydi (ekrandan, 00:10:00):

- **Güvenilmeyen internet sitelerinden gelen programlar:** masaüstü ve mobil uygulamalar, JavaScript, tarayıcı eklentileri. Mobil uygulamaları bir arkadaş tavsiyesiyle, bir e-postadaki linkle ya da bir reklamla "deneyeyim" diye yüklüyoruz. Web'de gezerken sürekli JavaScript geliyor. Tarayıcılara spor, hava durumu, moda gibi ilgi alanlarına göre eklentiler kuruyoruz. Sonuçta günlük hayatta, farkına varmadan onlarca, belki yüzlerce kez güvenliği sorgulanmamış kod yükleyip çalıştırıyoruz.
- **Dışa açık uygulamalar:** tarayıcı, PDF görüntüleyici, Outlook gibi e-posta istemcileri. Bunlarda çok sayıda zafiyet var; sürekli yama ve güncelleme çıkıyor, ama zafiyetler kalmaya devam ediyor ya da bir düzeltme başka bir zafiyete yol açıyor.
- **Eski servisler (legacy daemons):** sendmail ve bind. sendmail, internette alan adları arasında e-posta alıp vermeyi sağlayan ilk uygulama sayılabilir ve SMTP'yi uygular; yeniden şekillendirilmiş olsa da temel yapısı pek değişmediği için hâlâ çok kullanılıyor. bind (Berkeley Internet Name Daemon) DNS hizmetini veren sunucu sürecidir. Hakkında o kadar çok CVE yayımlanmış ki her biri yamalanıyor, yeni sürümler çıkıyor, ama temel tasarımdan ötürü yeni sürümlerde de hata çıkıyor.
- **Honeypot'lar:** saldırganların nasıl saldırdığını, hangi zafiyetlerden nasıl yararlandığını görmek için kurulan tuzak sistemler. Saldırganın bu sisteme girmesi istenir ama dışına çıkamaması gerekir; yeterli tedbir alınmazsa diğer sistemler de tehdit altına girer.

Slayttaki hedef: uygulama "kötü davranırsa" onu öldür (Goal: if application "misbehaves" ⇒ kill it). Hoca burada başa dönüldüğünü vurguladı. Uygulamayı çökerten başarısız bir saldırı hizmet engellemeye (denial of service) yol açar. Saldırıyı fark edip engellediğimizde de yaptığımız şey uygulamayı durdurmak olduğu için yine hizmet engellemeye varırız.

## 3. Sınırlama (Confinement) ve Seviyeleri

Bilgisayar sistemleri ve ağ güvenliği bağlamında confinement'ın teknik tanımı şudur: kötü davranan bir uygulamanın sistemin geri kalanına zarar verememesini sağlamak (ensure misbehaving app cannot harm rest of system) (ekrandan, 00:15:00). Hoca bunu hücre, hapis ya da etrafına çit çekmek benzetmeleriyle anlattı: uygulama belirlenen bölgenin dışına çıkamamalıdır. Sınırlama çok farklı seviyelerde yapılabilir.

### 3.1 Donanım seviyesi: air gap

En temel yaklaşım, uygulamaları yalıtılmış donanımda çalıştırmaktır. Slayttaki örnekte app 1 ve app 2 (ör. biri DNS sunucusu, biri e-posta sunucusu) iki ayrı bilgisayarda çalışıyor ve iki ayrı ağa (network 1 ve network 2) bağlı; aralarında "air gap", yani fiziksel bir hava boşluğu var (ekrandan, 00:15:00). Bu durumda bir ağ üzerinden bir uygulamaya yapılan saldırının diğer ağdaki uygulamayı ele geçirmesi çok zor, neredeyse imkânsızdır.

Ancak hoca bu yaklaşımın pratikte çok zor olduğunu anlattı:

- Bir kurumun dışa açık her uygulaması için ayrı ağdan erişim sağlamak pek mümkün değildir ve çok maliyetlidir.
- Her sunucunun kapasitesi en yüksek ihtiyaca (peak) göre belirlenir. E-posta sistemi her zaman bu yükü görmediği için donanım zamanın büyük kısmında boşta kalır.
- Makineler büyük olasılıkla benzer işletim sistemleri çalıştırır. Bir güncelleme ya da güvenlik yaması bir değil N sistemde ayrı ayrı yapılmalıdır.
- Dış ağlar ayrı servis sağlayıcılardan alınsa bile sistemlerin arka tarafta da bir iç ağa bağlanması gerekir; onların da ayrılması gerekir. Hangi sistemin hangi ağ üzerinden nasıl yönetileceği çok karmaşık hâle gelir.

Hoca burada KISS ilkesini hatırlattı: bir yapının güvenlik açısından analiz edilebilmesi, tehditlerin ortaya konabilmesi, tedbirlerin alınıp belgelenebilmesi için basit olması gerekir. Air gap kulağa hoş gelse de yönetilmesi zor bir yapıdır (slaytta: difficult to manage).

### 3.2 Sanal makineler

Air gap'in alternatifi sanal makinelerdir (ekrandan, 00:05:00, slayt listesi). Ortak donanımın üzerine bir Virtual Machine Monitor (hypervisor ya da kontrol programı diye de anılır) yerleştirilir ve bu katman üst tarafa birden fazla ayrı donanım varmış gibi görünür. Aynı donanım iki parçaya bölünür; birinde OS1, diğerinde OS2 çalışır. Önceki senaryonun aynısıdır ama iki fiziksel makine yerine bir makine kullanılır. Burada donanım ve yazılım tedbirleriyle bu yalıtımın fiziksel air gap'e denk olması sağlanmalıdır.

### 3.3 Süreç seviyesi: System Call Interposition

Fiziksel yaklaşımlardan giderek yazılımın ön plana çıktığı ve daha hassas yapılan yaklaşımlara geçilir. Süreç seviyesinde amaç tek bir işletim sistemi içinde bir süreci yalıtmaktır (ekrandan, 00:20:00). İşletim sistemi açısından bir uygulama bir süreçtir. Modern işletim sistemlerinde süreçlerin bellek alanları zaten birbirinden ayrılmıştır, ama süreçlerin zarar verecek eylemleri yapmaması için ayrıca tedbir gerekir. Bunun yolu sistem çağrıları üzerinden sürecin davranışını anlamak ve gerekli kısıtları uygulamaktır: System Call Interposition (SCI). Slayttaki şekilde aynı işletim sistemi üzerinde process 1 ve process 2 çalışıyor; process 2 ele geçirilmiş ama etrafındaki kalın siyah sınırın dışına çıkamıyor.

### 3.4 Thread seviyesi: Software Fault Isolation

Bir alt seviye thread'lerdir. Süreçler thread'lerden oluşur ve thread'ler aynı adres alanındadır; bir thread aynı süreçteki diğer thread'lerin bellek bölgelerine ve değişkenlerine erişebilir. Bu temel tanımın parçasıdır ve performans sağlar, ama güvenlik ve güvenilirlik açısından bazen bu erişimin engellenmesi istenir. Aynı adres alanını paylaşan thread'leri birbirinden yalıtmak için kullanılan kavram Software Fault Isolation'dır (SFI). Kısaca: süreçlerde SCI, thread'lerde SFI.

### 3.5 Uygulama seviyesi

Uygulama seviyesinde de thread mantığına benzer bir yalıtım gerekebilir. Örneğin tarayıcı içinde çalışan JavaScript ya da WebAssembly de aktif kod parçalarıdır ve tarayıcının diğer bileşenlerinden yalıtılmaları gerekir.

## 4. Referans Monitörü

Sınırlamayı uygulamak için gereken temel bileşen referans monitörüdür (reference monitor). Slayttaki özellikler şunlardı (ekrandan, 00:25:00):

- **Uygulamalardan gelen istekleri aracılar (mediates requests):** sınırlamayı uygular ve belirlenmiş bir koruma politikasını işletir. İsteğin yapılabilir mi, güvenlik zafiyeti yaratabilir mi, durdurulmalı mı olduğuna o karar verir.
- **Her zaman çağrılmalıdır:** her uygulama isteği aracılanmalıdır. Uygulamanın monitörü atlayıp başka bir yolla istekte bulunmasının hiçbir yolu olmamalıdır.
- **Kurcalamaya dayanıklıdır (tamperproof):** referans monitörü öldürülemez; öldürülürse izlenen süreç de öldürülür.
- **Analiz edilip doğrulanabilecek kadar küçüktür.**

Hoca bu kavramın işletim sistemlerinden uzak olmadığını söyledi: işletim sisteminden hizmet almanın tek yolu sistem çağrısıdır. Referans monitörü bu yaklaşımın genelleştirilmiş, güvenlik odaklı hâlidir.

> **Hocanın vurgusu:** Referans monitörünün bypass edilememesi çok önemlidir. Monitör çalışmıyorsa ya da atlanabiliyorsa uygulamaların düzgün mü, kötü niyetli mi çalıştığını anlamanın imkânı kalmaz. Monitör de özel bir uygulamadır; saldırı altındaysa ve durdurulursa sistemin geri kalanı da durmalıdır.

Bu kadar özelliği taşıyacak bir yapının küçük olması gerekir; çünkü kelimenin tam anlamıyla satır satır incelenip bilinen zafiyetlere karşı korumaların alınıp alınmadığı doğrulanabilmelidir.

## 5. chroot, Jailkit ve Hücreden Kaçış

### 5.1 chroot

En eski sınırlama örneği chroot'tur. Unix'te bir sistem çağrısıdır, aynı zamanda bir komut olarak da vardır; `chroot` komutu arka planda chroot sistem çağrısını çalıştırır. Yaptığı iş basittir: bir uygulamanın dosya sistemindeki başlangıç noktasını (kök dizinini) belirtilen dizin yapar.

Slayttaki örnekte guest kullanıcısı sınırlanır. Önce yetkili kullanıcı (Unix'te root) olarak şu iki komut çalıştırılır:

```text
chroot /tmp/guest
su guest
```

Birinci satır, root için dosya sisteminin tepe noktasını `/tmp/guest` yapar; bu komuttan sonra dosya sisteminin kök dizini `/tmp/guest` olur, öncesinde hiçbir şey yoktur. İkinci satırda root, guest kullanıcısının özelliklerine bürünür. Önceki haftadan hatırlanacağı gibi `su guest` ile etkin kullanıcı kimliği (effective user ID) guest'e ayarlanır; bütün erişim yetkilendirmeleri guest üzerinden yapılır. Böylece guest, root'un bir adım önce kurduğu dosya sistemi sınırının içine kapatılmış olur.

İşletim sisteminin yaptığı şey çok basittir: guest olarak çalışan uygulamalardan gelen her dosya sistemi erişiminin başına `/tmp/guest` ekler. Uygulama `/etc/passwd` dosyasını açmak isterse işletim sistemi aslında `/tmp/guest/etc/passwd` dosyasını açar. Böylece bir web, e-posta ya da DNS sunucusu dosya sisteminde kendisi için ayrılmış hücrenin dışına çıkamaz.

### 5.2 Jailkit

Bir sorun vardır: bazı komutlar kabuğun (shell) içinde yerleşik (built-in) gelir, ama `ls` gibi bazı komutlar ayrı çalıştırılabilir dosyalardır ve normalde `/bin`, `/usr/bin` ya da `/sbin` altında dururlar. Uygulamanın kök dizini başka bir yere taşınırsa bu programlara da erişemez. Bu durumda ya bu programlar hücrenin içinde uygun dizinler oluşturularak kopyalanmalı ya da gerçek dosyalara sembolik link verilmelidir.

Bu işi otomatikleştiren araç Jailkit'tir (ekrandan, 00:30:00):

- Sorun: bütün yardımcı programlar (`ls`, `ps`, `vi`) hücrenin içinde bulunmalıdır.
- `jailkit`: hücre ortamında gereken dosyaları, kütüphaneleri ve dizinleri otomatik kurar.
- `jk_init`: hücre ortamını oluşturur.
- `jk_check`: hücre ortamını güvenlik sorunlarına karşı denetler; değiştirilmiş programları ve herkesin yazabildiği (world writable) dizinleri arar.
- `jk_lsh`: hücre içinde kullanılacak kısıtlı kabuk.
- Not: basit bir chroot hücresi ağ erişimini sınırlamaz.

> **Hocanın vurgusu:** chroot ile sağlanan kısıtlama yalnız ve yalnız dosya sistemiyle ilgilidir; ağ erişimine hiçbir kısıt getirmez. Hoca bunu "üzerine basa basa" söylediğini belirtti.

### 5.3 Hücreden kaçış

Hücreden kaçmanın yolu var mı? `../` bir üst dizini gösterir ve işletim sistemi bunu destekler. İlk dönemde `../../` gibi göreli yollarla hücrenin dışına çıkılabildiği görülmüş, işletim sistemleri buna göre yamalanmıştır; bugün bu yöntem çalışmaz.

İkinci bir kural: chroot komutu ve sistem çağrısı yalnız root tarafından çalıştırılabilmelidir. Aksi hâlde hücreye alınmış bir uygulama kolayca root olabilir. Hocanın anlattığı adımlar:

```text
mkdir /aaa/etc                  # kendi alanında aaa ve altında etc dizini
/aaa/etc/passwd oluştur         # biçimine uygun; root için istediği (boş da olabilir) şifre
chroot /aaa                     # kök dizini /aaa yap
su root                         # kendi passwd dosyasıyla root ol
```

Uygulama kendi alanında `aaa` dizinini, altında `etc` dizinini ve onun altında biçimine uygun bir `passwd` dosyası oluşturur; root kullanıcısına istediği şifreyi verir ya da boş bırakır. Sonra `chroot /aaa` ile kök dizinini `/aaa` yapar ve `su root` dediğinde sistem kendi oluşturduğu `/aaa/etc/passwd` dosyasını kullandığı için root olur. Hoca bu hatanın chroot'u root dışındaki kullanıcılara da açan bir Unix sürümünde görüldüğünü söyledi. <!-- BELİRSİZ: sürüm adı altyazıda "altı sürevi 4.0" diye geçiyor; büyük olasılıkla Ultrix 4.0 -->

Hoca bunun neden önemli olduğunu da açıkladı: root olarak da kendimizi chroot ile kısıtlayabiliyoruz, ama dosya sisteminde kendimizi kısıtladıktan sonra root olarak çalışmaya devam edersek bu kısıtın pek önemi kalmaz.

## 6. FreeBSD Jail ve chroot/jail'in Sınırları

### 6.1 FreeBSD jail

Hoca önce Unix ailesini hatırlattı: AT&T laboratuvarlarında geliştirilen System V tarafı ve Berkeley Üniversitesi'nin sürdürdüğü Berkeley Software Distribution (BSD). FreeBSD, BSD'nin lisans ve kullanım açısından serbest bir uygulamasıdır. FreeBSD'de chroot da vardır ama daha gelişmiş olarak jail bulunur (ekrandan, 00:35:00):

- Basit chroot'tan daha güçlü bir mekanizmadır.
- Çalıştırma biçimi: `jail jail-path hostname IP-addr cmd`.
- Sağlamlaştırılmış bir chroot çağırır (`../../` kaçışı yok).
- Yalnız belirtilen IP adresi ve yetkili portlarla soket bağlayabilir.
- Yalnız hücre içindeki süreçlerle haberleşebilir.
- root kısıtlanır; örneğin kernel modülü yükleyemez.

Yani jail bir uygulamayı yalnız dosya sistemi açısından değil, hangi IP adresini kullanabileceği ve hücre dışındaki süreçlerle haberleşemeyeceği açısından da sınırlar. root olarak çalışan bir uygulama da jail ile hücreye sokulabilir, ama root'a ek kısıtlar getirilir. Kernel modülü yükleme yasağının sebebi, yüklenecek modülün hücreden kaçmak için kullanılabilecek olmasıdır.

### 6.2 chroot ve jail'in sınırları

İkisinin de temel sıkıntısı ince ayar yaptırmaması, "ya hep ya hiç" mantığıyla çalışmasıdır. Bu yüzden bazı uygulamalar için anlamlı değildir. Örneğin bir web tarayıcısı dosya sisteminde bir bölgeye kısıtlanarak çalıştırılabilecek bir uygulama değildir. Hoca Gmail'in web arayüzünü örnek verdi: e-posta yazarken ek eklemek istersiniz ve bu dosya dosya sisteminin herhangi bir yerinde olabilir; kısıtlanmış bir uygulamayla bunu nasıl ekleyeceksiniz?

Ayrıca chroot ağ erişimini kısıtlamadığı için yerleşilen yerel ağdaki başka sistemlere zarar verilmesinin önüne geçilemez; uygulamanın işletim sistemini çökertmeye çalışması da mümkündür. Hoca, chroot ve jail'in kullanılabilir yaklaşımlar olduğunu ama eksiklerinin bilinmesi gerektiğini, "gözü kapalı chroot ve jail kullandım, problemi çözdüm" denemeyeceğini söyledi.

## 7. Sandbox ve System Call Interposition

### 7.1 Kum havuzu benzetmesi

Sonraki konu bir süreci kum havuzuna (sandbox) yerleştirmekti (ekrandan, 00:40:00). Hoca benzetmeyi şöyle kurdu: patlayıcılarla çalışırken, bir patlayıcıyı etkisiz hâle getirirken ya da test ederken çevreye zarar vermemesi için kum havuzları kullanılır; kum patlamanın etkisini sönümler. Uygulamanın etrafına, yapacağı saldırının etkisini hafifletmek ya da ortadan kaldırmak için yerleştirilen çite de sandbox denir. chroot da bir sandbox'tır, jail de. Sandboxing terimi görüldüğünde bir izolasyon yapıldığı anlaşılmalıdır. Süreç seviyesinde de, thread seviyesinde de sandboxing yapılacaktır.

### 7.2 Tehlikeli sistem çağrıları

POSIX'te abartısız binlerce sistem çağrısı vardır, ama zararlı senaryolar şu çağrılarla kurulabilir:

- `unlink`: bir şeyin silinmesi.
- `open`: yazma, üzerine yazma (override) ya da ekleme (append) kipinde açma.
- `write`: yazmanın kendisi.
- `socket`: ağa erişim.
- `bind`: sunucu olarak bağlanma.
- `connect`: istemci olarak bağlanma.
- `send`: `write`'ın soketteki karşılığı.

Yani bütün sistem çağrıları zararlı değildir; bu yedisi ön plana çıkar. İyi amaçla da, kötü amaçla da kullanılabilirler.

### 7.3 SCI'nin mantığı ve uygulama biçimleri

System Call Interposition'ın mantığı çok basittir: uygulamanın yaptığı sistem çağrılarını izle, yapmaması gereken bir çağrı varsa onu durdur. Bu üç biçimde yapılır:

- Tamamen işletim sisteminin kernel'inde: Linux'taki seccomp buna örnektir.
- Tamamen kullanıcı alanında (user space): buna program shepherding denir.
- Karma (hibrit): bir kısmı kernel'de, bir kısmı kullanıcı alanında. <!-- BELİRSİZ: hibrit örneğin adı altyazıda "sister is" diye geçiyor; büyük olasılıkla Systrace -->

## 8. ptrace ile SCI: Janus

### 8.1 Çalışma biçimi

Bu kavram çok eskidir; 1996'da Janus kod adıyla ortaya atılmıştır. Unix'te süreç izleme (process tracing) için `ptrace` vardır ve normalde hata ayıklamada kullanılır. Janus'un fikri şudur: izlemek istediğimiz uygulamayı bir gözlemci uygulama ile takip edelim. Monitör, `ptrace` sistem çağrısıyla izlenen uygulamaya (slaytta bir tarayıcı) bağlanır.

Hoca akışı şöyle anlattı. Tarayıcı `fopen` ile `/etc/passwd` dosyasını okuma kipinde açmak istiyor. `ptrace` yalnız sistem çağrısı yapıldığında monitörün uyanmasını sağlar; onun dışında monitör kenarda uyur. Sistem çağrısı kernel'e gider; kernel çağrıyı yürütmeden önce bu uygulamayı izleyen bir süreç olup olmadığına bakar, olduğunu görünce monitörü uyandırır ve çağrının ayrıntılarını ona verir. Monitör hangi çağrı olduğuna, parametrelerin düzgün olup olmadığına ve çağrının sonlandırılması gerekip gerekmediğine karar verir. Sonlandırılmasına karar verirse uygulamayı öldürür.

### 8.2 Politika dosyası

Monitör ne zaman ne yapacağına bir kural dosyasıyla karar verir. Slayttaki PDF okuyucu örneği (ekrandan, 00:50:00):

```text
path allow /tmp/*
path deny /etc/passwd
network deny all
```

PDF okuyucu başka bir şey yapmayacaktır; açabileceği belgeler `/tmp` altındakilerdir, `/etc/passwd` dosyasına kesinlikle erişemez, ağ erişimi tamamen kapalıdır.

Bir uygulama için politikayı elle belirlemek zor olabilir. Uygulamanın kategorisine göre önerilen standart (varsayılan) politikalar vardır; bunlar alınıp gerektiğinde daha kısıtlı hâle getirilebilir. Ama burada bir emek söz konusudur: hangi kuralın gerekli olduğu, hangisinin mutlaka olması gerektiği, hangisinin varlığının önemsiz olduğu doğru analiz edilmelidir. Mekanizmanın özünde kuralların doğruluğu yatar.

### 8.3 Karmaşıklıklar

Slayttaki karmaşıklıklar (ekrandan, 00:55:00):

- **Uygulama fork ederse monitör de fork etmelidir;** fork edilen monitör fork edilen uygulamayı izler. Web ve e-posta sunucuları kendilerinin yeni kopyalarını oluşturarak çalışır. Bu durumda sistemdeki süreç sayısı otomatik olarak ikiyle çarpılır; kabaca bir hesapla sistemin toplam performansının yarısı kullanılabilir hâle gelir.
- **Monitör çökerse uygulama öldürülmelidir.** Referans monitörünün sürekli ayakta olması gerektiğini söylemiştik.
- **Monitör uygulamayla ilişkili bütün işletim sistemi durumunu tutmalıdır:** çalışma dizini (CWD), UID, EUID, GID. Uygulama `cd path` yaptığında monitör de kendi CWD'sini güncellemelidir. Örneğin uygulama önce `/tmp`'ye geçip `passwd` adlı bir dosya açar, sonra `/etc`'ye geçip `passwd` dosyasını açar; monitör hangisinin hangisi olduğunu ancak dizin değişikliklerini izleyerek bilebilir.

### 8.4 ptrace'in sorunları

Slayttaki sorunlar (ekrandan, 01:00:00):

- **ptrace bu iş için uygun değildir:** ya bütün sistem çağrıları izlenir ya da hiçbiri. Örneğin `close` çağrısını izlemeye gerek yoktur ama izlenir. `ptrace`'e bir grup sistem çağrısı verilemez; her çağrının bildirimi kernel üzerinden yapılır: uygulama kernel'e gider, kernel monitörü uyandırır, monitör kontrol edip kernel'e cevap verir, kernel uygulamayı öldürür ya da sürdürür. POSIX'teki çok sayıda çağrının yalnız yedisini değerlendireceğimiz bir senaryoda geri kalanlar için bu maliyeti ödemenin anlamı yoktur.
- **Monitör uygulamayı öldürmeden bir sistem çağrısını iptal edemez.**
- **Güvenlik sorunu: yarış durumları (race conditions).** Bu bir sonraki bölümde anlatılıyor.

## 9. Yarış Durumu ve TOCTOU

Hoca önce derlenmiş ve yorumlanan uygulamaları karşılaştırdı. Uygulamalar çoğu zaman derlenmiş değil yorumlanan dillerde yazılır: Python, Perl, PHP. Bunlar C/C++ gibi önceden derlenmez; çalışma sırasında yorumlanıp koda dönüştürülür. Bu yüzden native uygulamalara göre daha yavaş çalışır ve daha fazla gecikme içerir. Bu şartlarda işletim sistemlerinde yarış durumu olarak bilinen problem bir güvenlik saldırısı için kullanılabilir.

Yarış durumu, sonucun uygulamaların çalışma hızlarına ve sırasına bağlı olması; ya da uygulamaların hızları hakkında yapılan öngörülere dayanarak sonuca varılmasıdır. İki tanım aynı şeyi farklı açılardan söyler.

Slayttaki örnek (ekrandan, 01:00:00): başlangıçta `me` adlı sembolik link `mydata.dat` dosyasını gösteriyor.

```text
zaman
  |   proc 1:  open("me")
  |   monitor checks and authorizes
  |   proc 2:  me -> /etc/passwd
  v   OS executes open("me")
```

Süreç 1, `me` dosyasını açmak ister. Monitör devreye girer ve `me`'nin sorunsuz bir dosya olduğuna, açılabileceğine karar verir. Bu arada süreç 2, `me` linkini `/etc/passwd` dosyasına bağlar. İşletim sistemi süreç 1 için `me` dosyasını açtığında aslında `/etc/passwd` açılmış olur. Monitörün kontrol edip onaylaması ile işletim sisteminin bu onaya göre dosyayı açması arasına süreç 2 girebilmiştir. Böylece bir adım önceki kontrolün ve onayın hiçbir anlamı kalmaz.

Hoca, uygulamalar C/C++ ile yazılmış native uygulamalar olsaydı da bu ihtimalin var olacağını ama daha düşük olacağını, yorumlanan uygulamalarda çok daha yüksek olduğunu söyledi. Sorunun temelinde kontrol ve onay işlemi ile işletim sisteminin çağrıyı yürütmesinin atomik, yani bölünmez bir bütün olarak yapılmaması yatar. Bu hataya Time of Check, Time of Use (TOCTOU) hatası denir.

> **Hocanın vurgusu:** "Time of Check, Time of Use. Bunu unutmayın lütfen." Bu çok önemli bir güvenlik problemidir ve yarış durumunun sonucu olarak ortaya çıkar.

## 10. Linux'ta SCI: seccomp-bpf

### 10.1 Temel fikir

Linux çok yaygın kullanıldığı için SCI'nin Linux'taki karşılığına ayrıca bakıldı. Amaç, bütün sistem çağrılarının değil yalnız ihtiyaç duyulanların izlenmesi ve onlarla ilgili tedbir alınmasıdır. Slayttaki tanım (ekrandan, 01:05:00):

- Seccomp-BPF, süreçlerin sistem çağrılarını filtrelemek için kullanılan bir Linux kernel olanağıdır.
- Sistem çağrısı filtresi BPF dilinde yazılır (BPFC derleyicisi kullanılır).
- Chromium'da ve Docker konteynerlerinde kullanılır.

Hoca filtreyi "farklı bir derleyici gibi" düşünmeyi önerdi: bir uygulamanın derlenmiş ya da yorumlanacak hâli üzerinden yapacağı sistem çağrılarını statik olarak belirleme şansımız var. Bunlar belirlendikten sonra sıkıntılı kabul edilenler filtrelenir, geri kalanlar normal çalıştırılır. Bu, yeni Linux kernel'leriyle standart hâle gelmiş bir özelliktir.

### 10.2 Chrome renderer örneği

Hoca daha önce işlenen Chrome mimarisini hatırlattı: renderer, tarayıcı çekirdeği, eklentiler ve çerezlerle uğraşan kısım ayrı süreçlerdir. Chrome başlarken siteye göre renderer süreçleri başlatır. Slayttaki şekilde (ekrandan, 01:05:00) kullanıcı alanındaki "Chrome renderer process starts" kutusundan kernel'deki seccomp-bpf'e şu çağrı iner:

```c
prctl(PR_SET_SECCOMP, SECCOMP_MODE_FILTER, &bpf_policy)
```

Yani renderer başlarken kernel'e "bu uygulamadan şunlar gelebilir, bunlar gelemez" diyen bir filtre yerleştirilir. Uygulamayı yazan taraf hangi çağrıların geçerli olduğunu zaten bilir. Renderer, filtrede tanımlı olanlar dışında bir sistem çağrısı yaparsa (çağrı olarak ya da parametre olarak) kernel süreci öldürür. Böylece monitör yapısı kernel'in içine taşınmış olur. `bpf_policy`, kuralların tanımlandığı yapıdır; daha önce dosyada gösterilen "allow /tmp altı, deny /etc/passwd" türü kurallar artık kernel'e aktarılmıştır.

> **Ders sonrası not:** Hoca `prctl` için "privilege kontrolü" dedi; büyük olasılıkla adın açılımı "process control"dür (süreç kontrolü). Aynı şekilde hoca "SecComp" için "Security Compilation" dedi; doğrusu büyük olasılıkla "secure computing" (güvenli hesaplama) modudur.

### 10.3 BPF filtrelerinin özellikleri

Slayttaki özellikler (ekrandan, 01:10:00): bir süreç birden fazla BPF filtresi yükleyebilir ve

- Yüklenen filtre kaldırılamaz; her sistem çağrısında hepsi çalışır. Hoca bunun güvenlik sebebiyle olduğunu, filtrenin sistem yeniden başlatılana kadar kaldırılamadığını söyledi.
- Program fork ederse çocuk süreç bütün filtreleri miras alır; çocuk farklı bir filtreyle ya da filtresiz başlamaz.
- Program `execve` çağırırsa bütün filtreler korunur. "Fork ettim, sonra kendimi değiştirdim, filtrelerden kurtuldum" diye bir şey yoktur; filtreler kalıcıdır.

Filtrenin girdisi sistem çağrısı numarası, argümanlar ve mimaridir. Filtreler genel olsa da mimariye göre farklılıklar olduğundan x86 filtresi, ARM filtresi ya da PowerPC filtresi diye ayrılabilir. Filtrenin üç tür dönüşü vardır: süreci öldür (kill), süreç için belirli bir hata numarası (errno) döndür ya da çağrıya izin ver.

> **Ek bilgi (derste anlatılmadı):** Linux'ta bu üç dönüş değerinin adları büyük olasılıkla `SECCOMP_RET_KILL`, `SECCOMP_RET_ERRNO` ve `SECCOMP_RET_ALLOW` biçimindedir. Ayrıca bir de izleyici sürece haber veren `SECCOMP_RET_TRACE` gibi başka dönüşler de vardır.

### 10.4 Filtre yükleme kuralları

Hoca slaytta filtrelerin `prctl` ile nasıl yüklendiğini gösteren bir kod parçasını anlattı. Bu kodun karesi elimizde yok; anlatım altyazıdan kuruldu. <!-- BELİRSİZ: prctl kod örneğinin tam metni karede görülmedi -->

- Önce `prctl(PR_SET_NO_NEW_PRIVS, 1)` çağrılır. Bu çağrı BPF filtresi kurulmadan önce yapılmalıdır. Sonraki `exec` çağrılarında setuid ve setgid bitlerinin yok sayılmasını sağlar; böylece saldırgan yetki yükseltemez. Hoca hatırlattı: setuid ya da setgid programlar dosyanın sahibi kimse onun yetkileriyle çalışıyordu; bu çağrı Unix'in standart impersonation yapısını devre dışı bırakır.
- Sonra politika yapısı `prctl` ile kernel'e gömülür. Örnek politikada `open` çağrısı yazma kipinde yapılırsa uygulama öldürülüyordu. Dosyanın ne olduğu önemli değildir; önemli olan `open`'ın yazma kipinde yapılmasıdır.

## 11. Docker ve seccomp-bpf

Slayttaki başlık "Docker: isolating containers using seccomp-bpf" idi (ekrandan, 01:15:00):

- Konteyner süreç seviyesinde izolasyondur (container: process level isolation).
- Konteyner, seccomp-BPF ile filtrelenen sistem çağrılarını yapamaz.
- Konteyneri başlatan kimse BPF politikasını o belirleyebilir; varsayılan politika `ptrace` dahil pek çok sistem çağrısını engeller.
- Şekilde donanım, host OS, Docker engine ve onun üzerinde App 1, App 2, App 3 konteynerleri vardı.

Hoca, süreç seviyesindeki yalıtımın yalnız bellek yalıtımı olarak düşünülmemesi gerektiğini, ağ erişimi ve işlemci kullanımı dahil her türlü sistem kaynağı açısından sınırlama yapıldığını söyledi. Bir konteynerin hangi sistem çağrılarını ya da hangi parametrelerle yapamayacağı bu politika filtreleriyle belirlenir. Konteyneri Docker engine başlatır; başlatmadan önce kuralları kernel'e yükleyerek o konteynerde çalışacak uygulamanın filtrelerini belirler. Hiçbir özel kural verilmese bile varsayılan yapı `ptrace` dahil pek çok çağrıyı engeller.

Hocanın anlattığı örnekte Nginx, Docker tarafından bir konteyner olarak çalıştırılıyor ve seccomp seçeneğiyle JSON biçiminde bir filtre dosyası veriliyordu. Örnek filtrede varsayılan eylem reddetmekti; Nginx soketten bağlantı kabul edeceği için `accept` çağrısı argümanlarına bakılmaksızın izinli listeye (whitelist) alınmıştı. Gerçek bir filtrede bunun gibi alt alta pek çok kural bulunur. Docker, Nginx'i başlatmadan önce `prctl` ile bu kuralları kernel'e bildirir. Böylece ptrace'te konuşulan kernel'e girip çıkma ve monitörü fork etme gibi sorunlar ortadan kalkar. <!-- BELİRSİZ: Docker komutunun ve JSON filtresinin tam metni karede görülmedi -->

## 12. Ostia

Aradan sonra hoca, ptrace ve Linux'taki seccomp-bpf yapısından sonra Linux'a özgü olmayan, genel olarak önerilmiş bir başka yapıya geçti: Ostia. Slayttaki başlık "Ostia: SCI with minimal kernel support" idi (ekrandan, 01:20:00):

- İzlenen uygulamanın izlenen sistem çağrılarını yapması engellenir. Bunun için kernel'de çok küçük bir değişiklik gerekir (slaytta: "... but app can call close() itself").
- Sistem çağrısı, çağrıya izin verilip verilmeyeceğine karar veren bir ajana devredilir.
- Bu, uygulama değiştirilmeden bir libc stub ile yapılabilir.

Ostia'da izlenen bir sistem çağrısı uygun olmayan parametrelerle (ya da hangi parametreyle olursa olsun) çağrıldığında uygulama durdurulmaz; çağrı olumsuz bir dönüş koduyla geri döner. İzlenmeyen bütün sistem çağrılarını uygulama sorunsuz kullanabilir ve bunun için kernel'e girip başka bir uygulamaya sormak gerekmez.

Çalışma biçimi: izlenen uygulamanın yanında bir ajan vardır ve ajan kural dosyasını okur. Hoca, BPF'de de ve en baştaki ptrace yaklaşımında da bir kural dosyası olduğunu, bu yapının değişmediğini belirtti. Standart libc'nin önüne bir vekil (proxy) gibi çalışan ikinci bir libc konur; buna stub denir. Bu libc yalnız filtrelemek istediğimiz sistem çağrılarını ajana yönlendirir. Her şey kullanıcı alanında, bir fonksiyon çağrısı yapar gibi ajan üzerinden gider. Ajan onaylarsa çağrıyı kernel'e iletir; onaylamazsa uygulamaya o çağrıyla ilgili bir hata numarası döndürür.

## 13. Sanal Makineler ve Hypervisor

Hoca, ileri gidip geri geliyormuş gibi görünse de süreç izolasyonunu bilmenin sanal makine izolasyonunu daha iyi anlamaya yardım edeceğini söyledi. Slayttaki yapı (ekrandan, 01:35:00): en altta donanım, üstünde host OS (olabilir de olmayabilir de), onun üstünde ya da parçası olarak Virtual Machine Monitor (VMM, hypervisor, kontrol programı) ve en üstte sanal makineler. Bazen VMM ile host OS tek parçadır ya da host OS aslında VMM'nin kendisidir.

Slayttaki örnek NSA NetTop'tur: tek bir donanım platformu hem gizli (classified) hem de gizli olmayan (unclassified) veriyi işlemek için kullanılır. Amerika'nın Ulusal Güvenlik Ajansı bunu Linux platformunda yapmıştır. VM1 bir misafir işletim sistemi ve uygulamalarını, VM2 başka bir misafir işletim sistemini çalıştırır.

Hoca VM tarihçesini de anlattı. VM kavramı 1960'lardan beri vardır. Slaytta 1970 ile 2000 arası "non-existent" diye geçmesinin sebebi, 2000'e kadar VM teknolojisinin IBM'in uyguladığı, ürün olarak sattığı ve araştırdığı bir teknoloji olmasıdır. 2000 ile birlikte VMware bunu PC'lere ve Intel mimarisine taşıdı; son 20 yılda her ortamda uygulanan bir teknoloji oldu. Tek bir donanımı parçalara bölüp yazıcı, e-posta, web, dosya ve veritabanı sunucusu gibi her türlü hizmet için kullanabiliyoruz; bulut altyapısının temeli de VM teknolojisidir.

Hypervisor için güvenlik varsayımları şunlardır: kötü niyetli programlar ya da saldırganlar misafir işletim sistemini ve onun üzerindeki uygulamaları ele geçirebilir; ancak içinde bulundukları VM'in sınırlarının dışına çıkamazlar, hypervisor'ı ve dolayısıyla host OS'u ele geçiremezler, aynı donanım üzerindeki diğer VM'lere bulaşamazlar. Öyleyse hypervisor kendini korumalı ve hata içermemelidir. Bu yüzden mümkün olduğunca basit, küçük ve analiz edilebilir olmalı; tam bir işletim sisteminin bütün özelliklerine değil, yalnız sanallaştırmayı düzgün sağlayacak özelliklere sahip olmalıdır.

IBM donanımlarında olgunlaşmış bu teknoloji 2000'den itibaren Intel işlemcilere, standart sunuculara ve masaüstü bilgisayarlara uygulanmaya başlayınca donanım ve işlemci mimarisi kaynaklı eksikler ve buna bağlı zafiyetler ortaya çıktı; yeni bir olgunlaşma süreci başladı.

## 14. Gizli Kanallar (Covert Channels)

### 14.1 Tanım

Bu sıkıntıların başında gelenlerden biri gizli kanal (covert channel) zafiyetidir. Covert; gizli, açıkta olmayan, saklı demektir. Slayttaki tanım (ekrandan, 01:40:00): gizli kanal, yalıtılmış bileşenler arasında istenmeyen (öngörülmemiş, planlanmamış) bir haberleşme kanalıdır; gizli veriyi güvenli bileşenden açık bileşene sızdırabilir.

Hoca bunu akrostişe benzetti: şiir satır satır yazılır ve satır satır okunur, ama satırların ilk harfleri yukarıdan aşağı okunduğunda başka bir kelime ya da cümle çıkar. Gizli kanal da böyle, normal okumanın altına gizlenmiş bir haberleşmedir.

### 14.2 Senaryo

Slayttaki şekilde aynı hypervisor üzerinde iki VM var: gizli bir belge (secret doc) işleyen Classified VM ve herkese açık Public VM. Amaç da zaten budur: aynı donanım üzerinde hem gizli hem gizli olmayan veriyi işleyebilmek.

Classified VM'de bir malware vardır. Hoca bunun oraya nasıl girdiğini sosyal mühendislikle açıkladı. Gizli endüstriyel projelerin araştırıldığı bir laboratuvar düşünün (illa devlet sırrı olması gerekmez). Orada çalışan bir mühendis evine gönderilen e-posta ya da mesajlarla veya sosyal medya hesapları üzerinden bir linke gitmeye ikna edilir. Zamanla evde kullandığı USB belleği laboratuvardaki bilgisayara takar. Laboratuvar bilgisayarında gerekli tedbirler alınmamışsa tamamen kapalı bir ortama USB bellek üzerinden malware yerleşmiş olur.

Malware kalın duvarlarla çevrili bir VM'in içindedir; dışarı çıkmak kolay görünmez. Public VM ise herkese açıktır, ele geçirilebilir; orada malware'in diğer ucu olan bir dinleyici (listener) çalışır. Malware ile listener arasında bir gizli kanal kurulur. Nasıl? İkisi de aynı donanımı kullanır; tek işlemci olduğunu varsayalım. O dönemde VM'ler arasında işlemci performansı açısından bir yalıtım yoktu. Hoca, PC sanallaştırmasının başında uzun süre çalışılan problemlerden birinin işlemci gücünün VM'ler arasında sınırlanarak paylaştırılması olduğunu, bugün bunun bir iki sıkıntı dışında büyük ölçüde çözüldüğünü söyledi. Başlangıçta "2 GHz'lik işlemcinin 1 GHz'i bir VM'e, 1 GHz'i diğerine ait olsun" gibi bir kısıt yoktu; o an işlemci yoğun iş yapan VM 2 GHz'in tamamını kullanabiliyor, diğerine neredeyse bir şey kalmıyordu.

### 14.3 Bit gönderme

Malware'i de listener'ı da aynı kişi yazdığı için basit bir protokol kurulur. Slayttaki kurgu (ekrandan, 01:45:00):

- $b \in \{0,1\}$ bitini göndermek için malware:
  - $b = 1$ ise saat 1:00'de işlemci yoğun bir hesap yapar (hoca örneğin 10 saniye boyunca dedi),
  - $b = 0$ ise saat 1:00'de hiçbir şey yapmaz.
- Listener saat 1:00'de işlemci yoğun bir hesap yapar ve bitiş süresini ölçer.
- $b = 1 \Rightarrow$ bitiş süresi > eşik.

Listener her gece aynı işi yapar; işin işlemci boşken ve işlemci yoğun kullanılırken ne kadar sürdüğünü bilir. Arada ayırt edici bir eşik değeri vardır: süre eşiğin altındaysa 0, üstündeyse 1 geldiğini kabul eder. Mantık şudur: birbirinden yalıtılmış iki bileşen alt tarafta işlemciyle birbirine bağlıdır ve işlemci gücü açısından yalıtım yapılmadığı için aralarında veri aktarılabilir.

İşlemci yükü tek kaynak değildir: önbellek içerikleri, kesme gecikmesi, bir dosyanın kilitli olup olmaması gibi çok farklı noktalar gizli kanal için başlangıç noktası olabilir. Hepsini ortadan kaldırmak zordur. Gizli kanalın asıl sıkıntısı, böyle bir sızıntı olduğu fark edilmediği sürece kanalın orada durabilmesidir.

## 15. Pratikte VM İzolasyonu

### 15.1 Bulut

Slayttaki şekilde (ekrandan, 01:50:00) iki müşterinin VM örnekleri (VM instance customer 1 ve customer 2), kendi misafir işletim sistemleriyle aynı Xen hypervisor üzerinde çalışıyor. Xen bir Type 1 hypervisor'dır: donanımın üzerine doğrudan oturur, host OS yoktur. Hoca bunun işi basitleştirdiğini ve işlemci performansının daha iyi yönetilmesini sağladığını söyledi. Farklı müşterilerin VM'leri aynı makinede çalışabilir; hypervisor VM'leri yalıtmalıdır ama bir miktar bilgi sızar.

### 15.2 Son kullanıcı tarafı

Son kullanıcı tarafında VM'ler farklı müşterilerin değil aynı kişinin uygulamalarıdır; birinde Windows ve Windows uygulamaları, diğerinde Debian ve Debian uygulamaları çalışabilir. Qubes OS bu fikri uca götürür: her şeyi Xen hypervisor üzerinde ayrı bir VM olarak çalıştırır ve çevre birimlerine erişimi VM'ler denetler. Örnekler:

- Tek kullanımlık VM (disposable VM): içinde bir şeyler denenip yok edilen, gerekirse çökmesine izin verilen VM.
- Şifrelerin saklandığı kasa (vault) VM.
- Tor VM.

Hoca iki slayt arasındaki temel farkı vurguladı: bulut örneğinde VM'ler farklı şirketlere ve kurumlara aittir, aralarında veri kaçağı çok daha vahim bir durumdur; Qubes örneğinde ise VM'ler aynı kullanıcıya aittir.

## 16. Hypervisor Tespiti

### 16.1 Bir işletim sistemi hypervisor üzerinde çalıştığını anlayabilir mi?

Slayttaki soru buydu (ekrandan, 01:55:00). Hocanın cevabı: kesinlikle anlayabilir. Donanım ile onu kullanan işletim sistemi ve uygulamalar arasına ne kadar ince olursa olsun bir yazılım katmanı girer. Bu katmanın aynı donanımı çoklayabilmesi (multiplex) için donanımı üst tarafa normalden farklı göstermesi gerekir. Ayrıca ne kadar optimize olursa olsun bare metal'e (fiziksel makineye) göre belirli noktalarda performans farkı oluşur.

Slayttaki uygulamalar:

- **Malware hypervisor'ı fark edebilir** ve tersine mühendislikten kaçmak için çalışmayı reddedebilir. Malware "beni özel bir sandbox'a, bir VM'e koydular; yapımı tersine mühendislikle çıkaracaklar, o zaman çalışmıyorum" diye düşünebilir. Bazı malware'ler kodlarını şifreli olarak taşır; kod, uygulamanın içinde bir veri gibi görünür ve ancak belirli şartlar sağlanınca çözülüp (decrypt, decompress) devreye girer ya da bir komuta kontrol merkezinden ek parçalar indirilir. Malware çalışmazsa bu kısımlar açılmadığı için orijinal hâline ulaşmak çok zorlaşır.
- **Donanıma bağlı yazılım VM'de çalışmayı reddedebilir.** Belirli bir donanım için geliştirilmiş uygulama VM'de olduğunu fark ederek çalışmayabilir.
- **DRM sistemleri hypervisor üzerinde çalışmayı reddedebilir.**

Hoca DRM (Digital Rights Management) örneğini açtı. Bir videoyu kiraladığınızı ve 48 saat izleyebileceğinizi düşünün. Ekranda oynatabildiğinize göre kopyalamanızı ne engelliyor? Fiziksel donanımda ekrandaki görüntünün tutulduğu belleğe (frame buffer) erişip oradan videoyu kopyalamak zordur; özel bir sürücü yazıp kareleri tek tek dosyaya kaydedebilirsiniz (video ya da frame grabber'lar bu mantıktadır), ama emek ve en az performans etkisi gerekir. Aynı şeyi VM'de çalıştırırsanız neredeyse hiçbir şey yapmanıza gerek kalmaz: VM ekrana aradaki bir yazılım üzerinden erişir, aynı ekran VM'ler arasında paylaşıldığı için orada bir çoklama ve ayırma vardır ve araya girmek çok kolaydır. Video ne kadar şifrelenmiş ve süreyle kısıtlanmış olursa olsun, ekrana gösterilebilmek için çözülmüş olarak gönderilir. VM ortamında bu veriyi almak inanılmaz kolay olduğu için DRM sistemleri hypervisor varsa çalışmayı reddedebilir.

### 16.2 Red pill ve blue pill

Hoca Matrix filminden alınan iki yaklaşımı anlattı. Red pill: hypervisor'ın varlığını fark ediyoruz ve ona göre davranıyoruz, yani gerçeklerin farkındayız. Blue pill: hypervisor var mı yok mu bilmeden tamamen sanal ortamın içinde çalışıyoruz. Hypervisor tespiti red pill'dir.

Slayttaki red pill teknikleri (ekrandan, 02:00:00):

- **VM platformları çoğu zaman basit donanım taklit eder.** VMware eski bir i440bx yonga setini taklit eder, ama 8 GB RAM, çift CPU gibi değerler bildirir. Hoca bu yonga setini kendisinin de kullandığını, döneminde anakartların "Mercedes'i" sayıldığını, ama iki işlemciyi ve 8 GB RAM'i desteklemediğini anlattı. İşletim sistemini sanal makineye kurup Windows'ta sistem özelliklerine ya da Linux'ta `/proc` altındaki `cpuinfo` ve `meminfo`'ya baktığınızda hem i440bx yonga setini hem 8 GB RAM'i görürsünüz; bu mümkün değildir.
- **Hypervisor zaman gecikmesi farkları yaratır.** Bellek önbelleğinin davranışı hypervisor varken farklıdır; bu, herhangi iki işlem arasında göreli süre farklarına yol açar. Zamanlama (scheduling) davranışı da değişir.
- **Hypervisor TLB'yi misafir OS ile paylaşır;** misafir OS küçülmüş TLB boyutunu fark edebilir. TLB (Translation Lookaside Buffer) sanal bellek yönetimini hızlandırır. Aynı anda 2-3-4 VM yönetildiği için TLB'nin tamamı tek bir VM'e ait olmamalı, bölünerek kullanılmalıdır. Hoca, Intel işlemcilerde TLB kullanımı üzerinden yapılmış saldırılar olduğunu da hatırlattı: bir süreçten (ya da VM'den) diğerine geçerken TLB içerikleri sıfırlanmıyor ya da önceki sürece ait kullanılabilir izler kalıyor.
- Ve başka pek çok yöntem (slaytta kaynak: [GAWF'07]).

### 16.3 Tarayıcı VM'de çalıştığını anlayabilir mi?

Neden böyle bir şeye ihtiyaç var? Kötü niyetli web sitelerini bulmak için tarama (crawling) yapılabilir; crawling yalnız arama motoru indekslemesi için değildir. VM'de çalışan bir tarayıcıya sayfalar yüklenir; sayfa çalışınca VM'e zarar geliyorsa (VM'i ele geçirmeye çalışıyorsa) sayfa kötü niyetli olarak işaretlenir. Peki buradaki malware (alt seviyede değil, tarayıcının içinde) kendisini yakalamak için kurulan düzeneği fark edebilir mi? Maalesef edebilir. En basit yol: VM altındaki tarayıcıda render ve ekrana yazma işlemleri normal donanıma göre daha yavaştır. Ağ erişimindeki farklar ölçülebilir olmayabilir ama ekran tarafındaki fark çok belirgindir. Sayfadaki kötü niyetli JavaScript bu zamanlama bilgisiyle durumu fark edip normal davranabilir.

Bu yüzden kötü niyetli uygulamaları statik olarak bulabilmek çok daha önemlidir. Dinamik olarak bulmak için onları çalıştırmak gerekir; bunun iki riski vardır: daha önce görülmemiş bir yöntemle sistemin kontrolünü ele geçirmesi ya da kontrollü bir ortamda çalıştırıldığını fark edip tamamen normal davranması.

### 16.4 Sonuç

Hypervisor'lar fark edilebilir. Mükemmel hypervisor yoktur; günümüz hypervisor'larının iki odağı uyumluluk (compatibility) ve performanstır, yüzde yüz şeffaflık (transparency) sağlamazlar. Bu bazen lehimize, bazen aleyhimizedir: malware tespiti örneğinde aleyhimize, DRM örneğinde (hocanın anlatımıyla) lehimizedir.

## 17. Software Fault Isolation

### 17.1 Amaç

Son konu thread'lerin birbirinden yalıtılmasıydı. Slayttaki başlık "Software Fault Isolation [Whabe et al., 1993]" idi (ekrandan, 02:05:00). Hoca bunun 1993'e, yani süreç izolasyonundan (1996) daha eskiye dayandığını, çünkü ihtiyacın güvenlikten önce de var olduğunu söyledi.

> **Ders sonrası not:** Slaytta yazar adı "Whabe" olarak yazılmış; büyük olasılıkla doğrusu Wahbe'dir (Wahbe, Lucco, Anderson, Graham, 1993).

- **Hedef:** aynı adres alanında çalışan uygulamaları sınırlamak.
  - Kernel modülü kernel'i bozmamalıdır. İşletim sistemi kernel'inde disk, yazıcı, ağ aygıtı için aygıt sürücüleri vardır. Her biri bir thread gibidir, kernel de bir süreç gibidir; sürücülerden birindeki sorun aynı adres alanında oldukları için bütün kernel'in çökmesine yol açar.
  - Native kütüphaneler JVM'i bozmamalıdır. Java Virtual Machine çoğu zaman JNI üzerinden C kütüphanelerine, libc'ye erişir; her erişimde benzer risk vardır.
- **Basit çözüm:** uygulamaları ayrı adres alanlarında çalıştırmak.
  - Sorun: uygulamalar sık haberleşiyorsa yavaştır; her mesaj bir bağlam değişimi (context switch) gerektirir.

Hoca, ayrı adres alanlarının işleri ne kadar yavaşlattığını bildiğimizi söyledi: süreçler gereğinden fazla yalıtılmış olabilir. Aynı uygulamada çalışacak thread'leri süreçlere bölüp sonra süreçler arası haberleşme ile konuşturduğunuzu, araya en az kernel müdahalesi girse bile performansın thread'lere göre ciddi biçimde kötü olacağını düşünün. Öyleyse aynı adres alanındaki ilişkili thread'leri anlamlı biçimde yalıtacak bir yönteme ihtiyaç vardır.

### 17.2 Yöntem

Yaklaşım basittir: süreç belleği thread'lere göre parçalara bölünür. Her thread'in bir kod segmenti ve bir veri segmenti olur; süreç belleğinin şu kadarlık kısmı bu thread'in kodu, şurası verisi, şurası ikinci thread'in, şurası üçüncünün diye ayrılır.

Bu kez sistem çağrıları yerine güvenli olmayan makine komutlarına bakılır: her türlü jump, load ve store; call da jump'ın otomatik geri dönüşü sağlayan bir çeşididir. Bunların hepsi adres içerdiği için tehlikelidir. En temel yaklaşım, derleme sırasında bu güvenli olmayan komutların alışık olduğumuz guard yaklaşımıyla korunmasıdır. Hoca daha önce görülen StackGuard gibi guard'ları hatırlattı. Kod yüklenirken de guard'ların gerçekten var olduğundan emin olunmalıdır. <!-- BELİRSİZ: hocanın StackGuard'dan sonra saydığı ikinci örnek altyazıda "Kernel, Bouncer" diye geçiyor; anlaşılamadı -->

### 17.3 Segment eşleme tekniği

Slayttaki bilgiler (ekrandan, 02:10:00):

- MIPS işlemcisi için tasarlanmıştır; çok sayıda register vardır.
- `dr1`, `dr2`: program (binary) tarafından kullanılmayan ayrılmış (dedicated) register'lar.
  - Derleyici bu register'lar yokmuş gibi davranır.
  - `dr2` segment kimliğini (segment ID) tutar.

MIPS bir RISC işlemcisidir; o dönemdeki MIPS'te register'lar 32 bitliktir. ARM ve PowerPC de aynı mantıktan gelir. İki register'ı kullanıcı kullanmaz; derleyici bunları guard'ları oluşturmak için kendisine ayırır.

Hocanın anlattığı örnek komut, `R12` register'ına `R34`'ün gösterdiği adresteki değeri yüklemektir; bu dolaylı (indirect) bir load'dur. Tek komutla yapılabilecek bu iş, derleme sırasında guard komutlarıyla şöyle bir diziye dönüştürülür (anlatımdan kurulan sözde kod):

```text
dr1 <- R34                  # hedef adresi ayrılmış register'a al
scratch <- dr1 >> 20        # sağa kaydırarak segment ID'yi çıkar
compare scratch, dr2        # adresin segmenti thread'in segmenti mi?
trap if not equal           # değilse yazılım kesmesi
R12 <- [dr1]                # eşitse load'u yap
```

<!-- BELİRSİZ: guard kodunun slayttaki tam hâli karede görülmedi; yukarıdaki dizi altyazıdaki anlatımdan kuruldu, komut adları ve scratch register'ın adı kesin değil -->

Guard, kodun başka bir segmentten veri yüklememesini sağlar (guard ensures code does not load data from another segment). Adresin segment kimliği kısmı `dr2` ile eşitse load yapılabilir; değilse yazılım kesmesi oluşturulur.

Hoca segment boyutunu anlatırken "birer megabayt olsun, 12 bit... 12 bit olursa 4 megabayt olur" dedi ve sonra "20 bit, o zaman bunu sağa doğru shift ettiğimizde segment ID'sini alırız" diye düzeltti.

> **Ders sonrası not:** 32 bitlik bir adreste sağa 20 bit kaydırınca kalan üst $32 - 20 = 12$ bit segment kimliğidir; segment içindeki uzaklık (offset) 20 bittir, yani her segment $2^{20} = 1\,048\,576$ bayt = 1 MB'tır ve $2^{12} = 4096$ segment olabilir (python ile doğrulandı). Hocanın ara cümlesindeki "12 bit olursa 4 megabayt" ifadesi bu hesaba uymuyor; büyük olasılıkla doğrusu "segment ID 12 bit, segment boyutu 1 MB"dir.

İkinci bir yol daha vardır: adresi kontrol etmek yerine doğru segmente zorlamak. Adres segment maskesiyle AND'lenip segment bitleri sıfırlanır, sonra `dr2` ile OR'lanarak segmentin olması gereken değeri yerleştirilir ve yükleme doğrudan yapılır. Hoca birinci yöntemde bir satır yerine beş satır, bu yöntemde ise üç satır olduğunu, dolayısıyla performansın daha yüksek olduğunu söyledi. Buna address sandboxing denir. Hata ayıklama için birinci yöntem daha anlamlıdır, çünkü hatanın nerede olduğu görülür; üretim için ikincisi daha anlamlıdır.

> **Ek bilgi (derste anlatılmadı):** Address sandboxing'de kötü niyetli bir adres hata vermez, sessizce kendi segmentinin içindeki bir adrese çevrilir. Bu yüzden program başka bir segmente erişemez ama yanlış yere yazarak kendi segmentini bozabilir; yalıtımın amacı da zaten diğer segmentleri korumaktır.

### 17.4 Dolaylı jump ve cross-domain call

Kod dolaylı bir adrese jump ederse, yani bir register'daki adresin içeriğine atlarsa, bunun da önüne geçilmelidir. Jump komutu her zaman doğrudan değildir, bazen dolaylıdır; bu yüzden onun etrafına da aynı biçimde guard konur.

Hoca bir de cross-domain call kavramını anlattı. Bu, nesne yönelimli programlamada ve Remote Procedure Call mantığında da konuşulan eski bir kavramdır: bir taraf çağıran (caller), bir taraf çağrılan (callee). Bütün call komutları, kontrolden sonra çağrıyı gerçekleştiren branch'lere (jump) dönüştürülür; return'ler de branch'e dönüştürülür. Böylece uygulama dinamik olarak call yaptığını düşünür ama alt tarafta bu call bir kontrolden geçirilip jump ile gerçekleştirilir.

## 18. SFI'nin Performansı ve x86'daki Sınırları

Slayttaki özet (ekrandan, 02:15:00):

- **Performans:** genelde iyidir; `mpeg_play` için %4 yavaşlama. Hoca, `mpeg_play` bir video oynatıcısıyken guard'lar yerleştirildiğinde aynı donanımda %4 yavaşlama görüldüğünü, bunun kabul edilebilir olduğunu ve SFI mantığının genel olarak iyi bir mantık olduğunu söyledi.
- **SFI'nin sınırları: x86'da uygulamak daha zordur.**
  - Değişken uzunlukta komutlar: guard'ların nereye konacağı belirsizdir. Aynı komutun 2, 4, 5 baytlık türleri vardır. RISC işlemcilerde komutlar eşit uzunluktadır. Hoca bunun derleme zamanında çözülebileceğini, çok büyük bir sıkıntı olmadığını söyledi.
  - Az register: üçü SFI'ye ayrılamaz. Klasik Intel mimarisinde AX, BX, CX, DX olmak üzere dört genel register vardır; ikisi SFI'ye ayrılırsa iki tane kalır ve bunlardan biri zaten akümülatör, dönüş değeri gibi işleri tutar. Ayrıca bir de geçici (scratch) register gerekir. Bu büyük bir sıkıntıdır. Hoca yeni i3, i5, i7, i9 işlemcilerde ek register'lar geldiğini de belirtti.
  - Belleği etkileyen çok komut vardır: daha çok guard gerekir. RISC mimarisinde belleğe dokunan komutlar load (bellekten okuma), store (belleğe yazma) ve dolaylı olabilen jump'tır. CISC olan Intel'de ise AND, OR, çarpma, kaydırma gibi neredeyse her komutun bir işleneni bellek olabilir. Bu yüzden derleme sırasında çok daha fazla durum değerlendirilmeli; kod hem gereksiz uzar ve performans düşer hem de karmaşıklaşır.

> **Ders sonrası not:** Slayt "three" register'dan söz ediyor; hocanın anlattığı iki ayrılmış register (`dr1`, `dr2`) ile guard dizisinde kullanılan geçici (scratch) register birlikte büyük olasılıkla bu üç register'ı oluşturur.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:31:57): chroot ile oluşturulan hücreden kaçmanın yolu var mı?

> **Cevap (derste verildi):** İlk dönemde `../../` ile üst dizine çıkılarak kaçılabiliyordu; işletim sistemleri bunu yamaladı. Ayrıca chroot root dışındaki kullanıcılara açıksa, hücredeki süreç kendi alanında `/aaa/etc/passwd` dosyasını root için istediği şifreyle oluşturur, `chroot /aaa` ve `su root` ile root olur. Bu yüzden chroot yalnız root tarafından çalıştırılabilmelidir. Root olarak hücreye girip root olarak kalmak da kısıtı anlamsızlaştırır.

**Soru 2** (ekrandan, 01:00:00): ptrace tabanlı bir monitörde aşağıdaki sıra hangi sonuca yol açar ve bu hata nasıl adlandırılır? Başlangıçta `me -> mydata.dat`.

```text
proc 1:  open("me")
monitor checks and authorizes
proc 2:  me -> /etc/passwd
OS executes open("me")
```

> **Cevap (derste verildi):** Monitör `me` dosyasını (`mydata.dat`) denetleyip onaylar, ama işletim sistemi çağrıyı yürütmeden önce süreç 2 linki `/etc/passwd`'ye çevirir. Sonuçta süreç 1 `/etc/passwd` dosyasını açmış olur ve monitörün onayı anlamsızlaşır. Sebep, denetim ile kullanımın atomik olmamasıdır: Time of Check, Time of Use (TOCTOU) hatası. Yorumlanan dillerde yazılmış yavaş uygulamalarda bu yarışın olasılığı daha yüksektir.

**Soru 3** (ekrandan, 01:45:00): Aynı donanımda çalışan Classified VM'deki malware, Public VM'deki listener'a işlemci yükü üzerinden nasıl bir bit gönderir?

> **Cevap (derste verildi):** $b=1$ için malware saat 1:00'de işlemci yoğun bir hesap yapar, $b=0$ için hiçbir şey yapmaz. Listener aynı saatte işlemci yoğun bir hesap yapıp bitiş süresini ölçer. İşlemci VM'ler arasında paylaştırılmadığı için malware çalışıyorsa listener'ın işi uzar: bitiş süresi eşikten büyükse $b=1$, küçükse $b=0$.

**Soru 4** (ekrandan, 01:55:00; derste sözlü, 01:52:09): Bir işletim sistemi bir hypervisor üzerinde çalıştığını anlayabilir mi? Bu neden önemlidir?

> **Cevap (derste verildi):** Kesinlikle anlayabilir. Hypervisor donanımı çoklamak için onu farklı gösterir (ör. VMware'in i440bx yonga seti ile 8 GB RAM ve çift CPU bildirmesi), önbellek ve zamanlama davranışını değiştirerek gecikme farkları yaratır ve TLB'yi bölerek misafire küçülmüş TLB gösterir. Önemi: malware VM'de olduğunu anlayıp tersine mühendislikten kaçmak için çalışmayabilir; donanıma bağlı yazılımlar ve DRM sistemleri VM'de çalışmayı reddedebilir.

**Soru 5** (derste sözlü, 02:00:27): Bir tarayıcı (içindeki kötü niyetli JavaScript) VM altında çalıştığını anlayabilir mi?

> **Cevap (derste verildi):** Maalesef anlayabilir. VM altındaki tarayıcıda render ve ekrana yazma işlemleri normal donanıma göre belirgin biçimde daha yavaştır; JavaScript bu zamanlama farkından ortamı fark edip normal davranabilir. Bu yüzden kötü niyetli kodu statik olarak bulmak daha önemlidir.

**Soru 6** (derste sözlü, 02:10:43): SFI segment eşleme tekniğinde 32 bitlik bir adres sağa 20 bit kaydırılarak segment kimliği elde ediliyorsa segment kimliği kaç bittir, her segment kaç bayttır ve kaç segment olabilir?

> **Çözüm (derste verilmedi):** Segment kimliği $32 - 20 = 12$ bittir. Segment içi uzaklık 20 bit olduğundan her segment $2^{20} = 1\,048\,576$ bayt, yani 1 MB'tır. Segment sayısı en çok $2^{12} = 4096$'dır. Değerler python ile doğrulandı.

## Dersin Toparlaması

Bu derste kötü davranan bir uygulamanın sistemin geri kalanına zarar vermesini engelleyen sınırlama ilkesi farklı seviyelerde incelendi. Fiziksel air gap en güçlü ama yönetimi en zor yaklaşımdır. Sanal makineler aynı ayrımı tek donanım üzerinde hypervisor ile sağlar, ancak gizli kanallar ve hypervisor tespiti gibi sorunlar taşır. Süreç seviyesinde chroot ve FreeBSD jail dosya sistemi (jail'de ayrıca ağ ve süreçler arası haberleşme) üzerinden kaba bir sınırlama yapar. System Call Interposition ise sistem çağrılarını bir referans monitörüyle denetler. Bu fikrin ptrace tabanlı ilk biçimi (Janus) performans sorunları ve TOCTOU yarışı nedeniyle zayıftır. Linux'taki seccomp-bpf, filtreyi kernel'e gömerek bu sorunları çözer ve Chrome ile Docker'da kullanılır. Ostia ise libc stub ve kullanıcı alanındaki bir ajanla aynı işi en az kernel desteğiyle yapar. Thread seviyesinde Software Fault Isolation, adres içeren komutların önüne derleyicinin guard eklemesiyle aynı adres alanındaki parçaları ayırır. MIPS gibi RISC işlemcilerde ucuzdur (%4 yavaşlama), x86'da ise zordur.

Hoca dersi iki uyarıyla bağladı. Tam izolasyon amaç değildir, çünkü uygulamaların haberleşmesi gerekir; önemli olan haberleşmenin öngörülen ve bilinen kanallardan yapılmasıdır. Kullanılan yöntem ne olursa olsun kurallar doğru tanımlanmamışsa yöntem işe yaramaz. Gizli kanallar da ciddi bir baş ağrısıdır; çoğu zaman bir güvenlik açığı yaşanmadan fark edilmezler. Sonraki derste kalınan yerden devam edileceği söylendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
