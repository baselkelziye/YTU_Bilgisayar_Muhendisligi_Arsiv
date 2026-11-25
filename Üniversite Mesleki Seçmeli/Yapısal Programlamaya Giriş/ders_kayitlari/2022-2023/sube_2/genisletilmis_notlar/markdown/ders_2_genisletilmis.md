# Ders 2 Genişletilmiş Notu: Algoritmanın Özellikleri, Temel Algoritmik İşlemler, İyi Algoritma ve Algoritma Analizine Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Algoritmanın tanımı ve üç özelliği
- 2. Problem çözme yaklaşımı ile algoritma farkı
- 3. Gündelik hayattan algoritma örnekleri
- 4. Temel algoritmik işlemler
- 5. İyi (verimli) algoritma
- 6. Algoritma geliştirme nasıl öğrenilir
- 7. İlk karmaşıklık örnekleri: Gauss toplamı
- 8. Algoritma iyileştirmenin önemi ve çözülmemiş problemler
- 9. Algoritma analizi: bilimsel yöntem ve 3-SUM
- 10. Matematiksel model, temel işlem ve tilde gösterimi
- 11. 3-SUM'un iyileştirilmesi
- Örnek Sorular
- Dersin Toparlaması

## 1. Algoritmanın tanımı ve üç özelliği

Ders, bir önceki derste başlanan algoritma ve programlama kavramlarını hatırlatarak başladı. Hoca tahtaya (siyah zemin üzerine el yazısıyla, İngilizce terimlerle) şu tanımı yazdı (ekrandan, 00:10:00):

> Algorithm: set of certain (not ambiguous), sequential, limited/finite instructions.

Yani algoritma, **belirli** (muğlak olmayan), **sıralı** ve **sonlu** komutlardan oluşan bir komut kümesidir.

### 1.1 Belirli (certain)

Belirli olmak, kullanılan her komutun tanımlı bir komut kümesinin (instruction set) içinde olması demektir: "certain: defined commands/instructions". Olmayan bir komutla program yazılamaz. Örneğin bir giriş komutu programlama dilinde (`scanf`) ve akış diyagramında (giriş sembolü) tanımlıdır; bu yüzden kullanılabilir.

### 1.2 Sıralı (sequential)

Sıralı olmak, komutların **mantıksal bir sırayla** dizilmesi demektir: "sequential: logically ordered instructions". Hoca iki sayının toplamını örnek verdi (ekrandan, 00:15:00):

```text
Doğru sıra                 Yanlış sıra
Input X                    Input X
Input Y                    Z = X + Y
Z = X + Y                  Write Z
Write Z
```

Sol taraftaki algoritma yukarıdan aşağı akar; buna yürütme akışı (execution flow) denir. Sağdaki yanlıştır, çünkü `Y` henüz okunmadan `Z = X + Y` hesaplanmaya çalışılıyor. `Input Y` toplama satırından sonra yazılsaydı da yine hatalı olurdu.

### 1.3 Sonlu (limited / finite)

Sonluluk iki açıdan düşünülür: komut sayısı ve çalışma süresi ("finite: # of insts & running time"). Yazdığınız kodun sonu gelmiyorsa ya da çalıştırdığınız kod hiç tamamlanmıyorsa, bu bir algoritma değildir.

### 1.4 Soyut bir örnek

Hoca kavramları içerikten bağımsız düşünmek için komut kümesi $\{A, B, C, D, E\}$ olan bir dil tanımladı ve üç diziyi karşılaştırdı (ekrandan, 00:15:00):

| Dizi | Komutlar | Algoritma mı? | Neden |
|---|---|---|---|
| Alg-1 | A, A, B, C, A, D, E | Evet | Komutlar tanımlı, istenen sırada ve sayıda kullanılabilir, dizi sonlu |
| Alg-2 | A, B, Z, A, E | Hayır | `Z` komut kümesinde tanımlı değil ("komut bulunamadı" hatası gibi) |
| Alg-3 | A, B, C, D, E, A, B, C, ... | Hayır | Sonsuza kadar gidiyor, sonluluk ihlal ediliyor |

Bu örnekte komutların içeriğine ve öncelik-sonralık ilişkisine bakılmadı; sıralamanın mantıklı olduğu kabul edildi.

## 2. Problem çözme yaklaşımı ile algoritma farkı

Hoca sık karıştırılan bir kavramı ayırdı: **problem çözme yaklaşımı** (problem solving approach). Üniversiteye hazırlıkta bir matematik sorusunu çözerken "önce şunu hesaplarım, sonra bunu" diye kafada bir çözüm yolu kurulur. Bu yol sıralı ve sonlu olabilir, ama çoğu zaman **belirlilik** özelliğini ihlal eder: adımlar yeterince ayrıntılı değildir.

Örnek: girilen sayılar içindeki en küçük sayının karesini bulan program.

```text
Enter N numbers
Find min, say it x
Square x
```

Bu bir yaklaşımdır ama algoritma değildir. "Find min" adımı, N sayının en küçüğünün nasıl bulunacağını söylemiyor. Pek çok dilde bunun için hazır fonksiyon olabilir, ama algoritmik düşünüldüğünde bu adım ayrıca bir algoritmayla açılmalı ya da kendi yazdığımız bir fonksiyonla gerçekleştirilmelidir. Ders notundaki Türkçe tanım da buna uygundur: algoritma, bir problemi çözmek için gereken adımların listesidir.

## 3. Gündelik hayattan algoritma örnekleri

Hoca bu bölümü öğrencilerle soru-cevap biçiminde yürüttü.

### 3.1 Kek tarifi

Bir öğrenci kek tarifini algoritmik olarak anlattı: yumurtaları kır, şekeri ekle ve çırp, süt ve un ekle, tekrar çırp, fırın kabına dök, 200 derecede yarım saat pişir. Hoca iki noktaya dikkat çekti:

- "Şekeri ekle" dendiğinde miktar söylenmiyor. Ne kadar şeker? Miktarı belirsiz bir adım, sonluluğu ve belirliliği bozar. Bu yüzden "bir su bardağı" gibi kesin bir miktar verilmelidir.
- "30 dakika pişir" bir süreçtir: başı, sonu ve süresi bellidir.

**Soru:** "30 dakika boyunca ısıt" ifadesi programlamada neye karşılık gelir? **Cevap:** Başı ve sonu belli, tekrar sayısı belli bir döngüye, yani `for` döngüsüne.

**Soru:** "Kürdan batırıldığında ıslak çıkmayana kadar fırında beklesin" denseydi neye karşılık gelirdi? **Cevap:** Ne kadar süreceği önceden bilinmeyen bir tekrar, yani `while` döngüsü.

Hoca tarifte ayrıca "kabın içine yumurtayı koy, şekeri koy" gibi atama türünden adımlar ve tekrarlı adımlar olduğunu belirtti. Bu gözlem, temel algoritmik işlemlerin sınıflandırılmasına geçişi sağladı.

### 3.2 Yol tarifi

Bir öğrenciden, dili bilmeyen ve yalnız yürümeyi bilen birine metro çıkışından yurda kadar yol tarifi yapması istendi. Tarif "üst geçitten in, sağa dön, kapıdan gir, yemekhaneyi görene kadar düz yürü, yol bitene kadar devam et, sağa dön" biçiminde ilerledi.

- "Yemekhaneyi görene kadar yürü" ve "yol bitene kadar git" adımları tekrar sayısı belirsiz olduğu için `while` döngüsüne karşılık gelir.
- "Biraz daha yürü" gibi bir ifade kabul edilmez. Hoca, ABD'de yol tarifinin "beş blok sonra sağa dön" diye verildiğini örnek gösterdi; mesafe ya da sokak sayısı kesin söylenmelidir. "100 metre sonra sağa dön" dendiğinde ise sayısı belli bir tekrar (`for`) vardır.
- Bu tarif bir robota kodlansaydı, belirsiz kısımlar `while`, sayısı belli kısımlar `for` ile yazılırdı.

### 3.3 Komutları sınırlı bir çizim programıyla ev çizmek

Hocanın tanımladığı bir programın yalnız şu komutları var: yatay, dikey ve açılı düz çizgi çizmek (açı verilerek), merkezi ve yarıçapı belli daire çizmek. Bir öğrenci bu komutlarla bir ev tarif etti (ekrandan, 00:45:00):

- Koordinat vermek gerekir: "başlangıç noktasının iki boşluk yanı" yerine "(10, 10) noktasından (10, 100) noktasına dikey çizgi" gibi.
- Duvarlar dört çizgiyle, çatı iki eğik çizgiyle, pencereler iki daireyle (merkez ve yarıçapla), kapı üç çizgiyle çizildi (ekrandan, 01:20:00).
- Öğrencinin önerdiği "bunu ters çevir, ötele" işlemleri programda yoktu. Hoca, matematikte yansıtma olsa da bu programda olmayan bir işlemin kullanılamayacağını hatırlattı. Çatının tepe noktası da açı ya da koordinat verilmeden "x 50 olana kadar" diye tanımlanamadı; ya açı (trigonometri) ya da uç noktaların koordinatları verilmelidir.

Grafik kütüphanelerinde bunlara karşılık gelen `draw line`, `draw circle`, `draw arc` (yay) gibi fonksiyonlar vardır. "50 birim boyunca çiz" gibi bir işlem de bir anlamda `for` döngüsüdür. Evi farklı ve daha kolay yollarla da çizmek mümkündü; amaç, her durumda bir algoritma geliştirildiğini görmekti. Asıl hedef ise **iyi** algoritma geliştirmektir.

## 4. Temel algoritmik işlemler

**Soru:** Algoritmik işlemler temelde kaç gruba ayrılabilir? Bir öğrenci dört dedi: for, while, atama ve if-else. **Cevap:** En genel hâliyle üç grup vardır (ekrandan, 00:30:00):

```text
Algorithmic operations
-> sequential : assignment (:=), math (+, -, *, /), comparison (<, >, ==, !=)
     a = 8;
     a = x + 3;
-> conditional : if
-> repetitive
     -> number of iterations is clear (for)
     -> number of iterations is vague (while, do-while / repeat-until)
```

### 4.1 Sıralı (sequential) işlemler

Atama, matematiksel işlemler ve karşılaştırmalar bu gruptadır. Örnek atamalar: `a = 8;`, `a = x + 3;`. Sembolik gösterimde atama, matematikteki eşitlikle karışmasın diye `:=` ile gösterilir. Program yalnız sıralı işlemlerden oluşuyorsa, 1000 satır da olsa bütün satırlar çalıştırılır (execute edilir).

### 4.2 Koşullu (conditional) işlemler

Temeli `if`'tir. Akış diyagramında koşul ifadesi (conditional statement) altıgen bir kutuyla gösterilir; bir doğru (T) bir de yanlış (F) kolu vardır. Program yukarıdan gelir, ikiye ayrılır, ya sağ kol ya sol kol çalışır, sonra iki kol birleşir ve program aşağıdan devam eder. Yani kodun bir kısmı çalışır, bir kısmı çalışmaz.

> **Hocanın vurgusu:** if'in iki kolu da aşağıya gider. Bir kolu yukarı, bir kolu aşağı giden bir if çizilmez; böyle bir şekil geçerli bir if değildir. Ayrıca "if döngüsü" diye bir şey yoktur.

### 4.3 Tekrarlı (repetitive) işlemler

İki türü vardır:

- **Tekrar sayısı belli** (number of iterations is clear): örneğin tam 30 kez dönülecekse. Bu `for` döngüsüdür. Başlangıç değeri, bitiş değeri ve artış miktarı bellidir. Başlangıç 0 olmak zorunda değildir (5'ten, 8'den başlayabilir), artış 3'er 3'er, 5'er 5'er olabilir. Örnek: 1'den 1000'e kadar çift sayıların karelerinin toplamı.
- **Tekrar sayısı belirsiz** (number of iterations is vague): `while` ve `do-while`. `do-while` bazı dillerde `repeat-until` olarak geçer.

Hoca bu üç işlem dışında başka algoritmik yapı olmadığını, kuramsal olarak bütün problemlerin bu üç işlemle çözülebileceğini, ama bazı problemlerde bunun çok kötü bir çözüm vereceğini söyledi. Diziler algoritmayla değil, veri yapılarıyla ilgilidir ve ayrıca ele alınacaktır.

### 4.4 while ve do-while

Akış diyagramında while şöyle çalışır (ekrandan, 00:35:00): program gelir, önce koşul sınanır. Koşul doğruysa döngü gövdesi (A bloğu) çalışır ve koşula geri dönülür; yanlışsa döngüden çıkılıp aşağıdan devam edilir.

**Soru:** Program çalışırken A bloğu kesinlikle çalışır diyebilir miyiz? **Cevap:** Hayır. Koşul ilk sınamada yanlışsa akış doğrudan aşağı geçer, A hiç çalışmaz.

Gövdenin en az bir kez çalışması istenirse `do-while` kullanılır. Önce gövdedeki işlemler yapılır, sonra koşul sınanır; doğruysa gövde tekrarlanır, yanlışsa çıkılır.

Gündelik örnek **sisteme giriş (login)** işlemidir. Kullanıcı adı ve şifre en az bir kez girilir. Yanlış girilirse tekrar istenir. Ancak koşul yalnız "şifre yanlış olduğu sürece tekrar dene" olursa tehlikelidir: sınırsız deneme, şifrenin başkası tarafından kırılmasına imkân verir. Doğru koşul iki şartı birlikte içerir: şifre yanlış **ve** deneme sayısı sınıra ulaşmadı. Örneğin beş yanlış denemeden sonra ya da doğru şifre girildiğinde döngüden çıkılır.

### 4.5 Sade yazmak ve parametrik kod

> **Hocanın vurgusu:** Algoritmik düşünmek, en sade ve en anlaşılır biçimde düşünmek demektir. Algoritma bir edebi eser değildir; söz sanatlarına gerek yoktur. Özellikle ekip olarak yürütülen bir yazılım projesinde başkasının yazdığını sizin, sizin yazdığınızı başkasının anlaması gerekir.

**Soru:** Bir sıralı işlemi (örneğin `a = 8`) makineye üç kez yaptırmak için `for` döngüsü mü kullanmalıyız? **Cevap:** Sayı gerçekten sabit 3 ise `a = 8` satırını üç kez yazmakta sakınca yoktur. Ama ileride bu sayı n olabilecekse döngüyle yazmak gerekir. Yazılımın en önemli özelliklerinden biri yaşayabilir olmasıdır; geliştirilmek, daha esnek hâle getirilmek istenir. Döngü kullanmak kodu parametrik hâle getirir.

## 5. İyi (verimli) algoritma

Hoca "iyi algoritma" kavramını "kalite ne demek?" sorusuyla açtı. Kaliteli bir telefon örneğinde öğrencilerden "stabil çalışması", "malzemenin en verimli şekilde kullanılması", "istenen işi en az maliyetle ve olabildiğince hızlı yapması" ve "daha az uğraştırması" cevapları geldi. Bunlar şu ölçütlerde toplandı (ekrandan, 00:55:00 ve 01:00:00):

```text
İyi Algoritma / Efficient Algorithm
-> accuracy & precision
-> efficient & economical resource utilization
     - CPU (time)
     - Memory (space)
-> readability
           trade-off (ödünleşme)
```

### 5.1 Doğruluk ve hassasiyet (accuracy & precision)

İki ayrı kavram olsa da aynı başlıkta ele alındı: algoritma ne kadar doğru ve hassas sonuç üretiyor? Her zaman çalışan, doğru sonuç veren algoritma (algorithm that works all the time). Örnekler: hava durumu tahmini, satranç oynayan bir programın doğru hamleleri seçmesi. Hoca, sayısal analizde bir denklemin gerçek çözümünün analitik yolla bulunamadığı durumlarda algoritmik yollarla çözüme yaklaşıldığını ve orada en önemli kavramın doğruluk ve hassasiyet olduğunu söyledi.

### 5.2 Kaynakların verimli ve ekonomik kullanımı (resource utilization)

Temel kaynaklar iki tanedir: **CPU**, yani zaman (time), ve **bellek** (memory), yani alan (space). "Hızlı" derken aslında CPU kullanımından söz edilir. Derste üzerinde en çok durulacak iki kavram bunlardır.

### 5.3 Okunabilirlik (readability)

**Soru:** İyi algoritmanın anlaşılır olma zorunluluğu var mı? **Cevap:** Bir problemi çözen birden çok algoritma varsa ve bunlar doğruluk ile kaynak kullanımı açısından aynıysa, en anlaşılır olanı en iyisidir. Ama amaç doğruluksa ve çok doğru ama anlaşılması zor bir algoritma varsa, o kullanılır.

Sıralama algoritmaları bunu iyi gösterir (ekrandan, 01:00:00):

- Merge sort ve quick sort: okunması ve adım adım izlenmesi zordur, çünkü özyinelemeli (rekürsif) işlemler içerirler. Ama zaman açısından bubble sort'tan çok daha iyidirler. Quick sort 1960'larda ortaya çıkmış, çok ödül almış bir yeniliktir.
- Bubble sort, selection sort, insertion sort: okuması ve anlaması kolaydır; insertion sort bunların biraz daha iyisidir.
- Merge sort bellek açısından bubble sort'tan kötüdür ama daha hızlıdır. Hoca quick sort'u hem bellek hem zaman açısından iyi olduğu için sıralama ailesinin "kralı" diye niteledi; bir açmazı olduğunu ve ona sonra gelineceğini söyledi.

### 5.4 Ödünleşim (trade-off)

Bu ölçütler bazen birbirini götürür: birini kazanırken öbürünü kaybedersiniz. Buna **trade-off** (ödünleşme) denir.

- Merge sort daha fazla bellek kullanarak daha hızlı sıralar; bubble sort belleği iyi kullanır ama hızdan kaybeder.
- Gömülü sistem örneği: gömülü sistemler belleğin kısıtlı olduğu sistemlerdir. 4 MB belleği olan bir sistemde 4 MB veriyi merge sort ile sıralayamazsınız, çünkü merge sort ayrıca 4 MB daha ister. Bu durumda "ne kadar sürerse sürsün, yeter ki sıralasın" diyerek daha yavaş ama az bellekli bir yöntem seçilir.
- Sistem açısından kaynakları yalnız sizin programınız kullanmaz; işletim sisteminin gözetiminde başka programlar da CPU ve bellekten pay alır.

Hoca, telefon ya da bilgisayar alırken her özelliğin en iyisinin ucuza bulunamayacağını, belli bir bütçeye en uygun olanın seçildiğini hatırlattı. Algoritma da böyle seçilir: içinde bulunulan durumu en iyi çözen algoritma en iyi algoritmadır.

## 6. Algoritma geliştirme nasıl öğrenilir

Aradan sonra hoca, teorik kavramların sonraki derslerden itibaren kod ve akış diyagramlarıyla inceleneceğini söyledi. Doğruluğu her algoritmada ölçmek mümkün olmadığı için daha çok CPU ve bellek kullanımına bakılacak; bunun için bir matematiksel model kurulacak ve algoritma çalıştığında ortaya çıkan bir fonksiyon, algoritmanın iyiliği hakkında bilgi verecek.

Algoritma geliştirmeyi öğrenmek için bilinen çözüm yöntemlerini görmek, vizyonu geliştirmek ve tecrübe kazanmak gerekir. Hoca bunu kombinatorikle karşılaştırdı: permütasyon ve kombinasyonun yalnız birkaç formülü vardır,

$$\binom{n}{r} = \frac{n!}{(n-r)!\,r!}, \qquad P(n, r) = \binom{n}{r}\cdot r!$$

ama bu formüller etrafında çok sayıda farklı problem vardır ve bunları çözmenin genel bir yolu yoktur; her problem için ayrı bir kurgu yapılır. Algoritmada da elimizde yalnız üç temel işlem vardır, ama her problem için ayrı bir düşünce gerekir. Hoca, ders notlarında yazılı olan şu ifadeyi aktardı: **algoritma geliştirmenin bir algoritması yoktur**; bunun karşılığı tecrübedir.

<!-- BELİRSİZ: Hoca kombinasyon formülünü öğrencilere sordurup tahtada tamamladı; altyazıda formülün paydası bozuk çıkıyor ("n-1, r faktör"). Yukarıdaki formül standart tanımdır. -->

**Soru:** Yapay zekâ uygulamaları, örneğin sohbet robotları, bir nevi algoritma üretmiyor mu? **Cevap:** Bugün "yapay zekâ" denince çoğunlukla makine öğrenmesi kastedilir. Bu sistemler çok büyük metin verisinden öğrenen, regresyon ve sınıflandırma gibi matematiksel modelleri kullanan algoritmalardır; arkada gizli, sihirli bir şey yoktur. Tarihçesi Alan Turing'in 1950'lerde ortaya attığı Turing testine kadar gider: bir bilgisayarla konuşursunuz ve o size bir insan gibi cevap verir. Bu sistemler de tecrübeye, yani kendilerine verilen örneklere dayanarak öğrenir. Hocanın kastettiği ise şudur: bir insan için her türlü algoritmayı geliştirmeye yarayan genel, global bir algoritma yoktur.

> **Ders sonrası not:** Hoca bu sohbet robotlarının arka planında "LSTM ve CNN" modellerinin çalıştığını söyledi. Büyük olasılıkla bu sistemlerin temeli Transformer mimarisidir; hoca da ayrıntıların kapalı olduğunu belirtti.

## 7. İlk karmaşıklık örnekleri: Gauss toplamı

### 7.1 1'den N'ye kadar toplam

Örnek soru: $X = 1 + 2 + \dots + N$ değerini bulan program (ekrandan, 01:30:00). Bir öğrenciyle akış diyagramı birlikte kuruldu:

```text
START
  |
Input N                      (kullanıcıdan alınır)
  |
for i <- 1 ; i = N ; +1      (1'den N'ye, N dahil, birer artarak)
  |   \
  |    X = X + i             (döngü gövdesi)
  |
Output "X =", X
  |
STOP
```

Öğrencinin "i = i + 1 desek?" sorusuna hoca, `i`'nin döngü sayacı olduğunu ve bozulmaması gerektiğini, birikimin ayrı bir `X` değişkeninde tutulacağını söyledi.

> **Hocanın vurgusu:** `X = X + i` bir denklem değildir; "X'ler birbirini götürür, i = 0 olur" diye okunmaz. İçinde iki işlem vardır: önce sağdaki toplama yapılır (X'in mevcut değerine i eklenir), sonra sonuç X'e atanır. Atama operatörü en son çalışır.

N = 5 için izleme tablosu (ekrandan, 01:30:00; son satır sözlü anlatımdan tamamlandı):

| i | N | X (gövdeden önce) | X (gövdeden sonra) |
|---|---|---|---|
| 1 | 5 | 0 | 1 |
| 2 | 5 | 1 | 3 |
| 3 | 5 | 3 | 6 |
| 4 | 5 | 6 | 10 |
| 5 | 5 | 10 | 15 |
| 6 | 5 | döngü biter | X = 15 yazdırılır |

Toplama işlemi N kez yapılır. N = 5 için 5, N = 50 için 50 kez. Bu yüzden çalışma zamanı

$$T_1(N) \approx N$$

olarak yazılır. Bizim için önemli olan, işlem sayısının $N^2$ ya da $N^3$ değil, $N$ ile orantılı olmasıdır.

### 7.2 Gauss formülüyle aynı problem

Öğrenci döngü yerine doğrudan $\frac{N(N+1)}{2}$ kullanılabileceğini önermişti. Hoca ikinci akış diyagramını çizdi (ekrandan, 01:35:00):

```text
START -> Input N -> X = (N * (N + 1)) / 2 -> Output "X =", X -> STOP
```

Atama ya da matematiksel işlem kutusunun dikdörtgenle çizildiği de hatırlatıldı. Burada bir çarpma, bir toplama ve bir bölme, toplam üç işlem vardır. N bin de olsa milyar da olsa işlem sayısı değişmez:

$$T_2(N) = 3$$

$N \to \infty$ iken $T_1$ sonsuza gider, $T_2$ sabit kalır. Hesaplama (işlem sayısı) karmaşıklığı açısından sabit algoritma tercih edilir. Sabit değerler (3, 10, 15, 100) genel gösterimde 1 olarak, yani birim zaman olarak yazılır.

Formülün kanıtı: toplam bir kez düz, bir kez ters yazılıp alt alta toplanır (ekrandan, 01:45:00):

$$\begin{aligned} S &= 1 + 2 + \dots + N \\ S &= N + (N-1) + \dots + 1 \\ 2S &= (N+1) + (N+1) + \dots + (N+1) = N(N+1) \end{aligned}$$

Her sütun $N+1$ verir, N sütun vardır; toplam iki kez yazıldığı için 2'ye bölünür: $S = \frac{N(N+1)}{2}$.

> **Hocanın vurgusu:** Sabit işlemli algoritmalar her zaman N'e bağlı işlemli algoritmalara tercih edilir. Bir algoritmayı N karmaşıklıktan sabit karmaşıklığa indirgemek çok iyi bir indirgemedir.

**Soru:** Karşılaştırmalar ve atamalar arasında hesapta fark gözetiyor muyuz? **Cevap:** Burada önemli olan süre (saniye) değil, yapılan işlemin tekrar sayısıdır. Atama iki çözümde de olduğu için hesaba katmaya gerek yoktur. Analiz, temel işlem (basic operation) denen işlem üzerinden yapılacaktır; ayrıntısı ileride gelecek.

### 7.3 N'den M'ye ve −N'den M'ye toplam

Genel Gauss formülü: ardışık sayılarda terim sayısı $(\text{son} - \text{ilk})/\text{artış} + 1$, toplam ise terim sayısı ile ilk ve son terimin ortalamasının çarpımıdır. N'den M'ye kadar (birer artarak) (ekrandan, 01:45:00):

$$\sum_{k=N}^{M} k = \big((M-N)+1\big)\cdot\frac{M+N}{2}$$

Kanıt aynı mantıkla: $N, N+1, \dots, M$ dizisi ters yazılıp toplanınca her sütun $N+M$ verir, $(M-N+1)$ sütun vardır, 2'ye bölünür.

Sonra hoca soruyu değiştirdi: $M > N$ için $-N$ ile $M$ arasındaki sayıların toplamı (ekrandan, 01:45:00).

- Klasik yolda $-N$'den $M$'ye bir `for` döngüsü kurulur; yaklaşık $N + M$ işlem yapılır.
- Gözlem: $-N$ ile $+N$ arasındaki sayılar birbirini götürür, toplamları 0'dır. O hâlde yalnız $N+1$'den $M$'ye kadar toplamak yeter; döngü $M - N$ işlem yapar.
- Daha iyisi, döngüyü tamamen kaldırmaktır:

$$X_1 = \frac{M(M+1)}{2}, \qquad X_2 = \frac{N(N+1)}{2}, \qquad T = X_1 - X_2$$

Hoca bu çözümdeki işlemleri saydı ve sabit sayıda (7) işlem buldu. Döngülü çözüm $M-N$ işlem ister, formüllü çözüm N ve M'den bağımsızdır.

(Kontrol, ara adım eklendi: N = 3, M = 7 için $-3$'ten 7'ye toplam $22$; $X_1 - X_2 = 28 - 6 = 22$.)

**Soru:** Her soruda bu şekilde bir fonksiyon (formül) çıkarabiliyor muyuz? **Cevap:** Karmaşıklığı ifade eden fonksiyon her algoritma için çıkarılır, ama her problem için Gauss formülü gibi "sihirli" bir formül yoktur; çoğu zaman döngüler gerekir. Örneğin bubble sort iki iç içe döngüyle $N^2$ karmaşıklıktadır; biraz daha zorlanınca sıralama $N\log N$'ye indirgenebilmiştir. Bu, algoritmik ve eleştirel düşünmenin bir sonucudur.

## 8. Algoritma iyileştirmenin önemi ve çözülmemiş problemler

### 8.1 Sıralama karmaşıklıkları

Hoca tahtada şunları not etti (ekrandan, 01:45:00):

| Algoritma | Zaman karmaşıklığı |
|---|---|
| Bubble sort | $N^2$ |
| Merge sort | $N\log N$ |
| Quick sort | $N\log N$, ters sıralı (reversed order) girdide $N^2$ |

**Soru:** Zaman açısından hangisi tercih edilir? **Cevap:** $N\log N$ olan. Bir milyon elemanlı bir dizide bir milyonun karesi kadar işlem yapmaktan çok daha iyidir. Quick sort'un ters sıralı girdide $N^2$'ye düşmesinden nasıl kurtulunacağı ileride tartışılacak. Hoca ayrıca hiçbir genel sıralama algoritmasının N zamanda sıralayamadığını, N zamanlı yöntemlerin bulunduğunu ama tam anlamıyla genel sıralama algoritması sayılmadığını ya da pratikte uygulanabilir olmadığını belirtti.

### 8.2 Matematiğin yeri

> **Hocanın vurgusu:** Algoritma geliştirmede matematiksel düşünce kaçınılmazdır. Sürekli ve ayrık matematikteki teoremler algoritmaları iyileştirmede kullanılır. Matematik bilmeden programcı olunabilir, ama iyi algoritma geliştirmek için matematiğe başvurmak gerekir.

Örnek olarak web sayfalarını sıralayan ve ölçeklenebilir çalışan PageRank algoritması, Facebook gibi şirketlerin teknolojileri verildi: bunlar yıllar süren kolektif bir çalışmanın ve bilgi birikiminin ürünüdür.

### 8.3 Gezgin satıcı problemi (Travelling Salesman Problem)

N şehir ve aralarında uzunlukları bilinen yollar vardır. Bir şehirden başlanır, bütün şehirler birer kez gezilir ve başlangıca geri dönülür. Amaç en kısa (en az maliyetli) turu bulmaktır (ekrandan, 01:55:00).

Dört şehirli örnek (A, B, C, D; her şehirden her şehre yol var):

```text
A - B - C - D - A
A - C - D - B - A
A - D - C - B - A
...
```

Sayma kuralıyla: A'dan başlanınca ilk adımda 3, sonra 2, sonra 1 seçenek kalır; A'dan başlayan $3 \cdot 2 \cdot 1 = 6$ tur vardır. Başlangıç şehri 4 farklı seçilebildiği için $4 \cdot 6 = 24 = 4!$ durum incelenir (gidiş ve dönüş yollarının uzunlukları farklı olabilir). N şehir için bu $N!$'e yakındır. Türkiye'nin 81 ili için $81!$ durumu inceleyip en kısasını bulmak pratikte mümkün değildir. Kesin çözüm yerine yaklaşık çözümler üreten yöntemler (örneğin genetik algoritmalar) kullanılır.

Hoca, akademik çalışmalarda genellikle ya sıfırdan bir çözüm önerildiğini, ya var olan bir çözümün iyileştirildiğini (daha yüksek doğruluk, daha az CPU ya da bellek), ya da bir probleme önerilen algoritmanın başka bir probleme uyarlandığını anlattı. TSP'de iki algoritmanın bulduğu tur uzunluklarının karşılaştırılması doğruluk iyileştirmesine örnek verildi. Çözülmemiş problemlere (P ve NP tipi problemler gibi) örnek olarak bir bilgisayar bilimi kaynağı gösterildi.

### 8.4 Diğer iyileştirme örnekleri

- **Fourier dönüşümü:** Bir işareti zaman düzleminden frekans düzlemine geçirir. Doğrudan algoritma N örnek için $N^2$ işlem ister; hızlı Fourier dönüşümü (FFT) bunu $N\log N$'ye indirir. Görüntü ve ses analizinde çok kullanılır; hoca evrişimli sinir ağlarının (CNN) temelinde de FFT olduğunu söyledi.
- **N-cisim benzetimi (N-body simulation):** Kütle çekimiyle birbirini etkileyen cisimlerin benzetimi; $N^2$'den $N\log N$'ye indirgenmiş bir algoritma.

> **Ek bilgi (derste anlatılmadı):** CNN'lerde evrişim çoğu uygulamada doğrudan hesaplanır; FFT tabanlı evrişim büyük çekirdeklerde kullanılan bir hızlandırma yöntemidir. Yani FFT, CNN'lerin zorunlu temeli değil, bir uygulama seçeneğidir.

## 9. Algoritma analizi: bilimsel yöntem ve 3-SUM

Dersin son bölümünde Sedgewick ve Wayne'in "Algorithms" (4. baskı) kitabının "1.4 Analysis of Algorithms" slaytları işlendi (ekrandan, 02:05:00). Slayt başlıkları: introduction, observations, mathematical models, order-of-growth classifications, theory of algorithms, memory.

### 9.1 Çalışma zamanı ve roller

Slayttaki eski mekanik hesap makinesinde hesaplama bir kolun (crank) döndürülmesiyle ilerler. Soru şudur: kol kaç kez dönmeli? Ne kadar az dönerse, yani problem ne kadar kısa sürede çözülürse o kadar iyidir. Programcı çalışan bir çözüm, müşteri verimli bir çözüm, kuramcı ise işin arka planını anlamak ister; bir mühendislik öğrencisi bu rollerin hepsine sahip olmalıdır.

### 9.2 Bilimsel yöntem

Bilimsel yöntem: gerçek dünyadan **gözlem** yap, gözlemlerle tutarlı **hipotez** kur, hipotezle **tahmin** yap, tahminleri gözlemle **doğrula** ve bu döngüyü tekrarla. Deneyler tekrar üretilebilir (reproducible), hipotezler yanlışlanabilir olmalıdır. Bu yöntem algoritmaların zaman ve bellek açısından analizine uygulanır.

### 9.3 3-SUM problemi

**3-SUM:** N farklı tamsayı verildiğinde, toplamı tam olarak sıfır olan kaç üçlü vardır? (ekrandan, 02:10:00)

Slayttaki girdi: 8 sayı, `30 -40 -20 -10 40 0 10 5`. Cevap 4:

| # | a[i] | a[j] | a[k] | toplam |
|---|---|---|---|---|
| 1 | 30 | −40 | 10 | 0 |
| 2 | 30 | −20 | −10 | 0 |
| 3 | −40 | 40 | 0 | 0 |
| 4 | −10 | 0 | 10 | 0 |

(Python ile bütün üçlüler sayılarak doğrulandı: 4 üçlü.)

Hoca önce kendi küçük örneğini verdi: $1, 4, 8, -12, 0$ dizisinde $4 + 8 + (-12) = 0$ bir üçlüdür (ekrandan, 02:15:00).

Çözüm öğrencilerle birlikte kuruldu:

- Bir öğrenci permütasyon ya da kombinasyon kullanmayı önerdi. Hoca, bunun doğrudan bir koda dönüşmediğini ve hatalı kurulursa faktöriyel karmaşıklık doğurabileceğini söyledi.
- Üç iç içe `for` döngüsü kurulur. İlk öneride ikinci döngü sabit olarak 2'den başlıyordu; hoca bunun aynı üçlüleri tekrar tekrar sayacağını (örneğin $30, -40, 10$ ile $-40, 10, 30$) gösterdi. Hem fazladan işlem yapılır hem sonuç yanlış çıkar. Doğrusu `j` döngüsünü `i + 1`'den, `k` döngüsünü `j + 1`'den başlatmaktır. `k`'yı `i + 2`'den başlatmak da yanlıştır, çakışma yine olur.
- En içte `a[i] + a[j] + a[k] == 0` ise sayaç artırılır ya da üçlü yazdırılır.

Slayttaki kaba kuvvet (brute-force) kod Java ile yazılmıştır, C'ye çok benzer (ekrandan, 02:20:00):

```java
public class ThreeSum
{
   public static int count(int[] a)
   {
      int N = a.length;
      int count = 0;
      for (int i = 0; i < N; i++)
         for (int j = i+1; j < N; j++)
            for (int k = j+1; k < N; k++)
               if (a[i] + a[j] + a[k] == 0)   // check each triple
                  count++;                    // for simplicity, ignore integer overflow
      return count;
   }
   ...
}
```

Diziler 0'dan başladığı için `i` 0'dan N'e (N hariç) gider.

**Soru (öğrenci önerisi):** Diziyi önce pozitifler ve negatifler (ve sıfırlar) diye ayırırsak, üç pozitif sayının toplamını boşuna kontrol etmekten kurtulmaz mıyız? **Cevap:** Üç pozitif sayının toplamı zaten sıfır olamaz, bu gözlem doğru. Ama hoca, ayırdıktan sonra iki pozitifin toplamını negatifler içinde aramak gibi adımların yine iç içe döngüler gerektirdiğini, üçlü iç içe döngüden tam kurtulunamadığını gösterdi; daha iyi çözüme ders sonunda gelineceğini söyledi.

### 9.4 Karşılaştırma sayısı

Dış döngü N kez, ikinci döngü yaklaşık $N - i$ kez, üçüncü döngü yaklaşık $N - j$ kez döner. En içteki karşılaştırma yaklaşık $N(N-i)(N-j)$ kez yapılır; çarpım açıldığında baskın terim $N^3$'tür (ekrandan, 02:20:00). Algoritma yaklaşık $N^3$ işlem yapar, yani **kübiktir**: girdi boyutu iki katına çıkınca işlem sayısı $2^3 = 8$ katına çıkar.

**Soru (derste sözlü):** 8 elemanlı girdide 2 saniye süren bu algoritma 8000 elemanda yaklaşık ne kadar sürer? Hoca cevabın "küpü kadar" artacağını söyledi.

> **Ders sonrası not:** Hoca burada sonucu "yaklaşık 64000" diye söyledi. Girdi 1000 katına çıktığı için kübik algoritmada süre $1000^3 = 10^9$ katına çıkar: $2 \times 10^9$ saniye. 64 katlık artış, girdinin 4 katına çıktığı duruma karşılık gelir.

### 9.5 Deneysel analiz (empirical analysis)

Kitaptaki yaklaşım önce süre ölçmektir: `count` fonksiyonu çağrılmadan önce ve sonra saat okunur, fark alınır. Ölçüm sonuçları (ekrandan, 02:45:00):

| N | süre (s) |
|---|---|
| 1000 | 0,1 |
| 2000 | 0,8 |
| 4000 | 6,4 |
| 8000 | 51,1 |

N iki katına çıktıkça süre yaklaşık 8 katına çıkıyor: $0{,}1 \cdot 8 = 0{,}8$, $0{,}8 \cdot 8 = 6{,}4$, $6{,}4 \cdot 8 = 51{,}2 \approx 51{,}1$. Hoca daha küçük boyutlarda (250 ve 500) sürelerin sıfıra yakın olduğunu da söyledi.

<!-- BELİRSİZ: Hoca bundan önce "1K'da 70 saniye, 2K'da 528 saniye, 4K'da 4039 saniye" diye başka bir ölçüm de okudu (02:20:55); bu değerler okunan karelerde görünmüyor. 70·8 = 560 ve 70·64 = 4480 olduğu için hoca bunları kübik büyümeye "yakın" diye yorumladı. -->

Log-log grafik (ekrandan, 02:25:00): $\lg T(N)$, $\lg N$'ye karşı çizilince noktalar eğimi 3 olan bir doğru üzerine düşer.

$$\lg T(N) = b \lg N + c, \qquad b = 2.999, \quad c = -33.2103$$

$$T(N) = a N^b, \qquad a = 2^c$$

Bu, ölçülen sürelerden $N^3$ davranışını tahmin etmektir (hoca buna sayısal analizde regresyon denildiğini söyledi). Sonra bu modelle daha büyük N'ler için tahmin yapılıp ölçümle doğrulanır; bilimsel yöntemin tahmin (prediction) ve doğrulama (validation) adımları budur.

> **Hocanın vurgusu:** Süreyi saniye cinsinden ölçüp karşılaştırmak doğru değildir. Ölçümün yapıldığı bilgisayarın işlemcisi, belleği, işletim sistemi, yazılımı belli değildir; bilgisayar çok yavaş ya da çok hızlı olabilir, bulutta çalışıyor olabilir. Amaç bu sisteme bağlı etkilerden (system dependent effects) kurtulmaktır. Bu yüzden önce koddan $N^3$'ü bulup süreyi ondan tahmin etmek hem daha kolay hem daha doğrudur.

## 10. Matematiksel model, temel işlem ve tilde gösterimi

### 10.1 Knuth'un matematiksel modeli

Donald Knuth (1974 Turing Ödülü; "The Art of Computer Programming" serisi: temel algoritmalar, yarı sayısal algoritmalar, sıralama ve arama, kombinatoryal algoritmalar) bir matematiksel model önerdi: toplam çalışma süresi, her işlemin maliyeti ile sıklığının çarpımlarının toplamıdır. Örneğin toplama, çarpma, sinüs, arktanjant gibi işlemlerin her birinin nanosaniye cinsinden bir maliyeti vardır. Bunu genelleştirmek için değişken tanımlamaya $c_1$, atamaya $c_2$, karşılaştırmaya $c_3$ gibi sabit maliyetler verilir ve her işlemin kaç kez yapıldığı sayılır.

### 10.2 for döngüsü kaç karşılaştırma yapar?

`for (i = 0; i < N; i++)` döngüsü N = 5 için izlendi (ekrandan, 02:30:00):

- `i = 0` ataması bir kez yapılır.
- `i < N` karşılaştırması i = 0, 1, 2, 3, 4 için doğru çıkar, gövde çalışır, `i++` yapılır.
- i = 5 olduğunda karşılaştırma bir kez daha yapılır, yanlış çıkar ve döngü biter.

Gövde N kez çalışır, ama `i < N` karşılaştırması **N + 1** kez yapılır. Döngü bittikten sonra akış döngüden sonraki işlemden devam eder.

### 10.3 1-SUM ve 2-SUM sıklık tabloları

Tek döngülü örnekte (dizide sıfıra eşit eleman sayma) sıklıklar: değişken tanımı 2, atama 2, küçüktür karşılaştırması N + 1, eşitlik karşılaştırması N, dizi erişimi N, artırma ise N ile 2N arasında (sayaç artışı koşula bağlı olduğu için en iyi ve en kötü durum farkı burada ortaya çıkar). Hepsi maliyetleriyle çarpılıp toplanınca $c \cdot N + c'$ biçiminde, N ile doğrusal bir ifade elde edilir.

2-SUM'da (toplamı sıfır olan ikililer) iki iç içe döngü vardır (ekrandan, 02:35:00):

```java
int count = 0;
for (int i = 0; i < N; i++)
   for (int j = i+1; j < N; j++)
      if (a[i] + a[j] == 0)
         count++;
```

Slayttaki sıklık tablosunun görünen satırları:

| işlem | sıklık |
|---|---|
| variable declaration | $N + 2$ |
| assignment statement | $N + 2$ |
| less than compare | $\frac{1}{2}(N+1)(N+2)$ |

Bütün işlemleri tek tek saymak karmaşık ve zahmetlidir.

### 10.4 Temel işlem (basic operation)

Sadeleştirme: algoritmanın en önemli parçası, iç döngüdeki karşılaştırmadır (`== 0`). Problem zaten "toplam sıfıra eşit mi?" sorusudur. Yalnız bu işlemin kaç kez yapıldığını saymak yeterlidir; diğerleri ayrıntıdır. Her karşılaştırmanın maliyeti 1 kabul edilir.

Dış döngüde $i = 0, \dots, N-1$; iç döngü $j = i+1, \dots, N-1$ olduğu için iç döngü $N - 1 - i$ kez döner:

$$\sum_{i=0}^{N-1} (N - 1 - i) = \sum_{i=0}^{N-1}(N-1) - \sum_{i=0}^{N-1} i = N(N-1) - \frac{(N-1)N}{2} = \frac{N(N-1)}{2}$$

Slaytta da $0 + 1 + 2 + \dots + (N-1) = \frac{1}{2}N(N-1) = \binom{N}{2}$ olarak verilir. Sonuç $N^2$ mertebesindedir.

### 10.5 Tilde gösterimi

Uzun hesap sonunda örneğin $\frac{1}{6}N^3 + 20N + 16$ gibi bir ifade bulunduysa, tilde ($\sim$) gösteriminde yalnız en yüksek dereceli terim tutulur: $\sim \frac{1}{6}N^3$. Hoca ileride katsayının ($\frac{1}{6}$) da atılacağını söyledi.

3-SUM için dizi erişimi temel işlem alınırsa (ekrandan, 02:40:00): `i`, `j`, `k` döngüleri N'in üçlü kombinasyonları kadar çalışır,

$$\binom{N}{3} = \frac{N(N-1)(N-2)}{3!} \sim \frac{1}{6}N^3$$

Her üçlüde 3 dizi erişimi olduğu için cevap $\sim \frac{1}{2}N^3$ dizi erişimidir.

Dörtlüler aranacak olsaydı dört iç içe döngü gerekirdi. Ama K'lı gruplar için K sabit değilse K tane iç içe döngü yazılamaz; o zaman özyinelemeli (recursive) algoritmalar gibi başka yöntemler gerekir.

Hoca slaytta geçen bir araştırma notuna da değindi: $1 + 2 + 3 + \dots$ sonsuz toplamına bazı bağlamlarda $-\frac{1}{12}$ değerinin atandığını, bunun nasıl olabileceğinin araştırılabileceğini söyledi.

> **Ek bilgi (derste anlatılmadı):** $1 + 2 + 3 + \dots$ serisi olağan anlamda ıraksaktır. $-\frac{1}{12}$ değeri, Riemann zeta fonksiyonunun analitik devamında $\zeta(-1) = -\frac{1}{12}$ olmasından gelir ve ancak özel toplama (regülarizasyon) yöntemleriyle bu seriye atanır.

### 10.6 Büyüme sınıfları

Algoritmalar genellikle şu sınıflardan birindedir: sabit ($1$), logaritmik ($\log N$), doğrusal ($N$), doğrusal-logaritmik ($N\log N$), karesel ($N^2$), kübik ($N^3$), üstel ($2^N$). Üstel algoritmalar, N bitin $2^N$ farklı durumu olması gibi büyür. Bir algoritmayı bu listede daha düşük bir sınıfa indirmek ($N^3$'ten $N^2\log N$'ye, $N^2$'den $N\log N$'ye) iyileştirmedir.

## 11. 3-SUM'un iyileştirilmesi

Kaba kuvvet 3-SUM $N^3$'tür. Sıralama tabanlı çözüm:

1. Diziyi sırala. Bunun için $N\log N$ algoritmalar vardır.
2. Her $(i, j)$ ikilisi için $-(a[i] + a[j])$ değerini sıralı dizide **ikili arama** (binary search) ile ara. İkili arama $\log N$ sürer.

İkililer için $N^2$, her biri için $\log N$ arama: toplam $N^2\log N$. Bu, $N^3$'e göre süre açısından çok daha iyidir.

Slayttaki karşılaştırma (ekrandan, 02:45:00), hipotez: "Sıralama tabanlı $N^2\log N$ algoritma pratikte kaba kuvvet $N^3$ algoritmadan anlamlı ölçüde hızlıdır."

| N | ThreeSum ($N^3$) süre (s) | sıralama + ikili arama ($N^2\log N$) süre (s) |
|---|---|---|
| 1000 | 0,1 | 0,14 |
| 2000 | 0,8 | 0,18 |
| 4000 | 6,4 | 0,34 |
| 8000 | 51,1 | 0,96 |
| 16000 | – | 3,67 |
| 32000 | – | 14,88 |
| 64000 | – | 59,16 |

1000'den 8000'e (8 kat) çıkıldığında kaba kuvvet çözümün süresi yaklaşık 500 kat artarken sıralamalı çözümün süresi yaklaşık 7 kat artıyor. Sıralama ve ikili arama zaten bilinen algoritmalardır; onları birleştirmek bu kadar büyük bir kazanç sağladı. Ders başında yapılan "süreden denkleme" gitmek yerine "denklemden süreye" gitmek hem daha doğrudur hem de iyileştirmeyi açıkça gösterir.

> **Ek bilgi (derste anlatılmadı):** İkili aramalı çözümde her üçlünün tekrar sayılmaması için genellikle yalnız $a[j] < a[k]$ koşulunu sağlayan, yani j'den sonraki konumda bulunan eleman sayılır. Kitapta bu sürüm "ThreeSumDeluxe" adıyla geçer; hoca da tablodaki ikinci sütunu "deluxe" sürüm diye andı.

Hoca bu kitabın normalde ikinci sınıfın veri yapıları dersinde inceleneceğini, ama kitabın sitesindeki örnek kodlar (Java), demo animasyonlar ve slaytlarla şimdiden çalışılabileceğini söyledi. Sedgewick-Wayne kitabı ve Knuth'un kitapları meslek hayatı boyunca okunacak kaynaklar olarak önerildi. İş ve staj mülakatlarında "bubble sort'un karmaşıklığı nedir, neden kötüdür, quick sort'u ne iyileştirir" gibi soruların sorulduğunu da ekledi.

## Örnek Sorular

**Soru 1** (ekrandan, 00:15:00): Komut kümesi $\{A, B, C, D, E\}$ olan bir dilde aşağıdakilerden hangileri algoritmadır?
Alg-1: A, A, B, C, A, D, E. Alg-2: A, B, Z, A, E. Alg-3: A, B, C, D, E, A, B, C, ... (sonsuza kadar).

> **Çözüm (derste verildi):** Yalnız Alg-1 algoritmadır. Alg-2'de `Z` tanımlı değildir (belirlilik ihlali). Alg-3 sonsuza gider (sonluluk ihlali).

**Soru 2** (derste sözlü, 00:20:41 ve 00:22:15): Bir tarifteki "30 dakika ısıt" ve "kürdan ıslak çıkmayana kadar fırında beklet" adımları programlamada hangi yapılara karşılık gelir?

> **Çözüm (derste verildi):** İlki tekrar sayısı (süresi) belli olduğu için `for`, ikincisi tekrar sayısı belirsiz olduğu için `while` döngüsüdür.

**Soru 3** (derste sözlü, 00:23:30): Algoritmik işlemler temelde kaç gruba ayrılır?

> **Çözüm (derste verildi):** Üç: sıralı (atama, aritmetik, karşılaştırma), koşullu (if), tekrarlı (for; while ve do-while).

**Soru 4** (derste sözlü, 00:29:50): Bir while döngüsünün gövdesi (A bloğu) program çalışırken kesinlikle çalışır mı?

> **Çözüm (derste verildi):** Hayır. Koşul ilk sınamada yanlışsa gövde hiç çalışmaz. Gövdenin en az bir kez çalışması gerekiyorsa do-while kullanılır.

**Soru 5** (ekrandan, 01:30:00): $X = 1 + 2 + \dots + N$ değerini bulan algoritmanın akış diyagramını çizin ve karmaşıklığını yazın.

> **Çözüm (derste verildi):** Döngülü çözüm: N oku; `for i = 1..N: X = X + i`; X'i yaz. N = 5 için X: 1, 3, 6, 10, 15. $T_1(N) \approx N$. Formüllü çözüm: $X = \frac{N(N+1)}{2}$, $T_2(N) = 3$ (sabit).

**Soru 6** (ekrandan, 01:45:00): $M > N$ için $-N$ ile $M$ arasındaki tamsayıların toplamını en az işlemle bulun.

> **Çözüm (derste verildi):** $-N$ ile $N$ arasındakiler birbirini götürür. Toplam $= \frac{M(M+1)}{2} - \frac{N(N+1)}{2}$; sabit sayıda işlem. Döngüyle $N+1$'den $M$'ye toplamak $M - N$ işlem ister.

**Soru 7** (ekrandan, 01:55:00): Her şehirden her şehre yol olan 4 şehirde (A, B, C, D) gezgin satıcı problemi için kaç farklı tur incelenir?

> **Çözüm (derste verildi):** A'dan başlayınca $3 \cdot 2 \cdot 1 = 6$ tur; 4 başlangıç şehri için $4 \cdot 6 = 24 = 4!$. N şehir için yaklaşık $N!$.

**Soru 8** (ekrandan, 02:10:00): 3-SUM: `30 -40 -20 -10 40 0 10 5` dizisinde toplamı sıfır olan kaç üçlü vardır? Kaba kuvvet algoritmanın karmaşıklığı nedir?

> **Çözüm (derste verildi):** 4 üçlü: $(30, -40, 10)$, $(30, -20, -10)$, $(-40, 40, 0)$, $(-10, 0, 10)$. Üç iç içe döngü (`j = i+1`, `k = j+1`) ile $\sim N^3$.

**Soru 9** (derste sözlü, 02:20:12): Kübik bir algoritma 8 elemanlı girdide 2 saniye sürüyorsa, 8000 elemanlı girdide yaklaşık ne kadar sürer?

> **Çözüm (derste verilen cevap düzeltildi):** Girdi $1000$ katına çıkar, süre $1000^3 = 10^9$ katına çıkar: yaklaşık $2 \times 10^9$ saniye. (Hoca "yaklaşık 64000" dedi; bkz. 9.4'teki ders sonrası not.)

**Soru 10** (ekrandan, 02:35:00): 2-SUM kodunda (`for i = 0..N-1`, `for j = i+1..N-1`, `if (a[i] + a[j] == 0)`) eşitlik karşılaştırması kaç kez yapılır?

> **Çözüm (derste verildi):** $0 + 1 + \dots + (N-1) = \frac{N(N-1)}{2} = \binom{N}{2} \sim \frac{1}{2}N^2$.

**Soru 11** (ekrandan, 02:40:00): 3-SUM kaba kuvvet kodu, girdi boyutu N'in fonksiyonu olarak yaklaşık kaç dizi erişimi yapar?

> **Çözüm (derste verildi):** $\binom{N}{3} = \frac{N(N-1)(N-2)}{3!} \sim \frac{1}{6}N^3$ üçlü, her üçlüde 3 erişim: $\sim \frac{1}{2}N^3$ dizi erişimi.

## Dersin Toparlaması

Bu derste önce algoritmanın üç özelliği (belirlilik, sıralılık, sonluluk) ve bir yaklaşımın ne zaman algoritma sayılmadığı netleştirildi. Gündelik örneklerle (tarif, yol tarifi, ev çizimi) bütün algoritmaların üç temel işlemden (sıralı, koşullu, tekrarlı) kurulduğu gösterildi; tekrarlı işlemlerde for, while ve do-while ayrımı yapıldı. Ardından iyi algoritmanın ölçütleri (doğruluk ve hassasiyet, zaman ve bellek açısından verimlilik, okunabilirlik) ve bunlar arasındaki ödünleşim tartışıldı.

İkinci yarıda algoritma analizine giriş yapıldı. Gauss toplamı örneğinde döngülü $N$ işlemlik çözümün formülle sabit işleme inmesi, TSP'de $N!$ büyüklüğündeki arama uzayı ve 3-SUM'da $N^3$'ten $N^2\log N$'ye iyileştirme görüldü. Süre ölçümüne dayalı deneysel analizin makineye bağlı olduğu, bunun yerine temel işlemin sayılıp tilde gösterimiyle büyüme mertebesinin bulunmasının daha doğru olduğu vurgulandı. Hoca, sonraki derslerden itibaren bu analiz ve iyileştirme yöntemlerinin farklı problemler üzerinde, kod ve akış diyagramlarıyla uygulanacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
