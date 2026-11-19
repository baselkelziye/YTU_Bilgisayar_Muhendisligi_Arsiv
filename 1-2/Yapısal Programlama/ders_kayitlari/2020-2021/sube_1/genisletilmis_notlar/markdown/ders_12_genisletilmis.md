# Ders 12 Genişletilmiş Notu: Fonksiyonlara Parametre Aktarımı, Dizilerin Fonksiyonlara Aktarılması ve main Fonksiyonunun Argümanları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Planı
- 2. Değerle ve Referansla Çağırma
- 3. Fonksiyon Tanımı, Anma ve Çağrı
- 4. Fonksiyon Biçimleri ve Faktöriyel
- 5. Örnek 2: Alfabetik Karakter Denetimi
- 6. Örnek 3: İki Değişkenin Yerini Değiştirmek
- 7. Dizileri Fonksiyona Parametre Olarak Aktarmak
- 8. Dizi Boyutunu Bulan Makro
- 9. Dizinin İki Elemanının Yerini Değiştirmek
- 10. Fonksiyondan Dizi Döndürmek
- 11. İşaretçiden Diziye Kopyalama
- 12. Makro Fonksiyon İçinde Neden Çalışmaz?
- 13. Örneğin Özeti ve free Sorusu
- 14. Sonucun Yazılacağı Diziyi Çağıranın Vermesi
- 15. main Fonksiyonunun Argümanları
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Planı

Ders, fonksiyonlar konusunun devamıdır. Hoca bu dersin üç bölümünü slayttaki "Outline" ile verdi (ekrandan, 00:05:00):

- Argüman aktarımı: pass by reference, pass by value.
- Bildirimler ve çağrılar: tanım (definition), anma (allusion), fonksiyon çağrısı.
- `main` fonksiyonu.

Asıl soru şudur: bir fonksiyona normal bir değişken ya da işaretçi aktarıldığında, fonksiyon bittikten sonra parametre olarak verilen değişkenin değeri değişir mi, aynı mı kalır? Temelde iki çalışma biçimi vardır: değerle çağırma (call by value, pass by value) ve referansla çağırma (call by reference, pass by reference). Hoca, Java'da bunlara bir üçüncüsünün, referansın değerle aktarılmasının eklendiğini, onun başka bir derste görüleceğini söyledi. Anma konusu daha önce görülmüştü; burada kısaca hatırlatıldı.

## 2. Değerle ve Referansla Çağırma

C'de aksi belirtilmedikçe fonksiyon argümanları değerleriyle aktarılır. Bu, fonksiyonun içinde parametrelerin değerlerini istediğiniz gibi değiştirebileceğiniz anlamına gelir; ama bu değişikliklerin süresi fonksiyon gövdesiyle sınırlıdır. Fonksiyon tamamlanıp çağıran fonksiyona dönüldüğünde, parametre olarak verilen değişkenlerin değerleri eskisi gibi kalır.

Bunun tersi isteniyorsa, yani çağrılan fonksiyonda parametreye yapılan değişikliğin çağıran fonksiyonda da kalıcı olması gerekiyorsa, değişken işaretçi ile, referans olarak aktarılmalıdır. Hoca bunu `scanf` ile bağladı: `scanf`'e neden yalnız değişken adını değil adresini veriyoruz? Çünkü `scanf`'in okuduğu değerin `scanf` bittikten sonra da değişkende kalması gerekir. Bu yüzden ona referans, yani adres gönderilir.

### 2.1 increaseRegular ve increasePointer örneği

Derste Dev-C++ ile şu kod çalıştırıldı (ekrandan, 00:10:00). `increaseRegular` iki parametre alır, ilk parametrenin değerini ikinci parametre kadar artırır ve son değeri yazar. `increasePointer` aynı işi yapar, ama değeri değişecek olan ilk parametre işaretçi olarak alınır. Bu yüzden artırılan şey işaretçinin kendisi değil gösterdiği adresteki değerdir; başına `*` konur.

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

Ekrandaki kodda `return 0;` öncesinde `system("PAUSE");` satırı vardı; burada çıkarıldı. Kod gcc -Wall ile derlendi ve çalıştırıldı.

Adım adım çalışma şöyledir:

- main'de `a = 3`, `b = 5`.
- `increaseRegular(a, b)` çağrılır. `a`'nın değeri 3, `aa` parametresine kopyalanır; `b`'nin değeri 5, `bb`'ye kopyalanır. `aa += bb` ile `aa` 8 olur ve ekrana `increaseRegular finishes with 8` yazılır.
- main'e dönülür. main `main says the value is 3` der. Neden? `a` yalnız değeriyle aktarıldı. `a`'nın bellekte tuttuğu yer ile `aa`'nın bellekte tuttuğu yer farklıdır; yalnız değer kopyalanmıştır. `aa` üzerinde yapılan değişikliğin ömrü o fonksiyonun ömrü kadardır.
- `increasePointer(&a, b)` çağrılır. İlk parametre `int *` beklediği için normal değişken değil, `a`'nın adresi verilir; artık işaretçi `a`'yı gösterir. Hoca burada `&` konmazsa uygun bir atama olmayacağını belirtti.
- `*aa += bb;` ile `a`'nın adresindeki değere 5 eklenir. Fonksiyon `increasePointer finishes with 8` yazar.
- main'e dönülünce main de `main says the value is 8` der. Değişiklik kalıcı olmuştur.

Hoca bunu "bir bakıma avantaj, bir bakıma dezavantaj" diye değerlendirdi. Bir değeri fonksiyona verip fonksiyonun onunla istediği gibi oynamasını, fonksiyon bitince değerin eski hâline dönmesini istiyorsanız normal (değerle) aktarım uygundur. Fonksiyonun parametreyi değiştirebilmesi ve bu değişikliğin kalıcı olması gerekiyorsa referans, yani işaretçi aktarılmalıdır.

> **Hocanın vurgusu:** Bu, önemli bir çalışma biçimidir. Değerle aktarılan parametredeki değişiklik fonksiyon bitince kaybolur; kalıcı değişiklik için adres aktarılır.

## 3. Fonksiyon Tanımı, Anma ve Çağrı

Bir fonksiyonun çağrılabilmesi için ya daha yukarıda gövdesiyle birlikte tanımlanmış olması ya da en azından imzasının verilmiş olması gerekir. İmza verilip `;` ile bitirilirse fonksiyon aşağıda bir yerde çağrılabilir, gövdesi de daha aşağıda tanımlanabilir. İmzanın bu biçimde önceden verilmesi anmadır (allusion).

Slayttaki tanımlar şöyledir (ekrandan, 00:15:00):

- Tanım (definition): fonksiyonun ne yaptığını, argümanlarının sayısını ve türünü gerçekten belirler.
- Fonksiyon çağrısı (function call): fonksiyonu çağırır ve programın akışı çağrılan fonksiyona atlar. Fonksiyon dönünce çalışma çağrının hemen sonrasından devam eder.

Hoca bunu bellekle açıkladı. Bir fonksiyonun kodu bellekte ayrı bir yerde saklanır; main'in kodu da öyle. main içinde başka bir fonksiyon çağrılınca denetim akışı o fonksiyonun kodunun saklandığı adrese gider ve oradan itibaren çalışır. Çağrılan fonksiyon bitince çağırana geri dönülür. Bir fonksiyon çağrıldığında onun içinde tanımlanan bütün değişkenler o fonksiyonun ömrü boyunca vardır; fonksiyon bitince bu değerler silinir.

## 4. Fonksiyon Biçimleri ve Faktöriyel

Hoca konunun bütünlüğü için fonksiyon tanımlama biçimlerini sırayla hatırlattı. En basit fonksiyon hiçbir parametre almayan ve hiçbir değer döndürmeyen fonksiyondur. Böyle bir fonksiyonun yerine makro da rahatlıkla kullanılabilir; makroların normal fonksiyonlara göre avantaj ve dezavantajları daha önce görülmüştü.

Daha karmaşık bir fonksiyon hem parametre alır hem de sonuç döndürür. Slayttaki örnek bir faktöriyel fonksiyonuydu: parametre alır, kendi yerel değişkenlerini tanımlayıp kullanır ve hesapladığı sonucu döndürür. Fonksiyon adından sonra normal parantez içinde argümanlar yazılır; birden çok argüman virgülle ayrılır.

Faktöriyelde dikkat edilecek nokta taşmadır. Bir `int` yaklaşık 2 milyara kadar değer tutar, ama faktöriyel çok hızlı büyür: 5! = 120, 6! bunun 6 katı, 720 ve devamı hızla artar. Bu yüzden `int`'in üst sınırına bakılmalı ve belli bir girdiden büyük faktöriyeller için "bunu hesaplayamam" denmelidir. Daha büyük değerler gerekiyorsa `long` gibi daha geniş türler kullanılır. `long` da yetmiyorsa hoca bir sayının iki `long` ile tutulabileceğini söyledi: biri sayının en anlamlı (most significant), diğeri en az anlamlı (least significant) kısmını tutar.
## 5. Örnek 2: Alfabetik Karakter Denetimi

Slayttaki Örnek 2 (ekrandan, 02:10:00; hoca bu slaytı 00:19:10 civarında anlattı): verilen `char` değişkenin alfabetik olup olmadığını denetleyen basit bir fonksiyon yazın. Denetlenecekler `a-z` ve `A-Z` aralıklarıdır; fonksiyon alfabetikse 1, değilse 0 döndürür. Hoca küçük ve büyük harf kodlarıyla bir önceki derste buna benzer işler yapıldığını hatırlattı. Dönüş türü `int` olabilir; Boolean tür de kullanılabilir. Bu örnek evde yapılmak üzere bırakıldı. Çözüm "Örnek Sorular" bölümündedir.

## 6. Örnek 3: İki Değişkenin Yerini Değiştirmek

Slayttaki Örnek 3 (ekrandan, 00:20:00): iki tam sayı parametrenin değerlerini değiştiren bir fonksiyon yazın. Fonksiyon `a` ve `b` diye iki tam sayı alır; fonksiyon dönünce `a`'nın değeri `b`'de, `b`'nin değeri `a`'da olmalıdır. Slayt şu adımları hatırlatır:

```c
tmp = a;
a = b;
b = tmp;
```

Geçici değişken şarttır: ilk satır olmadan doğrudan `a = b` denirse `a`'nın değeri tamamen kaybolur ve `b`'ye atanacak değer kalmaz.

Hoca bu örneği hemen derste yaptı, çünkü az önce görülen değerle ve referansla çağırma farkını doğrudan gösterir. Normal değişkenler yalnız değerle aktarıldığı için değerleri kalıcı olarak değiştirilmek isteniyorsa fonksiyona işaretçi olarak verilmelidir. İki sürüm yazıldı: işaretçisiz `swapRegular` ve işaretçili `swapPointer`. İşaretçili sürümde yalnız `*` koymayı unutmamak gerekir. Kodun gövdesi altyazıdan kuruldu; main'in başı ekranda görülüyor (ekrandan, 00:35:00). gcc -Wall ile derlendi ve çalıştırıldı:

```c
#include <stdio.h>
#include <stdlib.h>
void swapRegular( int aa, int bb ) {
    int tmp = aa;
    aa = bb;
    bb = tmp;
}
void swapPointer( int *aa, int *bb ) {
    int tmp = *aa;
    *aa = *bb;
    *bb = tmp;
}

int main(int argc, char *argv[]){
    int a=3, b=5;
    swapRegular( a, b );
    printf("main says a is %d b is %d\n", a, b);
    swapPointer( &a, &b );
    printf("main says a is %d b is %d\n", a, b);
    return 0;
}
```

Çıktı `main says a is 3 b is 5` ve ardından `main says a is 5 b is 3` olur. Hoca sonucu şöyle özetledi: normal sürüm çalıştı ama fonksiyon bittikten sonra değişiklik kalıcı olmadı; işaretçi, yani referans aktarılınca değişiklik rahatlıkla yapıldı.

> **Hocanın vurgusu:** Bu temel noktayı kaçırmamak gerekiyor.

## 7. Dizileri Fonksiyona Parametre Olarak Aktarmak

Dizilerle her işlemde dizinin eleman sayısından fazla elemanla çalışmamaya dikkat edilmelidir. Slayt bunu "Do NOT forget: No boundary checking!" diye verir (ekrandan, 00:25:00). Fonksiyon yazmanın motivasyonu da unutulmamalıdır: aynı işi farklı verilerle tekrar tekrar yapabilmek.

Fonksiyonun dizinin nerede bittiğini bilmesi için iki yol vardır. Birincisi, dizinin son elemanı özel bir değer olur. Örneğin doğal sayılarla çalışan bir fonksiyonda negatif bir sayı dizinin sonuna gelindiğini belirtebilir; karakter katarlarında `'\0'` karakterinin yaptığı gibi. İkincisi, dizinin eleman sayısı fonksiyona ikinci parametre olarak gönderilir.

Slayttaki üç yöntem şunlardır (ekrandan, 00:25:00):

- Gerçek dizi boyutunu kullanmak: `void printArray( int ar[5] )`. Pek kullanışlı değildir; farklı boyutlarda dizileri yazdırmak gerekirse ne olacak? Hoca bunu sıralama örneğiyle açıkladı: 5 elemanlı diziyi sıralayan fonksiyon ayrı, 6 elemanlı diziyi sıralayan fonksiyon ayrı olması mantıksızdır.
- Dizi ve boyut parametresi kullanmak: `void printArray( int ar[], int size )`. Köşeli parantezler boyut yazılmadan açılıp kapanırsa fonksiyon herhangi bir eleman sayısında diziyi kabul eder. Ama kaç eleman olduğu ya ayrı parametreyle söylenir ya da bir bitiş değeriyle belirtilir. Bu bir öncekinden çok daha kullanışlıdır.
- İşaretçi ve tam sayı kullanmak: `void myFunction( int *ar, int size )`. Bu da kullanışlıdır; yine eleman sayısı ya da bir anahtar bitiş değeri gerekir.

Hoca son iki yöntemden birinin tercih edilebileceğini söyledi. Bir diziyi sıralayan fonksiyonun işaretçi parametresiyle yazılmasını da, yıldızı doğru yerde kullanmak koşuluyla, alıştırma olarak bıraktı.

## 8. Dizi Boyutunu Bulan Makro

Bir dizinin boyutunu hesaplamak için bir ipucu vardır: her türden dizinin boyutunu veren bir makro tanımlanabilir (ekrandan, 00:30:00):

```c
#define SIZE_OF_ARRAY(x) (sizeof(x) / sizeof((x)[0]))
```

Mantığı şudur: dizideki her eleman aynı türdendir ve boyutları sabittir. Dizinin toplam boyutu ilk elemanın boyutuna bölünürse eleman sayısı çıkar.

Ancak slayt hemen uyarır: bu, dizi boyutunu fonksiyona ayrı parametre olarak aktarma zorunluluğunu ortadan kaldırmaz. Fonksiyona parametre olarak gönderilen dizi işaretçi gibi ele alınır; `sizeof` dizinin değil işaretçinin boyutunu döndürür. Bu yüzden makro fonksiyonların içinde çalışmaz. Kullanıcıya kaç eleman gireceği sorulmalı ya da elemanlar bir `while` döngüsünde alınıyorsa bir sayaç tutulmalıdır.

Hoca bunu şöyle anlattı: fonksiyon içindeki `sizeof(x)` dizinin bellekte kapladığı toplam alanı değil, dizinin işaretçisinin kapladığı alanı verir. İşaretçi, ilgili türden bir elemanı gösterebilecek bir işaretçi olduğundan sonucun 1 çıkacağını söyledi. Dizi işaretçisi eleman türünden daha geniş tutuluyorsa sonuç 1'den büyük olabilir, ama yine de eleman sayısını vermez.

> **Ders sonrası not:** Hoca sonucun 1 çıkacağını söyledi ve derste kullanılan Dev-C++ ortamında da 1 çıktı (ekrandan, 01:20:00). Bu değer işaretçi boyutunun `int` boyutuna oranıdır ve platforma bağlıdır. 64 bitlik bir sistemde gcc ile denendiğinde 2 çıktı (8 baytlık işaretçi, 4 baytlık `int`). Sonuç ne olursa olsun eleman sayısı değildir.

## 9. Dizinin İki Elemanının Yerini Değiştirmek

Hoca, bir sonraki konuya (fonksiyondan dizi döndürme) neden ihtiyaç olduğunu göstermek için dizinin herhangi iki elemanının yerini değiştiren bir fonksiyon yazdı. Fonksiyon `swapArrayElement` adını aldı ve dizi, `i` ve `j` indisleri ile dizinin eleman sayısı `n`'yi parametre alır. Geriye bir şey döndürmesine gerek yoktur. İndislerden biri sıfırdan küçük ya da `n`'den büyükse fonksiyon hiçbir şey yapmadan `return` ile döner; istenirse hata mesajı da yazılabilir. Yazdırma için `listArray` fonksiyonu yazıldı: `for` ile `%d ` biçiminde elemanları yazar, sonunda yeni satır basar. `listArray`'in imzası yukarıya konup gövdesi sona bırakıldı, çünkü asıl görülmesi gereken main ve `swapArrayElement`'tir.

İlk yazılan denetim şuydu (ekrandan, 00:35:00):

```c
if( i < 0 || i > n || j < 0 || j > n )
    return;
```

Main yazılırken hoca hatayı fark etti: boyut 4 ise geçerli indisler 0, 1, 2, 3'tür; 4 verilirse de fonksiyonun dönmesi gerekir. Denetim `i >= n` ve `j >= n` olarak düzeltildi (ekrandan, 00:40:00). Hoca bunu "off by one error" örneği olarak andı. Son elemanı değiştirmek için de `SIZE` değil `SIZE-1` verilmelidir.

Derlemede `parse error before ';'` hataları çıktı (ekrandan, 00:40:00). Bir öğrenci nedenin yukarıdaki `#define SIZE 4;` satırındaki noktalı virgül olabileceğini sordu ve haklıydı. Makro satırındaki `;` makronun kullanıldığı her yere yapıştırıldığı için derleyici hatayı tanımın değil kullanımın olduğu satırlarda gösterdi. Hoca bunu ilginç buldu.

Düzeltilmiş program aşağıdadır. Ekrandaki dizi tanımı satırı düzenlenirken görüldüğü için `int dizi[SIZE] = {1,2,3,4};` biçiminde yazıldı ve `system("PAUSE");` çıkarıldı. gcc -Wall ile derlendi ve çalıştırıldı:

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

Çıktı `Before: 1 2 3 4` ve `After: 4 2 3 1` olur. Hoca burada asıl noktaya geldi: `swapArrayElement` içinde yapılan değişiklik kalıcı oldu. Peki dizinin ilk hâli korunsun, ilk ve son elemanı yer değiştirmiş hâli başka bir dizi olsun istenirse ne yapılır? İki dizi tanımlanıp biri ötekine kopyalanabilir ve kopya değiştirilebilir. Ama `swapArrayElement` içinde yeni bir dizi tanımlayıp elemanları ona atasaydık ve o diziyi döndürmeye çalışsaydık derleyici buna izin vermezdi.

## 10. Fonksiyondan Dizi Döndürmek

Aradan sonra hoca soruyu yeniden sordu: fonksiyondan nasıl dizi döndürülür? Döndürülemez. Motivasyon şuydu: fonksiyon bir diziyi alsın, ama aldığı diziyi değiştirmesin; değişmiş hâlini döndürsün. Geriye dizi döndürülemediği için bu ancak dinamik bellek yönetimi ile fonksiyondan işaretçi döndürmeyi birlikte kullanarak yapılabilir. Fonksiyon, oluşacak dizi kadar bir alan ayırır ve o alanın başlangıcına bir işaretçi döndürür.

Bir fonksiyondan birden çok değer döndürme ihtiyacı da aynı yere varır. Örneğin sıralama fonksiyonu sıralanacak diziyi parametre olarak alıp sıralanmış diziyi geri döndürsün istenirse, bu doğrudan yapılamaz; ama sıralanmış diziyi gösteren bir işaretçi döndürülebilir.

Bunun çalışmasının nedeni şudur: bir fonksiyon içinde `malloc` ya da `calloc` ile bellek alanı ayrılırsa bu alan kalıcıdır, fonksiyon bitince geri alınmaz. Fonksiyonun içinde tanımlı ilkel değişkenlerde yapılan değişiklikler ise fonksiyon bitince unutulur. Ayrılan alanın işaretçisi döndürülürse fonksiyon bittikten sonra da o işaretçi geçerli kalır.

### 10.1 Örnek: iki diziyi birleştirmek

Slayttaki görev (ekrandan, 01:00:00): iki diziyi alan ve bunların birleşimini döndüren bir fonksiyon yazın. Fonksiyon birinci diziyi ve eleman sayısını, ikinci diziyi ve eleman sayısını alır; iki diziyi değiştirmeden birleşik hâlini döndürür.

```c
int* concatArraysV1( int arr1[], int size1, int arr2[], int size2 ) {
    int *merged = (int*) malloc( (size1+size2)*sizeof(int) );
    int i;
    for( i=0; i<size1; i++ )
        merged[i] = arr1[i];
    for( ; i<size1+size2; i++ )
        merged[i] = arr2[i-size1];
    return merged;
}
```

Hoca kodu satır satır açıkladı:

- `merged` adlı bir `int` işaretçisi tanımlanır ve gerekli yer ayrılır. İki dizinin eleman türü aynı olmak zorundadır. Gerekli alan: birinci dizinin eleman sayısı artı ikinci dizinin eleman sayısı, çarpı bir elemanın boyutu. Eleman boyutu `sizeof(int)` ile öğrenilir.
- `malloc` `void *` döndürür; bu `(int*)` ile çevrilip `merged`'e atanır.
- `merged` işaretçisi dizi operatörüyle (`merged[i]`) de, `+` operatörüyle de ilerletilebilir. Hoca dizi biçimini, başka dizi fonksiyonlarından kopyalayıp yapıştırmayı kolaylaştırdığı için seçtiğini söyledi.
- Birinci `for` birinci dizinin elemanlarını ayrılan alanın ilk gözlerine atar. İkinci `for`'da ilk değer ataması yapılmaz; `i` kaldığı değerden itibaren toplam eleman sayısına kadar devam eder ve ikinci dizinin elemanları `arr2[i-size1]` ile atanır.
- İşaretçi döndürülür. Döndürülen işaretçi üzerinden birleşik dizi `printArray` ile ekrana yazılabilir.

Slayttaki yardımcı kod (ekrandan, 01:05:00):

```c
#include <stdio.h>
#define SIZE_OF_ARRAY(x) (sizeof(x) / sizeof((x)[0]))

void printArray( int a1[], int size ) {
    int i;
    for( i=0; i<size; i++ )
        printf("%d\t", a1[i]);
    printf("\n");
}
```

Main'de birinci dizide tek sayılar `{1, 5, 7, 19}`, ikinci dizide çift sayılar `{2, 6, 8, 12, 28}` vardır (ekrandan, 01:30:00). Hoca, iki diziyi elemanların değerine göre birleştirmenin ileride egzersiz olabileceğini söyledi. Fonksiyon işaretçi döndüreceği için sonuç `int *ptrM`'ye atanır; fonksiyona birinci dizi, eleman sayısı, ikinci dizi ve eleman sayısı verilir. Çıktı: birinci dizi `1 5 7 19`, ikinci dizi `2 6 8 12 28`, birleşik liste `1 5 7 19 2 6 8 12 28`.

## 11. İşaretçiden Diziye Kopyalama

Hoca, "yine de işaretçiyle değil diziyle çalışmak istiyorum" diyenler için bir yol gösterdi. Üçüncü dizi doğrudan parametre olarak verilebilir; bu daha önce konuşulmuştu. Başka bir yol: fonksiyon geriye işaretçi döndürür, sonra "işaretçinin başladığı yerden şu kadar elemanı al, diziye yaz" diyen bir fonksiyon yazılır. Hoca bunun hataya açık (error-prone) olduğunu, boyutların doğru hesaplanması gerektiğini, yanlış değer verilirse saçma sonuçlar çıkacağını söyledi.

İlk sürüm işaretçiye dizi gibi erişir (ekrandan, 01:15:00):

```c
void populateArrayV1( int array[], int size, int *begin ) {
    int i;
    for( i=0; i<size; i++ )
        array[i] = begin[i];
}
```

İkinci sürümde işaretçinin kendisi ilerletilir. Hoca, `for`'un artırım kısmında birden fazla komut verilebileceğini hatırlatarak `i++, begin++` yazdı; gövde `*begin` değerini atar. İsteyen daha alışılmış bir biçimle de yazabilir. Altyazıdan kurulan bu sürüm şöyledir:

```c
void populateArrayV2( int array[], int size, int *begin ) {
    int i;
    for( i=0; i<size; i++, begin++ )
        array[i] = *begin;
}
```

Main'de `int arr3[9];` tanımlandı ve `populateArray(arr3, 9, ptrM)` çağrıldı. İki sürüm de aynı sonucu verdi: `Array 3 is: 1 5 7 19 2 6 8 12 28` (ekrandan, 01:20:00). Hoca, işaretçi aritmetiğinde zorlananların `populateArrayV1`'deki gibi işaretçiye dizi gibi erişebileceğini söyledi. Ama işaretçiyle çalışmaya alışınca bu üçüncü dizi mantığına hiç gerek kalmaz; en doğrusu `concatArraysV1`'in özgün hâlindeki gibi işaretçi döndürüp onunla ilerlemektir.

Derste denenen tam program aşağıdadır (ekrandan, 01:15:00, 01:20:00, 01:30:00). Fonksiyon içindeki boyut yazdırma satırı Bölüm 12'deki deneme için eklendi; `system("PAUSE");` çıkarıldı, makronun sonucu `%d` için `(int)` ile çevrildi. gcc -Wall ile derlendi ve çalıştırıldı:

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

void populateArrayV2( int array[], int size, int *begin ) {
    int i;
    for( i=0; i<size; i++, begin++ )
        array[i] = *begin;
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
    populateArrayV2(arr3, 9, ptrM);
    printf("Array 3 is:\t");
    printArray(arr3, 9);
    free(ptrM);
    return 0;
}
```

gcc bu kodu derlerken `sizeof on array function parameter 'arr1' will return size of 'int *'` uyarısı verir; bu uyarı Bölüm 12'de anlatılan durumun ta kendisidir.

### 11.1 free sorusu

**Soru:** `free` yazmamız gerekmiyor muydu?

**Cevap:** Evet, gerekiyor. Hoca hatırlatma için teşekkür etti ve `free(ptrM);` satırını main'in sonuna, belleğe ihtiyaç bittikten sonraya ekledi (ekrandan, 01:30:00). Bu kod bir kez çalışınca fark etmeyebilir, ama milyonlarca kez çalıştırılırsa bellek tükenir.

## 12. Makro Fonksiyon İçinde Neden Çalışmaz?

`SIZE_OF_ARRAY` makrosu main'de doğru çalıştı. Hoca slayttaki uyarıya geri döndü: dizinin eleman sayısını öğrenme işi fonksiyonun içinde yapılamaz. Yani boyutlar main'de değil de `concatArraysV1`'in içinde makroyla hesaplanmak istenirse olmaz. Dizi main içindeyken makro doğru sonuç verir, ama fonksiyonun içinde vermez; çünkü parametre olarak dizi aktarılıyormuş gibi görünse de aslında dizinin başlangıcına bir işaretçi aktarılır.

Bunu göstermek için `concatArraysV1`'in içine `printf("Size of arr1 calculated in function as %d\n", SIZE_OF_ARRAY(arr1));`, main'e de aynısının "in main" sürümü eklendi. Sonuç (ekrandan, 01:20:00): fonksiyon içinde 1, main içinde 4. Fonksiyon içindeki sonuç yanlıştır.

> **Hocanın vurgusu:** Bu makro fonksiyonların içinde çalışmaz; dizinin boyutu fonksiyona ayrıca aktarılmalıdır.

## 13. Örneğin Özeti ve free Sorusu

Hoca örneği şöyle toparladı:

- main içinde iki dizi tanımlandı. Fonksiyon çağrılırken diziler yalnız adlarıyla, köşeli parantez olmadan verildi; boyutlar makroyla main'de hesaplandı, çünkü makronun yalnız orada doğru çalıştığı biliniyor.
- Fonksiyonun döndüreceği işaretçi `int *ptrM = concatArraysV1(...)` biçiminde, `*` ile tanımlanıp doğrudan fonksiyonun döndürdüğü değer atanarak alındı.
- Fonksiyonun parametre listesinde diziler adlarıyla ve köşeli parantezleriyle (`int arr1[]`) yazıldı.
- Çağrılan fonksiyonun içinde bellek ayrılması gerekir. İki dizi birleştirileceği için iki boyut toplanır ve bir elemanın boyutuyla çarpılır. `calloc` ile sıfırlamaya gerek yoktur, çünkü alanın tamamı iki dizinin elemanlarıyla doldurulacaktır.
- `return merged;` yazılırken işaretçinin başına `*` konmaz. Yıldız zaten dönüş türünde (`int*`) vardır; `return *merged;` yazılırsa işaretçi değil gösterdiği değer döndürülmüş olur. Hoca bunları hatırlamanın kolay olmadığını, kendisinin de bazen takıldığını söyledi.

**Soru:** Fonksiyonun içinde `malloc` yazdık; orada `free` gerekir mi?

**Cevap:** Orada `free` gerekmez. Bir `malloc` için bir `free` yapılır; fazlası hataya yol açabilir. Üstelik fonksiyonun içinde `free` dememek gerekir: denirse fonksiyonun döndürdüğü işaretçi artık serbest bırakılmış bir alanı gösterir. O alana yazılırsa hata vermeyebilir ama garip sonuçlar ortaya çıkar. Fonksiyonun içindeyken iş bitmemiştir; fonksiyon işaretçiyi döndürür ve main onunla çalışır. `free` yalnız main'de, işimiz bittiğinde yapılır.

Hoca, `free` yapılmasa da program kapanınca komut satırı penceresinin belleği büyük olasılıkla geri verdiğini, ama bundan C derleyicisinin değil kullandığı Windows komut satırı gerçeklemesinin sorumlu olduğunu söyledi. Ortam bunu yapamıyorsa yapamaz; doğru programlama alışkanlığı gereği iş bitince, genelde main'in sonunda, `free` yapılmalıdır.

## 14. Sonucun Yazılacağı Diziyi Çağıranın Vermesi

Slaytta bir seçenek daha vardır (ekrandan, 01:25:00): fonksiyonun bellek ayırıp sonucun işaretçisini döndürmesi yerine, fonksiyonu çağıran taraf boş bir dizi tanımlayıp bunu doldurulması için fonksiyona verebilir. Bu durumda bellek ayırma işi main'de yapılmış olur.

### 14.1 concatArraysV2: dizi parametresi

Ders notundaki V2 sürümünde `for` örgüsü hemen hemen aynıdır, ama fonksiyonda `malloc` yoktur. Fonksiyon `void` döner ve birleşik hâli nereye yazacağını üçüncü dizi parametresinden öğrenir. Hoca, `int arr3[9];` gibi bir dizi tanımının zaten yer ayırmak anlamına geldiğini söyledi; bu yüzden V2'de `free` gerekmez. Hoca, slaytta bu örneğin dizi biçiminde gösterildiğini, işaretçi biçiminde de gösterilse daha iyi olabileceğini söyledi. Ayrıca bu örnekte makro kaldırılıp boyutun hesabı doğrudan koda yazılmıştı; hesap yalnız iki kez yapılıyorsa makronun pek kazancı yoktur, beş on kez yapılıyorsa yararlı olabilir. Derste V2 çalıştırıldı ve doğru sonuç verdi.

### 14.2 concatArraysV3: işaretçi parametresi

V3'te üçüncü parametre dizi değil işaretçidir (ekrandan, 01:50:00):

```c
void concatArraysV3( int arr1[], int size1, int arr2[], int size2, int *arr3 ) {
    int i;
    for( i=0; i<size1; i++ )
        arr3[i] = arr1[i];
    for( ; i<size1+size2; i++ )
        arr3[i] = arr2[i-size1];
}
```

Main'de önce `malloc` ile yer ayrılıp işaretçi parametre olarak verildi (ekrandan, 01:35:00):

```c
int *ptrM = (int*) malloc( (SIZE_OF_ARRAY(arr1)+SIZE_OF_ARRAY(arr2))*sizeof(int) );
```

Hoca, boyutların her seferinde yeniden hesaplanması yerine `size1` ve `size2` diye bir kez hesaplanmasının daha iyi olacağını da söyledi. Derleme hatasız tamamlandı (ekrandan, 01:35:00) ama elemanların aktarılmasında bir sorun çıktı. Hoca nedeni derste bulamadı; aradan sonra da bakma fırsatı olmadığını söyledi.

> **Ders sonrası not:** 01:35:00 karesinde sonuç `concatArraysV3( ..., ptrM );` ile `ptrM`'nin gösterdiği alana yazılıyor, ama yazdırma satırı `printArray(arr3, ...)` olarak kalmış. Yanlış çıktının nedeni büyük olasılıkla hiç doldurulmamış `arr3` dizisinin yazdırılmasıdır. Yazdırma `printArray(ptrM, size1+size2)` olarak değiştirilince doğru sonuç alınır. <!-- BELİRSİZ: karede yazdırma satırının sonu kesik ve yanlış çıktının kendisi görünmüyor -->

V2 ve V3'ün düzeltilmiş hâli aşağıdadır. Bu tam program derste bu biçimde yazılmadı; iki fonksiyonun gövdesi kareden, main ajan tarafından kuruldu. gcc -Wall ile derlendi ve çalıştırıldı; iki satır da `1 5 7 19 2 6 8 12 28` yazdı.

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

void concatArraysV2( int arr1[], int size1, int arr2[], int size2, int arr3[] ) {
    int i;
    for( i=0; i<size1; i++ )
        arr3[i] = arr1[i];
    for( ; i<size1+size2; i++ )
        arr3[i] = arr2[i-size1];
}

void concatArraysV3( int arr1[], int size1, int arr2[], int size2, int *arr3 ) {
    int i;
    for( i=0; i<size1; i++ )
        arr3[i] = arr1[i];
    for( ; i<size1+size2; i++ )
        arr3[i] = arr2[i-size1];
}

int main(int argc, char *argv[]){
    int arr1[] = {1,5,7,19}, arr2[] = {2,6,8,12,28};
    int size1 = SIZE_OF_ARRAY(arr1), size2 = SIZE_OF_ARRAY(arr2);
    int arr3[9];
    int *ptrM = (int*) malloc( (size1+size2)*sizeof(int) );

    concatArraysV2( arr1, size1, arr2, size2, arr3 );
    printf("V2 merged:\t");
    printArray(arr3, size1+size2);

    concatArraysV3( arr1, size1, arr2, size2, ptrM );
    printf("V3 merged:\t");
    printArray(ptrM, size1+size2);
    free(ptrM);
    return 0;
}
```

### 14.3 Alıştırma: sıralı iki diziyi sıralı birleştirmek

Aradan sonra hoca bir alıştırma bıraktı. `arr1` ve `arr2` kendi içlerinde sıralıdır. Fonksiyon, ikinci diziyi birincinin sonuna eklemek yerine, ikisini sıralı biçimde birleştirmelidir. Beklenen sonuç: 1, 2, 5, 6, 7, 8, 12, 19, 28 (ekrandan, 01:50:00; hoca bu sırayı ekranda yazmaya başlamıştı). Çözüm "Örnek Sorular" bölümündedir.

## 15. main Fonksiyonunun Argümanları

`main` de bir fonksiyondur ve parametre alır. Bu parametreler nereden gelir ve `main` onları nasıl kullanır? Slayttaki açıklama şöyledir (ekrandan, 02:00:00):

- Her C programı `main()` adlı bir fonksiyon içermelidir; bu, programda her zaman ilk çalışan fonksiyondur.
- `main()` dönünce program biter.
- Derleyici `main()`'i diğer fonksiyonlar gibi ele alır; tek fark, çalışma anında iki argümanı sağlamaktan çalıştıran ortamın (host environment) sorumlu olmasıdır.
- `argc`: komut satırında verilen argümanların sayısı.
- `argv`: komut satırı argümanlarını gösteren işaretçiler dizisi.

Hoca bunu bir önceki saatle bağladı: bir fonksiyona dizi ya da işaretçi aktarılınca kaç eleman olduğunun da verilmesi gerekiyordu. `main` de böyledir. Programın ilk komutu bile çalışmadan önce programa bilgi aktarılmak istenirse bu `main`'in parametreleri üzerinden yapılır. Birinci parametre kaç argüman aktarıldığıdır; ikincisi argümanların kendisidir ve bir karakter katarı işaretçileri dizisidir. Yani komut satırında aralarında boşluk bırakılarak yazılan her argüman bir katar olarak gelir.

Slayttaki kod verilen bütün argümanları her biri yeni satırda olacak biçimde ekrana yazar (ekrandan, 02:00:00 ve 02:05:00). Ekrandaki kodda yalnız `stdio.h` vardı; `exit` için `stdlib.h` eklendi. gcc -Wall ile derlendi ve çalıştırıldı:

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    while(--argc > 0 )
        printf("%s\n", *++argv);
    exit(0);
}
```

Derste program Dev-C++'ta "Project 2" olarak derlendi ve komut satırından çalıştırıldı. Boşluk içeren yol adlarından kaynaklanabilecek sorunlardan kaçınmak için çalıştırılabilir dosya kısa adlı bir kopyaya alındı. `ali veli 49 50` gibi dört argümanla çalıştırılınca dört argüman ayrı satırlarda yazıldı; argümansız çalıştırılınca hiçbir şey yazılmadı. <!-- BELİRSİZ: argümanların tam yazımı altyazıda "Aliveli4950" olarak geçiyor; hoca dört argüman verdiğini söylüyor -->

Kodun çalışması:

- `argv[0]` çalıştırılabilir dosyanın adıdır; programa verilen ilk argüman `argv[1]`'dedir.
- `--argc > 0`: sayaç önce azaltılır, sonra sınanır. Böylece program adı sayılmaz ve döngü verilen argüman sayısı kadar döner.
- `*++argv`: `argv` önce bir artırılarak `argv[1]`'i gösterir hâle gelir, `*` ile o katar alınır ve `%s` ile yazdırılır. `++` yıldızdan önce devreye girdiği için `argv[0]` atlanır.
- `argc` 0'a ulaşınca döngü biter.

Hoca bu yazımın kriptik olduğunu kabul etti ve daha "düz mantık" bir sürüm yazdı:

```c
#include <stdio.h>

int main(int argc, char *argv[]){
    int i;
    for( i=0; i<argc; i++ )
        printf("%s\n", argv[i]);
    return 0;
}
```

Hoca `argv[i]`'nin başına yıldız gerekip gerekmediğinden emin olmadığını söyleyip denedi; gerekmez, çünkü `argv[i]` zaten bir katarın başlangıç adresidir ve `%s` bunu bekler. Bu sürüm 0'dan başladığı için önce `argv[0]`'ı, yani çalıştırılabilir dosyanın adını yazdı. Yani `main` kendisini çalıştıran dosyanın adını bile öğrenebilir. Bu sürüm de gcc -Wall ile derlendi ve çalıştırıldı.

Daha karmaşık argüman verme mantıkları da kurulabilir. Örneğin `ogrenci=Ali` gibi bir argüman verilirse program `argv[1]`'in bu biçimde geldiğini bilip `=` işaretinin sağını almalıdır; `not1=9` gibi bir argümanda ise sağ taraf sayıya çevrilmelidir. Derste ise bütün argümanlar olduğu gibi tek parça katar olarak yazdırıldı.

**Soru:** `argv`'nin ilk elemanı (indis 0) dosya adı mıdır?

**Cevap:** Evet. Hoca soruyu, az önce anlattığı ve gösterdiği için yanıtlanmış saydı. <!-- BELİRSİZ: altyazıda soru metni bozuk -->


Slaytta `getopt` ve benzeri seçenek ayrıştırma araçları da vardı; hoca isteyenlerin bakabileceğini söyleyip bu konuya girmedi.

## Örnek Sorular

**Soru 1** (ekrandan, 00:10:00): `increaseRegular` / `increasePointer` programı (Bölüm 2.1) ne yazar?

Çözüm (derste verildi): `increaseRegular finishes with 8`, `main says the value is 3`, `increasePointer finishes with 8`, `main says the value is 8`. Değerle aktarılan `aa` kopyadır; işaretçiyle aktarılan `*aa` doğrudan `a`'nın bellek gözüdür.

**Soru 2** (ekrandan, 00:20:00): İki tam sayı parametrenin değerlerini değiştiren bir fonksiyon yazın. Fonksiyon dönünce `a`'nın değeri `b`'de, `b`'nin değeri `a`'da olmalıdır.

Çözüm (derste verildi): Değişikliğin main'e yansıması için parametreler işaretçi olmalıdır: `void swapPointer( int *aa, int *bb ) { int tmp = *aa; *aa = *bb; *bb = tmp; }` ve çağrı `swapPointer(&a, &b);`. `a = 3, b = 5` için işaretçisiz sürümden sonra `3 5`, işaretçili sürümden sonra `5 3` yazılır (Bölüm 6).

**Soru 3** (ekrandan, 02:10:00): Verilen `char` değişkenin alfabetik olup olmadığını denetleyen basit bir fonksiyon yazın. `a-z` ve `A-Z` denetlenmeli; alfabetikse 1, değilse 0 döndürülmeli.

> **Çözüm (derste verilmedi):** Aşağıdaki kod gcc -Wall ile derlendi ve çalıştırıldı; `'k'`, `'Q'`, `'5'`, `'#'` için çıktı `1 1 0 0` oldu.

```c
#include <stdio.h>

int isAlphabetic( char c ) {
    if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') )
        return 1;
    return 0;
}

int main(void){
    printf("%d %d %d %d\n", isAlphabetic('k'), isAlphabetic('Q'), isAlphabetic('5'), isAlphabetic('#'));
    return 0;
}
```

**Soru 4** (ekrandan, 00:30:00 ve 01:20:00): `#define SIZE_OF_ARRAY(x) (sizeof(x) / sizeof((x)[0]))` makrosu `int arr1[] = {1,5,7,19};` için main içinde ve `int arr1[]` parametresi alan bir fonksiyon içinde hangi sonucu verir?

Çözüm (derste verildi): main içinde 4. Fonksiyon içinde dizi işaretçi olarak ele alındığı için `sizeof(arr1)` işaretçinin boyutudur; derste 1 çıktı. 64 bitlik sistemde gcc ile 2 çıkar. Her iki durumda da eleman sayısı elde edilmez.

**Soru 5** (derste sözlü, 00:41:14): `#define SIZE 4;` yazılan programda derleyici makronun kullanıldığı satırlarda `parse error` verdi. Neden?

Çözüm (derste verildi, bir öğrenci fark etti): Makro tanımı noktalı virgülle bitmez. `;` makronun gövdesine dahil olur ve `SIZE` geçen her yere `4;` olarak yapıştırılır; örneğin `swapArrayElement( dizi, 0, SIZE-1, SIZE );` satırı `swapArrayElement( dizi, 0, 4;-1, 4; );` hâline gelir.

**Soru 6** (derste sözlü, 01:23:42): Fonksiyonun içinde `malloc` ile bellek ayırdık; orada `free` gerekir mi?

Çözüm (derste verildi): Gerekmez, yapılmamalıdır da. Fonksiyon içinde `free` yapılırsa döndürülen işaretçi serbest bırakılmış alanı gösterir. Bir `malloc` için bir `free` yapılır ve bu, iş bittiğinde main'de yapılır.

**Soru 7** (derste sözlü, 01:49:09): Kendi içinde sıralı `arr1 = {1,5,7,19}` ve `arr2 = {2,6,8,12,28}` dizilerini alıp sıralı birleşimini döndüren bir fonksiyon yazın (dizileri ekrandan, 01:50:00).

> **Çözüm (derste verilmedi):** Fonksiyon `concatArraysV1` gibi `malloc` ile yer ayırıp işaretçi döndürür; iki dizinin başındaki elemanları karşılaştırıp küçük olanı alır, dizilerden biri bitince ötekinin kalanını ekler. Aşağıdaki kod gcc -Wall ile derlendi ve çalıştırıldı; çıktı `1 2 5 6 7 8 12 19 28` oldu.

```c
#include <stdio.h>
#include <stdlib.h>

int* mergeSorted( int arr1[], int size1, int arr2[], int size2 ) {
    int *merged = (int*) malloc( (size1+size2)*sizeof(int) );
    int i = 0, j = 0, k = 0;
    if( merged == NULL )
        return NULL;
    while( i < size1 && j < size2 ) {
        if( arr1[i] <= arr2[j] )
            merged[k++] = arr1[i++];
        else
            merged[k++] = arr2[j++];
    }
    while( i < size1 )
        merged[k++] = arr1[i++];
    while( j < size2 )
        merged[k++] = arr2[j++];
    return merged;
}

int main(void){
    int arr1[] = {1,5,7,19}, arr2[] = {2,6,8,12,28};
    int i, *m = mergeSorted(arr1, 4, arr2, 5);
    if( m == NULL )
        return 1;
    for( i=0; i<9; i++ )
        printf("%d ", m[i]);
    printf("\n");
    free(m);
    return 0;
}
```

**Soru 8** (ekrandan, 02:05:00): `while(--argc > 0) printf("%s\n", *++argv);` içeren program `ali veli 49 50` argümanlarıyla çalıştırılırsa ne yazar? Argümansız çalıştırılırsa?

Çözüm (derste verildi): `ali`, `veli`, `49`, `50` ayrı satırlarda yazılır. `argv[0]` (program adı) önce artırma yapıldığı için yazılmaz. Argümansız çalıştırılınca `argc` 1'dir, `--argc` 0 olur ve hiçbir şey yazılmaz.

## Dersin Toparlaması

Bu derste C'de fonksiyonlara parametre aktarımının iki biçimi ayrıldı. Varsayılan değerle aktarımda fonksiyon parametrenin kopyasıyla çalışır ve değişiklik fonksiyon bitince kaybolur. Referansla aktarımda değişkenin adresi verilir ve fonksiyon `*` ile o adrese yazdığı için değişiklik kalıcı olur. `increaseRegular`/`increasePointer` ve `swapRegular`/`swapPointer` örnekleri bu farkı doğrudan gösterdi. Fonksiyon tanımı, anma ve çağrı kavramları ile faktöriyelde taşma sorunu da hatırlatıldı.

Ardından diziler ele alındı. Diziler fonksiyona `int ar[]` ya da `int *ar` biçiminde, boyut ayrı parametre olarak verilerek aktarılır; dizi aslında başlangıç adresi olarak gittiği için fonksiyonda elemanlara yapılan değişiklik çağıranda görünür. Bu nedenle `SIZE_OF_ARRAY` makrosu fonksiyon içinde çalışmaz. C'de fonksiyon dizi döndüremez. Ya fonksiyon içinde `malloc` ile yer ayrılıp işaretçi döndürülür ve iş bitince main'de `free` yapılır (`concatArraysV1`), ya da sonucun yazılacağı dizi ya da işaretçi çağıran tarafından verilir (`concatArraysV2`, `concatArraysV3`). Son olarak `main(int argc, char *argv[])` ile komut satırından programa argüman aktarımı gösterildi: `argc` argüman sayısını, `argv` katarları tutar ve `argv[0]` program adıdır. Hoca bu dersle fonksiyonlar konusunu bitirdiğini, sıralı birleştirme alıştırmasını ve V3'teki sorunu sonraki derste kısaca ele alabileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
