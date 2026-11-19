# Ders 12 Çalışma Özeti

## Genel Konular

- Fonksiyonlara parametre aktarımı: değerle ve referansla çağırma
  - C'de aksi belirtilmedikçe argümanlar değerleriyle aktarılır (call by value / pass by value). Fonksiyon parametrenin bir kopyasıyla çalışır; içeride yapılan değişiklik yalnız o fonksiyonun ömrü boyunca geçerlidir, çağıran fonksiyona dönüldüğünde değişkenin eski değeri durur.
  - Değişikliğin çağıran fonksiyonda da kalıcı olması isteniyorsa değişkenin adresi işaretçi ile aktarılır (call by reference / pass by reference). `scanf`'e değişken adı yerine adres (`&x`) verilmesinin nedeni budur.
  - Hoca, Java'da bunlara ek olarak "referansın değerle aktarılması" diye üçüncü bir biçimin bulunduğunu, onun ileride başka bir derste görüleceğini söyledi.
  - `increaseRegular` / `increasePointer` örneği (ekrandan, 00:10:00): `a = 3, b = 5` ile `increaseRegular(a, b)` içeride 8 yazar ama main'de `a` hâlâ 3'tür; `increasePointer(&a, b)` içinde `*aa += bb;` yapılınca main'de de `a` 8 olur.
- Fonksiyon bildirimi, tanımı ve çağrısı (ekrandan, 00:15:00)
  - Tanım (definition): fonksiyonun ne yaptığını, argümanlarının sayısını ve türünü belirler. Fonksiyon kullanılmadan önce ya gövdesiyle tanımlanmış ya da imzası (`;` ile biten anma, allusion) verilmiş olmalıdır; gövde sonra aşağıda yazılabilir.
  - Çağrı (function call): denetim akışı çağrılan fonksiyonun kodunun saklandığı adrese atlar; fonksiyon bitince çağrının hemen sonrasından devam edilir. Fonksiyonun yerel değişkenleri yalnız fonksiyon çalışırken vardır.
  - En basit fonksiyon parametre almaz ve değer döndürmez; böyle işler için makro da kullanılabilir. Faktöriyel gibi bir fonksiyon hem parametre alır hem değer döndürür.
  - Faktöriyel çok hızlı büyür; `int` yaklaşık 2 milyara kadar değer tutabildiği için belli bir girdiden sonra hesaplanamayacağı denetlenmeli ya da daha geniş tür kullanılmalıdır. Hoca, `long` da yetmezse bir sayının iki `long` ile (biri en anlamlı, biri en az anlamlı kısım) tutulabileceğini söyledi.
- Örnek 2 ve Örnek 3 (ekrandan, 02:10:00 ve 00:20:00)
  - Örnek 2: bir `char` değişkenin alfabetik olup olmadığını (`a-z`, `A-Z`) denetleyen, alfabetikse 1, değilse 0 döndüren fonksiyon; evde yapılmak üzere bırakıldı.
  - Örnek 3: iki tam sayının değerlerini değiştiren (swap) fonksiyon. Geçici değişken gerekir: `tmp = a; a = b; b = tmp;`. Derste `swapRegular` (değerle) ve `swapPointer` (işaretçiyle) yazıldı; yalnız işaretçili sürümde değişiklik main'e yansıdı.
- Dizileri fonksiyona parametre olarak aktarma (ekrandan, 00:25:00)
  - C'de dizi sınırı denetimi yoktur; dizinin eleman sayısından fazla elemanla çalışılmamasına dikkat edilmelidir.
  - Gerçek boyutla aktarma: `void printArray( int ar[5] )`. Kullanışsızdır; her boyut için ayrı fonksiyon gerekir.
  - Boyutsuz dizi ve boyut parametresi: `void printArray( int ar[], int size )`. Daha kullanışlıdır.
  - İşaretçi ve tam sayı: `void myFunction( int *ar, int size )`. Bu da kullanışlıdır.
  - Boyut ayrı parametre olarak verilmezse dizinin sonu bir işaretçi değerle belirtilebilir: doğal sayılarla çalışan bir işte negatif sayı, karakter katarında `'\0'` gibi.
- Dizi boyutunu bulan makro (ekrandan, 00:30:00)
  - `#define SIZE_OF_ARRAY(x) (sizeof(x) / sizeof((x)[0]))`
  - Bu makro diziyi tanımlayan fonksiyonda (main'de) doğru sonuç verir, ama parametre olarak gelen dizide çalışmaz: fonksiyona aktarılan dizi işaretçi gibi ele alınır, `sizeof` işaretçinin boyutunu döndürür. Bu yüzden boyutu ayrı parametre olarak aktarma zorunluluğu kalkmaz.
  - Derste denendi (ekrandan, 01:20:00): main içinde 4, fonksiyon içinde 1 sonucu çıktı.
- `swapArrayElement` örneği (ekrandan, 00:35:00 ve 00:40:00)
  - Dizinin `i` ve `j` indisli elemanlarının yerini değiştirir; dizi, iki indis ve eleman sayısı `n` parametre olarak alınır. İndislerden biri geçersizse fonksiyon hiçbir şey yapmadan `return` eder.
  - İlk yazılan denetim `i > n` idi; geçerli indisler 0..n-1 olduğu için `i >= n` olarak düzeltildi (off-by-one hatası).
  - Dizi parametresi üzerinde yapılan değişiklik kalıcıdır: `{1, 2, 3, 4}` dizisinde 0. ve `SIZE-1`. elemanlar değiştirilince main'deki dizi `4 2 3 1` olur.
  - Derleme hatası: `#define SIZE 4;` satırındaki noktalı virgül makronun kullanıldığı satırlarda hata verdi; bir öğrenci fark etti.
- Fonksiyondan dizi döndürme (ekrandan, 01:00:00)
  - C'de bir fonksiyon dizi döndüremez. Asıl dizi değiştirilmeden yeni bir dizi üretilmek isteniyorsa fonksiyon içinde dinamik bellek ayrılır ve bu alanın başlangıç işaretçisi döndürülür.
  - `malloc`/`calloc` ile ayrılan alan fonksiyon bitince geri alınmaz; döndürülen işaretçi geçerli kalır. Yerel değişkenler ise fonksiyon bitince yok olur.
  - `concatArraysV1( int arr1[], int size1, int arr2[], int size2 )`: `(size1+size2)*sizeof(int)` bayt ayırır, önce `arr1`'i, sonra kaldığı `i`'den devam eden ikinci `for` ile `arr2[i-size1]` elemanlarını kopyalar ve `merged` işaretçisini döndürür.
  - `arr1 = {1,5,7,19}`, `arr2 = {2,6,8,12,28}` için birleşik liste `1 5 7 19 2 6 8 12 28` oldu (ekrandan, 01:20:00).
  - İşi bitince main'de `free(ptrM);` yazılmalıdır (bir öğrenci hatırlattı). Fonksiyon içinde `free` yapılmaz; yapılırsa döndürülen işaretçi geçersiz alanı gösterir.
- İşaretçiden diziye kopyalama: `populateArray`
  - `populateArrayV1( int array[], int size, int *begin )`: `array[i] = begin[i];` (ekrandan, 01:15:00). İşaretçiye dizi gibi köşeli parantezle erişilebilir.
  - İkinci sürümde işaretçi her adımda artırıldı: `for` artırım kısmında `i++, begin++` ve gövdede `*begin`.
  - Hoca, işaretçiyle çalışmaya alışınca bu üçüncü dizi mantığına gerek kalmadığını, en doğrusunun işaretçi döndürmek olduğunu söyledi.
- Diziyi çağıran tarafın ayırması (ekrandan, 01:25:00)
  - Fonksiyonun bellek ayırıp işaretçi döndürmesi yerine çağıran taraf boş bir dizi tanımlayıp fonksiyona doldurması için verebilir.
  - `concatArraysV2(..., int arr3[])` (ders notundaki sürüm) `int arr3[9];` ile çalıştı. Dizi tanımı yer ayırmak anlamına geldiği için `malloc` ve `free` gerekmez.
  - `concatArraysV3(..., int *arr3)`: main'de `malloc` ile ayrılan `ptrM` verildi (ekrandan, 01:35:00). Derleme hatasız oldu ama çıktı yanlıştı; hoca nedeni derste bulamadı.
- `main` fonksiyonunun argümanları (ekrandan, 02:00:00)
  - Her C programında `main` bulunur ve ilk çalışan fonksiyondur; `main` dönünce program biter. Derleyici `main`'i diğer fonksiyonlar gibi ele alır, ama çalışma anında iki argümanı çalıştıran ortam (komut satırı) sağlar.
  - `argc`: komut satırında verilen argüman sayısı. `argv`: argümanları gösteren karakter katarı işaretçileri dizisi. Argümanlar boşlukla ayrılır.
  - `argv[0]` çalıştırılabilir dosyanın adıdır; programa verilen ilk argüman `argv[1]`'dir.
  - Slayttaki kod: `while(--argc > 0) printf("%s\n", *++argv);` (ekrandan, 02:05:00). `++argv` önce işaretçiyi `argv[1]`'e ilerletir, `*` o katarı verir.
  - Derste `ali veli 49 50` gibi dört argümanla çalıştırıldı, her argüman ayrı satırda yazıldı; argümansız çalıştırınca hiçbir şey yazmadı. Ardından `for (i = 0; i < argc; i++) printf("%s\n", argv[i]);` ile `argv[0]` de yazdırıldı.
  - `ogrenci=Ali` gibi daha karmaşık argümanlar da verilebilir; o zaman katar `=` işaretinden ayrıştırılmalı, sayılar sayıya çevrilmelidir. `getopt` gibi araçlara girilmedi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Değerle ve referansla aktarım farkı
  - Bu çalışma biçimi kaçırılmamalıdır: değerle aktarılan parametredeki değişiklik fonksiyon bitince kaybolur; kalıcı değişiklik için adres aktarılır.
- Fonksiyon içinde dizi boyutu bulunamaz
  - `SIZE_OF_ARRAY` makrosu yalnız dizinin tanımlandığı yerde doğru çalışır. Fonksiyona dizi değil, dizinin başlangıcını gösteren işaretçi gider; boyut ayrıca aktarılmalıdır.
- Fonksiyondan dizi döndürülemez
  - Bunun yerine fonksiyon içinde `malloc` ile yer ayrılır ve işaretçi döndürülür ya da sonucun yazılacağı dizi parametre olarak verilir.
- Bir `malloc` için bir `free`
  - `free` fonksiyon içinde değil, belleğe ihtiyaç bittiğinde (genelde main'in sonunda) yapılır. Program kapanınca belleği işletim sisteminin geri alması derleyicinin değil ortamın işidir; doğru alışkanlık `free` yazmaktır.
- `return merged;` yazımı
  - İşaretçi döndürülürken başına `*` konmaz; dönüş türündeki `int*` zaten işaretçiyi belirtir.
- İndis sınırı (off-by-one)
  - `n` elemanlı dizide geçerli indisler 0..n-1'dir; denetim `i >= n` olmalıdır.

## Kısa Tekrar Notları

- Varsayılan aktarım değerledir; kalıcı değişiklik için `&x` ile adres, fonksiyonda `int *p` ve `*p` kullanılır.
- `swap` için geçici değişken şarttır: `tmp = *a; *a = *b; *b = tmp;`.
- Dizi parametresi üç biçimde: `int ar[5]` (kullanışsız), `int ar[], int size`, `int *ar, int size`.
- Dizi parametresinde yapılan değişiklik çağıranda görünür.
- `SIZE_OF_ARRAY(x)` fonksiyon içinde işaretçi boyutu / eleman boyutu verir, eleman sayısını vermez.
- Fonksiyon dizi döndüremez; `int*` döndürür. `malloc` ile ayrılan alan fonksiyon bitince yaşar, işi bitince `free` edilir.
- Sonucun yazılacağı dizi çağıran tarafından da verilebilir (`int arr3[]` ya da `int *arr3`).
- `main(int argc, char *argv[])`: `argc` argüman sayısı, `argv[0]` program adı, `argv[1]` ilk argüman.

## Detaylı Açıklamalar

- Değerle ve referansla aktarım
  - `increaseRegular(int aa, int bb)` fonksiyonu `aa += bb;` yapar. main'deki `a` ile fonksiyondaki `aa` bellekte ayrı yerlerdir; çağrıda yalnız değer kopyalanır. Bu yüzden fonksiyon `increaseRegular finishes with 8` yazar ama main `main says the value is 3` der. `increasePointer(int *aa, int bb)` ise `*aa += bb;` ile `a`'nın bulunduğu adrese yazar; main'e dönünce de değer 8'dir. Hoca, değerle aktarımın bir bakıma avantaj olduğunu da söyledi: fonksiyon parametreyle istediği gibi oynayabilir, çağıranın değişkeni bozulmaz.
  - Derste kullanılan kod (ekrandan, 00:10:00; Dev-C++'taki `system("PAUSE");` satırı çıkarıldı, gcc -Wall ile derlendi ve çalıştırıldı):

```c
#include <stdio.h>
#include <stdlib.h>
void increaseRegular( int aa, int bb ) {
    aa += bb;
    printf("increaseRegular finishes with %d\n", aa);
}
void increasePointer( int *aa, int bb ) {
    *aa += bb;
    printf("increasePointer finishes with %d\n", *aa);
}

int main(int argc, char *argv[]){
    int a=3, b=5;
    increaseRegular( a, b );
    printf("main says the value is %d\n", a);
    increasePointer( &a, b );
    printf("main says the value is %d\n", a);
    return 0;
}
```

  - Çıktı: `increaseRegular finishes with 8`, `main says the value is 3`, `increasePointer finishes with 8`, `main says the value is 8`.
- `swapArrayElement` ve dizinin kalıcı değişmesi
  - Dizi fonksiyona verildiğinde aslında başlangıç adresi gider; bu yüzden fonksiyonda dizinin elemanlarına yapılan atamalar main'deki diziyi değiştirir. Derste yazılan son hâl (ekrandan, 00:40:00) aşağıdadır. Ekranda dizinin ilk değer satırı düzenlenirken görüldüğü için `int dizi[SIZE] = {1,2,3,4};` biçiminde yazıldı; `#define SIZE 4` satırındaki noktalı virgül kaldırıldı ve `system("PAUSE");` çıkarıldı. `listArray` gövdesi altyazıdan kuruldu. gcc -Wall ile derlendi ve çalıştırıldı; çıktı `Before: 1 2 3 4` ve `After: 4 2 3 1`.

```c
#include <stdio.h>
#include <stdlib.h>
#define SIZE 4
void listArray( int aa[], int n );
void swapArrayElement( int aa[], int i, int j, int n ) {
    int tmp;
    if( i < 0 || i >= n || j < 0 || j >= n )
        return;
    tmp = aa[i]; aa[i] = aa[j]; aa[j] = tmp;
}
int main(int argc, char *argv[]){
    int dizi[SIZE] = {1,2,3,4};
    printf("Before: "); listArray(dizi,SIZE);
    swapArrayElement( dizi, 0, SIZE-1, SIZE );
    printf("After: "); listArray(dizi,SIZE);
    return 0;
}
void listArray( int aa[], int n ) {
    int i;
    for( i=0; i<n; i++ )
        printf("%d ", aa[i]);
    printf("\n");
}
```

- Fonksiyondan işaretçi döndürerek dizi birleştirme
  - Hoca, asıl diziyi değiştirmeden değiştirilmiş bir kopya elde etmek istendiğini, bunun ancak dinamik bellek ve işaretçi döndürme birlikte kullanılarak yapılabileceğini anlattı. Fonksiyon içinde yerel bir dizi tanımlayıp onu döndürmeye çalışmak olmaz. `concatArraysV1` iki diziyi ve boyutlarını alır, toplam eleman sayısı kadar `int` yer ayırır ve birleşik diziyi bu alana yazar. İkinci `for` döngüsünde ilk değer verilmez, `i` kaldığı yerden devam eder. `calloc` gerekmez, çünkü alanın tamamı doldurulacaktır.
  - Derste denenen program (ekrandan, 01:15:00, 01:20:00, 01:30:00). Fonksiyon içindeki boyut yazdırma satırı makronun burada çalışmadığını göstermek için eklendi. `system("PAUSE");` çıkarıldı, `SIZE_OF_ARRAY` sonucu `%d` için `(int)` ile çevrildi. gcc -Wall ile derlendi ve çalıştırıldı:

```c
#include <stdio.h>
#include <stdlib.h>
#define SIZE_OF_ARRAY(x) (sizeof(x) / sizeof((x)[0]))

void printArray( int a1[], int size ) {
    int i;
    for( i=0; i<size; i++ )
        printf("%d\t", a1[i]);
    printf("\n");
}

int* concatArraysV1( int arr1[], int size1, int arr2[], int size2 ) {
    int *merged = (int*) malloc( (size1+size2)*sizeof(int) );
    int i;
    printf("Size of arr1 calculated in function as %d\n", (int) SIZE_OF_ARRAY(arr1));
    for( i=0; i<size1; i++ )
        merged[i] = arr1[i];
    for( ; i<size1+size2; i++ )
        merged[i] = arr2[i-size1];
    return merged;
}

void populateArrayV1( int array[], int size, int *begin ) {
    int i;
    for( i=0; i<size; i++ )
        array[i] = begin[i];
}

int main(int argc, char *argv[]){
    int arr1[] = {1,5,7,19}, arr2[] = {2,6,8,12,28};
    int arr3[9];
    int *ptrM = concatArraysV1(
        arr1, SIZE_OF_ARRAY(arr1), arr2, SIZE_OF_ARRAY(arr2));
    printf("Size of arr1 calculated in main as %d\n", (int) SIZE_OF_ARRAY(arr1) );
    printf("Array 1 is:\t");
    printArray(arr1, SIZE_OF_ARRAY(arr1));
    printf("Array 2 is:\t");
    printArray(arr2, SIZE_OF_ARRAY(arr2));
    printf("Merged list is:\t");
    printArray(ptrM, SIZE_OF_ARRAY(arr1)+SIZE_OF_ARRAY(arr2));
    populateArrayV1(arr3, 9, ptrM);
    printf("Array 3 is:\t");
    printArray(arr3, 9);
    free(ptrM);
    return 0;
}
```

  - gcc bu kodda `sizeof on array function parameter 'arr1' will return size of 'int *'` uyarısı verir; uyarı tam da derste anlatılan durumu söyler. Birleşik liste ve `Array 3` satırları `1 5 7 19 2 6 8 12 28` olur.
  - Ders sonrası not: Hoca, fonksiyon içindeki sonucun 1 çıkacağını söyledi ve derste kullanılan Dev-C++ ortamında 1 çıktı. Bu sonuç işaretçi boyutunun `int` boyutuna oranıdır ve platforma bağlıdır; 64 bitlik bir sistemde gcc ile denendiğinde 2 çıktı (işaretçi 8, `int` 4 bayt). Her iki durumda da eleman sayısı (4) elde edilmez.
- Çağıranın ayırdığı diziye yazma
  - `concatArraysV2` sonucu yazacağı diziyi beşinci parametre olarak (`int arr3[]`) alır ve `void` döner; main'de `int arr3[9];` tanımı yer ayırdığı için `malloc`/`free` gerekmez. `concatArraysV3` aynı işi `int *arr3` parametresiyle yapar; derste main'de `malloc` ile ayrılan `ptrM` verildi (ekrandan, 01:35:00).
  - Ders sonrası not: Ekranda V3 sonucu yazdırılırken `printArray(arr3, ...)` satırının kaldığı görülüyor; sonuç ise `ptrM`'nin gösterdiği alana yazılmıştı. Yanlış çıktının büyük olasılıkla nedeni, hiç doldurulmamış `arr3`'ün yazdırılmasıdır; `printArray(ptrM, size1+size2)` yazılınca doğru sonuç alınır (gcc -Wall ile denendi). <!-- BELİRSİZ: ekranda satırın sonu kesik, yanlış çıktının kendisi karede görünmüyor -->
- `main` argümanları
  - Slayttaki kod (ekrandan, 02:05:00) `--argc` ile önce sayacı azaltır, böylece program adı sayılmaz; `*++argv` ile işaretçi önce bir sonraki katara ilerletilir. Hoca bu yazımın kriptik olduğunu kabul edip daha düz bir `for` sürümü yazdı. İki sürüm de gcc -Wall ile derlendi ve `ali veli 49 50` argümanlarıyla çalıştırıldı: ilk sürüm dört satır, `for` sürümü önce program adını, sonra dört argümanı yazdı.

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    while(--argc > 0 )
        printf("%s\n", *++argv);
    exit(0);
}
```

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
