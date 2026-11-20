# Ders 17 Çalışma Özeti

## Genel Konular

- Sayıcı ile zamanlayıcı ayrımı
  - Sayıcıda CLK girişine olay tetiklemeli (event trigger) bir kare dalga bağlanır: olay oldukça bir darbe gelir, darbeler arası süre düzensizdir. Örnekler: montaj hattında lazer alıcı-verici arasından geçen ürünler, ayakkabı tabanındaki düğmeyle adım sayma.
  - Zamanlayıcıda CLK girişine sabit frekanslı bir saat bağlanır (örneğin kristal osilatörden elde edilen kare dalga). Böylece her darbeden sonra geçen süre bilinir.
  - İkisi arasındaki temel fark, CLK ucuna bağlanan işaretin periyodik olup olmamasıdır.
- 8254 Programlanabilir Aralık Zamanlayıcısının (PIT) tekrarı
  - 3 bağımsız, 16 bitlik, aşağı sayan (down counter) sayıcı; veri yolu 8 bit olduğu için 16 bitlik değer iki seferde yazılır.
  - Her sayıcı mod 0-mod 5 arasındaki 6 moddan birinde programlanır; CLK girişine 8 MHz'e kadar işaret bağlanabilir.
  - Sayıcı bir frekans bölücüdür: yüklenen sayma değeri, CLK frekansını o değere böler (ekrandan, 00:25:00).
  - Uçlar: CLK saat girişi, GATE dış kontrol ucu (bazı modlarda saymayı duraklatır, bazılarında yeniden başlatır), OUT çıkışı (sayma bitince değişir, INTR için kullanılabilir) (ekrandan, 00:30:00).
  - A1 A0 = 00 Counter 0, 01 Counter 1, 10 Counter 2, 11 kontrol yazmacı; cihaz G/Ç uzayında 4 bayt yer kaplar. 16 bitlik işlemciyle ardışık çift ya da ardışık tek adreslerle arabirim yapılır.
- Kontrol sözcüğü: SC1 SC0 | RW1 RW0 | M2 M1 M0 | BCD
  - SC1 SC0 sayıcıyı seçer; 11 özel durumdur (read-back komutu).
  - RW1 RW0: 01 yalnız LSB, 10 yalnız MSB, 11 önce LSB sonra MSB; 00 özel durumdur (counter latch komutu).
  - RW = 11 seçildiyse sayıcı MSB de yazılmadan saymaya başlamaz; üst bayt 00 olsa bile gönderilmelidir.
  - M2 M1 M0: mod 2 ve mod 3'te M2 önemsizdir (X10, X11); diğer modlar 3 bitle yazılır (örneğin 101 = mod 5).
  - BCD = 0 ikili sayma (en büyük değer FFFFH, 0 dahil 65536 adım), BCD = 1 BCD sayma (en büyük 9999, 0 dahil 10000 adım).
- 8254 modları (ekrandan, 00:35:00)
  - Mod 0, Interrupt on Terminal Count: kontrol sözcüğü yazılınca OUT 0 olur; sayma değeri yazıldıktan sonra CLK'nin düşen kenarlarında azalır, 0'a ulaşınca OUT 1 olur ve öyle kalır. GATE = 0 saymayı duraklatır. Yalnız yazılımla (yeni sayma değeri yazarak) yeniden başlatılan tek seferlik moddur.
  - Mod 1, Hardware Retriggerable One Shot: sayma değeri yazıldığı halde sayma başlamaz, GATE'ten tetik bekler. Tetikle OUT 0 olur, sayma bitince 1 olur. Her yeni GATE tetiği aynı sayma değeriyle işlemi tekrarlar; arada yazılan yeni değer bir sonraki tetikte geçerli olur.
  - Mod 2, Rate Generator: periyodik; OUT sayma süresince 1'dir, sayma bitince bir CLK süresi 0'a iner, sonra aynı değerle tekrarlar. Aktif sıfır darbe katarı üretir. GATE saymayı durdurur.
  - Mod 3, Square Wave Generator: periyodik; yaklaşık %50 görev oranlı kare dalga. Tek sayıda değer yüklenirse OUT bir CLK fazla 1'de kalır (5 için 3 CLK 1, 2 CLK 0).
  - Mod 4, Software Triggered Strobe: mod 2'nin tek seferlik hali; OUT baştan 1, sayma bitince bir CLK süresi 0, sonra 1'de kalır. Yeni sayma değeri yazılmadıkça tekrarlamaz (ekrandan, 01:05:00).
  - Mod 5, Hardware Triggered Strobe: mod 4'ün aynısı, ama GATE tetiğiyle başlar ve her tetikte tekrarlar.
- Sayıcı iç yapısı
  - Sayma işlemini fiziksel olarak count element (CE) yapar.
  - Yazılan sayma değeri önce CR (counter register) LSB/MSB yazmaçlarına gider, oradan CE'ye aktarılır.
  - OL (output latch) yazmaçları CE'nin o anki değerinin kopyasını tutar; CE saymaya devam eder.
  - Status latch, iç durum yazmacının dışarıdan okunabilen kopyasıdır.
- Counter latch komutu (ekrandan, 01:10:00)
  - Kontrol adresine (A1 A0 = 11) SC1 SC0 | 0 0 | X X X X yazılır. Seçilen sayıcının anlık değeri OL'ye kopyalanır.
  - Sonra sayıcının kendi adresinden okunur; okuma sırası programlanmış RW ayarıyla aynıdır (16 bit ise önce LSB, sonra MSB).
- Read-back komutu (ekrandan, 01:15:00)
  - D7 D6 = 11; D5 = 0 sayma değerini latch'le, D4 = 0 durumu latch'le (ikisi de aktif sıfır); D3, D2, D1 sırasıyla Counter 2, 1, 0'ı seçer.
  - Birden fazla sayıcı için tek komutla latch yapılabilir.
  - Hem durum hem sayma latch'lendiyse sayıcı adresinden ilk okuma durumu, ikinci (ve üçüncü) okuma sayma değerini verir.
  - Latch'lenen değer okunmadan aynı değer için yeni latch komutu etkisizdir.
- Durum baytı (status byte) (ekrandan, 01:20:00)
  - D7 OUTPUT (OUT ucunun değeri), D6 NULL COUNT (1: null count, 0: sayma değeri okunabilir), D5-D0 sayıcının programlandığı RW1 RW0 M2 M1 M0 BCD değerleri.
  - Read-back komutundan sonra sayıcının kendi adresinden okunur.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sayıcı bir frekans bölücüdür
  - Gereken sayma değeri = CLK frekansı / istenen çıkış frekansı. 2 MHz'den 1 kHz için 2000 yüklenir.
- Kontrol sözcüğü kontrol adresine, sayma değeri sayıcının kendi adresine yazılır
  - Mod 2 örneğinde hoca, sayma değerinin kontrol adresine değil Counter 0 adresine gönderilmesi gerektiğini ayrıca vurguladı.
- BCD modda değer onaltılık basamaklarla yazılır
  - BCD modda 2000 adım için 2000H yazılır; ikili modda aynı sonuç için 2000 (onlu) ya da 07D0H yazılır.
- Read-back sonrasında okuma sırası
  - Hem durum hem sayma latch'lendiyse önce durum, sonra sayma değeri okunur. Hoca bunu "çok önemli" diye belirtti.
- Durum baytı sayıcı adresinden okunur
  - Hoca önce kontrol sözcüğünden okunduğunu söyleyip sonra düzeltti: read-back komutundan sonra ilgili sayıcının adresinden okunur.

## Kısa Tekrar Notları

- Sayıcı: düzensiz olay darbeleri; zamanlayıcı: sabit frekanslı saat.
- 8254: 3 × 16 bit aşağı sayıcı, 8 bit veri yolu, 6 mod, A1 A0 ile 4 adres.
- Kontrol sözcüğü: SC1 SC0 | RW1 RW0 | M2 M1 M0 | BCD.
- 10H: Counter 0, yalnız LSB, mod 0, ikili. 12H: aynı, mod 1. 14H: mod 2. 16H: mod 3.
- Mod 0 ve mod 4 yazılımla, mod 1 ve mod 5 GATE ile yeniden başlatılır; mod 2 ve mod 3 periyodiktir.
- Mod 2: bir CLK'lik aktif sıfır darbeler; mod 3: %50 kare dalga.
- 50 µs periyot, CLK0 = 2 MHz: sayma = 100 = 64H, kontrol sözcüğü 14H.
- 1 kHz kare dalga, CLK1 = 2 MHz: sayma = 2000; BCD ile 77H + 2000H, ikili ile 76H + 2000 ya da 07D0H.
- Counter latch: SC | 00 | XXXX; read-back: 11 | COUNT STATUS (aktif sıfır) | CNT2 CNT1 CNT0 | 0.
- Durum baytı: OUTPUT, NULL COUNT, RW1 RW0 M2 M1 M0 BCD.

## Detaylı Açıklamalar

- **Kontrol sözcüğünün çözümü.** Mod 0 dalga şeklinde kontrol sözcüğü 10H'dir (ekrandan, 00:40:00). İkilik açılımı 00 01 000 0'dır: SC = 00 Counter 0, RW = 01 yalnız LSB, M = 000 mod 0, BCD = 0 ikili sayma. Aynı mantıkla mod 1 şeklindeki 12H (00 01 001 0) mod 1'i, mod 2 şeklindeki 14H mod 2'yi, mod 3 şeklindeki 16H mod 3'ü seçer. Dalga şekillerinde "N" ile gösterilen adımlar null count adımlarıdır: kontrol sözcüğü yazılmış ama sayma değeri henüz sayıcıya aktarılmamıştır.
- **Sayma değerinin yüklenmesi.** Yazılan değer doğrudan sayıcıya gitmez, önce geçici bir yazmaca (CR) yazılır. CLK'nin ilk düşen kenarında CE'ye aktarılır, sonraki düşen kenarlarda birer azalır. Mod 0 şeklinde LSB = 3 yüklenince değerler 3, 2, 2, 2, 1, 0 diye ilerler: GATE'in 0 olduğu süre boyunca sayma 2'de beklemiş, OUT'un 0'da kalma süresi o kadar uzamıştır (ekrandan, 00:40:00).
- **Mod 2 örneği** (ekrandan, 00:50:00). Counter 0, CLK0 = 2 MHz iken 50 µs'de bir darbe üretecek. Darbenin frekansı $1/(50\times10^{-6}) = 20$ kHz'dir. Sayma değeri $\dfrac{2\times10^6}{1/(50\times10^{-6})} = 100 = 64\text{H}$ olur. 100 sekiz bite sığdığı için RW = 01 (yalnız LSB) seçilir, değer ikili gönderilir. Kontrol sözcüğü 00 01 010 0 B = 14H'dir. Kod (ekrandan, 00:55:00):

  ```asm
  MOV AL, 14H
  OUT CONTROL_ADDRESS, AL
  MOV AL, 64H
  OUT CNTR0_ADDRESS, AL
  ```

- **Mod 3 örneği** (ekrandan, 01:00:00). Counter 1, CLK1 = 2 MHz iken 1 kHz kare dalga. Sayma değeri $\dfrac{2\times10^6}{1\times10^3} = 2000$. 2000 sekiz bite sığmaz; RW = 11 (önce LSB, sonra MSB) seçilir. Mod 3 ve BCD sayma ile kontrol sözcüğü 01 11 011 1 B = 77H olur. BCD modda 2000 adım için sayıcıya 2000H yazılır. Hoca aynı sonucu veren üç yolu gösterdi: BCD mod (77H) ile 2000H; ikili mod (76H) ile onlu 2000; ikili mod (76H) ile 07D0H. 16 bitlik değer AX'e alınır, önce AL, sonra `MOV AL, AH` ile üst bayt AL'ye taşınıp yine sayıcı adresine yazılır.
- **Okuma komutları.** Counter latch yalnız sayma değerini OL'ye kopyalar. Read-back hem sayma değerini hem durumu, istenirse birden fazla sayıcı için tek komutla latch'ler. Durum baytının D7 biti OUT ucunun o anki değeridir; böylece OUT ucu donanımsal olarak izlenmeden yazılımla öğrenilebilir.

> **Ders sonrası not:** Hoca mod 1'de saymanın GATE'in "sıfır geçişinde", "1-0 geçişinde" başladığını söyledi (00:45:49, 00:55:21). Slayttaki dalga şeklinde ve 8254 veri sayfasında tetik, GATE'in yükselen kenarıdır (0→1). Mod 5 için hocanın söylediği "0-1 geçişi" doğrudur.

> **Ders sonrası not:** Hoca mod 2'yi anlatırken bir CLK'lik 0 darbesinden sonra "tekrar sayma süresi boyunca sıfırda kalıyor" dedi (00:47:31). Doğrusu, OUT sayma süresi boyunca 1'de kalır; hoca hemen sonra da aynı şekli bu biçimde çizdi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
