# Ders 5 Genişletilmiş Notu: DEMOS'ta Görevler Arası Haberleşme ve DEMOS/MP'de Proses Göçü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Biçimi ve Okunan İki Makale
- 2. DEMOS'ta Task ve Mesaj Tabanlı Haberleşme
- 3. Görev Haberleşmesinin Üç İşlevi
- 4. Cray-1'de Bellek Koruması ve Mesaj Tabanlı Tasarım
- 5. Linkler: Türleri ve Yönleri
- 6. Resource Link: Dosya Açma Örneği
- 7. Link Yönetimi, Deadlock ve Zaman Aşımı
- 8. Bypass Linkleri
- 9. DEMOS/MP'de Proses Göçü: Amaçlar ve Adımlar
- 10. Proses Göçünde Durum ve Mesaj İletme
- 11. Gevşek Bağlı ve Sıkı Bağlı Sistemler
- 12. Göç Kararı ve Günümüzdeki Alternatifler
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Biçimi ve Okunan İki Makale

Bu ders de önceki haftalar gibi öğrencilerin önceden okuduğu makalelerin soru-cevap biçiminde tartışılmasıyla geçti. Bu hafta iki makale vardı: biri DEMOS işletim sisteminde görevler arası haberleşme (task communication), diğeri DEMOS/MP'de proses göçü (process migration). Hoca önce DEMOS makalesiyle başladı, aradan sonra DEMOS/MP makalesine geçti. Kayıt boyunca ekranda slayt ya da makale paylaşılmadı; aşağıdaki bütün bilgiler sözlü anlatımdan ve hocanın makaleden sesli okuduğu cümlelerden alınmıştır. Hoca ayrıca makaleyi okurken bir öğrenciye "sakin sakin, yavaş yavaş" anlatmasını, önce sorulan soruya cevap vermesini ve makalenin sınırları dışına çıkmamasını öğütledi; makale tartışmasında sıranın ve kapsamın korunmasını önemsedi.

> **Ek bilgi (derste anlatılmadı):** Derste makalelerin tam adı ve yazarları söylenmedi. Anlatılan içerik büyük olasılıkla şu iki makaleye karşılık gelir: F. Baskett, J. H. Howard ve J. T. Montague'nin 1977'de SOSP'ta yayımlanan "Task Communication in DEMOS" makalesi ve M. L. Powell ile B. P. Miller'ın 1983'te SOSP'ta yayımlanan "Process Migration in DEMOS/MP" makalesi. Hocanın andığı ACM kitapçığındaki 110-116 sayfa aralığı da büyük olasılıkla ikinci makalenin bildiri kitapçığındaki yeridir.

## 2. DEMOS'ta Task ve Mesaj Tabanlı Haberleşme

Söz alan bir öğrenci makalenin bir proseslerarası haberleşme (interprocess communication) sistemi tanıttığını ve bu sistemin tabanında mesaj aktarımının (message passing) olduğunu söyledi. Makale giriş bölümünde bazı tanımlar verir. Bunlardan biri "task"tır: yazarlar proses yerine task (görev) terimini kullandıklarını, çünkü bunun daha iyi oturduğunu söyler. Öğrencinin benzetmesiyle görevler yapılır, yeri gelince durdurulur, rafa kaldırılır, sonra raftan indirilir. İkinci makalede ise yazarlar artık "process migration" der; hocaya göre task ve proses birbirinin yerine kullanılabilir.

### 2.1 Sistem çağrılarının adı: "messages"

Hoca, görevlerin haberleşmesine yönelik kullanılan sistem çağrılarına bu makalede özel bir ad verildiğini hatırlattı ve bu adı sordu. Cevap "messages" (mesajlar) oldu. Hocanın açıklamasına göre bunlar aslında bilinen standart sistem çağrılarıdır: dosya açmak, dosyaya yazmak, ekrana yazmak, bir görevin işlemciyi bırakması gibi. Haberleşmeyi gerçekleştirdikleri için topluca bu adı alırlar.

### 2.2 Link: mesajların yolu

Görevlerin birbiriyle haberleşebilmesi için bir bağlantıya, yani linke ihtiyaç vardır. Link, görevler arasında mesajların gidip gelmesini sağlayan bir yol olarak görülmelidir. Hoca linkin nerede başlayıp nerede bittiğini sordu. Makaledeki örnek üzerinden cevap şudur: tipik yapıda link kullanıcı tarafındaki görevde başlar, çekirdekte (kernel) biter.

Hoca bunun neden böyle olduğuna dair bir örnek istedi. Bir öğrenci konsola yazma örneğini verdi: konsol, her prosesin erişebildiği ortak bir arayüzdür. Oraya kimin ne zaman yazacağını yönetmek gerekir ve bu kullanıcı alanında (user space) yapılamaz. Çekirdek alanına inip sistem çağrılarıyla konsolun boşta olup olmadığına, göreve ayrılıp ayrılamayacağına karar verilir. Demek ki tipik olarak bir görevden çekirdeğe link olması gerekir.

## 3. Görev Haberleşmesinin Üç İşlev

Makale, görevin başka bir görevle haberleşebilmesi için sağlanması gereken üç işlevden söz eder. Hoca burada bir düzeltme yaptı: bunlar görevin gerçekleştirdiği bütün işlevler değil, haberleşme için gereken işlevlerdir; bir görev başka birçok işlev de gerçekleştirebilir.

### 3.1 Birinci işlev: standart linkler

Birinci işlev, görevin mesajlaşma yoluyla sistem çağrılarını yapabilmesidir. Bunun için görev oluşturulurken ona varsayılan olarak bazı linkler verilir. Bir öğrenci bunu, bir proses oluşturulduğunda ona verilen varsayılan dosya tanımlayıcılarına (standart girdi, standart çıktı, standart hata) benzetti; ekrana bir şey yazmak isteyen proses standart çıktıya yazar. Hoca bu benzetmeyi onayladı ve makalenin dosya sistemine erişim için sıradan (ordinary) standart linkler verilebileceğini söylediğini ekledi. Bu linkler, görevin özel olarak istemesine gerek kalmadan, görev oluştuğunda ona tahsis edilmesi gereken linklerdir. Bu link büyük olasılıkla çekirdekteki, sistem tarafından sağlanan bir servise (örneğin dosya G/Ç'sine) gider; dosya G/Ç'si konsola yazmayı ve konsoldan okumayı da kapsar.

### 3.2 İkinci işlev: karşılıklı rızayla haberleşme ve switchboard

İkinci işlev, bir öğrencinin makaleden aktardığı cümleyle, keyfi ve ilgisiz görevlerin (arbitrary and unrelated tasks) karşılıklı rızayla (mutual consent) iletişim kurabilmesidir. Yani başlangıçta birbirinden haberi olmayan iki görev ortak anlaşmayla haberleşebilmelidir. Bunun için aralarında bir yapı gerekir: makalede buna switchboard denir.

Hoca switchboard'u eski tip telefon santralleriyle açıkladı. Santralde bir operatör vardır. Arayan taraf operatörü arar ve belli bir numarayla görüşmek istediğini söyler. Operatör o numarayı kendisi arar ve "şu numara sizinle görüşmek istiyor, kabul ediyor musunuz?" diye sorar. Karşı taraf kabul ederse operatör iki hattı bir kabloyla birbirine bağlar ve aradan çekilir. Birbirinden haberi olmayan iki tarafın karşılıklı rızayla bağlanması budur. Hocaya göre bu, ilk santral memurlarının yaptığı işin bilgisayar ortamında görevler arası haberleşmeye birebir yansıtılmış halidir. Bu işi yapan özel göreve switchboard task denir.

Mekanizma şöyle işler. Nasıl dosya sistemine standart linkler varsa, görev oluşturulduğunda switchboard görevine de standart bir link verilir; görevin bunun için bir şey yapmasına gerek yoktur. Bir görev bu link üzerinden hangi görevle konuşmak istediğini bildirir. Karşı görevin de switchboard'a standart olarak oluşturulmuş bir linki vardır; switchboard bunu kullanarak karşı görevin haberleşmek isteyip istemediğini ve buna hazır olup olmadığını öğrenir. Şartlar iki taraf için de sağlanıyorsa istenen haberleşme için ek linklerin oluşturulmasını ve birleştirilmesini, yani bir yol kurulmasını sağlar. Böylece switchboard gibi servislere giden standart linkler veri aktarmak için değil, kontrol bilgisi aktarmak ve yeni bağlantı kurmak için kullanılır.

Hoca bu işlevin ne sağladığını sordu. Olayın tamamı zaten proseslerarası haberleşmedir; buradaki anahtar kelime esnekliktir (flexible). Makale, var olan linkler üzerinden görevlerin keyfi ve ilgisiz görevlerle konuşabilmesini, onlarla aralarında link oluşturulabilmesini sağlayan bir mekanizma ortaya atar. Hocanın makaleden okuduğu ifade şudur: "passing links along with messages over existing links". Var olan linkler üzerinden yeni link bilgisi, hatta ilk başlangıç mesajı aktarılabilir. Bir öğrenci de bunu şöyle yorumladı: büyük veriyi mesajın içinde göndermek mesajın boyutunu artırır; bunun yerine mesajla bir link gönderilir ve "benimle bu link üzerinden konuş" denir.

### 3.3 Üçüncü işlev: görev sarma, debugging ve monitoring

Üçüncü işlev, bir öğrencinin çevirisiyle bir görevin başka bir görevi ya da görev grubunu kapsayabilmesidir (sarabilmesidir). Hoca bunun hangi imkânı sağladığını sordu; cevap hata ayıklama (debugging) ve performans izleme (monitoring) oldu. Hocaya göre bu işleve instrumentation ya da mediation denir.

Bir öğrenci bu haberleşmenin debugging ile ilişkisinin dolaylı olduğunu, "mesaj atarak izlemek" gibi bir düşünce olduğunu söyledi. Hoca şöyle açıkladı: iki görev aralarında haberleşerek bir amaç için çalışıyor ama düzgün çalışmıyor olsun. Bunu debug edebilmek için araya girip alınan ve verilen mesajları, yani istek (request) olarak giden mesajların ve onlara cevap (response) olarak oluşturulan mesajların içeriğini inceleyebilmek gerekir. Demek ki bir görevi başka bir görevin gözetiminde ve kontrolünde, "çalıştır, durdur" yaklaşımıyla adım adım çalıştırabilmek gerekir. Böylece hatanın gönderilen istekte mi yoksa karşı taraftan gelen cevapta mı olduğu anlaşılabilir.

**Soru:** Bu, ağdaki Wireshark gibi gelen gideni görmeye yönelik bir işlev midir?

**Cevap:** Wireshark bunu bir prosesi kendi kontrolü altında çalıştırarak yapmaz. Ağ kartlarının bu işe yönelik özelliklerinden yararlanarak gelen ve giden paketleri yakalar (capture). Ağ kartı bunu desteklemiyorsa giden paket karta yazılmadan önce, gelen paket de ilgili yere aktarılmadan önce bir yere kopyalanabilir. Bu yazılım gerçekleştirmesidir; kartın desteğiyle yapılan donanım gerçekleştirmesi daha performanslıdır.

## 4. Cray-1'de Bellek Koruması ve Mesaj Tabanlı Tasarım

Bir öğrenci makaledeki ilgili paragrafı aktardı: makalede kullanılan Cray-1 sisteminde yalnız bir base ve bir limit yazmacı vardır. Bu yazmaçlar bir adresin prosese ait bellek bölgesinde olup olmadığını denetler ve prosesin başka bir prosesin belleğine girmesini engeller. Tek bir yazmaç çifti zayıf bir korumadır. Makaleye göre görevlerin birbirinin belleğine erişmediği ve yalnız mesajlaşmayla haberleştiği bir tasarım, belleğin zaten çok iyi korunamadığı böyle bir sisteme uygundur.

### 4.1 Base ve limit yazmaçlarının çalışması

Hoca base ve limit yazmaçlarının ne işe yaradığını sordu. Bir öğrenci bu yazmaçların programın erişebileceği bellek alanını belirlediğini, programın her bellek erişiminde işlemcinin bunu denetlediğini ve izin verilen alanın dışına çıkılırsa bir hata oluşturduğunu söyledi. Hoca bunu teknik terimlerle şöyle toparladı: görevden çıkan adres, o görev için belirlenmiş base + limit değeriyle karşılaştırılır. Çıkan adres base + limit'ten büyükse görevin kendisine izin verilen adres alanı dışına eriştiğine karar verilir ve bir kesme (interrupt) oluşur. Erişim donanım seviyesinde engellenir.

> **Ek bilgi (derste anlatılmadı):** Yaygın tanımda limit yazmacı bölgenin uzunluğunu tutar ve geçerli bir adres için $\text{base} \le \text{adres} < \text{base} + \text{limit}$ koşulu aranır. Koşul sağlanmazsa işlemci işletim sistemine bir tuzak (trap) üretir.

### 4.2 Koruma neyi sağlar, neyi ortadan kaldırır?

Bu mekanizmanın neyi sağladığı sorusuna bir öğrenci diğer görevleri koruduğunu, örneğin başka bir programın kod segmentine yanlışlıkla yazılmasını engellediğini söyledi. Hoca bunun bütünlük mü yoksa gizlilik mi olduğunu sordu; cevap ikisi birden oldu: hem bütünlük (integrity) hem gizlilik (privacy) korunur.

Hoca bir adım daha genelleştirdi: bu yöntem katı (strict) biçimde uygulanırsa global bellek erişimi ortadan kalkar. Çünkü her görevin yalnız kendine ayrılmış belleği olduğu varsayılır ve bu base + limit ile net biçimde belirlenir. Bunun doğal sonucu olarak global değişkenlere erişim söz konusu olamaz. Böyle bir yapı, paylaşılan değişkenlerle (shared variable) programlamaya standart olarak izin vermeyen, bilginin yalnız mesajların alınıp verilmesiyle paylaşıldığı bir yapıdır ve dağıtık işlemenin (distributed processing) temelini oluşturur. Hocanın gerekçesi: her bilgisayar sisteminin erişebildiği ortak bir veri alanı olduğunu varsaymak absürt olur; sistemler birbirine çok farklı biçimlerde bağlanmış olabilir.

### 4.3 Paylaşılan veri alanları

Yine de global değişkenlerin tamamen elenemediği durumlar olabilir; o zaman veri alanlarının paylaşılması gerekir. Bir öğrenci makalenin bu durumda linkler üzerinden veri alanlarının adreslerinin (pointer'ların) aktarılmasına izin verdiğini, ayrıca ileride ebeveyn prosesin çocuk prosesin yazmaçlarına müdahale edebildiğini ve oluşturma sırasında link üzerinden onun veri segmentinin adresini aldığını aktardı. Hoca bunu programlama dillerindeki argüman aktarımına benzetti: bir fonksiyona argüman değer olarak ya da referans (adres) olarak aktarılabilir. Burada da linkler üzerinden paylaşılabilen veri alanlarının adresleri aktarılır. Bu, yalnız mesajlaşmanın uygun olmadığı ya da yetersiz kaldığı, doğrudan veri paylaşımının gerektiği senaryolar için düşünülmüştür.

Hoca, böyle bir mekanizmada aşılması gereken sorunu sordu. Bir öğrenci, makalede yazmadığını belirterek, ortak bir alana erişen iki görevin aynı anda yazmaması, birinin diğerinin yazmasının bitmesini beklemesi gerektiğini, yani senkronizasyon ve kritik bölge (critical section) sorunları çıkabileceğini söyledi. Hoca makaleden şu cümleleri okudu:

> "The only part of the operating system that needs hardware access to the memory of more than one task at a time is the kernel, that part of the system which is used to move both messages and data from one task to another. The two types of communication are unified in the link concept."

Yani hem mesajlara hem paylaşılan alanlara erişimi olması gereken tek yer çekirdektir. Yazarların iddiası, çekirdek erişirse diğer taraflarda bir şey yapmaya gerek kalmayacağıdır. Mesaj ve veri aktarımı link kavramında birleştirilir. Makale bunun nasıl yapıldığına dair örnekler de verir.

## 5. Linkler: Türleri ve Yönleri

Hoca linklerin tanımını ve özelliklerini anlatacak birini istedi. Bir öğrenci aldığı notlardan şunları aktardı: makale dört link türünden söz eder: request, resource, reply ve general. Reply linkleri yalnız bir kez kullanılabilir; bir isteğin cevabı olarak oluştukları ve iş bittiği için kullanımdan sonra yok edilirler. Genel (general) linkler iki görev arasında haberleşme için kullanılabilir. Request linkleri isteklerin gönderildiği linklerdir.

Başka bir öğrenci önemli bir özelliği ekledi: linkler tek yönlüdür (one way, simplex). Aynı link üzerinden iki yönlü alıp verme yapılamaz; iki görev karşılıklı haberleşecekse iki link gerekir. Hoca iki link bir araya geldiğinde ne olduğunu sordu. Biri bir yönde, biri öbür yönde olan iki link bir araya geldiğinde full duplex haberleşme sağlanır ve aslında bir kanal (channel) oluşturulmuş olur.

> **Ders sonrası not:** Tartışmada hoca tek link için "half duplex" dedi. Tek yönlü bir link simplex'tir; half duplex iki yönlü ama aynı anda yalnız tek yönlü iletim demektir. Doğrusu: tek link simplex, ters yönlü iki link birlikte full duplex bir kanaldır.

Bir öğrenci de makaleden şu ayrıntıları okudu: bir link çoğaltılabilir (duplicate) ya da yok edilebilir (destroy), başka bir göreve verilebilir; bunun için linkin oluşturucusunun o görev olması gerekir. Linkin denetimi aslında onu oluşturan görevde değil, çekirdektedir.

## 6. Resource Link: Dosya Açma Örneği

Hoca özellikle resource linkin ne olduğunu sordu. Bir öğrenci, makalenin "Link Usage" bölümünün altında, "Link Management" bölümünden önce bir örnek bulunduğunu hatırlattı ("To open the file, task A performs a call operation..." diye başlayan paragraf). Öğrencinin ilk yorumuna göre görev A dosya sistemine bir istek gönderir, birkaç request ve reply ile kontroller yapılır, her şey uygunsa görev A'dan dosya sistemine bir resource link oluşur ve dosya bu link üzerinden okunur. Başka bir öğrenci de makalede sistemdeki açık kaynakların sayacını tutmak için, link her oluşturulduğunda ya da yok edildiğinde asıl linkin sahibine bir mesaj gittiğinin yazdığını aktardı.

Hoca önce arada neyin olması gerektiğini vurguladı: çekirdek. Her şey çekirdek üzerinden yönetilir. Ortak alana erişimi ve mesajlaşmayı birleştirmek için, donanım kısıtları da düşünülerek, her zaman her yere erişimi olabilecek tek yerin çekirdek olduğu varsayılır. O zaman linklerin oluşturulmasında, yok edilmesinde ve kullanılmasında da çekirdeğin etkin olması gerekir. Ardından örneği makaleden adım adım okudu:

1. Görev A, dosyayı açmak için bir "call" işlemi yapar. Bunu, görev oluşturulurken verilen dosya sistemine giden standart request linki üzerinden, dosya adını ve gerekli diğer parametreleri (örneğin salt okuma mı, okuma-yazma mı) içeren bir mesaj göndererek yapar.
2. Çekirdek, standart reply kanalını belirten bir reply linki oluşturur ve mesajla birlikte bu reply linkini dosya sistemine gönderir. Yani isteğin cevabının döneceği ayrı bir link oluşturulur.
3. Dosya sistemi mesajı alınca yorumlar, X dosyasını açar ve sırası gelince kendisine bir resource link oluşturur ("creates a resource link to itself"). Resource linkin kod alanında, dosya sisteminin açık dosya tablosunda X'in girdisine ait iç indis bulunur.
4. Dosya sistemi, görev A'nın gönderdiği reply linki üzerinden bir "reply" işlemi yapar ve X'i temsil eden resource linki bu reply linki üzerinden görev A'ya geri aktarır.
5. Tamamlanma mesajı ve resource linkin kimliği görev A'ya döner; görev A örtük receive işlemi sayesinde hazır (ready) hale gelir. Reply linki kullanıldıktan sonra çekirdek tarafından yok edilir.
6. Sonuçta görev A'nın dosya sistemine iki linki vardır: standart request linki ve X dosyasını temsil eden resource link. Dosya sisteminin görev A'ya hiç linki yoktur.

Hoca reply linkinin neden dosya sistemine gönderildiğini sordu. Cevap: dosya sisteminin link oluşturmasına gerek kalmasın diye. Dosya sistemi kodu yalnız dosyalara erişir, okur, yazar, siler, günceller. Aradaki çekirdek ise hem isteklerin gönderilmesi hem de cevapların ilgili göreve dönebilmesi için linklerin oluşturulmasından sorumludur. Böylece link yönetimi çekirdekte bırakılır, kullanıcı alanındaki görevlerden çıkarılır ve merkezi olarak yönetilir. Merkezi yönetim sayesinde ortak veriye erişimde de "yalnız çekirdeğin her yere erişimi olsun, her şey onun üzerinden yapılsın" diyen birleşik mekanizma sağlanmış olur.

Hoca "resource" kelimesinin anlamına da dikkat çekti: kaynak. İşletim sistemi kaynakları yönetir; dosya sistemi ve onda açılan dosyalar (nesneler) de birer kaynaktır. Dosya sistemi açılan dosyanın çetelesini tutabilmek, dosya işaretçisinin nerede olduğunu, dosyanın kapatılıp kapatılmadığını, yazılıp yazılmadığını, hata oluşup oluşmadığını bilebilmek için bu iç linki oluşturur.

> **Ders sonrası not:** Hoca toparlarken bir yerde dosyanın "kernel tarafından açıldığını" söyledi. Okuduğu makale paragrafına göre X dosyasını dosya sistemi açar; çekirdek yalnız reply linkini oluşturur ve linklerin aktarılmasını yönetir.

### 6.1 Resource linkin özeti

Hoca bir cümlelik özet istedi. Bir öğrenci "görev ile kaynak arasındaki bağlantıyı sağlayıp aradan çekiliyor" dedi. Hocanın tanımı şudur: resource link, kaynağa ihtiyaç duyan, isteği gönderen görevin aradaki yapıya tekrar tekrar istek gönderip onun üzerinden erişmesine gerek kalmadan kaynağa doğrudan erişmesini sağlayan linktir. Kaynaklara merkezi bir noktadan denetimli erişim gerekir; örneğin bir dosyayı bir görev açtıysa belki diğerinin açmaması gerekir (karşılıklı dışlama, mutual exclusion). Ama erişim bir kez verildikten sonra gereksiz bürokrasi ortadan kalkar: her seferinde istek dosya sistemine, oradan aygıt sürücüsü üzerinden dosyaya, cevap tekrar dosya sistemine ve göreve gitmez; aradaki ek mesajlaşma trafiği kalkar.

**Soru:** Örneğin yüz satırlık bir metin dosyasında 50. satırı, sonra 51. satırı okumak için her seferinde ayrı istek atmamak için mi?

**Cevap:** Aradaki dosya sistemine gerek kalmıyor; dosya sisteminin gidecek ve dönecek her şeyi üzerinden geçirmesine gerek kalmıyor.

Hoca yine santral benzetmesine döndü: eski santralde memur, kulaktan kulağa oynar gibi "şunu karşı tarafa söyle", "karşı taraf ne dedi?" diye arada mesaj taşımaz; beş numarayla yedi numarayı birbirine bağladıktan sonra aradan çekilir. Resource link bunun için vardır.

## 7. Link Yönetimi, Deadlock ve Zaman Aşımı

Hoca link yönetiminin (link management) ne yaptığını sordu. Bir öğrenci şöyle açıkladı: elde birden çok link vardır ve bunların bir kısmı ölmüş olabilir; gösterdikleri görevler sonlanmış, başarılı biçimde bitmiş ya da öldürülmüş olabilir. Bu linklerin yönetilmesi ve sistemde her zaman çalışan linklerin bulunması gerekir. Makale, yok edilmiş görevleri gösteren linklerin kullanılmamasını sağlamak için standart teknikler bulunduğunu, kullanımdan kaldırmayı standart yöntem olarak belirtir. Başka bir öğrenci linklere bayraklarla koruma konabildiğini ekledi: linkin çoğaltılmaması, belli bir biçimde kullanılmaması gibi; isteyen görev linkin çoğaltılıp çoğaltılmadığını, kopyalanıp kopyalanmadığını izleyebilmelidir.

### 7.1 Ölü göreve bağlı link ve döngüsel bekleme

Bir öğrenci link yönetiminde deadlock oluşabileceğini söyledi: ölmüş bir göreve bir linkle bağlıyızdır, ona bir istek göndeririz, cevap gelmez ve onu bekleriz; burada döngüsel bekleme (circular wait) olur. Hoca bunun gerçekten döngüsel bekleme olup olmadığını sordu. Öğrenci kendini düzeltti: bu döngüsel bekleme değil, bir sonsuz beklemedir. Hoca bu senaryonun döngüsel beklemeye dönüşüp dönüşemeyeceğini sordu. Cevap: tek başına dönüşmez; ama bekleyen göreve başka bir görev, ona da bir başkası bağlıysa ve o da ilk kaynağı bekliyorsa döngüsel bekleme oluşur.

### 7.2 Zaman aşımı

Bu durumları yönetmek için makalenin önerdiği çok basit ama etkili yöntem zaman aşımıdır (timeout): belli bir sürede olmuyorsa olmuyordur. Hoca zaman aşımını "İsviçre çakısı" gibi bir şey olarak niteledi ve günlük hayattan bir benzetme yaptı: biriyle buluşmaya gidersiniz, gelmiyorsa bir süre beklersiniz, sonra gelmediğine karar verip yolunuza devam edersiniz. Bazen zaman aşımı da işe yaramayabilir; çok kritik bir iş için cevap gelmezse iş yarım kalır.

> **Hocanın vurgusu:** Zaman aşımı bu senaryoda deadlock oluşmasını engellemek için kullanılabilecek bir mekanizmadır, ama işin düzgün yapılıp yapılmadığının garantisini vermez. İş hatalı da olabilir, düzgün tamamlanmış da. Buradaki hedef işi yapmak değil, sonsuz bekleme durumundan çıkabilmektir.

Hoca bu makalenin çok kısa olduğunu, referanslarıyla birlikte on sayfayı bile bulmadığını hatırlattı.

## 8. Bypass Linkleri

Hoca son olarak bypass linklerini sordu. Bir öğrenci bunun proses taşıma ile ilgili olduğunu düşündü; hoca "burada göç (migration) yaptık mı?" diye sorarak öğrencinin söylediğinden ne kadar emin olduğunu sınadı. Başka bir öğrenci bunun debugging bölümünde geçtiğini hatırlattı: debugger araya girip mesajı okur ama veri yoluna karışmaz; mesaj kanalını kopyalar, veri için bypass olarak ayrı bir link verir.

Hoca neden "bypass" dendiğini sordu. Büyük veri aktarılacağı zaman bu veri izleme (monitoring) görevi üzerinden geçerse çok fazla gecikme olur ve çok fazla işlem gücü harcanır. İşi hızlandırmak için veri kısmı izleyici üzerinden geçirilmez, izleyici atlanır; bu ayrı bağlantıya bypass link denir.

## 9. DEMOS/MP'de Proses Göçü: Amaçlar ve Adımlar

Aradan sonra hoca ikinci makaleye, DEMOS/MP'de proses göçüne geçti. Bir öğrenci giriş yaptı: makale proseslerin göçünden, yani işlemciler arasında transfer edilmesinden söz eder. Proses durdurulur, başka bir işlemciye aktarılır, sonra orada kaldığı yerden devam eder. Makalenin ana konusu, bunun doğru biçimde nasıl yapıldığıdır; yazarlar diğer işletim sistemlerinde bu işin zor olduğunu, kendilerinin bunu uygun biçimde yaptıklarını söyler.

### 9.1 Göçün amaçları

Öğrencilerin aktardığı amaçlar şunlardır:

- **Yük dengeleme:** Bir işlemcinin yükü %90, diğerininki %30 gibiyse, yükleri birbirine yaklaştırmak için yükü fazla olan işlemcideki bir proses diğerine taşınır.
- **Kaynağa yakınlık:** Bir prosesin bir kaynağa erişimi başka bir işlemcide daha kısa olacaksa proses oraya taşınır. Yerel olmayan kaynaklara erişimde haberleşme maliyeti azalır, sistem performansı iyileşir.
- **Hata toleransı:** Bir işlemci hatası tespit edildiğinde ya da öngörüldüğünde, prosesi kaybetmemek için başka bir işlemciye geçirilir.

### 9.2 Göçün sekiz adımı

Hoca göç sırasında neler yapılması gerektiğini sordu. Bir öğrenci makalenin bunu sekiz adımla tanımladığını söyledi ve başlıklardan şu sırayı aktardı (aradaki program aktarımı adımını hocanın "biraz atlamış olabilir misin?" uyarısıyla ekledi):

1. Proses yürütmeden çıkarılır (durdurulur); "in migration" olarak işaretlenir.
2. Hedef işlemcinin çekirdeğine prosesi alıp alamayacağı sorulur.
3. Hedef çekirdek gelecek proses için bir durum (state) yapısı ayırır.
4. Proses durumu aktarılır.
5. Program aktarılır: kod, veri ve yığın (stack).
6. Transfer sırasında gelen ve bekleyen mesajlar yeni konuma iletilir (forward).
7. Kaynak işlemcide prosesten kalan durum temizlenir; geride bir iletme adresi (forwarding address) bırakılır.
8. Proses yeni yerinde yeniden başlatılır.

Başka bir öğrenci temizleme adımındaki iletme adresinin önemini vurguladı: taşınan şey prosesin durumu ve kodudur, ama eski linkler yerinde kalır ve onlardan sonradan mesaj gelebilir. Hoca bunu şöyle açıkladı: prosesin bulunduğu işlemcide onunla link kurup haberleşen prosesler o sırada belki mesaj göndermiyor, bir şey bekliyordu. Bu proseslerin prosesin başka bir sisteme gönderildiğinden haberi yoktur. Linkler yeni sisteme yönlendirilmezse gönderdikleri mesajlar havada kalır ve bu prosesler çalışamaz hale gelir.

Hoca makalenin, bir önceki makaledeki DEMOS yapısının üzerine kurulduğunu, bu yüzden link ve switchboard yapısının olduğu gibi kabul edildiğini belirtti; makaledeki bir şekilde switchboard'un da göründüğünü hatırlattı.

### 9.3 Makaledeki şekil: üç işlemcili örnek

Hoca makaledeki bir şekilde ne görüldüğünü sordu. Bir öğrencinin aktarımıyla şekilde ağ üzerinden haberleşen üç-dört işlemciden oluşan dağıtık bir sistem vardır; birinde switchboard, birinde process manager ve memory scheduler bulunur; en sağdaki sistem ise dosya sisteminin proseslerini içerir, yani bir dosya sunucusuna denk düşer. Hocanın yorumuna göre burada bir işlevsel ayrışma vardır: biri dosya isteklerini (açma, kapama, okuma, yazma) yürüten G/Ç yoğun işler için, diğeri hesaplama yoğun (compute intensive) işler için özelleşmiştir. Bir öğrenci makalenin, dosya sistemine ait proseslerin hepsinin aynı işlemcide çalışmak zorunda olmadığını, farklı makinelerde de olabileceğini söylediğini ekledi.

<!-- BELİRSİZ: Makaledeki şekil ekranda paylaşılmadı; şeklin numarası ve hangi işlemcide hangi bileşenin bulunduğu yalnız sözlü anlatımdan aktarılmıştır. -->

Hoca buradan bir örnek kurdu: en soldaki makinede dosya yoğun çalışan bir görev oluşturulmuş olsun. Onu orada çalıştırmaya devam etmek mantıklı değildir; dosya sunucusunun bulunduğu makineye taşınmalıdır. Hesaplama yoğun bir görev ise işlemcisi daha güçlü ya da o anda daha boş olan makineye taşınmalıdır. Kısacası prosesler ihtiyaç duydukları kaynaklara yakın işlemcilere taşınmalıdır.

### 9.4 Akademiden günlük hayata

Hoca burada sanallaştırma ortamlarına (VMware, Hyper-V) dikkat çekti: bu ortamlarda yapılan göç işlemlerinin tamamen bu makalede anlatılan mantık üzerine kurulu olduğunu söyledi. Makalenin tarihi sorulduğunda referanslarda 1977 tarihli bir çalışma olduğu, makalenin ise 1983 tarihli olduğu belirlendi; yani makale dersin yapıldığı 2023'ten kırk yıl öncesine aittir. Hocaya göre o gün yalnız akademik görünen bir çalışma seneler sonra ticari bir ürünün merkezine yerleşip bilgisayar mühendisliği açısından günlük hayatın bir parçası olabilir.

> **Ek bilgi (derste anlatılmadı):** VMware'in vMotion gibi özellikleri tek tek prosesleri değil, bütün sanal makineleri çalışırken bir fiziksel sunucudan diğerine taşır (live migration). Durumu askıya alıp aktarma, hedefte yeniden başlatma ve bağlantıları yeni konuma yönlendirme fikri bakımından bu makaledeki proses göçüyle büyük olasılıkla aynı temele dayanır.

### 9.5 Elektrik kesintisi ve high availability

Bir öğrenci göçün çözdüğü bir sorunu öne sürdü: bir prosesin çalıştığı işlemcide bir kaynak ya da işlemcinin kendisi bozulursa, hatta elektrik kesilirse, sistem cevap veremez hale gelir; göçle yüksek erişilebilirlik (high availability) sağlanabilir. Hoca makalenin sınırları içinde kalınmasını isteyerek sordu: bu makalede tariflenen yöntemle elektriği kesilen bir sunucudaki proses göç ettirilebilir mi? Cevap: edilemez.

Başka bir öğrenci makalenin bu konuda söylediğini aktardı: proses durumu bir dosya sistemine kaydedilirse, bozulan işlemcinin çalıştırdığı proses başka bir işlemciye taşınıp kayıtlı durumdan devam edebilir. Hoca bunu onayladı: işlemcide çalışan hali değil, belleğe en son yazılmış durumu alınıp çalıştırmaya devam edilebilir; diğer donanım onarılana kadar başka bir işlemci aynı işi görmeye devam eder. Bu, prosesin durumunun replikasyonu demektir. Kod değişmez, salt okunur kabul edilebilir ve bütün sunucuların erişebileceği bir yerdedir. Durum ise belirli aralıklarla, bir checkpointing mantığıyla, diğerlerinin erişebileceği bir yere yazılmalıdır.

## 10. Proses Göçünde Durum ve Mesaj İletme

Bir öğrenci makalenin yazıldığı dönemde proses durumunun birçok tabloda tutulan dağıtık verilerden oluştuğunu ve bunun taşımayı zorlaştırdığını aktardı. Hoca örnek verdi: dosya sistemi tablosu ayrı, semafor tablosu ayrı, bellek ayırma tablosu ayrıdır; her birinden ilgili bilgiyi almak gerekir.

### 10.1 Makalenin sonucu

Hoca bunun en sevdiği makalelerden biri olduğunu, çünkü günlük hayatta doğrudan karşılığının görüldüğünü söyledi ve makalenin sonuç cümlelerini okudu:

> "Process migration has proven to be a reasonable facility to implement in a communication based distributed operating system. Less than one person month of time was required to implement and test the mechanism in the current version of DEMOS/MP."

Haberleşme ve dağıtık bir yapı varsa göç anlamlıdır; bugünkü internet yapısında bir proses on binlerce kilometre öteye bile hızlıca gönderilebilir. Gerçekleme ve test bir kişi-aydan kısa sürmüştür.

Hocaya göre yapılan iş aslında çok fazla değildir: proses askıya alınır, prosesle ilgili tabloların tamamı karşıya gönderilir, karşıda kod yüklenip çalıştırılır. Bu, yeni bir proses başlatmanın adımlarına çok benzer. İşletim sistemi yeni bir proses başlatırken bir proses bloğu oluşturur, prosesi proses tablosuna işler, bellek ayırır, diskten kodu ve statik veriyi yükler. Göçte kod yine diskten yüklenir, ama statik veri diskten değil, diğer sistemdeki en son halinden alınır. Yani yeni bir proses üretmekle göç ettirmek hemen hemen eşdeğerdir; tek ince iş link meselesini düzgün çözmektir.

### 10.2 "In migration" durumu: askıya alma mı?

Bir öğrenci hocanın "suspend ediliyor" ifadesine itiraz etti: makaleye göre proses yalnız run queue'dan çıkarılıyor, durumunda bir değişiklik yapılmıyor. Öğrenci makalenin 115. sayfasında, birinci adımda "The process is marked in migration" yazdığını gösterdi. Hoca önce askıya almanın ne olduğunu açıkladı: suspend, prosesin çalıştırılabilir (runnable) olmaktan çıkarılması, bir bekleme kuyruğuna (wait queue) alınması demektir. Run queue'dan çıkarılan bir proses zaten çalışmaz. Dosya sistemi G/Ç'si yaparken de, başka bir prosese mesaj gönderip cevabını beklerken de proses run queue'dan çıkarılır; bunlar klasik bekleme senaryolarıdır. Bu anlamda run queue'dan çıkarmak otomatik olarak askıya almak demektir.

Hoca prosesin durumunun ne zaman değişebileceğini de açıkladı: proses çalışırken, ya da bir mesaj veya olay beklerken o mesaj veya olay geldiğinde. Bunun dışında durum değişmez. Run queue'dan çıkarılan proses instruction çalıştırmayacağı için durumunu kendisi değiştiremez. Geriye ona gelecek mesajlar ve olaylar kalır; bunları da çekirdek üstlenir ve yeni konuma iletir.

Tartışmanın sonunda konu şöyle netleşti. Hazır (ready) durumundaki bir proses çalıştırılmaya adaydır; zamanlayıcının (scheduler) taşınmakta olan prosesi run queue'ya koymaması gerekir. Bunun için özel olarak "in migration" adlı ayrı bir durum oluşturulur. Prosesin kayıtlı running, ready ya da suspended durumu ise korunur, çünkü proses hedef sistemde kaldığı yerden devam etmelidir. Hoca bunun nedenini şöyle açıkladı: çalışmakta (running) olan bir prosesi askıya almak için değil, göç ettirmek için durdurduysak, onu karşıda askıda başlatmak haksızlık olur; birebir durum korunmamış olur. Böylece klasik beş durumlu zamanlayıcı modelindeki durumların dışında özel bir durum tanımlanmış olur. Hedefte kod yüklenip statik veri aktarıldıktan ve proses çalışmaya hazır hale geldikten sonra proses "in migration" durumundan çıkarılır ve en son kaldığı durum neyse ona döner. Bundan önce mesajların da oraya iletilmesi sağlanmış olmalıdır.

> **Hocanın vurgusu:** Yerel sistemde prosese gelen mesajların ve linklerin diğer tarafa iletilebilmesi kritiktir.

### 10.3 Seri topolojide iletme

Hoca makalenin 116. sayfasındaki duruma da değindi: sistemler arka arkaya bağlı (seri) bir topolojide düşünülürse ve proses bir sistemden diğerine, oradan bir sonrakine gidiyorsa, aradaki işlemcilerin mesajları iletebilmesi gerekir. Örneğin ortadaki işlemci 2 için, işlemci A'nın mesajlarını ileten bir "dummy" yapı varmış gibi düşünülebilir.

<!-- BELİRSİZ: 116. sayfadaki şekil ekranda gösterilmedi; işlemcilerin adlandırılması (işlemci 2, işlemci A) altyazıdan olduğu gibi aktarılmıştır. -->

## 11. Gevşek Bağlı ve Sıkı Bağlı Sistemler

**Soru:** Bu makale dağıtık sistemlerde proses göçünü anlatıyor; ilk makaledeki görevler de dağıtık bir sistemde mi, yoksa aynı sistem içinde miydi?

**Cevap:** DEMOS ile DEMOS/MP arasındaki fark "MP"nin çok işlemcili (multiprocessor) anlamına gelmesidir. DEMOS tek bir işlemcide, tek bir kapalı yapıda çalışır. DEMOS/MP ise birden fazla işlemciden oluşur ve bunlar arasında gevşek bağlı (loosely coupled) bir yapı vardır, sıkı bağlı (tightly coupled) değil.

Öğrenci gevşek bağlıyı, herhangi bir anda bir düğümün kopup yeniden bağlanabildiği ya da yeni bir cihazın eklenebildiği bir yapı olarak anladığını söyledi. Hoca bunu düzeltti. Sıkı bağlı yapıda belleğe doğrudan erişmek için kullanılan adres yolu, veri yolu ve kontrol yolu (okuma, yazma, bekleme gibi sinyaller) fiziksel olarak bir araya gelir ve bir önceliklendirme ya da paylaşım donanımıyla çözülür; arada fiziksel, elektronik bir bağlantı ağı (interconnection network) vardır. Gevşek bağlı yapıda ise işlemciler aynı fiziksel yol üzerinde bulunmaz, aralarında daha üst seviye haberleşme protokolleri vardır. Ağ Ethernet, eskiden kullanılan token ring ya da token bus olabilir; bakır, fiber optik ya da kablosuz olabilir; üst seviye protokol olarak bugün TCP/IP'de toplanmıştır. Zaman içinde Digital'in DECnet'i, IBM'in SNA'sı gibi farklı protokoller oluşmuş, birleşe birleşe bugün TCP/IP olmuştur.

> **Hocanın vurgusu:** Gevşek bağlı, belleğin fiziksel olarak paylaşılmadığı demektir. Bir işlemci bir belleğe doğrudan adres yolu, veri yolu ve kontrol yolu ile erişemiyorsa gevşek bağlı, erişebiliyorsa sıkı bağlıdır.

Hoca iki yaklaşımın bedelini de karşılaştırdı. Sıkı bağlı yapıda 8, 16, 32, 64 işlemciyi yönetecek, hepsinin birbirinden etkilenmeden, yeterli bant genişliğiyle aynı belleğe aynı anda erişmesini sağlayacak donanım ve bellek mimarisi çok ciddi bir maliyet demektir. Bu yapılamaz değildir; 64 ya da 128 fiziksel çekirdekli (iş parçacığı değil, fiziksel çekirdek) sistemler vardır, ama bir bedeli vardır. Gevşek bağlı yapıda ise ağın getirdiği bir gecikme vardır; bu gecikmeyi en aza indirmek için farklı bağlantı ve paylaşım yöntemleri, yıldız (star), halka (ring) ya da yol (bus) topolojileri kullanılır. Günümüzde fiziksel olarak çoğunlukla yıldız topolojisi kullanılır, ama mantıksal olarak makaledeki gibi arka arkaya bağlı sıralı bir halka ya da herkesin herkesle konuşabildiği bir örgü (mesh) yapısı kurulabilir.

## 12. Göç Kararı ve Günümüzdeki Alternatifler

Bir öğrenci makalenin çözülmesi gereken konulardan söz ettiğini aktardı: verimli ve etkili bir taşıma kararı mekanizması, makalenin yazıldığı dönemde hâlâ bir araştırma konusuydu. Hoca bugün bu konuda neler yapıldığına da bakmanın ilginç olacağını söyledi. Öğrenci proses yük dengeleme (load balancing) algoritmaları üzerine çalışmaların sürdüğünü ekledi. Hoca bugün yük dengelemenin çok yaygın yapıldığını, ters vekil sunucuların (reverse proxy) ve yük dengeleyicilerin buna örnek olduğunu belirtti.

Hoca proses göçüne alternatifin ne olduğunu sordu. "Statik atama" (yük dengelemeden işi doğrudan bir işlemciye vermek) cevabından sonra asıl alternatif ortaya çıktı: aynı prosesin birden çok replikasını hazır tutmak ve gelen istekleri bunlara yönlendirmek. Mevcut sistemlerin çoğu böyle çalışır ve bunu yapmak daha kolaydır. Ama bunun için uygulamaların durumsuz (stateless) olması ya da durum bilgisinin ortak bir yerde, örneğin Redis ya da memcached gibi bellek içi bir önbellekte, hızlı erişilebilir biçimde tutulması gerekir. Bu durumda aynı prosesin $n$ tane kopyası vardır; birinin başına bir şey gelirse diğeri en son kalan durumdan devam eder, prosesi taşımakla uğraşılmaz.

Hoca iki yaklaşımı karşılaştırdı: replika yönteminde aynı anda daha fazla kaynağı ayakta, çalışır durumda tutmak gerekir; göçte ise kaynak ihtiyaca bağlı kullanılır. Günümüzde ikisi de kullanılır; biri diğerini ortadan kaldırmaz, birbirini tamamlar.

Son olarak bir öğrenci makalenin deneysel sonuçlarından söz etti: bir işlemciden diğerine taşıma bir yeniden yerleştirmedir (relocation), kaynakların yeniden ayrılması gerektiği için zaman alır; ama genel olarak sistem performansını artırmak, yükü olabildiğince eşit dağıtmak ve paralelleştirme sağlamak için iyi bir fırsattır.

## Örnek Sorular

Kayıtta ekranda soru ya da slayt gösterilmedi; aşağıdaki sorular hocanın derste sözlü sorduğu sorulardır.

**Soru 1** (derste sözlü, 00:16:35): DEMOS makalesinde görevlerin haberleşmesine yönelik kullanılan sistem çağrılarına topluca hangi ad verilmiştir? Neden?

> **Cevap (derste verildi):** "Messages" (mesajlar). Bunlar dosya açma, yazma, ekrana yazma gibi bilinen sistem çağrılarıdır; haberleşmeyi gerçekleştirdikleri için bu adı alırlar.

**Soru 2** (derste sözlü, 00:18:23 ve 00:19:04): Tipik bir link nerede başlar, nerede biter? Bunun gerekliliğine bir örnek veriniz.

> **Cevap (derste verildi):** Kullanıcı tarafındaki görevde başlar, çekirdekte biter. Örnek: konsol bütün proseslerin eriştiği ortak bir arayüzdür; kimin ne zaman yazacağı kullanıcı alanında yönetilemez, çekirdekte sistem çağrılarıyla yönetilir.

**Soru 3** (derste sözlü, 00:22:21 ve 00:23:45): Görev haberleşmesi için gereken ikinci işlev nedir ve bunun için iki görev arasında hangi yapıya ihtiyaç vardır?

> **Cevap (derste verildi):** Birbirinden habersiz (arbitrary and unrelated) iki görevin karşılıklı rızayla (mutual consent) haberleşebilmesi. Bunun için eski telefon santralindeki operatör gibi çalışan switchboard görevine ihtiyaç vardır; iki görevin switchboard'a standart linkleri vardır, switchboard karşı tarafın rızasını alır ve yeni linkleri kurar.

**Soru 4** (derste sözlü, 00:30:36 ve 00:30:57): Üçüncü işlev, yani bir görevin başka bir görevi sarabilmesi hangi imkânı sağlar?

> **Cevap (derste verildi):** Hata ayıklama (debugging) ve izleme (monitoring). Bir görev başka bir görevin kontrolünde adım adım çalıştırılıp aradaki istek ve cevap mesajları incelenebilir. Bu işleve instrumentation ya da mediation denir.

**Soru 5** (derste sözlü, 00:36:07 ve 00:37:52): Base ve limit yazmaçları nasıl çalışır ve böyle bir koruma neyi sağlar? Katı uygulanırsa neyi ortadan kaldırır?

> **Cevap (derste verildi):** Görevden çıkan adres o görevin base + limit değeriyle karşılaştırılır; dışarıdaysa kesme oluşur ve erişim donanımda engellenir. Bu, görevlerin hem bütünlüğünü hem gizliliğini korur. Katı uygulanırsa global (paylaşılan) değişken erişimi ortadan kalkar; bilgi yalnız mesajlarla paylaşılır. Bu da dağıtık işlemenin temelidir.

**Soru 6** (derste sözlü, 00:55:27): Dosya açma örneğinde çekirdek neden oluşturduğu reply linkini dosya sistemine gönderir?

> **Cevap (derste verildi):** Dosya sisteminin link oluşturmasına gerek kalmasın diye. Dosya sistemi yalnız dosya işlemleriyle uğraşır; link oluşturma ve yok etme çekirdekte merkezi olarak yönetilir.

**Soru 7** (derste sözlü, 01:01:07): Resource linki bir cümleyle özetleyiniz.

> **Cevap (derste verildi):** Kaynağa ihtiyaç duyan görevin, aradaki yapıya (örneğin dosya sistemine) tekrar tekrar istek göndermeden kaynağa doğrudan erişmesini sağlayan linktir. Erişim bir kez denetimli biçimde verildikten sonra gereksiz mesaj trafiği ortadan kalkar.

**Soru 8** (derste sözlü, 01:07:27 ve 01:07:45): Ölmüş bir göreve istek gönderip cevap beklemek döngüsel bekleme (circular wait) midir? Döngüsel beklemeye dönüşebilir mi?

> **Cevap (derste verildi):** Tek başına döngüsel bekleme değil, sonsuz beklemedir. Bekleyen göreve başka bir görev, ona da bir başkası bağlıysa ve zincir ilk kaynağa geri dönüyorsa döngüsel bekleme oluşur. Makalenin önerdiği çözüm zaman aşımıdır; zaman aşımı işin doğru yapıldığını garanti etmez.

**Soru 9** (derste sözlü, 01:11:47): Bypass linklerine neden bu ad verilmiştir?

> **Cevap (derste verildi):** İzleme yapan bir görev araya girdiğinde, büyük veri izleyici üzerinden aktarılırsa çok gecikme ve işlem yükü olur. Veri kısmı izleyiciyi atlayan (bypass eden) ayrı bir link üzerinden aktarılır.

**Soru 10** (derste sözlü, 01:35:19): DEMOS/MP makalesinde tariflenen yöntemle elektriği kesilen bir sunucudaki proses göç ettirilebilir mi?

> **Cevap (derste verildi):** Hayır. Bunun için proses durumunun belirli aralıklarla (checkpointing) diğer sistemlerin erişebileceği bir yere yazılması, yani durumun replikasyonu gerekir; o zaman son kaydedilen durumdan başka bir işlemcide devam edilebilir.

**Soru 11** (derste sözlü, 01:57:35 ve 01:59:50): Gevşek bağlı (loosely coupled) ve sıkı bağlı (tightly coupled) sistemler arasındaki fark nedir?

> **Cevap (derste verildi):** Sıkı bağlı sistemde işlemciler belleğe doğrudan adres, veri ve kontrol yolları üzerinden erişir. Gevşek bağlı sistemde bellek fiziksel olarak paylaşılmaz; işlemciler TCP/IP gibi üst seviye protokollerle bir ağ üzerinden haberleşir.

**Soru 12** (derste sözlü, 02:03:12): Proses göçünün (ya da yük dengelemenin) günümüzdeki alternatifi nedir ve bunun için ne gerekir?

> **Cevap (derste verildi):** Aynı prosesin hazır replikalarını çalıştırıp gelen istekleri bunlara yönlendirmek. Bunun için uygulama durumsuz (stateless) olmalı ya da durum ortak, hızlı erişilebilir bir yerde (Redis, memcached gibi) tutulmalıdır. Bedeli, aynı anda daha fazla kaynağı çalışır durumda tutmaktır.

## Dersin Toparlaması

Bu derste iki klasik makale tartışıldı. İlki DEMOS'ta görevler arası haberleşmeydi: görevler birbirinin belleğine erişmez, yalnız tek yönlü linkler üzerinden giden mesajlarla haberleşir. Görev oluşturulurken standart linkler verilir; birbirinden habersiz görevler switchboard görevi aracılığıyla karşılıklı rızayla bağlanır; bir görev başka bir görevi sararak hata ayıklama ve izleme yapabilir. Cray-1'deki zayıf base/limit korumasıyla uyumlu bu tasarımda birden fazla görevin belleğine erişen tek parça çekirdektir; mesaj ve veri aktarımı link kavramında birleşir. Request, reply, resource ve general linkler, dosya açma örneğinde görüldüğü gibi, çekirdeğin merkezi link yönetimiyle birlikte görevin kaynağa aracısız erişmesini sağlar. Ölü görevlere karşı zaman aşımı, büyük veriler için bypass linkleri kullanılır.

İkinci makale bu yapının üzerine kurulan DEMOS/MP'de proses göçüydü. Yük dengeleme, kaynağa yakınlık ve hata toleransı için proses sekiz adımda başka bir işlemciye taşınır; ayrı bir "in migration" durumu prosesin kayıtlı durumunu korur, mesajlar yeni konuma iletilir ve geride bir iletme adresi kalır. Hoca, gevşek bağlı ve sıkı bağlı sistemlerin farkını, göçün yeni bir proses başlatmaya ne kadar benzediğini ve bu fikrin bugün sanallaştırma ortamlarında, replika ve yük dengeleme yaklaşımlarıyla birlikte nasıl yaşadığını vurguladı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
