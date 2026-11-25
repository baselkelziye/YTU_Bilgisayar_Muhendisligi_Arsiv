# Ders 11 Genişletilmiş Notu: Uygulama 2: LED Tabela Lab Çözümü, Simetrik Binary Matris ve Sıralayıp Tekrar Sayma

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin kodlama standardı (C89/ANSI C)
- 2. Lab çözümü: LED tabela gibi kayan kelime
- 3. Soru 1: Binary matrisi simetrik yapmak için minimum değişiklik
- 4. Soru 2: Diziyi sıralama ve tekrar sayma
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin kodlama standardı (C89/ANSI C)

Bu kayıt bir uygulama (problem çözümü) oturumudur. Oturum başlamadan önce dersin öğretim üyesi, ödev ve lab kodlarının hangi C standardına göre yazılması gerektiğine dair öğrenci sorularını cevapladı.

**Soru:** GCC ile derlerken ANSI parametresini eklemek okulun standardı için yeterli mi? Örneğin `-std=c89`?

**Cevap:** Kodun doğrudan derlenebilmesi gerekir; C89 ile de derlenebilir. Özetle şunlara dikkat edilmelidir:

- `for` ya da `if` gibi bir yapının bloğu içinde değişken tanımlanmaz. Örneğin `for (int i = 0; ...)` yazılmaz; `i` bloğun başında tanımlanır.
- Fonksiyon prototipleri `main`'den önce yazılır.
- `break` yalnız `switch` ile kullanılır. `continue` kullanılmaz; bunlar dersin anlattığı yapısal programlama anlayışıyla bağdaşmaz.

Kodun bu standarda uyup uymadığını görmek için Dev-C++ ya da CodeBlocks gibi bir IDE kurulup orada denenmesi, ya da online GDB gibi çevrimiçi bir derleyicide C seçilerek derlenmesi önerildi.

> **Ek bilgi (derste anlatılmadı):** `gcc -std=c89 -pedantic` ile `for (int k = 0; ...)` derlendiğinde gcc "'for' loop initial declarations are only allowed in C99 or C11 mode" hatası verir (ajan tarafından denendi). Aynı modda `//` ile başlayan tek satırlık yorumlar da kabul edilmez; C89'da yorum yalnız `/* ... */` biçimindedir.

**Soru:** `typedef` ve `struct` artık serbest mi?

**Cevap:** Bu derste `struct` yoktur. Ders diziler, matrisler, fonksiyonlar ve pointer'lar üzerinden algoritma geliştirmeye odaklanır.

Öğretim üyesi ayrıca uygulamada çözülecek örneklerin henüz fonksiyon kullanmadan, `main` içinde yazıldığını belirtti ve öğrencilere bu örnekleri, dizi üzerinde yapılan işlemleri fonksiyonlara ayıracak biçimde yeniden yazmalarını önerdi.

## 2. Lab çözümü: LED tabela gibi kayan kelime

### 2.1 Problem

Önce bir önceki laboratuvarda sorulan sorunun çözümü gösterildi. Soru metni şöyledir (ekrandan, 00:15:00):

> İstanbul sokaklarında yürüyen bir bilgisayar mühendisi öğrencisi Ali, mağazaların üzerinde bulunan LED tabelalar dikkatini çeker. Bu tabelalarda yazılan kelimenin elemanlarının her bir adımda sola kayıp belirli bir adım sonra kelimenin tekrar eski haline geldiğini fark eder. Ali bu örneği C programlamada programlamak ister.

Olması gereken kısımlar:

1. Kelime kullanıcıdan alınıp bir diziye aktarılmalı, işlemler bu dizi üzerinden yapılmalı.
2. LED tabelada olduğu gibi harfler her bir adımda en sona gelecek şekilde düzenlendiğinde her bir adım ekrana yazılmalı.
3. Programda `for` döngüsü kullanılmamalı, döngü işlemleri `do-while` ile yapılmalı.
4. Program bittiğinde kullanıcı `'E'` ya da `'e'`'ye basarsa program tekrar başlamalı.
5. Hiçbir durum için hazır fonksiyon kullanılmamalı.

Örnek kelime olarak "Muhendislik" verilmiştir (ekrandan, 00:15:00).

### 2.2 Değişkenler ve do-while

Çözümde bir karakter dizisi (`arr`), döngüler için `n`, `i`, `j` ve iki karakter değişkeni tanımlanır: `temp`, yeri değiştirilecek karakteri geçici olarak tutar; `devam`, kullanıcının `E`/`e` cevabını tutar.

**Soru:** `do-while` ne işe yarar?

**Cevap:** İşlem önce bir kez gerçekleştirilir, ardından koşul sağlanıyorsa tekrar gerçekleştirilmeye devam edilir.

Bu yüzden en dıştaki `do-while` "kelime iste, işle, sonra devam etmek isteyip istemediğini sor" kalıbına uyar: önce "Lütfen bir kelime girin" yazdırılır ve kelime alınır; döngünün koşulu `devam == 'E' || devam == 'e'`'dir.

**Soru:** Kelime okunurken neden `%s` kullanılıyor?

**Cevap:** Değer string (kelime) olarak alındığı için. Okunan kelime `arr` dizisine atanır.

### 2.3 strlen kullanmadan uzunluk bulma

Hazır fonksiyon yasak olduğu için kelimenin uzunluğu elle bulunur. `n` sıfırdan başlatılır; ikinci bir `do-while` içinde `n` her seferinde bir artırılır ve `arr[n]` sonlandırıcı boş karakter `'\0'` değilse döngü sürer. Döngü bittiğinde `n` kelimenin uzunluğudur; bu, `strlen` fonksiyonunun yaptığı iştir.

<!-- BELİRSİZ: Uzunluk döngüsünün tam yazımı karede görünmüyor; altyazıdaki anlatıma göre yazıldı. -->

```c
n = 0;
do {
    n++;
} while (arr[n] != '\0');
```

### 2.4 Bir adımda kelimeyi sola döndürme

Ekranda görünen ana döngü şöyledir (ekrandan, 00:20:00):

```c
i = 0;
do {
    printf("Adim %d: ", i+1);
    temp = arr[0];
    j = 0;
    do {
        arr[j] = arr[j+1];
        j++;
    } while (j < n-1);
    arr[n-1] = temp;

    j = 0;
    do {
        printf("%c ", arr[j]);
        j++;
    } while (j < n);
    printf("\n");

    i++;
} while (i < n);

printf("\nTekrar denemek icin E ya da e?");
scanf(" %c", &devam); // neden %c oncesi bosluk var acikla
}while(devam == 'E' || devam == 'e');
return 0;
}
```

Adım adım:

- `i` sıfırlanır; her turda `printf` ile kaçıncı adımda olunduğu `i+1` olarak yazılır (ilk turda "Adim 1").
- Dizinin 0. (ilk) elemanı `temp`'e atanır, çünkü bu eleman sona taşınacaktır.
- İç `do-while`'da `arr[j] = arr[j+1]` ile her elemana bir sonraki eleman atanır; böylece dizi bir sola kaymış olur. Koşul `j < n-1`'dir, yani son elemana kadar gidilir ve dizinin sınırı aşılmaz.
- Sonra `arr[n-1] = temp` ile saklanan ilk harf son konuma yazılır.
- `j` yeniden sıfırlanır ve üçüncü `do-while` dizinin karakterlerini `%c` ile tek tek yazar.

**Soru:** `%c` neyi ifade eder?

**Cevap:** Tek bir karakteri.

Dış döngünün koşulu `i < n`'dir: $n$ harfli bir kelime $n$ adımda tam bir tur döner ve son adımda kelimenin orijinali yeniden yazılır.

> **Ek bilgi (derste anlatılmadı):** Koddaki `scanf(" %c", &devam)` satırının yanında "neden %c öncesi boşluk var, açıkla" yorumu vardır (ekrandan, 00:20:00). Önceki `scanf("%s", ...)` çağrısından sonra basılan Enter karakteri giriş tamponunda kalır. `%c`'nin önündeki boşluk bu beyaz boşluk karakterlerini atlar; boşluk olmasaydı `devam` değişkenine Enter karakteri okunur ve kullanıcı cevap veremeden döngü biterdi.

### 2.5 Çalıştırma

Program "bilgisayar" kelimesiyle çalıştırıldı: birinci adımda `b`, ikinci adımda `i` sona alındı ve böyle devam ederek son adımda kelimenin orijinali yazıldı. Ardından program devam edilip edilmeyeceğini sordu; `E` girilince yeniden kelime istedi, başka bir tuşla çıkıldı.

> **Ders sonrası not:** Anlatımda üçüncü adımda "G"nin sona alındığı söylendi; "bilgisayar" için üçüncü adımda sona giden harf `l`'dir (`ilgisayarb` → `lgisayarbi` → `gisayarbil`). `g` dördüncü adımda sona gider. Kodun tamamlanmış bir sürümü ajan tarafından gcc ile derlenip "bilgisayar" girdisiyle çalıştırıldı; 10. adımda kelime ilk haline döndü.

## 3. Soru 1: Binary matrisi simetrik yapmak için minimum değişiklik

### 3.1 Problem ve fikir

Soru: $N \times N$ boyutlu binary bir matrisin ana (ilk) köşegenine göre simetrik olabilmesi için matris üzerinde yapılması gereken minimum değişiklik sayısını bulan C programını yazınız (ekrandan, 00:25:00). Simetri, her $i, j$ için $A[i][j] = A[j][i]$ olması demektir.

Çözüm gösterilmeden önce öğrencilerden fikir istendi. Bir öğrenci şunu önerdi: matrisin elemanları simetrik konumdakilerle karşılaştırılır; $A[i][j]$, $A[j][i]$ ile aynı değilse gereken minimum işlem sayısı bir artırılır. Bu öneri doğru kabul edildi.

### 3.2 Kod

Ekranda görünen kod (ekrandan, 00:25:00):

```c
//NXN boyutlu binary matrisin ilk kosegenine gore simetrik olmasi icin gereken minimum degisiklik sayisi
int main()
{
int A[N][N], T[N][N], n;
int i, j;
int flip;
do{
    printf("\nEnter the size of matrix\t");
    scanf("%d",&n);
}while(n > N);
printf("\nEnter the elements:\n");
for(i=0; i<n; i++){
    for(j=0; j<n; j++){
            printf("element[%d][%d]:",i,j);
            scanf("%d",&A[i][j]);
    }
}
//Print Matrix
for(i=0; i<n; i++){
    for(j=0; j<n; j++)
        printf("%3d",A[i][j]);
        printf("\n");
}
flip = 0;
for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
        if (A[i][j] != A[j][i])
```

<!-- BELİRSİZ: 30. satırdan sonrası karede görünmüyor. Altyazıya göre koşul sağlanınca flip bir artırılıyor ve sonuç flip/2 olarak yazdırılıyor. N'nin değeri altyazıya göre 10. -->

Kodun parçaları:

- İki matris tanımlanmıştır (`A` ve `T`), ama `T` kullanılmaz; `A` yeterlidir. `flip`, kaç değişiklik gerektiğini sayar.
- Boyut `do-while` içinde istenir. Kullanıcının izin verilen en büyük boyuttan (10) fazlasını girmesi engellenir; fazla girilirse boyut yeniden sorulur.
- Matris iki boyutlu olduğu için elemanlar `i` ve `j` ile iç içe iki döngüde okunur: önce `element[0][0]`, sonra `element[0][1]`, `element[0][2]` ... `n` kaçsa o kadar.
- Matris yine iç içe iki döngüyle yazdırılır.

**Soru:** `%3d` ne işe yarar?

**Cevap:** Sayıyı 3 karakter genişliğinde yazar; sayılar küçükken kenarda boşluk bırakılır ve matris daha düzgün, hizalı görünür.

### 3.3 Neden flip/2?

Bütün matris iç içe iki `for` ile gezilir; `A[i][j] != A[j][i]` olduğunda değişiklik gerekir ve `flip` bir artırılır.

**Soru:** Yazdırırken neden `flip`'in yarısı yazdırılıyor?

**Cevap:** Örneğin (4,5) elemanı (5,4) elemanıyla, ardından (5,4) elemanı da (4,5) elemanıyla karşılaştırılır. Matrisin tamamı gezildiği için aynı çift iki kez karşılaştırılmış ve `flip` iki kez artırılmış olur; (2,3)–(3,2) gibi bütün çiftler için aynısı geçerlidir. Bu yüzden minimum değişiklik sayısı `flip/2`'dir.

**Soru:** Kod köşegendeki elemanları da sayıyor mu? Örneğin (1,1) elemanı (1,1) ile karşılaştırılıyor.

**Cevap:** Önce köşegenin fazladan sayıldığı ve düzeltme gerekebileceği düşünüldü; ancak soruyu soran öğrenci kendisi de fark etti ki sayaç yalnız elemanlar eşit **olmadığında** artar. Köşegen elemanı kendisiyle karşılaştırıldığında her zaman eşit olduğu için sayaca hiçbir şey eklemez; `flip/2` doğrudur.

### 3.4 Çalıştırma

Program önce izin verilenden büyük bir boyutla (15) çalıştırıldı ve boyut yeniden soruldu; sonra 3 girildi (ekrandan, 00:30:00). Binary matris olduğu için elemanlar 0 ya da 1 olarak girildi. Matris yazdırıldığında köşegen 0, 1, 0 idi ve program 3 değişiklik gerektiğini buldu: köşegen dışındaki üç simetrik çiftin üçü de birbirinden farklıydı; her birinde iki elemandan birini değiştirmek simetriyi sağlar.

<!-- BELİRSİZ: Girilen 3×3 matrisin tamamı karede görünmüyor; yalnız element[0][0]=0 ve element[0][1]=1 okunuyor (ekrandan, 00:30:00). -->

### 3.5 Daha iyi çözüm: yalnız üst üçgen

Oturumun sonunda bir öğrenci sohbetten şunu sordu: matrisi tamamen gezmek yerine yalnız köşegenin üst kısmını gezmek daha iyi olmaz mıydı? Cevap: evet, karşılaştırma her durumda alt kısımdaki simetrik elemanla yapıldığı için bu daha iyi bir çözümdür. Kodunun öğrenciler tarafından yazılması istendi (bkz. Örnek Sorular).

## 4. Soru 2: Diziyi sıralama ve tekrar sayma

### 4.1 Problem

Soru: Elemanları kullanıcıdan alınan $n$ boyutlu bir diziyi Bubble Sort ile sıralayan ve dizide her bir elemanın kaç defa tekrar ettiğini ekrana yazdıran C programını yazınız.

Bubble Sort'un ne olduğu sorulduğunda, en temel sıralama algoritması olduğu, adım adım ilerlediği ve oldukça yorucu (maliyetli) bir algoritma olduğu söylendi.

### 4.2 Değişkenler ve giriş

Döngüler için `i` ve `j`, dizinin boyutu için `n` tanımlanır. Dizinin en büyük boyutu `#define` ile 100 olarak tanımlanmıştır; takas için `temp` kullanılır. Kullanıcıdan önce `printf`/`scanf("%d", &n)` ile boyut, sonra `i = 0`'dan `n`'e kadar her eleman alınır ve dizi girildiği sırayla, her eleman ayrı satırda yazdırılır.

### 4.3 Sıralama

Ekrandaki kod (ekrandan, 00:35:00):

```c
for (i=0; i<n; i++){
    printf("%d \n", dizi[i]);
}

// Diziyi sirala (Bubble sort)
for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
        if (dizi[i] > dizi[j]) {
            temp = dizi[i];
            dizi[i] = dizi[j];
            dizi[j] = temp;
        }
    }
}

printf("Dizinin sirali hali:");
for (i=0; i<n; i++){
printf("%d  ", dizi[i]);
printf("\n");
}

// dizideki elemanlarin kac defa tekrar ettigini yazdiriyor.
for( i = 0; i < n; i++) {
  int sayac = 0;
```

**Soru:** İç döngü neden `j = i + 1`'den başlıyor?

**Cevap:** Eleman kendisiyle karşılaştırılmasın diye; her eleman kendisinden sonraki elemanlarla karşılaştırılır.

Eğer `dizi[i]`, `dizi[j]`'den büyükse üç adımlı bir takas (swap) yapılır: `temp = dizi[i]`, `dizi[i] = dizi[j]`, `dizi[j] = temp`. Elemanlar ikili ikili karşılaştırılıp gerektiğinde yer değiştirdiği için dizi küçükten büyüğe sıralanır.

> **Ders sonrası not:** Derste bu kod "Bubble Sort" olarak anıldı. Ekrandaki kod komşu elemanları (`dizi[j]` ile `dizi[j+1]`) değil, `dizi[i]`'yi kendisinden sonraki her elemanla karşılaştırır. Bu biçim büyük olasılıkla "exchange sort" (seçmeli sıralamanın takaslı biçimi) olarak bilinir. Klasik kabarcık sıralamasında her geçişte komşu çiftler karşılaştırılır ve en büyük eleman sona "kabarcık gibi" yükselir. İki yöntem de $O(n^2)$ karşılaştırma yapar ve diziyi doğru sıralar.

### 4.4 Tekrar sayımı

Her `i` için `sayac` sıfırlanır. İç döngü `j = 0`'dan `j < i` olduğu sürece döner ve `dizi[i] == dizi[j]` ise sayaç artırılır; yani aynı eleman daha önce görüldüyse sayaç sıfırdan büyük olur.

**Soru:** Bu döngüden çıkıldığında sayaç sıfıra eşitse bu ne anlama gelir?

**Cevap:** Bu değer daha önce işlenmemiştir. O zaman değer dizide bir kez daha, bu sefer `j = i + 1`'den başlanarak aranır ve sonunda `printf` ile "dizinin i. elemanı sayaç kadar tekrar ediyor" yazdırılır. Daha önce işlenmiş değerler atlandığı için her değer bir kez yazılır.

<!-- BELİRSİZ: Tekrar sayım döngüsünün 48. satırdan sonrası karede görünmüyor; ekran çıktısına göre ilk görülen değerin sayacı 1'den başlayacak biçimde sayılıyor. -->

### 4.5 Çalıştırma

Önce boyut 5 ve elemanlar 15, 20, 10, 6, 58 girildi; dizi önce bu sırayla, sonra sıralı hali (6, 10, 15, 20, 58) yazdırıldı. Tekrar eden eleman olmadığı için ikinci bir örnek denendi (ekrandan, 00:40:00):

```text
Dizi boyutunu girin: 6
1. sayiyi giriniz:12
2. sayiyi giriniz:20
3. sayiyi giriniz:12
4. sayiyi giriniz:15
5. sayiyi giriniz:3
6. sayiyi giriniz:3
12
20
12
15
3
3
Dizinin sirali hali:3
3
12
12
15
20
3 sayisi 2 defa tekrar ediyor.
12 sayisi 2 defa tekrar ediyor.
15 sayisi 1 defa tekrar ediyor.
20 sayisi 1 defa tekrar ediyor.
```

Kodun eksik kısmı tamamlanarak ajan tarafından gcc ile derlenip aynı girdiyle çalıştırıldı; çıktı ekrandakiyle aynıdır. Tamamlanan sürüm (son döngü derste ekranda tam görünmedi):

```c
#include <stdio.h>
#define MAX 100
int main()
{
    int i, j, n;
    int dizi[MAX], temp;
    printf("Dizi boyutunu girin: ");
    scanf("%d", &n);
    for (i=0; i<n; i++){
        printf("%d. sayiyi giriniz:", i+1);
        scanf("%d", &dizi[i]);
    }
    for (i=0; i<n; i++){
        printf("%d \n", dizi[i]);
    }
    /* Diziyi sirala */
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (dizi[i] > dizi[j]) {
                temp = dizi[i];
                dizi[i] = dizi[j];
                dizi[j] = temp;
            }
        }
    }
    printf("Dizinin sirali hali:");
    for (i=0; i<n; i++){
        printf("%d  ", dizi[i]);
        printf("\n");
    }
    /* dizideki elemanlarin kac defa tekrar ettigini yazdiriyor */
    for (i = 0; i < n; i++) {
        int sayac = 0;
        for (j = 0; j < i; j++)
            if (dizi[i] == dizi[j])
                sayac++;
        if (sayac == 0) {          /* bu deger ilk kez goruluyor */
            sayac = 1;
            for (j = i + 1; j < n; j++)
                if (dizi[i] == dizi[j])
                    sayac++;
            printf("%d sayisi %d defa tekrar ediyor.\n", dizi[i], sayac);
        }
    }
    return 0;
}
```

Oturumun sonunda anlaşılmayan bir yer olup olmadığı soruldu; tekrar edilmesi istenen bir konu çıkmadı.

## Örnek Sorular

**Soru 1** (ekrandan, 00:15:00): Kullanıcıdan bir kelime alıp bir diziye aktaran, LED tabelada olduğu gibi her adımda ilk harfi en sona taşıyarak her adımı ekrana yazan programı yazınız. `for` yerine `do-while` kullanılacak, hazır fonksiyon kullanılmayacak; kullanıcı `E` ya da `e` girerse program yeniden başlayacak. Örnek kelime: "Muhendislik".

> **Çözüm:** Derste gösterildi (Bölüm 2). Uzunluk `'\0'`'a kadar sayılarak bulunur; her adımda `temp = arr[0]`, `arr[j] = arr[j+1]` (`j < n-1`), `arr[n-1] = temp`. "Muhendislik" 11 harflidir; 11. adımda kelime ilk haline döner.

**Soru 2** (ekrandan, 00:25:00): $N \times N$ binary bir matrisin ana köşegenine göre simetrik olması için gereken minimum değişiklik sayısını bulan programı yazınız.

> **Çözüm:** Derste gösterildi (Bölüm 3): tam gezmede `A[i][j] != A[j][i]` sayılır ve sonuç `flip/2`'dir.

**Soru 3** (derste sözlü, 00:40:39): Soru 2'de matrisi tamamen gezmek yerine yalnız köşegenin üst kısmını gezen çözümü yazınız.

> **Çözüm (derste verilmedi):** Yalnız $j > i$ olan konumlar gezilir; her simetrik çift bir kez karşılaştırıldığı için sayaç doğrudan sonuçtur ve ikiye bölme gerekmez. Karşılaştırma sayısı $n^2$'den $n(n-1)/2$'ye iner. Aşağıdaki kod ajan tarafından `gcc -Wall -std=c89 -pedantic` ile derlendi; köşegeni 0, 1, 0 olan ve üç simetrik çiftin üçü de uyumsuz olan bir 3×3 girdide 3 sonucunu verdi.

```c
#include <stdio.h>
#define N 10
int main()
{
    int A[N][N], n, i, j, flip = 0;
    do {
        printf("Boyut: ");
        scanf("%d", &n);
    } while (n > N || n < 1);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &A[i][j]);
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)   /* yalniz kosegenin ustu */
            if (A[i][j] != A[j][i])
                flip++;
    printf("Minimum degisiklik sayisi: %d\n", flip);
    return 0;
}
```

**Soru 4** (ekrandan, 00:40:00): Elemanları kullanıcıdan alınan $n$ boyutlu bir diziyi sıralayan ve her elemanın kaç kez tekrar ettiğini yazdıran programı yazınız. Girdi: 12, 20, 12, 15, 3, 3.

> **Çözüm:** Derste gösterildi (Bölüm 4). Sıralı dizi: 3, 3, 12, 12, 15, 20. Çıktı: 3 ve 12 ikişer kez, 15 ve 20 birer kez tekrar eder.

## Dersin Toparlaması

Bu uygulama oturumunda önce dersin kodlama standardı netleştirildi: kodlar C89'a uygun olmalı, değişkenler blok başında tanımlanmalı, prototipler `main`'den önce gelmeli, `break` yalnız `switch`'te kullanılmalıdır. Ardından üç problem çözüldü. LED tabela probleminde hazır fonksiyon kullanmadan string uzunluğu bulma, bir diziyi sola döndürme ve iç içe `do-while` döngüleri çalışıldı. Simetrik matris probleminde iki boyutlu dizi okuma/yazma, simetrik çift karşılaştırma ve tam gezmede her çiftin iki kez sayılması (`flip/2`) görüldü; yalnız üst üçgeni gezen daha verimli çözüm önerildi. Son problemde iç içe döngülerle takaslı bir $O(n^2)$ sıralama ve daha önce görülmüş değerleri atlayarak tekrar sayma uygulandı.

Öğrencilere bu `main` içinde yazılmış çözümleri, dizi işlemlerini ayrı fonksiyonlara taşıyarak yeniden yazmaları önerildi; böylece bir sonraki aşamada işlenecek fonksiyon konusu bu örnekler üzerinde pekiştirilebilir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
