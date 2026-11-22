# Ders 6 Çalışma Özeti

## Genel Konular

- Yapısal programlamada sık yapılan hatalar
  - `for (int i = 0; ...)` gibi döngü başında değişken tanımlamak C++ alışkanlığıdır; derste kullanılan C derleyicisinde değişken blok başında tanımlanmalıdır (bkz. ders sonrası not).
  - `if (a == 5)` yerine `if (a = 5)` yazmak derlenir ama yanlış sonuç verir; `scanf` içinde `&` unutmak da temel bir hatadır.
  - Diziyi sıfırlamak için gelişigüzel `static` kullanmak yanlıştır: `static` değişkeni program sonuna kadar yaşatır, yalnız sıfırlama aracı değildir.
  - Global değişken kullanmak yapısal programlamada yasaklanır; değerler fonksiyonlar arasında parametreyle aktarılmalıdır.
- Önişlemci (preprocessor) ve makrolar
  - Bütün önişlemci yönergeleri `#` ile başlar; `#` satırdaki ilk boşluk olmayan karakter olmalıdır.
  - Makro komutu noktalı virgülle değil, satır sonuyla biter; birden fazla satıra yaymak için satır sonuna `\` konur (ekrandan, 00:25:00).
  - Makrolar derlemeden önce işlenir: çağrıldığı yere tanımın metni kopyalanır (macro substitution / expansion).
  - En sık kullanım sayısal sabit tanımlamaktır: `#define BUFFER_LEN 512` ile `char buf[BUFFER_LEN];` yazılır; değer tek yerden değiştirilir. Makro adları geleneksel olarak büyük harfle yazılır.
  - Tip adı da makroyla verilebilir (`#define TIP int`); bu genel (jenerik) programlamaya bir adımdır.
- Fonksiyon benzeri makrolar (ekrandan, 00:30:00)
  - `#define MUL_BY_TWO(a) ((a) + (a))`: `j = MUL_BY_TWO(5);` satırı `j = ((5) + (5));` olur, `f = MUL_BY_TWO(2.5);` satırı `f = ((2.5) + (2.5));` olur.
  - `#define min(a, b) ((a) < (b) ? (a) : (b))`; çağrı örneği `printf("%d", min(-3, 6));`.
  - Makro tanımının sonuna `;` ve tanım içine `=` konmaz; parametrelerin tipi yoktur, tip denetimi yapılmaz.
  - Alıştırma (slayttan): `min` makrosunu üç sayı için genişletin.
- Makro yan etkisi (side effect) (ekrandan, 00:35:00)
  - `a = min(b++, c);` önişlemcide `a = ((b++) < (c) ? (b++) : (c));` olur; `b++` iki kez çalışabilir.
  - Örnek: `b = 2`, `c = 4` için koşul doğrudur, `b` önce 3 olur, sonra `a = b++` ile `a = 3`, `b = 4` olur. Beklenen `a = 2` değildir.
- Makrolar ve fonksiyonlar (ekrandan, 00:40:00)
  - Avantaj: makro genellikle daha hızlıdır, çünkü fonksiyon çağrısının gidiş-dönüş yükü (yedekleme/backup ve geri yükleme/restore) yoktur; tip kısıtı olmadığı için bir makro birden çok veri tipiyle kullanılabilir.
  - Dezavantaj: argümanlar makro gövdesinde her geçtiği yerde yeniden değerlendirilir; fonksiyon gövdesi bir kez derlenir, makro her kullanımda genişletilir; makro argüman sayısını denetler ama tipini denetlemez; makro içeren program fazladan bir çeviri katmanından geçtiği için hata ayıklaması zordur.
- `#undef`
  - Tanımlı makro kaynak dosyanın sonuna kadar geçerlidir; `#undef` ile o noktadan sonra geçersiz kılınır, sonra yeniden `#define` edilebilir.
- Hazır makrolar (ekrandan, 00:45:00)
  - `__LINE__` (çağrıldığı satır numarası), `__FILE__` (dosya adı), `__TIME__` (derleme saati), `__DATE__` (derleme tarihi), `__STDC__` (derleyici ANSI standardına uyuyorsa 1).
  - `__TIME__` ve `__DATE__` programın çalıştığı anı değil, derlendiği anı verir.
- Koşullu derleme (conditional compilation)
  - `#if`, `#elif`, `#else`, `#endif` ile kaynak kodun bazı satırları derlenir, bazıları derlenmez; özellikle hata ayıklama sürümlerinde kullanılır.
  - Her `#if` bloğu `#endif` ile kapanır; birden çok `#elif` olabilir, `#else` bir tanedir ve sondadır; süslü parantez gerekmez.
  - Türetilmiş biçimler (ekrandan, 00:50:00): `#if defined TEST` = `#if defined (TEST)`, `#if defined macro_name` = `#ifdef macro_name`, `#if !defined macro_name` = `#ifndef macro_name`.
- `#include` (ekrandan, 00:55:00)
  - `#include <dosya>`: derleyicinin standart dizinlerinde arar (UNIX'te genellikle `/usr/include`).
  - `#include "dosya"`: önce işletim sisteminin dosya kurallarına göre (genellikle programın bulunduğu klasörde) arar, bulamazsa `< >` gibi arar.
  - Başlık dosyaları (`.h`) veri yapısı tanımlarını, makro tanımlarını, fonksiyon prototiplerini ve global veriyi içerir; fonksiyonların gövdeleri (gerçekleştirimi) `.c` dosyasında kalır.
- `#line` (satır denetimi)
  - `#line 100` ve `#line 200 newname` gibi yönergeler derleyicinin kullandığı satır numarasını ve dosya adını değiştirir; derste yalnız tanıtıldı.
- Depolama sınıfları: kapsam (scope) ve ömür (duration)
  - Kapsam, değişken adının kaynak kodda etkin olduğu bölgedir; ömür, değişkenin bellekteki yaşam süresidir (ekrandan, 01:10:00).
  - Sabit ömürlü (fixed duration) değişken kapsamdan çıkıldıktan sonra da değerini korur; otomatik ömürlü (automatic duration) değişken için böyle bir garanti yoktur.
  - Yerel değişkenler varsayılan olarak otomatiktir; `static` ile sabit ömürlü yapılır. `auto` anahtar sözcüğü gereksizdir, çünkü yerel değişken zaten otomatiktir.
  - Sabit değişken yalnız bir kez ilklenir; otomatik değişken bloğa her girişte yeniden ilklenir.
  - İlk değer verilmeyen `static` değişkene 0 atanır; `static int a[5];` dizisi sıfırla başlar ama program sonuna kadar yaşar.
- Dört kapsam türü (ekrandan, 01:20:00)
  - Program kapsamı: değişken programı oluşturan bütün kaynak dosyalardan erişilebilir (global değişken). Fonksiyon dışında `static` olmadan tanımlanır.
  - Dosya kapsamı: tanımlandığı yerden dosya sonuna kadar etkindir. Fonksiyon dışında `static` ile tanımlanır.
  - Fonksiyon kapsamı: yalnız `goto` etiketleri bu kapsama sahiptir; etiket fonksiyon içinde tek (unique) olmalıdır, farklı fonksiyonlar aynı etiket adını kullanabilir (ekrandan, 01:25:00).
  - Blok kapsamı: tanımlandığı yerden bloğun sonuna kadar etkindir; blok, süslü parantez içindeki deyimler dizisidir. İç blokta aynı adla yeni değişken tanımlamak (variable hiding) mümkündür ama zor bulunan hatalara yol açabilir.
- Global değişkenler ve bildirim türleri (ekrandan, 01:35:00)
  - Global değişkenler programın bakımını zorlaştırır, karmaşıklığı artırır, modüller arasında çatışma yaratır; tek avantajı hızlı kod yazdırmasıdır.
  - Boyut/sayaç gibi sabitler `#define` ile tanımlanır ya da parametreyle aktarılır; `int max = 100;` gibi global değişken kullanılmaz.
  - İki bildirim türü vardır: tanım (definition) bellekte yer ayırır; ima (allusion) yer ayırmaz, değişkenin başka yerde tanımlı olduğunu bildirir: `extern int j;`.
- Diğer belirteçler
  - `register`: değişkenin işlemci yazmacında tutulmasını ister (karar derleyicinindir); yazmaçta tutulan değişkenin bellek adresi olmadığı için `&` uygulanamaz; tipik kullanım döngü sayaçlarıdır.
  - `const`: değişkenin değerini sabitler (`const int x = 5;` sonrası `x = x + 1` yapılamaz).
  - `volatile`: derleyiciye bazı optimizasyonları kapatmasını söyler.
- İşaretçilere giriş (ekrandan, 01:45:00 ve 01:50:00)
  - Değişkenin özellikleri: etiket (ad), değer, adres, tip, boyut (size), ömür ve kapsam.
  - İşaretçi, değişkene adres üzerinden erişmeyi sağlar; en basit örnek `scanf("%d", &a)`.
  - Atamada iki tarafın işaretçi türü aynı olmalıdır: `int`, `int *`, `int **` ve `int ***` birbirinden farklı türlerdir.
  - `p = &i;` sonrası `j = *p;` ile `p`'nin gösterdiği adresteki değer `j`'ye kopyalanır.
- Derin ve sığ kopyalama
  - Derin kopyalama (deep copy) değeri kopyalar, iki değişken bundan sonra bağımsızdır (`c = a;`, `j = *p;`).
  - Sığ kopyalama (shallow copy) adresi kopyalar; iki işaretçi aynı bellek hücresini gösterir, birinden yapılan değişiklik ötekinden görünür.
- Adres ve içerik işleçleri (ekrandan, 02:05:00 ve 02:15:00)
  - `*` ve `&` art arda gelince birbirini götürür: `*&pa` ve `&*pt` yine `pa`/`pt` değerini (a'nın adresini) verir; `&*&pa` = `&pa`, `*&*pt` = `*pt`.
  - `&&pa` gibi adresin adresini almak geçersizdir, derleme hatası verir.
- İşaretçi aritmetiği (ekrandan, 02:25:00)
  - `pa = pa + 1;` adresi 1 bayt değil, işaret edilen tipin boyutu kadar (`sizeof(int)`, genellikle 4) artırır; `char *` için 1 bayt artar.
  - Derste `pa+1` sonrası adresin 4 arttığı, `pch++` sonrası 1 arttığı çalıştırılarak gösterildi.
  - Ders sonrası not: Ekranda son olarak `pa=pa+1*sizeof(int);` yazıldı; işaretçi aritmetiği zaten ölçeklendiği için bu `pa + 4` demektir (16 bayt). Kodda `pa = pa + 1;` yazılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Makro çağrıldığı yere gelir, fonksiyon ise tanımlandığı yere gidilerek çalışır
  - Hoca bunu "birbirinin tam simetriği" diye birkaç kez tekrarladı; makro derleme öncesinde metin olarak kopyalanır.
- Makroda noktalı virgül ve eşittir kullanılmaz
  - Tanımın sonuna `;` konursa kopyalanan her yerde fazladan `;` oluşur.
- Makro yan etkisi
  - Parametre gövdede kaç kez geçiyorsa o kadar kopyalanır; `b++` gibi argümanlar beklenmedik sonuç verir.
- Global değişken yasak
  - Yapısal programlama dersinde global değişken kullanılmaz; sabitler `#define` ile tanımlanır, değerler parametreyle aktarılır. İşletim sistemlerinde görülecek karşılıklı dışlama (mutual exclusion) ve kilitlenme (deadlock) sorunlarına da yol açar.
- `static` gelişigüzel kullanılmamalı
  - `static` yalnız sıfırlama aracı değildir; değişkeni program sonuna kadar yaşatır ve adresini sabitler.
- Bellek adresleri varsayımsaldır
  - 1200, 1202 gibi adresler yalnız anlatım içindir; gerçek adresler çalışma zamanında işletim sistemi tarafından belirlenir ve her çalıştırmada değişebilir.
- İşaretçi konusu sonraki konuların temelidir
  - Hoca işaretçi, adres ve içerik işleçlerinin iyice öğrenilmesini, yoksa yapılar (struct) ve dinamik bellek konularında zorlanılacağını söyledi.
- İşaretçi artırımı tipin boyutu kadardır
  - "1 bayt da değil, 4 bayt da değil": artış `sizeof` ile belirlenir, derleyiciye ve sisteme göre değişebilir.

## Kısa Tekrar Notları

- `#` ile başlayan her satır önişlemci yönergesidir; derlemeden önce işlenir, `;` ile bitmez.
- `#define AD değer`: sabit tanımı; `#define F(a) ((a)+(a))`: fonksiyon benzeri makro, tip denetimi yok.
- Makro parametrelerini ve tüm gövdeyi parantez içine alın; `b++` gibi yan etkili argüman vermeyin.
- Makro: hızlı, tipten bağımsız; ama hata ayıklaması zor ve her kullanımda genişler.
- `#undef` makroyu geçersiz kılar; hazır makrolar: `__LINE__`, `__FILE__`, `__TIME__`, `__DATE__`, `__STDC__`.
- `#if / #elif / #else / #endif`; `#ifdef` = `#if defined`, `#ifndef` = `#if !defined`.
- `<dosya.h>` standart dizinde, `"dosya.h"` önce programın klasöründe aranır; `.h` dosyasına prototip, makro, yapı tanımı konur, gövde konmaz.
- Kapsam = adın etkin olduğu bölge; ömür = bellekte yaşam süresi.
- Yerel değişken otomatik; `static` yerel değişken bir kez ilklenir ve değerini korur (`increment()` örneği: j:2 k:2, j:2 k:3, j:2 k:4).
- Kapsamlar: program (global, `static`siz), dosya (fonksiyon dışında `static`), fonksiyon (`goto` etiketleri), blok.
- `extern int j;` bir ima (allusion) bildirimidir, bellek ayırmaz.
- `register` değişkenin adresi alınamaz; `const` değeri sabitler; `volatile` optimizasyonu kapatır.
- `int *`, `int **`, `int ***` farklı türlerdir; birbirine atanamaz.
- Derin kopya değeri, sığ kopya adresi kopyalar.
- `*&x` ve `&*p` birbirini götürür; `&&x` geçersizdir.
- `p + 1` adresi `sizeof(*p)` kadar ilerletir.

## Detaylı Açıklamalar

- **Önişlemcinin yeri.** Bir C programı derlenmeden önce önişlemciden geçer. `#define`, `#include`, `#if` gibi satırlar bu aşamada işlenir: makro adları tanımın metniyle değiştirilir, başlık dosyalarının içeriği eklenir, koşullu bloklar ya tutulur ya atılır. Derleyici bu işlemin sonucunu görür. Bu yüzden makro bir fonksiyon gibi "çağrılmaz"; adının geçtiği her yere tanım metni yapıştırılır. Fonksiyon çağrısında ise program akışı fonksiyonun bulunduğu yere sıçrar (jump), dönüşte kalınan yerden devam eder. Hoca bu farkı "makro bize gelir, biz fonksiyona gideriz" diye özetledi.

- **Neden sabit için makro?** `#define BUFFER_LEN 512` yazıp programın her yerinde `BUFFER_LEN` kullanırsanız boyutu değiştirmek için tek satırı değiştirmek yeterlidir. Hoca, `int n = 512;` gibi bir değişkenle dizi boyutu vermenin bellekte ayrıca yer açtığını ve boyutun derleme öncesinde değil çalışma sırasında belirlenmesi anlamına geldiğini, bunun iyi bir yöntem olmadığını söyledi. Makro adlarının büyük harfle yazılması, okuyanın onu sıradan değişkenden ayırmasını sağlar.

- **Fonksiyon benzeri makro ve parantezler.** `#define MUL_BY_TWO(a) ((a) + (a))` tanımında parametre tipsizdir; `MUL_BY_TWO(5)` için `((5) + (5))`, `MUL_BY_TWO(2.5)` için `((2.5) + (2.5))` yazılır. Her parametrenin ve tüm ifadenin paranteze alınması, makro bir ifadenin içinde kullanıldığında işlem önceliğinin bozulmamasını sağlar.

- **Yan etki örneği.** `#define min(a,b) ((a) < (b) ? (a) : (b))` ile `a = min(b++, c);` yazılırsa önişlemci `a = ((b++) < (c) ? (b++) : (c));` üretir. Derste `b = 2`, `c = 4` alındı: karşılaştırmada `2 < 4` doğrudur ve `b` 3 olur; doğru dalda yine `b++` çalışır, `a`'ya 3 atanır ve `b` 4 olur. Fonksiyonla aynı iş yapılsaydı `a = 2`, `b = 3` olurdu. Bu kod `gcc -Wall` ile derlenip denendi, sonuç `a=3 b=4` çıktı.

- **Fonksiyon çağrısının maliyeti.** Hoca, fonksiyona giderken program sayacı, yazmaç değerleri ve değişkenler gibi bilgilerin yedeklendiğini (backup), `return` sonrası geri yüklendiğini (restore) ve bunun zaman aldığını anlattı. Makroda böyle bir gidiş-dönüş olmadığı için makro daha hızlıdır. Bunun bedeli, kodun her kullanımda genişlemesi ve hata ayıklayıcıda görülen kaynak kod ile gerçekte derlenen kodun farklı olmasıdır.

- **Hazır makrolar.** `__LINE__` ve `__FILE__` özellikle hata ayıklamada hangi satırda ve dosyada olunduğunu yazdırmak için kullanılır (`printf("%d %s", __LINE__, __FILE__);`). `__DATE__` ve `__TIME__` programın derlendiği tarihi ve saati verir; program başka bir gün çalıştırılsa da derleme anı yazılır. Hoca adların başındaki ve sonundaki iki alt çizginin hazır makro olduğunu gösteren bir gösterim olduğunu söyledi.

- **Koşullu derleme.** Önişlemcinin `#if`'i C'nin `if`'inden farklıdır: koşul yanlışsa o satırlar hiç derlenmez. Derste anlatılan örnekte makronun değerine göre `#undef` ile eski tanım kaldırılıp yeni değerle yeniden `#define` ediliyordu. <!-- BELİRSİZ: bu örneğin slayttaki tam kodu karelerde görünmüyor; yalnız sözlü anlatım var. --> Derleyicilerin komut satırı seçenekleriyle makro tanımlanabildiği, böylece "hata ayıklama kipi açık" gibi sürümler derlenebildiği de söylendi.

- **Başlık dosyası düzeni.** Hoca sık görülen bir hatayı anlattı: programı modüler yapmak için her fonksiyonun gövdesini ayrı bir `.h` dosyasına koymak. Doğrusu, `.h` dosyasına yalnız yapı tanımları, makro tanımları, fonksiyon prototipleri (ve gerekirse global veri bildirimleri) konması, fonksiyonların gövdelerinin `.c` dosyalarında kalmasıdır.

- **`static` ile otomatik değişken.** Ekrandaki örnek (ekrandan, 01:15:00):

  ```c
  void increment ( void ) {
      int j = 1;
      static int k = 1;
      j++;
      k++;
      printf("j : %d\t k:%d\n", j, k);
  }
  main ( void ) {
      increment(); // j:2 k:2
      increment(); // j:2 k:3
      increment(); // j:2 k:4
  }
  ```

  `j` her çağrıda yeniden 1 ile başlar ve 2 olur. `k` yalnız ilk çağrıda 1 ile ilklenir, adresi sabittir ve program bitene kadar yaşar; bu yüzden 2, 3, 4 olur. Kod `int main(void)` ve `return 0;` eklenerek `gcc -Wall` ile derlenip çalıştırıldı, çıktı slayttakiyle aynıdır.

- **Global değişkenden neden kaçınılır?** Hoca banka hesabı örneği verdi: bakiye global olsun, bir fonksiyon para eklesin, öteki çıkarsın. Toplama ve çıkarma işlemci düzeyinde birkaç küçük adımdan oluşur; iki işlem aynı anda çalışırsa adımlar karışabilir ve 100 liraya 10 eklenip 15 çıkarılmasına rağmen 115 gibi yanlış bir değer görülebilir. Bu, işletim sistemlerinde görülecek karşılıklı dışlama sorunudur. Ayrıca global değişkenler programı analiz etmeyi ve bakımı zorlaştırır. Sayaç veya boyut gibi değerler ya `#define` ile sabit tanımlanmalı ya da parametreyle aktarılmalıdır.

- **`register`.** `register int len;` gibi bir tanım, değişkenin hız için işlemci yazmacında tutulmasını ister; bu her zaman mümkün olmayabilir ve karar derleyicinindir. Yazmaçtaki değişkenin bellek adresi olmadığından `&len` yazılamaz.

- **İşaretçi temel örneği (ekrandan, 01:45:00).**

  ```c
  #include <stdio.h>
  int main(int argc, char *argv[]) {
      short i,j;  //short integers
      short *p;   //pointer to short
      i = 123;    //statement #1
      j = 321;    //statement #2
      p = &i;     //statement #3: p now shows the memory address of i
      j = *p;     //statement #4: * means: use the indirect (pointer) value of p
      printf("i:%d j:%d", i, j);
      i += 2; j += 3; printf("i:%d j:%d", i, j); //statement #5
      return 0;
  }
  ```

  Varsayımsal adreslerle `i` 1200'de, `j` 1202'de, `p` 1204'te olsun (ekrandan, 01:50:00). İlk üç deyimden sonra `i = 123`, `j = 321`, `p = 1200` olur. Dördüncü deyimde `p`'nin gösterdiği 1200 adresindeki 123 değeri `j`'ye kopyalanır (derin kopya); ekrana `i:123 j:123` yazılır. Beşinci deyimde `i` 125, `j` 126 olur; iki değişken artık bağımsızdır. Kod `gcc -Wall` ile derlenip çalıştırıldı, çıktı `i:123 j:123i:125 j:126` oldu (iki `printf`'de `\n` olmadığı için çıktılar bitişik yazılır).
  - Ders sonrası not: Hoca bir yerde son değerleri "123 ve 126" diye söyledi; doğrusu `i = 125`, `j = 126`'dır (hocanın kendi adım adım anlatımı da 125 ve 126'dır).

- **Dev-C++ örneği: adresler ve işaretçiler (ekrandan, 02:05:00, 02:15:00, 02:25:00).** Derste yazılan kod (adres yazdırma satırları ekrandaki gibi `%d` ile):

  ```c
  #include<stdio.h>
  int main(){
      int a,b;
      int c,d;
      int *pa,*pb,*pt,*ptt;
      char ch='a';
      char *pch=&ch;
      a=100;
      b=200;
      c=a; //deep copy
      pa=&a;
      pb=&b;
      pt=&a;
      ptt=pa;
      printf("A:%d Adres-A:%d\n",a,&a);
      printf("A_1:%d A_2:%d Adres-A:%d\n",*pa,*ptt,pt);
      printf("Bu nereden cikti-1 %d %d %d\n",&pa, &pt, &ptt);
      printf("Bu nereden cikti-2 %d %d %d\n",*&pa, &*pt, *&*&ptt);
      printf("Bu nereden cikti-3 %d %d %d\n",&*&pa, *&*pt, &*&ptt);
      pa=pa+1;
      printf("B:%d Adres-B:%d\n",b,pb);
      printf("Yeni Adresler\nA_1:%d A_2:%d Adres-A:%d\n",pa,*ptt,pt);
      printf("Before:C=%c, C=%c &C=%d &C=%d\n",ch,*pch,&ch,pch);
      pch++; //pch=pch+1*sizeof(char)
      printf("After:C=%c, C=%c &C=%d &C=%d\n",ch,*pch,&ch,pch);
  }
  ```

  - Derste bir çalıştırmada ekranda (ekrandan, 02:15:00): `A:100 Adres-A:2358844`, `A_1:100 A_2:100 Adres-A:2358844`, `Bu nereden cikti-1 2358832 2358824 2358816`, `Bu nereden cikti-2 2358844 2358844 2358844`, `Bu nereden cikti-3 2358832 100 2358816`.
  - `a`'ya üç yoldan ulaşılır: `a`, `*pa`, `*ptt`; adresine de `&a` ya da `pt` ile ulaşılır. "Bu nereden çıktı-1" satırı, işaretçilerin kendilerinin de birer değişken olduğunu ve kendi adreslerinin bulunduğunu gösterir; üç değer farklıdır.
  - `*&` ve `&*` birbirini götürür: `*&pa` = `pa`, `&*pt` = `pt`, `*&*&ptt` = `ptt` (hepsi `a`'nın adresi); `&*&pa` = `&pa`, `*&*pt` = `*pt` = 100, `&*&ptt` = `&ptt`.
  - `pa=pa+1;` sonrası `pa` 2358844'ten 2358848'e geçti, yani `sizeof(int)` = 4 bayt ilerledi. `pt` ve `ptt` hâlâ `a`'yı gösterir. `b` ardışık tanımlanmasına rağmen bellekte `a`'nın hemen arkasında değildi; derleyici adresleri istediği sırada verebilir.
  - `pch++` sonrası `pch` 1 bayt ilerledi; `ch` yerinde kaldığı için `ch` hâlâ `'a'`, `*pch` ise sonraki bayttaki rastgele değeri verdi (derste `4` karakteri görüldü).
  - Kod bu hâliyle `gcc -Wall` ile derlenir ama adreslerin `%d` ile yazdırılması için biçim uyarıları verir; 64 bit Linux'ta adresler kesilip negatif sayı olarak görünebilir. Adresler `%p` ve `(void *)` dönüşümüyle yazdırılan bir sürümü derlenip çalıştırıldı ve aynı ilişkiler (cikti-2'deki üç değerin eşitliği, `pa+1`'in 4 bayt, `pch++`'nın 1 bayt ilerlemesi) gözlendi.
  - Ders sonrası not: Ekranda son olarak `pa=pa+1*sizeof(int);` yazıldı (ekrandan, 02:25:00). C'de işaretçi aritmetiği zaten tipin boyutuyla ölçeklenir; bu satır `pa + 4` demektir ve adresi 16 bayt ilerletir. Hocanın anlattığı "adres + 1 × sizeof" kuralı bayt düzeyindeki sonuçtur; kodda yalnız `pa = pa + 1;` yazılmalıdır. Hoca bir yerde bunu `sizeof(pa)` diye de söyledi; doğrusu `sizeof(*pa)` ya da `sizeof(int)`'tir (`sizeof(pa)` işaretçinin kendi boyutudur, 64 bit sistemde büyük olasılıkla 8).

- **Öğrenci sorusu: `%d` ile karakter okumak.** Bir öğrenci, `pch++` sonrası gösterilen değer `%d` ile yazdırılsaydı 4 baytın mı okunacağını sordu. Derste `%d` ile denendi ve 52 çıktı.
  - Ders sonrası not: Hoca 4 baytlık alanın okunduğunu söyledi; doğrusu `*pch` bir `char`'dır ve `printf`'e `int`'e yükseltilerek tek bayt olarak gider. 52, `'4'` karakterinin ASCII kodudur; yani `%c` ile `4` görünen bayt `%d` ile 52 olarak yazıldı.

- Ders sonrası not (döngüde tanım): Hoca `for (int i = 0; ...)` yazımının C'de olmadığını söyledi. Bu, C89/C90 standardı için doğrudur; C99 ve sonrası bu yazıma izin verir. Büyük olasılıkla derste kullanılan derleyici ayarı (C90 kipi) nedeniyle bu kural konmuştur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
