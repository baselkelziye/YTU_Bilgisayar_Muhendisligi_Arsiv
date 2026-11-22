# Ders 2 Genişletilmiş Notu: C Temellerine Hızlı Bakış: Değişkenler, Fonksiyonlar, Veri Tipleri ve Tip Dönüşümleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Değişkenler ve Bellek
- 2. Değişken Adlandırma Kuralları
- 3. İfadeler (Expressions)
- 4. Atama, L-value ve R-value
- 5. Yorum Satırları
- 6. Fonksiyonlar, Cohesion ve Coupling
- 7. main Fonksiyonu, exit, printf ve scanf
- 8. Önişlemci: define ve include
- 9. C Programının Genel Yapısı ve Dersin Yol Haritası
- 10. Veri Tipleri ve Atama Uyumluluğu
- 11. Tam Sayı Tipleri, Değer Aralıkları ve Karakterler
- 12. Format Dizgileri, Sabitler ve Kayan Noktalı Tipler
- 13. İlklendirme ve Bellek-Hız Dengesi
- 14. Tip Karıştırma: Örtük ve Açık Dönüşüm
- 15. enum, void ve typedef
- 16. Kaçış Karakterleri ve Noktalı Virgül
- 17. Operatörler ve İşlem Önceliği
- Örnek Sorular

## 1. Değişkenler ve Bellek

Ders, bir önceki derste kalınan değişkenler konusundan devam etti. Hoca, bu konuların öğrencilerin bildiği şeyler olduğunu ama bu derste temelden anlatılacağını söyledi. Normal bir programlama dersinde değişken için "adı ve değeri vardır" demek yeterli görülür. Bu derste ise ileride veri yapılarına geçileceği için değişkene belleği yönetme aracı olarak bakılır: adresler, belleğin kapasitesi ve belleğin düzeni.

Bir bilgisayar mühendisi açısından değişken, belleğin hücreleridir. Hoca belleği tek boyutlu (one dimensional) bir dizi olarak çizdi. Programlamayla ilgili yapılan her iş bu tek boyutlu dizi üzerinde yapılır. Belleğin kapasitesi RAM'in kapasitesine eşdeğerdir. Adresler 0'dan başlar ve genelde onaltılık (hexadecimal) yazılır, çünkü `0x0000`'dan `0xFFFF...`'ye kadar adreslemek bu şekilde daha kolay okunur. Bellekteki her adresin bir boyutu (size) ve bir değeri vardır.

Dizi değişkenleri, klasik değişkenler ve statik değişkenler bu bellek üzerinde yer alır. Hoca, dersin büyük kısmının belleğin yönetilmesiyle ilgili olacağını söyledi: adreslerin ardışık olmasının avantaj ve dezavantajları ile verinin dağınık adreslerde tutulmasının avantaj ve dezavantajları dersin ana konularıdır.

### 1.1 Sabit ve değişken

Slayttaki ifade `j = 5 + 10;` idi (ekrandan, 00:15:00). Burada bir emir ifadesi vardır: 5 ile 10'u topla, sonucu `j`'ye ata. Sabit (constant) üzerinde çalışılıyorsa değeri hiçbir zaman değişmez. Değişken ise bellekte bir adres kaplar, bir adreste oturur ve değeri değiştirilebilir.

### 1.2 Değişkenin beş özelliği

Hoca beyaz tahtaya bir değişkenin özelliklerini yazdı (ekrandan, 00:15:00):

- Adres (address)
- Değer (value)
- Etiket (label)
- Boyut (size)
- Tip (type)

Slayttaki çizimde `j` etiketi, 2482, 2486, 2490 adreslerinin sıralandığı bir bellek şeridinde 2486 adresindeki 4 baytlık hücreyi gösterir ve bu hücrenin içeriği 15'tir. Yani `j` etikettir, 2486 adresidir, 4 bayt boyuttur, 15 değerdir; tip ise programda ne tanımlandıysa odur (`int`, `float` gibi). Hoca bu beş özelliğin değişkenler için en çok kullanılan ve anlatılan özellikler olduğunu, devamının derste görüleceğini söyledi.

## 2. Değişken Adlandırma Kuralları

Hoca adlandırma kurallarının C diline özgü olduğunu, başka bir dilde öğrenilen kuralın C'de geçerli olmayabileceğini belirtti. <!-- BELİRSİZ: Altyazıda karşılaştırılan dilin adı bozuk yazılmış ("Bitlid"); büyük olasılıkla Python. --> C'de değişkenler için kullanılan adlandırma kuralları sabitler, fonksiyonlar ve program içindeki etiketler için de geçerlidir (ekrandan, 00:10:00):

- Ad yalnızca harf, rakam ve alt çizgi (`_`) içerebilir. Ünlem, soru işareti, noktalı virgül gibi karakterler kullanılmaz.
- Ad bir harf ya da alt çizgiyle başlamalıdır; rakamla başlayamaz.
- C büyük-küçük harfe duyarlıdır (case sensitive). `VaR`, `var` ve `VAR` üç farklı değişkendir. Bu duyarlılık dizgilerde de geçerlidir: bu üçü dizgi olarak karşılaştırılırsa hiçbir ikisi eşit çıkmaz.
- Ad, C'ye ayrılmış anahtar kelimelerden (reserved keywords) biri olamaz.

Hoca, yaklaşık 260 sayfalık slayt olduğunu ve bu ilk slaytların neden önemli olduğunu açıkladı: ileride dinamik bellek ayırma (dynamic memory allocation) ve sonraki konulara gelindiğinde "burada bunu demiştik, unutmuşsunuz" denecektir.

Ardından legal ve illegal ad örneklerinin olduğu slayt gösterildi. Hoca illegal olanların gerekçelerini saydı: biri rakamla başlıyor, biri alt çizgi dışında bir karakterle başlıyor, biri ayrılmış anahtar kelime, biri de alt çizgi dışında özel karakterler içeriyor. Legal olanlarda ise hiçbir kural ihlali yoktur. <!-- BELİRSİZ: Legal/illegal örnek adların slaytı karelerde okunamadı, örnek adlar nota alınmadı. -->

### 2.1 Ayrılmış anahtar kelimeler

Anahtar kelimeler tablosunda bazı kelimeler öğrencilere yabancı gelebilir. Hoca bunlardan `default`, `goto`, `sizeof` (bir operatördür), `register` (ileride anlatılacak), `enum`, `extern` ve `volatile`'ı örnek verdi. Bunlar değişken adı olarak kullanılamaz.

## 3. İfadeler (Expressions)

İfade (expression), operatörlerin, sayıların ve adların bir değeri hesaplayan herhangi bir birleşimidir. Slayttaki örnekler (ekrandan, 00:20:00):

| İfade | Açıklama |
|---|---|
| `5` | Bir sabit |
| `j` | Bir değişken |
| `5 + j` | Bir sabit artı bir değişken |
| `f()` | Bir fonksiyon çağrısı |
| `f()/4` | Sonucu bir sabite bölünen fonksiyon çağrısı |

Fonksiyon çağrısı da bir ifadedir. Hoca beyaz tahtada bir `f(x)` fonksiyonu çizdi: içine `x = 5` gibi bir parametre gider, fonksiyon tanımlandığı yerde bir şeyler yapar ve bir `return` ile değer döndürür. Bu dönen değere 2 eklemek (`f(x) + 2`) legal bir ifadedir.

Bu kullanım başka yerlerde de karşılaşılır. Hoca rastgele sayı fonksiyonunu örnek verdi: belli bir aralıkta sayı döndürür; 0 ile 10 aralığında (10 hariç) bir sayı istenirse fonksiyondan gelen değerin 10'a göre modu alınır ve 0 ile 9 arasında tam sayılar elde edilir.

> **Ders sonrası not:** Hoca rastgele sayı fonksiyonunun varsayılan olarak 0 ile 1 arasında değer verdiğini söyledi. C'de `rand()` 0 ile `RAND_MAX` arasında bir tam sayı döndürür; bu yüzden `rand() % 10` doğrudan 0-9 arasında değer verir.

## 4. Atama, L-value ve R-value

Eşittir operatörü bir atama işlemidir. Hoca bunun, programlamaya yeni başlayanların ve C ile başlayanların hata yaptığı bir bölüm olduğunu söyledi.

Beyaz tahtadaki örnekler `a = 5;` ve `a = a + 5;` idi (ekrandan, 00:25:00). Eşitliğin sol tarafına Left Value (L-value, LV), sağ tarafına Right Value (R-value, RV) denir.

- Sol tarafta değişken olabilir. Sabit olamaz: `5 = a;` geçerli değildir (tahtada üstü çizildi).
- Sağ tarafta değişken, sabit ve fonksiyon çağrısı (`f()`) olabilir.
- Fonksiyon çağrısı sol tarafta olamaz.
- Dizi hücresi (`a[i]`) her iki tarafta da olabilir.
- Matematiksel işlem sağ tarafta olabilir, sol tarafta olamaz.

Hoca bunları küme olarak düşünüp "R-value kümesi L-value kümesini kapsar diyebilir miyiz?" diye sordu ve cevabın evet olduğunu söyledi. Önemli olan sol tarafa nelerin gelemeyeceğidir: `5 = a` olmaz, `f = a` olmaz. Fonksiyonun çağrı sonucuna bir şey atanamaz, çünkü fonksiyonun değeri de 5, 6 gibi sabit bir sonuçtur.

**Soru:** Fonksiyon bir işaretçi döndürüyorsa, önüne yıldız koyarak sol tarafa yazamaz mıyız?
**Cevap:** Hoca önce fonksiyon çağrısının değerine doğrudan bir atama yapılamayacağını, fonksiyon işaretçilerinde farklı bir şey görüleceğini ama onun da bu şekilde olmadığını söyledi. Sonra yıldızın nerede anlamlı olduğunu tahtada gösterdi (ekrandan, 00:30:00):

```c
int *a;
int b = 0;
a = &b;
*a = f(x);
```

Burada `f(x)` illa işaretçi döndürmek zorunda değildir, bir değer döndürür. Bu değer `a`'nın gösterdiği adrese, yani `b`'nin oturduğu yere yazılır. Bu geçerlidir, çünkü `*a` yine bir değişkenin yeridir: önünde yıldız olması bunu değiştirmez. Özetle sol tarafta matematiksel işlem olamaz; buna dikkat etmek yeterlidir.

## 5. Yorum Satırları

Tek satırlık yorum `//` ile, birden fazla satırlık yorum `/*` ile `*/` arasında yazılır. Hoca yorumun ne işe yaradığını bir kütüphane örneğiyle anlattı: bir program ya da kütüphane yazıp yayınlamak istendiğinde yorum satırlarıyla kullanıcıya program ve fonksiyon hakkında bilgi verilir. Yazanın kim olduğu, kodlamanın ne zaman yapıldığı, parametrelerin ne olduğu ve fonksiyonun ne döndürdüğü gibi açıklamalar fonksiyon başlıklarının ya da tanımlarının olduğu yere yazılır.

Hoca her satıra tek tek yorum yazmanın doğru olmadığını vurguladı. "Bu sayı iki ile toplanıyor" gibi bir yorum gereksizdir, çünkü toplama zaten koddan görülür. Doğrusu fonksiyonun başına "bu fonksiyon şu parametreleri alır, bunu döndürür, bu işi yapar" gibi bir açıklama yazmaktır.

## 6. Fonksiyonlar, Cohesion ve Coupling

Fonksiyon, programı daha modüler hale getirmek için yazılır: program daha küçük, anlamlı ve yönetilebilir parçalara bölünür. Hoca bu konunun değişken adlarıyla ilgili olduğu için burada açıldığını, ilerleyen haftalarda tekrar edileceğini söyledi.

Bir fonksiyon tanımında önce fonksiyonun adı (tahtada `functionName`), sonra alacağı parametreler, döndüreceği değer ve gövdesi yazılır. Gövdede algoritma yer alır.

### 6.1 Cohesion ve coupling

Fonksiyonun adıyla yapacağı iş arasında bir ilişki olmalıdır. Buna cohesion denir (ekrandan, 00:35:00). Hoca Türkçe karşılığını önce "tutarlılık, bağlılık" diye söyledi, sonra düzeltti: cohesion uyum ya da tutarlılıktır, bağlılık öbür kavramdır. Cohesion'ın yüksek olması (high cohesion) önemlidir. İkinci kavram coupling'dir (bağlılık, bağımlılık) ve bunun düşük olması gerekir. Hoca bunun bir tasarım kalıpları (design patterns) konusu olduğunu belirtti.

Örnek: Fonksiyonun adı "dizi sıralar" ya da sadece "sıralar" olsun. Fonksiyonun içinde dizi sıralamayla ilgili işlemlerin olması, adla algoritmanın uyumlu olması cohesion'dır. Fonksiyon diziyi sıralayıp bir de ekrana yazdırıyorsa iki iş birden yapıyor demektir; belki ekrana yazdırmak istenmiyordur. Bu doğru değildir: her fonksiyon tek iş yapmalıdır. Yazdırmak isteniyorsa ayrı bir yazdır fonksiyonu yazılıp çağrılır.

### 6.2 Dört tür fonksiyon

Fonksiyonlar iki açıdan sınıflandırılır: parametre alan ve almayan; değer döndürmeyen (`void`) ve döndüren (non-void). Bu ikisinin birleşiminden 2 x 2 = 4 farklı fonksiyon türü çıkar:

- Parametre alır, değer döndürmez.
- Parametre alır, değer döndürür.
- Parametre almaz, değer döndürmez.
- Parametre almaz, değer döndürür.

Hoca rastgele sayı fonksiyonunu örnek verdi: herhangi bir parametre almaz ama bir değer döndürür. Cohesion ve coupling açısından da iyi bir örnektir: yalnız rastgele sayı döndürür, başka bir iş yapmaz; uyumu yüksek, bağlılığı düşüktür.

### 6.3 Fonksiyon tanımı ve modülerlik

Fonksiyon tanımlanırken önce dönüş tipi, sonra fonksiyonun adı yazılır, parantez açılır ve alacağı parametreler (argümanlar) yazılır; ardından bildirimler ve ifadeler gelir, fonksiyon kapatılır. Hoca önemli olanın modülerlik olduğunu söyledi: ödevlerde ve sınavlarda "şu işi yapan fonksiyonu yazınız" denecek ve o işe uygun bir fonksiyon yazılması gerekecek.

Fonksiyonlar işi alt parçalara bölerek modüler yazılım geliştirmeyi sağlar. Bir kez yazılan fonksiyon program içinde, hatta başka programlarda tekrar tekrar çağrılır. Örneğin `printf` bir kez yazılmıştır, derlenmiş hali çağrılır. Bu sayede bakım işleri ve hatalar (bug) daha kolay yönetilir. Hoca hataların ve değişikliklerin yazılım geliştirmede kaçınılmaz olduğunu, program ne kadar modüler yazılırsa bakım maliyetinin ve hata ayıklamanın o kadar kolaylaşacağını söyledi.

### 6.4 Fonksiyon bildirimi (prototip)

Bir fonksiyon kullanılmadan önce bildirilmelidir. Programın başlangıcından, `main`'den önce bir prototip yazılır. Prototip, derlenecek programda böyle bir fonksiyonun tanımlandığını bildirir. Parametrelerin yalnız tiplerini yazmak yeterlidir, adlarına gerek yoktur; dönüş tipi yazılır ve noktalı virgül konur. Slayttaki örnek (ekrandan, 00:40:00):

```c
int combination( int, int ); //This is also called allusion
void aTaskThatNeedsCombination( ) {
    //some code
    c = combination(a, b);
    //more code
}
int combination( int a, int b ) {
    //necessary code
}
```

Bu parça kod derlenmedi (`a`, `b`, `c` bildirilmemiştir; yapı göstermek içindir). Burada `aTaskThatNeedsCombination`, kendisinden sonra tanımlanan `combination`'ı çağırabilir, çünkü prototip önceden yazılmıştır. Hoca fonksiyonların gövdesinin `main`'den önce de yazılabileceğini söyledi. Genel düzen şöyledir: önce prototipler, sonra `main`, sonra diğer fonksiyonlar.

Hoca, matrisleri fonksiyona parametre olarak verirken sütun boyutunun yazılmasının gerektiğini (satır boyutu isteğe bağlıdır) ya da işaretçi kullanılabileceğini, bu konuya ileride gelineceğini de belirtti.

### 6.5 Kod biçimi

Slaytta `square` fonksiyonunun girintili ve girintisiz iki yazılışı vardı. Hoca slayttaki örnekte parametrenin tipinin yazılmasının unutulduğunu söyledi (`int` gibi bir tip olmalıydı). Gövde belli bir girintiyle yazılmazsa fonksiyon olduğu anlaşılmaz; girintili olan doğru stildir. İfadeler arasında gereksiz yere Tab'a basmak da gereksizdir. Hoca iş hayatında girinti kurallarına uymayan kodun hemen eleştirildiğini, insanın yazısının temizliği nasıl önemliyse kodun da temiz yazılması gerektiğini söyledi.

## 7. main Fonksiyonu, exit, printf ve scanf

### 7.1 main fonksiyonu ve exit

`main` özel bir fonksiyondur ve çalışacak her programda bulunmalıdır. Program `main`'in ilk satırını sıfırıncı satır kabul eder, sonra birinci, ikinci satır diye komutları aşağıya doğru yürütür ve kapanış parantezine gelince program tamamlanır. Slayttaki örnek (ekrandan, 00:45:00):

```c
int main ( ) {
    extern int square();
    int solution;
    solution = square(5);
    exit(0);
}
```

`exit()` bir çalışma zamanı kütüphane rutinidir (runtime library routine). Programın bitmesini sağlar, yani işletim sistemine "bu program bitti" der ve denetimi ona geri verir. Biterken 0 ya da başka bir değer gönderilebilir; genelde 0 kullanılır. 0 dönüyorsa program sağ salim, hatasız tamamlanmıştır. Sıfırdan farklı bir değer, programın çalışmasında bir sorun olduğunu gösterir ve koda dönüp düzeltme yapılır. `main` içinde `exit()` çağırmak `return` deyimiyle tamamen aynıdır; bu yüzden genelde `return 0;` yazılır.

> **Ek bilgi (derste anlatılmadı):** `exit()` fonksiyonu `<stdlib.h>` başlık dosyasında bildirilir. Slayttaki `extern int square();` satırı, `square` fonksiyonunun başka bir yerde (büyük olasılıkla başka bir kaynak dosyada) tanımlandığını derleyiciye bildirir.

### 7.2 printf ve scanf

`printf` ekrana yazı basar, `scanf` klavyeden girilen veriyi alır. Hoca bunların işletim sistemiyle haberleşmeyi sağlayan özel fonksiyonlar olduğunu söyledi: `printf` işletim sistemine ekrana şöyle bir veri gönderileceğini söyler, `scanf` ise girilen veriyi okur.

Bu fonksiyonların özelliği birden fazla argüman alabilmeleridir: tek bir sayı ya da dizgi yazılabildiği gibi virgüllerle ayrılmış birçok parametre de yazılabilir. İlk argüman format dizgisidir: çift tırnakla yazılır ve içinde format belirteçleri bulunur; `%d` orada bir tam sayı yazılacağını gösterir.

`scanf` de benzer mantıkla çalışır: bir tam sayı okunacaksa okunan değer verilen adrese yazılır (`scanf("%d", &num)`). `num`'ın adresi yazılmazsa hata alınır. Nedeni şudur: `scanf` tanımı gereği belleğe erişip `num` değişkeninin oturduğu adresteki alana bir şey yazmaya çalışır. İçeride değişiklik yapacağı için değişkenin adı yetmez, adresine ihtiyaç duyar. Birden fazla `%d` yazılabilir; `%` sayısı kadar virgülle ayrılmış argüman verilir. Hoca `printf` ve `scanf`'in ne döndürdüğüne ileride kod yazarken bakılacağını söyledi.

## 8. Önişlemci: define ve include

Program derlenirken hazırlık işleri yaptırılmak istenirse önişlemci (preprocessor) komutları kullanılır. Bunlar `#` sembolüyle başlar ve sonlarına noktalı virgül konmaz. İleride makrolar, şartlı derleme ve hata ayıklama makroları bu sayede kullanılacaktır.

### 8.1 define

`#define MAX 100` yazılır, noktalı virgül konmaz. Anlamı: `MAX` görülen her yere git, 100'ü yapıştır. Slayttaki örnek `#define NOTHING 0`'dır (ekrandan, 00:50:00): ileride nerede `NOTHING` görülürse yerine 0 yazılır.

Sabit adlarının tamamen büyük harfle yazılması genel bir alışkanlıktır (common practice). Büyük harfle yazılmış bir ad görüldüğünde onun `#define` ile tanımlandığı anlaşılır. Slayta göre sabitlere ad vermenin iki faydası vardır: anlamsız bir sayıya açıklayıcı bir ad verilir ve program kolay değiştirilir.

Hoca ikinci faydayı bir örnekle açıkladı: `#define MAX 100` tanımlanıp `int d[MAX];` gibi bir dizi ve `for (i = 0; i < MAX; i++)` gibi bir döngü yazılmış olsun. `MAX` yerine her yere 100 yazılsaydı, bu değeri 1000 ya da 500 yapmak için bütün yerleri tek tek değiştirmek gerekirdi. `#define` ile yalnız tanımdaki 100'ü 500 yapmak yeter. Hoca bunun genel (jenerik) program yazmanın temeli olduğunu söyledi.

Slayt bu sabitlerin değişken gibi kullanılmaması gerektiğini de gösterir: `NOTHING = j + 5` yazılırsa önişlemci bunu `0 = j + 5` yapar. Bu da daha önce söylenen kurala göre (sol tarafta sabit olamaz) geçersizdir.

> **Ders sonrası not:** Hoca önişlemci komutlarının derleme aşamasında çalıştığını söyledi. Daha kesin ifadeyle önişlemci, asıl derlemeden önce kaynak metin üzerinde çalışır ve metin yerine koyma yapar.

### 8.2 include

`#include` ile kullanılmak istenen özel kütüphaneler ya da kendi yazdığımız dosyalar programa dahil edilir. İki yazılışı vardır:

- `#include <dosya.h>`: Şimdiye kadar hep böyle yazıldı. Aranan kütüphane sistem dosyaları arasında aranır ve eklenir.
- `#include "dosya.h"`: Kütüphane, programın derlendiği proje klasöründeyse bu şekilde yazılır. Bütün sistem dosyalarına bakmaya gerek kalmaz; daha kısa sürede bulunur ve bağlanır.

## 9. C Programının Genel Yapısı ve Dersin Yol Haritası

Hoca "hello world" programıyla C programının yapısını toparladı (ekrandan, 00:55:00):

```c
#include <stdio.h>

int main ( void ) {

    printf("Hello World...\n");
    return 0;
}
```

- `#include <stdio.h>` standart giriş-çıkış kütüphanesini ekler.
- `main` programın başlangıç noktasıdır; parantez içine `void` yazılmasa da olur.
- `printf` bir fonksiyondur.
- `return 0;` çağıran programa bir değer döndürür; 0 başarıyla tamamlandığını gösterir.

Program `gcc -Wall` ile derlenip çalıştırıldığında `Hello World...` yazar (slayttaki kıvrık tırnaklar düz tırnakla yazılarak denendi).

Hoca dersin bundan sonraki yöntemini de anlattı: programlar fonksiyonlarla modüler hale getirilecektir. Fonksiyonların parametreleri `int`, `int *`, `int **`, dizi ya da `struct` değişkeni olabilir; tahtada bunu `functions(int, int *, int **, ..., struct)` ve `param(*struct x functions)` diye özetledi. Konular bir kartezyen çarpım gibi birleşecektir: önce struct'lar, sonra struct ile fonksiyon, sonra işaretçi ile struct, sonra işaretçi, struct ve fonksiyon birlikte, sonra dosya işlemleri. Hoca 14 haftanın uzun bir süre olduğunu, sıkmadan ve bol uygulama yaparak ilerleneceğini söyledi.

## 10. Veri Tipleri ve Atama Uyumluluğu

Hoca, döngülere ve koşullara henüz gelinmediğini, "bodrum katın temellerini yeni attıklarını" söyleyerek veri tiplerine geçti. Bu slayt ve sonraki birkaç slaydın çok hata yapıldığı için çok önemli olduğunu vurguladı.

### 10.1 Farklı tipler ve atama kuralı

Hoca örnekleri `int` üzerinden verdi ama aynı şeylerin diğer tipler için de geçerli olduğunu söyledi. Beyaz tahtada şu tanımlar vardı (ekrandan, 01:20:00):

```c
int a;      int x;
int *pA;    int *px;
int **pAA;  int **pxx;
```

`int` bir tiptir; bir boyutu ve değer aralığı vardır. `int *pA` ise `int`'ten farklı yeni bir veri tipidir. `int **pAA` de başka bir tiptir. Atama yapılabilmesi için tiplerin aynı olması ya da dönüştürmeye uyumlu olması gerekir (types must be same or must be compatible to convert).

- `a = x;` yapılabilir, çünkü ikisinin tipi aynıdır.
- `pA = x;` yapılamaz; tip uyuşmazlığı (type mismatch) alınır (tahtada üstü çizildi).
- `pAA = pA;` de yapılamaz (tahtada üstü çizildi).

Dönüştürmeye uyumluluk şu demektir: bir karakter (`'c'`) bir `int`'e yazılabilir; `1.506` gibi bir değer `int`'e dönüştürülebilir. Ama `"123abc"` gibi bir dizgi `int`'e dönüştürülemez. `"123"` belki dönüşebilir, ama `abc` kısmı yüzünden `"123abc"` hata verir.

### 10.2 Veri tipi ağacı

Slayttaki ağaç (ekrandan, 01:15:00):

```text
Data types
├── void
├── Scalar types
│   ├── Arithmetic types
│   │   ├── Integral types
│   │   └── Floating types
│   ├── Pointers
│   └── enum
└── Aggregate types
```

- `void`: İlk bakışta tipsiz, herhangi bir tipe ait olmayan bir şey olarak düşünülebilir. Hoca bunun doğru ama eksik olduğunu, `void`'in ileride genel (generic) bir tip olarak kullanılacağını söyledi.
- Skaler tipler: Başka dillerde ilkel (primitive) tipler denen tiplerdir. Aritmetik tipler (tam sayılar ve kayan noktalı sayılar), bunların işaretçileri ve numaralandırılmış tipler (`enum`) buradadır.
- Birleşik (aggregate) tipler: Tam sayı dizisi gibi ya da `int`, `char`, `float`'un bir araya getirildiği struct'lar gibi tiplerdir; dersin ilerleyen kısmında anlatılacaktır.

Hoca bir dizinin de (`d[...]`) ayrı bir tip gibi düşünülebileceğini, özellikle tek işaretçi, çift işaretçi, üçlü işaretçi gibi her işaretçi düzeyinin ayrı bir tip gibi davrandığını vurguladı.

### 10.3 Temel tipler ve niteleyiciler

Skaler tipler için 9 ayrılmış kelime vardır. Temel tipler `char`, `int`, `float` (tek duyarlıklı), `double` (çift duyarlıklı) ve `enum`'dur. Bunların önüne `long`, `short`, `signed`, `unsigned` niteleyicileri (qualifier) getirilerek değer aralıkları değiştirilir.

> **Ders sonrası not:** Hoca `int`'in 4 bayt, `long int`'in 8 bayt, `long long`'un 16 bayt olduğunu söyledi. Doğrusu: `long` platforma göre 4 ya da 8 bayttır (64 bit Linux'ta 8, Windows'ta 4); `long long` en az 64 bit, yaygın olarak 8 bayttır. Bu notu hazırlarken kullanılan 64 bit Linux sisteminde gcc ile `sizeof(int)` = 4, `sizeof(long)` = 8, `sizeof(long long)` = 8 ölçüldü.

## 11. Tam Sayı Tipleri, Değer Aralıkları ve Karakterler

### 11.1 int ve unsigned int aralıkları

`int` 4 bayt, yani 32 bittir. İşaretli (signed) olduğunda 1 bit işarete gider, kalan 31 bit değeri gösterir. Sıfır pozitif tarafa alındığı için aralık:

$$-2^{31} \le \text{int} \le 2^{31} - 1$$

`unsigned int` (uint) olarak kabul edilirse işaret biti yoktur; değer 0'dan başlar:

$$0 \le \text{unsigned int} \le 2^{32} - 1$$

Sayısal olarak bu aralıklar $-2\,147\,483\,648$ ile $2\,147\,483\,647$ ve $0$ ile $4\,294\,967\,295$'tir (ara adım eklendi). Tip `long int` yapılırsa 32 yerine daha fazla bit (örneğin 64) kullanılır.

### 11.2 Bildirim kuralları

`int` değişkeni tanımlamak için önüne `int` yazılır. Aynı tipte birden fazla değişken aynı anda tanımlanacaksa araya virgül konur (`int a, b;`). Bir bloktaki bütün bildirimler, herhangi bir çalıştırılabilir deyimden (executable statement) önce yapılmalıdır. Örneğin `a = 10;` ve `b = a + 10;` yazmadan önce `int a, b;` bildirilmiş olmalıdır; hoca Python gibi dillerde böyle bir zorunluluk olmadığını belirtti.

> **Ders sonrası not:** Bildirimlerin bloğun başında olma şartı C89/ANSI C'ye aittir. C99 ve sonrası bildirimin deyimler arasında yapılmasına izin verir; günümüz gcc sürümleri bu kodu varsayılan olarak kabul eder.

Slayttaki tabloda ANSI standardındaki tam sayı tipleri, boyutları, aralıkları ve format belirteçleri vardı. ANSI standardında 1 bayt 8 bit kabul edilir ve `int` en az 16 bit (2 bayt) olmalıdır; `short int` 2 bayta kadar indirilebilir. Hoca bilinmesi gerekenlerin şunlar olduğunu söyledi: `int`, `long int`, `short int`, `unsigned int` nasıl yazılır (önce niteleyici, sonra `int`), değer aralıkları ve format belirteçleri. Örneğin 4 baytlık `long int` işaretlidir ve $-2^{31}$ ile $2^{31}-1$ arasında değer alır. <!-- BELİRSİZ: Tam sayı tipleri tablosunun slaydı karelerde yok; tablo değerleri nota alınmadı. -->

### 11.3 Karakter de bir sayıdır

Karakter de aslında bir sayıdır. 1 bayt ile 256 farklı kod gösterilebilir; ASCII kod tablosu buradan çıkar. Hoca gri tonlu (grayscale) resimlerin de bu mantıkla oluşturulduğunu anlattı (ekrandan, 01:30:00): resmin satırları ve sütunları vardır, her piksel bir parlaklık (intensity) değeri alır. $m \times n$ resmin çözünürlüğüdür (resolution). $m \times n$ değeri her pikselin kaç bit kapladığıyla (örneğin 8 bit) çarpılırsa resmin boyutu bulunur. 8 bit ile 256 farklı renk tonu gösterilir.

**Soru:** 1 bayt ile neden $2^7$ oluyor?
**Cevap:** İşaretli sayılar da dikkate alındığı için. $-128$'den ($-2^7$) $+127$'ye kadar değerleri saklamak için bir bit işarete gider, kalan 7 bit değeri gösterir.

Hoca kayan nokta (floating point) gösteriminin daha önce görüldüğünü hatırlattı: orada da bir bit işarete, bir grup bit virgülden önceki kısma, bir grup bit virgülden sonraki kısma gidiyordu. Bellekteki 0 ve 1 dizisinin bir kısmının işarete, bir kısmının tam kısma, bir kısmının ondalık kısma ayrılmasıyla veri saklanır.

### 11.4 Resim boyutu örneği

Hoca 256 satır, 256 sütun ve her pikselde 256 renk (8 bit) olan bir resmin boyutunu hesapladı. İlk denemede renk sayısını $2^8$ alarak $2^8 \cdot 2^8 \cdot 2^8 = 2^{24}$ ve 16 MB buldu, sonra bunun hatalı olduğunu söyleyip düzeltti: her hücrede 256 durum değil 8 bitlik yer vardır, bu yüzden çarpan $2^8$ değil $8 = 2^3$ olmalıdır.

Verilen: $m = 256 = 2^8$, $n = 256 = 2^8$, piksel başına $8 = 2^3$ bit.

İşlem: $2^8 \cdot 2^8 \cdot 2^3 = 2^{19}$.

Hoca bu sonucu 512 KB olarak söyledi.

> **Ders sonrası not:** Hoca $2^{19}$ sonucunu 512 KB olarak söyledi. $2^{19}$ bit cinsindendir: $2^{19}$ bit = 512 Kbit = $2^{16}$ bayt = 64 KB. Hesap sırasında hoca birimleri de karıştırdı; doğrusu $2^{10}$ bayt = 1 KB, $2^{20}$ bayt = 1 MB, $2^{30}$ bayt = 1 GB'tır. Hocanın ilk denemesindeki $2^{24}$ de bit cinsinden alınsaydı 2 MB olurdu; 16 MB, $2^{24}$ bayt için doğrudur.

Python ile doğrulama: $256 \cdot 256 \cdot 8 = 524\,288 = 2^{19}$ bit, $524\,288 / 8 = 65\,536$ bayt = 64 KB.

### 11.5 Büyük ve küçük harf arasındaki fark

`'A'` 65'e, `'a'` 97'ye karşılık gelir. Hoca ikilik açılımlarını yazdı:

| Karakter | Onluk | İkilik |
|---|---|---|
| `'A'` | 65 | `01000001` |
| `'a'` | 97 | `01100001` |

Aradaki fark tek bir bittir (32'lik basamak): büyükten küçüğe geçerken $+32$, küçükten büyüğe geçerken $-32$. Hoca Shift tuşuna basıldığında ya da Caps Lock açıldığında bu bitin 0'dan 1'e döndüğünü, bu kodlama sayesinde harf dönüşümünün basit bir tam sayı toplaması olduğunu söyledi. `'B'` ve `'b'` için de aynı ilişkiye bakılabilir (66 ve 98).

## 12. Format Dizgileri, Sabitler ve Kayan Noktalı Tipler

### 12.1 Tam sayılar için format dizgileri

Format dizgisi `printf`'te bir değerin çıktıda nasıl gösterileceğini, `scanf`'te girdideki değerin nasıl yorumlanacağını belirler. Derleyiciye "okuyacağın şey bir `short int` ya da `unsigned short int`" gibi bir bilgi verir. Slayttaki program (ekrandan, 01:35:00):

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int sayi = 65;
        printf("     int \t%d\n",sayi);
        printf(" uns.int \t%u\n",sayi);
        printf(" srt.int \t%hi\n",sayi);
        printf(" lng.int \t%li\n",sayi);
        printf("usrt.int \t%hu\n",sayi);
        printf("ulng.int \t%ul\n",sayi);
        printf("     char\t%c\n",sayi);
        printf(" uns.char\t%uc\n",sayi);

    system("PAUSE");
    return 0;
}
```

Hoca bu kodun farklı değerlerle denenmesini tavsiye etti. Kod `gcc -Wall` ile derlendi; `%li` satırı için "`long int` bekleniyor ama `int` verildi" uyarısı alındı. `sayi = 65` ile çıktı:

```text
     int 	65
 uns.int 	65
 srt.int 	65
 lng.int 	65
usrt.int 	65
ulng.int 	65l
     char	A
 uns.char	65c
```

`%ul` ve `%uc` aslında `%u` belirtecidir; arkadaki `l` ve `c` harfleri düz metin olarak basılır. `system("PAUSE")` Windows'a özgü bir komuttur; Linux'ta komut bulunamaz ama program yine çalışır.

> **Ek bilgi (derste anlatılmadı):** İşaretsiz uzun tam sayı için doğru belirteç `%lu`'dur; `%ul` değildir. `int` bir değeri `%li` ile yazdırmak tanımsız davranıştır; doğrusu değeri `(long)sayi` diye çevirmektir.

### 12.2 Tam sayı sabitleri

Kod yazarken sabitler farklı tabanlarda yazılabilir: onluk (decimal), sekizlik (octal) ve onaltılık (hexadecimal). Bir değer `int` tipine uyuyorsa `int` olarak yazılır, uymuyorsa daha büyük bir tip olan `long int` kullanılır. Sonek (suffix) olarak işaretsiz için `u` ya da `U`, uzun için `l` ya da `L` eklenir. Hoca özellikle onaltılık yazıma dikkat çekti: `0xFF` 255'tir ve atamalarda böyle yazılabilir. Bu tür yazımlar kod analizi sorularında karşılaşılabilir.

### 12.3 Kayan noktalı tipler

Ondalıklı (gerçel) sayılar için iki tip vardır: `float` ve `double`. Slayttaki bilgiler (ekrandan, 01:40:00):

- `float` (`%f`), `double` (`%lf`).
- `double` çift duyarlık (double precision) demektir; `float`'a göre yaklaşık iki kat duyarlılıkla gösterim yapabilir.
- `float` genelde 4 bayt (32 bit), `double` genelde 8 bayt (64 bit) yer kaplar.
- Ondalık gösterim örnekleri: `0.356`, `5.0`, `0.000001`, `.7`, `7.`
- Bilimsel gösterim (`%e`) örnekleri: `3e2`, `5E-5`
- `long double` tanımlanabilir ama bazı platformlarda düz `double` olur.
- Sınırlar için `<limits.h>`'a bakılmalıdır.

Hoca `limits.h` dosyasının incelenmesini istedi. `%5.7f` gibi format değiştiricileri için kitaba ya da internet kaynaklarına bakılabileceğini söyledi.

> **Ders sonrası not:** Hoca `float` ile `double` için "Float ve Long Float" dedi ve `%5.7f`'yi "virgülden önce 5, sonra 7 karakter" diye açıkladı. Standart C'de tip adı `double`'dır. `%5.7f`'de 5 toplam en az alan genişliği, 7 ondalık basamak sayısıdır.

## 13. İlklendirme ve Bellek-Hız Dengesi

Hoca ilklendirmenin (initialization) neden gerekli olduğunu işletim sistemi açısından anlattı. Program yazılır, derlenir ve çalıştırılabilir (executable) hali oluşturulur. Program çalıştırıldığında bu kodun bir kopyası RAM'e yüklenir. Kullanılan değişkenler ve diziler belli bir düzene göre saklanır; bu düzende başlangıç değeri verilmiş (initialized) ve verilmemiş (uninitialized) değişkenler ayrı yerlerde tutulur. Hoca bunun işletim sistemleriyle ilgili bir konu olduğunu söyledi.

Başlangıç değeri örneğin faktöriyel hesabında gerekir; klavyeden dizi elemanları okunup toplamı bulunacaksa toplam değişkenine bir yerde sıfır atanır. Tanımlama sırasında değişkene yapılan atamaya ilklendirme denir. `int a; a = 5;` ile `int a = 5;` aynı işi yapar; ikincisinde tanım ve atama tek satırdadır. Eskiden bu iki yazımın derleyicideki karşılıkları performans açısından karşılaştırılırdı; hoca günümüz bilgisayarlarında buna gerek olmadığını söyledi.

Bu karşılaştırma bir denge (trade-off) konusudur. Hoca beyaz tahtada bellek (memory) ile hız (speed) arasında ters orantı olduğunu yazdı (ekrandan, 02:15:00): bellekten ödün verilirse hızdan kazanılır, hızdan ödün verilirse bellekten kazanılır. Hangisine ihtiyaç varsa ona göre karar verilir.

## 14. Tip Karıştırma: Örtük ve Açık Dönüşüm

Slayttaki başlıklar (ekrandan, 01:45:00): örtük dönüşüm (implicit conversion), işaretli ve işaretsiz tiplerin karıştırılması, tam sayılarla kayan noktalı tiplerin karıştırılması ve açık dönüşüm (explicit conversion).

### 14.1 Tip hiyerarşisi

Tipler birbirine dönüştürülürken bir hiyerarşiye dikkat etmek gerekir. `int` de `unsigned int` de 4 bayt olabilir, ama değer aralıkları farklıdır. Büyük bir aralığı küçük bir aralığa sığdırırken dikkat edilmelidir.

> **Ders sonrası not:** Hoca `int`'in $2^{32}-1$'e kadar gittiğini ve bu değerin işaret biti yüzünden `unsigned int`'e sığmadığını söyledi. Tersidir: `unsigned int` $2^{32}-1$'e kadar gider ve bu değer işaret biti olan `int`'e sığmaz (`int` en fazla $2^{31}-1$).

### 14.2 Örtük dönüşüm

Programda işlem yaparken farkında olmadan bazı dönüşümler gerçekleşir; bunlara örtük (implicit, gizli) dönüşüm denir. Derleyici bir ifadeyle karşılaşınca onu alt ifadelere böler. Alt ifadeler operandlardan ve operatörlerden oluşur. Slayttaki ifade `-3 / 4 + 2.5` idi: operatörler `-`, `/`, `+`; operandlar `3`, `4`, `2.5`. Operatörlerin tanım kurallarına göre gizli dönüşümler yapılabilir. Toplama operatörü örneğin bir `double` ile bir `int` için tanımlı değilse ya hata verilir ya da gizli bir dönüşümle toplama yapılır.

> **Ek bilgi (derste anlatılmadı):** `-3 / 4 + 2.5` ifadesinde önce `-3 / 4` iki tam sayı arasında yapılır ve sıfıra doğru kesilerek 0 olur; sonra 0, `double` olan 2.5 ile toplanırken `double`'a çevrilir ve sonuç 2.5 olur. Bu sonuç gcc ile doğrulandı.

Hoca örnek verdi: `int a = 3.5 + 2;`. Toplama operatörü float ile int için tanımlıdır, sağ taraf 5.5 olur. Sol tarafta `int` tanımı olduğu için 5.5'in tam kısmı 5 kopyalanır (5.0 değil, 5). Bu bir örtük dönüşümdür. gcc ile çalıştırıldığında `a` = 5 yazdırıldı.

### 14.3 İşaretli ve işaretsiz tiplerin karıştırılması

İkisi de tam sayı olan ama biri işaretli, biri işaretsiz iki değer karıştırıldığında gizli bir dönüşüm olabilir. Hoca aynı bit dizisinin işaretli okunduğunda $-22$, işaretsiz okunduğunda $234$ olduğunu gösterdi. Bir işlemin sonucu ifade işaretsiz alınırsa başka, işaretli alınırsa başka çıkar; hangisinin kullanılacağını bilmek gerekir. <!-- BELİRSİZ: Bu slaydın kodu karelerde yok; değerler altyazıdan alındı. -->

8 bit için doğrulama: $256 - 22 = 234$; `signed char s = -22;` değeri `unsigned char`'a çevrilince gcc'de 234 yazdırıldı.

### 14.4 Tam sayılarla kayan noktalı tiplerin karıştırılması

Slayttaki örnek (ekrandan, 01:50:00):

```c
int j;
float f;
j + f;                  // j is converted to float
j + f + 2.5;            // j and f both converted to double

j = 2.5;                // j's value is 2
j = 999999999999.888888 // overflow
```

`j + f`'te `j` otomatik olarak float'a dönüştürülür. `j + f + 2.5`'te 2.5 bir `double` sabiti olduğu için `j` ve `f` ikisi de `double`'a çevrilir. `j` `int` olduğu için `j = 2.5` atamasında hassasiyet kaybı olur ve `j` 2 olur. `j`'ye çok büyük bir değer atanırsa değer sığmadığı için taşma (overflow) olur.

### 14.5 Açık dönüşüm (cast)

Açık (explicit) dönüşümde bir ifadenin tipi bilerek başka bir tipe çevrilir; buna cast denir. Hocanın anlattığı örnekte `k` ve `j` tam sayıdır, `k = 3`, `j = 2`'dir (altyazıdan):

- `f = (float)(k / j);` Önce `k / j` tam sayı bölmesi yapılır: 3 / 2 = 1. Sonra 1 float'a çevrilir: 1.0. Dönüşüm açıktır ama veri kaybı olmuştur.
- `f = (float)k / j;` Önce `k` float'a çevrilir: 3.0. Bölme operatörünün bir operandı float olduğu için `j` de örtük olarak float'a çevrilir. 3.0 / 2 = 1.5 olur ve `f`'ye 1.5 atanır. Burada hem açık hem örtük dönüşüm birlikte yapılmıştır.

<!-- BELİRSİZ: Açık dönüşüm slaydının kodu karelerde yok; yazım altyazıdan kuruldu. --> İki sonuç gcc ile doğrulandı (1.0 ve 1.5).

## 15. enum, void ve typedef

### 15.1 enum

Numaralandırma (enumeration) tipi, bazı değişkenlere etiket atamak için kullanılır. Özellikle kategorik değişkenler 0, 1, 2, 3 gibi sayılarla ya da belli adlarla temsil edilir. Slayttaki örnek (ekrandan, 01:55:00):

```c
enum { red, blue, green, yellow } color;
enum { bright, medium, dark } intensity;

color = yellow;          // OK
color = bright;          // Type conflict
intensity = bright;      // OK
intensity = blue;        // Type conflict
color = 1;               // Type conflict
color = green + blue;    // Misleading usage
```

Slayttaki kurallar: enum tipleri değişkenleri ve o değişkende saklanabilecek adlandırılmış sabitler kümesini bildirmeyi sağlar. Varsayılan değerler sıfırdan başlar ve her yeni adla bir artar. Başka değerler verilerek varsayılanlar değiştirilebilir (override); hoca bunun ileride görüleceğini söyledi.

Hoca satırları şöyle açıkladı: `color`'a `yellow` atanabilir. `bright` atanamaz, çünkü bu tipin içinde böyle bir değer yoktur. `intensity`'ye `bright` atanabilir, `blue` atanamaz. `color = 1` olmaz, çünkü 1 diye bir etiket yoktur. İlginç olan `green + blue`'dur: `green`'in kodu (2) ile `blue`'nun kodu (1) toplanır ve 3 elde edilir. Bu toplama yanlış sonuçlara ve tanım dışına çıkmaya yol açabilir. Hoca enum'un ileride özellikle struct'larla ve `switch-case` yapısında kullanılacağını söyledi.

> **Ders sonrası not:** Slaytta "Type conflict" yazan satırlar C'de derleme hatası vermez. Bu satırlar gcc 15 ile `-Wall` seçeneğiyle uyarısız derlendi, çünkü C'de enum sabitleri `int` gibi davranır. Bu atamalar C++'ta hatadır. Slayttaki kural yine de doğru kullanım için uyulması gereken kuraldır.

**Soru:** Enum'daki adları (red, blue, green) tamamen büyük harfle yazmak yasak mı?
**Cevap:** Hayır, yazılabilir. Hoca `#define` ile yapılan tanımlarda olduğu gibi `RED`, `GREEN`, `BLUE` biçiminde etiket tarzı yazmanın doğru ve yaygın bir kullanım olduğunu söyledi.

### 15.2 void

Programlamaya C ile başlayanlara genelde "fonksiyon bir şey döndürmüyorsa `void` yaz, `void` herhangi bir tip ifade etmez" denir. Hoca aslında `void`'in bir tip ifade ettiğini, ama doğrudan herhangi bir tip üzerinde işlem yapmadığını söyledi. Java'daki `Object` tipine benzer ama tam onun gibi değildir. Her tip `void` üzerinden birbirine dönüştürülebilir ve bu sayede genel (generic) bir işaretçi elde edilir. Fonksiyonlarda `void` yazılması, fonksiyonun değer döndürmediğini gösterir. Bir başka kullanım fonksiyon işaretçileridir: örneğin bir toplama algoritması float tabanlı, int tabanlı ya da başka bir tipte olabilir; algoritmayı her tipte çalıştırmak için `void` kullanılacaktır. Hoca bunu ilerleyen haftalarda örneklerle açıklayacağını söyledi.

### 15.3 typedef

`typedef` var olan bir veri tipine kendi verdiğimiz bir ad tanımlamayı sağlar. Slayttaki örnek (ekrandan, 02:00:00):

```c
typedef long int INT32;

long int j;
INT32 j;
```

Anlamsal olarak yeni ad, veri tipinin eş anlamlısı olur. Alışkanlık olarak `typedef` adları büyük harfle yazılır. `long int j;` ile `INT32 j;` aynı tanımı yapar. Hoca bunun dili istenen dile dönüştürmek gibi bir şey olduğunu, örneğin `int` yerine `tamsayi` gibi bir ad verilebileceğini söyledi. Yazımı: `typedef`, boşluk, değiştirilecek ifade, boşluk, yeni etiket. Tanım `main`'den önce yazılır. Hoca `typedef`'in özellikle struct'larla çok kullanılacağını ve o konuda daha sistematik anlatılacağını söyledi.

> **Ders sonrası not:** Hoca `typedef` için "nerede INT32 görürsen yerine long int kopyalar" dedi. Bu davranış `#define`'a aittir. `typedef` metin yerine koyma yapmaz; derleyicinin işlediği bir tip eş adıdır. Örneğin `typedef int *IP; IP a, b;` ifadesinde `a` ve `b` ikisi de işaretçidir, `#define IP int *` ile ise yalnız `a` işaretçi olur.

## 16. Kaçış Karakterleri ve Noktalı Virgül

### 16.1 Kaçış karakterleri

Hoca `printf`'te kullanılan kaçış karakterlerinin bilindiğini varsayarak kısaca saydı: `\n` (alt satıra geçme), `\t` (sekme, birkaç karakter boşluk), `\\`, `\"`, `\'`. Bunlar iki tırnak arasındaki ifadelerde özel karakterleri yazmak için kullanılır. `\a` ses çıkarır; hoca bunun her bilgisayarda çalışmadığını söyledi.

### 16.2 Noktalı virgül

Noktalı virgül her yerde kullanılmaz. Hoca noktalı virgülün bir emir cümlesini (imperative) sonlandırdığını söyledi. "Ekrana 3 yaz" bir emir cümlesidir; C'de `printf("3");` diye yazılır ve sonuna noktalı virgül konur. Ama `if (x == 3)` bir emir değildir. Buraya noktalı virgül konursa (`if (x == 3);`) program hata vermez, çalışır, ama yanlış yapılmış olur: noktalı virgül konmamalıdır. Aynı şey `for` ve `while` başlıkları için de geçerlidir: `for` başlığından sonra konan noktalı virgül döngüyü geçersiz kılar ve döngünün gövdesi çalışmaz. Hoca bunun döngüler konusunda tekrar ele alınacağını söyledi.

> **Ders sonrası not:** `for (...);` yazıldığında döngü boş bir gövdeyle sayısı kadar döner; arkasındaki `{ ... }` bloğu döngünün parçası olmaktan çıkar ve döngü bittikten sonra yalnızca bir kez çalışır.

## 17. Operatörler ve İşlem Önceliği

Aritmetik operatörler bilinen operatörlerdir. İşlem önceliği:

- En önce parantezler.
- Sonra çarpma, bölme ve mod (`*`, `/`, `%`). Birden fazla varsa soldan sağa yapılır.
- Sonra toplama ve çıkarma (`+`, `-`); aynı kural geçerlidir.

### 17.1 Adım adım örnek

Slayttaki örnek (ekrandan, 02:05:00): `y = 2 * 5 * 5 + 3 * 5 + 7;`

| Adım | İfade | İşlem | Açıklama |
|---|---|---|---|
| 1 | `y = 2 * 5 * 5 + 3 * 5 + 7;` | `2 * 5` = 10 | En soldaki çarpma |
| 2 | `y = 10 * 5 + 3 * 5 + 7;` | `10 * 5` = 50 | En soldaki çarpma |
| 3 | `y = 50 + 3 * 5 + 7;` | `3 * 5` = 15 | Çarpma toplamadan önce |
| 4 | `y = 50 + 15 + 7;` | `50 + 15` = 65 | En soldaki toplama |
| 5 | `y = 65 + 7;` | `65 + 7` = 72 | Son toplama |
| 6 | `y = 72;` | | Son işlem: 72, `y`'ye yerleştirilir |

Hoca hem işlem önceliğine hem de aynı öncelikte birden fazla operatör varsa soldan sağa gidilmesine dikkat çekti. Sonuç gcc ile doğrulandı: 72.

### 17.2 Eşitlik ve ilişkisel operatörler

Eşitlik operatörleri `==` ve `!=`, ilişkisel operatörler `>`, `<`, `>=`, `<=`'dir. Öncelik ve birleşme (associativity) tablosunda yukarıdan aşağıya sıra:

- `*`, `/`, `%` (aynı seviyede soldan sağa)
- `+`, `-`
- `<`, `<=`, `>`, `>=`
- `==`, `!=`
- `=` (atama)

Atama operatörü en sondadır, çünkü önce bütün işlemler (toplama, çarpma vb.) yapılır, en son sonuç bir değişkenin yerinde saklanır. Atama sağdan sola doğru yapılır.

> **Hocanın vurgusu:** Tip dönüşümleri ve operatör öncelikleriyle ilgili kısımlara mutlaka bakın; bir sonraki derste bu konulara bakılacak.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:21:13): Bir `f(x)` fonksiyonu bir değer döndürüyor. `f(x) + 2` legal bir ifade midir?

> **Çözüm:** Evet. Fonksiyondan dönen değer bir ifadedir; ona 2 eklenebilir. Aynı mantıkla `rand() % 10` 0-9 aralığında bir tam sayı verir.

**Soru 2** (derste sözlü, 00:25:21): R-value kümesi L-value kümesini kapsar diyebilir miyiz?

> **Çözüm:** Evet. Sol tarafa yazılabilen her şey (değişken, dizi hücresi) sağ tarafa da yazılabilir. Sağ tarafa ayrıca sabit, fonksiyon çağrısı ve matematiksel işlem gelebilir; bunlar sol tarafa yazılamaz (`5 = a;`, `f = a;` geçersizdir).

**Soru 3** (derste sözlü, 00:26:25): Fonksiyon bir işaretçi döndürüyorsa, önüne yıldız koyarak atamanın sol tarafına yazabilir miyiz?

> **Çözüm:** Hoca fonksiyon çağrısının sonucuna doğrudan atama yapılamayacağını söyledi ve yıldızın bir işaretçi değişkenle anlamlı olduğunu gösterdi: `int *a; int b = 0; a = &b; *a = f(x);` geçerlidir, çünkü `*a` `b`'nin yeridir (ekrandan, 00:30:00).

> **Ek bilgi (derste anlatılmadı):** C'de `int *g(void);` gibi işaretçi döndüren bir fonksiyon için `*g() = 5;` de derlenir, çünkü `*g()` döndürülen adresteki nesneyi gösterir ve bir L-value'dur. Döndürülen adresin geçerli bir nesneyi göstermesi gerekir.

**Soru 4** (ekrandan, 00:50:00): `#define NOTHING 0` tanımlıyken `NOTHING = j + 5` yazılabilir mi?

> **Çözüm:** Hayır. Önişlemci `NOTHING` yerine 0 yazar ve ifade `0 = j + 5` olur. Sol tarafta sabit olamayacağı için geçersizdir.

**Soru 5** (derste sözlü, 01:29:49): 1 bayt ile neden $2^7$ oluyor?

> **Çözüm:** İşaretli sayılarda 8 bitten biri işarete gider, kalan 7 bit değeri gösterir. Aralık $-2^7 = -128$ ile $2^7 - 1 = 127$ arasıdır.

**Soru 6** (derste sözlü, 01:31:13): 256 x 256 boyutunda, her pikseli 256 renk (8 bit) taşıyan bir resim ne kadar yer kaplar?

> **Çözüm:** $2^8 \cdot 2^8 \cdot 2^3 = 2^{19}$ bit. Hoca bunu 512 KB olarak söyledi; $2^{19}$ bit = $2^{16}$ bayt = 64 KB'tır (512 Kbit). Bkz. 11.4.

**Soru 7** (ekrandan, 01:35:00): Format dizgileri programında `sayi` 128 olduğunda çıktı nedir? (Hoca böyle bir sorunun sorulabileceğini söyledi; çözümü vermedi.)

> **Çözüm (derste verilmedi):** Program `int sayi = 128;` ile gcc 15, 64 bit Linux'ta derlenip çalıştırıldı:
>
> ```text
>      int 	128
>  uns.int 	128
>  srt.int 	128
>  lng.int 	128
> usrt.int 	128
> ulng.int 	128l
>      char	(128 kodlu bayt; ASCII dışı, yazdırılabilir değil)
>  uns.char	128c
> ```
>
> 128, `short` ve `unsigned short` aralığına sığdığı için tam sayı satırları değişmez. `%c` satırı 128 kodlu baytı basar; bu ASCII tablosunun (0-127) dışındadır ve terminalde anlamlı bir karakter görünmez. `%li` satırı tip uyumsuzluğu yüzünden tanımsız davranıştır, ama bu sistemde 128 yazdı. `%ul` ve `%uc` satırlarında `l` ve `c` düz metindir.

**Soru 8** (derste sözlü, 01:55:28): Enum'daki adları tamamen büyük harfle yazmak yasak mı?

> **Çözüm:** Hayır. `#define` sabitlerinde olduğu gibi büyük harfle etiket tarzı yazmak doğru ve yaygın bir kullanımdır.

**Soru 9** (ekrandan, 02:05:00): `y = 2 * 5 * 5 + 3 * 5 + 7;` ifadesinden sonra `y` kaçtır?

> **Çözüm:** 2 * 5 = 10; 10 * 5 = 50; 3 * 5 = 15; 50 + 15 = 65; 65 + 7 = 72. `y = 72`.

## Dersin Toparlaması

Bu derste C'nin temelleri bellek yönetimi gözüyle tekrar edildi. Değişken, bellekte adresi, değeri, etiketi, boyutu ve tipi olan bir hücredir. Adlandırma kuralları, ifadeler, atamada L-value ve R-value ayrımı, yorum satırları ve fonksiyonlar anlatıldı. Fonksiyonlarda yüksek cohesion ve düşük coupling ilkesi vurgulandı, prototip, `main`, `exit`, `printf`/`scanf` ve önişlemci komutları (`#define`, `#include`) ele alındı. İkinci bölümde veri tipleri ağacı, `int`, `int *` ve `int **`'ın farklı tipler olduğu, tam sayı aralıkları, karakterlerin sayı olarak saklanması, format dizgileri, kayan noktalı tipler, ilklendirme, örtük ve açık tip dönüşümleri, `enum`, `void`, `typedef`, noktalı virgül kullanımı ve operatör önceliği işlendi.

Hoca bir sonraki derste koşullar (`if`) ve döngülerle devam edileceğini söyledi. İşaretçilerle ilgili eksikleri olanların bu konuya çalışmasını tavsiye etti; işaretçiler hem dinamik bellek ayırmada hem struct'larda hem de fonksiyonlarda ayrıntılı olarak kullanılacaktır. Hocanın özetiyle: C bilmek, işaretçi bilmek ve bellek yönetimini bilmektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
