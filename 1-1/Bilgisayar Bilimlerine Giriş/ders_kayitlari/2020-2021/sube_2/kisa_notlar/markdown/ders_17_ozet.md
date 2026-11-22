# Ders 17 Çalışma Özeti

## Genel Konular

- Laboratuvar ortamı ve çalışma düzeni
  - Uygulama, daha önce kurulan Ubuntu sanal makinesinde yapıldı. Masaüstünde `BBG` klasörü, içinde de `Lab01` klasörü açıldı; haftanın bütün örnekleri bu klasöre kaydedildi (ekrandan, 00:05:00).
  - Terminalde `cd Desktop/`, `ls -la`, `cd BBG/`, `cd Lab01/` komutlarıyla klasörler arasında gezinildi.
  - Editör ve derleyici ayrı ayrı kullanıldı: editör olarak `gedit`, derleyici olarak `gcc`. Hoca, bir IDE'ye bağımlı olmadan da program yazabilmeyi önemsediğini söyledi; IDE'ye daha sonra geçilecek.
- Dosya adı ve uzantı
  - gedit yeni dosyayı "Untitled Document 1" adıyla kaydeder. C programı `.c` uzantısıyla adlandırılmalıdır (`hello.c`). Uzantı hem okuyan kişiye hem editöre bunun bir C dosyası olduğunu söyler; editör sözdizimini buna göre renklendirir.
- İlk C programı: Hello World (ekrandan, 00:10:00 ve 00:15:00)
  - `#include <stdio.h>` ile kullanılacak kütüphane baştan belirtilir.
  - Her çalıştırılabilir programın bir başlangıç noktası vardır: `main` fonksiyonu. Dönüş tipi `int`, bu derste parametre almaz: `int main(void)`.
  - `main`'in dönüş değeri, programı çalıştıran sürece durumunu bildirmek için kullanılır. Unix ve türevlerinde başarıyla biten sürecin dönüş değeri geleneksel olarak 0'dır, bu yüzden sona `return 0;` yazılır.
  - `return` içinde bulunulan fonksiyondan döner, `exit` ise programı sonlandırır. `main`'in sonunda ikisi aynı işi görür, başka bir fonksiyonda `exit` kullanmak bütün programı bitirir.
  - İlk sürümde `printf("Hello World...")` yeni satır karakteri olmadan yazıldı; çıktıdan hemen sonra komut istemi aynı satırda başladı. `\n` eklenince istem alt satıra geçti.
- Derleme ve çalıştırma
  - `gcc hello.c` derler ve `a.out` adlı çalıştırılabilir dosya üretir.
  - `./a.out` ile çalıştırılır. `./`, programın içinde bulunulan klasörde arandığını söyler; yazılmazsa sistem, sistem genelinde yüklü bir `a.out` programı arar.
  - Her derleme eski `a.out`'un üzerine yazar. Bu yüzden çıktı adı `-o` ile verilir: `gcc fac.c -o Fac`.
  - Hoca bütün uyarıların açılmasını önerdi: `gcc -Wall fac.c -o Fac`.
  - Terminalde yukarı ve aşağı ok tuşlarıyla önceki komutlara dönülebilir.
- Derleyici hata mesajları
  - Hata mesajı dosya adını, satır ve sütun numarasını verir ve hatalı yeri gösterir. Örnek: dosyanın başına yanlışlıkla bir `+` girince `fac.c:1:1: error: expected identifier or '(' before '+' token` ve `fac.c:1:2: error: stray '#' in program` hataları alındı (ekrandan, 00:20:00).
  - Mesajlar, derleyicinin fark ettiği ilk hatadan başlayarak listelenir. Bir hata başka yerlerde de hata mesajlarına yol açabilir; hata asıl yerinden çok uzakta da görünebilir. Bu yüzden düzeltmeye her zaman ilk hata mesajından başlanır.
- Faktöriyel programı (ekrandan, 00:20:00)
  - Değişkenler: `int n, i, mul=1;`. `mul` çarpımı tutar ve 1 ile başlar.
  - `scanf("%d", &n);` ile sayı okunur; okuma yapılacak değişkenin adresi `&` ile verilir.
  - `for(i = 1; i <= n; i++) { mul = mul * i; }`, sonra `printf("%d! is equal to %d\n", n, mul);`.
  - 5 girildiğinde `5! is equal to 120` (ekrandan, 00:25:00). Sonra döngü 2'den başlatıldı, çünkü 1 ile çarpmanın anlamı yok; sonuç aynı.
  - Tek satırlık gövdede bile süslü parantezle blok açmak hatayı önleyen bir alışkanlıktır.
- Newton yöntemiyle karekök (ekrandan, 00:35:00)
  - Gerekenler: karekökü alınacak `x`, eşik `th`, eski ve yeni değer (`old`, `new`), aradaki fark `e` ve adımları sayan `i`.
  - İlk tahmin `old = 1`; `new = (old + x/old) / 2`; `e = fabs(new - old)`. Fark mutlak değerle alınır, çünkü yeni değerin eskisinden büyük mü küçük mü olacağı bilinmez.
  - `while(e > th)` döngüsünde `i++`, `old = new`, yeni değer ve fark tekrar hesaplanır.
  - `fabs` için `#include <math.h>` gerekir; eklenmeyince derleyici uyarı verdi.
  - `-Wall`, ilk denemedeki yanlış formülü (`new = (old + new) / 2`) yakaladı: `'new' is used uninitialized in this function` (ekrandan, 00:35:00).
  - 1024 için 9. iterasyonda 32, 4096 için 11. iterasyonda 64, 144 için 7. iterasyonda 12 bulundu (ekrandan, 00:35:00, 00:40:00, 00:45:00).
- Üçgen türünü bulan program (ekrandan, 00:50:00)
  - Üç kenar `a, b, c` okunur. İç içe `if-else`: `a == b` ise `b == c` sorulur (eşkenar ya da ikizkenar); değilse `b == c` (ikizkenar), o da değilse `a == c` (ikizkenar), hiçbiri değilse çeşitkenar.
  - Denemeler: 3 4 5 çeşitkenar, 6 6 6 eşkenar, 4 4 5 ve 3 4 4 ikizkenar.
- Dizinin ortalaması (ekrandan, 01:00:00)
  - `#define MAX_SIZE 100`, `int ar[MAX_SIZE];`, `float avg = 0.0;`. Kullanıcının gireceği eleman sayısının dizi boyutundan küçük olduğu varsayılır.
  - Birinci `for` diziyi okur, ikinci `for` toplar, sonra `avg /= n;`. İlk denemede bölme unutuldu ve 1..5 için 15 çıktı; düzeltilince 3, 1..10 için 5.5 bulundu.

## Hocanın Özellikle Vurguladığı Kısımlar

- Akış diyagramı ile C arasındaki döngü uyarlaması
  - Akışta döngü 1'den N'e gider. C'de dizi indisi 0'dan başladığı için döngü `i = 0` ile başlar ve `i < n` ile biter; toplam yine n adım atılır.
  - C'de döngü istenen değerden başlayabilir. Dizi indisleri ise 0'dan başlar; diziyle çalışan döngü buna göre kurulur.
- Sabit sayıları koda gömmemek
  - Dizi boyutu gibi sabitler `#define MAX_SIZE 100` gibi bir makroyla tanımlanmalıdır. Böylece değer tek yerden değiştirilir ve bakımı kolaylaşır.
- Dizi boyutu derleme zamanında belli olmalı
  - `n` kullanıcıdan okunduktan sonra `int ar[n];` tanımlamak derste kesinlikle kabul edilmez; hoca bunu temel bir yanlış anlamanın işareti saydı. Ayrıca bir fonksiyonda önce değişkenler, sonra deyimler yazılmalıdır.
- Çıktıyı biçimlendirmek
  - `\n` ve okunur etiketler olmadan iterasyon çıktıları tek satıra yığılır ve takip edilemez. Çıktının düzgünlüğünü takip etmek programcının sorumluluğundadır.
- Derlenmek çalışmak demek değildir
  - Program derlendikten sonra farklı girdilerle çalıştırılıp mantık hatası olup olmadığı kontrol edilmelidir (ortalamada bölmenin unutulması gibi).
- Okuma ve hesaplamayı ayırmak
  - Okuma ve toplama tek döngüde yapılabilir, ama girdi her zaman tek tek gelmez (dosyadan ya da bir cihazdan toplu okuma). Bu yüzden iki iş ayrı döngülerde yapılır, akışta da ayrı çizilir.
- Kavramları doğru kullanmak
  - Sorular tam ve net sorulmalı; kavramları yanlış kullanmak, karmaşık sistemlerde birbirini yanlış anlamaya yol açar.

## Kısa Tekrar Notları

- `gcc dosya.c` → `a.out`; `./a.out` ile çalıştır.
- `gcc -Wall dosya.c -o Ad` → bütün uyarılar açık, çıktı adı `Ad`.
- `#include <math.h>` → `fabs` gibi matematik fonksiyonları için.
- `int main(void) { ... return 0; }` → 0 başarılı bitiş demektir.
- `return` fonksiyondan döner, `exit` programı bitirir.
- `scanf("%d", &n);` → adresi `&` ile ver; float için `%f`.
- `printf` sonunda `\n` unutulmamalı.
- Derleme hatalarında ilk mesajdan başla.
- C dizi indisi 0'dan başlar: `for(i = 0; i < n; i++)`.
- Sabitler için `#define`.
- `float avg = 0.0;` ile `float avg = 0;` sonuç olarak aynıdır.
- Gerçel sabitler (`0.0` gibi) C'de `double` kabul edilir; `float` değişkene atanınca dönüştürülür.
- `main` parametre almıyorsa `void` yazmak doğrudur; yazılmazsa derleyici yine parametresiz kabul eder.
- Bu aşamada üçgenin geçerliliği (kenar eşitsizliği) ya da girdi denetimi beklenmiyor.

## Detaylı Açıklamalar

- Bu laboratuvarda, daha önce akış diyagramı çizilen problemler C'ye aktarıldı. Hoca her programı boş bir şablondan başlattı: önce `#include <stdio.h>`, sonra `int main(void)`, en sonda `return 0;`. Yeni bir program için önceki dosya farklı adla kaydedilip içi boşaltıldı. Her programda önce gereken değişkenler belirlendi, sonra girdi, işlem ve çıktı adımları akıştaki sırayla yazıldı.

- Faktöriyel programında çarpımı tutan `mul` 1 ile başlatıldı. Döngü önce 1'den, sonra 2'den başlatıldı. 5 için sonuç her iki durumda da 120 oldu. Hoca sonucu elle de kontrol etti: 5·4 = 20, ·3 = 60, ·2 = 120, ·1 = 120.

  ```c
  #include <stdio.h>

  int main(void)  {

      int n, i, mul=1;

      printf("Please enter a number:");
      scanf("%d", &n);

      for(i = 2;i <= n; i++)  {
          mul = mul * i;
      }

      printf("%d! is equal to %d\n", n, mul);

      return 0;
  }
  ```

  Kod ekrandaki son haline göre yazıldı (ekrandan, 00:20:00; döngünün 2'den başlaması altyazıdan) ve `gcc -Wall` ile derlenip 5 girdisiyle denendi: `5! is equal to 120`.

- Ders sonrası not: Hoca programın 20 gibi bir değerin faktöriyelini de hesaplayacağını söyledi. `int` türü bu programda 12!'den büyük değerleri doğru tutamaz; 13 girildiğinde program yanlış bir sayı (1932053504) yazdı (ajan denemesi). Büyük değerler için daha geniş bir tür gerekir.

- Newton programında hoca, akış diyagramındaki yapıyı izledi: ilk tahminle bir yeni değer hesaplanır, fark eşikten büyük olduğu sürece döngü sürer. Döngü içindeki `printf`, her iterasyonda eski değeri, yeni değeri ve farkı izlemek içindir. `#` ve `>` işaretleri yalnız okunurluk içindir; hoca bunu daha sonra `iteration number : 1) old : ...` biçimine çevirdi (ekrandan, 00:45:00). Son halinde izleme satırı yoruma alındı ve yalnız sonuç yazdırıldı (ekrandan, 00:40:00).

  ```c
  #include <stdio.h>
  #include <math.h>

  int main(void)  {

      int i=1;
      float x, new, old, th, e;

      printf("Please enter a number : ");
      scanf("%f", &x);

      printf("Please enter threshold : ");
      scanf("%f", &th);

      old = 1;
      new = (old + x/old) / 2;
      e = fabs(new - old);

      while(e > th)  {

          printf("#%d > old : %f - new : %f - e : %f\n", i, old, new, e);
          i++;
          old = new;
          new = (old + x/old) / 2;
          e = fabs(new - old);
      }

      printf("Square root of %f is %f at iteration : %d\n", x, new, i);

      return 0;
  }
  ```

  Kod ekrandan alındı (ekrandan, 00:35:00) ve `gcc -Wall ... -lm` ile derlenip denendi. 1024 ve eşik 0.0001 için çıktı ekrandakiyle aynıdır: 512.5, 257.249023, 130.614807, 69.227325, 42.009586, 33.192490, 32.021423, 32.000008 ve "Square root of 1024.000000 is 32.000000 at iteration : 9". 4096 ve 0.00001 için 11. iterasyonda 64, 144 ve 0.001 için 7. iterasyonda 12 bulundu.

- Üçgen programı, akışta konuşulan karşılaştırma sırasını iç içe `if-else` ile kurar. Önce `a == b` sorulur. Eşitse `b == c` ise eşkenar, değilse ikizkenardır. `a != b` iken `b == c` ise ikizkenar; o da değilse `a == c` ise ikizkenar, değilse çeşitkenardır (ekrandan, 00:50:00). Program derlenip 3 4 5, 6 6 6, 4 4 5, 3 4 4 ve ayrıca 4 5 4 girdileriyle denendi; sonuçlar çeşitkenar, eşkenar, ikizkenar, ikizkenar, ikizkenar oldu.

- Ortalama programı, okuma ve toplama için iki ayrı döngü kullanır. Dizinin boyutu derleme sırasında sabittir (`MAX_SIZE`); dinamik bellek ayırma öğrenilene kadar kullanıcının gireceği eleman sayısının bu boyuttan küçük olduğu varsayılır. Toplama `avg += ar[i];` ile yapılır, döngüden sonra `avg /= n;` ile ortalama bulunur. Kullanıcıya "1. eleman" gibi bir sıra göstermek için `printf` içinde `i+1` yazılabilir; dizi indisi yine 0'dan başlar (ekrandan, 01:05:00).

  ```c
  #include <stdio.h>

  #define MAX_SIZE 100

  int main(void)  {

      int i, n;
      int ar[MAX_SIZE];
      float avg = 0.0;

      printf("Please enter number of elements : ");
      scanf("%d", &n);

      for(i = 0; i < n; i++) {
          printf("Please enter %d. element : ", i+1);
          scanf("%d", &ar[i]);
      }

      for(i = 0; i < n; i++) {
          avg += ar[i];
      }

      avg /= n;

      printf("Average value of the elements is %f\n", avg);

      return 0;
  }
  ```

  Kod ekrandan alındı (ekrandan, 01:00:00 ve 01:05:00) ve `gcc -Wall` ile derlenip denendi: 1..5 için 3.000000, 1..10 için 5.500000.

- `float avg = 0.0;` sorusu: `0` yazmak da aynı sonucu verir. Hoca, veri tipleri hiyerarşisini (en altta `int`, en üstte `long double`) hatırlattı. `0` yazılınca bir tamsayı `float`'a dönüştürülür. `0.0` gerçel bir sabittir; standart, gerçel sabitleri `double` kabul eder, `float` değişkene atanırken dönüştürülür. Hoca bunun üzerinde durulacak bir fark olmadığını söyledi.

- Ders sonrası not: Hoca, `n` okunduktan sonra `int ar[n];` tanımlamanın standart C'de çalışmadığını, ancak C++ gibi derlenirse çalışacağını söyledi. Bu, C89/C90 için doğrudur; gcc `-std=c89 -pedantic` ile "ISO C90 forbids variable length array" uyarısı verir. C99 değişken uzunluklu dizileri standarda büyük olasılıkla eklemiştir ve gcc `-std=c99` ile bu kod derlenip çalıştı (ajan denemesi). Standart C++ ise bunu kabul etmez; g++ "ISO C++ forbids variable length array" uyarısı verir. Hocanın asıl kuralı değişmez: bu derste dizi boyutu sabit olarak (`MAX_SIZE` gibi) verilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
