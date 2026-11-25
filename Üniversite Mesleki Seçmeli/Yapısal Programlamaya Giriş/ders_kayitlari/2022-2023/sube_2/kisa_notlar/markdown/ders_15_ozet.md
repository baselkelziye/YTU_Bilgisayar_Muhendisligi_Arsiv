# Ders 15 Çalışma Özeti

## Genel Konular

- Hatırlatma: programın bellek düzeni ve fonksiyon çağrılarında stack
  - Program belleğe yüklenince bölgeler bellidir: Instructions (kodlar, salt okunur), Literals, Static Data (global/statik veriler), Dynamic Data (Heap, programcının yönettiği dinamik veriler) ve Stack (ekrandan, 00:05:00).
  - Stack bölgesinde fonksiyonun parametreleri, yerel değişkenleri, sabit uzunluklu yerel dizileri ve işlemcinin durum bilgisi tutulur. Değişkenler tanımlanma sırasıyla peş peşe yerleştirilir.
  - Bir fonksiyon başka bir fonksiyonu çağırınca dönülecek satır stack'e yedeklenir. Çağrılan fonksiyon bitince onun bütün bilgileri silinir ve kaldığı satırdan devam edilir.
  - Örnekte `main` 2. satırda `f1`'i, `f1` 11. satırda `f3`'ü, `f3` 31. satırda `f4`'ü çağırır. `f4` hiçbir fonksiyon çağırmadığı için biter; dönüş ters sırayla olur: `f4 → f3 → f1 → main` (ekrandan, 00:05:00).
  - Stack "bir dolar, bir boşalır". Bu yapı ileride Assembly, veri yapıları, algoritma analizi ve işletim sistemleri derslerinde tekrar karşılaşılacak bir mekanizmadır.
- Özyineleme (recursion) kavramı
  - Bir fonksiyonun kendini doğrudan (`f2` içinden `f2`) ya da dolaylı olarak (`f1 → f3 → f1`) çağırmasıdır (ekrandan, 00:10:00).
  - İngilizcedeki "recurrence" bir şeyin tekrar etmesi, nüksetmesi anlamındadır; ders notlarında "özünü yineleyen, kendini yineleyen" diye geçer.
  - Şimdiye kadarki algoritmalar iteratifti; özyinelemeli fonksiyonlar kendilerini çağırabilir.
- Sonsuz özyineleme ve stack taşması
  - Durma koşulu olmayan özyinelemeli fonksiyon teoride sonsuza kadar çağrılır, pratikte stack bölgesi dolar ve işletim sistemi programı sonlandırır (stack overflow).
  - Derste `f2(int x)` her çağrıda `"fonksiyon %d. kez cagrildi"` yazdırıp `f2(++x)` ile kendini çağırdı (ekrandan, 00:20:00). Bu bilgisayarda yaklaşık 43.178 çağrıdan sonra program durdu.
  - Fonksiyona yerel bir dizi (`int dizi[1000];`, sonra `int dizi[100];`) eklenince her çağrı stack'te daha çok yer kapladığı için program çok daha erken durur.
  - Döngü içinde bir fonksiyonu sonsuz kez çağırmak ise sorun değildir: her çağrı bitip stack'i boşaltır.
- Özyinelemeli fonksiyonun genel yapısı (ekrandan, 00:30:00)
  - 1. kısım **base case** (temel durum): genellikle bir `if` ile kontrol edilir ve mutlaka `return` ile biter.
  - 2. kısım **recursive case**: gerekli işlemler yapılır ve fonksiyon yeni argümanlarla tekrar çağrılır.
  - Base case önce yazılır. Sıra ters olursa fonksiyon hiç durmaz.
  - Fonksiyon kaç parametre alıyorsa çağrıda o kadar argüman gönderilir; tanımdakiler parametre, çağrıda gönderilenler argümandır.
- Durdurma için `return`
  - `break` döngüden çıkar, `continue` döngünün o adımını atlar; ikisi fonksiyondan çıkmak için kullanılamaz. Fonksiyondan çıkmak için `return` kullanılır.
  - `return` özyinelemeli çağrıdan sonra yazılırsa hiç çalışmaz (ekrandan, 00:25:00). Çağrıdan önce bir koşula bağlanmalıdır, örneğin `x` belli bir sayıya ulaşınca `return`.
- Faktöriyel
  - Temel durum $0! = 1$. Özyineleme: $n! = n \cdot (n-1)!$.
  - Kod (ekrandan, 00:50:00): `if(N==0) return 1; T = N*myFactorial(N-1); return T;`
  - `myFactorial(4)` izlemesi (ekrandan, 00:40:00): çağrılar ileri yönlü $4 \to 3 \to 2 \to 1 \to 0$; `myF(0)` 1 döndürür, sonra $1\cdot1=1$, $2\cdot1=2$, $3\cdot2=6$, $4\cdot6=24$ geriye doğru hesaplanır.
  - Çağırma ileri yönlü (push), hesaplamanın tamamlanması geri yönlüdür (pop).
  - `N*myFactorial(--N)` yazılınca 5! için 24 çıktı (ekrandan, 00:45:00). Doğrusu `N-1` göndermektir.
  - Negatif argüman (`myFactorial(-3)`) sonsuz özyinelemeye girer; `if(N<0) return -1;` gibi bir kontrol eklenir.
- Recurrence relation (yineleme bağıntısı)
  - $f(n) = n \cdot f(n-1)$, $f(0)=1$. Açılınca $f(n) = f(n-k)\cdot(n-k+1)\cdots(n-1)\cdot n$; $k=n$ alınınca $f(n)=1\cdot 2\cdots n$ olur.
  - Özyinelemeli faktöriyel de $n$ adım sürer; iteratif faktöriyelle aynı karmaşıklıktadır.
- Üs alma $x^n$
  - Temel durumlar (ekrandan, 01:10:00): `x==0` ve `n==0` ise $0^0$ tanımsız kabul edilip `-1`; `x==0` ve `n>1` ise `0`; `n==1` ise `x`.
  - Özyineleme: $x^n = x \cdot x^{n-1}$, yani `return x*powerXtoN(x,n-1);`.
  - Test çıktıları: $5^3=125$, $(-5)^4=625$, $(-5)^3=-125$. Negatif taban için ek kural gerekmez.
  - Negatif üs ($n<1$) için $x^n = \frac{1}{x}\cdot x^{n+1}$ fikri denendi (`return 1.0/x*powerXtoN(x,n+1);`, ekrandan, 01:15:00). Sonuç ondalıklı olduğu için fonksiyonun `double` döndürmesi gerekir. Bu kısım derste tam çalışır hale getirilemedi.
  - $x^n$'i $x^{n/2}$'yi bir kez hesaplayıp kendisiyle çarparak bulmak daha hızlı bir yoldur; bu yöntem ileride ayrıca ele alınacak.
- Dizilerle özyineleme
  - `toplam1(a,b)`: `b==0` ise `a` döner, değilse `toplam1(a+1,b-1)` çağrılır. `toplam1(2,6)` = 8; yani iki sayı dolaylı yoldan toplanır (ekrandan, 01:30:00).
  - `toplam2(dizi, n)`: `n` son elemanın indisidir. `n==0` ise `dizi[0]`, değilse `dizi[n] + toplam2(dizi, n-1)`. `{1,2,3,4,5}` için 15.
  - `ara(dizi, n, key)` (ekrandan, 01:40:00): `n<0` ise `-1` (bulunamadı), `dizi[n]==key` ise `n`, değilse `ara(dizi,n-1,key)`. 3 arandığında indis 2, -3 arandığında -1 döner.
- Özyinelemenin kullanım alanları
  - Fraktallar (çokgenlerin köşelerine yeni çokgenler, kare içinde kareler, özyinelemeli ağaç), palindrom kontrolü, Hanoi kuleleri.
  - Merge Sort ve Quick Sort özyinelemelidir; $n^2$'lik sıralamalar (Bubble Sort) bunlarla $n \log n$'e iner. Bir web animasyonunda Merge Sort'un çağrıları (0-3, 0-1, 0-0 aralıkları) adım adım gösterildi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Base case önce, recursive case sonra yazılır
  - Ters sırada yazılan ya da çağrıdan sonra konan `return` hiç çalışmaz, fonksiyon stack dolana kadar kendini çağırır.
- Özyinelemeli fonksiyonlar tersten tamamlanır
  - En son çağrılan fonksiyon ilk biter. Bir özyinelemeli kodun çıktısı sorulduğunda takip edilemiyorsa stack çizilerek çözülür; bu en temiz yöntemdir.
- Stack overflow
  - Sonsuz özyinelemenin sonucu stack taşmasıdır. İşletim sistemi kaynakları yönettiği için programı sonlandırır.
- Özyineleme her zaman verimli değildir
  - Faktöriyel gibi örnekler kavramı öğretmek içindir. İteratif sürüm stack'i doldurmadığı için daha az maliyetlidir; çok büyük girdilerde özyinelemeli sürüm daha geç biter.
  - Özyinelemenin asıl faydası Merge Sort ve Quick Sort gibi algoritmalarda görülür.
- Fonksiyon çağrısı ile `--N`
  - `N*myFactorial(--N)` ifadesinde `N` azaltıldığı için çarpımdaki `N` de değişir ve sonuç yanlış çıkar. `N-1` göndermek gerekir.
- İyi algoritma tasarlamak için özyinelemeli düşünme olmazsa olmazdır; basit örneklerle pratik yapılmalıdır.

## Kısa Tekrar Notları

- Stack'te her çağrı için yer açılır, dönüş adresi yedeklenir; fonksiyon bitince yer silinir.
- Özyineleme: doğrudan (`f → f`) ya da dolaylı (`f → g → f`).
- Genel yapı: `if (temel durum) return ...;` sonra işlemler ve kendini yeni argümanla çağırma.
- Durma koşulu yoksa stack overflow olur; yerel dizi büyüdükçe daha erken olur.
- $0! = 1$, $n! = n\cdot(n-1)!$; çağrılar ileri, hesap geri yönlü.
- Negatif faktöriyel için ayrı kontrol gerekir.
- Recurrence relation: $f(n)=n\,f(n-1)$, açılınca $n$ adım.
- $x^n = x\cdot x^{n-1}$; $n==1$ temel durumu unutulmamalı; negatif üs `double` gerektirir.
- Dizi toplamı: `dizi[n] + toplam2(dizi, n-1)`; arama: son indisten geriye, `n<0` bulunamadı.
- Merge Sort ve Quick Sort özyinelemelidir ve $n\log n$ sürer.

## Detaylı Açıklamalar

- Ders, önceki dersteki fonksiyon ve bellek konusunun devamı olarak başladı. Programın bellekteki bölgeleri gösterildi ve stack'in fonksiyon çağrılarındaki rolü bir örnekle hatırlatıldı: `main`'in 2. satırında `f1` çağrılınca 2 yedeklenir, `f1`'in 11. satırında `f3` çağrılınca 11 yedeklenir, `f3`'ün 31. satırında `f4` çağrılınca 31 yedeklenir. `f4` biter, `f3` 32. satırdan devam edip biter, `f1` kaldığı yerden devam edip biter ve `main` 3. satırda `f2`'yi çağırır. Bu örnekte bir fonksiyon geldiği yoldan geri döner, çağrı zinciri hiç başa dönmez.
- Özyinelemede çağrı zinciri başa döner. `void f1(){ ... f3(); }` ve `void f3(){ ... f1(); }` dolaylı özyinelemedir; `void f2(){ ... f2(); }` doğrudan özyinelemedir. Durma koşulu olmayan `f2` her çağrıda stack'e yeni bir kayıt ekler (ekranda `main | 100`, `f2 | 180`, `f2 | 180`, ... diye çizildi, ekrandan, 00:15:00). Bellek sınırlı olduğu için program sonlandırılır.
- Derste bunu ölçmek için çağrı sayacı kullanıldı:

```c
#include <stdio.h>
void f2(int x);
int main(){
    int x=1;
    f2(x);
    return 0;
}
void f2(int x){
    int dizi[1000];
    printf("fonksiyon %d. kez cagrildi\n",x);
    f2(++x);
}
```

  (ekrandan, 00:20:00; prototip satırı ders sonrası eklendi). Program hiçbir zaman `return 0`'a ulaşmaz. Dizi olmadan yaklaşık 43 bin çağrı yapılabildi; `dizi[1000]` ve `dizi[100]` ile sayı çok azaldı (100 elemanlı dizide yaklaşık 5 bin civarı söylendi). <!-- BELİRSİZ: 1000 elemanlı dizi ile elde edilen çağrı sayısı altyazıda net değil ("43 bini 51 bine kadar geldi"). -->
- Dolaylı özyinelemede `f2(int x)` içinden `f3(x)`, `f3(int x)` içinden `f2(++x)` çağrıldı (ekrandan, 00:25:00). `f2` içinde çağrıdan sonra yazılan `return;` hiç çalışmadı; çünkü akış hiçbir zaman o satıra ulaşmaz. Çözüm, çağrıdan önce bir koşula bağlı `return` yazmaktır: örneğin `if(x==5) return;` (ya da `x>5`), değilse kendini `x+1` ile çağır.
- Faktöriyel örneğinde temel durum $0!=1$'dir. Doğru kod:

```c
int myFactorial(int N){
    int T;
    if(N==0)
        return 1;
    T = N*myFactorial(N-1);
    return T;
}
```

  (ekrandan, 00:50:00). `T` yalnız izleme kolaylığı için konmuştur, doğrudan `return N*myFactorial(N-1);` da yazılabilir. Bu kod `myFactorial(5)` için 120 verir (gcc ile derlenip çalıştırıldı).
- Derste önce `return N*myFactorial(--N);` yazıldı ve 5! için 24 çıktı (ekrandan, 00:45:00). Hocanın açıklaması: fonksiyon çağrısı çarpmadan önce yapılır ve `--N` aynı fonksiyondaki `N`'yi de azalttığı için çarpımda bir eksik değer kullanılır.
  - Ders sonrası not: C'de `N*f(--N)` ifadesinde `N`'nin okunması ile azaltılmasının sırası standartta belirlenmemiştir (tanımsız davranış); gcc `-Wall` "operation on 'N' may be undefined" uyarısı verir. Kesin çözüm derste de söylendiği gibi `N-1` göndermektir.
- Üs alma örneğinde derste yazılan tam sayı sürümü (ekrandan, 01:10:00):

```c
int powerXtoN(int x, int n){
    if(x==0){
        if(n==0) return -1;
        if(n>1) return 0;
    }
    if(n==1) return x;
    return x*powerXtoN(x,n-1);
}
```

  Bu sürüm $0^0$ için -1, $0^5$ için 0, $5^3$ için 125, $(-5)^4$ için 625, $(-5)^3$ için -125 verir (gcc ile doğrulandı). Negatif üs verilince `n` hiç 1'e ulaşmaz ve sonsuz özyineleme olur.
- Dizi örneklerinde dizinin adresi her çağrıda aynı kalır, yalnız son indis küçülür. `toplam2` toplamı sondan başa doğru çağırır ama stack'ten dönüşte $1+2+3+4+5$ sırasıyla tamamlar. Ara değerleri yazdırmak için `printf`'in özyinelemeli çağrıdan sonra konması gerekir; `return` ifadesinin içindeki çağrıdan sonra işlem yapılamadığı görüldü.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
