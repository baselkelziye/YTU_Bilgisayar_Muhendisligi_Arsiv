# Ders 16 Çalışma Özeti

## Genel Konular

- Yüksek seviyeli dillerle assembly'nin birlikte kullanımı
  - C, Pascal, Java, Python gibi yüksek seviyeli dillerle assembly birlikte kullanılabilir. Derste yalnız C üzerinden örnek verildi.
  - Üç yol gösterildi: (1) Linux'ta C'den NASM ile yazılmış harici yordamı çağırmak, (2) Windows'ta Visual Studio'da C kodundan MASM ile yazılmış harici yordamı çağırmak, (3) C kodunun içine satır içi (inline) assembly yazmak.
  - Her üç örnekte 32 bitlik mimariyle çalışıldı: yazmaçların 32 bitlik sürümleri başlarına `E` getirilerek kullanılır (`EAX`, `EBP`, `ECX`, `ESI`...). Yığına atılan her eleman 4 byte'tır; yığın göreli konumları $+2$ yerine $+4$ ile sayılır.
- Örnek 1: Linux'ta C + NASM, dizi elemanlarının toplamı (ekrandan, 00:15:00, 00:20:00, 00:30:00, 00:35:00)
  - C tarafı kullanıcıdan `n` okur, `dizi[i] = i + 1` ile 1'den n'e kadar sayıları diziye koyar, `top = Topla(dizi, n);` ile assembly yordamını çağırır ve `Toplam: %d` yazar.
  - Yordam başka bir dosyada olduğu için C'de prototip `extern int Topla(int *, int);` biçiminde yazılır.
  - NASM dosyasında kesimlere `section` denir: `section .data` veri kesimi, `section .text` kod kesimidir (yığın için `section .stack` de kullanılabilir). `.text`'e kadar olan her şey veri kesimidir.
  - MASM'deki `PUBLIC` yerine NASM'de `global Topla` yazılır. Yordam `isim PROC NEAR` yerine yalnız `Topla:` etiketiyle başlar.
  - Yordam gövdesi: `PUSH EBP` / `PUSH ECX` / `PUSH ESI` / `MOV EBP, ESP` / `MOV ECX, [EBP+20]` / `MOV ESI, [EBP+16]` / `XOR EAX, EAX` / `L1: ADD EAX, [ESI]` / `ADD ESI, 4` / `LOOP L1` / `POP ESI` / `POP ECX` / `POP EBP` / `RET` (ekrandan, 00:35:00).
  - Derleme: `nasm -f elf32 -o ornek.o ornek.asm`, ardından `gcc -m32 -o asp ornek.o ornek.c`, çalıştırma `./asp`. <!-- BELİRSİZ: terminal komutları karede görünmedi; altyazıdan ("NAS-F1132", "-o", "32 bitlik çalışmaya zorlayacak") kuruldu, dosya adları ve bayrak yazımı tam doğrulanamadı. -->
  - `n = 10` için sonuç 55 çıktı; hoca 5, 7, 100, 99 değerlerini de denedi (sonuçları büyük olasılıkla 15, 28, 5050, 4950; python ve C karşılığıyla hesaplandı, ekranda görülmedi).
- C'nin yığın üzerinden parametre aktarması
  - C, parametreleri prototipte **sağdan sola** yığına atar: önce `n`, sonra `dizi`nin adresi. Ardından NEAR çağrı gibi dönüş ofseti atılır.
  - Yordam içinde `EBP`, `ECX`, `ESI` atıldıktan sonra `MOV EBP, ESP` ile: `[EBP+0]` ESI, `+4` ECX, `+8` EBP, `+12` dönüş ofseti, `+16` dizinin adresi, `+20` n olur.
  - Sonuç `EAX` (akümülatör) üzerinden döndürülür. C'de fonksiyonun tek bir değer döndürebilmesinin nedeni budur; birden fazla değer gerekiyorsa bir dizinin/yapının adresi döndürülür. 32 bitlik mimaride her şeyin adresi 32 bittir.
  - Yığına C'nin attığı parametreleri C kendisi temizler; yordamda `RET 8` gibi bir şey yazılmaz, yazılırsa sorun çıkar.
- Linux'ta çalıştırılabilir dosya
  - Linux'ta bir dosyanın çalıştırılabilir olması uzantısına değil, dosyanın "çalıştırılabilir" izin bitine bağlıdır. Bit temizlenince dosya çalıştırılamaz, set edilince çalıştırılır. Çalıştırılabilir dosya `./dosya_adi` ile çalıştırılır.
- Örnek 2: Windows'ta Visual Studio + MASM, büyükten küçüğe Selection Sort ve süre karşılaştırması (ekrandan, 01:05:00, 01:10:00, 01:15:00, 01:20:00)
  - Boş proje içinde `.cpp` dosyası açıldı ama içine C kodu yazıldı. `const int n` boyutlu dizi 1'den n'e sıralı doldurulur (en kötü durum), önce C fonksiyonu `SelSortC`, sonra assembly yordamı `SelSortASM` ile büyükten küçüğe sıralanır.
  - Süre `clock()` ile ölçülür: `sure = (double)(bit - bas) / CLOCKS_PER_SEC;` ve `printf("Toplam sure: %.2f\n", sure);`.
  - Assembly yordamı ayrı bir `.asm` kaynak dosyasında yazılır: `.586`, `.model flat` ile 32 bitlik korumalı kip ve düz bellek modeli belirtilir; `.stack`, `.data`, `.code` ile kesimler tanımlanır; yordam alışılmış `isim PROC NEAR` ... `RET` ... `isim ENDP` ve en sonda `END` ile yazılır.
  - C'den çağrılan harici yordam da C fonksiyonu da kesim içi (NEAR) dallanmayla çağrılır.
  - `.cpp` dosyasında prototip `extern "C"` ile bildirilir (altyazıdan; karede görünmedi).
  - `.asm` dosyasına sağ tık → Özellikler → Öğe türü: Özel Derleme Aracı (Custom Build Tool) seçilir; komut satırına MASM (`ml`) derleme komutu, çıktıya `%(Filename).obj` yazılır. <!-- BELİRSİZ: komut satırının tam metni karede görünmedi. -->
  - SelSortASM'de 7 yazmaç (görünen kısmı `EDI, ESI, EAX, EBX, EDX`) yığına atıldıktan sonra `MOV EBP, ESP`; dizinin adresi `MOV EDI, [EBP+32]`, eleman sayısı `MOV ECX, [EBP+36]` ile alınır (8. ve 9. eleman) (ekrandan, 01:15:00).
  - 100.000 eleman için C sürümü 12,31 s, assembly sürümü 3,44 s sürdü: yaklaşık 3,5 kat hızlanma ($12{,}31/3{,}44 \approx 3{,}58$).
- Ayrıştırılmış kod (disassembly) ile adım adım izleme (ekrandan, 01:20:00, 01:25:00)
  - Hata Ayıkla → Pencereler → Ayrıştırılmış Kod ile C kodunun assembly karşılığı görülür; Yazmaçlar penceresinde değişen yazmaçlar kırmızıyla gösterilir; F11 ile adım adım ilerlenir.
  - Çağrı öncesi `push 186A0h` (n = 100000), `lea eax,[dizi]` / `push eax`, `call _SelSortASM`, dönüşte `add esp,8`: C, attığı iki 4 byte'lık parametreyi yığından kendisi temizler.
  - C fonksiyonunun derlenmiş hâlinde de aynı kalıp görülür (önce `push ebp`, sonra `mov ebp, esp`), ama derleyicinin hata ayıklama için eklediği kodlar yüzünden elle yazılan assembly'den uzundur.
- Örnek 3: satır içi assembly ile bit aynalama (ekrandan, 01:30:00, 01:35:00, 01:40:00)
  - Aynalama: bir sayının ikili gösteriminde bit sırasını ters çevirmek. Örnek: $0D515_h = 1101010100010101_2 \rightarrow 1010100010101011_2 = 0A8AB_h$.
  - Assembly'de üç satırla yapılır: `SHR EAX, 1` (en düşük bit CF'ye düşer), `RCL EBX, 1` (CF, EBX'in sağından içeri girer), `LOOP L1`. 32 bit için 32 kez döner.
  - C kodunun içinde `__asm { ... }` bloğu açılarak C değişkenleri (`n`, `dizi`) assembly'de doğrudan okunup yazılabilir; değişkenlerin global olması gerekmez.
  - 1..10 dizisinin aynalanmış hâlleri: 1 → `80000000`, 2 → `40000000`, 3 → `C0000000` ... (python ve C ile doğrulandı).
- `MOV AX, 0ABCDh` sorusu
  - Yüksek anlamlı byte `AB` AH'ye, düşük anlamlı byte `CD` AL'ye girer. Makine kodunda ise anlık değer little endian sırayla (`B8 CD AB`) yazıldığı için ters görünebilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Parametreler sağdan sola yığına atılır
  - Hoca önce `n`'yi `[EBP+16]`, diziyi `[EBP+20]`'den aldı ve program segmentation fault verdi. Sağdan sola kuralı hatırlanınca yerleri değiştirildi (`n` → `+20`, dizi → `+16`) ve program doğru çalıştı. Göreli konumlar bu sıraya göre hesaplanmalıdır.
- Sonuç EAX'te döner
  - Yordamdan dönmeden önce sonucun `EAX`'te olduğundan emin olunmalıdır.
- Yığını C temizler
  - C, kendi attığı parametreleri çağrıdan sonra `add esp, 8` ile temizler; assembly yordamında `RET 8` yazmak hataya yol açar. Her dil bunu yapmayabilir; kullanılan dilin kuralı bilinmelidir.
- Boyuta göre artış
  - `int` bu mimaride 4 byte olduğu için `ADD ESI, 4` yazılır; `short` olsaydı 2, `char` olsaydı 1 eklenirdi. Boyut `sizeof` ile öğrenilebilir.
- Hız karşılaştırması oransaldır
  - Mutlak süreler bilgisayara göre değişir; önemli olan C ile assembly süreleri arasındaki orandır. Gerçek zamanlı projelerde bu hız farkı önemlidir.
- Bütün programlar çalışmadan önce assembly'ye (makine koduna) dönüşür
  - Bu yüzden arka tarafta assembly'nin nasıl çalıştığını bilmek, üst seviyede daha iyi kod yazmayı sağlar.

## Kısa Tekrar Notları

- NASM: `section .data`, `section .text`, `global isim`, `isim:` ... `RET`.
- MASM (VS): `.586`, `.model flat`, `.stack`, `.data`, `.code`, `isim PROC NEAR` ... `RET` ... `isim ENDP`, `END`.
- C prototipi: `extern int Topla(int *, int);` (C++ dosyasında `extern "C"`).
- Parametreler sağdan sola; dönüş adresi 4 byte; 3 PUSH sonrası ilk parametre `[EBP+16]`.
- Sonuç `EAX`; yığını çağıran C temizler (`add esp, 8`).
- Linux'ta çalıştırılabilirlik izin bitiyle belirlenir, uzantıyla değil.
- Inline: `__asm { ... }`; C değişkenleri doğrudan kullanılır.
- Aynalama: `SHR EAX,1` + `RCL EBX,1` + `LOOP`; `0D515h` → `0A8ABh`.

## Detaylı Açıklamalar

- C'den assembly yordamı çağırmanın mantığı
  - C kodunda bir fonksiyon çağrısı yazıldığında derleyici parametreleri sağdan sola yığına atar, `CALL` ile dallanır ve dönüşte sonucu `EAX`'ten alır. Assembly yordamı bu sözleşmeye uyduğu sürece C onu sıradan bir C fonksiyonu gibi kullanır. Yordamın adı C'deki adla birebir aynı olmalı ve dışarıya açılmalıdır (NASM'de `global`, MASM'de yordam adı C prototipiyle eşleşir). İki taraf ayrı ayrı nesne koduna derlenir ve bağlanır: Linux'ta `nasm` ile `.o`, sonra `gcc` ile C kodu ve bu `.o` birlikte tek çalıştırılabilir dosyaya; Visual Studio'da ise `.asm` dosyası özel derleme aracıyla `.obj`'ye çevrilir ve proje derlenirken bağlanır. Bu, MASM'de iki `.obj` dosyasını `LINK a.obj + b.obj` ile birleştirmenin aynısıdır.
- Topla yordamında yığın
  - Çağrı anında yığına sırasıyla `n`, dizinin adresi, dönüş ofseti atılır. Yordam `EBP`, `ECX`, `ESI`'yi saklar ve `MOV EBP, ESP` yapar. Her eleman 4 byte olduğundan `EBP`'den yukarı doğru $0, 4, 8, 12, 16, 20$: ESI, ECX, EBP, dönüş ofseti, dizi, n. `ESI` dizinin ilk elemanının adresini (sanki `LEA` ile yüklenmiş gibi), `ECX` eleman sayısını tutar. `EAX` `XOR` ile sıfırlanır; her turda `[ESI]` eklenir, `ESI` 4 artar, `LOOP` ECX'i azaltır. Sonunda saklanan yazmaçlar ters sırayla geri alınır ve `RET` ile dönülür; toplam `EAX`'tedir.
- Selection Sort örneğinde ölçüm
  - Dizi küçükten büyüğe sıralı verildi, büyükten küçüğe sıralatıldı: bu, sıralama algoritması için en kötü durumdur. 10 elemanda süre 0,00 s göründüğü için n = 100.000'e çıkıldı. Hoca örnek kodları paylaşacağını söyledi; derste assembly yordamının yalnız bir kısmı ekranda görüldü (Bölüm: SelSortASM).
- Satır içi assembly ile harici yordamın karşılaştırması
  - Inline assembly, küçük bit işlemleri gibi işlerde C değişkenlerini doğrudan okuyup sonucu yine C değişkenlerine yazmayı sağlar; tek dosyada çalışılır. Harici yordamın avantajı ise kodun karışık olmaması, yani yarısı C yarısı assembly bir dosya yerine C kodunun temiz kalmasıdır. GCC'de inline assembly sözdizimi farklıdır (örneğin yazmaçların önüne `%` gelir), ama yapılan iş aynıdır.
- Ders sonrası notlar
  - Hoca `SHR` ile sağa kaydırmada "en anlamlı bitin" carry bayrağına düştüğünü söyledi; doğrusu sağa kaydırmada **en düşük anlamlı** bit CF'ye düşer. Algoritma bu yüzden çalışır: en düşük bit EBX'e ilk girer ve sonunda en yüksek konuma ulaşır.
  - Hoca `%8x` biçiminin baştaki sıfırları da gösterdiğini söyledi; doğrusu `%8x` alanı 8 karaktere **boşlukla** doldurur, sıfırla doldurmak için `%08x` yazılır (gcc ile denendi).
  - Hoca aynalamayı big endian / little endian dönüşümüyle ilişkilendirdi. Endianness büyük olasılıkla byte sırasıdır (çok byte'lı bir değerin byte'larının bellekte sırası); bit aynalama ise seri iletimde önce en anlamlı bitin mi, en az anlamlı bitin mi gönderildiği (bit sırası) farkını gidermekte kullanılır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
