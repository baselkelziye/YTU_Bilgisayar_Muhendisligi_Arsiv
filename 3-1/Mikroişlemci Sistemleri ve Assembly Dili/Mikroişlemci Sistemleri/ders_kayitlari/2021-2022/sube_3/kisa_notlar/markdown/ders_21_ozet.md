# Ders 21 Çalışma Özeti

## Genel Konular

- 8254 Programlanabilir Aralık Zamanlayıcısı (Programmable Interval Timer, PIT) (ekrandan, 00:10:00)
  - Temel görevi yazılım kontrollü, kesin ve doğru zaman gecikmeleri üretmektir. Ayrıca olay sayıcı, gerçek zamanlı saat (real time clock), kare dalga üreteci, karmaşık dalga üreteci ve "one shot" (belirli bir süre sonra bir kez gerçekleşen) işlemler için kullanılır.
  - Zamanlayıcı ile sayıcı arasındaki fark, sayacın saat girişine neyin bağlandığıdır: sabit frekanslı bir kare dalga bağlanırsa devre zamanlayıcıdır; ayrık ve aperiyodik olayları algılayan bir sensör (konveyör bant üzerinden geçen ürünleri gören alıcı-verici ikilisi, adım sayan bir buton ya da ivme ölçer) bağlanırsa sayıcıdır.
  - PC'deki kullanımları: sistem saatinin üretilmesi, DRAM'lerin periyodik olarak yenilenmesi (refresh), hoparlörden uyarı sesleri (açılış kontrolündeki bip sesleri gibi) üretilmesi.
  - PWM işareti (periyodu sabit, birde kalma süresi ayarlanabilen kare dalga) 8254 ve yardımcı lojik devrelerle üretilebilir; uzaktan kumandalı model uçakların kanat kontrolü bu tür bir işaretle yapılır.
- 8254'ün genel özellikleri
  - Birbirinden bağımsız üç adet 16 bitlik sayıcı (Counter 0, 1, 2) vardır. Her biri diğerlerinden bağımsız olarak mod 0-mod 5 arasındaki altı moddan birinde programlanabilir.
  - Her sayıcı 8 MHz'e kadar saat girişini destekler; bu da $1/(8\times10^6)$ saniyelik çözünürlük demektir.
  - Sayıcılar aşağı sayıcıdır (down counter): ilk değer yüklenir, saat darbeleriyle azalır, sıfıra ulaşınca OUT ucunda moda göre bir değişiklik olur. Genel olarak her sayıcı bir frekans bölücü gibi çalışır.
- İç yapı ve uç tanımları (ekrandan, 00:15:00 ve 00:20:00)
  - Blok yapı: D0-D7 veri yolu tamponu (data bus buffer), okuma/yazma lojiği ($\overline{RD}$, $\overline{WR}$, A0, A1, $\overline{CS}$), kontrol sözcüğü yazmacı (control word register), iç yol ve her biri CLK, GATE ve OUT uçlarına sahip üç sayıcı.
  - 8 bitlik veri yolu: 16 bitlik veri yolu olan 8086'ya ek donanım olmadan bağlanmak için 8254 ardışık çift ya da ardışık tek adreslere yerleştirilir.
  - $\overline{RD}$ ve $\overline{WR}$ uçlarına 8086'nın aynı adlı uçları bağlanır. $\overline{CS}$ seçili değilken veri uçları yüksek empedansta kalır.
  - İki adres ucu (A1, A0) G/Ç uzayında 4 baytlık yer, yani dışarıdan erişilebilir 4 yazmaç demektir:

    | A1 | A0 | Seçim |
    |----|----|-------|
    | 0 | 0 | Counter 0 |
    | 0 | 1 | Counter 1 |
    | 1 | 0 | Counter 2 |
    | 1 | 1 | Kontrol yazmacı |

  - CLK: sayıcının saat girişi. GATE: dış kontrol ucu (saymayı durdurma ya da yeniden tetikleme). OUT: sayma bitince değişen çıkış; kesme isteği (INTR) için kullanılabilir. Bu derste OUT ucunun durumu yoklama (polling) mantığıyla, durum baytından okunarak izlenecektir.
- Kontrol sözcüğü (control word) biçimi (ekrandan, 00:25:00)
  - Yazma koşulu: A1A0 = 11, $\overline{CS}$ = 0, $\overline{RD}$ = 1, $\overline{WR}$ = 0.
  - Bitler: D7-D6 = SC1 SC0 (sayıcı seçimi), D5-D4 = RW1 RW0 (okuma/yazma biçimi), D3-D1 = M2 M1 M0 (mod), D0 = BCD.
  - SC: 00 Counter 0, 01 Counter 1, 10 Counter 2, 11 Read-Back komutu.
  - RW: 00 Counter Latch komutu, 01 yalnız düşük anlamlı bayt (LSB), 10 yalnız yüksek anlamlı bayt (MSB), 11 önce LSB sonra MSB.
  - Mod: 000 mod 0, 001 mod 1, X10 mod 2, X11 mod 3, 100 mod 4, 101 mod 5.
  - BCD: 0 ikili (binary) 16 bit sayıcı, 1 BCD sayıcı (4 onluk basamak).
- Sayıcıya ilk değer yükleme
  - Önce kontrol yazmacına sayıcı, bayt biçimi, mod ve sayma tipi yazılır; sonra sayıcının kendi adresine bir ya da iki yazmayla (RW ayarına göre) ilk değer gönderilir. Veri yolu 8 bit olduğu için 16 bitlik değer iki seferde gider.
- 8254'ün altı modu (ekrandan, 00:45:00, 00:50:00, 00:55:00, 01:10:00, 01:15:00)
  - Mod 0 (interrupt on terminal count): kontrol sözcüğü yazılınca OUT 0'a düşer; sayma her CLK düşen kenarında azalır; sayma 0 olunca OUT 1'e çıkar ve öyle kalır. GATE = 0 saymayı duraklatır, GATE = 1 olunca kaldığı yerden devam eder. Yalnız yazılımla (yeni kontrol ya da sayma değeriyle) yeniden başlatılır.
  - Mod 1: mod 0'ın donanımla (GATE ile) tetiklenen hali. OUT boşta 1'dedir; GATE'teki 0→1 geçişinden sonra OUT 0'a düşer, sayma bitince 1'e çıkar. Her yeni GATE yükselen kenarı son yüklenen değerle saymayı baştan başlatır; sayma bitmeden gelen tetikleme de saymayı yeniden başlatır.
  - Mod 2 (tekrarlı darbe üreteci): OUT 1'de bekler, sayma değerinin son adımında bir saat periyodu boyunca 0'a düşer, sonra değer otomatik yeniden yüklenir. GATE = 0 saymayı durdurur. Yeni sayma değeri mevcut periyot bitince etkili olur.
  - Mod 3 (kare dalga üreteci): %50 doluluk oranına (duty cycle) yakın periyodik kare dalga. Sayma değeri her düşen kenarda ikişer azalır; yarı periyot 1, yarı periyot 0. Tek sayma değerinde fazlalık 1 tarafına gider (doluluk oranı %50'den biraz büyük olur). GATE = 0 saymayı durdurur.
  - Mod 4: mod 2'nin tek seferlik hali; yazılımla başlatılır, sayma sonunda tek bir kısa darbe üretir.
  - Mod 5: mod 4'ün GATE ile tetiklenen hali; GATE'teki tetiklemeden sonra sayar ve tek bir darbe üretir.
- Counter Latch komutu, Read-Back komutu ve durum baytı (ekrandan, 01:25:00 ve 01:30:00)
  - İç yapıda 8086'dan gelen değerler önce 8 bitlik sayıcı yazmaçlarına (low, high), oradan 16 bitlik sayma elemanına (count element) aktarılır. Anlık sayma değeri isteğe bağlı olarak çıkış tutucularına (output latch) kopyalanır, sayıcı bu sırada saymaya devam eder.
  - Counter Latch: kontrol sözcüğünde sayıcı seçilip RW = 00 yazılır (diğer bitler önemsiz). O anki sayma değeri tutuculara alınır ve sayıcının kendi adresinden okunur.
  - Read-Back: kontrol sözcüğünde SC = 11. D5 = $\overline{COUNT}$, D4 = $\overline{STATUS}$ (ikisi de aktif 0), D3, D2, D1 sırasıyla Counter 2, 1, 0 seçimi. Birden fazla sayıcı için sayma ve durum aynı anda tutulabilir. Örnek: üç sayıcının hem durumunu hem sayma değerini tutmak için 11001110 = CEH yazılır.
  - Hem durum hem sayma tutulduysa sayıcı adresinden ilk okuma durum baytını, sonraki okumalar tutulan sayma değerini verir. Tutulup okunmamış bir değer varken aynı sayıcı için gelen yeni tutma komutu yok sayılır.
  - Durum baytı: D7 = OUT ucunun lojik değeri, D6 = NULL COUNT (1: sayma değeri henüz okunabilir değil, 0: okunabilir), D5-D0 = sayıcının programlandığı RW, mod ve BCD bitleri.

## Hocanın Özellikle Vurguladığı Kısımlar

- Zamanlayıcı ve sayıcı ayrımı
  - Aynı devre, CLK girişine sabit frekanslı saat bağlanırsa zamanlayıcı, aperiyodik olay sinyali bağlanırsa sayıcı olur. Hoca bu farkı dersin başında net olarak ortaya koymanın gerektiğini söyledi.
- İlk değer iki adımda gönderilir
  - Önce kontrol yazmacına ayar, sonra sayıcı adresine değer yazılır. Kontrol yazmacına yazılan sözcük değeri göndermez, yalnız nasıl gönderileceğini programlar. Hoca bunu "önemli bir nokta" olarak belirtti.
- Binary ve BCD modda en büyük sayma
  - 16 bit binary modda en büyük yazılabilen değer FFFFH (65535), sıfır da sayıldığında 65536 adım; BCD modda en büyük değer 9999, 10000 adım.
- Sayıcılar frekans bölücüdür
  - Çıkış frekansı = giriş frekansı / sayma değeri. Tersi: sayma değeri = giriş frekansı / çıkış frekansı. Periyot verilmişse önce frekansa çevrilir.
- Durum baytı nereden okunur
  - Durum baytı kontrol yazmacından değil, ilgili sayıcının kendi adresinden okunur; çünkü her sayıcının ayrı durum baytı vardır. Hoca en çok karışan noktanın bu olduğunu vurguladı.

## Kısa Tekrar Notları

- 8254: 3 bağımsız 16 bit aşağı sayıcı, 6 mod, 8 bit veri yolu, 4 adres (Counter 0/1/2, kontrol).
- Kontrol sözcüğü: SC1 SC0 | RW1 RW0 | M2 M1 M0 | BCD.
- RW = 00 Counter Latch; SC = 11 Read-Back.
- Mod 0: tek seferlik, OUT 0→1 sayma sonunda. Mod 1: mod 0 + GATE tetiklemesi.
- Mod 2: tekrarlı tek periyotluk darbe. Mod 3: tekrarlı kare dalga.
- Mod 4: tek seferlik darbe (yazılımla). Mod 5: tek seferlik darbe (GATE ile).
- Mod 0, 2, 3'te GATE = 0 saymayı durdurur; mod 1 ve 5'te GATE yükselen kenarı tetikler.
- $f_{out} = f_{clk}/N$; binary en çok 65536 adım, BCD en çok 10000 adım.
- Read-Back'te COUNT ve STATUS bitleri aktif 0; durum baytı sayıcı adresinden okunur, ilk okuma durum baytıdır.
- Durum baytı D7 = OUT, D6 = NULL COUNT.

## Detaylı Açıklamalar

- 8254 ayarlama örneği (ekrandan, 00:35:00 ve 00:40:00)
  - Soru: 98H adresinden itibaren ardışık çift adreslere yerleştirilmiş bir 8254'te Counter 0 mod 3'te CLK0'ı 4282 (BCD) değerine, Counter 2 binary sayma ve mod 3'te CLK2'yi C26AH değerine bölecek şekilde ayarlanacak; CLK0 = 1,2 MHz, CLK2 = 1,8 MHz ise çıkış frekansları sorulmaktadır.
  - Adresler: Counter 0 = 98H, Counter 1 = 9AH, Counter 2 = 9CH, kontrol yazmacı = 9EH.
  - Counter 0: SC = 00, değer 8 bite sığmadığı için RW = 11, mod 3 = 011, BCD = 1 → 0011 0111 = 37H. Değer BCD olduğundan 4282, onaltılık gibi 4282H olarak yazılır: önce LSB 82H, sonra MSB 42H gönderilir.
  - Counter 2: SC = 10, RW = 11, mod 3 = 011, binary = 0 → 1011 0110 = B6H. C26AH = 49770; önce 6AH, sonra C2H gönderilir.
  - Slayttaki kod (ekrandan, 00:40:00):

    ```text
    a) MOV AL, 37H          b) MOV AL, 0B6H
       OUT 9EH, AL             OUT 9EH, AL
       MOV AX, 4282H           MOV AX, 0C26AH
       OUT 98H, AL             OUT 9CH, AL
       MOV AL, AH              MOV AL, AH
       OUT 98H, AL             OUT 9CH, AL
    ```

  - Çıkış frekansları: OUT0 = 1,2 MHz / 4282 ≈ 280 Hz; OUT2 = 1,8 MHz / 49770 ≈ 36 Hz (python ile doğrulandı: 280,24 Hz ve 36,17 Hz).
  - Ders sonrası not: Slaytta Counter 0 için "binary sayma" yazıyor, ancak değer 4282 (BCD) olarak verilmiş ve hoca da kontrol sözcüğünü BCD = 1 ile (37H) kurdu; çözüm BCD sayma üzerinedir. Slayttaki soru "OUT1 ve OUT2" diye soruyor, ama ayarlanan sayıcılar 0 ve 2 olduğu için hesaplanan OUT0 ve OUT2'dir.
- Mod 2 örneği
  - 2 MHz saatle Counter 0'dan 50 µs'de bir darbe isteniyor. Çıkış frekansı $1/(50\times10^{-6}) = 20$ kHz; sayma değeri $2\times10^6 / 20\times10^3 = 100 = 64H$. 8 bite sığdığı için yalnız LSB yeterli: kontrol sözcüğü 00 01 010 0 = 14H; ardından Counter 0 adresine 64H yazılır.
- Mod 3 örneği
  - 2 MHz saatle Counter 1'den 1 kHz kare dalga isteniyor: sayma değeri $2\times10^6 / 10^3 = 2000$. Değer hem BCD hem binary sınıra sığar; hoca çeşitlilik için BCD seçti. Kontrol sözcüğü 01 11 011 1 = 77H; ardından Counter 1 adresine önce LSB 00H, sonra MSB 20H yazılır. Sayıcı 2000 (BCD) değerinden geriye sayar; sürenin yarısında OUT 1, yarısında 0'dır.
- Zamanlama diyagramlarındaki kontrol sözcükleri (ekrandan, 00:50:00, 00:55:00, 01:10:00)
  - CW = 10H: Counter 0, yalnız LSB, mod 0, binary. CW = 12H: mod 1. CW = 14H: mod 2. CW = 16H: mod 3.
  - Mod 0 diyagramında LSB = 3 yazıldıktan sonra sayma 3, 2, 1, 0 diye ilerler; 0'da OUT 1'e çıkar, sayıcı FFFF'e dönerek saymayı sürdürür.
  - Ders sonrası not: Hoca mod 0'da sayma sırasında yazılan yeni değerin önceki sayma bittikten sonra etkili olduğunu söyledi. Slayttaki diyagramda (LSB = 2 ikinci yazması) sayma 3, 2, 1'den sonra 2, 1, 0 diye devam ediyor; yani mod 0'da yeni değer bir sonraki saat darbesinde yüklenir ve sayma yeni değerden sürer. Önceki periyodun bitmesini bekleyen davranış mod 1 ve mod 2 içindir.
  - Mod 2 diyagramında (CW = 14H, LSB = 3) sayma 3, 2, 1, 3, 2, 1, 3 diye tekrarlanır; OUT, 1 değerinde bir saat periyodu boyunca 0'dır. Mod 3 diyagramında (CW = 16H, LSB = 4) sayma 4, 2, 4, 2 diye ikişer azalır; OUT her yeniden yüklemede seviye değiştirir.
- Read-Back örnek dizisi (ekrandan, 01:25:00)
  - Sırasıyla 11000010 (Counter 0 sayma + durum tutuldu), 11100100 (Counter 1 durum tutuldu), 11101100 (Counter 2 durum tutuldu, Counter 1 için yok sayıldı; çünkü önceki okunmadı), 11011000 (Counter 2 sayma tutuldu), 11000100 (Counter 1 sayma tutuldu, durum tutulmadı), 11100010 (komut yok sayıldı; durum zaten tutulmuş).
  - Ders sonrası not: Son satırda D1 = 1 olduğu için komut Counter 0'ı seçer; slayttaki açıklamada "Counter 1" yazıyor. Bit düzenine göre doğrusu büyük olasılıkla Counter 0'dır (Counter 0'ın durumu ilk komutta tutulmuş ve okunmamıştır).
- Ders sonrası notlar (hoca dil sürçmeleri)
  - Hoca örnekte adresleri sayarken bir yerde "98H'de Counter 1, 9AH'da Counter 2, 9CH'da Counter 3" dedi; doğrusu 98H Counter 0, 9AH Counter 1, 9CH Counter 2'dir (8254'te Counter 3 yoktur). Hoca ilerleyen kısımda 9CH'yi doğru biçimde Counter 2 olarak kullandı.
  - En büyük sayma için hoca FFFFH yazılıp sıfır da sayılınca 65536 adım elde edildiğini söyledi. 8254'te FFFFH yazılırsa sayıcı 65535 saat darbesi sayar; 65536 adımlık en büyük sayma, ilk değer olarak 0000H yazılarak elde edilir (BCD modda 0000 yazılması 10000 adım verir) (büyük olasılıkla, veri sayfası bilgisi).
  - Hoca mod 5'te OUT'un "bir sayma süresi boyunca" 0'da kaldığını söyledi; mod 4 ve mod 5'te OUT sayma sonunda yalnız bir saat periyodu boyunca 0'a düşer.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
