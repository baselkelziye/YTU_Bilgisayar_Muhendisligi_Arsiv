# Ders 4 Genişletilmiş Notu: Uygulama 1: Menülü Hesap Makinesi, Makrolar ve Karakter Dizisinde Kelime Arama

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Uygulama Oturumu ve Sorular
- 2. Soru 1: Menü İskeleti ve switch-case
- 3. Menüyü Sürekli Çalıştırmak: while(run)
- 4. Geçersiz Giriş ve Türkçe Karakterler
- 5. Kullanıcıdan Değer Almak ve İlk Deneme
- 6. İşlemleri Makroya Taşımak: calculations.h
- 7. Çok Satırlı Makro: menu.h
- 8. Faktöriyel Seçeneği
- 9. Soru 2: Karakter Dizisinde Kelime Arama
- 10. Uzunluk Bulma ve Küçük Harfe Çevirme
- 11. Arama Döngüsü ve Sınır Hesabı
- 12. Programı Çalıştırma ve Çıktıyı Düzeltme
- Örnek Sorular

## 1. Uygulama Oturumu ve Sorular

Bu kayıt Yapısal Programlama dersinin ilk uygulama (lab) oturumudur. Oturumda iki soru hazırlanmış ve ikisi de Dev-C++ ortamında öğrencilerle birlikte adım adım kodlanmıştır. Amaç bir problemi çözerken nasıl düşünüleceğini ve nasıl ilerleneceğini göstermektir. Sorular derste hızlıca geçilmiş ya da henüz gelinmemiş bazı konulara (makrolar, karakter dizileri gibi) değinir; bunun önemli olmadığı, soruların aşinalık kazanmak için hazırlandığı söylenir.

Ekranda gösterilen belgedeki iki soru şunlardır (ekrandan, 00:15:00):

**Soru 1:** Temel matematik işlemlerini yapabilen programı aşağıdaki şartları sağlayacak şekilde C programlama dilinde kodlayacağız.

1. Program bir menü içermelidir. (Toplama için 1, Çıkartma için 2, .., Çıkış için Enter'a basınız. vs.)
2. Her işlemin sonunda kullanıcı yeni bir işlem seçebilmeli ya da programı sonlandırabilmelidir.
3. Menüde geçerli bir sayı girilmediğinde kullanıcıdan yeni bir input istenmelidir.
4. Seçilen işlem için değerler kullanıcıdan input olarak alınmalıdır.
5. Her bir işlem için MACRO tanımlanmalıdır.

Şimdi menüye faktöriyel hesaplama seçeneği ekleyelim. Konsol ekranında input 5 olduğunda "5! = 5 * 4 * 3 * 2 * 1 = 120" çıktısını görecek şekilde kodlama yapalım.

**Soru 2:** Bir karakter dizisi içerisinde kullanıcıdan alınan kelimeyi arayan programı aşağıdaki şartları sağlayacak şekilde C programlama dilinde kodlayacağız.

1. Kullanıcıdan input olarak bir kelime alınmalıdır.
2. Arama yapılacak karakter dizisinin boyutu hesaplanmalıdır.
3. Arama yapılacak karakter dizisindeki büyük harfler küçük harflere çevrilmelidir.
4. Aranan kelimenin harfleri de küçük harfe çevrilmelidir.
5. Eğer aranan kelime karakter dizisinde varsa hangi index aralığında olduğu belirtilmelidir.
6. Son olarak karakter dizisinde aranan kelime kaç defa tekrar edilmiş belirtilmelidir.

Şartlar tek tek okunurken şu yorumlar yapılır: ikinci madde, programın bir işlemden sonra kapanmayıp kullanıcı çıkmak isteyene kadar menüyü yeniden göstermesi demektir; kullanıcı her işlem için programı yeniden çalıştırmak zorunda kalmamalıdır. Üçüncü madde, örneğin dört işlem tanımlıyken kullanıcı tanımsız bir sayı girerse bunun için ayrı bir durum hazırlanması gerektiğini söyler. Dördüncü madde programın statik olmadığını, kullanıcının kendi değerlerini girerek dinamik biçimde kullanacağını belirtir.

## 2. Soru 1: Menü İskeleti ve switch-case

Kodlamaya yeni bir proje açılarak başlanır. İlk adım menüdür. Kullanıcının yaptığı seçim bir değişkende tutulacak ve `switch` ifadesine bu değişken verilecektir. Bu değişkene `selection` adı verilir. Dört işlem yapılacağı için dört `case` gerekir: toplama 1, çıkarma 2, çarpma 3, bölme 4. İlk iskelet şöyledir (ekrandan, 00:20:00):

```c
int main() {
    int selection;

    switch(selection){
        case 1:
            break;

        case 2:
        case 3:
        case 4:

    }

    return 0;
}
```

`selection` 1 olduğunda akış `case 1:` bloğuna girer ve altındaki işlemleri yapar. Bir `case` bloğundaki işlemler bittikten sonra `break;` yazılmalıdır; böylece program `switch` bloğundan çıkar. Ardından çıkış için bir seçenek daha gerektiği fark edilir ve `case 5:` eklenir.

> **Hocanın vurgusu:** Her `case` bloğunun sonunda işlemler tamamlandıktan sonra `break` komutu bulunmalıdır ki `switch-case` yapısından çıkılabilsin.

> **Ek bilgi (derste anlatılmadı):** `break` yazılmayan bir `case` bloğunda akış bir sonraki `case` etiketine düşer (fall-through) ve oradaki komutlar da çalışır. Bu bazen bilerek kullanılır, örneğin birkaç seçeneğin aynı işi yapması istendiğinde `case` etiketleri art arda yazılır.

## 3. Menüyü Sürekli Çalıştırmak: while(run)

İkinci şart, menünün her işlemden sonra yeniden etkin olmasıdır. Bunun için `switch` bloğunun dışına bir döngü konması gerekir. Öğrencilere `while` ve `for` döngülerinden hangisinin uygun olduğu sorulur. Kullanıcı çıkmak isteyene kadar çalışacak bir döngü istendiği için `while` seçilir.

`while(1)` yazılırsa döngü sonsuza kadar çalışır. Oysa döngünün koşulu değiştirilebilmelidir. Bu yüzden `run` adlı, başlangıç değeri 1 olan bir değişken tanımlanır ve `while(run)` yazılır. Döngü içinde bir koşulda `run` sıfıra çekilirse döngü bir sonraki kontrolde çalışmaz. Kullanıcı çıkış seçeneğini seçtiğinde yapılacak iş budur (ekrandan, 00:25:00):

```c
int main() {
    int selection, run = 1;

    while(run){
        switch(selection){
            case 1: //Toplama
                break;
            case 2: // Çıkarma
                break;
            case 3: // Çarpma
                break;
            case 4: // Bölme
                break;
            case 5: // Çıkış
                run = 0;
                break;
            default:
                printf("Geçe")
        }

    }
}
```

`case 5` içinde `run = 0;` yapılıp `break;` ile `switch`'ten çıkıldığında işletilecek başka satır kalmaz; akış `while`'ın başına döner, koşulu kontrol eder, `run` sıfır olduğu için döngü biter ve program döngüden sonraki satırlarla devam eder.

## 4. Geçersiz Giriş ve Türkçe Karakterler

Üçüncü şart için, 1-5 dışındaki her girişi yakalayacak bir durum gerekir. `switch` yapısında bunun için `default:` etiketi kullanılır. Tanımlı girişlerin dışında bir değer gelirse kullanıcıya nasıl devam edeceğini anlatan bir uyarı yazılır (ekrandan, 00:30:00):

```c
default:
    printf("Geçerli bir giriş yapmadınız, lütfen tekrar deneyiniz.. \n");
```

Konsolda Türkçe karakterler normalde düzgün görünmez. Bunu düzeltmek için `#include <locale.h>` eklenir ve `main` başında `setlocale(LC_ALL, "turkish");` çağrılır. Bundan sonra Türkçe karakterli metinler konsolda doğru yazılır (ekrandan, 00:35:00).

## 5. Kullanıcıdan Değer Almak ve İlk Deneme

Makrolara geçmeden önce işlemler `case` blokları içinde doğrudan yazılır. Dört işlemin her biri için en az iki girdi gerekir. Bu yüzden `x` ve `y` adlı iki değişken tanımlanır; ilk değer vermeye gerek yoktur, çünkü değerler kullanıcıdan alınacaktır. Sonuç için de `result` değişkeni tanımlanır. Toplama bloğu şöyle yazılır (ekrandan, 00:30:00):

```c
case 1: //Toplama
    printf("input 1 : ");
    scanf("%d", &x);
    printf("input 2 : ");
    scanf("%d", &y);
    result = x+y;
    print("%d + %d = %d\n", x, y, result);
    break;
```

Bu ara sürümde iki hata vardır. Birincisi, menü ve `scanf("%d", &selection);` döngünün dışına yazılmıştır; oysa her turda yeniden seçim okunmalıdır. Okuma ve menü yazdırma döngünün başına alınır. İkincisi, bir öğrenci 21. satırda `printf` yerine `print` yazıldığını fark eder ve hata düzeltilir.

Düzeltilmiş sürüm ekranda şöyledir (ekrandan, 00:35:00):

```c
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "turkish");
    int selection, run = 1, x, y, result;

    while(run){
        printf("Toplama için 1'e basınız.\n");
        printf("Çıkarma için 2'ye basınız.\n");
        printf("Çarpma için 3'e basınız.\n");
        printf("Bölme için 4'e basınız.\n");
        printf("Çıkış için 5'e basınız.\n");
        scanf("%d", &selection);
        switch(selection){
            case 1: //Toplama
                printf("input 1 : ");
                scanf("%d", &x);
                printf("input 2 : ");
                scanf("%d", &y);
                result = x+y;
                printf("%d + %d = %d\n", x, y, result);
                break;
```

Program denenir: 1 seçilir, iki girdi olarak 5 ve 5 verilir, 10 sonucu görülür ve menü yeniden gelir; 5 seçilince program sonlanır. Toplama bloğu kopyalanarak çıkarma, çarpma ve bölme blokları yazılır, yalnız işlem satırı değişir. Çarpma için 5 ve 3 girilince 15 sonucu alınır. Tanımsız bir değer olarak 9 girildiğinde "Geçerli bir giriş yapmadınız" uyarısı çıkar ve menü yeniden basılır.

**Soru:** Çıkış için 5 yerine Enter'a basılmasını nasıl sağlayabiliriz? **Cevap:** Enter'ın ASCII tablosundaki değeri okunup o değer çıkış `case`'ine yazılırsa Enter'a basıldığında çıkış yapılır.

> **Ders sonrası not:** Bu cevap tek başına yetmez. `scanf("%d", ...)` bir tam sayı bekler ve boş satırı (yalnız Enter) sayı olarak okumaz, bir sonraki sayıyı beklemeye devam eder. Enter ile çıkmak için seçim karakter olarak okunmalıdır (örneğin `getchar()` ile); Enter'ın ürettiği satır sonu karakteri `'\n'`, ASCII değeri 10'dur.

## 6. İşlemleri Makroya Taşımak: calculations.h

Beşinci şart her işlem için bir makro tanımlanmasıdır. Makrolar ayrı bir başlık dosyasında, yani kendi tanımladığımız bir kütüphanede yazılır. Dev-C++'ta File > New Source File ile yeni dosya açılır ve `calculations.h` adıyla kaydedilir.

Başlık dosyasının başına `#ifndef` ve `#define`, sonuna `#endif` yazılır. Bu satırlar bazı derleyicilerde hazır gelir; Dev-C++ ise bunları dosya adına göre büyük harflerle (`CALCULATIONS_H`) kendisi oluşturur. Makrolar bu iki satırın arasına yazılır.

Makro tanımında `#define` kullanılır, ardından makronun adı ve parantez içinde alacağı parametreler gelir. Makro tek satırda yazılabiliyorsa başka bir şeye gerek yoktur. Sayıların sonradan sorun çıkarmaması için gövdede `x` ve `y` parametreleri parantez içinde kullanılır. Makro adları karelerde `SUM`, `DIFFERENCE`, `PRODUCT` ve `QUOTIENT` olarak görülür (ekrandan, 00:40:00 ve 00:50:00). Dosya içeriği karede görünmediği için aşağıdaki gövdeler anlatımdan kurulmuştur:

```c
#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#define SUM(x, y) ((x) + (y))
#define DIFFERENCE(x, y) ((x) - (y))
#define PRODUCT(x, y) ((x) * (y))
#define QUOTIENT(x, y) ((x) / (y))

#endif
```

<!-- BELİRSİZ: calculations.h dosyasının içi karede görünmüyor; makro gövdelerinin dış parantezleri altyazıdan kesin çıkmıyor. -->

Kendi tanımladığımız başlık dosyası `main.c` içine köşeli parantezle değil çift tırnakla eklenir: `#include "calculations.h"`. Ardından `case` bloklarındaki `result = x+y;` satırı silinir ve makro doğrudan `printf` içinde çağrılır (ekrandan, 00:40:00):

```c
printf("%d + %d = %d\n", x, y, SUM(x,y));
```

Başlık dosyası `main.c` ile aynı klasöre konup program çalıştırılır; 5 ve 2 girilince toplama makroyla yapılmış olur. Diğer işlemler de aynı şekilde makroya dönüştürülür. Artık kullanılmayan `result = x-y;` gibi satırlar silinir; kalsalar da sorun çıkarmazlar.

**Soru:** Makroda `SUM(x, y)` yerine `SUM(a, b)` deseydik de çalışır mıydı? Makrodaki x, y ile programdaki x, y birbirini nasıl buluyor? **Cevap:** İsimlerin önemi yoktur. Makro `a` ve `b` ile tanımlanıp denendiğinde program yine çalışır. Yalnız aynı makronun içinde parametreleri `x`, `y` diye tanımlayıp gövdede `a + b` yazmak çalışmaz; parametre adı ile gövdede kullanılan ad aynı olmalıdır.

> **Ek bilgi (derste anlatılmadı):** Makro bir fonksiyon değildir; önişlemci derlemeden önce `SUM(x,y)` yazısını gövdedeki metinle değiştirir. Parametrelerin parantezlenmesi bu yüzden önemlidir: `#define PRODUCT(x, y) x * y` tanımında `PRODUCT(2 + 3, 4)` ifadesi `2 + 3 * 4` olur ve 14 verir; parantezli tanım `((2 + 3) * (4))` olur ve 20 verir.

## 7. Çok Satırlı Makro: menu.h

Menü de bir makroya taşınır. Bunun için `menu.h` adlı ikinci bir başlık dosyası açılır. Tanım yine `#define` ve makro adıyla başlar, ardından süslü parantez açılır. Makro birden fazla satıra yayıldığı için her satırın sonuna ters bölü (`\`) konur; derleyicinin sonraki satırı makronun parçası olarak görmesi için gereken tek fark budur. `main` içindeki menü `printf` satırları buraya taşınır. Dosya içeriği karede görünmediği için aşağıdaki biçim anlatımdan kurulmuştur (faktöriyel eklendikten sonraki hali):

```c
#define MENU { \
    printf("Toplama için 1'e basınız.\n"); \
    printf("Çıkarma için 2'ye basınız.\n"); \
    printf("Çarpma için 3'e basınız.\n"); \
    printf("Bölme için 4'e basınız.\n"); \
    printf("Faktöriyel için 5'e basınız.\n"); \
    printf("Çıkış için 6'ya basınız.\n"); \
}
```

<!-- BELİRSİZ: menu.h dosyasının içi karede görünmüyor; menü satırları main.c'deki ilk menüden ve altyazıdan kuruldu. -->

`main.c` içine `#include "menu.h"` eklenir ve döngünün başında yalnız `MENU;` yazılır (ekrandan, 00:45:00). İlk denemede bir yerde boşluk bırakıldığı için derleyici makroyu görmez; düzeltilince menü eskisi gibi çalışır.

<!-- BELİRSİZ: Boşluğun tam olarak nerede kaldığı altyazıdan ve karelerden anlaşılmıyor. -->

Bu noktada Soru 1'in beş şartı tamamlanmıştır: menü, sürekli döngü, geçersiz giriş kontrolü, kullanıcıdan girdi ve her işlem için makro.

## 8. Faktöriyel Seçeneği

Menüye faktöriyel hesabı eklenir. Faktöriyel `case 5` olur, çıkış `case 6`'ya kaydırılır ve menüde de buna göre değiştirilir. Kullanıcıdan `n` değeri istenir (ekrandan, 00:50:00):

```c
case 5:
    printf("n! , n değerini giriniz.");
    scanf("%d", &x);
```

Faktöriyeli hesaplanacak değer `x`'te tutulur. `x` hesap sırasında azaltılacağı için kullanıcının girdiği ilk değer `y` değişkenine kopyalanır; çıktıda `n! = n * (n-1) * ... * 1` yazdırılırken bu değer gerekecektir. Sonuç için `result` başta `x`'e eşitlenir.

Öğrencilere hesabın nereye kadar süreceği sorulur. Cevap: sayı 1'e ulaşana kadar; 1 ile çarpmanın bir anlamı yoktur. Bu yüzden döngü koşulu `x > 1` olur. Döngü gövdesi `result = result * --x;` şeklindedir (ekrandan, 00:55:00):

```c
result = x;
y = x;
while(x > 1){
    result = result * --x;
}
```

Burada `--x` ile `x--` arasındaki fark önemlidir. Örnek olarak `x = 5` alınır: `result` de 5'tir. `--x` önce azaltır sonra kullanır; ilk adımda `5 * 4` hesaplanır, istenen de budur. `x--` yazılsaydı önce mevcut değer kullanılır, ilk adımda `5 * 5` hesaplanır, azaltma sonra yapılırdı. Bu yüzden önden azaltma kullanılır.

Adım adım izlemesi (ara adım eklendi):

| Adım | `--x` sonrası x | result |
|---|---|---|
| Başlangıç | 5 | 5 |
| 1 | 4 | 20 |
| 2 | 3 | 60 |
| 3 | 2 | 120 |
| 4 | 1 | 120 |

`x` 1 olunca `x > 1` sağlanmaz ve döngü biter; `result` 120'dir.

Faktöriyel hesaplandı, ancak soru konsolda `5! = 5 * 4 * 3 * 2 * 1 = 120` ifadesinin görülmesini istiyor. Bunun için önce `printf("%d! = ", y);` ile başlık yazılır. Sonra `y`'yi 5'ten 1'e kadar azaltan bir `for` döngüsü kurulur: `for(y; y>0; y--)`. Döngüde iki durum vardır: `y` 1 değilken hep aynı şey, yani `y *` yazılır; `y` 1 olduğunda ise `1 = 120` yazılıp ifade bitirilir (ekrandan, 00:55:00 ve altyazı):

```c
printf("%d! = ", y);
for(y; y>0; y--)
{
    if(y == 1)
    {
        printf("%d = %d\n", y, result);
    }
    else
    {
        printf("%d * ", y);
    }
}
break;
```

Ekrandaki ilk yazımda koşul `if(i == 1)` idi. Bir öğrenci döngünün `y` üzerinden döndüğünü ve koşulun `y == 1` olması gerektiğini söyler; alışkanlıkla `i` yazıldığı belirtilerek düzeltilir. Program 5 ile denenir ve `5! = 5 * 4 * 3 * 2 * 1 = 120` çıktısı alınır; 6 ile çıkılır.

Bu soruyla görülenler özetlenir: makro tanımlama, iki ayrı başlık dosyasını ekleme, `while` ve `for` döngüleri.

Soru 1'in tamamı bir araya getirildiğinde `main.c` şöyledir. Kod karelerden (ekrandan, 00:45:00, 00:50:00, 00:55:00) ve altyazıdan birleştirildi, yukarıdaki iki başlık dosyasıyla `gcc -Wall` ile derlendi ve çalıştırıldı (`for(y; ...)` için yalnız "statement with no effect" uyarısı verdi). `5 + 5 = 10`, `9 / 3 = 3`, `5! = 5 * 4 * 3 * 2 * 1 = 120` çıktıları ve tanımsız seçimde uyarı alındı.

```c
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "calculations.h"
#include "menu.h"

int main() {
    setlocale(LC_ALL, "turkish");
    int selection, run = 1, x, y, result;

    while(run){
        MENU;
        scanf("%d", &selection);
        switch(selection){
            case 1: //Toplama
                printf("input 1 : ");
                scanf("%d", &x);
                printf("input 2 : ");
                scanf("%d", &y);
                printf("%d + %d = %d\n", x, y, SUM(x,y));
                break;
            case 2: // Çıkarma
                printf("input 1 : ");
                scanf("%d", &x);
                printf("input 2 : ");
                scanf("%d", &y);
                printf("%d - %d = %d\n", x, y, DIFFERENCE(x, y));
                break;
            case 3: // Çarpma
                printf("input 1 : ");
                scanf("%d", &x);
                printf("input 2 : ");
                scanf("%d", &y);
                printf("%d * %d = %d\n", x, y, PRODUCT(x, y));
                break;
            case 4: // Bölme
                printf("input 1 : ");
                scanf("%d", &x);
                printf("input 2 : ");
                scanf("%d", &y);
                printf("%d / %d = %d\n", x, y, QUOTIENT(x, y));
                break;
            case 5:
                printf("n! , n değerini giriniz.");
                scanf("%d", &x);
                result = x;
                y = x;
                while(x > 1){
                    result = result * --x;
                }
                printf("%d! = ", y);
                for(y; y>0; y--)
                {
                    if(y == 1)
                    {
                        printf("%d = %d\n", y, result);
                    }
                    else
                    {
                        printf("%d * ", y);
                    }
                }
                break;
            case 6: // Çıkış
                run = 0;
                break;
            default:
                printf("Geçerli bir giriş yapmadınız, lütfen tekrar deneyiniz.. \n");
                break;
        }
    }
    return 0;
}
```

> **Ek bilgi (derste anlatılmadı):** Bu faktöriyel kodu `n = 0` için `result = 0` bırakır ve `for` döngüsü hiç çalışmadığı için yalnız `0! = ` yazar; oysa tanım gereği $0! = 1$'dir. Ayrıca `int` ile en büyük doğru faktöriyel $12! = 479001600$'dür; $13!$ 32 bitlik `int` sınırını aşar.

## 9. Soru 2: Karakter Dizisinde Kelime Arama

Aradan sonra ikinci soruya geçilir. Bir karakter dizisi içinde kullanıcıdan alınan bir kelime aranacaktır. Önce metnin, sonra aranan kelimenin boyutu hesaplanır. İki metin de küçük harfe çevrilir; çünkü ASCII tablosunda her karakterin bir kodu vardır ve büyük B ile küçük b'nin kodları farklıdır. Aslında aynı harf olan bu karakterlerin eşleşebilmesi için büyük harfler küçüğe çevrilir. Kelime bulunursa hangi indeks aralığında olduğu ("3 ile 5 indeksleri arasında bulundu" gibi) ve sonunda kaç kez bulunduğu ("aradığınız kelime iki kez tekrar edilmiş" gibi) yazdırılır.

Başlangıç kodu ders arasında hazırlanmıştır (ekrandan, 01:10:00):

```c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "turkish");
    char main_text[500] = "Ali ata bak, dön git bir daha bak";
    char searched[500];
    int main_text_length, searched_text_length, i, j, control = 0;

    printf("Aramak istediğiniz kelimeyi giriniz : ");
    gets(searched);
```

Ana metin bilerek "bak" kelimesini iki kez içerir; "bak" arandığında programın iki tane bulduğunu göstermesi beklenir. `searched` dizisi kullanıcının aramak istediği kelimeyi tutar. İki metnin boyutu için `main_text_length` ve `searched_text_length`, döngülerde indeks olarak `i` ve `j`, bulunan kelime sayısı için de `control` değişkeni tanımlanır. `control` 0 ise kelime hiç bulunmamış, 1 ise bir kez, 2 ise iki kez bulunmuş demektir. Kelime kullanıcıdan `gets` fonksiyonuyla okunur; `gets` boşluklu bir satırı bütün olarak alabilir.

> **Ek bilgi (derste anlatılmadı):** `gets` dizinin boyutunu kontrol etmediği için taşmaya açıktır; C11 standardından çıkarılmıştır ve güncel derleyiciler uyarı verir. Yerine `fgets(searched, sizeof(searched), stdin);` kullanılır; bu durumda okunan satırın sonundaki `'\n'` karakterinin silinmesi gerekir.

## 10. Uzunluk Bulma ve Küçük Harfe Çevirme

Metnin uzunluğu için `i = 0` ile başlanır ve bir `while` döngüsü kurulur. Öğrencilere karakter dizisinin sonuna gelindiğinin nasıl anlaşılacağı sorulur. Bir öğrenci önce `\n` der, sonra `\0` olarak düzeltir: C'de karakter dizisinin sonu `'\0'` karakteriyle gösterilir. Döngü `main_text[i] != '\0'` olduğu sürece `i`'yi artırır ve sonunda `i` dizinin boyutunu verir.

İlk yazımda uzunluk ve küçük harfe çevirme iki ayrı döngüyle yapılır (ekrandan, 01:10:00):

```c
i = 0;
while(main_text[i] != '\0')
{
    i++;
}
main_text_length = i;
i = 0;
while(main_text[i] != '\0')
{
    main_text[i] = tolower(main_text[i]);
    i++;
}
```

İkinci döngüden önce `i` sıfırlanacağı için uzunluk önce `main_text_length` değişkenine kaydedilir. Küçük harfe çevirme için `tolower` fonksiyonu kullanılır: fonksiyona büyük harf verilirse küçüğünü döndürür, küçük harf verilirse değiştirmeden döndürür.

Program çalıştırılınca metnin küçük harfli hali görülür. Ardından iki döngünün aynı indekse kadar çalışıp aynı artırmayı yaptığı, aradaki tek farkın `tolower` satırı olduğu belirtilir. Bu satır ilk döngüye taşınınca ikinci döngüye gerek kalmaz. Aranan kelime için de aynı döngü yazılır; iki dizi ayrı uzunlukta olduğundan aynı döngüye konamazlar (ekrandan, 01:15:00):

```c
i = 0;
while(main_text[i] != '\0')
{
    main_text[i] = tolower(main_text[i]);
    i++;
}
main_text_length = i;
printf("Main Text küçük harflerle : %s \n", main_text);

i = 0;
while(searched[i] != '\0')
{
    searched[i] = tolower(searched[i]);
    i++;
}
searched_text_length = i;
printf("Searched Text küçük harflerle : %s", searched);
```

Hesap yaparken indekslerin nereye kadar gideceğini hayal edebilmek için iki metnin boyutunu ekrana yazdırmanın yararlı olacağı söylenir ve iki `printf` satırı eklenir.

## 11. Arama Döngüsü ve Sınır Hesabı

Arama için `i` sıfırlanır ve bir `for` döngüsü kurulur. Döngünün nereye kadar gideceği "Ali ata bak" örneği üzerinden çizilerek anlatılır (ekrandan, 01:20:00). Boşluklar da birer karakterdir. İndeksler 0'dan 10'a kadardır; bu yüzden metnin boyutu 11'dir. Aranan "ali" için boyut 3'tür.

Arama sırasında bir başlangıç noktasında "a" bulunduğunda, kelimenin boyutu kadar ilerisine bakılır. Metnin sonuna yaklaşınca kelimenin uzunluğu kadar ileriye bakmak artık mümkün değildir; metin biter. Bu yüzden döngü sınırında aranan kelimenin uzunluğu metin uzunluğundan çıkarılır:

```c
for(i = 0; i < main_text_length - searched_text_length + 1; i++)
```

Öğrencilere bu `+ 1`'in anlamı sorulur. Hesap: $11 - 3 = 8$. `+ 1` olmasaydı koşul `i < 8` olur ve `i` en çok 7'ye gider; oysa 8. indeksten başlayan üç karakter ("bak") de metnin içindedir. `+ 1` boyut ile indeks arasındaki farktan gelir. `+ 1` yazmak istenmezse koşul `i <= main_text_length - searched_text_length` yapılır; böylece 8. indekse de gelinir.

> **Ders sonrası not:** Anlatımın bir yerinde `+ 1` ile birlikte `i`'nin 7'ye kadar gittiği söylendi. Doğrusu: `i < 11 - 3 + 1` yani `i < 9` koşulunda `i` 0'dan 8'e kadar gider; son geçerli başlangıç indeksi $11 - 3 = 8$'dir.

Döngünün içinde her başlangıç noktası için `j = 0` alınır ve bir `while` döngüsüyle kelime harf harf karşılaştırılır. İki şart vardır: karakterlerin aynı olması ve kelimenin uzunluğunun aşılmaması. İkinci şart için örnek verilir: "bak" aranırken metinde "bakabilir misin" gibi bir ifade olsaydı ilk üç harf uyduğu için kontrol devam edebilirdi; bu yüzden `j` kelimenin uzunluğuyla sınırlanır. `j` aranan kelimedeki konumu, `i + j` ana metindeki o anki konumu gösterir; arama kaydırarak yapılır.

```c
for(i = 0; i < main_text_length - searched_text_length + 1; i++)
{
    j = 0;
    while((j<searched_text_length) && (searched[j] == main_text[i + j])){
        j++;
    }
    if(j == searched_text_length){
        printf("Aradığınız kelime %d -%d bulundu.", i, i+j);
        control++;
    }
}
```

`while` döngüsü bittiğinde `j` aranan kelimenin uzunluğuna eşitse bütün harfler eşleşmiş, yani kelime bulunmuştur. Bu durumda bulunduğu aralık yazdırılır ve `control` bir artırılır (ekrandan, 01:25:00). Aralığın uçları için öğrencilerden `i` ve `i + j` önerisi gelir; indekslerin 0'dan mı 1'den mi sayılacağı çalıştırınca kontrol edilecektir. Döngüden sonra `control` sıfırsa "bulunamadı", değilse kaç adet bulunduğu yazdırılır. `control` negatif olamaz, çünkü yalnız artırılır.

## 12. Programı Çalıştırma ve Çıktıyı Düzeltme

İlk çalıştırmada birkaç hata çıkar ve sırayla düzeltilir:

- Döngü sınırında `searched_text_length` yerine dizinin kendisi (`searched`) yazılmıştır; derleme hatası buradan gelir.
- Boyut yazdıran `printf` satırlarına uzunluk değişkenleri yerine diziler (`main_text`, `searched`) verildiği için anlamsız bir boyut görülür; uzunluk değişkenleri verilerek düzeltilir.
- Sondaki "kaç adet bulundu" mesajında 97 gibi anlamsız bir sayı çıkar. Bir öğrenci sorunun `else` bloğunda olduğunu söyler: `printf` içine `control` değeri verilmemiştir; eklenince düzelir.

Kontroller bitince ara çıktılar (küçük harfli metin, boyutlar) yorum satırı yapılır. "Ali" arandığında "0 ile 3 arasında bulundu, 1 adet" çıktısı alınır. Burada indeks hesaplandığı için ikinci uç `i + j - 1` yazılırsa 0 ile 2 arasında, yani gerçek indeksler elde edilir. Bunun yerine birinci uç `i + 1` yazılırsa "a" 1. harf, "i" 3. harf sayılır ve iki uç dengelenir. Bu ikinci yol seçilir, son satıra bir de `\n` eklenir.

Sonuç olarak "Ali" büyük harfle arandığında da bulunur: 1 ile 3 arasında, 1 adet. "bak" arandığında 9-11 ve 31-33 aralıklarında, 2 adet bulunur. Metnin uzunluğu 33 olduğundan son eşleşmenin metnin sonuna denk geldiği görülür.

Bir öğrencinin sorusu üzerine `tolower` fonksiyonunun `<ctype.h>` kütüphanesinde olduğu söylenir ve include satırlarına açıklama yazılır (ekrandan, 01:30:00):

```c
#include <ctype.h> // tolower() fonksiyonu için
#include <locale.h> // türkçe karakter için
```

Programın son hali, karelerden (ekrandan, 01:15:00, 01:25:00, 01:30:00) ve altyazıdan birleştirilerek aşağıdadır. Yorum satırı yapılan ara çıktılar çıkarılmıştır. Kod `gcc -Wall` ile derlendi (yalnız `gets` için uyarı verdi) ve "ali", "Ali", "bak" ve metinde olmayan bir kelimeyle çalıştırıldı.

```c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // tolower() fonksiyonu için
#include <locale.h> // türkçe karakter için

int main() {
    setlocale(LC_ALL, "turkish");
    char main_text[500] = "Ali ata bak, Dön git bir daha bak";
    char searched[500];
    int main_text_length, searched_text_length, i, j, control = 0;

    printf("Aramak istediğiniz kelimeyi giriniz : ");
    gets(searched);

    i = 0;
    while(main_text[i] != '\0')
    {
        main_text[i] = tolower(main_text[i]);
        i++;
    }
    main_text_length = i;

    i = 0;
    while(searched[i] != '\0')
    {
        searched[i] = tolower(searched[i]);
        i++;
    }
    searched_text_length = i;

    for(i = 0; i < main_text_length - searched_text_length + 1; i++)
    {
        j = 0;
        while((j<searched_text_length) && (searched[j] == main_text[i + j])){
            j++;
        }
        if(j == searched_text_length){
            printf("Aradığınız kelime %d -%d bulundu.\n", i+1, i+j);
            control++;
        }
    }
    if(control == 0)
        printf("Aradığınız kelime bulunamadı.\n");
    else
        printf("Aradığınız kelime %d adet bulundu.\n", control);

    return 0;
}
```

<!-- BELİRSİZ: Son if/else bloğu ve sonuç mesajlarının tam metni karede görünmüyor; altyazıdaki anlatımdan yazıldı. -->

> **Ders sonrası not:** Linux'ta UTF-8 kaynak dosyayla derlenince "ö" harfi iki bayt tuttuğu için metin uzunluğu 34, ikinci "bak" 32-34 aralığında çıkar. Derste görülen 33 ve 31-33 değerleri Türkçe karakterin tek bayt tuttuğu Windows kod sayfasıyla elde edilir (kaynak Windows-1254'e çevrilip derlenerek doğrulandı). Ayrıca `tolower` yalnız tek baytlık ASCII harflerini güvenle küçültür; "Ö", "İ" gibi harfler yerel ayara ve kodlamaya göre değişmeyebilir.

## Örnek Sorular

**Soru 1 (ekrandan, 00:15:00):** Temel matematik işlemlerini yapabilen bir C programı yazın: program bir menü içersin; her işlemden sonra kullanıcı yeni işlem seçebilsin ya da programı sonlandırabilsin; menüde geçerli bir sayı girilmezse yeni input istensin; seçilen işlemin değerleri kullanıcıdan alınsın; her işlem için MACRO tanımlansın. Sonra menüye faktöriyel seçeneği ekleyin; input 5 olduğunda konsolda `5! = 5 * 4 * 3 * 2 * 1 = 120` görülsün.

> **Çözüm:** Derste kodlandı; tam kod 8. bölümün sonundadır, makrolar 6. ve 7. bölümdedir. Ana fikir: `while(run)` içinde `MENU; scanf; switch(selection)`; çıkışta `run = 0;`, tanımsız seçimde `default:` uyarısı; işlemler `SUM`, `DIFFERENCE`, `PRODUCT`, `QUOTIENT` makrolarıyla; faktöriyel `result = result * --x;` döngüsü ve `y` üzerinden geriye sayan yazdırma döngüsüyle.

**Soru 2 (ekrandan, 00:15:00):** Bir karakter dizisi içerisinde kullanıcıdan alınan kelimeyi arayan bir C programı yazın: kelime kullanıcıdan alınsın; aranacak dizinin boyutu hesaplansın; dizideki ve aranan kelimedeki büyük harfler küçüğe çevrilsin; kelime varsa hangi indeks aralığında olduğu ve kaç kez tekrar edildiği yazdırılsın.

> **Çözüm:** Derste kodlandı; tam kod 12. bölümdedir. "Ali ata bak, Dön git bir daha bak" metninde "bak" için çıktı 9-11 ve 31-33, 2 adettir (Windows kod sayfasıyla).

**Soru 3 (derste sözlü, 00:21:16):** Menünün kullanıcı çıkmak isteyene kadar sürekli çalışması için `switch` bloğunun dışına ne konmalıdır; `while` mı `for` mu uygundur?

> **Cevap (derste verildi):** Bir `while` döngüsü. Koşul `while(1)` olursa döngü hiç bitmez; bu yüzden koşul `run` değişkenine bağlanır ve çıkış seçeneğinde `run = 0;` yapılır.

**Soru 4 (derste sözlü, 00:50:31):** Faktöriyel döngüsünde `result = result * --x;` mı, `result = result * x--;` mı yazılmalı? Döngü koşulu ne olmalı?

> **Cevap (derste verildi):** `--x`. `result` başta `x`'e (5) eşit olduğundan ilk adımda `5 * 4` hesaplanmalıdır; `--x` önce azaltıp sonra kullandığı için bunu sağlar, `x--` ise ilk adımda `5 * 5` hesaplar. Koşul `x > 1`'dir, çünkü 1 ile çarpmanın anlamı yoktur.

**Soru 5 (derste sözlü, 01:08:16):** Karakter dizisinin sonuna gelindiği hangi karakterden anlaşılır?

> **Cevap (derste verildi):** `'\0'` (null karakter). Uzunluk döngüsü `while(main_text[i] != '\0')` koşuluyla çalışır.

**Soru 6 (derste sözlü, 01:18:10):** `for(i = 0; i < main_text_length - searched_text_length + 1; i++)` satırındaki `+ 1` ne işe yarar? `+ 1` kaldırılmak istenirse satırda ne değiştirilmelidir?

> **Cevap (derste verildi):** `+ 1` boyut ile indeks arasındaki farktan gelir ve son geçerli başlangıç indeksinin ($11 - 3 = 8$) de denenmesini sağlar. `+ 1` kaldırılırsa `<` yerine `<=` yazılır: `i <= main_text_length - searched_text_length`.

**Soru 7 (derste sözlü, 00:33:54):** Çıkış için 5 yerine Enter'a basılması nasıl sağlanır?

> **Cevap (derste verilen):** Enter'ın ASCII değeri tablodan okunup çıkış `case`'ine yazılır.
>
> **Çözüm (derste verilmedi):** `scanf("%d", ...)` boş satırı sayı olarak okumadığı için seçim karakter olarak okunmalıdır. Örneğin `int c = getchar();` ile okunur; `c == '\n'` (ASCII 10) ise `run = 0;` yapılır, `'1'`-`'5'` arasındaysa `c - '0'` seçim olarak kullanılır. Sayı okunduktan sonra tampondaki satır sonu da ayrıca tüketilmelidir.

## Dersin Toparlaması

Bu uygulama oturumunda iki küçük ama eksiksiz C programı adım adım kuruldu. Birincisinde menülü bir hesap makinesi yazılırken `switch-case` yapısı, `break` ve `default` kullanımı, programı kullanıcı isteyene kadar döndüren `while(run)` deseni, `scanf` ile girdi alma ve `setlocale` ile Türkçe karakter desteği görüldü. İşlemler önce `case` bloklarında yazıldı, sonra kendi başlık dosyalarımızda tanımlanan makrolara taşındı; parametreli makro, `#ifndef` koruması, çift tırnakla `#include` ve ters bölüyle çok satırlı makro yazımı uygulandı. Faktöriyel eklenirken önden azaltma (`--x`) ile sonradan azaltma (`x--`) farkı somut bir örnekte gösterildi.

İkinci programda karakter dizileriyle çalışıldı: dizinin sonu `'\0'` ile bulunarak uzunluk hesaplandı, `tolower` ile büyük-küçük harf farkı kaldırıldı ve kaydırmalı karşılaştırmayla bir kelimenin metindeki bütün konumları ve tekrar sayısı bulundu. Döngü sınırındaki `+ 1` üzerinden boyut ile indeks farkı tartışıldı ve çıktının 0'dan mı 1'den mi sayılacağı `i + 1` düzeltmesiyle belirlendi. Bu iki örnek, ileride işlenecek karakter dizisi ve önişlemci konularına bir hazırlık niteliğindedir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
