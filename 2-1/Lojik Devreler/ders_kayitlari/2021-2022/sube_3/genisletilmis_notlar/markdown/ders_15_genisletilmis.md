# Ders 15 Genişletilmiş Notu: Lojik Fonksiyonların İndirgenmesi: Karnaugh Haritaları ve Quine-McCluskey

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Lojik fonksiyonların indirgenmesi: amaç ve yöntemler
- 2. Görüşe dayalı indirgeme
- 3. Karnaugh diyagramlarının kurulması
- 4. Karnaugh diyagramlarında komşuluk kavramı
- 5. Karnaugh haritasıyla bir fonksiyonun indirgenmesi
- 6. Eksik Boole işlevleri (don't care durumları)
- 7. Quine-McCluskey yöntemi
- Örnek Sorular
- Dersin Toparlaması

## 1. Lojik fonksiyonların indirgenmesi: amaç ve yöntemler

Dersin konusu lojik fonksiyonların indirgenmesidir (ekrandan, 00:05:00). Hoca önce "indirgeme" ile ne kastedildiğini hatırlatır. Önceki derslerde ikili (binary) değişkenlerle $f(a,b,c,d) = abc' + cd + abc$ gibi lojik fonksiyonlar yazılmıştı (ekrandan, 00:10:00). Böyle bir fonksiyonun çıkışı, $a, b, c, d$ değişkenlerinin aldığı 0 ve 1 değerlerine göre belirlenir. $n$ değişken (ya da $n$ bit) varsa doğruluk tablosunda $2^n$ farklı durum vardır.

İfadedeki her terim lojik kapılarla gerçekleştirilir. Aynı çıkışı veren, daha az değişkenli ve daha az terimli bir ifade bulunabilirse kapılardan, yani çip maliyetinden tasarruf edilir. Her kapı elektrikle beslendiği için daha az kapı daha az güç tüketimi demektir; kapılar ısı da yaydığından devre üzerindeki ısınma da azalır. Hocanın vurguladığı gibi bu kavramların hepsi birbirine bağlıdır.

İndirgenmiş ifade ile asıl ifade birbirinden farklılaşmaz: $2^n$ giriş kombinasyonunun her birinde ikisi de aynı çıkışı üretmek zorundadır. Örneğin dört değişkende 16 satırın hepsinde sonuçlar aynı çıkmalıdır.

Derste üç indirgeme yöntemi işlenir (ekrandan, 00:15:00):

- a) Görüşe dayalı indirgeme
- b) Karnaugh diyagramları (Karnaugh haritaları, Karnaugh maps)
- c) Quine-McCluskey yöntemi

Hoca ayrıca tümleyenin iki gösterimini hatırlatır: değişkenin üzerine çizgi çekmek ya da sağına kesme işareti koymak aynı anlamdadır, $\bar a = a'$ (ekrandan, 00:15:00). Bu notta tahtadaki gibi $a'$ gösterimi kullanılır.

## 2. Görüşe dayalı indirgeme

Görüşe dayalı indirgeme, önceki derste görülen aksiyom ve teoremlerden yararlanarak, genelde az değişkenli ifadeleri elle ve hızlıca sadeleştirmek demektir. Ne kadar sadeleştirilebileceği, kişinin bu teoremleri ifadeye ne kadar iyi uygulayabildiğine bağlıdır.

### 2.1 Dört değişkenli örnek

Tahtadaki fonksiyon (ekrandan, 00:15:00):

$$f(a,b,c,d) = a'bc' + ad + bc'd'$$

Adım 1, ortak parantez: birinci ve üçüncü terimde $bc'$ ortaktır.

$$f = bc'(a' + d') + ad$$

Adım 2, De Morgan: hoca "$a' + d'$ hangi ifadenin De Morgan ile açılmış hâlidir?" diye sorar. Cevap $ad$'nin tümleyenidir: $a' + d' = (ad)'$.

$$f = bc'\,(ad)' + ad$$

Adım 3, dağılma: VEYA işleminin VE üzerine dağılma özelliği hatırlatılır (ekrandan, 00:15:00):

$$x + yz = (x + y)(x + z)$$

Burada $x = ad$, $y = bc'$, $z = (ad)'$ alınır:

$$f = (ad + bc')\,\big(ad + (ad)'\big)$$

Adım 4: ikinci parantezde $ad$ 0 ise $(ad)'$ 1'dir, $ad$ 1 ise $(ad)'$ 0'dır; toplam daima 1 olur (ekrandan, 00:20:00).

$$f = ad + bc'$$

Sonuç python ile 16 giriş kombinasyonunda doğrulandı (iki ifade de $4, 5, 9, 11, 12, 13, 15$ mintermlerinde 1'dir).

### 2.2 Kapı sayısı karşılaştırması

Hoca iki ifadenin devre maliyetini karşılaştırır (ekrandan, 00:20:00):

- İlk ifade $a'bc' + ad + bc'd'$: iki adet 3 girişli VE, bir adet 2 girişli VE, bunları birleştiren bir adet 3 girişli VEYA ve tümleyenler için DEĞİL kapıları.
- İndirgenmiş ifade $ad + bc'$: iki adet 2 girişli VE, bir adet 2 girişli VEYA ve $c'$ için bir DEĞİL kapısı. Tahtadaki çizimde $a$ ve $d$ bir VE kapısına, $c$ bir DEĞİL kapısından geçip $b$ ile birlikte ikinci VE kapısına girer; iki VE çıkışı bir VEYA kapısında birleşir.

> **Ders sonrası not:** Hoca ilk ifade için "dört tane DEĞİL işlemi" saydı (tahtada "4 NOT" yazıyor). İfadede $a'$, $c'$ (iki kez) ve $d'$ geçtiği için terim başına sayınca dört tümleme vardır; aynı tümleyen paylaşılırsa farklı tümleyen sayısı büyük olasılıkla üçtür ($a', c', d'$). Her iki durumda da indirgenmiş ifade daha ucuzdur.

### 2.3 Minterm gösterimiyle örnek

Hoca bir önceki derste görülen minterm gösterimini kullanarak üç değişkenli bir örnek daha verir (ekrandan, 00:20:00 ve 00:25:00):

$$f(x,y,z) = \sum(0,4) = m_0 + m_4 = x'y'z' + xy'z'$$

İlk adım $y'z'$ ortak parantezine almaktır:

$$f = y'z'(x' + x) = y'z'$$

$x' + x$ daima 1 olduğundan ifade en basit hâli olan $y'z'$'ye iner.

## 3. Karnaugh diyagramlarının kurulması

### 3.1 Tarihçe ve temel fikir

Yöntemi ilk olarak Veitch 1952'de önermiş, Karnaugh 1953'te son hâlini vermiştir (ekrandan, 00:25:00). Temel fikir, doğruluk tablosunu uzamsal bir matrisin üzerine yatırmaktır.

### 3.2 İki değişkenli harita

İki değişkenli ($x, y$) bir fonksiyonun doğruluk tablosunda dört satır vardır: $00 \to m_0$, $01 \to m_1$, $10 \to m_2$, $11 \to m_3$. Harita $2 \times 2$'dir: satıra $x$, sütuna $y$ yazılır (ekrandan, 00:25:00).

| $x \backslash y$ | 0 | 1 |
|---|---|---|
| 0 | $m_0$ | $m_1$ |
| 1 | $m_2$ | $m_3$ |

### 3.3 Üç değişkenli harita ve Hamming uzaklığı

Üç değişkende ($x, y, z$) $2^3 = 8$ durum ($m_0$ - $m_7$) vardır. 8 hücre bir kare oluşturmaz; bir kenara tek değişken, diğer kenara iki değişken yazılır. Örneğin satıra $x$ (0, 1), sütuna $yz$ yazılır. $yz$'nin dört durumu sırayla $00, 01, 10, 11$ diye yazılmaz.

Karnaugh haritasında art arda gelen satır ya da sütun etiketleri arasındaki Hamming uzaklığı en fazla 1 olmalıdır. Hamming uzaklığı, iki bit dizisinde birbirinden farklı olan bitlerin sayısıdır (ekrandan, 00:25:00):

- $001$ ile $000$: yalnız son bit farklı, Hamming uzaklığı 1.
- $101$ ile $011$: iki bit farklı, Hamming uzaklığı 2.

$01$'den sonra $10$ yazılsaydı iki bit birden değişirdi (uzaklık 2). Bunu önlemek için $01$'den sonra $11$, sonra $10$ yazılır. Sıra $00, 01, 11, 10$ olur. Bu yüzden hücrelere mintermler "atlayarak" yerleşir (ekrandan, 00:30:00):

| $x \backslash yz$ | 00 | 01 | 11 | 10 |
|---|---|---|---|---|
| 0 | $m_0$ | $m_1$ | $m_3$ | $m_2$ |
| 1 | $m_4$ | $m_5$ | $m_7$ | $m_6$ |

Tablo başka biçimde de kurulabilir: satıra $xy$ ($00, 01, 11, 10$), sütuna $z$ (0, 1) yazılırsa satırlar sırasıyla $m_0\,m_1$; $m_2\,m_3$; $m_6\,m_7$; $m_4\,m_5$ olur (ekrandan, 00:30:00). Hangi değişkenin hangi kenara yazıldığı serbesttir; önemli olan her hücreye doğru mintermin yerleştirilmesidir.

### 3.4 Dört değişkenli harita

Dört değişkende ($x, y, z, w$) $xy$ bir kenara, $zw$ diğer kenara yazılır; $4 \times 4$'lük bir matris oluşur. İki kenarda da etiket sırası $00, 01, 11, 10$'dur. Kenarlar yer değiştirebilir ($zw$ satıra, $xy$ sütuna); o zaman hücrelerdeki mintermlerin yeri de değişir (ekrandan, 00:30:00).

**Soru:** $01$'den sonra $11$, sonra $10$ yazılmasının devreyi oluştururken bir amacı var mı?
**Cevap:** Bu sıra, tabloda yan yana gelen hücrelerin Hamming uzaklığının 1 olması içindir. İndirgemede komşuluk kavramından yararlanılacağı için böyle yapılır; komşuluk anlatılınca nedeni anlaşılır.

## 4. Karnaugh diyagramlarında komşuluk kavramı

### 4.1 Tanım

Tahtadaki tanım (ekrandan, 00:35:00):

> $n$ değişkenli bir fonksiyonda $2^k$ ($k = 1, 2, 3, \dots$) terimin toplamı kısalıp $(n-k)$ çarpanlı bir tek terime dönüşürse, bu $2^k$ tane terim $k$. mertebeden komşudur.

Komşu hücrelerin harita üzerinde kapladığı bölgeye hoca "alan" der. Alanın karşılığı olan terim şöyle bulunur: alanı gören satır etiketlerine ve sütun etiketlerine bakılır; alan boyunca değişmeyen değişkenler yazılır. Değeri hep 1 olan değişken olduğu gibi, hep 0 olan tümlenmiş yazılır; 0'dan 1'e değişen değişken atılır.

### 4.2 Teorem 1: birinci dereceden komşuluk ($k = 1$)

$n = 4$, $k = 1$ için $2^k = 2$ terim birleşir ve $n - k = 3$ çarpanlı tek terim oluşur (ekrandan, 00:40:00). İki hücre alan üzerinde birbirine bir uzaklıkta, yani yan yana olmalıdır.

Örnek: $ab = 01$ satırında $cd = 01$ ve $cd = 11$ hücreleri 1 olsun. Minterm toplamı ve cebirle sadeleştirme:

$$a'bc'd + a'bcd = a'bd(c' + c) = a'bd$$

Haritadan okuma: satır etiketi $01$ alan boyunca sabittir, yani $a'b$. Sütunlar $01$ ve $11$'dir; $c$ 0'dan 1'e değişir, $d$ ikisinde de 1'dir. Sonuç $a'bd$; cebirle bulunanla aynıdır.

İkili bir alan yatay (bir satırda iki hücre) ya da dikey (bir sütunda iki hücre) olabilir. Harita ayrıca bir "soba borusu" gibi düşünülmelidir: $00$ sütunu ile $10$ sütunu, $00$ satırı ile $10$ satırı birbirine yapışıkmış gibi komşudur.

Hoca bunu bir harita üzerinde gösterir (ekrandan, 00:45:00). Haritada 1 olan hücreler şunlardır:

| $ab \backslash cd$ | 00 | 01 | 11 | 10 |
|---|---|---|---|---|
| 00 | 1 | 1 | 0 | 1 |
| 01 | 0 | 1 | 1 | 0 |
| 11 | 0 | 0 | 1 | 0 |
| 10 | 0 | 1 | 0 | 0 |

- $ab = 00$ satırındaki $cd = 00$ ve $cd = 10$ hücreleri (kenar komşuluğu): $a$ ve $b$ 0, $d$ 0 sabit, $c$ değişir $\Rightarrow a'b'd'$.
- $ab = 01$ satırında $cd = 01, 11$: $a'bd$.
- $cd = 11$ sütununda $ab = 01, 11$: $a$ değişir, $b = 1$, $c = d = 1$ $\Rightarrow bcd$.
- $cd = 01$ sütununda $ab = 00, 10$ (kenar komşuluğu): $b = 0$, $c = 0$, $d = 1$ $\Rightarrow b'c'd$.

$$f(a,b,c,d) = a'b'd' + a'bd + bcd + b'c'd$$

Aynı fonksiyon mintermlerle yazılsaydı yedi tane dört değişkenli terim gerekirdi ($a'b'c'd' + a'b'c'd + \dots$). Karnaugh haritası, fonksiyonu görsel olarak indirgeme imkânı verir. (Mintermler $0, 1, 2, 5, 7, 9, 15$; sonuç python ile doğrulandı.)

**Soru:** Çapraz köşedeki değerler, örneğin sol üst ve sağ alt köşe, komşu sayılır mı?
**Cevap:** Hayır, çaprazlar komşu olmaz; yalnız kenarlar komşudur. İkili komşulukta köşegen komşuluğu yoktur.

### 4.3 Teorem 2: ikinci dereceden komşuluk ($k = 2$)

$k = 2$ için $2^2 = 4$ terim (hücre) komşu olmalıdır (ekrandan, 00:50:00). Dört hücrenin ikinci dereceden komşu olması için gerek ve yeter koşul, harita üzerinde bir kare ya da bir sıra oluşturmalarıdır.

> **Hocanın vurgusu:** Kitapta dört hücrenin illa bir kare oluşturması gerektiği yazıyor; hocaya göre bu ifade yanlış, dört hücre bir sıra (bütün bir satır ya da sütun) da oluşturabilir.

Örnek (ekrandan, 00:50:00 ve 00:55:00): $cd = 01$ sütununun dört hücresi ile $ab = 01, 11$ satırlarının $cd = 11, 10$ sütunlarıyla kesiştiği dört hücre 1 olsun (toplam sekiz adet 1).

- Mavi alan, $cd = 01$ sütunu: sütun etiketi alan boyunca $01$'dir, satırların hepsi değişir $\Rightarrow c'd$. Burada $n - k = 4 - 2 = 2$ çarpanlı bir terim oluştu.
- Yeşil kare: satırlar $01$ ve $11$, $a$ değişir, $b = 1$ sabit; sütunlar $11$ ve $10$, $d$ değişir, $c = 1$ sabit $\Rightarrow bc$.

$$f = c'd + bc$$

Komşuluk mertebesi arttıkça ifade daha da basitleşir: ikili komşulukta üç çarpanlı, dörtlü komşulukta iki çarpanlı terim çıkar.

Dörtlü komşuluğun başka biçimleri (ekrandan, 00:55:00):

- Dört köşe: biraz önce sorulan soruyla bağlantılı olarak, dört köşenin hepsi 1 ise bunlar birlikte bir alan oluşturur. Satırlar $00$ ve $10$ ($b = 0$ sabit), sütunlar $00$ ve $10$ ($d = 0$ sabit) $\Rightarrow b'd'$.
- Kenar komşuluğu: $ab = 01$ ve $ab = 11$ satırlarında $cd = 00$ ve $cd = 10$ hücreleri. Satırlarda $b = 1$, sütunlarda $d = 0$ sabit $\Rightarrow bd'$. Bu soruyu öğrenciler cevapladı ("B", sonra "D üssü").

> **Hocanın vurgusu:** Yine köşegen (diyagonal) komşuluk yoktur. Dört köşenin birlikte alınması bir istisna gibi görünse de aslında kenarların yapışık sayılmasından gelen yüzeysel bir komşuluktur.

### 4.4 Teorem 3: üçüncü dereceden komşuluk ($k = 3$)

$2^3 = 8$ hücre komşu olmalıdır. Dört değişkende $4 - 3 = 1$, yani ifade tek bir değişkene iner (ekrandan, 01:00:00).

- $cd = 01$ ve $cd = 11$ sütunlarının sekiz hücresi: satırların hepsi değişir; sütunlarda $c$ değişir, $d = 1$ sabittir $\Rightarrow d$. Aynı fonksiyonu sekiz minterm ($a'b'c'd + a'b'cd + \dots$) ile yazmak çok daha uzun olurdu.
- $ab = 00$ ve $ab = 10$ satırlarının sekiz hücresi (üst ve alt kenar yapışık): sütunların hepsi değişir; satırlarda $b = 0$ sabittir $\Rightarrow b'$.

### 4.5 Teorem 4: dördüncü dereceden komşuluk ($k = 4$)

$f(a,b,c,d)$ için doğruluk tablosunda $0000$'dan $1111$'e 16 durum vardır. Dördüncü dereceden komşuluk için $2^4 = 16$ hücrenin hepsi 1 olmalıdır. Bu durumda fonksiyon daima 1 üretir: $f = 1$ (ekrandan, 01:00:00).

## 5. Karnaugh haritasıyla bir fonksiyonun indirgenmesi

### 5.1 Verilen ifadeden haritaya

Tahtadaki soru (ekrandan, 01:05:00):

$$f(a,b,c,d) = a'b'c' + b'cd' + a'bcd' + ab'c'$$

İlk iş fonksiyonu Karnaugh haritasına geçirmektir; bunun için her $abcd$ kombinasyonunda $f$'nin değeri bulunur. Uzun yol, 16 satırın hepsini tek tek hesaplamaktır. Kolay yol terim terim gitmektir (ekrandan, 01:10:00):

- $a'b'c'$: $a = b = c = 0$ olan her yerde $f = 1$; $d$ önemsizdir $\Rightarrow 0000$ ve $0001$.
- $b'cd'$: $bcd = 010$ olan yerler; $a$ önemsizdir $\Rightarrow 0010$ ve $1010$.
- $a'bcd'$: yalnız $0110$.
- $ab'c'$: $abc = 100$ olan yerler $\Rightarrow 1000$ ve $1001$.

Toplam yedi adet 1 vardır (mintermler $0, 1, 2, 6, 8, 9, 10$); diğer hücreler 0'dır.

| $ab \backslash cd$ | 00 | 01 | 11 | 10 |
|---|---|---|---|---|
| 00 | 1 | 1 | 0 | 1 |
| 01 | 0 | 0 | 0 | 1 |
| 11 | 0 | 0 | 0 | 0 |
| 10 | 1 | 1 | 0 | 1 |

### 5.2 En büyük komşulukla kapsama

1'ler teker teker ikili komşuluklarla da alınabilir, ama amaç en indirgenmiş ifadeyi bulmaksa her 1, alınabilecek en büyük komşulukla kapsanmalıdır (ekrandan, 01:10:00):

- $ab = 00$ ve $ab = 10$ satırlarında $cd = 00, 01$ (üst-alt kenar komşuluğu ile dörtlü kare): $b = 0$, $c = 0$ sabit $\Rightarrow b'c'$.
- Dört köşe: $b'd'$.
- Geriye kalan $0110$ hücresi, $0010$ ile birlikte dikey ikili alan oluşturur: $a = 0$, $c = 1$, $d = 0$ sabit $\Rightarrow a'cd'$.

$$f(a,b,c,d) = b'c' + b'd' + a'cd'$$

Bu kısmı öğrenciler cevapladı. Hoca, bütün 1'lerin kapsanması ve bunun mümkün olan en büyük komşulukla yapılması gerektiğini, bunun biraz pratik düşünme istediğini söyler.

### 5.3 Sıfırlardan yararlanma: toplamlar çarpımı

Şimdiye kadar yazılan ifadeler çarpımların toplamı (sum of products, $\Sigma\Pi$) biçimindedir. Aynı mantık 0'lara da uygulanabilir: 0'lar en büyük komşuluklarla kapsanır. Bu kez alan boyunca değişmeyen değişkenin tersi mantıkla yazılır (0 ise kendisi, 1 ise tümleyeni) ve terimler çarpım değil toplam biçimindedir (ekrandan, 01:15:00):

- $ab = 11$ satırı (dört adet 0): $a = 1$, $b = 1$ $\Rightarrow (a' + b')$.
- $cd = 11$ sütunu (dört adet 0): $c = 1$, $d = 1$ $\Rightarrow (c' + d')$. Bu terimi bir öğrenci düzeltti: "C'nin değili ve D'nin değili olması lazım."
- $ab = 01, 11$ satırlarında $cd = 00, 01$ kare: $b = 1$, $c = 0$ $\Rightarrow (b' + c)$.

$$f = b'c' + b'd' + a'cd' = (a' + b')(c' + d')(b' + c)$$

Birinci ifade çarpımların toplamı (çarpım biçimindeki terimlerin toplamı), ikincisi toplamların çarpımıdır (product of sums, $\Pi\Sigma$; toplam biçimindeki terimlerin çarpımı). İkisi de aynı sonuçları üretir (python ile doğrulandı).

### 5.4 Gereksiz büyük alan

Örnek (ekrandan, 01:20:00):

$$f(a,b,c,d) = \sum(0,3,4,5,6,7,13,14)$$

Hoca mintermlerin haritadaki yerini hızlı bulmak için hücrelere numaralarını yazar: $ab = 00$ satırı $0, 1, 3, 2$; $ab = 01$ satırı $4, 5, 7, 6$; $ab = 11$ satırı $12, 13, 15, 14$; $ab = 10$ satırı $8, 9, 11, 10$. Her satırda Hamming uzaklığı yüzünden 2 ile 3 (ve 6 ile 7 vb.) yer değiştirir.

Hoca önce $ab = 01$ satırını büyük bir dörtlü alan olarak alır ($a'b$), sonra kalan 1'leri ikili alanlarla kapsar:

$$f = a'b + a'c'd' + bc'd + a'cd + bcd'$$

Bir öğrenci "bu dörtlüyü yazmamıza gerek yok" diyerek hatayı yakalar. $m_0$, $m_3$, $m_{13}$ ve $m_{14}$'ü kapsamak için ikili alanlar zorunludur: $m_0, m_4 \to a'c'd'$; $m_5, m_{13} \to bc'd$; $m_3, m_7 \to a'cd$; $m_6, m_{14} \to bcd'$. Bu dört alan $ab = 01$ satırının bütün hücrelerini de kapsar, yani $a'b$ gereksizdir:

$$f = a'c'd' + bc'd + a'cd + bcd'$$

(Sonuç python ile doğrulandı.)

> **Hocanın vurgusu:** Karnaugh haritalarının etkin indirgenmesi için iki şeye dikkat edilir: olabildiğince büyük komşuluk alınır, ama bu her zaman geçerli değildir. Yapılması zorunlu başka alanlarla zaten kapsanan büyük bir alan işleme alınmaz.

## 6. Eksik Boole işlevleri (don't care durumları)

Bazı fonksiyonlarda belirli giriş kombinasyonları için çıkışın ne olduğu önemsizdir: 1 de olsa 0 da olsa istenen davranış değişmez, ya da bu değerler hiç verilmemiştir (ekrandan, 01:35:00). Önemli olan belirli girdiler için belirli çıktıların oluşmasıdır. Bunlara "don't care" (belirsizlik) durumları denir ve haritada $\phi$ ile gösterilir.

Örnek (ekrandan, 01:40:00):

$$f(a,b,c,d) = \sum(3,7,11,12,15) + \sum_\phi(0,10,13,14)$$

Kesin değerler yerleştirilir: $m_3, m_7, m_{11}, m_{12}, m_{15}$ hücrelerine 1. $m_0, m_{10}, m_{13}, m_{14}$ hücrelerine $\phi$ yazılır.

| $ab \backslash cd$ | 00 | 01 | 11 | 10 |
|---|---|---|---|---|
| 00 | $\phi$ | 0 | 1 | 0 |
| 01 | 0 | 0 | 1 | 0 |
| 11 | 1 | $\phi$ | 1 | $\phi$ |
| 10 | 0 | 0 | 1 | $\phi$ |

Amaç yine en büyük komşulukla en indirgenmiş ifadeyi elde etmektir. $\phi$'lere istenen değer verilebilir:

- $m_{13}$ ve $m_{14}$'e 1 verilirse $ab = 11$ satırı dörtlü bir alan olur: $ab$.
- $cd = 11$ sütunu zaten dörtlü bir alandır: $cd$.
- $m_0$ ve $m_{10}$'a 0 verilir; böylece işleme alınmaları gerekmez.

$$f(a,b,c,d) = ab + cd$$

**Soru:** Yani $\phi$ olan yerlere istediğimiz değeri, 0 ya da 1, verebiliyoruz değil mi?
**Cevap:** Evet. Buradaki iki $\phi$'ye 1 verilmesinin nedeni yeşil dörtlü alanı ($ab$) oluşturabilmektir. Diğer $\phi$'lere 0 verilmesinin nedeni onları yeniden bir komşulukla işin içine katmamaktır; katılırsa ifade uzar. Örneğin $m_{10}$'a 1 verilseydi büyük bir komşuluk ($ac$) oluşturulabilirdi, ama bu ifadeye gereksiz bir terim olarak eklenirdi. 0 verildiğinde bu eklemeye gerek kalmaz.

## 7. Quine-McCluskey yöntemi

### 7.1 Neden gerekir?

Görüşe dayalı yöntem ve Karnaugh haritaları 3-4 değişkene kadar rahat uygulanır; 5-6 değişkende işlemler uzar ve zorlaşır. Quine-McCluskey yöntemi çok değişkenli durumları da hesaba katan, daha algoritmik bir yaklaşımdır. Yöntem bir örnek üzerinden anlatılır.

### 7.2 Örnek

$$f(a,b,c,d) = \sum(3,7,11,12,13,14,15)$$

Fonksiyon bazen $\sum$ yerine 1'lerin yerlerini gösteren bir işaretle de verilir. Bu yöntemde harita çizilmez.

**İlk adım: mintermleri ikilik tabanda yazıp 1 sayısına göre gruplamak** (ekrandan, 01:45:00 ve 01:50:00). Her mintermin ikilik karşılığı ve içerdiği lojik 1 sayısı bulunur; aynı sayıda 1 içerenler bir grupta toplanır:

| Grup (1 sayısı) | Minterm | $abcd$ |
|---|---|---|
| 2 | 3 | 0011 |
| 2 | 12 | 1100 |
| 3 | 7 | 0111 |
| 3 | 11 | 1011 |
| 3 | 13 | 1101 |
| 3 | 14 | 1110 |
| 4 | 15 | 1111 |

**İkinci adım: ardışık grupları karşılaştırmak.** Bir gruptaki her terim bir sonraki gruptaki her terimle karşılaştırılır. Yalnız bir bitte farklı olan çiftler birleştirilir: aynı olan bitler yazılır, farklı olan bitin yerine alt çizgi ("_") konur. Birden fazla bitte farklı olan çiftler alınmaz. Örneğin $3 = 0011$ ile $13 = 1101$ üç bitte, $3$ ile $14 = 1110$ üç bitte, $12 = 1100$ ile $7 = 0111$ ve $12$ ile $11 = 1011$ birden fazla bitte farklıdır. 2'li grup ile 4'lü grup (15) doğrudan karşılaştırılmaz, çünkü aralarında çok fazla değişim vardır.

2'li ve 3'lü gruplardan çıkan çiftler (birinci yeni grup) ile 3'lü ve 4'lü gruplardan çıkan çiftler (ikinci yeni grup) (ekrandan, 01:50:00 ve 01:55:00):

| Yeni grup | Çift | $abcd$ |
|---|---|---|
| 1 | 3, 7 | 0_11 |
| 1 | 3, 11 | _011 |
| 1 | 12, 13 | 110_ |
| 1 | 12, 14 | 11_0 |
| 2 | 7, 15 | _111 |
| 2 | 11, 15 | 1_11 |
| 2 | 13, 15 | 11_1 |
| 2 | 14, 15 | 111_ |

**Üçüncü adım: aynı işlemi yeni gruplarla tekrarlamak.** Artık iki grup vardır. Karşılaştırmada alt çizgilerin de aynı yerde olması gerekir; yine yalnız bir bitte fark olabilir ve önceki adımdan gelen alt çizgi korunur:

- $3,7$ ($0\_11$) ile $7,15$ ($\_111$): çok fazla fark, alınmaz.
- $3,7$ ($0\_11$) ile $11,15$ ($1\_11$): alt çizgi ve 1'ler uyuşur, yalnız $a$ farklıdır $\Rightarrow 3,7,11,15 = \_\_11$.
- $3,11$ ($\_011$) ile $7,15$ ($\_111$): yalnız $b$ farklıdır $\Rightarrow 3,11,7,15 = \_\_11$.
- $12,13$ ($110\_$) ile $14,15$ ($111\_$): yalnız $c$ farklıdır $\Rightarrow 12,13,14,15 = 11\_\_$.
- $12,14$ ($11\_0$) ile $13,15$ ($11\_1$): yalnız $d$ farklıdır $\Rightarrow 12,14,13,15 = 11\_\_$.
- Diğer bütün eşleşmelerde birden fazla fark vardır.

| Terimler | $abcd$ |
|---|---|
| 3, 7, 11, 15 | __11 |
| 3, 11, 7, 15 | __11 |
| 12, 13, 14, 15 | 11__ |
| 12, 14, 13, 15 | 11__ |

**Sonuç:** Her terimde değişmeyen bitlere bakılır, alt çizgiler dikkate alınmaz. $11\_\_$ terimi $ab$'yi, $\_\_11$ terimi $cd$'yi verir (sabit bit 1 ise değişkenin kendisi, 0 ise tümleyeni yazılır; örneğin $10\_\_$ olsaydı $ab'$ olurdu). Aynı terimi veren iki satırdan birini almak yeterlidir:

$$f(a,b,c,d) = ab + cd$$

Bu, bölüm 6'daki don't care örneğinin sonucuyla aynıdır (python ile doğrulandı).

Yöntem iteratif ilerlediği için programı kolayca yazılabilir: gruplandırma ve listelerle ardışık grupların karşılaştırılması rahatça gerçekleştirilir. Bu yüzden özellikle değişken sayısı 4'ün üstünde olduğunda tercih edilir. Hoca ayrıntılı anlatımın ders kitabında bulunduğunu belirtir.

**Soru:** Örneğin $12,13$ ile $13,15$ gibi eşleşmelerde aynı terim (13) iki kez geçiyorsa, ya da aynı sonuç iki kez çıkıyorsa sorun olur mu?
**Cevap:** Hayır. Tek gruba indikten sonra elde kalan ifadelere bakılır; aynı ifadeyi veren satırlardan birini almak yeterlidir. Sonuç bu terimlerin çarpımlar toplamı biçiminde yazılmasıyla elde edilir.

> **Ek bilgi (derste anlatılmadı):** Quine-McCluskey'de son adımda bulunan ve daha fazla birleşemeyen terimlere asal çarpanlar (prime implicants) denir. Genel durumda bunların hepsi gerekmeyebilir; hangi asal çarpanların gerektiği bir "asal çarpan tablosu" ile seçilir. Bu örnekte iki asal çarpan ($ab$, $cd$) da zorunludur.

## Örnek Sorular

**Soru 1** (ekrandan, 00:15:00): $f(a,b,c,d) = a'bc' + ad + bc'd'$ ifadesini görüşe dayalı yöntemle indirgeyin.

> **Çözüm:** $f = bc'(a'+d') + ad = bc'(ad)' + ad = (ad + bc')((ad)' + ad) = ad + bc'$ (ekrandan, 00:20:00).

**Soru 2** (ekrandan, 00:20:00): $f(x,y,z) = \sum(0,4)$ fonksiyonunu açık yazıp indirgeyin.

> **Çözüm:** $f = m_0 + m_4 = x'y'z' + xy'z' = y'z'(x'+x) = y'z'$ (ekrandan, 00:25:00).

**Soru 3** (ekrandan, 01:05:00): $f(a,b,c,d) = a'b'c' + b'cd' + a'bcd' + ab'c'$ fonksiyonunu Karnaugh haritasıyla indirgeyin; aynı fonksiyonu 0'ları kullanarak toplamlar çarpımı biçiminde de yazın.

> **Çözüm:** Mintermler $0, 1, 2, 6, 8, 9, 10$. 1'lerden: $f = b'c' + b'd' + a'cd'$ (ekrandan, 01:10:00). 0'lardan: $f = (a'+b')(c'+d')(b'+c)$ (ekrandan, 01:15:00).

**Soru 4** (ekrandan, 01:20:00): $f(a,b,c,d) = \sum(0,3,4,5,6,7,13,14)$ fonksiyonunu Karnaugh haritasıyla indirgeyin.

> **Çözüm:** Zorunlu ikili alanlar: $a'c'd'$, $bc'd$, $a'cd$, $bcd'$. Bunlar $ab = 01$ satırını da kapsadığından $a'b$ gereksizdir. $f = a'c'd' + bc'd + a'cd + bcd'$.

**Soru 5** (ekrandan, 01:40:00): $f(a,b,c,d) = \sum(3,7,11,12,15) + \sum_\phi(0,10,13,14)$ fonksiyonunu indirgeyin.

> **Çözüm:** $m_{13}, m_{14}$ için $\phi = 1$, $m_0, m_{10}$ için $\phi = 0$ alınır. $f = ab + cd$.

**Soru 6** (ekrandan, 01:45:00 - 01:55:00): $f(a,b,c,d) = \sum(3,7,11,12,13,14,15)$ fonksiyonunu Quine-McCluskey yöntemiyle indirgeyin.

> **Çözüm:** Bölüm 7.2'deki adımlarla $\_\_11$ ve $11\_\_$ terimleri kalır: $f = ab + cd$.

**Soru 7** (derste sözlü, 00:46:41): Karnaugh haritasında çapraz köşelerdeki iki hücre (örneğin $0000$ ile karşı köşedeki hücre) ikili komşu sayılır mı?

> **Çözüm:** Hayır. Köşegen komşuluğu yoktur, yalnız kenarlar komşudur. Dört köşe ancak dördü birlikte bir alan ($b'd'$) oluşturabilir.

## Dersin Toparlaması

Bu derste bir lojik fonksiyonu aynı doğruluk tablosunu koruyarak daha az kapıyla gerçekleştirmenin üç yolu görüldü. Görüşe dayalı yöntem teoremlerle (ortak parantez, De Morgan, dağılma) elle sadeleştirmedir. Karnaugh haritası doğruluk tablosunu etiketleri $00, 01, 11, 10$ sırasında olan bir matrise yerleştirir; $2^k$ komşu hücre $(n-k)$ çarpanlı tek bir terime iner. Kenarlar ve dört köşe komşudur, köşegenler değildir. İndirgemede bütün 1'ler en büyük alanlarla kapsanır, gereksiz alanlar atılır. 0'lar gruplanarak toplamlar çarpımı biçimi de elde edilir. Don't care hücrelerine alanı büyütecek şekilde 1 ya da 0 değeri verilir. Quine-McCluskey yöntemi aynı birleştirme fikrini mintermleri 1 sayısına göre gruplayıp tek bit farkla tekrar tekrar birleştirerek algoritmik biçimde uygular; çok değişkenli fonksiyonlar için uygundur.

Hoca bir sonraki derste türetilmiş kapılarla temel lojik kapıların gerçekleştirilmesine ve kombinezonsal (birleşik) devrelere giriş yapılacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
