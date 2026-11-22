# Ders 10 Genişletilmiş Notu: Özyinelemeli Olmayan Algoritmaların Analizi: Döngüleri Toplam Gösterimiyle Saymak

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin amacı ve akış diyagramı gösterimi
- 2. Tek döngü: gövdedeki ifade sonucu nasıl değiştirir?
- 3. İç döngüsü N·N'e giden iki döngü
- 4. İç döngüsü i·i'ye giden iki döngü
- 5. Değişkeni iki katına çıkan while döngüsü
- 6. Geometrik toplam formülünün türetilmesi
- 7. i·A^i toplamı
- 8. Koşul içeren iç içe döngü
- 9. Önce K = 2^N hesaplayan algoritmalar
- 10. Üç iç içe döngü ve başlangıcı değişen döngüler
- Örnek Sorular
- Dersin Toparlaması

Bu derste hep aynı türden bir soru soruldu: akış diyagramıyla verilen bir algoritma bittiğinde sayaç değişkeni $T$'nin değeri, girdi $N$'e bağlı olarak ne olur? Hoca basit bir döngüyle başladı ve her adımda algoritmada küçük bir değişiklik yaptı. Her soruda önce öğrencilerden tahmin aldı, sonra çözümü birlikte kurdu. Bütün diyagramlar ve formüller tahtada elle çizildi.

## 1. Dersin amacı ve akış diyagramı gösterimi

Dersin konusu özyinelemeli (rekürsif) olmayan algoritmaların analizidir. Bir algoritmanın içindeki bir noktadan kaç kez geçildiğini bulmak, o algoritmanın ne kadar uzun çalışacağını ve neye bağlı olduğunu anlamak demektir. Bunun için her döngü bir toplam sembolüne ($\sum$) çevrilir, iç içe döngüler iç içe toplamlar olur ve sonra matematik kurallarıyla kapalı bir ifade elde edilir.

Akış diyagramlarında for döngüsü bir kutu olarak çizilir. Kutunun üst kısmında `i ← 1 || 1`, alt kısmında `N` yazar (ekrandan, 00:05:00). Bu, $i$'nin 1'den başladığını, birer birer arttığını ve $N$'e kadar gittiğini gösterir. Hoca bir öğrencinin sorusu üzerine "$N$'e kadar" ifadesinde $N$'in dahil olduğunu belirtti. Girdi okuma paralelkenar benzeri bir kutuyla, çıktı (ekrana yazdırma) dalgalı alt kenarlı bir kutuyla, başlangıç ve bitiş de START ve STOP elipsleriyle gösterilir.

## 2. Tek döngü: gövdedeki ifade sonucu nasıl değiştirir?

### 2.1 Gövde `T = T + 1`

İlk algoritma: START, $N$ okunur, `T = 0`, for $i = 1..N$ içinde `T = T + 1`, döngü bitince $T$ yazdırılır, STOP (ekrandan, 00:05:00). Öğrencilerden $N(N+1)$, $N-1$ gibi tahminler geldi. Hoca gövdeden kaç kez geçildiğini sordu: $i$ 1'den $N$'e kadar gittiği için $N$ kez geçilir. $T$ sıfırdan başladığı ve her geçişte 1 arttığı için sonuç $N$'dir.

Bu, lise matematiğindeki toplam gösterimiyle şöyle yazılır (ekrandan, 00:10:00):

$$T = \sum_{i=1}^{N} 1 = N$$

### 2.2 Gövde `T = T + i`, `T = T + 2` ve `T = T + 2i`

Gövde `T = T + i` olunca her turda o anki $i$ eklenir: $1 + 2 + \dots + N$.

$$T = \sum_{i=1}^{N} i = \frac{N(N+1)}{2}$$

Gövde `T = T + 2` olunca $N$ kez 2 eklenir, $T = \sum_{i=1}^{N} 2 = 2N$. Gövde `T = T + 2i` olunca sonuç `T = T + i` durumunun iki katıdır (ekrandan, 00:10:00):

$$T = \sum_{i=1}^{N} 2i = N(N+1)$$

### 2.3 `T = 1` ve gövde `T = T + T`

Son değişiklikte $T$ 1'den başlatıldı ve gövde `T = T + T` yapıldı (ekrandan, 00:10:00). Bir öğrenci hemen $2^N$ dedi; hoca bunu adım adım gösterdi:

| $i$ | $T$ (tur sonunda) |
|---|---|
| başlangıç | 1 |
| 1 | 2 |
| 2 | 4 |
| 3 | 8 |
| 4 | 16 |

Her turda $T$ iki katına çıkar, $N$ tur sonunda $T = 2^N$ olur. Bu toplamla değil çarpımla ifade edilir. Bir öğrencinin hatırlattığı "P gibi işaret" çarpım sembolüdür:

$$T = \prod_{i=1}^{N} 2 = 2^N$$

## 3. İç döngüsü N·N'e giden iki döngü

### 3.1 Gövde `T = T + 1` ve $N = 3$ ile deneme

Yeni algoritma: $N$ okunur, `T = 0`, for $i = 1..N$, onun içinde for $j = 1..N \cdot N$, gövde `T = T + 1`, sonunda $T$ yazdırılır (ekrandan, 00:15:00). Öğrencilerden $N^2$, $N^3$ ve "1'den $N$'e kadar karelerin toplamı" tahminleri geldi. Hoca tahmin yürütmek yerine $N = 3$ alıp algoritmayı elle çalıştırmalarını istedi. Bir öğrenci 14 buldu ($1 + 4 + 9$, yani karelerin toplamı), birkaç öğrenci 27 buldu. İkisinden en az biri yanlış olmalıydı.

Formülle yazınca iki döngü iki toplam olur (ekrandan, 00:25:00):

$$T = \sum_{i=1}^{N} \sum_{j=1}^{N^2} 1$$

İç toplam $N^2$ tane 1'in toplamıdır, yani $N^2$. Dış toplam $N$ tane $N^2$'yi toplar:

$$T = \sum_{i=1}^{N} N^2 = N^3$$

$N = 3$ için $3^3 = 27$; doğru cevap 27'dir. 14 cevabı, iç döngü $i \cdot i$'ye gitseydi doğru olurdu (bu durum 4. bölümde geldi).

### 3.2 Gövde `T = T + i`

Gövde `T = T + i` yapıldı. Hoca önce yalnız iç döngüye bakmayı önerdi: iç döngü dönerken $i$ değişmez. Bu yüzden $i$ iç toplamın dışına alınabilir:

$$T = \sum_{i=1}^{N} \sum_{j=1}^{N^2} i = \sum_{i=1}^{N} i \cdot \sum_{j=1}^{N^2} 1 = \sum_{i=1}^{N} i \cdot N^2$$

$N^2$ de $i$'ye bağlı olmadığı için dış toplamın dışına çıkar:

$$T = N^2 \sum_{i=1}^{N} i = N^2 \cdot \frac{N(N+1)}{2} = \frac{N^3(N+1)}{2}$$

### 3.3 Gövde `T = T + j`

Gövde `T = T + j` olunca (ekrandan, 00:25:00) $j$ iç toplamın dışına alınamaz, çünkü iç döngünün değişkenidir. İç toplam 1'den $N^2$'ye kadar olan sayıların toplamıdır (1'den $N$'e kadar değil):

$$\sum_{j=1}^{N^2} j = \frac{N^2(N^2+1)}{2}$$

Bu ifadede $i$'ye bağlı bir şey yoktur. $N$ kez toplamak $N$ ile çarpmak demektir:

$$T = N \cdot \frac{N^2(N^2+1)}{2} = \frac{N^3(N^2+1)}{2}$$

Bir öğrenci sonucu çarpanları dağıtarak yazdı; hoca bunun da aynı sonuç olduğunu söyledi.

## 4. İç döngüsü i·i'ye giden iki döngü

### 4.1 Gövde `T = T + 1`: karelerin toplamı

Bu sefer iç döngü $N$'e ya da $N^2$'ye değil, $i \cdot i$'ye kadar gider (ekrandan, 00:30:00):

$$T = \sum_{i=1}^{N} \sum_{j=1}^{i \cdot i} 1 = \sum_{i=1}^{N} i^2$$

Bir öğrenci önce içeriye $\frac{i^2(i^2+1)}{2}$ yazmayı önerdi; hoca bunun ancak gövdede $j$ toplansaydı doğru olacağını, burada içeride 1 toplandığını hatırlattı. Toplam $1 + 4 + 9 + 16 + \dots$ biçiminde gider, yani karelerin toplamıdır. Bir öğrenci formülü hatırladı:

$$\sum_{i=1}^{N} i^2 = \frac{N(N+1)(2N+1)}{6}$$

Hoca bu formülün "hiç güzel olmadığını" söyledi.

### 4.2 Gövde `T = T + i`: küplerin toplamı

Gövde `T = T + i` yapılınca $i$ yine dışarı alınır. İç toplam $i^2$ tane birin toplamı, yani $i^2$'dir:

$$T = \sum_{i=1}^{N} i \cdot \sum_{j=1}^{i \cdot i} 1 = \sum_{i=1}^{N} i \cdot i^2 = \sum_{i=1}^{N} i^3$$

Bir öğrencinin söylediği formül:

$$\sum_{i=1}^{N} i^3 = \left(\frac{N(N+1)}{2}\right)^2$$

Yani küplerin toplamı, 1'den $N$'e kadar sayıların toplamının karesidir. Hoca bu formülü karelerin toplamı formülünden daha güzel buldu.

### 4.3 Gövde `T = T + j`

Gövde `T = T + j` olunca (ekrandan, 00:35:00) iç toplam 1'den $i^2$'ye kadar olan sayıların toplamıdır:

$$\sum_{j=1}^{i \cdot i} j = \frac{i^2(i^2+1)}{2}$$

İçeride $i$ olduğu için dış toplam "$N$ tanesinin toplamı" diye çarpmaya çevrilemez. Ama ifade parçalara ayrılabilir: $\frac{1}{2}$ dışarı alınır ve toplam iki toplama bölünür (ara adım eklendi):

$$T = \frac{1}{2}\left(\sum_{i=1}^{N} i^4 + \sum_{i=1}^{N} i^2\right)$$

Bir öğrenci $i^4$'ün formülünün iki tane $i^2$ formülünden elde edilip edilemeyeceğini sordu; hoca "keşke" dedi, öyle olmadığını belirtti. Hoca tahtaya $\sum i^4$ için $\frac{N^5}{5} + \frac{N^4}{2} + \dots$ ile başlayan ve son teriminin paydası 30 olan "çok çirkin" formülü yazdı. Bu formülün tam hali şöyledir:

$$\sum_{i=1}^{N} i^4 = \frac{N^5}{5} + \frac{N^4}{2} + \frac{N^3}{3} - \frac{N}{30}$$

<!-- BELİRSİZ: Tahtadaki formülün ortadaki terimleri altyazıda okunmadı ve o ana ait kare yok. Yukarıdaki tam hal, altyazıdaki ilk iki terim ve 30 paydasıyla uyumludur ve python ile N = 1..8 için doğrulandı. -->

Kalan iş, bu formülle karelerin toplamını toplayıp ikiye bölmektir; hoca bunu öğrencilere bıraktı.

**Soru:** Kuvvet değiştikçe ($i$, $i^2$, $i^3$, $i^4$, ...) toplam formüllerini veren genel bir kural var mı? **Cevap:** Hoca, şimdiye kadar çözülen sorulara bakıldığında böyle basit bir genel kural görünmediğini söyledi; ilk üç formül birbirine benziyordu ama $i^4$ farklı çıktı.

> **Ek bilgi (derste anlatılmadı):** Kuvvet toplamları için genel bir formül aslında vardır (Faulhaber formülü); katsayıları Bernoulli sayılarıyla verilir. Bu yüzden her kuvvet için ayrı ve giderek karmaşıklaşan bir polinom çıkar. $\sum_{i=1}^{N} i^p$ her zaman $N$'in $p+1$. dereceden bir polinomudur ve baş terimi $\frac{N^{p+1}}{p+1}$'dir.

**Soru:** $i^4$'ü toplamın içinde $i^2 \cdot i^2$ diye yazıp $\sum i^2 \cdot \sum i^2$ biçiminde ayırabilir miyiz? **Cevap:** Hayır. Toplamın içindeki çarpım, toplamların çarpımına ayrılamaz.

## 5. Değişkeni iki katına çıkan while döngüsü

### 5.1 Algoritma ve $N = 32$ ile izleme

Bu sefer algoritmanın tipi değişti (ekrandan, 00:40:00 ve 00:45:00): START, `T = 0`, `i = 1`, $N$ okunur; `i <= N` olduğu sürece `T = T + 1` ve `i = i * 2`; döngüden çıkınca $T$ yazdırılır. Hesap kolay olsun diye $N$'in $2^k$ biçiminde (256, 512, 1024 gibi) olduğu varsayıldı.

Öğrencilerden önce $\log_2 N$, sonra algoritmayı deneyenlerden $\log_2 N + 1$ cevapları geldi. Hoca $N = 32$ ile tabloyu kurdu (ekrandan, 00:45:00):

| $i$ (girişte) | $T$ (tur sonunda) |
|---|---|
| 1 | 1 |
| 2 | 2 |
| 4 | 3 |
| 8 | 4 |
| 16 | 5 |
| 32 | 6 |

$i = 32$ iken koşul (`32 <= 32`) hâlâ doğrudur ve içeri girilir; sonra $i = 64$ olur ve döngüden çıkılır. $T = 6$ kalır. $\log_2 32 = 5$ olduğundan sonuç $\log_2 N + 1$'dir. Toplam gösterimiyle $T = \sum_{i=1}^{\log_2 N + 1} 1$ biçiminde yazılabilir.

**Soru:** $N = 2$ için sonuç nedir? **Cevap:** $i$ = 1 ve 2 değerlerinde içeri girilir, $T = 2 = \log_2 2 + 1$. Toplam gösterimindeki üs 0 ve 1 değerlerini alır.

### 5.2 Gövde `T = T + i`

Sonra gövde `T = T + i` yapıldı (ekrandan, 00:50:00). Bir öğrenci $\sum_{i=1}^{\log_2 N + 1} i$ yazılmasını önerdi. Başka bir öğrenci bunun olamayacağını, çünkü $i$'nin birer birer değil iki katına çıkarak ilerlediğini fark etti; hoca bunu "güzel yakaladın" diye onayladı. $i$ ikişer ikişer de artmaz (`i + 2` değil, `i * 2`). Eklenen değerler $1, 2, 4, 8, \dots$, yani $2^0, 2^1, 2^2, \dots$ olur. Bu yüzden indis 0'dan başlatılır, üst sınırdaki $+1$ de kalkar:

$$T = \sum_{i=0}^{\log_2 N} 2^i$$

Bir öğrenci, algoritmada $i$ 1'den başlarken toplamda neden 0'dan başladığını sordu. Hoca ikisinin farklı şeyler olduğunu açıkladı: algoritmadaki $i$ değişkeni 1'den başlar; toplam formülündeki indis ise üstün kendisidir ve $2^0 = 1$ olduğundan 0'dan başlar.

## 6. Geometrik toplam formülünün türetilmesi

Bu toplamı hesaplamak için önce genel bir formül türetildi (ekrandan, 01:10:00 ve 01:15:00). Hoca, cevabı bilen öğrencilerden cevabı değil, nasıl bulunacağını birlikte görmeyi istedi.

$$T = \sum_{i=0}^{N} A^i = A^0 + A^1 + A^2 + \dots + A^N$$

$A^0 = 1$ olduğundan:

$$T - 1 = A^1 + A^2 + \dots + A^N = A\left(A^0 + A^1 + \dots + A^{N-1}\right)$$

Parantezin içindeki $A^0 + \dots + A^{N-1}$ kısmı, $T$'nin açılımında da vardır; $T$'den tek farkı son terim $A^N$'in eksik olmasıdır. Bu yüzden parantez yerine $T - A^N$ yazılabilir:

$$T - 1 = A(T - A^N) = AT - A^{N+1}$$

Terimler yer değiştirilir ve $T$ parantezine alınır:

$$AT - T = A^{N+1} - 1 \quad\Rightarrow\quad T(A-1) = A^{N+1} - 1 \quad\Rightarrow\quad T = \frac{A^{N+1}-1}{A-1}$$

Hoca, karışık görünen bir toplamın $N$'e bağlı sade bir ifadeye dönüştüğünü vurguladı.

### 6.1 While örneğine uygulama

5.2'deki toplamda $A = 2$ ve üst sınır $N$ yerine $\log_2 N$'dir. Öğrencilere yerine koymaları için süre verildi. Bazıları $2N - 1$, biri $2^{\log_2 N + 1} - 1$ buldu; ikisi aynı şeydir:

$$T = \frac{2^{\log_2 N + 1} - 1}{2 - 1} = 2 \cdot 2^{\log_2 N} - 1 = 2N - 1$$

Burada $2^{\log_2 N} = N$ özdeşliği kullanıldı.

> **Ek bilgi (derste anlatılmadı):** $2^{\log_2 N} = N$, logaritmanın tanımından gelir: $\log_2 N$, 2'nin $N$'i vermesi için gereken üstür. Genel olarak $a^{\log_a x} = x$'tir ($a > 0$, $a \neq 1$, $x > 0$).

## 7. i·A^i toplamı

### 7.1 Problem ve öğrenci denemeleri

Ardından şu toplam soruldu ve on dakika süre verildi (ekrandan, 01:20:00):

$$T = \sum_{i=0}^{N} i A^i$$

İndisin 0'dan ya da 1'den başlamasının fark etmediği belirtildi, çünkü $i = 0$ terimi sıfırdır. Hoca sonucun $\frac{A^{N+1}-1}{A-1}$ kadar basit olmayacağını, ama çok da karmaşık olmayacağını söyledi; önce toplamı açıp örüntü aramayı önerdi.

Bir öğrenci $T = \frac{2NA}{1-A}$ buldu (ekrandan, 01:30:00); hoca bunu bir değerle denemesini önerdi. Başka bir öğrenci $\log_{N!} T = \frac{(N-1)N}{2}$ gibi bir ifadeye ulaştı; hoca sonucun $A$'ya bağlı olması gerektiğini, bu ifadede $A$ bulunmadığını gösterdi.

> **Ders sonrası not:** $\frac{2NA}{1-A}$ ifadesi doğru değildir. Örneğin $A = 2$, $N = 2$ için gerçek toplam $0 + 2 + 8 = 10$'dur, bu ifade ise $-8$ verir (python ile denendi).

### 7.2 A ile çarpıp çıkarma yöntemi

Hocanın yöntemi: toplam açık yazılır ve her iki taraf $A$ ile çarpılır (ekrandan, 01:35:00).

$$T = 0A^0 + 1A^1 + 2A^2 + 3A^3 + \dots + (N-1)A^{N-1} + NA^N$$

$$AT = \phantom{0A^0 + {}} 1A^2 + 2A^3 + \dots + (N-2)A^{N-1} + (N-1)A^N + NA^{N+1}$$

Şimdi $T - AT$ hesaplanır. Aynı üslü terimler alt alta gelir: iki tane $A^2$'den bir tane $A^2$ çıkar, üç tane $A^3$'ten iki tane $A^3$ çıkar, ..., $N$ tane $A^N$'den $N-1$ tane $A^N$ çıkar. Her üsten tam bir tane kalır. Eşi olmayan iki terim de kalır: üstteki $1A^1$ ve alttaki $NA^{N+1}$. Sonuç:

$$T - AT = A + A^2 + A^3 + \dots + A^N - NA^{N+1}$$

Sağdaki ilk kısım, 6. bölümdeki geometrik toplamın $A^0 = 1$ terimi eksik halidir. Bu yüzden yerine $\frac{A^{N+1}-1}{A-1} - 1$ yazılır:

$$T(1-A) = \frac{A^{N+1}-1}{A-1} - 1 - NA^{N+1}$$

$$T = \frac{\dfrac{A^{N+1}-1}{A-1} - 1 - NA^{N+1}}{1-A}$$

Hoca bu ifadenin daha da sadeleştirilebileceğini söyledi ve sadeleştirmeyi öğrencilere bıraktı (sadeleştirilmiş hal "Örnek Sorular" bölümünde). Bu işlemin amacı, $i A^i$ terimlerindeki $i$ katsayılarından kurtulmak ve daha önce bilinen $A^1 + A^2 + \dots + A^N$ toplamına ulaşmaktır. Bilinen formül bulununca o kullanılır ve çözüme gidilir.

## 8. Koşul içeren iç içe döngü

### 8.1 Algoritma ve $N = 4$ ile izleme

Yeni algoritma (ekrandan, 01:40:00): START, `T = 0`, $N$ okunur, for $i = 1..N$, onun içinde for $j = 1..i \cdot i$. İçeride bir karar kutusu vardır: `j mod i == 0` ise (T dalı) `T = T + 1`, değilse (F dalı) bir şey yapılmaz. Sonunda $T$ yazdırılır.

Öğrencilerden $\frac{N(N+1)}{2}$ ve $2N - 1$ cevapları geldi. Hoca $N = 4$ ile tablo kurdu (ekrandan, 01:50:00):

| $i$ | $j$ değerleri | `j mod i == 0` olanlar | $T$ (tur sonunda) |
|---|---|---|---|
| 1 | 1 | 1 | 1 |
| 2 | 1, 2, 3, 4 | 2, 4 | 3 |
| 3 | 1, 2, ..., 9 | 3, 6, 9 | 6 |
| 4 | 1, 2, ..., 16 | 4, 8, 12, 16 | 10 |

1, 3, 6, 10 dizisi ardışık sayıların toplamıdır. Her $i$ için 1'den $i^2$'ye kadar olan sayılardan tam $i$ tanesi $i$'nin katıdır, yani her $i$ turunda $T$ $i$ kadar artar:

$$T = \sum_{i=1}^{N} i = \frac{N(N+1)}{2}$$

### 8.2 False dalından kaç kez geçilir?

Hoca sonra soruyu değiştirdi: F dalından kaç kez geçilir? Bu, `T = T + 1` kutusunu F dalına koymakla aynıdır. Bir öğrenci şu fikri verdi: karar kutusuna toplam $\sum_{i=1}^{N} i^2$ kez gelinir; bundan T dalından geçiş sayısı çıkarılırsa F dalından geçiş sayısı bulunur. Tahtada kırmızı ile karar kutusunun girişi, mavi ile T dalı işaretlendi (ekrandan, 01:50:00):

$$T_F = \sum_{i=1}^{N} \left(i^2 - i\right) = \frac{N(N+1)(2N+1)}{6} - \frac{N(N+1)}{2}$$

$N = 4$ için bu $30 - 10 = 20$'dir (python ile denendi).

> **Ek bilgi (derste anlatılmadı):** İfade sadeleştirilirse $\frac{N(N+1)}{6}\left[(2N+1) - 3\right] = \frac{N(N+1)(N-1)}{3} = \frac{N^3 - N}{3}$ elde edilir. $N = 4$ için $\frac{64-4}{3} = 20$ ile tutarlıdır.

## 9. Önce K = 2^N hesaplayan algoritmalar

### 9.1 Gövde `T = T + 1`

Yeni algoritma (ekrandan, 01:55:00): `T = 0`, `K = 1`, $N$ okunur. İlk for ($i = 1..N$) içinde `K = K * 2` yapılır. Sonra ikinci bir for $i = 1..N$, onun içinde for $j = 1..K$ ve gövde `T = T + 1`.

Alt kısmı çözmek için önce üst kısım çözülmelidir: ilk döngüden çıkınca $K$ kaçtır? $N$ tane 2 birbiriyle çarpılır, yani $K = 2^N$. İç döngünün sınırı $K$ yerine $2^N$ yazılabilir:

$$T = \sum_{i=1}^{N} \sum_{j=1}^{2^N} 1 = \sum_{i=1}^{N} 2^N = N \cdot 2^N$$

### 9.2 Gövde `T = T + i` ve `T = T + j`

Gövde `T = T + i` olunca (ekrandan, 02:10:00) $i$ dışarı alınır; iç toplam $2^N$'dir ve o da dışarı çıkar:

$$T = \sum_{i=1}^{N} i \cdot 2^N = 2^N \cdot \frac{N(N+1)}{2}$$

Gövde `T = T + j` olunca $j$ dışarı alınamaz. İç toplam 1'den $2^N$'ye kadar olan sayıların toplamıdır ve içinde $i$ yoktur; $N$ tanesinin toplamı $N$ ile çarpmaktır:

$$T = \sum_{i=1}^{N} \frac{2^N(2^N+1)}{2} = N \cdot \frac{2^N(2^N+1)}{2}$$

### 9.3 İç döngü while olursa

Son $K$ örneğinde (ekrandan, 02:15:00) ilk kısım aynıdır. İkinci for $i = 1..N$ içinde `J = 1` yapılır ve bir while açılır: `J < K` olduğu sürece `T = T + 1`, `J = J * 2`.

Öğrencilerden altı yedi kişi cevap verdi; $N$ ve $N^2$ cevapları neredeyse eşit sayıdaydı, sonunda $N^2$ diyenler çoğunlukta kaldı. Hoca "Kim Milyoner Olmak İster" yarışmasındaki seyirciye sorma jokerine benzetti: seyircinin çoğunluğunun söylediği her zaman doğru olmayabilir, ama burada cevap verenler seyirci değil katılımcıdır, cevapları daha güvenilirdir.

Çözüm (ekrandan, 02:20:00): ilk döngüden sonra $K = 2^N$'dir ve while'daki $K$ yerine $2^N$ yazılabilir. Dış döngüde $i$'ye bağlı bir şey olmadığından önce iç kısmın kaç kez döndüğü bulunur, sonra $N$ ile çarpılır. $J$ birer birer artsaydı iç kısım $2^N$ kez dönerdi. Ama $J$ her seferinde iki katına çıkar. İki katına çıkarak $K$'ya giden bir değişkenle döngü $\log_2 K$ kez döner; $\log_2 2^N = N$:

$$T = \sum_{i=1}^{N} \sum_{j=1}^{\log_2 2^N} 1 = \sum_{i=1}^{N} \sum_{j=1}^{N} 1 = \sum_{i=1}^{N} N = N^2$$

Doğru cevap, çoğunluğun dediği $N^2$'dir. Burada koşulun `J < K` (küçük) olduğuna dikkat edilmelidir: $J$ = 1, 2, 4, ..., $2^{N-1}$ değerlerinde içeri girilir, $J = 2^N$ olunca koşul yanlış olur. Bu yüzden iç kısım tam $N$ kez döner (5. bölümdeki `<=` koşulunda ise $+1$ vardı).

## 10. Üç iç içe döngü ve başlangıcı değişen döngüler

### 10.1 Üç iç içe döngü

Algoritma: `T = 0`, $N$ okunur, for $i = 1..N$, for $j = 1..i$, for $k = 1..j$, gövde `T = T + 1`. Üç for var, ama formülle yazınca iş kolaylaşır:

$$T = \sum_{i=1}^{N} \sum_{j=1}^{i} \sum_{k=1}^{j} 1 = \sum_{i=1}^{N} \sum_{j=1}^{i} j = \sum_{i=1}^{N} \frac{i(i+1)}{2}$$

Hoca son toplamın $\frac{1}{2}\left(\sum i^2 + \sum i\right)$ biçiminde ilerletilebileceğini ve sonucun şu çıktığını söyledi:

$$T = \frac{N(N+1)(N+2)}{6}$$

<!-- BELİRSİZ: Bu algoritmanın çizildiği ana ait kare yok; diyagram ve formüller altyazıdan kuruldu. Sonuç python ile N = 1..8 için doğrulandı. -->

Hoca bu tür sorularda yeni alıştırma üretmenin çok kolay olduğunu belirtti: gövdedeki 1 yerine $i$, $j$ ya da $k$ yazmak, döngü sınırlarını değiştirmek gibi.

### 10.2 İç döngü 3'ten başlarsa

Algoritma (ekrandan, 02:25:00): `T = 0`, $N$ okunur, for $i = 1..N$, for $j = 3..N$, gövde `T = T + 1`.

$$T = \sum_{i=1}^{N} \sum_{j=3}^{N} 1$$

$j$ 1'den başlasaydı iç döngü $N$ kez dönerdi. 3'ten başladığı için 1 ve 2 değerleri yoktur, iç döngü $N - 2$ kez döner. Sonuç $N$ tane $N - 2$'nin toplamıdır: $T = N(N-2)$.

### 10.3 İç döngü $i$'den başlarsa

Son değişiklikte iç döngü $j = i..N$ oldu (ekrandan, 02:30:00). Öğrenciler hemen sonuca atlamaya çalıştı; hoca önce yalnız iç kısmın (tahtada kırmızıyla daire içine alınan kısım) kaç kez döndüğünü sordu. Bir önceki örnek buna hazırlıktı (ekrandan, 02:35:00):

| İç döngü | Tur sayısı |
|---|---|
| $j = 3..N$ | $N - 2$ |
| $j = 4..N$ | $N - 3$ |
| $j = 5..N$ | $N - 4$ |
| $j = i..N$ | $N - i + 1$ |

Böylece:

$$T = \sum_{i=1}^{N} \sum_{j=i}^{N} 1 = \sum_{i=1}^{N} (N - i + 1)$$

Toplamın içinde artı ve eksi olduğu için üç toplama ayrılabilir:

$$T = \sum_{i=1}^{N} N - \sum_{i=1}^{N} i + \sum_{i=1}^{N} 1 = N^2 - \frac{N(N+1)}{2} + N = \frac{N(N+1)}{2}$$

(Son eşitlik: $N^2 + N = N(N+1)$ olduğundan $N(N+1) - \frac{N(N+1)}{2} = \frac{N(N+1)}{2}$; ara adım eklendi.)

## Örnek Sorular

**Soru 1** (ekrandan, 00:15:00): $N$ okunur, `T = 0`; for $i = 1..N$, for $j = 1..N \cdot N$, gövde `T = T + 1`. Döngüler bitince $T$ kaç olur? $N = 3$ için algoritmayı çalıştırın.

> **Çözüm:** $T = \sum_{i=1}^{N}\sum_{j=1}^{N^2} 1 = N^3$. $N = 3$ için 27. (Karelerin toplamı olan 14 yanlıştır.)

**Soru 2** (ekrandan, 00:40:00): `T = 0`, `i = 1`, $N$ okunur ($N = 2^k$); `i <= N` olduğu sürece `T = T + 1`, `i = i * 2`. Sonunda $T$ kaçtır? Gövde `T = T + i` olursa ne olur?

> **Çözüm:** İlk durumda $T = \log_2 N + 1$ ($N = 32$ için 6). İkinci durumda $T = \sum_{i=0}^{\log_2 N} 2^i = 2N - 1$.

**Soru 3** (ekrandan, 01:10:00): $T = \sum_{i=0}^{N} A^i$ toplamının kapalı formunu bulun.

> **Çözüm:** $T - 1 = A(T - A^N)$ eşitliğinden $T = \frac{A^{N+1}-1}{A-1}$.

**Soru 4** (ekrandan, 01:20:00): $T = \sum_{i=0}^{N} i A^i$ neye eşittir?

> **Çözüm:** $A$ ile çarpıp çıkarınca $T(1-A) = \frac{A^{N+1}-1}{A-1} - 1 - NA^{N+1}$, buradan $T = \dfrac{\frac{A^{N+1}-1}{A-1} - 1 - NA^{N+1}}{1-A}$.

> **Çözüm (derste verilmedi):** Hocanın öğrencilere bıraktığı sadeleştirme yapılırsa ($A \neq 1$):
> $$T = \frac{A - (N+1)A^{N+1} + NA^{N+2}}{(1-A)^2}$$
> Bu ifade python ile $A$ = 2, 3, 5 ve $N$ = 0..7 için kaba toplamla karşılaştırıldı ve hocanın formülüyle aynı sonucu verdi. Örneğin $A = 2$, $N = 2$ için $\frac{2 - 3 \cdot 8 + 2 \cdot 16}{1} = 10$.

**Soru 5** (ekrandan, 01:40:00): `T = 0`, $N$ okunur; for $i = 1..N$, for $j = 1..i \cdot i$; `j mod i == 0` ise `T = T + 1`. Sonunda $T$ kaçtır? False dalından kaç kez geçilir?

> **Çözüm:** $T = \sum_{i=1}^{N} i = \frac{N(N+1)}{2}$ ($N = 4$ için 10). False dalı: $\sum_{i=1}^{N}(i^2 - i) = \frac{N(N+1)(2N+1)}{6} - \frac{N(N+1)}{2}$ ($N = 4$ için 20).

**Soru 6** (ekrandan, 02:15:00): `T = 0`, `K = 1`, $N$ okunur; for $i = 1..N$: `K = K * 2`. Sonra for $i = 1..N$: `J = 1`; `J < K` olduğu sürece `T = T + 1`, `J = J * 2`. Sonunda $T$ kaçtır?

> **Çözüm:** $K = 2^N$; iç while $\log_2 2^N = N$ kez döner; $T = N \cdot N = N^2$.

**Soru 7** (ekrandan, 02:30:00): `T = 0`, $N$ okunur; for $i = 1..N$, for $j = i..N$, gövde `T = T + 1`. Önce iç döngünün kaç kez döndüğünü, sonra $T$'yi bulun.

> **Çözüm:** İç döngü $N - i + 1$ kez döner; $T = \sum_{i=1}^{N}(N - i + 1) = N^2 - \frac{N(N+1)}{2} + N = \frac{N(N+1)}{2}$.

## Dersin Toparlaması

Bu derste döngülerin kaç kez döndüğü bulundu ve döngü içindeki ifadelerin (gövdede 1, $i$, $j$ toplanması; sınırın $N$, $N^2$, $i^2$, $2^N$ olması; değişkenin birer birer ya da iki katına çıkarak ilerlemesi) sonuca etkisi incelendi. Döngülerin toplam gösterimiyle çok rahat ifade edilebildiği görüldü: iç döngüde değişmeyen değerler toplamın dışına alınır, artı ve eksi içeren toplamlar parçalara ayrılır, bilinen formüller ($\sum i$, $\sum i^2$, $\sum i^3$, geometrik toplam) kullanılır. Bilinmeyen bir toplamda ($\sum i A^i$ gibi) amaç, cebirsel bir hileyle bilinen bir toplama indirgemektir. Hoca bu çalışmanın bir algoritmanın karmaşıklığını analiz etmek, yani algoritmanın ne kadar sürede çalıştığını ve bunun $N$'e, $N^2$'ye, $\log N$'e ya da başka bir parametreye nasıl bağlı olduğunu bulmak olduğunu vurguladı.

Bunlar özyinelemeli yapı içermeyen algoritmaların analiziydi. Sonraki derslerde önce fonksiyonlar, sonra özyinelemeli fonksiyonlar ve ardından özyinelemeli fonksiyonların analizi işlenecek. Oradaki analiz buradakinden biraz farklıdır, ama bu temel yapılabilmeden oraya geçilemez. Hoca bu dersi, ileriki yıllarda alınacak algoritma analizi dersine bir ön hazırlık olarak tanımladı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
