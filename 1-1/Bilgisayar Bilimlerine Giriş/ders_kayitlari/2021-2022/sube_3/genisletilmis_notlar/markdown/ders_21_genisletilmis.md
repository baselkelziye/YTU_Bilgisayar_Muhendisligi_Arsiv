# Ders 21 Genişletilmiş Notu: C Programlama Diline Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Algoritma analizi: değişken izleme tablosu
- 2. C diline genel bakış
- 3. Derleme süreci ve dosya türleri
- 4. Hata türleri ve hata ayıklama
- 5. Geliştirme ortamları (IDE)
- 6. Bir C programının genel yapısı
- 7. Okuma ve yazma işlemleri
- 8. Aritmetik işlemler
- 9. Kontrol akışı: if yapısı
- 10. Karşılaştırma ve mantıksal işleçler
- 11. İç içe if yapıları
- 12. Veri tipleri ve değişken tanımlama
- 13. İlk program: iki sayının toplamı
- 14. Döngüler
- 15. Diziler
- 16. Tekrar ve ek konular: açıklama satırları, taşınabilirlik, biçim belirteçleri
- Örnek Sorular

## 1. Algoritma analizi: değişken izleme tablosu

Dersin başında bir öğrencinin sorusu üzerine hoca, bir algoritmanın analizinin nasıl yapıldığını kısaca özetler. Analiz programdan değil, algoritmanın akış diyagramından yapılır. Algoritmada geçen bütün değişkenlerin adları bir tablonun sütunlarına yazılır. Akış diyagramında adım adım ilerlenirken her adımda değişkenlerin aldığı yeni değerler satır satır tabloya işlenir. Akış diyagramının sonuna gelindiğinde tabloda görülen değerler beklenen değerlerle aynıysa algoritmanın doğru çalıştığı gösterilmiş olur. Temel prensip budur: bütün değişkenleri yazmak, her adımda nasıl değiştiklerini göstermek ve sonucun doğruluğunu kontrol etmek.

Hoca ayrıca dersin amacını belirtir: amaç C dilini bütün ayrıntısıyla öğretmek değil, tasarlanan algoritmaları basit C programlarına çevirebilecek kadar C bilgisi kazandırmaktır. C öğrenmek için özel bir kaynak önermez; "C programming language" aramasıyla bulunan kaynakların çoğu yeterlidir.

## 2. C diline genel bakış

Hoca ilk sayfaya "Introduction C Programming Language" başlığı altında şu maddeleri yazar (ekrandan, 00:15:00): System programming language, Unix OS, 1972, Mid-level programming language, Case-sensitive, Compiler (Derleyici), Source File.

### 2.1 Sistem programlama dili

C bir sistem programlama dilidir; bir bilgisayarın bütün kaynaklarını programlayıp kullanmaya izin verir. Bunun sebebi Unix işletim sisteminin C ile geliştirilmiş olmasıdır. Hocanın ifadesiyle, bir işletim sistemini bir dille yazabiliyorsanız o dille bilgisayarı her anlamda kontrol edebiliyorsunuz demektir.

### 2.2 Tarihçe ve konum

C 1972'de ortaya çıkmıştır; yaklaşık 50 yıldır kullanılır ve teknoloji ölçüsünde çok uzun sayılabilecek bu sürede popülerliğini korumuştur. Hoca, bugün yoğun kullanılan Python dilinin de C üzerine inşa edildiğini örnek verir. C orta seviyeli (mid-level) bir dil olarak tanımlanır: ne alt seviye ne üst seviye, ikisinin arasında dengeli bir konumdadır.

> **Ek bilgi (derste anlatılmadı):** "Python'un C üzerine inşa edilmesi", en yaygın Python yorumlayıcısı olan CPython'un C ile yazılmış olması anlamına gelir.

### 2.3 Büyük-küçük harf duyarlılığı

C büyük-küçük harf ayrımı yapar (case-sensitive). Bir değişken adındaki tek bir harf büyük yazılırsa bu yeni bir değişken anlamına gelir. Bu yüzden kod yazarken harflerin büyüklüğüne dikkat etmek gerekir.

## 3. Derleme süreci ve dosya türleri

### 3.1 Kaynak, nesne ve çalıştırılabilir dosya

Derleyici (C compiler), programcının yazdığı kaynak kodu alıp nesne koduna (object code) çevirir. Aynı dil için birden fazla derleyici olabilir. Derleyicinin amacı yazılan kodu makine diline çevirmek, böylece makinenin anlayıp çalıştırabileceği hale getirmektir.

Süreç şöyle işler (ekrandan, 00:20:00):

- Programcı kaynak dosyayı (source file) yazar. Bu bir metin (text) dosyasıdır.
- Kod kurallara uygun yazıldıysa derleyici onu nesne dosyasına (object file) çevirir. Birden fazla kaynak dosya varsa birden fazla nesne dosyası oluşur. Nesne dosyası ikilik (binary) biçimdedir.
- Bağlayıcı (linker) bütün nesne dosyalarını bir araya getirerek çalıştırılabilir dosyayı (executable file) üretir. Bu dosya da ikilik biçimdedir.

Tek kaynak dosyalı bir programda derlemeden sonra klasörde üç dosya bulunur: kaynak, nesne ve çalıştırılabilir dosya.

### 3.2 Dosyalar okunabilir mi?

Kaynak dosya metin dosyası olduğu için insan gözüyle anlamlı biçimde okunabilir. Nesne ve çalıştırılabilir dosyalar ise byte byte, ikilik biçimde saklandığı için bir editörde açıldığında rakamlar, harfler ve çeşitli sembollerden oluşan anlamsız bir görüntü verir. Bu dosyalar makine diline çevrilmiş olduğu için üzerlerinde değişiklik yapmak kesinlikle uygun değildir. Değişiklik kaynak dosyada yapılır; değişikliğin yansıması için yeniden derleme yapılır, böylece nesne ve çalıştırılabilir dosyalar yeniden oluşur.

### 3.3 Dosya adları

Hoca örnek olarak bir toplama programının dosyalarını yazar (ekrandan, 00:30:00):

- `toplama.c` (Source File): programcının yazdığı kod. Uzantısı mutlaka `.c` olur.
- `toplama.o` (Object File): sistem tarafından üretilir.
- `toplama` ya da `toplama.exe` (Executable File): sistem tarafından üretilir. Uzantısız ad daha çok Linux ve MacOS'ta, `.exe` uzantısı Windows'ta karşımıza çıkar.

Dosya adını programcı verir; adın dosyanın yaptığı işle ilgili olması anlaşılırlığa katkı sağlar.

## 4. Hata türleri ve hata ayıklama

### 4.1 Sözdizimi hatası (syntax error)

Programlama dilinin kuralına uygun yazılmadığında oluşan hatadır. Hocanın örnekleri: `for` yazarken bir harfi fazla yazmak, `while` yazarken bir harfi fazla yazmak ya da unutmak, konması gereken noktalı virgülü unutmak, açılan parantezi kapatmamak, bir anahtar kelimeyi (keyword) yanlış kullanmak. Derleyici derleme sırasında bu hatayı tespit eder ve uyarı verir. Uyarılardan yola çıkılarak hatanın yeri bulunur, düzeltilir ve yeniden derlenince sorun ortadan kalkar.

### 4.2 Anlamsal hata (semantic error)

Mantıksal ve anlamsal bir hatadır; derleyici bu hatayı yakalayamaz ve program çalışır. Ancak çalışırken segmentation fault (bellek hatası), sıfıra bölme (division by zero) hatası verebilir, sonsuz döngüye girebilir ya da istenen çıktıyı üretemeyebilir. Ağırlıklı olarak tasarım hatalarından kaynaklanan bu hatalar programın hatayla sonlanmasına, hiç sonlanamamasına ya da yanlış çıktı üretmesine yol açar.

### 4.3 Debugger ve "bug" sözcüğünün kökeni

Hataları bulmak ve programı analiz etmek için hata ayıklayıcılardan (debugger) yararlanılır. Hoca "bug" sözcüğünün nereden geldiğini sorar.

**Soru:** Hata ayıklamaya neden "böcek bulmak" (debug) denir?
**Cevap:** Bir öğrenci, eski bir bilgisayarda bir arızanın nedeni aranırken içinden böcek çıktığını anlatır. Hoca bunu onaylar ve ayrıntılandırır: mekanik tasarımın ön planda olduğu, vakum tüplerin kullanıldığı dönemde bir arıza incelenirken bir böceğin içeri kaçtığı görülmüş, böcek çıkarıldıktan sonra bilgisayar programı düzgün çalıştırmıştır. "Bir böcek bulduk ve temizledik" ifadesinden "debug" kavramı doğmuştur. Debugger da hataları bulmayı kolaylaştıran bir hata ayıklama aracıdır.

## 5. Geliştirme ortamları (IDE)

Bir C programı yazmak için üç şey gerekir: bir editör, yazılan kodu makine diline çevirecek bir derleyici ve isteğe bağlı (zorunlu olmayan) bir debugger. Bunlar ayrı ayrı araçlar olarak sunulabileceği gibi tek bir çatı altında da sunulabilir. Bu üç özelliği ve başka pek çok ek özelliği bir arada sunan araçlara IDE (Integrated Development Environment, tümleşik geliştirme ortamı) denir.

Hocanın ve öğrencilerin saydığı IDE'ler (ekrandan, 00:25:00): Dev C++, Visual Studio (Microsoft), Eclipse, NetBeans, Code::Blocks, CLion. Bu listenin devamı vardır; bazıları başka dillerin geliştirilmesini de destekler. Notepad ve Notepad++ yalnız editördür: kod yazılabilir ama derleme yapılamaz.

Kurulumda bilgisayarın işletim sistemine (Linux, Windows, MacOS) ve 32 ya da 64 bit olmasına uygun sürüm indirilir. Kurulumdan sonra bir dosya açılır, kod yazılır ve dosya kaydedilir.

## 6. Bir C programının genel yapısı

Hoca bir kaynak dosyanın iskeletini kutu içinde yazar (ekrandan, 00:30:00):

```c
#include <stdio.h>
int main() {

    return 0;
}
```

### 6.1 include satırı

`#include <stdio.h>` (standard input output header) belirli fonksiyonların kullanılabilmesi için bir kütüphanenin koda dahil edilmesidir. Bu kütüphane `printf` ve `scanf` gibi okuma-yazma fonksiyonlarını içerir ve her programda eklenmesi beklenir. `math.h`, `stdlib.h`, `string.h` gibi başka kütüphaneler de `#` işaretinden sonra `include` yazılıp ad küçüktür-büyüktür işaretleri arasına konarak eklenebilir.

Küçüktür-büyüktür (`<stdio.h>`) yazımı, derleme sırasında sistemin ayarlı kütüphane klasörüne bakılacağını söyler. Çift tırnak (`"stdio.h"`) yazımı ise kütüphanenin göreli olarak kaynak kodun bulunduğu yerde aranacağını söyler; kütüphane başka bir yere konmuşsa ya da doğrudan yol verilmek isteniyorsa bu biçim kullanılır.

### 6.2 main fonksiyonu ve return 0

`main`, bir C programının çalışabilmesi için mutlaka bulunması gereken ana fonksiyondur. `return 0;` ifadesi programın sorunsuz çalışıp işini bitirdiğini işletim sistemine bildirir. Fonksiyon bir değer döndürdüğü için başına `int` yazılır. Bazı kaynaklarda `return 0;` yerine aynı anlamda `exit(0);` kullanıldığı görülür (ekrandan, 00:35:00). Bu kalıp sonraki haftalarda yazılacak bütün kodlarda bulunur.

Bu iskeletin içine okuma, yazma, dört işlem, karşılaştırma, `if`, `for`, `while`, `do...while` gibi ifadelerin kod karşılıkları yazılarak, şimdiye kadar tasarlanan algoritmaların programları elde edilir.

**Soru:** `int main(void)` diye yazıldığını gördüm, bu hatalı mı?
**Cevap:** Hayır. `void` bir değişken tipi olmadığını, fonksiyona bir değişken aktarılmadığını gösterir. Bu kullanımda sorun yoktur, ama yazmak zorunlu değildir.

## 7. Okuma ve yazma işlemleri

<!-- BELİRSİZ: Okuma-yazma sayfasının ekran görüntüsü kare aralığına düşmedi; aşağıdaki yazımlar altyazıdaki sözlü anlatımdan kurulmuştur, ekrandaki metin birebir doğrulanamadı. -->

### 7.1 scanf ile okuma

Okuma için `scanf` kullanılır:

```c
scanf("%d", &a);
```

Bu ifade sisteme "a değişkeninin adresine bir onluk (decimal) tam sayı oku" der. `&` (ampersand) işareti adresi, `a` değişkenin adını, `%d` okunacak verinin tipini (onluk tam sayı) gösterir.

### 7.2 printf ile yazma

Değişkenin değerini ekrana yazmak için:

```c
printf("%d", a);
```

Okumadan farkı şudur: okuma adrese yapıldığı için `&` kullanılır; yazdırmada adresle ilgili bir iş yapılmadığı için değer doğrudan ekrana yazılır. Sabit bir metin yazdırmak için değişken kullanılmadan metin çift tırnak içine yazılır; yazdıktan sonra imlecin (cursor) bir alt satıra geçmesi isteniyorsa sonuna `\n` eklenir: `printf("Hello World\n");`.

### 7.3 Birden fazla değer

İki değişken art arda `scanf("%d%d", &a, &b);` ile okunabilir ya da iki ayrı `scanf` ile ayrı ayrı okunabilir. Birden fazla değişken yazdırılırken, örneğin `printf("a'nın değeri %d, b'nin değeri %d", a, b);` yazımında birinci `%d` birinci değişkene, ikinci `%d` ikinci değişkene karşılık gelir ve değişkenlerin o andaki değerleri ekrana yazılır. İleride string (karakter grubu) okurken `scanf` yerine `gets`, yazarken `printf` yerine `puts` fonksiyonları da kullanılacaktır.

### 7.4 Adres işareti neden gerekli?

**Soru:** `&` işaretinin tam olarak ne işe yaradığını anlayamadım.
**Cevap:** `&` değişkenin adresini temsil eder. "Kullanıcıdan değeri al ve bu değişkenin bellekte bulunduğu adrese yaz" demektir. Adres bilgisi olmazsa sistem okunan değeri nereye yazacağını bilemez. Ekrana yazdırırken ise değer yazdırılır; değerin nerede olduğunu sistem zaten bilir. Okumada ilgili değişkenin adresine yazılacağı için adres bilgisini sisteme `&` ile söylemek gerekir.

## 8. Aritmetik işlemler

Temel aritmetik işlemler toplama (`+`), çıkarma (`-`), çarpma (`*`), bölme (`/`), mod alma (`%`) ve tam sayı bölmesidir (div).

C'de tam sayı bölmesi için ayrı bir işleç yoktur; bölmenin her iki tarafı da tam sayıysa bölme tam sayı bölmesi olarak yapılır:

- `5 / 2` sonucu 2'dir, çünkü iki taraf da tam sayıdır.
- `5.0 / 2`, `5 / 2.0` ya da `5.0 / 2.0` normal bölmedir ve sonuç 2.5'tir.

Bu yüzden div türü bir iş yapılacaksa bölmenin iki tarafının da tam sayı sabiti ya da tam sayı değişkeni olması gerekir. Mod alma kalanı verir: `5 % 2` sonucu 1'dir. (Değerler gcc ile kontrol edildi.)

## 9. Kontrol akışı: if yapısı

### 9.1 Üç yazım biçimi

Hoca "Control Flow (if)" başlığı altında üç yazım biçimi gösterir (ekrandan, 00:40:00):

```c
if (x)
    statement1;
statement2;
```

```c
if (x)
    statement1
else
    statement2
statement3;
```

```c
if (x) {
    statement1;
    statement2;
}
else {
    statement3;
    statement4;
}
statement5;
```

### 9.2 C if'i nasıl değerlendirir?

`if` bir koşulu ifade eder; koşul sağlanıyorsa true koluna, sağlanmıyorsa false koluna gidilir (akış diyagramındaki gibi). C'de kural şudur: `x` sıfır olmayan (non-zero) bir değerse true koluna, sıfırsa false koluna gidilir. Yani `if (0)` yazılırsa (varsa) else kolu çalışır; `if (1)`, `if (5)`, `if (-5)` yazılırsa true kolu çalışır. Pratikte `if` içine tek bir değer değil, çoğunlukla karşılaştırma işleçleri yazılır; ama C'nin `if`'i nasıl işlettiğini bilmek gerekir.

> **Ders sonrası not:** Hoca bu kısımda bir yerde "x non-zero bir değerse false koluna gidecektir" dedi; kastettiği "x sıfırsa false koluna gidecektir"dir.

### 9.3 Kolların kapsamı

İlk örnekte yalnız true kolu vardır: `statement1`, x sıfır dışıysa çalışır. x sıfırsa false kolu olmadığı için doğrudan `statement2`'ye geçilir. `statement2` her durumda çalışır, çünkü `if`'e ait değildir; `if`'ten sonra yazılmış sıradaki komuttur.

İkinci örnekte hem true hem false kolu vardır; false kolunun varlığı `else` ifadesinden anlaşılır. `if`'in hemen ardından yazılan `statement1` true kolunu, `else`'in altındaki ifade false kolunu oluşturur. `statement3` yine `if`'ten sonraki komuttur ve iki kola da dahil değildir.

Bir kolda tek komut varsa süslü parantez gerekmez; birden fazla komut varsa (üçüncü örnek) parantez kullanmak zorunludur. Tek komut için parantez koymak hata oluşturmaz.

> **Hocanın vurgusu:** Başlangıçta tek bir iş yapılıyor olsa bile hem true hem false kolu için mutlaka süslü parantez kullanın.

## 10. Karşılaştırma ve mantıksal işleçler

### 10.1 Karşılaştırma işleçleri

Karşılaştırma ifadeleri (comparison expressions): küçüktür `<` (less than), büyüktür `>` (greater than), küçük eşittir `<=` (less than or equal to), büyük eşittir `>=` (greater than or equal to), eşittir `==` (equal to), eşit değildir `!=` (not equal to).

> **Hocanın vurgusu:** Eşitliği kontrol etmek için çift eşittir (`==`), eşit olmamayı kontrol etmek için ünlem-eşittir (`!=`) kullanılır.

### 10.2 Karşılaştırma bir değer üretir

Hoca şu örnekleri tahtada çözer (ekrandan, 00:50:00):

- `if (-1 < 0) { ... } else { ... }`: önce `-1 < 0` değerlendirilir; doğru olduğu için 1 üretir, `if (1)` true koluna gider.
- `if (0 < -1) { ... } else { ... }`: karşılaştırma yanlış olduğu için 0 üretir, `if (0)` else koluna gider.

### 10.3 Üçlü karşılaştırma tuzağı

- `if (-1 < 0 < 1)`: Matematiksel olarak true kolunun çalışması beklenir. Ama C karşılaştırmaları ikişer ikişer, soldan sağa yapar: `-1 < 0` doğrudur ve 1 üretir; ardından `1 < 1` yanlıştır ve 0 üretir. Sonuç olarak else kolu çalışır (ekrandan, 00:50:00).
- `if (-1 < 0 < 2)` (bir öğrencinin sorusu): `-1 < 0` 1 üretir, `1 < 2` doğrudur ve 1 üretir; true kolu çalışır.

Hoca C'nin bu yönünü "iyi ve kötü" bir özellik olarak niteler: hatalı bir mantıkla yazılan ifade bile hata vermeden, dilin kendi kurallarına göre çalıştırılır. Parantez kullanmak her zaman işi kolaylaştırır. (Dört sonuç gcc ile kontrol edildi: 1, 0, 0, 1. gcc bu yazım için "X<=Y<=Z matematiksel anlamını taşımaz" uyarısı verir.)

### 10.4 Mantıksal işleçler

Akış diyagramlarında da görülen VE (AND) ve VEYA (OR) işlemleri C'de sırasıyla `&&` ve `||` ile yazılır (ekrandan, 00:50:00). Örnekler:

```c
if ((x < y) && (y < z))     /* x < y < z anlamında */
if ((x < 0) || (x > 100))
```

"x, y'den küçük ve y, z'den küçük" denmek isteniyorsa ilk biçim kullanılır; `x < y < z` yazmak doğru değildir.

Bir `if` içinde birden fazla `&&` ve `||` kullanmak tek bir kontrol yapıldığı anlamına gelmez; her biri ayrı bir kontroldür. Bu yüzden çok sayıda bağlaçtan kaçınılır; genelde bir, en fazla iki-üç bağlaçla iş görülmesi, tercihen birde kalınması beklenir. Teknik bir sınır yoktur, ama ne kadar çok bağlaç o kadar çok kontrol demektir.

## 11. İç içe if yapıları

Aradan sonra hoca iç içe if (nested if statements) yapısını gösterir (ekrandan, 01:10:00):

```c
if (a < b) {
    if (a < c) {
        d = a;
    }
    else {
        d = c;
    }
}
else if (b < c) {
    d = b;
}
else {
    d = c;
}
printf("%d", d);
```

**Soru:** Bu kod parçası hangi problemi çözer?
**Cevap:** Bir öğrenci sohbetten "en küçük değeri buluyor" diye cevap verir. Üç sayı a, b, c verilir. a < b ise ve a < c ise en küçük sayı a'dır; a < b ama a < c değilse (c < a ise) en küçük c'dir. a < b değilse b, a'dan küçüktür; b aynı zamanda c'den küçükse en küçük b'dir; değilse (c < b < a) en küçük c'dir.

Hoca örnek değerleri `a, b, c = 3, 4, 5` olarak yazar ve kodun 3 değerini vermesini bekler (ekrandan, 01:10:00). (gcc ile çalıştırıldı, çıktı 3.)

Bu kodun asıl amacı iç içe if yazımını göstermektir. Kural: `else` kendisine en yakın `if` ile ilişkilendirilir. Hoca kodu önce parantezsiz yazar, sonra kolların nerede bittiğini göstermek için parantezleri ekler. Bir `else if` varsa `else`'den sonra ayrıca parantez açılmaz, `else if` olduğu gibi kullanılır. Bu örnekte her kolda tek komut olduğu için parantezler kullanılsa da kullanılmasa da kod sorunsuz çalışır.

## 12. Veri tipleri ve değişken tanımlama

### 12.1 Skaler veri tipleri

C'de değişkenin adı yazılıp doğrudan kullanılamaz; mutlaka tipi verilerek tanımlanması gerekir. Temel tipler:

- `char`: karakterleri tutar.
- `int`: tam sayıları tutar.
- `float`: düşük hassasiyetli kesirli sayıları tutar.
- `double`: yüksek hassasiyetli kesirli sayıları tutar.

Bunlara ek olarak `short` ve `long` belirleyicileri vardır; genellikle `short int` ve `long int` biçiminde kullanılırlar. `int` normalde 4 byte, `short int` 2 byte, `long int` 4 ya da 8 byte yer kaplar. Tiplerin kapladığı yer çalıştıkları platforma göre değişebilir. Platformdan bağımsız olarak kesin bilinen tek tip `char`'dır: her platformda 1 byte yer kaplar.

Kesin olarak söylenebilecek sıralama şudur: `char` < `short int` ≤ `int` ≤ `long int`. Boyutlar genelde 1, 2, 4, 4 ya da 8 byte biçiminde ilerler; en büyük alan 8 byte'tır. `float` genelde 4 byte, `double` genelde 8 byte yer kaplar; `double` genelde daha fazla yer kaplar. Birden fazla karakteri saklamak için karakter dizisi (string) kullanılır; bu konu ileride işlenecektir.

### 12.2 signed ve unsigned

Daha önce işaretli ve işaretsiz sayılar olarak görülen ayrım C'de `signed` ve `unsigned` ile ifade edilir. Başına bir şey yazılmayan tipler varsayılan olarak `signed` kabul edilir. `unsigned int` tanımlanırsa bu değişkende yalnız sıfır ve pozitif sayılar saklanır; negatif sayılarla işlem yapılmaz.

### 12.3 Tanımlama ve ilk değer

Hocanın örnekleri (ekrandan, 01:15:00):

```c
int a, b, c;
float x; x = 0.0;
double y, z;
char harf, m;
float x = 0.0;
```

Her değişken kendi tipindeki değerleri saklar. Tanımlanan değişkenin ilk değeri, özellikle bir değer atanmadıysa, bellekte o anda ne varsa odur ve bilinemez. İlk değer verme (ilklendirme) tanımla aynı satırda (`float x = 0.0;`) ya da önce tanım sonra atama biçiminde yapılabilir.

## 13. İlk program: iki sayının toplamı

Hoca ilk derslerde algoritması çözülen toplama işlemini programa dönüştürür. Bundan sonraki kodlarda `#include` satırını yazmaz, eklendiğini varsayar (ekrandan, 01:15:00; programın tamamı altyazıdaki anlatımdan kuruldu):

```c
#include <stdio.h>

int main() {
    int num1, num2, result;
    printf("Iki sayi giriniz\n");
    scanf("%d", &num1);
    scanf("%d", &num2);
    result = num1 + num2;
    printf("Sonuc = %d", result);
    return 0;
}
```

**Soru:** Bu programda bir eksiklik var mı?
**Cevap:** Bir öğrenci `result` değişkeninin tanımlanmadığını söyler. Hoca ilk yazımda `result`'ı tanımlamamıştır ve tanımı ekler (yukarıdaki kod düzeltilmiş halidir). Tanımlanmayan değişken derleme aşamasında hataya yol açar.

Hoca hataları doğru yorumlamanın önemini vurgular: derleyici her zaman hatanın yerini birebir göstermez. Bu örnekte "undefined variable result" gibi açık bir uyarı verir, ama bazen uyarı yalnız yol gösterir ve hatayı programcının görmesi gerekir.

Program çalıştırıldığında ekranda "İki sayı giriniz" yazar ve imleç bir alt satıra geçerek bekler. Kullanıcı 5 girip Enter'a, sonra 6 girip yine Enter'a basar; ekranda "Sonuc = 11" görülür. (Program `gcc -Wall` ile derlendi ve 5, 6 girdisiyle çalıştırıldı; çıktı `Sonuc = 11`.)

## 14. Döngüler

C'de üç döngü vardır: `for`, `while` ve `do...while` (ekrandan, 01:20:00).

### 14.1 for döngüsü

```c
for (i = 0; i < 100; i++) {
    Statement1;
}
```

Bu döngü gövdedeki işi 100 kez yapar. Başlığın üç kısmı sırasıyla expr1, expr2 ve expr3 olarak adlandırılır (ekrandan, 01:20:00):

- expr1 (`i = 0`): döngüye girerken yalnız bir kez çalışır; ilk değer ataması yapılır ve bir daha buraya dönülmez.
- expr2 (`i < 100`): her turdan önce denetlenir; koşul sağlanıyorsa gövde çalışır.
- expr3 (`i++`): gövde çalıştıktan sonra çalışır ve i'yi bir artırır.

expr3'e yalnız `i++` değil, `i = i + 2` ya da `i = i * 2` gibi istenen herhangi bir ifade yazılabilir (ekrandan, 01:25:00).

### 14.2 Artırma ve azaltma işleçleri

`i++` ile `i = i + 1` aynı işi yapar; benzer şekilde `i--` ile `i = i - 1` aynıdır (ekrandan, 01:25:00). Hocanın anlatımına göre fark makine dilindedir: `i++` artırma (INC, increment), `i = i + 1` toplama (ADD) komutunu çağırır; `i--` azaltma (DEC, decrement), `i = i - 1` çıkarma (SUB) komutunu çağırır. Döngülerde artırma ve azaltma çok sık geçtiği için bu özel işleçler yaratılmıştır. Hoca, INC ve DEC'in ADD ve SUB'a göre daha az işlemci çevrimi (cycle) aldığını (örneğin biri iki çevrimde çalışıyorsa diğerinin üç çevrimde çalıştığını) ve bu yüzden bu işleçlerin bir performans kazancı sağladığını söyler.

> **Ders sonrası not:** INC/ADD farkı büyük olasılıkla eski derleyiciler ve işlemciler için geçerlidir; günümüz derleyicileri iyileştirme (optimization) ile `i++` ve `i = i + 1` ifadelerini çoğunlukla aynı makine koduna çevirir.

**Soru:** Süslü parantez kullandığımızda girinti kullanmamıza gerek var mı?
**Cevap:** Hayır, derleyici açısından gerek yoktur. Bütün kod satır bile atlanmadan, noktalı virgüllerle ayrılarak yazılabilir; kurallara uygunsa program çalışır. Ama girinti (indentation) kodun okunabilirliğini artırır. Başka biri ya da programcının kendisi haftalar, aylar sonra koda baktığında girintisiz koddan pek bir şey anlamayabilir. Hoca "şiir gibi kod yazılmış" ifadesini hatırlatarak yazımın önemli olduğunu söyler.

### 14.3 while döngüsü

Yukarıdaki `for` döngüsü `while` ile birebir aynı işi yapacak şekilde şöyle yazılır (ekrandan, 01:25:00):

```c
i = 0;
while (i < 100) {
    statement1;
    i++;
}
```

Ancak adım sayısı belli olduğu için burada `while` kullanmak çok mantıklı değildir. Hoca daha uygun bir örnek verir (ekrandan, 01:25:00):

```c
int x, y;
scanf("%d%d", &x, &y);
while (x < y) {
    x++;
    y--;
}
```

Bu, çalıştırılabilir bir program değil, bir kod parçasıdır. x ve y bilinmez ve kullanıcı tarafından verilir; örneğin x = 5, y = 8 verilebilir. Hoca, kullanıcı tersini (x = 8, y = 5) verirse sonsuz döngü oluşacağını, bu yüzden kullanıcının x'i y'den küçük vermesinin beklendiğini söyler. Büyük yazılımlarda kullanıcıdan alınan değerler denetlenir; ama derste ve özellikle sınav sorularında bu tür denetimler beklenmez, kullanıcının uygun değer vereceği kabul edilir.

> **Ders sonrası not:** Hoca x > y girilirse sonsuz döngü oluşacağını söyledi; doğrusu bu durumda `x < y` koşulu baştan yanlış olduğu için döngü hiç çalışmaz. Gösterilen kodda hiçbir girdi için sonsuz döngü oluşmaz, çünkü x artıp y azaldıkça koşul eninde sonunda yanlış olur. Sonsuz döngü, koşul değişkenlerinin gövdede koşulu yanlışa götürecek biçimde değişmediği durumlarda ortaya çıkar.

**Soru:** for döngüsünde, bir koşul gerçekleşince döngüyü bitirmek için i'yi 100'e eşitleyebilir miyiz?
**Cevap:** Bu asla yapılmaması gereken bir şeydir. `for` adım sayısı belli olan iş içindir. Döngünün arada bitme ihtimali varsa ve adım sayısı belli değilse o koşula göre `while` ya da `do...while` yazılmalıdır.

> **Hocanın vurgusu:** for döngüsünden `break` ile ya da i'nin değerini değiştirerek çıkmayı sakın düşünmeyin. Bu hiç unutulmaması gereken bir kuraldır.

### 14.4 do...while döngüsü

```c
i = 0;
do {
    statement;
    i++;
} while (i < 100);
```

Burada artırma ve gövde, kontrolden önce yapılır. `while`'ın temel prensibi "önce kontrol, sonra iş"tir; `do...while`'da önce bir kez iş yapılır, sonra koşul hâlâ sağlanıyorsa işe devam edilir. Birinde koşulun, diğerinde işin önceliği vardır; tek fark budur.

Yazımda da küçük bir fark vardır: `do`'dan sonra süslü parantez açılır, `while`'dan önce kapanır ve `while (...)` ifadesinin sonuna noktalı virgül konur. Bu yalnız `do...while`'a özgüdür.

> **Hocanın vurgusu:** `for` ve `while` başlığının sonuna kesinlikle noktalı virgül konmaz. Konursa `for` döngüsü gövdedeki işi yapmaz, yalnız boşuna döner; `while` döngüsünde ise koşul değişkeni artık değişmeyeceği için koşul sürekli denetlenir ve sonsuz döngü oluşur.

**Soru:** while ve do...while örneklerinde i'ye sıfır verdiğimiz için tanımlamaya gerek duymadık, değil mi?
**Cevap:** Hayır, bu yanlış bir kanıdır. Bunlar yalnız `for`, `while` ve `do...while` yazımını göstermek için yazılmış kod parçalarıdır; tanımlamalar bilerek yazılmamıştır. Bu parçaların hiçbiri bu haliyle derlenip çalışmaz. Hangi değişken kullanılıyorsa mutlaka kodun içinde tanımlanmalıdır.

## 15. Diziler

### 15.1 Tanım ve indisler

Değişkenler gibi dizilerin (arrays) de bir tipi vardır (ekrandan, 01:35:00):

```c
int a[100];    /* a[0] ... a[99] */
float x[50];   /* x[0] ... x[49] */
```

`int a[100];` bu dizinin 100 tam sayı saklayabileceğini, `float x[50];` 50 kesirli sayı saklayabileceğini söyler. Akış diyagramlarında indisler 1'den 100'e kadar kullanılıyordu; C'de ise indisler 0'dan başlar ve boyuttan bir eksiğe kadar gider: `a[0]`'dan `a[99]`'a, `x[0]`'dan `x[49]`'a. Yalnız bu gözlere erişilebilir.

### 15.2 Sınır dışı erişim

`a[100]`, `x[50]` ya da `x[100]` gibi sınır dışı bir göze erişmeye çalışmak bazen hata vermez, bazen hata verir; bu, o bölgenin başka bir şey tarafından kullanılıp kullanılmadığına bağlıdır. Bölge kullanılıyorsa ya da programın kullanımına verilmemişse erişim segmentation fault hatası oluşturur (ekrandan, 01:35:00). Bu yüzden sınır dışı erişim her zaman segmentation fault ihtimali taşır.

### 15.3 Diziye okuma ve diziyi yazdırma

Dizinin boyutu kullanıcıdan alınır, sonra elemanlar bir döngüyle okunur (ekrandan, 01:35:00):

```c
scanf("%d", &N);
for (i = 0; i < N; i++) {
    scanf("%d", &a[i]);
}
```

Ekrana yazdırma da benzer bir döngüyle `printf` ile yapılır (ekrandan, 01:35:00):

```c
for (i = 0; i < N; i++) {
    printf("%f", x[i]);
}
```

### 15.4 Boyut değişkenle tanımlanabilir mi?

Sık sorulan bir soru, N kullanıcıdan okunduktan sonra `int a[N];` tanımının yapılıp yapılamayacağıdır. Hocanın cevabı: böyle bir tanım olmaz. Tanımlama derleme sırasında yapılır, N'nin değeri ise program çalışırken (runtime) kullanıcıdan alınır. Derleme sırasında değer elde olmadığı için N'lik bir alan ayrılamaz.

Tek istisna önişlemci (preprocessing) ifadesidir (ekrandan, 01:35:00):

```c
#define N 100
int a[N];
```

Kodun başına `#define N 100` yazılırsa derlemeden önce kodda N görülen her yere 100 yazılır ve 100'lük bir dizi tanımlanmış olur.

> **Ek bilgi (derste anlatılmadı):** C99 standardından sonra derleyicilerin çoğu, çalışma anında belirlenen boyutla yerel dizi tanımlamaya (variable length array) izin verir; ama derste gösterilen ANSI C yaklaşımında boyut derleme zamanında bilinmelidir.

Örneğin 100'lük yer açıldı ve kullanıcı 5 değer girdi; kalan 95'lik alan boş durur. Buna statik yer ayırma denir. Kullanıcının verdiği değer kadar yeri çalışma anında ayırmayı sağlayan dinamik bellek ayırma (dynamic memory allocation) sonraki yıl yapısal programlama dersinde görülecektir. Şimdilik dizilere yeterince büyük boyut (50, 100, 200 gibi) verilmesi ve kullanılmayan alanın dert edilmemesi önerilir.

### 15.5 Bellekte yerleşim

Dizi elemanları bellekte kesintisiz, art arda yer alır: `a[0]` bir adresteyse `a[99]`'a kadar bütün elemanlar arka arkaya dizilir. `int` dizide her eleman 4 byte yer kaplar (ekrandan, 01:40:00); 100 elemanlı dizi için toplam 100 × 4 = 400 byte'lık kesintisiz alan gerekir. Bu alan bellekte bütün halinde varsa yer ayrılır, yoksa ayrılamaz ve hata alınır. Bir milyon ya da yüz milyon eleman istendiğinde kesintisiz alan bulma ihtimali azalır ve zaman zaman hatayla karşılaşılabilir. Bu bir sözdizimi hatası değildir; kimse "neden bu kadar büyük yer istiyorsun" diye uyarmaz, ama bellekte yer yoksa çalışma anında hata alınır.

> **Ders sonrası not:** Hoca bu durumda önce "değerleme (derleme) hatası alırsınız", birkaç cümle sonra "değerleme aşamasında bir hata almazsınız, runtime sırasında bu hatayı alırsınız" dedi; tutarlı olan ikinci ifadedir.

Temel prensip: diziler aynı tipte elemanlar saklar ve bunları kesintisiz, arka arkaya saklar.

### 15.6 Neden kesintisiz? Bağlı listeler

**Soru:** Bellekte yer yoksa dizi elemanlarını art arda dizmek yerine iki farklı yere bölse ne sorun çıkar? Nereye koyduğunu kaydetmiyor mu?
**Cevap:** Dizi oluşturulurken sistemin yalnız başlangıç adresini bilmesi yeterlidir. Bir elemana erişmek için başlangıç adresine indis × eleman boyutu eklenir; elemanlar arka arkaya olduğu için hesap sistem tarafından yapılır ve her elemana çok hızlı, doğrudan erişilir. Elemanları dağınık saklamak için farklı bir yapı gerekir: bağlı liste (linked list). Bağlı listede elemanlar bellekte uygun bulunan herhangi bir yere yerleşir ve her eleman bir sonraki elemanın adresini de saklar; bu, her eleman için ek bilgi demektir. Bunun bir handikapı vardır: doğrudan erişim (direct access) mümkün değildir. Dizide istenen elemana doğrudan erişilirken bağlı listede beşinci elemana ulaşmak için önceki dört elemanın üzerinden adres adres atlayarak gitmek gerekir.

Hoca örnek olarak başlangıç adresi 1000 olan bir `int` dizide "beşinci elemana" ulaşmak için 1000. adrese 5 × 4 byte eklendiğini; bunun onaltılık olarak 1010'a, onluk olsaydı 1020'ye karşılık geldiğini söyler.

> **Ders sonrası not:** 5 × 4 = 20 byte, onaltılıkta 14'tür (onaltılık 10 değil). Başlangıç adresi onluk 1000 ise `a[5]`'in adresi 1000 + 20 = 1020; onaltılık 1000 ise onaltılık 1014 olur. Ayrıca indis 0'dan başladığı için `a[5]` altıncı elemandır; beşinci eleman `a[4]`'tür ve adresi 1000 + 4 × 4 = 1016'dır (onluk). (Python ile kontrol edildi.)

## 16. Tekrar ve ek konular: açıklama satırları, taşınabilirlik, biçim belirteçleri

### 16.1 İşlenen konuların özeti

Hoca dersin sonunda işlenen konuları listeler (ekrandan, 01:45:00): genel yapı (general structure), okuma-yazma işlemleri, kontrol akışı (if), aritmetik işlemler ve karşılaştırma ifadeleri, skaler veri tipleri, döngüler (for, while, do...while), diziler. Bu bilgiyle ders kapsamında istenen programların kodu yazılabilir. Sonraki aşamada çok boyutlu diziler (multi-dimensional array) ve karakter dizileri (array of characters, string) işlenecektir (ekrandan, 01:50:00): bir kelime, paragraf ya da metnin bilgisayarda bir dizi üzerinde nasıl saklandığı, akış diyagramı ve kod olarak nasıl ifade edildiği görülecektir.

> **Hocanın vurgusu:** C'de dizi indisleri 0'dan boyut-1'e kadar gider; ama akış diyagramlarında indisleri 1'den n'e kadar kullanmak sizin açınızdan daha doğru olur. 0'dan n-1'e yazmak yanlış değildir, ama en ufak bir hata sıkıntı yaratabilir.

### 16.2 Açıklama satırları

Kodda açıklama (comment) satırı koymak beklenebilir (ekrandan, 01:50:00):

```c
int main() {
    // Comment Line
    /* Block1
       Block2
    */
    return 0;
}
```

`//` tek satırlık açıklama, `/* ... */` birden fazla satırı kapsayan blok açıklamadır. Bu kısımlar derleyici tarafından derlenmez; yalnız kaynak kodda yer alır ve o bölgede ne yapıldığını, bir fonksiyonun görevinin ne olduğunu anlatmaya yardımcı olur.

### 16.3 Yeniden derleme ve taşınabilirlik

Kodda bir değişiklik yapıldığında bunun programa yansıması için mutlaka yeniden derlemek gerekir. Bir bilgisayarda çalışan çalıştırılabilir dosya başka bir bilgisayara götürülürse çalışmaz; taşınacak olan kaynak koddur. Kaynak kod hedef bilgisayarda o platforma uygun derleyiciyle yeniden derlenir ve o bilgisayarın makine diline çevrilir.

### 16.4 ANSI C standardı

Derste American National Standards Institute (ANSI) standartlarına uygun yazım kuralları gösterilir (ekrandan, 01:50:00). Dilin yalnız belirli platformlarda çalışan ek yetenekleri ve fonksiyonları vardır; bunlara özellikle Microsoft tarafında sık rastlanır ve orada birçok hata alınmaz. Ama bu, programın Windows'ta çalışıp Linux'ta çalışmamasına yol açabilir. Bu yüzden standartlara uygun komut ve kullanımlardan yararlanmak çok önemlidir.

### 16.5 Birden fazla kaynak dosya

Bir projede birden fazla kaynak dosya olabilir (ekrandan, 01:50:00). Source File1 ve Source File2 derlenince obj1 ve obj2 oluşur, linker bunlardan tek bir çalıştırılabilir dosya üretir. İleride kodların farklı ekip üyelerince yazılacağı ve bir araya getirilerek tek program altında toplanacağı görülecektir.

### 16.6 Biçim belirteçleri

Hoca okuma-yazma işlemlerine geri dönüp biçim belirteçlerini tamamlar; bunlar hem `scanf` hem `printf` için geçerlidir (ekrandan, 01:55:00):

| Tip | Belirteç |
|---|---|
| Decimal (onluk tam sayı) | `%d` |
| Character (karakter) | `%c` |
| Floating-point (kesirli sayı) | `%f` |
| String (karakter grubu) | `%s` |
| Hexadecimal (onaltılık) | `%x` |

Başka biçimler de vardır, ama şimdilik bunları bilmek yeterlidir.

**Soru:** Dizi okurken `%s` mi kullanıyoruz? Dizide birden çok karakter var.
**Cevap:** Hayır. Tam sayı dizisi tam sayı dizisidir, karakter dizisi değildir. Karakter, tek tırnakla ifade edilen `'a'`, `'b'`, rakam `'1'`, boşluk, virgül, nokta gibi tek simgelerdir; bunlardan oluşan dizi karakter dizisidir, yani string'tir ve `%s` ile okunacağı zamanlar gelecektir. Hoca üç diziyi karşılaştırır (ekrandan, 01:55:00): `1, 2, -3, 5, 0, 7, 6` bir tam sayı dizisidir; `1.1, 2.1, 3.2` bir kesirli sayı dizisidir; `'a', 'b', '1', ' ', ',', '.'` bir karakter dizisidir. Tek bir karakter `%c` ile, karakter grubu `%s` ile okunur.

Hocanın örneği (ekrandan, 01:55:00):

```c
char a;
scanf("%c", &a);
printf("%c", a);
printf("%d", a);
```

`scanf("%c", &a)` a'yı karakter olarak okur, `printf("%c", a)` karakter olarak basar; `printf("%d", a)` ise karakterin ASCII tablosundaki sayısal karşılığını basar (örneğin `'a'` için 97; gcc ile kontrol edildi).

### 16.7 void tipi

Tiplere ek olarak `void` tipi vardır; tipsiz demektir (ekrandan, 01:55:00). Bir fonksiyonun tipi `void` ise o fonksiyon değer döndürmez. Bu konu ilerleyen derslerde ayrıntılı görülecektir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:19:22): Hata ayıklamaya neden "debug" (böcek ayıklama) denir?

> **Çözüm (derste verildi):** Vakum tüplü eski bilgisayarlarda bir arıza aranırken içeri kaçmış bir böcek bulunmuş, böcek çıkarılınca bilgisayar düzgün çalışmıştır. "Bug" hata, "debug" hatayı bulup temizleme anlamında kullanılmaya başlanmıştır.

**Soru 2** (derste sözlü, 00:23:02): C programı yazıp derleyebileceğiniz IDE'lere örnek verin.

> **Çözüm (derste verildi):** Dev C++, Visual Studio, Eclipse, NetBeans, Code::Blocks, CLion (ekrandan, 00:25:00). Notepad++ yalnız editördür, derleme yapmaz.

**Soru 3** (ekrandan, 00:50:00): Aşağıdaki if ifadelerinin her birinde true kolu mu, else kolu mu çalışır?

```c
if (-1 < 0)      { ... } else { ... }
if (0 < -1)      { ... } else { ... }
if (-1 < 0 < 1)  { ... } else { ... }
if (-1 < 0 < 2)  { ... } else { ... }
```

> **Çözüm (derste verildi):** `-1 < 0` → 1, true kolu. `0 < -1` → 0, else kolu. `-1 < 0 < 1` → önce `-1 < 0` = 1, sonra `1 < 1` = 0, else kolu. `-1 < 0 < 2` → önce 1, sonra `1 < 2` = 1, true kolu. (gcc ile kontrol edildi: 1, 0, 0, 1.)

**Soru 4** (ekrandan, 01:10:00): Aşağıdaki kod parçası hangi problemi çözer? `a = 3, b = 4, c = 5` için çıktı nedir?

```c
if (a < b) {
    if (a < c) {
        d = a;
    }
    else {
        d = c;
    }
}
else if (b < c) {
    d = b;
}
else {
    d = c;
}
printf("%d", d);
```

> **Çözüm (derste verildi):** Kod üç sayının en küçüğünü bulur. `a = 3, b = 4, c = 5` için `a < b` ve `a < c` doğrudur, `d = a = 3` olur; çıktı 3'tür. (gcc ile çalıştırıldı.)

**Soru 5** (derste sözlü, 01:16:16): İki sayıyı toplayan aşağıdaki programda bir eksiklik var mı?

```c
int main() {
    int num1, num2;
    printf("Iki sayi giriniz\n");
    scanf("%d", &num1);
    scanf("%d", &num2);
    result = num1 + num2;
    printf("Sonuc = %d", result);
    return 0;
}
```

> **Çözüm (derste verildi):** `result` değişkeni tanımlanmamıştır; derleme hatası alınır. `int num1, num2, result;` biçiminde tanımlanmalıdır. Ayrıca derste bilerek yazılmayan `#include <stdio.h>` satırı tam programda bulunmalıdır. Düzeltilen program 5 ve 6 girdisi için `Sonuc = 11` yazar.

## Dersin Toparlaması

Bu derste C programlama diline giriş yapıldı. C'nin bir sistem programlama dili olarak konumu, kaynak dosyadan nesne dosyasına ve oradan linker ile çalıştırılabilir dosyaya uzanan derleme zinciri, sözdizimi ve anlamsal hatalar ile IDE kavramı anlatıldıktan sonra bir C programının iskeleti (`#include <stdio.h>`, `int main()`, `return 0;`) kuruldu. `scanf` ve `printf` ile okuma-yazma, aritmetik işlemler (özellikle tam sayı bölmesi), C'nin sıfır/sıfır dışı değere göre çalışan `if` yapısı, karşılaştırma ve mantıksal işleçler, üçlü karşılaştırma tuzağı ve iç içe if'lerde `else`'in en yakın `if`'e bağlanması örneklerle gösterildi. Ardından temel veri tipleri, değişken tanımlama, ilk program olarak iki sayının toplamı, üç döngü türü ve hangi durumda hangisinin seçileceği, son olarak da dizilerin tanımı, 0'dan başlayan indisleri, bellekte kesintisiz yerleşimi ve bağlı listeyle farkı işlendi.

Böylece önceki haftalarda akış diyagramı olarak tasarlanan algoritmaları C programına çevirmek için gereken temel araçlar tamamlanmış oldu. Hocanın belirttiğine göre sonraki adımda çok boyutlu diziler ve karakter dizileri (string) ele alınacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
