# Ders 8 Genişletilmiş Notu: Fonksiyonlara Parametre Aktarımı, Dizi Döndürme, main Parametreleri ve Struct'a Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Fonksiyonlara parametre aktarımı: değer ile ve referans ile çağrı
- 2. Fonksiyon tanımı, ön bildirimi ve çağrısı
- 3. Takas fonksiyonu ve küçük fonksiyon örnekleri
- 4. Dizileri fonksiyona parametre olarak vermek
- 5. Fonksiyondan dizi döndürmek
- 6. main fonksiyonunun parametreleri
- 7. Struct yapısına giriş
- 8. Bağlı liste veri yapısına giriş
- Örnek Sorular
- Dersin Toparlaması

## 1. Fonksiyonlara parametre aktarımı: değer ile ve referans ile çağrı

Dersin ilk konusu, bir fonksiyona argüman olarak verilen değişkende fonksiyon içinde yapılan değişikliğin fonksiyon bittikten sonra kalıcı olup olmadığıdır. C iki yol sunar: değer ile gönderim (pass by value, call by value) ve referans ile gönderim (pass by reference, call by reference). İki çalışma biçiminin de farklı senaryolarda işe yaradığını, bu yüzden programcıya bu denetimin verildiğini söyleyen hoca, konuyu doğrudan bir kod üzerinden anlattı.

### 1.1 Gösterim kodu

Slayttaki kod şudur (ekrandan, 00:10:00):

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
    system("PAUSE"); return(0);
}
```

İki fonksiyonun gövdesi neredeyse aynıdır, fark ilk parametrededir. `increaseRegular` ilk parametreyi sıradan bir tam sayı olarak alır ve onu ikinci parametre kadar artırır. `increasePointer` ise ilk parametreyi işaretçi olarak alır ve işaretçinin gösterdiği adresteki değeri artırır.

`main` içinde `a` ve `b` sıradan (ilkel) değişkenlerdir. `increaseRegular(a, b)` normal bir çağrıdır. `increasePointer` ise işaretçi beklediği için ona `a`'nın adresi verilir: `increasePointer(&a, b)`. Hoca bunu "aradaki en önemli eşleşme kuralı" diye vurguladı. Bir işaretçiye değişken atarken `int *p = &a;` yazıyorduk. Parametre işaretçi olarak tanımlanınca da ona aynı mantıkla bir adres verilir.

### 1.2 Çıktının adım adım açıklaması

- `increaseRegular(a, b)` çağrısında `aa` parametresine `a`'nın değeri olan 3 kopyalanır. `aa += bb` ile `aa` 8 olur ve fonksiyon "increaseRegular finishes with 8" yazar.
- Fonksiyondan dönünce `main` "main says the value is 3" yazar. Artış olmuştur, fonksiyon bunu 8 yazarak gösterir. Ancak değişen yalnız kopyadır, `a` çağrıdan önceki değerinde kalır.
- `increasePointer(&a, b)` çağrısında `aa`, `a`'nın bellekteki adresini tutar. `*aa += bb` o adresteki 3 değerini 8 yapar. Fonksiyon "increasePointer finishes with 8" yazar.
- Dönüşte `main` de "main says the value is 8" yazar. Değişiklik kalıcıdır.

İlk çağrı değer ile çağrıdır, değişiklik kalıcı olmaz. İkinci çağrı işaretçi üzerinden, yani referans ile çağrıdır, değişiklik kalıcı olur. Kod derste çalıştırıldı ve çıktı tam bu şekilde geldi. Ajan da kodu `gcc -Wall` ile derleyip (`system("PAUSE")` satırı olmadan) aynı çıktıyı aldı:

```text
increaseRegular finishes with 8
main says the value is 3
increasePointer finishes with 8
main says the value is 8
```

> **Hocanın vurgusu:** Değer ile çağrı ve referans ile çağrı farkı bu bölümün en önemli ayrıntısıdır. Kodu satır satır yürütürken hangi çağrıda değişkenin değiştiğine dikkat etmek gerekir.

## 2. Fonksiyon tanımı, ön bildirimi ve çağrısı

### 2.1 İmza ve tanım

Fonksiyonun imzası ilk satırıdır: geri dönüş türü, fonksiyonun adı, kaç parametre aldığı ve her parametrenin türü. Tanım (definition) daha geniştir: imza ile gövdenin birlikte halidir. Slaytta tanım, fonksiyonun ne yaptığını, argümanların sayısını ve türünü belirleyen kısım olarak verildi (ekrandan, 00:15:00).

### 2.2 Fonksiyon çağrısı ve program sayacı

Slayttaki tanıma göre fonksiyon çağrısı yürütmenin çağrılan fonksiyona atlamasına yol açar. Fonksiyon dönünce yürütme çağrının hemen sonrasındaki noktadan sürer (ekrandan, 00:15:00). Hoca bunu makine düzeyinde açıkladı. C derlenen bir dildir, program makine diline çevrilir. Program ve veri bellekte aynı ortamda saklanır. İşlemcideki program sayacı (program counter) sıradaki komutun bellekteki yerini gösterir. Çağrı anında program sayacı, çağrılan fonksiyonun bellekte tanımlandığı adrese gider. Fonksiyon bitince denetim akışı çağrının hemen sonrasındaki komuttan sürer.

Hoca bunun için "sonraki satır" demediğini özellikle belirtti. Örneğin bir fonksiyonun döndürdüğü değer bir değişkene atanıyorsa, önce eşittirin sağındaki çağrı değerlendirilir, sonra aynı satırdaki atama yapılır. Programcı açısından "şu satırdayken çağrı oldu, şu satıra geçildi" diye düşünmekte de bir sakınca yoktur.

### 2.3 Ön bildirim (allusion)

Fonksiyon kullanılmadan önce bildirilmiş olmalıdır. Fonksiyon başka bir `.c` dosyasında tanımlıysa `extern` anahtar kelimesiyle bildirilir. Derste bütün örnekler tek dosyada yapıldığı için `extern` kullanılmadı.

Ön bildirimlerde parametrelerin yalnız türü yazılabilir, adları gerekmez. Önemli olan parametrenin türüdür. `int a` yerine `int b` ya da `int c` yazmak bir şey değiştirmez, ad programcının verdiği sembolik bir isimdir. Adları yazmak da sorun değildir. Parametre almayan bir fonksiyonda parantez içine `void` yazmak isteğe bağlıdır, derleyici özellikle istemedikçe boş bırakılabilir.

### 2.4 Faktöriyel örneği ve taşma

Slaytta bir faktöriyel fonksiyonu gösterildi. Kod basit bir kümülatif çarpımdır. Hoca burada taşmaya dikkat çekti. `int` 4 bayttır ve yaklaşık ±2 milyara kadar değer tutar. Faktöriyel çok hızlı büyüdüğü için bu sınıra çok küçük sayılarda ulaşılır.

> **Ek bilgi (derste anlatılmadı):** 32 bitlik `int` en çok $2^{31}-1 = 2\,147\,483\,647$ değerini tutar. $12! = 479\,001\,600$ bu sınırın altında, $13! = 6\,227\,020\,800$ ise üstündedir. Bu yüzden `int` ile faktöriyel en çok $12!$'e kadar doğru hesaplanır.

### 2.5 Çağrı sözdizimi

Fonksiyon çağrılırken adı yazılır, parantez içinde her parametreye karşılık gelen argüman verilir, birden fazla argüman virgülle ayrılır. Hoca bu kısmı bilinen konular olduğu için hızlı geçti.

## 3. Takas fonksiyonu ve küçük fonksiyon örnekleri

### 3.1 Karakterin harf olup olmadığı

İlk küçük örnek, verilen bir karakterin alfabetik olup olmadığını denetleyen bir fonksiyondur. Önceki haftalarda büyük-küçük harf dönüşümünde ve yalnız harfleri yazdırma örneğinde benzer denetim yapılmıştı. Bu kez iş tek bir fonksiyona taşınır. C'de yerleşik `true`/`false` mantıksal türü olmadığından fonksiyon harf ise 1, değilse 0 döndürebilir. Çözümü Örnek Sorular bölümündedir.

### 3.2 Takas (swap)

Sıralama yaparken iki değişkenin değerini değiştiren fonksiyonlar çok kullanılır. Slayttaki istek, iki tam sayı parametresinin değerlerini takas eden bir fonksiyon yazmaktır. Fonksiyon dönünce `a`'nın değeri `b`'de, `b`'nin değeri `a`'da olmalıdır. Slayt geçici değişkenle takası hatırlatır: `tmp = a; a = b; b = tmp;` (ekrandan, 00:20:00).

Hoca burada öğrencilere slaytta yazmayan çok önemli ayrıntının ne olduğunu sordu ve cevabı kendisi verdi. Yapılan değişikliğin kalıcı olması gerekir. Bu yüzden fonksiyon referans ile çağrı kullanmalı, `a` ve `b` parametreleri işaretçi olarak tanımlanmalıdır. Takas edilecek şeyler zaten işaretçiyse adları doğrudan verilir. Sıradan değişkense başlarına `&` (adres operatörü) konur.

> **Hocanın vurgusu:** Takası ilkel değişkenler, işaretçiler ve dizi elemanları için ayrı ayrı deneyin. Takastan önce ve sonra değerleri (dizi ise diziyi) yazdırıp takasın gerçekten yapılıp yapılmadığına bakın.

## 4. Dizileri fonksiyona parametre olarak vermek

### 4.1 Neden ve nasıl

Takas örneğinde dizinin yalnız iki elemanı ayrı parametreler olarak verilecekti. Şimdi bütün dizinin parametre olarak verilmesi konuşuldu. Bu, örneğin bir diziyi sıralayan ya da bütün diziyi yazdıran bir fonksiyon için gerekir. Önceki haftalarda dizinin başını gösteren bir işaretçi verilip bu işaretçi ilerletilerek elemanlar dolaşılmıştı. Aynı mantık sürer ama daha fazla şey yapılabilir.

Slayt şu uyarıları ve yöntemleri sıralar (ekrandan, 00:25:00):

- Sınır denetimi yoktur. Derleyici dizinin eleman sayısını kendiliğinden bilmez.
- Fonksiyon yazmanın amacını unutmamak gerekir.
- Gerçek boyutu kullanmak: `void printArray( int ar[5] )`. Pek kullanışlı değildir: farklı boylarda dizi yazdırmak gerekirse ne olacak?
- Dizi ve boyut parametresi: `void printArray( int ar[], int size )`. Önceki yöntemden daha kullanışlıdır.
- İşaretçi ve tam sayı: `void myFunction( int *ar, int size )`. Bu da kullanışlıdır.

Hoca sabit kapasite yönteminin esnek olmadığını şöyle anlattı: 5 elemanlık diziyi yazdıran fonksiyon 10 elemanlık diziyi yazdıramaz, 10 ve 15 eleman için ayrı fonksiyonlar yazmak saçma olur. `#define SIZE 5` gibi bir tanım da günü kurtarmaz. Esnek yol, diziyle birlikte eleman sayısını da göndermektir. String'lerde sondaki boş karakter (`'\0'`) dizinin sonunu gösterdiği için eleman sayısını göndermek gerekmez. Diğer bütün durumlarda eleman sayısı ikinci parametre olarak verilmelidir.

### 4.2 Dizi boyutunu bulan makro

Hoca bir ipucu olarak her türden dizinin eleman sayısını bulan bir makro verdi (ekrandan, 00:30:00):

```c
#define SIZE_OF_ARRAY(x) (sizeof(x) / sizeof((x)[0]))
```

Makro `#define` ile başlar, ardından makronun adı (`SIZE_OF_ARRAY`) ve parametresi (`x`) gelir. Makroda parametrenin türü yazılmaz. Bu bir esnekliktir, çünkü tek makro farklı türlerle çalışır. Ama bir dezavantajdır da: tür denetimi olmadığı için, örneğin tam sayı yerine ondalıklı sayı verildiğinde normalde alınacak uyarılar alınmaz ve olası hatalar önceden görülemez. Makronun gövdesi bir çift normal parantez içinde yazılmalıdır. Mantığı basittir: dizinin kapladığı toplam bayt sayısı bir elemanın kapladığı bayt sayısına bölünür. Makro ile fonksiyonun birbirine göre avantaj ve dezavantajları ilerideki bir konu olarak bırakıldı.

Slayt makronun sınırını da belirtir. Fonksiyona parametre olarak gönderilen dizi işaretçi gibi ele alınır, bu yüzden `sizeof` dizinin değil işaretçinin boyutunu döndürür. Fonksiyonların içinde bu makro çalışmaz. Makro, diziyi parametre olarak göndermediğiniz, dizinin tanımlandığı yerde (`main` ya da başka bir fonksiyon) çalışır. Hoca bunun pratikte büyük bir eksik olmadığını da söyledi. Diziye kaç eleman girileceği genelde kullanıcıya sorulur. Döngüyle eleman alınıyorsa bir sayaç tutulur. Dinamik bellek kullanılıyorsa kapasite zaten bilinir. Başka bir programın diske yazdığı veriden eleman sayısı bulunacaksa, eleman sayısı önceden diske yazılabilir.

### 4.3 Makronun denenmesi

Derste IDE'de şu kod yazıldı (ekrandan, 00:35:00):

```c
#include <stdio.h>
#define SIZE_OF_ARRAY(x) (sizeof(x) / sizeof((x)[0]))
int findSize( int dizi[] ) {
    return SIZE_OF_ARRAY(dizi);
}
int main() {
    int n=5;
    int dizi[5];
    printf("main  says the size is %d\n", sizeof(dizi) / sizeof((dizi)[0]) );
    printf("macro says the size is %d\n", SIZE_OF_ARRAY(dizi));
    system("PAUSE"); return(0);
}
```

Dizinin elemanlarına değer vermek gerekmez, çünkü yalnız boyut ölçülür. Hem `main` içindeki elle yazılan ifade hem makro 5 yazdı. <!-- BELİRSİZ: findSize fonksiyonunun derste çağrılıp çağrılmadığı ve ne yazdığı altyazıdan ve karelerden çıkmıyor. -->

Sonra aynı deneme dinamik bellekle yapıldı. 8 elemanlık alan `calloc` ile ayrılıp `int *alan` işaretçisine atandı. Hoca `malloc` ya da `calloc` ile yer ayrılamamış olabileceğini, bu yüzden `NULL` denetimi yapılması gerektiğini hatırlattı. Bu kez makro `main` içinde bile 8 değil 1 yazdı. Hoca ders notunda "başka fonksiyondan çağrıldığında çalışmaz" yazdığını, bunu "çalışmayabilir" diye okumak gerektiğini, sonucun derleyiciye ve platforma göre değişebileceğini söyledi.

> **Ders sonrası not:** Hoca bu sonucu "anlattığımdan biraz farklı" diye yorumladı. Sonuç aslında beklenen davranıştır. `alan` bir dizi değil işaretçidir, `sizeof(alan)` `main` içinde de işaretçinin boyutunu verir. Makro yalnız gerçek dizi değişkeninde, dizinin tanımlandığı yerde doğru sonuç verir. Derste kullanılan derleyici büyük olasılıkla 32 bitlik kod üretiyordu: işaretçi 4, `int` 4 bayt olduğu için sonuç 1 çıktı. Ajanın 64 bitlik gcc ile denemesinde aynı ifade de, `findSize` de 2 verdi. gcc `-Wall` bu iki kullanım için uyarı verir (`-Wsizeof-pointer-div`, `-Wsizeof-array-argument`).

Aradan sonra hoca `calloc`'un parametre sırasına döndü: ilki eleman sayısı, ikincisi eleman boyutudur. Önce `calloc` tek argümanla (`8*sizeof(int)`) yazılmıştı ve derleyici eksik argüman hatası vermemişti. Doğru biçim `calloc(8, sizeof(int))` ile ve `malloc` ile de denendi, sonuç yine 1 oldu. Hoca ANSI standardındaki tanıma rağmen derleyicilerin aynı fonksiyonun farklı sürümlerini barındırabildiğini düşündü. <!-- BELİRSİZ: Tek argümanlı calloc çağrısının neden derlendiği derste netleşmedi; ANSI C'de calloc iki argüman alır. Prototipi görmeyen eski bir derleyici örtük bildirimle derlemiş olabilir. -->

> **Ek bilgi (derste anlatılmadı):** `calloc(n, boyut)` `n` elemanlık alanı ayırır ve bütün baytları sıfırlar. `malloc(n*boyut)` ise alanı sıfırlamadan ayırır. İkisi de başarısız olursa `NULL` döndürür.

## 5. Fonksiyondan dizi döndürmek

### 5.1 Ne zaman gerekir?

Hoca birkaç senaryo verdi: elemanların değerlerini kullanıcıdan alan fonksiyonun onları saklayacak diziyi de oluşturup döndürmesi, vektör ve matris hesapları, iki dizinin elemanlarını birleştirip tekrar edenleri eleyerek yeni dizi döndürmek. Matris çarpımında en doğal yol, A ve B matrislerini parametre olarak alıp çarpım matrisi C'yi döndürmektir. Sonuç dizisini üçüncü parametre olarak vermek de bir yoldur ve ileride görülecektir.

### 5.2 Kural: işaretçi döndürülür, yerel dizi döndürülemez

Slayttaki kurallar şunlardır (ekrandan, 00:55:00):

- Fonksiyondan dizi döndürülmez, döndürülecek dizinin başlangıç adresini tutan işaretçi döndürülür.
- Dizinin fonksiyon bittikten sonra da var olduğundan emin olunmalıdır. Yerel diziler döndürülemez.
- Çözüm dinamik bellek ayırmadır.

Fonksiyon içinde tanımlanan bütün değişkenler yalnız o fonksiyonun bağlamında geçerlidir. Fonksiyon bitince geçici değişkenler ve geçici alanlar geçersiz olur. Fonksiyon içinde tanımlanmış bir diziyi döndürmeye çalışırsak, dizinin alanı fonksiyon bitince erişilemez hale gelir ve veri kaybolur. `malloc` ya da `calloc` ile ayrılan alanlar ise fonksiyon biterken silinmez. Adresleri bir yere aktarılmışsa erişilebilir ve kullanılabilir kalırlar.

### 5.3 Birinci sürüm: concatArraysV1

Slayttaki istek: iki dizi alan ve onların uç uca eklenmiş halini döndüren bir fonksiyon yazınız (ekrandan, 01:00:00). Tekrar eden eleman denetimi yapılmaz, odak dizi döndürmektir. Fonksiyon dizilerin eleman sayılarını da alır, çünkü makronun çalışmadığı durumlar vardır. IDE'deki son hali, hocanın sonradan eklediği `NULL` denetimiyle birlikte şöyledir (ekrandan, 01:10:00):

```c
int* concatArraysV1( int arr1[], int size1, int arr2[], int size2 ) {
    int *merged = (int*) malloc( (size1+size2)*sizeof(int) );
    int i;
    if( merged == NULL ) { printf("out of memory!"); exit(1); }
    for( i=0; i<size1; i++ )
        merged[i] = arr1[i];
    for( ; i<size1+size2; i++ )
        merged[i] = arr2[i-size1];
    return merged;
}
```

Adım adım:

- İki kapasitenin toplamı kadar `int` saklayacak alan `malloc` ile ayrılır, başlangıç adresi `merged` işaretçisinde tutulur.
- İlk döngü birinci dizinin bütün elemanlarını yeni alana kopyalar.
- İkinci döngünün başlangıç ifadesi boştur. `i` fonksiyonun başında tanımlandığı için ilk döngü bittiğinde zaten istenen değerdedir. C'de `for` başlığındaki ifadeler boş bırakılabilir.
- İkinci dizinin elemanları `merged`'in `size1` konumundan itibaren yazılır, ama `arr2` sıfırdan okunmalıdır. Bu yüzden indis `i-size1`'dir. Hocanın örneğinde birinci dizide 5, ikincide 3 eleman vardır. `merged`'in 0-4 konumları dolar. `i=5` için `arr2[5-5] = arr2[0]`, `i=6` için `arr2[1]` okunur.
- `merged` döndürülür.

`NULL` denetiminde `return` yerine `exit(1)` kullanıldı. Fonksiyon bir işaretçi döndürmek zorundadır, hata durumunda program hata koduyla sonlandırılır. `exit` için `stdlib.h` eklendi. Derlemede değişken tanımlarının komutlardan önce gelmesi gerektiği için bir düzeltme de yapıldı.

Sonuçları yazdırmak için bir `printArray` fonksiyonu yazıldı (ekrandan, 01:10:00):

```c
void printArray( int a1[], int size ) {
    int i;
    for( i=0; i<size; i++ )
        printf("%d\t", a1[i]);
    printf("\n");
}
```

`main` içinde diziler ve çağrı şöyledir (ekrandan, 01:05:00):

```c
int arr1[] = {1,5,7,19}, arr2[] = {2,6,8,11,28};
int *ptrM = concatArraysV1(
    arr1, SIZE_OF_ARRAY(arr1), arr2, SIZE_OF_ARRAY(arr2));
```

Birinci dizi, ikinci dizi ve birleşik dizi yazdırıldı, sonunda `free(ptrM)` yapıldı. Çıktıda birleşik dizi `1 5 7 19 2 6 8 11 28` oldu. Hoca hiçbir elemanın atlanmadığını, olmayan bir elemanın ya da rastgele bellekten gelen bir değerin yazılmadığını belirtti. Hoca, `int *ptrM` bildirimi ayrı satırda yapılsaydı atamanın yıldızsız `ptrM = concatArraysV1(...)` biçiminde yazılacağını da hatırlattı.

Slayttaki vurgulu satırlar parametre aktarımının izini gösterir: `main`'de tanımlanan diziler parametre olarak gider, fonksiyonda işaretçi tanımlanıp alan ayrılır, alanın başlangıcını gösteren işaretçi döndürülür ve `main`'deki `ptrM`'ye aktarılır. `merged` sıradan bir dizi olsaydı veri kaybolurdu.

> **Hocanın vurgusu:** `malloc` ile ayrılan alanın işi bitince `free` yapılmalıdır. Alanın ayrılıp ayrılamadığı da denetlenmelidir.

### 5.4 İkinci sürüm: concatArraysV2

Alternatif yaklaşımda çağıran fonksiyon (burada `main`, ama herhangi bir fonksiyon olabilir) sonuç dizisini tanımlar. Çağrılan fonksiyon yalnız elemanları doldurur. Fonksiyonun geri dönüş türü `void` olur, alışveriş yalnız parametreler üzerinden yapılır. Hoca, `concatArraysV2`'nin gövdesinin V1 ile neredeyse aynı olduğunu, farkın üçüncü dizi parametresi ile işaretçi tanımlama ve bellek ayırma işinin kalkması olduğunu söyledi. `main` kısmı şöyledir (ekrandan, 01:15:00):

```c
int main() {
    int arr1[] = {1,5,7,19}, arr2[] = {2,6,8,11,28};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    int size3 = size1+size2;
    int arr3[size3];
    printf("Array 1 is:\t");
    printArray(arr1, SIZE_OF_ARRAY(arr1));
    printf("Array 2 is:\t");
    printArray(arr2, SIZE_OF_ARRAY(arr2));
    printf("Array 3 is:\t");
    concatArraysV2( arr1, size1, arr2, size2, arr3 );
    printArray(arr3,size3);
    system("PAUSE"); return(0);
}
```

Fonksiyonun gövdesi karelerde görünmedi. Hocanın anlatımına göre kurulan ve ajanın derleyip denediği gövde şudur (ara adım eklendi):

```c
void concatArraysV2( int arr1[], int size1, int arr2[], int size2, int arr3[] ) {
    int i;
    for( i=0; i<size1; i++ )
        arr3[i] = arr1[i];
    for( ; i<size1+size2; i++ )
        arr3[i] = arr2[i-size1];
}
```

Çıktı yine `1 5 7 19 2 6 8 11 28` oldu. Bu sürümde `free` gerekmez, çünkü dinamik bellek kullanılmadı. `size3` fonksiyona gönderilmez, çünkü `size1` ve `size2`'den hesaplanabilir. Bellek ayrılan yer çağıran fonksiyon (`main`), doldurma işini yapan yer çağrılan fonksiyondur. Hoca boyutları makroyla mı, elle mi hesaplamanın daha iyi olduğu kararını öğrencilere bıraktı.

**Soru:** Sonuç dizisi kapasite verilmeden `int arr3[];` diye tanımlanabilir mi? **Cevap:** Hoca bunu derste denedi, derleyici boyutu verilmemiş dizi tanımına izin vermedi. Fonksiyon parametresinde `int arr3[]` yazılabilir, ama değişken tanımında dizi için bellekte yer ayrılması gerekir. Hoca derleyicinin buna izin vermemesini doğru buldu.

## 6. main fonksiyonunun parametreleri

### 6.1 argc ve argv

Bir program çalıştırılırken ona boşluklarla ayrılmış ek bilgiler verilebilir. Bu bilgilere `main`'in parametreleriyle erişilir. Slayta göre derleyici `main`'i diğer fonksiyonlar gibi ele alır, farkı çalışma anında iki argümanı ortamın sağlamasıdır (ekrandan, 01:25:00):

- `argc` (argument count): komut satırında verilen argüman sayısı.
- `argv`: komut satırı argümanlarına işaretçilerden oluşan dizi, yani her biri bir string olan karakter dizisi işaretçileri.

Komut satırına `uygulama param1 param2` yazılırsa `argc` 3 olur, çünkü programın adı da sayılır. `argv[0]` program adını, `argv[1]` ilk parametreyi, `argv[2]` ikinci parametreyi tutar. Bu yüzden argümanlar işlenirken 0. eleman atlanır ve 1'den başlanır.

Hocanın verdiği kullanım örneği: kodda hata ayıklama için çok sayıda `printf` vardır, ama bunlar yalnız hata ayıklama modunda görülmek istenir. Program `uygulama debug` diye çalıştırılır. Kod `argc`'nin 2 olup olmadığına ve `argv[1]`'in "debug" olup olmadığına bakar. Öyleyse ek çıktıları yazar, değilse yazmaz.

### 6.2 Slayttaki kod ve sade sürümü

Slayttaki kod verilen bütün parametreleri yazdırır (ekrandan, 01:25:00):

```c
int main(int argc, char *argv[]) {
    while(--argc > 0)
        printf("%s\n", *++argv);
    exit(0);
}
```

Önek gösterimi kullanılır. `--argc` her turda kalan argüman sayısını bir azaltır ve daha argüman kalıp kalmadığını denetler. `*++argv` önce işaretçiyi bir sonraki argümana ilerletir, sonra onu yazdırır, böylece program adı atlanır. Hoca bunu "biraz artistik bir kontrol" diye niteledi ve daha basit bir sürüm yazdı (ekrandan, 01:30:00):

```c
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int i;
    for( i=0; i<argc; i++ )
        printf("%s\n", argv[i]);
    exit(0);
}
```

Bu parametreleri vermenin tek yolu programı komut satırından çalıştırmaktır. IDE'ler varsayılan argüman tanımlamaya izin verebilir, ama hoca bunu denemediğini, elle yazmanın daha kolay geldiğini söyledi. Program derlendikten sonra komut satırında `program 1 2 3 4` gibi çalıştırıldı. İlk sürüm `1 2 3 4` değerlerini alt alta yazdı. Sade sürüm program adını da yazdı, bu da `argv[0]`'ın çalıştırılabilir dosyanın adı olduğunu gösterdi. Ajanın denemesinde de iki sürüm aynı argümanları yazdı, sade sürüm ek olarak program adını yazdı.

Hoca komut satırı için iki kısayol da gösterdi. Dosya gezgininin adres çubuğuna `cmd` yazınca komut satırı doğrudan o dizinde açılır. Komut satırında yukarı ok tuşu son yazılan komutu geri getirir, böylece komut baştan yazılmadan düzeltilebilir. `cd` ile dizin değiştirirken ilk birkaç harf yazılıp sekme (Tab) tuşuyla tamamlanabilir.

### 6.3 Ad-değer biçiminde argümanlar

Bazı programlarda argümanlar anlam taşıyan ad-değer çiftleri olarak, herhangi bir sırada verilir. Hocanın örneği matris işlemleridir: birinci matrisin satır ve sütun sayısı, ikinci matrisin satır ve sütun sayısı (`mat1row=...`, `mat1col=3`, `mat2row=3`, `mat2col=8` gibi). Çarpım için birinci matrisin sütun sayısı ikincinin satır sayısına eşit olmalıdır. Bu tür argümanları ayrıştırmak için bir yöntem vardır, ama hocanın söylediğine göre Windows ortamında çalışmaz, Linux'ta GNU C derleyicisiyle düzgün çalışır. Uygulamalı gösterilemeyeceği için slayt yalnız kaynak olarak bırakıldı.

> **Ek bilgi (derste anlatılmadı):** Bu iş için POSIX sistemlerde `unistd.h` içindeki `getopt` ve GNU'nun `getopt_long` fonksiyonları kullanılır (büyük olasılıkla slaytta anılan yöntem budur). Bu fonksiyonlar `-a 3` ya da `--satir=3` gibi seçenekleri sıradan bağımsız olarak ayrıştırır.

## 7. Struct yapısına giriş

### 7.1 Neden struct?

Ders, aradan sonra yapılar (structure) ve birleşimlerle (union) sürdü (ekrandan, 02:05:00). Şimdiye kadar hep tek türden verilerle çalışıldı: tam sayılar için tam sayı değişkenleri, aynı türden çok sayıda veri için diziler ya da dinamik bellek. Oysa kod gerçek dünya problemlerini çözmek, izlemek, raporlamak ve yönetmek için yazılır. Gerçek dünyadaki varlıkların koda aktarılmasına modelleme denir. Gerçek dünyada yalnız sayılarla ya da karakterlerle değil, varlıklar ve onların verileriyle uğraşılır. Örneğin bir öğrenci otomasyon sisteminde öğrencinin adı, kimlik numarası, kayıt tarihi, sınıfı, dönemi ve aldığı dersler tutulur. Struct, bir varlıkla ilgili verilerin tümünü tek bir kayıt yapısında saklamayı sağlar.

Struct'lar iç içe de tanımlanabilir. Otomasyon sisteminde öğrenci, öğretmen ve idari personel gibi kişiler olur, kişilerin doğum tarihleri de tutulmak istenir. Doğum tarihi gün, ay ve yıldan oluşan tek bir yapıdır. Kişi struct'ında üç ayrı alan tanımlamak yerine bir tarih struct'ı tutulabilir.

Bu bölümün planı: struct tanımı, iç içe struct, struct dizileri, struct'ları fonksiyona parametre olarak vermek, bağlı liste örneği, union tanımı ve union'ları parametre olarak vermek. Hoca örneklerin bağlı liste (linked list) üzerinden yapılacağını, böylece veri yapılarına da hazırlık yapılacağını söyledi. Problemi çözmek için kullanılan verinin organizasyonuna dikkat edilirse problem daha verimli ve hızlı çözülür. En eski veri yapısı dizilerdir, ama sabit kapasiteleri bir dezavantajdır. Union ise aynı bellek alanını farklı biçimlerde yorumlama esnekliği verir. Hocanın hatırladığına göre struct ve union'ı parametre olarak aktarmak arasında pek fark yoktur, ama ikisi de sıradan değişken gibi aktarılmaz.

### 7.2 Paralel dizilerin sorunu

Örnekte çalışan kayıtları tutulur: ad (string), soyad (string), kimlik numarası (tam sayı), maaş (ondalıklı sayı). Dizilerde ısrar edilirse her alan için ayrı dizi gerekir. 1000 çalışan için 1000 elemanlık ID dizisi, 1000 elemanlık maaş dizisi, ad ve soyad en çok 20 karakter ise 1000×20'lik ad matrisi ve 1000×20'lik soyad matrisi tutulur. Aynı indisteki elemanlar aynı kişiye aittir. Bu kod üzerinde çalışacak herkesin bunu bilmesi, bizim de bunu belgelememiz gerekir.

Hoca iyi tasarımı, problem hangi düzeyde parçalara ayrılıyorsa o düzeyde parçalanabilen tasarım diye tanımladı. Burada veri gereğinden fazla parçalanmıştır. Aynı indisteki bilgilerin tek başına bir varlık olarak ele alınabilmesi gerekir.

### 7.3 struct tanımı

Slayttaki tanım (ekrandan, 02:10:00):

```c
struct Employee {
    char name[20], surname [20];
    int  ID;
    float salary;
};
struct Employee employees[1000];
```

`struct` anahtar kelimesinden sonra türün adı (`Employee`) gelir. Süslü parantez içinde alanlar yazılır, kapanan parantezden sonra noktalı virgül unutulmamalıdır. Hoca `int i;` benzetmesini kurdu: `struct Employee` `int`'e, değişken adı `i`'ye karşılık gelir. Tek bir çalışan için `struct Employee emp;` yazılır. `struct Employee employees[1000];` ise 1000 çalışanı saklayacak, türü `struct Employee` olan bir dizidir.

### 7.4 typedef

`struct Employee` tür adı iki kelimedir. C'deki `typedef` komutu bir veri türüne takma ad (alias) vermeyi sağlar. `typedef struct { ... } EMPLOYEE;` biçiminde yazılınca struct'ın kendisi adsız (anonim) olur, ama `typedef` ile `EMPLOYEE` adı verildiği için artık tek başına `EMPLOYEE` yazmak yeterlidir. `struct` ile `{` arasına bir ad (`Employee`) da yazılsaydı hem `EMPLOYEE` hem `struct Employee` kullanılabilirdi. Takma adlar geleneksel olarak büyük harfle yazılır. Böylece bunun bir değişken değil tür adı olduğu bir bakışta anlaşılır.

### 7.5 Alanlara erişim

Slayttaki örnekler (ekrandan, 02:15:00; slayttaki değişken adı burada `emp` olarak yazıldı):

```c
EMPLOYEE emp;
emp.ID = 1234;

EMPLOYEE *e_ptr;
e_ptr->ID = 1234;

(*e_ptr).ID = 1234;
```

Sıradan struct değişkeninde alana nokta operatörüyle erişilir: değişken adı, nokta, alan adı. Struct işaretçisinde nokta yerine ok operatörü (`->`) kullanılır. Eksi ve büyüktür işaretleri birlikte tek bir operatör sayılır. `e_ptr->ID`, `(*e_ptr).ID` ifadesinin kısaltmasıdır. Parantez gerekir, çünkü nokta operatörünün önceliği `*` operatöründen yüksektir. Önce `e_ptr`'nin gösterdiği kayda gidilmeli, sonra onun `ID` alanına erişilmelidir. Hoca kısaltmayı daha kolay bulduğunu ve derste onu kullanacaklarını söyledi.

### 7.6 İç içe struct

Struct içinde struct kullanılabilir, ama iç struct'a dışarıdan da erişebilmek için ona bir ad vermek gerekir. Örneğin çalışanın işe alım tarihi tutulacaksa tarih ayrı bir yapı olarak tanımlanır ve `typedef` ile `DATE` adı verilir. Ardından `EMPLOYEE` struct'ının içinde `DATE enlisted;` diye bir alan tanımlanır. İşe alım yılına nokta operatörü zincirleme kullanılarak erişilir. Hocanın anlattığı biçimde ifade şuna benzer: `emp.enlisted.year`. <!-- BELİRSİZ: DATE struct'ının alan adları (gün, ay, yıl) slayttan doğrulanamadı; alan adı ve "enlisted" adı altyazıdan alındı. -->

İç struct dıştakinin içinde de tanımlanabilirdi. Ama o zaman o yapıya dışarıdan erişilememek gibi yan etkiler olabilir. Tarih başlı başına kullanılabilecek bir yapı olduğu için ayrı tanımlayıp adlandırmak daha yararlıdır, hem tek başına hem başka struct'ların içinde kullanılabilir.

### 7.7 Struct'ları fonksiyona parametre olarak vermek

Slayttaki iki yol (ekrandan, 02:20:00):

- Struct'ın kendisini göndermek (değer ile): `EMPLOYEE emp; printReport(emp);`
- Struct'a işaretçi göndermek (referans ile): `EMPLOYEE emp; increaseSalary(&emp);`

Slayta göre referans ile gönderim daha hızlı ve verimlidir. Fonksiyonun parametresi seçime göre struct ya da struct işaretçisi olarak tanımlanır, gövdede de buna göre `.` ya da `->` kullanılır. İşaretçi struct'ın ilk alanını değil bütün struct'ı gösterir.

Hoca seçimi şöyle açıkladı. Raporlama yalnız değerleri okur, durum bilgisini değiştirmez. Bu yüzden değer ile gönderim yeterlidir. Maaşa zam yapmak ise bir alanın değerini değiştirir. Değişikliğin kalıcı olması için referans ile gönderilmesi gerekir: çağrıda `&emp`, fonksiyonda `EMPLOYEE *emp` parametresi ve gövdede `emp->salary`.

Tek bir kayıt işaretçiyle aktarıldığında işaretçi aritmetiği söz konusu değildir. Struct dizisi aktarılırsa elemanlar arasında işaretçi aritmetiğiyle dolaşılabilir. İşaretçi bir artırıldığında aynı kaydın sonraki alanına değil, bir sonraki kaydın başına geçer.

> **Ek bilgi (derste anlatılmadı):** Değer ile gönderimde struct'ın bütün alanları kopyalanır. Büyük struct'larda bu kopya hem zaman hem bellek harcar. Referans ile gönderimde yalnız adres kopyalanır. Değiştirilmemesi gereken bir struct işaretçiyle gönderilecekse parametre `const EMPLOYEE *emp` olarak tanımlanabilir.

## 8. Bağlı liste veri yapısına giriş

### 8.1 Dizilerin sınırları

Struct dizisi yeterince verimli değildir. Dizinin kapasitesi artırılıp azaltılamaz, en çok olası kayıt sayısı kadar alan ayrılmalıdır. O kadar kayıt girilmezse bellek boşa gider. İki kaydın arasına eleman eklemek de kolay değildir, sonraki bütün elemanları kaydırmak gerekir. Aradan eleman silmek de zordur. Bu işler yapılamaz değildir ama daha fazla uğraştırır. Bağlı liste bu dezavantajları kaldıran daha verimli bir veri yapısıdır.

### 8.2 Bağlı listenin yapısı

Hoca bağlı listeyi birbirine bağlı sosislere benzetti: bir diğerine bağlı kayıtlardan oluşan bir zincir. Slayttaki örnek liste tam sayılar tutar (ekrandan, 02:25:00):

```text
[49|*] -> [15|*] -> [73|*] -> [87|*] -> [10|NULL]
 head node                              tail node
```

- Liste düğümlerden oluşur. Her düğümün bir veri alanı ve sonraki düğümü gösteren bir işaretçisi (next) vardır.
- Listenin ilk düğümü baş düğümdür (head node). "İpin ucunu kaçırmamak" için ilk düğümün işaretçisi her durumda saklanmalıdır.
- Listede dolaşmak için ayrı bir işaretçi kullanılır. Bu işaretçi önce baş düğümü gösterir, her adımda sonraki düğümü gösteren işaretçi izlenerek bir sonraki düğüme geçilir.
- Son düğüm (tail node), `next` işaretçisinin `NULL` olmasından anlaşılır. Şekilde bu çapraz bir çizgiyle gösterilir.

Hoca son düğümün adresini saklamanın zorunlu olmadığını da belirtti, çünkü son düğüm `next`'in `NULL` olmasından anlaşılır.

### 8.3 Bağlı liste çeşitleri

- Tek yönlü bağlı liste (singly linked list): her düğümde yalnız `next` vardır. En temel ve en basit çeşittir. Derste örnekler bunun üzerinden yapılacaktır.
- Çift yönlü bağlı liste (doubly linked list): her düğümde bir önceki düğümü gösteren `previous` işaretçisi de vardır. Baş düğümün `previous`'u `NULL`dır. 15'i tutan düğümün `previous`'u 49'u, 73'ü tutanınki 15'i, 87'yi tutanınki 73'ü gösterir.
- Dairesel çift yönlü liste (circular doubly linked list): ilk düğümün `previous`'u son düğümü, son düğümün `next`'i baş düğümü gösterir.
- Dairesel tek yönlü liste de olabilir: `previous` işaretçisi yoktur, son düğümün `next`'i baş düğümü (49) gösterir.

Hangi çeşidin seçileceği çözülecek probleme bağlıdır. Diğer veri yapıları ilgili derslerde görülecektir.

### 8.4 Kodlamada iki yaklaşım

Birinci yaklaşımda `Employee` struct'ı hem veri elemanı hem düğüm olarak kullanılır, işler biraz daha basit tutulur (ekrandan, 02:30:00):

```c
#include <stdio.h>
typedef struct Employee {
    char name[20];
    int  ID;
    float salary;
    struct Employee *next;
} EMPLOYEE;
EMPLOYEE *head;
```

Çalışanların bağlı listede tutulacağı baştan kabul edilir ve çalışan kaydına, veri yapısının yönetimi için gereken `next` işaretçisi eklenir. `next` alanı `struct Employee *` türündedir ve sıradaki düğümü gösterir. `head` işaretçisi listenin ilk düğümünü gösterecek şekilde kodla korunur.

İkinci yaklaşım veriyi ve verinin organizasyonunu birbirinden ayırır (ekrandan, 02:35:00):

```c
#include <stdio.h>
typedef struct {
    char name[20];
    int  ID;
    float salary;
} EMPLOYEE;
typedef struct emp_node {
    EMPLOYEE data;
    struct emp_node *next;
} EMP_NODE;
EMP_NODE *head;
```

İlk struct yalnız kayıt verisini tutar. Düğüm için ayrı bir struct (`emp_node`) tanımlanır, adı çalışan tutan bir liste düğümü olduğunu anlatır. İki alanı vardır: `EMPLOYEE` türünden veri alanı ve `next` işaretçisi. Baş işaretçi artık düğüm türündendir (`EMP_NODE *head`). Slayta göre bu yaklaşım probleme ait struct'ı veri gösterimine ait struct'tan ayrı tutar ve öğrencilere alıştırma olarak bırakılmıştır. Ders notlarında birinci yaklaşım kullanılır.

Hoca ikinci yaklaşımın daha karmaşık ama daha esnek olduğunu şöyle açıkladı. Çalışan struct'ı üzerinde çalışan birçok fonksiyon olacaktır: çalışanın bilgilerini ekrana dökmek, belli adı olan ya da maaşı belli bir değerden yüksek olan çalışanları bulmak gibi. Birinci yaklaşımda bu fonksiyonların hepsi bağlı listeye bağımlı kalır. İleride arama daha hızlı olsun diye ID verilince kayda doğrudan erişilen bir map ya da hash tablosu yapısına geçmek istenirse, struct ile ilgili kod ve onu kullanan bütün fonksiyonlar düzenlenmek zorunda kalır. Sıfırdan yazılmaz, ama bütün fonksiyonlarda ek çaba gerekir. İkinci yaklaşımda veri struct'ı herhangi bir veri yapısında kullanılmaya hazırdır.

> **Hocanın vurgusu:** Kodu basit tutmak için birinci yaklaşım kullanılabilir. Ama veri yapısının değişebileceği ya da verinin başka projelerde başka biçimlerde düzenlenebileceği düşünülüyorsa, geleceğe yatırım yapıp veriyi ve düğümü ayırmak daha doğrudur.

Bağlı liste kod örnekleri bir sonraki derse bırakıldı.

## Örnek Sorular

**Soru 1** (ekrandan, 00:20:00): İki tam sayı parametresinin değerlerini takas eden bir fonksiyon yazınız. Fonksiyon iki tam sayı (`a`, `b`) alır. Fonksiyon döndüğünde `a`'nın değeri `b`'de, `b`'nin değeri `a`'da olmalıdır. Hatırlatma: `tmp = a; a = b; b = tmp;`

Derste verilen ipucu: takasın kalıcı olması için parametreler işaretçi olmalı, çağrıda sıradan değişkenlerin başına `&` konmalıdır.

> **Çözüm (derste verilmedi):** Ajan tarafından yazıldı ve `gcc -Wall` ile denendi.
>
> ```c
> void swap( int *a, int *b ) {
>     int tmp = *a;
>     *a = *b;
>     *b = tmp;
> }
> ```
>
> `int x=3, y=5;` için `swap(&x, &y);` sonrasında `x=5, y=3` olur. Dizi elemanları için `swap(&d[0], &d[2]);` yazılır. `int d[3]={10,20,30}` dizisi bu çağrıdan sonra `30 20 10` olur.

**Soru 2** (derste sözlü, 00:18:28): Verilen bir karakterin alfabetik olup olmadığını denetleyen bir fonksiyon yazınız. Harf ise 1, değilse 0 döndürsün.

> **Çözüm (derste verilmedi):** Ajan tarafından yazıldı ve denendi. İngiliz alfabesindeki harfler için:
>
> ```c
> int isAlpha( char c ) {
>     return (c>='a' && c<='z') || (c>='A' && c<='Z');
> }
> ```
>
> `isAlpha('a')` ve `isAlpha('Q')` 1, `isAlpha('7')` 0 döndürür.

**Soru 3** (ekrandan, 01:00:00): İki dizi alan ve onların uç uca eklenmiş halini döndüren bir fonksiyon yazınız.

Çözüm derste verildi: `concatArraysV1` (bölüm 5.3) ve sonucu parametreyle veren `concatArraysV2` (bölüm 5.4). `{1,5,7,19}` ve `{2,6,8,11,28}` dizileri için sonuç `1 5 7 19 2 6 8 11 28` olur.

**Soru 4** (derste sözlü, 01:16:48): İki sıralı diziyi alan ve bunların sıralı birleşimini döndüren bir fonksiyon yazınız. Dizilerin eleman sayıları farklı olabilir. İsteğe bağlı ek: bir dizinin sıralı olup olmadığını diziyi sıralamadan belirleyen bir fonksiyon yazınız.

Derste verilen ipuçları: iki dizi uç uca eklenip sonra sıralanmamalı, sıralama masraflı bir iştir. Sıralılık denetimi için dizinin kopyası sıralanıp karşılaştırılmamalı. Her dizi için ayrı bir işaretçi (indis) tutulur. Her adımda iki dizinin o anki elemanlarından küçük olanı sonuç dizisine yazılır ve küçük olanın işaretçisi ilerletilir. Hoca test dizileri için Excel'de 1 ile 99 arasında rastgele değerler üretti (ekrandan, 01:20:00).

> **Çözüm (derste verilmedi):** Ajan tarafından yazıldı ve `gcc -Wall` ile denendi. Ekrandaki rastgele değerler sıralanarak denendi: `{1,9,53,55,67,86}` ve `{63,66,73,94}` için sonuç `1 9 53 55 63 66 67 73 86 94` oldu.
>
> ```c
> int* mergeSorted( int a[], int n1, int b[], int n2 ) {
>     int *c = (int*) malloc( (n1+n2)*sizeof(int) );
>     int i=0, j=0, k=0;
>     if( c == NULL ) { printf("out of memory!"); exit(1); }
>     while( i<n1 && j<n2 ) {
>         if( a[i] <= b[j] ) c[k++] = a[i++];
>         else               c[k++] = b[j++];
>     }
>     while( i<n1 ) c[k++] = a[i++];
>     while( j<n2 ) c[k++] = b[j++];
>     return c;
> }
>
> int isSorted( int a[], int n ) {
>     int i;
>     for( i=1; i<n; i++ )
>         if( a[i-1] > a[i] ) return 0;
>     return 1;
> }
> ```
>
> Dizilerden biri bitince diğerinde kalan elemanlar sırayla eklenir. `isSorted` diziyi bir kez tarar, ardışık iki elemandan önceki büyükse 0 döndürür. Çağıran taraf işi bitince sonucu `free` etmelidir.

## Dersin Toparlaması

Bu derste fonksiyonlara parametre aktarımının iki biçimi görüldü. Değer ile çağrıda fonksiyona kopya gider ve değişiklik kalıcı olmaz. Referans ile çağrıda adres gider ve değişiklik kalıcı olur. Fonksiyon imzası, tanımı, ön bildirimi ve çağrının program sayacı düzeyindeki karşılığı hatırlatıldı. Dizileri fonksiyona verirken C'nin sınır denetimi yapmadığı, bu yüzden eleman sayısının ayrıca gönderilmesi gerektiği vurgulandı. `SIZE_OF_ARRAY` makrosunun yalnız dizinin tanımlandığı yerde ve gerçek dizilerde çalıştığı denendi. Fonksiyondan dizi döndürmek için yerel dizi yerine dinamik olarak ayrılmış alanın işaretçisinin döndürülmesi gerektiği `concatArraysV1` ile, sonucu parametreyle vermenin de `concatArraysV2` ile gösterildi. `main`'in `argc` ve `argv` parametreleriyle komut satırı argümanları okundu.

Dersin son bölümünde struct kavramına girildi: tanım, `typedef`, nokta ve ok operatörleri, iç içe struct ve struct'ları fonksiyona parametre olarak vermek. Ardından bağlı liste veri yapısı ve çeşitleri tanıtıldı, düğüm struct'ını tanımlamanın iki yolu karşılaştırıldı. Bir sonraki derste bu yapı üzerinde pratik bağlı liste kod örneklerine geçilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
