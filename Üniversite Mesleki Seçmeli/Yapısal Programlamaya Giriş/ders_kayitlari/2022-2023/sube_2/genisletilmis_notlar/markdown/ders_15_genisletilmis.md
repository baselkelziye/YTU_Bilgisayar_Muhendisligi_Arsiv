# Ders 15 Genişletilmiş Notu: Özyineleme (Recursion): Stack, Temel Durum, Faktöriyel, Üs Alma ve Dizilerde Özyinelemeli Fonksiyonlar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Hatırlatma: bellek düzeni ve fonksiyon çağrılarında stack
- 2. Özyineleme kavramı: doğrudan ve dolaylı özyineleme
- 3. Sonsuz özyineleme ve stack taşması
- 4. Özyinelemeli fonksiyonun genel yapısı: base case ve recursive case
- 5. Faktöriyel örneği ve stack üzerinde izleme
- 6. Yineleme bağıntısı (recurrence relation) ve karmaşıklık
- 7. Üs alma: pozitif, negatif taban ve negatif üs
- 8. Dizilerle özyineleme: toplama ve arama
- 9. Özyinelemenin kullanım alanları
- Örnek Sorular
- Dersin Toparlaması

## 1. Hatırlatma: bellek düzeni ve fonksiyon çağrılarında stack

Ders, önceki dersteki fonksiyonlar konusunun devamı olarak açıldı. Yeni konu olan özyineleme bu bilgilere dayandığı için önce bellek düzeni kısaca hatırlatıldı.

Bir program çalışmak üzere belleğe yüklendiğinde ona ayrılan yer gelişigüzel değildir; belli bölgelere ayrılır (ekrandan, 00:05:00):

- **Instructions:** programın komutları; salt okunur ve çalıştırılabilir.
- **Literals:** sabit değerler; salt okunur.
- **Static Data:** global ve statik değişkenler; program başlarken ilk değerini alır.
- **Dynamic Data (Heap):** programcının yönettiği dinamik veriler. Hocanın belirttiğine göre "$n$ elemanlı bir diziyi, bir `MAX` sabiti tanımlamadan gerçekten nasıl oluştururum?" sorusunun cevabı bu bölgededir; konu ileride işlenecek.
- **Stack:** derleyicinin otomatik yönettiği bölge. Fonksiyon açılınca tanımlanan parametreler, yerel değişkenler, sabit uzunluklu yerel diziler ve işlemcinin durum bilgileri burada tutulur.

Stack'te değişkenler de rastgele değil, tanımlanma sırasıyla yerleştirilir: `main` içinde önce `int a`, sonra `char b`, sonra `float c` tanımlanırsa bunlar bu sırayla peş peşe yazılır.

### 1.1 Çağrı zinciri örneği

Ekrandaki örnekte `main` fonksiyonunun 2. satırında `f1()`, 3. satırında `f2()` çağrılır. `f1` 10. satırda başlar ve 11. satırda `f3()`'ü çağırır; `f2` 20. satırda başlar ve 21. satırda `f3()`'ü çağırır; `f3` 30. satırda başlar ve 31. satırda `f4()`'ü çağırır; `f4` 40. satırda başlar ve hiçbir fonksiyon çağırmaz (ekrandan, 00:05:00).

Akış adım adım şöyledir:

- `main` çalışır, 2. satırda `f1` çağrılır. `f1` stack'e yüklenir ve dönüşte kalınan yerden devam etmek için 2 bilgisi yedeklenir.
- `f1` 11. satırda `f3`'ü çağırır; `f3` stack'e yüklenir, 11 yedeklenir.
- `f3` 31. satırda `f4`'ü çağırır; `f4` yüklenir, 31 yedeklenir.
- `f4` hiçbir fonksiyon çağırmadan biter. `f4`'e ait her şey bellekten silinir.
- `f3` 32. satırdan devam edip biter; onun alanı da temizlenir.
- `f1` 11'den sonraki satırdan devam edip biter; `main` 3. satıra geçer ve bu kez `f2`'yi çağırır. Aynı süreç `f2 → f3 → f4` için tekrarlanır.

Yani stack "bir dolar, bir boşalır". Hoca bunun önemli bir detay olduğunu, bu derste kullanılacağını ve ileride Assembly dilinde (push/pop gibi stack işlemleri), veri yapılarında, algoritma analizinde ve özellikle işletim sistemleri tasarımında tekrar karşılaşılacağını söyledi.

Bu örnekte dikkat edilmesi gereken yapı şudur: oklar hep ileri gider (`f1 → f3 → f4`), en sondaki fonksiyon bir "çıkmaz nokta"dır, ondan sonra geldiğimiz yoldan geri döneriz. Hiçbir çağrı bizi zincirin başına geri götürmez.

## 2. Özyineleme kavramı: doğrudan ve dolaylı özyineleme

Hoca yeni bir tasarım fikri sordu: `f1`'den `f3`'e, `f3`'ten de tekrar `f1`'e gidilirse ne olur, bunun kodu nasıl yazılır? Bir öğrencinin önerisiyle cevap ekrana yazıldı (ekrandan, 00:10:00):

```c
void f1(){
    /* ... */
    f3();
}
void f3(){
    /* ... */
    f1();
}
```

`main`'den `f1` ya da `f3` hangisi çağrılırsa çağrılsın, iki fonksiyon birbirini durmadan çağırır. Buna **özyineleme (recursion)** denir; ders notlarında "özünü yineleyen, kendini yineleyen" diye geçer. İngilizcedeki "recurrence" bir şeyin tekrar etmesi, nüksetmesi anlamındadır (tıpta hastalığın nüksetmesi için de kullanılır).

İki yol vardır:

- **Doğrudan özyineleme:** fonksiyon kendi içinden kendisini çağırır (`f2` içinde `f2()`).
- **Dolaylı özyineleme:** `f`, `g`'yi; `g`, `h`'yi; ... sonunda biri tekrar `f`'yi çağırır (örnekteki `f1 → f3 → f1`).

Şimdiye kadar görülen algoritmalar iteratifti: işler sırayla yapılır, çağrılan fonksiyon tamamlanır ve geri gelinir. Bundan sonra yazılan fonksiyonlar kendini çağırabilecek. Hoca bu yaklaşımın bazı algoritmaları daha hızlı çözmeyi mümkün kıldığını söyledi.

## 3. Sonsuz özyineleme ve stack taşması

### 3.1 Sorun: bellek dolar

Hoca, bellek düzeni ile özyinelemenin birlikte düşünülmesini istedi ve sorunun ne olabileceğini sordu. Bir öğrenci "hafızayı doldurabilir" dedi. Gerçekten de durma koşulu olmayan bir `f2` kendini, o tekrar kendini çağırır; bu teoride sonsuza kadar gider.

Ekranda şu kod ve stack çizildi (ekrandan, 00:15:00): `main` 100. satırda `f2()`'yi çağırır, `f2` 180. satırda tekrar `f2()`'yi çağırır. Stack'te `main | 100`, ardından `f2 | 180`, `f2 | 180`, `f2 | 180`, ... kayıtları birikir.

Teoride sonsuz olan şey pratikte sonsuz değildir; çünkü programın üstünde onu denetleyen bir yazılım, işletim sistemi vardır. İşletim sisteminin görevlerinden biri kaynakları yönetmek ve koordine etmektir. Programa ayrılan stack bölgesi dolunca işletim sistemi "bütün belleği mahvedeceksin" diyerek programı sonlandırır. Bu sınır bilgisayarın RAM'ine ve işletim sisteminin programa ayırdığı yere göre değişir.

### 3.2 Kaç kez çağrılabiliyor?

Derste bunu görmek için fonksiyona bir sayaç parametresi eklendi:

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

(ekrandan, 00:20:00; ekrandaki kodda prototip yoktu ve Dev-C++ "conflicting types for 'f2'" uyarısı verdi; prototip satırı ders sonrası eklendi.) Program hiçbir zaman `return 0` satırına ulaşmaz, normal bitmez; işletim sistemi tarafından durdurulur.

- Yerel dizi yokken bu bilgisayarda yaklaşık 43.178 çağrı yapılabildi. Hoca daha az RAM'li bilgisayarda bu sayının daha küçük olacağını söyledi.
- Bir öğrenci, işletim sisteminin daha erken durdurması için yerel değişken tanımlanabileceğini önerdi. Fonksiyona `int dizi[1000];` eklendi: artık her çağrı stack'te 1000 elemanlık bir dizi için de yer açar, bu yüzden çağrı sayısı çok azalır. <!-- BELİRSİZ: 1000 elemanlı dizi ile elde edilen çağrı sayısı altyazıda net değil ("43 bini 51 bine kadar geldi"). -->
- Dizi `int dizi[100];` yapılınca yaklaşık 5000 civarı çağrı beklendiği söylendi. Hoca bunun kesin bir sayı olmadığını, işletim sisteminin ne zaman uyarı vereceğine bağlı olduğunu belirtti.

> **Ek bilgi (derste anlatılmadı):** Güncel gcc `-Wall` ile bu kodda "infinite recursion detected" uyarısı verir. Ayrıca optimizasyon açıkken derleyici kullanılmayan diziyi kaldırabilir ve çağrı sayısı değişebilir.

### 3.3 Döngü içinde çağırmak ile özyineleme farkı

Hoca karşılaştırma için şu sözde kodu yazdı (ekrandan, 00:35:00'da açıklama satırı olarak görünüyor):

```c
for(x=1; x<INF; x++)
    f1();
```

Burada `f1` içinde yalnız bir dizi tanımlansa bile `f1`'i sonsuz kez çağırmanın hiçbir etkisi olmaz: `f1` gider, işini yapar, biter, geri gelir; stack bir dolar bir boşalır. Özyinelemede ise önceki çağrılar bitmeden yenileri eklendiği için stack sürekli büyür. Fark budur.

### 3.4 Dolaylı özyinelemenin denenmesi

Dolaylı özyineleme de kodlandı (ekrandan, 00:25:00):

```c
void f2(int x){
    int dizi[100];
    printf("fonksiyon %d. kez cagrildi\n",x);
    f3(x);
    return;
}
void f3(int x){
    f2(++x);
}
```

Bu sürüm de yaklaşık 5000 civarında durdu ama biraz daha az çağrı yapılabildi. Hocanın açıklaması: her döngüde stack'e fazladan `f3`'ün kaydı da basıldığı için yer daha çabuk dolar.

## 4. Özyinelemeli fonksiyonun genel yapısı: base case ve recursive case

### 4.1 `break`, `continue` ve `return`

Hoca sonsuza gitmemesi için ne yapılması gerektiğini sordu. Bir öğrenci `break` ya da `continue` önerdi. Cevap: `break` döngülerden çıkmak, `continue` döngünün o adımını atlamak içindir; fonksiyondan çıkmak için işe yaramazlar. Fonksiyondan çıkmak için `return` kullanılır. `return` hem değer döndürmek hem de yalnız çıkmak için kullanılabilir: `void` bir fonksiyonda boş `return;` hatasızdır, ama `return 5;` yazılırsa derleyici hata verir.

### 4.2 `return` yanlış yerde

Yukarıdaki `f2` içine `f3(x);` satırından sonra `return;` yazıldı (ekrandan, 00:25:00). Bu hiçbir işe yaramadı: `f2`, `f3`'e gider; `f3`, `f2`'yi çağırır; akış hiçbir zaman `return` satırına düşmez. Bir öğrenci, `return`'ün çağrıdan önce bir koşulla yazılması gerektiğini söyledi. Hoca bunu onayladı: örneğin özyineleme en fazla 5 kez olsun istenirse önce `if (x == 5) return;` kontrolü yapılır, değilse fonksiyon `x` bir artırılarak tekrar çağrılır. Hoca bu biçimde bir eksik çağrı olacağını, `x > 5` gibi bir koşulla 6. seferde çıkılabileceğini de belirtti.

### 4.3 Genel şablon

Hoca bunu genel bir şablonla özetledi (ekrandan, 00:30:00):

```text
void funcName(params){
    (1) if( ... kontroller ... ){
            ... bir seyler yap ...
            return;
        }                              -> Base case
    (2) ... gerekli islemler ...
        funcName(args);                -> Recursive case
}
```

- Dönüş tipi `void` olmak zorunda değildir; `int` gibi bir tipse base case'te örneğin `return x;` yazılır.
- Önce **base case** (temel durum) yazılır. Genellikle bir `if` içerir ve mutlaka `return` ile biter.
- Base case'e girilmediyse **recursive case** çalışır: gerekli işlemler yapılır (arada `for` döngüsü vb. olabilir) ve fonksiyon tekrar çağrılır.
- Fonksiyonda tanımlanan değerler **parametre**, çağrıda gönderilenler **argüman**dır. Üç parametre tanımlandıysa çağrıda üç argüman gönderilir; bu, normal fonksiyon çağrısıyla aynıdır.

> **Hocanın vurgusu:** Sıra ters yazılırsa, yani önce recursive case sonra base case yazılırsa, fonksiyon sonsuz kez çalışır. Birinci adımda mutlaka base case yazılmalıdır.

Derste bu şablonla fonksiyonun `n` kez (örnekte 6 kez) çağrılması sağlandı: fonksiyon bir `n` değeri alır, sayaç `n`'i geçince `return` eder, aksi halde `n`'i değiştirmeden sayacı artırarak kendini çağırır.

```c
#include <stdio.h>
void f2(int x){
    if(x>5) return;
    printf("fonksiyon %d. kez cagrildi\n",x);
    f2(x+1);
}
int main(){ f2(1); return 0; }
```

> **Ek bilgi (derste anlatılmadı):** Yukarıdaki küçük kod, derste anlatılan "koşul önce, çağrı sonra" fikrinin çalışan bir biçimidir; ajan tarafından yazıldı, gcc ile derlenip çalıştırıldı ve 1'den 5'e kadar beş satır yazdırdı.

Hoca ayrıca özyinelemeyi slaytlarla anlatan bir üniversite dersinin (Stanford CS106B) sayfasını gösterdi; orada C++ kullanılsa da örneklerin (Hanoi kuleleri vb.) mantığının önemli olduğunu, bu konunun gelecek dönemki veri yapıları ve algoritma derslerinde de tekrar karşılaşılacağını söyledi.

> **Hocanın vurgusu:** İyi algoritma tasarlamak için özyinelemeli düşünme olmazsa olmazdır; bu kapsamlı bir konudur.

## 5. Faktöriyel örneği ve stack üzerinde izleme

### 5.1 Temel durum

En bilinen örnek faktöriyeldir. Hoca en küçük faktöriyelin hangisi olduğunu sordu: $1!$ mi, $0!$ mı? Bir öğrenci ikisinin sonucunun aynı olduğunu söyledi. Hoca sonucun aynı olduğunu ama en temel durumun $0! = 1$ olduğunu belirtti. Özyineleme ise $n! = n \cdot (n-1)!$ bağıntısından gelir.

### 5.2 Özyinelemeli fonksiyonlar tersten tamamlanır

Hoca bütün özyinelemeli fonksiyonların "tersten çalıştığını" vurguladı: `f` kendini çağırır, o tekrar çağırır, bir daha çağırır. Sonra `return` edilirken en son çağrılan fonksiyon ilk tamamlanır, sonra ondan öncekisi, sonra ondan öncekisi. Bunun nedeni stack yapısıdır.

> **Hocanın vurgusu:** For döngülü (iteratif) bir algoritmayı izlemek kolaydır, özyinelemeli algoritmayı izlemek ve debug etmek zordur; çünkü fonksiyon kendi içinden kendini çağırır ve sanki yeniden başlıyormuş gibi olur. Size bir kod verilip çıktısı sorulduğunda takip edemiyorsanız stack çizin; en temiz çözüm budur.

### 5.3 `myFactorial(4)` izlemesi

Slayttaki kod (ekrandan, 00:40:00):

```c
int myFactorial(int N){
    if (N==0)
        return 1;
    return N*myFactorial(--N);
}
```

ve çağrı `x = myFactorial(4);`. Stack üzerinde izleme:

- `main`, `myF(4)`'ü çağırır. $4 \neq 0$, bu yüzden `4 * (bir şey)` hesaplanacak; ama önce `myF(3)` çağrılır. `myF(4)` henüz tamamlanmamıştır.
- `myF(3)`: `3 * myF(2)`; önce `myF(2)` çağrılır.
- `myF(2)`: `2 * myF(1)`; önce `myF(1)` çağrılır.
- `myF(1)`: `1 * myF(0)`; önce `myF(0)` çağrılır.
- `myF(0)`: temel durum, `return 1`.
- Dönen 1, onu çağıran `myF(1)`'deki boşluğa yazılır: $1 \cdot 1 = 1$ döner.
- `myF(2)`: $2 \cdot 1 = 2$ döner. `myF(3)`: $3 \cdot 2 = 6$ döner. `myF(4)`: $4 \cdot 6 = 24$ döner ve `main`'deki `x` değişkenine 24 yazılır.

Kitaplarda bu genelde tek satırlık açılımla gösterilir. Ekranda `myF(3) → 3*myF(2) → 2*myF(1) → 1*myF(0)` zinciri ve dönüş yönünde $1 \to 1 \to 2 \to 6$ yazıldı (ekrandan, 00:40:00).

> **Hocanın vurgusu:** Çağırmalar ileri yönlü, hesaplamaların tamamlanması geri yönlüdür. Çağırırken stack'e **push** yapılır; dönerken her `return` değeri bir üstteki bölgeye kopyalanır, alt bölge yok edilir; bu da **pop** işlemidir.

### 5.4 `--N` hatası ve düzeltilmesi

Kod Dev-C++'ta `printf("%d! = %d\n", 5, myFactorial(5));` ile çalıştırıldığında sorunlar çıktı. Sınıfla birlikte şunlar denendi:

- Bir öğrenci temel durumu `N==1` yapmayı önerdi; çünkü `N` sıfıra düştüğünde çarpımın sıfır olacağını düşündü. `if(N==1) return 1;` ile 5! için 24 çıktı; beklenen 120'ydi (ekrandan, 00:45:00).
- Debugger ile `N` değeri izlendi; zincirin 5'ten değil 4'ten başlıyor gibi çarptığı görüldü.
- Bir öğrenci `--N` yerine `N-1` yazmayı önerdi. Hoca bunu "daha mantıklı" buldu: `N` azaltılınca bu fonksiyondaki `N` de azalır; `N-1` gönderilirse sorun çözülür.

Hocanın açıklaması: fonksiyon çağrısı çarpmadan önce yapılır. `myF(3)`'te `3 * myF(--N)` hesaplanırken önce çağrı yapılır ve `N` 2'ye iner; çarpımda artık 3 değil 2 kullanılır. Böylece her adımda bir eksik çarpılır.

Düzeltilmiş ve izleme için geçici `T` değişkeni eklenmiş kod (ekrandan, 00:50:00):

```c
int myFactorial(int N){
    int T;
    if(N==0)
        return 1;
    T = N*myFactorial(N-1);
    return T;
}
```

`myF(3)` için stack yeniden çizildi: `myF(3)` içinde `T = 3 * myF(2)`, `myF(2)` içinde `T = 2 * myF(1)`, `myF(1)` içinde `1 * myF(0)`; `myF(0)` 1 döndürür ve sonuç geriye doğru $1, 2, 6$ olur (ekrandan, 00:50:00). `T` yalnız izleme amaçlıdır; `return N*myFactorial(N-1);` da aynı sonucu verir.

> **Ders sonrası not:** C'de `N*myFactorial(--N)` ifadesinde `N`'nin çarpım için okunması ile `--N` ile değiştirilmesi arasında bir sıra garantisi yoktur; bu tanımsız davranıştır. gcc `-Wall` "operation on 'N' may be undefined" uyarısı verir. Derste görülen 24 sonucu bu derleyicinin seçtiği sıradan gelir. Doğru ve güvenli yazım `N-1`'dir. Ajan testinde `N==1` temel durumlu `--N` sürümü gcc'de de 24, `N-1` sürümü 120 verdi.

### 5.5 Negatif argüman

Ekrandaki ders notunda (PDF) "`M=fakto(-3)` dersek M ne olur?" sorusu vardı (ekrandan, 01:05:00). Bir öğrenci "sonsuza kadar gider" dedi: $-3$ temel duruma hiç ulaşmaz; çarpmadan önce $-4$'ü, o $-5$'i çağırır ve stack taşar. Derste program gerçekten çöktü. Basit çözüm, gelen sayı sıfırdan küçükse doğrudan `return -1;` yapmaktır (negatif sayının faktöriyeli tanımlı değildir; $-1$ "tanımsız" işareti olarak kullanılır).

Aynı PDF'te faktöriyelin açılımı da tablo olarak vardı (ekrandan, 01:05:00):

```text
fakto(5)=5*fakto(4)
fakto(5)=5*4*fakto(3)
fakto(5)=5*4*3*fakto(2)
fakto(5)=5*4*3*2*fakto(1)
fakto(5)=5*4*3*2*1
fakto(5)=5*4*3*2
fakto(5)=5*4*6
fakto(5)=5*24
fakto(5)=120
```

PDF'teki kurallar: özyinelemeli bir fonksiyonun her zaman stack overflow'a sebep olmaması için $f(n)$, $f(n)$'i çağırmamalı ve $f(n)$'de $f$'in çağrılmadığı bir bölüm (temel durum) olmalıdır. Bu iki şarta sahip olsa da yine stack overflow olabilir. Hoca, sonsuz çağrıda görülen hatanın adının **stack overflow** olduğunu, aynı adlı meşhur sitenin adının da buradan geldiğini söyledi.

## 6. Yineleme bağıntısı (recurrence relation) ve karmaşıklık

Önceki derslerde iteratif algoritmalar analiz edilmişti. Özyinelemeli algoritmalar da analiz edilecektir; bunun için **recurrence relation** (yineleme bağıntısı) kullanılır. Bağıntı fonksiyona benzeyen ama daha basit bir yapıdır. Faktöriyel için:

$$f(0) = 1, \qquad f(n) = n \cdot f(n-1)$$

$n$ yerine $n-1$ konarak açılır:

$$f(n) = n \cdot f(n-1) = n\,(n-1)\,f(n-2) = n\,(n-1)\,(n-2)\,f(n-3) = \dots$$

$k$ adım sonra:

$$f(n) = f(n-k)\cdot(n-k+1)\cdot(n-k+2)\cdots(n-1)\cdot n$$

Temel durumu bildiğimiz yer $n-k = 0$, yani $k=n$'dir. O zaman $f(n-k)=f(0)=1$ ve

$$f(n) = 1 \cdot 1 \cdot 2 \cdots (n-1) \cdot n$$

olur. Sonuç: algoritma $n$ kez döner. For döngüsüyle hesaplanan faktöriyel de $n$ adım sürer; özyinelemeli sürüm yalnız farklı biçimde yazılmıştır. Hoca bu örneğin özyinelemeyi öğrenmek için en basit örneklerden biri olduğunu, asıl işe yarayan örneklerin ileride geleceğini söyledi.

### 6.1 Özyinelemeli ve iteratif faktöriyel karşılaştırması

Hoca iki kodu yan yana koyup hangisinin daha az maliyetli olduğunu sordu. Bir öğrenci iteratif sürümün bellekten tasarruf ettiğini, özyinelemeli sürümün fonksiyonu çağıra çağıra stack'i doldurduğunu söyledi. Hoca onayladı: iteratif kodda fonksiyon bir kez çağrılır, içeride `for` döner; özyinelemeli kodda ise $n$ için iç içe $n$ çağrı yapılır.

> **Hocanın vurgusu:** Adım sayısı olarak fark yoktur ama özyineleme burada bir şey kazandırmaz, hatta kaybettirir. Çok büyük bir faktöriyel için süre ölçülürse özyinelemeli sürümün biraz daha geç bittiği görülür. Özyinelemenin asıl faydalı olduğu yerler sıralama algoritmalarıdır: Bubble Sort gibi $n^2$'lik algoritmalar $n \log n$'e indirilebilir ve bu $n \log n$'lik algoritmalardan Merge Sort ile Quick Sort özyinelemeyi kullanır.

## 7. Üs alma: pozitif, negatif taban ve negatif üs

### 7.1 Temel durumlar

İkinci örnek $x^n$'i hesaplayan `powerXtoN(x, n)` fonksiyonudur. Hoca temel durumu sordu; bir öğrenci "$x^0$, yani 1" dedi. Hoca önce $x=0$ durumunu ayrıca ele aldı:

- $x = 0$ ve $n = 0$: $0^0$ tanımsız kabul edildi; anlamsız bir değer olarak `-1` döndürülür.
- $x = 0$ ve $n$ pozitif: sonuç `0`.

Sonra $x \neq 0$ için: $x^n = x \cdot x^{n-1}$, $x^{n-1} = x \cdot x^{n-2}$, ... bu $n$ 1 olana kadar gider. Hoca burada eksik bir temel durum olduğunu sordu: **`n == 1` ise `x` döndürülmelidir**. Aksi halde zincir durmaz.

Ekrandaki kod (ekrandan, 01:10:00):

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

Test için `main` (ekrandan, 01:00:00):

```c
printf("%d! = %d\n",5,myFactorial(5));
printf("%d^%d=%d\n",0,0,powerXtoN(0,0));
printf("%d^%d=%d\n",0,5,powerXtoN(0,5));
printf("%d^%d=%d\n",5,3,powerXtoN(5,3));
```

Çıktılar: $5! = 120$, $0^0 = -1$, $0^5 = 0$, $5^3 = 125$. Zincir $x \cdot x \cdot \dots \cdot x$ biçiminde $n$ çarpana açılır ve yine $n$ adım sürer.

> **Ders sonrası not:** Ekrandaki koşul `if(n>1) return 0;` olduğu için $0^1$ durumu bu satıra değil `n==1` satırına düşer ve yine 0 döner; sonuç doğrudur. Ancak `powerXtoN(5,0)` gibi $x\neq0$, $n=0$ çağrısında hiçbir temel durum çalışmaz ve sonsuz özyineleme olur; bu sürüm $n \ge 1$ için yazılmıştır.

### 7.2 Daha hızlı yol: $x^{n/2}$

Hoca ilk derslerde kuvvet almanın daha kısa yoldan yapılabileceğini hatırlattı: $x^n$'i bulmak için $x^{n/2}$ bir kez hesaplanıp saklanır ve kendisiyle çarpılır. Böylece $n$ çağrıya gerek kalmaz. Hoca bu tekniği (hesaplanan sonucu saklayıp yeniden kullanma) "memoization" diye andı ve bu "recursive power" konusuna ayrıca dönüleceğini söyledi.

> **Ek bilgi (derste anlatılmadı):** $x^n = (x^{n/2})^2$ (çift $n$), $x^n = x\cdot(x^{\lfloor n/2\rfloor})^2$ (tek $n$) bağıntısıyla çağrı sayısı yaklaşık $\log_2 n$'e iner. Bu yönteme genellikle "hızlı üs alma" ya da "kare alarak üs alma" denir; "memoization" terimi ise çoğunlukla daha önce hesaplanmış alt problemlerin bir tabloda saklanması için kullanılır.

### 7.3 Negatif taban

Hoca $(-5)^4$ ve $(-5)^3$ için sonucun doğru çıkıp çıkmayacağını sordu. Bir öğrenci üssün tek ya da çift olmasına göre değişeceğini söyledi. Çalıştırınca $(-5)^4 = 625$ ve $(-5)^3 = -125$ çıktı. Ek kural gerekmez: tek sayıda çarpılırsa sonuç negatif, çift sayıda çarpılırsa pozitif olur.

### 7.4 Negatif üs

$5^{-3}$ için kod nasıl çalışır? Bir öğrenci sonsuz döngüye gireceğini söyledi. İzleme: $x \neq 0$, $n = -3 \neq 1$; `n-1` ile $-4$, o $-5$'i çağırır; $n$ hiç 1'e ulaşmaz, sonsuz özyineleme olur.

Çözüm olarak bir öğrenci $n$ negatifse tersiyle çarpmayı önerdi: $x^n = \frac{1}{x}\cdot x^{n+1}$. Bu kez `n-1` değil `n+1` gönderilir. Ekrandaki deneme (ekrandan, 01:15:00):

```c
if(n==1) return x;
if(n>1)  return x*powerXtoN(x,n-1);
if(n<1)  return 1.0/x*powerXtoN(x,n+1);
```

Bir öğrenci fonksiyonun `int` döndürmesinin sonucu etkileyip etkilemeyeceğini sordu. Hoca, sonucun ondalıklı olduğunu, bu yüzden dönüş tipinin `double` ya da `float` olması gerektiğini söyledi; `math` kütüphanesindeki `pow` fonksiyonunun da `double` tanımlandığını belirtti. Ayrıca `%d` ile `double` yazdırılamayacağı, prototip yazılmadığı için derleyicinin "conflicting types" uyarısı verdiği görüldü.

İşlem önceliği sorusu da geldi: `1.0/x*powerXtoN(...)` önce bölmeyi mi yapar? Hoca çarpma ve bölmenin aynı öncelikte olduğunu, soldan sağa (sol birleşimli) yapıldığını söyledi: önce `1.0/x`, sonra çarpma.

Derste daha sonra kod daha okunaklı olacak biçimde yeniden düzenlendi (ekrandan, 01:20:00):

```c
if(x==0 && n==0) return -1;
if(x==0 && n>0)  return 0;
if(n==1) return x;
if(n>1)  return x*powerXtoN(x,n-1);
if(n<1)  return 1/x*powerXtoN(1/x,n+1);
```

Hoca `return` satırlarından sonra `else` yazmaya gerek olmadığını da belirtti: bir `return`'e girilirse fonksiyondan çıkılır, girilmezse sonraki satıra geçilir. Son satırda bir öğrencinin önerisiyle ikinci argüman olarak `1/x` gönderilmesi denendi; ama $2^{-3}$ için beklenen $0.125$ yerine yanlış değerler çıktı. Hoca farklı çözümler üretilebileceğini, bu tür fonksiyonların genellikle alt fonksiyonlara bölündüğünü ve konuya ayrıca bakılacağını söyledi; negatif üs kısmı derste tam çalışır hale getirilmedi.

> **Çözüm (derste verilmedi):** `1/x` hem çarpan olarak kullanılıp hem de argüman olarak gönderilirse her adımda iki kez bölünmüş olur; ayrıca `int` dönüş tipi ve `int` parametre ondalık kısmı keser. Aşağıdaki sürüm `double` dönüş tipiyle ve `x`'i değiştirmeden `n+1` göndererek çalışır; ajan tarafından gcc ile derlenip test edildi: $2^{-3} = 0.125$, $5^{-3} = 0.008$, $5^0 = 1$, $5^3=125$.

```c
#include <stdio.h>
double powerXtoN(double x, int n){
    if(x==0 && n==0) return -1;   /* 0^0 tanimsiz */
    if(x==0 && n>0)  return 0;
    if(n==0) return 1;
    if(n>0)  return x*powerXtoN(x,n-1);
    return 1.0/x*powerXtoN(x,n+1); /* n<0 */
}
int main(){
    printf("%f %f %f %f\n", powerXtoN(2,-3), powerXtoN(5,-3),
           powerXtoN(5,0), powerXtoN(5,3));
    return 0;
}
```

## 8. Dizilerle özyineleme: toplama ve arama

Hoca bu tür örneklerin özyinelemenin mantığını oturtmak için basit de olsa çok faydalı olduğunu ve bunlara çalışılması gerektiğini söyledi.

### 8.1 İki sayıyı dolaylı yoldan toplamak

Ekrandaki kod (ekrandan, 01:30:00):

```c
int toplam1(int a, int b){
    if(b==0) return a;
    else toplam1(a+1,b-1);
}
```

ve çağrı `printf("%d", toplam1(2,6));`. Soru: bu fonksiyon ne işe yarar, sonuç ne olur? Bir öğrenci sonucun 2 ile 6'nın toplamı, yani 8 olacağını söyledi. İzleme: `toplam1(2,6)` → `toplam1(3,5)` → `toplam1(4,4)` → ... → `toplam1(8,0)`; `b` sıfıra düştüğünde iki sayının toplamı `a`'da birikmiş olur. İki sayı uzak bir yoldan toplanmış olur.

> **Ders sonrası not:** Ekrandaki `else` dalında `return` yok. `int` döndüren bir fonksiyonun değer döndürmeden bitmesi tanımsız davranıştır; derste 8 çıkması derleyicinin o anki davranışına bağlıdır. Doğrusu `else return toplam1(a+1,b-1);` biçimindedir; bu biçim gcc ile test edildi ve 8 verdi.

### 8.2 Dizi elemanlarının toplamı

`toplam2` fonksiyonuna dizi ve son elemanın indisi gönderilir. `main`'de `int dizi[5]={1,2,3,4,5};` tanımlandı (ekrandan, 01:30:00). Hoca önce dizinin eleman sayısını (5) göndermeyi düşündü, sonra son elemanın indisi olan 4'ü göndermeye karar verdi. Altyazıdaki anlatıma göre kod şöyledir:

```c
int toplam2(int dizi[], int n){
    if(n==0) return dizi[0];
    return dizi[n] + toplam2(dizi, n-1);
}
```

<!-- BELİRSİZ: toplam2'nin kodu karede görünmüyor; anlatımdan kuruldu ("n eşittir 0 ise dizinin n'inci elemanını döndür, değilse dizinin n'inci elemanı artı ..."). -->

Bir öğrenci fonksiyonun dizideki elemanların toplamını bulduğunu söyledi. İzleme: dizi her çağrıda aynı adresle (ilk elemanın adresi) gider, yalnız indis küçülür. `toplam2(dizi,4)` → `toplam2(dizi,3)` → ... → `toplam2(dizi,0)`; `dizi[0]=1` döner, sonra 2, 3, 4, 5 eklenir. Çağrılar sondan başa gitse de stack'ten dönüş sırasında toplama baştan sona doğru yapılır: $1+2+3+4+5 = 15$ (gcc ile doğrulandı).

Ara toplamları ekrana yazdırma denemesinde `printf`'in nereye konacağı soruldu. Hoca, işlem önceliğine göre toplamadan önce özyinelemeli çağrının yapılacağını, `printf` çağrıdan önce yazılırsa elemanların sondan başa doğru yazılacağını söyledi ve `printf`'i sona aldı. Ancak `return` satırından sonra konan `printf` hiç çalışmadı; bir öğrencinin de belirttiği gibi fonksiyon `return` ile hemen çıkar. Hoca bunun için ayrıca bir koşul yapısı kurulabileceğini söyleyip örneği bu haliyle bıraktı.

### 8.3 Dizide eleman arama

Son örnekte dizide bir eleman aranıp indisi bulundu (ekrandan, 01:40:00):

```c
int ara(int dizi[], int n, int key){
    if (n<0) return -1;
    if (dizi[n]==key) return n;
    return ara(dizi,n-1,key);
}
```

- İndis son elemandan başlayıp sıfıra doğru azalır. Sıfırın altına düşmüşse eleman bulunamamıştır: `-1` (not found).
- `dizi[n]` aranan elemana eşitse `n` döndürülür.
- Değilse dizi, bir azaltılmış `n` ve aynı `key` ile tekrar çağrılır.

`{1,2,3,4,5}` dizisinde 3 arandığında indis 2, -3 arandığında -1 döndü (gcc ile doğrulandı). Fonksiyon ya ilk ya da ikinci `return`'den döner.

## 9. Özyinelemenin kullanım alanları

Hoca dersin sonunda özyinelemenin kullanıldığı yerlerden örnekler gösterdi:

- **Fraktallar:** bir kök çizip ona dallar eklemek; bir çokgenin köşelerine yeni çokgenler, beşgenin her ucuna yeni beşgen, üçgenin içine üçgen, karenin içine dört kare ve onların içine dört kare çizmek. Özyinelemeli bir algoritmayla üretilmiş düzgün bir ağaç görseli de gösterildi.
- **Palindrom kontrolü:** bir kelimenin tersten de aynı okunup okunmadığı özyinelemeyle kontrol edilebilir.
- **Merge Sort ve Quick Sort:** bir web sayfasında Merge Sort'un adım adım animasyonu gösterildi: dizi ikiye bölünür, önce 0-3 aralığı için, sonra 0-1, sonra 0-0 için çağrı yapılır; 0-0 tamamlanınca bir önceki çağrıya dönülür ve sonraki satıra geçilir. Hoca Merge Sort'ta özyinelemeli fonksiyonun bir fonksiyon içinde iki kez çağrıldığına dikkat çekti.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:08:51): `f1` içinden `f3`, `f3` içinden de `f1` çağrılacaksa kod nasıl yazılır?

> **Cevap (derste verildi):** `void f1(){ ... f3(); }` ve `void f3(){ ... f1(); }`. Bu dolaylı özyinelemedir; `main`'den hangisi çağrılırsa çağrılsın iki fonksiyon birbirini durmadan çağırır (ekrandan, 00:10:00).

**Soru 2** (derste sözlü, 00:12:52): Programın bellek yapısı ile özyineleme birlikte düşünülünce ne gibi bir sorun çıkabilir?

> **Cevap (derste verildi):** Durma koşulu yoksa her çağrı stack'e yeni kayıt ekler ve bellek dolar. İşletim sistemi programı sonlandırır (stack overflow).

**Soru 3** (derste sözlü, 00:19:29): Sonsuz özyinelemeli `f2`'nin işletim sistemi tarafından daha erken durdurulması için ne yapılabilir?

> **Cevap (derste verildi):** Fonksiyona yerel değişken, örneğin `int dizi[1000];` gibi bir yerel dizi eklenir. Her çağrı stack'te daha çok yer kaplar ve stack daha az çağrıda dolar.

**Soru 4** (derste sözlü, 00:25:04): `f2` içinde `f3(x);` satırından sonra yazılan `return;` neden sonsuz çağrıyı durdurmaz?

> **Cevap (derste verildi):** Akış hiçbir zaman o satıra ulaşmaz; `f3` hemen tekrar `f2`'yi çağırır. `return` çağrıdan önce bir koşula bağlanmalıdır (base case).

**Soru 5** (derste sözlü, 00:32:21): Faktöriyelde temel durum $1!$ mi, $0!$ mı?

> **Cevap (derste verildi):** İkisinin değeri 1'dir ama en temel durum $0! = 1$'dir.

**Soru 6** (ekrandan, 01:05:00): `M=fakto(-3)` dersek M ne olur?

> **Cevap (derste verildi):** $-3$ temel duruma hiç ulaşmaz; $-4$, $-5$, ... çağrılır ve program stack overflow ile çöker. Çözüm: `if(N<0) return -1;`.

**Soru 7** (derste sözlü, 01:05:37): Özyinelemeli ve iteratif faktöriyelden hangisi daha az maliyetlidir, neden?

> **Cevap (derste verildi):** Adım sayısı ikisinde de $n$'dir; ama iteratif sürüm daha az maliyetlidir. Fonksiyon bir kez çağrılır, stack'i doldurmaz. Özyinelemeli sürüm $n$ iç içe çağrı yapar.

**Soru 8** (derste sözlü, 01:07:32): `powerXtoN` ile $(-5)^4$ ve $(-5)^3$ doğru hesaplanır mı?

> **Cevap (derste verildi):** Evet: $625$ ve $-125$. Tek sayıda çarpımda sonuç negatif, çift sayıda pozitif olur; ek kural gerekmez.

**Soru 9** (derste sözlü, 01:08:53): $5^{-3}$ için `powerXtoN` nasıl çalışır?

> **Cevap (derste verildi):** `n` $-3$'ten $-4$, $-5$, ... diye azalır ve hiç 1'e ulaşmaz; sonsuz özyineleme olur. Çözüm: negatif üste `1.0/x * powerXtoN(x, n+1)` ve `double` dönüş tipi. Çalışan sürüm 7.4'teki "derste verilmedi" bloğundadır.

**Soru 10** (ekrandan, 01:30:00): `toplam1(2,6)` ne döndürür, fonksiyon ne işe yarar?

> **Cevap (derste verildi):** 8. `b` sıfıra inene kadar `a` birer artar; iki sayı toplanır.

**Soru 11** (derste sözlü, 01:31:08): `toplam2(dizi,4)` ne yapar? (`dizi = {1,2,3,4,5}`)

> **Cevap (derste verildi):** Dizinin elemanlarını toplar; sonuç 15.

## Dersin Toparlaması

Bu derste özyineleme, fonksiyon çağrılarında stack'in nasıl dolup boşaldığı üzerinden kuruldu. Bir fonksiyonun kendini doğrudan ya da dolaylı olarak çağırabileceği, durma koşulu olmazsa stack'in dolup programın işletim sistemi tarafından sonlandırılacağı deneylerle gösterildi. Her özyinelemeli fonksiyonun önce bir base case, sonra bir recursive case içermesi gerektiği şablonla verildi. Faktöriyel örneğinde çağrıların ileri, hesaplamanın geri yönlü tamamlandığı stack çizimiyle izlendi; `--N` yazımının neden yanlış sonuç verdiği, negatif argümanların nasıl sonsuz özyinelemeye yol açtığı ve yineleme bağıntısıyla algoritmanın $n$ adım sürdüğü görüldü.

Üs alma örneğinde ek temel durumların (`n==1`, $0^0$, $0^n$) önemi ve negatif üs için `double` dönüş tipinin gerekliliği tartışıldı; dizi toplamı ve dizide arama örnekleri özyinelemenin dizilerle nasıl kullanıldığını gösterdi. Hoca özyinelemenin faktöriyel gibi örneklerde verimlilik kazandırmadığını, asıl faydasının $n \log n$ süren Merge Sort ve Quick Sort gibi algoritmalarda görüleceğini, $x^{n/2}$ ile hızlı üs almaya da ayrıca dönüleceğini belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
