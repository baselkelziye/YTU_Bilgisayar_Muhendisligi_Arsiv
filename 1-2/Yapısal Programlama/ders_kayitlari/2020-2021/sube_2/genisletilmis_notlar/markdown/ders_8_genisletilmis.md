# Ders 8 Genişletilmiş Notu: Diziler, İşaretçi Aritmetiği, Stringler ve İşaretçinin İşaretçisi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. İşaretçiler hakkında kısa tekrar
- 2. Veri organizasyonu ve neden dizi?
- 3. Dizi tanımı ve indis sınırları
- 4. Dizinin bellekteki yerleşimi
- 5. Dizilere ilk değer verme
- 6. Dizi elemanlarına indis ve işaretçiyle erişim
- 7. Sıralama örnekleri ve swap işlemi
- 8. Dev-C++ uygulaması: diziler ve işaretçiler birlikte
- 9. Dersin genel çerçevesi: işaretçi, dizi, struct ve fonksiyon
- 10. Stringler: null karakterle biten karakter dizileri
- 11. Hata ayıklama (debug) ve sabit stringler
- 12. String atamaları, karakterler ve stringler
- 13. String okuma, yazma ve string fonksiyonları
- 14. Örüntü eşleme (pattern matching)
- 15. Çok boyutlu diziler
- 16. İşaretçi dizileri ve işaretçinin işaretçisi
- 17. Dinamik bellek yönetimine giriş: stack ve heap
- Örnek Sorular

## 1. İşaretçiler hakkında kısa tekrar

Hoca derse, önceki hafta başlanan işaretçi (pointer) konusunu bu hafta çok boyutlu dizilerin sonuna kadar bitireceklerini, ardından dinamik bellek ayırma (dynamic memory allocation) konusuna geçeceklerini söyleyerek başladı. Önce işaretçilerin en önemli noktasını hızlıca tekrar etti.

İşaretçi, herhangi bir tipin yanında yeni bir veri tipi gibi düşünülmelidir. `int a` ile `int *pa` birbirinden farklı veri tipleridir; bu yüzden eşittir operatörüyle doğrudan birbirine atanamazlar. Ancak `a`'nın adresi `pa`'ya atanabilir (`pa = &a`), ya da `pa` dereferans edilerek gösterdiği değer `a`'ya atanabilir (`a = *pa`). Operatör önceliği açısından da önce `&` (adres) ya da `*` (dereferans) operatörü çalışır, sonra eşittir operatörü çalışır. Önceki derste adreslerin örneklerde varsayım olarak verildiği de hatırlatıldı.

## 2. Veri organizasyonu ve neden dizi?

Diziler "Yapısal Programlamaya Giriş" dersinde anlatılmıştı; hoca bu kez dizinin neden var olduğuna farklı bir açıdan baktı. Gerçek dünyadaki bir problemi çözerken elimizde kod ve veri bulunur; kod veriyi işler, veri de kodun üzerinde çalışır, yani ikisi arasında çift yönlü bir ilişki vardır (ekrandan, 00:15:00). Problem çözümünde algoritma tasarımı (design and algorithm) ayrı bir aşamadır. Algoritma tasarlandıktan sonra verinin organize edilmesi (data organization) gerekir: problemdeki verilerin bellekte nasıl saklanmasının iyi olacağına karar verilir.

Örneğin elimizde 100 öğrencinin notu olsun. Bunları 100 ayrı değişkende saklamak mümkündür, ama programlama açısından mantıklı değildir. Bunun yerine `grade[100]` gibi 100 elemanlı bir dizi tanımlanır (ekrandan, 00:15:00). Bu tek tanım bellekte 100 elemana yer ayırır, bu yerlere veri saklamayı (store) ve erişmeyi (access) sağlar. Erişim sıralı (sequential) olabilir: 0. elemandan 99. elemana kadar tek tek gidilir. Rastgele (random) de olabilir: doğrudan 40. elemana gidilebilir.

Elimizde 100 öğrencinin vize ve final notları varsa 100 elemanlı bir vize dizisi ve 100 elemanlı bir final dizisi tanımlanabilir; ama bu iki dizi tek bir değişkende, bir matriste birleştirilebilir. Verinin organizasyonu kapsamındaki bu en genel kavrama veri yapısı (data structure) denir ve probleme başlamadan önce belirlenmesi gerekir.

İleri seviyede diziler ve matrisler liste veri yapısı olarak anlatılacak; ayrık matematik ve veri yapıları derslerinde graflar ve ağaçlar görülecek. Hoca, ağaçların ve grafların da aslında listelerden, yani dizi mantığından türediğini vurguladı. Bunun nedeni belleğin kendisidir: RAM'de veriler 0. adresten örneğin 4 GB'lık adrese kadar tek tek saklanır; bu düzene bakıldığında görülen şey tek boyutlu bir dizidir (1D array). Diğer veri yapıları da bu mantığa göre organize edilir. Örneğin yığın (stack) veri yapısı da bir dizidir, ama her türlü erişime izin vermez: eleman yalnız üstten eklenir ve üstten çıkarılır. Verinin doğru organize edilmesi erişimi hızlandırır, dolayısıyla programı da hızlandırır; bu konu daha ayrıntılı olarak veri yapıları dersinde işlenir.

## 3. Dizi tanımı ve indis sınırları

### 3.1 Söz dizimi

Dizi tanımının söz dizimi slaytta bir akış şemasıyla gösterildi: tip belirteci (type specifier), dizi adı, `[`, dizi boyutu, `]` ve isteğe bağlı bir başlatıcı (initializer) (ekrandan, 00:20:00). Tip belirteci `int` ya da `char` olabileceği gibi kullanıcının tanımladığı bir tip de olabilir. Hoca ileride struct konusunda `struct ogrenci` türünden bir tip tanımlayıp `struct ogrenci ogrenciler[N]` gibi bir dizi kuracaklarını söyledi: tek bir öğrenci yapısı vardır, n tane öğrenciyi saklamak için o tipten bir dizi kullanılır.

Boyut kısmı önemlidir. C'de dizi tanımlanırken köşeli parantezin içine sabit bir değer (literal), örneğin 365 yazılır. Buraya doğrudan bir `N` değişkeni yazılmaz. `N` ancak `#define N 365` gibi bir önişlemci sabiti olarak tanımlanırsa kullanılabilir: önişlemci derlemeden önce `N` gördüğü her yere değeri yapıştırır, dolayısıyla derleyici yine bir sabit görür. Dizide ilk değer verilmek isteniyorsa küme parantezi açılıp değerler içine yazılır.

### 3.2 İndisler 0'dan başlar

Slayttaki örnek şuydu (ekrandan, 00:20:00):

```c
int dailyTemp[365];
dailyTemp[0] = 38;
dailyTemp[0] = 23;
```

Slaytın altında kırmızıyla "subscripts begin at 0, not 1 !" yazıyordu. Hoca bazı öğrencilerde gördüğü bir alışkanlığı eleştirdi: 365 elemanlı bir dizi gerekince boyutu 366 yapıp 1'den başlamak ve 0. elemanı hiç kullanmamak. Hoca bunun yanlış olduğunu söyledi: diziler 0. elemandan başlar, elemanlar oraya yerleştirilmeye başlanır ve 364. elemana kadar gider. 365 en büyük boyuttur; 365. indisli bir eleman yoktur.

> **Hocanın vurgusu:** Sıfırıncı eleman kullanılacak. Diziler sıfırıncı elemandan başlar; 365 elemanlı dizide 365. eleman diye bir şey olmaz.

### 3.3 Sınır dışı erişim

365. elemana örneğin `printf("%d", dailyTemp[365])` ile erişilmeye çalışılırsa bazı durumlarda hata alınır, bazı durumlarda alınmaz. Erişilen yer işletim sisteminin programınızın sürecine (process) ayırdığı alan içindeyse sorun çıkmadan anlamsız bir değer okunur. Başka bir sürecin adres alanındaysa hata alınır. C'de dizi sınırlarının denetimi programcıya bırakılmıştır. Java'da aynı erişim denendiğinde `ArrayIndexOutOfBoundsException` hatası alınır; C'de bu sorumluluk programcıdadır.

## 4. Dizinin bellekteki yerleşimi

Hoca dizinin bellekte nasıl organize edildiğini slayttaki şu örnekle anlattı (ekrandan, 00:25:00):

```c
int ar[5]; /* declaration */
ar[0] = 15;
ar[1] = 17;
ar[3] = ar[0] + ar[1];
```

Burada yalnızca bildirim (declaration) yapılmıştır, ilk değer verilmemiştir. `ar[0]`'a 15, `ar[1]`'e 17, `ar[3]`'e de bu ikisinin toplamı olan 32 atanır. `ar[2]` ve `ar[4]` için bir değer yazılmamıştır; içerikleri tanımsızdır (undefined), yani o bellek gözlerinde önceki program çalışmasından ne kaldıysa odur. Bildirimde eşittir operatörüyle ilk değer verilseydi içerikler sıfırlanabilirdi; bu birazdan ele alındı.

Slayttaki bellek tablosu şöyleydi:

| Eleman | Adres | Değer |
|---|---|---|
| | 0x0FFC | |
| `ar[0]` | 0x1000 | 15 |
| `ar[1]` | 0x1004 | 17 |
| `ar[2]` | 0x1008 | tanımsız |
| `ar[3]` | 0x100C | 32 |
| `ar[4]` | 0x1010 | tanımsız |
| | 0x1014 | |

`ar` değişkenine işletim sisteminin programa ayırdığı bellekteki ilk elemanın adresi atanır; hoca slayta `ar = &ar[0]` yazdı. İlk elemanın 1000 numaralı adreste oturduğu kabul edilirse ondan önceki göz 0x0FFC'dir; 0x0FFC'ye 4 eklenince 0x1000 elde edilir (onaltılıkta C + 4 = 0x10, elde ile 0x1000). Hoca burada eklenen şeyin aslında "4" değil `sizeof(int)` kadar olduğunu, bunun önceki hafta konuşulduğunu hatırlattı; `sizeof(ar[0])` da denebilir. Elemanlar böylece 0x100C, 0x1010, 0x1014 diye ilerler. Bunun önemli sonucu şudur: `ar[0]`'ın adresi biliniyorsa diğer bütün elemanlara işaretçi aritmetiğiyle erişilebilir.

### 4.1 `scanf` ve `printf` içinde adres hesabı

Bir dizinin `i`. elemanına `scanf("%d", &ar[i]);` ile veri okunur. `ar[i]` bir adres değil değer belirttiği için önüne `&` yazılması gerekir; bu çok yapılan bir hatadır. Arka planda olan şudur: `ar` dizinin ilk elemanının adresidir; buna `i * sizeof(int)` eklenir. Örneğin 3. eleman için adrese $3 \times 4 = 12$ bayt eklenir ve o gözün adresi elde edilir. Bu adres hesabı hem `printf`'te hem `scanf`'te yapılır; `scanf` doğrudan adres istediği için `&` yazılır. `printf("%d", ar[i])` ise `ar + i` adresindeki veriyi getirip yazdırmak demektir; burada da örtük bir işaretçi aritmetiği vardır.

## 5. Dizilere ilk değer verme

Slayttaki örnekler şunlardı (ekrandan, 00:30:00):

```c
int a_ar[5];
int b_ar[5] = {1, 2, 3.5, 4, 5};
int c_ar[5] = {1, 2, 3};

char d_ar[] = {'a', 'b', 'c', 'd'};
```

Slayttaki kurallar şöyle:

- Dizinin eleman sayısından fazla başlatıcı değer yazmak yanlıştır. 5 elemanlı bir diziye en fazla 5 değer yazılır.
- Eleman sayısından az değer yazılırsa kalan elemanlar sıfırlanır. `c_ar` dizisinde son iki eleman 0 olur.
- `b_ar` bir tamsayı dizisi olduğu için 3.5 değeri tamsayıya çevrilir ve 3 olarak saklanır (kesirli kısım atılır).
- İlk değerler yazılırsa dizi boyutu yazılmayabilir (omit). Derleyici dizide kaç eleman olduğunu kendisi bulur; `d_ar` dizisinin boyutu 4 olur.

### 5.1 Diziyi sıfırlamanın en kolay yolu

Hoca "Bir diziyi sıfırlamanın en kolay yolu nedir?" diye sordu. Öğrencilerin sık başvurduğu `static int a[...]` yolunu slayta yazıp üzerini çizdi: önceki hafta görülen `static` diziyi sıfırlamanın yolu değildir. En kolay yol `int a[10] = {0};` yazmaktır; küme parantezi içine tek bir 0 yazmak yeter, bütün elemanlar sıfırlanır. Hoca slayta `int a[10] = {0,0};` biçimini de yazdı ama tek sıfırın yeterli olduğunu belirtti.

> **Hocanın vurgusu:** Diziyi sıfırlamak gerekiyorsa `static` kullanmayın; `int a[10] = {0};` yazın.

> **Ders sonrası not:** Hoca boyutu yazılmayan dizide derleyicinin boyutu kendisi bulmasının "biraz performans kaybı" getirdiğini söyledi. Boyut derleme anında başlatıcıdan belirlenir; büyük olasılıkla programın çalışması sırasında ek bir maliyet yoktur.

## 6. Dizi elemanlarına indis ve işaretçiyle erişim

### 6.1 İki erişim yöntemi

Dizi elemanlarına iki yolla erişilir. Birincisi indis operatörüdür: 4 elemanlı bir dizide `ar[0]`, `ar[1]`, `ar[2]`, `ar[3]` yazılır (4. indis yoktur). Erişim bir `for` döngüsüyle ilk elemandan son elemana sırayla yapılabilir. İkincisi işaretçiyle erişimdir.

Slayttaki örnek `short ar[4];` idi (ekrandan, 00:35:00). Hoca bunun "dört short" olduğunu, short'tan başka ayrı bir bileşik veri tipi olmadığını vurguladı. Her eleman bir `short` değişkenine atanabilir: `short s;` tanımlıysa `s = ar[3];` ya da `s = ar[2];` yazılabilir. İşaretçiyle erişmek için dizinin tipinde bir işaretçi gerekir: `short *p;`. Dizi `int` olsaydı işaretçi de `int *` olurdu. Hoca örneklerin hep `short` ile verilmesinin bir zorunluluk olmadığını, yalnız anlatım için seçildiğini ekledi.

### 6.2 `p = ar` ve `*(p+3)`

Slayttaki ifadeler:

```c
short ar[4];
short *p;
p = &ar[0];  // assigns the address of array element 0 to p.
p = ar;      // is same as above assignment!
```

0. elemanın adresi işaretçi değişkenine kopyalanınca dizinin başındaki adres tespit edilmiş olur. Bu adresten ileri ya da geri gidilerek dizinin bütün elemanlarına erişilebilir. Dizi adı (etiketin kendisi) zaten `ar[0]`'ın adresini tuttuğu için `p = ar;` yukarıdakiyle aynıdır. `p + 3` dizinin başından itibaren 3 eleman ilerlemek demektir; ilk eleman 0. eleman olduğu için `*(p+3)` dördüncü elemana, yani `ar[3]`'e karşılık gelir.

Hoca bunun `scanf` karşılığını slayta yazdı (ekrandan, 00:35:00):

```c
scanf("%d", &ar[3]);
scanf("%d", (p+3));
```

Hoca önce `short` için `%s` yazmayı düşündü, `%s`'nin string için olduğunu fark edip `%d` yaptı. İşaretçiyle erişimde öğrencilerin sık yaptığı hata `p+3`'ün önüne de `&` koymaktır. `p` dizinin 0. elemanının adresidir; buna 3 eklemek 3. elemanın adresi demektir. Yani `p+3` zaten bir adrestir ve `scanf` değeri doğrudan oraya yazar.

> **Ders sonrası not:** `short` tipi için `scanf`'te doğru biçim belirteci `%hd`'dir; `%d` `int *` bekler. Hoca slaytta anlatım kolaylığı için `%d` yazdı.

### 6.3 Geçerli ve geçersiz atamalar

Slaytın sağındaki örnek (ekrandan, 00:35:00):

```c
float ar[5], *p;
...
p = ar;           // legal
ar = p;           // illegal
&p = ar;          // illegal
ar++;             // illegal
ar[1] = *(p+3);   // legal
p++;              // legal
```

`float ar[5], *p;` satırı aynı satırda bir dizi ve bir işaretçi tanımlar. Açıklamaları:

- `p = ar;` geçerlidir: dizinin ilk elemanının adresi işaretçiye kopyalanır.
- `ar = p;` geçersizdir: `ar`'ın adresi derleyici tarafından belirlenmiştir, değiştirilemez, sabittir.
- `&p = ar;` geçersizdir: `&p`, `p`'nin oturduğu adrestir ve atamanın sol tarafında yer alamaz. Hoca bunu "sol taraf ikinci dereceden, sağ taraf birinci dereceden bir işaretçi; birinci dereceden bir şey ikinci dereceden bir şeye atanmaz" diye açıkladı.
- `ar++;` geçersizdir: `ar` bir adres sabiti olduğu için doğrudan artırılamaz.
- `ar[1] = *(p+3);` geçerlidir: `p+3`'ün gösterdiği değer `ar[1]`'e kopyalanır.
- `p++;` geçerlidir: `p` şu an `ar[0]`'ı gösteriyorsa artırıldıktan sonra `ar[1]`'i gösterir. `p` bir `float` işaretçisi olduğu için adres `sizeof(float)` kadar artar.

## 7. Sıralama örnekleri ve swap işlemi

### 7.1 Kabarcık ve seçmeli sıralama

Hoca dizilere örnek olarak iki sıralama algoritmasını slayttaki animasyonlarla gösterdi (ekrandan, 00:40:00). Sıralama algoritmalarının ayrıca anlatılacağını da belirtti.

Kabarcık sıralaması (bubble sort) önce ilk iki elemana bakar; aralarındaki sıra bozuksa onları yer değiştirir. Animasyonun başında 6 ile 5 yer değiştirdi, sonra 6 ile 3'e bakıldı, sonra 6 ile 1'e. Dizinin başından sonuna bir tur gidilir: 6 ile 8 karşılaştırılır ve değişmez; 8 ile 2, sonra 8 ile 4 yer değiştirir. Bu tur bittiğinde en sondaki eleman en büyük elemandır. Sonra aynı işlem baştan bir daha başlar; en büyük veri "iteleye iteleye" sona taşınır. İkinci turda 7 ile 2, sonra 7 ile 4 yer değiştirdi. Karede animasyonun bir anında dizi `1 3 5 6 2 4 7 8` durumundaydı; son iki eleman (7 ve 8) yerine oturmuştu.

Seçmeli sıralama (selection sort) en basit mantıkla çalışan algoritmalardan biridir. Elemanların en küçüğü bulunur ve başa getirilir (baştaki elemanla yer değiştirilir). Artık en küçüğün yeri bellidir; kalanların içinden en küçüğü alınıp ikinci sıraya getirilir, böyle devam edilir. 10 eleman varsa en küçüğü bulma işlemi 10 kez çalışır ve her seferinde sıralanmamış kısmın başından başlar. Karedeki animasyonda dizinin ilk beş elemanı (0, 1, 2, 3, 4) sıralanmış, kalan `6 5 9 8 7` kısmında 4. konumla kalanların en küçüğünün yer değiştirmesi gösteriliyordu.

### 7.2 Swap

İki algoritmanın da temelinde yer değiştirme (swap) işlemi vardır. Hoca bu algoritmaların kodunu fonksiyonlar konusunda yazacağını, çünkü swap'ın fonksiyonla yapılmasında farklı bir mekanizmanın (adresle gönderme) devreye gireceğini söyledi. Fonksiyona göndermeden, dizinin `i`. ve `j`. elemanı bir geçici değişkenle yer değiştirilir:

```c
int t;
t = dizi[i];
dizi[i] = dizi[j];
dizi[j] = t;
```

Aynı işlem işaretçi aritmetiğiyle de yazılabilir. `dizi + i` bir adres verir; o adresteki değer `*(dizi + i)` ile alınır:

```c
t = *(dizi + i);
*(dizi + i) = *(dizi + j);
*(dizi + j) = t;
```

Hoca yazarken bir an `i` ile `j`'yi karıştırıp düzeltti. İki yazım aynı işi yapar; fark, birinde işaretçi işlemini programcının kendisinin, ötekinde derleyicinin arka planda yapmasıdır. "İşaretçi aritmetiği kullanarak diziye erişin" denen sorularda ikinci yazım kullanılmalıdır.

## 8. Dev-C++ uygulaması: diziler ve işaretçiler birlikte

Hoca aradan önce konuların "havada kalmaması" için Dev-C++'ta (TDM-GCC 4.8.1, 64 bit) basit bir program yazdı (ekrandan, 00:45:00).

### 8.1 Dizi elemanlarını ve adreslerini yazdırmak

Hoca dizi boyutunu kodun içine 5 diye yazmak yerine `#define N 5` ile tanımlamanın daha doğru olduğunu söyledi: boyut değişecekse (örneğin 50 olacaksa) iki ya da daha fazla yere gidip değiştirmek gerekmez, tek yerden değişir. Programın başı şöyleydi (ekrandan, 00:50:00):

```c
int a[N]={1,2,3};
int b[N]={5,6,7};
int i;
int *pA,*pB;

for(i=0;i<N;i++){
    printf("p[%d]= %d --- &p[i]= %p\n",i,a[i],&a[i]);
}
printf("\Pointer ile\n");
for(i=0;i<N;i++){
    printf("p[%d]= %d --- &p[i]= %p ---&p[i]= %p\n",i,*(a+i),(a+i),(&a[0]+i));
}
```

`%p` adresi işaretçi biçiminde yazdırır. İlk döngü indisle `a[i]` değerini ve `&a[i]` adresini yazar. Çıktı 1, 2, 3, 0, 0 oldu (başlatıcıda yazılmayan son iki eleman 0); adresler son haneleri ...30, ...34, ...38 diye 4'er artarak düzenli ilerledi. İkinci döngü aynı değerleri işaretçiyle yazar: değer `*(a+i)`, adres `a+i` ya da `&a[0]+i` ile alınır. `&a[0]+i` önce 0. elemanın adresini alıp sonra ona `i` ekler. Hoca format dizisindeki `[i]` kısımlarının yalnızca ekrana çıkan metin olduğunu fark edip bunları da `%d` yapıp argüman olarak `i` ekledi ("C'nin böyle bir kötülüğü var" diyerek). Derleyicinin `"\Pointer ile\n"` satırı için verdiği "unknown escape sequence: '\P'" uyarısı da ekranda görünüyordu (ekrandan, 00:50:00).

### 8.2 İşaretçiyle `scanf`

Sonra `a[2]` için klasik yolla `scanf("%d", &a[2]);` ile, `a[1]` için işaretçiyle `scanf("%d", (a+1));` ile değer okundu (ekrandan, 00:55:00). Hoca `a+1`'i parantez içine aldığını, işlem önceliğini o an hatırlamadığı için olası bir aksaklıktan kaçınmak istediğini söyledi. `&` konmadı, çünkü `a` zaten bir adrestir, bir sonraki elemanı da bir adrestir. Girilen 7 ve 8 değerleri `a[2]` ve `a[1]`'e yerleşti.

Sonra işaretçi değişkenleri kullanıldı: `pA = a;` (yorum satırında `pA=&a[0]`) ve `pB = &b[0];`. Hoca `pA = a` ile `pA = &a[0]`'ın aynı olduğunu, ikincisinde önce 0. elemanın adresinin hesaplandığını, sonra atamanın yapıldığını söyledi. `b`'nin iki elemanına işaretçiyle değer okundu (ekrandan, 01:00:00):

```c
printf("Enter a value for b[0]");
scanf("%d",pB); //&pB[0]
printf("Enter a value for b[1]");
scanf("%d",(pB+1));
```

`pB` doğrudan 0. elemanın adresini gösterir; yorum satırındaki `&pB[0]` ile aynıdır. `pB+1` birinci elemanın adresidir. Hoca "buraya kesinlikle `&` eklemeyin" diye uyardı.

**Soru:** `printf` içindeki metinde `%d`'lerin önünde hep `p` yazıyor; `b`'nin değerlerini ve adresini gösterdiğimize göre bunların `b` olması gerekmiyor mu? **Cevap:** Format dizisinde `%d` ve `%p` dışındaki her şey ekrana doğrudan çıkan karakterlerdir, çıktıya bir etkisi yoktur; okunurluk için `A` ve `B` yapılabilir. Hoca bunları `A[%d]` ve `B[%d]` olarak düzeltti.

İlk çalıştırmada `b`'ye 3 ve 4 girildi; `b[2]`'de 7 göründü. Hoca bu 7'nin nereden geldiğini bilmediğini söyledi. `A` dizisinin başladığı adresle `B` dizisinin başladığı adres de farklı bölgelerde görünüyordu.

> **Ders sonrası not:** O sırada ekranda `int b[N]={5,6,7};` tanımı vardı (ekrandan, 00:50:00). `b[0]` ve `b[1]`'e 3 ve 4 okununca `b[2]` başlatıcıdan gelen 7 olarak kaldı; değer tesadüf değildir.

### 8.3 İşaretçi aritmetiğiyle atamalar

Hoca sonra işaretçilerle değer atadı (ekrandan, 01:00:00 ve 01:05:00):

```c
printf("B dizisi\n");
*(pB+2)=*(pB)+ *(pB+1) +10;
*(pB+3)=-5;
```

İlk satır `pB`'nin gösterdiği değer ile `pB+1`'in gösterdiği değerin toplamına 10 ekleyip `b[2]`'ye yazar. Hoca ilk denemede `pB+3=-5;` yazdı (ekrandan, 01:00:00); "üç eleman sonraki adrese gidip o adresteki değere $-5$ yazacağız" diyerek bunu `*(pB+3)=-5;` olarak düzeltti. Çalıştırmada 1 ve 2 girilince `b` dizisi 1, 2, 13 ($1 + 2 + 10$), $-5$ ve 0 oldu. Son elemanın 0 olmasının nedeni başlatıcı yazılmış olmasıydı. Hoca başlatıcıyı yorum satırına alınca (`int b[N+1]; //={5,6,7};`, ekrandan, 01:40:00) ilk değer verilmeyen gözlerde önceki çalışmalardan kalan değerler, örneğin $-1$, göründü.

### 8.4 Bir adresi tamsayı olarak saklamak

Son olarak iki satır daha eklendi (ekrandan, 01:05:00):

```c
*(pB+4)=*(pA+3);
*(pB+5)=(int)(pA+4);
```

Birinci satır `pA+3`'ün gösterdiği değeri, yani `a[3]`'ü (dördüncü göz) `b[4]`'e kopyalar. İkinci satırda `*` yoktur: `pA+4` bir adrestir ve bu adresin sayısal değeri `b[5]`'e yazılmaya çalışılır. Hoca "`pB+5`'e zaten bir şey yazamam" dedikten sonra dizinin boyutunu bir artırıp (`b[N+1]`) döngüyü `i<N+1`'e kadar götürdü.

`(int)` dönüşümü olmadan derleyici "assignment makes integer from pointer without a cast" uyarısı verir: sol taraf bir `int`, sağ taraf bir `int *` adresidir. `(int)` ile dönüştürülünce bu kez "cast from pointer to integer of different size [-Wpointer-to-int-cast]" uyarısı geldi (ekrandan, 01:05:00 ve 01:10:00). Hoca bunu şöyle açıkladı: uyarı programın çalışmasına engel değildir, ama adres değeri `int`'in sınırlarını aşabilir; bu yüzden böyle durumlarda örneğin `long` kullanılır. Çalıştırmada 2 ve 2 girilince `b[2]` 14 oldu, `b[3]` $-5$, `b[4]` `a[3]`'ten gelen 0. `b[5]` ise `a[4]`'ün adresinin onluk karşılığıydı. Hoca o çalıştırmada `a[4]`'ün adresinin 23FE30 diye bir değer olduğunu, onaltılıktan onluğa 16'nın kuvvetleriyle çarpılarak çevrilmesi gerektiğini söyledi; 0x23FE30 onlukta 2358832'dir (ara adım eklendi).

**Soru:** Az önceki atamalarda uyarı veriyordu; işaretçi dereceleri farklı olduğunda da yine uyarı mı verir, yoksa program hiç çalışmaz mı? **Cevap:** Hoca `*(pB+5) = &pA;` satırıyla bunu gösterdi (ekrandan, 01:10:00). `pA` bir adrestir ve onun da kendine ait bir adresi vardır; `&pA` ikinci dereceden bir işaretçidir. Burada da benzer uyarılar gelir: dönüşüm yoksa "assignment makes integer from pointer without a cast", `(int)&pA` yazılırsa yine "farklı boyutta" uyarısı. Sonuçta her şey sayısal bir değere dönüştüğü için atama yapılır; derleyici yalnızca gelen değerin `int`'e sığmayabileceği konusunda uyarır.

### 8.5 `pA + 4` kaç bayt ekler?

Aradan dönünce hoca bir öğrencinin sorusunu açtı: `pA + 4` yazınca adrese 4 eklenmez; `4 * sizeof(int)` eklenir. `sizeof(int)` bu bilgisayarda 4 olduğu için adrese 16 eklenir. Ama `sizeof(int)`'in her zaman 4 olması gerekmez, 8 de olabilir. Hoca `sizeof`'un bir operatör olduğunu belirtip bunu yazdırdı (ekrandan, 01:25:00):

```c
printf("Integer*4=%d",4*sizeof(int));
```

Çıktı 16 oldu. 16 eklemek, adresin onaltılık değerine 16 (0x10) eklemek demektir.

Bir öğrenci hocanın parantezleri yazarken kullandığı bir kısayolu sordu. Hoca bir kısayol kullanmadığını, `*(pB+5)` gibi ifadeleri yazarken önce `pB+5`'in hesaplandığını, sonra parantezin, en son `*`'ın geldiğini göstermek için bu sırayla yazdığını söyledi. Satır sonuna gitmek için End tuşu, kelime atlamak için Ctrl + sağ ok kullanılabilir.

### 8.6 Programın son hali

Aşağıdaki program, derste ekranda görülen parçalardan birleştirildi (ekrandan, 00:50:00, 01:05:00, 01:25:00, 01:35:00 ve 01:40:00). `a[2]` okuma satırları karelerde görünmüyor, altyazıdan kuruldu. Program bu not hazırlanırken `gcc -Wall` ile derlendi ve `7, 8, 2, 2` girdileriyle çalıştırıldı:

```c
#include<stdio.h>
#define N 5
int main(){

    int a[N]={1,2,3};
    int b[N+1];
    int i;
    int *pA,*pB;
    pA=a; // pA=&a[0]
    pB=&b[0];

    for(i=0;i<N;i++){
        printf("A[%d]= %d --- &A[%d]= %p\n",i,a[i],i,&a[i]);
    }
    printf("Pointer ile\n");
    for(i=0;i<N;i++){
        printf("A[%d]= %d --- &A[%d]= %p ---&A[%d]= %p\n",i,*(a+i),i,(a+i),i,(&a[0]+i));
    }

    printf("Enter a value for a[2]");
    scanf("%d",&a[2]);
    printf("Enter a value for a[1]");
    scanf("%d",(a+1));
    for(i=0;i<N;i++){
        printf("A[%d]= %d --- &A[%d]= %p ---&A[%d]= %p\n",i,*(a+i),i,(a+i),i,(&a[0]+i));
    }

    printf("Enter a value for b[0]");
    scanf("%d",pB); //&pB[0]
    printf("Enter a value for b[1]");
    scanf("%d",(pB+1));
    printf("B dizisi\n");
    *(pB+2)=*(pB)+ *(pB+1) +10;
    *(pB+3)=-5;
    *(pB+4)=*(pA+3);
    *(pB+5)=(int)(pA+4);
    for(i=0;i<N+1;i++){
        printf("B[%d]= %d --- &B[%d]= %p ---&B[%d]= %p\n",i,*(b+i),i,(b+i),i,(&b[0]+i));
    }

    printf("Integer*4=%d",4*sizeof(int));
    return 0;
}
```

Test çıktısında `A` dizisi önce 1, 2, 3, 0, 0; okumalardan sonra 1, 8, 7, 0, 0 oldu. `B` dizisi 2, 2, 14, $-5$, 0 ve son gözde adresten türeyen büyük bir sayı olarak yazıldı; son satır `Integer*4=16` oldu. Adresler her elemanda 4 bayt arttı. 64 bit Linux'ta `gcc -Wall` iki uyarı verdi: `(int)(pA+4)` için "cast from pointer to integer of different size" ve son `printf` için `%d` ile `sizeof` sonucu (`size_t`) arasındaki tip uyuşmazlığı.

> **Ek bilgi (derste anlatılmadı):** `sizeof` sonucu `size_t` tipindedir ve `printf`'te taşınabilir biçimi `%zu`'dur. Bir adresi tamsayı olarak saklamak gerekiyorsa `<stdint.h>` içindeki `intptr_t` ya da `uintptr_t` tipleri, adresi kayıpsız tutacak genişlikte olacak şekilde tanımlanmıştır.

## 9. Dersin genel çerçevesi: işaretçi, dizi, struct ve fonksiyon

Hoca soru sormadan önce dersin genel yapısını kartezyen çarpım benzetmesiyle anlattı. Dönem boyunca işaretçi, dizi (array), struct ve fonksiyon konuları görülecek. Bunların her biri ayrı bir küme gibi düşünülürse şu an görülen "işaretçi × dizi"dir. Sonra "işaretçi × dizi × fonksiyon" gelecek. Struct'lar görülünce struct'larla diziler, struct'larla işaretçiler birlikte kullanılacak; struct'lar fonksiyona işaretçiyle gönderilecek. En sonunda bir struct dizisini işaretçiyle fonksiyona göndermek ya da fonksiyondan almak gerekecek.

> **Hocanın vurgusu:** Bu dersin özü bu kesişimdir: işaretçi, dizi, struct ve fonksiyonun birlikte kullanımı. Bu konuları çok iyi bilen biri dersin kalanında sıkıntı çekmez.

Dosya işlemleri (file operation) bunlara bir eklentidir; belki thread ve soket programlama da görülecek. Soket ve thread programlama arka planda dosyaları ve bu konuları kullanır. Veri yapılarına giriş (intro to data structures) de bu üç konunun bir anlamda uygulamasıdır. Hoca öğrencilerden işaretçileri ve dizileri birbirine "hibrit" olarak kullanmaya alışmalarını istedi.

## 10. Stringler: null karakterle biten karakter dizileri

### 10.1 Tanım

Hoca, dizileri öğrendikten sonra stringlerin dizilerin özel bir hali olduğunu bilmenin yeterli olduğunu, yalnızca birkaç farklı durum bulunduğunu söyledi. Tamsayı dizisi tamsayılardan, float dizisi float'lardan oluşur; string ise karakterlerden oluşur. Karakter dizisine, karakter katarına string denir. Slayttaki tanımlar (ekrandan, 01:30:00):

- A string is an array of characters terminated by a null character.
  - Null karakter, sayısal değeri 0 olan karakterdir.
  - C'de `'\0'` kaçış dizisiyle gösterilir.
- A string constant is any series of characters enclosed in double quotes.
  - Veri tipi karakter dizisidir ve stringdeki her karakter bir bayt yer kaplar.

Tamsayı dizisinin (örneğin `int a[3] = {1, 2, 3}`) sonunda özel bir işaret yoktur; sonunun denetimi programcıya kalmıştır. Karakter dizisi tanımlandığında ise derleyici stringin sonunu belli etmek için otomatik olarak bir null karakter ekler.

### 10.2 Null karakter ne işe yarar?

Hoca bunun ne işe yarayabileceğini sordu. Bir öğrenci stringin kaç harfli olduğunu (uzunluğunu) bulmaya yarayabileceğini söyledi; hoca bunu doğru buldu ve daha basit düşünmelerini istedi. Cevap: `printf("%s", str);` yazıldığında `str` dizinin başlangıç adresidir. Bellekte örneğin "some text"in `s`, `o`, `m`, ... karakterleri sırayla durur ve `str` ilk karakteri gösterir. `%s` ile yazdırmak şu demektir: bu adrese git, oradan başla, null karakteri görene kadar gördüğün her şeyi yaz. Null karakter stringin sonunu bulmayı sağlar.

Null karakter, boşluk (space) karakteriyle karıştırılmamalıdır. `"A B"` gibi bir stringde A ile B arasındaki boşluk ayrı bir karakterdir; `'\0'` bundan farklıdır. Bütün stringlerin sonunda diğer dizilerden farklı olarak bir null karakter bulunduğu için 4 karakterlik bir string bellekte 5 karakter yer kaplar.

### 10.3 Slayttaki tanımlar

Slaytın sağındaki tanımlar şunlardı (ekrandan, 01:30:00):

```c
char str[] = "some text";
char str[10] = "yes";
char str[3] = "four";
char str[4] = "four";

char *ptr = "more text";
```

- `"some text"` 9 karakterdir (4 + boşluk + 4); 10. eleman `'\0'`'dır, dizinin boyutu 10 olur.
- `char str[10] = "yes";` dizisinde 10 yer açılır, içine `yes` yazılır; 4. eleman `'\0'` olur.
- Kırmızıyla gösterilen `char str[3] = "four";` ve `char str[4] = "four";` tanımlarında dizi, 4 karakter ile `'\0'`'ı alacak kadar büyük değildir.
- `char *ptr = "more text";` satırında boyut yazmaya gerek yoktur. Çift tırnak arasındaki string bellekte bir adrese yerleştirilir ve ilk karakterin (`m`) adresi `ptr`'ye kopyalanır. Burada hem bildirim hem tanım vardır. Her karakter bir bayt olduğu için bu string $4 + 1 + 4 + 1 = 10$ bayt yer kaplar (sondaki `'\0'` dahil).

> **Ek bilgi (derste anlatılmadı):** C standardına göre `char str[4] = "four";` geçerlidir ama dizi null karakteri içermez, yani bir string değildir; `printf("%s", ...)` ya da `strlen` ile kullanılması tanımsız davranıştır. `char str[3] = "four";` ise başlatıcı diziden uzun olduğu için hatalıdır (derleyici uyarı verir).

### 10.4 `sizeof` ve `strlen` farkı

Hoca stringleri Dev-C++'ta denedi (ekrandan, 01:40:00):

```c
char *ptr="AAA BBB";
char str[10]="AAA BBB";
printf("%s -- sizeof(%d) -- length(%d)",str,sizeof(str),strlen(str));
printf("\n%s -- sizeof(%d)-- length(%d)",ptr,sizeof(ptr),strlen(ptr));
```

`strlen` için `#include<string.h>` gerekir. Hoca `sizeof` ile uzunluğun farklı şeyler olduğunu vurguladı. `sizeof(str)` 10 çıktı: dizi için ayrılan yer. İki uzunluk da 7 çıktı: `AAA`, boşluk ve `BBB`. `sizeof(ptr)` 8 çıktı.

**Soru:** İkinci `printf`'te `sizeof(ptr)` için de bir `%d` ve karşılığında bir değişken koymamız gerekmiyor mu? **Cevap:** `str` `%s`'ye, `sizeof(str)` `%d`'ye gider; her biçim belirtecinin karşılığında bir argüman vardır.

> **Ders sonrası not:** Hoca `sizeof(ptr)`'in 8 çıkmasını 7 karakter ile sondaki `'\0'` diye yorumladı. `ptr` bir işaretçi olduğu için `sizeof(ptr)` stringin değil işaretçinin boyutunu verir; 64 bit sistemde bu 8 bayttır. Stringin 7 + 1 = 8 bayt olması tesadüftür. Bu not hazırlanırken derlenen programda da `sizeof(str)` 10, `sizeof(ptr)` 8, iki `strlen` de 7 çıktı.

### 10.5 `strlen` nasıl çalışır?

Hoca `strlen`'in içini bir `while` döngüsüyle anlattı: `ptr[i]` null karakterden farklı olduğu sürece sayaç bir artırılır. Null karakter tek tırnak içinde `'\0'` diye yazılır; tek tırnak içinde iki sembol yazılabilmesinin nedeni bunun özel bir karakter olmasıdır. Son karaktere, yani `'\0'`'a gelince sayaç artırılmaz; uzunluk null karakteri saymaz. Algoritmalarda sayacın 0'dan ya da 1'den başlatılmasına göre uzunluk bir fazla görülebilir; bu yüzden uzunluk 7 çıkar.

**Soru:** İşaretçiyle tanımlanınca da sonuna null ekleniyor mu? **Cevap:** Evet; işaretçiyle de dizi olarak da tanımlansa string sonuna null eklenmek zorundadır. Ekrana yazdırırken iki tanım da fazladan karakter göstermedi; null eklenmeseydi bellekte devam eden hücreler de yazılırdı. Hoca bunu kanıtlamak için stringin ortasına `'\0'` ekledi: `char str[10]="AA\0A BBB";` (ekrandan, 01:45:00). `%s` yalnızca `'\0'`'a kadarki kısmı yazdı; uzunluk da buna göre kısaldı, `sizeof` ise değişmedi.

### 10.6 Karakter karakter işlem: büyük harften küçük harfe

Stringler üzerinde normal bir dizi gibi işlem yapılabilir. Hoca bir `for` döngüsüyle her karakteri `%c` ile ayrı ayrı bastırdı, sonra her karaktere 32 ekletti:

```c
for(i=0;i<10;i++){
    printf("%c",str[i]+32);
}
```

Hoca önce "eksi 48" ya da "eksi 32" dedi, sonra artı 32 olduğunu düzeltti. ASCII'de 'A' 65'tir; $65 + 32 = 97$ 'a' eder. Boşluk karakterine (32) 32 eklenince 64 olur ve `@` işareti çıkar. Bu yüzden okunan karakter analiz edilmeli, boşluk görülürse boşluk yazılmalıdır. Bu not hazırlanırken derlenen programda `"AAA BBB"` için çıktı `aaa@bbb` oldu.

## 11. Hata ayıklama (debug) ve sabit stringler

### 11.1 İşaretçiyle tanımlanan stringin karakteri değişir mi?

**Soru:** `ptr` ile string tanımlarsak elemanlar üzerinde değişiklik yapamıyoruz, değil mi? **Cevap:** Hoca bunu hiç denemediğini söyleyip denedi (ekrandan, 01:45:00):

```c
char *ptr="AAA BBB";
char str[10]="AA\0A BBB";
printf("%s -- sizeof(%d) -- length(%d)",str,sizeof(str),strlen(str));
printf("\n%s -- sizeof(%d)-- length(%d)",ptr,sizeof(ptr),strlen(ptr));

ptr[3]='C';
printf("\n%s -- sizeof(%d)-- length(%d)",ptr,sizeof(ptr),strlen(ptr));
```

Program çalışırken hata verdi. Hata ayıklayıcıyla bakılınca `ptr[3]='C';` satırında segmentasyon hatası (segmentation fault) alındığı görüldü: işaretçiyle atanmış bir sabit stringin karakteri bu şekilde değiştirilemez. Hoca sonra `*(ptr+3)` ile işaretçi aritmetiğini denedi; yine hata alındı ve hoca bunun sabit (constant) olmasından kaynaklandığını, `strcpy` ya da `strcat` gibi fonksiyonların farklı bir iş olduğunu söyledi. Hoca bunu "illegal" diye özetledi. Bu not hazırlanırken derlenen küçük bir programda da `ptr[3]='C';` satırı segmentasyon hatası verdi.

> **Ek bilgi (derste anlatılmadı):** `char *ptr = "..."` ile gösterilen string sabiti genellikle salt okunur bir bellek bölgesine yerleştirilir ve C standardına göre değiştirilmesi tanımsız davranıştır. Değiştirilebilir bir string için `char str[] = "...";` biçimi kullanılır; bu durumda karakterler dizinin kendi belleğine kopyalanır. Bu yüzden işaretçi `const char *ptr` diye tanımlanırsa hatalı atama derleme anında yakalanır.

### 11.2 Dev-C++'ta hata ayıklama

Hoca hata ayıklamayı önceki hafta anlatıp anlatmadığını sordu, anlatmadığı anlaşılınca gösterdi. Program derlenip çalışıyor ama beklenen sonucu vermiyorsa (mantıksal hata), en kısa ve en iyi çözüm hata ayıklamaktır (debug). Bu `printf` satırları ekleyerek, önişlemci yönergeleriyle ya da güncel IDE'lerin kendi hata ayıklama araçlarıyla yapılabilir. Dev-C++'ta adımlar şöyledir (ekrandan, 01:45:00):

- Satır numarasının yanına bir kez tıklanınca satır kırmızı olur; bu bir kesme noktasıdır (breakpoint). Program bu satıra kadar çalışır, sonrasında adım adım ilerler.
- Son değişikliklerin yansıması için program yeniden derlenir, sonra Execute menüsünden Debug seçilir.
- Program kesme noktasında bekler. Fare bir değişkenin üzerine getirilince içeriği görünür. Sağ tıklayıp ya da alttaki düğmeyle "Add Watch" denerek değişken izleme listesine eklenir.
- "Next line" ile bir sonraki satıra geçilir; o satır ne yapacaksa yapılır.

Hata ayıklayıcıda `ptr` için `0x404000 "AAA BBB"`, `str` için `"AA\000A BBB\000"` görünüyordu: hocanın eklediği `'\0'`'dan sonra `A BBB` geliyor ve sonunda derleyicinin eklediği `'\0'` bulunuyordu (ekrandan, 01:45:00). `%s` ilk `'\0'`'ı görünce stringin bittiğini kabul eder.

Hoca yeni konunun örneklerinin, kayıt tekrar izlenirken karışmaması için ayrı bir dosyada yapılmasının daha iyi olacağı önerisi üzerine örnekleri yeni bir dosyaya taşıdı.

## 12. String atamaları, karakterler ve stringler

### 12.1 String atamaları

Slayttaki örnek (ekrandan, 01:50:00):

```c
main () {
    char array[10];
    char *ptr1="10 spaces";
    char *ptr2;
    array = "not OK";       // can NOT assign to an address! Does not compile
    array[5] = 'A';         // Buggy because: Array is not populated yet. So, ...
    array[0] = 'C';         // ... Always begin from 0 and
    array[1] = '\0';        // use null-terminated strings where necessary
    ptr1[8] = 'r';          // Buggy because: The entire string is not populated yet.
    *ptr2 = "not OK";       // Type mismatch warning. Does not compile
    ptr2="OK";
}
```

Slaytın dipnotunda "in DevCPP4, linker gives warning at first but if you make a second attempt, it compiles!" yazıyordu. Hoca belleği çizerek anlattı: `ptr2` henüz hiçbir yeri göstermez; `ptr1` ise "10 spaces" stringinin bellekteki başlangıç adresini (örneğin 100) gösterir. `array` için 10 karakterlik yer ayrılmıştır, içi henüz doldurulmamıştır.

- `array = "not OK";` geçersizdir: `array` bir adrestir ve bir adrese string atanamaz.
- `array[5] = 'A';` dizi henüz doldurulmadığı için sorunlu kabul edilir; slayt doldurmanın 0'dan başlanarak yapılmasını önerir. `array[0] = 'C';` ve `array[1] = '\0';` geçerlidir: dizinin birinci elemanına sonlandırma karakteri atanabilir.
- `ptr1[8] = 'r';` hocanın biraz önce denediği işlemdir ve hata alınır.
- `*ptr2 = "not OK";` tip uyuşmazlığıdır. Hoca bunu şöyle açıkladı: `*ptr2`, `ptr2`'nin gösterdiği yerdeki tek bir değerdir; sağ tarafta ise çok değerli bir string vardır. Tek bir elemanın içine çoklu bir string yazılamaz. Ayrıca `ptr2` henüz bir yeri göstermediği için ya tanım sırasında başlatma yapılmalı ya da bellek ayrılıp `strcpy` ile kopyalanmalıdır; bu `malloc` konusunda ayrıca görülecek.
- `ptr2 = "OK";` geçerlidir: string bellekte bir yere yerleştirilir ve ilk elemanının adresi `ptr2`'ye atanır. Hoca bunu hata ayıklayıcıda denedi; doğrudan atama çalıştı, `*` konunca çalışmadı.

### 12.2 Karakterler ve stringler

Slayttaki karşılaştırma (ekrandan, 01:55:00):

```c
/* Chars */
char ch = 'a';      // one byte is allocated for 'a'
*p = 'a';           // OK
p = 'a';            // Illegal
/* Strings */
char *p = "a";      // two bytes allocated for "a"
*p = "a";           // INCORRECT
p = "a";            // OK
```

C'de karakterler tek tırnakla, stringler çift tırnakla yazılır; başka dillerle karıştırılmamalıdır. Karakter bir bayt yer kaplar. `*p = 'a';` geçerlidir: işaretçinin gösterdiği bir baytlık yere bir baytlık değer aktarılır. `p = 'a';` geçersizdir: işaretçinin kendisi bir adres tutar, ona karakter atanmaz. `"a"` ise bir stringdir ve sondaki `'\0'` ile iki bayt yer kaplar. `*p = "a";` yanlıştır, çünkü bir baytlık yere iki ya da daha fazla baytlık bir string sığmaz; hoca buna "boyut uyumsuzluğu" dedi. `p = "a";` doğrudur, çünkü burada işaretçiye bir adres atanır.

Hoca `p = "a";` atamasından sonra işaretçiye örneğin `"bb"` gibi daha uzun bir stringin atanıp atanamayacağını öğrencilerin kodda denemesini istedi.

## 13. String okuma, yazma ve string fonksiyonları

### 13.1 `scanf` ve `printf` ile string

Slayttaki program (ekrandan, 02:00:00):

```c
#include <stdio.h>
#define MAX_CHAR 80
int main(int argc,char *argv[]){
    char str[MAX_CHAR];
    printf("Enter a string: ");
    scanf("%s",str);
    printf("\nYou wrote:");
    printf("%s",str);
    return 0;
}
```

Slayttaki açıklamalar: stringler `scanf()` ile okunabilir; argüman, girdi stringini saklayacak kadar uzun bir karakter dizisinin işaretçisi olmalıdır. Karakterleri okuduktan sonra `scanf()` sona otomatik olarak bir null karakter ekler ve string geçerli hale gelir. Stringler `printf()` ile yazılabilir; argüman null ile biten bir karakter dizisinin işaretçisi olmalıdır.

Hoca bazı sorunlar olduğunu da söyledi. Enter'a basıldığında bir karakter oluşur; `%c` ile okumalarda bu sorun yaşanır. Tek kelime girilirse aynısı ekrana basılır. Ama arada boşluk olan iki kelime girilirse (örneğin "Yıldız Teknik") yalnızca boşluğa kadarki kısım alınır. Boşluk, Enter ve Tab karakterleri `%s` için stringin sonu gibi algılanır ve okuma orada durur; derleyici o noktaya null karakteri ekler. Hoca bunu aşmak için ileride başka yöntemler göreceklerini söyledi.

### 13.2 `strlen` fonksiyonu

`strlen` fonksiyonu bir string adresi alır; örneğin `strlen("ytu")` diye çağrılabilir. Gelen adres bir işaretçiye kopyalanır ve işaretçi aritmetiğiyle `'\0'` görülene kadar sayaç artırılır. Sıfırıncı eleman, birinci eleman, ikinci eleman sayılır; `'\0'` görülünce döngü biter. Bu fonksiyon `string.h` içinde tanımlıdır.

### 13.3 Diğer string fonksiyonları

Hoca bu fonksiyonların ayrıntısını ileride ayrı bir slaytla anlatacağını belirterek kısaca saydı:

- `strcpy`: kaynak (source) stringi hedefe (destination) kopyalar.
- `strncpy`: kaynağın en fazla n karakterlik bir parçasını kopyalar.
- `strcat`: bir stringi öbürünün sonuna ekler, ikisini birleştirir (concatenation).
- `strncat`: bir stringin ilk n elemanını öbürünün sonuna ekler.
- `strcmp`: iki stringin bütün karakterlerinin aynı olup olmadığını karakter karakter karşılaştırır.
- `strncmp`: yalnızca ilk n karakteri karşılaştırır.

Hoca `strcmp` için önce "eşitse 1, değilse 0 döndürüyor" dedi, sonra 1, 0 ya da $-1$ döndürebileceğini, birinci stringden ikincinin çıkarıldığını, fark negatifse birinci stringin daha büyük olduğunu söyledi.

> **Ders sonrası not:** Hoca `strcmp`'in eşit stringlerde 1 döndürdüğünü ve fark negatifse birinci stringin büyük olduğunu söyledi. Doğrusu: `strcmp` eşit stringlerde 0 döndürür. Birinci string sözlük sırasında önce geliyorsa (ilk farklı karakteri daha küçükse) negatif, sonra geliyorsa pozitif bir değer döndürür. Dönüş değerinin tam olarak $-1$ ya da 1 olması gerekmez, yalnızca işareti önemlidir.

## 14. Örüntü eşleme (pattern matching)

### 14.1 Kaba kuvvet ve daha hızlı algoritmalar

Stringler üzerinde en çok yapılan işlemlerden biri örüntü eşlemedir (ekrandan, 02:05:00). Bunun için birçok algoritmik yaklaşım vardır. Birincisi kaba kuvvettir (brute force): metnin ilk karakteri aranan parçanın ilk karakteriyle karşılaştırılır; eşitse ikinci karakterlere, sonra üçüncülere bakılır. Hepsi eşitse parça bulunmuştur. Bulunamazsa parça bir karakter kaydırılır ve karşılaştırma yeniden başlar. Hoca slayta metnin altına ve aranan parçanın altına oklar çizerek bunu gösterdi.

Boyer-Moore ve Horspool gibi farklı algoritmalar da vardır. Hoca istatistiksel olarak baştan değil sondan karşılaştırmanın daha başarılı olduğunu söyledi: son karakter eşleşmiyorsa diğer ikisine bakmadan doğrudan kaydırılır. Baştan karşılaştırmada ise iki karakter eşleşip üçüncüsü eşleşmezse iki karşılaştırma boşa yapılmış olur.

### 14.2 Problem ve slayttaki çözüm

Slayttaki problem: kullanıcıdan iki string alan, birinci stringin içinde ikinci stringin geçtiği yeri arayan, bulursa geçtiği yerin bayt konumunu, bulamazsa $-1$ döndüren bir program yazın; işaretçi işlemleri kullanın (ekrandan, 02:05:00). Hoca bunu önce bir alıştırma olarak, string fonksiyonlarını kullanmadan doğrudan dizi işlemleriyle kendilerinin kodlamasını istedi; sonra slayttaki çözümleri inceledi.

<!-- BELİRSİZ: Slayttaki "versiyon 1" ve "versiyon 2" kodları karelerde görünmüyor; aşağıdaki anlatım altyazıdan kuruldu. -->

Versiyon 1 iki stringin uzunluğunu alır. Arama, `len1 - len2` konumuna kadar yapılır: birinci string 10, ikinci 3 karakterse 7. konumdan sonra aramaya gerek yoktur. Her konumda `ptr1`'in gösterdiği karakter `ptr2`'nin gösterdiği karaktere eşit olduğu ve eşleşen karakter sayısı (match count) ikinci stringin uzunluğuna ulaşmadığı sürece döngü devam eder ve sonraki karaktere geçilir. Döngü ya karakterler farklı olunca ya da eşleşme sayısı `len2`'ye ulaşınca biter. Eşleşme sayısı `len2`'ye eşitse o konum döndürülür. Değilse eşleşme sayısı sıfırlanır, `ptr1` bir sonraki başlangıç konumuna, `ptr2` aranan stringin başına alınır.

Versiyon 2 hazır `strstr` fonksiyonunu kullanır. `strstr` birinci stringin içinde ikinciyi arar; bulursa geçtiği yeri gösteren bir işaretçi, bulamazsa `NULL` döndürür. Sonuç `NULL` değilse konum hesaplanır, `NULL` ise $-1$ döndürülür. Slayttaki `main` fonksiyonu iki stringi okuyup versiyon 1'i çağırıyor ve sonuca göre "bulundu" ya da "bulunamadı" yazıyordu. Bu not için yazılan tam çözüm Örnek Sorular bölümündedir.

## 15. Çok boyutlu diziler

### 15.1 Tanım ve erişim

İki boyutlu bir dizi tanımlanırken iç içe iki küme parantezi kullanılır; kümelerin içinde elemanlar virgülle ayrılır. Bir değer yazılıp gerisi boş bırakılırsa diğerleri otomatik olarak sıfır olur; matrisler böyle hızlıca sıfırlanabilir.

Slayttaki açıklama (ekrandan, 02:10:00): `int ar[3][5];` tanımında `ar`, 5 elemanlı dizilerden oluşan 3 elemanlı bir dizidir. `ar[1][2]` ifadesi `*(ar[1]+2)` olarak yorumlanır, bu da `*(*(ar+1)+2)` olarak açılır.

Hoca bunu şöyle anlattı: her satırın bir adresi vardır ve bu adres sütun sayısına göre oluşur. `ar[i]` `i`. satırın adresidir; buna `j` eklemek o satırda `j` eleman ilerleyip ilgili hücreye ulaşmak demektir. `*` kullanılmazsa elde edilen adrestir, kullanılırsa hücredeki değerdir. Daha önce `ar == ar[0]` (ilk satırın adresi) olduğu görülmüştü; `ar + 1` bir sonraki satırın adresini verir. Bu adres değerine 2 eklenince o satırdaki 2. sütuna gidilir; en dıştaki `*` o adresteki değeri verir.

Hoca adresleri sayısal bir örnekle de açıkladı: matris 100 numaralı adresten başlasın. Hoca burada önce elemanları 100, 101, 102 diye saydı, sonra tamsayılarda adımların 4'er bayt olduğunu düşünmek gerektiğini belirtti. Anlattığı durumda `ar + 1` 104'ü verir; bu satır adresine 2 eklenince ilgili hücrenin adresine gidilir ve bu adresteki değer `*` ile alınır.

> **Ders sonrası not:** `int ar[3][5]` dizisinde bir satır 5 tamsayıdan, yani $5 \times 4 = 20$ bayttan oluşur. Bu yüzden `ar` 100 adresindeyse `ar + 1` 104'ü değil 120'yi gösterir; `*(ar+1)+2` ise $120 + 2 \times 4 = 128$ adresidir. Hocanın 104 örneği büyük olasılıkla satır başına tek tamsayı düşen basitleştirilmiş bir anlatımdı.

Hoca indis gösterimlerinin farklı yazılabileceğini, ama en çok `ar[i][j]` gösterimini kullandıklarını söyledi. Üç boyutlu dizi için slaytta `char x[3][4][5];` örneği vardı: `x`, 5 elemanlı dizilerden oluşan 4 elemanlı dizilerden oluşan 3 elemanlı bir dizidir (ekrandan, 02:10:00). Hoca üç boyutlu durumda işaretçi gösteriminin nasıl yazılacağını çalışma sorusu olarak bıraktı (Örnek Sorular).

### 15.2 Çok boyutlu dizilere ilk değer verme

Slayttaki iki örnek (ekrandan, 02:15:00):

```c
int exap[5][3] = {{ 1, 2, 3 },
                  { 4 },
                  { 5, 6, 7 }};

int exap[5][3] = { 1, 2, 3,
                   4,
                   5, 6, 7 };
```

Birinci tanımda iç küme parantezleri satırları belirler. İlk satır 1, 2, 3; ikinci satırda yalnız 4 vardır, kalanı sıfırlanır; üçüncü satır 5, 6, 7'dir; geri kalan satırlar sıfırdır:

```text
1 2 3
4 0 0
5 6 7
0 0 0
0 0 0
```

İkinci tanımda iç parantez yoktur. Hoca bunun bellekte tek bir dizi gibi düşünüldüğünü, değerlerin sırayla kopyalandığını söyledi: 3'ün adresine `sizeof(int)` eklenince bir sonraki göze, yani ikinci satırın başına geçilir. 1'den 7'ye kadar değerler sırayla yerleşir, kalanlar sıfırlanır:

```text
1 2 3
4 5 6
7 0 0
0 0 0
0 0 0
```

Hoca C'de her türden verinin dizisinin oluşturulabildiğini, ileride struct dizilerinin de görüleceğini ekledi.

## 16. İşaretçi dizileri ve işaretçinin işaretçisi

### 16.1 İşaretçi dizileri

İşaretçi de bir tip olduğu için onun da dizisi yapılabilir. Örneğin 5 elemanlı bir işaretçi dizisinin her elemanı ayrı bir yeri gösterir. Slayttaki örnekte bir işaretçi dizisi (pointer 0, pointer 1, pointer 2, ...) ile iki karakter (A ve B) vardı; pointer 0 birinci karakterin, pointer 1 ikinci karakterin adresini gösteriyordu. 50 işaretçi gerekiyorsa normal değişkenlerde olduğu gibi 50'sini ayrı ayrı yazmak yerine bir dizi olarak tanımlanır. Hoca bunun asıl kullanımının dinamik bellek ayırmayla iki boyutlu dizi kurulurken görüleceğini söyledi.

### 16.2 İşaretçinin işaretçisi

Slayttaki örnek (ekrandan, 02:20:00):

```c
int r = 5;      // declares r to be an int
int *q = &r;    // declares q to be a pointer to an int
int **p = &q;   // declares p to be a pointer to a pointer to an int

r = 10;         // Direct assignment
*q = 10;        // Assignment with one indirection
**p = 10;       // Assignment with two indirections
```

Hoca belleği çizerek anlattı: `r` 100 numaralı adreste otursun ve içinde 5 olsun; `q` 200, `p` 300 numaralı adreste olsun. `q = &r` ile `r`'nin adresi olan 100 `q`'ya atanır; `q` birinci dereceden bir işaretçidir. `p = &q` ile `q`'nun adresi olan 200 `p`'ye kopyalanır; `p` ikinci dereceden bir işaretçidir. Birinci dereceden bir işaretçi birinci dereceye, ikinci dereceden bir işaretçi ikinci dereceye atanır. Çapraz atama yapılamaz: `&r` `p`'ye atanamaz, `q` da ikinci dereceden bir değişkene aktarılamaz, çünkü dereceler değişir.

`r = 10;` doğrudan atamadır. `*q = 10;` `q`'nun gösterdiği yere, yani `r`'ye yazar. Neden böyle olduğu `*` ile `&`'nin birbirini götürmesiyle açıklanır: `q = &r` olduğu için `*q = *&r = r`'dir. `**p = 10;` için de aynı mantık iki kez uygulanır:

```text
p   = &q
*p  = *&q = q
**p = *q  = *&r = r
```

Birinci `*` `q`'yu verir, ikinci `*` `q`'nun gösterdiği yeri, yani `r`'yi verir. Hoca anlatırken birkaç kez durup yeniden yazdı; sonuç olarak `**p` doğrudan `r`'ye eşittir.

Üçüncü dereceden işaretçi de olabilir. Hoca genel bir eşleştirme verdi: birinci dereceden işaretçiler genellikle tek boyutlu dizilerle, ikinci dereceden işaretçiler iki boyutlu dizilerle, üçüncü dereceden işaretçiler üç boyutlu dizilerle kullanılır. Bunun asıl uygulaması dinamik bellek ayırmadadır.

> **Hocanın vurgusu:** Üç anahtar kavram bilinmeli: her işaretçi başka bir işaretçide saklanabilir (adresi alınabilir); işaretçiler dizi olarak tutulabilir; işaretçi aritmetiği sayesinde dizinin bütün elemanlarına erişilebilir.

## 17. Dinamik bellek yönetimine giriş: stack ve heap

Hoca bir sonraki konunun dinamik bellek ayırma olduğunu söyleyip kısa bir giriş yaptı. Şimdiye kadar diziler ya statik boyutla tanımlandı ya da "500'lük yer aç, programda `scanf("%d", &n);` ile okunan `n` kadarını kullan (`n < 500`)" denildi. Bu iki yol bellek organizasyonunda farklı şeylere karşılık gelir.

Program çalıştırılabilir hale getirilip çalıştırıldığında bellek farklı bölümlere ayrılır; bu ayrıntı normalde işletim sistemleri dersinin konusudur. Bir bölümde program kodları, bir bölümde ilk değer verilmiş ve verilmemiş değişkenler, ayrıca stack ve heap bölgeleri bulunur. `int b[10]` gibi dinamik olmayan veriler stack'te saklanır ve stack kısıtlıdır (hoca burada "statik"in önceki derslerdeki `static` anahtar sözcüğüyle karıştırılmamasını istedi). Heap ise stack'ten daha büyüktür ve dinamik veriler burada tutulur.

Heap özel izinle kullanılır. Program işletim sistemine "bana 1 milyon uzunluğunda bir yer lazım" der; mümkünse işletim sistemi derleyiciyle birlikte heap bölgesinden belli bir adresten başlayan bir yer verir ve o adres stack'teki bir işaretçiye alınır. Bu işaretçiyle bütün diziye ya da matrise erişilir. Yer özel izinle alındığı için, iş bittiğinde işletim sistemine özel olarak geri verilmesi (serbest bırakılması) gerekir; buna dinamik bellek ayırma denir. Bu değişkenlerin kapsamı ve yaşam süresi daha geniştir: serbest bırakılmazlarsa program kapanana kadar bellekte yer kaplarlar ve bellek sızıntısına (memory leak) yol açarlar.

Hoca bellek sızıntısına örnek olarak bazı web tarayıcılarını verdi: 10 sayfa açılınca bellek, kullanılmasa bile çok hızlı dolar. Bir süre sonra bilgisayar yeniden başlayabilir ya da bellek hatası vermeye başlayabilir. Hoca ödevleri incelerken de belleği serbest bırakmayan kodlarla çok karşılaştığını, bellek aşırı dolunca programların hatalıymış gibi göründüğünü söyledi; bunun heap bölgesinin yanlış kullanımından kaynaklandığını belirtti.

Son olarak değişkenlerin yaşam süresiyle ilgili önemli bir kavrama değindi: bir `f` fonksiyonu içinde `int a` tanımlanıp `return a` denirse, değişken stack'te tanımlandığı için çağrılan yerde asıl değerinin görülememe ihtimali yüksektir; değişken statik ya da heap bölgesinde tanımlanmış olsaydı değeri rahatça görülebilirdi. Ayrıntılara gelecek hafta bakılacak.

> **Ders sonrası not:** Hoca, `return a` ile döndürülen yerel `int a` değişkeninin değerinin görülemeyebileceğini söyledi. Değerle döndürmede değer çağırana kopyalandığı için sorun yoktur. Sorun, yerel değişkenin adresi (`return &a;`) döndürüldüğünde çıkar: fonksiyon bitince o stack alanı geçersiz olur. Hoca büyük olasılıkla adres döndürmeyi kastetti.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:28:38): Bir diziyi sıfırlamanın en kolay yolu nedir?

> **Cevap (derste verildi):** `int a[10] = {0};` yazmak. Başlatıcıda eleman sayısından az değer yazılınca kalan elemanlar 0 olur; tek bir 0 yazmak yeter. `static` kullanmak bunun yolu değildir.

**Soru 2** (ekrandan, 00:35:00): `float ar[5], *p;` tanımı için aşağıdaki atamalardan hangileri geçerlidir? `p = ar;`, `ar = p;`, `&p = ar;`, `ar++;`, `ar[1] = *(p+3);`, `p++;`

> **Cevap (derste verildi):** Geçerli olanlar `p = ar;`, `ar[1] = *(p+3);` ve `p++;`. `ar = p;` ve `ar++;` geçersizdir, çünkü dizi adı değiştirilemeyen bir adres sabitidir. `&p = ar;` geçersizdir, çünkü bir değişkenin adresine atama yapılamaz.

**Soru 3** (derste sözlü, 01:29:40): Stringlerin sonundaki null karakter ne işe yarar?

> **Cevap (derste verildi):** Stringin nerede bittiğini belirler. `printf("%s", ...)` verilen adresten başlayıp `'\0'` görene kadar yazar, `strlen` `'\0'`'a kadar sayar. Bir öğrencinin cevabı olan "uzunluğu bulmak" da bu sayede mümkündür.

**Soru 4** (derste sözlü, 01:58:23): `char *p = "a";` tanımından sonra `p`'ye `"bb"` gibi daha uzun bir string atanabilir mi? Kodda deneyin.

> **Çözüm (derste verilmedi):** Atanabilir. `p = "bb";` ifadesi var olan stringin üzerine yazmaz; `"bb"` sabiti bellekte ayrı bir yere yerleştirilir ve yalnızca onun başlangıç adresi `p`'ye atanır. Bu yüzden yeni stringin uzunluğu önemli değildir. Buna karşılık `*p = "bb";` ya da `p`'nin gösterdiği sabitin karakterlerini değiştirmek (`p[0] = 'b';`) geçersizdir.

**Soru 5** (ekrandan, 02:05:00): Kullanıcıdan iki string alan, birinci stringin içinde ikinci stringin geçtiği ilk yeri arayan, bulursa bayt konumunu, bulamazsa $-1$ döndüren programı işaretçi işlemleriyle yazın.

> **Çözüm (derste verilmedi):** Slaytta bir çözüm gösterildi ama karelerde okunmuyor. Aşağıdaki kod derste anlatılan versiyon 1 (karakter karakter karşılaştırma) ve versiyon 2 (`strstr`) mantığıyla ajan tarafından yazıldı, `gcc -Wall` ile derlendi ve denendi: `yildizteknik` içinde `teknik` için 6, `abcabd` içinde `abd` için 3, `abc` içinde `xyz` için $-1$ döndü.

```c
#include <stdio.h>
#include <string.h>
#define MAX_CHAR 80

/* str2, str1 icinde ilk nerede geciyorsa o konumu, yoksa -1 dondurur */
int pattern_match(char *str1, char *str2){
    int len1 = strlen(str1), len2 = strlen(str2);
    int i, match_count;
    char *ptr1, *ptr2;
    for(i = 0; i <= len1 - len2; i++){
        ptr1 = str1 + i;
        ptr2 = str2;
        match_count = 0;
        while(*ptr1 == *ptr2 && match_count < len2){
            ptr1++;
            ptr2++;
            match_count++;
        }
        if(match_count == len2)
            return i;
    }
    return -1;
}

/* Hazir kutuphane fonksiyonu strstr ile ayni is */
int pattern_match2(char *str1, char *str2){
    char *p = strstr(str1, str2);
    if(p != NULL)
        return p - str1;
    return -1;
}

int main(){
    char str1[MAX_CHAR], str2[MAX_CHAR];
    int pos;
    printf("Birinci string: ");
    scanf("%s", str1);
    printf("Ikinci string: ");
    scanf("%s", str2);
    pos = pattern_match(str1, str2);
    if(pos >= 0)
        printf("Bulundu, konum: %d (strstr: %d)\n", pos, pattern_match2(str1, str2));
    else
        printf("Bulunamadi (%d)\n", pos);
    return 0;
}
```

**Soru 6** (derste sözlü, 02:13:26): Üç boyutlu bir dizide bir elemanın değerini (`%d`) ve adresini (`%p`) işaretçi gösterimiyle yazdırın. İndisle yazdırdığınız sonuç işaretçiyle yazdırdığınızla aynı çıkıyorsa doğru yapmışsınız demektir.

> **Çözüm (derste verilmedi):** `x[i][j][k]` ifadesi `*(*(*(x+i)+j)+k)`'ya, adresi `&x[i][j][k]` de `*(*(x+i)+j)+k`'ya eşittir. Aşağıdaki program ajan tarafından yazıldı, `gcc -Wall` ile derlendi ve çalıştırıldı: `x[1][2][3]` ve `*(*(*(x+1)+2)+3)` 123 çıktı, iki adres de aynıydı, 24 elemanın hiçbirinde uyuşmazlık olmadı.

```c
#include <stdio.h>

int main(){
    int x[2][3][4];
    int i, j, k, hata = 0;
    for(i = 0; i < 2; i++)
        for(j = 0; j < 3; j++)
            for(k = 0; k < 4; k++)
                x[i][j][k] = 100*i + 10*j + k;

    for(i = 0; i < 2; i++)
        for(j = 0; j < 3; j++)
            for(k = 0; k < 4; k++){
                if(x[i][j][k] != *(*(*(x+i)+j)+k) || &x[i][j][k] != *(*(x+i)+j)+k)
                    hata++;
            }
    printf("x[1][2][3] = %d, *(*(*(x+1)+2)+3) = %d\n", x[1][2][3], *(*(*(x+1)+2)+3));
    printf("&x[1][2][3] = %p, *(*(x+1)+2)+3 = %p\n", (void*)&x[1][2][3], (void*)(*(*(x+1)+2)+3));
    printf("Uyusmayan eleman sayisi: %d\n", hata);
    return 0;
}
```

## Dersin Toparlaması

Bu derste işaretçilerin dizilerle ilişkisi baştan sona işlendi. Dizi adının ilk elemanın adresi olduğu, `ar[i]` ile `*(ar+i)`'nin aynı olduğu ve işaretçi aritmetiğinin adrese `i * sizeof(tip)` eklediği hem slaytlarla hem de Dev-C++'ta yazılan bir programla gösterildi. Dizi tanımı, indislerin 0'dan başlaması, sınır denetiminin programcıya ait olması, ilk değer verme kuralları ve `scanf`'te `&` kullanımı sık yapılan hatalarla birlikte ele alındı. Ardından stringlerin `'\0'` ile biten karakter dizileri olduğu, `sizeof` ile `strlen` farkı, işaretçiyle tanımlanan sabit stringlerin değiştirilemeyeceği (hata ayıklayıcıyla gösterilen segmentasyon hatası), string atama kuralları, string fonksiyonları ve örüntü eşleme problemi işlendi. Son bölümde çok boyutlu diziler, `ar[i][j] == *(*(ar+i)+j)` gösterimi, işaretçi dizileri ve işaretçinin işaretçisi anlatıldı.

Hoca gelecek hafta dinamik bellek ayırmanın işleneceğini söyledi. Bu derste girişi yapılan stack ve heap ayrımı, heap'ten alınan belleğin serbest bırakılması ve bellek sızıntısı, işaretçi dizileri ile ikinci dereceden işaretçilerin dinamik iki boyutlu dizilerde nasıl kullanılacağı orada görülecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
