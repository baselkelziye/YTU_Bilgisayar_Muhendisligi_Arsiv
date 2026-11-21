# Ders 4 Genişletilmiş Notu: Monitörler ve Koşul Değişkenleri (Hoare ve Mesa Makaleleri)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Biçimi ve Tartışılan Makaleler
- 2. Monitörler ve Semaforlar: Hangisi Önce?
- 3. Semafor ve P/V İşlemleri
- 4. Koşul Değişkenine İlk Bakış
- 5. Monitörün Tanımı, Adı ve Simula 67 Sınıf Notasyonu
- 6. Koşul Değişkeninin Değeri ve Arkasındaki Kuyruk
- 7. Programcıya Sağlanan Soyutlama
- 8. Makaledeki Örnekler ve İşletim Sistemindeki Karşılıkları
- 9. Monitörü Semaforla Gerçeklemek ve Monitörü Kim Yazar?
- 10. Donanım Desteği: Atomik Komutlar
- 11. Kuyruk Disiplini: FIFO, Öncelik, Açlık ve Konvoy
- 12. Mesa ve Pilot: Monitörler Gerçek Bir Sistemde
- 13. Kesmelerin Monitörle Soyutlanması
- 14. Global Kaynak Paylaşımı
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Biçimi ve Tartışılan Makaleler

Bu ders de önceki haftalar gibi, öğrencilerin önceden okuduğu makalelerin soru-cevap biçiminde tartışılmasıyla geçti. Kayıt boyunca ekranda slayt ya da makale paylaşılmadı; aşağıdaki bilgiler sözlü anlatımdan ve makalelerden sesli okunan cümlelerden alınmıştır.

İki makale birbiriyle doğrudan ilişkilidir. Birincisi, monitör kavramını teorik örnekler ve basit, yerelleştirilmiş pratik örnekler üzerinden inceler. Hoca bu makalenin yılını 1974 olarak verdi. İkincisi, aynı kavramı bir işletim sistemi içinde gerçekleyerek inceler: Mesa programlama dili ve Pilot işletim sistemi. Hoca, sırayla verilen makalelerde genellikle öncekinin temeli, sonrakinin onun genişletilmiş ya da uygulanmış hali olduğunu söyledi; bu derste de durum böyledir.

> **Ek bilgi (derste anlatılmadı):** Derste makalelerin adı söylenmedi. Anlatılanlar büyük olasılıkla C. A. R. Hoare'un "Monitors: An Operating System Structuring Concept" (Communications of the ACM, 1974) makalesine ve B. W. Lampson ile D. D. Redell'in "Experience with Processes and Monitors in Mesa" (Communications of the ACM, 1980) makalesine karşılık gelir.

## 2. Monitörler ve Semaforlar: Hangisi Önce?

Tartışmayı açan öğrenci, monitörlerin semafor ve mutex'in bir tür atası ya da onlara yön veren bir kavram gibi göründüğünü söyledi. Ona göre monitörün semafordan farkı, kendi içinde yerel değişkenleri olması; kaynağa erişme ve kaynağı bırakma talepleri oluşturulması ve bu yerel değişkenler değiştirilerek süreçlerin bekleme ya da çalışma durumuna getirilmesidir.

Hoca "atası olduğundan emin misin?" diye sordu. Başka bir öğrenci düzeltti: makale, monitörleri semaforlarla gerçeklemeye ve bunun uygun bir kanıtını sunmaya çalışır; yani monitör yapısı semaforlar üzerinden kurulur. Dolayısıyla ilişki terstir: **semaforlar monitörlerin atasıdır**. Monitör kavramından önce semafor vardır.

> **Hocanın vurgusu:** Monitörler semaforların atası değildir; tam tersine semaforlar monitörlerin atasıdır. Bunu unutmamak gerekir.

## 3. Semafor ve P/V İşlemleri

Hoca "madem temel semafor, semafor nedir?" diye sordu. Öğrencilerin vardığı tanım şudur: semafor, işletim sisteminde süreçler arasındaki senkronizasyonu sağlamak için kullanılan ilkellerden (primitive) biridir. Bir öğrenci semaforun süreçlerin haberleşmesini de sağladığını söyledi; hoca bunun ayrı bir konu olduğunu belirtti.

Başka bir öğrenci işin çıkış noktasını kaynakların verimli kullanımı (resource utilization) olarak koydu: birden çok sürecin aynı kaynak üzerinde birbirini etkilemeden iş yapabilmesi gerekir. Bunun için zaman içinde semafor gibi yöntemler tanımlanmış, sonra monitör kavramının içinde koşul değişkeni (condition variable) ortaya atılmıştır. Öğrenci, monitörlerin Brinch Hansen ve Dijkstra ile birlikte ortaya çıktığını, Hoare'un makalesinin bunun üzerine kurulduğunu ve koşul değişkenini monitörlerin içine yerleştirdiğini aktardı.

Hoca semaforda kaç temel işlem olduğunu sordu. Cevap: iki işlem vardır, bugün **wait** ve **signal** diye bilinir. Dijkstra bunları ilk ortaya attığında **P** ve **V** diye adlandırmıştır. P "test etmek", V "artırmak" anlamındaki Hollandaca sözcüklerden gelir: biri semaforun durumunu test eder, diğeri değerini artırır. Zamanla P işlemi wait, V işlemi signal adını almıştır.

> **Ders sonrası not:** Hoca bu dönüşümü anlatırken "test etmek V'ye dönüşüyor" dedi. Doğrusu test (P) işleminin wait'e, artırma (V) işleminin signal'a dönüşmesidir; hoca cümlenin devamında V'nin signal'a dönüştüğünü doğru söyledi.

## 4. Koşul Değişkenine İlk Bakış

Hoca, koşul değişkeninde de wait ve signal olduğunu hatırlatıp semafordan farkını sordu. Bir öğrenci makalenin koşul değişkenini "değişken değil" ya da "Boolean değişken değil" diye nitelediğini söyledi. Hoca "değişken" ile "Boolean değişken"in çok farklı şeyler olduğunu vurgulayıp hangisinin kastedildiğini sordu. Öğrenci bunun yeni bir değişken tipi olduğunu, bu tipin süreçlerden oluşan bir kuyruk oluşturduğunu, yani kuyruğun elemanlarının süreçler olduğunu söyledi.

Hoca "bu değişkenin bir değeri var mı, varsa bizim için önemi var mı?" diye sordu ve koşul değişkenini monitör yapısının özü olduğu için ayrıca anlatacağını söyledi (bkz. bölüm 6). Öğrencinin açıklamasına göre kaynağı almak isteyen süreçler bu kuyruğa konarak takip edilir; kaynak bir süreç tarafından bırakılınca sıradaki süreç, ilk mantığa göre, kaynağı ele alır.

## 5. Monitörün Tanımı, Adı ve Simula 67 Sınıf Notasyonu

### 5.1 Sınıf kavramı

Bir öğrenci, semaforun yalnızca bir değişken olduğunu, monitörün ise makalede bir sınıf (class) gibi, bütün sistemi ifade eden bir tip olarak göründüğünü söyledi. Hoca burada ilginç bir ana dikkat çekti: 1974 yılında sınıf kavramından, yani nesneye yönelik programlamanın temelindeki yapıdan söz ediliyor. Bu notasyon **Simula 67** programlama dilinin sınıf notasyonundan gelir. Bir öğrenci bunun veri soyutlamasını (data abstraction) gerçekleştirmek için olduğunu ekledi: sürecin hangi veriye, hangi değişkene erişmesi gerektiğini ve hangisine erişmemesi gerektiğini tanımlamak için.

Hoca semaforla farkı yeniden toparladı: semaforda değişkene doğrudan erişim vardır, monitörde ise erişim bir prosedür üzerinden yapılır.

### 5.2 Makaledeki tanım

Bir öğrenci makalenin monitör tanımını okudu:

> "Each scheduler will consist of a certain amount of local administrative data, together with some procedures and functions which are called by programs wishing to acquire and release resources. Such a collection of associated data and procedures is known as a monitor; and a suitable notation can be based on the class notation of SIMULA67."

Yani kaynak dağıtan her zamanlayıcı bir miktar yerel yönetim verisinden ve kaynak almak ya da bırakmak isteyen programların çağırdığı prosedür ve fonksiyonlardan oluşur; bu veri ve prosedür topluluğuna **monitör** denir.

### 5.3 Monitörün yapısı

Hoca makaledeki notasyonu sözlü olarak şöyle anlattı: monitör adı `monitor` anahtar sözcüğüyle tanımlanır ve `end` ile biter. Monitörün kendi `begin` kısmı vardır; hemen arkasında monitöre yerel verilerin bildirimleri gelir; sonra bir ya da daha çok prosedür gelir; en altta, `end`'in hemen üstünde, önemli bir kısım bulunur: monitörün yerel verisinin ilk değer ataması. Bu sıralama aşağıdaki iskeletle özetlenebilir (iskelet hocanın sözlü anlatımından kurulmuştur):

```text
<ad>: monitor
begin
    declarations of data local to the monitor
    procedure <ad> (...)  begin ... end    -- birden fazla olabilir
    ...
    initialization of local data of the monitor
end
```

Hoca "bu, sınıf kavramında neye denk düşer?" diye sordu. Cevap: **yapıcıya (constructor)**. Monitör oluşturulduğunda yerel değişkenler almaları gereken ilk değerleri alır. Hocaya göre bu, kullanıcı hatasını en aza indiren bir özelliktir.

### 5.4 Monitör bir kaynak zamanlayıcısıdır

Hoca, işletim sistemi açısından her monitörün yerine getirdiği görevin teknik adını sordu: **resource scheduler** (kaynak zamanlayıcı). Paylaşılmasını istediğim bir kaynak varsa, o kaynak için bir monitör oluşturmalıyım; monitörün anlamı budur.

Monitörden önce, semafor varken durum şöyledir: tek bir global değişken vardır ve herkes ona erişir; işletim sistemi bu değişkeni güncellemek için iki işlem sağlar (P ve V); geri kalan bütün sorumluluk kaynağa erişen uygulamalardadır. Monitörde ise erişimi baştan sona monitör düzenler.

Sınıf notasyonundan çıkan bir sonuç daha vardır: çalışma anında, kullanım disiplini aynı olan farklı kaynakları zamanlamak için aynı monitörden birden fazla kopya oluşturulabilir.

### 5.5 Adın kökeni

Hoca "monitör" sözcüğünün anlamını sordu. Biz Türkçede monitörü daha çok görüntüleyen cihaz olarak düşünürüz, ama burada anlamı **gözetlemek**, denetlemek, kontrol altında tutmaktır. Hoca kavramın ilk ortaya atıldığında başka bir adla anıldığını sordu ve makalenin girişinin dördüncü paragrafını gösterdi. Orada monitör yapısının bir veri gösterimi için anlatılan yapıyla aynı olduğu, yalnız `monitor` sözcüğünün eklendiği ve **Brinch Hansen'in aynı amaç için "shared" sözcüğünü kullandığı** yazar.

## 6. Koşul Değişkeninin Değeri ve Arkasındaki Kuyruk

### 6.1 Değeri var mı?

Hoca sorusunu açtı: semaforu bir global değişkenle ifade ediyorum ve iki işlemi var, test ve artırma. Demek ki semaforun bir değeri vardır; test edilir ve artırılır. Benzer bir şey koşul değişkeni için de geçerli mi? Geçerliyse nasıl artırılır ya da test edilir; değilse nasıl çalışır?

Bir öğrenci semaforların süreçler arası, bütün sistemin erişebildiği bir değişken; koşul değişkenlerinin ise çalışan süreç üzerinde kurulan bir mekanizma olduğunu söyledi. Hoca bu yorumun doğru olmadığını, semaforla koşul değişkeni arasında böyle bir ayrım yapılamayacağını söyledi.

Başka bir öğrenci makaledeki tanımı okudu: koşul "değişkeni" ne doğru ne yanlıştır; aslında programın erişebileceği saklı bir değeri yoktur. Hoca bunu şöyle yorumladı: koşul değişkeninin içeride kullanılırken doğal olarak bir değeri olacaktır, ama bu değerin ne olduğu koşul değişkeni üzerinden kaynaklara erişecek süreçleri ilgilendirmez. Süreçler onun değerine göre karar vermez. Böylece programlar o tarafın çalışma ayrıntılarından soyutlanmış olur.

### 6.2 Ne işe yarar?

Hoca "koşul değişkeni neyi sağlar, neden ihtiyaç duyarız?" diye sordu. Bir öğrenci "bekleyenleri sıraya koymak için" dedi. Hoca bundan önce gelen adımı sordu: önce **bekletmek** gerekir. Sıraya koymak ayrı bir şeydir; önce bekletebilmek lazımdır, çünkü sorun zaten kaynaklara aynı anda erişimi engellemektir. Bir öğrenci ikinci görevi ekledi: bekletilen sürecin, gereken kaynak serbest kalınca yeniden çalışmaya başlamasını da sağlamak gerekir.

Hoca bunu onayladı ve sordu: değeri önemli olmasa da bu bekletmeyi ve yeniden çalıştırmayı sağlamak için her koşul değişkeninin arkasında nasıl bir veri yapısına ihtiyaç vardır? Cevap: bir **kuyruk**.

### 6.3 Kuyruk programlara görünmez

Bu kuyruk dışarıya açılmaz; programlar kuyruğun farkında değildir. Arkadaki temel düşünce şudur: aynı kaynağa kaç sürecin aynı anda eriştiğinin önemi yoktur. Her süreç kaynağa sanki yalnız kendisi erişiyormuş gibi algılar. Bu çok saydam (transparent) yapıldığı için süreç diğerlerinden haberdar olmaz, bekletildiğinin de farkına varmaz.

## 7. Programcıya Sağlanan Soyutlama

Hoca bu saydam yapının kime ne rahatlık sağladığını sordu ve "kullanıcı" yerine o süreci yazacak **programcıyı** kastettiğini belirtti. Cevap: programcı yönetim maliyetinden kurtulur. Kaynağa yalnız kendi programı erişiyormuş gibi yazar; "şu değer dönerse bunu mu yapacağım, isteği yeniden mi göndereceğim?" gibi sorularla uğraşmaz.

Temel semafor yapısında ise programcıya yüklenen sorumluluk şudur: semafor üzerinde uyguladığı P ve V işlemlerinin sonucuna göre kendisi denetim yapmalı ve doğru denetlemelidir. Semaforun ilk değerini de doğru vermelidir; yanlış ilk değer yine soruna yol açar.

> **Hocanın vurgusu:** Monitör, programcıları erişecekleri kaynaklara erişirken başka kaç sürecin eriştiği bilgisinden ve buna bağlı alınması gereken önlemlerin karmaşıklığından tamamen yalıtır, soyutlar. Bütün yükü monitör üstlenir.

## 8. Makaledeki Örnekler ve İşletim Sistemindeki Karşılıkları

### 8.1 Örnekler neden verilmiş?

Hoca makaledeki örneklerin neden monitörle denendiğini sordu. Bir öğrenci, başka araçlarla (örneğin mutex ile) çözülen örneklerin monitörle de çözülebildiğini göstermek için olduğunu söyledi; hoca bunu doğru buldu ve ikinci bir sebep sordu. Başka bir öğrencinin "ikna etmesi zor durumlar olduğu için" yorumunu hoca reddetti.

Hocanın açıklaması şudur: monitör bir kaynak yöneticisiyse, ilgili tipteki kaynağı o kaynağın kullanım politikasına, kullanım disiplinine uygun yönetecek biçimde hazır olmalıdır. Çünkü amaç kullanıcıyı bu işten yalıtmaktır; kullanıcı koduna özel bir şey yazmak zorunda kalmamalı, yalnız kullanma isteğini dile getirmelidir. O halde eşzamanlı erişime açık kaynak tiplerindeki mevcut kullanım senaryolarının ne kadarının, hatta tamamının desteklenip desteklenmediğini görmek için bu senaryolar monitörlerle sınanır. Örnekler işletim sistemindeki temel servisleri ve temel kaynak kullanım senaryolarını tarif eder: kaynağa bir zamanlamayla erişilmesi, kaynağın tek ya da çok kopyalı olması, eşzamanlı erişime izin verilip verilmemesi.

### 8.2 Tek kaynak zamanlayıcısı (single resource scheduler)

Makalenin özetinde geçen ilk örnek budur: tek bir kaynak vardır, ona teker teker erişilmelidir; biri bitince diğeri. Öğrenciler önce manyetik teyp, konsol, yazıcı, disk gibi kaynakları ve sürücüleri saydı. Hoca bunların hepsinin kaynak olduğunu, ama sorunun "tek kaynak" kavramı olduğunu söyledi.

Hocanın açıklaması: bazı kaynaklar aynı anda çoklu erişime yatkındır. Örneğin bellek; bir kısmını bir sürece, bir kısmını başka bir sürece aynı anda kullandırabilirim. Ama tek bir CPU varsa herhangi bir t anında onu ya A süreci ya da B süreci kullanır. Yazıcı da böyledir: iki sürecin aynı anda yazıcıya çıktı göndermesine hiçbir zamanlama yapmadan izin verirsem, bir satırda birinin, sonraki satırda öbürünün, hatta aynı satırda iki harf birinin, üç harf öbürünün çıktısı olur. Bu tür kaynaklar tek kaynaklardır.

### 8.3 Sınırlı tampon (bounded buffer)

Bir öğrenci üretici-tüketici durumunu anlattı: biri yazarken başka biri okur; okumalar tek başına sorun olmasa da yazmalarda sorun çıkar, bu yüzden senkronize etmek gerekir. Hoca tek sorunun bu olmadığını hatırlattı: tüketici yavaş, üretici hızlı çalışıyorsa ne olur? Hızlı olan süreç yavaş olanı beklemelidir; bu yüzden aradaki veriyi tamponlayabilmek gerekir.

### 8.4 Alarm saati (scheduled wait)

Hoca "alarm saati" örneğinin sabah kalkmak için kurduğumuz saat olarak mı anlaşılacağını sordu. Cevap: zamanlayıcıdan (timer) söz edilir. İleride oluşacak bir olaydan haberdar olunması ve ona göre bir eylemin gerçekleşmesidir; belirli bir süre bekleyip sonra devam etmek.

### 8.5 Tampon havuzu (buffer allocation)

Hoca "buffer pool"un anlamını sordu. Bir öğrencinin "aynı bellek alanına birden fazla sürecin erişmesi" cevabını hoca kabul etmedi; üretici-tüketici cevabına da bunun doğrudan üretici-tüketici olmak zorunda olmadığını, orada da kullanılabileceğini söyledi. <!-- BELİRSİZ: tampon havuzunun tanımı derste açıkça verilmedi; tartışma sınırlı tampon örneğine kaydı -->

### 8.6 Disk kafası zamanlayıcısı ve asansör problemi

Hoca, bugün artık çoğunlukla SSD kullanılsa da bu örneğin asansör (elevator) problemi olarak da bilindiğini söyledi. 30 katlı bir binada farklı katlardan istekler geliyor; bu istekleri sıralayacak bir kaynak zamanlayıcı yazsaydınız başarı ölçütünüz ne olurdu? Öğrenciler doğru kata gitmeyi, enerji maliyetini ve gecikmeyi azaltmayı, aynı anda daha çok kişiyi istediği yere ulaştırmayı saydı. Hoca doğru kata gitmenin zaten zorunlu olduğunu, enerjinin de ikinci bir hedef olduğunu belirtip asıl ölçütü **ortalama bekleme süresini en aza indirmek** diye koydu.

Diskte de aynı durum vardır: kafa o an X konumundadır, veri Y konumundadır; kafayı oraya götürmenin maliyeti gecikmedir ve uygulama yavaşlar. Diske birden fazla uygulama erişir ve diskin iki farklı yerinden aynı anda okunamaz. Bu yüzden istekler bir sıraya sokulmalıdır; öyle bir sıra ki gecikme ortalamada en az olsun. Mutlak en az problemin doğası gereği mümkün değildir, ama ortalama en aza indirilebilir.

### 8.7 Okuyucular-yazarlar (readers and writers)

Bir öğrencinin özetine göre birden fazla okuma sorun değildir, ama bir yazma ile okuma aynı anda yapılırsa okunan değerin tutarsız olma ihtimali doğar; bu yüzden erişimler sıraya sokulmalıdır.

Hoca örnekleri şöyle bağladı: monitör, programcıları alt taraftaki ayrıntılardan uzaklaştıran güzel bir yapıdır; ama ortaya atılan bu yapının klasik senkronizasyon problemlerine cevap verebildiğini ve onları sorunsuz gerçeklemeye imkan sağladığını da göstermek gerekir. Makalenin örnekleri bunu yapar. Makalenin sonraki bölümleri sırasıyla sınırlı tamponu, zamanlanmış beklemeyi (alarm saati) ve "Further Examples" başlığı altında tampon tahsisini, disk kafası zamanlayıcısını ve okuyucular-yazarlar problemini içerir.

## 9. Monitörü Semaforla Gerçeklemek ve Monitörü Kim Yazar?

### 9.1 İki yönlü gerçekleme

Bir öğrenci makalenin ilk olarak semaforun monitörle yazılabildiğini gösterdiğini hatırlattı. Hoca makalenin devamını okudu: "Having proved that semaphores can be implemented by a monitor, the next task is to prove that monitors can be implemented by semaphores." Hocaya göre bu, monitör yapısının ne kadar esnek olduğunu göstermek açısından güzeldir. Semaforun monitörle gerçeklenmesi makalenin hemen başında ve çok basittir. İkinci bölüm ise monitörün semaforla nasıl gerçekleneceğini, koşul değişkeni üzerinden adım adım anlatır; bir A4 sayfasından biraz kısadır.

### 9.2 Kuyruğu kim yönetir?

Bir öğrenci koşul değişkeninin yükünü derleyicinin üstlendiğini, kuyruğu ve wait/signal işlemlerini programcının yazmadığını öne sürdü. Başka bir öğrenci bunu işletim sisteminin, bir diğeri programlama dilinin yaptığını söyledi. Hoca "gerçeği söylüyorum, belki üzüleceksiniz" diyerek açıkladı: koşul değişkeninin arkasındaki kuyruğun oluşturulması ve yönetilmesiyle ilgili kod parçalarını insanlar yazar. Bu kod ya işletim sisteminin içinde bir parça olarak ya da paylaşılan kütüphane (shared library) gibi bir çalışma ortamının (runtime environment) parçası olarak kullanıma sunulur. Ne işletim sistemi o anda dinamik olarak arkada bir şey üretir ne de programlama dili; bunlar önceden kodlanmış ve hazırdır.

### 9.3 Kendi monitörümü yazabilir miyim?

Hoca isteyenin kendi monitörünü de kodlayabileceğini söyledi ve nedenini sordu. Cevap: monitör kendisi bir programdır; içinde yapıcısı, prosedürleri, fonksiyonları ve yerel verisi vardır, ve monitörler semaforlarla gerçeklenebilir. O halde işletim sisteminde semafor desteği varsa, bu işten anlayan bir programcı temel kavramları kullanarak kendi monitörünü yazabilir.

Ama bunu yapması gerekmez ve istenmez. Makale tam da bu işi programcıdan almaya çalışır: bu karmaşık ve hataya açık bir iştir. Programcı semaforu düzgün kullanmazsa Hoare'un deyişiyle "deadly embrace" (ölümcül kucaklaşma, yani kilitlenme) oluşur. Bunun olmaması için farklı senaryolara yönelik monitörler kodlanmış ve hazır gelmelidir.

## 10. Donanım Desteği: Atomik Komutlar

Bir öğrenci, işletim sistemini yazan biri olarak monitör ya da semafor gibi senkronizasyon yapılarını sunabilmek için donanımdan atomik komutların gelmesi gerekip gerekmediğini sordu: yapılan işlemin kesin olarak belleğe yazıldığını ya da değişkene aktarıldığını garanti eden komutlar olmadan bu yapılar kurulabilir mi?

**Cevap:** Kurulamaz. Modern işlemci mimarisinin temelinde bu yatar; atomik erişim mantığı en baştan tasarıma konmuştur. Bugün geriye kalan işlemci ailelerinin (Intel, ARM, PowerPC) hepsinde atomik komutlar vardır; başka birçok işlemci ailesi neredeyse ortadan kalkmıştır. Atomik komutlar işin en altında, donanımın kendisindedir. Onların varlığı semafor yazmayı, semafor yazabilmek de monitör yazmayı mümkün kılar; bunlar zincirleme bağımlılıklardır.

> **Ek bilgi (derste anlatılmadı):** Bu tür atomik komutlara örnek olarak test-and-set, compare-and-swap (x86'da `LOCK CMPXCHG`) ve ARM'daki load-linked/store-conditional çiftleri (`LDREX`/`STREX`) verilebilir. Bunlar bir bellek konumunu okuyup değiştirme işlemini araya başka bir işlemcinin giremeyeceği biçimde yapar.

## 11. Kuyruk Disiplini: FIFO, Öncelik, Açlık ve Konvoy

Bir öğrenci makalenin koşul değişkenleri hakkındaki başka bir noktasını aktardı: bekleyen süreçler başlangıçta basit bir FIFO yapısında, ilk giren ilk çıkacak biçimde (first come, first served) hizmet alır. Makale sonra koşul değişkenleri için bir **öncelik (priority)** kavramı önerir; amaç daha öncelikli işlere daha çabuk hizmet verebilmektir. Ama öncelik getirilince bir problem ortaya çıkar. Öğrenci önce kilitlenmeyi söyledi; hoca düzeltti: problem **açlıktır (starvation)**. Düşük öncelikli süreç kaynağı alamaz ve beklemek zorunda kalır.

Hoca FIFO'nun neden seçildiğini sordu. Öğrenci en basit yöntem olduğu için seçildiğini söyledi. Hoca ekledi: ilk gelene ilk hizmet verildiğinde, çok bekleyenin de hizmet alacağı garanti edilir; herkes kaynaktan zaman alabilir. "Bu çok bekledi, önce ona süre verirsem ortalama bekleme süresini azaltırım" güzel bir yaklaşımdır, ama sonradan ortaya çıkan, ilk bakışta görülmeyen bir sorun vardır.

Sorun şudur: öndeki süreç paylaşılan kaynağı (örneğin işlemciyi) çok uzun kullanma ihtiyacındaysa, diğerlerinin bekleme süresi inanılmaz derecede uzar. Hoca bunu yavaş bir konvoyun arkasında kalmaya benzetti: geçmek isteseniz geçemezsiniz, sollamak sıkıntılıdır, hızınızı artıramazsınız; konvoyun hızında ilerlemek zorundasınız. Bu durumun adı **konvoy** olgusudur; hoca bunun için "sendrom değil, semptom" ifadesini kullandı.

> **Ek bilgi (derste anlatılmadı):** İşletim sistemi literatüründe bu olgu genellikle "convoy effect" (konvoy etkisi) diye anılır; FCFS zamanlamada uzun bir işin arkasında kısa işlerin birikmesini anlatır.

Öncelikli yaklaşımdaki açlığın çözümü **yaşlandırmadır (aging)**: süreç bekledikçe önceliği yükseltilir, böylece sonunda kaynaktan zaman alabilir. Hizmet aldıktan sonra önceliği yeniden olması gereken değere çekilir.

## 12. Mesa ve Pilot: Monitörler Gerçek Bir Sistemde

Aradan sonra ikinci makaleyi bir öğrenci sundu. Yazarlar çalışmaya başlarken literatürde eşzamanlı çalışma için monitörün birçok kez tanımlandığını ve üzerinde çok çalışıldığını, ama gerçek sistemlerde karşılığının neredeyse olmadığını görmüşlerdir. Bu yüzden monitörleri gerçek bir sistemde kullanmış ve ortaya çıkan sorunları ele almışlardır.

Öğrencinin aktardığı sorunlar şunlardır:

- Monitör çağrılarının anlamı (semantiği)
- wait ve signal'in farklı biçimlerde tanımlanmasının yol açtığı karmaşıklık
- Öncelikli zamanlama (priority scheduling)
- Zaman aşımı (timeout)
- İptaller (abort) ve diğer istisnai durumlar
- Yaratma ve yok etme (creation, destruction)
- Çok sayıda küçük nesnenin izlenmesi

<!-- BELİRSİZ: öğrenci makalenin sekiz sorundan söz ettiğini söyledi, ama altyazıda yedi madde sayılabiliyor -->

Yazarlar eşzamanlı programlama ve senkronizasyon için **Mesa** dilini kullanmış ve bunu gerçek bir işletim sistemi üzerinde deneme şansı bulmuşlardır. Hoca Mesa dilinin hangi işletim sistemiyle ilişkili olduğunu sordu: **Pilot**.

Çalışma üç ana başlık üzerinde yürütülür:

- **Local concurrent programming** (yerel eşzamanlı programlama)
- **Global resource sharing** (global kaynak paylaşımı)
- **Replacing interrupts** (kesmelerin yerine geçme)

Hoca bunların birbirini takip eden adımlar olmadığını vurguladı: üçü de Pilot içinde monitör yapısı kullanılarak nereye kadar iyileştirme yapılabileceğini görmek için ortaya konmuş, geliştirmeye açık üç ayrı noktadır.

### 12.1 Yerel eşzamanlı programlama

Öğrencinin açıklamasına göre burada bir uygulamanın içinde eşzamanlı çalışması gereken işlemler çok sıkı biçimde bir araya getirilir ve sanki birden fazla işlem değil de tek parça bir işlem çalışıyormuş gibi yürütülür. Amaç uygulamanın hızını ve kaynak kullanım verimini artırmak, tasarımın karmaşıklığını azaltmak ve yönetimini kolaylaştırmaktır. Hoca makalenin girişindeki cümleyi okudu: "An individual application can be implemented as a tightly coupled group of synchronous processes to express the concurrency inherent in the application." Yani uygulamanın içindeki eşzamanlılığı en net biçimde ortaya koymak için uygulama sıkı bağlı bir senkron süreç grubu olarak yazılabilir.

Hoca "sıkı bağlı süreç grubunun bir adım sonrası nedir?" diye sordu; bunun bilinmesi ya da en azından duyulmuş olması gerektiğini söyledi. Bir öğrenci "tek süreç ama çok iş parçacıklı (multi-thread) yapılar" dedi ve hoca onayladı: süreçleri sıkı bağlı yapıyor ve olabildiğince hızlı, etkin, yüksek performanslı çalıştırmak istiyorsanız, bunlar kendiliğinden iş parçacığı (thread) mantığına dönüşür.

## 13. Kesmelerin Monitörle Soyutlanması

### 13.1 Kesme sırasında ne olur?

Öğrenci "replacing interrupts" başlığını şöyle yorumladı: geleneksel sistemlerde kesme geldiğinde yüksek öncelik sebebiyle çalışan işler durdurulur ve kesmeye öncelik tanınır; burada ise gelen kesmenin bir süreç gibi yürütülmesi ve diğer uygulamaların çalışmasına engel olmaması hedeflenir.

Hoca kesme işlenirken ne olduğunu sordu. Bir öğrenci yazılım kesmesi örneği olarak `int 80`'i verdi: kesme gelince kesme tablosundaki karşılığı çalıştırılır, komut göstericisi (instruction pointer) değişir, rutin çalışır ve bitince geri dönülür. Hoca bunu kabul etti ve kesmeyle çalışan (interrupt-driven) bir program üzerinden genelleştirdi: programa bir kesme geldiğinde akışı kesintiye uğrar ve özel bir adrese zorla götürülür. Program kendisi öyle bir komut çalıştırmadığı halde sanki bir atlama komutu çalıştırmış gibi olur; buna **forced branch** (zorunlu dallanma) denir. Kesmeyle ilgili rutine gidilir, orada iş yapılır, sonra geri dönülür. Bu klasik yaklaşımda işletim sisteminin kendi başına yapabileceği çok şey yoktur, çünkü bu kod parçaları birinci seviyede donanımla muhataptır.

### 13.2 Diske yazan program örneği

Bir program diske yazmak istiyor ve yazma bitmeden devam etmeyecek. İşletim sistemi yazmanın bittiğini nasıl anlar? Bir kesme oluşur. Bu bilginin yukarıdaki yazılıma da aktarılması gerekir, çünkü program başlattığı işin bitip bitmediğini bilmeden devam edemez.

Hoca bu arada programın yapabileceği bir şey olup olmadığını sordu. Cevap: yoktur; kesmenin gelip gelmediğini beklemek için kod çalıştırmasının hiçbir anlamı yoktur. İşlemci kullanımını iyileştirmek için bu programı **uyutmak** gerekir.

Hoca monitördeki kuyruk ve wait yapısını hatırlattı. Program diske, bu amaçla yazılmış bir monitör üzerinden erişirse yazma tamamlanana kadar kendiliğinden uyutulur. Yazma bitince işletim sistemine kesme gelir (ki o kesmenin işlenmesi zaten zorunludur); işletim sistemi de monitörün signal tarafını tetikler. Bekleyen program kaldığı yerden devam eder, çünkü işi bitmiştir. Böylece alt seviyede kesmeyle gerçekleşen mekanizma, üst seviyede tamamen yazılıma, basit bir uyutma ve uyandırmaya dönüştürülmüş olur.

Akış şöyle özetlenebilir:

```text
süreç: disk_write(...) çağırır
  -> monitörde wait: süreç uyur, işlemciyi bırakır
donanım: yazma biter, kesme oluşur
  -> işletim sistemi kesmeyi işler
  -> işletim sistemi monitörde signal'ı tetikler
süreç: uyanır, disk_write geri döner, süreç devam eder
```

### 13.3 Bu yaklaşımın getirileri

Hoca bu yaklaşımın birkaç güzelliğini sordu:

- Monitör yapısı bu işe birebir uyar.
- Uykuya yatan parça gereksiz yere işlemci kullanmaz; işlemciyi kendiliğinden bırakır, işlemci boşa çıkar.
- Aynı kesme mantığının yazılımda yukarıda da kurulduğunu düşünün: boşuna döngüde bekleyen programı zorla başka bir yere götürüp "sana kesme geldi" diye zaten sonucu bilinen bir şeyi aktarmak, sonra kaldığı yere döndürmek gerekirdi. Monitörle buna gerek kalmaz.
- Programcı yine soyutlanmıştır: uyutulduğundan, uyandırıldığından haberi yoktur. Koda tek satır yazar. Disk yavaşsa belki 10 saniye bekler, SSD hızlıysa belki 1 milisaniye ya da daha az bekler; programcının bununla ilgilenmesi gerekmez.

Bir öğrenci "programın başka işleri varsa onları yapar" dedi. Hoca bunu birinci başlıkla birleştirerek açıkladı: program kendi içinde sıkı bağlı parçalara bölünmüşse ve bir parçanın görevi yalnız diske yazmaksa, o parça uyutulur ama eşzamanlılık yapısı içinde ilerleyebildiği sürece programın geneli akmaya devam eder.

Hoca bunun ne kadar modern bir düşünce olduğuna dikkat çekti ve bugünkü işletim sistemlerinin temellerinin bu çalışmada görüldüğünü söyledi. Bir öğrenci bunun bugünkü dillerdeki asenkron yapılara karşılık gelip gelmediğini sordu; hoca kesinlikle öyle olduğunu söyledi.

> **Ders sonrası not:** Hoca bu makalenin 1977 yılında yazıldığını söyledi. Makale büyük olasılıkla 1979'da SOSP'de sunulmuş ve 1980'de Communications of the ACM'de yayımlanmıştır; Pilot ve Mesa üzerindeki çalışma 1970'lerin sonuna aittir.

> **Ek bilgi (derste anlatılmadı):** Mesa'daki monitörlerde Hoare'un signal'ı yerine notify kullanılır: uyandırılan süreç hemen çalışmaz, monitöre yeniden girdiğinde koşulu tekrar denetlemelidir (bu yüzden wait bir döngü içinde çağrılır). Bugün POSIX iş parçacıklarındaki ve Java'daki koşul değişkenleri de bu "Mesa semantiği"ni izler.

## 14. Global Kaynak Paylaşımı

Sunumu yapan öğrenciye göre bu başlık, birbirinden bağımsız uygulamaların aynı makinede çalışırken sistem kaynaklarını paylaşabilmesini tarif eder. Örneğin yoğun hesaplama gerektiren bir uygulama çalışırken diğer uygulamalar da işlemci kaynağına kesintisiz erişebilmelidir. Başka bir öğrenci bunu "birbirinden bağımsız programlar aynı kaynakları birbirini etkilemeden kullanabilir" diye özetledi.

Bir öğrenci bunun, birden fazla sürecin monitörleri çağırmasıyla sağlanıp sağlanmadığını sordu. **Cevap:** Evet. Bir monitörün arkada koruduğu ve zamanladığı kaynağa ihtiyaç duyan süreçler monitörü aynı anda çağırabilir. Kaynak o an daha önce çağrı yapmış bir süreç yüzünden meşgulse monitörün görevi çağıran süreci kuyruğa almaktır. Süreç bundan haberdar olmaz; askıya alınmış, beklemeye alınmış olur.

Makaleyi okuyan bir öğrenci, sınıflarla ilgili bölümde bugünkü sınıflardaki public ve private ayrımına ve süreç yaratmaya (process creation) karşılık gelen yapıların bulunmasının dikkatini çektiğini söyledi. Hoca, sınıf yapısının Simula 67 ile 1967'de çıktığını hatırlatıp bugün kullandığımız bu kavramın 55 yıllık olduğunu belirtti.

## Örnek Sorular

Derste ekranda soru gösterilmedi; aşağıdaki sorular hocanın derste sözlü sorduğu sorulardır.

**Soru 1** (derste sözlü, 00:11:39 ve 00:17:17): Semafor nedir ve üzerinde kaç temel işlem tanımlıdır?

> **Çözüm (derste verildi):** Süreçler arası senkronizasyon için işletim sisteminin sunduğu bir ilkeldir. İki işlemi vardır: Dijkstra'nın adlandırmasıyla P (test etmek) ve V (artırmak); bugünkü adlarıyla wait ve signal.

**Soru 2** (derste sözlü, 00:14:11 ve 00:15:01): "Monitor" sözcüğü burada ne anlama gelir ve kavram ilk ortaya atıldığında hangi sözcükle anılmıştır?

> **Çözüm (derste verildi):** Gözetlemek, denetlemek, kontrol altında tutmak anlamındadır. Brinch Hansen aynı amaç için "shared" sözcüğünü kullanmıştır.

**Soru 3** (derste sözlü, 00:24:31): Monitörün en altındaki "yerel verinin ilk değer ataması" kısmı sınıf kavramında neye karşılık gelir?

> **Çözüm (derste verildi):** Yapıcıya (constructor). Monitör oluşturulurken yerel değişkenler ilk değerlerini alır; bu, kullanıcı hatasını azaltır.

**Soru 4** (derste sözlü, 00:27:54): Koşul değişkeninin bir değeri var mıdır, bu değerin süreçler için önemi var mıdır? Koşul değişkeni ne işe yarar ve arkasında hangi veri yapısı bulunur?

> **Çözüm (derste verildi):** Makaleye göre koşul "değişkeni" ne doğru ne yanlıştır; programın erişebileceği saklı bir değeri yoktur. İçeride bir değeri olsa da süreçler bu değere göre karar vermez. Görevi önce süreçleri bekletmek, sonra kaynak serbest kalınca yeniden çalıştırmaktır. Arkasında, programlara görünmeyen bir süreç kuyruğu vardır.

**Soru 5** (derste sözlü, 00:34:43): Monitör kullanıldığında programcı neyden kurtulur; temel semafor yapısında programcıya hangi sorumluluk yüklenir?

> **Çözüm (derste verildi):** Monitörde programcı kaynağa tek başına erişiyormuş gibi yazar; dönen değerlere göre yeniden deneme gibi işlerle uğraşmaz. Semaforda ise ilk değeri doğru vermeli ve P/V işlemlerinin sonuçlarına göre denetimi kendisi, doğru biçimde yapmalıdır.

**Soru 6** (derste sözlü, 00:40:11): "Single resource scheduler" kavramına işletim sisteminden gerçek bir örnek veriniz.

> **Çözüm (derste verildi):** Tek bir CPU (herhangi bir t anında onu yalnız bir süreç kullanır) ya da yazıcı (zamanlama yapılmazsa iki sürecin çıktısı satır içinde bile karışır). Bellek ise aynı anda bölünerek birden çok sürece kullandırılabildiği için bu tür bir kaynak değildir.

**Soru 7** (derste sözlü, 00:47:04): Asansör ya da disk kafası için bir kaynak zamanlayıcı yazsaydınız temel başarı ölçütünüz ne olurdu?

> **Çözüm (derste verildi):** Ortalama bekleme süresini (gecikmeyi) en aza indirmek. Mutlak en az mümkün değildir, ortalama en aza indirilir; enerji gibi ölçütler ikincildir.

**Soru 8** (derste sözlü, 00:59:24 ve 01:00:04): Koşul değişkenine öncelik eklenince hangi problem doğar ve nasıl çözülür? FIFO'nun görünmeyen sakıncası nedir?

> **Çözüm (derste verildi):** Öncelik eklenince açlık (starvation) doğar; çözümü yaşlandırmadır (aging): bekledikçe öncelik yükselir, hizmet aldıktan sonra eski değerine çekilir. FIFO'da öndeki süreç kaynağı çok uzun kullanırsa arkadakilerin bekleme süresi çok uzar (konvoy olgusu).

**Soru 9** (derste sözlü, 01:16:43): Sıkı bağlı (tightly coupled) senkron süreç grubunun bir adım sonrası nedir?

> **Çözüm (derste verildi):** Tek süreç içinde çok iş parçacıklı (multi-thread) yapı.

**Soru 10** (derste sözlü, 01:22:04 ve 01:23:59): Diske yazan ve yazma bitmeden devam edemeyecek bir program yazma süresince ne yapmalıdır? Monitör bu durumu nasıl ele alır ve getirisi nedir?

> **Çözüm (derste verildi):** Program uyutulmalıdır. Monitör üzerinden yapılan çağrıda süreç wait ile uyur ve işlemciyi bırakır; yazma bitince oluşan kesmeyi işleyen işletim sistemi monitörün signal tarafını tetikler, süreç kaldığı yerden devam eder. Böylece kesme mekanizması üst seviyede uyutma-uyandırmaya dönüşür; işlemci boşa harcanmaz ve programcı bu ayrıntılardan soyutlanır.

## Dersin Toparlaması

Bu derste monitör kavramı iki makale üzerinden tartışıldı. Hoare'un makalesinde monitör, paylaşılan bir kaynağın yerel verisini, ona erişen prosedürleri ve ilk değer atamasını tek bir yapıda toplayan, Simula 67 sınıf notasyonuna dayanan bir kaynak zamanlayıcısı olarak tanımlanır. Semaforlar monitörlerin atasıdır; monitör, semaforda programcıya kalan bütün yükü (ilk değer verme, P/V sonuçlarını denetleme, kilitlenmeden kaçınma) üstlenir. Monitörün özü koşul değişkenidir: süreçlere açık bir değeri yoktur, arkasındaki gizli kuyrukla süreçleri bekletir ve uyandırır. Makaledeki örnekler (tek kaynak, sınırlı tampon, alarm saati, tampon havuzu, disk kafası, okuyucular-yazarlar) bu yapının işletim sistemindeki temel kaynak kullanım senaryolarını karşıladığını gösterir. Kuyruk disiplininde FIFO'nun konvoy sorunu ve önceliğin açlık sorunu, açlığa karşı da yaşlandırma konuşuldu. Atomik komut, semafor ve monitör arasındaki zincirleme bağımlılık da vurgulandı.

İkinci makalede aynı kavram Mesa dili ve Pilot işletim sistemi içinde gerçek bir sistemde sınanır. Yerel eşzamanlı programlama (ve onun ileri adımı olan iş parçacıkları), global kaynak paylaşımı ve kesmelerin monitörle soyutlanması tartışıldı. Özellikle diske yazma örneğinde, alt seviyedeki kesme mekanizmasının üst seviyede basit bir uyutma-uyandırmaya dönüşmesi, bugünkü asenkron programlama yapılarının temeli olarak gösterildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
