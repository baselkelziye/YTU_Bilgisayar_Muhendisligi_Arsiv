# Ders 16 Genişletilmiş Notu: Özyinelemeli Algoritmaların Analizi: Fark Denklemleri, Üs Alma Örnekleri ve Merge Sort

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Özyinelemeli algoritmaların analizi ve fark denklemi
- 2. Faktöriyel örneği: backward substitution ve özyineleme ağacı
- 3. Üs alma (power) problemi: iteratif çözümler
- 4. Üs alma problemi: özyinelemeli çözümler ve analizleri
- 5. Merge Sort
- Örnek Sorular
- Dersin Toparlaması

## 1. Özyinelemeli algoritmaların analizi ve fark denklemi

Bir önceki derste özyinelemeli (recursive) algoritmaların basit örneklerine başlanmıştı. Bu derste önce kısa bir hatırlatma yapılıp bu algoritmaların nasıl analiz edildiği gösterildi, sonra daha işe yarar örneklere geçildi.

İteratif algoritmaları analiz ederken temel işlem, döngünün kaç kez döndüğünü saymaktı. Özyinelemeli algoritmada döngü yoktur; tekrar, fonksiyonun kendini çağırmasıyla olur. Bu tekrarı bir bağıntıyla, bir denklemle yazarız. Bu denkleme **fark denklemi** ya da **recurrence relation** denir.

### 1.1 Temel adım ve özyinelemeli adım

Özyinelemeli bir algoritma iki parçadan oluşur (ekrandan, 00:10:00):

- **Temel adım (basic step):** algoritmanın sonsuza kadar gitmesini engelleyen kısımdır. Genellikle fonksiyonun en başında yazılır.
- **Özyinelemeli adım (recursive step):** fonksiyonun daha küçük bir girdiyle kendini çağırdığı kısımdır.

Algoritmanın karmaşıklığına $T(n)$ dersek, temel adımdan $n$'e bağlı bir maliyet çıkar. Bu, iteratif algoritmaların analiziyle aynıdır: temel adımda döngü yoksa maliyet sabittir, döngü varsa $n$ ya da $n^2$ gibi bir şey olabilir. Ekranda bu maliyet $\alpha$ ile gösterildi. Özyinelemeli adımdan ise $n$'in daha küçük bir değeri için maliyet gelir: $n-a$ biçiminde ($n-1$, $n-2$, ...) ya da $n/b$ biçiminde ($n/2$, $n/4$, ...). Böylece genel biçim şöyledir:

$$T(n)=\alpha+T(n-a)\qquad\text{ya da}\qquad T(n)=\alpha+T(n/b)$$

Bu denklemde iki bilinmeyen vardır: $T(n)$ ve $T(n-a)$. Bunlardan birinden kurtulmak için temel adıma karşılık gelen bir **başlangıç koşulu (initial condition)** kullanılır, örneğin $T(0)=1$ ya da $T(1)=1$. $n-a$ ya da $n/b$ bu başlangıç koşuluna yaklaştırıla yaklaştırıla bilinmeyenlerden biri yok edilir ve $T(n)$ açığa çıkar.

Yani ilk adım her zaman algoritmayı yazmak, sonra algoritmadan fark denklemini çıkarmaktır.

### 1.2 Çözüm yöntemleri

Fark denklemini çözmenin birkaç yolu vardır. Hoca bunların ayrık matematik dersinde daha ayrıntılı işleneceğini söyledi. Bu derste iki yöntem kullanıldı:

- **Geriye doğru yerine koyma (backward substitution):** $n$ bilinmiyor, $0$ biliniyor. $n$'den $n-1$'e, $n-1$'den $n-2$'ye açarak bilinmeyenden bilinene doğru gidilir, bir örüntü (pattern) aranır.
- **Özyineleme ağacı (recursion tree):** her çağrı bir düğümdür, düğümün maliyeti yazılır, ağacın yüksekliği bulunur ve bütün maliyetler toplanır.

Bir de bilinenden bilinmeyene doğru giden **ileriye doğru yerine koyma (forward substitution)** vardır; hoca bunun biraz daha karışık olduğunu söyleyip yalnız adını verdi.

> **Hocanın vurgusu:** Karmaşıklık bulmak, fonksiyonun döndürdüğü değeri bulmak değildir. Faktöriyel için fark denklemi çözülünce $n!$'in yaklaşık değeri bulunmaz; yapılan işlem sayısı bulunur.

## 2. Faktöriyel örneği: backward substitution ve özyineleme ağacı

### 2.1 Fark denkleminin yazılması

Ekrandaki kod (ekrandan, 00:10:00):

```c
int myFactorial(int N){
    int T;
    if(N==0)
        return 1;
    T = N*myFactorial(N-1);
    return T;
}
```

Temel adımda `N==0` kontrolü bir birimlik, `return 1` de bir birimlik işlemdir; toplam iki birim. Ama burada $n$'e bağlı bir döngü olmadığı için bu sabit $1$ olarak alınabilir. $n$ ister $1$ ister $1000$ olsun bu kısım iki kez yapılır; orada $10$ işlem olsaydı da $1$ yazılabilirdi. Özyinelemeli adımda fonksiyon kendini $N-1$ ile çağırır. Buradan (ekrandan, 00:15:00):

$$T(N)=1+T(N-1),\qquad T(0)=1$$

### 2.2 Backward substitution

Açılım adım adım şöyledir (ekrandan, 00:15:00):

$$\begin{aligned}
T(N)&=T(N-1)+1\\
&=\big(T(N-2)+1\big)+1=T(N-2)+2\\
&=\big(T(N-3)+1\big)+2=T(N-3)+3\\
&\;\;\vdots\\
&=T(N-k)+k
\end{aligned}$$

$T(N-1)$'i açmak için denklemde $n$ yerine $n-1$ yazılır: $T(N-1)=T(N-2)+1$. Her açılışta parantezin içi bir azalır, dışarıya bir $+1$ eklenir.

Şimdi $T(N-k)$'nin temel duruma, yani $T(0)$'a benzemesi istenir. Bunun için $k=N$ olmalıdır; yani denklem $N$ kez açılınca $T(0)$'a ulaşılır:

$$T(N)=T(0)+N=1+N=N+1\approx N$$

Sıfırıncı dereceden $1$ terimi ihmal edilir, birinci dereceden $N$ terimi kalır. Sonuç $O(N)$'dir. Faktöriyel normal bir döngüyle yazıldığında da döngü $N$ kez dönüyordu, yani zaman açısından hiçbir şey değişmedi. Üstelik özyinelemeli sürüm bellek kullanımı açısından daha verimsizdir. Hoca bu örneğin yalnız tasarım ve analiz yöntemini öğrenmek için seçildiğini hatırlattı.

Bu yönteme **backward** denmesinin sebebi, bilinmeyen $n$'den bilinen $0$'a doğru gidilmesidir. Temel adımda bir döngü olsaydı maliyet $1$ yerine $n$ ya da $n^2$ olurdu; yine fonksiyonun kendini kaç elemanla çağırdığına bakılarak $T(n)=\text{temel maliyet}+T(n-1)$ gibi yazılır ve aynı yolla çözülür.

### 2.3 Özyineleme ağacı

Ders notunda ağaç yatay çizilmiş; hoca bunu dikey olarak yeniden çizdi. $T(n)$ bir birimlik iş yapar ve $T(n-1)$'i çağırır. $T(n-1)$ bir birimlik iş yapar ve $T(n-2)$'yi çağırır. Bu şekilde $T(n-k)$'ye kadar iner. Her seviyede bir tane $1$ vardır; ne kadar $1$ varsa toplam maliyet o kadardır. Kaç tane $1$ olduğu ağacın derinliğine bağlıdır. Ağacın derinliği temel adıma göre belirlenir: $T(0)=1$ ya da $T(1)=1$. $n-k$'yı $0$'a yaklaştırmak için $k=n$ verilir, yani ağacın yüksekliği $n$'dir ve toplam $n$ tane $1$ vardır: $T(n)=O(n)$.

Özetle: zaman kazancı olmadı, fonksiyon çağrıları yüzünden bellekte kayıp oldu.

## 3. Üs alma (power) problemi: iteratif çözümler

Şimdi gerçekten işe yarayan bir özyinelemeli fonksiyona geçildi: $x^n$ hesabı. Hoca algoritmaların hepsini `main` içine değil, ayrı fonksiyonlara yazdı.

### 3.1 power1: düz for döngüsü

İlk yaklaşım iteratiftir: `r` sonucu $1$'den başlar ve döngü her turda `r`'yi $x$ ile çarpar (ekrandan, 00:30:00):

$$T(n)=\sum_{i=1}^{n}1=n$$

Ekrandaki fonksiyon (ekrandan, 00:25:00):

```c
int power1(int x, int n){
    int r=1;
    int i;
    if (n==0 && x!=0 ) return 1;
    if (n==0 && x==0 ) return -1;// indefinite
    for(i=1;i<=n;i++){
        r = r * x;
    }
    return r;
}
```

$n=0$ ve $x\neq0$ ise sonuç $1$'dir. $0^0$ tanımsız olduğu için bu durumda tanımsızlığı göstermek üzere $-1$ döndürülüyor; hoca bunun da tam anlamlı bir değer olmadığını, yalnız "tanımsız" demek için kullanıldığını belirtti. `main` içinde `printf("%d^%d = %d\n", 2, 10, power1(2,10));` ile $2^{10}=1024$ yazdırıldı. Döngü $10$ kez döndü. En kötü durumda ($n>0$) karmaşıklık $T(n)=n$'dir.

> **Hocanın vurgusu:** "Neden hazır power fonksiyonunu kullanmıyoruz?" sorusunun cevabı: Python'da, JavaScript'te, C'de üs alma hazır vardır ve kullanmak sorun değildir. Ama amaç olayın mantığını anlamaktır. Bilgisayar mühendisinin asıl işi algoritma tasarlamaktır; bazı problemlerde kendi özyinelemeli fonksiyonunuzu yazmak zorunda kalacaksınız ve basit örnekleri yapmadan karmaşık olanları tasarlamak zordur.

### 3.2 power3: iteratif hızlı üs alma

Hoca önce iteratif algoritmayı iyileştirdi. Fikir ekranda şöyle çizildi (ekrandan, 00:30:00): $n$ çiftse $x\to x^2\to x^4\to\dots$ diye kare alarak ilerlenir; $n$ tekse bir kez $x$ ile çarpılıp çift duruma geçilir ($x\to x^2\to x^3\to\dots$).

```c
int power3(int x, int n){ // T(n) = logn (base:2)
    int r=1;
    while(n>0){
        if(n%2==0){
            x = x*x;
            n = n/2;
        }
        else{
            r = r * x;
            n = n - 1;
        }
    }
    return r;
}
```

(ekrandan, 00:35:00; `return r;` satırı altyazıdan)

$n$ çiftse tabanın karesi alınır ve üs yarıya iner, çünkü artık elde $x^2$ vardır ve $x^n$ yerine $(x^2)^{n/2}$ hesaplamak yeter. $n$ tekse sonuç `r` bir kez $x$ ile çarpılır ve üs bir azalır.

$x$ tabanı ve $n=16$ için adımlar (ara adım eklendi):

| Tur | Başta $n$ | Durum | İşlem | Sonra $x$ (başlangıç $x$ cinsinden) | Sonra $n$ | `r` |
|---|---|---|---|---|---|---|
| 1 | 16 | çift | `x=x*x` | $x^2$ | 8 | 1 |
| 2 | 8 | çift | `x=x*x` | $x^4$ | 4 | 1 |
| 3 | 4 | çift | `x=x*x` | $x^8$ | 2 | 1 |
| 4 | 2 | çift | `x=x*x` | $x^{16}$ | 1 | 1 |
| 5 | 1 | tek | `r=r*x` | $x^{16}$ | 0 | $x^{16}$ |

Dört kare alma ve bir son çarpma ile iş biter. Hoca da düz yöntemde $16$ çarpma, bu yöntemde $4$ kare alma olduğunu söyledi. $n=17$ gibi tek bir değerle başlanırsa ilk turda bir kez `else` koluna düşülüp $16$'ya inilir, sonra hep yarılanarak devam edilir. Üs çoğunlukla yarılandığı için karmaşıklık yaklaşık $\log_2 n$'dir:

$$T(n)\approx\log_2 n$$

Kod `printf` ile $2^{16}=65536$ ve $2^{10}=1024$ için çalıştırıldı.

**Soru:** $2$ yerine $4$'e göre mod alsak daha da iyi bir iyileştirme olmaz mı?

**Cevap:** $4$ üzerinden genel bir iyileştirme yapmak çok zordur. $x^n=x^{n/2}\cdot x^{n/2}$ ayrışması her $n$ için kurulabilir (tekse bir $x$ fazladan çarpılır). $n/4$ ile çalışmak için $n$'in $4$'ün katı olmasını garanti etmek gerekir; $n/1$'den sonra en yakın genel bölme $n/2$'dir, $3$ bile olmaz. Genel bir algoritma tasarlamak istediğimiz için $2$ ile düşünülür.

Tek $n$ için kullanılan ayrışma şudur: $x^n=x\cdot x^{\lfloor n/2\rfloor}\cdot x^{\lfloor n/2\rfloor}$.

## 4. Üs alma problemi: özyinelemeli çözümler ve analizleri

### 4.1 power2: doğrudan özyineleme

İlk özyinelemeli sürümde sonuç değişkenine ve döngüye gerek kalmaz:

```c
int power2(int x, int n){
    if (n==0 && x!=0) return 1;
    return x * power2(x, n-1);
}
```

(altyazıdan; `main`'deki çağrı satırı ekranda görünüyor, ekrandan, 00:35:00)

Kod kısalır. Çağrıda iki argümanın da (`x` ve `n-1`) yazılmasına dikkat edilmesi gerektiği söylendi. Fark denklemi faktöriyeldekiyle aynıdır: $T(n)=1+T(n-1)$, sonuç $O(n)$. $2^{10}=1024$ doğru çıktı.

### 4.2 power4: iteratif fikrin özyinelemeli karşılığı

`power3`'teki tek/çift fikri özyinelemeli yazıldı (ekrandan, 00:40:00):

```c
int power4(int x, int n){ // T(n) = 1+ 2* T(n/2) O(n)
    if (n==0 && x!=0 ) return 1;
    if(n % 2 == 0){
        return power4(x,n/2)*power4(x,n/2);
    }
    else{
        return x*power4(x,n/2)*power4(x,n/2);
    }
}
```

(yorum satırı ekrandan, 00:50:00)

$n$ çiftse $x^n=x^{n/2}\cdot x^{n/2}$, tekse fazladan bir $x$ çarpılır. $2^{10}$ için yine $1024$ elde edildi. Bir öğrenci `printf` satırında `power4` yerine hâlâ `power3` çağrıldığını fark etti; satır düzeltildi.

**Fark denklemi.** Tek ve çift durum arasında yalnız bir çarpma fark vardır, bu yüzden çift durumu incelemek yeter. Bir kontrol işlemi ($1$) vardır; fonksiyon kendini $n/2$ ile iki kez çağırır. Aradaki çarpma, maliyetlerin çarpılacağı anlamına gelmez; burada sonuç değil maliyet hesaplanıyor, iki çağrının maliyetleri toplanır (ekrandan, 00:45:00):

$$T(n)=1+T(n/2)+T(n/2)=2T(n/2)+1,\qquad T(1)=1$$

**Özyineleme ağacı.** $T(n)$ iki tane $T(n/2)$ çağırır ve $1$ maliyeti vardır. Her $T(n/2)$ iki tane $T(n/4)$ çağırır ve kendi $1$'ini getirir. İkinci seviyede dört tane $T(n/4)$ ve $2$ birim, üçüncü seviyede sekiz tane $T(n/8)$ ve $4$ birim vardır. Hoca bu ağacın burada biraz zorlayıcı olduğunu, yalnız karmaşık olduğunu göstermek için çizdiğini söyleyip backward substitution'a geçti.

**Backward substitution.** Hoca açılımı yaparken ilk başta dıştaki $2$ katsayısını unuttu, sonra fark edip düzeltti: $n/2$ açılırken dıştaki $2$ de içeri çarpılmalıdır. Doğru açılım şöyledir (ara adımlar eklendi):

$$\begin{aligned}
T(n)&=2T(n/2)+1\\
&=2\big(2T(n/4)+1\big)+1=2^2T(n/2^2)+2+1\\
&=2^3T(n/2^3)+4+2+1\\
&\;\;\vdots\\
&=2^kT(n/2^k)+(2^{k-1}+\dots+2+1)=2^kT(n/2^k)+(2^k-1)
\end{aligned}$$

Temel duruma benzetmek için $n/2^k=1$ alınır, yani $n=2^k$. İki tarafın $2$ tabanında logaritması alınınca $\log_2 n=k\log_2 2=k$ bulunur (ekrandan, 00:45:00):

$$k=\log_2 n$$

Yerine yazınca:

$$T(n)=n\cdot T(1)+(n-1)=2n-1=O(n)$$

> **Ders sonrası not:** Hoca katsayıyı $2^k$ olarak düzeltti ama toplamsal kısmı $k\cdot1$ olarak bıraktı ve sonucu $n+\log_2 n$ olarak yazdı. Toplamsal kısım her seviyede ikiye katlandığı için ($1+2+4+\dots$) doğrusu $2^k-1=n-1$'dir ve sonuç $2n-1$ olur. Python ile $n=16$ için $T=31$, $n=1024$ için $T=2047$ bulundu. Derste gösterilen ders notunda da (ekrandan, 01:00:00) sonuç $2N-1=O(n)$ olarak yazılıdır. Varılan $O(n)$ sonucu her iki durumda da aynıdır.

**Neden iyileşmedi?** Hoca $x^{16}$ için çağrıları açtı: `power4(x,16)` iki kez `power4(x,8)` çağırır; her biri iki kez `power4(x,4)`, onlar iki kez `power4(x,2)`, onlar da iki kez `power4(x,1)` çağırır. Birinci `power4(x,8)` hesaplandığı hâlde ikinci `power4(x,8)` aynı işi baştan yapar. Aynı şeyi tekrar tekrar hesaplamak karmaşıklığa yansır ve sonuç yine $O(n)$ olur.

**Ders notundaki ağaç.** Ders notunda $T(n)=1+2T(n/2)$ için özyineleme ağacı da verilmiştir (ekrandan, 01:00:00). Seviyelerdeki $1$'lerin sayısı $2^0, 2^1, 2^2, \dots$ diye gider; ağacın yüksekliği $h=\log_2 n$'dir:

$$T(n)=\sum_{i=0}^{\log_2 n}2^i=\frac{2^{\log_2 n+1}-1}{2-1}=2\cdot2^{\log_2 n}-1=2n-1=O(n)$$

Bu, geometrik seri toplam formülüyle bulunur ve normal üs almadan bir farkı yoktur.

### 4.3 power5: sonucu saklayarak tek çağrı

İyileştirme fikri şudur: $x^{n/2}$ bir kez hesaplanıp bir değişkende saklanırsa ikinci çağrıya gerek kalmaz (ekrandan, 00:55:00):

```c
int power5(int x, int n){ // T(n) = 1 + T(n/2) O(logn)
    int t;
    if (n==0 && x!=0 ) return 1;
    t = power5(x,n/2);
    if(n%2 == 0){
        return t*t;
    }
    else{
        return x*t*t;
    }
}
```

`t`, $x^{n/2}$'dir. `power5(x,n/2)` kendi içinden $n/4$'ü, o da $n/8$'i çağırır. $n=16$ için çağrılar $16, 8, 4, 2, 1, 0$ diye iner; $1/2$ tam sayı bölmesinde $0$ olduğu için son çağrı $x^0$'dır ve $1$ döner. Sonra geri dönerken $x$, $x^2$, $x^4$, ... bulunur. Üs çiftse `t*t`, tekse `x*t*t` döndürülür. Böylece özyinelemeli çağrı sayısı bire indi.

**Fark denklemi.** Baştaki kontrol ve dönüşteki çarpmalar sabit işlemdir; $1$, $2$ ya da $3$ demek önemli değildir, $O(1)$ alınır (ekrandan, 00:55:00):

$$T(n)=1+T(n/2),\qquad T(1)=1$$

Backward substitution (ara adımlar eklendi):

$$\begin{aligned}
T(n)&=T(n/2)+1\\
&=T(n/2^2)+1+1\\
&=T(n/2^3)+1+1+1\\
&\;\;\vdots\\
&=T(n/2^k)+k
\end{aligned}$$

$n/2^k=1$ için $k=\log_2 n$ olur ve

$$T(n)=T(n/n)+\log_2 n=T(1)+\log_2 n=\log_2 n+1=O(\log n)$$

Özyineleme ağacında da her seviyede bir tane $1$ vardır ve ağacın derinliği $\log_2 n$'dir. Bu örnekte özyinelemeli algoritma kullanmanın gerçek bir avantajı görülmüş oldu. Ders notunda bu algoritma `hpower` adıyla şu tanımla verilmiştir (ekrandan, 01:50:00):

$$hpower(x,p)=\begin{cases}1 & p=0\\ x\cdot hpower\!\left(x,\lfloor p/2\rfloor\right)^2 & p \text{ tek}\\ hpower\!\left(x,\lfloor p/2\rfloor\right)^2 & \text{aksi hâlde}\end{cases}$$

Ders notunda sonucun "$\log_2 n$ tane $1$, yani $O(\log_2 n)$; normali $O(n)$'di" diye özetlendiği görülüyor (ekrandan, 01:00:00).

> **Ek bilgi (derste anlatılmadı):** `power4` ve `power5`'te `n==0 && x==0` durumu için ayrı bir kontrol yoktur. Bu durumda fonksiyon kendini sürekli `n=0` ile çağırır ve sonlanmaz (büyük olasılıkla yığın taşmasıyla çöker). `power1`'deki gibi `if (n==0 && x==0) return -1;` satırı eklenirse bu durum da ele alınmış olur.

Beş fonksiyon bir arada derlendi (`gcc -Wall`, uyarısız) ve çalıştırıldı; hepsi $2^{10}=1024$ verdi, ayrıca `power3(2,16)` $65536$ ve `power5(3,7)` $2187$ verdi.

## 5. Merge Sort

### 5.1 Sıralama algoritmalarının karmaşıklığı

Daha önce görülen bubble sort, insertion sort ve selection sort algoritmalarının karmaşıklığı genel olarak $n^2$'dir. Counting sort da görülmüştü ama genel bir çözüm sağlamadığı için her yerde işe yaramaz. Bu derste Merge Sort incelendi; kodu kısmen yazıldı ve analizi yapıldı. Quick Sort'un yalnız analizine değinildi, çünkü ayrıntısı veri yapıları dersinde anlatılacak.

### 5.2 Merge: iki sıralı diziyi birleştirme

Merge işlemi daha önce görülmüştü: iki **sıralı** dizi tek bir sıralı dizide birleştirilir. Ekrandaki örnek (ekrandan, 01:15:00):

- Birinci dizi: `1 4 7` (bu diziyi `i` gösterir)
- İkinci dizi: `2 5 8` (bu diziyi `j` gösterir)
- Yerleştirilecek konum `k` ile gösterilir.

Adımlar:

| Adım | `i`'nin gösterdiği | `j`'nin gösterdiği | Alınan | Sonuç dizisi |
|---|---|---|---|---|
| 1 | 1 | 2 | 1 | 1 |
| 2 | 4 | 2 | 2 | 1 2 |
| 3 | 4 | 5 | 4 | 1 2 4 |
| 4 | 7 | 5 | 5 | 1 2 4 5 |
| 5 | 7 | 8 | 7 | 1 2 4 5 7 |
| 6 | (bitti) | 8 | 8 | 1 2 4 5 7 8 |

Her adımda iki işaretçinin gösterdiği elemanlardan küçük olan alınır ve o işaretçi ile `k` bir ilerletilir. Birinci dizide $n$, ikincide $m$ eleman varsa $n+m$ işlem yapılır; toplam uzunluğa $N$ dersek maliyet $N$'dir.

### 5.3 Merge Sort fikri

Elimizde $n$ elemanlı sırasız bir dizi olsun. Dizi önce $n/2$ elemanlı iki parçaya bölünür; ilk yarı $n/4$'lere, onlar $n/8$'lere bölünür. Bu bölme iki tane tek elemanlı dizi kalana kadar sürer. Tek elemanlı bir dizi kendiliğinden sıralıdır. Sonra merge ile iki tek elemanlı dizi birleştirilip iki elemanlı sıralı bir dizi oluşturulur. Aynı işlem diğer yarı için de yapılır. İki elemanlı iki sıralı dizi birleştirilince dört elemanlı sıralı dizi oluşur. Parçalamaya simetrik olarak birleştirme yapılır ve sonunda bütün dizi sıralanır.

Hoca bir Merge Sort animasyonu açtı. Dizi boyutu $8$ seçilip elemanlar girildi ve algoritma adım adım izlendi: dizi önce ilk dört ve son dört eleman diye ikiye bölünüyor, sonra solun solu bölünüyor, tek elemanlı parçalar kalınca bunlar yedek yerlere kopyalanıp küçük olan önce alınarak orijinal diziye geri yazılıyor. Sol yarı sıralandıktan sonra sağ yarı aynı şekilde sıralanıyor ve son adımda iki sıralı yarı birleştiriliyor.

<!-- BELİRSİZ: Animasyonda girilen eleman değerleri altyazıdan tam çıkmıyor; bu sırada bağlantı koptuğu için karelerde de görünmüyor. -->

### 5.4 Merge Sort kodu

Ekranda yazılan kod (ekrandan, 01:30:00 ve 01:40:00):

```c
int main(){
    int N = 8;
    int d[8]={1,4,2,3,5,7,9,19};
    mergeSort(d,0,N-1);
}

void mergeSort(int d[], int l, int r){
    int m;
    if(l<r){
        m = l + (r-l)/2;
        mergeSort(d,l,m);
        mergeSort(d,m+1,r);
        merge(d,l,m,r);
    }
}
```

- `mergeSort`'a dizi, başlangıç indisi ve **son indis** gönderilir. Dizinin boyutu $8$ olduğu için son indis $7$, genel olarak `N-1`'dir.
- `l < r` koşulu, dizinin sol ve sağ sınırlarının henüz birleşmediğini gösterir. Bu koşul sağlanmazsa özyinelemeli işlem yapılmaz; bu kısım temel adım gibi düşünülür.
- Orta nokta `l + (r-l)/2` ile bulunur. `l` her zaman $0$ değildir; örneğin animasyonda sağ yarının içindeki iki elemanlı bir parçada `l` $2$, `r` $3$ olabilir. Bu yüzden orta nokta `l`'ye göre hesaplanır.
- Sol yarı (`l`'den `m`'ye) ve sağ yarı (`m+1`'den `r`'ye) ayrı ayrı sıralanır, sonra `merge(d,l,m,r)` ile birleştirilir. Birleştirme orijinal dizi üzerinde yapıldığı için `merge`'e iki ayrı dizi değil, alt ve üst kısımların indis sınırları gönderilir.

`merge` fonksiyonu daha önceki derste yazıldığı için hoca onu hazır koddan aldı. Fonksiyon dizinin sol kısmını ve sağ kısmını iki geçici diziye kopyalar, sonra iki sıralı diziyi birleştirme kodunu çalıştırır. Geçici dizilerin boyutu için büyük bir sabit ($100$) verildi; hoca bunun normalde C'de böyle yapılmadığını ama burada önemli olmadığını söyledi. Sıralamadan önce ve sonra diziyi yazdırmak için bir `printArray(d, N)` fonksiyonu eklendi; çıktıda dizi önce sırasız, sonra sıralı görüldü.

Derste `merge` fonksiyonunun gövdesi ekranda tam görünmedi. Aşağıdaki gövde ajan tarafından, derste anlatılan mantığa (iki geçici dizi, `i`, `j`, `k` işaretçileri) göre yazılmıştır; derste yazılan kodun aynısı değildir. Tam program `gcc -Wall` ile uyarısız derlendi; `{1,4,2,3,5,7,9,19}` dizisi `1 2 3 4 5 7 9 19` olarak sıralandı.

```c
#include <stdio.h>
void printArray(int d[], int n);
void mergeSort(int d[], int l, int r);
void merge(int arr[], int l, int m, int r);

int main(){
    int N = 8;
    int d[8] = {1, 4, 2, 3, 5, 7, 9, 19};
    printArray(d, N);
    mergeSort(d, 0, N - 1);
    printArray(d, N);
    return 0;
}
void printArray(int d[], int n){
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", d[i]);
    printf("\n");
}
void mergeSort(int d[], int l, int r){
    int m;
    if (l < r){
        m = l + (r - l) / 2;
        mergeSort(d, l, m);
        mergeSort(d, m + 1, r);
        merge(d, l, m, r);
    }
}
void merge(int arr[], int l, int m, int r){  /* gövde ajan tarafından yazıldı */
    int L[100], R[100];
    int n1 = m - l + 1, n2 = r - m;
    int i, j, k;
    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    i = 0; j = 0; k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else              arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}
```

> **Ek bilgi (derste anlatılmadı):** Derste fonksiyonlar `main`'den sonra prototipsiz tanımlandığı için derleyici "conflicting types" uyarıları verdi (ekrandan, 01:40:00). Yukarıdaki gibi fonksiyon prototiplerini `main`'den önce yazmak bu uyarıları giderir.

### 5.5 Merge Sort'un analizi

Merge Sort'un maliyeti iki parçadan oluşur: `mergeSort`'un kendini $N/2$ elemanlı iki parça için iki kez çağırması ve bir `merge` işlemi. İki sıralı diziyi birleştirmenin maliyeti, yarısı bir tarafta yarısı diğer tarafta olmak üzere $N/2+N/2=N$'dir. Buradan (ekrandan, 01:45:00):

$$T(N)=2T(N/2)+N,\qquad T(1)=1$$

Temel durum dizinin tek elemanlı olmasıdır ve maliyeti $1$'dir.

Backward substitution (ara adımlar eklendi):

$$\begin{aligned}
T(n)&=2T(n/2)+n\\
&=2\big(2T(n/4)+n/2\big)+n=2^2T(n/2^2)+2n\\
&=2^2\big(2T(n/2^3)+n/4\big)+2n=2^3T(n/2^3)+3n\\
&\;\;\vdots\\
&=2^kT(n/2^k)+k\cdot n
\end{aligned}$$

$n/2$ yerine $n/4$ yazılınca içeriden $n/2$ maliyet gelir; dıştaki $2$ ile çarpılınca yine $n$ olur. Bu yüzden her açılışta toplam bir $n$ daha eklenir. $k=\log_2 n$ yazılınca:

$$T(n)=2^{\log_2 n}\,T\!\left(\frac{n}{2^{\log_2 n}}\right)+n\log_2 n=n\,T(1)+n\log_2 n=n\log_2 n+n$$

En yüksek dereceli terim $n\log n$ olduğu için Merge Sort'un karmaşıklığı $O(n\log n)$'dir. Hoca bunu şöyle yorumladı: $\log n$ çarpanı diziyi ikiye bölme işleminin sayısından, $n$ çarpanı her seviyedeki merge işleminden gelir. Python ile $n=16$ için $80=16\cdot4+16$, $n=1024$ için $11264=1024\cdot10+1024$ doğrulandı.

**Özyineleme ağacıyla.** Ders notundaki ağaçta (ekrandan, 01:10:00) $T(n)$ kökünde $n$ maliyet, ikinci seviyede iki tane $n/2$, üçüncü seviyede dört tane $n/4$, sonra sekiz tane $n/8$ vardır. Her seviyenin toplamı $n$'dir. Ağaç $h$ kadar derinleşirse toplam $h\cdot n$ olur. Tek elemana inilene kadar bölündüğü için $h=\log_2 n$ ve sonuç $n\log_2 n$'dir.

### 5.6 Quick Sort ile karşılaştırma

Quick Sort'un fark denklemi de Merge Sort'unkiyle aynıdır: $T(n)=2T(n/2)+n$. İkisi de $n^2$'lik selection ve bubble sort gibi algoritmalara göre çok avantajlıdır. Merge Sort ekstra bir dizi (alan) kullanır; Quick Sort bunu yapmaz, elemanları dizinin bulunduğu yerde sıralar.

> **Ek bilgi (derste anlatılmadı):** $T(n)=2T(n/2)+n$ denklemi Quick Sort için yalnız pivot diziyi her seferinde yaklaşık iki eşit parçaya böldüğünde geçerlidir. Pivot kötü seçilirse (örneğin sıralı dizide hep en küçük eleman) denklem $T(n)=T(n-1)+n$ olur ve en kötü durum $O(n^2)$'dir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:15:00): `myFactorial` fonksiyonunun fark denklemini yazıp backward substitution ile çözünüz.

> **Çözüm:** $T(N)=1+T(N-1)$, $T(0)=1$. $T(N)=T(N-k)+k$; $k=N$ için $T(N)=T(0)+N=N+1=O(N)$.

**Soru 2** (derste sözlü, 00:34:53): Hızlı üs almada $2$ yerine $4$'e göre mod alsak algoritma daha da iyileşmez mi?

> **Çözüm:** Genel bir algoritma için $n$'in her değerde ayrıştırılabilmesi gerekir. $x^n=x^{n/2}\cdot x^{n/2}$ (tekse bir $x$ fazla) her $n$ için kurulur; $n/4$ ile çalışmak $n$'in $4$'ün katı olmasını gerektirir. Bu yüzden $2$ ile bölünür.

**Soru 3** (ekrandan, 00:40:00): `power4` fonksiyonunun fark denklemini yazıp çözünüz. Neden `power3` kadar iyi değildir?

> **Çözüm:** $T(n)=2T(n/2)+1$, $T(1)=1$. Açılım $2^kT(n/2^k)+(2^k-1)$; $k=\log_2 n$ için $T(n)=2n-1=O(n)$. Aynı $x^{n/2}$ değeri iki kez ayrı ayrı hesaplandığı için kazanç yok olur.

**Soru 4** (ekrandan, 00:55:00): `power5` fonksiyonunun fark denklemini yazıp çözünüz.

> **Çözüm:** $T(n)=1+T(n/2)$, $T(1)=1$. $T(n)=T(n/2^k)+k$; $k=\log_2 n$ için $T(n)=\log_2 n+1=O(\log n)$.

**Soru 5** (ekrandan, 01:15:00): `1 4 7` ve `2 5 8` sıralı dizilerini merge ile birleştiriniz. Kaç işlem yapılır?

> **Çözüm:** Sonuç `1 2 4 5 7 8`. $n=3$, $m=3$ için $n+m=6$ işlem; genel olarak $N$.

**Soru 6** (ekrandan, 01:45:00): Merge Sort için $T(N)=2T(N/2)+N$ fark denklemini çözünüz.

> **Çözüm:** $T(n)=2^kT(n/2^k)+kn$; $k=\log_2 n$ için $T(n)=n\,T(1)+n\log_2 n=n\log_2 n+n=O(n\log n)$.

## Dersin Toparlaması

Bu derste özyinelemeli algoritmaların analizi için fark denklemi kuruldu: temel adımın maliyeti ile daha küçük girdinin maliyeti toplanır, başlangıç koşulu ile bilinmeyenlerden biri yok edilir. Denklemler backward substitution ve özyineleme ağacıyla çözüldü. Faktöriyel ve doğrudan özyinelemeli üs almada ($T(n)=1+T(n-1)$) iteratif çözüme göre kazanç olmadığı, aynı alt problemi iki kez çağıran `power4`'te ($T(n)=1+2T(n/2)$) de sonucun $O(n)$ kaldığı görüldü. Alt problemin sonucunu bir değişkende saklayan `power5` ise $T(n)=1+T(n/2)$ ile $O(\log n)$'e indi. Son olarak Merge Sort'un bölme ve birleştirme mantığı, kodu ve $T(n)=2T(n/2)+n$ denkleminden çıkan $O(n\log n)$ karmaşıklığı incelendi. Quick Sort'un da aynı denkleme sahip olduğu belirtildi.

Hoca, farklı ağaç yapılarıyla özyinelemeli algoritmaların analizinin ve daha karmaşık özyinelemeli örneklerin sonraki derslerde ele alınacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
