# Ders 6 Genişletilmiş Notu: Sayı Sistemleri, Kodlar, Lojik Kapılar ve Boole Cebrine Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Analog işaretin sayısallaştırılması
- 2. Sayı sistemleri ve taban dönüşümleri
- 3. Farklı tabanlarda aritmetik ve tümleyen aritmetiği
- 4. Bilgisayarda sayıların gösterimi
- 5. Kodlama
- 6. Temel lojik işlemler ve kapılar
- 7. Boole cebri
- Örnek Sorular

## 1. Analog İşaretin Sayısallaştırılması

Ders, bir önceki haftada başlanan işaretler konusunun kısa bir tekrarıyla açıldı. İşaretler analog ve sayısal (dijital) olmak üzere ikiye ayrılır. Analog işarette yatay eksen zamanı, dikey eksen ise ölçülen niceliği (gerilim, akım, gerinim vb.) gösterir ve bu nicelik zaman içinde sürekli değişir.

Analog işaret, belirlenen aralıklarla örneklenip her aralıkta değeri bir sonraki örneğe kadar sabit tutularak sayısallaştırılır. Bunun nedeni bilgisayarın sonlu bir makine olmasıdır: sonsuz bir zaman ekseninde sonsuz sayıda değer alan bir işareti doğrudan işleyemez. Belirli süre boyunca aynı değeri gösteren bölgeler, işaretin zamanda ayrıklaştırılmış (discrete) halini oluşturur. Bu konu ileride sayısal işaret işleme derslerinde ayrıntılı işlenecektir. Oluşan her basamak, sayısal biçimde yazılabilecek bir etikete karşılık gelir.

Slayttaki bilgiler (ekrandan, 00:15:00):

- Analog işaretten kodlanmış sayısal işaret ADC (analog-sayısal) çeviricilerle elde edilir; ters işlem DAC (sayısal-analog) çeviricilerle yapılır.
- Analog dönüşümlerde duyarlılık, oluşacak sayısal işaretin kalitesini, yani basamak sayısını belirler.
- Çözünürlük (adım): $a = \dfrac{V_{maks}}{2^n}$. Slaytta ayrıca $\omega_s \ge 2\omega_c$ bağıntısı yer alıyordu; derste ayrıca açıklanmadı.

### 1.1 Tek bit ve çok bitli gösterim

İşaret tek bitle gösterilecekse bir eşik (threshold) seçilir: eşiğin altındaki değerlere 0, üstündekilere 1 denir. Hoca bunu klimadaki termostata benzetti. Klima sıcaklığı ölçer; belirli bir sıcaklığın üstündeyse soğutmaya başlar, altındaysa durur. Sıcaklık aslında sürekli bir büyüklüktür (24,3 derecenin ardında virgülden sonra çok sayıda basamak vardır) ama bu eşikle 1 ve 0'a indirgenir.

Bir yerine üç eşik (örneğin 2, 4 ve 6 seviyeleri) kullanılırsa işaret daha fazla aralığa bölünür: 2'nin altı, 2 ile 4 arası, 4 ile 6 arası, 6'nın üstü. Her aralığa ikili bir etiket vermek gerektiğinden basamak sayısı arttıkça gereken bit sayısı da artar. Sonuçta elde edilen sayısal işaret orijinaline daha çok benzer. Kısacası sayısallaştırmanın çözünürlüğü, sayısal işaretin bit genişliğiyle belirlenir.

Hoca bunu ADC'ler üzerinden örnekledi: 8 bitlik bir ADC işareti daha geniş basamaklarla, 16 bitlik bir ADC ise çok daha dar basamaklarla gösterir. Bu yüzden 16 bitlik çevirici daha hassas işlem yapılmasını sağlar (ekrandan, 00:20:00).

### 1.2 Örnek: ADC için gereken bit sayısı

0 ile 15 V arasında sürekli değer alan bir işaret 100 mV duyarlılıkla kodlanmak isteniyor. Basamak aralığı 100 mV olacağından:

$$\frac{15\,000\ \text{mV}}{100\ \text{mV}} = 150 \le 2^n$$

$2^7 = 128$ yetmez, $2^8 = 256$ yeter. Bu nedenle 8 bitlik bir ADC ile 100 mV duyarlılık elde edilir.

> **Ders sonrası not:** Hoca anlatırken bir yerde 15 V için "1500 milivolt" dedi; doğrusu 15 000 mV'tur. Hesapta kullanılan 150 basamak sayısı doğru değerle uyumludur.

### 1.3 Örnek: DAC adımı

4 bitlik bir DAC'de $0000$ kodu 0 V'u, $1111$ kodu 6 V'u gösteriyor. Dönüşüm tablosunu kurmak için önce bir adımın kaç volta karşılık geldiği bulunur:

$$a = \frac{6}{2^4} = \frac{3}{8} = 0{,}375\ \text{V}$$

Hoca, bazı kaynakların paydayı $2^n - 1$ olarak yazdığını, bunun burada çok önemli olmadığını söyledi.

> **Ders sonrası not:** $1111$ kodunun tam olarak 6 V'a karşılık gelmesi isteniyorsa adım büyük olasılıkla $6/(2^4-1) = 0{,}4$ V olmalıdır. Derste kullanılan $6/2^4 = 0{,}375$ V adımıyla $1111 = 15$ kodu $15 \cdot 0{,}375 = 5{,}625$ V'a karşılık gelir.

## 2. Sayı Sistemleri ve Taban Dönüşümleri

Sayısallaştırılmış işaret bilgisayarda 1 ve 0'lardan oluşur, ama okunan değerin onluk ya da onaltılık karşılığını bilmek pek çok uygulamada gerekir. Bu yüzden taban dönüşümleri tekrar edildi.

Slayttaki sınıflandırma ve çözümleme örnekleri (ekrandan, 00:25:00):

- Onluk (decimal) sistem: 10 tabanlı.
- Sekizlik (octal) sistem: 8 tabanlı.
- İkili (binary) sistem: 2 tabanlı.
- Onaltılı (hexadecimal) sistem: 16 tabanlı.

$$(173{,}25)_{10} = 1\cdot10^2 + 7\cdot10^1 + 3\cdot10^0 + 2\cdot10^{-1} + 5\cdot10^{-2}$$

$$(1247{,}172)_8 = 1\cdot8^3 + 2\cdot8^2 + 4\cdot8^1 + 7\cdot8^0 + 1\cdot8^{-1} + 7\cdot8^{-2} + 2\cdot8^{-3}$$

$$(10111)_2 = 1\cdot2^4 + 0\cdot2^3 + 1\cdot2^2 + 1\cdot2^1 + 1\cdot2^0$$

İkili sistemde her hane **bit**, yan yana 4 bit **nibble**, 8 bit **byte**, 16 bit (2 byte) **word** olarak adlandırılır.

### 2.1 İkiliden onluğa

İkili sayı, basamak ağırlıklarıyla çarpılıp toplanarak onluğa çevrilir:

$$(1010)_2 = 1\cdot2^3 + 0\cdot2^2 + 1\cdot2^1 + 0\cdot2^0 = 10$$

Benzer bir örnekte sonuç 25 bulundu. Virgülden sonraki basamaklar $2^{-1}, 2^{-2}, \dots$ ağırlıklarıyla çözümlenir. Derste işlenen örnekte tam kısım $111 = 7$, kesirli kısım ise $.101$ idi:

$$1\cdot2^{-1} + 0\cdot2^{-2} + 1\cdot2^{-3} = \frac{1}{2} + \frac{1}{8} = \frac{5}{8} = 0{,}625$$

Böylece sayı $7{,}625$ olur.

<!-- BELİRSİZ: 25 sonucunu veren ikili sayı ve 7,625 örneğinin yazılı hali karede görülmedi; .101 kesri altyazıdaki anlatımdan (2^-1 ve 2^-3 terimleri) kuruldu. -->

### 2.2 Onluktan ikiliye

**Birinci yöntem: art arda bölme.** Sayı 2'ye bölünür, bölüm yeniden 2'ye bölünür ve bu bölüm 0 olana kadar sürer. İlk kalan LSB (en anlamsız bit), son kalan MSB (en anlamlı bit) olur; kalanlar tersten okunur. Onluk sayıda nasıl yüzler basamağı birler basamağından daha anlamlıysa, ikili sayıda da en soldaki bit MSB, en sağdaki bit LSB'dir.

Slayttaki tablolar (ekrandan, 00:30:00):

| Bölünen | Bölüm | Kalan |
|---|---|---|
| 33 ÷ 2 | 16 | 1 (LSB) |
| 16 ÷ 2 | 8 | 0 |
| 8 ÷ 2 | 4 | 0 |
| 4 ÷ 2 | 2 | 0 |
| 2 ÷ 2 | 1 | 0 |
| 1 ÷ 2 | 0 | 1 (MSB) |

Sonuç: $(33)_{10} = (100001)_2$.

| Bölünen | Bölüm | Kalan |
|---|---|---|
| 172 ÷ 2 | 86 | 0 |
| 86 ÷ 2 | 43 | 0 |
| 43 ÷ 2 | 21 | 1 |
| 21 ÷ 2 | 10 | 1 |
| 10 ÷ 2 | 5 | 0 |
| 5 ÷ 2 | 2 | 1 |
| 2 ÷ 2 | 1 | 0 |
| 1 ÷ 2 | 0 | 1 |

Sonuç: $(172)_{10} = (10101100)_2$.

> **Ders sonrası not:** Slayttaki 172 tablosunda $10 \div 2$ satırının kalanı 1, $5 \div 2$ satırının kalanı 1 ve sonuç $(10111100)_2$ yazılmıştı. Hoca da "şurada bir yanlışlık yapılmış" diyerek düzeltti: $10 \div 2$'nin kalanı 0'dır ve doğru sonuç $(10101100)_2 = 128 + 32 + 8 + 4 = 172$'dir (python ile doğrulandı).

**İkinci yöntem: en büyük 2 kuvvetini çıkarma.** Sayıdan, ona sığan en büyük 2 kuvveti çıkarılır ve kalanla devam edilir. Hoca, $2^7 = 128$ ve $2^8 = 256$ gibi kuvvetlerin zamanla akılda kalacağını söyledi:

- $172 - 2^7 (128) = 44$
- $44 - 2^5 (32) = 12$
- $12 - 2^3 (8) = 4$
- $4 - 2^2 (4) = 0$

Kullanılan kuvvetlerin yerine 1, diğerlerine 0 yazılır: $2^7, 2^5, 2^3, 2^2 \Rightarrow (1010\,1100)_2$. Bu yöntem bölme yönteminden daha pratiktir.

### 2.3 Kesirli kısmın ikiliye çevrilmesi

Kesirli kısım 2 ile çarpılır; virgülün soluna geçen basamak (0 ya da 1) alınır, kalan kesirle işleme devam edilir. İlk alınan basamak virgülden sonraki en anlamlı bit, son alınan en anlamsız bittir. Derste tam kısmı 7 ($111$) olan bir sayının kesirli kısmı için ilk adım $0{,}8125 \cdot 2 = 1{,}625$ olarak gösterildi ve ilk bit 1 alındı; işlem $0{,}625$ ile sürdürüldü.

Adımların tamamı (ara adım eklendi):

- $0{,}8125 \cdot 2 = 1{,}625 \to 1$
- $0{,}625 \cdot 2 = 1{,}25 \to 1$
- $0{,}25 \cdot 2 = 0{,}5 \to 0$
- $0{,}5 \cdot 2 = 1{,}0 \to 1$

Sonuç: $(0{,}8125)_{10} = (0{,}1101)_2$.

<!-- BELİRSİZ: Bu örneğin slaytı karede görülmedi; 0,8125 değeri altyazıdaki "0.81.25" ve "1.625" ifadelerinden çıkarıldı. -->

### 2.4 Sekizlik taban

Sekizlikten onluğa geçiş ikilikten onluğa geçişle aynıdır: basamaklar $8^k$ ağırlıklarıyla, virgülden sonrası $8^{-1}, 8^{-2}, \dots$ ile çözümlenir. Onluktan sekizliğe geçişte en büyük 8 kuvvetini çıkarma yöntemi zor olduğundan sayı 8'e art arda bölünür; kalanlar yine LSB'den MSB'ye doğru dizilir. Kesirli kısım 8 ile çarpılarak virgülün soluna taşan basamaklarla yazılır.

<!-- BELİRSİZ: Onluktan sekizliğe örnekte kullanılan sayı altyazıda "347" diye geçiyor; slayt karede görülmedi. -->

**İkiliden sekizliğe kısa yol:** $2^3 = 8$ olduğundan ikili sayı virgülden başlayarak üçerli gruplara ayrılır ve her grup bir sekizlik basamak olur. Önce onluğa, sonra sekizliğe çevirmek mantıklı değildir. Virgülün solunda gruplar sağdan sola, virgülün sağında soldan sağa kurulur; sağ tarafta eksik kalan grup sağına 0 eklenerek üçe tamamlanır.

**Sekizlikten ikiliye:** her sekizlik basamağın 3 bitlik karşılığı yazılır; örneğin $7 \to 111$, $3 \to 011$.

### 2.5 Onaltılık taban

Onaltılıktan onluğa geçişte de çözümleme kullanılır; burada $A = 10$, $B = 11$, $C = 12$, $D = 13$, $E = 14$, $F = 15$ olduğunu bilmek gerekir. Virgülden sonrası $16^{-1}, 16^{-2}, \dots$ ile çarpılır.

Onluktan onaltılığa geçiş 16'ya art arda bölmeyle yapılır (ekrandan, 00:40:00):

| Bölünen | Bölüm | Kalan |
|---|---|---|
| 1357 ÷ 16 | 84 | 13 (D), LSB |
| 84 ÷ 16 | 5 | 4 |
| 5 ÷ 16 | 0 | 5, MSB |

Sonuç: $(1357)_{10} = (54D)_{16}$.

İkinci örnek $(25{,}125)_{10}$: tam kısım için $25 \div 16 = 1$, kalan 9 (LSB); $1 \div 16 = 0$, kalan 1 (MSB), yani $(19)_{16}$. Kesirli kısım için $0{,}125 \cdot 16 = 2{,}00$, yani $(0{,}125)_{10} = (0{,}2)_{16}$. Sonuç: $(25{,}125)_{10} = (19{,}2)_{16}$.

**İkili-onaltılı kısa yol:** $2^4 = 16$ olduğundan ikili sayı dörderli gruplara ayrılır ve her grup bir onaltılık basamak olur; tersinde her onaltılık basamağın 4 bitlik karşılığı yazılır.

## 3. Farklı Tabanlarda Aritmetik ve Tümleyen Aritmetiği

### 3.1 Toplama

İkili toplamada $1 + 1 = 2$ olduğunda o basamağa 0 yazılır ve sola 1 elde aktarılır. Sekizlik tabanda da aynı mantık geçerlidir: örneğin $3 + 7 = 10$ olur; bu 8'i geçtiği için basamağa $10 - 8 = 2$ yazılır ve sola 1 elde aktarılır. Onaltılık tabanda $7 + 3 = 10 = A$'dır; toplam 16'yı geçerse 16 çıkarılıp sola elde aktarılır.

<!-- BELİRSİZ: Sekizlik ve onaltılık toplama örneklerinin tamamı karede görülmedi; yalnız altyazıdaki adımlar aktarıldı. -->

### 3.2 Onluk yöntemle çıkarma

Üstteki sayı alttakinden büyükse çıkarma bilinen borç alma yöntemiyle yapılır (ekrandan, 00:45:00). Slayttaki örnekte $(101)_2 - (011)_2 = (010)_2$ işleminde bir üst basamaktan borç alınınca o sütun $(10)_2$ olur ($10 - 1 = 1$), borç veren basamak ise 0'a iner ($0 - 0 = 0$). Aynı slaytta alıştırma olarak $(100)_2 - (011)_2$ ve $(1010)_2 - (0011)_2$ verilmişti.

> **Ders sonrası not:** Slaytın sol üst kutusunda $(011)_2 - (001)_2 = (010)_2$ işleminin yanına onluk karşılık olarak $5 - 3 = 2$ yazılmıştı. İkili işlemin onluk karşılığı $3 - 1 = 2$'dir; $5 - 3 = 2$ ise $(101)_2 - (011)_2 = (010)_2$ işlemine karşılık gelir.

### 3.3 Bire tümleyen aritmetiği ile çıkarma

Hoca, bilgisayar sistemlerinde çıkarma işlemi olmadığını, bunun yerine tümleyen alınıp toplama yapıldığını vurguladı. İleride toplama-çıkarma devreleri bu mantıkla kurulacaktır.

Bire tümleme, sayının 1'lerini 0, 0'larını 1 yapmaktır. Yöntem:

1. İlk olarak üstteki sayının alttakinden büyük olup olmadığına bakılır; sonuç negatifse ek bir işlem gerekecektir.
2. Çıkan sayının bire tümleyeni alınır.
3. Bu tümleyen çıkılan sayıyla toplanır.
4. Elde 1 oluşursa sonuç pozitiftir; gerçek sonuç, eldenin en sağdaki basamağa eklenmesiyle bulunur.
5. Elde oluşmazsa sonuç negatiftir; gerçek sonuç, bulunan toplamın bire tümleyenidir.

**Negatif sonuçlu örnek** (ekrandan, 00:50:00): $(1001)_2 - (1101)_2$.

- Çıkan sayının bire tümleyeni: $1101 \to 0010$.
- Toplam: $1001 + 0010 = 1011$.
- Elde oluşmadı, sonuç negatif. $1011$'in tümleyeni $0100$, yani sonuç $-(0100)_2 = -4$.
- Kontrol: $(1001)_2 = 9$, $(1101)_2 = 13$, $9 - 13 = -4$.

**Pozitif sonuçlu örnek** (ekrandan, 00:50:00, slayttaki a şıkkı): $(10011)_2 - (10000)_2$.

- Çıkan sayının bire tümleyeni: $10000 \to 01111$.
- Toplam: $10011 + 01111 = 1\,00010$. Elde 1 oluştu, sonuç pozitif.
- Elde en sağ basamağa eklenir: $00010 + 1 = 00011 = 3$.
- Kontrol: $19 - 16 = 3$.

**Soru:** Bir öğrenci sonucu kontrol ederken neden 15 ve 4 değerlerinin beklendiğini sordu; hata nerede? **Cevap:** Bakılan sayı yanlıştı; çıkan sayı $(10000)_2 = 16$'dır. $19 - 16 = 3$ olduğundan sonuç doğrudur.

### 3.4 İkiye tümleyen aritmetiği ile çıkarma

Hoca, bugün işlemcilerin yaptığı işlemin ikiye tümleyen aritmetiği olduğunu söyledi. İkiye tümleyen, bire tümleyene 1 eklenerek bulunur. Yöntem:

1. Çıkan sayının ikiye tümleyeni alınır (bitler ters çevrilip 1 eklenir).
2. Çıkılan sayıyla toplanır.
3. Elde oluşursa sonuç pozitiftir; elde atılır ve sonuç doğrudan okunur. Bire tümleyendeki "eldeyi sona ekleme" adımı burada yoktur, çünkü 1 daha önceden eklenmiştir.
4. Elde oluşmazsa sonuç negatiftir; büyüklüğü, bulunan sonucun ikiye tümleyeni alınarak bulunur.

### 3.5 Onluk tabanda tümleyen

Tümleme aslında sayıyı, o basamak genişliğinde alınabilecek en büyük değerden çıkarmaktır. İkili sayıda bitlerin tersini almak, her biti 1'den çıkarmakla aynıdır. Onluk sayılarda da tümleyen, alınabilecek en büyük değerden sayının çıkarılmasıyla bulunur. Tümleyen toplandığında basamak sayısı artarsa (taşma olursa) sonuç pozitiftir; taşma olmazsa sonuç negatiftir ve bulunan değerin yeniden tümleyeni alınır.

<!-- BELİRSİZ: Onluk tümleyen örneğindeki sayılar (altyazıda "2164" ve "33.642" geçiyor) karede görülmedi. -->

**Soru:** Bilgisayar onluk tabanda tümleyen mi kullanır? **Cevap:** Bilgisayar onluk tabanda çalışmaz. Onluk olarak girilen bir sayı arka planda ikili tutulur; örneğin $-6$ girildiğinde bu, 6'nın ikili karşılığının ikiye tümleyeni olarak saklanır.

## 4. Bilgisayarda Sayıların Gösterimi

Tamsayılar bilgisayarda iki biçimde gösterilir (ekrandan, 00:55:00):

- İşaretsiz sayılar: negatif değer yoktur. Hoca bunun artık pek kullanılmadığını söyledi.
- İşaretli sayılar:
  - İşaret biti ile.
  - Tümleyen aritmetiği ile.

### 4.1 İşaret biti ile gösterim

En soldaki bit işareti gösterir: 1 negatif, 0 pozitif demektir; kalan bitler sayının büyüklüğüdür. Hocanın ekrana yazdığı örnek: $10110 = -6$, $00110 = +6$. Slayttaki örnek: $-5_{10} = 10101_2$, $5 = 00101_2$.

Bu yöntem eski bilgisayarlarda kullanılırdı, bugün kullanılmaz. İki sakıncası vardır:

- Bit genişliğinin en anlamlı biti işarete ayrıldığından 8 bitlik bir sistemde büyüklük için 7 bit, 16 bitlik bir sistemde 15 bit kalır.
- Sıfırın iki gösterimi oluşur: $10000 = -0$ ve $00000 = +0$.

### 4.2 Tümleyen aritmetiği ile gösterim

Negatif sayı, pozitif karşılığının ikiye tümleyeniyle yazılır; ayrı bir işaret biti kullanılmaz. Slayttaki örnek:

$$5_{10} = 0101_2 \xrightarrow{\text{1'e tümleme}} 1010_2 \xrightarrow{\text{2'ye tümleme}} 1011_2 \Rightarrow -5_{10} = 1011_2$$

Bilgisayarlarda sayılar genelde bu biçimde tutulur. Hoca dikkat çekti: aynı $1011$ dizisi işaret biti kullanan bir sistemde $-3$ anlamına gelirdi. Bu yüzden bir soruda hangi gösterimin kullanıldığına dikkat etmek gerekir.

## 5. Kodlama

Slayttaki tanım (ekrandan, 01:00:00): kodlama, bilginin veya verinin sayısal olarak gösterilmesi için kullanılan yöntemdir; sonlu elemanlı bir kümenin her elemanına birer kod verilmesidir. Slayttaki blok şemada kullanıcı sayısal sistemle etkileşir; girilen onluk değer (örnekte 2549) bir **kodlayıcıda** (BCD-ikili) koda çevrilir, **işlemciye (CPU)** gider, işlemcinin çıktısı **kod çözücüden (decoder)** geçerek **ekrana (display)** ulaşır. Kod çözücü devreler ileride işlenecektir.

### 5.1 Doğrudan kodlama ve ASCII

Doğrudan kodlamada sayı, ikili karşılığıyla yazılır; örneğin 4 bitlik bir sistemde $12 \to 1100$. ASCII ise tablo tabanlı bir kodlamadır: klavyeden "A" harfi girildiğinde ASCII tablosuna bakılarak onluk karşılığı 65 olan değer ve onun ikili karşılığı saklanır. Bu da aslında bir doğrudan kodlamadır, ama harfin karşılığı olan 65 sayısının doğrudan kodlamasıdır.

### 5.2 BCD kodu

BCD (ikili kodlanmış onluk), onluk sayının her basamağını ayrı ayrı 4 bitlik ikili karşılığıyla yazar. 24 sayısı doğrudan kodlamada $11000$ ($16 + 8$) olarak yazılırken BCD'de $0010\;0100$ olur. İki basamaklı bir sayıda en büyük değer 99'dur ve $1001\;1001$ diye yazılır. 25 de doğrudan ikili karşılığıyla değil, 2 ve 5'in ayrı 4 bitlik karşılıklarıyla (toplam 8 bit) tutulur.

### 5.3 Üç fazlalık kodu

Her rakamın ikili karşılığı değil, 3 fazlasının ikili karşılığı yazılır. Slayttaki tanım: ikili sistemin üç fazlası alınarak oluşturulan, ağırlığı olmayan simetrik bir koddur (ekrandan, 01:05:00).

| Sayı | 3-Fazlalık Kodu |
|---|---|
| 0 | 0011 |
| 1 | 0100 |
| 2 | 0101 |
| 3 | 0110 |
| 4 | 0111 |
| 5 | 1000 |
| 6 | 1001 |
| 7 | 1010 |
| 8 | 1011 |
| 9 | 1100 |

Hoca bunu veri gönderme örneğiyle anlattı: bir kelime harf harf karşı tarafa gönderilecek. Harflerden birinin değeri örnek olarak 12 kabul edilirse ($1100$), üç fazlalık koduyla bu harf $1111$ (15) olarak gönderilir. Karşı taraf verinin üç fazlalık koduyla gönderildiğini biliyorsa çözebilir; bilmiyorsa çözemez. Bu tür kodlamalar, veriyi bir noktadan diğerine farklı formatta göndermek için kullanılır.

### 5.4 Aiken kodu

Aiken kodunda 0'dan 4'e kadar olan rakamlar düz ikili kodla yazılır. 5 ve üstü ise alttaki rakamların bire tümleyenidir: 5, 4'ün; 6, 3'ün; 7, 2'nin; 8, 1'in; 9 da 0'ın bire tümleyenidir.

Hocanın 18 örneği:

- BCD: $0001\;1000$.
- Aiken: 1 düz yazılır ($0001$), 8 ise 1'in tümleyenidir ($1110$): $0001\;1110$.

> **Ders sonrası not:** Hoca 18'in üç fazlalık kodunu verirken $18 + 3 = 21$'in ikili karşılığını ($10101$) yazdı. Üç fazlalık kodu BCD gibi basamak basamak uygulanır; 18'in üç fazlalık kodu büyük olasılıkla $0100\;1011$ (1+3=4, 8+3=11) olmalıdır.

### 5.5 Bitişik kodlar ve Gray kodu

İki kod sözcüğü arasında farklı olan bit sayısına **Hamming uzaklığı** denir. $00 \to 01$ geçişinde tek bit değiştiği için uzaklık 1'dir; $00 \to 11$ geçişinde iki bit değiştiği için uzaklık 2'dir. Hocanın sorduğu örnekte $1101$ ile $0011$ arasında üç bit farklı olduğundan Hamming uzaklığı 3'tür; bu iki sözcük bitişik kodda art arda gelemez.

Slayttaki tanım (ekrandan, 01:10:00): birbirini izleyen sayılara karşılık alınan ikili kod sözcükleri arasındaki Hamming uzaklığı 1 ise bu kodlara **bitişik kodlar** denir. Ayrıca ilk ve son kod sözcüğü arasındaki uzaklık da 1 ise **çevrimli bitişik kod** adını alır. Örneğin 0'dan 3'e kadar sayılar $00, 01, 11, 10$ sözcükleriyle kodlanırsa bitişik kodlama yapılmış olur.

Slayttaki kod tablosu (ABCD), bir 4x4 tablonun içinde ok yönünde dolaşılarak elde edilmiştir:

| Sayı | Kod Sözcüğü (ABCD) |
|---|---|
| 0 | 0000 |
| 1 | 0001 |
| 2 | 0011 |
| 3 | 0010 |
| 4 | 0110 |
| 5 | 1110 |
| 6 | 1010 |
| 7 | 1000 |
| 8 | 1100 |
| 9 | 0100 |

Tablonun satır (AB) ve sütun (CD) etiketleri $00, 01, 11, 10$ sırasıyla yazılmıştır. Hoca, Gray kodunu en çok ileride Karnaugh haritalarının satır ve sütun etiketlerini oluştururken kullanacağımızı vurguladı.

> **Ek bilgi (derste anlatılmadı):** Standart (yansıtılmış) Gray kodunda $n$ sayısının kodu $n \oplus (n \gg 1)$ ile bulunur ve 0-9 için $0000, 0001, 0011, 0010, 0110, 0111, 0101, 0100, 1100, 1101$ dizisini verir. Slayttaki tablo ise 9'dan 0'a dönüşte de uzaklığı 1 olan çevrimli bir bitişik koddur; ilk beş satırdan sonra standart Gray kodundan ayrılır.

Hoca, gönderici ve alıcı arasındaki anlaşmaya bağlı başka kodlamaların da (örneğin Sezar şifrelemesi) bulunduğunu ve bunların lojik devrelerle gerçeklenebileceğini belirtti.

## 6. Temel Lojik İşlemler ve Kapılar

Lojikte 1 "var", 0 "yok" demektir; yani bir bitlik veri söz konusudur. Lojik devre tasarımında amaç, problemi bir $F$ fonksiyonuyla ifade etmek ve bu fonksiyonu devre haline getirmektir. $F$ fonksiyonu Boole cebriyle elde edilir. Boole cebrinde üç temel işlem vardır: **VE**, **VEYA** ve **tümleme**. Bütün problemler bu üç işlem bazında çözülür; diğer kapılar bunlardan türetilir.

Her işlem dört biçimde gösterilir:

- **Doğruluk tablosu:** bütün giriş kombinasyonlarında $F$'nin aldığı değeri verir. Sözel bir problem bu tabloya dökülerek test edilir. Girişler yazılırken LSB her satırda, bir sonraki bit iki satırda bir, sonraki dört satırda bir değişir; böylece bütün kombinasyonlar denenmiş olur.
- **Anahtar devresi:** elektriksel bir canlandırmadır; gerilim kaynağı, anahtarlar ve bir lamba ile işlemin davranışı gösterilir.
- **Lojik devre gösterimi:** kapının şematik sembolü.
- **Zamanlama diyagramı:** her zaman aralığında girişlerin ve çıkışın değerini gösterir.

### 6.1 VE işlemi (AND)

Birbirine VE ile bağlı iki önermeden oluşan birleşik önermenin doğru olması, iki önermenin de doğru olmasına bağlıdır: "A olmadan B olmuyor, B olmadan A olmuyor". Boole cebrinde çarpma ile gösterilir: $F = A \cdot B$ (ekrandan, 01:15:00).

| A | B | F = A·B |
|---|---|---|
| 0 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

Anahtar devresinde A ve B anahtarları lambayla **seri** bağlıdır; lamba yalnız iki anahtar da kapalıyken yanar. Zamanlama diyagramında $F$ yalnız A ve B'nin birlikte 1 olduğu aralıklarda 1'dir.

### 6.2 VEYA işlemi (OR)

Önermelerden en az biri doğruysa birleşik önerme doğrudur. Boole cebrinde toplama ile gösterilir: $F = A + B$. Anahtar devresinde A ve B anahtarları **paralel** bağlıdır; biri kapalıysa lamba yanar. Zamanlama diyagramında girişlerden herhangi birinin 1 olduğu bütün aralıklarda $F = 1$'dir.

| A | B | F = A+B |
|---|---|---|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 1 |

### 6.3 Tümleme işlemi (NOT)

Tek girişlidir: girişte 0 varsa çıkışta 1, girişte 1 varsa çıkışta 0 vardır. Gösterimler (ekrandan, 01:20:00): $\bar A$, $A'$; bazı bilgisayar ortamlarında $!A$ ya da $/A$.

| A | F = Ā |
|---|---|
| 0 | 1 |
| 1 | 0 |

**Soru (anahtar devresi):** Tümleme işleminin anahtar devresi nasıl olur? **Cevap:** Bir öğrenci şu fikri önerdi ve ekrana çizdi: lambaya giden yolun yanında lambayı kısa devre eden ayrı bir kablo olsun ve anahtar bu kablonun üzerinde bulunsun. Anahtar açıkken (A = 0) akım lambadan geçer ve lamba yanar; anahtar kapatılınca (A = 1) akım kısa devre yolundan geçer ve lamba söner. Hoca bu mantığı doğru buldu.

### 6.4 Tümleyen VE işlemi (NAND)

Hoca, gerçek donanımda genellikle AND ve OR yerine NAND ve NOR kapılarının kullanıldığını söyledi. İki nedeni vardır: bu kapılar daha hızlıdır ve tek bir NAND ya da tek bir NOR türüyle hem VE hem VEYA işlemi kurulabilir, böylece birden fazla farklı entegre kullanmak gerekmez (bu konu ilerideki haftalarda açıklanacaktır).

NAND, AND'in doğruluk tablosunun tümlenmiş halidir: iki giriş de 1 iken çıkış 0, diğer durumlarda 1'dir. $F = \overline{A \cdot B}$.

| A | B | F = (A·B)' |
|---|---|---|
| 0 | 0 | 1 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

### 6.5 Tümleyen VEYA işlemi (NOR)

Birbirine VEYA DEĞİL ile bağlı iki önermeden oluşan birleşik önermenin doğru olması, iki önermenin de yanlış olmasına bağlıdır (ekrandan, 01:25:00). $F = \overline{A + B}$.

| A | B | F = (A+B)' |
|---|---|---|
| 0 | 0 | 1 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 0 |

### 6.6 NAND ve NOR için anahtar devreleri (sınıf tartışması)

NOT devresindeki kısa devre fikri bu iki kapıya genişletildi. Tartışmada önce iki anahtarın lambayı kısa devre eden **ayrı (paralel) yollara** konduğu bir devre NAND için önerildi. Bu devrede tek bir anahtara basmak bile lambayı söndürür, lamba yalnız iki anahtar da açıkken yanar; bu davranış NOR'a uyar. Ardından NOR için iki anahtarın **aynı kısa devre yolu üzerinde (seri)** olduğu devre önerildi; bu devrede lamba yalnız iki anahtar birden kapatılınca söner, bu da NAND davranışıdır. Bir öğrenci iki devrenin yer değiştirdiğini fark etti ve hoca bunu onayladı ("demin ters yapmışız").

Doğru eşleşme şöyledir:

- **NAND:** A ve B anahtarları lambayı kısa devre eden **tek bir yol üzerinde seri** bağlıdır. İkisi birden kapalıyken lamba söner; tek biri kapalıyken ya da ikisi açıkken lamba yanar.
- **NOR:** A ve B anahtarları lambayı kısa devre eden **iki ayrı paralel yol** üzerindedir. Herhangi biri kapalıyken lamba söner; yalnız ikisi de açıkken yanar.

### 6.7 Özel VEYA (XOR) ve Özel VEYA DEĞİL (XNOR)

XOR iki girişlidir: girişler birbirinden farklıysa çıkış 1, aynıysa 0'dır (ekrandan, 01:30:00).

| A | B | F = A⊕B |
|---|---|---|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

$$F = A \oplus B = \bar A B + A \bar B$$

Formül, $F$'nin 1 olduğu satırlardan okunur: $A = 0, B = 1$ satırı $\bar A B$ terimini, $A = 1, B = 0$ satırı $A\bar B$ terimini verir; aradaki $+$ (VEYA), ikisinden birinin olmasının yeterli olduğunu gösterir.

**XOR ile kontrollü tümleme.** Hoca XOR'un özel bir kullanımını ekranda çizerek anlattı: XOR'un bir girişine akan bir veri dizisi (örneğin $1010$), diğer girişine bir kontrol birimi (CU) bağlanır.

- Kontrol biti 0 ise: $1 \oplus 0 = 1$, $0 \oplus 0 = 0$, ... çıkış verinin aynısıdır.
- Kontrol biti 1 ise: $1 \oplus 1 = 0$, $0 \oplus 1 = 1$, ... çıkış verinin bire tümleyenidir.

Yani XOR, bir sayının tümleyenini "al ya da alma" komutunu gerçekler. Bu kullanım ileride toplayıcı-çıkarıcı devrelerde karşımıza çıkacaktır. XOR'un anahtar devresi için çapraz (iki konumlu) anahtarlar gerekir; hoca bunun ayrıntısına girmedi.

XNOR, XOR'un tümleyenidir: girişler aynıysa 1, farklıysa 0 üretir. $F = \overline{A \oplus B} = A B + \bar A \bar B$; iki girişin birlikte 1 ya da birlikte 0 olduğu durumlarda $F = 1$'dir.

| A | B | F = (A⊕B)' |
|---|---|---|
| 0 | 0 | 1 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

### 6.8 Zamanlama diyagramından kapıyı bulma

Dersin sonunda ekranda üç zamanlama diyagramı gösterildi ve hangi kapılara ait oldukları soruldu (ekrandan, 01:35:00). Çözümler aşağıdaki Örnek Sorular bölümündedir.

## 7. Boole Cebri

Boole cebri, kapıları matematiksel fonksiyonlarla birleştirip genel bir lojik devre tasarımını formülleştirdiğimiz matematiktir. Gerçek tasarımlarda tek bir kapı değil, örneğin beş kapı kullanılır ve hepsi birlikte tek bir $F$ fonksiyonu verir; bu fonksiyon Boole cebriyle bulunur.

### 7.1 Venn diyagramı sezgisi

Boole cebrinin kavramları Venn diyagramlarından gelir:

- Kesişim çarpmaya (VE) karşılık gelir. $A$ ile $\bar A$'nın kesişimi boştur: $A \cdot \bar A = 0$.
- $A$ ile $\bar A$'nın birleşimi bütün evreni kaplar: $A + \bar A = 1$.
- Evren 1 kabul edildiğinden $1 + A = 1$ ve $1 \cdot A = A$.
- 0 hiçbir yer olmayan kümedir: $0 + A = A$, $0 \cdot A = 0$.

### 7.2 Aksiyomlar ve teoremler

Boole cebri aksiyomlar ve teoremlerden oluşur. Aksiyomlar ispat gerektirmeyen, kabul edilmiş kurallardır; örneğin $1 \cdot 1 = 1$ (iki önerme de doğruysa VE ile bağlı önerme doğrudur), $0 + 0 = 0$ (VEYA ile bağlı iki önermenin ikisi de yanlışsa sonuç yanlıştır). Teoremler ise ispatlanabilen önermelerdir.

<!-- BELİRSİZ: Aksiyom slaytı karede görülmedi; örnekler altyazıdan alındı. -->

Boole cebri, karmaşık bir devrenin $F$ fonksiyonunu en sade matematiksel biçime getirmek için kullanılır. Sadeleştirmenin ilk yöntemi Boole cebridir; ileride Karnaugh haritaları gibi yöntemler de görülecektir.

Teoremler (ekrandan, 01:40:00 ve 01:45:00):

| No | a | b | Ad |
|---|---|---|---|
| 1 | $a+b=b+a$ | $a\cdot b=b\cdot a$ | Değişme özelliği |
| 2 | $a+b+c=(a+b)+c=a+(b+c)$ | $a\cdot b\cdot c=(a\cdot b)\cdot c=a\cdot(b\cdot c)$ | Birleşme özelliği |
| 3 | $a+b\cdot c=(a+b)\cdot(a+c)$ | $a\cdot(b+c)=(a\cdot b)+(a\cdot c)$ | Dağılma özelliği |
| 4 | $a+a=a$ | $a\cdot a=a$ | Değişkende fazlalık özelliği |
| 5 | $a+a\cdot b=a$ | $a\cdot(a+b)=a$ | Yutma özelliği |
| 6 | $\overline{(a)}=\bar a$ | $\overline{(\bar a)}=a$ | İşlemde fazlalık özelliği |
| 7 | $\overline{a+b+c+\cdots}=\bar a\cdot\bar b\cdot\bar c\cdots$ | $\overline{a\cdot b\cdot c\cdots}=\bar a+\bar b+\bar c+\cdots$ | De Morgan kuralı |
| 8 | $a+\bar a=1$ | $a\cdot\bar a=0$ | Sabit özelliği |
| 9 | $0+a=a$ | $1\cdot a=a$ | Etkisizlik özelliği |
| 10 | $1+a=1$ | $0\cdot a=0$ | Yutan sabit özelliği |
| 11 | $(a+\bar b)\cdot b=a\cdot b$ | $a\cdot\bar b+b=a+b$ | |
| 12 | $(a+b)(\bar a+c)(b+c)=(a+b)(\bar a+c)$ | $ab+\bar a c+bc=ab+\bar a c$ | |
| 13 | $(a+b)(\bar a+c)=ac+\bar a b$ | $ab+\bar a c=(a+c)(\bar a+b)$ | |

Hoca, VE işleminin dağılma özelliğinin sıradan çarpmadaki dağılmayla aynı olduğunu, VEYA işleminin dağılmasının ($a + bc = (a+b)(a+c)$) ise normal matematikte bulunmayan bir özellik olduğunu belirtti.

### 7.3 Yutma özelliğinin gösterilmesi

$a + a b = a$ ifadesi ortak paranteze alınarak gösterilir:

$$a + ab = a(1 + b) = a \cdot 1 = a$$

çünkü $1 + b = 1$'dir. Çarpım biçimi de dağıtılarak gösterilir:

$$a(a + b) = a a + a b = a + ab = a(1 + b) = a$$

Hoca ayrıca $a + ab$ ifadesinin VEYA'nın dağılma özelliğiyle $(a + a)(a + b) = a(a + b)$ biçimine de açılabileceğini gösterdi.

### 7.4 De Morgan kuralı

Hoca De Morgan'ı en çok kullanılacak, belki de en önemli kural olarak tanıttı. Çok yapılan bir hataya dikkat çekti (ekrandan, 01:45:00):

$$\overline{a + b} \neq \bar a + \bar b$$

Üst çizgi parantezin içine dağıtılırken aradaki işlem de değişir:

$$\overline{a + b} = \bar a \cdot \bar b \qquad \overline{a \cdot b} = \bar a + \bar b$$

> **Hocanın vurgusu:** De Morgan uygulanırken üst çizgi içeri dağıtılır ve işaret değişir; VE, VEYA olur, VEYA, VE olur. Bu kural çok kullanılacaktır.

### 7.5 Teorem 11'in gösterilmesi

$(a + \bar b) \cdot b$ çarpılırsa $ab + b\bar b$ elde edilir. Bir değişkenin kendi tümleyeniyle çarpımı 0 olduğundan ($b \bar b = 0$) sonuç $ab$'dir.

$a\bar b + b$ ifadesi VEYA'nın dağılma özelliğiyle açılır:

$$a\bar b + b = (a + b)(\bar b + b) = (a + b)\cdot 1 = a + b$$

Hoca, $\bar b + b$ teriminin her durumda 1 olduğunu şöyle açıkladı: $b = 1$ ise $\bar b = 0$, $b = 0$ ise $\bar b = 1$'dir; iki durumda da toplam 1'dir.

### 7.6 Boole cebriyle sadeleştirme örneği

Slaytta A, B, C girişli bir $F$ fonksiyonu verilmiş ve önce $\bar F$'nin bulunması, sonra sadeleştirilmesi istenmişti. Çözüm adımları şöyle anlatıldı:

1. $F$'nin tamamının üzerine bir tümleme çizgisi çekilir.
2. De Morgan uygulanır: üstteki genel çizgi içeri dağıtılırken VE işlemleri VEYA'ya, VEYA işlemleri VE'ye döner.
3. Üst üste gelen iki tümleme birbirini götürür (çift tümleme kuralı).
4. Parantez içlerine yeniden De Morgan uygulanır; çift tümlenen değişkenler kendisine döner.
5. Son olarak dışarıdaki değişken parantezin içine dağıtılarak $\bar F$'nin sade biçimi elde edilir.

<!-- BELİRSİZ: Bu örneğin F fonksiyonu ve sonucu karede görülmedi; altyazıda yalnız A'nın tümleyeni, B ve "A + C'nin tümleyeni" terimleri geçiyor. Aynı slayttaki F1 ve F2'nin tersini bulma alıştırması da karede görülmedi. -->

### 7.7 Dualite ilkesi

Bir Boole ifadesinin duali, VE ile VEYA işlemlerinin ve 1 ile 0'ın yer değiştirmesiyle bulunur; değişkenler ve tümleyenleri olduğu gibi kalır. Derste verilen örnekte $x \cdot y + 0$ ifadesinin duali $(x + y) \cdot 1$'dir ve bu doğrudan $x + y$'ye eşittir.

<!-- BELİRSİZ: Dualite örneğinin slaytı karede görülmedi; örnek altyazıdaki anlatımdan kuruldu. -->

## Örnek Sorular

**Soru 1** (derste sözlü, 00:21:03): 0 ile 15 V arasında sürekli değer alan bir işaret 100 mV duyarlılıkla kodlanacaktır. Kaç bitlik ADC gerekir?

> **Çözüm:** Basamak sayısı $15\,000 / 100 = 150$. $2^7 = 128 < 150 \le 2^8 = 256$ olduğundan 8 bit gerekir.

**Soru 2** (derste sözlü, 00:22:17): 4 bitlik bir DAC'de $0000$ 0 V'u, $1111$ 6 V'u gösteriyor. Bir adım kaç volttur?

> **Çözüm:** Derste $a = 6/2^4 = 0{,}375$ V bulundu. (Ders sonrası not: $1111$'in tam 6 V olması için adım büyük olasılıkla $6/15 = 0{,}4$ V alınmalıdır.)

**Soru 3** (ekrandan, 00:30:00): $(33)_{10} = (\,?\,)_2$ ve $(172)_{10} = (\,?\,)_2$.

> **Çözüm:** 2'ye art arda bölmeyle $(33)_{10} = (100001)_2$ ve $(172)_{10} = (10101100)_2$.

**Soru 4** (ekrandan, 00:40:00): $(1357)_{10} = (\,?\,)_{16}$ ve $(25{,}125)_{10} = (\,?\,)_{16}$.

> **Çözüm:** $(1357)_{10} = (54D)_{16}$; $(25{,}125)_{10} = (19{,}2)_{16}$.

**Soru 5** (ekrandan, 00:45:00): Onluk yöntemle $(100)_2 - (011)_2$ ve $(1010)_2 - (0011)_2$ işlemlerini yapın.

> **Çözüm (derste verilmedi):** $(100)_2 - (011)_2 = (001)_2$ ($4 - 3 = 1$); $(1010)_2 - (0011)_2 = (0111)_2$ ($10 - 3 = 7$).

**Soru 6** (ekrandan, 00:50:00): Bire tümleyen aritmetiğiyle a) $(10011)_2 - (10000)_2$, b) $(011011)_2 - (100111)_2$, c) $(10001)_2 - (111)_2$.

> **Çözüm (a, derste verildi):** $10011 + 01111 = 1\,00010$; elde 1, sonuç pozitif; $00010 + 1 = (00011)_2 = 3$.

> **Çözüm (b ve c, derste verilmedi):** b) $100111$'in bire tümleyeni $011000$; $011011 + 011000 = 110011$, elde yok, sonuç negatif; $110011$'in tümleyeni $001100$, sonuç $-(001100)_2 = -12$ ($27 - 39 = -12$). c) $00111$'in bire tümleyeni $11000$; $10001 + 11000 = 1\,01001$, elde 1, sonuç pozitif; $01001 + 1 = (01010)_2 = 10$ ($17 - 7 = 10$). Python ile doğrulandı.

**Soru 7** (ekrandan, 01:10:00): $1101$ ile $0011$ kod sözcükleri arasındaki Hamming uzaklığı nedir?

> **Çözüm:** Üç bit farklıdır, Hamming uzaklığı 3'tür. Bu iki sözcük bitişik kodda art arda gelemez.

**Soru 8** (derste sözlü, 01:19:18): Tümleme (NOT) işleminin anahtar devresi nasıl kurulur? Aynı soru NAND ve NOR için de soruldu.

> **Çözüm:** NOT: anahtar, lambayı kısa devre eden bir yolun üzerine konur; anahtar kapanınca lamba söner. NAND: iki anahtar aynı kısa devre yolunda seri. NOR: iki anahtar ayrı paralel kısa devre yollarında (bkz. 6.6).

**Soru 9** (ekrandan, 01:35:00): Aşağıdaki zamanlama diyagramları hangi kapılara aittir?

Diyagram 1 ($t_0$-$t_6$ aralıkları):

| Aralık | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|---|---|---|---|---|---|---|---|
| A | 0 | 1 | 1 | 0 | 1 | 0 | 1 |
| B | 0 | 1 | 1 | 0 | 0 | 0 | 1 |
| Q | 1 | 1 | 1 | 1 | 0 | 1 | 1 |

Diyagram 2:

| Aralık | 1 | 2 | 3 | 4 | 5 | 6 |
|---|---|---|---|---|---|---|
| A | 1 | 0 | 1 | 0 | 1 | 0 |
| B | 1 | 1 | 1 | 0 | 0 | 0 |
| Q | 1 | 0 | 1 | 0 | 0 | 0 |

Diyagram 3:

| Aralık | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|---|---|---|---|---|---|---|---|
| A | 0 | 1 | 1 | 0 | 1 | 0 | 1 |
| B | 0 | 1 | 1 | 0 | 0 | 0 | 1 |
| Q | 1 | 0 | 0 | 1 | 0 | 1 | 0 |

> **Çözüm:** Derste önce bir öğrenci birinci diyagram için XOR dedi; hoca XOR'un farklı girişlerde 1 ürettiğini ($A\bar B + \bar A B$), oysa bu diyagramda girişler aynıyken 1, farklıyken 0 çıktığını gösterdi. Diyagram 1: **XNOR**. Diyagram 2: çıkış yalnız iki giriş de 1 iken 1, **AND**. Diyagram 3 için önce NAND önerildi; ancak $A = 1, B = 0$ iken NAND 1 üretmesi gerekirken çıkış 0'dır. Çıkış yalnız iki giriş de 0 iken 1 olduğundan kapı **NOR**'dur.

**Soru 10** (derste sözlü, 01:42:12): $a + ab = a$ ve $a(a + b) = a$ eşitliklerini gösterin.

> **Çözüm:** $a + ab = a(1 + b) = a$; $a(a + b) = a + ab = a(1 + b) = a$ (bkz. 7.3).

**Soru 11** (ekrandan, 01:45:00): $a \bar b + b = a + b$ eşitliğini gösterin.

> **Çözüm:** $a\bar b + b = (a + b)(\bar b + b) = (a + b)\cdot 1 = a + b$.

## Dersin Toparlaması

Bu derste önce analog işaretin örneklenerek sayısallaştırılması ve çözünürlüğün bit sayısıyla ilişkisi ($a = V_{maks}/2^n$) ADC ve DAC örnekleriyle işlendi. Ardından onluk, ikili, sekizli ve onaltılı sayı sistemleri arasındaki dönüşümler, farklı tabanlarda toplama ve bilgisayarda çıkarmanın nasıl tümleyen alıp toplama ile yapıldığı (bire ve ikiye tümleyen) anlatıldı. İşaretli sayıların işaret biti ve tümleyen aritmetiğiyle gösterimi karşılaştırıldı; BCD, üç fazlalık, Aiken ve Gray kodları ile Hamming uzaklığı tanıtıldı.

Dersin ikinci yarısında temel lojik işlemler (AND, OR, NOT) ve türetilmiş kapılar (NAND, NOR, XOR, XNOR) doğruluk tablosu, anahtar devresi, sembol ve zamanlama diyagramıyla incelendi; zamanlama diyagramından kapı bulma alıştırması yapıldı. Son olarak Boole cebrinin aksiyom ve teoremleri, özellikle De Morgan kuralı, ve dualite ilkesi tanıtıldı. Sonraki derste doğruluk tablosundan fonksiyon çıkarma, minterm ve maxterm kavramlarına geçileceği belirtildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
