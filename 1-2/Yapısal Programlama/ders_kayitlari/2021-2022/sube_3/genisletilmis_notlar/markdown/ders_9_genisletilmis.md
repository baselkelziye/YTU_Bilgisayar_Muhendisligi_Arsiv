# Ders 9 Genişletilmiş Notu: Fonksiyonlarda Parametre Aktarımı, main Argümanları ve Yapılar (struct)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Parametre Aktarımı: Değerle ve Adresle
- 2. Fonksiyondan Dönen Değer Sayısı ve Virgül Operatörü
- 3. İşaretçiyle Birden Fazla Sonuç Döndürme
- 4. const ile İşaretçi Parametreleri
- 5. Stack, Heap ve Değişken Adresleri
- 6. Bildirim, Tanım, Çağrı; Argüman ve Parametre
- 7. İşaretçi Döndüren Fonksiyonlar ve Yaşam Süresi
- 8. Dizilerin Fonksiyona Aktarımı
- 9. Fonksiyondan Dizi Döndürmek: Dizi Birleştirme
- 10. Seyrek Matris
- 11. main Fonksiyonuna Argüman Göndermek
- 12. Yapılar (struct): Neden Gerekli?
- 13. Yapı Tanımı, Değişken Üretme ve typedef
- 14. Yapı Üyelerine Erişim
- 15. İç İçe Yapılar ve Polinom Örneği
- 16. Ders Sonu Soru-Cevaplar
- 17. Dinamik Matris Uygulaması: Kare Olan Dikdörtgenler
- Örnek Sorular
- Dersin Toparlaması

## 1. Parametre Aktarımı: Değerle ve Adresle

Ders, fonksiyonlar konusunun kalan kısmıyla başladı. Konu başlıkları slaytta (ekrandan, 00:10:00) argüman aktarımı (pass by reference, pass by value), bildirimler ve çağrılar (definition, allusion, function call) ve `main` fonksiyonu olarak verildi.

Hangi dil kullanılırsa kullanılsın en sık karşılaşılan kavramlardan biri, bir fonksiyona verinin değerle mi adresle mi aktarıldığıdır. Değerle aktarımda (pass by value) verinin kopyası çıkarılır; derste bu "deep copy" diye anıldı. Bir verinin iki, üç kopyası oluşacağı için hem bellek hem de kopyalama süresi açısından maliyet doğar. Adresle aktarımda (pass by reference) yalnız verinin bulunduğu adres aktarılır ve işlem adres üzerinden yapılır; bu da "shallow" ya da "shadow copy" diye anıldı.

Aktarım biçimi üç şeyi etkiler (ekrandan, 00:10:00):

- Performans: kopyalama maliyeti.
- Doğruluk (accuracy): fonksiyondaki değişikliğin çağırana yansıyıp yansımaması.
- Dönen değer sayısı: fonksiyondan kaç sonuç alınabileceği.

Doğruluk için klasik örnek `swap` fonksiyonudur. `swap(int a, int b)` içinde `t = a; a = b; b = t;` yazılıp main'de önce `a, b` yazdırılır, sonra `swap(a, b)` çağrılır, sonra yine `a, b` yazdırılırsa iki çıktı aynıdır. Çünkü main'deki `a, b` ile fonksiyondaki `a, b` bellekte farklı yerlerdedir; değerler kopyalanmıştır ve fonksiyondaki değişiklik main'e yansımaz.

## 2. Fonksiyondan Dönen Değer Sayısı ve Virgül Operatörü

Bir fonksiyondan `return` ile yalnız bir değer döner. Hoca öğrencilere `return 3, 8;` gibi bir şey yazanın olup olmadığını ve ekranda hangi değerin görüleceğini sordu.

**Soru:** (Bir öğrenci) Hangisi görülür? **Cevap:** C burada hata vermez. Virgül bir operatördür ve tek bir değer üretir; virgülün birleşme yönü gereği en sağdaki ifadenin değeri döner. Kaç virgül olursa olsun en sağdaki döner, bu örnekte ekranda 8 görülür.

MATLAB ya da Python kullananlar böyle bir yazımla birden fazla değer döndürebilir ve çağıran taraf hepsini alabilir. C'de ise kesinlikle tek değer döner. Hocanın belirttiğine göre C++ ve Java bu durumda daha sıkı denetim yapar. C'de birden fazla değer döndürmek gerekiyorsa adresle aktarım kullanılır: değişkenler fonksiyona işaretçi yoluyla gönderilir, fonksiyon içinde birden fazla değişken üzerinde işlem yapılır ve sonuçlar çağırana yansır.

> **Ek bilgi (derste anlatılmadı):** gcc, `-Wall` ile derlendiğinde `return x, y;` için "left-hand operand of comma expression has no effect" uyarısı verir. Bu yazım derlenir ama sol taraf boşa hesaplanır.

## 3. İşaretçiyle Birden Fazla Sonuç Döndürme

Hoca bu fikri Dev-C++'ta kısa bir örnekle gösterdi (ekrandan, 00:15:00 ve 00:20:00):

```c
#include<stdio.h>

int f(int a, int *pa, int *pb);

int main(){
    int a,b,c=6;
    int x;
    x=f(c,&a,&b);
    printf("%d %d %d %d\n",x,a,b,c); //14 12 10 6
    return 0;
}

int f(int a, int *pa, int *pb){
 int x=5, y=7;
 a +=8;
 *pa = x +7;
 *pb = y +3;
 return a;
}
```

Çağrıdan önce `a`, `b` ve `x` ilklendirilmediği için bunları yazdırmak çöp değer gösterir; yalnız `c` 6'dır. Çağrıdan sonraki adımlar şöyledir:

- `c` değerle gider, fonksiyondaki `a` 6 olur. `a += 8` ile 14 olur ve `return a` ile döner, böylece main'deki `x` 14 olur.
- `c` değerle gittiği için 6 olarak kalır.
- `pa`, main'deki `a`'nın adresidir. `*pa = x + 7 = 5 + 7 = 12` yazılır, main'deki `a` 12 olur.
- `pb`, main'deki `b`'nin adresidir. `*pb = y + 3 = 7 + 3 = 10` yazılır, main'deki `b` 10 olur.

Ekranda `14 12 10 6` görülür. Fonksiyon `return` yoluyla bir, parametre yoluyla iki değer aktarmıştır. Program derlenip çalıştırıldı ve bu çıktı doğrulandı (ekranda prototip yoktu, fonksiyon `main`'den sonra tanımlıydı; derleme için prototip eklendi).

> **Hocanın vurgusu:** Fonksiyonlarda bu yöntem çok önemlidir; çoğu zaman adresle aktarım daha işe yarar, çünkü değer kopyalamak gerçekten sorunludur.

## 4. const ile İşaretçi Parametreleri

Performans için işaretçi gönderilir, ama işaretçi gönderildiğinde içeriğin değişmesi mümkün hale gelir. Hem hızlı aktarım hem de içeriğin değişmemesi isteniyorsa parametrenin başına `const` yazılır. Ekrandaki örnek (ekrandan, 00:20:00):

```c
int g(const int *pa, int *pb){
 int x=5, y=7;

 *pb = *pa +3;
 return y;
}
```

`g(&a, &b)` çağrısında `pa`, `a`'nın adresini alır. `*pa` okunabilir ve başka bir yere (burada `*pb`'ye) yazılabilir; ama `*pa = ...` gibi bir atama yapılırsa derleyici "assignment of read-only location" hatası verir. Bu yöntem özellikle bir dizi ya da büyük bir değişken gönderilip değişmemesi istendiğinde kullanılır; hocanın belirttiğine göre C++ programcıları bunu daha sık kullanır.

`const`'un yeri neyin sabitlendiğini belirler. Derste hoca denemeler yaparak üç durumu gösterdi:

- `const int *pa` (ya da `int const *pa`): gösterilen değer sabittir.
- `int * const pa`: `const` işaretçiye yakın olduğu için işaretçinin kendisi sabittir; `pa` yalnız ilk gösterdiği yeri gösterebilir, `pa = &x;` hatadır. Bu tanımlandığı yerde ilk değer verilerek yapılmalıdır.
- `const int * const pa`: ne değer ne adres değiştirilebilir.

> **Ders sonrası not:** Derste hoca bu üç yazımı canlı denerken bir süre hangisinin neyi sabitlediğini karıştırdı ("Acaba tersten mi söyledim?"). Doğrusu yukarıdaki listedir. Ajan gcc ile denedi: `int * const pa` için `pa = &x;` "assignment of read-only variable", `const int * const pa` için hem `*pa = 5;` hem `pa = &x;` hata verir.

## 5. Stack, Heap ve Değişken Adresleri

Slayttaki örnek (ekrandan, 00:25:00) iki fonksiyonu karşılaştırır:

```c
#include <stdio.h>
void increaseRegular( int aa, int bb ) {
    aa += bb;
    printf("increaseRegular finishes with %d\n", aa);
}
void increasePointer( int *aa, int bb ) {
    *aa += bb;
    printf("increasePointer finishes with %d\n", *aa);
}
int main() {
    int a=3, b=5;
    increaseRegular( a, b );
    printf("main says the value is %d\n", a);
    increasePointer( &a, b );
    printf("main says the value is %d\n", a);
    return(0);
}
```

`increaseRegular` çağrıldığında 3 ve 5 değerleri kopyalanarak `aa` ve `bb`'ye gelir. Fonksiyon kendi içinde 8 yazar, main'e dönülünce `a` hâlâ 3'tür. `increasePointer`'da `aa`'ya `a`'nın adresi gelir, `bb`'ye 5 kopyalanır. `*aa += bb` adresin gösterdiği yeri 8 yapar; bu değer main'de de 8 olarak görülür. Kod derlenip çalıştırıldı; çıktı sırasıyla 8, 3, 8, 8 oldu.

Hoca bunun bellekteki karşılığını çizdi. Belleğin bir stack bölgesi, bir de heap bölgesi vardır:

- Stack bölgesi (assembly'de stack segment) yerel değişkenler için kullanılır: `int`, `char`, `float`, her düzeyden işaretçi ve yapı değişkenleri. Bunlar fonksiyona değerle aktarılırsa kopyalanır; işaretçi aktarılırken de aslında adres değeri kopyalanır.
- Heap bölgesi `malloc` ile oluşturulan alanlar içindir. Bu alanlara adres üzerinden doğrudan erişilir.

Değişkenlere adres gelişigüzel verilmez. Hoca bunu `%p` ile adresleri yazdırarak gösterdi (ekrandan, 00:30:00). `int a, b; char d; int c;` için ekranda şu adresler görüldü:

| Değişken | Adres |
|---|---|
| `a` | `000000000062FE1C` |
| `b` | `000000000062FE18` |
| `d` | `000000000062FE17` |
| `c` | `000000000062FE10` |

`1C`'den 4 çıkarınca `18` olur: `b`, `a`'nın 4 bayt altındadır. `char d` 1 bayt yer kapladığı için `17`'dedir. `c` ise `10`'dadır; hoca aradaki farkın doldurma (padding) gibi bir nedenden olabileceğini söyledi. Aynı şeyi `f` fonksiyonunun işaretçi parametrelerinin adresleriyle yapınca adresler 8'er bayt farkla dizildi <!-- BELİRSİZ: bu adresler karede görülmedi, altyazıdan alındı -->. Sonuç: tanımlanan değişkenler belirli bir düzenle, en son tanımlanan en aşağıda olacak şekilde yerleşir.

> **Ders sonrası not:** Hoca adreslerin bu sırasını bir yerde little endian ile ilişkilendirdi. Endianness çok baytlı bir değerin baytlarının sırasıyla ilgilidir; yerel değişkenlerin stack'teki sırası ve aralarındaki boşluklar büyük olasılıkla derleyiciye, hizalama kurallarına ve en iyileme ayarlarına bağlıdır ve standartta garanti edilmez.

> **Ders sonrası not:** Hoca yapıları da primitif türler arasında saydı. Yapı, temel türlerden oluşturulan kullanıcı tanımlı (türetilmiş) bir türdür; yerel bir yapı değişkeninin stack'te tutulması ve değerle aktarılınca kopyalanması doğrudur.

## 6. Bildirim, Tanım, Çağrı; Argüman ve Parametre

- Bildirim (declaration): fonksiyonun prototipini yazmaktır.
- Çağrı (call): fonksiyonu kullanmak için yazılan komuttur. `printf` nasıl tanımına uygun biçimde (bir string ve varsa parametreler) çağrılıyorsa her fonksiyon tanımına uygun çağrılmalıdır.
- Tanım (definition): fonksiyonun gövdesini, yani ne yapacağını yazmaktır.
- Allusion: başka bir yerde tanımlı bir fonksiyonun bildirimidir.

Slayttaki örnekler (ekrandan, 00:35:00):

```c
void simpleFunction1( void );    // prototype of last example
simpleFunction1();

extern float simpleFunction2();
int factorial( int );
void sortArray(int *, int);
float *mergeSort(float *, int, float *, int, int *);
```

`simpleFunction1` parametre almaz, değer döndürmez; ikinci satır onun çağrısıdır. `extern` anahtar sözcüğü `simpleFunction2`'nin başka bir yerde, örneğin başka bir C dosyasında tanımlı olduğunu söyler; derleyici programı derlerken diğer dosyalara da bakar. `factorial` `int` alıp `int` döndürür, `sortArray` bir `int*` ve bir `int` alan `void` fonksiyondur, `mergeSort` büyük olasılıkla iki diziyi birleştiren ve geriye `float*` döndüren bir fonksiyondur. Slaytta birden fazla kaynak dosyalı projenin ileride gösterileceği de yazıyordu.

Fonksiyon çağrılırken gönderilene **argüman**, fonksiyon tanımlanırken alınana **parametre** denir.

Program çalıştırıldığında işletim sistemi önce `main` fonksiyonunu arar; `main`'den önce yazılan bir şey kendiliğinden çalışmaz. Diğer fonksiyonlar `main`'in akışına göre çağrılır. Kod yazılırken fonksiyonların prototipleri ya da tanımları `main`'den önce yazılabilir; tanım `main`'den önce yazılırsa prototipe gerek kalmaz. Prototiplerin sırası çağrı sırasını belirlemez; önce `f`, sonra `g` prototipi yazılıp `main`'de istenen sırada çağrılabilir.

Slayttaki küçük alıştırmalardan biri, girilen bir karakterin alfabetik olup olmadığını denetleyen `check` fonksiyonudur. Karakter `'a'` ile `'z'` arasında ya da `'A'` ile `'Z'` arasındaysa doğru (1), değilse 0 döndürülür.

## 7. İşaretçi Döndüren Fonksiyonlar ve Yaşam Süresi

Slaytta `static` ve `extern` sözcüklerinin işaretlendiği kısımdan sonra hoca, işaretçi döndüren fonksiyonlarda dikkat edilmesi gereken noktaya geçti. Bir fonksiyon içinde şunlar olsun:

- `int x;` gibi basit bir yerel değişken,
- `static int y;` gibi statik bir yerel değişken,
- `int *px = malloc(...)` ile açılmış bir alan.

`return` ile `&x`, `&y` ya da `px` yazılabilir; üçü de derlenir. Ama çağıran taraf (örneğin `main`) bunu bir işaretçide tuttuğunda `&y` ve `px` program kapanana kadar geçerlidir, `&x` değildir. Değişkenlerin kapsamı (scope) ve yaşam süresi (duration) vardır: yerel `x` fonksiyon bitince ölür. `static` değişken program kapanana kadar yaşar ve öldürülemez; `malloc` ile ayrılan alan da `free` edilene kadar yaşar.

Aynı sorun yerel diziler için de geçerlidir: fonksiyon içinde `int d[10];` tanımlanıp `d` ya da `&d[0]` döndürülürse, bu da yerel bir değişkenin adresidir ve geçersizdir.

> **Hocanın vurgusu:** Geriye işaretçi döndüren bir fonksiyon yazıyorsanız neyi döndürdüğünüzün çok farkında olun. Dizi döndürülecekse `malloc` ile, tek değişken döndürülecekse `static` ile oluşturulmalıdır.

## 8. Dizilerin Fonksiyona Aktarımı

Diziyi fonksiyona aktarmanın iki yolu vardır: dizinin tamamını ya da tek bir elemanını aktarmak. Dizinin tamamını aktarırken parametre `int a[5]` gibi sabit boyutla yazılabilir, ama her zaman 5 olmaz; `#define` ile biraz daha parametrik hale getirilebilir. C sınır denetimi yapmaz, dizinin dışına taşılıp taşılmadığına bakmaz; bunu programcı denetlemelidir. Diğer yol dizinin ilk adresini ve boyutunu göndermektir. Dizi adı bir işaretçi gibidir, sadece başka bir yeri göstermesine izin verilmez.

Hoca Dev-C++'ta üç biçimi yazdı (ekrandan, 00:45:00):

```c
int main(){
    int dizi[MAX];
    dizi_yaz(dizi);
    dizi_yaz1(&dizi,MAX);
    dizi_yaz2(&dizi[0],MAX);
}

void dizi_yaz(int dizi[MAX]){
}

void dizi_yaz1(int dizi[], int max){
}

void dizi_yaz2(int dizi[], int max){
}
```

İlk biçim önerilmez, çünkü `MAX`'ın ne olacağı önceden bilinemez; `#define` derleme öncesi işlenir ve program çalışırken değiştirilemez. Bunun yerine boyut ayrı bir parametre olarak (örneğin kullanıcıdan alınıp) gönderilir. Hoca `dizi_yaz2`'de parametreyi doğrudan işaretçi (`int *`) olarak almayı ve fonksiyonu `&dizi[0]` ya da `dizi` ile çağırmayı anlattı. Fonksiyon içinde dizi bir `for` döngüsünde `dizi[i]` biçiminde, yazdırmak ya da değer değiştirmek için kullanılabilir.

> **Ders sonrası not:** Ekrandaki `dizi_yaz1(&dizi, MAX);` çağrısında `&dizi`'nin türü `int (*)[10]`'dur, `int *` değildir. Eski derleyiciler yalnız uyarı verir; ajanın denediği güncel gcc bunu "incompatible pointer type" hatası olarak verdi. Doğru çağrı `dizi_yaz1(dizi, MAX);` ya da `dizi_yaz1(&dizi[0], MAX);` biçimindedir.

Bir dizinin eleman sayısı bilinmiyorsa bir makro tanımlanabilir: `sizeof(x)` dizinin bellekte kapladığı toplam baytı verir; bunu bir elemanın boyutuna, `sizeof(x[0])`'a bölmek eleman sayısını verir.

> **Ek bilgi (derste anlatılmadı):** Bu makro yalnız dizinin tanımlandığı kapsamda doğru çalışır. Fonksiyon parametresi olarak gelen dizi aslında işaretçi olduğu için orada `sizeof` işaretçinin boyutunu verir.

Slaytta bir sıralama fonksiyonunun evde yazılması istendi. Fonksiyon `void` olabilir: dizi adresle (call by reference mantığıyla) aktarıldığı için fonksiyondaki bütün değişiklikler asıl diziyi değiştirir, ayrıca değer döndürmeye gerek yoktur.

## 9. Fonksiyondan Dizi Döndürmek: Dizi Birleştirme

C'de `int[] f(...)` gibi dizi türünde dönüş yoktur; hocanın belirttiğine göre Java ve C#'ta vardır. Çözüm, fonksiyon içinde dinamik bellekle (`malloc`) bir dizi oluşturup işaretçisini döndürmektir. Görünüşte bir işaretçi döner ama bu işaretçi bir diziyi gösterir ve çağıran yerde dizi gibi kullanılabilir.

Slayttaki örnek iki diziyi birleştirmektir (concatenation): 4, 8, 2 dizisinin arkasına 6, 6, 5, 4 eklenerek yepyeni bir 4, 8, 2, 6, 6, 5, 4 dizisi oluşur. Yeni dizinin boyutu önceden bilinemez; 500 elemanlık gibi geniş bir yer açılabileceği düşünülebilir, ama doğrusu gelen boyutlara göre dinamik bellekle açmaktır. Böylece dizi, program yaşadıkça (ya da `free` edilene kadar) kalır. Fonksiyon açılan alana önce birinci, sonra ikinci diziyi kopyalar ve işaretçiyi döndürür. `main`'de dizilerin boyutu bilinmiyormuş gibi bir boyut makrosuyla hesaplanır, diziler ve sonuç yazdırılır, en sonda sonuç `free` edilir.

<!-- BELİRSİZ: malloc kullanan birinci sürümün slayt kodu karede görülmedi; aşağıdaki kod hocanın anlatımından ajan tarafından yeniden kuruldu, derlendi ve çalıştırıldı (çıktının son satırı 4 8 2 6 6 5 4). Fonksiyon ve makro adları slayttakinden farklı olabilir. -->

```c
#include <stdio.h>
#include <stdlib.h>
#define SIZE_OF_ARRAY(x) (sizeof(x)/sizeof((x)[0]))

void printArray( int a1[], int size ) {
    int i;
    for( i=0; i<size; i++ ) printf("%d\t", a1[i]);
    printf("\n");
}

int* concatArrays(int arr1[], int size1, int arr2[], int size2){
    int i;
    int *arr3 = (int*) malloc((size1+size2)*sizeof(int));
    for(i=0;i<size1;i++) arr3[i] = arr1[i];
    for(;i<size1+size2;i++) arr3[i] = arr2[i-size1];
    return arr3;
}

int main(){
    int a1[] = {4,8,2}, a2[] = {6,6,5,4};
    int s1 = SIZE_OF_ARRAY(a1), s2 = SIZE_OF_ARRAY(a2);
    int *ptr = concatArrays(a1, s1, a2, s2);
    printArray(a1, s1); printArray(a2, s2); printArray(ptr, s1+s2);
    free(ptr);
    return 0;
}
```

Hoca `free` konusunu bellek çizimiyle açıkladı: `ptr` bu fonksiyonda (`main`'de) oluşturulmamış bir alanı gösteriyor, ama bu önemli değildir. `malloc` ile açılan alan heap'tedir; stack'teki `ptr` değişkeni o alanı gösterir. `free(ptr)` denince o adresten başlayan alan başka bir isteğe verilebilecek biçimde serbest bırakılır.

Slaytta bunun bir alternatifi de vardı (ekrandan, 01:10:00):

```c
#include <stdio.h>
void printArray( int a1[], int size ) {
    int i;
    for( i=0; i<size; i++ )
        printf("%d\t", a1[i]);
    printf("\n");
}
void concatArraysV2( int arr1[], int size1, int arr2[],
        int size2, int arr3[] ) {
    int size3 = size1+size2;
    int i;
    for( i=0; i<size1; i++ )
        arr3[i] = arr1[i];
    for( ; i<size1+size2; i++ )
        arr3[i] = arr2[i-size1];
}
```

Burada üçüncü dizi çağıran yerde `size1 + size2` boyutunda tanımlanır ve parametre olarak gelir; fonksiyon yalnız içeriğini doldurur ve değişiklik çağırana yansır. Hoca bu yöntemin her zaman çalışmayabileceğini söyledi: dizi stack'te oluşturulurken o kadar bitişik yer yoksa dizi oluşturulamayabilir. Bu yüzden gerçek uygulamalarda pek önerilmez; `malloc` kullanan yöntem işin olması gereken tarafıdır. Alternatif fonksiyon küçük bir `main` ile derlenip çalıştırıldı, sonuç 4, 8, 2, 6, 6, 5, 4 oldu (`size3` kullanılmadığı için gcc uyarı verir).

Slaytta ayrıca iki sıralı dizinin birleşimini (union) yeni bir dizi olarak döndüren bir fonksiyon yazmak alıştırma olarak verildi.

## 10. Seyrek Matris

Slayttaki bir sonraki alıştırma seyrek (sparse) matrisi sıkıştıran bir fonksiyondur. Hoca konuyu kısaca özetledi. 9 şehir arasındaki yolları gösteren 9×9'luk bir matris düşünülsün: çoğu hücre 0, az sayıda hücre 1'dir. 81 hücrenin belki 10 tanesi 1'dir, yani 71 tane gereksiz 0 tutulur.

Bunun yerine her satırında (i, j, değer) üçlüsü tutulan n×3'lük (ya da 3×n'lik) yeni bir yapı kullanılabilir. Değer yalnız 1 ise tutulmayabilir de; ama iki şehir arasında maliyet (örneğin kilometre) varsa üçüncü sütunda o tutulur. Örneğin "3 ile 8 arasında 10" demek, 3. şehirden 8. şehre maliyetin 10 olduğu anlamına gelir. 10 tane sıfırdan farklı değer için 10×3 = 30 hücre yeter; 81'den 30'a düşülmüş olur. Hoca bu konunun teorisinin ayrık matematikte graflar konusunda anlatılacağını söyledi.

Fonksiyon (`compress`) bir matris alır; matris dinamik olarak oluşturulur. Sıfırdan farklı eleman sayısı ya önceden sayılmış olarak parametre gelir ya da fonksiyonda sayılır, o kadar satır × 3 yer açılır, sonra matris gezilerek sıfırdan farklı değerler yerleştirilir. Hoca kodun hazır olduğunu ama öğrenmek için kendi başınıza yazmaya çalışmanızı istedi (çözüm için Örnek Sorular bölümüne bakın).

## 11. main Fonksiyonuna Argüman Göndermek

Şimdiye kadar hep fonksiyonlara parametre gönderildi; acaba `main`'e de gönderilebilir mi? Bunun için `main`'in iki parametresi vardır. Hoca `D:\Deneme` klasöründe bir C programı yazdı (ekrandan, 01:20:00):

```c
#include<stdio.h>
#define MAX 10
int main(int argc, char *argv[]){
// argc : Kaç tane argüman programa gönderildi
// argv : Gönderilen argümanlar neler (string)
int i;
printf("Gelen arguman sayisi = %d\n"+argc);
for(i=0;i<argc;i++){
    printf("%d . arguman =%s \n",ar
```

- `argc` (argument counter): kaç argüman geldiğini söyleyen bir tam sayıdır.
- `argv` (argument vector): karakter işaretçilerinin dizisidir. Her elemanı bir string'in başlangıç adresini tutar.

Hoca `argv`'yi beyaz tahtada çizdi: komut satırında "Hello World" gibi ya da "ABC", "4" gibi string'ler gönderildiğinde her birinin ilk karakterinin adresini tutmak için bir diziye ihtiyaç vardır; bu dizi karakter dizisi değil, karakter işaretçisi dizisidir. `argv[0]` ilk string'in başını gösterir; `%s` bu adresten başlayıp `'\0'` görene kadar bütün karakterleri yazar.

Program Dev-C++'ta derlendi, sonra komut satırında (`cmd`) `cd deneme` ile klasöre gidilip çalıştırıldı. Program adının arkasına `1`, `ABC`, `XYZ` gibi şeyler yazınca program yine çalışır; bu, `main`'e dışarıdan argüman göndermek demektir. Hoca gcc'yi örnek verdi: gcc de bir programdır ve `-o` gibi seçenekler, derlenecek kaynak dosyanın adı, üretilecek çalıştırılabilir dosyanın adı ve en iyileme seçenekleri ona gönderilen argümanlardır.

İlk çalıştırmada argüman sayısı satırında anlamsız bir çıktı görüldü. Ekrandaki satırda `printf("Gelen arguman sayisi = %d\n"+argc);` yazıyordu; hoca virgül yerine `+` yazıldığını fark etmeden "`%d`'nin değeri yazılmadığı için" dedi ve satırı `printf("Gelen arguman sayisi = %d\n", argc);` olarak düzeltti. Yeniden derleyince argüman sayısı 4 oldu ve argümanlar sırasıyla yazıldı: 0. argüman programın adıdır, sonra gönderilenler gelir.

> **Ek bilgi (derste anlatılmadı):** `"...%d\n" + argc` ifadesi string'in başlangıç adresini `argc` kadar ilerletir; `printf` o adresten başlayan metni biçim olarak alır ve `%d` için argüman olmadığından tanımsız davranış oluşur. Anlamsız çıktının nedeni budur.

**Soru:** Gönderilen argüman sayı ise (örneğin 444), string olarak geldiğine göre sayıya çevrilebilir mi? **Cevap:** Evet. `i = atoi(argv[3]);` ile tam sayıya çevrilir; `atof` ile `float`'a çevrilmeye çalışılır. Ama her zaman çevrilemez, çevrilebilecek bir şey olması gerekir. Hoca `i++` ekleyip 444 gönderdi ve 445 görüldü; sayı gerçekten işlem yapılabilir hale gelmişti.

> **Ders sonrası not:** Hoca `atoi`'yi "argüman to integer" diye açıkladı. Adın açılımı "ASCII to integer"dır (`atof`: "ASCII to float").

Ajan aynı programı (düzeltilmiş `printf` ile) derleyip `ABC 1 xyz` argümanlarıyla çalıştırdı: argüman sayısı 4, 0. argüman program adı, sonra `ABC`, `1`, `xyz` yazıldı. `atoi(argv[3])` ile 444'ün 445'e çevrilmesi de doğrulandı.

> **Hocanın vurgusu:** Parametre sırası önemlidir: önce `argc`, sonra `argv` yazılır.

Slaytta komut satırı argümanlarını işleyen özel fonksiyonlar (seçenek, alt seçenek gibi) da vardı. Hoca bunların sistemden sisteme değiştiğini (Linux'ta ve Windows'ta farklı çalıştığını) ve öğrencilerin bunlardan sorumlu tutulmayacağını söyledi.

## 12. Yapılar (struct): Neden Gerekli?

Yeni konu, slayt kapağında "Structures and Unions" başlığıyla açıldı (ekrandan, 01:25:00). Şimdiye kadar aynı türden birden fazla verinin birleştirildiği diziler kullanıldı. Ama bu birçok problemi çözmekte yetersiz kalır. Örneğin n öğrencinin adı, soyadı, vize ve final notu tutulacaksa, `malloc` ile her nitelik için ayrı bir işaretçi ve ayrı yer açılması gerekir. Bu iyi bir yol değildir.

Gerçek hayattaki verileri ve nesneleri soyutlama (abstraction) mantığıyla modellemek gerekir. Hoca bunun bir algoritma meselesi değil, bir programlama kolaylığı olduğunu belirtti: sıralı, şartlı (`if`) ve tekrarlı (`for`, `while`) işlemlerle her program yazılabilir ama bir yerden sonra bu yetersiz kalır. İlk kolaylık diziler oldu; ama dizide tek türde eleman saklanır ve gerçek dünyadaki verilerin çoğu tek bileşenden oluşmaz.

Öğrenci nesnesi düşünülsün: ad (`char*` ya da karakter dizisi), soyad (karakter dizisi), vize (`float`), final (`float`). Bu nesneyi temel türler cinsinden tasarlayıp yeni bir tür tanımlarız; buna **yapı (structure)** denir, özelleşmiş hali ise **union**'dır.

Hoca soyutlamayı iki benzetmeyle açıkladı. Birincisi, büyük ve küçük "e" harfi arasında anlam ya da ses olarak fark yoktur; bu ikiye ayrım insanların sembollere yüklediği bir anlamdır. İkincisi, gerçekte "hafta sonu" diye bir şey yoktur; günler akıp gider, insanlar işlerini düzene koymak için yedi günü beşe iki bölmüştür. Programdaki soyutlama da böyledir: öğrenciyi bilgisayarın içine koymayız, niteliklerini bilgisayardaki temel veri türleri (`int`, `char`, `float`, `bool`, işaretçi) cinsinden yazarız.

Konunun başlıkları yapı tanımı, iç içe yapılar, yapı dizileri ve yapıların fonksiyona gönderilmesidir. Bir şeyin dizisi iki türlü olur: sabit (`int a[10]` gibi) ya da `malloc` ile dinamik. Yapılarda da hiçbir fark yoktur: `int *t = malloc(n * sizeof(int))` nasıl yazılıyorsa `ogrenci *o = malloc(n * sizeof(ogrenci))` yazılır. Fonksiyona nasıl bir `int` dizisi gönderiliyor ya da fonksiyondan `int*` alınabiliyorsa, yapı dizisi gönderilip yapı işaretçisi de alınabilir.

> **Hocanın vurgusu:** Bu dersin asıl gayesi, yaklaşık yüzde 60'lık kısmı, yapıları dizilerle (`malloc` ile dinamik bellek yöntemleriyle oluşturulan dizilerle) ve fonksiyonlarla birlikte kullanmaktır: fonksiyona parametre göndermek ve fonksiyondan çıkış almak.

Slaytta dizinin yetersizliği şu örnekle verildi: 1000 kişinin 20'şer karakterlik adını tutmak için 1000×20'lik bitişik bir karakter matrisi gerekir; soyadları, kimlik numaraları ve maaşlar için de ayrı ayrı yer açılır. Verileri okumak için her biri için ayrı `printf` ve `scanf` satırları yazılır, program zorlaşır. Bunun yerine `employee` adlı bir yapı oluşturup ad, soyad, kimlik numarası ve maaşı bu yapının üye değişkenleri (member variable) yapmak çok daha düzenlidir.

## 13. Yapı Tanımı, Değişken Üretme ve typedef

Yapı genelde `main`'in üstünde, dosyanın başında tanımlanır. `struct` anahtar sözcüğünden sonra yapının adı, süslü parantez içinde üye değişkenler yazılır ve kapanıştan sonra noktalı virgül konur. Bu bir tür tanımıdır: artık programda `employee` adında yeni bir veri türü vardır; `char`, `int`, `float` nasıl birer türse bu da bir türdür.

Değişken üretmek için:

- Tek değişken: `struct employee e;` (`struct` sözcüğü mutlaka yazılır).
- Sabit dizi: `struct employee e[1000];`
- Dinamik dizi: `struct employee *e;` tanımlanıp `n` kullanıcıdan alındıktan sonra `e = malloc(n * sizeof(struct employee));`

Her seferinde `struct` yazmamak için `typedef` kullanılır. `typedef A B;` "A yerine B kullanılabilir" demektir; hocanın deyişiyle insanın kendi dilini oluşturmasını sağlar. Örneğin `int` yerine `tamsayi` tanımlanırsa `tamsayi a;` yazılabilir. Hoca bunu makro gibi bir yerine koyma (substitution) olarak düşünmeyi önerdi. Yapı için `typedef struct {...} EMPLOYEE;` yazılınca derleyici `EMPLOYEE` gördüğü yerde o yapıyı anlar; artık `EMPLOYEE e[1000];` ya da `EMPLOYEE *e;` ile `malloc` kullanılabilir. Bu tür adları genelde büyük harfle yazılır.

Hoca bu yıl örnekleri polinom üzerinden yürüteceğini söyledi. Bir polinom terimi için gereken nitelikler katsayı ve derecedir. Polinomun genel biçimi:

$$a_1 x^{n} + a_2 x^{n-1} + \dots + a_n x^{0}$$

Başlangıçta yapı yalnız tek bir terimi tutar; terim sayısı daha sonra artırılacaktır. Hoca üç tanım biçimini gösterdi:

- Birinci yöntem: `struct polinom { int katsayi; int derece; };` ve değişken için `struct polinom p1;`
- İkinci yöntem: `typedef struct polinom1 { int katsayi; int derece; } POLINOM1;` Bundan sonra hem `POLINOM1 p2;` hem `struct polinom1 p3;` yazılabilir. `typedef` yazılıp sona bir ad yazılmazsa derleyici boş bildirim (empty declaration) uyarısı verir, hata vermez.
- Üçüncü yöntem: `typedef struct { int katsayi; int derece; } POLINOM2;` Burada `struct` sözcüğünden sonra ad olmadığı için yalnız `POLINOM2 p4;` yazılabilir, `struct ...` biçimi kullanılamaz.

> **Hocanın vurgusu:** Üçü de olur ama üçünü de bilmek gerekir. Tercih edilen ve derste önerilen yazım ikincisidir (`typedef struct ad {...} AD;`).

Ekrandaki tanım (ekrandan, 01:45:00):

```c
#include <stdio.h>
// polinom = a1*x^(n) + a2*x^(n-1) ....+ an*x^0
typedef struct polinom{
    int katsayi;
    int derece;
}POLINOM;

int main(){
    POLINOM p1;
    POLINOM *p2;
```

Bu türden normal değişkenlerle yapılabilen her şey yapılabilir (ekrandan, 01:55:00):

```c
    POLINOM *p2;
    POLINOM **p3;

    POLINOM p4[10];
    POLINOM *p5[10];

    POLINOM p6[4][8];
```

`p4` 10 elemanlı bir polinom dizisi, `p5` 10 tane polinom işaretçisi tutan bir dizi, `p6` 4×8'lik bir polinom matrisidir; `p3` ikinci dereceden işaretçidir.

Hoca, öğrencilerin yapılara geçince önceki konularla bağı koparmasına anlam veremediğini söyledi: yapı, kullanıcının tanımladığı bir türdür, geri kalan her şey `int` ve dizilerle birebir aynıdır. Derleyici arka planda `POLINOM` yerine katsayı ve dereceyi saklar.

## 14. Yapı Üyelerine Erişim

### 14.1 Nokta operatörü

Üyelere erişmenin iki yolu vardır: işaretçisiz ve işaretçili. Slayttaki örnekte bir çalışan değişkeninin kimlik numarasına nokta (`.`) operatörüyle erişilir. Polinom örneğinde:

```c
    p1.derece = 4;
    p1.katsayi= 6;
    printf("Derece= %d , Katsayi = %d\n",p1.derece,p1.katsayi);
    printf("Struct Adress =%p, Derece= %p , Katsayi = %p\n",&p1,&p1.derece,&p1.katsayi);
```

(ekrandan, 01:55:00)

Bellekte `p1` için bir yer ayrılır ve içinde iki üye bulunur; atama ile bu üyelere 4 ve 6 yazılır. Hoca bunu bir bellek kutusu çizerek gösterdi.

Yapı dizi gibi değildir. Dizide bütün elemanlar aynı boyutta olduğu için başlangıç adresine 5 eklenince 5. elemana gidilir. Yapıda üyeler farklı türde ve boyutta olabileceği için (örneğin derece `int`, katsayı `float`) üyelere doğrudan işaretçi aritmetiğiyle gidilmez.

Adresler yazdırılınca yapının adresinin (örneğin `...FE00`) ilk tanımlanan üye olan katsayının adresiyle aynı olduğu görüldü; derece, katsayının 4 bayt ilerisindeydi. Katsayı `double` yapılınca derece 8 bayt ileriye yerleşti. Yani üyeler tanımlandıkları sırayla yerleşir.

Adreslerin yazdırılmasının bir amacı da `scanf`'tir: kullanıcıdan derece ya da katsayı okunacaksa üyenin adresi verilmelidir:

```c
    printf("Derece giriniz"); scanf("%d",&p1.derece);
    printf("Katsayi giriniz"); scanf("%lf",&p1.katsayi);
    printf("Derece= %d , Katsayi = %2.2lf\n",p1.derece,p1.katsayi);
```

(ekrandan, 01:55:00)

Derste önce katsayı `%d` ile yazdırıldığı için girilen 98 doğru görünmedi; katsayı `double` olduğundan okuma ve yazmada `%lf` (long float) kullanılması gerektiği fark edildi. Sonra çıktı `%2.2lf` biçimine getirildi.

### 14.2 İşaretçi önce bir yeri göstermeli

Slayttaki bir örnekte bir yapı işaretçisi (`e_ptr`) tanımlanıp hemen üyesine atama yapılıyordu. Hoca bunun eksik olduğunu belirtti: işaretçi hiçbir yeri göstermiyorsa atama yapılamaz. `int a; int *pa;` tanımlandıktan sonra `*pa = 5;` denirse hata alınır; önce `pa = &a;` yazılmalıdır. Yapıda da önce `e_ptr = &calisan;` gibi bir atamayla işaretçi bir yapı değişkenini göstermeli, ondan sonra üyelere erişilmelidir.

Polinom örneğinde (ekrandan, 02:10:00):

```c
    p2=&p1;
    p3=&p2;
    (*p2).derece=66;
    p2->katsayi=100;
    printf("Derece= %d , Katsayi = %2.2lf\n",p1.derece,p1.katsayi);
```

`p2`, `p1`'in adresini tutar; `p3` ise `p2`'nin adresini tutar ve dolaylı olarak `p1`'i gösterir. Üç değişkenle de aynı yere erişilebilir.

### 14.3 (*p).uye ve p->uye

Hoca önce `p2.derece = 66;` yazıp derledi. Derleyici "request for member 'derece' in something not a structure or union" hatası verdi: `p2` bir işaretçidir, yapı değildir. `*p2.derece` yazınca da olmaz, çünkü nokta operatörünün önceliği yıldızdan yüksektir; önce `p2.derece` hesaplanmaya çalışılır. Doğru yazım, önce parantezle `p2`'nin gösterdiği yapıya gitmek, sonra noktayı kullanmaktır: `(*p2).derece = 66;`

İkinci ve daha kolay yol ok operatörüdür: `p2->katsayi = 100;` Ekrana `p1` üzerinden yazdırınca 66 ve 100 görüldü. Ajanın kurduğu küçük programda (katsayı `double`) bu değerler `p1` üzerinden ve `p3` üzerinden (`(*p3)->derece`, `(**p3).katsayi`) aynı çıktıyı verdi.

### 14.4 İşaretçiyle scanf ve operatör önceliği

`scanf` ile `p2` üzerinden okuma yapılmak istendi. Hoca öğrencilere `p2->derece`'nin önüne `&` konmalı mı diye sordu.

**Soru:** (Hoca sordu) `scanf` içinde `p2->derece` yazılırken `&` gerekli mi? **Cevap:** (Bir öğrenci) `p2` zaten adres olduğu için gerek yok. Hoca ilk kısmın doğru olduğunu ama eksik olduğunu söyledi: `p2` bir adrestir, ama `p2`'nin derece alanı bir adres değil, bir değerdir. `&` olmadan program derlenir ama değer girildiğinde çalışma anında hata (exception) oluşur, tıpkı düz bir değişkende `scanf("%d", a)` yazınca olduğu gibi. Doğrusu `&p2->derece` ve `&p2->katsayi` yazmaktır.

Ekrandaki son hali (ekrandan, 02:15:00):

```c
    printf("Struct Adress =%p, Derece= %p , Katsayi = %p\n",p2,&p2->derece,&p2->katsayi);

    printf("Derece= %d , Katsayi = %2.2lf\n",p2->derece,(*p2).katsayi);

    printf("Derece giriniz"); scanf("%d",&p2->derece);
    printf("Katsayi giriniz"); scanf("%lf",&p2->katsayi);
    printf("Derece= %d , Katsayi = %2.2lf\n",p2->derece,(*p2).katsayi);
```

Hoca bunu operatör öncelik tablosuyla açıkladı: nokta ve ok operatörleri en yüksek öncelikli gruptadır, adres operatörü bir alttadır. Bu yüzden `&p2->derece` önce derece alanına gider, sonra o alanın adresini alır. `p2` ile `&p1`, `&p2->derece` ile `&p1.derece` aynı adresi verdi.

### 14.5 & ve * birbirini götürür

Hoca `&` (adres) ve `*` (dereferans) operatörlerinin birbirini götürdüğünü hatırlattı. `&a` "a'nın adresi", `*&a` "a'nın adresindeki değer" yani `a`'dır; önüne bir `&` daha konursa yine `a`'nın adresi olur. Ama `**&a` gibi "değerin değeri" olmaz, derleyici geçersiz der. `&&a` gibi "adresin adresi" de olmaz: `a`'nın kendi adresi vardır, ama o adresi bir işaretçi tutmuyorsa onun da adresi olamaz.

## 15. İç İçe Yapılar ve Polinom Örneği

### 15.1 Terim ve polinom ayrımı

Polinom örneğine dönen hoca yeni bir ihtiyaç ortaya koydu. Bir `POLINOM` değişkeninde yalnız bir derece ve bir katsayı vardır; oysa bir polinom birden fazla terimden oluşur. Polinom dizisi açılabilir: 10 ya da 100 eleman verilebilir, ama `n` verilemez. Bu yüzden `POLINOM *pptr = (POLINOM*) malloc(n * sizeof(POLINOM));` yazılabilir (`malloc` `void*` döndürdüğü için dönüşüm yapılır ve `stdlib.h` eklenir).

Burada bir kavram karmaşası vardır: bu kodla n tane polinom oluşturulmuştur, ama aslında istenen bir polinomun n terimidir. `POLINOM` yapısı aslında bir terimi tutmaktadır. Hoca bunu bellek çizimiyle gösterdi: 10 elemanlı bir polinom dizisinin her elemanında derece ve katsayı alanları vardır, ama bu bir polinom değildir.

Çözüm iç içe yapıdır (nested structure): önce terim tasarlanır, sonra polinom. Her terimde katsayı ve derece vardır; polinom ise terimlerden (dinamik olarak n tane) ve terim sayısından oluşur (ekrandan, 02:50:00):

```c
typedef struct terim{
    double katsayi;
    int derece;
}TERIM;
typedef struct polinom{
    TERIM *terimler;
    int terimsayisi;
}POLINOM;
```

Böylece tek bir polinom olur; içinde terimler dizisinin adresi ve terim sayısı tutulur, terimlerin her biri derece ve katsayıdan oluşur.

Hoca aynı tasarım fikrini öğrenci örneğiyle de açıkladı. Öğrenciden bir yapı oluşturulabilir: öğrenci numarası, ad, cinsiyet gibi nitelikleri vardır. Öğrencinin ders bilgileri de tutulmak istenirse yapının içine dersin adı, vizesi, finali gibi alanları tek tek yazmak makul değildir; ders aslında ayrı bir yapıdır. Ayrı bir `ders` yapısı oluşturulup öğrencide bu türden bir işaretçi (birden fazla ders için) ya da tek değişken tutulur. Hoca, nesneye yönelik programlamanın da buradan türediğini söyledi.

> **Hocanın vurgusu:** Bir yapının hangi üyelerden oluşacağını iyi okuyup anlamak gerekir. Görmediğiniz şeyleri doğru anlayın; anlamadığınız bir şey varsa soru sormaktan çekinmeyin.

### 15.2 Slayttaki iç içe yapı örneği

Slayttaki örnekte (ekrandan, 02:30:00) bir çalışanın orduya katıldığı tarih eklenir. Tarih gün, ay, yıl gibi birden fazla parçadan oluştuğu için önce ayrı bir `DATE` yapısı tanımlanır, sonra çalışan yapısına bu türden bir üye konur:

```c
typedef struct {
    short day, month;
    int year;
} DATE ;
typedef struct {
    char name[20], surname [20];
    int  ID;
    float salary;
    DATE enlisted;
} EMPLOYEE ;
```

Slaytta bir `EMPLOYEE` değişkeni üzerinden `degisken.enlisted.year = 2008;` biçiminde erişim gösteriliyordu (slayttaki değişken adı burada genel bir adla değiştirildi). Tarih birden fazla olacaksa dizi ya da `malloc` ile dinamik yer açılan bir işaretçi kullanılır.

### 15.3 Terimleri dinamik oluşturmak ve doldurmak

Terim sayısı `N` kullanıcıdan alınır. Terim sayısı kadar polinom değil, terim sayısı kadar terim oluşturulur; bu yüzden `sizeof` içine `TERIM` yazılır ve `void*` `TERIM*`'a dönüştürülür.

**Soru:** (Hoca sordu) Açılan alan nerede tutulacak? **Cevap:** (Bir öğrenci) Polinomun terimler alanında. Hoca ekledi: yapının içine doğrudan erişilemez, önce bir polinom değişkeni (`p1`) üretilmelidir; `p1.terimler` zaten `TERIM*` türündedir.

Ekrandaki kod (ekrandan, 02:35:00):

```c
    srand(time(NULL));
    POLINOM p1; // derece ve katsayi

    int N,i;
    printf("Terim sayisini giriniz");
    scanf("%d",&N);
    p1.terimsayisi = N;
    p1.terimler = (TERIM*) malloc(N*sizeof(TERIM));
```

Döngü sınırında `N` yerine `p1.terimsayisi` kullanılması önerildi, çünkü polinomdaki terim sayısı sonradan güncellenebilir. Terimler önce rastgele dolduruldu; derslerde rastgele derece üretilince aynı dereceden terimler çıktığı için derece `i`'ye bağlandı (ekrandan, 02:40:00):

```c
    for(i=0; i<p1.terimsayisi;i++){
        p1.terimler[i].derece = i;
        p1.terimler[i].katsayi = 1+rand()%4;
    }
```

`p1` işaretçi olmadığı için nokta kullanılır: `p1`'in terimler dizisinin i. elemanının derece alanı `p1.terimler[i].derece`'dir.

### 15.4 Polinomu yazdırmak

Polinom `katsayi X ^ derece` biçiminde, terimler arasına `+` konarak yazdırıldı. İlk sürümde sonda fazladan bir `+` kalıyordu. Çözüm, döngüyü terim sayısının bir eksiğine kadar döndürüp son terimi döngüden sonra `+` olmadan yazmaktır; döngü bittiğinde `i` zaten son terimi gösterir (ekrandan, 02:40:00):

```c
    for(i=0; i<p1.terimsayisi-1;i++){
        printf("%2.2lf X ^ %d + ",p1.terimler[i].katsayi, p1.terimler[i].derece);
    }
    printf("%2.2lf X ^ %d\n",p1.terimler[i].katsayi, p1.terimler[i].derece);

    for(i=p1.terimsayisi-1; i > 0;i--){
        printf("%2.2lf X ^ %d + ",p1.terimler[i].katsayi, p1.terimler[i].derece);
    }
    printf("%2.2lf X ^ %d\n",p1.terimler[i].katsayi, p1.terimler[i].derece);
```

İkinci döngü dereceleri n, n-1, ... diye tersten yazar: `i` terim sayısının bir eksiğinden başlar, sıfırdan büyük olduğu sürece azalır, sonda 0. terim yazılır.

Hoca alıştırma olarak katsayısı sıfır olan terimin yazılmamasını istedi; matematikte de böyle terimler yazılmaz. Polinomu bu şekilde modellemenin, sayısal analizdeki kök bulma yöntemleri gibi uygulamaları kolaylaştırdığını da ekledi.

### 15.5 Polinomu kullanıcıdan okumak ve işaretçiyle erişmek

Değerler rastgele yerine elle girilmek istendi. `scanf` içinde `p1.terimler[i].katsayi`'nin adresi verilir; başka bir fark yoktur. İlk denemede katsayı `%d` ile okunduğu için değerler yanlış göründü; katsayı `double` olduğundan `%lf` kullanılması gerektiği yine fark edildi. Sonra aynı polinoma `p2 = &p1;` ile işaretçi üzerinden erişildi (ekrandan, 02:45:00):

```c
    for(i=0; i<p1.terimsayisi;i++){
        scanf("%lf",&p1.terimler[i].katsayi);
        scanf("%d",&p1.terimler[i].derece);
    }

    for(i=0; i<p1.terimsayisi-1;i++){
        printf("%2.2lf X ^ %d + ",p1.terimler[i].katsayi, p1.terimler[i].derece);
    }
    printf("%2.2lf X ^ %d\n",p1.terimler[i].katsayi, p1.terimler[i].derece);

    for(i=0; i<p2->terimsayisi-1;i++){
        printf("%2.2lf X ^ %d + ",p2->terimler[i].katsayi, (*p2).terimler[i].derece);
    }
    printf("%2.2lf X ^ %d\n",p2->terimler[i].katsayi, (*p2).terimler[i].derece);
```

`p2` işaretçi olduğu için terim sayısına `p2->terimsayisi` ile erişilir. `p2->terimler[i]` ise bir `TERIM` değişkenidir (işaretçi değil), bu yüzden katsayısına nokta ile erişilir: `p2->terimler[i].katsayi`. `scanf` ile okurken de aynı şekilde `&p2->terimler[i].derece` yazılır.

Ajan bu parçaları `stdlib.h` ve `time.h` ekleyerek tam bir programa dönüştürdü, derleyip 3 terim ve `1 1 2 2 3 3` girdisiyle çalıştırdı; iki satır da `1.00 X ^ 1 + 2.00 X ^ 2 + 3.00 X ^ 3` oldu.

### 15.6 İç içe iki ok

**Soru:** (Bir öğrenci) `p2`'nin terimlerinin derecesine iç içe iki ok ile erişilebilir mi? **Cevap:** Evet. Hoca bunu, polinomun tek bir terim tuttuğu (`malloc` kullanılmayan) bir örnekle gösterdi (ekrandan, 02:50:00):

```c
    POLINOM p1; // derece ve katsayi
    POLINOM *p2;
    p2 = &p1;

    TERIM t1;
    t1.derece=5;
    t1.katsayi=3.6;

    p1.terimler=&t1;
```

Önce terim oluşturulup "paketlenir", sonra bu paket `p1`'in terimler alanına bağlanır. İlk denemede `p1.terimler = t1;` yazıldığı için hata alındı: `t1` bir yapı, `p1.terimler` ise bir işaretçidir; `t1`'in adresi verilmelidir. Ardından `p1.terimler->derece` ile 5, `p1.terimler->katsayi` ile (`%lf` ile yazdırınca) 3.6 görüldü. `p2` üzerinden ise `p2->terimler->derece` ya da yıldız ve parantezle `(*(*p2).terimler).derece` biçiminde erişilir. Ajan bu örneği derleyip çalıştırdı; her iki yoldan da `5` ve `3.600000` yazıldı.

<!-- BELİRSİZ: Bu son printf satırlarının ekrandaki tam hali karede görülmedi; erişim ifadeleri altyazıdan kuruldu. -->

## 16. Ders Sonu Soru-Cevaplar

Hoca bir sonraki derste yapıların fonksiyonlara parametre olarak gönderilmesinin işleneceğini, bunun da yapılar konusunu tamamlayacağını söyledi. Önemli olan tasarım yapabilmektir: bir yapı içinde hangi üyeler olur, iç içe yapıya ne zaman gerek vardır.

**Soru:** (Bir öğrenci) Polinom yapısından terimler yapısına işaretçi kullanmadan erişemez miyiz? **Cevap:** Bir polinom birden fazla terimden oluşmak zorundadır, yani n tane terim olacaktır. Bu dizi ya `malloc` ile açılır ya da sabit boyutlu bir dizi olarak yazılır. Sabit dizide program çalışırken istenen terim sayısı belirlenemez; `n` girildiğinde küçük değerlerde hata çıkmayabilir, ama bir yerden sonra erişilemez. Tek bir değişken olursa her polinom tek terimli olur, o da olmaz. Mecburen `malloc` gibi bir yöntemle terimler oluşturulup başlangıç adresi işaretçide tutulur. Polinom yapısı tamamen kaldırılıp yalnız n terimlik bir dizi de tutulabilir, ama o zaman polinoma ait özellikler (terim sayısı, sabit terim, polinomun bir x değerindeki değeri gibi) terimlerin içine konamaz. Slayttaki örnekte de tarih yapısının içine maaş ya da kimlik numarası konamaz; bunlar çalışana ait niteliklerdir. Yapılar iç içe kutular gibi düşünülmelidir.

Hoca bu dersten sonra, veri yapıları ve algoritma analizi dersinde çok kullanılacak bağlı listelerin (linked list) gerçeklenmesine geçileceğini söyledi.

> **Hocanın vurgusu:** Yapıları, dinamik bellek ayırmayı bilmek ve bunları fonksiyonlarla ve dizilerle kullanabilmek bu dersin asıl gayesidir. Aklınıza bir şey takıldığında belleği kağıt üzerinde çizin: neyi nereye bağlayacağınızı, neyin dizi neyin işaretçi olduğunu çizerek çalışırsanız karıştırmazsınız.

**Soru:** (Bir öğrenci) C ile yazdığım konvolüsyon fonksiyonu doğru sonuç veriyor ama çok yavaş; MATLAB'ın kendi fonksiyonu neden çok daha hızlı? **Cevap:** Hızın nedeni algoritmanın karmaşıklığıyla anlaşılmalıdır. 5 saniyelik bir ses dosyası saniyede 44 bin örnekle 200-300 bin örnek tutar (öğrenci kendi dosyasında 40 bin örnek saydığını söyledi; hoca bunun düşük bir örnekleme frekansı olabileceğini belirtti). 40 bin çarpı 40 bin mertebesinde çarpma büyük bir maliyettir. MATLAB'ın hazır fonksiyonları ise vektörel işlem yapar (iki vektörü döngüyle eleman eleman değil, tek bir operasyonda toplayabilir) ve kodu paralelleştirir. Konvolüsyon fonksiyonunun içine bakılırsa orada da C'de görülen işlemler görülür.

Hoca ayrıca programlama dillerinin kullanım oranlarını karşılaştıran TIOBE indeksini açtı. C'nin üst sıralarda olduğunu, assembly'nin bile MATLAB'dan çok kullanıldığını, MATLAB'ın aslında bir dil değil bir paket program olduğunu söyledi. Mühendis yetiştiren bir bölümde C ve C++ gibi temel dillerin öğretilmesi gerektiğini, bu indekslerin hangi ölçütlere göre hazırlandığının araştırılmasını önerdi.

## 17. Dinamik Matris Uygulaması: Kare Olan Dikdörtgenler

Dersin son kısmında, daha önce sorulmuş iki sorunun çözümü Dev-C++'ta yapıldı. Hoca bunun bir laboratuvar uygulaması yerine geçebileceğini söyledi. Soruların metni ve tam çözümü Örnek Sorular bölümündedir; burada anlatılan genel dersler özetlenir.

### 17.1 İşaretçi dizisi ile string'ler

Birinci soruda karakter işaretçilerinden oluşan bir dizi (`char *x[5]`), bu dizinin iki elemanını tutan ikinci bir işaretçi dizisi (`char *y[]`) ve bir `char *p` vardır. Her `printf` satırında `%s`'in bir adresten başlayıp `'\0'`'a kadar yazdığı, `%c`'nin tek karakter yazdığı, işaretçi aritmetiğinin ve `++` operatörünün etkisi izlenir. Hoca `%c` yerine `%s` yazılırsa ne olacağını da gösterdi: `%s` verilen sayısal değeri (örneğin bir karakterin ASCII kodu olan 97'yi) adres sanıp o adresten okumaya çalışır, bu yüzden olmaz. Adres olan bir ifadede (`++y[1]` gibi) ise `%s` kullanılabilir: `y[1]` bir artırılınca "lanTuring1912" yazılır.

### 17.2 Dinamik matris, kareler dizisi ve bellek boşaltma

İkinci soruda N tane dikdörtgenin iki kenarı N×2'lik dinamik bir `int**` matriste tutulur. Hoca çözümü adım adım kurdu:

- `verileriOku` matrisi açar, rastgele değerlerle doldurur, kare sayısını işaretçi parametre üzerinden günceller ve matrisin adresini (`int**`) döndürür. Önce satırlar için yer açıp her satıra ayrıca yer açmayı unuttuğu için çalışma anında hata alındı. Bir öğrenci yalnız `matris[0]` ve `matris[1]` için yer açıldığını fark etti; hoca bunu `for` döngüsüyle her satıra `malloc` yaparak düzeltti.
- `kareBul`, kare olan satırların **adreslerini** tutan `int**` türünde bir dizi döndürür. Değerleri kopyalamak sağlıklı değildir; hoca bunu öğrenci bilgi sistemindeki kayıtların başka bir sisteme kopyalanarak aktarılmasına benzetti: veri kopyalanınca ikinci sistemdeki kayıt geç güncellenir, adresle tutulsaydı tek kaynak olurdu.
- `matrisYaz`, her satırı yazar ve satırın adresi kareler dizisindeki adreslerden birine eşitse yanına "Kare" yazar.
- Boşaltma: değerler matris satırlarında, kareler dizisinde ise yalnız bu satırların adresleri tutulur. Önce her satır, sonra satır işaretçileri dizisi `free` edilir; kareler dizisi için yalnız `free(kareler)` yeterlidir. Kareler dizisinin gösterdiği satırları yeniden `free` etmeye çalışmak, zaten boşaltılmış yeri ikinci kez boşaltmak olur ve hata verebilir.

Hoca sık görülen hataları sıraladı: tek işaretçi kullanıp satır adresi yerine satır indisini tutmak, `&matris[i]` gibi "adresin adresi"ni saklamak, `*` ile `&`'yi karıştırmak, fonksiyon çağrısında `int n` gibi tür yazmak. Daha verimli bir çözüm, kareleri tararken her kare bulunduğunda `realloc` ile kareler dizisini büyütmek olurdu; bu, matrisi iki kez taramayı önler. Hoca bunu Eratosthenes kalburunda bulunanların bir dizide saklanmasına benzetti.

**Soru:** (Bir öğrenci) Matrisi `free` ettikten sonra `matris = NULL;` yapmamız gerekiyor mu? **Cevap:** Zorunlu değildir. `free` işleminden sonra `matris` değişkeni hâlâ aynı bellek bölgesini gösterir; o bölge başka birine verilmemişse döngüyle eski değerler hâlâ okunabilir. Bunu önlemek için `free`'den sonra işaretçiye `NULL` atanması önerilir: işaretçi artık hiçbir yeri göstermez ve eski bölgeye yanlışlıkla erişilemez. Daha sağlıklıdır.

### 17.3 const ile adresle aktarımı korumak

Hoca dersin başındaki `const` konusuna bu çözüm üzerinde döndü. `verileriOku`'da kare sayısı adresle aktarılır: kopya çıkmaz ve fonksiyon değeri değiştirebilir. Adresle aktarılan bir parametrenin içeriği değişmesin isteniyorsa `const int *` yazılır; fonksiyon içinde `*kareSayisi = 6;` gibi bir atama derleyici tarafından reddedilir, ama değer okunabilir. `int * const kareSayisi` yazılırsa işaretçinin kendisi sabitlenir: başka bir değişkenin adresi atanamaz ("assignment of read-only parameter"), ama gösterdiği değer değiştirilebilir. İkisi birden isteniyorsa `const int * const kareSayisi` yazılır. Ekrandaki `kareBul` başlığında kare sayısı değerle gelip `const int kareSayisi` olarak sabitlenmişti (ekrandan, 03:40:00).

> **Ders sonrası not:** Derste bu kısımda da hoca bir süre yazımı karıştırdı ve bunu sonraki derste yeniden göstereceğini söyledi. Doğru eşleşme yukarıdaki gibidir ve Bölüm 4'teki gcc denemeleriyle uyumludur.

## Örnek Sorular

### Soru 1: return ile virgül (derste sözlü, 00:10:19)

Bir fonksiyonda `return 3, 8;` (ya da `return x, y;`) yazılırsa ekranda hangi değer görülür?

> **Çözüm:** Virgül operatörü en sağdaki ifadenin değerini verir; fonksiyon 8 döndürür. C hata vermez. Ajanın denemesinde (`int x=3, y=8; return x, y;`) çıktı 8 oldu; gcc `-Wall` ile yalnız uyarı verdi.

### Soru 2: Yapı işaretçisiyle scanf (derste sözlü, 02:11:19)

`POLINOM *p2 = &p1;` iken `scanf("%d", p2->derece);` yazılması doğru mudur, `&` konmalı mıdır?

> **Çözüm:** `&` konmalıdır: `scanf("%d", &p2->derece);`. `p2` bir adrestir ama `p2->derece` bir `int` değeridir. `->` operatörünün önceliği `&`'den yüksek olduğu için ifade önce derece alanına gider, sonra alanın adresini alır. `&` konmazsa kod derlenir ama değer girildiğinde program çalışma anında hata verir.

### Soru 3: İşaretçi dizisi çıktısı (ekrandan, 03:10:00 ve 03:15:00)

Aşağıdaki programın her `printf` satırı ne yazar? Hata veren satır var mıdır?

```c
#include <stdio.h>
int main( ) {
char *x[5] = {  "ElHarizmi780", "CharlesBabbage1791", "AdaLovelace1815",
"AlanTuring1912", "DennisRitchie1941" };
    char *y[] = { x[0] , x[3] };    char *p=y[0];
    printf("%s \n", (p+2));
    printf("%s \n", y[1]);
    printf("%c \n", *(*(x+3)+2));
    printf("%c \n", *(*(y+1))[4]);
    printf("%c\n", *(++y[1]));
    printf("%c\n", x[2][0]-x[1][7]+x[0][0]);
return 0;
}
```

> **Çözüm:** (derste verildi, ekrandaki açıklamalarla)
> - `p`, `y[0]`'ı yani `x[0]`'ı ("ElHarizmi780") gösterir. `p+2` iki karakter ileriyi gösterir; `%s` ile `Harizmi780` yazılır.
> - `y[1]`, `x[3]`'tür; `AlanTuring1912` yazılır.
> - `*(x+3)` = `x[3]`, `+2` ile üçüncü karaktere gidilir: `a`.
> - `*(*(y+1))[4]` hatalıdır: `[]` önceliği yüksek olduğu için `(*(y+1))[4]` önce hesaplanır ve bir `char` verir (`'T'`); bir karakterin önüne `*` konamaz, "değerin değeri" olmaz. Derleyici hata verir. Baştaki yıldız kaldırılırsa (`(*(y+1))[4]`) `AlanTuring1912`'nin 4. indeksi olan `T` yazılır.
> - `++y[1]`, `y[1]`'i bir karakter ilerletir; artık "lanTuring1912"yi gösterir. `*` ile ilk karakter alınır: `l`.
> - `x[2][0]` = `'A'` (65), `x[1][7]` = `'B'` (66, "CharlesBabbage1791"nin 7. indeksi), `x[0][0]` = `'E'` (69). 65 - 66 + 69 = 68, `%c` ile `D` yazılır.
>
> Ajan programı hatalı satır `(*(y+1))[4]` olarak düzeltilmiş haliyle derleyip çalıştırdı; çıktı sırasıyla `Harizmi780`, `AlanTuring1912`, `a`, `T`, `l`, `D` oldu. Hatalı biçim ayrıca denendi ve gcc "invalid type argument of unary '*'" hatası verdi.

> **Ders sonrası not:** Son satırı anlatırken hoca 'E' için "65, 66, 67, 70 mi oluyor? 70 oluyor herhalde", sonuç için de "69" dedi. Doğrusu `'E'` = 69 ve sonuç 65 - 66 + 69 = 68'dir; 68 de `'D'` karakteridir. Ekranda yazılan sonuç (`D`) doğrudur.

### Soru 4: Dikdörtgen verileri ve kareler (derste sözlü ve ekrandan, 03:17:24 - 03:43:43)

<!-- BELİRSİZ: Sorunun tam metni karede görülmedi; aşağıdaki metin hocanın okuduğu ve anlattığı kısımlardan kuruldu. -->

`main` içinde kullanıcıdan N alınır. N dikdörtgenin iki kenar uzunluğu N×2'lik dinamik bir tamsayı matrisinde tutulacaktır.

- (2) `verileriOku` fonksiyonunu yazıp çağırın: matris için hem yer ayırsın hem veri girişi yapsın (değerler rastgele üretilebilir), matrisin bellekteki adresini döndürsün ve matristeki kare sayısını parametre olarak geri versin.
- (3) Parametre olarak gelen dikdörtgen verileri içinde kare özelliği taşıyan verilerin bellek adreslerini döndüren `kareBul` fonksiyonunu yazıp çağırın.
- (4) Girilen tüm verileri "Kenar-1, Kenar-2, Ek Bilgi" biçiminde ekrana yazan fonksiyonu yazın; kare olan satırların yanına "Kare" yazılsın.
- (5) Dinamik olarak oluşturulan matrisi temizleyen fonksiyonu yazın ve çağrısını yapın; tüm dinamik alanları boşaltın.

> **Çözüm:** (derste verildi; ekrandaki parçalar 03:35:00, 03:40:00 ve 03:45:00 karelerinden birleştirildi)
>
> Ekranda `main`'deki `int kareSayisi;` ilk değer almadan `verileriOku` içinde `(*kareSayisi)++` ile artırılıyordu; aşağıda `0` ile başlatıldı. Ekrandaki `kareBul`'un bir sürümünde `kareler` tek işaretçi (`int *`) olarak tanımlanmıştı ve derleyici iki uyarı verdi ("assignment makes integer from pointer without a cast", "return from incompatible pointer type"); hoca bunu sık yapılan hatalardan biri olarak gösterdi. Aşağıda hocanın anlattığı doğru hali (`int **`) kullanıldı. `temizle` fonksiyonunun ve satır `malloc` döngüsünün tam hali karede görülmedi, hocanın anlatımından yazıldı. Ajan programı derleyip N = 6 ile çalıştırdı; uyarısız derlendi ve kare olan satırın yanında "Kare" yazdı.

```c
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int** verileriOku(int N, int* kareSayisi);
int** kareBul(int** matris, int N, const int kareSayisi);
void matrisYaz(int **matris, int N, int **kareler, int kareSayisi);
void temizle(int **matris, int N);

int main(){
    int N;
    int kareSayisi = 0;
    int **matris, **kareler;
    srand(time(NULL));
    scanf("%d",&N);
    matris = verileriOku(N, &kareSayisi);
    kareler = kareBul(matris, N, kareSayisi);
    matrisYaz(matris, N, kareler, kareSayisi);
    temizle(matris, N);
    free(kareler);
    return 0;
}

int** verileriOku(int N, int* kareSayisi){
    int i;
    int **matris=(int**) malloc(N*sizeof(int*));
    for(i=0;i<N;i++)
        matris[i]=(int*) malloc(2*sizeof(int));
    for(i=0;i<N;i++){
        matris[i][0] = rand()%5+1;
        matris[i][1] = rand()%5+1;
        if(matris[i][0]==matris[i][1])
            (*kareSayisi)++;
    }
    return matris;
}

int** kareBul(int** matris, int N, const int kareSayisi){
    int i, j=0;
    int **kareler=(int**) malloc(kareSayisi*sizeof(int*));
    for(i=0;i<N;i++){
        if(matris[i][0]==matris[i][1]){
            kareler[j] = matris[i];
            j++;
        }
    }
    return kareler;
}

void matrisYaz(int **matris, int N, int **kareler, int kareSayisi){
    int i,k;
    printf("Kenar-1\tKenar-2\tEk Bilgi[Toplam Kare=%d]\n",kareSayisi);
    for(i=0;i<N;i++){
        printf("%3d\t%3d",matris[i][0],matris[i][1]);
        for(k=0;k<kareSayisi;k++)
            if(matris[i]==kareler[k])
                printf("\tKare");
        printf("\n");
    }
}

void temizle(int **matris, int N){
    int i;
    for(i=0;i<N;i++)
        free(matris[i]);
    free(matris);
}
```

> Hocanın anlattığı kabul edilebilir varyasyonlar: kare sayısı işaretçi yerine değerle de gönderilebilir (değişmemesi isteniyorsa `const` yazmak iyi olur); `verileriOku` matrisi parametre olarak da alabilir; `kareBul` `void` olup sonucu parametreyle de verebilir; satır yazdırmada iki sütun için ayrı bir `j` döngüsü de kullanılabilir.

### Soru 5: Seyrek matrisi sıkıştırma (derste sözlü, 01:13:13)

Bir matrisi alıp sıfırdan farklı elemanlarını (satır, sütun, değer) üçlüleriyle k×3'lük yeni bir yapıda tutan `compress` fonksiyonunu yazın.

> **Çözüm (derste verilmedi):** Ajan tarafından yazıldı, derlendi ve 4×4'lük, üç sıfırdan farklı elemanı olan bir matrisle çalıştırıldı (çıktı `0 2 1`, `2 3 10`, `3 0 1`).

```c
#include <stdio.h>
#include <stdlib.h>
/* matris: n x m, dondurulen: k x 3 (satir, sutun, deger) */
int** compress(int **matris, int n, int m, int *k){
    int i, j, say = 0, t = 0;
    int **sik;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(matris[i][j] != 0) say++;
    sik = (int**) malloc(say*sizeof(int*));
    for(i=0;i<say;i++)
        sik[i] = (int*) malloc(3*sizeof(int));
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(matris[i][j] != 0){
                sik[t][0] = i; sik[t][1] = j; sik[t][2] = matris[i][j];
                t++;
            }
    *k = say;
    return sik;
}
```

## Dersin Toparlaması

Ders iki büyük parçadan oluştu. İlk parçada fonksiyonlar konusu tamamlandı: değerle ve adresle aktarımın farkı, fonksiyondan tek değer döndüğü ve birden fazla sonuç için işaretçi kullanıldığı, `const`'un işaretçiyle birlikte nereye yazıldığına göre neyi sabitlediği, yerel değişkenlerin stack'te, `malloc` alanlarının heap'te durduğu ve yerel değişken adresi döndürmenin neden hatalı olduğu görüldü. Dizilerin fonksiyona adres olarak gittiği, fonksiyondan dizi döndürmek için `malloc` kullanılması gerektiği, seyrek matrisin üçlülerle sıkıştırılabileceği ve `main`'e `argc`/`argv` ile komut satırından argüman gönderilebileceği anlatıldı.

İkinci parçada yapılara geçildi. Yapıların soyutlama aracı olduğu, `typedef` ile tanımlanma biçimleri, nokta ve ok operatörleriyle erişim, `scanf`'te üye adresinin alınması ve operatör önceliği gösterildi. Polinom örneğiyle terim ve polinom kavramlarının ayrılması ve iç içe yapının dinamik bir terim dizisiyle kurulması işlendi. Son olarak dinamik `int**` matris, adres tutan ikinci bir işaretçi dizisi ve doğru sırayla bellek boşaltma üzerine bir uygulama sorusu çözüldü. Bir sonraki derste yapıların fonksiyonlara parametre olarak gönderilmesi, ardından bağlı listelerin gerçeklenmesi işlenecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
