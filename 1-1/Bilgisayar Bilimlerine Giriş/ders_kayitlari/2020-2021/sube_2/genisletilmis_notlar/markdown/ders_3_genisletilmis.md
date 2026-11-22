# Ders 3 Genişletilmiş Notu: Bilgisayar Sistemleri, Tarihçe, Programlama Dilleri ve Sayı Sistemleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Amacı ve Yol Haritası
- 2. Bilgisayar Sisteminin Bileşenleri
- 3. İşletim Sistemi Neden Var?
- 4. Eş Zamanlılık (Concurrency) ve Paralellik
- 5. Bellek Yönetimi
- 6. Sistem Programları
- 7. Bilgisayar Organizasyonu
- 8. Bilgisayarların Tarihçesi
- 9. Mainframe Bilgisayarlar
- 10. Donanım Neden Bu Kadar Farklı Fiyatlı?
- 11. Yazılım Türleri
- 12. Programlama Dillerinin Nesilleri
- 13. Sayı Sistemlerine Giriş
- 14. İkili, Sekizli, Ondalık ve Onaltılı Sistemler
- 15. Sayı Sistemleri Arasında Geçiş
- 16. Bit, Nibble, Byte ve Word
- Örnek Sorular

## 1. Dersin Amacı ve Yol Haritası

Hoca dersin bu bölümünün amacını, bilgisayar sistemleri hakkında genel bir bakış açısı vermek olarak tanımladı. Amaç her konuda derin bilgi vermek değil, sonraki konulara (sayı sistemleri, sıralama ve arama algoritmaları) temel hazırlamaktır. Burada değinilen bilgisayar organizasyonu, işletim sistemleri, bilgisayar ağları ve veri haberleşmesi bölümde ayrı derslerde ayrıntılı işlenecek.

Dersin ilk sunumunun sırası şöyleydi: önce bilgisayar sisteminin bileşenleri, sonra organizasyonu, ardından kısa bir tarihçe, yazılım türleri ve programlama dillerinin gelişimi. İkinci sunumda sayı sistemlerine geçildi. Hoca tarihçe kısmının, kimin kimden ne aldığı gibi ilginç hikâyelerle dolu olduğunu, meraklıların kaynaklardan ayrıca okuyabileceğini söyledi.

## 2. Bilgisayar Sisteminin Bileşenleri

"Bilgisayar Sisteminin Bileşenleri" slaytında katmanlı bir şema vardı (ekrandan, 00:20:00). En altta **computer hardware**, onun üzerinde **operating system**, onun üzerinde **system and application programs** (compiler, assembler, text editor, ..., database system) ve en üstte **user 1, user 2, user 3, ..., user n** yer alıyordu.

```text
user 1   user 2   user 3   ...   user n
   |        |        |              |
compiler  assembler  text editor ... database system
      (system and application programs)
            operating system
            computer hardware
```

Bilgisayar sistemi dendiğinde yalnız masaüstü bilgisayar akla gelmemelidir. Önümüzdeki tablet, cep telefonu, kişisel bilgisayar (PC), bir mainframe ya da sunucu sistemi de bilgisayar sistemidir. Hoca "akıllı buzdolabı" örneğini verdi: içindekilerin fotoğrafını çekip mesaj atan değil, temel kontrol işlevlerini bir mikrodenetleyiciyle yapan sıradan bir buzdolabı da bir bilgisayar sistemidir. Dijital saatler de öyle.

Bir bilgisayar sisteminde kaynak denince ilk akla gelmesi gereken **merkezi işlem birimi** (işlemci, CPU), hemen ardından da **bellek** (memory) birimidir; bütün işler bu iki temel birim sayesinde yürür. Sistem yalnız bunlardan oluşmaz, diğer birimlere organizasyon kısmında bakıldı.

Bu iki kaynağın bolluğuna göre donanım üzerinde bir işletim sistemi çalıştırılabilir ya da çalıştırılmayabilir. Özellikle 8 bit, 16 bit, zaman zaman 32 bit mikrodenetleyicilerde işletim sistemi kullanılmadan uygulama doğrudan donanım üzerinde çalıştırılabilir. Bu yapıya **bare metal** denir. Masaüstü, dizüstü ve tabletlerde ise bir işletim sistemi vardır.

Dördüncü bileşen olan kullanıcıyı hoca özellikle vurguladı: ne olursa olsun bütün bilgisayar sistemleri sonunda bir kullanıcıyla etkileşime girer.

## 3. İşletim Sistemi Neden Var?

Hoca sınıfa işletim sisteminin neden var olduğunu sordu. Öğrenciler "arayüz sağlamak", "kullanım kolaylığı", "herkesin kullanabilmesi", "çevirmen gibi", "işi kolaylaştırmak" gibi cevaplar verdi.

> **Hocanın vurgusu:** Yuvarlak cevapların bir anlamı yoktur. "Kolaylaştırmak için" denirse "zor olan ne?" diye sorulur. Verilen cevap karşı tarafı doyurmalı ya da konuyu net biçimde açıklamalıdır. Kolaylığın nereden geldiği anlatılmalıdır.

Hocanın cevabı şöyleydi: bilgisayar donanımını doğrudan kullanan bir uygulama, donanımın her parçasının nasıl kullanılacağına ilişkin bilgiyi de kendi içine gömmek zorundadır. Uygulama yalnız işlemci ve bellekle çalışmaz; ekrana görüntü gönderir, diskten okur, USB'den okur, klavye ve fareden girdi alır. Bütün bunları uygulamanın içinde yapmak, bu birimlerin nasıl kullanılacağını tarifleyen **sürücülerin** (driver) uygulamaya gömülmesi demektir.

Örneğin kullanıcıdan iki sayı alıp ekrana basan bir programı işletim sistemi olmadan yazmaya kalkarsak, önce klavyeden okumak için bir klavye sürücüsü, sonra ekrana yazmak için bir ekran sürücüsü yazmamız gerekir. Normalde çok hızlı yazılan bu program "bildiğiniz bir eziyete" döner.

Bare metal çalışmada da durum benzerdir. Ancak son on yıl kadardır mikrodenetleyici üreticileri genellikle bir kütüphane verir. Geliştirici mikrodenetleyicinin bileşenlerini bu kütüphanedeki fonksiyonları çağırarak kullanır ve uygulamayı çok daha hızlı geliştirir.

İşletim sisteminin ikinci katkısı birden fazla uygulamayı çalıştırmaktır. İşletim sistemi olmadan donanım üzerinde tek bir uygulama çalışır. Bu uygulama birkaç alt uygulamayı içerecek ve onları kooperatif çoklu görev (cooperative multitasking) ile çalıştıracak biçimde yazılabilir. İşletim sistemi ise birbirinden bağımsız, yalıtılmış uygulamaları aynı anda, yani eş zamanlı ya da paralel olarak çalıştırır.

### 3.1 Kaynak Yöneticisi Olarak İşletim Sistemi

İşletim sisteminin tanımı farklı kaynaklarda sayfalarca anlatılabilir. Ama hemen her yerde görülen en basit tanım şudur: **işletim sistemi bir kaynak yöneticisidir**. Kaynakların uygulamalar tarafından verimli (efektif) kullanılmasını sağlar.

Verimliliğin ne demek olduğunu hoca üç işle anlattı. A işi kullanıcıdan bilgi alıp yoğun hesap yapacak, B işinin verisi hazır ve doğrudan işleme başlayacak, C işi diskten veri okuyup işleyecek. A, B, C sırayla çalıştırılırsa A kullanıcıdan girdi beklerken (kullanıcı o sırada çay almaya gitmiş olabilir) herkes bekler. Hoca bu örneğin bugün için abartılı olduğunu, ama ilk sistemler için gayet olası olduğunu söyledi.

Günümüz işletim sistemlerinde bir işlem G/Ç (I/O) için beklemeye geçerse işletim sistemi onu işlemciden alır, G/Ç kuyruğuna koyar ve sıradaki işlemi işlemciye yerleştirir. B de girdi beklemeye geçerse o da G/Ç kuyruğuna gider, C çalışır. Bu sırada G/Ç'si biten A ya da B tekrar işine döner. Böylece işlemcinin boşta (idle) kalması engellenir ve işlemci zamanı işlemler arasında verimli paylaştırılır. Sıradaki işlemin hangi ölçüte göre seçileceği (öncelik, burst time vb.) işletim sistemleri dersinde ayrıntılı işlenecek.

## 4. Eş Zamanlılık (Concurrency) ve Paralellik

Hoca eş zamanlı (concurrent) ve paralel çalışmanın farklı kavramlar olduğunu vurguladı.

Tarihsel olarak ilk sistemlerde bir bilgisayar ve onu kullanan bir kullanıcı vardı. Birden fazla kullanıcı varsa biri işlerini sisteme verir, işleri bitince diğeri gelirdi (tek kullanıcı, tek görev). Sonra birden fazla uygulamanın tek işlemcide ilerleyebilmesi için **concurrency** fikri ortaya atıldı: A'nın biraz çalıştırılır, sonra B'nin biraz, sonra C'nin biraz, sonra yine B, A, C... Böylece işler birbirinin bitmesini beklemeden ilerler. Bunun için "A sen dur, B sen çalış" diyen bir denetim mekanizması gerekir. İşlemciyi uygulamalar arasında yöneten bu mekanizma işletim sistemidir.

**Paralellik** ise iki işlemci ve iki işlem olduğunda her işlemin ayrı işlemcide gerçekten aynı anda çalışmasıdır. Paralellik için birden fazla kaynak gerekir.

### 4.1 Java ve Çoklu İş Parçacığı Sorusu

**Soru:** Java'da kullanılan multitasking ve multithreading bu konuyla nasıl ilişkili?

**Cevap:** Java kodu donanım üzerinde doğrudan (native) çalışmaz. Donanımın üzerinde işletim sistemi, onun üzerinde de Java sanal makinesi (Java Virtual Machine) vardır ve kod orada çalışır. Hoca konuyu basit bir örnekle açıkladı: bir işlemci ve onu kullanmak isteyen iki kullanıcı olsun. Önce birine sonuna kadar kullandırıp sonra diğerine geçmek sıralı çalışmadır. Birine biraz, diğerine biraz kullandırmak concurrency'dir.

Diyelim ki birinci iş 30 birim, ikinci iş 3 birim sürüyor. Sıralı çalışmada ikinci iş 30 birim boşuna bekler. Her işe 2'şer birim verilirse ikinci iş kendi ikinci payında tamamlanır ve sistemden çıkar; geri kalan sürede birinci iş çalışır. Concurrency işlemlerin bekleme süresini azaltmak, sistemi etkileşimli hâle getirmek ve kaynakları daha verimli kullanmak için ortaya atılmıştır. Donanımda tek işlemci varsa multithreading aslında yalnız concurrency sağlar. Birden fazla işlemci varsa ve iş parçacıkları bunlara dağıtılırsa paralel çalışmadan söz edilebilir.

Bu örnekte ikinci işin tamamlanma zamanı şöyle bulunur (ara adım eklendi): birinci iş 0-2, ikinci iş 2-4, birinci iş 4-6, ikinci iş 6-7 aralığında çalışır. Kısa iş sıralı çalışmadaki 33. birim yerine 7. birimde biter. Hesap Python ile kontrol edildi.

## 5. Bellek Yönetimi

İşletim sistemi yalnız işlemciyi değil belleği de yönetir. Hoca öğrencilere bilgisayarlarının belleğini sordu; 4 GB belleği olanlar olduğunu görünce örneği 4 GB üzerinden kurdu.

4 GB belleği olan bir bilgisayarda art arda tarayıcı, sunum programı, Zoom, mesajlaşma uygulaması açılır. Açılan her program işletim sisteminde bir ya da daha fazla **işleme** (process) dönüşür. İşletim sistemi programın kodunu belleğe kopyalar, başına sonuna bazı eklemeler yapar, onunla ilgili veri yapıları (process control vb.) oluşturur ve işleme "bu sistemde 4 GB bellek var, istediğin gibi kullan" der.

Tarayıcıya, mesajlaşma uygulamasına ve Zoom'a aynı söz verildiğinde işletim sistemi üç işleme 4'er GB, toplam 12 GB bellek "satmış" olur; oysa arkada 12 GB RAM yoktur. İşletim sistemi bunu belleği segmentlere bölüp işlemlere atayarak, işlem ek bellek isterse yeni segment ayırarak yönetir. Yani işlemlere gerçek bellek değil bir **sanal adres uzayı** (virtual address space) sunar.

Gerçek ihtiyaç fiziksel belleği aşarsa ne olur? Diyelim ki işlemlerden biri gerçekten 2 GB, diğeri 1,5 GB, üçüncüsü 1 GB kullanmak istedi. Toplam $2 + 1{,}5 + 1 = 4{,}5$ GB eder ve fiziksel 4 GB'a sığmaz. Bu durumda işletim sistemi az kullanılan, az başvurulan bellek parçalarını genellikle dosya sistemine, yani diske taşır. Kaba hatlarıyla bellek yönetimi bu tür problemleri içerir. Kendi uygulamamızı işletim sistemi olmadan yazsaydık verinin bellekten büyük olduğu durumları da kendimiz kodlamak zorunda kalırdık.

## 6. Sistem Programları

İşletim sisteminin içinde donanımın nasıl kullanılacağını tarifleyen ve servis olarak sunan kısımlar (sürücüler) vardır. İşletim sisteminin hemen üzerinde **sistem programları** bulunur. Buradaki "sistem" bilgisayar sistemidir; sistem programları da bu sistemin yönetilmesi ve geliştirilmesi için gereken temel bileşenlerdir.

- **Metin editörü:** İşletim sisteminin herhangi bir yapılandırma dosyasını açıp değiştirebilmek gerekir. En basit sistem programı bir metin editörüdür.
- **Derleyici (compiler):** İşletim sistemi için çalıştırılabilir kod üretir. Önce metin editöründe kod yazılır, sonra derleyiciyle uygulamaya dönüştürülür.
- **Assembler:** İşletim sisteminde çalışacak programların donanım seviyesine çevrilmesini sağlar; ayrıntısı programlama dilleri kısmında anlatıldı.

### 6.1 vi Editörü

Hoca Linux kullananların duymuş olabileceği **vi** editörünü özellikle andı (Roma rakamıyla 6 değil, "vi"). Gelişmiş sürümü (Vim) olsa da merak edenlerin özgün vi'yi denemesini önerdi. vi tamamen metin tabanlıdır, konsolda çalışır. Bir dosyaya girildiğinde her harf bir komuta dönüşür. Düzenleme, görüntüleme, makro gibi farklı çalışma kipleri vardır ve bugünkü gelişmiş editörlerde uzun süren işler vi ile çok hızlı yapılabilir.

vi en eskiye giden ve hâlâ kullanılan editörlerden biridir. Sistem yöneticiliği yapmak isteyen ya da işletim sistemlerine ilgi duyanların yolu mutlaka vi ile kesişir, çünkü sunucularda grafik arayüz genellikle gereksiz bir bileşendir. Hoca'nın deyişiyle "hiçbir şeyin çalışmadığı yerde vi çalışır."

## 7. Bilgisayar Organizasyonu

"Bilgisayar Organizasyonu" slaytında donanımın içi gösterildi (ekrandan, 00:50:00): en solda **CPU**, ardından **disk controller** (disklere bağlı), **USB controller** (mouse, keyboard, printer'a bağlı) ve **graphics adapter** (monitor'e bağlı). Bunların hepsi ortak bir yolla **memory** birimine bağlıdır.

Diskler, klavye, fare, yazıcı ve monitör birer çevre birimidir. Bu birimler belli bir "akla" sahip denetleyiciler (controller) tarafından kullanıma sunulur. Hoca grafik adaptörüne artık "adaptör" değil "denetleyici" demek gerektiğini, şemanın tarihsel olarak eski bir gösterim olduğunu belirtti.

Birimler arasındaki haberleşme bellek üzerinden gerçekleşir. Eski kişisel bilgisayarlarda disk denetleme işi de işlemciye yüklenmişti: işlemci diskteki bilgiyi okuyor, belleğe yazıyor, sonra bu bilgiyle işlem yapıyordu. Bugün ise bir disk G/Ç işlemi başlatılacağında CPU disk denetleyicisine "şu adresteki bilgileri getir, belleğin şuraya yaz" der ve aradan çekilir. Disk denetleyicisi okur ve belleğe yazar.

Bu mimaride dikkat edilmesi gereken nokta, **belleğin darboğaz** (bottleneck) oluşturmasıdır. Her şey belleğe gider ve bellek yolu tektir; CPU dahil bütün denetleyicilerin aynı anda belleğe ulaşması mümkün değildir.

İşi denetleyiciye devretmenin güzelliği, işlemcinin bu sırada boşta olmasıdır. İşlemci verinin okunmasını beklemek zorunda kalmaz, başka işlere ya da hesaplamalara geçebilir. İşletim sistemi açısından bu, "bir işlem G/Ç başlattı, onu kenara koyup başka işleme geçeyim" yaklaşımıdır.

## 8. Bilgisayarların Tarihçesi

Hoca bilgisayarların bir anda bugünkü işlemcilerle ortaya çıkmadığını, ilk gelişmelerin elektronik bile olmayıp mekanik seviyede başladığını vurguladı.

### 8.1 Abaküs ve Babbage'ın Makineleri

İlk bilgisayar olarak mekanik açıdan bakılırsa abaküs gösterilebilir; hoca abaküsün M.Ö. 300'lerde Babil'de kullanıldığını söyledi. Daha modern anlamda ilk bilgisayar sayılabilecek makine **Charles Babbage**'ın **Difference Engine** (Fark Makinesi) adlı makinesidir. Üzerinde bol miktarda çark vardır; her sütundaki her dişli bir basamağı ifade eder ve makine 20-30 basamaklı sayılarla hesap yapabilir. Ancak mekanik hassasiyet ve deformasyon yüzünden yaklaşık 20. basamaktan sonra hatalar oluşabiliyordu. Makine astronomik ve matematik tabloları hesaplamak için yapılmıştı.

Hoca, mekanik ve ilk elektronik makinelerin çoğunlukla karmaşık hesapları yapmak, yani "compute" etmek için ortaya çıktığını, "computer" adının da buradan geldiğini söyledi.

Babbage daha sonra **Analytic Engine** adını verdiği, ev büyüklüğünde ve 6 buhar makinesi tarafından beslenen **programlanabilir** bir cihaz tasarladı; bunun için **punched card** (delikli kart) kullandı (ekrandan, 00:55:00). Hoca "ev büyüklüğü"nün apartman dairesi değil, Amerikan filmlerindeki iki katlı büyük evler gibi düşünülmesi gerektiğini söyledi. Fark Makinesi statik bir işi yapıyordu; başka bir hesap için makineyi yeniden tasarlamak gerekiyordu. Analytic Engine'e ise adım adım ne yapacağı söylenebiliyordu.

Delikli kartlar bilgisayar sistemlerine uzun süre hâkim oldu ve 1960'lara kadar farklı biçimlerde karşımıza çıktı. Bu kartlar hem programlama hem bilgi depolama için kullanılıyordu; cihazda kartları uygun yerlerinden delerek bilgiyi saklayan mekanizmalar da vardı. Hoca'ya göre bu makinelerde ayrı bir bellek yapısı pek yoktur; delikli kartlar disk ile bellek arasında bir yerde duran bir kavramdır. İşlemci ise çarklardır; hangi çarkın ne zaman çalıştığı yapılan işlemi belirler.

### 8.2 İlk Programcı: Ada Byron

Önceki bir derste programlama dillerinin nasıl ortaya çıktığı sorulmuştu. Hoca dünyanın ilk programcısının bir kadın olduğunu söyledi: Babbage'ın arkadaşı **Ada Byron** (Ada Lovelace), programlanabilir Analytic Engine için ilk kodları yazdı. Birçok mesleğin tersine programcılıkta ilk kişi kadındır.

Hoca slayttaki kodun sözdizimini şöyle anlattı: `N1 123` ve `N2 456` gibi satırlar vardı. `N` kartın tipini gösterir; `N1 123` "123 değerini 1 numaralı bellekte sakla" demektir. Her satır için ayrı bir kart hazırlanır: N tipi bir kart seçilir ve üzerine uygun delikler açılır. Üçüncü satır boştur; dizilimde oraya boş bir yorum kartı konur. Ardından toplama işlemi ve `L1`, `L2`, `S3` kartları gelir: birinci adresi yükle (load), ikinci adresi yükle, ikisini topla, sonucu üçüncü adrese yaz (store). Amaç işi modüler hâle getirmektir. <!-- BELİRSİZ: Slayttaki kart dizisinin tam yazımı karede yok (00:57:51-00:59:50 arasında kare alınmamış); burada yalnız altyazıdaki anlatım aktarıldı. -->

Hoca bu sırada işlemci komutlarına da kısaca değindi: işlemci işlemleri genellikle register ve bellek üzerinde yapar, asla doğrudan disk üzerinde yapmaz. RISC mimarisinde komutlar yalnız register'lar üzerinden, CISC mimarisinde register ve bellek adresi üzerinden yürür. Bu konu ilerideki haftalarda işlenecek.

### 8.3 Ateşleme Tabloları ve İnsan Hesaplayıcılar

Hoca her icatta olduğu gibi bilgisayarın da ihtiyaçtan doğduğunu söyledi. Buradaki temel ihtiyaç, savaş zamanında **ordunun ağır silahları için ateşleme tablolarının hesaplanmasıydı** (ekrandan, 01:00:00). Rüzgârın yönü ve şiddeti, kullanılan barut miktarı gibi etkenlere bağlı olarak hangi topun, hangi mermiyle, hangi mevziden, hangi açıyla nereye atış yapabileceği elle hesaplanıyordu. Bir hesap hatası, ansiklopedi gibi hazırlanmış bir tablonun tamamını çöpe atmayı gerektirebiliyordu.

Erkekler askerde olduğu için bu hesapları kadınlar yapıyordu. Bu kişiler üniversitelerin matematik bölümlerinden mezun, nitelikli insanlardı. Daha sonra bilgisayarlar geldiğinde bu kişiler elle yaptıkları hesapları bilgisayara yaptıran operatörler oldular.

### 8.4 ENIAC

"Tarihçe - VI" slaytındaki bilgiler (ekrandan, 01:15:00):

- İlk genel amaçlı bilgisayar: 1946'da U. Penn.'de US Army için **ENIAC**.
- Açılımı: **E**lectronic **N**umerical **I**ntegrator **a**nd **C**alculator.
- Tasarlayanlar: J. Presper Eckert (24 yaşında) ve John Mauchley.
- 30 ton ve 1500 sq. ft.
- 500.000 dolar masraf.
- Veri girişi delikli kartlarla, programlama kabloları ve anahtarları elle değiştirerek.
- Decimal veri ile çalışır.
- Matematiksel hesaplar, hava tahmini ve atom enerjisi hesapları.

> **Ders sonrası not:** Altyazıda tasarımcı adı "Maculay", slaytta "John Mauchley" diye geçiyor; doğru yazımı büyük olasılıkla John Mauchly'dir.

Hoca "genel amaçlı" ifadesinin, istenen matematik hesabının yapılabilmesi anlamına geldiğini söyledi. Programlama farklı işlemlere ait birimlerin kablolarla birbirine bağlanmasıyla yapılıyordu.

### 8.5 İlk Elektronik Bilgisayar: ABC

Hoca ilk elektronik bilgisayarın 1939'da Atanasoff tarafından geliştirilen **ABC** olduğunu söyledi. Savaş yılları yüzünden maddi destek bulamayınca prototip uzun süre kenarda kaldı. Slayttaki fotoğraf özgün makine değil, Iowa State Üniversitesi'nde müzede sergilenmek üzere yeniden yapılmış bir kopyaydı. Bu makinede de programlama kablolarla yapılıyordu.

> **Ek bilgi (derste anlatılmadı):** ABC'nin açık adı büyük olasılıkla Atanasoff–Berry Computer'dır; John Atanasoff bu makineyi öğrencisi Clifford Berry ile birlikte geliştirmiştir.

### 8.6 Kablolarla Programlama ve Operatör Konsolu

O yıllarda bir bilgisayar sistemi birkaç katlı bir bina gibi düşünülebilir. Hangi işlemin ne zaman yapılacağı, çıktısının nereye yönlendirileceği ve sonraki işlemin ne olacağı kablolamayla belirleniyordu. Bu işi yapan kişilere **operatör** denirdi. Slayttaki fotoğrafta (ekrandan, 01:20:00) elinde talimatlar olan bir kişi, diğerine hangi bağlantıyı nereye yapması gerektiğini tek tek söylüyordu; programlama bu şekilde yapılıyordu.

Operatörün oturup sistemi denetlediği masaya **operatör konsolu** denirdi; terim buradan gelir. Bugün bir web servisini yönetiyorsak operatör konsolu, işlerin hangi aşamada olduğunu gösteren web tabanlı bir arayüzdür. Gelişmiş kurumsal depolama donanımlarında bakım konsolu çoğu zaman bir dizüstü bilgisayardır.

## 9. Mainframe Bilgisayarlar

Bu ilk sistemlerin ardından **mainframe**'ler geldi: disk birimi, bellek, işlemci gibi her bileşeni büyük kasalar hâlinde olan, oda, ev ya da bina büyüklüğüne ulaşabilen makineler. Elektronikteki gelişmelerle bir zamanlar oda büyüklüğündeki işlemci birimi bugün birkaç santimetrekareye sığıyor; bilgisayarlar bu yüzden küçüldü.

En bilinen mainframe üreticisi IBM'dir. Bir dönem IBM ve diğer üreticiler "IBM ve yedi cüceler" diye anılıyordu, çünkü diğerleri ya belirli bileşenleri üretiyor ya da çok daha küçük pazar paylarına sahipti. "Mainframe Bilgisayarlar - II" slaytında şu bilgiler vardı (ekrandan, 01:25:00):

- 1970'lerin başında piyasadaki küçülme şirket sayısını azaltmıştır.
- 1980'lerde mini bilgisayarlar etkin olmaya başlamıştır.
- 2012'de NASA son mainframe bilgisayarını kapatmıştır.
- IBM hâlen mainframe üretimine devam etmektedir: 2016 Şubat'ta z13s, 2017 Temmuz'da z14 tanıtıldı.

Hoca NASA'nın uzay mekiklerinin dönüş hesaplarında elle hesaptan IBM mainframe'ine geçtiğini anlattı. IBM'in slayttan sonra yeni bir mainframe daha tanıttığını da ekledi; mainframe'ler kolay kolay ortadan kalkmayacaktır, çünkü birçok teknolojinin başlangıcıdır. Örneğin bugün kullandığımız sanallaştırma teknolojisi ilk kez iyi biçimde mainframe'lerde, büyük olasılıkla 1970'lerin sonunda uygulanmıştır.

### 9.1 Yüksek Erişilebilirlik (High Availability)

Mainframe'ler kesintisiz çalışabilmeleri ve kesintide veri kaybetmemeleri yüzünden tercih ediliyordu. Hoca bunun nasıl sağlandığını anlattı:

- İşlemci biriminde bugün en az iki işlemci birimi ve yüzler mertebesinde (300-500) çekirdek vardır. Soğutma fanla değil gazlı ya da sıvılı sistemle yapılır.
- Cihazın en az dört elektrik girişi farklı kaynaklara bağlanır. Bir ya da iki kaynak giderse cihaz çalışmaya devam eder.
- Bütün fişler çekilse bile işlemcinin pil yedeği vardır. İşlemci güç kaynağının gittiğini anlar, elindeki işleri tamamlar, yeni iş almaz, önbellekte ve bellekte veri bırakmamak için her şeyi yazmaya başlar; yani kendini düzgün kapatmaya hazırlar.
- Depolama biriminde bir değil iki ya da dört denetleyici vardır. Her disk grubunun altında da pil yedeği bulunur; diskin fişi çekilse bile diske yazılmayı bekleyen önbellek verisi diske yazılır.

Her bileşen bağımsız bir kutudur ve elektrik kesintisinde ya da donanım arızasında kendini kurtarabilecek biçimde yapılmıştır. Bu yüzden mainframe'ler pahalı ve niş ürünlerdir. Bugün daha çok sayıda ucuz bilgisayarla geniş yapılar kurma yoluna gidilmektedir.

### 9.2 Delikli Kartlardan Terminallere

Mainframe'lerde de delikli kartlar (punch card, punch paper) kullanıldı. Slaytta iki örnek kart vardı (ekrandan, 01:35:00). Kartlar zaman zaman çıktı üretmek için, çoğu zaman da programı bilgisayara vermek için kullanılıyordu. Hoca kart okuyucuyu bankadaki para sayma makinesine benzetti: bir deste para makineye konur, makine döner ve kaç banknot olduğunu söyler. Benzer biçimde kod kartlar delinerek hazırlanır, sıraya dizilir, makine okur ve ne yapacağını bilir. Zamanla mainframe'ler kablolardan terminallere (klavye, ekran) doğru evrildi.

"Mainframe Bilgisayarlar - III" slaytında IBM Stretch (1959) makinesinin genel görünümü ve operatör konsolu gösterildi (ekrandan, 01:30:00). Hoca IBM 7094 ile IBM z13'ü karşılaştırdı: eski makine bütün bir kata yayılmıştı (teyp birimleri, yazıcılar, depolama), z13'te ise yalnız işlemci kasası görünüyordu.

### 9.3 Kişisel Bilgisayarlara Geçiş

Teknolojinin gelişmesi bilgisayarların küçülmesi ve günlük kullanıma girmesi demekti. İlk kişisel bilgisayarlardan biri olarak 1965'te Olivetti'nin ürettiği **Programma 101** anıldı; fiyatı 3200 dolardı. Ardından Apple gibi sınırlı kapasiteli kişisel bilgisayarlar geldi. Mainframe'leri küçültüp sahada kullanılabilir hâle getiren gelişmeler de oldu. Hoca örnek olarak DEC'in **PDP** (Program Data Processor) serisini andı: işlemcisi, depolaması ve operatör konsolu tek bir kasada olan, saha testlerinde ve sensör uygulamalarında kullanılmış kompakt makineler. <!-- BELİRSİZ: Altyazıda "PDP13" geçiyor; hangi PDP modelinin kastedildiği karede doğrulanamadı. -->

> **Ders sonrası not:** PDP'nin açılımı büyük olasılıkla "Programmed Data Processor"dır; altyazıda "Program Data Processor" geçiyor.

Hoca bugün elimizdeki herhangi bir tablet ya da telefonun bu makinelerden çok daha fazla işlem gücüne sahip olduğunu söyledi.

## 10. Donanım Neden Bu Kadar Farklı Fiyatlı?

Hoca öğrencilere 2 TB'lık bir diskin, özellikle SSD'nin fiyatını sordu; öğrenciler 1500-2000 TL dedi. Sonra bir sunucu üreticisinin "full flash" depolama birimi diskinin fiyatına bakmalarını istedi; bulunan fiyat yaklaşık 15.350 TL idi. Aradaki yaklaşık 7 katlık farkın birkaç nedeni vardır.

Donanım derslerinde bileşenlerin veri sayfalarını (datasheet) okumayı öğrenince görüleceği gibi, bir transistörün, diyotun, hatta direncin bile bir hassasiyeti ve çalışma aralığı vardır. Bir transistör 20-65 derece, 0-80 derece ya da -20 ile +150 derece aralığında çalışacak şekilde üretilmiş olabilir ve bunlar farklı değerlendirilir.

- Sunucu diskleri 7/24 kesintisiz çalışmak üzere tasarlanır. Masaüstündeki SSD ya da dönen diskler öyle tasarlanmaz. SSD'lerin yaklaşık 4-5 yıllık bir ömrü vardır; daha uzun ömürlü olanı alınmak istenirse fiyat 2000 TL'den 5000-6000 TL'ye çıkabilir.
- Masaüstü ve dizüstü bilgisayarlardaki dönen disklerin hızları düşüktür: 4500 RPM'den başlar, 7200 RPM'e, en fazla 10.000 RPM'e çıkar. Ne kadar hızlı dönerse o kadar güç harcar ve ısı üretir.
- Sunucularda dönüş hızı 7200'den başlar, daha çok 10.000 ve 15.000 RPM görülür. Bu diskler daha çok kafa ve silindir içerir. Bir masaüstü disk yaklaşık 1 amper çekerken sunucu diski 4 amper çekebilir; farklı beslenmesi ve farklı soğutulması gerekir.

> **Ders sonrası not:** Dizüstü dönen disklerde yaygın devirler büyük olasılıkla 4200 ve 5400 RPM'dir; altyazıda alt sınır "4500 RPM" diye geçiyor.

Kısacası üretim mantığı, kullanılan malzeme ve sonucun kalitesi fiyatı belirler. Hoca bunu "ucuzdur vardır illeti, pahalıdır vardır hikmeti" sözüyle özetledi.

## 11. Yazılım Türleri

Hoca yazılımları iki gruba ayırdı:

- **Sistem yazılımı:** Bilgisayar sistemini kullanmamızı sağlayan, işletim sistemiyle iç içe (tightly coupled) çalışan yazılımlardır. İşletim sisteminin yapılandırma dosyasını düzeltmek için editör, ona komut vermek için kabuk (shell, komut satırı), onun için yazılan kodu derlemek için derleyici gerekir; bunların hepsi sistem yazılımıdır.
- **Uygulama yazılımı:** Hocanın o anda kullandığı sunum programı ya da internette gezmek için kullanılan tarayıcı gibi yazılımlardır.

Bu yazılımların ortaya çıkabilmesi için programlama dillerine ihtiyaç vardır.

## 12. Programlama Dillerinin Nesilleri

Programlama dilleri birçok şekilde sınıflandırılabilir. Hoca tarihsel gelişimi görmek için nesillere göre bakmanın yararlı olduğunu söyledi.

### 12.1 Birinci Nesil: Makine Kodu

"Birinci Nesil – Makine Kodu" slaytı (ekrandan, 01:40:00): komutlar 0 ve 1 kullanılarak ifade edilir. Örnek olarak iki sayının toplanması için makine kodu verildi:

```text
000000 00001 00010 00110 00000 100000
```

Hoca slaytta "iki sayısının" değil "iki sayının" yazması gerektiğini düzeltti. Bu 32 bitlik bir komuttur (instruction) ve iki sayının toplanacağını söyler; hangi alanın ne anlama geldiği register ve bellek kavramları işlendikten sonra konuşulacak. İlk makinelerde decimal sistem kullanılsa da sonra ikili (binary) sisteme geçildi; ikilinin onluğa ya da onaltılığa göre artısı ve eksisi ilerideki derslerde konuşulacak.

> **Ek bilgi (derste anlatılmadı):** Bu bit dizisi büyük olasılıkla MIPS mimarisindeki R tipi bir komuttur. Alanlar soldan sağa işlem kodu (6 bit, 000000), rs (00001 = 1), rt (00010 = 2), rd (00110 = 6), kaydırma miktarı (00000) ve fonksiyon kodu (100000 = add) olarak okunur; yani 1 ve 2 numaralı register'ları toplayıp sonucu 6 numaralı register'a yazar. Toplam uzunluk $6+5+5+5+5+6 = 32$ bittir (Python ile sayıldı).

Makine koduyla bugün de program yazmak mümkündür, ama hiç "insansı" değildir. 8, 16 ya da 32 tane 0 ve 1'den oluşan bir komutu doğru yazıp yazmadığınızı kontrol etmek bile, belli bir sistematik izlense de kolay değildir. "Bunu daha anlaşılır seviyeye getirebilir miyiz?" sorusundan yola çıkıldı.

### 12.2 İkinci Nesil: Assembly Dilleri

İlk geliştirilen diller **assembly** dilleridir. Programlama dilinin adı assembly, bu dilde yazılmış kodu makine koduna çeviren yapının adı **assembler**dır. "İkinci Nesil – Assembly Diller" slaytı (ekrandan, 01:45:00): bilgisayar yalnız makine kodunu işleyebilir; assembly dilinde yazılmış programın makine koduna çevrilmesi gerekir; çevirme işlemi assembler tarafından yapılır.

```text
Assembly kodu  -->  Assembler  -->  Makine kodu
```

Assembly dilinde basit İngilizce kısaltmalar kullanılır. İki sayıyı toplamak için `ADD`, bir değeri bir yerden bir yere taşımak (sabit bir değeri register'a atamak ya da bir bellek konumunu register'a almak) için "move" kelimesinin kısaltması `MOV` kullanılır. PowerPC gibi mimarilerde taşıma işi **load** (bellekten register'a) ve **store** (register'dan belleğe) komutlarıyla yapılır.

Her işlemci ailesinin ayrı bir assembly dili vardır. Intel mimarisindeki işlemcilerin (8086, 686) assembly dili ile RISC mimarisindeki PowerPC gibi işlemcilerin assembly dili farklıdır; komutların adları ve yapabildikleri farklıdır. İşlemcinin yalnız veri ve adres bacakları vardır; ona yalnız 0-1 sinyalleriyle ne yapacağı söylenebilir. Bu yüzden assembly kodunun sonunda birinci nesil 0-1'lere dönüşmesi gerekir.

Hoca ileride alınacak assembly dersinin keyifli ama hiç kolay olmadığını, bugünkü programlama mantığından çok farklı olduğunu ve dikkat edilecek çok şey içerdiğini söyledi.

### 12.3 Üçüncü Nesil: Yüksek Seviyeli Diller

Assembly makine diline göre kolay olsa da hâlâ zordur. Ayrıca farklı mimari farklı komut demektir; bir kodu başka mimariye taşımak yeni bir dil öğrenmeyi gerektirir. Bu yüzden işi bir seviye yukarıda, İngilizce komutlarla yapmak istendi. Böylece 1950-1970 arasında COBOL, Fortran, Pascal ve C ortaya çıktı; Java da bu gruba girer. C bu derste ve sonraki programlama derslerinde işlenecek.

### 12.4 Nesneye Dayalı Programlama

Yazılımlar büyüyüp karmaşıklaştıkça ve yalnız matematik hesabının ötesine geçtikçe (stok kontrol programları, ERP, CRM) başka bir modülerlik gerekti ve **nesneye dayalı programlama** kavramı ortaya atıldı. Hoca bunun başlangıcını 1967 olarak verdi. Slaytta 1995'e kadar olan diller vardı; sonra da birçok nesneye dayalı dil çıktı.

### 12.5 Yorumlayıcı (Interpreter)

Sonra farklı bir fikir ortaya çıktı: programı derleyip sonra çalıştırmak yerine, yazılanın anında çalıştırılabileceği bir yapı kurulabilir mi? "Yorumlayıcı (Interpreter)" slaytı (ekrandan, 01:50:00):

- Program bir seferde değil satır satır derlenir: bir satır çalıştırıldıktan sonra bir sonraki satır çalıştırılır.
- Pek çok programlama dili hem derleyici hem yorumlayıcı ile çalışabilir.
- Yorumlayıcı ile çalışan diller: Basic, Lisp, MATLAB, SmallTalk ...

### 12.6 Yeni Bir Dil Bilgisayara Nasıl "Tanımlanır"?

**Soru:** Yeni bir dil yazıldığında, örneğin Türkçe komutlu bir dil oluşturulsa, bu dil bilgisayarda nasıl işlevsel hâle getirilir?

**Cevap:** Hoca önce Türkçe komutlu bir programlama dili oluşturup yaygınlaştırmaya çalışmanın kendi gözünde çok verimli bir çaba olmadığını, nedenini başka bir zaman anlatacağını söyledi. Sonra kendi adından uydurduğu bir dil örneğiyle cevap verdi. Bir dilin önce bir tasarımı olmalıdır: hangi komut nerede ve nasıl kullanılacak, anahtar kelimeler neler olacak, sözdizimi kuralları nasıl belirlenecek. Derleyicinin nasıl çalışacağı ve arkasındaki durum makinesinin nasıl kurulacağı, dördüncü sınıftaki **Derleyici Tasarımı** dersinde işlenir.

Dil tasarlandıktan sonra bilgisayara "ben böyle bir dil geliştirdim" diye bir şey anlatılmaz. Derleyici, dilin kurallarına göre yazılmış kodu bulunduğu mimarinin (örneğin Intel 686) anlayacağı makine koduna, yani 0-1'lere çevirir. Arada işletim sistemi de olduğu için çıktı işletim sisteminin kurallarına da uygun olmalıdır. Aynı dil PowerPC'de çalışacaksa derleyicinin PowerPC sürümü yazılmalıdır.

Diğer yol **cross compiler**dır: A mimarisinde çalışan derleyicinin B mimarisi için çıktı üretmesi. Örneğin mikrodenetleyici için kod PC'de yazılır, ama derleyiciye "bu kodu ARM tabanlı şu mikrodenetleyici için derle" denir. Bu çıktı, bir emülatör ya da simülatör olmadan PC'de çalıştırılamaz; yalnız mikrodenetleyiciye aktarıldığında çalışır. Buna **cross-compilation** denir.

### 12.7 Dördüncü Nesil: Özel Amaçlı Diller

Bilgisayar sistemleri geliştikçe çok miktarda bilgi üretildi ve bu bilgiyi saklamak için veritabanları kuruldu. Bilginin veritabanına konması, sonra tekrar çekilip işlenmesi için de diller üretildi. **SQL** bir sorgu dili olarak geçse de içinde komutlarla periyodik çalışacak ve bazı şeyleri denetleyecek yapılar kurulabildiği için bir programlama dili gibidir. Dördüncü nesil bu tür dilleri kapsar: bir dönem popüler olan rapor üretme dilleri, yapısal veritabanlarını sorgulamak için hâlâ yaygın kullanılan SQL, raporlama, analiz ve veri işleme için PL/SQL ve MATLAB gibi diller.

### 12.8 Beşinci Nesil: Belirli Amaca Yönelik Diller

Beşinci nesil tamamen belli bir amaca yönelik geliştirilmiş dillerdir. Örneğin Simulink gibi, kutuları sürükleyip bırakarak ve aralarındaki çizgileri bağlayarak çalışılan diller; ya da yapay zekâ ve doğal dil işlemede kullanılan Prolog ve Lisp gibi diller. Bunlarla her şey yazılamaz; örneğin metin üzerinde çalışmak için tasarlanmış bir dille ERP programı yazılmaz. Bu yüzden bunlara kısıtlı diller denir. <!-- BELİRSİZ: Altyazıda bu grupta "lep", "merkez", "risk" gibi bozuk dil adları da geçiyor; hangi diller olduğu karede doğrulanamadı. -->

## 13. Sayı Sistemlerine Giriş

İkinci sunumun "İçerik" slaytında (ekrandan, 02:05:00) konular şöyle sıralanmıştı: sayı sistemleri (Binary, Octal, Decimal, Hexadecimal) ve operatörler (aritmetik operatörler, mantıksal (logic) operatörler, bitwise operatörler).

Hoca sayı sistemlerinden en az ikisinin çok rahat kullanılabilmesi gerektiğini söyledi:

> **Hocanın vurgusu:** Günümüzde bütün bilgisayar sistemleri ikili (binary) sistemi kullanır; bu yüzden ikili sisteme hâkim olmak gerekir. Ondalık sistem de günlük hayatta kullanılır. İkili ve ondalık, iyi bilinmesi gereken en az iki sayı sistemidir.

Bunlara ek olarak programlama dillerinde onaltılı (hexadecimal) sistem de sık görülecek. 32 ya da 64 bitlik sayıları ikili ya da ondalık yerine onaltılı yazmak hem kısa hem okunaklı hem de anlaşılır olur. Bu sayılar bazen bir adresi, bazen de sayının kendisini belirtmek için yazılır.

Operatörler de işlemler demektir: aritmetik işlemler, mantıksal işlemler ve ikili sistemde basamaklara (bitlere) uygulanan bit işlemleri.

## 14. İkili, Sekizli, Ondalık ve Onaltılı Sistemler

### 14.1 İkili (Binary) Sayı Sistemi

İkili sistem teknik olarak ondalık sisteme benzer. Ondalık sistemde 0-9 rakamları kullanılır; 10'a gelindiğinde onlar basamağına geçilip oraya 1 yazılır. İkili sistemde yalnız 0 ve 1 vardır; 2 yazmak için ikiler basamağına geçilir, yani 2 sayısı "10" diye yazılır. Toplamada da elde mantığı aynıdır: alt alta gelen hanelerin toplamı 2 ya da daha fazla olursa bir sonraki haneye aktarılır.

"İkili (Binary) Sayı Sistemi" slaytı (ekrandan, 02:10:00):

- İkili sayı sisteminde sadece 0 ve 1 rakamları kullanılır. İki sayısı «10» şeklinde ifade edilir. Ondalık sayı sisteminde olduğu gibi toplamın iki olması durumunda bir sonraki haneye aktarılır.
- İkili sayı sistemindeki sayıların yazımı **genellikle** ondalık sisteme göre daha uzundur. Bunun temel nedeni ikilik sistemde her hanenin onluk sisteme göre daha az bilgi ifade edebilmesidir. Bundan dolayı ikilik sistemdeki hanelere **bit** adı verilir.

Basamak değerleri 1, 2, 4, 8 diye gider. Dört basamağın hepsi 1 olduğunda ifade edilebilen en büyük değer $1+2+4+8 = 15$'tir. Ondalık sistemde 15'i yazmak için iki basamak yeter.

### 14.2 Sekizli (Octal) Sayı Sistemi

Sekizli sistemde 0 ve 1'in yanında 2, 3, 4, 5, 6 ve 7 de kullanılır. Sekizli sistemdeki her hane ikili sistemde üç haneye karşılık gelir. Sekizli sistemin hâlâ çalışma alanımızda olmasının nedeni, bazı sistemlerin yapısının bunun üzerine kurulmuş olmasıdır: PDP-8 ve bazı IBM mainframe'leri sekizli sistemi varsayılan olarak kullanıyor ya da destekliyordu. PDP-8 12 bitlik bir makineydi.

> **Ek bilgi (derste anlatılmadı):** 12 bitlik bir sözcük tam olarak dört sekizli haneye ($4 \times 3 = 12$ bit) bölünür; PDP-8 gibi makinelerde sekizli gösterimin doğal olmasının nedeni büyük olasılıkla budur.

### 14.3 Ondalık (Decimal) Sayı Sistemi

"Ondalık (Decimal) Sayı Sistemi" slaytı (ekrandan, 02:15:00):

- Hindu Arabic, Arabic olarak da bilinir. 10 farklı rakam kullanılır: 0, 1, 2, 3, 4, 5, 6, 7, 8 ve 9.
- Kesirli sayıların gösterimi için **nokta işareti** kullanılır.
- Ondalık sayı sisteminde 543.21 sayısı şöyle değerlendirilir:

$$543.21 = (5\times10^2) + (4\times10^1) + (3\times10^0) + (2\times10^{-1}) + (1\times10^{-2})$$

Her basamak 10'un bir kuvvetini ifade eder: birler, onlar, yüzler, binler... Noktadan sonra kesirli kısım $10^{-1}, 10^{-2}$ diye devam eder.

> **Hocanın vurgusu:** Türkçe yazımda kesir ayırıcı olarak virgül görülse de matematik standardında nokta kullanılır. Kesirli sayılar ilerde floating point ve fixed point olarak işlenecek ve iş hep noktadan dönecek; bu yüzden virgül ile nokta karıştırılmamalıdır.

### 14.4 Onaltılı (Hexadecimal) Sayı Sistemi

Her sayı sisteminde, sistemin adındaki sayının bir eksiğine kadar rakam kullanılır: onluda 9'a, sekizlide 7'ye, ikilide 1'e kadar. Onaltılı sistemde 10'u tek başına ifade eden bir rakam yoktur; harflerden yararlanılır: A=10, B=11, C=12, D=13, E=14, F=15. Sekizli sistem ikili sistemdeki üç haneyi bir arada ifade ediyordu; onaltılı sistem de doğal olarak ikili sistemdeki **dört haneyi** tek seferde ifade eder.

"Onaltılık (Hexadecimal) Sayı Sistemi" slaytı (ekrandan, 02:20:00):

- Onaltılık sayı sisteminde sayıların ifade edilmesi için 16 değere ihtiyaç vardır. Bunun için 10 rakam (0-9) ve 6 harften (A, B, C, D, E ve F) yararlanılır.
- Hanelerin kullanımı ondalık sayı sistemi ile aynıdır.
- Ondalık sayı sisteminde 256,058 sayısı ikilik sayı sisteminde «11 1110 1000 0011 1010», sekizlik sayı sisteminde «764072», onaltılık sayı sisteminde «3E83A» şeklinde yazılır.

Slaytta bu sayı "256,058" diye, binler ayırıcısı olarak virgülle yazılmıştı; sayı iki yüz elli altı bin elli sekizdir. Hoca ikiliden onaltılıya çevirmeyi sağdan sola dörder bitlik gruplarla gösterdi:

- En sağdaki grup $1010$: birler basamağı 0, ikiler 1, dörtler 0, sekizler 1; $8+2 = 10$, onaltılıda **A**.
- Sonraki grup $0011$: $1+2 = 3$, yani **3**.
- Sonraki grup $1000$: yalnız sekizler basamağı dolu, yani **8**.
- Sonraki grup $1110$: $8+4+2 = 14$, yani **E**.
- Son grup $11$: $1+2 = 3$, yani **3**.

Sonuç soldan sağa $3E83A_{16}$'dır. Sekizliye çevirmek için aynı sayı sağdan üçerli gruplara ayrılır (ara adım eklendi): $111\,110\,100\,000\,111\,010$, yani $7\,6\,4\,0\,7\,2$ ve $764072_8$. Üç gösterim de Python ile kontrol edildi.

## 15. Sayı Sistemleri Arasında Geçiş

### 15.1 Onluktan İkiliye: Bölme Yöntemi Yerine Pratik Yol

Okulda öğretilen yöntemde sayı ikiye bölünür, bölüm tekrar ikiye bölünür ve bu, sayı ikiye bölünemeyecek hâle gelene kadar sürer; son bölüm ve kalanlar tersten dizilir. Slaytta bu yöntemle bir örnek gösterildi.

> **Hocanın vurgusu:** Onluktan ikiliye çevirme istendiğinde bu bölme hesabının yapılması beklenmiyor; o hesap ortaokulda ya da lisede kaldı. Çevirme daha pratik, temiz ve net yollarla yapılmalı.

Pratik yol, basamak değerlerini bilmektir. İkili sistemde sağdan sola her bitin değeri 1, 2, 4, 8, 16, 32, 64, 128, 256 diye gider. Ondalık sistemde 1'in sağına bir sıfır eklenince 10, bir daha eklenince 100 olur; her basamak 10 katına çıkar. İkili sistemde her basamak 2 katına çıkar. Sekiz bitin önüne bir bit daha eklenip 1 yazılırsa o bit 256'yı ifade eder.

Hoca 195 sayısını chat üzerinden adım adım gösterdi:

- 256, 195'ten büyük olduğu için 195'in içinde yoktur; 128 vardır. 128 basamağına 1 yazılır. $195 - 128 = 67$.
- 67'nin içinde 64 vardır. 64 basamağına 1 yazılır; şimdiye kadar $128 + 64 = 192$ ifade edildi. $67 - 64 = 3$.
- 32, 16, 8 ve 4'ün hepsi 3'ten büyüktür; bu basamaklar 0 olur.
- Kalan 3, $2 + 1$ olarak yazılır; 2 ve 1 basamaklarına 1 yazılır.

Sonuç: $195_{10} = 1100\,0011_2$. Bölme yöntemi de aynı sonucu verir; Python ile kontrol edildi.

**Soru:** Sondaki 1 nereden geliyor?

**Cevap:** $67 - 64 = 3$ kalır. 3'ten önce bir sonraki basamak olan 2 çıkarılır, kalan 1 için birler basamağı kullanılır ve kalan 0 olur. Yalnız 2 basamağı yazılırsa $1100\,0010_2 = 194$ elde edilir; 195 için birler basamağı da 1 olmalıdır: $1100\,0011_2 = 195$.

**Soru:** Dokuzlu gibi başka bir tabandan ikiliye nasıl geçilir?

**Cevap:** Bilgisayar sistemlerinde taban ikili olduğu için dokuzlu sisteme geçme ihtiyacı pek olmaz; bilgisayar mühendisliği kitaplarında dokuzlu sistemden söz edilmez. Gerekirse dokuzlu sayı önce onluya, sonra ikiliye çevrilir; ikiliden dokuzluya geçerken de önce onluya geçilir. Doğrudan geçiş pek mümkün değildir. İkili ile sekizli ve onaltılı arasındaki doğrudan geçiş, 8 ve 16'nın 2'nin kuvveti olmasından gelir.

### 15.2 Sekizli ve Onaltılı Gruplama

"Sayı Sistemleri Arasında Geçiş" slaytı (ekrandan, 02:25:00):

- İkilik, sekizlik ve onaltılık sayı sistemleri arasındaki geçişler daha pratik şekillerde yapılabilir.
- Sekizlik sistemdeki her hane, ikilik sistemdeki **üç haneye** karşılık gelir: «1 000 010 111 100 011», «173».
- Onaltılık sistemdeki her hane, ikilik sistemde **dört haneye** karşılık gelir: «1000 0101 1110 0011», «A09C».

Hoca slaytı anlatırken sekizlik ve onaltılık karşılıklarda hata olduğunu fark etti ve öğrencilerden bu karşılıkları dikkate almamalarını istedi. Slayttaki iki ikili gösterim aslında aynı sayıdır; biri üçerli, biri dörderli gruplanmıştır.

Hoca onaltılı karşılığı derste chat üzerinden doğru biçimde buldu: $1000 = 8$; $0101$'de 1 ve 4 basamakları dolu, yani $5$; $1110$'da 8, 4 ve 2 dolu, yani $14 = E$; $0011$'de 2 ve 1 dolu, yani $3$. Sonuç $85E3_{16}$'dır.

> **Ders sonrası not:** Slayttaki "173" ve "A09C" yanlıştır. Python ile kontrol edildi: $1\,000\,010\,111\,100\,011_2 = 102743_8$, $1000\,0101\,1110\,0011_2 = 85E3_{16}$ ve sayının ondalık değeri $34275$'tir.

Sekizliye çevirme için hoca sayıyı üçerli gruplarla yeniden yazdı ve en soldan başlayarak okumaya başladı; ancak çözüm derste sesli olarak tamamlanmadı (çözüm Örnek Sorular bölümünde).

## 16. Bit, Nibble, Byte ve Word

**Soru:** İkili sayılar neden dörderli yazılıyor?

**Cevap:** Okunabilirlik için. Her ikili basamağa bit denir. 8 bit bir araya gelince **byte**, 16 bit **word**, 32 bit **double word** denir. 16 ya da 32 bit bitişik yazıldığında kaç bit olduğu ve hangi bitlerin 1 olduğu takip edilemez. Genel standart bitleri dörderli ayırmaktır. Böylece her boşluğun 4 bit ötede olduğu bilinir ve 12., 16. gibi belirli bitler kolayca bulunur. Bu dörtlü gruplara **nibble** denir. Her nibble onaltılı sistemde bir haneye karşılık gelir; dörderli yazılan bir sayı onaltılıya da kolayca çevrilir.

> **Ek bilgi (derste anlatılmadı):** Byte'ın 8 bit olması bugün evrenseldir, ama "word" uzunluğu mimariye göre değişir. 16 bit word ve 32 bit double word adlandırması büyük olasılıkla x86 geleneğinden gelir; başka mimarilerde word 32 ya da 64 bit olabilir.

**Soru:** İkili ve onaltılı sayılar nasıl okunmalı?

**Cevap:** İkili sayılar yazıldığı gibi, dörderli gruplar hâlinde okunmalıdır. Bitleri tek tek art arda okumak takip edilemez; "0010, boşluk, 1101" gibi gruplar hâlinde okumak daha anlaşılırdır. Onaltılı sayılarda ikişer ikişer okumak çoğu zaman daha iyidir. Sekizli sistem çok yaygın olmadığı için hoca kesin bir şey söylemedi; tek tek ya da ikişer okunabilir.

Dersin sonunda aritmetik operatörler slaytı açıktı (toplama +, çıkarma -, çarpma *, bölme /, mod) (ekrandan, 02:45:00); operatörler ve sayı sistemleri arasındaki geçişler bir sonraki derste sürecek.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:20:21): Bilgisayarlarda işletim sistemi neden vardır?

> **Çözüm (derste verildi):** İşletim sistemi olmasaydı her uygulama, kullandığı bütün çevre birimlerinin sürücülerini kendi içinde taşımak zorunda kalırdı. İşletim sistemi donanımı sürücüler aracılığıyla servis olarak sunar, birbirinden yalıtılmış birden fazla uygulamayı aynı anda çalıştırır ve bir kaynak yöneticisi olarak işlemci zamanını (G/Ç bekleyen işlemi kenara alarak) ve belleği (sanal adres uzayı, diske taşıma) verimli kullandırır.

**Soru 2** (derste sözlü, 00:44:43): Tek işlemcide 30 birimlik ve 3 birimlik iki iş var. Sırayla çalıştırma ile her işe 2'şer birim veren dönüşümlü çalıştırma kısa iş açısından nasıl karşılaştırılır?

> **Çözüm (derste verildi, ara adımlar eklendi):** Sırayla çalıştırmada kısa iş 30 birim bekler ve 33. birimde biter. Dönüşümlü çalıştırmada uzun iş 0-2, kısa iş 2-4, uzun iş 4-6, kısa iş 6-7 aralığında çalışır; kısa iş ikinci payında, 7. birimde tamamlanıp sistemden çıkar. Uzun iş yine 33. birimde biter.

**Soru 3** (derste sözlü, 00:36:28): 4 GB fiziksel belleği olan bir sistemde üç işleme 4'er GB sanal adres uzayı verilmiş; gerçek ihtiyaçları 2 GB, 1,5 GB ve 1 GB oluyor. Ne olur?

> **Çözüm (derste verildi):** İşlemlere toplam $3 \times 4 = 12$ GB sanal bellek sözü verilmiştir. Gerçek toplam ihtiyaç $2 + 1{,}5 + 1 = 4{,}5$ GB olup fiziksel 4 GB'ı aşar. İşletim sistemi az kullanılan bellek parçalarını diske taşıyarak durumu yönetir.

**Soru 4** (ekrandan, 02:10:00; derste sözlü 02:09:45): Dört bitlik bir ikili sayının ifade edebileceği en büyük değer nedir?

> **Çözüm (derste verildi):** Dört bitin hepsi 1 olduğunda $1111_2 = 8+4+2+1 = 15$.

**Soru 5** (ekrandan, 02:15:00): 543.21 sayısını basamak değerleriyle yazınız.

> **Çözüm (slaytta verildi):** $543.21 = (5\times10^2) + (4\times10^1) + (3\times10^0) + (2\times10^{-1}) + (1\times10^{-2}) = 500 + 40 + 3 + 0.2 + 0.01$.

**Soru 6** (ekrandan, 02:20:00): $256058_{10}$ sayısını ikili, sekizli ve onaltılı sistemde yazınız.

> **Çözüm (slaytta ve derste verildi, Python ile kontrol edildi):** $256058_{10} = 11\,1110\,1000\,0011\,1010_2$. Dörderli gruplar sağdan $A, 3, 8, E, 3$ verir: $3E83A_{16}$. Üçerli gruplar $111\,110\,100\,000\,111\,010$ verir: $764072_8$.

**Soru 7** (derste sözlü, 02:22:37): 195 sayısını bölme yöntemi kullanmadan ikili sisteme çeviriniz.

> **Çözüm (derste verildi):** $195 - 128 = 67$, $67 - 64 = 3$, $3 = 2 + 1$. 128, 64, 2 ve 1 basamakları 1, diğerleri 0: $195_{10} = 1100\,0011_2$.

**Soru 8** (ekrandan, 02:25:00; derste sözlü 02:39:24): $1000\,0101\,1110\,0011_2$ sayısını onaltılı sisteme çeviriniz.

> **Çözüm (derste verildi):** $1000 = 8$, $0101 = 5$, $1110 = E$, $0011 = 3$; sonuç $85E3_{16}$. Slayttaki "A09C" yanlıştır.

**Soru 9** (ekrandan, 02:25:00; derste sözlü 02:41:33): $1\,000\,010\,111\,100\,011_2$ sayısını sekizli sisteme çeviriniz.

> **Çözüm (derste verilmedi):** Sağdan üçerli gruplar: $011 = 3$, $100 = 4$, $111 = 7$, $010 = 2$, $000 = 0$, en soldaki $1 = 1$. Sonuç soldan sağa $102743_8$'dir. Slayttaki "173" yanlıştır. Python ile kontrol edildi: sayının ondalık değeri $34275$'tir ve $34275_{10} = 102743_8$.

## Dersin Toparlaması

Ders, bir bilgisayar sisteminin donanım, işletim sistemi, sistem ve uygulama programları ile kullanıcıdan oluştuğunu anlatarak başladı. İşletim sisteminin temel işi, sürücüleri sunan, işlemci zamanını ve belleği uygulamalar arasında paylaştıran bir kaynak yöneticisi olmaktır. Concurrency tek kaynağı parça parça paylaştırır, paralellik birden fazla kaynak ister. Bilgisayar organizasyonunda bütün birimler bellek üzerinden haberleşir ve bellek darboğazdır. Tarihçe kısmında Babbage'ın mekanik makinelerinden, Ada Byron'ın ilk programlarından, ateşleme tablolarını hesaplayan insanlardan ENIAC'a, mainframe'lere ve kişisel bilgisayarlara uzanan gelişim izlendi. Programlama dilleri makine kodundan assembly'ye, yüksek seviyeli dillere, nesneye dayalı dillere, yorumlayıcılara ve özel amaçlı 4. ve 5. nesil dillere doğru gelişti.

Dersin son bölümünde sayı sistemlerine geçildi. İkili, sekizli, ondalık ve onaltılı sistemlerin rakamları ve basamak değerleri anlatıldı. Onluktan ikiliye çevirmede basamak değerlerini kullanan pratik yöntem, ikiliden sekizliye ve onaltılıya geçişte de üçlü ve dörtlü gruplama gösterildi. Bit, nibble, byte ve word kavramları tanıtıldı. Sayı sistemleri arasındaki geçişler ile aritmetik, mantıksal ve bit operatörleri bir sonraki derste sürecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
