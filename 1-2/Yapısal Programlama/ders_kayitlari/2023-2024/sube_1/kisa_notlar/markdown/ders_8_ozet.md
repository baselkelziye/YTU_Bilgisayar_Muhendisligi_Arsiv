# Ders 8 Çalışma Özeti

## Genel Konular

- Karakter matrisinde gösterici kullanımı (önceki dersin devamı)
  - Bir satırın ortasındaki bir karakterin adresi (`&metinler[0][1]`) bir `char *` parametresine doğrudan verilebilir; fonksiyon o karakterden başlayarak satırı yazar (ekrandan, 00:10:00).
  - `%d` ile iki karakterin farkı yazdırıldığında (`metinler[1][3]-metinler[1][2]`) iki karakterin ASCII kodları arasındaki fark tam sayı olarak çıkar (ekrandan, 00:15:00).
- Göstericiyi gösteren gösterici (çift gösterici)
  - `int r = 5; int *q = &r; int **p = &q;` tanımında `p`, `q`'nun adresini tutar (ekrandan, 00:20:00).
  - `r`, `*q` ve `**p` aynı bellek gözüdür; hangisine değer atanırsa üçü de aynı değeri gösterir.
- Dinamik bellek yönetimi fonksiyonları (`stdlib.h`)
  - `void* malloc(toplam_bayt)`: istenen kadar baytlık alan ayırır, başlangıç adresini döndürür; içeriği sıfırlamaz.
  - `void* calloc(eleman_sayısı, eleman_boyutu)`: aynı işi iki parametreyle yapar ve ayrılan alanı sıfırlar; sıfırlama ek iş olduğu için `malloc` biraz daha hızlıdır.
  - `void* realloc(önceki_gösterici, yeni_toplam_bayt)`: daha önce ayrılmış bloğu büyütür ya da küçültür. Blok yerinde genişleyebilir ya da başka adrese taşınabilir; yeni eklenen kısmın sıfırlanacağının garantisi yoktur, yalnız eski içeriğin korunacağı garantidir (ekrandan, 00:25:00).
  - Dönüş türü `void*` olduğu için sonuç, saklanacak veri türünün göstericisine dönüştürülür (cast).
  - Bellek ayrılamazsa `NULL` döner; bu her zaman kontrol edilir.
  - Her `malloc`/`calloc` için bir `free` yazılır.
- Dinamik iki boyutlu matris
  - Önce `n` tane satır göstericisi için yer ayrılır (`malloc(n * sizeof(int *))`), sonra her satır için ayrı ayrı `m` elemanlık yer ayrılır (`malloc(m * sizeof(int))`) (ekrandan, 00:30:00).
  - Satırların uzunluğu eşit olmak zorunda değildir (düzensiz matris); kısa satırlar için gereksiz yer harcanmaz.
  - Boşaltma ters sırada yapılır: önce döngüyle her satır, en son satır gösterici dizisi.
- `char **text` üzerinde gösterici aritmetiği (17 çıktılı örnek)
  - `text` 3 satırlık, her satırı 64 karakterlik `calloc` ile ayrılmış bir metin matrisidir; satırlar `strcpy` ile doldurulur (ekrandan, 00:40:00 ve 00:45:00).
  - `bp = text[0]`, `mp = text[1]` tek düzeyli `char *` göstericilerdir; `mp+1`, `mp+2` aynı satırda bir sonraki karaktere geçer.
  - `*(*(text+1)+2)` ifadesinde ilk toplama satır, ikinci toplama sütun değiştirir: sonuç `text[1][2]`.
  - Biçim belirteci ile verilen ifadenin türü uyuşmazsa (`%s` ile `char **`, `%c` ile gösterici) çıktı anlamsızdır ya da program çöker.
- Dinamik sıralama (selection sort, bubble sort)
  - Fonksiyonlar dizi yerine dinamik ayrılmış alanın başlangıç göstericisini ve eleman sayısını alır; sayılarda dizgilerdeki gibi bir sonlandırıcı olmadığı için eleman sayısı parametre olarak verilmek zorundadır (ekrandan, 01:50:00).
  - Elemanlara `*(list+i)` biçiminde gösterici aritmetiğiyle erişilir; takasta geçici değişken gösterici değil, değer (`int`) tutar.
- Fonksiyonlara parametre aktarımı
  - C, ilkel değişkenleri değerle aktarır (call by value): fonksiyonun içindeki değişiklik çağırana yansımaz.
  - Değişikliğin kalıcı olması için değişkenin adresi verilir, parametre gösterici olarak tanımlanır ve değişiklik `*` ile yapılır (call by reference; `scanf` de böyle çalışır) (ekrandan, 02:15:00).
  - `swap` örneği: değerle aktarılan sürüm değerleri değiştiremez, adresle aktarılan sürüm değiştirir.
  - C'de aynı adlı ama parametre listesi farklı iki fonksiyon tanımlanamaz (fonksiyon aşırı yüklemesi yoktur); derleyici "conflicting types" hatası verir (ekrandan, 02:25:00).
- Dizilerin parametre olarak aktarılması
  - Sınır denetimi yoktur; eleman sayısı ayrı bir parametre olarak verilmelidir (ekrandan, 02:30:00).
  - `int ar[5]` gibi sabit boyutlu parametre esnek değildir; `int ar[], int size` ya da `int *ar, int size` biçimi tercih edilir.
- Fonksiyondan dizi döndürme
  - Fonksiyon dizinin kendisini değil, başlangıç adresini döndürür; yerel dizi döndürülemez, çünkü fonksiyon bitince yok olur (ekrandan, 02:35:00).
  - Çözüm dinamik bellektir: alan ya fonksiyonun içinde ayrılıp adresi döndürülür (V1) ya da çağıran (`main`) ayırıp fonksiyona parametre olarak verir (V3). İki durumda da `free`, `main` içinde yapılır.
  - Örnek: iki tamsayı dizisini art arda birleştirme (`concatArraysV1`) (ekrandan, 02:50:00).
- Önişlemci makrosu
  - `#define SIZE_OF_ARRAY(x) (sizeof(x) / sizeof((x)[0]))` derlemeden önce metin olarak yerine konur; parametrenin türü yoktur (ekrandan, 02:45:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- `free` atlanmaz
  - Bellek yönetiminin bütün sorumluluğu C'de programcıdadır. Her `malloc`/`calloc` için tam karşılığı olan bir `free` yazılır; iç içe ayırmalarda önce en içteki bloklar boşaltılır. Bu kural hem lab çalışmalarında hem sınavlarda beklenir.
- `NULL` kontrolü
  - Bellek ayrılamamışsa program anlamlı biçimde devam edemez; kullanıcıya bildirilip `return -1` ile çıkılır. `__FILE__` ve `__LINE__` hazır makroları hatanın hangi dosyada ve satırda olduğunu yazdırmak için kullanılabilir.
- `sizeof` kullanımı
  - `n * 4` yerine `n * sizeof(int)` yazılır; `int`'in kaç baytla temsil edildiği platforma göre değişebilir, kod böylece taşınabilir olur.
- Yıldızın yeri
  - `char *bp, *mp;` iki gösterici tanımlar; `char* bp, mp;` yazılırsa yalnız `bp` gösterici olur, `mp` sıradan bir `char` olur. Boşluklar yalnız okunabilirlik içindir.
- Satır önce, sütun sonra
  - `*(*(text+1)+2)` ifadesinde ilk `+1` satırı, ikinci `+2` sütunu değiştirir. Hoca bu örnekte önce yanlış tahmin yapıp sonra düzeltmiş ve aynı hatanın kolay yapılabileceğini vurgulamıştır.
- Ayrılmamış belleğe erişim güvenlik açığıdır
  - Ayrılan alanın dışına erişmek programı çökertebilir ya da başka verileri sızdırabilir (buffer overflow).
- Gösterici aritmetiği kullanın
  - Bundan sonra dinamik alanlarda dizi gösterimi (`b[i]`) yerine `*(b+i)` kullanılması istenir.
- Sınav stratejisi
  - Çıktı tahmini sorularında önce en iyi tahminle hepsi yazılır, zaman kalırsa "hileli" olabilecek yerlere geri dönülür.

## Kısa Tekrar Notları

- `int **p = &q;` gösteriyi gösteren göstericidir; `**p` en sondaki değere ulaşır.
- `malloc(toplam_bayt)` sıfırlamaz; `calloc(adet, boyut)` sıfırlar; `realloc` bloğu taşıyabilir, eski veriyi korur.
- Dönen `void*` istenen türe cast edilir; `NULL` kontrol edilir; her ayırmanın bir `free`'si vardır.
- 2B dinamik matris: `malloc(n*sizeof(int*))` + her satır için `malloc(m*sizeof(int))`; boşaltma: önce satırlar, sonra satır dizisi.
- Satır uzunlukları farklı olabilir (düzensiz matris).
- `*(*(t+i)+j)` = `t[i][j]`; `*(t[i]+j)` = `t[i][j]`; `*(*(t+i))+j` ise `t[i][0]`'ın değerine `j` ekler.
- `%s` bir `char *` bekler, `%c` bir karakter bekler; uyuşmazlık tanımsız davranıştır.
- `char *a, *b;` iki gösterici; `char *a, b;` bir gösterici ve bir karakter.
- Dinamik alan alan fonksiyonlara eleman sayısı da verilir.
- Değerle aktarımda değişiklik kalıcı değildir; adresle aktarımda kalıcıdır.
- C'de fonksiyon aşırı yüklemesi yoktur.
- Yerel dizi döndürülmez; dinamik alanın adresi döndürülür ve `main`'de `free` edilir.
- `SIZE_OF_ARRAY(x)` makrosu yalnız gerçek dizide doğru sonuç verir.

## Detaylı Açıklamalar

**Çift gösterici.** Bir gösterici de bellekte bir değişkendir ve onun da adresi alınabilir. `int r = 5; int *q = &r; int **p = &q;` tanımından sonra `r = 10`, `*q = 11` ya da `**p = 12` atamalarının üçü de aynı gözü değiştirir. Bu ders içinde derlenen programda her atamadan sonra `r`, `*q`, `**p` yazdırıldığında sırasıyla `10 10 10`, `11 11 11`, `12 12 12` çıkar. Hoca bu yapının, bir göstericinin başlangıç yerini tutmak gibi durumlarda işe yarayacağını ve bir yıldızın ya da `&` işaretinin olup olmamasının çok şeyi değiştirdiğini söyledi.

**Bellek ayırma fonksiyonları.** `malloc` toplam bayt sayısını alır. `calloc` eleman sayısı ve eleman boyutu olarak iki parametre alır; toplam alan aynıdır ($n \times \text{eleman boyutu}$), ama `calloc` alanı sıfırlar. `malloc` sıfırlamadığı için alanda önceden kalmış değerler görülebilir. `realloc` mevcut bloğun boyutunu değiştirir; bloğun yerinde mi büyüdüğü yoksa başka bir yere mi taşındığı garanti edilmez (merak edilirse eski ve yeni adres karşılaştırılabilir). Eklenen kısmın sıfırlanması da garanti değildir; garanti olan, eski içeriğin korunmasıdır.

Tipik kullanım: `p = (int *) malloc(n * sizeof(int));` ardından `if (p == NULL) { ... return -1; }`, iş bitince `free(p);`. Diziler bir kez tanımlandıktan sonra eleman sayısı değiştirilemez; dinamik bellekte böyle bir kısıt yoktur.

**Dinamik matris.** Slayttaki örnekte (ekrandan, 00:30:00) `int **mat` için önce `n` tane `int *` kadar yer ayrılır, `NULL` kontrol edilir, sonra her `mat[i]` için `m` tane `int` kadar yer ayrılır. Böylece `mat[0]`, `mat[1]`, ... birer gösterici dizisi elemanı olur ve her biri ayrı bir satırı gösterir. Satırlar farklı uzunlukta ayrılabilir: beş farklı uzunlukta isim saklanacaksa her satıra yalnız gerektiği kadar yer ayrılır ve 5×5 bir kare matristeki boş hücreler hiç yer kaplamaz. Boşaltmada önce döngüyle her satır, sonra `mat` serbest bırakılır.

**Metin matrisi örneği.** `char **text` için `calloc(ROWS, sizeof(char*))`, her satır için `calloc(COLS, sizeof(char))` (ROWS = 3, COLS = 64) ile yer ayrılıp satırlara `"012345\n"`, `"6789AB\n"`, `"CDEFGH\n"` kopyalanır. `bp = text[0]` ve `mp = text[1]` iken:

- `printf("%s", mp)` → `6789AB`, `mp+1` → `789AB`, `mp+2` → `89AB` (`%s` ilk `'\0'`'a kadar yazar).
- `printf("%s", *text)` → `012345`; `*bp` → `0`; `*(bp+2)` → `2`; `**text` → `0`.
- `*(*(text+1)+2)` → `8`, `*((text[1])+3)` → `9`.
- `char *mat[3]` dizgi sabitleri dizisinde `*(*(mat+1))+3` → `'6'+3` = `9`, `*(*(mat+1)+2)` → `8`.
- `%d` ile `mat[2][4]-mat[1][4]` → `'G'-'A'` = 71 − 65 = 6.

Bu sonuçlar ekrandaki çıktı listesiyle aynıdır (ekrandan, 01:35:00) ve ders sonrası gcc ile doğrulandı. `%s` ile `text` (`char **`), `%c` ile `text`, `bp` ya da `*text` vermek "buggy" satırlardır: biçim belirteci ile argüman türü uyuşmadığı için tanımsız davranıştır, ekranda anlamsız karakterler çıkar. `%s` ile `**text` vermek ise programı çökertir.

**Sıralama.** `getPosOfMin(int *list, int n, int fromPos)` `fromPos`'tan sonra en küçük elemanın konumunu döndürür; `selectionSort(int *b, int n)` her adımda bu konumla `i`'yi takas eder (ekrandan, 01:50:00 ve 01:55:00). Fonksiyon tanımında parametre `int *b` olarak yazılır, çağrıda ise yalnız göstericinin adı verilir (`selectionSort(p, n)`), başına `*` ya da `&` konmaz.

**Değerle ve adresle aktarım.** `increaseRegular(a, b)` içinde `a` artırılsa da `main`'de `a` 3 kalır; `increasePointer(&a, b)` ile `*aa += b` yapılınca `main`'de `a` 8 olur. Aynı şekilde `swap1(int x, int y)` değerleri değiştiremez, `swap2(int *x, int *y)` değiştirir: çıktı önce `3 5`, sonra `5 3` olur.

**Fonksiyondan dizi döndürme.** `concatArraysV1` iki diziyi ve boyutlarını alır, `(size1+size2)*sizeof(int)` baytlık yer ayırır, önce birinci diziyi, sonra aynı `i` sayacıyla `arr2[i-size1]` biçiminde ikinci diziyi kopyalar ve yeni alanın adresini döndürür. Birleşik dizinin boyu iki boyun toplamı olduğu için ayrıca döndürülmesi gerekmez. Dönen gösterici `main`'de `free` edilir. V3 sürümünde alan `main`'de `malloc` ile ayrılır ve `void` fonksiyona parametre olarak verilir. Hoca iki yolun da doğru olduğunu, farkın yalnız ayırmanın nerede yapıldığı olduğunu söyledi.

**Ödev olarak bırakılan soru.** İki sıralı dizinin, yeniden sıralama fonksiyonu çağırmadan, iki gösterici ile adım adım karşılaştırılarak sıralı biçimde birleştirilmesi istendi (ekrandan, 02:55:00). Her adımda iki göstericinin gösterdiği değerlerden küçüğü sonuç dizisine yazılır ve o gösterici bir ilerletilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
