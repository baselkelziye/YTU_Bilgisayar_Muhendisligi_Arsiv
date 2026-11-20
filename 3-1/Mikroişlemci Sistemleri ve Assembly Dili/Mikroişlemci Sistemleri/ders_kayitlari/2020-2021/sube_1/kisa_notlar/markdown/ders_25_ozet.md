# Ders 25 Çalışma Özeti

## Genel Konular

- Hafıza birimlerinin mikroişlemci sistemindeki yeri
  - Bir mikroişlemci tek başına çalışmaz; RAM ve ROM birimleri ile çevre birimleri bağlı olduğunda sistem çalışır hale gelir.
  - ROM kalıcı hafızadır ve daha çok BIOS gibi program barındıran yapılar için kullanılır. RAM geçici işlem sonuçlarını tutan ana hafızadır.
  - Daha önce kullanılan çevre birimleri 8 bitlikti; bu derste 8086 ile uyumlu, 16 bit genişlikte bir hafıza arayüzü kurulur.
- ROM ve 8086 reset vektörü
  - ROM yalnız okunabilir ve kalıcıdır (non-volatile): enerji kesilse de veri kaybolmaz.
  - 8086 reset sonrası CS=FFFFH, IP=0000H değerleriyle başlar; fiziksel adres $FFFFH \times 10H + 0000H = FFFF0H$'dir. Bu reset vektöründe bir ROM (BIOS ROM) bulunmalıdır.
- ROM çeşitleri (ekrandan, 00:15:00)
  - Masked ROM: üretim aşamasında maskelenerek programlanır.
  - PROM: kullanıcı tarafından bir kez programlanır.
  - EPROM: ultraviyole ışıkla silinip yeniden programlanır; çip üzerindeki pencere UV ışığa 20-30 dakika tutulunca program silinir.
  - EEPROM: programlama uçlarına uygun koşullar uygulanarak elektriksel olarak silinip yazılır.
  - Flash bellek: blok olarak silinip blok olarak yazılabilir; flash disklerde kullanılır.
- Basit ROM iç yapısı: 4x4 ROM (ekrandan, 00:20:00)
  - A1-A0 adres uçları 2x4 dekodere girer; dekoder çıkışları aktif 0'dır. Her satırda D3-D0 veri hatlarına giden sigortalı transistörler, her veri hattında pull-up direnç vardır.
  - Seçilen satırda sigorta korunursa çıkış lojik 0, sigorta yakılırsa çıkış (pull-up üzerinden) lojik 1 olur.
  - $n$ adres ve $m$ veri uçlu bir ROM'da $2^n$ satır vardır; kapasite $2^n \times m$'dir. Örnekte $2^2 \times 4 = 4\times4$.
- ROM blok diyagramı (ekrandan, 00:25:00)
  - Uçlar: $n$ adres (giriş), $m$ veri (çıkış), $\overline{OE}$ ve $\overline{CS}$ (aktif 0).
  - $\overline{OE} \leftrightarrow \overline{RD}$; $\overline{CS} \leftrightarrow$ adres çözümleme devresi çıkışı. Adres uçları mikroişlemcinin adres uçlarına, veri uçları veri uçlarına bağlanır.
- RAM: SRAM ve DRAM
  - RAM uçucudur (volatile): enerji kesilince veri kaybolur. Rastgele erişim (random access), herhangi bir göze doğrudan adresle erişmektir; manyetik bant gibi sıralı erişimli (sequential access) birimlerde baştan ilerlemek gerekir.
  - SRAM flip-flop temellidir; bir bit için yaklaşık 6 transistör gerekir. DRAM bir transistör ve bir kapasiteden oluşur, veri yoğunluğu daha yüksektir ama kapasitedeki yük kaçak akımlarla kaybolduğundan periyodik olarak yenilenmelidir (refresh).
- SRAM hücresi (ekrandan, 00:30:00)
  - Çapraz bağlı iki evirici (M1-M4) ve iki erişim transistöründen (M5, M6) oluşur. WL (word line) adres/seçim hattı, BL ve $\overline{BL}$ (bit line) veri hattıdır.
  - Yazma: BL'ye veri, $\overline{BL}$'ye tersi konur, WL=1 yapılır; çapraz bağlı yapı kendi içinde tutarlı duruma geçer ve WL kalktıktan sonra da besleme var oldukça değeri saklar.
  - Okuma: WL=1 yapılınca Q ve $\overline{Q}$ bit hatlarına çıkar; bir karşılaştırıcı iki hat arasındaki farka bakarak (pozitifse 1, negatifse 0) gerilim kayıplarını telafi eder.
- SRAM blok diyagramı ve iç yapısı (ekrandan, 00:35:00 ve 00:40:00)
  - Uçlar: $n$ adres (giriş), $m$ veri (çift yönlü), $\overline{WE}$, $\overline{RE}$, $\overline{CS}$. $\overline{RE} \leftrightarrow \overline{RD}$, $\overline{WE} \leftrightarrow \overline{WR}$, $\overline{CS} \leftrightarrow$ adres çözümleme.
  - İç yapıda $n \times 2^n$ dekoder satır seçer; $\overline{WE}$ ile $\overline{CS}$ bir OR kapısından yazma denetimine, $\overline{CS}$ ile $\overline{OE}$ bir OR kapısından çıkış tamponlarına gider.
  - Okuma: $\overline{WE}=1$, $\overline{CS}=0$, $\overline{OE}=0$. Yazma: $\overline{WE}=0$, $\overline{CS}=0$, $\overline{OE}=1$.
- DRAM hücresi, yenileme ve satır/sütun adresleme (ekrandan, 00:45:00)
  - 1 yazarken bit hattına 1 konur, word line 1 yapılır ve kapasite şarj olur. 0 yazarken bit hattı 0'dır, kapasite deşarj olur.
  - Kapasite gerilimi zamanla üstel olarak düşer; HIGH/LOW eşiğinin altına inmeden değer yeniden yazılır (refresh). Yenileme sıklığı, maliyet ile veri kaybı arasında optimize edilir.
  - 8088 kullanan sistemlerde 8254'ün sayıcılarından biri yenileme hızı için ayrılmıştı.
  - DRAM'de satır ve sütun seçim uçları vardır; aynı $n$ adres ucu iki kez (bir kez sütun, bir kez satır için) kullanılır. Kapasite $2^n \times 2^n \times m = 2^{2n} \times m$'dir.
- 8086 adres uzayı ve çift/tek bank yapısı (ekrandan, 00:50:00-01:05:00)
  - 8086'nın 20 adres ucu, 16 veri ucu vardır: $2^{20} = 1M$ göz, her göz 1 bayt, toplam 1 MB.
  - Hafıza birimleri aksi belirtilmedikçe 8 veri uçludur ($m=8$).
  - 8086, çift adresten 16 bitlik, tek adresten 8 bitlik ve çift adresten 8 bitlik işlemleri bir okuma/yazma çevriminde yapar. Bu yüzden 1 MB'lik alan $1M \times 8$ değil, $512K \times 16$ olarak görülmek istenir.
  - Bellek çift (even) ve tek (odd) iki banka ayrılır. A1-A19 her iki bankta aynı satırı seçer. Çift bank D0-D7'ye, tek bank D8-D15'e bağlanır.
  - Çift bankı A0 (diğer adıyla $\overline{BLE}$), tek bankı $\overline{BHE}$ seçer; ikisi de aktif 0'dır. Üç durum (yalnız çift, yalnız tek, ikisi birden) olduğu için iki kontrol ucu gerekir.
- Erişim türleri
  - `MOV AL,[0]` (çift adres, 8 bit): A0=0, $\overline{BHE}$=1; veri D0-D7'den gelir.
  - `MOV AL,[1]` (tek adres, 8 bit): A0=1, $\overline{BHE}$=0; veri D8-D15'ten gelir.
  - `MOV AX,[0]` (çift adres, 16 bit): A0=0, $\overline{BHE}$=0; [0] D0-D7'den AL'ye, [1] D8-D15'ten AH'ye gelir.
  - `MOV AX,[1]` (tek adres, 16 bit): 1 ve 2 adresleri farklı satırlardadır; işlem iki ayrı 8 bitlik çevrimle yapılır (AL←[1], AH←[2]).
- Adres çözümleme (ekrandan, 01:10:00 ve 01:30:00)
  - Hafıza ve I/O çipleri ortak veri ve adres yollarını kullanır. Bir anda yola tek bir çipin veri çıkarması ve çiplerin belirli adres aralıklarına yerleşmesi için adres çözümleme gerekir.
  - Aksi belirtilmedikçe izole I/O kullanılır, yani M/$\overline{IO}$ adres çözümlemeye mutlaka girer; hafıza için M/$\overline{IO}$=1 olmalıdır.
  - Hafıza çipine A1'den kapasitesinin gerektirdiği uca kadar adres uçları bağlanır; kalan üst uçlar adres çözümlemeye gider.
  - Separate bank decoder: A0 ve $\overline{BHE}$ adres çözümleme devresine girer; devre çift ve tek bank için iki ayrı seçim çıkışı üretir.
  - Separate bank strobe: iki bank için tek chip select üretilir; A0 ve $\overline{BHE}$, $\overline{RD}$ ve $\overline{WR}$ ile OR kapılarında birleştirilerek her bankın okuma/yazma uçlarına gider (aktif 0 sinyalleri aktif 0 çıkışta birleştirmek için OR).
  - Adres çözümleme için çok girişli NAND kapısı, dekoder entegresi ya da PAL/PLD kullanılabilir. Derste 3x8 (74LS138 türü: C,B,A girişleri, bir aktif-1 ve iki aktif-0 enable, aktif-0 çıkışlar) ve 2x4 dekoder kullanılır.
- Örnek 1: 27128 EPROM ile 64 KB (ekrandan, 01:35:00-01:45:00)
  - 16Kx8 EPROM'dan ($2^{14}$ göz, 14 adres ucu, 8 veri ucu) 4 adet ile F0000H'den itibaren 64 KB; mikroişlemci bunu $32K \times 16$ olarak görür.
  - Aralıklar: F0000H-F7FFFH (1. satır), F8000H-FFFFFH (2. satır). A0 bank seçimi, A1-A14 tüm EPROM'ların adres uçları, A15 satır ayırıcı, A16-A19 hep 1.
  - 3x8 dekoder: C=A17, B=A16, A=A15; M/$\overline{IO}$ aktif-1 enable'a, A18 ve A19 aktif-0 enable'lara (tersleyerek). Y6 üst satırı, Y7 alt satırı seçer.
  - Separate bank strobe: $\overline{RD}$+A0 çift sütunun, $\overline{RD}$+$\overline{BHE}$ tek sütunun $\overline{OE}$ ucuna. Aynı sütundaki iki çipin veri uçları ortaktır; tek sütun D8-D15'e, çift sütun D0-D7'ye bağlanır.
- Örnek 2: 32Kx8 RAM ile 128 KB, 0 adresinden
  - 4 adet 32Kx8 RAM ($2^{15}$ göz, 15 adres ucu); mikroişlemci $64K \times 16$ görür. Aralıklar: 00000H-0FFFFH ve 10000H-1FFFFH.
  - A1-A15 tüm RAM'lere, A16 satır ayırıcı, A17-A19 sıfır olmalı. Dekoderin 0 numaralı çıkışı üst satırı, 1 numaralı çıkışı alt satırı seçer.
  - Strobe: $\overline{RD}$ ile A0/$\overline{BHE}$ birleşerek $\overline{OE}$'lere, $\overline{WR}$ ile A0/$\overline{BHE}$ birleşerek $\overline{WE}$'lere gider.
- Örnek: 80486 ve dört banklı hafıza (ekrandan, 01:55:00)
  - 80486'nın 32 bit veri ve 32 bit adres yolu vardır; hafızayı $\times 32$ görmek ister. Dört bank ($\overline{BE0}$-$\overline{BE3}$) 4'e bölümünden kalan 0, 1, 2, 3 olan adresleri tutar; A0 ve A1 bank seçimi için ayrılır.
  - Ekrandaki örnekte 8 adet 256Kx8 EPROM ile 2 MB ($512K \times 32$) kurulur: veri yolu 4 kat, kapasite 2 kat artar. Bankların veri yolları D0-D7, D8-D15, D16-D23, D24-D31'dir.

## Hocanın Özellikle Vurguladığı Kısımlar

- 8086'nın çift adresten 16 bitlik işlemi tek çevrimde yapabilmesi hafıza arayüzünü I/O arayüzünden farklılaştırır.
  - Bu yüzden hafıza çift ve tek bank olarak bölünür; hoca bu farka özellikle dikkat edilmesini istedi.
- Verilerin hizalı tanımlanması çok önemlidir.
  - Tek adresten başlayan bir word dizisinde her 16 bitlik erişim iki çevrim sürer; bu yarı yarıya performans kaybıdır.
- Hafıza arayüzü konusunun iyi takip edilmesi gerekir; hoca bu konunun çok önemli olduğunu söyledi.
- Separate bank strobe ile separate bank decoder yöntemlerinin ayırt edilmesi önemli bir konudur.
- Tasarımlarda ROM için ROM blok diyagramı, SRAM için SRAM blok diyagramı varsayılan olarak kullanılacaktır.
- Adresler kapasiteye hizalıysa (başlangıç adresi kapasitenin katıysa) adres çözümleme mantığı hızlıca çıkarılır; hizalı değilse ek işlem gerekir.

## Kısa Tekrar Notları

- ROM: kalıcı, yalnız okunur; $\overline{OE}\leftrightarrow\overline{RD}$, $\overline{CS}\leftrightarrow$ adres çözümleme.
- Reset: CS=FFFFH, IP=0000H, fiziksel adres FFFF0H; orada BIOS ROM olmalı.
- ROM sigortası: koru = 0, yak = 1.
- $n$ adres, $m$ veri ucu: kapasite $2^n \times m$; DRAM'de $2^{2n} \times m$.
- SRAM: 6 transistör, flip-flop, yenileme yok. DRAM: 1 transistör + 1 kapasite, yoğun, yenileme gerekir.
- SRAM okuma: $\overline{WE}=1,\overline{CS}=0,\overline{OE}=0$; yazma: $\overline{WE}=0,\overline{CS}=0,\overline{OE}=1$.
- 8086: 1 MB'yi $512K \times 16$ ister. Çift bank D0-D7 ve A0, tek bank D8-D15 ve $\overline{BHE}$.
- Tek adresten 16 bit erişim iki çevrim sürer.
- Hafıza çiplerine A1'den başlayarak adres bağlanır; kalan üst uçlar ve M/$\overline{IO}$ adres çözümlemeye gider.
- Separate bank decoder: A0 ve $\overline{BHE}$ çözümlemeye girer, iki CS çıkar. Separate bank strobe: tek CS, A0/$\overline{BHE}$ ile $\overline{RD}$/$\overline{WR}$ OR'lanır.
- 4×(16Kx8) F0000H: satırlar F0000H-F7FFFH ve F8000H-FFFFFH, A15 ayırır, Y6/Y7.
- 4×(32Kx8) 0 adresi: satırlar 00000H-0FFFFH ve 10000H-1FFFFH, A16 ayırır, Y0/Y1.

## Detaylı Açıklamalar

- **ROM'un iç yapısı ve programlanması.** 4x4 ROM'da iki adres ucu 2x4 dekodere girer ve aktif 0 çıkışlardan yalnız seçilen satır 0 olur. Her satır ile her veri hattı arasında sigortalı bir transistör vardır. Veri hatları pull-up dirençlerle 1'e çekilidir. Seçilen satırdaki sigorta korunmuşsa transistör veri hattını 0'a çeker; yakılmışsa bağlantı kopar ve hat pull-up ile 1 olarak görünür. Seçilmeyen satırların çıkışa etkisi yoktur. Derste sigorta durumlarıyla şu değerler yazıldı: 0. göz "yak-koru-yak-koru" = 1010 = AH; 1. göz "koru-koru-yak-yak" = 0011 = 3H; 2. göz 0101 = 5H; 3. göz 0111 = 7H. Yani ROM'a değer yazmak, sigortaları yakmak ya da korumak demektir.
- **SRAM ve DRAM farkı.** SRAM hücresi çapraz bağlı iki eviriciden oluşan bir flip-flop'tur; besleme olduğu sürece veri kendi kendini korur, okuma sırasında bit hatlarındaki fark bir karşılaştırıcıyla değerlendirilir. DRAM hücresi delikli bir kova gibidir: kapasite doldurulduğunda 1 saklanır, ama yük zamanla akıp gider. 0 değeri kaybolmaz, 1 değeri ise eşik altına inmeden yeniden yazılmazsa kaybolur. DRAM'de adres uçları satır ve sütun için ardışık iki kez kullanılır; bu, aynı uç sayısıyla çok daha büyük bir adres uzayı sağlar.
- **8086'nın beklediği hafıza arayüzü.** Tek ve çift banktaki karşılıklı gözlerin adresleri yalnız A0'da farklıdır; A1-A19 aynıdır. A0 bank seçimine ayrılınca A1-A19 iki bankın aynı satırını birlikte seçer. Çift adresten 8 bitlik okumada yalnız çift bank seçilir ve veri D0-D7'den gelir; tek adresten 8 bitlikte yalnız tek bank seçilir ve veri D8-D15'ten gelir; çift adresten 16 bitlikte iki bank birden seçilir ve veri D0-D15'ten gelir. Tek adresten 16 bitlik okumada (örneğin `MOV AX,[1]`) 1 ve 2 adresleri aynı satırda olmadığından işlemci önce 1 adresini (D8-D15 üzerinden AL'ye), sonra 2 adresini (D0-D7 üzerinden AH'ye) okur. Bu iki çevrim demektir.
- **Örnek 1'in adres tablosu.** F0000H'den 64 KB ($2^{16}$ göz) ilerleyince alt 16 bit tümüyle 1 olur ve bitiş FFFFFH'dir. Yarısı (32 KB, $2^{15}$) F7FFFH'de biter, ikinci satır F8000H'de başlar. İkilik yazımda A19-A16 iki satırda da 1111'dir; A15 birinci satırda 0, ikincide 1'dir; A14-A1 her satır içinde 0'dan 1'e tüm değerleri alır ve EPROM'ların 14 adres ucuna gider; A0 bank seçimidir. Dekoderde A17, A16, A15 = 110 olduğunda Y6 (üst satır), 111 olduğunda Y7 (alt satır) seçilir. Veri tarafında aynı sütundaki iki çipin veri uçları ortaktır; iki satır aynı anda seçilemediği için çakışma olmaz.
- **80486 genellemesi.** Dört banklı yapıda 8 bitlik komut herhangi bir banktan, 16 bitlik komut ikili banklardan, 32 bitlik komut tüm banklardan okur (ekrandan, 01:55:00). Strobe işaretleri ilgili $\overline{BE}$ ucu ile $\overline{RD}$ birleştirilip her sütunun $\overline{OE}$ ucuna bağlanarak üretilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
