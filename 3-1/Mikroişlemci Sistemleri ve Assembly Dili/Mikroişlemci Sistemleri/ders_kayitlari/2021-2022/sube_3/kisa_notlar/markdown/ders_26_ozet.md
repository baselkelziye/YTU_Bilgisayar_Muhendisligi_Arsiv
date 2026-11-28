# Ders 26 Çalışma Özeti

## Genel Konular

- Dersin kapsamı (ekrandan, 00:10:00)
  - Hafıza birimleri: ROM (Masked ROM, PROM, EPROM, EEPROM, Flash) ve RAM (SRAM, DRAM).
  - Adres çözümleme ve 8086 ile hafıza birimleri arasındaki arayüz.
  - Küçük hafıza bloklarından daha büyük bloklar kurmak: veri yolu yönünde genişleme, kapasite yönünde genişleme ya da her iki yönde birden. Kurulan bloğu belirli bir adres aralığına yerleştirmek.
- ROM ve çeşitleri (ekrandan, 00:15:00)
  - ROM, çalışma sırasında yalnız okunabilen ve enerji kesilince verisini kaybetmeyen (non-volatile) hafızadır. Sistemi ilk ayağa kaldıran BIOS çipi ROM'dur; bu yüzden 8086'nın reset vektörünün bulunduğu bölgeye bir ROM yerleştirilmelidir.
  - Masked ROM: imalat aşamasında programlanır, kullanıcı programlanmış hâlde alır.
  - PROM: kullanıcı tarafından bir kez programlanır. Programlama, sigortaların (fuse) yakılması ya da korunmasıyla yapılır.
  - EPROM: silinebilir ve yeniden programlanabilir. Üzerinde bir pencere vardır; çip 15-20 dakika ultraviyole ışıkta tutulursa program silinir.
  - EEPROM: silme ve programlama elektrikseldir; normal fonksiyon uçlarının yanında programlama uçları bulunur.
  - Flash bellek: USB belleklerdeki yapı; tek tek hücreler yerine bloklar hâlinde silinir.
- ROM blok yapısı
  - $n$ adres ucu, $m$ veri ucu, $\overline{OE}$ (output enable) ve $\overline{CS}$ (chip select) kontrol uçları vardır.
  - $n$ adres ucu $2^n$ hafıza gözü demektir; her göz $m$ bit tutar. Kapasite $2^n \times m$ bittir.
  - $\overline{OE}$ mikroişlemcinin $\overline{RD}$ ucuna, adres uçları mikroişlemcinin adres uçlarına, veri uçları veri yoluna, $\overline{CS}$ ise adres çözümleme devresinin çıkışına bağlanır.
  - Hafıza birimlerine `IN`/`OUT` ile değil `MOV` komutuyla erişilir.
- ROM iç yapısı: dekoder ve transistör matrisi (ekrandan, 00:20:00 ve 00:25:00)
  - Dekoder $n$ adres bitinden $2^n$ satır (hafıza gözü) seçer. Her satırda her bit için bir transistör vardır; sütunlar pull-up dirençle beslenir ve D3-D0 veri uçlarına gider.
  - Anlatılan NMOS senaryoda sigorta korunursa seçilen satırda o bit 0, sigorta yakılırsa 1 okunur. PMOS kullanılırsa durum tersine döner.
  - 4x4 ROM programlama örneği (Adr./Data): 0 → A (1010), 1 → 3 (0011), 2 → 5 (0101), 3 → 7 (0111). A1A0 = 10 verildiğinde D3-D0 = 0101 okunur.
- RAM (ekrandan, 00:30:00 - 00:45:00)
  - Geçici (volatile) hafızadır, okuma/yazma ROM'dan hızlıdır, ana bellek olarak kullanılır. Rastgele erişim: istenen adrese doğrudan, $O(1)$ sürede erişilir. Karşıtı sıralı erişimdir (bağlı liste, manyetik kaset).
  - SRAM hücresi: geri beslemeli iki evirici (flip-flop mantığı) ve iki erişim transistörüyle en az 6 transistör (M1-M6). WL (word line) adresi, BL ve $\overline{BL}$ (bit line) veriyi taşır.
  - SRAM'e yazma: WL = 1 yapılır, BL'ye yazılacak değer, $\overline{BL}$'ye tersi verilir; WL kalkınca değer kararlı biçimde tutulur. Okuma: yalnız WL = 1 yapılır, BL ve $\overline{BL}$ bir karşılaştırıcıya (sense) verilir; karşılaştırıcı bozulmuş seviyeleri net lojik değere çevirir.
  - SRAM blok yapısı: $n$ adres, $m$ çift yönlü veri ucu, $\overline{WE}$, $\overline{RE}$ ve $\overline{CS}$. İçeride dekoder, hafıza matrisi ve giriş/çıkış tamponu vardır.
  - DRAM hücresi: bir transistör ve bir kapasite. Lojik 1 kapasitedeki yüktür; kaçak akımlarla yük azaldığı için eşik altına düşmeden periyodik olarak yeniden yazılır (refresh). Lojik 0'ın kaybı söz konusu değildir. Benzetme: sızdıran kova.
  - DRAM adresi iki zamanda alınır: satır adresi $\overline{RAS}$ ile satır mandalına, sütun adresi $\overline{CAS}$ ile sütun mandalına. $n$ bitlik adres uçlarıyla $2^{2n}$ göz adreslenir; kapasite $2^{2n} \times m$ olur. Slayttaki örnekte adres girişi RADR[11:0], yani 12 bittir.
- 8086 hafıza arayüzü (ekrandan, 00:50:00 - 01:00:00)
  - 8086'nın 20 adres ucu, 16 veri ucu vardır; hafıza birimleri 8 bitliktir. $2^{20} \times 8$ = 1 MB adreslenir.
  - 8086 bir okuma/yazma çevriminde çift adresten 16 bit (`MOV AX, [100H]`), tek adresten 8 bit (`MOV AL, [101H]`) ve çift adresten 8 bit (`MOV AL, [100H]`) işlemleri destekler. Bu yüzden 1M x 8 değil, 512K x 16 bir arayüz görmek ister.
  - Hafıza ikiye bölünür: çift adresler bankası (even bank, D0-D7, $A0 = 0$ ile seçilir) ve tek adresler bankası (odd bank, D8-D15, $\overline{BHE} = 0$ ile seçilir). A1-A19 iki bankaya ortak gider; 19 uçla $2^{19}$ = 512K satır seçilir.
  - `MOV AL, [100H]`: A0 = 0, $\overline{BHE}$ = 1 → yalnız çift banka, veri D0-D7'den.
  - `MOV AL, [101H]`: A0 = 1, $\overline{BHE}$ = 0 → yalnız tek banka, 100H ile aynı satırdaki göz, veri D8-D15'ten.
  - `MOV AX, [100H]`: A0 = 0, $\overline{BHE}$ = 0 → iki banka aynı satırla seçilir; 100H → AL (D0-D7), 101H → AH (D8-D15). Little endian düzeniyle tutarlıdır.
  - Tek adresten 16 bit (`MOV AX, [5]`): 5 (0101) ve 6 (0110) A0 atıldıktan sonra aynı satıra düşmez. İşlemci işlemi iki 8 bitlik çevrime böler.
- Adres çözümleme (ekrandan, 01:05:00 ve 01:10:00)
  - Hafıza ve G/Ç çipleri ortak adres ve veri yollarını kullanır; adres çözümleme aynı anda yola yalnız bir çipin veri çıkarmasını ve çiplerin belirli adres aralıklarına yerleşmesini sağlar.
  - A0 banka seçimine, A1-Ai cihazın adres uçlarına, Ai+1-A19 adres çözümleme devresine gider. İzole G/Ç'de M/$\overline{IO}$ da adres çözümlemeye girer.
  - Separate Bank Decoder: çift ve tek bankalar için ayrı $\overline{CS}$ üretilir; A0 ve $\overline{BHE}$ adres çözme lojiğine girer.
  - Separate Bank Strobe: iki bankaya tek $\overline{CS}$; ayrım OR kapılarıyla üretilen $\overline{RD}_{\text{çift}}$, $\overline{RD}_{\text{tek}}$, $\overline{WR}_{\text{çift}}$, $\overline{WR}_{\text{tek}}$ işaretleriyle yapılır.
  - Çözümlemede 3x8 (74138 tipi, $E1 = 1$, $\overline{E2} = \overline{E3} = 0$ ile etkin) ya da 2x4 aktif 0 çıkışlı dekoder kullanılır.
- Örnekler (ekrandan, 01:30:00 - 01:55:00)
  - Hafıza arayüzü kapasiteleri: 8088 → 1M x 8, 8086 → 512K x 16, 80486 → 1G x 32.
  - 128 KB RAM (00000H'dan, 32K x 8 SRAM) ve 128 KB ROM (FFFFFH'ta biten, 64K x 8 EPROM) yerleşimi, tek 3x8 dekoderle.
  - FF800H-FFFFFH aralığına iki 1 KB EPROM ile ROM bloğu.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bu dersin konusu ve bir önceki dersin kesme konusu (farklı G/Ç cihazları, NMI ve INTR uçlarından kesmeler) final sınavında kesin sorulacak; derste çözülen örneklerin mantığına benzer sorular gelecek.
- Aksi belirtilmedikçe izole G/Ç kabul edilir; bu durumda M/$\overline{IO}$ ucu adres çözümlemede mutlaka kullanılmalıdır. Kullanılmazsa sistem memory-mapped I/O olur.
- 8086 tek adresten 16 bitlik işlemi bir çevrimde yapamaz; iki 8 bitlik çevrime böler.
- Hizalı adres: blok, toplam uzayın $1/2^k$'sı kadar büyüklükte ve bu büyüklüğün katı olan bir adresten başlıyorsa hizalıdır; o zaman adres uçları doğrudan bağlanır. Hizalı değilse blok ilk hizalı sınıra kadar parçalara ayrılır.
- Adres sınırını bulmak için kapasitenin kaç adres ucunun değişmesine karşılık geldiği bulunur ve o kadar bit başlangıç adresinde değiştirilir.
- Tek 3x8 dekoderde dört seçim biti gerekiyorsa hile: A19 ve A18'i XOR'layıp aktif 0 enable ucuna vermek. Bu iki bitin hep aynı olması garanti edilir, A18 seçim girişine verilir.

## Kısa Tekrar Notları

- ROM: non-volatile, yalnız okunur; kapasite $2^n \times m$; uçlar: adres, veri, $\overline{OE}$ ($\overline{RD}$'ye), $\overline{CS}$ (adres çözücüye).
- PROM bir kez, EPROM UV ile silinir, EEPROM elektriksel silinir, Flash blok blok silinir.
- ROM iç yapısı: dekoder + transistör matrisi + sigortalar.
- SRAM: 6 transistörlü flip-flop hücre, refresh yok. DRAM: 1 transistör + 1 kapasite, refresh gerekir, adres RAS/CAS ile iki parçada; kapasite $2^{2n} \times m$.
- 8086: 1 MB, 512K x 16 arayüz; çift banka A0, tek banka $\overline{BHE}$ ile seçilir.
- $A0 = 0, \overline{BHE} = 1$: çift adres 8 bit; $A0 = 1, \overline{BHE} = 0$: tek adres 8 bit; $A0 = 0, \overline{BHE} = 0$: çift adres 16 bit.
- Separate Bank Decoder: iki $\overline{CS}$. Separate Bank Strobe: tek $\overline{CS}$, bölünmüş $\overline{RD}$/$\overline{WR}$.
- Gerekli çip sayısı = blok kapasitesi / çip kapasitesi. 128 KB / 32K x 8 = 4 SRAM, 128 KB / 64K x 8 = 2 EPROM.
- 128 KB = $2^{17}$: 00000H-1FFFFH ve E0000H-FFFFFH.
- 8088 → 1M x 8, 8086 → 512K x 16, 80486 → 1G x 32.

## Detaylı Açıklamalar

- **ROM'da bir bit nasıl saklanır?** Dekoder seçilen satırı etkin yapar. Anlatılan senaryoda bir sütundaki transistörün kapısına seçim işareti ulaşırsa (sigorta sağlam) transistör iletime geçer ve pull-up direncinden gelen akım toprağa akar; veri ucunda 0 görülür. Sigorta yakılmışsa transistör devreden kopmuş gibidir ve veri ucu pull-up üzerinden 1 olur. 4x4 ROM'da 0 → A, 1 → 3, 2 → 5, 3 → 7 programlanmıştır; örneğin 0. satıra 1010 yazmak için D3 ve D1 sütunlarındaki sigortalar yakılır, D2 ve D0'dakiler korunur. A1A0 = 10 verildiğinde 2. satır seçilir ve D3D2D1D0 = 0101 okunur (ekrandan, 00:25:00).
- **SRAM hücresinde yazma ve okuma.** Hücre, birbirini besleyen iki eviricidir (slaytta M1-M4) ve iki erişim transistörü (M5, M6) ile bit hatlarına bağlanır (ekrandan, 00:30:00). Lojik 1 yazmak için WL = 1 yapılır, BL = 1, $\overline{BL}$ = 0 verilir; Q = 1, $\overline{Q}$ = 0 kararlı hâle gelir ve WL kalktıktan sonra besleme sürdükçe korunur. Okumada yalnız WL = 1 yapılır; BL'ye saklanan değer X, $\overline{BL}$'ye tersi gelir ve bunlar karşılaştırıcının + ve − girişlerine verilir. + girişi daha yüksekse çıkış 1, değilse 0 olur; böylece hatlardaki küçük gerilim kaymaları temizlenir (ekrandan, 00:35:00).
- **DRAM ve tazeleme.** Erişim transistörü WL ile açılır; bit hattı 1 ise kapasite şarj olur, 0 ise deşarj olur (ekrandan, 00:40:00). WL kalktıktan sonra kapasitedeki yük kaçak akımlarla üstel olarak azalır. Kapasitenin zaman sabitine göre seçilen aralıklarla değer, eşik gerilimin altına düşmeden yeniden yazılır. DRAM iç yapısında 12 bitlik RADR[11:0] adresi önce $\overline{RAS}$ ile satır adres mandalına, sonra $\overline{CAS}$ ile sütun adres mandalına alınır; okunan veri sense amplifier'lar ve data-out tamponu üzerinden DOUT'a çıkar (ekrandan, 00:45:00).
  > **Ders sonrası not:** Hoca bir yerde ilk gönderilen adresin sütun, ikincinin satır adresi olduğunu söyledi. Slayttaki yapıda ve standart DRAM çalışmasında büyük olasılıkla önce satır adresi ($\overline{RAS}$), sonra sütun adresi ($\overline{CAS}$) alınır.
- **8086'da bankalar.** 1M x 8'lik bir hafıza doğrudan bağlansaydı 8 bitlik çıkış ya D0-D7'ye ya da D8-D15'e bağlanacağı için hafızanın yarısına erişilemezdi. Bu yüzden 512K'lık iki banka yan yana çalıştırılır. Aynı satırdaki iki göz yalnız A0 bitinde farklıdır (100H ve 101H gibi). 16 bitlik bir okuma sırasında iki bankada da aynı satır seçilir, düşük adresteki bayt D0-D7'ye, yüksek adresteki bayt D8-D15'e çıkar; little endian düzeninde düşük anlamlı bayt düşük adreste saklandığı için AX doğru oluşur (ekrandan, 01:00:00). Tek adreste başlayan 16 bitlik veride iki bayt farklı satırlarda olduğundan işlemci önce tek bankadan (D8-D15), sonra çift bankadan (D0-D7) okuyarak işlemi iki çevrimde bitirir.
- **Separate Bank Strobe kapıları.** $\overline{RD}_{\text{çift}} = \overline{RD} + A0$, $\overline{RD}_{\text{tek}} = \overline{RD} + \overline{BHE}$, $\overline{WR}_{\text{çift}} = \overline{WR} + A0$, $\overline{WR}_{\text{tek}} = \overline{WR} + \overline{BHE}$. İki giriş de aktif 0 iken aktif 0 çıkış üretmek için OR kapısı kullanılır. Çift adresten 16 bitlik yazmada iki bankanın da $\overline{WR}$ hattı 0 olur (ekrandan, 01:10:00).
- **Örnek: 128 KB RAM + 128 KB ROM.** RAM 00000H-1FFFFH, ROM E0000H-FFFFFH aralığındadır. SRAM 32K x 8 olduğu için 15 adres ucu (A1-A15'e bağlanır), EPROM 64K x 8 olduğu için 16 adres ucu (A1-A16'ya bağlanır) vardır. RAM, 2x2 yerleşim için RAM low (00000H-0FFFFH) ve RAM high (10000H-1FFFFH) olarak ikiye bölünür. Seçimde RAM için A16-A19, ROM için A17-A19 gerekir; dört bitlik seçim tek 3x8 dekoderde A19 ⊕ A18'i $\overline{G2B}$'ye vererek çözülür. Dekoder bağlantısı: C = A18, B = A17, A = A16, G1 = M/$\overline{IO}$, $\overline{G2A}$ = 0; $\overline{Y0}$ → $\overline{CS}_{RAMlow}$, $\overline{Y1}$ → $\overline{CS}_{RAMhigh}$, $\overline{Y6}$ ve $\overline{Y7}$ bir AND kapısından geçerek $\overline{CS}_{ROM}$ (ekrandan, 01:45:00).
- **Örnek: FF800H-FFFFFH arası iki EPROM.** 2 KB'lık aralık, 1 KB'lık iki EPROM (tek ve çift banka) ile doldurulur; A1-A10 EPROM'ların 10 adres ucuna gider, A11-A19 hep 1'dir. Separate Bank Decoder çözümünde çok girişli NAND, A11-A19 = 1, M/$\overline{IO}$ = 1 ve $\overline{BHE}$ = 0 iken tek bankanın, A0 = 0 iken çift bankanın $\overline{CS}$'sini üretir. Separate Bank Strobe çözümünde tek NAND iki bankaya ortak $\overline{CS}$ verir, $\overline{OE}$ uçları $\overline{RD} + \overline{BHE}$ (D8-D15) ve $\overline{RD} + A0$ (D0-D7) ile sürülür (ekrandan, 01:50:00 ve 01:55:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
