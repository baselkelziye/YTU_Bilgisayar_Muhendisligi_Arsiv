# Ders 14 Genişletilmiş Notu: Fonksiyon Tasarım İlkeleri, Bellekte Fonksiyon Çağrısı, Min-Max Bulma ve En Yakın İkili Problemi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Fonksiyonların amacı ve dokümantasyonu
- 2. Fonksiyon tanımı, çağrısı, parametre ve argüman
- 3. Fonksiyon tasarım ilkeleri: düşük bağlaşım, yüksek uyum
- 4. Akış diyagramında fonksiyon gösterimi
- 5. Programın bellekteki yerleşimi ve fonksiyon çağrısı
- 6. Dizinin en küçük ve en büyük elemanını bulan fonksiyon
- 7. Aynı fonksiyonla matrisin en küçük ve en büyük elemanı
- 8. Dizi, dizi elemanı ve adres göndermek
- 9. Fonksiyon aşırı yükleme (overloading)
- 10. En yakın ikili (closest pair) problemi
- 11. Gerçek hayat senaryoları: çöpçatan sitesi ve doktor-hasta teşhisleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Fonksiyonların amacı ve dokümantasyonu

Ders, daha önce başlanan fonksiyonlar konusunun ayrıntılarıyla başlar. Hoca önce birkaç slayt ve ders notu üzerinden kavramları anlatır, sonra örneklere geçer.

Fonksiyon, isimlendirilmiş ve parametre alabilen bir algoritmadır; başka algoritmalar tarafından kullanılır (ekrandan, 00:10:00). Ders notunda genel gösterim şöyledir:

```text
[çıkış parametreleri] = Fonksiyon_ismi(giriş parametreleri)
```

Çıkış parametrelerinin çoğul yazılmasının sebebi, Python ve MATLAB gibi bazı dillerde bir fonksiyondan birden fazla değer döndürülebilmesidir. C'de "döndürmek" `return` ile döndürmek demektir ve `void` olmayan bir fonksiyon en fazla bir değer döndürebilir. Her dil birden fazla çıkışı desteklemez, ama genelde tek çıkış yeterlidir.

Fonksiyonların faydaları:

- Bir kez yazılır, tekrar tekrar kullanılır; başkaları da kullanabilir.
- Böl-yönet: büyük bir çalışma daha küçük parçalara, modüllere ayrılır. Ama her şey parçalanmaz, bunun bir ölçütü vardır (Bölüm 3).
- Kolay düzeltme: bin satırlık, yalnız `main`'den oluşan bir kodda hatanın yerini bulmak zordur; fonksiyonlara bölünmüş kodda kolaydır.
- Kolay bakım ve güncelleme.
- Yazılım mühendisliği açısından kod tekrarının önüne geçilir; bundan sonra modüler yapı tercih edilecektir.

Her algoritma gibi fonksiyonlar da iyi dokümante edilmelidir:

- Fonksiyonun hangi parametreleri aldığı, onlarla ne yaptığı ve hangi kısıtlar altında çalıştığı açıklama satırı olarak yazılır. Örneğin "dizinin en büyük elemanını bulan fonksiyon" için parametreler ve yapılan iş bellidir; varsa kısıtlar yazılır.
- Fonksiyonda iki tür değişken tanımlanır: gelen parametreleri alanlar ve gövdede ihtiyaç duyulan yardımcı değişkenler. Yardımcı değişkenlerin ne tuttuğu da açıklanmalıdır.
- Değişken adları ne tuttuğunu ifade etmelidir; `x`, `y`, `z` yerine gerekirse birkaç kelimeden oluşan uzun adlar kullanılır (`nameOfStudent`, `numberOfStudents` gibi).

## 2. Fonksiyon tanımı, çağrısı, parametre ve argüman

Hoca, Deitel'in fonksiyon slaytlarına (CHTP4_05_functions) bir şekil eklediğini söyler: bir C programında bir ana program (`main`) ve yardımcı fonksiyonlar (worker) vardır; `main` örneğin `worker1`, `worker2`, `worker3`'ü çağırır, bunlardan biri de `worker4` ve `worker5`'i çağırır. Fonksiyonlar ikiye ayrılır: kütüphane (hazır) fonksiyonları ve kullanıcının tanımladığı fonksiyonlar. İkisi de programın karmaşıklığını azaltır.

Daha önce dört durumdan söz edilmişti: dönüş tipi `void` olan ya da olmayan, parametre alan ya da almayan fonksiyonlar. Bir şey döndürmeyen fonksiyon `void`'dir ve içinde değer döndüren `return` kullanılmaz. Bir şey döndüren fonksiyonda `return` zorunludur; döndürülen şey tek olmalıdır: bir değişken, bir dizi elemanı, bir karakter ya da bir pointer olabilir. Parametre alınmayacaksa parantez boş bırakılır; bir ya da birden fazla parametre alınabilir.

Hoca boş bir slayta "Functions", "Definition" ve "Call / Invoke" başlıklarını açar (ekrandan, 00:05:00) ve tanımın genel kalıbını altına yazar:

```text
return_type (void ya da diğerleri)  function_name ( params )
{
    değişken tanımları (variable declarations)
    ...
    işlemler
}
```

Fonksiyonu kullanmaya çağırma (call ya da invoke) denir. Çağrıda gönderilenlere **argüman**, tanımda yazılanlara **parametre** denir. Örnek:

```c
int f1(int x, char c){
    /* ... bir şeyler yapar ... */
    return something;
}
/* çağrı: */
x = f1(8, 'c');
```

Burada `8` ve `'c'` argüman, `x` ve `c` parametredir; işlemin sonunda dönen değer fonksiyonun sonucudur.

## 3. Fonksiyon tasarım ilkeleri: düşük bağlaşım, yüksek uyum

Programı parçalara bölerken doğru bölmenin iki ölçütü vardır: coupling (bağlaşım) ve cohesion (uyum). Aralarında ilişki vardır ama önce ayrı ayrı düşünülür.

### 3.1 Düşük bağlaşım (low coupling)

Slayttaki tanımlar (ekrandan, 00:15:00):

- Bağlaşım: bir parçanın diğer parçalara bağımlılık oranıdır. Parça bir sınıf, alt sistem ya da paket olabilir.
- Bağımlılık: bir sınıfın diğerinin hizmetlerinden yararlanması, iç yapısından haberdar olması, çalışma prensiplerinden haberdar olması, onun özelleşmiş ya da genelleşmiş hali olması (kalıtım ilişkisi).
- Diğer sınıfların sayısı arttıkça bağlaşım oranı artar.
- Düşük bağlaşımın yararları: bir sınıfta yapılan değişiklik geri kalan sınıfların daha azını etkiler; yeniden kullanılabilirlik artar.

Hoca bunu bir örnekle açıklar. Bir `F1` fonksiyonu bir iş yapıyor, ardından ona biraz bağlı başka bir iş, sonra yine başka işler yapıyor olsun. Örneğin fonksiyon diziyi hem sıralıyor hem yazdırıyor. Sıralamak bir iş, yazdırmak başka bir iştir. On elemanlı dizide sorun görünmez, ama bir milyon elemanlı diziyi sıraladıktan sonra yazdırmak istemezsiniz; ilgilendiğiniz şey verinin sıralı olmasıdır. Doğrusu işleri `F1`, `F2`, `F3` diye ayrı fonksiyonlara bölmek ve hangisi lazımsa onu çağırmaktır. Gerekirse `F1`, `F2`, `F3`'ü sırayla çağıran bir `F4` yazılır; buna **sarmalayıcı (wrapper) fonksiyon** denir. Her şeyi tek fonksiyonda yapmak yüksek bağlaşımdır, ayrı fonksiyonlar düşük bağlaşımdır.

Yüksek bağlaşımın bir sonucu kod tekrarıdır. Diziye ya da matrise eleman okuyan bir fonksiyon, okuduğunu ekrana da yazdırıyorsa, sıralamadan sonra da yazdırmak gerektiğinde aynı yazdırma satırları ya kopyala-yapıştır yapılır ya da yeniden yazılır. Sayısal analizden örnek: Newton-Raphson, interpolasyon, sayısal integral ve türev gibi yöntemlerin çoğunda bir $x$ için $f(x)$ hesaplanır. Bunun için bir kez "function evaluation" fonksiyonu yazılır ve bütün yöntemlerde çağrılır; her algoritmanın içine ayrıca yazılmaz.

> **Hocanın vurgusu:** Bu, yazılım mühendisliğinin temel kuralıdır; ileride göreceğiniz nesne yönelimli programlama bunun üzerine kuruludur. Bu derste de bu kurala uyulacak.

### 3.2 Yüksek uyum (high cohesion)

Slayttaki tanımlar (ekrandan, 00:20:00):

- Uyum: bir parçanın sorumluluklarının birbirleri ile uyumlu olma oranıdır.
- Yüksek uyumun yararları: sınıfın anlaşılma kolaylığı artar, yeniden kullanılabilirlik artar, bakım kolaylığı artar, sınıfın değişikliklerden etkilenme olasılığı düşer.
- Genellikle düşük bağlaşım getiren bir tasarım yüksek uyumu, yüksek bağlaşım getiren bir tasarım ise düşük uyumu beraberinde getirir.

Bir fonksiyonun adı, aldığı parametreler ve yaptığı işler birbiriyle tutarlı olmalıdır. Hoca bunu "İsviçre çakısı gibi fonksiyon yazılmaz" diye anlatır: aynı fonksiyonda hem $f(x)$ hesaplayıp hem doğrusal olmayan denklemin kökünü bulup hem sayısal integral almak, hem bağlaşım hem uyum kuralına aykırıdır. Matrise veri okuyan fonksiyon yalnız veri okur, verileri ekrana yazdırmaz. İki kural birbirini tamamlar; birini bozarsanız öbürü de bozulur.

## 4. Akış diyagramında fonksiyon gösterimi

Hoca slayttaki bir örnek üzerinden fonksiyonun akış diyagramında nasıl gösterildiğini anlatır. Ana programda başlangıç (start), dizinin elemanlarının ve eleman sayısının kullanıcıdan alınması, sonra bir maksimum bulma fonksiyonunun çağrılması ve bulunan değerlerin yazdırılması vardır. Örnekte fonksiyon iki değer döndürüyor gibi çizilmiştir; hoca C'de bunun başka bir yolla (pointer ile) yapılacağını hatırlatır.

Fonksiyonun kendi akış diyagramında, ok işaretine benzeyen kutunun üst tarafına fonksiyonun adı ve giriş parametreleri, altına çizilen çizginin altına çıkış parametreleri yazılır. Geri kalan her şey (döngü, `if`, matematiksel işlem) aynıdır. Fonksiyonun sonunda bir **stop** vardır; stop bir `return` gibi düşünülür: fonksiyon tamamlanır ve çağrıldığı yere geri dönülür.

<!-- BELİRSİZ: akış diyagramı slaydı kareye düşmedi; anlatım yalnız altyazıdan kuruldu. -->

**Soru:** Akış diyagramında `return` gibi bir yazıya ihtiyacımız var mı? **Cevap:** Yok; akış diyagramında `return` yazılmaz, doğrudan stop denir.

## 5. Programın bellekteki yerleşimi ve fonksiyon çağrısı

Buraya kadar anlatılanlar işin kâğıt üzerindeki kısmıdır. Fonksiyon bir programın içinde çalıştığı için bir de programın bellekteki yerleşimine (program allocation in memory) bakılır.

### 5.1 Bellek bölgeleri

Hangi dilde yazarsanız yazın, derlenip çalıştırılan programa bilgisayarın belleğinde (RAM) bir yer ayrılır. Bellek yalnız sizin programınızdan ibaret değildir; programın bölgesinin altında ve üstünde başka bölgeler de vardır. Hocanın gösterdiği şekil (ekrandan, 00:25:00) alttan üste şöyledir:

| Bölge | Erişim | Ne zaman / kim yönetir |
|---|---|---|
| Instructions | salt okunur, çalıştırılabilir | süreç başlarken yüklenir |
| Literals | salt okunur, çalıştırılamaz | süreç başlarken yüklenir |
| Static Data | yazılabilir, çalıştırılamaz | süreç başlarken yüklenir |
| Dynamic Data (Heap) | yazılabilir, çalıştırılamaz | programcı yönetir |
| (boş alan) | | heap yukarı, stack aşağı büyür |
| Stack | yazılabilir, çalıştırılamaz | derleyici "otomatik" yönetir |

- Instructions: programın kodu; `#include <stdio.h>`'tan son satıra kadar bütün fonksiyonlar buradadır.
- Literals: başlangıç değeri verilen şeyler, örneğin `int x = 8` gibi.
- Static Data: statik veriler.
- Heap: dinamik veriler burada tutulur; ileride görülecek.
- Stack: üst üste binen bir yapı; bir şey alınacaksa tepeden alınır. Hoca, heap'in aşağıdan yukarı, stack'in yukarıdan aşağı dolduğunu söyler.

### 5.2 Çağrı yığını adım adım

Hoca şu programı çizer ve satırlara numara verir (ekrandan, 00:30:00):

```text
1  main() {          10 f1() {        20 f2() {        30 f3() {        40 f4() {
2     f1();          11    f3();      21    f3();      31    f4();           ...
3     f2();             ...              ...              ...           }
   ...               }                }                }
}
```

Program `f1` ve `f2`'yi kullanır; `f1` ve `f2` içeriden `f3`'ü, `f3` de `f4`'ü çağırır. Program ikili kod olarak Instructions bölgesine yerleşmiştir ve işlemci komutları sırayla çeker.

1. `main` çağrılınca stack'e eklenir. `main`'in yerel değişkenleri ve elde edilen sonuçlar burada durur.
2. 2. satırda `f1` çağrılır. `f1` bitince programın 3. satırdan devam etmesi gerekir; bu yüzden "2. satırda kaldım" bilgisi stack'te saklanır. `f1` stack'in tepesine eklenir, kendi yerel değişkenleriyle birlikte.
3. `f1` 10. satırdan 11. satıra geçer ve `f3`'ü çağırır. 11 bilgisi saklanır, `f3` stack'e eklenir.
4. `f3` 31. satırda `f4`'ü çağırır. 31 saklanır, `f4` stack'e eklenir.
5. `f4` başka çağrı yapmadan biter ve stack'ten silinir. Bu yüzden fonksiyonda tanımlanan değişkenler kalıcı değildir.
6. Saklanan 31 okunur, `f3` 32, 33... satırlarla devam eder ve biter; silinir. 11 okunur, `f1` 12, 13... satırlarla devam eder ve biter; silinir. 2 okunur, `main` 3. satırdan devam eder.
7. 3. satırda `f2` çağrılır; 3 saklanır. `f2` 21. satırda `f3`'ü, `f3` 31. satırda `f4`'ü çağırır ve aynı ekleme-silme süreci tekrarlanır.
8. En sonunda `main` de tamamlanır (`return 0`) ve program biter.

> **Hocanın vurgusu:** Fonksiyon çağrısında arka planda olan olaylar bunlardır; bu çok önemli bir şey.

**Soru:** Fonksiyonlar için yeni bir stack açtığımızda işletim sistemi stack'e yalnız değişkenleri mi alıyor, fonksiyona ait komutları da mı? **Cevap:** Bu işler siz fonksiyonu çağırınca işletim sisteminin denetiminde yapılır. Fonksiyonun komutları zaten Instructions bölgesindedir, stack'e alınmaz. Ama stack'e yalnız değişkenler de alınmaz. İşlemcinin içinde program counter vardır; programın hangi satırda kaldığını tutan bu değerin yedeği alınır (yukarıdaki 2, 11, 31 bilgileri). İşlemcinin durum yazmacı (status register; toplamada elde, çıkarmada ödünç olup olmadığını tutan bayraklar) gibi durum bilgisi de yedeklenir. Değişkenlerin son değerleri de orada saklanır. Yapı bundan daha karmaşıktır, ama fonksiyon çağırınca bunların arka planda olduğunu bilmek gerekir.

Bu ayrıntı şunun için lazımdır: `f1` içinde tanımlanan yerel değişken yalnız `f1` çalışırken vardır, fonksiyon bitince yok olur. Kalıcı olması istenirse heap bölgesinden yararlanılır (`malloc` gibi); bu, sonraki dönem görülecek bir konudur. Değişkenin ne kadar yaşadığına lifetime ya da duration denir. Stack'teki değişkenler yazılıp silindiği için tekrar yaşamaz.

Hoca konuyu üç bakış açısıyla bağlar: yazılım mühendisliği, sistem ve programlama. Kod yazarken bellek göz önüne gelmelidir.

## 6. Dizinin en küçük ve en büyük elemanını bulan fonksiyon

### 6.1 Prototip

Bazı dillerde gerekmez ama C'de fonksiyonlar `main`'den sonra yazılıyorsa prototiplerinin yazılması gerekir. Prototipte değişken adları yazılmayabilir, yalnız tipler yeterlidir: derleyici yalnız "bir dizi, bir `int`, bir `int` pointer, bir `int` pointer gelecek" bilgisine bakar. En kolayı tanım satırını kopyalayıp sonuna `;` koymaktır. Derste prototip unutulduğunda Dev-C++ "implicit declaration" notu ve "conflicting types" uyarısı verdi (ekrandan, 00:45:00).

### 6.2 Kod

Tek fonksiyonda hem en küçük hem en büyük elemanın yeri (indisi) bulunacaktır. İki sonuç olduğu için `return` kullanılamaz; fonksiyon `void` olur ve sonuçlar pointer parametrelerle çağrılan yere yazılır. Döngü 1'den başlar, çünkü 0. eleman başta hem en küçük hem en büyük kabul edilir; böylece bir karşılaştırma az yapılır. Dikkat: karşılaştırma `dizi[minI]` ile, yani o ana kadarki en küçüğün **indisindeki eleman** ile yapılır.

Derste yazılan kod (ekrandan, 00:45:00 ve 00:50:00; prototip eklenmiş haliyle):

```c
#include <stdio.h>
#define MAX 15
void minmaxBul(int dizi[], int N, int *min, int *max);
int main(){
    int dizi[MAX]={2,4,7,9,1,6,-8};
    int min, max;
    int N = sizeof(dizi)/sizeof(dizi[0]);
    minmaxBul(dizi,N,&min,&max);
    printf("Min = Dizi[%d] -> %d\n",min,dizi[min]);
    printf("Max = Dizi[%d] -> %d\n",max,dizi[max]);
    return 0;
}
void minmaxBul(int dizi[], int N, int *min, int *max){
    int i;
    int minI=0, maxI=0;
    for(i=1;i<N;i++){
        if(dizi[i]<dizi[minI]){
            minI = i;
        }
        if(dizi[i]>dizi[maxI]){
            maxI = i;
        }
    }
    *min = minI;
    *max = maxI;
}
```

Bu kod `gcc -Wall` ile derlendi ve çalıştırıldı; çıktı:

```text
Min = Dizi[6] -> -8
Max = Dizi[3] -> 9
```

Fonksiyondaki `minI` ve `maxI` yedek (yerel) değişkenlerdir ve fonksiyon bitince ölecektir. Değerlerin kalıcı olması için `*min = minI;` ve `*max = maxI;` ile `main`'deki değişkenlerin adreslerine yazılır. Hoca bu işi döngü içinde doğrudan pointer'larla da yapabileceğimizi, ama çok fazla pointer işlemiyle uğraşmamak için yedek değişken kullandığını söyler.

Diziler fonksiyona adresiyle gider; fonksiyonda dizide yapılan değişiklik orijinal diziyi değiştirir, bundan kaçış yoktur. Buna call by reference denir. `N` gibi bir `int` ise değer olarak kopyalanır: `main`'deki `N` ile fonksiyondaki `N` ayrı değişkenlerdir. `sizeof(dizi)` dizinin bellekte kapladığı yeri, `sizeof(dizi[0])` bir elemanın boyutunu verir; bölümleri eleman sayısıdır.

> **Ders sonrası not:** Hoca eleman sayısının 7 olacağını söyledi; ama `dizi` `MAX` (15) elemanlı tanımlandığı için `sizeof(dizi)/sizeof(dizi[0])` 15 verir. Derste bir öğrenci de bunu fark etti ve hata ayıklayıcıda 15 görüldü. Kalan 8 eleman 0 olduğu için bu örnekte sonuç değişmez (en küçük $-8 < 0$, en büyük $9 > 0$). Dizide yalnız pozitif sayılar olsaydı en küçük olarak 0 bulunurdu; doğru eleman sayısı için `N = 7` yazılmalı ya da dizi `int dizi[] = {...}` diye boyutsuz tanımlanmalıdır.

**Soru (hocanın sorusu):** `printf` ile `min` ve `max`'ı yazdırırken neden `*` kullanmadık? **Cevap:** Bir öğrenci önce "diğer fonksiyonda adreslerine kaydettik" dedi; hoca diğer fonksiyonun bittiğini, artık `main`'de olduğumuzu hatırlattı. Doğru cevap: `main`'de `min` ve `max` pointer değil, normal değişkendir. `*` yalnız bir pointer'ın gösterdiği yerdeki değere ulaşmak için yazılır. Burada `*min` yazmak "`min`'in içindeki sayıyı adres kabul et ve oraya git" demektir; örneğin `min` 5 ise belleğin 5 numaralı adresine gidilmeye çalışılır ve program hata alır. Derleyici zaten `min` pointer olmadığı için bunu derleme zamanında kabul etmez.

## 7. Aynı fonksiyonla matrisin en küçük ve en büyük elemanı

### 7.1 Fikir

Hoca aynı fonksiyonu başka bir iş için kullanmak ister: matrisin en küçük ve en büyük elemanının değerini bulmak. Matris `MAX x MAX` boyutlu tanımlanır, satır sayısı `m = 2`, sütun sayısı `n = 3` alınır ve her satır için başlangıç değerleri verilir.

Kâğıt üzerinde: matrisin her satırı $n$ elemanlı bir dizi gibidir; matris $m$ tane $n$ elemanlı dizidir. Her satır yedek bir diziye kopyalanır ve `minmaxBul`'a gönderilir. Dönen en küçük ve en büyük, `dizimin` ve `dizimax` yedek dizilerine yazılır. Sonunda bu dizilerin içinden en küçük ve en büyük bulunur. Böylece aynı fonksiyon defalarca çağrılır ama bir kez yazılmış olur.

Fonksiyonun tanımı (ekrandan, 00:50:00):

```c
void minmaxBulv2(int m[][MAX], int m, int n, int *min, int *max)
```

Matris parametresinde satır sayısı boş bırakılabilir, ama sütun sayısı yazılmak zorundadır; burada olabilecek en büyük değer (`MAX`) yazılır, daha küçüğü kullanılır. Hoca fonksiyonun aldığı parametre sayısının çok fazla olmaması gerektiğini de belirtir: 20-30 parametre alan bir fonksiyon kötü tasarımdır. Sonra matris parametresiyle satır sayısının ikisinin de `m` adını taşıdığı fark edilir ve matrisin adı `matris` yapılır.

### 7.2 Birinci sürüm: satırı kopyalayarak

Derste yazılan gövde (ekrandan, 00:55:00 ve 01:00:00):

```c
int i,j;
int dizi[MAX] = {0};
int dizimin[MAX] = {0};
int dizimax[MAX] = {0};
int m1,m2;
for(i=0;i<m;i++){
    for(j=0;j<n;j++){
        dizi[j] = matris[i][j];
    }
    minmaxBul(dizi,n,&m1,&m2);
    dizimin[i] = dizi[m1];
    dizimax[i] = dizi[m2];
}
minmaxBul(dizimin,m,&m1,&m2);
*min = dizimin[m1];
minmaxBul(dizimax,m,&m1,&m2);
*max = dizimax[m2];
```

**Soru (hocanın sorusu):** `minmaxBul(dizi, ?, ...)` çağrısında kopyalanan dizi kaç elemanlıdır? **Cevap:** Öğrenciler önce döngü değişkenini söyledi; hoca onun yalnız "j. eleman" anlamına geldiğini hatırlattı. Kopyalanan satırda sütun sayısı kadar, yani küçük `n` kadar eleman vardır. `dizimin` ve `dizimax` ise satır sayısı kadar, yani `m` elemanlıdır.

`dizimin`'in en küçüğü ile `dizimax`'ın en büyüğü ayrı ayrı bulunmak zorundadır, çünkü ikisi tek çağrıyla gönderilemez. Toplamda fonksiyon $m+2$ kez çağrılır. (Hoca kâğıt üzerinde anlatırken $m+1$ dedi; kodda iki yedek dizi ayrı gönderildiği için $m+2$ oldu.) İşlem adımı azalmaz, ama bir kez yazılan kod tekrar tekrar kullanılır. Hoca "bu kadar niye uğraştık, sıfırdan yazabilirdik" itirazına, min-max kodunu her yerde yeniden yazmanın kodu ne kadar büyüteceğini göstererek cevap verir.

Matris `{{3,2,1},{6,2,8}}` iken sonuç en küçük 1, en büyük 8 oldu. Bir eleman (büyük olasılıkla 8) $-8$ yapıldığında en küçük $-8$, en büyük 6 çıktı. <!-- BELİRSİZ: matrisin ilk satırı hata ayıklayıcı penceresinde {3,2,1} olarak görünüyor (ekrandan, 01:15:00); ikinci satır ve değiştirilen eleman altyazıdan kuruldu. -->

### 7.3 İyileştirme: `matris[i]`'yi dizi gibi göndermek

Hoca bir programlama iyileştirmesi gösterir: satırı yedek diziye kopyalayan döngüden kurtulmak. `matris[i]`, matrisin `i`. satırının başlangıç adresidir; derleyici bunu "buradan itibaren `n` tane eleman" olarak bir dizi gibi algılar. Aslında ilgili satırın pointer adresi gönderilmektedir.

İlk denemede sonuç yanlış (0) çıktı. Hoca kesme noktası (breakpoint) koyup Dev-C++ hata ayıklayıcısında "Add Watch" ile değişkenleri izledi. Arada bir öğrenci `minmaxBul`'daki ikinci `if`'te karşılaştırmanın `dizi[maxI]` ile yapılması gerektiğini fark etti ve bu yazım hatası düzeltildi. Sonra izlenen değerler: `matris[i] = {3, 2, 1, 0 <12 kez>}`, fonksiyon içinde `*min = 2`, `*max = 0` doğru indisler çıkıyordu (ekrandan, 01:15:00). Asıl hata dönüşteydi: `dizimin[i] = dizi[m1];` satırı hâlâ artık doldurulmayan, içi sıfır olan `dizi`'yi okuyordu. Düzeltilmiş döngü (ekrandan, 01:15:00):

```c
for(i=0;i<m;i++){
    minmaxBul(matris[i],n,&m1,&m2);
    dizimin[i] = matris[i][m1];
    dizimax[i] = matris[i][m2];
}
```

Doğru okuma: `i`. satırın `m1`. sütunundaki eleman o satırın en küçüğü, `m2`. sütunundaki en büyüğüdür. Pointer'lar sayesinde yedek diziye kopyalama maliyeti ve bir döngü ortadan kalktı. Hoca bunu "$n^2$'lik karmaşıklıktan $n$'lik karmaşıklığa indirgedik" diye özetler, ama `minmaxBul`'un kendi maliyetinin de ayrıca olduğunu ekler.

> **Ders sonrası not:** Kopyalama döngüsü kalksa da her satırda `minmaxBul` yine $n$ elemana bakar; toplam iş $m \cdot n$ düzeyinde kalır. Kazanılan şey, satır başına ek $n$ adımlık kopyalama ve yedek dizi belleğidir; asimptotik mertebe değişmez.

### 7.4 Doğru tasarım: ayrı `minBul` ve `maxBul`

> **Hocanın vurgusu:** Hem en küçüğü hem en büyüğü bulan fonksiyon çok iyi bir yazım değildir; işi "İsviçre çakısına" döndürür. Normalde en küçük için ayrı, en büyük için ayrı fonksiyon yazılır. Burada tek fonksiyon, birden fazla sonucun pointer'la döndürülmesini göstermek için kullanıldı.

Hoca kodu hızlıca dönüştürür: `minBul(dizi, n, &min)` yalnız en küçüğün indisini, `maxBul(dizi, n, &max)` yalnız en büyüğün indisini bulur. Derleyicinin verdiği "conflicting types for 'maxBul'" hatası, çağrıda kalan yanlış değişken adı düzeltilerek giderildi. Sonuç yine $-8$ ve 6'dır. Bu fonksiyonlar bağımsız olduğu için ileride yalnız en küçük ya da yalnız en büyük gerektiğinde de işe yarar; `minmaxBulv2` ise bunları çağıran bir sarmalayıcı fonksiyon olmuştur.

Derste gösterilen fikri bir araya getiren tam program (ayrı `minBul`/`maxBul` ile; derste bu biçimde tek parça yazılmadı, ajan tarafından birleştirilip `gcc -Wall` ile derlendi ve çalıştırıldı):

```c
#include <stdio.h>
#define MAX 15
void minmaxBulv2(int matris[][MAX], int m, int n, int *min, int *max);
void minBul(int dizi[], int N, int *min);
void maxBul(int dizi[], int N, int *max);

int main(){
    int matris[MAX][MAX] = {{3,2,1},{6,2,-8}};
    int min, max;
    minmaxBulv2(matris, 2, 3, &min, &max);
    printf("Matris Min = %d\n", min);
    printf("Matris Max = %d\n", max);
    return 0;
}

void minmaxBulv2(int matris[][MAX], int m, int n, int *min, int *max){
    int i;
    int dizimin[MAX] = {0};
    int dizimax[MAX] = {0};
    int m1, m2;
    for(i=0;i<m;i++){
        minBul(matris[i], n, &m1);
        maxBul(matris[i], n, &m2);
        dizimin[i] = matris[i][m1];
        dizimax[i] = matris[i][m2];
    }
    minBul(dizimin, m, &m1);
    *min = dizimin[m1];
    maxBul(dizimax, m, &m2);
    *max = dizimax[m2];
}

void minBul(int dizi[], int N, int *min){
    int i, minI=0;
    for(i=1;i<N;i++)
        if(dizi[i]<dizi[minI]) minI = i;
    *min = minI;
}

void maxBul(int dizi[], int N, int *max){
    int i, maxI=0;
    for(i=1;i<N;i++)
        if(dizi[i]>dizi[maxI]) maxI = i;
    *max = maxI;
}
```

Çıktı: `Matris Min = -8`, `Matris Max = 6`.

### 7.5 Hazır bir örnek: seçime göre en büyük ya da en küçük

Hoca hazır bir kodu (`minMaxBul.c`) inceler. Burada fonksiyon bir dizi, eleman sayısı, bir seçim değeri ve bir indis pointer'ı alır. Seçim 1 ise en büyüğü, değilse en küçüğü bulur; bulunan elemanın değeri `return` ile, indisi pointer ile döner. Dizinin ilk elemanı başta sonuç kabul edilir; döngüde seçime göre daha büyük ya da daha küçük eleman bulununca hem sonuç hem indis güncellenir. Örnekte seçim 1 gönderildiği için en büyük eleman (9, 4. indiste) bulundu; 0 gönderilseydi en küçük ($-5$) bulunacaktı. Aynı dosya matris için de her satırı bir `k` dizisine kopyalayıp fonksiyona gönderir. Hoca bunun aynı problemin farklı bir tasarımı olduğunu söyler.

<!-- BELİRSİZ: bu hazır kodun ekran görüntüsü yok; dizinin elemanları ve en küçük elemanın indisi altyazıdan kesin okunamıyor. -->

## 8. Dizi, dizi elemanı ve adres göndermek

Hoca matris okuyan bir hazır fonksiyonu (`matrisOku.c`) kısaca gösterir: satır ve sütun sayısı kullanıcıdan alınır, matris için fazladan yer ayrılmıştır, okuma fonksiyonu matrisi doldurur ve `main`'de ilk ve son eleman yazdırılır. Bu, matrislerin ve dizilerin adresle aktarılması sayesinde olur: yerel değişkenler kaybolur, ama matris `main`'de oluşturulduğu ve fonksiyona adresi gönderildiği için yapılan değişiklik tanımlandığı yere yansır. Hoca fonksiyonların `main`'in üstüne de yazılabileceğini, ama önce `main`'in görülmesinin tercih edildiğini ekler.

Sonra "herkese doğal istisna gibi gelen" durumu yeni bir kodla gösterir (ekrandan, 01:30:00 ve 01:35:00):

- `f1(dizi, 4)`: dizinin bütün elemanlarını sıfırlar. Dizi adresle gittiği için değişiklik yansır.
- `f2(dizi[2])`: dizinin 2. elemanını gönderir ve fonksiyonda ona 5 atar. Dizinin tek bir elemanı sıradan bir `int`'tir; değerle kopyalanır, değişiklik yansımaz.
- `f3(&dizi[2])`: elemanın adresini gönderir; fonksiyon `int *x` alır ve `*x = 5` yazar. Değişiklik yansır.

Hoca ilk denemede parametreyi `int 4` diye yazmıştı (ekrandan, 01:30:00); parametre bir değişken adı olmalıdır (`int n`), sabit yazılamaz.

Aşağıdaki kod derstekiyle aynı mantıktadır ve `gcc -Wall` ile derlenip çalıştırıldı. Derste dizi ilk değer verilmeden tanımlandığı için ilk satırda çöp değerler görüldü; testte çöp yerine 7 verildi:

```c
#include <stdio.h>
void f1(int dizi[], int n);
void f2(int x);
void f3(int *x);
void yazdir(int dizi[], int n, char *str);
int main(){
    int dizi[4] = {7, 7, 7, 7};
    yazdir(dizi, 4, "before f1");
    f1(dizi, 4);
    yazdir(dizi, 4, "after f1");
    f2(dizi[2]);
    yazdir(dizi, 4, "after f2");
    f3(&dizi[2]);
    yazdir(dizi, 4, "after f3");
    return 0;
}
void f1(int dizi[], int n){
    int i;
    for(i=0;i<n;i++) dizi[i] = 0;
}
void f2(int x){ x = 5; }
void f3(int *x){ *x = 5; }
void yazdir(int dizi[], int n, char *str){
    int i;
    printf("%s", str);
    for(i=0;i<n;i++) printf(" %d", dizi[i]);
    printf("\n");
}
```

Çıktı:

```text
before f1 7 7 7 7
after f1 0 0 0 0
after f2 0 0 0 0
after f3 0 0 5 0
```

Dersteki çıktıda da `after f1` ve `after f2` satırları `0 0 0 0`, `after f3` satırı `0 0 5 0` idi (ekrandan, 01:35:00).

> **Hocanın vurgusu:** Bir fonksiyona dizinin herhangi bir elemanı (üçüncü, sekizinci eleman) aktarılıyorsa bu, normal bir değişken aktarmaktan farksızdır; değişiklik yukarıya yansımaz. Yansıması isteniyorsa adresi gönderilir ve pointer ile alınır.

Fonksiyonların içindeki değişkenlerin hepsi yereldir ve fonksiyon tamamlanınca ölür. `f2`'de `x` 5 olur, öyle kalır ve fonksiyon bitince kaybolur. Dizinin kendisinin gönderilmesi ise orijinal diziyi değiştirir.

## 9. Fonksiyon aşırı yükleme (overloading)

Ders notundaki bir maddeye göre fonksiyonda değişecek şeyler parametre olarak alınmalı, fonksiyon sayısı azaltılmalıdır: 4 elemanlı diziyi okuyan fonksiyon yerine $n$ elemanlı diziyi okuyan fonksiyon yazılır; "büyükten küçüğe" ve "küçükten büyüğe" sıralama gibi seçenekler parametreyle verilir (Bölüm 7.5'teki seçim parametresi gibi).

Yeni bir kavram: fonksiyon aşırı yükleme (overloading). Aynı isimli fonksiyonların farklı tipte ve sayıda parametreyle tanımlanmasıdır; örneğin bir `f1` bir kez `int` dizisi, bir kez `int` matrisi alacak şekilde yazılır. Nesne tabanlı programlamada vardır; kavramsal olarak bilinir ama C bunu doğrudan desteklemez.

## 10. En yakın ikili (closest pair) problemi

Hoca bunu "çok önemli bir problem" diye tanıtır: bir boyutlu noktalar dizisinin içinden birbirine en yakın iki noktanın indisini bulmak.

### 10.1 Bir boyutlu noktalar

Bir boyutlu noktalar bir sayı doğrusu üzerinde gösterilir. Bilgisayarda $N$ tane (sonlu sayıda) noktayı tutmak için $N$ elemanlı bir dizi kullanılır; 0. nokta, 1. nokta, ..., $(N-1)$. nokta. Noktalar `double` olabilir; derste `int` kullanıldı.

Noktalar sıralıysa $P_1, P_2, P_3, P_4$ için yalnız ardışık uzaklıklara ($d_1 = |P_1P_2|$, $d_2 = |P_2P_3|$, $d_3 = |P_3P_4|$) bakmak yeterlidir; $P_1$ ile $P_3$'e bakmanın anlamı yoktur. Sırasızsa bütün ikililer karşılaştırılmalıdır. Problemin adı closest pair'dir; iki ve üç boyutlu uzaylarda da sorulur. Hoca, bir şeyin başka bir şeye benzerliğine bakmanın yapay zekânın en çok kullandığı yöntemlerden birinin temeli olduğunu ve bunun özünde bir closest pair problemi bulunduğunu söyler.

### 10.2 Sırasız dizi: iç içe iki döngü

Bir boyutta uzaklık için mutlak fark yeterlidir. Örnek dizi 8, 3, 6, 1 için: 8 ile 3, 8 ile 6, 8 ile 1'in uzaklıkları 5, 2, 7'dir. En küçüğü (8 ile 6, indisler 0 ve 2) saklanır. Sonra 3 ile 6, 3 ile 1'e bakılır; daha küçük bir uzaklık bulunursa güncellenir.

**Soru (hocanın sorusu):** Tek döngü yeterli olur mu? **Cevap:** Hayır, iç içe iki döngü gerekir.

**Soru (hocanın sorusu):** Dış döngüde `i` son elemana kadar gitmeli mi? **Cevap:** Hayır, `N-1`'e kadar (son elemandan bir öncekine kadar) gitmesi yeterlidir.

**Soru (hocanın sorusu):** İç döngü `j` nereden başlamalı? **Cevap:** `i+1`'den. Eleman kendisiyle karşılaştırılırsa uzaklık 0 çıkar ve yanlış sonuç verir; ayrıca önceki ikililere tekrar bakmaya gerek yoktur: (0,1), (0,2), (0,3), ..., sonra (1,2), (1,3), ... İç döngü `N`'e kadar gider.

En küçük uzaklığın bir başlangıç değeri olmalıdır. Hoca çok büyük bir değer vermek yerine 0. ve 1. elemanlar arasındaki uzaklığı başlangıçta en küçük kabul eder. Yeni hesaplanan uzaklık `temp` değişkenine yazılır; `temp < dist` ise `dist` güncellenir ve hangi iki elemanın yakın olduğu `x` ve `y`'de tutulur. Döngü bitince `*e1 = x; *e2 = y;` yazılır.

**Soru (hocanın sorusu):** `*e1 = x; *e2 = y;` yerine tersini yazsaydık bir şey değişir miydi? **Cevap:** Hayır; sonuç sıralı bir ikili değil, sıradan bir ikilidir.

Derste bu sırada bir öğrenci ikisine de `y` yazıldığını fark etti; ayrıca `abs(dizi[i],dizi[j])` yazım hatası "too many arguments" hatası verdi (ekrandan, 01:50:00), prototipler eklenmeyince "implicit declaration" alındı. Dizi `randomFill` ile rastgele dolduruldu ve önce ekrana yazdırıldı. Aynı sayıların sık çıkmaması için rastgele değer aralığı `MAX*MAX*MAX`'a genişletildi ve eleman sayısı 5'e indirildi (ekrandan, 02:05:00).

### 10.3 Sıralı dizi: tek döngü

**Soru (hocanın sorusu):** Dizi rastgele değil de sıralı doluysa birinci sürümü kullanmak mantıklı mı? **Cevap:** Hayır; bir öğrencinin dediği gibi ardışık terimlere bakmak yeterlidir. Birinci sürüm $n^2$ karmaşıklıktadır, ikinci sürüm $n$'dir.

İkinci sürümde ilk iki elemanın farkı başta en küçük kabul edilir, döngü 1'den başlar ve `abs(dizi[i]-dizi[i+1])`'e bakılır. Dizinin dışına taşmamak için koşul mutlaka `i < N-1` olmalıdır. Derste yazılan gövde (ekrandan, 02:00:00):

```c
for(i=1;i<N-1;i++){
    temp  = abs(dizi[i]-dizi[i+1]);
    if(temp < dist){
        dist = temp;
        x = i;
        y = i+1;
    }
}
*e1 = x;
*e2 = y;
```

Burada iki değişkene gerek de yoktur; `y` her zaman `x+1`'dir.

**Soru (hocanın sorusu):** Birinci sürümün içinden ikinci sürümü çağırarak problemi çözebilir miydik? **Cevap:** Hayır, çünkü birinci sürümün dizisi rastgele doludur; ikinci sürüm yalnız sıralı dizide doğru çalışır.

Sıralı dizi üretmek için önce `d[i] = 2*i*i + 1` denendi (1, 3, 9, 19, 33, ...). Hoca bu dizide farkların sürekli arttığını, en yakın ikilinin her zaman ilk iki eleman olacağını fark etti; bu iyi bir test değildir. Bir öğrencinin önerisiyle artış miktarı rastgele yapıldı. İlk denemede `r = rand() % i` yazıldı ve `i = 0`'da sıfıra bölme (mod 0) yüzünden program çöktü; bunu da bir öğrenci fark etti (ekrandan, 02:05:00). Sonra her eleman bir öncekinin üstüne eklenerek üretildi (ekrandan, 02:10:00):

```c
void sortedFill(int d[], int N){
    int i,r;
    d[0] = 4; printf(" %d ",d[0]);
    for(i=1;i<N;i++){
        r = rand() % (i+1);
        d[i] = d[i-1] + (i+1);
        printf(" %d ",d[i]);
    }
}
```

Bu karede `r` hesaplanıyor ama henüz eklenmiyordu; çıkan dizi 4, 6, 9, 13, 18 oldu. Sonra `r`'nin de eklenmesi gerektiği hatırlandı. Bir hata daha bulundu: `x` ve `y`'ye başlangıç değeri verilmemişti; en küçük fark zaten ilk iki eleman arasındaysa döngüde hiç güncellenmedikleri için çöp değerle kalıyorlardı. Doğrusu `x = 0`, `y = 1` ile başlatmaktır.

Derste parça parça yazılan iki sürümün, bulunan hatalar düzeltilmiş tam hali (ajan tarafından birleştirildi, `gcc -Wall` ile derlenip çalıştırıldı; `sortedFill`'de `r`'nin eklenmesi ve `x`, `y` başlangıç değerleri derste söylenen düzeltmelerdir):

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 5
void randomFill(int d[], int N);
void sortedFill(int d[], int N);
void findClosestPairV1(int dizi[], int N, int *e1, int *e2);
void findClosestPairV2(int dizi[], int N, int *e1, int *e2);
int main(){
    srand(time(NULL));
    int dizi[MAX];
    int e1, e2;
    randomFill(dizi, MAX);
    findClosestPairV1(dizi, MAX, &e1, &e2);
    printf("\n%d and %d (indis %d, %d)\n", dizi[e1], dizi[e2], e1, e2);
    sortedFill(dizi, MAX);
    findClosestPairV2(dizi, MAX, &e1, &e2);
    printf("\n%d and %d (indis %d, %d)\n", dizi[e1], dizi[e2], e1, e2);
    return 0;
}
void findClosestPairV1(int dizi[], int N, int *e1, int *e2){
    int i, j;
    int dist = abs(dizi[0]-dizi[1]);
    int temp;
    int x = 0, y = 1;
    for(i=0;i<N-1;i++){
        for(j=i+1;j<N;j++){
            temp = abs(dizi[i]-dizi[j]);
            if(temp < dist){
                dist = temp;
                x = i;
                y = j;
            }
        }
    }
    *e1 = x;
    *e2 = y;
}
void findClosestPairV2(int dizi[], int N, int *e1, int *e2){
    int i;
    int dist = abs(dizi[0]-dizi[1]);
    int temp;
    int x = 0, y = 1;
    for(i=1;i<N-1;i++){
        temp = abs(dizi[i]-dizi[i+1]);
        if(temp < dist){
            dist = temp;
            x = i;
            y = i+1;
        }
    }
    *e1 = x;
    *e2 = y;
}
void randomFill(int d[], int N){
    int i;
    for(i=0;i<N;i++){
        d[i] = rand() % (MAX*MAX*MAX);
        printf("%d ", d[i]);
    }
}
void sortedFill(int d[], int N){
    int i, r;
    d[0] = 4; printf("\n%d ", d[0]);
    for(i=1;i<N;i++){
        r = rand() % (i+1);
        d[i] = d[i-1] + r + 1;
        printf("%d ", d[i]);
    }
}
```

Bir çalıştırmada çıktı şöyleydi (rastgele olduğu için her çalıştırmada değişir):

```text
31 57 27 106 38 
31 and 27 (indis 0, 2)

4 5 7 10 14 
4 and 5 (indis 0, 1)
```

### 10.4 İki boyutlu noktalar

İki boyutlu uzayda iki sayı doğrusu (x ve y eksenleri) vardır. İki nokta arasındaki uzaklık için Pisagor bağıntısından bilinen Öklid uzaklığı (Euclidean distance) kullanılır:

$$d = \sqrt{(x_1-x_2)^2 + (y_1-y_2)^2}$$

İki boyutta noktalar normal şartlarda sıralı olmaz; bütün noktalar birbiriyle karşılaştırılır. Noktalar artık bir matriste tutulur: her satır bir nokta, sütunlar koordinatlardır. Hoca noktaları rastgele dolduran ve ekrana yazan kodu hazırlamıştı; en yakın ikiliyi bulan fonksiyonu derste yazdı (ekrandan, 02:20:00):

```c
void findClosestPair(int M[][2],int m, int n, int *x, int *y ){
    int i ,j;
    int d = INT_MAX;
    int tmp;
    for(i=0;i<m;i++){
        for(j=i+1;j<m;j++){
            tmp = pow(M[i][0]-M[j][0],2) + pow(M[i][1]-M[j][1],2);
            if(tmp<d){
                d  =tmp;
                *x = i;
                *y = j;
            }
        }
    }
}
```

Karşılaştırma için kare köke gerek yoktur; kareler toplamı küçük olan uzaklığın kendisi de küçüktür. Başlangıç uzaklığı `INT_MAX` alındı; hoca bunun çok tercih edilen bir yol olmadığını, şimdilik yeterli olduğunu söyler. Burada yedek değişken kullanmadan doğrudan `*x` ve `*y`'ye yazılır.

Hoca çıktıda üç noktanın koordinatlarını ve örnek bir kare uzaklık hesabını gösterdi (fark 2'nin karesi 4, fark 1'in karesi 1, toplam 5); diğer hesapları öğrencilere bıraktı. <!-- BELİRSİZ: rastgele üretilen noktaların koordinatları ve hangi ikilinin en yakın çıktığı altyazıdan kesin okunamıyor; çıktı ekranı kareye düşmedi. -->

### 10.5 $k$ boyutlu noktalar

**Soru (hocanın sorusu):** Noktalar 3, 4, 5, yani $k$ boyutlu olursa nasıl saklanır? **Cevap:** Bir öğrencinin dediği gibi yalnız matrisin ikinci boyutu büyütülür; $N$ nokta için $N \times k$ matris kullanılır. Her satır bir nokta, sütunlar onun boyutlarıdır (x, y, z, t, ...).

Üç boyutta iki nokta arasındaki uzaklık $\sqrt{(x_1-x_2)^2+(y_1-y_2)^2+(z_1-z_2)^2}$'dir; dört boyutta bir $(t_1-t_2)^2$ terimi daha eklenir (dört boyut çizilemez). $k$ boyutta kare farklar toplamı için bir döngü daha gerekir (ekrandan, 02:30:00):

```c
for(i=0;i<m;i++){
    for(j=i+1;j<m;j++){
        tmp = 0;
        for(t=0;t<n;t++){
            tmp += pow(matris[i][t]-matris[j][t],2);
        }
        if(tmp<d){
            *x = i;
            *y = j;
            d = tmp;
        }
        printf("\n%d %d >>> %d",i,j,tmp);
    }
}
```

Geri kalan her şey iki boyutlu sürümle aynıdır.

> **Ek bilgi (derste anlatılmadı):** `pow` `<math.h>`'de tanımlıdır ve `double` döndürür; sonucun `int`'e atanması, büyük sayılarda yuvarlama ihtimali yüzünden, tam sayılarla çalışırken `(a-b)*(a-b)` yazmaktan daha az güvenlidir. Linux'ta `gcc` ile derlerken `pow` için `-lm` bağlayıcı seçeneği gerekebilir.

## 11. Gerçek hayat senaryoları: çöpçatan sitesi ve doktor-hasta teşhisleri

Hoca, kodları aynı olduğu için bu örnekleri sıfırdan yazmadığını, hazır kodlar üzerinden incelediğini söyler.

### 11.1 Çöpçatan sitesi (sayısal cevaplar)

Slayttaki soru (ekrandan, 02:25:00): "Bir çöpçatan sitesi yapalım. Sisteme giren herkese D adet soru soruyor. Cevaplar sayısal. Birbirine en uygun 2 kişiyi bulalım. Erkekler: E (M*D) matris, Kadınlar: K(M*D) matris."

Sorular "hangi rengi seversin", "hangi tür şarkıyı seversin" gibidir ve cevaplar 1 ile 10 arasında sayılarla verilir. $N$ erkek ve $M$ kadın $D$ soruya cevap verir. Geometrideki en yakın nokta, bu senaryoda birbirine en uyumlu iki kişidir. Her erkek her kadınla karşılaştırılır; toplam $N \cdot M$ uzaklık hesabı yapılır. En küçük uzaklık, en uyumlu (erkek, kadın) ikilisini verir.

Slayttaki sözde kod (ekrandan, 02:25:00):

```text
[ind1,ind2]=en_uygun(E,M,K,N,D)
min_dist=100000;
ind1=0; ind2=0;
for i=1:M
    for j=1:N
        dist=0;
        for k=1:D
            dist=dist+|E(i,k)-K(j,k)|;
        end
        if dist<min_dist
            min_dist=dist;
            ind1=i;
            ind2=j;
        end
    end
end
```

Burada uzaklık mutlak farkların toplamıdır; hoca karelerinin toplanmasının da sonucu değiştirmeyeceğini söyler.

> **Ek bilgi (derste anlatılmadı):** Mutlak farkların toplamına Manhattan uzaklığı denir; kare farkların toplamının kökü ise Öklid uzaklığıdır. İkisi her zaman aynı en yakın ikiliyi vermeyebilir, ama ikisi de benzerlik ölçüsü olarak kullanılır.

Hoca bunu öneri (recommendation) sistemlerine bağlar: dinlediğiniz müziklere en yakın arkadaşınız bulunur ve onun dinleyip sizin dinlemediğiniz bir müzik size önerilir.

**Soru (hocanın sorusu):** Bu çözüm önceki çözümlerden hangisine benziyor: bir boyutlu, iki boyutlu, $k$ boyutlu? **Cevap:** Bir öğrenci "iki boyutlu" dedi; kodda iki soru (iki sütun) için çözüm yazılmıştı. Soru sayısı $k$ olursa $k$ boyutlu closest pair koduyla aynıdır; tek fark, aynı matris içinde değil iki ayrı matrisin satırları arasında (i. erkek ile j. kadının t. soruları) karşılaştırma yapılmasıdır.

Programın çalıştırılmasında ilk matris 3 kayıtlı, ikinci matris 2 kayıtlı ve 2 sütunlu (soru) girildi; ilk matrisin elemanları 1, 2, 4, 2, 1, 4 olarak verildi (ekrandan, 02:35:00) ve en yakın ikili indisleri ekrana yazıldı. <!-- BELİRSİZ: ikinci matrisin elemanları ve sonuç indisleri kareden okunamadı. -->

### 11.2 Kategorik cevaplar

Bir çalışma sorusunda sistem değişir: cevaplar sayısal değil kategoriktir. Örneğin "hangi tür müziği seversin" sorusunda rock 0, pop 1; film türünde korku 1, romantik komedi 2, polisiye 3, bilim kurgu 4 diye kodlanır. Burada bilim kurgu ile romantik komedinin farkı semantik olarak bir anlam taşımaz, çünkü kodlar rastgele verilmiştir. Bu yüzden yalnız aynı olup olmadığına (varlık-yokluk) bakılır.

Hazır kodda `findDistance` diye bir yardımcı fonksiyon vardır ve verinin kategorik olup olmadığını bir parametreyle alır:

- Kategorikse: iki değer aynıysa 0, farklıysa 1 döndürür. En küçük uzaklık arandığı için aynılıkta 0 döndürmek mantıklıdır.
- Kategorik değilse: iki değerin farkının mutlak değerini döndürür.

Ana döngüde uzaklık her soru için `findDistance` çağrılarak toplanır. Hoca bu fonksiyonun önceki kodlarda `abs` yerine de kullanılabileceğini, böylece fonksiyon içinden fonksiyon çağrılarak aynı kodun her senaryoda işe yarayacağını söyler. Ayrıca matris parametresinin farklı bir yazımla da verilebileceğini, iki yazım arasında fark olmadığını, şimdilik alışılan yazımın kullanılmasını önerir.

<!-- BELİRSİZ: findDistance fonksiyonunun kodu kareye düşmedi; anlatım altyazıdan kuruldu. -->

### 11.3 Doktor-hasta teşhis problemi

Slayttaki problem: $D$ adet doktorun $H$ adet hastaya koyduğu teşhisler ve doğru teşhisler verilsin. Hoca çizimde (ekrandan, 02:40:00) teşhisleri bir matriste tutar: satırlar doktorlar, sütunlar hastalar; örneğin 0. doktor 0. hastaya "grip" (0 ile kodlanır), 1. hastaya "bronşit" (3 ile kodlanır) demiştir. Gerçek teşhisler $H$ elemanlı bir `G` dizisindedir (örneğin 0. hastanınki 1, 1. hastanınki 0).

**En başarılı doktor kimdir?** En çok doğru teşhis koyan doktordur. Doğru teşhis sayıları `DT` dizisinde tutulur. İki döngüyle doktor $i$, hasta $j$ gezilir; `D[i][j] == G[j]` ise `DT[i]++` yapılır. Bu kategorik bir karşılaştırmadır. Sonra `DT`'nin en büyüğünün indisi daha önce yazılan `maxBul` fonksiyonuyla bulunur.

Hoca öğrencilerden aynı veriden başka sorular üretmelerini ister ve kendisi şunları sayar:

- En başarısız doktor: aynı `DT` dizisinin en küçüğü.
- Birbirine en çok benzeyen iki doktor: aynı hastaya verdikleri teşhisler karşılaştırılır; hastalar sabit tutulup doktorlar değiştirilir; aynı teşhis sayısı bir benzerlik skorudur. Bu, kategorik benzerlikle bir closest pair problemidir.
- Birbirine en çok benzeyen iki hasta: aynı işlem satır yerine sütunlar üzerinde yapılır; yine $k$ noktalı bir closest pair problemi.
- En nadir (ya da en çok) konulan teşhis: hastalık kodları örneğin 0-100 arasındaysa 100 elemanlı, başta sıfır olan bir teşhis dizisi tutulur ve her konulan teşhisin sayacı bir artırılır. Bu bir frekans (histogram) problemidir; dizinin en küçüğü en nadir, en büyüğü en sık konulan teşhistir.
- Hasta "demokrasi usulü" teşhis seçse kimlere yanlış teşhis konur? Örneğin 4. hasta için 10 doktordan 4'ü grip, 5'i Covid, 1'i zatürre demiş olsun. Çoğunluk Covid dediği için Covid seçilir; ama gerçek teşhis gripse bu hastaya yanlış teşhis konmuştur. Her hasta için en çok konulan teşhis sayılıp gerçek teşhisle karşılaştırılır; tutmuyorsa "çoğunluk yanılmış" denir. Hazır kodda bu fonksiyonun adı `KimlerOlecek`'tir (ekrandan, 02:45:00): $N$ doktorun $k$ hastaya koyduğu teşhisler $N \times k$'lık `E` matrisinde, doğru teşhisler `DogruTe[]` dizisindedir; fonksiyon her hasta için tüm doktorların teşhislerini bir `Teshisler` dizisine alır, `Frekanslar` dizisiyle sayar ve sonucu `Madurlar[]` dizisine (yanlış teşhis konduysa 1, değilse 0) yazar.

> **Hocanın vurgusu:** Bu veriden 5-6 soru üretilebilir; sınavlarda da buna benzer sorular soruluyor.

**Soru:** Hastaların benzerliğinde neden transpoze alınıyor? **Cevap:** Gerekli değildir. Doktorların benzerliği için yazılan closest pair fonksiyonu hastalar için de kullanılsın diye, fonksiyonda indisleri değiştirmek yerine önce matrisin transpozesi alınıp fonksiyona gönderilir; böylece boyutlar aynı kalır. Başka bir yolla da çözülebilir.

Hoca bütün bu kodların, derste yazılan min-max, frekans ve closest pair kodlarının senaryoya giydirilmiş hali olduğunu söyler.

## Örnek Sorular

**Soru 1** (ekrandan, 00:45:00; derste sözlü, 00:43:07). `minmaxBul(dizi,N,&min,&max);` çağrısından sonra `main`'de `printf("Min = Dizi[%d] -> %d\n",min,dizi[min]);` yazılıyor. Burada `min` yerine neden `*min` yazılmaz?

> **Çözüm:** `main`'de `min` bir pointer değil, `int` değişkendir; fonksiyon sonucu bu değişkenin adresine yazmıştır. `*` yalnız bir pointer'ın gösterdiği değere erişmek için kullanılır; `*min` yazılırsa derleyici hata verir, çünkü `min`'in içindeki sayı bir adres değildir.

**Soru 2** (derste sözlü, 00:54:25). Matrisin bir satırını `dizi`'ye kopyaladıktan sonra `minmaxBul(dizi, ?, &m1, &m2)` çağrısında eleman sayısı olarak ne gönderilir? Sonraki `minmaxBul(dizimin, ?, &m1, &m2)` çağrısında ne gönderilir?

> **Çözüm:** İlkinde satırdaki eleman sayısı, yani sütun sayısı `n`; ikincisinde satır sayısı `m`, çünkü `dizimin` her satırdan bir eleman alır.

**Soru 3** (derste sözlü, 01:33:11). Aşağıdaki çağrılardan sonra `yazdir` ne basar? Dizi ilk değer verilmeden `int dizi[4];` diye tanımlanmıştır. `f1` diziyi sıfırlar; `f2(int x)` `x = 5` yapar; `f3(int *x)` `*x = 5` yapar.

```c
yazdir(dizi,4);   /* before f1 */
f1(dizi,4);
yazdir(dizi,4);   /* after f1 */
f2(dizi[2]);
yazdir(dizi,4);   /* after f2 */
f3(&dizi[2]);
yazdir(dizi,4);   /* after f3 */
```

> **Çözüm:** İlk satırda çöp değerler; `after f1` ve `after f2` satırlarında `0 0 0 0` (dizinin tek elemanı değerle gittiği için `f2` diziyi değiştirmez); `after f3` satırında `0 0 5 0` (ekrandan, 01:35:00).

**Soru 4** (derste sözlü, 01:46:54 ve 01:47:38). Bir boyutlu sırasız noktalar dizisinde en yakın iki noktanın indisini bulmak için tek döngü yeterli mi? Dış döngü nereye kadar, iç döngü nereden başlamalı?

> **Çözüm:** İç içe iki döngü gerekir. Dış döngü `i = 0`'dan `N-2`'ye (`i < N-1`), iç döngü `j = i+1`'den `N-1`'e gider; eleman kendisiyle karşılaştırılmaz, önceki ikililere tekrar bakılmaz. Karmaşıklık $O(n^2)$'dir.

**Soru 5** (derste sözlü, 01:57:06). Dizi sıralıysa sırasız dizi için yazılan algoritmayı kullanmak mantıklı mı?

> **Çözüm:** Hayır. Sıralı dizide en yakın ikili mutlaka ardışık iki elemandır; tek döngüyle `abs(dizi[i]-dizi[i+1])`'e bakmak yeterlidir ve karmaşıklık $O(n)$'dir.

**Soru 6** (derste sözlü, 02:00:02). Sırasız dizi için yazılan birinci sürümün içinden sıralı dizi için yazılan ikinci sürüm çağrılarak problem çözülebilir mi?

> **Çözüm:** Hayır; birinci sürümün dizisi rastgele doludur, ikinci sürüm yalnız sıralı dizide doğru sonuç verir.

> **Ek bilgi (derste anlatılmadı):** Sırasız dizi önce $O(n \log n)$ bir algoritmayla sıralanıp sonra ikinci sürüm uygulanırsa toplam maliyet $O(n \log n)$ olur; bu, $O(n^2)$'den iyidir. Ama indisler sıralamadan sonra değiştiği için orijinal indislerin ayrıca saklanması gerekir.

**Soru 7** (derste sözlü, 02:21:10). Noktalar $k$ boyutlu olursa nasıl saklanır ve uzaklık nasıl hesaplanır?

> **Çözüm:** $N$ nokta için $N \times k$ matris kullanılır; her satır bir nokta, her sütun bir boyuttur. İki nokta için kare farklar $\sum_{t=0}^{k-1} (p_{i,t}-p_{j,t})^2$ üçüncü bir döngüyle toplanır; karşılaştırma için kare köke gerek yoktur.

**Soru 8** (ekrandan, 02:25:00; derste sözlü, 02:28:12). Çöpçatan sitesinde $D$ soru soruluyor, cevaplar sayısal; erkekler `E`, kadınlar `K` matrisinde. Birbirine en uygun iki kişiyi bulan çözüm, derste yazılan closest pair sürümlerinden hangisine benzer?

> **Çözüm:** Derste iki soru için yazıldığından iki boyutlu sürüme; genel halde $k$ boyutlu sürüme benzer. Fark, karşılaştırmanın aynı matrisin satırları yerine `E`'nin i. satırı ile `K`'nin j. satırı arasında yapılması ve toplam $N \cdot M$ karşılaştırma olmasıdır.

**Soru 9** (ekrandan, 02:40:00; derste sözlü, 02:37:01 ve 02:39:33). $D$ doktorun $H$ hastaya koyduğu teşhisler `D` matrisinde, gerçek teşhisler `G` dizisinde. En başarılı doktor kimdir? Demokrasi usulüyle (her hastaya en çok konulan teşhis) kimlere yanlış teşhis konur?

> **Çözüm:** Derste fikir anlatıldı: `D[i][j] == G[j]` ise `DT[i]++`, sonra `DT`'nin en büyüğünün indisi; demokrasi usulü için hasta başına teşhis frekansı çıkarılıp en sık teşhis gerçek teşhisle karşılaştırılır.

> **Çözüm (derste verilmedi):** Aşağıdaki kod ajan tarafından yazıldı, `gcc -Wall` ile derlenip küçük bir örnekle çalıştırıldı. Örnekte 3 doktor ve 4 hasta vardır; 0. doktor dört hastanın hepsini doğru bilmiştir, 2. hastaya iki doktor 2, bir doktor 1 demiş ama gerçek teşhis 1'dir.
>
> ```c
> #include <stdio.h>
> #define MAXH 50
> #define TESHIS 100
>
> int enBasariliDoktor(int D[][MAXH], int nd, int nh, int G[]){
>     int DT[MAXH] = {0};
>     int i, j, enIyi = 0;
>     for(i=0;i<nd;i++)
>         for(j=0;j<nh;j++)
>             if(D[i][j] == G[j]) DT[i]++;
>     for(i=1;i<nd;i++)
>         if(DT[i] > DT[enIyi]) enIyi = i;
>     return enIyi;
> }
>
> void demokrasiMagdurlari(int D[][MAXH], int nd, int nh, int G[], int Magdur[]){
>     int i, j, enCok;
>     for(j=0;j<nh;j++){
>         int Frekans[TESHIS] = {0};
>         for(i=0;i<nd;i++) Frekans[D[i][j]]++;
>         enCok = 0;
>         for(i=1;i<TESHIS;i++)
>             if(Frekans[i] > Frekans[enCok]) enCok = i;
>         Magdur[j] = (enCok != G[j]);
>     }
> }
>
> int main(){
>     int D[MAXH][MAXH] = {
>         {0, 3, 1, 2},
>         {0, 3, 2, 2},
>         {1, 3, 2, 0},
>     };
>     int G[MAXH] = {0, 3, 1, 2};
>     int Magdur[MAXH], j;
>     printf("En basarili doktor: %d\n", enBasariliDoktor(D, 3, 4, G));
>     demokrasiMagdurlari(D, 3, 4, G, Magdur);
>     printf("Yanlis teshis konan hastalar:");
>     for(j=0;j<4;j++) if(Magdur[j]) printf(" %d", j);
>     printf("\n");
>     return 0;
> }
> ```
>
> Çıktı: `En basarili doktor: 0` ve `Yanlis teshis konan hastalar: 2`. Doğru teşhis sayıları 4, 3, 1'dir; 2. hastada çoğunluk 2 dediği hâlde gerçek teşhis 1'dir.

## Dersin Toparlaması

Ders, fonksiyonların neden yazıldığıyla (tekrar kullanım, böl-yönet, kolay düzeltme ve bakım) başladı ve bir fonksiyonun nasıl iyi tasarlanacağını iki ilkeyle bağladı: düşük bağlaşım ve yüksek uyum. Ardından programın bellekteki yerleşimi ve çağrı yığını adım adım izlendi; yerel değişkenlerin neden fonksiyon bitince yok olduğu, dönüş satırının ve işlemci durumunun stack'te saklandığı görüldü. Bu bilgi, dizilerin adresle, tek değişkenlerin ve dizi elemanlarının değerle gitmesiyle birleşerek C'de birden fazla sonucun pointer parametrelerle nasıl döndürüldüğünü açıkladı.

Uygulamada önce dizinin en küçük ve en büyük elemanını bulan fonksiyon yazıldı, sonra aynı fonksiyon matrisin satırlarına `matris[i]` ile uygulanarak yeniden kullanıldı ve ayrı `minBul`/`maxBul` fonksiyonlarıyla daha iyi bir tasarıma dönüştürüldü. Dersin ikinci yarısında en yakın ikili problemi bir boyuttan (sırasız $O(n^2)$, sıralı $O(n)$) iki ve $k$ boyuta genişletildi; çöpçatan sitesi, kategorik veriler ve doktor-hasta teşhisleri gibi senaryoların hepsinin min-max bulma, frekans sayma ve closest pair problemlerine indirgendiği gösterildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
