# Ders 5 Çalışma Özeti

## Genel Konular

- Dersin tarihi 9 Nisan 2021 Cuma. Ders Zoom üzerinden yapıldı. Dönemin 5. haftası.
  - Asıl ders yaklaşık 00:07'de başlar. İlk dakikalar selamlaşma ve aşı sohbetidir.
- Geçen haftadan kalan programlanabilir lojik cihazlar
  - PLA'nın kısa tekrarı (bir öğrencinin isteğiyle).
  - PAL (Programmable Array Logic) yapısı ve 4 çıkışlı örnek.
- Bellek temelleri (Memory Basics)
  - RAM türleri: statik RAM (SRAM) ve dinamik RAM (DRAM).
  - Bellek organizasyonu: adres, kelime (word), kapasite gösterimi.
  - Bellek blok diyagramı ve kontrol girişleri (chip select, read/write).
  - Yazma ve okuma döngülerinin zamanlama diyagramı.
  - Uçucu (volatile) ve kalıcı (non-volatile) bellek.
  - SRAM hücresi, RAM bit dilimi (bit slice), 16×1 RAM.
  - Çakışık seçim (coincident selection): satır ve sütun decoder'ları.
  - Üç durumlu (three-state) çıkış.
- Daha büyük bellek oluşturma
  - Boyuna uzatma (daha çok satır, making larger memories).
  - Enine genişletme (daha geniş kelime, making wider memories).
  - Adres ucu, veri ucu ve çip sayısı hesap alıştırmaları.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bellek genişletme konusu önemlidir. "Bu konularla ilgili mutlaka sınavda soru olacak."
- Kitabın bölüm sonu sorularını çözün.
  - Hoca kitabın 4. baskısının PDF'ini ders duvarına koydu.
  - Çözemediğiniz soruları hocaya ya da donanım ana bilim dalı asistanlarına e-postayla sorun.
- Kapasite sorularında verilen kelime genişliğine dikkat edin.
  - "2 MB" gibi bayt cinsinden verilen kapasiteyi, elinizdeki çipin kelime genişliğine (ör. 16 bit) göre yeniden yazın. Soru bu yüzden "biraz trikli".
- 48K gibi 2'nin kuvveti olmayan sayılarda bir üst kuvveti alın.
  - 32 için 5 bit yeter. 32'yi aşan her sayı için (64'e kadar) 6 bit gerekir.
- Statik RAM pahalıdır, bu yüzden yalnız küçük kapasiteli önbellekte (cache) kullanılır.
- Bellek, işlemciye göre yavaştır. Bir okuma ya da yazma yaklaşık 4 saat periyodu sürer. Bu yüzden bellek erişiminden kaçınılır.
- Bütün bellek işlemlerini CPU yönetir.
  - Okuma: bellekteki veri CPU register'ına taşınır.
  - Yazma: CPU register'ındaki veri belleğe yazılır.
- Dersin sonunda kalan öğrencilere: "Dersin sonuna kadar bilgisayarınızın başında olun."

## Kısa Tekrar Notları

- PAL: AND dizisi programlanabilir, OR dizisi sabit. Her OR kapısı sınırlı sayıda (örnekte 3) çarpım terimi toplar.
- Bütün sigortaları bağlı AND kapısının çıkışı 0'dır: $A \cdot A' = 0$.
- SRAM: SR latch ile yapılır, hızlı ve pahalıdır, önbellekte kullanılır.
- DRAM: kapasitör ile yapılır, ucuzdur, yükünü kaybettiği için tazeleme (refresh) gerekir. Ana bellek DRAM'dir.
- RAM uçucudur (volatile). Güç gidince veri kaybolur. ROM kalıcıdır (non-volatile).
- $2^k \times n$ bellek: $k$ adres ucu, $2^k$ kelime, her kelime $n$ bit.
- Kontrol girişleri:
  - Chip select (CS) 0 ise çip hiçbir işlem yapmaz.
  - CS = 1 ve $R/\overline{W} = 1$: seçili kelimeden okuma.
  - CS = 1 ve $R/\overline{W} = 0$: seçili kelimeye yazma.
- Ön ekler: K = $2^{10}$, M = $2^{20}$, G = $2^{30}$, T = $2^{40}$, P = $2^{50}$ (sonra E, Z, Y).
- Gerekli çip sayısı = toplam kapasite / bir çipin kapasitesi.
- Boyuna uzatma: adres uçları, veri uçları ve $R/\overline{W}$ ortak bağlanır. Üst adres bitleri bir decoder ile çiplerin CS girişlerini seçer.
- Enine genişletme: adres uçları ve CS ortak bağlanır. Veri uçları yan yana konur (biri üst bayt, biri alt bayt).
- Çakışık seçim: $k$ adres biti satır ve sütun decoder'larına bölünür. Decoder'lar küçülür, AND kapısı sayısı azalır.

## Detaylı Açıklamalar

### PLA tekrarı

- ROM: AND dizisinin önü sabit (decoder), OR dizisinin önü programlanabilir.
- PLA: hem AND hem OR dizisinin önü programlanabilir.
- Ders 4'teki örnekte $F_1$ ve $F_2$'de $AC$ ortak terimi vardı. Bu yüzden 5 yerine 4 AND kapısı yetti.
- AND kapısının kaç girişli olduğu önemli değildir. Örnekte her AND kapısının 6 girişi vardır ($A, A', B, B', C, C'$). Tasarımcı yalnız hangi sigortaların bağlı kalacağını seçer.
- Bir öğrenci PLA'nın avantajını sordu. Hocanın cevabı:
  - ROM sabit veri saklamak içindir. Birkaç fonksiyonu ROM ile gerçeklemek verimli değildir.
  - PLA, verilen fonksiyonları en az maliyetle gerçeklemeyi sağlar. Çok sayıda üretimde tercih edilebilir.

### PAL (Programmable Array Logic)

- ROM'un tersidir: AND kapılarının önü programlanabilir, OR kapılarının önü sabittir.
- Örnek yapı 4 girişlidir ($A, B, C, D$). Her giriş tersleyen tampondan geçer. Her değişkenin kendisi ve tümleyeni hazırdır.
- Örnekteki her OR kapısı en fazla 3 çarpım terimi toplayabilir.
- Örnek: dört fonksiyon ($W, X, Y, Z$) gerçeklenecek.
  - $W = ABC' + A'B'CD'$ (iki terim).
  - $Z$ dört terimlidir. İki terimi $W$ ile aynıdır.
  - OR kapısı 3 girişli olduğu için $Z$ doğrudan sığmaz.
  - Çözüm: $W$ çıkışı geri besleme ile PAL'e giriş olarak verilir. Böylece $Z = W + AC'D' + A'B'C'D$ biçiminde 3 terimle yazılır.
- Kullanılmayan AND kapısı: kapının ortasına tek bir çarpı konur. Bu, bütün sigortaların bağlı olduğu anlamına gelir.
  - Girişte hem $A$ hem $A'$ olduğu için çıkış her zaman 0'dır. OR kapısını etkilemez.

### RAM türleri

| Özellik | Statik RAM (SRAM) | Dinamik RAM (DRAM) |
| :--- | :--- | :--- |
| Hücre | SR latch | Kapasitör |
| Maliyet | Pahalı (hocaya göre yaklaşık 10 kat) | Ucuz |
| Tazeleme | Gerekmez | Gerekir (refresh) |
| Kullanım | Önbellek (cache) | Ana bellek |

- DRAM'de kapasitör zamanla yükünü kaybeder. Tazeleme işlemi hücredeki değeri okuyup yeniden yazar.

### Bellek organizasyonu

- Bellek: bilgiyi saklayan hücreler ve bu hücrelere veri yazan, okuyan devrelerin toplamıdır.
- Bellek adresi bir satırı (kelimeyi) seçer. Her satırda 1 bit, 1 bayt ya da bir kelime (word) tutulabilir.
- Slayttaki örnek mimariler:
  - PDP-8: 12 bit adres (4096 kelime), her kelime 12 bit.
  - IBM 360: 24 bit adres, 16 M bayt. 32 bitlik veri yoluyla $4\text{M} \times 32$ bit olarak da yazılabilir.
  - Intel 8080: 16 bit adres (65536 satır), her satır 8 bit.
- Örnek: 10 adres biti, 16 veri biti.
  - $2^{10} \times 16 = 1\text{K} \times 16$.
  - Bayt cinsinden: $2^{10} \times 2 \times 8$ bit $= 2$ KB.
  - $1\text{K} \times 16$ gösterimi adres ve veri ucu sayısını, "2 KB" gösterimi toplam kapasiteyi verir. İkisini de bilin.

### Yazma ve okuma zamanlaması

- Örnekte CPU saat periyodu 20 ns.
- Yazma döngüsü:
  - Önce bellek etkinleştirme (memory enable, CS) 1 yapılır ve adres, adres yoluna konur.
  - Sonra $R/\overline{W}$ 0'a çekilir. CPU yazılacak veriyi veri yoluna koyar.
  - Yazma yaklaşık 4 periyotta (T4'ün sonunda) biter. Slaytta yaklaşık 75 ns.
- Okuma döngüsü:
  - CS 1, $R/\overline{W}$ 1, adres yolda.
  - Bellek adresi çözer, geçerli veri T4 içinde veri yoluna düşer. Slaytta yaklaşık 65 ns.
- Sonuç: İşlemci her saat periyodunda bir komut işleyebilirken bir bellek erişimi yaklaşık 4 periyot sürer.

### SRAM hücresi ve RAM bit dilimi

- SR latch doğruluk tablosu: $SR = 00$ değişmez, $01$ reset ($Q=0$), $10$ set ($Q=1$), $11$ tanımsız.
- SRAM hücresi:
  - Select = 0 ise giriş AND kapıları kapanır. $S = R = 0$ olur, latch değerini korur.
  - Select = 1 ise $B$ girişi $S$'ye, $B'$ girişi $R$'ye gider. $B = 1$ ise set, $B = 0$ ise reset olur.
  - Select aynı zamanda çıkıştaki AND kapısını da kontrol eder. Okuma için de gereklidir.
- $m$ kelimeli ve kelime başına $n$ bitli bir RAM çipinde $m \times n$ ikili hücre vardır.
- RAM bit dilimi: Hücreler alt alta dizilir. Her satırın select girişine bir kelime seçme (word select) hattı gelir.
  - Yazma: bit select = 1 ve $R/\overline{W} = 0$ iken Data in'den $B$ ve $B'$ üretilip hücrelere gönderilir.
  - Okuma: bit select = 1 iken seçili hücrenin değeri Data out'a çıkar.
- 16×1 RAM: 4→16 decoder ve 16 hücre. 4 adres ucu, 1 bit Data in, 1 bit Data out, $R/\overline{W}$ ve memory enable.

### Çakışık seçim (coincident selection)

- Büyük belleklerde tek decoder çok büyür. Ör. 1 MB ($2^{20} \times 8$) için 20→$2^{20}$ decoder gerekir.
- Çözüm: Adres bitleri satır seçme (row select) ve sütun seçme (column select) olarak ikiye bölünür. 20 bit için iki tane 10→$2^{10}$ decoder kullanılır.
- 16×1 RAM örneği:
  - 4→16 decoder yerine iki tane 2→4 decoder.
  - AND kapısı sayısı 16'dan 8'e iner.
  - Adres $1001$ (hücre 9): üst iki bit $10$ satır 2'yi, alt iki bit $01$ sütun 1'i seçer. Kesişimdeki hücre seçilir.
- 8×2 RAM örneği:
  - 3 adres biti eşit bölünmez. Üst 2 bit satır decoder'ına, alt 1 bit sütun decoder'ına gider.
  - Sütun decoder'ının her çıkışı iki sütunu birden seçer. Böylece her adreste 2 bit okunur.
  - Adres $011$: satır $01$ (satır 1), sütun $1$. Kesişimdeki iki hücre okunur.
- Bir öğrenci 3 boyutlu yapı olur mu diye sordu. Hoca: Bir select hattını 8 hücreye birden vermek, 8 biti birlikte seçmek gibidir. Bu bir tür üçüncü boyut gibi düşünülebilir.

### RAM çipine dışarıdan bakış

- 64K × 8 RAM: $2^{16} \times 8$. 16 adres ucu, 8 bit Data in, 8 bit Data out, CS ve $R/\overline{W}$.
- Çıkıştaki üçgen sembolü üç durumlu (three-state) çıkıştır.
  - Üçüncü durum yüksek empedanstır (High-Z).
  - Bu sayede birden çok çipin çıkışı aynı hatta bağlanabilir.

### Kapasite alıştırmaları

- Adres ucu sayısı örnekleri:
  - 64K = $2^6 \cdot 2^{10} = 2^{16}$, 16 adres ucu.
  - $2^{16} \times 32$ bit: 16 adres ucu, 32 veri ucu. Toplam $2^{16} \times 4$ bayt $= 2^{18}$ bayt $= 256$ KB.
  - 2M = $2^{21}$, 21 adres ucu.
  - 4G = $2^{32}$, 32 adres ucu.
- Adres ve veri ucu sayıları:

| Bellek | Adres ucu | Veri ucu |
| :--- | :---: | :---: |
| 48K × 8 | 16 | 8 |
| 512K × 32 | 19 | 32 |
| 64M × 64 | 26 | 64 |
| 2G × 1 | 31 | 1 |

### Boyuna uzatma: 4 tane 64K × 8 ile 256K × 8

- Her çip: 16 adres ucu, 8 veri ucu.
- Hedef: $256\text{K} \times 8 = 2^{18} \times 8$, 18 adres ucu.
- Çip sayısı: $2^{18} / 2^{16} = 4$.
- Bağlantı:
  - $A_0$-$A_{15}$ bütün çiplerde ortak. Bütün çiplerin $A_0$ uçları birbirine, $A_1$ uçları birbirine bağlanır.
  - $A_{17}A_{16}$ bir 2→4 decoder'a girer. Decoder'ın her çıkışı bir çipin CS girişine gider.
  - $R/\overline{W}$, Data in ve Data out ortak bağlanır. Çıkış yine 8 bittir.
- Hangi çip? $A_{17}A_{16} = 00$ ise en üstteki çip, $01$ ise ikinci, $10$ ise üçüncü, $11$ ise dördüncü seçilir. Diğer çiplerin CS'si 0 olduğu için çıkışları veri yolunu etkilemez.

### Enine genişletme: 2 tane 64K × 8 ile 64K × 16

- Adres ucu sayısı değişmez: 16.
- İki çip yan yana konur. Adres uçları ve CS ortak bağlanır.
- Soldaki çip üst 8 biti, sağdaki çip alt 8 biti verir. Toplam 16 bit.

### Örnek: 128K × 16 çiplerle 2 MB

- Çip sayısı: $\dfrac{2^{21} \times 8}{2^{17} \times 16} = \dfrac{2^{24}}{2^{21}} = 8$.
- 2 MB'ı çipin kelime genişliğine göre yazın: $2^{21} \times 8 = 2^{20} \times 16 = 1\text{M} \times 16$. Gereken adres ucu 20.
- Her çipin adres ucu: 17 ($A_0$-$A_{16}$). Bu uçlar bütün çiplere ortak bağlanır.
- Kalan 3 bit ($A_{17}, A_{18}, A_{19}$) bir 3→8 decoder'a girer. Her çıkış bir çipin CS girişine gider.
- 16 bit Data in ve 16 bit Data out bütün çiplerde ortak bağlanır.
- Bir öğrenci 1,96 MB istenseydi ne olurdu diye sordu. Hoca: Yine 8 çip gerekir. Fazla kısmı kullanmayabilirsiniz.

### Örnek: 64K × 8 çiplerle 512K × 16 (iki yönde genişletme)

- Çip sayısı: $\dfrac{2^{19} \times 16}{2^{16} \times 8} = 2^3 \times 2 = 16$.
- Yerleşim: 8 satır, her satırda yan yana 2 çip (üst bayt ve alt bayt).
- Adres: $512\text{K} = 2^{19}$, 19 adres ucu.
  - $A_0$-$A_{15}$ bütün çiplere ortak.
  - $A_{16}, A_{17}, A_{18}$ bir 3→8 decoder'a girer. Her çıkış bir satırdaki iki çipin CS girişine birlikte gider.
- Veri: Soldaki çipler $D_{15}$-$D_8$, sağdaki çipler $D_7$-$D_0$ hatlarını oluşturur.

### Duyurular ve kısa sınav

- Bir kısa sınav daha yapılacak.
- İlk kısa sınavda süre kısa geldi. Özellikle T flip-flop ile ikili sayıcı tasarlanan kısım zaman aldı.
- Hoca değerlendirmenin esnek olacağını söyledi. Ör. çoklayıcı girişlerinin her biri ayrı puanlanıyor. "Aynı veriyi tutsun" seçeneği çalışıyorsa 25 puan alınıyor.
- Hoca, sınavı birlikte okudukları bir öğretim üyesinden "Erkan Hoca" diye söz etti.

### Ders sonrası notlar

- **Ders adı:** Hoca dersi birkaç kez "bilgisayar donanımı dersi" diye andı. Anlatılan konular (programlanabilir lojik, bellek, register transferi) Mano'nun *Logic and Computer Design Fundamentals* kitabına uyuyor.
- **512K × 16 örneği:** Hoca çizimde önce "18 tane adres girişi var" dedi. Sonra kendisi 19 olarak düzeltti. Doğrusu 19'dur: 16 ortak adres ucu ve 3 decoder girişi.
- **"Adres uçlarını 2'ye bölüyorum" (coincident selection):** 16×1 örneğinde AND kapısı sayısı yalnız decoder çıkışları için 16'dan 8'e iner. Her hücrede satır ve sütun seçimini birleştiren ek bir AND işlemi de vardır. Hocanın karşılaştırması yalnız decoder'ları kapsar.
- **"Pardon 4 milyon byte" ifadesi:** IBM 360 örneğinde 16 M bayt, 32 bitlik kelimelerle $4\text{M} \times 32$ bit olarak yazılır. Kelime sayısı 4 M'dir, bayt sayısı yine 16 M'dir.
- **PAL örneği:** $Z$'nin kalan iki terimi altyazıda karışık okunuyor. Kitaptaki örnekle uyumlu biçimi: $Z = ABC' + A'B'CD' + AC'D' + A'B'C'D = W + AC'D' + A'B'C'D$.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
