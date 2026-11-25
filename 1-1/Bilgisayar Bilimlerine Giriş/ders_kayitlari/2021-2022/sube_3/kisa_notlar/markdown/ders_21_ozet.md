# Ders 21 Çalışma Özeti

## Genel Konular

- C programlama diline giriş
  - C bir sistem programlama dilidir: Unix işletim sistemi C ile yazılmıştır; bir işletim sistemini yazabildiğiniz dille bilgisayarın bütün kaynaklarını kontrol edebilirsiniz.
  - 1972'de ortaya çıkmıştır, yaklaşık 50 yıldır popülerliğini korur.
  - Orta seviyeli (mid-level) bir dildir: ne alt ne üst seviye, ikisinin arasında dengeli bir konumdadır.
  - Büyük-küçük harfe duyarlıdır (case-sensitive): aynı harfin büyüğü yeni bir değişken adı anlamına gelir.
- Derleme süreci ve dosya türleri
  - Kaynak dosya (source file) metin dosyasıdır; derleyici (compiler) onu nesne dosyasına (object file) çevirir; bağlayıcı (linker) nesne dosyalarından çalıştırılabilir dosya (executable file) üretir.
  - Nesne ve çalıştırılabilir dosyalar ikilik (binary) biçimdedir; editörle açılınca anlamsız karakterler görünür, üzerlerinde değişiklik yapılmaz.
  - Örnek: `toplama.c` (kaynak), `toplama.o` (nesne), `toplama` (Linux/MacOS) ya da `toplama.exe` (Windows) (ekrandan, 00:30:00).
  - Birden fazla kaynak dosya varsa her biri ayrı nesne dosyasına derlenir, linker bunları tek çalıştırılabilir dosyada birleştirir (ekrandan, 01:50:00).
- Hata türleri ve hata ayıklama
  - Sözdizimi hatası (syntax error): dilin kuralına uyulmadığında oluşur (yanlış yazılmış anahtar kelime, unutulan noktalı virgül, kapatılmayan parantez). Derleyici yakalar ve uyarı verir.
  - Anlamsal hata (semantic error): mantıksal hatadır, derleyici yakalayamaz. Program çalışır ama segmentation fault, sıfıra bölme, sonsuz döngü ya da yanlış çıktı ortaya çıkabilir.
  - Hata ayıklayıcı (debugger) hataları bulmayı kolaylaştıran araçtır; "bug" adı eski bilgisayarların içine kaçan bir böcekten gelir.
- Program yazmak için gerekenler ve IDE'ler
  - Editör, derleyici ve isteğe bağlı olarak debugger gerekir. Bunları bir arada sunan ortama IDE (Integrated Development Environment) denir.
  - Örnekler: Dev C++, Visual Studio, Eclipse, NetBeans, Code::Blocks, CLion (ekrandan, 00:25:00). Notepad++ yalnız editördür, derleme yapmaz.
  - İşletim sistemine ve 32/64 bit mimariye uygun sürüm kurulur.
- C programının genel yapısı
  - `#include <stdio.h>`: `printf`, `scanf` gibi giriş-çıkış fonksiyonlarını içeren kütüphaneyi ekler. `math.h`, `stdlib.h`, `string.h` da eklenebilir.
  - `< >` sistemin ayarlı kütüphane klasörüne, `" "` kaynak kodun bulunduğu yere göre (göreli yol) bakar.
  - `int main()` zorunlu ana fonksiyondur; `return 0;` (ya da `exit(0);`) programın sorunsuz bittiğini işletim sistemine bildirir. Değer döndürdüğü için başında `int` vardır (ekrandan, 00:35:00).
- Okuma ve yazma işlemleri
  - `scanf("%d", &a);` a değişkeninin adresine bir tam sayı okur; `&` adres işaretidir.
  - `printf("%d", a);` değeri ekrana yazar; adres gerekmez.
  - Sabit metin çift tırnak içinde yazılır; `\n` imleci alt satıra geçirir.
  - Biçim belirteçleri: `%d` tam sayı, `%c` karakter, `%f` kesirli sayı, `%s` karakter dizisi (string), `%x` onaltılık (ekrandan, 01:55:00).
- Aritmetik işlemler
  - `+`, `-`, `*`, `/`, `%` (mod). İki tarafı da tam sayı olan bölme tam sayı bölmesidir: `5/2` sonucu 2; `5.0/2` sonucu 2.5; `5 % 2` sonucu 1.
- Kontrol akışı (if)
  - C'de sıfır olmayan değer doğru (true), sıfır yanlış (false) sayılır: `if(0)` else kolunu, `if(1)`, `if(5)`, `if(-5)` true kolunu çalıştırır.
  - Karşılaştırma işleçleri: `<`, `>`, `<=`, `>=`, `==`, `!=`. Doğru karşılaştırma 1, yanlış karşılaştırma 0 üretir.
  - Mantıksal işleçler: VE `&&`, VEYA `||` (ekrandan, 00:50:00).
  - İç içe if yapısında `else` kendisine en yakın `if` ile eşleşir (ekrandan, 01:10:00).
- Veri tipleri ve değişken tanımlama
  - Temel tipler: `char`, `int`, `float`, `double`; niteleyiciler `short`, `long`, `signed`, `unsigned`; ayrıca `void` (tipsiz).
  - Değişken kullanılmadan önce tipiyle tanımlanır; ilk değer verilmezse bellekte ne varsa o değeri taşır.
- Döngüler: `for`, `while`, `do...while`
- Diziler (arrays)
  - `int a[100];` 100 tam sayı saklar, indisler `a[0]` ile `a[99]` arasıdır (ekrandan, 01:35:00).
  - Elemanlar bellekte kesintisiz, art arda yer alır.
- Açıklama satırları: `//` tek satır, `/* ... */` blok (ekrandan, 01:50:00).
- ANSI C standardı ve taşınabilirlik

## Hocanın Özellikle Vurguladığı Kısımlar

- Kaynak kodda değişiklik yapınca mutlaka yeniden derlemek gerekir
  - Değişiklik ancak derlemeyle nesne ve çalıştırılabilir dosyaya yansır.
  - Çalıştırılabilir dosya başka bir bilgisayara taşınırsa çalışmayabilir; taşınacak olan kaynak koddur, hedef platformda yeniden derlenir.
- Üçlü karşılaştırma (`-1 < 0 < 1`) C'de matematikteki gibi çalışmaz
  - Karşılaştırmalar ikişer ikişer, soldan sağa yapılır: `-1 < 0` sonucu 1, sonra `1 < 1` sonucu 0, else kolu çalışır.
  - Doğrusu `(x < y) && (y < z)` biçimidir. Parantez kullanmak her zaman işi kolaylaştırır.
- Eşitlik denetimi `==` ile yapılır; eşit değildir `!=` ile yazılır.
- if ve else kolunda tek komut olsa bile süslü parantez kullanılması tavsiye edilir.
- Bir if içinde çok sayıda `&&`/`||` kullanmak çok sayıda kontrol demektir; mümkünse bir, en fazla iki-üç bağlaç kullanılır.
- Adım sayısı belli olan iş `for` ile, belli olmayan iş `while` ya da `do...while` ile yazılır
  - Döngüyü erken bitirmek için `for` içinde `i`'yi 100'e eşitlemek ya da `break` kullanmak yapılmamalıdır; böyle bir koşul varsa `while` yazılmalıdır.
- `for` ve `while` başlığının sonuna noktalı virgül konmaz; noktalı virgül yalnız `do...while`'ın sonundaki `while(...)` ifadesinden sonra konur.
- Dizi boyutu kullanıcıdan okunan bir değişkenle (`int a[N];`, N çalışma anında okunuyorsa) tanımlanamaz
  - Tanımlama derleme sırasında yapılır; istisna `#define N 100` önişlemci tanımıdır.
  - Statik yer ayırmada yeterince büyük bir boyut verilir, kullanılmayan alan boş kalır.
- C dizileri 0'dan başlar, ama akış diyagramlarında 1'den n'e kadar indis kullanmak hata riskini azaltır.
- Derste ANSI standartlarına uygun yazım gösterilir; yalnız belirli platformlarda çalışan özellikler programın başka platformda çalışmamasına yol açabilir.

## Kısa Tekrar Notları

- C: sistem programlama dili, Unix, 1972, orta seviye, büyük-küçük harfe duyarlı.
- Kaynak (metin) → derleyici → nesne (binary) → linker → çalıştırılabilir (binary).
- Sözdizimi hatasını derleyici yakalar; anlamsal hatayı yakalayamaz.
- IDE = editör + derleyici + debugger.
- Her programda `#include <stdio.h>`, `int main() { ... return 0; }`.
- `scanf` adrese okur (`&a`), `printf` değeri yazar.
- `%d`, `%c`, `%f`, `%s`, `%x`.
- `5/2 = 2`, `5.0/2 = 2.5`, `5 % 2 = 1`.
- Sıfır dışı değer true, sıfır false; karşılaştırma 1 ya da 0 üretir.
- `-1 < 0 < 1` → 0 (else kolu); `-1 < 0 < 2` → 1 (true kolu).
- `&&` VE, `||` VEYA.
- `else` en yakın `if`'e aittir.
- `char` (her platformda 1 byte) ≤ `short int` ≤ `int` ≤ `long int`; `float` genelde 4, `double` genelde 8 byte.
- `unsigned` yalnız sıfır ve pozitif sayıları saklar.
- `for (i = 0; i < 100; i++)`: expr1 bir kez, expr2 her turdan önce, expr3 her turdan sonra çalışır.
- `i++` ↔ `i = i + 1`, `i--` ↔ `i = i - 1`.
- `int a[100]` → `a[0] ... a[99]`; sınır dışı erişim segmentation fault riski taşır.
- Dizi elemanları bellekte kesintisizdir; bağlı liste (linked list) dağınık saklar ama doğrudan erişim sağlamaz.

## Detaylı Açıklamalar

- **C'nin yeri.** C, Unix işletim sisteminin yazıldığı dil olduğu için bilgisayarın bütün kaynaklarını programlamaya izin veren bir sistem programlama dilidir. Hoca, Python'un da C üzerine inşa edildiğini örnek verir. C orta seviyeli bir dil olarak tanımlanır. Dersin amacı C'yi bütün ayrıntısıyla öğretmek değil, tasarlanan algoritmaları basit C programlarına çevirebilecek kadar bilgi vermektir.

- **Derleme zinciri.** Programcı yalnız kaynak dosyayı (`toplama.c`) yazar; uzantısı mutlaka `.c` olur. Derleyici aynı adlı `toplama.o` nesne dosyasını, linker da `toplama` (Linux/MacOS) ya da `toplama.exe` (Windows) çalıştırılabilir dosyasını üretir (ekrandan, 00:30:00). Böylece tek kaynak dosyalı bir programda klasörde üç dosya oluşur. Kaynak dosya metin olduğu için okunabilir; diğer ikisi byte byte saklanan ikilik dosyalardır. Büyük projelerde birden fazla kaynak dosya, farklı ekip üyelerince yazılabilir; her biri ayrı nesne dosyasına derlenir ve linker hepsini tek çalıştırılabilir dosyada toplar (ekrandan, 01:50:00).

- **Hatalar.** Sözdizimi hatasında derleyici uyarı verir; uyarıdan yola çıkılarak hatanın yeri bulunur. Derleyici her zaman hatanın yerini birebir göstermez, uyarıyı doğru yorumlamak gerekir (örneğin tanımlanmamış değişken için "undefined variable" uyarısı). Anlamsal hatada program derlenir ve çalışır ama yanlış davranır: segmentation fault (bellek hatası), sıfıra bölme, sonsuz döngü ya da yanlış çıktı.

- **Bug hikâyesi.** Derste bir öğrencinin anlattığı ve hocanın onayladığı hikâyeye göre eski, vakum tüplü bilgisayarlarda bir arıza aranırken içeride bir böcek bulunmuş, böcek çıkarılınca bilgisayar düzgün çalışmış; "bug" ve "debug" kavramları buradan gelir.

- **Okuma-yazma.** `scanf("%d", &a);` "a değişkeninin adresine bir onluk tam sayı oku" demektir. Okunan değerin nereye yazılacağını bilmek için adres gerekir, bu yüzden `&` kullanılır. `printf("%d", a);` ise değeri yazar; değerin nerede olduğunu sistem zaten bilir. Birden çok değer `scanf("%d%d", &a, &b);` ile okunabilir; `printf` içinde birinci `%d` birinci değişkene, ikinci `%d` ikinci değişkene karşılık gelir. String okuma-yazma için ileride `gets` ve `puts` kullanılacaktır. `int main(void)` yazımı da doğrudur: `void` fonksiyona parametre aktarılmadığını gösterir, yazmak zorunlu değildir.
  <!-- BELİRSİZ: Okuma-yazma ve aritmetik işlem sayfalarının ekran görüntüsü kare aralığına düşmedi; bu bölümdeki örnek yazımlar altyazıdaki sözlü anlatımdan kuruldu. -->

- **Karakter ve sayı dizileri.** Hoca `%c`, `%s` ayrımını şu dizilerle gösterir (ekrandan, 01:55:00): `1, 2, -3, 5, 0, 7, 6` bir tam sayı dizisidir; `1.1, 2.1, 3.2` kesirli sayı dizisidir; `'a', 'b', '1', ' ', ',', '.'` gibi tek tırnaklı karakterlerden oluşan dizi karakter dizisidir (string). Tek karakter `%c`, karakter grubu `%s` ile okunur. `char a;` için `printf("%c", a);` karakteri, `printf("%d", a);` karakterin ASCII karşılığını basar.

- **if'in çalışması.** C'de koşul ifadesinin sonucu sıfırsa false, sıfır dışındaysa true koluna gidilir. Karşılaştırma işleçleri doğruysa 1, yanlışsa 0 üretir; `if (-1 < 0)` true, `if (0 < -1)` else kolunu çalıştırır (ekrandan, 00:50:00). `if (x) statement1; statement2;` yazımında `statement2` if'e ait değildir, her durumda çalışır. Bir kolda birden fazla komut varsa süslü parantez zorunludur (ekrandan, 00:40:00).

- **İç içe if ile en küçük sayı.** Ekrandaki kod üç sayının en küçüğünü `d` değişkenine atar ve yazar (ekrandan, 01:10:00). Hocanın örnek değerleri `a, b, c = 3, 4, 5` için sonuç 3'tür (gcc ile kontrol edildi).

- **Veri tipleri.** `int` genelde 4 byte, `short int` 2 byte, `long int` 4 ya da 8 byte yer kaplar; bu boyutlar platforma göre değişebilir. Yalnız `char` her platformda 1 byte'tır. Önek verilmezse tipler `signed` kabul edilir. Tanımlama ve ilk değer aynı satırda (`float x = 0.0;`) ya da ayrı ayrı (`float x; x = 0.0;`) yapılabilir (ekrandan, 01:15:00).

- **Döngüler.** `for (i = 0; i < 100; i++)` döngüsünde expr1 (`i = 0`) yalnız bir kez çalışır; expr2 (`i < 100`) her turdan önce denetlenir; gövde çalıştıktan sonra expr3 (`i++`) çalışır (ekrandan, 01:20:00). expr3 yerine `i = i + 2` ya da `i = i * 2` de yazılabilir (ekrandan, 01:25:00). Hocaya göre `i++` makine dilinde artırma (INC), `i = i + 1` toplama (ADD) komutuna karşılık gelir ve INC/DEC daha az işlemci çevrimi alır. Aynı döngü `while` ile `i = 0; while (i < 100) { statement1; i++; }` biçiminde yazılır. `while (x < y) { x++; y--; }` örneğinde x ve y kullanıcıdan okunur; hoca, kullanıcının x'i y'den büyük girmesi durumunda sonsuz döngü oluşacağını söyler ve büyük yazılımlarda kullanıcı girdisinin denetlendiğini, sınav sorularında ise girdinin uygun verildiğinin kabul edildiğini belirtir (aşağıdaki ders sonrası nota bakın). `do { ... } while (i < 100);` yapısında önce iş, sonra kontrol yapılır.

- **Diziler ve bellek.** `int a[100];` için 100 × 4 = 400 byte'lık kesintisiz alan gerekir. Dizinin yalnız başlangıç adresi bilinir; i. elemanın adresi başlangıç adresi + i × eleman boyutu ile hesaplanır, bu yüzden doğrudan erişim (direct access) mümkündür. Elemanları dağınık saklayan yapı bağlı listedir (linked list): her eleman sonrakinin adresini saklar, bu yüzden beşinci elemana ulaşmak için öncekilerin üzerinden geçmek gerekir. Kullanıcıdan N okunup elemanlar `for (i = 0; i < N; i++) scanf("%d", &a[i]);` ile okunur (ekrandan, 01:35:00).

- **Ders sonrası notlar.**
  - Hoca `while (x < y) { x++; y--; }` döngüsünde x > y girilirse sonsuz döngü oluşacağını söyledi; doğrusu bu durumda koşul baştan yanlış olduğu için döngü hiç çalışmaz. Gösterilen kodda sonsuz döngü olmaz, çünkü x artıp y azaldığı için koşul eninde sonunda yanlış olur.
  - Hoca, başlangıç adresi 1000 olan int dizide "beşinci elemana" ulaşmak için 5 × 4 byte eklenip onaltılık 1010'a (onluk olsaydı 1020'ye) gidileceğini söyledi. 5 × 4 = 20 byte onaltılıkta 14 eder; başlangıç onaltılık 1000 ise adres onaltılık 1014, onluk 1000 ise 1020 olur. Ayrıca `a[5]` altıncı elemandır; beşinci eleman `a[4]`, adresi 1000 + 16'dır.
  - Hoca büyük bir dizi için bellekte kesintisiz yer bulunamazsa önce "değerleme (derleme) hatası", sonra derleme aşamasında değil çalışma anında hata alınacağını söyledi; tutarlı olan ikinci ifadedir: bu bir sözdizimi hatası değildir, yer ayrılamaması çalışma anında ortaya çıkar.
  - Hoca `i++` ile `i = i + 1` ifadesinin farklı makine komutlarına (INC ve ADD) çevrildiğini söyledi; bu büyük olasılıkla eski derleyiciler için geçerlidir, günümüz derleyicileri iyileştirme (optimization) ile ikisini çoğunlukla aynı koda çevirir.
  - Hoca if örneğinde bir yerde "x non-zero ise false koluna gider" dedi; kastettiği "x sıfırsa false koluna gider"dir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
