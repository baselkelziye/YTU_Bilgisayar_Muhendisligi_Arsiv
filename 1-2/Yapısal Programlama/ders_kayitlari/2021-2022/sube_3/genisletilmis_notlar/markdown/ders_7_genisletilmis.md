# Ders 7 Genişletilmiş Notu: Dinamik Bellek Yönetimi, Dinamik Dizi ile Sıralama ve Karakter Matrisi Erişimleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. İşaretçinin İşaretçisi
- 2. Bellek Ayırma Fonksiyonları
- 3. Dinamik Dizi Ayırma Şablonu
- 4. Dinamik Matris Ayırma
- 5. Uygulama: Dinamik Dizi ile Sıralama
- 6. Uygulama: İki Boyutlu Karakter Dizilerine Erişim
- Örnek Sorular

## 1. İşaretçinin İşaretçisi

Ders, bir önceki haftanın kaldığı yer olan işaretçi dizileri (array of pointers) konusundan devam eder. Hoca bu konu üzerinde fazla durmayacaklarını, asıl ağırlığın dinamik bellek yönetimine, bellek ayırmaya ve ayrılan alana işaretçi aritmetiğiyle erişmeye verileceğini söyler.

Slaytta işaretçinin işaretçisi şöyle gösterilir (ekrandan, 00:20:00):

```c
int r = 5;      // declares r to be an int
int *q = &r;    // declares q to be a pointer to an int
int **p = &q;   // declares p to be a pointer to a pointer to an int

r = 10;         // Direct assignment
*q = 10;        // Assignment with one indirection
**p = 10;       // Assignment with two indirections
```

İlk iki satır bilinen durumdur: bir tamsayı tanımlanır ve `q` işaretçisi onun adresini tutar. Üçüncü satırda iki yıldız kullanılır; `p`, `q`'nun adresini tutar. Böylece `p` → `q` → `r` zinciri oluşur. `r`'ye doğrudan, bir dolaylamayla (`*q`) ya da iki dolaylamayla (`**p`) değer atanabilir.

Hoca işaretçinin işaretçisine bu aşamada pratikte pek ihtiyaç olmadığını, slaytın da belirttiği gibi tam örneklerin dinamik bellek öğrenildikten sonra daha anlamlı olacağını söyler. Gerçekten de iki boyutlu dinamik alan ayırırken (Bölüm 4) bu tür kullanılır.

## 2. Bellek Ayırma Fonksiyonları

Bu hafta önce bellek ayırmak için kullanılan iki fonksiyon (malloc ve calloc) ve farkları, sonra bir ve iki boyutlu alan ayırma ve bunlarla ilgili örnekler işlenir. Slayttaki fonksiyonlar şunlardır (ekrandan, 00:25:00):

- `void* malloc( total_size_in_bytes )`: Bellekte belirtilen sayıda bayt ayırır. Ayrılan bloğun başını gösteren bir işaretçi döndürür.
- `void* calloc( number_of_elements, element_size )`: malloc'a benzer, ama ayrılan baytları sıfırlar. calloc iki, malloc bir parametre alır; ayrılan toplam alan aynıdır (toplam boyut = n × eleman boyutu).
- `void* realloc( void *prev_ptr, total_size_in_bytes )`: Daha önce ayrılmış `prev_ptr` bloğunun boyunu değiştirir. Fonksiyon bloğu yeni bir yere taşıyabilir (yeni adres fonksiyonun dönüş değeridir). Dinamik olarak büyütülen bir bloğun eklenen kısmının temizlendiği asla varsayılmamalıdır. Önceden ayrılmış belleğin içeriği ise olduğu gibi kalır.
- `void free( void *ptr )`: malloc, calloc ya da realloc ile ayrılmış belleği serbest bırakır.

### 2.1 malloc ve calloc farkı

İki fonksiyon da ayrılan belleğe `void` türünden bir işaretçi döndürür. Hangi türden veri saklanacaksa dönen işaretçi o türün işaretçisine dönüştürülür (cast). Fark parametrelerdedir: malloc'a toplam kaç bayt istendiği verilir; calloc'a ilk parametre olarak eleman sayısı, ikinci parametre olarak eleman boyutu verilir. Örneğin 10 tamsayı için (tamsayı 4 bayt ise) malloc'a 40, calloc'a 10 ve 4 verilir. Hangisi o anda işe daha uygunsa o kullanılır.

Hoca önce başka bir fark hatırlamadığını ve ayrılan belleğin genelde sıfırlanmadığını söyledi. Uygulama sırasında (Bölüm 5.3) calloc'un ayırdığı alanı sıfırladığı görüldü ve slaytta da bunun yazdığı fark edildi.

> **Ders sonrası not:** Ayrılan belleği sıfırlamayan malloc'tur; calloc ayırdığı baytları sıfırlar. Slayttaki "initializes the allocated bytes to zero" ifadesi calloc için geçerlidir.

### 2.2 realloc ve bir benzetme

Hoca realloc'u bir ders kaydı örneğiyle anlattı. Bir ders 100 kişilik gruplara bölünmüş olsun; 101. kişi geldiğinde yeni grup açılır. Diyelim ki iki grup açılmış ve dolmuş, sonradan 4 öğrenci daha geldi. Yeni bir grup oluşturmak için iki gruptan öğrenci koparmak mantıklı değildir; o kadar hoca olmayabilir, gruplar derse başlamıştır. Mantıklı olan yeni gelen 4 öğrenciyi ikişer ikişer mevcut iki gruba dağıtmaktır. Bu öğrencilerin bilgileri için de yer gerekir. İşte bu durumda realloc'a ilk parametre olarak önceki alanı gösteren işaretçi, ikinci parametre olarak yeni toplam boyut (100 yerine 102 kayıtlık alan) verilir.

Eski alanın hemen arkasında yeterli boş yer olmayabilir. Bu durumda blok bütünüyle başka bir başlangıç adresine taşınabilir. Eski bilgiler silinmez, aynen kopyalanır; ama adres değişebilir. Bellek bloğunun başlangıç adresini başka bir değişkende sakladıysanız onu güncellemeyi unutmamalısınız.

> **Ders sonrası not:** Hoca bloğun taşınmasına "derleyicinin karar verebileceğini" söyledi; bu karar çalışma anında bellek yöneticisi tarafından verilir. Ayrıca `prev_ptr` değişkeninin kendisi değişmez; yeni adres realloc'un dönüş değeridir, bu yüzden dönüş değeri bir işaretçiye atanmalıdır.

### 2.3 free'nin önemi

Ayrılan alan iş bitince mutlaka boşaltılmalıdır. C gibi dillerde bellek yönetimi programcının elindedir; boşaltılmayan bellek işgal edilmiş olarak kalır.

> **Hocanın vurgusu:** Program bittiğinde işletim sisteminin o bellek alanını boşaltacağına hiç güvenmeyin. Farklı sistemlerin bellek yöneticileri farklı çalışabilir; aynı işletim sistemine gelen bir güncelleme bile bunu değiştirebilir. Ayırdığınız ve kullandığınız belleği iş bittikten sonra `free` etmeyi unutmayın.

## 3. Dinamik Dizi Ayırma Şablonu

Slayttaki dizi ayırma örneği (ekrandan, 00:30:00):

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
free(list)
```

`n` eleman sayısıdır ve tamsayıdır. Liste başını gösteren işaretçi `int *` olduğu için elemanlar da tamsayıdır. malloc kullanılırsa toplam bayt `n * sizeof(int)` olarak verilir.

> **Hocanın vurgusu:** `sizeof(int)` yerine doğrudan `4` yazmayın. Biraz fazla tuşa basılır ama C zaten taşınabilirliği çok yüksek bir dil değildir; `int`'in farklı uzunlukta olduğu platformlarda sorun çıkmaz. Ayrıca sabit rakamlar başka anlamlarla karışır: öğrencinin dört dersi, dört sınavı ve int'in 4 baytı aynı kodda olursa, ders sayısı değiştiğinde hangi `4`'ün neyi ifade ettiğini bütün kodda aramak gerekir.

malloc yerine calloc kullanılırsa ilk parametre eleman sayısı, ikinci parametre `sizeof(int)` olur.

Bellek istenir ama verilmeyebilir. Ders örneklerinde bilgisayarlarda yeterli bellek olduğu için bu durumla karşılaşılmaz; yine de kod belleği kısıtlı platformlarda çalışabilir. Bu yüzden dönen işaretçinin `NULL` olup olmadığı mutlaka denetlenmelidir. `__FILE__` ve `__LINE__` makrolarını kullanmak zorunlu değildir; "yeterli bellek yok" gibi sabit bir mesaj verip fonksiyondan `return -1` ile ya da main'den çıkış koduyla dönmek yeterlidir. İş tamamen bitince `free` fonksiyonuna alanın başlangıcını gösteren işaretçi verilir.

### 3.1 Gizli ayrıntı: işaretçiyi başa döndürmek

Bellek kullanılırken `list` işaretçisi `++` ya da `--` ile ileri geri oynatıldıysa, `free` yapmadan önce tekrar ilk noktaya getirilmelidir. Bunun için iki yol söylendi:

- Baştan ikinci bir işaretçi (ör. `listHead`) oluşturup `listHead = list;` demek, işlemleri `list` üzerinden yapmak ve sonunda `free(listHead)` çağırmak.
- Bütün ileri geri hareketleri bir sayaçta tutup sonunda `list` işaretçisini o kadar geri alarak başa getirmek.

> **Hocanın vurgusu:** Dinamik bellekle ilgili ne sorulursa sorulsun, aradaki iş ne kadar basit ya da karmaşık olursa olsun bu şablon kullanılmalıdır: belleği düzgün ayırmak, `NULL` olup olmadığını denetlemek, ayrılamadıysa hata mesajı verip çıkmak ve sonunda belleği düzgünce serbest bırakmak. Bunlar sınavlarda önemli not bileşenleri olacaktır.

## 4. Dinamik Matris Ayırma

Matrisin satır ve sütun olmak üzere iki boyutu vardır. Bu yüzden işaretçi iki yıldızla (`int **mat`) tanımlanır. Slayttaki kod (ekrandan, 00:40:00):

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

Hoca satır ve sütun için `n` ve `m` yerine aslında `rows` ve `cols` gibi adları tercih ettiğini söyledi. Yapılması gereken iki adımdır: önce satır sayısı kadar satır işaretçisi tutabilecek alan ayırmak, sonra her satır için ayrı ayrı sütun sayısı kadar eleman ayırmak.

### 4.1 Excel ile gösterim

Hoca yapıyı Excel'de 3 satır, 5 sütunluk bir tabloyla anlattı (ekrandan, 00:35:00). Tabloda satırlar `[0]`, `[1]`, `[2]`, sütunlar `[0]`'dan `[4]`'e kadar numaralandı.

- `**mat` ilk gözü gösteriyor gibi düşünülse de arka planda her satırın başında bir satır işaretçisi vardır.
- `mat[0]` (ya da `*(mat+0)`) ilk satırı, `mat[1]` ikinci satırı, `mat[2]` üçüncü satırı gösteren işaretçidir.
- `mat[0][0]` gözü `*(*(mat+0)+0)` biçiminde de yazılabilir; `mat[0][1]` için `*(*(mat+0)+1)`, `mat[1][2]` için `*(*(mat+1)+2)` yazılabilir. Normal iki boyutlu bir dizinin başına işaretçi konduğunda yapılabilen işlemler burada da yapılabilir.

<!-- BELİRSİZ: Excel gösteriminde hocanın gözlere yazdığı ifadeler altyazıda bozuk ("Mat 0, 6, 0" gibi); yukarıdaki yazımlar anlatımdan ve slayttaki kalıptan kuruldu. -->

Bu yapı yüzünden yalnızca satır × sütun kadar yer ayırmak yetmez; önce satır sayısı kadar işaretçilik yer, sonra her satır için ayrı yer ayrılır. İlk ayırma `n * sizeof(int *)` kadardır, yani tek boyutlu bir işaretçi dizisi ayırmaya benzer. Sonra döngü içinde her satıra `m` tamsayılık yer ayrılır.

Slaytta döngü içindeki ayırmalar ayrıca `NULL` diye denetlenmemiştir. Hoca, ilk ayırma başarılı olduysa sonrakilerin de büyük olasılıkla başarılı olacağını, bu yüzden bunu ayrıca denetlemenin zorunlu olmadığını, ama ilk denetimin mutlaka yapılması gerektiğini söyledi.

### 4.2 Boşaltma sırası

Ayırırken önce satır işaretçileri, sonra her satır ayrılmıştı. Boşaltırken ters simetriyle önce her satır ayrı ayrı, sonra satır işaretçilerini tutan ana alan boşaltılır.

> **Hocanın vurgusu:** Her malloc'a karşılık gelen bir free olmalıdır. İç içe süslü parantezlerde en son açılan parantez ilk kapanır; malloc ve free için de aynı simetri geçerlidir.

### 4.3 Soru-cevap: free'den sonra veri neden duruyor?

**Soru:** `free` yaptıktan sonra diziyi tekrar yazdırdım; başta biraz bozulma olsa da çoğu değer aynı çıktı. `free` yapıldığını test etmenin bir yolu var mı?

**Cevap:** `free` denince o alan "artık kullanılabilir" diye işaretlenir. Aynı programdaki başka malloc işlemleri ya da işletim sisteminin çalıştırdığı başka bir süreç bellek istediğinde o alan ona verilebilir. Ama `free` bloklardaki içeriği tek tek sıfırlamakla uğraşmaz; bunu alanı sonra kullanacak olana bırakır. Bu, dizinin olmayan bir elemanına ya da ayrılan alanın ötesine gidildiğinde rastgele değerlerle karşılaşılmasıyla aynı durumdur. Bu yüzden kod yazarken bellekteki mevcut duruma güvenilmemeli, her alana gerektiği gibi ilk değer verilmelidir. Hoca sayaç değişkenlerinde bile `sayac = 0` yazılmasını önerir: kümülatif toplamda ilk değer 0, kümülatif çarpımda 1 olmalıdır ve bunu açıkça yazmak hatayı önler.

## 5. Uygulama: Dinamik Dizi ile Sıralama

Slayttaki örnekler şunlardır (ekrandan, 00:45:00):

- Basit bir sıralama programı: dizideki eleman sayısını sor, gerekli yeri ayır, elemanları iste, diziyi sırala.
- Matris çarpımı programı: matrislerin boyutlarını sor, çarpılabilir olup olmadıklarını denetle, gerekli yeri ayır, elemanları iste, çarpımı yap, sonuç matrisini yaz. Bu örnek evde yapılacak alıştırma olarak bırakıldı (çözüm: Örnek Sorular).

Sıralama örneğinde önceki haftalarda dizilerle yapılan Selection Sort ve Bubble Sort bu kez dinamik bellekle yazılır. Kod Dev-C++'ta derste birlikte yazıldı. Amaç kodu modüler tutmaktır: diziyi yazdırma, en küçük elemanı bulma, sıralama ayrı fonksiyonlarda olur.

> **Hocanın vurgusu:** Bu sürümün en önemli farkı global değişken kullanılmamasıdır. Elemanlar için yer main fonksiyonunda ayrılır ve bütün yardımcı fonksiyonlara ayrılan alanın başlangıcını gösteren işaretçi gönderilir.

### 5.1 Yer ayırma ve eleman okuma

Kullanıcıdan bilgi almak için ayrı fonksiyon yazılmaz; malloc main'de yapıldığı için onunla ilgili işler de main'de kalır. Tek bir dizi işlendiği için girişi ayrı fonksiyona çekmeye gerek görülmedi; birden fazla dizi olsaydı çekilebilirdi. main'in ilk hali (ekrandan, 01:10:00 ve 01:20:00):

```c
int i, n;
int *p;
printf("Kac eleman girmek istiyorsunuz? "); scanf("%d",&n);
p = (int*) malloc( n * sizeof(int) );
if(p==NULL) {
    printf("Bellekte yer ayrilamadi. Program sonlanacak."); return(1);
}
for( i=0; i<n; i++ ) {
    printf("%d. elemani girin: ", (i+1)); scanf("%d",p[i]);
}
printList( p, n );
```

Kullanıcıya elemanlar 1'den başlayarak sorulur (`i+1`), kod içinde ise sayım 0'dan başlar.

Hoca burada artık normal bir değişkene değil, işaretçinin gösterdiği alana değer girildiğini vurguladı. Önce `p+i` biçimini (parantezli ve parantezsiz) denedi; ikisi de düzgün çalıştı, yani `scanf("%d", p+i)` için parantez gerekmiyor. Sonra köşeli parantezli `scanf("%d", p[i])` biçimini denedi; program eleman girişinde takıldı. Hoca önce dizi gösterimine çok alışılmaması, işaretçide işaretçi aritmetiği kullanılması gerektiğini söyledi. Ardından bir öğrencinin hatırlatmasıyla başa `&` konarak `scanf("%d",&p[i])` yazıldı ve düzgün çalıştı (ekrandan, 01:30:00).

> **Ders sonrası not:** `p[i]` ile `*(p+i)` tamamen eşdeğerdir; sorun köşeli parantez gösteriminde değil, scanf'e adres yerine değer verilmesindedir. scanf her zaman adres bekler: `p+i` ile `&p[i]` aynı adrestir. `scanf("%d", p[i])` tanımsız davranıştır; `gcc -Wall` bu satır için format uyarısı verir.

### 5.2 printList fonksiyonu

Diziyi birden fazla kez yazdırmak gerekir (özellikle sıralama adımlarında ara durumları göstermek için), bu yüzden kendi fonksiyonuna çekilir. Elemanlar tamsayı olduğu için fonksiyon herhangi türden bir listeyi değil, `int` listesini yazar; parametre `int *list` olur.

İşaretçi yalnızca başlangıç adresini taşır; kaç eleman ileri gidileceği bilgisi işaretçide yoktur. Bu yüzden eleman sayısı ikinci parametre olarak mutlaka verilir. Main'de `n` eleman ayrıldığı için fonksiyonda da eleman sayısı için yaygın olan `n` adı kullanıldı. Ekrandaki son hali (ekrandan, 01:25:00):

```c
void printList( int *list, int n ) {
    int i;
    printf("\n");
    for( i=0; i<n; i++ )
        printf("%d ", *(list+i));
}
```

Başta yazdırılan `\n` her yazdırmanın yeni satırdan başlamasını sağlar. Değer yazdırmak gerektiği için `*(list+i)` biçiminde yıldız konması zorunludur; yıldız konmazsa gözlerin adresleri yazdırılır. `list[i]` da kullanılabilir.

Fonksiyon çağrılırken ilk parametreye `p`, ikinciye `n` verilir. `*p` vermek bu aşamada yanlıştır: fonksiyon bir işaretçi beklemektedir. 4 eleman (2, 4, 6, 8) girilerek elemanların doğru okunduğu görüldü.

### 5.3 malloc ve calloc denemesi

Elemanlar girilmeden önce (ama `NULL` denetiminden sonra) bir kez daha `printList` çağrıldı. malloc ile ayrılan alanda ne olduğu yazdırıldı; ardından aynı deneme `calloc(n, sizeof(int))` ile yapıldığında bütün elemanların 0 olduğu görüldü. Hoca slayttaki "initializes the allocated bytes to zero" ifadesini okuyarak bu farkı not ettirdi. İlk değerlerin hepsi kullanıcıdan alınacağı için burada calloc kullanmanın özel bir gereği yoktur.

<!-- BELİRSİZ: malloc denemesinde ekranda görülen değerler altyazıdan okunamadı. -->

### 5.4 bubbleSort

Parametre listesi `printList` ile aynıdır: sıralanacak liste ve eleman sayısı. Ekrandaki son hali (ekrandan, 01:35:00):

```c
void bubbleSort( int *list, int n ) {
    int i,j,tmp;
    for( i=0; i<n-1; i++ ) {
        for( j=i+1; j<n; j++ ) {
            if( list[i] > list[j] ) {
                tmp = *(list+i);
                *(list+i) = *(list+j);
                *(list+j) = tmp;
            }
        }
    }
}
```

Karşılaştırma önce yıldız gösterimiyle (`*(list+i) > *(list+j)`) yazıldı, sonra köşeli parantez gösterimine çevrildi; ikisi aynı sonucu verir. Hoca burada da işaretçinin uzunluk bilgisi taşımadığını hatırlattı. Tek istisna null karakterle sonlandırılmış karakter dizileridir; orada null karakter görülene kadar ilerlenebilir.

İlk denemede çıktı sıralanmamış göründü; sebep `bubbleSort` fonksiyonunun main'de çağrılmamış olmasıydı. Main'e şu satırlar eklendi (ekrandan, 01:30:00):

```c
printf("Girilen liste:"); printList( p, n );
bubbleSort( p, n );
printf("\nSirali liste:"); printList( p, n );
```

Denemede girilen 7 eleman (54, 23, 87, 11, 22, 33, 34) doğru sıralandı.

> **Hocanın vurgusu:** Fonksiyona liste gönderirken işaretçinin adı doğrudan yazılır; başına yıldız konursa hata olur, ampersand konursa o da hata olur. Fonksiyon tanımında parametre `tür *ad` biçiminde yazılır. Kaç elemanlık veri gönderildiği de mutlaka ikinci parametre olarak verilir. Fonksiyon içinde elemanlara ister yıldız ister köşeli parantez gösterimiyle erişilebilir.

### 5.5 getPosOfMin ve selectionSort

Selection Sort'ta iki iş vardır: en küçük elemanı bulmak ve yer değiştirmek. En küçük elemanı bulan fonksiyon, en küçüğü gösteren bir işaretçi yerine onun indisini döndürür; liste başı artı indisle elemana zaten ulaşılabilir. Fonksiyonun imzası için iki seçenek konuşuldu: aramanın başlayacağı konumu gösteren işaretçiyi vermek ya da her zaman listenin başını, eleman sayısını ve aramanın başlayacağı konumu vermek. İkincisi seçildi. Diğer fonksiyonlarda olduğu gibi ilk iki parametre başlangıç adresi ve eleman sayısıdır, üçüncüsü başlangıç konumudur.

Fonksiyon ilk baktığı elemanı (`pos`) en küçük kabul eder, sonrakilere bakar, daha küçüğü bulursa `pos`'u günceller. Derste ilk yazımda fonksiyon içinde `pos` adıyla ikinci bir değişken tanımlanınca derleyici "declaration of 'pos' shadows a parameter" uyarısı verdi (ekrandan, 01:40:00). Parametre zaten başlangıç konumudur, ayrıca tanımlamaya gerek yoktur. Bir de döngü sınırı ilk yazımda `i<n-1` idi:

```c
for( i=pos+1; i<n-1; i++ ) {
```

Denemede son iki eleman karşılaştırılmadı; hoca bunu "off by one" hatası olarak adlandırdı ve sınırı `i<n` yaparak düzeltti. Düzeltilmiş hali (ekrandan, 01:50:00):

```c
int getPosOfMin( int *list, int n, int pos ) {
    int i;
    for( i=pos+1; i<n; i++ ) {
        if( *(list+i) < *(list+pos) ) {
            pos = i;
        }
    }
    return pos;
}
void selectionSort( int *list, int n ) {
    int i, minPos, tmp;
    for( i=0; i<n-1; i++ ) {
        minPos = getPosOfMin( list, n, i );
        tmp = *(list+i);
        *(list+i) = *(list+minPos);
        *(list+minPos) = tmp;
    }
}
```

Dış döngü `n-1`'e kadar gider; son kalan iki elemandan küçüğü yerine konunca son eleman zaten yerindedir.

> **Ek bilgi (derste anlatılmadı):** `i<n-1` sınırının etkisini görmek için hatalı sürüm scratchpad'de denendi: 4, 3, 2, 1 girildiğinde sonuç `2 3 4 1` çıkar, çünkü son eleman hiçbir zaman en küçük aday olarak incelenmez.

### 5.6 Dizi sürümüyle karşılaştırma

Hoca önceki haftalarda yazılan dizi sürümlerini (WordPad'de açılan `sortBu2.c` ve `sortSe2.c`) açarak karşılaştırma yaptı (ekrandan, 01:45:00). Eski sürümde dizi global olarak `int arr[ARR_SIZE];` biçiminde tanımlıydı, `enterArray()` ve `printArray()` hiç parametre almıyordu; eleman sayısı sabitti, bu sayıdan az eleman girilebilir ama fazlası girilemezdi.

- Bubble Sort ve Selection Sort ikisi de $O(n^2)$ karmaşıklıktadır; Selection Sort daha az yer değiştirme yaptığı için biraz avantajlıdır, ama fark ihmal edilebilir düzeydedir.
- Yeni `printList` fonksiyonunun eski `printArray`'den tek farkı parametre almasıdır.
- Tek tek fonksiyonlarda mantık ve yer değiştirme aynıdır. Asıl kazanç program yapısındadır: global değişken kullanılmadı ve dinamik bellek yönetimi kullanıldı.

Önceki sürümlerde sıralamanın her adımından sonra dizinin ara hali yazdırılıyordu. Bunu yeni sürümde yapmak için `printList` sıralama fonksiyonlarından içeriden çağrılabilir. Ancak bunun için `printList` ya onlardan önce tanımlanmalı ya da dosyanın başına prototipi (hocanın deyişiyle "allusion") konmalıdır. Hoca prototipi en başa koydu (ekrandan, 01:50:00): `void printList( int *list, int n );`. `selectionSort` kendisine gelen `list` ve `n` parametrelerini `printList`'e aktarır; `printList`'in başındaki `\n` sayesinde ek bir satır sonu yazmaya gerek kalmaz. Çıktıda ilk adımda en küçük eleman (11) baştaki 33 ile yer değiştirdi; zaten yerinde olan elemanlar için de yer değiştirme yapıldı. Hoca "zaten yerindeyse yer değiştirme" denetimi eklenebileceğini, ara durumların normalde gösterilmesine gerek olmadığını ama koşullu hata ayıklama (conditional debug) ile gösterilebileceğini söyledi.

### 5.7 swap fonksiyonu

Son olarak yer değiştirme işlemi fonksiyona çekildi. İki elemanın yerini değiştirmek için, sıralama ister dizi ister dinamik bellek üzerinde yapılsın, mutlaka işaretçi vermek gerekir. Elemanlar tamsayı olduğu için parametreler `int *p` ve `int *q`'dur (ekrandan, 01:50:00):

```c
void swap( int *p, int *q ) {
    int tmp = *p;
    *p = *q;
    *q = tmp;
}
```

<!-- BELİRSİZ: swap gövdesinin yalnız ilk satırı karede yazılırken görülüyor; diğer iki satır altyazıdaki anlatımdan kuruldu. -->

`selectionSort` içindeki üç satırlık yer değiştirme yorum satırı yapıldı ve yerine `swap( list+i, list+minPos );` yazıldı. Burada konum (indis) değil işaretçi verilir; başına yıldız konmaz, çünkü değer değil adres gönderilmelidir ki fonksiyon o adreslerdeki içerikleri değiştirebilsin. Bu, main'den `selectionSort` çağrılırken `*p` değil `p` yazılmasıyla aynı mantıktır. 1'den 7'ye kadar girilen elemanlarla deneme doğru sonuç verdi. Hoca aynı fonksiyonun dizilerle de çalıştığını söyledi.

Derste parça parça yazılan kod, son haline getirilip birleştirildi ve `gcc -Wall` ile uyarısız derlendi. 54, 23, 87, 11, 22, 33, 34 girdisiyle hem bubbleSort hem selectionSort `11 22 23 33 34 54 87` sonucunu verdi. Birleştirilmiş program (`stdlib.h` ve `free(p)` derste ekranda görülmedi, eklendi):

```c
#include <stdio.h>
#include <stdlib.h>
void printList( int *list, int n );
void swap( int *p, int *q ) {
    int tmp = *p;
    *p = *q;
    *q = tmp;
}
int getPosOfMin( int *list, int n, int pos ) {
    int i;
    for( i=pos+1; i<n; i++ ) {
        if( *(list+i) < *(list+pos) ) {
            pos = i;
        }
    }
    return pos;
}
void selectionSort( int *list, int n ) {
    int i, minPos;
    for( i=0; i<n-1; i++ ) {
        minPos = getPosOfMin( list, n, i );
        swap( list+i, list+minPos );
        printList( list, n );
    }
}
void printList( int *list, int n ) {
    int i;
    printf("\n");
    for( i=0; i<n; i++ )
        printf("%d ", *(list+i));
}
void bubbleSort( int *list, int n ) {
    int i,j,tmp;
    for( i=0; i<n-1; i++ ) {
        for( j=i+1; j<n; j++ ) {
            if( list[i] > list[j] ) {
                tmp = *(list+i);
                *(list+i) = *(list+j);
                *(list+j) = tmp;
            }
        }
    }
}
int main(int argc, char *argv[])
{
    int i, n;
    int *p;
    printf("Kac eleman girmek istiyorsunuz? "); scanf("%d",&n);
    p = (int*) malloc( n * sizeof(int) );
    if(p==NULL) {
        printf("Bellekte yer ayrilamadi. Program sonlanacak."); return(1);
    }
    for( i=0; i<n; i++ ) {
        printf("%d. elemani girin: ", (i+1)); scanf("%d",&p[i]);
    }
    printf("Girilen liste:"); printList( p, n );
    selectionSort( p, n );
    printf("\nSirali liste:"); printList( p, n );
    free(p);
    return 0;
}
```

## 6. Uygulama: İki Boyutlu Karakter Dizilerine Erişim

Dersin son bölümünde iki boyutlu karakter dizileri (metin matrisi) üzerinde işaretçi işlemleri incelendi. Hoca sayısal matris çarpımını alıştırma olarak bıraktığını, daha karmaşık ve "hileli" olabilecek karakter matrisi işlemlerini birlikte yapacaklarını söyledi. Amaç satır ve sütunları olan bir metinde herhangi bir konuma nasıl ulaşıldığını, hangi yazımların çalışıp hangilerinin çalışmadığını göstermektir. Hoca kodu hazır olarak getirmişti.

### 6.1 Tanımlar

Ekrandaki kodun başı (ekrandan, 02:10:00 ve 02:15:00):

```c
#define USED_ROWS 3
#define USED_COLS 6

int main(int argc, char *argv[])
{
    int i, j;
    char **text = (char**) calloc( ROWS, sizeof(char*) );
    char *mat[ROWS] = {"012345\n","6789AB\n","CDEFGH\n"};
    char *bp, *mp; /* same as char *bp; char *mp;
     Notice where * is aligned, *mp does not become **mp. */
    if( text == NULL ) {
        printf("Can not allocate memory for the text"); return -1;
    }
    for( i=0; i < ROWS; i++ )
        text[i] = (char*) calloc( COLS, sizeof(char) );

    strcpy(text[0], "012345\n");
    strcpy(text[1], "6789AB\n");
    strcpy(text[2], "CDEFGH\n");
    for(i = 0; i < ROWS; i++)
        printf("%s",text[i]);
    system("pause");
```

<!-- BELİRSİZ: ROWS ve COLS makrolarının değeri karelerde görülmedi (dosyanın üst kısmı ekrana gelmedi). Hoca matrisin üç satırlık, altı ya da daha fazla sütunluk olduğunu söyledi; COLS en az 8 olmalıdır ("6789AB\n" ve sonlandırıcı null için). -->

Kodda iki yapı yan yana kullanılır:

- `text`: çift işaretçidir (`char **`). Önce satır işaretçileri için calloc ile yer ayrılır, ayrılamazsa çıkılır; sonra her satır için ayrıca yer ayrılır ve metinler `strcpy` ile kopyalanır. Hem bellek ayırma hem içeriğin değiştirilebilmesi bakımından tamamen dinamiktir; herhangi bir satır ve sütundaki içerik değiştirilebilir. calloc seçilmesinin sebebi içeriğin rastgele harfler yerine sıfırlarla dolu olmasıdır.
- `mat`: işaretçi dizisidir (array of pointers), tanımlandığı anda ilk değerlerini alır. Dersin başında hızlı geçilen işaretçi dizilerine örnek olsun diye konmuştur. Değer atama biçiminde yazıldığı için gösterdiği metinler sabittir; içlerinden bir karakter değiştirilmeye çalışılırsa ya hiçbir şey olmaz ya da program takılır (önceki haftalarda görülmüştü).

Satırlar bilerek `012345`, `6789AB`, `CDEFGH` diye seçilmiştir; böylece bir çıktı görüldüğünde hangi satır ve sütundan geldiği kolayca anlaşılır.

`char *bp, *mp;` satırında yıldız tür adına değil değişken adına bitişik yazılmıştır. Tür adı (`char`) iki değişkene ortak paranteze alınmış gibi dağılır: `char *bp; char *mp;` olur, `*mp` `**mp`'ye dönüşmez. Bu iki işaretçi birer karakteri gösteren sıradan işaretçilerdir; istenirse `text`'in ya da `mat`'ın bir satırını gösterecek şekilde ayarlanabilir.

Hoca ilk çalıştırmada sonda `free(mat)` denemesini de yaptı: hata çıkmadı. malloc ile yer ayrılmadığı için `mat`'ı boşaltmaya gerek yoktur; `text` ise mutlaka boşaltılmalıdır. Kodun sonu (ekrandan, 02:50:00):

```c
for(i = 0; i < ROWS; i++) {
    free(text[i]); //free(mat[i]);
}
free(text); //free(mat);
```

> **Ders sonrası not:** `mat[i]` dize sabitlerini gösterir; `free(mat[i])` çağrısı tanımsız davranıştır ve çoğu sistemde programı çökertir. `free` yalnız malloc, calloc ya da realloc'tan dönen adreslere uygulanmalıdır. Derste denenen `free(mat)` de büyük olasılıkla yalnız o anda tesadüfen sorun çıkarmamıştır.

> **Hocanın vurgusu:** Bu örneklere sınavlardan önce mutlaka çalışın.

### 6.2 Çıktılar

Erişimler ardışık printf satırlarıyla denenir. Her satırda dikkat edilmesi gerekenler: format dizgisinde `%s` mi `%c` mi kullanıldığı ve parametrenin başında yıldız, `&`, köşeli parantez, artı ya da normal parantez olup olmadığı. Hoca her satırın çıktısını önce Not Defteri'ne tahmin olarak yazdı, sonra çalıştırıp karşılaştırdı. Satırların son hali (ekrandan, 02:45:00 ve 02:50:00):

```c
bp = text[0]; mp = text[1];  j = 1;
printf("Output %d:%s", j, mp); j++;
printf("Output %d:%s", j, mp+1); j++;
printf("Output %d:%s", j, mp+2); j++;
//printf("Output %d:%s\n", j, text ); j++; //buggy
printf("Output %d:%s", j, *text ); j++; // **text:crash
printf("Output %d:%c\n", j, text ); j++; //buggy
printf("Output %d:%c\n", j, *bp); j++; //(#6) %c & *bp: OK
printf("Output %d:%c\n", j, bp); j++; //(#7)%c & bp: buggy
printf("Output %d:%c\n", j, *(bp+2) ); j++; //(#8)
printf("Output %d:%c\n", j, *text ); j++; //(#9)buggy
printf("Output%d:%c\n", j, **text ); j++; //(#10)
printf("Output%d:%c\n", j, *(*(text+1)+2) ); j++; //(#11)
printf("Output%d:%c\n", j, *((text[1])+3) ); j++; //(#12) +3:OK [3]:error
printf("Output%d:%c\n", j, *(*(mat+1))+3 ); j++; //+3:OK [3]:error
printf("Output%d:%c\n", j, *(*(mat+1)+2) ); j++;
printf("Output%d:%d\n", j, mat[2][4]-mat[1][4] ); j++;
```

Çıktıların açıklaması:

- **Output 1 (`%s`, `mp`):** `mp` ikinci satırın başını gösterir. `%s` olduğu için satır string olarak yazılır: `6789AB`. Metnin sonunda `\n` olduğu için ayrıca satır sonu konmamıştır.
- **Output 2 (`%s`, `mp+1`):** Burada soru şudur: `+1` bir sonraki satıra mı gider, bir sonraki karaktere mi? `mp` bir `char *` olduğu için `+1` bir karakter ileri gider; çıktı `789AB`'dir. Sonraki satıra geçmek için yıldızlı ve parantezli başka gösterimler gerekir.
- **Output 3 (`%s`, `mp+2`):** Aynı mantıkla `89AB`.
- **`%s` ile `text`:** Hatalıdır (buggy). `text` iki boyutlu yapının satır işaretçileri dizisini gösterir; `%s` bir satır sonuna kadar gidebilir ama sonraki satıra geçemez. Bütün matris tek bir printf ile yazdırılamaz; tek doğru yol her satırı döngüde ayrı yazdırmaktır. Bu satır yorum satırı yapıldı.
- **Output 4 (`%s`, `*text`):** Hoca önce bunu da hatalı diye işaretlemişti, ama düzgün çalıştı: tek yıldız `text[0]`'ı, yani işaretçi dizisinin ilk elemanını verir; çıktı `012345`'tir. Kodu hazırlarken kopyala-yapıştır hatası yapıldığı anlaşıldı. `%s` ile `**text` ise programı anında çökertir; bu da denenip görüldü.
- **Output 5 (`%c`, `text`):** Hatalı. `text` bir adrestir; adresler genelde büyük sayılardır ve bir karaktere karşılık gelmez. Program çökmez ama anlamsız bir karakter basar; her çalıştırmada ve her bilgisayarda farklı olabilir.
- **Output 6 (`%c`, `*bp`):** `bp` ilk satırın başını gösterir. Tek karakter yazdırılacağı için adres değil değer verilmelidir: `*bp`. Çıktı `0`.
- **Output 7 (`%c`, `bp`):** Hatalı; yine adres verilmiştir, anlamsız bir karakter çıkar.
- **Output 8 (`%c`, `*(bp+2)`):** Parantez içinde başka yıldız olmadığı için iki karakter ileri gidilir: 0, 1, 2. Çıktı `2`.
- **Output 9 (`%c`, `*text`):** Hatalı. `*text` ilk satırın başlangıç adresidir. Output 7 ile aynı anlamsız karakteri verdi; bu tesadüf değildir, çünkü `bp` de `text[0]`'ı gösterir.
- **Output 10 (`%c`, `**text`):** İlk başlangıç noktasındaki içerik tek karakter olarak yazılır: `0`.
- **Output 11 (`%c`, `*(*(text+1)+2)`):** Hoca içeriden dışarıya, derleyici gibi düşünerek değerlendirdi. İlk tahmini `3` idi, çıktı `8` oldu. Doğru okuma şudur: `text+1` ikinci satır işaretçisinin adresidir; başına yıldız konunca (`*(text+1)`) ikinci satıra (`6789AB`) gidilir; `+2` bu satırda iki karakter ilerletir; dıştaki yıldız değeri alır: `8`. Parantez açıp başına yıldız koydukça yapılan artırmalar satır ve sütun gibi işlenir.
- **Output 12 (`%c`, `*((text[1])+3)`):** `text[1]` ikinci satırdır, `+3` dördüncü karakter: 6, 7, 8, 9 → `9`. `text[3]` yazılırsa (olmayan dördüncü satır) çalışma anında hata verip çöktüğü görüldü. `*text[1][3]` biçimi ise derlenmez: "invalid type argument of 'unary *'" hatası alındı (ekrandan, 02:50:00), çünkü `text[1][3]` zaten bir karakterdir, başına yıldız konamaz.
- **Output 13 (`%c`, `*(*(mat+1))+3`):** Hoca bunu `mat+1` ile `6789AB` satırına gidip üç ileri gitmek olarak yorumladı; çıktı `9`.
- **Output 14 (`%c`, `*(*(mat+1)+2)`):** İkinci satırın üçüncü karakteri: `8`.
- **Output 15 (`%d`, `mat[2][4]-mat[1][4]`):** `mat[2]` üçüncü satır (`CDEFGH`), 4 indisli karakter `G`; `mat[1]` ikinci satır (`6789AB`), 4 indisli karakter `A`. Karakterler arka planda sayısal kodlardır; `G` ile `A` arasında 6 harf farkı vardır. Format `%d` olduğu için çıktı sayısal `6`'dır, matristeki `'6'` karakteri değildir. Format `%c` yapıldığında kodu 6 olan karakter basıldı; konsolda bu bir maça simgesi olarak göründü.

> **Ders sonrası not:** Output 13'teki ifade `*(*(mat+1))+3` biçimindedir: önce `*(*(mat+1))` ile `'6'` karakteri alınır, sonra karakter koduna 3 eklenir. `'6' + 3` kodu `'9'`'a denk geldiği için çıktı yine `9` olur; ama bu bir eleman erişimi değil, karakter aritmetiğidir. Dördüncü elemana erişim `*(*(mat+1)+3)` biçiminde yazılmalıdır; iki ifade rakamlar ardışık olduğu için burada tesadüfen aynı sonucu verir.

> **Ders sonrası not:** Hoca karakter kodu için örnek olarak "97" dedi; ASCII'de `'A'` 65, `'G'` 71'dir (97 küçük `'a'`'nın kodudur). Fark yine 6'dır.

Geçerli satırlar (`ROWS 3`, `COLS 10` varsayımıyla) `gcc -Wall` ile derlenip çalıştırıldı: Output 1-4, 6, 8, 10-15 ekrandaki değerlerle aynı çıktı (`6789AB`, `789AB`, `89AB`, `012345`, `0`, `2`, `0`, `8`, `9`, `9`, `8`, `6`). Hatalı satırlar tanımsız davranış olduğu için denenmedi.

> **Hocanın vurgusu:** İşler giderek karmaşıklaşıyor. Yıldız ve artı kullanımına, parantezlerin yerine çok dikkat edin; en ufak bir parantezi yanlış yere koymak sorun çıkarır.

Dersin sonunda hoca bir satırla ilgili kafaya takılan bir varyasyon varsa sorulabileceğini, tahmin edip çalıştırarak görülebileceğini söyledi. Hatalı satırlardan biri yorumdan çıkarılıp çalıştırıldığında beklenmedik uzunlukta anlamsız çıktı verdi; hoca hatalı satırların arka plandaki nedenini çözümlemekle uğraşmadı.

## Örnek Sorular

### Soru 1: Dinamik bellekle sıralama (ekrandan, 00:45:00)

Basit bir sıralama programı yazın: dizideki eleman sayısını sorun, gerekli yeri ayırın, elemanları isteyin, diziyi sıralayın.

> **Çözüm (derste verildi):** Bölüm 5'teki birleştirilmiş program. Main'de malloc ile `n` elemanlık yer ayrılır, `NULL` denetlenir, elemanlar `scanf("%d", &p[i])` ile okunur; `bubbleSort` ya da `selectionSort` (`getPosOfMin` ve `swap` yardımıyla) çağrılır, sonunda `free` yapılır.

### Soru 2: Matris çarpımı (ekrandan, 00:45:00)

Matris çarpımı yapan bir program yazın: (1) matrislerin boyutlarını sorun, (2) çarpılabilir olup olmadıklarını denetleyin, (3) gerekli yeri ayırın, (4) elemanları isteyin, (5) çarpımı yapın, (6) sonuç matrisini yazın. (Evde yapılacak alıştırma olarak bırakıldı.)

> **Çözüm (derste verilmedi):** Birinci matrisin sütun sayısı ikincinin satır sayısına eşit olmalıdır. Aşağıdaki program `gcc -Wall` ile uyarısız derlendi; $\begin{pmatrix}1&2&3\\4&5&6\end{pmatrix}$ ile $\begin{pmatrix}7&8\\9&10\\11&12\end{pmatrix}$ çarpımı için $\begin{pmatrix}58&64\\139&154\end{pmatrix}$ sonucunu verdi (python ile doğrulandı); 2×3 ile 2×2 için "çarpılamaz" mesajı verdi.

```c
#include <stdio.h>
#include <stdlib.h>

int **allocMatrix( int n, int m ) {
    int i, **mat = (int**) malloc( n * sizeof(int*) );
    if( mat == NULL ) return NULL;
    for( i=0; i<n; i++ ) {
        mat[i] = (int*) calloc( m, sizeof(int) );
        if( mat[i] == NULL ) return NULL;
    }
    return mat;
}
void freeMatrix( int **mat, int n ) {
    int i;
    for( i=0; i<n; i++ ) free( mat[i] );
    free( mat );
}
void readMatrix( int **mat, int n, int m ) {
    int i, j;
    for( i=0; i<n; i++ )
        for( j=0; j<m; j++ ) {
            printf("[%d][%d]: ", i, j); scanf("%d", *(mat+i)+j);
        }
}
int main( void ) {
    int n1, m1, n2, m2, i, j, k;
    int **a, **b, **c;
    printf("1. matrisin satir ve sutun sayisi: "); scanf("%d %d", &n1, &m1);
    printf("2. matrisin satir ve sutun sayisi: "); scanf("%d %d", &n2, &m2);
    if( m1 != n2 ) {
        printf("Bu matrisler carpilamaz.\n"); return 1;
    }
    a = allocMatrix( n1, m1 ); b = allocMatrix( n2, m2 ); c = allocMatrix( n1, m2 );
    if( a == NULL || b == NULL || c == NULL ) {
        printf("Bellekte yer ayrilamadi.\n"); return 1;
    }
    readMatrix( a, n1, m1 );
    readMatrix( b, n2, m2 );
    for( i=0; i<n1; i++ )
        for( j=0; j<m2; j++ )
            for( k=0; k<m1; k++ )
                c[i][j] += a[i][k] * b[k][j];
    printf("\nSonuc:\n");
    for( i=0; i<n1; i++ ) {
        for( j=0; j<m2; j++ ) printf("%5d", c[i][j]);
        printf("\n");
    }
    freeMatrix( a, n1 ); freeMatrix( b, n2 ); freeMatrix( c, n1 );
    return 0;
}
```

Sonuç matrisi calloc ile ayrıldığı için toplamaya sıfırdan başlanır.

### Soru 3: Karakter matrisi çıktı tahmini (ekrandan, 02:20:00)

`text` satırları `"012345\n"`, `"6789AB\n"`, `"CDEFGH\n"` olan bir `char **`, `mat` aynı metinlerle ilk değer almış bir `char *mat[ROWS]`, `bp = text[0]`, `mp = text[1]` olsun. Aşağıdakiler ne yazdırır?

1. `printf("%s", mp+1);`
2. `printf("%c", *(bp+2));`
3. `printf("%c", *(*(text+1)+2));`
4. `printf("%c", *((text[1])+3));`
5. `printf("%d", mat[2][4]-mat[1][4]);`
6. `printf("%c", bp);`

> **Çözüm (derste verildi, çalıştırılarak denetlendi):** (1) `789AB`; (2) `2`; (3) `8` (ikinci satırın üçüncü karakteri; derste ilk tahmin 3 idi); (4) `9`; (5) `6` (`'G' - 'A'`); (6) tanımsız: `%c`'ye adres verilmiştir, anlamsız bir karakter basılır.

### Soru 4: free sonrası içerik (derste sözlü, 00:42:21)

`free` yapıldıktan sonra dizi yazdırıldığında değerlerin çoğu neden hâlâ aynı görünür?

> **Çözüm (derste verildi):** `free` alanı yalnızca "kullanılabilir" diye işaretler, içeriği sıfırlamaz. Alan başka bir ayırmaya verilene kadar eski değerler kalabilir; bu yüzden serbest bırakılmış belleğe erişilmemeli, değişkenlere her zaman ilk değer verilmelidir (Bölüm 4.3).

## Dersin Toparlaması

Bu derste işaretçinin işaretçisinden başlanarak dinamik bellek yönetimi işlendi. malloc, calloc, realloc ve free fonksiyonlarının parametreleri ve farkları görüldü; calloc'un ayırdığı alanı sıfırladığı uygulamada doğrulandı. Her dinamik bellek kullanımında aynı şablon uygulanmalıdır: yer ayır, `NULL` denetle, kullan, işaretçiyi başa getirip `free` et. Matris için önce satır işaretçileri, sonra her satır ayrılır ve boşaltma ters sırada yapılır.

Uygulamada önceki haftaların Bubble Sort ve Selection Sort programları global değişken kullanmadan, main'de ayrılan dinamik dizi üzerinde yeniden yazıldı. Fonksiyonlara her zaman başlangıç adresi ve eleman sayısı gönderildi, yer değiştirme işaretçi alan bir `swap` fonksiyonuna çekildi. Son bölümde `char **` ile işaretçi dizisi üzerinde yıldız, artı ve köşeli parantez birleşimlerinin hangi karaktere ya da satıra ulaştığı, hangilerinin anlamsız sonuç verdiği ya da çöktüğü tek tek denendi. Hoca bu örneklere iyi çalışılmasını istedi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
