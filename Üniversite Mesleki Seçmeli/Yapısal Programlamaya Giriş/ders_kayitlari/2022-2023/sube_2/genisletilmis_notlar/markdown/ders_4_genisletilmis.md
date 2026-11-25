# Ders 4 Genişletilmiş Notu: Ödünleşim, Seri Yaklaşımları ve C ile Algoritma Uygulamaları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Ödünleşim ve karmaşıklık aileleri
- 2. Soru 1: Faktöriyel hesabı ve Stirling yaklaşımı
- 3. Soru 2: Pi sayısı için seri yaklaşımı
- 4. C'de operatör önceliği ve birleşme yönü
- 5. Pi kodunun çalıştırılması, hata ayıklama ve süre ölçümü
- 6. Soru 3: e üzeri x için Taylor serisi
- 7. Soru 4: Fibonacci sayıları
- 8. Soru 5: Armstrong sayıları
- 9. Önermeler mantığı ve karşı örnek yöntemi
- Örnek Sorular
- Dersin Toparlaması

## 1. Ödünleşim ve karmaşıklık aileleri

Ders, önceki derste tanıtılan **ödünleşim (trade-off)** kavramının tekrarıyla başladı. Ödünleşim, bir şeyden kazanırken başka bir şeyden kaybetmektir. Algoritma tasarımında tartılan üç ölçüt vardır: **zaman (time)**, **bellek (memory)** ve **doğruluk (accuracy)** (ekrandan, 00:05:00). Örneğin bir denklemi hızlı çözmek isteyebiliriz, ama hızlı çözüm gerçek sonuçtan uzaklaşabilir; ya da bellek önemliyse zamandan feda edebiliriz. Hoca, bu kavrama dönem boyunca sık sık geri döneceklerini söyledi.

Örnek olarak Gauss formülü hatırlatıldı:

$$1 + 2 + \dots + N = \frac{N(N+1)}{2}$$

Bu formül bir `for` döngüsü yerine bir çarpma, bir toplama, bir bölme ve bir atama gibi birkaç tekil işlemle sonucu verir. Bu birkaç işlem sabit sayıda olduğu için karmaşıklığı $1$ kabul edilir. Gauss formülü hem zamandan hem bellekten kazandırır, doğruluktan da bir şey kaybettirmez; bu yüzden iyi bir çözümdür.

Ardından **algoritma aileleri** sıralandı (ekrandan, 00:15:00):

- Sabit: $1$
- Logaritmik: $\log N$
- Doğrusal: $N$ (2N ya da 5N de bu ailedendir)
- $N \log N$
- Polinom: $N^2$, $N^3$, $N^4$, ... Hoca bunlara "P tipi" diyebileceğimizi, ama bu adın aslında problemleri sınıflandırırken kullanıldığını belirtti.
- Üstel: $2^N$, $3^N$, ..., $N!$, $N^N$. Daha büyük ifadeler de düşünülebilir, ama bunları çözen bilgisayar ya da modellenmiş problem yoktur.

Amaç, zaman ya da bellek karmaşıklığını girdi boyutuna göre bir alt aileye indirmektir. Sıralama algoritmalarının çoğu $N^2$ ile bilinir; birleştirerek sıralama (merge sort) ve hızlı sıralama (quicksort) ise $N \log N$'ye iner.

## 2. Soru 1: Faktöriyel hesabı ve Stirling yaklaşımı

### 2.1 Naif algoritma

$N! = 1 \cdot 2 \cdot 3 \cdots (N-1) \cdot N$ hesabı için bir öğrenci, 1'den $N$'e kadar bir `for` döngüsüyle bütün sayıları çarpmayı önerdi. Hoca buna **naif algoritma** dedi: akla ilk gelen, karmaşık olmayan çözüm. Tahtadaki sözde kod şöyledir (ekrandan, 00:15:00):

```c
f = 1;
for(i=1; i<=N; i++){
    f = f*i;
}
```

Bu algoritmanın adım sayısı $T_1(N) = N$'dir, elde edilen sonuç ise $f = N!$'dir.

> **Hocanın vurgusu:** Algoritmanın çalışmasıyla elde edilen sonuç ile algoritmanın tamamlanması için gereken adım sayısı farklı şeylerdir. Problem faktöriyel hesabıdır, ama karmaşıklık $N!$ değil, $N$'dir.

### 2.2 Stirling formülü

Alternatif olarak **Stirling formülü** verildi. Bu formül $N!$'i tam değil, yaklaşık olarak verir (ekrandan, 00:15:00):

$$N! \approx \sqrt{2\pi N}\left(\frac{N}{e}\right)^N$$

Burada doğruluktan kaybedildi. Peki zamandan kazanıldı mı? Hoca karekök ve birkaç çarpmanın basit olduğunu, ama $(N/e)^N$ teriminin işi bozduğunu söyledi: $N/e$ bir kez hesaplanır, ama $N$'inci kuvvetini almak için yine $N$ kez dönen bir döngü gerekir. Başta 3-4 tane ek işlem (bölme, çarpmalar, karekök) olduğu için $T_2(N) = N + 4$ olur; $N$ yanında 4 ihmal edilir ve $T_2(N) \approx N$ bulunur. Sonuç: doğruluk kaybedildi, zamandan da bir şey kazanılmadı.

**Soru:** Karekök tek seferde çözülebiliyor mu? **Cevap:** Fonksiyon kullanınca tek seferde çözülüyor gibi görünür, ama makine düzeyinde `SQRT` diye temel bir işlem yoktur. Karekök de yaklaşım yöntemleriyle, yani aslında bir döngüyle, kayan noktalı sayının hassasiyeti kadar hesaplanır.

### 2.3 Kuvveti yarılayarak hesaplamak

$(N/e)^N$ teriminin daha hızlı hesaplanabileceği gösterildi (ekrandan, 00:20:00). $N^k$'yi $k$ kez dönen bir döngüyle hesaplamak yerine şu gözlem kullanılır:

$$N^k = N^{k/2} \cdot N^{k/2}$$

$N^{k/2}$ biliniyorsa, onu kendisiyle bir kez çarpmak yeter; problem yarı yarıya küçülür. Aynı fikir tekrar uygulanır:

$$N^{k/2} = N^{k/4} \cdot N^{k/4}, \quad \dots, \quad N^2 = N^1 \cdot N^1$$

Genel adım $N^{k/2^i}$ biçimindedir. Yarılama, üs 1'e inince durur:

$$\frac{k}{2^i} = 1 \;\Rightarrow\; 2^i = k \;\Rightarrow\; i = \log_2 k$$

Yani $k$ işlem yerine yaklaşık $\log_2 k$ işlem yapılır. Hoca $k$'nın tek ya da çift olduğu durumlarda bir adımda birden fazla işlem gerektiğini, bunun şimdilik göz ardı edildiğini söyledi. Bu yolla Stirling formülünün maliyeti $T_3(N) \approx \log_2 N$ olur. Doğruluk yine kaybedilir, çünkü $\pi$ ve $e$ irrasyonel sayılardır ve sonuç yaklaşık bir çözümdür (approximate solution). Naif çarpım ise kesin çözümdür (exact solution).

Bu yarılama fikri algoritmik olarak **özyineleme (recursion)** ile gerçeklenir. Özyineleme, bir problemi daha küçük problemlere bölüp onlar üzerinden çözme stratejisidir. Zaman kazandırır, doğruluğu bozmaz, ama bellekten kaybettirir. Kodu, özyineleme konusu işlenince yazılacak.

> **Hocanın vurgusu:** Özyineleme çok önemli bir konudur; bu örneğe o konuda tekrar dönülecek.

Hoca alıştırma olarak, Stirling formülünü `for` döngüsü ve karekök fonksiyonuyla kodlayıp örneğin $10!$'i iki yöntemle hesaplamayı ve aradaki farkı hata kavramıyla değerlendirmeyi önerdi.

> **Ek bilgi (derste anlatılmadı):** $10! = 3\,628\,800$'dür. Stirling formülü $10$ için yaklaşık $3\,598\,696$ verir; göreli hata yaklaşık %0,8'dir (python ile hesaplandı).

## 3. Soru 2: Pi sayısı için seri yaklaşımı

### 3.1 Seri ve ilk çözüm

$\pi$ için şu seri verildi (ekrandan, 00:30:00):

$$\pi = \frac{4}{1} - \frac{4}{3} + \frac{4}{5} - \frac{4}{7} + \dots$$

Terim sayısı arttıkça sonuç gerçek değere yaklaşır. Bir öğrenci $\pi$'nin değerini zaten bildiğimizi söyledi; hoca, programlama dilinde $\pi$'yi veren bir sabit ya da fonksiyon olmadığını varsaymamızı istedi. Bu durumda formül kodlanır ve $N$ terim alınır.

> **Hocanın vurgusu:** Her problemi $\log N$ ya da $1$'e indirmek gerekmez. Bazı durumlarda $N$'de kalmak gerekir.

Kesirlere bakınca pay hep 4, payda ise 1, 3, 5, 7 diye gider. Terimler 0'dan numaralanırsa çift numaralı terimler eklenir, tek numaralı terimler çıkarılır; son terim $N-1$'inci terimdir. Hoca akış diyagramı çizmek yerine kod yazar gibi ilerlediğini, bunun hem grafik tablette daha kolay olduğunu hem de öğrencilerin koda alışmasını sağladığını söyledi. Tahtadaki ilk çözüm (ekrandan, 00:30:00 ve 00:35:00):

```c
double mypi = 0;
int pay = 4;
int payda = 1;
for(i=0; i<N; i++){
    if(i%2==0){
        mypi += pay/(float)payda;
    }
    else{
        mypi -= (1.0*pay)/payda;
    }
    payda += 2;
}
print(mypi)
```

Hangi terimde olunduğunu anlamak için mod işlemi kullanılır: `i%2==0` ise terim çifttir, toplama yapılır; değilse çıkarma yapılır. `+=` operatörü önceki değerin üzerine ekler.

**Tam sayı bölmesi.** Algoritmada "pay bölü payda" demek yeterlidir, ama programlamada değildir. Bir öğrenci bunun tam sayı bölmesi yapacağını söyledi. Örneğin `4/5` tam sayı bölmesinde `0` verir, oysa kesirli sonuç gerekir. Bu yüzden ikisinden biri kayan noktalı türe çevrilir:

- Açık (explicit) dönüşüm: `(float)payda` ya da `(double)pay`.
- Örtük (implicit) dönüşüm: `1.0*pay`; tam sayı, `1.0` ile çarpılınca kayan noktalı sayıya dönüşür.

Bu kod bir algoritmadır: değişkenler tanımlanmış, bütün işlemler açık ve belirsizlik içermeyecek biçimde yazılmıştır. Hoca, bu tür bir soruda sözde kod, C'ye yakın kod, akış diyagramı ya da C koduyla verilen bu benzerlikte bir çözümün kabul edileceğini söyledi. Ama ara adımları atlayıp yalnızca "mypi'yi güncelle" yazmak algoritma sayılmaz.

### 3.2 Paydayı döngü değişkeninden hesaplamak

Bir öğrenci, payda ile döngü değişkeni arasında $\text{payda} = 2i + 1$ ilişkisi olduğunu fark etti. Bu durumda `payda += 2` yerine döngünün ilk satırında `payda = 2*i + 1;` yazılabilir: $i=0$ için 1, $i=1$ için 3 olur ve ayrı bir güncellemeye gerek kalmaz (ekrandan, 00:35:00).

### 3.3 Çözüm 2: `if` olmadan, ikişer terim

Bir öğrenci, her adımda önce bir terimi toplayıp sonra bir sonraki terimi çıkarmayı ve döngüyü ikişer ilerletmeyi önerdi. Hoca bunu şöyle yazdı (ekrandan, 00:35:00):

```c
for(i=0; i<N/2; i++){
    mypi += pay/payda;
    payda += 2;
    mypi -= pay/payda;
}
```

Burada her döngü adımında iki terim işlendiği için döngü $N/2$ kez döner. `if` ortadan kalkmıştır. (Kodda paydanın ikinci kez de artırılması gerekir; bu eksik, bilgisayarda çalıştırırken fark edildi, bkz. Bölüm 5.3.)

### 3.4 Çözüm 3: İşaret değişkeni

Bir öğrenci, bir işaret değişkeni tutup her adımda terimi bununla çarpmayı önerdi. Hoca `sign` değişkenini başta 1 yaptı (ilk terim toplanacağı için):

```c
mypi += 1.0*sign*pay/payda;
sign = -sign;
payda += 2;
```

`-sign` ifadesi C'deki tekli eksi (negation) operatörüdür; $-1$ ile çarpmaya gerek kalmadan değerin negatifini verir. Bu çözümle de `if` ortadan kalkar.

Tartışma sırasında bir öğrenci $8/2$ gibi somut sayılarla konuştu; hoca, algoritmada belirli sayılar üzerinden değil, parametrik konuşmak gerektiğini hatırlattı.

## 4. C'de operatör önceliği ve birleşme yönü

Hoca Dev-C++'ta kodu yazmaya başladı (ekrandan, 00:40:00):

```c
#include <stdio.h>

int main(){
    int pay=4, payda=1;
    int N = 100;
    double mypi=0;
    int i;
    ...
}
```

Değişken tanımları üzerine kısa bir not düştü: yalnızca bildirilen (declaration) bir değişken ile bildirildiği yerde ilk değer atanan (initialization) bir değişken, C'de bellekte farklı yerlerde düzenlenir; bunu ileride göstereceğini söyledi. Ayrıca kodda girinti (indentation) kullanarak okunabilirliği artırmanın önemini vurguladı.

**Soru:** `(double)pay/payda` ifadesini `((double)pay)/payda` diye parantez içine almak gerekir mi? **Cevap:** Gerek yoktur. C, operatörlerin önceliğine bakar. Tür dönüştürme (cast) operatörünün önceliği bölmeden yüksektir; yani bölmeden önce mutlaka dönüşüm yapılır. Ek parantez, operatör önceliğine hâkim olmayan biri için işi garantiye almaktan başka bir şey değildir.

Hoca, cppreference sitesindeki C operatör önceliği tablosunu açtı (ekrandan, 00:45:00). Tabloya göre:

| Öncelik | Operatörler | Açıklama | Birleşme yönü |
|---|---|---|---|
| 1 | `++` `--` (sonek), `()`, `[]`, `.`, `->` | Sonek artırma/azaltma, fonksiyon çağrısı, dizi indisi, üye erişimi | Soldan sağa |
| 2 | `++` `--` (önek), `+` `-` (tekli), `!` `~`, `(type)`, `*`, `&`, `sizeof` | Önek artırma/azaltma, tekli artı/eksi, mantıksal/bit değil, tür dönüştürme, işaretçi | Sağdan sola |
| 3 | `*` `/` `%` | Çarpma, bölme, kalan | Soldan sağa |
| 4 | `+` `-` | Toplama, çıkarma | Soldan sağa |
| 5 | `<<` `>>` | Bit kaydırma | Soldan sağa |
| 6 | `<` `<=` `>` `>=` | İlişkisel | Soldan sağa |
| 7 | `==` `!=` | Eşitlik | Soldan sağa |

Öncelik numarası ne kadar küçükse işlem o kadar önce yapılır. `+` operatörü tabloda iki yerde geçer: 2. satırda tekli artı (işaret), 4. satırda toplama.

Aynı öncelikteki operatörler bir arada olduğunda **birleşme yönü (associativity)** devreye girer. Hoca internette dolaşan şaşırtmaca sorulara örnek verdi: `8/4*2`. Çarpma ve bölme aynı önceliktedir ve soldan sağa işlenir: önce $8/4 = 2$, sonra $2 \cdot 2 = 4$. Sonuç 1 değildir.

Sağdan sola birleşmeye örnek atama operatörüdür:

```c
a = b = c = d = 3;
```

Önce `d`'ye 3 atanır, bu atamanın değeri olan 3 `c`'ye atanır, ve böyle devam eder. Bir ifadede hem atama hem çarpma varsa, atamanın önceliği düşük olduğu için önce eşitliğin sağ tarafındaki çarpma ve bölmeler yapılır, sonra atama yapılır.

> **Hocanın vurgusu:** C'de her şey kurallıdır; "öyle hissettim" diye bir şey yoktur.

## 5. Pi kodunun çalıştırılması, hata ayıklama ve süre ölçümü

### 5.1 İlk çalıştırma ve hata ayıklama

İlk çalıştırmada sonuç 0'a yakın çıktı; bir öğrenci paydanın artırılmasının unutulduğunu söyledi. Güncelleme eklenince $N=100$ için yaklaşık 3,13, $N=1000$ için 3,14 civarı, daha büyük $N$ için 3,1415'e yaklaşan değerler görüldü.

Hoca, kod doğru görünüp derleme hatası ya da uyarısı olmadığı halde beklenen sonuç çıkmıyorsa **hata ayıklama (debug)** kullanılacağını gösterdi (ekrandan, 00:50:00):

- Kodun bir satırına kesme noktası (breakpoint) konur.
- Execute menüsünden Debug seçilir; program o satıra kadar çalışır, sonra adım adım ilerler.
- İzlenecek değişkenler (`i`, `mypi`, `(double)pay`, `payda`) "Add watch" ile eklenir.
- "Next line" ile her adımda değişkenlerin değeri görülür.

Ekrandaki kod şuydu (ekrandan, 00:50:00):

```c
for(i=0;i<N;i++){
    if(i%2==0){
        mypi += (double)pay/payda;
    }
    else{
        mypi -= 1.0*pay/payda;
    }
    payda += 2;
    printf("%d %d %d ...", ...);
}
printf("Sonuc-1=%lf", mypi);
```

Bir algoritmanın adım adım analizini tablo halinde çıkarmak gerekiyorsa, kod doğruysa her adımda `i`, `pay`, `payda` ve `mypi` değerleri `printf` ile yazdırılabilir; `%d` tam sayı, `%lf` `double` için kullanılır, `\n` her satırı ayırır.

### 5.2 Ekrana yazdırma ve süre ölçümü

$N = 100\,000$ ile her adımı yazdırınca program uzun sürdü. Hoca, hesaplamanın aslında çoktan bittiğini, uzun sürenin ekrana yazdırma olduğunu açıkladı: çıktı bir arabelleğe (buffer) alınıp ekrana gönderilir. İşlemciler saniyede milyarlarca işlem yapar; 100 bin işlem milisaniyeler içinde biter.

> **Hocanın vurgusu:** Kodun hızı ekrana bakarak anlaşılmaz. Süre ölçümü yapılırken döngü içindeki `printf`'ler kapatılmalıdır; bunlar algoritmanın parçası değil, yalnızca sonucu görmek içindir.

C'de süre ölçümü için kodun başına bir `start`, sonuna bir `stop` değişkeni konur ve aralarındaki fark alınır. Hoca bunu ilerleyen kısımda `time.h` kütüphanesiyle gösterdi: `time_t` türünde iki değişken alınır, döngünün başında ve sonunda zaman kaydedilir, `difftime` fonksiyonu ile fark hesaplanır.

### 5.3 Tam sayı bölmesinin gösterimi

Bir öğrencinin isteği üzerine tam sayı bölmesi tekrar gösterildi. `3/4` ifadesi `%lf` ile yazdırılınca 0,75 yerine 0,00 benzeri bir değer çıktı. Sayılardan biri `3.0` yapılınca sonuç 0,75 oldu. Hoca, önceki derste gösterdiği veri türleri piramidine atıf yaptı: alttaki (küçük) tür üsttekine sorunsuz dönüşür, üstteki alttakine kayıpla dönüşür. Bölmenin doğası gereği iki işlenenden birinin dönüştürülmesi yeterlidir. Toplamada da durum aynıdır: `3.0 + 4` sonucu `7.000000` olarak görüldü (ekrandan, 00:55:00). `printf`'te `%lf` yazmak sonucu `double` yapmaz; sonuç ifadenin kendisinde belirlenir.

C bu tür dönüşümlerde uyarı vermez; programcının sorumluluğundadır. Java gibi diller ise tür dönüşümü (typecasting) yapılmadığında derleyici uyarısı verir. Değişken adlarında `pay.0` gibi bir yazım olmadığı için değişkenlerde dönüşüm ya `1.0*` ile çarparak ya da `(double)` ile yapılır.

### 5.4 Çözüm 2 ve 3'ün kodu

Çözüm 2 kodlanırken iki hata yapıldı ve düzeltildi: ikinci döngüden önce `mypi` sıfırlanmadığı için hesap kaldığı yerden devam etti; paydanın ikinci kez artırılması unutulduğu için sonuç 3,98 gibi yanlış çıktı. Düzeltilmiş hali (ekrandan, 01:00:00):

```c
for(i=0;i<N;i++){
    mypi += (double)pay/payda;
    payda += 2;
    mypi -= (double)pay/payda;
    payda += 2;
}
printf("Sonuc-2=%lf",mypi);
```

Hoca bu döngüyü $N$ kez çevirdiği için ikinci çözümün aslında $2N$ terim işlediğini, bu yüzden gerçek değere daha yakın çıktığını gösterdi; birinci çözüm $2N$ ile çalıştırılınca iki sonuç eşitlendi.

Çözüm 3 (ekrandan, 01:00:00):

```c
pay=4; payda=1; mypi=0; sign=1;
for(i=0;i<N;i++){
    mypi += sign*pay/(double)payda;
    sign = -sign;
    payda += 2;
}
```

Virgülden sonra 10 basamak görmek için `%2.10lf` biçim belirteci kullanılabilir; biçim belirteçleri ileride ayrıntılı işlenecek.

Aşağıdaki tam program, derste gösterilen üç çözümü birleştirir. Ajan tarafından `gcc -Wall` ile derlenip çalıştırıldı ($N=100$ için üç çözüm de `3.131593` verdi):

```c
#include <stdio.h>

int main(){
    int pay = 4, payda = 1;
    int N = 100;
    double mypi = 0;
    int i, sign;

    for(i = 0; i < N; i++){
        if(i % 2 == 0){
            mypi += (double)pay / payda;
        }
        else{
            mypi -= 1.0 * pay / payda;
        }
        payda += 2;
    }
    printf("Sonuc-1=%lf\n", mypi);

    payda = 1; mypi = 0;
    for(i = 0; i < N/2; i++){
        mypi += (double)pay / payda;
        payda += 2;
        mypi -= (double)pay / payda;
        payda += 2;
    }
    printf("Sonuc-2=%lf\n", mypi);

    pay = 4; payda = 1; mypi = 0; sign = 1;
    for(i = 0; i < N; i++){
        mypi += sign * (double)pay / payda;
        sign = -sign;
        payda += 2;
    }
    printf("Sonuc-3=%lf\n", mypi);
    return 0;
}
```

## 6. Soru 3: e üzeri x için Taylor serisi

### 6.1 Seri ve ilk yaklaşım

Arada verilen moladan sonra daha karmaşık bir yaklaşım algoritmasına geçildi (ekrandan, 01:20:00):

$$e^x = \frac{1}{0!} + \frac{x}{1!} + \frac{x^2}{2!} + \frac{x^3}{3!} + \dots + \frac{x^{N-1}}{(N-1)!} + \frac{x^N}{N!}$$

Terimler 0'dan numaralanırsa $N-1$'inci terim $\frac{x^{N-1}}{(N-1)!}$'dir. Bir öğrenci iç içe `for` döngüleri önerdi: dışta terimleri dolaşan bir döngü, içte biri üst (pay) diğeri faktöriyel (payda) için iki döngü. Hoca bunu tahtada akış diyagramı olarak çizdi (ekrandan, 01:20:00). İlk iki terimin toplamı doğrudan yazılır: sonuç başta $R = x + 1$ olur ve döngü $x^2$'den başlar. İç döngülerin sınırı dış döngünün değişkenine bağlıdır: ikinci terimde kare, üçüncü terimde küp alınır.

Hoca, bu yaklaşımın sorununu sordu. Bir öğrenci $N^2$'de çalıştığını söyledi: dış döngü $N$ kez, içtekiler yaklaşık $N$ kez döner.

### 6.2 İkinci yaklaşım: önceki terimi kullanmak

Kuvvet hesabındaki fikir burada da kullanılır: $x^2$ hesaplandıysa $x^3$'ü baştan hesaplamaya gerek yoktur; $x^2$ ile $x$ çarpılır. Aynı şekilde $3! = 2! \cdot 3$'tür. Böylece iç döngüler kalkar ve tek döngü kalır:

- `pay = pay * x;`
- `payda = payda * i;` ($i$ 2'den başlatılırsa $+1$'e gerek kalmaz)
- `tmp = 1.0*pay/payda;` (ara toplam)
- `result = result + tmp;`

Bu döngü $N$ kez döner; karmaşıklık $N^2$'den $N$'ye iner.

Ödev kâğıdındaki çalışma sorusu olarak $\cos x$ serisi verildi; bu soru, $\pi$ sorusundaki işaret değişimini $e^x$ sorusundaki üst ve faktöriyel hesabıyla birleştirir:

$$\cos x = 1 - \frac{x^2}{2!} + \frac{x^4}{4!} - \frac{x^6}{6!} + \dots$$

### 6.3 Birinci yaklaşımın kodu

Hoca yeni bir dosyada kullanıcıdan $x$ değeri aldı (ekrandan, 01:25:00 ve 01:35:00):

```c
int x;
printf("Enter x value");
scanf("%d",&x);
```

`scanf`'te alınacak verinin türü belirtilir: tam sayı için `%d`, karakter için `%c`. Değişkenin adres bölgesinde değişiklik yapılacağı için değişken adının önüne `&` konur; ayrıntısı işaretçiler (pointer) konusunda işlenecek.

**Soru:** Kullanıcı on altılık tabanda `0xE` gibi bir değer girebilir mi? **Cevap:** Hoca denemediğini, dönüşüm yapılamazsa programın hatalı çalışacağını ve kurallara uygun girdi verilmesi gerektiğini söyledi.

C yapısal bir dil olduğu için değişken tanımları işlemlerden önce yapılır. Birinci yaklaşımın kodu (ekrandan, 01:30:00):

```c
result = x + 1;
for(i=2;i<=N;i++){
    pay = 1;
    for(j=1;j<=i;j++){ // exponent
        pay = pay * x; // pay *=x;
    }
    payda = 1; // fctorial
    for(j=1;j<=i;j++){
        payda = payda * j; // pay *=j;
    }
    tmp = (double)pay/payda;
    result = result + tmp;
}
```

İç döngülerde aynı `j` değişkeni kullanılabilir, çünkü ilk döngü bittiğinde `j`'nin işi biter. `pay *= x` ifadesi `pay = pay * x` ifadesinin kısa yazımıdır.

### 6.4 Taşma (overflow) sorunu

$x = 5$ için gerçek değer $e^5 \approx 148{,}413$'tür. Terim sayısı çok büyük verilince sonuç sonsuz (inf) çıktı; 10 terimle 146,380 bulundu. Terim sayısı artırılınca sonucun gerçek değere yaklaşması gerekirken uzaklaştı. Hoca kesme noktası koyup değerleri izledi (ekrandan, 01:35:00): $x^2 = 25$, $2! = 2$, `tmp` $= 12{,}5$, `result` $= 6 + 12{,}5$; sonra $x^3 = 125$, $3! = 6$... Bu adımlar doğruydu. Sorunun nedeni şuydu: `pay` ve `payda` `int` türünde olduğu için büyük terimlerde değer sığmaz ve **tam sayı taşması (overflow)** olur. `long`, `long long`, `unsigned long` gibi türler denendi; sınır biraz ötelendi ama yeterince büyük terim sayısında taşma yine oluştu.

> **Ders sonrası not:** 32 bitlik `int` en çok $2\,147\,483\,647$ tutar. $13! = 6\,227\,020\,800$ ve $5^{14} = 6\,103\,515\,625$ bu sınırı aşar; bu yüzden $x=5$ için 13 ve daha fazla terimde `int` ile sonuç bozulur. `long long` kullanılınca 15 terimle `148.402917` elde edilir (ajan tarafından `gcc` ile doğrulandı). 10 terimle elde edilen 146,38 değeri python ile de doğrulandı.

Hoca, çok büyük sayılarla toplama ve çarpma gibi `int`'in yetmediği durumlarda ileride yapılar (structure) üzerinde farklı yöntemler göreceklerini söyledi.

### 6.5 Karmaşıklık analizi

Hoca birinci yaklaşımın kodunu slayta alıp analiz etti (ekrandan, 01:40:00). Bütün işlemleri tek tek saymak yerine **temel işlem (basic operation)** sayılır ve maliyeti 1 kabul edilir. İç döngülerdeki çarpmalar temel işlemdir. İç döngü 1'den $i$'ye kadar gider, yani $i$ kez döner:

$$T(N) = \sum_{i=1}^{N} \sum_{j=1}^{i} 1 = \sum_{i=1}^{N} i = 1 + 2 + \dots + N = \frac{N(N+1)}{2} \approx \frac{N^2}{2} \approx N^2$$

Bu, ifadenin sonucu değil, algoritmanın adım sayısıdır. İki çarpmanın maliyetini 2 kabul etmek de sonucu değiştirmez; sabit çarpanlar düşer ve yine $N^2$ bulunur.

> **Hocanın vurgusu:** Döngü birer birer artıyorsa doğrudan toplam sembolüne çevrilebilir. İkişer ikişer ya da 1, 2, 4, 8 gibi üstel artıyorsa başka yöntemler gerekir.

### 6.6 İkinci yaklaşımın kodu

İkinci yaklaşımda başlangıç değerleri `result = x + 1`, `pay = x`, `payda = 1` oldu (ekrandan, 01:45:00). Kodlarken iki hata çıktı: önce pay ve paydanın başlangıç değerleri ters yazıldı, sonra kopyala-yapıştır yüzünden faktöriyel güncellemesinde döngü değişkeni `i` yerine `j` kaldı. Düzeltilmiş hali:

```c
result = x + 1;
pay = x;
payda = 1;
for(i=2;i<=N;i++){
    pay = pay * x;
    payda = payda * i;
    tmp = (double)pay/payda;
    result = result + tmp;
}
```

Bir öğrenci iki yaklaşımın farkını süre olarak görmek istedi. Hoca `time.h` kütüphanesinde `time_t` türü ve `difftime` fonksiyonunu gösterdi: döngünün başında `start`, sonunda `stop` alınır ve fark ekrana yazdırılır; içeride `printf` olmamalıdır.

İki yaklaşımı içeren tam program (ajan tarafından `gcc -Wall` ile derlenip $x=5$ ve $x=1$ girdileriyle çalıştırıldı; taşmayı önlemek için `long long` kullanıldı, derste `int` ile başlandı):

```c
#include <stdio.h>

int main(){
    int x;
    long long pay, payda;
    int N = 15;
    double result, tmp;
    int i, j;
    printf("Enter x value: ");
    scanf("%d", &x);

    result = x + 1;
    for(i = 2; i <= N; i++){
        pay = 1;
        for(j = 1; j <= i; j++){
            pay = pay * x;
        }
        payda = 1;
        for(j = 1; j <= i; j++){
            payda = payda * j;
        }
        tmp = (double)pay / payda;
        result = result + tmp;
    }
    printf("\nSonuc-1=%lf\n", result);

    result = x + 1;
    pay = x; payda = 1;
    for(i = 2; i <= N; i++){
        pay = pay * x;
        payda = payda * i;
        tmp = (double)pay / payda;
        result += tmp;
    }
    printf("Sonuc-2=%lf\n", result);
    return 0;
}
```

Çıktı: $x=5$ için iki yaklaşım da `148.402917`, $x=1$ için `2.718282` verdi.

## 7. Soru 4: Fibonacci sayıları

### 7.1 Üç değişkenli çözüm

Fibonacci dizisi 0 ve 1 ile başlar; sonraki her terim kendinden önceki iki terimin toplamıdır: 0, 1, 1, 2, 3, 5, 8, 13, ... (ekrandan, 01:55:00). Amaç ilk $N$ terimi ekrana yazdırmaktır.

Başlangıç koşulları $t_1 = 0$, $t_2 = 1$'dir. Bunlar yazdırılır, sonra döngüye girilir:

```c
t1 = 0;
t2 = 1;
print(t1, t2)
for(i=2; i<N; i++){
    next = t1 + t2;
    print(next)
    t1 = t2;
    t2 = next;
}
```

Güncellemede sıra önemlidir. Önce `t1 = t2`, sonra `t2 = next` yapılır. Tersi yapılırsa `t2`'nin değeri kaybolur. Her adımda bir toplama ve üç atama, yani yaklaşık 4 işlem vardır: $T_1(N) \approx 4N$, karmaşıklık ailesi $N$'dir. Bellek açısından yalnızca üç değişken (`t1`, `t2`, `next`) kullanılır; bu sabit bellektir.

### 7.2 Dizi ile çözüm

İkinci çözümde bir `d` dizisi kullanılır: `d[0] = 0`, `d[1] = 1`, sonraki elemanlar başta çöp değer olabilir (ekrandan, 01:55:00):

```c
for(i=2; i<N; i++){
    d[i] = d[i-1] + d[i-2];
}
```

Hoca işlem sayısını kabaca saydı: iki indis hesabı, iki dizi erişimi, bir toplama ve bir atama; yaklaşık $T_2(N) \approx 6N$. Zaman açısından kazanç yoktur, hatta biraz kayıp vardır. Bir öğrenci dezavantajın yer tutması olduğunu söyledi: bellek $N$'dir. Bu çözümün avantajı kodlamasının kolay olmasıdır (easy to implement); $t_1$ ile $t_2$'nin hangi sırayla güncelleneceğini düşünmek gerekmez. Aynı mantık ileride özyinelemeli çözümde de kullanılacak.

### 7.3 Daha hızlı çözümler

Hoca, başlangıç koşulları bilinen $2 \times 2$'lik bir matrisin $N$'inci kuvveti alınarak $N$'inci Fibonacci sayısının bulunabileceğini söyledi. Kuvvet, ders başında görülen yarılama yöntemiyle $\log N$ adımda alınabilir; böylece $N$'den daha iyi bir karmaşıklık elde edilir. Altın oran (yaklaşık 1,618) ile ilgili bir çözümden de söz etti. Bunları araştırma ödevi olarak bıraktı.
<!-- BELİRSİZ: 01:56:28 civarında matrisin elemanları altyazıda "0-0-0-1" diye geçiyor, ekranda görülmedi; 01:57:40 civarında altın oranla ilgili çözümün karmaşıklığı altyazıda anlaşılmıyor. -->

> **Ek bilgi (derste anlatılmadı):** Bilinen matris biçimi $\begin{pmatrix}1 & 1\\ 1 & 0\end{pmatrix}^n = \begin{pmatrix}F_{n+1} & F_n\\ F_n & F_{n-1}\end{pmatrix}$ eşitliğidir. Altın oranla ilgili olan ise Binet formülüdür: $F_n = \frac{\varphi^n - \psi^n}{\sqrt{5}}$, $\varphi = \frac{1+\sqrt5}{2} \approx 1{,}618$.

### 7.4 Fibonacci kodu

Moladan sonra iki çözüm de C ile yazıldı (ekrandan, 02:10:00):

```c
int t1=0, t2=1, next;
int i;
int N=MAX;
int dizi[MAX];
printf("0 -> %d\n",t1);
printf("1 -> %d\n",t2);
for(i=2;i<=N;i++){
    next = t1 + t2;
    printf("%d -> %d\n",i,next);
    t1 = t2;
    t2 = next;
}
```

Çıktının son satırı 15. Fibonacci sayısı olarak 610'u gösterdi.

Dizi için hoca şunu açıkladı: C'de dizinin boyutu çalışma zamanında bir değişkenin değerine göre belirlenemez; çalışma zamanında belirlenen büyük diziler için işletim sisteminin izin verdiği yığın (heap) bölgesi ve işaretçiler gerekir. Küçük boyutlu diziler için kısa yol, boyutu derleme zamanında bir sabitle (`MAX`) vermektir; derleme sırasında bu sabit kodun içine yapıştırılır. Döngü içinde `dizi[i] = dizi[i-1] + dizi[i-2];` yazılır. Hoca elemanları ayrı bir döngüyle yazdırmak yerine aynı döngüde hesaplayıp yazdırmanın kodu sadeleştireceğini söyledi: birbirinden bağımsız iki döngü karmaşıklığı $N$'den $2N$'ye çıkarır; bu aile değiştirmez ama kodu kalabalıklaştırır.

> **Ders sonrası not:** Döngü `i<=N` ile $N = $ `MAX` indisine kadar gittiği için dizinin `MAX+1` elemanlı tanımlanması gerekir; `int dizi[MAX];` ile `dizi[MAX]`'a yazmak dizi sınırını aşar.

Ajanın birleştirdiği tam program (`gcc -Wall` ile derlenip çalıştırıldı, iki çözüm de 0'dan 610'a kadar aynı diziyi verdi):

```c
#include <stdio.h>
#define MAX 15

int main(){
    int t1 = 0, t2 = 1, next;
    int i;
    int N = MAX;
    int dizi[MAX + 1];

    printf("0 -> %d\n", t1);
    printf("1 -> %d\n", t2);
    for(i = 2; i <= N; i++){
        next = t1 + t2;
        printf("%d -> %d\n", i, next);
        t1 = t2;
        t2 = next;
    }

    dizi[0] = 0;
    dizi[1] = 1;
    printf("%d %d ", dizi[0], dizi[1]);
    for(i = 2; i <= N; i++){
        dizi[i] = dizi[i-1] + dizi[i-2];
        printf("%d ", dizi[i]);
    }
    printf("\n");
    return 0;
}
```

## 8. Soru 5: Armstrong sayıları

### 8.1 Problem ve ilk çözüm

Soru: 1 ile 1000 arasında, basamaklarının küpleri toplamı kendisine eşit olan sayıları listeleyin. Bu sayılara **Armstrong sayısı** denir. Bütün sayılara bakılacağı için bir `for` döngüsü yeterlidir; `while`'a gerek yoktur.

Döngü değişkeni `i` doğrudan basamaklarına ayrılırsa döngü bozulur; bu yüzden sayı `num` adlı bir değişkene yedeklenir. Son basamak `num % 10` ile alınır, sayı `num / 10` tam sayı bölmesiyle küçültülür. Hoca küp için `pow` fonksiyonu yerine doğrudan `digit*digit*digit` yazdı. İlk çözüm üç basamağı açıkça ayırır (ekrandan, 02:15:00 ve 02:20:00):

```c
for(i=1;i<=999;i++){
    num=i;
    sum = 0;
    digit = num % 10;
    sum += digit*digit*digit;
    num = num / 10 ;
    digit = num % 10;
    sum += digit*digit*digit;
    num = num / 10 ;
    digit = num % 10;
    sum += digit*digit*digit;
    if(sum == i){
        printf("%d \n",sum);
    }
}
```

Sayı tek basamaklıysa ikinci ve üçüncü adımlarda basamak 0 gelir ve toplama etkisi olmaz; iki basamaklıysa üçüncü adımın etkisi olmaz. Çıktı: 1, 153, 370, 371, 407. Hoca 407'yi elle doğruladı: $4^3 + 0^3 + 7^3 = 64 + 0 + 343 = 407$.

### 8.2 Genelleştirme

**Soru:** Aralık 999 yerine 999 999 olsaydı program doğru çalışır mıydı? **Cevap:** Hayır. Dört ve daha fazla basamaklı sayılarda dördüncü basamak alınmaz; bu çözüm geçicidir. Bir öğrenci üç basamak daha eklemeyi önerdi; hoca bunun gereksiz uzun kod yazmak olduğunu, 66 basamaklı bir sayı düşünüldüğünde algoritmik çözüm olmadığını söyledi. Doğrusu, sayı 0 olana kadar son basamağı alıp küçülten bir iç döngüdür:

```c
for(i=1;i<=999;i++){
    num = i;
    sum = 0;
    while(num > 0){
        digit = num % 10;
        sum += digit*digit*digit;
        num /= 10;
    }
    if(sum == i){
        printf("%d \n", sum);
    }
}
```

Hoca, aynı fikrin klavyeden girilen bir sayının kaç basamaklı olduğunu bulma sorusunda da kullanıldığını belirtti.

### 8.3 do-while sürümü

Aynı iç döngü `do-while` ile de yazıldı (ekrandan, 02:25:00):

```c
num=i;
sum = 0;
do{
    digit = num %10;
    sum += digit*digit*digit;
    num /=10;
}while(num>0);
if(sum == i){
    printf("%d \n",sum);
}
```

> **Hocanın vurgusu:** `if` ve `while` satırlarının sonuna noktalı virgül konmaz. Tek istisna `do-while`'dır: `while(koşul);` satırının sonunda noktalı virgül gerekir.

Hoca üst sınırı çok büyütünce programın uzun süre çalıştığını, 407'den sonra yeni bir sayı bulmadığını gösterdi. Bunun makul olduğunu açıkladı: basamak sayısı arttıkça küplerin toplamı sayının kendisine yetişemez. Armstrong sayısının genel tanımı ise şudur: $n$ basamaklı bir sayının basamaklarının $n$'inci kuvvetleri toplamı kendisine eşitse sayı Armstrong sayısıdır.

> **Ders sonrası not:** Ekranda döngü sınırı `i<=9999999999` yazılmıştı (ekrandan, 02:25:00). Bu sabit 32 bitlik `int`'in en büyük değerinden büyük olduğu için `int i` ile koşul hiçbir zaman yanlış olmaz; döngü kendiliğinden bitmez. Programın "bitmeden çalışmaya devam etmesinin" bir nedeni büyük olasılıkla budur.

Bir öğrenci basamak sayısını her sayı için yeniden bulmak yerine, sayılar 10, 100, 1000 sınırlarını geçtikçe basamak sayısını artırmayı önerdi. Hoca bunun iç içe iki döngü gerektirdiğini söyledi ve fikri kod olarak yazıp sonraki derse getirmesini istedi.

Derste gösterilen üç çözümü içeren tam program (ajan tarafından `gcc -Wall` ile derlenip çalıştırıldı; üçü de 1, 153, 370, 371, 407 verdi):

```c
#include <stdio.h>

int main(){
    int i, num, sum, digit;
    for(i = 1; i <= 999; i++){
        num = i;
        sum = 0;
        digit = num % 10;
        sum += digit*digit*digit;
        num = num / 10;
        digit = num % 10;
        sum += digit*digit*digit;
        num = num / 10;
        digit = num % 10;
        sum += digit*digit*digit;
        if(sum == i){
            printf("%d \n", sum);
        }
    }
    for(i = 1; i <= 999; i++){
        num = i; sum = 0;
        while(num > 0){
            digit = num % 10;
            sum += digit*digit*digit;
            num /= 10;
        }
        if(sum == i) printf("%d \n", sum);
    }
    for(i = 1; i <= 999; i++){
        num = i; sum = 0;
        do{
            digit = num % 10;
            sum += digit*digit*digit;
            num /= 10;
        }while(num > 0);
        if(sum == i) printf("%d \n", sum);
    }
    return 0;
}
```

## 9. Önermeler mantığı ve karşı örnek yöntemi

### 9.1 Önermeler ve kanıt yöntemleri

Armstrong sorusundaki "tek tek deneme" yaklaşımından matematiğin önemli bir konusuna geçildi: **önermeler mantığı** (ekrandan, 02:30:00). Bir $P(x)$ önermesi ya doğrudur (T) ya da yanlıştır (F); doğruluğu $x$ parametresine bağlıdır. Önermenin doğruluğunu göstermek için iki yol vardır (ekrandan, 02:35:00):

- **Kanıt yöntemleri (proof methods):** tümevarım (induction), doğrudan kanıt (direct proof), dolaylı kanıt (indirect proof), çelişki (contradiction). Bunlar kâğıt üzerinde yapılır ve ayrıntılı olarak ayrık matematik dersinde görülecek.
- **Hesaplama (computing):** kanıt yöntemlerinin yetişemediği yerde bilgisayarla program yazılır. Hesaplama bütün durumlarda önermeyi doğrularsa önerme doğrudur; en az bir durumda yanlışlarsa önerme yanlıştır.

### 9.2 Örnek: n² + n + 41 asal mıdır?

Önerme (ekrandan, 02:35:00):

$$P(n): \; \forall n \in \mathbb{N}^+, \; n^2 + n + 41 \text{ asaldır.}$$

Bir öğrenci $n = 41$ için bakılmasını önerdi:

$$41^2 + 41 + 41 = 41 \cdot (41 + 1 + 1) = 43 \cdot 41$$

Bu sayı asal değildir; önerme "her $n$ için" dediğinden tek bir aykırı durum onu yanlışlar. Hoca, 41'in göze çarptığını ama bunun bilgisayarla nasıl bulunacağını sordu. Algoritma taslağı:

```text
for(n=1; n<sonsuz; n++)
    Pn = n*n + n + 41
    check: Pn is prime or not
```

Hoca bunun henüz tam bir algoritma olmadığını vurguladı: $P_n$'i hesaplamak kolaydır, ama "asal mı kontrol et" adımı açık değildir (vague). Algoritmada böyle belirsiz bir adım olmamalıdır; problemin içinden yeni bir problem çıkmıştır.

### 9.3 Asal sayı kontrolü

Bir sayı, 1 ve kendisi dışındaki hiçbir sayıya tam bölünmüyorsa asaldır. Bu yüzden 2'den başlayıp $n-1$'e kadar her `i` için `n % i` hesaplanır (ekrandan, 02:45:00):

```c
for(i=2; i<n-1; i++){
    ...
}
if(i==n)
    print(Asal Degil)
```

Hoca, bir bölen bulunduğunda döngünün sonuna kadar gitmenin gereksiz olduğunu sordu. Bir öğrenci `for` içine `while` eklemeyi önerdi; hoca bunun iç içe iki döngü, yani daha fazla işlem demek olduğunu söyledi. Bir öğrenci `break` önerdi; hoca `break`'in işlevini döngü koşuluna taşıdı: döngü `i < n-1 && n%i != 0` olduğu sürece döner. Böylece döngü gövdesi boşalır ve bu yapı `while` döngüsüyle daha doğal yazılır:

```c
i = 2;
while(i < n/2 && n%i != 0)
    i++;
if(i == n)
    print(Asal degil)
else
    print(Asal)
```

Hoca $n = 17$ örneğiyle döngüyü izledi: 2'den başlayarak hiçbir sayı 17'yi bölmez; sayaç sona ulaşınca koşuldan çıkılır.

> **Ders sonrası not:** Hoca tahtada ve sözlü olarak "`i == n` ise asal değil, değilse asal" dedi. Doğrusu tersidir: döngü hiçbir bölen bulmadan sona geldiyse sayı **asaldır**; döngü bir bölende durduysa asal değildir. Ayrıca döngü sınırı `n-1` ya da `n/2` iken `i` hiçbir zaman `n` değerine ulaşmaz; bu yüzden ya sınır `i < n` alınıp `i == n` denetlenmeli ya da `n % i != 0` sonucu (bölen bulunup bulunmadığı) denetlenmelidir.

Bu çözüm $P(n)$ taslağındaki "check" adımının yerine konur. $n = 1, 2, 3, \dots$ için denenir; $n = 41$'de $43 \cdot 41$ asal çıkmaz ve önerme yanlışlanır. İlk yanlışlayan örnek bulunduğu için daha büyük $n$ değerlerine bakmaya gerek yoktur.

> **Ders sonrası not:** $n = 41$ doğru bir karşı örnektir, ama ilk karşı örnek değildir: $n = 40$ için $40^2 + 40 + 41 = 1681 = 41^2$ asal değildir. Aşağıdaki program da ilk karşı örnek olarak $n = 40$'ı bulur.

Ajanın düzelttiği tam program (derste bu biçimde yazılmadı; `gcc -Wall` ile derlenip çalıştırıldı, çıktı: `Karsi ornek: n=40, P(n)=1681`):

```c
#include <stdio.h>

int asal_mi(long long n){
    long long i = 2;
    if(n < 2) return 0;
    while(i < n && n % i != 0){
        i++;
    }
    return i == n;
}

int main(){
    long long n, pn;
    for(n = 1; ; n++){
        pn = n*n + n + 41;
        if(!asal_mi(pn)){
            printf("Karsi ornek: n=%lld, P(n)=%lld\n", n, pn);
            break;
        }
    }
    return 0;
}
```

### 9.4 Karşı örnek yöntemi

Yapılan işin adı **karşı örnek bulma (counter example)** yöntemidir. Bir önermenin doğruluğunu bu yolla göstermek için sonsuz deneme gerekir; ama yanlışlığını göstermek için tek bir karşı örnek bulmak yeter. Bu tür aramalarda, nerede biteceği önceden bilinmediği için `while` döngüsü kullanılır.

### 9.5 Asal kontrolünü iyileştirmek

Bir öğrenci kontrolün $n/2$'ye kadar yapılmasını önerdi; bir sayının kendisi dışındaki en büyük böleni en fazla yarısıdır. Hoca daha iyisinin $\sqrt{n}$'e kadar bakmak olduğunu söyledi. Örneğin 16 için 8'e kadar değil 4'e kadar bakmak yeter; 17 için $\sqrt{17} \approx 4{,}12$ olduğundan 2'den 5'e kadar bakmak yeterlidir. Oysa 17'nin yarısına (yaklaşık 9) kadar bakmak gereksiz iştir.

Hoca ayrıca **Eratosthenes kalburu** adlı bir algoritmadan söz etti: bilinen asal sayılar bir dizide saklanır; test edilen sayı bunlardan birinin katıysa asal değildir.

> **Ek bilgi (derste anlatılmadı):** Klasik Eratosthenes kalburu, 2'den $N$'e kadar bütün sayıları listeleyip her asalın katlarını işaretleyerek $N$'e kadarki bütün asalları bulur. Derste anlatılan "bilinen asallara bölerek deneme" ise asallarla deneme bölmesidir; ikisi akraba fikirlerdir ama aynı algoritma değildir.

### 9.6 Euler'in kuvvetler toplamı sanısı

Son örnek olarak şu önerme verildi (ekrandan, 02:50:00):

$$\exists\, a, b, c, d \in \mathbb{N}^+ : \; a^4 + b^4 + c^4 = d^4$$

Uzun süre bu eşitliği sağlayan bir çözümün olmadığı düşünüldü. 1988'de bilgisayar aramasıyla bir çözüm bulundu:

$$95800^4 + 217519^4 + 414560^4 = 422481^4$$

(Eşitlik python ile doğrulandı.) Böyle bir arama, $a$, $b$, $c$, $d$ değişkenlerini 1'den başlatan dört iç içe döngüyle yapılabilir; en içte $a^4 + b^4 + c^4 = d^4$ denetlenir (ekrandan, 02:50:00). Çözüm bulununca arama durdurulur. Her değişken 1'den $N$'e kadar giderse karmaşıklık $N^4$'tür. Hoca, önermenin daha genel bir hali olan $a^n + b^n + c^n = d^n$ için de "çözüm yoktur" iddiasının 4. kuvvette bulunan bu karşı örnekle yanlışlandığını, ama genel durumun ispatının daha zor olduğunu söyledi.
<!-- BELİRSİZ: 02:48:34-02:49:24 arası altyazı bozuk (halüsinasyon); döngü yapısı yalnız ekrandaki çizimden alındı. -->

> **Ek bilgi (derste anlatılmadı):** Bu sanı Euler'in kuvvetler toplamı sanısı olarak bilinir. 1988'de önce Noam Elkies bir karşı örnek buldu; Roger Frye ise bilgisayar aramasıyla derste verilen en küçük çözümü buldu (büyük olasılıkla).

## Örnek Sorular

**Soru 1** (ekrandan, 00:15:00): $N!$'i hesaplayan bir algoritma geliştirin ve karmaşıklığını bulun. Stirling yaklaşımı $N! \approx \sqrt{2\pi N}(N/e)^N$ zaman ve doğruluk açısından nasıl karşılaştırılır?

> **Çözüm (derste verildi):** Naif çözüm `f=1; for(i=1;i<=N;i++) f=f*i;`, $T_1(N)=N$, sonuç kesin. Stirling formülü kuvvet döngüyle alınırsa $T_2(N)=N+4\approx N$, sonuç yaklaşık; kuvvet yarılamayla alınırsa $T_3(N)\approx\log_2 N$, sonuç yine yaklaşık.

**Soru 2** (ekrandan, 00:30:00): $\pi = 4/1 - 4/3 + 4/5 - 4/7 + \dots$ serisini $N$ terim için hesaplayan algoritmayı yazın.

> **Çözüm (derste verildi):** Bölüm 3 ve 5.4'teki üç çözüm. $N=100$ için sonuç `3.131593`'tür.

**Soru 3** (derste sözlü, 00:43:51): C'de `8/4*2` ifadesinin değeri nedir?

> **Çözüm (derste verildi):** `*` ve `/` aynı önceliktedir ve soldan sağa işlenir: $(8/4)\cdot 2 = 4$.

**Soru 4** (ekrandan, 01:20:00): $e^x = 1 + x/1! + x^2/2! + \dots$ serisini hesaplayan algoritmayı yazın; karmaşıklığını analiz edin.

> **Çözüm (derste verildi):** İç içe döngülü yaklaşım $\sum_{i=1}^{N} i \approx N^2$; önceki terimi kullanan yaklaşım $N$. $x=5$, 10 terim için 146,38; gerçek değer 148,413.

**Soru 5** (derste sözlü, 01:23:08; ödev kâğıdındaki çalışma sorusu): $\cos x = 1 - x^2/2! + x^4/4! - x^6/6! + \dots$ serisini hesaplayan algoritmayı yazın.

> **Çözüm (derste verilmedi):** Önceki terimden bir sonrakine geçmek için terim $-x^2/((2k-1)(2k))$ ile çarpılır. Aşağıdaki kod ajan tarafından `gcc -Wall` ile derlenip $x=1$ için çalıştırıldı; sonuç `0.540302`'dir (`cos(1)` ile aynı).

```c
#include <stdio.h>

int main(){
    double x = 1.0, terim = 1.0, sonuc = 1.0;
    int k, N = 10;
    for(k = 1; k < N; k++){
        terim = -terim * x * x / ((2*k - 1) * (2*k));
        sonuc += terim;
    }
    printf("cos(%lf) = %lf\n", x, sonuc);
    return 0;
}
```

**Soru 6** (ekrandan, 01:55:00): Fibonacci dizisinin ilk $N$ terimini yazdırın; üç değişkenli ve dizili çözümleri zaman ve bellek açısından karşılaştırın.

> **Çözüm (derste verildi):** Üç değişkenli çözüm $T_1(N)\approx 4N$, sabit bellek; dizili çözüm $T_2(N)\approx 6N$, bellek $N$. 15. terim 610'dur.

**Soru 7** (ekrandan, 02:15:00): 1 ile 1000 arasında basamaklarının küpleri toplamı kendisine eşit olan sayıları listeleyin.

> **Çözüm (derste verildi):** 1, 153, 370, 371, 407.

**Soru 8** (ekrandan, 02:35:00): $\forall n\in\mathbb{N}^+$, $n^2+n+41$ asaldır önermesi doğru mudur?

> **Çözüm (derste verildi):** Yanlıştır. $n=41$ için $43\cdot 41$ asal değildir. (İlk karşı örnek $n=40$, $1681=41^2$'dir; bkz. Bölüm 9.3.)

**Soru 9** (ekrandan, 02:50:00): $a^4+b^4+c^4=d^4$ eşitliğini sağlayan pozitif tam sayılar var mıdır? Bunu arayan algoritma nasıl kurulur?

> **Çözüm (derste verildi):** Vardır: $95800^4+217519^4+414560^4=422481^4$. Dört iç içe döngüyle kaba kuvvet araması yapılır, karmaşıklık $N^4$.

## Dersin Toparlaması

Bu derste algoritma tasarımındaki zaman, bellek ve doğruluk ödünleşimi somut sorular üzerinden incelendi. Faktöriyel örneğinde sonuç ile adım sayısının farklı olduğu, Stirling yaklaşımının doğruluktan kaybettirip zaman kazandırmadığı, kuvveti yarılayarak almanın ise adım sayısını $\log_2$ düzeyine indirdiği görüldü. $\pi$ ve $e^x$ serileriyle seri yaklaşımlarının C'de kodlanması, tam sayı bölmesi, tür dönüşümleri, operatör önceliği ve birleşme yönü, hata ayıklama, ekran çıktısının süreye etkisi ve tam sayı taşması işlendi. İç içe döngülü bir çözümün $N^2$, önceki terimi kullanan bir çözümün $N$ karmaşıklıkta olduğu toplam sembolüyle gösterildi.

Fibonacci örneğinde sabit bellekli çözüm ile kodlaması kolay ama bellek harcayan dizili çözüm karşılaştırıldı. Armstrong sayılarıyla, basamak sayısına bağlı uzun kod yerine döngüyle genelleştirilmiş çözüm ve `do-while` yapısı gösterildi. Son olarak önermeler mantığına giriş yapıldı; bir önermeyi yanlışlamak için tek bir karşı örneğin yettiği, bilgisayarın bu tür aramalarda kanıt aracı olarak kullanılabildiği $n^2+n+41$ ve Euler sanısı örnekleriyle gösterildi. Kuvvet yarılama ve Fibonacci'nin $\log N$ çözümü, ileride işlenecek özyineleme konusuna bağlanacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
