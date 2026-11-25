# Ders 11 Genişletilmiş Notu: Veri Saklama, Negatif ve Kesirli Sayıların Gösterimi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Giriş: Konumsal sayı sistemlerinden veri saklamaya
- 2. Bit, byte ve bellek adresleri
- 3. Mantık kapıları
- 4. En anlamlı ve en anlamsız bit, sayı dönüşümleri
- 5. Bilginin bit örüntüleriyle temsili
- 6. Analog ve dijital bilgi
- 7. Negatif sayılar: bire ve ikiye göre tümleyen
- 8. Excess gösterimi
- 9. Kesirli sayılar ve kayan nokta gösterimi
- 10. İkilik toplama, taşma ve çıkarma
- 11. Tek ve çift duyarlıklı kayan nokta, kesme hatası
- Örnek Sorular

## 1. Giriş: Konumsal sayı sistemlerinden veri saklamaya

Ders, önceki haftada işlenen sayı sistemlerinin hatırlatılmasıyla başlar. Birler, onlar, yüzler basamağı diye adlandırdığımız onluk sayı sistemi bir konumsal sayı sistemidir (positional number system); aynı mantığın ikilik, sekizlik ve onaltılık karşılıkları vardır. Bu derste bu bilgi üzerine, verinin bilgisayarda nasıl saklandığı inşa edilir.

## 2. Bit, byte ve bellek adresleri

### 2.1 Bit ve byte

Bilginin saklanabildiği en küçük birim bit'tir (binary digit). Bir bit yalnız 0 ya da 1 değerini alır. Sekiz bit bir araya gelince bir byte oluşur. Bellek (memory) kullanılırken adreslenebilen en küçük alan bir byte'lık alandır.

### 2.2 Hücreler ve adresler

Hoca belleği alt alta çizilmiş hücrelerle modelledi: Cell1, Cell2, Cell3, Cell4. Her hücrenin bir değeri (value) ve bir adresi (address) vardır. Örnekte birinci hücrede `00000000`, ikinci hücrede `11111111` yazıyordu (ekrandan, 00:05:00).

Adresler onaltılık sayılarla yazılır ve başlarına `0x` öneki konur:

```text
0x0000, 0x0001, ..., 0x0009, 0x000A, ..., 0x000F, 0x0010
```

Hoca burada "F'den sonra ne gelecek?" diye sordu; cevap `0x0010`'dur. Yani adresler birer byte artarak ilerler ve her adreste 8 bit saklanır.

Adresler her zaman sıfırdan başlamaz. Bellekte başka bir yerde, örneğin `0xABCD` adresinde olunduğu varsayılırsa sonraki adresler şöyledir (ekrandan, 00:05:00):

```text
0xABCD -> 0xABCE -> 0xABCF -> 0xABD0
```

Sayı dönüşümü yaparken tabanı parantezin dışına indis olarak yazarız: $(ABCD)_{16}$. İki yazım da mümkündür, ama dönüşümlerde indisli yazım, bilgisayarda adresleme yaparken `0x` yazımı kullanılır.

### 2.3 Değişken tipine göre kaplanan yer

Değişkenin tipi kapladığı yeri belirler. Karakter değişkeni bir byte yer kaplar. Tamsayı değişkeni mimariye bağlı olarak dört byte (32 bit) kaplayabilir. Saklanan değer 0, 200 ya da 10000 olsun, dört byte'lık yer ayrılır. Bu nedenle ardışık tamsayıların adresleri dörder dörder ilerler: 0'dan 4'e, 4'ten 8'e, 8'den 12'ye, 12'den 16'ya, yani `0x10` adresine.

## 3. Mantık kapıları

### 3.1 Temel kapılar

Verinin teknik olarak saklanmasını ve işlenmesini sağlayan en küçük donanım birimleri mantık kapılarıdır (logic gates). Kapılar bir araya gelerek flip-flop gibi devreleri oluşturur. Voltaj değişikliği bilgisi kullanılarak 0 ve 1 bilgileri bu yapılarda saklanır.

Temel Boole işlemleri AND, OR, XOR ve NOT'tur. Başka kapılar da vardır, ama bunlar temel olanlardır.

- **AND:** İki giriş (x, y), bir çıkış. Girişlerden biri bile 0 ise çıkış 0; ikisi de 1 ise çıkış 1.
- **OR:** İki giriş de 0 ise çıkış 0; diğer bütün durumlarda 1.
- **XOR (exclusive or):** Girişler farklıysa (01 ve 10) çıkış 1. Hocanın karşılaştırması: AND ikisinin de 1 olduğu durumu, OR ikisinin de 0 olduğu durumu ayırt eder; XOR ise ikisinin farklı olduğu duruma odaklanır.
- **NOT:** Tek giriş, tek çıkış. 0 girerse 1, 1 girerse 0 çıkar; girişin değilidir.

| x | y | AND | OR | XOR |
|---|---|-----|----|-----|
| 0 | 0 | 0 | 0 | 0 |
| 0 | 1 | 0 | 1 | 1 |
| 1 | 0 | 0 | 1 | 1 |
| 1 | 1 | 1 | 1 | 0 |

Hoca bu işlemlerin bilgisayar dünyasında çok sık kullanıldığını ve Lojik Devreler dersinde daha fazla kapı görüleceğini belirtti.

### 3.2 Kapıları birleştirmek: küçük bir devre

Kapıları birbirine bağlamak devre üretmek demektir. Örnek devrede x ve y bir AND kapısına girer; AND kapısının çıkışı ile z bir OR kapısına girer ve OR kapısının çıkışı devrenin çıkışıdır (ekrandan, 00:15:00). Yani çıkış $(x \cdot y) + z$'dir.

Bütün giriş kombinasyonları yazılıp her satırda önce AND'in çıkışı ("yukarıdan gelen"), sonra z ("aşağıdan gelen") OR'a verilir:

| x | y | z | AND çıkışı | output |
|---|---|---|------------|--------|
| 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 0 | 1 |
| 0 | 1 | 0 | 0 | 0 |
| 0 | 1 | 1 | 0 | 1 |
| 1 | 0 | 0 | 0 | 0 |
| 1 | 0 | 1 | 0 | 1 |
| 1 | 1 | 0 | 1 | 1 |
| 1 | 1 | 1 | 1 | 1 |

"output" sütunu ekrandan alınmıştır; "AND çıkışı" sütunu hocanın satır satır anlattığı ara değerlerdir. Kapılar farklı biçimlerde bağlanabilir: bir kapının çıkışı başka bir kapının girişi olabilir ya da devre kendini geri besleyebilir. Bu sayede birçok işlemi yapan donanım devreleri üretilir. Ders sonunda bir soru üzerine hoca, bilgisayarların toplama işlemini de mantık kapılarıyla gerçekleştirdiğini, ayrıntısının donanım derslerinde ve Lojik Devreler dersinde görüleceğini söyledi.

## 4. En anlamlı ve en anlamsız bit, sayı dönüşümleri

### 4.1 MSB ve LSB

8 bitlik bir sayı bellekte yer alsın, örneğin `01011100` (ekrandan, 00:15:00). Bu sayının en soldaki ve en sağdaki bitleri kritik bitlerdir.

- En soldaki bit **most significant bit** (en anlamlı bit) ya da **high-order end** diye adlandırılır.
- En sağdaki bit **least significant bit** (en anlamsız bit) ya da **low-order end** diye adlandırılır.

Neden böyle adlandırılır? 8 bitlik sayıda en soldaki bit $2^7$ basamağıdır. Orada 0 yerine 1 yazılırsa sayıya 128 eklenir: 32 yazmak isterken 160 yazılmış olur. En sağdaki bitteki bir hata ise sayıyı yalnız 1 değiştirir.

### 4.2 İşaretsiz sayının onluk değeri

`01011100` işaretsiz tamsayı (unsigned number) olsaydı onluk değeri ne olurdu? Her bit kendi basamak değeriyle ($2^0$'dan $2^7$'ye) çarpılıp toplanır (ekrandan, 00:20:00):

$$
0\cdot 2^7 + 1\cdot 2^6 + 0\cdot 2^5 + 1\cdot 2^4 + 1\cdot 2^3 + 1\cdot 2^2 + 0\cdot 2^1 + 0\cdot 2^0 = 64 + 16 + 8 + 4 = 92
$$

### 4.3 Üç sayının dönüşümü

Hoca üç işaretsiz sayıyı önce onluğa, sonra sekizliğe, sonra onaltılığa çevirtti. Sayılar ilk başta 7 bit yazılmıştı; hoca bunu fark edip hepsine birer 0 ekleyerek 8 bite tamamladı.

> **Hocanın vurgusu:** Özel bir durum yoksa sayılar mutlaka 8 bit ile ifade edilmelidir.

Sonuç tablosu (ekrandan, 00:25:00):

| İkilik | Onluk | Sekizlik | Onaltılık |
|--------|-------|----------|-----------|
| 11100000 | 224 | 340 | E0 |
| 00010000 | 16 | 20 | 10 |
| 10000000 | 128 | 200 | 80 |

**Sekizlik doğrulama (224):** $3 \cdot 8^2 + 4 \cdot 8^1 + 0 \cdot 8^0 = 192 + 32 + 0 = 224$.

**Onaltılık (224):** 224 içinde kaç tane 16 var? $14 \cdot 16 = 160 + 64 = 224$, kalan 0. 14 onaltılıkta E'dir, sonuç `E0`.

**Kısa yol:** Sayı sağdan başlayarak 4 bitlik gruplara ayrılır ve her grubun değeri yazılır. `1110 0000` için ilk grup $8+4+2 = 14$ = E, ikinci grup 0, sonuç `E0`. `0001 0000` için 1 ve 0, sonuç `10`. `1000 0000` için 8 ve 0, sonuç `80`. Bir öğrenci sekizlik için de aynı şeyin yapılabileceğini belirtti; hoca onayladı: sekizlikte 3 bitlik gruplar kullanılır.

### 4.4 Bölme yöntemiyle dönüşüm

Bir sayıyı "bilimsel olarak", kâğıt üstünde ikiliğe çevirmek için sayı art arda 2'ye bölünür (ekrandan, 00:25:00):

```text
16 / 2 = 8   kalan 0
 8 / 2 = 4   kalan 0
 4 / 2 = 2   kalan 0
 2 / 2 = 1   kalan 0
 son bölüm 1
```

Sonuç, en son elde edilen değerden başlanarak geriye doğru yazılır: $(10000)_2$. Aynı yöntem her taban için geçerlidir. 16'yı sekizliğe çevirmek için $16 / 8 = 2$, kalan 0; 2 sekizden küçük olduğu için bölme biter ve sonuç $(20)_8$'dir. Hangi tabana çevrilecekse o tabana bölünür, kalanlar tersten yazılır.

## 5. Bilginin bit örüntüleriyle temsili

### 5.1 Neler temsil edilir

Bütün bit örüntüleri bir bilgiyi ifade eder. Bir bit örüntüsü bir sayıyı, bir karakteri (A harfi, nokta), bir metni, bir görüntüyü, bir videoyu, bir sesi ya da bir program kodunu temsil edebilir (ekrandan, 00:35:00). Bunun için örüntünün neyi temsil ettiğinin tanımlanması gerekir.

### 5.2 Karakterler ve ASCII

Karakterler de 0 ve 1'lerle saklanır; hangi örüntünün hangi karaktere karşılık geldiği bir dönüştürücü tablo ile anlaşılır. Bunlardan biri ASCII tablosudur: **American Standard Code for Information Interchange**. ASCII, ANSI (**American National Standards Institute**) tarafından belirlenmiş bir standarttır.

Hocanın anlatımına göre bir byte ile 256 farklı simge (0–255) ifade edilir. Tabloda null karakteri, harfler, rakamlar ve noktalama işaretleri vardır; harfler ağırlıklı olarak Batı Avrupa dillerine göredir. Ekrandaki örnek değerler (ekrandan, 00:35:00):

| Değer | Karakter |
|-------|----------|
| 48 | `'0'` (rakamlar `'9'`'a kadar sürer) |
| 49 | `'1'` |
| 65 | `'A'` (büyük harfler `'Z'`'ye kadar sürer) |
| 97 | `'a'` (küçük harfler `'z'`'ye kadar sürer) |

Yani 65 değeri karakter olarak yorumlanıyor ve ASCII kullanılıyorsa büyük A harfini temsil eder; 97 küçük a'yı temsil eder. Tabloda nokta, virgül, boşluk gibi karakterler ve basılı olarak görünmeyen bazı karakterler de vardır.

Kore dili, Rusça, Çince, Japonca gibi diller için bir byte yetmez. Derste bunun için UTF-8 (**Unicode Transformation Format 8-bit**) kullanıldığı, 2 byte (16 bit) ile $2^{16} = 65536$ farklı simgenin saklanabildiği anlatıldı.

> **Ders sonrası not:** Hoca ASCII'yi 8 bitlik (0–255) ve UTF-8'i 2 byte'lık bir kodlama olarak anlattı. Standart ASCII 7 bitliktir (0–127); 128–255 aralığı kod sayfasına göre değişen "genişletilmiş ASCII" tablolarına aittir. UTF-8 ise karakter başına 1 ile 4 byte kullanan değişken uzunluklu bir kodlamadır; ASCII karakterlerini tek byte'ta, aynı değerlerle saklar. 2 byte'ta $2^{16}$ simge düşüncesi UTF-16/UCS-2 yapısına daha yakındır.

### 5.3 Karakter sabitleri

> **Hocanın vurgusu:** ASCII tablosundaki hiçbir değer ezbere kullanılmamalıdır. Karakterlerle çalışırken mutlaka karakter sabitleri kullanılmalıdır.

Karakter sabiti tek tırnakla yazılır: `'A'`, `'b'`, boşluk, nokta. Tek tırnak arasındaki karakterin değeri otomatik olarak kullanılır. `'A'` yerine 65 yazmak çalışır, ama başka bir kodlamaya geçildiğinde o kodlamanın değerlerini de ezberlemek gerekir; bu doğru bir yöntem değildir. Tek tırnak içinde yalnız bir karakter bulunabilir. Birden fazla karakter için çift tırnak kullanılır (ör. `"ab"`). Karakter dizileri (string) ilerleyen haftalarda ayrıca ele alınacaktır.

### 5.4 Görüntü ve video

Bir görüntü bir matristir; matrisin her gözü bir pikseli (picture element) temsil eder (ekrandan, 00:35:00). Full HD görüntü 1920 × 1080 çözünürlüklüdür, yani 1920 × 1080'lik bir matristir ve her gözde bir ya da birden fazla renk değeri saklanır.

Video birden fazla görüntüden (kare, frame) oluşur. Saniyedeki kare sayısı günümüzde 30 fps'den 120, hatta 240 fps'ye kadar çıkabilir; 30 fps'nin altında çekim yapan cihazlar da vardır (ekrandan, 00:45:00). Kare sayısı, çözünürlük ve renk derinliği arttıkça içerik çok daha fazla yer kaplar.

## 6. Analog ve dijital bilgi

### 6.1 Örnekleme

Analog bilgi süreklilik arz eder. Dijital bilgi ise analog bilgiden belirli bir örnekleme sıklığıyla alınan örneklerle oluşturulur. Bir sinyalden yalnız dört noktada değer alınırsa sinyal modellenemez. Ne kadar çok örnek alınırsa sinyalin sürekliliği o kadar iyi yakalanır; sinyal sonsuz sayıda parçaya bölünseydi analog verinin kendisine ulaşılırdı (ekrandan, 00:45:00).

Görüntü için de aynı şey geçerlidir: günlük hayattaki bir görüntü ne kadar çok pikselle ifade edilirse dijital hali o kadar gerçekçi ve ayrıntılı olur. Eskiden yeterli görülen standart çözünürlük bugün yetmez; 4K görüntüler analog görüntüye çok yakın keskinliktedir. Ancak göz ve kulak bir noktadan sonraki ayrıntıyı ayırt edemez; 4K ile Full HD arasındaki fark bile cihaza bağlı olarak her zaman fark edilmeyebilir.

Hoca ses için MP3 örneğini verdi: MP3, kulağın duymadığı ya da farkı algılayamadığı sesleri kodlamayarak yer kazanır. Bu yüzden onlarca megabaytlık bir şarkı birkaç megabayta indirilebilir ve dinleyici kalite farkını çoğunlukla fark etmez.

> **Ders sonrası not:** Hoca CD kalitesindeki kaydı "44100 kHz" diye andı; doğrusu 44100 Hz, yani 44,1 kHz örnekleme frekansıdır.

Ses dijitale çevrilirken sesin genliği incelenir; genlikten örnekler alınır ve bu örnekler kodlanarak dijital olarak saklanır.

### 6.2 Kova benzetmesi

Hoca analog ile dijital arasındaki farkı bir kova ile anlattı (ekrandan, 00:45:00). Kovadaki su yüksekliği analog bir bilgi olarak tam olarak görülebilir. Dijital olarak saklanmak istense her kova yalnız "dolu" (1) ya da "boş" (0) olabilir. Birkaç boş ve dolu kovayla o yüksekliği aynı hassasiyette ifade etmek çok zordur; çok fazla kova, yani çok fazla örnek gerekir.

### 6.3 Avantaj ve dezavantajlar

Analog bilgi fiziksel materyaller üzerinde saklanır ve kesinliği yüksektir, ama korunması zordur: kova biraz sallansa bilgi bozulur. Manyetik teyp, kaset ya da sinema film şeritleri fiziksel darbelerden etkilenir.

Dijital veri saklamanın üstünlükleri:

- Veri kolay çoğaltılabilir.
- Fiziksel hatalardan daha az etkilenir.
- Kolay paylaşılabilir.

Dijital gösterim, analog verinin tam değerini kodlamak çok fazla veri gerektirdiği için hassasiyette bir parça geride kalır. Yine de günümüzde kullanılan yüksek çözünürlükler, bir sahneyi gözle görmekle dijital kaydını izlemek arasındaki farkı neredeyse ortadan kaldırmıştır.

## 7. Negatif sayılar: bire ve ikiye göre tümleyen

### 7.1 İşaret biti

Negatif sayıları saklamak için iki gösterim kullanılır: ikiye göre tümleyen gösterimi (two's complement notation) ve excess gösterimi (excess notation) (ekrandan, 00:50:00). Kâğıt üzerinde eksi işaretiyle yazdığımız −5'i bilgisayara eksi işaretiyle anlatamayız. Bunun için bir işaret bitine ihtiyaç vardır: en anlamlı bit olan en soldaki bit. Bu bit 0 ise sayı pozitif, 1 ise negatif kabul edilir.

### 7.2 Bire göre tümleyen

Bire göre tümleyen (one's complement) almak, sıfırları bir, birleri sıfır yapmaktır; yani her bitin değilini almaktır (ekrandan, 00:50:00):

```text
0000 1111  ->  1111 0000
0101 1001  ->  1010 0110
```

### 7.3 İkiye göre tümleyen

İkiye göre tümleyen (two's complement) almak için önce bire göre tümleyen alınır, sonra elde edilen sayıya 1 eklenir (ekrandan, 00:50:00):

```text
  0000 1111          0101 1001
  1111 0000 (1'e)    1010 0110 (1'e)
+         1        +         1
-----------        -----------
  1111 0001          1010 0111
```

**Soru:** Bire göre tümleyenin son basamağı da 1 ise 1 eklerken ne oluyor?
**Cevap:** Normal ikilik toplamadaki gibi elde (carry) sola aktarılır. Örneğin `00111100` için bire göre tümleyen `11000011`'dir; 1 eklenince en sağda $1+1 = 10$, yani 0 yazılır, elde 1 sola geçer; yine $1+1 = 10$, 0 yazılır, elde 1 bir sonraki basamağa konur. Sonuç `11000100`'dür (ara adımlar altyazıdan kuruldu).

### 7.4 İşaretli bir sayının değerini bulmak

İşaretli tamsayı sisteminde (signed number system) verilen bir sayının değeri şöyle bulunur (ekrandan, 00:55:00):

- İlk bit 0 ise sayı pozitiftir, dönüşüme gerek yoktur. `01100000` = 64 + 32 = 96.
- İlk bit 1 ise sayı negatiftir. İkiye göre tümleyeni alınır, ortaya çıkan sayının işaretsiz değeri bulunur ve başına eksi konur.

**Örnek 1: `10000000`.** İlk bit 1, sayı negatif. Bire göre tümleyen `01111111`, 1 eklenince `10000000`. Bunun işaretsiz değeri 128'dir; sonuç −128.

**Örnek 2: `11000001`.** İlk bit 1, sayı negatif. Bire göre tümleyen `00111110`, 1 eklenince `00111111`. İşaretsiz değeri $32 + 16 + 8 + 4 + 2 + 1 = 63$; sonuç −63.

**Soru:** İkiye göre tümleyeni bulmanın sağdan başlayan bir kısa yolu vardı; o neydi?
**Cevap:** Hoca önce şunu gösterdi: `11000001` dizisi işaretsiz olarak $128 + 64 + 1 = 193$'tür (ekrandan, 01:35:00). Bir byte'lık bir sayının negatif olduğu görüldükten sonra 256'dan işaretsiz değeri çıkarılırsa mutlak değer bulunur: $256 - 193 = 63$, yani −63. Bir byte için işaretli değerin mutlak değeri ile işaretsiz değerin toplamı her zaman 256'dır.

Sorudaki asıl kısa yolu hoca aradan sonra anlattı: sağdan başlanarak ilk 1 görülene kadar olan bitler (o 1 dahil) aynen aşağı yazılır; ondan sonraki bitlerin bire göre tümleyeni alınır. Örnek: `0110` için sağdaki `10` aynen kalır, soldaki `01` tersine döner, sonuç `1010`. Sağlaması: `0110` → bire göre `1001` → +1 → `1010` (ekrandan, 01:35:00). İki yöntem aynı sonucu verir; birincisi işin "bilimsel" yolu, ikincisi kısa yoludur. Hoca bu kısa yolu yalnız pratik bir yöntem olarak verdi; çözümlerde asıl yöntemin (bire göre tümleyen + 1) kullanılmasını önerdi.

### 7.5 3 bitlik ikiye göre tümleyen tablosu

| Kod | Değer |
|-----|-------|
| 011 | 3 |
| 010 | 2 |
| 001 | 1 |
| 000 | 0 |
| 111 | −1 |
| 110 | −2 |
| 101 | −3 |
| 100 | −4 |

(ekrandan, 01:35:00)

### 7.6 Aralıklar

Bir byte'lık alanda yalnız pozitif sayı saklanırsa (unsigned) 0 ile 255 arası saklanabilir. İşaretli tamsayı saklanırsa −128 ile 127 arası saklanabilir, çünkü bir bit işaret için kullanılır (ekrandan, 01:15:00).

### 7.7 Neden bire göre tümleyen kullanılmaz

Hoca kimse sormadan bu soruyu kendisi açtı. `00000000` işaretli sistemde 0'dır. Negatif sayılar bire göre tümleyenle gösterilseydi `11111111` dizisi negatif olduğu için tümleyeni alınınca `00000000` çıkacak, yani −0 olacaktı (ekrandan, 01:35:00). Hem bütün birlerden hem bütün sıfırlardan oluşan iki farklı dizi aynı değeri (sıfırı) gösterecekti. Bir değeri iki kombinasyonla göstermek bir kombinasyonun boşa gitmesidir. Bu durumda aralık −127 ile 127 olur, −128 saklanamazdı. İkiye göre tümleyende sıfırın tek gösterimi vardır ve fazladan bir değer (−128) kazanılır.

### 7.8 Ters yönde dönüşüm: onluktan ikiye göre tümleyene

Şimdiye kadar ikilik bir sayıdan onluk değere gidildi. Ters yön için, örneğin −32:

**Soru:** −32 nasıl yazılır? (Bir öğrenci önce 1 çıkarıp sonra bire göre tümleyen almayı önerdi.)
**Cevap:** Hoca bunun tersten bir yaklaşım olduğunu söyledi ve şu yolu verdi: önce sayının pozitif hali yazılır, sonra ikiye göre tümleyeni alınır.

```text
 32       = 0010 0000
1'e göre  = 1101 1111
+1        = 1110 0000   -> -32
```

`11100000` işaretsiz olarak yorumlansaydı 224 olurdu (ara adımlar altyazıdan kuruldu; değerler python ile doğrulandı).

Hoca bir dakikalık alıştırma olarak −1'i yazdırdı. Gelen cevap `11111111` idi ve doğruydu: `00000001` → bire göre `11111110` → +1 → `11111111`.

> **Ek bilgi (derste anlatılmadı):** Hocanın sözünü ettiği "bilimsel" yöntem ile 256'dan çıkarma kuralı aynı şeydir: $n$ bitte bir $x$ sayısının ikiye göre tümleyeni $2^n - x$'tir. 8 bitte $2^8 = 256$ olduğundan −63, $256 - 63 = 193$ işaretsiz koduyla saklanır.

## 8. Excess gösterimi

### 8.1 Excess-4

Negatif sayıları göstermenin ikinci yolu excess (fazlalık) gösterimidir. 3 bitlik örnekte `100` orta nokta, yani 0 kabul edilir. Yukarı doğru `101`, `110`, `111` sırasıyla 1, 2, 3; aşağı doğru `011`, `010`, `001`, `000` sırasıyla −1, −2, −3, −4 olur (ekrandan, 01:15:00).

Kolay hesap: kodun işaretsiz değerinden 4 çıkarılır.

| Kod | İşaretsiz | Hesap | Değer |
|-----|-----------|-------|-------|
| 111 | 7 | 7 − 4 | 3 |
| 110 | 6 | 6 − 4 | 2 |
| 101 | 5 | 5 − 4 | 1 |
| 100 | 4 | 4 − 4 | 0 |
| 011 | 3 | 3 − 4 | −1 |
| 010 | 2 | 2 − 4 | −2 |
| 001 | 1 | 1 − 4 | −3 |
| 000 | 0 | 0 − 4 | −4 |

Çıkarılan 4, sıfır kabul edilen `100` kodundaki 1'in basamak değeridir (birler, ikiler, dörtler basamağından dörtler). Bu nedenle bu gösterime **Excess-4 notation** denir ve −4 ile 3 aralığını kapsar.

### 8.2 Excess-8

**Soru (derste soruldu):** 4 bitte `1000` sıfır olsaydı `1111` ve `0000` hangi değerleri gösterirdi?
**Cevap:** `1111` = 15 − 8 = 7, `0000` = 0 − 8 = −8. Bu Excess-8 gösterimidir (ekrandan, 01:15:00).

Genel kural: 1 ile başlayıp geri kalanı 0 olan kod 0 değerini alır. Bu koddaki 1 hangi basamaktaysa o basamağın değeri çıkarılır ve gösterimin adı da odur.

## 9. Kesirli sayılar ve kayan nokta gösterimi

### 9.1 İkilik kesirler

Onluk sistemde nokta solundaki basamaklar $10^0, 10^1, \dots$, sağındakiler $10^{-1}, 10^{-2}, \dots$ değerindedir (ekranda örnek olarak 5.25 yazıldı). İkilik sistemde de nokta konabilir: noktanın solu $2^0, 2^1, 2^2, \dots$, sağı $2^{-1}, 2^{-2}, \dots$ değerindedir (ekrandan, 01:20:00).

**Örnek:** $(100.11)_2 = 4 + \frac{1}{2} + \frac{1}{4} = 4\frac{3}{4} = 4.75$.

**Örnek:** $(10.01)_2 = 2 + \frac{1}{4} = 2\frac{1}{4} = 2.25$ (ekrandan, 01:25:00).

Sorun, noktanın bilgisayara nasıl anlatılacağıdır. Eksi işareti işaret bitiyle anlatıldı; noktayı anlatmak bu kadar kolay değildir. Bunun için **kayan nokta gösterimi** (floating-point notation) kullanılır.

### 9.2 8 bitlik kayan nokta yapısı

8 bit üç bölüme ayrılır (ekrandan, 01:25:00):

```text
| işaret (1 bit) | üs / exponent (3 bit) | mantis / mantissa (4 bit) |
```

Bit sayısı arttıkça bölümlerin boyu da değişir.

**Soru (hoca sordu):** Noktanın sağa ya da sola hareketinden hangi bölüm sorumludur?
**Cevap (bir öğrenci):** Üs (exponent). Sayının işaretinden işaret biti, noktanın kaymasından üs, sayının kendisinden mantis sorumludur.

Üs alanı için daha önce görülen Excess-4 gösterimi kullanılır, çünkü noktanın sola kayması eksi, sağa kayması artı bir değerle ifade edilmelidir.

### 9.3 Kayan noktadan onluğa

**Örnek 1: `0 110 1011`** (ekrandan, 01:25:00)

- İşaret biti 0: sayı pozitif.
- Mantis `1011` alınır, başına nokta konur: `.1011`.
- Üs `110` = 6, Excess-4 ile $6 - 4 = 2$: nokta iki basamak sağa kayar.
- `.1011` → `10.11` = $2 + \frac{1}{2} + \frac{1}{4} = 2\frac{3}{4} = 2.75$.

**Örnek 2: `1 110 1011`**

İşaret biti 1, geri kalan aynı. Sonuç $-2\frac{3}{4} = -2.75$.

**Örnek 3: `0 011 1100`** (ekrandan, 01:30:00)

- İşaret 0: pozitif.
- Mantis `.1100`.
- Üs `011` = 3, $3 - 4 = -1$: nokta bir basamak sola kayar, başa bir 0 gelir: `.01100`.
- Değer $\frac{1}{4} + \frac{1}{8} = \frac{3}{8}$.

> **Hocanın vurgusu:** Aynı 0/1 dizisi işaretsiz, işaretli ya da kayan nokta olarak farklı değerlere karşılık gelir. Bir bit grubu verildiğinde hangi gösterimde olduğu da verilmelidir.

### 9.4 Onluktan kayan noktaya

**Örnek 4: $1\frac{1}{2} = 1.5$** (ekrandan, 01:30:00)

- İşaret: pozitif, 0.
- İkilik hali: `1.1`.
- Mantis: `1100`.
- `.1100`'den `1.1`'e ulaşmak için nokta bir sağa kaymalı: üs = 1. Excess-4 ile kod $1 + 4 = 5$ = `101`.
- Sonuç: `0 101 1100`.
- Sağlama: mantis `.1100`, üs $5 - 4 = 1$, nokta bir sağa: `1.1` = $2^0 + 2^{-1} = 1.5$.

**Soru:** Mantise `1100` yerine `0110` yazıp noktayı iki kaydırsak aynı şey olmaz mı?
**Cevap:** Hoca bunu 3/8 örneğiyle cevapladı.

**Örnek 5: $\frac{3}{8}$** (ekrandan, 01:40:00)

- İkilik hali: `.011` (tamsayı kısmı yok).
- İşaret: 0.
- Bir öğrenci mantis için `0011` önerdi; hoca bunun doğru olmadığını söyledi. Kural: mantise ilk 1'in görüldüğü yerden itibaren yazılır. Baştaki sıfırlar bir şey ifade etmez, yalnız yer kaplar. Mantis `1100` olur.
- `.1100`'den `.011`'e ulaşmak için nokta bir sola kaymalı: üs = −1, kod $-1 + 4 = 3$ = `011`.
- Sonuç: `0 011 1100`. Bu, Örnek 3'te çözülen dizinin aynısıdır.

> **Hocanın vurgusu:** Mantise her zaman 1 ile başlayan bölüm yazılmalıdır. Baştaki gereksiz bir 0, sondaki anlamlı bir 1'in kaybolmasına yol açabilir.

**Örnek 6: −1.75** (öğrenci sorusu üzerine, ekrandan, 01:40:00)

Bir öğrenci negatif kesirli sayıları yazarken hata yaptığını söyleyip örnek istedi.

- $1.75 = 1 + \frac{1}{2} + \frac{1}{4}$ = `1.11`.
- Eksi olduğu için işaret biti 1.
- Mantis: `1110`.
- Nokta bir sağa kaymalı: üs 1, kod $1 + 4 = 5$ = `101`.
- Sonuç: `1 101 1110`.

Öğrenci, hatasının mantise yazmaya ilk 1'den başlamayı unutmak olduğunu fark etti.

## 10. İkilik toplama, taşma ve çıkarma

### 10.1 Taşma

İki sayı her zamanki gibi toplanır: $1 + 1 = 10$, 0 yazılır, elde 1 sola geçer. Hocanın 4 bitlik örneğinde en soldaki toplamdan bir elde daha çıktı ve beşinci bir bit oluştu. Yalnız 4 bit yer olsaydı bu beşinci bit kaybolacaktı; buna **taşma** (overflow) problemi denir. Aynı sayılar 8 bitle işlenince sorun ortadan kalkar. 8 bitte de iki sayı toplandığında sonuç dokuzuncu bite taşabilir; sonuç bir byte'lık alanda tutuluyorsa elde edilen sayı istenen sayı olmaz. <!-- BELİRSİZ: Taşma örneklerinde toplanan 4 bitlik ve 8 bitlik sayıların değerleri karelerde görünmüyor, altyazıdan da çıkarılamıyor. -->

> **Hocanın vurgusu:** İşlemin sonucunda en solda çıkan değer saklanmalıysa ve onun için yer yoksa bilgi kaybolur. Buna dikkat etmek gerekir.

### 10.2 Toplama örnekleri

4 bitlik ikiye göre tümleyen ile (ekrandan, 01:45:00):

**$3 + 2 = 5$**

```text
  0011   (3)
+ 0010   (2)
------
  0101   (5)
```

**$(-3) + (-2) = -5$**

−3 ve −2 önce pozitif halleri yazılıp ikiye göre tümleyenleri alınarak bulunur (hoca bu adımı uzun uzun yazmadı).

```text
  1101   (-3)
+ 1110   (-2)
------
  1011   (-5)   (taşan beşinci bit atılır; ara adım eklendi)
```

`1011`'in ikiye göre tümleyeni `0101` = 5 olduğundan sonuç −5'tir.

### 10.3 Çıkarma

**Soru (hoca sordu):** 7'den 5'i çıkarmak için ne yapılır?
**Cevap (bir öğrenci):** 7 ile −5 toplanır.

Bilgisayar çıkarmayı bildiğimiz biçimde yapmaz: çıkarılan sayının negatifi (ikiye göre tümleyeni) alınır ve toplanır. İki negatif sayı varsa da aynı yol izlenir.

```text
  0111   (7)
+ 1011   (-5)
------
  0010   (2)    (taşan beşinci bit atılır; ara adım eklendi)
```

(ekrandan, 01:45:00)

**Soru:** Çıkarmada tümleyen işlemi nasıl yapılıyordu?
**Cevap:** −5 için önce 5 yazılır, bire göre tümleyeni alınır, 1 eklenir (ekrandan, 01:50:00):

```text
 5        = 0000 0101
1'e göre  = 1111 1010
+1        = 1111 1011
```

Toplama 4 bitle yapıldığı için yalnız son dört bit `1011` kullanıldı; isterseniz 8 bitin hepsiyle de işlem yapılabilir.

## 11. Tek ve çift duyarlıklı kayan nokta, kesme hatası

### 11.1 Single ve double precision

Günümüzde 32 ve 64 bitlik işlemciler kullanılır. 32 bitlik tek duyarlıklı kayan nokta (single precision floating point) biçiminde bitler şöyle ayrılır (ekrandan, 01:50:00):

```text
| işaret (1 bit) | üs (8 bit) | mantis (23 bit) |
```

Daha yüksek hassasiyet gerektiğinde 64 bitlik çift duyarlıklı kayan nokta (double precision floating point) kullanılır. Noktadan sonraki hassasiyet arttığı için daha küçük farklar ifade edilebilir.

Ekrandaki örnek: 1.378 gibi bir sayı için 32 bit yeterlidir; 2.57921876983247 gibi çok sayıda ondalık basamaklı bir sayı için 64 bit gerekir (ekrandan, 01:50:00). Hassasiyet arttıkça kaplanan alan da artar. 64 bitlik alan ayrıldığında 2.5 ya da 3.0 gibi basit sayılar da saklanabilir, ama her biri yine 64 bit (8 byte) yer kaplar.

C dilinde tek duyarlıklıya `float`, çift duyarlıklıya `double` tipi karşılık gelir. Yüksek hassasiyet gerekmiyorsa boşuna yer kaplamamak için `float` kullanılır.

**Soru:** 8 bitlik kayan noktada Excess-4 kullandık; 32 bitte ne kullanılır?
**Cevap:** 8 bitlik yapıda üs 3 bitti ve Excess-4 kullanıldı. 32 bitte üs 8 bit olduğundan Excess-128 kullanılır: üs kodundan 128 çıkarılarak noktanın kaç basamak kayacağına karar verilir. Fazlalık değeri üs alanının bit sayısına göre belirlenir ($2^{n-1}$).

> **Ders sonrası not:** Gerçek IEEE 754 tek duyarlıklı standardında üs sapması (bias) 127'dir, 128 değildir. Standart ayrıca normalize sayılarda mantisin başındaki 1'i saklamaz (gizli bit); derste anlatılan 8 bitlik model bu ayrıntıları içermeyen öğretim amaçlı bir modeldir.

> **Ek bilgi (derste anlatılmadı):** IEEE 754 çift duyarlıklı biçimde 64 bit; 1 işaret, 11 üs ve 52 mantis biti olarak ayrılır ve üs sapması 1023'tür. Bu sayede `double` yaklaşık 15–16 anlamlı ondalık basamak, `float` ise yaklaşık 7 anlamlı basamak hassasiyet sağlar.

### 11.2 Kesme hatası

Ders sonundaki örnek (ekrandan, 02:00:00): $2\frac{5}{8}$ sayısı ikilikte `10.101` diye yazılır.

- Mantis ilk 1'den başlar ve 4 bittir: `1010`. Sondaki 1 sığmaz.
- Nokta `.1010`'dan `10.101`'e ulaşmak için iki sağa kaymalı: üs 2, kod $2 + 4 = 6$ = `110`.
- İşaret 0. Saklanan dizi: `0 110 1010`.

Bu dizi geri çevrilince: `.1010`, nokta iki sağa → `10.10` = $2\frac{4}{8} = 2.5$. Sondaki bit kaybolmuştur. Buna kayıp bit (lost bit), bu hataya **kesme hatası** (truncation error) denir.

Sayı biraz daha büyük olsaydı, örneğin `1000.101`, noktadan sonraki kısmın da saklanamayacağı belirtildi. Yani saklanacak sayının büyüklüğü ile saklama alanının büyüklüğü karşılaştırıldığında, hassasiyeti düşük olan kısım yer yetmediği için kaybolabilir. Değişkene $2\frac{5}{8}$ verilse bile bilgisayar onu $2\frac{4}{8}$ olarak saklayabilir.

> **Hocanın vurgusu:** Kayan noktadaki bu hassasiyet farkı nedeniyle iki bilgisayarda kesirli sayılarla yapılan işlemler farklı sonuçlar üretebilir.

> **Ek bilgi (derste anlatılmadı):** Kesme hatası yalnız mantis kısalığından değil, bazı onluk kesirlerin ikilikte sonlu yazılamamasından da doğar. Örneğin 0.1 ikilikte sonsuz tekrar eden bir kesirdir; bu yüzden birçok dilde `0.1 + 0.2` tam olarak 0.3'e eşit çıkmaz.

## Örnek Sorular

**Soru 1** (ekrandan, 00:05:00) Adres `0x000F`'ten sonra hangi adres gelir? `0xABCD`'den sonraki üç adres nedir?

> **Çözüm:** `0x0010`. `0xABCE`, `0xABCF`, `0xABD0`.

**Soru 2** (ekrandan, 00:20:00) `01011100` işaretsiz tamsayı olarak verilseydi onluk değeri ne olurdu?

> **Çözüm:** $64 + 16 + 8 + 4 = 92$.

**Soru 3** (ekrandan, 00:25:00) `11100000`, `00010000` ve `10000000` işaretsiz sayılarını onluk, sekizlik ve onaltılık tabana çevirin.

> **Çözüm:** 224, $(340)_8$, $(E0)_{16}$; 16, $(20)_8$, $(10)_{16}$; 128, $(200)_8$, $(80)_{16}$.

**Soru 4** (derste sözlü, 00:47:39) Bire göre tümleyen almak nedir?

> **Çözüm:** Sıfırları bir, birleri sıfır yapmak, yani her bitin değilini almak.

**Soru 5** (ekrandan, 00:55:00) İşaretli tamsayı sisteminde `11000001` kaçtır? İşaretsiz olarak kaçtır?

> **Çözüm:** Negatif; tümleyen `00111110` + 1 = `00111111` = 63, sonuç −63. İşaretsiz olarak 193; $256 - 193 = 63$.

**Soru 6** (derste sözlü, 01:12:51) Excess-8 gösteriminde (4 bit) `1111` ve `0000` hangi değerleri gösterir?

> **Çözüm:** $15 - 8 = 7$ ve $0 - 8 = -8$.

**Soru 7** (derste sözlü, 01:21:35) Kayan nokta gösteriminde noktanın sağa sola kaymasından hangi alan sorumludur?

> **Çözüm:** Üs (exponent) alanı.

**Soru 8** (ekrandan, 01:30:00) $1\frac{1}{2}$ sayısını 8 bitlik kayan nokta gösterimiyle yazın.

> **Çözüm:** `1.1` → işaret 0, mantis `1100`, üs +1 → `101`. Sonuç `0 101 1100`.

**Soru 9** (derste sözlü, 01:36:20) −1 sayısını 8 bitlik ikiye göre tümleyen gösterimiyle yazın.

> **Çözüm:** `00000001` → `11111110` → +1 → `11111111`.

**Soru 10** (ekrandan, 01:40:00) −1.75 sayısını 8 bitlik kayan nokta gösterimiyle yazın.

> **Çözüm:** `1.11` → işaret 1, mantis `1110`, üs +1 → `101`. Sonuç `1 101 1110`.

**Soru 11** (ekrandan, 02:00:00) $2\frac{5}{8}$ sayısını 8 bitlik kayan nokta gösterimiyle yazın. Geri çevirince hangi değer elde edilir?

> **Çözüm:** `10.101` → mantis `1010`, üs +2 → `110`, sonuç `0 110 1010`. Geri çevirince $2\frac{4}{8} = 2.5$ çıkar; sondaki bit kaybolur (kesme hatası).

## Dersin Toparlaması

Bu derste verinin bilgisayarda en temel düzeyde nasıl saklandığı görüldü. Bit ve byte kavramlarından, belleğin bir byte'lık hücrelerden oluştuğundan ve adreslerin onaltılık sayılarla yazıldığından başlandı. Verinin donanımda mantık kapılarıyla tutulduğu ve işlendiği, AND, OR, XOR ve NOT kapıları ile basit bir devrenin doğruluk tablosu üzerinden anlatıldı. MSB ve LSB kavramlarının ardından sayı dönüşümleri tekrar edildi. Sayıların yanında karakterlerin (ASCII, UTF-8), görüntünün, videonun ve sesin de bit örüntüleriyle temsil edildiği, analog bilginin örnekleme ile dijitale çevrildiği konuşuldu.

Dersin ikinci yarısında negatif ve kesirli sayıların gösterimi işlendi. Negatif sayılar için ikiye göre tümleyen ve excess gösterimleri, bire göre tümleyenin neden kullanılmadığı (iki sıfır sorunu) anlatıldı. Kesirli sayılar için 8 bitlik kayan nokta modeli (1 işaret, 3 bit Excess-4 üs, 4 bit mantis) ile iki yönde dönüşümler yapıldı. İkilik toplama, taşma ve çıkarmanın tümleyenle toplama olarak yapılması gösterildi. Son olarak 32 ve 64 bitlik kayan nokta biçimleri, C'deki `float` ve `double` tipleri ve mantise sığmayan bitlerden doğan kesme hatası anlatıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
