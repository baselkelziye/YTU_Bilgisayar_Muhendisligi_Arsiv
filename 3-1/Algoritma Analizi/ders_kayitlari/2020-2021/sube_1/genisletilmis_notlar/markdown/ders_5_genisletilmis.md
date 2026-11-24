# Ders 5 Genişletilmiş Notu: Özyinelemeli Algoritmaların Analizi, Master Teoremi ve Böl ve Yönet (Merge Sort, Quick Sort)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersin Asimptotik Gösterim Örneklerine Dönüş
- 2. Özyinelemeli Algoritmaların Matematiksel Analizi
- 3. Yineleme Bağıntılarını Çözme Yolları
- 4. Böl ve Yönet Algoritmaları
- 5. Merge Sort
- 6. Quick Sort'a Giriş
- Örnek Sorular
- Dersin Toparlaması

## 1. Önceki Dersin Asimptotik Gösterim Örneklerine Dönüş

Ders başlarken hoca, önceki derste tahtaya yazılmış iki örnek hakkında gelen soruları cevapladı. Tahtada önceki dersten kalan sayfada Big Θ tanımı duruyordu (ekrandan, 00:05:00):

$$0 \le c_1\, g(n) \le f(n) \le c_2\, g(n), \qquad n \ge n_0 > 0$$

Bu durumda $f(n) \in \Theta(g(n))$ yazılır ve "$f(n)$, $g(n)$'e asimptotik olarak eşittir" denir. Θ bir sıkı sınırdır (tight bound): $f(n)$ hem üstten hem alttan $g(n)$'in sabit katlarıyla sınırlanır.

### 1.1 $n^2 + n \in O(n)$ yanlış bir iddiadır

Bir öğrenci, önceki dersteki bir örneğin hatalı olup olmadığını e-postayla sormuştu. Hoca, o örneğin zaten **yanlış** bir duruma örnek olarak verildiğini, tahtada yanında bir çarpı işareti olduğunu açıkladı. İncelenen soru şuydu: $n^2 + n \le c \cdot n$ şartı sağlanıyor mu?

$c = 5$, $n_0 = 1$ seçilsin:

- $n = 1$: $2 \le 5$, sağlanır.
- $n = 2$: $6 \le 10$, sağlanır.
- $n = 3$: $12 \le 15$, sağlanır.
- $n = 4$: $20 \le 20$, sağlanır.
- $n = 5$: $30 \le 25$, **sağlanmaz**.

$n$, 5'e ulaştığı anda şart bozulur ve bundan sonra bir daha sağlanmaz. Kural ise şartın bir $n_0$ noktasından itibaren **sürekli** sağlanmasıdır. Küçük $n$'lerde sağlanması yetmez; bu yüzden $n^2 + n \notin O(n)$ (python ile doğrulandı). Buna karşılık $n^2 + n \in O(n^3)$ demek doğrudur, çünkü $c \cdot n^3$ büyüdükçe $n^2 + n$'yi her zaman kapsar.

> **Hocanın vurgusu:** Bu örneği yanlış anlayıp doğru sanmak sınavlarda sorun çıkarır; şart, $n_0$'dan sonra her $n$ için sağlanmalıdır.

### 1.2 $2n + 5 \in \Theta(n)$ ve alt sınır sabitinin seçimi

Bir başka öğrenci, $2n + 5 \in \Theta(n)$ örneğinde alt sınır için seçilen sabitin hatalı olduğunu söyledi. $\Theta(n)$ diyebilmek için hem $O(n)$ hem de $\Omega(n)$ şartının sağlanması gerekir.

Üst sınır ($O(n)$) için $2n + 5 \le c \cdot n$ incelenir. $n_0 = 1$, $c = 7$ seçilirse $n = 1$ için $7 \le 7$, $n = 2$ için $9 \le 14$ olur ve eşitsizlik bundan sonra hep sağlanır.

Alt sınır ($\Omega(n)$) için önceki derste $c_2 = 4$ seçilmişti: $2n + 5 \ge 4n$.

- $n = 1$: $7 \ge 4$, sağlanır.
- $n = 2$: $9 \ge 8$, sağlanır.
- $n = 3$: $11 \ge 12$, **sağlanmaz**.

Hoca öğrencinin haklı olduğunu kabul etti: eşitsizlik doğru olsa bile önemli olan seçilen sabit ve $n_0$ değeridir; $c_2$ yanlış seçilmişti. Düzeltilmiş değeri daha sonra hesaplayacağını söyledi.

> **Ders sonrası not:** Kayıtta düzeltilmiş sabit verilmedi. Örneğin $c_2 = 2$ (ya da $c_2 = 1$) seçilirse $2n + 5 \ge 2n$ her $n \ge 1$ için sağlanır. Böylece $2n + 5 \in \Omega(n)$, dolayısıyla $2n + 5 \in \Theta(n)$ olur (python ile doğrulandı).

## 2. Özyinelemeli Algoritmaların Matematiksel Analizi

Tahtanın başlığı "Mathematical Analysis of Recursive Function" idi (ekrandan, 00:10:00). Önceki derste rekürsif olmayan algoritmaların analizi yapılmıştı: bir temel işlem (basic operation) belirlenir; bu, en çok tekrar eden, genellikle bir döngü (`while`) içinde $n$'e bağlı olarak tekrar eden işlemdir ve karmaşıklık bu işlemin kaç kez yapıldığına göre hesaplanır. Rekürsif algoritmalarda ise fonksiyon kendi kendini çağırdığı için hesap farklı yapılır.

### 2.1 Faktöriyel örneği

Hoca, rekürsiyonu anlatmak için en kolay örnek olan faktöriyelle başladı (aslında rekürsif yazılması gerekmediğini de belirtti). $n! = 1 \cdot 2 \cdots n$'dir ve şöyle yazılabilir:

$$n! = n \cdot (n-1)!, \qquad (n-1)! = (n-1) \cdot (n-2)!, \qquad \dots, \qquad 0! = 1$$

Buna göre faktöriyel fonksiyonu:

$$F(n) = \begin{cases} 1 & n = 0 \\ n \cdot F(n-1) & n > 0 \end{cases}$$

Kod karşılığında durma şartı $n = 0$'dır ve 1 döndürülür; değilse `n * factorial(n-1)` döndürülür.

Burada tekrar eden temel işlem $n \cdot F(n-1)$ çarpmasıdır (ekrandan, 00:15:00). $M(n)$, $F(n)$ hesaplanırken yapılan çarpma sayısı olsun:

$$M(n) = M(n-1) + 1$$

Buradaki $M(n-1)$, `factorial(n-1)` hesabı içinde yapılan çarpmalardır; $+1$ ise en sonda $n$ ile `factorial(n-1)`'in çarpılmasıdır (ekrandan, 00:15:00).

### 2.2 Geriye doğru yerine koyma ile çözüm

$M(n) = M(n-1) + 1$ açık bir ifade değildir: $M(n-1)$'in kaç olduğu bilinmez, çünkü bu da bir fonksiyon çağrısıdır. Çözme yollarından biri **geriye doğru yerine koyma** (backward substitution) yöntemidir. $M(n-1) = M(n-2) + 1$ olduğundan (ekrandan, 00:20:00):

$$\begin{aligned}
M(n) &= M(n-1) + 1 \\
&= [M(n-2) + 1] + 1 = M(n-2) + 2 \\
&= M(n-3) + 1 + 2 = M(n-3) + 3 \\
&= M(n-i) + i
\end{aligned}$$

Geriye doğru giderken bir kalıp (pattern) görülür, ama hâlâ bir indirgeme yapılamamıştır: $M(n-2)$ için $M(n-3)$'e, onun için $M(n-4)$'e ihtiyaç vardır. Bu nereye kadar gider? Rekürsif fonksiyon $n = 0$ olunca durur; değeri bilinen tek nokta $M(0)$'dır.

**Soru (hoca sınıfa):** $M(0)$ neye eşittir?
**Cevap:** Bir öğrenci 1 dedi. Hoca, $n = 0$ kontrolü bir işlem sayılırsa 1 de denebileceğini, ama burada çarpma sayıldığı ve $n = 0$ iken hiç çarpma yapılmadığı için $M(0) = 0$ demenin daha doğru olduğunu söyledi.

$M(n-i)$'nin $M(0)$ olması için $n - i = 0$, yani $i = n$ olmalıdır. O zaman:

$$M(n) = M(n - n) + n = M(0) + n = n$$

Faktöriyel hesabında sürpriz yoktur: en iyi, ortalama ve en kötü durum birbirine eşittir (tahtada "Best C = Average C = Worst C", ekrandan 00:20:00). Bu yüzden en doğru gösterim

$$M(n) \in \Theta(n)$$

olur (python ile doğrulandı: $M(0..5) = 0, 1, 2, 3, 4, 5$).

### 2.3 Yineleme bağıntısı ve analiz adımları

$M(n) = M(n-1) + 1$ türü ifadelere **yineleme bağıntısı** (recurrence relation, kısaca recurrence) denir (ekrandan, 00:25:00). Yineleme bağıntısı, fonksiyonun rekürsif bir tanımıdır ("recursive description of function"). Faktöriyel için tam bağıntı:

$$M(n) = M(n-1) + 1 \;\; (n > 0), \qquad M(0) = 0$$

Rekürsif bir algoritmanın analiz adımları (ekrandan, 00:25:00):

1. Temel işlemi belirle (Identify the basic operation). Rekürsif algoritmada bu, kendi kendini çağıran bölümdür.
2. Rekürsif işlem için yineleme bağıntısını kur (Setup a recurrence relation for recursive operation). Durma noktası da yazılır.
3. Bağıntıyı, durma noktasını kullanarak çöz.

### 2.4 İkili gösterimdeki basamak sayısı

İkinci örnek: pozitif bir ondalık tamsayının ikili gösteriminde kaç basamak vardır? (Tahtada: "Find the number of binary digits in the binary representation of a positive decimal integer", ekrandan 00:30:00.)

**Soru (hoca sınıfa):** 27'nin ikili karşılığını ve kaç basamaklı olduğunu nasıl bulursunuz?
**Cevap:** Bir öğrenci "sürekli 2'ye bölerek" dedi. Hoca onayladı.

27'nin bölümleri tahtada şöyle yazıldı (ekrandan, 00:30:00):

| Bölünen | Bölüm | Kalan |
|---|---|---|
| 27 | 13 | 1 |
| 13 | 6 | 1 |
| 6 | 3 | 0 |
| 3 | 1 | 1 |
| 1 | — | 1 |

Kalanlar sondan başa okunur: $27 = 11011_2$ (basamak değerleri $16 + 8 + 2 + 1$). Her bölmede bir basamak daha bulunur; sayı 1'e inince durulur. Toplam 5 basamak vardır (python ile doğrulandı). Hoca önce 27'nin yarısını yanlışlıkla 18 dedi; bir öğrenci 13 olacağını söyledi, hoca düzeltti.

Algoritma: $n$ 1 olana kadar 2'ye böl ve her bölmede bir basamak say. Rekürsif kod (ekrandan, 00:35:00):

```c
int binaryDigits(int n)
{
    if (n == 1)
        return 1;
    else
        return binary(n/2) + 1;   /* 1 digit daha oldu! */
}
```

<!-- BELİRSİZ: Tahtada fonksiyon adı tanımda binaryDigits, rekürsif çağrıda binary olarak yazılmış; aynı fonksiyon kastediliyor. -->

**Soru (hoca sınıfa):** Durma şartı nedir?
**Cevap:** Bir öğrenci "sayı, yani $n$ 1 olunca" dedi. $n = 1$ ise tek bir ikili basamak vardır, 1 döndürülür. Değilse fonksiyon $n/2$ için tekrar çağrılır.

**Soru:** Sondaki $+1$ sayaç olarak mı kullanılıyor?
**Cevap:** Evet. $n$ 1'den farklı olduğu için bu adımda bir basamak daha bulunmuştur; `binary(n/2) + 1` bunu sayar. Örneğin 27, 2'ye bölününce bir basamak çıkar, sonra 13 için çağrılır; 13 bölününce bir basamak daha çıkar, sonra 6 için çağrılır.

**Soru:** Bu problemde 0 ele alındı mı?
**Cevap:** Hayır; problem özellikle pozitif sayılar için tanımlandı, negatifler de yok.

Temel işlem `binary(n/2) + 1` satırındaki toplamadır. $A(n)$ toplama sayısı olsun (ekrandan, 00:35:00):

$$A(n) = A(n/2) + 1 \;\; (n > 1), \qquad A(1) = 0$$

$A(1) = 0$'dır, çünkü $n = 1$ iken toplama yapılmaz. Hoca, kaç işlem yapıldığına bakılırsa $n = 1$ kontrolü nedeniyle burada 1 de görülebileceğini, ama temel işlem toplama olduğu için 0'ın doğru olduğunu belirtti.

Geriye doğru yerine koyma:

$$\begin{aligned}
A(n) &= A(n/2) + 1 \\
&= [A(n/4) + 1] + 1 = A(n/4) + 2 \\
&= [A(n/8) + 1] + 2 = A(n/8) + 3 \\
&= A(n/2^i) + i
\end{aligned}$$

Kalıp yine görüldü ama $A(n/2^i)$ hâlâ bilinmiyor. Durma noktası $A(1)$'dir: $n = 2^i$ alınırsa $n/2^i = 1$ olur. $n = 2^i$ ise $i = \log_2 n$'dir (bir öğrenci cevapladı). O zaman:

$$A(n) = A(2^i / 2^i) + \log_2 n = A(1) + \log_2 n = \log_2 n$$

Toplama sayısı $\log_2 n$'dir, yani $A(n) \in \Theta(\log n)$ (python ile $n = 2^k$ için doğrulandı: $A(2^k) = k$).

> **Ek bilgi (derste anlatılmadı):** $n$ ikinin kuvveti değilse kodda tamsayı bölmesi yapıldığından toplama sayısı $\lfloor \log_2 n \rfloor$, basamak sayısı $\lfloor \log_2 n \rfloor + 1$ olur. 27 için toplama sayısı 4, basamak sayısı 5'tir.

## 3. Yineleme Bağıntılarını Çözme Yolları

### 3.1 Geriye doğru yerine koyma (backward substitution)

Aradan sonra hoca, birinci yöntem olan geriye doğru yerine koymaya bir örnek daha verdi:

$$x(n) = x(n-1) + n, \qquad x(0) = 0$$

> **Hocanın vurgusu:** Durma şartını ($x(0) = 0$ gibi) her zaman yazmanız lazım.

$$\begin{aligned}
x(n) &= x(n-1) + n \\
&= [x(n-2) + (n-1)] + n \\
&= [x(n-3) + (n-2)] + (n-1) + n \\
&= x(n-i) + (n-i+1) + (n-i+2) + \dots + n
\end{aligned}$$

$i = n$ alınınca $x(0) = 0$ olur, kalan terimler $1, 2, \dots, n$'dir:

$$x(n) = 1 + 2 + \dots + n = \frac{n(n+1)}{2}$$

Bu $n^2$ mertebesindedir; problem hakkında başka bilgi (en kötü, en iyi durum) olmadığından hoca $O(n^2)$ yazdı (python ile doğrulandı).

> **Ders sonrası not:** Altyazıda bir ara adım "$xn-3 + 3n - 3$" olarak geçiyor. $x(n-3) + (n-2) + (n-1) + n = x(n-3) + 3n - 3$ olduğundan bu ifade doğrudur.

### 3.2 İleriye doğru yerine koyma (forward substitution)

İkinci yöntem ileriye doğru yerine koymadır (ekrandan, 00:55:00):

$$x(n) = 2x(n-1) + 1 \;\; (n > 1), \qquad x(1) = 1$$

Değerler küçük $n$'den başlanarak tek tek hesaplanır:

- $n = 1$: $x(1) = 1$
- $n = 2$: $x(2) = 2x(1) + 1 = 3$
- $n = 3$: $x(3) = 2x(2) + 1 = 2 \cdot 3 + 1 = 7$
- $n = 4$: $x(4) = 15$

Buradan $x(n) = 2^n - 1$ olduğu görülür (python ile $n \le 30$ için doğrulandı); yani bu üstel, $2^n$ karmaşıklıkta bir problemdir. Hoca, ileriye doğru yerine koymanın geriye doğru yerine koyma kadar kolay olmadığını, değerleri tek tek hesaplamanın çok daha zaman alıcı olduğunu söyledi.

<!-- BELİRSİZ: Altyazıda sonuç "2 üzeri n-1" diye geçiyor; değerler (1, 3, 7, 15) 2^n - 1'e uyuyor, ifade bu biçimde yazıldı. -->

### 3.3 Master teoremi

Üçüncü yol, bağıntının biçiminden hazır sonuç veren **master teoremidir**. Bağıntı şu biçimde olsun (ekrandan, 01:00:00 ve 01:10:00):

$$T(n) = a\,T\!\left(\frac{n}{b}\right) + f(n), \qquad T(1) = c, \qquad f(n) \in \Theta(n^d),\; d \ge 0$$

- $a$: rekürsif olarak çözülmesi gereken alt problem sayısı.
- $n/b$: her alt problemin büyüklüğü. Örneğin ikili basamak örneğinde alt problem $n/2$ idi; faktöriyelde ise $n-1$ idi.
- $f(n)$: rekürsif çağrıların dışında yapılan ek iş. Örneğin merge sort'ta dizi ikiye bölünerek geriye doğru çağrılır, her seferinde de iki sıralı parça birleştirilir (merge); bu birleştirme işi $f(n) = n$'dir.

Teorem (ekrandan, 01:10:00):

$$T(n) \in \begin{cases}
\Theta(n^d) & a < b^d \\
\Theta(n^d \log n) & a = b^d \\
\Theta(n^{\log_b a}) & a > b^d
\end{cases}$$

Tahtada bunun altına "Ω, O için de geçerli" yazıldı: asimptotik gösterim ne olursa olsun, bu taraftaki ifadeye odaklanılır.

> **Hocanın vurgusu:** Master teoremiyle backward ya da forward substitution gibi uzun hesap yapmanız gerekmez. Yalnız $a$, $b$ ve $d$'yi bulup $a$'nın $b^d$'den küçük, eşit ya da büyük olduğuna bakar, karşılık gelen ifadeyi yazarsınız.

**$d$ nasıl bulunur?** Bir öğrenci $d$'nin nasıl bulunduğunu kaçırdığını söyledi. Hoca açıkladı: $f(n)$, rekürsif çağrı dışında yapılan iştir. Faktöriyelde ek iş yoktur, yalnız $n \cdot F(n-1)$ yapılır. İkili basamak örneğinde fonksiyon kendini $n/2$ için çağırır ve ek olarak bir toplama ($+1$) yapar; bu ek iş $n$'e bağlı olmadığı için $f(n) = 1 = n^0$, yani $d = 0$'dır. Merge sort'ta ek iş birleştirmedir, $f(n) = n = n^1$, yani $d = 1$'dir.

#### Örnek: $T(n) = 3T(n/2) + n^2$

$a = 3$, $b = 2$, $d = 2$ (çünkü $f(n) = n^2$). $3 < 2^2 = 4$ olduğundan birinci durum geçerlidir:

$$T(n) \in \Theta(n^2)$$

#### Örnek: $T(n) = T(2n/3) + 1$

Tahtaya önce $a = 1$, $b = 2/3$, $d = 0$ yazıldı ve $1 = (2/3)^0$ olduğundan ikinci durumdan $T(n) \in O(n^0 \log n) = O(\log n)$ bulundu (ekrandan, 01:10:00). Hoca önce $a$'yı yanlışlıkla 2 dedi, $T$'nin önünde çarpan olmadığı için hemen 1 olarak düzeltti.

**Soru:** $b$'nin $3/2$ olması gerekmiyor mu?
**Cevap:** Hoca öğrencinin haklı olduğunu söyledi: bağıntı $T(n/b)$ biçiminde olduğu için $n/b = 2n/3$'ten $b = 3/2$ olur. Sonuç değişmez, çünkü $d = 0$ iken $b^0 = 1$'dir ve yine $a = b^d$ durumu geçerlidir: $T(n) \in \Theta(\log n)$.

**Soru:** İleriye doğru yerine koyma örneğindeki $x(n) = 2x(n-1) + 1$ bağıntısına master teoremi uygulanabilir mi? İçinde $n-1$ var.
**Cevap:** Uygulanamaz. Hoca, master teoreminin uygulanabilmesi için bağıntının teoremdeki $n/b$ biçimine (polinomsal biçime) uyması gerektiğini söyledi.

#### Hocanın ikili basamak örneğine uygulaması

Hoca teoremi ikili basamak örneğine de uyguladı. Bağıntıyı $2A(n/2) + 1$ olarak yazdı: $a = 2$, $b = 2$, $d = 0$. $2 > 2^0 = 1$ olduğundan üçüncü durumdan $\Theta(n^{\log_2 2}) = \Theta(n)$ buldu.

> **Ders sonrası not:** İkili basamak örneğinde kurulan bağıntı $A(n) = A(n/2) + 1$'dir (ekrandan, 01:05:00); fonksiyon kendini yalnız bir kez çağırır, yani $a = 1$'dir. Doğrusu $a = 1$, $b = 2$, $d = 0$, $1 = 2^0$ olduğundan ikinci durum geçerlidir: $A(n) \in \Theta(n^0 \log n) = \Theta(\log n)$. Bu, geriye doğru yerine koyma ile bulunan $\log_2 n$ ile uyumludur. Hocanın bulduğu $\Theta(n)$ yalnız $T(n) = 2T(n/2) + 1$ bağıntısı için doğrudur.

## 4. Böl ve Yönet Algoritmaları

Rekürsiyonun en çok kullanıldığı algoritma türleri böl ve yönet (divide and conquer) ve azalt ve yönet (decrease and conquer) algoritmalarıdır. Hoca, bu konulara önceki yıl veri yapıları dersinde başlandığını, bu derste ise algoritmaların analizi üzerinden gidileceğini söyledi.

### 4.1 Fikir ve bir benzetme

Böl ve yönet, hocanın ifadesiyle Romalılar zamanından kalma bir yaklaşımdır: Düşman bir bütün olarak karşındaysa onunla baş etmek zordur; onu bölersen rahat yönetirsin ve sana zarar vermesini zorlaştırırsın. Algoritmalarda da elimizdeki bilgiyi bölmek daha etkili bir çözüm sağlıyorsa bölünür, her parça için işlem yapılır, sonra alt parçaların çözümleri birleştirilerek ana çözüm elde edilir.

Bir problemle karşılaşıldığında sorulması gereken soru şudur: Bunu böldüğümde bir şey kazanacak mıyım?

### 4.2 Bölmenin kazancı: selection sort ve quick sort karşılaştırması

Hoca kazancı iki sıralama yöntemiyle karşılaştırdı (ekrandan, 01:15:00).

Selection sort $n^2$ karmaşıklıklıdır, çünkü her adımda kalan bütün elemanlara bakar. 9 8 7 14 5 2 dizisinde en küçük eleman (2) $n-1$ karşılaştırmayla bulunup başa alınır: 2 8 7 14 5 9. Sonraki en küçük için $n-2$ karşılaştırma yapılır, sonra $n-3$ ve bu böyle $n$'e bağlı olarak sürer.

Quick sort'ta bir pivot seçilir (örnekte dizinin ilk elemanı 4) ve pivottan küçükler bir tarafa, büyükler diğer tarafa yerleştirilir. Tahtadaki örnekte 4 15 2 7 9 13 11 dizisi, solda 4'ten küçükler, ortada 4, sağda 15 7 13 11 olacak biçimde ayrıldı (ekrandan, 01:15:00). Pivot yerine oturduktan sonra sol parça kendi içinde, sağ parça kendi içinde sıralanır. Sol parçayı sıralarken sağa bakmaya gerek yoktur, çünkü sağdaki hiçbir eleman başa gelemez.

> **Hocanın vurgusu:** Algoritmanızı tasarlarken bölmenin size gerçekten böyle bir fayda sağlayıp sağlamadığına bakmalısınız.

### 4.3 Böl ve yönetin yapısı

Böl ve yönet algoritmalarında $n$ elemanlı bir problem genellikle iki parçaya bölünür. Parçaların tam eşit olması gerekmez, ama amaç yaklaşık eşit bölmektir. Her parça birbirine karışmadan ayrı ayrı çözülür ve sonunda iki parçanın çözümü birleştirilir. Tahtadaki şema (ekrandan, 01:35:00):

```text
                problem of size n
               /                 \
 subproblem 1 of size n/2    subproblem 2 of size n/2
          |                            |
 solution to subproblem 1    solution to subproblem 2
               \                 /
         solution to the original problem
```

İşlem üç aşamalıdır:

1. **Divide (böl):** Elinizdeki bilgiyi parçalara bölün.
2. **Conquer (yönet):** Her parça için ayrı iş yapın.
3. **Combine (birleştir):** Parçalardaki işlemler bitince sonuçları birleştirerek bütün sonucu elde edin.

Böl ve yönet algoritmaları rekürsiftir: her parça da kendi içinde aynı biçimde bölünerek çözülür; parçanın yarısı da ikiye bölünür, o da ikiye bölünür. Hoca, her böl ve yönet algoritmasının şahane çalıştığını söylemenin yanlış olduğunu; bütün problemlerin bu yaklaşıma uygun olmadığını ve uygun problemlerin belirlenmesi gerektiğini vurguladı. En bilinen başarılı örnekler merge sort ve quick sort'tur.

## 5. Merge Sort

### 5.1 Mantık

Merge (birleştirme), iki sıralı diziyi tek bir sıralı dizi hâline getirmektir. Merge sort'un fikri şudur: elimdeki dizi iki sıralı diziden oluşsaydı onları birleştirirdim. Sıralı değillerse bölmeye devam edilir. Örnek dizi: 8 3 2 9 7 1 5 4.

- Dizi ortadan ikiye bölünür: 8 3 2 9 ve 7 1 5 4. Bunlar sıralı değildir, birleştirilemez.
- Tekrar bölünür: 8 3 ve 2 9. Hâlâ sıralı değildir.
- Tekrar bölünür: 8 ve 3; 2 ve 9. Artık tek elemanlı parçalar vardır ve tek eleman sıralıdır.
- 8 ile 3 birleştirilir: 3 8. 2 ile 9 birleştirilir: 2 9.
- 3 8 ile 2 9 birleştirilir: 2 3 8 9.
- Sağ yarıda 7 ve 1 birleşerek 1 7, 5 ve 4 birleşerek 4 5, bunlar da birleşerek 1 4 5 7 olur.
- Son birleştirme: 1 2 3 4 5 7 8 9 (python ile doğrulandı).

Dizi önce birer eleman kalana kadar bölünür, sonra birleştirerek ("toplaya toplaya") geri dönülür. Bu yönteme **top-down merge sort** denir (ekrandan, 01:40:00); bir de bottom-up biçimi vardır.

### 5.2 Kod iskeleti

$A[0..n-1]$ dizisi $A[0..n/2-1]$ ve $A[n/2..n-1]$ olarak ikiye bölünür. Fonksiyon, A dizisinin $p$'den $r$'ye kadar olan kısmıyla çalışır; ilk çağrıda $p = 0$, $r = n-1$'dir. Kod (ekrandan, 01:50:00):

```c
mergesort(A, p, r)
{
    if (p < r)
    {
        q = (p + r) / 2;
        mergesort(A, p, q);
        mergesort(A, q + 1, r);
        merge(A, p, q, r);
    }
}
```

$p < r$ ise en az iki eleman vardır. $p = r$ ise (örneğin ikisi de 3) tek eleman kalmıştır; bu durma noktasıdır ve fonksiyon bir şey yapmadan döner. Önce sol taraf ($p..q$), sonra sağ taraf ($q+1..r$) için merge sort çağrılır, sonra iki parça birleştirilir.

### 5.3 Çağrıların izlenmesi

8 3 2 9 7 1 5 4 dizisinde indisler 0'dan 7'ye kadardır (ekrandan, 01:50:00):

- $ms(0,7)$: $p = 0$, $r = 7$, $q = 7/2 = 3$. Önce $ms(0,3)$ çağrılır.
- $ms(0,3)$: $q = 3/2 = 1$. Önce $ms(0,1)$ çağrılır.
- $ms(0,1)$: $q = 1/2 = 0$. $ms(0,0)$ çağrılır: tek eleman (8), geri döner. Sonra $ms(1,1)$: tek eleman (3), geri döner. $merge(0,0,1)$ ile 3 8 elde edilir.
- $ms(0,3)$'e dönülür; şimdi $ms(q+1, r) = ms(2,3)$ çağrılır: $q = (2+3)/2 = 2$; $ms(2,2)$ (2) ve $ms(3,3)$ (9) tek elemandır; birleştirme 2 9'u verir.
- $merge(0,1,3)$: 0–1 aralığı (3 8) ile 2–3 aralığı (2 9) birleştirilir: 2 3 8 9.

> **Ders sonrası not:** Tahtada $ms(2,2) \to 9$ ve $ms(3,3) \to 7$ yazıldı (ekrandan, 01:50:00). Hoca bunu fark ederek "şurası 2 olacak" diye düzeltti. Dizinin 2. gözünde 2, 3. gözünde 9 vardır; doğrusu $ms(2,2) \to 2$ ve $ms(3,3) \to 9$'dur. Bu yüzden ara sonuç 7 9 ve 3 7 8 9 değil, 2 9 ve 2 3 8 9'dur.

Hoca bu izlemede algoritmanın iki avantajını gösterdi. Birincisi, sol yarı sıralanırken sağ yarıya hiç bakılmaz; sekiz elemanın hepsini birbiriyle karşılaştırmak yerine her yarı kendi içinde sıralanır. İkincisi, birleştirilen parçalar zaten sıralı olduğu için bir eleman bütün elemanlarla karşılaştırılmaz; örneğin 8 yalnız 3 ile karşılaştırılır.

### 5.4 Merge işlemi

Hoca, merge işlemini öğrencilerin birinci sınıftan beri bildiğini söyleyerek yalnız ana hatlarıyla yazdı (ekrandan, 01:55:00):

```c
void merge(int A[], int p, int q, int r)
{
    int i, j, k, n, *B;   /* B: malloc ile yer tutulur */
    i = p;
    j = q + 1;
    while ((i <= q) && (j <= r))
    {
        if (A[i] <= A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    /* biten dizi dışındaki kalan elemanlar B'ye eklenir */
    /* B, A'ya geri kopyalanır */
}
```

Kodun döngü gövdesi ve son iki adım tahtaya yazılmadı, sözlü anlatıldı. Burada önemli olan, iki parçanın ayrı diziler değil aynı A dizisinin iki parçası olmasıdır. Tahtadaki örnekte A = 4 9 3 7; $p = 0$, $q = 1$, $q+1 = 2$, $r = 3$'tür ve 4 9 ile 3 7 birleştirilecektir (ekrandan, 01:55:00). Her çağrıda parça boyu değiştiği için B dizisine `malloc` ile yer alınır.

Birleştirmeyi A üzerinde yer değiştirerek yapmak sırayı bozar. Hocanın örneğinde parçalar 8 9 ve 2 7 olsun. 2 ile 8 karşılaştırılır; 2 başa konup 8, 2'nin yerine konursa 8, 7'den önce kalır ve sağ parçanın sırası bozulur. Bu yüzden yedek dizi (B) kullanılır: küçük eleman B'ye yazılır, dizilerden biri bitince bitmeyenin kalanı B'ye eklenir ve en sonda B, A'ya kopyalanır, çünkü sonuç asıl A üzerinde olmalıdır.

### 5.5 Merge sort'un analizi

$n = 1$ ise yapılacak iş yoktur. $n > 1$ ise fonksiyon $n/2$ elemanlı iki parça için kendini çağırır ve bir kez de merge yapar. Merge'ün karmaşıklığı $n$'dir. Bağıntı (ekrandan, 02:00:00):

$$T(n) = \begin{cases} 1 & n = 1 \\ 2\,T(n/2) + n & n > 1 \end{cases}$$

Geriye doğru yerine koyma:

$$\begin{aligned}
T(n) &= 2T(n/2) + n \\
&= 2\left[2T(n/4) + \frac{n}{2}\right] + n = 4T(n/4) + 2n \\
&= 4\left[2T(n/8) + \frac{n}{4}\right] + 2n = 8T(n/8) + 3n \\
&= 2^i\,T(n/2^i) + i\,n
\end{aligned}$$

Hoca son satırı önce $T(n/2^i) + i \cdot n$ biçiminde yazdı; bir öğrencinin uyarısıyla $T(n/2^i)$'nin önüne $2^i$ katsayısını ekledi. Durması için $n/2^i = 1$, yani $n = 2^i$, $i = \log_2 n$ olmalıdır:

$$T(n) = n \cdot T(1) + n \log_2 n = n + n \log_2 n$$

Büyük terim alınır (python ile $n = 2^k$ için doğrulandı).

**Soru (hoca sınıfa):** $O$ mu yazayım, $\Theta$ mı?
**Cevap:** Bir öğrenci $O$ yazmanın daha mantıklı olduğunu, sonucun her zaman böyle olmayabileceğini söyledi. Hoca, burada sürprizle karşılaşılmadığını açıkladı: merge sırasında `while` bittikten sonra kalan elemanlar da yerleştirildiği için her durumda $n$ elemanın hepsi için işlem yapılır; merge sort da diziyi her durumda ikiye bölerek bütün parçalar için çalışır. En iyi, ortalama ve en kötü durum aynıdır, bu yüzden

$$T(n) \in \Theta(n \log n)$$

yazılabilir. (Hoca, "sürprizli durumlar her zaman olabilir, çok emin konuşmayayım" diye de ekledi.)

> **Ek bilgi (derste anlatılmadı):** Aynı sonuç master teoremiyle de bulunur: $a = 2$, $b = 2$, $d = 1$ ve $2 = 2^1$ olduğundan ikinci durum geçerlidir, $T(n) \in \Theta(n^1 \log n)$. Hoca bunu master teoremiyle de göstereceğini söylemişti, ama kayıtta yalnız geriye doğru yerine koyma yapıldı.

### 5.6 Merge sort için iki pratik iyileştirme

Tahtaya iki öneri yazıldı (ekrandan, 02:05:00):

1. **Küçük alt diziler için insertion sort kullanın** ("Use insertion sort for small subarrays"). Küçük dizilerde rekürsiyonun ek yükü (overhead) daha fazladır; on eleman için merge sort kullanmaya değmez. Hoca, aynı şeyin quick sort için de geçerli olduğunu ve Java'nın sıralama kütüphanesinin küçük diziler için insertion sort çağırdığını söyledi.
2. **Zaten sıralıysa durun** ("Stop if already sorted"). Birinci yarının en büyük elemanı ikinci yarının en küçük elemanından küçük ya da eşitse birleştirmeye gerek yoktur. Örneğin 3 5 7 9 ile 11 17 23 25 birleştirilecekse 9 ≤ 11 olduğu için dizi zaten sıralıdır. Hoca, örneğin bir milyon elemanlı dizinin 50 binlik parçaları birleştirilirken bu tek kontrolün bir yavaşlık getirmediğini söyledi.

## 6. Quick Sort'a Giriş

Merge sort diziyi konuma göre, ortadan ikiye bölerek ilerler. Quick sort ise **değere göre** böler: pivot olarak seçilen eleman, dizi sıralı olsaydı nerede olacaksa parçalar oradan ayrılır. Bu yüzden tam ortadan bölme gibi bir durum yoktur; bu hem avantaj hem dezavantaj olabilir. Hoca, quick sort'un 20. yüzyılın ilk 10 algoritmasından biri seçildiğini ve en çok kullanılan sıralama algoritması olduğunu söyledi.

### 6.1 Bölme (partition) örneği

Dizi: 5 3 1 9 8 2 4 7 (indisler 0–7). En basit hâliyle ilk eleman pivot alınır: pivot = 5 (ekrandan, 02:10:00). Soldan, pivottan küçük olduğu sürece ilerlenir; büyük bir eleman bulununca sondan gelinerek küçük bir eleman aranır ve ikisi yer değiştirir.

- 3 < 5, 1 < 5: devam. 9 > 5: dur.
- Sondan: 7 > 5, yerinde kalabilir. 4 < 5: 9 ile 4 yer değiştirir → 5 3 1 4 8 2 9 7.
- Soldan: 8 > 5: dur. Sondan: 2 < 5: 8 ile 2 yer değiştirir → 5 3 1 4 2 8 9 7.
- Son bulunan küçük eleman 2'dir; 2 ile pivot 5 yer değiştirir → 2 3 1 4 **5** 8 9 7.

5 artık yerine oturmuştur: solunda hep 5'ten küçükler, sağında hep büyükler vardır (ekrandan, 02:10:00). Sol taraf sıralanırken sağa bakmaya gerek yoktur.

> **Hocanın vurgusu:** Bu algoritmanın bu kadar değerli olmasının sebebi budur: bakmaya gerek olmayan elemanlarla hiç uğraşılmaz. Selection sort gibi bilinen yöntemler $n^2$ karmaşıklıkla çalışırken quick sort ve merge sort'un $n \log n$ olmasının sebebi bu.

Sonra iki taraf aynı mantıkla sıralanır:

- Sol parça 2 3 1 4, pivot 2: 3 > 2 dur; sondan 4 > 2, 1 < 2; 3 ile 1 yer değiştirir → 2 1 3 4. Sonra 2 ile 1 yer değiştirir → 1 **2** 3 4. 2'nin solunda tek eleman kaldığı için 1 de yerleşir. Sağda 3 pivot alınır; 3 ve 4 de yerleşir.
- Sağ parça 8 9 7, pivot 8: 9 > 8, sondan 7 < 8; 9 ile 7 yer değiştirir → 8 7 9. Sonra pivot 8 ile 7 yer değiştirir → 7 **8** 9. 8'in iki yanında tek eleman kalır.
- Sonuç: 1 2 3 4 5 7 8 9 (python ile doğrulandı).

Pivot seçimi ve quick sort'un karmaşıklığı sonraki derste ayrıntılı incelenecek.

### 6.2 Çalışma süresi karşılaştırması

Hoca, saniyede $10^8$ karşılaştırma yapan bir ev bilgisayarı için şu süreleri verdi:

| $n$ | Insertion sort | Merge sort | Quick sort |
|---|---|---|---|
| binler mertebesi | fark anlaşılmıyor | fark anlaşılmıyor | fark anlaşılmıyor |
| milyon ($10^6$) | 2,8 saat | 1 saniye | 0,6 saniye |
| milyar ($10^9$) | 317 yıl | 18 dakika | 12 dakika |

Insertion sort $n^2$, diğer ikisi $n \log n$ karmaşıklıktadır. Insertion sort satırı $n^2 / 10^8$ hesabıyla uyumludur: $10^{12}/10^8 = 10^4$ saniye ≈ 2,8 saat ve $10^{18}/10^8 = 10^{10}$ saniye ≈ 317 yıl (python ile doğrulandı).

> **Ek bilgi (derste anlatılmadı):** Bu tablo büyük olasılıkla Sedgewick ve Wayne'in *Algorithms* kitabındaki benzer tablodan alınmıştır. $n \log_2 n / 10^8$ hesabı $n = 10^6$ için yaklaşık 0,2 saniye, $n = 10^9$ için yaklaşık 5 dakika verir; tablodaki daha büyük süreler, sabit çarpanları da içeren ölçümlerden gelir.

Quick sort'un merge sort'a tercih edilmesinin sebebi biraz daha hızlı olmasıdır; daha az yer değiştirme yapar. Merge sort'un pek bahsedilmeyen bir dezavantajı da yedek dizi kullanmasıdır; eleman sayısı çok fazlaysa bu iyi bir şey değildir.

### 6.3 Quick sort'un en kötü durumu

**Soru (hoca sınıfa):** Quick sort'un en kötü durumu ne zaman olur?
**Cevap:** Bir öğrenci "sıralıyken" dedi. Hoca onayladı: dizi küçükten büyüğe sıralıysa ve ilk eleman pivot alınırsa, örneğin 1'den küçükler bir tarafa dendiğinde hepsi büyük olduğu için hepsi bir tarafta kalır; sonraki pivot için de aynısı olur. Bölme ikiye ayırmadığı için her seferinde bütün elemanlarla uğraşmak gerekir ve karmaşıklık $n^2$ olur; normal bir sıralama algoritmasından farkı kalmaz.

**Soru (hoca sınıfa):** $n^2$ olmaması için ne yaparsınız?
**Cevap:** Bir öğrenci diziyi başta karıştırmayı önerdi. Hoca iki yol söyledi: diziyi baştan karıştırmak (shuffle) ya da birinci elemanı değil başka bir elemanı pivot almak. Böyle yapılırsa karmaşıklık $n^2$ değil $n \log n$ olur.

## Örnek Sorular

**1. (derste sözlü, 00:02:15; tahtada önceki dersten, ekrandan 00:05:00)** $n^2 + n \in O(n)$ midir? $c = 5$, $n_0 = 1$ seçimini inceleyin.

> **Çözüm:** $n = 1, 2, 3, 4$ için $n^2 + n \le 5n$ sağlanır ($2 \le 5$, $6 \le 10$, $12 \le 15$, $20 \le 20$), ama $n = 5$ için $30 \le 25$ yanlıştır ve sonraki her $n$'de bozulur. Şart $n_0$'dan sonra sürekli sağlanmadığı için $n^2 + n \notin O(n)$.

**2. (derste sözlü, 00:06:02)** $2n + 5 \in \Theta(n)$ olduğunu gösterin. Alt sınır için $c_2 = 4$ seçimi doğru mudur?

> **Çözüm:** Üst sınır: $c = 7$, $n_0 = 1$ ile $2n + 5 \le 7n$. Alt sınır için $c_2 = 4$ yanlıştır: $n = 3$'te $11 \ge 12$ sağlanmaz (derste bulundu).

> **Çözüm (derste verilmedi):** $c_2 = 2$ seçilirse $2n + 5 \ge 2n$ her $n \ge 1$ için sağlanır; böylece $2n \le 2n + 5 \le 7n$, $n \ge 1$, yani $2n + 5 \in \Theta(n)$.

**3. (ekrandan, 00:20:00)** Rekürsif faktöriyel algoritmasında çarpma sayısı $M(n)$ için yineleme bağıntısını kurup çözün.

> **Çözüm:** $M(n) = M(n-1) + 1$, $M(0) = 0$. Geriye doğru yerine koyma: $M(n) = M(n-i) + i$; $i = n$ için $M(n) = n$. $M(n) \in \Theta(n)$.

**4. (ekrandan, 00:30:00 ve 00:35:00)** Pozitif bir ondalık tamsayının ikili gösterimindeki basamak sayısını bulan rekürsif algoritmayı yazın; 27 için sonucu bulun ve toplama sayısı $A(n)$ için bağıntıyı çözün.

> **Çözüm:** `if (n == 1) return 1; else return binary(n/2) + 1;`. 27 → 13 → 6 → 3 → 1, $27 = 11011_2$, 5 basamak. $A(n) = A(n/2) + 1$, $A(1) = 0$; $A(n) = A(n/2^i) + i$, $n = 2^i$ için $A(n) = \log_2 n$.

**5. (derste sözlü, 00:51:29)** $x(n) = x(n-1) + n$, $x(0) = 0$ bağıntısını geriye doğru yerine koyma ile çözün.

> **Çözüm:** $x(n) = x(n-i) + (n-i+1) + \dots + n$; $i = n$ için $x(n) = 1 + 2 + \dots + n = \frac{n(n+1)}{2} \in O(n^2)$.

**6. (ekrandan, 00:55:00)** $x(n) = 2x(n-1) + 1$ ($n > 1$), $x(1) = 1$ bağıntısını ileriye doğru yerine koyma ile çözün.

> **Çözüm:** $x(1) = 1$, $x(2) = 3$, $x(3) = 7$, $x(4) = 15$; $x(n) = 2^n - 1$, yani üstel ($2^n$) karmaşıklık.

**7. (derste sözlü, 01:07:04)** $T(n) = 3T(n/2) + n^2$ bağıntısını master teoremiyle çözün.

> **Çözüm:** $a = 3$, $b = 2$, $d = 2$; $3 < 2^2$ olduğundan $T(n) \in \Theta(n^2)$.

**8. (ekrandan, 01:10:00)** $T(n) = T(2n/3) + 1$ bağıntısını master teoremiyle çözün.

> **Çözüm:** $a = 1$, $b = 3/2$, $d = 0$ (derste önce $b = 2/3$ yazıldı, bir öğrenci düzeltti). $1 = (3/2)^0$ olduğundan $T(n) \in \Theta(n^0 \log n) = \Theta(\log n)$.

**9. (derste sözlü, 01:08:30)** İleriye doğru yerine koyma örneğindeki $x(n) = 2x(n-1) + 1$ bağıntısına master teoremi uygulanabilir mi?

> **Çözüm:** Hayır; bağıntı $T(n/b)$ biçiminde değil, $n-1$ içeriyor. Master teoremi bu biçimdeki bağıntılar için kullanılmaz.

**10. (ekrandan, 01:50:00)** 8 3 2 9 7 1 5 4 dizisi top-down merge sort ile sıralanırken sol yarıdaki ($ms(0,3)$) çağrıları izleyin.

> **Çözüm:** $ms(0,3)$: $q = 1$ → $ms(0,1)$: $q = 0$ → $ms(0,0)$ (8), $ms(1,1)$ (3), merge → 3 8. $ms(2,3)$: $q = 2$ → $ms(2,2)$ (2), $ms(3,3)$ (9), merge → 2 9. $merge(0,1,3)$ → 2 3 8 9. Sağ yarı benzer biçimde 1 4 5 7 olur; son birleştirme 1 2 3 4 5 7 8 9.

**11. (ekrandan, 02:00:00)** Merge sort için $T(n) = 2T(n/2) + n$, $T(1) = 1$ bağıntısını geriye doğru yerine koyma ile çözün. $O$ mu, $\Theta$ mı yazılmalı?

> **Çözüm:** $T(n) = 2^i T(n/2^i) + i\,n$; $n = 2^i$ için $T(n) = n + n\log_2 n$. Merge her durumda bütün elemanları yerleştirdiği ve bölme her durumda aynı olduğu için en iyi, ortalama ve en kötü durum aynıdır: $T(n) \in \Theta(n \log n)$.

**12. (ekrandan, 02:10:00)** 5 3 1 9 8 2 4 7 dizisinde ilk eleman pivot alınarak quick sort'un ilk bölme adımını uygulayın.

> **Çözüm:** 9 ile 4 yer değiştirir → 5 3 1 4 8 2 9 7; 8 ile 2 yer değiştirir → 5 3 1 4 2 8 9 7; pivot 5 ile 2 yer değiştirir → 2 3 1 4 5 8 9 7. Tam sıralama sonucu 1 2 3 4 5 7 8 9.

**13. (derste sözlü, 02:14:39)** Quick sort'un en kötü durumu ne zaman oluşur, nasıl önlenir?

> **Çözüm:** Dizi zaten sıralıysa ve ilk eleman pivot alınırsa her bölmede bütün elemanlar bir tarafta kalır, karmaşıklık $n^2$ olur. Diziyi baştan karıştırmak (shuffle) ya da başka bir elemanı pivot seçmek bunu önler; karmaşıklık $n \log n$ olur.

## Dersin Toparlaması

Bu derste rekürsif algoritmaların nasıl analiz edildiği öğrenildi: önce temel işlem belirlenir, sonra bu işlemin sayısı için durma koşuluyla birlikte bir yineleme bağıntısı kurulur, en sonda bağıntı çözülür. Faktöriyel örneğinde $M(n) = M(n-1) + 1$ bağıntısı geriye doğru yerine koymayla $\Theta(n)$, ikili basamak sayısı örneğinde $A(n) = A(n/2) + 1$ bağıntısı $\log_2 n$ verdi. Çözüm yolu olarak geriye doğru yerine koyma, daha zahmetli olan ileriye doğru yerine koyma ve hesap gerektirmeyen master teoremi görüldü. Master teoreminde yalnız $a$, $b$, $d$ bulunup $a$ ile $b^d$ karşılaştırılır.

Dersin ikinci yarısında böl ve yönet yaklaşımı (böl, yönet, birleştir) ve bu yaklaşımın iki ünlü örneği ele alındı. Merge sort diziyi konuma göre ortadan bölüp sıralı parçaları birleştirir; $T(n) = 2T(n/2) + n$ bağıntısından $\Theta(n \log n)$ bulunur, ama yedek dizi gerektirir. Quick sort diziyi pivota göre değere bağlı olarak böler; ortalamada daha hızlıdır, ancak sıralı dizide ilk eleman pivot alınırsa $n^2$'ye düşer. Sonraki derste pivot seçimi ve quick sort'un karmaşıklığı ile böl ve yönet ve azalt ve yönet algoritmalarına devam edilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
