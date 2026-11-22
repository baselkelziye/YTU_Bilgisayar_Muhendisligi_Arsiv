# Ders 15 Genişletilmiş Notu: Sınav Sorusu Çözümü: Dinamik Matrisle Karmaşık Sayılar ve Struct'a Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Oturumun amacı ve sorudaki kurallar
- 2. Sorunun metni
- 3. Dinamik N x 2 matrisin kurulması
- 4. Verilerin kullanıcıdan alınması
- 5. liste_yazdir fonksiyonu
- 6. enbuyuk_bul fonksiyonu ve belleğin bırakılması
- 7. Karmaşık sayının büyüklüğü üzerine soru-cevap
- 8. Aynı problemin struct ile çözümü
- 9. Fonksiyondan struct döndürmek ve kopyalama
- 10. Sorunun ikinci kısmı üzerine sorular
- Örnek Sorular

## 1. Oturumun amacı ve sorudaki kurallar

Bu kayıt yaklaşık bir saatlik kısa bir oturumdur. İlk yarıda bir sınav sorusu Dev-C++ ortamında baştan sona kodlanır. Soru, önceki dönemin konularını (fonksiyonlar, diziler) bu dönemin dinamik bellek ayırma (dynamic memory allocation) konusuyla birleştirmek için hazırlanmıştır. İkinci yarıda aynı problem `struct` kullanılarak yeniden çözülür ve böylece yapılar (struct) konusuna giriş yapılır.

Kodlamaya geçmeden önce hoca sorularda verilen kurallara uymanın önemini anlatır. Soru $N \times 2$ boyutlu dinamik bir matris istemektedir. Problem iki ayrı N elemanlı dinamik diziyle ya da tek boyutlu bir diziyle de çözülebilir ve sonuç doğru çıkabilir; ama bu sorunun koyduğu kuralın dışına çıkmaktır. Hoca bunu bir benzetmeyle anlatır: Markete gidip pirinç isteyen birine bulgur verilmez. Bazı yemekler bulgurla da yapılır, ama pirinç isteniyorsa pirinç kullanılır. Kural anlaşılmadıysa sınavın başında ya da soru-cevap kısmında "şöyle yapsak olur mu?" diye sorulmalıdır.

> **Hocanın vurgusu:** Sorudaki kurallar bozulmamalıdır. İki boyutlu bir yapı istendiyse tek boyutlu bir yapı kullanılmaz; C sorusunda C++'a ait yapılar kullanılmaz ve dosya C dosyası olarak açılır.

Soruda karmaşık sayılar geçtiği için bazı öğrenciler karmaşık sayıları bilmediklerini söylemiştir. Hoca, sorunun karmaşık sayı bilgisi gerektirmediğini belirtir: Yapılacak iş iki sayının karelerini toplayıp bu toplamları karşılaştırmaktır. Bu, lisede de anlatılan bir hesaptır.

## 2. Sorunun metni

Oturumun sonunda ekranda gösterilen sorunun birinci kısmı şöyledir (ekrandan, 00:55:00):

> Kullanıcıdan alınan N sayısına göre N farklı karmaşık sayının reel ve sanal kısmı, Nx2 boyutlu bir dinamik int matriste saklanacaktır. Main fonksiyonunda bu matrise bilgi girişi yapıldıktan sonra, aşağıdaki işlemleri yapan fonksiyonları yazınız.
>
> a. Matrisi parametre olarak alıp reel ve sanal kısımların kareleri toplamı en büyük karmaşık sayının kaçıncı satırda olduğunu bulan ve geri döndüren fonksiyonu yazınız. Fonksiyon prototipi: `______ enbuyuk_bul(matris parametre olarak alınacaktır);`
>
> b. Matrisi parametre olarak aldıktan sonra N sayıdaki karmaşık sayının her birisini a + bi formatında alt alta yazdıran fonksiyonu yazınız. Fonksiyon prototipi: `______ liste_yazdir(matris parametre olarak alınacaktır);` Örnek çıktı: `2 + 3i`, `5 - 2i`, ..., `7 + 4i`.

Prototiplerdeki dönüş türleri ve parametrelerin tam listesi bilerek boş bırakılmıştır. Fonksiyonun `void` mi, `int` mi, işaretçi mi döndüreceğine ve hangi parametreleri alacağına öğrencinin kendisinin karar vermesi beklenir.

## 3. Dinamik N x 2 matrisin kurulması

Program `stdio.h`, `stdlib.h` (malloc ve free için) ve `math.h` ekleyerek başlar. Matris iki boyutlu veri tutacağı için iki yıldızlı bir işaretçiye ihtiyaç vardır: `int **matris;`. Neden iki yıldız? Çünkü önce N tane işaretçiden oluşan bir dizi gerekir; bu dizinin her elemanı bir `int *`'dır. İşaretçileri tutan bir dizinin adresi de işaretçinin işaretçisi, yani `int **` olur.

Kullanıcıdan N değeri alındıktan sonra ayırma iki adımda yapılır (ekrandan, 00:10:00 ve 00:15:00):

```c
int **matris;
int N, i, j;
printf("N degeri"); scanf("%d",&N);
matris=(int **) malloc(N*sizeof(int*));
for(i=0;i<N;i++){
    matris[i]=(int*)malloc(2*sizeof(int));
}
```

İlk `malloc` N tane `int *` büyüklüğünde yer ayırır; bu, satırların adreslerini tutacak dizidir. Döngüdeki `malloc` ise her satır için iki `int`'lik yer açar. Verilerin asıl saklandığı yer bu satır dizileridir. Sütun sayısı sabit 2 olduğu için kullanıcıdan ikinci bir boyut almaya gerek yoktur. `malloc` yerine `calloc` da kullanılabilir.

## 4. Verilerin kullanıcıdan alınması

N sayının her biri için iki değer okunur: birinci sütun (`[0]`) reel kısım, ikinci sütun (`[1]`) sanal kısımdır. İki iç içe döngü de kullanılabilirdi, ama sütun sayısı yalnız 2 olduğu için iki ayrı satır daha açıktır (ekrandan, 00:15:00):

```c
for(i=0;i<N;i++){
    printf("%d. reel part",i); scanf("%d",&matris[i][0]);
    printf("%d. sanal part",i); scanf("%d",&matris[i][1]);
}
```

Hoca burada köşeli parantez gösterimini açıklar. `matris[i][0]` yazıldığında işaretçi aritmetiği yapmaya gerek kalmaz; bu ifade doğrudan $i$. satırın 0. sütunundaki değeri verir. Ama `scanf` bir adres ister ve köşeli parantezli ifade adres değil değer verir. Bu yüzden başına `&` konur.

## 5. liste_yazdir fonksiyonu

### 5.1 Dönüş türü ve parametreler

Fonksiyon matrisi alır. Matrisin iki sütunlu olduğu bilindiği için ayrıca yalnız satır sayısı N gönderilir; 2 sayısı da parametre olarak gönderilebilir, bu da kabul edilir. Fonksiyonun görevi ekrana yazmaktır, bir şey döndürmez. Böyle fonksiyonların türü `void` yazılır. Başarılı yazıp yazamadığını belirtmek için 0 ya da 1 döndürmek anlaşılır bir tercihtir; ama hiçbir anlamı olmayan bir `int` döndürmek doğru değildir.

> **Hocanın vurgusu:** Yalnız bir şey yazdıran ve geri değer döndürmeyen fonksiyonlar normalde `void` yazılır.

### 5.2 a + bi biçimi

Önce sayının sırası ve reel kısmı yazılır. Sanal kısım sıfırsa yazılmaz, doğrudan alt satıra geçilir. Sanal kısım sıfırdan farklıysa işaretine bakılır: pozitifse araya `" + "`, negatifse `" - "` yazılır. Ardından sanal kısmın mutlak değeri ve `i` harfi basılır. Mutlak değer (`abs`) kullanılmasının nedeni, negatif bir sayının önüne zaten `-` konduğu için iki eksinin yan yana yazılmasını (`3 - -2i`) önlemektir. Hoca, bu biçimlendirme ayrıntılarının çok katı değerlendirilmediğini, buna yakın bir çözümün yeterli olduğunu da ekler.

Ekrandaki kod şöyledir (ekrandan, 00:20:00):

```c
void liste_yazdir(int **matris, int N){
    int i;
    for(i=0;i<N;i++){
        printf("%d -> %d",i,matris[i][0]);
        if(matris[i][1]!=0){
            if(matris[i][1]>0){
                printf(" + ");
            }
            else {
                printf(" - ");
            }
            printf("%di\n",abs(matris[i][1]));
        }
        printf("\n");
    }
}
```

`main` içinde fonksiyon `liste_yazdir(matris,N);` diye çağrılır.

> **Ders sonrası not:** Sanal kısım sıfırdan farklıyken hem `"%di\n"` hem de döngü sonundaki `printf("\n")` çalışır. Bu yüzden ekrandaki çıktıda her sayının ardından bir boş satır görünür (ekrandan, 00:30:00). Boş satır istenmiyorsa içteki biçim `"%di"` yapılabilir.

## 6. enbuyuk_bul fonksiyonu ve belleğin bırakılması

### 6.1 Hazır fonksiyonlar

Bazı öğrenciler hazır fonksiyon kullanmanın serbest olup olmadığını sormuştur. Aksi söylenmedikçe `abs`, `pow` gibi hazır fonksiyonlar kullanılabilir; string sorularında da `strcmp` kullanılabileceği daha önce söylenmişti.

### 6.2 Algoritma

Fonksiyon matrisi ve N'yi alır, en büyük sayının bulunduğu satırın indisini `int` olarak döndürür. Fonksiyonda bir döngü değişkeni `i`, en büyüğün indisini tutan `maxI` ve iki geçici değişken (`tmp`, `tmp2`) vardır. `maxI` başlangıçta 0'dır, yani ilk satır o ana kadarki en büyük kabul edilir. Döngünün her adımında `tmp` $i$. satırın kareler toplamını, `tmp2` ise o ana kadarki en büyüğün (`maxI` satırının) kareler toplamını tutar. `tmp` daha büyükse `maxI` güncellenir (ekrandan, 00:25:00; `maxI=i` ve `return` satırları altyazıdan):

```c
int enbuyuk_bul(int **matris, int N){
    int i, maxI=0, tmp=0, tmp2=0;
    for(i=0;i<N;i++){
        tmp=matris[i][0]*matris[i][0] + matris[i][1]*matris[i][1];
        tmp2=matris[maxI][0]*matris[maxI][0] + matris[maxI][1]*matris[maxI][1];
        if(tmp>tmp2){
            maxI=i;
        }
    }
    return maxI;
}
```

Karekök de alınabilirdi, ama karşılaştırma kareler üzerinden yapıldığı için buna gerek yoktur: Negatif olmayan iki sayıdan karesi büyük olanın kendisi de büyüktür. Hoca, en büyüğü aradığı için başlangıç değerlerini sıfır aldığını, kareler toplamının zaten sıfırdan küçük olamayacağını belirtir. Kodda değerlerin yerine indis tutulmasını da kendisine daha rahat geldiği için seçtiğini söyler.

`main` içinde dönen indis aynı `i` değişkenine alınır ve yazdırılır:

```c
i=enbuyuk_bul(matris,N);
printf("En buyuk deger = %d. satirdadir",i);
```

### 6.3 Belleğin bırakılması

Ayrılan bellek ayrıldığı sıranın tersiyle bırakılır: önce her satırın verileri, sonra satır işaretçilerini tutan dizi (ekrandan, 00:25:00):

```c
for(i=0;i<N;i++){
    free(matris[i]);
}
free(matris);
```

> **Hocanın vurgusu:** Bir şey için allocation yapılıyorsa `free` etmek gerekir. Bu, programcı açısından zorunludur; soru açıkça istemese bile yapılmalıdır.

### 6.4 Derleme ve çalıştırma

Hoca derlerken derleyici fonksiyon bildirimlerinin (prototiplerin) yukarı alınması gerektiğini bildirir; prototipler `main`'den önce yazılır. Program 4 sayıyla çalıştırılır (ekrandan, 00:30:00):

```text
N degeri4
0. reel part2
0. sanal part2
1. reel part4
1. sanal part4
2. reel part3
2. sanal part-2
3. reel part1
3. sanal part7
0 -> 2 + 2i

1 -> 4 + 4i

2 -> 3 - 2i

3 -> 1 + 7i

En buyuk deger = 3. satirdadir
```

Kareler toplamları adım adım (ara adım eklendi): $2^2 + 2^2 = 8$, $4^2 + 4^2 = 32$, $3^2 + (-2)^2 = 13$, $1^2 + 7^2 = 50$. En büyüğü 50'dir ve 3. satırdadır (indis 0'dan başlar).

Tam program (prototipler `main`'den önce olacak şekilde) `gcc -Wall` ile derlendi ve aynı girdiyle çalıştırıldı; çıktı ekrandakiyle aynıdır. Kullanılmayan `j` değişkeni için yalnız bir uyarı verir.

> **Hocanın vurgusu:** C ile kodlamaya alışmak gerekir. Sınavda küçük bir hata olunca sonradan üzülmemek için bol pratik yapılmalıdır.

## 7. Karmaşık sayının büyüklüğü üzerine soru-cevap

**Soru:** Kareler toplamı alınırken sanal kısmın karesi neden doğrudan toplanıyor? $i^2 = -1$ olduğu için sanal kısmın karesinin eksi gelmesi gerekmez mi?

**Cevap:** Büyüklük (magnitude) hesaplanırken öyle bir şey yoktur. Sayı iki boyutlu koordinat düzleminde bir vektör gibi düşünülür. Örneğin $3 + 4i$ sayısında 3 reel kısım, 4 sanal kısımdır. Düzlemde reel eksen boyunca 3 uzunluğunda, sanal eksen boyunca 4 uzunluğunda iki dik kenar çizilir. Sayının uzunluğu bu üçgenin hipotenüsüdür:

$$|3 + 4i| = \sqrt{3^2 + 4^2} = \sqrt{25} = 5$$

Yani reel kısmın karesi ile sanal kısmın karesi toplanır. Programda "$i$'li kısım" diye ayrı bir şey yoktur; o yalnız akılda kurulan bir anlamdır, ikinci sütundaki değer de sıradan bir `int`'tir. Soru toplama ya da çarpma isteseydi, ikinci sütunu karmaşık sayıların toplama ya da çarpma kuralına göre işlemek gerekirdi; bu soruda yalnız kareler alınır. Hoca, sınav değerlendirmesinde matematik işleminden çok C tarafına, yani parametrelerin doğru alınıp karşılaştırmanın doğru kurulmasına baktıklarını da ekler.

> **Ek bilgi (derste anlatılmadı):** $a + bi$ sayısının büyüklüğü (modülü) $|z| = \sqrt{a^2 + b^2}$ ile tanımlanır. $i^2 = -1$ kuralı sayının kendisiyle çarpımında ($z \cdot z$) ortaya çıkar; büyüklük ise $z$ ile eşleniği $\bar{z} = a - bi$ çarpılarak bulunur: $z \cdot \bar{z} = a^2 + b^2$. Soruda istenen "kareler toplamı" bu nedenle $|z|^2$'dir.

**Soru:** Satır sayısı için `N` yerine farklı bir değişken adı kullanılması sorun olur mu?

**Cevap:** Hayır. Değişkenlere istenen ad verilebilir; farklı adlar olması hatta daha iyidir.

## 8. Aynı problemin struct ile çözümü

### 8.1 Yapı tanımı

Aynı problem bir yapı (struct) ile şöyle kurulabilir (ekrandan, 00:35:00):

```c
typedef struct complex{
    int reel;
    int sanal;
}CMP;
#define N 10
```

Soruda nasıl bir nesne tarif edildiyse onun bütün özellikleri yapının içine alan olarak yazılır. Hoca burada önemli bir ayrıma dikkat çeker: Bu bir global değişken tanımı değildir, yalnız bir yapı (tür) tanımıdır. Normalde türün adı `struct complex`'tir; `typedef` bu adı `CMP` diye kısaltır. `typedef` bir etiketleme, yeniden adlandırma aracıdır; istenirse `int` için de `tam_sayi` gibi bir ad tanımlanabilir. N bu örnekte `#define` ile 10 olarak sabitlenmiştir, istenirse kullanıcıdan da alınabilir.

### 8.2 Bu türle neler tanımlanabilir?

Hoca sorular sorarak `CMP`'nin `int`'ten hiçbir farkı olmadığını gösterir (ekrandan, 00:35:00):

```c
CMP c0;
CMP *c1, **c2, *c3;
CMP C3[10];
c1 = (CMP*)malloc(N*sizeof(CMP));
c1 = (struct complex*)malloc(N*sizeof(struct complex));
```

- Normal bir değişken tanımlanabilir: `CMP c0;`
- İşaretçi tanımlanabilir: `CMP *c1`. İşaretçinin işaretçisi de (`CMP **c2`), istenen kadar derin işaretçi de tanımlanabilir.
- On elemanlı statik bir dizi tanımlanabilir: `CMP C3[10];`
- `malloc` ile dinamik bir dizi oluşturulabilir.

Bütün bu tanımlarda `CMP` yerine `int` yazılsa hepsi yine geçerli olurdu. Dolayısıyla yapılarla aslında çok yeni bir şey öğrenilmez; yalnız düşünme biçimi nesneye yönelik bir düşünceye doğru yönlenir.

`malloc` bayt cinsinden yer ister; N elemanlık yer için `N*sizeof(CMP)` yazılır. `malloc`'un döndürdüğü `void *` işaretçi `(CMP*)` ile dönüştürülür. Aynı satır `typedef` kullanılmadan `struct complex` ile de yazılabilir, ama daha uzun olduğu için kısa biçim tercih edilir. Ekranda ikinci satır daha sonra yorum satırına alınmıştır.

### 8.3 Verilerin okunması ve fonksiyona gönderilmesi

Okuma döngüsü matris çözümündekinin aynısıdır; tek fark alanlara nokta operatörüyle erişilmesidir (ekrandan, 00:45:00):

```c
for(i=0;i<N;i++){
    printf("%d. reel part",i); scanf("%d",&c1[i].reel);
    printf("%d. sanal part",i); scanf("%d",&c1[i].sanal);
}
i=enbuyuk_bul2(c1,N);
printf("En buyuk = %d --> %d + %di",i, c1[i].reel, c1[i].sanal);
free(c1);
```

`c1[i]` dizinin $i$. elemanına, yani bir yapıya gider; `.reel` o yapının `reel` alanını verir. `scanf` adres istediği için yine `&` gerekir. Ok operatörü (`->`) gibi başka yazımlar da mümkündür; bu operatörler sonraki derste örnek üzerinde ele alınacaktır.

Fonksiyona bir `int` dizisi nasıl gönderiliyorsa yapı dizisi de öyle gönderilir: dizinin adı (`c1`) ve eleman sayısı. Fonksiyon dönen indisle `main` içinde `c1[i].reel` ve `c1[i].sanal` doğrudan yazdırılabilir.

`free(c1)` ile bırakılan şey `c1`'in gösterdiği alandır. `c1` işaretçisinin kendisi stack bölgesindedir; `malloc` ile ayrılan ve `c1`'in başlangıç adresini tuttuğu alan heap bölgesindedir.

### 8.4 enbuyuk_bul2

Fonksiyon önceki `enbuyuk_bul`'dan kopyalanıp değiştirilir. Kareler bu kez `pow` ile alınır (ekrandan, 00:40:00 ve 00:50:00):

```c
int enbuyuk_bul2(CMP *c,int n){
    int i, maxI=0, tmp=0, tmp2=0;
    for(i=0;i<N;i++){
        tmp=pow(c[i].reel,2)+pow(c[i].sanal,2);
        tmp2=pow(c[maxI].reel,2)+pow(c[maxI].sanal,2);
        if(tmp>tmp2){
            maxI=i;
        }
    }
    return maxI;
}
```

N `#define` ile tanımlandığı için aslında parametre olarak almaya gerek yoktur; ama örnek öncekiyle aynı kalsın diye küçük `n` parametresi bırakılmıştır. Döngü sınırında `#define` ile gelen `N` kullanılmıştır.

Derlemede iki ders çıkar. Birincisi, prototip (`int enbuyuk_bul2(CMP *c,int n);`) `typedef`'ten önce yazılamaz; `CMP` türü tanımlanmadan prototipte kullanılamaz. İkincisi, `math.h` eklenmeden `pow` kullanılınca derleyici "incompatible implicit declaration of built-in function 'pow'" uyarısını verir (ekrandan, 00:40:00); hoca bunun üzerine `#include` satırını ekler.

<!-- BELİRSİZ: Bu bölümdeki deneme çalıştırmalarında (yaklaşık 00:40:41 - 00:43:31) girilen değerler altyazıda karışık ve kareye düşmedi; N değeri de bu sırada 10'dan 3'e indirildi. Bu yüzden ara çalıştırmaların çıktısı nota alınmadı. -->

## 9. Fonksiyondan struct döndürmek ve kopyalama

### 9.1 İndis yerine değeri döndürmek

Hoca soruyu değiştirir: İndis yerine en büyük sayının reel ve sanal kısımları döndürülsün. Bir fonksiyon tek bir değer döndürebilir; ama bu tek değer bir `CMP` olursa iki sayı birlikte döndürülmüş olur. Fonksiyonun dönüş türü `CMP` yapılır, en büyüğün indisi aynı yolla bulunur ve değerler yerel bir `CMP` değişkenine kopyalanıp döndürülür (ekrandan, 00:50:00):

```c
CMP enbuyuk_bul3(CMP *c,int n){
    int i, maxI=0, tmp=0, tmp2=0;
    CMP c2;
    for(i=0;i<N;i++){
        tmp=pow(c[i].reel,2)+pow(c[i].sanal,2);
        tmp2=pow(c[maxI].reel,2)+pow(c[maxI].sanal,2);
        if(tmp>tmp2){
            maxI=i;
        }
    }
    printf("%p",&c2);
    c2.reel=c[maxI].reel;
    c2.sanal=c[maxI].sanal;
    return c2;
}
```

`main` içinde dönen değer `c0`'a alınır: `c0 = enbuyuk_bul3(c1, N);`. Artık `c0` tek bir eleman olduğu için `[i]` kullanılmaz; `c0.reel` ve `c0.sanal` yazdırılır. Hoca, fonksiyondaki değişkene `main`'deki `c`'lerle karışmasın diye `c2` adını verdiğini ve bunun statik (yerel) bir eleman olduğunu vurgular.

<!-- BELİRSİZ: main içinde c0'ın alanlarını yazdıran printf satırının tam metni karede görünmüyor. -->

### 9.2 Debug ile kopyanın gösterilmesi

Program `N` 3 yapılarak debug edilir. Girdi $3+3i$, $2+2i$, $5+5i$'dir. `c0` ve `c2` izlemeye (watch) eklenir, fonksiyonun içine girilir (step into). Fonksiyon bitince iki değişkende de `reel = 5`, `sanal = 5` görünür (ekrandan, 00:50:00). Ardından `printf("%p", ...)` ile `&c0` ve `&c2` yazdırılır ve izleme penceresine eklenir: iki adres farklıdır. Yani `c2` ile `c0` bellekte ayrı yerlerdir. Hesaplama fonksiyon içindeki `c2` üzerinde yapılır; `return` ile `c2`'nin içeriği değerle (call by value) `c0`'a kopyalanır.

Program `math.h` eklenmiş haliyle `gcc -Wall` ile derlendi ve aynı girdiyle çalıştırıldı: `enbuyuk_bul2` 2 indisini, `enbuyuk_bul3` $5 + 5i$ değerini verdi; iki adres farklı çıktı. Kullanılmayan `c2`, `c3`, `C3` tanımları için yalnız uyarı verir.

> **Ders sonrası not:** Hoca bu kopyalamayı "deep copy" diye adlandırdı. Yapının değerle döndürülmesi alan alan (üye üye) yapılan bir kopyadır. Bu yapı yalnız `int` alanlar içerdiği için kopya eksiksizdir. Yapının içinde işaretçi bir alan olsaydı büyük olasılıkla yalnız adres kopyalanır, gösterilen veri kopyalanmazdı; "deep copy" terimi genelde bu gösterilen verinin de kopyalanmasını anlatır.

### 9.3 Yerel dizinin adresini döndürmenin tehlikesi

Hoca bir uyarıyla bölümü kapatır. Burada yapı değerle döndürüldüğü için sorun yoktur. Ama `c2` fonksiyon içinde statik bir dizi olarak tanımlanıp bu dizinin adresi döndürülseydi işlem sağlıklı olmazdı. Fonksiyon içinde statik tanımlanan dizi stack bölgesindedir; fonksiyon tamamlanınca o alan boşa çıkar ve başka işler tarafından kullanılabilir. Bu durumda döndürülen işaretçi üzerinden okunan değerler bozulur. Aynı durum `int` dizileri için de geçerlidir: Tek bir `int` döndürülürken değeri kopyalanır, ama yerel bir `int` dizisinin işaretçisi başka bir işaretçiye aktarılırsa değerlerin korunması garanti değildir. Bunun nedeni değişkenlerin ömür (duration) ve kapsam (scope) kurallarıdır; konu sonraki derslerde ayrıntılı ele alınacaktır.

> **Ders sonrası not:** Hoca, boşa çıkan stack alanını "başka programların" kullanabileceğini söyledi. Doğrusu büyük olasılıkla şudur: O alanı aynı programın sonraki fonksiyon çağrıları ve yerel değişkenleri yeniden kullanır; bu yüzden yerel dizinin adresi üzerinden okunan değerler bozulabilir.

> **Ek bilgi (derste anlatılmadı):** Yerel bir dizinin adresini döndürmenin güvenli yolları, diziyi fonksiyon içinde `malloc` ile heap'te ayırıp adresini döndürmek (çağıran sonra `free` eder) ya da diziyi çağıran fonksiyonda oluşturup parametre olarak göndermektir.

## 10. Sorunun ikinci kısmı üzerine sorular

Oturumun sonunda öğrenciler sorunun ikinci kısmıyla ilgili sorular sorar. İkinci kısım bir öğrenci bilgi sistemidir (soru metni Örnek Sorular bölümündedir).

**Soru:** İkinci kısımda kullanıcıdan öğrenci bilgilerinin girilmesi istenmemişti; bu normal miydi?

**Cevap:** Soruda "N elemanlı dinamik öğrenci dizisi oluşturunuz" denmiştir. Aslında verilerin `main` içinde girilmesi isteniyordu; yani yapı dizisi için yukarıda yapılan okuma işleminin aynısı. Ama asıl önemli olan sonraki kısımlardır.

**Soru:** İkinci kısımdaki fonksiyonlara N değeri de gönderilecek miydi?

**Cevap:** Evet. Fonksiyon dinamik dizinin eleman sayısını bilmek zorundadır. Dinamik ayrılmış bir dizinin boyutu fonksiyon içinde `sizeof` ile bulunamaz; `sizeof` ile hesap yapmak için de N gerekir. N kullanıcıdan alınan bir değerdir ve parametre geçişiyle her fonksiyona aktarılabilir. Prototiplerin dönüş türlerinin ve bazı parametrelerin bilerek boş bırakılması, öğrencinin bunları kendi kurgusuna göre çıkarması içindir.

**Soru:** Kullanıcı saymaya 1'den başlıyor diye bulunan satır indisini `return` ederken 1 ekledim; sorun olur mu?

**Cevap:** Döngü 0'dan başlatıldıysa ve 1 yalnız gösterim için eklendiyse sorun yoktur. Yanlış olan, N elemanlı dizi için `n+1` yer ayırıp döngüyü 1'den başlatmak ve 0. elemanı kullanmamaktır. Diziler 0'dan başlar ve N'ye kadar (N dahil değil) gider. Kullanıcıya 1'den saymak gösterilmek isteniyorsa yazdırırken `i+1` yazılmalıdır.

> **Hocanın vurgusu:** Diziyi 1'den başlatıp fazladan bir eleman ayırmak yanlıştır; indisler 0'dan başlatılmalıdır.

## Örnek Sorular

### Soru 1: Dinamik matriste karmaşık sayılar

(ekrandan, 00:55:00) Kullanıcıdan alınan N sayısına göre N farklı karmaşık sayının reel ve sanal kısmı, $N \times 2$ boyutlu bir dinamik `int` matriste saklanacaktır. `main` fonksiyonunda bu matrise bilgi girişi yapıldıktan sonra:

- a. Matrisi parametre olarak alıp reel ve sanal kısımların kareleri toplamı en büyük karmaşık sayının kaçıncı satırda olduğunu bulan ve geri döndüren `enbuyuk_bul` fonksiyonunu yazınız.
- b. Matrisi parametre olarak alıp N karmaşık sayının her birini `a + bi` formatında alt alta yazdıran `liste_yazdir` fonksiyonunu yazınız. Örnek çıktı: `2 + 3i`, `5 - 2i`, ..., `7 + 4i`.

> **Çözüm (derste verildi):** Bölüm 3-6'daki kod. `main` içinde `int **matris` için önce `malloc(N*sizeof(int*))`, sonra her satıra `malloc(2*sizeof(int))` ile yer açılır ve değerler `&matris[i][0]`, `&matris[i][1]` ile okunur. `void liste_yazdir(int **matris, int N)` işarete göre `+` ya da `-` ve `abs` ile sanal kısmı yazar. `int enbuyuk_bul(int **matris, int N)` $a^2 + b^2$ değeri en büyük satırın indisini döndürür. Sonda her satır ve işaretçi dizisi `free` edilir. Girdi $2+2i$, $4+4i$, $3-2i$, $1+7i$ için sonuç 3. satırdır.

### Soru 2: Öğrenci bilgi sistemi

(ekrandan, 00:55:00) Öğrenci bilgi sistemi için id, Ad, yaş ve ortalama bilgilerini saklayan bir struct üzerinde aşağıdaki işlemleri yapan programı yazınız.

- a. id, Ad, yaş ve ortalama bilgileri için gereken struct'ı tanımlayınız.
- b. `main` fonksiyonu içerisinde kullanıcıdan alınan N sayısına göre N elemanlı bir dinamik öğrenci dizisi oluşturunuz.
- c. Oluşturulan öğrenci dizisini ortalamaya göre sıralayan bir fonksiyon yazınız. Sıralama sonrası `main` içerisinde tanımlanan dizinin orijinal hali değiştirilmelidir. İstediğiniz sıralama algoritmasını kullanabilirsiniz. Fonksiyon prototipi: `______ nota_gore_sirala(struct öğrenci, eleman sayısı);`

<!-- BELİRSİZ: Sorunun c maddesinden sonraki kısımları karede görünmüyor; ders sırasında başka maddelerden de söz edildi ama metinleri okunamadı. -->

> **Çözüm (derste verilmedi):** Aşağıdaki çözüm a-c maddeleri için yazılmıştır; sıralama yönü soruda belirtilmediği için büyükten küçüğe seçilmiştir. Dizinin orijinal halinin değişmesi için fonksiyona dizinin adresi (`OGRENCI *`) ve eleman sayısı gönderilir; sıralama doğrudan bu dizi üzerinde yapılır. Kod `gcc -Wall` ile uyarısız derlendi ve üç öğrencilik bir girdiyle doğru sıralama verdi.

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct ogrenci {
    int id;
    char ad[30];
    int yas;
    float ortalama;
} OGRENCI;

void nota_gore_sirala(OGRENCI *dizi, int n) {
    int i, j;
    OGRENCI gecici;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (dizi[j].ortalama < dizi[j + 1].ortalama) {
                gecici = dizi[j];
                dizi[j] = dizi[j + 1];
                dizi[j + 1] = gecici;
            }
        }
    }
}

int main() {
    int n, i;
    OGRENCI *dizi;
    printf("N: ");
    scanf("%d", &n);
    dizi = (OGRENCI *)malloc(n * sizeof(OGRENCI));
    if (dizi == NULL) {
        return 1;
    }
    for (i = 0; i < n; i++) {
        printf("%d. ogrenci (id ad yas ortalama): ", i);
        scanf("%d %29s %d %f", &dizi[i].id, dizi[i].ad, &dizi[i].yas, &dizi[i].ortalama);
    }
    nota_gore_sirala(dizi, n);
    for (i = 0; i < n; i++) {
        printf("%d %s %d %.2f\n", dizi[i].id, dizi[i].ad, dizi[i].yas, dizi[i].ortalama);
    }
    free(dizi);
    return 0;
}
```

Bu çözümde yapı değişkenlerinin `gecici = dizi[j];` biçiminde doğrudan atanabildiğine dikkat edin; Bölüm 9'daki gibi atama alan alan kopya yapar.

### Soru 3: İndis yerine değeri döndürmek

(derste sözlü, 00:42:20) Soru 1a'daki fonksiyon, en büyük sayının indisi yerine reel ve sanal kısımlarını birlikte döndürecek şekilde nasıl yazılır?

> **Çözüm (derste verildi):** Dönüş türü `CMP` olan bir fonksiyon yazılır. En büyüğün indisi `maxI` aynı yolla bulunur, yerel `CMP c2` değişkenine `c2.reel = c[maxI].reel; c2.sanal = c[maxI].sanal;` ile kopyalanır ve `return c2;` yapılır (Bölüm 9.1). Değer, çağıran taraftaki `c0` değişkenine kopyalanır.

## Dersin Toparlaması

Bu oturumda iki boyutlu dinamik matrisin `int **` ile nasıl kurulduğu, fonksiyonlara nasıl gönderildiği ve ters sırayla nasıl bırakıldığı tam bir program üzerinde görüldü. Yeni olan nokta, dinamik bellek ayırmanın fonksiyonlarla birlikte kullanılmasıdır: Fonksiyon dinamik dizinin boyutunu kendisi bilemez, bu yüzden boyut parametre olarak gönderilir. Karmaşık sayının büyüklüğü, iki boyutlu düzlemdeki vektörün uzunluğu olarak yorumlandı ve karşılaştırma için kareler toplamının yeterli olduğu görüldü.

İkinci yarıda aynı problem `typedef struct` ile yeniden yazıldı. Yapı türüyle `int` ile yapılabilen her tanımın (değişken, işaretçi, statik ve dinamik dizi) yapılabildiği, alanlara nokta operatörüyle erişildiği ve fonksiyondan bir yapı döndürülerek birden fazla değerin birlikte döndürülebildiği gösterildi. Yapının değerle kopyalandığı debug ile doğrulandı; yerel bir dizinin adresini döndürmenin neden tehlikeli olduğu ise sonraki derslere bırakıldı. Sonraki derslerde yapılar, ok operatörü ve bu kapsam/ömür sorunları örneklerle sürdürülecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
