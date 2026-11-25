# Ders 29 Genişletilmiş Notu: Çok Boyutlu Diziler ve Çok Boyutlu Karakter Dizileri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Hazır fonksiyon yerine algoritmik çözüm
- 2. Tek boyutlu diziden çok boyutlu diziye
- 3. Çok boyutlu dizi tanımlama ve gezme
- 4. İlk değer ataması ve "dizilerden oluşan dizi" bakışı
- 5. Çok boyutlu dizilerin belleğe yerleşimi
- 6. Matris toplama: akış diyagramı ve C kodu
- 7. Matris çarpımı: akış diyagramı ve C kodu
- 8. Dizi tanımlarını katman katman okumak
- 9. Çok boyutlu karakter dizileri
- 10. Karakter matrisi üzerinde C denemeleri
- 11. Her satırdaki karakter dizisini ters çevirme
- 12. Değişken izleme tablosu

## 1. Hazır fonksiyon yerine algoritmik çözüm

Dersin başında bir öğrencinin sorusu üzerine hoca, bu dersteki C kodlarının amacını hatırlattı. Kodlar C dilinin bütün inceliklerini göstermek için değil, tasarlanan algoritmaların çalışır hâlini (gerçeklemesini) yapmak için yazılır. Bu yüzden şimdiye kadar yalnız `printf` ve `scanf` için `stdio.h` kullanıldı; `ctype.h`, `stdlib.h` gibi kütüphanelerden bahsedilmedi. `toupper` ya da `tolower` gibi hazır bir fonksiyonu çağırmak problemi çözmek değil, başkasının çözümünü kullanmaktır. Henüz fonksiyon bile işlenmedi, yalnız `main` biliniyor.

> **Hocanın vurgusu:** Her işi yapan bir fonksiyon zaten bulunur; önemli olan boşlukları nasıl sayacağınızı, kalanları bir döngüyle nasıl kaydıracağınızı, art arda gelen iki karakteri nasıl karşılaştıracağınızı düşünerek algoritmik çözümü kendinizin geliştirmesidir.

Benzer şekilde bir karakter dizisinden boşlukları temizleme probleminde beklenen, yalnız boşlukları atlayarak yazdırmak değil, dizinin kendisini (tercihen kendi üzerinde, olmazsa ek bir dizide) düzeltip sonra yazdırmaktır. Yazdırma, sonucu görmeyi sağlayan ek bir adımdır.

## 2. Tek boyutlu diziden çok boyutlu diziye

### 2.1 Değişken ve tek boyutlu dizi

Değişken, bellekte belirli boyutta bir alana (tamsayı için mimariye göre 16, 32 ya da 64 bit; karakter için 1 bayt; `float` ve `double` için farklı boyutlar) bir isimle erişmeyi ve içindeki 0-1 dizisini kullanmayı sağlar. Aynı türden çok sayıda veri üzerinde hep birlikte işlem yapılacaksa bu veriler tek boyutlu bir dizide tutulur. Örneğin bir sınıftaki öğrencilerin notları birinci, ikinci, üçüncü göz şeklinde tutulabilir; sıralanabilir; toplamı, ortalaması ya da belirli aralıkta kaç not olduğu kolayca bulunabilir. Bu kolaylığı sağlayan şey indis mantığıdır: bir yineleyici (iteratör) ile bütün gözler gezilebilir.

### 2.2 Daha fazla boyut

Slaytta çok boyutlu dizi şöyle tanımlanır (ekrandan, 00:15:00):

- Aynı türdeki verilerin tek bir sıra hâlinde değil, mantıksal olarak satır-sütun formatında tutulduğu yapılardır.
- Daha fazla boyutlu (3 boyutlu, 4 boyutlu, ..., n boyutlu) olabilirler; 3 boyuttan sonrasını görselleştiremiyoruz.
- Bellekte tek boyut var mı? C'de diziler içsel olarak tek boyutlu dizi biçiminde saklanır.

İki boyutlu dizi, matematikteki matrise karşılık gelir. Bir yerine iki indis kullanılır: birinci indisle satırlar, ikinci indisle sütunlar gezilir. İki indis iki gezinti mekanizması demektir; bu iki mekanizma birbirine bağlı olmalıdır, yani iç içe döngüler gerekir. C'deki gibi indisler sıfırdan başlatılırsa sol üstteki göz 0. satırın 0. sütunudur.

Üç boyutlu dizide aynı matristen birden fazlası arka arkaya yerleştirilir: satır, sütun ve derinlik (dilim). Üç eksen için üç yineleyici gerekir; örneğin (0,0,0), arkasında (0,0,1), onun arkasında (0,0,2). Aynı mantıkla 4 boyutlu (i, j, k, l indisli), 5 ya da 6 boyutlu diziler de oluşturulabilir. Yalnız üç boyuttan sonrası dikdörtgen, ızgara ya da küp gibi bir şekille gösterilemez.

Bellek ise tek boyutludur: belirli bir adres sırasıyla giden, her biri 8, 16, 32 ya da 64 bit veri tutan, arka arkaya sıralı özdeş depolama bloklarından oluşur. Bu yüzden kaç eksen tanımlanırsa tanımlansın, C'de bunların hepsi arka planda tek boyutlu bir dizi olarak saklanır.

## 3. Çok boyutlu dizi tanımlama ve gezme

Tanımlama biçimi slaytta şöyledir (ekrandan, 00:25:00):

```text
<tür> [boyut1] [boyut2] [boyut3] ...
  - Boyutlar sabit ifadeler olmak zorundadır.
int A[5][8];
  İfadesi iki boyutlu bir dizidir. Matris olarak da isimlendirilir.
  İlk boyut satırları, ikinci boyut sütunları ifade eder.
```

`int A[5][8]` tanımında `A` önce 5 tamsayı tutan bir dizi gibi görünür, ama ikinci bir indis (8) daha vardır; demek ki iki boyutludur. Slayttaki tabloda indisler `A[0][0]`, `A[0][1]`, ..., `A[0][7]` diye ilk satırda, `A[4][0]`, ..., `A[4][7]` diye son satırda ilerler. Bellekte böyle yerleşmez; bu mantıksal (algısal) bir görünümdür.

Hoca bu diziyi gezen akışı slaytın üzerine çizdi (ekrandan, 00:25:00):

```text
döngü i = 1'den 5'e, artım 1          (satırlar, yavaş dönen)
    döngü j = 1'den 8'e, artım 1      (sütunlar, hızlı dönen)
        A[i][j] = i * j
    j döngüsü sonu
i döngüsü sonu
...
```

Gövdede atama yerine okuma ya da yazdırma da yapılabilirdi. İçteki hızlı dönen döngü bitince dıştaki satır döngüsü bir adım ilerler; o da bitince akış devam eder. İki boyutlu bir dizi kullanan algoritmada temel olarak iki iç içe `for` döngüsü ve bu şekilde erişilen indisler beklenir.

> **Ek bilgi (derste anlatılmadı):** Akış diyagramında döngüler 1'den başlatıldı; C kodunda ise indisler 0'dan başlar, bu yüzden C'de döngüler `i=0; i<5` biçiminde yazılır.

## 4. İlk değer ataması ve "dizilerden oluşan dizi" bakışı

Slayttaki örnek (ekrandan, 00:30:00):

```c
int a[5][2] = { {10, 20},
                {30, 40},
                {50, 60},
                {70, 80},
                {90, 100}
              };
```

`a[5][2]` beş satır (0-4) ve iki sütundan (0-1) oluşur. Hoca bunun C açısından şöyle okunması gerektiğini vurguladı: `a` değişkeni 5 elemanlı bir tamsayı dizisidir ve bu dizinin her gözü kendi içinde 2 tamsayıdan oluşan bir dizi barındırır. Yani "her biri ikilik dizilerden oluşan beşlik dizi"dir. İlk değer atamasındaki `{10, 20}` aslında `a`'nın ilk elemanına yazılan iki elemanlı dizidir; `{30, 40}` ikinci gözdeki ikilik dizi, ve böyle `{90, 100}` beşinci gözdeki ikilik diziye kadar gider.

Örneğin `a[2]` denince 2 indisli göze, yani `{50, 60}` dizisine gidilir; ardından `[1]` ile bu ikilik dizinin 1 indisli elemanına geçilir. `a[2][1]` yazdırılırsa 60 görülür.

Aynı ilk değer ataması tek küme parantezi ile de yapılabilir:

```c
int a[5][2] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
/*             a00 a01 a10 a11 a20 a21 a30 a31 a40 a41 */
```

Değerler sırayla yerleşir: 10 `a[0][0]`'a, 20 `a[0][1]`'e, 30 `a[1][0]`'a gider ve böyle 100 `a[4][1]`'e kadar devam eder (ekrandan, 00:30:00).

> **Hocanın vurgusu:** Çok boyutlu diziyi "her elemanı bir dizi olan dizi" diye düşünürseniz C'deki dizi mantığının nasıl olduğunu tam olarak anlarsınız.

## 5. Çok boyutlu dizilerin belleğe yerleşimi

### 5.1 Satır öncelikli yerleşim

Düşük boyut her zaman düşük adreste bulunacak şekilde yerleşir: önce 0. satır, en son 4. satır. `int a[5][2]` tanımı yapıldığında derleyici 10 tamsayı sığacak bir alan ayırır (allocate eder). Bu temsilî bir gösterimdir; işletim sisteminin bellek yöneticisi alanı parçalara bölebilir, ama bu dersin ilgi alanı dışındadır. Program açısından `a[0][0]`, ardından `a[0][1]`, ardından `a[1][0]` diye `a[4][1]`'e kadar mantıksal olarak ardışık bir blok vardır.

### 5.2 Adres örneği

Slayttaki örnek (ekrandan, 00:35:00): "İki boyutlu dizilerin satır elemanları sol taraf değeri değildir. Satırların bellekteki başlangıç adresini gösterirler." `int a[5][2];` 1FC0 adresinden başlayarak yerleşmiş olsun; tamsayılar 2 bayt (16 bit) kabul edilsin.

| Adres | Eleman | Satır adı |
|---|---|---|
| 1FC0 | a[0][0] | a[0] |
| 1FC2 | a[0][1] | |
| 1FC4 | a[1][0] | a[1] |
| 1FC6 | a[1][1] | |
| 1FC8 | a[2][0] | a[2] |
| 1FCA | a[2][1] | |
| 1FCC | a[3][0] | a[3] |
| 1FCE | a[3][1] | |
| 1FD0 | a[4][0] | a[4] |
| 1FD2 | a[4][1] | |

Her eleman bir öncekinden 2 sonra gelir. 1FC8'e 2 eklenince onluk düşünüldüğünde 10 olur, ama onaltılık gösterimde A'dır: 1FCA. 1FCE'ye 2 eklenince E, F'den sonra 0'a dönülür ve elde 1 oluşur; C bir artıp D olur, adres 1FD0'dır.

`a[0]` yazmak 1FC0 adresini verir; o indisin içindeki her şey `a[0]`'ın altındadır. `a[1]` 1FC4'ü gösterir ve 1FC6'nın sonuna kadar gider. Slayttaki özet: `a[0]`, `a[1]`, `a[2]`, `a[3]`, `a[4]` ifadeleri satırların başlangıç adreslerini gösterir; `a` değişkeni, her elemanı 2 uzunlukta tamsayı dizisi olan 5 uzunluklu bir tamsayı dizisidir. Bu gösterim aynı derste karakter dizilerinde de kullanıldı.

> **Ek bilgi (derste anlatılmadı):** `a[i]` bir adres ifadesi olduğu için `a[1] = ...` gibi bir atama derlenmez; değer atamaları yalnız `a[i][j]` gözlerine yapılabilir. "Sol taraf değeri değildir" ifadesinin pratik anlamı budur.

## 6. Matris toplama: akış diyagramı ve C kodu

### 6.1 Toplamanın mantığı

Hoca Zoom beyaz tahtasında iki matris çizdi (ekrandan, 00:40:00). İki matrisin toplanabilmesi için aynı boyutta olmaları gerekir; sonuç da aynı boyutta bir C matrisidir. A'daki ve B'deki aynı indisli gözler alınıp toplanır ve C'nin aynı indisli gözüne yazılır. Böylece her işlemde birinci indisler aynı, ikinci indisler de aynıdır.

### 6.2 Akış diyagramı

Tahtadaki akış (ekrandan, 00:40:00):

```text
START
oku M, N                              (M satır, N sütun)
döngü i = 1'den M'e, artım 1
    döngü j = 1'den N'e, artım 1
        oku A[i][j], B[i][j]
bağlantı noktası 1
döngü i = 1'den M'e, artım 1
    döngü j = 1'den N'e, artım 1
        C[i][j] = A[i][j] + B[i][j]
bağlantı noktası 2
STOP
```

Okuma ve toplama aynı döngüde de yapılabilirdi; burada ayrı gösterildi. Aynı yapı `while` döngüleriyle de kurulabilir.

### 6.3 C kodu

Dinamik bellek ayırma henüz bilinmediği için dizi boyutları sabit olmalıdır. Kullanıcıdan `n` ve `m` okunup o boyutta dizi açılmaya çalışılırsa hata alınır; bu yüzden `#define` kullanıldı. Değerler hızlı olsun diye ilk değer atamasıyla verildi. Toplam `a`'nın üzerine de yazılabilirdi (`a[i][j] = a[i][j] + b[i][j]`), ama sonraki adımda çarpma için üçüncü bir matris gerekeceğinden ayrı bir `c` dizisi kullanıldı (kod ekrandan, 00:45:00; yazdırma biçimi çıktıdan, 01:00:00):

```c
#include <stdio.h>
#define M 5
#define N 2

int main()
{
    int a[M][N]={10,20,30,40,50,60,70,80,90,100};
    int b[M][N]={5,10,15,20,25,30,35,40,45,50};
    int c[M][N];
    int i,j;

    for (i=0;i<M;i++)
        for(j=0;j<N;j++){
            c[i][j]=a[i][j]+b[i][j];
            printf("[%d][%d]=%d\n",i,j,c[i][j]);
        }

    return 0;
}
```

Biçim dizgisinde önce iki indis `%d` ile, sonra eşittir ve değer yine `%d` ile yazdırılır; `\n` her sonucu ayrı satıra alır. Çıktı (ekrandan, 01:00:00):

```text
[0][0]=15
[0][1]=30
[1][0]=45
[1][1]=60
[2][0]=75
[2][1]=90
[3][0]=105
[3][1]=120
[4][0]=135
[4][1]=150
```

Kod `gcc -Wall` ile derlenip çalıştırıldı ve aynı çıktı alındı; tek küme parantezli ilk değer için yalnız "missing braces" uyarısı verir.

## 7. Matris çarpımı: akış diyagramı ve C kodu

### 7.1 Çarpılabilirlik şartı

Tahtada (ekrandan, 00:50:00) A matrisi M satır, N sütundan (çizimde 4x2), B matrisi P satır, Q sütundan (çizimde 2x3) oluşur. İki matrisin çarpılabilmesi için birinci matrisin sütun sayısı N ile ikinci matrisin satır sayısı P eşit olmalıdır. Akışta bu bir karar kutusuyla kontrol edilir: $N \neq P$ ise doğru kolunda "Çarpılamaz" yazdırılıp çıkılır (bir kontrol değişkeniyle de yapılabilir), yanlış kolunda çarpma yapılır. Sonuç matrisi $M \times Q$ boyutludur (ekrandan, 00:55:00).

### 7.2 Çarpmanın mantığı

A'nın bir satırındaki iki değer ile B'nin bir sütunundaki iki değer alınır; birinci ile birinci, ikinci ile ikinci çarpılır, bu iki çarpım toplanır ve toplam, o satır ile o sütunun kesiştiği C gözüne yazılır. Tahtada sarı renkle A'nın 0. satırı ile B'nin 1. sütunu C'nin (0,1) gözüne, yeşil renkle A'nın 2. satırı ile B'nin 2. sütunu C'nin (2,2) gözüne eşlendi (ekrandan, 00:50:00). Genel formül:

$$C_{ij} = \sum_{k=1}^{N} A_{ik} \, B_{kj}$$

### 7.3 Akış diyagramı

A'nın satırlarını gezmek için `i` (M'e kadar), B'nin sütunlarını gezmek için `j` (Q'ya kadar) gerekir. Ama bu yeterli değildir: her C gözü için satır ile sütunun karşılıklı elemanlarını tek tek çarpıp toplamak gerekir. Bunun için içte üçüncü bir `k` döngüsü kurulur; `k` N'e ya da P'ye kadar gider (ikisi zaten eşittir, akışta P yazıldı). Tahtadaki parça (ekrandan, 00:55:00):

```text
döngü i = 1'den M'e, artım 1
    döngü j = 1'den Q'ya, artım 1
        döngü k = 1'den P'ye, artım 1
            C[i][j] = C[i][j] + A[i][k] * B[k][j]
        k sonu
    j sonu
i sonu
...
```

Burada `C[i][j]` gözünün eski değerine her adımda bir çarpım eklenir. Çarpma toplamadan önce yapıldığı için parantez gerekmez.

> **Ek bilgi (derste anlatılmadı):** Bu akışın doğru sonuç vermesi için `C` matrisinin gözleri döngülere girmeden önce sıfırlanmış olmalıdır. Derste yazılan C kodunda bu iş ayrı bir `sum` değişkeniyle çözüldü.

### 7.4 C kodu

Bu kez diziler 10x10 büyüklüğünde açıldı; gerçek boyutlar (A için m x n, B için p x q) kullanıcıdan okunur. Satır-sütun çarpımlarının toplamı `sum` değişkeninde tutulur. Hoca boyut kontrolünü, yanlışsa ikinci matrisi boşuna okumamak için, p ve q okunduktan hemen sonraya taşıdı. Kapanan blokların yanına `// for j`, `// for i`, `// end else` yorumları yazıldı. Kod ekrandan alındı (01:00:00 ve 01:05:00). Ekranda ilk okuma döngüsünde bir an `j<m` görünür; hoca bunu fark edip düzeltti, aşağıda düzeltilmiş hâli vardır:

```c
#include <stdio.h>

int main()
{
    int a[10][10], b[10][10], c[10][10];
    int m,n, p, q, i, j, k, sum=0;

    printf("m-n degerlerini giriniz:");
    scanf("%d%d",&m,&n);

    for (i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    printf("p-q degerlerini giriniz:");
    scanf("%d%d",&p,&q);

    if (n!=p)
        printf("boyutlar tutarsiz. Carpilamazlar.");
    else{
        for (i=0;i<p;i++)
            for(j=0;j<q;j++)
                scanf("%d",&b[i][j]);
        //carpim islemi
        for(i=0;i<m;i++){
            for(j=0;j<q;j++){
                for(k=0;k<p;k++){
                    sum+=a[i][k]*b[k][j];
                }
                c[i][j]=sum;
                sum=0;
            } // for j
        } // for i

        printf("\nCarpim Sonucu:\n");
        for(i=0;i<m;i++){
            for(j=0;j<q;j++)
                printf("%4d",c[i][j]);
            printf("\n");
        }
    } // end else

    return 0;
}
```

Açıklamalar:

- `scanf("%d%d",&m,&n);` iki tamsayıyı `m` ve `n`'nin adreslerine yazar.
- `k` döngüsü bitince satır-sütun çarpımlarının toplamı elde edilmiştir; bu değer `c[i][j]`'ye yazılır ve bir sonraki göz için `sum` sıfırlanır.
- `%4d` tamsayıyı 4 karakterlik bir blok içinde yazar; her satırın sonunda `\n` ile alt satıra geçilir.

Derste denenen girdi: m-n = 2 2, A = 1 2 3 4; p-q = 2 2, B = 5 6 7 8. Çıktı `19 22` / `43 50` oldu (ara adım eklendi):

$$\begin{pmatrix}1&2\\3&4\end{pmatrix}\begin{pmatrix}5&6\\7&8\end{pmatrix}=\begin{pmatrix}1\cdot5+2\cdot7 & 1\cdot6+2\cdot8\\ 3\cdot5+4\cdot7 & 3\cdot6+4\cdot8\end{pmatrix}=\begin{pmatrix}19&22\\43&50\end{pmatrix}$$

Kod `gcc -Wall` ile derlenip aynı girdiyle çalıştırıldı ve aynı sonuç alındı.

> **Ders sonrası not:** Hoca ilk denemede 3x3 bir A (1-9) ve 3x2 bir B girmek istedi, program "Carpilamazlar" yazdı; hoca daha sonra girdiyi ters yazdığını söyledi. 3x3 ile 3x2 aslında çarpılabilir ($N = P = 3$); bu çıktı büyük olasılıkla boyutların yanlış sırayla girilmesinden kaynaklandı.

Üç boyutlu dizilere çok sık ihtiyaç olmaz; olursa da mantık aynı şekilde devam eder.

## 8. Dizi tanımlarını katman katman okumak

Hoca bellek yerleşim mantığını vurgulamak için beyaz tahtaya şu tanımları yazdı (ekrandan, 01:10:00):

```c
int w[10][20][30];
int x[20][30];
int y[30];
int z;
```

- `y`, 30 tamsayıdan oluşur; sanki içinde 30 tane `z` tipinde değişken vardır.
- `x`, 20 elemanlı bir dizidir ama her gözünde 30'luk bir tamsayı dizisi tutar: 30'luk dizilerden oluşan 20'lik dizi, yani sanki 20 tane `y`'den oluşur.
- `w`, 10 elemanlı bir dizidir; her gözü 20x30'luk bir matristir, yani 10 tane `x` tutar. Onun bir gözüne girildiğinde 20 elemanlı bir dizi, onun bir gözüne girildiğinde 30 tamsayı bulunur.

Her durumda ilk indis bellekte bir bloğun başlangıç adresini gösteren kısımdır. Bu mantık kavranırsa ileride C'nin dizi mantığıyla daha rahat çalışılır.

## 9. Çok boyutlu karakter dizileri

### 9.1 Tek boyutlu karakter dizilerinin hatırlatılması

Önceki derste yazılan tek boyutlu karakter dizileri (ekrandan, 01:15:00):

```c
char y[10] = {'y', 'i', 'l', 'd', 'i','z','\0'};
char t[]={'t','e','k','n','i','k','\0'};
char u[15]="universitesi";
```

Karakter karakter verilen dizilerde sona `\0` (null karakter) konmalıdır. `t` için boyut verilmedi, ilk değer atamasından belirlenir. Çift tırnakla verilen dizgide `\0` derleyici tarafından konur. Bunlar tek boyutludur, çünkü yan yana duran karakterlerden oluşurlar; bellekte ASCII kodlarının sayısal değerleri tutulur.

### 9.2 Karakter matrisi

Aynı üç kelime tek bir değişkende tutulabilir (ekrandan, 01:15:00):

```c
char ytu[3][15]={"yildiz", "teknik", "universitesi"};
```

Bu 3x15'lik bir karakter matrisidir. 0, 1, 2 satırları ve 0'dan 14'e kadar sütunları vardır. 0. satırda `y i l d i z \0`, 1. satırda `t e k n i k \0`, 2. satırda `u n i v e r s i t e s i \0` durur. Karakterler 1 bayt olduğu için 3 x 15 = 45 baytlık yer ayrılır, ama bunun yalnız bir kısmı dolu, geri kalanı boşa gider. Dinamik bellek ayırma ile bu verimsizlik giderilebilir, ama kabaca düşünüldüğünde karakter dizilerinden oluşan bir dizi bir matris olarak kurulabilir. Buna çok boyutlu karakter dizisi denir.

## 10. Karakter matrisi üzerinde C denemeleri

Denemeler OnlineGDB ortamında yapıldı.

### 10.1 Satırları tek indisle yazdırmak

Kod (ekrandan, 01:20:00):

```c
#include <stdio.h>
#define N 5

int main()
{
    char a[N][N] = {"ali", "veli","ayse","can" };
    int i;

    for(i=0;i<N;i++)
        printf("%s\n",a[i]);

    return 0;
}
```

Burada matris üzerinde i ve j ile iki döngü kurmak yerine yalnız birinci indis üzerinde gezilir. `a[i]` her satırın başlangıç adresidir; `printf` `%s` ile (ya da `puts(a[i])` ile) oradan başlayıp `\0` görene kadar yazar. Hoca önce `puts` kullandı, sonra aynısını `printf("%s\n", a[i])` ile yaptı. Çıktı: `ali`, `veli`, `ayse`, `can` ve boş beşinci satır. Kod `gcc -Wall` ile derlenip çalıştırıldı.

### 10.2 Boyutu aşan dizge

Hoca son kelimenin yerine 5x5'lik diziye sığmayan uzun bir kelime ("abuzittin") yazdı ve ne olacağını sordu (Örnek Sorular, Soru 1). Program yalnız sığan ilk beş harfi ("abuzi") yazdırdı, geri kalanı yazmadı; derleyici bir uyarı verdi. Hoca, bu ortamın daha ılımlı olduğunu, daha da uzun bir şey yazılırsa değişkenlerin tutulduğu yığının (stack) taşmasıyla hata alınabileceğini söyledi.

> **Hocanın vurgusu:** Ayrılan boyut asla aşılmamalıdır. Bu ortam yalnız uyarı verse de her zaman böyle olmayabilir; doğrudan hata da alabilirsiniz.

> **Ders sonrası not:** Hoca uyarının yığınla ilgili olduğunu söyledi. gcc ile denendiğinde uyarı "initializer-string for array of 'char' is too long (10 chars into 5 available)" biçimindedir: ilk değer atamasında fazla karakterler derleme sırasında atılır, taşma oluşmaz. Satır `\0` içermediği için `abuzi`'nin düzgün yazdırılması, bir sonraki satırın sıfırla dolu olmasına bağlıdır. Çalışma sırasında (ör. döngüyle ya da `scanf` ile) sınır dışına yazmak ise gerçekten başka verilerin üzerine yazar ve tanımsız davranıştır.

### 10.3 Karakter karakter atama ve boş satırlar

Boyut 10'a çıkarıldı ve satırlar karakter karakter verildi (ekrandan, 01:25:00):

```c
char a[N][N]= {
                {'a','l','i','\0'},
                {'v','e','l','i','\0'},
                {'f','a','t','m','a','\0'}
              };
```

Bu, her biri onluk karakter dizisi olan on elemanlı bir karakter dizisidir; yalnız üç satır verildi. İlk denemede ilk değer bloğunda fazladan bir kapanış parantezi kaldığı için derleme hatası alındı (ekrandan, 01:25:00); düzeltilince `ali`, `veli`, `fatma` yazdırıldı. Sonra yazdırma `printf("%d: %s\n", i, a[i])` biçimine çevrildi ve indislerle ne görüleceği soruldu (Örnek Sorular, Soru 2). Döngü `N` kez, yani 0'dan 9'a kadar 10 kez çalıştı ve 3-9 indisli satırlar için yalnız numara yazıldı. İlk değer verilmeyen satırlar boştur, ama döngü yine her birinin üzerinden geçer: açılan alan boş diye işlenmez değildir.

### 10.4 Adres kontrol eden `while` döngüsü

Hoca bir de şunu denedi (ekrandan, 01:30:00):

```c
int i=0;
while (a[i]!='\0'){
    printf("%d: %s\n",i, a[i]);
    i++;
}
```

İlk denemede `i++` unutulduğu için sonsuz döngü oluştu. `i++` eklenince döngü yine durmadı: `a[i]` bir satırın adresidir ve hiçbir zaman null olmaz, bu yüzden döngü dizinin sınırını aşıp yüzlerce satır yazdı (ekranda 300'ü geçen satır numaraları görünür). Hoca bunun doğru bir yol olmadığını, sıfırıncı gözleri kontrol etseydi doğru çalışacağını söyledi.

Ardından `for` döngüsüne dönüldü ve her satırın sıfırıncı elemanı kontrol edildi; böylece yalnız dolu satırlar yazdırıldı (çıktı ekrandan, 01:35:00):

```text
0: ali
1: veli
2: fatma
```

<!-- BELİRSİZ: düzeltilmiş kodun tam satırı karede görünmüyor; altyazıya göre a[i][0] kontrolü eklendi. -->

Aşağıdaki biçim `gcc -Wall` ile derlenip aynı çıktıyı verdi:

```c
for(i=0;i<N;i++)
    if (a[i][0]!='\0')
        printf("%d: %s\n",i, a[i]);
```

Böyle bir kontrol yapılmazsa döngü ayrılan alanın sonuna kadar gider; adres düzgün kontrol edilmezse `while` örneğinde görüldüğü gibi öngörülmeyen davranışlar oluşabilir.

### 10.5 Sütun sütun yazdırma (alıştırma)

Hoca, satırlar yerine sütunlar üzerinde gezmeyi bir alıştırma olarak anlattı ama kodunu yazmadı (ekrandan, 01:35:00). Satırlar `ali`, `veli`, `can` olsun; sütun sütun yazdırılınca çıktı `a v c l e a i l n i` olmalıdır. Yalnız karakter matrisi kullanılacak, yardımcı dizi kullanılmayacaktır. Anlatılan yöntem (sözlü):

- `while` ile, sayaçlar elle artırılarak gezilir. Sütun sayacı sabitken satır sayacı artırılır ve her satırdaki eleman yazdırılır.
- Satır sayacı sona (N'e) gelince sıfırlanır ("sütun başı") ve sütun sayacı bir artırılır.
- Bir satırda `\0` görülünce o göz yazdırılmaz. `\0`'dan sonraki gözlerde ne olduğu bilinmediği için, sütun sayacı son sütuna gelmediyse o satırın bir sonraki gözü de `\0` yapılır. Böylece sonraki turda yine `\0` görülür ve hiçbir şey yazdırılmaz.
- Sütun sayacı sınıra varınca döngüden çıkılır; ekrana yalnız gerçekten dolu harfler sütun sütun yazılmış olur, matrisin kalan gözleri null karakterle dolar.

Null kontrolüyle devam etmek gerektiği için `for` yerine `while` tercih edildi. Hoca algoritmanın ve akış diyagramının öğrencilerce yazılmasını istedi.

## 11. Her satırdaki karakter dizisini ters çevirme

Önceki derste tek bir karakter dizisi ters çevrilmişti; şimdi aynı işlem karakter matrisinin her satırına uygulanır. Gereken değişkenler: döngü değişkenleri `i`, `j`, uzunluk için `k`, takas için `char temp`. Önce "Önce:" başlığıyla satırlar yazdırılır. Sonra her satır için:

- `for(k=0;ytu[i][k];k++);` ile satırdaki karakter dizisinin boyutu bulunur: `ytu[i][k]` null olmadığı sürece `k` artırılır. Hoca bu yöntemin çok iyi bir yöntem olmadığını, ama önceki derste kullanıldığını hatırlattı.
- `k` uzunluktur (`yildiz` için 6); son karakterin indisi `k-1`'dir. `k` döngü sınırında kullanılacağı için azaltılmaz; bunun yerine kopyası `kk = k-1` tutulur.
- `j`, 0'dan `k/2`'ye kadar gider. Tamsayı bölmesi olduğu için uzunluk tekse ortadaki karakter yerinde kalır, bu sorun değildir.
- Üç satırlık takas: `temp=ytu[i][j]; ytu[i][j]=ytu[i][kk]; ytu[i][kk]=temp;` ve ardından `kk--`. `kk--` `for` başlığına virgülle de yazılabilirdi, ama gövdede yazmak daha temiz ve algoritmik bulundu.

Kod ekrandan alındı (01:45:00 ve 01:50:00); son hâlinde `N` sabit yapılıp yeni kelimeler eklenmişti:

```c
#include <stdio.h>
#define N 7

int main()
{
    char ytu[N][15]={"i","love","yildiz","teknik","universitesi","so","gut"};

    int i,j, k, kk;
    char temp;

    printf("Once:\n");
    for(i=0;i<N;i++)
        printf("%s\n",ytu[i]);

    for(i=0;i<N;i++){
        for(k=0;ytu[i][k];k++); // i.satirdaki karakter dizisinin boyutu:k
        kk=k-1;

        for (j=0;j<k/2;j++){
            temp=ytu[i][j];
            ytu[i][j]=ytu[i][kk];
            ytu[i][kk]=temp;
            kk--;
        }

    } //for i

    printf("\nSonra:\n");
    for(i=0;i<N;i++)
        printf("%s\n",ytu[i]);

    return 0;
}
```

Ekranda `N` 10 olarak tanımlıydı ve 7 dizge verilmişti, bu yüzden çıktıda boş satırlar da vardı. Aşağıda `N` 7 alınarak derlendi; "Sonra:" kısmı ekrandaki sonuçla aynıdır (ekrandan, 01:50:00):

```text
Sonra:
i
evol
zidliy
kinket
isetisrevinu
os
tug
```

Hoca tek karakterli ("i"), iki karakterli ("so") ve üç karakterli ("gut") dizgilerle de deneyerek algoritmanın doğru çalıştığını gösterdi. Kod `gcc -Wall` ile derlenip çalıştırıldı ve aynı çıktı alındı.

## 12. Değişken izleme tablosu

Bir öğrencinin sorusu üzerine hoca, bir algoritmanın doğru çalışıp çalışmadığını göstermek için değişkenlerin aldığı değerlerin izlenmesini ters çevirme örneği üzerinde gösterdi. Bu, Big-O gibi bir algoritma analizi değil, değişken değerlerinin adım adım takibidir. Değişkenler `i`, `j`, `k`, `kk` ve `ytu[i]` sütunlarına yazılır (yaklaşık başlangıç, ara adım eklendi):

| i | j | k | kk (takas anında) | ytu[i] (takastan sonra) |
|---|---|---|---|---|
| 0 | - | 6 | 5 | yildiz |
| 0 | 0 | 6 | 5 | zildiy |
| 0 | 1 | 6 | 4 | zildiy |
| 0 | 2 | 6 | 3 | zidliy |

Hoca tahtada `yildiz` için başladı ve yer değiştirmelerin adım adım nasıl ilerlediğini gösterdi. Hocanın anlattığı ilk adımda `k` için 6 ve 7 değerleri karıştı (null karakter dahil sayıldığında 7). <!-- BELİRSİZ: hocanın tahtada yazdığı k ve kk değerleri altyazıda tutarsız; tablo kodun gerçek davranışına göre yazıldı. --> Gerekirse `temp` değeri ve dizinin son hâli de tabloya eklenebilir.

> **Ek bilgi (derste anlatılmadı):** Kodda `k`, `\0`'dan önceki karakter sayısıdır; `yildiz` için 6'dır ve `kk` 5'ten başlar. İkinci adımda iki `i` harfi yer değiştirdiği için dizge değişmez. Üçüncü adımda (`j=2`) ortadaki `l` ve `d` yer değiştirir; `j<3` olduğu için döngü bu adımdan sonra biter. Tablodaki son satır bu takastan sonraki hâli gösterir.

## Örnek Sorular

**Soru 1** (ekrandan, 01:20:00; derste sözlü, 01:20:47): `#define N 5` ile `char a[N][N] = {"ali","veli","ayse","abuzittin"};` tanımlanıp `for(i=0;i<N;i++) printf("%s\n",a[i]);` çalıştırılırsa ekranda ne görülür? "abuzi" mi, "abuzittin" mi yazılır, yoksa hata mı alınır?

> **Çözüm (derste gösterildi):** Program `ali`, `veli`, `ayse`, `abuzi` yazar; sığmayan kısım saklanmaz. Derleyici dizinin çok uzun bir dizgeyle ilklendirildiğine dair uyarı verir. gcc ile de aynı sonuç alındı.

**Soru 2** (ekrandan, 01:25:00; derste sözlü, 01:25:47): `#define N 10` ile `char a[N][N]` matrisine yalnız `ali`, `veli`, `fatma` karakter karakter verilmiştir. `for(i=0;i<N;i++) printf("%d: %s\n", i, a[i]);` ne yazdırır?

> **Çözüm (derste gösterildi):** `0: ali`, `1: veli`, `2: fatma` yazar, ardından 3'ten 9'a kadar her satır için yalnız numara (`3: `, ..., `9: `) yazar; çünkü döngü açılan alanın tamamını, yani 10 satırı gezer ve boş satırlar boş dizge olarak yazdırılır.

**Soru 3** (ekrandan, 01:30:00): `while (a[i] != '\0') { printf("%d: %s\n", i, a[i]); i++; }` döngüsü neden üç satırda durmaz?

> **Çözüm (derste gösterildi):** `a[i]` satırın karakteri değil, satırın başlangıç adresidir ve hiçbir zaman null olmaz. Bu yüzden koşul hep doğrudur ve döngü dizinin sınırını aşar. Satırın ilk karakteri `a[i][0]` kontrol edilmelidir.

**Soru 4** (ekrandan, 01:35:00): `char` matrisinde `ali`, `veli`, `can` satırları vardır. Yalnız bu matrisi kullanarak harfleri sütun sütun yazdırın; beklenen çıktı `a v c l e a i l n i`'dir.

> **Çözüm (derste verilmedi):** Hoca yalnız yöntemi anlattı (bkz. 10.5). Aşağıdaki çözüm ajan tarafından yazıldı ve `gcc -Wall` ile derlenip `a v c l e a i l n i` çıktısı alındı. Burada satırın sonuna gelinip gelinmediği, o satırın 0'dan j'ye kadar gözlerinde `\0` olup olmadığına bakılarak anlaşılır; böylece hocanın yöntemindeki gibi `\0`'dan sonraki bilinmeyen karakterler yazdırılmaz.

```c
#include <stdio.h>
#define S 3
#define U 15

int main()
{
    char a[S][U]={"ali","veli","can"};
    int i, j, k, bitti;

    for(j=0;j<U;j++)
        for(i=0;i<S;i++){
            bitti=0;
            for(k=0;k<=j;k++)
                if(a[i][k]=='\0'){ bitti=1; break; }
            if(!bitti) printf("%c ",a[i][j]);
        }
    printf("\n");
    return 0;
}
```

**Soru 5** (derste sözlü, 01:06:09 ve 01:07:04): Matris çarpımı programına m-n = 2 2, A = 1 2 3 4, p-q = 2 2, B = 5 6 7 8 girilirse çıktı ne olur?

> **Çözüm (derste gösterildi):** `19 22` / `43 50`. Hesap: $1\cdot5+2\cdot7=19$, $1\cdot6+2\cdot8=22$, $3\cdot5+4\cdot7=43$, $3\cdot6+4\cdot8=50$.

## Dersin Toparlaması

Bu derste tek boyutlu dizilerden çok boyutlu dizilere geçildi. Çok boyutlu dizi mantıksal olarak satır-sütun düzenindedir, ama bellek tek boyutlu olduğu için C'de satır öncelikli ve ardışık olarak saklanır. `int a[5][2]` gibi bir tanım "her biri ikilik dizi olan beşlik dizi" diye okunur; `a[i]` satırların başlangıç adresini verir ve sol taraf değeri değildir. Bu bakış, ilk değer atamasının iki biçimini, bellekteki adres hesabını ve `w[10][20][30]` gibi daha çok boyutlu tanımları anlamayı kolaylaştırır.

Uygulama olarak matris toplama (iki iç içe döngü) ve matris çarpımı (çarpılabilirlik şartı ve üç iç içe döngü) akış diyagramı ve C koduyla yazıldı. Ardından çok boyutlu karakter dizileri işlendi: her satır bir karakter dizisidir, tek indisle `%s` kullanılarak yazdırılabilir; boyut aşımı, boş satırlar ve adres-karakter karışıklığı denemelerle gösterildi. Son olarak her satırdaki dizgeyi ters çeviren kod yazıldı ve değişkenlerin adım adım izlenmesi gösterildi. Sütun sütun yazdırma algoritmasının ve akış diyagramının yazılması alıştırma olarak bırakıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
