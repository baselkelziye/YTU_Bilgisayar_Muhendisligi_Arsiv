# Ders 4 Genişletilmiş Notu: Seri Hesaplayan Algoritmalar, Fibonacci ve Önermelerin Bilgisayarla Sınanması

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Hatırlatma: İyi Algoritmanın Özellikleri
- 2. Tam Formül, Yaklaşık Formül ve İşlem Sayısı
- 3. Akış Diyagramı Gösterimi ve $x^n$ Algoritması
- 4. $\pi$'yi Seri ile Hesaplamak
- 5. $e^x$'i Seri ile Hesaplamak ve $n^2$'den $n$'e İnmek
- 6. $n$. Fibonacci Sayısı: Diziden Sabit Belleğe
- 7. Basamak Küpleri Toplamı Kendine Eşit Sayılar
- 8. Hangi Döngü: For mu While mı?
- 9. Önermeler, Karşıt Örnekler ve Bilgisayarla Arama
- 10. Algoritma Geliştirme İteratif Bir Süreçtir
- Örnek Sorular

## 1. Hatırlatma: İyi Algoritmanın Özellikleri

Bu ders tahtaya çizerek anlatıldı. Hoca, algoritma anlatımının çizim gerektirdiğini, bu yüzden slayt yerine elle yazılan bir tahta kullanacağını söyledi.

Derse önceki haftanın tekrarıyla başlandı. Bir problemi çözen birden çok algoritma olabilir ve bunların arasından "doğru", yani daha iyi olanı seçmek gerekir. Öğrencilerle birlikte iyi bir algoritmanın özellikleri sayıldı:

- daha hızlı olması,
- daha az donanım ve bellek gerektirmesi (daha az yer kaplaması),
- daha esnek olması,
- daha anlaşılır olması,
- daha modüler olması.

## 2. Tam Formül, Yaklaşık Formül ve İşlem Sayısı

### 2.1 Gauss formülü: $n$ adımdan sabit adıma

Hoca, 1'den $n$'e kadar sayıların toplamı için Gauss'un bulduğu formülü hatırlattı (ekrandan, 00:15:00):

$$1 + 2 + \dots + n = \frac{(n+1)\,n}{2}$$

Burada eşittir işareti vardır; formül yaklaşık değil, tam sonuç verir. Formülün değeri şuradadır: sayıları tek tek toplamak $n$ adım sürerken formül sonucu sabit sayıda işlemle verir. $n$ bin de olsa on bin de olsa işlem sayısı değişmez. Yani Gauss, $n$'e bağlı bir işi sabite indirmiştir.

### 2.2 Faktöriyel ve Stirling formülü

Sonra hoca "Gauss'u biraz zorlayalım" diyerek çarpımı sordu: $1\cdot 2\cdot 3 \cdots n$. Öğrenciler bunun $n!$ olduğunu söyledi. Hoca bunun bir formül değil, faktöriyelin tanımı olduğunu belirtti ve şu yaklaşık formülü yazdı (ekrandan, 00:15:00):

$$n! \approx \sqrt{2\pi n}\left(\frac{n}{e}\right)^n$$

Buradaki $\approx$ işareti "yaklaşık" demektir; Gauss formülündeki gibi tam bir eşitlik yoktur. $e$, 2,7 diye giden bilinen sayıdır. Bu formül, bulan kişinin adıyla Stirling formülü olarak bilinir. Hoca, formülün düzeltme katsayılı daha ayrıntılı halleri olduğunu, derste ham haline bakıldığını söyledi.

### 2.3 Formülün maliyeti nerede?

Hoca formülü işlem sayısı açısından inceledi:

- $\sqrt{2\pi n}$ kısmı sabittir (tahtada "sabit" diye işaretlendi). $n$ ile $\pi$ çarpılır, 2 ile çarpılır, karekök alınır: üç işlem. $n$ büyüdükçe bu işlem sayısı değişmez.
- $n/e$ tek bir bölmedir.
- Asıl değişken kısım $\left(\frac{n}{e}\right)^n$, yani "bir şeyin $n$. kuvveti"dir. $x^n$ bulmak için $x$ kendisiyle çarpıla çarpıla gidilir: $x^n = x\cdot x \cdots x$, toplam $n$ çarpma (ekrandan, 00:15:00).

Bu durumda formül bize ne kazandırır? $n!$'i tanımıyla hesaplamak zaten $n$ çarpma demektir. Formül de $x^n$ yüzünden $n$ işlem ister. Bu bakışla formül kazanç sağlamıyormuş gibi görünür.

Fakat hoca işin güzel bir tarafı olduğunu söyledi: $x^n$ değeri $n$ adımda değil, $\log_2 n$ adımda bulunabilir. Bu yöntem ileride özyinelemeli (recursive) algoritmalar işlenirken görülecek. $n$'den $\log_2 n$'e geçiş büyük kazançtır: 1000 adım yerine yaklaşık 10 adım, 1 milyon adım yerine yaklaşık 20 adım atılır. Bu yöntemle birlikte Stirling formülü, yaklaşık bir değer verse de, işlem sayısını çok azaltır.

> **Hocanın vurgusu:** Eşittir ile yaklaşık işaretine dikkat edin. Stirling formülü tam sonuç vermez, ama oldukça iyi bir indirgeme sağlar.

> **Ders sonrası not:** Python ile kontrol edildi: Stirling formülü $n = 10$ için gerçek değerin yaklaşık %99,2'sini, $n = 100$ için yaklaşık %99,9'unu veriyor. $\log_2 1000 \approx 9{,}97$ ve $\log_2 10^6 \approx 19{,}93$; hocanın verdiği 10 ve 20 adım bununla uyumlu.

## 3. Akış Diyagramı Gösterimi ve $x^n$ Algoritması

### 3.1 Tahtada kullanılan gösterim

Derste çizilen akış diyagramlarında şu şekiller kullanıldı (ekrandan, 00:30:00, 00:50:00):

- **START / STOP:** oval içine yazılır. Her algoritma START ile başlar, STOP ile biter.
- **Okuma (giriş):** üst kenarı eğik bir kutu; kullanıcıdan alınan değişkenler içine yazılır (örneğin `x, n`).
- **Yazdırma (çıkış):** alt kenarı dalgalı, belge biçiminde bir kutu.
- **İşlem:** dikdörtgen kutu (örneğin `y = y * x`).
- **For döngüsü:** iki katlı kutu. Üst katta başlangıç değeri ve artış miktarı `i ← 1 || 1` biçiminde, alt katta bitiş değeri (`N`) yazılır. Hoca, artış miktarına $-1$, 5 ya da başka bir değer de yazılabileceğini sonradan ayrıca açıkladı.
- **Bağlantı dairesi:** döngü gövdesinin sonu numaralı bir daireyle (1, 2, 3) döngü kutusuna geri bağlanır.
- **Karar:** altıgen kutu; çıkışlar T (true) ve F (false) diye işaretlenir. Karşılaştırmada atamayla karışmasın diye `==` yazılır.

### 3.2 $x^n$ algoritması ve ilk hata

$x^n$'i bulan algoritma birlikte çizildi. START ile başlandı. $x$ ve $n$'in değerleri algoritmaya yazılabilirdi, ama daha mantıklısı kullanıcıdan okumaktır; bu yüzden `x, n` okundu. $x$ kendisiyle $n$ kez çarpılacağı için $i$ 1'den $n$'e birer birer giden bir döngü açıldı. Hoca döngü içine önce `x = x * x` yazdı ve sonunda `x`'i yazdırıp STOP koydu.

Bir öğrenci burada sürekli karesinin alındığını fark etti. Gerçekten de `x = x * x` her adımda $x$'in karesini alır: $x, x^2, x^4, x^8, \dots$ diye gider, $x^n$ vermez. Çözüm, sonucu ayrı bir değişkende biriktirmektir:

- Önce `K = 0` önerildi. Bu da yanlıştır, çünkü sıfırla çarpılan her şey sıfır kalır.
- Doğrusu `K = 1` ile başlamaktır. Döngüde `K = K * x` yapılır ve sonunda `K` yazdırılır.

```text
START
okut: x, n
K = 1
i <- 1 || 1 ... n:
    K = K * x
yaz: K
STOP
```

<!-- BELİRSİZ: x^n akış diyagramının son hali hiçbir karede görünmüyor (00:20:00 karesinde yalnız START var, 00:25:00 karesinde yeni sayfa açılmış); yukarıdaki yapı altyazıdaki anlatımdan kuruldu. -->

Hoca bunu bir hile değil, "dikkat edilmesi gereken bir kısım" olarak niteledi: biriktirme yapılan değişkenin ilk değeri işlemin etkisiz elemanı olmalıdır (çarpmada 1, toplamada 0).

## 4. $\pi$'yi Seri ile Hesaplamak

### 4.1 Seri

Hoca yeni bir yaklaşık formül yazdı ve neyin yaklaşığı olduğunu sordu (ekrandan, 00:25:00):

$$4 - \frac{4}{3} + \frac{4}{5} - \frac{4}{7} + \frac{4}{9} - \dots \approx\ ?$$

Payların hepsi 4'tür, paydalar 1, 3, 5, 7, 9 diye gider, işaretler bir artı bir eksi değişir. Sohbetten bir öğrencinin yazdığı cevap doğruydu: bu seri $\pi$'ye yaklaşır. Hoca böylece bilgisayarlarda $\pi$'nin nasıl hesaplandığının görüldüğünü söyledi. $\pi$ sabit, bilinen bir sonlu değer değildir; böyle bir seriyle hesaplanır. Ne kadar çok terim alınırsa (terim sayısı $N$ büyüdükçe) gerçek değere o kadar yaklaşılır. Gerçek değerin sonu olmadığı için bir noktada "bu kadarı yeter" denir.

### 4.2 Analiz

Algoritma START ile başlar. Kullanıcıdan alınacak bir şey var mı? Bir öğrencinin dediği gibi, $\pi$'nin ne kadar doğru hesaplanacağına kullanıcı karar verir; bu yüzden terim sayısı $N$ okunur. Sonra $N$ kez işlem yapacak bir döngü açılır: `i ← 1 || 1`, bitiş $N$.

Hoca iki gözlem yaptı (ekrandan, 00:30:00):

- **4'leri en sonda çarpmak:** Bütün paylar 4 olduğu için toplam en sonda 4 ile çarpılabilir. Böylece döngü içinde yalnız $1/\text{payda}$ terimleri düşünülür.
- **Payda:** $i$ ile payda arasındaki ilişki bir tabloyla bulundu:

| $i$ | payda |
|---|---|
| 1 | 1 |
| 2 | 3 |
| 3 | 5 |
| 4 | 7 |
| $i$ | $2i - 1$ |

- **İşaret:** $i$ tekse terim eklenir (artı), $i$ çiftse çıkarılır (eksi).

### 4.3 If ile çözüm

Toplam `P` değişkeninde tutulur ve döngüden önce `P = 0` yapılır. "i tek mi?" diye bir kutu algoritmaya doğrudan yazılamaz; bir öğrencinin önerdiği gibi 2'ye bölümden kalana bakılır: `i mod 2 == 1` ise sayı tektir.

```text
START
okut: N
P = 0
i <- 1 || 1 ... N:
    eğer i mod 2 == 1:
        P = P + 1/(2*i - 1)      (T dalı)
    değilse:
        P = P - 1/(2*i - 1)      (F dalı)
    (iki dal 1 numaralı bağlantıda birleşir, döngü başına döner)
yaz: 4*P
STOP
```

Bir öğrencinin "4 bölü olmayacak mı?" sorusuna hoca, 4 ile çarpmanın en sona bırakıldığını hatırlattı. Algoritma doğru yazılmışsa istenen kadar terimle $\pi$'ye istenen kadar yaklaşılabilir.

### 4.4 If'ten kurtulmak

Hoca bu kez if kullanmadan aynı işi yapmanın yolunu sordu. Öneriler tartışıldı:

- **$(-1)^i$ ile çarpmak:** Hoca bunun iyi bir fikir olmadığını söyledi: $(-1)^i$'yi her adımda hesaplamak için ayrıca 1'den $i$'ye bir döngü gerekir ve karmaşıklık $n^2$ mertebesine çıkar.
- **İki ayrı döngü:** Artı terimler için bir döngü, eksi terimler için bir döngü kurulabilir. Her biri $n/2$ adım sürer, karmaşıklık yine $n$ mertebesinde kalır, ama tek döngülü daha şık bir çözüm aranıyordu.
- **Her adımda $-1$ ile çarpmak:** Bir öğrenci, bir değişkenin her adımda $-1$ ile çarpılırsa artının eksiye, eksinin artıya döneceğini söyledi. Bu, $(-1)^i$'nin sonucunu tek işlemle verir.

Son öneriyle algoritma şöyle oldu:

```text
P = 0, e = 1
i <- 1 || 1 ... N:
    P = P + e * 1/(2*i - 1)
    e = e * (-1)
yaz: 4*P
```

İlk girişte `e = 1` olduğundan terim eklenir; sonra `e` $-1$ olur ve ikinci terim çıkarılır; sonra yine $+1$ olur. Artı, eksi, artı, eksi diye gider. Böylece if kullanmadan, küçük bir hileyle aynı sonuç elde edilir.

> **Ders sonrası not:** İki sürüm python ile karşılaştırıldı ve her $N$ için aynı sonucu verdi: $N = 5$ için $3{,}3397$, $N = 10$ için $3{,}0418$, $N = 1000$ için $3{,}14059$. Seri yavaş yakınsadığı için iyi bir yaklaşım çok terim ister.

## 5. $e^x$'i Seri ile Hesaplamak ve $n^2$'den $n$'e İnmek

### 5.1 Seri ve karmaşıklık

Yeni yaklaşık formül (ekrandan, 00:40:00):

$$e^x = 1 + \frac{x}{1} + \frac{x^2}{2!} + \frac{x^3}{3!} + \dots$$

Hoca bu açılımın Taylor serilerinden geldiğini, dersin sayfasında bununla ilgili notlar bulunacağını söyledi.

Karmaşıklık incelendi. $n$ terim vardır. Her terimin içinde ise $x^i$ ve $i!$ hesapları vardır; $i$. terim için payda $i$, paydada da $i$ işlem gerekir. Son terim $\frac{x^n}{n!}$ için yaklaşık $2n$ işlem eder. Hoca kabaca $n$ terim ve terim başına $2n$ işlemden $2n^2$ çıkardı ve sabit çarpanın önemsiz olduğunu, bunun $n^2$ mertebesinde bir karmaşıklık olduğunu söyledi (ekrandan, 00:50:00: $(2n)n$, $2n^2$, $n^2$).

Bir önceki $\pi$ algoritmasında her terim tek bir işlemle bulunuyordu, döngü içinde başka döngü yoktu. Burada ise her terim için hem $x^i$ hem $i!$ hesaplanacağından iç içe döngüler gerekecek.

### 5.2 İlk çözüm: iç içe döngüler

Kullanıcıdan $x$ ve $n$ okunur. Toplam `E` değişkeninde tutulur. İlk terim 1 olduğundan `E = 1` ile başlanır ve dış döngü ikinci terimden devam eder (ekrandan, 00:50:00):

```text
START
okut: x, n
E = 1
i <- 1 || 1 ... n-1:          (bağlantı 1)
    y = 1
    j <- 1 || 1 ... i:
        y = y * x             (x^i)
    A = 1
    j <- 1 || 1 ... i:
        A = A * j             (i!)
    E = E + y/A
yaz: E
STOP
```

Derste bu çizilirken birkaç noktaya dikkat çekildi:

- İç döngüde artık `i` kullanılamaz, çünkü dış döngünün değişkenidir; bu yüzden `j` kullanıldı. İkinci iç döngü birinci bittikten sonra başladığı için `j` yeniden kullanılabilir.
- $x^i$ için döngüde `y = y * x` yazılır. Bir öğrenci `y = y * j` önerdi; hoca bunun yanlış olduğunu, $x^i$ için $x$ ile çarpılması gerektiğini gösterdi. Faktöriyel döngüsünde ise doğrusu `A = A * j`'dir.
- **Soru:** İlk döngü $n$'e kadar gidiyor ama `E` zaten 1 ile başladı; bir adım fazla gitmiyor mu? **Cevap:** Hoca haklı olduğunu söyledi; ilk terim baştan eklendiği için dış döngünün bitişi $n-1$ yapıldı. Böylece toplam $n$ terim hesaplanır.

### 5.3 Ara adım: iki iç döngüyü birleştirmek

Bir öğrenci iki iç döngünün tek döngüde birleştirilebileceğini söyledi: `y = y * x` ve `A = A * j` aynı `j` döngüsünde yapılabilir. Hoca bunu uyguladı: iş biraz basitleşti, sonuç aynı kaldı. Ama hâlâ iç içe iki döngü vardır ve iç içe döngülerde işlem sayısı kabaca döngü uzunluklarının çarpımıdır. Dış döngü $n$, iç döngü ortalama $n/2$ adım gittiği için karmaşıklık yine $n \cdot n/2$, yani $n^2$ mertebesindedir.

Bir öğrencinin `y` yerine $x/(n-j)$ ile çarpma önerisi de aynı nedenle reddedildi: iç içe iki döngü kaldığı sürece karmaşıklık değişmez.

### 5.4 Tek döngüye inmek

Asıl istenen tek döngüydü. Bir öğrenci, her adımda payın yalnız bir kez $x$ ile, paydanın da yalnız bir kez çarpılabileceğini söyledi. Hoca bunu şöyle formüle etti (ekrandan, 01:00:00):

$$x^n = x \cdot x^{n-1}, \qquad n! = n \cdot (n-1)!$$

Yani bir önceki adımda bulunmuş $x^{i-1}$ ve $(i-1)!$ değerleri saklanırsa, yeni terimin payı için bir çarpma, paydası için bir çarpma yeter. Bunun için `A = 1` ve `y = 1` döngüden önce bir kez verilir ve döngü içinde sıfırlanmaz:

```text
START
okut: x, n
E = 1, A = 1, y = 1
i <- 1 || 1 ... n-1:
    y = y * x
    A = A * i
    E = E + y/A
yaz: E
STOP
```

Artık iç döngüde kullanılan `j` yoktur; faktöriyel için dış döngünün `i`'si kullanılır.

Bu çözüm öğrencilerle uzun uzun tartışıldı:

- **Soru:** Her adımda toplama yapıyoruz, bu yanlış olmaz mı? **Cevap:** Her adımda bir terim eklenmesi zaten istenen şeydir. `y` her adımda $x$ ile, `A` her adımda $i$ ile çarpılır; `y/A` o adımın terimidir ve `E`'ye eklenir.
- Bir öğrenci her adımda fazladan 1 eklendiğini düşündü; incelemede 1'in yalnız başta `E = 1` ile eklendiği, döngüde tekrar eklenmediği görüldü.
- **Soru:** Neden $n$ adım değil $n-1$ adım? **Cevap:** Başta 1 terimi ayrıca eklendi. İstenen toplamın tamamına $n$ terim dersek, ilk terim 1 ve geri kalan $n-1$ terim döngüde hesaplanır. Hoca bunun çok önemli bir ayrıntı olmadığını, döngü $n$'e kadar giderse bir terim fazla hesaplanacağını söyledi.
- Bir öğrenci $x = 2$ için elle iz sürdü (ekrandan, 01:00:00, "x = 2"). İlk adımda `y = 2`, `A = 1`, terim $2/1$. Sonraki adımda paydan $x^2$'ye geçmek için bir kez daha $x$ ile, paydayı $2!$'e geçmek için 2 ile çarpmak gerekir; algoritma tam bunu yapar.

Tek döngüyle karmaşıklık $n$ oldu. Hoca tahtaya $n^2 \to n$ yazıp bir gülen yüz çizdi ve $n^2$'den $n$'e inmenin çok büyük bir başarı olduğunu söyledi.

> **Hocanın vurgusu:** $n^2$'den $n$'e inebilmek çok güzel bir sonuçtur. İç içe döngüler varsa işlem sayısı kabaca döngü uzunluklarının çarpımı kadardır.

> **Ders sonrası not:** İlk çözüm ve tek döngülü çözüm python ile karşılaştırıldı ve aynı sonucu verdi: $x = 2$, $n = 3$ için $1 + 2 + 2 = 5$; $n = 4$ için $1 + 2 + 2 + \tfrac{8}{6} \approx 6{,}333$; $n = 20$ için $7{,}389056$, bu da $e^2$ ile aynı.

## 6. $n$. Fibonacci Sayısı: Diziden Sabit Belleğe

### 6.1 Tanım ve dizili çözüm

Aradan sonra klasik bir problemle devam edildi: $n$. Fibonacci sayısını bulmak (ekrandan, 01:25:00).

$$f(1) = 1, \quad f(2) = 1, \quad f(n) = f(n-1) + f(n-2)$$

Her terim kendinden önceki iki terimin toplamıdır: 1, 1, 2, 3, 5, 8, 13, 21, ...

İlk algoritmada bir `F` dizisi kullanıldı:

```text
START
okut: N
F(1) = 1, F(2) = 1
i <- 3 || 1 ... N:
    F(i) = F(i-1) + F(i-2)
yaz: F(N)
STOP
```

Algoritma basittir ama bir sorunu vardır: 1 milyonuncu Fibonacci sayısı için bellekte 1 milyon elemanlık bir dizi açmak gerekir. Bu iyi bir şey olmayabilir.

### 6.2 Dizisiz çözüm: üç değişken

Hoca problemi dizi kullanmadan, sabit sayıda değişkenle çözmeyi sordu. Amacın daha hızlı çözmek olmadığını, hatta biraz daha yavaş bile olabileceğini, burada amacın yerden tasarruf etmek olduğunu açıkça söyledi.

Bir öğrenci üç değişken önerdi: `T`, `E`, `K`. Başlangıç değerleri `T = 0`, `E = 1`, `K = 1`; döngüde (ekrandan, 01:35:00):

```text
T = 0, E = 1, K = 1
i <- 3 || 1 ... N:
    T = K + E
    E = K
    K = T
yaz: T
```

Hoca değişkenlerin anlamını açıkladı: `T` o anki Fibonacci sayısıdır ($f(n)$), `K` bir öncekidir ($f(n-1)$), `E` iki öncekidir ($f(n-2)$). Yeni sayı bulunduktan sonra `E = K` ve `K = T` ile bir sonraki adım için değişkenler hazırlanır.

> **Hocanın vurgusu:** Bu çözüm zamandan kazandırmaz; iki tarafta da $n$ çarpı sabit sayıda işlem vardır. Kazanç bellektedir: $n$ büyüklüğünde bir bellek yerine sabit büyüklükte bir bellekle problem çözüldü.

### 6.3 Kullanıcı girişleri ve ilk değerler

- **Soru:** $N = 1$ girilirse sonuç yanlış olmuyor mu? **Cevap:** Evet. `T = 0` ile başlandığı ve döngü 3'ten başladığı için döngüye hiç girilmez ve birinci Fibonacci sayısı 0 çıkar. Birinci ve ikinci sayı için bir if ile doğrudan geçiş yapılabilir. Hoca, genelde birinci ya da ikinci Fibonacci sayısının sorulmayacağını ama kullanıcının $N$ için 1, hatta $-1$ gibi düşünülmemiş değerler de girebileceğini, bunlar için ek kontroller gerekebileceğini söyledi.
- **Soru:** `T`'ye 0 atamasak da olur muydu? **Cevap:** Döngüye en az bir kez girileceği varsayılırsa olur, çünkü `T` ilk kullanımında `T = K + E` ile atanır. Ama döngüye girilmeden çıkılırsa `T`'nin bellekte o an ne değeri varsa o yazdırılır. Bu yüzden `T`'ye bir değer vermek daha güvenlidir. `E` ve `K`'ya değer vermemek ise kesinlikle tehlikelidir, çünkü ilk kullanımlarında okunurlar.

> **Hocanın vurgusu:** Pratik olarak değişkenlere ilk değeri kendiniz atayın. Bellekteki rastgele değerleri kullanmak bazı durumlarda sorun çıkarır.

### 6.4 İki değişkenli çözüm

Bir öğrenci iki değişkenin de yeteceğini söyledi: `S` (second) ve `F` (first), ikisi de 1 ile başlar; döngüde (ekrandan, 01:35:00):

```text
S = 1, F = 1
i <- 3 || 1 ... N:
    S = S + F
    F = S - F
yaz: S
```

`S = S + F` yeni sayıyı verir; `F = S - F` ise yeni `S`'den eski `F`'yi çıkararak eski `S`'yi geri elde eder. Hoca algoritmanın doğruluğunu bir iz sürme tablosuyla gösterdi (ekrandan, 01:35:00):

| $i$ | $S$ | $F$ |
|---|---|---|
| başlangıç | 1 | 1 |
| 3 | 2 | 1 |
| 4 | 3 | 2 |
| 5 | 5 | 3 |
| 6 | 8 | 5 |

Görüldüğü gibi $i$. Fibonacci sayısı her zaman `S`'nin içindedir; sonunda `S` yazdırılır. Hoca bu çözümün daha hızlı olduğunu söylemenin mümkün olmadığını, ama daha az değişken kullandığı için belleği biraz daha iyi kullandığını belirtti.

Hoca, bütün bu çözümlerin hâlâ $n$ adım sürdüğünü, $n$. Fibonacci sayısını $n$'den daha kısa sürede hesaplamanın ileride özyinelemeli algoritmalarla görüleceğini söyledi.

> **Ders sonrası not:** Üç algoritma python ile çalıştırıldı. $n \ge 3$ için üçü de 2, 3, 5, 8, 13, 21, ... değerlerini veriyor. Üç değişkenli sürüm $n = 1$ ve $n = 2$ için 0 veriyor; iki değişkenli sürüm bu değerlerde döngüye girmediği halde doğru sonuç olan 1'i veriyor.

## 7. Basamak Küpleri Toplamı Kendine Eşit Sayılar

### 7.1 Problem

Soru: 1 ile 1000 arasında, basamaklarının küpleri toplamı kendisine eşit olan sayıları bulun (ekrandan, 01:40:00). İki basamaklı $ab$ sayısı için koşul

$$a^3 + b^3 = 10a + b,$$

üç basamaklı $abc$ sayısı için

$$a^3 + b^3 + c^3 = 100a + 10b + c$$

olur. Sohbette bir öğrenci bunların Armstrong sayıları diye bilindiğini yazdı. **Soru:** Verilen bir sayının bu özellikte olup olmadığına mı bakıyoruz, yoksa hepsini mi yazdırıyoruz? **Cevap:** 1'den 1000'e kadar bu özellikteki bütün sayılar yazdırılır.

### 7.2 Algoritma

Aralık problemde verildiği için kullanıcıdan bir şey okunmaz. Her sayı tek tek ele alınır, basamaklarına erişilir, basamakların küpleri toplanır ve sayının kendisiyle karşılaştırılır.

Hoca işi kolaylaştırmak için bir sadeleştirme yaptı: 1000'in kendisi bu özellikte değildir ve iki basamaklı böyle bir sayı yoktur. Bu yüzden döngü 100'den 999'a kurulabilir ve her sayının tam üç basamağı olur (ekrandan, 01:40:00: `i ← 100 || 1`, bitiş 999). Hoca bu varsayımın ancak bu bilgi bilindiğinde yapılabileceğini vurguladı.

### 7.3 Basamaklara erişmek

Basamaklar `y` (yüzler), `o` (onlar), `b` (birler) diye adlandırıldı. Örnek sayı 845 alındı.

- **Yüzler basamağı:** Bir öğrenci "div 100" önerdi; hoca algoritmada böyle bir işlem olmadığını söyledi. $845/100 = 8{,}45$ olur; bunun aşağı yuvarlanması gerekir. Algoritmalarda aşağı yuvarlama $\lfloor\ \rfloor$, yukarı yuvarlama $\lceil\ \rceil$ ile gösterilir:

$$y = \left\lfloor \frac{i}{100} \right\rfloor$$

- **Soru:** Kodlamada tam bölme diye bir şey vardı, onu kullanamaz mıyız? **Cevap:** Burada kod açısından düşünülmüyor. Algoritma programlama dilinden bağımsız ifade edilmelidir; dillerde bunun için pek çok fonksiyon vardır ama burada mümkün olduğunca basit, genel bir yapı kurulur.
- **Onlar basamağı:** Doğrudan 10'a bölmek $84{,}5$ verir. Bir öğrencinin önerisiyle önce yüzler basamağının katkısı çıkarılır, sonra 10'a bölünüp aşağı yuvarlanır: $(845 - 800)/10 = 4{,}5 \to 4$.

$$o = \left\lfloor \frac{i - 100\,y}{10} \right\rfloor$$

- **Birler basamağı:** $b = i \bmod 10$.

Sonra bir karar kutusunda `y^3 + o^3 + b^3 == i` sorulur. True ise `i` yazdırılır; false ise bir şey yapılmaz. İki dal bağlantı noktasında birleşir, döngü bitince STOP. Hoca basamaklara erişmenin başka yollarının da bulunabileceğini söyledi.

<!-- BELİRSİZ: Armstrong akış diyagramının tamamlanmış hali karelerde görünmüyor (01:40:00 karesinde yalnız döngü kutusu ve y, o, b başlıkları var, 01:45:00 karesinde tahta temizlenmiş); basamak formülleri altyazıdaki anlatımdan yazıldı. -->

> **Ders sonrası not:** Python ile 100-999 arasında bu özellikte 153, 370, 371 ve 407 sayıları bulundu. 845 için formüller $y = 8$, $o = 4$, $b = 5$ veriyor. İki basamaklı böyle sayı yok; hocanın sadeleştirmesi doğru.

Hoca ayrıca, aralığın 1000 yerine kullanıcının verdiği bir sınıra kadar olması halinde algoritmanın nasıl yazılacağını öğrencilere çalışma olarak bıraktı ve bunun derstekinden daha zor olacağını söyledi.

## 8. Hangi Döngü: For mu While mı?

Hoca kısa sorularla döngü seçimini tartıştı:

- **Bir sayının dizide ilk geçtiği yer:** while. Bulunduğu anda durulur.
- **İkinci geçtiği yer:** yine while.
- **Son geçtiği yer:** Dizinin sonuna kadar gitmek gerektiği için for. Bir öğrencinin dediği gibi dizi tersten taranırsa ilk bulunan yer son geçtiği yerdir; o zaman while da kullanılabilir.
- **Bütün geçtiği yerler:** Dizinin tamamı taranacağı için for.

## 9. Önermeler, Karşıt Örnekler ve Bilgisayarla Arama

### 9.1 $n^2 + n + 41$ önermesi

Hoca matematiksel bir önerme yazdı (ekrandan, 01:50:00):

$$\forall n \in \mathbb{N}^+,\quad n^2 + n + 41 \text{ asaldır.}$$

İlk değerler denendi:

- $n = 1$: $1 + 1 + 41 = 43$, asal.
- $n = 2$: $4 + 2 + 41 = 47$, asal.
- $n = 3$: $9 + 3 + 41 = 53$, asal.

Önerme doğru mu? Bir öğrenci $n = 41$ için ifadenin $41\cdot 43$ olduğunu, yani asal olmadığını söyledi. Hoca ifadeyi $n(n+1) + 41$ diye yazdı ve daha küçük bir değerin de işe yaradığını gösterdi: $n = 40$ için

$$40 \cdot 41 + 41 = 41 \cdot 41 = 1681,$$

bu da asal değildir. Demek ki önerme $n = 40$ için yanlıştır, dolayısıyla önerme yanlıştır.

Hoca bunu birazcık düşünerek, matematikle bulduklarını söyledi. Matematik kullanmadan, bilgisayarın gücüyle (brute force) çözmek isteseydik: $n$ 1'den başlatılır, yeterince büyük bir sayıya kadar artırılır, her $n$ için $n^2+n+41$ hesaplanır ve asal olup olmadığı kontrol edilir. Asalsa devam edilir, asal değilse çıkılır. Herhangi bir anda çıkılacağı için burada for yerine while kullanmak daha anlamlıdır.

> **Ders sonrası not:** Python ile kontrol edildi: $n = 1$'den $39$'a kadar değerlerin hepsi asal; $n = 40$ için $1681 = 41^2$ ve $n = 41$ için $1763 = 41 \cdot 43$ asal değil.

### 9.2 $a^4 + b^4 + c^4 = d^4$ önermesi

İkinci önerme (ekrandan, 01:55:00):

$$\neg \exists\, a, b, c, d \in \mathbb{N}^+ : \ a^4 + b^4 + c^4 = d^4$$

Yani bu denklemin pozitif doğal sayılarda çözümü yoktur. Önermeyi yanlışlamak için bu eşitliği sağlayan $a, b, c, d$ değerlerini bulmak gerekir. Sohbette önerilen 0 değeri, sayılar pozitif olduğu için geçersizdir; 1'lerle de olmaz.

Bunu yukarıdaki gibi elle analiz etmek çok zordur. Bilgisayarla aramak için bir algoritma kuruldu:

- Bir üst sınır gerekir; sonsuza kadar gidilemez. Örneğin kullanıcıdan bir $n$ (1 milyon gibi) okunur.
- $a$, $b$, $c$, $d$ için 1'den $n$'e giden dört iç içe döngü kurulur (ekrandan, 01:55:00).
- En içte `a^4 + b^4 + c^4 == d^4` kontrol edilir.

Bir öğrenci $d$'nin ayrıca aranmasına gerek olup olmadığını sordu. Hoca, $d$'nin diğer üçünden doğrudan çıkarılamayacağını, bu yüzden dördüncü döngünün gerektiğini söyledi. Başka bir öğrenci, $a^4+b^4+c^4$ toplamının dördüncü dereceden kökünü alıp tam sayı olup olmadığına bakmayı önerdi; hoca bunun da doğru olduğunu, ama dördüncü dereceden kökün nasıl hesaplanacağının ayrı bir algoritma olduğunu söyledi ve öğrenciye bunu araştırmasını önerdi. Bir başka öneri for'lar yerine while kullanmaktı; hoca bunun daha mantıklı olduğunu, çünkü çözüm bulunduğu anda dışarı çıkılacağını söyledi.

Hoca bu önermenin yanlış olduğunu açıkladı. Denklemin bir çözümü vardır (ekrandan, 02:00:00):

$$a = 95800,\quad b = 217519,\quad c = 414560,\quad d = 422481$$

Bu karşıt örnek ancak 1988'de bulunabilmiştir. Neden bu kadar gecikti? Öğrencilerin dediği gibi bilgisayarların bulunması ve epey hızlanması gerekiyordu. Sayılar 400 bin civarındadır; dört iç içe döngüde yaklaşık 500 bin çarpı 500 bin çarpı 500 bin çarpı 500 bin mertebesinde işlem gerekir. Bir insan ömrü boyunca uğraşsa bunu elle bulamaz.

> **Hocanın vurgusu:** Bir önermenin doğru olduğunu göstermek için çalışan binlerce örneğe güvenemeyiz. Örneğin bu önerme 400 küsur bine kadar denenen trilyonlarca örnekte tutuyordu. Yanlış olduğunu göstermek için tek bir karşıt örnek yeter; doğru olduğunu göstermek için ispat gerekir.

> **Ders sonrası not:** $95800^4 + 217519^4 + 414560^4 = 422481^4$ eşitliği python'da tam sayı aritmetiğiyle doğrulandı.

> **Ek bilgi (derste anlatılmadı):** Bu önerme Euler'in kuvvet toplamları sanısının $k = 4$ durumudur. İlk karşıt örneği büyük olasılıkla 1986-1988 yıllarında Noam Elkies bulmuş, derste verilen en küçük çözümü ise büyük olasılıkla 1988'de Roger Frye bilgisayar aramasıyla bulmuştur.

### 9.3 Goldbach önermesi

Üçüncü önerme (ekrandan, 02:05:00):

> 2 haricindeki her çift sayı iki asal sayının toplamıdır.

Örnekler:

- $8 = 5 + 3$
- $18 = 13 + 5 = 11 + 7$
- $46 = 41 + 5$

Hoca 13 ve 43 gibi tek sayılar sorduğunda öğrenciler bunların çift olmadığını hatırlattı. Bir öğrenci 4'ün iki asalın toplamı olmadığını düşündü; ama $4 = 2 + 2$'dir ve önerme iki "farklı" asal demez. 2'nin kendisi önermeden hariç tutulur, çünkü 1 asal değildir ve 2 iki asalın toplamı olarak yazılamaz. 2, toplamda asal sayı olarak kullanılabilir.

Hoca öğrencilere karşıt örnek bulmaları için 5 dakika verdi. Bu sürede internete bakan öğrencilere kendi kafalarını kullanmalarını söyledi: her şeyde internete başvurulursa internette olmayan problemler çözülemez.

Süre sonunda bir öğrenci 18 basamaklı, bütün basamakları 2 olan sayıyı önerdi; bu sayının 3'e, 7'ye, 11'e bölünecek biçimde seçildiğini anlattı. Hoca iki noktaya dikkat çekti:

- Bir sayının çok sayıda bölenin olması, iki asalın toplamı olmadığını göstermez.
- Bu sayının iki asalın toplamı olduğunu biliyordu, ama hangi iki asal olduğunu bilmiyordu.

Bunu nasıl söyleyebildiğini şöyle açıkladı: bu önermenin bugün doğru mu yanlış mı olduğu bilinmemektedir. Durumu, $a^4+b^4+c^4=d^4$ önermesinin 1988 öncesindeki durumuna benzer: ne bir karşıt örnek bulunmuştur ne de doğru olduğunu gösteren bir ispat. Önerilen gibi bir sayı büyük olasılıkla zaten test edilmiş sayılar arasındadır. Günün birinde tek bir karşıt örnek bulunursa önerme yanlış olacaktır.

> **Ders sonrası not:** Python ile (Miller-Rabin asallık testiyle) kontrol edildi: $222222222222222222 = 79 + 222222222222222143$ ve iki sayı da asal. Yani önerilen sayı gerçekten iki asalın toplamı; hocanın öngörüsü doğru.

> **Ek bilgi (derste anlatılmadı):** Bu önerme Goldbach sanısı olarak bilinir ve 1742'den beri açıktır. Büyük olasılıkla $4 \times 10^{18}$'e kadar bütün çift sayılar için bilgisayarla doğrulanmıştır; öğrencinin önerdiği yaklaşık $2{,}2 \times 10^{17}$ büyüklüğündeki sayı bu aralığın içindedir.

### 9.4 Algoritma yazmak ispat demek değildir

**Soru:** Bu önermeyi araştıran bir algoritma yazılabilirse önerme zaten ispatlanmış olmaz mı? **Cevap:** Hayır. Örneğin dört sayıyı arayan algoritma yazıldı; ama algoritmayı yazmak önermeyi doğrulamak ya da yanlışlamak demek değildir. Algoritma belli bir $n$'e kadar çalıştırılır ve o sınıra kadarki sonuca bakılır. Karşıt örnek bulursa önermenin yanlış olduğu gösterilmiş olur; bulamazsa önermenin doğru olduğu söylenemez. Algoritma, önermenin doğru mu yanlış mı olduğunu anlamak için yazılır.

### 9.5 Goldbach'ı araştıran algoritma taslağı

Öğrencilerle bir algoritma kurulmaya çalışıldı. İlk öneri, $i$ 1'den sonsuza giden bir döngü ve içinde $j$ ve $k$ döngüleriydi. Hoca bitiş değerine sonsuz yazılamayacağını, yoksa alttaki döngülerin hiç bitmeyeceğini söyledi. Öneriler gelişti: $j$ 1'den $i$'ye, $k$ 1'den $i - j$'ye gitsin; sonra $k = i - j$ zaten hesaplanabildiği için $k$ döngüsüne gerek olmadığı görüldü (ekrandan, 02:20:00). Hoca, kafasında çizdiğini söyleyen bir öğrenciye algoritmayı önce kâğıda tam çizmesini, sonra konuşmalarını söyledi.

Kolaylık olsun diye asal sayıların bir `AS[1..N]` dizisinde hazır olduğu varsayıldı. Bir öğrencinin önerdiği taslak şöyle çizildi (ekrandan, 02:25:00):

```text
START
x <- 2 || 2 ... N:                (bağlantı 3)
    i <- 1 || 1 ... AS[x]:        (bağlantı 2)
        j <- 1 || 1 ... AS[x]:    (bağlantı 1)
            eğer x == AS[i] + AS[j]:
                (T) bir sonraki x'e geç
```

Öğrencinin ilk fikri iç döngünün `AS[i]` değeri $x$'i geçene kadar sürmesiydi; hoca basitlik için bitişi `AS[x]` yaptı ve bunun biraz fazla işlem yapacağını ama büyük bir sorun olmadığını söyledi. Tartışmada şunlar ortaya çıktı:

- Eşitlik bulunduğu anda döngülere devam etmenin anlamı kalmaz; bu yüzden aslında for'lar yerine while'lar gerekir.
- Tek bir $(i, j)$ ikilisi için eşitliğin tutmaması, hiçbir ikili için tutmadığı anlamına gelmez. Karşıt örnek ancak bütün ikililer denenip hiçbiri tutmazsa bulunmuş olur. Bunun için ek bir kontrol gerekir; derste bu kısım tamamlanmadı ve hoca algoritmayı tamamlamayı öğrencilere çalışma olarak bıraktı.

Hoca, asal sayılar dizisinin elde olduğunu varsaymanın başlangıç için iyi bir sadeleştirme olduğunu söyledi. Dizi yoksa en makulü önce asal sayılar dizisini oluşturan ayrı bir algoritma yazmak, sonra bu diziyi bu problemde kullanmaktır. Her sayının asal olup olmadığını döngünün içinde tekrar tekrar kontrol etmek işi çok uzatır.

## 10. Algoritma Geliştirme İteratif Bir Süreçtir

Hoca dersi, algoritmaları neden yaza boza, tahtada çizerek anlattığını açıklayarak kapattı. Algoritma geliştirmek iteratif bir süreçtir. Tek seferde mükemmel bir algoritma çıkarmak beklenmemelidir. Önce çok basit, kötü ama problemi çözen bir şey yapılır; sonra memnun olunmayan yerleri bulunur ve iyileştirilir. Bu sırada yanlışlar yapmak doğaldır; hoca kendisinin de yaptığını söyledi. Bu derste $x^n$, $\pi$, $e^x$ ve Fibonacci algoritmalarında bu süreç adım adım görüldü.

**Soru:** Derste cevabı tam bulunamayan algoritmaların çözümü sonradan verilecek mi? **Cevap:** Hayır; öğrencilerin bunları kendilerinin tamamlaması beklenir. Tamamlanan çözümler hocaya gönderilebilir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:25:00): $4 - \frac{4}{3} + \frac{4}{5} - \frac{4}{7} + \frac{4}{9} - \dots$ serisi neyin yaklaşık değeridir?

> **Çözüm (derste verildi):** $\pi$. Terim sayısı arttıkça $\pi$'ye yaklaşılır. Python ile $N = 1000$ terim için $3{,}14059$ bulunur.

**Soru 2** (derste sözlü, 00:19:38): Kullanıcıdan $x$ ve $n$ alıp $x^n$'i hesaplayan algoritmayı çizin.

> **Çözüm (derste verildi):** `K = 1`; $i$ 1'den $n$'e döngüde `K = K * x`; sonunda `K` yazdırılır. Döngüde `x = x * x` yazmak her adımda karesini alır ve yanlıştır; `K = 0` ile başlamak sonucu sıfır yapar.

**Soru 3** (derste sözlü, 00:32:07): $\pi$ algoritmasındaki `i mod 2` kontrolünü (if'i) kullanmadan işaret değişimini nasıl sağlarsınız?

> **Çözüm (derste verildi):** `e = 1` ile başlanır; döngüde `P = P + e * 1/(2*i-1)` ve ardından `e = e * (-1)`. $(-1)^i$'yi her adımda ayrı döngüyle hesaplamak karmaşıklığı $n^2$'ye çıkardığı için uygun değildir.

**Soru 4** (derste sözlü, 00:48:12): $e^x = 1 + x + \frac{x^2}{2!} + \dots$ serisini hesaplayan iç içe döngülü ($n^2$) algoritmayı tek döngüyle ($n$) yazabilir misiniz?

> **Çözüm (derste verildi):** $x^i = x\cdot x^{i-1}$ ve $i! = i\cdot (i-1)!$ olduğundan `E = 1, A = 1, y = 1` ile başlanır; $i$ 1'den $n-1$'e döngüde `y = y * x`, `A = A * i`, `E = E + y/A`. Python ile $x = 2$, $n = 20$ için $7{,}389056 \approx e^2$.

**Soru 5** (derste sözlü, 01:22:40): $n$. Fibonacci sayısını dizi kullanmadan, sabit sayıda değişkenle bulun.

> **Çözüm (derste verildi):** Üç değişkenle: `T = 0, E = 1, K = 1`; döngüde `T = K + E`, `E = K`, `K = T`. İki değişkenle: `S = 1, F = 1`; döngüde `S = S + F`, `F = S - F`. İkisi de $i$ 3'ten $n$'e döner. Bellek sabit, süre yine $n$ mertebesinde.

**Soru 6** (ekrandan, 01:40:00): 1 ile 1000 arasında, basamaklarının küpleri toplamı kendisine eşit olan sayıları yazdıran algoritmayı çizin.

> **Çözüm (derste verildi):** $i$ 100'den 999'a; $y = \lfloor i/100 \rfloor$, $o = \lfloor (i - 100y)/10 \rfloor$, $b = i \bmod 10$; $y^3 + o^3 + b^3 == i$ ise $i$ yazdırılır. Python ile bulunan sayılar: 153, 370, 371, 407.

**Soru 7** (derste sözlü, 01:44:41): Bir sayının bir dizide ilk, ikinci, son ve bütün geçtiği yerleri bulmak için for mu while mı kullanırsınız?

> **Çözüm (derste verildi):** İlk ve ikinci geçtiği yer için while; son geçtiği yer için for (ya da dizi tersten taranırsa while); bütün geçtiği yerler için for.

**Soru 8** (ekrandan, 01:50:00): "Her pozitif doğal $n$ için $n^2 + n + 41$ asaldır" önermesi doğru mudur?

> **Çözüm (derste verildi):** Yanlıştır. $n^2 + n + 41 = n(n+1) + 41$ olduğundan $n = 40$ için $40\cdot 41 + 41 = 41^2 = 1681$ asal değildir. ($n = 41$ için de $41 \cdot 43$.)

**Soru 9** (ekrandan, 01:55:00): "$a^4 + b^4 + c^4 = d^4$ denkleminin pozitif doğal sayılarda çözümü yoktur" önermesini bilgisayarla araştıran algoritma nasıl kurulur, önerme doğru mudur?

> **Çözüm (derste verildi):** Bir üst sınır $n$ okunur; $a$, $b$, $c$, $d$ için 1'den $n$'e dört iç içe döngü (bulunca çıkılacağı için tercihen while) ve en içte `a^4 + b^4 + c^4 == d^4` kontrolü. Önerme yanlıştır: $95800^4 + 217519^4 + 414560^4 = 422481^4$ (ekrandan, 02:00:00; python ile doğrulandı).

**Soru 10** (ekrandan, 02:05:00): "2 haricindeki her çift sayı iki asal sayının toplamıdır" önermesine bir karşıt örnek bulun.

> **Çözüm (derste verildi):** Bilinen bir karşıt örnek yoktur; önermenin doğru mu yanlış mı olduğu bugün bilinmemektedir. Derste önerilen, 18 basamağı da 2 olan sayı iki asalın toplamıdır; python ile $79 + 222222222222222143$ ayrışımı bulundu.

**Soru 11** (derste sözlü, 01:37:34): Basamak küpleri toplamı kendine eşit sayıları 1000 yerine kullanıcının verdiği bir sınıra kadar bulan algoritmayı yazın.

> **Çözüm (derste verilmedi):** Derste ödev olarak bırakıldı. Bir yol: sınır $M$ okunur; $i$ 1'den $M$'e döner; `t = i`, `s = 0`; `t > 0` olduğu sürece `s = s + (t mod 10)^3` ve `t = ⌊t/10⌋`; sonunda `s == i` ise `i` yazdırılır. Bu yol basamak sayısından bağımsızdır. Python ile $M = 10^5$ için 1, 153, 370, 371, 407 bulunur.

## Dersin Toparlaması

Bu derste algoritmaların işlem sayısı ve bellek ihtiyacı üzerinden nasıl karşılaştırılıp iyileştirileceği somut örneklerle görüldü. Gauss ve Stirling formülleri, bir formülün asıl kazancının işlem sayısını $n$'den sabite ya da $\log_2 n$'e indirmesinde olduğunu gösterdi. $\pi$ ve $e^x$ serilerinde akış diyagramları adım adım çizildi. $\pi$'de if yerine her adımda $-1$ ile çarpma kullanıldı. $e^x$'te önceki adımın sonucunu saklayarak iç içe döngülerden kurtulundu ve karmaşıklık $n^2$'den $n$'e indi. Fibonacci örneğinde zamandan değil bellekten kazanıldı: dizi yerine üç, sonra iki değişken yetti. Basamak küpleri örneğinde aşağı yuvarlama ve mod ile basamaklara erişildi.

Dersin ikinci yarısında önermeler ele alındı. Çalışan örnekler bir önermeyi kanıtlamaz; tek bir karşıt örnek onu yanlışlar. Bilgisayar, $a^4+b^4+c^4=d^4$ örneğinde olduğu gibi elle bulunamayacak karşıt örnekleri arayabilir. Ama algoritmayı yazmak ispat demek değildir; Goldbach önermesi bugün hâlâ açıktır. Hoca $x^n$'in $\log_2 n$ adımda ve Fibonacci sayısının $n$'den kısa sürede hesaplanmasının ileride özyinelemeli algoritmalarla görüleceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
