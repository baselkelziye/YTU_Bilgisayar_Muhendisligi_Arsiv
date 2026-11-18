# Ders 3 Genişletilmiş Notu: İşletim Sistemi Servisleri, Kullanıcı Arayüzleri, Sistem Çağrıları, Sistem Programları ve İşletim Sistemi Yapıları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Katmanlı Bir Bakış
- 2. İşletim Sistemi Servisleri
- 3. Komut Satırı Arayüzü (Shell)
- 4. Grafik Kullanıcı Arayüzü
- 5. Sistem Çağrıları ve API'ler
- 6. Sistem Çağrısında Parametre Geçirme
- 7. Sistem Çağrısı Türleri ve Standart C Kütüphanesi
- 8. İşletim Sistemi Örnekleri: MS-DOS ve FreeBSD
- 9. Sistem Programları
- 10. İşletim Sistemi Tasarımı ve Gerçekleştirimi
- 11. İşletim Sistemi Yapıları
- 12. İşletim Sistemi Hata Ayıklama ve Başarım Ayarı
- 13. Sistem Üretimi ve Önyükleme
- Örnek Sorular
- Dersin Toparlaması

## 1. Katmanlı Bir Bakış

Bu derste işletim sistemi yapıları ele alındı. Hoca konunun dönem boyunca görülecek birçok konunun temel kavramlarını içerdiğini söyledi: işletim sistemi servisi, sistem arayüzü, sistem çağrısı ve sistem programları. Bunları bir katmanlı mimari olarak düşünmemizi istedi: A, B, C, D katmanları ve en altta donanım. En üstte (A) kullanıcı, yani biz varız; en altta donanım vardır. Bilgisayarın kaynaklarından faydalanmak için doğrudan donanıma erişemeyiz. İşletim sistemi de tek başına tek bir katman değildir; birbiriyle haberleşen birçok katman ve servisten oluşur. Bir katman altındaki katmandan hizmet ister (request) ve bir yanıt (response) alır; A, B ile, B, C ile, C, D ile, D de donanımla etkileşir. Bu katmanlardan birine işletim sistemi servisleri, birine sistem arayüzü, birine sistem çağrıları, birine sistem programları denir.

İşletim sistemi kullanıcılara ve programlara bir ortam sağlar: donanımı verimli kullanmak ve kullanıcı programlarını koordine edip kontrol etmek için.

## 2. İşletim Sistemi Servisleri

### 2.1 Kullanıcı arayüzü

İşletim sisteminin ilk bakışta fark ettiğimiz kolaylığı bir kullanıcı arayüzüne (user interface) sahip olmasıdır. Üç tür vardır:

- **Komut satırı arayüzü (command line interface, CLI):** İlk işletim sistemlerinde işlemler komut satırından yapılırdı. Bir program çalıştırmak için komut girilir, Enter'a basılır, program çalışır ve bitince ana ekrana dönülür. Çok kullanıcılı durumlarda da komut satırı kullanılmıştır.
- **Grafik kullanıcı arayüzü (GUI):** Günümüz işletim sistemlerinde daha yaygındır.
- **Toplu işlem (batch) arayüzü:** Yapılacak işler toplu hâlde ya da bir program hâlinde girdi olarak verilir, sistem onları sırayla işler. Hoca bunun ilk dersteki insan operatöre benzediğini, o insanın da aslında bir arayüz olduğunu söyledi. Bir batch dosyası oluşturup "önce şu işi, sonra bu işi yap" diye tarif edersiniz; gereken diğer programlar da sisteme verilmelidir. Yani kullanıcıdan alınan bir tarifin arayüzüdür.

Hoca MS-DOS dönemini hatırlattı: İşletim sistemi bir disketin içindeydi; program da o diskete yüklenir, bilgisayar disketten açılır ve program komut satırından çalıştırılırdı. Bilgisayar arızalandığında başka bir disketle farklı bir işletim sistemi açılır, onunla sürücüler temizlenip biçimlendirilir ve sistem yeniden kurulurdu.

### 2.2 Program çalıştırma ve G/Ç

İşlemciyi ve belleği kullanacaksak en çok program çalıştırmayla (program execution) muhatap oluruz. Programların süreç hâline geldikten sonra belleğe alınması, işlemciye yer verilmesi, zaman zaman işlemciden çıkarılması ve G/Ç işlemleriyle birlikte çalışmasının sürdürülmesi işletim sisteminin servislerindendir. Program normal ya da anormal biçimde sonlanabilir; bunu da işletim sistemi denetler.

G/Ç ihtiyaçları için hoca geçen dersteki şemayı hatırlattı: CPU, bellek, ortadaki bus ve bus'a bağlı G/Ç aygıtları. **Soru:** Aygıtlarla bus arasındaki bu yapılara ne diyorduk? **Cevap:** Aygıt denetleyicisi (device controller). Yazıcının, monitörün her birinin kendi denetleyicisi vardır. Programın G/Ç ihtiyacı olduğunda işletim sistemi denetleyicilerle haberleşir; denetleyiciler aygıtı nasıl kullanacağını aygıt sürücüleri sayesinde bilir ve G/Ç gerçekleşir.

### 2.3 Dosya sistemi işlemleri

Dosyaların tutulduğu kalıcı bellekler, yani diskler üzerinde dosya sisteminin servisleri sağlanmalıdır. C'de dosya açıp okumak ya da dosyaya yazmak bunlara örnektir. Dosya ve klasör oluşturmak, silmek, yeniden adlandırmak ve izinleri (permissions) yönetmek dosya sistemi servisleri altındaki görevlerdir.

### 2.4 Haberleşme

Süreçler aynı bilgisayarda ya da ağdaki uzak bir bilgisayarda birbiriyle haberleşmeye ihtiyaç duyabilir; bunun denetimi ve koordinasyonu işletim sistemindedir. Hoca veritabanı dersinden bir örnek verdi. **Soru:** PostgreSQL için kullandığınız pgAdmin ne işe yarar? Sınıftan "SQL sorgusunu yazıp çalıştırıp sonucunu görüyoruz" cevabı geldi. **Cevap:** pgAdmin yalnızca veritabanını tasarlamak ya da verileri raporlamak için PostgreSQL sunucusuna ulaşan bir arayüzdür. Veritabanını o arayüzü kullanmak için tasarlamayız; bir mobil, web ya da masaüstü uygulamasında verileri kalıcı saklamak ve onlara erişmek için tasarlarız. Örneğin bir kitaplar veritabanıyla haberleşen ayrı bir web uygulamanız vardır; uygulamanın veritabanına sorgu gönderip veri alması için arada bir haberleşme mekanizması gerekir.

Bir başka örnek WhatsApp'tır: Birine mesaj gönderdiğinizde internet üzerinden bir yönlendirme olur ve mesaj o kişinin telefonunun IP adresine gider. Telefonda birçok uygulama olduğu için mesaj gelişigüzel bir uygulamaya değil WhatsApp'a gitmelidir. Bu haberleşmenin denetimi için iki genel yaklaşım vardır: **paylaşımlı bellek (shared memory)** ve **mesaj geçirme (message passing)**. Hoca bunlara "yaklaşım" demesinin nedeninin, altlarında farklı teknik ve algoritmaların geliştirilmiş olması olduğunu söyledi.

### 2.5 Hata algılama

İşletim sistemi bir gözlemci gibi sistemde hata olup olmadığını sürekli izler: süreçlerin oluşturduğu bir exception, CPU'da, G/Ç'de ya da bir kullanıcı programında meydana gelen bir sorun. Örneğin sıfıra bölme exception'ı oluştuğunda sistem kaynaklarının organizasyonu kesintiye uğramamalıdır. İşletim sistemi programı ya da G/Ç işlemini sonlandırabilir, ek önlemler alabilir ve kaynakların diğer süreçlerce kullanılmaya devam edilmesini güvenceye alır. Gerektiğinde hata ayıklama (debug) için kolaylıklar da sağlayabilir.

### 2.6 Kaynak tahsisi ve muhasebe

Donanım açısından her şey bir kaynaktır: CPU, bellek, dosya sistemi, her bir G/Ç aygıtı. Hoca yazıcı örneğini verdi: Bir belge yazdırırsınız (Ctrl+P), ardından bir tane daha. Önce hangisi çıkmalıdır? Burada bir FIFO, yani kuyruk mantığı vardır ve bunu işletim sistemi denetler. Word'den de tarayıcıdan da gönderseniz, gelen istekler bir yazma (`write`) sinyaline dönüştürülür, kuyruğa alınır ve sırayla yazıcıya gönderilir.

Kaynak tahsis edebilmek için hangi kaynağın kime verildiğinin ve hangisinin boşta olduğunun çetelesini tutmak gerekir; buna **muhasebe (accounting)** denir.

### 2.7 Koruma ve güvenlik

**Koruma (protection)**, sistem kaynaklarına erişimin güvenli olmasıdır. Bir süreç belleğin belli bir yerini kullanıyorsa başka bir süreç işletim sisteminin izni olmadan oraya erişemez. C'de `malloc` kullanmamızın nedeni budur: Bin bayt yer istediğinizde bu işletim sisteminin denetiminde alınır, muhasebe servisleri size bir yer bulur ve siz orayı kullanırken başka bir süreç kullanamaz.

**Güvenlik (security)**, kullanıcılara ait özel bilgilerin ve sistemdeki verilerin yetkisiz erişimle (invalid access) zarar görmesinin önlenmesidir. Birisi bir virüsle bilgilerinizi ele geçirmek isteyebilir; bilgisayarda birden çok kullanıcı varsa diğerleri sizin bilgilerinizi görememelidir. Hoca bilgisayar sistemleri güvenliğinin ayrı bir seçmeli dersin konusu olduğunu, kendi içinde "bambaşka bir alem" olduğunu belirtti.

### 2.8 Katmanlar arasında bir örnek: yazdırma

Katmanlı şemada en altta donanım, onunla doğrudan muhatap olan işletim sistemi ve en tepede kullanıcı ya da sistem programları vardır. İşletim sisteminin servislerini kullanmak için arayüzler gerekir. Ctrl+P'ye bastığınızda bir pencere açılır; aşağıda bir yazdırma servisi vardır, pencere ise o servisi kolay kullanmamızı sağlayan bir kullanıcı arayüzüdür. Kullanıcı arayüzü GUI, komut satırı ya da batch olabilir. Kullanıcı arayüzü aşağıdaki servisleri kullanabilmek için bir **sistem çağrısından** geçmek zorundadır. `printf` de en tepede ekrana bir şey yazdırmak için kullandığımız bir arayüzdür; bir `write` sistem çağrısıyla haberleşir, o da yazdırmayla ilgili bir işletim sistemi servisiyle haberleşir. Servis başlayınca verinin belleğe mi, ağa mı, ekrana mı, yazıcıya mı yazılacağına göre işlemler sırayla yapılır.

> **Hocanın vurgusu:** Kullanıcı programının donanıma ya da işletim sisteminin içine doğrudan erişmesi mümkün değildir. Mümkün olsaydı işletim sisteminin anlamı kalmazdı: İşlemciyi, belleği kullanıcı olarak ben ayarlamak zorunda kalırdım ("üç saniye sen işlemcide kal, sen bellekte şu kadar yer al"). Dört değişkenli bir optimizasyon problemini çözerken bile zorlanırken bunu kullanıcının yönetmesi mümkün değildir.

## 3. Komut Satırı Arayüzü (Shell)

### 3.1 Komut örnekleri

Komut satırı arayüzü sistemi doğrudan komutlarla kullanmayı sağlar. Windows'ta CMD (Komut İstemi) ve Windows 10 ile gelen PowerShell vardır. Hoca PowerShell'de MS-DOS komutlarının yanında Linux komutlarının da çalıştığını gösterdi ve arka planda Linux komutlarını Windows komutlarına dönüştüren bir yazılım olduğunu tahmin etti.

> **Ek bilgi (derste anlatılmadı):** PowerShell'de `ls`, `dir`, `pwd`, `cd` gibi adlar takma adlardır (alias); örneğin `ls` ve `dir` aynı `Get-ChildItem` komutunu çalıştırır. Bu yüzden Linux'taki parametreler ve CMD'deki `/s`, `/w` gibi anahtarlar PowerShell'de her zaman aynı biçimde çalışmaz.

Derste gösterilen komutlar:

- `cd` (change directory) ile klasör değiştirilir; `cd ..` bir üst klasöre gider.
- `dir` bulunulan klasördeki dosya ve klasörleri listeler. `dir /w` listeyi sütunlar hâlinde gösterir; `dir /s` alt klasörlerdeki bütün dosyaları da içeren ayrıntılı bir listedir. Hoca bu anahtarların PowerShell'de desteklenmediğini görünce CMD'ye geçti.
- Dosya adı kalıplarıyla arama yapılabilir; örneğin adının ikinci karakteri "s" olan dosyaları, uzantısı ne olursa olsun aramak gibi, düzenli ifadeye benzer kalıplar verilir. <!-- BELİRSİZ: Hocanın yazdığı tam kalıp altyazıdan çıkmıyor; ekrandaki komut satırı kareleri kişisel dosya listeleri içerdiği için aktarılmadı. -->
- `pwd` (present/print working directory) o anda bulunulan klasörü gösterir.
- `ping` iki nokta arasında ICMP paketleri göndererek bağlantının sağlıklı kurulup kurulmadığını, sorunun sizde mi karşıda mı olduğunu kontrol eder. Bunu yaparken işletim sisteminin ilgili servisini kullanan bir başka program çağrılır. Hocanın denemesinde bir zaman aşımı (timeout) hatası alındı.
- `gcc` ile programlar derlenir: `gcc` bir yerde duran bir programdır ve ona parametre verilir. Komut satırında `for` ve `if` içeren betikler yazmak da mümkündür.

Ctrl+C sürekli devam eden bir işi durdurur; aslında bir öldürme (kill) sinyali göndermek demektir. Sinyaller ayrıca konuşulacak.

### 3.2 `format C:` ve koruma

**Soru:** `format C:` dersem çalışır mı, bilgisayardaki işletim sistemine zarar verebilir miyim? **Cevap:** Katmanlı mimariyi unutmayalım: En altta donanım, üstünde işletim sistemi servisleri, sistem çağrıları, komut satırı arayüzü ve en üstte ben varım. Şu an muhatap olduğum şey komut satırı arayüzüdür. İşletim sisteminin görevlerinden biri koruma ve güvenliktir; koruma görevini yapmak için beni engellemesi gerekir. Nitekim komut çalıştırıldığında "erişim engellendi" (access denied) yanıtı geldi. `format` donanıma doğrudan erişip diskteki ilgili kısımları silen bir programdır; ama işletim sistemi "dur bakalım" der. Harici bir USB disk ya da sabit disk için ise (örneğin `H:`) format atılabilir.

### 3.3 Shell ve dış komutlar

Komut yorumlayıcıları zaman içinde bazı sistemlerde çekirdeğin bir parçası, günümüz sistemlerinde ise bir sistem programı olarak gerçekleştirilmiştir. Windows'taki "Donatılar" (Accessories) altında bulunan disk temizleme (disk cleanup) ve disk birleştirme (defrag) gibi araçlar da sistem programıdır. Defrag, sürekli kopyalama, kesme ve taşıma yüzünden diskte parçalanmış kısımları toparlayıp düzene sokar ve bilgisayarı kısmen hızlandırabilir.

Komut yorumlayıcılarına genellikle **shell** denir. Görevi kullanıcıdan bir komut almak, onu çalıştırmak ve çalışma sırasında üretilen çıktıyı göstermektir; buton ya da grafik arayüz yoktur, komutlar parametreleriyle yazılır. Komutların bir kısmı yerleşiktir (built-in), bir kısmı dışarıdan eklenen programlardır. Örneğin eskiden `format` yerleşik değildi, ayrı bir program olarak yüklenirdi. `fdisk` ile diskin bölümleme yapısı sıfırlanırdı: Disk yapılandırması bozulup sistem çalışmaz hâle gelince bölümleme baştan kurulur (C sürücüsüne şu kadar, D sürücüsüne bu kadar gigabayt), sonra format atılırdı. Bu tür programlar bir disketten ya da USB'den kullanılırdı.

Slaytta Mac üzerinde çalışan Bourne shell örneği vardı: Komutlar yazılmış, gereği yapılmış ve süren bir iş Ctrl+C ile kesilmişti. `ls`, Windows'taki `dir`'in karşılığıdır.

Komut satırı arayüzünün bir kısıtı aynı anda tek bir program çalıştırabilmesidir: `ls` yaptığınızda o bitmeden başka bir şey yapamazsınız.

### 3.4 Göreli ve mutlak yol

`pwd` ne işe yarar? Bir yerden çok sayıda veri okuyup üzerinde bir algoritma çalıştıracağınızı ve başka bir yere yazacağınızı düşünün. Programınızı masaüstündeki bir klasörde kurguladınız ve veriler o klasördeki "okunacaklar" klasöründe duruyor. Kod içinde verinin `C:\Users\...\Desktop\...` gibi uzun bir **mutlak yolunu (absolute path)** yazarsanız, klasörü D sürücüsüne ya da başka bir yere taşıdığınızda program çalışmaz. Bunun yerine yalnızca "bulunduğum yerdeki okunacaklar klasörü" denirse, yani **göreli yol (relative path)** kullanılırsa, program taşındığında bozulmadan çalışır. Arka planda o anki çalışma klasörü (current working directory) kullanılır.

> **Ders sonrası not:** Hoca `pwd`'nin açılımını "present working directory" diye hatırladığını, "JWD" ya da "current working directory" diye de yazıldığını söyledi. `pwd`'nin yaygın açılımı "print working directory"dir; kavramın adı ise "current working directory"dir (C'de bunu veren fonksiyon `getcwd`'dir).

## 4. Grafik Kullanıcı Arayüzü

Masaüstü arayüzü olan, simgelerle ve grafik ögelerle sağlanan daha kapsamlı arayüzlere **GUI** denir. Her programın kendi simgesi vardır, klasör ve dosya ayrı gösterilir, fareyle işlem yapılır.

Hoca GUI'nin kökenini Xerox'a bağladı ve yazıcı/fotokopi makinesi örneğiyle anlattı: Bir fotokopi makinesinde arkalı önlü basmak, bir sayfaya iki sayfa sığdırmak, A3 ya da A4'e basmak gibi her seçenek için ayrı komut yazmak gerekseydi çok zor olurdu. Çamaşır makinesindeki program düğmeleri gibi, bir grafik arayüzden dokunarak seçim yapmak bu işi kolaylaştırır.

> **Ders sonrası not:** Hoca GUI'nin Xerox yazıcılarını kullanmak için geliştirildiğini söyledi. İlk masaüstü GUI büyük olasılıkla 1970'lerde Xerox PARC araştırma merkezinde geliştirilen Xerox Alto bilgisayarındaki arayüzdür; yani Xerox'tan çıkmıştır ama yazıcı arayüzü olarak değil, bir bilgisayar arayüzü olarak geliştirilmiştir.

Windows, macOS ve Unix sistemleri farklı GUI'lere sahiptir. Android telefonlarda da her markanın arayüzü farklıdır; sistem hepsinde Android'dir ama GUI farklı kodlanmıştır. Bunun nedeni GUI'nin işletim sisteminin bir parçası olması ama çekirdekle ilgili olmamasıdır; GUI'yi değiştirirken çekirdeğe müdahale edilmez.

**Soru:** Bunların içinde en eski GUI'ye sahip olan hangisidir? **Cevap:** Hoca önce Apple'ın Unix tabanlı olduğunu söyleyip düzeltti ve Unix'te kullanıcı arayüzünün bulunduğunu, Microsoft'un GUI'ye daha sonra geçtiğini anlattı; ona göre Windows 3.1 komut satırı arayüzüydü ve GUI Windows 95 ile geldi, bu da o dönem bir devrim gibi karşılandı.

> **Ders sonrası not:** Windows 3.1 de grafik arayüzlü bir sistemdi (MS-DOS üzerinde çalışan bir grafik ortam olarak); Windows 95 ise Başlat menüsü ve görev çubuğuyla arayüzü köklü biçimde değiştiren ve MS-DOS'u kullanıcıdan büyük ölçüde gizleyen sürümdür. "Windows 95 ile GUI geldi" ifadesi bu yüzden tam doğru değildir.

Günümüzde dokunmatik ekran arayüzleri ve sesli komutla çalışan arayüzler de vardır. Slaytta macOS'un GUI'si gösterildi.

## 5. Sistem Çağrıları ve API'ler

### 5.1 Tanım

Kullanıcı arayüzünün bir altında sistem çağrıları vardır. Sistem çağrıları, işletim sistemi servislerini kullanabilmek için kullanılan bir programlama arayüzüdür; genellikle C/C++ ile yazılır. İşletim sistemi tarafından gerçekleştirilmiş, programların erişimine hazır biçimde bir kenarda tutulur.

Uygulamalar sistem çağrılarına genellikle **API (Application Programming Interface)** üzerinden ulaşır. Yazdığımız uygulamalardaki `printf` gibi fonksiyonlar sistem çağrısı değildir. API'ler sistem çağrılarıyla, sistem çağrıları servislerle, servisler de donanımla haberleşir; böylece işletim sisteminin gözetiminde istediğimiz şeyler yapılır. Win32 API ve POSIX API bunlara örnektir.

### 5.2 Dosya kopyalama örneği

Slayttaki örnek bir dosyanın içeriğini başka bir dosyaya kopyalamak için gereken sistem çağrıları dizisidir (ekrandan, 00:42:30):

```text
Girdi dosyasının adını al
  Ekrana istem yaz
  Girdiyi kabul et
Çıktı dosyasının adını al
  Ekrana istem yaz
  Girdiyi kabul et
Girdi dosyasını aç
  dosya yoksa iptal et
Çıktı dosyasını oluştur
  dosya varsa iptal et
Döngü
  Girdi dosyasından oku
  Çıktı dosyasına yaz
Okuma başarısız olana kadar
Çıktı dosyasını kapat
Ekrana tamamlandı mesajı yaz
Normal sonlan
```

Önce kaynak dosyanın adı kullanıcıdan alınmalıdır; ekrana bir istem yazmak ve girdiyi almak için sistem çağrıları çalışır, alınan veri bir yerde saklanır. Çıktı dosyasının adı da böyle alınır. Bu işlemlerin her adımında sistem çağrıları görev alır. Dosyayı açmak için C'de `fopen` kullanırız; `fopen` bir API'dir ve bir sistem çağrısıyla ilişkilendirilir. Farklı dillerdeki farklı fonksiyonlar dosya erişimiyle ilgili aynı sistem çağrısına bağlanır. Kimisi parametreleri açıkça alır (örneğin `fopen`'a `"rb+"` verip ikilik okuma yapmak gibi), kimisinde parametreleri arka planda kendisi hazırlar; ama aşağıdaki sistem çağrısı aynıdır.

### 5.3 `read` API'si

Slaytta örnek olarak Unix/Linux sistemlerinde standart olan `read` API'si verildi; bir kaynaktan veri okumak için kullanılır. Linux komut satırında `man read` yazılırsa (manual page) nasıl kullanılacağının ayrıntıları gelir. Windows'ta aynısı yoktur, benzerleri vardır. Bu, C'deki `fread`, `fscanf`, `fwrite`, `fprintf` gibi fonksiyonlardan farklıdır: Görünüş olarak bir fonksiyondur ama bir sistem çağrısıyla konuşabilen bir API'dir.

### 5.4 Sistem çağrısının gerçekleşmesi

Her sistem çağrısının bir **numarası (ID)** vardır ve addan bu numaraya dönüşüm yapılır. Sistem çağrısı arayüzü ilgili sistem çağrısını çağırır (invoke; hoca kelimenin "yalvarmak, dua etmek" anlamı da olduğunu, burada "call" anlamında kullanıldığını söyledi). Sistem çağrısı etkinleşince ilgili işletim sistemi servisleri çalışır ve istenen işlem gerçekleşir.

Çağıranın hangi sistem çağrısının hangi numarada olduğunu bilmesi gerekir. Bunu bilmek mümkün değildir; örneğin bu bilgisayarda `read` sistem çağrısının numarası bilinemez. Bu yüzden API'leri ve üst düzey fonksiyonları kullanırız. Mikroişlemciler dersinde assembly ile ekrana bir şey yazmak için AX'e bir değer koyup belli bir kesmeyi çağırmak gibi ayrıntıları yazmak gerekir; `printf`'te böyle bir şey yapmayız. Ne kadar üst düzeyde program yazılırsa o kadar kolaydır, ama aşağısı o kadar ayrıntılıdır ve bazen o ayrıntıya da ihtiyaç olur. Birçok işletim sistemi arayüzünde bu ayrıntılar hem gereksiz olduğu için hem de güvenlik nedeniyle gizlenir; işletim sisteminin her şeyine müdahil olmak iyi değildir.

Akış şöyledir: Kullanıcı uygulaması bir dosya açmak ister ve bu isteği sistem çağrısı arayüzüne iletir (`fopen` ya da başka bir fonksiyonla). `fopen` çağrılırken kullanıcı modundasınızdır ve yetkiniz kısıtlıdır. Asıl işi yapan çağrıyı kullanabilmek için sistem çekirdek moduna geçer, ilgili sistem çağrısının numarasına göre adresi bulunur. Bu numaraya karşılık gelen bir fonksiyon vardır; o da bir programdır, bir C fonksiyonu gibidir. Fonksiyon çalıştırılır ve dönene kadar beklenir. Sonra sistem çağrısı arayüzüne bir yanıt döner: Dosya açılabilir ya da açılamaz. Açılamamasının nedenleri farklı olabilir: erişim hakkınız yoktur, böyle bir dosya yoktur ya da donanımsal bir hata olmuştur. İşlemin başarılı ya da başarısız olduğunu bildiren farklı yanıtlar beklenir.

Bu yalnızca dosya açmak için değil, bir programdan veritabanına bağlanmak için de geçerlidir: Java ya da C# uygulamanızdan PostgreSQL'deki kitaplar veritabanına bağlanmak istediğinizde bir istek gönderirsiniz, bu arka planda bir bağlantıya dönüşür; bağlantı açılırsa veri okuma ya da yazma işlemleri yapılır.

Ders arasında yazılı bir soruya hoca şöyle yanıt verdi: Sistem çağrısı numaraları görünüş olarak onaltılık (hexadecimal) tabanda gösterilir, ama bilgisayarın içinde onaltılık diye bir şey yoktur; ikilik olarak saklanır. Onaltılık gösterim bizim için bir kolaylıktır.

## 6. Sistem Çağrısında Parametre Geçirme

### 6.1 Fonksiyon çağrısı ve yığın hatırlatması

Hoca önce normal bir C programındaki akışı hatırlattı. Ana program (`mx`) bir yerde `fx` fonksiyonunu çağırır, `fx` de içinde `gx`'i çağırır. `fx` çağrıldığında bir sonraki satır çalıştırılmaz, önce `fx`'e gidilir; `gx` önce biter, sonra `fx` biter, sonra ana program kaldığı yerden devam eder. `fx`'e gittiğimizde geri döneceğimiz adresi nasıl hatırlarız? **Cevap:** Yığın (stack).

Program çalıştırıldığında bellekte ona bir yer ayrılır ve bunun bir bölümü yığındır. Yığında `int a`, `int b`, `float x` gibi yerel değişkenler tutulur. Bir fonksiyona dallanıldığında o ana kadarki değişkenlerin son durumu ve dönüş adresi (assembly düzeyinde düşünülürse örneğin 5. satır bilgisi, dönünce 6, 7, 8 diye devam etmek için) saklanır. `fx` içinden `gx` çağrılınca (örneğin 800. satır) bunlar yeniden yığına push edilir; böylece yığın büyür. Fonksiyonlardan dönüldükçe yığından eleman çıkarılarak eski yere dönülür.

Sistem çağrısı da bir programdır; içinde kendi kodları vardır. Bir sistem çağrısı içinden başka bir sistem çağrısı çağrılırsa işler karışır. Bir sistem çağrısını tanımlamak için çoğu zaman yalnızca numarası yetmez: Nasıl bir iş yapacağı, ne kadar bellek kullanacağı gibi bilgiler de gerekir.

### 6.2 Üç yöntem

Slayttaki maddeler (ekrandan, 00:56:00):

- Çoğu zaman istenen sistem çağrısının kimliğinden fazlası gerekir; bilginin türü ve miktarı işletim sistemine ve çağrıya göre değişir.
- Parametreleri işletim sistemine geçirmenin üç genel yöntemi vardır:
  - En basiti: parametreleri register'larda geçirmek. Bazı durumlarda parametre sayısı register sayısından fazla olabilir.
  - Parametreleri bellekte bir blokta ya da tabloda saklamak ve bloğun adresini bir register'da parametre olarak geçirmek. Linux ve Solaris bu yaklaşımı kullanır.
  - Parametreleri program yığına yerleştirir (push), işletim sistemi yığından alır (pop).
- Blok ve yığın yöntemleri geçirilen parametrelerin sayısını ya da uzunluğunu sınırlamaz.

Hoca register yönteminin sorununu şöyle anlattı: Register'lar hızlıdır ve sistem çağrısının hızlı tamamlanmasını isteriz. Ama bir fonksiyonun adresini AX'te tuttuğumuzu düşünelim; AX'te 5 var ve `fx` çağrıldı. `fx` içinden `gx` çağrılırsa 5 gider, yerine 8 ya da 80 gelir. İş bitince geri döneceğim adresi artık silmiş olurum; AX yetersiz kalır. AX ve BX'i birlikte kullanmak da çözüm değildir, çünkü iç içe çağrıların sonu yoktur; üstelik 20 değişken olsa daha fazla register gerekir. Bu yüzden register yöntemi yerine göre mantıklıdır ama kendi içinde açmazları vardır.

Blok yönteminde talebe ait veriler, genel amaçlı register'lar (AX, BX gibi) yerine özel olarak ayrılmış (dedicated) bir bölgeye blok hâlinde yazılır ve bloğun adresi özel amaçlı bir register'da tutulur. Blok, yığın mantığıyla düzenlenir ki yazıldığı gibi okunabilsin; yoksa AX örneğindeki gibi veri silinir ve sistem devam edemez. Bunun daha sistematik versiyonu, parametrelerin işletim sisteminin yönettiği bir yığın alanına push ve pop edilmesidir. Bu işlemlerin de kendi sistem çağrıları vardır; mantık normal bir programdaki gibidir, ama burada push ve pop sistem çağrısı düzeyindedir ve kullanıcı programı kadar geciktirilemez, hızlı tamamlanmalıdır.

> **Hocanın vurgusu:** Blokların ve yığına aktarılanların bir sınırı olmalıdır. Normal bir fonksiyon yazar gibi 30-40 parametreli bir sistem çağrısı yazmak iyi değildir; sistem çağrıları olabildiğince küçük ve basit olmalıdır. Çok parametre alan bir sistem çağrısının sorun çıkarması muhtemeldir.

Örneğin 13 numaralı sistem çağrısı çağrıldığında numara bir register'da saklanabilir ve sistem çağrısının koduna dallanılır. Parametre bilgileri geçici olarak bir tabloda ya da blokta tutulur; bunun için genel amaçlı değil özel amaçlı bir register gerekir. Sürekli sistem çağrısı gelme ihtimali varsa yığın kullanılmalıdır.

## 7. Sistem Çağrısı Türleri ve Standart C Kütüphanesi

### 7.1 Türler

Aradan sonra hoca sistem çağrısı türlerine geçti:

- **Süreç kontrolü:** süreç oluşturma, sonlandırma (öldürme), yarıda kesme (abort, bir şeyin durduk yere yarıda kesilmesi), süreç özelliklerini alma ve ayarlama (get/set), bekleme. Ayrıca kilitler (lock): Paylaşılan bir veriye süreçlerin erişimini yönetmek için kullanılan kilitler de sistem çağrılarıyla sağlanır.
- **Dosya yönetimi:** dosya oluşturma, silme, açma, kapatma, okuma, yazma, konumlandırma (örneğin dosyanın başına gitmek için reposition).
- **Aygıt yönetimi:** aygıt isteme (request device) ve bırakma (release device), okuma ve yazma. Okuma ve yazma yalnızca dosya yönetimi için değildir: Diske erişirken de, ağa veri yazarken de `read`/`write` kullanılır; yazıcıya genellikle yalnızca `write` yapılır. Hepsi aynı `write` üzerinden gider; sistem çağrısı ilgili aygıtın denetleyicisine bir istek gönderir ve aygıt o denetleyici üzerinden çalıştırılır.
- **Bilgi bakımı:** saat ve tarih bilgilerinin alınması ve ayarlanması gibi.
- **Haberleşme:** mesaj geçirme ya da paylaşımlı bellek yapılarının oluşturulması ve yürütülmesi.
- **Koruma.**

Slayttaki Windows ve Unix karşılaştırma tablosu (ekrandan, 01:13:00):

```text
Kategori            Windows                          Unix
Süreç kontrolü      CreateProcess()                  fork()
                    ExitProcess()                    exit()
                    WaitForSingleObject()            wait()
Dosya işlemleri     CreateFile()                     open()
                    ReadFile()                       read()
                    WriteFile()                      write()
                    CloseHandle()                    close()
Aygıt işlemleri     SetConsoleMode()                 ioctl()
                    ReadConsole()                    read()
                    WriteConsole()                   write()
Bilgi bakımı        GetCurrentProcessID()            getpid()
                    SetTimer()                       alarm()
                    Sleep()                          sleep()
Haberleşme          CreatePipe()                     pipe()
                    CreateFileMapping()              shmget()
                    MapViewOfFile()                  mmap()
Koruma              SetFileSecurity()                chmod()
                    InitializeSecurityDescriptor()   umask()
                    SetSecurityDescriptorGroup()     chown()
```

Hoca Unix'te süreç oluşturmak için `fork` ve `exec` sistem çağrılarının kullanıldığını, bunların fonksiyon gibi görünse de aslında sistem çağrısı olduğunu, Windows'ta ise `CreateProcess` kullanıldığını söyledi; bu konu gelecek derste ele alınacak. İki süreç haberleşirken `pipe`, paylaşımlı bellek ya da bellek eşleme (memory map) çağrıları kullanılır.

### 7.2 Standart C kütüphanesi örneği

Slayttaki örnekte (ekrandan, 01:14:30) bir C programı `printf()` kütüphane çağrısını, o da `write()` sistem çağrısını çağırır:

```c
#include <stdio.h>
int main ( )
{
    ...
    printf ("Greetings");
    ...
    return 0;
}
```

`printf` çağrıldığında kullanıcı modundayız ve standart C kütüphanesine gidilir. Kütüphane çekirdek moduna geçip `write()` sistem çağrısını çağırır. `printf` ekrana yazar; bu yüzden `write`'a "böyle bir veri var, bunu ekrana yazdır" diye parametre verilir. `fprintf` kullanılsaydı bir dosyaya yazılacağı için hangi dosya olduğu da söylenmeliydi; `fopen` ile açılan dosya işaretçisi (file pointer) hedef olarak `write` sistem çağrısına iletilir. Şemada sistem çağrısı parametresiz görünse de ona çok sayıda parametre gelebilir. İş bitince yanıt önce kütüphaneye, sonra programa döner.

**Soru:** `printf`'in dönüş değeri olarak ne görürsünüz? **Cevap:** Ekrana kaç karakter basıldıysa o sayıyı. Hocanın tahminine göre `write` sistem çağrısı kaç karakter yazıldığını raporlar ve `printf` bunu geri getirir; hiçbir şey yazılamadıysa eksi bir gibi bir değer gelebilir. Hoca `printf` içinde `fprintf` çağırmak gibi denemeler yapmayı önerdi. Benzer şekilde bir veritabanına kayıt eklediğinizde ya da sildiğinizde "3 rows affected" gibi bir yanıt gelir; bu da sistem çağrılarından gelen dönüş değeridir.

> **Ek bilgi (derste anlatılmadı):** C standardına göre `printf` yazdığı karakter sayısını, bir çıkış hatasında ise negatif bir değer döndürür. Ajanın denemesinde `printf("Greetings")` çağrısı 9 döndürdü ("Greetings" dokuz karakterdir); deneme programı `gcc -Wall` ile derlenip çalıştırıldı.

## 8. İşletim Sistemi Örnekleri: MS-DOS ve FreeBSD

**MS-DOS** tek görevli (single tasking) bir işletim sistemidir: Bir zaman aralığında tek bir görev yapılır. Bootstrap sistemi belleğe yükleyip işletim sistemini açtıktan sonra komut yorumlayıcısı (command interpreter) adlı sistem yazılımı çalıştırılır ve komut satırı arayüzü karşımıza gelir. Programları çalıştırmanın basit bir yöntemidir; tek bir bellek uzayı vardır. `format`, `dir` gibi bir program çalıştırıldığında çekirdek onu belleğin boş bölgesine yükler; program bitince (exit) kabuk yeniden yüklenir ve ekrana gelir.

**FreeBSD**, buna çok benzeyen ama çok görevli (multitasking) çalışabilen bir Unix türevidir. Bellekte tek bir süreç değil A, B, C gibi birçok süreç olabilir. Kullanıcı oturum açar (login); "A'yı çalıştır" dendiğinde kabuk üzerinden `fork` sistem çağrısıyla süreç oluşturulur ve ona yer ayrılır (`fork` ve `exec` ileride anlatılacak). Bir kod hatasız biterse 0, hata varsa sıfırdan büyük bir değer döndürür; çünkü bunlar da kendi içinde programdır.

## 9. Sistem Programları

Sistem programları, en alt düzeydeki işletim sistemi servislerini rahat kullanmamızı sağlayan programlardır:

- **Dosya yönetimi:** Masaüstünde sağ tıklayıp yeni klasör oluşturmak, bir şeyi silmek; dosya oluşturma, silme, kopyalama, yeniden adlandırma.
- **Durum bilgisi (status information):** Örneğin bir veriyi bir yerden bir yere gönderirken zaman damgası (timestamp) eklemek için sistemden saat ve tarih almak; veritabanı yönetim sisteminin bir kayda otomatik zaman bilgisi eklemesi. Log bilgileri (şu kullanıcı giriş yaptı, şu dosyayı sildi, açtı, içine yazdı) ve hata ayıklama bilgileri de sistemin güvenliği ve servislerin sürdürülmesi için saklanan durum bilgileridir.
- **Dosya değişikliği (file modification).**
- **Programlama dili desteği:** derleyici, assembler, debugger. Linux sistemlerde `gcc` hazır gelir; bu da bir sistem programıdır.
- **Program yükleme ve çalıştırma:** Çalıştırdığınız programın bir kopyasının diskten belleğe aktarılması ayrı bir programın işidir.
- **Haberleşme.**
- **Arka plan servisleri:** Bilgisayar açılmasıyla birlikte çalışan uygulamalar.
- **Uygulama programları:** Bazıları sistem programı olabilir.

> **Hocanın vurgusu:** Sistem programları kullanıcı düzeyine yakındır ama kullanıcı programı gibi değildir. Sistem çağrısı da değildir; örneğin bir format uygulamasını kullanırken ya da Ctrl+P ile yazdırırken ben sistem çağrısı kullanmam, yalnızca arayüzü kullanırım.

**Soru:** Windows'taki kayıt defteri düzenleyicisi (regedit) nedir, bir durum bilgisi midir? **Cevap:** Hayır. Kayıt defteri (registry), bilgisayarda kurulu yazılımlarla ilgili bazı ayarları tutan basit bir veritabanı ya da sözlüktür. Örneğin bir program açılırken çıkan ve sesli olabilen açılış ekranını (splash screen) kapatmak gibi ayarlar buradan okunur. İnternette "regedit'i açın, şu yolu izleyin" denince `HKEY_LOCAL_MACHINE` ya da `HKEY_CURRENT_USER` altındaki program ayarlarına gidilir; hoca örnek olarak WinRAR'a ait değerleri gösterdi. Program bu değerleri okuyarak çalışır.

## 10. İşletim Sistemi Tasarımı ve Gerçekleştirimi

Hoca bu konuların soyut olduğunu, kitaptan ek okuma gerektirdiğini, çünkü doğrudan algoritmik bir uygulamasının her zaman görülmediğini belirtti.

### 10.1 "Çözülebilir" değil

> **Hocanın vurgusu:** İşletim sisteminin tasarımı ve gerçekleştirimi "çözülebilir" (solvable) bir problem değildir.

Bir problemin çözülebilir olduğunu söylemek için onun bir algoritmasını yazmak gerekir; polinom zamanlı olması tercih edilir, olmasa bile bir algoritma varsa çözülebilir denir. Oysa "şu algoritmayı kullanırsan işletim sistemi tasarlarsın" denebilecek bir algoritma yoktur. Bunun yerine başarılı olduğu kanıtlanmış bazı yaklaşımlar vardır: Microsoft'un kendine göre bir stili, Linux sistemlerin kendine göre bir yolu vardır. Altlarında elbette algoritmalar vardır, ama faktöriyel algoritması gibi "önce bunu, sonra bunu yap, al sana işletim sistemi" denemez; çünkü işletim sistemlerinin iç yapıları birbirinden farklıdır.

### 10.2 Hedefler

Bir yazılımda gereksinim analizi ve spesifikasyonlar belirlendiği gibi işletim sisteminde de belirlenir. İşletim sistemi gömülü sistemler için mi, gerçek zamanlı mı, kişisel bilgisayar için mi, mobil için mi olacak? Donanıma ve gereksinime göre farklı yaklaşımlar seçilir.

- **Kullanıcı hedefleri:** kolay kullanılsın, öğrenmesi kolay olsun, güvenilir, güvenli ve hızlı olsun. Sistemlerin sürekli değişmesinin nedeni daha hızlı, daha güvenli ve yeni özellikli olma beklentisidir.
- **Sistem hedefleri:** tasarımı, gerçekleştirimi ve bakımı kolay; esnek, güvenilir, hatasız ve verimli olmalıdır.

Hoca bir uyarı yaptı: Her yeteneğe sahip bir işletim sistemi her zaman iyi değildir. En alt düzeyde algoritmalar çalışır ve onların karmaşıklığı sistemi kötü kullanmaya yol açabilir; "çok şey istiyorsunuz ama hiçbir şey yapamaz duruma gelebilirsiniz", yani bindiğiniz dalı kesersiniz.

### 10.3 Politika ve mekanizma

İki farklı ilke ayrılmalıdır: İşletim sistemi ne yapacak (what will be done, politika) ve yapacağı şeyi nasıl yapacak (how to do it, mekanizma). Örneğin bir gerçek zamanlı işletim sistemi kuracaksanız gereksinimlerini belirlemek gerekir. Bu ikisini birbirinden ayırmak önemlidir.

Hocaya göre işletim sistemleri yazılım mühendisliği kriterlerinin çok güzel bir uygulamasıdır. Yazılım mühendisliğinde bir örnek olay incelemesi yapılacaksa işletim sistemi ilk düşünce aşamasından gerçekleştirime kadar incelenebilir. İnşaatta iyi bir mimarinin arkasında ciddi emek olması gibi, işletim sisteminde de öyledir. Bizim yazdığımız bir web ya da mobil uygulama her zaman bu kriterleri sağlamaz; bir şey eklemeye çalışınca baştan yazmak daha mantıklı hâle gelebilir. Oysa bir işletim sistemine güncelleme geldiğinde sistemi baştan kurmak gerekmez; güncelleme indirilir ve etkisi kısa sürede görülür.

### 10.4 Gerçekleştirim dili

İlk zamanlarda assembly, sonra Algol (algorithmic language) ve PL/1 kullanıldı. Günümüzde C/C++ kullanılır; Rust da artık görülebilir. Günümüz sistemleri karmaşık biçimde gerçekleştirilir: düşük düzey işler assembly'de, orta düzey işler C'de, daha üst düzey sistem programları Python ya da Perl gibi dillerde yazılabilir. Örneğin ekran kaydı alan, grafik arayüzlü küçük bir sistem programını assembly'de yazmak çok uzun olur; üst düzey bir dille eklenti gibi yazmak daha basittir. Üst düzey dillerle yazılmış kodu başka donanımlara taşımak (port etmek) daha kolaydır ama daha yavaştır. Donanım olmadan işletim sistemini çalıştırmayı sağlayan emülasyon yazılımları da gerçekleştirimde kullanılabilir.

Ders sırasında bir öğrenci bir sorun sordu; hoca yanıtında UEFI'nin iki işletim sistemini de destekleyecek şekilde ayarlanabileceğini, birini önce birini sonra yüklerken bazen donanımla yazılım arasındaki uyumsuzluk ("organ nakli gibi tam uyuşmaması") yüzünden hata alınabileceğini, kendi deneyiminde Windows üzerine Linux kurmanın daha mantıklı olduğunu ve daha çok kullanılan sistemin üzerine kurmanın iyi olduğunu söyledi. <!-- BELİRSİZ: Öğrencinin sorusu altyazıda duyulmuyor; yanıttan iki işletim sistemini (Windows ve Linux) aynı bilgisayara kurmakla ilgili olduğu anlaşılıyor. -->

## 11. İşletim Sistemi Yapıları

Genel amaçlı bir işletim sistemi çok büyük bir programdır. Farklı yaklaşımlar izlenmiştir: Önce basit bir yapı (başı ve sonu olan tek bir program gibi), sonra birbiriyle haberleşen alt yapılarla daha karmaşık yapılar, ardından soyutlamayla katmanlı yapılar ve mikroçekirdek.

### 11.1 Basit yapı: MS-DOS

MS-DOS'ta uygulama yazılımı ve sistem programları gerektiğinde doğrudan donanıma ya da aygıt sürücülerine erişebilir. Modüler bir yapıdan söz edilemez; bazı yapılar olsa da arayüzler ve işlevler iyi ayrılmamış ve düzenlenmemiştir. Normal bir program gibi başlar ve biter; yerine göre donanıma doğrudan, yerine göre başka yazılımlar üzerinden erişir.

### 11.2 Geleneksel Unix

Unix daha az basit, çekirdek yapısıyla öne çıkan bir sistemdir; "kernel" ifadesi de biraz Unix ile yaygınlaşmıştır. Donanıma doğrudan erişimi kısıtlamıştır ve sistem programı kavramı daha çok burada görülür. Geleneksel Unix mimarisinde kullanıcının muhatap olacağı şeyler ayrı bir yerde tutulur; araya sistem çağrısı arayüzü konur, işletim sistemi servisleri onun altına yerleştirilir ve donanıma erişim çekirdek arayüzü (kernel interface) ile sağlanır. Yani bir sistem çağrısı arayüzü ve bir çekirdek-donanım arayüzü vardır; çekirdek hem donanımdan hem kullanıcıdan ayrılmıştır. Tamamen katmanlı değildir, ama MS-DOS'a göre çok daha verimli olduğu zamanla kanıtlanmıştır.

### 11.3 Katmanlı yaklaşım

En temelde donanım (katman 0) vardır. Onunla doğrudan muhatap olan katman 1'dir; katman 1 bir şey talep ederse katman 0'dan talep eder ve katman 2'ye hizmet verir. Bu bir istek-yanıt yapısıdır. Modülerlik artmıştır; yönetimi ve bakımı kolaydır, hatanın nerede olduğu rahatça bulunur.

Hoca bu yapının uygulama geliştirmede de kullanıldığını, örneğin web ve mobilde kullanılan **MVC** (Model-View-Controller) desenini örnek verdi. Bir web uygulamasında veritabanı, kullanıcı arayüzü ve kayıt ekleme, silme gibi algoritmik işler vardır (örneğin öğrenci bilgi sisteminde ders eklemek aslında veritabanına bir kayıt eklemektir). Bunların tek bir program gibi yazılması çok kötüdür. Veritabanını ilk öğrenirken `main` içinde bağlantı açılır, SQL komutları gönderilir, veriler işlenir ve bağlantı kapatılır; bütün kod tek bir fonksiyona sıkıştırılmıştır. Bu "spagetti koda" çok yakındır ve bir şey değiştirmek ya da eklemek istendiğinde baştan yazmak daha mantıklı olabilir. Bunu önlemek için veritabanı bağlantısıyla ilgili şeyler modele, kullanıcı arayüzü ile ilgili şeyler görünüme (view), ekleme, silme, güncelleme gibi algoritmalar denetleyiciye (controller) ayrı sınıflar olarak yazılır. Böylece daha yönetilebilir, modüler bir yazılım olur.

Bir diğer örnek e-Devlet'tir: e-Devlet'ten öğrenci belgesi aldığınızda belge e-Devlet'in bilgisayarında üretilmez; e-Devlet YÖKSİS'e, YÖKSİS de üniversitenin sistemine bağlanır ve sistemler kendi aralarında haberleşerek belgeyi verir. Hepsi tek yerde olsaydı hem gecikme hem güvenlik sorunu olurdu. Katmanlı mimari donanıma doğrudan erişim özgürlüğünü kısıtlar ama ciddi faydaları vardır; sistem ne kadar modülerse o kadar iyidir.

### 11.4 Çekirdekte ne kadar servis olmalı?

**Soru:** Siz olsanız çekirdeğe sistem çağrısını az mı koyarsınız, çok mu? Dosya sistemi, disk ve teyp sürücüleri, CPU zamanlama gibi işler çekirdekte mi olmalı; çekirdek kalabalık mı olmalı? **Cevap:** Hoca on beş dakika önce söylediği "bindiğin dalı kesmek" uyarısını hatırlattı. Çekirdeğe gereğinden fazla servis yüklenirse sistem hantallaşır ve donanım verimli kullanılamaz. Gereğinden az servis konursa, kullanıcı isteklerini karşılayacak sistem çağrısı olmadığı için kullanıcı düzeyinde ek yazılımlar yüklemek gerekir. Örneğin hiçbir bilgisayarda yazıcıya veri gönderme uygulaması olmasaydı, Ctrl+P'ye basınca hiçbir şey çıkmazdı; bir yazıcı bağlarken hem sürücüsünü hem de o yazıcıyla uyumlu bir uygulama yazılımını (örneğin o markanın uygulamasını) yüklemek gerekirdi. Çekirdekte şişirilmeyen şey bu kez uygulama düzeyinde şişer. Dolayısıyla kullanılacak sisteme yetecek ölçüde işletim sistemi servisiyle tasarlamak en doğrusudur.

### 11.5 Mikroçekirdek

**Mikroçekirdek (microkernel)** yaklaşımında çekirdek olabildiğince küçük tutulur ama en fazla faydayı sağlayacak servisler içinde bulunur. Örnek olarak macOS X çekirdeğinin dayandığı Mach verilir. Kişisel bilgisayar kullanıcılarının belki yüzde 95'inin günlük ihtiyaç duyacağı servisler çekirdekte bulunur; geri kalan yüzde 5'lik kısma çok yer verilmez. Yapı genişletilebilir (extendable); gerekirse yeni şeyler eklenir, çekirdek gereksiz yere meşgul edilmez, daha güvenilir ve güvenlidir, değiştirmesi kolaydır. Gerçek zamanlı bir işletim sistemindeyse çekirdek o sistemden beklenen servisleri kapsar, kişisel bilgisayarda ise kişisel kullanıma uygun servisleri.

Slayttaki şemada (ekrandan, 01:47:00) uygulama programı, dosya sistemi ve aygıt sürücüsü kullanıcı modundadır ve birbirleriyle mikroçekirdek üzerinden mesajlarla (messages) haberleşir. Çekirdek modundaki mikroçekirdekte yalnızca süreçler arası iletişim (interprocess communication), bellek yönetimi ve CPU zamanlama bulunur; mikroçekirdek donanımla konuşur.

Dezavantajı şudur: Çekirdek yeterli işleve sahip olmadığında kullanıcı alanı (user space) ile çekirdek alanı (kernel space) arasında sürekli geçişler olur. Örneğin dosya sisteminden bir şey okumak, yazıcıya ya da ekran kartına bir şey göndermek gerekiyorsa ve bu servisler mikroçekirdekte yoksa bir kullanıcı modu, bir çekirdek modu diye gidip gelinir; bu da ek yük (overhead), yani bekleme demektir. Yine de çekirdeği olabildiğince küçük tutmak birçok açıdan faydalıdır.

### 11.6 Yüklenebilir çekirdek modülleri

Nesne yönelimli yaklaşıma benzer biçimde, bir çekirdek vardır ve sistem **yüklenebilir çekirdek modülleriyle (loadable kernel modules)** yönetilir; ihtiyaç olursa çekirdeğe ek modüller eklenir. Linux ve Solaris'te zaman zaman kullanılmıştır.

**Soru:** Mikroçekirdek mi yapalım, modüler mi, başka bir şey mi? Bunları tek başına mı kullanmalı, yoksa amaca göre melez olarak mı? **Cevap:** Modüler yapı güzeldir ama her zaman yüzde yüz kullanılabilir ve sonsuza kadar böyle kalacak denemez; hayat, gereksinimler ve sistemlerin mantığı değişir. Zamanla bunları hibrit kullanmak çok daha mantıklı hâle gelmiştir ve hangi yöntemin hangisiyle birlikte kullanılacağına dair birçok araştırma ve makale vardır.

> **Hocanın vurgusu:** Dönem boyunca birçok konuda "hangisi daha iyi, hangisini kullanalım?" sorusunu soracağım. Cevap çoğu zaman tek bir yöntem değil, amaca göre birleştirilmiş yöntemlerdir.

### 11.7 Hibrit sistemler

Modern sistemler tek bir saf model kullanmaz; yerine göre mikroçekirdek, yerine göre yüklenebilir modüller, yerine göre monolitik yapılar bir araya getirilir ve sistem ihtiyaca göre genişleyip daralabilir. Windows büyük ölçüde monolitik bir yapıdan çıkmış, üzerine farklı kullanımlar için mikroçekirdek özellikleri eklenmiştir; işletim sistemi servislerini açıp kapatarak çekirdeği büyütüp küçültebilirsiniz.

Hoca Windows Vista örneğini verdi: XP'den sonra gelen Vista görünüş olarak çok hoştu, ama çok yavaştı. O dönemin ortalamanın üzerinde işlemcili yeni bir bilgisayarda bile açılış iki dakika kadar sürüyordu. Nedeni Vista'nın çok fazla servisle yapılandırılmış olmasıydı; açılışta bu servislerin hepsi başlatılmaya çalışılıyor, masaüstü gelene kadar bu süre geçiyordu. Aynı bilgisayara Windows 7 kurulduğunda açılış 15-20 saniyeye indi. Bunu kullanıcı kendisi de düzeltebiliyordu, ama burada açılışta uygulamaları kapatmaktan değil, gereksiz işletim sistemi servislerini kapatmaktan söz ediliyor. 200-300 servis arasında hangisinin kapatılacağını bilmeyen biri yanlışlıkla kablosuz ağ servisini kapatabiliyordu. Windows 7'de ise genel kullanıma uygun servisler açık geliyor, isteyen ek servisleri sonradan açabiliyordu.

**macOS X** yapısında çekirdekte bir çekirdek kısım (Mach), G/Ç ile ilgili bir kit (I/O Kit), çekirdek uzantıları (kernel extensions) ve bir BSD kısmı vardır; istendiğinde genişletilebilir ya da küçültülebilir. **iOS**'ta mobil cihazlarda sürekli enerji gelmediği için hem bataryayı tüketmeyecek hem de sistemi uygun kullanacak bir yapı gerekir: Çekirdek işletim sistemi (Core OS) üzerine çekirdek servisler (Core Services), medya servisleri ve Cocoa Touch eklenir.

**Android** benzerdir: Açık kaynaktır ve değiştirilmiş bir Linux çekirdeğine sahiptir. Üzerinde süreç, bellek ve aygıt sürücüsü yönetimi servisleri vardır; bunlara bir **güç yönetimi** servisi eklenmiştir. Fişe takılı çalışan eski masaüstü bilgisayarlarda güç yönetimine pek gerek yoktur, ama mobilde batarya çok önemlidir. Çalışma zamanında Dalvik sanal makinesi çalışır; kurduğunuz uygulamalar bu sanal makine üzerinde çalışır.

> **Ek bilgi (derste anlatılmadı):** Kitabın 9. baskısındaki Android şemasında Dalvik yer alır; Android 5.0 (2014) ile birlikte Dalvik'in yerini ART (Android Runtime) almıştır. Uygulamaların bir çalışma zamanı ortamında yürütülmesi mantığı aynıdır.

## 12. İşletim Sistemi Hata Ayıklama ve Başarım Ayarı

### 12.1 Log, core dump ve crash dump

Hata ayıklama (debug) bir programda mantıksal hata, çalışma zamanı hatası ya da derleme hatası olup olmadığını görmek için yapılır; en çok, çalışma zamanında beklenmedik sonuçlar geldiğinde işe yarar. İşletim sistemi de bir yazılım olduğuna göre onun da hata ayıklaması gerekir, ama adım adım (step by step) hata ayıklamadan söz edilmez. İşletim sistemi hatalarla ilgili **log dosyaları** üretir; bunlar bazen, siz farkında olmasanız da, internet varsa arka planda sistemin tasarımcılarına otomatik gönderilir.

Uygulamalar yarıda kesilebilir; bunlar için **core dump** dosyaları üretilir: Hata oluşan durum ya da hata olana kadarki program serüveni kaydedilir. Hata işletim sistemi düzeyindeyse buna **crash dump** denir; çekirdeğin bellek durumunun bir dosya olarak saklanmasıdır. Hoca Windows Görev Yöneticisi'nde "İşlemler" (süreçler) sekmesinde arka planda çalışan bir kötü amaçlı yazılımdan koruma servisine sağ tıklayıp "döküm dosyası oluştur" seçeneğini gösterdi. Bu, programın başladığından o ana kadarki bellek geçmişini bir dosyaya kaydeder ve çok büyük olabilir; işletim sistemi versiyonunda ise bütün bir çekirdek alınıp dosya olarak incelenebilir.

**Soru:** Bir core dump ya da crash dump'ı incelemek ne işe yarar? **Cevap:** Hoca Windows sürümlerinden birinin tanıtımında mavi ekran hatası verdiğini hatırlattı. İşletim sistemi kodunu yazanlar ileride bir hata olursa nedenini bulabilmek için olası her durumu loglar; hoca bunu kodun içine sürekli `printf` ile ek mesajlar yazmaya benzetti. Örneğin dosya açıldıysa okunur, açılmadıysa "dosya şu nedenle açılamadı" yazılmalıdır. Kullanıcılardan bir hata bildirimi geldiğinde bu loglar incelenerek hatanın işletim sisteminin kodundan mı yoksa kullanıcının yaptığı bir şeyden mi kaynaklandığı tespit edilir.

### 12.2 Başarım ayarı

Hata dışında, başarımı optimize etmek için de istatistikler tutulmalıdır: Süreçler işlemciye, belleğe, G/Ç'ye ne kadar ihtiyaç duyuyor? Bu etkinlikler kaydedilir ve buna göre zamanlama ya da bellek optimizasyonu için istatistiksel kararlar verilir. Yani bu araçlar hem mevcut hataları düzeltmek hem de sistemi optimum kullanmak içindir.

İşletim sistemi zaman içinde kullanılan kaynakların istatistiğini tutarak bir darboğaz oluşup oluşmadığını izlemeli ve buna göre zamanlamada önlem almalıdır: gerekirse kullanıcı uygulamalarının ağırlığını düşürmek, bazılarını sonlandırmak ya da önceliklerini azaltmak. Windows Görev Yöneticisi CPU kullanımını ve diğer kaynakları belli zaman aralıklarında izler ve sisteme dair bir tehlike büyümeden onu sonlandırır. Hoca bu konuya ölümcül kilitlenme (deadlock) konusunda ayrıntılı döneceklerini söyledi.

### 12.3 Hata ayıklamanın zorluğu ve modülerlik

Hata ayıklamak her zaman kolay değildir. Hoca bir Java uygulaması örneği verdi: Uygulama veritabanına bağlanıp bir sorgu çeker ve sonucu bir tabloya (data table) yükler; görsel tabloyu oluşturan kodlar, veritabanı bağlantısı ve SQL sorgusu hepsi birbirine karışmıştır. Böyle bir kod iki nesne yönelimli ilkeyi ihlal eder:

- **Yüksek uyum (high cohesion):** Bir fonksiyon olabildiğince adına uygun tek bir iş yapmalıdır. Hem dosyaya hem veritabanına bağlanan, hem de tabloya bir şeyler basan bir fonksiyon uyumlu değildir. Fonksiyonlar "veritabanına bağlan", "sorguyu çalıştır", "tabloya yaz" diye ayrılmalıdır.
- **Düşük bağlaşıklık (low coupling):** Bir fonksiyona ne kadar çok karmaşık iş yüklenirse ona o kadar bağımlı olunur. Bağlaşıklık düşük olmalıdır.

> **Ders sonrası not:** Hoca ilkeyi "high coherence, low coupling" olarak söyledi ve "coherence"ı "tutarlılık" diye çevirdi. Yazılım mühendisliğindeki terim "high cohesion, low coupling"dir; "cohesion" uyum (bir modülün içindeki ögelerin aynı işe hizmet etme derecesi) anlamına gelir.

Hoca slayttaki Kernighan yasasını okudu: "Hata ayıklamak, kodu ilk baştan yazmaktan iki kat daha zordur. Bu yüzden kodu olabildiğince zekice yazarsanız, tanımı gereği onun hatasını ayıklayacak kadar zeki değilsinizdir." Hoca bunu şöyle yorumladı: Bir süre sonra kendi yazdığınız kodda "ben burada ne yazmıştım?" dersiniz; başkasının yazdığı kodu anlamaya çalışmak ise çok daha zordur, devasa kodlarda daha da zordur. Hata ayıklamak zor ama gereklidir ve bu zorluk azalsın diye işletim sistemi olabildiğince modüler tasarlanmalıdır. Başarım ayarında iz kayıtları (trace) ve profil çıkarma (profiling) gibi araçlar kullanılır.

## 13. Sistem Üretimi ve Önyükleme

### 13.1 Sistem üretimi (SYSGEN)

Bir program yazdığınızda onu çalışacağı işlemciye göre derlemeniz gerekir; Java gibi diller bir ara koda derlendiği için başka makinelere taşınabilir. İşletim sistemi ise doğası gereği belli bir sınıf cihaz için tasarlanır. İşletim sistemini kurarken onu derleyip kurmayız; hazır bir çalıştırılabilir hâli vardır ve genellikle USB'den ya da CD'den kurulur. Dolayısıyla belli bilgisayar türlerinin hepsinde (örneğin bütün dizüstülerde) çalışacak şekilde tasarlanmalıdır.

**SYSGEN** programı sistemin, özellikle donanımın özelliklerini elde eder ve işletim sistemini buna göre ayarlar. İşletim sistemi kurulduğunda bazı sürücüleri ayrıca tanıtmak gerekir, ama bazılarını kendisi tanır; çünkü çekirdekte belli donanımlara uygun hazır modüller vardır. Ekranı tanımazsa kurulumda görüntü bile alınamaz; en azından ekran, ekran kartı, klavye gibi temel donanımları tanıyacak şekilde üretilmelidir. Yaygın kullanılan donanımlarla ilgili standartlar bellidir. Yazıcı gibi bir aygıtı kurulumda tanımak zorunda değildir, sonra tanıtılabilir. Kurulumda bilgisayardaki işlemciyi, ekran kartını, klavyeyi (marka olarak değil, hangi mantıkla çalıştığı olarak) tanır ve sistemi buna göre yapılandırır; sonraki açılışlarda bu yapılandırmaya gerek kalmaz ve çekirdek o bilgisayara özgü biçimde çalışır.

### 13.2 Önyükleme

Güç düğmesine basıldığında sabit bir bellek bölgesinden bir program çalışmaya başlar. Geçen hafta kullanıcı programını işletim sisteminin belleğe yüklediği söylenmişti; işletim sistemini ise ROM'daki bootstrap belli bir rutinle belleğe yükler. Buna **firmware** denir: Bir yazılımdır ("ware") ama kullanıcı yazılımı gibi yumuşak (soft) değil, belli standartları olan "sıkı" bir yazılımdır. İşletim sistemi başlatıldıktan sonra klavye, fare, ekran gibi temel donanımların rutinleri bir domino etkisiyle başlatılır: Süreçler `fork` ya da `CreateProcess` çağrılarıyla bir ağaç gibi birkaç koldan oluşturulur ve masaüstü ekranı gelene kadar bu süreç sürer. Bu işi **bootstrap loader** denen küçük bir kod parçası başlatır ve çekirdeği belleğe yükler.

**Soru:** İşletim sistemini yüklemekle görevli yazılım ROM'da. Peki işletim sistemi nerede? **Cevap:** Diskte (örneğin C sürücüsünde). **Soru:** O hâlde bootstrap loader çekirdeği diskte nasıl bulacak, bir terabaytlık bütün diski mi tarayacak? **Cevap:** Hayır; diskte doğrudan gidilebilecek bilinen bir bölge olmalıdır. Bu **Master Boot Record (MBR)** gibi, işletim sistemine ait bir bölgedir ve çekirdek oradadır. Bootstrap loader bu bölgeyi okumaya başlar ve okudukça bir kopyasını belleğe yükler. Normal bir programı çalıştırdığımızda da diskten belleğe bir kopya alınır; ama işletim sisteminin kopyalanması çok hızlı olmalıdır, bütün diski aramak bir gecikme olurdu. Burada da bir optimizasyon vardır.

Önyükleme iki aşamalı bir süreçtir: Birinci adımda güç verilince ROM'daki önyükleme kodu (boot block ile ilgili kısım) çalışır; ikinci adımda bootstrap loader diskten çekirdeği bulup belleğe yükler. Yaygın kullanılan bir bootstrap loader **GRUB**'dur: Bilgisayarda iki ya da üç işletim sistemi varsa hangisinin çalıştırılacağını soran ekran bunun gibi bir şeydir. Hangi diskte durduğu, sürümü, hangi çekirdeklerin bulunduğu gibi bilgiler onun içinde saklanır. Sonra çekirdek yüklenir, sistem çalışır ve masaüstü ekranı gelir.

Ders sonunda bir soruya verilen yanıtta hoca bootstrap loader'ın ROM üzerinde olduğunu, bilgisayar açılınca önce ROM'daki kısmın, ardından diğerlerinin çalıştığını yineledi.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:27:00): Yönetici yetkisi olmayan bir kullanıcı komut satırında `format C:` yazarsa ne olur? Neden?

> **Çözüm:** Komut "erişim engellendi" (access denied) yanıtıyla reddedilir. Kullanıcı komut satırı arayüzüyle muhataptır; bu arayüz servislerden ve sistem çağrılarından geçmek zorundadır ve işletim sistemi koruma görevi gereği sistem diskine format atılmasını engeller. Harici bir diske ise format atılabilir.

**Soru 2** (ekrandan, 00:42:30): Bir dosyanın içeriğini başka bir dosyaya kopyalayan bir program hangi adımlarda sistem çağrısı kullanır?

> **Çözüm:** Girdi ve çıktı dosyası adlarını almak (ekrana istem yazma, girdiyi kabul etme), girdi dosyasını açmak (yoksa iptal), çıktı dosyasını oluşturmak (varsa iptal), okuma başarısız olana kadar döngü içinde girdi dosyasından okuyup çıktı dosyasına yazmak, çıktı dosyasını kapatmak, ekrana tamamlandı mesajı yazmak ve normal sonlanmak. Bu adımların her biri bir sistem çağrısıyla gerçekleşir.

**Soru 3** (ekrandan, 00:56:00): Sistem çağrısı parametrelerini işletim sistemine geçirmenin üç genel yöntemi nedir? Register yönteminin sorunu nedir?

> **Çözüm:** Register'larda geçirmek; parametreleri bellekte bir blok ya da tabloda tutup bloğun adresini bir register'da geçirmek (Linux, Solaris); parametreleri programın yığına push edip işletim sisteminin pop etmesi. Register yönteminde parametre sayısı register sayısını aşabilir ve iç içe çağrılarda register'daki değerin üzerine yazılır. Blok ve yığın yöntemleri parametre sayısını ve uzunluğunu sınırlamaz.

**Soru 4** (derste sözlü, 01:15:00): `printf`'in dönüş değeri nedir?

> **Çözüm:** Ekrana yazılan karakter sayısıdır; çıkış hatasında negatif bir değerdir. Ajanın denemesi (derste yapılmadı, `gcc -Wall` ile derlenip çalıştırıldı):

```c
#include <stdio.h>

int main(void) {
    int n = printf("Greetings");
    printf("\n%d\n", n);
    return 0;
}
```

> Çıktının ikinci satırı `9`'dur; "Greetings" dokuz karakterdir.

**Soru 5** (derste sözlü, 01:22:00): Windows kayıt defteri (regedit) bir durum bilgisi (status information) aracı mıdır?

> **Çözüm:** Hayır. Kayıt defteri kurulu yazılımların ayarlarını tutan basit bir veritabanı ya da sözlüktür; programlar çalışırken ayarlarını buradan okur. Durum bilgisi ise tarih-saat, log ve hata ayıklama bilgileri gibi sistemin işleyişine ilişkin bilgilerdir.

**Soru 6** (derste sözlü, 01:41:00): Çekirdeğe çok sayıda mı yoksa az sayıda mı servis konmalıdır?

> **Çözüm:** Gereğinden fazla servis çekirdeği hantallaştırır ve donanım verimli kullanılamaz. Gereğinden az servis konursa eksik işlevler için kullanıcı düzeyinde ek yazılımlar gerekir (örneğin her yazıcı için ayrı bir yazdırma uygulaması) ve yük uygulama katmanına kayar. Doğrusu, sistemin amacına yetecek ölçüde servis koymaktır; mikroçekirdek, yüklenebilir modül ve hibrit yaklaşımlar bu dengeyi kurmaya çalışır.

**Soru 7** (derste sözlü, 01:48:00): Mikroçekirdek mi, modüler yapı mı tercih edilmelidir?

> **Çözüm:** Tek bir yapı her zaman ve her amaç için en iyisi değildir; gereksinimler zamanla değişir. Modern sistemler mikroçekirdek, yüklenebilir modül ve monolitik yapıları amaca göre birleştiren hibrit yapılardır (Windows, macOS, iOS, Android).

**Soru 8** (derste sözlü, 02:11:00): Bootstrap loader işletim sistemi çekirdeğini diskte nasıl bulur?

> **Çözüm:** Bütün diski taramaz; diskin bilinen bir bölgesine (Master Boot Record ya da önyükleme bloğu) gider, çekirdeğin yerini buradan öğrenir ve çekirdeği okuyarak belleğe yükler. Süreç iki aşamalıdır: önce ROM'daki önyükleme kodu çalışır, sonra bootstrap loader çekirdeği diskten yükler.

## Dersin Toparlaması

Bu derste işletim sistemine kullanıcıdan donanıma uzanan katmanlı bir yapı olarak bakıldı. Kullanıcı arayüzleri (komut satırı, grafik arayüz, toplu işlem), işletim sistemi servisleri (program çalıştırma, G/Ç, dosya sistemi, haberleşme, hata algılama, kaynak tahsisi, muhasebe, koruma ve güvenlik) ve bu servislere ulaşmayı sağlayan sistem çağrıları ele alındı. `printf`, `fopen` gibi fonksiyonların birer API olduğu ve altta `write`, `open` gibi sistem çağrılarına bağlandığı, sistem çağrılarının numarayla bulunduğu ve parametrelerinin register, bellek bloğu ya da yığın yoluyla geçirildiği görüldü.

İkinci yarıda sistem programları, işletim sistemi tasarımında hedefler ile politika-mekanizma ayrımı, basit, geleneksel Unix, katmanlı, mikroçekirdek, modüler ve hibrit yapılar incelendi; Windows, macOS, iOS ve Android örnekleri verildi. Ders log, core dump ve crash dump ile hata ayıklama, başarım ayarı, SYSGEN ve iki aşamalı önyükleme süreciyle kapandı. Hoca sonraki derste süreç oluşturmada kullanılan `fork` ve `exec` gibi çağrılara geçileceğini belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
