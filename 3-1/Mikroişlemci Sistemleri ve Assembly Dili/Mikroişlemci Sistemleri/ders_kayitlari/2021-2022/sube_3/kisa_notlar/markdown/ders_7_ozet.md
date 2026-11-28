# Ders 7 Çalışma Özeti

## Genel Konular

- Çevre birimleri (peripheral devices)
  - Çevre birimleri mikroişlemcinin dış dünyayla iletişimini sağlayan giriş ve/veya çıkış cihazlarıdır: LED yakıp söndürmek, bir düğmeden veri okumak gibi (ekrandan, 00:05:00).
  - Bir kod çözücüde (decoder) çıkışı doğrudan girişle seçeriz; mikroişlemcide ise çevre birimi, hafıza birimleri gibi belirli bir adres bölgesine yerleştirilir ve işlemci önce adres yolundan birimi seçer, sonra veri yolundan okur ya da yazar.
  - Hafıza birimine göre adres genişliği dardır (slaytta 1-4 byte). Çevre birimlerine erişim iki komutla yapılır: `OUT` (porta yaz) ve `IN` (porttan akümülatöre oku).
  - Sabit (fixed) adresli G/Ç 8 bitlik adres kullanır (00H-0FFH, adres komutta doğrudan yazılır). Değişken (variable) adresli G/Ç 16 bitlik adresi `DX` yazmacı üzerinden verir (0100H-0FFFFH aralığı yalnız bu yolla erişilir).
  - G/Ç işlemi 8 ya da 16 bit olabilir: `AL` ile 8 bit, `AX` ile 16 bit veri gönderilebilir.
- G/Ç haritalama yöntemleri (ekrandan, 00:10:00)
  - Isolated I/O: $M/\overline{IO}$ ucu adres çözümlemede kullanılır. Bellek (20 bit, 1 MB) ve G/Ç (16 bit, 64 KB) ayrı uzaylardır; aynı sayısal adres ($M/\overline{IO}$ ucuna göre) ya bellekteki ya da G/Ç uzayındaki gözü gösterir. Erişim için ayrı komutlar (`IN`, `OUT`) vardır.
  - Memory mapped I/O: $M/\overline{IO}$ ucu kullanılmaz. Tek adres uzayı vardır, G/Ç birimleri bu uzayın bir bölümüne gömülür; hafıza komutlarıyla (`MOV`) erişilir, ayrı komut ve G/Ç-hafıza ayıran fiziki uç gerekmez (ekrandan, 00:15:00). Bellek için 1 MB eksi ayrılan alan kalır.
  - Derste ve lablarda genelde isolated yöntem kullanılır.
- Düğme arayüzü
  - Düğmelerde basıldığı anda mekanik titreşimden kaynaklanan sıçrama (bouncing) olur; çıkış hemen sabit seviyeye oturmaz, birkaç kez salınır.
  - Yazılımda bastıktan sonra bir gecikme (delay) koyarak ya da donanımda flip-flop gibi bir debounce devresiyle bu salınım bastırılır.
  - Tercih edilen yapı: giriş ucu normalde 1'dedir, düğmeye basılınca 0'a düşer; işlemcinin 0'ı algılaması daha kolaydır.
  - Altı devreli sorunun doğru cevabı: düğme bir ucuyla toprağa, diğer ucuyla 10 kΩ'luk direnç üzerinden +5 V'a bağlı (pull-up) ve bu düğüm 8086'ya giden yapı (ekrandan, 00:20:00).
- LED arayüzü
  - LED doğrudan mikroişlemci ucundan beslenmez; uç yalnız tetikleme (kontrol) sinyali üretir.
  - Uç bir transistörün beyzini sürer, transistör iletime geçince LED +5 V'tan beslenir ve yanar. Simülasyonda (Proteus) doğrudan bağlantı çalışsa da gerçek devrede kullanılmaz.
- Basit çevre birimleri için adres çözümleme (ekrandan, 00:25:00)
  - Bellek: A19-A(i+1), değişken G/Ç: A15-A(i+1), sabit G/Ç: A7-A(i+1) bitleri adres çözümleme devresine gitmelidir.
  - Örnek: 0F000H adresine 8 LED. 74245 tamponu (transceiver) kullanılır; DIR=5 V (A→B, yazma yönü), etkin düşük $\overline{E}$ ucu adres kod çözme kapısından sürülür. Kapı yalnız A15-A12=1, diğer adres bitleri 0, $\overline{WR}$=0 ve $M/\overline{IO}$=0 iken $\overline{E}$'yi 0 yapar (ekrandan, 00:30:00).
  - Kod: `mov al, 55h` / `mov dx, 0F000h` / `out dx, al`. 55H = 01010101b, yani LED'ler bir yanık bir sönük deseni gösterir.
  - Aynı adrese 8 düğme: DIR=GND (B→A, okuma yönü), kapıda $\overline{WR}$ yerine $\overline{RD}$ kullanılır; `mov dx, 0F000h` / `in al, dx` ile okunur (ekrandan, 00:35:00).
- Çevre birimi kontrol yöntemleri
  - Yoklama (polling): öncelikli yoklamada birinci birim işi bitene kadar tekrar tekrar kontrol edilir, bitince sıradakine geçilir, her adımda başa dönülür. Sıralı (round robin) yoklamada birimler sırayla kontrol edilir, başa dönülmeden döngü sürer.
  - Kesme (interrupt): birim bir kesme ürettiğinde işlemci ona gider. Günümüzde daha çok kullanılır; ilerleyen haftalarda işlenecek.
- 8255 programlanabilir çevre birimi arayüzü (PPI)
  - Üç adet 8 bitlik genel amaçlı port (A, B, C) ve 8 bitlik veri yolu vardır.
  - Uçlar: D0-D7, A1-A0 (port seçimi), $\overline{RD}$, $\overline{WR}$, $\overline{CS}$ (yonga seçimi, adres çözümlemeyle sürülür), RESET.
  - A1A0: 00 port A, 01 port B, 10 port C, 11 kontrol yazmacı (ekrandan, 00:50:00).
  - Port A grup A'ya, port B grup B'ye bağlıdır; port C ikiye bölünür: üst 4 biti (PCH) grup A'da, alt 4 biti (PCL) grup B'dedir ve ayrı ayrı giriş ya da çıkış yapılabilir.
  - Mod 1 ve mod 2'de port C kontrol ve durum sinyalleri için kullanılır.
- 16 bitlik veri yolunda 8 bitlik çevre birimi
  - 8086'da düşük bayt (D0-D7) çift adreslerde ($A0=0$), yüksek bayt (D8-D15) tek adreslerde ($\overline{BHE}=0$) aktarılır.
  - Yalnız çift adresler (F8H başlangıç): F8H, FAH, FCH, FEH; CPU A2-A1 → 8255 A1-A0; 3'e 8 kod çözücüye A5-A4-A3 girer, Y7 çıkışı $\overline{CS}$'ye gider; $M/\overline{IO}$ ve A0 etkin düşük girişlere, A7·A6 (VE kapısı) etkin yüksek girişe bağlanır (ekrandan, 00:55:00 ve 01:00:00).
  - Yalnız tek adresler: F9H, FBH, FDH, FFH; aynı tasarımda A0 bir DEĞİL kapısından geçer, 8255 veri yolu yüksek bayta (D8-D15) bağlanır.
  - Hem çift hem tek adresler (C0H başlangıç): C0H port A, C1H port B, C2H port C, C3H kontrol; CPU A1-A0 doğrudan 8255 A1-A0'a gider. Kod çözücü (A4-A3-A2) Y0 çıkışı, A0 ile birleşerek düşük bayt tamponunu, $\overline{BHE}$ ile birleşerek yüksek bayt tamponunu etkinleştirir (ekrandan, 01:05:00).
- 8255 modları ve kontrol yazmacı (ekrandan, 01:20:00 ve 01:25:00)
  - Mod 0: Basic I/O, Bit Set/Reset modu, Mod 1: Strobed I/O, Mod 2: Bi-directional Bus.
  - Mod seçme kontrol sözcüğü: D7=1 (mode set flag), D6-D5 grup A modu (00 mod 0, 01 mod 1, 1X mod 2), D4 port A, D3 port C üst, D2 grup B modu (0 mod 0, 1 mod 1), D1 port B, D0 port C alt; giriş için 1, çıkış için 0.
  - D7=0 olunca kontrol sözcüğü bit set/reset sözcüğüdür: seçilen bir bit doğrudan 1 ya da 0 yapılır.
  - Mod 0: el sıkışma (handshake) ve kesme yoktur; doğrudan porttan okuma ve porta yazma yapılır. İki 8 bitlik (A, B) ve iki 4 bitlik (PCH, PCL) port vardır; bir portun tek tek bitleri farklı yönde ayarlanamaz. Mod 0'da 16 farklı yön birleşimi oluşur.

## Hocanın Özellikle Vurguladığı Kısımlar

- Adres yolu ve veri yolu ayrımı
  - Önce adres yolundan birim seçilir, sonra veri yolundan veri gönderilir. Ortak (çoklanmış) yol kullanıldığı için adresin bir mandal (latch) devresinde tutulması gerekir.
- Düğmede 0'ın algılanması
  - Basılınca 0'a düşen yapı tercih edilir; 8086 ucunun doğrudan +5 V'a bağlanması yerine koruma direnci kullanılmalıdır.
- A0-A1 = 11 durumu "çok önemli"
  - 8255'te A1A0=11 verildiğinde portlarla ilgisi kalmaz; gönderilen veri entegreyi programlayan kontrol sözcüğüdür. Programlanabilir çevre birimi denmesinin nedeni budur.
- Kontrol sözcüğü şablonu ezberlenmez
  - Lab ve sınavda arayüz tabloları elde olacağı söylendi; önemli olan tabloyu yorumlamaktır.
- Adres çözümleme tasarımı tek değildir
  - Kod çözücüye A3-A5 yerine A5-A7 bağlamak gibi farklı tasarımlar da doğrudur; amaç $\overline{CS}$'nin yalnız istenen adreslerde etkin olmasıdır.
- 8255'i kullanmadan önce kontrol sözcüğü yazmak zorunludur.
- 16 bit verinin tek 8255 ile aktarımı tek seferde değil, iki çevrimde (önce bir bayt, sonra diğeri) olur.

## Kısa Tekrar Notları

- Isolated I/O: $M/\overline{IO}$ adres çözümlemede kullanılır, `IN`/`OUT`; memory mapped I/O: kullanılmaz, `MOV`.
- Sabit G/Ç: 8 bit adres (00H-0FFH); değişken G/Ç: `DX` ile 16 bit adres.
- Düğme: pull-up dirençli, basınca 0 veren yapı; bouncing için gecikme ya da debounce devresi.
- LED: uç transistörü sürer, LED doğrudan uçtan beslenmez.
- 74245: DIR=1 A→B, DIR=0 B→A, $\overline{E}$=0 iken çalışır; adres çözümleme $\overline{E}$'yi sürer.
- 0F000H LED örneği: `mov al,55h` / `mov dx,0F000h` / `out dx,al`.
- Düğme bekleme döngüsü: `L1: in al,dx` / `cmp al,0FFh` / `je L1` (basılana kadar döner).
- 8255: A1A0 = 00 A, 01 B, 10 C, 11 kontrol.
- Yalnız çift adres: F8H, FAH, FCH, FEH (CPU A2-A1 → 8255 A1-A0). Yalnız tek: F9H, FBH, FDH, FFH. Çift+tek: C0H-C3H (CPU A1-A0 → 8255 A1-A0, $\overline{BHE}$ ile).
- 93H = 1001 0011b: mod set, grup A mod 0, port A giriş, PC üst çıkış, grup B mod 0, port B giriş, PC alt giriş.

## Detaylı Açıklamalar

- Mikroişlemci ile çevre birimi arasındaki temel fark, birimin bir adres uzayına yerleştirilmesidir. 8086'nın 20 bitlik adres yolu belleği (1 MB) adreslerken, G/Ç uzayı 16 bitliktir (64 KB). Isolated yöntemde $M/\overline{IO}$ ucu 1 iken bellek, 0 iken G/Ç uzayı seçilir; böylece "32 numaralı adres" ucun değerine göre ya bellekteki ya da G/Ç uzayındaki 32. göz olur. Bu yöntem programlamayı kolaylaştırır (ayrı `IN`/`OUT` komutları), ama G/Ç için ayrı bir uzay tanımlamayı gerektirir. Memory mapped yöntemde ise G/Ç birimleri bellek uzayının bir bölümünü kaplar ve `MOV` komutlarıyla erişilir.
- 0F000H LED örneğinde adres kod çözme kapısı, $\overline{WR}$ ve $M/\overline{IO}$ dahil bütün ilgili sinyalleri birleştirir. Tek bir bit bile farklı gelirse kapının çıkışı 1 olur, 74245 etkinleşmez ve LED'lere veri yansımaz. Slayttaki çok girişli kapı yalnız mantığı göstermek içindir; gerçekte bu kadar girişli kapı yoktur, kod çözücü kullanılır (ekrandan, 00:30:00).
- Düğme okuma örneğindeki döngü, okunan değer 0FFH olduğu sürece (hiçbir düğmeye basılmamış, bütün girişler pull-up ile 1) `L1` etiketine döner. Bir düğmeye basılınca ilgili bit 0 olur (örneğin 5. bit için DFH), değer 0FFH'ye eşit olmaz ve döngüden çıkılır (ekrandan, 00:35:00).
- 8255 çift adreslere yerleştirildiğinde CPU'nun A0'ı her zaman 0 olduğundan port seçimi için A1-A0 kullanılamaz; bunun yerine CPU'nun A2 ve A1 uçları 8255'in A1 ve A0'ına bağlanır. F8H = 1111 1000b olduğundan kod çözücü girişleri (A5-A4-A3) 111 olur ve Y7 çıkışı $\overline{CS}$'yi sürer. Hem tek hem çift adreslerin kullanıldığı C0H örneğinde ise 8255'in tek bir veri yolu, iki 74245 tampon üzerinden bir çevrimde düşük bayta, bir çevrimde yüksek bayta bağlanır: A0=0 düşük bayt tamponunu, $\overline{BHE}$=0 yüksek bayt tamponunu etkinleştirir.
- Kontrol sözcüğü örneğinde önce kontrol yazmacının adresi (C3H) `DX`'e yüklenir, sonra 93H bu adrese `OUT` ile gönderilir. 93H = 1001 0011b: D7=1 mod seçme sözcüğüdür; D6-D5=00 grup A mod 0; D4=1 port A giriş; D3=0 port C üst çıkış; D2=0 grup B mod 0; D1=1 port B giriş; D0=1 port C alt giriş (ekrandan, 01:30:00). Bu ayarda port A'ya LED bağlamanın anlamı yoktur, çünkü port A giriş olarak tanımlanmıştır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
