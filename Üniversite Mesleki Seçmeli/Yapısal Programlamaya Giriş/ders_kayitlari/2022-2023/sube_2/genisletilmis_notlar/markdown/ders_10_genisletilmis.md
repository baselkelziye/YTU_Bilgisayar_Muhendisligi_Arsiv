# Ders 10 Genişletilmiş Notu: Fonksiyonlara Dizi ve Pointer Aktarımı, Histogram ile Seçim Sistemleri ve Sayarak Sıralama

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Fonksiyonların dört türü ve prototip
- 2. Fonksiyona dizi gönderme
- 3. Yığın, yerel değişkenin ömrü ve pointer döndürme tehlikesi
- 4. Pointer ile birden fazla sonuç döndürme
- 5. Önceki algoritmaları fonksiyonlara bölme: birleştirme ve sıralılık denetimi
- 6. Soru: 1'ler ve 2'lerin sayısı
- 7. Histogram
- 8. Seçim sistemleri
- 9. Sayarak doğrusal sıralama
- 10. Counting sort
- Örnek Sorular
- Dersin Toparlaması

## 1. Fonksiyonların dört türü ve prototip

Ders, önceki haftada başlanan fonksiyon konusunun tamamlanmasıyla açıldı. Fonksiyonlar programı modüler yazmayı sağlar. Bir fonksiyon iki bakımdan incelenir: çağrılırken **parametre alıp almadığı** ve **değer döndürüp döndürmediği**. Bu iki ikili özellik $2 \times 2 = 4$ durum verir. Ders boyunca Dev-C++ ortamında her durum için küçük bir örnek yazıldı.

### 1.1 Parametre almayan, değer döndürmeyen: menü

Tipik örnek bir menüdür: "1'e basarsan toplama, 2'ye basarsan çıkarma, 3'e basarsan çıkış" gibi seçenekleri ekrana basar. Bu satırlar `main` içine de yazılabilir; ama menünün önünde ve arkasında çok sayıda satır olduğunu düşünürsek, menüyü bir fonksiyona koymak ve bu fonksiyonu bir döngü içinde çağırmak `main`'i sadeleştirir. Kullanıcı çıkmak istemediği sürece menü tekrar tekrar ekrana gelir. Her gösterimden önce ekranı temizlemek için Windows'ta işletim sistemine `cls` komutu gönderilebilir: `system("cls");`.

Değer döndürmediği için dönüş türü `void`'dir; parametre almadığı için parantez boş kalır ve çağrı `menu();` biçimindedir.

### 1.2 Parametre alan, değer döndürmeyen: ekrana yazma

`main`'de `double x = 3.4, e = 2.17;` tanımlandı ve bu iki değeri yazan `ekranaYaz(x, e)` çağrıldı (ekrandan, 00:30:00). Tanımda iki `double` gelecekse iki `double` parametre tanımlanır: `void ekranaYaz(double x, double y)`. Parametre adlarının çağrıdaki değişken adlarıyla aynı olması gerekmez. `double` değer `printf` ile `%lf` biçimiyle yazılır.

### 1.3 Parametre almayan, değer döndüren: değer okuma

`int degerOku()` fonksiyonu içinde bir geçici değişkene `scanf("%d", &temp)` ile değer okur ve `return temp;` ile döndürür. `main`'de `y = degerOku();` yazılarak dönen değer alınır. Hoca, bunun doğrudan `scanf` ile de yapılabileceğini, örneğin amacının yalnızca fonksiyon kullanımını göstermek olduğunu belirtti. Bu fonksiyon `main`'den önce tanımlandığı için prototipe gerek kalmadı.

`return` ifadesi **yalnız bir değer** döndürür. Fonksiyonda `t` ve `a` gibi iki değişken olsa bile `return t, a;` gibi bir yazımla ikisi birden döndürülemez; hangisi döndürülecekse yalnız o yazılır. Birden fazla sonuç gerekiyorsa başka bir mekanizma kullanılır (Bölüm 4).

### 1.4 Parametre alan, değer döndüren: kare alma

```c
int mySquare(int x){
    return x*x;
}
```

**Soru:** Önce `return` mu çalışır, çarpma mı? **Cevap:** Önce matematiksel işlem yapılır; elde edilen sayısal sonuç döndürülür.

### 1.5 Prototip

Bir fonksiyon `main`'den sonra yazılacaksa başlığı alınır, sonuna noktalı virgül konur ve `main`'den önce yazılır. Buna **prototip** denir. Prototiplerin sırası günümüz derleyicilerinde önemli değildir; eski derleyicilerde önemliydi. Hoca, işin içine diziler ve pointer'lar girince prototip yazmadan programın derlenmeyeceğini, bu yüzden prototipleri her zaman yazmak gerektiğini söyledi.

**Soru:** Aşağıdaki bir fonksiyonu değiştirince üstteki prototipi de değiştirmek zorunda mıyız? **Cevap:** Fonksiyonun başlığı değiştiyse evet. Prototip ile tanım uyuşmazsa derleyici "conflicting types" uyarısı verir; sıkı bir C derleyicisinde başlığın birebir aynısı yukarıya yazılmalıdır (ekrandan, 01:00:00).

### 1.6 Değişken sayıda argüman

**Soru:** `ekranaYaz` iki argüman alıyor; ona bir ya da üç argüman gönderebilir miyiz? **Cevap:** ANSI C'de doğrudan mümkün değildir. Python gibi bazı dillerde parametreye varsayılan değer verilebilir (örneğin `y = 0`); argüman gönderilmezse varsayılan değer kullanılır. C'de bu yoktur; "en sade, en kurallı haliyle" düşünülür.

Öğrenci, `scanf`'in bazen iki bazen üç argümanla çağrıldığını hatırlattı. Hoca, Dev-C++'ta `scanf` yazılınca açılan ipucu kutusunu gösterdi: prototip `int scanf(const char *_Format, ...)` biçimindedir (ekrandan, 00:55:00). Sondaki `...` değişken sayıda argüman alınmasını sağlar; `printf` ve `scanf` bu şekilde çalışır. Bu mekanizma dönemin konusu olmadığı için anlatılmadı.

## 2. Fonksiyona dizi gönderme

Şimdiye kadar gönderilen bütün değişkenler **skaler**di; yani tek bir bilgi taşıyordu. Sıra dizi göndermeye geldi.

### 2.1 Örnek: büyük harfe çevirme

`main`'de `char c[MAX] = {'a','b','c','d'};` tanımlandı (`MAX` = 4) (ekrandan, 00:35:00). Dizideki harfleri büyük harfe çeviren bir fonksiyon yazılacak. Dizi göndermek, diziyle birlikte **eleman sayısını** göndermek demektir:

```c
void buyukHarfeCevir(char c[], int n){
    int i;
    for(i=0;i<n;i++)
        c[i] -= 32;
}
```

Küçük `a`'nın ASCII kodu 97, büyük `A`'nınki 65'tir; aradaki fark 32'dir. İlk sürümde fonksiyon yalnızca `printf("%c ", c[i]-32)` ile büyük harfli halini ekrana yazdırıyordu; sonra diziyi gerçekten değiştiren `c[i] -= 32` haline getirildi.

Parametredeki köşeli parantezin içine 4 yazmak bir anlam taşımaz; içi boş bırakılabilir ve hoca bu yazımı tercih ettiğini söyledi. Dizi boyutu `#define MAX 4` ile tanımlanıp her yerde `MAX` kullanılarak program parametrik hale getirildi.

> **Hocanın vurgusu:** Fonksiyona dizi gönderiyorsak dizinin eleman sayısını da mutlaka parametre olarak göndermeliyiz. Bu yazım stiline dikkat edilirse hiçbir sorun yaşanmaz.

### 2.2 Derin kopya ve sığ kopya

Dizinin adı (`c`), dizinin ilk elemanının adresini tutan bir pointer gibidir. Fonksiyon çağrıldığında dizinin elemanları yeni bir yere kopyalanmaz; yalnızca bu adres kopyalanır. Bellekte bir yerde 4 eleman, başka bir yerde de 4 eleman daha oluşmaz.

- Skaler parametrelerde (örneğin `ekranaYaz`'daki `x` ve `y`, ya da `n`) değerin birebir kopyası oluşturulur. Hoca buna **derin kopya (deep copy)** dedi.
- Dizi parametresinde yalnızca adres kopyalanır. Hoca buna **sığ kopya (shallow copy)** dedi.

**Soru:** `char c[4]` yazınca fonksiyon çalışırken yeni bir dizi oluşturmuş olmuyor muyuz? **Cevap:** Fonksiyon çağrıldığında, önceki derste anlatılan **yığın (stack)** bölgesinde geçici bir alan açılır; fonksiyon bitip çağrılan yere dönülünce bu alan yok edilir. Dizinin kendisi oraya kopyalanmaz.

Bir öğrenci `static` anahtar kelimesini sordu; hoca bunun ve `malloc`'un ayrıca ele alınacağını, şimdilik mevcut bilgilerle devam edileceğini söyledi.

### 2.3 Fonksiyondaki değişiklik asıl diziye yansır mı?

Diziyi ekrana yazan bir fonksiyon eklendi ve `main`'de şu çağrılar yapıldı (ekrandan, 00:30:00):

```c
diziYazdir(c,MAX);        // a b c d
buyukHarfeCevir(c,MAX);
diziYazdir(c,MAX);        // A B C D
```

Hoca, ikinci `diziYazdir` çağrısında ne görüleceğini sordu. Bir öğrenci, fonksiyon `void` olduğu ve diziyi değiştirmediği için iki satırda da küçük harf görüleceğini söyledi. Hoca iki noktayı düzeltti:

- `void` olmak yalnızca dönüş değeriyle ilgilidir; içeriğin değişip değişmeyeceğini belirlemez.
- Skaler bir parametrede (örneğin `n = 8` yapılsa) değişiklik çağrılan yere yansımaz. Ama dizide arka planda örtülü bir pointer vardır; önceki haftaki `swap` fonksiyonunda olduğu gibi, fonksiyonun dizinin elemanları üzerinde yaptığı her değişiklik asıl diziye yansır.

Bu yüzden ikinci satırda `A B C D` görülür. Hoca bunu hata ayıklayıcıda gösterdi: kesme noktası koydu, `c`'yi izlemeye ekledi (add watch), adım adım fonksiyona girdi. Fonksiyon içinde yeni bir `c` oluşmadığı, çağrıdan sonra `main`'deki dizinin `ABCD` olduğu görüldü. Derleme sırasında `diziYazdir`'ın prototipte farklı harf büyüklüğüyle yazılmasından kaynaklanan bir "undefined reference" hatası da düzeltildi (bir öğrenci büyük-küçük harf farkını fark etti).

Bu mekanizmanın iki faydası vardır:

- Kopyalama maliyetini önler. `MAX` 4 değil 4000 olsaydı, her çağrıda 4000'lik yeni bir dizi açılıp bütün değerler kopyalanırdı.
- Dizinin içeriği fonksiyonda değiştirilmek isteniyorsa değişiklik doğrudan asıl diziye yansır.

Dizinin değiştirilmemesi isteniyorsa parametre `const` ile tanımlanabilir.

> **Hocanın vurgusu:** Diziler fonksiyona gönderilirken, swap örneğinde olduğu gibi pointer gibi gider. Bunu hiçbir zaman unutmuyoruz.

### 2.4 Fonksiyondan dizi döndürülemez

C'de fonksiyondan doğrudan dizi döndürmek yoktur. Fonksiyonda `n` elemanlı bir dizi oluşturup `return dizi;` yazmak dilde tanımlı değildir. Bunun nedeni, fonksiyon bitince yerel dizinin de yok olmasıdır: olmayan bir dizinin adresini döndürmenin anlamı yoktur, bu yüzden C bunu doğrudan engeller. Bu iş pointer'lar ve `malloc` ile yapılabilir; bu, normalde sonraki dönemin konusudur.

### 2.5 Önerilen dizi parametresi yazımı

En genel ve temiz yazım, köşeli parantezin içini boş bırakmak ve eleman sayısını ayrı parametre olarak almaktır:

```c
void diziYazdir(char c[], int n);
```

Burada yalnızca gelen şeyin normal bir değişken değil, bir dizi olduğunu belirtmek yeterlidir.

## 3. Yığın, yerel değişkenin ömrü ve pointer döndürme tehlikesi

### 3.1 Pointer döndüren fonksiyon

Hoca, pointer döndüren bir fonksiyon yazdı. İlk sürüm bir pointer ve bir tam sayı alıyordu; `temp` değişkenine "p'nin gösterdiği yerdeki değer artı 2 çarpı x" yazılıyor ve `temp`'in adresi döndürülüyordu. Çağrıda `c[2]`'nin değil adresinin gönderilmesi gerektiği fark edilince fonksiyon sadeleştirildi ve ilk parametre normal tam sayı yapıldı (ekrandan, 00:50:00):

```c
int* myfunc(int p, int x){
    int temp;
    temp = p + 2*x;
    return &temp;
}
```

`main`'de dönen pointer'ı tutmak için `int *ptr;` tanımlandı; dönüş türü pointer ise onu alan değişken de pointer olmalıdır. Hoca önce bu kodu tahtada izledi (ekrandan, 00:40:00):

```c
ptr = myfunc(c[2],2);
printf("\nSonuc (myfunc) : %d",*ptr);
```

`c[2]` başlangıçta küçük `c`, yani 99 olduğu için $99 + 2\cdot 2 = 103$ beklendi. Çalıştırınca 71 çıktı. Bunun nedeni, çağrıdan önce `buyukHarfeCevir`'in diziyi değiştirmiş olmasıydı: `c[2]` artık büyük `C`, yani 67'dir ve $67 + 2\cdot 2 = 71$ olur.

### 3.2 71 neden görüldü, sonra neden kayboldu?

Hoca bir öğrencinin "`temp` artık yok, değeri görmeyeceğiz" tahminine karşın 71'in görüldüğünü belirtti ve yığını tahtada çizerek açıkladı (ekrandan, 00:40:00):

- Program başlayınca `main` yığına yüklenir.
- `diziYazdir` çağrılınca onun alanı `main`'in üstüne açılır; fonksiyon bitince bu alan silinir.
- Ardından `buyukHarfeCevir` aynı bölgeye yerleşir, işi bitince o da silinir; sonra `diziYazdir` yeniden gelir ve gider.
- `myfunc` çağrılır ve biter. Alanı serbest kalır, ama üstüne henüz yeni bir şey yazılmadığı için `temp`'in eski değeri orada "çöp" olarak durur.

Fonksiyonun hemen ardından `*ptr` yazdırılınca 71 görülmesi bu yüzdendir. Ardından ikinci bir senaryo kuruldu (ekrandan, 00:50:00):

```c
ptr = myfunc(c[2],2);
diziYazdir(c,MAX);
diziYazdir(c,MAX);
printf("\nSonuc (myfunc) : %p %d",ptr, *ptr);
```

Bu kez sonuç 4 çıktı. `%p` ile yazdırılan adres iki senaryoda da aynıydı; ama aradaki iki fonksiyon çağrısı o bellek bölgesinin üstüne yazmıştı. `diziYazdir` diziyi değiştirmediği için dizide bir değişiklik yoktu; değişen, `ptr`'nin gösterdiği ölü değişkenin yeriydi. Hoca bunu "köprünün altından çok su geçti" diye özetledi: `temp`'in ömrü (lifetime, duration) bitmiştir, adresi yakalansa bile kullanılamaz.

Derleyici de bu durumu fark eder ve uyarı verir: `function returns address of local variable [-Wreturn-local-addr]` (ekrandan, 00:50:00). Bu bir hata değil uyarıdır; kod derlenir ve çalışır, ama yanlış sonuç verebilir.

> **Hocanın vurgusu:** Bu kod algoritmik olarak çalışır görünür, ama programlama olarak burada bir sakatlık var. "Hatalı sonuç verebilir" değil, "verir" diye düşünün ve böyle bir şey yapmayın. C'nin belleği nasıl yönettiğini anlamanın en iyi yolu bu konudur.

> **Ek bilgi (derste anlatılmadı):** Güncel GCC sürümleri bu durumda adres yerine büyük olasılıkla doğrudan `NULL` döndüren kod üretir. Bu notu hazırlarken aynı fonksiyon `gcc -Wall` ile derlenip çalıştırıldığında `ptr` değeri `(nil)` çıktı; `*ptr` okunsaydı program çökerdi. Derste görülen 71 ve 4 değerleri derste kullanılan derleyiciye özgüdür.

### 3.3 Değer döndürmek neden güvenli?

`mySquare` gibi sayısal değer döndüren bir fonksiyonda sorun yoktur. `int x = mySquare(5);` çağrısında 5 parametreye kopyalanır, $5 \cdot 5 = 25$ hesaplanır ve 25 döndürülür. Dönen değer `x`'e kopyalanır; hoca bunu da bir derin kopya olarak niteledi. Fonksiyondaki 25 ölür, ama `x`'teki 25 yaşamaya devam eder.

**Soru:** Fonksiyon bittiğinde dönen değer hafızanın bir yerinde saklanıyor mu? **Cevap:** Başka bir yerde saklanmaz. Dönen değeri saklamak istiyorsanız `=` ile bir değişkene alırsınız. Sorun, bu `=`'nin sol tarafı pointer olduğunda ortaya çıkar: o zaman bir değer değil adres saklanır ve adresteki değer sonradan değişebilir.

Hoca özeti şöyle yaptı:

- Dizi döndürülemez; bunun için ileride başka bir yöntem görülecek.
- Dizi parametre olarak alınabilir; alınırken boyutu da alınır.
- Fonksiyon `int`, `char`, `float`, `long` gibi bir değer döndürüyorsa sorun yoktur.
- Pointer döndürüyorsa çok dikkat edilmelidir; çalışır ama "gizli bir mayınlı arazi" vardır. Bunun istisnaları (örneğin `static`) yeri gelince konuşulacaktır.

## 4. Pointer ile birden fazla sonuç döndürme

### 4.1 `scanf` benzeri bir fonksiyon

`return` tek değer döndürür; peki iki sonuç gerekiyorsa? Aslında bunu zaten kullanıyoruz: `scanf("%d %d", &x, &y);` hem `x`'i hem `y`'yi doldurur. Aynı şeyi kendi fonksiyonumuzla yapabiliriz (ekrandan, 00:55:00):

```c
void funcG(int *x, int *y){
    *x=5;
    *y=8;
}
```

`main`'de `funcG(&y, &t);` çağrıldı. Fonksiyondaki `x` pointer'ı `main`'deki `y`'nin, `y` pointer'ı ise `t`'nin adresini tutar. Hoca adları bilerek karışık seçti: eşleşme ada göre değil sıraya göre olur. Çağrıdan sonra `y = 5`, `t = 8` olur ve `printf("\n%d %d", y, t)` `5 8` yazar. Fonksiyon `return` kullanmadan, gizlice iki değer döndürmüş olur.

### 4.2 En büyük ve en küçük elemanın yeri

Dizinin en büyük ve en küçük elemanının yerini aynı anda bulan fonksiyon (ekrandan, 01:00:00):

```c
void bul(char c[], int N, int *max, int *min){
    int i;
    int tmax=0;
    int tmin=0;
    for(i=0;i<N;i++){
        if(c[i]>c[tmax])
            tmax=i;
        if(c[i]<c[tmin])
            tmin=i;
    }
    *max=tmax;
    *min=tmin;
}
```

Döngü bittiğinde `tmax`'ta en büyük, `tmin`'de en küçük elemanın indisi vardır; bunlar pointer'ların gösterdiği yerlere yazılır. `main`'de:

```c
bul(c, 4, &y, &t);
printf("max=%d, min=%d---",y,t);
printf("max=%c, min=%c",c[y],c[t]);
```

`c` dizisi bu noktada `ABCD` olduğu için sonuç `max=3, min=0` ve `max=D, min=A`'dır. İstenirse indis yerine değerin kendisi de tutulabilirdi.

## 5. Önceki algoritmaları fonksiyonlara bölme: birleştirme ve sıralılık denetimi

Aradan sonra önceki derste yazılan **iki sıralı diziyi birleştirme** algoritması fonksiyonlara bölündü. Amaç hem fonksiyon bilgisini tekrar etmek hem de algoritmaları yeniden denemekti.

### 5.1 Dizi doldurma, yazdırma ve birleştirme

Kodda her dizi için ayrı ayrı yazılmış doldurma ve yazdırma döngüleri gereksiz tekrar oluşturuyordu. Bunun yerine iki genel fonksiyon yazıldı (ekrandan, 01:25:00):

```c
void diziDoldur(int d[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d. eleman gir ",i);
        scanf("%d",&d[i]);
    }
}
```

`d` pointer gibi gelse de `d[i]` bir pointer değildir; `scanf` için `d[i]`'nin adresi `&d[i]` yazılmalıdır.

> **Hocanın vurgusu:** Dizi dolduran fonksiyona dizi yazdırma işi yaptırmayın. Her fonksiyonun tek bir görevi olmalıdır; bir fonksiyonun üstlendiği iş sayısı arttıkça işler zorlaşır. Bu, yazılım mühendisliğinin temel kriteridir.

`diziYazdir` sonradan başa bir etiket yazacak şekilde genişletildi: `void diziYazdir(char *c, int d[], int n)`. Çağrı `diziYazdir("Dizi-1", d1, N);` biçimindedir. `"Dizi-1"` bir karakter dizisidir; fonksiyon ilk karakterin adresini alır, `printf("%s", c)` bu adresten başlayıp `'\0'` görene kadar bütün karakterleri yazar.

**Soru:** Etiketi neden `char c[]` değil `char *c` diye alıyoruz? **Cevap:** İkisi aynıdır, hiçbir şey fark etmez. Ama hoca, ileride dizgi işlemlerinde işi kolaylaştıracağı için pointer yazımına alışılmasını tercih ettiğini söyledi.

Birleştirme fonksiyonu, `main`'deki çağrıya uygun biçimde tanımlandı (ekrandan, 01:20:00):

```c
merge(d1, N, d2, M, d3);
```

Parametreler aynı sırayla `int d1[], int n, int d2[], int m, int d3[]` olmalıdır. İlk yazımda `d3` parametresi `int d3` diye yazılmıştı; derleyici `d3[k]` için hata verdi ve `int d3[]` yapıldı. **Soru:** `d3`'e eleman sayısı olarak `m+n`'yi de göndermemiz gerekmez mi? **Cevap:** `n` ve `m` zaten gönderildiği için içeride hesaplanabilir. Dizilerin sıralı girileceği kabul edildi. Birleştirme gövdesi önceki dersten olduğu gibi kopyalandı; aşağıdaki gövde bu not için yazılıp derlenmiştir:

```c
void merge(int d1[], int n, int d2[], int m, int d3[]){
    int i=0, j=0, k=0;
    while(i<n && j<m){
        if(d1[i]<d2[j]){ d3[k]=d1[i]; i++; }
        else { d3[k]=d2[j]; j++; }
        k++;
    }
    while(i<n){ d3[k]=d1[i]; i++; k++; }
    while(j<m){ d3[k]=d2[j]; j++; k++; }
}
```

### 5.2 Makro adlarıyla parametre adlarının çakışması

Derlerken art arda hatalar alındı. Sorun, `#define N 4` ve `#define M 3` makrolarıyla fonksiyonların `N`, `M` parametre adlarının aynı olmasıydı. Önişlemci makro adını her yerde metin olarak değiştirdiği için parametre listesi `int 4` gibi anlamsız bir şeye dönüşür ve derleyici "numeric constant" hatası verir. Çözüm, makro adları ile parametre adlarını ayırmaktır. Hoca, makro adlarının genelde büyük harfle yazıldığını, adlandırmanın baştan düşünülmesi gerektiğini, bir yerde değişen bir adın her yerde değiştirilmek zorunda kalınmasının yazılımın en büyük sıkıntılarından biri olduğunu söyledi. Ayrıca makroların prototiplerden önce yazılması gerektiği görüldü.

Çalıştırıldığında birinci diziye `1 4 8 9`, ikinciye `2 3 7` girildi ve birleşik dizi `1 2 3 4 7 8 9` çıktı.

### 5.3 Sıralılık denetimi

Önceki haftanın sorusu da fonksiyonla çözüldü: dizi sıralı mı? En az karmaşıklığa sahip yol, ilk elemandan başlayıp ardışık her çifti karşılaştırmaktır (ekrandan, 01:25:00):

```c
char* kontrol(int d[], int n){
    int i=0;
    while(i<n-1 && d[i]<d[i+1]){
        i++;
    }
    if(i==n-1)
        return "SIRALI";
    else
        return "SIRASIZ";
}
```

Döngü bir kural bozulmasına rastlamadan `n-1`'e ulaşırsa dizi sıralıdır. İlk sürümde fonksiyon `int` döndürüyordu (sıralıysa 1, değilse 0). Birleşik dizi bu fonksiyonla denetlendi; böylece hem birleştirme kodu hem denetleme algoritması sınanmış oldu. Önce sonuç ekrana yazdırılmadığı için hiçbir şey görülmedi; hoca, bir hata bile vermeden sonucun kaybolmasının ne kadar tehlikeli olduğunu belirtti. Yazdırılınca yalnızca `1` görüldü; kodlamayı unutan biri için bu `1`'in ne anlama geldiği belirsizdir.

**Soru:** C'de Boolean türünde değişken var mı? **Cevap:** Hoca, C'de `true`/`false` olmadığını söyledi; olsaydı bile ekrana anlamlı bir yazı basmak için dizgiye çevirmek gerekirdi.

> **Ders sonrası not:** Hocanın cevabı derste kullanılan ANSI C (C89) için doğrudur. C99 ve sonrasında `_Bool` türü ve `<stdbool.h>` başlığındaki `bool`, `true`, `false` vardır.

Bu yüzden fonksiyon `"SIRALI"` ya da `"SIRASIZ"` sabit dizgisini döndürecek şekilde değiştirildi ve `main`'de `char* sonuc; sonuc = kontrol(d3, n+m); printf("%s", sonuc);` yazıldı (ekrandan, 01:30:00). İlk denemede eşit elemanlar girildiği için iki çalıştırmada da `SIRASIZ` çıktı; karşılaştırma `<` olduğundan eşit elemanlar sıralı sayılmaz. `1 4 7 9` ve `2 3 6` girilince `SIRALI` çıktı.

Burada da bir pointer döndürülüyor; ama hoca, döndürülen şeyin yerel bir değişkenin adresi değil, **sabit bir dizgi** olduğunu ve bunun sorun yaratmadığını vurguladı. Yerel bir `float` değişken tanımlayıp adresini döndürmek ise Bölüm 3'teki hatanın aynısıdır.

> **Ders sonrası not:** Hoca dizgilerin "birebir kopyalandığını" söyledi. Büyük olasılıkla kastedilen şudur: `"SIRALI"` gibi dizgi sabitleri yığında değil, programın ömrü boyunca yaşayan statik bir bellek bölgesinde saklanır; fonksiyon yalnızca bu bölgenin adresini döndürür, dizgi kopyalanmaz. Adres fonksiyon bitince de geçerli kaldığı için döndürmek güvenlidir.

## 6. Soru: 1'ler ve 2'lerin sayısı

Soru: Bir dizi yalnızca 1 ve 2'lerden oluşuyor. Kaç tane 1, kaç tane 2 var?

### 6.1 Birinci çözüm: iki sayaç

Dizi `diziDoldur` ile dolduruldu. Sayma işi iki sonuç ürettiği için bir `say` fonksiyonu yazıldı ve sayaçlar adresleriyle gönderildi. Tek bir sonuç olsaydı (yalnızca 1'lerin sayısı) `return` ile alınabilirdi; iki sonuç istendiği için pointer gerekir (ekrandan, 01:35:00):

```c
void say(int d[], int n, int *c1, int *c2){
    int i;
    *c1 = *c2 = 0;
    for(i=0;i<n;i++){
        if(d[i]==1)
            *c1 = *c1 + 1;
        else if(d[i]==2)
            *c2 = *c2 + 1;
    }
}
```

`main`'de çağrı `say(d1, n, &c1, &c2);`'dir. Sonuç yazdırılırken `printf` içinde `c1`, `c2` doğrudan kullanılır, yıldız kullanılmaz. **Soru (hocanın sorusu):** Burada neden yıldız kullanmadık? **Cevap (öğrenci):** Bunlar `main`'in kendi değişkenleri, pointer değişkeni değiller. Yalnızca `say` içinde pointer üzerinden erişilirler.

`1 2 1 2 1` girildiğinde sonuç: 1'lerin sayısı 3, 2'lerin sayısı 2. Aşağıdaki tam program bu not için derlenip aynı girdiyle çalıştırıldı:

```c
#include <stdio.h>
#define N 5
void diziDoldur(int d[], int n);
void say(int d[], int n, int *c1, int *c2);
int main(){
    int d1[N];
    int c1, c2;
    diziDoldur(d1,N);
    say(d1,N,&c1,&c2);
    printf("1 sayisi = %d, 2 sayisi = %d\n", c1, c2);
    return 0;
}
void diziDoldur(int d[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d. eleman gir ",i);
        scanf("%d",&d[i]);
    }
}
void say(int d[], int n, int *c1, int *c2){
    int i;
    *c1 = *c2 = 0;
    for(i=0;i<n;i++){
        if(d[i]==1)
            *c1 = *c1 + 1;
        else if(d[i]==2)
            *c2 = *c2 + 1;
    }
}
```

### 6.2 Çözüm genel mi?

Diziye 3'ler de eklenirse `c3` diye bir sayaç, bir pointer parametre ve bir `else if` daha eklenir. Kod doğru çalışır (doğruluk açısından sorun yok) ve zaman karmaşıklığı da $n$'dir. Ama dizi $n$ farklı değerden oluşacaksa her biri için bir `if` yazmak gerekir. Hoca bunun **genellik (generality)**, yani parametrik olma kuralını ihlal ettiğini söyledi.

> **Hocanın vurgusu:** Mühendislik, işin sonrasını hesap etmekle ilgilidir. Yüz farklı değer için yüz tane `if` yazmak hem bilgisayar mühendisliğinin doğasına hem mantığa aykırıdır; böyle bir program olmaz.

## 7. Histogram

### 7.1 Tanım ve fikir

Bir veri kümesinde her değerden kaç tane bulunduğunu gösteren dağılıma istatistikte **histogram** denir. Örnek: 0 ile 100 arasındaki öğrenci notlarında 0 alan, 1 alan, ..., 100 alan kaç kişi var?

Genel çözüm için değerlerin hangi aralıkta olduğu bilinmelidir. Bu genellikle bilinir; bilinmiyorsa dizinin en büyük elemanı bulunarak öğrenilir. En kolay durumda değerler 0'dan bir `MAX` değerine kadardır. Fikir şudur: 1'lerin, 2'lerin, ..., 100'lerin sayısını ayrı ayrı yerlerde tutmak ve her yeni değer görüldüğünde ilgili sayacı bir artırmak. Bu sayaçlar bir diziye konursa her değerin sayacı, dizide o değerin indisindeki elemandır.

Hoca bunu tahtada şöyle izledi: notlar `1, 8, 80, 40, 1, ...` olsun; 101 elemanlı histogram dizisinin hepsi başta 0'dır. 1 görülünce `histogram[1]` 1 olur, 8 görülünce `histogram[8]` 1 olur, 80 görülünce `histogram[80]` 1 olur, 40 görülünce `histogram[40]` 1 olur, tekrar 1 görülünce `histogram[1]` 2 olur.

### 7.2 Sayma

```c
void say(int notlar[], int n, int histogram[]){
    int i;
    for(i=0;i<n;i++)
        histogram[notlar[i]]++;
}
```

Burada `notlar[i]++` değil `histogram[notlar[i]]++` yazılır: histogramın ilgili indisi notun kendisinden bulunur ve o eleman bir artırılır. Hiç `if` yazılmaz. Histogramın boyutunu fonksiyona göndermeye gerek yoktur, çünkü gezilen dizi histogram değil notlardır (ekrandan, 01:50:00).

### 7.3 Histogramı sıfırlamak

Histogram ilk yazdırıldığında içinde bir sürü çöp değer görüldü. Nedeni, bu bellek bölgesinin önceki kullanımlardan kalan değerleri taşımasıdır. C belleği temizlemeden verir; "kullanacaksan önce temizle, bu benim işim değil" der. En kolay yol, ilk elemanı sıfırlayan bir ilk değer listesi vermektir; listede yazılmayan elemanlar otomatik olarak sıfırlanır (ekrandan, 02:00:00):

```c
int histogram[MAX]={0};
```

Hoca, önceki bölümde pointer ile yanlış değer görülmesinin nedeninin de aynı olduğunu hatırlattı: C belleği çöp haliyle bırakır.

### 7.4 Histogramı yıldızlarla yazdırmak

**Soru (hocanın sorusu):** Histogram nasıl bir grafiktir? **Cevap (öğrenci):** Değerlerin üstünde sayılarına göre sütunlar olur. Hoca, bunun bir sütun grafiği gibi olduğunu doğruladı: histogram `3, 8, 5` ise ilk satırda 3, ikincide 8, üçüncüde 5 yıldız basılır. Düşey çizmek daha zor olduğu için yatay çizildi. Bunun için iç içe iki döngü gerekir: dıştaki histogramı gezer, içteki o elemanın değeri kadar yıldız basar.

İlk sürüm her satırı basıyordu; çoğu değer 0 olduğu için ekranda boş satırlar oluştu (ekrandan, 01:55:00: `1 1 4 4 5` girdisinde önce iki yıldız, birkaç boş satır, sonra yine iki yıldız ve bir yıldız). Bunu güzelleştirmek için yalnız sıfırdan büyük elemanlar basıldı ve satırın başına değer ile adet yazıldı:

```c
void histogramYaz(int d[], int n){
    int i, j;
    for(i=0;i<n;i++){
        if(d[i]>0){
            printf("%d - %d :", i, d[i]);
            for(j=0;j<d[i];j++)
                printf("*");
            printf("\n");
        }
    }
}
```

Örneğin `1 1 3 5 5` girilince `1 - 2 :**`, `3 - 1 :*`, `5 - 2 :**` satırları basılır.

### 7.5 Kazanç ve kayıp

Programı içinden çıkılmaz hale getirmekten kurtulduk, yani çok sayıda `if` yazmaktan kazandık. Bellekten kaybettik: 5 elemanlık bir not dizisi için 101 elemanlık, çoğu sıfır olan bir dizi açtık. Değerler çok büyük sayılardan oluşuyorsa çok büyük bir bellek alanı gerekir; bunun başka çözümleri vardır ve sonra konuşulacaktır.

## 8. Seçim sistemleri

Histogramın bir uygulaması olarak seçim sistemleri problemleri çözüldü. Slaytta dört durum vardı (ekrandan, 02:55:00):

- En çok oyu alan partiyi bulmak ($N$ seçmen sayısı, $N$ elemanlı bir dizi).
- Herkesin 1 değil 3 partiye oy vermesi durumu ($N \times 3$'lük bir matris).
- Herkesin her partiye 1-10 arası puan vermesi durumu ($P$ parti sayısı, $N \times P$'lik bir matris).
- Herkesin oyunun eşit olmadığı (ödediği ya da ödemesi gereken vergi, yaş, eğitim vb. ile ağırlıklandırılmış) durum ($N \times 2$'lik bir matris, ilk sütunda ağırlık, ikinci sütunda oy).

### 8.1 En çok oyu alan parti

Hoca, bu sorunun histogram koduyla nasıl ilişkilendirileceğini sordu. Bir öğrenci, oyları histogramı hesapladığımız gibi sayabileceğimizi söyledi. Gerçekten de değişen yalnızca adlardır: "notlar" yerine "oylar" olur. Oy dizisinin her elemanı bir kişinin oy verdiği partinin numarasıdır; histogram her partinin kaç oy aldığını verir.

**Soru (hocanın sorusu):** Bundan sonra birinci partiyi nasıl buluruz? **Cevap (öğrenci):** Histogram dizisinin en büyük elemanını buluruz. Hoca, en büyük elemanın yerini bulmanın yeterli olduğunu, yer biliniyorsa değerin de bilineceğini ekledi: en büyük elemanın indisi kazanan partinin numarası, değeri ise aldığı oy sayısıdır.

```c
int enBuyukBul(int h[], int n){
    int i, max=0;
    for(i=1;i<n;i++)
        if(h[i]>h[max])
            max=i;
    return max;
}
```

`main`'de `max = enBuyukBul(histogram, MAX);` ve `printf("max kisi = %d, oy sayisi = %d", max, histogram[max]);` yazıldı. Burada yerel `max`'ın değeri döndürülür; bu bir değer kopyasıdır, fonksiyon bitince yerel değişken ölse de değer `main`'de saklanır.

On kişinin oyunu elle girmek zahmetli olduğu için dizi rastgele sayılarla dolduruldu; rastgelelik bir sonraki derste ayrıca anlatılacaktı. `rand()` bir değer üretir; bunun 10'a göre modu alınıp 1 eklenince 1-10 arası bir parti numarası elde edilir: `d[i] = rand() % 10 + 1;` (ekrandan, 02:15:00).

> **Ders sonrası not:** Hoca `rand() % 10` için "0 ile 10 arası" dedi; doğrusu 0 ile 9 arasıdır. 1 eklenince 1-10 aralığı elde edilir.

İlk çalıştırmada histogram doğruydu (örneğin 5. partiye 3 oy), ama sonuç `max kisi = 10, oy sayisi = 49` gibi anlamsız çıktı (ekrandan, 02:05:00). Hoca kesme noktası koyup `h[i]`, `h[max]`, `max` ve `i` değişkenlerini izlemeye aldı. Bu sırada bir öğrenci hatayı buldu: fonksiyon ilk yazımda `return i;` diyordu. Döngü bitince `i` sınır değerinde olduğu için anlamsız bir indis dönüyordu; `return max;` yapılınca kazanan doğru bulundu (5. parti, 3 oy).

> **Ders sonrası not:** Ekrandaki ilk sürümde `#define MAX 10` ile `int histogram[MAX]` tanımlıydı; `rand() % 10 + 1` ise 10 değerini de üretir ve `histogram[10]` dizinin dışına yazar (geçerli indisler 0-9). Hoca bir aşamada `MAX`'ı 15'e çıkardı; değerler 1-10 arasındaysa histogram boyutu en az 11 olmalıdır.

Her çalıştırmada aynı oyların gelmesi dikkat çekti. `rand()` belli bir düzene göre çalışır; sonuçları zamana bağlamak için programın başında bir kez `srand(time(NULL));` çağrıldı. Bundan sonra her çalıştırmada farklı sonuç geldi. Eşit oy alan iki parti olduğunda `>` karşılaştırması ilk bulunanı tuttu. Kişi sayısı 100, sonra 1000'e, aday sayısı 15'e çıkarıldı; 1000 oyda kazanan aday 126 oy aldı.

Aşağıdaki tam program dersteki parçaların birleşimidir; bu not için `gcc -Wall` ile derlenip çalıştırıldı (histogram boyutu yukarıdaki ders sonrası nota göre 11 alındı):

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100
#define MAX 11
void diziDoldur(int d[], int n);
void say(int oylar[], int n, int histogram[]);
void histogramYaz(int d[], int n);
int enBuyukBul(int h[], int n);
int main(){
    int oylar[N];
    int histogram[MAX]={0};
    int max;
    srand(time(NULL));
    diziDoldur(oylar,N);
    say(oylar,N,histogram);
    histogramYaz(histogram,MAX);
    max = enBuyukBul(histogram,MAX);
    printf("max kisi = %d, oy sayisi = %d\n", max, histogram[max]);
    return 0;
}
void diziDoldur(int d[], int n){
    int i;
    for(i=0;i<n;i++)
        d[i] = rand() % 10 + 1;
}
void say(int oylar[], int n, int histogram[]){
    int i;
    for(i=0;i<n;i++)
        histogram[oylar[i]]++;
}
void histogramYaz(int d[], int n){
    int i, j;
    for(i=0;i<n;i++){
        if(d[i]>0){
            printf("%d - %d :", i, d[i]);
            for(j=0;j<d[i];j++)
                printf("*");
            printf("\n");
        }
    }
}
int enBuyukBul(int h[], int n){
    int i, max=0;
    for(i=1;i<n;i++)
        if(h[i]>h[max])
            max=i;
    return max;
}
```

### 8.2 Herkes üç partiye oy veriyor

Artık her kişinin birinci, ikinci ve üçüncü oyu vardır. Bunun için üç ayrı dizi (`oylar1`, `oylar2`, `oylar3`) açılabilirdi; ama oy sayısı 13 olsaydı bu çok zahmetli olurdu. Doğru veri yapısı $N \times 3$'lük bir **matristir**: satır kişiyi, sütun kişinin kaçıncı oyu olduğunu gösterir.

> **Hocanın vurgusu:** Programlamaya geçmeden önce veri yapısını tasarlamak gerekir.

Fonksiyona matris gönderirken ilk boyut boş bırakılabilir, ama **ikinci boyut mutlaka yazılmalıdır**. Hoca bunu şimdilik ezbere bir kural olarak bilmemizi, gerekçesinin ayrıca anlatılacağını söyledi. Oy sayısı genelleştirilmek için bir makroyla verildi (ekrandan, 02:25:00):

```c
#define MAX 10
#define O 3

void diziDoldur(int d[][O], int n, int m);
void diziYazdir(char *c, int d[][O], int n, int m);
void say(int oylar[][O], int n, int m, int histogram[]);
void histogramYaz(int d[], int n);
int enBuyukBul(int h[], int n);
```

Satır sayısı köşeli parantezde verilmediği için ayrı parametre olarak gönderilir; sütun sayısı da makro olduğu halde genel yazım için ayrıca gönderildi. Doldurma ve yazdırma artık iç içe iki döngüyle yapılır: dıştaki döngü kaçıncı kişinin oy kullandığını, içteki döngü kişinin kaçıncı oyunu kullandığını gezer; her hücreye `rand() % 10 + 1` yazılır. Yazdırırken `%2d` ile her değere iki karakterlik yer ayrıldı.

Sayma da yalnızca bir döngü daha eklenerek değişir: `oylar[i][j]`, $i$. kişinin $j$. oyunu hangi partiye verdiğini söyler. Histogramda o partinin sayacı bir artırılır (ekrandan, 02:40:00; ekranda sütun boyutu bu aşamada `P` makrosuyla yazılıydı):

```c
void say(int oylar[][O], int n, int m, int histogram[]){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            histogram[oylar[i][j]] ++;
        }
    }
}
```

Histogramı yazdırma ve en büyüğünü bulma fonksiyonlarında hiçbir değişiklik gerekmez: kişi ister 3 ister 13 partiye oy versin, histogram yalnızca partilerin kaçar oy aldığını gösterir. Oy sayısını 5 yapmak için yalnız makronun değerini değiştirmek yeterlidir. Hoca, bu örnekleri fonksiyonlar olmadan anlatmanın çok daha karmaşık olacağını, böylece hem fonksiyonların tekrar edildiğini hem algoritma örneklerinin yapıldığını söyledi.

### 8.3 Herkes her partiye 1-10 arası puan veriyor

Bu kez $N$ kişi $P$ partinin her birine 1-10 arası puan verir. Hoca veri yapısını sordu; bir öğrenci yine iki boyutlu bir matris kullanılacağını, içine oy yerine puan yazılacağını söyledi. Matrisin satırları kişiler ($0, 1, \dots, N-1$), sütunları partiler ($0, 1, \dots, P-1$), hücreleri puanlardır. Sonuç $P$ elemanlı bir dizide tutulur: her eleman bir partinin toplam puanıdır (ekrandan, 02:30:00).

**Soru (hocanın sorusu):** Bu matristen her partinin puanını nasıl elde ederiz? **Cevap (öğrenci):** Her partinin puanlarını kişiler üzerinden toplarız. Bütün matris gezilir: $i$ kişiler üzerinde $N$'ye, $j$ partiler üzerinde $P$'ye kadar gider. `m[i][j]` $i$. kişinin $j$. partiye verdiği puandır; bu puan $j$. partinin toplamına eklenir:

$$\text{toplam}[j] \mathrel{+}= m[i][j]$$

Hoca, bunun yerine indisleri yer değiştirip `toplam[i] += m[j][i]` yazmanın da aynı işi yapıp yapmayacağını sordu. Bir öğrenci, ikinci yazımda döngü sınırlarının da değiştirilmesi gerektiğini, aksi halde $N \times P$'lik matrisin $P \times N$ gibi gezileceğini belirtti; hoca katıldı. Doğru sınırlarla iki yazım da çalışır: birinde kişi sabit tutulup partiler değişir, diğerinde parti sabit tutulup kişiler değişir. Bir öğrenci, parti sabit tutulursa puanların önce geçici bir değişkende toplanıp sonra atanabileceğini önerdi; hoca bunun da olacağını söyledi.

Kodda değişen tek satır, `histogram[oylar[i][j]]++` yerine sütun toplamıdır. Artık histogram adı tam doğru değildir, çünkü sayılar birer birer değil puan kadar artar; ama bir histogram gibi düşünülebilir. Toplamlar dizisi sıfırlanarak açılmalıdır.

Örnek çıktı (ekrandan, 02:45:00): 5 kişinin 5 partiye verdiği puanlar

```text
 7 10  8 10  3
 5  2  5  4  1
 7  4  7 10  7
 9  4  2  1  9
 5  2  9  2  2
```

Sonuçlar: 0. parti 33, 1. parti 22, 2. parti 31, 3. parti 27, 4. parti 22; kazanan 0. parti, 33 puan. Hoca 0. partinin toplamını sözlü doğruladı: $7 + 5 = 12$, $12 + 7 = 19$, $19 + 9 = 28$, $28 + 5 = 33$. Diğer sütunlar da toplandığında $10+2+4+4+2 = 22$, $8+5+7+2+9 = 31$, $10+4+10+1+2 = 27$, $3+1+7+9+2 = 22$ bulunur.

Bu bölümün tam programı not için derlenip çalıştırıldı:

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
#define P 5
void diziDoldur(int d[][P], int n, int p);
void diziYazdir(char *c, int d[][P], int n, int p);
void say(int oylar[][P], int n, int p, int histogram[]);
void histogramYaz(int d[], int n);
int enBuyukBul(int h[], int n);
int main(){
    int oylar[N][P];
    int histogram[P]={0};
    int max;
    srand(time(NULL));
    diziDoldur(oylar,N,P);
    diziYazdir("PUANLI OYLAR",oylar,N,P);
    say(oylar,N,P,histogram);
    printf("\nSONUCLAR\n");
    histogramYaz(histogram,P);
    max = enBuyukBul(histogram,P);
    printf("max kisi = %d, oy sayisi = %d\n", max, histogram[max]);
    return 0;
}
void diziDoldur(int d[][P], int n, int p){
    int i, j;
    for(i=0;i<n;i++)
        for(j=0;j<p;j++)
            d[i][j] = rand() % 10 + 1;
}
void diziYazdir(char *c, int d[][P], int n, int p){
    int i, j;
    printf("%s:\n",c);
    for(i=0;i<n;i++){
        for(j=0;j<p;j++)
            printf("%2d ",d[i][j]);
        printf("\n");
    }
}
void say(int oylar[][P], int n, int p, int histogram[]){
    int i, j;
    for(i=0;i<n;i++)
        for(j=0;j<p;j++)
            histogram[j] += oylar[i][j];
}
void histogramYaz(int d[], int n){
    int i, j;
    for(i=0;i<n;i++){
        if(d[i]>0){
            printf("%d - %d :", i, d[i]);
            for(j=0;j<d[i];j++)
                printf("*");
            printf("\n");
        }
    }
}
int enBuyukBul(int h[], int n){
    int i, max=0;
    for(i=1;i<n;i++)
        if(h[i]>h[max])
            max=i;
    return max;
}
```

Bir çalıştırmada iki parti aynı en yüksek puanı (37) aldı. Hoca, `enBuyukBul`'un ilk bulduğunu döndürdüğünü; birden fazla kazanan olup olmadığını anlamak için önce en büyük değerin bulunup sonra dizinin yeniden gezilebileceğini, en büyük değere eşit birden fazla eleman varsa hepsinin kazanan olarak yazılabileceğini söyledi ve bunu öğrencilere bıraktı.

Hoca ayrıca, herkesin herkese puan verdiği böyle bir sistemin gerçek hayatta daha adil olup olamayacağını düşünmeye davet etti.

### 8.4 Ağırlıklı oy

Son durumda herkesin oyu eşit değildir: oy, kişinin ödediği ya da ödemesi gereken verginin ne kadarını ödediğine, yaşına, eğitim durumuna, yükümlülüklerini yerine getirip getirmediğine göre ağırlıklandırılır. Hoca, kişilerin bilgilerinden bir skor üreten bir fonksiyon olduğunu ve her kişinin verdiği puanın bu ağırlıkla çarpılacağını söyledi; kodlamayı öğrencilere bıraktı. Slayttaki veri yapısı $N \times 2$'lik bir matristir: ilk sütunda ağırlık, ikinci sütunda oy.

## 9. Sayarak doğrusal sıralama

Dersin sonunda iki alternatif sıralama algoritması anlatıldı. Sözde kod hocanın kullandığı ders notundan gösterildi ve üzerine çizilerek açıklandı (ekrandan, 02:55:00). Sözde kodda diziler 1'den başlar; 0'dan başlatmak da sorun değildir.

### 9.1 Fikir ve algoritma

Düşünce şudur: **benden küçük $k$ tane sayı varsa benim yerim $k+1$'dir.** Örneğin benden küçük 4 sayı varsa ben 5. sırayım.

```text
K yı sıfırla
for i=1:N
    for j=1:N
        if A(i)>A(j)
            K(i)=K(i)+1;
        end
    end
end
for i=1:N
    B(K(i)+1)=A(i);
end
```

### 9.2 Adım adım örnek

$A = 6, 3, 4, 2$. Sıfırlanmış yedek bir `K` dizisi kullanılır.

- $i$ = 6: 6 > 6 değil; 6 > 3 evet (K = 1); 6 > 4 evet (K = 2); 6 > 2 evet (K = 3). 6'dan küçük 3 eleman var.
- $i$ = 3: 3 > 6 değil; 3 > 3 değil; 3 > 4 değil; 3 > 2 evet (K = 1).
- $i$ = 4: 4 > 6 değil; 4 > 3 evet (K = 1); 4 > 4 değil; 4 > 2 evet (K = 2).
- $i$ = 2: hiçbir elemandan büyük değil (K = 0).

Sonuç $K = 3, 1, 2, 0$. İkinci döngüde her eleman, kendisinden küçük eleman sayısının bir fazlası olan yere yazılır: 6 ($K=3$) dördüncü, 3 ($K=1$) ikinci, 4 ($K=2$) üçüncü, 2 ($K=0$) birinci sıraya gider. Böylece $B = 2, 3, 4, 6$ elde edilir.

### 9.3 Karmaşıklık

İç içe iki döngü $n$'er kez döner, bu $n^2$ işlem eder; ikinci döngü $n$ kez döner. Toplam $n^2 + n$'dir ve en yüksek mertebe alınarak $O(n^2)$ denir.

**Soru (hocanın sorusu):** Bu iyi bir sıralama mı? **Cevap (öğrenci):** İşe yarıyor ama $n^2$'de. Bubble sort ve selection sort da $n^2$ olduğu için zaman açısından fark yoktur. Ama yer bakımından fark vardır: bir diziyi sıralamak için üç dizi kullanıldı. **Soru:** Bu ne kadarlık bir bellek karmaşıklığı? **Cevap (öğrenci):** Yaklaşık $2n$ ek bellek. Hoca doğruladı: bellek karmaşıklığı $n$ mertebesindedir; bubble sort'ta böyle bir ek bellek yoktu.

### 9.4 İki kat hızlandırma

6, 3, 4 ve 2 ile karşılaştırıldıktan sonra 3'ü tekrar 6 ile karşılaştırmaya gerek yoktur. Her çift bir kez karşılaştırılırsa iç döngü $N$'ye değil $i$'ye kadar gider. Karşılaştırmanın `else` tarafında, $A(i)$ büyük değilse $A(j)$'nin daha büyük olduğu anlaşılır ve onun sayacı artırılır (ekrandan, 02:55:00 ve 03:00:00):

```text
K yı sıfırla
for i=1:N
    for j=1:i
        if A(i)>A(j)
            K(i)=K(i)+1;
        else
            K(j)=K(j)+1;
        end
    end
end
for i=1:N
    C(K(i))=A(i);
end
```

> **Ek bilgi (derste anlatılmadı):** Bu sürümde $j = i$ durumunda `else` dalı çalışır ve her eleman kendi sayacını bir kez artırır. Bu yüzden `K(i)` doğrudan elemanın 1 tabanlı sıra numarası olur ve yerleştirme `C(K(i)) = A(i)` biçiminde, `+1` olmadan yapılır. $A = 6, 3, 4, 2$ için $K = 4, 2, 3, 1$ ve $C = 2, 3, 4, 6$ bulunur (bu not için Python ile denendi).

İç döngüdeki işlem bir birim sayılırsa iç döngü $i$ birim, toplam

$$\sum_{i=1}^{n} i = \frac{n(n+1)}{2} \approx \frac{n^2}{2}$$

birim eder. Böylece işlem sayısı $n^2$'den yaklaşık $n^2/2$'ye iner ve aynı sonuç alınır. Ama karmaşıklık hâlâ $O(n^2)$'dir, çünkü $n^2$'den kurtulamadık.

## 10. Counting sort

### 10.1 Algoritma

Daha da iyileştirmek için **counting sort** kullanılır (ekrandan, 03:00:00):

```text
T, A'nın en büyük elemanı
K yı sıfırla 1:T
for i=1:N
    K(A(i))=1;
end
j=1;
for i=1:T
    if K(i) ≠ 0
        B(j)=i;
        j=j+1;
    end
end
```

Bu kez `K` dizisinin boyutu $N$ değil, dizinin en büyük elemanı $T$'dir. `K` önce sıfırlanır; sonra dizideki her değerin indisine 1 yazılır, yani değerler 0/1 olarak kodlanır. Sonra `K` baştan sona gezilir; 1 ile karşılaşılan her indis, yeni `B` dizisine sırayla yazılır.

### 10.2 Örnek

$A = 6, 2, 4, 8$ için $T = 8$'dir. `K`'da 2, 4, 6 ve 8. indisler 1, geri kalan her şey 0 olur. `K` gezilirken 0'lar atlanır; 2. indiste 1 görülür ve `B`'nin ilk elemanı 2 olur, sonra 4, 6 ve 8 gelir: $B = 2, 4, 6, 8$ (ekrandan, 03:05:00). `B` dizisi $N$ elemanlıdır; aslında `B`'ye gerek de yoktur, sonuç doğrudan `A`'nın üzerine yazılabilir.

### 10.3 Karmaşıklık

İlk döngü $N$ kez, ikinci döngü $T$ kez döner; en büyük elemanı bulmak da $N$ adımdır. Hangisi büyükse o belirleyicidir: $O(\max(T, N))$ (ekrandan, 03:05:00). $T$ ile $N$ yakınsa bu yaklaşık $n$'dir. Hoca, sıralamada şimdiye kadar $O(n)$'lik bir algoritma görülmediğini, pratikte de pek olmadığını, bunun çok hızlı bir algoritma olduğunu söyledi. Ders notundaki ifadeyle: "Karmaşıklık O(T), ama yerden kaybettik. Bir de?"

### 10.4 Sorunlar

**Soru (hocanın sorusu):** Bu algoritmanın sorunları neler olabilir?

**Cevap (öğrenci):** Aynı değerdeki elemanlar sıralanamıyor; örneğin iki tane 2 olsaydı. Hoca doğruladı: 0/1 kodlamasıyla bu haliyle algoritma çözümsüzdür. Çözüm, `K(A(i)) = 1` yerine `K(A(i))++` ile **frekans** tutmaktır; örneğin $A = 6, 2, 4, 8, 2$ için `K[2] = 2` olur ve yeni dizi kurulurken 2 iki kez yazılır. Bu, histogram tutmanın aynısıdır ve fazla ek kod gerektirmez.

Asıl sorun ise **içerik (değer aralığı) problemidir**. Dizide `INT_MAX`'ın 5 eksiği gibi yaklaşık 2 milyarlık bir sayı olsa `K` dizisi 2 milyar elemana kadar uzar. Bu dizi seyrektir (sparse): içinde neredeyse hep sıfır vardır ve yalnızca tek bir büyük sayının hatırına bellekte çok büyük bir yer açılmış olur. Böyle bir bellek ayırmaya işletim sistemi izin vermeyebilir; özellikle gömülü sistemlerde bu olmaz. Değerler 1-100 ya da 1-1000 gibi küçük bir aralıktaysa sorun yoktur: fonksiyon içinde açılan ek dizi fonksiyon bitince yok edilir ve sıralama çok hızlı yapılır.

> **Hocanın vurgusu:** Zaman performansı iyidir ama bellekten çok kayıp vardır, özellikle büyük sayılarda. Tekrarlı durumlarda da 0/1 kodlaması yerine histogram gibi frekans tutulmalıdır.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:26:52): `c = {'a','b','c','d'}` iken aşağıdaki kod ne yazdırır? `buyukHarfeCevir` içinde `c[i] -= 32` yapılmaktadır.

```c
diziYazdir(c,MAX);
buyukHarfeCevir(c,MAX);
diziYazdir(c,MAX);
```

> **Çözüm (derste verildi):** İlk satır `a b c d`, ikinci satır `A B C D` yazar. Dizi fonksiyona adresiyle gittiği için fonksiyondaki değişiklik asıl diziye yansır; fonksiyonun `void` olması bunu etkilemez.

**Soru 2** (ekrandan, 00:40:00): `int* myfunc(int p, int x)` yerel `temp = p + 2*x` değişkeninin adresini döndürüyor. Büyük harfe çevirmeden sonra `ptr = myfunc(c[2],2); printf("%d", *ptr);` ne yazdırır? Arada başka fonksiyonlar çağrılırsa ne olur?

> **Çözüm (derste verildi):** `c[2]` = `'C'` = 67, $67 + 2\cdot 2 = 71$. Hemen ardından yazdırılınca 71 görüldü, çünkü o yığın bölgesinin üstüne henüz yazılmamıştı. Araya iki fonksiyon çağrısı girince aynı adreste çöp değer (derste 4) görüldü. Yerel değişkenin ömrü fonksiyonla biter; bu kullanım yanlıştır ve derleyici `-Wreturn-local-addr` uyarısı verir.

**Soru 3** (derste sözlü, 00:55:46): Bir dizinin en büyük ve en küçük elemanlarının yerini tek fonksiyonla döndürün.

> **Çözüm (derste verildi):** Bölüm 4.2'deki `bul(char c[], int N, int *max, int *min)` fonksiyonu. `ABCD` için `max=3`, `min=0`.

**Soru 4** (derste sözlü, 01:23:29): Bir dizinin sıralı olup olmadığını denetleyen bir fonksiyon yazın.

> **Çözüm (derste verildi):** Bölüm 5.3'teki `kontrol` fonksiyonu; ardışık çiftler `d[i] < d[i+1]` ile karşılaştırılır, döngü `n-1`'e ulaşırsa dizi sıralıdır. `1 2 3 4 7 8 9` için `SIRALI` döner.

**Soru 5** (derste sözlü, 01:32:08): Bir dizi yalnızca 1 ve 2'lerden oluşuyor. Kaç tane 1, kaç tane 2 var?

> **Çözüm (derste verildi):** Bölüm 6.1'deki `say(int d[], int n, int *c1, int *c2)`; `1 2 1 2 1` için 3 ve 2. Değer çeşidi artarsa genel çözüm histogramdır (Bölüm 7).

**Soru 6** (ekrandan, 02:55:00): En çok oyu alan partiyi bulun ($N$ seçmen, $N$ elemanlı bir dizi).

> **Çözüm (derste verildi):** Oyların histogramı çıkarılır (`histogram[oylar[i]]++`), histogramın en büyük elemanının indisi kazanan partidir (`enBuyukBul`). Tam program Bölüm 8.1'de.

**Soru 7** (ekrandan, 02:55:00): Herkes 1 değil 3 partiye oy veriyor ($N \times 3$'lük matris). Kazanan kim?

> **Çözüm (derste verildi):** Matris iç içe döngülerle gezilir ve `histogram[oylar[i][j]]++` yapılır; sonra en büyük eleman bulunur (Bölüm 8.2).

**Soru 8** (ekrandan, 02:55:00): Herkes her partiye 1-10 arası puan veriyor ($P$ parti, $N \times P$'lik matris). Kazanan kim?

> **Çözüm (derste verildi):** Her partinin sütunu toplanır: `histogram[j] += oylar[i][j]`; en büyük toplamın indisi kazanandır. Ekrandaki örnekte toplamlar 33, 22, 31, 27, 22; kazanan 0. parti (Bölüm 8.3).

**Soru 9** (derste sözlü, 02:45:50): Birden fazla parti aynı en yüksek puanı alırsa hepsini kazanan olarak yazdırın.

> **Çözüm (derste verilmedi):** Hocanın tarif ettiği yol: önce en büyük değer bulunur, sonra dizi yeniden gezilip bu değere eşit bütün indisler yazılır. Aşağıdaki fonksiyon bu not için derlenip `{2,7,1,7,3}` dizisiyle denendi; çıktı `En yuksek deger: 7, kazanan(lar): 1 3` oldu.

```c
void kazananlariYaz(int h[], int n){
    int i, max=0;
    for(i=1;i<n;i++)
        if(h[i]>h[max])
            max=i;
    printf("En yuksek deger: %d, kazanan(lar):", h[max]);
    for(i=0;i<n;i++)
        if(h[i]==h[max])
            printf(" %d", i);
    printf("\n");
}
```

**Soru 10** (ekrandan, 02:55:00): Herkesin oyu eşit değil; oylar vergi, yaş, eğitim vb. ile ağırlıklandırılmış ($N \times 2$'lik matris, ilk sütunda ağırlık, ikinci sütunda oy). Kazanan kim?

> **Çözüm (derste verilmedi):** Her kişinin oyu ağırlığı kadar sayılır: `histogram[oylar[i][1]] += oylar[i][0];`, ardından `enBuyukBul`. Bu satır bu not için derlenip denendi: `{{3,0},{1,2},{2,2},{1,1}}` (ağırlık, parti) için toplamlar 3, 1, 3 çıktı. Ağırlığın tam sayı olduğu varsayılmıştır.

```c
void agirlikliSay(int oylar[][2], int n, int histogram[]){
    int i;
    for(i=0;i<n;i++)
        histogram[oylar[i][1]] += oylar[i][0];
}
```

**Soru 11** (ekrandan, 02:55:00): "Benden küçük $k$ sayı varsa benim yerim $k+1$'dir" fikriyle $A = 6, 3, 4, 2$ dizisini sıralayın. Zaman ve ek bellek karmaşıklığı nedir?

> **Çözüm (derste verildi):** $K = 3, 1, 2, 0$, $B = 2, 3, 4, 6$. Zaman $n^2 + n \approx n^2$, ek bellek $2n$ (Bölüm 9).

**Soru 12** (ekrandan, 03:00:00): Counting sort ile $A = 6, 2, 4, 8$ dizisini sıralayın. Karmaşıklığı nedir ve algoritmanın sorunları nelerdir?

> **Çözüm (derste verildi):** $T = 8$, `K`'da 2, 4, 6, 8. indisler 1; $B = 2, 4, 6, 8$. Karmaşıklık $O(\max(T, N))$. Sorunlar: tekrarlı değerler (frekans tutularak çözülür) ve çok büyük değerlerde `K` dizisinin bellek gereksinimi (Bölüm 10).

## Dersin Toparlaması

Bu derste fonksiyon konusu dizi ve pointer'larla birleştirildi. Dizinin fonksiyona yalnızca adresiyle gittiği, bu yüzden fonksiyondaki değişikliğin asıl diziye yansıdığı görüldü. Fonksiyondan dizi döndürülemediği, yerel bir değişkenin adresini döndürmenin ise çalışır görünen ama yanlış sonuç veren bir hata olduğu, yığın üzerinden gösterildi. Birden fazla sonuç gerektiğinde `return` yerine pointer parametreler kullanıldı. Önceki derslerin birleştirme ve sıralılık denetimi algoritmaları tek görevli fonksiyonlara bölündü.

Ardından sayma problemleri üzerinden genellik kavramı tartışıldı: her değer için ayrı sayaç tutmak yerine histogram dizisiyle tek satırda sayılabileceği, bunun bedelinin bellek olduğu gösterildi. Histogram fikri seçim sistemlerine uygulandı; tek oy, üç oy ve puanlı oy durumları için uygun veri yapısı (dizi ya da matris) seçildi ve fonksiyona matris gönderme kuralı öğrenildi. Son olarak sayarak doğrusal sıralama ve counting sort ile zaman ve bellek arasındaki ödünleşim bir kez daha görüldü: counting sort zamanı doğrusala yakın tutar, ama değer aralığı büyüdükçe bellek bedeli kabul edilemez hale gelir. Algoritma analiziyle ilgili örnekler sonraki derste sürdürülecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
