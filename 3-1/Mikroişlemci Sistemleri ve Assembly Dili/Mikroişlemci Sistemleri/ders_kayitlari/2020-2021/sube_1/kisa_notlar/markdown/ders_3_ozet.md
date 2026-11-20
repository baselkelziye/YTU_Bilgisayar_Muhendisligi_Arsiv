# Ders 3 Çalışma Özeti

## Genel Konular

- 8086 adresleme modlarının tekrarı
  - Fiziksel adres, bir segment yazmacı ile bir offset değerinden hesaplanır: $PA = SR \times 10H + OR$ (ekrandan, 00:05:00). Yazmaçlar ve veri yolu 16 bit, adres yolu 20 bit olduğu için bu yöntem gerekir.
  - Yığın adresleme: `PUSH` ve `POP` gibi yığın komutlarında varsayılan segment yazmacı SS'dir.
  - Program hafızası adresleme: segment yazmacı CS, offset yazmacı IP'dir. Üç türü vardır.
    - Doğrudan: `JMP`/`CALL` komutuna iki 16 bitlik değer verilir ve CS ile IP doğrudan değişir. Başka bir kod segmentine dallanan far jump ve far call komutlarıdır.
    - Göreli: IP, 8 ya da 16 bitlik işaretli (ikiye tümleyen) bir değer kadar ileri ya da geri kaydırılır. 8 bitte aralık $-128 \ldots +127$'dir. `JMP 100` "IP'yi 100 artır", `JMP 0FFH` ise $-1$ olduğu için "IP'yi 1 azalt" demektir.
    - Dolaylı: gidilecek adres bir yazmaçla verilir (`JMP BX`, `CALL BX`). Komuttan önce BX uygun değere ayarlanmalıdır.
  - Veri hafızası adresleme:
    - Yazmaç adresleme: işlem yazmaçlar arasında yapılır. 8 bitlik AL, AH, BL, BH, CL, CH, DL, DH; 16 bitlik AX, BX, CX, DX, SP, BP, SI, DI kullanılabilir (ekrandan, 00:10:00). Genişlikler uyumlu olmalıdır: `MOV BX, CX` geçerli, `MOV AX, BL` ya da `MOV BX, AL` derleme hatasıdır.
    - Anlık (immediate) adresleme: sabit değer komutun makine koduna gömülür. Örnek: `MOV AL, 0F2H`. Sabit 8 ya da 16 bit, hatta tek tırnak içinde ASCII karakter olabilir. 8 bitlik yazmaca 16 bitlik sabit atanamaz.
    - Doğrudan adresleme: erişilecek hafıza gözü köşeli parantez içinde doğrudan verilir. `MOV BX, [1234H]` komutu BX'e 1234H değerini değil, DS:1234H adresindeki içeriği kopyalar (ekrandan, 00:15:00). Uygulamada adres yerine etiket kullanılır: `MOV AL, DATA` komutunda assembler etiketi karşılık gelen adresle değiştirir.
    - Dolaylı adresleme: köşeli parantez içinde yalnız BX, SI, DI (ve bunların sabitle toplamı, örn. `[BX+100H]`), taban+indis (`[BX+SI]`, `[BX+DI]`) ve taban+indis+sabit (`[BX+DI+100H]`) geçerlidir. `[AX]`, `[DX]` gibi kullanım derleme hatası verir.
  - BYTE PTR / WORD PTR: işlem genişliği operandlardan anlaşılamıyorsa belirtilmelidir. `MOV AX, [BX]` için gerek yoktur (AX 16 bit). `INC [BX]` ise belirsizdir, `INC BYTE PTR [BX]` ya da `INC WORD PTR [BX]` yazılmalıdır.
- 8086 uç tanımları (minimum mod)
  - MN/$\overline{MX}$ ucu 1 ise minimum, 0 ise maksimum mod (ekrandan, 00:25:00). Maksimum mod 8087 gibi bir yardımcı işlemciyle birlikte çalışmak içindir. Derste hep minimum mod kullanılacak, uç 5 V'a (lojik 1) bağlanacak.
  - AD0–AD15 adres/veri uçları, A16/S3–A19/S6 adres/durum uçları zaman çoğullamalıdır: T1'de adres, T2'den sonra veri (ya da durum) taşırlar.
  - ALE (Address Latch Enable): AD uçlarında adres olduğunu bildirir; adres tutucularının tutma ucuna bağlanır.
  - $\overline{DEN}$ (Data Enable): aktif 0; AD uçlarında veri olduğunu bildirir.
  - DT/$\overline{R}$ (Data Transmit/Receive): veri yönü. 1 ise işlemci veri gönderir, 0 ise okur. Yalnız veri ayırma devresine bağlanır, çevre birimlerine gitmez.
  - $\overline{RD}$, $\overline{WR}$: aktif 0 okuma/yazma uçları; bütün çevre birimlerine kadar uzanır.
  - RESET: işlemciyi fiziksel olarak sıfırlar. Reset vektörü CS = FFFFH, IP = 0000H, yani FFFF0H fiziksel adresidir; BIOS ROM'u burada bulunmalıdır.
  - READY: 0 olunca işlemci bekleme durumlarına girer; yavaş çevre birimleri için kullanılır.
  - $\overline{BHE}$/S7 (Bus High Enable): verinin yalnız veri yolunun yüksek baytında olduğunu 0 ile gösterir. Ayrı bir $\overline{BLE}$ ucu yoktur; A0 = 0 düşük baytın kullanıldığını gösterir (A0 ≡ $\overline{BLE}$, ekrandan 00:40:00).
  - M/$\overline{IO}$: slayttaki IO/M yazımı hoca tarafından M/$\overline{IO}$ olarak düzeltildi. `MOV AX, [100H]` için 1, `IN AX, ...` için 0 olur (ekrandan, 00:45:00).
  - HOLD / HLDA: DMA sırasında işlemcinin yollardan çekilmesi ve yolları geri alması için istek/onay çifti.
  - INTR / $\overline{INTA}$: dış kesme isteği (giriş) ve kesme onayı (çıkış, aktif 0). INTR'nin etkili olması için IF = 1 olmalıdır (ekrandan, 00:55:00). INTR seviye tetiklemelidir.
  - NMI: maskelenemeyen kesme; bayrakla kapatılamaz, kenar tetiklemelidir. Güç dalgalanması, RAM hatası gibi kritik durumlar için kullanılır.
  - CLK, VCC, GND: dışarıdan üretilen senkron saat işareti ve besleme.
- Hafıza ve G/Ç uzayı
  - 20 adres ucu ile hafıza uzayı $2^{20}$ = 1 MB'tır.
  - `IN`/`OUT` komutlarında port adresi 8 bite sığıyorsa doğrudan verilir; sığmıyorsa DX ile verilir (`IN AX, DX`). DX 16 bit olduğu için G/Ç uzayı $2^{16}$ = 64 KB'tır.
  - M/$\overline{IO}$ adres çözümlemeye katılırsa 1 MB hafıza ve 64 KB G/Ç iki ayrı uzay olur; katılmazsa düşük 64 KB G/Ç'ye ayrılır ve hafızadan bu kadar alan kaybedilir, ama çözümleme devresi basitleşir.
- Adres çözümleme devresi
  - Bütün çevre birimleri aynı adres, veri ve kontrol yollarına bağlıdır. Çözümleme devresi, işlemcinin verdiği adrese göre yalnız bir cihazın chip select ucunu etkin yapar; diğerleri yüksek empedansta kalır ve çakışma önlenir.
- Veri aktarım yöntemleri
  - Polling (yoklama): bir durum bitini döngü içinde okuyup maskeleyerek veri hazır olana kadar aktif bekleme.
  - DMA: işlemci aktarım cihazını programlar, kendini yollardan yalıtır; aktarım hafıza ile G/Ç arasında işlemciye uğramadan yapılır.
  - Kesme tabanlı: çevre birimi veri hazır olunca INTR ile haber verir; işlemci o anki komutu bitirip kesme alt programına dallanır ve sonra ana programa döner.
- Yardımcı devreler
  - Saat üreteci (8284): kristal osilatörün çıkışını kare dalgaya çevirir; RC devresiyle reset gecikmesi sağlar; yavaş çevre birimleri için READY ile bekleme üretir.
  - Yol tamponlama (buffering): uçların akım kapasitesi sınırlı olduğundan sinyaller tamponlarla güçlendirilir.
  - Yol tutma (latching): zaman çoğullamalı uçlardaki adres ve veri, komutun 4 saat çevrimi boyunca kararlı tutulmalıdır.
- Kullanılan entegreler
  - 74LS373 sekizli tutucu: $\overline{OE}$ = 1 ise çıkış yüksek empedans; $\overline{OE}$ = 0 ve LE = 1 ise çıkış girişi izler; LE = 0 ise son değer tutulur (ekrandan, 01:30:00). Adres ayırmada: giriş AD uçları, LE ← ALE, $\overline{OE}$ ← 0.
  - 74LS245 sekizli alıcı-verici: $\overline{E}$ = 1 ise yollar yalıtılır; $\overline{E}$ = 0, DIR = 0 ise B → A; DIR = 1 ise A → B (ekrandan, 01:40:00). Veri ayırmada: A ← AD uçları, DIR ← DT/$\overline{R}$, $\overline{E}$ ← $\overline{DEN}$.
  - 74LS244 sekizli tampon: tutma ucu yoktur; $\overline{1G}$, $\overline{2G}$ = 0 iken çıkış girişi izler, 1 iken yüksek empedans (ekrandan, 01:45:00). Daha yüksek akımla sürer; $\overline{RD}$, $\overline{WR}$, M/$\overline{IO}$ uçlarını tekrarlamak için kullanılır.
- Tam tamponlanmış 8086 sistemi ve yol zamanlaması
  - Üç adet '373 (A0–A15 ve A16–A19 ile $\overline{BHE}$), iki adet '245 (D0–D15) ve bir '244 (M/$\overline{IO}$, $\overline{RD}$, $\overline{WR}$) ile bütün uçlar ayrıştırılır (ekrandan, 01:50:00). Bundan sonra derste "adres, veri ve kontrol uçlarının tutulmuş ve tekrarlanmış olduğunu varsayabilirsiniz" denince bu yapı kastedilir.
  - Okuma çevrimi T1–T4 sürer: T1'de adres çıkar ve ALE 1 olur; T2'de AD uçları veriye geçer, $\overline{DEN}$ = 0, DT/$\overline{R}$ = 0, $\overline{RD}$ = 0; veri T3 civarında okunur (ekrandan, 01:55:00). Yazma çevriminde DT/$\overline{R}$ = 1 olur ve $\overline{WR}$ gönderilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Köşeli parantez değerin kendisini değil, o offset'teki hafıza içeriğini ifade eder; veri komutlarında varsayılan segment DS'dir.
  - `MOV BX, [1234H]` BX'e 1234H yazmaz, DS:1234H'deki word'ü yazar.
- Göreli dallanmada verilen sayı adres değil, IP'ye eklenecek işaretli bir yerdeğiştirmedir.
  - `JMP 0FFH` 255. offset'e gitmez, bir geri gider.
- BYTE PTR / WORD PTR yalnız genişlik belirsizken gereklidir.
  - Örnek: 100H'de 0FFH, 101H'de 99H varken `INC BYTE PTR [BX]` yalnız 100H'yi 00H yapar; `INC WORD PTR [BX]` 99FFH'yi 9A00H yapar.
- Adres uçları işlemci açısından yalnız çıkıştır, veri uçları iki yönlüdür.
  - Bu yüzden adres ayırmada tek yönlü tutucu (373), veri ayırmada iki yönlü alıcı-verici (245) kullanılır ve yön DT/$\overline{R}$ ile verilir.
- Uç tanımları aksi belirtilmedikçe işlemci açısından yapılır.
  - $\overline{RD}$ "işlemci okuyor" anlamına gelir.
- ALE 1 olduğu anda AD uçlarında adres vardır; ALE 0'a düştüğünde 373 adresi tutar ve AD uçları veri taşıyabilir. Hoca bunu "çok önemli" diye vurguladı.
- 373, 245 ve 244 farkları ayırt edilmeli: tutucu, alıcı-verici, tampon.

## Kısa Tekrar Notları

- $PA = SR \times 10H + OR$; 16 bit yazmaç, 20 bit adres yolu.
- Yığın komutları → SS; program akışı → CS:IP; veri komutları → DS.
- Program adresleme: doğrudan (far, CS ve IP değişir), göreli (işaretli 8/16 bit), dolaylı (`JMP BX`).
- Veri adresleme: yazmaç, anlık, doğrudan (`[1234H]`), dolaylı (`[BX]`, `[SI]`, `[DI]`, `[BX+SI]`, `[BX+DI+100H]`).
- `[AX]`, `[DX]` geçersiz; `MOV AX, BL` geçersiz.
- MN/$\overline{MX}$ = 1 → minimum mod.
- ALE → adres var; $\overline{DEN}$ = 0 → veri var; DT/$\overline{R}$ = 1 gönder, 0 al.
- $\overline{BHE}$ = 0 → yüksek bayt; A0 = 0 → düşük bayt.
- M/$\overline{IO}$: MOV → 1, IN/OUT → 0.
- Hafıza 1 MB, G/Ç 64 KB (port DX ile).
- Reset vektörü: CS = FFFFH, IP = 0000H → FFFF0H.
- INTR: IF = 1 gerekir, seviye tetikleme; NMI: maskelenemez, kenar tetikleme.
- HOLD/HLDA → DMA.
- 373: LE ← ALE, $\overline{OE}$ ← 0. 245: DIR ← DT/$\overline{R}$, $\overline{E}$ ← $\overline{DEN}$. 244: $\overline{RD}$, $\overline{WR}$, M/$\overline{IO}$ tamponu.
- Yol çevrimi 4 saat periyodu: T1 adres, T2–T3 veri.

## Detaylı Açıklamalar

- **Adres hesabı ve segmentler.** 8086'nın yazmaçları ve veri yolu 16 bit, adres yolu 20 bittir. 20 bitlik adres, bir segment yazmacının 10H ile çarpılıp (sola 4 bit kaydırılıp) bir offset değeriyle toplanmasıyla elde edilir. Hangi segment yazmacının kullanılacağı komut türüne bağlıdır: yığın komutları SS, program akışı CS (offset olarak IP), veri aktarım komutları DS kullanır.

- **Program hafızası adresleme.** Doğrudan modda `JMP`/`CALL` iki 16 bitlik değer alır ve CS ile IP'yi birlikte değiştirir; bu, başka bir kod segmentine geçen far jump ve far call'dur. Göreli modda aynı kod segmenti içinde kalınır ve IP işaretli bir sayı kadar kaydırılır. Örneğin `JMP 100` (onluk, pozitif) IP'yi 100 artırır; `JMP 0FFH` ikiye tümleyende $-1$ olduğu için IP'yi bir azaltır. Uygulamada sayı yerine etiket yazılır; komut boyutlarını ve adres aritmetiğini assembler hesaplar. Kullanıcının IP'ye doğrudan müdahalesi istenmeyen sonuçlar doğurabileceği için bu yol tercih edilir. Dolaylı modda gidilecek adres bir yazmaçtadır (`JMP BX`).

- **BYTE PTR / WORD PTR örneği (ekrandan, 00:20:00).** Hafızada 100H adresinde 0FFH, 101H adresinde 99H olsun ve `MOV BX, 100H` çalıştırılmış olsun. `INC [BX]` belirsizdir.
  - `INC BYTE PTR [BX]`: 100H'deki bayt 0FFH + 1 = 00H olur, 101H değişmez.
  - `INC WORD PTR [BX]`: little endian yerleşimde 100H'deki word 99FFH'dir; 99FFH + 1 = 9A00H. Sonuçta 100H'de 00H, 101H'de 9AH bulunur.
  - Ders sonrası not: Hoca bayt artırımında taşma bayrağının (CF) 1 olduğunu söyledi (00:19:45). 8086'da `INC` komutu CF'yi etkilemez; ZF = 1 ve AF = 1 olur, CF önceki değerini korur.

- **Zaman çoğullama ve ayırma devreleri.** Uç sayısını azaltmak için adres ve veri aynı uçları paylaşır. Hafıza ve G/Ç cihazları ise adresin bütün okuma/yazma çevrimi boyunca kararlı kalmasını ister. Bu yüzden ALE ile tetiklenen 373 tutucuları adresi T1'de yakalayıp çevrim boyunca tutar. Veri iki yönlü olduğundan 245 alıcı-vericisi kullanılır: DT/$\overline{R}$ = 1 iken A → B (işlemciden dışarı), 0 iken B → A (dışarıdan işlemciye) aktarır. $\overline{DEN}$ ise 245'i etkinleştirir. Kontrol uçları ($\overline{RD}$, $\overline{WR}$, M/$\overline{IO}$) bütün çevre birimlerine gittiği için 244 tamponuyla daha yüksek akımla sürülür. Hoca bunu bakır hattın ara kutularda kuvvetlendirilerek eve ulaştırılmasına benzetti.

- **Adres çözümleme ve M/$\overline{IO}$.** `MOV AX, [100H]` ve `IN AX, ...` ikisi de adres uçlarına aynı değeri çıkarabilir. M/$\overline{IO}$ çözümleme devresine dahil edilirse iki ayrı uzay oluşur: 1 MB hafıza ve 64 KB G/Ç. Dahil edilmezse düşük 64 KB G/Ç'ye ayrılır; devre basitleşir ama hafıza uzayından kayıp olur.

- **Kesmeler.** INTR'ye gelen istek o anki komut tamamlandıktan sonra değerlendirilir. İşlemci $\overline{INTA}$ ucunu 0 yaparak isteği değerlendirdiğini çevre birimine bildirir; böylece birim bir sonraki veriye hazırlanabilir. INTR yalnız IF = 1 iken etkilidir. NMI hiçbir bayrakla kapatılamaz.
  - Ders sonrası not: Hoca NMI'nin yükselen kenarda mı düşen kenarda mı tetiklendiğini hatırlayamadığını söyledi (00:56:29). 8086'da NMI yükselen kenarda tetiklenir.

- **Yol zamanlaması (ekrandan, 01:55:00).** Bir yol çevrimi T1–T4 olmak üzere dört saat periyodudur. Okumada T1'de AD uçlarında adres vardır ve ALE ile tutulur; geçerli adres çevrim boyunca adres yolunda kalır. $\overline{RD}$ T2'de 0'a iner; AD uçlarında T3 boyunca "hafızadan gelen veri" bulunur ve işlemci veriyi bu aralıkta okur. Yazma çevriminde T2'de işlemcinin göndermek istediği veri AD uçlarına çıkar, $\overline{DEN}$ = 0 ve DT/$\overline{R}$ = 1 olur, çevre birimine $\overline{WR}$ gönderilir.
  - <!-- BELİRSİZ: Hoca okuma ve yazma için verinin hangi saat kenarında alındığını önce düşen, sonra yükselen kenar olarak düzeltti (01:54:55, 01:56:42); yazma çevriminin zaman çizelgesi karesi yok. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
