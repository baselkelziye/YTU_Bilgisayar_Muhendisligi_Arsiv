# Ders 11 Genişletilmiş Notu: Uygulama: Dinamik Bellekle Metin Şifreleme ve Eratosthenes Kalburu

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Oturumun amacı
- 2. Soru 1: Metni resme gömen şifreleme algoritması
- 3. Şifreleme programının adım adım yazılması
- 4. Satır satır realloc ile büyütme ve çökme
- 5. Şifre çözme (decode) programı
- 6. İki boyutlu dinamik dizi nasıl düşünülür?
- 7. Soru 2: Eratosthenes Kalburu
- 8. Kalbur programının adım adım yazılması
- 9. Hatanın yeniden ele alınması ve kod okunabilirliği
- Örnek Sorular

## 1. Oturumun amacı

Bu kayıt teori dersi değil, bir uygulama (lab) oturumudur. Oturumda iki uygulama sorusu Dev-C++ ortamında baştan sona birlikte kodlandı. Birinci soru bir metni sayılardan oluşan kare bir "resme" gömen ve bu resimden metni geri çıkaran iki programdan oluşur. İkinci soru Eratosthenes Kalburu algoritmasıyla bir sayının altındaki bütün asal sayıları bulan bir programdır. İki sorunun ortak noktası, derslerde işlenen dinamik bellek yönetimidir: `malloc`, `calloc`, `realloc`, `free`, `NULL` denetimi ve `int **` ile iki boyutlu dizi kurmak.

Oturumu yürüten, soruları önce ekrana yansıttı, öğrencilerden sorunun ekran görüntüsünü almalarını istedi, sonra kodu yazarken her adımı açıkladı. Öğrenciler de aynı anda kendi bilgisayarlarında kodladı ve sorularını sesli sordu.

## 2. Soru 1: Metni resme gömen şifreleme algoritması

### 2.1 Sorunun metni

Ekranda gösterilen soru şöyledir (ekrandan, 00:10:00 ve 01:10:00):

> Bir şifreleme algoritması; harflerin ASCII karşılıklarından oluşan MxM matristen bir image yaratıyor. (Matrisin her bir hücresi 0-255 arasında bir pixel değeri olarak gelmektedir. Bir pixelin değeri "0" ise bu pixelde harf olmadığı anlamına gelir.) Kelimenin ilk harfi 0x0 hücresinde, ikinci harfi 0x1 ... şeklinde saklanıyor.
>
> Bir metni şifreleyen ve şifreli metnin şifresini çözen birer algoritmayı C dilinde gerçekleyelim.
>
> NOT: Stringin uzunluğu önceden bilinmediği varsayılacaktır.

<!-- BELİRSİZ: Soru metninin sağ kenarı karede kesik; "değeri olarak gelmektedir" ve "anlamına gelir" sözcük sonları kareden tam okunamadı, altyazıdaki anlatımla tamamlandı. -->

Örnek girdi ve çıktı olarak `"YILDIZTEKNIK"` metni ve şu matris verildi (ekrandan, 00:10:00):

| | 0 | 1 | 2 | 3 |
|---|---|---|---|---|
| 0 | 89 | 73 | 76 | 68 |
| 1 | 73 | 90 | 84 | 69 |
| 2 | 75 | 78 | 73 | 75 |
| 3 | 0 | 0 | 0 | 0 |

Matrisin yanında bu değerlerin gri tonlu bir resim olarak nasıl göründüğü de gösterildi: değerler 255'e göre küçük olduğu için resim neredeyse tamamen siyahtır.

### 2.2 Sorunun yorumu

Anlatıma göre harfler satır satır yerleşir: ilk dört harf `[0][0]`, `[0][1]`, `[0][2]`, `[0][3]` hücrelerine yazılır, beşinci harf `[1][0]` hücresine geçer. Metnin harf sayısı hücre sayısından azsa kalan hücrelere 0 yazılır. Uzunluk önceden bilinmediği için kullanıcıdan alınır.

Kod yazılmadan önce hangi değişkenlere ihtiyaç olduğu tartışıldı. Metnin uzunluğunu tutan bir değişken gerekir. Uzunluk alındıktan sonra, bu kadar harfin sığacağı en küçük $M$ değeri bulunmalıdır: harf sayısı $M^2$'den büyük olmamalıdır.

**Soru:** Resim kare olmak zorunda mı?
**Cevap:** Evet. Soru $M \times M$ boyutunda bir matristen söz ediyor.

## 3. Şifreleme programının adım adım yazılması

### 3.1 Değişkenler ve metnin okunması

Program şu tanımlarla başladı (ekrandan, 00:20:00 ve 00:25:00):

```c
int textSize, m, i, j;
// text dizisi 1D boyutundadır. Kullanıcıdan alınacak kelimenin tutulduğu array.
char *text, junk;
int **theImage;

printf("Enter the length of text to encrypt \n");
scanf("%d",&textSize);

text = (char *)(malloc)(sizeof(char)*textSize);
theImage=(int**)(calloc)(1,sizeof(int*));
theImage[0]= (int*)(calloc)(1,sizeof(int));
```

`text` tek boyutlu bir dizidir ($1 \times$ `textSize`), kullanıcının girdiği kelimeyi tutar. `theImage` ise matristir; ilk anda yalnız bir satır ve o satırda bir eleman olacak şekilde açıldı. Bunun nedeni, boyutun daha sonra ihtiyaç oldukça `realloc` ile büyütülecek olmasıdır.

Metin şu üç satırla okundu (ekrandan, 00:25:00):

```c
printf("Enter the text \n");
scanf("%c",&junk);
scanf("%[^\n]", text);
// Alternatif scanf("%s", text)
```

İlk `scanf("%d", ...)` sayıyı okuduktan sonra girdi tamponunda Enter'ın bıraktığı satır sonu karakteri kalır. `junk` değişkeni bu karakteri yutmak için kullanılır; böylece metin okuması boş bir satırla bitmez.

**Soru:** `scanf` içindeki köşeli parantez nasıl çalışıyor?
**Cevap:** `%[^\n]`, Enter (yani `\n`) karakterini görene kadar yazılan her şeyi alır. Alternatif olarak `scanf("%s", text)` da kullanılabilir; bu durumda girilen string doğrudan alınır.

> **Ek bilgi (derste anlatılmadı):** `%s` boşlukta durur; "YILDIZ TEKNIK" gibi boşluklu bir metinde yalnız "YILDIZ" okunur. `%[^\n]` ise boşlukları da alır. İkisi de sona `'\0'` ekler, bu yüzden dizide metin uzunluğundan bir fazla yer olmalıdır.

Oturumu yürüten başlangıçta her satıra yorum yazıyordu; zamanın yetmesi için uzun yorumlardan vazgeçildi.

### 3.2 $M$ değerinin hesaplanması

$M$ şu satırla bulundu (ekrandan, 00:25:00):

```c
m = ceil(sqrt(textSize));
```

`sqrt` ve `ceil` fonksiyonlarının kullanılabilmesi için `#include <math.h>` eklendi.

**Soru:** `ceil` fonksiyonu ne işe yarıyor?
**Cevap:** Bir üst tam sayıya yuvarlar. `YILDIZTEKNIK` 12 harftir. $\sqrt{12} \approx 3{,}46$ çıkar, `ceil` bunu 4 yapar. $M = 4$ olunca $4 \times 4 = 16$ hücreli matrise 12 harf sığar.

**Soru:** $M$'yi matrisi tanımladıktan sonra bulduk. Önce $M$'yi bulup matrisi doğrudan $M \times M$ boyutunda açsaydık daha iyi olmaz mıydı?
**Cevap:** Öyle de yapılabilir, daha pratik olur. Burada `realloc` ile matrisin boyutunun yeniden düzenlenebildiğini de görmek için bu yol seçildi.

### 3.3 Matrisin doldurulması

Matrisi dolduran iç içe döngüler şöyle yazıldı (ekrandan, 00:30:00, 00:35:00 ve 00:40:00):

```c
// text dizisi için indexdir.
k=0;
for(i=0; i < m; i++)
{
    theImage=(int**)realloc(theImage, (i+1)*sizeof(int*));
    for(j=0; j < m; j++)
    {
        theImage[i]=(int*)realloc(theImage[i],(j+1)*sizeof(int));
        if(k <textSize)
        {
            pixel = (int)text[k];
            theImage[i][j] = pixel;
        }
        else
        {
            theImage[i][j] = 0;
        }
        k++;
    }
}
```

<!-- BELİRSİZ: else bloğunun satırları (38-41) karelerde görünmüyor; altyazıdaki "değilse ... sıfır olacak" anlatımından kuruldu. -->

Dış döngüde `i` satırı, iç döngüde `j` sütunu temsil eder. Dış döngünün her adımında `theImage` bir satır büyütülür; `i` sıfırdan başladığı için yeni boyut `i + 1` satırdır. İç döngüde de o satır `j + 1` elemana büyütülür.

`k`, metindeki sıradaki harfin indeksidir. $4 \times 4$ matriste 16 hücre vardır ama kelime 12 harftir. `k` 12'ye ulaştığında artık matrise yazılacak harf kalmamıştır; bu hücrelere 0 yazılır. `k < textSize` ise harfin tam sayı değeri, yani ASCII kodu, piksel değeri olur: `(int)text[k]`. `k` iç döngünün sonunda, her hücreden sonra bir artırılır.

Yazım sırasında bir öğrenci, ilk tanımda `theImage`'in yanlışlıkla üç yıldızlı yazıldığını fark etti; çift işaretçi (`int **`) olması gerektiği söylenerek düzeltildi. Başka bir öğrenci `k`'nin artırılmadığını sordu; artırmanın iç döngünün sonunda yapılacağı gösterildi.

### 3.4 Matrisin basılması

Sonuç şöyle basıldı (ekrandan, 00:35:00):

```c
printf("The Image is: \n");
for(i=0; i< m; i++){
    for(j=0; j<m; j++){
        printf("%3d ", theImage[i][j]);
    }
    printf("\n ");
}

free(theImage);
free(text);
```

**Soru:** `%3d` sayıyı 3 basamakta yazıyor, sıralar kaymasın diye mi?
**Cevap:** Evet. Sayı için 3 karakterlik alan bırakılır: sayı 1 ise iki boşluk ve 1, 12 ise bir boşluk ve 12 yazılır. Böylece matris hizalı görünür.

Program `ASCII` değerlerini doğru üretir: `'Y'` = 89, `'I'` = 73, `'L'` = 76, `'D'` = 68, `'Z'` = 90, `'T'` = 84, `'E'` = 69, `'K'` = 75, `'N'` = 78. Bu değerler python ile doğrulandı ve ekrandaki matrisle aynıdır.

> **Ders sonrası not:** Dersteki kodda `text` için `textSize` bayt ayrıldı. `scanf("%[^\n]", text)` metnin sonuna bir de `'\0'` yazdığı için 12 harflik metin 13 bayt ister; doğrusu `malloc(sizeof(char) * (textSize + 1))` biçimindedir. Ayrıca `free(theImage)` yalnız satır işaretçilerinin bloğunu bırakır; önce her `theImage[i]` ayrı ayrı `free` edilmelidir. Ajanın AddressSanitizer denemesinde birinci sorun taşma olarak görüldü.

### 3.5 Geliştirme ortamı sorunu

Kod hatasız derlendiği halde program çalışmadı. Dev-C++'ta açık kalan nesne dosyası (`main2.o`) kapatıldı, Execute menüsünden "Clean" yapıldı. Sonunda kaynak dosya masaüstüne yeniden kaydedilince program çalıştı. Açıklama şuydu: kaynak dosya işletim sisteminin korumalı bir klasörüne kaydedilmişse derleyicinin çıktısı engellenebilir.

## 4. Satır satır realloc ile büyütme ve çökme

### 4.1 Gözlenen durum

Program `12` ve `YILDIZTEKNIK` girilince metni okudu, sonra matrisi hesaplarken hata verdi. Oturumu yürüten kendi bilgisayarında aynı kodun daha önce çalıştığını söyledi. Öğrencilerden gelen bilgiler de karışıktı: bazılarında kod çalışıyordu, bazılarında çalışmıyordu. Bir öğrenci beş harfli bir kelimeyle kodun çalıştığını, `YILDIZTEKNIK` ile çalışmadığını bildirdi; $3 \times 3$ için de çalıştığı görüldü.

Hata ayıklayıcıyla (debug) ilerlenince hatanın, yeni bir satıra geçildiğinde iç döngüdeki `realloc` satırında oluştuğu görüldü. O an verilen açıklama, `j`'nin yeni satırda tekrar 0'dan başlamasıyla ilgili bir bellek erişimi sorunu olduğuydu.

### 4.2 Derste uygulanan çözüm

Bir öğrencinin baştaki önerisine dönüldü: kelimenin uzunluğu ve dolayısıyla $M$ belli olduğuna göre matris tek seferde $M \times M$ ayrılabilir. Satır 17-18'deki ilk ayırma satırları $M$ hesaplandıktan sonraya taşındı ve boyut olarak $M$ verildi; döngü içindeki `realloc` satırları yoruma alındı. Düzeltilmiş program aşağıdadır.

```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int textSize, m, i, j, k, pixel;
    char *text, junk;
    int **theImage;

    printf("Enter the length of text to encrypt \n");
    scanf("%d", &textSize);

    text = (char *)malloc(sizeof(char) * textSize);

    printf("Enter the text \n");
    scanf("%c", &junk);
    scanf("%[^\n]", text);

    m = ceil(sqrt(textSize));
    theImage = (int **)calloc(m, sizeof(int *));
    for (i = 0; i < m; i++) {
        theImage[i] = (int *)calloc(m, sizeof(int));
    }

    k = 0;
    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            if (k < textSize) {
                pixel = (int)text[k];
                theImage[i][j] = pixel;
            } else {
                theImage[i][j] = 0;
            }
            k++;
        }
    }

    printf("The Image is: \n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            printf("%3d ", theImage[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < m; i++)
        free(theImage[i]);
    free(theImage);
    free(text);
    return 0;
}
```

Bu tam program ajan tarafından karelerden yeniden kuruldu: `calloc` ile tek seferde ayırma derste yapılan değişikliktir; satırların `free` edilmesi ve son `printf("\n")` küçük düzeltmelerdir. `gcc -Wall` ile uyarısız derlendi; `12` ve `YILDIZTEKNIK` girdisiyle ekrandaki matrisi verdi. `malloc` satırındaki bir baytlık eksik (bkz. 3.4) derstekiyle aynı bırakıldı.

Asıl hatanın nedeni ders sonunda yeniden konuşuldu (bkz. Bölüm 9).

## 5. Şifre çözme (decode) programı

### 5.1 Programın kurulması

Şifre çözmede kullanıcı matrisi girer, program metni geri verir. Zaman azaldığı için bu bölüm daha hızlı yazıldı. Önce değişkenler tanımlandı: döngüler için `i`, `j`, matrisin kenarı için `m`, okunan piksel değeri için `pixel` ve metin dizisinde kullanılacak, sıfırdan başlayan `textIndex` (ekrandan, 00:55:00 ve 01:05:00).

```c
int n,m,i,j,pixel,textIndex=0;
char *text;
int **theImage;

printf("Enter Image Size: M \n");
scanf("%d", &m);

text = (char *)(malloc)(sizeof(char));

theImage=(int**)(calloc)(m,sizeof(int*));
for(i=0; i< m; i++){
    theImage[i]= (int*)(calloc)(m,sizeof(int));
}
```

Resmin içinde kaç harf saklı olduğu bilinmediği için `text` yalnız bir elemanlı açıldı; harf buldukça büyütülecek. Matris ise bu kez birinci programdaki sorun yüzünden doğrudan $M \times M$ ayrıldı: önce satır sayısı kadar `int *`, sonra her satıra $M$ tane `int`.

**Soru:** `argc` ve `argv` ne oluyor?
**Cevap:** `main` fonksiyonunun, programı işletim sistemi çalıştırırken kullanılan parametreleridir; ayrıntısına bu oturumda girilmedi.

### 5.2 Piksellerin okunması

Kullanıcıdan hangi hücreyi girdiğini görmesi için `(i, j) = ` biçiminde bir istem basıldı (ekrandan, 01:00:00):

```c
printf("Enter The Pixel Values from top-left to bottom-right\n");
for(i=0; i < m; i++){
    for(j=0; j < m; j++){
        printf("(%d, %d) = ", i, j);
        scanf("%d", &pixel);
        theImage[i][j]=pixel;
    }
}
```

### 5.3 Metnin geri kurulması

İkinci döngüde her hücre için metin dizisi bir karakter büyütüldü, piksel değeri `(char)` ile karaktere çevrilip eklendi ve `textIndex` artırıldı (ekrandan, 01:10:00):

```c
for(i=0; i < m; i++){
    for(j=0; j < m; j++){
        text=(char*)(realloc)(text,sizeof(char)*(textIndex+1));
        text[textIndex]=(char)theImage[i][j];
        textIndex++;
    }
}

printf("The Text That Was Hidden Into The Image ...", text);
free(theImage);
```

<!-- BELİRSİZ: realloc satırındaki boyut ifadesinin sonu ve son printf'in biçim dizgesi karede kesik; (textIndex+1) ve "%s" altyazıdaki "bir karakter boyutunda genişletmiş" anlatımına göre tamamlandı. -->

Program $M = 4$ ve ekrandaki 16 değer (89, 73, 76, 68, 73, 90, 84, 69, 75, 78, 73, 75, 0, 0, 0, 0) girilerek denendi ve `YILDIZTEKNIK` geri elde edildi.

Ajanın tam sürümü (aynı mantık, satırların `free` edilmesi eklendi) `gcc -Wall` ile uyarısız derlendi ve aynı girdiyle `YILDIZTEKNIK` çıktısını verdi:

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int m, i, j, pixel, textIndex = 0;
    char *text;
    int **theImage;

    printf("Enter Image Size: M \n");
    scanf("%d", &m);

    text = (char *)malloc(sizeof(char));

    theImage = (int **)calloc(m, sizeof(int *));
    for (i = 0; i < m; i++) {
        theImage[i] = (int *)calloc(m, sizeof(int));
    }

    printf("Enter The Pixel Values from top-left to bottom-right\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            printf("(%d, %d) = ", i, j);
            scanf("%d", &pixel);
            theImage[i][j] = pixel;
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            text = (char *)realloc(text, sizeof(char) * (textIndex + 1));
            text[textIndex] = (char)theImage[i][j];
            textIndex++;
        }
    }

    printf("The Text That Was Hidden Into The Image: %s\n", text);
    for (i = 0; i < m; i++)
        free(theImage[i]);
    free(theImage);
    free(text);
    return 0;
}
```

### 5.4 Özet ve iyileştirme önerileri

Bir öğrencinin isteğiyle program baştan özetlendi. Önce matrisin boyutu sorulur, çünkü kaça kaçlık bir matristen söz edildiği bilinmeden hiçbir şey ayrılamaz. Sonra metin dizisi bir elemanlı, matris $M \times M$ açılır. Pikseller iki iç içe döngüyle okunur; `i` satır, `j` sütun indeksidir. Okuma ve dönüştürme iki ayrı döngü çiftinde yapıldı. Okurken dönüştürmek de mümkündü, ama kod daha okunabilir olsun diye ayrıldı.

Bir iyileştirme önerildi: hücredeki değer 0 ise bu bir harf değildir, `text` dizisini onun için büyütmeye gerek yoktur. Dersteki kodda 0'lar için de dizi büyütülür; 0 değeri görünür bir karakter olmadığı için çıktıda fark edilmez.

> **Ek bilgi (derste anlatılmadı):** 0 değerli hücreler metne `'\0'` olarak girer ve `printf("%s", ...)` metni orada bitirir. Örnekte son satır 0 olduğu için metin doğru biter. Harf sayısı tam $M^2$ olsaydı (örneğin 9 harf, $M = 3$) dizide hiç `'\0'` olmazdı; bu durumda döngüden sonra bir eleman daha açıp `'\0'` yazmak gerekir.

## 6. İki boyutlu dinamik dizi nasıl düşünülür?

**Soru:** 19. satırda `theImage[i]` tek köşeli parantezle yazılıyor, 27. satırda `theImage[i][j]` iki köşeli parantezle. Bu bir matrisse 19. satırda nasıl tek parantez kullanılıyor?

**Cevap:** Konu Paint'te çizilerek anlatıldı. Önce $M$ elemanlı bir dizi tanımlanır; örnekte 4 eleman. Tek boyutlu bir `A` dizisinin elemanına tek indeksle erişilir. Burada ise bu dizinin her elemanının içine ayrıca bir dizi tanımlanır; o da 4 elemanlıdır. `theImage[i]`, dış dizinin `i`'nci elemanıdır ve kendisi bir dizidir (bir `int *`). Bu yüzden ona `calloc` ile yer ayırırken tek parantez yeterlidir. Ayrılan satırın içindeki elemana ise iki indeksle, `theImage[i][j]` ile erişilir. Kafada canlandırılan $4 \times 4$ tablo (sıfıra sıfır, sıfıra bir ...) bunun görsel karşılığıdır; bellekteki gerçek yapı ise "her elemanı bir dizi olan dizi"dir.

## 7. Soru 2: Eratosthenes Kalburu

### 7.1 Sorunun metni

İkinci soru ekranda gösterildi ve sesli okundu (derste sözlü, 01:15:38): Eratosthenes Kalburu (Sieve of Eratosthenes) algoritmasını kullanarak, kullanıcının girdiği tam sayının altında kalan bütün asal sayıları hesaplayan bir program yazılacaktır. Maddeler şunlardır:

- Altında kalan asal sayıların hesaplanacağı tam sayı ($n$) kullanıcıdan alınır.
- Hesaplama sonunda bulunan asal sayılar yeni bir dizide tutulur; bu dizinin boyutu bulunan asal sayı kadar olur.
- Program çıktısı örnekteki gibi görünmelidir.

<!-- BELİRSİZ: İkinci sorunun PDF metni hiçbir karede görünmüyor; maddeler ve örnek çıktı biçimi altyazıdan ve programın çıktı satırlarından kuruldu. -->

### 7.2 Algoritma

Algoritma $n = 10$ üzerinden anlatıldı:

1. 2'den $n$'ye kadar bütün sayılar bir listeye yazılır: 2, 3, 4, 5, 6, 7, 8, 9, 10. (Bunlar doğrudan dizide tutulabilir ya da indeks olarak kullanılabilir.)
2. O an kontrol edilen asal sayıya $a$ denir. İlk değer $a = 2$'dir.
3. $a^2 \le n$ olduğu sürece $a$'nın katları listeden elenir; $a$'nın kendisine dokunulmaz.
4. Elenmemiş en küçük sonraki sayı yeni $a$ olur ve 3. adıma dönülür.
5. $a^2 > n$ olunca durulur; listede kalanlar asaldır.

$n = 10$ için adımlar:

- $a = 2$: $2^2 = 4 \le 10$. 4, 6, 8, 10 elenir.
- $a = 3$: $3^2 = 9 \le 10$. 6 ve 9 elenir (6 zaten elenmişti).
- 4 elenmiş olduğu için sonraki $a = 5$'tir: $5^2 = 25 > 10$, hesaplama biter.
- Kalan sayılar: 2, 3, 5, 7.

## 8. Kalbur programının adım adım yazılması

### 8.1 Türkçe karakter için setlocale

Önce konsolda Türkçe karakter göstermek için şu satır gösterildi (ekrandan, 01:25:00):

```c
#include <locale.h>
...
setlocale(LC_ALL, "Turkish");
```

Bu satır yazılınca istemdeki "ı", "ş" gibi harfler konsolda doğru göründü.

### 8.2 Değişkenler

```c
int n, i, j, prime_count, *primes;
char *prime_states;
```

`n` kullanıcıdan alınan sayıdır. `prime_count` kaç asal sayı bulunduğunu, `primes` bulunan asal sayıları (örneğin 2, 3, 5, 7) tutar. `prime_states` ise her sayının asal olup olmadığını tutan bayrak dizisidir.

Bayrak dizisinin neden `char` olduğu açıklandı: C'de tanımlanabilen en küçük veri tipi 1 bayttır; keşke bit tutabilseydik. Bir sayının asal olup olmadığı doğru/yanlış (boolean) bir bilgidir: asalsa 1, değilse 0 tutulur. 1 ve 0 `char` boyutuna sığar. Tipin adı `char` diye illa harf tutmak zorunda değildir; karakterler de bellekte sayısal değerleriyle saklanır.

### 8.3 Girdi, n-- ve bellek ayırma

Kod şöyle sürdü (ekrandan, 01:30:00 ve 01:35:00):

```c
printf("Sieve of Eratosthenes algortitmasını kullanarak asal sayı\noluşturmak için bir n tamsayısı girinini : ");
scanf("%d", &n);
n--;
prime_states = (char*)malloc (n*sizeof(char));
if(primes_states == NULL)
{
    printf("Bellekte alan oluşturulamadı.");
    exit(0);
}
```

`n` bir azaltılır. Liste 2'den başladığı için 1 sayısını dizide tutmanın anlamı yoktur, 1 zaten asal değildir. $n = 10$ girildiğinde `n = 9` olur ve dizi 2..10 arasındaki 9 sayıyı tutar.

`malloc` sonrasında `NULL` denetimi yapıldı: bellekte yeterli alan ayrılamazsa işaretçi `NULL` olur. Bu durumda mesaj basılıp `exit` ile çıkılır; bu kalıp ders sunumlarında da vardır.

> **Ders sonrası not:** Karede `if` satırında değişken adı `primes_states` diye yazılmış görünüyor (01:30:00 ve 01:35:00); tanımlı ad `prime_states` olduğu için bu hâliyle derlenmez. Program çalıştırılmadan önce büyük olasılıkla düzeltildi. Ajanın sürümünde `prime_states` kullanıldı.

### 8.4 Bütün sayıları asal işaretlemek

Algoritmaya göre başlangıçta bütün sayılar asal kabul edilir:

```c
for(i=0; i<n; i++){
    prime_states[i]=1; // 1 = asal sayı demektir.
}
```

### 8.5 İndeks kaydırma: i, i + 2'yi temsil eder

Döngülere geçmeden önce dizinin yapısı Paint'te çizildi. $n = 10$ için 9 eleman vardır, indeksler 0..8'dir ve hepsine 1 yazılmıştır. Ama 0. indekse 1 yazmak 0 sayısını asal saymak demek değildir. Kontrol edilmek istenen sayılar 2, 3, ..., 10'dur. Yani 0. indeks 2'yi, 1. indeks 3'ü, 2. indeks 4'ü temsil eder: **sayı = indeks + 2**.

> **Hocanın vurgusu:** Burası önemli. Bu kaydırma anlaşıldıktan sonra bütün hesaplar aynı mantıkla sürer.

Bu yüzden $a^2 \le n$ koşulu kodda `(i+2)*(i+2) <= n+1` olur: `i + 2` asıl sayıdır, `n + 1` de azaltılmadan önceki $n$ değeridir.

### 8.6 Kalbur döngüsü

```c
for(i=0; (i+2)*(i+2)<=n+1; i++){
    if(prime_states[i] == 1)
    {
        for(j = (i+2)*(i+2); j <= n+1; j+=i+2)
        {
            prime_states[j-2] = 0;
        }
    }
}
```

(ekrandan, 01:40:00)

Dış döngü yalnız hâlâ asal işaretli sayılarla çalışır: algoritmaya göre "kontrol edilebilir en küçük sayı" asal kalmış sayıdır; elenmiş bir sayının katlarını elemeye gerek yoktur.

İç döngüde `j` asıl sayıları dolaşır. $a = 2$ için `j` önce $2^2 = 4$ olur, sonra her adımda `i + 2 = 2` artar: 4, 6, 8, 10. Her biri asal değil diye işaretlenir. Ama dizide bir sayının bayrağı, sayının 2 eksiği olan indekste durur; 4'ün bayrağı 2. indekstedir. Bu yüzden `prime_states[j-2] = 0` yazılır. $j = 12$ olunca `j <= n + 1 = 10` koşulu bozulur ve iç döngü biter.

> **Ek bilgi (derste anlatılmadı):** Katları elemeye $a$'nın kendisinden değil $a^2$'den başlamak yeterlidir, çünkü $a^2$'den küçük katlar ($2a$, $3a$, ...) daha küçük bir asal çarpana sahiptir ve daha önce elenmiştir. Aynı nedenle dış döngü $a^2 \le n$ iken durur.

### 8.7 Asalları saymak ve yeni diziye koymak

```c
prime_count=0;
for(i=0; i<n; i++){
    if(prime_states[i]==1)
        prime_count++;
}
```

Asal sayısı ancak şimdi bilindiği için `primes` dizisi tam bu boyutta ayrıldı ve yine `NULL` denetimi yapıldı. Ardından dizi dolduruldu (ekrandan, 01:45:00):

```c
j=0;
for(i=0; i<n; i++)
{
    if(prime_states[i] == 1)
    {
        primes[j] = i + 2;
        j++;
    }
}
```

<!-- BELİRSİZ: primes için malloc ve NULL denetimi satırları (42-49) karelerde görünmüyor; altyazıdaki "boyutunu tanımlıyoruz ... tekrar kontrol edeceğiz ama bu sefer prime için" anlatımına göre kuruldu. -->

Burada yine `i + 2` yazılır: `primes` dizisi asal sayıların gerçek değerlerini tutar, `i` ise yalnız bayrak dizisinin indeksidir. `j` bu kez `primes` dizisinin indeksidir; diziye bir değer yazıldıkça bir artırılır.

### 8.8 Çıktı

Çıktı başlığı şöyle yazıldı (ekrandan, 01:45:00):

```c
printf("-Program Çıktısı-\n0-%d arasındaki asal sayılar: ", n+1);
for(i=0; i < prime_count; i++)
{
    if(i % 10 == 0)
        printf("\n");
    ...
}
```

`n + 1` yazılır, çünkü `n` bir azaltılmıştı. Döngü asal sayısı kadar döner. İndeks 10'a tam bölündüğünde yeni satıra geçilir; böylece her satırda 10 asal sayı olur. Sonra bir `if` daha eklendi: indeks `prime_count - 1` ise, yani son sayıdaysa, sayıdan sonra virgül konmaz; değilse sayı ve virgül yazılır. Hizalama için 5 karakterlik alan kullanıldı. Sonunda kullanılan diziler `free` ile serbest bırakıldı. Program 500 ile çalıştırıldı ve 500'ün altındaki asal sayıları listeledi.

<!-- BELİRSİZ: Son if/else'in tam biçimi karede görünmüyor; "%5d" ve "%5d," altyazıdaki "5 tane boşlukla hizalama" ve "else ise virgülü yazacağız" anlatımına göre tamamlandı. -->

Ajanın tam sürümü:

```c
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char *argv[]) {
    int n, i, j, prime_count, *primes;
    char *prime_states;

    setlocale(LC_ALL, "Turkish");

    printf("Sieve of Eratosthenes algoritmasını kullanarak asal sayı\noluşturmak için bir n tamsayısı giriniz : ");
    scanf("%d", &n);
    n--;
    prime_states = (char *)malloc(n * sizeof(char));
    if (prime_states == NULL) {
        printf("Bellekte alan oluşturulamadı.");
        exit(0);
    }

    for (i = 0; i < n; i++) {
        prime_states[i] = 1; // 1 = asal sayı demektir.
    }

    for (i = 0; (i + 2) * (i + 2) <= n + 1; i++) {
        if (prime_states[i] == 1) {
            for (j = (i + 2) * (i + 2); j <= n + 1; j += i + 2) {
                prime_states[j - 2] = 0;
            }
        }
    }

    prime_count = 0;
    for (i = 0; i < n; i++) {
        if (prime_states[i] == 1)
            prime_count++;
    }

    primes = (int *)malloc(prime_count * sizeof(int));
    if (primes == NULL) {
        printf("Bellekte alan oluşturulamadı.");
        exit(0);
    }

    j = 0;
    for (i = 0; i < n; i++) {
        if (prime_states[i] == 1) {
            primes[j] = i + 2;
            j++;
        }
    }

    printf("-Program Çıktısı-\n0-%d arasındaki asal sayılar: ", n + 1);
    for (i = 0; i < prime_count; i++) {
        if (i % 10 == 0)
            printf("\n");
        if (i == prime_count - 1)
            printf("%5d", primes[i]);
        else
            printf("%5d,", primes[i]);
    }
    printf("\n");

    free(prime_states);
    free(primes);
    return 0;
}
```

`gcc -Wall` ile uyarısız derlendi. Girdi 10 için çıktı `2, 3, 5, 7`; girdi 100 için 25 asal (son satır `73, 79, 83, 89, 97`); girdi 500 için son asal 499'dur. Ajanın sürümünde istem metnindeki yazım hataları ("algortitmasını", "girinini") düzeltildi.

## 9. Hatanın yeniden ele alınması ve kod okunabilirliği

### 9.1 Ders sonundaki açıklama

Oturumun sonunda dersin hocası birinci programdaki çökmeyi kendi ekranında yeniden gösterdi (ekrandan, 01:50:00). Verilen açıklamaya göre: başlangıçta zaten bir elemanlı bir yer vardır; yeni satıra gelince tekrar bir elemanlık ayırma yapılmaya çalışılınca hata alınır. Programın bazı bilgisayarlarda çalışıp bazılarında çalışmamasının nedeni bellekte tahsis edilen yerle ilgilidir: uygun boyutta yer varsa (kısa kelimelerde) verilebilir, daha uzun kelimelerde ayrılamayabilir.

İki çözüm önerildi. Birincisi, satırları sayan ekstra bir değişken (örneğin `L`) tutup her seferinde bir artırarak yeniden ayırma yapmak. İkincisi ve daha iyisi, metnin uzunluğu baştan biliniyorsa (ya da string fonksiyonları işlenince `strlen` ile hesaplanırsa) bütün hesabı baştan yapıp ayırmayı doğrudan yapmaktır; programın içinde sonradan hesaba katılacak bir şey kalmaz.

> **Ders sonrası not:** Derste hatanın nedeni "aynı boyutta tekrar ayırmaya çalışmak" ve "bellekte uygun yer bulunamaması" diye açıklandı. Doğrusu büyük olasılıkla şudur: `theImage = realloc(theImage, (i+1)*sizeof(int*))` satırı yeni bir satır işaretçisi ekler ama bu `theImage[i]` işaretçisine değer vermez; içinde çöp bir adres kalır. İç döngü ilk adımda `realloc(theImage[i], ...)` ile bu çöp adresi `realloc`'a verir. `realloc`'a yalnız `NULL` ya da daha önce `malloc`/`calloc`/`realloc` ile alınmış bir adres verilebilir; başka her şey tanımsız davranıştır. Bu yüzden program kimi bilgisayarda (çöp değer tesadüfen zararsızsa) çalıştı, kimide çöktü; aynı boyutta yeniden ayırma ise hata değildir. Ajanın AddressSanitizer denemesinde çökme tam bu satırda görüldü. Dış `realloc`'tan sonra `theImage[i] = NULL;` yazmak ya da derste yapıldığı gibi matrisi tek seferde ayırmak sorunu giderir.

### 9.2 Kod yazım kuralları

Hoca, kodun yazılış biçimine de dikkat çekti: değişkenlerin nasıl tanımlandığı, `malloc` ifadesinin nasıl kullanıldığı, girinti (indentation) ve diğer yazım kuralları önemlidir. Okunabilirliği olmayan kod, çalışsa bile iyi bir kod sayılmaz; "elinden geldiği kadar" değil, "olması gerektiği gibi" yazmak hedeflenmelidir.

## Örnek Sorular

**Soru 1 (ekrandan, 00:10:00).** Bir şifreleme algoritması, harflerin ASCII karşılıklarından oluşan $M \times M$ bir matristen bir resim oluşturuyor. Matrisin her hücresi 0-255 arasında bir piksel değeridir; bir pikselin değeri 0 ise o pikselde harf yoktur. Kelimenin ilk harfi `[0][0]`, ikinci harfi `[0][1]` hücresinde saklanır. Stringin uzunluğunun önceden bilinmediğini varsayarak bir metni şifreleyen algoritmayı C dilinde yazın. Örnek: `"YILDIZTEKNIK"` metni için çıktı matrisi nedir?

> **Çözüm (derste verildi):** $M = \lceil \sqrt{12} \rceil = 4$. Harfler satır satır ASCII kodlarıyla yazılır, kalan dört hücre 0 olur:
>
> `89 73 76 68`
> `73 90 84 69`
> `75 78 73 75`
> ` 0  0  0  0`
>
> Program Bölüm 4.2'dedir.

**Soru 2 (ekrandan, 00:10:00).** Aynı sorunun ikinci kısmı: şifreli resmin (matrisin) şifresini çözen algoritmayı yazın. Yukarıdaki $4 \times 4$ matris girildiğinde hangi metin elde edilir?

> **Çözüm (derste verildi):** Kullanıcıdan $M$ ve $M^2$ piksel alınır; her piksel `(char)` ile karaktere çevrilip `realloc` ile büyütülen metin dizisine eklenir. Sonuç `YILDIZTEKNIK`'tir. Program Bölüm 5.3'tedir.

**Soru 3 (derste sözlü, 01:15:38).** Eratosthenes Kalburu algoritmasını kullanarak, kullanıcının girdiği $n$ tam sayısının altında kalan bütün asal sayıları bulan bir program yazın. Bulunan asal sayılar, boyutu asal sayı kadar olan yeni bir dizide tutulmalıdır. $n = 10$ için sonuç nedir?

> **Çözüm (derste verildi):** $a = 2$ için 4, 6, 8, 10; $a = 3$ için 9 elenir; $a = 5$'te $25 > 10$ olduğu için durulur. Sonuç: 2, 3, 5, 7. Program Bölüm 8.8'dedir; 500 girdisiyle de denendi.

## Dersin Toparlaması

Bu uygulama oturumunda dinamik bellek fonksiyonları iki gerçek problem üzerinde kullanıldı. Şifreleme sorusunda bir metin, harflerin ASCII kodlarından oluşan $M \times M$ bir matrise gömüldü ve geri çözüldü; bunun için `int **` ile iki boyutlu dinamik dizi kurmak, `ceil(sqrt(...))` ile kenar uzunluğunu bulmak, `%[^\n]` ile satır okumak ve `realloc` ile diziyi büyütmek gerekti. Satır satır `realloc` ile büyütülen ilk çözümün bazı bilgisayarlarda çökmesi, boyut belli olduğunda belleği tek seferde ayırmanın neden daha güvenli olduğunu gösterdi; ilklendirilmemiş bir işaretçiyi `realloc`'a vermenin tanımsız davranış olduğu da bu hatadan çıkan derstir.

Eratosthenes Kalburu sorusunda bayrak dizisi için 1 baytlık `char` kullanıldı, indeks ile sayı arasındaki kaydırma (`sayı = indeks + 2`) bütün döngü sınırlarını belirledi, `malloc` sonrası `NULL` denetimi yapıldı ve sonuç dizisi ancak eleman sayısı bilinince tam boyutunda ayrıldı. Oturumun sonunda, metin uzunluğunun `strlen` gibi string fonksiyonlarıyla hesaplanmasının ileride işleneceği söylendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
