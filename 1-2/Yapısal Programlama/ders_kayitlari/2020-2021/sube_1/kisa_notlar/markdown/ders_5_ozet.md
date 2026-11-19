# Ders 5 Çalışma Özeti

## Genel Konular

- Ön işlemci (preprocessor) komutları
  - `#` ile başlayan satırlar derleme başlamadan önce ön işlemci tarafından işlenir; komutun etkisi kaynak kodun geri kalanına uygulanır, sonra asıl derleme yapılır.
  - `#` satırdaki ilk boşluk olmayan karakter olmalıdır; önünde boşluk ya da sekme olabilir.
  - Ön işlemci komutu noktalı virgülle değil satır sonuyla biter. Komut bir satıra sığmıyorsa satır sonundan hemen önce ters bölü (`\`) konur (ekrandan, 00:10:00).
  - Ön işlemciyle yapılabilenler: tip tanımlamaları, kod kitaplıklarını ekleme (`#include`), makro tanımlama, koşullu derleme ve satır/dosya bilgisini koda yerleştirme.
- Makrolar (`#define`)
  - Derleyici makro adını gördüğü her yere makronun gövdesini yapıştırıyormuş gibi derler; kaynak dosya değişmez.
  - En basit kullanım sabit tanımlamaktır: `#define BUFLEN 512`. Değişkenden farkı, bellekte yer ayrılmamasıdır.
  - Makro tanımında satır sonuna `;` ve `=` konmaz (ekrandan, 00:15:00).
  - Fonksiyon benzeri makrolar parametre alır, ama parametrelerin türü belirtilmez ve denetlenmez (ekrandan, 00:15:00):
    - `#define MUL_BY_TWO(a) ((a) + (a))`; `j = MUL_BY_TWO(5);` ve `f = MUL_BY_TWO(2.5);` ikisi de geçerlidir.
    - `#define min(a, b) ( (a) < (b) ? (a) : (b))`
  - Gelenek olarak makro adları büyük harfle yazılır; zorunlu değildir ama kodda makroyu fonksiyondan ayırmayı kolaylaştırır.
- Makronun yan etkisi (side effect)
  - `a = min(b++, c);` ön işlemcide `a = ((b++) < (c) ? (b++) : (c));` olur (ekrandan, 00:20:00). Koşul doğruysa `b++` iki kez çalışır.
  - Derste Dev-C++ ile denendi: `x = 3, y = 10` için fonksiyon `min(x++, y)` 3 döndürür ve sonra `x` 4 olur; makro `MIN(x++, y)` 4 döndürür ve `x` 5 olur (ekrandan, 00:30:00).
- Makro ve fonksiyon karşılaştırması (ekrandan, 00:35:00)
  - Avantajlar: fonksiyon çağrısı ek yükü (yığında yeni bağlam açma) yoktur, genelde daha hızlıdır; tür kısıtı olmadığından tek makro birden çok veri türüne hizmet eder.
  - Dezavantajlar: argümanlar gövdede geçtiği her yerde yeniden değerlendirilir (yan etki); makro her kullanıldığı yerde açıldığı için çalıştırılabilir kod büyür; argüman sayısı denetlenir ama türü denetlenmez; ek bir çeviri katmanı olduğu için hata ayıklamak zordur.
  - Makro bir, en çok iki satırlık işler içindir. Daha uzunsa fonksiyon yazmak daha doğrudur.
- `#undef`
  - Bir makronun tanımını geri alır. Örnek: `FALSE` değerini 1 kabul eden bir kitaplık kodu ile 0 kabul eden başka bir kod için önce `#define FALSE 1`, sonra `#undef FALSE` ve `#define FALSE 0` yazılır.
- Hazır (built-in) makrolar (ekrandan, 00:40:00)
  - `__LINE__`: çağrıldığı satır numarası; `__FILE__`: dosyanın adı; `__TIME__` ve `__DATE__`: derlenme saati ve tarihi; `__STDC__`: derleyici ANSI standardına uyuyorsa 1.
  - `__LINE__` sayı olduğu için `%d`, `__FILE__`, `__DATE__`, `__TIME__` karakter katarı olduğu için `%s` ile yazdırılır.
- Koşullu derleme (conditional compilation) (ekrandan, 00:45:00)
  - Derlenmesi istenmeyen kod kısımlarını ayırır: `#if`, `#elif`, `#else`, `#endif`.
  - Hata ayıklama aşamasında kullanışlıdır; makro komut satırından tanımlanabilir: `gcc -DDEBUG=1 test.c`.
  - Koşulda parantez zorunlu değildir; süslü parantez kullanılmaz. Her `#if` bir `#endif` ile kapanır, tek bir `#else` olur ve en sonda yer alır.
  - Tanım denetimi: `#if defined TEST`, `#if defined (TEST)`, `#ifdef macro_name`, `#if !defined macro_name`, `#ifndef macro_name` (ekrandan, 00:50:00).
- `#include`
  - `<...>` ile verilen dosya işletim sisteminin varsayılan dizinlerinde aranır (Unix'te `/usr/include`); `"..."` ile verilen dosya önce kaynak dosyanın bulunduğu dizinde aranır.
  - Eklenecek kodun tanıtım dosyası (başlık dosyası) genelde `.h` uzantılıdır; fonksiyon imzaları burada verilir.
- Değişken kapsamı (scope) ve ömrü (duration)
  - Kapsam: bir değişken ya da fonksiyon adının geçerli ve erişilebilir olduğu kod bölgesidir. Ömür: değişkenin bellekte yer kapladığı süredir. Değişken bellekte dururken erişilemez olabilir.
  - Bir fonksiyon başka bir fonksiyonu çağırınca çağıranın yerel değişkenleri yığında durur ama erişilemez; çağrılan fonksiyon bitince onun bellek alanı yığından çekilir.
  - Yerel (otomatik) değişkenler bloğa her girişte yeniden ilk değer alır. `static` yerel değişken bir kez ilk değer alır ve değerini çağrılar arasında korur (sabit ömür).
  - `increment()` örneği: `int j = 1;` ve `static int k = 1;` ile üç çağrı `j:2 k:2`, `j:2 k:3`, `j:2 k:4` yazar (ekrandan, 01:30:00).
  - `static` yerel değişkenin global değişkene göre üstünlüğü: değişkenin denetimi yalnız o fonksiyondadır, başka fonksiyon değiştiremez (main'den erişim derleme hatası verdi).
  - Dört kapsam türü, kapsayıcıdan içe: program kapsamı, dosya kapsamı, fonksiyon kapsamı, blok kapsamı. İç kapsamda tanımlı değişkene dış kapsamdan erişilemez.
  - İç blokta aynı adla tanımlanan değişken dıştakini örter; içeriden dıştakine erişilemez.
- Global değişkenler (ekrandan, 01:50:00)
  - Mümkün olduğunca kaçınılmalıdır: bakımı zorlaştırır, karmaşıklığı artırır, modüller arasında çakışma yaratır.
  - Bildirimin iki türü vardır: tanım (definition) ve anma (allusion). `extern int j;` değişkenin başka yerde tanımlandığını bildirir, bellek ayırmaz.
- Saklama sınıfları ve niteleyiciler (ekrandan, 01:55:00)
  - `auto`: gereksizdir, nadiren kullanılır. `static`: fonksiyon içinde sabit ömür, fonksiyon dışında dosya kapsamı verir. `extern`: başka dosyada tanımlı değişken. `register`: değişkenin işlemci yazmacında tutulması için derleyiciye ipucudur, derleyici yok sayabilir. `const`: değeri değiştirilemez. `volatile`: derleyicinin bazı optimizasyonlarını kapatır.
- İşaretçilere giriş
  - `*` ile tanımlanan değişken işaretçidir; içinde bir bellek adresi tutar. `&` bir değişkenin adresini verir, `*p` işaretçinin gösterdiği adresteki değeri verir.
  - "Basics" örneği (ekrandan, 02:10:00): `short i, j, *p; i = 123; j = 321; p = &i; j = *p;` sonrası `i:123 j:123`; `i += 2; j += 3;` sonrası `i:125 j:126`. `i` ve `j` ayrı bellek gözleridir; `j = *p` yalnız değeri kopyalar.
  - Bellek tablosu (ekrandan, 02:25:00): `i` 1200, `j` 1202, `p` 1204 adresinde; `p` içinde 1200 yazar. Adres değerleri örnek içindir.
- Diziler
  - Tanım: tür, ad, köşeli parantez içinde boyut ve isteğe bağlı ilk değer listesi. İndisler 0'dan başlar (ekrandan, 02:35:00).
  - `int ar[5]; ar[0] = 15; ar[1] = 17; ar[3] = ar[0] + ar[1];` sonrası `ar[2]` ve `ar[4]` tanımsızdır; bellekte önceden kalan değeri taşır (ekrandan, 02:40:00).
  - İlk değer listesi eleman sayısından kısaysa kalan elemanlar 0 olur (derste denendi). Liste verilirse boyut yazılmayabilir ama köşeli parantez şarttır.
- Dizi elemanlarına işaretçiyle erişim (ekrandan, 02:50:00)
  - `p = &ar[0];` ile `p = ar;` aynıdır. `*(p+3)` ile `ar[3]` aynı bellek içeriğidir.
  - `p + 3` sayısal olarak 3 bayt değil, 3 eleman ilerler: `short` için 6 bayt.
  - Geçerli: `p = ar;`, `ar[1] = *(p+3);`, `p++;`. Geçersiz: `ar = p;`, `&p = ar;`, `ar++;`.

## Hocanın Özellikle Vurguladığı Kısımlar

- Makroların yan etkisi
  - Argümanda `++` gibi yan etkili bir ifade varsa makro beklenmedik sonuç verir. Bazen doğru bazen yanlış çalışan kodun hatasını bulmak çok zordur.
- Makrolardan mümkün olduğunca kaçınma
  - Dezavantaj tarafı çok daha ağırdır. Bellekten her baytın kazanılması gereken küçük IoT cihazları gibi özel durumlar dışında fonksiyon tercih edilmelidir.
- Global değişken kullanmama
  - Uzun kodda bir adın yerel mi dosya kapsamlı mı olduğunu düşünmek kodu anlamayı zorlaştırır.
- `static` ile denetimi tek fonksiyonda tutma
  - Çağrılar arasında korunması gereken değer (ör. bir listede en son okunan kaydın yeri) global yerine fonksiyon içinde `static` tanımlanabilir.
- İşaretçide `*` unutulmamalı
  - `j = *p` yerine `j = p` yazılırsa `j`'ye değer değil adres atanır (derleyici tür uyarısı verir).
- İşaretçi aritmetiğinde birim
  - `p + i` ifadesindeki `i` bayt değil eleman sayısıdır. İndis dizinin sınırını aşarsa bellekteki rastgele bir değer okunur.

## Kısa Tekrar Notları

- Ön işlemci komutu `#` ile başlar, satır sonuyla biter, devam için `\` kullanılır.
- Makroda `;` ve `=` yok; parametreler parantez içine alınır; tür denetimi yok.
- `min(b++, c)` makrosunda `b++` iki kez çalışabilir.
- Makro: hızlı, türden bağımsız. Fonksiyon: güvenli, kod tekrarı yok, hata ayıklaması kolay.
- `#undef` tanımı geri alır; yeniden tanımlamadan önce kullanılır.
- `__LINE__` (`%d`), `__FILE__`, `__DATE__`, `__TIME__` (`%s`), `__STDC__`.
- Koşullu derleme: `#if / #elif / #else / #endif`, `#ifdef`, `#ifndef`, `gcc -DDEBUG=1`.
- `#include <...>` sistem dizini, `#include "..."` kaynak dosyanın dizini.
- Kapsam: program > dosya > fonksiyon > blok. Ömür: bellekte kalma süresi.
- `static` yerel: bir kez ilk değer, değeri korunur. `static` global: dosya kapsamı.
- `register` ipucudur; `const` değiştirilemez; `volatile` optimizasyonu kapatır; `extern` başka yerde tanımlı.
- `p = &i` adres; `*p` değer; `j = *p` yalnız kopyalar.
- Dizide eksik ilk değerler 0 olur; hiç değer atanmamış yerel dizi elemanı tanımsızdır.
- `p = ar` geçerli, `ar = p` ve `ar++` geçersiz; `*(p+3) == ar[3]`.

## Detaylı Açıklamalar

- **Makro nasıl çalışır?** Ön işlemci, derleme öncesinde makro adının geçtiği her yere gövdeyi metin olarak koyar. Bu yüzden `#define BUFLEN 512` dendiğinde `BUFLEN` için bellekte değişken yeri ayrılmaz; derleyici doğrudan 512 sayısını görür. Fonksiyon benzeri makroda parametre adları da metin olarak değiştirilir. `MUL_BY_TWO(5)` ifadesi `((5) + (5))` olur. Parametrelerin türü olmadığı için aynı makro tam sayı ve ondalıklı sayıyla kullanılabilir. Buna karşılık yanlış türde bir argüman (ör. karakter) derleme hatası vermeden sessizce işlenebilir.
- **Yan etki örneği adım adım.** Derste yazılan kod (ekrandan, 00:30:00):

  ```c
  #include <stdio.h>
  #include <stdlib.h>
  #define MIN(a,b)  ((a) < (b) ? (a) : (b))

  int min( int a, int b ) {
      if( a < b ) return a;
      return b;
  }

  int main(int argc, char *argv[]){
      int x = 3, y = 10;
      printf("min: %d\n", MIN(x++,y));
      printf("x: %d\n",x);
      printf("y: %d\n",y);
      system("PAUSE");
      return 0;
  }
  ```

  - Fonksiyonla (`min(x++, y)`): fonksiyona `x`'in eski değeri 3 gider, `x` bir kez artıp 4 olur. Çıktı `min: 3`, `x: 4`, `y: 10`.
  - Makroyla (`MIN(x++, y)`): ifade `((x++) < (y) ? (x++) : (y))` olur. Koşulda 3 < 10 doğrudur ve `x` 4 olur; sonra seçilen dalda `x++` yeniden çalışır, 4 döner ve `x` 5 olur. Çıktı `min: 4`, `x: 5`, `y: 10`. Hoca derste aynı sonucu gösterdi.
  - Kod gcc -Wall ile derlendi ve çalıştırıldı (`system("PAUSE")` satırı Linux'ta çıkarılarak); iki sürüm de yukarıdaki çıktıyı verdi.
  - Ders sonrası not: Hoca bu farkı "makro yazımının önceliği daha düşük" diye açıkladı. Asıl neden öncelik değil, argümanın makro gövdesinde iki kez geçmesi ve bu yüzden iki kez değerlendirilmesidir (slayttaki ilk dezavantaj maddesi de budur).
- **Koşullu derleme örneği.** Derste yazılan kod (ekrandan, 01:10:00 ve 01:15:00):

  ```c
  #include <stdio.h>
  #include <stdlib.h>

  #define x 1

  void myFunc( );

  int main(int argc, char *argv[]){
      printf("main x: %d\n",x);
      myFunc( );
      return 0;
  }

  #if    x==1
      #undef  x
      #define     x   0
  #elif   x == 2
      #undef  x
      #define     x   3
  #else
      #define     y   4
  #endif

  void myFunc( ){
      printf("myFunc x: %d\n",x);
  }
  ```

  - Ön işlemci dosyayı yukarıdan aşağı işler. `main` derlenirken `x` yerine 1 konur. `#if` bloğu `main`'den sonra geldiği için `x`'i yalnız sonraki satırlar için 0 yapar. Çıktı `main x: 1`, `myFunc x: 0`. `x` 2 tanımlansaydı çıktı 2 ve 3 olurdu.
  - `x` 5 tanımlanınca ilk iki koşul tutmaz, `#else` dalı çalışır ve yalnız `y` 4 olarak tanımlanır: `main x: 5`, `myFunc x: 5`, `y` 4. `x` 1 iken `myFunc` içinde `y` kullanılırsa `y` tanımsız olduğu için derleme hatası alınır.
  - Kod gcc -Wall ile derlendi ve `x` 1, 2, 5 için çalıştırıldı; sonuçlar yukarıdaki gibidir. `x` 1 iken `y` kullanan sürüm "y undeclared" hatası verdi.
- **Kapsam ve ömür.** Kapsam bir adın nerede kullanılabildiğini, ömür değişkenin bellekte ne kadar kaldığını anlatır. `main` içinde `x = 5`, çağrılan fonksiyonda da `x = 3` tanımlıysa, çağrı sırasında `main`'in `x`'i yığında kalır ama erişilemez. Fonksiyon bitince onun alanı yığından çekilir; aynı fonksiyon yeniden çağrılınca oluşan `x` yepyeni bir değişkendir. `static` anahtar kelimesi bu davranışı değiştirir: değişken bir kez ilk değer alır ve programın sonuna kadar bellekte kalır. Derste yazılan kodda (ekrandan, 01:45:00) kapsamlar yorum olarak işaretlendi: `int g = 3; //program scope`, `static int s = 5; //file scope`, fonksiyon içindeki `int j` ve `static int k` için `//function scope`, `for` bloğundaki `int y = 4;` için `//block scope`.
- **`increment()` örneği.** Kod (ekrandan, 01:30:00):

  ```c
  #include <stdio.h>
  void increment ( void ) {
      int j = 1;
      static int k = 1;
      j++;
      k++;
      printf("j : %d\t k:%d\n", j, k);
  }
  int main ( void ) {
      increment();
      increment();
      increment();
      return 0;
  }
  ```

  - `j` her çağrıda 1'den başlar ve 2 olur. `k`'ye ilk değer yalnız ilk çağrıda verilir, sonra 2, 3, 4 diye artar. Çıktı: `j : 2  k:2`, `j : 2  k:3`, `j : 2  k:4`. Kod gcc -Wall ile derlendi ve çalıştırıldı (slayttaki `main ( void )` dönüş tipi `int` olarak eklendi).
- **İşaretçi temelleri ve bellek tablosu.** Slayttaki kod (ekrandan, 02:10:00):

  ```c
  #include <stdio.h>
  int main(int argc, char *argv[]) {
     short i,j; //short integers
     short *p;  //pointer to short
     i = 123;   //statement #1
     j = 321;   //statement #2
     p = &i;    //statement #3: p now shows the memory address of i
     j = *p;    //statement #4: * means: use the indirect (pointer) value of p
     printf("i:%d j:%d", i, j);
     i += 2; j += 3; printf("i:%d j:%d", i, j); //statement #5
     return 0;
  }
  ```

  - 4\. komuttan sonra tablo (ekrandan, 02:25:00): `i` 1200 adresinde 123, `j` 1202 adresinde 123, `p` 1204 adresinde 1200. 5. komuttan sonra `i` 125, `j` 126, `p` yine 1200.
  - Kod gcc -Wall ile derlendi ve çalıştırıldı (çıktılar okunur olsun diye `before`/`after` ve `\n` eklendi): `before i:123 j:123`, `after i:125 j:126`.
  - Ders sonrası not: Hoca önce "i ve j artık bellekte aynı yeri gösteriyor, ikisi de 128 olur" dedi; programı çalıştırmadan önce kendisi düzeltti. `j = *p` yalnız değeri kopyalar; `i` ile `j` farklı bellek gözleridir.
- **Diziler ve işaretçi aritmetiği.** `int ar[5]` için ilk eleman 0x1000 adresindeyse, `int` 4 bayt olduğundan `ar[1]` 0x1004, `ar[3]` 0x100C adresindedir (ekrandan, 02:40:00). `ar[3] = ar[0] + ar[1]` ile 32 yazılır; değer atanmayan `ar[2]` ve `ar[4]` önceden bellekte kalan değeri taşır. Derste çalıştırılınca 15, 17, 32 doğru çıktı, diğer iki gözde rastgele değerler göründü. `short *p = ar;` için `p + 3` adresi `p`'den 3 × 2 = 6 bayt ileridedir ve `*(p+3)` ile `ar[3]` aynıdır.
  - Ders sonrası not: Hoca `float` için "8 bayt ile gösteriliyorsa" diyerek 3 × 8 = 24 bayt hesabı yaptı. Yaygın derleyicilerde `float` 4 bayttır (8 bayt olan `double`'dır); bu durumda `p + 3` 12 bayt ilerler. Kural aynıdır: ilerleme miktarı eleman boyutu çarpı adım sayısıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
