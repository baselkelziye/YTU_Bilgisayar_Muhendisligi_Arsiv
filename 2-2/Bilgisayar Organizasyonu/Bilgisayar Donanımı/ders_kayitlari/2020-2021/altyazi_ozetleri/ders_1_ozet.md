# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin tarihi 12 Mart 2021 Cuma. Ders Zoom üzerinden yapıldı.
  - Asıl ders yaklaşık 00:06:24'te başlar. Kaydın başı bekleme kısmıdır.
  - Hoca dersin adını "Bilgisayar Donanımı" olarak anıyor (ders kodu BLM2022). Ders 2 grupta veriliyor; diğer grubu Erkan Hoca veriyor.
- Dersin tanıtımı ve işleyişi
  - Ders, Lojik Devreler dersinin devamı gibidir. İşlemci, bellek, çevre birimleri ve portlar işlenecek.
  - İlk 2-3 hafta lojik konularının hızlı tekrarı yapılacak.
  - Ders kitabı: M. M. Mano ve C. R. Kime, *Logic and Computer Design Fundamentals*, 5. baskı (2015).
  - Duyurular ve kaynaklar Online YıldızEdu ders sayfasından paylaşılır. Avesis'e duyuru konmaz.
- Haftalık plan (ders tanıtım formundan)
  - Kombinasyonel ve ardışıl devreler, saklayıcı ve sayıcılar, programlanabilir yapılar (PLD, PLA, PAL), RAM ve ROM.
  - Saklayıcı transfer işlemleri, ortak veri yolu, komut yapısı ve adresleme yöntemleri.
  - Merkezi işlem birimi (CPU) tasarımı ve pipeline, giriş/çıkış birimleri, önbellek (cache) map teknikleri, sanal bellek ve sayfa tabloları.
  - 23 Nisan ve Ramazan Bayramı (14 Mayıs) haftalarında ders yok. Vize 30 Nisan haftasında (akademik takvime göre).
- Lojik kapılar ve Boole cebri tekrarı
  - AND, OR, NOT, NAND, NOR, XOR kapıları ve sembolleri.
  - Boole cebri kuralları: etkisiz eleman, tümleyen, değişme, dağılma, involution, yutma (absorption), De Morgan.
- Lojik fonksiyonların gösterimi
  - Doğruluk tablosu, lojik ifade, devre şeması ve HDL (Verilog, VHDL).
  - Örnek: 3 girişli çoğunluk (majority) fonksiyonu.
  - Karnaugh haritası ile sadeleştirme.
- Sayı sistemleri
  - 0-18 arası sayıların ikilik ve onaltılık karşılıkları.
  - İşaretli sayılar: işlemcide yalnızca ikiye tümleyen (two's complement) kullanılır.
- Kombinasyonel yapı taşları
  - Multiplexer (MUX), decoder, demultiplexer, encoder, priority encoder.
  - Küçük MUX ve decoder'larla büyüklerini kurmak.
  - Priority encoder'ın kesme (interrupt) isteklerinde kullanımı.
- Problem çözümü (Mano kitabından 4 soru, whiteboard uygulamasıyla)
  - Decoder ve 8x2 AND-OR ile 8'den 1'e MUX.
  - Decoder ve OR kapılarıyla 3 fonksiyon.
  - 8'den 1'e MUX ve bir inverter ile 4 değişkenli fonksiyon.
  - 4'ten 1'e MUX ve harici kapılarla 4 değişkenli fonksiyon.

## Hocanın Özellikle Vurguladığı Kısımlar

- Değerlendirme: 1 ara sınav %30, 2 kısa sınav (2 x %15) %30, final %40.
  - Ödev yok. Kısa sınavlar 4. hafta (2 Nisan) ve 13. hafta (4 Haziran).
  - Kısa sınavların amacı derse hazırlıklı gelmenizdir.
- Devam zorunluluğu %70'tir. Devamsız öğrencinin notu F0 olur.
- Dönemin ilk yarısı kolay gelecek. İkinci yarısı (CPU, giriş/çıkış, cache, sanal bellek) dersin asıl kısmıdır.
  - Bu konular İşletim Sistemleri dersindeki bellek yönetimini anlamak için gereklidir.
- XOR kapısının genel tanımı: girişlerdeki 1'lerin sayısı tekse çıkış 1'dir.
  - Bu tanım 2'den fazla girişte de geçerlidir. XOR bu yüzden bir çift eşlik (even parity) üretecidir.
- İşaretli sayılarda yalnızca ikiye tümleyeni düşünün. Öğrenciler bu konuda çok hata yapıyor.
- MUX, decoder ve encoder çizimlerinde giriş ve çıkış ağırlıklarını (0, 1, 2...) mutlaka yazın.
  - Ağırlıklar yazılmazsa çözüm "hiçbir anlam ifade etmez".
- Encoder'da girişlerden aynı anda yalnızca biri 1 olabilir. Bunu tasarımcı garanti eder.
- Priority encoder'da önce geçerlilik (valid) biti Z'ye bakılır. Z = 0 ise diğer çıkışlar önemsizdir.
- Ders kitabını edinin ve bölüm sonu problemlerini çözün.

## Kısa Tekrar Notları

- AND: girişlerden biri bile 0 ise çıkış 0. OR: girişlerden en az biri 1 ise çıkış 1.
- XOR: 1'lerin sayısı tekse çıkış 1. Even parity üreteci olarak çalışır.
- Etkisiz eleman: $x \cdot 1 = x$, $x + 0 = x$.
- Yutma: $x(x + y) = x$, $x + xy = x$.
- De Morgan: $\overline{xy} = \bar{x} + \bar{y}$, $\overline{x + y} = \bar{x}\,\bar{y}$.
- Çoğunluk fonksiyonu (3 giriş): $F = AB + AC + BC$.
- 4 bit ikiye tümleyen aralığı: $-8 \ldots +7$. Genel olarak $n$ bit: $-2^{n-1} \ldots 2^{n-1}-1$.
- $n$ girişli MUX için $\log_2 n$ seçme ucu gerekir.
- $n$ girişli decoder $2^n$ çıkış üretir. Enable = 0 ise bütün çıkışlar 0.
- $2^n$ girişli encoder $n$ çıkış üretir.
- 4'ten 1'e MUX = 3 tane 2'den 1'e MUX. 16'dan 1'e MUX = 5 tane 4'ten 1'e MUX.
- 4'ten 16'ya decoder = 5 tane 2'den 4'e decoder.
- Sadeleştirmenin amacı: daha az kapı, daha düşük maliyet, daha anlaşılır devre.

## Detaylı Açıklamalar

### Dersin işleyişi ve plan

Ders Cuma günleri yapılan zorunlu bir derstir. Hoca dersin Lojik Devreler dersinin üzerine kurulduğunu söyledi. İlk haftalarda lojik konuları hızla tekrar edilecek. Lojik bilgisi eksik olanlar (özellikle bilimsel hazırlık öğrencileri) kitabın ilk 5-6 bölümünü erkenden çalışmalı.

Dersin ana hedefi bir CPU'nun yapı taşlarını öğrenmek ve bunları birleştirerek işlemci tasarlamaktır. Dönem sonuna doğru giriş/çıkış haberleşmesi, önbellek map teknikleri (direct mapped, set associative, associative) ve sanal bellek (paging, sayfa tabloları) işlenecek.

### Lojik kapılar ve XOR

Hoca kapıları "tek cümleyle" tanımlatmak istedi.

- AND: girişlerden bir tanesi bile 0 ise çıkış 0 olur.
- OR: girişlerden bir veya daha fazlası 1 ise çıkış 1 olur.
- NAND: AND + NOT. NOR: OR + NOT.

XOR için "girişler farklıysa 1" tanımı yalnızca 2 giriş için geçerlidir. Genel tanım şudur: girişlerdeki 1'lerin sayısı tekse çıkış 1'dir.

Even parity'de, üretilen eşlik biti dahil 1'lerin sayısı çift olmalıdır. XOR, 1'ler tek olduğunda 1 üretir. Bu bit eklenince toplam 1 sayısı çift olur. Yani XOR bir even parity üretecidir.

### Lojik fonksiyon örneği: çoğunluk fonksiyonu

Tanım: girişlerdeki 1'lerin sayısı 0'lardan fazlaysa çıkış 1'dir. 3 giriş için doğruluk tablosunda 011, 101, 110 ve 111 satırları 1'dir.

$$F = AB + AC + BC$$

Devre: 3 tane 2 girişli AND kapısı ve bunları toplayan bir OR kapısı. Aynı fonksiyon yalnızca NAND kapılarıyla da kurulabilir.

### Karnaugh haritası

Haritada komşu gözler arasında yalnızca bir bit değişir. Bu yüzden sıra 00, 01, 11, 10 şeklindedir. Mümkün olan en büyük 1 gruplarını oluşturup her grubun terimini yazarız.

### Sayı sistemleri ve ikiye tümleyen

Tabloda 0-18 arası sayılar ikilik ve onaltılık olarak verildi. 15 = $0F_{16}$, 16 = $10_{16}$.

4 bitlik ikiye tümleyende en yüksek anlamlı bit (B3) işaret bitidir. 0 pozitif, 1 negatif demektir. 16 kombinasyonun 8'i negatiftir (-1 ... -8). Kalan 8 kombinasyonun biri 0 olduğu için en büyük pozitif sayı +7'dir.

Negatif bir sayının değerini bulmak için ikiye tümleyeni tekrar alınır. Örnek: $1011$ negatiftir. İkiye tümleyeni $0101 = 5$ olduğu için $1011 = -5$.

### Multiplexer

Seçme uçlarına göre girişlerden birini çıkışa aktarır. $n$ veri girişi için $\log_2 n$ seçme ucu gerekir. Örnek: 8 giriş için 3 seçme ucu. Seçme ucu 011 ise $D_3$ çıkışa gider.

2'den 1'e MUX:

$$F = \bar{S}\,W_0 + S\,W_1$$

4'ten 1'e MUX: 4 tane 3 girişli AND kapısı ve bir OR kapısı.

$$F = \bar{S_1}\bar{S_0}W_0 + \bar{S_1}S_0W_1 + S_1\bar{S_0}W_2 + S_1S_0W_3$$

Büyük MUX kurmak:

- 4'ten 1'e MUX: 3 tane 2'den 1'e MUX. Girişteki iki MUX'un seçme ucu $S_0$, çıkıştaki MUX'unki $S_1$'dir.
- 16'dan 1'e MUX: 5 tane 4'ten 1'e MUX. Girişteki dört MUX'a düşük anlamlı $S_1S_0$, çıkıştakine yüksek anlamlı $S_3S_2$ bağlanır.

### Decoder

$n$ girişi $2^n$ çıkışa açar. Kodlanmış bilgiyi çözer. Enable = 0 ise bütün çıkışlar 0'dır. Enable = 1 ise yalnızca girişteki sayıya karşılık gelen çıkış 1 olur.

2'den 4'e decoder doğruluk tablosu (Enable = 1):

| $W_1 W_0$ | Aktif çıkış |
| :---: | :---: |
| 00 | $Y_0$ |
| 01 | $Y_1$ |
| 10 | $Y_2$ |
| 11 | $Y_3$ |

4'ten 16'ya decoder, 5 tane 2'den 4'e decoder ile kurulur. Yüksek anlamlı $W_3W_2$ ilk decoder'a girer. Bu decoder'ın çıkışları diğer dört decoder'ın enable uçlarını sürer. Düşük anlamlı $W_1W_0$ dört decoder'ın hepsine ortak bağlanır. Bir öğrenci hazır 4'ten 16'ya decoder olup olmadığını sordu. Hoca bunun var olduğunu, örneğin alıştırma için verildiğini söyledi.

3'ten 8'e decoder kendisi kurulacaksa: 3 giriş, 1 enable ucu, 8 tane 4 girişli AND kapısı.

### Demultiplexer

MUX'un tersidir. Tek girişi seçme uçlarına göre çıkışlardan birine gönderir. $n$ çıkış için $\log_2 n$ seçme ucu vardır. Pratikte çok kullanılmaz.

### Encoder

$2^n$ girişi $n$ bitle kodlar. Örnek: 4'ten 2'ye encoder. Kural: girişlerden aynı anda yalnızca biri 1 olabilir. Hangi kanaldan 1 geldiyse o kanalın numarası çıkışa yazılır.

Girişlerin yalnızca biri 1 olabildiği için çıkış denklemleri gözle yazılır:

$$Y_0 = W_1 + W_3, \qquad Y_1 = W_2 + W_3$$

Bir öğrenci birden fazla giriş 1 olursa ne olacağını sordu. Hoca bu durumda doğru sonuç garantisi olmadığını, tek girişin 1 olmasını tasarımcının sağlaması gerektiğini söyledi.

### Priority encoder

Girişler arasında öncelik vardır. 4'ten 2'ye priority encoder'da $W_3$ en yüksek, $W_0$ en düşük önceliklidir. Ek bir Z (valid) çıkışı vardır.

| $W_3 W_2 W_1 W_0$ | $Y_1 Y_0$ | $Z$ |
| :---: | :---: | :---: |
| 0000 | XX | 0 |
| 0001 | 00 | 1 |
| 001X | 01 | 1 |
| 01XX | 10 | 1 |
| 1XXX | 11 | 1 |

Yüksek öncelikli bir giriş 1 ise daha düşük öncelikli girişler önemsizdir (X).

Kullanım alanı: CPU'ya gelen kesme isteklerini kodlamak. Hızlı çalışan birimler (örneğin disk) yüksek öncelik alır. Yavaş birimler (klavye, fare) düşük öncelik alır. Aynı anda birden fazla istek gelirse en yüksek öncelikli birime hizmet verilir.

Hoca ödev olarak bu tablonun Karnaugh haritasıyla sadeleştirilmesini istedi. Haritada tablodaki X'ler girişte değil çıkışta don't care olarak düşünülür. Haritada 16 girişin hepsi yer alır. Bir öğrenci 0101 ile 0110'un aynı önceliğe sahip olup olmadığını sordu. İkisinde de en yüksek öncelikli aktif giriş $W_2$ olduğu için çıkış 10'dur.

### Soru 1: Decoder ve 8x2 AND-OR ile 8'den 1'e MUX

8x2 AND-OR: 8 tane 2 girişli AND kapısı ve çıkışlarını toplayan bir OR kapısı.

- Seçme uçları $S_2S_1S_0$, 3'ten 8'e decoder'ın girişlerine ağırlık sırasıyla bağlanır.
- Decoder'ın her $Y_i$ çıkışı, $W_i$ ile bir AND kapısına girer.
- AND çıkışları OR kapısında toplanır. OR çıkışı $F$'dir.

Tek decoder yeterlidir.

### Soru 2: Decoder ve OR kapılarıyla üç fonksiyon

$$F_1 = \overline{X + Z} + XYZ, \quad F_2 = \overline{X + Z} + \bar{X}YZ, \quad F_3 = X\bar{Y}Z + \overline{X + Z}$$

$\overline{X + Z} = \bar{X}\bar{Z}$ olduğu için bu terim 0 ve 2 numaralı mintermleri verir.

- $F_1 = \sum m(0, 2, 7)$
- $F_2 = \sum m(0, 2, 3)$
- $F_3 = \sum m(0, 2, 5)$

Çözüm: XYZ'yi ağırlık sırasıyla (X en yüksek anlamlı) 3'ten 8'e decoder'a bağlarız. Her fonksiyon için ilgili decoder çıkışlarını bir OR kapısında toplarız. Toplam 3 OR kapısı gerekir.

### Soru 3: 8'den 1'e MUX ve bir inverter

$$F(A, B, C, D) = \sum m(2, 4, 6, 9, 10, 11, 15)$$

$A, B, C$ seçme uçlarına bağlanır ($A$ en yüksek anlamlı). $D$ veri girişlerinde kullanılır. Doğruluk tablosunu ABC'ye göre ikişer satırlık gruplara ayırıp her grupta $F$ ile $D$ arasındaki ilişkiye bakarız:

| ABC | MUX girişi |
| :---: | :---: |
| 000 | 0 |
| 001 | $\bar{D}$ |
| 010 | $\bar{D}$ |
| 011 | $\bar{D}$ |
| 100 | $D$ |
| 101 | 1 |
| 110 | 0 |
| 111 | $D$ |

$\bar{D}$ için tek inverter yeterlidir.

### Soru 4: 4'ten 1'e MUX ve harici kapılar

$$F(A, B, C, D) = \sum m(1, 3, 4, 11, 12, 13, 14, 15)$$

$A$ ve $B$ seçme uçlarına bağlanır. Veri girişleri $C$ ve $D$'nin fonksiyonudur.

| AB | MUX girişi |
| :---: | :---: |
| 00 | $D$ |
| 01 | $\bar{C}\bar{D} = \overline{C + D}$ (NOR) |
| 10 | $CD$ (AND) |
| 11 | 1 |

Derste 01 durumu için önce NAND dendi. Bir öğrencinin uyarısıyla doğrusunun NOR olduğu belirtildi.

### Ders sonrası notlar

- Derste "18 sayısının onaltılık karşılığı 1F" dendi. Doğrusu $18 = 16 + 2 = 12_{16}$. $1F_{16}$ = 31'dir.
- İkiye tümleyen örneğinde ara adım olarak "1010" söylendi. Doğru adım: $1011$'in bitleri ters çevrilir ($0100$), sonra 1 eklenir ($0101 = 5$). Sonuç $-5$'tir.
- Hoca HDL dillerini "gömülü sistem yazılımında kullanılan diller" diye andı. HDL (Hardware Description Language) donanım tanımlama dilidir. Verilog ve VHDL ile FPGA ve ASIC gibi donanımlar tasarlanır.
- Kesme örneğinde bir yerde "D3 en düşük önceliğe sahip" dendi. Hoca hemen düzeltti: D3 en yüksek, D0 en düşük önceliklidir.
- Bir öğrencinin sorusuna cevap verirken "W3 1 olduğunda W1 ve W0 ne olursa olsun, W2'ye hizmet verilir" dendi. Doğrusu: $W_3 = 0$ ve $W_2 = 1$ olduğunda $W_1$ ve $W_0$ önemsizdir ve $W_2$'ye hizmet verilir.
- "$Y_0 = W_1 + W_3$" denklemi yalnızca sıradan encoder için geçerlidir. Priority encoder için sadeleştirilmiş denklemler şunlardır:
  - $Y_1 = W_3 + W_2$
  - $Y_0 = W_3 + \bar{W_2}W_1$
  - $Z = W_3 + W_2 + W_1 + W_0$
- Soru 2, 3 ve 4'ün minterm ve MUX giriş tabloları Python ile kontrol edildi; derste bulunan sonuçlarla aynı.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
