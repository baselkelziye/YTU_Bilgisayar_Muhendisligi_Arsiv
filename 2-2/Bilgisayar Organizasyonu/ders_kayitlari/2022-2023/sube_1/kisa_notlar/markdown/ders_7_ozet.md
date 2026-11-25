# Ders 7 Çalışma Özeti

## Genel Konular

- Tek çevrimli (single cycle) CPU'nun veri yolu ve yazmaç dosyası (ekrandan, 00:05:00)
  - Önceki derste kurulan veri yolu (datapath), CPU tasarımında yazmaç dosyası (register file) adını alır. Slayttaki örnekte dört yazmaç (R0-R3) vardır.
  - A select ve B select (2'şer bit) birer 4'e 1 MUX'u sürer; seçilen yazmaçlar A data ve B data kanallarına çıkar. İki kanala aynı yazmaç da çıkabilir.
  - Destination select (2 bit) bir 2'ye 4 dekodere girer. Dekoder çıkışları Load enable/Write işaretiyle AND'lenip ilgili yazmacın Load işaretini üretir. Write 0 iken hiçbir yazmaç yüklenmez.
  - Yüklenecek değer D data hattından gelir ve saatin yükselen kenarında yazılır. Kenardan önce yazmacın eski değeri MUX'lardan sonraki kata aktarılmış olur.
  - Slaytta mavi kutular (yazmaçlar) saatle çalışan ardışıl elemanlardır; geri kalan bloklar kombinasyonel devredir, girişleri değişince hemen çıkış üretir.
- Fonksiyon birimi (function unit) ve veri yolundaki seçiciler (ekrandan, 00:05:00 ve 01:30:00)
  - A kanalı ALU'nun A girişine ve Address out hattına gider (Bus A).
  - MUX B, B data ile komuta gömülü sabit değer (Constant in) arasında seçim yapar (MB select: 1 sabit, 0 yazmaç). Çıkışı (Bus B) ALU/Shifter'ın B girişine ve Data out hattına gider.
  - Fonksiyon biriminin içinde ALU ve Shifter vardır; ikisi de her zaman sonuç üretir. MUX F (MF select: 0 ALU, 1 Shifter) hangisinin F çıkışına gideceğini seçer.
  - MUX D (MD select: 0 fonksiyon birimi, 1 Data in) yazmaç dosyasına geri yazılacak değeri seçer. Böylece hedefe bir yazmacın ALU/Shifter sonucu, sabitle işlem sonucu ya da bellekten okunan değer yazılabilir.
  - Örnek: `MOV [R1], 10` gibi bir komutta R1 A kanalından adres olarak, 10 sabiti MUX B üzerinden veri olarak belleğe gider.
- Durum bayraklarının üretimi
  - Sıfır bayrağı (Z): çıkışın bütün bitleri NOR kapısına girer; hepsi 0 ise $Z = 1$.
  - İşaret/negatif bayrağı (N): ikiye tümleyen gösterimde en yüksek anlamlı bit doğrudan N olur.
  - Elde bayrağı (C): işaretsiz toplamadaki taşmadır; $n$ bitlik toplayıcının $C_{out}$ ucundan alınır.
  - Taşma bayrağı (V): işaretli işlemde taşmadır; en yüksek anlamlı bite giren elde ile çıkan elde farklıysa oluşur: $V = C_n \oplus C_{n-1}$.
- ALU'nun blok yapısı (ekrandan, 00:30:00)
  - $n$ bitlik A ve B veri girişleri, $C_{in}$, işlem seçme uçları $S_0, S_1$, mod seçme ucu $S_2$; çıkışlar $G_0 \ldots G_{n-1}$ ve $C_{out}$.
  - Genel yöntem: bir $n$ bitlik toplayıcının $X_i$, $Y_i$ ve $C_{in}$ girişleri önüne giriş lojiği konur: $X_i = f(A_i, S)$, $Y_i = g(B_i, S)$, $C_{in} = h(A_i, B_i, S)$.
- Aritmetik birim tasarımı (tahtada, ekrandan, 00:45:00 ve 00:50:00)
  - İstenen fonksiyon tablosu ($S_2 S_1 S_0$): 000 $F = A$, 001 $F = A+1$, 010 $F = A+B$, 011 $F = A+B+1$, 100 $F = A+\overline{B}$, 101 $F = A+\overline{B}+1 = A-B$, 110 $F = A-1$, 111 $F = A$.
  - Toplayıcı girişleri: her satırda $X_i = A_i$; $Y_i$ sırasıyla 0'lar, $B_i$, $\overline{B_i}$, 1'ler; $C_{in}$ ise $S_0$'ın kendisi.
  - Sonuç: $X_i = A_i$, $C_{in} = S_0$, Karnaugh diyagramından $Y_i = S_1 B_i + S_2 \overline{B_i}$.
  - $C_{in}$ yalnız en düşük anlamlı tam toplayıcıya bağlanır; diğer basamaklara bir önceki basamağın eldesi girer.
  - Slayttaki kitap tablosunda (ekrandan, 00:35:00) aynı fonksiyonlar $S_1 S_0$ ve $C_{in}$ ile verilir: 00 → $Y$ = 0'lar, 01 → $B$, 10 → $\overline{B}$, 11 → 1'ler.
- Lojik birim (ekrandan, 01:15:00)
  - Her bit dilimi için bir 4'e 1 MUX: 00 AND, 01 OR, 10 XOR, 11 NOT ($\overline{A}$). $n$ bit için $n$ MUX gerekir.
  - Aritmetik ve lojik birimin çıkışları bir 2'ye 1 MUX ile birleştirilir. Bu dördüncü seçme ucu ($S_3$ ya da mod) 0 iken aritmetik, 1 iken lojik sonuç ALU çıkışına gider.
- Shifter ve döndürücü (ekrandan, 01:20:00 ve 01:25:00)
  - 4 bitlik shifter her bit için bir 3 girişli MUX kullanır: S = 00 transfer ($H = B$), 01 sağa öteleme (sr B, boşalan bite $I_R$), 10 sola öteleme (sl B, boşalan bite $I_L$). Seri girişlere 0 verilir.
  - Döndürücü (barrel) tablosu: 00 döndürme yok, 01 bir, 10 iki, 11 üç basamak sola döndürme. Her çıkış biti bir 4'e 1 MUX'tan gelir.
  - Bu shifter'lar kombinasyonel devredir, sonucu saat beklemeden üretir; ardışıl ötelemeli yazmaçlar ise saat kenarında çalışır.
- Fonksiyon birimi tablosu ve kontrol kelimesi (ekrandan, 01:35:00 ve 02:10:00)
  - FS(3:0): 0000 $A$, 0001 $A+1$, 0010 $A+B$, 0011 $A+B+1$, 0100 $A+\overline{B}$, 0101 $A+\overline{B}+1$, 0110 $A-1$, 0111 $A$, 1000 AND, 1001 OR, 1010 XOR, 1011 $\overline{A}$, 1100 $B$, 1101 sr B, 1110 sl B. FS 0xxx ve 10xx için MF = 0, 11xx için MF = 1 (H select = FS'nin son iki biti).
  - 8 yazmaçlı yazmaç dosyası için 16 bitlik kontrol kelimesi: DA (15-13), AA (12-10), BA (9-7), MB (6), FS (5-2), MD (1), RW (0).
- Mikro işlemlerin kontrol kelimesine çevrilmesi (ekrandan, 01:40:00 ve 01:50:00)
  - $R1 \leftarrow R2 - R3$: 001 010 011 0 0101 0 1. Fonksiyon birimi yalnız $A - B$ yaptığı için çıkarılan değer B kanalından gelmelidir.
  - $R4 \leftarrow \text{sl}\ R6$: 100 XXX 110 0 1110 0 1. Öteleme yalnız B girişinde tanımlıdır.
  - $R7 \leftarrow R7 + 1$: 111 111 XXX X 0001 0 1. Artırma yalnız A girişinde tanımlıdır.
  - $R1 \leftarrow R0 + 2$: 001 000 XXX 1 0010 0 1. Sabit yalnız B kanalına girebilir.
  - Data out ← R3: XXX XXX 011 0 XXXX X 0. $R4 \leftarrow$ Data in: 100 XXX XXX X XXXX 1 1.
  - $R5 \leftarrow 0$: 101 000 000 0 1010 0 1 ($R0 \oplus R0 = 0$). Doğrudan bir "sıfırla" işlemi olmasa da kontrol kelimesiyle bu anlam verilebilir.
- Basit bilgisayarın komut kümesi (ekrandan, 02:15:00 ve 02:25:00)
  - 16 bitlik komutun üç biçimi: yazmaç (opcode 7 bit + DR + SA + SB), anlık operand (opcode + DR + SA + 3 bitlik OP), dallanma (opcode + AD'nin üst 3 biti + SA + AD'nin alt 3 biti; AD 6 bitlik işaretli görece adres).
  - Komutlar: MOVA, INC, ADD, SUB, DEC, AND, OR, XOR, NOT, MOVB, SHR, SHL, LDI, ADI, LD, ST, BRZ, BRN, JMP. Her komuttan sonra $PC \leftarrow PC + 1$ da yürütülür.
  - INC/DEC/NOT/MOVA yalnız SA ile, MOVB/SHR/SHL yalnız SB ile çalışır; bu, fonksiyon biriminin donanım kısıtından gelir.
  - LDI ve ADI'de 3 bitlik sabit sıfırla doldurularak (zero fill) $n$ bite genişletilir.
  - LD: $R[DR] \leftarrow M[R[SA]]$. ST: $M[R[SA]] \leftarrow R[SB]$ (adres A kanalından, veri B kanalından).
  - BRZ/BRN: koşul sağlanırsa $PC \leftarrow PC + \text{se}\ AD$, sağlanmazsa $PC \leftarrow PC + 1$. JMP: $PC \leftarrow R[SA]$.
- İşaret genişletme (sign extend)
  - 6 bitlik ikiye tümleyen AD'nin 5. biti 1 ise üst bitler 1 ile, 0 ise 0 ile doldurulur; değerin işareti ve büyüklüğü korunur.
- Bellekteki komutların çözülmesi (ekrandan, 02:30:00)
  - 25: `0000101 001 010 011` → SUB, $R1 \leftarrow R2 - R3$. 35: `0100000 000 100 101` → ST, $M[R4] \leftarrow R5$. 45: `1000010 010 111 011` → ADI, $R2 \leftarrow R7 + 3$.
  - 55: `1100000 101 110 100` → BRZ, SA = R6, AD = 101100 = $-20$; $R6 = 0$ ise $PC \leftarrow PC - 20$.
  - 70'teki `0000000011000000` (192) bir veri sözcüğüdür. von Neumann yapısında komut ve veri aynı bellekte olabildiğinden bir sözcüğün anlamı PC'nin oraya gelip gelmemesine bağlıdır.
- Tek çevrimli bilgisayarın tam blok diyagramı (ekrandan, 02:35:00)
  - PC, komut belleği, komut çözücü, Extend (IR(8:6) ∥ IR(2:0)), Zero fill (IR(2:0)), yazmaç dosyası, MUX B, fonksiyon birimi, veri belleği, MUX D ve dallanma denetimi (Branch Control).
  - Yeni kontrol bitleri: MW (veri belleğine yazma), PL (PC'ye yükleme yani dallanma var/yok), JB (jump mı branch mı), BC (sıfıra mı negatife mi göre dallanma). Kontrol kelimesi 20 bite çıkar.
  - Dallanma denetimi V, C, N, Z bayraklarına ve PL, JB, BC'ye bakarak PC'nin $PC+1$, $PC + \text{se}\ AD$ ya da A kanalındaki değerle mi yükleneceğine karar verir.
- Komut çözücü (ekrandan, 02:40:00 ve 02:45:00)
  - DR, SA, SB doğrudan DA, AA, BA olur. Opcode bitlerinden MB, FS, MD, RW, MW, PL, JB, BC üretilir.
  - Doğruluk tablosu (bitler 15, 14, 13, 9 → MB MD RW MW PL JB BC): yazmaçla FU işlemi 000X → 0 0 1 0 0 X X; bellek okuma 001X → 0 1 1 0 0 X X; bellek yazma 010X → 0 X 0 1 0 X X; yazmaç ve sabitle FU işlemi 100X → 1 0 1 0 0 X X; BRZ 1100 → X X 0 0 1 0 0; BRN 1101 → X X 0 0 1 0 1; JMP 111X → X X 0 0 1 1 X.
  - Opcode'lar gruplanarak seçilirse çözücü birkaç kapıya iner (ör. BC opcode'un 9. biti, JB 13. biti olur); gruplama yapılmazsa çözücü karmaşıklaşır.
- Tek çevrimde gecikme yolu (ekrandan, 02:50:00)
  - PC 0.2 ns, komut belleği 4 ns, yazmaç okuma 0.6 ns, MUX B 0.2 ns, fonksiyon birimi ya da veri belleği 4 ns, MUX D 0.2 ns, yazmaç yazma 0.6 ns. Birikimli değerler 0.2, 4.2, 4.8, 5.0, 9.0, 9.2, 9.8 ns'dir.

## Hocanın Özellikle Vurguladığı Kısımlar

- $C_{in}$'in nereye bağlandığı
  - Bit dilimi çizimi ile bütün bitlerin çizimi karıştırılmamalıdır. Kontrol ucu ($S_0$) yalnız en düşük anlamlı tam toplayıcının eldesine girer; diğer basamaklar bir önceki basamağın eldesini alır. Hoca bunu "çok önemli bir nüans" diye vurguladı.
- Kontrol kelimesini donanım kısıtına göre seçmek
  - Fonksiyon birimi yalnız $A - B$ yapar, artırma/azaltma yalnız A girişinde, öteleme ve B transferi yalnız B girişindedir, sabit yalnız B kanalına girer. Mikro işlem kontrol kelimesine çevrilirken yazmaçlar kanallara buna göre yerleştirilir.
- Aritmetik birimi fonksiyon tablosundan tasarlayabilmek
  - Verilen bir fonksiyon tablosu için $X_i$, $Y_i$ ve $C_{in}$ giriş lojikleri Karnaugh diyagramıyla bulunup tam toplayıcılarla devre kurulabilmelidir.
- Opcode seçiminin çözücüye etkisi
  - Opcode'lar uygun gruplanırsa komut çözücü çok basitleşir.

## Kısa Tekrar Notları

- Yazmaç dosyası: A/B adresleriyle iki yazmaç okunur, D adresi + Write ile bir yazmaç saat kenarında yazılır.
- $Z$ = çıkış bitlerinin NOR'u; $N$ = en yüksek anlamlı bit; $C$ = $C_{out}$; $V = C_n \oplus C_{n-1}$.
- Aritmetik birim: $X_i = A_i$, $Y_i = S_1 B_i + S_2 \overline{B_i}$, $C_{in} = S_0$.
- $A - B = A + \overline{B} + 1$; $A - 1 = A + (1\ldots1)$.
- Lojik birim: bit başına 4'e 1 MUX (AND, OR, XOR, NOT).
- Shifter: transfer, sr, sl; döndürücü: 0-3 basamak sola döndürme; ikisi de kombinasyonel.
- Kontrol kelimesi 16 bit: DA 3, AA 3, BA 3, MB 1, FS 4, MD 1, RW 1. Tam bilgisayarda MW, PL, JB, BC ile 20 bit.
- Komut 16 bit: opcode 7 bit + üç tane 3 bitlik alan.
- LDI/ADI sabitini sıfırla, dallanma ofsetini işaretle genişlet.
- `1100000 101 110 100` → BRZ R6, AD = $-20$.

## Detaylı Açıklamalar

- **Yazmaç dosyasından fonksiyon birimine.** Önceki haftalarda yazmaçlar arası veri transferi için kurulan yapı, CPU'da yazmaç dosyası olarak kullanılır. A select ve B select uçları iki ayrı MUX'u sürer, böylece iki operandlı bir komut için iki yazmaç aynı anda hazırlanır. Hedef seçimi bir dekoder ve Write işaretiyle yapılır; dekoderin seçtiği satır Write ile AND'lenir, yalnız o yazmacın Load işareti 1 olur. Yükleme saatin yükselen kenarında olur. A kanalı fonksiyon biriminin A girişine ve bellek adres hattına, B kanalı ise MUX B üzerinden fonksiyon biriminin B girişine ve bellek veri hattına gider. MUX B sayesinde B girişine komuta gömülü bir sabit de verilebilir; bu, komut çözücünün komuttan ayıkladığı değerdir.

- **Bayraklar.** Sıfır bayrağı için çıkış bitlerini OR'lamak yanlış sonuç verir (hepsi 0 iken 0 çıkar), doğru kapı NOR'dur. Negatif bayrağı ikiye tümleyen gösterimden dolayı doğrudan en yüksek anlamlı bittir. Elde bayrağı işaretsiz toplamada taşmayı gösterir ve toplayıcının elde çıkışından alınır. Taşma bayrağı iki pozitif sayının toplamının negatif ya da iki negatif sayının toplamının pozitif çıkmasıdır; bu, en yüksek anlamlı tam toplayıcıya giren ve çıkan eldelerin farklı olmasıyla aynı şeydir.

- **Aritmetik birim tasarımı.** Hoca tahtada sekiz satırlı bir fonksiyon tablosu kurdu ve her satır için toplayıcının girişlerini buldu. $A$'yı aktarmak için $X = A$, $Y = 0$, $C_{in} = 0$; $A+1$ için aynı bağlantıda $C_{in} = 1$; $A+B$ ve $A+B+1$ için $Y = B$; $A+\overline{B}$ ve $A-B$ için $Y = \overline{B}$; $A-1$ için $Y$'ye bütün bitleri 1 olan değer ($-1$) ve $C_{in} = 0$; son satırda $A + (-1) + 1 = A$. Tablo $C_{in}$'in her zaman $S_0$'a eşit olduğunu ve $X_i$'nin her zaman $A_i$ olduğunu gösterir. $Y_i$ için $S_2, S_1, S_0, B_i$ değişkenli Karnaugh diyagramında $S_0$ etkisiz kalır ve $Y_i = S_1 B_i + S_2 \overline{B_i}$ bulunur (iki AND, bir NOT, bir OR kapısı). Kitaptaki çizimde aynı devre farklı adlarla ($S_1, S_0, C_{in}$) verilir.

- **Lojik birim, ALU ve shifter.** Lojik birim her bit için AND, OR, XOR ve NOT kapılarının çıkışlarını bir 4'e 1 MUX'la seçer. Aritmetik birim (üç seçme ucu) ve lojik birim (iki seçme ucu) aynı uçları paylaşır; bir 2'ye 1 MUX ve dördüncü bir seçme ucu ALU çıkışını belirler. Shifter da MUX'larla kurulur: her çıkış biti ya kendi bitini, ya soldaki ya da sağdaki komşusunu alır. Döndürücüde her çıkış biti 4'e 1 MUX ile 0-3 basamak döndürülmüş bitlerden birini seçer ve "merdiven" biçimli bir bağlantı oluşur.

- **Kontrol kelimesi.** Fonksiyon biriminin 16 durumu 4 bitlik FS ile seçilir (15'i kullanılır). 8 yazmaçlık dosyada adresler 3'er bittir; MB, MD, RW birer bittir; toplam 16 bit. Bir mikro işlemi kontrol kelimesine çevirmek için önce işlemin hangi blokta, hangi girişte tanımlı olduğuna bakılır; kullanılmayan alanlar don't care (X) olur. $R5 \leftarrow R0 \oplus R0$ örneği, donanımın doğrudan sunmadığı bir işlemin (sıfırlama) kontrol kelimesiyle elde edilebileceğini gösterir.

- **Komut kümesi ve çözücü.** Kontrol kelimesi geniş ve seyrek bir bit dizisidir; komutlar bunun paketlenmiş halidir. 16 bitlik komutta DR, SA, SB alanları doğrudan DA, AA, BA'ya gider; 7 bitlik opcode'dan ise MB, FS, MD, RW ve tam bilgisayarda MW, PL, JB, BC üretilir. Dallanma komutlarında 6 bitlik görece adres iki parçaya bölünerek DR ve SB alanlarına yazılır, Extend bloğunda birleştirilip işaret genişletilir ve PC ile toplanır. JMP'de ise A kanalındaki yazmaç değeri doğrudan PC'ye yüklenir. Opcode'lar işlev gruplarına göre seçildiğinde çözücünün her çıkışı opcode'un bir ya da birkaç bitinin basit bir fonksiyonu olur.

- **Bellek dökümünü okumak.** Komut belleğinden okunan bir sözcük opcode, DR, SA, SB alanlarına bölünür ve tabloya bakılarak anlamı bulunur. 55. adresteki BRZ komutunda AD = 101100 negatif bir sayıdır; ikiye tümleyeni 010100 = 20 olduğundan dallanma 20 komut geriye yapılır.

- **Gecikme.** Bir komut tek çevrimde PC'den başlayıp komut belleği, yazmaç okuma, MUX B, fonksiyon birimi ya da veri belleği, MUX D ve yazmaç yazmadan geçer. Bu yayılma gecikmelerinin toplamı (slayttaki örnekte 9.8 ns) saat periyodunu sınırlar.

<!-- BELİRSİZ: Hoca PC'nin 15 bit olduğunu söyledi (komut belleğinin 15 adres ucu olduğu gerekçesiyle), ancak işaret genişletmeyi anlatırken 5-15 numaralı bitlerden söz etti. Bu kayıtta PC genişliğini gösteren kare yok. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
