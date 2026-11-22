# Ders 19 Genişletilmiş Notu: Özyinelemeli (Recursive) Fonksiyonlar: Beş Uygulama Örneği

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Özyinelemeli Fonksiyonlar: Tanım ve Yapı
- 2. Çalışma Mantığı: fonk Örneği
- 3. Özyinelemeli Fonksiyon Tasarlamak
- 4. Örnek 1: String Uzunluğu
- 5. Örnek 2: Bir Sayının Basamak Sayısı
- 6. Örnek 3: 1'den n'ye Kadar Toplam
- 7. Örnek 4: EBOB
- 8. Örnek 5: String'i Ters Yazdırmak
- 9. İşaretçi Üzerine Sorular
- Örnek Sorular
- Dersin Toparlaması

## 1. Özyinelemeli Fonksiyonlar: Tanım ve Yapı

Bu oturum laboratuvar değil, uygulama dersidir. Konu teorik derste henüz anlatılmadığı için önce kısa bir özet verildi, sonra hazırlanan beş örnek birlikte C ile yazıldı, derlendi ve denendi. Kod bir metin düzenleyicide yazıldı, terminalde `gcc` ile derlendi ve `./a.out` ile çalıştırıldı (ekrandan, 00:35:00).

Özyinelemeli (recursive) fonksiyon, kendi kendini çağıran fonksiyondur. Genellikle küçük parçalara bölünebilen problemleri çözen algoritmalarda kullanılır. Algoritmalar dersinde görülecek böl ve fethet (divide and conquer) yaklaşımı bu fikre dayanır.

Özyinelemeli bir fonksiyon iki bölümden oluşur:

- **Base case (temel durum):** Problemin bölünmesinin nerede duracağını söyler. Problem bölünür, bölünür, bölünür; base case'e gelince durulur. C'de bu genellikle bir `if` koşuluyla yazılır.
- **Recursive part (özyinelemeli kısım):** Problemin bölündüğü, yani parametrenin değiştiği kısımdır. Fonksiyon kendini her seferinde aynı kurala göre değişmiş bir parametreyle çağırır; örneğin parametre bir azalır ya da ikiye bölünür.

## 2. Çalışma Mantığı: fonk Örneği

Slaytta şu örnek vardı (ekrandan, 00:10:00):

```c
int fonk(int n)
{
  if n==1
    return 1;
  else
    return 1+fonk(n);
}
int main()
{
  int n=3;
  printf(%d,fonk(n));
  return 0;
}
```

Slayttaki kod sözde koda yakındır (`if` koşulunda parantez, `printf` içinde tırnak yoktur). Anlatım sırasında `return 1+fonk(n);` satırının yanlış yazıldığı, doğrusunun `return 1+fonk(n-1);` olduğu söylendi. Fonksiyon, kaç kez çağrıldığını sayar: `fonk(3)` için 3 döndürmesi beklenir.

Çalışma adım adım şöyledir (slayttaki çağrı şemasına göre):

1. `main`, `fonk(3)`'ü bir kez çağırır.
2. `fonk(3)` içinde $n \neq 1$ olduğu için `else` kolu çalışır ve `fonk(2)` çağrılır.
3. `fonk(2)` içinde de $n \neq 1$ olduğundan `fonk(1)` çağrılır.
4. `fonk(1)` içinde $n = 1$ olduğu için base case çalışır ve 1 döner.
5. Bir fonksiyon değerini kendisini çağırdığı yere döndürür. `fonk(1)`'i `fonk(2)` çağırmıştı; `fonk(2)` gelen 1'i kendi 1'iyle toplar ve $1+1=2$ döndürür.
6. `fonk(2)`'yi `fonk(3)` çağırmıştı; `fonk(3)` $1+2=3$ döndürür.
7. `fonk(3)`'ü `main` çağırmıştı; `main` 3'ü yazdırır.

Döngü olmadığı için özyinelemeli fonksiyonlar "ucuza geliyormuş gibi" görünür. Ancak her çağrının yerel değişkenleri yığına (stack) konur. Çağrı sayısı arttıkça bu bir süre sonra yığının dolmasına yol açabilir. Bu eksi yön algoritmalar ve veri yapıları derslerinde daha ayrıntılı görülecektir.

> **Ek bilgi (derste anlatılmadı):** Yığının dolmasına "stack overflow" denir. Base case'i hiç gerçekleşmeyen bir özyineleme (örneğin slayttaki hatalı `1+fonk(n)` satırı) sonsuza kadar kendini çağırır ve program büyük olasılıkla bu hatayla çöker.

## 3. Özyinelemeli Fonksiyon Tasarlamak

Doğru bir özyinelemeli fonksiyon yazmak için iki karar verilir:

- **Base case nedir?** Fonksiyonu çağırmayı nerede durduracağımız çok iyi planlanmalıdır. Bu, doğru bir özyinelemeli fonksiyonun temelidir.
- **Yeni parametre ile önceki parametre arasındaki bağıntı nedir?** Yani problem nasıl bölünecek: ikiye mi bölünecek, ona mı bölünecek, bir mi azaltılacak?

> **Hocanın vurgusu:** Base case'i doğru bulmak, doğru bir özyinelemeli fonksiyon yazmanın temelidir. İkinci önemli tasarım kararı problemin nasıl bölüneceğidir.

Derste yazılan beş örnek tek bir slaytta listelenmişti (ekrandan, 00:15:00): string uzunluğu, basamak sayısı, 1'den $n$'ye toplam, EBOB ve string'in tersi. Hepsinin "özyineleme metoduyla" ve C dilinde gerçeklenmesi istenir.

## 4. Örnek 1: String Uzunluğu

### 4.1 Problem ve main fonksiyonu

Verilen bir string'in uzunluğu özyinelemeli bir fonksiyonla hesaplanacaktır. Normalde string bir dizide tutulur ve bir döngüyle sonuna kadar sayılır; burada döngü kullanılmayacaktır.

Önce `stdio.h` eklenir ve `main` yazılır. En fazla 50 karakterlik bir string için `char str[50];` tanımlanır. Bu biçimde yer ayrıldığında başlangıç değeri vermeye gerek yoktur; derleyici işletim sisteminden 50 karakterlik yer ister. Uzunluğu tutmak için `int len;` tanımlanır. Kullanıcıya `Enter Your String` yazdırılır, sonra string `scanf("%s",str);` ile okunur. Alternatif olarak `gets(str);` da kullanılabileceği söylendi; kodda bu satır yorum olarak bırakıldı (ekrandan, 00:20:00).

`main` `int` tanımlandığı için bir değer döndürmesi beklenir; `void` olmayan her fonksiyonun başına döndüreceği değerin veri tipi yazılır. `main`'in 0 döndürmesi programın sorunsuz bittiği anlamına gelir.

> **Ders sonrası not:** Derste `scanf("%s", str)` ile `gets(str)` arasında fark olmadığı söylendi. Aslında `scanf("%s", ...)` ilk boşlukta durur, `gets` bütün satırı okur. `gets` taşma denetimi yapmadığı için güvensizdir ve C11 standardında dilden kaldırılmıştır.

### 4.2 Bildirim, gerçekleme ve imza

Fonksiyon önce `main`'den önce bildirilir (declaration), gövdesi `main`'den sonra yazılır (implementation). Bunun yararı şudur: gerçekleme henüz yapılmamış olsa bile hangi fonksiyonların kullanılacağı ve onlara hangi parametrelerin gönderileceği önceden bellidir. Önce tasarlanır, sonra gerçeklemeye geçilir. Bildirim satırına fonksiyonun imzası (signature) denir; imza gerçeklemedekiyle birebir aynı olmalıdır.

Fonksiyonun adı C'nin kendi `strlen` fonksiyonuyla karışmamalıdır; bu yüzden `strLen` adı seçildi. Kendi yazdığınız fonksiyonlara kütüphane fonksiyonlarının adlarını vermeyin, derleyiciler bunda sorun çıkarır.

Parametre bir string'dir, yani bir karakter dizisi. Parametre `char *str` biçiminde yazıldı (ekrandan, 00:20:00).

> **Ek bilgi (derste anlatılmadı):** Fonksiyon parametresinde `char *str` ile `char str[]` yazımları aynı anlama gelir; her ikisinde de fonksiyona dizinin ilk elemanının adresi geçer.

### 4.3 Base case

Base case için öğrencilere "nerede durmalıyız?" diye soruldu. Sohbetten gelen cevaplar "sonuna ulaştığında" ve "null olduğunda" idi. Doğru cevap null karakteridir. 50'ye kadar saymak doğru değildir, çünkü 50'lik yer ayrılmış olsa da string o kadar uzun olmayabilir; string'in bittiği yere kadar sayılmalıdır. String'in sonunda `'\0'` (null) karakteri vardır. Gösterilen karakter buna eşit olmadığı sürece string'de hâlâ bir eleman var demektir:

```c
if(*str!='\0')
```

Base case'e ulaşıldığında string boştur; içinde hiçbir şey yoktur, bu yüzden 0 döner.

### 4.4 Özyinelemeli kısım

Anlatım için 12 karakterlik bir ad örnek olarak yorum satırına yazıldı ve her çağrıda string'in nasıl kısaldığı gösterildi: birinci çağrı string'in tamamını, ikinci çağrı ilk harfi atılmış hâlini, üçüncü çağrı ilk iki harfi atılmış hâlini görür; 13. çağrıda (yorumda "(12)" diye gösterildi) elde yalnız `'\0'` kalır (ekrandan, 00:30:00).

String bir karakter dizisidir ve fonksiyona gönderilen işaretçi dizinin birinci elemanının adresidir. İşaretçi aritmetiğinde bir sonraki adrese işaretçiyi bir artırarak gidilir (`++str`). İşaretçi bir artırıldığında artık ikinci harfi gösterir. Geçilen karakter de sayılması gerektiği için sonuca 1 eklenir. Bu, `fonk` örneğindeki `1+fonk(n-1)` ile aynı mantıktır: bir sonrakine geçildiği için dönüş değeri 1 artırılır.

Dönüş değeri şöyle düşünülür: "Beni çağıran fonksiyon benden bir tamsayı bekliyor. Ben kendimi daha kısa bir string ile çağırıyorum. Bana dönecek değere kendi uzunluğumu, yani 1'i ekleyip beni çağırana gönderiyorum." Kısalan string'ler kendi uzunluklarını hesaplayıp geri gönderir, her çağrı bir ekler, sonunda değer `main`'e ulaşır. En son çağrı base case'e ulaştığında boş string için 0 döndürür.

`if`'in `else` kolunun yazılmasına gerek yoktur: `*str1` `'\0'` değilse `if`'in içindeki `return` çalışır; değilse akış aşağıdaki `return 0;` satırına iner.

### 4.5 Değişken adları ve atama

Parametrenin adı `str`'den `str1`'e çevrildi. Farklı fonksiyonlarda aynı parametre ve yerel değişken adlarını kullanmak doğru değildir. 20-22 satırlık bir kodda sorun olmaz, ama onlarca uzun fonksiyonu olan bir programda, özellikle işaretçiler de işe girince işler karışabilir.

`len=strLen(str);` atamasının yapılabilmesinin nedeni, fonksiyonun `int` döndürmesi ve `len`'in de `int` olmasıdır; sol ve sağ tarafın veri tipleri uyumludur. Bu işleme günlük dilde "eşitleme" denir, doğru terim atamadır (assign).

Sonuç `printf("Lenght of your string is: %d\n",len);` ile yazdırılır; uzunluk en fazla 50 olduğu için `%d` yeterlidir.

### 4.6 Derleme, hata ve sonuç

İlk derlemede `implicit declaration of function 'srtLen'` uyarısı ve `undefined reference to 'srtLen'` bağlayıcı hatası alındı; çağrıda ad `srtLen` diye yanlış yazılmıştı. Düzeltildikten sonra program çalıştı ve 12 karakterlik girdi için `Lenght of your string is: 12` yazdı (ekrandan, 00:35:00). Kodun son hâli (ekrandan, 00:35:00):

```c
#include<stdio.h>

int strLen(char *str1);

int main()
{
    char str[50];
    int len;
    printf("Enter Your String\n");
    scanf("%s",str);
    //gets(str);
    len=strLen(str);

    printf("Lenght of your string is: %d\n",len);

    return 0;
}

int strLen(char *str1)
{
    if(*str1!='\0')
        return 1+strLen(++str1);
    return 0;
}
```

Bu kod `gcc -Wall` ile uyarısız derlendi; 12 karakterlik bir girdiyle 12 sonucu alındı.

### 4.7 Örnek 1 üzerine sorular

**Soru:** `scanf` içinde `str`'nin önüne neden adres işareti (`&`) yazmıyoruz? **Cevap:** String'ler karakter dizileridir. `str` tek başına kullanıldığında zaten dizinin adresini ifade eder. Önüne `&` konursa işaretçinin işaretçisi olur; bu da iki boyutlu dizileri ifade eder.

> **Ders sonrası not:** `&str` iki boyutlu dizi ya da "işaretçinin işaretçisi" değildir; 50 elemanlı dizinin tamamını gösteren bir işaretçidir (`char (*)[50]`). Adres değeri `str` ile aynıdır, türü farklıdır. `scanf("%s", ...)` `char *` beklediği için `str` yazmak doğrudur.

**Soru:** Return kısmı tekrar anlatılabilir mi? **Cevap:** Yukarıda 4.4'teki açıklama tekrarlandı: her çağrı daha küçük string için kendini çağırır, gelen değere kendi 1'ini ekleyip çağırana gönderir; son çağrı boş string için 0 döndürür.

**Soru:** Parametreyi neden işaretçi olarak (`char *str1`) yazdık? Dizilerde işaretçiye gerek yok diye hatırlıyorum. **Cevap:** Fonksiyon parametrenin bir dizi olduğunu başka türlü bilemez; yazılmazsa tek bir karakter sanır.

## 5. Örnek 2: Bir Sayının Basamak Sayısı

Verilen bir sayının basamak sayısı bulunacaktır. Problem bir öncekine çok benzer: orada karakterler sayılıyordu, burada basamaklar sayılır. Tek fark problemin bölünme biçimidir; yeni parametre bir azaltılarak ya da bir sonraki karaktere geçilerek değil, farklı bir yolla hesaplanır.

> **Hocanın vurgusu:** Benzer bir kodu kopyalayıp yapıştırmak yerine yeniden yazın. Kopyala-yapıştır programlama önceki koddaki hatayı tekrarlatır ve ileriye yayar; yeniden yazarken hatayı bir noktada bırakıp doğrusuna ulaşırsınız.

`main` içinde `int number,digit;` tanımlanır, `Enter Your Number` yazdırılır ve sayı `scanf` ile okunur. Fonksiyon `int countDigits(int number1);` olarak bildirilir (ekrandan, 00:45:00). Ekranda ilk yazılan `scanf("%d",number);` satırında `&` eksikti; sonra burada adres verilmesi gerektiği, string'de ise string zaten bir adres olduğu için verilmediği hatırlatıldı.

Base case: sayı 0'dan büyükse hâlâ basamak vardır; 0'dan büyük değilse 0 döner (basamak yok). Özyinelemeli kısımda sayı tam sayı bölmesiyle 10'a bölünür, böylece son basamak atılır; çağrılan fonksiyonun döndürdüğü basamak sayısına kendi basamağı (1) eklenir. Anlatımda $239$ örneği yorum olarak yazıldı: $239 \to 23 \to 2 \to 0$. Üçüncü çağrıda 0 elde edilir ve base case'e ulaşılır (ekrandan, 00:50:00).

Bu yorum satırı başına `//` konmadan yazıldığı için ilk derleme `expected identifier or '(' before numeric constant` hatası verdi; düzeltilince program `1234567` girdisi için `7 Digits In Your Number` yazdı (ekrandan, 00:50:00).

**Soru:** Bölme işlemi tam bölme mi? **Cevap:** Evet; `int` ile `/` işareti tam sayı bölmesi (integer division) yapar.

Kodun son hâli karelerde bütünüyle görünmüyor; aşağıdaki kod ekranda görülen parçalardan (bildirim, `main`, `if(number1>0)`) ve anlatımdan kuruldu:

```c
#include<stdio.h>

int countDigits(int number1);

int main()
{
    int number,digit;

    printf("Enter Your Number \n");
    scanf("%d",&number);

    digit=countDigits(number);
    printf("%d Digits In Your Number\n",digit);

    return 0;
}

int countDigits(int number1)
{
    if(number1>0)
        return 1+countDigits(number1/10);
    return 0;
}
```

<!-- BELİRSİZ: countDigits gövdesinin son hâli ve main'deki printf satırı karelerde tam görünmüyor; kod anlatıma ve terminal çıktısına göre kuruldu. -->

Bu kod `gcc -Wall` ile uyarısız derlendi; `1234567` girdisi için `7 Digits In Your Number` çıktısı alındı.

> **Ders sonrası not:** Bu fonksiyon 0 için 0 basamak döndürür ve negatif sayılarda da 0 verir. 0'ın bir basamağı vardır; derste yalnız pozitif girdiyle denendi.

## 6. Örnek 3: 1'den n'ye Kadar Toplam

### 6.1 Önce main'i tasarlamak

1'den $n$'ye kadar olan sayıların toplamı bulunacaktır. Kapalı bir formülle hesaplanabileceği söylendi, ama özyinelemeyle yapılacaktır.

> **Ders sonrası not:** Derste formül "$n \cdot (n-1)/2$" diye söylendi; doğrusu $\dfrac{n(n+1)}{2}$'dir. Örneğin $n=5$ için $5 \cdot 6/2 = 15$, derste programın verdiği sonuçla aynıdır.

`main` içinde `int n,sum;` tanımlanır, `Enter n` yazdırılır, `scanf("%d",&n);` ile $n$ okunur, `sum=sumOfNumber(n);` ile toplam hesaplanır ve `printf("Sum of NUmber from 1 to n=%d \n",sum);` ile yazdırılır (ekrandan, 00:55:00).

Burada vurgulanan nokta şudur: hiç gerçekleme yapmadan önce `main` bu biçimde tasarlanabilir, sonra gerçeklemeye geçilir. Modülerliğin önemi buradan gelir; çok fonksiyonlu bir programda bazı fonksiyonlar sonraya bırakılabilir ve sonradan eklenebilir. Bildirim yerine gövdesi boş bir fonksiyon yazmak da mümkündür, ama bu pek şık görünmez.

> **Ek bilgi (derste anlatılmadı):** Derste, gerçeklemesi yazılmamış ama bildirilmiş bir fonksiyonu çağıran programın hata vermeyeceği söylendi. Bu yalnız derleme aşaması için doğrudur; bağlama (link) aşamasında gövde bulunamazsa `undefined reference` hatası alınır. Örnek 1'deki `srtLen` hatası da bu türdendi.

### 6.2 Base case ve özyineleme

Parametre olarak "1'den kaça kadar" toplanacağı gönderilir. 1'den 1'e kadar olan toplam yalnız 1'dir; bu base case olur ve 1 döner.

$n = 3$ için çağrılar şöyle ilerler (ekrandaki yorumdan, 01:00:00):

```text
n=3  ->  n=2  ->  n=1
3+(1+2)   (1)+2    1
```

1. `sumOfNumber(3)` çağrılır, `sumOfNumber(2)`'yi çağırır.
2. `sumOfNumber(2)`, `sumOfNumber(1)`'i çağırır.
3. `sumOfNumber(1)` base case'tir ve 1 döndürür.
4. `sumOfNumber(2)` kendi sayısını gelen değere ekler: $1+2=3$ döndürür.
5. `sumOfNumber(3)` kendi sayısını ekler: $3+3=6$ döndürür; değer `main`'e gider.

Fikir şudur: "Biri bana $n-1$'e kadar olan toplamı verirse, ben de $n$'yi buna ekler ve döndürürüm." Yine `else` yazmaya gerek yoktur; `if`'in içine yalnız $n$ 1 iken girilir, diğer durumlarda akış aşağıdan devam eder.

İlk derlemede gövdede `n` yazıldığı için `'n' undeclared` hatası alındı; `n1` yapılınca düzeldi. Program $n=5$ için 15, $n=3$ için 6 yazdı (ekrandan, 01:00:00). Kodun son hâli (ekrandan, 00:55:00 ve 01:00:00):

```c
#include<stdio.h>

int sumOfNumber(int n1);

int main()
{
    int n,sum;

    printf("Enter n\n");
    scanf("%d",&n);

    sum=sumOfNumber(n);

    printf("Sum of NUmber from 1 to n=%d \n",sum);

    return 0;
}

int sumOfNumber(int n1)
{
    if (n1==1)
        return 1;
    return n1+sumOfNumber(n1-1);
}
```

Bu kod `gcc -Wall` ile uyarısız derlendi; 5 ve 3 girdileri için 15 ve 6 sonuçları alındı.

**Soru:** Fonksiyonu neden iki kez (yukarıda ve aşağıda) yazıyoruz? Neden doğrudan yukarıya yazmıyoruz? **Cevap:** Yukarıdaki satır bildirimdir, aşağıdaki gerçeklemedir. Bu modülerlik alışkanlığı yazılım mühendisliğinde ayrıntılı görülecektir ve şimdiden kolaylık sağlar. Bildirim yapmadan doğrudan gerçekleme yazmak da yanlış değildir.

## 7. Örnek 4: EBOB

### 7.1 Algoritma

İki sayının en büyük ortak böleni (EBOB, GCD) Öklid'in algoritmasıyla özyinelemeli olarak bulunacaktır. İlk anlatımda kalanlı (mod) biçimden söz edildi, ardından derste çıkarmaya dayalı biçim kullanıldı:

- İki sayı birbirine eşitse EBOB sayının kendisidir. Bu base case'tir.
- Eşit değillerse büyük olandan küçük olan çıkarılır ve fonksiyon yeni ikiliyle yeniden çağrılır. Biri diğerine tam bölünüyorsa çıkarmalar sonunda iki sayı eşitlenir.

> **Ek bilgi (derste anlatılmadı):** Öklid algoritmasının kalanlı biçimi $\mathrm{EBOB}(a,b) = \mathrm{EBOB}(b, a \bmod b)$, $\mathrm{EBOB}(a,0)=a$ kuralıdır. Çıkarmalı biçim aynı sonucu verir, çünkü tekrarlı çıkarma kalanı hesaplamanın yavaş bir yoludur.

### 7.2 Kod

`main` içinde iki sayı `scanf("%d%d",&n1,&n2);` ile okunur. Kullanıcıdan önce büyük sayıyı vermesi istenebilirdi, ama fonksiyon her iki sırayı da işler. Fonksiyon `int EBOB(int n_1,int n_2)` olarak bildirildi (ekrandan, 01:10:00). Fonksiyon gövdesinde:

- `while(n_1!=n_2)` koşulunun içine yalnız sayılar eşit değilken girilir.
- İçeride geriye iki seçenek kalır: ya birinci büyüktür ya ikinci. Bu yüzden `if`/`else` yeterlidir.
- Birinci büyükse `EBOB(n_1-n_2,n_2)`, değilse `EBOB(n_1,n_2-n_1)` döndürülür.
- Sayılar eşit olduğunda `return n_1;` çalışır.

Sonuç `printf` ile `GCD=` biçiminde yazdırıldı. Kodun son hâli (ekrandan, 01:10:00; `main`'deki çağrı ve `printf` anlatımdan ve terminal çıktısından):

```c
#include<stdio.h>

int EBOB(int n_1,int n_2);

int main()
{
    int n1,n2,ebob;

    printf("Enter Your Numbers\n");
    scanf("%d%d",&n1,&n2);

    ebob=EBOB(n1,n2);
    printf("GCD=%d\n",ebob);

    return 0;
}

int EBOB(int n_1,int n_2)
{
    while(n_1!=n_2)
    {
        if(n_1>n_2)
            return EBOB(n_1-n_2,n_2);
        else
            return EBOB(n_1,n_2-n_1);
    }
    return n_1;
}
```

Döngü gövdesi her durumda bir `return` ile bittiği için bu `while` aslında bir kez çalışır ve bir `if` gibi davranır; tekrarı döngü değil, özyineleme sağlar.

### 7.3 Denemeler

Program önce birbirine tam bölünen sayılarla, sonra küçük sayı önce girilerek, sonra tam bölünmeyen sayılarla ve son olarak EBOB'u 1 olan sayılarla denendi (ekrandan, 01:15:00):

| Girdi | Çıktı |
|---|---|
| 12, 3 | GCD=3 |
| 3, 12 | GCD=3 |
| 45, 15 | GCD=15 |
| 36, 45 | GCD=9 |
| 17, 3 | GCD=1 |

Bütün sonuçlar python `math.gcd` ile doğrulandı; kod `gcc -Wall` ile uyarısız derlendi ve aynı girdilerle aynı çıktıları verdi. Örneğin $(36, 45)$ için adımlar şöyledir (ara adım eklendi): $(36,45) \to (36,9) \to (27,9) \to (18,9) \to (9,9)$, sonuç 9. $(17, 3)$ için çıkara çıkara 1'e ulaşılır.

## 8. Örnek 5: String'i Ters Yazdırmak

### 8.1 İlk tasarım: string döndüren fonksiyon

İlk tasarımda girilen string'in üzerine yazılmaması için ikinci bir dizi (`reversed[50]`) tanımlandı ve fonksiyon `char* reverseStr(char* str1);` olarak bildirildi: parametre olarak bir karakter dizisi alıp ters çevrilmiş string'i döndürecekti. `main`'de sonuç `printf("Reversed String: %s\n",reversed);` ile yazdırılacaktı (ekrandan, 01:20:00).

### 8.2 Soru: string işlemlerinde hep işaretçi mi kullanılır?

**Soru:** İşaretçileri tam görmedik; string işlemleri yaparken her zaman işaretçi mi kullanmamız gerekiyor? **Cevap:** String bir karakter dizisidir ve bir diziyi ifade etmenin yolu onun adresidir. Dizi bellekte Word'deki tek satırlı bir tablo gibi, kutu kutu ardışık durur. Birinci kutunun adresi bilinirse dizinin bütün elemanlarına ulaşılabilir. Bir dizi için yer ayrıldığında işletim sisteminin döndürdüğü şey dizinin birinci elemanının adresidir; bu bir adres olduğu için aslında bir işaretçidir. İşaretçinin kendisi adresi verir; içindeki değere ulaşmak için önüne `*` konur. Ekrana bu yüzden `*ptr = value of ptr` yazıldı (ekrandan, 01:20:00). Örneğin değeri 4 olan bir tamsayının adresi `ptr`'de tutuluyorsa, `ptr` adresi, `*ptr` 4'ü verir.

### 8.3 İkinci tasarım: void fonksiyon

Döndürülen string'li çözümün kafa karıştırıcı olduğu düşünülerek tasarım değiştirildi: fonksiyon bir şey döndürmesin, verilen string'i kendi içinde yazdırsın. Fonksiyon `void reverseStr(char* str1);` olarak bildirildi ve `main`'de `reverseStr(str);` ile çağrıldı (ekrandan, 01:25:00). `void`, fonksiyonun geriye bir değer döndürmeyeceği anlamına gelir; özyinelemede her çağrı bir sonrakini çağırır, kendi işini yapar ve yalnız bittiğini bildirerek döner.

Base case yine string'in boş olmasıdır, yani elde `'\0'` kalması. Base case'e ulaşıldığında bir değer döndürülmez. Elde hâlâ bir karakter varsa fonksiyon bir sonraki karakter için yeniden çağrılır. Her çağrı, kendisinden sonraki çağrılar döndükten sonra kendi elindeki string'in ilk karakterini yazdırır. Bu yüzden karakterler sondan başa doğru yazılır.

Yazdırılacak olan işaretçinin kendisi değil, gösterdiği adresteki değerdir; bunun için önüne `*` konur. Karşılaştırma için ekrana `// int b=3; &b` yazıldı (ekrandan, 01:25:00): `int b=3;` bellekte bir tamsayılık yer ayırıp içine 3 yazar; bu 3'ün hangi adreste olduğu `&b` ile öğrenilir. Normal bir değişkenin önüne `&` konunca adresine ulaşılır, bir işaretçinin önüne `*` konunca değerine ulaşılır.

### 8.4 Çağrıların izlenmesi

Anlatım beş harfli bir ad örneğiyle yapıldı; ekrandaki yorum satırında string her çağrıda bir harf kısalır: tam ad, ilk harfi atılmış hâli, ..., son harf, `'\0'` (ekrandan, 01:30:00). Her işaretçi kendi elindeki dizinin ilk elemanını gösterir. Örneğin son iki harfi gören çağrı sondan ikinci harfi yazar, ondan önceki çağrı bir önceki harfi yazar. Son çağrı base case'e ulaşıp döndüğünde zincir geri sarılır ve her çağrı kendi ilk karakterini yazdırır; bütün çağrılar dönünce program biter.

**Soru (sohbetten):** `*` işaretini tipin sonuna ya da değişkenin başına koymak, yani arada boşluk olup olmaması fark eder mi? **Cevap:** Fark etmez; `char* str1` ile `char *str1` aynıdır.

Sohbetten gelen bir başka öneriyle yazdırma satırı `*str1` yerine `str1[0]` ile yazılıp denendi; aynı sonucu verdi ve değeri görmeyi kolaylaştırdığı söylendi. İki gösterimin eşdeğerliği koda yorum olarak eklendi (ekrandan, 01:35:00). <!-- BELİRSİZ: Sohbetteki önerinin metni okunmuyor; kod değişikliğinden str1[0] önerisi olduğu çıkarıldı. -->

Kodun son hâli (ekrandan, 01:30:00 ve 01:35:00):

```c
#include<stdio.h>

void reverseStr(char* str1);

int main()
{
    char str[50];

    printf("Enter Your String\n");
    scanf("%s",str);

    reverseStr(str);
    printf("\n");

    return 0;
}

void reverseStr(char* str1)
{
    if(*str1!='\0')
        reverseStr(str1+1);

    printf("%c",str1[0]); //*str1 = str[0]
}
```

Bu kod `gcc -Wall` ile uyarısız derlendi ve girilen kelimeyi ters yazdırdı. Ekranda `main`'in başında ayrıca bir işaretçi denemesi vardı (bkz. 9. bölüm); burada çıkarıldı.

> **Ders sonrası not:** `printf` satırı `if`'in dışında olduğu için base case çağrısı da `str1[0]`, yani `'\0'` karakterini yazdırır. Terminalde görünmez, ama çıktıya fazladan bir null bayt girer; ajan programı derleyip çıktıyı bayt bayt inceleyerek bunu doğruladı. `printf` satırı `if` bloğunun içine alınırsa (`if(*str1!='\0') { reverseStr(str1+1); printf("%c",str1[0]); }`) yalnız gerçek karakterler yazılır.

## 9. İşaretçi Üzerine Sorular

Son örnekten sonra sohbetten gelen sorular üzerine kısa bir işaretçi denemesi yapıldı.

**Soru:** `*ptr` adresteki değeri belirtiyor; ama işaretçiyi tanımlarken de `int *ptr` yazıyoruz. Bu nasıl oluyor? **Cevap:** `int *ptr;` bir tamsayı işaretçisi tanımlar. `ptr`'nin içinde bir adres vardır (örneğin 1001 numaralı adres). Bu deneme için `int *ptr;` tanımlanıp `printf("%d",ptr);` ile adres yazdırıldı. Derleyici `format '%d' expects argument of type 'int', but argument 2 has type 'int *'` uyarısı verdi, program yine de bir sayı yazdı. Program yeniden çalıştırıldığında farklı bir adres çıktı; bu, bilgisayarın belleğinden verilen bir adrestir. Ardından `*ptr`'ye 3 yazılıp `printf("%d",*ptr);` ile değer yazdırıldı: `ptr` adresi, `*ptr` içindeki değeri verir (ekrandan, 01:35:00).

<!-- BELİRSİZ: *ptr'ye 3'ün yazıldığı satır karelerde görünmüyor; altyazıdan alındı. -->

> **Ders sonrası not:** Derste "adres de int'tir, bu yüzden `%d` kullanıyorum" denildi. Adres yazdırmak için doğru biçim belirteci `%p`'dir (`printf("%p", (void*)ptr);`); derleyicinin verdiği `-Wformat` uyarısı bu yüzdendir. Ayrıca adres atanmamış bir işaretçinin (`int *ptr;`) gösterdiği yere `*ptr` ile değer yazmak tanımsız davranıştır; önce işaretçi geçerli bir adrese bağlanmalıdır (örneğin `int b; int *ptr=&b;`).

**Soru:** `*ptr`'yi bir değere atamak normal bir değere atamakla aynı şey mi? **Cevap:** Evet. `*ptr`'ye atama "adresin içini değiştir" demektir.

**Soru:** `*ptr`'yi `x`'e atayıp sonra `x` üzerinde değişiklik yaparsak işaretçi etkilenir mi? **Cevap:** Derste "evet" denildi ve `*ptr` üzerinden yapılan her değişikliğin adresin içini değiştirdiği, önceki değerin (3) kaybolacağı açıklandı.

> **Ders sonrası not:** `x = *ptr;` ataması adresteki değerin bir kopyasını `x`'e yazar; sonradan `x`'i değiştirmek `*ptr`'yi etkilemez. Adresteki değer yalnız `*ptr = ...` ile (ya da `x` bir işaretçi olup aynı adresi gösteriyorsa) değişir.

> **Hocanın vurgusu:** Kodları kendiniz yazmaya çalışın ve denemeler yapın; örneğin bir işaretçi tanımlayıp önüne `*` konunca ne yazdığını deneyin. Birisi oklarla ne kadar gösterirse göstersin, kendi denemeniz çok daha verimlidir. Özellikle işaretçi aritmetiğini denemeniz önerilir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:15:00): Verilen bir string'in uzunluğunu özyineleme metoduyla hesaplayan algoritmayı C dilinde gerçekleyiniz.

> **Çözüm (derste verildi):** Base case `*str1=='\0'` iken 0 döndürmektir; değilse `return 1+strLen(++str1);`. Kodun tamamı 4.6'dadır.

**Soru 2** (ekrandan, 00:15:00): Verilen bir sayının basamak sayısını özyineleme metoduyla bulan algoritmayı C dilinde gerçekleyiniz.

> **Çözüm (derste verildi):** Sayı 0'dan büyük değilse 0 döndürülür; değilse `return 1+countDigits(number1/10);`. `1234567` için sonuç 7'dir. Kod 5. bölümdedir.

**Soru 3** (ekrandan, 00:15:00): 1'den $n$'ye kadar olan sayıların toplamını özyineleme metoduyla bulan algoritmayı C dilinde gerçekleyiniz.

> **Çözüm (derste verildi):** $n=1$ ise 1 döndürülür; değilse `return n1+sumOfNumber(n1-1);`. $n=3$ için 6, $n=5$ için 15. Kod 6.2'dedir.

**Soru 4** (ekrandan, 00:15:00): Verilen iki sayının EBOB'unu özyineleme metoduyla bulan algoritmayı C dilinde gerçekleyiniz.

> **Çözüm (derste verildi):** Sayılar eşitse sayının kendisi döndürülür; değilse büyükten küçük çıkarılıp fonksiyon yeniden çağrılır. $(36,45)$ için 9, $(17,3)$ için 1. Kod 7.2'dedir.

**Soru 5** (ekrandan, 00:15:00): Verilen bir string'in tersini özyineleme metoduyla bulan algoritmayı C dilinde gerçekleyiniz.

> **Çözüm (derste verildi):** `void` bir fonksiyon önce `str1+1` ile kendini çağırır, döndükten sonra `str1[0]`'ı yazdırır; karakterler sondan başa doğru yazılır. Kod ve düzeltme notu 8.4'tedir.

**Soru 6** (derste sözlü, 00:21:25): Bir string'in elemanlarını özyinelemeyle sayarken nerede durmalıyız, base case ne olmalı?

> **Çözüm (derste verildi):** String'in sonundaki `'\0'` (null) karakterine gelindiğinde durulur. Ayrılan yer (50) değil, string'in gerçek sonu esas alınır, çünkü string ayrılan yerin tamamını doldurmayabilir.

**Soru 7** (derste sözlü, 00:34:40): `scanf("%s", str)` satırında `str`'nin önüne neden adres işareti yazmıyoruz?

> **Çözüm (derste verildi):** String bir karakter dizisidir ve dizi adı zaten ilk elemanın adresidir. `int` gibi tek bir değişken okunurken ise `&` gerekir (`scanf("%d",&number)`).

## Dersin Toparlaması

Bu uygulama dersinde özyinelemeli fonksiyonların iki parçası, base case ve kendini değişmiş parametreyle çağıran kısım, önce slayttaki `fonk` örneğiyle gösterildi, sonra beş problemde uygulandı. Her örnekte aynı iki soru soruldu: çağrılar nerede duracak ve problem nasıl küçülecek? String uzunluğu ve string'i ters yazdırmada problem işaretçiyi bir karakter ilerleterek, basamak sayısında sayıyı 10'a bölerek, toplamda $n$'yi bir azaltarak, EBOB'da büyük sayıdan küçüğü çıkararak küçüldü. Her çağrının değerini kendisini çağıran yere döndürdüğü, sonucun geri dönüşte biriktiği ve derin özyinelemenin yığını doldurabileceği vurgulandı.

Örnekler sırasında fonksiyon bildirimi ile gerçekleme ayrımı, modülerlik, anlamlı ve çakışmayan adlar seçmek, dizi adının adres olması ve `*`/`&` işleçleri de tekrar edildi. Özyineleme ve işaretçiler teorik derste ayrıntılı işlenecek, böl ve fethet algoritmaları ile yığın kullanımı da algoritmalar ve veri yapıları derslerinde görülecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
