# Ders 11 Çalışma Özeti

## Genel Konular

- 8255 mod 1 tekrarı: el sıkışma, kesme izin bitleri ve durum sözcüğü
  - Mod 0 el sıkışmasız temel G/Ç'dir (LED, düğme gibi doğrudan sürülen ya da okunan uçlar). Mod 1 ve mod 2 el sıkışmalıdır; mod 1 tek yönde, mod 2 çift yönde çalışır.
  - Mod 1 giriş: dış dünya veri hazır olunca $\overline{STB}$ gönderir, 8255 IBF ile cevap verir. Mod 1 çıkış: 8255 veriyi uçlara koyunca $\overline{OBF}$ verir, dış dünyadan $\overline{ACK}$ bekler.
  - $\overline{STB}$/IBF ve $\overline{OBF}$/$\overline{ACK}$ sinyalleri 8086'nın kesme isteği için uygun değildir; bu yüzden ayrı bir INTR ucu vardır. Grup A'nın INTR ucu PC3, grup B'ninki PC0'dır.
  - INTR'nin oluşması için kesme izin (INTE) bitinin bit set/reset (BSR) moduyla kurulması gerekir: giriş yönlü grup A için PC4, grup B için PC2.
  - Port C adresinden yapılan okuma durum sözcüğünü (status word) verir. Giriş yönlü grup A ve B için: D5 = $\text{IBF}_A$, D4 = $\text{INTE}_A$, D3 = $\text{INTR}_A$, D2 = $\text{INTE}_B$, D1 = $\text{IBF}_B$, D0 = $\text{INTR}_B$ (ekrandan, 00:10:00).
  - $\text{INTR}_A$ için durum sözcüğü `08H` ile, $\text{INTR}_B$ için `01H` ile VE'lenerek maskelenir; böylece kesme isteği yoklama (polling) ile okunabilir.
- 8255 mod 2 (çift yönlü veri yolu)
  - Yalnız grup A destekler. Port A çift yönlü veri portudur; port C'nin 5 ucu el sıkışma ve kontrol işaretidir.
  - Kontrol sözcüğünde D7 = 1 (mod ayarı), D6 = 1, D5 = X mod 2 anlamına gelir. Grup A için yön ayarı gerekmez. Grup B mod 0 ya da mod 1'de, giriş ya da çıkış olarak ayarlanabilir.
  - Port C'nin düşük yarısından yalnız PC0-PC2 serbest kalır; PC3 $\text{INTR}_A$ olarak kullanılır.
  - INTE1 PC6, INTE2 PC4 ile BSR modunda kurulur. Durum sözcüğünde D3 $\text{INTR}_A$, D5 $\text{IBF}_A$, D7 $\overline{OBF}_A$'dır.
  - Özet tablo: mod 1 girişte yalnız PC6-PC7, mod 1 çıkışta yalnız PC4-PC5 boşta kalır.
- Mod 1 Proteus örneğinin tekrarı (tuş takımı ve 7 parçalı gösterge)
  - Tuş tarama entegresi (MM74C922) sütunları sürer, satırları okur. Tuşa basılınca DA (data available) ucu 1 olur; $\overline{OE}$'ye 0 verilince tuşun ikili kodu D, C, B, A uçlarına çıkar.
  - 4511 entegresi ortak katotlu 7 parçalı göstergeyi sürer; girişteki değeri tutmak için bir latch enable (strobe) ucu vardır.
  - Tuş takımı grup A mod 1 girişe bağlanır: DA, $\overline{STB}$ işlevini görür; IBF'den $\overline{OE}$ sürülür (ekrandan, 00:25:00).
  - Gösterge grup B mod 1 çıkışa bağlanır: $\overline{OBF}$ 4511'in latch girişini sürer. 4511'in $\overline{ACK}$ üretecek ucu olmadığı için $\overline{OBF}$ iki DEĞİL kapısının gecikmesinden geçirilip $\overline{ACK}$ olarak geri verilir.
  - Cihaz 200H'den itibaren ardışık çift adreslerdedir: 200H port A, 202H port B, 204H port C, 206H kontrol yazmacı.
  - Kod: `09H` ve `05H` BSR komutlarıyla $\text{INTE}_A$ (PC4) ve $\text{INTE}_B$ (PC2) kurulur, `0BCH` ile grup A mod 1 giriş, grup B mod 1 çıkış seçilir (ekrandan, 00:30:00). Durum sözcüğü `08H` ile maskelenip $\text{INTR}_A$ beklenir, port A okunur; sonra `01H` ile $\text{INTR}_B$ beklenir ve okunan değer port B'ye yazılır.
- Seri ve paralel veri iletişimi
  - Paralel iletişimde her bit için ayrı bir kanal vardır ve bütün bitler aynı anda gider: daha hızlıdır, kısa mesafeler içindir. Uzun mesafede çok telli hat maliyeti artırır.
  - Seri iletişimde veri önce serileştirilir (paralelden seriye), bit bit gönderilir, alıcıda yeniden paralelleştirilir. Daha az maliyetli, daha yavaştır.
  - Seri iletişim ikiye ayrılır: senkron ve asenkron.
- Senkron ve asenkron iletişim
  - Senkron: alıcı ile verici ortak bir saat işaretini paylaşır. Kayma olmadığı için büyük veri blokları gönderilir; blokların başı ve sonu çok bitli özel işaretlerle belirtilir. Ek yük (overhead) azdır, ama ortak saat gerektiği için pahalıdır. Örnek çerçeveler: BISYNC (iki senkronizasyon karakteri, veri, hata kontrol baytları) ve IBM'in SDLC'si (8 bitlik başlangıç/bitiş bayrakları, adres, kontrol, veri, çerçeve kontrol).
  - Asenkron: ortak saat yoktur; iki taraf baştan baud hızında, veri biti sayısında, eşlik ve dur biti sayısında anlaşır. Veri küçük paketlerle gönderilir, her paketin başına başlangıç (start), sonuna dur (stop) biti eklenir.
  - Asenkron bağlantı için üç tel gerekir: gönderme, alma ve ortak toprak. Ortak toprak, iki tarafın lojik 1 seviyesinin aynı referansa göre anlamlı olmasını sağlar.
  - Hat boştayken lojik 1'dedir. Verici hattı 0'a çekerek start bitini verir; sonra veri bitleri en düşük anlamlı bitten başlayarak, varsa eşlik biti ve dur bitleri gelir. Hocanın anlattığı modelde alıcı her biti bit süresi boyunca iki kez örnekler.
  - Ders kapsamında yalnız asenkron iletişim kullanılacaktır.
- Simplex, half duplex, full duplex
  - Simplex: veri tek yönde akar (bilgisayardan yazıcıya; radyo, karasal TV yayını).
  - Half duplex: iki yön de mümkündür ama aynı anda tek yön kullanılır (telsiz).
  - Full duplex: iki yön aynı anda kullanılır (cep telefonu, sabit telefon).
- Baud hızı ve hesap örnekleri
  - Baud hızı iki tarafın anlaştığı iletişim hızıdır; sinyalin saniyedeki en fazla değişim sayısıdır. Tersi bir bitin hatta kalma süresini verir: 1200 baud için $1/1200 \approx 0{,}83$ ms, 9600 baud için yaklaşık 104 µs.
  - Bit süresi 3,33 ms, 1 start + 8 veri + 2 stop: bit hızı 300 bit/s, karakter süresi 36,63 ms, karakter hızı 27,3 karakter/s (ekrandan, 01:10:00).
  - 1 MB dosya, 1 start + 7 veri + 1 eşlik + 1 stop: 9600 bps'de 1092 s (18 dk 12 s), 28800 bps'de 364 s (6 dk 4 s) (ekrandan, 01:10:00).
- Hata tespiti
  - Bitler hatta belirli süre kaldığı için elektromanyetik girişimle bozulabilir.
  - Eşlik (parity) denetimi: çift eşlikte veri ve eşlik bitleri dahil 1'lerin sayısı çift, tek eşlikte tek tutulur. Tek sayıda bit bozulursa yakalanır, çift sayıda bozulma yakalanamaz.
  - CRC: verinin sonuna özel bir kontrol paketi eklenir, alıcı kendi hesapladığıyla karşılaştırır.
- Yazılımsal seri gönderici
  - Akış: bit sayacını kur, start bitini gönder, bit süresi bekle, karakteri akümülatöre al; döngüde D0 üzerinden biti çıkar, bit süresi bekle, sonraki biti D0'a döndür, sayacı azalt; son bitten sonra gerekirse eşlik biti ve dur bitlerini gönder (ekrandan, 01:20:00).
  - Kod (ekrandan, 01:25:00): `MOV CX,10`, `CLC`, `RCL AL,1`; döngüde `OUT DPORT,AL`, `CALL DELAY`, `RCR AL,1`, `STC`, `LOOP TRANS`. Çıkış biti 8255'in bir port ucudur (örnekte PA0).
  - Yazılımsal alıcı: start biti iki kez örneklenerek beklenir, sonra her bit okunup bekleme yapılır ve carry üzerinden AL'ye kaydırılarak biriktirilir; sonda dur biti (ve varsa eşlik) denetlenir. Bunun kodu derste verilmedi.
- 8251 USART
  - Evrensel senkron/asenkron alıcı-verici. 8 bitlik bir cihazdır; ardışık çift adreslere yerleşirse D0-D7'ye, tek adreslere yerleşirse D8-D15'e bağlanır.
  - Uçlar: CLK (iç zamanlama), RESET, $\overline{RD}$, $\overline{WR}$, $\overline{CS}$, tek adres ucu C/$\overline{D}$, TxRDY ve RxRDY (kesme isteği kaynağı, 8259 üzerinden 8086'nın INTR ucuna), RxD ve TxD (seri veri), RxC ve TxC (ayrı alma/gönderme saatleri), modem kontrol uçları (kullanılmayacak).
  - Dışarıdan erişilen yazmaçlar: mod, senkronizasyon 1, senkronizasyon 2, kontrol, data-in, data-out ve durum. Tek adres ucu olduğu için G/Ç uzayında 2 bayt yer kaplar.
  - Erişim tablosu (ekrandan, 01:40:00): $\overline{CS}$ = 1 ya da $\overline{RD}$ = $\overline{WR}$ = 1 iken veri yolu üç durumludur; C/$\overline{D}$ = 1 okuma durum yazmacını, C/$\overline{D}$ = 1 yazma mod/kontrol/senkronizasyon yazmaçlarını, C/$\overline{D}$ = 0 okuma data-in'i, C/$\overline{D}$ = 0 yazma data-out'u seçer.
  - Kontrol adresine yazma sırası: resetten sonraki ilk yazma mod yazmacına gider. Senkron modda ardından bir ya da iki senkronizasyon karakteri, sonra kontrol yazmacı gelir; asenkron modda doğrudan kontrol yazmacı gelir. Reset komutu akışı başa döndürür.
- 8251 mod, kontrol ve durum yazmaçları
  - Mod yazmacı (asenkron, ekrandan 01:45:00): B2B1 baud faktörü (00 senkron mod, 01 → 1, 10 → 16, 11 → 64), L2L1 veri biti sayısı (00 → 5, 01 → 6, 10 → 7, 11 → 8), PEN eşlik izni, EP eşlik türü (0 tek, 1 çift), S2S1 dur biti (00 geçersiz, 01 → 1, 10 → 1,5, 11 → 2).
  - Kontrol yazmacı (ekrandan, 01:50:00), D0'dan D7'ye: TxEN, DTR, RxE, SBRK, ER, RTS, IR, EH. TxEN gönderme, RxE alma izni; SBRK hattı 0'a zorlayıp kesinti (break) üretir; ER durum yazmacındaki üç hata bitini temizler; IR iç reset'tir (`40H`); EH (hunt mod) 0 kullanılacaktır.
  - Durum yazmacı (ekrandan, 01:55:00), D0'dan D7'ye: TxRDY, RxRDY, TxE, PE, OE, FE, SYNDET, DSR. Gönderme için TxRDY (D0) = 1, alma için RxRDY (D1) = 1 beklenir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kesme izin bitleri BSR moduyla kurulur
  - Mod 1 ve mod 2'de INTR ucunun işlemesi için ilgili INTE bitinin port C'nin belirli bir bitine BSR komutu yazılarak 1 yapılması gerekir.
- Adres çözümleme tam yapılmalı
  - Proteus örneğinde bazı adres uçları boşta bırakıldığı için devre birçok adreste çalışır; derste yapılacak tasarımlarda ise cihazın yalnız kendi 4 baytlık aralığında çalışacağı tam çözümleme istenir.
- Asenkron iletişimde paketler küçük tutulur
  - Ortak saat olmadığı için iki tarafın saat farkı uzun paketlerde bir önceki ya da sonraki bitin yanlış okunmasına yol açar; bu yüzden start ve stop bitleriyle sınırlanmış küçük paketler kullanılır.
- 8251'de tek adres ucuyla yedi yazmaca erişim
  - Kontrol adresine yapılan yazmalar sıralı bir akışla mod, senkronizasyon ve kontrol yazmaçlarına gider; reset komutu akışın neresinde olunduğunu kesinleştirir.
- Yoklama ile 8251 kullanımı
  - Yeni veri yazmadan önce TxRDY = 1 beklenir, yoksa önceki veri ezilebilir. Veri okumadan önce RxRDY = 1 beklenir.

## Kısa Tekrar Notları

- Mod 1 giriş: $\overline{STB}$ → IBF; çıkış: $\overline{OBF}$ → $\overline{ACK}$. $\text{INTR}_A$ = PC3, $\text{INTR}_B$ = PC0.
- Giriş yönlü $\text{INTE}_A$ = PC4, $\text{INTE}_B$ = PC2 (BSR ile). Mod 2: INTE1 = PC6, INTE2 = PC4.
- Durum sözcüğü port C adresinden okunur; $\text{INTR}_A$ maskesi `08H`, $\text{INTR}_B$ maskesi `01H`.
- Mod 2 yalnız grup A'da; port A çift yönlü, port C'nin 5 ucu kontrol.
- `0BCH` = 1011 1100: grup A mod 1 giriş, grup B mod 1 çıkış. `09H`: PC4 set, `05H`: PC2 set.
- Seri: ucuz ve yavaş, uzun mesafe; paralel: hızlı, kısa mesafe.
- Senkron: ortak saat, büyük blok, az ek yük, pahalı. Asenkron: ortak saat yok, küçük paket, start/stop bitleri.
- Asenkron hat boşta 1, start biti 0, veri LSB önce, sonra eşlik ve dur bitleri (1).
- Bit süresi = 1 / baud. 9600 baud ≈ 104 µs.
- Karakter hızı = baud / (çerçevedeki bit sayısı).
- Eşlik denetimi tek sayıda bit hatasını yakalar.
- 8251: C/$\overline{D}$ = 1 kontrol/durum, C/$\overline{D}$ = 0 veri. Resetten sonra ilk kontrol yazması mod yazmacına gider.
- Mod yazmacında son iki bit 00 ise senkron, değilse asenkron ve baud faktörü (1, 16, 64).
- Kontrol: TxEN = D0, RxE = D2, ER = D4, IR = D6 (`40H`). Durum: TxRDY = D0, RxRDY = D1.

## Detaylı Açıklamalar

- **Mod 1 örneğinin kodu.** Cihaz 200H'den başlayan çift adreslerde olduğundan adresler 8 bite sığmaz ve DX üzerinden verilir. Kontrol adresi 206H'ye önce `09H` (0000 1001: BSR, bit seçimi 100 = PC4, set) ve `05H` (0000 0101: bit seçimi 010 = PC2, set) yazılarak iki kesme izni açılır, sonra `0BCH` kontrol sözcüğü yazılır. Sonsuz döngüde 204H'den durum sözcüğü okunur, `AND AL,08H` ile $\text{INTR}_A$ biti ayrılır ve sıfır olduğu sürece beklenir. Bit 1 olunca dış dünyadan gelen veri port A yazmacındadır; 200H'den okunup BL'de saklanır. Ardından yine durum sözcüğü okunur, `AND AL,01H` ile $\text{INTR}_B$ beklenir; bu bit 1 olunca port B yeni veri almaya hazırdır ve BL 202H'ye yazılır. Böylece basılan tuşun değeri 7 parçalı göstergede görünür (ekrandan, 00:30:00).
- **`CMP AL,00` / `JE` yerine başka yollar.** Bir soru üzerine hoca, `JE` ile `JZ`'nin aynı komut olduğunu ve `CMP` yerine `TEST` de kullanılabileceğini, ikisinin aynı sonucu ürettiğini doğruladı.
- **Asenkron iletişimde saat farkı.** Hoca örnek olarak bir terminalin 2 MHz, diğerinin 1,8 MHz kristalle çalıştığı durumu verdi ve 8 bitlik paketlerde bunun büyük kayba yol açmayacağını, ama 20-50 bitlik paketlerde bitlerin kayarak yanlış okunacağını söyledi.
  - Ders sonrası not: %10'luk bir saat farkı 10-11 bitlik bir çerçevede bile son bitlerde örnekleme noktasını bir bit süresine yakın kaydırır; pratikte UART'larda iki taraf arasındaki toplam fark büyük olasılıkla birkaç yüzdeyle sınırlı tutulmalıdır. Örneğin anlamı, küçük paketlerin saat farkına karşı daha toleranslı olmasıdır.
- **Baud hızı ve çerçeve hesabı.** Bit süresi 3,33 ms ise bit hızı $1/3{,}33\text{ ms} \approx 300$ bit/s'dir. Çerçeve 1 + 8 + 2 = 11 bittir; bir karakter $11 \times 3{,}33 = 36{,}63$ ms sürer ve saniyede $1/36{,}63\text{ ms} \approx 27{,}3$ karakter gider. 1 MB = $2^{20}$ = 1048576 bayt ve çerçeve 10 bit olduğunda 9600 bps'de $1048576 \times 10 / 9600 \approx 1092$ s (18 dk 12 s), 28800 bps'de yaklaşık 364 s (6 dk 4 s) gerekir. Değerler python ile doğrulandı.
- **Yazılımsal göndericide RCL/RCR/STC hilesi.** `CLC` ile carry 0 yapılır; `RCL AL,1` bu 0'ı AL'nin D0'ına koyar, AL'nin D7'si carry'ye geçer. İlk `OUT` start bitini (0) gönderir. `RCR AL,1` start bitini carry'ye geri alır, D7'yi yerine koyar; AL artık orijinal veridir. Her turda `STC` carry'yi 1 yapar, bir sonraki `RCR` bu 1'i AL'ye soldan sokar. Sonraki sekiz `OUT` D0-D7 veri bitlerini sırayla gönderir; onuncu turda AL'nin D0'ında soldan giren 1 bulunur ve dur biti olarak gider. Hoca önce bu komutu "CLC" diye okudu, sonra `STC` olduğunu düzeltti. Gecikme fonksiyonu boş bir döngüdür; 9600 baud için yaklaşık 104 µs sürmelidir. Bit dizisi python benzetimiyle doğrulandı: 41H için 0, 1, 0, 0, 0, 0, 0, 1, 0, 1.
- **4511'in latch ucu.** Hoca latch enable'a 0 verilince girişteki değişikliklerin göstergeye yansımadığını söyledi.
  - Ders sonrası not: 4511'de LE ucu büyük olasılıkla tersi biçimde çalışır: LE = 0 iken giriş göstergeye geçer, LE = 1 iken son değer tutulur. Proteus devresinde $\overline{OBF}$'nin yazmadan sonra 0'a düşüp latch girişini sürmesi de bu davranışla uyumludur.
- **Hata tespitinde CRC.** Hoca CRC ile alıcının hata olup olmadığını ve hatanın nerede olduğunu bulabileceğini söyledi.
  - Ders sonrası not: CRC büyük olasılıkla yalnız hata tespiti için kullanılır; hatanın yerini bulup düzeltmek Hamming gibi hata düzelten kodların işidir.
- **8251 durum hataları.** Eşlik hatası (PE): alınan eşlik biti alıcının hesapladığıyla uyuşmaz. Çerçeve hatası (FE): beklenen dur biti doğru alınmaz. Taşma hatası (OE): hoca bunu "veri gönderimi bitmeden üzerine veri yazılması" diye anlattı.
  - Ders sonrası not: OE büyük olasılıkla alıcı tarafın hatasıdır: işlemci data-in tamponundaki karakteri okumadan yeni karakter gelir ve eskisinin üzerine yazar.
- **8251'in iki reset yolu.** Fiziksel RESET ucuna 1 vermek ya da kontrol yazmacının D6 (IR) bitine 1 yazmak, yani kontrol adresine `40H` göndermek. Tipik kurulum: reset, mod yazmacına asenkron mod ve uygun baud faktörü, ardından reset olmayan bir kontrol sözcüğü.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
