# Ders 3 Çalışma Özeti

## Genel Konular

- Önceki dersin kısa tekrarı: kontrol ele geçirme (control hijacking) saldırıları
  - Stack smashing: yığındaki geri dönüş adresi ya da bir fonksiyon işaretçisi ezilir, akış saldırganın istediği koda gider.
  - Heap spraying: heap, önünde uzun bir NOP kızağı (NOP slide) bulunan saldırı koduyla doldurulur; böylece "gözü kapalı" atlamada bile saldırı kodu yüksek olasılıkla çalışır.
  - Use-after-free (Internet Explorer 11 örneği), integer overflow ve format string zafiyetleri.
- Temel tasarım hatası: veri ile kontrolü karıştırmak (ekrandan, 00:10:00)
  - Captain Crunch düdüğü: telefon santralinin şehirlerarası ücretlendirme sinyalini aynı ses hattından (in-band) göndermesi, düdükle bu sinyalin taklit edilip ücretsiz görüşme yapılmasına yol açtı.
  - In-band kontrol: kontrol bilgisi veriyle aynı kanaldan taşınır; out-of-band: ayrı kanaldan taşınır.
  - Buffer overflow da aynı hatanın ürünü: geri dönüş adresi (kontrol) ile yerel değişkenler ve argümanlar (veri) aynı yığında yan yana durur.
  - Hocanın düşünce deneyi: geri dönüş adresleri ile yerel değişkenler için iki ayrı yığın işaretçisi olsaydı buffer overflow saldırısı diye bir şey olmayacaktı. Bugün bu yapı uyumluluk (geriye uyumluluk, donanım bağımlılığı) nedeniyle değiştirilemiyor.
  - Aynı karışıklık XSS (cross-site scripting) ve use-after-free'deki vtable istismarının da temelidir.
- Ele geçirme saldırılarını önlemenin üç yolu (ekrandan, 00:25:00)
  - 1) Hataları düzeltmek: yazılımı otomatik araçlarla denetlemek (Coverity, Infer) ya da tip güvenli bir dille (Java, Go, Rust) yeniden yazmak. Eski (legacy) kod için zor.
  - 2) Platform savunmaları: saldırı kodunun çalışmasını engellemek.
  - 3) Çalışma zamanı kodu eklemek: taşma istismarı fark edilince süreci durdurmak (StackGuard, CFI, LibSafe).
  - Bu çözümlerin ortak sonucu: sistemin tamamen ele geçirilmesi (complete breach) hizmet engellemeye (DoS) dönüştürülür.
- Platform savunması 1: belleği çalıştırılamaz işaretlemek (DEP) (ekrandan, 00:30:00 ve 00:35:00)
  - Yığın ve heap çalıştırılamaz (non-executable) işaretlenir. Her sayfa tablosu girdisinde (PTE) bir öznitelik biti vardır.
  - AMD64'te NX biti, Intel x86'da XD biti (2005), ARM'de XN biti. Aynı işlev, ticari marka nedeniyle farklı adlar.
  - Dağıtım: Linux, OpenBSD; Windows'ta DEP, XP SP2'den (2004) beri. Visual Studio bayrağı: `/NXCompat[:NO]`.
  - Kısıtlar: JIT derleme (Java) ve Lisp (AutoCAD'in temelindeki dil) gibi çalışma ortamları yığın/heap'te kod çalıştırmaya ihtiyaç duyar. Windows XP'de Windows Explorer'ın DEP tarafından durdurulduğu ekran örneği gösterildi.
- Saldırı: Return Oriented Programming (ROP) (ekrandan, 00:40:00)
  - Kod enjekte etmeden kontrol ele geçirme: geri dönüş adresi libc içindeki `exec()` fonksiyonuna, argüman alanı `"/bin/sh"` dizgesinin adresine yönlendirilir.
  - Yığında tek bir komut çalıştırılmaz; `exec` zaten çalıştırılabilir olan libc içindedir. Bu yüzden DEP/NX bu saldırıyı engellemez.
  - Uzaktan kabuk için stdin ve stdout sokete yönlendirilir (ekrandan, 00:50:00): `dup2(s, 0)`, `dup2(s, 1)`, `execve("/bin/sh", 0, 0)`.
  - Zincir: her fonksiyonun adresi geri dönüş adresine, argümanları yanına yerleştirilir; her fonksiyonun sonundaki `ret` bir sonrakine götürür. Yöntem, işletim sistemindeki dispatcher'ın süreç değiştirirken kullandığı yönteme benzer.
- Platform savunması 2: ASLR (Address Space Layout Randomization) (ekrandan, 00:55:00 ve 01:00:00)
  - Süreç belleğindeki bütün kodun yeri rastgele kaydırılır; saldırgan `exec` fonksiyonuna doğrudan atlayamaz.
  - Windows 7: DLL'ler için 8 bit rastgelelik, 16 MB bölgede 64K hizalı, 256 seçenek. Windows 8: 64 bit işlemcilerde 24 bit rastgelelik. Bayrak: `/DynamicBase`.
  - Windows 7'de rastgele değer açılışta bir kez seçilir; doğrusu her süreç için ayrı seçmektir.
  - Akademik öneriler: sistem çağrısı numaralarının rastgeleleştirilmesi ve komut kümesi rastgeleleştirmesi; endüstride yaygınlaşmadı.
- Platform savunması 3: kBouncer (ekrandan, 01:20:00 ve 01:25:00)
  - Gözlem: ROP'ta `ret`, bir `call` komutunu izlemeyen bir adrese döner (anormal yürütme sırası).
  - Intel'in Last Branch Recording (LBR) özelliği son 16 dallanmayı yonga üstü MSR yazmaçlarında tutar, ayrıcalıklı kipte `rdmsr` ile okunur.
  - kBouncer, çekirdeğe girmeden önce son 16 `ret`'in normal olduğunu doğrular. Uygulama kodunda değişiklik gerekmez, ek yük çok düşüktür.
- Çalışma zamanı denetimi: StackGuard ve kanarya (ekrandan, 01:30:00 ve 01:35:00)
  - Yığın çerçevesinde yerel değişkenlerle kaydedilmiş çerçeve işaretçisi/geri dönüş adresi arasına bir kanarya değeri konur; fonksiyondan dönmeden önce kontrol edilir.
  - Rastgele kanarya: program başında seçilir, değişmişse program sonlandırılır (DoS'a dönüşür). Saldırganın değeri öğrenmesi gerekir (örneğin format string zafiyetiyle).
  - Sonlandırıcı (terminator) kanarya: {0, newline, linefeed, EOF}; string fonksiyonları bu değerin ötesine kopyalayamaz. Hızlıdır ama yalnız string tabanlı saldırılara karşı korur.
  - StackGuard'ın Apache üzerinde yaklaşık %8 performans kaybı getirdiği belirtildi.
- ProPolice ve Microsoft /GS (ekrandan, 01:40:00 ve 01:45:00)
  - ProPolice (gcc 3.4.1'den beri, `-fstack-protector`): yığın düzenini yeniden sıralar. Sıra: args, ret addr, SFP, CANARY, yerel dizi (string) tamponları, dizi olmayan yerel değişkenler, işaretçi argümanlarının kopyası.
  - Microsoft /GS: kanaryaya "cookie" der; cookie yığın işaretçisiyle XOR'lanıp çerçeveye yazılır, dönüşte yine XOR'lanıp `__security_check_cookie` ile denetlenir. Visual Studio 2010'dan beri varsayılan olarak bütün fonksiyonlara uygulanır.
  - /GS çerçevesinde istisna işleyicileri (exception handlers) kanaryanın üstündedir; kanarya hem geri dönüş adresini hem istisna işleyici çerçevesini korur.
- SEH (Structured Exception Handling) saldırısı ve savunmaları (ekrandan, 01:50:00)
  - SEH listesi bağlı listedir (next, handler). Taşma ile `next` ve `handler` ezilir, sonra istisna tetiklenir. İstisna, kanarya kontrolünden önce gerçekleştiği için kanarya işe yaramaz; bu bir gerilemedir.
  - `/SAFESEH` (bağlayıcı bayrağı): ikili dosyada güvenli istisna işleyicileri tablosu üretilir; listede olmayan işleyiciye atlanmaz.
  - `/SEHOP` (platform savunması, Vista SP1'den beri): SEH listesinin en başına sahte (dummy) bir kayıt konur; dispatcher listeyi dolaşırken bu kaydı doğrular, yoksa süreci sonlandırır.
- Kanarya çıkarma (canary extraction) (ekrandan, 01:55:00)
  - Çöken servis erişilebilirlik için otomatik yeniden başlatılır; `fork` ile yeniden başlatıldığında kanarya değişmez.
  - Saldırgan kanaryayı bayt bayt tahmin eder: 8 baytlık kanarya için en çok $256 \times 8 = 2048$ deneme yeter.
  - Aynı sorun `fork` ile yeniden başlatılan servislerde ASLR rastgeleliği için de geçerlidir.
- LibSafe: yeniden derleme gerektirmeyen savunma
  - Dinamik olarak yüklenen bir kütüphane, `strcpy` gibi güvensiz fonksiyonların güvenli sürümlerini sağlar (en son yüklenen kütüphanedeki fonksiyon geçerli olur).
  - Kopyalamadan önce çerçeve işaretçisi ile hedef arasındaki uzaklığın kaynak dizgenin uzunluğundan büyük olduğunu kontrol eder; değilse süreci sonlandırır.
- Gölge yığın (shadow stack) (ekrandan, 02:00:00)
  - `call` anında geri dönüş adresi gölge yığına da itilir; `ret` anında gölge yığının tepesi yığındaki dönüş adresiyle karşılaştırılır, eşit değilse çöker.
  - Bellek bozulması gölge yığını bozmamalıdır. Intel, gölge yığın sayfalarını özel bir öznitelikle işaretleyip yalnız `call`/`ret` sırasında yazılabilir kılar.
- Kontrol akışı bütünlüğü (CFI) (ekrandan, 02:05:00)
  - Amaç: kontrol akışının kodun akış grafiğine uymasını sağlamak (2005'te önerildi).
  - Derleme zamanında olası çağrı hedefleri listelenir; çalışma zamanında dolaylı çağrıdan (`s->hdlr(s, pkt)`) önce hedefin geçerliliği kontrol edilir.
  - Akademik çalışmalar: CCFIR (2013), kBouncer (2013), FECFI (2014), CSCFI (2015) ve bunlara karşı birçok saldırı.
  - Microsoft Control Flow Guard (CFG, Windows 10): dolaylı çağrılar, geçerli fonksiyon giriş noktalarının bit maskesiyle `_guard_check_icall` üzerinden kontrol edilir.
  - Intel CET: dolaylı `jmp`/`call` sonrası ilk komut "end branch" komutu olmalıdır; değilse hata üretilir. Derleyici bu komutu geçerli hedeflere kendisi ekler.
  - Sınır: CFG ve CET, saldırganın geçerli ama yanlış bir fonksiyona atlamasını engellemez; doğru bir akış grafiğini statik olarak çıkarmak zordur (ekrandan, 02:10:00).
  - Kriptografik CFI: bellekte yazılan her atlama adresine 64 bitlik bir MAC eklenir, her atlamadan önce doğrulanır; anahtar bellekte değil özel yazmaçlarda tutulur.

## Hocanın Özellikle Vurguladığı Kısımlar

- Veri ile kontrolü asla karıştırmamak
  - En temel tasarım ilkesi budur. Kontrol amaçlı sinyalleşme kullanıcı verisinden bağımsız ayrı bir kanaldan yapılmalıdır. Santral örneği (1971) ile buffer overflow aynı hatanın iki yüzüdür.
- Savunmaların ortak sonucu: ele geçirmeyi DoS'a dönüştürmek
  - Hem saldırı kodunu çalıştırmayıp hem hizmeti sürdüren bir çözüm yoktur. Tam ele geçirme yerine hizmet kesintisi kabul edilir.
- Tek hat değil, katmanlı savunma
  - "Hattı müdafaa yoktur, satıh müdafaası vardır": NX/DEP tek başına ROP'u durdurmasa da kullanılmaya devam eder; her katman saldırganın seçeneklerini daraltır.
- ROP'un DEP'i anlamsızlaştırması
  - Yığında tek bayt komut çalıştırılmadan, yalnız argüman ve geri dönüş adresiyle saldırı yapılır; üstelik NOP kızağı ve adres hizalaması derdi de ortadan kalkar.
- Canary + istisna işleyicisi gerilemesi
  - /GS'deki kanarya, istisna kontrolden önce tetiklendiği için SEH saldırısına karşı korumaz. /GS mutlaka SafeSEH veya SEHOP ile birlikte kullanılmalıdır.
- Fork ile yeniden başlatma tehlikesi
  - Kanarya ve ASLR rastgeleliği `fork` sonrası değişmez; bayt bayt çıkarma ile kanarya en çok 2048 denemede bulunur.
- Savunmalar sıfır risk değil, yönetilebilir risk sağlar
  - kBouncer'ı aşmak için son 16 dönüşü normal gösteren daha karmaşık saldırı gerekir; risk sıfırlanmaz ama kabul edilebilir sınıra iner.

## Kısa Tekrar Notları

- Temel hata: veri ve kontrolün aynı kanalda (in-band) taşınması.
- Üç savunma yolu: hataları düzeltmek, platform savunmaları, çalışma zamanı denetimi.
- DEP/NX: yığın ve heap çalıştırılamaz; NX (AMD64), XD (Intel), XN (ARM); PTE'de bir bit.
- ROP: kod enjekte etmeden libc fonksiyonlarına `ret` ile atlama; DEP'i aşar.
- Uzak kabuk zinciri: `dup2(s,0)`, `dup2(s,1)`, `execve("/bin/sh",0,0)`.
- ASLR: Windows 7'de 8 bit (256 seçenek), Windows 8'de 64 bit sistemlerde 24 bit.
- kBouncer: LBR ile son 16 `ret`'in bir `call`'u izlediğini çekirdeğe girmeden kontrol eder.
- StackGuard: kanarya; rastgele ve sonlandırıcı kanarya.
- ProPolice (`-fstack-protector`): diziler kanaryanın hemen altına, diğer yerel değişkenler ve işaretçi argüman kopyaları daha aşağıya.
- Microsoft /GS: cookie, yığın işaretçisiyle XOR; istisna işleyicilerini de korur.
- SEH saldırısı kanaryayı aşar; çözüm SafeSEH (güvenli işleyici tablosu) ve SEHOP (sahte kayıt).
- Kanarya çıkarma: fork ile yeniden başlatılan serviste $256 \times 8 = 2048$ deneme.
- LibSafe: yeniden derlemesiz, `strcpy` öncesi uzunluk kontrolü.
- Gölge yığın: dönüş adresinin korumalı kopyası.
- CFI / CFG / CET: dolaylı çağrı hedeflerini sınırlama; geçerli ama yanlış fonksiyona atlamayı engellemez.

## Detaylı Açıklamalar

- **Captain Crunch ve in-band sinyalleşme.** ABD'de uzun yıllar telefon hizmetini tek şirket (AT&T) veriyordu. Şehirlerarası aramada karşı santral, ödemenin yapılıp yapılmadığını insan kulağının duymadığı bir frekanstaki sinyalden anlıyordu. Bu sinyal konuşma hattının kendisinden gönderiliyordu. Düdüğü tasarlayan kişi frekansı çözüp aynı sesi üreten bir düdük yaptı: numara çevrildikten sonra ahizeye üflenince santral para atıldığını sanıp bağlantıya izin veriyordu. Hata, veri ile kontrolün aynı hatta taşınmasıdır. Hoca bunu buffer overflow'a bağladı: yığında geri dönüş adresi (kontrol bilgisi) ile argümanlar ve yerel değişkenler (veri) yan yanadır. Yerel tampon taşınca SFP ve geri dönüş adresi de ezilir ve akış saldırganın istediği yere gider. Slaytta aynı karışıklığın XSS'in de nedeni olduğu yazıyordu.
- **Neden tasarım değiştirilemiyor?** İki ayrı yığın işaretçisi (biri veri, biri dönüş adresleri için) bu saldırı türünü baştan ortadan kaldırırdı. Ancak bu yapı onlarca yıldır kullanılıyor, işlemci mimarisi de buna göre biçimlenmiş durumda. Milyarlarca cihazı bir gecede değiştirmek mümkün olmadığı için çözümler mevcut donanım ve yazılımla uyumlu olmak zorundadır.
- **Tip güvenli diller.** Java'da `boolean` bir değişkene yalnız `true`/`false` atanabilir. C'de ise 0 yanlış, sıfır dışındaki her değer doğrudur; ayrı bir Boolean tipi yoktur (C++'taki `bool` da aynı yaklaşıma dayanır). Tip güvenli dil ve uygun çalışma ortamı bu zafiyetleri azaltır. Ancak Java'nın kendisi güvenli olsa da JVM C/C++ ile yazılmıştır ve Java ile ilgili güvenlik açıklarının çoğu JVM tarafındadır. Go ve Rust da C/C++ kütüphaneleri üzerinde çalışır.
- **Yığın kod için tasarlanmadı.** Intel mimarisinde kod, veri, yığın ve ek segment ayrıdır. Dokümantasyona göre çalıştırılacak komutlar kod segmentinde, yığın ise dönüş adresi, parametre ve yerel değişkenler içindir. Buffer overflow'da ise kod yığında çalıştırılır. NX/XD/XN biti her sayfanın kod çalıştırıp çalıştıramayacağını belirler. İşletim sistemi desteği (Linux, OpenBSD, Windows XP SP2'de DEP) yetmez; derleyicinin de yığında çalışacak kod üretmemesi gerekir (Visual Studio'da NX uyumluluk bayrağı).
- **ROP adım adım.** Saldırgan yerel tamponu taşırarak SFP'yi, geri dönüş adresini ve argüman alanını ezer. Geri dönüş adresine libc içindeki `exec` fonksiyonunun adresini, argüman alanına da `"/bin/sh"` dizgesinin adresini (32 bit mimaride 4 bayt) koyar. Normalde argümanları çağıran yığına iter, dönüş adresini de `call` komutu otomatik iter. Burada fonksiyon `ret` ile "çağrılır". `exec` çağrılan taraftır: yalnız çağıranın yazmaçlarını saklar, argüman alanından işaretçiyi alıp gösterdiği programı yükler. Böylece yığında hiç komut çalıştırılmadan kabuk açılır. Uzaktan saldırıda saldırgan, kabuğun stdin (0) ve stdout (1) tanımlayıcılarını kendi bağlantısının soketine `dup2` ile bağlar. Üç fonksiyon arka arkaya "adres + argüman" çiftleriyle zincirlenir; her fonksiyonun `ret`'i zincirdeki bir sonraki adrese gider.
- **ASLR ayrıntıları.** Saldırganın işini kolaylaştıran şey, aynı çekirdek ve libc sürümünde fonksiyon adreslerinin her makinede aynı olmasıdır. ASLR bu adresleri makineden makineye (ve açılıştan açılışa) değiştirir. Windows 7'de 32 bitlik adres alanı nedeniyle yalnız 8 bit rastgeleleştirilir: 16 MB'lık bölgede 64K adımlarla $16\text{ MB} / 64\text{ KB} = 256$ konum. Windows 8 ile 64 bit sistemlerde 24 bit. Windows 7'de değer açılışta bir kez belirlenir ve yeniden başlatılana kadar sabit kalır; 256 olasılık bir sunucuda deneme ile aşılabilir. Doğrusu rastgeleleştirmeyi her süreç için ayrı yapmaktır. Kütüphane kayınca süreç bellek düzenindeki yığın, heap ve paylaşılan kütüphane adresleri de değişir.
- **kBouncer.** "Bouncer" kapıdaki fedai demektir; "k" çekirdekten gelir. ROP'ta fonksiyonlara `call` ile değil `ret` ile gidildiği için, `ret`'in döndüğü adresin hemen öncesinde bir `call` komutu yoktur. Intel'in dallanma tahmini için tuttuğu LBR kayıtları son 16 dallanmayı saklar. kBouncer sistem çağrısından önce bu kayıtları okuyup son 16 dönüşün normal olduğunu doğrular. Dispatcher'ın meşru `ret` kullanımı bilindiği için ayrı tutulur. Saldırgan son 16 dönüşü normal gösteren bir zincir kurabilir, ama bu saldırıyı çok zorlaştırır.
- **Kanarya.** Ad, maden ocaklarına zehirli gazı erken fark etmek için götürülen kanaryalardan gelir. Yığının bütününü kopyalayıp dönüşte karşılaştırmak performans açısından anlamsız olduğundan, yerel değişkenlerle kontrol bilgisi arasına tek bir değer konur. Yerel tampondan yukarı doğru bir taşma kanaryayı atlayamaz. Dönüşte yalnız bu tek değer kontrol edilir.
- **Microsoft /GS kodu.** Hocanın anlatımına göre fonksiyon girişinde yığında 8 baytlık yer açılır, `__security_cookie` değeri ESP ile XOR'lanıp bu alana yazılır. XOR mod 2 toplama olduğu için aynı değerle iki kez XOR orijinali verir: $c \oplus sp \oplus sp = c$. Çıkışta değer ESP ile yeniden XOR'lanıp `__security_check_cookie` çağrılır. Bozulmuşsa süreç sonlandırılır. <!-- BELİRSİZ: /GS derleyici çıktısının komutları (01:41-01:43) karede görülmedi; komutlar altyazıdan anlatıldı. -->
- **SEH saldırısı.** İstisna işleyicileri özelden genele giden bağlı bir listedir. İstisna oluşunca dispatcher listeyi uygun işleyiciyi bulana dek dolaşır, bulamazsa varsayılanı kullanır. Taşma `next` ve `handler` alanlarını ezer, sonra istisna tetiklenir. Kanarya kontrolü fonksiyon dönüşünde yapıldığı hâlde istisna fonksiyon çalışırken oluştuğu için kontrol saldırganın adresine geçer. Hoca bunu iyi özellikleri birleştirirken kötüye gitmek, yani gerileme olarak adlandırdı. SafeSEH ve SEHOP bu açığı kapatır. SafeSEH'in performans maliyeti, istisnaların yoğun kullanıldığı nesne yönelimli kodda yüksektir.
- **LibSafe.** Dinamik kütüphanelerde en son yüklenen kütüphanedeki fonksiyon geçerli olur. LibSafe, `strcpy` gibi fonksiyonların güvenli sürümlerini araya yerleştirir ve çerçeve işaretçisi ile hedef arasındaki uzaklık kaynak dizge uzunluğundan büyük değilse süreci durdurur. Uygulamanın yeniden derlenmesi gerekmez; yalnız str ailesi üzerinden yapılan saldırılara karşı korur.
- **CFG, CET ve kriptografik CFI.** CFG, "yoksul adamın CFI'ı" olarak bütün olası akışları değil yalnız dolaylı çağrıların hedefini kontrol eder: ESI'daki fonksiyon işaretçisi ECX'e kopyalanır, `_guard_check_icall` bit haritasında doğrulanır, ardından `call esi` yapılır (ekrandan, 02:10:00). CET'te dolaylı atlama sonrası ilk komut "end branch" olmalıdır. Ancak geçerli fonksiyon listesindeki yanlış bir fonksiyona atlama engellenmez: HandshakeHandler → LoginHandler → CheckCredentials → DataHandler akışında saldırgan LoginHandler yerine doğrudan DataHandler'ı çağırtarak kimlik doğrulamayı atlayabilir. Kriptografik CFI'da her atlama adresine bir MAC eklenir ve anahtar ayrıcalıklı yazmaçlarda tutulduğu için saldırgan DataHandler için geçerli bir MAC üretemez.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
