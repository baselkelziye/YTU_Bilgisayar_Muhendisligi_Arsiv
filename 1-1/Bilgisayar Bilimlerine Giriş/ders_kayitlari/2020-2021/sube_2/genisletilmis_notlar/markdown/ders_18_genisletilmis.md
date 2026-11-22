# Ders 18 Genişletilmiş Notu: Sıralama: Bubble Sort, Selection Sort ve Sıralı Dizileri Birleştirme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Çalışma Yöntemi: Problem, Akış, Kod
- 2. Sıralama Problemi
- 3. Bubble Sort
- 4. Bubble Sort Akışı
- 5. Akıştaki Döngü Sınırı Hatası
- 6. lvalue, rvalue ve İlk Değer
- 7. Bubble Sort'un C Kodu
- 8. Selection Sort
- 9. Selection Sort Akışı
- 10. Selection Sort'un C Kodu ve Derleme Hataları
- 11. Sıralamada Adım Sayısı Belli mi?
- 12. İki Sıralı Diziyi Birleştirme
- 13. printf ile Hata Ayıklama ve G/Ç Tamponlama

## 1. Çalışma Yöntemi: Problem, Akış, Kod

Önceki laboratuvar oturumunda C ile ilk örnekler yazılmıştı. Hoca bu dersten itibaren çalışmanın şöyle ilerleyeceğini söyledi: bir problem üzerine konuşulur, akışı hazırlanır, akış bittikten sonra C'de kodlanır. Adım adım gidilir.

> **Hocanın vurgusu:** Bir problem verildiğinde önce akışın çizilmesi, sonra kodun yazılması beklenir. "Kodu biliyorum, doğrudan yazayım" yaklaşımı kabul edilmez. Çizilen akış ile yazılan kod birbiriyle uyumlu olmalıdır.

## 2. Sıralama Problemi

Bilgisayar sistemlerinde çok sık karşılaşılan ve çözülmek zorunda kalınan problemlerden biri sıralamadır (sort). Bunun için farklı algoritmalar vardır; hoca aklına gelenlerden birkaçını saydı: merge sort, bubble sort, quick sort, selection sort. Bu derste sıralamanın ne olduğu konuşuldu ve bu yöntemlerden bazılarının üzerinden geçildi.

Sıralama için önce bir diziye ihtiyaç vardır. Hoca rastgele elemanlardan oluşan bir dizi yazdı ve bunun küçükten büyüğe sıralanmasını hedef olarak koydu (ekrandan, 00:15:00):

```text
Dizi              :  9  3  7  11  66  23   6  41
Küçükten büyüğe   :  3  6  7   9  11  23  41  66
```

Varılmak istenen yer, en küçük elemanın (3) başta, sonra 6, 7, 9, 11, 23, 41 ve en sonda 66'nın olduğu dizidir.

## 3. Bubble Sort

Bubble sort'ta yapılan şey, dizinin en başından başlayarak her elemanı sağındakiyle karşılaştırmaktır. Sağdaki eleman soldakinden küçükse ikisi yer değiştirir. Sonra bir sonraki elemana geçilir. Dizinin son gözüne kadar gidildiğinde bir tur tamamlanmış olur.

### 3.1 Birinci tur

`9 3 7 11 66 23 6 41` dizisinde birinci tur şöyle ilerler:

- 9 ile 3: 3 daha küçük, yer değiştirirler → `3 9 7 11 66 23 6 41`
- 9 ile 7: 7 daha küçük, yer değiştirirler → `3 7 9 11 66 23 6 41`
- 9 ile 11: değişikliğe gerek yok.
- 11 ile 66: değişikliğe gerek yok.
- 66 ile 23: 23 daha küçük → `3 7 9 11 23 66 6 41`
- 66 ile 6: 6 daha küçük → `3 7 9 11 23 6 66 41`
- 66 ile 41: 41 daha küçük → `3 7 9 11 23 6 41 66`

Birinci turun sonunda dizi `3 7 9 11 23 6 41 66` olur (ekrandan, 00:20:00). En büyük eleman olan 66 bir turda dizinin sonuna taşınmıştır.

### 3.2 Sonraki turlar

Dizi hâlâ sıralı olmadığı için tekrar baştan başlanır. Hocanın tahtadaki işaretleriyle (her komşu çift için "tamam" ya da "değil") turlar şöyledir (ekrandan, 00:20:00; python ile doğrulandı):

```text
1. tur sonu :  3  7  9  11  23   6  41  66
2. tur sonu :  3  7  9  11   6  23  41  66    (23 ile 6 yer değiştirdi)
3. tur sonu :  3  7  9   6  11  23  41  66    (11 ile 6)
4. tur sonu :  3  7  6   9  11  23  41  66    (9 ile 6)
5. tur sonu :  3  6  7   9  11  23  41  66    (7 ile 6)
6. tur      :  hiçbir çift yer değiştirmedi -> dizi sıralı
```

Hoca beşinci tura neden geçildiğini şöyle açıkladı: bir önceki turda dizi boyunca ilerlerken değişiklik yapılan bir yer vardı. Altıncı turda 3-6, 6-7, 7-9, 9-11, 11-23, 23-41, 41-66 çiftlerinin hepsi "tamam" çıkar. Değişecek hiçbir şey kalmadığı için daha fazla kurcalamaya gerek yoktur ve dizi sıralanmış sayılır. Bubble sort'un çalışma mantığı budur: değişiklik yapılan bir tur olmadığı ana kadar turlara devam edilir.

## 4. Bubble Sort Akışı

### 4.1 Akışın fikri

Her turda dizinin ilk elemanından son elemanına kadar kontrol edilerek gidilir: `I`. eleman `I+1`. elemandan büyükse yer değiştirilir, küçükse bir şey yapılmaz. Bu bir turdur. Tur bittiğinde hiçbir iki elemanın yeri değişmemişse dizi sıralıdır. Şart budur.

Hoca burada sıralama yönünün sabit olmadığını belirtti: küçükten büyüğe sıralanabildiği gibi büyükten küçüğe de sıralanabilir. Akıştaki karşılaştırma ters çevrilerek yön değiştirilir. Küçükten büyüğe sıralamak için `A(I) > A(I+1)` sorulur, doğruysa ikisinin yeri değiştirilir.

Takas yapıldığında, değişiklik olduğunu anlamayı sağlayacak başka bir değişkenin de değiştirilmesi gerekir. Çünkü dizi üzerinde kurulacak for döngüsü diziyi yalnız bir kez dolaşır. Asıl ihtiyaç, değişiklik olmadığı sürece bu döngüyü baştan tekrar başlatmaktır. Bu yüzden for döngüsü başka bir döngünün içinde olmalıdır: iki iç içe döngü. Dıştaki döngü kaç kez döneceği bilinen bir döngü değildir. Hoca bunu şöyle anlattı: karşılaştırma işlemini dizi boyunca on kez mi, beş kez mi, yüz kez mi, eleman sayısı kadar mı yapacağı konusunda hiçbir bilgisi yoktur; yalnız elemanlar yer değiştirmediği zaman duracağını bilir. Bu kontrol uygun bir değişken üzerinden yapılır.

### 4.2 swapped değişkeni

Bu kontrol için `SWAPPED` adlı bir değişken kullanılır:

- Dış döngüden önce `SWAPPED = 1` atanır. Değişken döngü değişkeni olarak kullanılacağı için döngüye girilebilmesi için önce 1 olmalıdır.
- Dış döngü `SWAPPED = 1` olduğu sürece döner.
- Döngüye her girildiğinde `SWAPPED = 0` yapılır, çünkü her turda takas yapılıp yapılmadığı ayrıca kontrol edilmek istenir.
- İç döngüde bir takas yapıldığında `SWAPPED = 1` yapılır.

### 4.3 Takas

Takas, daha önce de denenen geçici değişken yöntemiyle yapılır: `TMP` değişkenine `A(I)` atanır, `A(I)`'ya `A(I+1)` atanır, `A(I+1)`'e `TMP` atanır. Böylece iki dizi elemanının yeri değişir. Ardından `SWAPPED = 1` atanır.

### 4.4 Çizilen akış

Hocanın çizdiği akış (ekrandan, 00:35:00 ve 00:50:00):

```text
START
  |
[ N, A(N) ]                           (girdi)
  |
[ SWAPPED = 1 ]
  |
< SWAPPED = 1 > <------------------------------ (1)
  | F                 | T
 (2)            [ SWAPPED = 0 ]
                      |
                [ I <- 1 || 1 ; bitiş N ] <-----------+
                  | (bitince)      | (gövde)          |
                 (1)         < A(I) > A(I+1) >        |
                              F |          | T        |
                                |   [ TMP = A(I)      ]
                                |   [ A(I) = A(I+1)   ]
                                |   [ A(I+1) = TMP    ]
                                |   [ SWAPPED = 1     ]
                                +----------+----------+
```

Döngü bitince akış bağlantı noktası (1) ile koşullu döngünün başına döner. Koşul yanlış olunca bağlantı noktası (2) ile dizinin ekrana yazdırıldığı kısma geçilir. Hoca yazdırma kısmı sayfaya sığmayacağı için onu bağlantı noktasıyla ayırdı.

<!-- BELİRSİZ: (2) bağlantı noktasından sonraki yazdırma döngüsü ve STOP kısmı incelenen karelerde görünmüyor; altyazıya göre dizi ekrana yazdırılıp akış bitiriliyor. -->

Bu akışta for döngüsünün bitişi `N` yazılmıştır; bunun hatalı olduğu bir sonraki bölümde gösterildi.

## 5. Akıştaki Döngü Sınırı Hatası

Hoca akışı çizdikten sonra, analiz bile yapmadan tehlikeli bir nokta gördüğünü söyledi ve sınıfa sordu. Bir öğrenci hatayı buldu: for döngüsünde `I`, `N`'ye eşit olduğunda `A(I+1)` denince dizinin dışına çıkılıyor.

Hoca açıklamayı şöyle genişletti. Dizinin eleman sayısı `N`'dir; dizi birinci elemandan başlar, `N`. elemanda biter. Döngüde `I` sırayla 1, 2, 3, ... değerlerini alır ve en sonunda `N` olur. Gövdede `I` ile dizinin elemanlarına referans verilir. Yalnız `A(I)` kullanılsaydı sıkıntı olmazdı: `I = 1` için birinci eleman, `I = N` için `N`. eleman. Ama `I+1` ile de referans veriliyor. `I = N` olduğunda `N`. eleman ile `N+1`. eleman karşılaştırılmaya çalışılır; `N+1`. eleman diye bir şey yoktur. Bu, akışta hatalı bir akıştır.

Gerçek hayatta ne olacağı kullanılan programlama diline bağlıdır:

- Bunu derleme zamanında kontrol eden programlama dili çok nadirdir.
- Bir kısmı çalışma zamanında "out of bounds exception" gibi bir hata verir.
- C ise bununla ilgili hata vermez. Dizinin ve programın bellekteki yerine, dizinin kodda hangi sırayla tanımlandığına göre değişen bir ihtimaller sürüsü vardır: hata da alınabilir, hiçbir şey olmayabilir.

Doğru çözüm için `I` her seferinde bir sonraki elemana da eriştiğine göre döngünün bitişi `N-1` olmalıdır (ekrandan, 00:40:00).

> **Hocanın vurgusu:** Döngü içinde indis üzerinde ekstra bir işlem yapılıyorsa (bir fazlasına ya da bir eksiğine erişmek gibi), döngü sınırının uygun ve doğru olup olmadığı bir kez daha kontrol edilmelidir.

## 6. lvalue, rvalue ve İlk Değer

Bu sırada bazı öğrencilerden `TMP`'nin akışta ilk değeri olmadığına dair bir soru geldi. Hoca bunu lvalue ve rvalue konusuyla açıkladı (ekrandan, 00:40:00).

`x = y + 1;` ifadesi düşünülsün. Bu ifadede `x`'in önceden bir değerinin olmasının bir anlamı yoktur. `x` bu ifadede ilk kez kullanılıyorsa, önceden ilk değer verilip verilmediği önemsizdir; `x`, `y`'nin değerinin bir fazlasının atandığı yerdir ve bu ifadeden sonra istenen bir değere sahip olur. Ama `y` ilk kez burada kullanılıyorsa `y`'nin değeri bilinmez. O zaman `x`'e de bilinmeyen, kontrol dışında bir değer gönderilmiş olur.

Takasta `TMP` ilk kez sol tarafta kullanılır: `A(I)`'nın değerini kenara almak için. Sonra `A(I)`'ya `A(I+1)` yazılır, en sonda kenara alınan değer `A(I+1)`'in yerine yazılır. Bu noktada `TMP`'nin bir ilk değerinin olması söz konusu değildir.

Hoca ayrıca akışta hiçbir değişkenin tanımlanmadığını hatırlattı. Değerler girdi alanı üzerinden okunur; okunduğunda dışarıdan alındıkları ve kullanıcı tarafından ilklendirildikleri bellidir. Değeri kontrol edilecek ya da hesapta kullanılacak değişkenlere ise ilk değer atanır ve öyle kullanılır. Örneğin `SWAPPED`'e 1 atanıp ondan sonra "1 olduğu sürece" döngüsü kurulmuştur; döngü değişkeni `I`'nın ilk değeri de döngü kutusunda atanır.

> **Hocanın vurgusu:** Bir değişken sol tarafta işleme giriyorsa ilk değer ataması önemli değildir. Sağ tarafta bir hesaba girip sonuç üretecekse ilk değeri önemlidir.

## 7. Bubble Sort'un C Kodu

Hoca akışı ve kodu aynı anda göstermeye çalıştı, olmayınca kodu da tahtaya yazdı.

### 7.1 Kodun kurulması

- `#include <stdio.h>` ile kütüphane açılır.
- Dizi statik bir yapı olduğu için eleman sayısına belirli bir sabit verilir (100, 1000 gibi). Hoca bu sayıların ortada dolaşan sabitler olarak değil, makro olarak tanımlanmasını tercih ettiğini hatırlattı: `#define SIZE 100`.
- `int main(void)` ile başlanır. Değişkenler: döngü değişkeni `i`, eleman sayısı `n`, geçici değişken `tmp`, ilk değeri 1 olan kontrol değişkeni `swapped` ve dizi `ar[SIZE]`.
- Değişkenler tek satırda "tren gibi" tanımlanabildiği gibi mantıksal olarak gruplara bölünerek de tanımlanabilir (ör. bir satırda `i` ve `n`, bir satırda `tmp` ve `swapped`, ayrı bir satırda dizi). Sonuçta hepsi aynı noktaya çıkar.
- Önce eleman sayısı okunur, sonra bir for döngüsüyle dizinin elemanları okunur.
- Sonra akıştaki döngüler koda aktarılır: `while (swapped)`, içinde `swapped = 0;`, ardından for döngüsü, `if` ve takas.
- En sonda dizi bir for döngüsüyle yazdırılır. `printf("%d\t", ar[i]);` ile elemanlar yan yana, aralarında boşlukla düzgün görünecek biçimde basılır; `\t` bir sonraki tab durağına kadar boşluk bırakır. Döngüden sonra `printf("\n");` ile satır bitirilir.

### 7.2 Kod

Tahtadaki kod (ekrandan, 00:55:00 ve 01:00:00); `gcc -Wall` ile derlendi ve örnek diziyle `3 6 7 9 11 23 41 66` çıktısını verdi (ajan tarafından test edildi):

```c
#include <stdio.h>
#define SIZE 100

int main(void) {
    int i, n, tmp, swapped = 1, ar[SIZE];
    printf("Please enter # of elements : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Please enter %d. eleman", i);
        scanf("%d", &ar[i]);
    }
    while (swapped) {
        swapped = 0;
        for (i = 0; i < n - 1; i++) {
            if (ar[i] > ar[i + 1]) {
                tmp = ar[i];
                ar[i] = ar[i + 1];
                ar[i + 1] = tmp;
                swapped = 1;
            }
        }
    }
    for (i = 0; i < n; i++) {
        printf("%d\t", ar[i]);
    }
    printf("\n");
    return 0;
}
```

Kodda for döngüsünün sınırı `i < n-1`'dir: C'de diziler 0'dan başladığı için akıştaki `1..N-1` aralığı burada `0..n-2` olur.

### 7.3 while (swapped) ile while (swapped == 1)

**Soru:** Koşulun `swapped == 1` olması gerekmez mi? Akışta öyle çizilmişti.

**Cevap:** `swapped == 1` yazmak da çalışır, akıştaki kontrol de budur. Ama `while (swapped)` da çalışır. Geçen haftaki sunumda konuşulduğu gibi `while`, `if` ve benzeri kontroller aslında aritmetik işlemlerdir ve sonuç üretir: `a == b` ifadesi `a` ile `b` eşitse 1, değilse 0 üretir. Sıfırdan farklı bir değer olduğu sürece döngüde kalınır. `swapped`'in değeri başta 1'dir; içeride 0 yapılır, bir takas olursa yeniden 1 olur ve döngü devam eder, olmazsa döngüden çıkılır. Değişken yalnız 0 ve 1 değerlerini aldığı için dilin bu özelliği kullanılarak `swapped == 1` yerine doğrudan `swapped` yazılabilir.

### 7.4 Dizinin 0'dan başlaması

**Soru:** Eleman okunurken ekrana yazdırılan sıra numarası 0'dan başlıyor; bunun bir artırılması gerekmez mi?

**Cevap:** Gerekmez. C'de dizi indisi zaten 0'dan başlar ve "sıfırıncı eleman" denince karşı tarafın anlayacağı düşünülür. Kullanıcıya numaraların 1'den başlaması isteniyorsa `printf`'te `%d` için parametre olarak verilen `i` yerine `i+1` yazılır. Bu bir zorunluluk ya da yasak değildir.

## 8. Selection Sort

Aradan sonra hoca bubble sort'un sıralama yöntemlerinden yalnız biri olduğunu, başka yöntemlerin de kullanılabileceğini söyledi ve yeni bir dizi yazdı (ekrandan, 01:20:00). Bu kez sayıları 1 ile biten değerlerden seçti:

```text
21  51  11  41  1  71  91
```

Bu diziyi sıralamanın başka bir yolu, her seferinde en küçük elemanı bulup bir yere yazmaktır.

### 8.1 Birinci adım

İlk elemandan başlanır; 21 elimizdeki aday (hoca "pivot" diye andı) olur. 21, 51'den küçük; 11'den küçük değil, yeni aday 11. 11, 41'den küçük; 1'den küçük değil, yeni aday 1. 1, 71'den ve 91'den küçük. Tur tamamlandığında dizinin en küçük elemanının 1 olduğu bilinir.

1 en başa yazılmak istenir, ama en başta 21 vardır ve onun kaybolması istenmez. Bu yüzden 21, 1'in eski yerine yazılır; 51, 11, 41, 71, 91 yerinde kalır:

```text
1 | 51  11  41  21  71  91
```

Artık dizinin ilk gözü sıralıdır ve oraya dokunulmaz.

### 8.2 Sonraki adımlar

Hocanın tahtadaki adımları (ekrandan, 01:20:00; python ile doğrulandı):

```text
Başlangıç :  21  51  11  41   1  71  91
1. adım   :   1 | 51  11  41  21  71  91     (en küçük 1, 21 ile yer değiştirdi)
2. adım   :   1  11 | 51  41  21  71  91     (en küçük 11, 51 ile yer değiştirdi)
3. adım   :   1  11  21 | 41  51  71  91     (en küçük 21, 51 ile yer değiştirdi)
4. adım   :   1  11  21  41 | 51  71  91     (41 zaten en küçük, yerinde kaldı)
5. adım   :   1  11  21  41  51 | 71  91     (51 yerinde kaldı)
6. adım   :   1  11  21  41  51  71 | 91     (71 yerinde kaldı)
```

İkinci adımda 51'den başlanır: 51, 11'den küçük değil, aday 11; 11 geri kalan 41, 21, 71, 91'den küçük. 11 ikinci göze taşınırken 51 de 11'in yerine konur. Üçüncü adımda 51'den başlanır: 41 daha küçük, sonra 21 daha küçük; 21, 71 ve 91'den küçük olduğu için en küçük odur ve 51 ile yer değiştirir. Sonraki adımlarda 41, 51 ve 71 zaten kendi kısımlarının en küçüğüdür, yerlerinde kalırlar. 91 için bir şey yapmaya gerek yoktur.

Bu yönteme selection sort denir: her adımda en küçük eleman bulunur, sıralanmamış kısmın başına konur ve konulan nokta kontrol anlamında izole edilir. Her adımda sıralı kısma yeni bir eleman eklenerek dizinin sonuna kadar sıralanması sağlanır.

### 8.3 Eşit elemanlar fark eder mi?

**Soru:** Dizide aynı değerden iki eleman olursa fark eder mi?

**Cevap:** Hoca soruyu şöyle somutlaştırdı: dizide 11 yerine de 1 olsun, yani iki tane 1 olsun. Sonuçta `1 1 21 41 ...` yazmakla iki 1'in yerini değiştirip yine `1 1 21 41 ...` yazmak arasında bir fark yoktur; hangi 1'in hangisi olduğu da bilinmez. Teknik olarak bakılırsa kontrol "elimizdeki sayı sonrakinden küçük mü" diye yapılır. "1, 1'den küçük mü?" sorusunun cevabı hayırdır. Bu yüzden önce ilk bulunan 1 yerleştirilir, sonra diğeri. Hangisi listede önceyse o önce yerleşir.

> **Ek bilgi (derste anlatılmadı):** Karşılaştırma `<` ile yapıldığı için eşit elemanlardan ilk görülen minimum olarak kalır. Ders kodu iki tane 1 içeren `1 51 11 41 1 71 91` girdisiyle denendiğinde `1 1 11 41 51 71 91` çıktısı verir (ajan tarafından test edildi).

## 9. Selection Sort Akışı

### 9.1 Akışın fikri

Dışarıdan `N` elemanlı `A` dizisi okunur. Her adımda bir elemandan başlanır, sona kadar gidilerek en küçük eleman bulunur ve başa yazılır; sonra bir sonraki adımdan başlanarak devam edilir. Yani dizinin elemanlarını kontrol eden bir döngü ve bunu tekrar tekrar yapan başka bir döngü vardır.

Her turda o gözdeki eleman en küçük eleman (`MIN`) diye alınır. Bu elemanın hangi gözde olduğu bilgisi de önemlidir, çünkü sonunda en küçük eleman ile turun başındaki eleman yer değiştirecektir. Bu yer `PL` değişkeninde tutulur.

İç döngü `J ← I+1`'den başlar. Hoca bunun farklı bir şey olduğunu vurguladı: şimdiye kadar döngüler hep 1'den başlatılıp birer artırılmıştı. Burada ise ilk turda birinci gözden başlanırken ikinci turda ikinci gözden başlanır; önceki gözler artık kullanılmaz. Her seferinde, en küçük olarak belirlenip yerine konan elemanın ötesinden devam edilmelidir.

İç döngüde `A(J) < MIN` sorulur. Doğruysa yeni minimum `A(J)`, onun yeri `J` olur. İç döngü bittiğinde bir tur tamamlanmış demektir; bulunan minimum o anki turun başındaki elemanla yer değiştirir.

### 9.2 TMP olmadan yer değiştirme

Hoca bu adımda "bir çakallık" yaptığını söyledi. Elde `MIN`, onun dizideki yeri `PL` ve değişikliğin yapılacağı `A(I)` vardır. Normal şartlarda iki elemanın yerini değiştirmek için geçici değişken kullanılır: elemanlardan birinin değeri geçici değişkene aktarılır, sonra onun üzerine diğeri yazılır, sonra kenara alınan değer diğer elemanın üzerine yazılır. Burada ise bir avantaj vardır: `PL` indisindeki değerin bir kopyası zaten `MIN`'dedir. Bu yüzden `A(PL)`'nin üzerine doğrudan `A(I)` yazılabilir; değerin kopyası kenarda olduğu için kayıp olmaz. Sonra `MIN`, `A(I)`'nın üzerine yazılır ve iş biter:

```text
A(PL) = A(I)
A(I)  = MIN
```

> **Hocanın vurgusu:** Burası önemli, iyi anlaşılmalıdır. Hoca akışta bu kutunun yanına ünlem koydu ki normal üç adımlı `TMP` takasıyla karıştırılmasın (ekrandan, 01:35:00 ve 01:40:00).

Sonradan bir öğrenci ünlemin bir hatayı mı gösterdiğini sordu. Hoca ünlemin hata değil dikkat işareti olduğunu, iki değişkenin değerini birbiriyle değiştirmek için normalde `TMP` ile üç adım (1. `TMP`'ye kopyala, 2. üzerine yaz, 3. geri kopyala) yapıldığını, burada ise neden `TMP` olmadan yapılabildiğini anlattığını tekrarladı.

### 9.3 Döngü sınırı

Burada da dikkat edilecek bir nokta vardır. Dizinin eleman sayısı `N`'dir. `I` 1'den `N`'ye gidiyor, `J` ise `I+1`'den başlayıp `N`'ye gidiyorsa son turda `I = N` iken `J`'nin ilk değeri `N+1` olur ve iç döngü zaten hiç çalışmaz. Ayrıca örnekte 71 kontrol edildikten sonra 91 için kontrol edilecek bir şey kalmamıştı; o zaten yerindedir. Bu yüzden boşuna bir kez daha dönmeye gerek yoktur ve dış döngünün bitişi `N-1` yapılabilir.

### 9.4 Çizilen akış

Hocanın çizdiği son akış (ekrandan, 01:35:00):

```text
START
  |
[ N, A(N) ]                                  (girdi)
  |
[ I <- 1 || 1 ; bitiş N-1 ] <------------------------------+
  | (bitince)                 | (gövde)                    |
  |                     [ MIN = A(I) ]                     |
  |                     [ PL  = I    ]                     |
  |                           |                            |
  |                     [ J <- I+1 || 1 ; bitiş N ] <---+  |
  |                       | (bitince)    | (gövde)      |  |
  |                       |        < A(J) < MIN >       |  |
  |                       |         F |      | T        |  |
  |                       |           |  [ MIN = A(J) ] |  |
  |                       |           |  [ PL  = J    ] |  |
  |                       |           +------+----------+  |
  |                 [ A(PL) = A(I) ]  (!)                  |
  |                 [ A(I)  = MIN  ]                       |
  |                       +--------------------------------+
  |
[ I <- 1 || 1 ; bitiş N ] <---+
  | (bitince)    | (gövde)    |
STOP          ( A(I) )        |    (çıktı)
                 +------------+
```

## 10. Selection Sort'un C Kodu ve Derleme Hataları

### 10.1 Kodun yazılması

Hoca bu kez akışı gerçek hayata uyarlamak için bir terminal editöründe `selection.c` dosyasını açtı. `#include <stdio.h>`, dizi boyutu için `#define SIZE 100`, `int main(void)`. Gerekenler: döngü değişkenleri `i` ve `j`, minimum değeri saklamak için `min`, minimumun yerini saklamak için `pl` ve dizi. Eleman sayısı ve elemanlar okunduktan sonra dış döngü `i < n-1`'e kadar gider; içinde `min = ar[i]; pl = i;` atanır, iç döngü `j = i+1`'den `n`'ye gider, `ar[j] < min` ise yeni minimum `ar[j]`, yeri `j` olur. İç döngü bittiğinde bir şey yapılmaz; dış döngünün gövdesinde ise yer değiştirme yapılır: dizinin `pl` gözüne `ar[i]`, `i` gözüne `min` atanır.

### 10.2 Derleme hataları

Hoca kodu ilk derlediğinde bilerek bazı hataları bıraktı ve hataları tek tek düzeltti:

- 11. satırda `n` tanımlı değil (undeclared identifier): bütün değişkenler tanımlanmış ama `n` unutulmuştu.
- Örtük fonksiyon bildirimi (implicit function declaration) `scan`: bir öğrencinin de fark ettiği gibi `scan` diye bir fonksiyon yoktur, `scanf` vardır.
- Kodda `ar` yerine `A` yazılmıştı. Hoca bunun asıl nedenini vurguladı: çizilen akış ile yazılan kod birbiriyle tam uyumlu değildi; akışta ve kodda farklı değişken adları kullanılınca bu tür hatalar çok daha kolay ortaya çıkar.

> **Hocanın vurgusu:** Bu ve benzeri hatalar herkesin başına her an gelebilir. Ön yargıyı kenara bırakıp kontrol edin. Hataları her seferinde birer birer düzeltin.

### 10.3 Son kod

Düzeltilmiş kod (ekrandan, 01:50:00). Aşağıdaki kod ekrandakiyle aynıdır, `gcc -Wall` ile derlendi ve `21 51 11 41 1 71 91` girdisiyle `1 11 21 41 51 71 91` çıktısını verdi; derste de aynı çıktı alındı:

```c
#include <stdio.h>

#define SIZE 100

int main(void) {

	int i, j, n, min, pl, ar[SIZE];

	printf("Please enter # of elements : ");
	scanf("%d", &n);

	for(i = 0; i < n; i++)  {
		printf("Please enter elent %d : ", i);
		scanf("%d", &ar[i]);
	}

	for(i = 0; i < n-1; i++) {

		min = ar[i];
		pl = i;

		for(j = i+1; j < n; j++)  {

			if(ar[j] < min )  {
				min = ar[j];
				pl = j;
			}
		}
		ar[pl] = ar[i];
		ar[i] = min;
	}

	for(i = 0; i < n; i++)  {
		printf("%d\t", ar[i]);
	}
	printf("\n");

	return 0;
}
```

## 11. Sıralamada Adım Sayısı Belli mi?

**Soru:** Genel olarak sıralama algoritmalarında adım sayısı belli mi oluyor?

**Cevap:** Hayır. Hoca soruyu sınıfa geri sordu: bubble sort'ta kaç adım gidileceği bilinmez. Selection sort'ta ise bilinir, sonuna kadar gidilir. Elde iki örnek vardır ve birinde adım sayısı belli, diğerinde belli değildir. Bu yüzden iki örnekten bir genelleme yapılamaz.

Hoca konuyu şöyle genişletti: şimdiye kadar konuşulan, buzdağının çok küçük bir kısmıdır. Hangi sıralama algoritmasının kullanılacağı hem içerikle hem veri tipiyle çok ilgilidir. Şimdiye kadar yalnız standart veri tipleri ile tek boyutlu ve iki boyutlu diziler konuşuldu. Veri tipleri bunlarla sınırlı değildir; veri yapıları ve algoritmalar dersinde ağaç yapıları, bağlı listeler gibi yapılar görülecektir. Bu yapıların her biri arama ve sıralama faaliyetlerini değiştirir ve her birine göre algoritmalar vardır. "Yüz tane sıralama algoritması var, en iyisi şu" diye bir durum yoktur; ihtiyaca göre farklı sıralama ve arama algoritmaları seçilir. Bunların bir kısmı yapısı gereği deterministik, bir kısmı deterministik değildir. Bazılarında karmaşıklık doğrudan `N`'ye, yani dizinin boyutuna bağlıdır.

- Bubble sort'ta kaç tur dönüleceği tamamen dizinin düzenine bağlıdır. Dizi şans eseri sıralı gelirse bir tur dönülür ve iş biter. Kötü durum, dizinin karmakarışık olmasıdır; o zaman da tur sayısı yerleşime bağlıdır.
- Selection sort'ta dönüş sayısı bellidir: `n` eleman varsa işlem `n-1` tur boyunca yapılır. Dizi sıralı gelse bile, gerçekten sıralı olup olmadığını anlamak için bütün turlar tek tek yapılmak zorundadır.

> **Hocanın vurgusu:** Özellikle işin başındayken bir genellemenin peşine düşmeyin, zihninizi olasılıklara boşuna kapatmayın.

## 12. İki Sıralı Diziyi Birleştirme

### 12.1 Problem

Yeni problem, iki sıralı diziyi yeni bir sıralı dizide birleştirmektir. Hoca örnek diziler yazdı (ekrandan, 01:55:00 ve 02:00:00):

```text
A :  3  5  7  9  11  23
B :  7  8  10  15  41
```

Bu iki dizinin elemanları yeni bir diziye aktarılacak ve yeni dizi de sıralı olacaktır.

### 12.2 Makul olmayan çözüm

En kötü yol, iki diziyi yeni bir dizide arka arkaya birleştirip sonra bu diziyi sıralamaktır. Hoca bunun makul ve mantıklı bir çözüm olmadığını, işin çok daha basit ve temiz bir yolu olduğunu söyledi.

### 12.3 Temiz çözüm

İki dizinin de ilk elemanları alınır ve karşılaştırılır. Adım adım (ekrandan, 02:00:00):

```text
3 ile 7   -> 3 yazılır, A'da 5'e geçilir
5 ile 7   -> 5 yazılır, A'da 7'ye geçilir
7 ile 7   -> eşit; kontrol "A'nın elemanı B'ninkinden küçük mü" ise
             küçük olmadığı için B'nin 7'si yazılır, B'de 8'e geçilir
7 ile 8   -> 7 yazılır, A'da 9'a geçilir
9 ile 8   -> 8 yazılır, B'de 10'a geçilir
9 ile 10  -> 9 yazılır
11 ile 10 -> 10 yazılır
11 ile 15 -> 11 yazılır
23 ile 15 -> 15 yazılır
23 ile 41 -> 23 yazılır, sonra 41 yazılır ve iş biter

Sonuç: 3  5  7  7  8  9  10  11  15  23  41
```

Eşit elemanlarda hangisinin önce yazıldığı fark etmez; kontrol öbür türlü kurulsaydı öbür 7 önce yazılırdı.

Yapılan iş şudur: her seferinde iki dizinin o anki elemanları karşılaştırılır, daha küçük olan yeni diziye kopyalanır ve yalnız o dizideki kontrol edilecek indis bir artırılır. Hep adım adım artırılan bir yer vardır, ama hangi indisin artacağı karşılaştırmanın sonucuna bağlıdır.

Hoca bu yüzden işin sabit adımlı bir for döngüsüyle (iki indisin birlikte arttığı biçimde) yapılamayacağını söyledi. Dersin sonunda bir öğrencinin karmaşık çözümüne bakarken de bu işin tek bir döngüyle halledilebileceğini, iki for içinde yeni while döngüleri gerekmediğini belirtti: "Biri diğerinden küçükse küçük olanı yeni diziye aktar, sonra küçük elemana sahip dizinin indisini bir artır."

> **Ders sonrası not:** Hocanın "for döngüsüyle mümkün değil" sözü büyük olasılıkla iki dizinin indislerini birlikte artıran bir for döngüsü içindir. Toplam eleman sayısı `n+m` bilindiği için tek bir döngü `k = 0`'dan `n+m`'ye giden bir for olarak da yazılabilir; yeter ki `i` ve `j` gövdede karşılaştırmaya göre artırılsın ve dizilerden biri bitince diğerinden kopyalamaya devam edilsin.

**Soru:** Diziler sıralı verilmezse ne olur?

**Cevap:** Problemin tanımı zaten sıralı iki dizi verildiğidir. Girdiyi sırasız veren kullanıcı problemin tanımına uymamış olur.

## 13. printf ile Hata Ayıklama ve G/Ç Tamponlama

Dersin sonunda bir öğrenci yazdığı birleştirme kodunda `scanf`'in sürekli tekrar ettiğini düşündüğünü söyledi ve ekranını paylaştı. Hocanın bu sorun üzerinden anlattıkları genel bir hata ayıklama dersidir.

### 13.1 Varsayım değil, kanıt

Hoca öğrenciye programın nerede çalıştığını bilmediğini, yalnız bir varsayımda bulunduğunu hatırlattı. Öğrenci `scanf`'in tekrar tekrar çalıştığını sanıyordu; hoca ise programın büyük olasılıkla sonsuz döngüye girdiğini tahmin etti. Bunu havada tartışmak yerine kanıtlamak gerekir.

> **Hocanın vurgusu:** `printf` çok güzel bir hata ayıklama aracıdır (debugging tool). Kodun nereye kadar geldiğini bilmiyorsanız, şüphelendiğiniz yerlerin arkasına çıktı satırları koyun.

Öğrenciden `scanf`'lerin hemen arkasına "after scanf" yazdıran bir `printf` eklemesi istendi. İlk denemede bu yazı da görünmedi. Hoca bunun nedenini buldu: `printf`'in içindeki metnin sonunda `\n` yoktu. `\n` eklenince yazı göründü ve programın `scanf`'leri geçtiği anlaşıldı.

### 13.2 G/Ç tamponlama

Hoca bunun nedenini şöyle açıkladı. G/Ç (giriş/çıkış) işlemleri tamponlanır (buffered), hem de iki seviyede: C çalışma zamanı kütüphaneleri tamponlar, işletim sistemi de tamponlar. Ekrana art arda `printf` ile a, b, c, d yazdırılsa bile bunların karşılığı ekrana hemen gelmeyebilir. G/Ç yavaş bir iş olduğu için onu hızlandırmak ve verimli kılmak adına tampon mekanizması kurulur. Tampon dolunca ekrana yazılır. Çıktının hemen gelmesi için ya metnin sonuna yeni satır (`\n`) konur ya da `printf` (dosyaya yazılıyorsa `fprintf`) çağrıldıktan sonra tamponu boşaltan `fflush` çağrılır; hoca bunu "tamponda ne varsa çek gitsin" diye anlattı. Bunlar yapılmadığı sürece çıktı ekrana verilmeyebilir.

> **Ek bilgi (derste anlatılmadı):** Standart çıktı bir terminale bağlıyken genellikle satır tamponludur, yani `\n` geldiğinde boşaltılır. Bu yüzden hata ayıklama için konan `printf` satırlarının sonuna `\n` koymak, program bir döngüde takılsa bile çıktının görünmesini sağlar. `fflush(stdout);` aynı işi açıkça yapar.

### 13.3 Döngülerin içini izlemek

Sonraki adımda dış ve iç for döngülerinin içine döngü değişkenlerini yazdıran `printf` satırları eklendi. Hoca çıktıların karışmaması için değerlerin başına etiket koymayı önerdi (ör. `printf("i : %d\n", i);` ve `printf("j : %d\n", j);`). Çıktı, dış döngünün belli bir değerinde iç döngünün bir yerde takıldığını gösterdi. Girdi değerleri değiştirildiğinde programın farklı yerlerde takılması, döngülerin içindeki koşulların hatalı olduğunu gösteriyordu. Hoca her `while`'dan sonra ilgili kontrol değişkenlerinin değerlerini yazdırıp adım adım ilerlemeyi önerdi.

### 13.4 Süreci başka terminalden görmek

Program çalışırken hoca öğrenciden ikinci bir terminal açıp `ps -ef` komutunu çalıştırmasını istedi. Listede programın süreci, süreç numarası, onu başlatan terminalin (üst süreç) numarası ve CPU kullanımı görüldü. Hoca sürecin çok yüksek CPU kullandığını, bunun nedeninin bir döngüde takılmış olması olduğunu gösterdi. Program daha sonra Ctrl-C ile sonlandırıldı.

<!-- BELİRSİZ: Altyazıda `ps -ef` komutunun ardından bir filtre (büyük olasılıkla program adıyla arama) söyleniyor, ama tam biçimi anlaşılmıyor. -->

Hoca son olarak öğrencinin yaklaşımının fazla karmaşık olduğunu, bu işin derste örnek üzerinden gösterildiği gibi tek döngüyle çok daha basit çözülebileceğini, problemi yeniden düzenlemesi gerektiğini söyledi.

## Örnek Sorular

### Soru 1: Akıştaki tehlikeli nokta (derste sözlü, 00:33:37)

Bubble sort akışında iç döngü `I ← 1 || 1`, bitiş `N` olarak çizilmiş ve gövdede `A(I) > A(I+1)` sorulmuştur. Bu akışta ne gibi bir sorun vardır?

**Çözüm (derste verildi):** `I = N` olduğunda `A(N+1)` istenir ve dizinin dışına çıkılır. İç döngünün bitişi `N-1` olmalıdır. C bu hatayı yakalamaz; sonuç belleğin durumuna göre değişir.

### Soru 2: Bubble sort izleme (ekrandan, 00:15:00 ve 00:20:00)

`9 3 7 11 66 23 6 41` dizisini bubble sort ile küçükten büyüğe sıralayın; her turun sonundaki diziyi yazın.

**Çözüm (derste verildi, python ile doğrulandı):**

```text
1. tur :  3  7  9  11  23   6  41  66
2. tur :  3  7  9  11   6  23  41  66
3. tur :  3  7  9   6  11  23  41  66
4. tur :  3  7  6   9  11  23  41  66
5. tur :  3  6  7   9  11  23  41  66
6. tur :  değişiklik yok, algoritma durur
```

### Soru 3: Selection sort izleme (ekrandan, 01:20:00)

`21 51 11 41 1 71 91` dizisini selection sort ile sıralayın; her adımın sonundaki diziyi yazın.

**Çözüm (derste verildi, python ile doğrulandı):**

```text
1. adım :  1  51  11  41  21  71  91
2. adım :  1  11  51  41  21  71  91
3. adım :  1  11  21  41  51  71  91
4.-6. adım : değişiklik yok
```

### Soru 4: İki sıralı diziyi birleştirme (ekrandan, 02:00:00; derste sözlü, 01:51:33)

İki sıralı diziyi yeni bir sıralı dizide birleştiren algoritmanın önce akışını çizin, sonra C kodunu (`merge.c`) yazın. Örnek: `3 5 7 9 11 23` ve `7 8 10 15 41`.

Derste çözüm fikri örnek üzerinden anlatıldı (Bölüm 12.3), ama tam akış ve kod verilmedi.

> **Çözüm (derste verilmedi):** Aşağıdaki kod derste anlatılan fikre göre ajan tarafından yazıldı; `gcc -Wall` ile derlendi ve örnek dizilerle `3 5 7 7 8 9 10 11 15 23 41` çıktısını verdi. Önce `n` ve `m`, sonra `A`'nın ve `B`'nin elemanları okunur.

```c
#include <stdio.h>
#define SIZE 100

int main(void) {
    int n, m, i, j, k, a[SIZE], b[SIZE], c[2 * SIZE];
    printf("Please enter n and m : ");
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    for (j = 0; j < m; j++) scanf("%d", &b[j]);
    i = 0; j = 0; k = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            c[k] = a[i];
            i++;
        } else {
            c[k] = b[j];
            j++;
        }
        k++;
    }
    while (i < n) { c[k] = a[i]; i++; k++; }
    while (j < m) { c[k] = b[j]; j++; k++; }
    for (k = 0; k < n + m; k++) printf("%d\t", c[k]);
    printf("\n");
    return 0;
}
```

> Akış diyagramı olarak aynı fikir: `I = 1`, `J = 1`, `K = 1`; `I <= N AND J <= M` oldukça `A(I) < B(J)` sorulur, doğruysa `C(K) = A(I)`, `I = I + 1`, yanlışsa `C(K) = B(J)`, `J = J + 1`; her iki durumda `K = K + 1`. Döngüden sonra hangi dizide eleman kaldıysa kalan elemanlar sırayla `C`'ye kopyalanır.

## Dersin Toparlaması

Bu derste sıralama problemi ele alındı. Bubble sort komşu elemanları karşılaştırıp gerektiğinde yer değiştirerek turlar halinde ilerler ve hiç takas yapılmayan bir turda durur; bu yüzden dış döngüsü kaç kez döneceği bilinmeyen, `swapped` kontrol değişkenine bağlı bir koşullu döngüdür. Selection sort her turda sıralanmamış kısmın en küçük elemanını bulup başa koyar; tur sayısı her zaman `n-1`'dir ve takası minimumun kopyası sayesinde geçici değişken olmadan yapılabilir. İki algoritmanın akışı çizildi ve C'ye aktarıldı. Yol boyunca döngü sınırının indisle yapılan işlemlere göre kontrol edilmesi, sol ve sağ taraftaki değişkenlerin ilk değer gereksinimi, C'de karşılaştırmaların 1/0 üretmesi ve derleyici hatalarının birer birer düzeltilmesi vurgulandı.

Son olarak iki sıralı diziyi yeni bir sıralı dizide birleştirme problemi tanıtıldı: iki indisle ilerlenir, küçük olan eleman kopyalanır ve yalnız onun indisi artırılır. Dersin sonundaki hata ayıklama örneği, `printf`'in en temel hata ayıklama aracı olduğunu ve G/Ç tamponlaması yüzünden çıktı satırlarının sonuna `\n` konması gerektiğini gösterdi. Birleştirme probleminin akışı ve kodu sonraki laboratuvar oturumunda ayrıntılı olarak tartışılacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
