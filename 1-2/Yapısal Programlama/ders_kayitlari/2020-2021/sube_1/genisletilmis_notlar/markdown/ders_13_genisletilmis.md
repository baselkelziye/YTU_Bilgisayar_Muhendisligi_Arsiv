# Ders 13 Genişletilmiş Notu: Uygulama: Matris Tabanlı Metin Şifreleme ve Eratosthenes Kalburu

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Oturumun Yapısı
- 2. Problem 1: Metni Bir Görüntü Matrisine Gömmek
- 3. Şifreleme Programı
- 4. Derleme ve Çalıştırma: -lm Bayrağı
- 5. Şifre Çözme Programı
- 6. Kodlardaki Bellek Hataları (Ders Sonrası)
- 7. Problem 2: Eratosthenes Kalburu
- 8. Kalbur Programı
- 9. Asalları Toplama ve Yazdırma
- 10. malloc, calloc ve realloc Üzerine Soru
- Örnek Sorular
- Dersin Toparlaması

## 1. Oturumun Yapısı

Bu kayıt dersin teorik bölümü değil, bir öğretim elemanının yürüttüğü uygulama (laboratuvar) oturumudur. Önceki laboratuvarlarda sorulmuş iki problem, hazır yazılmış C kodları üzerinden satır satır anlatıldı. Kodlar Visual Studio Code'da açıldı ve terminalde GCC ile derlenip çalıştırıldı. Üç dosya kullanıldı: `encryption.c`, `decryption.c` ve `findPrimes.c` (ekrandan, 00:10:00).

İki problemin ortak teması dinamik bellek yönetimidir. İkinci problemin belgesinin adı "Yapısal Programlama Lab 1 (Memory Allocation, loops, if&else statements)" idi (ekrandan, 00:35:00). Yani amaç `malloc`, `calloc`, `realloc` ve `free` ile döngü ve koşul yapılarını birlikte kullanmaktır.

## 2. Problem 1: Metni Bir Görüntü Matrisine Gömmek

Ekrandaki problem metni şöyledir (ekrandan, 00:05:00):

> Bir şifreleme algoritması, harflerin ASCII karşılıklarından oluşan MxM matristen meydana gelen bir image yaratıyor. Matrisin her bir hücresi 0-255 arasında bir piksel değerine karşılık gelmektedir. Bir pikselin değeri "0" ise bu pikselde harf olmadığı anlamına gelmektedir. Bir kelimenin ilk harfi 0x0 hücresinde, ikinci harfi 0x1 ... şeklinde saklanıyor. Bir metni şifreleyen ve şifreli metnin şifresini çözen birer algoritmayı C dilinde gerçekleyelim. NOT: Stringin uzunluğu önceden bilinmediği varsayılacaktır.

Örnek girdi ve çıktı olarak `"YILDIZTEKNIK"` stringinin matrisi verilmiştir (ekrandan, 00:05:00):

```text
89 73 76 68
73 90 84 69
75 78 73 75
 0  0  0  0
```

Fikir şudur: her harf ASCII değeriyle bir piksel olur. Gri tonlamalı bir görüntüde 0 siyah, 255 beyazdır; örneğin 89 değeri siyaha göre biraz daha açık bir pikseldir. Öğretim elemanı bu matrisi Python'da gerçekten bir görüntüye dönüştürüp göstermişti; görüntü büyük ölçüde koyu renkliydi, çünkü harflerin ASCII değerleri 255'e göre küçüktür.

Son satırın 0 olmasının nedeni, kare bir matrisin her zaman metin uzunluğuna tam oturmamasıdır. 12 harf 4x4 = 16 hücreye yazılınca 4 hücre boş kalır ve bu hücrelere 0 yazılır.

## 3. Şifreleme Programı

### 3.1 Kütüphaneler ve değişkenler

Karekök (`sqrt`) kullanıldığı için `math.h`, bellek ayırma için `stdlib.h`, ayrıca `string.h` ve `stdio.h` eklenir. Değişkenler şunlardır: `textSize` metnin uzunluğu, `k` metindeki karakterin sırası (0'dan başlar, metnin ilk karakteri), `text` şifrelenecek metin, `junk` atılacak karakter ve `theImage` görüntü matrisi.

`theImage` `int **` türündedir, yani bir işaretçinin işaretçisidir. Öğretim elemanı bunu "bir dizinin adresini tutan adresler" diye anlattı: her satır bir tamsayı dizisidir, `theImage` ise bu satırların adreslerini tutan dizidir.

### 3.2 Metni okumak

Önce `scanf("%d",&textSize)` ile metnin uzunluğu alınır ve `text` için `textSize` karakterlik yer `malloc` ile ayrılır. Kullanıcı sayıyı yazıp Enter'a bastığında girdi tamponunda bir `'\n'` karakteri kalır. Bazı derleyiciler bunu kendiliğinden işleyemediği için `scanf("%c",&junk);` ile bu karakter okunup atılır. Koddaki yorum da bunu söyler: `//"\n" karakterini çöpe atıyoruz.`

Ardından `scanf("%[^\n]",text);` ile metin okunur. Bu biçim "bir Enter görene kadar oku" demektir; `%s`'ten farkı, boşlukta durmamasıdır. Öğretim elemanı satır okumak için `fgets` ve `gets` gibi başka yolların da bulunduğunu, ama her derleyicide aynı çalışmayabileceklerini söyledi.

**Soru:** `\n`'den önce konan şapka (`^`) işareti ne için kullanılıyor?
**Cevap:** "Değil" anlamındadır. `%[^\n]` "yeni satır olmadıkça metni al" demektir.

### 3.3 Matrisin boyutu: ceil, floor, round

Matrisin kare olması istendiği için kenar uzunluğu metin uzunluğunun kareköküdür. 12 karakterlik bir metin 2x6'lık bir matrise de yazılabilirdi, ama görüntü olacağı için kare tercih edildi. `sqrt` bir `double` döndürür ve sonuç büyük olasılıkla tam sayı olmaz; bu yüzden `ceil` ile en yakın üst tam sayıya yuvarlanır:

```c
m = ceil(sqrt(textSize));
```

Öğretim elemanı diğer yuvarlama fonksiyonlarını da hatırlattı: `floor` en yakın alt tam sayıya yuvarlar; `round` en yakın tam sayıya yuvarlar, örneğin 4,6'yı 5'e, 4,4'ü 4'e.

### 3.4 Matrisi realloc ile büyütmek

Matris için başta yalnız bir satır işaretçisi ve bir tamsayılık yer ayrılır, sonra iç içe döngülerde her adımda `realloc` ile büyütülür. Dış döngüde satır işaretçileri dizisi `(i+1)` elemana, iç döngüde her satır `(j+1)` tamsayıya çıkarılır. Her hücreye `text[k]` karakterinin ASCII değeri (`(int)` dönüşümüyle) yazılır ve `k` artırılır. Metin bittiğinde hücreye 0 yazılır. Son olarak matris yazdırılır ve `free` ile bellek bırakılır; öğretim elemanı kaynakların her zaman önemli olduğunu vurguladı.

Ekrandaki kod aşağıdadır (ekrandan, 00:10:00, 00:15:00 ve 00:45:00). Karelerde 50. satıra kadar görünüyor; son iki satır (`free(text);` ve `return 0;`) karede görünmedi ve anlatıma göre eklendi. Bu haliyle `gcc -Wall blm2031_13_enc.c -lm` ile uyarısız derlendi ve `13`, `YILDIZ TEKNIK` girdisiyle derstekiyle aynı çıktıyı verdi. Kodun bellek hataları 6. bölümde.

```c
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int textSize,i,j,pixel,m,k=0;
    char * text,junk;
    int **theImage;
    printf("Enter The Lenght of Text To Encrypt\n");
    scanf("%d",&textSize);

    text=(char *)(malloc)(sizeof(char)*textSize);
    theImage=(int**)(calloc)(1,sizeof(int*));
    theImage[0]=(int*)(calloc)(1,sizeof(int));

    printf("Enter The Text\n");
    scanf("%c",&junk); //"\n" karakterini çöpe atıyoruz.
    scanf("%[^\n]",text);

    printf("%s\n",text);
    m=ceil(sqrt(textSize));

    for(i=0;i<m;i++)
    {
        theImage=(int**)(realloc)(theImage,(i+1)*sizeof(int*));

        for(j=0;j<m;j++)
        {
            theImage[i]=(int*)(realloc)(theImage[i],(j+1)*sizeof(int));
            pixel=(int)text[k];
            theImage[i][j]=pixel;
            if(k>textSize)
                theImage[i][j]=0;
            k++;
        }
    }

    printf("The Image is: \n");

    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d ",theImage[i][j]);
        }
        printf("\n");
    }

    free(theImage);
    free(text);   /* karede görünmedi, eklendi */
    return 0;     /* karede görünmedi, eklendi */
}
```

## 4. Derleme ve Çalıştırma: -lm Bayrağı

Program önce `gcc encryption.c` ile derlendi ve şu hata alındı (ekrandan, 00:15:00):

```text
undefined reference to `sqrt'
undefined reference to `ceil'
collect2: error: ld returned 1 exit status
```

Öğretim elemanı bunun nedenini şöyle açıkladı: `math.h` include edilse de GCC'de matematik kütüphanesini dışarıdan kullanacağınızı derleme komutunda ayrıca söylemeniz gerekir. `-lm` "math kütüphanesi" demektir. `gcc encryption.c -lm` komutuyla program derlendi.

> **Ek bilgi (derste anlatılmadı):** `#include <math.h>` yalnız fonksiyonların bildirimlerini getirir; fonksiyonların derlenmiş kodu ayrı bir kütüphanededir (libm). Hata derleme aşamasında değil bağlama (link) aşamasında çıkar; mesajdaki `ld` bağlayıcıdır. `-l` bayrağı bağlayıcıya hangi kütüphaneyi ekleyeceğini söyler.

Çalıştırınca uzunluk olarak 13 girildi ("Yıldız Teknik" araya bir boşlukla 13 karakterdir) ve metin `YILDIZ TEKNIK` olarak yazıldı. Çıktı (ekrandan, 00:20:00):

```text
YILDIZ TEKNIK
The Image is:
89 73 76 68
73 90 32 84
69 75 78 73
75 0 0 0
```

Program 4x4'lük bir matris oluşturdu: $\sqrt{13} \approx 3{,}606$ olduğu için 3'ü geçen değer 4'e yuvarlandı. Değerler adım adım şöyledir: Y=89, I=73, L=76, D=68, I=73, Z=90, boşluk=32, T=84, E=69, K=75, N=78, I=73, K=75; kalan üç hücre 0'dır (ajan python ile doğruladı).

## 5. Şifre Çözme Programı

### 5.1 Ne biliniyor, ne bilinmiyor?

Şifre çözmede elimizde görüntü vardır, yani matrisin boyutu (M) bilinir. Ama metnin uzunluğu bilinmez, çünkü matriste kaç tane 0 olduğu baştan bilinmez. Bu yüzden metin için başta derleyiciye yalnız bir karakterlik yer ayrılır ve her karakter geldiğinde metin büyütülür. Görüntü için ise MxM yer ayrılır.

Görüntü normalde dosyadan okunabilirdi, ama C'de bir görüntüyü dosyadan okumak zor olduğu için pikseller tek tek klavyeden girildi. Öğretim elemanı laboratuvarda da aynı yolu izlediğini söyledi.

### 5.2 Kod

Her pikseli `(char)` ile dönüştürmek doğrudan karakteri verir; bunun için ASCII'de o değere karşılık gelen bir karakter olması gerekir, yoksa farklı şeyler ortaya çıkabilir. `textIndex` her yeni karakterde artırılır, sonunda metin yazdırılır. Karede görünen kısım (ekrandan, 00:20:00):

```c
        scanf("%d",&pixel);
        theImage[i][j]=pixel;
    }
}

for (i=0;i<m;i++)
{
    for(j=0;j<m;j++)
    {
        text=(char*)(realloc)(text,sizeof(char));
        text[textIndex]=(char)theImage[i][j];
        textIndex++;
    }
}
```

### 5.3 Çalıştırma

Program `Enter Image Size: M` diye sordu, 4 girildi. Sonra `Enter The Pixel Values from top-left to bottom-right` iletisiyle değerler sol üstten başlayarak girildi: 89, 73, 76, 68, 73, 90, 32, 84, 69, 75, 78, 73, 75. Öğretim elemanı sıfırları önce yazmadı; program 4x4 = 16 değer beklediği için kalan üç 0 da girildi. Çıktı (ekrandan, 00:25:00):

```text
The Text That Was Hidden Into The Image is: YILDIZ TEKNIK
```

## 6. Kodlardaki Bellek Hataları (Ders Sonrası)

Programlar derste doğru çıktı verdi, ama ekrandaki kodlarda öğretim elemanının değinmediği bellek hataları vardır.

> **Ders sonrası not:** Şifre çözme döngüsündeki `realloc(text, sizeof(char))` bloğu her seferinde 1 bayta ayarlar, büyütmez. Öğretim elemanı "her karakter geldiğinde bir tane büyütüyoruz" dedi; bunun için boyutun `(textIndex+1)*sizeof(char)` olması, metni yazdırmadan önce de sona `'\0'` için bir bayt daha eklenmesi gerekir. Derste doğru çıktının alınması büyük olasılıkla şans eseridir (tanımsız davranış).

> **Ders sonrası not:** Şifreleme kodunda `text` için `textSize` bayt ayrılır, ama `scanf("%[^\n]",text)` metnin sonuna `'\0'` da yazar: 13 karakterlik metin 14 bayt yazar. Ajan kodu AddressSanitizer (`-fsanitize=address`) ile çalıştırdı ve bu taşmayı (heap-buffer-overflow, 14 baytlık yazma) doğruladı. `textSize+1` bayt ayrılmalıdır.

> **Ders sonrası not:** Aynı kodda `text[k]` önce okunup sonra `if(k>textSize)` denetimi yapılır. Geçerli indisler 0..textSize-1 olduğu için denetim okumadan önce ve `k >= textSize` biçiminde olmalıdır. Ayrıca dış dizi `realloc` ile `(i+1)` işaretçiye büyütülünce yeni `theImage[i]` gözü ilk değer almamıştır ve doğrudan `realloc`'a verilir. Güvenli olması için iç döngüden önce `theImage[i] = NULL;` yazılmalıdır (`realloc(NULL, n)`, `malloc(n)` gibi davranır). Program sonunda yalnız `free(theImage)` yapmak satırları bırakmaz; önce her `theImage[i]` bırakılmalıdır.

## 7. Problem 2: Eratosthenes Kalburu

### 7.1 Algoritmanın mantığı

Eratosthenes Kalburu (Sieve of Eratosthenes) bir n sayısına kadar olan bütün asal sayıları bulur. "Sieve" elek demektir. Belgede 500'e kadar bütün asalları bulan bir örnek gösterildi.

Mantık şöyledir. Önce 2'den n'ye kadar bütün sayılar asal kabul edilir (hepsi "asal" diye işaretlenir). İlk asal sayı olan 2 alınır ve 2'ye bölünen bütün sayılar elenir, yani "asal değil" diye işaretlenir. Sonra işaretlenmemiş bir sonraki sayıya, 3'e geçilir ve 3'ün katları elenir. Sayılar bir elekten geçer gibi elendiği için bu ada sahiptir.

### 7.2 Örnek: n = 10

Belgedeki örnek "10'a kadar olan tüm asal sayıları Sieve of Eratosthenes algoritmasını kullanarak bulunuz" idi (ekrandan, 00:35:00).

- Başlangıç: liste 2, 3, 4, 5, 6, 7, 8, 9, 10; hepsi asal kabul edilir.
- a = 2: listenin en küçük asalı 2'dir ve $2^2 = 4 \le 10$ eşitsizliğini sağlar. 2'nin katları 4, 6, 8, 10 elenir.
- a = 3: kontrol edilmemiş en küçük asal 3'tür ve $3^2 = 9 \le 10$ sağlanır. 3'ün katlarından 9 elenir (6 zaten elenmişti).
- Sonraki aday 5'tir, ama $5^2 = 25 > 10$ olduğu için işlem biter.
- Sonuç: 2, 3, 5, 7.

### 7.3 Neden karekök?

Öğretim elemanı bu sınırı çarpanlara ayırmayla açıkladı: $n = a \cdot b$ biçiminde çarpanlarına ayrılan bir sayıda çarpanlardan biri $\sqrt{n}$'den küçük ya da eşit, diğeri $\sqrt{n}$'den büyük ya da eşit olmalıdır. Bu yüzden $\sqrt{n}$'e kadar çarpan bulunamayan sayı asaldır ve kalburda yalnız $a^2 \le n$ olan asallara bakmak yeterlidir.

### 7.4 Neden karesinden başlanır?

Elimizdeki sayı asalsa onun karesi asal değildir; eleme oradan başlar. Akla "karesinden önce de katları vardı" diye gelebilir. Ama en küçük asaldan başlandığı için bu katlar daha önce daha küçük bir asal tarafından elenmiştir. Örneğin 3'e gelindiğinde 6, 2 tarafından zaten elenmiştir.

## 8. Kalbur Programı

### 8.1 Kütüphaneler ve değişkenler

Dosyanın başında `stdio.h`, `stdlib.h`, `conio.h` ve `locale.h` vardır (ekrandan, 00:25:00). `setlocale(LC_ALL, "Turkish");` Türkçe karakterleri kullanabilmek içindir. Öğretim elemanı `conio.h`'nin ne için konduğunu o an hatırlayamadı.

Değişkenler koddaki yorumlarla açıklanmıştır: `n` kullanıcıdan alınan tam sayı, `i` ve `j` döngü değişkenleri, `prime_count` bulunan asal sayısı, `primes` asalların tutulacağı dizi, `prime_states` her sayının asal olup olmadığını tutan dizi.

`prime_states` bir `char` dizisidir. Koddaki yoruma göre `char` 1 bayttır ve en küçük veri tipi olduğu için true/false saklamak için kullanılabilir: asalsa 1 (true), değilse 0 (false). Öğretim elemanı `int` dizisinin de kullanılabileceğini, ayrıca 0-1'i true-false olarak kullanmayı sağlayan bir kütüphane (`stdbool.h`, `bool` türü) bulunduğunu söyledi.

### 8.2 n'den 1 çıkarmak ve bellek ayırmak

Kullanıcıdan n alındıktan sonra `n -= 1;` yapılır. Koddaki yoruma göre 1 asal sayı değildir; n = 10 girilirse kontrol edilecek sayılar 2, 3, 4, 5, 6, 7, 8, 9, 10 olur, yani 9 tane. Sonra bu kadar karakterlik yer ayrılır ve ayrılamazsa program durdurulur (ekrandan, 00:25:00 ve 00:35:00):

```c
n-=1;
prime_states = (char *) malloc ((n) * sizeof(char));
...
    printf("Bellekte alan oluşturulamadı.");
    exit(0); // Exit from the program
```

<!-- BELİRSİZ: 32-34. satırlardaki NULL denetiminin tam yazımı karede görünmüyor -->

### 8.3 İndeks ile sayı arasındaki ilişki

Dizinin 0. gözü 2 sayısını, 1. gözü 3 sayısını temsil eder; genel olarak `prime_states[i]`, `i+2` sayısının durumudur. Kodda sayı gerektiğinde bu yüzden hep `i+2` kullanılır. Öğretim elemanı "3 nerede? 1'de" diye örnek verdi.

### 8.4 Ana döngüler

Önce bütün gözlere 1 yazılır: hepsi asal kabul edilir. Sonra kalbur döngüsü çalışır (ekrandan, 00:30:00):

```c
// Dizideki tüm sayılar asal sayı olarak işaretlemek için aşağıdaki döngü kullanılır.
for(i = 0; i < n; i++)
{
//1(true) değeri sayının asal olduğunu ifade eder.
    prime_states[i] = 1;
}

/* a^2 <= n kontrolünü sağlarken i değerinin 2 fazlası kullanılır
 * çünkü 0'ıncı indexde 2 değerinin asal sayı olup olmadığını belirten boolean değer tutulur.
 * Bu sebeple i değerinin 2 fazlası kullanılır.
 */
for(i = 0; (i + 2)*(i + 2) <= n+1; i++)
{
    if(prime_states[i] == 1) // 1 = true
    {
        for(j = (i + 2)*(i + 2); j <= n+1; j += i+2 )
        {
            prime_states[j-2] = 0; // 0 = false
        }
    }
}
```

Dış döngü, sayının ($i+2$) karesi hâlâ sınırın içinde olduğu sürece döner; `n` bir azaltıldığı için sınır `n+1`, yani kullanıcının girdiği sayıdır. Sayı o ana kadar asal işaretliyse iç döngüye girilir.

İç döngü $j = (i+2)^2$'den başlar ve her adımda `i+2` kadar ilerler; `j` bir sayıdır, dizideki yeri `j-2`'dir. Elemek, o göze 0 yazmaktır. n = 10 için:

- `i = 0` (sayı 2): j = 4'ten başlar, 2'şer artar: 4, 6, 8, 10 elenir. Sonraki 12, 10'u aştığı için iç döngü biter.
- `i = 1` (sayı 3): j = 9'dan başlar, 3'er artar: 9 elenir. Sonraki 12 sınırı aştı.
- `i = 2` (sayı 4): $4^2 = 16 > 10$ olduğu için dış döngü biter.

Böylece aradaki mesafe hep `i+2` olur: önce sayının iki katı, sonra üç katı ve böyle devam edilir. İndeksler ile tam sayılar birbirine bağlı olduğu için, örneğin `i+2`'nin karesinde 4 bulunur.

**Soru:** Son `for` kısmını bir daha anlatabilir misiniz?
**Cevap:** Öğretim elemanı aynı adımları tekrarladı: dış döngüde `i` 0'dan başlar ama sayı her zaman indeksten 2 fazladır. Önce 4'e (2'nin karesi), sonra 9'a (3'ün karesi) bakılır, kare sınırın içinde mi diye. İç döngü sayının karesinden başlar ve sayının kendisi kadar adımla ilerler; bulunan her göze 0 yazılır.

## 9. Asalları Toplama ve Yazdırma

Kalburdan sonra `prime_states` gözlerinden 1 olanlar sayılır ve o kadar `int`'lik bir dizi ayrılır (ekrandan, 00:30:00):

```c
// Kaç adet asal sayı tespit edildiği aşağıdaki döngü ile belirlenir.
prime_count = 0;
for(i = 0; i < n; i++)
{
    if(prime_states[i] == 1)
        prime_count++;
}

// Aşağıdaki kod parçası ile asal sayı adedi uzunluğunda hafızada yer ayrılır.
primes = (int *) malloc (prime_count * sizeof(int));
```

Sonra `prime_states`'i 1 olan sayılar bu diziye yazılır ve dizi her zamanki gibi bir `for` döngüsüyle yazdırılır. Öğretim elemanına göre yazdırmada 5 genişlikli bir tam sayı biçimi kullanılır ve sayılar yan yana uzayıp gitmesin diye her 10 sayıda bir alt satıra geçilir. <!-- BELİRSİZ: yazdırma kodu karede görünmüyor; biçim ifadesinin tam yazımı bilinmiyor -->

Derste n = 80 girildi. Ekrandaki çıktı (ekrandan, 00:40:00):

```text
Sieve of Eratosthenes algoritmasını kullanarak asal sayı
oluşturmak için bir n tamsayısı giriniz : 80
-Program Çıktısı-
0-80 arasındaki asal sayılar:
    2,    3,    5,    7,   11,   13,   17,   19,   23,   29,
   31,   37,   41,   43,   47,   53,   59,   61,   67,   71,
```

> **Ders sonrası not:** 80'e kadar 22 asal sayı vardır; listenin sonunda 73 ve 79 olmalıdır (ajan python ile doğruladı). Ekrandaki çıktıda bu iki sayı görünmüyor. Yazdırma döngüsü karede görünmediği için nedeni bilinmiyor; kodda büyük olasılıkla bir sınır hatası vardır.

Öğretim elemanı burada `free` konusunu tekrar vurguladı.

> **Hocanın vurgusu:** Ayırdığınız yerleri `free` ile işletim sistemine geri vermeden programı sonlandırmayın. Bırakılmayan bir alan başka bir programın veri kaybına yol açabilir.

## 10. malloc, calloc ve realloc Üzerine Soru

Oturumun sonunda şifreleme kodundaki bellek ayırma satırları üzerine bir soru geldi ve öğretim elemanı bunları tek tek açıkladı:

- `malloc(sizeof(char)*textSize)`: programınızdan sorumlu işletim sistemine "bana bellekte `textSize` kadar karakter yeri ayır, bunu kullanacağım" dersiniz.
- `calloc(1,sizeof(int*))`: "bana bir tamsayı adresi saklayacak kadar yer ayır" dersiniz.
- `calloc(1,sizeof(int))`: "bana bir tamsayı saklayacak kadar yer ayır" dersiniz.

Bunu iki katmanlı bir yapı olarak düşünmek gerekir: alt katmanda tamsayılardan oluşan diziler vardır, bir üst dizide ise bu dizilerin adresleri tutulur.

`realloc`'u anlamak için iç döngüden başlamak daha mantıklıdır. Başta yalnız bir tamsayılık yer ayrılmıştı; iç döngüde "artık bir tane değil, iki tane istiyorum", sonra "üç tane", sonra "dört tane" denir. `j+1` olmasının nedeni budur: `realloc` elinizdekini alıp size bir fazlasını veriyor gibi düşünebilirsiniz. Sonunda M tane tamsayı istenmiş olur; bunlar satırlardır (row size). Dış döngüde de aynı şey satır dizileri için yapılır: "bir dizi istemiştim, artık iki, artık üç dizi istiyorum." Sonuçta MxM bir matris oluşur: MxM matris, içinde M tamsayı bulunan M dizi demektir. Derste bu, dört tamsayıdan oluşan dört diziydi.

> **Ek bilgi (derste anlatılmadı):** `calloc` ayırdığı alanı sıfırlarken `malloc` ve `realloc`'un yeni eklediği kısım sıfırlanmaz. Her adımda bir eleman büyütmek yerine boyut önceden biliniyorsa (burada `m` hesaplandıktan sonra) önce `m` satır işaretçisi, sonra her satır için `m` tamsayı tek seferde ayrılabilir; bu hem daha hızlı hem daha az hataya açıktır.

## Örnek Sorular

### Soru 1: Metni matrise gömen şifreleme ve çözme (ekrandan, 00:05:00)

Bir şifreleme algoritması, harflerin ASCII karşılıklarından oluşan MxM matristen meydana gelen bir image yaratıyor. Matrisin her hücresi 0-255 arasında bir piksel değeridir; "0" o pikselde harf olmadığı anlamına gelir. Kelimenin ilk harfi 0x0 hücresinde, ikinci harfi 0x1 hücresinde ... saklanır. Bir metni şifreleyen ve şifreli metnin şifresini çözen birer algoritmayı C dilinde gerçekleyin. Stringin uzunluğunun önceden bilinmediği varsayılacaktır. Örnek: `"YILDIZTEKNIK"` için matris `89 73 76 68 / 73 90 84 69 / 75 78 73 75 / 0 0 0 0`.

**Çözüm (derste verildi):** Şifrelemede `m = ceil(sqrt(uzunluk))` ile kare matrisin kenarı bulunur, `int **` matris `realloc` ile büyütülerek satır satır doldurulur, metin bittiğinde 0 yazılır (3. bölümdeki kod). Çözmede M okunur, MxM piksel girilir, her piksel `(char)` ile karaktere çevrilip metne eklenir (5. bölüm). `YILDIZ TEKNIK` (13 karakter) için 4x4 matris `89 73 76 68 / 73 90 32 84 / 69 75 78 73 / 75 0 0 0` olur ve çözme bu metni geri verir.

### Soru 2: Eratosthenes Kalburu (ekrandan, 00:35:00)

10'a kadar olan tüm asal sayıları Sieve of Eratosthenes algoritmasını kullanarak bulunuz.

**Çözüm (derste verildi):** Başta 2-10 arası bütün sayılar asal kabul edilir. $2^2 \le 10$ olduğu için 2 alınır ve katları 4, 6, 8, 10 elenir. $3^2 \le 10$ olduğu için 3 alınır ve 9 elenir. $5^2 > 10$ olduğu için işlem biter. Asallar: 2, 3, 5, 7. Derste aynı program n = 80 ile de çalıştırıldı (9. bölüm).

## Dersin Toparlaması

Bu uygulama oturumunda dinamik bellek yönetimi iki problem üzerinden çalışıldı. İlkinde bir metin, harflerin ASCII değerleriyle MxM'lik bir "görüntü" matrisine yazıldı ve geri okundu. Burada `scanf("%[^\n]")` ile boşluklu satır okuma, artık Enter karakterini temizleme, `ceil`/`floor`/`round` ile yuvarlama, `int **` ile iki boyutlu dinamik dizi kurma ve GCC'de `math.h` için `-lm` bağlama bayrağı görüldü. İkincisinde Eratosthenes Kalburu ile n'ye kadar olan asallar bulundu: bütün sayılar asal kabul edilip $p^2 \le n$ olan her asalın katları karesinden başlanarak elendi, dizi indeksi ile sayı arasındaki `i+2` kaydırması kullanıldı ve bulunan asallar ayrı bir dinamik diziye toplandı.

Her iki programda da ayrılan belleğin `free` ile geri verilmesi vurgulandı. Ders sonrası notlarda belirtildiği gibi, ekrandaki kodlarda ayrılan alan boyutlarıyla ilgili birkaç hata vardır; kendi kodunuzu yazarken sondaki `'\0'` için yer ayırmayı, `realloc`'a yeni boyutu tam vermeyi ve dizi sınırını `>=` ile denetlemeyi unutmayın.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
