# Ders 7 Genişletilmiş Notu: Güvenlik Denetimi ve Denetim İzleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Giriş: güvenlik denetimi neden gereklidir
- 2. Güvenlik denetimi terminolojisi (RFC 4949)
- 3. Güvenlik denetim mimarisi (X.816)
- 4. Olay tanımlama ve olay tespiti
- 5. Uygulama yönergesi ve toplanacak veriler
- 6. Denetlenebilir öğeler: X.816 ve ISO 27002
- 7. Denetim izi örnekleri ve fiziksel erişim izleri
- 8. Denetim verisinin depolanması (RFC 2196)
- 9. Loglama işlevinin uygulanması: Windows ve Unix
- 10. Syslog servisi ve protokolü
- 11. Uygulama düzeyi loglama
- 12. Denetim izi analizi
- 13. SIEM sistemleri
- Dersin Toparlaması

## 1. Giriş: güvenlik denetimi neden gereklidir

Bu ders, bilgisayar ve ağ güvenliğinin yönetimsel boyutunu işleyen dizinin devamıdır. Önceki derslerde önce örnek bir firmanın varlıkları üzerinden risk değerlendirmesi ve risk yönetimi yapılmış, ardından bu risk analizine dayanarak güvenlik kontrolleri, planları ve prosedürleri çıkarılmıştı. Daha sonra bilişim güvenliğinin yalnız mantıksal boyuttan ibaret olmadığı, sunucuların fiziksel altyapısını, barındıkları binayı ve kampüsü kapsayan fiziksel ve altyapı güvenliği anlatılmıştı. Son olarak hem sistemin kullanıcısı, hem saldırganı, hem de güvenliğini sağlayanı olan insanın güvenliği, yani işe alımdan iş sözleşmelerine, güvenlik araştırmalarından işten ayrılma süreçlerine kadar insan kaynakları güvenliği standartlar ölçüsünde ele alınmıştı.

Bu dersin konusu güvenliğin denetimidir. Hoca bunu bir işletim sistemi kurulumuyla karşılaştırdı: bir sisteme işletim sistemi kurulur, ayarlar yapılır ve sonra yalnız güncelleme geldiğinde ya da sorun çıktığında ilgilenilir. Güvenlik böyle işlemez; "kur ve unut" mantığında bir mekanizma değildir. Saldırganlar sürekli yeni teknolojilerle yeni zayıflıklar arar. Bu yüzden kurulan sistemin, yapılan planların, prosedürlerin ve kontrollerin doğru işlediği sürekli denetlenmeli, denetim sonuçlarına göre planlar gözden geçirilip güncellenmelidir.

Hoca bir başka gerekçeye de dikkat çekti: güvenlik için tedbirler alınır, prosedürler konur, kullanıcılara politikalar uygulanır. Sistem tamamen güvenli olup hiç saldırı yaşanmadığında insanların aklına "bu sisteme boşa mı harcadık" sorusu gelir. Alınan önlemlerin sonuç verdiğini görmek de güvenlik denetimiyle mümkündür. Ayrıca denetim sayesinde hatalar erken bulunur ve bu hatalar nedeniyle yeni zararlar doğma olasılığı düşer.

> **Hocanın vurgusu:** Güvenlik denetimi, en az uyguladığınız politikalar ve prosedürler kadar önemlidir.

Dersin içeriği slaytta şöyle verildi (ekrandan, 00:10:00):

- Güvenlik denetim mimarisi
- Güvenlik denetimi izi
- Loglama işlevini uygulama
- Denetim izi analizi
- Güvenlik bilgileri ve olay yönetimi

Denetimin en önemli enstrümanı loglamadır. Planlar, programlar ve kontroller yapılır; bu kontrollere göre belirli mekanizmalar ve veriler kaydedilir. Sonra bu kayıtlar incelenerek sürecin rutin biçimde, beklendiği gibi işleyip işlemediği ya da anormal bir aktivite olup olmadığı kontrol edilir. Bu incelemeye göre sistemde saldırı olup olmadığı, bir saldırı teşebbüsü mü yoksa gerçekleşmiş bir saldırı mı olduğu anlaşılır ve bir sonraki adım uygulanır. Logların analizi ve analiz sonucunda olay yönetimi (bir olay gerçekleştiğinde nasıl bir tepki verileceği) bu yüzden önemlidir.

## 2. Güvenlik denetimi terminolojisi (RFC 4949)

Aynı dili konuşmak için hoca terminolojiyi standart bir kaynaktan, güvenlik terminolojisinde sık kullanılan RFC 4949 belgesinden verdi. Slayttaki tablo şöyledir (ekrandan, 00:15:00):

| Terim | Tanım |
|---|---|
| Güvenlik Denetimi | Sistem kontrollerinin yeterliliğini belirlemek, yerleşik güvenlik politikası ve prosedürlerine uyumu sağlamak, gizlilik hizmetlerindeki ihlalleri tespit etmek ve karşı önlemler için belirtilen değişiklikleri tavsiye etmek için bir sistemin kayıtlarının ve faaliyetlerinin bağımsız olarak gözden geçirilmesi ve incelenmesidir. Temel denetim amacı, güvenlikle ilgili olayları ve eylemleri başlatan veya bunlara katılan sistem varlıkları için hesap verebilirlik oluşturmaktır. Bu nedenle, bir güvenlik denetim izi oluşturmak ve kaydetmek ve saldırıları ve güvenlik ihlallerini keşfetmek ve araştırmak için denetim izini incelemek ve analiz etmek için araçlara ihtiyaç vardır. |
| Güvenlik Denetimi İzi | Başlangıcından nihai sonuçlarına kadar güvenlikle ilgili bir işlemde bir operasyon, prosedür veya olayı çevreleyen veya bunlara yol açan ortamlar ve faaliyetler dizisinin yeniden oluşturulmasını ve incelenmesini sağlamak için yeterli olan sistem faaliyetlerinin kronolojik kaydıdır. |

Hoca "bağımsız olarak" ifadesini açtı: normal bir akışta sistemin bir süreci vardır; veriler ve mesajlar akar, sistemler işler. Güvenlik denetimi bu normal işleyişten bağımsız olarak sistemin gözlenmesi ve incelenmesidir. Denetim amacıyla yapılan kayıtlar da rutin süreçten ayrı tutulur.

Hesap verebilirlik kavramı için hoca bir benzetme kullandı: bir güvenlik ihlali tespit edildiğinde durum, başı ağrıyan birinin durumuna benzer. Baş ağrısının nedeni migren mi, daha ciddi bir rahatsızlık mı, yoksa yaşanan bir üzüntü mü? Belirtiden nedene gitmek gerekir. Denetim izi de ihlali başlatan nedenleri ve ona katkı sağlayan unsurları tespit etmek için tutulur. Kronolojik kayıt sayesinde sorunun ve ihlalin nerede olduğu ve hangi bileşenlerin zafiyeti bulunduğu belirlenebilir. Bu iki terim üzerinde anlaşıldıktan sonra süreç daha net takip edilir.

## 3. Güvenlik denetim mimarisi (X.816)

### 3.1 Güvenlik denetimi ve alarm modeli

Hoca, ITU-T X.816 standardında tanımlanan güvenlik denetimi ve alarm modelini anlattı. Akışın başında bir olay ayrıştırıcı (event discriminator) bulunur. Rutin süreçlerdeki her faaliyet kaydedilmez. Örneğin e-posta trafiğinde her mesaj loglanmaz; belli adreslere giden e-postalar, içinde belli metinler geçen ya da belli ekleri olan e-postalar kaydedilir. Bunlar için belli eşikler (threshold) tanımlanır ve eşik aşıldığında alarm üretilir. Kısacası ayrıştırıcı ya belli verileri kayda gönderir ya da alarm üretir. Üretilen alarma göre olay yönetim planlarında tanımlı aksiyon alınır.

Alarm yalnız eşik aşıldığında üretilmez. Kaydedilmiş verilerin analizi sonucunda da alarm üretilebilir: bir faaliyet hiçbir eşiği aşmamış olabilir ama kayıtlar incelendiğinde anormal bir aktivite görülebilir. Son olarak kayıtlar arşive gönderilebilir ve toplu olarak yeniden incelenebilir. Hoca bu modeli standart dokümana dayanan, mantıklı ve takip edilebilir bir şema olarak niteledi.

<!-- BELİRSİZ: modelin şeması karelerde yok; bileşen adları ve aralarındaki oklar yalnız altyazıdan kuruldu -->

### 3.2 Dağıtık denetim izi modeli

X.816'daki ikinci model dağıtık denetim izi modelidir. Bir kurumda ağ, sunucular ve diğer bileşenler bulunur ve bunların hepsinde normal aktiviteler işlenir. Dağıtık modelde her sunucuda (örneğin e-posta sunucusunda) aktiviteleri takip edip toplayan küçük ajanlar vardır. Bu ajanların topladığı loglar belli bir noktada birleştirilir ve topluca analiz edilir. Hoca bunu, sistemi bütüncül olarak incelediğimizde karşımıza çıkan model olarak tanımladı.

### 3.3 Güvenlik denetimi işlevlerinin akışı

Ardından aynı yapı daha ayrıntılı bir akış olarak gösterildi. Sistemde sürekli işlemler olduğu için sürekli veri üretilir (veri üretimi); bu sırada verinin hangi kullanıcı kimliği tarafından üretildiği de kaydedilir. Üretilen veriler arasından bazı olaylar ve aktiviteler seçilir (olay seçimi). Seçilenlerin bir kısmı kaydedilir (olay depolama), belli aktivitelere ve eşiklere karşı alarm üretilir (otomatik yanıt). Kaydedilen veriler analiz edilerek potansiyel zayıflıklar ve potansiyel saldırılar bulunur (analiz). En sonunda denetimin genel incelemesi yapılır ve buna göre güvenlik planları oluşturulur ya da güncellenir.

<!-- BELİRSİZ: akış diyagramının slaytı karelerde yok; işlev adları altyazıdan alındı -->

## 4. Olay tanımlama ve olay tespiti

### 4.1 Olay tanımlama

Denetim izinin kronolojik takibinde eksik olmaması için önce hangi tür faaliyetlerin izleneceği, yani denetime tabi olaylar kümesi tanımlanmalıdır. Slaytta Ortak Kriterler'in önerdiği olaylar şöyle verildi (ekrandan, 00:20:00):

- Nesnelerin tanıtımı
- Nesnelerin silinmesi
- Erişim haklarının veya yeteneklerinin dağıtılması veya iptali
- Özne veya nesne güvenlik özniteliklerinde yapılan değişiklikler
- Güvenlik yazılımı tarafından gerçekleştirilen politika kontrolleri
- Politika kontrolünü atlamak için erişim haklarının kullanılması
- Tanımlama ve kimlik doğrulama işlevlerinin kullanımı
- Operatör/kullanıcı tarafından gerçekleştirilen güvenlikle ilgili eylemler
- Çıkarılabilir ortamdan/ortama veri alma/verme

Hoca maddeleri örneklerle açtı. Bir sistemde nesne tanımlanması ve silinmesi önemli olaylardır; örneğin veritabanında bir tablonun açılması ya da silinmesi kaydedilmesi gereken bir olaydır. Erişim haklarının verilmesi, dağıtılması ya da iptali kritik bir olaydır. Özellik değişiklikleri yalnız erişim haklarıyla sınırlı değildir; bazı kullanıcıların gruplarının ya da bağlı oldukları birimlerin değiştirilmesi, bazı nesnelerin haklarının değiştirilmesi de bu kapsamdadır. Güvenlik yazılımının yaptığı kontrollerde tespit edilen olaylar, sisteme gelen kullanıcının kimlik doğrulama ve tanılama süreçleri ve operatörün ya da kullanıcının güvenlikle ilgili eylemleri de kaydedilir. Bir bilgisayara çıkarılabilir flash disk ya da harici disk takılıp sisteme veri alınması ya da sistemden veri çekilmesi de tipik olarak tanımlanacak olaylardandır. Bu olayların sayısı, korunan sisteme bağlı olarak artırılabilir.

### 4.2 Olay tespiti

Olaylar tanımlandıktan sonra onların tespit edilmesi gerekir. Slayttaki maddeler (ekrandan, 00:25:00):

- Olay algılamayı etkinleştirmek için uygulamada ve sistem yazılımında uygun kancalar bulunmalıdır.
- İlgili etkinliği yakalamak için izleme yazılımının sisteme ve uygun yerlere eklenmesi gerekir.
- Kurcalamaya veya silmeye karşı dayanıklı güvenli bir depolama sağlama ihtiyacını içeren bir olay kayıt işlevi gereklidir.
- Olay ve denetim izi analizi yazılımı, araçları ve arayüzleri, toplanan verileri analiz etmenin yanı sıra veri eğilimlerini ve anormallikleri araştırmak için kullanılabilir.
- Denetim fonksiyonunun güvenliği için ek bir gereklilik vardır.
- Denetim sisteminin işlevsellik üzerinde minimum etkisi olmalıdır.

Kancalar (hook) için hoca balık tutma benzetmesini kullandı: olayları akış içinde yakalamak istiyoruz. Sazan tutmak için sazan kancası kullanılır; kocaman kancayla küçük balık, küçük kancayla büyük balık tutulamaz. Yakalanmak istenen olaya uygun kanca seçilmeli ve doğru yere eklenmelidir.

Depolama konusunda hoca bir saldırı senaryosu verdi. Kancalar tanımlanmış, uygun yerlere konmuş ve örneğin uzaktan girişleri ve yetki yükseltmelerini kaydediyor olsun. Bu kayıtlar saldırganın erişebildiği aynı yerde tutulursa, yetkisini yükselten akıllı bir saldırgan ilk iş olarak log kaydını değiştirir. Bu yüzden kayıtlar değiştirmeye, kurcalamaya (içeriği güncelleyip değiştirmeye) ve silmeye karşı dayanıklı, güvenli bir yerde tutulmalıdır.

Analiz araçları yalnız belirli eşiklerle alarm üretmek için kullanılmaz. Yapay zekâ ya da öğrenme yöntemleriyle anormallikler bulunabilir, verinin eğilimi incelenerek trendler çıkarılabilir.

Denetim sisteminin işlevselliğe etkisi konusunda hoca kendi gözleminden söz etti: bazen bir güvenlik cihazında o kadar karmaşık kurallar tanımlanır ki cihazın bu kuralları işleme kapasitesi yetersiz kalır. Cihaz aşırı yüklenir, ağın toplam kapasitesinin kullanılmasına izin vermez, darboğaz oluşturur ve performansı düşürür. Evde ya da küçük bir işletmede saniyede çok sayıda paket üretilmediği için bu bir sorun değildir. Ama büyük bir işletmede sistem saniyede 1 milyondan fazla paket üretiyor ve konulan cihaz saniyede yalnız 1 milyon paket işleyebiliyorsa fazlası düşürülür (drop) ve kurum tam kapasitesini kullanamaz.

> **Hocanın vurgusu:** Kuracağınız denetim sisteminin, sistemin işlevselliği üzerindeki etkisi sıfır ya da en az olmalıdır.

## 5. Uygulama yönergesi ve toplanacak veriler

### 5.1 Denetim için uygulama yönergesi

Güvenlik denetimi için bir uygulama yönergesi bulunmalıdır. Derste sayılan adımlar şunlardır:

- Denetim gereksinimleri üzerinde uygun yönetim kademesiyle anlaşmaya varılmalıdır.
- Kancaların hangi verileri almak için kullanılacağı belirlenmeli; teknik denetim testlerinin kapsamı kararlaştırılmalı ve kontrol edilmelidir.
- Denetim testleri yazılıma ve verilere salt okunur erişimle sınırlanmalıdır.
- Salt okunur dışındaki erişime yalnız sistem dosyalarının yalıtılmış kopyaları üzerinde izin verilmelidir.
- Özel veya ek işleme gereksinimleri tanımlanmalı ve kararlaştırılmalıdır.
- Sistem kullanılabilirliğini etkileyebilecek denetim testleri mesai saatleri dışında yapılmalıdır.
- Bir referans izi oluşturmak için tüm erişimler izlenmeli ve loglanmalıdır.

Hoca salt okunur erişimi şöyle gerekçelendirdi: denetimin amacı gözlemek ve gerekirse aksiyon almaktır, süreç üzerinde etki yapıp verileri değiştirmek değildir. Bir değişiklik yapılacaksa normal çalışan sistemde değil, onun klonu üzerinde yapılmalıdır. Mesai dışı test için örnek olarak log toplama, analiz, aktarım ve yedek alma gibi performans isteyen işlerin sistemin daha az yoğun olduğu zamanlarda yapılması gerektiğini söyledi.

### 5.2 Hangi veriler toplanmalı

Loglama denince her şeyin toplanıp toplanmayacağı sorusu akla gelir. Derste toplanabilecek veri grupları şöyle sayıldı:

- Denetim yazılımının kullanımıyla ilgili olaylar: birisinin denetime müdahale edip etmediğini görmek için.
- Sistemdeki güvenlik mekanizmalarıyla ilgili olaylar.
- Çeşitli güvenlik algılama ve önleme mekanizmaları tarafından kullanılmak üzere toplanan veriler.
- Sistem yönetimi ve sistemin işletimiyle ilgili olaylar.
- İşletim sistemine erişim.
- Seçilen uygulamalara erişim: kurum için kritik olan finans ya da ERP uygulamaları gibi.
- Uzaktan erişim faaliyetleri.

Bu liste de yapılan işe göre genişletilebilir.

## 6. Denetlenebilir öğeler: X.816 ve ISO 27002

### 6.1 X.816'da önerilen denetlenebilir öğeler

Slaytta X.816'ya göre önerilen denetlenebilir öğeler iki sütunlu bir tabloyla verildi (ekrandan, 00:30:00).

Sol sütun:

- Belirli bir bağlantıyla ilgili güvenlikle ilgili olaylar
  - Bağlantı istekleri, onaylanan bağlantılar, bağlantı kesme istekleri, onaylanan bağlantı kesmeler, bağlantıyla ilgili istatistikler
- Güvenlik hizmetlerinin kullanımıyla ilgili güvenlikle ilgili olaylar
  - Güvenlik hizmeti talepleri, güvenlik mekanizmaları kullanımı, güvenlik alarmları
- Yönetimle ilgili güvenlikle ilgili olaylar
  - Yönetim işlemleri, yönetim bildirimleri
- Denetlenebilir olayların listesi en azından şunları içermelidir
  - Giriş redleri, kimlik doğrulama, öznitelik değişikliği, nesne oluşturma, nesne silme, nesne değiştirme, ayrıcalık kullanımı

Sağ sütun, bireysel güvenlik hizmetleri açısından önemli olayları listeler:

- Kimlik doğrulama: başarının doğrulanması; doğrulama başarısızlığı
- Erişim kontrolü: erişimin başarılı olmasına karar verilmesi; erişimin başarısız olmasına karar verilmesi
- İnkâr edilemezlik: mesajın reddedilemez kaynağı; mesajın reddedilemez biçimde alındığı
- Reddetmeme: olayın başarısız ve başarılı biçimde reddedilmesi
- Bütünlük: kalkan (koruma) kullanımı; kalkansız kullanım; başarının doğrulanması; doğrulama başarısızlığı
- Gizlilik: gizleme kullanımı; açıklama kullanımı
- Denetim: denetim için olay seçimi; olay seçiminin kaldırılması; denetim olayı seçim kriterlerinin değiştirilmesi

Hoca bağlantı istatistiklerini "ne kadar sıklıkla, nereye bağlanıldığı" gibi bilgiler olarak örnekledi.

> **Ek bilgi (derste anlatılmadı):** Slayttaki "kalkan kullanımı" ve "kalkansız kullanım" ifadeleri büyük olasılıkla İngilizce "shield" ve "unshield" terimlerinin çevirisidir. Bütünlük hizmetinde veriye bütünlük koruması eklenmesi (shield) ve korumalı verinin bütünlüğünün doğrulanıp korumanın kaldırılması (unshield) anlamına gelir.

### 6.2 ISO 27002'de önerilen izleme alanları

X.816 güvenlik açısından bir öğe listesi verirken ISO 27002 izlenmesi gereken alanları şöyle sıralar:

- Kullanıcı kimlikleri
- Sistem faaliyetleri
- Oturum açma ve kapatma gibi temel olayların tarih, saat ve ayrıntıları
- Mümkünse cihaz kimliği, cihazın konumu ve sistem tanımlayıcısı
- Başarılı ve reddedilen sistem erişim girişimleri
- Başarılı ve reddedilen veri ve diğer kaynak erişim girişimleri
- Sistem yapılandırmasındaki değişiklikler
- Ayrıcalıkların kullanımı
- Sistem yardımcı programlarının ve uygulamaların kullanımı
- Erişilen dosyalar ve erişim türü
- Ağ adresleri ve protokolleri
- Erişim kontrol sistemi tarafından üretilen alarmlar
- Antivirüs ve saldırı tespit/önleme (IDS/IPS) sistemlerinin devre dışı bırakılma girişimleri
- Uygulamalarda kullanıcılar tarafından gerçekleştirilen işlemlerin kayıtları

## 7. Denetim izi örnekleri ve fiziksel erişim izleri

### 7.1 Örnek denetim izleri

Slaytta üç örnek denetim izi gösterildi (ekrandan, 00:35:00).

(a) Kimlik doğrulama mesajlarını gösteren örnek sistem logu:

```text
Jan 27 17:14:04  host1  login: ROOT LOGIN console
Jan 27 17:15:04  host1  shutdown: reboot by root
Jan 27 17:18:38  host1  login: ROOT LOGIN console
Jan 27 17:19:37  host1  reboot: rebooted by root
Jan 28 09:46:53  host1  su: 'su root' succeeded for user1 on /dev/ttyp0
Jan 28 09:47:35  host1  shutdown: reboot by user1
Jan 28 09:53:24  host1  su: 'su root' succeeded for user1 on /dev/ttyp1
Feb 12 08:53:22  host1  su: 'su root' succeeded for user1 on /dev/ttyp1
Feb 17 08:57:50  host1  date: set by user1
Feb 17 13:22:52  host1  su: 'su root' succeeded for user1 on /dev/ttyp0
```

Hoca bu logu okurken her kayıtta zamanın, işlemin hangi makinede olduğunun ve hangi işlemin yapıldığının tutulduğuna dikkat çekti: konsoldan root girişi yapılmış, sistem yeniden başlatılmış, bir kullanıcı `su` ile root yetkisi almış.

(b) Bir e-posta teslim sistemi için uygulama düzeyi denetim kaydı:

```text
Apr 9 11:20:22  host1  AA06370:  from=<user2@host2>, size=3355, class=0
Apr 9 11:20:23  host1  AA06370:  to=<user1@host1>, delay=00:00:02,stat=Sent
Apr 9 11:59:51  host1  AA06436:  from=<user4@host3>, size=1424, class=0
Apr 9 11:59:52  host1  AA06436:  to=<user1@host1>, delay=00:00:02, stat=Sent
Apr 9 12:43:52  host1  AA06441:  from=<user2@host2>, size=2077, class=0
Apr 9 12:43:53  host1  AA06441:  to=<user1@host1>, delay=00:00:01, stat=Sent
```

Burada her mesaj için gönderen, boyut, alıcı, gecikme ve teslim durumu kaydedilir.

(c) Kullanıcıların çalıştırdığı komutların kronolojik listesini gösteren kullanıcı logu:

```text
rcp      user1  ttyp0  0.02 secs  Fri Apr 8 16:02
ls       user1  ttyp0  0.14 secs  Fri Apr 8 16:01
clear    user1  ttyp0  0.05 secs  Fri Apr 8 16:01
rpcinfo  user1  ttyp0  0.20 secs  Fri Apr 8 16:01
nroff    user2  ttyp2  0.75 secs  Fri Apr 8 16:00
sh       user2  ttyp2  0.02 secs  Fri Apr 8 16:00
mv       user2  ttyp2  0.02 secs  Fri Apr 8 16:00
sh       user2  ttyp2  0.03 secs  Fri Apr 8 16:00
col      user2  ttyp2  0.09 secs  Fri Apr 8 16:00
man      user2  ttyp2  0.14 secs  Fri Apr 8 15:57
```

Bu logda hangi kullanıcının, hangi terminalden, hangi saatte hangi komutu çalıştırdığı görülür: dosya kopyalanmış (`rcp`), listelenmiş, ekran temizlenmiş, dosya taşınmış (`mv`), kılavuz sayfasına bakılmış (`man`). Hoca bunları tipik log dosyaları olarak tanıttı.

### 7.2 Fiziksel erişim denetim izleri

Denetim izi yalnız mantıksal sistemlerle sınırlı değildir. Bir ekipmana fiziksel erişimle ilgili izler, fiziksel erişimi kontrol eden ekipman tarafından üretilir: kartlı anahtar sistemleri ve alarm sistemleri gibi. Bir binaya, kampüse ya da kısıtlı bir alana girildiğinde bu sistemler kayıt üretir. Bu kayıtlar, gerekli alarmlar, analiz ve depolama için merkezi bir bilgisayara gönderilmelidir. Kaydedilmesi gerekenler:

- Erişim girişiminin tarihi, saati, konumu ve kullanıcısı
- Yalnız geçerli erişimler değil, geçersiz (kabul edilmeyen) erişim girişimleri de
- Fiziksel ayrıcalıklardaki değişiklikler: örneğin bir odaya girme yetkisi. Önceki derste alanlar ziyaretçi alanı, kısıtlı alan ve girilmez alan diye gruplandırılmıştı; bu yetkilerdeki değişiklikler de kaydedilir.
- Fiziksel erişimde ihlal olduğunda ilgili personele gönderilen mesajlar

## 8. Denetim verisinin depolanması (RFC 2196)

RFC 2196 (Site Güvenliği El Kitabı) denetim verilerinin nerede saklanacağına dair üç seçenek tanımlar. Hoca bunları avantaj ve dezavantajlarıyla karşılaştırdı:

- Ana bilgisayarda okuma/yazma dosyası: kolaydır, en az kaynak gerektirir ve anında erişim sağlar. Ancak saldırganlara açıktır: makineye erişen kişi orada tutulan log kayıtlarına ve denetim izlerine de erişebilir. Daha önce kayıtların silinmeye ve kurcalanmaya karşı korunan bir yerde tutulması gerektiği söylenmişti; en kolay yer burasıdır ama en korunaklı yer değildir.
- Bir kez yazılıp çok kez okunan aygıtlar (CD-ROM, DVD-ROM): daha güvenlidir ama daha az kullanışlıdır. Kayıt fiziksel olarak o makinede değildir; incelemek için ortamın takılıp yüklenmesi gerekir. Hızı sabit diskin hızına ulaşmaz. Sürekli bir kayıt ortamı tedarik etmek gerekir ve erişimler gecikebilir, kayıtlar hemen kullanılamayabilir.
- Salt yazılır aygıtlar (satır yazıcı): loglar kâğıda basılır. Büyük ağlarda ve bağlantı sistemlerinde ayrıntılı denetimi yakalamak için pratik değildir; kâğıt üzerindeki kayıtları takip etmek ve kontrol etmek zordur. Buna karşın kalıcı bir delil oluşturur ve log gerektiğinde elde basılı olarak hazırdır.

Hangi yöntem seçilirse seçilsin denetim verisi değiştirilmemeli, silinmemeli, yetkisiz kişilerce okunmamalı ve gizliliği korunmalıdır. Bunun için kayıtlar şifrelenebilir, dijital imza kullanılabilir ve erişim kontrolleri uygulanabilir.

## 9. Loglama işlevinin uygulanması: Windows ve Unix

### 9.1 Genel ilke

Slayttaki maddeler (ekrandan, 00:40:00):

- Güvenlik denetim tesisinin temeli, denetim verilerinin ilk elde edilmesidir.
- Yazılım, önceden seçilmiş olaylar meydana geldikçe veri toplamayı ve depolamayı tetikleyen kancalar (yakalama noktaları) içermelidir.
- Yazılımın doğasına bağlıdır: işletim sistemine ve ilgili uygulamalara bağlı olarak değişir.

Hoca ilk maddeyi şöyle açıkladı: veri yoksa güvenlik denetimi yapmak mümkün değildir. Yazılımda böyle bir kanca mekanizması yoksa loglama gerçekleştirilemez.

### 9.2 Windows olay logu

Windows tarafında loglama, Windows olay logu (Event Log) ile yapılır. Slayttaki tanım (ekrandan, 00:45:00):

- Olay, bazı ilginç olayları tanımlayan bir varlıktır. İçerir:
  - Sayısal bir tanımlama kodu
  - Bir dizi özellik
  - İsteğe bağlı kullanıcı tarafından sağlanan veriler
- Üç tür olay logu vardır:
  - Sistem: sistemle ilgili uygulamalar ve sürücüler
  - Uygulama: kullanıcı düzeyinde uygulamalar
  - Güvenlik: Windows YSA

Hoca her log kaydının kendine ait benzersiz bir sayısal tanımlama kodu olduğunu vurguladı.

> **Ek bilgi (derste anlatılmadı):** Slayttaki "Windows YSA" büyük olasılıkla "Yerel Güvenlik Yetkilisi"nin (Local Security Authority, LSA) kısaltmasıdır. LSA, Windows'ta yerel güvenlik politikasını uygulayan ve oturum açmaları doğrulayan bileşendir; güvenlik logunu bu bileşen yazar.

Windows olay şemasının öğeleri derste bir liste olarak okundu. Sayılanlar arasında şunlar vardı: ikili veri içeren bir olayın özellik değerleri, Windows olay günlüğünün sağladığı ikili veriler, olayın yayınlandığı kanal, olay sağlayıcının sağladığı parametreler, hata ayıklama olaylarında kullanılan bileşen adı, olayın meydana geldiği bilgisayar, ilişkili olayları bulmak için kullanılabilecek iki adet 128 bitlik değer, olay verisi işlenirken hataya neden olan öğenin adı, görevi tanımlayan sembolik değerler, olayın meydana geldiği zamana ilişkin bilgi ve hata ayıklama olaylarında kullanılan kullanıcı ve çekirdek zamanlayıcıları ile sürüm bilgileri. <!-- BELİRSİZ: şema öğeleri tablosunun slaytı karelerde yok; öğe adları Whisper metninden toparlandı -->

Ardından örnek bir Windows olay logu kaydı gösterildi. Kayıtta olay tipi "Success Audit", kaynak "Security", kategori, olay kimliği, zaman, kullanıcı ve bilgisayar alanları vardı; açıklamada olay logunun temizlendiği yazıyordu. <!-- BELİRSİZ: örnek kaydın slaytı karelerde yok; altyazıda olay kimliği "512" ve kategori "1" diye geçiyor -->

> **Ders sonrası not:** Hoca örnek kaydın olay kimliğini 512 diye okudu. Eski Windows sürümlerinde (Windows 2000/XP/2003) "denetim logu temizlendi" olayının kimliği büyük olasılıkla 517'dir; 512 ise sistemin başlatılmasına karşılık gelir. Slayt karelerde olmadığı için hangisinin yazdığı doğrulanamadı.

Windows olay kategorileri şöyle sayıldı: hesap oturum açma olayları, hesap yönetimi, dizin hizmeti erişimi, oturum açma olayları, nesne erişimi, politika değişiklikleri ve ayrıcalık kullanımı.

### 9.3 Unix loglama mekanizmaları

Unix'in genel amaçlı loglama mekanizması bütün Unix sistemlerinde bulunur ve şu bileşenlerden oluşur:

- `syslog()`: Unix'te birkaç standart sistem yardımcı programının başvurduğu ve uygulama programlarının da kullanabildiği bir API'dir.
- `logger`: sistem günlüğüne tek satırlık girişler eklemek için kullanılan komuttur.
- `/etc/syslog.conf`: sistem günlüğü olaylarının kaydedilmesini ve yönlendirilmesini kontrol eden yapılandırma dosyasıdır.
- `syslogd`: günlük olaylarını alıp kaydeden sistem cinidir (daemon), yani arka planda çalışan bir süreçtir. Yapılandırma dosyasındaki ayarlara göre ilgili olayları kaydeder.

Hoca bir uygulamanın içinden log yazmak gerektiğinde `syslog()` çağrısının kullanıldığını, komut satırından ise `logger` ile satır eklendiğini belirtti.

## 10. Syslog servisi ve protokolü

### 10.1 Syslog servisi

Syslog servisinin sunduğu imkânlar slaytta şöyle verildi (ekrandan, 00:50:00):

- Temel servisler:
  - İlgili olayları yakalamanın bir yolu
  - Bir depolama imkânı
  - Sistem logu mesajlarını diğer makinelerden, sistem log sunucusu olarak işlev gören merkezi bir makineye iletmek için bir protokol
- Ekstra eklenti özellikleri:
  - Sağlam filtreleme
  - Log analizi
  - Olay yanıtı
  - Alternatif mesaj formatları
  - Log dosyası şifreleme
  - Veritabanı depolama
  - Oran sınırlaması

Hoca eklentileri açtı: olay yanıtı alarm üretmek ya da sıralı bazı olayları tetiklemek demektir. Veritabanında depolama, logların PostgreSQL gibi bir veritabanına kaydedilmesidir. Oran sınırlaması ise belli bir miktarın üzerindeki logun sınırlanması ya da eski kayıtların üzerine yazılması gibi düzenlemeleri kapsar.

### 10.2 Syslog protokolü

Slayttaki maddeler (ekrandan, 01:10:00):

- Ana bilgisayarların sistem log sunucularına IP olay bildirim mesajları göndermesine izin veren bir aktarım:
  - Çok genel bir mesaj formatı sağlar.
  - İşlemlerin ve uygulamaların loga kaydedilen olayları için uygun kuralları kullanmasına izin verir.
- Syslog protokolünün ortak versiyonu ilk olarak University of California Berkeley Software Distribution (BSD) UNIX/TCP/IP sistem uygulamalarında geliştirilmiştir.
- BSD syslog formatındaki mesajlar şunlardan oluşur:
  - PRI: tesisler/önem derecesi kodu
  - Başlık: zaman damgası ve ana bilgisayar adı/IP adresi
  - Mesaj: programın adı ve içeriği

Hoca başlığın, logun üretildiği bilgisayarın adını ve IP adresini taşıdığını, mesaj kısmının ise loglanan olayla ilgili kaydedilen içerik olduğunu söyledi. Ardından tarih, sunucu ve açıklamadan oluşan örnek bir syslog mesajı gösterildi. <!-- BELİRSİZ: örnek syslog mesajının slaytı karelerde yok -->

### 10.3 Syslog tesisleri ve önem düzeyleri

Son olarak syslog tesisleri (facility) ve önem düzeyleri bir tabloyla verildi. Altyazıdan çıkarılabilen tesisler: `kern` (sistem çekirdeği), `user` (kullanıcı süreçleri), `mail` (e-posta), `daemon` (sistem cinleri), `auth` (kimlik doğrulama programları; `login` ve `getty` gibi), `syslog`, `lpr` (yazıcı sistemi), `news`, zamanlanmış görevler, `ftp` ve `ntp`. Önem düzeylerinden en üsttekiler olarak "emergency" ve "alert" anıldı. <!-- BELİRSİZ: tesis ve önem düzeyi tablosu karelerde yok; altyazıda "NIVS", "Clock" gibi bozuk adlar var -->

> **Ek bilgi (derste anlatılmadı):** Syslog'da (RFC 5424) sekiz önem düzeyi vardır: 0 emergency, 1 alert, 2 critical, 3 error, 4 warning, 5 notice, 6 informational, 7 debug. PRI değeri büyük olasılıkla tesis kodunun 8 ile çarpılıp önem düzeyine eklenmesiyle hesaplanır.

## 11. Uygulama düzeyi loglama

### 11.1 Ayrıcalıklı uygulamaların riski

Buraya kadar işletim sistemi düzeyindeki loglar (Windows ve Unix) anlatıldı. Uygulama düzeyinde özellikle ayrıcalıklı uygulamalar önemlidir. Bu uygulamalar güvenlik sorunu yaratır: bir zafiyet nedeniyle sorun çıktığında, uygulama ayrıcalıklı olduğu için saldırgan uygulamanın yetkileriyle sistemde işlem yapabilir. Bu davranış, uygulama ayrıcalıklı çalıştığı için sistem düzeyindeki denetim verileriyle yakalanmayabilir. Ayrıca bildirilen güvenlik açıklarının büyük bir kısmı uygulama düzeyindeki zayıflıklardır.

Saldırganların kullandığı açıklar çoğunlukla girdi verilerinin dinamik olarak denetlenmemesinden kaynaklanır: SQL enjeksiyonu ya da arabellek taşması (buffer overflow) gibi. Denetlenmeyen girdiyle sisteme hata yaptırılır ve bu hata üzerinden uygulamanın ayrıcalıkları kullanılarak sisteme erişilir. Bu tür davranışı yakalamak için dosya sistemi erişiminin ötesinde, uygulama düzeyinde denetim verisi gerekebilir.

Uygulama düzeyinde denetim verisi toplamanın iki yaklaşımı vardır: araya yerleştirilebilir kütüphaneler ve dinamik ikili yeniden yazma.

### 11.2 Araya yerleştirilebilir kütüphaneler

Bu yaklaşım, sistem kütüphanelerini veya uygulamayı yeniden derlemeye gerek kalmadan denetim verisi oluşturulmasına izin verir; denetim verisi sistem değiştirilmeden üretilir. Paylaşılan kütüphaneler sayesinde yürütülebilir dosyanın kaynak koduna erişmeden de uygulanabilir.

Statik bağlantılı kütüphanelerde kütüphane kodunun ayrı bir kopyası programın içine yüklenir. Dinamik (paylaşılan) bağlantılı kütüphanelerde ise kütüphane fonksiyonu çalışma anında programın sanal belleğine yüklenir. Araya yerleştirmede, uygulama programının çağırdığı kütüphane fonksiyonunun önüne, paylaşılan bellek alanına aynı adlı bir fonksiyon yerleştirilir; çağrı bu kanca üzerinden geçerken veri alınır ve log kaydedilir. Derste bu yapı önce normal kütüphane çağrısı, sonra araya giren fonksiyonlu çağrı olarak bir şemayla, ardından araya yerleştirilen loglama fonksiyonunun ve içinde kullanılan makronun örnek koduyla gösterildi. Hoca bu kancaların belli eylemlerde log almak için kullanıldığını söyledi. <!-- BELİRSİZ: şema ve örnek fonksiyon kodu karelerde yok; kod nota alınamadı -->

> **Ek bilgi (derste anlatılmadı):** Linux'ta bu teknik büyük olasılıkla `LD_PRELOAD` ortam değişkeniyle uygulanır. Önceden yüklenen kütüphanedeki aynı adlı fonksiyon (örneğin `open`) önce çağrılır, log yazar ve `dlsym(RTLD_NEXT, ...)` ile asıl kütüphane fonksiyonunu çağırır.

### 11.3 Dinamik ikili yeniden yazma

Slayttaki maddeler (ekrandan, 01:15:00):

- Hem statik hem de dinamik olarak bağlantılı programlarla kullanılabilir.
- Derleme sonrası yürütülebilir dosyaların ikili kodunu doğrudan değiştiren tekniktir:
  - Değişiklik yükleme sırasında yapılır ve bir programın yalnızca bellek görüntüsünü değiştirir.
  - Uygulama ikili dosyasının yeniden derlenmesini gerektirmez.
- Linux'ta iki modül kullanılarak uygulanmıştır:
  - Yüklenebilir çekirdek modülü
  - İzleme cini (daemon)
- Yüklenebilir modüller talep üzerine otomatik olarak yüklenebilir ve boşaltılabilir.

Hoca özetle, kodun çekirdek tarafından yüklenirken izlendiğini ve olayların bu yolla loga kaydedildiğini anlattı.

## 12. Denetim izi analizi

### 12.1 Analizin hazırlanması

Denetim izlerinin analizinde analiz programları ve prosedürleri büyük rol oynar; bunlar ortama göre değişir. Analiz, log girişlerinin bağlamının anlaşılmasını gerektirir. İlgili bilgi; aynı logdaki diğer girişlerle, diğer loglarla ve log olmayan kaynaklarla korelasyondan bulunabilir. Denetim dosyası biçimleri düz metin ve kodların karışımıdır; bu yüzden elle ya da otomatik olarak çözülmeleri gerekir. Temel durumu (olağan işleyişi) anlamak için girişlerin ideal olarak düzenli biçimde gözden geçirilmesi gerekir.

### 12.2 Analizin zamanlaması

Denetim izi analizi farklı zamanlarda yapılabilir:

- Bir olaydan sonra denetim izinin incelenmesi
- Denetim izi verilerinin periyodik olarak gözden geçirilmesi
- Gerçek zamanlı denetim analizi: izinsiz giriş tespit işlevinin bir parçası olarak, akış sırasında yapılır.

### 12.3 Denetim incelemesi

İnceleme özelliği, yöneticiye denetim kayıtlarını seçme imkânı verir. Şunlar incelenebilir: bir veya daha fazla kullanıcının eylemleri, belirli bir nesne veya kaynak üzerindeki eylemler, denetlenen istisnaların tümü veya belirli bir grubu, belirli bir sistem ya da güvenlik özelliğine ilişkin eylemler. Kayıtlar zamana, kaynağa ve sıklığa göre filtrelenebilir. Bu incelemeler sistem etkinliğinin temel çizgisini (olağan profilini) oluşturmak için de kullanılabilir.

### 12.4 Analiz yaklaşımları

Derste dört yaklaşım sayıldı:

- Basit uyarı: ilginç türde bir olayın gerçekleştiğini bildirmekten ibarettir.
- Temel çizgi (baselining) ve eşikleme: değişikliği tespit etmek için olaylar normal kalıplarla karşılaştırılır; kalıp içindekiler normal, dışındakiler anormal sayılır. Eşiklemede belirli bir temel değeri aşan veriler tanımlanır ve analiz edilir.
- Pencereleme: olayları çevreleyen parametreler (örneğin belirli bir zaman aralığı) tanımlanır ve bu sınırlar içindeki olaylar değerlendirilir. <!-- BELİRSİZ: yaklaşımın adı altyazıda geçmiyor; yalnız "olayları çevre tanımlayan parametreler" ifadesi var -->
- Korelasyon: en karmaşık yaklaşımdır. Birbirinden bağımsız görünen olaylar arasındaki ilişkiler bulunarak güvenlik analizi yapılır.

## 13. SIEM sistemleri

Son konu güvenlik bilgileri ve olay yönetimi (SIEM) sistemleriydi. Slayttaki maddeler (ekrandan, 01:20:00):

- Yazılım, syslog'a benzer, ancak ondan çok daha karmaşık, merkezi bir günlük kaydı yazılım paketidir.
- Merkezi, tek tip bir denetim izi depolama tesisi ve bir dizi denetim verisi analiz programı sağlar.
- İki genel yapılandırma yaklaşımı vardır:
  - Aracısız: SIEM sunucusu, günlük üreten ana bilgisayarlardan, bu ana bilgisayarlara herhangi bir özel yazılım yüklenmesine gerek kalmadan veri alır.
  - Aracı tabanlı: belirli bir günlük türü için olay filtreleme ve toplama ve günlük normalleştirmesi yapmak ve ardından normalleştirilmiş günlük verilerini genellikle gerçek zamanlı veya neredeyse gerçek zamanlı olarak bir SIEM sunucusuna iletmek için günlük üreten ana bilgisayara bir ajan programı kurulur.

Hoca farkı şöyle özetledi: aracısız yapılandırmada sunucuya yalnız ham veriler toplanır. Aracı tabanlı yapılandırmada ise log üreten sunucuda bir ajan çalışır ve verileri belirli bir biçime, filtrelemeye ve mekanizmaya göre işleyip SIEM sunucusuna gönderir.

SIEM yazılımı farklı kaynaklardan gelen farklı log biçimlerini tanıyabilir ve bunlara yenileri tanımlanıp entegre edilebilir. Yazılım bu çeşitli günlük girişlerini normalleştirir; böylece bütün girişlerde aynı veri öğesi için aynı biçim kullanılır. Log girişlerini silebilir. SIEM sunucusu çoklu log kaynaklarından gelen birleştirilmiş verileri analiz eder, log girişleri arasındaki olayları ilişkilendirir, önemli olayları tanımlar ve öncelik sırasına koyar, istenirse olaylara yanıt mekanizmasını başlatabilir. Hoca SIEM'i bu nedenle oldukça yetenekli bir yazılım olarak niteledi. <!-- BELİRSİZ: 01:20:54-01:21:20 arasında altyazı boş; SIEM'in log biçimlerini tanıma kısmı eksik olabilir -->

## Dersin Toparlaması

Bu derste güvenliğin bir kez kurulup bırakılan bir yapı olmadığı, kontrollerin işleyişinin sürekli denetlenmesi gerektiği anlatıldı. RFC 4949'a göre güvenlik denetimi kayıtların ve faaliyetlerin bağımsız incelenmesi, denetim izi ise olayları yeniden kurmaya yeten kronolojik kayıttır. X.816 denetim ve alarm modeli ile dağıtık model, Ortak Kriterler'in önerdiği olay listesi, olay tespitinin gereksinimleri (uygun kancalar, kurcalamaya dayanıklı depolama, en az performans etkisi), uygulama yönergesi, X.816 ve ISO 27002'nin denetlenebilir öğeleri ve örnek denetim izleri incelendi. RFC 2196'ya göre denetim verisinin nerede ve nasıl korunarak saklanacağı tartışıldı.

Dersin ikinci yarısında loglamanın pratiği ele alındı: Windows olay logu ve kategorileri, Unix'te `syslog()`, `logger`, `syslog.conf` ve `syslogd`, syslog servisinin özellikleri ve BSD syslog mesaj biçimi. Ayrıcalıklı uygulamaların riski nedeniyle uygulama düzeyinde loglama için araya yerleştirilebilir kütüphaneler ve dinamik ikili yeniden yazma teknikleri anlatıldı. Son olarak denetim izlerinin analiz zamanlaması ve yaklaşımları (basit uyarı, temel çizgi ve eşik, pencereleme, korelasyon) ile bütün bu işlevleri merkezileştiren SIEM sistemleri tanıtıldı. Böylece güvenlik denetimi konusu bu derste tamamlandı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
