# Ders 12 Çalışma Özeti

## Genel Konular

- Arayüzler dokümanı ve 8255 kontrol yazmacı tekrarı
  - Derste "arayüzler" adlı bir PDF kullanıldı: 8255 adresleme tablosu, BSR ve mod 0/1/2 kontrol yazmaçları, mod 1 ve mod 2 durum (status) kelimeleri, 8255 ve 8086 bacak şemaları ile 8086 bayrak yazmacı tek sayfada özetlenir (ekrandan, 00:15:00). Bitlerin anlamını ezberlemek gerekmez; doküman her şeyin özetini verir.
  - 8255'in A1A0 uçları: 00 port A, 01 port B, 10 port C (ve durum), 11 kontrol yazmacı (ekrandan, 00:15:00).
  - 80H'den başlayan çift adreslere yerleştirilmiş bir 8255'te 80H port A, 82H port B, 84H port C, 86H kontrol yazmacıdır (ekrandan, 00:20:00).
  - Kontrol yazmacının iki biçimi vardır ve D7 (MSB) belirler:
    - D7 = 0: bit set/reset (BSR) modu. D6-D4 önemsiz (X), D3-D1 port C'nin pin numarası ($B_2B_1B_0$, ikilik), D0 = S/R (1 set, 0 reset). Örnek: PC3'ü 1 yapmak için `0000 0111` = 07H, kontrol adresine (86H) gönderilir.
    - D7 = 1: mod seçimi (temel G/Ç). D6D5 grup A modu (00 mod 0, 01 mod 1, 1X mod 2), D4 port A, D3 port C üst (PC7-PC4), D2 grup B modu (0 mod 0, 1 mod 1), D1 port B, D0 port C alt (PC3-PC0). Yön bitinde 1 giriş, 0 çıkış (ekrandan, 00:15:00).
  - Grup A, port A ile port C'nin üst yarısını; grup B, port B ile port C'nin alt yarısını kontrol eder.
- Adres uzayına 8255 yerleştirme: şemadan adres çıkarma (ekrandan, 00:25:00 ve 00:30:00)
  - Proteus'taki 8086 demo kartında AD0-AD15 ve AD16-AD19, ALE ile tetiklenen üç adet 74273 mandal (latch) entegresiyle adres yoluna (A0-A19) ayrılır. Adres ve veri aynı bacakları paylaştığı için önce gelen adres mandallanır, sonra aynı uçlardan veri gönderilir.
  - Yonga seçimi 74LS137 (3'e 8 kod çözücü) ile yapılır: A5→A, A6→B, A7→C girişleri; Y3 çıkışı $\overline{CS8255}$'e gider. Y3'ün 0 olması için C B A = 0 1 1, yani A7 = 0, A6 = 1, A5 = 1 olmalıdır.
  - Etkinleştirme uçları: E1'e A0 bir DEĞİL kapısından gelir (A0 = 0 olmalı), E2'ye $M/\overline{IO}$ gelir (G/Ç seçimi için 0 olmalı), üçüncü uca A3 ile A4'ün VEYA'sı gelir (A3 = A4 = 0 olmalı).
  - CPU'nun A1 ve A2 uçları 8255'in A0 ve A1 uçlarına bağlıdır; port seçimi bunlarla yapılır.
  - Sonuç: A7-A0 = 0110 0xx0, yani port A = 60H, port B = 62H, port C = 64H, kontrol = 66H (python ile doğrulandı).
  - Tersten de gidilebilir: "8255'i 60H'ye yerleştir" denirse tek bir çözüm yoktur; kod çözücü girişleri ve kullanılan çıkış değiştirilebilir. Tek şart, entegrenin yalnız istenen adreste seçilmesidir; başka bir adreste de seçiliyorsa çözüm yanlıştır.
  - Kod çözücü, çok girişli VE kapıları yerine tercih edilir: birden fazla adres bitini tek entegrede değerlendirir, üçten fazla girişli kapı gerekmez.
- 4 buton, 4 LED örneği (mod 0)
  - Port C'nin alt yarısına (PC0-PC3) pull-up dirençli 4 buton, üst yarısına (PC4-PC7) 4 LED bağlı (ekrandan, 00:35:00 ve 00:40:00). Butona basılmadığında uç 1'dedir, basılınca 0'a düşer; anlamlı veri 0'dır.
  - Kontrol kelimesi: port C üst çıkış, port C alt giriş ve mod 0 olmalıdır. Hoca port A giriş, port B çıkış seçerek 91H (`1001 0001`) yazdı; programda kullanılan 81H (`1000 0001`) de aynı işi görür (yalnız port A'nın yönü farklı).
  - Proteus'ta kırmızı 1 (+5 V), mavi 0 seviyesini gösterir; 91H ile 81H arasındaki port A farkı simülasyonda gözlendi.
  - Program ve akışı kareden alındı (bkz. Detaylı Açıklamalar).
- Yedi parçalı (7 segment) gösterge (ekrandan, 00:50:00)
  - Ortak anotlu yapıda ortak uç 1 olmalı, yakılacak parçaya 0 verilir (söndürmek istenen parça 1'lenir). Ortak katotlu yapıda ortak uç 0 olmalı, yakılacak parçaya 1 verilir.
  - Parçalar a-g ve nokta (h) olarak bağlanır; derste son halinde h = D7 (MSB), a = D0 (LSB) alındı.
  - 0 rakamı: ortak anotta C0H (g ve h sönük), ortak katotta 3FH.
  - Demo kartta ortak anotlu gösterge port B'ye bağlıdır (ekrandan, 00:55:00); kontrol yazmacına 80H (bütün portlar çıkış, mod 0) gönderilir, rakam kodları veri bölütünde `DB` tablosu olarak tutulur ve 62H'ye (port B) yazılır; C0H ile 0 gösterildi.
- Tuş takımı (keypad)
  - Tuş takımı sütunlardan sürülür, satırlardan okunur. Pull-up dirençli yapıda sütun 0 ile sürülür ve satırda 0'a düşen uç aranır; pull-down yapıda sütun 1 ile sürülür ve 1 aranır.
  - Demo kartta 4x3 tuş takımının sütunları port A'dan (PA0-PA2) sürülür, satırları pull-up dirençlerle port C'nin alt yarısından (PC0-PC3) okunur (ekrandan, 01:00:00).
  - Kontrol kelimesi 81H (port A çıkış, port C alt giriş). Port A'ya FDH (`1111 1101`) yazılınca yalnız orta sütun (2, 5, 8, 0) 0 ile sürülür. Port C okunup `TEST AL, 02H` ile PC1 (ikinci satır) denetlenir; bu, 5 tuşuna basılıp basılmadığının kontrolüdür. Basıldıysa program "tuş var" etiketine atlar ve BL'ye FFH yazar.
- 8255 mod 1 ve mod 2'ye giriş
  - Mod 0: el sıkışma yok; veri gönderilir ya da okunur, karşı tarafın alıp almadığı denetlenmez.
  - Mod 1: port A ve port B için el sıkışmalı (handshake) G/Ç. Port C'nin uçları el sıkışma ve kesme sinyallerine ayrılır. Bir port ya giriş ya çıkıştır.
  - Mod 2: yalnız port A, çift yönlü (hem okuma hem yazma) el sıkışmalı çalışır; port B ayrıca mod 0 ya da mod 1 olabilir; port C yine el sıkışma sinyallerini taşır.
- BSR mod örneği (ekrandan, 01:10:00)
  - 80H'den itibaren çift adreslere yerleşmiş 8255'te PC2'yi lojik 1 yapın; PC6'da duty cycle'ı %66 olan kare dalga üretin.
  - PC2 için kontrol adresine (86H) 05H. PC6 için 0DH (set) ve 0CH (reset); set'ten sonra iki gecikme, reset'ten sonra bir gecikme konup döngüye alınır.
- Mod 1 bağlantıları ve sinyaller (ekrandan, 01:15:00 ve 01:20:00)
  - Grup A mod 1 kontrol kelimesi: D7 = 1, D6D5 = 01, D4 = port A yönü, D3 = boşta kalan iki port C ucunun yönü. Grup B: D2 = 1, D1 = port B yönü.
  - Port A giriş: PC4 = $\overline{STB_A}$, PC5 = $IBF_A$, PC3 = $INTR_A$, PC6-PC7 serbest G/Ç.
  - Port A çıkış: PC6 = $\overline{ACK_A}$, PC7 = $\overline{OBF_A}$, PC3 = $INTR_A$, PC4-PC5 serbest G/Ç.
  - Port B giriş: PC2 = $\overline{STB_B}$, PC1 = $IBF_B$, PC0 = $INTR_B$. Port B çıkış: PC2 = $\overline{ACK_B}$, PC1 = $\overline{OBF_B}$, PC0 = $INTR_B$. Port B mod 1'de PC0-PC2'yi kullanır; grup B mod 1 kontrol kelimesinde port C için serbest uç yönü seçilmez.
  - STB: karşı taraf "veri gönderiyorum" der. IBF: "veriyi aldım, tamponda tutuyorum". OBF: "çıkış tamponuma veri koydum, gönderiyorum". ACK: karşı taraf "veriyi aldım" der.
  - INTE A / INTE B iç kesme izin bayraklarıdır; BSR ile ilgili port C biti (giriş A için PC4, çıkış A için PC6, B için PC2) 1 yapılırsa kesme üretilebilir, 0 yapılırsa kesme kapanır.
  - Mod 1'de port C okunursa durum kelimesi elde edilir: IBF/OBF, INTE ve INTR bitleri buradan izlenir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bir entegreyi adres uzayına yerleştirmek
  - Hoca bunu 8086 dersinin anlaşılması gereken en önemli konusu olarak niteledi: 8086 mimarisi adres uzayındaki bir birime erişim üzerine kuruludur; önce adresle birim seçilir, adres mandallanır, sonra veri gönderilir.
- Adres çözme tasarımında tek doğru yok, tek şart var
  - Farklı kod çözücü bağlantıları kabul edilir; ama tasarlanan devre istenen adres dışında hiçbir adreste entegreyi seçmemelidir.
- Bit anlamları ezberlenmez
  - Kontrol yazmaçları, mod 1 port C bağlantıları ve durum kelimeleri arayüzler dokümanında vardır; önemli olan dokümanı doğru okumaktır.
- Mod 1'de port C uçlarının karıştırılması
  - En sık yapılan hata: port A çıkışken serbest olan PC4-PC5 yerine PC6-PC7'yi kullanmaya çalışmak. Port A giriş/çıkış seçimi, port C'nin hangi uçlarının serbest kaldığını belirler.
- Pull-up yapıda 0'ı kontrol et
  - Butona ya da tuşa basıldığını anlamak için ucun 0'a düşmesi denetlenir.
- 8255 sınavlarda en çok hata yapılan konudur; özellikle mod 0 iyi öğrenilmelidir.

## Kısa Tekrar Notları

- 8255 A1A0: 00 PA, 01 PB, 10 PC, 11 kontrol. 8086'da çift adres kullanılınca CPU A2A1 → 8255 A1A0.
- Kontrol yazmacı D7 = 0 → BSR, D7 = 1 → mod seçimi.
- BSR: `0 X X X B2 B1 B0 S/R`. PC3 set = 07H, PC2 set = 05H, PC6 set = 0DH, PC6 reset = 0CH.
- Mod 0 kelimesi: `1 0 0 PA PCu 0 PB PCl` (1 giriş, 0 çıkış). 80H hepsi çıkış; 81H yalnız PC alt giriş; 91H PA ve PC alt giriş.
- Demo karttaki 74LS137 bağlantısı 8255'i 60H/62H/64H/66H'ye yerleştirir.
- Ortak anot: 0 yakar; ortak katot: 1 yakar. "0" rakamı CA = C0H, CC = 3FH (h = MSB).
- Keypad: sütundan sür, satırdan oku; pull-up'ta 0 ile sür, 0 ara.
- Mod 1: A ve B el sıkışmalı, tek yönlü; mod 2: yalnız A, çift yönlü.
- Mod 1 port A giriş: PC4 STB, PC5 IBF, PC3 INTR; çıkış: PC6 ACK, PC7 OBF, PC3 INTR. Port B: PC2, PC1, PC0.
- INTE bitleri BSR ile set edilirse kesme açılır.

## Detaylı Açıklamalar

- Şemadan adres çıkarma. Kod çözücünün Y3 çıkışı etkin düşüktür ve 8255'in $\overline{CS}$ ucuna gider. Seçilen çıkıştan 0, diğerlerinden 1 çıktığı için Y3'ün seçilmesi C B A = 011 ister; bu girişlere sırasıyla A7, A6, A5 bağlı olduğundan A7 = 0, A6 = A5 = 1 olur. Kod çözücü etkin değilse girişlerin önemi kalmaz; bu yüzden etkinleştirme uçlarına bağlı bitler de çıkarılır: A0'ın değili etkin yüksek uca gittiği için A0 = 0, $M/\overline{IO}$ etkin düşük uca gittiği için G/Ç erişimi (isolated I/O), A3 ve A4'ün VEYA'sı etkin düşük uca gittiği için A3 = A4 = 0. Geriye kalan A2 ve A1, 8255'in port seçme uçlarıdır. Böylece adresler $0110\,0000_2$ = 60H (PA), 62H (PB), 64H (PC), 66H (kontrol) çıkar (ekrandan, 00:30:00).
- 4 buton 4 LED programı (ekrandan, 00:45:00):

  ```asm
  START:
          MOV AL, 81H
          OUT 66H, AL      ; PC alt giriş, diğerleri çıkış, mod 0
          MOV AL, 0FFH
          OUT 64H, AL      ; LED'ler (PC4-PC7) yanar
  ENDLESS:
          IN  AL, 64H      ; butonları oku (PC0-PC3)
          OR  AL, 0F0H     ; üst 4 bit 1
          CMP AL, 0FFH     ; hiçbir butona basılmadıysa FFH
          JZ  ENDLESS
          MOV CL, 4
          SHL AL, CL       ; buton bitlerini LED bitlerine kaydır
          OUT 64H, AL      ; basılan butona karşılık gelen LED söner
          JMP ENDLESS
  ```

  - `OR AL, 0F0H` üst yarıyı 1'ler; böylece karşılaştırma yalnız butonlara bağlı kalır ve kaydırmadan sonra basılmayan butonların LED'leri yanık kalır.
  - Hocanın örneği: alt yarı `1011` okunursa AL = FBH olur, FFH değildir; dört sola kaydırma ile AL = B0H (`1011 0000`) port C'ye yazılır ve PC6'daki LED söner (python ile doğrulandı).
- 7 segment kodlaması. h = D7, a = D0 sırasında "3" rakamı için a, b, c, d, g yanar; ortak anotta sönük kalacak e, f, h 1'lenir.

  > **Ders sonrası not:** Hoca önce a'yı MSB alarak `0000 1101` yazdı, sonra sırayı h = MSB olarak düzeltip "D0H" dedi. h = MSB sırasında doğru değer `1011 0000` = B0H'dir (bit sırası ters çevrilir, yarım baytlar yer değiştirmez).

- Mod 1 el sıkışma zamanlaması (derste çizimden anlatıldı). Giriş: karşı taraf $\overline{STB}$'yi 0'a çeker (veri gönderiyorum), 8255 veriyi mandallayıp IBF'yi 1 yapar (aldım); STB tekrar 1 olunca ve INTE açıksa INTR 1 olur; işlemci $\overline{RD}$ ile okuyunca INTR düşer. Çıkış: $\overline{WR}$ ile yazma yapılınca $\overline{OBF}$ 0'a düşer (gönderilecek veri hazır); karşı taraf $\overline{ACK}$ ile aldığını bildirir ve ardından INTR oluşur.

  > **Ders sonrası not:** Hoca kesme oluşumunu bir yerde "orlanması" diye anlattı; arayüzler dokümanındaki şemada INTR, INTE ile el sıkışma sinyallerinin VE kapısından çıkar (ekrandan, 01:15:00).

- Araştırma sorusu (derste çözülmedi): grup A mod 1 çıkış, grup B mod 1 giriş olarak ayarlanır ve port A port B'ye bağlanırsa el sıkışma için port C uçları nasıl bağlanmalıdır? Ayrıntı genişletilmiş nottadır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
