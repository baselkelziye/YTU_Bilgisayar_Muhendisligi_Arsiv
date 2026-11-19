# Ders 7 Genişletilmiş Notu: Dizilerle Sıralama, Karakter Katarları ve Çok Boyutlu Diziler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Neden Sıralama Fonksiyonla Yazılmalı?
- 2. Sıralama Algoritmaları: Selection Sort ve Bubble Sort Hatırlatması
- 3. Dizi Üzerinde Sıralama Programı
- 4. Sıralamayı Tablo Üzerinde Adım Adım İzlemek
- 5. C'de Karakter Katarları ve Null Karakteri
- 6. String Atama Örnekleri: Ne Olur, Ne Olmaz?
- 7. Karakter ile String Arasındaki Fark
- 8. scanf ile String Okumak ve Tampon Taşması
- 9. Kendi strLen Fonksiyonumuz
- 10. string.h İçindeki Diğer Fonksiyonlar
- 11. strcmp ile Karşılaştırma Denemeleri
- 12. Örüntü Arama Örneği: indexOfV1
- 13. indexOfV1'i Tablo Üzerinde İzlemek
- 14. strstr ile Daha Kısa Çözüm: indexOfV2
- 15. Çok Boyutlu Diziler ve İşaretçi Aritmetiği
- 16. Çok Boyutlu Dizilerin İlklendirilmesi

## 1. Neden Sıralama Fonksiyonla Yazılmalı?

Bu hafta dizilerden devam edildi. Hoca önce, sıralama gibi bir işin normalde ayrı bir fonksiyon olarak yazılacağını hatırlattı. Bunun nedeni kodun modüler olmasını istememizdir: Yaptığımız bir işi başka yerlerde tekrar tekrar yazmak istemeyiz. Elimizde hazır bir sıralama fonksiyonu olsa onu bir kitaplığa kaydeder, sonra `#include` ederek birçok yerden kullanırız.

Fonksiyonlar ve fonksiyonlara parametre aktarma henüz işlenmedi. Hoca, parametre bir dizi olduğunda yapılan değişikliklerin kalıcı olması için diziyi işaretçi (pointer) üzerinden aktarmak gerektiğini, bunun ilerideki haftalarda görüleceğini söyledi. Bu yüzden ilk örnek fonksiyon kullanılmadan, şimdiye kadar görülen dizi bilgisiyle yazıldı.

## 2. Sıralama Algoritmaları: Selection Sort ve Bubble Sort Hatırlatması

Bilgisayar programlamaya giriş derslerinde anlatılan ilk ileri düzey algoritmalardan biri selection sort'tur. Çalışma biçimi şöyleydi:

- Dizinin içindeki en küçük elemanı bul, dizinin başındaki elemanla yerlerini değiştir.
- İkinci en küçük elemanı bul, dizinin ikinci elemanıyla yer değiştir.
- Böyle devam ederek $n$ elemanlı bir dizide $n-1$. en küçük elemanı bulup ilgili konuma yerleştir.

Burada en küçüğü bulmak başlı başına bir sorumluluktur, ayrı bir iştir. Hoca bu yüzden selection sort'u fonksiyonlar görüldükten sonra yapmanın daha doğru olacağını söyledi ve derste yapmadı.

Bubble sort'u ise şöyle anlattı: Hep bir elemanı sonraki elemanla karşılaştır; daha küçükse yerlerini değiştir; bunu dizinin sonuna kadar sürdür. Bu yapılırken küçük elemanlar giderek yukarı, büyük elemanlar aşağı doğru gider. Hocanın benzetmesiyle küçük elemanlar kabarcık gibi suyun yüzüne yükselir, ağır elemanlar suyun dibine batar. Algoritmanın adı da buradan gelir.

## 3. Dizi Üzerinde Sıralama Programı

### 3.1 Eleman sayısını sabit olarak tanımlamak

Program kullanıcıdan 10 eleman isteyecek. Bu sayı daha sonra kolayca değiştirilebilsin diye değişken yerine bir sabit tanımlandı: `#define ELEMAN_SAYISI 10`. Hoca, ön işlemci komutlarının yaptığı işin ilgili tanımı kodun her yerine gömmek olduğunu hatırlattı. `int sayi = 10;` gibi bir global değişken tanımlansaydı bu bir `int` kadar bellek tutacaktı; `#define` ile tanımlanan sabit ise kullanıldığı her yere yazılır ve bu amaçla bellek kullanılmaz.

### 3.2 Elemanları okumak ve yazdırmak

Ekrandaki kodun ilk kısmı şöyledir (ekrandan, 00:15:00):

```c
int main(int argc, char *argv[]){
    int ar[ELEMAN_SAYISI];
    int i,j;
    printf("%d eleman girilecek.\n", ELEMAN_SAYISI);
    for( i=0; i<ELEMAN_SAYISI; i++ ) {
        printf("%d. elemani girin",(i+1));
        scanf("%d",&ar[i]);
    }
    printf("Girilen dizi: ");
    for( i=0; i<ELEMAN_SAYISI; i++ ) {
        printf("%d ",ar[i]);
    }
    ...
```

Hoca birkaç ayrıntıya dikkat çekti. Kullanıcıya kaç eleman gireceği baştan söylenir; böylece kullanıcı işin ne kadar süreceğini bilir, istemezse programı kapatabilir. Biz diziyi 0'dan saymaya başlarız, ama normal kullanıcılar 1'den sayar; bu yüzden ekrana `i+1` yazılır. İlk denemede `scanf` içinde `&` unutulmuştu; bir öğrenci "ampersand gerekiyor" diye hatırlattı ve düzeltildi.

Hoca, elemanları okuma ve yazdırma kısımlarının normalde ayrı fonksiyonlar olması gerektiğini de söyledi: Dizi sıralamadan önce de sonra da yazdırılacak. Aynı kod iki kez kopyalanırsa, bir yanlış yapıldığında onu iki yerde düzeltmek gerekir.

### 3.3 Yer değiştirme ve geçici değişken

İki elemanın yerini değiştirmek için geçici bir değişken gerekir. Hoca bunu elindeki pillerle gösterdi: Piller dizinin elemanları, eller dizinin gözleri olsun. İki pilin yerini değiştirmek için ikisini aynı anda havaya atamazsınız; birini önce bir yere koymanız gerekir. Kodda bu yer `tmp` değişkenidir:

```c
tmp = ar[i];
ar[i] = ar[j];
ar[j] = tmp;
```

İlk eleman `tmp`'de saklandıktan sonra onun yerine korkmadan yazılabilir, sonra saklanan değer ikinci gözün yerine konur.

### 3.4 Döngü sınırları

Artan sıralama yapıldığı için şu anki eleman sonrakinden büyükse yer değiştirilir. Aynı elemanı kendisiyle karşılaştırmaya gerek yoktur, bu yüzden iç döngü `j = i+1`'den başlar. Dizi 0 ile `ELEMAN_SAYISI-1` arasında indislenir; son elemanın karşılaştırılacağı başka eleman kalmadığı için dış döngü `ELEMAN_SAYISI-1`'e kadar gider. Hoca burada off-by-one hatası yapmamaya dikkat çekti.

<!-- BELİRSİZ: iç döngünün son hâli karede görünmüyor. Altyazıda "j'yi i-1'den başlatıyorum" yazıyor; Excel izlemesinde i=0 için j=1, 2, ... değerleri kullanıldığından başlangıç j=i+1 kabul edildi. -->

Aşağıdaki tam program ajan tarafından derste anlatılana ve ekrandaki kısma göre bir araya getirildi. `gcc -Wall` ile uyarısız derlendi ve derste girilen değerlerle çalıştırıldı.

```c
#include <stdio.h>
#define ELEMAN_SAYISI 10

int main(int argc, char *argv[]) {
    int ar[ELEMAN_SAYISI];
    int i, j, tmp;
    printf("%d eleman girilecek.\n", ELEMAN_SAYISI);
    for (i = 0; i < ELEMAN_SAYISI; i++) {
        printf("%d. elemani girin", (i + 1));
        scanf("%d", &ar[i]);
    }
    printf("Girilen dizi: ");
    for (i = 0; i < ELEMAN_SAYISI; i++)
        printf("%d ", ar[i]);
    printf("\n");
    for (i = 0; i < ELEMAN_SAYISI - 1; i++) {
        for (j = i + 1; j < ELEMAN_SAYISI; j++) {
            if (ar[i] > ar[j]) {
                tmp = ar[i];
                ar[i] = ar[j];
                ar[j] = tmp;
            }
        }
    }
    printf("Sirali dizi: ");
    for (i = 0; i < ELEMAN_SAYISI; i++)
        printf("%d ", ar[i]);
    printf("\n");
    return 0;
}
```

### 3.5 Programı denemek

Derste girilen değerler 98, 45, 34, 27, 74, 68, 59, 25, 49, 77'dir; ilk yedisi karede okunuyor (ekrandan, 00:20:00). <!-- BELİRSİZ: 8. ve 9. değerler karede yok; "25" ve "49" altyazıdan ve hocanın sıralı çıktıyı okumasından çıkarıldı. --> Sıralı çıktı 25, 27, 34, 45, 49, 59, 68, 74, 77, 98 oldu ve en büyük eleman en sona gitti.

Hoca burada önemli bir test alışkanlığından söz etti: Yalnızca çıktının sıralı görünüp görünmediğine bakmak yetmez. Bir şeyler karışmışsa dizi kendi içinde sıralı olduğu hâlde girilmemiş bir eleman içerebilir. Bu yüzden girilen her elemanın çıktıda yer alıp almadığı da tek tek denetlendi. Okunabilirlik için çıktıların arasına `\n` eklendi.

> **Ders sonrası not:** Hoca algoritmayı "her elemanı bir sonrakiyle karşılaştır" diye bubble sort olarak anlattı, ama yazılan döngü `ar[i]`'yi kendisinden sonraki bütün `ar[j]` elemanlarıyla karşılaştırıyor. Bu biçim büyük olasılıkla "exchange sort" diye bilinen, selection sort'a yakın bir sıralamadır. Klasik bubble sort'ta her geçişte yan yana duran `ar[j]` ve `ar[j+1]` karşılaştırılır. İki yöntem de diziyi doğru sıralar.

## 4. Sıralamayı Tablo Üzerinde Adım Adım İzlemek

Hoca algoritmanın nasıl çalıştığını göstermek için Excel'de 0 ile 99 arasında 10 rastgele sayı üretti, birinci satıra indisleri, ikinci satıra değerleri yazdı. Anlatımı kolaylaştırmak için ilk değeri 36 yaptı. Tablo şöyledir (ekrandan, 00:25:00):

| İndis | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|---|---|---|---|---|---|---|---|---|---|---|
| Değer | 36 | 96 | 22 | 94 | 85 | 73 | 47 | 88 | 48 | 73 |
| i=0, j=2'den sonra | 22 | 96 | 36 | 94 | 85 | 73 | 47 | 88 | 48 | 73 |

İzleme şöyle ilerler:

- `i=0, j=1`: 36 ile 96 karşılaştırılır. 36 daha küçük, sıra istenen gibi; değişiklik yok.
- `i=0, j=2`: 36 ile 22 karşılaştırılır. 22 daha küçük, yer değiştirilir: 0. gözde 22, 2. gözde 36 olur. Diğer değerler değişmez.
- `i=0, j=3 ... 9`: 22'den küçük eleman yok; değişiklik olmaz.
- İlk iterasyonun sonunda en küçük eleman (22) dizinin ilk gözüne yerleşmiş olur.
- `i=1, j=2`: 96 ile 36 karşılaştırılır. 96 büyük olduğu için yer değiştirilir; 1. gözde 36, 2. gözde 96 olur. Sonra `j=3`'ten itibaren devam edilir.

Böylece her iterasyonda o konuya gelmesi gereken eleman yerine oturur. Hoca, algoritmanın tarif ettiği karşılaştırma biçimi bu olduğu için döngülerin bu şekilde kurulduğunu söyledi.

## 5. C'de Karakter Katarları ve Null Karakteri

C'de hazır bir karakter katarı (string) tipi yoktur. Stringler karakter dizileri olarak işlenir. Bu yüzden bir string kullanılacağı zaman en fazla kaç karakter uzunluğunda olacağı, tıpkı bir dizinin eleman sayısı gibi, baştan tanımlanmalıdır. Örneğin yer 64 karakter olsun.

Peki 64 karakterlik bir alana 30 karakterlik bir string yazıldığında stringin nerede bittiği nasıl anlaşılır? Burada null karakteri devreye girer. Null karakteri kaçış dizisiyle (escape sequence) `\0` biçiminde yazılır ve stringin sonuna gelindiğini gösterir. Örneğin 10 karakterlik bir alana "yes" yazıldığında son karakter olarak `\0` konur.

Hoca bunun neden önemli olduğunu bir örnekle anlattı: Aynı dizi daha önce başka bir amaçla kullanılmış ve içinde "programlar" yazıyor olsun. Üzerine "yes" yazılır ama sona `\0` konmazsa, string "yesgramlar" gibi görünür. Bu yüzden karakter katarının sonunu null karakteriyle belirtmek önemlidir.

Stringleri modellemek için karakter işaretçileri de kullanılabilir. Ancak hoca, işaretçiye doğrudan string atanan bir ifadeyi her C derleyicisinin ve her standardın aynı biçimde desteklemeyeceğini söyledi. İşaretçinin önce bir karakter dizisini göstermesi ya da ileride görülecek şekilde önce bir bellek alanı ayrılıp işaretçinin o alanın başını göstermesi gerekir.

## 6. String Atama Örnekleri: Ne Olur, Ne Olmaz?

Slayttaki örnek şöyledir (ekrandan, 00:35:00; düzeltilmiş hâli 00:40:00):

```c
main () {
    char array[10];
    char *ptr1="10 spaces";
    char *ptr2;
    array = "not OK";   // can NOT assign to an address! Does not compile
    array[5] = 'A';     // Buggy because: Array is not populated yet. So, ...
    array[0] = 'O';     // ... Always begin from 0 and
    array[1] = 'K';
    array[2] = '\0';    // use null-terminated strings where necessary
    ptr1[8] = 'r';      // Buggy because: The entire string is not populated yet.
    *ptr2 = "not OK";   // Type mismatch warning. Does not compile
    ptr2="OK";
}
```

Slaytın altındaki dipnot: "in DevCPP4, linker gives warning at first but if you make a second attempt, it compiles!"

Satır satır açıklama:

- `char *ptr1 = "10 spaces";` 9 karakter içerdiği için 10 elemanlık bir yere sığar. Hoca önce bunun sorunsuz olduğunu söyledi, sonra sözünü geri aldı: `ptr1` önceden ilklendirilmediği için bu ifade her yerde çalışmayabilir.
- `array = "not OK";` hatalıdır. `array` yalnızca dizinin adıdır, dizinin başladığı adresi gösteren bir işaretçi gibi düşünülür. Bir adresin içeriğine değer atanabilir, adresin kendisine doğrudan değer atanamaz. Bu yüzden derleme hatası verir.
- `array[5] = 'A';` derlenir, ama dizinin o bellek gözlerinde önceden ne yazılı olduğunu bilmiyoruz. Bazıları ekranda görüntülenemeyen karakterler olabilir. Sonuçta arada bir yerde `A` geçen anlamsız bir string elde edilir.
- Bu yüzden bir string yazarken hep dizinin 0. elemanından başlanır ve yazılanın sonu `\0` ile bitirilir. Hoca örneği iki harfli "OK" stringi olacak şekilde düzeltti: `array[0]='O'; array[1]='K'; array[2]='\0';`.
- `ptr1[8] = 'r';` ilklendirme tam doğru yapılmadığı için hatalıdır.
- `*ptr2 = "not OK";` başında yıldız olduğu için tip uyuşmazlığıdır. `ptr2 = "OK";` biçiminde yıldız olmadan yapılan atama ise sorun çıkarmaz.

### 6.1 Dev-C++'ta deneme

Hoca kodu Dev-C++ 4'e yazdı. Karakter sabitleri için tek tırnak kullanılması gerektiğini, çift tırnakla yazılırsa hata alınacağını da gösterdi. Derlemede önce `array = "not OK";` satırı için "incompatible types in assignment" hatası geldi; bu satır yoruma alındı. Sonra `*ptr2 = "not OK";` için tamsayı ile işaretçi arasında dönüşüm yapılmadan atama yapılamayacağını söyleyen bir uyarı geldi. Dipnotta yazdığı gibi ikinci denemede derleme tamamlandı.

Sonra çıktı satırları eklendi (ekrandan, 00:45:00):

```c
printf("Array: %s\n",array);
printf("ptr1: %s\n",*ptr1);
printf("%s\n",*ptr2);
```

Program çalıştı ve hiçbir çıktı vermeden kapandı. Hoca bunu işaretçilerin düzgün kullanılmadığının bir göstergesi olarak yorumladı. İşaretçiyle ilgili şüpheli satırlar kapatılınca dizi kısmı düzgün çalıştı: `array[5]`'e `A` atanmış olsa da 0, 1 ve 2. gözlere `O`, `K` ve `\0` konduğu için çıktı `OK` oldu. Hoca bu üç satırı da kapatıp diziyi yazdırınca ekrana anlamsız karakterler geldi. Bunlar aslında anlamsız değildir: O gözlerde tamsayı olarak ne varsa onun ASCII tablosundaki karşılığı görünür. 5. gözde de büyük `A` yer alır.

> **Ders sonrası not:** Karedeki `printf("ptr1: %s\n", *ptr1);` ve `printf("%s\n", *ptr2);` satırlarında `%s` bir adres (`char *`) beklerken tek bir karakter (`*ptr1`) veriliyor. Programın hiç çıktı vermeden kapanmasının bir nedeni büyük olasılıkla bu satırlardır. Ayrıca `char *ptr1 = "10 spaces";` C'de geçerli bir tanımdır; sorun, işaretçinin değiştirilemeyen bir string sabitini göstermesidir. `ptr1[8] = 'r';` bu yüzden tanımsız davranıştır. Güncel gcc (15.2) `*ptr2 = "not OK";` satırını uyarı olarak değil, hata olarak bildirir (ajan denemesi).

Aradan sonra hoca toparladı: İşaretçi aritmetiği henüz ayrıntılı işlenmediği için stringlerle çalışmanın en sağlam yolu, önce bir karakter dizisine yer ayırmak, sonra stringin her harfini dizinin gözlerine uygun biçimde yerleştirmek ve en sona `\0` koymaktır.

## 7. Karakter ile String Arasındaki Fark

Slayt şöyledir (ekrandan, 01:00:00):

```c
// Chars
char ch = 'a';   // one byte is allocated for 'a'
*p = 'a';        // OK
p = 'a';         // Illegal
// Strings
char *p = "a";   // two bytes allocated for "a"
*p = "a";        // INCORRECT
p = "a";         // OK
```

`char` tipinin genişliği 1 bayt olduğu için `ch` değişkenine 1 bayt ayrılır. `*p = 'a';`, `p`'nin gösterdiği gözün içine `a` yaz demektir; sorun yoktur. `p = 'a';` ise yanlıştır: İşaretçi bir adres ifadesidir; adres türündeki bir bilgiye değer atanmaya çalışılır.

`char *p = "a";` yazıldığında bu kez 2 bayt ayrılır, yani daha fazla yer harcanır. Çift tırnak içinde bir karakter de olsa on karakter de olsa, çift tırnak bunun birden fazla harf içerebilecek bir karakter katarı olduğu anlamına gelir. İşaretçi ise tek bir karakter gözünü gösterir; sonraki gözler de vardır ama oraya otomatik bir taşıma yapılmaz. Bu yüzden `*p = 'a';` doğruyken `*p = "a";` yanlıştır.

Hoca bunu Dev-C++'ta gösterdi (ekrandan, 01:05:00):

```c
char *p = "a";
*p = "b";
printf("p: %s\n",p);
```

Derleyici uyarı verdi, program çalıştırılınca da düzgün sonuç alınmadı. Hoca bu yapılan işin doğru olmadığını, verilen uyarıya dikkat etmek gerektiğini söyledi. `p = "b";` biçiminde yazıldığında ise program düzgün çalıştı.

## 8. scanf ile String Okumak ve Tampon Taşması

Karakter katarlarını elle tek tek yaratmak sıkıcıdır. Kullanıcıdan string almak için `scanf` kullanılabilir; iki şart vardır:

- Biçim belirteci olarak `%s` kullanılır.
- Önceden bir karakter dizisi tanımlanır. Her dizinin bir maksimum eleman sayısı olması gerektiği için `MAX_CHAR` gibi bir sabit tanımlanıp dizi o uzunlukta oluşturulur.

String ekrana yine `%s` ile yazdırılır. `scanf`'in güzel bir yanı, sona null karakterini kendisinin eklemesidir. Böylece 80 karakterlik alana daha kısa bir şey yazıldığında, kullanıcının girdiği harflerden sonra garip karakterler görülmez.

Hoca "Yapısal Programlama" girdiğinde yalnızca "Yapısal" okundu: `scanf` boşluğu da karakter girişinin bittiği yer olarak algılar.

### 8.1 Taşmayı zorlamak

Hoca 80 karakterlik yer ayrılmışken kullanıcının daha uzun bir şey girmesi durumunda sorun çıkacağını, ama farklı derleyicilerin farklı davranacağını söyledi ve denedi. Dizi önce 20'ye indirildi, uzun girişte görünür bir sorun çıkmadı.

<!-- BELİRSİZ: 01:10:12 civarı altyazı bozuk; hoca 10 elemanlık dizinin tamamı kullanıldığında null karakterinin konmadığını ve dizinin sonunun bilindiğini söylüyor gibi. -->

> **Ders sonrası not:** C'de `scanf("%s")` her zaman sona `\0` yazar. `char[10]` dizisine 10 karakter girilirse 11 bayt yazılır ve büyük olasılıkla dizi taşar. `printf("%s")` de dizinin boyutunu bilmez, yalnızca `\0` görene kadar yazar.

Dizi 5 karaktere indirildi ve tampon taşması (buffer overflow) gözlendi: 5 karakterlik yer ayrılmasına rağmen program fazladan karakterleri dizinin sonuna yazmaya devam etti. Hoca normalde orada kesmesini beklediğini söyledi. Ama program sağlıklı tepki vermedi: 4 harfli bir girişte tuşa basınca program hemen kapandı; 6 harfte sorun görülmedi; 10 karakterlik girişte ise tuşlara bastıkça program bekledi, çıkılamadı. Az taşma çok yan etki yapmıyor, ama sonrasında tepki epey gecikiyor.

Hoca bunun bir açıklamasını da önerdi: Derleyici arka planda küçük bir alan istense bile örneğin 16 elemanlık (ikinin bir katı kadar) yer ayırıyor olabilir. Hangi durumda olursa olsun mantıklı olan maksimum karakter sayısını geçmemektir. Bu keşifler derleyiciye ve derleyicinin ürettiği kodun çalıştığı işletim sistemine göre değişir. Nitekim aynı kodu deneyen bir öğrenci Linux'ta core dump hatası aldığını yazdı.

> **Ek bilgi (derste anlatılmadı):** `scanf`'e alan genişliği verilerek taşma önlenebilir: `char str[20]` için `scanf("%19s", str);` en fazla 19 karakter okur ve yer kalan son göze `\0` koyar.

## 9. Kendi strLen Fonksiyonumuz

Bir karakter katarına 80 karakterlik yer ayrılmış olabilir, ama içine örneğin 16 karakterlik bir şey yazılmış olabilir. Kaç harf olduğunu öğrenmek için `string.h`'de `strlen` fonksiyonu vardır. Hoca onunla çakışmasın diye kendi fonksiyonunu `strLen` adıyla yazdı. İkinci mantıksal kelimenin büyük harfle başlaması okumayı kolaylaştırır; buna camel casing denir. Hoca adın nereden geldiğini de anlattı: Devenin bir ya da iki hörgücü vardır; kelimelerin ortasındaki her büyük harf düz hizada bir hörgüç gibi durur.

Slayt şöyledir (ekrandan, 01:15:00):

```c
int strLen( char *str ) {
    int i=0;
    while( str[i] != '\0' ) {
        i++;
    }
    return i;
}
```

Slayttaki açıklama: Dizinin her elemanı null karakterine gelene kadar tek tek denetlenir. Null karakterinin değeri sıfırdır ve `while` koşulunu yanlış yapar; `str[i]`'nin başka her değeri koşulu doğru yapar. Null karaktere gelinince döngüden çıkılır ve son indis değeri `i` döndürülür.

Hoca, fonksiyonlarda işaretçi tanımının henüz görülmediğini ama bunun çok karmaşık olmadığını söyleyip fonksiyonu `main`'in üstüne yazdı. Denemede "BirDenemeDaha" girildi ve "It has 13 characters" çıktısı alındı (ekrandan, 01:20:00). İlk denemede yanlış sonuç gelmişti; hoca bunun nedeninin girişi iki kez yapıştırmış olması olduğunu fark etti. Stringi girdikten sonra basılan Enter'ın komut satırında alt satıra geçmeyi de sağladığını gösterdi.

Aşağıdaki program ajan tarafından slayttaki fonksiyon ve ekrandaki çıktı metinlerine göre yazıldı, `gcc -Wall` ile derlendi ve çalıştırıldı ("BirDenemeDaha" için 13 verdi).

```c
#include <stdio.h>
#define MAX_CHAR 80

int strLen(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int main(void) {
    char str[MAX_CHAR];
    printf("Enter a string: ");
    scanf("%s", str);
    printf("You wrote:%s\n", str);
    printf("It has %d characters\n", strLen(str));
    return 0;
}
```

Hoca, bu örnekte `string.h` include edilmediği için çakışma olmadığını; include edilen durumlarda aynı adı kullanmanın çakışmaya yol açacağını, adın bu yüzden büyük `L` ile yazıldığını hatırlattı.

## 10. string.h İçindeki Diğer Fonksiyonlar

Bütün fonksiyonları kendimiz yazmayacağız; `string.h`'de işe yarayan birçok fonksiyon tanımlıdır. Slayt şöyledir (ekrandan, 01:25:00):

```c
char* strcpy(char* szCopyTo, const char* szSource)
char* strncpy(char* szCopyTo, const char* szSource, size_t sizeMaxCopy)
char* strcat(char* szAddTo, const char* szAdd)
char* strncat(char* szAddTo, const char* szAdd, size_t sizeMaxAdd)
int strcmp(const char* sz1, const char* sz2)
int strncmp(const char* sz1, const char* sz2, size_t sizeMaxCompare)
```

Slayta göre diğerleri `string.h` dosyasında ve herhangi bir C kitabında ya da sitesinde bulunabilir.

### 10.1 strcpy ve strncpy

`strcpy` (string copy), kaynak olarak verilen karakter katarını hedef olarak verilen adrese kopyalar ve kopyaladığı adresin başlangıcını gösteren bir işaretçi döndürür. Hedef bir sabit string olamaz; sabit stringlerin üzerine kopyalama yapılamaz.

Hoca, hedef adresin neden ayrıca döndürüldüğünü sordu ve `string.h` dosyasına baktı; dosyada yalnızca fonksiyon başlıkları vardı, açıklama yoktu.

**Soru (hocanın sorusu):** `strcpy` hedefi zaten parametre olarak aldığı hâlde neden hedefin adresini döndürüyor? **Cevap (bir öğrenci):** İlk parametre olarak bellekte o anda yer ayrılan bir alan verilebiliyor; o alanın adresi bize geri veriliyor. Hoca bunu doğruladı: `malloc` ile o anda bir alan açılıp oraya kopyalama yapılırsa, `malloc`'un döndürdüğü başlangıç adresi başka bir yerde saklanmamış olur; `strcpy`'nin döndürdüğü adres sayesinde bu alan kaybolmaz. `malloc` ileride işlenecek.

> **Ek bilgi (derste anlatılmadı):** Dönüş değeri çağrıları zincirlemeyi de sağlar; örneğin `strcat(strcpy(hedef, "Yapisal "), "Programlama");` önce kopyalar, sonra aynı hedefin sonuna ekler.

Hedefe kaynağın tamamı değil de belli sayıda karakter kopyalanmak istenirse `strncpy` kullanılır; `n` adet karakter kopyalanır. Hoca, buraya verilen `n`'nin bir boyut (`size_t`) olduğunu, Unicode destekleyen bir platformda bir karakter birden fazla baytla gösterilse de fonksiyonun doğru çalışıp yalnızca `n` karakter kopyalayacağını söyledi.

> **Ders sonrası not:** `strncpy` büyük olasılıkla `n` karakter değil `n` bayt (`char`) kopyalar; çok baytlı bir karakteri tanımaz ve onu ortasından bölebilir. Ayrıca kaynak `n` karakterden uzunsa hedefin sonuna `\0` eklemez.

### 10.2 strcat ve strncat

`strcat` (concatenate), bir stringin sonuna başka bir stringi ekler. Stringin tamamı değil de ilk `n` karakteri eklenmek istenirse `strncat` kullanılır.

### 10.3 strcmp

İki stringi karşılaştırmak, örneğin öğrencileri isimlerine göre sıralamak için gerekir. Stringler sözlük sırasına göre karşılaştırılır: Önce ilk harflere bakılır; aynı değilse sözlükte daha önde olan daha küçüktür. İlk harfler aynıysa ikinci harflere bakılır; farklı bir harf bulunana kadar böyle devam edilir. İki string tamamen aynıysa 0 döner.

`strcmp` büyük/küçük harf duyarlıdır (case sensitive). Türkçe karakterler ise bu platformda düzgün görüntülenemediği için denenmedi; onların sonucu da ASCII kodları neyse ona göre çıkar.

## 11. strcmp ile Karşılaştırma Denemeleri

Hoca `string.h`'yi ekleyip iki string okuyan ve `strcmp(str1, str2)` sonucunu yazan küçük bir program yazdı. Aşağıdaki program ajan tarafından ekrandaki çıktı metinlerine göre yazıldı, `gcc -Wall` ile derlendi ve çalıştırıldı.

```c
#include <stdio.h>
#include <string.h>

int main(void) {
    char str1[64], str2[64];
    printf("Enter 1st string: ");
    scanf("%s", str1);
    printf("Enter 2nd string: ");
    scanf("%s", str2);
    printf("Comparison result: %d\n", strcmp(str1, str2));
    return 0;
}
```

Derste yapılan denemeler:

- "Baba" ile "Anne": Sonuç 1 oldu (ekrandan, 01:30:00). B harfi A'dan sonra geldiği için ilk string daha büyüktür; ilk string "ben daha büyüğüm" der ve pozitif sonuç döner.
- Hoca ikinci bir örnekte yine büyük olanı önce yazdığı için yine 1 aldı. İlk stringi küçük olacak şekilde girince negatif, yani -1 sonucu geldi. <!-- BELİRSİZ: bu denemelerde girilen kelimeler altyazıda net değil ("cadde"/"ara", "karar"/"alfabe" gibi duyuluyor). -->
- İki string içerik olarak tamamen aynıyken 0 döndü.
- Aynı kelimenin küçük harfle başlayan hâli ilk, büyük harfle başlayan hâli ikinci string olarak girildi; sonuç pozitif 1 oldu. Çünkü önce büyük A, B, C harfleri sıralanır, sonra küçük a, b, c harfleri gelir. Fonksiyon büyük A ile küçük a arasında ayrım yapar.

Hoca, farklı platformların farklı sonuç üretebileceğini, burada ilk string büyükse her durumda 1, küçükse -1 döndüğünü söyledi.

> **Ek bilgi (derste anlatılmadı):** C standardı `strcmp` için yalnızca sonucun işaretini (pozitif, negatif, sıfır) garanti eder. Ajanın gcc/glibc ile yaptığı denemede "Baba"/"Anne" için 1, ters sırada -1 çıktı, küçük/büyük harf örneğinde ise 32 (küçük ve büyük harfin ASCII farkı) çıktı. Bu yüzden sonuç `== 1` ile değil `> 0` ile sınanmalıdır.

## 12. Örüntü Arama Örneği: indexOfV1

### 12.1 Problem

Hoca daha değişik bir kod yazmak istediğini söyleyip slayttaki "Pattern Matching Example" sorusuna geçti. Kullanıcıdan iki karakter katarı alınacak, ikincisi birincinin içinde aranacak. Bulunursa hangi konumdan itibaren bulunduğu döndürülecek, bulunmazsa -1 döndürülecek. Sorunun şartı işaretçi işlemlerinin kullanılmasıdır, yani yalnızca dizi işlemi yapılmamalıdır. `string.h`'de bu işi yapan `strstr` fonksiyonu da vardır, ama örnek olsun diye önce kendimiz yazacağız.

Bundan sonra fonksiyon kullanmakta sakınca görülmedi. Hoca bir diziyi doğrudan bir işaretçi parametresine aktarmada bir sakınca olmadığını söyledi. `main` ders notlarına hazır yazılmıştı: İki karakter dizisi tanımlanır, bulunan konumu tutan bir değişken vardır, iki string kullanıcıdan istenir, fonksiyon çağrılır ve sonuç yazdırılır.

### 12.2 Algoritmanın mantığı

Hoca mantığı önce bir örnek üzerinde konuştu: "istanbul" içinde "ana" aransın.

- Büyük stringin ilk karakteri ile aranan stringin ilk karakterine bakılır. Tutmuyorsa arama buradan başlamıyor demektir; büyük stringin bir sonraki karakterine geçilir, küçük stringde ise yine baştan başlanır.
- i ile a tutmaz, s ile a tutmaz, t ile a tutmaz.
- 3. konumda a ile a tutar. İkinci karakterlere bakılır: n ile n tutar. Üçüncü karakterlere bakılır: b ile a tutmaz.
- Şimdi aramaya nereden devam edilmeli? Eşleşme 3. konumda başlamıştı ve karşılaştırma 5. indise (b) kadar ilerledi. Ama aramaya devam edilmesi gereken yer 4. indistir (n).

Bu yüzden büyük stringde iki ayrı bilgi tutmak gerekir: Biri o anda hangi karakterden itibaren arama yapıldığı, diğeri eşleşme bulunduğunda ileriye doğru bakarken gelinen yer. Küçük stringde ilerlemek için de bir sayaç gerekir. Yani üç sayaç tutulabilir, ama küçük stringin uzunluğu belli olduğu için buna gerek yoktur. Kaç karakterin eşleştiği sayılırsa, bu sayı küçük stringin uzunluğuna eşit olduğunda "buldum" denir. Her seferinde string uzunluğu fonksiyonunu çağırmak verimli olmayacağı için uzunluklar baştan değişkenlere alınır ve eşleşen karakter sayısı için `matchCount` adlı bir değişken tutulur.

Hoca, önce normal dizi işlemleriyle düşünüp sonra bunu işaretçi koduna çevirmenin yararlı olabileceğini, bunun kişinin düşünme tarzına bağlı olduğunu söyledi. İşaretçi kullanıldıkça gereken indeks değişkeni sayısı azalır.

### 12.3 Döngü sınırı

Dışarıda `for` yerine `while` döngüsü de kurulabilir; `for` döngüsü `while` cinsinden, `while` da `for` cinsinden yazılabilir. "Bulana ya da sonuna gelene kadar ara" biçiminde farklı bir algoritma da kurulabilir; problemin farklı çözümleri vardır.

Arama en kötü ihtimalle iki stringin uzunlukları farkı kadar tekrarlanır. "istanbul" içinde "ana" ararken 5. indise gelindiğinde ("bul") eşleşme yoksa, 6. indisten itibaren bakmaya gerek yoktur; çünkü artık ikinci stringin sığacağı kadar yer kalmamıştır. Daha fazla tekrarlanırsa, ikinci string yeterince uzunsa stringin sonundan taşılır ve buffer overflow ya da core dump gibi sorunlar çıkar.

> **Hocanın vurgusu:** Koşulda `<=` kullanılmalıdır. `<` yazılırsa son konum denenmez; aranan string büyük stringin sonundaysa bulunması gerekirken bulunamaz.

### 12.4 Kod

Slayttaki birinci çözüm şöyledir (ekrandan, 01:35:00):

```c
int indexOfV1( char *ptr1, char *ptr2) {
    int i, matchCount = 0;
    int len1 = strlen(ptr1), len2 = strlen(ptr2);
    for( i=0; i<=len1-len2; i++ ) {
        while( *ptr1 == *ptr2 && matchCount != len2 ) {
            matchCount++; ptr1++; ptr2++;
        }
        if( matchCount == len2 ) return i;
        else {
            ptr1 -= (matchCount-1);
            ptr2 -= matchCount; matchCount = 0;
        }
    }
    return -1;
}
```

Fonksiyona `main`'den birinci parametre olarak `str1`, ikinci parametre olarak `str2` dizisi gönderilir; bu yüzden başta iki işaretçi iki stringin ilk adreslerini gösterir. İşaretçilerin gösterdiği değerler eşitse sonraki harflere de bakılır. Bu, eşleşen eleman sayısı küçük stringin uzunluğuna ulaşana kadar sürer. Arada bir fark görülürse ikinci stringte daha ileri gitmeye gerek yoktur; birinci stringte kaldığımız yerden bakmaya devam edilir.

`else` kısmı dikkatle okunmalıdır. Hiç eşleşme yoksa `matchCount` 0'dır ve `ptr1 -= (0-1)` ifadesi `ptr1`'i bir ilerletir; `ptr2` ise `0` kadar geri gider, yani yerinde kalır. Kısmi eşleşme varsa `ptr1` eşleşen karakter sayısının bir eksiği kadar geri alınır; böylece arama eşleşmenin başladığı yerin bir sonrasından sürer. `ptr2` eşleşen karakter sayısı kadar geri alınıp küçük stringin başına döner. `matchCount` sıfırlanmayı unutmamalıdır.

## 13. indexOfV1'i Tablo Üzerinde İzlemek

Hoca izlemeyi Excel'de yaptı: birinci satıra indisleri, ikinci satıra `str1`'i, üçüncü satıra `str2`'yi yazdı. `ptr1`'in gösterdiği göz sarı, `ptr2`'nin gösterdiği göz yeşil boyandı (ekrandan, 01:45:00 ve 01:50:00).

| İndis | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|---|---|---|---|---|---|---|---|---|---|---|
| str1 | i | s | t | a | n | b | u | l | `\0` | r |
| str2 | a | n | a | | | | | | | |

`str1`'in 9. gözündeki `r` diziden önceden kalan bir karakterdir; `\0`'dan sonra geldiği için stringe dahil değildir. `len1 = 8`, `len2 = 3` olduğundan dış döngü i = 0'dan 5'e kadar döner.

### 13.1 Hiç eşleşme olmayan ve kısmi eşleşmeli durum ("ana")

- i = 0: `ptr1` i'yi, `ptr2` a'yı gösterir. Eşit değil; `while`'a girilmez. `matchCount` 0, `return` çalışmaz. `else`'te `ptr1` bir ilerler, `ptr2` yerinde kalır. Daha önce eşleşme olsaydı `ptr2`'yi başa çekmek gerekecekti; bu unutulmamalıdır.
- i = 1: s ile a; eşleşme yok. Bir önceki iterasyonla aynı sonuç: `ptr2` a'da kalır, `ptr1` bir ilerler.
- i = 2: t ile a; yine eşleşme yok.
- i = 3: a ile a eşit ve `matchCount` (0) `len2`'ye (3) eşit değil; `while`'a girilir. `matchCount` 1 olur, iki işaretçi de bir ilerler. Hoca bir sonraki aramanın başlayacağı yeri (4. indis) mavi ile işaretledi, çünkü oraya geri dönmek gerekecek.
- n ile n eşit; `matchCount` 2 olur, işaretçiler bir ilerler.
- b ile a eşit değil; `while`'dan çıkılır. `matchCount` (2) `len2`'ye (3) eşit değil, bu yüzden konum döndürülmez. Zaten döndürülmemesi gerekir, çünkü bulunamadı.
- `else`'te `ptr1 -= (2-1)`: `ptr1` bir geri gider ve 4. indisi (n) gösterir. `ptr2 -= 2`: `ptr2` iki geri gidip küçük stringin başına döner. `matchCount` sıfırlanır.
- i = 4: Arama, mavi ile işaretlenen yerden, yani doğru yerden sürer. Küçük stringte geri gitmenin de, büyük stringte kalınan yerden devam etmenin de doğru çalıştığı görülür.
- Sonraki iterasyonlarda eşleşme bulunmaz. i = 5'te "bul" ile "ana" eşit olmadığından, i 6 olunca döngüden çıkılır ve -1 döner.

Hoca aranın saatini geçmiş olmasına rağmen bu ilerlemeyi yarıda bırakmak istemediğini söyleyip izlemeyi bitirdi.

### 13.2 Eşleşmenin bulunduğu durum ("anb")

Aradan sonra aynı izleme "istanbul" içinde "anb" için yapıldı. Hoca, eşleşme olmayan ve kısmi eşleşme olan durumların zaten görüldüğünü söyleyip doğrudan i = 3, `matchCount` = 0 durumundan başladı (ekrandan, 02:10:00).

- a ile a eşit, `matchCount` `len2`'ye ulaşmadı; `while`'a girilir. `matchCount` 1 olur, işaretçiler ilerler.
- n ile n eşit; `matchCount` 2 olur, işaretçiler ilerler.
- b ile b eşit; `matchCount` 3 olur, işaretçiler ilerler.
- Şimdi `ptr1` u'yu, `ptr2` `\0`'ı gösterir (ekrandan, 02:20:00). Değerler eşit değil; koşul yanlış olur.

Hoca burada `\0`'ın rolünü de tartıştı. Önce `\0` olmasaydı dizinin geri kalanında anlamsız karakterler olabileceğini söyledi, sonra sözünü düzeltti: Stringler `scanf` ile `%s` kullanılarak girildiği için `\0` zaten eklenmiştir. Aranan string büyük stringin tam sonunda olsaydı (iki işaretçi de `\0`'ı gösterseydi) karakterler eşit çıkardı, ama bu kez `matchCount != len2` koşulu (3, 3'e eşit değildir) yanlış olacağı için yine `while`'dan çıkılırdı. Yani son karakterde bulunsa da fonksiyon doğru çalışır.

`while`'dan çıkınca `matchCount == len2` (3 == 3) doğrudur ve `i` yani 3 döndürülür; fonksiyon sonlanır.

### 13.3 Kodu çalıştırmak

Hoca fonksiyonu ve `main`'i Dev-C++'a yapıştırıp denedi:

- "istanbul" içinde "ana": bulunamadı, -1 döndü.
- "istanbul" içinde "anb": 3. konumda bulundu (ekrandan, 02:15:00). İndisler 0, 1, 2, 3 diye sayılır. Hoca, son kullanıcıya gösterilecekse "4. harften itibaren bulundu" demek için `i+1` yazdırılabileceğini, `if (pozisyon == -1)` ile "bulunamadı" mesajı verilerek çıktının güzelleştirilebileceğini söyledi.
- Başta bir eşleşme 0. konumda bulundu. <!-- BELİRSİZ: bu denemede aranan string altyazıda net değil. -->
- "bul": 5. konumda bulundu.
- Taşma olup olmadığını görmek için "ula" arandı: bulunamadı, ama program "istanbul"un dışına taşmadı ve çökmeden çalıştı.

Aşağıdaki program ajan tarafından yazıldı: `indexOfV1` slayttan, `indexOfV2` bir sonraki bölümdeki anlatımdan, `main` ise ekrandaki istem metinlerinden alındı. `gcc -Wall` ile uyarısız derlendi; "istanbul" içinde ana, anb, ist, bul, ula ve t arandığında iki sürüm de sırasıyla -1, 3, 0, 5, -1, 2 verdi.

```c
#include <stdio.h>
#include <string.h>
#define MAX 64

int indexOfV1(char *ptr1, char *ptr2) {
    int i, matchCount = 0;
    int len1 = strlen(ptr1), len2 = strlen(ptr2);
    for (i = 0; i <= len1 - len2; i++) {
        while (*ptr1 == *ptr2 && matchCount != len2) {
            matchCount++; ptr1++; ptr2++;
        }
        if (matchCount == len2) return i;
        else {
            ptr1 -= (matchCount - 1);
            ptr2 -= matchCount; matchCount = 0;
        }
    }
    return -1;
}

int indexOfV2(char *ptr1, char *ptr2) {
    char *ptr = strstr(ptr1, ptr2);
    if (ptr != NULL) return ptr - ptr1;
    return -1;
}

int main(void) {
    char str1[MAX + 1], str2[MAX + 1];
    printf("Enter the 1st string (Max. %d characters): ", MAX);
    scanf("%64s", str1);
    printf("Enter the 2nd string (Max. %d characters): ", MAX);
    scanf("%64s", str2);
    printf("V1 found at: %d\n", indexOfV1(str1, str2));
    printf("V2 found at: %d\n", indexOfV2(str1, str2));
    return 0;
}
```

### 13.4 İşaretçi aritmetiği üzerine bir uyarı

Hoca örnekten şu dersi çıkardı: İşaretçi bir dizinin elemanları içinde belli bir yeri gösterir. Karşılaştırma örneğinde işaretçiler gerektiğinde ileri, gerektiğinde geri götürüldü. Hem `str1`'de hem `str2`'de ileri götürülen işaretçiyi gerektiği kadar geri götürmeyi unutmamak bu örneğin püf noktasıydı; kaç adım geri gidileceği `matchCount` tutularak bilindi.

Hoca bunu kasetçalara benzetti: Kasetten müzik dinlerken bir noktada sayacın değerini aklınızda tutarsınız. İlerledikten sonra bir şarkıyı yeniden dinlemek isterseniz, geri sararken aklınızdaki başlangıç değerine ulaşıp ulaşmadığınıza bakmanız gerekir.

> **Hocanın vurgusu:** İşaretçi ilerleterek işlem yaparken geri gitmek de gerekebileceğini düşünün. Ne kadar geri gideceğinizi hesaplamanız ya da bir değişkende tutmanız gerektiğini kafanıza yazın ve kodu ile algoritmayı buna göre düşünün.

## 14. strstr ile Daha Kısa Çözüm: indexOfV2

`string.h`'deki `strstr` fonksiyonu bir string içinde diğer stringi arar. Bulursa aranan stringin büyük string içinde başladığı yeri gösteren bir işaretçi döndürür; bulamazsa null işaretçi döndürür.

Hoca kodun bununla nasıl kısaltılabileceğini örnek vaka üzerinden düşündü. Burada işaretçi ilerletme yapılmayacak, yalnızca işaretçi aritmetiği kullanılacak. "istanbul" içinde "anb" arandığında `strstr` 3. indisi (tabloda mavi işaretlenen göz) gösteren bir işaretçi döndürür. Bu konumun `str1`'in kaçıncı konumu olduğu adres farkıyla bulunur: Fonksiyon başında `ptr1` stringin başını (örneğin bellekte 1000 numaralı gözü) gösterir, `strstr`'ün döndürdüğü işaretçi ise 1003 numaralı gözü gösterir. İki adres arasındaki fark (3) konumu verir.

Çıkarma yapılmadan önce dönen işaretçinin `NULL` olup olmadığına bakılmalıdır. Null işaretçiyle bu çıkarma yapılırsa program çöker. Dönen işaretçi null değilse en az ilk konumda ya da daha ileride bir yerdedir, böylece negatif bir sonuç elde edilmez. Hoca çözümü slaytta gösterdi; yalnızca fonksiyon başlığı karede okunuyor (ekrandan, 02:25:00). Kod, hocanın anlatımına göre 13.3'teki programda verilmiştir.

<!-- BELİRSİZ: indexOfV2 slaytının gövdesi karede yok; kod altyazıdaki anlatımdan kuruldu. -->

Hoca "istanbul" içinde "ana" ve "anb" ile denedi; bulduğu durumda konumu, bulamadığı durumda -1 aldı. İkinci string birincinin dışına taşmaya yol açar mı diye de baktı; sorun çıkmadı. Derste bir de "t" arandı (ekrandan, 02:25:00).

Soru da işaretçi işlemlerinin kullanılmasını istiyordu; burada da işaretçi işlemi (adres farkı) kullanıldı. Hoca şaka yollu, soruda "`string.h` fonksiyonlarını kullanmayın" denmezse bu yanıtın da kabul edilebilir bir çözüm olduğunu söyledi.

> **Hocanın vurgusu:** `indexOfV1`'i de `indexOfV2`'yi de öğrenmek gerekir, çünkü ikisinde farklı işaretçi işlemleri yapılıyor: birinde adım adım ilerleyip gerektiğinde geri gitme, diğerinde daha basit adres farkı.

## 15. Çok Boyutlu Diziler ve İşaretçi Aritmetiği

Bir boyutlu dizinin kullanımı ve içinde işaretçi işlemlerinin nasıl yapılacağı görüldü. Ama 2, 3 ve daha fazla boyutlu diziler de tanımlanabilir. Bu durumda dizinin herhangi bir elemanına doğru işaretçi aritmetiğiyle nasıl ulaşılacağı incelendi. Hoca işaretçi dizilerine (array of pointers) çok az girileceğini, onları dinamik bellek ayırma ile birlikte yapmanın daha mantıklı olacağını söyledi.

### 15.1 İki boyutlu dizi: dizilerin dizisi

`int ar[3][5];` 3 satır ve 5 sütunluk iki boyutlu bir dizi tanımlar. Hoca bunu Excel'de kutucuklarla gösterdi: satır indisleri 0, 1, 2; sütun indisleri 0-4 (ekrandan, 02:30:00). `ar[1][3]` ikinci satırın dördüncü gözünü gösterir.

Aynı yapı 5 elemanlı 3 tane tek boyutlu dizi olarak da yorumlanabilir. Hoca, böyle düşünüldüğünde iki boyutlu dizilerdeki işaretçi mantığının kafada daha kolay oturacağını söyledi.

### 15.2 ar[1][2] ifadesinin işaretçi biçimleri

Tablodaki ifadeler şöyledir (ekrandan, 02:40:00):

- `ar[0]` birinci satırı, `ar[1]` ikinci satırı ifade eder. `ar[1]`, ikinci 5 elemanlı tek boyutlu dizidir.
- `ar[1][2]`, `*(ar[1]+2)` ve `*(*(ar+1)+2)` aynı elemanı gösterir.
- `ar[1]` ile `*(ar+1)` aynı ifadedir.

Parantezlemede içteki parantezin önce işlendiği unutulmamalıdır. `ar[1]` bir satırın başlangıç adresi gibi davranır; ona 2 eklemek o satırda iki göz ilerlemek demektir. Yıldız ve parantez konmadan `ar[1]+2` yazılırsa elde edilen bir adrestir, değer değil; bu tip uyuşmazlığı (incompatible type) uyarısına yol açar.

Tek başına `ar`, dizinin adıdır ve dizinin başlangıcını, yani `ar[0][0]`'ın bulunduğu yeri gösterir. `ar+1`, iki boyutlu dizide bir satır ilerlemek demektir; çünkü `ar` 5 elemanlı 3 diziden oluşur. Köşeli parantez içindeki bir sayı ile yıldızlı parantez içinde eklenen sayı aynı anlama gelir. Bu eşdeğerlik bilindiğinde ifadeler birbirinin yerine konarak genişletilebilir ya da daraltılabilir. Hoca bunun biraz hileli olduğunu, ama odaklanıp düşünüldüğünde bulunabileceğini söyledi.

### 15.3 Üç boyutlu dizi

`char x[3][4][5];` 4 satır 5 sütunluk 3 tane matris gibi düşünülebilir; ya da 5 elemanlık 4 tek boyutlu dizinin birleşiminden 3 tane yapılmış gibi. Tablodaki ifade (ekrandan, 02:50:00):

```c
x[1][2][3]  /* ile */  *(*(*(x+1)+2)+3)  /* aynıdır */
```

İlk boyutta 1 ilerlenir ve parantez içine alınıp yıldızlanır; sonraki `+2` ikinci boyutta ilerletir, o da parantezlenip yıldızlanır; son `+3` üçüncü boyutta ilerletir. İndisler soldan sağa aynı sırada kalır, ters dönmez. Hocanın ipucu: Yalnızca işaretçi işlemleriyle bir göze erişmek için iki boyutlu dizide iki, üç boyutlu dizide üç yıldız gerekir. İfadeler tamamen indisle, tamamen işaretçiyle ya da ikisinin karışımıyla yazılabilir.

Ajan, bu eşdeğerlikleri küçük bir programla `gcc -Wall` altında denedi: `ar[1][2]`, `*(ar[1]+2)` ve `*(*(ar+1)+2)` aynı değeri; `x[1][2][3]` ile `*(*(*(x+1)+2)+3)` aynı karakteri verdi.

## 16. Çok Boyutlu Dizilerin İlklendirilmesi

Tek boyutlu dizilerde elemanlar yazılarak tanım ve ilklendirme birlikte yapılabiliyordu. İki ya da üç boyutlu dizilerde de bu yapılabilir. Slayt şöyledir (ekrandan, 02:45:00):

```c
int exap[5][3] = { { 1, 2, 3 },
                   { 4 },
                   { 5, 6, 7 } };
```

```text
1 2 3
4 0 0
5 6 7
0 0 0
0 0 0
```

```c
int exap[5][3] = { 1, 2, 3,
                   4,
                   5, 6, 7 };
```

```text
1 2 3
4 5 6
7 0 0
0 0 0
0 0 0
```

İki boyutlu matris, bir boyutlu dizilerin dizisidir. Birinci örnekte en dıştaki süslü parantez bütün diziyi, içindeki ilk süslü parantez birinci satırı gösterir. `{4}` yazılınca ikinci satırın yalnızca birinci elemanı verilmiş olur; geri kalanlar 0 olur. Önceki hafta tek boyutlu dizide bir eleman yazıldığında geri kalanların sıfırlandığı görülmüştü.

İkinci örnekte iç süslü parantezler yoktur. Girinti ya da boşluklardan bağımsız olarak yazılan ilk değer matrisin ilk elemanı, ikinci değer ikinci elemanı olur; bir satır dolunca sonraki satıra geçilir. 5x3'lük matriste toplam 15 eleman vardır; yazılmayanlar 0 olur. Girinti bilgisayar için önemli değildir, yalnızca okunabilirlik içindir. Ama farklı parantezlemeler farklı sonuçlar doğurur, bu yüzden parantezleme önemlidir.

Ajan iki tanımı derleyip yazdırdı; çıktılar slayttaki tablolarla aynıdır. gcc ikinci tanım için "missing braces around initializer" uyarısı verir; bu uyarı kodun geçersiz olduğu anlamına gelmez, iç parantez kullanılmasını önerir.

## Örnek Sorular

**Soru 1** (ekrandan, 01:35:00; derste sözlü, 01:33:27): İkinci stringi birinci stringin içinde arayan bir fonksiyon yazın. Bulunursa başladığı konumu, bulunmazsa -1 döndürsün. İşaretçi işlemleri kullanılsın.

> **Çözüm (derste verildi):** Bölüm 12.4'teki `indexOfV1` (işaretçileri ilerletip `matchCount` kadar geri alma) ya da Bölüm 14'teki `indexOfV2` (`strstr` ve adres farkı). "istanbul" içinde "anb" için sonuç 3, "ana" için -1'dir.

**Soru 2** (ekrandan, 00:35:00): Aşağıdaki satırlardan hangileri derlenmez, hangileri derlenir ama hatalıdır?

```c
char array[10];
char *ptr1="10 spaces";
char *ptr2;
array = "not OK";
array[5] = 'A';
ptr1[8] = 'r';
*ptr2 = "not OK";
ptr2="OK";
```

> **Çözüm (derste verildi):** `array = "not OK";` derlenmez, çünkü dizinin adı bir adrestir ve ona atama yapılamaz. `*ptr2 = "not OK";` tip uyuşmazlığıdır (`char`'a `char *` atanıyor). `array[5] = 'A';` derlenir ama dizi doldurulmadığı için anlamsız sonuç verir. `ptr1[8] = 'r';` hatalıdır (Bölüm 6'daki ders sonrası nota bakın). `ptr2 = "OK";` geçerlidir.

**Soru 3** (ekrandan, 01:00:00): `char ch='a'`, `*p='a'`, `p='a'`, `char *p="a"`, `*p="a"`, `p="a"` ifadelerinden hangileri doğrudur? Kaç bayt ayrılır?

> **Çözüm (derste verildi):** `'a'` için 1 bayt, `"a"` için 2 bayt ayrılır. `*p='a'` ve `p="a"` doğrudur. `p='a'` geçersizdir (adrese karakter atanıyor). `*p="a"` yanlıştır (tek karakter gözüne string atanıyor).

**Soru 4** (derste sözlü, 01:29:46; ekrandan, 01:30:00): `strcmp("Baba", "Anne")` ne döndürür? Argümanların yeri değişirse ne olur? İki string aynıysa ne olur?

> **Çözüm (derste verildi):** İlk string sözlükte daha sonra geldiği için pozitif (Dev-C++'ta 1); yer değişirse negatif (-1); aynıysa 0. Standart yalnızca işareti garanti eder.

**Soru 5** (ekrandan, 02:40:00): `int ar[3][5];` için `ar[1][2]` elemanını yalnızca işaretçi aritmetiğiyle nasıl yazarsınız?

> **Çözüm (derste verildi):** `*(ar[1]+2)` ya da `*(*(ar+1)+2)`.

**Soru 6** (ekrandan, 02:50:00): `char x[3][4][5];` için `x[1][2][3]` elemanını yalnızca işaretçi aritmetiğiyle yazın.

> **Çözüm (derste verildi):** `*(*(*(x+1)+2)+3)`.

**Soru 7** (ekrandan, 02:45:00): `int exap[5][3] = { {1,2,3}, {4}, {5,6,7} };` ve `int exap[5][3] = { 1,2,3, 4, 5,6,7 };` tanımlarından sonra matrisler nasıl görünür?

> **Çözüm (derste verildi):** Birincisi 1 2 3 / 4 0 0 / 5 6 7 / 0 0 0 / 0 0 0; ikincisi 1 2 3 / 4 5 6 / 7 0 0 / 0 0 0 / 0 0 0.

**Soru 8** (ekrandan, 00:25:00): 36, 96, 22, 94, 85, 73, 47, 88, 48, 73 dizisi derste yazılan sıralama döngüsüyle sıralanırken `i=0, j=2` adımından sonra dizi nasıl görünür?

> **Çözüm (derste verildi):** 36 ile 22 yer değiştirir: 22, 96, 36, 94, 85, 73, 47, 88, 48, 73.

## Dersin Toparlaması

Bu derste diziler üzerinde bir sıralama programı yazıldı. Eleman sayısının `#define` ile tanımlanması, yer değiştirmede geçici değişken kullanımı, döngü sınırlarında off-by-one hatasından kaçınma ve sonucu girilen elemanlarla karşılaştırarak test etme işlendi. Ardından C'de stringin `\0` ile biten bir karakter dizisi olduğu, dizi adına atama yapılamayacağı, karakter ile string arasındaki bayt farkı, `scanf("%s")` ile okuma ve tampon taşmasının derleyiciye göre değişen etkileri görüldü. `strLen` fonksiyonu yazıldı; `strcpy`, `strncpy`, `strcat`, `strncat`, `strcmp` ve `strstr` tanıtıldı.

Dersin ağırlıklı örneği örüntü aramaydı: İşaretçileri ilerletip gerektiğinde geri alan `indexOfV1` ve `strstr` ile adres farkını kullanan `indexOfV2`. Son olarak çok boyutlu dizilerin "dizilerin dizisi" olarak yorumlanması, `a[i][j]` = `*(*(a+i)+j)` eşdeğerliği ve ilklendirmede süslü parantezlerin etkisi anlatıldı. Hoca, bir sonraki derse işaretçiler konusunu hatırlatarak başlamayı ve kalan yerden devam etmeyi planladığını söyledi. Fonksiyonlar, fonksiyonlara dizi aktarma ve dinamik bellek ayırma (`malloc`) ileride işlenecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
