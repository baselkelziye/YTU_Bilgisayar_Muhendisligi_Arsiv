# Ders 2 Genişletilmiş Notu: Kontrolü Ele Geçirme Saldırıları: Buffer Overflow, Integer Overflow, Format String ve Use After Free

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kontrolü Ele Geçirme Saldırıları
- 2. İlk Örnek: Buffer Overflow ve C/C++
- 3. Saldırı İçin Gerekenler
- 4. 32 Bit Linux Süreç Bellek Düzeni
- 5. Stack Frame
- 6. Buffer Overflow Nedir?
- 7. Temel Stack İstismarı: Shell Kod ve NOP Slide
- 8. Gerçek Hayattan Örnekler
- 9. Güvensiz libc Fonksiyonları
- 10. Diğer Buffer Overflow Fırsatları
- 11. Heap Overflow ve C++ Vtable
- 12. Tarayıcı Heap'i ve Heap Spraying
- 13. Buffer Overflow Nasıl Bulunur?
- 14. Diğer Kontrol Ele Geçirme Saldırıları: Double Free
- 15. Integer Overflow
- 16. Format String Zafiyeti
- 17. Use After Free
- Örnek Sorular
- Dersin Toparlaması

## 1. Kontrolü Ele Geçirme Saldırıları

Dersin konusu, saldırganın karşı taraftaki bilgisayar sisteminin kontrolünü nasıl ele geçirdiğidir. Bu saldırılara İngilizce "control hijacking attack", Türkçe "kontrolün ele geçirilmesi saldırısı" denir. Slayt başlığındaki "basic" kelimesi, bunların temel saldırılar olduğunu gösterir. Bu iş başladığından beri hep aynı metodoloji ve aynı temel üzerinden gidilmektedir; günümüzde aynı sonucu veren daha gelişmiş ve karmaşık saldırılar da vardır, ama hepsi bu temelden çıkar.

Slayttaki tanım şöyledir (ekrandan, 00:05:00):

- **Attacker's goal:** Take over target machine (e.g. web server)
  - Execute arbitrary code on target by hijacking application control flow
- **Examples:** Buffer overflow and integer overflow attacks; Format string vulnerabilities; Use after free

Saldırganın amacı, saldırdığı sistemin (bir web, e-posta ya da DNS sunucusu olabilir) kontrolünü almaktır. Kontrolü sistemdeki en yüksek yetkili kullanıcı olarak ele geçirebilirse istediği her kod parçasını çalıştırabilir; ele geçirilen sistem, saldırganın kod çalıştırdığı ve başka yerlere saldırmak için kullandığı bir makineye dönüşür.

Hoca tanımdaki "by hijacking application control flow" kısmının altını çizdi. Saldırgan bir uygulamaya saldırmak, o uygulamadaki bir açıktan yararlanmak zorundadır. Uygulamalar belirli bir görev için tasarlanıp kodlanmıştır; içlerindeki zafiyetler kullanılarak planlanan amacın dışında başka bir kod parçasını çalıştırmaları sağlanır. Yüklenen kod, sıfırdan dosya sistemine yerleştirilip adı verilerek çalıştırılan bir program değildir. Çalışmakta olan bir sistem ya da kullanıcı uygulamasının akışı değiştirilir.

> **Hocanın vurgusu:** Saldırının özü, çalışan bir uygulamanın akışını değiştirmektir. "Burası kritik nokta, bunu lütfen aklınızdan çıkarmayın."

Bu saldırıların temel yaklaşımları sırasıyla buffer overflow, integer overflow, format string zafiyeti ve use after free'dir. Bu sıra iki şeyi birden gösterir: kronolojik olarak saldırılar buffer overflow ile başlamış ve zamanla use after free'ye doğru gitmiştir; aynı zamanda zorluk derecesi de bu sırayla artar. Buffer overflow yapmak integer overflow'dan, integer overflow da format string zafiyetinden yararlanmaktan daha kolaydır.

Slayttaki ifade farkına da dikkat çekildi. Buffer overflow ve integer overflow için doğrudan "attack" (saldırı) denir: bu zafiyet varsa hocanın deyişiyle "neredeyse yüzde 99.99" bir saldırıyla sonuçlanır. Format string için ise "vulnerability" (zafiyet) yazılmıştır: saldırı imkânı verebilir, saldırıyla sonuçlanabilir ya da saldırıda kullanılacak hassas bir bilgiyi ele geçirmeye yarayabilir.

## 2. İlk Örnek: Buffer Overflow ve C/C++

Slayt: "First example: buffer overflows. Extremely common bug in C/C++ programs. First major exploit: 1988 Internet Worm. Fingerd." (ekrandan, 00:10:00)

C ve C++ programlarına bu kapsamda, günümüz dahil, çok sayıda saldırı düzenlenmiştir. Programlama dilinin kendisinden kaynaklanan sorunlar da vardır, ama asıl neden yüksek seviyede yazılan kodun alt seviyeye (assembly) çevrilmesi ve çalıştırılmasıyla ilgili tasarım kararlarıdır. Bu yapı bir tasarımın sonucudur ve bu tasarımdaki bazı zafiyetler bir araya gelince saldırı inanılmaz kolaylıkla yapılabilir hâle gelmiştir. Hoca, anlatılanlar kafada canlandırıldığında bunun başka programlama ortamlarında da olabileceğinin anlaşılacağını söyledi.

C/C++'ın kritik yanı, bugün kullanılan işletim sistemlerinin neredeyse istisnasız C/C++ ile yazılmış olmasıdır. Uygulamaları çalıştırmak için kullanılan çalıştırma zamanı kütüphanelerinin (runtime library) de neredeyse tamamı C/C++'tadır. Slayttaki "whenever possible avoid C/C++; often cannot avoid C/C++" ifadesi bunu anlatır: bu dilleri göz ardı etme ya da kullanmama seçeneğimiz çoğu zaman yoktur.

Bu zafiyetin saldırıya dönüştüğü ilk büyük olay 1988'deki Internet Worm'dur ve Unix'teki `fingerd` servisine yapılmıştır. Unix terminolojisinde bir uygulamanın adının sonundaki "d", onun sürekli çalışan bir servis (daemon) olduğunu gösterir. Daemon komut satırından başlatılır, sonra arka planda çalışmaya devam eder; çoğunlukla işletim sistemiyle birlikte açılıp onunla birlikte kapanır. Bu süreklilik saldırganın işini kolaylaştırır: servis her an saldırıya açıktır, programın o anda açık olup olmadığını düşünmeye gerek kalmaz.

Slayttaki grafik (kaynak: web.nvd.nist.gov) yıllara göre bildirilen buffer overflow zafiyeti sayısını gösterir; 1997'de sıfıra yakın olan sayı 2015'te yaklaşık 1000'e çıkmıştır (ekrandan, 00:10:00). Hoca bunun yanlış anlaşılmamasını istedi: 1000, 1000 farklı uygulamada zafiyet bulunduğu anlamına gelir. Bu uygulamaların her birinin on binlerce, yüz binlerce kopyası çalışabilir ve onları kullanan bütün sistemler bu zafiyetten etkilenir. Bir yılda bin farklı uygulamada bu zafiyetin bulunup kullanılabilir hâle getirilmesi ciddi bir güvenlik açığıdır.

## 3. Saldırı İçin Gerekenler

Slayt "What is needed" (ekrandan, 00:15:00):

- Understanding C functions, the stack, and the heap.
- Know how system calls are made
- The exec() system call
- Attacker needs to know which CPU and OS used on the target machine:
  - Our examples are for x86 running Linux or Windows
  - Details vary slightly between CPUs and OSs: Stack Frame structure (Unix vs. Windows); Little endian vs. big endian

Öncelikle C fonksiyon yapısını ve çalışma zamanı ortamını bilmek gerekir; C fonksiyonları çalışırken stack ve heap'ten bolca yararlanılır. İşletim sistemi açısından sistem çağrılarının nasıl yapıldığı da bilinmelidir. Özellikle önemli olan sistem çağrısı, kod çalıştırmaya yarayan `exec`'tir (execute'tan kısaltılmış). Saldırgan çalışan uygulamanın akışını değiştirip kendi gönderdiği kodu çalıştıracaksa onu bir şekilde başlatabilmelidir.

Saldırılan sistemin işlemci mimarisi de bilinmelidir. İşlemci mimarisi değişince komut seti değişir: Intel, Power ya da ARM olması saldırıda kullanılacak komutları değiştirir. Saldırı kodu çoğu zaman üst seviyeli bir dilde yazılır ve komut karşılığı derleyiciyle elde edilir; istenirse doğrudan assembly ile de yazılabilir.

İşlemcilerin belleğe erişim sırası da önemlidir. Tek byte için bu sıra bütün işlemcilerde aynıdır, ama 16 bitlik bir tam sayıda önce düşük anlamlı mı yüksek anlamlı byte'ın mı geleceği işlemciye göre değişir; her ikisini kullanan işlemciler vardır:

- **Little endian:** Düşük adreste düşük anlamlı byte, yüksek adreste yüksek anlamlı byte bulunur. Bellekten okunan değer kâğıda yazılıp kontrol edilmek istendiğinde yüksek adresli byte önce, düşük adresli sonra yazılmalıdır.
- **Big endian:** Düşük adreste en yüksek anlamlı byte bulunur. Bellekte görülen sırayla kâğıda yazıldığında sıranın değiştirilmesi gerekmez.

Hoca bunu "biri bize yakın, biri makineye yakın" diye özetledi.

İşletim sisteminin Unix ya da Windows olması, fonksiyon çağrısında stack'te oluşturulan veri yapısında (stack frame) bazı değişiklikler gerektirir. Ama bunlar küçük farklardır; bir saldırıyı imkânsız kılmaz ya da bir işletim sisteminden diğerine taşınmasını çok zorlaştırmaz. Derste kolaylık için Linux ve 32 bit üzerinden gidildi. Örneklerin hepsi 64 bite ve Windows'a da uygulanabilir; 64 bitte adresler çok daha uzun olduğu için yazılması, okunması ve kullanılması daha zordur.

## 4. 32 Bit Linux Süreç Bellek Düzeni

Her sürecin bir sanal adres uzayı (memory layout, address space) vardır. Bu uzay sıfır adresinden başlayıp işletim sisteminin süreçler için tanımladığı en yüksek adrese kadar gider. Slayttaki şekil (ekrandan, 00:20:00) yukarıdan aşağıya şöyledir:

| Bölge | Adres | Büyüme yönü |
|---|---|---|
| user stack | `0xC0000000`'den aşağı | aşağı (`%esp` tepeyi gösterir) |
| boş alan | | |
| shared libraries | `0x40000000`'den başlar | yukarı |
| run time heap | executable'ın üstünde | yukarı |
| loaded from executable | `0x08048000`'den başlar | |
| unused | `0` ile `0x08048000` arası | |

**Stack.** 32 bit Linux'ta bir sürecin sahip olabileceği en yüksek adres `0xC0000000`'dir; 64 bitte bu sınır çok daha yukarıdadır. Bu adresten aşağı doğru user stack bulunur ve stack'in büyüme yönü negatiftir: stack kullanıldıkça adresler azalır. Normalde bir değişkene, diziye ya da yapıya erişirken adresler artar. Bunun nedeni şekilden anlaşılır: yukarıda aşılmaması gereken bir limit, aşağıda bir başlangıç noktası vardır. Program çalışırken komutlara ve değişkenlere pozitif yönde, stack işlemlerinde negatif yönde adresleme yapılır; böylece iki taraf birbirine doğru ilerler. Stack aşağı doğru çok ilerleyip paylaşılan kütüphanelerin ya da heap'in üstüne gelirse **stack overflow** oluşur: stack için yer kalmamış, stack programın diğer verilerinin, hatta programın kendisinin alanına taşmıştır.

**Paylaşılan kütüphaneler.** Shared library'ler `0x40000000` adresinden başlamak zorundadır; bu, Linux süreç bellek düzeni tasarlanırken verilmiş bir karardır. Bunlar yalnız bizim programımızın değil bütün programların çalışma zamanında ihtiyaç duyduğu kütüphanelerdir: giriş-çıkış, matematik işlemleri, thread işlemleri gibi. En önemlisi C çalışma zamanı kütüphanesi `libc`'dir. Linux'ta `/lib` ya da `/usr/lib` altında hem `libc` hem `libc++` bulunur; bu iki kütüphane işletim sistemi sürümüyle birlikte ilerler ve bütün uygulamaların çalışmasının temelidir.

**Kullanılmayan alan ve program.** Sıfırdan programın yüklendiği adrese kadar olan kısım kullanılmaz (unused). Bu alan işletim sistemine aittir: süreci yönetmek için gereken bilgiler ve kullanıcıya açılmaması gereken, mimariyle ilgili bilgiler burada tutulur. Program her zaman `0x08048000` adresinden yüklenir. Hoca, kendi bilgisayarında ve öğrencilerinkinde fiziksel ya da sanal 32 bitlik bir Linux çalışsa da bu adresin değişmediğini vurguladı.

> **Hocanın vurgusu:** Bu sabit adresler saldırgan için değerlidir. Saldırılacak sistemin 32 bitlik Linux kullandığını bilmek, programın, paylaşılan kütüphanelerin ve user stack'in başlangıç adreslerini bilmek demektir. Uzak sistem hakkında yalnız işletim sistemi bilgisiyle çok daha kapsamlı bilgi elde edilir.

> **Ders sonrası not:** Hoca 00:24:48'de paylaşılan kütüphanelerin başlangıcını da `0x08048000` olarak söyledi. Slayta göre programın başlangıcı `0x08048000`, paylaşılan kütüphanelerin başlangıcı `0x40000000`'dir (ekrandan, 00:20:00).

**Heap.** Executable'ın hemen üstüne runtime heap yerleşir. Heap, dinamik olarak kullanılan bellek bölgesidir: program başlamadan boyutu bilinmeyen, çalışma sırasında boyutu belli olan değişkenler burada tutulur. C'de heap'e erişimin temel arayüzü `malloc` (memory allocate) ve `free`'dir (ayrılmış belleği serbest bırak). Heap en fazla paylaşılan kütüphanelerin başladığı yere kadar büyüyebilir; şekildeki kalın çizgiyi geçerse **heap overflow** olur.

## 5. Stack Frame

Her fonksiyon çağrılmadan önce stack'te onun için bir veri yapısı oluşturulur; buna **stack frame** (yığında bir çerçeve) denir. Slayttaki şekilde (ekrandan, 00:30:00) sağdaki ok yüksek adresten düşük adrese doğru ilerleyen stack büyümesini, solda SP (stack pointer) frame'in alt sınırını gösterir. Yüksek adresten düşüğe frame'in bölümleri şunlardır:

- **arguments:** Fonksiyona aktarılan argümanlar. Fonksiyon tanımında parantez içine yazılanlar parametre, onlara karşılık gelen değerler argümandır.
- **return address:** Argümanların bittiği yerde dönüş adresi vardır. Frame genişliğini 32 bit kabul edersek, mimari 32 bit olduğundan dönüş adresi de 32 bittir.
- **stack frame pointer:** Bu fonksiyonu çağıran fonksiyonun stack'teki frame'inin adresidir. Böylece fonksiyon çağrıları sırasında frame'ler birbirine bağlanır. Amaç basittir: uygulama çökerse memory dump incelenerek o noktaya hangi fonksiyonlardan geçerek gelindiği görülür. Java, C# ve Python'da da görülen, "şu hata oluştu, öncesinde buradaydı, ondan önce buradaydı" diyen satırlar dolusu çıktı bu bağlantı sayesinde üretilir.
- **exception handlers:** C'de de özel durum işleme vardır; C++'ta `try` bloklarıyla daha açık yapılır. Bir özel durum oluştuğunda hangi adresten devam edileceğini gösteren bir function pointer gibi düşünülebilir.
- **local variables:** Fonksiyon içinde kullanılan yerel değişkenler. Fonksiyon çalışırken erişilebilir, fonksiyondan çıkınca erişilemez. Değerler stack'te kalır, silinmez; ama frame'in başlangıcını gösteren bir şey kalmadığı için onlara ulaşılamaz. Bu yapının güzelliği, yerel değişkenlerin diğer fonksiyonları rahatsız etmeden hızla oluşturulup fonksiyondan çıkınca "unutulabilmesi"dir.
- **callee saved registers:** Caller çağıran, callee çağrılan fonksiyondur. Çağrılan fonksiyon, dönüş kodu için kullandığı register dışındaki register'ların değerini bozmamalıdır; kendisine gelindiğinde register'lar nasılsa dönerken de öyle olmalıdır. Intel mimarisinde dönüş kodu (return code) için `AX`/`EAX` kullanılır; `BX`, `CX`, `DX`, `ES`, `DI`, `SI` gibi diğer register'lar fonksiyona girişte bu alana kaydedilir ve dönüşte geri yüklenir.

## 6. Buffer Overflow Nedir?

### 6.1 Örnek fonksiyon

Slayt: "Suppose a web server contains a function:" (ekrandan, 00:35:00)

```c
void func(char *str) {
    char buf[128];

    strcpy(buf, str);
    do-something(buf);
}
```

Fonksiyonun parametresi `char *str`'dir: 32 bitlik bir adres gelir ve bu adres arka arkaya yerleştirilmiş karakterleri gösterir. C'de dizginin bittiği sonundaki sıfır değerinden anlaşılır. Fonksiyonda yerel olarak 128 byte'lık `char buf[128]` tanımlanır, gelen `str`'nin bir kopyası `strcpy` ile `buf`'a çıkarılır ve `buf` başka bir fonksiyona (`do-something`) aktarılır.

Hoca bunun çok yaygın bir kalıp (pattern) olduğunu, muhtemelen öğrencilerin de kullandığını söyledi: gelen verinin bozulmaması için kopyası çıkarılır ve işlemler kopya üzerinde yapılır. `do-something`'in içine bakılsa büyük olasılıkla benzer bir yapı görülür. Bu yalnız bir his değildir; birçok programın yalnız kaynak kodu incelenerek yapılan analizlerde bu kalıbın pek çok farklı programcı tarafından kullanıldığı görülmüştür.

### 6.2 Stack'teki yerleşim

`func`'ın tek argümanı `str`'dir ve 32 bittir. Altında dönüş adresi vardır. Örnekte C kabul edildiği ve exception handling ile uğraşılmadığı için exception handler yoktur; dönüş adresinin altında hemen stack frame pointer, onun altında `buf` bulunur. Her satır 4 byte (32 bit) olduğundan `buf` $128 / 4 = 32$ satır kaplar.

> **Ders sonrası not:** Hoca 00:37:02'de "128 bit'lik buff" ve "her biri 4 bit'lik" dedi; doğrusu `buf` 128 byte, her satır 4 byte'tır (32 bit). 32 satır sonucu doğrudur.

Stack yukarıdan aşağı büyür: yüksek adresler yukarıda, düşük adresler aşağıdadır. Değişkenler pozitif yönde adreslendiği için `buf[0]` en düşük adreste, `buf[1]` bir sonraki adreste olur ve `buf[127]` stack frame pointer'ın hemen dibine gelir. Yani `buf`'ın başlangıcı aşağıdadır ve `buf` yukarı doğru doldurulur.

### 6.3 136 byte'lık girdi

Gelen argüman en fazla kaç byte olmalıdır? Karakter dizisinin sonuna mutlaka `\0` konması gerektiğinden, 128 byte'lık alana en fazla $128 - 1 = 127$ karakterlik bir argüman sığar.

Slayttaki soru: "What if `*str` is 136 bytes long? After `strcpy`:" (ekrandan, 00:40:00). Şekilde argüman `str` griyken, `buf[128]`, stack frame pointer ve return address kırmızıyla `*str` tarafından kaplanmış gösterilir.

- Verilen: `buf` 128 byte, girdi 136 byte.
- Fazla byte: $136 - 128 = 8$.
- İlk 4 fazla byte stack frame pointer'ı ezer. Bir önceki fonksiyonun frame'iyle bağlantı kopar. Uygulamada hata olup memory dump alınmadığı sürece bu çok kritik görünmeyebilir.
- Sonraki 4 byte dönüş adresini ezer. Hoca buna "felaket" dedi: fonksiyon döndüğünde dönüş adresinde saklı olan yere gider ve bu adres artık dışarıdan verilen girdiyle değiştirilmiştir.

> **Hocanın vurgusu:** Uç kullanıcı olarak, ister terminalden ister web sunucusundan gelen bir girdi olsun, bu girdiyi işleyen fonksiyonun dönüş adresini değiştirebiliyor olmamamız gerekir. Birkaç tasarım eksiği bir araya gelince bu değişiklik mümkün hâle gelir. Dönüş adresi değişen fonksiyon bozulmuştur; asıl dönmesi gereken yere dönmez.

Sorunun kaynağı `strcpy` kütüphane fonksiyonunda sınır kontrolü olmamasıdır. `strcpy` sıfır değerini görene kadar kopyalar; burada belirleyici olan `str`'deki sıfırdır. Böylece 136 byte hiçbir engelle karşılaşmadan yerel değişkene aktarılır, yerel değişkenin sınırları aşılır, stack frame pointer ve dönüş adresi ezilir. Hoca bunu "en temel stack üzerinden yapılan saldırı" olarak tanımladı.

## 7. Temel Stack İstismarı: Shell Kod ve NOP Slide

### 7.1 Program P

Slayt "Basic stack exploit": "Suppose `*str` is such that after `strcpy` stack looks like: ... Program P: `exec("/bin/sh")` (exact shell code by Aleph One)" (ekrandan, 00:45:00). Şekilde stack'in en altında `char buf[128]`, üstünde iki satır (frame pointer ve return address), en üstte "Program P" vardır; return address'ten çıkan ok Program P'yi gösterir.

Girdi, dönüş adresinden sonra da ezmeye devam eder. Dönüş adresi bir programı gösterir ve o programı da saldırgan dışarıdan, girdinin içinde aktarır. Yani uygulamanın çalıştıracağı program girdiyle gönderilmiş olur.

Bu konuda çalışan Aleph One adlı araştırmacı, Linux için kabuk (shell) başlatan kodu yazıp kullanımını sitesinde açmıştır. `exec("/bin/sh")` yeni bir kabuk başlatır. Kabuk başlatılırken `-c` ile çalıştırılacak komut da verilirse karşı sistemde her türlü kod çalıştırılabilir, örneğin `/bin/sh -c reboot`. Hoca süreci şöyle anlattı: bu bir satırlık kod derlenir, giriş (entry) gibi gereksiz kısımlar atılır, yalnız `exec`'e karşılık gelen komutlar alınır. Bu komutlar dönüş adresinin arkasına eklenir, dönüş adresi bunların başlangıcına ayarlanır ve girdi saldırılan sisteme gönderilir. Sistem buffer overflow'a karşı önlem almıyorsa karşı tarafın yeniden başlama olasılığı çok yüksektir.

> **Ek bilgi (derste anlatılmadı):** Aleph One'ın bu tekniği anlatan yazısı "Smashing the Stack for Fun and Profit" adıyla 1996'da Phrack dergisinde yayımlanmıştır. Yazı, stack tabanlı buffer overflow istismarının klasik kaynağı sayılır.

### 7.2 Yetki engeli

Önde tek bir engel daha vardır: saldırılan programın `reboot` komutunu çalıştıracak yetkide olması. Her kullanıcının bu yetkisi yoktur; Unix ve türevlerinde bu kullanıcı root, Windows'ta Administrator'dır. Windows'ta "System" adlı bir sistem kullanıcısı da vardır. Bu yüzden saldırganlar genelde sistem uygulamalarına saldırmayı tercih eder: sistem uygulamalarının çoğu geçmişten gelen bir alışkanlıkla sistemdeki en yetkili kullanıcının yetkisiyle çalıştırılır. Fonksiyon döndüğünde asıl dönmesi gereken yere değil shell koda gidilir ve shell kodun içine her türlü komut gömülebilir.

### 7.3 NOP slide

Kod çalıştırılırken adresler düşükten yükseğe doğru ilerler (şekildeki mavi ok). 32 bit mimaride adreslerin tek, çift ya da dörde bölünebilir olmasıyla ilgili donanımsal koşullar vardır. Hem bu koşulları aşmak hem de saldırının yalnız bir sistemde değil birden fazla sistemde ilk seferde tutması için shell kodun önüne NOP değerleri yerleştirilir.

NOP her işlemcide bulunan "no operation" komutudur ve tek byte'tır. İşlemci o anda komut çalıştırmıyorsa saati (clock) çalışmaya devam eder; işlemci saatleri durdurulup yeniden başlatılmadığından işlemcinin hiçbir şey değiştirmeden çalışacağı bir komut gerekir. NOP'ta işlemci yalnız program sayacını artırır, iç durumu değişmez. Aynı amaçla `EAX` register'ını artırmak gibi komutlar da kullanılabilir. `EAX`'i kullanmanın sakıncası yoktur, çünkü bu register'ın değeri çağrılan fonksiyonda zaten değiştirilebilir.

> **Ders sonrası not:** Hoca (00:49:14) `EAX`'in kendisiyle XOR'lanmasının da bir byte olduğunu söyledi. 32 bit x86'da `inc eax` tek byte'tır (`0x40`), `xor eax, eax` ise iki byte'tır (`31 C0`).

### 7.4 Zorluklar

Slayt "Details and examples — Some complications" (ekrandan, 00:50:00):

- Program P should not contain the '\0' character.
- Overflow should not crash program before func() exits.

Yerleştirilen programın içinde sıfır değeri olmamalıdır, çünkü `strcpy` sıfıra kadar kopyalar ve kopyalama orada kesilir. Taşma, karşı tarafta çalışan programı çökertmemelidir; program çökerse fonksiyon geri dönemez, fonksiyon dönmezse saldırı devreye giremez.

Uzaktan yapılan buffer overflow saldırılarına literatürde **stack smashing** de denir (smash: ezmek). Stack frame pointer, dönüş adresi ve sonrasındaki alan, orijinal içeriğin üzerine yeni içerik ezilerek yazılır.

## 8. Gerçek Hayattan Örnekler

**Windows animasyonlu imleç.** Animasyonlu imleçte (animated cursor) bir programın açılması beklenirken fare imleci dönen bir kum saatine dönüşür ya da bir şeyin üzerine gelince rengi değişir. Bu aslında işlemci gücü gerektiren aktif bir kod parçasıdır. Windows'taki `LoadAniIcon` kütüphane çağrısının içindeki zafiyetten yararlanan saldırganlar, güzel görünen ikonların yanında zararlı kod da içeren animasyonlu ikon paketleri yayınladı. Paketi yükleyen kullanıcı saldırıya uğradı.

**Symantec (2016).** Symantec'in virüs tarayıcısında buffer overflow vardı. Sorun, zafiyetin çalıştırılabilir dosyanın başlığını (header) ayrıştıran kodda olmasıydı ve bu kod işletim sistemi çekirdeğinin içinde çalışacak şekilde tasarlanmıştı; hoca bunu Symantec'in tasarım hatası olarak niteledi. Saldırgan başlık ayrıştırılırken bilinçli olarak taşma tetikleyip kod aktarıyordu. Çekirdekte olunduğu için kimse root ya da Administrator olup olmadığınızla ilgilenmez; saldırı başarıyla sonuçlanır. Sistemi virüslerden koruması gereken uygulamadaki zafiyet, sistemi saldırılara da açık hâle getirmiştir.

## 9. Güvensiz libc Fonksiyonları

Slayt "Many unsafe libc functions" (ekrandan, 00:55:00):

```c
strcpy (char *dest, const char *src)
strcat (char *dest, const char *src)
gets (char *s)
scanf ( const char *format, ... )        // and many more.
```

- "Safe" libc versions `strncpy()`, `strncat()` are misleading — e.g. `strncpy()` may leave string unterminated.
- Windows C run time (CRT): `strcpy_s (*dest, DestSize, *src)`: ensures proper termination

`gets`'i güncel derleyiciler neredeyse bütün sistemlerde kullandırmaz. Hocaya göre Linux'ta güncel bir GNU C derleyicisiyle `main` içinde yalnız `gets` olan bir satırlık kod derlenmeyecek, `gets` kullanılmaması yönünde uyarı verilecektir. `gets` yalnız bir karakter pointer'ı alır: sonu nerede, ne uzunlukta okunacak bilgisi yoktur. Arka tarafta ne kadar yer açılırsa açılsın yetersizdir; 1K açılırsa saldırgan 1K + 1 byte, 10K açılırsa 10K + 1 byte gönderir.

`strcpy`'nin `strncpy`, `strcat`'in `strncat` sürümleri vardır: ya sıfır görene kadar ya da verilen sayıda byte kopyalanır. Burada da sorun vardır. C kütüphanesi işletim sistemi sürümüyle birlikte güncellenir ve bir dönem dağıtılan `strncpy` ve `strncat`'te kopyalama sonrasında en sona konması gereken sıfırın konmadığı durumlar oluşmuştur; bu da başka sorunlara yol açar. Windows tarafında POSIX sözdizimine uymayan `strcpy_s` (safe sürüm) verilmiştir.

> **Hocanın vurgusu:** `strcpy`, `strcat`, `strncpy`, `strncat` ya hiç kullanılmamalı ya da çok dikkatli kullanılmalıdır.

> **Ders sonrası not:** Hoca `strcpy_s`'nin `strncpy`'nin "birebir aynısı, ismi farklı" olduğunu söyledi. Slayta göre `strcpy_s` hedef boyutunu (`DestSize`) alır ve dizginin doğru sonlandırılmasını garanti eder; `strncpy` ise dizgiyi sonlandırmadan bırakabilir (ekrandan, 00:55:00).

> **Ek bilgi (derste anlatılmadı):** `strncpy`'nin davranışı standartta böyle tanımlıdır: kaynak, verilen sayıdan uzunsa hedefe `\0` yazılmaz. Bu nedenle bu durum yalnız eski ve hatalı bir sürüme özgü değildir; `strncpy` sonrası son byte'ı elle `\0` yapmak yaygın bir alışkanlıktır.

## 10. Diğer Buffer Overflow Fırsatları

Slayt "Buffer overflow opportunities" (ekrandan, 01:00:00):

- **Exception handlers:** Overwrite the address of an exception handler in stack frame.
- **Function pointers:** (e.g. PHP 4.0.2, MS MediaPlayer Bitmaps). Şekilde `buf[128]`'in hemen ardında `FuncPtr` vardır ("Heap or stack"). Overflowing buf will override function pointer.
- **Longjmp buffers:** `longjmp(pos)` (e.g. Perl 5.003). Overflowing buf next to pos overrides value of pos.

**Exception handler.** Şimdiye kadar ele alınmayan exception handler adresi de stack frame'de ezilebilir.

**Function pointer.** Örnekler PHP 4.0.2 ve Microsoft Media Player bitmap'leridir; bitmap, verinin hangi biçimde olduğunu, hangi decoder'ın devreye gireceğini ve görüntünün ya da sesin neyle oynatılacağını belirler. Function pointer'lar yerel değişkenlerin olduğu yere, ama yerel değişkenlerden önce yerleştirilir. Kritik nokta budur: 136 byte'lık kopyalamayı düşünün. Function pointer'lar olmasaydı taşma stack frame pointer'ı ve dönüş adresini ezecekti; araya function pointer yerleştirildiği için önce onlar ezilir. Saldırının tetiklenmesi için ilgili function pointer'ı kullanan bir kod akışı gerekir. Derleyiciler `switch-case` yapısını optimize ederken genelde böyle bir jump table ya da function pointer tablosu kullanır.

**Longjmp buffer.** Perl 5.003'te karşılaşılmıştır. Hoca longjmp'ı Intel işlemcilerin segmentli belleği üzerinden açıkladı: 32 bitlik adres uzayına sığmayan bir program parçası varsa iki adres uzayı kullanmak ve aralarında geçiş yapmak gerekir; bir uzaydan diğerine gidip geri dönebilmek için adresi sabit bir atlama noktası gerekir, buna long jump buffer denir. Bu buffer'lar ezilip oraya istenen değerler yerleştirilirse, buffer kullanıldığında asıl gidilmesi gereken yere değil saldırganın adresine gidilir; temel buffer overflow saldırısındaki durumla yine karşılaşılır.

<!-- BELİRSİZ: Hocanın longjmp için yaptığı segmentli bellek açıklaması altyazıda bu şekilde geçiyor; C'deki setjmp/longjmp'ın yaygın tanımı ile örtüşmüyor (aşağıdaki ek bilgiye bakın). -->

> **Ek bilgi (derste anlatılmadı):** C'de `setjmp` o anki yürütme bağlamını (yığın göstericisi, program sayacı gibi register'lar) bir `jmp_buf` içine kaydeder; `longjmp` bu bağlama geri döner. Bu, fonksiyonlar arası yerel olmayan bir atlamadır ve büyük olasılıkla slayttaki `pos` bu kaydedilmiş bağlamı temsil eder. Kaydedilen program sayacı ezilirse `longjmp` saldırganın adresine atlar.

## 11. Heap Overflow ve C++ Vtable

Heap'te de benzer bir sorun vardır. Heap dinamik bellek için kullanılır ve bu kez C++ açısından düşünmek gerekir: nesneye yönelik dillerin çalışma zamanı ortamında en çok kullanılan bölge heap'tir, çünkü her şey dinamik olarak oluşturulup yok edilir. Bir sınıftan örnek (instance) oluşturmak stack'te değil heap'te yapılır; programcı istediği için değil, çalışma zamanı öyle kodlandığı için.

Bir sınıf temel sınıf kabul edilip genişletilebilir ve ondan gelen metotlar değiştirilebilir (override) ya da aynı adla farklı argüman tipleriyle aşırı yüklenebilir (overload). Bunların çalışma zamanında düzgün yönetilmesi için function pointer'lar kullanılır: FP1, FP2, FP3 sırasıyla metot 1, metot 2, metot 3'ü gösterir. Function pointer'ların tutulduğu tabloya **vtable** denir. Nesnenin verisinin yanında vtable'ı gösteren bir `vptr` bulunur.

Heap'te oluşturulan bir buffer vtable'ın önüne denk gelirse (gelmemesi için hiçbir sebep yoktur) buffer taştığında vtable da ezilir. Bu durumda yine başa dönülür: function pointer taşma sonucu ezilip değeri değiştirildiğinde ve o pointer kullanıldığında kod akışı değiştirilebilir. Hoca ayrıntının ileride görüleceğini, şimdilik kafada canlanması için anlatıldığını söyledi.

## 12. Tarayıcı Heap'i ve Heap Spraying

### 12.1 Saldırı senaryosu

Solda kurban, sağda kötü niyetli bir web sitesi vardır. Kurban sosyal mühendislikle ya da başka bir yolla bu siteye yönlendirilir ve oradan bir sayfa yükler. Sayfada, kurbana saldırmak için hazırlanmış ve zafiyetten yararlanan kod parçası vardır. Bu kod C/C++ değil JavaScript'tir, çünkü web sayfalarındaki dinamik yapı JavaScript ile sağlanır. Saldırganın hedefi tarayıcı üzerinden sistemi ele geçirmektir: tarayıcıya heap overflow'dan yararlanan bir JavaScript gönderir.

Slayt "A reliable exploit?" (ekrandan, 01:05:00):

```html
<SCRIPT language="text/javascript">
 shellcode = unescape("%u4343%u4343%...");    // allocate in heap
 overflow-string = unescape("%u2332%u4276%...");

 cause-overflow(overflow-string );    // overflow  buf[ ]
</SCRIPT>
```

`unescape`, veriyi HTTP üzerinden gönderirken uygulanan kodlamayla ilgilidir; değerler bozulmadan aktarılsın diye yapılır. Kod tarayıcı tarafından derlenmez, satır satır yorumlanır. `shellcode` satırına gelindiğinde JavaScript çalışma zamanında bir değişken oluşturulur ve gelen değerle ilklendirilir; ardından `overflow-string` oluşturulur. JavaScript bunları çalıştırma ortamında, yani heap'te yapar. Son olarak `cause-overflow` fonksiyonu `overflow-string` ile çağrılır ve `buf[]` taşırılır. Şekilde `buf[256]`'nın taşarak `vtable`'ı ezdiği gösterilir.

**Problem:** "attacker does not know where browser places shellcode on the heap". Tarayıcıda kaç sekme açık olduğu, ne kadar süredir açık olduğu, hangi sayfadan gelindiği, ne kadar bellek kullanıldığı gibi birçok etkene bağlı olarak shell kodun heap'teki adresi sabit değildir.

### 12.2 Heap spraying

Çözüm heap spraying'dir; mantık, stack'teki NOP slide'ın heap için düzenlenmiş hâlidir. JavaScript ile heap'in her yerine shell kod püskürtülür ve her shell kodun önüne NOP slide konur. NOP slide'lar çok uzun, shell kod çok kısadır. Heap'in tamamı bunlarla dolduğu için herhangi bir NOP slide tutturulursa NOP'lar arka arkaya işletilerek sonunda gerçek shell koda gelinir. Vtable pointer'ını püskürtülen alanda herhangi bir yeri gösterecek şekilde değiştirmek yeterlidir.

Slayt "Javascript heap spraying" (ekrandan, 01:10:00):

```javascript
var nop = unescape("%u9090%u9090")
while (nop.length < 0x100000)  nop += nop;

var shellcode = unescape("%u4343%u4343%...");

var x = new Array ()
for (i=0; i<1000; i++) {
       x[i] = nop + shellcode;
}
```

"Pointing function-ptr almost anywhere in heap will cause shellcode to execute."

Adım adım:

- `nop` dizgisi `%u9090%u9090` ile başlar; Intel mimarisinde NOP komutunun kodu `0x90`'dır.
- `while` döngüsü `nop`'u kendisiyle birleştirerek her adımda iki katına çıkarır, yani üstel olarak büyütür. 2 karakterden başlayan dizgi 19 ikilemede $2 \cdot 2^{19} = 2^{20} = 0x100000 = 1\,048\,576$ karaktere ulaşır (ara adım eklendi; python ile doğrulandı).
- `x` adlı yeni bir dizi tanımlanır; `i` 0'dan 1000'e kadar `x[i] = nop + shellcode` yapılır. Dizinin 1000 elemanının her biri heap'te açılır.

Kullanıcının gözünden: siteye gidilir, site çok küçük bir JavaScript gönderir, ama bu kod heap'i tamamen doldurduğu için bilgisayarı epey yorar. Kullanıcı "bilgisayarım niye yavaşladı" der; aslında o sırada heap spraying yapılmakta ve arkasından saldırı gerçekleşmektedir.

> **Ders sonrası not:** Hoca JavaScript'i çalıştıran ortamın "değiştirilmiş bir Java Virtual Machine" olduğunu ve `90`'ın Java bytecode'da da NOP olduğunu söyledi. Tarayıcılar JavaScript'i kendi JavaScript motorlarında çalıştırır; bunlar JVM değildir. Buradaki `0x90` değeri, shell kodun çalışacağı x86 işlemcinin NOP komutudur (JVM bytecode'unda `0x00` `nop`'tur).

> **Hocanın vurgusu:** Zor ya da imkânsız görünen saldırılar, karşıdaki tasarımın ayrıntısı öğrenildiğinde kolaylaşabilir.

### 12.3 Önlemler

Heap overflow'a karşı bazı önlemler alınmıştır:

- **JavaScript dizgilerini ayrı bir heap alanında saklamak.** JavaScript'te her şey dizgi olarak gelir: değişkenler de kod parçası da. Bunun bir kısmı değişkene, bir kısmı kodun kendisine dönüşür. İkisi ayrılırsa taşırılabilecek yer yalnız dizgilerin bulunduğu alandır; orada vtable olmadığı için onu ezip bir NOP slide'a yönlendirme şansı kalmaz.
- **Guard page'ler.** İşletim sisteminin bellek yönetimi ve işlemcinin donanım özellikleri kullanılarak belirli aralıklarla yazmaya izin vermeyen koruma sayfaları (non-writable pages, guard pages) yerleştirilir. Hoca bunun şu anda daha çok kullanılan yöntem olduğunu söyledi.

## 13. Buffer Overflow Nasıl Bulunur?

Bir web sunucusundaki buffer overflow'u bulmak için sunucu yerel makinede çalıştırılır. Ona, sonunda bir işaret (hocanın deyişiyle "catcher") bulunan, farklı uzunluklarda girdiler verilir; bunun için bir script yazılır. İşaret `&`, `#` ya da `$` olabilir; örnekte beş dolar işareti (`$$$$$`) kullanılmıştır. Hoca bunu esprili biçimde, saldırı başarılı olunca para kazanılmasına bağladı.

Bir noktada web sunucusu çöker. O zaman sürecin belleğinin dökümü (memory dump, core dump) alınır ve içinde beş dolar işareti aranır. Bulunduğu yer taşmanın gerçekleştiği yerdir; o stack frame'in ait olduğu fonksiyon da buffer overflow zafiyetinin bulunduğu fonksiyondur. Adres bilindiği için orijinal executable'da o adrese karşılık gelen fonksiyon bulunur ve girdi, daha önce tarif edildiği biçimde o fonksiyona uygun olarak hazırlanır.

## 14. Diğer Kontrol Ele Geçirme Saldırıları: Double Free

Aradan sonra hoca "More Control Hijacking Attacks" bölümüne geçti (ekrandan, 01:25:00). Temel kontrol ele geçirme saldırısı görülmüş, analizi yapılmıştı; şimdi diğer tipler ele alındı: integer overflow, double free, use after free ve format string zafiyeti.

**Double free.** Bellek `malloc` ile ayrılır, işi bitince `free` ile serbest bırakılır. Serbest bırakılmış bir adres tekrar `free` edilirse ne olacağı tamamen bellek ayırmayı yapan kodun davranışına bağlıdır. Normalde bunu tasarlayan kişi bu durumu öngörüp serbest bırakılmış bölge tekrar bırakılmak istendiğinde hiçbir şey yapmadan dönmelidir. Ancak heap'i yöneten bellek yöneticilerinde bu durum her zaman düşünülmemiştir: incelemeler, o dönemde bazı yöneticilerin böyle bir istekte belirli bir alana bilgi yazdığını göstermiştir. Hoca bunun bütün bellek yöneticileri için değil, saldırının yapıldığı dönemdeki durum için geçerli olduğunu belirtti. O dönemin popüler sürüm kontrol sistemlerinden CVS bu zafiyetten zarar gören servislerden biridir.

**Use after free** ise bir bölgeyi iki kez serbest bırakmak değil, serbest bıraktıktan sonra kullanmaktır; o da bir zafiyettir (Bölüm 17).

## 15. Integer Overflow

### 15.1 Tam sayı taşması

Her tam sayının bit sayısına bağlı olarak gösterebildiği en büyük bir değer vardır. Bu değer aşılırsa sayı başa döner:

- 8 bit: $128 + 128 = 256$, ama 8 bitle gösterilebilecek en büyük değer 255 olduğundan sonuç 0 olur.
- 16 bit (`short`): $0xff80 + 0x80 = 0x10000$, 16 bite sığmadığından `s` 0 olur.
- 32 bit: $0xffffff80 + 0x80 = 0x100000000$, 32 bite sığmadığından `m` 0 olur.

Üç sonuç da işaretsiz tiplerle küçük bir C programında ve python'da $\bmod 2^n$ hesabıyla doğrulandı.

### 15.2 Saldırı örneği

Slayt "An example" (ekrandan, 01:30:00):

```c
void  func( char *buf1, *buf2,    unsigned int len1, len2) {
      char temp[256];
      if  (len1 + len2 > 256)   {return -1}         // length check
      memcpy(temp,  buf1,  len1);                   // cat buffers
      memcpy(temp+len1,  buf2,  len2);
      do-something(temp);                           // do stuff
}
```

"What if `len1 = 0x80`, `len2 = 0xffffff80`? ⇒ `len1+len2 = 0`. Second `memcpy()` will overflow heap !!"

Fonksiyona iki buffer ve iki uzunluk gelir: `len1` `buf1`'in, `len2` `buf2`'nin uzunluğudur. Yerel `temp` 256 byte'tır. Fonksiyonu yazan kişi kendince önlem almış: uzunlukların toplamı 256'dan büyükse geri dön, çünkü bu kadar yer yok. Ancak:

- `len1 = 0x80` = 128; tek başına sorun yoktur.
- `len2 = 0xffffff80`; bir önceki slayttaki örnek.
- $len1 + len2 = 0x80 + 0xffffff80 = 2^{32} \equiv 0$ (32 bit işaretsiz toplama).
- $0 > 256$ yanlıştır; kontrol geçilir ve `memcpy`'lere gelinir.
- İlk `memcpy` 128 byte kopyalar; 256'lık alanın 128'i kullanılır, sorun yoktur.
- İkinci `memcpy`, `temp`'in 128. elemanından itibaren `len2` kadar, yani yaklaşık 4 GB kopyalamaya çalışır (ara adım eklendi) ve hocanın deyişiyle heap alanını ezip geçer.

Demek ki integer overflow da bu tür bir saldırı için kullanılabilir.

> **Ders sonrası not:** Örnekteki `temp` yerel bir değişken olduğu için büyük olasılıkla stack'tedir; slayt ve hoca taşmanın "heap"i ezeceğini söyledi. Hangi bölgede olursa olsun ikinci `memcpy` `temp`'in sınırlarını çok aşar.

Hoca integer overflow zafiyetlerinin sayısını ilk slayttaki buffer overflow grafiğiyle karşılaştırdı. Buffer overflow'da yıllık sayılar binlere çıkarken integer overflow'da en yüksek değer 120 civarındadır; aralarında yaklaşık 1'e 8 oranında fark vardır. Bu da integer overflow'un daha zor olduğunu gösterir. <!-- BELİRSİZ: Bu karşılaştırmanın yapıldığı grafik slaydının karesi yok; 120 değeri ve yıl altyazıdan doğrulanamadı. -->

## 16. Format String Zafiyeti

### 16.1 Problem

Biçim dizgileri (format string) C'de ekrana ya da dosyaya yazılacakları biçimlendirmek için bolca kullanılır. Slayt "Format string problem" (ekrandan, 01:35:00):

```c
int func(char *user)   {
   fprintf(stderr, user);
}
```

Problem: what if `*user = "%s%s%s%s%s%s%s"` ??

- Most likely program will crash: DoS.
- If not, program will print memory contents. Privacy?
- Full exploit using `user = "%n"`

Fonksiyonun karakter pointer'ı argümanı vardır ve içinde `fprintf` kullanılmıştır; `printf`, `fprintf` ya da `sprintf` olması fark etmez. Burada çıktı standart hataya (`stderr`) yazılır. Programcı, gelen dizgiyi aynen `fprintf`'e vererek kullanıcıya biçimlendirme rahatlığı sağladığını düşünmüş, ama büyük bir hata yapmıştır.

Kullanıcı yedi tane `%s` gönderirse her `%s` bir dizgi basılacağı anlamına gelir ve dizginin adresi için 32 bitlik bir pointer gerekir. Virgülden sonra argüman verilmediği için bu pointer stack'te bulunulan yerden itibaren alınır ve o adresten sıfır görülene kadar basılır. Bu yedi kez tekrarlanır: yedi tane 32 bitlik adres alınır ve içerikleri basılır. Bellekte erişilmemesi gereken her yere erişilir; büyük olasılıkla bir yerde geçersiz bir bellek erişimi olur ve program çöker (DoS).

> **Hocanın vurgusu:** Başarısız olan her buffer overflow saldırısı programın çökmesine yol açar ve kontrol ele geçirme saldırısı hizmet engellemeye (denial of service) dönüşür. Önlem alındığı için ya da saldırı yanlış hazırlandığı için olsun, buffer overflow saldırısıyla karşılaşıldığında çalışan uygulamanın sonlanma olasılığı çok yüksektir; bu da servis kesintisi demektir. Önlemler sonraki derste görülecek.

Erişilen adresler programı çökertmezse bu kez erişilmemesi gereken bellek alanlarının içeriği görülür; bu da mahremiyeti ortadan kaldırır. Çok kullanılmayan ama biçim dizgisi olarak anlamı olan bir de `%n` vardır. `%n` dışındaki bütün biçim belirteçleri okumaya yöneliktir, `%n` ise yazmaya yöneliktir; bu yüzden daha tehlikelidir.

### 16.2 Doğru kullanım

Hocaya göre satırın olması gereken hâli şudur (`stderr` ya da `stdout` fark etmez):

```c
fprintf(stderr, "%s", user);
```

Böylece kullanıcı ne verirse versin tamamı tek bir dizgi olarak algılanır ve basılır; yukarıdaki sorunların hiçbiri yaşanmaz. `printf`, `fprintf`, `sprintf`, `vprintf`, `vfprintf`, `vsprintf` fonksiyonlarının hepsi bu zafiyeti taşır. Bunların üzerine kurulu `syslog`, `err`, `warn` gibi sistem servisleri de aynı riski taşır: örneğin `syslog`, bir dosyaya "şöyle oldu, parametre buydu, saat şuydu, sonuç buydu" diye log yazarken `printf`'ten yararlanır. Yanlış kullanılırsa zafiyet `printf` zafiyeti olarak kalmaz, `syslog`, `err` ya da `warn` zafiyetine dönüşür.

### 16.3 Bellek okuma ve `%n` ile yazma

Herhangi bir bellek bölgesinin içeriğini elde etmek için `printf` ile `%08x` biçimleri (içeriği sıfırlarla doldurulmuş 8 haneli onaltılık olarak bas) ve sonunda `%s` kullanılır. Virgülden sonra argüman verilmediği için her `%08x` stack'ten bir değer çeker. Dört `%08x`'ten sonra `%s`, stack'teki bir sonraki 4 byte'lık değeri pointer olarak alır ve oradan sıfır görülene kadar içeriği basar. <!-- BELİRSİZ: Bu slaytta gösterilen tam printf satırının karesi yok; satırın tam biçimi (ayraçlar dahil) doğrulanamadı. -->

> **Ders sonrası not:** Hoca her `%08x`'in stack'i "sekiz ilerlettiğini" ve dördünün "otuz iki byte ilerlettiğini" söyledi. 32 bit sistemde her `%08x` stack'ten 4 byte'lık bir değer okur ve ekrana 8 karakter basar; dördü stack'te 16 byte ilerler ve 32 karakter basar. Hocanın andığı 32 sayısı basılan karakter sayısına karşılık gelir.

`%n`, o ana kadar kaç karakter basıldığını verilen değişkene yazar. Örnek `printf("hello %n", &temp)`: "hello" 5 karakter, ardından bir boşluk, toplam 6 karakter; bu yüzden işlem bitince `temp` değişkenine 6 yazılır. Bu özellik, çıktının sağının solunun düzgün hizalanması amacıyla düşünülmüştür. Yukarıdaki örnekte 32 karakter basıldıktan sonra bir `%n` gelirse stack'te o anda gelinen yere 32 değeri yazılır.

Hoca `%n` ile saldırı yapmanın çok zor olduğunu söyledi, çünkü her seferinde sınırlı bir değer yazılabilir. Bu özellikten yararlanan saldırılar vardır ama binlerce değil, çok azdır. Yine de gösterdiği şey açıktır: fırsat verilirse her fırsat aktif bir saldırıya dönüşebilir.

> **Ek bilgi (derste anlatılmadı):** Güncel sistemlerde `%n` kısıtlanmıştır: Microsoft CRT'de varsayılan olarak kapalıdır, glibc'de `_FORTIFY_SOURCE` ile derlenen programlarda yazılabilir bellekteki biçim dizgilerinde `%n` programı sonlandırır. Ayrıca derleyiciler `-Wformat-security` uyarısıyla `fprintf(stderr, user)` gibi sabit olmayan biçim dizgilerini işaretler.

## 17. Use After Free

### 17.1 Kavram ve Chrome istatistiği

Bellek `malloc` ile ayrılır, `free` ile serbest bırakılır, ardından sanki serbest bırakılmamış gibi kullanılmaya devam edilir. Bu use after free'dir.

Slayt "High impact security vulns. in Chrome 2015 – 2020 (C++)" (ekrandan, 01:40:00; kaynak: Google). Chrome C++ ile yazılmıştır. "High+, impacting stable" başlıklı pasta grafiğe göre:

| Kategori | Oran |
|---|---|
| Use-after-free | %36.1 |
| Other memory unsafety | %32.9 |
| Other | %23.9 |
| Security-related assert | %7.1 |

"70% due to memory management bugs." Use after free ile diğer bellek güvenliği hatalarının toplamı $36.1 + 32.9 = 69.0$, yani yaklaşık %70'tir. Hoca, hedef odaklı olarak tarayıcı zafiyetlerini ortadan kaldırmak için geliştirilmiş bir tarayıcıda bile bu kadar açık bulunduğuna ve bunların %70'inin bellek yönetimiyle ilgili olduğuna dikkat çekti.

### 17.2 Internet Explorer 11 örneği

Internet Explorer 11 de C++ ile yazılmıştır ve bu örnek belgelenmiş bir saldırıdır; slaytta izlemeyi kolaylaştırmak için sadeleştirilmiştir. Sayfada `form` adlı bir form ve iki giriş alanı vardır: biri `textarea`, biri `input`. Kimliği `c1` olana A1, diğerine A2 denmiş; birine başlangıç değeri olarak `val` verilmiştir. Formdaki her nesnenin `DoSomething`, `DoReset`, `DoSomethingElse` gibi metotları için function pointer'ları vardır.

Slayt "The exploit" (ekrandan, 01:45:00):

```html
<script>
   function changer() {
      document.getElementById("form").innerHTML = "";
      CollectGarbage();

      --- allocate string object to occupy vtable location ---
   }

   document.getElementById("c1").onpropertychange = changer;
   document.getElementById("form").reset();
</script>
```

Akış:

- `changer()` önce formun `innerHTML`'ini boşaltır; `c1` ve `c2` alanları temizlenir, hiçbir şey kalmaz. Ardından çöp toplama çağrılır.
- `c1`'in `onpropertychange` olayına `changer` bağlanır: `c1` değişirse `changer` çağrılır.
- Form sıfırlanır (`reset()`). Formu sıfırlamak, formun bütün elemanları üzerinde dolaşıp her birinin reset'ini çağırmak demektir; bunu programcı değil, JavaScript'in kendisi yapısı gereği yapar.
- `c1`'in `DoReset`'i `c1`'i değiştirir, bu da `changer`'ın çağrılmasına ve `c2` nesnesinin serbest bırakılmasına yol açar.
- Döngü sırası `c2`'ye gelir; ama `c2` artık yoktur. Silinmiş bir nesnenin reset'i çağrılır ve burada bir kontrol yoktur: use after free.
- Saldırgan, `changer` içinde vtable ile aynı boyutta bir string ayırıp boşalan vtable konumuna yerleştirir ve içini shell kodu gösterecek biçimde doldurur. "When c2.DoReset() is called, attacker gets shell."

Saldırının zorluğu sorusuna hoca kodun kendisiyle cevap verdi: gereken tek şey, `innerHTML`'i boşaltıp çöp toplamayı çağırdıktan sonra vtable konumunu işgal edecek bir string nesnesi ayırmaktır; geri kalanı birkaç satırdır.

> **Hocanın vurgusu:** "Use after free can be a serious security vulnerability." Use after free deyip geçmemek lazım; bu göz ardı edilirse beklenmedik bir yerden çok ciddi saldırılarla karşılaşılabilir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:38:43): `char buf[128]` tanımlı fonksiyona gelen `str` argümanı `strcpy` ile güvenle kopyalanabilmek için en fazla kaç karakter olmalıdır?

> **Çözüm (derste verildi):** Dizginin sonuna `\0` konması gerektiğinden $128 - 1 = 127$ karakter.

**Soru 2** (ekrandan, 00:40:00): `void func(char *str) { char buf[128]; strcpy(buf, str); do-something(buf); }` fonksiyonunda `*str` 136 byte uzunluğundaysa `strcpy` sonrasında stack'te ne olur?

> **Çözüm (derste verildi):** $136 - 128 = 8$ byte taşar. İlk 4 byte stack frame pointer'ı, sonraki 4 byte dönüş adresini ezer. Fonksiyon döndüğünde girdinin belirlediği adrese gidilir; girdi ayrıca dönüş adresinin üstüne shell kod yerleştirip dönüş adresini onun başına ayarlarsa saldırganın kodu çalışır.

**Soru 3** (ekrandan, 01:30:00): Aşağıdaki fonksiyonda `len1 = 0x80`, `len2 = 0xffffff80` verilirse ne olur?

```c
void  func( char *buf1, *buf2,    unsigned int len1, len2) {
      char temp[256];
      if  (len1 + len2 > 256)   {return -1}
      memcpy(temp,  buf1,  len1);
      memcpy(temp+len1,  buf2,  len2);
      do-something(temp);
}
```

> **Çözüm (derste verildi):** 32 bit işaretsiz toplamda $0x80 + 0xffffff80 = 0$ olur. $0 > 256$ yanlış olduğundan uzunluk kontrolü geçilir. İlk `memcpy` 128 byte kopyalar; ikinci `memcpy` `temp+128`'den itibaren `0xffffff80` byte kopyalamaya çalışır ve belleği ezer. Toplamın 0 çıktığı ve kontrolün geçildiği gcc ile derlenen küçük bir programla doğrulandı.

**Soru 4** (ekrandan, 01:35:00): `int func(char *user) { fprintf(stderr, user); }` fonksiyonuna `*user = "%s%s%s%s%s%s%s"` verilirse ne olur? Doğru yazım nedir?

> **Çözüm (derste verildi):** Her `%s` stack'ten 4 byte'lık bir değeri adres olarak alır ve oradan `\0`'a kadar basar. Büyük olasılıkla geçersiz bir adrese erişilir ve program çöker (DoS); çökmezse bellek içeriği sızar. `%n` ile belleğe yazılarak tam istismar mümkündür. Doğrusu `fprintf(stderr, "%s", user);`.

**Soru 5** (derste sözlü, 01:38:05): `printf("hello %n", &temp);` çalıştıktan sonra `temp` değişkeninin değeri nedir?

> **Çözüm (derste verildi):** "hello" 5 karakter ve bir boşluk, toplam 6 karakter basılmıştır; `temp = 6`. Küçük bir C programı gcc ile derlenip çalıştırılarak doğrulandı.

**Soru 6** (derste sözlü, 01:25:31): `free` ile serbest bırakılmış bir adres tekrar `free` ile serbest bırakılmak istenirse ne olur?

> **Çözüm (derste verildi):** Sonuç tamamen bellek yöneticisinin davranışına bağlıdır. Doğru tasarlanmış bir yönetici hiçbir şey yapmadan dönmelidir; ancak saldırıların yapıldığı dönemde bazı heap yöneticileri bu durumda belirli bir alana bilgi yazıyordu ve bu, CVS gibi servislerde kontrolü ele geçirmek için kullanıldı.

## Dersin Toparlaması

Bu derste bir saldırganın, hedef sistemde çalışan bir uygulamanın kontrol akışını ele geçirerek keyfi kod çalıştırmasının temel yolları incelendi. Önce gereken altyapı kuruldu: 32 bit Linux'ta sabit adreslere sahip süreç bellek düzeni, aşağı doğru büyüyen stack, yukarı doğru büyüyen heap ve argüman, dönüş adresi, frame pointer, exception handler, yerel değişkenler ile kaydedilmiş register'lardan oluşan stack frame. Bu yapı üzerinde `strcpy` gibi sınır kontrolü yapmayan fonksiyonların yerel bir buffer'ı taşırarak dönüş adresini nasıl ezdiği ve shell kodu çalıştırdığı gösterildi. Aynı fikir function pointer, longjmp buffer, exception handler ve C++ vtable gibi hedeflere, tarayıcılarda ise NOP slide ile heap spraying'e genişletildi.

İkinci bölümde zorluğu artan diğer saldırılar ele alındı: double free, uzunluk kontrolünü atlatan integer overflow, kullanıcı girdisinin biçim dizgisi olarak verilmesinden doğan format string zafiyeti ve Chrome'un yüksek etkili zafiyetlerinde ilk sırada yer alan use after free. Ortak ders, zor görünen saldırıların tasarımın ayrıntısı bilindiğinde kolaylaştığı ve başarısız bir taşmanın bile hizmet engellemeye yol açtığıdır. Hoca bir sonraki derste bu saldırılara karşı savunma mekanizmalarına geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
