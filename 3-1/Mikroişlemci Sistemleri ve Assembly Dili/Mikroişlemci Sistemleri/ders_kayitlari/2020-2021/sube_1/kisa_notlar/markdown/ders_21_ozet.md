# Ders 21 Çalışma Özeti

## Genel Konular

- 8254 mod 3 üzerine bir soru-cevap
  - Mod 3'te yeni bir mod yazılmadıkça kare dalga periyodik olarak üretilmeye devam eder; sayma değeri değişirse yalnız frekans değişir.
  - Sayıcı, yüklenen değeri CLK ucundaki saatin her darbesinde bir azaltır. 2 MHz saatte bu, 0,5 µs'de bir azaltma demektir. Mod 3'te çıkış sayma süresinin yarısında 1, yarısında 0 kalır.
  - Başka bir bakışla sayma değeri CLK frekansını böler: 2 MHz için sayma değeri 1000 ise çıkış 2 kHz olur.
- DAC0830 tekrarı
  - 8 bitlik DAC; kara kutu olarak 8 veri ucu, $\overline{CS}$, $\overline{WR}$ ve analog çıkış ucu vardır. Adres ucu yoktur, G/Ç uzayında $2^0=1$ bayt yer kaplar. (ekrandan, 00:10:00)
  - Zamanlama: $\overline{CS}$ aktifken veri uçlarına değer konur, $\overline{WR}$ darbesinden belli bir süre ($t_S$) sonra çıkış ±½ LSB içinde oturur. (ekrandan, 00:10:00)
  - Tek bir `OUT DX, AL` komutu hem $\overline{CS}$ (adres çözümleme üzerinden), hem $\overline{WR}$, hem de veri yolundaki değeri sağlar.
  - Örnek kod (1000H adresi): `MOV DX,1000H`, `MOV AL,00H`, `TEKRAR: OUT DX,AL`, `CALL DELAY`, `INC AL`, `JMP TEKRAR`. AL 00H'den FFH'ye artıp tekrar 00H'ye döndüğü için çıkış testere dişi dalgadır; basamak genişliği DELAY süresidir. (ekrandan, 00:15:00)
  - 00H → 0 V, FFH → 5 V. 8 bitlik DAC'de adım 5 V/256, 10 bitlik DAC'de 5 V/1024'tür.
  - Başka dalga şekilleri de istenebilir: üçgen dalga (adım adım artıp adım adım azalma) ve sinüzoidal dalga.
- Paralel ADC
  - Bütün bitler tek seferde hesaplandığı için hızlıdır. (ekrandan, 00:20:00)
  - $V_{ref}=7$ V, yedi eşit R direnci: $I=7V/7R$, en alttaki düğüm $V_7=I\cdot R=1$ V; düğümler sırayla 1, 2, …, 6 V, en üst karşılaştırıcı 7 V'a bağlıdır. (ekrandan, 00:20:00)
  - 3 bitlik çıkış için $2^3=8$ seviye gerekir: 7 karşılaştırıcı eşiği ve 0 değeri.
  - Karşılaştırıcı: $V_+>V_-$ ise çıkış 1, $V_-\ge V_+$ ise 0.
  - 8'den 3'e öncelikli kodlayıcı (priority encoder): en anlamlı girişten başlayarak 1 gördüğü ilk girişin numarasını ikili olarak verir.
  - Örnekler: $V_{in}=8$ V → I7 = 1 → 111. $V_{in}=3$ V → yalnız 1 V ve 2 V eşikli karşılaştırıcılar 1 verir, ilk 1 I2'de → 010.
- Rampa (ramp) dönüştürücü
  - Yapı: sayıcı (CTR), sayıcı çıkışını analoga çeviren iç DAC, karşılaştırıcı ve kaydırmalı yazmaç (SRG). (ekrandan, 00:25:00)
  - Sayıcı 00H'den başlar, her saat darbesinde artar; DAC çıkışı 0 V'tan yükselir. DAC çıkışı $V_{in}$'i (örnekte 2,5 V) geçince karşılaştırıcı çıkışı 0 olur.
  - Bu anda sayıcının değeri SRG'ye yüklenir (örnekte yaklaşık 7FH-80H) ve aktif sıfır $\overline{Load}$ ile sayıcı bir sonraki saat kenarında yeniden 0 yüklenir.
  - Sakıncası: dönüşüm, DAC çıkışının 0'dan giriş gerilimine ulaşmasını bekler; zaman alır.
- ADC0804
  - Adres ucu yoktur, 1 bayt yer kaplar. $\overline{CS}$, $\overline{RD}$, $\overline{WR}$, $\overline{INTR}$, VIN+ (potansiyometreden), DB0-DB7 uçları kullanılır; saat kara kutunun içinde kabul edilir. (ekrandan, 00:30:00)
  - Dönüşüm $\overline{CS}$ ile birlikte bir $\overline{WR}$ (yani `OUT`) ile başlar; gönderilen değerin önemi yoktur.
  - Dönüşüm sürerken $\overline{INTR}$ 1'dedir, bitince 0'a iner; o zaman `IN` ile ($\overline{CS}$ + $\overline{RD}$) sonuç okunur. (ekrandan, 00:35:00)
  - Kesmeler henüz görülmediği için $\overline{INTR}$ ucu bir 74125 üç durumlu tamponla ikinci, 1 bitlik bir G/Ç cihazı yapılır; tamponun izin ucu bu cihazın $\overline{CS}$'idir, çıkışı AD7'ye bağlanır. (ekrandan, 00:30:00)
- ADC0804 örneği (ADC 200H, $\overline{INTR}$ cihazı 400H)
  - `TEKRAR: MOV DX,0200H`, `MOV AL,00H`, `OUT DX,AL`, `MOV DX,0400H`, `INTR_KONTROL: IN AL,DX`, `TEST AL,80H`, `JNZ INTR_KONTROL`, `MOV DX,0200H`, `IN AL,DX`, `CALL DELAY`, `JMP TEKRAR`. (ekrandan, 00:40:00) <!-- BELİRSİZ: kod, PowerPoint küçük resminden (17. slayt) okundu; altyazıdaki anlatımla uyumlu. -->
  - Adres 8 bite sığmadığı için DX kullanılır. `TEST AL,80H` sonucu 0 olunca MSB, yani $\overline{INTR}$, 0'a inmiştir.
- Proteus DAC örneği
  - DAC0830 1000H'de, VREF'e −5,1 V bağlı, çıkış opamp üzerinden osiloskopa verilir. (ekrandan, 00:50:00)
  - DELAY: `PUSH CX`, `MOV CX,00FFH`, `L1: LOOP L1`, `POP CX`, `RET`. CX, çağıran programın değeri bozulmasın diye yığına atılır. (ekrandan, 00:45:00)
  - Genlik: `INC AL` sonrasına `CMP AL,7FH`, `JBE DEVAM`, `XOR AL,AL` eklenince AL 00H-7FH arasında döner, tepe gerilimi yarıya iner (0-5 V yerine yaklaşık 0-2,5 V).
  - Frekans: ilk hâlde periyot yaklaşık 400 ms ölçüldü. DELAY'de CX 00FFH yerine 01FFH yapılınca periyot yaklaşık 800 ms oldu; periyot gecikmeyle doğrusal artar.
  - Yazılım gecikmesi işlemci saatine bağlıdır; bekleme 8254 gibi sabit frekanslı bir zamanlayıcıyla yapılsaydı saat frekansından bağımsız olurdu.
- Proteus ADC örneği
  - Lojik analizör $\overline{INTR}$'nin düşen kenarıyla tetiklenince veri uçlarında anlamlı sonuç görülür: potansiyometre %100'de FFH, %50'de 80H. Tetik tamponun seçim ucundan alınırsa yoklama sırasındaki ara değerler de yakalanır.
  - Adres çözümleme: 74154'ün A, B, C, D girişleri A9, A10, A11, A12'ye bağlı. E1 için A13-A15 0 (7427 NOR + NOT), E2 için A0 ile M/$\overline{IO}$ 0 (OR) olmalı. IO1 (DCBA = 0001) A9 = 1 → 200H; IO2 (DCBA = 0010) A10 = 1 → 400H. (ekrandan, 01:00:00)
  - Karma örnek fikri: iki işaretin üst üste bindiği bir analog işaret ADC ile okunur, yüksek frekanslı bileşen sayısal olarak süzülür, sonuç DAC ile dışarı verilir.
- Veri aktarım yöntemleri
  - Yoklama (polling): durum biti sürekli okunup maskelenir; işlemciyi bloklar. 8255 el sıkışma, 8251 hazır bitleri, 8254 OUT ucu ve ADC $\overline{INTR}$ örnekleri hep yoklamaydı.
  - Kesme tabanlı: cihaz programlandıktan sonra koşul oluşunca işlemci kesme isteği ucundan uyarılır; işlemci arada başka işle uğraşabilir.
  - DMA: işlemci devreden çekilir, DMA denetleyicisi iki cihaz (G/Ç-G/Ç ya da G/Ç-bellek) arasında aktarımı doğrudan yapar.
  - Benzetme: su kesikken ders çalışan öğrenci kovayı ara ara kontrol ederse yoklama; kova dolunca hoparlör çalarsa kesme. (ekrandan, 01:30:00)
- Kesme kaynakları (ekrandan, 01:35:00)
  - Yazılımsal: `INT n` (n = 00H-FFH, 256 kesme tipi), `INTO` (taşma varsa), `INT 3`.
  - Donanımsal: NMI ve INTR uçları; INTR'nin onayı $\overline{INTA}$ ucudur.
  - Bayraklar: IF, TF. Dönüş komutu: IRET.
- Near, far çağrı ve kesme farkı
  - Near CALL: IP yığına; `RET` IP'yi çeker. Far CALL: önce CS, sonra IP yığına; `RETF` IP ve CS'yi çeker.
  - Kesme: önce bayrak yazmacı, sonra CS, sonra IP yığına atılır; `IRET` sırasıyla IP, CS ve bayrakları çeker.
- NMI ve INTR
  - NMI her zaman tip 2 kesmesini tetikler ve IF ile kapatılamaz; bellek yokluğu, gerilimin kararsız olması gibi kritik durumlar için kullanılır.
  - INTR'de işlemci isteği $\overline{INTA}$ ile onaylar, sonra veri yolunun düşük 8 bitinden kesme tipini okur.
  - IF = 0 iken INTR istekleri dikkate alınmaz; IF = 1 iken kabul edilir. TF = 1 iken her komuttan sonra tek adım (single step) kesmesi oluşur (hata ayıklama için).
- Kesme vektör tablosu
  - Belleğin en düşük 1024 baytında, her biri 4 bayt olan 256 göz. Düşük word offset (IP), yüksek word segment (CS) değeridir.
  - Tip 0 0H'den, tip 1 4H'den, tip 2 08H'den başlar.
  - Tip 0: sıfıra bölme; tip 1: tek adım (TF); tip 2: NMI; tip 3: kesme noktası (breakpoint); tip 4: taşma (INTO). Kalanı BIOS, işletim sistemi ve kullanıcıya ayrılmıştır.
  - Tablo BIOS, işletim sistemi açılışı ya da kullanıcı programı tarafından önceden doldurulur.
- Kesme işlemi adımları (ekrandan, 01:50:00)
  - Sırası gelen komut bitince işlemci, komut işlemeyle oluşan kesme, single-step, NMI, INTR, INT sırasıyla kesme olup olmadığına bakar.
  - Kesme varsa: PUSHF; IF ← 0, TF ← 0 (iç içe INTR ve single-step kesmeleri engellenir); PUSH CS; PUSH IP; IP ve CS vektör tablosundan yüklenir. Bunları işlemci kendisi yapar.
  - IRET bayrakları geri yüklediği için IF önceden 1 idiyse kendiliğinden yeniden 1 olur.
- Bayrak komutları
  - `STI` IF'yi 1, `CLI` 0 yapar; parametre almazlar. TF için özel komut yoktur.
  - TF ve diğer bayraklar `PUSHF`/`POPF` ile yığında ya da `LAHF`/`SAHF` ile AH'de bit işlemiyle değiştirilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- ADC0804 kullanım sırası
  - "Burayı anlamak çok önemli": ADC adresine yazarak dönüşüm başlat, $\overline{INTR}$ cihazının adresinden okuyup MSB 0 olana dek yokla, sonra ADC adresinden sonucu oku.
- ADC ile $\overline{INTR}$ tamponu aynı anda seçilmez
  - İki cihaz farklı adreslerdedir; biri seçiliyken diğerinin çıkışı yüksek empedanstadır. Bu yüzden $\overline{INTR}$'nin AD7'ye bağlı olması sonucun MSB'sini bozmaz.
- DAC dalga üretimi
  - Gönderilen değer aralığı genliği, değerin hatta kalma süresi frekansı belirler; uygun genlik ve frekansta dalga üretmek lab ve sınavlarda istenebilir.
- Kesme alt programları kısa olmalı
  - Kesme alt programı mümkün olduğunca hızlı dönmelidir; mikrodenetleyici programlamada da geçerli bir ilkedir.
- Kesme vektör tablosu
  - 256 göz × 4 bayt = 1024 bayt; her gözde ilgili kesme alt programının segment ve offset değeri bulunur.

## Kısa Tekrar Notları

- 8254 sayma değeri CLK frekansını böler: 2 MHz / 1000 = 2 kHz.
- DAC0830 ve ADC0804'ün adres ucu yoktur; her biri G/Ç uzayında 1 bayt kaplar.
- 8 bitlik DAC adımı 5 V/256.
- Paralel ADC: direnç merdiveni + karşılaştırıcılar + öncelikli kodlayıcı; hızlı.
- Rampa ADC: sayıcı + DAC + karşılaştırıcı + SRG; yavaş.
- ADC0804: `OUT` ile başlat, $\overline{INTR}$ = 0'ı yokla, `IN` ile oku.
- Testere dişi dalgada genlik değer aralığıyla, periyot gecikmeyle ayarlanır.
- Polling bloklayıcıdır; kesmede cihaz işlemciyi uyarır; DMA'da işlemci devre dışıdır.
- NMI → tip 2, maskelenemez. INTR → tip veri yolundan, $\overline{INTA}$ ile onay, IF ile maskelenir.
- Kesmede yığına sırasıyla bayraklar, CS, IP; IF ve TF sıfırlanır; IRET IP, CS, bayrakları geri alır.
- Vektör tablosu 00000H'den başlar, tip $n$'nin gözü $4n$ adresindedir.
- Tip 0 sıfıra bölme, 1 tek adım, 2 NMI, 3 breakpoint, 4 taşma.
- `STI`/`CLI` IF'yi ayarlar; TF için PUSHF/POPF ya da LAHF/SAHF kullanılır.

## Detaylı Açıklamalar

- DAC ile testere dişi üretimi
  - Program AL'yi sürekli artırıp DAC'ye gönderir. Her değer DELAY süresi kadar hatta kalır; bu yüzden çıkış merdiven biçiminde yükselir. FFH'den sonra INC AL değeri 00H yapar ve çıkış birden 0 V'a düşer. Proteus'ta ilk hâlde ölçülen periyot yaklaşık 400 ms idi. DELAY döngüsünün sayısı 00FFH'den 01FFH'ye çıkarılınca (255'ten 511'e, yaklaşık iki kat) periyot yaklaşık 800 ms'ye çıktı. Değer aralığı 00H-7FH'ye kısıtlanınca tepe gerilim yarıya indi.
  - > **Ders sonrası not:** Hoca 7FH sınırıyla tepe gerilimi için "2.9 volt olarak gerçekleşmiş" dedi (00:47:44). VREF 5,1 V iken 7FH için beklenen çıkış büyük olasılıkla $5{,}1\cdot127/256\approx2{,}53$ V'tur; hoca aynı yerde "0 ile 2.5 volt arasında" da demişti.
  <!-- BELİRSİZ: 00:49:19'da altyazıda CX'e "FFF" yüklendiği geçiyor; hoca 00:51:16'da "1FFH, yani 200H, iki katına çıktı" dediği için değer 01FFH kabul edildi. -->
- Paralel ADC'de 3 V örneği
  - Eşikler 1-7 V'tur. 3 V girişte $V_+>V_-$ koşulu yalnız 1 V ve 2 V eşikli karşılaştırıcılarda sağlanır (3 V eşiğinde eşitlik vardır, çıkış 0). Öncelikli kodlayıcı en üstten bakar, ilk 1'i I2'de görür ve 010 üretir.
- ADC0804'ün tam akışı
  - `OUT 200H` dönüşümü başlatır, $\overline{INTR}$ 1'e çıkar. Program 400H'den okuyup `TEST AL,80H` ile MSB'yi sınar; sonuç sıfır değilse dönüşüm sürüyordur ve okuma tekrarlanır. MSB 0 olunca `IN 200H` ile 8 bitlik sonuç alınır. Kısa bir bekleme sonrası döngü yeni bir dönüşüm başlatır.
- Kesmeye giriş ve dönüş
  - Kesme, near ve far çağrıdan bayrakları da saklamasıyla ayrılır. Bayraklar yığına atıldıktan sonra IF ve TF sıfırlanır, sonra CS ve IP yığına atılır ve vektör tablosundaki gözün ilk word'ü IP'ye, ikinci word'ü CS'ye yüklenir. IRET, IP'yi, CS'yi ve bayrakları geri alır; böylece kesmeden önceki IF değeri de geri gelir.
  - > **Ders sonrası not:** Hoca TF bayrağının "tip 3" kesmesi oluşturduğunu söyledi (01:40:18), sonra 01:46:54'te kendisi düzeltti: tek adım kesmesi tip 1'dir, tip 3 breakpoint kesmesidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
