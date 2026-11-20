# Ders 3 Genişletilmiş Notu: Kontrol Ele Geçirme Saldırılarına Karşı Savunmalar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersin Tekrarı: Kontrol Ele Geçirme Saldırıları
- 2. Temel Hata: Veri ile Kontrolü Karıştırmak
- 3. Ele Geçirme Saldırılarını Önlemenin Üç Yolu
- 4. Platform Savunması: Belleği Çalıştırılamaz İşaretlemek (DEP)
- 5. Return Oriented Programming (ROP)
- 6. Adres Uzayı Rastgeleleştirme (ASLR)
- 7. kBouncer
- 8. Çalışma Zamanı Denetimi: StackGuard ve Kanarya
- 9. ProPolice ve Microsoft /GS
- 10. SEH Saldırısı, SafeSEH ve SEHOP
- 11. Kanarya Çıkarma (Canary Extraction)
- 12. LibSafe
- 13. Gölge Yığın (Shadow Stack)
- 14. Kontrol Akışı Bütünlüğü: CFI, CFG ve CET

## 1. Önceki Dersin Tekrarı: Kontrol Ele Geçirme Saldırıları

Ders, "Control Hijacking: Defenses" başlıklı slayt bölümüyle açıldı (ekrandan, 00:05:00). Hoca önce geçen hafta incelenen kontrol ele geçirme (control hijacking) saldırısını ve varyasyonlarını hatırlattı. Geçen haftanın sonunda sorulan soru, bu dersin konusuydu: bu saldırılara karşı nasıl bir savunma uygulanabilir?

Hatırlatılan saldırılar şunlardı:

- **Stack smashing:** "Smash" ezmek demektir; yığın (stack) ezilir. Özellikle ezilen yer bir geri dönüş adresi ya da bir fonksiyon işaretçisidir (function pointer). Amaç, o adrese başvurulduğunda program akışının saldırganın istediği kod parçasına gitmesidir.
- **Heap spraying:** Heap alanı çok büyük miktarda saldırı koduyla doldurulur. Saldırı kodunun önüne çok uzun bir NOP bölgesi (NOP slide) konur. Böylece "gözü kapalı" denebilecek bir atlamada bile saldırı kodunun çalışma olasılığı yüksek olur.
- **Use-after-free:** Dinamik olarak ayrılıp serbest bırakılmış bir alanın yeniden kullanılması. Internet Explorer 11'deki bir hata incelenmişti: saldırgan, serbest bırakılmış bir kontrol yapısına yazma şansı bulur. Tarayıcı alanın serbest bırakıldığını fark etmeden yapıyı yeniden kullandığında aslında bir fonksiyon işaretçisinin kullanılmasını tetiklemiş olur.
- **Integer overflow** ve **format string** zafiyetleri.

Hoca, tedbir alabilmek için önce saldırının nasıl yapıldığını ayrıntısıyla gördüklerini, ama bir şeyin daha farkına varmak gerektiğini söyledi: bu saldırı neden gerçekleştirilebiliyor?

## 2. Temel Hata: Veri ile Kontrolü Karıştırmak

### 2.1 Captain Crunch Düdüğü

Slaytın başlığı "The mistake: mixing data and control" idi; altında "An ancient design flaw: enables anyone to inject control signals" yazıyor ve sarı bir Cap'n Crunch düdüğünün resmi görülüyordu (ekrandan, 00:10:00).

Hoca hikâyeyi şöyle anlattı: ABD'de uzun yıllar boyunca, eyaletler arası dahil telefon hizmetini veren tek şirket AT&T idi. Şehir ya da eyalet içinde konuşma için para ödenmezken şehirlerarası ya da eyaletlerarası görüşmede ödeme yapılıyordu. Düdüğü tasarlayan kişi şunu fark etti: yerel olmayan bir numara arandığında, ödemenin yapılıp yapılmadığı karşı santrale kulağın duymayacağı bir frekansta bir sinyalle bildiriliyordu. Yerel santral jeton ya da para atıldığını algılayınca bu sinyali gönderiyor, karşı santral de "ödeme yapıldı, görüşmenin devam etmesine izin verebilirsin" diye anlıyordu.

Kişi bu frekansı çözdü ve düdüğü tam o frekansta ses üretecek şekilde tasarladı. Sonuç: numara çevrilir, karşı tarafla ilk bağlantı kurulur, karşı taraf para atılmasını bekler. Para atmak yerine ahizeye düdükle üflenir. Çıkan sesi insan duymaz ama karşı santral duyar, para atıldığını düşünür ve bağlantıya izin verir.

> **Ek bilgi (derste anlatılmadı):** Bu düdüğün ürettiği ses, büyük olasılıkla AT&T'nin hat boşta sinyali olarak kullandığı 2600 Hz tonuydu. "Captain Crunch" lakabı, düdüğün bir mısır gevreği kutusundan çıkan oyuncak olmasından gelir. Bu tür santral kandırma işlemlerine "phreaking" denir.

### 2.2 In-band ve Out-of-band Kontrol

Hata, veri ile kontrolün birbirine karıştırılmasıdır. Kontrol bilgisi iki türlü gönderilebilir:

- **In-band:** Veriyi aktarmak için kullanılan hat, o veriyle ilgili kontrol bilgisini aktarmak için de kullanılır. Ayrı bir hat kurmak gerekmediği için işe gelir.
- **Out-of-band:** Kontrol bilgisi ayrı bir kanaldan aktarılır.

Hem santral örneğinde hem buffer overflow'da veri ile o verinin kullanımına yönelik kontrol bilgisi bir arada aktarılır ya da kullanılır; aralarında izolasyon yoktur. Bu yüzden saldırılara açık olunur.

> **Hocanın vurgusu:** En temel tasarım ilkesi şudur: bir veriyi anlamlı kılan, nasıl kullanılacağını ya da durumun nasıl değiştiğini belirten kontrol amaçlı sinyalleşme mutlaka kullanıcı verisinden bağımsız, ayrı bir kanaldan yapılmalıdır. İkisi birbirine karışmamalıdır.

### 2.3 Aynı Hata Yığında

Yığında geri dönüş adresinin hemen bir yanında yerel değişkenler, diğer yanında fonksiyona aktarılan argümanlar bulunur. Geri dönüş adresi kontrol bilgisidir, çünkü dönüşte program akışının nereden devam edeceğini söyler. Argümanlar ve yerel değişkenler ise kontrol bilgisi değildir; fonksiyonun düzgün çalışması için gereken veridir. Yerel değişkenler tamamen kullanıcının denetimindedir. Yerel değişkenlerin başlangıcından itibaren yazmaya devam edip SFP'yi (stack frame pointer) ve geri dönüş adresini ezerek geçen bir taşma, akışı saldırganın istediği koda çevirir.

Hoca bir düşünce deneyi önerdi: geri dönüş adreslerinin tutulduğu yığın alanı ile yerel değişkenlerin tutulduğu alan farklı adres bölgelerinde olsaydı, yani biri kullanıcının yerel değişken ve argümanlarını adreslemesi için, diğeri dönüşleri ve çerçeve bağlantılarını yönetmek için iki ayrı yığın işaretçisi bulunsaydı, bugün buffer overflow diye bir saldırı türünden söz etmiyor olurduk. Demek ki tasarımda alınan kararlar çok önemlidir.

Bu neden bugün değiştirilemiyor? Tamamen uyumluluk nedeniyle. Bu yapı o kadar temel ve o kadar uzun süredir kullanılıyor ki işlemci mimarisi bile buna göre biçimlenmiştir; donanım düzeyinde bağımlılıklar vardır. Kâğıt üzerinde harika çalışan bir yapı kurulabilir, ama bugüne kadar üretilmiş milyarlarca cihaz ve yazılım bir gecede değiştirilemez. Bu yüzden üretilecek çözümlerin mevcut donanım ve yazılım yapılarıyla uyumlu olması gerekir.

Hoca santral hatasının 1971'de fark edildiğini, ilk buffer overflow saldırısının ise "81-82" yıllarında olduğunu söyledi. Aradan on yıl geçmiş, saldırı çok farklı bir biçimde ortaya çıkmış, ama temel ilke aynı kalmıştır. Santralde gönderilen kontrol sinyali, karşı tarafın akışını değiştirip para atılmamışken atıldı kararı aldırır; bu, bir argümanın değerinin değiştirilmesine benzetilebilir.

> **Ders sonrası not:** Hoca ilk buffer overflow saldırısı için "81-82" dedi. Buffer overflow'u kullanan ve en çok bilinen ilk yaygın saldırı büyük olasılıkla 1988'deki Morris solucanıdır (fingerd'deki taşma). Tarih altyazıdan doğrulanamadı.

### 2.4 XSS ve Use-after-free Bağlantısı

Slaytta "Later we will see that mixing data and code is also the reason for XSS, a common web vulnerability" yazıyordu. Hoca, cross-site scripting'in de veri ile kodun aynı yerde yaşaması üzerine kurulu olduğunu söyledi. Internet Explorer 11 use-after-free örneğinde de durum benzerdi: nesne yönelimli yapıda her şey heap'te oluşturulur. Kontrol için kullanılan vtable serbest bırakıldıktan sonra saldırgan oraya script ile bir değişken yerleştirir. Sistem bundan habersiz olarak orayı hâlâ vtable sanır, oysa içinde saldırganın istediği koda giden yeni bir işaretçi vardır. Biri kontrol, biri veri alanıdır ama iç içe yaşarlar.

## 3. Ele Geçirme Saldırılarını Önlemenin Üç Yolu

Slayttaki "Preventing hijacking attacks" listesi şöyleydi (ekrandan, 00:20:00 ve 00:25:00):

```text
1. Fix bugs:
   - Audit software
       Automated tools: Coverity, Infer, ...
   - Rewrite software in a type safe language (Java, Go, Rust)
       Difficult for existing (legacy) code ...
2. Platform defenses: prevent attack code execution
3. Add runtime code to detect overflows exploits
   - Halt process when overflow exploit detected
   - StackGuard, CFI, LibSafe, ...
```

### 3.1 Hataları Düzeltmek

Birinci yolun iki boyutu vardır. İlki mevcut yazılımlardaki hataları gidermektir. Bunun için yazılımlar bu tür zafiyetler açısından özel bir gözle denetlenmelidir (audit). Yazılımların boyutu düşünüldüğünde bu el ile yapılamaz, otomatikleştirilmelidir. Hem açık kaynak hem ticari araçlar vardır; Coverity ve Infer bunlardan ikisidir. Ama bunun bir bedeli vardır: hataları bulduktan sonra düzeltmenin ve düzeltilmiş hâli yaymanın bir maliyeti vardır.

İkincisi yeni yazılımları tip güvenliği sağlayan bir dilde yazmaktır. Hoca tip güvenliğini Java ile C'yi karşılaştırarak anlattı. Java'da bir değişken `boolean` tanımlanırsa ona yalnız `true` ya da `false` (veya bir karşılaştırmanın sonucu) atanabilir. C'de ise 0 değeri yanlışa, 0 dışındaki her değer (tam sayı ya da kayan noktalı, pozitif ya da negatif) doğruya karşılık gelir; yani ayrı bir Boolean tipi yoktur, genellikle `char` ya da `int` bir değişkenin sıfır olup olmadığına bakılır. C++'ta `bool` tipi tanımlanmıştır ama arka plandaki yaklaşım C'ye benzediği için Java'daki gibi bir kısıtlama yoktur. Böyle bir dil ve ona uygun bir çalışma ortamı, bu zafiyetleri en aza indirir, hatta ortadan kaldırır.

Slayttaki uyarı ise şudur: mevcut (legacy) kod için bu zordur. C ile yazılmış bir kodu Java'da, C++ ile yazılmış bir kodu Go'da yeniden mi yazacağız? Ayrıca Java'nın kendisi tip güvenlidir ama doğrudan (native) çalışmaz, JVM üzerinde çalışır. Java ile ilgili güvenlik açıklarının büyük çoğunluğu JVM tarafındadır, çünkü JVM C/C++ ve onların üzerine kurulu sistem kütüphanelerinden yararlanır. Go ve Rust için de aynı durum geçerlidir: dil güvenli olsa bile altta çalıştığı C/C++ kütüphaneleri ve çalışma ortamı aynıdır.

### 3.2 Platform Savunmaları ve Çalışma Zamanı Kodu

İkinci yol platform savunmalarıdır. Platform, kodun çalıştırılacağı, yani saldırının yapılacağı yerdir: bir sunucu ya da bir uç kullanıcı bilgisayarı olabilir. Burada amaç, saldırı sırasında karşı tarafa aktarılan kod parçasının çalışmasını engellemektir.

Üçüncü yol, akışı değiştirilecek olan kodun kendisine öyle mekanizmalar yerleştirmektir ki kod parçasının akışının değiştirilmesi engellensin ya da fark edilsin. Fark edildiğinde yapılacak şey uygulamayı durdurmaktır.

Hoca burada geçen hafta söylediğini hatırlattı: düzgün gerçekleştirilemeyen bir buffer overflow saldırısı büyük olasılıkla hizmet engelleme (denial of service, DoS) saldırısına dönüşür. Savunmaların sonucu da aynıdır: sistemin tamamen ele geçirilmesi (complete breach), sistemin hizmet verememesine dönüştürülür.

> **Hocanın vurgusu:** Hem saldırı kodunu çalıştırmayıp hem de gelenlere hizmet etmeye devam eden güzel bir seçenek ne yazık ki yoktur. Tam ele geçirmeyi DoS'a dönüştürmeyi kabul edip bununla yaşıyoruz.

Birinci seçenek en masraflı ve her anlamda en zor olanıdır. Bu yüzden derste platform savunmalarına (işlemci, işletim sistemi, çalışma ortamı) ve saldırı altındaki kod parçasında yapılabileceklere odaklanıldı.

## 4. Platform Savunması: Belleği Çalıştırılamaz İşaretlemek (DEP)

### 4.1 Yığın Kod Çalıştırmak İçin Tasarlanmadı

Temel buffer overflow saldırısında kod yığına aktarılır. Hoca, Intel dokümantasyonuna bakıldığında yığının kod çalıştırmak için tasarlanmış bir alan olmadığını vurguladı. Orijinal Intel tasarımında kod segmenti, veri segmenti, yığın segmenti ve ek (extra) segment ayrıdır. Çalıştırılacak komutlar kod segmentinde, bu komutların kullandığı veri veri segmentindedir. Fonksiyon çağrısında program sayacının değişmesi, dönüş adresinin saklanması, parametrelerin aktarılması ve yerel değişkenlerin tutulması içinse yığın segmenti kullanılır. Yani yığın kod çalıştırmak için değildir, ama buffer overflow'da sisteme aktarılan kod yığında çalıştırılır.

### 4.2 NX, XD ve XN Bitleri

Slayt şöyleydi (ekrandan, 00:30:00 ve 00:35:00):

```text
Marking memory as non-execute (DEP)
Prevent attack code execution by marking stack and heap as non-executable
 - NX-bit on AMD64, XD-bit on Intel x86 (2005), XN-bit on ARM
     disable execution: an attribute bit in every Page Table Entry (PTE)
 - Deployment:
     Linux, OpenBSD
     Windows DEP: since XP SP2 (2004)
       Visual Studio: /NXCompat[:NO]
```

En çok saldırı Intel mimarisine yapıldığı için hoca bu mimariden gitti. Bu mimarinin bugün iki uygulaması vardır: Intel'in kendisi ve AMD. Komutlar ve davranışları aynı olduğu için birinde yazılan kod ötekinde çalışır. Her iki üretici de yığında komut çalıştırılmasını donanım düzeyinde devre dışı bırakacak bir tedbir aldı. AMD buna NX (non-executable) biti, Intel XD (execute disable) biti dedi; çok yakın zamanda ARM'de de XN biti geldi. Hoca, bunların aynı şey olduğunu, farklı adların ticari marka (trademark) nedeniyle yapılan harf oyunları olduğunu belirtti.

Mantık basittir: bu üç işlemci de sanal bellek kullanır. Bellek, bir seferde ayrılıp üzerinde işlem yapılabilen mantıksal birimlere, yani sayfalara (page) bölünür. Bir sayfada kod da veri de tutulabilir, yığın olarak da kullanılabilir. Sayfanın özellikleri belirlenirken "bu sayfa kod çalıştırabilir ya da çalıştıramaz" diye bir tanımlayıcı eklenir.

> **Ders sonrası not:** Hoca konuşurken bu özellik için "2015" dedi; slaytta Intel XD biti için yıl 2005 olarak yazıyor.

Hoca bunun tek başına yeterli olmadığını, ama önemli olduğunu söyledi. Linux'ta karşılığı hemen bir çekirdek değişikliğiyle yapıldı, OpenBSD de benzer şekilde yaptı. Windows'ta ilk kez 2004'te XP Service Pack 2 ile bir tedbir alındı ve Microsoft buna, yine ticari marka nedeniyle, DEP (Data Execution Prevention) adını verdi.

### 4.3 Derleyici ve Çalışma Ortamı Sorunları

İşletim sisteminin desteklemesi yetmez. Geliştirme ortamları incelendiğinde, Visual Studio derleyicileri de dahil olmak üzere pek çok derleyicinin yığında kod çalıştırmaya yönelik kod ürettiği görüldü. Bu yüzden Visual Studio'ya NX uyumluluğu için bir bayrak eklendi (`/NXCompat`); bu açıksa derleyici yığında çalışacak kod üretmez.

En çok etkilenen çalışma ortamlarından biri Java'dır. Java'da just-in-time (JIT) derleme vardır: bir sınıf kaynak olarak gelir, bytecode'a dönüştürülür ve oradan çalıştırılır. Bu süreç çalıştırılabilir bellek alanına ihtiyaç duyar. Diğer örnek Lisp'tir (List Processor). Listeler üzerinde etkin çalışmaya uygun bu dil, bir dönem Prolog ile birlikte uzman sistemlerde çok kullanılmıştır. Mimar, inşaat ve makine mühendislerinin yoğun kullandığı AutoCAD'in çekirdeğinde de Lisp büyük rol oynar; çizimler vektörlerle, yani listeler gibi tutulur. Lisp, dinamik yapısı içinde listeleri değiştirebilmek için yığının çalıştırılabilir olduğunu varsayar. Demek ki çalıştırmaya devam etmek zorunda olduğumuz, başka uygulamaların da temeli olan eski (legacy) uygulamalar ek kısıtlar getirebilir.

### 4.4 Windows'ta DEP Ayarları

Ekranda Windows'taki DEP ayar penceresi gösterildi. İki seçenek vardı: DEP'i yalnız temel Windows programları ve hizmetleri için açmak ya da seçilenler dışındaki bütün programlar ve hizmetler için açmak. Yanında bir Windows XP ekranı vardı: DEP, Windows Explorer'ın çalışmasını durduruyordu. Hoca bunun Internet Explorer değil, Windows'un grafik arayüzü olan Windows Explorer olduğunu özellikle belirtti. Buradan şu anlaşılır: Microsoft işletim sistemine DEP özelliğini koymuş, ama işletim sisteminin en temel programlarından biri henüz bununla uyumlu hâle getirilmemiştir. Hoca bunu Microsoft'u kötülemek için değil, ticari kaygılar altında farklı bileşenlerin zamanlamasını tutturmanın zorluğunu göstermek için verdi.

Daha büyük sorun ise şudur: saldırganlar, donanım, işletim sistemi ve çalışma ortamı düzeyinde bu tedbirlerin alındığını görünce saldırı biçimlerini değiştirdiler. Sonuçta Return Oriented Programming (ROP) ortaya çıktı.

## 5. Return Oriented Programming (ROP)

### 5.1 Kod Enjekte Etmeden Kontrol Ele Geçirme

Slaytın başlığı "Attack: Return Oriented Programming (ROP)", alt başlığı "Control hijacking without injecting code" idi (ekrandan, 00:40:00). Solda yığın (yukarıdan aşağıya: args, ret-addr, sfp, boş alan, local buf), sağda libc.so (içinde `exec()`, `printf()` ve `"/bin/sh"`) çiziliydi. Bir ok `ret-addr`'den `exec()`'e, bir ok da `args`'tan `"/bin/sh"`'ye gidiyordu.

Hoca ilk derste söylediğini hatırlattı: sistem çağrıları bilinmeli ve bunların içinde özellikle iyi bilinmesi gereken biri `exec`'tir. Bir programı sürece dönüştürüp çalıştırmak için işletim sisteminden `exec` sistem çağrısıyla talep edilir.

Yığının durumu şöyledir: argümanlar, dönüş adresi ve SFP itilmiştir; arada istisna işleme için bir alan (şimdilik göz ardı edilen) ve yerel değişkenler vardır. Yerel değişkendeki zafiyet nedeniyle (`strcpy`, `memcpy` gibi kontrolsüz bir kopyalama) yerel tampon, SFP, dönüş adresi ve argümanlar ezilir. Saldırganın amacı yeni bir kabuk (shell) açmaktır. `exec`'e çalıştırılacak komut `"/bin/sh"` dizgesi olarak verilir: kök dizine göre `bin` klasörünün altındaki `sh` çalıştırılabilir dosyasını bul ve çalıştır.

`exec` libc içindedir. Bir dizge verildiği için argüman alanına dizgenin işaretçisi konmalıdır. Hoca, slaytta anlaşılsın diye `/bin/sh`'nin sağda çizildiğini, kendi anlatımında ise dizgenin argüman alanının hemen ardına yazıldığını ve argüman alanında (32 bit mimaride 4 baytlık) adresinin bulunduğunu söyledi. Dönüş adresine ise `exec`'in adresi yazılır.

### 5.2 Neden Çalışır?

Intel mimarisinde bir fonksiyon `call` komutuyla çağrılmadan önce argümanları (ya da adreslerini) yığına itmek çağıranın görevidir. Dönüş adresini oraya yerleştirmek ise `call` komutuyla işlemcinin otomatik yaptığı iştir. Saldırıda fonksiyon `call` ile değil `ret` ile "çağrılır":

1. Saldırgan dönüş adresine `exec`'in adresini, ondan önceki argüman alanına dizgenin işaretçisini, onun ötesine de dizgenin kendisini yerleştirir.
2. Fonksiyon geri dönerken dönüş adresini kullanır ve `exec`'e gider.
3. `exec` çağrılan taraftır. Yaptığı şey, kendisini çağıranın yazmaç değerlerini (callee-saved registers) bir yere saklamaktır; argüman alanına bir şey itmez, argümanları değiştirmez.
4. Ardından argüman alanından işaretçiyi alır ve gösterdiği dizgedeki programı (`/bin/sh`) yükleyip çalıştırır.

Yığına bir bayt bile komut aktarılmadı: yalnız argüman ve dönüş adresi aktarıldı. Yığında kod çalışmadı; `exec` zaten çalıştırılabilir bir yerde, libc içindedir ve yığından yalnız argümanları kullanır. Hocaya göre bu, ilk saldırıya göre daha sofistike ve daha rahat bir saldırıdır: adres hesabı inanılmaz kolaylaşır; NOP kızağının adresinin çift mi tek mi olacağı, dörde bölünüp bölünmeyeceği gibi dertler kalmaz.

> **Ek bilgi (derste anlatılmadı):** Tek bir libc fonksiyonuna dönülen bu saldırı literatürde genellikle "return-to-libc" diye anılır. ROP terimi ise çoğu zaman, `ret` ile biten kısa komut dizilerinin ("gadget") art arda zincirlenmesiyle keyfi hesaplama yapılan genel tekniği belirtir. Derste ve slaytta iki yaklaşım ROP başlığı altında birlikte anlatıldı.

### 5.3 Uzaktan Kabuk: dup2 ve execve Zinciri

Saldırının uzaktan, internet üzerinden yapıldığı varsayılır. Örneğin bir web sunucusundaki açık kullanılarak saldırganın kendi bilgisayarı ile sunucu arasında öyle bir bağlantı kurulmak istenir ki saldırgan komut satırına yazıyormuş gibi komutları uzak sistemde çalıştırabilsin. Slayt şöyleydi (ekrandan, 00:50:00):

```c
// To run /bin/sh we must direct stdin and stdout to the socket:
dup2(s, 0)        // map stdin to socket
dup2(s, 1)        // map stdout to socket
execve("/bin/sh", 0, 0);
```

Soket, TCP/IP mantığında iki uç arasında veriyi taşıyan yapıdır. Her çalışan programın bir standart girişi (tanımlayıcısı 0) ve standart çıkışı (1) vardır; program isterse standart hatayı (2) da kullanır. `dup2` bir dosya tanımlayıcısının kopyasını çıkarır (çoğullar). `dup2(s, 0)` soketi 0 ile ilişkilendirir, böylece saldırgan soket üzerinden kabuğa girdi gönderebilir. `dup2(s, 1)` soketi 1 ile ilişkilendirir, böylece kabuğun çıktısı soket üzerinden saldırgana döner; soketin öbür ucunda saldırgan vardır. Hoca, `dup` ve `dup2` diye iki ayrı sistem çağrısı olduğunu, burada `dup2`'nin kullanıldığını belirtti.

Bu üç fonksiyon C çalışma zamanı kütüphanesinde kullanıcıya açık birer fonksiyon olarak bulunur. Sistem çağrıları doğrudan da yapılabilir ama daha zordur; kütüphane fonksiyonları sistem çağrısının ihtiyaç duyduğu parametreleri alır, fonksiyon çağrısı gibi başlar ve sistem çağrısıyla devam eder.

### 5.4 Zincirin Yığında Kurulması

Slayttaki ayrıntılı çizimde "stack pointer moves up on pop" notu vardı: `pop` edildikçe yığın işaretçisi düşük adreslerden yüksek adreslere doğru ilerler. Taşma dizgesi, üç yapıyı "adres + argüman" çiftleri hâlinde arka arkaya yığına yerleştirir. Hocanın okuduğu adresler 408400, 408500 ve 408300 idi; ilk ikisinin ilgili konumunda `dup2`'ye, üçüncüsünde `exec`'e giden adres bulunuyordu. <!-- BELİRSİZ: ROP zinciri slaytındaki adresler (yaklaşık 00:51-00:54) karede görülmedi; değerler ve hangi adresin hangi fonksiyona karşılık geldiği altyazıdan alındı, Whisper karışıklığı olabilir. -->

Akış şöyledir:

1. İlk `ret` ile `dup2`'ye gidilir; yığındaki argümanlar `s` ve `0`'dır, soket standart girişle ilişkilendirilir.
2. `dup2`'nin sonundaki `ret` bir sonraki adrese götürür; bu kez argümanlar `s` ve `1`'dir, soket standart çıkışla ilişkilendirilir.
3. Bir sonraki `ret` ile `exec`'e gidilir; argümanlar `"/bin/sh"` ve iki tane 0'dır. Kabuk açılır.

Önceki iki `dup2` çağrısı sayesinde saldırgan, uzak sistemde açılan kabuğa kendi istemcisinden erişebilir, çünkü kabuğun standart girişi ve çıkışı soket üzerinden onunla ilişkilendirilmiştir.

Hoca işin ilginç tarafını şöyle anlattı: bir fonksiyon içinden başka bir fonksiyon `call` ile çağrılmadığı ve SFP değişmediği için, dönüş adresi değiştirilerek çağrılan her fonksiyonun sonundaki `ret`, sizi yine zincirin bir sonraki halkasına getirir. Normalde çağırmadan önce argümanlar itilir, `call` ise dönüş adresini yığına basar; burada ise fonksiyonun başına doğrudan `ret` ile gidilir. Hoca bunun "uzay icadı" bir şey olmadığını, işletim sistemindeki zamanlayıcının (scheduler/dispatcher) bir süreçten ötekine yığında değişiklik yapmadan geçmek için uzun yıllardır kullandığı yöntem olduğunu söyledi.

### 5.5 Katmanlı Savunma

Yığını çalıştırılamaz yapmak saldırganları ROP'a yöneltti ve bütün odak oraya kaydı. Bu, NX bitine artık gerek olmadığı anlamına gelmez.

> **Hocanın vurgusu:** "Hattı müdafaa yoktur, satıh müdafaası vardır." Tek bir çizgi hâlinde savunulursa çizginin herhangi bir yerinde delinme olduğunda arkaya geçilir. Farklı seviyelerde savunma yapılırsa biri delinse bile diğerlerinin tutma, yavaşlatma ya da tamamen durdurma şansı olur. Bu yüzden NX tedbiri alınmaya devam edilir; saldırganın seçenekleri sıkıştırılabildiği kadar sıkıştırılır.

## 6. Adres Uzayı Rastgeleleştirme (ASLR)

### 6.1 Fikir

Saldırgan bir önceki saldırıyı neden bu kadar rahat yapabiliyor? Hoca ilk derste söylediğini hatırlattı: saldırgan hedefin örneğin 32 bit Linux çekirdek sürümünü biliyorsa C çalışma zamanı kütüphanesinin sürümünü de bilir. Kütüphanedeki `exec`, `dup2` gibi bütün fonksiyonların adresi bellidir; tahmin etmek zorunda değildir. Bu şartlarda saldırı dizgesini kendi bilgisayarında adresler nokta atışı doğru olacak şekilde hazırlayıp karşıdaki açıktan gönderebilir.

Çözüm, saldırganın C kütüphanesindeki fonksiyonların adresini bu rahatlıkla tespit etmesini engellemektir, yani adres rastgeleleştirmesidir. Aynı çekirdek ve aynı C kütüphanesi sürümü olsa bile `exec`'in adresi her bilgisayar sisteminde farklıdır. Slayt şöyleydi (ekrandan, 00:55:00 ve 01:00:00):

```text
ASLR: (Address Space Layout Randomization)
 - Randomly shift location of all code in process memory
     => Attacker cannot jump directly to exec function
 - Deployment: (/DynamicBase)
     Windows 7: 8 bits of randomness for DLLs
       aligned to 64K page in a 16MB region => 256 choices
     Windows 8: 24 bits of randomness on 64-bit processors
```

### 6.2 Windows 7 ve Windows 8 Uygulaması

Hoca uygulamanın Windows 7'de yapıldığını, 64 bit seçeneği olsa da varsayılan sürümün 32 bit olduğunu söyledi. 32 bitlik adreste rastgele yapılabilecek bit sayısı çok kısıtlıdır; 8 bit rastgele yapılmaya karar verilmiştir.

**Örnek (ekrandan, 01:00:00):** Windows 7'de kütüphane kaç farklı konuma yerleşebilir?

- Verilen: 16 MB'lık bölge, 64 KB'lık adımlar (hizalama).
- İşlem: $\dfrac{16\ \text{MB}}{64\ \text{KB}} = \dfrac{2^{24}}{2^{16}} = 2^{8}$.
- Sonuç: 256 seçenek, yani 8 bit rastgelelik.

Windows 8 ile standart sürüm 64 bite geçtiği için rastgele belirlenebilen bit sayısı 24'e çıkar ($2^{24} = 16\,777\,216$ olasılık; ara adım eklendi). Hoca benzer yaklaşımın Linux'ta Windows'tan çok daha önce bulunduğunu, Linux'un 32 bit çözümlerinde bile 256'dan fazla seçenek sağladığını söyledi. Windows'un örnek olarak seçilmesi, uç kullanıcıda en yaygın işletim sistemi olması ve pek çok orta ölçekli sunucuda kullanılmasındandır.

> **Ders sonrası not:** Hoca ASLR'nin Windows'ta ilk kez Windows 7'de uygulandığını söyledi. Windows'ta ASLR büyük olasılıkla ilk kez Windows Vista (2007) ile geldi; slayt Windows 7'yi yalnız bir dağıtım örneği olarak veriyor.

### 6.3 Açılışta mı, Süreç Başına mı?

Microsoft işi hızlı yapmak için rastgele değeri sistem düzeyinde belirledi: sistem her açılışta rastgele bir değer üretir ve kütüphaneyi oraya yükler. Adresin değişmesi için sistemin yeniden başlatılması gerekir. Bu akıllıca görünür, ama Windows'un uç kullanıcı sürümleri sunucu sürümlerinin de temelidir; aynı karar Windows 7'nin eşleniği olan Windows Server için de geçerlidir. 32 bitte olası adres sayısı 256'dır ve bu bir sunucuysa (uç kullanıcı sistemi olsa da aynı) 256 denemeyle doğru adres bulunabilir. 64 bitte 24 bit olunca deneme sayısı artar. Hoca doğrusunun rastgeleleştirmeyi sistemin açılışında değil, her süreç çalıştırılırken bağımsız olarak yapmak olduğunu söyledi.

### 6.4 ASLR Örneği

Slaytta "Booting twice loads libraries into different locations" başlığıyla iki açılıştaki yükleme adresleri gösterildi (ekrandan, 01:05:00):

| DLL | 1. açılış | 2. açılış | Açıklama |
|---|---|---|---|
| ntlanman.dll | 0x6D7F0000 | 0x6DA90000 | Microsoft Lan Manager |
| ntmarta.dll | 0x75370000 | 0x75660000 | Windows NT MARTA provider |
| ntshrui.dll | 0x6F2C0000 | 0x6D9D0000 | Shell extensions for sharing |
| ole32.dll | 0x76160000 | 0x763C0000 | Microsoft OLE for Windows |

Hoca, örneğin `ole32.dll` için adresin 7616... iken 763C... olduğunu, Lan Manager'da 6D7F yerine 6DA9 olduğunu göstererek bir baytın değiştiğini, bunun da yeniden başlatmalarda adreslerin değiştiği anlamına geldiğini söyledi. Bu rastgeleleştirme yapılınca süreç belleğindeki her şey kayar: süreç bellek düzenindeki yığın, heap ve paylaşılan kütüphanelerin adresleri otomatik olarak değişir.

> **Ders sonrası not:** Hoca her satırda bir baytın değiştiğini söyledi. Tablodaki dört satırın üçünde yalnız üçüncü bayt (16-23. bitler) değişiyor. `ntshrui.dll` satırında ise (0x6F2C0000 → 0x6D9D0000) en üst bayt da değişiyor (python ile XOR alınarak kontrol edildi).

Windows 8 ile Windows 7'deki ve onun sunucu sürümündeki kısıtlamalar kaldırıldı: yüklü bütün sistem modülleri, ayrıca seçmeye gerek kalmadan ASLR kullanır.

### 6.5 Diğer Rastgeleleştirme Yaklaşımları

Akademik olarak tartışılmış, yayınları ve deneyleri yapılmış ama donanım ya da yazılım açısından uygulanması ASLR'ye göre daha zor olduğu için endüstride kabul görmemiş iki yaklaşım daha anlatıldı:

- **Sistem çağrısı rastgeleleştirme (syscall randomization):** Sistem çağrılarının numaraları vardır; örneğin `exec`'in numarası 72 olsun. Bu numara rastgeleleştirilir: bir sistemde 72, ötekinde 172, bir başkasında 372 olur.
- **Komut kümesi rastgeleleştirme (instruction set randomization):** Modern işlemcilerde sistem çağrısı için `syscall` gibi bir komut vardır ama aslında buna gerek yoktur; yazılımsal kesme üretecek bir durum yaratmak yeterlidir. En kolay yolu tanımsız bir komutu çalıştırmaktır; işlemci tanımadığı bir komutla karşılaşınca hata (kesme) üretir. Bazı işlemcilerde bayt cinsinden onlarca, hatta yüzlerce tanımsız kombinasyon vardır ve bunlar kullanılabilir.

## 7. kBouncer

Aradan sonra hoca, ROP'a karşı yapılan ve kabul gören bir çalışmayı anlattı. Bu yaklaşım, işlemcilerin mevcut durumuyla donanım düzeyinde de oldukça rahat gerçekleştirilebilir. Adı kBouncer'dır. "Bouncer" gece kulüplerinin kapısında kimin girip kimin giremeyeceğine karar veren fedaidir; "k" kernel'dan gelir. Yani çekirdeğin giriş kapısındaki fedai.

### 7.1 Gözlem: Anormal Yürütme Sırası

Slaytta `pop rdi; ret` → `pop rsi; ret` → `pop rax; ret` → `syscall; ret` → kernel şeklinde bir zincir çiziliydi; altında "Observation: abnormal execution sequence — ret returns to an address that does not follow a call" yazıyordu (ekrandan, 01:20:00).

Normal çalışmada her `ret`'in bir `call` karşılığı vardır: `ret` geri döndüğünde döndüğü adresin hemen öncesinde bir `call` komutu bulunur. ROP örneklerinde `dup2`, `exec` ya da diğer sistem çağrılarına `call` ile değil, adreslerine doğrudan `ret` ile gidildiği için, bu fonksiyonlar bitip `ret` çalıştığında dönülen adresin önünde bir `call` yoktur. kBouncer bunu tespit etmeye dayanır.

Kural şudur: bir sistem çağrısından önce, ondan önce gelen `ret` komutlarının döndüğü adreslerin hemen öncesinde `call` komutu olsun. Bu, donanımın izin verdiği kadar geriye (bir, iki, üç, dört...) gidilerek kontrol edilir. Hepsinde `call` varsa buraya düzgün bir sırayla gelinmiştir. Yoksa bu noktaya ROP ile gelinmiştir ve çekirdeğe girilmesi tehlikelidir.

**Soru:** Dispatcher da bu yöntemi kullanıyor dendi; o zaman sorun çıkmaz mı? **Cevap:** Dispatcher için bu kontrolün yapıldığı bilindiğinden onun sonucuna bakmak gerekmez. Ama dispatcher dışında herhangi bir durumda bununla karşılaşılırsa sorun var demektir. (Hoca bu soruyu kendisi sorup cevapladı.)

### 7.2 Donanım Desteği: Last Branch Recording

Slayt şöyleydi (ekrandan, 01:25:00):

```text
Intel's Last Branch Recording (LBR):
 - store 16 last executed branches in a set of on-chip registers (MSR)
 - read using rdmsr instruction from privileged mode
kBouncer: before entering kernel, verify that last 16 rets are normal
 - Requires no app. code changes, and minimal overhead
```

Intel işlemciler dallanma tahminini (branch prediction) daha iyi yapabilmek için, yani bir `if`'in doğru ya da yanlış koluna gidileceğini önceden tahmin edip o taraftan komutları pipeline'a alabilmek için, donanımda bir dallanma öngörüsü algoritması çalıştırır. Bunun parçası olarak son sürümlerde (i3, i5, i7, i9) son dallanmaların donanımsal bir listesi tutulur: Last Branch Recording. Liste yonga üstü yazmaçlarda son 16 dallanmayı saklar ve `rdmsr` komutuyla okunur. Böylece dönüş adresinin öncesinde gerçekten `call` olup olmadığı tespit edilebilir.

kBouncer, sistem çağrısı öncesinde çekirdekte yapılan çok basit bir değişiklikle, çekirdeğe girmeden son 16 dönüşün normal olduğunu doğrular. Uygulama kodunda değişiklik gerekmez; donanımda zaten bulunan bir bilgi okunup 16 karşılaştırma yapılır. Bu yüzden ek performans yükü çok düşüktür. Hoca, Intel'in yeni işlemcilerinde çalışan Linux çekirdeklerinde bu özelliğin kullanılmaya başlandığını, Power ve ARM ailelerinde de denk düşen donanım özellikleri bulunduğunu söyledi.

> **Ders sonrası not:** Hoca kBouncer'ın Linux çekirdeklerinde kullanılmaya başlandığını söyledi. kBouncer büyük olasılıkla 2013'te yayımlanmış akademik bir öneridir (bir sonraki slayttaki CFI listesinde de "kBouncer (2013)" olarak geçiyor); ana akım Linux çekirdeğine bu adla girdiği altyazıdan ya da slayttan doğrulanamadı.

### 7.3 Sınırı

Donanımsal MSR kümesi son 16 dallanmayı tutar. Saldırgan, son 16 dönüşü doğru gösterecek şekilde bir saldırı düzenleyebilir; yani son 16'sı doğru, 17.'sinde sorun olan bir zincir kurabilir. Bu çok daha sofistike bir saldırı gerektirir ve her koşulda yapılamaz.

> **Hocanın vurgusu:** İşi zorlaştırdık, riski neredeyse sıfırladık ama tamamen ortadan kaldırmadık; yine de bir ihtimal var. Yaptığımız şey riski yönetilebilir, kabul edilebilir sınırlar içine sokmaktır.

Buraya kadar platform tarafındaki tedbirler, yani işlemcide donanımsal olarak yapılabilecekler, işletim sistemindeki karşılıkları ve en önemlisi ROP'a karşı yapılması gerekenler görüldü. Sonraki kısım, doğrudan saldırılan çalıştırılabilir dosyanın nasıl güçlendirileceğiydi.

## 8. Çalışma Zamanı Denetimi: StackGuard ve Kanarya

### 8.1 Neden Kanarya?

Saldırı altındaki kodu güçlendirmenin pek çok uygulaması vardır; endüstride kabul görmüş ve bugün derleyicilerin kod üretirken uyguladığı en temel yöntem StackGuard'dır. Hoca isim benzerliğine dikkat çekti: kBouncer çekirdeğin fedaisiydi, StackGuard ise bodyguard gibi yığının koruyucusudur.

Buffer overflow olduğunda yığının yapısı bozulur: fonksiyona girildiğindeki hâli ile çıkıldığındaki hâli aynı değildir. Akla ilk gelen, yığını bir kenara kopyalayıp çıkışta birebir karşılaştırmaktır. Ama bunun için en başta sözü edilen ikinci bir yığın işaretçisi gibi donanımda olmayan bir özelliğe ihtiyaç vardır. Ayrıca argüman sayısı, yerel değişkenlerin boyutu ve kaydedilecek yazmaç sayısı düşünülünce bir bellek alanını bir başkasıyla birebir karşılaştırmak performans açısından sorunludur. Yapılabilir ama anlamlı değildir. Bu yüzden çok basitleştirilmiş bir hâli önerilmiştir.

Hoca adın kaynağını anlattı: kömür madenlerinde gaz kaçakları zehirlenmelere ve ölümlere yol açar, kaçak çoğu zaman önceden fark edilemez. Kuşların, özellikle kanaryaların bu gaza insanlardan daha duyarlı olduğu ve daha düşük seviyelerde öldükleri anlaşıldı. Madenciler ocağa kafes içinde kanaryalarla girer; kanaryalar yaşadıkça her şey normaldir. Kanarya öldüğünde henüz insan için tehlikeli olmayan ama tehlikeli hâle gelebilecek bir kaçak var demektir ve maden boşaltılır. Burada canlı hayvan değil bir veri kullanılır; bu veri, bozulması kolay bir sigorta teli gibi düşünülebilir.

### 8.2 Kanaryanın Yeri

Slayt şöyleydi (ekrandan, 01:30:00):

```text
Run time checking: StackGuard
 - Many run-time checking techniques ...
     we only discuss methods relevant to overflow protection
 - Solution 1: StackGuard
     Run time tests for stack integrity.
     Embed "canaries" in stack frames and verify their integrity
     prior to function return.

   Frame 2: | local | canary | sfp | ret | str |  Frame 1: | local | canary | sfp | ret | str |  top of stack
```

Kanarya, yerel değişkenler ile yığındaki kontrol bilgileri (SFP, istisna işaretçisi, dönüş adresi) arasına yerleştirilir. Yerel değişken üzerinden bir taşma olursa kanarya da bozulur; kanaryayı atlayıp ötesine ilerlemenin yolu yoktur. Bu yüzden dönüşte bir sürü değer yerine yalnız kanarya kontrol edilir; bu performans açısından çok daha iyidir. Kanarya bozulmadıysa yerel değişkenden yukarı doğru bir taşma yoktur.

### 8.3 Kanarya Türleri

Slayt şöyleydi (ekrandan, 01:35:00):

```text
Random canary:
 - Random string chosen at program startup.
 - Insert canary string into every stack frame.
 - Verify canary before returning from function.
     Exit program if canary changed. Turns potential exploit into DoS.
 - To corrupt, attacker must learn current random string.
Terminator canary: Canary = {0, newline, linefeed, EOF}
 - String functions will not copy beyond terminator.
 - Attacker cannot use string functions to corrupt stack.
```

**Rastgele kanarya:** Program başlarken rastgele bir değer seçilir, her yığın çerçevesine konur ve fonksiyondan dönmeden önce kontrol edilir. Değişmişse program sonlandırılır; yine tam ele geçirme DoS'a dönüştürülür. Dönüş adresini değiştirebilmek için saldırganın kanarya değerini öğrenmesi gerekir. Hoca burada format string zafiyetini hatırlattı: bu zafiyet bellek içeriğini kontrolsüz biçimde döktürdüğü için saldırgan kanaryayı öğrenebilir ve göndereceği paketin içinde kanaryanın denk geldiği yere bu değeri koyabilir. O zaman kanarya taşma sırasında ezilse bile kendi orijinal değeriyle ezildiği için fark edilmez. Yöntem yüzde yüz mutlak bir çözüm değildir ama saldırganın işini çok zorlaştırır.

**Sonlandırıcı (terminator) kanarya:** Daha çok string fonksiyonlarındaki açıklara karşıdır. `strcpy` 0 değerini (ya da newline, linefeed, EOF) görünce kopyalamayı durdurur. Bu değerlerden biri kanarya olarak konursa `strcpy` daha fazla ilerleyemez. Hiçbir kontrol yapılmaz, çünkü kopyalamanın orada biteceğinden emin olunur; bu yüzden performansı çok daha yüksektir. Ama saldırının string fonksiyonları üzerinden yapıldığı varsayımına dayandığı için koruma yeteneği daha düşüktür. Rastgele kanarya ise kanarya herhangi bir yolla ezilip dönüş adresi ve argümanlar değiştirildiğinde de durumu fark eder.

StackGuard önce GCC'de bir güncelleme olarak denendi; programın yeniden derlenmesi gerekiyordu. Bir dönem en çok saldırıya uğrayan programlardan biri olan Apache web sunucusunda, aynı işlemcide yalnız %8'lik bir performans düşüşü gösterdiği anlaşıldı. Bu kabul edilebilir bir maliyettir ve yöntem neredeyse günümüzün endüstri standardı olmuştur.

## 9. ProPolice ve Microsoft /GS

### 9.1 ProPolice

Kanarya yapısı tam koruma sağlamaz; kanaryanın değerini tespit eden yöntemler kullanılırsa kanarya değişmemiş gibi görünür ve korumanın anlamı kalmaz. IBM, StackGuard üzerinde çalışıp bir iyileştirme önerdi ve endüstri bunu kabul etti. Bugün kullanılan sürüm ProPolice, kısa adıyla Stack Protector'dır. Slayt şöyleydi (ekrandan, 01:40:00):

```text
StackGuard enhancements: ProPolice
 - ProPolice - since gcc 3.4.1. (-fstack-protector)
     Rearrange stack layout to prevent ptr overflow.

   String Growth (yukarı)        args
                                 ret addr
                                 SFP
                                 CANARY
                                 local string buffers
   Stack Growth (aşağı)          local non-buffer variables   <- pointers, but no arrays
                                 copy of pointer args
   Protects pointer args and local pointers from a buffer overflow
```

Hoca bu yaklaşımı Doğu kültüründeki Feng Shui'ye benzetti: bir ortamdaki eşyaların enerji akışından en iyi yararlanılacak şekilde düzenlenmesi. Burada da yığındaki veri ve kontrol bilgisinin, kontrol ile veriyi en iyi ayıracak ve olası bir saldırıyı kanarya üzerinden en iyi tespit edecek şekilde nasıl düzenleneceği sorusu cevaplanır.

IBM'in önerisi şöyledir:

- Argümanlar, dönüş adresi ve SFP çağırana aittir; onlara dokunulmaz.
- SFP'den hemen sonra kanarya gelir. Gerekirse (C++ çalışma ortamı varsa) arada istisna işleyicileri de yer alır.
- Taşmaya yol açabilecek değişkenler dizilerdir (tamponlar). Programcı yerel değişkenleri hangi sırayla tanımlamış olursa olsun, dizi türündeki yerel tamponlar kanaryanın hemen dibine yerleştirilir.
- Dizi olmayan değişkenler (tek karakter, integer, float, struct, işaretçiler) tamponların altına yerleştirilir.
- Kanaryanın koruduğu bölgeye kod akışı sırasında erişilmemesi için, işaretçi olan argümanların (call by value değil call by reference ile aktarılanların) kopyası da aşağıya alınır.

Böylece kanarya tam ortada bir koruma duvarı olur: bir tampon yukarı doğru taşarsa önce kanaryayı bozar, aşağıdaki işaretçilere ise ulaşamaz.

### 9.2 Microsoft /GS ve Cookie

Hoca, Visual Studio'da bu korumanın nasıl uygulandığını üretilen kod üzerinden gösterdi. Microsoft, ProPolice ile rastgele kanaryanın bir birleşimini kullanır. Linux tarafı buna StackGuard, Microsoft tarafı Guard Stack der; /GS kısaltması buradan gelir. Kanaryanın Microsoft jargonundaki karşılığı "cookie"dir.

Hocanın anlattığı akış şöyledir:

1. Fonksiyon girişinde yığında 8 baytlık bir yer açılır.
2. `__security_cookie`'nin orijinal değeri alınır ve yığın işaretçisi (ESP) ile XOR'lanır.
3. Sonuç ESP+8'e, yani açılan alana yazılır. Kanarya budur.
4. Fonksiyon çıkışında bu değer alınır ve yine ESP ile XOR'lanır; orijinal değere dönmüş olması gerekir.
5. `__security_check_cookie` çağrılır. Değer doğruysa yığın işaretçisi 8 geri alınır (girişteki `sub`'ın tersi) ve normal akış sürer. Bozulmuşsa süreç sonlandırılır.

<!-- BELİRSİZ: /GS derleyici çıktısı (yaklaşık 01:41-01:43) karede görülmedi; komutlar ve ofsetler hocanın anlatımından aktarıldı. -->

XOR en basit kriptografik işlemdir: mod 2 aritmetiğinde toplamadır ve mod 2'de toplama ile çıkarma aynıdır. Bu yüzden aynı değerle art arda iki kez XOR yapılınca orijinal değer bulunur:

$$c \oplus sp \oplus sp = c$$

Cookie sabit olsa da yığın işaretçisi çalışma sırasında sürekli değiştiği için XOR sonucu hep farklı (rastgele görünen) değerler çıkar. (Özdeşlik python ile örnek değerlerle kontrol edildi.)

Hoca, Visual Studio'da geliştirilen bir fonksiyon "3" değeriyle dönerse o fonksiyona bir saldırı olmuş demektir, diye ekledi.

> **Ders sonrası not:** Hoca, cookie bozulunca fonksiyonun "Exit 3" ile döndüğünü söyledi. Güncel MSVC çalışma ortamlarında cookie hatası büyük olasılıkla süreci `STATUS_STACK_BUFFER_OVERRUN` (0xC0000409) koduyla sonlandırır; "3" değeri altyazıdan ve kareden doğrulanamadı.

/GS başlangıçta (2003) kullanıcının açması gereken bir özellikti; hatta fonksiyon bazında açılıp kapatılabiliyordu. Visual Studio 2010 ile tersine döndü: devre dışı bırakılmadıkça bütün fonksiyonlara uygulanır; istenmeyen fonksiyonlar bir istisna listesine verilir.

### 9.3 /GS Çerçevesi: İstisna İşleyicilerini de Korumak

Microsoft bir adım daha attı: ProPolice yapısıyla birleştirdiği /GS düzeninde istisna işleyicilerini de koruyabileceğini söyledi. Slayt şöyleydi (ekrandan, 01:45:00):

```text
/GS stack frame
   args
   ret addr             \
   SFP                   } Canary protects ret-addr and
   exception handlers   /  exception handler frame
   CANARY
   local string buffers
   local non-buffer variables   <- pointers, but no arrays
   copy of pointer args
```

İstisna işleyicileri çalışma ortamı nedeniyle SFP ile kanarya arasında yer alır. Böylece kanarya artık yalnız dönüş adresini değil istisna işleyici çerçevesini de korur (görünüşte).

## 10. SEH Saldırısı, SafeSEH ve SEHOP

### 10.1 SEH Listesi ve Saldırı

İstisna işleyici yapısı kendi içinde bağlı bir liste gibidir, çünkü özel istisnadan genel istisnaya doğru gidilir: önce en özel durum, değilse bir sonraki, değilse bir sonraki... Her kayıtta bir sonraki kaydı gösteren `next` işaretçisi ve bir `handler` vardır. SEH, structured exception handling demektir. Bir istisna oluştuğunda ne yapılacağına karar veren kod parçası olan istisna dispatcher'ı, listeyi uygun bir işleyici bulana kadar dolaşır; tam uyan bir işleyici yoksa varsayılan işleyiciyi kullanır.

Saldırıda tampon taşırılır, hem `next` hem `handler` alanları ezilir. Taşmadan sonra `handler` saldırganın koduna işaret eder. İstisna oluştuğunda kontrol ele geçirilir.

Dikkat edilecek nokta şudur: istisna, kanarya kontrolünden önce tetiklenir. Kanarya kontrolü fonksiyondan dönerken yapılır, istisna ise fonksiyon çalışırken oluşur. /GS düzeninde kanarya istisna işleyicilerinin önünde, yerel tamponlar da kanaryanın arkasında olduğu için, istisna listesini değiştirecek bir taşma kanaryayı da mutlaka ezer. Bunun üstüne bir istisna tetiklenirse, kanarya kontrol edilmeden doğrudan istisna işleyicisinin gösterdiği adrese gidilir. Hoca durumun daha da ciddi bir yanını vurguladı: kanaryanın bozulması da bir istisnadır. Saldırgan kanaryayı bozarak, kanarya kontrol edilmeden istisna oluşmasını ve kendi adresine gidilmesini tetikleyebilir.

Hoca buna gerileme (regression) dedi: iyi özellikleri bir araya getirip daha iyi bir yapı kurmak isterken, birbirleriyle çelişen ve birbirini olumsuz etkileyen durumlar yüzünden iyiye değil kötüye gidilmesi.

### 10.2 SafeSEH ve SEHOP

Slayt şöyleydi (ekrandan, 01:50:00):

```text
Defenses: SAFESEH and SEHOP
 - /SAFESEH: linker flag
     Linker produces a binary with a table of safe exception handlers
     System will not jump to exception handler not on list
 - /SEHOP: platform defense (since win vista SP1)
     Observation: SEH attacks typically corrupt the "next" entry in SEH list.
     SEHOP: add a dummy record at top of SEH list
     When exception occurs, dispatcher walks up list and verifies dummy
     record is there. If not, terminates process.
```

**SafeSEH:** Programcı hangi durumların istisna üretmesi gerektiğini kaynak kodda zaten belirtir. Kaynak kod nesne koduna dönüştürülürken kenarda güvenli istisna işleyici adreslerinin bir listesi oluşturulur. Sistem bir istisna adresine gideceğinde o adresin listede olup olmadığına bakar; listede değilse gitmez, program sonlandırılır (yine DoS). Ancak performans yükü çok fazladır: C++, C# ve Java gibi nesne yönelimli dillerde neredeyse her şey try-catch içinde yapıldığından istisnalar çok yoğun kullanılır.

**SEHOP:** SEH saldırıları tipik olarak listedeki `next` girdisini bozmak zorundadır, çünkü liste bağlıdır. Listenin en başına bir sahte (dummy) kayıt konur. İstisna oluştuğunda dispatcher zaten listeyi dolaşacağı için bu sırada sahte kaydın yerinde ve düzgün olduğunu da doğrular. Bu, aslında SEH için ayrı bir kanarya demektir. Kayıt doğruysa istisna işlenir; bozuksa istisna adresi değiştirilmiş ve akış ele geçirilebilir durumdadır, program sonlandırılır.

> **Hocanın vurgusu:** Kanarya yapısı güzeldir ama her şeyi korumaz. Kanarya tamamen yığınla ilgilidir; heap için bir koruma sağlamaz. Fark edilmeyen bir integer overflow da farklı adresleri gösterebilir. Microsoft'un /GS yapısı mevcut hâliyle, istisna işleme nedeniyle saldırganlar için "bayram hediyesi" gibidir; mutlaka SafeSEH ya da SEHOP ile birlikte kullanılmalıdır.

## 11. Kanarya Çıkarma (Canary Extraction)

Hoca bir "karanlık senaryo" anlattı. Slayt şöyleydi (ekrandan, 01:55:00):

```text
Even worse: canary extraction
A common design for crash recovery:
 - When process crashes, restart automatically (for availability)
 - Often canary is unchanged (reason: relaunch using fork)
   ... | local buffer |   | C A N A R Y | ret addr |
Danger: canary extraction byte by byte
```

Süreklilik için, bir sistemde çalışan servis kesintiye uğrayınca elle başlatmak yerine otomatik yeniden başlatılması sağlanır. Unix türevlerinde ve Windows'ta bu neredeyse standart yaklaşımdır: servis çöktüğünde döküm (dump) kenara alınıp sonra incelenir, ama servis çalışmaya devam etmelidir. Bu yeniden başlatma sırasında servisin kopyası `fork` ile çıkarılır. `fork` kopya çıkarır; çocuk süreçte `exec` ile yeni bir çalıştırılabilir dosya yüklenmez, var olan çalıştırılabilir kendini yeniden başlatır. `exec` yapılmadığı için kanarya değeri değişmez.

Saldırgan bunu şöyle kullanır: kanarya örnekte olduğu gibi "CANARY" olsun. Saldırgan uygulamaya saldırır, kanaryanın ilk baytına A koyar, uygulama çöker; B koyar, çöker; C koyar, çökmez. İlk bayt bulunmuştur. Sonra ikinci bayta geçilir: CA... Böylece kanarya bayt bayt çıkarılır (dictionary attack). Saldırganın müdahale etmesine bile gerek yoktur; farklı kanarya değerleriyle saldıran bir script yeter.

**Örnek (derste sözlü, 01:55:51):** Derleyici yapısından kanaryanın 8 bayt olduğu bilinsin. Kaç deneme gerekir?

- Verilen: 8 baytlık kanarya; her bayt 256 farklı değer alabilir.
- Bütün baytlar tek parça düşünülürse: $2^{64}$ kombinasyon denemek gerekir; hocanın deyişiyle "yüzyıllarımı alacak bir şey".
- Bayt bayt çıkarmada: her bayt için en çok 256 deneme.
- Sonuç: $256 \times 8 = 2048$ deneme (en kötü durum).

> **Ders sonrası not:** Hoca "8 byte 64 byte'a düşüyor" dedi; doğrusu 8 bayt = 64 bittir ve tek parça deneme $2^{64}$ olasılık demektir. Ayrıca bayt başına ortalama 128 deneme ile ortalama durumda yaklaşık $128 \times 8 = 1024$ deneme yeter (ara adım eklendi, python ile kontrol edildi).

Hoca bunu felaket bir senaryo olarak niteledi ve buna da tedbir alınması gerektiğini söyledi. Benzer biçimde ASLR ile korunan bir servis `fork` üzerinden yeniden başlatılırsa rastgeleleştirme yeniden yapılmadığından oradaki rastgelelik de aynı yolla çözülebilir.

## 12. LibSafe

Buraya kadarki çözümlerin hepsinde programın yeniden derlenmesi gerekiyordu. Yeniden derlenemiyorsa ne yapılır?

İşletim sisteminde kütüphaneler dinamik olarak yüklenir ve aynı anda birçok uygulama tarafından kullanılır; sistem çağrılarının gerçekleştirilmesinde aracıdırlar. Araya, güvensiz bir fonksiyonun güvenli sürümünü sağlayan ve aynı adlı fonksiyonu içeren bir kütüphane yerleştirilirse orijinal kütüphane değil yerleştirilen kütüphane çağrılır. Burada belirleyici olan dinamik kütüphanelerin yüklenme sırasıdır: en son yüklenen kütüphanedeki fonksiyonlar geçerlidir. Böylece sistemin ve uygulamaların çalışmasını değiştirmeden bir fonksiyonun güvenli sürümü sisteme yükletilebilir.

LibSafe bunu yapar. En çok saldırı `strcpy` üzerinden yapıldığı için LibSafe kopyalamadan önce şunu kontrol eder: çerçeve işaretçisi ile hedef arasındaki bayt cinsinden uzaklık, kopyalanacak kaynağın uzunluğundan büyük mü? Yani hedef, kaynağı karşılar mı? Bunun bir performans maliyeti olduğu kesindir, ama en azından kopyalama sonrasında SFP ve dönüş adresinin ezilmesi engellenir. Tedbir str ailesi üzerinden yapılabilecek saldırılara karşıdır ve yeniden derleme gerektirmez. Uygulama bozuksa bozuk kalır, ama koşullar düzgün değilse uygulama sonlandırılır: yine tam ele geçirme DoS'a dönüştürülmüş olur.

## 13. Gölge Yığın (Shadow Stack)

Slayt şöyleydi (ekrandan, 02:00:00):

```text
More methods: Shadow Stack
Shadow Stack: keep a copy of the stack in memory
 - On call: push ret-address to shadow stack on call
 - On ret:  check that top of shadow stack is equal to
            ret-address on stack. Crash if not.
 - Security: memory corruption should not corrupt shadow stack
```

Bu, dersin başında sözü edilen "yığının kopyasını tutma" fikrinin yalnız dönüş adresleri için uygulanmasıdır. `call` anında dönüş adresi gölge yığına da itilir; `ret` anında gölge yığının tepesi gerçek yığındaki dönüş adresiyle karşılaştırılır, eşit değilse program çöker. Saldırganın gölge yığın bölgesine erişemediği varsayılır.

Intel bunun için donanım düzeyinde bir özellik sağlar: gölge yığın işaretçisi. Bu gerçek bir yığın işaretçisi değildir; belirli koşullarda mevcut yığın işaretçisini gölgeleyecek şekilde çalışır. Gölge yığın sayfaları yeni bir öznitelikle işaretlenir; `call` ve `ret` sırasında bu sayfalar okunup yazılabilir, bunların dışında değiştirilemez.

## 14. Kontrol Akışı Bütünlüğü: CFI, CFG ve CET

### 14.1 CFI

Slayt şöyleydi (ekrandan, 02:05:00):

```c
// Control flow integrity (CFI) [ABEL'05, ...]
// Ultimate Goal: ensure control flows as specified by code's flow graph
void HandshakeHandler(Session *s, char *pkt) {
    ...
    s->hdlr(s, pkt)
}
// Compile time: build list of possible call targets
// Run time: before call, check validity of s->hdlr
// Lots of academic research on CFI systems:
//   CCFIR (2013), kBouncer (2013), FECFI (2014), CSCFI (2015), ...
// and many attacks ...
```

CFI, 2005'te önerilmiş bir yöntemdir. Kodun akış grafiği çıkarılır ve öngörülen akış ile o anda gerçekleşen akışın aynı olup olmadığı karşılaştırılır. Derleme sırasında herhangi bir noktadan nerelere dallanılabileceğinin listesi çıkarılır. Çalışma sırasında `call` komutundan önce, gerçekten bu listedeki adreslere gidilip gidilmediği kontrol edilir. Hoca, SafeSEH'teki güvenli istisna işleyici listesinin de bu yaklaşımdan yola çıkılarak geliştirildiğini, kBouncer'ın da bu araştırmaların bir sonucu olarak ortaya çıktığını ve çok sayıda araştırma arasında kabul görenlerden biri olduğunu söyledi.

### 14.2 Control Flow Guard (CFG)

Microsoft, Windows 10'da Control Flow Guard'ı devreye aldı. Bu, CFI'ın "yoksul adam sürümü"dür (poor man's version). CFI bütün olası akışları tespit edip bunların dışında bir akış olmamasını garanti etmeye çalışır. CFG ise yalnız dolaylı çağrıları korur: çalıştırılabilir dosyadaki bütün geçerli fonksiyon giriş noktalarının bir bit maskesine (bitmap) bakarak, dolaylı bir çağrıda hedefe gitmeye izin olup olmadığını kontrol eder. Windows'ta bunu yapan kütüphane fonksiyonu `_guard_check_icall`'dur ve hedefin bir fonksiyonun giriş noktası olduğunu doğrular.

Slayttaki derleyici çıktısının görünen kısmı şöyleydi (ekrandan, 02:10:00):

```text
rep s...
mov   ...
mov   ...
push  ...
call  @_guard_check_icall@4    ; _guard_check_icall(x)
call  esi
add   esp, 4
xor   eax, eax
```

<!-- BELİRSİZ: CFG kod örneğindeki mov/push satırlarının işlenenleri, karede üstte açılan bir kutunun altında kaldı ve okunamadı. -->

Hoca kodu şöyle açıkladı: `call esi` ile ESI'daki adrese gidilecektir; ESI bir fonksiyon işaretçisidir. Doğrudan gidilirse saldırganın verdiği koda gidilebilir. Bu yüzden ESI'ın bir kopyası ECX'e alınır ve `_guard_check_icall`'a gönderilir. Bu fonksiyon ECX'teki adresi kendi tablosunda, performans için bit haritası üzerinden kontrol eder; ya çalışmayı durdurur ya da akışın sürmesine izin verir. İzin verirse `call esi` ile dolaylı çağrı yapılır.

### 14.3 Intel CET

Intel, bu işi kolaylaştırmak için donanımda CET adlı bir yapı önerdi. 64 bit komut kümesinde yeni bir "end branch" komutu vardır. Dolaylı bir `jmp` ya da `call` komutundan sonra (yani bir fonksiyon işaretçisi ya da uzun atlama sonrasında), komut akışındaki bir sonraki komut "end branch" olmalıdır. Değilse bir hata tetiklenir ve yürütme durdurulur. Saldırgan, kendi akışı içinde gideceği yere bu komutu yerleştiremez; normalde bu komutun bulunmadığı bir yere gidecektir. Böylece dolaylı bir atlama ya da çağrı yalnız geçerli bir hedef adrese gidebilir. Derleyici "end branch" komutunu geçerli yerlere kendisi ekler; programcının bir şey yapması gerekmez.

> **Ek bilgi (derste anlatılmadı):** x86-64'te bu komutun adı `ENDBR64`'tür (32 bit için `ENDBR32`). Intel CET, bu dolaylı dallanma takibinin (IBT) yanında bir önceki bölümde anlatılan donanımsal gölge yığını da içerir. GCC'de bu destek büyük olasılıkla `-fcf-protection` seçeneğiyle açılır.

### 14.4 Sınır: Geçerli Ama Yanlış Fonksiyon

Slayttaki uyarı şöyleydi (ekrandan, 02:10:00):

```text
- Do not prevent attacker from causing a jump to a valid wrong function
- Hard to build accurate control flow graph statically
```

Geçerli fonksiyonlar listesindeki bir fonksiyon saldırganın bir adımı atlamasını ya da bir veriyi açığa çıkarmasını sağlıyorsa, saldırgan kontrol akışını geçerli ama o anda çağrılmaması gereken bir fonksiyona yönlendirebilir. Nedeni, kaynak kod üzerinden (statik olarak, çalışma zamanında değil) çok hassas bir kontrol akış grafiği çıkarmanın maliyetinin çok yüksek olmasıdır; hocaya göre bazı durumlarda polinom olmayan zamana kadar gider.

Hoca örneği şöyle anlattı: HandshakeHandler, LoginHandler'ı çağırır; LoginHandler kimlik bilgilerini doğrulamak için CheckCredentials'ı çağırır, yetkilendirme sağlanırsa DataHandler'a gidilir. Yani önce oturum açılır, kullanıcı adı ve parola onaylanır, sonra veriye erişilir. Saldırgan tam bu noktada saldırır ve LoginHandler'ın yerine DataHandler'ı çağırtır. LoginHandler da DataHandler da kodda yer alan, geçerli ve onaylı fonksiyonlardır. Ama giriş dizisi atlanmış olur: kullanıcı adı ve parolasını girmemiş, yetkisiz bir kullanıcı veriye erişebilir.

### 14.5 Kriptografik CFI

ARM işlemcileri tarafında da CFI üzerine çalışmalar yapılmaktadır. Gelinen noktada saldırganın bellekte herhangi bir yeri okuyup yazabileceği varsayılmalıdır; buna kısıt getirilemez. Bu koşullarda programın öngörülen akışından çıkmaması gerekir, çünkü buffer overflow saldırısının temelinde uygulamanın kontrol akışını değiştirmek vardır. Hocanın anlattığı yöntem şöyledir:

- Bir atlama adresi bellekte herhangi bir yere yazıldığında ya da kopyalandığında 64 bitlik bir MAC (altyazıda "IS MAC"; büyük olasılıkla AES-MAC) hesaplanır ve adrese eklenir.
- Adresin heap'te mi yığında mı olduğu ayrıca işaretlenir.
- Her `jmp` ya da `call` öncesinde adresin geçerliliği MAC ile yeniden doğrulanır; doğru değilse program durdurulur.

<!-- BELİRSİZ: Kriptografik CFI slaytı (yaklaşık 02:12-02:14) karede görülmedi. Altyazıda "IS MAC" geçiyor (büyük olasılıkla AES-MAC); "heap'te sıfır, stack'te bir" işaretlemesinin ayrıntısı doğrulanamadı. -->

Sorun anahtardır: anahtar bellekte saklanmamalıdır, çünkü saldırgan belleğin her yerini okuyabilir. Hoca bunun için özel XMM yazmaçlarının kullanıldığını, bu yazmaçların yalnız ayrıcalıklı kipte (işletim sistemi tarafından) okunup değiştirilebildiğini söyledi.

> **Ders sonrası not:** Hoca bu yöntemi ARM işlemcisine bağladı. XMM yazmaçları x86 (Intel/AMD) mimarisinin SSE yazmaçlarıdır; anahtarı XMM yazmaçlarında tutan kriptografik CFI (CCFI) büyük olasılıkla x86-64 ve AES-NI üzerinde tasarlanmıştır.

Örneğe dönülürse: saldırgan CheckCredentials'ı atlayıp LoginHandler'dan DataHandler'a geçilmesini sağlamak istiyordu. Kriptografik CFI devredeyken saldırgan DataHandler adresi için geçerli bir MAC değeri üretemez; bu yüzden akışı oraya çeviremez.

## Örnek Sorular

**Soru 1 (derste sözlü, 00:05:22):** Stack smashing saldırısında yığında özellikle neresi ezilir ve neden?

> **Cevap (derste verildi):** Bir geri dönüş adresi ya da bir fonksiyon işaretçisi ezilir. Böylece o adrese başvurulduğunda program akışı saldırganın istediği kod parçasına gider.

**Soru 2 (derste sözlü, 00:25:54):** Düzgün gerçekleştirilemeyen bir buffer overflow saldırısı büyük olasılıkla hangi saldırıya dönüşür?

> **Cevap (derste verildi):** Hizmet engelleme (denial of service) saldırısına. Savunmalar da tam ele geçirmeyi bilinçli olarak DoS'a dönüştürür.

**Soru 3 (ekrandan, 00:40:00; derste sözlü, 00:44:57):** ROP saldırısında (`ret-addr` → `exec()`, `args` → `"/bin/sh"`) yığında kod çalıştırılır mı? `exec` nerede çalışır ve yığından neyi kullanır?

> **Cevap (derste verildi):** Yığında kod çalıştırılmaz, tek bir komut baytı bile aktarılmaz. `exec` libc içinde, yani zaten çalıştırılabilir bir yerde çalışır. Yığından yalnız argümanları (dizgenin işaretçisini) kullanır. Bu yüzden DEP/NX bu saldırıyı engellemez.

**Soru 4 (ekrandan, 00:50:00):** Uzaktaki bir sunucuda açılan `/bin/sh` kabuğunu saldırganın kendi bilgisayarından kullanabilmesi için hangi çağrılar yapılmalıdır?

> **Cevap (derste verildi):** `dup2(s, 0)` ile standart giriş, `dup2(s, 1)` ile standart çıkış saldırganın soketine bağlanır; ardından `execve("/bin/sh", 0, 0)` çağrılır.

**Soru 5 (ekrandan, 01:00:00):** Windows 7'de DLL'ler 16 MB'lık bir bölgede 64 KB'lık sayfalara hizalı olarak rastgele yerleştirilirse kaç seçenek vardır, kaç bit rastgelelik elde edilir?

> **Cevap (derste verildi):** $\dfrac{16\ \text{MB}}{64\ \text{KB}} = \dfrac{2^{24}}{2^{16}} = 2^8 = 256$ seçenek, yani 8 bit rastgelelik.

**Soru 6 (derste sözlü, 01:33:22):** Rastgele kanarya kullanılan bir sistemde saldırganın dönüş adresini değiştirebilmesi için ne bilmesi gerekir ve bunu nasıl öğrenebilir?

> **Cevap (derste verildi):** Kanaryanın değerini bilmesi gerekir. Örneğin bir format string zafiyeti bellek içeriğini döktürdüğü için kanarya bu yolla öğrenilebilir; saldırgan değeri taşma paketinde kanaryanın yerine koyar.

**Soru 7 (derste sözlü, 01:47:01):** /GS düzeninde kanarya istisna işleyicilerini koruyor görünse de SEH saldırısı neden başarılı olur?

> **Cevap (derste verildi):** Kanarya kontrolü fonksiyondan dönerken yapılır, istisna ise fonksiyon çalışırken oluşur. Taşma `next` ve `handler` alanlarını ezdikten sonra istisna tetiklenirse kanarya kontrol edilmeden saldırganın adresine gidilir. Çözüm SafeSEH ya da SEHOP'tur.

**Soru 8 (ekrandan, 01:55:00; derste sözlü, 01:56:26):** `fork` ile otomatik yeniden başlatılan bir serviste 8 baytlık bir kanarya bayt bayt çıkarılırsa en çok kaç deneme gerekir?

> **Cevap (derste verildi):** Her bayt için en çok 256 deneme, toplam $256 \times 8 = 2048$ deneme. Kanarya tek parça denenseydi $2^{64}$ olasılık gerekirdi.

**Soru 9 (derste sözlü, 02:14:35):** Kriptografik CFI devredeyken, LoginHandler'ın yerine DataHandler'ı çağırtmak isteyen saldırgan neyi oluşturamaz?

> **Cevap (derste verildi):** DataHandler adresi için geçerli bir mesaj doğrulama kodu (MAC) oluşturamaz, çünkü anahtar bellekte değil, yalnız ayrıcalıklı kipte erişilebilen yazmaçlarda tutulur.

## Dersin Toparlaması

Ders, kontrol ele geçirme saldırılarının kök nedenini, yani veri ile kontrolün aynı kanalda (in-band) taşınmasını, Captain Crunch düdüğü örneğiyle buffer overflow'a bağlayarak başladı. Savunmalar üç başlıkta toplandı: hataları düzeltmek (denetim araçları, tip güvenli diller), platform savunmaları ve çalışma zamanı denetimleri. Platform tarafında DEP/NX ile yığında kod çalıştırma engellendi; saldırganlar bunun üzerine libc fonksiyonlarını `ret` ile zincirleyen ROP'a geçti. ROP'a karşı ASLR ile adresler rastgeleleştirildi, kBouncer ile de son 16 dönüşün bir `call`'u izleyip izlemediği çekirdeğe girmeden donanımsal LBR kayıtlarından kontrol edildi.

Çalışma zamanı tarafında StackGuard'ın kanaryası, ProPolice'in yığın düzenlemesi ve Microsoft /GS'nin cookie yapısı anlatıldı. Kanaryanın SEH saldırısı karşısındaki gerilemesi SafeSEH ve SEHOP ile kapatıldı. `fork` ile yeniden başlatılan servislerde kanaryanın bayt bayt çıkarılabileceği gösterildi. Yeniden derleme gerektirmeyen LibSafe, gölge yığın ve son olarak CFI, CFG, Intel CET ile kriptografik CFI ele alındı. Bu yöntemlerin hiçbiri riski sıfırlamaz. Hepsinin ortak sonucu, tam ele geçirmeyi hizmet engellemeye dönüştürmek ve katmanlı savunmayla saldırganın seçeneklerini daraltmaktır. Bir sonraki derste konuya kalınan yerden devam edileceği söylendi; slayttaki "more on this next week" notu, otomatik yazılım denetim araçlarının sonraki haftalarda ele alınacağını gösteriyordu.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
