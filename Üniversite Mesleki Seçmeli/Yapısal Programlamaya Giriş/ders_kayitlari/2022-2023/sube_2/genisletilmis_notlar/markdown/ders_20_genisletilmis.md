# Ders 20 Genişletilmiş Notu: Özyinelemeli Bağıntıların Özyineleme Ağacıyla Çözümü, Fibonacci Analizi, Flood Fill ve Bağlı Bileşen Etiketleme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Hatırlatma: koddan karmaşıklık bağıntısına
- 2. Özyinelemeli Fibonacci ve çağrı ağacı
- 3. Özyineleme ağacı yöntemi: bölerek giden bağıntılar
- 4. Parametrelerin anlamı ve üçe bölerek giden örnekler
- 5. Azaltarak giden bağıntılar (decrease and conquer)
- 6. Fibonacci'nin analizi ve daha hızlı çözümler
- 7. Flood fill (taşırma) algoritması
- 8. Bağlı bileşen etiketleme (connected component labeling)
- 9. C ile ilgili kısa sorular
- Örnek Sorular
- Dersin Toparlaması

## 1. Hatırlatma: koddan karmaşıklık bağıntısına

Ders, bir önceki derste başlanan özyinelemeli (recursive) algoritmaların analizinin kısa bir tekrarıyla açıldı. Özyinelemeli fonksiyon kendini yeniden çağıran fonksiyondur. Sonsuz çağrı olmaması için gerekli yere bir `if` yazılır; bu, temel durumdur (base case).

### 1.1 Sabit iş yapan fonksiyon: $O(n)$

İlk örnekte fonksiyon `N` alır; `N==0` ise döner, değilse kendini `N-1` için çağırır. Her çağrıda yalnız bir karşılaştırma yapılır; buna bir birimlik iş denir. Bağıntı şöyledir:

$$T(n)=1+T(n-1),\qquad T(0)=1$$

Temel durumda da yalnız bir karşılaştırma yapılıp çıkılır, bu yüzden $T(0)=1$ alınır. Bunu daha önce ağaç yöntemi ya da geriye doğru yerine koyma (backward substitution) ile çözüp $O(n)$ bulmuştuk. Matematiksel ispat yapmadan da düşünülebilir: fonksiyon $n$ kez çağrılır, her çağrının maliyeti bir birimdir, toplam $n\cdot1=n$.

### 1.2 Her çağrıda döngü: $O(n^2)$

Aynı fonksiyonun temel durumdan sonra `for(i=0;i<N;i++)` ile $N$ kez mesaj yazdırdığını düşünelim (`func2`). $N=10$ için ilk çağrıda döngü 10 kez, sonra 9 kez, sonra 8 kez döner. Her çağrıya $n$'lik bir terim gelir:

$$T(n)=n+T(n-1)$$

Açılınca $n+(n-1)+(n-2)+\dots$ olur; en yüksek dereceli terim $n^2$'dir. Algoritma $O(n^2)$ mertebesindedir.

### 1.3 İkiye katlanan döngü: $O(n\log n)$

`func3`'te döngü `for(i=1;i<=N;i*=2)` biçimindedir (ekrandan, 00:10:00). Hoca sınavda da benzer bir soru olduğunu hatırlattı. `i` değişkeni $1,2,4,8,\dots,2^k$ diye ilerler; $2^k\approx N$ olduğunda durur, yani döngü kabaca $\log_2 N$ kez döner. Her özyinelemeli çağrı $\log_2 n$'lik maliyet getirir ve fonksiyon $n$ kez çağrılır:

$$T(n)=\log_2 n+T(n-1)\ \Rightarrow\ T(n)=O(n\log n)$$

Ekrandaki kodun sonunda çağrı `func(N-1);` diye yazılmıştı.

> **Ders sonrası not:** Ekrandaki `func3` gövdesinde özyinelemeli çağrı `func(N-1)` olarak görünüyor; fonksiyonun kendini çağırması için `func3(N-1)` olmalıdır. Bu derste fonksiyon adları kopyalanarak değiştirildiği için kalmış bir yazım hatası olabilir.

### 1.4 İki özyinelemeli çağrı: üstel karmaşıklık

Ardından aynı fonksiyonda `func(N-1)` çağrısı iki kez yazıldı (`func4`, ekrandan, 00:15:00). İki çağrı demek, önce birinci çağrının bütün zincirinin bitmesi, sonra ikinciye sıra gelmesi demektir. Hoca kaç mesaj yazılacağını sordu, sonra global bir sayaç `x` tanımlayıp her mesajda `x++` yaptırarak saydı. Global değişkenin normalde neden tercih edilmediğinin sonraki derslerde anlatılacağını söyledi.

$N=3$ için akış şöyledir:

- `func4(3)`: 3 mesaj (toplam 3), sonra `func4(2)`: 2 mesaj (toplam 5), sonra `func4(1)`: 1 mesaj (toplam 6), `func4(0)` hiçbir şey yazmadan döner.
- Geri dönüşlerde ikinci çağrılar çalışır: `func4(1)` içindeki ikinci `func4(0)`, `func4(2)` içindeki ikinci `func4(1)` (1 mesaj), sonra `func4(3)` içindeki ikinci `func4(2)` (yeniden 2 + 1 + 1 mesaj).
- Toplam 11 mesaj. $N=10$ için sayaç 2036'ya ulaştı.

Bağıntı artık $T(n)=n+T(n-1)$ değil, $T(n)=n+2T(n-1)$'dir; çünkü fonksiyon kendini iki kez çağırır. Bu ifade $2^n$'li bir terim içerir; üstel zamana geçilmiş olur. Bu analizlerin bir kısmı bu derste, bir kısmı ikinci sınıftaki ayrık matematik dersinde anlatılacaktır.

> **Ek bilgi (derste anlatılmadı):** $T(n)=n+2T(n-1)$, $T(0)=0$ bağıntısının kapalı biçimi $T(n)=2^{n+1}-n-2$'dir. $n=3$ için $11$, $n=10$ için $2036$ verir; ekrandaki sayaç değerleriyle aynıdır. Ajan kodu `gcc -Wall` ile derleyip bu sayıları doğruladı.

## 2. Özyinelemeli Fibonacci ve çağrı ağacı

Fibonacci sayıları $0$ ve $1$ ile başlar; sonraki her terim kendinden önceki iki terimin toplamıdır: $0,1,1,2,3,5,8,13,21,\dots$. Bilgisayar biliminde birkaç farklı algoritmayla çözülebilen bir problemdir. Burada gösterilen özyinelemeli sürüm yazımı kolay ama karmaşıklığı çok kötü bir algoritmadır; özyinelemenin mantığını göstermek için anlatılır.

Kod (ekrandan, 00:20:00):

```c
// 0 1 1 2 3 5 8 13 21 ...
int fib(int N){  // T(N) = 1 + T(N-1) + T(N-2) = 2^N
    if (N==0) return 0;
    if (N==1) return 1;
    return fib(N-1) + fib(N-2);
}
```

`main` içinde `int r = fib(N); printf("Result = %d", r);` ile sonuç yazdırıldı. Sıfırıncı terim $0$ kabul edilir; `fib(3)` sonucu $2$, `fib(8)` sonucu $21$'dir. Hoca önce 8. sayı için 34 tahmin etti, ekranda 21 görünce dizide sayarak sonucun doğru olduğunu gösterdi.

Bağıntı: temel durumlarda bir ya da iki karşılaştırma vardır, bunlar sabit terimdir. Üstüne bir $T(n-1)$ ve bir $T(n-2)$ gelir:

$$T(n)=1+T(n-1)+T(n-2)$$

`func4`'e benzer, ama orada iki çağrı da $n-1$ içindi; burada biri $n-2$ olduğu için işler biraz bozulur. Yaklaşık olarak $2^n$ gibi çalışır; daha doğrusu altın oran denilen $1.618$ sayısının kuvvetine yakın bir maliyeti vardır.

### 2.1 `fib(4)` çağrısının izlenmesi

Kod, bir çağrı bitmeden sonraki terime geçmez. `F4` çağrılınca:

- `F4`, önce `F3`'ü çağırır. `F3`, `F2`'yi çağırır. `F2`, `F1`'i çağırır; `F1` temel durumdur, 1 döner. Sonra `F2` içindeki ikinci çağrı `F0` çalışır, 0 döner. $F2=1+0=1$.
- `F3`'e dönülür, ikinci çağrısı `F1` çalışır ve yeniden 1 bulunur. $F3=1+1=2$.
- `F4`'ün ikinci çağrısı `F2`'dir. `F2` yeniden `F1` ve `F0`'ı çağırır; daha önce hesaplanmış olması hiçbir şey ifade etmez, yeniden hesaplanır. $F2=1$.
- $F4=2+1=3$.

Bu yapı bir ağaçtır: iki çağrı yapan fonksiyon iki kollu bir ağaç gibi derinleşir, üç çağrı yapan üç kollu bir ağaç gibi. Hoca örnek olarak `n-1`, `n-2` ve `n-3` için üç çağrı yapan bir "myFibonacci" fonksiyonu da düşündü. Bunun düzgün çalışması için bir başlangıç değeri daha gerekir (örneğin ilk üç terim $0,1,1$); yoksa $n-3$ yüzünden negatif değerlere inilir ve sonsuz çağrı olur. Böyle bir ağaçta birinci kol çok derinleşir, ikinci kol biraz daha az, üçüncü kol daha da az.

## 3. Özyineleme ağacı yöntemi: bölerek giden bağıntılar

Dersin asıl konusu, bir algoritmanın özyinelemeli bağıntısı (recurrence) verildiğinde karmaşıklığını bulmaktır. Bir kod verilip bağıntının yazdırılması bir sorudur; bağıntı verilip kodun ne kadar çalışacağının sorulması başka bir sorudur. Kullanılan notlar ders notu PDF'i üzerinden işaretlenerek anlatıldı.

### 3.1 Bağıntıyı okumak: $T(n)=2T(n/4)+n$

(ekrandan, 00:25:00) Bu bağıntıda fonksiyon kendini iki kez çağırır (Fibonacci gibi), her çağrıda eleman sayısı dörde bölünür ve her çağrıda $n$ birimlik iş vardır. Bağıntıdan yaklaşık bir kod şöyle kurulabilir: fonksiyon `g(n)` önce `for(i=0;i<n;i++)` ile $n$ kez döner, sonra `g(n/4)` ve yine `g(n/4)` çağrılır; başa da `n==0` ya da `n==1` için bir temel durum yazılır.

**Soru:** Bu denklemde kaç bilinmeyen vardır? **Cevap:** $n$ bilinmeyen değildir, kullanıcıdan alınan, bilinen bir sayıdır (3, 5, 10 gibi). Bilinmeyenler $T(n)$ ve $T(n/4)$'tür; denklemi $y$ ve $x$ gibi iki değişkenli düşünmek gerekir.

Önceki derste geriye doğru yerine koyma (backward substitution) anlatılmıştı. Burada aynı genişletme ağaç yöntemiyle, daha görsel biçimde yapılır.

### 3.2 Seviye seviye maliyet

- Kök: 1 adet $n$, maliyet $n$.
- 1. seviye: 2 adet $n/4$; her biri $n/4$ maliyet üretir, toplam $n/2$.
- 2. seviye: 4 adet $n/16$; toplam $n/4$.
- 3. seviye: 8 adet $n/64$; toplam $n/8$.

İkişer ikişer gittiği için desen görülür: $i$. seviyede toplam maliyet $n/2^i$'dir. Böylece

$$T(n)=n+\frac n2+\frac n4+\frac n8+\dots=n\sum_{i=0}^{h}\left(\frac12\right)^i$$

### 3.3 Ağacın yüksekliği

Toplam sembolünün üst sınırına ağacın derinliği yazılır; çünkü çağrılar sonsuza gitmez, temel duruma gelince durur. Problem her adımda dörde bölünür: $n, n/4, n/16, \dots, n/4^k$. En sonda her parçanın maliyeti 1 olur:

$$\frac{n}{4^k}=1\ \Rightarrow\ n=4^k\ \Rightarrow\ k=\log_4 n$$

Her iki tarafın 4 tabanında logaritması alınır; $\log_4 4=1$ olduğu için $k=\log_4 n$ kalır. Yani $h=\log_4 n$.

### 3.4 Seri toplamı ve sonuç

$n$, $i$'ye bağlı olmadığı için dışarı alınır. Geometrik seri formülü kullanılır:

$$\sum_{i=0}^{h}a^i=\frac{a^{h+1}-1}{a-1}$$

Sonsuz toplamda ve $|a|<1$ iken bu $\frac{1}{1-a}$'ya gider. Ekrandaki çözüm (ekrandan, 00:35:00):

$$T(n)=n\,\frac{\left(\frac12\right)^{\log_4 n+1}-1}{\frac12-1}=2n\left(1-\left(\tfrac12\right)^{\log_4 n+1}\right)=2n\left(1-2^{-(\log_4 n)-1}\right)$$

$$2^{-\log_4 n}=n^{-\log_4 2}=n^{-1/2}\ \Rightarrow\ T(n)=2n\left(1-\frac{1}{2\sqrt n}\right)=2n-\sqrt n=O(n)$$

$2n$, $\sqrt n$'den büyük olduğu için baskın terim $2n$'dir; sabit katsayı atılır ve sonuç $O(n)$ olur.

**Soru:** $T(n)$ ile $O(n)$ aynı şey mi? **Cevap:** $T(n)$, karmaşıklık denkleminin sonucudur; algoritmanın $n$'e bağlı çalışma zamanı fonksiyonudur. $O(n)$ ise bu sonucun mertebesini gösteren bir gösterimdir. Aralarında denklem ilişkisi yoktur, yalnız ifade ederiz. $T(n)$ yalnız özyinelemeli fonksiyonlarda kullanılmaz; iteratif algoritmalarda da $n$'e bağlı zaman fonksiyonudur ($y=f(n)$ gibi). Fark şudur: iteratif algoritmalarda $T$'nin karşısına doğrudan $n^2$, $n^3$, $\log n$ yazılırdı; özyinelemelide yapı gereği $T(n-1)$, $T(n/4)$ gibi terimler de eklenir.

### 3.5 $T(n)=8T(n/2)+n$

(ekrandan, 00:40:00) Bu kez fonksiyon $n/2$ için 8 kez çağrılır. Ağaçta her düğümün 8 dalı vardır:

- 1 adet $n$: maliyet $n$.
- 8 adet $n/2$: toplam $8\cdot\frac n2=4n$.
- 64 adet $n/4$: toplam $16n$.
- 512 adet $n/8$: toplam $64n$.

$$T(n)=n+4n+16n+64n+\dots=n(1+4+16+64+\dots)=n\sum_{i=0}^{h}4^i$$

Ağaç yarılana yarılana iner ($n, n/2, n/4, \dots$), bu yüzden $h=\log_2 n$:

$$T(n)=n\sum_{i=0}^{\log_2 n}4^i=n\,\frac{4^{\log_2 n+1}-1}{4-1}=\frac n3\left(4\cdot4^{\log_2 n}-1\right)$$

$4^{\log_2 n}=n^{\log_2 4}=n^2$ olduğundan:

$$T(n)=\frac n3\left(4n^2-1\right)=O(n^3)$$

Burada kullanılan kural, taban ile üssün yer değiştirmesidir: $a^{\log_b n}=n^{\log_b a}$. Hoca kuralı hatırlamak için slaytta aradı; $4^{\log_2 n}$'yi $(2^2)^{\log_2 n}=(2^{\log_2 n})^2=n^2$ diye yazmanın da aynı sonucu verdiğini gösterdi.

### 3.6 $T(n)=8T(n/2)+n^2$

(ekrandan, 00:45:00 - 00:50:00) Dal sayısı ve bölme aynıdır, ama her çağrıda $n^2$ maliyet vardır. Kodda iç içe iki `for` (`for(i=0;i<N;i++) for(j=0;j<N;j++)`) ve ardından sekiz tane `g(N/2)` çağrısı bulunur. Ağaç:

- 1 adet $n^2$.
- 8 adet $(n/2)^2$: toplam $2n^2$.
- 64 adet $(n/4)^2$: toplam $4n^2$.
- 512 adet $(n/8)^2$: toplam $8n^2$.

$$T(n)=n^2(1+2+4+8+\dots)=n^2\sum_{i=0}^{\log_2 n}2^i=n^2\,\frac{2^{\log_2 n+1}-1}{2-1}=n^2\left(2n^{\log_2 2}-1\right)=n^2(2n-1)$$

$$T(n)=2n^3-n^2=O(n^3)$$

### 3.7 Alıştırma: $T(n)=8T(n/2)+1$

Slaytta bu bağıntının sonucu $T(n)=O(n^3)$ olarak verildi (ekrandan, 00:50:00), çözümü öğrencilere bırakıldı. Her özyinelemeli çağrıda $n$'den bağımsız bir birimlik iş vardır. Hoca, hiç döngü yazmadan yalnız bir kontrol yapıp 8 özyinelemeli çağrı yapan böyle kodların mümkün olduğunu söyledi.

> **Çözüm (derste verilmedi):** Seviyelerde $1, 8, 64, \dots$ birim vardır; $T(n)=\sum_{i=0}^{\log_2 n}8^i=\frac{8\cdot8^{\log_2 n}-1}{7}=\frac{8n^3-1}{7}=O(n^3)$. Burada $8^{\log_2 n}=n^{\log_2 8}=n^3$ kuralı kullanıldı.

## 4. Parametrelerin anlamı ve üçe bölerek giden örnekler

Aradan sonra hoca, $T(n)=4T(n/3)+1$ ile $T(n)=8T(n/2)+n^2$ bağıntılarını alt alta yazıp farkları sordu (ekrandan, 01:05:00):

- 4 yerine 8: fonksiyon 4 değil 8 kez çağrılır.
- $n/3$ yerine $n/2$: özyinelemeli çağrıya verilen parametre değişir; biri yarılanarak, öbürü üçe bölünerek iner.
- $1$ yerine $n^2$: her çağrıdaki ek iş değişir; $n^2$ iç içe iki `for` demektir.

> **Hocanın vurgusu:** Katsayı ağacın dal sayısını, bölen ağacın derinleşme miktarını, ek terim de her seviyedeki yükü belirler. Bir kod verildiğinde bu üçünü okuyabilmek gerekir; bu tarz sorular sınavlarda gelir.

### 4.1 $T(n)=4T(n/3)+1$

(ekrandan, 01:10:00) İlk adımda bir birimlik maliyet vardır, büyük olasılıkla bir `if` kontrolü. Kökten 4 dal çıkar, her biri $T(n/3)$'tür.

**Soru:** $n$ için maliyet 1 ise $n/3$ için maliyet nedir? **Cevap:** Yine 1'dir. Maliyet sabittir; problem uzayı küçülürken maliyet artmaz. Doğru orantı kurulur: $n$'e 1 ise $n/9$'a da 1'dir.

- 1. seviye: $1\cdot1=1$.
- 2. seviye: $4\cdot1=4$.
- 3. seviye: 16 dal, her biri $n/9$; $16\cdot1=16$.
- Sonraki: $64$.

$$T(n)=1+4+16+64+\dots=\sum_{i=0}^{h}4^i=\frac{4^{h+1}-1}{4-1}=\frac{4\cdot4^h-1}{3}$$

Ağaç $n, n/3, n/9, n/27, \dots, n/3^h$ diye iner. $n/3^h=1$ eşitlenir (her yaprakta bir birim olsun diye), $n=3^h$, $h=\log_3 n$. Yerine konunca:

$$T(n)=\frac{4\cdot4^{\log_3 n}-1}{3}=\frac{4n^{\log_3 4}-1}{3}=O\left(n^{\log_3 4}\right)$$

$\log_3 4$ sabit bir sayıdır, yaklaşık $1.26$; yani sonuç $n^1$ ile $n^2$ arasında bir ifadedir.

> **Ders sonrası not:** Hoca bir yerde üssü "2 nokta küsür" diye söyledi; doğrusu $\log_3 4\approx1.26$'dır, hemen ardından kendisi de $n^1$ ile $n^2$ arasında olduğunu söyledi.

### 4.2 $T(n)=9T(n/3)+1$

(ekrandan, 01:15:00) Önceki örneğin aynısıdır, ama her dalın altında 9 dal vardır:

- $1\cdot1=1$, $9\cdot1=9$, $9^2\cdot1=81$, $9^3\cdot1=729$, ...

$$T(n)=1+9+81+729+\dots=\sum_{i=0}^{h}9^i=\frac{9^{h+1}-1}{9-1}$$

Ağacın yüksekliği yine $h=\log_3 n$'dir. $9=3^2$ yazılınca $9^{\log_3 n}=(3^{\log_3 n})^2=n^2$ olur:

$$T(n)=\frac{9\cdot9^{\log_3 n}-1}{8}=\frac{9n^2-1}{8}=O(n^2)$$

Hoca önce payda $+1$ yazdı, sonra $-1$ olarak düzeltti. Dallanma sayısı biraz değişince ağacın büyüme hızı ve sonuç değişir.

**Soru:** $n/3^h$'yi 1'e eşitlemek temel durum mu oluyor? **Cevap:** Evet. $n$ büyük bir sayıdır ve küçüle küçüle gider; eksi sonsuza gitmemesi gerekir. Bu işlemler genellikle eleman sayısını gösterir ve en fazla 0'a ya da 1'e iner. Merge Sort'ta 16 elemanlı dizi 8'e, 4'e bölünür ve tek elemana kadar düşer; oradaki 1 temel durumdur. Soruda farklı bir durma koşulu verilirse (örneğin $n$ 4'e kadar yaklaştırılsın denirse) ağaç derinliği ona göre bulunur.

### 4.3 $T(n)=4T(n/3)+n$

(ekrandan, 01:20:00) Ağaç dörder dallanır, her dallanmada $n/3$'e iner, ama her çağrıda $n$ kadar maliyet vardır:

- 1 adet $n$: $1\cdot n$.
- 4 adet $n/3$: $4\cdot\frac n3$.
- 16 adet $n/9$: $16\cdot\frac n9$.
- 64 adet $n/27$.

$$T(n)=n+\frac{4n}{3}+\frac{16n}{9}+\frac{64n}{27}+\dots=n\left(1+\frac43+\frac{16}{9}+\frac{64}{27}+\dots\right)=n\sum_{i=0}^{h}\left(\frac43\right)^i$$

Ekrandaki ara satırda 3. seviye $16\cdot\frac N3$ diye yazılmış, ama anlatımda ve sonraki toplamda doğru değer $16\cdot\frac n9$ kullanıldı (ekrandan, 01:20:00).

Bu seri sonsuza giderse maliyet de sonsuz olur; bu yüzden ağaç yüksekliği bulunur. Ağaç yine $n/3^h=1$'de durur, $h=\log_3 n$. Seri formülünde $a=\frac43>1$ olduğu için $\frac{a^{h+1}-1}{a-1}$ kullanılır; payda $\frac43-1=\frac13$ olur:

$$T(n)=n\,\frac{\left(\frac43\right)^{\log_3 n+1}-1}{\frac13}$$

Ara işlemler yapılınca sonuç $n^{\log_3 4}$ mertebesine gelir. Hesap makinesiyle $\log_3 4\approx1.261$ bulundu; algoritmanın karmaşıklığı yaklaşık $n^{1.26}$'dır. Hoca mertebe söylerken üste yuvarlamak gerektiğini, aşağı yuvarlamanın doğru sonuç vermeyeceğini söyledi.

> **Ders sonrası not:** Hoca sonucu söylerken bir yerde "$n$ üzeri 1.61" dedi; hesap makinesinde görünen değer $1.261$'dir. Ayrıca bu sonucun "$n^2$'ye yakın" olduğunu söyledi; $n^{1.26}$, $n$ ile $n^2$ arasındadır ve $n^2$'den belirgin biçimde küçüktür.

> **Ek bilgi (derste anlatılmadı):** $\left(\frac43\right)^{\log_3 n}=n^{\log_3(4/3)}=n^{\log_3 4-1}$ olduğundan $T(n)\approx 3n\cdot\frac43\,n^{\log_3 4-1}=4n^{\log_3 4}$ çıkar. Bu bağıntıda ağacın yaprak seviyesi baskındır; ek terim $n$, sonucu değiştirmez.

## 5. Azaltarak giden bağıntılar (decrease and conquer)

Şimdiye kadarki örneklerde problem bölünerek küçülüyordu ($n/2$, $n/3$, $n/4$; hatta $n/25$ de olabilir). Diziyi yarıya ya da üçe bölerek ilerleyen bu algoritmalara **divide and conquer** (böl ve yönet) denir. Bir de **decrease and conquer** (azalt ve yönet) yaklaşımı vardır: $n$'den $n-1$, oradan $n-2$ çağrılır; ağaç birer (ya da ikişer) azalarak dallanır. Bunun bir örneği dersin başında görülmüştü.

### 5.1 $T(n)=2T(n-1)+1$

(ekrandan, 01:25:00) Her çağrıda $n$'den bağımsız bir birimlik iş yapılır ve iki tane $T(n-1)$ çağrılır.

**Soru:** $n$ geldiğinde maliyet 1 ise $n-1$ geldiğinde maliyet nedir? **Cevap:** Yine 1'dir; sabittir. Gelen verinin boyutuna bakılmaksızın her çağrıda bir birim iş yapılır. Dersin başındaki kodlarla aynı yapıdır.

- 1. seviye: $1\cdot1=1$.
- 2. seviye: iki çağrı, $2\cdot1=2$.
- 3. seviye: dört tane $T(n-2)$, $4\cdot1=4$.

$$T(n)=1+2+4+\dots=\sum_{i=0}^{h}2^i$$

Ağaç $n, n-1, n-2, n-3, \dots, n-h$ diye iner. Burada durma koşulu $n/b^h=1$ değildir, $n-h$'dir. $n-h=1$ alınırsa $h=n-1$ olur ve iş biraz zorlaşır; $n-h=0$ alınırsa doğrudan $h=n$ bulunur. (Bu algoritmalarda `if` kontrolü genellikle $n$'nin 0 ya da 1 olmasına göre yapılır.)

$$T(n)=\sum_{i=0}^{n}2^i=\frac{2^{n+1}-1}{2-1}=2\cdot2^n-1=O(2^n)$$

Bu çok kötü bir algoritmadır. Decrease and conquer ile bir çözüm üretilmiş, ama belki $O(n)$'de çözülebilecek bir problem $2^n$ mertebesine taşınmıştır.

## 6. Fibonacci'nin analizi ve daha hızlı çözümler

### 6.1 Dengesiz ağaç

Fibonacci'nin bağıntısı $T(n)=T(n-1)+T(n-2)$ (artı sabit karşılaştırma maliyeti) biçimindedir (ekrandan, 01:30:00). Az önceki ağaç dengeliydi; burada bir kol $n-1$, öbür kol $n-2$ diye gider, ağaç dengesizdir. $n=3$ için 3, 2'yi; 2, 1'i; 1, 0'ı çağırır; sol taraf sağ taraftan daha derine iner. Bunun farklı çözüm yöntemleri vardır, ama bu derste anlatılmadı. Bu yöntemlerle yapılan analizin sonucu yalnız bilgi olarak verildi:

$$T(n)=O\left(\left(\frac{1+\sqrt5}{2}\right)^n\right),\qquad \varphi=\frac{1+\sqrt5}{2}\approx1.618$$

$\varphi$, altın oran (golden ratio) denilen sayıdır. Kabaca $2^n$ diyebiliriz.

### 6.2 İteratif çözüm: $O(n)$

Fibonacci bir `for` döngüsüyle $O(n)$'de çözülebilir. Hoca bunu sözlü olarak kurdu: döngüden önce birinci sayı `s1 = 0`, ikinci sayı `s2 = 1` alınır; döngü `i=2`'den başlar; her adımda yeni sayı `s1 + s2` olur, sonra `s1` eski `s2` değerini alır, `s2` de yeni sayıya güncellenir. Döngü $n$ kez döner.

10. Fibonacci sayısı için iteratif çözüm 10 adımda biterken özyinelemeli çözüm yaklaşık $2^{10}=1024$ adım yapar. İnternette Fibonacci kodu arandığında çoğunlukla özyinelemeli kod çıkar; ama iteratif çözüm daha verimlidir.

Aşağıdaki program derste bu biçimde yazılmadı; sözlü anlatımdan ajan tarafından kuruldu, `gcc -Wall` ile derlenip $n=0..10$ için $0,1,1,2,3,5,8,13,21,34,55$ çıktısıyla denendi:

```c
#include <stdio.h>

int fib_iter(int n) {
    int s1 = 0, s2 = 1, yeni, i;
    if (n == 0) return 0;
    for (i = 2; i <= n; i++) {
        yeni = s1 + s2;
        s1 = s2;
        s2 = yeni;
    }
    return s2;
}

int main(void) {
    int n;
    for (n = 0; n <= 10; n++) printf("%d ", fib_iter(n));
    printf("\n");
    return 0;
}
```

**Soru:** $n/2$ olunca da $O(n)$ mi sayılıyor? **Cevap:** Evet. $n/2$, $n/3$, $n/4$ gibi sabitle bölünmüş ifadeler yine $O(n)$'dir.

### 6.3 Matris üssüyle $O(\log n)$

$O(n)$'den daha hızlı bir algoritma var mı? Var. Daha önce $a^n$'yi $a^{n/2}\cdot a^{n/2}$ diye hesaplayıp $O(\log_2 n)$'de bulmuştuk; aynı fikir burada bir matrisle birlikte kullanılır (ekrandan, 01:35:00):

$$F=\begin{bmatrix}1&1\\1&0\end{bmatrix},\qquad F^n=\begin{bmatrix}f(n+1)&f(n)\\f(n)&f(n-1)\end{bmatrix}$$

Matrisin sol üst elemanı bir sonraki Fibonacci sayısını, diğerleri mevcut ve bir önceki sayıyı verir; $f(n)+f(n-1)=f(n+1)$ ilişkisi matrise gömülüdür. $F$'nin kendisi ilk üç terimi ($0,1,1$) içerir. Kuvvetler (ekrandan, 01:40:00):

$$F^2=\begin{bmatrix}1&1\\1&0\end{bmatrix}\begin{bmatrix}1&1\\1&0\end{bmatrix}=\begin{bmatrix}2&1\\1&1\end{bmatrix},\qquad F^3=\begin{bmatrix}2&1\\1&1\end{bmatrix}\begin{bmatrix}1&1\\1&0\end{bmatrix}=\begin{bmatrix}3&2\\2&1\end{bmatrix}$$

$F^3$'te sol üstte 3, yani dördüncü terim bulunur. 8. Fibonacci sayısı istenirse başlangıç matrisinin 8. kuvveti alınır ve değer matristen okunur.

$2\times2$ matrisler için üç iç içe döngüyle genel matris çarpımı yazmaya gerek yoktur; birkaç toplama ve çarpma yeter. Matris $\begin{bmatrix}a&b\\c&d\end{bmatrix}$ ise karesi dört satır kodla hesaplanır (yeni değerler örneğin $x,y,z,t$ değişkenlerine yazılır):

$$\begin{bmatrix}a&b\\c&d\end{bmatrix}^2=\begin{bmatrix}a^2+bc&ab+bd\\ac+cd&bc+d^2\end{bmatrix}$$

> **Ders sonrası not:** Ekrandaki el yazısında sağ üst ve sol alt elemanlar yer değiştirmiş görünüyor (sağ üstte $ac+dc$, sol altta $ab+bd$, ekrandan, 01:40:00). Genel matris için doğrusu yukarıdaki gibidir; Fibonacci matrisinde $b=c$ olduğu için sonuç değişmez.

Her kuvvet alma adımı sabit sayıda işlemdir. Hoca önce 4 işlem dedi, toplama ve çarpmaları tek tek sayınca yaklaşık 12 işlem olduğunu söyledi; bu sabit atılır. Böylece $F^n$ hesabı $O(\log_2 n)$ zaman alır. Zamandan kazanılır, buna karşılık biraz daha fazla yer kullanılır; yer ile zaman arasında ödünleşim vardır. Bu çözüm özyinelemeli ve iteratif çözümlerden çok daha başarılıdır.

> **Ek bilgi (derste anlatılmadı):** Ajan, $F^n$'yi hızlı üs alma (üs tekse sonucu $F$ ile çarp, $F$'nin karesini al, üssü yarıya indir) ile hesaplayan bir C sürümünü derleyip $n=0..10$ için yukarıdaki iteratif sonuçlarla karşılaştırdı; değerler aynıdır.

> **Hocanın vurgusu:** Bir kod ya da bağıntı verildiğinde katsayının, bölenin ve ek terimin ne anlama geldiğini bilmek gerekir: biri ağacı derinleştirir, biri maliyeti ortaya çıkarır, biri her düğümde kaç dal olacağını söyler. Sorularda genellikle yüksekliği kolay bulunabilen bağıntılar verilir ($T(n-1)$, $T(n/2)$ gibi); Fibonacci'deki gibi $T(n-1)+T(n-2)$ dengesiz ağaçlarda derinlik bulmak daha zordur. Bu konunun devamı ikinci sınıftaki ayrık matematik ve veri yapıları derslerinde gelecektir.

## 7. Flood fill (taşırma) algoritması

Hoca konuya Paint programıyla başladı. Paint'te birkaç kapalı şekil çizip boya kovasıyla bir bölgenin içine tıkladı: boyama, çizgilerin bulunduğu yere kadar yayıldı ve orada durdu. Bu ekran kartı içinde gerçekleşen bir işlemdir; görsel olarak sonucunu görürüz.

### 7.1 Görüntü bir matristir

Ekran piksellerden oluşan bir matristir. Hocanın bilgisayarında çözünürlük $1600\times900$'dü; yani yatayda 1600, dikeyde 900 elemanlı bir matris. Renkli görüntüde üç renk kanalı için üç matris vardır. Boya kovasıyla tek bir piksele dokunulur; o pikselle aynı renkte olup belli bir sınırın içinde kalan bütün pikseller boyanır.

### 7.2 İteratif çözüm denemesi

Bir $(x,y)$ noktasından başlanıp sağa gidilir: $(x,y+1)$, $(x,y+2)$, ... Bakılan renk başlangıç rengiyle aynı olduğu sürece boyanır; farklı renk görülünce durulur. Sonra sola, yukarı ve aşağı için ayrı `while` döngüleri yazılır; 8 yönlü olacaksa çaprazlar için 4 döngü daha.

**Soru:** Sekiz `while` döngüsüyle tam boyama yapılabilir mi? **Cevap:** Hayır, arada boşluklar kalır. Yalnız başlangıç noktasından geçen düz hatlar boyanır. Tam boyama için her boyanan pikselden yeniden sağa, sola, yukarı, aşağı gitmek gerekir; bu da `while` içinde `while`, onun içinde yine `while` demektir. İteratif çözüm mümkündür ama çok zorlaşır.

### 7.3 Özyinelemeli çözüm

Özyinelemeli çözümde `fill(x, y)` gibi bir fonksiyon yazılır: komşu piksel başlangıç rengiyle aynıysa boyanır ve fonksiyon o komşu için yeniden çağrılır. Böylece her pikselin komşuları (4 ya da 8 yön) incelenmiş olur. Bir noktadan başlanıp sağa doğru engele kadar gidilir, sonra üstler, sonra onların üstleri doldurulur ve seçilen bölgenin tamamı boyanır.

Bu algoritmaya **flood fill** denir. "Flood" sel demektir; bir noktayı seçip her yeri taşırırsınız. Hoca internette C'nin grafik kütüphanesiyle yazılmış bir flood fill kodu gösterdi: bir piksele renk koyuluyor, sonra alttaki, üstteki, sağdaki ve soldaki piksel için fonksiyon yeniden çağrılıyordu; asıl algoritma, piksel önceki renkle aynıysa onu boyayıp dört yöne özyinelemeli çağrı yapan kısımdır. Kodun ayrıntıları kayıttaki karelerde görünmüyor.

<!-- BELİRSİZ: İnternetten gösterilen flood fill C kodunun tam metni kareden okunamadı; yalnız anlatımdaki yapı aktarıldı. -->

Hoca bağıntıyı da kurmaya çalıştı: dört özyinelemeli çağrı vardır ve her çağrıda yalnız bir piksel boyanır (bir birim iş). Çalışılan şey bir matris olduğu için $m$ ve $n$ gibi iki parametre vardır. $m\approx n$ kabul edilerek $T(n)\approx4T(\dots)+1$ biçiminde bir bağıntı yazıldı ve bunun maliyetli bir algoritma olduğu söylendi.

<!-- BELİRSİZ: Hocanın flood fill için söylediği bağıntının parametresi altyazıda "4 T n kare artı bir", "n eksi birin karesi" diye karışık geçiyor. -->

> **Ders sonrası not:** Flood fill'de her piksel en fazla bir kez boyanır; zaten boyanmış ya da farklı renkteki pikselde fonksiyon sabit işle hemen döner. Bu yüzden toplam iş, büyük olasılıkla bölgedeki piksel sayısıyla orantılıdır ($m\times n$'lik görüntüde $O(mn)$); $4T(n-1)+1$ gibi üstel bir bağıntı gerçek maliyeti göstermez. Aynı şey bağlı bileşen etiketleme için de geçerlidir.

## 8. Bağlı bileşen etiketleme (connected component labeling)

Flood fill'de tek bir noktadan başlayıp bir bölge boyanır. İkinci senaryo bunun tersidir: elinizde bir görüntü vardır (örneğin kanserli bir doku görüntüsü) ve içinde kaç nesne olduğunu bulmak istersiniz. Aynı renk koduna sahip, birbirine bağlı pikseller aynı nesneye aittir. Bu işleme **connected component labeling** (bağlı bileşen analizi) denir. Görüntüdeki nesneleri kendi içinde gruplamak (segmentasyon) için kullanılır; örneğin bir resimde kaç bozuk para ya da kaç gül olduğunu saymak gibi.

### 8.1 Mantık

(ekrandan, 02:05:00) Matris 0 ve 1'lerden oluşur; 0 siyah, 1 beyazdır. Gerçek görüntü önce ön işlemlerden geçirilip siyah-beyaz biçime getirilir. Ekrandaki örnekte $7\times7$'lik bir ikili görüntü ve etiketlenmiş hali gösterildi:

| Girdi (satır satır) | Etiketli çıktı |
|---|---|
| 0 0 0 0 0 0 0 | 0 0 0 0 0 0 0 |
| 1 0 0 0 1 1 1 | 1 0 0 0 2 2 2 |
| 1 1 1 0 0 1 0 | 1 1 1 0 0 2 0 |
| 1 1 0 0 0 1 0 | 1 1 0 0 0 2 0 |
| 0 0 0 1 0 1 0 | 0 0 0 3 0 2 0 |
| 0 0 1 1 0 0 0 | 0 0 3 3 0 0 0 |
| 0 0 0 0 0 1 1 | 0 0 0 0 0 4 4 |

Matris iki `for` döngüsüyle normal biçimde gezilir. 0 dışında bir değer (1) görülünce o hücre etiketlenir ve sağına, soluna, üstüne, altına bakılır; komşu da 1 ise aynı etiket verilir ve onun komşularına geçilir. Bir grup bitince arama kalınan yerden devam eder. Yeni bir grup bulununca bir sonraki numara (2, 3, 4, ...) verilir. Sonunda etiket matrisindeki en büyük değer, nesne sayısını verir.

4 komşulukta yalnız yatay ve dikey komşular bağlı sayılır, çaprazdakiler alınmaz. 8 komşulukta çaprazlar da (kuzeydoğu, güneydoğu gibi) bağlı sayılır.

### 8.2 4 komşuluk kodu

(ekrandan, 02:10:00 - 02:15:00) Girdi matrisi $8\times10$'dur:

```c
int m[8][10]= { {1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
                {1, 1, 0, 0, 1, 1, 1, 1, 0, 1},
                {0, 1, 1, 0, 1, 1, 1, 0, 1, 1},
                {0, 0, 1, 1, 1, 1, 1, 0, 0, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
                {1, 1, 1, 1, 0, 1, 1, 0, 1, 0},
                {0, 1, 0, 0, 0, 0, 1, 0, 0, 0}};
```

Etiket matrisi aynı boyutta ayrı bir matristir ve sıfırla başlatılır (0 = etiketlenmemiş). Orijinal matris bozulmaz. Ana döngü:

```c
int label[8][10]={0};
int component = 1;
int row_count=8;
int col_count=10;
int i,j;
for (i = 0; i < row_count; i++)
    for (j = 0; j < col_count; j++)
        // if not labelled and m(i,j)=1
        if (!label[i][j] && m[i][j]) etiketle(i, j, component++, m,row_count,col_count,label);
```

`etiketle` fonksiyonuna bulunulan konum, verilecek etiket numarası (`component++` ile bir sonraki değer hazırlanır), matris, satır ve sütun sayısı (matrisin dışına taşmamak için) ve etiket matrisi gönderilir. Hoca bu kodun daha önce yapılan "matriste robot gezdirme" uygulamasından uyarlandığını söyledi.

Ekranda gösterilen fonksiyon (ekrandan, 02:15:00):

```c
void etiketle(int x, int y, int current_label,int m[][10],int row_count,int col_count,int label[][10]) {
    if (x < 0 || x == row_count) return; // out of bounds
    if (y < 0 || y == col_count) return; // out of bounds
    if (label[x][y]==1 || !m[x][y]) return; // already labeled or not marked with 1 in m

    label[x][y] = current_label;
        etiketle(x+1, y, current_label,m,row_count,col_count,label);
        etiketle(x, y+1, current_label,m,row_count,col_count,label);
        etiketle(x-1, y, current_label,m,row_count,col_count,label);
        etiketle(x, y-1, current_label,m,row_count,col_count,label);
}
```

Önce sınır kontrolü yapılır: indis 0'dan küçük ya da satır/sütun sayısına eşitse doğrudan dönülür. Sonra hücre zaten etiketlenmişse ya da girdi matrisinde 0 ise dönülür. `!m[x][y]` yazımı, 1 ve 0'ın doğrudan mantıksal değer olarak kullanılmasıdır; `== 1` yazmaya gerek yoktur. Komşunun daha önce başka bir yoldan etiketlenmiş olabileceği için bu kontrol yeterlidir. Aksi halde hücreye etiket yazılır ve dört yön için fonksiyon yeniden çağrılır: `x+1`, `y+1`, `x-1`, `y-1`.

> **Ders sonrası not:** Ekrandaki `label[x][y]==1` kontrolü yalnız 1 numaralı bileşende doğru çalışır. 2 ve sonraki bileşenlerde zaten etiketlenmiş bir hücreye (değeri 2, 3, ...) geri dönülünce fonksiyon durmaz, iki komşu birbirini sonsuza kadar çağırır ve yığın taşar. Ajan bu sürümü derleyip çalıştırdı; program segmentation fault ile sonlandı. Doğru kontrol 8 komşuluk kodundaki gibi `if (label[x][y] || !m[x][y]) return;` olmalıdır. Hoca çalıştırırken sonucun beklenenden farklı çıktığını görüp bir şeyin yanlış silinmiş olabileceğini söyledi.

Ajan kodu düzeltilmiş kontrolle ve `int main(void)` ile `gcc -Wall` altında derleyip çalıştırdı. Etiket matrisi şöyle çıktı; 6 bileşen vardır:

```text
1 0 0 0 0 0 0 0 2 2
1 1 0 0 1 1 1 1 0 2
0 1 1 0 1 1 1 0 2 2
0 0 1 1 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0
0 3 0 0 0 0 0 4 0 0
3 3 3 3 0 5 5 0 6 0
0 3 0 0 0 0 5 0 0 0
```

Derste de 6 grup görüldü: birinci grup matrisin büyük kısmına yayılmıştı, sonra ikinci, üçüncü, tek hücrelik dördüncü, beşinci ve tek hücrelik altıncı grup vardı.

> **Ders sonrası not:** Ekrandaki programda `main` `void main()` olarak yazılmış ve derleyici `printf` için "incompatible implicit declaration" uyarısı vermiştir (ekrandan, 02:15:00); yani `#include <stdio.h>` eksiktir. Standart C'de `int main(void)` kullanılmalı ve başlık dosyası eklenmelidir.

**Soru:** Çıktıda 4 etiketi neden 3'ten daha yukarıda görünüyor? **Cevap:** Etiket sırası, satır satır taramada bileşenin ilk hücresine ne zaman rastlandığına bağlıdır. 3 numaralı grup daha önce bulunmuştur; tarama sağa doğru devam edince sonraki gruba 4 verilmiştir.

<!-- BELİRSİZ: Bu soru-cevap altyazıda kısa ve karışık geçiyor (02:17:00 civarı). -->

### 8.3 8 komşuluk ve yön dizileri

**Soru:** 8 komşulukta grup sayısı artar mı, azalır mı? **Cevap:** Azalır. Çapraz komşular da aynı gruba alındığı için çaprazdan değen gruplar birleşir. Derste 4 komşulukta 6 grup, 8 komşulukta 3 grup bulundu. Hangi komşuluğun seçileceği uygulamaya göre değişir; görüntü işlemede farklı anlamları vardır.

8 komşuluk kodunda yönler dizilerle verilir ve bir `for` döngüsüyle çağrılır (ekrandan, 02:20:00):

```c
void dfs(int x, int y, int current_label,int m[][10],int row_count,int col_count,int label[][10]) {
    int direction;
    // direction vectors
    int dx[] = {+1, 0, -1, 0, -1, -1, +1, +1};
    int dy[] = {0, +1, 0, -1, -1, +1, -1, +1};
    //      down, right, up, left

    if (x < 0 || x == row_count) return; // out of bounds
    if (y < 0 || y == col_count) return; // out of bounds
    if (label[x][y] || !m[x][y]) return; // already labeled or not marked with 1 in m

    // mark the current cell
    label[x][y] = current_label;
    // recursively mark the neighbors
    for (direction = 0; direction < 8; ++direction)
        dfs(x + dx[direction], y + dy[direction], current_label,m,row_count,col_count,label);
}
```

`(+1, 0)` çifti "x'te bir ileri git, y'de sabit kal" demektir; `(0, +1)` "x sabit, y'de bir ileri" demektir. Dizilerdeki değerlerin karşılıklı olarak doğru eşleşmesi gerekir. İlk dört çift aşağı, sağ, yukarı, sol; son dört çift çaprazlardır. Aynı yön dizisi fikriyle 4 komşuluk da `direction < 4` döngüsüyle yazılabilir. Kod kısalır ama karmaşıklık aynıdır: yine 8 özyinelemeli çağrı yapılır, yalnız bir döngünün içinde.

Ajan, 4 komşuluk dosyasındaki matrisle 8 komşuluk fonksiyonunu çalıştırdı; 3 bileşen çıktı. Ekrandaki 8 komşuluk dosyasında matrisin ilk satırları 4 komşuluk dosyasından biraz farklı görünüyor (ekrandan, 02:20:00); matrisin tamamı karede okunamadığı için çıktı 4 komşuluk matrisiyle kontrol edildi.

Hoca bu kod için de bağıntı yazdı: her çağrıda birkaç karşılaştırma ve bir atama (sabit iş) ile 4 özyinelemeli çağrı vardır; matris iki boyutlu olduğu için $n^2$ elemanlı düşünülür ve $4T(\dots)+1$ biçiminde bir bağıntı çıkar. (Gerçek maliyet için Bölüm 7.3'teki ders sonrası nota bakın.)

<!-- BELİRSİZ: Bağlı bileşen bağıntısının parametresi altyazıda "4 t n'li bir şey", "n kare eksi bir" diye net olmayan biçimde geçiyor. -->

Flood fill ile bağlı bileşen etiketleme birbirinin tersi gibidir: flood fill'de nesne yoktur, çizgilere bakarak bir bölge doldurulur; bağlı bileşende nesne grupları vardır ve her biri ayrı etiketlenir (örneğin hangi bölgenin kanserli hücre olabileceği gibi).

> **Hocanın vurgusu:** Dersi tekrar ederken örnekleri baştan kendiniz çözün: önce ağacı bir kenara çizin, sonra bir toplam sembolü denklemi üretin, toplamdan önce ağacın yüksekliğini bulun, sonra verilen formülleri kullanarak basit işlemlerle sonuca gidin.

## 9. C ile ilgili kısa sorular

Dersin sonunda öğrencilerden C ile ilgili birkaç soru geldi.

**Soru:** `long double` değişkene `scanf` ile `%Lf` (ya da `%llf`) kullanarak değer okununca 0 atanıyor; `double` ile sorun yok. Neden? **Cevap:** Hoca önce sayının ondalık ayırıcı olarak virgülle değil noktayla girilmesi gerektiğini hatırlattı; virgüllü giriş kabul edilmez. Sonra internette arama yaptı ve sorunun derleyiciden kaynaklanabileceğini söyledi (Dev-C++ MinGW kullanır). Farklı derleyicileri denemek için ideone gibi bir çevrimiçi derleyicide denenmesini önerdi. Ders kapsamında `long double` gibi uç türlere gerek olmadığını, `double`'ın yeterli olduğunu söyledi. Öğrenci aynı kodun ideone'da çalıştığını, kendi ortamında çalışmadığını söyledi; hoca bunun büyük olasılıkla derleyicinin standardıyla ilgili olduğunu söyledi.

> **Ek bilgi (derste anlatılmadı):** Windows'taki MinGW tabanlı derleyiciler büyük olasılıkla `printf`/`scanf` için Microsoft'un C çalışma zamanı kütüphanesini kullanır; bu kütüphanede `long double`, `double` ile aynı boyutta kabul edilir ve `%Lf` ile okuma/yazma bozuk sonuç verebilir. Bu yüzden aynı kod Linux'taki GCC'de doğru çalışırken Windows'ta 0 ya da anlamsız değer gösterebilir. `__USE_MINGW_ANSI_STDIO` tanımlamak bazı MinGW sürümlerinde bu sorunu giderir.

**Soru:** Bir fonksiyona birkaç dizi ve her birinin uzunluğu gönderilince parametre listesi çok uzuyor (`func(AR, u1, ar2, u2, ar3, u3)`). Nasıl kısaltılır? **Cevap:** (ekrandan, 02:50:00) Uzunluklar program boyunca değişmeyen sabitlerse `#define u1 5`, `#define u2 55` gibi tanımlanır; parametre olarak gönderilmesine gerek kalmaz. Matrislerde birinci boyut sabitse sabit olarak alınır, ikinci boyutlar parametre olarak gider. Boyutlar kullanıcıdan alınıp sonra değişmiyorsa hepsi bir "boyutlar dizisine" konup tek parametre olarak gönderilebilir; örneğin dizinin sıfırıncı elemanı birinci matrisin sütun sayısı, birinci elemanı ikinci matrisin sütun sayısı olur. Global değişken kullanılmamalı, parametre aktarımı yapılmalıdır.

Çok uzun parametre listesi istenmeyen bir durumdur; buna "primitive obsession" (ilkel verilere takıntı) ya da "long parameter list" denir. Hoca, parametreler her çağrıda yığına aktarıldığı için bazı eski C derleyicilerinde yığın taşmasın diye parametre sayısına bir sınır konduğunu söyledi.

**Soru:** Kodlama yarışmalarında (competitive programming) test durumlarının bir kısmı geçilemiyor; ne önerirsiniz? **Cevap:** Bu yarışmalar dinamik programlama, backtracking ve özyinelemeli algoritma tasarım yöntemleri gibi henüz görülmemiş konulara dayanır; genellikle optimizasyon soruları sorulur. Birinci sınıfta bu konular ve veri yapıları henüz anlatılmadığı için zorlanmak normaldir. İlk akla gelen algoritma her durumda çalışmayabilir; test durumları uç değerler ve programı "patlatacak" değerler içerebilir, kod bunlara göre kontrol edilmelidir. Farklı çözüm yöntemleri üzerinde düşünmek önerildi.

## Örnek Sorular

**1. (ekrandan, 00:15:00)** Aşağıdaki fonksiyon `main` içinden `func4(3)` ile çağrılırsa ekrana kaç mesaj yazılır? Karmaşıklık bağıntısı nedir?

```c
void func4(int N){
    int i;
    if(N==0) return;
    for(i=0;i<N;i++){
        printf("Message\n");
    }
    func4(N-1);
    func4(N-1);
}
```

> **Çözüm:** Derste sayaçla gösterildi: 11 mesaj ($3+2+1+1+2+1+1$). Bağıntı $T(N)=N+2T(N-1)$, $T(0)=1$; karmaşıklık üsteldir ($2^N$ mertebesi). $N=10$ için 2036 mesaj yazılır.

**2. (ekrandan, 00:25:00)** $T(n)=2T(n/4)+n$ için özyineleme ağacını çizip karmaşıklığı bulunuz.

> **Çözüm:** Derste verildi (Bölüm 3): seviye maliyetleri $n, n/2, n/4, \dots$, $h=\log_4 n$, $T(n)=2n-\sqrt n=O(n)$.

**3. (ekrandan, 00:40:00)** $T(n)=8T(n/2)+n$ için özyineleme ağacını çiziniz.

> **Çözüm:** Derste verildi: $T(n)=\frac n3(4n^2-1)=O(n^3)$.

**4. (ekrandan, 00:50:00)** $T(n)=8T(n/2)+1$ için $O(\cdot)$ nedir?

> **Çözüm (derste verilmedi):** Slaytta yalnız sonuç $O(n^3)$ verildi. $T(n)=\sum_{i=0}^{\log_2 n}8^i=\frac{8n^3-1}{7}=O(n^3)$.

**5. (derste sözlü, 00:49:19)** Bir kod $n=1000$ için 1 ms sürüyor. Kodun karmaşıklığı $O(1)$, $O(n)$, $O(n^2)$, $O(n^3)$ ise $n=2000$ için yaklaşık ne kadar sürer?

> **Çözüm:** Derste verildi: $O(1)$ için yine 1 ms, $O(n)$ için 2 ms, $O(n^2)$ için 4 ms, $O(n^3)$ için 8 ms. Girdi iki katına çıkınca süre $2^k$ katına çıkar ($k$: polinomun derecesi).

> **Ders sonrası not:** Hoca sabit karmaşıklık için bir an "yine 1000 olacaktır" dedi; doğrusu sürenin yine 1 ms olmasıdır.

**6. (ekrandan, 01:10:00 - 01:20:00)** $T(n)=4T(n/3)+1$, $T(n)=9T(n/3)+1$ ve $T(n)=4T(n/3)+n$ bağıntılarını özyineleme ağacıyla çözünüz.

> **Çözüm:** Derste verildi (Bölüm 4): sırasıyla $O(n^{\log_3 4})\approx O(n^{1.26})$, $O(n^2)$ ve $O(n^{\log_3 4})$.

**7. (ekrandan, 01:25:00)** $T(n)=2T(n-1)+1$ bağıntısını çözünüz.

> **Çözüm:** Derste verildi: $h=n$, $T(n)=2^{n+1}-1=O(2^n)$.

**8. (ekrandan, 02:30:00 - 02:35:00)** Vize sınavında sorulan ve derste çözülen soru: Aşağıdaki algoritmada `rand()` 0-1 aralığında rastgele bir gerçel sayı üretir. $N$ çok büyükken `say/N` hangi değere yaklaşır?

```text
oku(N);
say=0;
for i=1:N
   s1=rand();
   s2=rand();
   if (s1*s1<=s2)
      say=say+1;
   end
end
yaz(say/N)
```

> **Çözüm:** Derste verildi. $(s_1,s_2)$ çiftleri $N$ büyüdükçe birim kareyi düzgün biçimde doldurur. $s_1^2\le s_2$ koşulu, $s_2=s_1^2$ eğrisinin üst tarafındaki bölgeyi seçer. `say/N`, bu bölgenin alanına yaklaşır. Eğrinin altındaki alan $\int_0^1 x^2\,dx=\frac13$ olduğundan üstteki alan $1-\frac13=\frac23$'tür. Bu, daha önce derste çözülen $\pi$ örneğine benzer: orada $s_1^2+s_2^2<1$ koşuluyla çeyrek daire alanı bulunuyor ve $4\cdot\text{say}/N\approx\pi$ oluyordu.

**Soru:** $s_2$ 0 ile 1 arasında değiştiğine göre ortalaması 0.5 olmaz mı, doğrudan eğrinin altındaki alan diyemez miyiz? **Cevap:** Burada ortalama ile ilgilenilmez. $s_2$ 0 ile 1 arasındaki her değeri alabilir; bakılan şey, koşulu sağlayan noktaların bütün noktalara oranıdır, yani bir alandır. **Soru:** `rand()`'ın yalnız 0 ve 1 değerlerini, yani dört olası durumu ($00, 01, 10, 11$) ürettiği düşünülebilir mi? **Cevap:** Hayır; soruda `rand()`'ın 0 ile 1 aralığında gerçel sayı (örneğin 0.005 ya da 0.8) ürettiği not olarak verilmiştir.

**9. (ekrandan, 02:35:00)** Aynı algoritmada koşul `if (s1>1-s2) && (s2<0.5)` olursa `say/N` neye yaklaşır?

> **Çözüm:** Derste sonucu $\frac18$ olarak verildi ve iki bölgenin ortak kısmının alınacağı söylendi. Ayrıntı (ara adım eklendi): $s_1>1-s_2$, yani $s_1+s_2>1$ köşegenin üstündeki üçgendir; $s_2<0.5$ ile kesişimi, $s_2$ ekseninde 0'dan 0.5'e uzanan ve alanı $\int_0^{0.5}s_2\,ds_2=\frac{(0.5)^2}{2}=\frac18$ olan üçgendir.

**10. (derste sözlü, 02:35:28)** Vize sınavında sorulan ve derste çözülen soru: $N$ öğrencinin vize ve final notlarının ortalamasını, en büyüğünü ve en küçüğünü hesaplayan bir program yazılacaktır. Bellek kullanımı açısından en uygun veri yapısı hangisidir? Anlatımdan çıkan seçenekler: notların bir diziye kaydedilmesine gerek yoktur; notlar $N$ elemanlı iki diziye kaydedilmelidir; notlar $N\times2$ ya da $2\times N$'lik bir matrise kaydedilmelidir; notlar sıralı girilecekse dizi ya da matris gerekir.

<!-- BELİRSİZ: Soru metni ekranda görünmedi; seçeneklerin tam metni ve harfleri altyazıdan kesin çıkmıyor. -->

> **Çözüm:** Derste verildi: notların diziye kaydedilmesine gerek yoktur. Ortalama için kümülatif toplam, en büyük ve en küçük için birer değişken tutulur; ilk girilen değer hem en büyük hem en küçük kabul edilip yeni değerlerle güncellenir. İki $N$ elemanlı dizi, $N\times2$ ya da $2\times N$ matris seçeneklerinin hepsi $2N$ yer kaplar ve birbirinden farkı yoktur; bu yüzden birlikte elenebilir. Dizi ancak notlar sıralanacaksa ya da örneğin 500. öğrenci bulunacaksa gerekir.

## Dersin Toparlaması

Bu derste özyinelemeli algoritmaların karmaşıklığı özyineleme ağacı yöntemiyle çözüldü. Bir bağıntıdaki katsayının dal sayısını, bölenin (ya da azaltmanın) ağacın derinliğini, ek terimin de her seviyedeki yükü verdiği görüldü. Yöntem her örnekte aynıydı: seviye maliyetlerini yaz, toplam sembolüne çevir, ağacın yüksekliğini bul, geometrik seri formülü ve $a^{\log_b n}=n^{\log_b a}$ kuralıyla sadeleştir. Bölerek giden (divide and conquer) örneklerde $O(n)$, $O(n^3)$, $O(n^{\log_3 4})$, $O(n^2)$ gibi sonuçlar, azaltarak giden (decrease and conquer) $T(n)=2T(n-1)+1$ örneğinde ise $O(2^n)$ bulundu.

Fibonacci örneği aynı problemin üç farklı karmaşıklıkta çözülebileceğini gösterdi: özyinelemeli çözüm altın oranın üssü kadar ($\approx2^n$), iteratif çözüm $O(n)$, matris üssüyle hızlı üs alma ise $O(\log n)$ zaman alır. Son bölümde özyinelemenin gerçek bir uygulaması olarak Paint'teki boya kovasının arkasındaki flood fill algoritması ve görüntüdeki nesneleri sayan bağlı bileşen etiketleme anlatıldı; 4 ve 8 komşuluğun bileşen sayısını nasıl değiştirdiği kod üzerinde gösterildi. Bu analizlerin devamı ayrık matematik ve veri yapıları derslerinde gelecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
