# Ders 5 Çalışma Özeti

<!-- BELİRSİZ: Bu dersin videosu bulunmadığı için ekran karesi çıkarılamadı. Not yalnız altyazıdan yazıldı; slayttaki kodlar ve tablolar görülemedi. Aşağıdaki kod örnekleri hocanın sözlü anlatımından yeniden kuruldu, birebir slayt kodu değildir. -->

## Genel Konular

- Önişlemci (preprocessor) konusunun tekrarı
  - `#define` ile yapılan her tanım, derleyici tarafından kodun kullanıldığı her yere "kopyala-yapıştır" gibi yerleştirilir. Makroların davranışını anlamak için bu mekanizmayı bilmek gerekir.
  - Makrolar özellikle önek/sonek (`++i`, `i++`) kullanımında yan etki üretebilir. Bu tür hataların kaynağını bulmak (debug) zordur.
  - Bir makro `#undef` ile kaldırılıp başka bir değerle yeniden tanımlanabilir.
  - Dille birlikte gelen beş hazır makro: `__LINE__` (satır numarası), `__FILE__` (dosya adı), `__TIME__` (derleme saati), `__DATE__` (derleme tarihi), `__STDC__` (ANSI standardına uyum).
- Koşullu derleme (conditional compilation)
  - Komutlar: `#if`, `#elif` ("else if" anlamında), `#else`, `#endif`. Süslü parantez kullanılamadığı için `#if` bloğunun sonu `#endif` ile belirtilir.
  - Önişlemci komutları kodun başında olmak zorunda değildir; kodun ortasında herhangi bir satırda yer alabilir.
  - Bir makronun tanımlı olup olmadığı `#if defined MAKRO` ya da kısaca `#ifdef MAKRO` ile denetlenir. Tersi `#if !defined MAKRO` ya da `#ifndef MAKRO` ile yazılır.
  - `defined` sonrasındaki parantezler isteğe bağlıdır. <!-- BELİRSİZ: Slayttaki kısa ad / uzun ad karşılık tablosu görülemedi. -->
- `#include` komutunun iki biçimi
  - `#include <dosya.h>`: dosya derleyicinin standart include dizininde aranır (Unix benzeri sistemlerde `/usr/include`; Dev-C++'ta kurulum dizini altındaki `include` klasörü).
  - `#include "dosya.h"`: önce projenin bulunduğu dizin gibi işletim sisteminin ya da derleyicinin belirlediği yerlere, bulunamazsa standart include dizinine bakılır; orada da yoksa hata verilir.
  - Başlık (`.h`) dosyaları veri yapısı tanımları, makrolar, fonksiyon prototipleri ve global değişkenler içerebilir.
- Kapsam (scope)
  - Bir tanımın (değişken ya da fonksiyon) nerede geçerli olduğunu, nereden erişilebildiğini ve ne zaman yok edildiğini belirtir.
  - Program kapsamı / dosya kapsamı: global değişkenler. Fonksiyon kapsamı: fonksiyon içinde tanımlanan değişkenler ve fonksiyon parametreleri. Blok kapsamı: süslü parantezle açılan bir blok içinde tanımlanan değişkenler.
  - Program kapsamındaki bir değişkenin başına `static` yazılırsa onu "dosya kapsamı" diye adlandırmak teknik olarak daha doğrudur.
- `static` yerel değişken
  - Normal yerel değişken fonksiyonun her çağrılışında yeniden ilk değerini alır. `static` yerel değişken ise son değerini korur ve sonraki çağrıda kaldığı yerden devam eder.
- Değer ile aktarma
  - Fonksiyona bir değişken verildiğinde yalnız değeri parametreye kopyalanır. Parametre üzerinde yapılan değişiklik çağıranın değişkenini etkilemez; etkilemek için işaretçiler gerekir.
  - C'de aynı adlı ama farklı parametre listeli fonksiyonlar (aşırı yükleme) tanımlanamaz; Java'dan farklıdır.
- Ezme (shadowing / "override")
  - İç blokta dıştaki ile aynı adlı bir değişken tanımlanırsa, blok boyunca iç tanım dıştakini gizler. Bloktan çıkınca dıştaki değişken değişmemiş olarak geri gelir.
- Değişken sıfatları
  - `auto` (pek kullanılmaz), `static`, `extern` (başka dosyada tanımlı değişken), `register`, `const`, `volatile`.
  - `register`: değişkenin işlemci yazmacında tutulmasını rica eder; garanti yoktur.
  - `const`: değeri değiştirilemeyen değişken; değiştirme girişimi derleyici tarafından reddedilir.
  - `volatile`: derleyicinin bazı optimizasyonlarını devre dışı bırakır (ayrıntıya girilmedi).
- Bellek hiyerarşisi
  - Yazmaçlar (register), L1/L2/L3 önbellek, RAM, sabit disk. Yukarı çıkıldıkça kapasite azalır, hız artar.
- İşaretçilere giriş
  - `*` işaretçi tanımlar; `p = &i;` ile `p`, `i`'nin adresini tutar; `*p` o adresteki değerdir.
  - `j = *p;` yalnız değeri kopyalar; `i` ve `j` yine farklı bellek gözleridir.
- Diziler ve işaretçiler
  - Dizi, aynı türden ardışık bellek gözleridir; indis 0'dan başlar.
  - İlk değer verilmeyen dizi elemanlarının sıfırlanacağının garantisi yoktur; önceki programlardan kalan rastgele değerler görülebilir.
  - `p = &ar[0];` ile `p = ar;` aynıdır. `*(p + i)`, `ar[i]` elemanıdır.
  - İşaretçi aritmetiği türün boyutuna göre ilerler: `short *p` için `p + 1`, 2 bayt ileriyi gösterir.
- Sıralama algoritmaları ve fonksiyonlara bölme
  - 8 elemanlı dizi üzerinde kabarcık sıralaması (bubble sort) önce tek `main` içinde, sonra `enterArray` ve `printArray` fonksiyonlarıyla yazıldı. Ardından seçmeli sıralama (selection sort) `findMinIndex` fonksiyonuyla yazıldı.
  - İki algoritma da iç içe iki döngü içerdiği için $O(n^2)$ karmaşıklığa sahiptir.

## Hocanın Özellikle Vurguladığı Kısımlar

- `#if` ile açılan her blok mutlaka `#endif` ile kapatılmalıdır
  - `#elif` ve `#else` isteğe bağlıdır, ama `#endif` zorunludur.
- `static` "sabit" demek değildir
  - `static` yerel değişkenin değeri fonksiyon bittikten sonra da saklanır ve sonraki çağrıda kaldığı yerden devam eder. Değeri bir kez verilip hiç değişmeyen değişken `const`'tur; ikisi karıştırılmamalıdır.
- Global değişkenlerden mümkün olduğunca kaçınılmalıdır
  - Fonksiyonlar arasındaki bilgi paylaşımı global değişkenlerle değil, parametrelerle ve dönüş değerleriyle yapılmalıdır.
  - Farklı kapsamlar, `static` değişkenler ve ezme yüzünden global değişkenle veri aktarımı bozulmaya açıktır; farkında olmadan bir değişken ezilir ve hatanın kaynağını bulmak çok zorlaşır.
  - Sıralama örneğinde döngü sayaçları (`i`, `j`) global yapılınca fonksiyonlar aynı sayacı bozdu ve dizi doğru sıralanmadı.
- `goto` kullanılmayacak
- İşaretçinin türü, gösterdiği değişkenin ya da dizinin türüyle aynı olmalıdır
- `scanf` ile dizi elemanı okunurken `&` unutulmamalıdır: `scanf("%d", &arr[i]);`
- Dizi elemanlarına uygun ilk değer vermek her zaman yararlıdır
- Tekrarlanan kod parçaları fonksiyona alınmalıdır
  - Diziyi yazdırma işi üç yerde tekrarlanıyordu; bir değişiklik üç yerde yapılmak zorunda kalınır. Odaklanmış fonksiyonlar hata ayıklamayı da kolaylaştırır.

## Kısa Tekrar Notları

- `#if / #elif / #else / #endif`; `#ifdef` = `#if defined`; `#ifndef` = `#if !defined`.
- `<...>` standart include dizini, `"..."` önce proje/OS dizinleri, sonra standart dizin.
- Kapsamlar: program (global), dosya (`static` global), fonksiyon (yerel + parametre), blok.
- `static` yerel değişken çağrılar arasında değerini korur.
- Değer ile aktarmada parametre, argümanın kopyasıdır.
- İç bloktaki aynı adlı değişken dıştakini blok boyunca gizler.
- `register` bir ricadır; `const` değişmez; `extern` dış dosyadaki tanım.
- `p = ar;` geçerli; `ar = p;`, `&p = ar;`, `ar++` geçersiz; `p++` geçerli.
- `*(p + i)` ile `ar[i]` aynı eleman; `short *p` için `p + 1` iki bayt ileri.
- İlk değer verilmemiş dizide rastgele değerler olabilir; dizi sınırı dışına erişim anlamsız değerler verir.
- Bubble sort ve selection sort: $O(n^2)$; 8 elemanda 28 karşılaştırma.

## Detaylı Açıklamalar

- Koşullu derleme örneği
  - Hoca slayttaki örneği şöyle okudu: `X` 1'e eşitse `X` kaldırılıp 0 olarak yeniden tanımlanır; değilse ve `X` 2'ye eşitse `X` kaldırılıp 3 olarak tanımlanır; ikisi de değilse `Y` 4 olarak tanımlanır. `Y`'nin tanımlanması yalnız `X` 1 ya da 2 değilse gerçekleşir.
  - Aşağıdaki kod bu anlatımdan yeniden kuruldu (slayt kodu değildir), `gcc -Wall` ile derlenip çalıştırıldı; `X` 2 iken çıktı `X = 3, Y tanimsiz` oldu.

```c
#include <stdio.h>
#define X 2
#if X == 1
#undef X
#define X 0
#elif X == 2
#undef X
#define X 3
#else
#define Y 4
#endif
int main(void) {
#ifdef Y
    printf("X = %d, Y = %d\n", X, Y);
#else
    printf("X = %d, Y tanimsiz\n", X);
#endif
    return 0;
}
```

- `static` yerel değişken örneği
  - `increment` fonksiyonunda normal bir `c` ve `static` bir `k` değişkeni vardır. Her çağrıda ikisi de bir artırılıp yazdırılır. `main` fonksiyonu `increment`'i üç kez çağırır.
  - Derste çıktıda `c` her seferinde 2, `k` ise sırayla 2, 3, 4 oldu. Aşağıdaki kod anlatımdan yeniden kuruldu, `gcc -Wall` ile derlenip çalıştırıldı ve aynı çıktıyı verdi.

```c
#include <stdio.h>

void increment(void) {
    int c = 1;
    static int k = 1;
    c++;
    k++;
    printf("c = %d, k = %d\n", c, k);
}

int main(void) {
    increment();   /* c = 2, k = 2 */
    increment();   /* c = 2, k = 3 */
    increment();   /* c = 2, k = 4 */
    return 0;
}
```

  - `main` içinden `increment`'in yerel değişkenlerine (`c`, `k`) erişmeye çalışmak "tanımsız" derleme hatası verir. `main` içinde de `c` adlı bir değişken tanımlansa, iki `c` bellekte tamamen farklı yerlerdir.
- Global değişken ve tanım sırası
  - Fonksiyonların dışında tanımlanan `int g = 9;` hem `increment` hem `main` içinden kullanılabilir. Ancak `g`'nin tanımından önce yazılmış bir fonksiyon `g`'yi kullanamaz (tanımsız hatası); her değişken kullanılmadan önce tanımlanmalıdır.
- Değer ile aktarma örneği
  - `int incrementByOne(int a) { return a + 1; }` fonksiyonu `u = incrementByOne(t);` ile çağrıldı; `t = 89` için çıktı `t = 89, u = 90` oldu (derlenip doğrulandı). `t`'nin değeri `a`'ya kopyalanır; `a` fonksiyon bitince yok olur ve `t` değişmez.
  - Hoca önce fonksiyona `increment` adını verdi; aynı adlı fonksiyon zaten olduğu için derleyici kabul etmedi. C'de parametre listesi farklı olsa da aynı adla iki fonksiyon tanımlanamaz.
- Blok kapsamı ve ezme
  - `main` içinde ek süslü parantezlerle yeni bir blok açılıp `int b1 = 7;` tanımlandı ve blok içinde yazdırıldı. Blok dışında `b1++` yazmak "tanımsız" derleme hatası verdi.
  - Ezme örneği: `main` içinde `int t = 89;` yazdırılır, iç blokta `int t = 7;` tanımlanıp yazdırılır, bloktan sonra `t` yeniden yazdırılır. Çıktı `89`, `7`, `89` oldu (derlenip doğrulandı).
  - Hoca bu yapının hata ayıklama kodunda işe yarayabileceğini söyledi: debug kodunda ana koddaki değişkenlere dokunmamak gerekir, yoksa yan etki oluşur. Ama bu biçimde değişken gizlemek kafa karıştırıcı da olabilir.
- `const` örneği
  - `const int c = 11;` tanımlandıktan sonra `c++` yazınca derleyici salt okunur (read-only) değişkenin değiştirilemeyeceğini bildirdi. (Ajanın denediği GCC sürümünde mesaj `increment of read-only variable 'c'` hatasıdır.)
- `register` ve bellek hiyerarşisi
  - Yazmaçlar işlemci çekirdeğinde, aritmetik-mantık birimleriyle aynı silikon üzerindedir; en hızlı ama en kısıtlı bellektir. Normal programlama dilleriyle yazmaçlara doğrudan erişilemez, yalnız assembly ile erişilir.
  - `register` sözcüğü değişkenin yazmaçta tutulmasını yalnız rica eder. Sistemde birçok süreç aynı anda çalıştığı için işletim sistemi bu değeri yazmaçtan çıkarabilir; performans kazancının garantisi yoktur.
  - Önbellek (L1, L2, duruma göre L3) yazmaçtan yavaş, RAM'den hızlıdır. Hiyerarşide yukarı çıkıldıkça kapasite azalır, hız artar.
- İşaretçi örneği (Statement 1-5)
  - `short i, j, *p;` tanımlanır. `i = 123;` (1), `j = 321;` (2), `p = &i;` (3), `j = *p;` (4), sonra `i += 2; j += 3;` (5).
  - Örnek adresler: `i` 1200, `j` 1202, `p` 1204 (short 2 bayt olduğu için). Statement 3 sonrası `p`'nin gözünde 1200 yazar. Statement 4 sonrası 1200 ve 1202 adreslerinin ikisinde de 123 vardır, ama bunlar bağımsızdır.
  - Statement 5 sonrası `i` 125, `j` 126 olur. Kod derlenip çalıştırıldı: `123 123` ve `125 126`.
  - Ders sonrası not: Hoca işaretçi için de 2 baytlık yer ayrılacağını varsaydı. Bu yalnız temsili bir varsayımdır; gerçekte işaretçinin boyutu büyük olasılıkla platforma bağlıdır (32 bit sistemde 4, 64 bit sistemde 8 bayt) ve gösterdiği türden bağımsızdır.
- Dizi tanımı ve bellekte yerleşimi
  - `int ar[5];` tanımında dizi örneğin 1000 adresinden başlar; `int` 4 bayt olduğu için `ar[0]` 1000-1003, `ar[1]` 1004-1007 adreslerindedir. `ar[0] = 15; ar[1] = 17; ar[3] = ar[0] + ar[1];` sonrası `ar[3]` 32 olur; `ar[2]` ve `ar[4]` tanımsızdır.
  - İlk değer listesiyle tanım: `int a[5] = {1, 2, 3, 4, 5};`. Tamsayı dizisine 3.5 yazılırsa değer 3'e çevrilir. Eleman sayısı yazılmadan dört elemanlı bir liste verilirse dizi otomatik olarak dört elemanlı olur.
  - Ders sonrası not: Hoca `int c[5]` dizisine üç değer verilmesinin derleme hatası verebileceğini, belki de kalan elemanlara 0 verileceğini söyledi. C standardında ilk değer listesi eksik kalırsa kalan elemanlar 0 olur, hata verilmez (ajanın GCC denemesinde de böyle).
- Diziye işaretçiyle erişim
  - `short ar[4] = {1, 2, 3, 4}; short *p = ar;` ile `*(p + i)` döngüde 1 2 3 4 yazdırır; `p` hâlâ ilk elemanı gösterir (`*p` = 1).
  - `p++` sonrası `p` ikinci elemanı gösterir; üç elemanlık döngü 2 3 4, `*p` 2 yazdırır (derlenip doğrulandı).
  - Geçersiz atamalar: `ar = p;` (dizi türüne atama yapılamaz), `&p = ar;` (adres ifadesine atama yapılamaz), `ar++` (dizi adı artırılamaz).
  - Dizi sınırının dışına `*(p + i)` ile çıkılınca anlamsız değerler (derste örneğin negatif bir sayı) okundu. Bu normalde yapılmaması gereken bir şeydir.
- Sıralama
  - Kabarcık sıralaması: dış döngü 0'dan $N-2$'ye, iç döngü $i+1$'den $N-1$'e gider; `arr[i] > arr[j]` ise yer değiştirilir. Her değişiklikte dizinin yeni hali yazdırılır.
  - Seçmeli sıralama: her adımda kalan kısmın en küçük elemanının indisi `findMinIndex` ile bulunur ve o eleman baştaki elemanla yer değiştirir. Yer değiştirme için değer değil indis gerekir.
  - `6 5 3 1 8 7 2 4` girdisiyle bubble sort 16, selection sort 6 yer değiştirme yaptı; ikisinde de 28 karşılaştırma yapıldı ($8 \cdot 7 / 2 = 28$).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
