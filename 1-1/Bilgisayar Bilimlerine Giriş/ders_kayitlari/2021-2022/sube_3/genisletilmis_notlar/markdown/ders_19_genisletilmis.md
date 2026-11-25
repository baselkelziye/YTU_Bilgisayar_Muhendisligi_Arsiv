# Ders 19 Genişletilmiş Notu: Döngü Türleri, Diziler ve Akış Diyagramı Örnekleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Akış Diyagramı Elemanlarının Tekrarı
- 2. Koşullu Döngüler: While, Do-While, Repeat-Until
- 3. Diziler
- 4. Dizilerle Akış Diyagramları
- 5. Üç Sayının Ortancası
- 6. Fibonacci Sayıları
- 7. Tam Bölenler
- 8. Toplamayla Çarpma, Çıkarmayla Bölme
- 9. Saat Kolları Arasındaki Açı
- Örnek Sorular
- Dersin Toparlaması

## 1. Akış Diyagramı Elemanlarının Tekrarı

Ders, önceki haftada başlanan akış diyagramlarının hızlı bir tekrarıyla açılır. Çizimler bir dijital beyaz tahta üzerinde el yazısıyla yapılır (ekrandan, 00:15:00).

Her algoritmanın bir başlangıcı ve bir bitişi vardır. Bunlar "Başla/START" ve "Dur/Bitir/STOP" yazılı, elips ya da üstü ve altı düz, yanları parantez gibi yuvarlak bir şekille gösterilir. Akışlar her zaman yönlü oklarla çizilir.

Girdi için sol üst köşesi çentikli bir dikdörtgen kullanılır; bu şekil eskinin delikli kartını temsil eder. İşlemler (atamalar, hesaplar) düz dikdörtgen kutulara yazılır.

Karar mekanizması için içine uzun mantıksal kontroller yazılabilsin diye uzatılmış bir altıgen kullanılır. Karar kutusunun en az iki çıkışı vardır. Bir kolda hiçbir şey yapılmasa bile o kol (çoğunlukla False kolu) boş geçilerek çizilir ve yönüyle gösterilir; kolların üzerine T ve F yazılır.

Adım sayısı belli döngü üç bölmeli bir dikdörtgenle çizilir (ekrandan, 00:20:00):

- Sol üst bölme: başlangıç ataması, örneğin $i = 1$.
- Sağ üst bölme: her adımdaki artım miktarı, örneğin $1$.
- Alt bölme: son değer, örneğin $N$.

Döngü gövdesindeki işlemler yapıldıktan sonra akış yeniden döngü kutusuna döner. Hoca, kullandığı beyaz tahtanın çizgileri yumuşattığını, oysa akış diyagramlarında mümkün olduğunca düz, köşeli çizgiler ve oklar tercih edildiğini belirtir. Karar kutusunun iki kolu daha sonra birleşip tek bir okla aşağı iner.

Çıktılar, alt kenarı dalgalı kesilmiş bir kağıdı (yazıcı çıktısını) temsil eden şekille gösterilir.

## 2. Koşullu Döngüler: While, Do-While, Repeat-Until

### 2.1 While döngüsü

Adım sayısı belli döngü yerine bir koşula bağlı döngü kurulabilir (ekrandan, 00:20:00). Akış yukarıdan gelir ve önce bir karar kutusunda koşul kontrol edilir, örneğin $J < N$. Koşul doğruysa döngü gövdesine girilir, gövdedeki işlemler yapılır ve akış yeniden koşul kutusuna döner. Koşul yanlışsa akış aşağıdan algoritmanın geri kalanına devam eder.

$N$ genellikle yukarıda okunmuş ya da tanımlanmış sabit bir değerdir. Bu yüzden döngü değişkeni (iteratör) olan $J$, gövdenin içinde bir yerde mutlaka güncellenmelidir: $J = J + 1$, $J = J - k$ ya da başka bir değişiklik. Güncellenmezse koşul hep doğru kalır, döngüden çıkılamaz ve sonsuz döngüye girilir.

While döngüsünde koşul baştan yanlışsa (örneğin $J$, $N$'e eşit ya da büyükse) gövde hiç çalışmaz; akış doğrudan aşağı devam eder.

### 2.2 Do-while döngüsü

Gövdenin en az bir kez çalışması, kontrolün ondan sonra yapılması istenirse do-while kullanılır (ekrandan, 00:25:00). Akış yukarıdan gelir, önce gövdedeki işlemler (ekranda "işlem 1" ve "işlem 2") yapılır, sonra koşul ($J < N$) kontrol edilir. Koşul doğru olduğu sürece akış gövdenin başına (do kısmına) döner ve bütün işlemler yeniden yapılır. Koşul yanlış olunca akış aşağı devam eder.

Burada da koşuldaki değişkenin gövde içinde mutlaka değiştirilmesi gerekir; yoksa sonsuz döngü oluşur ve tasarım algoritma tanımına uymaz.

### 2.3 Repeat-until

Ekranda üç isim yazılıdır: while, do-while, repeat-until (ekrandan, 00:25:00). While ve do-while "koşul doğru olduğu sürece", repeat-until ise "koşul doğru olana kadar" diye okunabilir. Repeat-until Pascal gibi dillerde vardır, C'de yoktur. Bunun nedeni, koşulun değili (NOT) alınıp do-while ile kontrol edildiğinde repeat-until'in zaten elde edilmesidir. Bu yüzden ayrı bir döngü yapısına gerek yoktur; while ve do-while yeterlidir.

### 2.4 Roadrunner ve çakal benzetmesi

İki döngü arasındaki farkı göstermek için hoca çizgi filmdeki çok hızlı koşan kuş (Roadrunner) ile onu yakalamaya çalışan çakalı örnek verir.

- Roadrunner while döngüsü gibi davranır: "Kenarda değilsem koş." Her adımda önce kenarda mıyım diye bakar, değilse bir adım koşar. Uçurumun kenarına geldiğinde koşul yanlış olur ve durur.
- Çakal do-while döngüsü gibi davranır: "Koş, sonra kenarda mıyım diye bak." Kenara geldiği adımda bile önce bir kez daha koşar, sonra kontrol eder. Ama artık çok geçtir; bir adım fazla koştuğu için uçurumdan aşağı düşer.

## 3. Diziler

### 3.1 Dizi kavramı

Dizi, aynı türden elemanların bir arada durduğu veri topluluklarına verilen isimdir (ekrandan, 00:30:00). Örneğin 2, 5, 8, 1, 3 sayıları $a$, $b$, $c$, $d$, $e$ adlı beş ayrı değişkende tutulabilir. Önceki haftaki toplam örneğinde de elemanlar tek tek okunup bir $top$ değişkeninde toplanmıştı.

Ama aynı türden birden fazla değer tutulacak ve bunların üzerinde gezinme, sorgulama gibi işlemler yapılacaksa her biri için ayrı bir değişken adı bilmek gereksizdir. Bunun yerine tek bir kutu (container) yapısı oluşturulur: $A$ dizisi. Bellek organizasyonu açısından gözlerin ardışık adreslerde durduğu düşünülebilir (örneğin 0xf1, 0xf2, 0xf3, 0xf4 gibi birer bayt ilerleyen adresler). Hoca, dizinin bellekte illa ardışık durmak zorunda olmadığını, önemli olanın algoritmada diziyi tek bir bütün olarak görüp kullanabilmek olduğunu söyler.

> **Ek bilgi (derste anlatılmadı):** C dilinde bir dizinin elemanları bellekte bitişik (ardışık) adreslerde tutulur ve her göz eleman türünün boyutu kadar yer kaplar; örneğin `int` dizisinde adresler genellikle 4'er bayt artar. Hocanın "ardışık olmak zorunda değil" sözü, akış diyagramı düzeyindeki soyut dizi kavramı için geçerlidir.

### 3.2 İndis ve notasyon

Dizinin farkı, elemanlara indisle erişilebilmesidir (ekrandan, 00:35:00). $A$ dizisinin gözleri 1, 2, 3, 4, 5 diye numaralanır: birinci gözde 2, ikinci gözde 5, üçüncü gözde 8, sonra 1 ve 3 vardır. Akış diyagramlarında indis köşeli parantezle gösterilir: $A[i]$, dizinin $i$'inci gözünde duran değerdir.

Böylece bütün elemanların toplamı çok kısa bir döngüyle bulunur: $i = 1$'den $5$'e birer birer artan bir for döngüsünde her adımda $top = top + A[i]$ yapılır. İzleme tablosu (ekrandan, 00:35:00):

| $i$ | $A[i]$ |
|---|---|
| 1 | 2 |
| 2 | 5 |
| … | … |
| 5 | 3 |

### 3.3 İndislerin başlangıcı

Akış diyagramlarında kolay okunup anlaşılsın diye indisler $1$'den $N$'e alınır. Gerçeklemede indislerin $1 \ldots N$ olması gerekmez. C programlama dilinde bütün diziler $0$'dan başlar; bu durumda indisler $0, 1, 2, 3, 4$ olur ve döngü $0$'dan $N-1$'e kurulur (ekranda yeşil ile "$0 \to N-1$"). Hangisi seçilirse seçilsin başlangıç ve bitiş değerlerine dikkat etmek gerekir.

Hoca ek bilgi olarak, bazı programlama dillerinde indislerin sayı olmak zorunda olmadığını, enumerasyon ya da kelime karşılıkları olabileceğini söyler. Örneğin gözlere "elma", "armut", "muz" adları verilirse "A dizisinin muz indisindeki eleman" denince 8 değerine erişilir. Bu derste ise akış diyagramlarında $1 \ldots N$, C kodlarında $0 \ldots N-1$ kullanılacaktır.

## 4. Dizilerle Akış Diyagramları

### 4.1 Toplam ve ortalama

Önceki haftada $N$ eleman bir döngü içinde tek tek okunup toplam ve ortalama hesaplanmıştı. Aynı örnek bu kez dizi ile yapılır (ekrandan, 00:40:00 ve 00:45:00).

İlk iş değerleri okumaktır. Önce kaç eleman okunacağı bilinmelidir. Okuma kutusuna "$N, A[N]$" yazılır. Dikkat edilecek en önemli nokta, önce uzunluğun, sonra dizinin elemanlarının okunmasıdır.

Bu kompakt gösterim aslında şunun kısaltmasıdır: $N$ okunur, sonra $i = 1 \ldots N$ birer birer artan bir döngüde her adımda $A[i]$ okunur. İkisi aynı şeydir; ama tek kutuluk gösterim akışın uzun yer kaplamaması için daha kullanışlıdır.

Akışın devamı:

```text
START
Oku: N, A[N]
top = 0, ort = 0
for i = 1 .. N (artım 1):
    top = top + A[i]
ort = top / N
Yaz: top, ort
STOP
```

$N$'in sıfır olmaması gerektiği önceki haftada konuşulmuştu. Burada gerekiyorsa bir kontrol eklenir; ya da girdinin $N > 0$ olduğu varsayılırsa bu kontrole gerek kalmaz. Önceki haftadaki çözümden farkı, döngüde her adımda yeni bir değer okumak yerine dizinin $i$'inci gözündeki değerin kullanılmasıdır.

### 4.2 Tek ve çift toplamları ayrı tutmak

Hoca bir değişiklik sorar: Okunan dizide çift sayıları ve tek sayıları ayrı toplamak istesek ne yapardık? Ortalama bırakılır; iki toplam değişkeni gerekir: $tt = 0$ ve $tc = 0$ (ekrandan, 00:45:00).

Döngü gövdesi güncellenir. Her adımda önce mod 2 kontrolü yapılır (mod işlemi $\%$ işaretiyle de yazılabilir):

- Tek ve çift indisleri ayrı toplamak isteniyorsa $i \bmod 2 = 0$ kontrol edilir.
- Tek ve çift değerleri ayrı toplamak isteniyorsa $A[i] \bmod 2 = 0$ kontrol edilir.

Kalan sıfırsa çifttir ve $tc = tc + A[i]$; değilse tektir ve $tt = tt + A[i]$ yapılır. İki kol birleşir ve akış for döngüsüne geri döner.

**Soru:** Mod 2 kontrolünde sonuç 0 ise çift tarafı, 1 ise tek tarafı güncelleriz, değil mi? **Cevap:** Evet, aynen öyle; ekrandaki algoritma da budur. Toplama yapıldığı için her kolda eklenen değer $A[i]$'dir.

### 4.3 Ardışık iki elemanın toplamı ve taşma

Bir öğrenci $A[i+1]$ gibi bir ifade yazınca hoca bunu bir örneğe çevirir: $N$ elemanlı $A$ dizisi okunur ve takip eden iki gözdeki değerlerin toplamı ekrana yazdırılır (ekrandan, 00:50:00).

```text
START
Oku: N, A[N]
for i = 1 .. N (artım 1):
    Yaz: A[i] + A[i+1]
STOP
```

Hoca hatayı bilerek yapmıştır. Analiz için $N = 3$, $A = [2, 4, 6]$ alınır. Döngüde $i$ değeri 1, 2, 3 olur; 4 olunca döngüden çıkılır.

- $i = 1$: $A[1] + A[2] = 2 + 4 = 6$ yazılır.
- $i = 2$: $A[2] + A[3] = 4 + 6 = 10$ yazılır.
- $i = 3$: $A[3] + A[4]$ hesaplanmaya çalışılır, ama $A[4]$ tanımlı değildir.

Dizinin toplam eleman sayısının dışına taşılmıştır. Hoca, bunun ileride "array index out of bounds" hatası olarak öğrenileceğini söyler. Düzeltme, döngünün $N$ yerine $N-1$'e kadar dönmesidir: $N = 3$ iken $i$ yalnız 1 ve 2 olur, ekrana 6 ve 10 yazılır ve döngü tamamlanır. Bunun için algoritmanın değerlerle analiz edilmesi ve uç değerlerin tekrar tekrar kontrol edilmesi önemlidir.

C gibi dillerde, özellikle dizi bellekte dinamik olarak ayrıldığında, taşma kontrolünün sorumluluğu tamamen programcıdadır. Olmayan dizi gözü aslında dizi için ayrılan bellekten bir sonraki bellek gözüdür. Orada daha önceden kalmış, örneğin $-312$ gibi bir değer varsa $6 + (-312) = -306$ gibi alakasız, yanlış bir sonuç ekranda görülür. Esnek ve kontrolün programcıya bırakıldığı dillerde hata alınmadan sonuç elde edilebilir, ama algoritma yanlış çalışmıştır.

Taşma iki yönlü olabilir. Döngü $1$'den başlarken $A[i-1]$ yazılsaydı soldan taşma olurdu (sıfırıncı göz akışta tanımlı değil).

**Soru:** $A[0] = 0$ diye bir şey yazmamalı mıyız? **Cevap:** Yazabilirsin; C'de indisler $0$'dan başlar ve o, dizinin ilk elemanı olur. Ama akış $1$'den başlıyorsa sıfırıncı göz akışta görünmeyeceği için yine hata alınabilir. Her başlangıç ve son değer kontrolünde dizide taşılıp taşılmadığına dikkat etmek gerekir.

> **Hocanın vurgusu:** Uç değerleri mutlaka, tekrar tekrar kontrol edin; dizilerde taşıyor muyum diye dikkatle bakın.

## 5. Üç Sayının Ortancası

### 5.1 Problem

Üç sayı ayrı değişkenlerde okunur: $a$, $b$, $c$. Bu üç değerin ortancası ekrana yazdırılacaktır (ekrandan, 00:55:00 ve 01:00:00). Örnekler:

- $3, 5, 8$: ortanca 5.
- $8, 3, 5$: ortanca 5 (sıralı verilmek zorunda değil).
- $5, 8, 3$: ortanca 5.
- $-2, 0, 2$: ortanca 0.
- $3, 3, 8$: ortanca 3; iki 3'ten hangisinin söylendiğinin önemi yoktur, çünkü değerleri aynıdır. Üçü de eşitse herhangi biri yeterlidir.

Hoca dizi kullanılmasını ve sayıları sıralayıp ortadakini seçmeyi istemez; sayı sayısı artmayacaktır, yalnız karşılaştırmalarla ortanca bulunacaktır. En büyük ve en küçüğü ayrı ayrı bulmak da istenmez, yalnız ortanca istenir.

### 5.2 İç içe kararlarla çözüm

Düz mantık şudur: $a$, $b$'den küçükse ve $a$, $c$'den büyükse $a$ ikisinin arasındadır, yani ortancadır. Akış (ekrandan, 01:05:00):

```text
START
Oku: a, b, c
a < b ?
  T: a >= c ?
       T: ort = a
       F: b < c ?
            T: ort = b
            F: ort = c
  F: a < c ?
       T: ort = a
       F: b > c ?
            T: ort = b
            F: ort = c
Yaz: ort
STOP
```

Adım adım düşünce:

- $a < b$ doğru, $a \ge c$ doğru: $c \le a < b$, ortanca $a$. İlk çizimde $a > c$ yazılmış, $8, 3, 3$ gibi eşitlik durumları düşünülünce $a \ge c$ yapılmıştır; böylece $a = c$ iken de doğru sonuca gidilir.
- $a < b$ doğru, $a \ge c$ yanlış: $a$ hem $b$'den hem $c$'den küçüktür, yani en küçüktür. $b$ ile $c$ karşılaştırılır; $b < c$ ise ortanca $b$, değilse $c$. Burada eşitlik kontrolü gerekmez: eşitlik konursa ortanca $b$, konmazsa $c$ bulunur, ama değerleri aynıdır.
- $a < b$ yanlış ($b \le a$), $a < c$ doğru: $b \le a < c$, ortanca $a$.
- $a < b$ yanlış, $a < c$ yanlış: $a$ en büyüktür. $b > c$ ise ortanca $b$, değilse $c$.

Böylece iç içe if'ler kurulmuş olur. Başlangıç $a$ ve $b$ yerine $b$ ve $c$ ile de yapılabilirdi; o zaman alttaki kontroller ona göre değişirdi.

> **Hocanın vurgusu:** Koşulların içinde alt koşullar istenildiği kadar dallanabilir; ama akışta oklar yönlüdür ve bu kararların içinde bir döngü mekanizması yer almaz. Bir kolun ucundan yukarı geri ok çekip döngü kurulamaz; yapılar blok halinde, iç içe (nested) kurulur.

Bir öğrenci "ve" işleciyle ($a < b$ ve $a > c$ gibi) çözmeyi önerdi; hoca bunun da bir yol olduğunu, akış tasarlamada tek bir doğru yol olmadığını söyler. Bu çözüm temel olsun ve iç içe kararları açıkça göstersin diye seçilmiştir, en iyi yol değildir; çok sayıda karşılaştırma yapılır. Başka bir öğrenci önce $a$'yı ortanca kabul edip $b$ ve $c$ ile karşılaştırmayı önerdi; hoca bu durumda $b$ ile $c$'nin aynı anda karşılaştırılması gerekeceğini belirtir. Kararlar "ve" ile birleştirilse de if sayısından pek kazanç olmaz.

### 5.3 Ortalamaya en yakın olan

Bir öğrenci üç değerin ortalamasını bulup ortalamaya en yakın olanı seçmeyi önerdi: üçünü topla, üçe böl, ortalamaya olan farklara (mutlak değerlerine) bak. Hoca, bunun da sonunda yine benzer karşılaştırmalar gerektirdiğini söyler. Aradan sonra gelen soruya da bir sayı çok büyük olduğunda ortalamanın o tarafa kayacağını, bu yüzden yaklaşımın yanlış olacağını söyleyerek cevap verir ve konuya takılmamayı önerir.

> **Ders sonrası not:** Hoca bu yaklaşımın yanlış olduğunu söyledi; oysa $a \le b \le c$ ve $m = (a+b+c)/3$ için ortanca $b$ her zaman ortalamaya en yakın (ya da eşit yakın) sayıdır. $b \ge m$ ise $c \ge b$ olduğundan $c$ daha uzaktır ve $(b-m) - (m-a) = (a+b-2c)/3 \le 0$ olduğundan $a$ da daha yakın değildir; $b < m$ durumu simetriktir. Python ile $-20 \ldots 20$ aralığındaki bütün üçlülerde denendi, karşı örnek çıkmadı. Yine de bu yol bölme, mutlak değer ve karşılaştırma gerektirdiği için daha sade değildir.

### 5.4 Farklarla çözüm

Öğrencinin farklara bakma fikrinden yola çıkılır. İkili karşılaştırmalar yapılıyorsa ikililer arasındaki farklar bir anlam taşımalıdır (ekrandan, 01:10:00 ve 01:15:00):

$$x = a - b, \quad y = b - c, \quad z = c - a$$

Farkın işareti hangisinin büyük olduğunu sayısal bir artı/eksi bilgisine çevirir: $a > b$ ise $x$ pozitif, $a < b$ ise negatiftir. İki farkın çarpımına bakmak, iki büyüklük ilişkisini birlikte ("ve" ile) test etmek demektir.

- $x \cdot y > 0$ ise iki fark aynı işaretlidir: ya $a > b > c$ ya da $a < b < c$. Her iki durumda ortanca $b$'dir.
- Değilse ortanca $a$ ya da $c$'dir. Bu, $z$'nin işaretine ya da $x \cdot z$ çarpımına bakılarak ayırt edilir.

Ekranda çizilen akış:

```text
START
Oku: a, b, c
x = a - b
y = b - c
z = c - a
x*y > 0 ?
  T: ort = b
  F: x*z > 0 ?
       T: ort = c
       F: ort = a
Yaz: ort
STOP
```

Böylece yalnız iki if ile aynı iş yapılmış olur; karşılığında 3 fazla değişken ($x, y, z$) kullanılır.

Hoca analiz için şu girdilerin denenmesini ister (ekrandan, 01:15:00): $3, 5, 8$'in bütün sıralamaları ($3\,5\,8$, $5\,3\,8$, $3\,8\,5$, $8\,3\,5$, $5\,8\,3$, $8\,5\,3$), iki negatif sayılı $-2, -3, 1$, sıfırlı $-5, 0, 5$ ve hepsi eşit $0, 0, 0$. Hepsi eşitse bütün farklar sıfırdır; iki karar da yanlış olur ve ortanca $a$ denir, bu da doğrudur.

Derste izlenen örnek $-2, 2, -2$:

- $x = -2 - 2 = -4$
- $y = 2 - (-2) = 4$
- $z = -2 - (-2) = 0$
- $x \cdot y = -16 < 0$, False kolu.
- $x \cdot z = 0$, $0 > 0$ yanlış, $ort = a = -2$. Doğru sonuç.

> **Ders sonrası not:** Ekrandaki akışta ikinci kararın kolları ters yazılmıştır. $x \cdot z > 0$ ise $a-b$ ile $c-a$ aynı işaretlidir, yani $b < a < c$ ya da $c < a < b$; bu durumda ortanca $c$ değil $a$'dır. Örneğin $5, 3, 8$ için $x = 2$, $y = -5$, $z = 3$; $x \cdot y < 0$, $x \cdot z = 6 > 0$ ve akış $8$ yazdırır, doğrusu $5$'tir. Derste izlenen $-2, 2, -2$ örneğinde $a = c$ olduğu için hata görünmedi. Python ile denendiğinde şu sıra bütün durumlarda (eşitlikler dahil) doğru çalıştı: $x \cdot y \ge 0$ ise $ort = b$; değilse $x \cdot z \ge 0$ ise $ort = a$; değilse $ort = c$. Eşitlik ($\ge$) gereklidir; yalnız kollar düzeltilip $>$ bırakılırsa $3, 3, 8$ girdisinde $c = 8$ seçilir.

Hoca bu örneği farklı düşünme biçimlerine alışmak için verdiğini söyler. Kararları "ve/veya" ile birleştirerek de tasarım yapılabilir, ama okunabilirlik ve yalınlık azalır. Karar mekanizmaları karmaşıklaştıkça analiz ve test de zorlaşır.

### 5.5 Fazla değişken mi, fazla if mi?

**Soru:** Fazla değişken kullanmak mı daha maliyetlidir, fazla if yapmak mı? **Cevap:** Kesin cevabı yoktur. Önceki haftada algoritmaların başarımını karşılaştırırken konuşulduğu gibi, "iyi" kavramı hedefe göre değişir.

- Hız önemliyse her karar ve her dallanma yavaşlatır; ikinci yöntem (daha fazla değişken, daha az karar) tercih edilebilir.
- Gömülü bir sistemde bellek çok kısıtlı ve değerliyse, cevap beş saniye yerine on saniyede gelse bile az bellek kullanmak önemlidir; o zaman fazla değişken kullanmaktan kaçınılır.

Bu derste ise öncelik, olabildiğince basit, kolay okunan ve sade akış diyagramları oluşturmaktır.

## 6. Fibonacci Sayıları

### 6.1 Tanım

Bu örnek, değerlerin değişkenler arasında aktarılmasını göstermek için seçilmiştir (ekrandan, 01:35:00):

$$f_1 = 1, \quad f_2 = 1, \quad f_n = f_{n-2} + f_{n-1}, \quad n > 2$$

Hoca "$n > 2$" kısmının altını kırmızıyla çizer: Bu, girdi uzayının bir kısıtı olarak baştan verilmiştir. Böylece akışın içinde "$N$ 2'den küçükse hata vermeli miyim?" gibi bir kontrol istenmez. Çözüm dizi kullanarak ya da en az sayıda değişkenle yapılabilir; ikisi ayrı ayrı gösterilir.

### 6.2 Değişkenlerle: N'e kadar olan Fibonacci sayıları

Verilen bir sayıya ($N$) kadar olan bütün Fibonacci sayıları yazdırılacaktır (ekrandan, 01:40:00).

```text
START
Oku: N
a = 1
b = 1
Yaz: a, b
c = a + b
c <= N olduğu sürece:
    Yaz: c
    a = b
    b = c
    c = a + b
STOP
```

$a$ ve $b$, $f_1$ ve $f_2$'dir; $n > 2$ kısıtı verildiği için ayrıca kontrol edilmeden doğrudan yazdırılırlar. Sıradaki sayı $c$'de tutulur; bu yüzden koşullu döngünün kontrolü $c$ üzerinden yapılır. Her yeni eleman için yalnız önceki iki değer gerekir, üç önceki değeri tutmaya gerek yoktur. Bu yüzden bir kaydırma işlemi yapılır: $a = b$, $b = c$, sonra yeni $c = a + b$.

$a = b$ ilk başta kafa karıştırıcı gelebilir; bu bir atamadır: "$b$'nin bellek gözündeki değeri al, $a$'nın gözüne kopyala" demektir.

Hoca bundan sonra "test" yerine "analiz" kelimesini kullanacağını söyler. Bu ders giriş seviyesinde olduğu için gerçek performans analizleri yapılmayacaktır; "algoritmanın analizini yapınız" denince anlaşılması gereken, akış oluşturulduktan sonra değişkenlerin aldığı değerlerle akışın doğru işlediğini, doğru sonuç verdiğini ve durduğunu göstermektir.

$N = 20$ için analiz:

| Adım | $a$ | $b$ | $c$ | $c \le 20$ | Ekran |
|---|---|---|---|---|---|
| Başlangıç | 1 | 1 | 2 | — | 1, 1 |
| 1 | 1 | 2 | 3 | $2 \le 20$ doğru | 2 |
| 2 | 2 | 3 | 5 | $3 \le 20$ doğru | 3 |
| 3 | 3 | 5 | 8 | $5 \le 20$ doğru | 5 |
| 4 | 5 | 8 | 13 | $8 \le 20$ doğru | 8 |
| 5 | 8 | 13 | 21 | $13 \le 20$ doğru | 13 |
| 6 | — | — | — | $21 \le 20$ yanlış | dur |

(Her satırda önce $c$ kontrol edilip yazdırılır, sonra kaydırma yapılır; tablo satırındaki $a, b, c$ kaydırmadan sonraki değerlerdir.)

Ekran çıktısı: 1, 1, 2, 3, 5, 8, 13. 21 yazdırılmaz, çünkü 20'ye kadar olanlar istenmiştir. Python ile kontrol edildi.

### 6.3 Diziyle: N tane Fibonacci sayısı

Bu kez adım sayısı bellidir: $N$'e kadar olanlar değil, $N$ tane Fibonacci sayısı hesaplanır ve dizide tutulur (ekrandan, 01:45:00).

```text
START
Oku: N
A[1] = 1
A[2] = 1
for i = 3 .. N (artım 1):
    A[i] = A[i-2] + A[i-1]
    Yaz: A[i]
STOP
```

Hoca döngüyü önce "1'den $N$'e" diye başlatıp hemen düzeltir: $A[1]$ ve $A[2]$ zaten atandığı için döngü $3$'ten başlar. $N = 6$ için:

- $i = 3$: $A[3] = A[1] + A[2] = 1 + 1 = 2$
- $i = 4$: $A[4] = A[2] + A[3] = 1 + 2 = 3$
- $i = 5$: $A[5] = A[3] + A[4] = 2 + 3 = 5$
- $i = 6$: $A[6] = A[4] + A[5] = 3 + 5 = 8$

Dizi: 1, 1, 2, 3, 5, 8. Burada da dikkat edilecek şey başlangıç ve son değerlerin doğru seçilmesidir. Böylece Fibonacci sayıları hem dizisiz bir while döngüsüyle (adım sayısı belirsiz) hem dizili bir for döngüsüyle (adım sayısı belli) hesaplanmış olur.

## 7. Tam Bölenler

Bir $N$ sayısının $1$'den $N$'e kadar olan tam bölenleri yazdırılacaktır (ekrandan, 01:50:00 ve 01:55:00). Bir öğrenci asal çarpanlara ayırmayı önerdi; başka bir öğrenci doğrudan deneme yöntemini yazdı. Hoca "biraz kaba" bir yöntemle, $1$'den $N$'e kadar bütün sayıları tek tek dener: Bir $x$ sayısı $N$'i kalansız bölüyorsa tam bölendir ve yazdırılır.

Öğrenci for ile yazmıştı; hoca while ile yapar (for ile de yapılabilir):

```text
START
Oku: N
x = 1
x <= N olduğu sürece:
    N mod x = 0 ?
      T: Yaz: x
      F: (bir şey yapma)
    x = x + 1
STOP
```

Hoca iki hataya dikkat çeker:

- Bazı öğrenciler kararın False kolunu döngünün dışına, doğrudan aşağıya bağlamıştı. Bu kesinlikle yanlıştır; iki kol birleşip döngü bloğu tamamlanmalı ve akış koşul kutusuna dönmelidir.
- Hoca ilk çizimde $x = x + 1$ adımını bilerek koymaz ve bir öğrenci "$x$'i artırmadık" diyerek hatayı yakalar. Döngü koşulundaki $x$ hiç değişmediği için $N = 5$ için akış sürekli $5 \bmod 1 = 0$ kontrolünü yapar, sonsuza kadar 1 yazdırır. Artım (ekranda kırmızıyla) eklenince döngü tamamlanır; $x = N$ olduğunda da eşitlikten dolayı $N$ yazdırılır ve durulur.

Öğrencilerden gelen iyileştirme önerisi: $N/2$'den büyük ve $N$'den küçük bir sayı $N$'i tam bölemez. Bu yüzden döngü $N/2$'ye kadar gidip ardından $N$'in kendisi ayrıca yazdırılabilir; $N$ tek ise yuvarlama (taban) ile yapılır. Hoca, böyle ince noktaları görerek daha az iş yapan, daha hızlı çalışan iyileştirmelerin her zaman yapılabileceğini söyler.

## 8. Toplamayla Çarpma, Çıkarmayla Bölme

### 8.1 Toplamayla çarpma

Çarpma işleci olmadığını varsayarak $x \cdot y$ toplamalarla hesaplanır (ekrandan, 02:00:00). $3 \times 2$, iki tane 3'ü toplamak ($3 + 3$) demektir. Yani $y$ tane $x$ toplanır; toplama sayısı bellidir.

```text
START
Oku: x, y
c = 0
for i = 1 .. y (artım 1):
    c = c + x
Yaz: c
STOP
```

### 8.2 Çıkarmayla bölme

Bölmede tam bölünme ve bölünmeme durumları için kalan da gerekir. Fikir, $x$'ten çıkarılabildiği kadar $y$ çıkarmak ve kaç kez çıkarıldığını saymaktır. Sayı bölümü verir; çıkarılamayan kısım $x$'te kalır ve kalandır (ekrandan, 02:00:00).

$10 / 3$:

- $10 - 3 = 7$ (1 kez)
- $7 - 3 = 4$ (2 kez)
- $4 - 3 = 1$ (3 kez)
- $1$'den $3$ çıkarılamaz. Bölüm 3, kalan 1.

```text
START
Oku: x, y
b = 0
x >= y olduğu sürece:
    x = x - y
    b = b + 1
Yaz: b, x
STOP
```

İlk değer ataması unutulmamalıdır: bölüm bir sayaçtır ve $b = 0$ ile başlar. Döngüden sonra $b$ (bölüm) ve $x$ (kalan) yazdırılır.

**Soru (öğrenci):** $x = 10$, $y = 9$ iken bir fazla mı artırıyoruz? **Cevap:** Birlikte denenir: $10 \ge 9$ doğru, $x = 1$, $b = 1$; $1 \ge 9$ yanlış, döngüden çıkılır. Bölüm 1, kalan 1; doğrudur. Hoca, sürekli sorgulamanın istediği en önemli şey olduğunu söyler: uç noktaları kontrol etmek, "bu döngüyü böyle yazmalı mıyım, bu atama gerekli mi, değişkeni başka türlü tutabilir miyim?" diye düşünmek.

> **Ek bilgi (derste anlatılmadı):** Bu iki akış $x$ ve $y$'nin negatif olmayan tam sayılar olduğunu varsayar. Bölmede $y = 0$ verilirse $x \ge 0$ koşulu hep doğru kalır ve sonsuz döngü oluşur; bu yüzden gerçekte girdi kısıtı olarak $y > 0$ verilmeli ya da kontrol edilmelidir.

## 9. Saat Kolları Arasındaki Açı

Son örnek, hocanın daha önce bir sınav sorusu olarak tasarladığı bir problemdir. 12'lik bir analog saatte akrep ile yelkovan arasındaki açıyı hesaplayan algoritmanın akış diyagramı istenir (ekrandan, 02:05:00 ve 02:10:00).

Kısıtlar: saat $H$ 1 ile 12, dakika $M$ 0 ile 59 arasında değer alır.

Hesap:

- Kadran $360°$'dir. 12 saat olduğundan akrep bir saatte $360 / 12 = 30°$ tarar.
- Akrep bu $30°$'yi 60 dakikada yürür; saat değişmeden dakika ilerlerken de yavaş yavaş ilerler. Dakikada $30 / 60 = 0.5°$ ilerler.
- Akrebin toplam açısı: saat 60 dakika demek olduğu için $H \cdot 60$, üzerine geçen dakika $M$ eklenir; örneğin 20 dakika geçmişse akrep iki saat çizgisi arasının üçte birini, yani $10°$ ilerlemiş olur:

$$Ha = (H \cdot 60 + M) \cdot 0.5$$

- Yelkovan bir tam turu (60 dakikayı) $360°$'de yapar, dakikada $360/60 = 6°$ ilerler. Aradaki açı, yelkovanın açısından akrebin açısı çıkarılarak bulunur:

$$a = M \cdot 6 - Ha$$

Hoca, ayrı bir $Ma$ değişkeni tanımlayıp $a = Ma - Ha$ da denebileceğini, burada bir değişken az kullanmak için doğrudan yazdığını söyler.

Akış (ekrandan, 02:15:00):

```text
START
Oku: H, M
Ha = (H * 60 + M) * 0.5
a  = M * 6 - Ha
a < 0 ?
  T: a = -1 * a
a < 360 - a ?
  T: Yaz: a
  F: Yaz: 360 - a
STOP
```

Fark negatif çıkabileceği için önce pozitife çevrilir (mutlak değer). Sonra iki koldan hangisinin söyleneceğine karar verilir: hesaplanan açı ya iç (dar) taraf ya da dış taraf olabilir; doğal olarak küçük olan söylenir. Toplamın $360°$ olduğu bilindiğinden $a$ ile $360 - a$ karşılaştırılır. Hoca bu kontrolü sözlü anlatırken önce "açı 360'tan küçükse" der, sonra "180'den küçük de diyebilirdik" diye düzeltir; ekrandaki $a < 360 - a$ kontrolü $a < 180$ ile aynıdır.

## Örnek Sorular

**1. Tek ve çift toplamlar** (derste sözlü, 00:43:31)

$N$ elemanlı bir $A$ dizisinde tek ve çift sayıları ayrı ayrı toplayan akışta nasıl bir değişiklik gerekir?

> **Çözüm:** İki toplam değişkeni $tt = 0$, $tc = 0$ alınır. Döngüde $A[i] \bmod 2 = 0$ ise $tc = tc + A[i]$, değilse $tt = tt + A[i]$ yapılır. Tek ve çift indisler isteniyorsa kontrol $i \bmod 2 = 0$ olur (ekrandan, 00:45:00).

**2. Ardışık iki elemanın toplamı** (ekrandan, 00:50:00)

$i = 1 \ldots N$ için $A[i] + A[i+1]$ yazdıran akış $N = 3$, $A = [2, 4, 6]$ ile nasıl çalışır, hata nerededir?

> **Çözüm:** $i = 1$'de 6, $i = 2$'de 10 yazılır; $i = 3$'te tanımsız $A[4]$'e erişilir (dizi sınırı dışına taşma). Döngü $N-1$'e kadar dönmelidir.

**3. Üç sayının ortancası** (ekrandan, 00:55:00 ve 01:05:00)

$a, b, c$ okunup ortancası yazdırılsın; dizi ve sıralama kullanılmasın. Örnekler: $3, 5, 8$; $8, 3, 5$; $5, 8, 3$; $-2, 0, 2$; $3, 3, 8$.

> **Çözüm:** Bölüm 5.2'deki iç içe kararlı akış (python ile bütün durumlarda doğrulandı) ya da Bölüm 5.4'teki farklarla çözüm (ders sonrası nottaki düzeltmeyle).

**4. Farklarla ortancayı izleme** (ekrandan, 01:15:00)

$x = a-b$, $y = b-c$, $z = c-a$ akışını $-2, 2, -2$ girdisiyle izleyin.

> **Çözüm:** $x = -4$, $y = 4$, $z = 0$; $x \cdot y < 0$; $x \cdot z = 0$; ortanca $a = -2$.

**5. N'e kadar Fibonacci sayıları** (ekrandan, 01:40:00)

Dizi kullanmadan, $N = 20$'ye kadar olan Fibonacci sayılarını yazdıran akışı çizip analiz edin.

> **Çözüm:** Bölüm 6.2. Çıktı: 1, 1, 2, 3, 5, 8, 13.

**6. N tane Fibonacci sayısı, diziyle** (ekrandan, 01:45:00)

$N = 6$ için dizideki değerler nelerdir?

> **Çözüm:** $A = [1, 1, 2, 3, 5, 8]$.

**7. Tam bölenler** (ekrandan, 01:55:00)

$1 \ldots N$ arasındaki tam bölenleri yazdıran while akışında ilk çizimdeki hata nedir?

> **Çözüm:** $x$ hiç artırılmadığı için sonsuz döngü oluşur; döngü gövdesine $x = x + 1$ eklenmelidir. İyileştirme: $N/2$'ye kadar deneyip $N$'i ayrıca yazdırmak.

**8. Toplamayla çarpma** (ekrandan, 02:00:00)

Çarpma işleci olmadan $x \cdot y$ nasıl hesaplanır?

> **Çözüm:** $c = 0$; $i = 1 \ldots y$ için $c = c + x$; $c$ yazdırılır.

**9. Çıkarmayla bölme** (ekrandan, 02:00:00; öğrenci sorusu, 02:02:15)

$x / y$ için bölüm ve kalanı çıkarma ile bulan akışı $10/3$ ve $10/9$ için izleyin.

> **Çözüm:** $10/3$: bölüm 3, kalan 1. $10/9$: bölüm 1, kalan 1.

**10. Saat kolları arasındaki açı** (ekrandan, 02:05:00 ve 02:15:00)

Verilen bir saat ($H$: 1–12, $M$: 0–59) için akrep ile yelkovan arasındaki açıyı hesaplayan akışı oluşturun. Hoca kadranda yaklaşık 3:55'i (15:55) gösterdi.

> **Çözüm:** Akış Bölüm 9'dadır.

> **Çözüm (derste verilmedi):** 3:55 için $Ha = (3 \cdot 60 + 55) \cdot 0.5 = 117.5$, $a = 55 \cdot 6 - 117.5 = 212.5$; $a \ge 0$; $212.5 < 147.5$ yanlış olduğundan $360 - 212.5 = 147.5°$ yazdırılır. Python ile kontrol edildi; aynı akış 12:00 için $0°$, 12:30 için $165°$ verir.

## Dersin Toparlaması

Bu derste akış diyagramı elemanları tekrar edildikten sonra koşullu döngü türleri ayrıştırıldı: while önce koşulu kontrol eder ve gövde hiç çalışmayabilir; do-while gövdeyi en az bir kez çalıştırır; repeat-until ise koşulun değiliyle kurulan bir do-while'dır. Her koşullu döngüde koşul değişkeninin gövde içinde güncellenmesi sonsuz döngüden kaçınmanın şartıdır. Ardından dizi kavramı, $A[i]$ notasyonu, akıştaki $1 \ldots N$ ile C'deki $0 \ldots N-1$ indisleri ve dizi sınırlarının dışına taşmanın tehlikesi anlatıldı.

Dersin ikinci yarısı algoritmik düşünmeyi geliştiren örneklere ayrıldı: üç sayının ortancası (iç içe kararlarla ve fark çarpımlarının işaretiyle), Fibonacci sayıları (kaydırmalı değişkenlerle ve diziyle), tam bölenler, toplamayla çarpma, çıkarmayla bölme ve saat kolları arasındaki açı. Ortak mesaj, bir problemin tek bir doğru çözümü olmadığı, hedefe (hız, bellek, okunabilirlik) göre tasarım seçilmesi ve her akışın uç değerlerle analiz edilmesi gerektiğidir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
