# Ders 10 Çalışma Özeti

## Genel Konular

- Dinamik bellek yönetimine (Dynamic Memory Allocation) giriş
  - `int A[100];` ya da `char C[MAX][MAX];` gibi tanımlar sabit boyutludur; yer derleme zamanında belirlenir ve sonradan büyütülemez, küçültülemez.
  - Boyut program çalışırken belirlenecekse ve gerektiğinde değiştirilecekse dinamik bellek kullanılır. Bu alan belleğin heap bölgesinden alınır.
  - Konu işaretçilerle, fonksiyonlarla, ileride görülecek struct konusuyla (struct içinde dinamik diziler) ve dosya işlemleriyle doğrudan bağlantılıdır.
  - Günlük örnek: bir resim görüntüleyici dosya başlığındaki genişlik, yükseklik ve piksel başına bit bilgisini okuyup bellekte o kadar yer açar. Her resim ya da şarkı farklı boyutta olduğu için yer önceden sabitlenemez.
- Bellek ayırma fonksiyonları (ekrandan, 00:20:00)
  - `void *malloc(total_size_in_bytes)`: verilen bayt kadar yer ayırır, bloğun başlangıç adresini döndürür. Boyut `100 * sizeof(int)` gibi yazılır; `int`'in kaç bayt olduğu ezberlenmez.
  - `void *calloc(number_of_elements, element_size)`: malloc gibidir ama ayrılan baytları sıfırlar. İki parametre alır, çarpımı kendisi yapar; toplam yer yine `n * element_size` kadardır.
  - `void *realloc(void *prev_ptr, total_size_in_bytes)`: daha önce ayrılmış bloğun boyutunu değiştirir. Bloğu yeni bir yere taşıyabilir; eski içerik korunur, eklenen kısım sıfırlanmaz.
  - `void free(void *ptr)`: malloc, calloc ya da realloc ile alınan alanı işletim sistemine geri verir.
  - Dönen `void *` her işaretçi türüne dönüştürülebilen genel işaretçidir. Yer ayrılamazsa `NULL` döner; bu her zaman kontrol edilir.
- Dizi ayırma (Array Allocation) (ekrandan, 00:35:00)
  - `list = (int *) malloc(n * sizeof(int));` ya da `list = (int *) calloc(n, sizeof(int));`
  - `if (list == NULL)` ise `__FILE__` ve `__LINE__` ile hata mesajı yazılır, `return -1;` ile çıkılır. İş bitince `free(list)`.
  - Elemanlara `list[i]` ya da `*(list + i)` ile erişilir.
- Matris ayırma (Matrix Allocation) (ekrandan, 00:40:00)
  - `int **mat;` önce `mat = (int **) malloc(n * sizeof(int *));` ile satır işaretçilerini tutan dizi ayrılır.
  - Sonra her satır için `mat[i] = (int *) malloc(m * sizeof(int));` ile ayrı bir dizi açılır.
  - Her boyut için bir derece daha işaretçi gerekir: 3 boyutlu dizi için `int ***`.
  - Serbest bırakma tersten yapılır: önce `free(mat[i])` ile her satır, en son `free(mat)`.
- Bellek sızıntısı (memory leak)
  - Ayrılan alan `free` edilmezse program boyunca dolu kalır; sürekli görüntü okuyan uygulamalarda bir süre sonra bellek hataları ortaya çıkar.
  - Bir işaretçiye ikinci kez malloc/calloc sonucu atanmadan önce eski alan `free` edilmelidir, yoksa eski alanın adresi kaybolur.
- Dev-C++ uygulamaları
  - Dizi boyutu: `int N = sizeof(a) / sizeof(a[0]);` (ekrandan, 00:55:00).
  - Elemanlara üç yolla erişim: `a[i]`, `*(p + i)` ve `*p` ile yazıp `p++`. Üçüncüsünde `p` dizinin başını kaybeder.
  - Çift işaretçi ile erişim: `p3 = &p2;` sonra `*(*p3 + i)`.
  - Dinamik karakter matrisi: `char **ch`, satır başına `malloc`, `scanf(" %c", ...)`, `*(*(ch + i) + j)` ile yazdırma ve tersten `free` (ekrandan, 01:40:00).
  - realloc'u güvenli kullanmak için geçici işaretçi (`tmp`).
- Fonksiyonlar
  - Kütüphane fonksiyonları ve kullanıcı tanımlı fonksiyonlar vardır.
  - Parametre alıp almamasına ve değer döndürüp döndürmemesine göre dört tür fonksiyon vardır (ekrandan, 01:55:00).
  - Tasarım ilkeleri: düşük bağlılık (low coupling), yüksek uyum (high cohesion).
  - Fonksiyon prototipi (bildirimi), tanımı ve çağrısı; parametre (tanımdaki) ve argüman (çağrıdaki) ayrımı.
- C'de parametre aktarımı
  - C'de argümanlar her zaman değerle (call by value) aktarılır (ekrandan, 02:00:00).
  - Fonksiyonun bir değişkeni değiştirmesi isteniyorsa değişkenin adresi gönderilir ve fonksiyon içinde işaretçi üzerinden (dereferans) atama yapılır. Bu "call by reference" gibi çalışır ama aslında adresin değerle kopyalanmasıdır.
- Dizilerin fonksiyona aktarılması (ekrandan, 02:20:00)
  - `void printArray(int ar[5])`: kullanışlı değil, yalnız bir boyuta uyar.
  - `void printArray(int ar[], int size)` ve `void myFunction(int *ar, int size)`: kullanışlı yöntemler.
  - Diziyi gönderirken yalnız ilk elemanın adresi kopyalanır; fonksiyon içindeki değişiklik asıl diziyi değiştirir. Sınır denetimi yoktur.
- Fonksiyondan dizi döndürme (ekrandan, 02:25:00)
  - C'de dizi döndürülmez, dizinin başlangıç adresini tutan işaretçi döndürülür.
  - Yerel (stack'teki) dizinin adresi döndürülemez, fonksiyon bitince o alan geçersizdir. Çözüm dinamik bellek ayırmaktır.
  - Alternatif (ekrandan, 02:30:00): çağıran taraf boş bir dizi tanımlar ve fonksiyona doldurması için gönderir.
- Örnek programlar
  - Değerle ve adresle swap; dizi ile tek eleman aktarımı farkı; Fibonacci dizisini doldurma; dizinin en küçük elemanını üç farklı dönüş tipiyle bulma; seyrek matrisi sıkıştırma (sparse matris).

## Hocanın Özellikle Vurguladığı Kısımlar

- malloc/calloc sonucunu tür dönüştürme (cast) ile atamak
  - Zorunlu değildir, bazı derleyiciler uyarı verir. Hoca okunabilirlik için yazılmasını istedi: `(int **)` görünce satır işaretçilerinin tutulduğu hemen anlaşılır. Sınavlarda da bunu bekleyeceğini söyledi.
- Matris dinamik olarak bu yöntemle ayrılır
  - Tek boyutlu `malloc(n * m * sizeof(int))` ile matris gibi kullanmak mümkündür. Hoca "matris ayırın" denince satır işaretçileri yöntemini, 3 ya da 4 boyutlu dizide de aynı mantığın genişletilmesini beklediğini söyledi.
- realloc dönüşü doğrudan asıl işaretçiye atanmaz
  - Yer yoksa `NULL` döner. `dizi = realloc(dizi, ...)` yazılırsa eski dizinin adresi kaybolur. Önce `tmp`'ye atanır, `tmp != NULL` ise `dizi = tmp` yapılır.
  - `tmp` ile `dizi` aynı yeri gösterebilir (blok yerinde büyüdüyse); bu yüzden bu durumda `dizi` free edilmez. Bu işlem sığ kopyadır (shallow copy).
- `free` unutulmamalı
  - Free edilmeyen alan tekrar verilemez. Derste aynı boyut ikinci kez istendiğinde, önceki alan free edilmişse aynı adresin yeniden verildiği, edilmemişse başka bir adres verildiği gösterildi.
- `scanf` ve `&`
  - `scanf("%d", &dizi[i])` ya da `scanf("%d", dizi + i)` yazılır. `dizi + i` zaten adres olduğu için `&` gerekmez; `%s` ile string okurken de `&` kullanılmaz.
  - `scanf("%d", dizi[i])` ve `&(dizi + i)` yanlıştır: ilki elemanın değerini adres sanır, ikincisi "adresin adresi" ister ve derlenmez.
- Dizinin bütünü ile tek elemanı farklı davranır
  - Dizi gönderilince elemanlar değişir. Tek eleman (`a[3]`) gönderilince sıradan bir değişken gibi kopyalanır; değiştirmek için adresi (`&a[3]`) gönderilmelidir. Hoca bunu "çok çok önemli" diye vurguladı.
- Yerel dizinin adresini döndürmek
  - Öğrencilerin sık yaptığı hata: fonksiyonda `int d[n];` tanımlayıp `return d;` ya da `return &d[0];` yazmak. Bu alan stack'tedir, fonksiyon bitince yaşamaz.
- Ödevlerde C kullanılmalı
  - Dev-C++'ta dosya C++ olarak kaydedilmemeli; ders C dersidir.

## Kısa Tekrar Notları

- Sabit dizi: derleme zamanında stack'ten, boyut sabit. Dinamik dizi: çalışma zamanında heap'ten, boyut değiştirilebilir.
- `malloc(n * sizeof(T))`: çöp değerli; `calloc(n, sizeof(T))`: sıfırlanmış; `realloc(p, yeni_bayt)`: boyut değiştir; `free(p)`: geri ver.
- Hepsi `void *` döndürür; hata durumunda `NULL`. Her çağrıdan sonra `NULL` kontrolü yapılır.
- `malloc` ve `calloc` için `#include <stdlib.h>` gerekir.
- Matris: `int **mat = (int **) malloc(n * sizeof(int *));` sonra her satıra `malloc(m * sizeof(int))`. Free tersten: satırlar, sonra `mat`.
- realloc: `tmp = realloc(dizi, ...)`; `if (tmp != NULL) dizi = tmp;` değilse eski veri korunur.
- `p++` ile dizide gezinmek dizinin başını kaybettirir; başlangıç adresini ayrı bir işaretçide sakla.
- Fonksiyon türleri: parametre var/yok × dönüş var/yok = 4 tür.
- Düşük bağlılık, yüksek uyum: bir fonksiyon tek bir iş yapar (sıralama fonksiyonu yazdırmaz).
- C'de her şey değerle aktarılır; değiştirmek için adres gönder, `*p` ile ata.
- Diziyi fonksiyona `(int ar[], int size)` ya da `(int *ar, int size)` ile gönder.
- Fonksiyondan dizi değil işaretçi döner; yerel dizinin adresi döndürülmez, malloc ile ayrılan alanın adresi döndürülür.
- Prototip yazılmazsa derleyici uyarı verir; prototip, fonksiyon başlığının kopyalanıp sonuna `;` konmasıyla yazılır.

## Detaylı Açıklamalar

- **Neden dinamik bellek?** `int A[100];` tanımında 100 elemanlık yer derleme zamanında ayrılır. Program sırasında 101. eleman gerekirse genişletmek mümkün değildir; daha az eleman gerekirse yer boşa gider. Hoca, stack bölgesinin sınırlı olduğunu ve işletim sisteminin burada "cimri" davrandığını söyledi. Boyutun kullanıcıdan alındığı, sonradan büyütülüp küçültüldüğü durumlarda dinamik bellek fonksiyonları kullanılır ve alan heap bölgesinden işletim sistemiyle haberleşilerek alınır. Bu alanın işi bitince `free` ile geri verilmesi gerekir ki başka işlemler kullanabilsin.

- **malloc ve calloc farkı.** `malloc(100 * sizeof(int))` 100 tamsayılık yer açar ve ilk baytın adresini `void *` olarak döndürür. Bu alandaki eski çöp değerler olduğu gibi kalır. `calloc(100, sizeof(int))` aynı büyüklükte yer açar ama bütün baytları sıfırlar. Derste malloc ile 6 elemanlı dizi açılıp yazdırıldığında eski çöp değerler ve sıfırlar görüldü; calloc ile açılan dizinin bütün elemanları sıfır çıktı. `sizeof(int)` yerine yanlışlıkla `sizeof(char)` yazılırsa istenen yerin yaklaşık dörtte biri ayrılır; bu yüzden `sizeof` doğru türle yazılmalıdır.

- **Dizi ayırma kalıbı** (ekrandan, 00:35:00):

```c
int n;
int *list;
...
printf("How many numbers are you going to enter ?");
scanf("%d", &n);
list = (int *) malloc( n * sizeof(int) ); //OR: (int *) calloc( n, sizeof(int) );
if(list==NULL) {
    printf("%s:%d>Can not allocate memory for the array...\n",__FILE__, __LINE__);
    return -1;
}
//use the memory and then
free(list);
```

  Programdan `-1` ile çıkmak hata olduğunu gösterir; normal bitişte 0 beklenir.

- **Matris ayırma kalıbı** (ekrandan, 00:40:00). `n` satır, `m` sütunlu matris için önce `n` tane `int *` tutacak bir dizi gerekir; bu dizinin kendisi `int **` türündedir. Sonra her satır ayrı bir `m` elemanlı dizi olarak ayrılır ve adresi `mat[i]`'ye yazılır:

```c
int **mat;
int n,m;
printf("Please enter number of rows");scanf("%d", &n);
printf("Please enter number of columns");scanf("%d", &m);
mat = (int **) malloc( n * sizeof(int *) );
if(mat == NULL) {
    printf("%s:%d>Can not allocate memory for the array...\n",__FILE__, __LINE__);
    return -1;
}
for(i = 0; i < n; i++) {
    mat[i] = (int *)malloc(m * sizeof(int) );
}
```

  Serbest bırakma ayırmanın tersidir: önce `for` ile her `free(mat[i])`, en son `free(mat)`. Önce `mat` free edilirse satırların adresleri kaybolur ve satırlar bellekte sahipsiz kalır.

- **Bellek sızıntısı.** Hoca, birkaç sekme açık bırakılan bir tarayıcının zamanla belleği doldurmasını ve sürekli görüntü işleyen programların free yapmadığında bellek hatası vermesini örnek verdi. Derste aynı `dizi` işaretçisine önce malloc, sonra calloc sonucu atandı. Araya `free(dizi)` konmayınca calloc başka bir adres verdi; konunca aynı adres yeniden verildi. `dizi` işaretçisinin kendisi stack'te, gösterdiği elemanlar heap'tedir; free edilen işaretçi değil, gösterdiği alandır.

- **İşaretçi aritmetiğiyle dizi gezme** (ekrandan, 00:55:00 ve 01:00:00). `int a[]={1,2,3,4,5}; int *p, *p2; p2=p=&a[0];` (ya da `p=a;`). `a[i]`, `*(p+i)` ve `*p; p++;` aynı elemanları yazar. Üçüncü yolda döngü bitince `p` dizinin son elemanından bir sonraki adresi gösterir. Derste `&a[0]` 23FE20, döngü sonundaki `p` 23FE34 çıktı. Başlangıç adresi `p2`'de saklandığı için kaybolmadı; hoca bu "baş" işaretçisi fikrinin bağlı listelerde de (head) kullanılacağını söyledi.
  - Ders sonrası not: hoca adresleri onluk düzende "20, 24, 28, 32, 34" diye saydı. Adresler on altılık düzendedir: 20, 24, 28, 2C, 30 beş elemanın adresidir, 34 ise dizinin hemen dışıdır ($\text{0x23FE20} + 5 \cdot 4 = \text{0x23FE34}$).
  - Çift işaretçi ile: `int **p3 = &p2;` sonra `*(*p3 + i)`: `*p3` dizinin başlangıç adresini verir, `+ i` ile ilerlenir, dış `*` değeri alır.

- **Dinamik karakter matrisi** (ekrandan, 01:35:00 ve 01:40:00). `char **ch` için `M` satır işaretçisi, her satıra `N` karakter ayrıldı. Dış `malloc` başarısızsa "Tip -2 hata" (`return -2`), bir satır başarısızsa "Tip -1 hata" (`return -1`) yazdırıldı. Okumada iki ayrıntı çıktı: döngüde yanlışlıkla iki koşulda da `M` yazılmıştı, bir öğrencinin uyarısıyla içteki `N` yapıldı; `%c` önceki Enter karakterini okuduğu için biçim `" %c"` (önünde boşluk) yapıldı. Yazdırma `printf("%c ", *(*(ch+i)+j));` ile, serbest bırakma `free(ch[i])` döngüsü ve `free(ch)` ile yapıldı. 2×2 matrise A, B, C, D girildi ve matris biçiminde yazdırıldı.

- **realloc ve geçici işaretçi.** realloc istendiğinde iki durum olur: bloğun devamında yeterli boş yer varsa blok yerinde büyür; yoksa yeterli büyüklükte başka bir yer bulunur, eski veriler oraya kopyalanır ve eski yer bırakılır. Her iki durumda da yer bulunamazsa `NULL` döner. Bu yüzden:

```c
tmp = (int *) realloc(dizi, N * sizeof(int));
if (tmp != NULL) {
    dizi = tmp;
} else {
    printf("dizi genisletme hatasi");
    return -3;
}
```

  Derste çok büyük boyutlar istenerek realloc'un başarısız olduğu durum denendi. "dizi genişletme hatası" mesajından sonra eski dizinin elemanlarına hâlâ erişilebildi, çünkü dönüş değeri `tmp`'ye atanmıştı. Bu denemede `INT_MAX` kullanmak için `#include <limits.h>` eklendi ve `INT_MAX*3` yazıldığında derleyici tamsayı taşması (integer overflow) uyarısı verdi.
  <!-- BELİRSİZ: realloc denemesinin tam kodu karelerde yalnız parça parça görünüyor (ekrandan, 01:45:00 ve 01:50:00); yukarıdaki parça anlatımdan ve görünen satırlardan kuruldu. -->

- **Fonksiyon türleri ve tasarım ilkeleri.** Parametre alan/almayan ve değer döndüren/döndürmeyen fonksiyonlar dört grup oluşturur. Slaytta `void hello(){ printf("hello c"); }` dönüşsüz, `int get(){ return 10; }` dönüşlü örnektir (ekrandan, 01:55:00). Çağrı tanıma uygun yapılır: değer döndüren fonksiyonun sonucu bir değişkene atanır ya da `printf` içinde kullanılır. Düşük bağlılık için hoca şu örneği verdi: bir sıralama fonksiyonu diziyi ekrana da yazdırırsa 5 elemanda sorun olmaz ama 5 milyon elemanda gereksiz uzun bir iş olur. Sıralama ve yazdırma ayrı fonksiyonlarda olmalıdır; `sin` fonksiyonu nasıl yalnız sinüs hesaplıyorsa her fonksiyon tek bir amaca hizmet etmelidir. Yüksek uyum, bir fonksiyondaki işlerin birbiriyle ilgili olmasıdır: dizi sıralama, string uzunluğu bulma ve faiz hesabı aynı fonksiyonda yer almaz.

- **Değerle aktarım ve adres gönderme** (ekrandan, 02:05:00). Slayttaki örnekte `a=3, b=5` ile `increaseRegular(a, b)` çağrılır. Fonksiyondaki `aa` ve `bb` kopyadır; `aa += bb` ile fonksiyon içinde 8 yazılır ama `main`'deki `a` 3 kalır. `increasePointer(&a, b)` ile `a`'nın adresi gönderilir, `*aa += bb` asıl değişkeni değiştirir ve `main` de 8 yazar (`gcc -Wall` ile derlenip çalıştırıldı). Parametre adları `main`'deki değişkenlerle aynı olabilir, çünkü kapsamları farklıdır. Swap fonksiyonu da aynı nedenle `swap(&x, &y)` biçiminde çağrılır ve içeride `tmp = *x; *x = *y; *y = tmp;` yazılır.

- **Dizilerin fonksiyona aktarılması** (ekrandan, 02:20:00 ve 02:45:00). Dizi gönderilirken bütün elemanlar kopyalanmaz, ilk elemanın adresi kopyalanır. `write_array(a, N)` ve `write_array(&a[0], N)` aynı işi yapar; `write_array(&a, N)` de aynı adresi gönderir ama türü `int (*)[5]` olduğu için derleyici "incompatible pointer type" uyarısı verir. `INC_array(a, N)` her elemanı bir artırınca `main`'deki dizi 2, 3, 4, 5, 6 oldu. Ardından `a[3]` değerle gönderildiğinde dizi değişmedi; adresle (`&a[3]`) gönderildiğinde dizi 2, 3, 4, 6, 6 oldu.

- **Fonksiyondan dizi döndürme** (ekrandan, 02:25:00). Java ya da C#'taki `int[] f()` gibi bir dönüş tipi C'de yoktur. Yerel `int d[n];` dizisinin adresini döndürmek hatadır, çünkü dizi stack'tedir ve fonksiyon bitince geçersiz olur. Doğrusu `int *p = (int *) malloc(n * sizeof(int));` ile heap'te yer açıp `return p;` yazmaktır; bu alan `free` edilene ya da program bitene kadar yaşar. Derste iki diziyi birleştiren (concat) bir örnek anlatıldı: fonksiyon `size1 + size2` kadar yer açar, birinci diziyi, ardından kaldığı yerden ikinci diziyi kopyalar ve işaretçiyi döndürür. `main` sonucu yazdırıp başka bir fonksiyonda açılmış bu alanı kendisi `free` edebilir. Alternatif yöntemde (ekrandan, 02:30:00) çağıran taraf `size1 + size2` boyutlu boş bir dizi tanımlar ve fonksiyon onu doldurur; hoca bunun dinamik olmadığını, dizinin boyutunun sabit kaldığını belirtti.

- **Fibonacci ve en küçük eleman örnekleri** (ekrandan, 02:50:00 ve 02:55:00). `#define MAX 10` ile tanımlı dizi `fib(dizi)` ile dolduruldu (`dizi[0]=dizi[1]=1`, sonra her eleman önceki ikisinin toplamı). `fib2` aynı işi yapıp `&dizi[0]` döndürdü; dönen işaretçi `write2(int *dizi)` ile yazdırıldı (1, 1, 2, 3, 5, ...). En küçük eleman üç yolla bulundu: `find_min_v1` indisi (`int`), `find_min_v2` elemanın adresini (`int *`, `int *min=&dizi[0];` ile başlar), `find_min_v3` değerin kendisini (`int`) döndürür. Derste 4, 6, 8, 2, 6, 8, 9 girildi; üç fonksiyon da 2 değerine ulaştı.

- **Seyrek matrisin sıkıştırılması** (ekrandan, 03:00:00). Graf teorisinde komşuluk matrisi düğüm sayısının karesiyle büyür ve çoğu eleman 0'dır. Sıfırdan farklı her eleman için (satır, sütun, değer) üçlüsü saklanarak matris sıkıştırılır. Programda `matrix = (int**) malloc(M*sizeof(int*))` ve satırlar ayrıldı; `enter_data` ile değerler okundu, `count_data` sıfırdan farklı eleman sayısını (`counter`) döndürdü, `matrix_compress` `counter × 3` boyutlu yeni bir matrisi fonksiyon içinde ayırıp çift işaretçi olarak döndürdü. `display_matrix` başlık metni, matris ve boyutları alan ortak bir yazdırma fonksiyonudur; `free_matris` her iki matrisi satır sayısıyla (M ve counter) serbest bıraktı. Derste 2×3 matrise 3 0 1 / 6 0 0 girildi; sıkıştırılmış matris (0,0,3), (0,2,1), (1,0,6) oldu.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
