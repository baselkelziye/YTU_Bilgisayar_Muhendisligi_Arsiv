# Ders 6 Çalışma Özeti

## Genel Konular

- Önermeler ve asallık kontrolü (önceki dersin devamı)
  - Önerme, sonucu ya doğru ya yanlış olan matematiksel ya da mantıksal ifadedir. Örnek: "her pozitif doğal sayı $n$ için $n^2+n+41$ asaldır" bir $P(n)$ önermesidir.
  - Bu önermenin yanlışlığını göstermek, doğruluğunu göstermekten kolaydır: $n=40$ için $40^2+40+41 = 1681 = 41^2$, $n=41$ için $1763 = 41\cdot 43$ asal değildir.
  - Bir sayının asallığı, 2'den başlayıp sayının yarısına (hatta kareköküne) kadar bölen aranarak kontrol edilir. Bölen bulununca hemen çıkmak için `for` yerine `while` kullanılır.
  - Eratosten kalburu (Sieve of Eratosthenes): bilinen asal sayıların katları sırayla elenir, kalanlar asaldır (ekrandan, 00:10:00). Hız kazandırır ama asalları tutmak için dizi gerekir; ek bellek $O(n)$ olur. Basit deneme yönteminde ek bellek $O(1)$'dir.
- Karşı örnek yöntemi (counter example method)
  - Önerme: $\neg\exists\, a,b,c,d \in \mathbb{N}^+$, $a^4+b^4+c^4=d^4$ (ekrandan, 00:20:00). Ekrandaki nota göre bu önermenin yanlışlığı 1988'de gösterilmiştir.
  - Kaba kuvvet çözümü: $a$, $b$, $c$, $d$ için 1'den $N$'ye iç içe 4 döngü ve bir `if` kontrolü. $T(N)=\sum_{a=1}^{N}\sum_{b=1}^{N}\sum_{c=1}^{N}\sum_{d=1}^{N} 1 \approx N^4$.
  - Bir örnek bulununca çıkmak gerektiği için `for` yerine `while` daha mantıklıdır (ekrandan, 00:25:00).
  - Yöntemin fikri: doğruluk, varlık, yanlışlık ya da yokluk ispatından hangisi zorsa tersini göstermek. Yokluğu ispatlamak bütün olasılıkları denemeyi gerektirir; tek bir karşı örnek bulmak çok daha kolaydır.
  - Çözülmemiş örnek: "2 dışındaki her çift tam sayı iki asal sayının toplamıdır". $4=2+2$, $6=3+3$, $8=5+3$, $100=97+3=41+59$ (ekrandan, 00:25:00). Doğruluğu ya da yanlışlığı henüz bilinmiyor.
- Takas (swap)
  - Geçici değişkenle iki değişken takası: `T=a; a=b; b=T;`. $T(N)=1$, $S(N)=M(N)=1$ (ekrandan, 00:40:00).
  - Üç değişkenli döngüsel takas ($a\leftarrow b$, $b\leftarrow c$, $c\leftarrow a$): tek geçici değişken yeter; hangi değişkenle başlanırsa ona değer veren değişken sırayla zincir boyunca kaydırılır.
  - Geçici değişkensiz takas: toplama-çıkarma, çarpma-bölme ve XOR ile (ekrandan, 00:35:00). Toplama ve çarpmada taşma (overflow) riski vardır, kayan noktalı sayı ve string için uygun değildir.
- Mantıksal işlemler ve XOR
  - AND (`&&`), OR (`||`), NOT ve XOR. XOR: iki girişten yalnız biri doğruysa sonuç 1'dir.
  - Bit düzeyinde XOR: karşılıklı bitler aynıysa 0, farklıysa 1. $10 \oplus 5 = 1010 \oplus 0101 = 1111 = 15$.
- Pisagor üçlüsü problemi: $a+b+c=1000$, $a^2+b^2=c^2$, $a,b,c>0$
  - Beş algoritma adım adım iyileştirildi (ekrandan, 00:45:00-01:15:00). Hepsi aynı iki sıralı üçlüyü bulur: (200, 375, 425) ve (375, 200, 425).
  - Algoritma 1: üç iç içe döngü, $10^9$ adım ($N^3$). Algoritma 2: $c=1000-a-b$, $10^6$ adım ($N^2$). Algoritma 3: `b<=1000-a`, 499.500 adım. Algoritma 4: `a<500`, `b` 500-a'dan 499'a, 124.750 adım. Algoritma 5: dış döngü `c` 333'ten 499'a, `b` 1'den 499'a, $a=1000-c-b$; 83.333 adım.
  - `&&` kısa devre yapar: yanlış olma olasılığı yüksek koşul öne yazılırsa ikinci koşul hiç hesaplanmaz. `||` için tersi geçerlidir: doğru olma olasılığı yüksek koşul öne yazılır.
- Sayı piramidi
  - Satırları 1, 2 3, 4 5 6, 7 8 9 10, ... olan üçgende 1000. satırın son elemanı nedir (ekrandan, 01:25:00)?
  - İç içe döngüyle sayaç artırılırsa $\sum_{i=1}^{N}\sum_{j=1}^{i}1 = \frac{N(N+1)}{2}$ işlem yapılır; sayaç da aynı değere ulaşır. $N=1000$ için sonuç 500500'dür.
  - Doğrudan formülle ($N(N+1)/2$) üç işlemde, yani sabit karmaşıklıkta hesaplanır.
- Diziler (array)
  - En büyük 3., 6. sayıyı ayrı değişkenlerle bulmak, `if` sayısını patlatır. Veriler bellekte, mümkünse ardışık olarak saklanmalıdır. Bunun için veri yapıları (data structure) kullanılır; en temeli dizidir.
  - Algoritmanın üç temel işlemi (sıralı, şartlı, tekrarlı işlem) bu tür problemler için yetmez; programlama dilinin sunduğu dizi yapısı gerekir.
  - Dizi tanımı `int array[MAX];`, boyut `#define` ile verilir. Elemanlar `array[0]`'dan `array[MAX-1]`'e kadardır; bu sayılar indistir. Diziye "indisli değişken" de denir.
  - C sınır kontrolü yapmaz; sınır dışına erişim bazen çalışır, bazen segmentation fault verir.
  - İlk değer verilmeyen yerel dizide çöp değerler olur. `= {0}` ile tüm elemanlar sıfırlanır; `= {1}` yalnız ilk elemanı 1 yapar, kalanlar 0 olur.
  - `int` elemanların adresleri 4'er bayt artar: dizi elemanları bellekte bitişiktir (contiguous).
- En büyük 8. eleman
  - Sayılar diziye kaydedilir, dizi artan sırada sıralanır, sondan 8. eleman ($n-8$ indisli) okunur (ekrandan, 01:50:00).
  - Dizi elemanına erişim tek adımdır; maliyeti sıralama belirler: basit algoritmalarla (bubble, insertion, selection sort) $N^2$, quick sort ve merge sort ile $N\log N$.
- Diziyi tersine çevirme ve yerinde (in-place) algoritma
  - İkinci diziye tersten kopyalama: `d2[i] = d1[n-i-1]`. $T(N)=N$ ama $S(N)=N$; yerinde (in-place) değildir.
  - Yerinde tersleme: `i` 0'dan `n/2`'ye kadar `d[i]` ile `d[n-i-1]` takas edilir; $T(N)\approx N$, $S(N)=1$ (ekrandan, 02:00:00). Döngü `n`'ye kadar giderse dizi iki kez terslenip eski haline döner.
  - Yerinde sıralama algoritmaları en fazla bir geçici değişken kullanır; örnek olarak quick sort ve in-place merge sort gösterildi.
- String ve palindrom
  - C'de string bir karakter dizisidir ve `'\0'` (null karakter) ile biter. `scanf("%s", str)` boşlukta durur; `&` gerekmez çünkü dizi adı adres gibi davranır.
  - Boşluklu metin `scanf("%[^\n]s", str)` ile okunur (ekrandan, 02:20:00). Önceki okumadan kalan Enter karakteri tamponda kalır.
  - Uzunluk: `while (str[i] != '\0') i++;`. "hello world" için uzunluk 11'dir; 12. karakter `'\0'`'dır.
  - Palindrom 1: ters kopya `str2` oluşturulur, karakter karakter karşılaştırılır (ek bellek gerekir) (ekrandan, 02:30:00). Palindrom 2: `i < len/2 && str[i] == str[len-i-1]` koşuluyla yerinde kontrol.
- 6 ve 7 basamaklı palindrom sayılar
  - Yöntem 1: 100000'den 999999'a her sayının basamakları diziye alınıp palindrom kontrolü yapılır.
  - Yöntem 2: 100'den 999'a her üç basamaklı sayı alınır, basamakları ayrılır ve `b3 b2 b1 b1 b2 b3` biçiminde yazılır; 900 sayı üretilir. 7 basamak için ortaya 0-9 arası bir basamak eklenir: 9000 sayı.
  - Sayma formülü: $n$ basamaklı palindrom sayısı $9\cdot 10^{\lfloor (n-1)/2 \rfloor}$'dir (ekrandan, 02:45:00). Üs hesabı yarılamayla $\log n$ adımda yapılabilir; sayma ile listeleme farklı karmaşıklıktadır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Karşı örnek yöntemi
  - Bir şeyin yokluğunu göstermek bütün olasılıkları denemeyi gerektirir. Tersini, yani bir örneğin varlığını göstermek hem algoritmik olarak hem hız açısından çok daha kolaydır.
- Matematik ile algoritmanın birlikteliği
  - Pisagor üçlüsü örneğinde her matematiksel gözlem bir döngüyü kaldırdı ya da sınırı daralttı: $10^9$ adımdan 83.333 adıma inildi. Hoca, bu işin matematikten ayrı düşünülmemesi gerektiğini söyledi.
- Koşul sırası ve kısa devre
  - `&&` ile bağlanan koşullarda yanlış olma olasılığı yüksek olan öne, `||` ile bağlananlarda doğru olma olasılığı yüksek olan öne yazılır. Dizilerde bu yaklaşım sık kullanılacak.
- Dizi sınırları
  - Erişim 0 ile `MAX-1` arasında kalmalıdır. Sınır dışına erişim bir bilgisayarda çalışsa bile başka bir bilgisayarda çökebilir; sorumluluk programcıdadır.
- Diziyi sıfırlama
  - Özellikle sayısal hesaplarda dizi başlatılmazsa çöp değerler yanlış sonuç verir.
- Yerinde (in-place) özellik
  - Bir algoritmanın ek dizi isteyip istemediği önemli bir özelliktir. Ters kopya yerine yarıya kadar takas yapmak belleği $N$'den 1'e indirir.
- Standart C
  - Bu derste C++ sözdizimi karıştırılmamalı; çözümler standart C ile yazılmalıdır.

## Kısa Tekrar Notları

- $n^2+n+41$ önermesi $n=40$ ve $n=41$ için yanlıştır; tek karşı örnek önermeyi çürütür.
- Asallık kontrolünde karekök sınırı ve bölen bulununca çıkış (`while`) kullanılır. Eratosten kalburu hızlıdır ama $O(n)$ ek bellek ister.
- $a^4+b^4+c^4=d^4$ için kaba kuvvet $N^4$'tür.
- Geçici değişkenli takas: 3 atama, $S=1$. Geçici değişkensiz takas: toplama-çıkarma, çarpma-bölme, XOR; taşma ve tür sınırlamaları vardır.
- XOR: aynı bitler 0, farklı bitler 1; $10\oplus5=15$, $3\oplus5=6$.
- Pisagor üçlüsü: (200, 375, 425); adımlar $10^9 \to 10^6 \to 499500 \to 124750 \to 83333$.
- Piramidin $N$. satırının son elemanı $N(N+1)/2$; $N=1000$ için 500500.
- Dizi indisleri 0..MAX-1; `= {0}` ile sıfırlama; `int` elemanlar 4 bayt arayla bitişik.
- En büyük $k$. eleman: sırala ($N\log N$ ya da $N^2$), sonra $n-k$ indisine eriş (1 adım).
- Yerinde tersleme: `for (i=0; i<n/2; i++) swap(d[i], d[n-i-1])`.
- String `'\0'` ile biter; boşluklu okuma `%[^\n]`; palindrom kontrolü `len/2`'ye kadar.
- $n$ basamaklı palindrom sayısı: $9\cdot10^{\lfloor(n-1)/2\rfloor}$ (6 basamak: 900, 7 basamak: 9000).

## Detaylı Açıklamalar

- **Asallık ve Eratosten kalburu.** Önceki derste yazılan asallık kontrolü 2'den sayının yarısına (ya da kareköküne) kadar bölen arar; bölen bulunursa `while` döngüsü hemen biter. Döngü sonuna kadar gittiyse sayı asaldır. Bu yöntem birkaç değişkenle çalışır, ek bellek $O(1)$'dir. Eratosten kalburunda 2'den 100'e kadar sayılar yazılır; önce 2'nin, sonra 3'ün, sonra sıradaki asalın katları karalanır, kalanlar asaldır. Asallar bir dizide tutulursa sonraki kontroller yalnız asallara bölünerek yapılır. Hoca zaman karmaşıklığının $n\log n$ düzeyine indiğini, buna karşılık $O(n)$ yardımcı bellek gerektiğini söyledi: hız kazanılır, bellek kaybedilir.

> **Ders sonrası not:** Hoca kalburun karmaşıklığını $n\log n$ olarak verdi; Eratosten kalburunun bilinen karmaşıklığı büyük olasılıkla $O(n\log\log n)$'dir. Her iki durumda da $n^2$'den çok daha iyidir.

- **Dört değişkenli önerme.** Ekrandaki önerme $P(a,b,c,d): \neg\exists\, a,b,c,d\in\mathbb{N}^+,\ a^4+b^4+c^4=d^4$ biçimindedir. Ekrandaki nota göre bu önermenin yanlışlığı 1988'de ispatlanmıştır, yani denklemi sağlayan bir dörtlü vardır. Kaba kuvvet algoritması $a$, $b$, $c$, $d$ için 1'den $N$'ye iç içe döngü kurar; en içte $a^4+b^4+c^4=d^4$ kontrolü yapılır. Dış döngü $N$, ikinci $N^2$, üçüncü $N^3$, en içteki $N^4$ kez döner. Örnek bulunduğunda bütün döngülerden çıkmak gerektiği için koşulun `while` döngülerine yazılması daha doğrudur.

> **Ders sonrası not:** Hoca bir noktada önermenin "doğruluğunun ispat edildiğini" söyledi; ekrandaki notta "yanlışlığı ispat edilmiş" yazıyor. Doğrusu ikincisidir: büyük olasılıkla Noam Elkies'in 1988'de bulduğu karşı örnek kastediliyor; bilinen en küçük karşı örnek $95800^4+217519^4+414560^4=422481^4$'tür.

- **Takas.** İki değişkenli takas `T=a; a=b; b=T;` ile yapılır. Üç değişkenli döngüsel takasta $a\leftarrow b$, $b\leftarrow c$, $c\leftarrow a$ istenir. `T=a` ile başlanırsa $a$'ya kendisine değer verecek değişken (burada $c$) yazılır, sonra $c$'ye $b$ yazılır, en son $b$'ye `T` yazılır (derste $b$ ile başlayan simetrik çözüm de gösterildi). Ekrandaki kodda geçici değişkensiz üç yöntem var: `x=x+y; y=x-y; x=x-y;` (10 ve 5 için `x` önce 15 olur), `x=x*y; y=x/y; x=x/y;` (`x` önce 50 olur) ve XOR (`x=x^y; y=x^y; x=x^y;`, `x` önce 15 olur). Toplama ve çarpma büyük sayılarda `int` sınırını aşabilir; kayan noktalı sayı ve string için bu yöntemler uygun değildir.

> **Ders sonrası not:** Tahtadaki örnekte $3\oplus5$ sonucu `110` olarak doğru yazıldı ama karşısına 8 yazıldı; `110` ikilik sayısı 6'dır. Ayrıca XOR takası iki değişkenin değeri aynı olduğunda bozulmaz (derste de 5 ile 5 denendi ve doğru çalıştı); büyük olasılıkla asıl sorun, iki işaretçi aynı bellek gözünü gösterdiğinde ortaya çıkar, o zaman değer 0'a düşer.

- **Pisagor üçlüsü.** Tam C kodu aşağıdadır; beş algoritmayı da içerir ve adım sayılarını yazar. Kod karelerden alınan parçalarla kuruldu (ekrandan, 00:45:00, 00:50:00, 00:55:00, 01:05:00, 01:15:00), `gcc -Wall` ile derlenip çalıştırıldı.

```c
#include <stdio.h>
/* a + b + c = 1000, a^2 + b^2 = c^2, a,b,c>0 */
int main(){
    int a, b, c;
    long t = 0;
    int count = 0;
    for (a = 1; a <= 1000; a++)
        for (b = 1; b <= 1000; b++)
            for (c = 1; c <= 1000; c++) {
                t = t + 1;
                if ((a+b+c == 1000) && (a*a + b*b == c*c)) {
                    count++;
                    printf("%d %d %d\n", a, b, c);
                }
            }
    printf("Alg1: %ld step, %d triplet\n", t, count);
    t = count = 0;
    for (a = 1; a <= 1000; a++)
        for (b = 1; b <= 1000 - a; b++) {   /* Alg3 */
            c = 1000 - a - b;
            t = t + 1;
            if (a*a + b*b == c*c) { count++; printf("%d %d %d\n", a, b, c); }
        }
    printf("Alg3: %ld step, %d triplet\n", t, count);
    t = count = 0;
    for (a = 1; a < 500; a++)
        for (b = 500 - a; b < 500; b++) {   /* Alg4 */
            c = 1000 - a - b;
            t = t + 1;
            if (a*a + b*b == c*c) { count++; printf("%d %d %d\n", a, b, c); }
        }
    printf("Alg4: %ld step, %d triplet\n", t, count);
    t = count = 0;
    for (c = 333; c < 500; c++)
        for (b = 1; b < 500; b++) {         /* Alg5 */
            a = 1000 - c - b;
            t = t + 1;
            if (a*a + b*b == c*c) { count++; printf("%d %d %d\n", a, b, c); }
        }
    printf("Alg5: %ld step, %d triplet\n", t, count);
    return 0;
}
```

  - Ekranda `t` değişkeni `int` olarak tanımlıydı; $10^9$ `int` sınırına sığar. Yukarıdaki kodda `long` kullanıldı. Çalıştırma çıktısı: Alg1 1000000000 adım, Alg3 499500 adım, Alg4 124750 adım, Alg5 83333 adım; hepsinde 2 üçlü. Algoritma 2 (`b` de 1'den 1000'e, $c=1000-a-b$) $10^6$ adımdır.
  - Algoritma 5'in sonunda `a+b+c` yazdırıldığında 1002 çıktı. Nedeni, döngüler bittiğinde `c=500` ve `b=500` olması, `a`'nın ise son geçerli değeri olan $1000-499-499=2$'de kalmasıdır.

- **Sayı piramidi.** Satırları $1;\ 2\,3;\ 4\,5\,6;\ 7\,8\,9\,10;\ \dots$ olan üçgende satır sonları $1, 3, 6, 10, 15, \dots$ olup her adımda artış bir fazlalaşır. Kod `t=0; for(i=1;i<=N;i++) for(j=1;j<=i;j++) t=t+1;` biçimindedir. İşlem sayısı $\sum_{i=1}^{N}\sum_{j=1}^{i}1=\sum_{i=1}^{N} i=\frac{N(N+1)}{2}$ olur; sayaç birer arttığı için karmaşıklık ile sonuç aynı çıkar. $N=1000$ için $t=1000\cdot1001/2=500500$ (ekrandan, 01:25:00 ve 01:30:00). Formülle hesap bir çarpma, bir toplama ve bir bölmeyle biter.

- **Diziler.** Bellek de bir dizi gibidir: 4 GB bellekte adresler 0'dan $2^{32}-1$'e kadar gider, her gözde 1 bayt saklanır. Ekrandaki ArrayIntro programında `for(i=0;i<MAX;i++) printf("Array[%d] -- %d\n", i, array[i]);` ile başlatılmamış dizinin çöp değerleri görüldü (ekrandan, 01:45:00). `%p` ile `&array[i]` yazdırılınca adreslerin 4'er arttığı görüldü. Okuma `scanf("%d", &array[i])` ile yapılır.

- **Yerinde tersleme.** Kod (gcc ile derlenip `{1,2,3,4,5}` için `5 4 3 2 1` çıktısı alındı; döngü gövdesi derste yazılandır, `main` ve test dizisi eklendi):

```c
#include <stdio.h>
#define N 5
int main(){
    int d[N] = {1,2,3,4,5};
    int i, t;
    for (i = 0; i < N/2; i++) {
        t = d[i];
        d[i] = d[N-i-1];
        d[N-i-1] = t;
    }
    for (i = 0; i < N; i++) printf("%d ", d[i]);
    printf("\n");
    return 0;
}
```

- **Palindrom string.** Derste önce ikinci dizili çözüm yazıldı (ekrandan, 02:30:00), sonra yerinde çözüme geçildi. Yerinde çözüm (`MAX` derste önce 20, sonra 25 yapıldı; gcc ile derlenip "kek" ve "neveroddoreven" için Palendrom, "hello world" ve boşluklu "never odd or even" için Non-palendrom çıktısı alındı):

```c
#include <stdio.h>
#define MAX 25
int main(){
    int i, len;
    char str[MAX];
    printf("Enter a string: ");
    scanf("%[^\n]s", str);
    i = 0;
    while (str[i] != '\0') i++;
    len = i;
    i = 0;
    while (i < len/2 && str[i] == str[len-i-1]) i++;
    if (i == len/2) printf("Palendrom\n");
    else printf("Non-palendrom\n");
    return 0;
}
```

  - Boşluklar da karakter sayıldığı için "never odd or even" bu kodla palindrom çıkmaz; boşluklar ya kaldırılmalı ya da hesaba katılmalıdır.

- **6 ve 7 basamaklı palindrom sayılar.** İlk basamak 0 olamaz (9 seçenek), sonraki basamaklar 10'ar seçeneklidir, aynalanan basamaklar tek seçeneklidir: 6 basamak için $9\cdot10\cdot10\cdot1\cdot1\cdot1=900$, 7 basamak için $9\cdot10^3=9000$ (ekrandan, 02:45:00). Yöntem 2'de `i` 100'den 999'a gider; `b1=i%10`, `b2=(i/10)%10`, `b3=i/100` ayrılır ve `b3 b2 b1 b1 b2 b3` yazılır. 7 basamak için ortaya `j=0..9` döngüsü eklenir. gcc ile denendi: 900 ve 9000 sayı üretildi; kaba kuvvet kontrolü de 6 basamaklı palindrom sayısını 900 buldu.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
