# Ders 26 Genişletilmiş Notu: Dinamik Bellek Ayırma (malloc, calloc, realloc, free), Kumarbaz Problemi ve Doğum Günü Paradoksu, Ortalama ve Medyan Filtresiyle Görüntü İşleme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Stack bölgesi ve sınırları
- 2. İşaretçi ve dizi ilişkisinin tekrarı
- 3. Yasal olmayan erişimler
- 4. Heap ve malloc
- 5. calloc, free ve realloc
- 6. Kumarbaz problemi
- 7. Doğum günü paradoksu
- 8. Görüntüde tuz-biber gürültüsü
- 9. Ortalama filtresi
- 10. Medyan filtresi
- 11. Görüntü küçültme ve büyütme
- 12. Konvolüsyon çekirdekleri: kaydırma, yumuşatma, keskinleştirme
- Örnek Sorular
- Dersin Toparlaması

## 1. Stack bölgesi ve sınırları

Ders, laboratuvarda yapılan ağaç ve bağlı liste örneklerine bir göndermeyle başlıyor. Bu yapılar `struct` gerektirir; `struct` bu dersin kapsamında değildir. Ancak hepsinin arkasındaki ortak soru, değişkenlerin bellekte nerede tutulduğudur. Dönem başından beri söylendiği gibi, normal yerel değişkenler ve diziler belleğin **stack** bölgesinde saklanır. Stack'in belirli bir kapasitesi vardır; bir noktadan sonra istenen kadar yer alınamaz.

Hoca bunu canlı bir denemeyle gösterdi (ekrandan, 00:10:00). Program şuydu:

```c
#include <stdio.h>
#define MAX 984540
int main(){
    int d[MAX];

    printf("Test");
    return 0;
}
```

Küçük bir `MAX` ile program sorunsuz çalışır ve 0 döndürerek kapanır. Çalışan programa **proses** denir; proses bitince işletim sistemi onun belleğini temizler. `MAX` milyonlar mertebesine çıkarılınca derleme yine hatasızdır, ama program çalışırken hata koduyla döner ve `Test` satırı hiç yazılmaz: işletim sistemi programın o satıra gelmesine izin vermez. Değer küçültülerek (yaklaşık 98 bin gibi) çalışan sınır arandı.

Stack'in ikinci sorunu yaşam süresidir. Bir fonksiyon çağrılınca gönderilen argümanlar ve fonksiyonun parametreleri stack'e yerleştirilir; bunun ayrıntısı Assembly dersinde görülür. Fonksiyon bitince yerel değişkenlere (örneğin `f(int a, int c)` içindeki `a` ve `c`) erişim hakkı kalmaz, o alan başkası tarafından kullanılabilir hale gelir.

Burada iki kavram ayrılır:

- **Kapsam (scope):** bir değişkene adıyla hangi aralıkta erişilebildiği. Bir blokta tanımlı değişkene başka bir yerden adıyla erişilemez. Değişken hâlâ yaşıyorsa işaretçi gibi başka bir yolla erişilebilir.
- **Ömür (duration):** değişkenin bellekte yaşadığı süre. Bazen bir yerde tanımlanan bir verinin program kapanana kadar yaşaması istenir.

Bu iki sorunun (az yer, kısa ömür) çözümü belleğin **heap** bölgesidir. Dersin geri kalanında heap'e diziler açısından bakıldı.

## 2. İşaretçi ve dizi ilişkisinin tekrarı

Heap'e geçmeden önce işaretçiler hatırlatıldı (ekrandan, 00:15:00 ve 00:20:00). Bir işaretçi değişkeni bir adresi tutar; o adres üzerinden gösterilen değişkene ulaşılır. Örnek kod:

```c
#include <stdio.h>
#define MAX 100
int main(){
    int d[MAX]={1,2,3,4,5,6,7};
    int *p;
    int i;
    p = d;
    printf("%d - %d\n",d[0],*p);
    p = &d[0];
    printf("%d - %d\n",d[0],*p);
    p = &d[0];
    printf("%d - %d\n\n",d[3],*(p+3));
    for(i=0;i<10;i++){
        printf("%p -- %p\n",&d[i],p+i);
    }
    ...
}
```

Satır satır:

- `int d[MAX]={1,2,3,4,5,6,7};` ilk 7 elemanı verir, kalan bütün elemanlar 0 olur.
- `p = d;` geçerlidir, çünkü dizi adı zaten ilk elemanın adresidir. `p = &d[0];` aynı şeydir. İki `printf` de aynı değeri yazar.
- `*p`, `p`'nin gösterdiği yerdeki değere git demektir (dereferans).
- `*(p+3)`, `d[3]` ile aynı değeri verir. "3 adım ileri git" 3 eklemek değildir: `3 * sizeof(int)`, yani `int` 4 bayt ise 12 bayt ileri gidilir. Köşeli parantez de arka planda bu işaretçi aritmetiğini yapar.
- `%p` ile `&d[i]` ve `p+i` yazdırıldığında iki sütun birebir aynıdır ve adresler 4'er artar (derste ...7C, ...80, ...84 gibi).

### 2.1 Gösterilen değeri artırmak

Bir öğrencinin sorusu üzerine, işaretçinin gösterdiği yerdeki değeri artırmak gösterildi. Dizi yoluyla `d[i]++` yazılır. İşaretçi yoluyla önce `p+i` adresine gidilir, sonra o adresteki değer artırılır:

```c
for(i=0;i<10;i++){
    d[i]++;
    (*(p+i))++;
    printf("%d %d\n",d[i],*(p+i));
}
```

Parantezler önemlidir. Hoca `*` (dereferans) işlecinin buradaki `+` işlecine göre öncelikli olduğunu, bu yüzden `p+i`'nin paranteze alınması gerektiğini söyledi; dıştaki parantez de `++`'nın adrese değil değere uygulanmasını sağlar. Karışık gelirse `*(p+i) = *(p+i) + 1;` yazılabilir.

Çıktıda her eleman iki kez artmıştır: 1 → 3, 2 → 4, ..., 7 → 9; başlangıçta 0 olan elemanlar 2 olur. İki sütun aynıdır.

İkinci bir yol `p`'yi kaydırmaktır: döngüde `(*p)++;` ve ardından `p++;`. Sonuç aynıdır, ama döngü bitince `p` artık dizinin başını değil 10. elemanı gösterir; orijinal değeri kaybolmuştur. Hangisinin uygun olduğu senaryoya bağlıdır.

> **Ek bilgi (derste anlatılmadı):** C'de son ek `++` ve `[]` işleçleri, ön ek `*` işlecinden daha önceliklidir. Bu yüzden `*p++` önce işaretçiyi artırır (eski adresteki değeri okur), `(*p)++` ise değeri artırır.

### 2.2 `d[3]`, `3[d]`, `*(d+3)`

Köşeli parantezin işaretçi aritmetiği olduğunu göstermek için hoca bir "hile" gösterdi (ekrandan, 00:25:00): `d[3]` yerine `3[d]` yazmak da aynı elemanı verir. Çünkü `a[b]`, arka planda `*(a+b)` demektir ve toplama değişme özelliğine sahiptir.

### 2.3 İşaretçi köşeli parantezle kullanılabilir mi?

**Soru:** `p` ve `d` aynı adresi tutuyorsa `p`'yi köşeli parantezle kullanabilir miyiz?
**Cevap:** Hoca hayır dedi: köşeli parantez dizi değişkeni için kullanılır, `p` bir işaretçidir ve onun üzerinde işlemler parantezli işaretçi aritmetiğiyle yapılır. İşaretçilerden oluşan dizi de tanımlanabilir (`int *p[5]`, beş adres tutan bir dizi), ama bu dersin konusu dışında bırakıldı.

> **Ders sonrası not:** Hoca `p`'nin köşeli parantezle kullanılamayacağını söyledi; doğrusu `p[i]` C'de her işaretçi için geçerlidir ve `*(p+i)` ile aynıdır. Hoca birkaç dakika sonra malloc ile alınan alanı gösteren `array` işaretçisi için `array[i]` kullanımını gösterdi; bu, alanın malloc ile alınmasından değil, köşeli parantezin işaretçi aritmetiği olmasından kaynaklanır.

## 3. Yasal olmayan erişimler

### 3.1 Dizinin dışına taşmak

100 elemanlı dizide şu satırlar denendi (ekrandan, 00:25:00):

```c
p = d;
printf("\n %d",d[103]);
printf("\n %d",103[d]);
printf("\n %d",*(p+103));
```

Program sorunsuz bitti ve değerler yazıldı; indis 1003'e çıkarıldığında da çalıştı. Daha uzağa gidildiğinde ise program durduruldu. Hocanın vurgusu şuydu: bu kod başka bir bilgisayarda ya da aynı bilgisayarda başka program çalışırken farklı davranabilir. Size 100 elemanlık yer verilmiştir; 101. elemana ulaşamamanız gerekir, çünkü orası size ait değildir. Hoca bu satırları kodda "illegal printf" olarak işaretledi.

> **Ders sonrası not:** Dizi sınırı dışına erişim C standardına göre tanımsız davranıştır. Derste "çalışmış" görünmesi rastlantıdır; çıktı, çökme ya da başka bir verinin bozulması gibi her sonuç mümkündür.

### 3.2 Boyutu çalışırken okunan dizi

Bir başka sorunlu kullanım (ekrandan, 00:30:00):

```c
printf("Enter N "); scanf("%d",&N);
int dizi2[N];
```

25 ve 200 bin gibi değerlerle program çalıştı, ama hoca bunun garanti olmadığını söyledi ve kodda "illegal array allocation" diye işaretledi: dizi stack'te açılır ve program çalışırken stack'te ne kadar yer olduğu bilinmez. Ayrıca hocaya göre C'de değişken tanımları fonksiyonun başında yapılmalıdır.

> **Hocanın vurgusu:** "Yaptım, çalıştı" olabilir, ama bu her zaman çalışacağı anlamına gelmez. Ödevlerde sık yaşanan durum budur: laboratuvardaki bilgisayarların RAM'i (2 GB) evdeki bilgisayardan (örneğin 16 GB) azdır; evde çalışan kod orada çalışmaz.

> **Ders sonrası not:** `int dizi2[N];` biçimi C99'da değişken uzunluklu dizi (VLA) olarak standarttır, C11'de isteğe bağlıdır; derleyici bu yüzden hata vermez. Asıl sorun hocanın dediği gibi büyük `N` için stack taşmasıdır. Değişkenlerin blok başında tanımlanması kuralı büyük olasılıkla C89'dan kalmadır; C99 sonrası zorunlu değildir.

**Soru:** Dizi tanımlandıktan sonra `N` değişirse ne olur?
**Cevap:** Dizinin boyutu değişmez. Örneğin `N` sonradan `2N` yapılıp dizinin `2N` elemanına erişilmeye çalışılırsa bu, dizinin dışına taşmakla aynı sorundur.

**Soru:** Özyinelemeli (recursive) fonksiyonlar bellekte farklı mı davranır?
**Cevap:** "Özyinelemeli fonksiyon" diye ayrı bir fonksiyon türü yoktur; özyineleme, problemi küçülterek çözen bir algoritma geliştirme tarzıdır. Her çağrı yeni bir fonksiyon çağrısı gibi değişkenlerini yeniden tanımlar ve bellekten yeniden yer ayırır.

## 4. Heap ve malloc

Yasal yol, işletim sisteminin gözetiminde heap bölgesinden yer istemektir. Böylece programın herhangi bir yerinde istenen boyutta dizi oluşturulabilir. Hoca stack ile heap'in doldurulma yönlerinin farklı olduğunu da söyledi: biri yukarıdan aşağı, öbürü aşağıdan yukarı dolar; bu sisteme bağlıdır.

Bu iş için **memory allocation** (bellek tahsisi) fonksiyonu `malloc` kullanılır; `stdlib.h` içindedir. Parametresi `size_t` türünde bir boyut bilgisidir ve bayt cinsindendir. `N` tane `int` için gereken bayt sayısı `N*sizeof(int)`'tir. `sizeof` bir fonksiyon değil, bir **operatördür**; türün o bilgisayardaki boyutunu verir (int 2 bayt ise 2, 4 bayt ise 4).

Ekrandaki kod (ekrandan, 00:30:00 ve 00:35:00):

```c
int *array;
int i, N;
...
printf("Enter N "); scanf("%d",&N);
array = (int*) malloc(N*sizeof(int));
if(array != NULL){
    printf("Memory allocated");
}
for(i=0;i<4;i++){
    //array[i] = i;
    //scanf("%d",&array[i]);
    scanf("%d",(array+i));
}
```

- `malloc` işletim sisteminden bu kadar yer ister; yer verileceğini garanti etmez.
- Yer verilirse ayrılan alanın başlangıç adresi döner. Bu adres `array` işaretçisine atanır; artık `array`, `d` dizisinde olduğu gibi bir dizinin başlangıç adresidir.
- `malloc`'un döndürdüğü tür aslında `void *` (genel, generic işaretçi) türündedir; her türden dizi için kullanılabildiği için `(int*)` ile tür dönüşümü (typecasting) yapılır.
- Alan normal dizi gibi kullanılır: `array[i] = i;`, `scanf("%d",&array[i]);` ve `scanf("%d",(array+i));` üçü de geçerlidir.

### 4.1 NULL kontrolü

İşletim sistemi istenen yeri her zaman vermeyebilir. Örneğin 4 GB RAM'li bir bilgisayarda yalnız sizin programınız çalışmaz; 2 GB istenirse verilmeyebilir. Yer verilmezse `malloc` **NULL** döndürür. Bu yüzden belleğe erişmeden önce `if(array != NULL)` kontrolü yapılır; erişim işlemleri bu `if`'in içine alınır, değilse programdan çıkılır. Açılmamış belleğe erişen program çöker.

Ekranda ilk önce küçük harfle `null` yazılmıştı; hoca C'de bunun büyük harfle `NULL` yazıldığını, bazı başka dillerde küçük yazıldığını söyledi.

Milyon mertebesinde bir `N` ile program "Memory allocated" yazdı, dört değer okundu ve geri yazdırıldı. Okuma ve yazdırmada `array[i]` ile `*(array+i)` birbirinin eşdeğeridir; hoca karışıklığı önlemek için köşeli parantezi tavsiye etti, ama işaretçi aritmetiğiyle yazmanın da bilinmesini istedi.

### 4.2 malloc alanı temizlemez

Yalnız 4 değer okunup 400 eleman yazdırıldı (ekrandan, 00:40:00):

```c
for(i=0;i<400;i++){
    printf("%d -- %d\n",array[i], *(array+i));
}
```

Normal dizide ilklendirme yapınca kalan elemanlar 0 oluyordu. `malloc` ise verilen alanı olduğu gibi, içindeki çöp değerlerle bırakır. Derste elemanların çoğu 0 göründü, ama bazı hücrelerde 0 olmayan değerler çıktı.

## 5. calloc, free ve realloc

### 5.1 calloc

`malloc`'un belleği temizleyerek veren gelişmiş biçimi **clear allocation**, yani `calloc`'tur. İki parametre alır: eleman sayısı ve her elemanın boyutu.

```c
array = (int*) calloc(N, sizeof(int));
```

Çarpma yerine virgül konur; çarpımı fonksiyon kendisi yapar. `calloc` bütün elemanların sıfırlanmasını garanti eder.

### 5.2 free

İşi biten alan sisteme iade edilmelidir:

```c
free(array);
```

İade edilmezse **bellek sızıntısı (memory leak)** olur. `free`'ye her türden işaretçi verilebilir. İade etmek, oradaki değerleri sıfırlamak değildir; o bölge başka bir proses ya da aynı programın başka bir yeri için kullanılabilir hale gelir. Hocanın benzetmesi: okuldaki bir sandalye. Siz oturuyorsanız başkası oturamaz; kalktığınızda (free) başkası oturabilir.

### 5.3 realloc

Alınan alanın boyutu sonradan değiştirilebilir: `N = N/2` ile küçültmek ya da `N = N*2`, `N = N+500` ile büyütmek. Bunun için `realloc` kullanılır. İlk parametre hâlihazırda sahip olunan alanın işaretçisi, ikinci parametre yeni boyuttur; boyut yine bayt cinsindendir, bu yüzden `sizeof(int)` ile çarpılır. Küçültmede alanın bir kısmı serbest bırakılır; geri kalan kullanım aynıdır.

Büyütmede bir sorun vardır. `malloc` ve `calloc` gibi `realloc` da yer bulamazsa `NULL` döndürür. Sonuç doğrudan `array`'e yazılırsa `array` `NULL` olur: yeni yer alınamamıştır ve eski alan hâlâ yaşadığı halde adresi kaybedilmiştir. Bu yüzden geçici bir işaretçi kullanılır (ekrandan, 00:45:00):

```c
N = N*2;
tarray = (int*) realloc(array,N*sizeof(int));
if(tarray != NULL){
    array = tarray;
}
```

Bu yapı iki işe yarar. Birincisi `NULL` durumuna karşı orijinal alan korunur. İkincisi, bağlı listeler anlatılırken söylendiği gibi bellekte bitişik yer her zaman bulunmayabilir. Dizi önceden 1000 adresinden başlıyorsa ve 1000'den sonra `2N` kadar yer yoksa, işletim sistemi örneğin 3000 adresinden başlayan bir yer verebilir. `realloc` bu durumda eski değerleri arka planda yeni yere kopyalar; yer yerinde yetiyorsa alan yerinde kalır. Kontrolden sonra `array` yeni yeri gösterir ve program kaldığı yerden devam eder.

Özet: `malloc` ve `calloc` dinamik olarak yer açar, `realloc` açılan yeri büyütür ya da küçültür, `free` iade eder.

### 5.4 Yapı (struct) dizileri

Laboratuvarda `struct` kullanıldığı için kısa bir örnek verildi: `x` ve `y` alanlı bir `Point` yapısı `typedef struct` ile tanımlanır. `malloc` ile `N` tane `int` yerine `N` tane `Point` tutan dinamik bir dizi aynı şekilde oluşturulabilir; yalnız tür adları (`int` yerine `Point`) değişir. Bu konuya derste daha fazla girilmedi; hoca malloc ve işaretçileri yaz boyunca ayrıntılı çalışmayı tavsiye etti.

### 5.5 Derlenmiş tam örnek

Aşağıdaki program, ekrandaki parçaları tek programda birleştirir. Dizi dışına erişen satırlar (tanımsız davranış) çıkarılmıştır; `calloc` satırı derste anlatılan çağrının denemesidir. `gcc -Wall -Wextra` ile uyarısız derlendi, `N=10` ve girdi `1 2 3 4` ile çalıştırıldı: adres sütunları aynı çıktı, artırma döngüsü `3 3`, `4 4`, ..., `9 9`, `2 2` yazdı, `calloc` sonrası elemanlar 0 çıktı.

```c
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int main(){
    int d[MAX]={1,2,3,4,5,6,7};
    int *p;
    int *array, *tarray;
    int i, N;
    p = d;
    printf("%d - %d\n",d[0],*p);
    printf("%d - %d %d\n\n",d[3],*(p+3),3[d]);
    for(i=0;i<10;i++){
        printf("%p -- %p\n",(void*)&d[i],(void*)(p+i));
    }
    for(i=0;i<10;i++){
        d[i]++;
        (*(p+i))++;
        printf("%d %d\n",d[i],*(p+i));
    }
    printf("Enter N "); scanf("%d",&N);
    array = (int*) malloc(N*sizeof(int));
    if(array == NULL){ printf("Memory not allocated\n"); return 1; }
    for(i=0;i<4 && i<N;i++){
        scanf("%d",(array+i));
    }
    for(i=0;i<4 && i<N;i++){
        printf("%d -- %d\n",array[i], *(array+i));
    }
    N = N*2;
    tarray = (int*) realloc(array,N*sizeof(int));
    if(tarray != NULL){
        array = tarray;
    }
    free(array);
    array = (int*) calloc(N, sizeof(int));
    if(array != NULL){
        printf("calloc: %d %d\n", array[0], array[N-1]);
        free(array);
    }
    printf("Test");
    return 0;
}
```

> **Ders sonrası not:** Hoca `%p` çıktısında adreslerin aşağıdan yukarı artmasını "little endian" diye adlandırdı; doğrusu endianness bir değişkenin baytlarının bellekteki sırasıdır, dizi elemanlarının adreslerinin artmasıyla ilgili değildir. Hoca `float` için "8 bayt veya 4 bayt" dedi; `float` genelde 4, `double` 8 bayttır.

## 6. Kumarbaz problemi

İkinci bölümde ders notundaki olasılıksal algoritmalara dönüldü (ekrandan, 00:50:00). Problem:

> Kumarbaz. Her oyunda $p$ olasılıkla 1 TL kazanıyor, $1-p$ olasılıkla 1 TL kaybediyor. Elinde $N$ TL'si var. Ya $M+N$ TL'yi kazanıp sevinecek ya da 0 TL ile eve dönecek. Kumarbazın sevinme olasılığı?

Örnek: elde 100 lira var, hedef 200 lira. Bir oyun salonunda 1 milyon oyun üzerinden kazanma oranının yaklaşık %47,3 olduğu bulunmuş olsun ($p = 0.473$).

### 6.1 Tek oyunun benzetimi

Ders notundaki sözde kod (MATLAB benzeri sözdizimiyle, ekrandan, 00:50:00):

```text
m=100;
n=100;
h=m+n;
p=0.473;   % 1 oyunda kazanma ihtimali
t=0;
while (n<h) && (n>0)   % oyun sürüyor
    if rand()>(1-p)    % kazandı
        n=n+1;
    else
        n=n-1;
    end
    t=t+1;
    R(t)=n;
end
çizdir(R);
```

- `rand()` 0 ile 1 arasında rastgele sayı üretir. Sayı $1-p$'den büyükse kazanılmıştır; aynı şey "sayı $p$'den küçükse kazandı" biçiminde de yazılabilir.
- Kazanınca `n=n+1`, kaybedince `n=n-1`.
- O anki para `R` dizisinde tutulur, sonunda çizdirilir.
- Oyun, para hedefe ulaşınca ya da bitince sona erer; yani `n<h` ve `n>0` iken sürer.

Ekrandaki grafikte para 100'den başlayıp dalgalanarak yaklaşık 1200 adımda 0'a düşmüştür. Hoca başka senaryolar da çizdi: para 200'e ulaşabilir; hedefe çok yaklaşıp sonra sıfırlanabilir; ya da bir kazanıp bir kaybederek oyun çok uzun sürebilir.

### 6.2 Çok sayıda oyun

Tek deney genel bir yargı vermez. Hoca "bu oyunu 1 milyon kişi oynasa yüzde kaçı hedefe ulaşır" sorusunu sordu.

**Soru:** Kodu bunun için nasıl değiştiririz?
**Cevap (bir öğrenci):** Oyunu kaç kişi oynayacaksa o kadar dönen bir döngüye alırız; her turun sonunda kazanıp kazanmadığını tutar, sonuç çıkarırız.

Ders notundaki kod (ekrandan, 00:55:00):

```text
m=10;
en=100;
h=m+en;
p=0.473;   % 1 oyunda kazanma ihtimali
K=10000;   % denemesayisi
kaz=0;
for i=1:K
    n=en;
    while (n<h) && (n>0)
        if rand()>(1-p)   % kazansin
            n=n+1;
        else
            n=n-1;
        end
    end
    if n==h
        kaz=kaz+1;
    end
end
yazdır(kaz/K)
```

Başlangıç parası `en`'de saklanır, çünkü her oyun yeniden 100 liradan başlar. Hedefe ulaşan sayısı `kaz` ile sayılır; ulaşamayanlar `K - kaz`'dır. Sonuç 0–1 aralığına normalize edilmiş bir orandır.

Ekrandaki sonuçlar:

| $p$ | $n$ (başlangıç) | $m$ (hedeflenen kâr) | Sonuç |
|---|---|---|---|
| 0.473 | 100 | 10 | 0.339 |
| 0.473 | 1000 | 10 | 0.341 |
| 0.473 | 100 | 20 | 0.115 |
| 0.473 | 200 | 20 | 0.114 |
| 0.473 | 1000 | 20 | 0.115 |
| 0.473 | 100 | 100 | 0.000018 |
| 0.473 | 1000000 | 100 | 0.0000201… |

Yorumlar:

- Başlangıç parası 100'den 1000'e çıkınca sonuç neredeyse değişmez.
- Hedeflenen kâr ($m$) arttıkça kazanma olasılığı hızla düşer; ters orantılı bir ilişki vardır.
- Hoca bu olasılığın olasılıkçılar tarafından $p/(1-p)$ ve $m$ ile ifade edilen bir formülle modellendiğini, adının "gambler's" (kumarbaz) ile başlayan bir sonuç olduğunu söyledi ve olasılığın başlangıç parasına bağlı olmadığını vurguladı.
- Sonuç: kumarhanede her zaman kazanan kasadır. Oyuncuların bir kısmı kazanır, ama hedef büyüdükçe kazananların oranı çok azalır.

Derste program bir de canlı çalıştırıldı ($n=100$, $m=20$ ve sonra $m=50$, $p=0.47$, 5 tekrar); $m=50$'de olasılık çok düştü.

> **Ders sonrası not:** Hocanın "p bölü 1-p çarpı m gibi" dediği formül büyük olasılıkla kumarbazın iflası (gambler's ruin) sonucudur. $q = 1-p$ ve $r = q/p$ için kazanma olasılığı $\dfrac{1 - r^{n}}{1 - r^{n+m}}$'dir; $p<0.5$ ve $n$ büyükken bu yaklaşık $\left(\dfrac{p}{1-p}\right)^{m}$ olur (çarpım değil, $m$. kuvvet). Python ile: $(0.473/0.527)^{10} \approx 0.3392$, $(0.473/0.527)^{20} \approx 0.1151$, $(0.473/0.527)^{100} \approx 2.02 \times 10^{-5}$; tablodaki benzetim sonuçlarıyla uyumludur. Başlangıç parasına bağlılık yalnız yaklaşık olarak yoktur.

## 7. Doğum günü paradoksu

Olasılığın güzel bir uygulaması olarak doğum günü paradoksu (birthday paradox) anlatıldı; hoca bunun ayrık matematikte de geleceğini söyledi.

**Soru:** Sınıfta 30–32 kişiyiz. İçimizde doğum günü aynı olan iki kişi olma olasılığı nedir?

Sezgisel cevap düşük bir olasılıktır; hesap bunun yanlış olduğunu gösterir.

### 7.1 Formül

Aynı günde doğma olasılığını doğrudan yazmak zordur. Bunun yerine tümleyeni kullanılır: $P(\text{en az iki kişi aynı}) = 1 - P(\text{herkes farklı günde})$ (ekrandan, 01:00:00 ve 01:10:00).

- Birinci kişi 365 günün herhangi birinde doğabilir: $365/365$.
- İkinci kişi birinciyle farklı olmak için 364 günden birinde doğmalıdır: $364/365$.
- Üçüncü kişi: $363/365$.
- $N$. kişi: $(365-N+1)/365$.

$$P(N) = 1 - \frac{365 \cdot 364 \cdot 363 \cdots (365-N+1)}{365^N} = 1 - \frac{365!}{(365-N)!\; 365^N}$$

Bir öğrenci faktöriyelle yazmayı önerdi; tahtadaki faktöriyelli biçim de buradan çıktı.

> **Ders sonrası not:** Tahtada çarpımın son terimi $(365-N)/365$, faktöriyelli biçimin paydası $(364-N)!\,365^N$ yazıldı (ekrandan, 01:10:00). Doğrusu son terim $(365-N+1)/365$ ve payda $(365-N)!\,365^N$'dir; aksi halde $N+1$ çarpan alınmış olur.

### 7.2 Excel ile hesap

Hoca hesabı Excel'de yaptı (ekrandan, 01:05:00). $N=1$ anlamsız olduğu için $N=2$'den başlandı:

| $N$ | $P(N)$ |
|---|---|
| 2 | 0.00274 |
| 3 | 0.008204 |
| 4 | 0.016356 |
| 14 | 0.223103 |

14 kişi için çarpanlar tek tek yazıldı (365·364·…·352) ve sonuç %22 çıktı; 4'ten 14'e çıkınca ciddi bir sıçrama vardır. $365!$ doğrudan hesaplanmak istendiğinde Excel sayı hatası verdi; bu büyüklükteki faktöriyel için çarpım adım adım yapılmalı ya da kodla hesaplanmalıdır.

Sonra internetteki değerlere bakıldı: 23 kişide olasılık yaklaşık %50, 30 kişide yaklaşık %70, 50 kişide %97, 60 kişide yaklaşık %99. 200 kişide neredeyse kesindir. Model, doğum günlerinin yıl boyunca düzgün (uniform) dağıldığını varsayar; gerçekte bazı bölgelerde bazı aylarda doğum daha sık olabilir.

> **Ders sonrası not:** Ekrandaki Excel tablosunda 0.223103 değeri $N=5$ satırına yazılmıştır; bu değer derste 14 çarpanla hesaplanan $N=14$ içindir. Python ile: $P(5) \approx 0.027136$, $P(14) \approx 0.223103$, $P(23) \approx 0.5073$, $P(30) \approx 0.7063$, $P(32) \approx 0.7533$, $P(50) \approx 0.9704$, $P(60) \approx 0.9941$.

> **Hocanın vurgusu:** Olasılıksal yöntemler bilgi çıkarmada ve tahminde, özellikle bilgisayar bilimlerinde çok işe yarar; olasılık dersi ileride çok lazım olacak.

## 8. Görüntüde tuz-biber gürültüsü

Aradan sonra bir görüntü işleme problemi ele alındı (ekrandan, 01:25:00). Ekranda 512×512, 8 bit gri seviyeli bir test görüntüsü vardı; üzerinde rastgele siyah ve beyaz noktalar görülüyordu. Gri seviyede siyahın kodu 0, beyazın kodu 255'tir. Bu gürültüye **tuz-biber (salt and pepper)** gürültüsü denir: beyazlar tuz, siyahlar biber. Amaç bu gürültüyü gidermektir. Görüntü üzerinde yapılabilecek diğer işlemler küçültme, büyütme (interpolasyon) gibi matris işlemleridir.

Dosya `.pgm` biçimindedir; başlığında satır, sütun sayısı gibi bilgiler, ardından piksel verisi vardır. Okuma ve yazma hazır fonksiyonlarla yapılır, dersin konusu değildir. Ana program (ekrandan, 01:30:00):

```c
int main(){
    int M, N, Q;
    bool type;
    char resimadi[]="lenasp.pgm";
    readImageHeader(resimadi,N,M,Q,type);
    int **resim = resimOku(resimadi);
    int **Yeniresim = resimOku(resimadi);
    meanfilter(resim,Yeniresim,M,N,Q );
    //medianfilter(resim,Yeniresim,M,N,Q );
    //image_shrink(resim,M,N,Q);
    printf("\nProgram Tamamlandi");
}
```

`resim` aslında bir matristir (iki yıldızlı işaretçi olmasına takılmamak gerekir). `M` ve `N` satır ve sütun sayısı, `Q` desteklenen renk sayısıdır (quantization level); yalnız dosyaya yazarken kullanılır. Kod C++ dosyasında yazılmıştır, ama C++'a özgü bir şey kullanılmaz.

**Soru:** Bu siyah ve beyaz noktaları nasıl gideririz?
**Cevap (bir öğrenci):** Her pikselin dört komşusuna (sağ, sol, yukarı, aşağı) bakıp ortalamasını alabiliriz. Hoca sekiz komşuya da bakılabileceğini ekledi.

Hoca önce bu fikrin sınırını sayılarla gösterdi. Üç komşusu 100 olan siyah (0) piksel: $(100+100+100+0)/4 = 75$. Siyahtan uzaklaşır ama tam gri olmaz. Komşuları 100 olan beyaz (255) piksel: $(100+100+100+255)/4 = 138{,}75$. Yani gürültü tamamen temizlenmez, çevreye yayılır ve görüntü biraz bulanıklaşır.

> **Ders sonrası not:** Hoca beyaz piksel örneğinde "555 bölü 4, 125 desek, 130 falan" dedi; doğrusu $555/4 = 138{,}75$'tir.

## 9. Ortalama filtresi

### 9.1 Mantık

Görüntü yatay ve düşey piksel sayısı olan bir matristir. Üzerinde 3×3'lük küçük bir matris (filtre) gezdirilir (ekrandan, 01:40:00 sayfasındaki animasyon). Filtrenin içi 1'lerle doludur. Penceredeki 9 piksel 1 ile çarpılıp toplanır ve 9'a bölünür; bu, 9 değerin ortalamasıdır. Sonuç pencerenin merkezine karşılık gelen piksele yazılır. Sonra pencere bir kaydırılır ve bütün matris gezilir.

- Görüntünün bütün piksellerini gezmek için iki döngü gerekir.
- Filtre penceresini gezmek için iki döngü daha gerekir (3×3, 5×5 ya da daha büyük olabilir).
- Toplam dört iç içe döngü.

Bu işleme **ortalama filtresi (average/mean filter)**, genel olarak **filtreleme** denir. Bir öğrenci bunun birinci dönemde "konvolüsyon" adıyla ödev olarak yapıldığını hatırlattı; hoca işlemin konvolüsyon ya da korelasyon diye geçtiğini söyledi.

Sayısal örnekte (ekrandan anlatılan animasyon) 0'lar ve 90'lardan oluşan bir bölgede: pencerede tek bir 90 varsa $90/9 = 10$, üç 90 varsa $270/9 = 30$, iki 90 varsa $180/9 = 20$ yazılır.

<!-- BELİRSİZ: Sayısal örneğin matrisinin tamamı karelerde görünmüyor; yalnız altyazıdaki 10, 30, 20 sonuçları aktarıldı. -->

### 9.2 Kod

Ekrandaki ikinci sürüm (ekrandan, 01:35:00):

```c
void meanfilter(int **resim,int **Yeniresim, int M, int N, int Q){
    int i,j,m,n;
    int toplam=0;
    int filtre=3;
    char yeni[]="LenaMeanilteredv2.pgm";
    int mf[3][3]={{1,1,1},{1,1,1},{1,1,1}};
    for(i=0;i<N+1-filtre;i++){
        for(j=0;j<M+1-filtre;j++){
            c=0;
            if(resim[j][i]==0 || resim[j][i]==255 ){
                for(m=0;m<filtre;m++){
                    for(n=0;n<filtre;n++){
                        toplam +=resim[j+m][i+n];
                        c++;
                        //toplam +=resim[j][i]*mf[m][n];
                    }
                }
                Yeniresim[j][i]=(float)toplam/c;
            }
            ...
```

<!-- BELİRSİZ: Fonksiyon başlığının ve c değişkeninin tanımı ile if bloğundan sonraki kısım (else ve toplamın sıfırlanması) karede görünmüyor; başlık satırı karede kısmen kapalı. -->

- Sınırlar `i < N+1-filtre` ve `j < M+1-filtre`'dir; filtre görüntünün dışına taşmasın diye son `filtre-1` satır ve sütuna gidilmez.
- İlk sürümde her piksel için "körü körüne" ortalama alınır. Toplam, penceredeki eleman sayısı `c`'ye (burada 9) bölünür ve yeni görüntüye yazılır; sonra toplam sıfırlanır.
- Yorum satırındaki `mf[m][n]` ile çarpma, ağırlıklı filtre için kullanılabilecek biçimdir; burada bütün ağırlıklar 1 olduğu için doğrudan aritmetik ortalama alınır.

Sonuç (birinci sürüm): biraz iyileşme var, ama siyahlar 70'lere, beyazlar 130'lara yaklaştığı için noktalar tam kaybolmadı.

### 9.3 İyileştirme denemeleri

**Soru (hoca):** Merkezin ağırlığı diğerleriyle eşit; merkezin ağırlığını sıfıra indirsek?
**Cevap:** Merkezde siyah ya da beyaz nokta olup olmadığından emin olamayız; aynı noktaya takılırız.

İkinci sürümde yalnız değeri 0 ya da 255 olan piksellerde ortalama alındı (yukarıdaki `if`). Sonuç biraz daha iyi oldu, ama şapkanın beyaz bölgeleri, gözün beyazı ve saçın siyah bölgeleri gibi yerlerde temiz olmayan alanlar kaldı.

Ortalamanın temel sorunu: bütün değerler alınıp toplanınca gürültü de hesaba katılır ("onu da adamdan saymak"). 0 ise 0, 255 ise 255 ortalamaya girer. Bu yüzden ortalama filtresi bu gürültüde pek işe yaramaz.

## 10. Medyan filtresi

### 10.1 Medyan nedir

**Soru:** Bir veri grubunun medyanı nasıl bulunur?
**Cevap (bir öğrenci):** Küçükten büyüğe sıralayıp ortadakine bakılır.

Hoca bir veri grubu yazıp sıraladı, eleman sayısını tek yapmak için bir değer ekledi ve 9 elemanlı sıralı dizinin tam ortadaki elemanının medyan (ortanca) olduğunu gösterdi.

<!-- BELİRSİZ: Derste yazılan veri grubunun tam değerleri altyazıda karışık (3, 4, 8, 6, 1 ile başlayıp eklemelerle 9 elemana çıkıyor); kare yok. -->

Önemli nokta: ortanca alınırken uçtaki veriler hiç hesaba katılmaz. Görüntüde 0 bir uç, 255 öbür uçtur. Bir bölgede 0 ve 255 aykırı değerse (outlier), sıralamada uçlarda kalırlar. Örneğin çoğu siyah olan bir bölgedeki tek beyaz nokta sıralı dizinin sonuna gider; ortanca değer siyahlardan biri olur. Hep beyaz olan bir bölgede (gözün beyazı gibi) ise 255'ler çoğunluktadır; orada ortalama da medyan da sorun çıkarmaz.

### 10.2 Algoritma

- 3×3'lük pencere yine bütün görüntüde gezdirilir.
- Penceredeki 9 değer yedek bir diziye kopyalanır.
- Dizi basit bir sıralama fonksiyonuyla sıralanır.
- Sıralı 9 elemanlı dizide ortadaki eleman (0'dan sayınca 4 numaralı indis) yeni görüntüye yazılır.

Sayısal örnekte: beş 0 ve bir 90 içeren bir pencerenin ortancası 0'dır; hepsi 90 olan bir pencerenin ortancası 90'dır.

Hoca Photoshop'taki tuz-biber gürültüsü giderme işleminin de medyan filtresiyle çalıştığını söyledi. Ortalama hesabı yoktur, ama bir sıralama maliyeti vardır.

### 10.3 Sonuç

Medyan filtresi uygulanmış görüntüde ortalama filtresindeki sorunların hiçbiri görülmedi; yalnız köşelerde ve kenarlarda gürültü kaldı, çünkü filtre oralara dokunmadı.

Pencere 9×9 yapıldığında (81 piksel, ortanca 40 numaralı indis) iki şey oldu:

- Program yavaşladı. Karmaşıklık görüntünün satır sayısı × sütun sayısı × pencere boyutudur (9·9 = 81); medyanda buna sıralama maliyeti eklenir.
- Görüntü fazla bulanıklaştı ("medyan ala ala").

Bu yüzden pencere genelde 3 ya da 5 gibi tek sayı seçilir; bu örnekte 3 bile yeterli oldu.

> **Ek bilgi (derste anlatılmadı):** $k \times k$ pencereli medyan filtresinin basit uygulaması her piksel için $k^2$ elemanı sıralar; toplam maliyet yaklaşık $O(M N k^2 \log k^2)$'dir. Hoca "dördüncü eleman" derken 0'dan başlayan indisi kastediyor; 9 elemanlı sıralı dizide bu 5. sıradaki elemandır.

## 11. Görüntü küçültme ve büyütme

### 11.1 Küçültme (shrink)

$M \times N$'lik bir görüntüyü %50 küçültmek için önce yeni matrise yer açılır; örneğin 300×300'den 150×150 (ekrandan, 01:45:00):

```c
void image_shrink(int **resim, int M, int N, int Q){
    int i,j,m=0,n=0;
    char yeni[]="LenaShrinked2.pgm";
    int **B= (int**)malloc((N/2)*sizeof(int*));
    for(i=0;i<N/2;i++)
        B[i] = (int*)malloc((M/2)*sizeof(int));
    for(i=0;i<N-1;i+=2){
        n=0;
        for(j=0;j<M-1;j+=2){
            B[m][n]=(resim[i][j] + resim[i][j+1] +resim[i+1][j+1] +resim[i+1][j] ...
```

<!-- BELİRSİZ: Ortalama satırının devamı karede ekran dışında kalıyor; büyük olasılıkla dört pikselin toplamı 4'e bölünüyor. -->

İki yöntem anlatıldı:

- **Atlayarak örnekleme:** `i` ve `j` ikişer artar, `B[m][n] = resim[i][j];` alınır (birer atlayarak). Komşular dikkate alınmadığı için sonuç bazen bozulabilir.
- **Komşu ortalaması:** (0,0), (0,1), (1,0), (1,1) gibi 2×2'lik dört pikselin ortalaması alınır. Maliyet biraz artar, sonuç komşulukları hesaba katar.

Derste medyan filtresi uygulanmış görüntü küçültüldü; sonuç iyi göründü. İki yöntem arasındaki farkın görsel olarak değerlendirilmesi gerekir.

### 11.2 Büyütme

$M \times N$'lik görüntü $2M \times 2N$ olur. En basit yol her pikseli iki kez yazmaktır. Derste yazılan deneme (ekrandan, 01:50:00):

```c
int **B= (int**)malloc((2*N)*sizeof(int*));
for(i=0;i<N/2;i++)
    B[i] = (int*)malloc((2*M)*sizeof(int));
for(i=0;i<N-1;i+=1){
    n=0;
    for(j=0;j<M-1;j+=1){
        B[m][n+1] = B[m][n]= resim[i][j];
        n++;
    }
    ...
```

Program önce çöktü, düzeltmeden sonra 1024×1024 bir görüntü üretti ama görüntünün bir kısmı siyahla doldu; hoca kodda küçük bir hata olduğunu söyledi.

> **Ders sonrası not:** Bu taslakta büyük olasılıkla birkaç hata var. Satır işaretçileri dizisi `2*N` elemanlı açılmış ama döngü yalnız `N/2` satıra bellek ayırıyor; kalan satır işaretçileri ilklendirilmemiş olduğundan onlara yazmak tanımsız davranıştır (çökme bundan olabilir). `n` her adımda 1 arttığı için `B[m][n+1]`'e yazılan değer bir sonraki adımda üzerine yazılıyor; doğru büyütmede `n` 2'şer artmalı ve her piksel `B[2i][2j]`, `B[2i][2j+1]`, `B[2i+1][2j]`, `B[2i+1][2j+1]` hücrelerine yazılmalıdır. Satırların yalnız yarısı dolduğu için çıktının bir kısmı siyah kalır.

Hocaya göre bir pikseli doğrudan kopyalamak her zaman yeterli değildir. Küçültürken ortalama alındığı gibi, büyütürken de ara değerler **interpolasyon** ile hesaplanır: $i$, $i+1$, $i+2$ pikselleri arasındaki değişime bakılarak doğrusal, kuadratik ya da kübik interpolasyon kullanılabilir. MATLAB'daki `imresize` ve Python'daki benzer fonksiyonlarda en yakın komşu (nearest neighbor), doğrusal (bilinear) ve kübik (bicubic, üçüncü dereceden çekirdek) seçenekleri vardır. Bu konu görüntü işlemenin konusu olduğu için ayrıntıya girilmedi.

## 12. Konvolüsyon çekirdekleri: kaydırma, yumuşatma, keskinleştirme

Son olarak bir web sayfasındaki örneklere bakıldı (ekrandan, 01:55:00). Çekirdek (kernel) ile yapılan işlemler basit matematiksel işlemlerdir:

- Ortası 1, gerisi 0 olan çekirdek: her şey 0 ile, ortadaki piksel 1 ile çarpılır; görüntü değişmez.
- Tek 1'i merkez dışında bir hücreye koyan çekirdek: görüntüyü bir piksel kaydırır.
- İçi 1 olan ve $1/9$ ile çarpılan 3×3 çekirdek: ortalama alır, yani yumuşatır (smoothing).
- Orijinalden yumuşatılmış görüntü çıkarılınca kenarlar, yani detaylar bulunur:

$$\text{detay} = \begin{bmatrix}0&0&0\\0&1&0\\0&0&0\end{bmatrix} - \frac{1}{9}\begin{bmatrix}1&1&1\\1&1&1\\1&1&1\end{bmatrix}$$

- Detaylar orijinale eklenince kenar bilgileri belirginleşir; buna keskinleştirme (sharpen), genel olarak iyileştirme (enhancement) denir:

$$\text{keskin} = \begin{bmatrix}0&0&0\\0&1&0\\0&0&0\end{bmatrix} + \left(\begin{bmatrix}0&0&0\\0&1&0\\0&0&0\end{bmatrix} - \frac{1}{9}\begin{bmatrix}1&1&1\\1&1&1\\1&1&1\end{bmatrix}\right) = \begin{bmatrix}0&0&0\\0&2&0\\0&0&0\end{bmatrix} - \frac{1}{9}\begin{bmatrix}1&1&1\\1&1&1\\1&1&1\end{bmatrix}$$

Bunlar konvolüsyon işlemleri diye geçer; sinyal işleme ve görüntü işleme derslerinde ayrıntılı görülür.

## Örnek Sorular

**1.** (derste sözlü, 00:06:12) `#define MAX` ile çok büyük bir yerel dizi (`int d[MAX];`) tanımlayan ve sonra `printf("Test")` yazan program derlenip çalıştırılınca ne olur?

> **Çözüm (derste verilen):** Derleme hatasız olur. Dizi stack'te açılır; stack sınırlı olduğu için milyonlar mertebesinde bir `MAX` ile program çalışırken işletim sistemi tarafından durdurulur ve `Test` yazılmaz. Küçük bir `MAX` ile program normal biter.

**2.** (derste sözlü, 00:28:04) Bir dizi `int dizi2[N];` ile tanımlandıktan sonra `N` değişirse ne olur?

> **Çözüm (derste verilen):** Dizinin boyutu değişmez. Yeni `N`'e kadar erişmek, dizinin dışına taşmakla aynı sorundur. Boyutu değişecek diziler `malloc` ile açılıp `realloc` ile yeniden boyutlandırılır.

**3.** (derste sözlü, 00:42:24) `array = realloc(array, ...)` yazmanın sakıncası nedir?

> **Çözüm (derste verilen):** `realloc` yer bulamazsa `NULL` döner; `array` `NULL` olur ve eski alanın adresi kaybolur (alan yaşamaya devam eder ama erişilemez). Doğrusu sonucu geçici `tarray`'e almak, `NULL` değilse `array = tarray;` yapmaktır.

**4.** (ekrandan, 00:50:00) Kumarbaz her oyunda $p$ olasılıkla 1 TL kazanıyor, $1-p$ olasılıkla 1 TL kaybediyor. Elinde $N$ TL'si var. Ya $M+N$ TL'yi kazanıp sevinecek ya da 0 TL ile eve dönecek. Kumarbazın sevinme olasılığı nedir?

> **Çözüm (derste verilen):** Benzetimle: $K=10000$ oyun oynatılır, hedefe ulaşanlar sayılır, oran `kaz/K` yazdırılır. $p=0.473$ için $m=10$'da yaklaşık 0.34, $m=20$'de yaklaşık 0.115, $m=100$'de yaklaşık $2 \times 10^{-5}$ bulundu; sonuç başlangıç parasına neredeyse bağlı değildir. Kapalı formül derste tam yazılmadı; büyük olasılıkla $\dfrac{1 - r^{N}}{1 - r^{N+M}}$, $r = (1-p)/p$, büyük $N$ için yaklaşık $(p/(1-p))^M$ (python ile benzetim sonuçlarıyla karşılaştırıldı).

**5.** (derste sözlü, 00:58:29) 32 kişilik bir sınıfta doğum günü aynı olan en az iki kişi olma olasılığı nedir?

> **Çözüm (derste verilen):** $P = 1 - \dfrac{365 \cdot 364 \cdots (365-N+1)}{365^N}$. Derste 23 kişide yaklaşık %50, 30 kişide yaklaşık %70 olduğu gösterildi. $N=32$ için python ile $P \approx 0.753$ (bu değer derste hesaplanmadı).

**6.** (derste sözlü, 01:23:48) Gri seviyeli bir görüntüdeki siyah (0) ve beyaz (255) gürültü noktalarını algoritmik olarak nasıl gideririz?

> **Çözüm (derste verilen):** Komşulukla: ortalama filtresi gürültüyü çevreye yayar ve tam temizlemez; medyan filtresi pencere değerlerini sıralayıp ortancayı aldığı için 0 ve 255 gibi uç değerleri dışarıda bırakır ve gürültüyü neredeyse tamamen giderir.

**7.** (ekrandan, 01:55:00) Bir göz görüntüsüne $\begin{bmatrix}0&0&0\\0&2&0\\0&0&0\end{bmatrix} - \frac{1}{9}\begin{bmatrix}1&1&1\\1&1&1\\1&1&1\end{bmatrix}$ çekirdeği uygulanırsa sonuç ne olur? (Ekranda "Note that filter sums to 1" notu var.)

> **Çözüm (derste verilmedi):** Çekirdeğin ağırlıkları toplamı $2 - 9 \cdot \frac{1}{9} = 1$'dir; bu yüzden düz bölgelerin parlaklığı korunur. Çekirdek "orijinal + (orijinal − ortalama)" demektir; kenarlardaki farklar iki kat vurgulanır ve sonuç, kenarları ve detayları belirginleşmiş (keskinleştirilmiş) göz görüntüsüdür.

## Dersin Toparlaması

Dersin ilk yarısında stack'in sınırlı ve kısa ömürlü olduğu, dizi dışına taşmanın ve stack'te büyük ya da çalışırken boyutlanan dizi açmanın güvenilmez olduğu gösterildi. Çözüm heap'tir: `malloc` ve `calloc` ile yer istenir, dönen değer `NULL` ile kontrol edilir, `realloc` ile alan geçici işaretçi üzerinden büyütülüp küçültülür ve iş bitince `free` ile iade edilir. İşaretçi aritmetiği (`*(p+i)`, `d[i]`, `i[d]`) bu dinamik dizilerin nasıl kullanıldığının temelidir.

İkinci yarıda dizi ve matris bilgisi uygulamalara taşındı. Kumarbaz ve doğum günü örnekleri olasılıkta sezginin yanılabileceğini ve benzetimin gücünü gösterdi. Görüntü işlemede tuz-biber gürültüsü önce ortalama, sonra medyan filtresiyle giderildi; küçültme, büyütme ve konvolüsyon çekirdekleriyle kaydırma, yumuşatma ve keskinleştirme örneklendi. Hoca sonraki derste matris çarpımı, dış birleştirmeli sıralama (external merge sort), kombinatorik ve NP sınıfıyla ilgili problemler (gezgin satıcı, alt küme problemleri) gibi konulara geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
