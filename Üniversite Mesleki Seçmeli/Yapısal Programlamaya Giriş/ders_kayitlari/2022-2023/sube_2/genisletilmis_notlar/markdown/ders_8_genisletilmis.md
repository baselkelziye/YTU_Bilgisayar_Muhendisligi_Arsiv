# Ders 8 Genişletilmiş Notu: Sıralı Dizileri Birleştirme, Arama Algoritmaları, Pointer ve Fonksiyonlara Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. İki sıralı dizinin birleştirilmesi
- 2. Dizide eleman arama: doğrusal arama
- 3. Sıralı dizide eleman arama: ikili arama
- 4. İnterpolasyon araması
- 5. Bir dizinin sıralı olup olmadığını bulma
- 6. Pointer'lar ve bellek organizasyonu
- 7. Fonksiyonlara giriş: değerle ve adresle çağrı
- Örnek Sorular
- Dersin Toparlaması

## 1. İki sıralı dizinin birleştirilmesi

Ders, dizilerle ilgili soru listesinin ilk sorusuyla başlar: iki sıralı diziyi birleştirmek (merging two sorted arrays). Slaytta problem şöyle yazılır (ekrandan, 00:10:00):

```text
S1) Merging two sorted array:
L1[N], L2[M]  ->  L3[N+M]
```

$N$ elemanlı sıralı `L1` ile $M$ elemanlı sıralı `L2`'den, $N+M$ elemanlı ve yine sıralı bir `L3` oluşturulacaktır. Hoca bu işlemin birleştirmeli sıralamada (merge sort) sıkça kullanılan bir alt adım olduğunu hatırlatır.

### 1.1 Birinci yaklaşım: önce birleştir, sonra sırala

Bir öğrencinin ilk önerisi, iki diziyi sırasız biçimde arka arkaya `L3`'e kopyalamak ve sonra `L3`'ü sıralamaktır. Slayttaki çizimde `L3`'ün ilk $N$ hücresine `L1`, sonraki $M$ hücresine `L2` yazılır (ekrandan, 00:20:00).

- Birleştirme (merge) adımı: her eleman bir kez kopyalanır, $N+M$ işlem.
- Sıralama adımı: iyi bir sıralama algoritmasıyla $N \log N$.
- Toplam: $N \log N + N + M \approx N \log N$.

Kötü bir sıralama algoritması seçilirse sıralama adımı $N^2$'ye, dolayısıyla bütün çözüm $N^2$'ye çıkar. Hoca bu nedenle en iyi sıralama algoritmasının kullanıldığını varsayar ve "daha az karmaşıklıkla çözmek mümkün mü?" diye sorar.

Hocanın örneği `L1 = {2, 4, 6}`, `L2 = {1, 3, 5, 7}` biçimindedir; arka arkaya yazılıp sıralanınca `1, 2, 3, 4, 5, 6, 7` elde edilir.

### 1.2 İkinci yaklaşım: iki işaretçiyle karşılaştırarak kopyalama

Öğrenciler "iki diziyi karşılaştıra karşılaştıra atalım" önerisini getirir. Hoca bunu tahtada üç indisle kurar: `D1` dizisinde `x`, `D2` dizisinde `y`, sonuç dizisi `D3`'te `i` (ya da `z`). İkisi de 0'dan başlar. Hangi dizinin o anki elemanı küçükse o eleman `D3`'e yazılır ve o dizinin indisi bir artırılır; `D3`'ün indisi her adımda artar.

Tahtadaki ilk taslak (ekrandan, 00:20:00):

```text
x = 0, y = 0
for (i = 0; i < N+M; i++) {
    if (D1[x] <= D2[y]) {
        D3[i] = D1[x];
        x++;
    }
    else {
        D3[i] = D2[y];
        y++;
    }
}
```

Eşitlik durumu da ilk `if`'e dahil edilir; böylece yalnız iki durum kalır.

**Soru:** `D2`, `D1`'den çok uzunsa bu kod patlamaz mı? **Cevap:** Evet. Hoca örneği değiştirir: `D1 = {1, 2, 3}`, `D2 = {4, 5, 6, 7, 8}`. Önce 1, 2, 3 alınır; `x` 3 olur ve `D1[3]` dizinin dışındadır. Algoritma her durumda çalışmalı, yani genelleştirilebilir olmalıdır.

Bir öğrenci döngü koşuluna `x < N && y < M` eklenmesini önerir. Hoca bunun yetmediğini gösterir: döngüden çıkılınca bir dizinin kalan elemanları yarım kalır. Bu yüzden döngüden sonra hangi koşulla çıkıldığına bakılır ve kalan elemanlar karşılaştırmadan kopyalanır (ekrandan, 00:25:00):

```text
if (x == N)  for(...)  D3[i] = D2[y]; y++;   // birinci dizi bitti, ikincinin kalanı
if (y == M)  for(...)  D3[i] = D1[x]; x++;   // ikinci dizi bitti, birincinin kalanı
```

Hoca bu çözümün `for` döngüsünün doğasına aykırı olduğunu vurgular: döngünün ne zaman biteceği belli değilse `for` kullanmak pek iyi değildir.

> **Hocanın vurgusu:** Bir döngünün kaç kez döneceği baştan belli değilse `for` yerine `while` tercih edilmelidir.

### 1.3 Sona çok büyük bir sayı ekleme (sentinel) çözümü

Ders notlarındaki çözüm biraz farklıdır: iki dizinin de sonuna, yani $N+1$. ve $M+1$. hücrelere çok büyük bir sayı (slaytta `INT max`) yazılır (ekrandan, 00:25:00). Böylece hangi dizi önce biterse bitsin, onun son "elemanı" karşılaştırmayı hiçbir zaman kazanamaz ve döngü $N+M$ adım boyunca öbür dizinin elemanlarını almaya devam eder. Kalan elemanları kopyalayan ek döngülere gerek kalmaz.

Örneğin birinci dizi tek elemanlıysa ona bir hücre eklenip iki elemanlı yapılır; öbür dizi bin elemanlıysa bin bir elemanlı olur. Döngü yine $N+M$ kez döner ve en sonunda yalnız büyük sayılar kalır.

Bu çözümün sıkıntısı, $N$ elemanlı bir dizinin $N+1$. elemanına değer yazabilmek için diziyi bir hücre genişletmek gerekmesidir.

Bir öğrencinin önerdiği "push ile ekle, sonra sırala" çözümüne hoca, iki dizinin zaten kesin sıralı olduğunu ve sıralama çalıştırılırsa karmaşıklığın yeniden $N \log N$'ye gideceğini söyler. "Uzun olan dizinin kalanını sona ekleyelim" önerisine de şunu gösterir: uzunluk tek başına bir şey ifade etmez; `D1 = {1, 3, 5, ...}` ve `D2 = {2, 4, ...}` gibi iç içe geçen dizilerde bazı elemanlar birinden, bazıları öbüründen alınmak zorundadır. Kalan kısmı eklemek ise zaten döngü sonrasındaki kopyalama işidir.

### 1.4 `while` ile C kodu

Hoca sentinel kullanmayan ve `for` yerine `while` kullanan bir çözüm yazar. Diziler klavyeden girilmez; birinci diziye tek sayılar, ikinciye çift sayılar atanır ve atama sırasında ekrana yazılır. Kodun son hali (ekrandan, 00:35:00 ve 00:45:00):

```c
#include <stdio.h>
#define N 15
#define M 3
int main(){
    int d1[N], d2[M], d3[N+M];
    int i, j, k;
    printf("Dizi-1:");
    for(i=0;i<N;i++){ d1[i] = 2*i+1; printf("%d ", d1[i]); }
    printf("\nDizi-2:");
    for(j=0;j<M;j++){ d2[j] = 2*j; printf("%d ", d2[j]); }
    k=i=j=0;
    while(i<N && j<M){
        if(d1[i] <= d2[j]){ d3[k] = d1[i]; i++; }
        else{ d3[k] = d2[j]; j++; }
        k++;
    }
    while(i<N){ d3[k] = d1[i]; i++; k++; }
    while(j<M){ d3[k] = d2[j]; j++; k++; }
    printf("\nDizi-3:");
    for(k=0;k<N+M;k++) printf("%d ", d3[k]);
    printf("\n");
    return 0;
}
```

Bu tam program `gcc -Wall` ile derlenip çalıştırıldı. Çıktısı, dersteki ekran çıktısıyla aynıdır (ekrandan, 00:40:00):

```text
Dizi-1:1 3 5 7 9 11 13 15 17 19 21 23 25 27 29
Dizi-2:0 2 4
Dizi-3:0 1 2 3 4 5 7 9 11 13 15 17 19 21 23 25 27 29
```

Kodun mantığı:

- İlk `while`, iki diziden biri bitene kadar döner. Koşul `i<N && j<M` olduğu için ya soldaki ya sağdaki koşul bozulunca çıkılır.
- Döngüden sonra hangi dizinin bittiğini `if` ile sormak gerekmez. İki `while` yazılır: bitmiş dizinin `while`'ının koşulu zaten yanlıştır ve hiç çalışmaz; bitmemiş olanınki çalışır ve kalan elemanları kopyalar.

> **Hocanın vurgusu:** Döngü sonrasında `if` ile hangi dizinin bittiğini kontrol etmek yerine iki `while` yazmak gereksiz `if` kontrolünden kurtarır.

İlk çalıştırmada son iki `while`'da diziler ters yazılmıştı (`i<N` iken `d2`'den kopyalanıyordu); indisler güncellenmediği için dizinin dışına çıkıldı ve program segmentation fault ile kapandı. Hoca bunu şöyle açıklar: program erişim izni olmayan bellek bölgesine gitti, işletim sistemi de programı durdurdu. Bir öğrencinin "son `while`'larda `i` ve `j`'de hata olabilir mi?" sorusuyla hata bulundu ve düzeltildi.

**Soru:** İlk başta dizileri `2*i` ile neden doldurduk? **Cevap:** Klavyeden sıralı eleman girmekle uğraşmamak için dizilere belli bir düzende değer atandı; tekler bir dizide, çiftler öbüründe. Aynı diziler kullanıcıdan da alınabilirdi.

### 1.5 Kalan kopyalamayı tek döngüye indirme denemesi

Hoca iki `while`'ı tek döngüye indirmeyi dener: `if (i == N)` ise ikinci diziden, değilse birinci diziden kalan yerden devam edilsin; bir `temp` değişkeni döngünün sınırını tutsun. Ancak döngünün içinde hangi diziden kopyalanacağının yine söylenmesi gerektiği görülür. Bu bilgiyle tek döngüye indirmenin pek yolu yoktur; pointer'lar görüldükten sonra yapılabilir. Bu yüzden iki `while` korunur.

### 1.6 Karmaşıklık analizi

- İlk `while` döngüsü, iki diziden biri bitene kadar döner.
- Kalan iki `while`'dan yalnız biri çalışır ve kalan elemanları kopyalar.
- Hangi dizi önce biterse bitsin, toplam adım sayısı $N+M$'dir.

$N$ ile $M$ birbirine yakın kabul edilirse toplam $2N$ olur; sabit katsayı atılınca $O(N)$ kalır. Birinci yaklaşımdaki $N + M + N \log N$ karmaşıklık, sıralamadan kurtulunca $N$'ye inmiş olur.

### 1.7 Bir öğrencinin tek `for` döngülü çözümü

Bir öğrenci birleştirmeyi tek `for` döngüsüyle yazmayı önerir. Hoca kodu Dev-C++'a kopyalar (ekrandan, 00:50:00):

```c
x=y=0;
for (i=0; i<N+M; i++){
    if (x < N && a[x]<=b[y]){
        c[i] = a[x];
        x++;
    }
    else if (y<M){
        c[i] = b[y];
        y++;
    }
    printf("%d-",c[i]);
}
```

`a = {1, 2, 3}`, `b = {4, ..., 11}` gibi bir dizinin tamamen öbüründen küçük olduğu örnekte kod doğru çalışır. Hoca birinci dizinin elemanlarını ikincinin elemanlarıyla iç içe geçecek biçimde değiştirince (birinci dizinin son elemanı ikinci dizinin bütün elemanlarından büyük olacak şekilde) çıktıda bir eleman kaybolur ve yerine bellekteki rastgele bir değer yazılır. Sebep: ikinci dizi bitince (`y == M`) birinci dizinin kalan elemanı için ne `if`'in koşulu (`a[x] <= b[y]`, üstelik `b[y]` artık dizinin dışından okunur) ne de `else if (y<M)` sağlanır; `c[i]` doldurulmadan geçilir.

> **Ders sonrası not:** Bu açık `a = {1, 4, 12}`, `b = {2, 3, 6, 7, 8, 9, 10, 11}` örneğiyle `gcc` üzerinde denendi: 12 sonuç dizisine hiç yazılmadı ve son hücre doldurulmadan kaldı. Düzeltmek için `if` koşulu `x < N && (y >= M || a[x] <= b[y])` yapılabilir; bu düzeltme derste yazılmadı, ajan tarafından eklendi.

## 2. Dizide eleman arama: doğrusal arama

İkinci soru, bir dizide eleman aramaktır (ekrandan, 00:55:00). Dizi herhangi bir şey olabilir: kişiler arasında kimlik numarasına göre birini aramak ya da bir sayı dizisinde bir sayı aramak. Elimizde bir arama kriteri (anahtar, key) vardır.

İlk akla gelen yöntem baştan başlayıp elemanlara tek tek bakmaktır. Aranan eleman arada bir yerde bulunabileceği için `while` döngüsü uygundur (ekrandan, 01:05:00):

```text
i = 0
while (i < N && dizi[i] != key) {
    i++
}
if (i == N)
    Not found
else
    found i-th location
```

Döngü ya dizinin sonuna gelindiği için ya da eleman bulunduğu için biter. Döngüden sonra `i == N` ise eleman bulunamamıştır, değilse `i`. konumdadır.

Karmaşıklık, önceki algoritmadan farklı olarak üç duruma ayrılır (ekrandan, 01:05:00):

- En iyi durum (best case): 1. Eleman ilk hücrededir.
- En kötü durum (worst case): $N+1$. Eleman son hücrededir ya da hiç yoktur; $+1$ dizinin dışına çıkan, "bulunamadı" denemesidir.
- Ortalama durum (average case): $N/2 \approx N$.

Birleştirmede böyle bir ayrım yoktu: diziler nasıl olursa olsun iş $N+M$ idi. Aramada ise şansa göre değişir.

## 3. Sıralı dizide eleman arama: ikili arama

Üçüncü soru, sıralı bir dizide eleman aramaktır (ekrandan, 01:05:00). Dizi kesin sıralıysa baştan ya da sondan tek tek bakmaya gerek yoktur. Öğrencilerden biri doğrudan ikili arama (binary search) adını verir.

### 3.1 Fikir ve kod taslağı

Dizinin arasında bir `x` konumu seçilir ve o konumdaki elemana bakılır. Aranan değer bu elemandan büyükse sağ kısma, küçükse sol kısma bakılır. Böylece dizinin bir kısmı arama uzayının dışına atılır.

Hoca bunu sayısal analizdeki kök bulma yöntemlerine bağlar: gerçel sayılar da sayı doğrusu üzerinde sıralı bir dizidir ve orada ikiye bölme (bisection) ile regula falsi yöntemleri vardı. Burada indisler tamsayı olduğu için iş daha kolaydır.

`x` orta eleman (mid element) seçilir. Başta `i = 0`, `j = N-1` olur. Tahtadaki taslak (ekrandan, 01:05:00):

```text
i = 0;
j = N-1;
mid = (i+j)/2;
while (i < j && dizi[mid] != key) {
    if (dizi[mid] <= key)
        i = mid+1;
    else
        j = mid-1;
    mid = (i+j)/2;
}
```

`i` baştan sona, `j` sondan başa doğru yaklaşır; bir yerde eşitlenebilirler ama `j` hiçbir zaman `i`'yi geçmemelidir. Döngü ya eleman bulununca ya da `i`, `j`'yi geçince biter; bu durumda (`i > j`) "bulunamadı" yazılır, değilse eleman `mid` konumunda bulunmuştur.

### 3.2 Animasyonla gösterim

Hoca bir görselleştirme sitesinde 32 elemanlı sıralı bir dizi üzerinde iki aramayı karşılaştırır (ekrandan, 01:10:00). Doğrusal aramada 840 aranır; elemanlara tek tek bakılır ve 25. indise kadar gidilir. Bulununca arama durur. Hoca, aranan eleman birden fazla varsa ilk geçtiği yer (first occurrence), son geçtiği yer (last occurrence) ya da bütün yerleri bulma gibi seçenekler olabileceğini, ama şimdilik en basit hal düşünüldüğünü belirtir.

İkili aramada başta `low = 0`, `high = 31` olur; ilk orta nokta $(0+31)/2 = 15$'tir. Aranan değer daha büyük olduğu için `low` 16'ya gelir, yeni orta nokta 23 olur; sonra 24'e gelinir; bu kez aranan daha küçük olduğu için `high` kayar ve aranan yer bulunur. Sitedeki koddaki döngü koşulu `low <= high`'dır.

**Soru:** `i` ya da `j` aranan elemanın tam üstüne gelirse ne olur? **Cevap:** Hoca 483'ü (dizinin 16. indisi) aratarak gösterir: aralık daralır ve sonunda `i` ile `j` eşitlenir; o zaman orta nokta da aynı yerdir ve eleman orta nokta olarak bulunur. Bunun çalışması için döngü koşulunun `i <= j` olması gerekir; tahtadaki `i < j` koşulu `i <= j` olarak düzeltilir.

### 3.3 Karmaşıklık

$N$ elemanlı dizide ilk adımdan sonra bakılacak eleman sayısı $N/2$'ye, sonra $N/4$'e, $N/8$'e iner; $k$ adım sonra $N/2^k$ kalır. Tek eleman kalana kadar devam edilir:

$$\frac{N}{2^k} = 1 \;\Rightarrow\; N = 2^k \;\Rightarrow\; \log_2 N = k \log_2 2 = k \;\Rightarrow\; k = \log_2 N$$

En kötü durumda ikili arama $\log_2 N$ adımda sonuca ulaşır. 1024 elemanlı bir dizide doğrusal arama en kötü 1024 adım, ikili arama 10 adım sürer.

## 4. İnterpolasyon araması

### 4.1 Orta noktayı tahmin etmek

İkili aramada orta nokta $\frac{i+j}{2}$ ile bulunur. İnterpolasyon araması (interpolation search) bunun yerine orta noktayı, regula falsi yöntemindeki gibi iki uç değer arasına bir doğru uydurarak tahmin eder. Kodun geri kalanı aynıdır. Hoca hazır bir C kodunu (bir öğretici sitesinden) açar (ekrandan, 01:15:00). Sitedeki dizi ve orta nokta formülü:

```c
#define MAX 10
int list[MAX] = { 10, 14, 19, 26, 27, 31, 33, 35, 42, 44 };
...
mid = lo + (((double)(hi - lo) / (list[hi] - list[lo])) * (data - list[lo]));
```

Matematiksel olarak:

$$mid = lo + \frac{hi - lo}{list[hi] - list[lo]} \cdot (data - list[lo])$$

Sitede bu algoritmanın çalışması için verinin sıralı ve düzgün dağılmış olması gerektiği, çalışma süresinin $\log_2(\log_2 n)$ olduğu yazar (ekrandan, 01:15:00).

> **Ek bilgi (derste anlatılmadı):** $\log_2(\log_2 n)$, değerler düzgün dağıldığında beklenen (ortalama) adım sayısıdır. Değerler çok dengesiz dağılmışsa interpolasyon aramasının en kötü durumu $O(n)$'ye kadar çıkabilir.

### 4.2 İki aramanın aynı programda karşılaştırılması

Hoca interpolasyon araması fonksiyonu `find`'ın yanına ikili arama kodunu `findv2` adıyla ekler; ikisi de karşılaştırma sayısını yazar. `main` iki fonksiyonu da 33 için çağırır ve konumu `location+1` olarak yazdırır (ekrandan, 01:35:00). Sonuç:

- İnterpolasyon araması: 1 karşılaştırma, 7. konum. İlk tahmin $0 + \frac{9}{34}\cdot(33-10) \approx 6{,}09 \to 6$ ve `list[6] = 33`.
- İkili arama: 4 karşılaştırma, 7. konum. Orta noktalar sırasıyla 4 (27), 7 (35), 5 (31), 6 (33).

İkili aramada da bir karşılaştırmada bulunsaydı orta nokta hemen 33'ün yerine gelmiş olmalıydı; interpolasyon, değerlerden yararlanarak doğrudan oraya yakın bir tahmin yapar. Hoca iki kodu yan yana gösterip yalnız orta nokta hesabının farklı olduğunu, geri kalan her şeyin aynı olduğunu vurgular.

### 4.3 `break` kullanmadan yazma

Sitedeki kod, eleman bulununca `break` ile döngüden çıkar. Hoca "hoca `break` kullanmayı yasakladıysa ne yaparsınız?" diye sorar. Bir öğrenci `if`'in koşulunu `while`'ın koşuluna taşımayı önerir. Hoca koşulun tersiyle alınması gerektiğini hatırlatır: "eleman bulunduysa çık" yerine "orta noktadaki eleman aranandan farklıysa aramaya devam et". Döngüden sonra da `index` belirlenir (ekrandan, 01:25:00):

```c
int lo = 0;
int hi = MAX - 1;
int mid = 0;
int comparisons = 1;
int index = -1;

while(lo <= hi && list[mid] != data) {
    ...
    comparisons++;
    mid = lo + (((double)(hi - lo) / (list[hi] - list[lo])) * (data - list[lo]));
    if(list[mid] < data) {
        lo = mid + 1;
    } else {
        hi = mid - 1;
    }
}
// döngüden sonra: lo > hi ise index = -1 (bulunamadı), değilse index = mid
```

Bu değişiklik sırasında iki hata çıkar:

- `mid`'in başlangıç değeri sitedeki kodda $-1$'di. Döngü koşulu artık `list[mid]`'e baktığı için ilk turda `list[-1]` okunur; dizide $-1$. eleman yoktur. Başlangıç değeri 0 yapılır.
- Döngü sonrasındaki kontrolde koşul ters yazılmıştı; eleman bulunduğu halde "bulunamadı" yazılıyordu. Arada verilen moladan sonra hoca bunu düzeltir: `lo`, `hi`'yi geçerse (`lo > hi`, ya da `hi < lo`) eleman yoktur ve $-1$ döndürülür; değilse bulunan yer orta noktadır.

Hoca aynı değişikliği ikili arama koduna da uygular; o kodda da aynı koşulun ters yazıldığı görülür ve düzeltilir. Ayrıca orta nokta hesabının döngünün başına alınmasıyla bir işlemin eksiltilebileceğini gösterir.

### 4.4 Aranan eleman dizide yoksa: interpolasyonun takılması

Hoca dizide olmayan 32'yi aratır. İkili arama doğru biçimde "bulunamadı" der. İnterpolasyon araması ise sonsuz döngüye girer. Hoca hata ayıklayıcıda (debug) `mid`, `list[mid]`, `lo` ve `hi` değişkenlerini izlemeye (add watch) alır. Ekran çıktısı (ekrandan, 01:40:00):

```text
Comparison 1
lo : 0, list[0] = 10
hi : 9, list[9] = 44
mid = 5

Comparison 2
lo : 6, list[6] = 33
hi : 9, list[9] = 44
mid = 5

Comparison 3
lo : 6, list[6] = 33
hi : 9, list[9] = 44
mid = 5
...
```

Adım adım: ilk tahmin $0 + \frac{9}{34}\cdot 22 \approx 5{,}8 \to 5$, `list[5] = 31 < 32` olduğu için `lo = 6`. İkinci turda $6 + \frac{3}{11}\cdot(32 - 33) \approx 5{,}7 \to 5$ bulunur; yine `list[5] = 31 < 32` ve `lo` yine 6 olur. `lo` ve `hi` değişmediği için aynı nokta etrafında takılıp kalınır. Hoca bunu interpolasyondaki bölme işlemlerine ve tahminin bir yerde ıraksamasına (divergence) bağlar.

> **Ders sonrası not:** Takılmanın doğrudan nedeni, aranan değer `list[lo]`'dan küçük olduğunda formülün `lo`'dan küçük bir `mid` (burada 5) üretmesi ve bu `mid`'in yeniden `lo = mid + 1 = 6` vermesidir. Bu durum ajan tarafından `gcc` ile aynı dizide denenerek doğrulandı. Yaygın çözüm, döngü koşuluna `data >= list[lo] && data <= list[hi]` eklemektir; bu derste yazılmadı.

### 4.5 Kitap benzetmesi

Hoca üç aramayı bir kitapta sayfa aramaya benzetir. 500 sayfalık kitapta 100. sayfa aranıyor olsun:

- Doğrusal arama 1. sayfaya, 2. sayfaya, 3. sayfaya tek tek bakar.
- İkili arama tam ortayı, 250. sayfayı açar; aranan daha küçük olduğu için o yarıya geçer, sonra yine ortayı açar. Böyle yarılaya yarılaya ilerler.
- İnterpolasyon araması, bizim kitabı aradığımız sayfaya yakın bir yerden tahminle açmamıza benzer. Hızlı sonuca gider ama aranan yoksa takılabilir.

> **Ders sonrası not:** Hoca ikili arama örneğinde ikinci adımı "125 ile 250" arası olarak söyledi. 100. sayfa arandığı için 250'den sonra 1–250 aralığının ortası olan 125'e bakılır ve 100 < 125 olduğu için 1–125 aralığına geçilir.

## 5. Bir dizinin sıralı olup olmadığını bulma

Dördüncü soru: bir dizinin sıralı olup olmadığını kontrol etmek (check if array is sorted or not) (ekrandan, 01:45:00).

### 5.1 `for` döngüsüyle çözüm

Bir öğrenci ikinci elemanın birinciyle, üçüncünün ikinciyle karşılaştırılmasını önerir; genelleştirilince `d[i+1]` ile `d[i]` karşılaştırılır. Sonucu tutmak için bir bayrak değişkeni kullanılır. Hoca, mantıksal olarak anlamlı olsun diye `sorted = 1` (sıralı) ile başlar ve sırayı bozan bir durum görülünce `sorted = 0` yapar (ekrandan, 01:50:00):

```text
sorted = 1;
for (i = 0; i < N-1; i++) {
    if (d[i+1] <= d[i])
        sorted = 0;
}
if (sorted == 1)  SORTED
else              NOT sorted
```

Artan sıraya göre kontrol edilir; varsayılan düzen genellikle budur. `{1, 2, 3, 4, 5, 6}` dizisinde 2 < 1 mi, 3 < 2 mi, ... sorularının hiçbiri doğru olmadığı için `sorted` hep 1 kalır ve dizi sıralıdır.

### 5.2 Karşı örnekte durmak: `while` ile çözüm

`for` çözümü her durumda $N$ adım döner. Oysa `{1, 4, 3, 4, 5, 6}` gibi bir dizide sıra bir kez bozulunca daha fazla bakmaya gerek yoktur. Hoca bu yüzden `for`'un burada döngünün doğasına aykırı olduğunu söyler ve tahtadaki `for` çözümünün üstünü çizer (ekrandan, 01:50:00):

```text
i = 0; sorted = 1;
while (i < N-1 && sorted == 1) {
    if (d[i+1] <= d[i])
        sorted = 0;
    i++;
}
if (sorted == 1)  SORTED
else              NOT sorted
```

Koşul iki cümleyi koda çevirir: sırayı bozan bir durum yok **ve** dizinin sonuna gelinmedi. Sıra bozulursa `sorted` 0 olur ve döngü `&&` sayesinde biter; dizi sıralıysa `i` son elemana kadar ilerler. İki kod da $O(N)$'dir ama ikincisi daha az kontrol yapma imkânı verir.

Bu kod bir fonksiyon içinde iki örnek diziyle `gcc -Wall` ile derlenip çalıştırıldı: `{1, 2, 3, 4, 5, 6}` için "sorted", `{1, 4, 3, 4, 5, 6}` için "not sorted" verdi.

> **Hocanın vurgusu:** Bu, karşı örnek (counter example) yaklaşımıdır. İlk derslerde mantıkta konuşulduğu gibi, bir şeyin doğruluğunu ispatlamak zordur ama yanlışlığını tek bir örnekle göstermek kolaydır.

### 5.3 Daha kötü bir çözüm: sıralayıp karşılaştırmak

İkinci çözüm: diziyi bir kopyasına sıralayarak aktarmak (örneğin kabarcık sıralamasıyla) ve sonra iki diziyi eleman eleman karşılaştırmak. Sıralanmış dizi ile orijinal aynıysa orijinal zaten sıralıdır. Ancak sıralamanın maliyeti en iyi ihtimalle $N \log N$ olduğu için bu çözüm $O(N)$ çözümden kötüdür.

## 6. Pointer'lar ve bellek organizasyonu

Beşinci soruya geçmeden önce hoca, sonraki örneklerde gerekeceği için bir programlama konusuna girer: pointer'lar. Konunun bir kısmı C'ye özgü, bir kısmı ise bütün programlama dilleri, işletim sistemi ve bilgisayar sistemleriyle ilgilidir.

### 6.1 Program bellekte nasıl yer alır

Slayttaki akış (ekrandan, 02:00:00):

```text
myprog.c / myprog.py  --(compile)-->  .exe  --(RUN)-->  RAM'de programa ayrılan bölge (memory location)
                                                         içinde: Data section
```

Metin halindeki program derlenir (compile), bağlanır (link) ve çalıştırılabilir hale gelir. Çalıştırıldığında işletim sistemi RAM'de programa bir yer ayırır. Program artık bir süreç (process) olur; hoca bunu Windows Görev Yöneticisi'nde birleştirme programının ve Dev-C++'ın birer süreç olarak göründüğünü göstererek anlatır. Kısa süren program hemen kapandığı için listede bir an görünüp kaybolur.

Programa ayrılan bölgede üç tür bilgi vardır: programın kodu, programın kullandığı veriler ve işletim sisteminin sürece ait tuttuğu bilgiler. Hoca bu son kısım için süreç kontrol bloğu (process control block) görselini açar: program sayacı (program counter), açık dosyalar, hesap (accounting) bilgileri, süreç kimliği gibi alanlar içerir.

> **Ders sonrası not:** Süreç kontrol bloğu (PCB), programın kendi adres alanında değil, işletim sisteminin çekirdek belleğinde tutulur; programa ayrılan bölgede kod, veri, heap ve stack bulunur.

### 6.2 Data section: stack, heap, global ve static

Programın değişkenlerinin tutulduğu veri kısmı (data section) kendi içinde bölümlere ayrılır (ekrandan, 02:00:00):

- Stack: `int`, `float`, `int *` gibi değişkenler ve `int a[10];` gibi sabit uzunluklu diziler.
- Heap
- Global değişkenler (global variables)
- Static değişkenler (static variables)

Şimdilik genellikle stack kullanılır; diğerleri yeri geldiğinde kullanılacaktır.

> **Ek bilgi (derste anlatılmadı):** Yaygın anlatımda bir sürecin bellek görüntüsü kod (text), başlangıç değerli ve değersiz global/static veriler (data, bss), heap ve stack bölümlerinden oluşur. Heap, çalışma sırasında `malloc` gibi fonksiyonlarla ayrılan bellek içindir.

Stack, yığın demektir: tabak yığını gibi her şey üste eklenir ve alınırken de en üstten alınır. A, sonra B, sonra C eklenmişse aradan B çıkarılamaz; her zaman tepedeki silinir.

Program çalışınca önce `main` fonksiyonu çalıştığı için stack'e önce `main` gelir. `main` içinde tanımlanan bütün değişkenler belli bir düzene göre, birbirinin ardına yerleştirilir.

### 6.3 Adresleri `%p` ile görmek

Hoca, `scanf`'te kullanılan `&` (adres) operatörünü bu kez `printf` ile kullanır ve değişkenlerin adreslerini `%p` biçim belirteciyle 16'lık tabanda yazdırır (ekrandan, 02:05:00):

```c
#include <stdio.h>

#define M 8
#define N 3
int main()
{
    int i,x,y;
    int a[N] = {1,4,12};
    int b[M] = {2,3,6,7,8,9,10,11};
    int c[N+M];

    printf("%p >> i\n",&i);
    printf("%p >> x\n",&x);
    printf("%p >> y\n",&y);
    printf("%p >> a[0]\n",&a[0]);
    printf("%p >> b[0]\n",&b[0]);

    return 0;
}
```

Bu adresler, işletim sisteminin kendi kriterlerine göre programa verdiği bölgeden gelir ve her çalıştırmada farklı olabilir. Çıktıda görülenler:

- Değişkenler belleğe gelişigüzel serpiştirilmez; ardışık yerleşir.
- `int` 4 bayt olduğu için ardışık değişkenlerin adresleri 4'er bayt farklıdır.
- Değişkenlerin hemen ardından, arada boşluk bırakılmadan diziler gelir.
- Stack yüksek adresten (high address) düşük adrese (low address) doğru doldurulur. Hoca önce tersini çizer, sonra düzeltir: mantık değişmez, yalnız adres değerlerinin yönü değişir.

Adresleri bilmek programın nasıl organize edildiğini anlamaya yarar; ama bazen bir değişkenin adresine gerçekten ihtiyaç duyulur. Birleştirme örneğindeki iki döngüyü tek döngüye indirme isteği bunun bir örneğidir. Bu ihtiyacı karşılayan yapı pointer'lardır.

### 6.4 Pointer değişkenleri

Pointer değişkeni yeni bir değişken türü gibidir. `int` tamsayı tutar; `int` pointer ise `int` türündeki bir değişkenin adresini tutar. İçine 3, 5, 10 gibi değer konamaz, yalnız adres konur. Tanımlarken önüne `*` konur. Slayttaki örnek (ekrandan, 02:15:00):

```c
int a;   int ar[5];
int *pa;          // pointer variable declaration
pa = &a;
pa = &ar[0];
```

**Soru:** Yıldız başka nerede kullanılır? **Cevap:** Çarpmada. Ama çarpma iki işlenenli (sol ve sağ) bir işlemdir; pointer tanımındaki `*` ise tek işlenenli (unary) bir operatördür, yalnız sağında bir şey vardır.

`pa = &ar[0]` yazılır, `pa = ar[0]` yazılamaz; elemanın değeri değil adresi gerekir. Bundan sonra diziye yapılan erişimler `pa` üzerinden de yapılabilir.

Bellek çiziminde önce `a` (4 bayt), sonra 5 hücreli `ar` dizisi (her hücre 4 bayt), sonra `pa` yer alır. Pointer değişkenleri genellikle 8 bayttır; bu, belleğin boyutuna ve işletim sisteminin adresleme kapasitesine bağlıdır ve 16 bayt olduğu durumlar da vardır. `pa = &a` denince `a`'nın adres değeri (çizimde $\alpha$) `pa`'nın hücresine kopyalanır.

Pointer'ın türü, gösterdiği değişkenin türüyle aynı olmalıdır. `float` bir değişken için `float *pf` tanımlanır (ekrandan, 02:10:00):

```c
int i,x,y;
float f;
int *pa;
float *pf;

pa = &i;
pf = &f;

printf("%p -- %p >> i\n",&i,pa);
```

`&i` ile `pa` aynı adresi yazar; `pa` zaten adres tuttuğu için önüne `&` konmaz.

### 6.5 Adresteki değere ulaşmak: dereferans

`i`'ye 5, `f`'ye bir ondalık değer verildikten sonra `printf("%d %f", i, f)` ile değerler değişken adlarıyla yazdırılır. Pointer'ın güzelliği, değişkenin değerine pointer üzerinden de ulaşılabilmesi ve istenirse değiştirilebilmesidir. Bunun için referansla (`&`) yapılan işlem geri alınır: dereferans, yani `*pi` ve `*pf`. Bu ifade "pointer'ın gösterdiği yerdeki bellek içeriğini getir" demektir ve aynı sonuçları verir.

`printf("%d %f", pi, pf)` yazılırsa hatalı bir sonuç görülür, çünkü `pi` ve `pf`'nin tuttuğu değerler adreslerdir.

Pointer konusundaki iki temel operatör (ekrandan, 02:15:00):

- Adres/referans operatörü `&`: bir değişkenin adresini verir.
- Değer/dereferans operatörü `*`: bir adresteki değeri verir. `*` ayrıca pointer değişkeni tanımlarken de kullanılır.

### 6.6 `scanf` neden adres ister?

**Soru:** `scanf("%d", &i)` içinde neden `&` kullanılır? Bir öğrenci "C bizden belleğe doğrudan erişmemizi istiyor olabilir" der; hoca bunun yaklaştığını söyler. **Cevap:** `scanf` klavyeden girilen değeri `i` ile temsil edilen bellek hücresine kopyalar. `scanf` bir fonksiyondur; `i`'nin içeriğinin bu fonksiyonda değişmesi ve çağıran `main`'e yansıması gerekir. Yansımazsa değer boşuna girilmiş olur. Bir değişken bir fonksiyona parametre olarak gidiyorsa ve içeriğinin değişmesi isteniyorsa mutlaka adresi gönderilmelidir. `printf`'te içerik değişmediği, yalnız ekrana basıldığı için adres gönderilmez.

Hoca, pointer'ın çoğu programlama dilinde görünürde olmadığını ama arka planda aslında bulunduğunu da ekler.

## 7. Fonksiyonlara giriş: değerle ve adresle çağrı

Pointer'ların burada birlikte anlatılmasının sebebi fonksiyonlardır; ayrıntıları sonraki derslerde gelecektir. `printf`, `scanf` ve matematik fonksiyonları zaten kullanılan fonksiyonlardır: bir kez yazılıp tekrar tekrar kullanılabilen, gereksiz işten kurtaran yapılar. Fonksiyona parametreler verilir, fonksiyon bunları işler ve isterse bir değer döndürür (return). Fonksiyon `main` içinden ya da başka bir fonksiyonun içinden çağrılabilir.

### 7.1 Kod tekrarından fonksiyona

10 elemanlı bir diziyi yazdırmak için `for` döngüsüyle `printf` yazılır. Diziyi yeniden yazdırmak gerektiğinde (örneğin bir eleman değiştikten sonra) aynı kod kopyalanıp yapıştırılır. **Soru:** Bu kodda ne sorun var? **Cevap (bir öğrenci):** Kendimizi tekrar ediyoruz. Hoca bunu onaylar: buna kod tekrarı (duplicated code) denir. Kod 20 satır olsaydı ve bir değişiklik yapılması gerekseydi her kopyada ayrı ayrı yapılması gerekirdi; bu iyi bir şey değildir, "mühendislikle alakası yoktur".

Çözüm bir `yazdir` fonksiyonudur. Fonksiyon `main`'den önce ya da sonra yazılabilir; hoca `main`'den sonra yazmaya alışılmasını ister. Dönüş değeri olmadığı için `void` kullanılır; parametreler, gönderilen değerlerle aynı türde tanımlanır. Dizi parametresinde eleman sayısı yazılmaz (ekrandan, 02:25:00):

```c
#define N 10
void yazdir(int a[], int n);
int main(){
    int a[N];
    int i;
    yazdir(a,N);
    a[4] =5;
    yazdir(a,N);
}

void yazdir(int a[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d -",a[i]);
    }
    printf("\n");
}
```

Fonksiyon `main`'den sonra yazılınca derleyici bir uyarı verir; `main`'den önce fonksiyonun başlığını (prototipini) yazmak bu uyarıyı giderir. Hoca bunun ayrıca konuşulacağını söyler. Böylece 3–4 satırlık kod tek satırlık bir çağrıya iner; bir kez yazılan fonksiyon birçok kez kullanılır ve başkalarına açılırsa onlar da kullanır (`printf` gibi).

**Soru:** Fonksiyondaki `for` döngüsünde `N` yerine `n` olması gerekmiyor mu? **Cevap:** Evet, iyi bir tespit. `N` derlemede 10 ile değiştirildiği için program yine çalışır, ama parametre `n` o zaman boşa çıkar; doğrusu `i < n` yazmaktır.

### 7.2 Kapsam (scope): aynı adlı değişkenler karışır mı?

Hoca `main`'e `int n = N;` ekler, fonksiyona `n`'yi gönderir ve iki yerde de `n`'yi yazdırır (ekrandan, 02:30:00). **Soru:** `main`'deki `n` ile `yazdir`'daki `n` birbirine karışır mı? **Cevap (bir öğrenci):** Kapsamları (scope) farklı olduğu için karışmaz.

Hoca bunu bellek organizasyonuyla açıklar: `main` çağrıldığında stack'e eklenir; `yazdir` çağrılınca onun alanı `main`'in üstüne gelir; `yazdir` içinde `printf` çağrılınca o da onun üstüne gelir. Her birinin kendi alanı vardır; dolayısıyla iki `n` ayrı hücrelerdir.

Sonra `yazdir`'ın sonuna `n = 6;` ve bir `printf` eklenir. **Soru:** Fonksiyon döndükten sonra `main`'deki `printf` ne yazar? **Cevap:** 10. Çağrıda `main`'deki `n`'nin değeri fonksiyondaki `n`'ye birebir kopyalanır (değer kopyalama); fonksiyondaki değişiklik yukarıya yansımaz. Fonksiyon ikinci kez çağrıldığında yine 10 ile başlar, içeride 6 olur. Her çağrı öncekinden bağımsızdır, kaldığı yerden devam etmez.

### 7.3 Takas fonksiyonu: değerle çağrı

Geçen derste görülen takas (swap) işlemi bir fonksiyon olarak yazılır (ekrandan, 02:35:00):

```c
void takas(int x, int y){
    int t;
    t = x;
    x = y ;
    y = t;
}
```

`main`'de `x = 2`, `y = 6` tanımlanır, yazdırılır, `takas(x, y)` çağrılır ve yeniden yazdırılır. **Soru:** İkinci `printf` ne yazar? **Cevap (bir öğrenci):** Değişmez; yalnız değer kopyalanmış olur. Gerçekten de ekranda iki kez `x = 2, y = 6` görülür. `takas` çalışınca kendi `x` ve `y`'si oluşturulur, takas onların üzerinde yapılır ve `main`'e yansımaz. Fonksiyondaki parametre adlarının `x` ve `y` olması da gerekmez; amaç iki `x`'in bağımsız olduğunu göstermektir.

`yazdir`'da dönüş değerine ihtiyaç yoktu, çünkü yalnız ekrana yazılıyordu; `takas`'ta ise sonuç `main`'e ulaşmadığı için fonksiyon işe yaramadı. Hoca `scanf`'i hatırlatır: orada da sonuç dönüş değeriyle alınmaz, `i`'nin adresi gönderilir ve `i` klavyeden girilen değere göre değişir. `scanf`'in de aslında bir dönüş değeri vardır, ama `i`'nin değeri bu yolla alınmaz.

> **Ek bilgi (derste anlatılmadı):** `scanf` başarıyla okunan öğe sayısını, `printf` ise yazdırdığı karakter sayısını döndürür.

### 7.4 `takasv2`: adresle çağrı

Pointer bilgisiyle fonksiyon birleştirilir: `takasv2(&x, &y)` çağrısında değişkenlerin adresleri gönderilir. Gelen veriler adres olduğu için parametreler pointer olarak tanımlanır ve takas dereferansla yapılır (ekrandan, 02:40:00):

```c
void takasv2(int *x, int *y){
    int t;
    t = *x;
    *x = *y ;
    *y = t;
    *x=9999;
}
```

`t = *x`: `x`'in gösterdiği yerdeki değeri (2) `t`'ye kopyalar. `*x = *y`: `y`'nin adresine gidip oradaki 6'yı alır ve `x`'in adresindeki bellek hücresine yazar. `*y = t`: geçici değeri `y`'nin adresine yazar. Program ilk çalıştırmada beklenen çıktıyı vermez gibi görünür; sebep koddaki bir `scanf`'in klavyeden giriş beklemesidir. Sonra ekranda takastan önce `2 6`, `takas`'tan sonra `2 6`, `takasv2`'den sonra `6 2` görülür.

Parametre olarak bir değişkenin adresi gönderildiği için fonksiyonda adres üzerinden yapılan her değişiklik çağırana yansır. Örneğin fonksiyonun sonuna `*x = 9999;` eklenirse, fonksiyon bittikten sonra çağıran yerdeki `x` de 9999 olur.

Değerle ve adresle takas, bir tam programda `gcc -Wall` ile derlenip çalıştırıldı (`*x = 9999;` satırı olmadan): `takas`'tan sonra `x=2, y=6`, `takasv2`'den sonra `x=6, y=2` yazdı.

**Soru:** Pointer'ları bellek yönetimi açısından kullanıyor muyuz? Gereksiz kopya oluşmasını engellediğini hatırlıyorum. **Cevap:** Adres üzerinden değerlere erişmek basit anlamda bir bellek yönetimidir; istenen herhangi bir adrese erişmek ise ayrı bir konudur. Kopya konusunda haklısın: `takas(x, y)` çağrısında değerler birebir kopyalanır ve bellekte iki gereksiz hücre oluşur (yukarıda `x`, `y`, aşağıda kopyaları). Adres gönderilince fonksiyondaki değişkenler yalnız adres tutar; aynı değerler iki kez saklanmaz.

### 7.5 Sonraki derslere bağlantı

Hoca, bundan sonraki soruların kod üzerinde çözüleceğini ve bunun için fonksiyon ve pointer bilgisinin gerektiğini söyler; kağıt üzerinde ilerlemek kolay olsa da kod üzerinde bu bilgiler olmadan ilerlemek zordur. Fonksiyonların başka ayrıntıları sonraki derslerde anlatılacaktır; öğrencilerin fonksiyon ve pointer örnekleriyle alıştırma yapması istenir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:10:00): Merging two sorted array: $N$ elemanlı sıralı `L1` ve $M$ elemanlı sıralı `L2` dizilerini $N+M$ elemanlı sıralı `L3` dizisinde birleştirin. Karmaşıklığı en düşük çözüm nedir?

> **Çözüm (derste verildi):** İki indisle küçük olan eleman alınır, ilgili indis ilerletilir; biri bitince öbürünün kalanı kopyalanır. Kod Bölüm 1.4'tedir. Karmaşıklık $O(N+M)$; önce birleştirip sonra sıralamak ise $O(N \log N)$'dir.

**Soru 2** (ekrandan, 00:55:00): Search an element in an array: $N$ elemanlı bir dizide bir anahtarı arayın. En iyi, en kötü ve ortalama durum karmaşıklığı nedir?

> **Çözüm (derste verildi):** `while (i < N && dizi[i] != key) i++;` Döngüden sonra `i == N` ise bulunamadı. En iyi 1, en kötü $N+1$, ortalama $N/2 \approx N$.

**Soru 3** (ekrandan, 01:05:00): Search an element in a sorted array: sıralı bir dizide arama nasıl daha hızlı yapılır?

> **Çözüm (derste verildi):** İkili arama: `mid = (i+j)/2`; `dizi[mid] < key` ise `i = mid+1`, değilse `j = mid-1`; döngü `i <= j && dizi[mid] != key` iken döner. Karmaşıklık $\log_2 N$; 1024 elemanda 10 adım.

**Soru 4** (ekrandan, 01:45:00): Check if array is sorted (or not): bir dizinin artan sırada sıralı olup olmadığını bulun.

> **Çözüm (derste verildi):** `sorted = 1` ile başla; `while (i < N-1 && sorted == 1)` içinde `d[i+1] <= d[i]` ise `sorted = 0`; her turda `i++`. $O(N)$. Sıralayıp karşılaştırmak $O(N \log N)$'dir.

**Soru 5** (derste sözlü, 01:18:33): İnterpolasyon araması kodunda eleman bulununca `break` ile döngüden çıkılıyor. `break` kullanmak yasak olsaydı kod nasıl yazılırdı?

> **Çözüm (derste verildi):** "Bulunduysa çık" koşulunun tersi döngü koşuluna eklenir: `while (lo <= hi && list[mid] != data)`. `mid` başta 0 yapılır. Döngüden sonra `lo > hi` ise `index = -1`, değilse `index = mid`.

**Soru 6** (derste sözlü, 02:14:19): `scanf("%d", &i)` içinde `i`'nin adresi neden gönderilir?

> **Çözüm (derste verildi):** `scanf` bir fonksiyondur ve `i`'nin içeriğini değiştirmesi, bu değişikliğin çağıran fonksiyona yansıması gerekir. İçeriği değişecek bir değişken fonksiyona adresiyle gönderilmelidir. `printf` içeriği değiştirmediği için adres istemez.

**Soru 7** (derste sözlü, 02:28:30): `yazdir(a, n)` çağrısında fonksiyon içinde `n = 6` yapılıyor. Fonksiyon döndükten sonra `main`'de `printf("n: %d\n", n)` ne yazar? (`main`'de `n = 10`.)

> **Çözüm (derste verildi):** 10. Değer kopyalanarak gönderildiği için fonksiyondaki değişiklik `main`'deki `n`'ye yansımaz.

**Soru 8** (derste sözlü, 02:31:33): `x = 2, y = 6` iken `takas(x, y)` çağrısından sonra `printf` ne yazar? `takasv2(&x, &y)` çağrısından sonra ne yazar?

> **Çözüm (derste verildi):** `takas`'tan sonra `x = 2, y = 6` (değişmez); `takasv2`'den sonra `x = 6, y = 2`.

## Dersin Toparlaması

Bu derste dizilerle ilgili ilk dört soru çözüldü. İki sıralı diziyi birleştirmede, birleştirip sıralamanın $N \log N$ maliyetinden iki işaretçili karşılaştırma ile $O(N+M)$'ye inildi; sentinel çözümü ve dizi bittikten sonra kalanı kopyalayan iki `while` yaklaşımı karşılaştırıldı. Aramada doğrusal aramanın en iyi, en kötü ve ortalama durumları, sıralı dizide ikili aramanın $\log_2 N$ karmaşıklığı ve orta noktayı tahmin eden interpolasyon araması görüldü; interpolasyonun aranan eleman yokken takılabildiği hata ayıklayıcıyla gösterildi. Sıralılık kontrolünde karşı örnek bulununca duran `while` çözümü, `for` çözümüne tercih edildi. Bütün bu çözümlerde ortak ders şuydu: döngünün ne zaman biteceği belli değilse `while` kullanılır ve algoritma her durum için denenir.

Dersin ikinci yarısında, sonraki sorular kod üzerinde çözüleceği için pointer'lara ve fonksiyonlara giriş yapıldı. Programın bellekteki yerleşimi, stack'in çalışması, `&` ve `*` operatörleri, fonksiyonlarda değerle çağrı ve kapsam, adresle çağrının (`takasv2`) değişkeni nasıl değiştirdiği anlatıldı. Sonraki derslerde fonksiyonların diğer ayrıntılarıyla birlikte kalan dizi sorularına bu bilgilerle devam edilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
