# Ders 13 Çalışma Özeti

## Genel Konular

- Kısa sınav çözümü: kontrol kelimesi ve komut kodlama (tek çevrimli bilgisayar)
  - Kontrol kelimesi alanları DA, AA, BA, MB, FS, MD, RW, MW, PL, JB, BC'dir. Komutun kullanmadığı alanlar "don't care" bırakılır (ekrandan, 00:05:00).
  - Store (ST RA, RB): D kanalı kullanılmaz. A kanalı adres, B kanalı veri verir; MW = 1, RW = 0. Dallanma olmadığı için PL = 0.
  - XOR: üç operand (DR, SA, SB), FS = 1010, MD = 0 (function unit çıkışı), RW = 1.
  - Move B: A kanalı kullanılmaz; FS = 1100 ($F = B$).
  - Add immediate: sabit, komutun 3 bitlik OP alanına gömülür (3 = 011). MB = 1 seçilir, çünkü sabit B kanalı yerine komuttan gelir. FS = 0010 ($F = A + B$).
  - Jump: yalnız A kanalı kullanılır (ör. R4); PL = 1, JB = 1 ile PC = R[SA] olur.
  - Komut kodlamada (ikinci kısım) opcode komut tablosundan alınır. Branch on negative komutunda $-20$ ofseti 6 bitlik ikiye tümleyenle $101100$ olarak AD (sol) ve AD (sağ) alanlarına bölünür.
- Kısa sınav çözümü: tam toplayıcılarla aritmetik birim tasarımı
  - 16 fonksiyon için 4 seçim biti ($S_3S_2S_1S_0$) ve 16'ya 1'lik MUX'lar gerekir.
  - Genel yapı: $X = f_1(A, S)$, $Y = f_2(B, S)$, $C_{in} = f_3(A, B, S)$. Soruda verilen kısıt gereği $C_{in} = S_0$ olur (ekrandan, 00:10:00).
  - Her fonksiyon, $C_{in}$ değerine göre X ve Y girişlerine A, $\bar A$, B, $\bar B$, 0 ya da 1111... ($-1$) verilerek elde edilir.
  - Bayraklar: S = sonucun en anlamlı biti, C = en anlamlı bitin elde çıkışı, Z = tüm toplam bitlerinin NOR'u, $V = C_6 \oplus C_7$.
- Kısa sınav bonus soruları
  - CMP A, B ile V = 1, N = 0, C = 1, Z = 0 üreten bir A, B ikilisi yoktur (hocanın çözümü, C'yi borç (borrow) kabul ederek).
  - 10 bitlik komut, 8 yazmaç, iki operand: $3 + 3 = 6$ bit operand, 4 bit opcode, $2^4 = 16$ opcode.
- Sanal bellek (virtual memory) ve bellek hiyerarşisi
  - Cache, ana bellekle işlemci arasını hızlandırır. Sanal bellek hiyerarşinin öbür ucudur: ikincil bellek (disk) ile ana bellek arasındaki aktarımı yönetir.
  - Her programın kendine ait, fiziksel bellekten büyük olabilen bir sanal adres uzayı vardır. Farklı programların sanal sayfaları fiziksel bellekte aynı yerlere düşebilir.
  - Aktarım birimi sayfadır (page). Cache'teki blok (line) kavramının karşılığıdır.
  - Temel tasarım soruları (ekrandan, 00:30:00): sayfa boyutu, bellek doluysa hangi sayfanın çıkarılacağı (replacement policy), yeni sayfanın nereye konacağı (placement policy), eksik sayfanın yalnız hata anında getirilmesi (demand load policy).
  - Taban-sınır (base and bound) yerleşiminde parçalanma (fragmentation) sorunu çıkar: toplam boşluk yeterli olsa da bitişik olmadığı için yeni program yerleşemez. Sayfalama bu sorunu çözer, çünkü bütün parçalar aynı boydadır (ekrandan, 00:35:00 ve 01:00:00).
- Adres çevirisi ve sayfa tablosu (page table)
  - Sanal adres = sanal sayfa numarası (VPN) + sayfa ofseti. Fiziksel adres = fiziksel sayfa numarası (PPN) + aynı ofset (ekrandan, 00:40:00).
  - $PPN = \text{PageTable}[VPN]$; fiziksel ofset = sanal ofset.
  - Sayfa tablosu satırı: valid biti, erişim hakları (read only, read/write, executable) ve PPN. Tablo $2^{VPN}$ satırlıdır, ana bellekte tutulur ve işletim sistemi tarafından yönetilir. Her programın kendi sayfa tablosu vardır (ekrandan, 00:50:00).
  - Matematiksel tanım: MAP(a) = a' (veri bellekteyse) ya da $\theta$ (yoksa, page fault). Page fault olunca işletim sistemi sayfayı diskten ana belleğe taşır (ekrandan, 00:55:00).
- Cache ile sanal belleğin karşılaştırılması (ekrandan, 01:20:00)
  - Blok/line ↔ page, miss ↔ page fault.
  - Cache'te direct mapped ya da set associative; sanal bellekte fully associative yerleşim.
  - Değiştirme: cache'te LRU ya da random; sanal bellekte LRU.
  - Yazma: cache'te write through ya da write back; sanal bellekte write back.
- TLB (Translation Lookaside Buffer)
  - Sayfa tablosunun cache'idir. VPN önce TLB'de aranır; hit ise PPN doğrudan alınır. Miss ise sayfa tablosuna bakılır; orada da valid = 0 ise page fault olur (ekrandan, 01:25:00).
  - TLB fully associative ise tag = VPN'dir. Set associative ise VPN index ve tag'e bölünür.
  - TLB satırında valid, dirty, tag (VPN) ve veri (PPN) bulunur. Dirty biti, sayfanın ana bellekte güncellenip diskte güncellenmediğini gösterir.
- Sayfa değiştirme politikaları (ekrandan, 01:45:00)
  - Random, FIFO (en eski yükleneni çıkar), Optimal/MIN (en uzak gelecekte kullanılacak olanı çıkar), LRU (en uzun süredir kullanılmayanı çıkar), NFU/Clock (LRU yaklaşımı).
  - Üç çerçeve, referans dizisi A B C A B D A D B C B: FIFO 7, LRU 5, Optimal 5 page fault.
- Bütünleşik örnek: TLB + sayfa tablosu + L1 cache
  - Sayfa 1 KB, veri yolu 32 bit, sanal adres 20 bit, fiziksel adres 18 bit; TLB fully associative 16 girişli; L1 8-way set associative, blokta 8 word, toplam 512 word.
  - VPN 10, VPO 10, TLB tag 10, PPN 8, sayfa tablosu $2^{10}$ satır; cache tag 10, index 3, word offset 3, byte offset 2.
  - 0x04AA4: TLB hit, PPN A1, fiziksel adres 0x286A4. 0x078E6: TLB miss, page fault yok, PPN 57, fiziksel adres 0x15CE6.
- Cache örnekleri
  - 64 KB direct mapped, blok 4 word (32 byte), 32 bit adres: tag 16, index 11, word offset 2, byte offset 3.
  - Aynı cache'e 16 referans: 5 miss, 11 hit.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sanal bellek ile cache arasındaki köprü fiziksel adrestir
  - Cache adres bölmesi sanal adres genişliğiyle değil fiziksel adres genişliğiyle yapılır. Bütünleşik örnekte cache için 20 değil 18 bit bölünür; tag = $18 - (3 + 3 + 2) = 10$.
- Ofset sanal ve fiziksel adreste aynıdır
  - Sayfa diskten belleğe olduğu gibi kopyalanır. Sayfa içindeki konum değişmez, yalnız sayfa numarası değişir.
- TLB'nin yapısı tag alanını belirler
  - Fully associative TLB'de tag = VPN'dir; set associative TLB'de VPN'in bir kısmı index olur. Sınavda bu değiştirilerek soru çeşitlendirilebilir.
- Fully associative yapıda adres bölmesinde index alanı yoktur
  - Direct mapped ve set associative'de satır (küme) sayısı index alanını belirler.
- Bütünleşik örnek "resmin tamamını görmek" için önemli bir örnektir
  - Sorunun ikinci aşamasında TLB, sayfa tablosu ve cache içerikleri verilip TLB hit/miss, page fault ve L1 hit/miss sorulabilir.
- Verilen bir kodun cache yapısını ne kadar verimli kullandığını yorumlayabilmek beklenir.

## Kısa Tekrar Notları

- Ofset bit sayısı = $\log_2(\text{sayfa boyutu})$; VPN = sanal adres − ofset; PPN = fiziksel adres − ofset.
- Sayfa tablosu satır sayısı $= 2^{VPN}$.
- Fiziksel adres = PPN ile ofsetin yan yana yazılması (birleştirme).
- TLB hit → PPN TLB'den; TLB miss → sayfa tablosu; valid = 0 → page fault.
- TLB'de tag eşleşse bile valid = 0 ise miss sayılır.
- Cache: byte offset = $\log_2(\text{word byte sayısı})$, word offset = $\log_2(\text{bloktaki word})$, index = $\log_2(\text{küme sayısı})$, tag = kalan.
- Sanal bellek: fully associative, LRU, write back.
- Örnek sonuçlar: FIFO 7, LRU 5 page fault; 64 KB DM cache 16/11/2/3; 16 referansta 5 miss.

## Detaylı Açıklamalar

- **Kısa sınavda aritmetik birim tasarımı.** Tam toplayıcı tabanlı aritmetik birimde her işlem $F = X + Y + C_{in}$ olarak yazılır. $C_{in} = S_0$ kısıtı yüzünden çift numaralı fonksiyonlarda elde 0, tek numaralılarda 1'dir. Örneğin $A$ fonksiyonunda elde 1 olduğu için Y'ye $-1$ (bütün bitler 1) verilir: $A + (-1) + 1 = A$. $A - B$ için elde 1 iken $Y = \bar B$ verilir: $A + \bar B + 1$. $\bar A$ için elde 0 iken $X = \bar A$, $Y = 0$ verilir. $0$ için elde 1 iken X ya da Y'den biri $-1$ verilir. 1 bitlik tam toplayıcılarla kurulursa her dilimin elde girişine bir önceki dilimin elde çıkışı bağlanır; yalnız 0. bitin elde girişine $S_0$ bağlanır. MUX'ların seçim uçları ortaktır ve fonksiyon seçme bitlerine bağlanır.
- **Bonus soru (CMP).** CMP, $A - B$ işlemidir. Hoca C'yi borç olarak yorumlar: C = 1 için işaretsiz $A < B$ olmalıdır. V = 1 ve N = 0 için iki negatif sayının toplamı pozitif çıkmalıdır, yani $A + (-B)$ işleminde A küçük bir negatif sayı (en anlamlı bit 1), B büyük bir pozitif sayı (en anlamlı bit 0) olmalıdır. Bu durumda işaretsiz olarak $A > B$ olur ve C = 1 koşulu sağlanamaz. Bu yüzden böyle bir ikili yoktur.
  - **Ders sonrası not:** Bu sonuç C'nin borç anlamına geldiği kabulüne bağlıdır (python ile tüm 8 bitlik ikililer denendi, borç kabulünde 0 ikili çıktı). Mano & Kime'deki function unit'te çıkarma $A + \bar B + 1$ ile yapılır ve C bu toplamanın elde çıkışıdır. Bu yorumda C = 1, işaretsiz $A \ge B$ demektir ve örneğin $A = 80_{16}$, $B = 01_{16}$ ikilisi V = 1, N = 0, C = 1, Z = 0 verir.
- **Sanal adresin çevrilmesi.** Programın ürettiği sanal adres ikiye bölünür. Düşük anlamlı kısım (ofset) sayfa boyutuna göre belirlenir ve fiziksel adrese olduğu gibi geçer. Yüksek anlamlı kısım (VPN) sayfa tablosunda index olarak kullanılır ve oradan PPN okunur. Slayttaki basit örnekte program 32 KB'lık (32 adet 1 KB'lık sayfa) sanal alana, bellek ise 8 KB'lık (8 sayfa) alana sahiptir. Sanal adres $5 + 10 = 15$ bit, fiziksel adres $3 + 10 = 13$ bittir ve sayfa tablosu 32 satırdır.
- **TLB örneği (Example-2, ekrandan, 01:30:00).** VPN 20 bit, PPN 12 bit, ofset 12 bittir; sanal adres 32, fiziksel adres 24 bittir. TLB fully associative olduğu için tag doğrudan VPN'dir. 02BB4A65: tag 02BB4 var ve valid = 1, hit; fiziksel adres 45CA65. 0E45FB32: tag var ama valid = 0, TLB miss. Page fault olup olmadığı sayfa tablosuna bakmadan bilinemez. 0D34E9DC: tag yok, miss. 03CA0777: tag var, valid = 0, miss.
- **Sayfa değiştirme örneği (ekrandan, 01:40:00).** FIFO'da ilk üç referans boş çerçevelere girer (3 fault). D gelince en eski A çıkar, sonra A gelince B çıkar, B gelince C çıkar, C gelince A çıkar: toplam 7 fault. LRU'da D gelince en uzun süredir kullanılmayan C çıkar, son C gelince A çıkar: toplam 5 fault. Optimal'de D gelince en uzak gelecekte kullanılacak C çıkar. Son C geldiğinde A ve D bir daha kullanılmadığı için eşittir ve biri rastgele seçilir. Toplam 5 fault (python ile doğrulandı; sayı derste söylenmedi).
- **Bütünleşik örnek.** 1 KB sayfa → 10 bit ofset; 20 bit sanal adres → 10 bit VPN; 18 bit fiziksel adres → 8 bit PPN. L1 cache'te bir blok 8 word, 8-way olduğu için bir kümede 64 word vardır; $512 / 64 = 8$ küme → 3 bit index. Word 4 byte → 2 bit byte offset; blokta 8 word → 3 bit word offset; tag $18 - 8 = 10$ bit. 0x04AA4 adresinde VPN = 0x012, VPO = 0x2A4; TLB'de 012 valid ve PPN = A1 olduğundan fiziksel adres $A1 \cdot 2^{10} + 2A4 = 0x286A4$. 0x078E6 adresinde VPN = 0x01E, VPO = 0x0E6; TLB'de yok, sayfa tablosunda valid = 1 ve PPN = 57, fiziksel adres 0x15CE6 (ekrandan, 02:10:00).
- **64 KB direct mapped cache (ekrandan, 02:25:00).** $64 \cdot 2^{10} / 32 = 2^{11}$ satır → 11 bit index. Bir word $32/4 = 8$ byte → 3 bit byte offset; blokta 4 word → 2 bit word offset; tag $32 - 16 = 16$ bit. Boş cache'e 4, 16, 32, 20, 80, 68, 76, 224, 36, 44, 16, 172, 20, 24, 36, 68 adresleri sırayla erişildiğinde miss'ler 4, 32, 80, 224, 172 adreslerindedir. Her miss'te 32 byte'lık blok (ör. 0-31, 32-63, 64-95, 224-255, 160-191) ilgili satıra getirilir. Sonuç 5 miss, 11 hit (ekrandan, 02:30:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
