# Ders 2 Çalışma Özeti

## Genel Konular

- Kontrolü ele geçirme saldırıları (control hijacking attacks)
  - Saldırganın hedefi, bir web, e-posta ya da DNS sunucusu gibi hedef makinenin kontrolünü almaktır (ekrandan, 00:05:00).
  - Yöntem: hedefte çalışan bir uygulamanın kontrol akışını ele geçirip saldırganın istediği kodu (arbitrary code) çalıştırmak. Kod sıfırdan dosya sistemine yüklenip çalıştırılmaz; çalışmakta olan bir programın akışı değiştirilir.
  - Derste sırasıyla dört örnek ele alındı: buffer overflow, integer overflow, format string zafiyeti, use after free. Bu sıra hem kronolojik sırayı hem de artan zorluğu gösterir.
  - Buffer ve integer overflow neredeyse her zaman doğrudan saldırıya dönüşür. Format string ise bir "zafiyet"tir: saldırıya ya da hassas bilgi sızdırmaya yol açabilir.
- Buffer overflow'un tarihçesi ve önemi
  - C/C++ programlarında son derece yaygın bir hatadır. İşletim sistemleri ve çalışma zamanı kütüphaneleri (runtime library) neredeyse tamamen C/C++ ile yazıldığı için C/C++'tan kaçınmak çoğu zaman mümkün değildir.
  - İlk büyük istismar: 1988 Internet Worm, Unix'teki `fingerd` servisi (ekrandan, 00:10:00). Sondaki "d", sürekli arka planda çalışan servis (daemon) anlamına gelir.
  - NVD verisine göre yılda bildirilen buffer overflow zafiyeti sayısı 2015'te 1000'e yaklaşmıştır (ekrandan, 00:10:00). Her zafiyetli uygulamanın binlerce kopyası çalışabileceği için etki çok daha büyüktür.
- Saldırı için gereken bilgiler (ekrandan, 00:15:00)
  - C fonksiyonları, stack ve heap'in çalışma zamanındaki yapısı.
  - Sistem çağrılarının nasıl yapıldığı; özellikle kod çalıştırmayı sağlayan `exec()` çağrısı.
  - Hedefin işlemci mimarisi ve işletim sistemi: komut seti, stack frame yapısı (Unix ve Windows farkı), little endian ve big endian.
  - Derste kolaylık için 32 bit Linux üzerinden gidildi; örnekler 64 bit ve Windows'a da uygulanabilir.
- 32 bit Linux süreç bellek düzeni (ekrandan, 00:20:00)
  - `0` ile `0x08048000` arası kullanılmaz (işletim sistemine ayrılmış).
  - Program `0x08048000` adresinden yüklenir; üstünde runtime heap vardır ve yukarı doğru büyür.
  - Paylaşılan kütüphaneler (shared libraries, ör. `libc`) `0x40000000` adresinden başlar.
  - User stack `0xC0000000` adresinden aşağı doğru büyür; `%esp` stack'in tepesini gösterir.
  - Stack aşağı taşıp diğer bölgelere gelirse stack overflow, heap kendi sınırını aşarsa heap overflow oluşur.
- Stack frame yapısı (ekrandan, 00:30:00)
  - Yüksek adresten düşüğe: argümanlar, dönüş adresi (return address), stack frame pointer, exception handler'lar, yerel değişkenler, callee saved registers.
  - Stack frame pointer çağıran fonksiyonun frame'ini gösterir; çökme anında çağrı zincirinin (stack trace) çıkarılmasını sağlar.
  - Fonksiyondan çıkınca yerel değişkenlerin değerleri stack'te kalır ama onlara ulaşmak için başlangıç noktası kalmadığından erişilemez.
  - Çağrılan fonksiyon, dönüş değeri için kullanılan register (Intel'de `EAX`) dışındaki register'ların değerini korumalıdır.
- Temel stack tabanlı buffer overflow (ekrandan, 00:35:00 ve 00:40:00)
  - `func(char *str)` içinde `char buf[128]` tanımlanır ve `strcpy(buf, str)` yapılır. `strcpy` sınır kontrolü yapmaz, kaynakta `\0` görene kadar kopyalar.
  - `str` 136 byte olursa fazladan 8 byte önce stack frame pointer'ı, sonra dönüş adresini ezer.
  - Dönüş adresini değiştirmek, fonksiyonun dışarıdan gelen bir girdiyle saldırganın seçtiği adrese dönmesi demektir.
- Basic stack exploit (ekrandan, 00:45:00)
  - Girdi, dönüş adresinin üstüne bir "Program P" yerleştirecek ve dönüş adresini P'yi gösterecek şekilde hazırlanır. P: `exec("/bin/sh")` (Aleph One'ın shell kodu).
  - Shell başlatabilen saldırgan `/bin/sh -c <komut>` ile istediği komutu çalıştırabilir.
  - Saldırının etkisi, saldırılan programın yetkisiyle sınırlıdır. Bu yüzden root ya da Administrator yetkisiyle çalışan sistem uygulamaları tercih edilir.
  - NOP slide: hizalama sorunlarını aşmak ve saldırıyı farklı sistemlerde ilk denemede tutturmak için shell kodun önüne NOP komutları konur.
  - Zorluklar (ekrandan, 00:50:00): P içinde `\0` karakteri olmamalı; taşma, `func()` dönmeden programı çökertmemeli.
- Gerçek örnekler
  - Windows animated cursor (`LoadAniIcon`) zafiyeti: zararlı kod içeren animasyonlu imleç paketleri.
  - Symantec (2016): çalıştırılabilir dosya başlığını ayrıştıran kod çekirdekte çalışıyordu; buradaki taşma doğrudan çekirdek yetkisi verdi.
- Güvensiz libc fonksiyonları (ekrandan, 00:55:00)
  - `strcpy`, `strcat`, `gets`, `scanf` ve daha fazlası. `gets` için uzunluk sınırı hiç yoktur; güncel derleyiciler uyarı verir.
  - "Güvenli" sanılan `strncpy()` ve `strncat()` yanıltıcıdır; `strncpy()` dizgiyi `\0` ile sonlandırmadan bırakabilir.
  - Windows CRT: `strcpy_s(*dest, DestSize, *src)` doğru sonlandırmayı garanti eder.
- Diğer buffer overflow fırsatları (ekrandan, 01:00:00)
  - Exception handler: stack frame'deki handler adresinin ezilmesi.
  - Function pointer (ör. PHP 4.0.2, MS MediaPlayer Bitmaps): `buf[128]`'in hemen ardındaki function pointer taşmayla ezilir; heap'te de stack'te de olabilir.
  - Longjmp buffer (ör. Perl 5.003): `longjmp(pos)` için tutulan `pos`, yanındaki buffer taşınca ezilir.
- Heap overflow ve C++ vtable
  - C++'ta nesneler heap'te oluşturulur. Sanal metotlar için function pointer tablosu (vtable) kullanılır; nesne, verisinin yanında vtable'ı gösteren `vptr` taşır.
  - Heap'teki bir buffer vtable'ın önüne denk gelirse taşma vtable'ı ezer ve metot çağrısı saldırganın adresine gider.
- Tarayıcı heap'i üzerinden saldırı ve heap spraying (ekrandan, 01:05:00 ve 01:10:00)
  - Zararlı site JavaScript ile shell kodu heap'e yerleştirir ve bir heap overflow tetikler. Sorun: saldırgan shell kodun heap'te nereye konduğunu bilmez.
  - Çözüm heap spraying: heap, önünde uzun NOP slide bulunan çok sayıda shell kod kopyasıyla doldurulur. Function pointer heap'te neredeyse herhangi bir yere işaret etse de shell kod çalışır.
  - Önlemler: JavaScript dizgilerini ayrı bir heap'te tutmak; yazılamaz koruma sayfaları (guard pages) yerleştirmek.
- Buffer overflow bulma
  - Sunucu yerelde çalıştırılır, sonu `$$$$$` gibi bir işaretle biten farklı uzunlukta girdiler verilir. Program çökünce core dump'ta işaret aranır; bulunduğu stack frame'in fonksiyonu zafiyetli fonksiyondur.
- Diğer kontrol ele geçirme saldırıları
  - Double free: serbest bırakılmış bölgeyi tekrar `free` etmek; bazı heap yöneticileri bu durumda belleğe bilgi yazıyordu (ör. CVS).
  - Integer overflow: tam sayı, sınırını aşınca başa döner (ekrandan, 01:30:00 örneği). Uzunluk kontrolü toplama taşmasıyla atlatılabilir.
  - Format string: kullanıcı girdisinin doğrudan biçim dizgisi olarak verilmesi (ekrandan, 01:35:00).
  - Use after free: serbest bırakılmış bölgeyi kullanmaya devam etmek. Chrome 2015-2020 yüksek etkili zafiyetlerinde ilk sırada (ekrandan, 01:40:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Saldırının özü uygulamanın kontrol akışını değiştirmektir
  - Kod sıfırdan yüklenip çalıştırılmaz; çalışan bir sistem ya da kullanıcı uygulamasının akışı, içindeki zafiyet kullanılarak değiştirilir. Hoca bunun "kritik nokta" olduğunu, akıldan çıkarılmaması gerektiğini söyledi.
- Bilgi, tasarımın ayrıntısından gelir
  - 32 bit Linux'ta program, kütüphane ve stack başlangıç adresleri sabittir. Yalnız işletim sistemini bilmek, uzak sistem hakkında çok daha değerli bilgi verir.
  - Zor görünen saldırılar, karşıdaki tasarımın ayrıntısı öğrenilince kolaylaşır.
- Dönüş adresinin ezilmesi "felaket"tir
  - Uç kullanıcının verdiği girdi, onu işleyen fonksiyonun dönüş adresini değiştirebilmemelidir. Birkaç tasarım eksiği bir araya gelince bu mümkün olur.
- Başarısız buffer overflow da bir saldırıdır
  - Başarısız ya da önlemle kesilen bir taşma programı çökertir; kontrol ele geçirme saldırısı hizmet engellemeye (denial of service) dönüşür.
- `strcpy`, `strcat`, `strncpy`, `strncat` ya hiç kullanılmamalı ya da çok dikkatli kullanılmalıdır.
- Use after free hafife alınmamalıdır
  - "Use after free deyip geçmemek lazım"; beklenmedik yerden ciddi saldırılara yol açabilir.

## Kısa Tekrar Notları

- Control hijacking: uygulamanın akışını ele geçirip hedefte keyfi kod çalıştırmak.
- Sıra ve zorluk: buffer overflow < integer overflow < format string < use after free.
- 32 bit Linux: program `0x08048000`, paylaşılan kütüphaneler `0x40000000`, stack tepesi `0xC0000000`; stack aşağı, heap yukarı büyür.
- Stack frame (yüksekten düşüğe): argümanlar, dönüş adresi, frame pointer, exception handler, yerel değişkenler, callee saved registers.
- `char buf[128]` en fazla 127 karakter ve `\0` alır. 136 byte'lık girdi frame pointer'ı ve dönüş adresini ezer.
- Shell kod `\0` içermemeli; taşma fonksiyon dönmeden programı çökertmemeli.
- NOP (x86'da `0x90`) slide, atlama adresindeki belirsizliği tolere eder.
- `strncpy` dizgiyi sonlandırmayabilir; Windows'ta `strcpy_s` hedef boyutunu alır.
- Function pointer, longjmp buffer, exception handler ve C++ vtable da taşmayla ezilebilir.
- Heap spraying: heap'i NOP slide + shell kod kopyalarıyla doldurmak. Önlem: ayrı string heap'i, guard page.
- Integer overflow: `0x80 + 0xffffff80 = 0` (32 bit), uzunluk kontrolünü atlatır.
- Format string: `fprintf(stderr, user)` yanlış, `fprintf(stderr, "%s", user)` doğru. `%n` belleğe yazar.
- Use after free: Chrome 2015-2020 yüksek etkili zafiyetlerinin %36.1'i; %70'i bellek yönetimi hatası.

## Detaylı Açıklamalar

- **Neden C/C++?** Saldırıların büyük kısmı C/C++ programlarına yöneliktir. Bunun nedeni yalnız dilin kendisi değil, yüksek seviyeli kodun alt seviyeye çevrilme ve çalıştırılma biçimindeki tasarım kararlarıdır. Bu kararların birkaçı bir araya gelince saldırı çok kolaylaşır. Anlatılan mekanizmalar başka programlama ortamlarında da ortaya çıkabilir; ancak bütün işletim sistemleri ve runtime kütüphaneleri C/C++ ile yazıldığından bu dillerden kaçınmak çoğu zaman mümkün değildir.

- **Endianness.** Byte erişim sırası bütün işlemcilerde aynıdır, ama çok byte'lı tam sayılarda (ör. 16 bit) önce düşük mü yüksek anlamlı byte'ın mı geleceği işlemciye göre değişir. Little endian'da düşük adreste düşük anlamlı byte bulunur; bellekten okunan değer kâğıda yazılırken sıra ters çevrilmelidir. Big endian'da düşük adreste yüksek anlamlı byte bulunur ve okunduğu sırayla yazılabilir. Hoca, birinin insana, diğerinin makineye yakın olduğunu söyledi.

- **Bellek düzeninin saldırgana verdiği bilgi.** 32 bit Linux'ta her süreç sanal adres uzayında aynı düzeni kullanır: program her zaman `0x08048000`'den yüklenir, kütüphaneler `0x40000000`'den, stack `0xC0000000`'den başlar (ekrandan, 00:20:00). Stack aşağı, program ve heap yukarı doğru büyür; iki yön birbirine doğru ilerler. Heap, `malloc` ve `free` ile yönetilen dinamik bellek bölgesidir.
  - Ders sonrası not: Hoca bir yerde (00:24:48) paylaşılan kütüphanelerin başlangıcını da `0x08048000` olarak söyledi; slayta göre doğrusu `0x40000000`'dir (ekrandan, 00:20:00).

- **Stack frame ve buffer'ın yeri.** Örnekte tek argüman `str` (32 bit) vardır; altında dönüş adresi, onun altında stack frame pointer, en altta `buf[128]` bulunur (C kabul edildiği için exception handler göz ardı edildi). Stack satırı 4 byte olduğundan `buf` $128/4 = 32$ satır kaplar. Değişkenler pozitif yönde adreslendiği için `buf[0]` en düşük adreste, `buf[127]` frame pointer'ın hemen altındadır. Böylece `buf`'a yazılan veri yukarı, yani frame pointer ve dönüş adresine doğru ilerler.
  - Ders sonrası not: Hoca 00:37:02'de "128 bit'lik buff" ve "4 bit'lik satır" dedi; doğrusu 128 byte'lık buffer ve 4 byte'lık (32 bit) satırdır.

- **136 byte'lık girdi (ekrandan, 00:40:00).** `strcpy` sınır kontrolü yapmadan `str`'deki `\0`'a kadar kopyalar. Girdi 136 byte ise ilk 128 byte `buf`'ı doldurur, sonraki 4 byte stack frame pointer'ı, son 4 byte dönüş adresini ezer ($136 - 128 = 8$). Frame pointer'ın bozulması yalnız hata ayıklamayı zorlaştırır; dönüş adresinin bozulması ise fonksiyonun dönerken saldırganın belirlediği adrese gitmesi demektir.

  ```c
  void func(char *str) {
      char buf[128];
      strcpy(buf, str);
      do-something(buf);
  }
  ```

  (ekrandan, 00:35:00; slayttaki parça kod, derlenmedi)

- **Shell kod ve NOP slide.** Girdi, dönüş adresinden sonra da ezmeye devam ederek oraya bir program (shell kod) yerleştirir ve dönüş adresini bu programın başına ayarlar. `exec("/bin/sh")` yeni bir kabuk başlatır; `-c` ile komut verilirse (ör. `/bin/sh -c reboot`) her komut çalıştırılabilir. Hoca, bir satırlık bu kodu derleyip yalnız `exec` ile ilgili komutları alarak girdiye eklediğini anlattı. Adres hizalama koşullarını aşmak ve farklı sistemlerde ilk denemede tutturmak için shell kodun önüne tek byte'lık NOP komutları konur. NOP, işlemcinin yalnız program sayacını artırdığı, durumunu değiştirmediği komuttur. `EAX`'in artırılması gibi komutlar da aynı amaçla kullanılabilir; bu register zaten dönüş değeri için kullanıldığından değeri değişebilir.
  - Ders sonrası not: Hoca (00:49:14) `EAX`'in kendisiyle XOR'lanmasının da bir byte olduğunu söyledi. 32 bit x86'da `inc eax` 1 byte'tır (`0x40`), `xor eax, eax` ise 2 byte'tır (`31 C0`).
  - Bu stack ezme işlemine literatürde "stack smashing" de denir.

- **Güvensiz kütüphane fonksiyonları (ekrandan, 00:55:00).** `gets(char *s)` hedefin uzunluğunu hiç almaz; ne kadar yer ayrılırsa ayrılsın saldırgan bir byte fazlasını gönderebilir. `strncpy` ve `strncat` en fazla verilen sayıda byte kopyalar, ama libc'nin bazı sürümlerinde sonuna `\0` konmadığı durumlar oluşmuştur. Windows CRT'deki `strcpy_s(*dest, DestSize, *src)` hedef boyutunu alır ve doğru sonlandırmayı garanti eder.
  - Ders sonrası not: Hoca `strcpy_s`'nin `strncpy`'nin "birebir aynısı" olduğunu söyledi; slayta göre fark, `strcpy_s`'nin dizgiyi her zaman doğru sonlandırmasıdır (ekrandan, 00:55:00).

- **Function pointer ve longjmp.** Yerel bir buffer'ın hemen ardında function pointer varsa taşma önce onu ezer; saldırının tetiklenmesi için bu pointer'ı kullanan bir kod akışı gerekir. Derleyiciler `switch-case` yapılarını optimize ederken jump table ya da function pointer tablosu kullanabilir. Longjmp buffer'ında saklanan atlama adresi (`pos`) ezilirse `longjmp` çağrısı saldırganın adresine gider. <!-- BELİRSİZ: Hoca longjmp'ı Intel segmentli belleğinde adres uzayları arası geçiş olarak açıkladı; setjmp/longjmp'ın yaygın tanımı yerel olmayan atlamadır. -->

- **Heap spraying kodu (ekrandan, 01:10:00).**

  ```javascript
  var nop = unescape("%u9090%u9090")
  while (nop.length < 0x100000) nop += nop;

  var shellcode = unescape("%u4343%u4343%...");

  var x = new Array ()
  for (i=0; i<1000; i++) {
      x[i] = nop + shellcode;
  }
  ```

  `nop` dizgisi her adımda kendisiyle birleştirilerek üstel olarak büyür; 2 karakterden başlayıp 19 ikilemede $0x100000 = 1\,048\,576$ karaktere ulaşır (python ile doğrulandı). Ardından 1000 elemanlı dizinin her elemanı uzun bir NOP slide ve sonunda shell kod içerir. NOP slide'lar shell koda göre çok uzun olduğundan, vtable ya da function pointer püskürtülen alanda herhangi bir yere işaret etse büyük olasılıkla bir slide'a düşer ve shell koda kayar. Kullanıcı yalnız bilgisayarın bir an yavaşladığını fark eder.
  - Ders sonrası not: Hoca JavaScript'in "değiştirilmiş bir JVM" üzerinde çalıştığını söyledi; tarayıcılar JavaScript'i kendi motorlarında çalıştırır, bunlar JVM değildir. `0x90` x86'nın NOP komutudur.

- **Integer overflow örneği (ekrandan, 01:30:00).**

  ```c
  void func( char *buf1, *buf2,   unsigned int len1, len2) {
      char temp[256];
      if (len1 + len2 > 256)  {return -1}      // length check
      memcpy(temp,  buf1,  len1);              // cat buffers
      memcpy(temp+len1,  buf2,  len2);
      do-something(temp);                      // do stuff
  }
  ```

  `len1 = 0x80` (128), `len2 = 0xffffff80` olursa 32 bit işaretsiz toplam $0x80 + 0xffffff80 = 2^{32} \equiv 0$ olur. $0 > 256$ yanlış olduğundan kontrol geçilir. İlk `memcpy` 128 byte kopyalar, sorun çıkmaz; ikinci `memcpy` `temp+128`'den itibaren yaklaşık 4 GB kopyalamaya çalışır ve heap'i ezer. Toplamanın 0 verdiği ve kontrolün geçildiği küçük bir C programıyla doğrulandı (gcc -Wall; memcpy çağrılmadan).

- **Format string (ekrandan, 01:35:00).** `fprintf(stderr, user)` kullanıcı girdisini biçim dizgisi yapar. Girdi `"%s%s%s%s%s%s%s"` ise her `%s` stack'ten 4 byte'lık bir adres alıp oradan `\0`'a kadar basar. Sonuç büyük olasılıkla çökme (DoS); çökmezse erişilmemesi gereken bellek içeriği basılır (mahremiyet). `%n` o ana kadar basılan karakter sayısını verilen adrese yazar; ör. `printf("hello %n", &temp)` sonunda `temp = 6` olur (gcc ile çalıştırılarak doğrulandı). Doğru kullanım `fprintf(stderr, "%s", user)`'dır. `printf`, `fprintf`, `sprintf`, `vprintf`, `vfprintf`, `vsprintf` ve bunlar üzerine kurulu `syslog`, `err`, `warn` aynı riski taşır.

- **Use after free: IE11 örneği (ekrandan, 01:45:00).** Formda `c1` ve `c2` alanları vardır. `changer()` formun `innerHTML`'ini boşaltır ve çöp toplamayı çağırır; `c1`'in `onpropertychange` olayına `changer` bağlanır ve form sıfırlanır. Form sıfırlanırken `c1`'in reset'i `changer`'ı çağırır, bu da `c2`'yi serbest bırakır. Ardından serbest bırakılmış `c2`'nin reset'i çağrılır. Saldırgan bu arada vtable ile aynı boyda bir string ayırıp boşalan yere yerleştirirse `c2`'nin reset çağrısı shell koda gider.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
