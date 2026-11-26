# Ders 4 Çalışma Özeti

## Genel Konular

- Uygulama dersinin yapısı
  - Bu kayıt bir uygulama (lab) oturumudur. Ekrandaki belgede iki soru vardır ve ikisi de Dev-C++ ortamında birlikte kodlanır (ekrandan, 00:15:00).
  - Soru 1: menülü bir hesap makinesi, işlemler için makrolar ve faktöriyel seçeneği. Soru 2: bir karakter dizisinde kullanıcıdan alınan kelimeyi arama.
- Menü, `while` döngüsü ve `switch-case`
  - Kullanıcının seçimi `int selection` değişkeninde tutulur, `switch(selection)` ile her işlem kendi `case` bloğuna gider (ekrandan, 00:20:00).
  - Her `case` bloğunun sonunda `break;` yazılır; yoksa akış sonraki `case` bloğuna geçer.
  - Programın her işlemden sonra yeniden menüye dönmesi için `switch` bir `while(run)` döngüsünün içine alınır. `run` başta 1'dir; çıkış seçeneğinde `run = 0;` yapılır ve döngü bir sonraki kontrolde biter (ekrandan, 00:25:00).
  - Tanımlı seçeneklerin dışındaki girişler `default:` bloğunda yakalanır ve "Geçerli bir giriş yapmadınız, lütfen tekrar deneyiniz.." uyarısı yazılır (ekrandan, 00:30:00).
  - Menü yazdırma ve `scanf("%d", &selection);` döngünün başına alınır, böylece her turda yeniden seçim okunur (ekrandan, 00:35:00).
- Türkçe karakterler için `setlocale`
  - `#include <locale.h>` eklenip `main` başında `setlocale(LC_ALL, "turkish");` çağrılırsa konsolda Türkçe karakterler görünür (ekrandan, 00:35:00).
- Makrolar ve kendi başlık dosyalarımız
  - İşlemler `calculations.h` adlı yeni bir başlık dosyasında `#define` ile makro olarak tanımlanır: `SUM`, `DIFFERENCE`, `PRODUCT`, `QUOTIENT` (ekrandan, 00:40:00 ve 00:50:00).
  - Başlık dosyası `#ifndef` / `#define` / `#endif` korumasıyla yazılır; Dev-C++ bu satırları dosya adına göre büyük harfle kendisi ekler.
  - Makro gövdesinde parametreler parantez içine alınır ki makroya ifade verildiğinde işlem önceliği bozulmasın.
  - Kendi başlık dosyamız köşeli parantezle değil çift tırnakla eklenir: `#include "calculations.h"`.
  - Menü de `menu.h` dosyasında çok satırlı bir makro (`MENU`) olarak yazılır; makro birden fazla satıra yayılırken her satırın sonuna ters bölü (`\`) konur. `main` içinde yalnız `MENU;` yazılır (ekrandan, 00:45:00).
- Faktöriyel seçeneği
  - Menüye 5. seçenek olarak faktöriyel eklenir, çıkış 6'ya kaydırılır (ekrandan, 00:50:00).
  - `result = x; y = x;` ile girilen değer saklanır, `while(x > 1){ result = result * --x; }` ile faktöriyel hesaplanır (ekrandan, 00:55:00).
  - `5! = 5 * 4 * 3 * 2 * 1 = 120` çıktısı için `y` üzerinden geriye sayan bir `for` döngüsü kurulur; `y == 1` olduğunda `= sonuç` yazılır, değilse `y *` yazılır.
- Karakter dizisinde kelime arama
  - Ana metin `char main_text[500] = "Ali ata bak, Dön git bir daha bak";`, aranan kelime `char searched[500];` dizisindedir; kelime `gets(searched);` ile okunur (ekrandan, 01:10:00).
  - Dizinin uzunluğu `while(main_text[i] != '\0') i++;` ile bulunur; dizinin sonunu `'\0'` karakteri gösterir.
  - Büyük-küçük harf farkını kaldırmak için iki dizi de `tolower()` ile küçük harfe çevrilir (`<ctype.h>`). Uzunluk bulma ve küçük harfe çevirme aynı döngüde yapılabilir (ekrandan, 01:15:00).
  - Arama döngüsü: `for(i = 0; i < main_text_length - searched_text_length + 1; i++)`, içinde `while((j<searched_text_length) && (searched[j] == main_text[i + j])) j++;`. `j == searched_text_length` olursa kelime bulunmuştur, konum yazılır ve sayaç (`control`) artırılır (ekrandan, 01:25:00).
  - Sonunda `control` 0 ise "bulunamadı", değilse kaç kez bulunduğu yazılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- `case` sonundaki `break`
  - `break` olmazsa `switch` bloğundan çıkılmaz, akış sonraki `case` bloklarına geçer.
- `while(1)` yerine koşul değişkeni
  - `while(1)` sonsuza kadar döner. Döngüyü kullanıcının isteğiyle bitirmek için koşul bir değişkene (`run`) bağlanır.
- `--x` ile `x--` farkı
  - `result = result * --x;` önce `x`'i azaltır, sonra kullanır; böylece ilk adımda 5 * 4 hesaplanır. `x--` yazılsaydı ilk adımda 5 * 5 hesaplanır, azaltma sonra olurdu.
- Arama sınırındaki `+ 1`
  - Aranan kelimenin uzunluğu kadar ileriye bakılacağı için döngü metnin sonuna kadar gitmez; `+ 1` uzunluk (size) ile indeks arasındaki farktan gelir. Aynı sınır `i <= main_text_length - searched_text_length` diye de yazılabilir.
- Makro parametre adları
  - Makrodaki parametre adları serbesttir; `SUM(x, y)` yerine `SUM(a, b)` da çalışır. Yeter ki gövdede aynı adlar kullanılsın.

## Kısa Tekrar Notları

- Menülü program iskeleti: `while(run) { menü; scanf; switch(selection) { case ...: ...; break; default: ...; } }`.
- Çıkış seçeneğinde `run = 0;` yapılır.
- `default:` tanımsız seçimleri yakalar.
- `#define SUM(x, y) ((x) + (y))` biçiminde makro; parametreler parantezli.
- Kendi başlık dosyası `#include "dosya.h"` ile eklenir.
- Çok satırlı makroda her satır sonu `\`.
- `result = result * --x;` önce azaltır, sonra çarpar.
- C dizgisinin sonu `'\0'` ile işaretlenir.
- `tolower()` `<ctype.h>` içindedir; büyük harfi küçültür, küçük harfi değiştirmez.
- Kaydırmalı arama: her başlangıç `i` için `searched[j] == main_text[i + j]` karşılaştırılır.
- Son başlangıç indeksi `metin uzunluğu - kelime uzunluğu` olur.

## Detaylı Açıklamalar

- Soru 1'in şartları (ekrandan, 00:15:00)
  - Program bir menü içermelidir (Toplama için 1, Çıkartma için 2, ..., Çıkış için Enter'a basınız vs.).
  - Her işlemin sonunda kullanıcı yeni bir işlem seçebilmeli ya da programı sonlandırabilmelidir.
  - Menüde geçerli bir sayı girilmediğinde kullanıcıdan yeni bir input istenmelidir.
  - Seçilen işlem için değerler kullanıcıdan input olarak alınmalıdır.
  - Her bir işlem için MACRO tanımlanmalıdır.
  - Ek: menüye faktöriyel seçeneği eklenmeli; input 5 olduğunda konsolda `5! = 5 * 4 * 3 * 2 * 1 = 120` görülmelidir.
- Menülü programın son hali
  - Aşağıdaki kod karelerden alındı (ekrandan, 00:45:00, 00:50:00, 00:55:00). `calculations.h` ve `menu.h` dosyalarının içi karelerde görünmedi; altyazıdaki anlatımdan kuruldu. Faktöriyel çıktısındaki `printf` satırları da altyazıdan tamamlandı. Kod `gcc -Wall` ile derlendi ve 5 + 5, 9 / 3 ve 5! girdileriyle çalıştırıldı; çıktılar `5 + 5 = 10`, `9 / 3 = 3`, `5! = 5 * 4 * 3 * 2 * 1 = 120` oldu.

```c
/* calculations.h */
#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#define SUM(x, y) ((x) + (y))
#define DIFFERENCE(x, y) ((x) - (y))
#define PRODUCT(x, y) ((x) * (y))
#define QUOTIENT(x, y) ((x) / (y))

#endif
```

<!-- BELİRSİZ: calculations.h ve menu.h içeriği karede görünmüyor; makro adları kareden, gövdeler ve menü satırları altyazıdan kuruldu. -->

```c
/* menu.h */
#ifndef MENU_H
#define MENU_H

#define MENU { \
    printf("Toplama için 1'e basınız.\n"); \
    printf("Çıkarma için 2'ye basınız.\n"); \
    printf("Çarpma için 3'e basınız.\n"); \
    printf("Bölme için 4'e basınız.\n"); \
    printf("Faktöriyel için 5'e basınız.\n"); \
    printf("Çıkış için 6'ya basınız.\n"); \
}

#endif
```

```c
/* main.c */
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

- Faktöriyel döngüsünün izlenmesi (x = 5)
  - Başta `result = 5`, `y = 5`.
  - `--x` ile x = 4, result = 20; x = 3, result = 60; x = 2, result = 120; x = 1, result = 120. `x > 1` artık sağlanmaz.
  - `for` döngüsü `y` = 5, 4, 3, 2 için `5 * 4 * 3 * 2 * ` yazar, `y == 1` olunca `1 = 120` yazar.
  - Derste önce `if(i == 1)` yazılmıştı; bir öğrencinin uyarısıyla `if(y == 1)` olarak düzeltildi (ekrandan, 00:55:00).
- Soru 2'nin şartları (ekrandan, 00:15:00)
  - Kullanıcıdan input olarak bir kelime alınmalıdır.
  - Arama yapılacak karakter dizisinin boyutu hesaplanmalıdır.
  - Arama yapılacak karakter dizisindeki büyük harfler küçük harflere çevrilmelidir.
  - Aranan kelimenin harfleri de küçük harfe çevrilmelidir.
  - Aranan kelime karakter dizisinde varsa hangi index aralığında olduğu belirtilmelidir.
  - Son olarak aranan kelimenin kaç defa tekrar edildiği belirtilmelidir.
- Arama programı
  - Kod karelerden alındı (ekrandan, 01:15:00, 01:25:00, 01:30:00). Ekrandaki ara sürümde boyut yazdıran satırlara ve döngü sınırına yanlışlıkla dizinin kendisi (`main_text`, `searched`) verilmişti; çalıştırınca anlamsız değerler çıkınca uzunluk değişkenleriyle düzeltildi. Son `if/else` bloğu ve indeks çıktısının `i+1` düzeltmesi altyazıdan tamamlandı. Kod `gcc -Wall` ile derlendi (yalnız `gets` için kullanım dışı uyarısı verdi) ve çalıştırıldı.

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

<!-- BELİRSİZ: Son if/else bloğundaki mesaj metinleri karede görünmüyor; altyazıdaki anlatımdan yazıldı. -->

- Arama sonuçları
  - Derste "Ali" (büyük harfle de) arandığında 1 ile 3 arasında, 1 adet bulundu. "bak" arandığında 9-11 ve 31-33 aralıklarında, 2 adet bulundu; metnin uzunluğu 33 olarak görüldü.
  - Derste önce `i` ile `i+j` yazdırılınca "0 ile 3" çıktı. Bunun yerine `i` ile `i+j-1` yazılırsa 0'dan başlayan indeksler (0-2), `i+1` ile `i+j` yazılırsa 1'den başlayan konumlar (1-3) elde edilir.
  - Ders sonrası not: Linux'ta UTF-8 kaynak dosyayla derlenince "ö" iki bayt tuttuğu için metin uzunluğu 34, ikinci "bak" 32-34 çıkar. Derste görülen 33 ve 31-33 değerleri, Türkçe karakterin tek bayt tuttuğu Windows kod sayfasıyla elde edilir (Windows-1254 ile derlenerek doğrulandı).
- Aramanın döngü sınırı
  - Örnek "ali ata bak" (uzunluk 11) ve "ali" (uzunluk 3): `11 - 3 + 1 = 9`, yani `i` 0'dan 8'e kadar gider. 8. indeksten başlayan "bak" son üç karakteri kapsar; daha ileriden başlayan bir eşleşme metne sığmaz.
  - Ders sonrası not: Derste sınır tartışılırken bir noktada `i`'nin 7'ye kadar gittiği söylendi; `+ 1` ile birlikte son başlangıç indeksi 8'dir. `i <= 11 - 3` yazımı da aynı sonucu verir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
