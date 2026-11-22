# Ders 10 Genişletilmiş Notu: Dinamik Bellek Yönetimi ve Fonksiyonlar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dinamik bellek yönetimine giriş
- 2. Bellek ayırma fonksiyonları
- 3. Dinamik dizi ve matris ayırma
- 4. Belleği serbest bırakma ve bellek sızıntısı
- 5. Dev-C++ uygulaması: işaretçi aritmetiğiyle dizi gezme
- 6. Dev-C++ uygulaması: malloc, calloc ve free
- 7. Dev-C++ uygulaması: dinamik karakter matrisi
- 8. Dev-C++ uygulaması: realloc ve geçici işaretçi
- 9. Fonksiyonlar: türler ve tasarım ilkeleri
- 10. Parametre aktarımı
- 11. Fonksiyon bildirimi, tanımı ve çağrısı
- 12. Dizilerin fonksiyonlara aktarılması
- 13. Fonksiyondan dizi döndürme
- 14. Uygulama örnekleri
- Örnek Sorular

## 1. Dinamik bellek yönetimine giriş

### 1.1 Konunun yeri

Dersin ilk konusu dinamik bellek yönetimi (Dynamic Memory Allocation, DMA), ikinci konusu fonksiyonlardır. Hoca DMA'yı, bundan sonra dinamik bellek gerektiren her işte doğru kullanılması gereken önemli bir konu olarak tanıttı ve bağlantılı olduğu konuları sıraladı:

- **İşaretçiler:** önceki derste görülen işaretçiler, işaretçinin işaretçisi ve `&` operatörü doğrudan kullanılır.
- **Fonksiyonlar:** fonksiyon içinde ayrılan alanın dışarıya aktarılması bu konuya dayanır.
- **Struct'lar:** ileride görülecek yapılarda da dinamik diziler oluşturmak gerekecek.
- **Dosya işlemleri:** dosyadan okunan verinin büyüklüğü önceden bilinmez.

### 1.2 Sabit boyutlu dizinin sınırı

`int A[100];` ya da `#define` ile verilen bir boyutla `char C[MAX][MAX];` gibi tanımlanan diziler sabit boyutludur. Hoca bunların yerinin belleğin stack bölgesinden derleme zamanında ayrıldığını ve değiştirilemeyeceğini anlattı: 100 elemanlı dizi sonradan 101 elemana çıkarılamaz, gerekmediğinde küçültülemez. Stack bölgesi nispeten kısıtlıdır, işletim sistemi orada "biraz daha cimri" davranır. Program çalışırken kendi belirlediğimiz bir boyutta dizi oluşturmak, gerekirse büyütmek ya da küçültmek istiyorsak farklı bir yaklaşım gerekir ve bu yaklaşım işaretçilerin etkin kullanımına dayanır.

### 1.3 Sınıfta tartışma: dinamik bellek deyince ne anlıyoruz?

Hoca konuya geçmeden önce birkaç öğrenciye dinamik belleğin ne olduğunu sordu. Öğrenciler şunları söyledi:

- Statik ve otomatik değişkenlerin yerini işletim sistemi kendisi ayırır ve işi bitince yok eder. Dinamik bellekte yeri programcı kendisi ayırır ve yine kendisi verdiği komutla geri verir. Kaynak koda yazılan komutlarla işletim sistemiyle iletişim kurulur, işletim sistemi de gereken işi yapar.
- Dinamik bellekle dizinin boyutu ayarlanabilir, artırılıp azaltılabilir ve bellekteki veriler programcı tarafından silinebilir.
- Kullanıcıdan alınan veri seti bazen çok büyük, bazen küçük olabilir. Büyük veri gelince bellek artırılır, küçük veri gelince daha küçük bir yer ayrılır.

Hoca bu cevapları doğru buldu.

### 1.4 Günlük örnek: resim ve ses dosyaları

Hoca bir resim görüntüleyicide bir fotoğraf açtı. Altta resmin boyutu 3264 × 1836 × 24 olarak görünüyordu: 3264 × 1836 piksel ve her pikselde 24 bit. Bu, $2^{24}$ farklı renk temsil edilebileceği anlamına gelir. Piksel sayısı fotoğraf makinesinin çözünürlüğüne bağlıdır. Dosyanın özelliklerinde görünen genişlik (width) ve yükseklik (height) bilgisi dosyanın başlığında (header) saklıdır; hoca başlığın ne olduğunu dosya işlemlerinde ayrıca anlatacağını söyledi.

Dosyaya çift tıklayınca ekranda görülen görüntü RAM'den gelir. Program önce dosyanın başlığına bakar: "3264 × 1836 hücre, her hücre 24 bit; bana bu kadar yer aç." Sonra dosyadaki veriyi bu yere matris biçiminde yerleştirir ve ekrana basar. Başka bir resim daha küçük ya da daha büyük olabilir, yine ona göre yer açılır. Müzik çalarken de durum aynıdır: bir şarkı 3, diğeri 13 dakika olabilir, süre önceden belli değildir. Hoca görüntü ve ses işlemede, veri analizinde bu tür ihtiyaçların çok sık olduğunu, C ile yazılmış görüntü işleme kütüphanelerinin arka planda malloc ve dinamik bellek yönetimini kullandığını söyledi. Programcı bunları doğrudan kullanmasa bile kullandığı fonksiyonlar arka planda kullanır.

## 2. Bellek ayırma fonksiyonları

Slaytta dört fonksiyon verildi (ekrandan, 00:20:00):

- `void *malloc( total_size_in_bytes )`: bellekte belirtilen bayt kadar yer ayırır, ayrılan bloğun başlangıcını gösteren bir işaretçi döndürür.
- `void *calloc( number_of_elements, element_size )`: malloc'a benzer ama ayrılan baytları sıfırlar. calloc iki, malloc bir parametre alır; ayrılan toplam yer aynıdır ($\text{total size} = n \cdot \text{element size}$).
- `void *realloc( void *prev_ptr, total_size_in_bytes )`: daha önce ayrılmış `prev_ptr` bloğunun boyutunu değiştirir. Blok yeni bir yere taşınabilir, yeni adres fonksiyonun dönüş değeridir. Blok büyütülürken eklenen kısmın sıfırlanacağı varsayılmamalıdır. Önceden ayrılmış kısmın içeriği ise korunur.
- `void free( void *ptr )`: malloc, calloc ya da realloc ile ayrılmış belleği geri verir.

### 2.1 malloc

malloc'a bayt cinsinden toplam boyut verilir. 100 elemanlı bir tamsayı dizisi için `int`'in 4 bayt olduğu bilinse bile her sistemde aynı olmayabilir; bu yüzden `sizeof` kullanılır: `100 * sizeof(int)`. Hoca bunu slaytın üstüne yazdı.

Dönüş tipi `void *`'dır. Hoca "void görünce hiçbir şey döndürmüyor sanmayın, yanında bir yıldız var" diye uyardı. `void *` her türe dönüştürülebilen genel bir işaretçi türüdür, hocanın deyişiyle bir tür "varyant". Ayrılan yer integer dizisi için kullanılacaksa `int *`'a, karakter için kullanılacaksa `char *`'a dönüştürülür. Fonksiyon, bellekte 100 × `sizeof(int)` baytlık yerin ilk adresini, yani ilk elemanın adresini döndürür; diğer elemanlara işaretçi aritmetiği ya da dizi işlemleriyle erişilir.

**Soru:** Bir öğrenci void dönüş tipinin bir şey döndürmemek anlamına geldiğini sordu. **Cevap:** Yalın `void` olsaydı fonksiyon hiçbir şey döndürmezdi; burada `void *` vardır, yani bir işaretçi döner. Hoca void işaretçiyi fonksiyonlar konusunda ayrıntılı konuşacaklarını söyledi.

### 2.2 calloc

malloc ile ayrılan alanda eski çöp değerler durur ve programcının sıfırlaması gerekir. calloc (clear allocation) bütün değerleri başlangıçta sıfırlar. Tanımdaki fark şudur: çarpma yazılmaz, iki parametre virgülle verilir: "kaç eleman?" (100) ve "her biri ne kadar?" (`sizeof(int)`). Çarpmayı fonksiyon kendisi yapar. Dönen değer yine bir işaretçidir ve bir işaretçi değişkende saklanır.

### 2.3 realloc

realloc daha önce ayrılmış bir bloğun boyutunu değiştirir. Birinci parametre malloc ya da calloc'tan elde edilen işaretçi, ikincisi yine bayt cinsinden yeni boyuttur. 100 elemanlık blok için `80 * sizeof(int)` verilirse blok küçülür, `180 * sizeof(int)` verilirse büyür.

Küçültmede sorun yoktur: blok aynı başlangıç adresinde 80 elemana indirilir. Büyütmede, bulunulan yerin devamında bitişik 180 elemanlık yer yoksa arka planda başka şeyler olur: 180 elemanlık başka bir yer bulunur, eski 100 elemanlık yerdeki değerler oraya kopyalanır ve yeni yerin adresi döndürülür. Bu yüzden realloc'un dönüş değerine her zaman güvenilmez. Yer yoksa `NULL` döner; bu değer doğrudan eski değişkenin üzerine yazılırsa eldeki 100 elemanlık veri kaybedilebilir. Bunun için geçici bir değişken kullanılır: dönüş önce geçici değişkene atanır, `NULL`'dan farklıysa eski değişken artık yeni yeri göstermek üzere güncellenir (bkz. Bölüm 8).

Üç fonksiyonun da dönüşü `NULL` ise yer ayrılamamış demektir. Bu fonksiyonlar işletim sistemiyle haberleşerek çalışır ve aldıkları alan heap bölgesindedir.

### 2.4 free

İşletim sisteminden izin alınarak elde edilen alan, başka işlemlerin kullanabilmesi için yine işletim sistemine geri verilmelidir. Bu üç fonksiyondan biriyle alınan alan `free` ile iade edilir. `free`'ye yalnız elde edilen bellek alanının işaretçisi verilir: `dizi` diye ayrıldıysa `free(dizi)`.

> **Ders sonrası not:** Hoca `free`'nin "herhangi bir şey döndürmediğini, null döndürdüğünü" söyledi. Doğrusu: `free`'nin dönüş tipi `void`'dir, hiçbir değer döndürmez. `NULL` bir işaretçi değeridir, dönüş tipi değildir.

## 3. Dinamik dizi ve matris ayırma

### 3.1 Dizi ayırma (Array Allocation)

Programda `n` elemanlı bir dizi isteniyor; bu bir ses dizisi de olabilir. Kullanıcıya kaç sayı gireceği sorulur, sonra malloc ya da calloc çağrılır (ekrandan, 00:35:00):

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

Fonksiyon `void *` döndürür; integer listesi üzerinde çalışılacağı için `(int *)` ile tür dönüşümü (cast) yapılır. Hoca bazı derleyicilerin cast olmadan hata vermediğini, ama yapılan işin bir integer dizisi oluşturmak olduğunu görmek için cast yazmanın faydalı olduğunu söyledi. Ardından dönen işaretçi `list`'e atanır. Dönüş ya bir adres ya da `NULL`'dır. `NULL` ise ayırma gerçekleşmemiştir: dosya adını ve satır numarasını veren bir mesaj yazılır ve programdan `-1` ile çıkılır. Normalde programın 0 ile bitmesi beklenir; `-1` görülmesi bir hata olduğunu gösterir. `NULL` değilse yer hazırdır: `for (i = 0; i < n; i++)` döngüsünde `list[i]` ile ya da işaretçi aritmetiğiyle `*(list + i)` ile elemanlara erişilir.

calloc'ta dikkat edilecek nokta iki parametre olmasıdır, malloc'ta bir parametre vardır.

### 3.2 Matris ayırma (Matrix Allocation)

Dizi ayırırken derleyiciye söylenen şudur: "Bana `n` elemanlı bir yer aç; açabiliyorsan ilk elemanın adresini gönder." Matriste kullanıcıdan satır ve sütun sayısı alınır. Her satır, sütun sayısı kadar sayıdan oluşan bir dizidir ve bu dizilerden satır sayısı kadar gerekir (0. satır, 1. satır, ..., $n-1$. satır). Her satır bir malloc ile ayrılıp bir işaretçide tutulabilir. Bu işaretçilerin hepsini matris biçiminde tutan başka bir işaretçiye de ihtiyaç vardır. İşaretçiyi tutan işaretçi çift işaretçidir; matris ayırmanın mantığı budur (ekrandan, 00:40:00):

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
//will be continued in the next slide
```

Önce `n` tane `int *` tutan bir dizi ayrılır; `sizeof(int *)` kullanılır, çünkü elemanlar işaretçidir. Dönen değer `NULL` değilse her satır için `m` elemanlı bir integer dizisi oluşturulur ve adresi `mat[i]`'ye kopyalanır. Hoca tahtaya `mat`'tan çıkan yıldızları ve her birinin gösterdiği satır dizilerini çizdi.

**Soru:** Bir öğrenci baştaki cast işlemlerinin zorunlu olup olmadığını, derleyicinin bunu kendisi yapıp yapmadığını sordu. **Cevap:** `void *` her türe dönüştürülebilir, bu yüzden zorunlu değildir; ama bazı derleyicilerde hata, en azından uyarı alınabilir. Ayrıca okunabilirliği artırır: `(int **)` görülünce `n` tane işaretçi tutulduğu, bunların ikinci dereceden işaretçide saklandığı hemen anlaşılır.

> **Hocanın vurgusu:** Hoca cast yazılmasını istedi ve sınavlarda da bunu bekleyeceğini söyledi.

Hoca matrisi şöyle özetledi: $n \times m$'lik matriste her satır, dinamik bellekle oluşturulmuş ayrı bir dizi gibi düşünülür. Matris biçiminde saklayabilmek için bu dizilerin başlangıç adreslerinin ayrı bir yerde, ikinci dereceden bir işaretçide tutulması gerekir. Önce dizilerin başlangıç adreslerini tutan işaretçi dizisi oluşturulur; bu başarılı olursa her satır için yeni bir integer dizisi oluşturulur ve adresi matrisin $i$. elemanında saklanır.

Bir alternatif de tek boyutlu bir dizi açıp matris gibi kullanmaktır: `int *m = malloc(n * M * sizeof(int));`. Hoca bunun kullanılabileceğini, ama sınavda "matris ayırın" dendiğinde matrisin yukarıdaki yöntemle ayrılmasını beklediğini söyledi.

> **Hocanın vurgusu:** Üç ya da dört boyutlu dizi istendiğinde aynı mantık genişletilir; her boyut için bir derece daha işaretçi gerekir.

## 4. Belleği serbest bırakma ve bellek sızıntısı

### 4.1 Matrisi serbest bırakma

Matris serbest bırakılırken ayırma işi tersten yapılır. Önce her satır dizisi `free(mat[i])` ile, en son satır işaretçilerini tutan dizi `free(mat)` ile bırakılır. Hoca slayttaki free döngüsünde bir hata olduğunu ve orada `free(mat[i])` yazılması gerektiğini belirtti. Satırlar bırakılınca o alanlar gider, geriye yalnız işaretçileri tutan dizi kalır; en son o da bırakılır ve bütün bellek başka işlemlerin kullanabileceği hale gelir.

### 4.2 Bellek sızıntısı (memory leak)

Free yapmak belleğin gereksiz kullanımını engeller. Program bir yerde çökerse ve alan o satıra kadar free edilmediyse alan kullanılmaya devam edebilir; buna bellek sızıntısı (memory leakage) denir. Hoca kendi denediği bir örneği anlattı: bir tarayıcıda 3-4 sekme açıp hiçbir şey yapmadan beklendiğinde, RAM yetersizse bir süre sonra bilgisayar bellek hatası verebiliyor, hatta yeniden başlayabiliyordu, çünkü sürekli bir sızıntı vardı. Sürekli görüntü okuyup işleyen uygulamalarda da bellek gerektiği gibi serbest bırakılmazsa bir süre sonra bellek hataları oluşur.

## 5. Dev-C++ uygulaması: işaretçi aritmetiğiyle dizi gezme

Hoca önceki dersi tekrar etmek için önce dinamik bellek kullanmadan, dizi ve işaretçi aritmetiğiyle bir örnek yazdı. Bundan sonraki konuların daha çok kod yazma üzerine olacağını söyledi.

### 5.1 Dizinin boyutu ve üç yazdırma yolu

Kodun son hali (ekrandan, 00:55:00 ve 01:00:00):

```c
#include<stdio.h>

int main(){

    int a[]={1,2,3,4,5};
    int *p, *p2,i;
    int N=sizeof(a)/sizeof(a[0]);
    p2=p=&a[0]; // p=a;

    for(i=0;i<N;i++){
        printf("%d - %d \n",a[i],*(p+i));
    }
    //p=&a[0];
    printf("\n");
    for(i=0;i<N;i++){
        printf("%d - %d \n",a[i],*p);
        p++; //p=p+1*sizeof(a[0]);
    }
    printf("\n &A[0]:%p----&A[X]:%p" ...);
    return 0;
}
```

<!-- BELİRSİZ: son printf satırının argümanları karede yazılırken kesik görünüyor (ekrandan, 01:00:00); anlatıma göre p2 ve p yazdırıldı. -->

`sizeof(a)` dizinin bellekte kapladığı toplam baytı, `sizeof(a[0])` tek bir elemanın baytını verir. Bölüm $\frac{5 \cdot \text{sizeof(int)}}{1 \cdot \text{sizeof(int)}} = 5$ eder; `int`'in kaç bayt olduğu önemli değildir. `p = &a[0]` yerine `p = a` da yazılabilir, çünkü dizinin adı ilk elemanın adresini tutan etikettir.

Birinci döngüde `a[i]` ile `*(p+i)` yan yana yazılır: `p` bir adrestir, `p + i` yeni bir adres hesaplar ve `*` o adresteki değeri getirir. İkinci döngü üçüncü bir yazım biçimidir: `p`'nin gösterdiği yerdeki değer yazılır, sonra `p` bir artırılır. `p++` aslında `p = p + 1*sizeof(a[0])` anlamına gelir; integer dizisinin her elemanı bir integer olduğu için adres bir eleman boyu ilerler.

Hoca programı çalıştırınca ekranda "Return value 5" gördüklerini, bunun `return 0;` yazılmadığı için son `printf`'in döndürdüğü değer olduğunu açıkladı ve `return 0;` ekledi.

> **Hocanın vurgusu:** Ödevlerde Dev-C++'ta dosyayı C++ olarak seçmeyin. Bu ders C dersidir; C++ kodu kabul edilmeyecektir.

### 5.2 Üçüncü yolun sorunu

**Soru (hocanın sorusu):** Üçüncü yazım biçiminde nasıl bir sorunla karşılaşabiliriz? **Cevap (bir öğrenci):** `p` dizinin başlangıcını gösteren bir işaretçiydi; her artırmada bir sonraki elemanı gösterir ama böylece dizinin başı kaybedilebilir. Hoca cevabı doğru buldu: geri dönmek için ne kadar ileri gidildiyse o kadar geri gelmek gerekir.

Hoca bunu göstermek için `p2` ve `p`'yi `%p` ile yazdırdı. `&a[0]` 23FE20 çıktı; döngü sonunda `p` 23FE34'ü gösteriyordu, yani dizinin dışına çıkmıştı. Başlangıç adresi `p2`'de saklandığı için kaybolmadı. Hoca bu yöntemin kullanılabileceğini, bir yedek tutmak yeterli olduğunu söyledi; bağlı listelerde ve veri yapılarında da başlangıç elemanını tutan bir "head" olacak, bir başka işaretçiyle liste içinde gezilecektir.

> **Ders sonrası not:** Hoca adresleri "20, 24, 28, 32, 34" diye saydı ve son adımın farklı çıktığını söyledi. Adresler on altılık düzendedir: beş elemanın adresleri 0x23FE20, 0x23FE24, 0x23FE28, 0x23FE2C ve 0x23FE30'dur. 0x23FE34, son elemandan hemen sonraki adrestir ($\text{0x23FE20} + 5 \cdot 4 = \text{0x23FE34}$, python ile doğrulandı).

### 5.3 Çift işaretçi ile erişim

Hoca aynı diziye çift işaretçiyle de erişti. `p3` adında çift işaretçi oluşturup `p2`'nin adresini verdi (doğrudan diziyi değil, `p2`'yi saklayan bir yapı). `p3` bir adres gösterir, o adres de başka bir yeri gösterir. Önce `p3`'ün gösterdiği değer alınır (dizinin başlangıç adresi), sonra bu değer `i` kadar artırılır, en dışta `*` ile o adresteki değer okunur:

```c
int **p3 = &p2;
for(i=0;i<N;i++){
    printf("%d - %d \n",a[i],*(*p3+i));
}
```

<!-- BELİRSİZ: bu bölümün kodu karede görünmüyor; parça anlatımdan kuruldu ve gcc -Wall ile derlenerek 1-5 değerlerini yazdırdığı doğrulandı. -->

## 6. Dev-C++ uygulaması: malloc, calloc ve free

### 6.1 malloc ile çöp değerler

Hoca yeni bir dosyada `#include <stdlib.h>` ekleyerek başladı; malloc ve calloc kullanmak için bu başlık gerekir (ekrandan, 01:05:00). Kullanıcıdan boyut alındı ve dizi ayrıldı (ekrandan, 01:10:00):

```c
int main(){
    int N;
    printf("Boyut giriniz"); scanf("%d",&N);
    int *dizi, i;
    dizi=(int *) malloc(N*sizeof(int));
    if(dizi==NULL){
        printf("yer yok");
    }
    else{
        for(i=0;i<N;i++){
            printf("%d - %d - %d\n",i,&dizi[i],dizi[i]);
        }
    }

    printf("Yeni Boyut giriniz"); scanf("%d",&N);
    dizi=(int*)calloc(N,sizeof(int));
}
```

Hoca satırı "olayların oluş sırasına göre" tersten anlattı: malloc bir işaretçi döndürür, bu işaretçi `int *`'a cast edilir ve dizinin ilk elemanını tutmak için `dizi`'de saklanır. Karakter dizisi olsaydı `sizeof(char)` yazılacaktı. 6 elemanlı dizi istendiğinde elemanlar yazdırıldı: bir kısmı eski çöp değerlerdi, diğerleri sıfırdı. Adres burada kolaylık için `%d` ile yazdırıldı; hoca işaretçi biçiminde yazdırmak için `%p` gerektiğini söyledi.

Hoca bu sırada `scanf` konusunda da uyardı: bir sınav sorusunda beş `scanf` varsa ve bir öğrenci hiçbirinde `&` kullanmamışsa, bu öğrencinin `&` kullanılması gerektiğini bilmediği ve kodu ezberlediği anlaşılır. Biri unutulmuşsa bunu yazım hatası gibi görebileceğini söyledi.

### 6.2 calloc ve kaybolan alan

calloc'ta `N` ve `sizeof(int)` virgülle verilir. Hoca `sizeof(int)` yerine `sizeof(char)` yazılırsa neredeyse dörtte bir boyutlu bir dizi elde edileceğini söyledi; önemli olan doğru sayısal değerin yazılmasıdır ve bu `sizeof` ile ezberlemeden yapılır.

Ardından önemli bir noktaya dikkat çekti: `dizi = calloc(...)` satırıyla `dizi` yeni bir alanı gösterir. Malloc ile ayrılmış eski alan bulunduğu yerde kalır ama adresi kaybedilmiştir. calloc ile yeni boyut olarak 8 verildiğinde başka bir yerde yeni bir dizi oluştu ve bütün elemanları sıfır çıktı.

Erişim için başka bir yazım da gösterildi: `*(dizi+i)`. `dizi` başlangıç adresini tutar; buna `i` eklenerek her seferinde bir sonraki adrese gidilir ve o adresteki değer getirilir. Kodun sonraki halinde yazdırma satırı `printf("%d - %d - %d - %d\n",i,&dizi[i],dizi[i],*(dizi+i));` oldu (ekrandan, 01:50:00).

### 6.3 free'nin etkisi

Eski alanın yaşamaya devam etmemesi için calloc'tan önce `free(dizi)` yazılmalıdır. Hoca, sona tek bir `free(dizi)` konursa yalnız `dizi`'nin son gösterdiği yerin bırakılacağını, ilk alanın hâlâ yaşayacağını söyledi. `dizi` değişkeni stack bölgesinde, gösterdiği elemanlar heap bölgesindedir; stack'teki değişken heap'teki veriyi yalnızca bir işaretçiyle gösterir.

Deneme: araya `free(dizi)` konunca, önce 4 sonra 8 eleman istendiğinde 8 elemanlık dizi aynı adresten başlatılabildi. `free` kaldırılıp aynı deneme yapıldığında başka bir adres verildi, çünkü eski alan free edilmediği için hâlâ kullanılıyordu. Hoca bunu free'nin önemini gösteren güzel bir sonuç olarak yorumladı.

## 7. Dev-C++ uygulaması: dinamik karakter matrisi

### 7.1 Ayırma ve hata kontrolleri

Aradan sonra bir karakter matrisi örneği yazıldı. `M` satır, `N` sütun sayısıdır. Önce satır sayısı kadar işaretçi tutan ikinci dereceden bir işaretçi gerekir: `malloc(M * sizeof(char *))`. Sonra `for (i = 0; i < M; i++)` ile her işaretçiye `N` karakterlik bir dizi atanır; bu, önceki dizi ayırma işleminin aynısıdır.

Hoca ek kontroller ekledi: dış malloc başarısızsa "Tip -2 hata", her satır için yapılan malloc başarısızsa "Tip -1 hata" yazılıp farklı kodlarla çıkılır (ekrandan, 01:35:00):

```c
            if(ch[i]==NULL){
                printf("Tip -1 hata oluştu");
                return -1;
            }
        }
    }
    else {
        printf("Tip -2 hata oluştu");
        return -2;
    }
```

### 7.2 scanf'e adres göndermek

Tamsayı dizisinde okuma iki biçimde yapılabilir. `scanf("%d", &dizi[i]);` yazılırken `&` gerekir. **Soru (hocanın sorduğu biçimde):** "Dizi zaten bir işaretçi değil mi?" **Cevap:** Dizinin adı bir adrestir, ama `dizi[i]` indisle hesaplanmış bir elemandır, işaretçi değildir; bu yüzden `&` yazılır. Alternatif olarak `scanf("%d", dizi+i);` yazılabilir; burada `&` gerekmez, çünkü `dizi + i` zaten bir adrestir (ekrandan, 01:45:00, `scanf("%d",(dizi+i));`). Hoca burada `p++` mantığıyla yazmadığını, öyle yazsaydı diziyi başa döndüremeyeceğini hatırlattı.

> **Hocanın vurgusu:** Her zaman `&` kullanılacak diye bir şey yok. `%s` ile string okurken `&` kullanılmaz. Önemli olan `scanf`'e bir adres gitmesidir; `&dizi[i]` de, `dizi + i` de adrestir.

### 7.3 Okuma, yazdırma ve serbest bırakma

Matris elemanları `scanf("%c", &matrix[i][j])` ile okundu (ekrandan, 01:35:00). İki hata çıktı:

- Değişkenin adı `ch` olduğu halde `matrix` yazılmıştı; hoca düzeltti.
- Döngüde iki koşulda da `M` yazılmıştı. Bir öğrencinin uyarısıyla içteki döngü `j < N` yapıldı.

Çalıştırınca "Enter ch" iki kez art arda geldi. Bunun nedeni önceki Enter tuşunun karakter olarak okunmasıydı (dummy karakter). Çözüm `%c`'nin önüne bir boşluk koymaktır: `" %c"`. Hoca bu iş için bir "flush" fonksiyonu da olduğunu, ama derste pek anlatmadıklarını söyledi.

Yazdırma ayrı bir döngüde yapıldı ve her satırdan sonra alt satıra geçildi. Ardından işaretçi aritmetiğiyle alternatif yazım gösterildi: `ch` çift işaretçidir; `ch + i` ile satır işaretçileri arasında gezinilir, `*(ch + i)` satırın başlangıç adresini verir, buna `j` eklenir ve dıştaki `*` ile değer alınır. Okumada `*(ch+i)+j` adresi doğrudan `scanf`'e verilir. Son hali (ekrandan, 01:40:00):

```c
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            //printf("%c ",ch[i][j]);
            printf("%c ",*(*(ch+i)+j));
        }
        printf("\n");
    }

    for(i=0;i<M;i++){
        free(ch[i]);
    }
    free(ch);
```

2×2 matrise A, B, C, D girildi ve matris biçiminde yazdırıldı. Serbest bırakma yine tersten yapıldı: önce her satır, sonra `ch`.

<!-- BELİRSİZ: okuma satırının işaretçili son hali karede görünmüyor; anlatıma göre scanf(" %c", *(ch+i)+j) biçimindedir. Tam program gcc -Wall ile derlenip 2x2 girdiyle denendi. -->

### 7.4 Öğrenci sorusu: üç boyutlu dizi

**Soru:** Bir öğrenci önceki derste sorulan üç boyutlu diziye işaretçiyle erişim alıştırmasını yapmaya çalıştığını, ama başaramadığını söyledi. **Cevap:** Hoca, öğrencinin yazdığının doğru göründüğünü, sorunun büyük olasılıkla parantezlerde olduğunu söyledi. Örnek olarak "küpün ikinci diliminin dördüncü satırının beşinci hücresi" gibi bir erişimi verdi ve konuya üç boyutlu bir dizi oluştururken döneceğini söyledi. Bu derste bu soruya dönülmedi (bkz. Örnek Sorular).

## 8. Dev-C++ uygulaması: realloc ve geçici işaretçi

### 8.1 realloc'un iki durumu

Hoca dizinin boyutunu kullanıcıdan alıp realloc ile genişletmek istedi. realloc'a önce dizinin adresi (işaretçide saklanan), sonra yeni boyut verilir; boyut `N * sizeof(int)` biçiminde yazılır ve dönüş yine `int *`'a cast edilir.

Hoca OneNote'ta belleği bir şerit olarak çizip iki durumu anlattı:

- **Birinci durum:** Bloğun devamında istenen yeni yer kadar boşluk vardır. Blok taşınmadan büyütülür.
- **İkinci durum:** Devamında yeterli yer yoktur. Blok başka bir aralığa taşınır, eski verilerin hepsi oraya kopyalanır, eski yer free edilir ve işaretçi artık yeni yeri gösterir.

Her iki durumda da bellekte o kadar yer yoksa `NULL` dönebilir. `dizi = realloc(dizi, ...)` yazılmışsa `NULL` doğrudan `dizi`'ye atanır ve eski dizi kaybedilir.

### 8.2 Geçici işaretçiyle güvenli kullanım

Çözüm geçici bir işaretçidir:

```c
tmp = (int *) realloc(dizi, N * sizeof(int));
if (tmp != NULL) {
    dizi = tmp;
}
else {
    printf("dizi genisletme hatasi");
    return -3;
}
```

<!-- BELİRSİZ: bu parça karelerde yalnız kısmen görünüyor (ekrandan, 01:45:00: tmp=( ... if(tm... else{ ... ); kalan kısmı anlatımdan kuruldu. -->

`tmp` ve `dizi` aynı yeri gösterebilir; birinci durumda blok yerinde büyüdüğü için adres değişmez. Bu yüzden `dizi = tmp` yapıldıktan sonra `dizi` free edilmez: free edilirse `tmp`'nin gösterdiği alan da boşaltılmış olur. Hoca `dizi = tmp` atamasının derin kopya değil sığ kopya (shallow copy) olduğunu, artık `tmp` yerine doğrudan `dizi`'nin kullanılabileceğini söyledi.

### 8.3 Deneme

Önce 3 elemanlı dizi oluşturuldu ve 2, 3, 4 girildi. Yeni boyut olarak çok büyük bir sayı girilince program bir istisna (exception) verdi; hoca bunun `if` kontrolünün neden gerekli olduğunu gösterdiğini söyledi. Sonraki denemelerde girilen sayıların `int` sınırını aşmış olabileceğini fark etti ve `INT_MAX` kullanmak için `#include <limits.h>` ekledi. `calloc(INT_MAX*3, sizeof(int))` satırında derleyici tamsayı taşması (integer overflow) uyarısı verdi (ekrandan, 01:50:00). Bazı denemelerde çok büyük istekler bile karşılandı; hoca bunu bilgisayarındaki boş bellekle açıkladı. Ayrıca bir kontrolü yanlış yere yazdığını fark edip düzeltti.

> **Ek bilgi (derste anlatılmadı):** `INT_MAX*3` ifadesi `int` türünde hesaplanır ve taşar. Taşma C'de tanımsız davranıştır; yaygın sistemlerde sonuç 2147483645 gibi beklenmedik bir değer olur. Bu yüzden böyle bir denemede istenen boyut amaçlanan boyut değildir.

Son denemede boyut adım adım artırılarak yer ayrılamayan bir noktaya gelindi. Program "dizi genişletme hatası" yazdı ama önceki veriler korunmuştu, çünkü dönüş değeri `tmp`'ye atanmıştı. Yer ayrılabildiği bir denemede ise yeni bloğun ilk adresinin eskisinden farklı olduğu, yani bloğun başka bir yere taşındığı görüldü (ikinci durum).

## 9. Fonksiyonlar: türler ve tasarım ilkeleri

### 9.1 Kütüphane ve kullanıcı tanımlı fonksiyonlar

C'de iki tür fonksiyon vardır: kütüphane fonksiyonları ve programcının kendi yazdığı kullanıcı tanımlı (user defined) fonksiyonlar. Yazılacak fonksiyonlar iki ölçüte göre dört türe ayrılır: parametre alıp almaması ve değer döndürüp döndürmemesi (return type). Hoca slayta "param +/−" ve "return type +/−" yazarak dört durumu gösterdi (ekrandan, 01:55:00):

- Parametre alır, değer döndürür.
- Parametre alır, değer döndürmez.
- Parametre almaz, değer döndürür.
- Parametre almaz, değer döndürmez.

Slayttaki örnekler:

```c
void hello(){
printf("hello c");
}

int get(){
return 10;  // an integer returns
}
```

Değer döndürmeyen fonksiyonun dönüş tipi `void`'dir; içine yazılan, programcının algoritmasıdır. Değer döndüren fonksiyonda `return` ile dönen değerin tipi, tanımdaki dönüş tipiyle uyumlu olmalıdır. Bir fonksiyon bir, iki, üç ya da $n$ parametre alıp değer döndürebilir; $n$ parametre alıp hiçbir şey döndürmeyebilir (örneğin bir `a` sayısını alıp yalnız ekrana yazdırmak).

### 9.2 Fonksiyon çağrısı

Çağrı, fonksiyon nasıl tanımlandıysa ona göre yapılır. `get` bir değer döndürür ve parametre almaz; döndürdüğü değer ya `=` ile bir değişkene atanır ya da `printf` içinde uyumlu bir biçim belirteciyle (`%d` gibi) kullanılır. `add` iki parametre alıp integer döndürüyorsa parametreler sırasıyla yazılır ve dönen değer bir integer değişkene alınır.

### 9.3 Düşük bağlılık, yüksek uyum

Fonksiyon tasarımında iki genel ilke vardır: düşük bağlılık (low coupling) ve yüksek uyum (high cohesion).

Düşük bağlılık için hoca şu örneği verdi: bir sıralama (sort) fonksiyonuna bir dizi geliyor, fonksiyon diziyi sıralayıp ekrana da yazdırıyor. 5 elemanlı dizide bu makuldür, ama 5 milyon elemanlı dizide sıraladıktan sonra yazdırmak çok gereksiz ve uzun bir iş olur. Bu yüzden yazdırma kısmı sıralama fonksiyonunun içine yazılmaz; ayrı bir `print` fonksiyonu yazılır ve dizi ona verilir. Sinüs fonksiyonu nasıl yalnız sinüs değeri veriyorsa, sıralama fonksiyonu da yalnız sıralama yapmalıdır. Bağlılık düşük tutulursa programda yapılan bir değişiklik diğer kısımları az etkiler, program daha modüler olur.

Yüksek uyum, bir fonksiyondaki işlerin birbiriyle ilgili olmasıdır. Aynı fonksiyonda bir dizi sıralanıp, bir string'in uzunluğu bulunup, bir faiz hesabı yapılmaz; bu birbirinden ilgisiz işler ayrı fonksiyonlara bölünür. Hoca iki ilkeyi birbirine bağladı: bağlılık düşük tutulursa uyum yüksek olur, bağlılık yükselirse uyum düşer.

## 10. Parametre aktarımı

### 10.1 C'de aktarım her zaman değerle yapılır

Slaytta şu ilke yazıyordu (ekrandan, 02:00:00): C argümanları değerle aktardığı için fonksiyon, gerçek argümanları etkilemeden biçimsel argümanlara (formal arguments) değer atayabilir. Fonksiyonun bir nesnenin değerini değiştirmesi isteniyorsa nesnenin işaretçisi gönderilmeli ve atama dereferans edilmiş işaretçi üzerinden yapılmalıdır. Slayt bunun için `scanf` fonksiyonunu ve daha önce yazılan `indexOf` fonksiyonunu hatırlatıyordu.

Hoca bunu şöyle açıkladı: `f(int a, int b)` biçiminde tanımlanmış bir fonksiyon `f(10, 20)` ya da `f(a, b)` ile çağrıldığında, gönderilenler değişken de olsa sabit de olsa parametrelere birebir kopyalanır. Buna değerle çağırma (call by value) denir.

**Soru (hocanın sorusu):** Bir dizi gönderilecekse bütün elemanların kopyalanmasına gerek var mı? **Cevap (bir öğrenci):** İlk adresi kopyalamak yeter. Hoca onayladı: bütün diziyi ya da matrisi kopyalamak kötü bir şey olurdu. Burada da bir değer kopyalanır, ama kopyalanan ilk adresin değeridir.

Fonksiyon içinde `main`'deki `a`'nın değeri bu haliyle değiştirilemez. Değiştirilecekse değer adres üzerinden gönderilir: parametre işaretçi olarak tanımlanır ve çağrıda `&a` yazılır. Yine bir değer kopyalanır ama kopyalanan değer adrestir. Hoca, C'de gerçek anlamda "call by reference" olmadığını, buradakinin "yalancı bir call by reference" olduğunu söyledi. Bir değeri değiştirmenin C'deki tek yolu değişkeni işaretçiyle göndermek ve fonksiyon içinde dereferans yapmaktır.

### 10.2 increaseRegular ve increasePointer

Slayttaki örnek (ekrandan, 02:05:00):

```c
#include <stdio.h>
void increaseRegular( int aa, int bb ) {
    aa += bb;
    printf("increaseRegular finishes with %d\n", aa);
}
void increasePointer( int *aa, int bb ) {
    *aa += bb;
    printf("increasePointer finishes with %d\n", *aa);
}
int main() {
    int a=3, b=5;
    increaseRegular( a, b );
    printf("main says the value is %d\n", a);
    increasePointer( &a, b );
    printf("main says the value is %d\n", a);
    return(0);
}
```

**Soru (hocanın sorusu):** Fonksiyonda parametre adlarını `aa`, `bb` yerine `main`'deki gibi `a`, `b` yapabilir miyiz? **Cevap (bir öğrenci):** Yazabiliriz. Hoca açıkladı: kapsamları farklıdır; biri `main`'in içindeki `a`'dır, diğeri `increaseRegular` ya da `increasePointer`'ın içindeki değişkendir.

Adım adım:

- `main`'de `a = 3`, `b = 5`.
- `increaseRegular(a, b)` çağrılınca fonksiyondaki `aa`'ya 3, `bb`'ye 5 kopyalanır. Hoca bunu "birebir kopya, deep copy" diye adlandırdı.
- `aa += bb` ile `aa` 8 olur; fonksiyon "increaseRegular finishes with 8" yazar.
- Değişiklik fonksiyonda kalır, `main`'e yansımaz: "main says the value is 3".
- `increasePointer(&a, b)` çağrılınca `a`'nın adresi ve `b`'nin değeri gönderilir. Hoca, birinin adresini diğerinin değerini göndermenin hiçbir engeli olmadığını söyledi.
- `*aa += bb`: `aa`'nın gösterdiği yerdeki değer alınır, `bb` kadar eklenir ve sonuç aynı yere yazılır. Fonksiyon "increasePointer finishes with 8" yazar.
- Değişiklik adres üzerinden yapıldığı için `main` de 8 yazar: "main says the value is 8".

Program `gcc -Wall` ile derlenip çalıştırıldı ve bu çıktıyı verdi. Hoca slayt üzerinde `bb`'nin de adresle gönderilebileceğini göstermek için `int *bb` ve `&b` çizdi; o zaman fonksiyonda `*aa += *bb` yazılır ve hocanın önerisiyle parantez içine almak karışıklığı önler.

### 10.3 swap

Aynı mantıkla iki değişkenin yerini değiştiren `swap` fonksiyonu değişkenleri işaretçiyle alır ve `swap(&x, &y)` ile çağrılır. İçeride işaretçi olmayan bir `tmp` vardır: önce `tmp`'ye `x`'in gösterdiği değer alınır, `x`'in gösterdiği yere `y`'nin gösterdiği değer yazılır, son olarak `y`'nin gösterdiği yere `tmp` yazılır.

## 11. Fonksiyon bildirimi, tanımı ve çağrısı

Fonksiyon tanımı (definition), fonksiyonun yaptığı işi ifade eder. Fonksiyon bildirimi (declaration) ise fonksiyonun kaç parametre aldığını, parametre tiplerini ve dönüş tipini `main`'den önce yazmaktır; buna fonksiyonun prototipini yazmak denir. Örneğin `void f(int, char, int *);` gibi gövdesiz bir satır bırakılır. Hoca bunun önemli olduğunu ve ileride prototiplerin bir başlık (header) dosyasına taşınacağını söyledi.

Slaytta "function allusion" diye geçen kavram, başka bir yerde tanımlanmış bir fonksiyonun bildirimidir. Örnekte bir `simple_function_1` prototipi ve `extern` ile bildirilmiş bir `factorial` fonksiyonu vardı. Bunların bazılarının aynı dosyada gerçeklenmesi gerekmez, başka bir dosyada tanımlanabilirler.

Fonksiyon çağrılırken argümanlar virgülle ayrılarak yazılır. Hoca iki terimi ayırdı:

- **Parametre:** fonksiyon tanımındaki değişkenler.
- **Argüman:** fonksiyon çağrılırken gönderilen değerler. `printf` ve `scanf`'e verilenler de argümandır; `printf` değişken sayıda argüman alacak biçimde tasarlanmıştır.

Sıralama kuralı: fonksiyon `main`'den önce kullanılacaksa ya `main`'den önce aynı dosyada tanımlanır ya da `main`'den önce prototipi yazılıp gövdesi `main`'den sonra herhangi bir yerde tanımlanır. Slaytta faktöriyel hesaplayan, bir karakterin alfabetik olup olmadığını bulan (alfabetikse 1, değilse 0 döndüren) ve iki sayıyı yer değiştirip yazdıran fonksiyon örnekleri vardı; hoca bunları öğrencilerin kendilerinin yapabileceğini söyleyerek hızlıca geçti.

## 12. Dizilerin fonksiyonlara aktarılması

### 12.1 Üç yöntem

Slaytta diziyi parametre olarak göndermenin yolları verildi (ekrandan, 02:20:00). Slayt iki noktayı unutmamayı hatırlatıyordu: sınır denetimi (boundary checking) yoktur ve fonksiyon yazmanın amacı unutulmamalıdır.

- **Gerçek dizi boyutunu kullanmak:** `void printArray( int ar[5] )`. `printArray(dizi)` ile çağrılır ve dizi 5 elemanlı kabul edilir. Farklı boyutlarda diziler yazdırılacaksa uygun değildir.
- **Dizi ve boyut parametresi:** `void printArray( int ar[], int size )`. `printArray(dizi, 8)` gibi çağrılır; öncekinden daha kullanışlıdır.
- **İşaretçi ve tamsayı:** `void myFunction( int *ar, int size )`. Gelen şey zaten bir adres olduğu için işaretçiyle alınır; bu da kullanışlıdır.

Her iki durumda da dizinin başlangıç adresi parametreye kopyalanır; derin kopya yoktur. Bu yüzden fonksiyon içinde dizi elemanlarında yapılan değişiklik asıl diziyi değiştirir.

Dizinin boyutu için bir makro da yazılabilir: dizinin adı `x` ise `sizeof(x) / sizeof(x[0])`. Hoca yine de boyutun ayrı bir parametre olarak gönderilmesinin daha iyi olduğunu söyledi.

> **Ek bilgi (derste anlatılmadı):** Bu makro yalnız dizinin tanımlandığı yerde doğru sonuç verir. Fonksiyona `int ar[]` olarak gelen parametre aslında bir işaretçidir; fonksiyon içinde `sizeof(ar)` işaretçinin boyutunu verir. Boyutun ayrı parametre olarak gönderilmesinin bir nedeni budur.

### 12.2 Dizinin tamamı ve tek eleman (Dev-C++ uygulaması)

Hoca bir `write_array` fonksiyonu ve diziyi değiştiren bir `INC_array` fonksiyonu yazdı. `write_array` önce `int d[]` ile tanımlanmıştı, sonra bir sürümü `int *d` ile yazıldı. Fonksiyonda `printf("%d -> %d\n",i,d[i]);` ile elemanlar yazdırılır (ekrandan, 02:40:00). `main` (ekrandan, 02:45:00):

```c
#include<stdio.h>
void write_array(int d[],int N);
void INC_array(int d[],int N);
int main(){
    int a[]={1,2,3,4,5};
    int N=sizeof(a)/sizeof(a[0]);
    write_array(a,N);
    write_array(&a,N);
    write_array(&a[0],N);
    INC_array(a,N);
    write_array(&a,N);
    INC_element_passbyvalue(a[3]);
    write_array(a,N);
}
void write_array(int *d,int N){
    int i;
    printf("Array Elements\n");
    ...
```

Diziyi çağırmanın üç yolu: `write_array(a, N)`, `write_array(&a, N)` ve `write_array(&a[0], N)`. Üçü de aynı elemanları yazdırdı (1, 2, 3, 4, 5).

`INC_array` her elemanı bir artırır. İçeride iki yazım gösterildi: `d[i]++` ya da `*(d+i) = *(d+i) + 1`. Hoca ikisinin aynı işi yaptığını söyledi. Değişkenler swap fonksiyonuna gönderildiğinde değişiklik geri yansımamıştı; dizi gönderildiğinde ise hangi kod çalışırsa çalışsın elemanların içeriği doğrudan değişti ve dizi 2, 3, 4, 5, 6 oldu.

Derleyici uyarıları da konuşuldu. İlk uyarılar fonksiyon prototiplerinin yazılmamasından kaynaklandı; hoca prototipin, fonksiyon başlığını kopyalayıp `main`'den önce yapıştırıp sonuna `;` koymakla yazıldığını gösterdi. Kalan uyarılar `write_array(&a, N)` satırları içindi: "passing argument 1 of 'write_array' from incompatible pointer type", not olarak da "expected 'int \*' but argument is of type 'int (\*)[5]'" (ekrandan, 02:45:00). Hoca birini işaretçi, birini dizi biçiminde bıraktığını, ikisinin de çalıştığını görmelerini istediğini söyledi.

> **Ek bilgi (derste anlatılmadı):** `&a`, dizinin ilk elemanının değil dizinin bütününün adresidir. Sayısal değeri `&a[0]` ile aynıdır, ama türü "5 elemanlı int dizisine işaretçi"dir (`int (*)[5]`). Uyarının nedeni bu tür farkıdır.

Sonra dizinin bir elemanı gönderildi. İki fonksiyon yazıldı: değerle alan `INC_element_passbyvalue(int p)` içinde `p++`, adresle alan `INC_element_passbyreference(int *p)` içinde gösterilen değer bir artırılır. `a[3]` değerle gönderilince dizi 2, 3, 4, 5, 6 olarak kaldı; `&a[3]` gönderilince 2, 3, 4, 6, 6 oldu.

> **Hocanın vurgusu:** Çok çok önemli: dizi aktarılırken dizinin tamamı değiştirilebilir. Tek bir eleman gönderilirken normal bir değişken göndermekten hiçbir farkı yoktur; değiştirmek istiyorsanız adresini göndermeniz gerekir.

Tam program (iki eleman fonksiyonu dahil) `gcc -Wall` ile derlendi ve aynı çıktıları verdi.

## 13. Fonksiyondan dizi döndürme

### 13.1 C'de dizi döndürülmez

**Soru (hocanın sorusu):** Bir fonksiyondan dizi döndürmek mümkün müdür? Hoca Java ya da C# bilenlerin `int[] a = new int[5]; ... return a;` gibi bir yazımı bileceğini, ama C'de böyle bir şey olmadığını söyledi: C'de dönüş tipinde köşeli parantez kullanılmaz. Slayt (ekrandan, 02:25:00):

- Fonksiyonlardan dizi döndürmeyiz; döndürülecek dizinin başlangıç adresini tutan bir işaretçi döndürürüz.
- Fonksiyon bittikten sonra dizinin var olduğundan emin olmalıyız; yerel diziler döndürülemez.
- Çözüm: dinamik bellek ayırma.

### 13.2 Sık yapılan hata

Hoca öğrencilerin sık yaptığı hatayı tahtaya yazdı: `int *f(int n) { int d[n]; ... return &d; }` gibi bir fonksiyon. Fonksiyonda bir dizi tanımlanır, üzerinde işlemler yapılır, sonra dizinin adresi ya da sıfırıncı elemanının adresi döndürülür. Bir işaretçi döner, ama fonksiyon bittikten sonra bu dizi yaşamaz, çünkü belleğin stack bölgesindedir; hoca bunu "volatile bir durum" diye niteledi. Çağıran yerden bu diziye erişmek çoğu zaman mümkün olmaz.

Doğrusu: `int *f(int n)` içinde `int *p;` tanımlanır, `p = malloc(n * sizeof(int))` gibi bir çağrıyla heap'te yer açılır ve `return p;` yazılır. Dönen işaretçi heap'teki alanı gösterdiği için program kapanana kadar (ya da free edilene kadar) o alana ulaşılabilir. Hoca, dizi döndürmek için başka dillerdeki gibi bir mekanizma beklemenin evde domatesi baltayla kesmeye benzediğini söyledi: gerek yoktur, domates bıçakla kesilir.

### 13.3 İki diziyi birleştirme (concat)

Slayttaki örnekte bir fonksiyon iki diziyi ve boyutlarını alır, `merged` adında yeni bir işaretçi için `size1 + size2` kadar yer açar. Bu alan program kapanana kadar yaşar. Fonksiyon bir `for` döngüsüyle birinci diziyi olduğu gibi kopyalar, ikinci diziyi kaldığı yerden kopyalamaya devam eder ve en sonunda `merged` işaretçisini döndürür. `main`'de `concat_arrays_v1` çağrılır, dönen `int *` istenildiği gibi kullanılır ve program kapanmadan `free` edilebilir. Hoca, bir fonksiyon içinde oluşturulmuş bir dizinin başka bir fonksiyonda işletim sistemine iade edilebileceğini, çünkü iade edilmesi gerekenin yalnız işaretçinin gösterdiği alan olduğunu vurguladı.

Örnekte bir `print_array` fonksiyonu ve dizinin boyutunu veren bir makro da vardı. `concat_arrays_v1`'e `arr1`, makroyla hesaplanan boyutu, `arr2` ve onun boyutu gönderilir. Hoca dizilerin birebir kopyalanmadığını, yalnız başlangıç adreslerinin ve boyutlarının gittiğini tekrarladı. Program önce `arr1`'i ve boyutunu, sonra `arr2`'yi, en son birleştirilmiş `arr3`'ü yazdırır. Hoca slayttaki vurgulu yerlerde parantezlere dikkat çekti: fonksiyonun nasıl tanımlandığı ve nasıl çağrıldığı çok önemlidir.

<!-- BELİRSİZ: concat örneğinin kodu karelerde görünmüyor; fonksiyon ve değişken adları altyazıdan alındı. -->

### 13.4 Alternatif: çağıran taraf boş dizi verir

Slayt (ekrandan, 02:30:00): fonksiyonun bellek ayırıp sonuca işaretçi döndürmesi yerine, fonksiyonu çağıran taraf boş bir dizi tanımlayıp doldurulması için fonksiyona verebilir. Örnekte `size3 = size1 + size2` boyutunda boş bir `arr3` tanımlanır ve fonksiyona gönderilir; fonksiyon gösterilen yere `size1 + size2` kadar değer kopyalar. Bu sürümde makro kaldırılıp yerine basit bir kod yazılmıştı. Hoca bunun iyi bir çözüm olmadığını ama bir alternatif olduğunu söyledi; tek sıkıntısı dinamik olmaması, dizinin boyutunun sabit kalmasıdır.

### 13.5 Matrisi fonksiyona gönderme ve döndürme

Matris fonksiyona birkaç biçimde gönderilebilir: sütun sayısı yazılarak (`int matrix[][N]` gibi), boyut ayrıca parametre olarak verilerek ya da işaretçiyle (`int **`). Seyrek matris örneğinde fonksiyon içinde malloc ile bir matris oluşturulur ve çift işaretçi olarak döndürülür, çünkü sıfırdan farklı eleman sayısı önceden bilinmez (Bölüm 14.4).

> **Ek bilgi (derste anlatılmadı):** `int matrix[][N]` biçimi statik iki boyutlu dizi içindir. Satır işaretçileriyle ayrılmış dinamik bir matris `int **` parametresiyle gönderilir; iki biçim birbirinin yerine kullanılamaz.

## 14. Uygulama örnekleri

### 14.1 Değerle ve adresle swap

Hoca derse ait hazır bir örneği kopyaladı. `x` ve `y` önce yazdırılır ("before"). `swap_pass_by_value(x, y)` çağrılınca değerler kopyalanır; değişiklik fonksiyonda kalır ve "after pass by value" satırında aynı değerler görülür. Adresle swap'ta adresler kopyalanır ve değişiklik o adreslerde yapılır. Fonksiyon ayrıca iki değerin toplamını döndürecek biçimde yazılmıştı; hoca bunun anlamsız ama yapılabilir bir tasarım olduğunu, yalnız göstermek için yapıldığını söyledi. Çalıştırınca önce 5 ve 8, değerle swap'tan sonra yine 5 ve 8, adresle swap'tan sonra 8 ve 5 görüldü; toplam 13 olarak yazdırıldı.

<!-- BELİRSİZ: swap örneğinin kodu karede görünmüyor; çıktı değerleri altyazıdan alındı. -->

### 14.2 Geçerli ve geçersiz yazımlar

Hoca bir başka hazır örneği derledi. Dizinin boyutu girilir, yer ayrılır, yer yoksa "yer yok" yazılır; varsa elemanlar okunur. Kodda bazı satırlar bilerek yanlış yazılmıştı:

- `scanf("%d", &dizi[i])` ve `scanf("%d", dizi+i)` geçerlidir.
- `scanf("%d", dizi[i])` geçersizdir: elemanın sayısal değeri adres gibi kullanılmaya çalışılır ve çalışma zamanında hata alınır.
- `&(dizi+i)` geçersizdir: dizinin adresine `i` eklenip o adresin adresi istenir. Hoca "adresin adresi" diye bir şey olmadığını, adresin adresinin ancak bir işaretçi değişkenine atandıktan sonra alınabileceğini söyledi. Derleyici bu satır için "lvalue required as unary '&' operand" hatası verdi (ekrandan, 02:50:00).
- Sıralama fonksiyonu `mysort(dizi, ...)` ya da `mysort(&dizi[0], ...)` ile çağrılabilir, ama ilk elemanın değeriyle (`dizi[0]`) çağrılamaz. Örneğin ilk eleman 5 ise 5 diye bir adres olmadığı için bu geçersizdir.
- `printf` ile `&dizi[i]` ve `dizi+i` adres yazar, `dizi[i]` ve `*(dizi+i)` değer yazar; `&(dizi+i)` yine geçersizdir.

Hoca `mysort` fonksiyonunun içini boş bıraktı ve öğrencilerin doldurmasını istedi; kodu çalıştırmak için geçersiz satırların kapatılması gerektiğini söyledi.

### 14.3 Fibonacci dizisi

`#define MAX 10` ile tanımlı bir dizi boş olarak `fib`'e gönderilir, sonra yazdırılır; aynı dizi `fib2`'ye gönderilir ve dönen işaretçiyle yazdırılır (ekrandan, 02:50:00):

```c
#include <stdio.h>
#define MAX 10
int *fib2(int dizi[MAX]);
int main(){
    int dizi[MAX];
    int *p;
    fib(dizi);
    write(dizi);
    p=fib2(dizi);
    write2(p);
}

void write2(int *dizi){
    int i=0;
    for(i=0;i<MAX;i++){
        printf("%3d---",dizi[i]);
        printf("%3d\n",*(dizi+i));
    ...
```

`write` diziyi `MAX` ile alır; `MAX` `#define` ile tanımlandığı için bu mümkündür ve sıfırıncı elemandan `MAX`'a kadar bütün elemanlar yazılır. `fib` dizinin 0. ve 1. elemanına 1 atar, sonra 2. elemandan `MAX`'a kadar her elemanı önceki iki elemanın toplamı olarak hesaplar. `fib2` aynı işi yapar; farkı dizinin 0. elemanının adresini döndürmesidir. Adres döndürüldüğü için dönüş tipi `int *`'dır, `main`'de bir işaretçiyle alınır ve `write2`'ye verilir. `write2` bu işaretçi yoluyla bütün elemanları `MAX`'a kadar yazdırır. `MAX` `#define` ile tanımlı olmasaydı boyut ikinci bir parametreyle gönderilebilirdi. Çıktı 1, 1, 2, 3, 5, ... biçimindeydi.

Uyarıların nedeni yine prototiplerin yazılmamasıydı; hoca prototipleri ekledikçe uyarı sayısının azaldığını gösterdi. `fib`, `write` ve `write2` gövdeleri karede görünmediği için tam program anlatıma göre tamamlanıp `gcc -Wall` ile derlendi; ilk 10 eleman 1, 1, 2, 3, 5, 8, 13, 21, 34, 55 çıktı.

### 14.4 Dizinin en küçük elemanı: üç dönüş tipi

Diziyi alan ve en küçük elemanı bulan üç fonksiyon yazılmıştı (ekrandan, 02:55:00):

```c
int *find_min_v2(int *dizi, int N){
    int i;
    int *min=&dizi[0];
    for(i=1;i<N;i++){
        if(dizi[i]<*min){
            min=&dizi[i];
        }
    }
    return min;
}

int find_min_v3(int *dizi, int N){
    int i,min=dizi[0];
    for(i=1;i<N;i++){
        if(dizi[i]<min){
            min=dizi[i];
    ...
```

- **v1:** Dizinin başlangıç adresi ve boyutu gönderilir. Minimum önce sıfırıncı eleman kabul edilir, birinci elemandan son elemana kadar karşılaştırılır ve minimum elemanın indisi döndürülür. `main`'de bu indisle elemanın adresi ve değeri yazdırılır.
- **v2:** Dizinin 0. elemanının adresi `min` işaretçisine atanır; karşılaştırma işaretçi üzerinden yapılır ve minimum elemanın gerçek bellek adresi döndürülür (indis değil).
- **v3:** Dizinin 0. elemanı bir değişkene kopyalanır, en küçük elemanın değeri bulunur ve değer döndürülür.

Hoca farkı şöyle özetledi: birinde indis gelir ve indis üzerinden erişilir, birinde adres gelir, birinde doğrudan değer gelir. Derste 7 elemanlı dizi için 4, 6, 8, 2, 6, 8, 9 girildi.

<!-- BELİRSİZ: find_min_v1 ve main kodu karede görünmüyor. Anlatıma göre tamamlanan program gcc -Wall ile derlendi; aynı girdiyle üç sürüm de 2 değerine (indis 3) ulaştı. -->

### 14.5 Seyrek matrisin sıkıştırılması

Hoca bu örneği slayttaki "bir matrisi sıkıştırıp seyrek (sparse) matris haline getiren fonksiyon" alıştırmasının çözümü olarak gösterdi. Önce arka planı anlattı: graf teorisinde A, B, C şehirleri arasında bir kenar varsa bu bir komşuluk matrisiyle gösterilir. A ile A arasında bir şey yoksa 0, A ile B arasında kenar varsa 1 yazılır. Bu matris üzerinden çeşitli analizler yapılır. Matrisin boyutu düğüm sayısının karesiyle artar: 5 düğümde 25, 6 düğümde 36 hücre olur. Bu yüzden çok yer kaplar. Alternatif olarak yalnız var olan kenarlar yazılır: "3. ile 4. arasında bir kenar var" gibi. Bazen yalnız varlık değil, maliyet de yazılır (4 birim, 3 birim gibi). Değer 0 ise hiçbir şey yazılmaz, 0'dan farklıysa yeri ve değeri yazılarak matris sıkıştırılır. Sıfırdan farklı eleman sayısı önceden bilinmediği için durum dinamiktir.

`main` (ekrandan, 03:00:00):

```c
    int **matrix, **c_matrix;
    int i,j,counter=0;

    printf("M  - N "); scanf("%d %d",&M, &N);
    matrix=(int**) malloc(M*sizeof(int*));
    for(i=0;i<M;i++){
        matrix[i]=(int*)malloc(N*sizeof(int));
    }

    enter_data(matrix,M,N);
    counter=count_data(matrix,M,N);
    display_matrix("Original Matrix Printing\n",matrix,M,N);
    c_matrix=matrix_compress(matrix,M,N,counter);
    display_matrix("Compressed Matrix Printing\n",c_matrix,counter,3);

    free_matris(matrix,M);
    free_matris(c_matrix,counter);
```

Fonksiyonlar:

- **`enter_data`:** Matris `int **` olarak alınır; elemanlar `printf` ve `scanf` ile klavyeden okunur. İşaretçi olsa da indis operatörü doğrudan kullanılabildiği için normal bir matrise okumaktan farkı yoktur.
- **`count_data`:** Matristeki sıfırdan farklı elemanları bir `counter` değişkeniyle sayar ve döndürür.
- **`display_matrix`:** Bir başlık metni, bir matris ve boyutları alır; metni ve matrisi yazdırır. Hoca bu fonksiyonu hem orijinal hem sıkıştırılmış matris için kullanılan ortak (genel) bir fonksiyon olarak yazdığını söyledi.
- **`matrix_compress`:** Matris, `M`, `N` ve `counter` alınır. Fonksiyon içinde `counter × 3` boyutlu yeni bir matris oluşturulur. Orijinal matris gezilir; sıfırdan farklı bir değer görülünce satır indisi `i`, sütun indisi `j` ve değer yeni matrise yazılır, `k` değişkeni yeni matrisin bir sonraki satırına geçer. Yeni matris çift işaretçi olarak döndürülür. `i` ve `j` şehirleri gösteren indisler olarak kullanılabilir (A yerine 0 gibi).
- **`free_matris`:** Her satırı ayrı ayrı free eder, sonra matrisi free eder. Orijinal matris `M`, sıkıştırılmış matris `counter` satırla bırakılır.

Derste 2×3 matrise 3, 0, 1 / 6, 0, 0 girildi. Sıkıştırılmış matris (0, 0, 3), (0, 2, 1) ve (1, 0, 6) satırlarından oluştu: 0. satır 0. sütunda 3, 0. satır 2. sütunda 1, 1. satır 0. sütunda 6 vardır. Hoca 50 × 50'lik ve çok sayıda sıfır içeren bir matriste bu yöntemle çok daha az veri saklanacağını söyledi.

<!-- BELİRSİZ: yardımcı fonksiyonların gövdeleri karede görünmüyor. Anlatıma göre tamamlanan program gcc -Wall ile derlendi ve aynı girdiyle aynı sıkıştırılmış matrisi verdi. -->

## Örnek Sorular

**Soru 1** (derste sözlü, 00:56:48): Bir dizinin elemanlarını `printf("%d", *p); p++;` biçiminde yazdırmanın sakıncası nedir?

> **Çözüm (derste verildi):** Döngü sonunda `p` dizinin son elemanından sonraki adresi gösterir ve dizinin başlangıç adresi kaybolur. Başa dönmek için başlangıç adresi ayrı bir işaretçide (örneğin `p2`) saklanmalıdır.

**Soru 2** (derste sözlü, 00:42:02): Matris ayırma mantığıyla 3 boyutlu dinamik bir dizi oluşturun (3. dereceden işaretçi gerekir).

> **Çözüm (derste verilmedi):** Ajan tarafından yazıldı ve `gcc -Wall` ile derlenip `2 2 3` girdisiyle denendi.

```c
#include<stdio.h>
#include<stdlib.h>
int main(){
    int K,M,N,i,j,k;
    int ***kup;
    printf("Dilim, satir, sutun: "); scanf("%d %d %d",&K,&M,&N);
    kup=(int***)malloc(K*sizeof(int**));
    if(kup==NULL) return -1;
    for(i=0;i<K;i++){
        kup[i]=(int**)malloc(M*sizeof(int*));
        if(kup[i]==NULL) return -2;
        for(j=0;j<M;j++){
            kup[i][j]=(int*)malloc(N*sizeof(int));
            if(kup[i][j]==NULL) return -3;
        }
    }
    for(i=0;i<K;i++)
        for(j=0;j<M;j++)
            for(k=0;k<N;k++)
                *(*(*(kup+i)+j)+k)=100*i+10*j+k;
    for(i=0;i<K;i++){
        printf("Dilim %d\n",i);
        for(j=0;j<M;j++){
            for(k=0;k<N;k++) printf("%4d",kup[i][j][k]);
            printf("\n");
        }
    }
    for(i=0;i<K;i++){
        for(j=0;j<M;j++) free(kup[i][j]);
        free(kup[i]);
    }
    free(kup);
    return 0;
}
```

> Erişim `kup[i][j][k]` ya da `*(*(*(kup+i)+j)+k)` ile yapılır; serbest bırakma yine ayırmanın tersidir.

**Soru 3** (ekrandan, 02:05:00): "Please run the code and check the output." `increaseRegular` ve `increasePointer` örneğinin (Bölüm 10.2) çıktısı nedir?

> **Çözüm:** `increaseRegular finishes with 8`, `main says the value is 3`, `increasePointer finishes with 8`, `main says the value is 8`. Derste değerler slayt üzerinde anlatıldı; çıktı `gcc -Wall` ile derlenip doğrulandı.

**Soru 4** (derste sözlü, 02:00:17): Bir dizi fonksiyona gönderilirken bütün elemanların kopyalanması gerekir mi?

> **Çözüm (derste verildi):** Hayır. Yalnız ilk elemanın adresi (değerle) kopyalanır; bu yüzden fonksiyon içindeki değişiklik asıl diziyi etkiler.

**Soru 5** (derste sözlü, 02:02:24): `increaseRegular(int aa, int bb)` fonksiyonunda parametre adları `main`'deki değişkenlerle aynı (`a`, `b`) olabilir mi?

> **Çözüm (derste verildi):** Olabilir. Kapsamları farklıdır; fonksiyondaki `a`, `main`'deki `a`'dan bağımsız bir değişkendir.

**Soru 6** (derste sözlü, 02:32:08): İki sıralı diziyi alıp sıralı birleşimini döndüren bir fonksiyon yazın; birleştirme (merging) algoritmasını kullanın.

> **Çözüm (derste verilmedi):** Ajan tarafından yazıldı, `gcc -Wall` ile derlendi; `{1,4,7,9}` ve `{2,3,8}` için çıktı `1 2 3 4 7 8 9`.

```c
#include<stdio.h>
#include<stdlib.h>
int *merge_sorted(int *a,int n1,int *b,int n2){
    int i=0,j=0,k=0;
    int *c=(int*)malloc((n1+n2)*sizeof(int));
    if(c==NULL) return NULL;
    while(i<n1 && j<n2){
        if(a[i]<=b[j]) c[k++]=a[i++];
        else c[k++]=b[j++];
    }
    while(i<n1) c[k++]=a[i++];
    while(j<n2) c[k++]=b[j++];
    return c;
}
int main(){
    int a[]={1,4,7,9}, b[]={2,3,8};
    int n1=sizeof(a)/sizeof(a[0]), n2=sizeof(b)/sizeof(b[0]), i;
    int *c=merge_sorted(a,n1,b,n2);
    if(c==NULL){ printf("yer yok\n"); return -1; }
    for(i=0;i<n1+n2;i++) printf("%d ",c[i]);
    printf("\n");
    free(c);
    return 0;
}
```

**Soru 7** (derste sözlü, 02:47:14): Aşağıdakilerden hangileri geçerlidir? `scanf("%d", &dizi[i])`, `scanf("%d", dizi+i)`, `scanf("%d", dizi[i])`, `scanf("%d", &(dizi+i))`, `mysort(dizi[0], ...)`.

> **Çözüm (derste verildi):** İlk ikisi geçerlidir. `dizi[i]` elemanın değerini adres sanır (çalışma zamanı hatası); `&(dizi+i)` adresin adresini ister ve derlenmez ("lvalue required as unary '&' operand"); `mysort(dizi[0], ...)` ilk elemanın değerini adres olarak gönderir.

**Soru 8** (derste sözlü, 02:32:50): Bir matrisi sıkıştırıp seyrek matris biçimine getiren ve sonucu döndüren bir fonksiyon yazın.

> **Çözüm (derste verildi):** Bölüm 14.5'teki `matrix_compress` çözümü: sıfırdan farklı eleman sayısı `counter` kadar satırlı, 3 sütunlu bir matris fonksiyon içinde malloc ile ayrılır, her satıra (satır, sütun, değer) yazılır ve çift işaretçi döndürülür.

## Dersin Toparlaması

Bu derste dinamik bellek yönetiminin dört temel fonksiyonu (malloc, calloc, realloc, free) ile tek boyutlu dizi ve matrisin çalışma zamanında nasıl ayrılıp serbest bırakıldığı görüldü. Matris için satır işaretçilerini tutan bir `int **` dizisi ve her satıra ayrı bir dizi ayrılır; serbest bırakma tersten yapılır. Her ayırmadan sonra `NULL` kontrolü yapılır. realloc sonucu önce geçici bir işaretçiye alınır. Free edilmeyen alan bellek sızıntısına yol açar. Dev-C++ uygulamalarında işaretçi aritmetiğiyle dizi gezme, çift işaretçiyle erişim, dinamik karakter matrisi ve realloc'un başarısız olduğu durumda verinin korunması denendi.

İkinci bölümde fonksiyonlar ele alındı: dört fonksiyon türü, düşük bağlılık ve yüksek uyum ilkeleri, prototip ile tanım farkı, parametre ve argüman ayrımı. C'de aktarım her zaman değerle yapılır; bir değişkeni değiştirmek için adresi gönderilir. Diziler fonksiyona başlangıç adresiyle gider, bu yüzden elemanlar değiştirilebilir; tek eleman ise sıradan bir değişken gibi kopyalanır. Fonksiyondan dizi değil işaretçi döndürülür ve döndürülen alan malloc ile heap'te ayrılmış olmalıdır. Seyrek matris örneği bu konuların hepsini birleştirdi. Hoca sonraki derslerde `main` argümanlarına ve struct'lara geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
