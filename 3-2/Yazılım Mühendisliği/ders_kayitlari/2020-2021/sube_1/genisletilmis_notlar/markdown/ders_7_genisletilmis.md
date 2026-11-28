# Ders 7 Genişletilmiş Notu: UML Uygulaması: Anket, Süreli Yayın ve Kitap Ödünç Verme Örnekleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Uygulama Dersinin Amacı
- 2. Örnek 2: Online Anket Yönetimi Bilgi Sistemi
- 3. Örnek 1: Süreli Yayın Yönetim Yazılımı
- 4. Süreli Yayın İçin Olası Alan Modelleri
- 5. Kullanım Senaryosu: Yeni Sayı Gelişi (check-in)
- 6. Olası UML Kullanım Durumu Şemaları
- 7. Ek Gereksinim: Check-in Kartı
- 8. Soru-Cevap: Soyut Sınıf ve Ayrık/Örtüşen Alt Sınıflar
- 9. Örnek 3: Kitap Ödünç Verme Sistemi
- 10. Alan Şeması
- 11. Etkileşim Şeması: Sıralama (Sequence) Şeması
- 12. Durum (State) Şeması
- Örnek Sorular
- Dersin Toparlaması

## 1. Uygulama Dersinin Amacı

Bu ders bir uygulama dersidir. Önceki derslerde nesneye yönelik analiz, kullanım öyküleri, use case şemaları ve sınıf şemaları anlatılmıştı; bu derste bu bilgiler örnekler üzerinde uygulanır. Her örnekte bir sistemin gereksinimleri (sistemin neler yapabildiği, neler yapamadığı) doğal dille verilmiştir. Önce sistemin tanımı okunur ve anlaşılır, ardından bu gereksinimlerin çeşitli UML gösterimleriyle nasıl modellendiğine bakılır: sınıf şeması, kullanım senaryosu, kullanım durumu (use case) şeması, sıralama şeması ve durum şeması.

Derste üç örnek işlenir. Önce daha kısa olan anket örneği (alıştırma dosyasındaki Örnek-2), sonra daha uzun senaryolu süreli yayın örneği (Örnek-1), en son da kütüphanede kitap ödünç verme örneği ele alınır.

## 2. Örnek 2: Online Anket Yönetimi Bilgi Sistemi

### 2.1 Gereksinimler

Soru şöyledir (ekrandan, 00:25:00): "Aşağıda verilen gereksinimler belgesi ışığında, bir anket oluşturma sürecini anlatan kullanım senaryosunu yazarak alan modelini UML sınıf şeması çizerek oluşturunuz."

Gereksinim metni (ekrandan, 00:20:00):

> İnternet üzerinde anketler yapmamıza yarayacak ve bize bu anketler ile ilgili raporlar verebilecek bir bilgi sistemine sahip olmak istiyoruz. Her anketin başlangıç ve bitiş süreleri olmalıdır. Bir anketin seçenekleri sadece metinden oluşmamalı, birer resim de içerebilmelidir. Anketlere ancak kayıtlı kullanıcılar oy verebilmelidir. Bir anket ancak o anketin yöneticisi olarak atanmış bir kullanıcı tarafından oluşturulabilmelidir.

Sistemde kayıtlı kullanıcılar vardır. Anketi oluşturan kişi de bu kayıtlı kullanıcılardan biridir; o anketin yöneticisi (admin) olarak atanmıştır.

### 2.2 Örnek sınıf şeması

Karedeki sınıf şeması metin olarak şöyledir (ekrandan, 00:20:00):

| Sınıf | Nitelikler |
|---|---|
| Anket | `- başlangıç, bitiş : Date` |
| Seçenek | `- resim`, `- metin : String`, `- seçenSayısı : int` |
| Admin | (nitelik yazılmamış) |
| Kullanıcı | (nitelik yazılmamış) |

İlişkiler:

- Anket (1) — Admin (1): Her anketin bir yöneticisi vardır, bu yüzden birebir ilişki kurulmuştur.
- Anket (1) — Kullanıcı (*): Bir anketi birden fazla kullanıcı cevaplayabilir, bu yüzden bire çok ilişki kurulmuştur.
- Anket (1) — Seçenek (*): Bir ankette birden çok seçenek olabilir.
- Admin —▷ Kullanıcı: Kalıtım (genelleştirme) ilişkisi; admin de bir kullanıcıdır.

Tasarımın gerekçeleri anlatımda şöyle kurulur. Anket bir sınıf olarak düşünülür. Sistemde kullanıcılar vardır ve anketin yöneticisi de bu kullanıcılardan biridir. Nesneye dayalı programlama dersinde görülen "is-a" ilişkisi burada kullanılır: admin bir kullanıcıysa, kullanıcı sınıfının bir alt sınıfı olarak ayrı bir `Admin` sınıfı gösterilebilir. Anketin özellikleri olarak başlangıç ve bitiş tarihleri `Date` tipinde verilmiştir.

Gereksinimdeki seçeneklerle ilgili cümle, seçenekler için ayrı bir sınıf oluşturmanın daha iyi bir tasarım olacağını gösterir. Seçenek metinden oluşur, ek olarak resim de içerebilir; bu yüzden bir resim dosyası alabilecek biçimde tanımlanmıştır. Raporlama yapabilmek için her seçeneği kaç kişinin seçtiği de gerekir; bu değer `seçenSayısı` adlı bir sınıf değişkeninde tutulur.

### 2.3 Örnek kullanım senaryosu: Anket oluşturma

<!-- BELİRSİZ: Anket kullanım senaryosunun bulunduğu sayfa karelerde yok; aşağıdaki maddeler altyazıdaki anlatımdan kuruldu, slayttaki tam ifade ve numaralar doğrulanamadı. -->

Kullanım senaryoları farklı konularda olabilir; burada seçilen senaryo anket oluşturmadır.

- Senaryo adı: Anket oluşturma.
- Birincil aktör: Anket yöneticisi (admin), yani anketi oluşturacak kişi.
- İlgi alanları: Anket yöneticisi atandığı anketi başkasının değiştirmesini istemez; kendi anketi üzerinde yalnız kendisi işlem yapmak ister. Diğer kullanıcılar anketlerde oy kullanmak ve anket sonuçlarını görmek ister.
- Ön koşul: Anket yöneticisi sisteme girmiştir.
- Ana senaryo:
  1. Yönetici yeni bir anket oluşturur.
  2. Anketin sorularını oluşturur ve anketle ilişkilendirir.
  3. Anketi yayınlar.
- Alternatif senaryo (2. adımdan): Soru resim içeriyorsa anket yöneticisi bu soru için sisteme bir resim dosyası da yükler.

**Soru:** Alternatif akışa neden 2 numarası verildi?
**Cevap:** Ana senaryonun kaçıncı adımında bu alternatife girildiğini belirtmek için. Alternatife ikinci adımdan çıkıldığı için numarası 2'dir; aynı adımdan birden fazla alternatif olsaydı 2a, 2b diye devam ederdi. Alternatif senaryonun kendi alt adımları da altına kırılım olarak sıralanır.

## 3. Örnek 1: Süreli Yayın Yönetim Yazılımı

### 3.1 Gereksinim metni

Karedeki gereksinim metni şöyledir (ekrandan, 00:30:00):

> Kütüphanemiz için bir süreli yayın yönetimi yazılımına ihtiyacımız vardır. Süreli yayın; yeni sayılarının aylık – üç aylık – 4 aylık gibi periyotlarda geldiği ve bir yayın ismine sahip dergilerdir. Her süreli yayın bir isme ve kendisini diğerlerinden ayırt eden 8 karakterlik ISSN numarasına sahiptir. ISSN numarasının ilk 7 karakteri 0-9 arası sayı, son karakteri 0-9 arası sayı veya X karakteridir. Örneğin "Nature" adlı derginin ISSN'i 09534563'tür. Daha doğru bir terminoloji ile Nature bir aylık süreli yayındır. Kütüphanemiz de bu süreli yayına 2014 Mart sayısından itibaren abonedir. Ancak arada kütüphanemize ulaşmamış sayılar olabilir.
>
> Abone olunan süreli yayınlara bazen sadece basılı, bazen sadece elektronik, bazen de hem elektronik hem de basılı olarak abone olunmaktadır. Elektronik yayınlar için, derginin bütün sayılarına erişim için kullanılan tek bir URL ve bu derginin geriye dönük kaç yıllık sayılarına erişimimizin olduğu (backfile) bilgisi saklanmalıdır. Bazı elektronik yayınlarda ise backfile sınırı bulunmamaktadır. Basılı yayınlar için, derginin kütüphanemizde bulunan her sayısı için yıl ve sayı bilgileri saklanır. Kütüphaneci yeni gelen basılı dergi sayısını sisteme gireceği zaman, derginin mevcut sayılarının her biri bir kutucuk içerisinde yıl, sayı ve durum bilgilerine göre gösterilir. Kütüphaneci kutulardan birine tıklayarak derginin o sayısının durumunu değiştirebilir. Olası durumlar şunlardır: Geldi ve bekleniyor. O anki tarihe ve derginin periyoduna göre, sistem gelecek sayıların durumunu 'bekleniyor' olarak belirler. Kütüphaneci ise bu bilgiyi 'geldi' olarak değiştirebilir.
>
> Kütüphanemize gelen bir süreli yayın sayısı olduğunda, eğer sistemde yayının kaydı yoksa önce kütüphaneci bu kaydı oluşturur. Bu amaçla kütüphaneci derginin ISSN ve periyot bilgilerini girer. Adından aboneliğin basılı ve/veya elektronik olmasına göre gerekli bilgiler sisteme girilir. Eğer yayının kaydı zaten mevcutsa, kütüphaneci yukarıda belirtilen şekilde sayıyı sisteme 'geldi' olarak işler.

> **Ders sonrası not:** Slayttaki örnek ISSN değeri gerçek Nature dergisinin ISSN'i değildir; Nature'ın basılı ISSN'i büyük olasılıkla 0028-0836'dır. Örnek, ISSN biçimini göstermek için verildiğinden modellemeyi etkilemez.

### 3.2 Metnin çözümlenmesi

Süreli yayın, belirli periyotlarla yayınlanan dergi demektir. Yayınlanma süresi aylık, üç ayda bir ya da dört ayda bir olabilir. Metni okurken model kafada kurulmaya başlar: bir "süreli yayın" sınıfı vardır ve bunun "periyot" adında bir niteliği (attribute) vardır. Her derginin bir yayın adı ve bir kimlik numarası gibi kendine özgü 8 karakterlik ISSN numarası vardır.

Dergiler kütüphanede fiziksel (basılı) olarak bulunabilir ya da elektronik ortamda çevrimiçi erişilebilir. Elektronik yayınlarda derginin bütün sayılarına tek bir URL ile erişilir. Geriye dönük kaç yıllık sayılara erişim olduğu `backfile` adlı bir tamsayı değişkende tutulur. Bazı elektronik yayınlarda backfile sınırı yoktur, yani her elektronik yayında bir backfile sınırı olması şart değildir.

Basılı yayınlarda her sayı geldikçe sisteme işlenir: hangi yılın kaçıncı sayısının bulunduğu tutulur. Kütüphaneci yeni gelen bir sayıyı girerken derginin mevcut sayıları kutucuklar içinde yıl, sayı ve durum bilgileriyle gösterilir. Bir sayının olası durumları "geldi" ve "bekleniyor"dur. İlgili ay ya da üç aylık periyot gelmişse sistem o sayıyı "bekleniyor" olarak gösterir; sayı gelince kütüphaneci onu "geldi" olarak işaretler. Kütüphaneci eski sayılara da aynı biçimde ulaşabilir.

Kütüphaneci yeni bir dergi geldiğinde sisteme ISSN numarasını girer, çünkü derginin tanımlayıcı numarası budur. Sistem bu kaydı bulamazsa kütüphaneci aboneliği oluşturur, yani yeni bir kayıt açar: ISSN'i, derginin adını ve kaç ayda bir yayınlandığını gösteren periyot bilgisini girer; aboneliğin basılı mı, elektronik mi, yoksa ikisi birden mi olduğuna göre gerekli bilgileri ekler. Kayıt zaten varsa yalnız gelen sayıyı "geldi" olarak işaretler.

## 4. Süreli Yayın İçin Olası Alan Modelleri

Sorunun (b) şıkkı "Olası Alan modelleri (Metotsuz UML sınıf şemaları)" başlığını taşır (ekrandan, 00:35:00). Karede üç model vardır.

### 4.1 Model 1: Toplama ilişkisi ve 0..1 elektronik dergi

| Sınıf | Nitelikler |
|---|---|
| Süreli Yayın | `- isim, ISSN : String`, `- periyot : int`, `- sayılar[] : Sayı`, `- e_dergi : ElektronikDergi` |
| Sayı | `- sayiNo, yil : int`, `- durum : String` |
| ElektronikDergi | `- URL : String`, `- backfile : int` |

İlişkiler ve notlar:

- Sayı — Süreli Yayın: Süreli yayın tarafında içi boş elmas bulunan toplama (aggregation) ilişkisi.
- Süreli Yayın (1) — ElektronikDergi (0..1).
- Not: "periyot: Kaç ayda bir çıktığını gösteren sayı."
- Not: "backfile: Sınırsız ise 0 olur."

ISSN içinde X karakteri de bulunabildiği için `String` olarak tanımlanmıştır: rakam, rakam, rakam ve en sonda X gelebilir. Bir yayının kütüphanede bulunan sayıları vardır; "bu yayından bende şu sayılar var" demek için toplama ilişkisi kurulur ve sayılar bir dizide tutulur.

Elektronik dergide durum farklıdır: bir süreli yayının çok sayıda elektronik dergisi yoktur, hepsi tek bir URL'den listelenir. Süreli yayının ya hiç elektronik aboneliği yoktur (yalnız basılı olarak bulunuyordur) ya da tek bir elektronik versiyonu vardır. Bu yüzden ilişki 0..1 olarak kurulur. Elektronik derginin alanları URL ve kaç yıllık geçmiş sayıya erişildiğini gösteren backfile'dır.

### 4.2 Model 2: Soyut üst sınıf ve kalıtım

| Sınıf | Nitelikler |
|---|---|
| «abstract» Süreli Yayın | `- isim, ISSN : String`, `- periyot : int` |
| BasılıSayı | `- sayiNo, yil : int`, `- durum : String` |
| ElektronikDergi | `- URL : String`, `- backfile : int` |

`BasılıSayı` ve `ElektronikDergi`, `Süreli Yayın` sınıfından kalıtım alır. Karedeki not: "Sistemde aynı ISSN'li bir tek ElektronikDergi örneği, birden fazla BasılıSayı örneği bulunur. SüreliYayın sınıfı soyut olabilir."

Buradaki düşünce şudur: basılı yayın da elektronik dergi de birer süreli yayınsa aralarında bir "is-a" (kalıtım) ilişkisi kurulabilir. İkisi de süreli yayın olduğu için ortak alanları (isim, ISSN, periyot) vardır. Basılı sayı ek olarak hangi yılda yayınlandığı, kaçıncı sayı olduğu ve durum bilgisini (geldi, bekleniyor) içerir. Elektronik dergi ise ek olarak URL ve backfile alanlarını içerir. Süreli yayın sınıfı burada soyut (abstract) yapılmıştır.

### 4.3 Model 3: 1–* sayılar ve elektronik dergi alt sınıfı

| Sınıf | Nitelikler |
|---|---|
| Süreli Yayın | `- isim, ISSN : String`, `- periyot : int`, `- sayılar[] : Sayı` |
| Sayı | `- sayiNo, yil : int`, `- durum : String` |
| ElektronikDergi | `- URL : String`, `- backfile : int` |

- Süreli Yayın (1) → Sayı (*).
- ElektronikDergi —▷ Süreli Yayın (kalıtım).

Bir süreli yayının birden fazla sayısı olacağı için sayılar yine bir dizide tutulur ve bire çok ilişki kurulur. Elektronik dergi, süreli yayına eklenen bir ek alan gibi düşünülür: süreli yayın ek olarak bir de elektronik dergi URL'sine sahiptir; bu durum bir alt sınıfla gösterilir.

## 5. Kullanım Senaryosu: Yeni Sayı Gelişi (check-in)

Sorunun (a) şıkkı olası kullanım senaryosudur. Karedeki senaryo şöyledir (ekrandan, 00:40:00):

- KULLANIM SENARYOSU: Yeni Sayı Gelişi (check-in)
- Birincil Aktör: Kütüphaneci.
- Diğer İlgililer: Yok.
- İlgi Alanları: Kütüphaneci: Yeni ve eski her dergi sayısının bilgilerini doğru olarak işleyebilmeyi ister.
- Ön Koşullar: Kütüphaneci sisteme girmiştir.
- Son Koşullar: Süreli yayın ve sayı kayıtları sisteme girilmiş ve/veya güncellenmiştir.
- Ana Senaryo:
  1. Kütüphaneci kütüphaneye yeni gelen derginin ISSN'ini girer.
  2. Derginin basılı aboneliği varsa; ad, ISSN ve periyot bilgileri gösterilir.
  3. Derginin basılı aboneliği varsa, bu yıla ait sayıları kutucuklar şeklinde gösterilir. Mevcut sayıların durumu sistemden elde edilir, gelecek sayıların durumu 'bekleniyor' olarak gösterilir.
  4. Derginin elektronik aboneliği varsa, URL ve backfile bilgileri de gösterilir.
  5. Kütüphaneci ekranda sunulan tüm bilgileri gereken şekilde günceller ve onay düğmesine basar.

<!-- BELİRSİZ: Ana senaryonun 5. maddeden sonra devam edip etmediği karelerde görünmüyor; anlatımda güncellemeden sonra çıkış yapıldığı söyleniyor. -->

Bu senaryoda işi yapan tek kişi kütüphanecidir. Olay yalnız bir kişi ile sistem arasında geçiyorsa tek aktör olur; bir kişi, sistem ve başka bir kişi varsa "diğer ilgililer" de yazılmalıdır.

Ana senaryoda kütüphaneci yeni gelen derginin ISSN'ini girer; sistem dergiyle ilgili bilgileri gösterir. Mevcut (gelmiş) sayılar "geldi" olarak, gelecek sayılar "bekleniyor" olarak gösterilir. Bazı dergilerin elektronik aboneliği de olabileceği için bu durumda URL ve backfile bilgisi gösterilir. Kütüphaneci gelen sayıların durumunu "bekleniyor"dan "geldi"ye çevirip onaylar.

### 5.1 Alternatif senaryolar

Karedeki alternatif senaryolar (ekrandan, 00:45:00):

- 1a. Yeni abonelik.
  1. Sistem derginin ISSN'ini bulamamıştır, kütüphaneciye yeni abonelik oluşturmayı önerir.
  2. Öneri onaylanırsa sistem kütüphaneciden derginin adını, ISSN'ini ve periyodunu alır.
  3. Derginin elektronik aboneliği varsa URL ve backfile bilgileri kütüphaneciden alınır.
  4. Derginin basılı aboneliği varsa yıl ve sayı bilgileri kütüphaneciden alınır.
  5. Sistem girilen sayının durumunu 'Geldi' olarak atar.
- 3a. Kütüphaneci önceki yıla ait bir sayının işlemini yapmak ister.
  1. Kütüphaneci görmek istediği yılı belirtir.
  2. Sistem girilen yılın kutucuklarını çizerek sayıların durumlarını veritabanından alır.

<!-- BELİRSİZ: 3a'nın 2. maddeden sonraki adımları karede görünmüyor; anlatımda kütüphanecinin gelen sayının durumunu "geldi" olarak güncelleyebileceği ya da yalnız görüntüleyebileceği söyleniyor. -->

1a alternatifi, ana senaryonun birinci adımında ortaya çıkar: kütüphaneci ISSN'i girdiğinde dergi sisteme kayıtlı değilse yeni bir abonelik (yeni bir kayıt) oluşturması gerekir. Kütüphaneci "yeni abonelik oluştur" seçeneğine tıklar, sistem derginin adını, ISSN'ini ve periyodunu ister; elektronik abonelik varsa URL ve backfile, basılı abonelik varsa elindeki derginin yıl ve sayı bilgisi girilir. Bu sayı elde bulunduğu için sistem durumunu otomatik olarak "geldi" yapar.

3a alternatifi üçüncü adımla ilgilidir. Üçüncü adımda bu yılın sayıları gösterilir; ama kütüphaneciye önceki bir yıla ait bir sayı ulaşmış olabilir. Bu yüzden kütüphaneciye görmek istediği yılı belirtme imkânı verilmelidir. Sistem o yılın kutucuklarını çizer ve sayıların durumlarını listeler (örneğin 2012 yılında hangi sayıların bulunup bulunmadığı, gelip gelmediği).

## 6. Olası UML Kullanım Durumu Şemaları

Sorunun (c) şıkkı olası UML kullanım şemalarıdır (ekrandan, 00:50:00). Use case şemasında aktör bir insansa çöp adam olarak çizilir ve altına adı yazılır. Kütüphanecinin yapabileceği işlemler sisteme giriş, yeni sayı gelişiyle ilgili işlemler ve sıfırdan abonelik (yeni kayıt) oluşturmayla ilgili işlemlerdir. En temel gösterim bu işlemleri listeler; include ve extend ilişkileriyle alt ayrıntılar da verilebilir. Karedeki dört şema metin olarak şöyledir:

**Şema A (uygun):**

- Aktör: Kütüphaneci.
- Kullanım durumları: Abonelik, Yeni sayı gelişi, Sisteme Giriş (login).
- Not: "Şema uygun ancak doğru bir include veya extend ilişkisi göstermeniz yararınızadır."

**Şema B (uygun şema):**

- Aktör: Kütüphaneci.
- Kullanım durumları: Abonelik, Yeni sayı gelişi, Sisteme Giriş.
- "Eski abonelik" `«extend»` → "Yeni sayı gelişi".
- "Yeni abonelik" `«extend»` → "Yeni sayı gelişi".

Bu şemada yeni sayı gelişi, sayının eski bir aboneliğe mi yoksa yeni bir aboneliğe mi ait olduğuna göre genişletilmiştir. Var olan bir abonelikte kütüphaneci ekrandan hızlıca durumu "geldi" yapar; yeni abonelikte ise yeniden kayıt oluşturma gibi farklı işlemler yürütülür.

**Şema C (kütüphanecilik bilgisine göre uygun şema):**

- Aktör: Kütüphaneci.
- Kullanım durumları: Abonelik, Yeni sayı gelişi.
- "Elektronik" `«extend»` → "Abonelik".
- "Basılı" `«extend»` → "Abonelik".
- Not: "Kütüphanecilik bilgisine göre uygun şema: Bir dergiye sadece basılı, sadece elektronik veya basılı+elektronik olarak 3 şekilde abone olunabilir."

Burada durum aboneliklerle ilgili olduğu için bunu abonelik kullanım durumunda göstermek daha doğru bir tasarımdır. Elektronik abonelikte bir takım bilgiler, basılı abonelikte başka bilgiler girilir; abonelik işlemi bu şekilde genişletilmiş olur.

**Şema D (yanlış):**

- Aktör: Kütüphaneci.
- Kullanım durumları: Abonelik, Yeni sayı gelişi.
- "Yeni sayı gelişi" `«include»` → "Basılı".
- "Yeni sayı gelişi" `«include»` → "Elektronik".
- Not: "Bu şema metne bakınca doğru gibi görünüyor ama kütüphanecilik bilgisine göre yanlış. 'basılı aboneliği varSA, elektronik aboneliği varSA' ifadelerine dikkat!"

Include ilişkisi "bu işlem şu işi mutlaka içermeli" anlamında bir zorunluluk ifade eder. Oysa yeni sayı geldiğinde elektronik aboneliğin olması şart değildir; hatta basılı abonelik bile olmayabilir, çünkü yeni bir abonelik oluşturmak gerekebilir. Bu yüzden "yeni sayı gelişi işlemleri için mutlaka basılı abonelik ve elektronik abonelik içerilsin" ifadesi mantık gereği yanlıştır.

> **Hocanın vurgusu:** En uygun ifade, aboneliği elektronik ve basılı olması cinsinden `«extend»` etmektir. Gereksinim metnindeki "varsa" ifadeleri isteğe bağlılık bildirir; isteğe bağlı durum `«include»` ile değil `«extend»` ile gösterilir.

## 7. Ek Gereksinim: Check-in Kartı

Gereksinim belgesine bir ekleme yapılır: kütüphanecinin içine tıklayarak değiştirebildiği, okuyucuların ise değiştirmeden içeriğini okuyabildiği ekrana derginin check-in kartı denir. Karede görünen cümlenin sonu şöyledir (ekrandan, 00:55:00): "... görebilme yetkisine sahip olduğu yukarıda anlatılan ekrana derginin check-in kartı denilir."

<!-- BELİRSİZ: Ek gereksinim cümlesinin başı karede görünmüyor; yukarıdaki ifade altyazıdan kuruldu. -->

Check-in kartı dergiye ait bir karttır; dergiyle ilgili bilgileri, hangi sayılarının bulunduğunu gösterir. Kütüphaneci bu kart üzerinde işlem yapar, okuyucu ise yalnız görüntüler. Bu yüzden şemaya ikinci bir aktör olarak okuyucu eklenir.

Karedeki şema (ekrandan, 00:55:00):

- Aktörler: Kütüphaneci, Okuyucu.
- Kütüphaneci — Abonelik, Check-in kartı gösterimi, Yeni sayı gelişi.
- Okuyucu — Check-in kartı gösterimi.
- "Yeni sayı gelişi" `«include»` → "Check-in kartı gösterimi".
- "Check-in kartı gösterimi" `«extend»` → "Abonelik".
- "Check-in kartı düzenlemesi" `«extend»` → "Check-in kartı gösterimi".

Yeni bir sayı geldiğinde kütüphanecinin bu kartı görmesi şarttır; gelen sayıyı ancak kartta görüp "geldi" diye işaretleyebilir. Bu yüzden "Yeni sayı gelişi" işlemi "Check-in kartı gösterimi"ni include eder.

Abonelik işleminde ise kütüphaneci dergi bilgilerini girer; o sırada var olan bir kart yoktur, kart zaten abonelikle birlikte oluşturulur. Bilgileri yazıp tamamladıktan sonra kontrol etmek amacıyla kartı ayrıca görmek isteyebilir. Bu isteğe bağlı olduğu için check-in kartı gösterimi, abonelik işleminde bir extend olur.

Kart üzerinde yalnız gösterim değil, işaretleme gibi düzenleme işlemleri de yapılabildiği için "Check-in kartı düzenlemesi" de gösterimi extend eder. Okuyucu ise yalnız gösterim işlemini kullanır.

## 8. Soru-Cevap: Soyut Sınıf ve Ayrık/Örtüşen Alt Sınıflar

**Soru:** Bir sınıf birden fazla kez extend edilebilir mi? Java'da olmuyor, UML'de farklı mı? Soruyu soran öğrenci daha sonra soruyu açar: Süreli yayın soyut sınıf olarak tanımlanmış (Model 2). Bir derginin hem basılı hem elektronik olma durumu bu şemada nasıl gösterilir? Şema "ya basılı ya elektronik dergi olur" gibi görünüyor. Veritabanında görülen overlap (bir varlık birden fazla alt sınıfa ait olabilir) ve disjoint (alt sınıflar ayrık olmak zorunda) kavramları UML'de nasıl gösterilir?

**Cevap:** Güzel bir soru. UML gösterimine bakıldığında bu iki alt sınıf ayrık sınıflar gibi düşünülmüştür. Bu çizimde elektronik derginin bir ismi, ISSN'i, periyodu ve üstüne URL'si ile backfile'ı; basılı sayının da aynı ortak alanlar artı kendi alanları olduğu mantığı yürütülmüştür. Ancak bu gösterim basılı sayıyla elektronik dergiyi doğrudan ilişkilendirmez; elektronikler bir tarafta, basılı sayılar bir tarafta kalır. Diğer gösterimlerde (Model 1 ve Model 3) ise yayın doğrudan elektronik dergiye bağlanabildiği gibi sayılarıyla da doğrudan ilişkilendirilebilir. Bu yüzden diğer gösterimler daha mantıklıdır.

> **Ek bilgi (derste anlatılmadı):** UML 2'de bir üst sınıfın alt sınıfları bir genelleştirme kümesi (generalization set) olarak gruplanabilir ve bu kümeye `{disjoint}` ya da `{overlapping}`, ayrıca `{complete}` ya da `{incomplete}` kısıtları yazılabilir. `{overlapping}`, bir nesnenin aynı anda birden fazla alt sınıfın örneği olabileceğini anlatır; bu, veritabanı modellemesindeki overlap kavramına karşılık gelir. Java gibi dillerde bir sınıf yalnız tek bir sınıftan kalıtım alabildiği için böyle bir model kodda genellikle arayüzler ya da bileşim (composition) ile gerçeklenir.

## 9. Örnek 3: Kitap Ödünç Verme Sistemi

Bu örnek yine bir kütüphane yazılımıyla ilgilidir; okuyucuların bir kitabı ödünç alıp alamaması ele alınır. Karedeki metin şöyledir (ekrandan, 01:00:00):

> Kitap ödünç verilirken izlenen yol:
>
> - Okuyucunun üzerinde kaç kitap olduğuna bakılır. Eğer okuyucu kitap alma sınırını doldurmuşsa yeni kitap verilmez.
> - Okuyucunun üzerindeki TOPLAM para cezasının, okuyucu için önceden tanımlanmış ceza sınırından (Okuyucu.cezaSınırı) yüksek olup olmadığına bakılır. (Toplam ceza = Okuyucu.cezaMiktarı + bu sırada okuyucuda bulunan iade tarihi geçmiş kitaplardan kaynaklanan cezaların miktarı).
> - Ceza sınırı aşılmışsa okuyucuya yeni kitap verilmez. Aksi halde bir ödünç kaydı oluşturularak okuyucu kaydı ile ilişkilendirilir. Ödünç kaydının alış tarihi bugünün tarihine, dönüş tarihi ise istenen kitabın kaç günlüğüne ödünç verileceğine bakılarak belirlenir.

Okuyucunun aynı anda elinde bulundurabileceği kitap sayısının bir sınırı vardır. Okuyucu bu sınırı doldurmuşsa yeni kitap verilmez. İkinci kısıt toplam para cezasıdır. Kişinin geçmişte aldığı ve henüz ödemediği cezalar vardır; buna o an elinde bulunan ve iade tarihi geçmiş kitaplardan doğan ceza eklenir. Bu toplam okuyucuya tanımlı ceza sınırını aşıyorsa yeni kitap verilmez. Yani okuyucuyla ilgili iki temel kontrol vardır: kitap sınırı (bir tamsayı değişken) ve ceza sınırı.

Bu metin okununca sınıflar belirmeye başlar. Kitabın kaç günlüğüne ödünç verileceği bilgisi kitapla ilgili bir sınıfta tutulur. Okuyucuya ait bir okuyucu sınıfı olur. Her ödünç işleminde alınış ve dönüş tarihleri tutulacağı için ayrı bir ödünç kaydı sınıfı olur; dönüş tarihi hesaplanırken ilgili kitabın kaç günlüğüne verilebildiğine bakılır. Okuyucu sınıfında geçmiş para cezaları tutulur; elindeki kitapların gecikme cezaları ise kitapla ilgili sınıftaki günlük ceza bilgisinden hesaplanıp toplanır.

Sorunun istekleri altyazıya göre bir tasarım modeli olarak alan şeması, etkileşim şeması ve durum şemasıdır.

## 10. Alan Şeması

Karedeki alan şeması (ekrandan, 01:05:00):

| Sınıf | Nitelikler | Metotlar |
|---|---|---|
| Okuyucu | `- ad, soyad: String`, `- üyeNo: Integer`, `- kitapSınırı: Integer`, `- cezaSınırı: Double`, `- cezaMiktarı: Double` | `+ getKitapSayısı():int`, `+ getCeza():double`, `+ getToplamCeza():int`, `+ kitapEkle(ÖdünçKaydı)` |
| ÖdünçKaydı | `- alışTarihi: Date`, `- dönüşTarihi: Date` | `+ getDonusTarihi(): Date`, `+ getGunlukCeza() : double` |
| KitapKopyası | `- barkod: String`, `- ödünçSüresi: Integer`, `- günlükCeza: Double` | `+ getGunlukCeza() : double` |
| Kitap | `- adı, yazarı: String`, `- basımYılı: Integer` | (yok) |

İlişkiler:

- Okuyucu (1) ◇— ÖdünçKaydı (*): Okuyucu tarafında içi boş elmas (toplama).
- ÖdünçKaydı (1) — KitapKopyası (1).
- KitapKopyası (*) — Kitap (1).

Okuyucunun adı, soyadı ve üye numarası; elinde kaç kitap tutabileceği ve ceza bilgileri tutulur. Bir okuyucunun birden fazla ödünç kaydı olabilir; her kayıtta ne zaman alındığı ve ne zaman getirilmesi gerektiği ayrı ayrı tutulur.

Kitap ile kitap kopyası ayrımının mantığı şudur: bir kitabın adı, yazarı, basım yılı gibi bilgileri vardır. Ancak kütüphanede aynı kitaptan birden fazla bulunabilir ve her biri farklı bir kullanıcıya verilebilir; örneğin aynı kitaptan üç tane varsa üç farklı kullanıcıya verilebilir. Bu yüzden ayrı bir kitap kopyası sınıfı oluşturmak mantıklıdır. Kitabın kaç günlüğüne ödünç verilebileceği (`ödünçSüresi`) ve günlük ceza bilgisi kopya sınıfındadır. Bir ödünç kaydında yalnız bir kitap olabilir, bu yüzden ödünç kaydı ile kitap kopyası arasında birebir ilişki kurulmuştur.

Okuyucu ile ödünç kaydı arasında neden düz bir bire çok ilişki değil de elmas (toplama) kullanıldığı sorusu akla gelebilir. Ödünç kaydı doğrudan bir kullanıcıyla ilgilidir; kayıtlar ayrı ayrı tanımlansa da her biri bir okuyucuya atanır ve ona ait olur. Aralarındaki bağ daha kuvvetli olduğu için toplama ilişkisi kullanılmıştır. Bunun bir üstündeki daha kuvvetli ilişki bileşimdir (composition, içi dolu elmas): o durumda parça sınıfın bilgileri doğrudan bütün sınıfın içinde oluşturulur ve parça bütünden ayrı düşünülemez.

> **Ders sonrası not:** Sıralama şemasında okuyucu nesnesine `getKitapSınırı()` ve `getCezaSınırı()` çağrıları gönderilir, ancak alan şemasındaki Okuyucu sınıfında bu metotlar yazılı değildir (ekrandan, 01:05:00). Ayrıca `getToplamCeza()` dönüş tipi `int` yazılmışken ceza nitelikleri `Double` tipindedir. Tutarlı bir modelde büyük olasılıkla bu iki metot Okuyucu'ya eklenir ve `getToplamCeza()` `double` döndürür.

## 11. Etkileşim Şeması: Sıralama (Sequence) Şeması

### 11.1 Etkileşim şemaları

Etkileşim şemaları ikiye ayrılır: işbirliği (collaboration) şeması ve sıralama (sequence) şeması. Bu şemalar nesneler arasındaki etkileşimin nasıl olduğunu, olayların nasıl ilerlediğini, hangi mesajların hangi sırada gönderildiğini gösterir.

> **Hocanın vurgusu:** Etkileşim şeması, etkinlik şemasıyla (activity diagram) karıştırılmamalıdır. Etkileşim şeması nesnelerin birbirine nasıl mesaj gönderip aldığını gösterir; etkinlik şeması ayrı bir şemadır.

Sıralama şemasında üstte nesneler sıralanır. Bir nesneden başka bir nesneye mesaj gönderilir: bir istek (request) yapılır, o sınıftan bir metot çağrılır. Ardından bir cevap (response) döner. İçi dolu oklu düz çizgi gönderilen mesajı, kesik çizgi alınan cevabı gösterir. Bir nesne kendi sınıfındaki bir metodu çağırıyorsa kendine dönen bir okla ve küçük bir kutucukla gösterilir. Köşeli parantez içindeki ifade bir koşul ifadesidir. Açıklama yapmak için UML'deki not kutucukları (köşesi kıvrık kutu) kullanılır. Cevap beklenmeyen bir çağrıda dönüş oku çizilmez, tek yönlü ok yeterlidir.

Şemanın adı "ardışık şema" olduğu için zaman çizelgesi önemlidir: en üstteki mesaj en önce olur, sonra alttaki gelir.

> **Hocanın vurgusu:** Sıralama şemasında metotların sırayla çağrılması çok önemlidir. "Keyfime göre önce şu metodu çağırayım" denemez; derleyici yazılan kodu hangi sırayla çalıştırıyorsa şemadaki çağrılar da o sırayla yazılmalıdır.

### 11.2 Ödünç verme sıralama şeması

Karedeki şemanın nesneleri (ekrandan, 01:20:00): `Kütüphaneci`, `Otomasyon Sistemi`, `okur:Okuyucu`, `kayıt:ÖdünçKaydı`, `kitap:KitapKopyası`; şemanın sonunda oluşturulan `yeniKayıt:ÖdünçKaydı`.

Mesajlar yukarıdan aşağıya sırasıyla şöyledir (ekrandan, 01:20:00):

| Sıra | Gönderen → Alan | Mesaj |
|---|---|---|
| 1 | Kütüphaneci → Otomasyon Sistemi | `okuyucuBul(okurBarkod)` |
| 2 | Otomasyon Sistemi ⇢ Kütüphaneci | dönüş: `okur` |
| 3 | Kütüphaneci → okur:Okuyucu | `kitapSayisi = getKitapSayısı()` (dönüş kesik çizgi) |
| 4 | Kütüphaneci → okur:Okuyucu | `kitapSınırı = getKitapSınırı()` (dönüş kesik çizgi) |
| 5 | Kütüphaneci → okur:Okuyucu | `getToplamCeza()` |
| 6 | okur:Okuyucu → okur:Okuyucu | `toplamCeza = getCeza()` (kendine mesaj) |
| 7 | okur:Okuyucu → kayıt:ÖdünçKaydı | `* getDonusTarihi()` |
| 8 | kayıt:ÖdünçKaydı ⇢ okur:Okuyucu | dönüş: `tarih` |
| 9 | okur:Okuyucu → kayıt:ÖdünçKaydı | `* [tarih < bugün] toplamCeza += getGünlükCeza() * (bugün-tarih)` |
| 10 | kayıt:ÖdünçKaydı → kitap:KitapKopyası | `getGunlukCeza()` |
| 11 | kitap:KitapKopyası ⇢ kayıt:ÖdünçKaydı | dönüş: `ceza` |
| 12 | kayıt:ÖdünçKaydı ⇢ okur:Okuyucu | dönüş |
| 13 | okur:Okuyucu ⇢ Kütüphaneci | dönüş: `toplamCeza` |
| 14 | Kütüphaneci → okur:Okuyucu | `getCezaSınırı()` |
| 15 | okur:Okuyucu ⇢ Kütüphaneci | dönüş: `cezaSınırı` |
| 16 | Kütüphaneci → Otomasyon Sistemi | `ödünçVer( okurBarkod, kitapBarkod )` |
| 17 | Otomasyon Sistemi → yeniKayıt:ÖdünçKaydı | `new` |
| 18 | Otomasyon Sistemi → okur:Okuyucu | `kitapEkle( yeniKayıt )` |

`ödünçVer` mesajına bağlı not: `[toplamCeza < cezaSınırı AND kitapSayısı < kitapSınırı]`.

> **Ek bilgi (derste anlatılmadı):** Sıralama şemasında mesaj adının önündeki `*` işareti yinelemeyi (iteration) gösterir: mesaj birden çok kez, burada okuyucunun her ödünç kaydı için gönderilir. Köşeli parantez içindeki ifade ise koruma koşuludur (guard); mesaj yalnız koşul doğruysa gönderilir. UML 2'de bu yapılar genellikle `loop` ve `opt` birleşik parçalarıyla (combined fragment) çizilir.

### 11.3 Akışın anlatımı

Okuyucu elinde kitapla gelir ve kitabı almak istediğini söyler. Kütüphaneci önce sisteme okurun bilgisini (üye numarası gibi bir okur barkodu) gönderir. Otomasyon sisteminde `okuyucuBul` adında bir metot vardır; parametresi okur barkodudur ve okurla ilgili bütün bilgileri taşıyan okur nesnesini döndürür.

Ardından iki koşul kontrol edilir: kitap sayısı ve ceza miktarı. Kitap sınırı aşılmamışsa ve ceza sınırı aşılmamışsa kitap verilebilir. Önce kitap sayısına bakılır: okuyucu nesnesine `getKitapSayısı` gönderilir ve okurun elindeki kitap sayısı alınır. Karşılaştırma yapabilmek için okura atanmış kitap sınırı da gerekir; bunun için yine okuyucu nesnesine `getKitapSınırı` isteği gönderilir ve okurun en fazla kaç kitap alabileceği döner. Kütüphaneci artık bu iki bilgiyle bir çıkarım yapabilir.

İkinci kısım ceza hesabıdır ve birkaç aşamalıdır. Kütüphaneci okuyucuya `getToplamCeza` gönderir; toplam ceza birkaç sınıf kullanılarak hesaplanır. Önce okuyucu sınıfındaki geçmiş cezaların toplamı alınır. Bu, okuyucunun kendi sınıfındaki bir metodu çağırmasıdır ve kendine mesaj olarak gösterilir: `toplamCeza = getCeza()`.

Buna elindeki kitaplardan doğan ceza eklenir. Bunun için okuyucunun ödünç kayıtlarına gidilir ve `getDonusTarihi` ile her kaydın dönüş tarihi alınır. Dönen tarih bugünün tarihiyle karşılaştırılır. Tarih bugünden küçükse kitabın iade tarihi geçmiştir. Hocanın sayısal örneği şöyledir:

- Bugün ayın 20'si, kitabın dönüş tarihi ayın 30'u ise tarih bugünden büyüktür; süre geçmemiştir, ceza yoktur.
- Bugün ayın 20'si, kitabın dönüş tarihi ayın 10'u ise tarih bugünden küçüktür; süre geçmiştir.
- Gecikme gün sayısı: $20 - 10 = 10$ gün (ara adım eklendi).
- Bu kitap için eklenecek ceza: $10 \times \text{günlükCeza}$ (ara adım eklendi).

Ceza, bugünden dönüş tarihi çıkarılarak bulunan gün sayısı ile günlük ceza çarpılarak hesaplanır:

$$\text{toplamCeza} \mathrel{+}= \text{günlükCeza} \times (\text{bugün} - \text{tarih})$$

Günlük ceza ödünç kaydında bulunmaz; kitapla ilgili bilginin bulunduğu kitap kopyası sınıfındadır. Bu yüzden ödünç kaydı kitap kopyasına `getGunlukCeza` gönderir ve kitabın gecikmesi durumunda her gün için uygulanacak ceza miktarını alır. Bu değer gün sayısıyla çarpılır, elindeki kitaplardan doğan ceza geçmiş cezayla birleştirilir ve toplam ceza kütüphaneciye döner. Tarih geçmemişse ek bir işlem yapılmaz; toplam ceza geçmiş ceza kadar olarak geri döner.

Ceza miktarı hesaplandıktan sonra sınırla karşılaştırılmalıdır, çünkü her kullanıcıya en fazla ne kadar cezası olabileceğine dair bir sınır tanımlanmıştır. Kitap sayısında olduğu gibi kütüphaneci bu sınırı da okuyucu sınıfından `getCezaSınırı` ile alır.

Artık kütüphanecinin elinde kitap sayısı, kitap sınırı, ceza miktarı ve ceza sınırı vardır. Toplam ceza ceza sınırının altındaysa ve kitap sayısı kitap sınırının altındaysa `ödünçVer` metodu çalıştırılır: otomasyon sistemine okurun numarası (kimlik numarası gibi) ve kitabın numarası verilir. Şemada en boş yere yeni bir kutucuk açılarak `ÖdünçKaydı` sınıfından yeni bir kayıt nesnesi `new` ile oluşturulur. Yeni kaydın bilgileri (alış tarihi olarak o günün tarihi ve dönüş tarihi) girilir. Ardından bu kayıt okuyucu nesnesiyle ilişkilendirilir: okuyucudaki `kitapEkle` metodu yeni kayıtla çağrılır. Burada bir cevap beklenmediği için yalnız tek yönlü ok çizilmiştir.

## 12. Durum (State) Şeması

Bu örnekte istenen son şema durum şemasıdır; okuyucunun ödünç alabilme ve alamama durumları modellenir. Durum şemaları nesnelerin durumları hakkında bilgi verir; bir başlangıçları ve bir bitişleri vardır. Başlangıç içi dolu bir daireyle, bitiş (sonlanma) durumu ise bu dairenin çevresine bir çember daha çizilerek gösterilir.

Karedeki şema (ekrandan, 01:25:00):

- Durumlar: "Ödünç alabilir", "Ödünç alamaz".
- Başlangıç → Ödünç alabilir: `«M»Okuyucu Kütüphaneye kayıt oldu`.
- Ödünç alabilir → Ödünç alabilir (kendine geçiş): `«M»Ödünç alma[ödünç limiti AND ceza limiti aşılmadı]`.
- Ödünç alabilir → Ödünç alamaz: `«M»Ödünç alma[ödünç limiti OR ceza limiti aşıldı]`.
- Ödünç alamaz → Ödünç alabilir: `«M»İade [ceza limiti altına düşüldü]/«M»Ceza ödeme [ödünç limiti altına düşüldü]`.
- Ödünç alamaz → Ödünç alamaz (kendine geçiş): `«M»İade[ceza limiti aşıldı]`.
- Ödünç alamaz → Bitiş: `«M»Okuyucu ilişiğini kesti`.

Etiketlerdeki «M» mesaj anlamındadır. Okuyucu kütüphaneye kayıt olunca "ödünç alabilir" durumuna girer. Bu durum, ödünç limiti ve ceza limiti aşılmadığı sürece devam eder; köşeli parantez içindeki ifade koşuldur. Limitlerden herhangi biri aşılınca (ödünç limiti ya da ceza limiti) durum değişir ve okuyucu "ödünç alamaz" durumuna geçer.

"Ödünç alamaz" durumundan yeniden "ödünç alabilir" durumuna geçmek için limitin altına inilmelidir. Ödünç limiti, okuyucunun elindeki kitapların izin verilen sınırdan fazla olmasıdır; okuyucu kitap iade eder ve kitap sayısı ödünç limitinin altına düşerse yeniden ödünç alabilir. Benzer biçimde cezasını ödeyip ceza limitinin altına inerse de yeniden ödünç alabilir duruma gelir. Ancak iade etse bile ceza limiti aşılmış durumdaysa okuyucu "ödünç alamaz" durumunda kalır; en sonunda kitabı alamadan kütüphaneden ilişiğini keserse bitiş durumuna gidilir.

> **Ders sonrası not:** Slayttaki geri dönüş etiketinde koşullar çapraz yazılmıştır: "İade [ceza limiti altına düşüldü] / Ceza ödeme [ödünç limiti altına düşüldü]" (ekrandan, 01:25:00). Derste anlatıldığı gibi iade, ödünç (kitap) limitinin; ceza ödemesi ise ceza limitinin altına düşülmesini sağlar. Etiket büyük olasılıkla "İade [ödünç limiti altına düşüldü] / Ceza ödeme [ceza limiti altına düşüldü]" biçiminde olmalıdır.

> **Ek bilgi (derste anlatılmadı):** UML durum şemasında bir geçiş genellikle `olay [koruma koşulu] / eylem` biçiminde yazılır. Olay geçişi tetikler, köşeli parantezdeki koşul doğruysa geçiş gerçekleşir, eğik çizgiden sonraki eylem geçiş sırasında yapılır. Bu yüzden slayttaki etikette eğik çizgi iki ayrı olayı ayırmak için kullanılmış olsa da, UML yazımında eğik çizgi normalde eylemi başlatır; iki ayrı olay için iki ayrı geçiş oku çizmek daha açıktır.

## Örnek Sorular

**Soru 1 (ekrandan, 00:25:00):** Aşağıda verilen gereksinimler belgesi ışığında, bir anket oluşturma sürecini anlatan kullanım senaryosunu yazarak alan modelini UML sınıf şeması çizerek oluşturunuz.

> İnternet üzerinde anketler yapmamıza yarayacak ve bize bu anketler ile ilgili raporlar verebilecek bir bilgi sistemine sahip olmak istiyoruz. Her anketin başlangıç ve bitiş süreleri olmalıdır. Bir anketin seçenekleri sadece metinden oluşmamalı, birer resim de içerebilmelidir. Anketlere ancak kayıtlı kullanıcılar oy verebilmelidir. Bir anket ancak o anketin yöneticisi olarak atanmış bir kullanıcı tarafından oluşturulabilmelidir.

Çözüm (derste verildi): Örnek sınıf şeması Bölüm 2.2'de, örnek kullanım senaryosu Bölüm 2.3'tedir. Özetle sınıflar `Anket (başlangıç, bitiş : Date)`, `Seçenek (resim, metin : String, seçenSayısı : int)`, `Kullanıcı` ve `Kullanıcı`'dan kalıtım alan `Admin`'dir; ilişkiler Anket 1–1 Admin, Anket 1–* Kullanıcı, Anket 1–* Seçenek'tir. Senaryoda birincil aktör anket yöneticisidir; soru resim içeriyorsa resim yükleme alternatif senaryodur.

**Soru 2 (ekrandan, 00:30:00; 00:35:00; 00:40:00; 00:50:00):** Süreli Yayın Yönetim Yazılımı gereksinim metni (Bölüm 3.1) için (a) olası kullanım senaryosunu (Yeni Sayı Gelişi), (b) olası alan modellerini (metotsuz UML sınıf şemaları), (c) olası UML kullanım şemalarını hazırlayınız.

<!-- BELİRSİZ: Soru 2'nin tam soru cümlesi karelerde görünmüyor; şıklar karelerdeki (a), (b), (c) başlıklarından alındı. -->

Çözüm (derste verildi): (a) Bölüm 5'teki "Yeni Sayı Gelişi (check-in)" senaryosu ve 1a, 3a alternatifleri; (b) Bölüm 4'teki üç alan modeli; (c) Bölüm 6'daki şemalar. En uygun use case şeması "Elektronik" ve "Basılı" durumlarının "Abonelik"i `«extend»` ettiği şemadır; "Yeni sayı gelişi"nin bunları `«include»` ettiği şema yanlıştır, çünkü abonelik türleri isteğe bağlıdır.

**Soru 3 (ekrandan, 00:55:00; derste sözlü, 00:51:25):** Gereksinimlere şu eklenirse use case şeması nasıl değişir? Kütüphanecinin içine tıklayarak değiştirebildiği, okuyucuların ise değiştirmeden içeriğini görebilme yetkisine sahip olduğu yukarıda anlatılan ekrana derginin check-in kartı denilir.

Çözüm (derste verildi): Bölüm 7'deki şema. Okuyucu ikinci aktör olarak eklenir ve yalnız "Check-in kartı gösterimi"ni kullanır; "Yeni sayı gelişi" bu gösterimi `«include»` eder; "Check-in kartı gösterimi" "Abonelik"i, "Check-in kartı düzenlemesi" de "Check-in kartı gösterimi"ni `«extend»` eder.

**Soru 4 (ekrandan, 01:00:00; derste sözlü, 01:08:13):** Kitap ödünç verilirken izlenen yol (Bölüm 9'daki metin) için alan şemasını, etkileşim şemasını ve durum şemasını çiziniz.

<!-- BELİRSİZ: Soru 4'ün tam soru cümlesi karede kısmen görünüyor (yalnız "durum şemasını çiziniz" kısmı); istenen şemalar altyazıdan alındı. -->

Çözüm (derste verildi): Alan şeması Bölüm 10'da, sıralama şeması Bölüm 11.2'de, durum şeması Bölüm 12'dedir. Ödünç verme koşulu `toplamCeza < cezaSınırı AND kitapSayısı < kitapSınırı`, toplam ceza ise geçmiş ceza ile iade tarihi geçmiş her kitap için `günlükCeza × (bugün − dönüşTarihi)` toplamıdır.

## Dersin Toparlaması

Bu uygulama dersinde doğal dille yazılmış gereksinim belgelerinden UML modellerine nasıl geçildiği üç örnek üzerinde gösterildi. Anket örneğinde gereksinim cümlelerinden sınıflar, nitelikler, çokluklar ve kalıtım ilişkisi çıkarıldı; kullanım senaryosunun aktör, ön koşul, ana senaryo ve alternatif senaryo bölümleri kuruldu. Süreli yayın örneğinde aynı gereksinim için birden fazla geçerli alan modeli olabileceği görüldü; kullanım senaryosu ve use case şemalarında `«include»` ile `«extend»` arasındaki fark, metindeki "varsa" ifadeleri üzerinden tartışıldı. Kitap ödünç verme örneğinde alan şemasıyla birlikte bir sıralama şeması ve bir durum şeması çizildi; sıralama şemasında mesajların sırası, koşullar ve nesne oluşturma, durum şemasında ise koşullu geçişler gösterildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
