# Ders 2 Çalışma Özeti

## Genel Konular

- Değişkenler ve bellek
  - Bellek tek boyutlu bir dizi gibi düşünülür; adresler 0'dan başlar ve genelde onaltılık (`0x0000` ... `0xFFFF...`) yazılır.
  - Bir değişkenin beş özelliği vardır: adres, değer, etiket (ad), boyut ve tip.
  - Slayttaki örnekte `j = 5 + 10;` ifadesinde `j` etiketi 2486 adresindeki 4 baytlık hücreyi gösterir ve içeriği 15'tir (ekrandan, 00:15:00).
  - Sabitin değeri hiç değişmez; değişken ise bellekte bir adres kaplar ve değeri değiştirilebilir.
- Değişken adlandırma kuralları (C'ye özgü)
  - Ad yalnızca harf, rakam ve alt çizgi (`_`) içerebilir; harf ya da alt çizgiyle başlamalıdır, rakamla başlayamaz.
  - C büyük-küçük harfe duyarlıdır: `VaR`, `var`, `VAR` üç farklı addır (ekrandan, 00:10:00).
  - Ad, ayrılmış anahtar kelimelerden (`default`, `goto`, `sizeof`, `register`, `enum`, `extern`, `volatile` vb.) biri olamaz.
  - Aynı kurallar sabitler, fonksiyonlar ve etiketler için de geçerlidir.
- İfadeler (expression)
  - Operatör, sayı ve adların bir değeri hesaplayan birleşimidir: `5`, `j`, `5 + j`, `f()`, `f()/4` (ekrandan, 00:20:00).
  - Fonksiyondan dönen değer başka bir işlemde kullanılabilir; örneğin `rand() % 10` ile 0-9 aralığında tam sayı elde edilir.
- Atama, sol değer (L-value) ve sağ değer (R-value)
  - `a = 5;`, `a = a + 5;` ifadelerinde sol taraf L-value, sağ taraf R-value'dur (ekrandan, 00:25:00).
  - Sol tarafta değişken ya da dizi hücresi (`a[i]`) olabilir; sabit, fonksiyon çağrısı ya da matematiksel işlem olamaz (`5 = a;` geçersizdir).
  - Sağ tarafta değişken, sabit, fonksiyon çağrısı, dizi hücresi ve matematiksel işlem olabilir. Bu yüzden R-value kümesi L-value kümesini kapsar.
  - `int *a; int b = 0; a = &b; *a = f(x);` geçerlidir, çünkü `*a` bir değişkenin yerini gösterir (ekrandan, 00:30:00).
- Yorum satırları
  - Tek satır için `//`, çok satır için `/* ... */` kullanılır.
  - Yorum, fonksiyonun başına ne aldığı, ne döndürdüğü ve ne yaptığı yazılarak konur; her satıra açık olanı tekrar eden yorum yazmak doğru değildir.
- Fonksiyonlar
  - Programı küçük, anlamlı ve yönetilebilir parçalara (modüllere) bölmek için yazılır; tekrar kullanım, bakım ve hata ayıklamayı kolaylaştırır.
  - Yapı: dönüş tipi, fonksiyon adı, parametre listesi, gövde.
  - Parametre alan/almayan ve değer döndüren/döndürmeyen (`void`) olmak üzere 2 x 2 = 4 tür fonksiyon yazılabilir.
  - Kullanılmadan önce bildirilmelidir: prototipte (`int combination(int, int);`) yalnız parametre tipleri yazılır, adlar gerekmez (ekrandan, 00:40:00).
  - Kod girintili (indentation) ve düzenli yazılmalıdır.
- Tasarım ilkeleri: cohesion ve coupling
  - Cohesion (uyum, tutarlılık): fonksiyonun adıyla yaptığı iş arasındaki uyumdur; yüksek olmalıdır.
  - Coupling (bağlılık): bir fonksiyonun birden fazla işe bağımlı olmasıdır; düşük olmalıdır.
  - Örnek: `sirala` fonksiyonu yalnız sıralamalı, ekrana yazdırma ayrı bir fonksiyonda olmalıdır. `rand()` yalnız rastgele sayı döndürdüğü için uyumu yüksek, bağlılığı düşüktür.
- `main` fonksiyonu, `exit` ve `return`
  - Her çalışan programda bulunur; programın başlangıç noktasıdır.
  - `exit(0)` programı bitirir ve denetimi işletim sistemine verir; 0 hatasız bitişi, sıfırdan farklı değer anormal bitişi gösterir. `main` içinde `exit()` çağırmak `return` ile aynıdır (ekrandan, 00:45:00).
- `printf` ve `scanf`
  - İşletim sistemiyle haberleşerek ekrana yazar ve klavyeden okur; değişken sayıda argüman alırlar.
  - İlk argüman format dizgisidir (`"%d"` gibi). `scanf` okuduğunu belleğe yazacağı için değişkenin adresini (`&num`) ister.
- Önişlemci (preprocessor)
  - `#` ile başlar, sonunda noktalı virgül yoktur; makrolar, şartlı derleme ve hata ayıklama için kullanılır.
  - `#define MAX 100`: kodda `MAX` görülen her yere 100 yazılır. Sabit adları büyük harfle yazılır; değer tek yerden değiştirilebilir.
  - `#define NOTHING 0` iken `NOTHING = j + 5` yazmak `0 = j + 5` anlamına gelir ve geçersizdir (ekrandan, 00:50:00).
  - `#include <...>` sistem dizinlerinde, `#include "..."` önce proje klasöründe arar.
- Veri tipleri
  - Ağaç: `void`, skaler tipler (aritmetik: tam sayı ve kayan noktalı; işaretçiler; `enum`) ve birleşik (aggregate) tipler (diziler, struct) (ekrandan, 01:15:00).
  - `int`, `int *` ve `int **` birbirinden farklı tiplerdir. Atama için tipler aynı ya da dönüştürmeye uyumlu olmalıdır (ekrandan, 01:20:00).
  - Temel tipler `char`, `int`, `float`, `double`, `enum`; önlerine `short`, `long`, `signed`, `unsigned` niteleyicileri gelir.
  - 32 bitlik `int` aralığı $-2^{31}$ ile $2^{31}-1$, `unsigned int` aralığı $0$ ile $2^{32}-1$'dir. 1 baytlık işaretli sayı $-128$ ile $127$ arasındadır.
  - Bir bloktaki bildirimler çalıştırılabilir deyimlerden önce yapılır.
- Karakterler de sayıdır
  - 1 bayt ile 256 farklı kod gösterilir (ASCII). `'A'` = 65 = `01000001`, `'a'` = 97 = `01100001`; aralarındaki fark 32'dir (tek bir bit).
  - Gri tonlu resimde her piksel 8 bitlik parlaklık (intensity) değeri taşır; $m \times n$ çözünürlüktür.
- Format dizgileri ve sabitler
  - `%d`, `%u`, `%hi`, `%li`, `%hu`, `%c` gibi belirteçler `printf`'te çıktının nasıl gösterileceğini, `scanf`'te girdinin nasıl yorumlanacağını belirler (ekrandan, 01:35:00).
  - Tam sayı sabitleri onluk, sekizlik ve onaltılık (`0xFF` = 255) yazılabilir; `U` ve `L` sonekleri işaretsiz ve uzun tip belirtir.
  - `float` (`%f`) genelde 4 bayt, `double` (`%lf`) 8 bayttır ve yaklaşık iki kat duyarlıdır; bilimsel gösterim `%e` ile yazılır (`3e2`, `5E-5`) (ekrandan, 01:40:00).
- İlklendirme (initialization)
  - Tanım sırasında değer vermektir; ilk değer verilmiş ve verilmemiş değişkenler bellekte ayrı bölgelerde tutulur.
  - Bellek ile hız arasında ters orantı (trade-off) vardır.
- Tip karıştırma ve dönüşümler
  - Örtük (implicit) dönüşüm: `int a = 3.5 + 2;` sonucu 5.5'in tam kısmı olan 5'tir.
  - `int j; float f;` için `j + f`'te `j` float'a, `j + f + 2.5`'te ikisi de double'a çevrilir; `j = 2.5` hassasiyet kaybı, çok büyük değer atamak taşma (overflow) üretir (ekrandan, 01:50:00).
  - İşaretli ve işaretsiz tipler karıştığında aynı bit dizisi farklı okunur (8 bitte $-22$ ile $234$).
  - Açık (explicit) dönüşüm (cast): `k = 3, j = 2` iken `(float)(k / j)` 1.0, `(float)k / j` 1.5 verir.
- `enum`, `void` ve `typedef`
  - `enum { red, blue, green, yellow } color;` değerleri 0'dan başlar ve birer artar; başka değer de verilebilir (ekrandan, 01:55:00).
  - `void` herhangi bir değer döndürmemeyi gösterir ama aynı zamanda genel (generic) işaretçi için kullanılan bir tiptir.
  - `typedef long int INT32;` ile var olan tipe yeni ad verilir; `INT32 j;` ile `long int j;` aynıdır (ekrandan, 02:00:00).
- Kaçış karakterleri ve noktalı virgül
  - `\n`, `\t`, `\\`, `\"`, `\'`, `\a` gibi kaçış dizileri tırnak içinde özel karakter yazmak içindir.
  - Noktalı virgül emir cümlesinin sonuna konur; `if (x == 3);` gibi koşul ya da döngü başlığından sonra konursa derleyici hata vermez ama mantık bozulur.
- Operatör önceliği
  - Önce parantez, sonra `*`, `/`, `%`, sonra `+`, `-`; aynı seviyede soldan sağa. İlişkisel ve eşitlik operatörleri daha sonra, atama en son ve sağdan sola yapılır.
  - `y = 2 * 5 * 5 + 3 * 5 + 7;` adım adım 72 olur (ekrandan, 02:05:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- İlk slaytlardaki temel kurallar önemlidir
  - Dinamik bellek yönetimi ve sonraki konularda "burada şunu demiştik" diye bu temellere dönülecektir.
- Değişkenler belleği yönetmek demektir
  - Ardışık adreslerde ve dağınık adreslerde çalışmanın avantaj ve dezavantajları dersin ana konularındandır (veri yapılarına hazırlık).
- Tek pointer, çift pointer ve diğerleri ayrı tiplerdir
  - `int`, `int *`, `int **` birbirine doğrudan atanamaz; bu en çok hata yapılan yerlerden biridir.
- Fonksiyon tasarımında yüksek cohesion, düşük coupling
  - Her fonksiyon tek iş yapmalıdır.
- Sol tarafa matematiksel işlem, sabit ya da fonksiyon çağrısı yazılmaz.
- Format dizgileri ve değer aralıkları
  - Belirli bir değer (örneğin 128) için format dizgisi örneğinin çıktısını çıkarabilmek gerekir; farklı değerlerle denemesi tavsiye edildi.
- Tip dönüşümleri ve operatör öncelikleri
  - Bu konulara ayrıca çalışılması tavsiye edildi.
- C bilmek pointer bilmek ve bellek yönetimini bilmektir.

## Kısa Tekrar Notları

- Değişkenin 5 özelliği: adres, değer, etiket, boyut, tip.
- Ad: harf/alt çizgiyle başlar, yalnız harf-rakam-`_` içerir, büyük-küçük harf duyarlı, anahtar kelime olamaz.
- L-value: değişken, dizi hücresi. R-value: bunlar + sabit, fonksiyon çağrısı, matematiksel işlem.
- 4 fonksiyon türü: parametreli/parametresiz x void/değer döndüren.
- Prototipte parametre adı gerekmez, tipi yeter.
- `exit(0)` = `return 0` (main içinde); 0 başarı.
- `scanf` adres ister: `&num`.
- `#define` sonunda `;` yok, ad büyük harf; `#include "..."` önce proje klasörü.
- `int` 32 bit: $[-2^{31},\ 2^{31}-1]$; `unsigned int`: $[0,\ 2^{32}-1]$; 1 bayt işaretli: $[-128,\ 127]$.
- `'A'` = 65, `'a'` = 97, fark 32.
- `int a = 3.5 + 2;` sonucu 5 (örtük dönüşüm).
- `(float)(3/2)` = 1.0, `(float)3/2` = 1.5.
- `enum` değerleri 0'dan başlar.
- `typedef eski_tip YENI_AD;`
- Öncelik: `()` > `* / %` > `+ -` > ilişkisel > eşitlik > `=` (sağdan sola).

## Detaylı Açıklamalar

- Bellek ve değişken. Bir bilgisayar mühendisi için değişken, belleğin hücreleridir. Bellek tek boyutlu bir dizi gibidir ve programlamadaki her iş bu dizi üzerinde yapılır. Bellek kapasitesi RAM kapasitesine karşılık gelir; adresler 0'dan başlar ve okunması kolay olsun diye onaltılık yazılır. Slayttaki çizimde `j` değişkeni 2486 adresindeki 4 baytlık hücreye karşılık gelir ve `j = 5 + 10;` sonrası içeriği 15'tir (ekrandan, 00:15:00). Bu çizimde etiket `j`, adres 2486, boyut 4 bayt, değer 15 ve tip `int`'tir.
- Atama ve L-value/R-value. Yeni başlayanların sık yaptığı hata, eşittir işaretinin iki yönlü çalıştığını sanmaktır. Atamanın sol tarafı bir bellek yerini göstermelidir: değişken ya da dizi hücresi. `5 = a;` ya da `f = a;` geçersizdir, çünkü fonksiyon çağrısının sonucu 5, 6 gibi bir sabittir. Bir işaretçi tanımlanıp bir değişkenin adresine bağlanırsa (`int *a; int b = 0; a = &b;`) `*a = f(x);` geçerlidir; burada sol taraf `b`'nin oturduğu yerdir (ekrandan, 00:30:00).
- Fonksiyon bildirimi. Slayttaki örnekte `combination` fonksiyonu önce prototip olarak bildirilir, sonra başka bir fonksiyonun içinde çağrılır, tanımı ise en sondadır (ekrandan, 00:40:00):

  ```c
  int combination( int, int ); //This is also called allusion
  void aTaskThatNeedsCombination( ) {
      //some code
      c = combination(a, b);
      //more code
  }
  int combination( int a, int b ) {
      //necessary code
  }
  ```

  Bu parça kod derlenmedi (eksik bildirimler içerir). Genel düzen: önce prototipler, sonra `main`, sonra diğer fonksiyonlar.
- Format dizgisi örneği. Slayttaki program aynı tam sayıyı farklı belirteçlerle yazdırır (ekrandan, 01:35:00):

  ```c
  #include <stdio.h>
  #include <stdlib.h>

  int main(int argc, char *argv[]){
      int sayi = 65;
          printf("     int \t%d\n",sayi);
          printf(" uns.int \t%u\n",sayi);
          printf(" srt.int \t%hi\n",sayi);
          printf(" lng.int \t%li\n",sayi);
          printf("usrt.int \t%hu\n",sayi);
          printf("ulng.int \t%ul\n",sayi);
          printf("     char\t%c\n",sayi);
          printf(" uns.char\t%uc\n",sayi);

      system("PAUSE");
      return 0;
  }
  ```

  - Kod `gcc -Wall` ile derlendi; `%li` satırı için tip uyarısı verdi. 65 ile tam sayı satırları 65, `%c` satırı `A` yazdı; `%ul` satırı `65l`, `%uc` satırı `65c` yazdı (sondaki harf belirteçten sonra düz metin olarak basılır).
  - `system("PAUSE")` Windows'a özgüdür; Linux'ta komut bulunamaz ama program yine çalışır.
- Örtük ve açık dönüşüm. Derleyici bir ifadeyi alt ifadelere böler ve her operatörün tanımına göre gerekirse gizli dönüşüm yapar. `int a = 3.5 + 2;` ifadesinde sağ taraf 5.5'tir, sol taraf `int` olduğu için 5 kopyalanır. Açık dönüşümde `(float)(k / j)` önce tam sayı bölmesi yapar (3/2 = 1) ve 1.0 verir; doğru sonuç için operandlardan biri önce float'a çevrilmelidir: `(float)k / j` = 1.5. Bu iki sonuç gcc ile doğrulandı.
- Enum örneği. Slayttaki satırlar (ekrandan, 01:55:00):

  ```c
  enum { red, blue, green, yellow } color;
  enum { bright, medium, dark } intensity;

  color = yellow;          // OK
  color = bright;          // Type conflict
  intensity = bright;      // OK
  intensity = blue;        // Type conflict
  color = 1;               // Type conflict
  color = green + blue;    // Misleading usage
  ```

  `green + blue` = 2 + 1 = 3 olur ve bu da `yellow`'un koduna denk gelir; bu tür toplamlar yanıltıcı sonuçlar verebilir.
- Ders sonrası notlar
  - Hoca `long int`'in 8 bayt, `long long`'un 16 bayt olduğunu söyledi. Doğrusu: `long` platforma göre 4 ya da 8 bayttır (64 bit Linux'ta 8, Windows'ta 4); `long long` en az 64 bit (8 bayt) olur. Bu sistemde gcc ile `long` 8, `long long` 8 bayt ölçüldü.
  - Hoca `rand()`'ın varsayılan olarak 0 ile 1 arası değer verdiğini söyledi. C'de `rand()` 0 ile `RAND_MAX` arasında bir tam sayı döndürür; `rand() % 10` bu yüzden 0-9 verir.
  - Resim boyutu örneğinde hoca $256 \times 256 \times 8 = 2^{19}$ sonucunu 512 KB olarak söyledi. $2^{19}$ bittir; bayta çevrilince $2^{16}$ bayt = 64 KB olur (512 Kbit). Ayrıca $2^{10}$ bayt = 1 KB, $2^{20}$ bayt = 1 MB, $2^{30}$ bayt = 1 GB'tır.
  - Hoca `%5.7f` için "virgülden önce 5, sonra 7 karakter" dedi. Doğrusu: 5 toplam en az alan genişliği, 7 ondalık basamak sayısıdır.
  - Tip hiyerarşisi anlatımında hoca `int`'in $2^{32}-1$'e kadar gittiğini ve bunun `unsigned int`'e sığmadığını söyledi; tersidir: `unsigned int` $2^{32}-1$'e kadar gider ve bu değer `int`'e sığmaz.
  - `typedef` önişlemci gibi metin kopyalamaz; derleyicinin işlediği bir tip eş adıdır. `#define` ise önişlemcide metin yerine koyar.
  - Bildirimlerin bloğun başında olma şartı C89/ANSI C'ye aittir; C99 ve sonrası bildirimin deyimler arasında yapılmasına izin verir.
  - Slayttaki "Type conflict" satırları C'de derleme hatası vermez: `color = 1;` ve `color = bright;` gcc `-Wall` ile uyarısız derlendi (enum değerleri `int` gibi davranır). Bu satırlar C++'ta hatadır.
  - `for (...);` biçiminde başlıktan sonra konan noktalı virgül döngünün boş gövdeyle dönmesine, arkasındaki bloğun döngüden sonra bir kez çalışmasına yol açar.

<!-- BELİRSİZ: Legal/illegal ad örneklerinin slaytı karelerde okunamadı; örnek adlar nota alınmadı. -->
<!-- BELİRSİZ: İşaretli/işaretsiz karıştırma ve açık dönüşüm slaytlarının kodu karelerde yok; değerler altyazıdan alındı. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
