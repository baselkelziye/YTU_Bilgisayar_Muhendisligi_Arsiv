# Ders 4 Genişletilmiş Notu: Uygulama 1: Pisagor Üçlüsü, İşaretçi Tekrarı ve İşaretçiyle Alt Kod Arama

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Uygulama oturumu ve algoritmik düşünme
- 2. Soru 1: Dizide Pisagor üçlüsü arama
- 3. Soru 2: İşaretçi konusunun hızlı tekrarı
- 4. Soru 3: İşaretçiyle alt kod arama
- 5. Kod yazım kuralları
- Örnek Sorular
- Dersin Toparlaması

## 1. Uygulama oturumu ve algoritmik düşünme

Bu kayıt dönemin ilk uygulama oturumudur. Oturumda üç soru çözülür. Birinci soru dizi ve döngülerle ilgilidir. İkinci soru, derste girişi yapılan işaretçi (pointer) konusunun kısa bir tekrarıdır. Üçüncü soru hem bu konuları hem de sonraki derslerde ayrıntısıyla görülecek işaretçi ile dizi ilişkisini birleştirir. Soruların listesi ekranda bir Word belgesi olarak gösterilir (ekrandan, 00:05:00), kodlar Dev-C++ içinde yazılıp çalıştırılır, dizilerin nasıl gezildiği de Paint'te çizilerek anlatılır.

Soruya geçmeden önce algoritmik düşünmenin önemi vurgulanır. Bir önceki dönemde akış şeması çizerken yapılan şey burada da geçerlidir: önce problem adımlara bölünür. Pisagor üçlüsü sorusu için bu adımlar şöyle kurulur:

- Kullanıcıdan dizinin kaç elemanlı olacağı alınır (ör. 6).
- O kadar eleman kullanıcıdan istenir ve dizi doldurulur.
- Dizideki elemanlar üçerli olarak gezilir; birinin karesinin diğer ikisinin karelerinin toplamına eşit olup olmadığına bakılır.
- Böyle bir üçlü bulunursa sayılar yazılır, bulunmazsa dizide Pisagor üçlüsü olmadığı yazılır.

> **Hocanın vurgusu:** Kodun içindeki işlevleri ezberlemek değil, problemi çözen algoritmayı kafada oturtmak önemlidir. Bu düşünme biçimi bütün meslek hayatı boyunca kullanılacaktır.

Bu adımlar yazılırken hangi değişkenlerin gerekeceği de kendiliğinden ortaya çıkar: eleman sayısı, dizi, döngü indeksleri, kareler ve bulunan üçlü sayısı.

## 2. Soru 1: Dizide Pisagor üçlüsü arama

### 2.1 Soru

Ekrandaki soru metni şudur (ekrandan, 00:05:00): verilen bir dizi içinde Pythagorean triplet (Pisagor üçlüsü) bulunup bulunmadığını kontrol eden, eğer varsa bu üçlüyü ekrana yazdıran programı C dilinde hazırlayınız. Örnek girdi `arr[] = {3, 1, 4, 6, 5}`, çıktı `True` ve "There is a Pythagorean triplet (3, 4, 5)".

Pisagor üçlüsü, $a^2 = b^2 + c^2$ eşitliğini sağlayan üç sayıdır. Burada aranan, dizinin içindeki herhangi üç elemanın bu eşitliği sağlayıp sağlamadığıdır.

### 2.2 Dizinin tanımlanması ve doldurulması

Program `stdio.h` ile başlar. Ek olarak `locale.h` eklenir ve `setlocale(LC_ALL, "Turkish");` çağrılır; bu, `printf` ile yazılan Türkçe karakterlerin konsolda doğru görünmesi için kullanılır.

Dizi iki şekilde tanımlanabilir: boyutu verilip boş bırakılır ve sonra doldurulur, ya da tanımlama sırasında elemanlar süslü parantezle yazılır. Bu soruda eleman sayısı kullanıcıdan geleceği için dizi en büyük boyutla açılır. Boyut doğrudan sayı olarak yazılmaz; programın başında bir makro sabit tanımlanır: `#define MAX 50` ve dizi `int Array[MAX];` olarak açılır (ekrandan, 00:10:00).

> **Hocanın vurgusu:** Bölümün yazım prensiplerinden biri: boyutu sabit olan ve bir daha değişmeyecek diziler, yukarıda `#define` ile tanımlanmış bir makro sabitle boyutlandırılır.

Eleman sayısı `esayi` değişkenine alınır. Elemanlar için bir `for` döngüsü kurulur. Döngü değişkeni `i` döngünün içinde değil, yukarıda tanımlanır (bölüm kuralı, bkz. Bölüm 5).

`scanf` içinde değişkenin önüne konan `&` işleci burada hatırlatılır. Bu işleç, önündeki değişkenin bellekteki adresini verir. `scanf("%d", &esayi)` kullanıcıdan gelen değeri `esayi`'nin adresine yazar. Dizi elemanında da aynısı yapılır: `&Array[i]`, dizinin `i`'inci elemanının adresidir ve değer oraya yazılır. Ekrandaki ilk taslakta `scanf("%d",esayi);` yazılmıştır (ekrandan, 00:10:00); `&` eksikliği hemen fark edilip `&esayi` olarak düzeltilir (ekrandan, 00:20:00).

### 2.3 Üç iç içe döngüyle arama

Arama mantığı Paint'te `5, 7, 3, 8, 4, 10, 12, 13` elemanlı bir dizi çizilerek anlatılır (ekrandan, 00:15:00). Dizinin üzerinde üç ok düşünülür. İlk iki ok sabitken üçüncü ok dizinin sonuna kadar ilerler; bulunamazsa ikinci ok bir adım ilerler ve üçüncü ok onun bir sağından yeniden başlar; ikinci ok da sona gelince birinci ok ilerler. Bu, üç iç içe `for` döngüsüne karşılık gelir.

Döngülerin başlangıç değerleri önemlidir. `b` yeniden sıfırdan başlatılmaz; `a`'nın bir sonrasından, `b = a + 1`'den başlar. `c` de `b + 1`'den başlar. Böylece her üçlü yalnız bir kez denenir ve bir eleman kendisiyle eşleştirilmez.

Dizi sıralı olmak zorunda değildir; en büyük sayı üçlünün herhangi bir yerinde olabilir. Bu yüzden kareler `x`, `y`, `z` değişkenlerinde tutulur ve üç durum tek bir koşulda birleştirilir: `x == y + z`, `y == x + z` ya da `z == x + y`. Örneğin `3, 4, 5` için 5 hangi konumda olursa olsun koşullardan biri sağlanır.

Bulunan üçlülerin sayısı `count` değişkeninde tutulur. Koşul sağlandığında `count++` yapılır ve üçlü kaçıncı üçlü olduğu ile birlikte yazdırılır. Üç döngü bittiğinde `count == 0` ise dizide Pisagor üçlüsü olmadığı yazılır ve program `return 0;` ile biter.

Ekranda görülen kod (ekrandan, 00:20:00 ve 00:25:00) aşağıdadır. Üçlüyü yazdıran `printf` satırları ve sondaki `if (count == 0)` bloğu karelerde görünmediği için o satırlar altyazıdaki anlatıma göre tamamlanmıştır. <!-- BELİRSİZ: yazdırma satırlarının ekrandaki tam metni karelerde görünmüyor --> Ekranda `int count;` ilk değersiz tanımlanmıştı; aşağıda `int count = 0;` olarak yazıldı (bkz. ders sonrası not).

```c
#include <stdio.h>
#include <locale.h>

#define MAX 50

int main() {
    setlocale(LC_ALL, "Turkish");

    int Array[MAX];
    int i;
    int esayi;
    int a,b,c;
    int x,y,z;
    int count = 0;   /* ekranda: int count; */
    printf("Dizimiz kaç elemanlı olsun");
    scanf("%d",&esayi);

    for(i=0;i<esayi;i++)
    {
        printf("Dizi [%d]. elemanını giriniz:",i);
        scanf("%d",&Array[i]);
    }

    for(a=0;a<esayi;a++)
    {
        for(b=a+1;b<esayi;b++)
        {
            for(c=b+1;c<esayi;c++)
            {
                x=Array[a]*Array[a];
                y=Array[b]*Array[b];
                z=Array[c]*Array[c];

                if(x==y+z||y==x+z||z==x+y)
                {
                    count++;
                    /* karede görünmeyen kısım, anlatıma göre tamamlandı */
                    printf("\n%d. Pisagor üçlüsü: %d %d %d\n", count, Array[a], Array[b], Array[c]);
                }
            }
        }
    }
    if(count==0)
    {
        printf("\nPisagor üçlüsü yoktur.\n");
    }
    return 0;
}
```

Bu kod `gcc -Wall` ile uyarısız derlendi ve derste girilen `5 8 1 3 4` girdisiyle çalıştırıldı: çıktı "1. Pisagor üçlüsü: 5 3 4" oldu.

> **Ders sonrası not:** Ekranda `int count;` ilk değer verilmeden tanımlanmış görünüyor (ekrandan, 00:25:00). Fonksiyon içindeki yerel değişkenin ilk değeri belirsizdir; `count++` ve `count == 0` denetiminin güvenilir olması için `int count = 0;` yazılmalıdır. `gcc -Wall -O2` ilk değersiz hali için "may be used uninitialized" uyarısı verir.

### 2.4 Programın denenmesi

Program derste üç kez çalıştırılır:

- 5 elemanlı dizi `5, 8, 1, 3, 4`: birinci Pisagor üçlüsü olarak (5, 3, 4), yani 3-4-5 bulunur.
- 10 elemanlı bir dizi; içinde 3, 4, 5 ile 5, 12, 13 bulunur: program iki üçlü yazar, (5, 3, 4) ve (5, 12, 13). <!-- BELİRSİZ: girilen 10 sayının tam listesi altyazıdan net çıkmıyor -->
- 3 ve 4 verilmeyen 5 elemanlı bir dizi: üçlü bulunamadığı mesajı çıkar.

Bu üç durum kodla da denendi ve aynı sonuçlar alındı.

### 2.5 Karmaşıklık üzerine

Kodun daha düşük karmaşıklıkla da yazılabileceği belirtilir. Her iç içe döngü çalışma süresini artırır; ne kadar çok iç içe döngü varsa program o kadar uzun sürer. Bazen bu zorunludur, ama zorunlu olmadığında döngü sayısı az, okunaklı ve karmaşıklığı düşük kod tercih edilir. Bu konu ileride algoritma analizi dersinde görülecektir; şimdilik amaç kodun doğru çalışmasıdır.

> **Ek bilgi (derste anlatılmadı):** Üç iç içe döngü $n$ elemanlı bir dizide yaklaşık $n^3/6$ üçlü dener, yani $O(n^3)$ zaman alır. Kareler hesaplanıp dizi sıralanırsa her eleman için iki uçtan yaklaşan iki indeksle arama yapılarak $O(n^2)$ zamanda çözülebilir.

## 3. Soru 2: İşaretçi konusunun hızlı tekrarı

### 3.1 Değişkenler ve bellek

Programda tanımlanan her değişken ve dizi bellekte (RAM) tutulur. Belleğin her yerinin bir adresi vardır ve o adreste değişkenin değeri saklanır. `int var = 20;` yazıldığında bellekte 4 baytlık bir alan ayrılır; çizimde bu alanın adresi örnek olarak `0x004`, bir sonrakinin `0x008` diye gösterilir. 20 değeri bu alana yazılır. Değişkene sonradan ulaşmak ve değerini değiştirmek için hem değerin hem adresin bilinmesi gerekir. Ne tür bir değişken tanımlanırsa o türün boyutu kadar yer ayrılır; `int` için 4 bayt.

### 3.2 İşaretçi tanımlama ve kullanma

C dilinin en önemli özelliklerinden biri belleğe kolayca erişilebilmesidir. Bir değişkenin adresine ulaşıp o adresteki değerle işlem yapmak için işaretçi (pointer) tanımlanır. İşaretçi adresi işaret eden bir değişkendir. Nasıl bir `int` değişkene `int` değer atanıyorsa, bir işaretçiye de adres atanır. Adres `&` işleciyle alınır: `ip = &var;`. Artık `ip`, `var`'ın RAM'deki adresini tutar.

İşaretçinin kendisi yazdırılırsa içinde sakladığı adres görünür. Adresi tutmanın amacı o adresteki değere ulaşmaktır; bunun için işaretçinin önüne `*` konur. `*ip`, `ip`'nin tuttuğu adrese gider ve oradaki değeri, yani 20'yi verir.

İşaretçinin türü, işaret edeceği verinin türüyle aynı olmalıdır. Bir `int` değişkenin adresi tutulacaksa `int *` tanımlanır; böylece atamalarda sorun çıkmaz.

Ekrandaki kod (ekrandan, 00:30:00):

```c
int  var = 20;   /* değişken tanımlama ve ilk değer atama */

printf("var degiskenimizin adresi: %p\n", &var  );
int  *ip;        /* integer işaretçisi tanımlama */
int  *ptr = NULL;

printf("ptr isaretcisinin degeri: %p\n", ptr  );
printf("ip isaretcisinin degeri: %p\n", ip  );

ip = &var;  /* var değişkeninin adresini işaretçimize atıyoruz*/

printf("var degiskenimizin adresi: %p\n", &var  );
printf("var degiskenimizin degeri: %d\n", var  );

/* işaretçimizde saklanan adres değerine bu şekilde ulaşıyoruz */
printf("ip işaretçisinde saklanan adres: %p\n", ip );

/* işaretçimizin işaret ettiği adreste bulunan değişkenin değerine ulaşıyoruz*/
printf("*ip değişkeninin değeri: %d\n", *ip );

return 0;
```

Çalıştırıldığında önce `var`'ın onaltılık (hexadecimal) adresi görünür. `ptr` ve `ip` henüz bir adrese bağlanmadığı için ekranda sıfır adres yazar. Atamadan sonra `ip`'nin yazdırdığı adres `&var` ile aynıdır, yani atama doğru yapılmıştır; `*ip` de 20 verir. İşaretçinin temel mantığı budur.

> **Ders sonrası not:** Asistan, işaretçinin iki şekilde tanımlanabileceğini, `NULL` atanabileceğini ya da boş bırakılırsa zaten sıfır atanacağını söyledi. Doğrusu: fonksiyon içinde ilk değer verilmeden tanımlanan `int *ip;` işaretçisinin değeri belirsizdir; ekranda sıfır görünmesi garanti değildir. Bu yüzden `int *ip = NULL;` biçimi kullanılmalıdır. `gcc -Wall` bu satır için "'ip' is used uninitialized" uyarısı verir (kodun tam hali ayrıca derlenerek denendi).

### 3.3 Dizinin eleman sayısını `sizeof` ile bulmak

Ek bir bilgi olarak, elemanlarını saymak zahmetli olan bir dizinin eleman sayısının `sizeof` ile bulunabileceği gösterilir. `sizeof(dizi)` dizinin toplam bayt boyutunu, `sizeof(dizi[0])` bir elemanın boyutunu verir. 3 elemanlı bir `int` dizisinde toplam boyut $3 \times 4 = 12$ bayt, bir eleman 4 bayttır; $12 / 4 = 3$ eleman bulunur.

### 3.4 Dizi ve işaretçi aritmetiği

Bir dizinin elemanlarına işaretçiyle ulaşmak için işaretçi dizinin başlangıç adresine bağlanır. Bu iki şekilde yapılabilir ve ikisi aynı anlama gelir: dizinin adı doğrudan yazılır (`ptr = dizi;`) ya da ilk elemanın adresi verilir (`ptr = &dizi[0];`).

Normal bir `int` değişkende `a++` değeri 1 artırır. İşaretçide ise `ptr++` adresi 1 artırmaz; işaretçinin türünün boyutu kadar artırır. `int *` için 4 bayt ilerler, yani adres `...04` ise bir sonraki `...08` olur ve sıradaki elemanın adresine gelinir. Derste çalıştırılan örnekte sıfırıncı elemanın adresinin son haneleri `00`, sonrakilerin `04` ve `08` çıktığı gösterilir. <!-- BELİRSİZ: bu ikinci işaretçi örneğinin (dizi) kodu karelerde görünmüyor --> Böylece işaretçi dizinin başına konup artırıldıkça dizinin her elemanına ulaşılabilir; dizi de aslında bellekte art arda duran değişkenler olarak düşünülebilir.

## 4. Soru 3: İşaretçiyle alt kod arama

### 4.1 Soru

Ekrandaki soru metni şudur (ekrandan, 00:35:00): bir laboratuvarda kimyasal deneylerde kullanılan kısa kodlar kayıt altına alınıyor. Laboratuvar görevlisi, elindeki kodların içinde belirli bir alt kodun (ör. "Na" ya da "Cl") aranması gerektiğini söylüyor. İki girdi vardır: ana kod (kısa bir kelime ya da kimyasal sembol dizisi) ve aranacak alt kod. Örneğin ana kod "NaClK", aranacak alt kod "Cl" ise "NaClK" içinde "Cl" dizisinin olup olmadığı ve olduysa hangi indeksten başladığı bulunmalıdır. Görev:

- Birinci girdi: ana kod (ör. "NaClK").
- İkinci girdi: aranacak alt kod (ör. "Cl").
- Diziler ve işaretçi kullanarak ikinci girdinin birinci girdi içinde geçip geçmediğini kontrol ediniz.
- Geçiyorsa ilk geçtiği indeks bilgisiyle ekrana yazdırınız.
- Geçmiyorsa "Aradığınız alt kod bulunamadı." gibi bir mesaj gösteriniz.

Yani bir ana metin ve onun içinde aranacak küçük bir alt metin (substring) vardır. Derste örnek olarak ana metin "fenerbahce", alt metin "bah" alınır: "bah" ana metinde 0, 1, 2, 3, 4, 5 diye sayıldığında 5. indekste başlar.

Algoritma yine önce sözle kurulur: iki karakter dizisi tanımlanıp girdiler alınır, sonra iki dizi arasında arama yapılır. Ana metnin her konumundan başlayarak alt metnin karakterleri sırayla karşılaştırılır; yalnız bir karakterin eşleşmesi yetmez, alt metnin tamamı art arda eşleşmelidir (ör. "bah" yerine "bac" aransaydı `b` eşleşir ama devamı eşleşmezdi).

### 4.2 Karakter dizileri

`char text[100], pattern[100];` ile iki dizi tanımlanır. Asistan burada da boyutun aslında `#define` ile verilmesinin daha doğru olacağını belirtir. Girdiler `scanf("%s", text);` ve `scanf("%s", pattern);` ile alınır. `int` elemanlar 4 bayt yer kaplarken `char` elemanlar 1 bayt kaplar; bu yüzden `char *` işaretçi artırıldığında adres 1 artar.

Bir karakter dizisine girilen metnin sonunu `'\0'` (sonlandırıcı karakter) gösterir; dizinin sonuna kadar gitmek, `'\0'` görülene kadar ilerlemek demektir.

> **Ders sonrası not:** Asistan, 100 elemanlı diziye 7-8 karakter girilince geri kalan kısma sonlandırıcı karakter atıldığını söyledi. Doğrusu: `scanf("%s")` yalnız okunan metnin hemen sonuna tek bir `'\0'` ekler; fonksiyon içindeki dizinin geri kalan elemanlarının değeri belirsizdir. Kod ilk `'\0'`'da durduğu için yine doğru çalışır.

### 4.3 `ptr` ve `temp` işaretçileri

Paint'te iki dizi çizilir: üstte `f e n e r b a h ç e`, altta `b a h` (ekrandan, 00:40:00). Ana metnin üzerinde bir işaretçi tanımlanır: `char *ptr = text;` (ya da `&text[0]`). `ptr`, aramanın o anda başladığı konumu gösterir. Karşılaştırma sırasında bu başlangıcın kaybolmaması gerekir, çünkü eşleşme olmazsa bir sonraki konuma geçilecek, eşleşme olursa da indeks bu konumdan hesaplanacaktır. Bu yüzden karşılaştırmayı yapan ikinci bir işaretçi kullanılır: `temp`. Her adımda `temp = ptr;` yapılır, karşılaştırma `temp` üzerinden yürür, iş bitince `ptr` bir artırılır.

Kod (ekrandan, 00:45:00 ve 00:50:00):

```c
#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Turkish");
    char text[100], pattern[100];

    printf("Metni girin: ");
    scanf("%s", text);
    printf("Aranacak deseni girin: ");
    scanf("%s", pattern);

    int i;
    int count = 0;
    int index = -1;
    char *ptr = text;
    char *temp=NULL;
    while (*ptr != '\0') {
        i = 0;
        temp = ptr;
        while (*(temp + i) == pattern[i] && pattern[i] != '\0') {
            i++;
        }
        if (pattern[i] == '\0') {
            count++;
            if (index == -1){
                printf("ptr'in adresi = %p\n",ptr );
                printf("text'in adresi = %p\n",text );
                index = ptr - text;
            }

        }

        ptr++;
    }
    /* karede görünmeyen kısım, soru metnine göre tamamlandı */
    if (count == 0) {
        printf("Aradığınız alt kod bulunamadı.\n");
    } else {
        printf("Alt kod ilk olarak %d. indekste geçiyor, toplam %d kez geçiyor.\n", index, count);
    }
    return 0;
}
```

<!-- BELİRSİZ: kodun 36. satırdan sonraki kısmı (sonuç yazdırma) karelerde görünmüyor; yukarıda soru metnine göre tamamlandı -->

Bu kod (`%p` için `(void*)` dönüşümü eklenerek) `gcc -Wall` ile derlendi ve denendi: "fenerbahce"/"bah" için 5. indeks, "NaClK"/"Cl" için 2. indeks, bulunmayan bir desen için "Aradığınız alt kod bulunamadı." çıktısı alındı.

### 4.4 Arama adım adım ("fenerbahce" içinde "bah")

Asistan aramayı çizim üzerinde adım adım izler:

- `ptr` `f`'yi gösterir. `i = 0`, `temp = ptr`. `*(temp + 0)` yani `f`, `pattern[0]` yani `b` ile karşılaştırılır; eşit değil. İç döngü hemen biter, `pattern[0]` `'\0'` olmadığından eşleşme yoktur. `ptr++`.
- `ptr` `e`'yi gösterir; `e` ile `b` eşit değil. `ptr++`. Aynı şekilde `n`, `e`, `r` konumlarında da ilk karakter eşleşmez.
- `ptr` `b`'yi (5. indeks) gösterir. `temp = ptr`, `i = 0`: `b == b`, eşleşti, desen henüz bitmedi, `i = 1`.
- `*(temp + 1)` yani `a`, `pattern[1]` yani `a` ile eşleşir, `i = 2`.
- `*(temp + 2)` yani `h`, `pattern[2]` yani `h` ile eşleşir, `i = 3`.
- `pattern[3]` `'\0'` olduğu için iç döngü durur. `pattern[i] == '\0'` sağlandığından desenin tamamı eşleşmiştir: `count` 1 artar.
- `index` hâlâ $-1$ olduğundan bu ilk eşleşmedir. `ptr` başlangıç konumunda durduğu için (karşılaştırmayı `temp` yaptı) indeks iki adresin farkıdır: `index = ptr - text;`.

Programın çıktısında `ptr`'nin adresinin son hanesi 5, `text`'in adresinin son hanesi 0 görünür; fark 5'tir ve alt kod 5. indekste, bir kez geçer. `char` elemanları 1 bayt olduğu için adres farkı doğrudan indeksi verir.

> **Ders sonrası not:** Asistan indeks hesabını önce elemanlar arası 4 bayt varmış gibi anlattı, programı çalıştırırken `char`'ın 1 bayt olduğunu söyleyerek düzeltti. Ayrıca C'de aynı dizideki iki işaretçinin farkı (`ptr - text`) bayt değil eleman sayısı cinsindendir; bu yüzden indeks hesabı `int` dizilerde de doğru sonuç verirdi.

**Soru:** `temp` kullanmanın ne farkı var? **Cevap:** Aramanın başladığı konum olan `ptr`'nin kaybolmaması gerekir. Karşılaştırma `temp` ile yapılırken `ptr` sabit kalır; böylece eşleşme bulunduğunda başlangıç adresi elde olur ve indeks hesaplanabilir, eşleşme yoksa da `ptr` bir adım ilerletilerek aramaya devam edilir.

> **Hocanın vurgusu:** İşaretçi konusu C programlamanın en önemli konusudur. Veri yapıları ve algoritma analizi gibi ileriki derslerde hem bellek hem işlem tarafında sürekli kullanılacağı için iyi öğrenilmelidir.

## 5. Kod yazım kuralları

Oturumun sonunda bölümde uygulanan bazı kod yazım kuralları hatırlatılır. Bir problem birçok şekilde kodlanabilir ve doğru çıktı verebilir; ama bölümün kurallarına uymayan kod doğru sayılmaz:

- Döngü değişkeni `for (int i = 0; ...)` biçiminde döngünün içinde tanımlanmaz; değişken yukarıda tanımlanır ve döngüde `i = 0` ile başlatılır. Bu kural `for`, `while` ve diğer döngüler için geçerlidir.
- `break`, `continue` ve `goto` kullanılmaz.
- Boyutu sabit olan diziler `#define` ile tanımlanan bir sabitle boyutlandırılır.

Bu kuralların ayrıntılı bir belge olarak ayrıca paylaşılacağı söylenir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:05:00): Verilen bir dizi içinde Pythagorean triplet bulunup bulunmadığını kontrol eden, eğer varsa bu üçlüyü ekrana yazdıran programı C dilinde hazırlayınız. Örnek: girdi `arr[] = {3, 1, 4, 6, 5}`; çıktı `True`, "There is a Pythagorean triplet (3, 4, 5)".

> **Çözüm (derste verildi):** Eleman sayısı ve elemanlar kullanıcıdan alınır. `a`, `b = a + 1`, `c = b + 1` başlangıçlı üç iç içe döngüyle her üçlü bir kez denenir. Kareler `x`, `y`, `z` olarak hesaplanır ve `x == y + z || y == x + z || z == x + y` koşulu denetlenir. Kodun tamamı Bölüm 2.3'tedir. Örnek dizi için yalnız `a=0` (3), `b=2` (4), `c=4` (5) üçlüsünde $9 + 16 = 25$ sağlanır; çıktı tek üçlü (3, 4, 5) olur. (Örnek dizi kodla ayrıca denendi.)

**Soru 2** (ekrandan, 00:35:00): Bir laboratuvarda kimyasal deneylerde kullanılan kısa kodlar kayıt altına alınıyor. Ana kod (ör. "NaClK") ve aranacak alt kod (ör. "Cl") girdi olarak veriliyor. Diziler ve işaretçi kullanarak alt kodun ana kod içinde geçip geçmediğini kontrol ediniz; geçiyorsa ilk geçtiği indeksi yazdırınız, geçmiyorsa "Aradığınız alt kod bulunamadı." gibi bir mesaj gösteriniz.

> **Çözüm (derste verildi):** `ptr` ana metinde başlangıç konumunu tutar, her konumda `temp = ptr` yapılıp `*(temp + i) == pattern[i] && pattern[i] != '\0'` olduğu sürece `i` artırılır. `pattern[i] == '\0'` ise alt kod bulunmuştur; ilk bulunuşta `index = ptr - text`. Kodun tamamı Bölüm 4.3'tedir. "NaClK" içinde "Cl": N(0), a(1), C(2) konumunda `C == C`, `l == l` eşleşir, desen biter; indeks $2$ olur. Derste denenen "fenerbahce"/"bah" girdisinin sonucu 5'tir.

## Dersin Toparlaması

Bu uygulama oturumunda önce dizi, döngü ve koşul yapılarıyla bir arama algoritması kurularak bir dizide Pisagor üçlüsü arandı; üç iç içe döngüyle bütün üçlüler bir kez denendi, dizi sıralı olmadığı için üç eşitlik birlikte denetlendi. Ardından işaretçi konusu tekrar edildi: değişkenlerin bellekte bir adreste tutulduğu, `&` ile adresin alındığı, işaretçinin bu adresi sakladığı ve `*` ile o adresteki değere ulaşıldığı, dizi adının başlangıç adresi olduğu ve `ptr++`'ın türün boyutu kadar ilerlediği gösterildi.

Son soruda bu bilgiler birleştirilerek bir metin içinde alt kod arandı. Başlangıç konumunu tutan `ptr` ile karşılaştırmayı yapan `temp`'in ayrılması ve indeksin iki adresin farkıyla bulunması sorunun özüdür. İşaretçiler, sonraki konularda ve ileriki derslerde temel araç olarak kullanılmaya devam edecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
