# Ders 19 Çalışma Özeti

## Genel Konular

- 8254 örneği 1: 1 saniyede bir pulse üretmek (kaskat sayıcı)
  - Soru: A9H adresinden itibaren ardışık tek adreslere yerleştirilmiş 8254 (8253 ile de olur) kullanılarak periyodik olarak 1 sn'de bir pulse işareti üretilecek. 8254 için yalnız 2 MHz'lik saat işareti vardır. (ekrandan, 00:05:00)
  - Adresler: A9H'de CNTR0, ABH'de CNTR1, ADH'de CNTR2, AFH'de kontrol yazmacı. (ekrandan, 00:05:00)
  - Sayıcı bir frekans bölücüdür. 1 sn periyot 1 Hz demektir, yani 2 MHz'in $2\times10^6$'ya bölünmesi gerekir.
  - Tek sayıcıyla en büyük bölme 65536'dır (0 değeri 65536 adım sayılır). Tek sayıcıyla elde edilebilecek en düşük frekans $\frac{2\times10^6}{65536}\cong 30\,\text{Hz}$'dir. Bu yüzden iki sayıcı gerekir. (ekrandan, 00:05:00)
  - Kaskat bağlantı: 2 MHz CNTR0'ın CLK ucuna, CNTR0'ın OUT ucu CNTR1'in CLK ucuna bağlanır. Sayma değerlerinin çarpımı $2\times10^6$ olmalıdır.
  - CNTR0 2000, CNTR1 1000 ile yüklenir: 2 MHz → 1 kHz → 1 Hz. Pulse istendiği için ve ilk sayıcının çıkışının periyodik olması gerektiği için iki sayıcı da mod 2'de çalıştırılır. (ekrandan, 00:10:00)
  - Mod 2'de GATE 0 iken sayma durur; bu yüzden simülasyonda iki sayıcının GATE ucu lojik 1'e (5 V) bağlıdır.
- Örnek 1'in adres çözümlemesi (Proteus devresi)
  - Ardışık tek adresler için 8254'ün D0-D7 uçları veri yolunun yüksek anlamlı yarısına (D8-D15) bağlanır.
  - A9H = 1010 1001, ABH = 1010 1011, ADH = 1010 1101, AFH = 1010 1111. Değişen bitler A2 ve A1'dir: işlemcinin A1'i 8254'ün A0'ına, A2'si 8254'ün A1'ine bağlanır. M/$\overline{IO}$ = 0 olmalıdır. (ekrandan, 00:15:00)
  - Sabit kalması gereken uçlar: A0 = A3 = A5 = A7 = 1; A4 = A6 = 0; M/$\overline{IO}$ = 0. Yedi koşul vardır, 74LS138'in altı girişi vardır; bu yüzden 0 olması gereken iki uç bir OR kapısıyla birleştirilip aktif sıfır bir izin ucuna verilir.
  - Proteus'taki devre: A0 → A, A5 → B, A7 → C, A3 → E1, A4 → $\overline{E2}$, A6 ve M/$\overline{IO}$ bir OR kapısından $\overline{E3}$'e. CBA = 111 olduğundan Y7 çıkışı 8254'ün $\overline{CS}$ ucunu sürer. (ekrandan, 00:20:00)
  - Hocanın tahtada çizdiği tasarımda OR kapısına M/$\overline{IO}$ ile A4 verilmiş, A6 doğrudan aktif sıfır izin ucuna bağlanmıştır; iki çözüm de aynı adresleri seçer.
- Örnek 1'in yazılımı
  - Kontrol sözcükleri ekrandan: `00110101B` (CNTR0, 16 bit, önce LSB sonra MSB, mod 2, BCD) ve `01110101B` (CNTR1, aynı ayarlar); ikisi de `OUT 0AFH, AL` ile kontrol yazmacına yazılır. (ekrandan, 00:25:00)
  - BCD sayıldığı için 2000 ve 1000 değerleri `2000H` ve `1000H` olarak yüklenir. BCD'de 2000'den sonra 1999 gelir; binary sayılsaydı 2000H'den sonra 1FFFH gelirdi.
  - İki değerin LSB'si 00H olduğu için `XOR AL, AL` ile AL sıfırlanıp önce iki sayıcıya LSB, sonra CNTR0'a `20H`, CNTR1'e `10H` MSB'leri gönderilir. Sayıcılar bağımsız olduğu için LSB/MSB yazımları iç içe yapılabilir.
  - BCD en fazla 9999'a kadar sayma değeri verir; daha büyük değerde binary zorunludur.
  - Ayardan sonra program boş döngüde bekler; 1 Hz pulse tamamen 8254 tarafından üretilir. Osiloskopta OUT0 pulse'ları arasında 1 ms (1000 Hz), OUT1 pulse'ları arasında 1 s ölçülür.
- 8254 örneği 2: frekansmetre
  - Frekansmetre, bir işaretin 1 saniyede kaç kez değiştiğini sayar; bu yüzden hassas bir 1 saniyelik süre gerekir.
  - 0,5 Hz'lik kare dalganın (2 s periyot) 1'de kaldığı 1 saniyede dış işaret sayılır, 0'da kaldığı 1 saniyede hesap yapılır.
  - CNTR0 ve CNTR1 kaskat bağlanır, ikisi de mod 3'te (kare dalga) 2000 ile yüklenir: $\frac{2\times10^6}{2000\times2000}=0{,}5\,\text{Hz}$. (ekrandan, 00:55:00)
  - Ölçülecek işaret CNTR2'nin CLK ucuna, OUT1 CNTR2'nin GATE ucuna bağlanır; böylece CNTR2 yalnız 1 saniye sayar, sonraki 1 saniye sayma durur.
  - 8254 adresleri bu örnekte F0H (CNTR0), F1H (CNTR1), F2H (CNTR2), F3H (kontrol). (ekrandan, 00:55:00)
  - CNTR2 mod 0'da, BCD, 9999 ile yüklenir (`10110001B`, sonra iki kez `99h`). En çok 9999 Hz ölçülür. Mod 0'da sayma bitince OUT 1'e çıkıp kalır; OUT2'nin 1 görülmesi taşma (overflow) demektir. (ekrandan, 01:00:00)
  - OUT1'in 0'a düştüğü an, read-back komutuyla (`0E4h`) CNTR1'in durum baytı okunup `ROL AL,1` ile OUTPUT biti carry'e alınarak beklenir (`JC stat`). (ekrandan, 01:00:00)
  - Sonra `C8H` read-back komutuyla CNTR2'nin hem sayma değeri hem durumu tutulur. İlk okuma durum baytıdır: OUTPUT = 1 ise taşma, 0 ise sonraki iki okuma LSB ve MSB'dir.
  - Sayıcı aşağı saydığı için geçen adım sayısı 9999'dan okunan değer çıkarılarak bulunur; BCD baytlarda bu, her bayt için 99'dan çıkarmadır. Örnek: okunan 3275 ise $9999-3275=6724\,\text{Hz}$. (ekrandan, 00:55:00)
  - Mod 0 tekrarlı değildir; sayma değeri her ölçüm döngüsünde yeniden yazılmalıdır.
- ADC ve DAC'ye giriş
  - Mikroişlemci sayısaldır, fiziki dünya analogdur (sıcaklık, basınç, nem, hız). Girdi için ADC, çıktı için DAC gerekir.
  - Örnek akış: fiziki dünya → sıcaklık (analog) → transducer → elektriksel analog → ADC → elektriksel dijital → μP → işlenmiş veri → DAC → elektriksel analog → transducer → fan hızı (analog). (ekrandan, 01:25:00)
  - Transducer bir enerji türünü elektriksel işarete (ya da tersine) çevirir. Sıcaklık için NTC/termistör, fan tarafında motorun kendisi transducer'dır.
- Analog ve sayısal işaret
  - Zamanda sürekli ve genliği sürekli: analog. Zamanda sürekli, genliği ayrık: ayrık genlikli işaret. Zamanda ayrık, genliği sürekli: ayrık zamanlı işaret. Hem zamanda hem genlikte ayrık: sayısal işaret. (ekrandan, 01:30:00)
  - Sayısal işaret, örneğin yalnız tamsayı tutan 100 elemanlı bir dizi gibidir.
- Binary weighted (ikili ağırlıklı) DAC
  - Opamplı evirici toplayıcıdır: V1 (MSB) R, V2 2R, V3 (LSB) 4R üzerinden; geri besleme direnci $4R/7$. (ekrandan, 01:35:00)
  - İdeal opamp: $V_n=V_p$, $i_p=i_n=0$. $V_p$ toprakta olduğu için $V_n=0$.
  - $V_{out}=-\left(\frac{V_1}{R}+\frac{V_2}{2R}+\frac{V_3}{4R}\right)\frac{4R}{7}$. Hepsi 5 V: −5 V; hepsi 0: 0 V; yalnız V1: −20/7 V; yalnız V2: −10/7 V; yalnız V3: −5/7 V. (ekrandan, 01:40:00)
  - En küçük dirençli kol en büyük katkıyı yapar (MSB). Sakıncası: bit sayısı kadar farklı direnç değeri ve her birinde hassas tolerans gerekir.
- R/2R merdiven DAC
  - Yalnız R ve 2R dirençleri kullanılır; toleransı ayarlanması gereken iki direnç türü vardır. (ekrandan, 01:45:00)
  - Thevenin eşdeğeriyle çözülür: LSB düğümünde $V_{th}=V_3/2$, $R_{th}=2R\parallel2R=R$. Seri R ile tekrar 2R olur, devre kendini tekrarlar. Katkılar: V1/2, V2/4, V3/8.
- DAC0830
  - 8 bitlik DAC entegresi; derste ve deneylerde hazır bağlantıyla, bir kara kutu gibi verilir: veri uçları (DI0-DI7), $\overline{CS}$, $\overline{WR}$ ve analog çıkış. (ekrandan, 01:50:00)
  - VREF'e −5 V bağlanır; evirici yapı nedeniyle çıkış 0 ile 5 V arasında olur. Akım çıkışları (IOUT1, IOUT2) harici bir opampa verilir, RFB geri besleme direncidir. (ekrandan, 01:55:00)
  - Adres ucu yoktur: $2^0=1$ bayt yer kaplar. Tek bir adres için adres çözümleme devresi $\overline{CS}$ üretir.
  - Örnek kod (1000H adresi): `MOV DX,1000H`, `MOV AL,00H`, döngüde `OUT DX,AL`, `CALL DELAY`, `INC AL`. Ardışık iki değer arasındaki gerilim farkı 5 V/256; FFH'den sonra AL 00H'ye döndüğü için çıkış testere dişi dalgadır. (ekrandan, 02:00:00)
  - Ders sonrası not: Hoca hem "FFH için 5 V" hem "adım 5 V/256" dedi. FFH tam 5 V verseydi adım 5 V/255 ≈ 19,6 mV olurdu. Gerçek DAC0830'da çıkış büyük olasılıkla $V_{REF}\cdot D/256$ biçimindedir; o zaman adım 5 V/256 ≈ 19,5 mV, FFH için çıkış ≈ 4,98 V olur.

## Hocanın Özellikle Vurguladığı Kısımlar

- Tek sayıcı yetmiyorsa kaskat bağlantı
  - Bir sayıcının OUT'u diğerinin CLK'ına bağlanır; toplam bölme oranı sayma değerlerinin çarpımıdır. İlk sayıcı periyodik bir modda (mod 2 ya da mod 3) çalışmalıdır.
- Durum okumak için read-back zorunludur
  - Counter latch komutu yalnız sayma değerini tutar. OUT ucunun durumunu öğrenmek için read-back komutu gerekir. Hem durum hem sayma tutulduysa ilk okuma durum baytıdır.
- Frekansmetre örneği bütüncül bir örnektir
  - Kaskat sayıcı, GATE ile sayma denetimi, mod 0 ile taşma algılama, read-back ve BCD hesap bir arada kullanılır. Hoca örneği incelemeyi ve üzerinde değişiklik yapmayı önerdi.
- Mod 0'da sayma değeri döngü içinde yeniden yazılmalıdır
  - Mod ayarı döngü dışında kalabilir, ama değer yazma satırları mutlaka döngü içinde olmalıdır.
- Adres ucu olmayan cihaz 1 bayt yer kaplar
  - "0 bayt" cevabı yanlıştır. 8254 ve 8255 iki adres ucuyla 4 bayt, DAC0830 adres ucu olmadığı için 1 bayt kaplar.
- R/2R'nin üstünlüğü
  - Binary weighted DAC'de bit sayısı kadar hassas direnç gerekir; R/2R'de yalnız iki tür direnç vardır.

## Kısa Tekrar Notları

- Tek 8254 sayıcısıyla 2 MHz'ten en düşük ≈30 Hz elde edilir ($2\times10^6/65536$).
- 1 Hz için 2000 × 1000 kaskat, ikisi de mod 2. Adresler A9H/ABH/ADH/AFH; kontrol AFH.
- Tek adresler → 8254 veri uçları D8-D15'e; işlemci A1 → 8254 A0, A2 → 8254 A1.
- 74LS138: üç seçim ucu (C en anlamlı), E1 aktif 1, $\overline{E2}$ ve $\overline{E3}$ aktif 0; çıkışlar aktif 0.
- BCD sayımda 2000 → `2000H` yüklenir; en büyük BCD sayma değeri 9999.
- `XOR AL,AL` = `MOV AL,0`, ama daha kısa sürer.
- Frekansmetre: CNTR0 ve CNTR1 mod 3 × 2000 → 0,5 Hz; OUT1 → GATE2; CNTR2 mod 0, BCD, 9999.
- Read-back: `E4H` = CNTR1 durum, `E8H` = CNTR2 durum, `C8H` = CNTR2 sayma + durum.
- Durum baytı: D7 OUTPUT, D6 NULL COUNT, D5-D0 RW1 RW0 M2 M1 M0 BCD.
- $f = 9999 - \text{okunan}$; 3275 → 6724 Hz.
- Sayısal işaret: hem zamanda hem genlikte ayrık.
- Binary weighted DAC: R, 2R, 4R; $V_{out}=-(V_1/R+V_2/2R+V_3/4R)\cdot 4R/7$.
- R/2R merdiven: iki direnç türü, Thevenin ile her kademede yarıya bölünme.
- DAC0830: 8 bit, VREF = −5 V → 0-5 V çıkış, IO uzayında 1 bayt, adım 5 V/256.
- AL'yi sürekli artırıp DAC'ye yazmak testere dişi dalga üretir.

## Detaylı Açıklamalar

- **Kaskat sayıcıyla 1 Hz pulse.** 8254'ün her sayıcısı 16 bitlik aşağı sayan bir frekans bölücüdür. Yazılabilecek en büyük değer 65535'tir, ama 0 yazıldığında sayıcı 65536 adım sayar. 2 MHz'lik saat tek sayıcıyla en fazla 65536'ya bölünebildiği için en düşük çıkış ≈30,5 Hz olur; 1 Hz için bölme oranı $2\times10^6$ olduğundan iki sayıcı zincirlenir. Hoca yuvarlak değerler olarak 2000 ve 1000'i seçer: ilk sayıcının çıkışı 1 kHz, ikincisinin çıkışı 1 Hz olur. Mod 2 (rate generator) uzun süre 1'de kalıp bir saat periyodu boyunca 0'a düşen periyodik bir pulse üretir; ikinci sayıcı birinci sayıcının bu pulse'ları ile saydığı için zincir çalışır. Simülasyonda osiloskopta OUT0 pulse'ları arası 1 ms, OUT1 pulse'ları arası 1 s ölçülmüştür.

- **Adres çözümleme.** Adreslerin hepsi tek olduğu için cihaz veri yolunun yüksek anlamlı baytına bağlanır. A9H, ABH, ADH, AFH'nin ikili yazımında yalnız A2 ve A1 değişir; bunlar 8254'ün A1 ve A0 uçlarına gider. Geriye kalan A0, A3, A5, A7 (1 olmalı), A4, A6 (0 olmalı) ve M/$\overline{IO}$ (G/Ç için 0) sabit koşullardır. 74LS138'in altı girişine yedi koşul sığmadığı için 0 olması gereken iki koşul OR kapısıyla birleştirilir: iki giriş de 0 iken 0 veren kapı OR'dur. Proteus devresinde A0, A5, A7 seçim uçlarına bağlandığı için doğru adreste CBA = 111 olur ve Y7 çıkışı $\overline{CS}$ olur.

- **BCD sayım ve kontrol sözcüğü.** Kontrol sözcüğünde D7-D6 sayıcı seçimi, D5-D4 okuma/yazma biçimi (11 = önce LSB sonra MSB), D3-D1 mod, D0 BCD/binary seçimidir. `00110101B` CNTR0'ı mod 2'de BCD sayacak biçimde ayarlar. BCD modunda sayma değeri onluk basamakların BCD karşılığıdır: 2000 için `20H` (MSB) ve `00H` (LSB) yazılır. BCD seçimi bu örnekte yeterli olduğu ve BCD'nin nasıl çalıştığını göstermek için yapılmıştır.

- **Frekansmetre.** 0,5 Hz'lik kare dalga 1 saniye 1'de, 1 saniye 0'da kalır. OUT1 CNTR2'nin GATE ucuna bağlandığından CNTR2 yalnız OUT1 = 1 iken sayar. CNTR2 mod 0'da 9999 (BCD) ile yüklenir; mod 0'da çıkış sayma değeri yüklenince 0'a düşer, sayma bitince 1'e çıkıp kalır. 1 saniye içinde 9999'dan fazla değişim olursa OUT2 1'e çıkar; bu, ölçüm aralığının aşıldığını (taşma) gösterir. Program önce read-back `E4H` (11 1 0 0 1 0 0: sayma tutulmaz, durum tutulur, CNTR1) ile CNTR1'in durum baytını okur. `ROL AL,1` en anlamlı biti (OUTPUT) carry'e taşır; carry 1 olduğu sürece döngü sürer. OUT1 0'a düşünce `C8H` (11 0 0 1 0 0 0: sayma ve durum birlikte, CNTR2) yazılır. İlk okunan bayt durum baytıdır; OUTPUT = 1 ise taşma işlenir (ekranda FF gösterilir), değilse LSB ve MSB okunur, her biri 99'dan çıkarılarak BCD basamaklar bulunur ve 8255 üzerinden 7 parçalı göstergelere yazılır. BCD'de 99'dan çıkarmada ödünç (borrow) oluşmadığı için iki bayt ayrı ayrı işlenebilir.

- **ADC/DAC ve işaret türleri.** Mikroişlemcili bir oda sıcaklığı kontrol sisteminde sıcaklık önce bir transducer (ör. NTC termistör, gerilim bölücüyle) ile gerilime, sonra ADC ile sayıya çevrilir. İşlemci karar verir (fanı hızlandır/durdur), DAC çıktıyı analog gerilime çevirir, motor (transducer) bunu açısal hıza çevirir.

- **Binary weighted DAC.** Opampın evirici girişi sanal topraktır; her koldan $V_i/R_i$ akım akar, opampa akım girmediği için hepsi geri besleme direncinden geçer. Böylece direnci en küçük kol (R) en büyük ağırlığı taşır ve MSB gibi davranır. Ağırlıklar 4:2:1'dir. Bu yapı çok bitli DAC'de çok farklı direnç değerleri ve her biri için hassas tolerans gerektirir.

- **R/2R merdiven DAC.** LSB kolunda kaynak, 2R ve topraktaki 2R bir gerilim bölücü oluşturur: $V_{th}=V_3/2$, $R_{th}=R$. Bu eşdeğerdeki R, merdivendeki seri R ile toplanıp 2R olur ve bir sonraki düğümde aynı yapı tekrar ortaya çıkar. Her kademede düşük anlamlı katkı yarıya bölünür; sonuçta katkılar V1/2, V2/4, V3/8 olur ve bunlar opampın 2R geri besleme direnciyle çıkışa aktarılır.

- **DAC0830.** 8 bitlik, adres ucu olmayan bir cihazdır; IO uzayında tek bir adres (1 bayt) kaplar. $\overline{CS}$ seçildikten sonra veri uçlarına yazma yapılır, belirli bir dönüşüm süresinden sonra çıkışta kararlı gerilim oluşur. Entegrenin içinde R-2R merdiveni ve geri besleme direnci vardır, opamp dışarıdan bağlanır. Örnek kodda AL 00H'den FFH'ye kadar birer artırılarak yazılır; her adımda çıkış 5 V/256 artar, FFH'den sonra AL 00H'ye döner ve çıkış 0 V'a düşer. Sonuç testere dişi dalgadır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
