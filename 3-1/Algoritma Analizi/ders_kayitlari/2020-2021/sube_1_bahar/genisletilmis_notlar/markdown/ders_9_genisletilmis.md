# Ders 9 Genişletilmiş Notu: Dinamik Programlama: Fibonacci, Madeni Para Dizisi, 0-1 Sırt Çantası ve Düzenleme Uzaklığı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Giriş: İkili Ağaç ve İfade Gösterimleri
- 2. Inorder Gezinme: İteratif ve Özyinelemeli Yazım
- 3. Fibonacci Sayıları ve Üç Paradigma
- 4. Dinamik Programlama Nedir?
- 5. Dinamik Programlamanın Adımları ve Fibonacci Karşılaştırması
- 6. Madeni Para Dizisi (Coin-Row) Problemi
- 7. 0-1 Sırt Çantası (Knapsack) Problemi
- 8. Düzenleme Uzaklığı (Edit Distance)
- Örnek Sorular
- Dersin Toparlaması

## 1. Giriş: İkili Ağaç ve İfade Gösterimleri

Hoca dinamik programlamaya doğrudan girmek yerine, konunun "nereden geldiğini" göstermek için bilinen birkaç algoritmayla başladı. İlk araç ikili ağaçtır (binary tree). Ağacın ikili arama ağacı olması gerekmez; düğümlerde matematiksel işlemler bulunabilir.

Ekrandaki örnekte $(x * y) + B$ ifadesi bir ağaçla gösterildi (ekrandan, 00:20:00):

```text
        +
       / \
      *   B
     / \
    x   y
```

Operatörün operandlara göre yerine göre üç gösterim vardır:

- **Infix:** operatör içeride (günlük hayatta kullandığımız biçim), örneğin $a + b$.
- **Prefix:** operatör önde, örneğin $+\,a\,b$.
- **Postfix:** operatör sonda, örneğin $a\,b\,+$.

Bu gösterimleri elde etmek için ya yığıt (stack) ya da ağaç kullanılır; hoca ağaç kullanmanın algoritmik olarak daha kolay olduğunu söyledi. İfade hangi gösterimde verilirse verilsin, kurulan ağaç aynıdır ve diğer gösterimler bu ağaçtan okunur.

### 1.1 Ağaçtan postfix ve prefix

**Postfix** (sol, sağ, operatör): gidilebildiği kadar sola gidilir. İlk ulaşılan $x$, sonra sağdaki $y$, ardından bu küçük ağacın operatörü $*$ yazılır. Bu, büyük ağacın sol tarafıdır. Sonra büyük ağacın sağı $B$, en son kök $+$ gelir:

$$x\ y\ *\ B\ +$$

**Prefix** (operatör, sol, sağ): önce kökteki operatör $+$ alınır. Sola gidilince yeni bir ağaçla karşılaşılır; onun kökü $*$ alınır. Bu ağacın sol çocuğu $x$, sağ çocuğu $y$ alınır. Sol taraf bitince büyük ağacın sağı $B$ alınır:

$$+\ *\ x\ y\ B$$

Hoca, bu dönüşümlerin özellikle derleyicilerde, işlem önceliğini ifade etmek ve değerlendirmeyi kolaylaştırmak için kullanıldığını söyledi. Bunların asıl olarak veri yapıları ve ayrık matematik derslerinin konusu olduğunu, burada yalnız sonraki tartışmaya zemin hazırlamak için anıldığını belirtti.

### 1.2 Inorder gezinme ve infix

Gösterimlerin adları (infix, prefix, postfix) ile ağaç üzerindeki gezinmelerin adları (inorder, preorder, postorder traversal) birbirine karşılık gelir. Inorder gezinme "önce sola git, sonra ortaya gel, sonra sağa git" kuralıyla ilerler. Örnekte önce $x$, sonra operatörü $*$, sonra $y$ yazılır; ardından üstteki $+$ ve $B$ gelir. Dönüşümde her işleme parantez eklendiği için sonuç $(x*y)+B$ olur. Yani elimize bir ağaç verilirse, inorder gezinerek günlük hayatta kullandığımız orijinal ifadeyi geri elde ederiz.

## 2. Inorder Gezinme: İteratif ve Özyinelemeli Yazım

Ağaçta gezinmek için yalnız kök (root) bilinmelidir; bağlı listede başı bildiğimiz gibi, ağaçta da kökten başlayıp sağa sola giderek bütün düğümlere ulaşılır.

### 2.1 Yığıtlı (özyinelemesiz) yazım

Hoca internetten bulduğu "özyinelemesiz inorder gezinme" kodunu gösterdi (ekrandan, 00:25:00). Mantığı elle şöyle izledi: kökten başlayıp bir `while` döngüsüyle gidilebildiği kadar sola gidilir. Ancak geçilen düğümler kaybedilmemelidir; bu yüzden belli bir hiyerarşiyle bir yığıtta saklanır. Örnekte $+$, sonra $*$, sonra $x$ yığıta atılır. $x$'in solu ve sağı olmadığı için yığıttan çıkarılıp yazılır. Sonra $*$ çıkarılıp yazılır, sağındaki $y$ yığıta atılır; çocuğu olmadığı için çıkarılıp yazılır. Ardından $+$ çıkarılıp yazılır ve sağındaki $B$ için aynı işlem yapılır.

Hoca bu yaklaşımı algoritma analizi açısından bir **kaba kuvvet (brute force)** yaklaşımı olarak niteledi: kökten başlanır, gidilen düğümler bir yığıta eklenerek bütün ağaç dolaşılır.

### 2.2 Özyinelemeli yazım

Özyinelemeli yazım ise bir **böl ve fethet (divide and conquer)** yaklaşımıdır. Büyük ağaç küçük alt ağaçlara bölünür. Fonksiyon önce sol alt ağaç için kendini çağırır; bu, `NULL` görülene kadar sürer. `NULL` görülünce geri dönülür (return), en son çağıran düğüm yazdırılır, ardından aynı fonksiyon sağ alt ağaç için çağrılır.

> **Ek bilgi (derste anlatılmadı):** Özyinelemeli inorder gezinme genellikle şu biçimde yazılır: `void inorder(node *r) { if (r == NULL) return; inorder(r->left); printf(...); inorder(r->right); }`. Derste gösterilen kodun birebir metni karelerde okunmadığı için bu yalnız genel kalıptır.

### 2.3 Karmaşıklık karşılaştırması

Ekrandaki özet (ekrandan, 00:35:00):

| Yazım | Paradigma | Zaman |
|---|---|---|
| İteratif | Kaba kuvvet | $O(n)$ |
| Özyinelemeli | Böl ve fethet | $O(n)$ |

Hoca iteratif yazımda bütün düğümlerin bir kez gezildiğini ve ağaç dışında bir de yığıt saklandığını, bunun da yer açısından $O(n)$'e kadar çıkabileceğini söyledi. Özyinelemeli yazımda iki çağrı olsa da biri ağacın bir yarısına, diğeri öbür yarısına gider; her düğümden bir kez geçildiği için toplam yine $n$ adımdır. Hoca, özyinelemeli yazım için ayrıca bir yedek yapıya ihtiyaç olmadığını, yerin $O(1)$ sayılabileceğini söyledi.

> **Ders sonrası not:** Hoca özyinelemeli inorder için yeri $O(1)$ olarak verdi. Özyinelemeli çağrılar çağrı yığıtında yer tutar; bu ek yer büyük olasılıkla ağacın yüksekliği kadardır ($O(h)$, dengesiz ağaçta en kötü $O(n)$).

Hoca buradan şu sonucu çıkardı: zaman bakımından fark yoktur, ama problemi alt parçalara bölebilmek bize çok daha sade bir algoritma kazandırmıştır. Sonra asıl soruyu sordu: böl ve fethetten daha iyi bir algoritma geliştirme yolu olabilir mi?

## 3. Fibonacci Sayıları ve Üç Paradigma

Fibonacci dizisi kendinden önceki iki terimin toplamıyla ilerler: $0, 1, 1, 2, 3, 5, \dots$. Bağıntı (ekrandan, 00:40:00):

$$F_n = F_{n-1} + F_{n-2}, \qquad F_0 = 0,\ F_1 = 1$$

### 3.1 Kaba kuvvet çözüm

İki değişken tutulur: $s_1 = 0$, $s_2 = 1$. Önce bu ikisi yazdırılır. Sonra döngünün her adımında $temp = s_1 + s_2$ hesaplanıp yazdırılır, ardından $s_1 \leftarrow s_2$ ve $s_2 \leftarrow temp$ yapılır. Döngü yaklaşık $n-2$ kez döner.

Hoca bir öğrenciye bu kodun $T(n)$'ini sordu; öğrenci $O(n)$ dedi ve hoca doğruladı: döngü $n$ mertebesinde döner, içinde sabit sayıda işlem vardır. Ekstra dizi kullanılmadığı için $S(n) = O(1)$'dir.

> **Ders sonrası not:** Hoca bu kodu bir an "recursive brute force" diye andı; kod bir döngüyle yazıldığı için iteratiftir.

### 3.2 Böl ve fethet (özyinelemeli) çözüm

Karede yazılan kod (ekrandan, 00:40:00):

```c
void fib(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    else fib(n-1) + fib(n-2);
}
```

> **Ders sonrası not:** Kod tahtada `void` dönüş tipiyle ve son satırda `return` olmadan yazıldı. Değer döndüren doğru C yazımı `int fib(int n)` ve `else return fib(n-1) + fib(n-2);` biçimindedir.

Hoca, bu algoritmanın kaba kuvvetten daha kötü sonuç verdiğini göreceğimizi, ama Fibonacci'nin bir algoritmanın farklı paradigmalarla yazılmasının avantajlarını ve dezavantajlarını göstermek için çok güzel bir örnek olduğunu söyledi. Neredeyse her algoritma paradigmasına Fibonacci uyar.

**$F(3)$'ün izlenmesi.** $F(3)$ çağrılır; $n$ ne 0 ne 1'dir, önce $F(2)$ çağrılır. Hoca burada önemli bir uyarı yaptı: izleme yaparken hemen yanına artı koyup "3'ü çağırır, 2'yi çağırır, 1'i çağırır" denmez; önce soldaki fonksiyon tamamlanır, artı işlemi ondan sonra yapılır. $F(2)$, $F(1)$'i çağırır; $n=1$ olduğu için 1 döner. Sonra $F(0)$ çağrılır ve 0 döner. $1+0=1$ ile $F(2)$ biter. Ardından $F(3)$'ün sağ tarafı $F(1)$ çağrılır ve 1 döner. $1+1=2$ bulunur.

**Zaman karmaşıklığı.** Kontroller için bir birim işlem sayılırsa (ekrandan, 00:45:00):

$$T(n) = 1 + T(n-1) + T(n-2)$$

Hoca bunu Master teoremiyle karşılaştırdı. $T(n) = 2T(n/2) + 1$ gibi bir bağıntıda $n$ boyutlu problem iki eşit $n/2$ boyutlu alt probleme bölünür ve iki terim ortak olduğu için başlarına 2 yazılır. $T(n) = 2T(n-1) + 1$ gibi bir bağıntıda da iki eşit $n-1$ boyutlu çağrı vardır (azalt ve fethet). Fibonacci'de ise çağrılar $n-1$ ve $n-2$ boyutludur; birbirine benzemez.

> **Hocanın vurgusu:** Bu bağıntı kesinlikle Master teoremiyle ($a$, $b$, $d$ ile) çözülmez. Ödevlerde bunu kullananlar olmuş; kullanılmamalı.

Burada fark denklemleri (karakteristik denklem) kullanılır: $T(n)$ terimi $r^2$, $T(n-1)$ terimi $r$, $T(n-2)$ terimi sabit 1 olarak düşünülür ve katsayılar 1 olduğundan $r^2 - r - 1 = 0$ elde edilir. Hoca, çözümün ayrıntısının ayrık matematiğin konusu olduğunu söyleyip sonucu verdi: $T(n)$ yaklaşık $O(2^n)$'dir. Daha kesin olarak taban $2$ değil, altın orana yakın $1{,}6$ küsurlu bir sayıdır.

> **Ek bilgi (derste anlatılmadı):** $r^2 - r - 1 = 0$ denkleminin büyük kökü $\varphi = \frac{1+\sqrt{5}}{2} \approx 1{,}618$'dir; bu yüzden özyinelemeli Fibonacci'nin zamanı $\Theta(\varphi^n)$ olur. $O(2^n)$ bunun gevşek bir üst sınırıdır.

**Pratik kural.** Hoca karakteristik denkleme girmeden şu kestirimi önerdi: özyinelemeli çağrılarda $n$'e yakın boyutlu ($n-1$, $n-2$ gibi) iki dallanma varsa karmaşıklık "dallanma sayısı üzeri $n$" kadardır. Kendinden önceki üç terimi toplayan bir dizi olsaydı üç dallanma olur, $3^n$ mertebesinde bir algoritma çıkardı.

Yer bakımından ekstra dizi kullanılmadığı için hoca $S(n)$'i 1 olarak verdi (karede $S(n)=1$ yazılı).

> **Ders sonrası not:** Özyineleme derinliği $n$ olduğu için çağrı yığıtı büyük olasılıkla $O(n)$ yer tutar; hocanın verdiği 1, ekstra veri yapısı kullanılmadığı anlamındadır.

### 3.3 Gereksiz tekrar: $F(5)$ çağrı ağacı

Hoca, kötülüğün yalnız $2^n$ olmadığını, bir de gereksiz bir "angarya" olduğunu söyledi ve bir öğrenciye $F(5)$'in çağrı ağacını adım adım çizdirdi. Öğrenci soldan başlayarak $F(5) \to F(4) \to F(3) \to F(2) \to F(1)$, sonra $F(2)$'nin sağında $F(0)$, sonra $F(3)$'ün sağında $F(1)$ diye ilerledi. $F(4)$'ün sağında $F(2)$ tekrar çağrıldı ve onun altında $F(1)$ ile $F(0)$ yeniden hesaplandı. $F(5)$'in sağındaki $F(3)$ alt ağacı ise soldaki $F(3)$ alt ağacının aynısıdır.

```text
                    F(5)
              /              \
          F(4)                F(3)
         /    \              /    \
     F(3)      F(2)      F(2)     F(1)
    /   \      /  \      /  \
 F(2)  F(1) F(1) F(0) F(1) F(0)
 /  \
F(1) F(0)
```

Değerler aşağıdan yukarı toplanınca $F(5) = 5$ bulunur ($0, 1, 1, 2, 3, 5$). İşlem doğrudur ama $F(1)$ ve $F(0)$ defalarca hesaplanmıştır. Ağaç iki koldan büyüdüğü için üstel bir derinliğe ve karmaşıklığa ulaşılır. Hoca örnek verdi: 1000 elemanda kaba kuvvet 1000 adımda biterken burada $2^{1000}$ mertebesinde adım gerekir.

> **Ek bilgi (derste anlatılmadı):** Bu ağaçta toplam 15 çağrı vardır; $F(1)$ beş kez, $F(0)$ üç kez, $F(2)$ üç kez, $F(3)$ iki kez hesaplanır (python ile sayıldı).

Öte yandan özyinelemeli kodun yazımı, yineleme bağıntısından doğrudan geldiği için çok basittir; döngülü kod ise biraz daha "çetrefilli"dir, kafa yormak gerekir. Hoca şu soruyu sordu: birinin algoritmik karmaşıklığını, öbürünün kolay kodlanabilirliğini birleştiren bir yöntem bulunamaz mı? Bulunur: bu yöntem dinamik programlamadır.

## 4. Dinamik Programlama Nedir?

Ekrandaki tanım (ekrandan, 01:05:00):

```text
Dynamic Programming -> Planning
                       Optimizasyon
                       Combinatoric
-> Recurrence Relation
   Tabulation & Memoization method in addition dec. by conq. / divide by conq.
-> Technique to solve problems with overlapping subproblems.
-> Recording: Solutions of overlapping problems
   are stored in the proper data structures.
```

Hoca, buradaki "programlama" sözcüğünün kod yazmak değil **planlama** anlamına geldiğini, yaklaşımın 1950'ler-1960'larda ortaya çıktığını ve endüstri mühendislerinin çok kullandığı bir teknik olduğunu söyledi. Kombinatorik problemlerin çözümünde çok faydalıdır.

Bir öğrenciye böl ve fethet ile azalt ve fethette kod yazmak için neye ihtiyaç olduğunu sordu. Cevap **yineleme bağıntısıdır (recurrence relation, öz yineleme bağıntısı)**; Fibonacci'de $F_n = F_{n-1} + F_{n-2}$ bağıntısına göre kod yazılmıştı. Hoca bunun "formül" değil yineleme bağıntısı diye adlandırıldığını vurguladı.

Dinamik programlama, yineleme bağıntısı açısından böl ve fethet ya da azalt ve fethetle hemen hemen aynıdır. Farkı, onların gereksiz tekrarlarını ortadan kaldıran bir hatırlama (hafıza) sistemi kullanmasıdır. Buna **tabulation** ya da **memoization** yöntemi denir.

Tanımın iki parçası:

- Dinamik programlama, **örtüşen alt problemleri (overlapping subproblems)** olan problemleri çözmek için kullanılan bir tekniktir. Azalt ve fethette de böl ve fethette de problem alt problemlere bölünür; Fibonacci'de olduğu gibi bu alt problemler çakışabilir.
- **Kayıt (recording):** çakışan alt problemlerin çözümleri uygun veri yapılarında saklanır, böylece çözülmüş bir problem tekrar çözülmez.

Hoca bunu şöyle özetledi: azalt ve fethet ya da böl ve fethetteki yineleme bağıntısını alırsınız, buna bir de saklama özelliği eklersiniz; oldu size dinamik programlama.

### 4.1 Fibonacci'nin dinamik programlama çözümü

Yineleme bağıntısı değişmez. Önceki "tecrübeler" bir dizide saklanır (ekrandan, 01:05:00):

```c
int A[100];        /* gerekirse malloc ile oluşturulur */
A[0] = 0;
A[1] = 1;
for (int i = 2; i < n; i++)
    A[i] = A[i-1] + A[i-2];
```

Hoca ilk adımı izledi: $A[2]$ hesaplanırken $A[1]=1$ ve $A[0]=0$ daha önce çözülmüştür; $A[2] = 1$ bulunur ve saklanır. $A[3]$ için $A[2]$ ve $A[1]$ yeniden hesaplanmaz, dizide hazırdır. "Uygun veri yapısı" dediğimiz şey budur; probleme uygun veri yapısı seçilir.

Karmaşıklık: döngü $n$ kez döner, $T(n) = O(n)$; kaba kuvvetten farkı yoktur. Yer bakımından $n$ elemanlı dizi gerekir, $S(n) = O(n)$. Kaba kuvvette ise yalnız sabit sayıda değişken vardı ($S(n) = 1$). Yani Fibonacci'de dinamik programlamanın kaba kuvvetten tek kötü yanı $n$'lik bir diziye ihtiyaç duymasıdır.

## 5. Dinamik Programlamanın Adımları ve Fibonacci Karşılaştırması

Aradan sonra hoca konuyu tekrar özetledi. Problemin alt problemlere bölünerek çözülebilmesi gerekir; yoksa dinamik programlama kullanılamaz. Bir öğrenciye "herhangi bir problemi dinamik programlamayla çözmek için önce ne yapmalıyım" diye sordu. Doğru cevap: önce bir yineleme bağıntısı kurulmalıdır. Sonra başlangıç koşullarından başlanıp elde edilen her sonuç kaydedilerek en iyi (optimal) sonuca ulaşılır.

Ekrandaki adımlar (ekrandan, 01:20:00 ve 01:25:00):

1. **Define subproblems:** alt problemleri tanımla.
2. **Establish recurrence relation:** yineleme bağıntısını kur.
3. **Specify and solve base conditions:** başlangıç koşullarını belirle ve çöz.
4. **Find the final solution by using and recording the subsolutions:** ara çözümleri kullanarak ve kaydederek son çözümü bul.

Hoca bu adımlara örnek olarak $x^n$ hesabını verdi. $x^{n/2}$ biliniyorsa karesi alınarak $x^n$ bulunur:

$$x^n = x^{n/2} \cdot x^{n/2}, \qquad x^0 = 1$$

$x^{n/2}$'den başlayıp tek tek $x$ ile çarparak $n$'e gitmek gereksizdir; bu yolla işlem logaritmik sayıda adımda biter. Problem alt problemlere bölünür, yineleme bağıntısı ve başlangıç koşulu vardır; çözüm de önceki sonuçlar kaydedilerek bulunur.

Sonra Fibonacci için üç yaklaşım öğrencilerle birlikte bir tabloya yazıldı (ekrandan, 01:25:00):

| Fibonacci | $T(n)$ | $S(n)$ |
|---|---|---|
| Kaba kuvvet | $O(n)$ | $O(1)$ |
| Böl ve fethet | $O(2^n)$ | $O(1)$ |
| Dinamik programlama | $O(n)$ | $O(n)$ |

Böl ve fethet satırını soran hocaya bir öğrenci "üstel, $\log n$ mi" diye cevap verdi. Hoca $\log n$'in logaritmik, $2^n$, $3^n$ gibi ifadelerin üstel olduğunu düzeltti.

Hoca, Fibonacci için en iyi çözümün aslında kaba kuvvetten çıktığını söyledi: hem zaman hem bellek bakımından iyidir. Dinamik programlama da iyidir ama bellek ister; özyinelemeli çözüm ise "bayağı kötü" bir çözümdür. Fibonacci sayıları hesaplanacaksa kaba kuvvet ya da dinamik programlama kullanmak en doğrusudur. Fibonacci algoritma kitaplarında analiz için güzel bir eğitim örneği olduğundan sıkça kullanılır.

## 6. Madeni Para Dizisi (Coin-Row) Problemi

### 6.1 Problem

Sıralı madeni paralar vardır: $c_1, c_2, \dots, c_n$. Kitaptaki örnekte değerler (ekrandan, 01:35:00):

$$5,\ 1,\ 2,\ 10,\ 6,\ 2$$

Kural: **yan yana iki para seçilemez**. Amaç, bu kuralla toplanabilecek en yüksek miktarı bulmaktır. Paraların sırası değiştirilemez. Hoca bunu, yan yana oturan ve birbiriyle tanışmayan kişilere benzetti. Bu kombinatorik bir optimizasyon problemidir: 5, 1'den büyük diye doğrudan 5'i almak her zaman en iyisi değildir.

### 6.2 Kaba kuvvet

Hoca olası seçimleri listeledi (ekrandan, 01:35:00): 5, 2, 6; 5, 10, 2; 5, 6; 1, 10, 2; 1, 6; 2, 6; 2, 2; 10, 2; ayrıca tek tek seçimler. Bunların hepsi hesaplanıp en büyüğü bulunur; en yüksek kazanç 17 görünüyor (5, 10, 2). Bütün kombinasyonlar denendiği için karmaşıklık yine $2^n$'e yakındır.

### 6.3 Yineleme bağıntısı

Hoca, bağıntıyı baştan kurmanın zor olduğunu, sondan geriye düşünmenin daha kolay olduğunu söyledi. Son para $c_n$ için iki durum vardır:

- **Durum 1, son para alınır:** $c_n$ kadar kazanılır. Bu durumda $(n-1)$. para alınamaz; geriye kalan problem ilk $n-2$ paradır:
  $$P_1(n) = P(n-2) + c_n$$
- **Durum 2, son para alınmaz:** son para devreden çıkar; problem ilk $n-1$ para için sıfırdan yeniden çözülüyormuş gibi düşünülür:
  $$P_2(n) = P(n-1)$$

Hangisi daha kârlıysa o seçilir (ekrandan, 02:05:00):

$$P(n) = \max\{P(n-2) + c_n,\ P(n-1)\}, \qquad P(0) = 0$$

Hiç para yoksa kazanç 0'dır. Hoca, bu bağıntının böl ve fethet (doğrudan azalttığı için aslında azalt ve fethet) ile özyinelemeli de yazılabileceğini, ama $P(n-1)$ ve $P(n-2)$ çağrılarının Fibonacci'deki gibi çakışacağını söyledi. Bunun yerine tablo doldurulur.

> **Hocanın vurgusu:** Yineleme bağıntısı sondan düşünülerek kurulur, ama tablo sondan geriye doldurulmaz; başlangıç koşulundan başlanarak baştan doldurulur. Çünkü ileriki adımı doldurmak için önceki kayıtlar kullanılır.

### 6.4 Tablonun doldurulması

Adım adım (ekrandan, 02:05:00):

- $P(1) = \max(P(-1) + 5,\ P(0)) = \max(0 + 5,\ 0) = 5$. Negatif indisli durum yoktur, 0 sayılır. Elde tek para olsaydı ya onu alırdık (5) ya da hiçbir şey (0).
- $P(2) = \max(P(0) + 1,\ P(1)) = \max(1,\ 5) = 5$.
- $P(3) = \max(P(1) + 2,\ P(2)) = \max(7,\ 5) = 7$. Üç para varken sonuncuyu alırsak (2) ikinciyi alamayız, birinciyi (5) alırız: 7.
- $P(4) = \max(P(2) + 10,\ P(3)) = \max(15,\ 7) = 15$.
- $P(5) = \max(P(3) + 6,\ P(4)) = \max(13,\ 15) = 15$.
- $P(6) = \max(P(4) + 2,\ P(5)) = \max(17,\ 15) = 17$.

| indeks | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
|---|---|---|---|---|---|---|---|
| $c$ | – | 5 | 1 | 2 | 10 | 6 | 2 |
| $P$ | 0 | 5 | 5 | 7 | 15 | 15 | 17 |

$P(3)$ hesaplanırken bir öğrenci önce değerleri tablodaki komşu sütunlardan çıkarmaya çalıştı; hoca, yalnızca bağıntıdaki yerlerine yazmak gerektiğini hatırlattı. Daha önce çözülmüş $P(1)$ ve $P(2)$ değerleri yeniden hesaplanmadan tablodan alınır.

### 6.5 Seçilen paraların bulunması

**Soru:** Sonunda 17'ye ulaşıyoruz; hangi paraları aldığımızı bir yerde tutuyor muyuz? **Cevap:** Tablodan geriye doğru izlenerek (backtracking) bulunur. Bir değer bir öncekiyle aynıysa o para alınmamıştır; farklıysa alınmıştır. Kod yazarken her adımda hangi durumun seçildiğini bir listede tutmak, alt problemlerin çözümlerini sonradan kolayca yeniden kurmayı sağlar.

Geriye izleme:

1. $P(6) = 17 \neq P(5) = 15$: 6. para (2) alınmış. $17 - 2 = 15$, yani $P(4)$'e gidilir.
2. $P(4) = 15 \neq P(3) = 7$: 4. para (10) alınmış. $15 - 10 = 5$, yani $P(2)$'ye gidilir.
3. $P(2) = 5 = P(1)$: 2. para alınmamış, $P(1)$'e geçilir.
4. $P(1) = 5 \neq P(0) = 0$: 1. para (5) alınmış.

Seçilen paralar 1., 4. ve 6. paralardır: $5 + 10 + 2 = 17$ (ekrandan, 02:05:00). Hoca, problemi ilk dört para için kesersek kazancın 15 olacağını ve 4. ile 1. paranın alınacağını da örnek verdi.

**Soru:** Neden bütün paraları alamıyoruz? **Cevap:** Problemin kuralı budur; yan yana dizilmiş iki para seçilemez.

### 6.6 Karmaşıklık

Bir öğrencinin hatırlatmasıyla karmaşıklık konuşuldu. Tablo aslında $2 \times 6$'lık bir matristir; ilk satırı paralar, ikinci satırı kârlardır. Bir `for` döngüsüyle her $P(i)$ bir kez, önceki iki değere bakılarak hesaplanır (ekrandan, 02:05:00):

$$T(n) = \Theta(n), \qquad S(n) = \Theta(n)$$

Paraların zaten bir dizide verildiği kabul edilirse ek olarak yalnız $n$'lik $P$ dizisi gerekir. Kaba kuvvette ise "5'i alırsam 1'i alamam; 2'yi, 10'u, 6'yı alabilirim..." diye dallanan bir ağaç kurulur; bu $2^n$, $3^n$ mertebesinde, hatta faktöriyele kadar gidebilen bir büyüme gösterir. Böl ve fethet ile yazılsa $P(n-1)$ ve $P(n-2)$ çağrıları Fibonacci'deki gibi çakışırdı.

## 7. 0-1 Sırt Çantası (Knapsack) Problemi

### 7.1 Problem ve ilk tartışma

Bir çantanın kapasitesi $W$'dir; $n$ eşyanın her birinin bir ağırlığı ve değeri vardır. Ağırlık sınırı aşılmadan toplam değer en büyük yapılmak istenir. Her eşyadan yalnız bir tane vardır, bölünemez: ya alınır ya alınmaz. Bu yüzden probleme **0-1 knapsack** denir.

İlk örnek (ekrandan, 02:10:00), $W = 5$:

| eşya | ağırlık | değer |
|---|---|---|
| 1 | 2 | 10 |
| 2 | 1 | 20 |
| 3 | 3 | 15 |
| 4 | 4 | 50 |
| 5 | 5 | 90 |

Bir öğrenci "90'ı doğrudan çantaya atarım" dedi. Hoca, bunun kaba kuvvet değil **aç gözlü (greedy)** yaklaşım olduğunu söyledi: en değerli eşyaya bakılır, ağırlık uyuyorsa alınır, diğerlerine bakılmaz. Daha iyi bir aç gözlü fikir "yükte hafif, pahada ağır" olanı, yani değer/ağırlık oranı en yüksek olanları kapasite dolana kadar almaktır (örneğin $90/5 = 18$). Aç gözlü algoritmalar ileriki bir konudur.

> **Ders sonrası not:** Bu örnekte 90 (yalnız 5. eşya) gerçekten en iyi çözümdür; python ile bütün alt kümeler denendi. Oran sırasıyla seçen aç gözlü yaklaşım ise önce 2. eşyayı (oran 20), sonra 4. eşyayı (oran 12,5) alır ve 70'te kalır. Yani bu örnekte oran tabanlı aç gözlü seçim daha kötü sonuç verir.

### 7.2 Kaba kuvvet

Kaba kuvvet bütün olasılıkları dener: tek eşyalar (1, 2, 3, 4, 5), ikililer (1-2, 1-3, ..., 4-5), üçlüler ve bütün eşyalar. Hoca bunu lojik dersindeki doğruluk tablosuna benzetti: her eşya için 0 (alma) ya da 1 (al) yazılırsa $2^5 = 32$ durum çıkar. Hiçbir şey almama durumu ve ağırlığı 5'i aşanlar elenir. Genel olarak $2^n$ deneme yapılır; zaman $O(2^n)$'dir. Değerler zaten dizide verildiği için ek yer gerekmez, $S(n) = O(1)$. Küçük $n$ için 32 deneme sorun değildir ama $n$ büyüdükçe bu yöntem kullanılamaz.

### 7.3 Dinamik programlama: tablo yapısı

İki değişken vardır: kullanılan eşyalar ve çantanın ağırlığı. Bu yüzden veri yapısı bir matristir; satırlar eşyaları, sütunlar ağırlığı ($0, 1, \dots, W$) gösterir. Hoca, kaba kuvvetin burada bir anlamda yine yapıldığını, ama kaydederek ilerlendiği için gereksiz işlem kalabalığının olmadığını söyledi.

Amaç ve kısıt (ekrandan, 02:30:00):

$$\text{maximize} \sum v_i \quad \text{subject to} \quad \sum w_i \le W$$

Başlangıç koşulları:

$$P[0, w] = P[i, 0] = 0$$

Hiç eşya almazsak çanta ne kadar büyük olursa olsun kâr 0'dır; 0 kiloluk çantaya hiçbir eşya sığmadığı için kâr yine 0'dır.

### 7.4 Birinci örnek: $W = 5$

Derste bu adımda değerler değiştirildi (ekrandan, 02:30:00):

| eşya | ağırlık | değer |
|---|---|---|
| 1 | 2 | 12 |
| 2 | 1 | 10 |
| 3 | 3 | 20 |
| 4 | 2 | 15 |

Satır satır doldurma:

- **Eşya 1 (2 kg, 12):** 1 kg'lık çantaya sığmaz, 0. 2 kg'lık çantaya sığar; atarsak 0 kg boş yer kalır, oradaki önceki kâr 0'dır; $12 + 0 = 12$, öncekinden (0) iyi. Hoca "doğrudan kopyalayamıyoruz, her seferinde karşılaştırıyoruz" diye uyardı. 3, 4, 5 kg için de 12.
- **Eşya 2 (1 kg, 10):** 1 kg'a sığar: $10 + P[1,0] = 10 > 0$, 10. 2 kg: $10 + P[1,1] = 10$, ama üst satırda 12 var; 12 kalır. 3 kg: atarsak 2 kg boş yer kalır, orada 12'lik kâr vardır; $10 + 12 = 22$. 4 ve 5 kg için de 22.
- **Eşya 3 (3 kg, 20):** 1 ve 2 kg'a sığmaz; 10 ve 12 aynen kalır. 3 kg: $20 + P[2,0] = 20 < 22$; 22 kalır. 4 kg: $20 + P[2,1] = 20 + 10 = 30 > 22$; 30. 5 kg: $20 + P[2,2] = 20 + 12 = 32$.
- **Eşya 4 (2 kg, 15):** 1 kg'a sığmaz, 10. 2 kg: $15 + 0 = 15 > 12$; 15. 3 kg: $15 + P[3,1] = 25 > 22$; 25. 4 kg: $15 + P[3,2] = 27 < 30$; 30 kalır. 5 kg: $15 + P[3,3] = 15 + 22 = 37 > 32$; 37.

Tablo (ekrandan, 02:30:00):

| eşya \ $w$ | 0 | 1 | 2 | 3 | 4 | 5 |
|---|---|---|---|---|---|---|
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| 1 | 0 | 0 | 12 | 12 | 12 | 12 |
| 2 | 0 | 10 | 12 | 22 | 22 | 22 |
| 3 | 0 | 10 | 12 | 22 | 30 | 32 |
| 4 | 0 | 10 | 15 | 25 | 30 | 37 |

Hoca, 3. eşyanın 5 kg'lık hücresinde üstteki 22'yi doğrudan kopyalasaydık 10 birim zararımız olacağını gösterdi: bu hücreler alt problemlerdir; "çanta 2 kg olsaydı en fazla 12 elde ederdik" bilgisi kayıtlıdır ve kullanılır.

**Geriye izleme:** $P[4,5] = 37$, üst satırdaki 32'den farklıdır; 4. eşya alınmıştır. Ağırlığı çıkarılır: $5 - 2 = 3$, $P[3,3] = 22$. Bu, üstündeki $P[2,3] = 22$ ile aynıdır; 3. eşya alınmamıştır. $P[2,3] = 22 \neq P[1,3] = 12$; 2. eşya alınmıştır, $3 - 1 = 2$. $P[1,2] = 12 \neq P[0,2] = 0$; 1. eşya alınmıştır. Sonuç: eşya 1, 2 ve 4 alınır, kâr 37 (ekrandan, 02:30:00).

### 7.5 Yineleme bağıntısı

Hoca önce mantığı elle kurup sonra bağıntıyı yazdı (ekrandan, 02:35:00):

- **Durum 1, $i$. eşya alınır:** $v_i$ kazanılır ve çantada $w_i$ kadar yer azalır:
  $$P(i, w) = P(i-1,\ w - w_i) + v_i$$
- **Durum 2, $i$. eşya alınmaz:** bir önceki çözüm aynen kullanılır:
  $$P(i, w) = P(i-1,\ w)$$
- Bir de eşya çantaya hiç sığmayabilir; o zaman almayı denemeye bile gerek yoktur, üst satır kopyalanır.

$$P(i, w) = \begin{cases} P(i-1, w) & \text{eğer } w_i > w \\ \max\{P(i-1, w - w_i) + v_i,\ P(i-1, w)\} & \text{değilse} \end{cases}$$

Örneğin 5 kg'lık çantaya 3 kg'lık bir eşya atarsak 2 kg yer kalır; bu eşya 20 birim kazandırır ve kalan 2 kg'ın daha önce çözülmüş kârı buna eklenir.

**Karmaşıklık.** Bir matris doldurulur; zaman ve yer, eşya sayısı ile kapasitenin çarpımı kadardır. Hoca, $W$ ile $n$ birbirine yakın tutulursa bunun $n^2$'ye düştüğünü, yani $2^n$'den $n^2$'ye inildiğini söyledi. Özyinelemeli çağrı yoktur; başlangıç koşulları belli olan matris bir `for` döngüsüyle doldurulur.

> **Ek bilgi (derste anlatılmadı):** Bu zaman genellikle $\Theta(nW)$ diye yazılır. $W$ girdi boyutuna göre çok büyük olabileceğinden bu algoritmaya sözde-polinom (pseudo-polynomial) zamanlı denir.

### 7.6 İkinci örnek: $W = 9$

Eşyaların numarası ile ağırlığı aynı alındı (ekrandan, 02:50:00):

| eşya | 1 | 2 | 3 | 4 | 5 |
|---|---|---|---|---|---|
| ağırlık | 1 | 2 | 3 | 4 | 5 |
| değer | 1 | 4 | 4 | 5 | 7 |

Öğrencilerle birlikte dolduruldu. 0 kg sütunu ve 0. satır sıfırdır. Bazı adımlar:

- **Eşya 1:** her kapasiteye sığar, en fazla 1 değer verir; satır 1'lerle dolar.
- **Eşya 2:** 1 kg'a sığmaz, üst satır kopyalanır (1). 2 kg: $4 + P[1,0] = 4 > 1$. 3 kg: $4 + P[1,1] = 5$. 4 kg ve sonrası: $4 + 1 = 5$; satır 5'lerle devam eder.
- **Eşya 3:** 1 ve 2 kg'da 1 ve 4 kalır. 3 kg: $4 + 0 = 4 < 5$, 5 kalır (eşya 3 işe yaramadı). 4 kg: $4 + P[2,1] = 5$, üst satır da 5; alınabilir de alınmayabilir de. 5 kg: $4 + P[2,2] = 8$. 6 kg: $4 + P[2,3] = 9$; sonrası 9.
- **Eşya 4:** 4 kg: $5 + 0 = 5$, üstte de 5. 5 kg: $5 + P[3,1] = 6 < 8$, 8 kalır. 6 kg: $5 + P[3,2] = 9$, eşit. 7 kg: $5 + P[3,3] = 10$. 8 kg: $5 + P[3,4] = 10$. 9 kg: $5 + P[3,5] = 13$.
- **Eşya 5:** 5 kg: $7 + 0 = 7 < 8$. 6 kg: $7 + 1 = 8 < 9$. 7 kg: $7 + P[4,2] = 11$. 8 kg: $7 + P[4,3] = 12$. 9 kg: $7 + P[4,4] = 12 < 13$; 13 kalır.

| eşya \ $w$ | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|---|---|---|---|---|---|---|---|---|---|---|
| 1 | 0 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |
| 2 | 0 | 1 | 4 | 5 | 5 | 5 | 5 | 5 | 5 | 5 |
| 3 | 0 | 1 | 4 | 5 | 5 | 8 | 9 | 9 | 9 | 9 |
| 4 | 0 | 1 | 4 | 5 | 5 | 8 | 9 | 10 | 10 | 13 |
| 5 | 0 | 1 | 4 | 5 | 5 | 8 | 9 | 11 | 12 | 13 |

Derste 4. eşyanın 7 kg hücresi önce 9 yazıldı; bir öğrencinin uyarısıyla 10 olarak düzeltildi.

**Geriye izleme:** $P[5,9] = 13 = P[4,9]$; 5. eşya alınmamış. $P[4,9] = 13 \neq P[3,9] = 9$; 4. eşya alınmış. Ağırlıktan gidilirse $9 - 4 = 5$; değerden gidilirse $13 - 5 = 8$; ikisi de $P[3,5] = 8$'e götürür. $P[3,5] = 8 \neq P[2,5] = 5$; 3. eşya alınmış, $5 - 3 = 2$. $P[2,2] = 4 \neq P[1,2] = 1$; 2. eşya alınmış, $2 - 2 = 0$. Başlangıç durumuna gelinmiştir. Sonuç: eşya 2, 3 ve 4 alınır, kâr 13.

> **Hocanın vurgusu:** Tabloyu çok doldura doldura ezberlemek mümkündür, ama asıl öğrenilmesi gereken yineleme bağıntısını kurmaktır: bir eşya alınacak mı, alınmayacak mı; alınacaksa nasıl bir güncelleme yapılacak.

## 8. Düzenleme Uzaklığı (Edit Distance)

### 8.1 Problem

Bir dizgiden diğerine geçmek için yapılması gereken **en az** işlem sayısı aranır. Üç temel işlem vardır (ekrandan, 03:05:00):

1. **Değiştirme (replace / substitute):** "sunny" yerine yanlışlıkla "sumny" yazılması.
2. **Silme (deletion):** "sunny" ile "sun-y"; bir karakter silinmiştir.
3. **Ekleme (insertion):** bunun tersi; bir karakter eklenir.

İşlemlerin maliyetleri farklı olabilir; hoca, bazı sistemlerde değiştirmenin 2, bazılarında 1 sayıldığını, burada hepsinin 1 kabul edileceğini söyledi. Hem en az işlem sayısı hem de bu işlemlerin neler olduğu bulunmak istenir.

Örnek: "maths" ile "arts" (ekrandan, 03:05:00). S'ler ortaktır. Hizalama şöyle düşünülebilir:

```text
M A T H S
- A R T S
```

Baştaki M için ekleme (ya da ters yönden silme), T ile R ve H ile T arasında değiştirme yapılır; A ve S aynen kalır. Toplam 3 işlem. Ters yönden düşünüldüğünde ekleme silmeye dönüşür ama maliyet aynıdır; işlemler simetriktir.

Kullanım alanı olarak biyoenformatik anıldı: gen benzerliği ölçülmeden önce ön işlem olarak düzenleme uzaklığıyla hizalama yapılır. Kaba kuvvet çok maliyetlidir, çünkü her konumda dört seçenek (aynen bırakma, silme, değiştirme, ekleme) vardır ve hizalamanın nereden başlayacağı da belli değildir.

### 8.2 Yineleme bağıntısı

$x$ dizgisi $m$, $y$ dizgisi $n$ uzunluğunda olsun; $ED[i, j]$, $x$'in ilk $i$ karakterini $y$'nin ilk $j$ karakterine çevirmenin en az maliyetidir. Tablonun son hücresi $ED[m, n]$ en küçük düzenleme uzaklığını verir.

Karakterler farklıysa ($x_i \ne y_j$) üç durum vardır:

- Durum 1: $ED[i,j] = ED[i-1, j] + 1$ (hoca bunu ekleme olarak adlandırdı).
- Durum 2: $ED[i,j] = ED[i, j-1] + 1$ (hoca bunu silme olarak adlandırdı).
- Durum 3: $ED[i,j] = ED[i-1, j-1] + 1$ (değiştirme).

Hoca önce "to maximize the cost" dedi; bir öğrencinin uyarısıyla "minimize" olarak düzeltti. Bağıntı (ekrandan, 03:30:00):

$$ED[i, j] = \begin{cases} ED[i-1, j-1] & \text{eğer } x_i = y_j \\ \min\{ED[i-1, j] + 1,\ ED[i, j-1] + 1,\ ED[i-1, j-1] + 1\} & \text{eğer } x_i \ne y_j \end{cases}$$

$$ED[i, 0] = i, \qquad ED[0, j] = j$$

> **Ek bilgi (derste anlatılmadı):** Hangi komşu geçişin "ekleme", hangisinin "silme" diye adlandırılacağı, hangi dizginin kaynak hangisinin hedef alındığına bağlıdır; ters yönde adlar yer değiştirir ama maliyet aynı kalır. Derste bağıntıda ve tabloda kullanılan adlar bu yüzden farklı görünebilir.

Hoca tablodaki bir hücreye üç yerden gelinebileceğini çizdi: üstten, soldan ve çaprazdan. Karakterler eşitse hiçbir işlem yapılmaz, çapraz değer aynen kopyalanır. Farklıysa üç komşunun en küçüğüne 1 eklenir.

Özünde mantık şudur: iki dizginin son karakterleri aynıysa hiçbir şey yapılmaz, geri kalan kısma bakılır (5 karakter varsa kalan 4 karaktere). Aynı değilse, ondan önceki üç farklı durumun en az maliyetlisi seçilir ve 1 eklenir.

### 8.3 Örnek: "abcfg" ve "adceg"

Hoca internetten bulduğu örneği çözdü (ekrandan, 03:25:00). Sütunlarda $\varnothing$, a, b, c, f, g; satırlarda $\varnothing$, a, d, c, e, g vardır.

İlk satır ve sütun: boş dizgiyi boş dizgiye çevirmek için işlem gerekmez, 0. Boş dizgiyi "a"ya çevirmek için 1 ekleme, "ab"ye çevirmek için 2 ekleme gerekir; satır $0, 1, 2, 3, 4, 5$ diye dolar. "a"yı boş dizgiye çevirmek için 1 silme, "ad"yi boş dizgiye çevirmek için 2 silme gerekir; sütun da $0, 1, 2, 3, 4, 5$ diye dolar.

Bazı adımlar:

- a ile a aynı: çapraz değer kopyalanır, 0.
- "a"dan "ab"ye: a ile b farklı; soldaki 0'a 1 eklenir (ekleme), 1. "a"dan "abc"ye 2, "abcf"ye 3, "abcfg"ye 4.
- "ad"den "a"ya: üstteki 0'a 1 eklenir (silme), 1. "ad"den "ab"ye: d ile b farklı; en küçük komşu çapraz 0'dır, $0+1 = 1$ (doğrudan değiştirme).
- c ile c aynı: çapraz değer 1 aynen alınır.
- Son hücre g ile g aynı olduğu için çapraz değer 2 aynen alınır.

Derste son hücre önce 3 yazıldı; bir öğrencinin uyarısıyla, g'ler eşit olduğu için çaprazdaki 2'nin aynen alınması gerektiği düzeltildi.

| | $\varnothing$ | a | b | c | f | g |
|---|---|---|---|---|---|---|
| $\varnothing$ | 0 | 1 | 2 | 3 | 4 | 5 |
| a | 1 | 0 | 1 | 2 | 3 | 4 |
| d | 2 | 1 | 1 | 2 | 3 | 4 |
| c | 3 | 2 | 2 | 1 | 2 | 3 |
| e | 4 | 3 | 3 | 2 | 2 | 3 |
| g | 5 | 4 | 4 | 3 | 3 | 2 |

"abcfg" ile "adceg" arasındaki uzaklık **2**'dir.

**Geriye izleme:** g ile g aynı, işlem yok. Buraya çaprazdaki 2'den gelinmiştir; e ile f farklıdır ve çapraz geçiş, f'nin e'ye değiştirilmesi demektir (1 işlem). c ile c aynı. d ile b farklı; çapraz geçiş b'nin d'ye değiştirilmesidir (1 işlem). a ile a aynı, maliyet 0. Toplam iki değiştirme.

Hoca, bazı hücrelere birden fazla yoldan (aynı maliyetle) gelinebildiğini, bunun birden fazla geçerli işlem dizisi olabileceği anlamına geldiğini okla işaretledi. Tablonun alt parçaları da alt problemlerin cevabıdır: örneğin "adc" ile "abcfg" arasındaki uzaklık tablodan 3 okunur. Bunun yolu iki ekleme (sona f ve g eklenmesi) ve bir değiştirmedir (b ile d).

**Soru:** "ad"den "abc"ye geçiş değiştirme olarak çizildi; nasıl değiştirme oluyor? **Cevap:** Araya bir karakter eklenip d değiştirilirse de, bir karakter silinip c değiştirilirse de olur; aynı maliyete birden fazla yoldan ulaşılabilir.

**Soru:** Bu tabloyu doldurmak $n^2$ karmaşıklığa sahip; fazla değil mi? Tek döngüde aynı indisteki karakterleri karşılaştırsak? **Cevap:** Burada dizgiler karşılaştırılmıyor, bir dizgi diğerine dönüştürülüyor; ekleme, silme ve değiştirme yapılabiliyor. Bulmacalardaki gibi bir kelimeden ötekine geçiş aranıyor. Kaba kuvvetle bunu yapmak çok daha zordur.

### 8.4 Karmaşıklık

Uzunlukları $m$ ve $n$ olan iki kelime için $m \times n$'lik matris doldurulur:

$$T = O(mn), \qquad S = O(mn)$$

Kaba kuvvette her konumda dört işlem seçeneği olduğundan ve maliyet en aza indirilmeye çalışıldığından durum sayısı dizgilerin uzunluğuyla çok hızlı büyür; hoca bu yüzden kaba kuvvetin bu problemde çok zor olduğunu söyledi.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:27:21): Ekranda gösterilen ikili ağacın inorder gezinme sırası nedir?

> **Çözüm (derste verildi):** Bir öğrenci 4, 2, 5, 1, 3 dedi ve hoca doğruladı: gidilebildiği kadar sola gidilip 4 yazılır, sonra üstteki 2, sonra sağdaki 5, sonra kök 1, en son 3. <!-- BELİRSİZ: ağacın kendisi karelerde görünmüyor; kökü 1, sol çocuğu 2 (çocukları 4 ve 5), sağ çocuğu 3 olan bir ağaç olduğu cevaptan anlaşılıyor. -->

**Soru 2** (derste sözlü, 00:36:50): İki değişkenle döngü kullanarak Fibonacci terimlerini yazan kaba kuvvet kodunun $T(n)$'i nedir (büyük O ile)?

> **Çözüm (derste verildi):** $O(n)$. Döngü yaklaşık $n-2$ kez döner ve içinde sabit sayıda işlem vardır. Ek dizi kullanılmadığı için yer $O(1)$'dir.

**Soru 3** (derste sözlü, 00:48:24): Özyinelemeli Fibonacci algoritmasıyla $F(5)$'in çağrı ağacını çizin. Bu çözümdeki gereksiz iş nedir?

> **Çözüm (derste verildi):** Ağaç Bölüm 3.3'teki gibidir ve $F(5) = 5$ bulunur. Gereksiz iş, aynı alt problemlerin ($F(3)$, $F(2)$, $F(1)$, $F(0)$) defalarca yeniden hesaplanmasıdır. Ağaç iki koldan büyüdüğü için üstel zaman çıkar; dinamik programlama bu tekrarları kayıt tutarak önler.

**Soru 4** (derste sözlü, 01:02:26): Herhangi bir problemi dinamik programlamayla çözmek için ilk olarak ne yapmak gerekir?

> **Çözüm (derste verildi):** Önce bir yineleme bağıntısı kurulmalıdır. Sonra başlangıç koşullarından başlanıp elde edilen her sonuç kaydedilerek son (optimal) çözüme ulaşılır.

**Soru 5** (ekrandan, 01:35:00): Madeni paralar sırasıyla 5, 1, 2, 10, 6, 2'dir. Yan yana iki para seçmeden toplanabilecek en yüksek miktar nedir, hangi paralar seçilir?

> **Çözüm (derste verildi):** $P(n) = \max\{P(n-2) + c_n,\ P(n-1)\}$, $P(0) = 0$ ile $P = 0, 5, 5, 7, 15, 15, 17$. En yüksek miktar 17; 1., 4. ve 6. paralar seçilir ($5 + 10 + 2$). Ayrıntı Bölüm 6.4 ve 6.5'te.

**Soru 6** (ekrandan, 02:10:00): Kapasitesi $W = 5$ olan bir çanta ve ağırlıkları 2, 1, 3, 4, 5, değerleri 10, 20, 15, 50, 90 olan beş eşya vardır (her eşyadan bir tane). Çantaya hangi eşyalar konmalı?

> **Çözüm (derste verilmedi):** Derste bir öğrenci 90'ı (5. eşya) önerdi; hoca bunun aç gözlü bir seçim olduğunu söyleyip örneği değiştirdi. Python ile $2^5$ alt kümenin hepsi ve aynı zamanda dinamik programlama tablosuyla kontrol edildi: en büyük değer 90'dır ve yalnız 5. eşya alınır. İkinci en iyi seçenek 2. ve 4. eşyalardır (ağırlık 5, değer 70).

**Soru 7** (ekrandan, 02:30:00): $W = 5$, ağırlıklar 2, 1, 3, 2 ve değerler 12, 10, 20, 15 için 0-1 sırt çantası problemini dinamik programlamayla çözün.

> **Çözüm (derste verildi):** Tablo Bölüm 7.4'teki gibidir. En büyük değer 37; eşya 1, 2 ve 4 alınır (ağırlık $2 + 1 + 2 = 5$).

**Soru 8** (ekrandan, 02:50:00): $W = 9$, ağırlıklar 1, 2, 3, 4, 5 ve değerler 1, 4, 4, 5, 7 için tabloyu doldurun ve seçilen eşyaları bulun.

> **Çözüm (derste verildi):** Tablo Bölüm 7.6'daki gibidir. En büyük değer 13; eşya 2, 3 ve 4 alınır (ağırlık $2 + 3 + 4 = 9$, değer $4 + 4 + 5 = 13$).

**Soru 9** (ekrandan, 03:05:00): "maths" kelimesini "arts" kelimesine çevirmenin düzenleme uzaklığı nedir?

> **Çözüm (derste verildi):** 3: bir ekleme ya da silme (M) ve iki değiştirme (T ile R, H ile T). Python ile de 3 bulundu.

**Soru 10** (ekrandan, 03:25:00): "abcfg" ile "adceg" arasındaki düzenleme uzaklığını tabloyla bulun ve işlemleri gösterin.

> **Çözüm (derste verildi):** Tablo Bölüm 8.3'teki gibidir; uzaklık 2'dir. İşlemler b ile d'nin ve f ile e'nin değiştirilmesidir.

**Soru 11** (derste sözlü, 03:31:53): Hoca alıştırma olarak "Hyundai" ile "Honda" arasındaki geçişin maliyetini ve farklı hizalama yollarını çalışmayı önerdi; maliyetin 3 olduğunu söyledi.

> **Çözüm (derste verilmedi):** Python ile düzenleme uzaklığı 3 bulundu. Bir hizalama: H aynı; Y yerine O (değiştirme); U silinir; N, D, A aynı; sondaki I silinir. Toplam bir değiştirme ve iki silme.
>
> ```text
> H Y U N D A I
> H O - N D A -
> ```

## Dersin Toparlaması

Ders, aynı problemin farklı paradigmalarla nasıl çözüldüğünü karşılaştırarak dinamik programlamaya ulaştı. Inorder gezinmede böl ve fethet, yığıtlı kaba kuvvet yazımına göre çok daha sade bir kod vermişti ve zaman aynıydı. Fibonacci'de ise böl ve fethet, $n-1$ ve $n-2$ boyutlu çakışan alt problemler yüzünden üstel zamana düştü. Dinamik programlama, yineleme bağıntısını korurken çakışan alt problemlerin çözümlerini uygun bir veri yapısında saklayarak bu gereksiz tekrarı ortadan kaldırır. Adımlar her zaman aynıdır: alt problemleri tanımla, yineleme bağıntısını kur, başlangıç koşullarını belirle, tabloyu baştan doldurarak son çözümü bul ve gerekirse tablodan geriye izleyerek seçimleri çıkar.

Bu kalıp üç klasik problemde uygulandı. Madeni para dizisinde "son parayı al ya da alma" ayrımı $O(n)$ bir çözüm verdi. 0-1 sırt çantasında "eşyayı al ya da alma" ayrımı ve kapasite boyutu, $2^n$ yerine eşya sayısı ile kapasitenin çarpımı kadar süren bir tablo çözümüne götürdü. Düzenleme uzaklığında ise karakterler eşitse çapraz değerin kopyalandığı, farklıysa üç komşunun en küçüğüne 1 eklendiği $O(mn)$'lik bir tablo kuruldu. Hoca, dinamik programlamanın ileride başka problemlerle sürdürüleceğini ve aç gözlü algoritmaların sonraki konulardan biri olduğunu belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
