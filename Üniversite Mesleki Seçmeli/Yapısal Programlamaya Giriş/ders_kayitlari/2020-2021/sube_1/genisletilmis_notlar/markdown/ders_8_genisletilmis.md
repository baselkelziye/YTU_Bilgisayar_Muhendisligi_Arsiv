# Ders 8 Genişletilmiş Notu: Dizi Algoritmaları: Birleştirme, Arama, Sayma ve Doğrusal Zamanlı Sıralama

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. İki Sıralı Diziyi Birleştirme
- 2. Dizide Eleman Arama: Doğrusal ve İkili Arama
- 3. Bir Dizinin Sıralı Olup Olmadığını Bulma
- 4. Dizi Sınırı Dışına Erişim Neden Tehlikelidir?
- 5. Dizideki Değerlerin Sayısını Bulma
- 6. Seçim Sistemleri: Sayma Fikrinin Uygulamaları
- 7. Linear Sort with Counting
- 8. Var/Yok İşaretleyerek Doğrusal Zamanlı Sıralama
- 9. Karmaşıklıkta Sabit Katsayılar
- Örnek Sorular

## 1. İki Sıralı Diziyi Birleştirme

Ders, önceki derslerde olduğu gibi akış diyagramlarının elle çizildiği bir tahta üzerinde işlendi. Bu derste hep dizilerle ilgili problemler ele alındı ve her problemde yalnız çalışan bir çözüm değil, daha az işlem yapan bir çözüm arandı.

### 1.1 Problem

Elimizde iki dizi var: $L1$ dizisi $m$ elemanlı, $L2$ dizisi $n$ elemanlı. Eleman sayıları farklı olabilir. İki dizi de kendi içinde küçükten büyüğe sıralıdır. Amaç, $m+n$ elemanlı ve yine küçükten büyüğe sıralı yeni bir $L3$ dizisi elde etmektir (ekrandan, 00:15:00).

Tahtadaki örnek (ekrandan, 00:15:00):

- $L1 = 1, 3, 6, 9$
- $L2 = 2, 4, 8, 10, 12$
- Beklenen sonuç: $L3 = 1, 2, 3, 4, 6, 8, 9, 10, 12$

### 1.2 Kötü çözüm: kopyala ve sırala

İlk akla gelen yol, önce $L1$'i $L3$'e kopyalamak, bittiği yerden sonra $L2$'yi kopyalamak ve ardından $L3$'ü kendi içinde sıralamaktır. Bu çalışır ama maliyetlidir. Hoca $k = m+n$ diyerek, quicksort ya da merge sort gibi en hızlı sıralama algoritmalarının bile $k$ elemanlı bir diziyi $k \log_2 k$ işlemde sıraladığını söyledi. Oysa diziler zaten sıralı olduğu için bu bilgiden yararlanıp işi $k$ adımda bitirmek isteniyor.

> **Ek bilgi (derste anlatılmadı):** Merge sort her durumda $k \log_2 k$ mertebesinde çalışır. Quicksort ise ortalamada $k \log_2 k$ mertebesindedir; kötü pivot seçimlerinde en kötü durumu $k^2$ mertebesine çıkabilir.

### 1.3 İki indisle birleştirme

Birleşik dizi kurulurken bazen $L1$'den, bazen $L2$'den eleman alınacaktır. Hangi diziden nereye kadar alındığını bilmek için iki indis tutulur: $L1$ için $i$, $L2$ için $j$. Her adımda $L1[i]$ ile $L2[j]$ karşılaştırılır. Küçük olan $L3$'e yazılır ve yalnız o dizinin indisi bir artırılır.

Örnek üzerinde ilk adımlar:

- $i = 1$, $j = 1$: $L1[1] = 1$ ile $L2[1] = 2$ karşılaştırılır. 1 küçüktür, $L3$'e 1 yazılır, $i = 2$ olur.
- $L1[2] = 3$ ile $L2[1] = 2$ karşılaştırılır. Bu kez 2 küçüktür, $L3$'e 2 yazılır, $j = 2$ olur.
- $L1[2] = 3$ ile $L2[2] = 4$: 3 yazılır. Sonra 4, sonra 6 yazılır ve iş böyle sürer.

Döngünün kaç kez döneceği bellidir: her adımda $L3$'e tam bir eleman yazıldığı için $m+n$ kez döner. Bir öğrenci de bunu "ikisinin toplamı kadar" diye cevapladı. Bu yüzden `for` döngüsü kullanılır.

Akış diyagramı (ekrandan, 00:15:00 ve 00:20:00):

```text
START
oku m, n
i = 1'den m'ye kadar: oku L1[i]
i = 1'den n'ye kadar: oku L2[i]
i = 1, j = 1
k = 1'den m+n'ye kadar, birer birer:
    L1[i] < L2[j] ?
        T: L3[k] = L1[i];  i = i + 1
        F: L3[k] = L2[j];  j = j + 1
STOP
```

### 1.4 Dizilerden biri bitince ne olur?

Hoca öğrencilerden algoritmayı küçük bir örnekte adım adım denemelerini, özellikle sona yaklaşırken bir sorun çıkıp çıkmayacağına bakmalarını istedi. Bir öğrenci sorunu buldu: kısa dizi bittiğinde, örneğin $L1$'in 4 elemanı tükendiğinde, algoritma $L1[5]$'e bakar. Orada ne olduğu bilinmediği için karşılaştırma anlamsız olur.

Hocanın çözümü dizilerin sonuna birer **sonlandırıcı** (sentinel) eklemektir: dizideki bütün elemanlardan büyük bir sayı. Tahtada $L1[m+1] = 10^6$ ve $L2[n+1] = 10^6$ yazıldı (ekrandan, 00:20:00). Bir dizi bitince onun sonundaki dev sayı hiçbir zaman küçük olarak seçilmez, diğer dizinin elemanları sırayla alınmaya devam eder.

**Soru:** Böylece oluşan dizinin son elemanı da $10^6$ olmaz mı, sonradan çıkarmak gerekmez mi? **Cevap:** Hayır. Döngü $m+n$ adımda biter. Bu adımlarda ya $L1$'in ya $L2$'nin gerçek elemanları tükenir; sonlandırıcılara ulaşmak için $m+n$'den fazla adım gerekir. Bu yüzden $L3$'e hiç sonlandırıcı yazılmaz. Dizilerden birinin diğerinden kaç fazla elemanı olduğu da önemli değildir.

**Soru:** Sonlandırıcının yanına bir de $10^{10}$ eklesek yine çalışır mı? **Cevap:** Evet, yine $m+n$ adımda durulduğu için çalışır.

**Soru:** Ya $10^6$ gerçekten dizide olan bir sayıysa? **Cevap:** Sonlandırıcı, kullanıcının verdiği sayıların hepsinden büyük olacak şekilde seçilir; dizinin gerçek elemanlarından biri olamaz.

> **Hocanın vurgusu:** Programda "büyük bir sayı" diye elle bir değer yazılmaz. Dizi `int` ise o tipin alabileceği en büyük değer (`INT_MAX`) kullanılır. Daha uzun bir yol olarak, okuma döngülerinde bütün sayıların maksimumu bulunur ve onun bir fazlası sonlandırıcı yapılır.

Aşağıdaki C programı derste yazılmadı; akış diyagramının C karşılığı olarak ajan tarafından yazıldı, `gcc -Wall` ile derlendi ve tahtadaki örnekle denendi. C dizileri 0'dan başladığı için indisler bir kaydırılmıştır.

```c
#include <stdio.h>
#include <limits.h>

int main(void) {
    int m, n, i, j, k;
    int L1[101], L2[101], L3[202];

    scanf("%d %d", &m, &n);
    for (i = 0; i < m; i++) scanf("%d", &L1[i]);
    for (i = 0; i < n; i++) scanf("%d", &L2[i]);

    L1[m] = INT_MAX;   /* sonlandirici (sentinel) */
    L2[n] = INT_MAX;

    i = 0; j = 0;
    for (k = 0; k < m + n; k++) {
        if (L1[i] < L2[j]) { L3[k] = L1[i]; i++; }
        else               { L3[k] = L2[j]; j++; }
    }
    for (k = 0; k < m + n; k++) printf("%d ", L3[k]);
    printf("\n");
    return 0;
}
```

Girdi `4 5 1 3 6 9 2 4 8 10 12` için çıktı `1 2 3 4 6 8 9 10 12` olur.

## 2. Dizide Eleman Arama: Doğrusal ve İkili Arama

Hoca "Bir dizide bir elemanı aramak" başlığını yazdı (ekrandan, 00:25:00) ve bunun ne kadar süreceğini sordu: elimizdeki eleman dizide var mı, varsa nerede?

Dizi sırasızsa elemanlar tek tek aranan değerle karşılaştırılır: birinci eleman eşit mi, ikinci eleman eşit mi... En fazla $N$ karşılaştırmada ya bulunur ya da "yok" denir. Çok şanslıysak ilk karşılaştırmada buluruz. Tahtada "aramak $\to N$" yazıldı (ekrandan, 00:35:00).

Dizi küçükten büyüğe sıralıysa iş değişir. Bir öğrenci önce "yine en fazla $N$" ve sonra "$N/2$" dedi; hoca ikili aramayı (binary search) hatırlattı. Öğrenciler bunu ilk dönemden hatırladıklarını söyledi: dizi sürekli ikiye bölünür, ortadaki değerin aranan değerden büyük ya da küçük olmasına göre dizinin yarısı atılır.

Hocanın tahtadaki anlatımı (ekrandan, 00:35:00): Aranan değer önce dizinin ortasındaki elemanla karşılaştırılır. Aranan değer ortadakinden büyükse, sıralı dizinin küçük yarısında olamaz; o yarı atılır. Kalan yarının ortası bulunur ve aynı soru sorulur. Her adımda kalan parça yarıya iner. Bu yüzden en fazla $\log_2 N$ karşılaştırma yapılır; tahtada "sıralı $\to \log_2 N$" yazıldı.

Hoca ikili aramanın daha önce anlatıldığını, burada yalnız mantığının hatırlatıldığını belirtti.

## 3. Bir Dizinin Sıralı Olup Olmadığını Bulma

Bu kez dizi sıralanmayacak; yalnız sıralı olup olmadığı bulunacak (ekrandan, 00:35:00). Hoca "sıralı" denince küçükten büyüğe mi büyükten küçüğe mi kastedildiğinin belirtilmesi gerektiğini de not etti; burada küçükten büyüğe kabul edildi.

### 3.1 Kötü yol

Diziyi başka bir dizide sıralayıp iki diziyi eleman eleman karşılaştırmak mümkündür. Maliyeti sıralama ve kontrolün toplamıdır: $N \log_2 N + N$ (ekrandan, 00:35:00).

### 3.2 Tek geçişte kontrol

Bir öğrenci `while` döngüsü önerdi: $i$. eleman $(i+1)$. elemandan küçük olduğu sürece ilerlenir. Döngüden çıkılmasının bir sebebi vardır ve bu sebep dizinin sıralı olup olmadığını söyler: dizi sıralıysa sonuna kadar gidilmiştir, değilse daha önce çıkılmıştır. Bu yüzden çıkışta $i$'nin değerine bakılır.

İndislerin 1'den başladığı akış diyagramında, sıralı bir dizide son karşılaştırma $A[N-1] < A[N]$'dir. Tahtadaki son hali (ekrandan, 00:40:00):

```text
i = 1
(i < N) ve (A[i] < A[i+1]) ?
    T: i = i + 1, aynı soruya dön
    F: i == N ?
        T: "sıralı" yaz
        F: "değil" yaz
STOP
```

Bu çözüme varırken sınıfta iki tartışma oldu.

**Soru:** Döngü koşulu $i < N-1$ yerine $i \le N-1$ olmamalı mı? **Cevap:** İlk çizimde koşul $i < N-1$ ve çıkış testi $i = N-1$ idi (ekrandan, 00:35:00). Öğrencinin itirazı haklı bulundu: $i = N-1$ iken de $A[N-1] < A[N]$ kontrol edilmelidir. Bu yüzden koşul $i < N$, çıkış testi $i = N$ yapıldı. Öğrencilerden biri kendi hesabını C'deki gibi 0'dan başlattığını, 1'den başlayınca hocanın haklı olduğunu söyledi.

**Soru:** $N = 10$ olsun. $i = 9$ iken içeri girilir, $i = 10$ olur ve sonra $A[10]$ ile $A[11]$ karşılaştırılır. Ama $A[11]$ yok? **Cevap:** Haklı bir tespit. Çözüm koşulların sırasını değiştirmektir: önce $i < N$ kontrol edilir, sonra $A[i] < A[i+1]$. Koşullar "ve" ile bağlıysa ilk koşul yanlış olduğunda ikincisine bakılmadan döngüden çıkılır. Böylece $i = 10$ iken $A[11]$'e hiç erişilmez (ekrandan, 00:40:00).

Bir öğrenci, $i = 10$ olduğunda $10 < 10$ zaten yanlış olacağı için sıranın fark etmeyeceğini düşündü. Hoca burada "yanlış" ile "hata"yı ayırdı: $10 < 10$ yanlış bir sonuçtur ama hata değildir; $A[11]$'e erişmek ise hatadır, çünkü öyle bir eleman yoktur.

Maliyet en fazla $N$'dir. Hoca bunun "tam $N$ adım" değil "en fazla $N$ adım" olduğunu vurguladı, çünkü sıralı olmayan bir dizide döngüden erken çıkılabilir.

> **Ek bilgi (derste anlatılmadı):** Koşul katı küçüklük ($<$) ile yazıldığı için eşit komşu elemanlar içeren bir dizi (örneğin 1, 2, 2, 3) bu algoritmaya göre "değil" çıkar. Eşit elemanlara izin veren "azalmayan sıralı" kontrolü için koşul $A[i] \le A[i+1]$ olmalıdır.

## 4. Dizi Sınırı Dışına Erişim Neden Tehlikelidir?

Bir öğrenci programın neden "patlayacağını" sordu. Hoca şöyle açıkladı. Program çalışırken, örneğin `A` için "10 elemanlı yer ayır" denir ve bellekte 10 elemanlık yer ayrılır. C programlama dilinde 11. elemana erişmek mümkündür; başka birçok dil ise dizinin sınırı dışına erişince hata verir. Bu "koruma" programı düzeltmek değildir; programa hakkı olmayan bir bellek alanına erişmeye çalıştığını söylemektir.

İşletim sistemi her programa bellekte bir alan ayırır ve aynı anda başka birçok program da çalışır; program kendi alanının içinde kalmalıdır. C çok esnek bir dildir ve belleğin farklı yerlerine erişmeye izin verir. Hoca, işletim sistemlerinin C ile yazıldığını, bu yüzden bu esnekliğin gerekli olduğunu söyledi.

$A[11]$'e erişildiğinde orada ne olduğu bilinmez. Bazen programın akışını bozmayan bir değer çıkar, bazen bozan bir değer. Sonuç olarak program kararlı (stabil) çalışmaz: kendi bilgisayarınızda 100 kez çalışır, 101. denemede sorun çıkarır; sizin bilgisayarınızda çalışır, başkasınınkinde çalışmaz.

> **Hocanın vurgusu:** Tanımladığınız dizilerin alanlarının dışına taşmayın; taşarsanız programınız kararlı olmaz.

## 5. Dizideki Değerlerin Sayısını Bulma

### 5.1 Yalnız 1 ve 2'lerden oluşan dizi

$N$ elemanlı dizide yalnız 1'ler ve 2'ler var. Tahtadaki dizi: $A = 1, 1, 2, 2, 2, 1, 2, 1, 2, 1, 1, 2, 2$ (ekrandan, 00:45:00). Soru: kaç tane 1, kaç tane 2 var?

Bir öğrencinin önerisi: iki sayaç tutulur, her eleman kontrol edilir; 1 ise birin sayacı, değilse ikinin sayacı artırılır. Akış diyagramında `bir = 0`, `iki = 0` başlangıç değerleriyle $i = 1 \ldots N$ döngüsü kurulur, `A[i] == 1` ise `bir = bir + 1`, değilse `iki = iki + 1` yapılır. Dizi yalnız 1 ve 2'lerden oluştuğu için ikinci bir soru sormaya gerek yoktur.

Hoca çizimde bir karar kutusunu işlem kutusu gibi çizdiğini fark edip düzeltti, sonra bir iyileştirme sordu: `iki` sayacına hiç gerek var mı? Yok, çünkü 2'lerin sayısı $N - bir$'dir. Tahtada `iki` sayacı ve onu artıran kutu silindi, çıktı `bir, N-bir` oldu (ekrandan, 00:45:00).

Tahtadaki dizide 13 eleman, 6 tane 1 ve 7 tane 2 vardır (python ile sayıldı).

### 5.2 1, 2 ve 3'lerden oluşan dizi

Bu kez bir karar kutusu daha gerekir: eleman 1 değilse, 2 mi diye sorulur. 2 ise `iki = iki + 1` yapılır; 2 de değilse 3'tür ve ayrıca saymaya gerek yoktur. Başlangıçta `bir = 0` ve `iki = 0` yine gerekir. Çıktı `bir, iki, N-bir-iki` olur (ekrandan, 00:50:00).

### 5.3 1'den 9'a kadar değerler

Aynı yöntemle 9 değer için 8 sayaç ve tek bir `for` içinde 8 tane `if` gerekir. Bu şık bir çözüm değildir. Hoca bunu ara öncesi düşünmeye bıraktı.

Aradan sonra öğrencilerden fikirler alındı:

- Bir öğrenci ASCII tablosundan yararlanmayı önerdi, sonra fikrinden vazgeçti.
- Bir öğrenci iç içe iki döngü önerdi: dış döngü $i = 1 \ldots N$, iç döngü $j = 1 \ldots 9$; `A[i] == j` ise `x = x + 1`, iç döngü bitince `x` yazdırılır (ekrandan, 01:10:00). Karar kutusundan $9N$ kez geçilir.
- Bir öğrenci iç döngünün `while` olmasını, eşleşme bulununca çıkılmasını önerdi. Hoca bunun karmaşıklığı ortalamada yarıya indirebileceğini söyledi.
- Bir öğrenci önce sayının tek mi çift mi olduğuna (mod) bakıp yalnız ilgili değerleri aramayı önerdi; hoca bunun da adım sayısını yarıya düşürebileceğini söyledi.

> **Ders sonrası not:** Tahtaya çizilen iki döngülü diyagramda `x` her $i$ için sıfırlanıp iç döngüden sonra yazdırılıyor. Her eleman 1-9 arasındaki tam bir değere eşit olduğu için bu diyagram her eleman için 1 yazdırır, değerlerin sayısını vermez. Her değerin sayısını bu yöntemle bulmak için dış döngü değerler ($j = 1 \ldots 9$), iç döngü elemanlar ($i = 1 \ldots N$) üzerinde olmalı ve `x` her $j$ için sıfırlanıp iç döngüden sonra yazdırılmalıdır. Maliyet yine $9N$ olur.

### 5.4 Sayma dizisi: $N$ adımlık çözüm

Bir öğrenci en iyi çözümü önerdi: ayrı bir $B$ dizisi tutulur ve dizinin elemanının kendisi $B$'ye indis olarak kullanılır. Önce $B$'nin 9 elemanı sıfırlanır, sonra tek döngüde:

```text
i = 1'den N'ye kadar:
    B[A[i]] = B[A[i]] + 1
```

$B$'nin 1. elemanı dizide kaç tane 1 olduğunu, 4. elemanı kaç tane 4 olduğunu tutar.

Hocanın adım adım örneği: $A = 4, 5, 3, 4$.

- $i = 1$: $A[1] = 4$, $B[4]$ 0'dan 1'e çıkar.
- $i = 2$: $A[2] = 5$, $B[5]$ 0'dan 1'e çıkar.
- $i = 3$: $A[3] = 3$, $B[3]$ 0'dan 1'e çıkar.
- $i = 4$: $A[4] = 4$, $B[4]$ 1'den 2'ye çıkar.

Sonuç: $B[3] = 1$, $B[4] = 2$, $B[5] = 1$, diğerleri 0. Döngüden yalnız $N$ kez geçildiği için maliyet $N$'dir. Hoca bunu "şık bir çözüm" diye niteledi.

## 6. Seçim Sistemleri: Sayma Fikrinin Uygulamaları

Hoca sayma dizisi fikrini seçim problemlerine uyguladı (ekrandan, 01:15:00).

### 6.1 Tek oy

$V$ vatandaş oy vermiştir. $V$ elemanlı $A$ dizisinin $i$. elemanı, $i$. vatandaşın oy verdiği partinin numarasıdır; değerler $1 \ldots P$ arasındadır ($P$ parti sayısı). Soru: seçimi kim kazanır?

Bir öğrencinin dediği gibi bu, az önceki problemin neredeyse aynısıdır. Sayma döngüsünde 9 yerine $P$ kullanılır: $B$'nin $P$ elemanı sıfırlanır, her $i$ için $B[A[i]] = B[A[i]] + 1$ yapılır. Sonunda $B$ her partinin aldığı oy sayısını tutar ve $B$'nin en büyük elemanı bulunur.

### 6.2 Herkes üç partiye oy verirse

Her vatandaş en beğendiği üç partiye oy verir. Veri yapısı bir matris olur: 3 satır, $V$ sütun; $i$. sütun, $i$. vatandaşın oy verdiği üç partiyi tutar (ekrandan, 01:25:00). $B$ dizisinin yapısı değişmez.

Akış diyagramında önce $V$ ve $P$ okunur, iç içe döngüyle matris okunur ($i = 1 \ldots V$, $j = 1 \ldots 3$) ve $B$'nin $P$ elemanı sıfırlanır. Sonra yine iç içe döngüyle sayılır (ekrandan, 01:25:00):

```text
i = 1'den V'ye kadar:
    j = 1'den 3'e kadar:
        B[A[j,i]] = B[A[j,i]] + 1
```

Ardından $B$'nin maksimumu bulunur; hoca bunu ayrıca çizmedi.

**Soru:** Matrisi okurken $A[i,j]$, sayarken $A[j,i]$ kullandık; kafam karıştı. **Cevap:** Matrisin nasıl tutulduğu bir tercihtir; önemli olan okurken ve kullanırken aynı düzeni izlemektir. Hoca karışıklık olmasın diye okuma kutusunu da sayma kutusundaki gibi $A[j,i]$ yaptı. $i$. satırın $j$. gözü ile $j$. satırın $i$. gözü farklı şeylerdir ve dikkatle kullanılmalıdır. Saymayı her vatandaşın üç oyuna sırayla bakarak yapmak zorunlu değildir; önce herkesin birinci oyları, sonra ikinci, sonra üçüncü oyları da sayılabilir.

### 6.3 Herkes her partiye 1-10 arası puan verirse

Bu kez matris $P$ satır, $V$ sütunludur. $A[j,i]$, $i$. vatandaşın $j$. partiye verdiği puandır (ekrandan, 01:30:00). Bir öğrencinin önerisiyle her satır (her parti) kendi içinde toplanır ve toplamların en büyüğü bulunur. Toplamlar ayrı bir değişkende değil, doğrudan $B$ dizisinin elemanlarına eklenerek tutulur; iç içe iki döngü ($i = 1 \ldots V$, $j = 1 \ldots P$) yeterlidir. Hoca bu kısmın çizimini öğrencilere bıraktı.

**Soru:** Sadece kazanan isteniyorsa bir diziye gerek yok; tek bir değişkende en büyüğü tutmak yetmez mi? **Cevap:** Yalnız en büyük gerekiyorsa yeter. Ama seçim sonuçlarının şeffaf olması gerekir, her partinin puanının açıklanması lazım; bu yüzden dizide tutmak gerekir.

### 6.4 Oyların ağırlıklı olduğu sistem

Hoca "demokrasiden biraz uzaklaşarak" herkesin oyunun eşit olmadığı bir sistem düşünmeyi önerdi. Önce sınıfla ağırlık kriterleri tartışıldı; hoca bunların doğru ya da yanlış olduğunun tartışılmadığını, yalnız ne yapılabileceğinin düşünüldüğünü belirtti. Önerilen kriterler ve tahtadaki önem eğrileri (ekrandan, 01:40:00):

- Eğitim seviyesi.
- Yaş: önem belli bir yaşa (tahtada 40) kadar artıp sonra azalır.
- Gelir: gelir arttıkça önem artabilir (borçlu olanlarda eksiye bile düşebilir), tersine en fakirlerin oyu en değerli sayılabilir ya da ortalama gelirden uzaklaştıkça önem azalabilir.
- Yıllık gelirin çalışma saatine oranı: az kazanıp çok çalışanın ya da tersine az çalışıp çok kazananın oyu daha değerli sayılabilir.
- Okunan kitap sayısı (kitapların ayrıca puanlanması gerekir), genel kültür sınavları ve yurt içinde ya da dışında yaşama.

Hangi kriter kullanılırsa kullanılsın, sonuç her vatandaş için bir ağırlıktır. $V$ elemanlı $R$ dizisinde $R[i]$, $i$. vatandaşın oyunun ağırlığıdır ve 0 ile 1 arasına normalize edilmiştir (ekrandan, 01:45:00). Herkes yine tek partiye oy verir.

Bir öğrencinin önerisiyle tek oy algoritmasındaki "+1" yerine $R[i]$ eklenir:

```text
i = 1'den V'ye kadar:
    B[A[i]] = B[A[i]] + R[i]
```

Partiye bir puan yerine, oyu veren kişinin ağırlığı kadar puan eklenir. Hoca ağırlıkların farklı yollarla bulunabileceğini, çarpma gibi başka işlemlerin de kullanılabileceğini, ama en basit çözümün bu olduğunu söyledi.

## 7. Linear Sort with Counting

### 7.1 Temel fikir

Ara sonrası sıralama algoritmalarına geçildi. Tahtadaki başlık ve fikir (ekrandan, 02:00:00):

> Benden küçük $k$ sayı varsa benim yerim $k+1$'dir.

Dizideki her eleman, kendisinden küçük kaç eleman olduğunu bilirse sıralı dizideki yerini de bilir.

Örnek (ekrandan, 02:00:00): $A = 3, 1, 4, 6$.

- 3'ten küçük 1 sayı var, $K[1] = 1$.
- 1'den küçük 0 sayı var, $K[2] = 0$.
- 4'ten küçük 2 sayı var, $K[3] = 2$.
- 6'dan küçük 3 sayı var, $K[4] = 3$.

$K = 1, 0, 2, 3$ ve $K+1 = 2, 1, 3, 4$. Yani 3 sıralı dizinin 2. yerine, 1 1. yerine, 4 3. yerine, 6 4. yerine gider: $B = 1, 3, 4, 6$.

### 7.2 Akış diyagramı

Her eleman dizinin her elemanıyla karşılaştırılacağı için tek bir döngü yetmez. Tahtadaki diyagram (ekrandan, 02:00:00 ve 02:05:00):

```text
START
oku N
i = 1'den N'ye kadar: oku A[i]
i = 1'den N'ye kadar: K[i] = 0
i = 1'den N'ye kadar:
    j = 1'den N'ye kadar:
        A[i] > A[j] ?
            T: K[i] = K[i] + 1
i = 1'den N'ye kadar:
    B[K[i] + 1] = A[i]
STOP
```

**Soru:** $B$'nin indisine neden $K[i]$ değil de $K[i]+1$ yazıyoruz? **Cevap:** Kural "benden küçük $k$ sayı varsa yerim $k+1$" idi. İndisler 1'den başlıyor; en küçük elemanın $K$ değeri 0'dır ama yeri 1. sıradır. C'de diziler 0'dan başladığı için orada $+1$ yazılmaz.

### 7.3 Karmaşıklık ve iyileştirme

En içteki karşılaştırmadan $N^2$ kez geçilir. Toplam $N^2 + N$ gibi bir değer çıkar ama baskın terim $N^2$'dir. Bu kötü bir karmaşıklıktır.

İyileştirme fikri: $A[i] > A[j]$ yanlışsa (F dalı), bu kez $A[j]$ büyüktür ve $K[j]$ artırılabilir. Bir öğrenci de "$K[j]$'yi mi artıralım" diye önerdi. Böylece her çift bir kez karşılaştırılınca iki tarafın sayacı birden güncellenir ve iç döngünün $N$'e kadar değil $i$'ye kadar dönmesi yeter (ekrandan, 02:05:00). Taranan alan kare yerine üçgen olur ve maliyet $N^2/2$'ye iner. Bir öğrencinin önerdiği farklı bir cevabı hoca kabul etmedi ve sonucun $N^2/2$ olduğunu söyledi. <!-- BELİRSİZ: öğrencinin cevabı altyazıda "N çarpı elenen" diye bozuk geçiyor; büyük olasılıkla "N çarpı log N" denmişti. -->

> **Ders sonrası not:** Tahtada iç döngünün üst sınırı $i$ olarak yazıldı. $j = i$ adımında $A[i] > A[i]$ yanlış olur ve F dalı $K[i]$'yi gereksiz yere bir artırır. $A = 3, 1, 4, 6$ için bu hali $K = 2, 1, 3, 4$ verir ve 6 dizinin dışındaki 5. yere yazılmaya çalışılır. İç döngü $i-1$'e kadar dönmelidir; o zaman $K = 1, 0, 2, 3$ doğru çıkar. Karşılaştırma sayısı $N(N-1)/2$ olur (iki hali de python ile denendi).

Hoca bu iyileştirmenin büyük bir kazanç olmadığını belirtti: algoritma hâlâ $N^2$ mertebesindedir. İleriki derslerde görülecek quicksort ve merge sort gibi algoritmaların karmaşıklığı $N \log_2 N$'dir.

## 8. Var/Yok İşaretleyerek Doğrusal Zamanlı Sıralama

### 8.1 Sınıfa soru

Hoca açıklama yapmadan bir akış diyagramı çizdi ve öğrencilerden algoritmanın ne yaptığını bulmalarını istedi: bir $A$ dizisi girer, sonunda bir $B$ dizisi oluşur ve ekrana yazılır; $A$ ile $B$ arasındaki ilişki nedir? Ayrıca karmaşıklığını da düşünmelerini istedi. Birkaç dakika sonra sohbetten gelen cevaplar "sıralama" oldu. Karmaşıklık için "$N$", "$2N + 2T$" ve "$T$ de olabilir" cevapları geldi.

### 8.2 Algoritma

Tahtadaki diyagram (ekrandan, 02:15:00):

```text
START
oku N
i = 1'den N'ye kadar: oku A[i]
T = 0
i = 1'den N'ye kadar:
    A[i] > T ?  T: T = A[i]
i = 1'den T'ye kadar: K[i] = 0
i = 1'den N'ye kadar: K[A[i]] = 1
j = 1
i = 1'den T'ye kadar:
    K[i] != 0 ?  T: B[j] = i;  j = j + 1
i = 1'den N'ye kadar: yaz B[i]
STOP
```

Adım adım çözümleme:

- İlk döngü bittiğinde $T$, $A$'nın en büyük elemanıdır; tahtaya `T = max(A)` yazıldı (ekrandan, 02:25:00).
- $T$ elemanlı bir $K$ dizisi oluşturulup sıfırlanır.
- Her $A[i]$ için $K[A[i]] = 1$ yapılır. $K$'daki 1'ler, o sayının $A$'da var olduğunu gösterir.
- $K$ baştan sona taranır; sıfır olmayan her konumun indisi sırayla $B$'ye yazılır.

### 8.3 Hocanın örneği

$A = 6, 3, 5, 7$ ve dolayısıyla $T = 7$ (ekrandan, 02:25:00).

- $i = 1$: $A[1] = 6$, $K[6] = 1$.
- $i = 2$: $A[2] = 3$, $K[3] = 1$.
- $i = 3$: $A[3] = 5$, $K[5] = 1$.
- $i = 4$: $A[4] = 7$, $K[7] = 1$.

Sonuç: $K = 0, 0, 1, 0, 1, 1, 1$ (ekrandan, 02:25:00). Tarama: $K[1]$ ve $K[2]$ sıfırdır, atlanır. $K[3] \neq 0$, $B[1] = 3$ ve $j = 2$. $K[4]$ sıfırdır, atlanır. Sonra $B[2] = 5$, $B[3] = 6$, $B[4] = 7$. Sonuç $B = 3, 5, 6, 7$, yani $A$'nın sıralanmış halidir.

### 8.4 Karmaşıklık

Algoritmada hiç iç içe döngü yoktur. Hoca bunu "bir sıralama algoritması ama iç içe hiçbir döngü yok; bu çok güzel" diye vurguladı. Bütün döngüler $N$ ya da $T$ kadar döner, bu yüzden karmaşıklık $\max(N, T)$ olarak yazılabilir (ekrandan, 02:30:00). Genelde $T$'nin $N$'den büyük olma ihtimali daha yüksektir.

1'den 100'e kadar sayılar karışık halde bir dizide dursun. Burada $N = T = 100$'dür ve algoritma 100 adımda sıralar; $N^2$'lik algoritma $100^2 = 10.000$ adım ister, yani 100 kat yavaştır. 1'den 1 milyona kadar sayılar için bu algoritma yaklaşık $10^6$ adım, $N^2$'lik algoritma $10^{12}$ adım ister.

### 8.5 Zayıf yanları

- **Tekrar eden değerler:** Bir öğrenci aynı değerden iki tane olursa ne olacağını sordu. Hoca "tabii ki ezecek" dedi: $K[A[i]] = 1$ işlemi ikinci kopyayı ayırt etmez, sonuçta o değer bir kez görünür.
- **Bellek:** Bir öğrenci fazladan diziler açıldığına dikkat çekti. Hoca $A = 100, 1, 2$ örneğini verdi: 3 elemanı sıralamak için 100 elemanlı bir $K$ dizisi açılır ve 100 adımlık tarama yapılır. Diğer sıralama algoritmalarında $N$ elemanlı dizi için $N$ elemanlı bir dizi yeter, hatta dizinin kendi üzerinde de sıralanabilir. Burada ise en büyük eleman kaçsa o boyutta dizi açmak gerekir.

Sohbetten bir öğrencinin özeti hoca tarafından onaylandı: "Hızdan kazanırken doğruluktan ve hafızadan kaybettik."

Aşağıdaki C programı derste yazılmadı; akış diyagramının C karşılığı olarak ajan tarafından yazıldı, `gcc -Wall` ile derlendi ve tahtadaki örnekle denendi. Değerlerin 1 ile 1000 arasında pozitif tam sayılar olduğu varsayıldı. $B$'de kaç eleman dolduğu `j` ile tutulduğu için yazdırma döngüsü $N$ yerine `j`'ye kadar döner; tekrar eden değerler olduğunda $B$'nin $N$ elemanının hepsi dolmaz.

```c
#include <stdio.h>

int main(void) {
    int n, i, j, t;
    int A[100], K[1001], B[100];

    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &A[i]);

    t = 0;                               /* en buyuk elemani bul */
    for (i = 0; i < n; i++)
        if (A[i] > t) t = A[i];

    for (i = 1; i <= t; i++) K[i] = 0;   /* K dizisini sifirla */
    for (i = 0; i < n; i++) K[A[i]] = 1; /* hangi sayilar var */

    j = 0;
    for (i = 1; i <= t; i++)
        if (K[i] != 0) { B[j] = i; j++; }

    for (i = 0; i < j; i++) printf("%d ", B[i]);
    printf("\n");
    return 0;
}
```

Girdi `4 6 3 5 7` için çıktı `3 5 6 7`, girdi `3 100 1 2` için çıktı `1 2 100` olur.

> **Ek bilgi (derste anlatılmadı):** $K$ dizisinde 1 yazmak yerine sayaç tutulursa ($K[A[i]] = K[A[i]] + 1$, yani 5. bölümdeki sayma dizisi) ve tarama sırasında her değer $K[i]$ kez $B$'ye yazılırsa tekrar eden değerler kaybolmaz. Bu yöntem literatürde "counting sort" (sayarak sıralama) diye bilinir; bellek sorunu ise aynen kalır.

## 9. Karmaşıklıkta Sabit Katsayılar

Ders sonunda bir öğrenci sordu: iç içe iki `for` $N^2$ işlem yapıyor; ama alt alta iki ayrı $N$'lik `for` olunca toplam $2N$ işlem olmaz mı, neden yine $N$ diyoruz?

Hoca önce bir düzeltme yaptı: $N^2$ veren döngüler alt alta değil iç içe olanlardır. Sonra şöyle cevap verdi: $N$, $2N$, $3N$, $4N$ algoritmik açıdan büyük farklar değildir. $N$'e bağlı olmayan sabit katsayılar ($2N$, $N/2$, $N/3$, $N/100$) karmaşıklık analizinde göz ardı edilebilir. Alt alta iki $N$'lik döngü toplam $2N$ işlem yapar ama karmaşıklık açısından $N$'lik sayılır. Benzer şekilde $N^2 + N$ için yalnız $N^2$'ye bakılır. Pratikte $N$ ile $N/100$ arasında elbette fark vardır, ama $N$ büyüdükçe bu farkın önemi azalır. Hoca bu analizlerin ileriki dönemlerde veri yapıları ve algoritma analizi derslerinde çok daha ayrıntılı görüleceğini söyledi.

## Örnek Sorular

**Soru 1** (ekrandan, 00:15:00): $L1$ ($m$ elemanlı) ve $L2$ ($n$ elemanlı) küçükten büyüğe sıralı iki dizidir. Bunlardan $m+n$ elemanlı, sıralı $L3$ dizisini $m+n$ adımda üreten algoritmayı çizin. $L1 = 1, 3, 6, 9$ ve $L2 = 2, 4, 8, 10, 12$ için sonucu yazın.

> **Çözüm:** İki indis ($i$, $j$) tutulur; $k = 1 \ldots m+n$ boyunca küçük olan eleman $L3[k]$'ya yazılır ve o dizinin indisi artırılır. Dizilerin sonuna her elemandan büyük birer sonlandırıcı ($L1[m+1]$, $L2[n+1]$) eklenir. Sonuç: $1, 2, 3, 4, 6, 8, 9, 10, 12$.

**Soru 2** (derste sözlü, 00:23:36): Bir dizide bir elemanı aramak ne kadar sürer? Dizi sıralıysa ne değişir?

> **Çözüm:** Sırasız dizide doğrusal arama en fazla $N$ karşılaştırma ister. Sıralı dizide ikili arama her adımda kalan parçayı yarıya indirir ve en fazla $\log_2 N$ karşılaştırma ister.

**Soru 3** (ekrandan, 00:35:00): Bir dizinin (küçükten büyüğe) sıralı olup olmadığını bulan algoritmayı çizin; karmaşıklığı nedir?

> **Çözüm:** $i = 1$; $(i < N)$ ve $(A[i] < A[i+1])$ olduğu sürece $i = i + 1$. Çıkışta $i = N$ ise "sıralı", değilse "değil". Koşulların sırası önemlidir: önce $i < N$ kontrol edilir ki $A[N+1]$'e erişilmesin. Karmaşıklık en fazla $N$'dir; sıralayıp kontrol etmek ise $N \log_2 N + N$ tutar.

**Soru 4** (ekrandan, 00:45:00): $A = 1, 1, 2, 2, 2, 1, 2, 1, 2, 1, 1, 2, 2$ dizisinde yalnız 1 ve 2 vardır. Kaç tane 1, kaç tane 2 olduğunu bulun. Dizide 1, 2 ve 3 olsaydı ne değişirdi?

> **Çözüm:** Tek sayaç yeter: `A[i] == 1` ise `bir = bir + 1`; 2'lerin sayısı $N - bir$. Bu dizide $N = 13$, 6 tane 1, 7 tane 2 vardır (python ile sayıldı). 1-2-3 durumunda ikinci bir karar kutusuyla `iki` sayılır, 3'lerin sayısı $N - bir - iki$ olur.

**Soru 5** (derste sözlü, 01:03:47): Dizide 1'den 9'a kadar değerler var. Her değerden kaç tane olduğunu verimli biçimde bulun.

> **Çözüm:** 9 elemanlı $B$ dizisi sıfırlanır; $i = 1 \ldots N$ için $B[A[i]] = B[A[i]] + 1$. Maliyet $N$'dir. İç içe döngüyle ($j = 1 \ldots 9$) yapmak $9N$ karşılaştırma ister.

**Soru 6** (ekrandan, 01:25:00): $V$ vatandaş, $P$ parti var. (a) Herkes bir partiye oy verirse, (b) herkes üç partiye oy verirse, (c) herkes her partiye 1-10 arası puan verirse, (d) her vatandaşın oyu $R[i] \in (0,1)$ ağırlığına sahipse seçimi kim kazanır?

> **Çözüm:** (a) $B[A[i]] = B[A[i]] + 1$, sonra $B$'nin maksimumu. (b) $A$ 3×$V$ matris; iç içe döngüyle $B[A[j,i]] = B[A[j,i]] + 1$, sonra maksimum. (c) $A[j,i]$ puan; her partinin satırı $B[j]$'ye toplanır, sonra maksimum. (d) $B[A[i]] = B[A[i]] + R[i]$, sonra maksimum.

**Soru 7** (ekrandan, 02:00:00): "Benden küçük $k$ sayı varsa benim yerim $k+1$'dir" fikriyle sıralayan algoritmayı çizin; $A = 3, 1, 4, 6$ için $K$ ve $B$ dizilerini bulun; karmaşıklığı nedir, nasıl iyileştirilir?

> **Çözüm:** $K = 1, 0, 2, 3$, $K+1 = 2, 1, 3, 4$, $B = 1, 3, 4, 6$. Karmaşıklık $N^2$. F dalında $K[j]$ de artırılır ve iç döngü $i-1$'e kadar döndürülürse karşılaştırma sayısı $N(N-1)/2$ olur.

**Soru 8** (ekrandan, 02:15:00): Tahtadaki akış diyagramı (en büyük eleman $T$'yi bulur, $K[A[i]] = 1$ yapar, $K$'yı tarayıp sıfır olmayan indisleri $B$'ye yazar) ne yapar? $A$ ile $B$ arasındaki ilişki nedir, karmaşıklığı nedir?

> **Çözüm:** $B$, $A$'nın sıralanmış halidir. $A = 6, 3, 5, 7$ için $T = 7$, $K = 0, 0, 1, 0, 1, 1, 1$, $B = 3, 5, 6, 7$. İç içe döngü yoktur; karmaşıklık $\max(N, T)$'dir. Tekrar eden değerleri tek bir taneye indirir ve $T$ büyükse çok bellek harcar.

## Dersin Toparlaması

Bu derste dizilerle ilgili bir dizi problem üzerinden aynı soru tekrar tekrar soruldu: çalışan bir çözümden daha az işlem yapan bir çözüme nasıl geçilir? İki sıralı dizi, sıralı olmalarından yararlanılarak iki indis ve sonlandırıcıyla $m+n$ adımda birleştirildi. Sıralı dizide aramanın $\log_2 N$'ye indiği hatırlatıldı. Bir dizinin sıralılığı tek geçişte kontrol edildi ve bu sırada koşulların sırası ile dizi sınırı dışına erişimin neden tehlikeli olduğu tartışıldı. Değer sayma probleminde elemanın kendisini indis olarak kullanan sayma dizisi $N$ adımlık bir çözüm verdi. Bu fikir farklı seçim sistemlerine (tek oy, üç oy, puanlama, ağırlıklı oy) genellendi.

Son bölümde iki sıralama algoritması incelendi. "Benden küçük $k$ sayı varsa yerim $k+1$" fikrine dayanan Linear Sort with Counting $N^2$ mertebesinde kaldı. Var/yok işaretleyen algoritma ise iç içe döngü olmadan $\max(N, T)$ adımda sıraladı, ama tekrar eden değerleri ve belleği feda etti. Ders, karmaşıklıkta sabit katsayıların göz ardı edildiği ve bu analizlerin ileriki veri yapıları ve algoritma analizi derslerinde ayrıntılı görüleceği notuyla kapandı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
