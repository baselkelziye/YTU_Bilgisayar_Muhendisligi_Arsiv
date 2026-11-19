# Ders 10 Genişletilmiş Notu: İşaretçi Dizileri, İki Boyutlu Dizilerde İşaretçi Kullanımı ve Dinamik Bellek Yönetimi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersten Bu Derse
- 2. İşaretçi Dizisi (Array of Pointers)
- 3. Metin Matrisini Satır Satır İşaretçiyle İşlemek
- 4. Büyük ve Küçük Harfe Çevirme
- 5. İşaretçiyi Gösteren İşaretçi
- 6. Bütün Matrisi Tek İşaretçiyle Dolaşmak
- 7. Dinamik Bellek Yönetimine Neden İhtiyaç Var?
- 8. Bellek Ayırma Fonksiyonları
- 9. Dizi İçin Bellek Ayırma
- 10. Matris İçin Bellek Ayırma ve Bellek Sızıntısı
- 11. Örnek 1: Dinamik Dizi ve Sıralama
- 12. Selection Sort ile Karşılaştırma
- 13. Sıralamayı Fonksiyonlara Bölmek: printList ve selectionSort
- 14. Örnek 2: Matris Çarpımının Planı
- 15. Metin Örneğini Dinamik Bellekle Yeniden Yazmak
- Örnek Sorular

## 1. Önceki Dersten Bu Derse

Geçen hafta diziler, işaretçiler (pointer), dizilere işaretçi üzerinden erişim ve işaretçi aritmetiği üzerine örnekler yapılmıştı. Bu derste önce bu bilgileri birleştiren işaretçi dizileri ele alınıyor, ardından iki boyutlu bir karakter dizisinin satırlarına işaretçiyle erişen uzun bir örnek kodlanıyor. Dersin ikinci yarısında yeni konu olan dinamik bellek yönetimine (dynamic memory allocation) geçiliyor ve bu konu sıralama örnekleriyle pekiştiriliyor. Kodlar derste Dev-C++ ortamında yazılıp çalıştırıldı.

## 2. İşaretçi Dizisi (Array of Pointers)

Slayttaki tanım şudur (ekrandan, 00:05:00):

```c
char *ar_of_p[5];
char c0 = 'a';
char c1 = 'b';

ar_of_p[0] = &c0;
ar_of_p[1] = &c1;
```

`char *ar_of_p[5];` dendiğinde 5 elemanlı bir işaretçi dizisi tanımlanır. Dizinin her gözü bir adres tutar ve bu adresler birer karakteri gösterecektir. Slayttaki bellek tablosunda dizinin başlangıcı onaltılık `0x1000` adresidir ve gözler `0x1000`, `0x1004`, `0x1008`, `0x100C`, `0x1010` adreslerine yerleşmiştir; yani her işaretçi bu örnekte 4 bayt yer kaplar.

Yalnız 5 tane işaretçi tanımlamak tek başına bir anlam taşımaz; bu işaretçilerin bellekte bir yerleri göstermesi gerekir. En azından birer karakter gösterebilirler, daha iyisi birer karakter dizisi gösterebilirler. Örnekte iki karakter değişkeni tanımlanır: `c0` için `0x2000`, `c1` için `0x2001` adresi ayrılmış ve içlerine `'a'` ile `'b'` yazılmıştır.

Şimdi `ar_of_p[0]` işaretçisinin `c0`'ın simgelediği bellek gözünü göstermesi isteniyor. Bunun için `ar_of_p[0]` gözüne o gözün adresi, yani `2000` yazılmalıdır. Programcı bu adresin kaç olduğunu bilmez (isterse öğrenebilir), ama elinde `c0` değişkeni vardır. Bu yüzden "`c0`'ın adresini al, işaretçinin gözüne yaz" denir: `ar_of_p[0] = &c0;`. Aynı şekilde `ar_of_p[1] = &c1;` ile ikinci göze `2001` yazılır. Kalan üç göz tanımsızdır (undefined).

> **Hocanın vurgusu:** Nereye adres operatörü `&`, nereye işaretçi operatörü `*` konacağı karıştırılmamalıdır. İşaretçiye bir değişkeni göstertmek için o değişkenin adresi (`&c0`) atanır.

## 3. Metin Matrisini Satır Satır İşaretçiyle İşlemek

Hoca işaretçi dizisi fikrini bir uygulamaya taşımak için 5 tane 5 karakterlik metin üzerinde çalışan bir program yazdı. Başlangıç kodu şöyleydi (ekrandan, 00:15:00):

```c
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
void listOneLineOfText( char *p ) {
}

int main(int argc, char *argv[]){
    char metinler[SIZE][SIZE], i;
    for( i=0; i<SIZE; i++ ) {
        printf("Enter text %d: (max %d letters)", i, SIZE);
        scanf("%s",&metinler[i]);
    }
    for( i=0; i<SIZE; i++ ) {
        listOneLineOfText(metinler[i]);
    }

    printf("\n");
    system("PAUSE");
    return 0;
}
```

`metinler` iki boyutlu bir karakter dizisidir, yani bir matristir. Program önce `metinler[0]` satırına, sonra `metinler[1]` satırına ve böyle `metinler[4]`'e kadar her satıra kullanıcıdan bir metin okur. Ardından her satırı ayrı bir fonksiyonla ekrana yazdırır.

### 3.1 Satırı kopyalamak yerine satıra işaretçi göndermek

Bir satırı yazdıracak fonksiyona satırın bütün elemanlarını kopyalamak yerine o satıra bir işaretçi vermek yeterlidir. Hoca bunun en doğru yol olduğunu vurguladı: elemanları kopyalamak, onlar için ayrıca bellek ayırmak demektir. Belleğin en verimli kullanımı her seferinde bir satıra işaretçi yollayıp o satırı fonksiyonda yazdırmaktır.

Fonksiyonun tamamlanmış hali (ekrandan, 00:25:00):

```c
void listOneLineOfText( char *p ) {
    int j;
    for( j=0; j<SIZE; j++ ) {
        printf("%c",*p);
        p++;
    }
    printf("\n");
}
```

Fonksiyon gelen adresten başlayarak `SIZE` kadar karakteri tek tek yazar. Her adımda `p++` ile işaretçi bir sonraki gözü gösterir. Hoca geçen haftayı hatırlattı: işaretçinin türü neyse, işaretçi bir artırıldığında o türün boyu kadar ilerler ve bir sonraki gözü gösterir.

Derste ilk denemede `printf` içinde `*` unutulmuştu. O zaman işaretçinin kendi değeri (adres) bir karakter gibi yazdırılmaya çalışıldı ve ekrana garip karakterler çıktı. İşaretçinin gösterdiği adresteki değeri almak için yıldız operatörü gerekir: `*p`.

Hoca ayrıca iç içe kullanılan döngü değişkenlerinin karışmaması için fonksiyonun içindekine `j` adını verdi.

### 3.2 Matrisin bellekteki resmi

Hoca matrisin bellekte nasıl durduğunu bir tabloda gösterdi (ekrandan, 00:20:00). `metinler[5][5]` için satırlar `metinler[0]`'dan başlayarak alt alta, sütunlar 0'dan 4'e kadar yan yana düşünülür. Her satıra kısa bir isim girildiğinde harfler satırın ilk gözlerine yerleşir; boş kalan gözlerde boş karakter (null, `\0`) bulunur. Örneğin `metinler[0][3]` sıfırıncı satırın üçüncü gözü, `metinler[2][4]` ikinci satırın dördüncü gözüdür.

İlk çağrıda `i = 0` olduğu için fonksiyondaki `p`, `metinler[0]` satırını gösterir; `j = 0`'dan başlayarak `metinler[0][0]`, `metinler[0][1]`, ... gözlerinin içeriği ekrana yazılır.

> **Ders sonrası not:** `char metinler[5][5]` bir satırda en fazla 4 harf ile sonlandırıcı `\0` karakterini tutabilir. Derste 5 harflik isimler de girildi; bu durumda `\0` bir sonraki satırın ilk gözüne taşar. Örnekte sonraki satır hemen ardından okunduğu ve fonksiyon sabit `SIZE` karakter yazdığı için sorun görünmedi, ama son satıra 5 harf girilseydi dizinin dışına yazılırdı.

> **Ders sonrası not:** Ekrandaki `scanf("%s",&metinler[i]);` satırında `&metinler[i]` bir satırın adresidir ama türü `char (*)[5]`'tir; `%s` ise `char *` bekler. Doğru yazım `scanf("%s", metinler[i]);` olmalıdır. Ayrıca ekranda döngü sayacı `i` `char` olarak tanımlanmıştı; `gcc -Wall` bunun dizi indisi olarak kullanılmasına uyarı verir, `int i` yazmak daha doğrudur.

## 4. Büyük ve Küçük Harfe Çevirme

Sonra her satırı büyük harfe çeviren bir fonksiyon yazıldı. Bunun için harflerin ASCII değerleri gerekiyordu. Hoca önce değerleri karıştırdı; doğrulamak için şu küçük deneme yapıldı (ekrandan, 00:40:00):

```c
char ba='A', ka='a';
printf("A=%d,a=%d",ba,ka);
//A=65,a=97,fark=32
```

Çıktı büyük `A` için 65, küçük `a` için 97'dir; aradaki fark 32'dir.

Hoca amacın her türlü metni işleyecek bir `string.h` kütüphanesi yazmak olmadığını, yalnız işaretçilerin dizide ilerletilmesini göstermek olduğunu söyledi. Bu yüzden döngü `\0` görene kadar değil, sabit `SIZE` kadar çalışır.

### 4.1 Hata ve düzeltme süreci

İlk yazımda büyük harflerin aralığı küçük harf aralığı sanıldı ve 32 eklendi; program çalıştırıldığında hiçbir değişiklik olmadı. Bir öğrenci küçük harflerin 97'den başladığını, bu yüzden 97 ile 123 arasına bakıp 32 çıkarmak gerektiğini söyledi. Hoca "şu an kendimi yanlış görmüyorum, deneyip yanlışsam göreyim" diyerek denedi ve hatasını gördü. Bu sırada şu genel tavsiyeyi verdi: insan kodda da sosyal ilişkilerde de yanlışını ancak deneyip görünce anlayabilir. Düzeltildikten sonra büyük harfle girilen bir metnin bozulmadığı da test edildi; zaten büyük olan harflere dokunulmadı.

Son haller (ekrandan, 00:35:00 ve 00:45:00):

```c
void toUpperCase( char *p ) {
    int j;
    for( j=0; j<SIZE; j++ ) {
        if( *p >= 97 && *p <= 123 )
            *p -= 32;
        p++;
    }
}
void toLowerCase( char *p ) {
    int j;
    for( j=0; j<SIZE; j++ ) {
        if( *p >= 65 && *p <= 91 )
            *p += 32;
        p++;
    }
}
```

Koşul `*p` değerine bakar. Karakter küçük harf aralığındaysa 32 çıkarılarak büyük harfe, büyük harf aralığındaysa 32 eklenerek küçük harfe çevrilir. Her durumda `p++` ile bir sonraki göze geçilir. Hoca, buradaki asıl amacın aradaki hatalardan çok iki boyutlu bir dizide işaretçinin nasıl ilerletildiğini görmek olduğunu söyledi: iki boyutlu dizi satır satır, her satırı tek boyutlu bir dizi gibi işlenmiştir.

> **Ders sonrası not:** Hoca 26 harf için sınırı 65 + 26 = 91 ve 97 + 26 = 123 diye hesapladı ve `<=` kullandı. Oysa `Z` 90, `z` 122'dir; 91 `[`, 123 `{` karakteridir. Doğru koşullar `*p >= 97 && *p <= 122` ve `*p >= 65 && *p <= 90` olmalıdır (ya da `<` ile 123 ve 91).

## 5. İşaretçiyi Gösteren İşaretçi

Matrisin tamamını bir fonksiyona vermeye geçmeden önce hoca slayttaki "Pointers to Pointers" konusunu anlattı (ekrandan, 00:40:00):

```c
int r = 5;      /* r bir int */
int *q = &r;    /* q bir int'i gösteren işaretçi */
int **p = &q;   /* p, int'i gösteren bir işaretçiyi gösteren işaretçi */

r = 10;         /* doğrudan atama */
*q = 10;        /* bir dolaylı (indirection) atama */
**p = 10;       /* iki dolaylı atama */
```

`r` değişkeni tam sayıdır ve 5 değerini tutar. `q`, `r`'nin adresini tutan işaretçidir. `q`'yu gösteren bir işaretçi tanımlamak için iki yıldız konur: `p` artık bir işaretçiyi gösteren işaretçidir. Aynı bellek gözüne üç yoldan 10 yazılabilir: doğrudan `r = 10`, `q` üzerinden `*q = 10`, `p` üzerinden `**p = 10`.

Hoca bunun iki boyutlu matris işlemlerinde gerektiğini, ama asıl anlamlı örneklerin dinamik bellek ayırma konusunda geleceğini söyledi. Bu derste yazılan matris örneğinde dinamik bellek ayırma komutu kullanılmadığı için işaretçinin işaretçisine gerek kalmadı. Slayta, ileride dinamik bellek yönetimi kısmında daha basit bir örnek kod eklemek için kendine bir not bıraktı.

## 6. Bütün Matrisi Tek İşaretçiyle Dolaşmak

Bu kez satırları tek tek göndermek yerine bütün matrisi tek bir işaretçiyle yazdıran `listAllLines` fonksiyonu yazıldı. İki boyutlu dizi için iç içe iki döngü de kullanılabilirdi, ama buna gerek yoktur: bellek gözleri peşi sıra ayrıldığı için işaretçiyi tek tek artırmak yeter. Satır sonunu anlamak için sayacın `SIZE`'a bölümünden kalana bakılır. Yalnız geçerli harfler yazdırılır; boş gözlerdeki `\0` gibi değerler atlanır.

Son hali (ekrandan, 01:25:00):

```c
void listAllLines( char *p ) {
    int j;
    for( j=0; j<SIZE*SIZE; j++ ) {
        if( j % SIZE == 0 )
            printf("\n");
        if( ( *p >= 97 && *p <= 123 ) || ( *p >= 65 && *p <= 91 ) ) {
            printf("%c",*p);
        }
        p++;
    }
}
```

### 6.1 Derleyici matrisin adını kabul etmedi

Fonksiyon `listAllLines(metinler)` diye çağrılınca derleyici "incompatible pointer type" (uyumsuz işaretçi türü) dedi. Hoca dizinin adının ilk gözün adresi olduğunu konuştuklarını hatırlatıp birkaç farklı yazım denedi. Sonunda bir öğrencinin önerisiyle ilk satır verildi: `listAllLines(metinler[0])`. Bu çalıştı. Hoca derleyicinin mantığını tam anlamadığını, ama iki boyutlu dizide derleyicinin bir satırdan başlatılmasını istediğini söyledi. Arada şu yorumu da yaptı: derleyici yazmak kolay değildir, gerçekleştirenler böyle bir karar vermiştir. <!-- BELİRSİZ: Arada denenen diğer yazımlar (adres alma vb.) altyazıdan ve karelerden tam okunamadı. -->

> **Ek bilgi (derste anlatılmadı):** `char metinler[5][5]` bir ifadede kullanıldığında ilk elemanının adresine dönüşür. İlk eleman burada 5 karakterlik bir satırdır; bu yüzden `metinler`'in türü `char (*)[5]` (5 karakterlik diziyi gösteren işaretçi) olur, `char *` olmaz. `metinler[0]` ise bir `char` dizisidir ve `char *`'a dönüşür. İki ifade aynı adresi gösterir ama türleri farklıdır; `gcc` bu durumda da "incompatible pointer type" hatası verir.

### 6.2 Yeni satırın yeri

İlk çalıştırmada yeni satır kontrolü harf yazdırıldıktan sonra yapıldığı için satır geçişleri kaydı. Bir öğrenci kontrolü döngünün başına almayı önerdi; hoca bunu güzel bir çözüm buldu. İlk adımda (`j = 0`) da bir boş satır yazılır ama bu bir sorun değildir. Sonuçta beş isim satır satır, hatasız yazdırıldı.

### 6.3 Derlenmiş tam program

Ekrandaki parçalar birleştirilerek aşağıdaki program oluşturuldu. `main`'in sıralaması (önce büyük harfe çevirip satır satır yazma, sonra küçük harfe çevirip bütün matrisi yazma) derste anlatılan akıştan kuruldu (ara adım eklendi). Ekrandakinden farkları: `i` `int` yapıldı, `scanf`'te `&` kaldırıldı, Windows'a özgü `system("PAUSE")` çıkarıldı; harf aralıkları ekrandaki gibi bırakıldı. Program `gcc -Wall` ile uyarısız derlendi ve kısa bir girdiyle çalıştırıldı.

```c
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

void listOneLineOfText( char *p ) {
    int j;
    for( j=0; j<SIZE; j++ ) {
        printf("%c",*p);
        p++;
    }
    printf("\n");
}
void toUpperCase( char *p ) {
    int j;
    for( j=0; j<SIZE; j++ ) {
        if( *p >= 97 && *p <= 123 )
            *p -= 32;
        p++;
    }
}
void toLowerCase( char *p ) {
    int j;
    for( j=0; j<SIZE; j++ ) {
        if( *p >= 65 && *p <= 91 )
            *p += 32;
        p++;
    }
}
void listAllLines( char *p ) {
    int j;
    for( j=0; j<SIZE*SIZE; j++ ) {
        if( j % SIZE == 0 )
            printf("\n");
        if( ( *p >= 97 && *p <= 123 ) || ( *p >= 65 && *p <= 91 ) ) {
            printf("%c",*p);
        }
        p++;
    }
}

int main(int argc, char *argv[]){
    char metinler[SIZE][SIZE];
    int i;
    for( i=0; i<SIZE; i++ ) {
        printf("Enter text %d: (max %d letters)", i, SIZE);
        scanf("%s", metinler[i]);
    }
    for( i=0; i<SIZE; i++ ) {
        toUpperCase(metinler[i]);
        listOneLineOfText(metinler[i]);
    }
    for( i=0; i<SIZE; i++ )
        toLowerCase(metinler[i]);
    listAllLines(metinler[0]);
    printf("\n");
    return 0;
}
```

`ali`, `veli`, `ab`, `cde`, `fgh` girdisiyle önce `ALI`, `VELI`, `AB`, `CDE`, `FGH` satırları, sonra `listAllLines` ile küçük harfli halleri alt alta yazıldı. `listOneLineOfText` sabit 5 karakter yazdığı için satır sonlarındaki `\0` baytları da çıktıya gider; terminalde görünmezler.

## 7. Dinamik Bellek Yönetimine Neden İhtiyaç Var?

On dakikalık aradan sonra yeni konuya geçildi. Bu kısımda bellekten belli bir miktar alanın nasıl ayrılacağı, rezerve edileceği ve programın kendi amaçları için nasıl kullanılacağı anlatıldı. Tek bir bilgiyi saklamak için bellek ayırmak çabaya değmez; asıl amaç bir boyutlu dizi ya da matris gibi kullanılacak geniş bir alan ayırıp üzerinde çalışmaktır.

Hoca gerekçeyi önceki örnekten verdi. Orada metinlerin 5 karakterlik olacağına, matrisin 5'e 5 olacağına baştan karar verilmişti. Kullanıcının 16 karakterlik satırlara ihtiyacı olursa `SIZE` 16 yapılmalıydı; bugün 16 olan ihtiyaç yarın başka olabilir. Programcı ihtiyaç kadar bellek kullanmak ister.

Bir engel daha vardır: C'nin eski standartlarında bir değişken kullanılmadan önce tanımlanmak zorundadır. Kullanıcıya kaç karakter gerektiğini sorup bir değişkene yazmak mümkündür, ama girdi alındıktan sonra o boyutta dizi tanımı yapılamaz; dizinin daha önce tanımlanmış olması gerekir. Bu durumda çare dinamik bellek yönetimidir. Hoca başka dillerin buna izin verdiğini, ama yapısal programlama dillerinin önemli bir bölümünün "önce her şeyi tanımlayacaksın" dediğini söyledi. C standardını bildiğimiz yöne çekmeye çalışmak yerine yeni bir yöntemi öğrenmek gerekir.

## 8. Bellek Ayırma Fonksiyonları

Slayttaki fonksiyonlar şunlardır (ekrandan, 01:05:00). Bazıları birbirinin yerine kullanılabilir; uygun olan sürüm biraz kolaylık sağlar.

- `void *malloc( total_size_in_bytes )`: Parametre olarak verilen bayt kadar bellek ayırır ve ayrılan bloğun başlangıcına bir işaretçi döndürür.
- `void *calloc( number_of_elements, element_size )`: malloc'a benzer, ama iki farkı vardır. İki parametre alır (kaç adet, her biri kaç bayt) ve ayırdığı baytların hepsini sıfırlar. Toplam alan `n * element size` olduğu için iki fonksiyonla aynı büyüklükte alan ayrılabilir.
- `void *realloc( void *prev_ptr, total_size_in_bytes )`: Önceden ayrılmış `prev_ptr` bloğunun boyutunu değiştirir. Bloğu yeni bir yere taşıyabilir; yeni adres fonksiyonun dönüş değeridir. Büyütülen ek alanın sıfırlanacağı asla varsayılmamalıdır. Önceden ayrılmış kısmın içeriği ise korunur.
- `void free( void *ptr )`: malloc, calloc ya da realloc ile ayrılmış belleği geri verir.

### 8.1 malloc ve calloc

Örneğin 10 tane 10 baytlık elemana ihtiyaç varsa `malloc(100)` (10 × 10) ya da `calloc(10, 10)` yazılabilir. İkisi de aynı büyüklükte bir alan ayırıp başlangıcına işaretçi döndürür; calloc ayrıca alanın içini sıfırlar. Sıfırlanmış bir alan gerekiyorsa malloc'la ayırıp her göze tek tek sıfır yazmak yerine calloc bu işi yapar. Çok büyük bir alanda her göze sıfır yazmanın bir işlem maliyeti vardır, ama hoca birkaç yüz gözlük bir alanda bu maliyetin milisaniyelerle bile ölçülemeyecek kadar küçük olduğunu söyledi.

### 8.2 realloc

realloc daha önce ayrılmış bir alanın yerine daha geniş ya da duruma göre daha dar bir alan kullanma imkânı verir. Genişletmede ek gelen baytların sıfırlandığından emin olunamaz: bazı derleyiciler sıfırlar, bazıları sıfırlamaz. En kötü durum düşünülüp alan sıfırlanmamış gibi davranılmalıdır. İyi haber, önceki boyutun kapladığı baytlardaki verinin silinmemesidir.

Programcı "şu adresten itibaren boş bellek istiyorum" diyemez. Nerede boş blok varsa o verilir ve yeni başlangıç fonksiyonun döndürdüğü işaretçidir. Bu yüzden realloc aynı adresten devam eden bir ek alan yerine bambaşka bir adresten başlayan bir alan verebilir; o zaman eski alandaki veriyi yeni alana kopyalar.

> **Hocanın vurgusu:** realloc'un verdiği tek garanti eski verinin korunmasıdır. Yeni gelen bellek alanında rastgele (kirli) veri olabilir; bunun dışında hiçbir garanti yoktur.

### 8.3 free

malloc, calloc ya da realloc ile ayrılan alana olan işaretçi unutulmamalı, nereyi gösterdiği kaybedilmemelidir. free yalnız işaretçi alır; kaç bayt boşaltacağı verilmez. Hoca bu bilginin arka planda bir yerlerde tutulduğunu söyledi. Programcıya düşen, boşaltılacak alanın başlangıcını gösteren işaretçiyi kaybetmemektir.

## 9. Dizi İçin Bellek Ayırma

Slayttaki örnek (ekrandan, 01:15:00):

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

Kullanıcıdan `n` adet tam sayı istenecektir; `n` 1, 10 ya da 100 olabilir. Kullanıcının girebileceği en büyük sayıyı tahmin edip önceden yer ayırmak yerine yalnız gerektiği kadar yer ayrılır. Bu alanın başlangıcı `list` işaretçisinde tutulur.

### 9.1 sizeof

Programcı, kodun çalışacağı platformda bir `int`'in kaç bayt olduğunu bilmek zorunda olmamalıdır; kod farklı platformlarda da çalışabilmelidir. Bunun için `sizeof` vardır: parametre olarak aldığı tür adının o programın çalıştığı platformda kaç baytla simgelendiğini döndürür. `n * sizeof(int)` ile `n` tam sayının kaplayacağı alan hesaplanır ve bu alan malloc ile ayrılır.

### 9.2 Tür dönüşümü

malloc'un tanımında görüldüğü gibi fonksiyon `void *` türünde bir işaretçi döndürür. Bir öğrenci, `void` ise nasıl bir şey döndürdüğünü sordu (Örnek Sorular, Soru 1). Hoca, `void *`'ın türü olmayan bir işaretçi olduğunu, hangi türde işaretçi kullanılacaksa ona dönüştürülmesi (cast) gerektiğini anlattı. `list` `int *` olarak tanımlandığı için malloc'un sonucu `(int *)` ile dönüştürülür.

> **Hocanın vurgusu:** Belki bu dönüşümü otomatik yapan derleyiciler ya da C standartları olabilir, ama buna güvenmemek gerekir. C'de her şeyi kendiniz yapmanız gerekir.

Hoca bunu bir atasözüyle anlattı; bunun üzerine bir öğrenciyle atasözünün aslı ve kurtların sürü hayvanı olup olmadığı üzerine kısa bir sohbet geçti.

### 9.3 NULL kontrolü

malloc istenen alanı ayıramamış olabilir; sistemde o kadar boş bellek kalmamış olabilir. Bu durumda NULL işaretçisi döner. NULL dönmüşse programın ilerleyemeyeceği anlaşılır ve programdan çıkmak en doğrusudur. Hata hakkında ek bilgi vermek için slayttaki gibi `__FILE__` ve `__LINE__` kullanılabilir. Bunlar ön işlemci makrolarıdır: komutun hangi `.c` dosyasında ve hangi satırda olduğunu verirler. Alan başarıyla ayrıldıysa onunla ilgili işler yapılır, en sonunda `free(list)` ile alan sistemin kullanımına geri verilir.

## 10. Matris İçin Bellek Ayırma ve Bellek Sızıntısı

Slayttaki ikinci örnekte `n` satır, `m` sütunluk bir matris oluşturulur. Kullanıcıdan satır sayısı ve sütun sayısı alınır, malloc ile yer ayrılır, ayrılamamışsa programdan çıkılır. Bellek bir blok olarak verildiği için bu blok bir matris gibi kullanılacaksa matrisin gözleri satırlara paylaştırılmalıdır; bu iş bir `for` döngüsüyle yapılır. Hoca calloc'un sıfırladığını, malloc'un sıfırlamadığını burada tekrar hatırlattı. Matris hesapları bittikten sonra matris boşaltılır. <!-- BELİRSİZ: Matris ayırma slaytı (yaklaşık 01:20-01:28) hiçbir karede görünmüyor; slayttaki kodun ayrıntısı (satırlara bölme döngüsü, boşaltma döngüsü) aktarılamadı. -->

Hoca slayttaki boşaltma kısmından emin olamadığını söyledi; açıklamanın slaytta hemen aşağıda verildiğini belirtti. Bellek sızıntısı (memory leak), bir bellek alanı ayırıp sonra geri verememektir. Ayrılan alan sistemden ayrılmış kalır; program yüz kez çalıştırılıp her seferinde biraz bellek alıp geri vermezse sonunda diğer süreçlerin çalışması için bellek kalmaz. Genel kural, her malloc için karşılık gelen bir free komutu olmasıdır. Hoca slayttaki kodu Dev-C++'ta derleyerek denedi ve boşaltma döngüsünü bu kurala uyacak şekilde düzeltti.

> **Hocanın vurgusu:** Her malloc için bir free olmalıdır. Matriste önce bütün alan alınıp satırlara bölündüyse, boşaltırken parantez eşleştirme probleminde olduğu gibi ters sırayla gidilir: önce satırlar, sonra bütün bellek boşaltılır.

> **Ders sonrası not:** Hoca, geri verilmeyen belleğin program kapandıktan sonra bile ayrılmış kalabileceğini söyledi. Günümüz işletim sistemleri büyük olasılıkla süreç bittiğinde onun bütün belleğini geri alır. Sızıntı asıl uzun süre çalışan programlarda (sunucular, sürekli açık uygulamalar) belleğin giderek tükenmesine yol açar; yine de her malloc için free yazma kuralı geçerlidir.

### 10.1 İşaretçilerin boyutu

Bu sırada bir öğrenci `sizeof(int *)` ile `sizeof(char *)`'ın farklı olup olmadığını sordu. Hoca evet dedi: bir karakter genelde 1 baytla, bir tam sayı 2 ya da 4 baytla simgelendiği için işaretçilerin boyunun da farklı olacağını söyledi (Örnek Sorular, Soru 2).

> **Ders sonrası not:** Hoca evet dedi; doğrusu, işaretçinin kendi boyu gösterdiği türün boyuna bağlı değildir. Aynı platformda `int *` ile `char *` büyük olasılıkla aynı boydadır (32 bit sistemlerde 4, 64 bit sistemlerde genelde 8 bayt). Farklı olan, işaretçinin bir artırıldığında kaç bayt ilerlediğidir: `char *` 1, `int *` `sizeof(int)` kadar. Slayttaki `ar_of_p` tablosunda `char *` gözlerinin 4'er bayt olması da bunu gösterir.

Hoca ardından anlaşılmayan yerde araya girip sormayı tekrar rica etti.

## 11. Örnek 1: Dinamik Dizi ve Sıralama

Slayttaki örnekler şunlardı (ekrandan, 01:35:00):

- Basit bir program yaz: sıralama. Dizideki eleman sayısını sor, gerekli alanı ayır, elemanları iste, diziyi sırala.
- Bir program yaz: matris çarpımı (bkz. bölüm 14).

Hoca bu programda üç ayrı temel yetenek gördüğünü söyledi: dizi girişi, dizi listeleme ve dizi sıralama. Bunları ayrı fonksiyonlarda yapmak yararlıdır; en azından sıralama mutlaka ayrı fonksiyon olacaktır.

### 11.1 Bellek ayırma ve eleman okuma

İlk hali (ekrandan, 01:45:00):

```c
int main(int argc, char *argv[]){
    int i, n;
    int *p, *begin;
    printf("Kac tamsayi girmek istiyorsunuz? ");
    scanf("%d",&n);
    p = (int*) malloc( n * sizeof(int) );
    begin = p;
    if( p == NULL ) {
        printf("Bellek ayrilamadi"); return -1;
    }
    for( i=0; i<n; i++ ) {
        printf("%d. tamsayi? ",(i+1));
        scanf("%d", p+i);
    }
    ...
```

`scanf` adres ister. İşaretçinin adı zaten ilgili bellek adresini tuttuğu için burada `*p` ya da `&p` yazmak yanlış olur; `p+i` yazılır. `p+i`, `i`'nci tam sayının adresidir; `p` her artırıldığında `sizeof(int)` kadar (4 baytsa 4) ilerler.

Hoca önce ayrılan alanın başlangıcını kaybetmemek için `begin` değişkenini ekledi: işaretçi ilerletilecekse başlangıç bir yerde tutulmalı, sonunda o boşaltılmalıdır. Sonra başka bir yol seçti: `p` hiç kıpırdatılmaz, her seferinde "başlangıç adresinden şu kadar ileri" denir (`p+i`). Okunan sayıları kontrol etmek için `printf("%d ", *(p+i));` ile yazdırdı; burada adresi değil, gösterilen değeri yazdırmak istendiği için yıldız gerekir. 9 sayı (11, 22, 44, 33, 55, 77, 66, 99, 88) girildi ve aynı sırayla okunduğu görüldü. `p` hiç ilerletilmediği için `begin` gereksiz kaldı ve son halde silindi (ekrandan, 01:55:00).

### 11.2 Sıralama fonksiyonu

Sıralama için en kolay yöntem olarak hocanın "bubble sort" dediği yöntem seçildi. Fonksiyona dizinin başlangıç adresi ve kaç eleman sıralanacağı verilir. Dizi yerinde sıralanacağı için geri dönüş değerine gerek yoktur; fonksiyon `void`'dir. Hoca alternatif olarak `int *` döndüren, gelen diziyi bozmadan sıralı halini döndüren bir imzayı da düşündü, ama bunu belleği boş yere kullanmak olarak gördü: gerekirse çağırmadan önce veri başka bir alana kopyalanabilir.

Değiş tokuş (swap) için ayrı fonksiyon yazılmadı; hoca fonksiyonlar arası bilgi aktarımının püf noktalarına (değerle ve referansla çağırma) henüz gelinmediğini, oraya takılmak istemediğini söyledi. İç içe iki döngü kurulduğu için `b` işaretçisi ileri geri oynatılmadı, dizi gösterimiyle indekslendi (ekrandan, 01:50:00):

```c
void bubbleSort( int *b, int n ) {
    int i, j, tmp;
    for( int i=0; i<n-1; i++ ) {
        for( int j=i+1; j<n; j++ ) {
            if( b[i] > b[j] ) {
                tmp = b[i];
                b[i] = b[j];
                b[j] = tmp;
            }
        }
    }
}
```

Hoca çalışma mantığını şöyle anlattı: önce dizi[0] ile dizi[1] karşılaştırılır, gerekiyorsa yer değiştirilir; sonra dizi[0] ile dizi[2], böyle sona kadar. Sonra dizi[1] ile dizi[2], dizi[1] ile dizi[3] karşılaştırılır. Bir öğrenci "`j` ile `j+1`'i kontrol etmemiz gerekmiyor mu?" diye sordu; hoca kendi yazdığı biçimde `i`'nin `j`'nin hemen öncesinden başlayan bir eleman olduğunu, böyle de sıralandığını açıkladı.

> **Ders sonrası not:** Klasik kabarcık sıralama (bubble sort) her turda yan yana elemanları (`b[j]` ile `b[j+1]`) karşılaştırır; öğrencinin sorusu bu tanıma dayanıyordu. Derste yazılan, `b[i]`'yi ondan sonraki her `b[j]` ile karşılaştıran biçim literatürde büyük olasılıkla "değiş tokuş sıralaması" (exchange sort) diye geçer. İkisi de $O(n^2)$ karşılaştırma yapar ve doğru sonucu verir. Ayrıca ekrandaki kodda `i` ve `j` hem fonksiyonun başında hem `for` içinde tanımlanmıştır; içteki tanım dıştakini gizler ve dıştaki kullanılmaz.

### 11.3 Derlenmiş tam program

Ekrandaki `bubbleSort` ve `main` parçaları birleştirildi (ekrandan, 01:50:00 ve 01:55:00). Ekranın altında kalan son satırlar (son yazdırma döngüsü ve `free`) anlatımdan tamamlandı (ara adım eklendi); fonksiyondaki gizlenen dış `i`, `j` tanımları çıkarıldı. `gcc -Wall` ile derlendi.

```c
#include <stdio.h>
#include <stdlib.h>

void bubbleSort( int *b, int n ) {
    int tmp;
    for( int i=0; i<n-1; i++ ) {
        for( int j=i+1; j<n; j++ ) {
            if( b[i] > b[j] ) {
                tmp = b[i];
                b[i] = b[j];
                b[j] = tmp;
            }
        }
    }
}

int main(int argc, char *argv[]){
    int i, n;
    int *p;
    printf("Kac tamsayi girmek istiyorsunuz? ");
    scanf("%d",&n);
    p = (int*) malloc( n * sizeof(int) );
    if( p == NULL ) {
        printf("Bellek ayrilamadi"); return -1;
    }
    for( i=0; i<n; i++ ) {
        printf("%d. tamsayi? ",(i+1));
        scanf("%d", p+i);
    }
    for( i=0; i<n; i++ )
        printf("%d ",*(p+i));
    bubbleSort(p,n);
    printf("\nSirali dizi ");
    for( i=0; i<n; i++ )
        printf("%d ",*(p+i));
    printf("\n");
    free(p);
    return 0;
}
```

9 sayı ve 11 22 44 33 55 77 66 99 88 girdisiyle `Sirali dizi 11 22 33 44 55 66 77 88 99` çıktısı alındı.

### 11.4 Yeni öğrenilenlerin özeti

Hoca kodu yeniden gözden geçirirken yeni konulara odaklandı:

- Dizi tanımı kullanılmadı; sıralama fonksiyonunda yalnız dizi gösterimi (köşeli parantez) kullanıldı.
- Kullanıcı kaç tam sayı gireceğini çalışma anında söyledi; tam sayı boyutunda `n` adet alan ayrıldı.
- Burada calloc kullanmaya gerek yoktur: bütün elemanlar kullanıcıdan gelecektir, önce sıfırlanmalarının bir anlamı yoktur. calloc boş yere sıfırlama işi yaptırırdı; doğrusu malloc'tur.
- `p` hiç ileri geri götürülmediği için başlangıç adresini ayrıca saklamaya gerek kalmadı.
- Önce alanın ayrılıp ayrılmadığı kontrol edildi, sonra sayılar alındı ve doğru alındığı görüldü, sonra sıralama fonksiyonu çağrıldı, en sonunda `free(p)` ile alan boşaltıldı.

> **Hocanın vurgusu:** Sıralama fonksiyonuna eleman sayısını da göndermek önemlidir. `p` işaretçisine şu kadar bayt ayrıldı diye işaretçi kendi boyunu tutmaz; fonksiyon kaç eleman olduğunu başka türlü bilemez.

## 12. Selection Sort ile Karşılaştırma

Bir öğrenci yazılan sıralamanın selection sort'a benzeyip benzemediğini sordu. Hoca benzemediğini söyledi ve iki yöntemi Excel'de beş elemanlı bir dizi üzerinde gösterdi. Dizi 77, 66, 98, 45, 74 idi. <!-- BELİRSİZ: Excel tablosunun karesi yok; dizi değerleri altyazıdaki anlatımdan kuruldu ve aşağıdaki adımlarla tutarlı olduğu python ile denetlendi. -->

### 12.1 Selection sort adımları

Selection sort önce dizinin en küçük elemanını bulur, seçer (adı "select"ten gelir) ve baştaki elemanla yerini değiştirir.

| Tur | Aramaya başlanan konum | Bulunan en küçük | Dizi |
|---|---|---|---|
| Başlangıç | | | 77 66 98 45 74 |
| 1 | 0 | 45 (konum 3) | 45 66 98 77 74 |
| 2 | 1 | 66 (zaten yerinde) | 45 66 98 77 74 |
| 3 | 2 | 74 (konum 4) | 45 66 74 77 98 |
| 4 | 3 | 77 (zaten yerinde) | 45 66 74 77 98 |

İkinci turda aramaya 1 numaralı gözden başlanır, çünkü baştaki göz artık yerindedir; o yüzden bulunan eleman sıradaki en küçüktür. Her turdan sonra dizi o tura kadar olan kısmı için sıralıdır: ilk turdan sonra ilk eleman, ikinci turdan sonra ilk iki eleman, ve böyle.

### 12.2 Derste yazılan sıralamanın adımları

Derste yazılan yöntemde önce 77 ile 66 karşılaştırılır; sıra bozuk olduğu için yer değiştirir (66 77 98 45 74). Sonra hep sıfırıncı göz diğerleriyle karşılaştırılmaya devam eder: 66 ile 98 arasında sorun yok; 66 ile 45 arasında sıra bozuk, yer değiştirir (45 77 98 66 74); 45 ile 74 arasında sorun yok. Hoca bu yöntemde küçük değerlerin gitgide yukarı, büyük değerlerin aşağı doğru kabarcıklandığını, ama selection sort'taki gibi her turda baş kısmın kesin sıralı olacağının söylenemeyeceğini anlattı.

> **Ek bilgi (derste anlatılmadı):** Derste yazılan `i`-`j` yönteminde de her dış tur bittiğinde `b[i]` kalan elemanların en küçüğü olur; farkı, bu en küçüğe ulaşırken araya birçok gereksiz değiş tokuş girmesidir. Selection sort ise her turda yalnız bir değiş tokuş yapar.

## 13. Sıralamayı Fonksiyonlara Bölmek: printList ve selectionSort

İkinci aradan sonra hoca yeni konuya geçmeyip sıralama örneğini geliştirdi.

### 13.1 printList

Diziyi birçok yerde yazdırdığı için bunu ayrı bir fonksiyon yaptı. İşaretçi kaç elemanlı olduğunu bilmediği için eleman sayısı da parametre olarak verilir. Fonksiyon önce bir yeni satır, sonra dizinin elemanlarını yazar. Bubble sort'ta her karşılaştırmadan sonra dizinin o anki hali yazdırıldı. <!-- BELİRSİZ: printList'in gövdesi hiçbir karede görünmüyor; aşağıdaki derlenmiş programdaki gövde altyazıdaki anlatımdan ve ekrandaki çıktı biçiminden kuruldu. -->

İlk derlemede derleyici `printList` için tür uyuşmazlığı uyarısı verdi. Hoca nedenini hatırladı: fonksiyon, onu çağıran fonksiyonlardan sonra tanımlanmıştı. Çözüm, ya fonksiyonu öne almak ya da baştan bildirimini (prototip) yazmaktır.

> **Ek bilgi (derste anlatılmadı):** Eski C kurallarında bildirimi görülmemiş bir fonksiyon çağrılınca derleyici onun `int` döndürdüğünü varsayar. Sonradan `void printList(...)` tanımıyla karşılaşınca bu varsayımla çelişen bir tür görür ve uyarı (yeni derleyicilerde hata) verir. Prototip `void printList( int *b, int n );` dosyanın başına yazılırsa sorun kalmaz.

9 sayı girildi: 23, 65, 87, 23, 85, 99, 44, 55, 27 (ekrandan, 02:20:00). En küçük değer başta olduğu için ilk turdaki bütün karşılaştırmalarda değişiklik olmadı. İkinci turda 65 ile ondan küçük olan ikinci 23 yer değiştirdi (23 23 87 65 ...), sonra 87 ile 65 yer değiştirdi. Hoca küçüklerin yukarı, büyüklerin aşağı doğru yavaş yavaş indiğini bu çıktı üzerinde gösterdi; satır satır ayrıntılı incelemeyi öğrencilere bıraktı.

### 13.2 getPosOfMin

Selection sort için, belirli bir konumdan başlayarak en küçük elemanın kaçıncı konumda olduğunu döndüren bir fonksiyon gerekir. Hoca fonksiyonun iki parametreye (dizinin adresi ve eleman sayısı) ek olarak aramaya başlanacak konumu da alması gerektiğini anlattı. Başlangıç için çok büyük bir "sihirli sayı" (örneğin bir milyon) vermek yerine, aramaya başlanan konumdaki elemanı en küçük kabul etmenin daha mantıklı olduğunu söyledi. Yalnız en küçük değeri değil, onun konumunu da saklamak gerekir.

Fonksiyonun adı için uzun ve anlamlı isimleri tercih ettiğini, bunun nesneye yönelik programlamadan kalma bir alışkanlık olduğunu ve yapısal programlamada da yararlı olduğunu söyledi; bir öğrencinin önerdiği adı beğenip kullandı. Ayrıca bir yerde küme parantezi açtıysa tutarlılık için diğer yerlerde de açmayı tercih ettiğini belirtti.

Kod (ekrandan, 02:30:00):

```c
int getPosOfMin( int *p, int n, int pos ) {
    int i, minVal = *(p+pos), minPos = pos;
    for( i=pos+1; i<n; i++ ) {
        if( minVal > *(p+i) ) {
            minVal = *(p+i); minPos = i;
        }
    }
    return minPos;
}
```

Hoca, en küçüğü bulmayı ayrı bir fonksiyona koymanın fazladan bir çağrı maliyeti getirdiğini, hissedilmese bile kodu biraz yavaşlattığını da belirtti.

### 13.3 selectionSort

Dış döngü `n-1` kez döner: 5 elemanlı bir dizide 4. en küçük bulunup yerine konduktan sonra son elemana bakmaya gerek kalmaz. Her turda `getPosOfMin` ile `i` konumundan başlayan kısmın en küçüğünün yeri bulunur ve `i`'deki elemanla yer değiştirir. Döngü içinde çağrılan fonksiyonun kendi döngüsü olduğu için bu yapı aslında iç içe iki döngüdür.

İki gözdeki değer zaten doğru sıradaysa boşuna değiş tokuş yapmamak için bir `if` konabilir. Hoca bunun isteğe bağlı olduğunu söyledi: bir karşılaştırma pahasına üç atamadan kurtulunur.

İlk yazımda hoca `tmp` değişkenini ve dizi gösterimini kullandı; bir öğrenci `j`'nin kaldığını hatırlattı ve `minPos` ile değiştirildi. Hoca, kullandığı değişkenleri her fonksiyonun içinde tanımladığı için tanımsız bir değişken kaldığında derleyicinin hemen hata vereceğini söyledi.

Dizi gösterimiyle doğru sıraladığı görüldükten sonra kod işaretçi gösterimine çevrildi: `b[i]` yerine `*(b+i)`. Hoca, işaretçi gösterimine geçince sıralama bozulursa hatanın işaretçi gösterimini yanlış uygulamaktan kaynaklanacağını, böylece hatanın yerini ayırabileceğini söyledi. `b`'nin türü belli olduğu için `b+i` her seferinde `i` kere tür boyu kadar ilerler. Son hali (ekrandan, 02:40:00):

```c
void selectionSort( int *b, int n ) {
    int i, minPos, tmp;
    for( i=0; i<n-1; i++ ) {
        minPos = getPosOfMin( b, n, i );
        if( *(b+i) > *(b+minPos) ) {
            tmp = *(b+i); *(b+i) = *(b+minPos); *(b+minPos) = tmp;
        }
        printList( b, n );
    }
}
```

### 13.4 Ekrandaki çalıştırma

9 sayı girildi: 34, 65, 12, 76, 43, 77, 87, 74, 37. Ekrandaki çıktı (ekrandan, 02:35:00):

```text
Girilen dizi
34 65 12 76 43 77 87 74 37
12 65 34 76 43 77 87 74 37
12 34 65 76 43 77 87 74 37
12 34 37 76 43 77 87 74 65
12 34 37 43 76 77 87 74 65
12 34 37 43 65 77 87 74 76
12 34 37 43 65 74 87 77 76
12 34 37 43 65 74 76 77 87
12 34 37 43 65 74 76 77 87
Sirali dizi
12 34 37 43 65 74 76 77 87
```

Her satır bir turun sonudur ve dizinin baş kısmının tur tur büyüyerek sıralandığı görülür. Son turda değişiklik olmadığı için son iki satır aynıdır. İşaretçi gösterimine geçildikten sonra da program başka bir girdiyle doğru sıraladı; hoca işaretçi aritmetiğini doğru kurduğunu böylece gördü. Hoca iki yöntemde elemanların değişme sırasını karşılaştırıp incelemeyi öğrencilere bıraktı.

### 13.5 Derlenmiş tam program

`getPosOfMin` ve `selectionSort` ekrandaki gibidir; `printList` gövdesi ve `main`'in yazdırma satırları anlatımdan ve ekrandaki çıktı biçiminden kuruldu (ara adım eklendi). `printList` çağıranlardan önce tanımlandı. `gcc -Wall` ile uyarısız derlendi ve yukarıdaki girdiyle çalıştırıldı; çıktı ekrandaki çıktıyla satır satır aynı çıktı.

```c
#include <stdio.h>
#include <stdlib.h>

void printList( int *b, int n ) {
    int i;
    printf("\n");
    for( i=0; i<n; i++ )
        printf("%d ", *(b+i));
}

int getPosOfMin( int *p, int n, int pos ) {
    int i, minVal = *(p+pos), minPos = pos;
    for( i=pos+1; i<n; i++ ) {
        if( minVal > *(p+i) ) {
            minVal = *(p+i); minPos = i;
        }
    }
    return minPos;
}

void selectionSort( int *b, int n ) {
    int i, minPos, tmp;
    for( i=0; i<n-1; i++ ) {
        minPos = getPosOfMin( b, n, i );
        if( *(b+i) > *(b+minPos) ) {
            tmp = *(b+i); *(b+i) = *(b+minPos); *(b+minPos) = tmp;
        }
        printList( b, n );
    }
}

int main(int argc, char *argv[]){
    int i, n;
    int *p;
    printf("Kac tamsayi girmek istiyorsunuz? ");
    scanf("%d",&n);
    p = (int*) malloc( n * sizeof(int) );
    if( p == NULL ) {
        printf("Bellek ayrilamadi"); return -1;
    }
    for( i=0; i<n; i++ ) {
        printf("%d. tamsayi? ",(i+1));
        scanf("%d", p+i);
    }
    printf("\nGirilen dizi");
    printList( p, n );
    selectionSort( p, n );
    printf("\nSirali dizi");
    printList( p, n );
    printf("\n");
    free(p);
    return 0;
}
```

Hoca değiş tokuş işlemini ayrı bir `swap` fonksiyonuna taşımak için önce değerle çağırma (call by value) ve referansla çağırma (call by reference) konularının anlatılması gerektiğini söyledi; bunu fonksiyonlar konusuna bıraktı.

## 14. Örnek 2: Matris Çarpımının Planı

İkinci örnek iki boyutlu matrislerle benzer bir iş yapmaktır. Slayttaki adımlar (ekrandan, 01:35:00):

1. Matrislerin boyutlarını sor.
2. Çarpılabilir olup olmadıklarını kontrol et.
3. Gerekli alanı ayır.
4. Elemanları iste.
5. Çarpımı yap.
6. Sonuç matrisini yaz.

Slaytta bu örnek evde kodlanmak üzere alıştırma olarak bırakıldı.

### 14.1 Çarpılabilirlik kuralı

Hoca kuralı Excel'de hatırlattı (ekrandan, 01:30:00). Örnek A matrisi 4 satır, 3 sütunludur. Çarpımda A'nın her satırındaki elemanlar B'nin her sütunundaki elemanlarla çarpılıp toplanır. Bu yüzden A'nın 3 sütunu varsa B'nin de 3 satırı olmalıdır. İki matris de kareyse sorun yoktur, ama burada kare olmayan matrislerle de çalışılacaktır; önce satır ve sütun sayılarının uygunluğu kontrol edilmelidir.

$$A_{n \times m} \cdot B_{m \times p} = C_{n \times p}, \qquad c_{ij} = \sum_{k=0}^{m-1} a_{ik}\, b_{kj}$$

### 14.2 Hangi adım için fonksiyon yazılmalı?

Hoca her şeyi tek bir `main` içinde yapmamak gerektiğini, neredeyse her adım için bir fonksiyon yazılabileceğini söyledi, ama gerekliliği adım adım tartıştı:

- 1 (boyutları sormak): ayrı fonksiyon gerekmez.
- 2 (çarpılabilirlik kontrolü): fonksiyon yazılmalı; başka yerlerde de kullanılabilir.
- 3 (bellek ayırma): yazılabilir, ama işi gereksiz karmaşıklaştırır. Zaten malloc ya da calloc ile yapılan bir iştir ve fonksiyonun döndüreceği işaretçinin türünün sonra başka bir türe çevrilmesi gibi ek karmaşıklıklar getirir.
- 4 (elemanları almak): fonksiyon yazılabilir.
- 5 (çarpma): mutlaka ayrı fonksiyon olmalı.
- 6 (matris yazma): ayrı fonksiyon olmalı. Kullanıcının girdiği A ve B matrislerini ve sonucu ekranda görmesi yararlıdır. `A x B = C` biçiminde hepsini aynı satıra yazmak, komut satırında belirli bir koordinata gitmeyi gerektireceği için yazdırma fonksiyonuyla yapılamaz; her matrisin ayrı satırlarda yazılması bile yararlıdır.

Hoca, fonksiyonlara parametre aktarımı konusu görüldükten sonra bu örnekte daha fazla işin fonksiyona taşınabileceğini söyledi.

## 15. Metin Örneğini Dinamik Bellekle Yeniden Yazmak

Dersin sonunda hoca ilk saatteki metin örneğini dinamik bellekle yazmaya başladı. Artık `#define SIZE 5` yoktur; kullanıcıya kaç metin ve en fazla kaç karakterlik metin gireceği sorulur. Büyük-küçük harf çevirme için ASCII hesaplarına da artık gerek kalmadı. Ders bittiğinde kod şu noktadaydı (ekrandan, 02:45:00):

```c
int main(int argc, char *argv[]){
    int strCount, strLength;
    char *s;
    printf("How many strings you will enter? ")
    scanf("%d",&strCount);
    printf("How long will your strings be at most? ")
    scanf("%d",&strLength);
    s = (char*) calloc(
    ...
```

Burada calloc seçildi. Hoca, harf çevirme işlemleri anlamlı karakter kodlarıyla çalışacağı için sıfırlamanın tek başına çok önemli olmadığını, ama sıfırın null karakterine denk geldiğini ve metinlerin null ile sonlanmasının (null terminated) yararlı olduğunu hatırlattı; calloc bunu sağlar. calloc'ta önce eleman sayısı (metin sayısı), sonra eleman boyu gelir. Eleman boyu için `strLength * sizeof(char)` yazmanın daha doğru olacağını söyledi; çarpmanın eleman sayısına değil, genişliğe ait olduğunu vurguladı. Ardından NULL kontrolü yapılıp metinlerin okunmasına geçilecekti.

> **Ders sonrası not:** Hoca bir platformda karakterin iki baytla simgelenebileceğini, bu yüzden `sizeof(char)` ile çarpmanın daha doğru olduğunu söyledi. C standardına göre `sizeof(char)` her zaman 1'dir; `sizeof(char)` ile çarpmak zararsızdır ama zorunlu değildir.

### 15.1 Ne kadar tasarruf edilir?

Hoca bu yapıda çok büyük bir tasarruf yapılmadığını da söyledi. En fazla 10 karakter denip kullanıcı çoğunlukla 2-3 karakter girerse her satırda gözler boşa harcanır. Belleği matris gibi değil, düz giden tek bir alan gibi düşünüp metinleri `\0` ile ayrılmış biçimde peş peşe dizmek de mümkündür; ama o zaman sonlandırıcı için uzunluğa bir eklemek (`strLength + 1`) gerekir. Kullanıcı en fazla 5 dediği halde çoğunlukla 2-3 karakter girerse bu durumda da ayrılan bellek ihtiyaçtan fazla olur.

Hoca örneğe gelecek hafta devam edebileceklerini, ya da önce fonksiyonlara parametre aktarımını (değerle ve referansla çağırma) görüp sonra bu örneğe dönebileceklerini söyledi. Örneğin işaretçinin işaretçisi için de bir örnek olarak kullanılabileceğini ekledi.

## Örnek Sorular

**Soru 1** (derste sözlü, 01:16:36): malloc ve realloc'un tanımında "returns" (döndürür) yazıyor, ama fonksiyonların türü `void`. `void` olan bir fonksiyon nasıl bir şey döndürebilir?

**Cevap (derste verildi):** Fonksiyonlar `void` değil, `void *` döndürür. `void *` türü belirli olmayan bir işaretçidir; döndürülen adres hangi türde kullanılacaksa ona dönüştürülmelidir. Örneğin `list` `int *` olduğu için `list = (int *) malloc( n * sizeof(int) );` yazılır. Bu dönüşümü derleyicinin otomatik yapmasına güvenilmemelidir.

**Soru 2** (derste sözlü, 01:26:54): `sizeof(int *)` ile `sizeof(char *)` farklı mıdır?

**Cevap:** Hoca derste "evet, `int` daha fazla yer kapladığı için işaretçisi de daha büyük olur" dedi.

> **Çözüm (derste verilmedi):** Hayır, işaretçinin boyu gösterdiği türden bağımsızdır; aynı platformda ikisi de büyük olasılıkla aynı boydadır. Ajanın 64 bit Linux'ta `gcc` ile denediği sistemde ikisi de 8 bayttır. Farklı olan, işaretçi aritmetiğidir: `p+1` ifadesi `char *` için 1, `int *` için `sizeof(int)` bayt ilerler.

**Soru 3** (derste sözlü, 01:55:38): Derste yazılan sıralama selection sort gibi değil mi? Selection sort'un adımlarını 77, 66, 98, 45, 74 dizisinde gösteriniz.

**Cevap (derste verildi):** Hayır. Selection sort her turda kalan kısmın en küçüğünü seçip baştaki yerine koyar: 77 66 98 45 74 → 45 66 98 77 74 → 45 66 98 77 74 → 45 66 74 77 98 → 45 66 74 77 98 (ayrıntı için bölüm 12). Her turdan sonra dizinin baş kısmı sıralıdır. Derste yazılan yöntemde ise değerler kabarcık gibi yavaş yavaş yer değiştirir.

**Soru 4** (ekrandan, 02:35:00): 34, 65, 12, 76, 43, 77, 87, 74, 37 dizisine selection sort uygulandığında her turdan sonra dizi nasıl olur?

**Cevap (derste verildi, ekrandaki çıktıdan):** Bölüm 13.4'teki tablo. Turlar sırasıyla 12, 34, 37, 43, 65, 74, 76 ve 77'yi yerine koyar; sonuç 12 34 37 43 65 74 76 77 87'dir.

**Soru 5** (ekrandan, 01:35:00): Matris çarpımı yapan bir program yazınız: matrislerin boyutlarını sorun, çarpılabilir olup olmadıklarını kontrol edin, gerekli alanı dinamik olarak ayırın, elemanları isteyin, çarpımı yapın ve sonuç matrisini yazın.

> **Çözüm (derste verilmedi):** Aşağıdaki program ajan tarafından yazıldı ve test edildi; derste kodlanmadı. Hocanın önerdiği gibi çarpılabilirlik kontrolü, eleman okuma, çarpma ve yazdırma ayrı fonksiyonlardır. Matris her satırı ayrı ayrılan bir işaretçi dizisiyle (`int **`) tutulur ve ters sırayla, önce satırlar sonra satır işaretçileri boşaltılır. `gcc -Wall` ile uyarısız derlendi. $A = \begin{pmatrix}1&2&3\\4&5&6\end{pmatrix}$ ve $B = \begin{pmatrix}7&8\\9&10\\11&12\end{pmatrix}$ için $C = \begin{pmatrix}58&64\\139&154\end{pmatrix}$ verdi; 2×3 ile 2×2 boyutları girildiğinde "Bu matrisler carpilamaz." yazdı.

```c
#include <stdio.h>
#include <stdlib.h>

int **matrisAyir( int satir, int sutun ) {
    int i, **m = (int **) malloc( satir * sizeof(int *) );
    if( m == NULL ) return NULL;
    for( i=0; i<satir; i++ ) {
        m[i] = (int *) malloc( sutun * sizeof(int) );
        if( m[i] == NULL ) return NULL;
    }
    return m;
}
void matrisBosalt( int **m, int satir ) {
    int i;
    for( i=0; i<satir; i++ )
        free( m[i] );
    free( m );
}
int carpilabilirMi( int aSutun, int bSatir ) {
    return aSutun == bSatir;
}
void matrisOku( int **m, int satir, int sutun, char ad ) {
    int i, j;
    for( i=0; i<satir; i++ )
        for( j=0; j<sutun; j++ ) {
            printf("%c[%d][%d]? ", ad, i, j);
            scanf("%d", &m[i][j]);
        }
}
void matrisCarp( int **a, int **b, int **c, int n, int m, int p ) {
    int i, j, k;
    for( i=0; i<n; i++ )
        for( j=0; j<p; j++ ) {
            c[i][j] = 0;
            for( k=0; k<m; k++ )
                c[i][j] += a[i][k] * b[k][j];
        }
}
void matrisYaz( int **m, int satir, int sutun ) {
    int i, j;
    for( i=0; i<satir; i++ ) {
        for( j=0; j<sutun; j++ )
            printf("%5d", m[i][j]);
        printf("\n");
    }
}
int main( void ) {
    int n, m, m2, p;
    int **a, **b, **c;
    printf("A satir ve sutun sayisi? ");
    scanf("%d %d", &n, &m);
    printf("B satir ve sutun sayisi? ");
    scanf("%d %d", &m2, &p);
    if( !carpilabilirMi( m, m2 ) ) {
        printf("Bu matrisler carpilamaz.\n");
        return -1;
    }
    a = matrisAyir( n, m );
    b = matrisAyir( m, p );
    c = matrisAyir( n, p );
    if( a == NULL || b == NULL || c == NULL ) {
        printf("Bellek ayrilamadi\n");
        return -1;
    }
    matrisOku( a, n, m, 'A' );
    matrisOku( b, m, p, 'B' );
    matrisCarp( a, b, c, n, m, p );
    printf("\nA =\n"); matrisYaz( a, n, m );
    printf("B =\n");   matrisYaz( b, m, p );
    printf("C = A x B =\n"); matrisYaz( c, n, p );
    matrisBosalt( a, n ); matrisBosalt( b, m ); matrisBosalt( c, n );
    return 0;
}
```

## Dersin Toparlaması

Ders işaretçi dizisinin bellekteki görünümüyle başladı ve bu fikir iki boyutlu bir karakter dizisi üzerinde uygulandı. Bir matrisin satırına işaretçi göndermenin, satırı kopyalamaktan daha verimli olduğu görüldü; aynı matris hem satır satır hem de tek bir işaretçiyle baştan sona dolaşıldı. Bu sırada `*` ile `&`'nin yeri, işaretçi artırmanın anlamı ve derleyicinin iki boyutlu dizinin adını `char *` olarak kabul etmemesi gibi pratik noktalar ortaya çıktı. İşaretçiyi gösteren işaretçi kısaca tanıtıldı.

Dersin ikinci yarısında dinamik bellek yönetimine geçildi: malloc, calloc, realloc ve free'nin farkları, `sizeof` ile platformdan bağımsız boyut hesabı, `void *` dönüşünün açıkça dönüştürülmesi, NULL kontrolü ve her malloc için bir free kuralı. Bunlar kullanıcının çalışma anında belirlediği boyutta bir diziyi sıralayan örneklerle uygulandı, derste yazılan sıralama selection sort ile karşılaştırıldı, selection sort fonksiyonlara bölünüp işaretçi gösterimiyle yazıldı. Matris çarpımı evde yapılacak alıştırma olarak bırakıldı. Metin örneğinin dinamik bellekle yazılmasına başlandı; hoca bir sonraki konunun fonksiyonlarda parametre aktarımı (değerle ve referansla çağırma) olacağını, `swap` gibi işlemlerin orada daha anlamlı yapılacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
