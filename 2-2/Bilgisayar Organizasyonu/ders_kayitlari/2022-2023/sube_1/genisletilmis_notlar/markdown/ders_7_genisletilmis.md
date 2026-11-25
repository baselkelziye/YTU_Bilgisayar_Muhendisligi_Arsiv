# Ders 7 Genişletilmiş Notu: Tek Çevrimli Bilgisayar: Yazmaç Dosyası, ALU ve Shifter Tasarımı, Kontrol Kelimesi, Komut Kümesi ve Komut Çözücü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Tek çevrimli CPU'nun genel yapısı ve yazmaç dosyası
- 2. Fonksiyon birimine giden yollar ve bellek bağlantısı
- 3. Durum bayraklarının üretimi
- 4. Fonksiyon birimi içindeki seçim ve geri yazma yolu
- 5. ALU'nun blok yapısı ve genel tasarım yöntemi
- 6. Aritmetik birimin fonksiyon tablosundan tasarlanması
- 7. Lojik birim ve ALU'nun birleştirilmesi
- 8. Shifter ve döndürücü
- 9. Fonksiyon birimi tablosu ve 16 bitlik kontrol kelimesi
- 10. Mikro işlemlerin kontrol kelimesine çevrilmesi
- 11. Kontrol kelimesinden komut kümesine
- 12. Basit bilgisayarın komutları
- 13. Bellekteki komutların çözülmesi
- 14. Tam blok diyagram: PC, bellekler ve dallanma denetimi
- 15. Komut çözücü
- 16. Tek çevrimde gecikme yolu
- Örnek Sorular

Bu derste önceki haftalarda kurulan veri yolu (datapath) yapısı bir adım derinleştirilerek tek çevrimli (single cycle, hardwired) bir CPU'nun nasıl tasarlanacağı işlenir. Önce yazmaç dosyası ve fonksiyon birimi tanıtılır, bayrakların nasıl üretildiği gösterilir. Ardından aritmetik birim, lojik birim ve shifter tek tek tasarlanır. Aradan sonra bu blokların seçme uçları bir kontrol kelimesinde toplanır, mikro işlemler kontrol kelimesine çevrilir. Son bölümde kontrol kelimesiyle komut kümesi arasındaki ilişki kurulur, PC, komut belleği, veri belleği, dallanma denetimi ve komut çözücü eklenerek basit bilgisayar tamamlanır. Anlatım, kitabın (Mano ve Kime, *Logic and Computer Design Fundamentals*, 4. baskı) 9. bölüm şekil ve tabloları üzerinden, arada çizim tahtasında el çizimiyle yürür.

## 1. Tek çevrimli CPU'nun genel yapısı ve yazmaç dosyası

Slayttaki şema (ekrandan, 00:05:00) basit bir tek çevrimli CPU'nun çekirdeğini gösterir. Üst kısım geçen hafta kurulan, yazmaçlar arasında veri aktaran yapıdır. Buna aritmetik-lojik birim ve shifter eklenerek CPU'nun çekirdeği oluşturulur. Şekilde görünmeyen ama gereken başka birimler de vardır: bellek bağlantısı (bellek yönetimi), komut çözücü (instruction decoder) ve dallanmaları, yani program sayıcıyla ilgili değerleri yöneten bir birim. Önce çekirdek incelenir.

Şemada mavi kutularla gösterilen R0, R1, R2, R3 yazmaçları senkron ardışıl elemanlardır; işlevlerini saat işaretinin yükselen kenarında gerçekleştirirler. Hoca, derste mavi çizgiyle işaretlenmiş bütün yapıların bu mantıkla düşünülmesi gerektiğini söyledi. Geri kalan yapılar kombinasyonel devredir: girişlerindeki işaret değiştiği anda çıkış üretirler.

### 1.1 Yazmaç dosyası (register file)

Geçen hafta görülen veri yolu yapısına CPU tasarımında **yazmaç dosyası** (register file) adı verilir. Girdi ve çıktıları şöyledir:

- **A select ve B select:** ikişer bitlik kontrol uçlarıdır. Her biri bir 4'e 1 MUX'un seçme uçlarını sürer. MUX'ların girişlerine $n$ bitlik R0-R3 yazmaçlarının çıkışları gelir. Böylece A select ile R0-R3 arasından herhangi biri **A data** kanalına, B select ile herhangi biri **B data** kanalına çıkarılır. İki kanala aynı yazmaç da çıkabilir.
- **Destination select (D address):** 2 bitlik bir kontrol ucudur ve bir 2'ye 4 dekodere bağlıdır. Verilen değere göre dekoderin dört çıkışından yalnız biri aktif olur. Her dekoder çıkışı bir AND kapısına girer; AND'in diğer girişinde **Load enable / Write** işareti vardır. Write 0 ise hiçbir yazmaç için yükleme işareti üretilmez. Write 1 ise yalnız adresi verilen yazmaç (R0 için 00, R1 için 01, R2 için 10, R3 için 11) yüklenir.
- **D data:** yüklenecek $n$ bitlik değerdir ve bütün yazmaçların veri girişlerine bağlıdır.

Örneğin R2'ye yazılacaksa D data hattına değer, D address'e 10 ve Write'a 1 verilir; yazma saatin yükselen kenarında olur. Kenar gelmeden önce R2'nin eski değeri MUX'lar üzerinden bir sonraki kata zaten aktarılmıştır. Bu yapı, komut kümesindeki iki operandlı komutlar için iki yazmaç operandını aynı anda hazırlar ve seçilen yazmaca yükleme imkânı verir.

## 2. Fonksiyon birimine giden yollar ve bellek bağlantısı

A data kanalındaki değer fonksiyon biriminin içindeki aritmetik-lojik birimin (ALU) A girişine ulaşır. Aynı kanal (Bus A) **Address out** hattına da gider; yani bellek için adres değeri de A kanalından üretilebilir.

ALU'nun B girişine ise bir MUX (**MUX B**) üzerinden değer gelir. MUX B'nin bir girişi yazmaç dosyasının B data kanalı, diğeri dışarıdan verilen sabit değerdir (**Constant in**). Sabit değer komutun içine gömülüdür; hoca bunu 8086'daki `MOV AL, 1` gibi bir komutla örnekledi: 1 değeri makine kodunun içindedir. Komut çözücü komutu aldığında bu sabiti ayıklayıp MUX B'ye verir. Böylece ALU'da ya iki yazmaç ya da bir yazmaç ile bir sabit işleme sokulabilir.

MUX B'nin çıkışı (Bus B) aynı zamanda belleğin **Data out** hattına gider. Bu, bir sabiti ya da bir yazmacın değerini belleğe yazma imkânı verir. Hoca örnek olarak `MOV [R1], 10` komutunu verdi: R1 yazmaç dosyasında seçilip A kanalından adres olarak, 10 sabiti MUX B'den veri olarak belleğe ulaşır.

Fonksiyon biriminin içinde ALU'nun yanında bir **Shifter** vardır. ALU iki girişli çalışır (iki kanalı toplar), shifter ise tek bir değeri öteler ya da döndürür. Bu tasarımda shifter'ın girişi B kanalıdır; yani yazmaç dosyasının B adresindeki yazmaç ya da komuttaki sabit shifter'a gider.

ALU'nun 4 seçme ucu olduğundan 16 farklı işlem yapılabilir: toplama, çıkarma, artırma (increment), azaltma (decrement), negatif alma, sıfırlama gibi. Shifter'da ise sağa/sola öteleme ve döndürme gibi 4 işlem olabilir; sağa ve sola ötelemede boşalan bitlere verilen seri girişler bu şemada 0'a bağlıdır.

## 3. Durum bayraklarının üretimi

Bir CPU'da bazı kararların (örneğin koşullu dallanma) verilebilmesi için durum değişkenleri, yani bayraklar tutulmalıdır. Bayraklar temel olarak ALU tarafından üretilir. Hoca ALU'yu henüz bir kara kutu gibi düşünerek, çıkışına göre bayrakların hangi lojikle üretileceğini sordu.

### 3.1 Sıfır bayrağı (Z)

Çıkış 0 ise $Z = 1$, değilse $Z = 0$ olmalıdır. Çıkışın sıfır olması bütün bitlerin 0 olması demektir.

**Soru:** Sıfır bayrağını üreten lojik nedir? **Cevap:** Bir öğrenci önce bütün bitleri OR'lamayı önerdi. Hoca, bütün bitler 0 iken OR'un 0 vereceğini, oysa 1 çıkması gerektiğini gösterdi. Doğru cevap **NOR**'dur: $R_0, R_1, \ldots, R_{n-1}$ bitlerinin hepsi bir NOR kapısına girer (ekrandan, 00:20:00).

$$Z = \overline{R_0 + R_1 + \cdots + R_{n-1}}$$

### 3.2 İşaret/negatif bayrağı (N ya da SF)

Yazmaç 0'dan küçükse $N = 1$, değilse 0 olmalıdır.

**Soru:** Bu nasıl sağlanır? **Cevap:** Bir öğrenci ilk bite bakılabileceğini söyledi. Sayısal sistemlerde ikiye tümleyen işaretli gösterim kullanıldığından, sayının negatif olup olmadığını anlamanın en kolay yolu en yüksek anlamlı bitine bakmaktır. Bu yüzden N bayrağına doğrudan ilgili yazmacın en yüksek anlamlı biti (8 bitlik örnekte $R_7$) atanır.

### 3.3 Elde bayrağı (C)

Elde bayrağı işaretsiz toplamadaki taşmayı gösterir. ALU içinde $n$ bitlik bir tam toplayıcı olduğu düşünülürse, bu toplayıcının elde çıkışı ($C_{out}$) doğrudan elde bayrağı olarak alınır.

### 3.4 Taşma bayrağı (V ya da OF)

Taşma bayrağı işaretli işlemde taşmayı gösterir: iki negatif sayı toplanıp sonuç pozitif çıkarsa ya da iki pozitif sayı toplanıp sonuç negatif çıkarsa taşma vardır. Tam toplayıcı bit bit ayrıldığında, $n-1$ numaralı (en yüksek anlamlı) tam toplayıcıya giren elde ile ondan çıkan elde farklıysa taşma oluşur. 8 bitlik örnekte:

$$V = C_7 \oplus C_6$$

> **Ek bilgi (derste anlatılmadı):** Genel olarak $n$ bitlik toplayıcıda $V = C_n \oplus C_{n-1}$ yazılır; burada $C_n$ en yüksek anlamlı bitten çıkan, $C_{n-1}$ ona giren eldedir. Hocanın "carry 7 ile carry 6" ifadesi bu genel kuralın 8 bitlik hâlidir.

## 4. Fonksiyon birimi içindeki seçim ve geri yazma yolu

ALU ve shifter kombinasyonel devrelerdir; A ve B kanalları hazırlandığında ikisi de hemen sonuç üretir (ALU'nun çıkışı G, shifter'ın çıkışı H). Örneğin toplama yapılırken shifter da bir şey üretir, ama bu değer dikkate alınmamalıdır; bir öteleme komutunda da ALU'nun ürettiği değerler önemsizdir. Bunun için fonksiyon biriminin içinde 1 bit seçme uçlu bir **MUX F** vardır: seçme ucu 1 ise shifter'ın çıkışı, 0 ise ALU'nun çıkışı fonksiyon biriminin F çıkışına aktarılır.

Bellekten okuma için de bir yol gerekir. Adres A kanalından üretilir; belleğe okuma komutu verildiğinde gelen veri (**Data in**) yazmaç dosyasına yazılmak istenebilir. Bunun için **MUX D** kullanılır: MD seçme ucu 0 ise fonksiyon biriminin çıkışı, 1 ise bellekten gelen değer D data hattına (Bus D) verilir.

Sonuç olarak bir yazmaca yazılabilecek değerler şunlardır: bir ya da iki yazmacın ALU'da ya da shifter'da işlenmiş sonucu, bir yazmaçla bir sabitin işlenmiş sonucu ya da bellekten okunan değer.

## 5. ALU'nun blok yapısı ve genel tasarım yöntemi

ALU'nun blok yapısında (ekrandan, 00:30:00) $n$ bitlik **Data input A** ($A_0 \ldots A_{n-1}$), $n$ bitlik **Data input B** ($B_0 \ldots B_{n-1}$), **Carry input** ($C_{in}$), işlem seçme uçları (**Operation select**, $S_0$, $S_1$) ve mod seçme ucu (**Mode select**, $S_2$) vardır. Çıkışlar $n$ bitlik **Data output G** ($G_0 \ldots G_{n-1}$) ve **Carry output** ($C_{out}$) ucudur. $C_{out}$ bir bayrak çıkışı olarak düşünülebilir.

Toplam 4 kontrol ucu (seçme uçları ve $C_{in}$) 16 farklı fonksiyon demektir. Hoca, akıllı bir tasarımla kontrol uçlarından birinin doğrudan toplayıcının elde girişine, bir başkasının da aritmetik ve lojik birim çıkışları arasında seçim yapan MUX'a indirgenebileceğini söyledi.

En genel senaryoda aritmetik birim şöyle kurulur: bir $n$ bitlik toplayıcının $X$ ve $Y$ girişlerinin önüne birer **giriş lojiği** konur, aynı şey $C_{in}$ için de yapılır.

- $X_i = f(A_i, S_2, S_1, S_0)$
- $Y_i = g(B_i, S_2, S_1, S_0)$
- $C_{in} = h(A_i, B_i, S_2, S_1, S_0)$

Tasarım özelleştirilebilirse bu fonksiyonlar basitleşir. Örneğin 16 fonksiyon, $C_{in}$'in 0 ve 1 olduğu durumlarda aynı bağlantıyla 8'er 8'er karşılanabiliyorsa $C_{in}$ lojiği doğrudan bir tampona (buffer) dönüşür. Bütün aktarımlar A kanalı, işlemler B kanalı üzerinden yapılabiliyorsa A giriş lojiği de bir tampon olur.

## 6. Aritmetik birimin fonksiyon tablosundan tasarlanması

Hoca, kitaptaki indirgenmiş tasarım yerine daha genel bir durumdan başlayarak aritmetik birimi çizim tahtasında kurdu (ekrandan, 00:45:00).

### 6.1 İstenen fonksiyon tablosu

Üç seçme ucu $S_2, S_1, S_0$ olsun. Aritmetik birimin F çıkışında şu işlemler istenir:

| $S_2 S_1 S_0$ | Fonksiyon |
|---|---|
| 000 | $F \leftarrow A$ (transfer) |
| 001 | $F \leftarrow A + 1$ (artırma) |
| 010 | $F \leftarrow A + B$ |
| 011 | $F \leftarrow A + B + 1$ |
| 100 | $F \leftarrow A + \overline{B}$ |
| 101 | $F \leftarrow A + \overline{B} + 1$ ($A - B$) |
| 110 | $F \leftarrow A - 1$ (azaltma) |
| 111 | $F \leftarrow A$ (transfer) |

Amaç, her satır için $n$ bitlik toplayıcının $X_i$, $Y_i$ ve $C_{in}$ girişlerine ne verileceğini bulmaktır. Hoca, mümkünse en düşük kontrol bitinin 0 ve 1 olduğu satır çiftlerini aynı bağlantıyla karşılamaya çalışmayı önerdi; böylece $C_{in}$ lojiği basit bir tampon olur.

### 6.2 Satır satır bağlantılar

Tam toplayıcı $X + Y + C_{in}$ toplamını üretir.

- **$F = A$:** $X$'in her bitine $A$'nın ilgili biti verilir. Sonucun $A$ kalması için $Y$'nin bütün bitlerine 0, $C_{in}$'e 0 verilir: $A + 0 + 0 = A$.
- **$F = A + 1$:** Aynı bağlantıda $C_{in} = 1$: $A + 0 + 1$.
- **$F = A + B$:** $X = A$, $Y = B$, $C_{in} = 0$.
- **$F = A + B + 1$:** $X = A$, $Y = B$, $C_{in} = 1$.
- **$F = A + \overline{B}$:** $X = A$, $Y$'ye $B$'nin her bitinin değili, $C_{in} = 0$.
- **$F = A + \overline{B} + 1$:** Aynı bağlantıda $C_{in} = 1$. Bu, ikiye tümleyenle $A - B$ demektir.
- **$F = A - 1$:**

**Soru:** $A - 1$'i nasıl elde ederiz? **Cevap:** Bir öğrenci $Y$'ye bütün bitleri 1 olan bir değer girilebileceğini söyledi. Hoca bunu "$A + (-1) + 0$" olarak onayladı: $X = A$, $Y$ = 1'ler, $C_{in} = 0$.

- **$F = A$ (son satır):** Aynı bağlantıda $C_{in} = 1$ verilirse $A + (-1) + 1 = A$ olur; $-1$ ile $+1$ birbirini götürür.

Tahtadaki tamamlanmış tablo (ekrandan, 00:45:00):

```text
S2 S1 S0 | Fonksiyon        | Xi | Yi      | Cin
0  0  0  | F <- A           | Ai | 0'lar   | 0
0  0  1  | F <- A + 1       | Ai | 0'lar   | 1
0  1  0  | F <- A + B       | Ai | Bi      | 0
0  1  1  | F <- A + B + 1   | Ai | Bi      | 1
1  0  0  | A + B'           | Ai | Bi'     | 0
1  0  1  | A + B' + 1 (A-B) | Ai | Bi'     | 1
1  1  0  | A - 1            | Ai | 1'ler   | 0
1  1  1  | A                | Ai | 1'ler   | 1
```

### 6.3 Giriş lojiklerinin bulunması

**Soru:** $C_{in}$'in $A_i, B_i, S_2, S_1, S_0$ cinsinden karşılığı nedir? **Cevap:** Bir öğrenci "$S_0$" dedi. Tabloda $S_0$ ne ise $C_{in}$ de odur: $C_{in} = S_0$.

**Soru:** $X_i$'nin karşılığı nedir? **Cevap:** $X_i = A_i$; diğer değişkenlere hiç bakılmaz.

Hoca, bu tasarımda böyle bir indirgeme çıktığını ama her zaman böyle olmayabileceğini vurguladı. Genel mantık $f$, $g$ ve $h$ fonksiyonlarını bulmaktır; karmaşık durumlarda örneğin $g$'nin içine $A$'yı da katmak gerekebilir.

$Y_i$ daha karışıktır. Hoca bunu dört değişkenli bir Karnaugh diyagramıyla buldu: satırlar $S_0 B_i$, sütunlar $S_2 S_1$ (her ikisi 00, 01, 11, 10 sırasıyla) (ekrandan, 00:50:00).

- $S_2 S_1 = 00$: $Y_i = 0$ ($B_i$'den ve $S_0$'dan bağımsız).
- $S_2 S_1 = 01$: $Y_i = B_i$.
- $S_2 S_1 = 11$: $Y_i = 1$.
- $S_2 S_1 = 10$: $Y_i = \overline{B_i}$.

Diyagramda iki dörtlü grup alınır. $S_0$ her iki grupta da düşer. Sonuç:

$$Y_i = S_1 B_i + S_2 \overline{B_i}$$

Doğrulama: $S_2 S_1 = 00$ için 0; $01$ için $B_i$; $10$ için $\overline{B_i}$; $11$ için $B_i + \overline{B_i} = 1$. Bu sonuç ders sonrasında python ile dört durum için denetlendi.

### 6.4 Bir bit diliminin devresi

Hoca tam toplayıcının $i$'inci bit dilimini (bit slice) çizdi. $X_i$'ye doğrudan $A_i$, $C_{in}$'e doğrudan $S_0$ bağlanır. $Y_i$ giriş lojiğinde $B_i$ ile $S_1$ bir AND kapısına, $B_i$'nin değili (bir NOT kapısı) ile $S_2$ ikinci bir AND kapısına girer; iki AND'in çıkışı bir OR kapısında birleşir. Bu dilimden $n$ tane vardır.

Kitaptaki çizimde aynı devre farklı adlarla verilir: hocanın $S_2$ dediği uç orada $S_1$, $S_1$ dediği $S_0$, $S_0$ dediği ise $C_{in}$'dir; ortaya çıkan mantık aynıdır. Kitabın tablosu (ekrandan, 00:35:00) şöyledir:

| $S_1$ | $S_0$ | $Y$ | $C_{in} = 0$ | $C_{in} = 1$ |
|---|---|---|---|---|
| 0 | 0 | 0'lar | $G = A$ (transfer) | $G = A + 1$ (artırma) |
| 0 | 1 | $B$ | $G = A + B$ (toplama) | $G = A + B + 1$ |
| 1 | 0 | $\overline{B}$ | $G = A + \overline{B}$ | $G = A + \overline{B} + 1$ (çıkarma) |
| 1 | 1 | 1'ler | $G = A - 1$ (azaltma) | $G = A$ (transfer) |

### 6.5 $C_{in}$ nereye bağlanır?

> **Hocanın vurgusu:** Bit dilimini çizmek ile bütün bitleri göstererek çizmek arasındaki fark çok önemli bir nüanstır. $S_0$ adı verilen kontrol ucu $n$ bitlik toplayıcının elde girişine, bit dilimi olarak çizildiğinde ise yalnız **en düşük anlamlı** tam toplayıcının elde girişine bağlanır. Diğer basamaklara bir önceki basamağın eldesi girer.

Bu noktadan sonra, verilen herhangi bir aritmetik birim fonksiyon tablosuna bakarak tasarımı tam toplayıcılarla ya da $n$ bitlik bir toplayıcıyla gerçekleştirebilmek beklenir.

## 7. Lojik birim ve ALU'nun birleştirilmesi

### 7.1 Lojik birim

Lojik birimin dört işlem yaptığı düşünülsün: bitwise AND, OR, XOR ve NOT. Bunlar her bit dilimi için bir 4'e 1 MUX ile gerçekleştirilir (ekrandan, 01:15:00). $A_i$ ve $B_i$ AND, OR ve XOR kapılarına girer, $A_i$ ayrıca bir NOT kapısına girer; dört kapının çıkışı MUX'un 0-3 girişlerine bağlanır, MUX çıkışı $G_i$ olur. $n$ bitlik lojik birim için $n$ tane MUX gerekir.

| $S_1$ | $S_0$ | Çıkış | İşlem |
|---|---|---|---|
| 0 | 0 | $G = A \wedge B$ | AND |
| 0 | 1 | $G = A \vee B$ | OR |
| 1 | 0 | $G = A \oplus B$ | XOR |
| 1 | 1 | $G = \overline{A}$ | NOT |

### 7.2 ALU'nun birleştirilmesi

Aritmetik birim üç, lojik birim iki kontrol ucuna ihtiyaç duyar; lojik birimin iki ucu aritmetik birimin uçlarıyla paylaşılır. İki birim de kombinasyonel olduğundan ikisi de her zaman çıkış üretir. İstenen sonucu seçmek için bir 2'ye 1 MUX ve bir seçme ucu daha ($S_3$ ya da mod seçme ucu) gerekir: 0 verilirse aritmetik birimin, 1 verilirse lojik birimin çıkışı ALU çıkışı olur. ALU'nun fonksiyon tablosunda böylece aritmetik işlemler (A transferi, artırma, toplama, eldeli toplama, $A + \overline{B}$, çıkarma, azaltma, yine A transferi) ve lojik işlemler (AND, OR, XOR, birinci tümleyen) bulunur. A transferi iki ayrı kontrol koduyla elde edilir.

## 8. Shifter ve döndürücü

### 8.1 Shifter'ın fonksiyon tablosunu çıkarmak

Hoca, verilen bir shifter devresinin fonksiyon tablosunu çıkarmayı bir alt problem olarak ele aldı (ekrandan, 01:20:00). Devrede dört bit için birer MUX vardır; seçme ucu S iki bittir. Her MUX'un 0 girişine kendi biti, 1 girişine solundaki bit (en soldakine $I_R$), 2 girişine sağındaki bit (en sağdakine $I_L$) bağlıdır. Ayrıca B3 "Serial output L", B0 "Serial output R" olarak dışarı verilir.

- **S = 00:** $H_3 = B_3$, $H_2 = B_2$, $H_1 = B_1$, $H_0 = B_0$. B kanalındaki değer aynen aktarılır: **transfer B**.
- **S = 01:** $H_3 = I_R$, $H_2 = B_3$, $H_1 = B_2$, $H_0 = B_1$: **sağa öteleme** (sr B).
- **S = 10:** $H_3 = B_2$, $H_2 = B_1$, $H_1 = B_0$, $H_0 = I_L$: **sola öteleme** (sl B).

Buradan önemli bir sonuç çıkar: bu tasarımda A kanalındaki değeri fonksiyon biriminin çıkışına aktarmak için ALU, B kanalındaki değeri aktarmak için shifter kullanılır.

### 8.2 Döndürücü (barrel shifter) tasarımı

Sonraki örnekte tersten gidilir: bir fonksiyon tablosu verilir ve devre tasarlanır (ekrandan, 01:25:00). Tablo şöyledir:

| $S_1$ | $S_0$ | $Y_3$ | $Y_2$ | $Y_1$ | $Y_0$ | İşlem |
|---|---|---|---|---|---|---|
| 0 | 0 | $D_3$ | $D_2$ | $D_1$ | $D_0$ | Döndürme yok |
| 0 | 1 | $D_2$ | $D_1$ | $D_0$ | $D_3$ | Bir basamak döndürme |
| 1 | 0 | $D_1$ | $D_0$ | $D_3$ | $D_2$ | İki basamak döndürme |
| 1 | 1 | $D_0$ | $D_3$ | $D_2$ | $D_1$ | Üç basamak döndürme |

Döndürme yönü soladır. Her çıkış biti için bir 4'e 1 MUX kullanılır; bütün MUX'ların seçme uçları ortak 2 bitlik S hattına bağlanır. Her MUX'un 0 girişine kendi biti, 1 girişine bir basamak, 2 girişine iki basamak, 3 girişine üç basamak döndürülmüş bit gelir. Örneğin $D_0$ bir basamak döndürmede $Y_1$'in 1 girişine, iki basamakta $Y_2$'nin 2 girişine gider. Hoca çizimin dağınık olduğunu ama adım adım gösterilmesinin önemli olduğunu söyledi; düzgün çizimde bağlantılar bir "merdiven" yapısı oluşturur.

### 8.3 Kombinasyonel ve ardışıl öteleme

Bu shifter ve döndürücüler kombinasyonel devredir; uçlarındaki değer değişir değişmez sonuç üretirler. Ardışıl devre konusunda görülen ötelemeli yazmaçlar ise saat işaretinin yükselen kenarında işlev gösterir.

## 9. Fonksiyon birimi tablosu ve 16 bitlik kontrol kelimesi

### 9.1 Ulaşılan blok diyagram

Böylece iki hafta önce görülen yazmaç dosyası ile fonksiyon biriminin içini dolduran ALU (aritmetik + lojik birim) ve shifter bir araya gelmiş olur. Genel hâliyle (ekrandan, 01:30:00) yazmaç dosyası $2^m \times n$ kapasitelidir: A address, B address ve D address $m$ bittir, A data, B data ve D data $n$ bittir. Write işareti, dekoder çıkışlarıyla AND'lenerek her yazmacın yükleme işaretini üretir. Fonksiyon birimi 4 bitlik FS ile kontrol edilir ve V, C, N, Z bayraklarını üretir.

Bütün seçme uçları (A adresi, B adresi, D adresi, Write, MB select, function select, MD select) birer kontrol işaretidir. Komutlar bu kontrol işaretlerinin geniş bir dizisi olarak değil, paketlenmiş (sıkıştırılmış) bit dizileri olarak yazılır. Komut çözücü bu dizileri açar ve kontrol işaretlerini üretir. Önce fonksiyon biriminin tam tablosu çıkarılır.

### 9.2 G select, H select ve MF select kodları

Fonksiyon biriminin 4 kontrol ucu (FS) vardır. Bunlardan MF select (çıkışın ALU'dan mı shifter'dan mı geleceği), ALU'nun seçme uçları (G select) ve shifter'ın seçme uçları (H select) türetilir. Tablo (ekrandan, 01:35:00):

| FS(3:0) | MF | G select(3:0) | H select | Mikro işlem |
|---|---|---|---|---|
| 0000 | 0 | 0000 | XX | $F = A$ |
| 0001 | 0 | 0001 | XX | $F = A + 1$ |
| 0010 | 0 | 0010 | XX | $F = A + B$ |
| 0011 | 0 | 0011 | XX | $F = A + B + 1$ |
| 0100 | 0 | 0100 | XX | $F = A + \overline{B}$ |
| 0101 | 0 | 0101 | XX | $F = A + \overline{B} + 1$ |
| 0110 | 0 | 0110 | XX | $F = A - 1$ |
| 0111 | 0 | 0111 | XX | $F = A$ |
| 1000 | 0 | 1X00 | XX | $F = A \wedge B$ |
| 1001 | 0 | 1X01 | XX | $F = A \vee B$ |
| 1010 | 0 | 1X10 | XX | $F = A \oplus B$ |
| 1011 | 0 | 1X11 | XX | $F = \overline{A}$ |
| 1100 | 1 | XXXX | 00 | $F = B$ |
| 1101 | 1 | XXXX | 01 | $F = \text{sr}\ B$ |
| 1110 | 1 | XXXX | 10 | $F = \text{sl}\ B$ |

Hoca, slayttaki H select sütun başlığında 4 bit yazdığını ama shifter için iki bit olması gerektiğini, bunun yazım hatası olduğunu belirtti. Toplam 16 durum 4 bitlik FS ile üretilir. Bu tablo, ileride komut çözücüde FS ile içerideki karşılıklar kurulurken önemlidir.

### 9.3 Kontrol kelimesinin alanları

Bu sistemi çalıştırmak için verilmesi gereken girdiler bir kontrol kelimesinde toplanır. 8 yazmaçlı ($8 \times n$) bir yazmaç dosyası için (ekrandan, 02:10:00):

```text
Bit:   15 14 13 | 12 11 10 | 9 8 7 | 6  | 5 4 3 2 | 1  | 0
Alan:     DA    |    AA    |  BA   | MB |   FS    | MD | RW
```

- **DA, AA, BA:** 3'er bit. Sekiz yazmacı seçmek için 3 bit yeter. Yazmaç numarası ikilik olarak yazılır (R0 için 000, R7 için 111).
- **MB:** 1 bit. İşlem sabit değer içeriyorsa 1, B kanalından bir yazmaç kullanılıyorsa 0.
- **FS:** 4 bit, değerleri yukarıdaki tablodan.
- **MD:** 1 bit. Bellekten okunan değer yazılacaksa 1, fonksiyon biriminden değer aktarılacaksa 0.
- **RW (register write):** 1 bit. Sonuç yazmaç dosyasına saklanacaksa 1, saklanmayacaksa 0.

Toplam $3 + 3 + 3 + 1 + 4 + 1 + 1 = 16$ bittir. Bazı işlemlerde bazı bitler don't care olabilir, ama tablodaki bütün fonksiyonları yürütmek için 16 bitin her biri bir işlemde mutlaka değer alır.

## 10. Mikro işlemlerin kontrol kelimesine çevrilmesi

Bu bir veri yolu olduğuna göre yazmaç transfer diliyle bazı mikro işlemler tanımlanıp kontrol kelimesinin bitleri belirlenebilir. Kitaptaki sembolik ve ikilik tablolar (ekrandan, 01:40:00 ve 01:50:00):

| Mikro işlem | DA | AA | BA | MB | FS | MD | RW |
|---|---|---|---|---|---|---|---|
| $R1 \leftarrow R2 - R3$ | 001 | 010 | 011 | 0 | 0101 | 0 | 1 |
| $R4 \leftarrow \text{sl}\ R6$ | 100 | XXX | 110 | 0 | 1110 | 0 | 1 |
| $R7 \leftarrow R7 + 1$ | 111 | 111 | XXX | X | 0001 | 0 | 1 |
| $R1 \leftarrow R0 + 2$ | 001 | 000 | XXX | 1 | 0010 | 0 | 1 |
| Data out $\leftarrow R3$ | XXX | XXX | 011 | 0 | XXXX | X | 0 |
| $R4 \leftarrow$ Data in | 100 | XXX | XXX | X | XXXX | 1 | 1 |
| $R5 \leftarrow 0$ | 101 | 000 | 000 | 0 | 1010 | 0 | 1 |

Hoca her satırı donanım kısıtlarına bakarak açıkladı:

- **$R1 \leftarrow R2 - R3$:** Fonksiyon birimi yalnız $A - B$ yapabilir, $B - A$ yapamaz. Bu yüzden çıkarılan R3 B kanalından, R2 A kanalından gelmelidir. DA = 001 (R1), AA = 010 (R2), BA = 011 (R3). MB = 0, çünkü B girişine sabit değil yazmaç gider. İşlem $A + \overline{B} + 1$, yani FS = 0101 (5). Sonuç fonksiyon biriminden gelir, MD = 0; yazılacağı için RW = 1.
- **$R4 \leftarrow \text{sl}\ R6$:** Sola öteleme yalnız B kanalında tanımlıdır; R6 B kanalından çıkmalıdır (BA = 110). Shifter'a A girişi gelmediği için AA don't care'dir. DA = 100, MB = 0, FS = 1110. Hoca önce MD'nin 1 olması gerektiğini söyledi, hemen düzeltti: fonksiyon biriminin sonucu aktarılacağı için MD = 0. RW = 1.
- **$R7 \leftarrow R7 + 1$:** Artırma yalnız A kanalında yürür; AA = 111. B kanalından ne geldiği önemsiz olduğundan BA ve MB don't care'dir. FS = 0001, MD = 0, RW = 1.
- **$R1 \leftarrow R0 + 2$:** Toplama FS = 0010. Sabit yalnız fonksiyon biriminin B girişine aktarılabilir, bu yüzden R0 A kanalına gelmelidir. MB = 1 ve 2 değerinin komuta gömülü olduğu varsayılır. Yazmaç dosyasının B kanalından ne geldiği önemsizdir. MD = 0, RW = 1.
- **Data out $\leftarrow R3$:** Data out hattı MUX B'nin çıkışından gelir. R3 yazmaç dosyasından B kanalına (BA = 011), MUX B'nin 0 girişinden Data out'a gider (MB = 0). Yazmaca yazılmaz, RW = 0.
- **$R4 \leftarrow$ Data in:** Bellekten gelen değerin Bus D'ye aktarılması için yalnız MD = 1 gerekir. DA = 100 (R4), RW = 1; AA, BA, MB ve FS don't care'dir.
- **$R5 \leftarrow 0$:** Kitapta bu işlem $R5 \leftarrow R0 \oplus R0$ olarak yapılır. AA = BA = 000, DA = 101, MB = 0, FS = 1010 (XOR), MD = 0, RW = 1. Hoca bunun önemli bir esneklik olduğunu söyledi: donanımda doğrudan bir sıfırlama işlemi olmadığı hâlde kontrol kelimesine bu anlam yüklenebilir ve komut kümesine bir "yazmacı sıfırla" komutu tanımlanabilir.

Kitaptaki tablolarda MB "Register/Constant", MD "Function/Data in", RW "Write/No Write" diye sembolik olarak da yazılır.

## 11. Kontrol kelimesinden komut kümesine

Şimdiye kadar yapılanlar sırasıyla şunlardır: yazmaç tanımlandı, yazmaçlar bir araya getirildi ve aralarında veri transferi tanımlanarak yazmaç dosyası ortaya çıktı. Aritmetik işlemlerle aritmetik birim, lojik işlemlerle lojik birim kombinasyonel devre olarak kuruldu ve birleştirilerek ALU oluştu. Öteleme ve döndürme birimi eklenerek fonksiyon birimi tamamlandı. Son olarak tek çevrimli CPU'nun kontrol kelimeleri tanımlandı.

Kontrol kelimesi geniş, esnek ve seyrek (sparse) bir bit dizisidir; her biti doğrudan bir işlev gösterir. Komutlar doğrudan kontrol kelimesi olarak tanımlansaydı her komut 16 bit olurdu. Oysa toplam komut sayısı düşünüldüğünde komutlar çok daha küçük genişliklerde paketlenebilir. Bu yüzden komutları çözüp kontrol kelimesine çeviren bir birime ihtiyaç doğar.

Blok diyagramda görünmeyen birimler de eklenmelidir:

- **Program sayıcı (PC):** sıradaki komutu gösterir; aslında komut belleğinin adresini işaret eder. Komutlar sırayla yürütülüyorsa her seferinde bir artırılır. Dallanmada ise belirli bir ofset kadar ileri ya da geri değiştirilir.
- **Komut belleği (instruction memory).**
- **Veri belleği (data memory):** veri saklanan ve okunan birim.

Yazmaç dosyası, PC, komut belleği ve veri belleği sistemdeki bütün hafıza birimleridir.

## 12. Basit bilgisayarın komutları

### 12.1 Komut biçimleri

Komut 16 bittir. Kitapta üç biçim vardır:

- **Yazmaç biçimi:** bitler 15-9 arası 7 bitlik **opcode**, kalan 9 bit 3'er bitlik **DR** (destination register, 8-6), **SA** (source register A, 5-3) ve **SB** (source register B, 2-0). DR doğrudan kontrol kelimesindeki DA'ya, SA AA'ya, SB BA'ya karşılık gelir. Opcode ise çözülerek MB, MD, RW ve FS üretilir; burada bire bir eşleşme olmayabilir.
- **Anlık operand biçimi:** opcode, DR, SA ve SB'nin yerinde 3 bitlik bir sabit **OP**. Sabit MUX B üzerinden fonksiyon biriminin B kanalına aktarıldığı için B yazmacının adresinin yerine yazılabilir. 3 bitle işaretsiz olarak 0-7, işaretli olarak $-4$ ile $3$ arası değer verilebilir. Hoca bunu `MOV AL, 5` gibi sabit içeren komutlarla örnekledi.
- **Dallanma biçimi:** opcode, durumu incelenen yazmaç SA, ve 6 bitlik işaretli görece adres **AD**. AD'nin yüksek anlamlı 3 biti DR alanına (bit 8-6), düşük anlamlı 3 biti SB alanına (bit 2-0) yazılır. Koşullu ya da koşulsuz dallanmada bir yazmaca bakılır ve PC'nin bulunduğu noktadan görece olarak yukarı ya da aşağı dallanılır.

### 12.2 Komut tablosu

Kitaptaki tablo (ekrandan, 02:15:00 ve 02:25:00). Her komut için ayrıca $PC \leftarrow PC + 1$ yürütülür:

| Komut | Opcode | Anımsatıcı | Biçim | Açıklama | Bayrak |
|---|---|---|---|---|---|
| Move A | 0000000 | MOVA | RD, RA | $R[DR] \leftarrow R[SA]$ | N, Z |
| Increment | 0000001 | INC | RD, RA | $R[DR] \leftarrow R[SA] + 1$ | N, Z |
| Add | 0000010 | ADD | RD, RA, RB | $R[DR] \leftarrow R[SA] + R[SB]$ | N, Z |
| Subtract | 0000101 | SUB | RD, RA, RB | $R[DR] \leftarrow R[SA] - R[SB]$ | N, Z |
| Decrement | 0000110 | DEC | RD, RA | $R[DR] \leftarrow R[SA] - 1$ | N, Z |
| AND | 0001000 | AND | RD, RA, RB | $R[DR] \leftarrow R[SA] \wedge R[SB]$ | N, Z |
| OR | 0001001 | OR | RD, RA, RB | $R[DR] \leftarrow R[SA] \vee R[SB]$ | N, Z |
| Exclusive OR | 0001010 | XOR | RD, RA, RB | $R[DR] \leftarrow R[SA] \oplus R[SB]$ | N, Z |
| NOT | 0001011 | NOT | RD, RA | $R[DR] \leftarrow \overline{R[SA]}$ | N, Z |
| Move B | 0001100 | MOVB | RD, RB | $R[DR] \leftarrow R[SB]$ | |
| Shift Right | 0001101 | SHR | RD, RB | $R[DR] \leftarrow \text{sr}\ R[SB]$ | |
| Shift Left | 0001110 | SHL | RD, RB | $R[DR] \leftarrow \text{sl}\ R[SB]$ | |
| Load Immediate | 1001100 | LDI | RD, OP | $R[DR] \leftarrow \text{zf}\ OP$ | |
| Add Immediate | 1000010 | ADI | RD, RA, OP | $R[DR] \leftarrow R[SA] + \text{zf}\ OP$ | N, Z |
| Load | 0010000 | LD | RD, RA | $R[DR] \leftarrow M[SA]$ | |
| Store | 0100000 | ST | RA, RB | $M[SA] \leftarrow R[SB]$ | |
| Branch on Zero | 1100000 | BRZ | RA, AD | $R[SA] = 0$ ise $PC \leftarrow PC + \text{se}\ AD$, değilse $PC \leftarrow PC + 1$ | N, Z |
| Branch on Negative | 1100001 | BRN | RA, AD | $R[SA] < 0$ ise $PC \leftarrow PC + \text{se}\ AD$, değilse $PC \leftarrow PC + 1$ | N, Z |
| Jump | 1110000 | JMP | RA | $PC \leftarrow R[SA]$ | |

Hoca komutları tek tek açıkladı:

- **MOVA:** iki parametre alır (kaynak ve hedef), B kısmı don't care'dir. SA'daki yazmacın değeri DR'ye aktarılır, PC bir artar, N ve Z bayrakları etkilenir. Hoca, 8086 komut tablolarında da opcode, işlem, biçim ve etkilenen bayrakların verildiğini hatırlattı; bu tablo onun daha genel bir hâlidir.
- **INC ve DEC:** tek kaynak (RA) ve hedef alır. Bunların A adresinde olmasının nedeni fonksiyon biriminde artırma ve azaltmanın yalnız A girişi için tanımlı olmasıdır; RB don't care'dir.
- **ADD, SUB, AND, OR, XOR:** üç parametre (RD, RA, RB). SUB'da A'dan B çıkarılır.
- **NOT:** iki parametre, kaynak ve hedef.
- **MOVB, SHR, SHL:** B'yi aktarma ve öteleme yalnız shifter bloğunda gerçekleşir ve shifter yalnız B kanalından giriş alır. Bu yüzden bu komutlar RB ve RD alır; SA don't care kalır. Komut kümesi arkadaki donanımla uyumlu olacak şekilde tasarlanmıştır.
- **LDI (Load Immediate):** komuta gömülü sabiti hedef yazmaca aktarır. Sabit 3 bittir, hedef yazmaç ise $n$ bittir. Bu yüzden sabit **sıfırla doldurularak** (zero fill) genişletilir: giren değer bloğun düşük anlamlı bitlerine yazılır, yüksek anlamlı bitler 0 ile doldurulur.
- **ADI (Add Immediate):** SA'daki yazmaçla sıfırla genişletilmiş 3 bitlik sabit toplanır, sonuç DR'ye yazılır. Sabit B kanalından gelir.
- **LD (Load):** bellekten değer okur. Hoca önce load'u belleğe yazma diye söyledi, sonra düzeltti: load bellekten okuma, store belleğe yazmadır. Okumak için adres çıkılmalı ve gelen veri Data in'den alınmalıdır. Adres, A kanalına çıkan yazmaç üzerinden dolaylı olarak verilir; bu yüzden LD, RD ve RA alır.
- **ST (Store):** bir yazmaçtaki değeri bir bellek adresine yazar. Adres A kanalından, veri B kanalından gelir. Yani B kanalında verilen yazmacın içeriği, A kanalında verilen yazmacın gösterdiği bellek adresine yazılır.
- **BRZ ve BRN:** durumu incelenen yazmaç mutlaka RA kanalından gelir. BRZ'de RA'daki yazmaç 0 ise 6 bitlik AD işaret genişletilip PC ile toplanır ve görece dallanma olur. BRN'de yazmaç 0'dan küçükse aynı işlem yapılır. Koşul sağlanmazsa PC bir artar, yani komut belleğindeki bir sonraki komuta geçilir.
- **JMP:** PC'ye görece değil, doğrudan değer atanır; atanan değer A kanalına verilen yazmacın içeriğidir.

### 12.3 İşaret genişletme

AD 6 bitlik ikiye tümleyen işaretli bir sayıdır. En yüksek anlamlı biti (5. bit) 0 ise dallanma ileriye, 1 ise geriye doğrudur. PC'ye eklenmeden önce AD PC'nin genişliğine **işaret genişletilir** (sign extend): 5. bit 1 ise üstteki bütün bitler 1 ile, 0 ise 0 ile doldurulur. Böylece sayının hem işareti hem büyüklüğü korunur.

**Soru:** Buraya bakarak PC'nin kaç bit olduğunu söyleyebilir misiniz? **Cevap:** Bir öğrenci 16 bit dedi. Hoca, PC'nin komut belleğinin adres işaretçisi olduğunu ve komut belleğinin 15 adres ucu bulunduğunu söyleyerek PC'yi 15 bitlik bir yazmaç olarak aldı; komut belleğinin 16 veri ucu olduğu için her komut 16 bittir.

<!-- BELİRSİZ: Hoca PC'yi 15 bit kabul etti, ama işaret genişletmeyi anlatırken "5'ten 15'e kadar olan bitleri 1 ile doldurur" diyerek 16 bitlik bir yazmaçtan söz etti. Komut belleğinin adres ucu sayısını gösteren slayt bu kayıttaki karelerde görünmüyor. -->

## 13. Bellekteki komutların çözülmesi

Komut belleğinin içeriği dökülüp (dump) her göz tek tek çözülmeye çalışılır. Kitaptaki tablo (ekrandan, 02:30:00):

| Ondalık adres | Bellek içeriği | Ondalık opcode | Diğer alanlar | İşlem |
|---|---|---|---|---|
| 25 | 0000101 001 010 011 | 5 (Subtract) | DR:1, SA:2, SB:3 | $R1 \leftarrow R2 - R3$ |
| 35 | 0100000 000 100 101 | 32 (Store) | SA:4, SB:5 | $M[R4] \leftarrow R5$ |
| 45 | 1000010 010 111 011 | 66 (Add Immediate) | DR:2, SA:7, OP:3 | $R2 \leftarrow R7 + 3$ |
| 55 | 1100000 101 110 100 | 96 (Branch on Zero) | AD:44, SA:6 | $R6 = 0$ ise $PC \leftarrow PC - 20$ |
| 70 | 0000000011000000 | | | Veri = 192 |

- **Adres 25:** opcode 5 çıkarma işlemidir. DR = 1, SA = 2, SB = 3; R2'den R3 çıkarılıp sonuç R1'e yazılır. Bu, yazmaç biçimindeki bir komut örneğidir.
- **Adres 35:** opcode store'dur. Adres A kanalından, veri B kanalından gelir. Register file'a yazma olmadığı için DR alanı 0 yazılmıştır, kontrol kelimesindeki karşılığı don't care'dir. R4'ün gösterdiği bellek adresine R5'in içeriği yazılır.
- **Adres 45:** opcode add immediate'dir. DR = 2, SA = 7, OP = 3; R7 ile 3 toplanıp R2'ye yazılır.
- **Adres 55:** opcode 1100000, branch on zero'dur. Ortadaki alan SA = 110, yani R6. Sağdaki ve soldaki alanlar 6 bitlik görece adresin parçalarıdır: yüksek anlamlı kısım 101, düşük anlamlı kısım 100, birleşince AD = 101100.

AD'nin değeri adım adım bulunur:

- AD = 101100, en yüksek anlamlı biti 1 olduğundan negatiftir.
- Büyüklüğü bulmak için ikiye tümleyen alınır: sağdan ilk 1 dahil bitler aynen bırakılır (…100), soldaki bitler tersine çevrilir (101 → 010). Sonuç 010100.
- $010100_2 = 16 + 4 = 20$. Yani AD $= -20$ (işaretsiz okunursa 44, tablodaki "AD: 44" budur; $44 - 64 = -20$).

Sonuç: R6 = 0 ise 20 komut geriye dallanılır ($PC \leftarrow PC - 20$); R6 sıfır değilse PC bir artar. Opcode'ların ondalık değerleri (5, 32, 66, 96) ve AD $= -20$ ders sonrasında python ile denetlendi.

- **Adres 70:** bu bir komut değildir. Veri olarak değerlendirilirse 192 sayısıdır; tabloda 35'teki komut yürütüldükten sonra bu sözcüğün değerinin 80 olduğu da yazar. Hoca bunu von Neumann mimarisiyle ilişkilendirdi: komut ve veri belleği aynı yolları kullandığında aynı hafızada yer alabilir. PC oraya gelirse sözcük opcode olarak çözülmek zorundadır; o bölge veri bölgesi olarak ayrılmışsa sözcük yalnızca bir bit dizisidir.

## 14. Tam blok diyagram: PC, bellekler ve dallanma denetimi

Eksik parçalar eklendiğinde basit bilgisayarın tam şeması ortaya çıkar (ekrandan, 02:35:00). Veri yolu tarafında yazmaç dosyası, MUX B, fonksiyon birimi ve MUX D önceden görülmüştü. Yeni eklenenler şunlardır:

- **Veri belleği:** Address (Bus A'dan), Data in (Bus B'den, yani Data out hattı) ve Data out (MUX D'nin 1 girişine giden Data in) uçları vardır. Kombinasyonel mantık nedeniyle adres ve veri hatlarına her zaman bir değer ulaşır; ama belleğe yalnız gerçekten yazma isteyen bir komut varken yazılmalıdır. Bunun için yeni bir kontrol işareti gerekir: **MW** (memory write).
- **Zero fill:** komuttaki 3 bitlik sabit (IR(2:0)) $n$ bite (örneğin 16 bite) sıfırla genişletilip Constant in olarak MUX B'ye verilir.
- **Extend:** dallanma komutundaki görece adresin parçaları (IR(8:6) ve IR(2:0)) sırt sırta birleştirilerek 6 bitlik değer oluşturulur, PC'nin genişliğine işaret genişletilir ve PC ile toplanır. Hoca, şekilde gösterilmese de burada bir toplama devresi olduğunu belirtti.
- **Komut belleği:** adres uçları PC'ye bağlıdır. Bir algoritmaya göre yazılmış assembly komutlarının (dallanmalar, atamalar, aritmetik-lojik işlemler) makine kodları burada bir blok olarak durur; her komut 16 bittir.
- **Jump Address:** A kanalından PC'ye giden yol.

**Soru:** Şemada A yolu üzerinden gelip PC'yi değiştiren şey nedir? **Cevap:** Bir öğrenci "jump" dedi. Hoca onayladı: koşulsuz dallanmada A kanalındaki yazmaç değeri doğrudan PC'ye yüklenir.

Böylece PC'nin üç kaynağı vardır: koşullu dallanmada komuttaki görece adres işaret genişletilip PC ile toplanır; koşulsuz dallanmada A kanalındaki değer doğrudan PC'ye yazılır; dallanma yoksa PC bir artar. Hangisinin seçileceğine **dallanma denetimi** (Branch Control) karar verir. Bu birime V, C, N, Z durum bitleri ve üç kontrol biti girer:

- **PL:** dallanma (PC'ye yükleme) var mı, yok mu.
- **JB:** dallanma koşulsuz (jump) mu, koşullu (branch) mu.
- **BC:** koşullu dallanma sıfıra göre mi, negatife göre mi.

Önceki kontrol bitleri DA, AA, BA, MB, FS, MD ve RW idi. Sisteme MW, PL, JB ve BC eklenince kontrol kelimesi 20 bite çıkar. Komutlar 16 bit, kontrol kelimesi 20 bit olduğundan komutların kontrol kelimesinin uygun gruplara bölünmüş ve paketlenmiş hâli olduğu açıkça görülür.

## 15. Komut çözücü

Kontrol işaretleri komutun içinde açıkça yazılı değildir; bunları **komut çözücü** (instruction decoder) üretir. Çözücü PC'nin gösterdiği adresteki komutu alır ve 20 bitlik kontrol işaretini üretir (ekrandan, 02:40:00):

```text
Komut:          Opcode (15-9) | DR (8-6) | SA (5-3) | SB (2-0)
Kontrol kelimesi: DA (19-17) | AA (16-14) | BA (13-11) | MB (10) | FS (9-6)
                  | MD (5) | RW (4) | MW (3) | PL (2) | JB (1) | BC (0)
```

DR doğrudan DA'ya, SA AA'ya, SB BA'ya gider. Opcode bitlerinden ise birkaç kapıyla MB, FS, MD, RW, MW, PL, JB ve BC üretilir. Hoca, gerçekte opcode'ların çözücüyü olabildiğince basitleştirecek şekilde seçildiğini, uygun gruplanması gerektiğini söyledi. Kitapta bütün komutlar ve kontrol kelimeleri bir tabloda toplanmış, her kontrol biti için komut bitlerine bağlı bir fonksiyon yazılıp indirgenmiştir. Bunun sonucunda örneğin BC doğrudan opcode'un 9 numaralı biti, JB ise 13 numaralı biti olarak çıkmıştır.

Çözücünün doğruluk tablosu (ekrandan, 02:45:00):

| Komut işlev tipi | 15 | 14 | 13 | 9 | MB | MD | RW | MW | PL | JB | BC |
|---|---|---|---|---|---|---|---|---|---|---|---|
| Yazmaçlarla FU işlemi | 0 | 0 | 0 | X | 0 | 0 | 1 | 0 | 0 | X | X |
| Bellek okuma | 0 | 0 | 1 | X | 0 | 1 | 1 | 0 | 0 | X | X |
| Bellek yazma | 0 | 1 | 0 | X | 0 | X | 0 | 1 | 0 | X | X |
| Yazmaç ve sabitle FU işlemi | 1 | 0 | 0 | X | 1 | 0 | 1 | 0 | 0 | X | X |
| Sıfıra göre koşullu dallanma (Z) | 1 | 1 | 0 | 0 | X | X | 0 | 0 | 1 | 0 | 0 |
| Negatife göre koşullu dallanma (N) | 1 | 1 | 0 | 1 | X | X | 0 | 0 | 1 | 0 | 1 |
| Koşulsuz dallanma | 1 | 1 | 1 | X | X | X | 0 | 0 | 1 | 1 | X |

Hoca satırları şöyle açıkladı:

- **Yazmaçlarla fonksiyon birimi işlemi** (opcode'un üst bitleri 000): MUX B sabit yerine yazmacı seçer, sonuç fonksiyon biriminden hedefe aktarılır, yazmaca yazılır; belleğe yazma ve dallanma yoktur.
- **Bellek okuma** (001): MD = 1 olmalıdır, çünkü bellekten gelen değer yazılacaktır; RW = 1. Hoca burada MB'nin değeri üzerinde bir an duraksadı; tabloya göre MB = 0'dır.
- **Bellek yazma** (010): adres A kanalından, veri yazmaç dosyasının B kanalından geleceği için MB = 0 olmalıdır; MW = 1, RW = 0.
- **Yazmaç ve sabitle işlem** (100): MUX B sabiti seçer (MB = 1), MD = 0, RW = 1.
- **Koşullu dallanma:** yazmaca ve belleğe yazma yoktur, PL = 1, JB = 0. BC sıfıra göre dallanmada 0, negatife göre dallanmada 1'dir.
- **Koşulsuz dallanma:** PL = 1, JB = 1.

Instruction'dan kontrol kelimesine geçerken bu şekilde bir gruplama yapılırsa çözücü için çok uğraşmaya gerek kalmaz. Gruplama dikkate alınmadan komutlarla kontrol kelimeleri arasında sırayla ilişki kurulmaya çalışılırsa karmaşık bir çözücüyle karşılaşılır.

Hoca son olarak örnek komutların çözücüden çıkan kontrol kelimelerini sözlü olarak inceledi (slaytı yakınlaştırmaya çalıştı ama başaramadı; ayrıntıya öğrencilerin daha sonra bakmasını istedi):

- **ADI:** MB = 1 seçilir; sonuç yazmaç dosyasına yazılır (RW = 1). Hoca, bu ikisinin gerçekten aranan çıktılar olduğunu, bazı don't care alanların en uygun Karnaugh grubunda 1 olarak çıktığını söyledi. Belleğe yazma ve dallanma yoktur.
- **LD:** A kanalındaki değer adresi belirler; MW = 0, RW = 1, MD = 1 (veri belleğinin çıkışı okunur). Dallanma yoktur; bazı alanlar don't care'den 1 ya da 0 çıkmıştır.
- **ST:** Hem A hem B kanalından değer gelir; MB mutlaka yazmaç B kanalını göstermelidir, çünkü veri oradadır. MW = 1, dallanma yoktur.
- **SHL:** sonuç fonksiyon biriminden hedefe aktarılır ve yazılır; dallanma yoktur.
- **BRZ:** dallanma vardır (PL = 1), koşulsuz değildir (JB = 0), sıfıra göre olduğu için BC = 0.

> **Ders sonrası not:** Hoca store komutu için "MD'nin 1 olması lazım" dedi. Çözücünün doğruluk tablosunda bellek yazma satırında MD = X'tir (don't care), çünkü yazmaç dosyasına yazılmaz (RW = 0). Store için MD'nin 1 olması gerekmez; çözücüden çıkan somut değer büyük olasılıkla don't care'in Karnaugh indirgemesindeki seçimine bağlıdır.

<!-- BELİRSİZ: Hocanın sözlü incelediği örnek kontrol kelimeleri tablosu (ADI, LD, ST, SHL, BRZ satırları) bu kayıttaki karelerde okunur biçimde görünmüyor; bu yüzden tam bit değerleri nota alınmadı. -->

## 16. Tek çevrimde gecikme yolu

Bir komut yürütülürken çeşitli blokların işlevlerini yapıp anlamlı değerlere ulaşması beklenmelidir. Sıra şöyledir: önceki işlem bitince PC'ye yeni değer yüklenir; komut belleğinden sıradaki komut alınır ve çözülür; yazmaç dosyası ilgili çıktıları üretir; MUX B seçimini yapar; fonksiyon birimi işlemi ya da bellek okuması gerçekleşir; MUX D seçimini yapar; son olarak veri yazmaç dosyasına geri yazılır.

Slayttaki gecikmeler (ekrandan, 02:50:00):

| Blok | Gecikme | Birikimli |
|---|---|---|
| PC | 0.2 ns | 0.2 ns |
| Komut belleği | 4 ns | 4.2 ns |
| Yazmaç dosyası (okuma) | 0.6 ns | 4.8 ns |
| MUX B | 0.2 ns | 5.0 ns |
| Fonksiyon birimi ya da veri belleği | 4 ns | 9.0 ns |
| MUX D | 0.2 ns | 9.2 ns |
| Yazmaç dosyası (yazma) | 0.6 ns | 9.8 ns |

Hoca birikimli değerleri 4.2, 4.8, 5, 9, 9.2, 9.8 ns olarak okudu (python ile denetlendi). Her bloğun süresi, anlamlı veriyi üretmek için geçen yayılma (propagation) süresi olarak düşünülebilir; saat periyodu bu toplam yolu karşılamalıdır.

> **Ek bilgi (derste anlatılmadı):** Tek çevrimli tasarımda bütün komutlar en uzun yolu (burada büyük olasılıkla bellek okuyan ya da fonksiyon biriminden geçen komutların yolu) bir saat periyodunda tamamlamak zorundadır. Bu yüzden saat periyodu en yavaş komuta göre seçilir; çok çevrimli ve boru hattılı tasarımlar bu sınırlamayı gevşetmek için geliştirilmiştir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:18:36): ALU'nun $n$ bitlik çıkışından sıfır bayrağını üreten lojik nedir?

> **Çözüm (derste verildi):** Çıkışın bütün bitleri OR'lanırsa hepsi 0 iken 0 çıkar, oysa $Z = 1$ olmalıdır. Doğrusu NOR'dur: $Z = \overline{R_0 + R_1 + \cdots + R_{n-1}}$ (ekrandan, 00:20:00).

**Soru 2** (derste sözlü, 00:20:50): İşaret (negatif) bayrağı nasıl üretilir?

> **Çözüm (derste verildi):** İkiye tümleyen gösterimde en yüksek anlamlı bit 1 ise sayı negatiftir. N bayrağına doğrudan yazmacın en yüksek anlamlı biti atanır.

**Soru 3** (derste sözlü, 00:43:01): Bir $n$ bitlik tam toplayıcıyla $X = A$ bağlıyken $F = A - 1$ nasıl elde edilir?

> **Çözüm (derste verildi):** $Y$'nin bütün bitlerine 1 (yani $-1$), $C_{in}$'e 0 verilir: $A + (-1) + 0 = A - 1$. Aynı bağlantıda $C_{in} = 1$ verilirse $A + (-1) + 1 = A$ olur.

**Soru 4** (tahtada, ekrandan, 00:45:00 ve 00:50:00): $S_2 S_1 S_0$ = 000: $A$, 001: $A+1$, 010: $A+B$, 011: $A+B+1$, 100: $A+\overline{B}$, 101: $A+\overline{B}+1$, 110: $A-1$, 111: $A$ fonksiyon tablosunu gerçekleştiren aritmetik birimin $X_i$, $Y_i$ ve $C_{in}$ giriş lojiklerini bulun.

> **Çözüm (derste verildi):** $X_i = A_i$; $C_{in} = S_0$; Karnaugh diyagramından $Y_i = S_1 B_i + S_2 \overline{B_i}$. $C_{in}$ yalnız en düşük anlamlı tam toplayıcının elde girişine bağlanır.

**Soru 5** (ekrandan, 01:20:00): Her bit için 3 girişli bir MUX kullanan 4 bitlik shifter devresinin (0 girişine kendi biti, 1 girişine solundaki bit ya da $I_R$, 2 girişine sağındaki bit ya da $I_L$) fonksiyon tablosunu çıkarın.

> **Çözüm (derste verildi):** S = 00: $H = B$ (transfer); S = 01: $H_3 = I_R$, $H_2 = B_3$, $H_1 = B_2$, $H_0 = B_1$ (sağa öteleme, sr B); S = 10: $H_3 = B_2$, $H_2 = B_1$, $H_1 = B_0$, $H_0 = I_L$ (sola öteleme, sl B).

**Soru 6** (ekrandan, 01:40:00): $R1 \leftarrow R2 - R3$, $R4 \leftarrow \text{sl}\ R6$, $R7 \leftarrow R7 + 1$, $R1 \leftarrow R0 + 2$, Data out $\leftarrow R3$, $R4 \leftarrow$ Data in ve $R5 \leftarrow 0$ mikro işlemlerinin 16 bitlik kontrol kelimelerini (DA, AA, BA, MB, FS, MD, RW) yazın.

> **Çözüm (derste verildi):** Sırasıyla (ekrandan, 01:50:00): 001 010 011 0 0101 0 1; 100 XXX 110 0 1110 0 1; 111 111 XXX X 0001 0 1; 001 000 XXX 1 0010 0 1; XXX XXX 011 0 XXXX X 0; 100 XXX XXX X XXXX 1 1; 101 000 000 0 1010 0 1. Açıklamalar 10. bölümdedir.

**Soru 7** (ekrandan, 02:30:00): Komut belleğinin 55. adresinde `1100000 101 110 100` bulunuyor. Bu komut ne yapar?

> **Çözüm (derste verildi):** Opcode 1100000 (96) BRZ'dir. SA = 110, yani R6. AD = 101 ∥ 100 = 101100; ikiye tümleyeni 010100 = 20 olduğundan AD $= -20$. R6 = 0 ise $PC \leftarrow PC - 20$, değilse $PC \leftarrow PC + 1$.

**Soru 8** (derste sözlü, 02:35:09): Tam blok diyagramda A yolu üzerinden gelip PC'yi değiştiren yol hangi komut içindir?

> **Çözüm (derste verildi):** Koşulsuz dallanma (JMP). A kanalındaki yazmacın değeri doğrudan PC'ye yüklenir.

## Dersin Toparlaması

Bu derste tek çevrimli bir bilgisayar baştan sona kuruldu. İki operandı aynı anda okuyup bir hedefi saat kenarında yazan yazmaç dosyası, MUX B ile sabit girişi, fonksiyon biriminin içindeki ALU ve shifter, MUX F ve MUX D ile geri yazma yolu tanıtıldı. Sıfır, negatif, elde ve taşma bayraklarının hangi lojikle üretildiği gösterildi. Aritmetik birim, verilen bir fonksiyon tablosundan toplayıcının giriş lojikleri Karnaugh diyagramıyla bulunarak tasarlandı; lojik birim ve shifter/döndürücü MUX'larla kuruldu ve hepsi 4 bitlik FS koduyla seçilen bir fonksiyon biriminde toplandı.

İkinci kısımda bu blokların seçme uçları 16 bitlik kontrol kelimesine dönüştürüldü ve donanım kısıtları (yalnız $A - B$, artırmanın A'da, ötelemenin B'de olması) dikkate alınarak mikro işlemler kontrol kelimelerine çevrildi. Ardından kontrol kelimesinin paketlenmiş hâli olan 16 bitlik komut biçimleri, basit bilgisayarın komut kümesi, sıfırla ve işaretle genişletme, bellek dökümünden komut çözme, PC, komut ve veri belleği, dallanma denetimi ve komut çözücü işlendi. Son olarak bir komutun tek çevrimde geçtiği blokların gecikmeleri incelendi; hoca bir sonraki derste bu yapıyı farklı şekillerde ifade etmeye devam edeceklerini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
