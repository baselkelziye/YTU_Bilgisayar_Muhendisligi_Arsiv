# Ders 3 Çalışma Özeti

## Genel Konular

- 8086'nın 16 bit ve 20 bit yapısı
  - 8086 16 bitlik bir mikroişlemcidir: iç yazmaçları 16 bitlik veri tutar, yani bir yazmaç `0000H` ile `FFFFH` arasında değer alabilir.
  - Adres yolu 20 bittir. 20 bit ile $2^{20} = 1\,048\,576$ farklı hafıza gözü adreslenir. Her göz 1 bayt tuttuğu için adres uzayı 1 MB'tır.
  - Bayt kavramı mikroişlemciden değil hafıza bloğundan gelir: 20 bit adres "1 milyon satır" seçer, her satır 8 bit olduğu için toplam 1 MB eder.
  - Aynı mantıkla 32 bit adresli bir işlemci $2^{32}$ bayt, yani 4 GB adresleyebilir.
- 8086 iç yapısı: EU ve BIU (ekrandan, 00:10:00)
  - Execution Unit (EU): AH/AL, BH/BL, CH/CL, DH/DL genel amaçlı yazmaçları; SP, BP, DI, SI; geçici yazmaçlar, ALU, bayraklar ve EU kontrol birimi.
  - Bus Interface Unit (BIU): CS, DS, SS, ES segment yazmaçları, IP, iç iletişim yazmaçları, adresi üreten toplama (summation) birimi, 20 bitlik adres yolu, veri yolu, yol kontrolü ve 6 baytlık komut kuyruğu.
- Segment mimarisi
  - Çelişki: yazmaçlar 16 bit, adres yolu 20 bit. Örneğin `F2F3EH` gibi 5 haneli bir adres tek bir 16 bitlik yazmaca sığmaz (ekrandan, 00:20:00).
  - Çözüm: hafıza segmentlere ayrılır. İlk 16 bitlik değer segmentin başlangıcını, ikinci 16 bitlik değer segment içindeki ofseti verir.
  - Fiziksel adres $= \text{segment} \times 10H + \text{ofset}$. $10H$ ile çarpmak, onaltılık sayıyı bir hane sola kaydırmak (sağına 0 eklemek) demektir.
- Yazmaçlar
  - AX (akümülatör): en çok kullanılan yazmaç; veri transferi, çarpma/bölmede gizli operand, DX ile birlikte giriş/çıkış komutları.
  - BX (base): dizi biçimindeki veri bloklarında taban adresi.
  - CX (count): döngü ve öteleme sayacı.
  - DX (data): port numarası, çarpma/bölmede yardımcı.
  - SP: yığının en üst adresi; SS ile kullanılır, her zaman çift değer gösterir, WORD tipinde veriyi gösterir (ekrandan, 00:30:00).
  - BP: SS ile kullanılır; yığındaki veriye erişim ve parametre aktarımı.
  - SI, DI: dizi komutlarında kaynak ve hedef indisi.
  - IP: sıradaki işlenecek komutu gösterir, CS ile kullanılır; efektif program adresi $CS \times 10H + IP$ (ekrandan, 00:35:00).
- Bayrak yazmacı
  - CF (elde), PF (eşlik), AF (yardımcı elde, 4 bitlik kısım), ZF (sıfır), SF (işaret), TF (tuzak), IF (kesme izni), DF (yön), OF (işaretli taşma).
- Real mod ve protected mod
  - Real modda segment ve ofset birleşimiyle 1 MB'lık fiziksel adres uzayına erişilir. Derste ve uygulamalarda real mod kullanılacak.
  - Protected mod 1 MB'tan fazla hafızayı tablolar aracılığıyla kullanır; bu derste kullanılmayacak.
- Veri adresleme modları
  - Genel yapı: `MOV hedef, kaynak` (ekrandan, 00:55:00).
  - Yazmaç adresleme, anında (immediate) adresleme, doğrudan adresleme, yazmaç dolaylı adresleme, taban+indis, yazmaç göreli ve taban göreli+indis adresleme.
- Program hafızası adresleme
  - Doğrudan (CS ve IP'ye yeni değer), göreli (mevcut IP'den belirli kadar ileri/geri) ve dolaylı (bir yazmacın gösterdiği adrese) dallanma; `JMP`, `CALL` gibi komutlarla.
- Yığın adresleme
  - `PUSH` ve `POP` ile LIFO yapısı; her işlem bir WORD (2 bayt) taşır, SP 2 azalır ya da 2 artar.
- 8086 uç tanımları (40 bacaklı kılıf)
  - AD15-AD0 ortak adres/veri uçları, A19-A16/S6-S3, $\overline{BHE}$/S7, MN/$\overline{MX}$, $\overline{RD}$, READY, $\overline{TEST}$, RESET, CLK, NMI, INTR ve minimum mod uçları (ALE, $\overline{DEN}$, DT/$\overline{R}$, M/$\overline{IO}$, $\overline{WR}$, $\overline{INTA}$, HOLD, HLDA) (ekrandan, 01:25:00).
- Yol tamponlama ve mandallama (bus buffering & latching)
  - 74LS373 mandal (latch): ALE ile adres bilgisini tutar.
  - 74LS245 çift yönlü tampon (transceiver): $\overline{DEN}$ ve DT/$\overline{R}$ ile veri yolunun yönünü belirler.
  - 74LS244 sekizli tampon: kontrol hatlarını tamponlar (ekrandan, 01:40:00 ve 01:45:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Segment yazmaçları önemlidir
  - 16 bitlik yazmaçlarla 20 bitlik adres ancak iki 16 bitlik değerin (segment ve ofset) birleşimiyle üretilebilir. 20 bitlik yazmaç olsaydı bu yapıya gerek kalmazdı.
- Bir segment neden 64 KB'tır?
  - Ofset 16 bittir, çünkü yazmaçlar 16 bittir. 16 bit ile `0000H`-`FFFFH` arası, yani $2^{16} = 65\,536$ bayt = 64 KB adreslenir.
- Bayraklar kod yazarken çok önemli olacak
  - Programlarda dallanma ve hesap kontrolü için bayraklar okunacak.
- SP her zaman çift değer gösterir
  - Yığına her seferinde 2 bayt yazıldığı için SP her `PUSH`'ta 2 azalır, her `POP`'ta 2 artar. `PUSH BL` gibi 8 bitlik işlem hata verir.
- `POP CS` yapılamaz
  - CS yığına atılabilir (`PUSH CS`) ama yığından CS'ye çekilemez.
- Onaltılık sayı yazımı
  - Harfle başlayan onaltılık sayının başına 0 konmalıdır (`0F2H`); yoksa derleyici kabul etmez.
- Doğrudan adreslemede köşeli parantezli değer bir adrestir
  - `1234H` değeri yazmaca yazılmaz; DS içindeki `1234H` ofsetindeki göz okunur.
- Ortak adres/veri yolu senkronizasyon gerektirir
  - Önce adres verilip mandallanmalı, sonra aynı uçlardan veri taşınmalıdır. Mandal ve tampon devreleri tasarlanmayacak (şablon hazır verilecek) ama mantığı bilinmelidir.

## Kısa Tekrar Notları

- 16 bit yazmaç, 20 bit adres, 1 MB adres uzayı.
- Fiziksel adres $= \text{segment} \times 10H + \text{ofset}$; örnek: `1000H:2000H` → `12000H`.
- Farklı segment:ofset çiftleri aynı fiziksel adresi verebilir (`1234H:0005H` ve `1231H:0035H` → `12345H`); bu yüzden fiziksel adresten segment:ofset tek türlü geri bulunamaz.
- Segment başına 64 KB, çünkü ofset 16 bit.
- CS:IP komut, SS:SP ve SS:BP yığın, DS:BX/SI/DI veri, ES dizi işlemleri.
- PF: sonuçtaki 1 sayısı çiftse 1, tekse 0.
- ZF: sonuç 0 ise 1. SF: sonuç negatifse 1.
- OF: işaretli işlemde taşma. DF: dizi işlemlerinde artarak/azalarak gitme.
- `MOV AX, [BX]`: DS:BX adresindeki WORD AX'e gelir; düşük adresteki bayt AL'ye, yüksek adresteki AH'ye.
- `PUSH`: SP-1 ve SP-2'ye yazar, SP 2 azalır. `POP`: SP ve SP+1'den okur, SP 2 artar.
- ALE=1 iken AD uçlarında adres vardır; 74LS373 bu adresi tutar.
- 74LS245: $\overline{G}$=0 iken çalışır; DIR yönü seçer. 8086'da $\overline{DEN}$ ve DT/$\overline{R}$ ile sürülür.
- MN/$\overline{MX}$=1 minimum mod, 0 maksimum mod.
- NMI maskelenemez kesme (vektör 2), INTR maskelenebilir kesme.

## Detaylı Açıklamalar

- **Adres uzayı ve bit/bayt ayrımı.** Derste bir öğrenci $2^{20}$ bitin 1 MB etmediğini, $2^{17}$ bayta karşılık geldiğini sordu. Cevap: 20 bit adres hattı bir kod çözücü (dekoder) gibi düşünülmelidir. Nasıl 3x8 dekoder 3 bit ile 8 farklı çıkışı seçiyorsa, 20 bit de yaklaşık 1 milyon ($2^{20}$) farklı hafıza satırını seçer. Bu 20 bit, adresin kendisidir, saklanan veri miktarı değildir. Her satır 8 bit (1 bayt) olduğu için adreslenebilen toplam alan $2^{20} \times 1 \text{ bayt} = 1 \text{ MB}$ olur. Yani "bayt" hesabı mikroişlemciden değil, hafızanın her gözünün 1 bayt olmasından gelir.

- **Segment:ofset birleşimi.** BIU içindeki toplama birimi, ilk gönderilen 16 bitlik segment değerini $10H$ ile çarpar (bir onaltılık hane sola kaydırır) ve ikinci 16 bitlik ofseti ekler. Böylece 5 onaltılık haneli, 20 bitlik fiziksel adres oluşur. Örnek slayttaki gibi $1000H \times 10H + 2000H = 12000H$ (ekrandan, 00:50:00). Segment değeri her 1 arttığında başlangıç adresi 16 bayt ilerler; ofset 16 bit olduğu için her segment 64 KB'lık bir alanı kaplar. Ofset 8 bit olsaydı segmentler küçülür, hafızanın tamamını kapsamak mümkün olmazdı; iki tane 16 bitlik değer en uygun çözümdür.

- **Fiziksel adresten geri dönüş.** Bir öğrenci fiziksel adresten segment ve ofsetin geri bulunup bulunamayacağını sordu. `1234H:0005H` → `12345H` olur; ama `1231H:0035H` da aynı `12345H` adresini verir (ekrandan, 00:45:00). Aynı fiziksel adresi gösteren birden çok çift olduğu için geri dönüş tek türlü değildir. Pratikte buna gerek de yoktur: segment başlangıcı kodun başında tanımlanır, program yalnızca ofseti verir.

- **Eşlik bayrağı (PF).** Bir işlem sonucundaki 1 olan bitlerin sayısı çiftse PF=1, tekse PF=0 olur. Hoca bunu veri iletimindeki eşlik bitine bağladı: gönderen taraf eşlik bilgisini de gönderir, alıcı gelen verideki 1 sayısıyla karşılaştırır, uyuşmazsa veriyi yeniden ister. Mikroişlemci ile çevre birimi entegresi arasındaki 8 bitlik iletişimde de böyle bir kontrol kullanılabilir. Bu basit bir yöntemdir: iki bit birden değişirse hata yakalanamaz; CRC ve checksum gibi yöntemler daha güçlüdür.

- **Bayrak tanımları (ekrandan, 00:40:00).** TF her komuttan sonra kesme oluşmasını sağlar (adım adım hata ayıklama). IF kesme kaynaklarının kesme oluşturmasına izin verir. DF dizi işlemlerinde başlangıç adresinden itibaren artırarak mı azaltarak mı ilerleneceğini belirler. OF işaretli işlemlerde taşma olursa 1 olur.
  - Ders sonrası not: Hoca anlatımda tuzak bayrağı için "kesmeleri önlemek için sıfırlanan bayrak" tanımını, ikinci bayrak için de "hata ayıklama" tanımını verdi. Slayttaki tanımlara göre bu iki açıklama yer değiştirmiştir: kesmeleri açıp kapatan IF, hata ayıklama (tek adım) için kullanılan TF'dir.

- **Yazmaç dolaylı adresleme (ekrandan, 01:00:00).** BP (SS ile), BX, DI ve SI (DS ile) kullanılabilir; ofset bir yazmaçta saklanır. Slayttaki örnekte DS = `0100H`, BX = `1000H`. `MOV AX, [BX]` komutunda fiziksel adres $0100H \times 10H + 1000H = 02000H$ olur. `02000H` gözünde `12H`, `02001H` gözünde `34H` vardır. AX 16 bit olduğu için iki göz birden okunur: AL = `12H`, AH = `34H`, yani AX = `3412H`.
  - Ders sonrası not: Hoca little-endian/big-endian anlatımında hangi baytın AH'ye gideceğini karışık anlattı. 8086 little-endian'dır: düşük adresteki bayt AL'ye, yüksek adresteki bayt AH'ye gider; slayttaki AX = `3412H` sonucu da bunu gösterir.

- **Yığın.** `PUSH BX` (BX = `1234H`) örneğinde iki bayt yığına yazılır ve SP 2 azalır; `POP CX` ile aynı iki bayt CX'e geri okunur ve SP 2 artar (ekrandan, 01:20:00). SP her zaman en son yazılan veriyi gösterir.

- **Mandal ve tampon devreleri.** 74LS373'te LE (G) yüksekken giriş çıkışa aynen geçer; LE düşük ve $\overline{OE}$ düşük iken çıkış önceki değerini korur. 8086, adres koyduğu anda ALE'yi 1 yapar; ALE 0'a düşünce mandal adresi tutar, aynı AD uçları artık veri taşıyabilir. 74LS245'te $\overline{G}$=1 iken entegre yalıtımdadır; $\overline{G}$=0 iken DIR=0 ise veri B'den A'ya, DIR=1 ise A'dan B'ye aktarılır. 74LS244 sekizli tamponda $\overline{1G}$, $\overline{2G}$ düşükken giriş çıkışa geçer, yüksekken çıkış yüksek empedanstadır (ekrandan, 01:40:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
