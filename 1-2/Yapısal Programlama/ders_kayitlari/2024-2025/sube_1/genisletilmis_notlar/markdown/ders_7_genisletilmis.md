# Ders 7 Genişletilmiş Notu: Dinamik Bellek Yönetimi Uygulamaları (malloc, calloc, realloc, free)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dinamik Bellek Ayırmaya Kısa Bir Hatırlatma
- 2. Uygulama 1: Üç Zarın Toplam ve Olasılık Matrisi
- 3. Uygulama 2: Collatz Fonksiyonu ve realloc ile Büyüyen Sepet Dizisi
- 4. Uygulama 3: Fatura Oluşturma (String ve Dinamik Bellek)
- 5. Laboratuvar 1 Sorusunun Çözümü: Ortak Anahtarların Değerlerini Toplama
- 6. Örnek Sorular

Bu oturum, teorik dersin yanında yürütülen bir uygulama (laboratuvar) dersidir. Ekranda "Yapısal Programlama – Dinamik Memory Allokasyonu" başlıklı bir sunum açıldı (ekrandan, 00:05:00). Program: dinamik bellek ayırmayla ilgili üç soru çözmek ve en sonda birinci laboratuvar sorusunun çözümünü incelemek. Kodlar Dev-C++ ortamında yazılıp çalıştırıldı.

## 1. Dinamik Bellek Ayırmaya Kısa Bir Hatırlatma

### 1.1 Statik dizi ile dinamik dizi

Dinamik bellek ayırmayı görmeden önce 5 elemanlı bir diziyi `int a[5];` gibi sabit boyutla tanımlıyorduk. Dinamik bellek ayırmayla aynı dizi `malloc` ile de tanımlanabilir. Derste öğrencilere bu yöntemin avantajı soruldu, cevap gelmeyince de açıklandı.

Statik tanımda bellekteki yer, dizi kullanılsa da kullanılmasa da ayrılmış kalır. Dinamik ayırmada ise yalnız ihtiyaç duyulan kadar yer alınır ve iş bitince bu yer boşaltılabilir. Bellek sınırlı olduğu için bu yaklaşım bellekle ilgili hataları önler ve daha verimli bir program sağlar. Boyutun bir değişkenle verildiği gösterimde (`malloc(n * sizeof(int))` gibi) dizinin boyutunu değiştirmek de daha kolaydır, çünkü yalnız değişkenin değeri değişir.

<!-- BELİRSİZ: Sunum slaytındaki dizi tanımı kodları karelerde görünmüyor; yalnız kapak slaytı okunabildi. -->

### 1.2 Dört özel fonksiyon

Dinamik bellek yönetimi için dört özel fonksiyon vardır. Hepsi `<stdlib.h>` kütüphanesindedir, bu yüzden kodun başına bu kütüphane eklenmelidir.

- `malloc`: bellekte belirtilen kadar yer ayırır.
- `calloc`: yer ayırır ve ek olarak ayrılan alanı sıfırlar. `malloc`'tan farklı olarak iki parametre alır: eleman sayısı ve bir elemanın boyutu.
- `realloc`: `malloc` ya da `calloc` ile ayrılmış bir bellek bölgesini genişletmek ya da daraltmak için kullanılır.
- `free`: ayrılmış yeri boşaltır (serbest bırakır).

## 2. Uygulama 1: Üç Zarın Toplam ve Olasılık Matrisi

### 2.1 Sorunun anlatımı

Ekranda "Zar toplamı ve olasılık matrisi" başlıklı soru açıldı (ekrandan, 00:10:00). Üç zar birlikte atılır ve üst yüze gelen rakamlar toplanır. İstenen program:

- Üç zarın olası her toplamını birinci sütunda, o toplamın olasılığını ikinci sütunda tutan bir matrisi dinamik bellek ayırmayla tanımlamalı.
- Birinci sütundaki toplam değerleri tekrar etmemeli (ilk sütun benzersiz olmalı).
- İkinci sütundaki olasılıklar döngü, kontrol ve aritmetik işlemlerle doldurulmalı. `mat[i,j] = 0.0046296` gibi elle ("hard coded") atama yapılmamalı.

Ekrandaki örnek tablo şöyledir:

| Toplam | Olasılık |
|---|---|
| 3 | 0.0046296.. |
| 4 | 0.0138888.. |
| 5 | 0.0277777.. |
| ... | ... |
| 18 | 0.0046296.. |

Benzersizlik koşulu şunu anlatır: Toplamın 4 gelmesi üç farklı yolla olur (1-1-2, 1-2-1, 2-1-1). Ama tabloda 4 yalnız bir kez yer alır ve bu üç durumun hepsi onun olasılığına katkı yapar. Olasılık için verilen sezgi: Her zarın her yüzü $1/6$ olasılıkla gelir. Üç zarın belirli bir üçlüyü vermesi $\frac{1}{6} \cdot \frac{1}{6} \cdot \frac{1}{6} = \frac{1}{216}$ olasılıklıdır. Örneğin toplamın 3 gelmesi yalnız 1-1-1 ile olur, olasılığı da $1/216 \approx 0.0046296$'dır.

### 2.2 Tasarım: her iş ayrı bir fonksiyonda

Kod yazılmadan önce yapılacaklar planlandı ve her işlem ayrı bir fonksiyona konuldu:

- Matrisi dinamik olarak oluşturan fonksiyon: `float** initialize_mat(int nrow, int ncolumn)`. Değerler ondalıklı olduğu için tip `float`'tır. İki boyutlu dizi döndürdüğü için dönüş tipi işaretçinin işaretçisidir (`float**`).
- Toplamları ve olasılıkları hesaplayan fonksiyon: `void calc_prob(float **mat)`. Değer döndürmez, matrisi doğrudan değiştirir.
- Matrisi yazdıran fonksiyon: `void print_probs(float **mat, int nrow)`.
- Matrisi boşaltan fonksiyon: `void free_mat(float **mat, int nrow)`.

İskelet önce bu dört fonksiyonun boş gövdeleriyle yazıldı (ekrandan, 00:20:00). Neyin nerede yapılacağını baştan bilmenin kodu kafada oturtmayı kolaylaştırdığı söylendi.

### 2.3 Matrisi oluşturma

Önce satır sayısı kadar `float*` için `malloc` ile yer ayrılır. Sonra ayırmanın başarılı olup olmadığına bakılır: bellekte yer yoksa uyarı verilir ve programdan çıkılır. Bellek varsa satırlar dolaşılır ve her satır için sütun sayısı kadar yer ayrılır. Burada `calloc` tercih edildi, çünkü alan sıfırlanır. Bu, olasılıkların sonradan `+=` ile biriktirilmesi için gereklidir. Aynı döngüde her satırın 0. sütununa toplam değeri yazılır. En küçük toplam 3 olduğundan `i`. satıra `i + 3` konur.

```c
float** initialize_mat(int nrow, int ncolumn){
    int i;
    float **mat;
    mat=(float**)malloc(nrow*sizeof(float*));
    if(mat==NULL){
        printf("Bellek Ayrilamadi");
        exit(-1);
    }
    for(i=0;i<nrow;i++){
        mat[i]=(float*)calloc(ncolumn,sizeof(float));
        mat[i][0]=i+3;
    }
    return mat;
}
```

(ekrandan, 00:25:00)

Yazım sırasında `calloc`'a parametre adı yanlış verilmişti (`column` yerine `ncolumn`). Bir öğrencinin uyarısıyla düzeltildi.

> **Ders sonrası not:** Anlatımda "3'ten 18'e kadar, ancak 15 satırımız var" dendi. 3'ten 18'e kadar (ikisi dahil) $18 - 3 + 1 = 16$ farklı toplam olduğundan doğrusu 16 satırdır. Kodda da `nrow=16` kullanıldı (ekrandan, 00:35:00).

### 2.4 Toplamı ve olasılığı hesaplama

Üç zar olduğu için üç iç içe `for` döngüsü kullanılır. Her döngü bir zarı temsil eder ve 1'den 6'ya kadar (6 dahil, bu yüzden `<=`) döner. İlk denemede döngüler 0'dan başlatılmıştı, sonra 1'den başlayacak biçimde düzeltildi (ekrandan, 00:25:00 ve 00:30:00).

```c
void calc_prob(float **mat){
    int i,j,k,top;
    for(i=1;i<=6;i++){
        for(j=1;j<=6;j++){
            for(k=1;k<=6;k++){
                top=i+j+k;
                mat[top-3][1]+=(float) 1/(6*6*6);
            }
        }
    }
}
```

(ekrandan, 00:30:00)

Mantık şöyledir: $6 \cdot 6 \cdot 6 = 216$ üçlünün her biri $1/216$ olasılıklıdır. Her üçlü için toplam `top = i + j + k` hesaplanır ve o toplamın satırındaki olasılığa $1/216$ eklenir. Toplam en az 3 olduğundan satır indisi `top - 3`'tür: 3 toplamı 0. satıra, 18 toplamı 15. satıra düşer. `(float) 1/(6*6*6)` yazımında tür dönüşümü önemlidir. `1/216` tamsayı bölmesi olarak 0 verir; önce 1 `float`'a çevrilince sonuç ondalıklı olur.

Döngülerin işleyişi de anlatıldı: En içteki döngü `k` 7 olana kadar döner. Sonra bir dıştaki `j` döngüsüne dönülür, `j` artar ve `k` yeniden başlar. En dıştaki `i` de 7 olana kadar bu böyle sürer. Sonunda bütün toplamların olasılıkları hesaplanmış olur.

### 2.5 Yazdırma ve boşaltma

`print_probs` önce "Toplam Olasilik :" başlığını yazar, sonra satırları dolaşıp her satırın 0. sütununu (toplam) ve 1. sütununu (olasılık) yazdırır. `free_mat`, `malloc` ve `calloc` ile alınan yeri geri verir. Önce her satır tek tek serbest bırakılır, sonra satır işaretçilerini tutan dizinin kendisi.

```c
void print_probs(float **mat, int nrow){
    printf("Toplam Olasilik : \n");
    int i;
    for(i=0;i<nrow;i++){
        printf("%.0f %f\n", mat[i][0], mat[i][1]);
    }
}
void free_mat(float **mat, int nrow){
    int i;
    for(i=0;i<nrow;i++){
        free(mat[i]);
    }
    free(mat);
}
```

<!-- BELİRSİZ: print_probs içindeki printf satırının biçim dizgesi karelerde görünmüyor; altyazıda "%f" ve satır sonu geçiyor. Buradaki "%.0f %f\n" biçimi test için seçildi. free_mat gövdesi ekrandan alındı (00:35:00). -->

### 2.6 main ve çalıştırma

```c
int main() {
    float **mat;
    int nrow=16, ncolumn=2;
    mat=initialize_mat(nrow, ncolumn);
    print_probs(mat, nrow);
    calc_prob(mat);
    print_probs(mat, nrow);
    free_mat(mat, nrow);
    return 0;
}
```

(ekrandan, 00:35:00)

Matris önce hesaplamadan önce, sonra hesaplamadan sonra yazdırıldı. İlk derlemede iki hata çıktı: değişken adı (`ncolumn` tanımlanmamış görünüyordu) ve `print_probs` çağrılarında eksik parametre (`too few arguments to function 'print_probs'`). Çağrılar `print_probs(mat, nrow)` olarak düzeltilince program çalıştı. İlk yazdırmada olasılık sütunu `calloc` sayesinde sıfırdı. Hesaplamadan sonra ilk satırın olasılığı sorudaki tabloyla aynı biçimde 0.0046 olarak geldi. Olasılık `%f` yerine başka biçimlerde de yazdırılabilir.

Bu program (yukarıdaki parçalar birleştirilerek) `gcc -Wall` ile uyarısız derlendi ve çalıştırıldı. Çıktıdaki bazı değerler: 3 → 0.004630, 4 → 0.013889, 5 → 0.027778, 10 → 0.125000, 11 → 0.125000, 18 → 0.004630. Bunlar $1/216$, $3/216$, $6/216$ ve $27/216$ değerleriyle python'da da doğrulandı.

### 2.7 Özet (derste istek üzerine yapıldı)

Bir öğrenci özet istedi ve çözüm baştan özetlendi. Matrisin ilk sütunu üç zarın toplamıdır. Her zara en az 1 geleceği için toplam en az 3, 6-6-6 ile en çok 18'dir. İkinci sütun o toplamın gelme olasılığıdır. `initialize_mat` önce satır sayısı kadar `malloc`, sonra satır başına `calloc` ile matrisi kurar. `calc_prob` üç iç içe döngüyle toplamı ve olasılığı hesaplar. `print_probs` 0. ve 1. sütunları yazdırır. `free_mat` önce satırları, sonra matrisin tamamını boşaltır. `main` de bunları sırayla çağırır.

## 3. Uygulama 2: Collatz Fonksiyonu ve realloc ile Büyüyen Sepet Dizisi

### 3.1 Sorunun anlatımı

İkinci soru ekranda "Yapısal Programlama 2. Lab" başlığıyla açıldı (ekrandan, 00:40:00). Fonksiyon şöyle tanımlıdır:

$$
f(n) = \begin{cases} 3n+1 & n \equiv 1 \pmod 2 \\ n/2 & n \equiv 0 \pmod 2 \end{cases}
$$

İstenenler:

1. Kullanıcıdan pozitif bir $n$ tam sayısı okunmalı.
2. `calloc` fonksiyonu kullanılarak 2 eleman için yer ayıran, tek boyutlu bir "sepet" dizisi oluşturulmalı.
3. $n$ sayısına $f$ fonksiyonu 1 değeri elde edilene kadar tekrar tekrar uygulanmalı ve elde edilen her değer sepet dizisine yazılmalı. Sepet dizisi dolduğunda dizinin boyutu `realloc` ile 2 katına çıkarılmalı.
4. Sepet dizisi ve hafızada kapladığı alan ekrana yazdırılmalı.
5. Sepet dizisi `free` edilmeli.

Sorunun notunda `ptr = realloc(ptr, newSize);` kullanımı ve mod işleminin `%` ile yapıldığı hatırlatılıyor (ekrandan, 00:40:00).

Ekrandaki örnekte $N = 13$ için sepet 13 40 20 10 5 16 8 4 2 1 olmalı. Adım adım tablo:

| Adım | Sepet | Eleman sayısı | Boyut |
|---|---|---|---|
| 0 | [ ] | 0 | 2 |
| 1 | [13] | 1 | 2 |
| 2 | [13, 40] | 2 | 4 |
| 3 | [13, 40, 20] | 3 | 4 |
| 4 | [13, 40, 20, 10] | 4 | 8 |
| 5 | [13, 40, 20, 10, 5] | 5 | 8 |
| 6 | [13, 40, 20, 10, 5, 16] | 6 | 8 |

(ekrandan, 00:40:00; tablonun devamı karede görünmüyor)

13 tek olduğu için $3 \cdot 13 + 1 = 40$ olur. 40 çift olduğu için $40/2 = 20$, sonra 10, sonra 5 gelir. 5 tek olduğu için 16 olur ve böyle 1'e kadar devam eder. Tabloda dikkat edilecek nokta, dizi dolduğu anda boyutun hemen iki katına çıkmasıdır. 2 eleman olunca boyut 4, 4 eleman olunca 8, 8 eleman olunca 16 olur.

### 3.2 Çözüm (main içinde)

Bu soruda işlemler fonksiyonlara bölünmeden `main` içinde yapıldı. Pozitif sayı girilene kadar sormak için `do-while` kullanıldı. Dizi `A` adıyla `calloc` ile açıldı. Kapasite `current_length` değişkeninde, dolu eleman sayısı `i` değişkeninde tutuldu. Kullanıcının girdiği ilk sayı önce yazdırılıp dizinin ilk elemanı yapıldı. Sonra `while (N != 1)` döngüsünde her adımda `N = f(N)` hesaplandı ve sonuç `A[i++]` konumuna eklendi. Dolu eleman sayısı kapasiteye eşit olunca (dizi dolunca) kapasite ikiye katlandı ve `realloc` ile dizi büyütüldü. Bu, yukarıda `calloc` ile ayrılmış yerin genişletilmesidir.

```c
int main() {
    int N;
    do {
        printf("Pozitif tam sayi giriniz");
        scanf("%d",&N);
    } while (N<=0);

    int *A=(int*)calloc(2,sizeof(int));
    int current_length=2;
    printf("N =%d\n",N);
    A[0]=N;
    int i=1;
    while(N!=1){
        N=f(N);
        A[i++]=N;
        if(i==current_length){
            current_length*=2;
            A=(int*)realloc(A, current_length*sizeof(int));
        }
    }
    int j;
    printf("Dizi elemanlari");
    for(j=0;j<i;j++){
        ...
```

(ekrandan, 00:55:00)

Sonra dizi elemanları bir `for` döngüsüyle tek tek yazdırıldı ve ardından dizinin eleman sayısı ve hafızada kapladığı alan yazdırıldı. $f$ fonksiyonu `main`'in dışında tanımlandı. Sayının ikiye bölümünden kalan sıfırsa (sayı çiftse) ikiye bölünür, değilse üç katının bir fazlası alınır:

```c
int f(int n){
    if(n%2==0)
        return n/2;
    else
        return 3*n+1;
}
```

<!-- BELİRSİZ: f fonksiyonunun gövdesi, yazdırma satırlarının tam biçimi ve free(A) satırı karelerde görünmüyor; altyazıdaki anlatıma göre yazıldı. -->

### 3.3 Çalıştırma

17 girildiğinde ekran çıktısı şöyleydi (ekrandan, 01:00:00):

```text
Pozitif tam sayi giriniz17
N =17
Dizi elemanlari175226134020105168421
Dizinin Eleman sayisi 13
 kapladi-i alan 16
```

Elemanlar arasına boşluk konmadığı için sayılar bitişik çıktı. Okunduğunda dizi 17 52 26 13 40 20 10 5 16 8 4 2 1'dir. 17 tek olduğu için 52, sonra 26, 13, 40, 20, 10, 5, 16, 8, 4, 2, 1 gelir. Eleman sayısı 13, kapasite 16'dır. Ardından yazdırma biçimi düzeltildi: elemanlar arasına boşluk ve satır sonları eklendi. 13 girdisiyle de eleman sayısı 10, kapasite 16 elde edildi; bu, sorudaki örnekle uyumludur.

Yukarıdaki parçalar `f` fonksiyonu, boşluklu yazdırma ve `free(A)` ile tamamlanarak `gcc -Wall` ile uyarısız derlendi. 13 girdisiyle `13 40 20 10 5 16 8 4 2 1`, eleman sayısı 10, kapasite 16; 17 girdisiyle eleman sayısı 13, kapasite 16 çıktı.

> **Ders sonrası not:** Programda "kapladığı alan" olarak kapasite (eleman cinsinden, 16) yazdırıldı. Alan bayt cinsinden isteniyorsa `current_length * sizeof(int)` yazdırılmalıdır; 4 baytlık `int` ile bu büyük olasılıkla 64 bayttır.

> **Ek bilgi (derste anlatılmadı):** `A = realloc(A, ...)` yazımında `realloc` başarısız olup `NULL` döndürürse eski bloğun adresi kaybolur ve bellek sızıntısı olur. Güvenli kullanımda sonuç önce geçici bir işaretçiye alınır, `NULL` değilse `A`'ya atanır.

## 4. Uygulama 3: Fatura Oluşturma (String ve Dinamik Bellek)

### 4.1 Sorunun anlatımı

Üçüncü soru bir fatura oluşturma sistemi gibi düşünülebilir. Hem string işlemleri hem dinamik bellek kullanılır. Kullanıcıdan dört farklı ürün (soda, meyve suyu, kola ve su) için miktar bilgisi istenir. Her ürünün sabit bir birim fiyatı vardır. Miktar ile birim fiyatın çarpımı o ürünün tutarıdır. Her ürünün tutarı ayrı bir satırda yazdırılmalı, en sonda da toplam tutar hesaplanmalıdır. Birim fiyatlar sodanın 10, meyve suyunun 15, kolanın 20, suyun 5'tir (ekrandan, 01:35:00).

<!-- BELİRSİZ: Üçüncü sorunun metni ekranda gösterildi ama o sırada alınan kareler boş (kamera kapalı görüntüsü); soru altyazıdaki anlatımdan aktarıldı. -->

### 4.2 Makrolar

Bu soruda ürün sayısı makro olarak tanımlandı. Böylece ileride 5 ürünle çalışmak istenirse yalnız bu satırı değiştirmek yeterli olur; makro kullanılmasaydı sayının geçtiği her yeri değiştirmek gerekirdi. Her fatura satırı bir string olacağı için en büyük satır uzunluğu da makroyla 100 karakter olarak belirlendi. Makrolar birer sabit gibi davranır ve kodun okunabilirliğini ve bakımını kolaylaştırır.

```c
#define NUM_PRODUCTS 4
#define MAX_STRING_LENGTH 100
```

(ekrandan, 01:20:00)

### 4.3 Faturayı oluşturan fonksiyon

`generateInvoice` bir string dizisi döndürdüğü için dönüş tipi `char**`'dır. Parametreleri alınan miktarlar, ürün adları ve birim fiyatlardır. Ürün adları bir string dizisi olduğu için `char**` tipindedir. Önce toplam tutarı tutacak `totalAmount` ve döngü değişkeni `i` tanımlandı. Sonra satırları tutacak işaretçi dizisi için `NUM_PRODUCTS + 1` kadar `char*` yer ayrıldı. Fazladan bir satır, en alta yazılacak toplam tutar içindir. Ardından her ürün için tutar hesaplanıp toplama eklendi, her satır için `MAX_STRING_LENGTH` karakterlik yer ayrıldı. Biçimli string üretmek için `sprintf` kullanıldı. `sprintf`, `printf` gibi çalışır ama sonucu ekrana değil verilen karakter dizisine yazar.

Derste ekranda yazılan hâli şöyledir:

```c
char** generateInvoice(int* quantities, char** productNames, int* unitPrices){
    int totalAmount=0;
    int i;
    char** invoiceLines=(char**)malloc((NUM_PRODUCTS+1)*sizeof(char*));
    for(i=0;i<NUM_PRODUCTS;i++){
        int amount=quantities[i]*unitPrices[i];
        totalAmount+=amount;

        invoiceLines[i]=(char*)malloc(MAX_STRING_LENGTH*sizeof(char));
        sprintf(invoiceLines[i],"Toplam tutar:%d TL",totalAmount);
        return invoiceLines;
    }
}
```

(ekrandan, 01:25:00)

### 4.4 Yazdırma ve boşaltma fonksiyonları

`printInvoice` değer döndürmez. Ürün sayısı kadar satırı bir `for` döngüsüyle yazdırır. Döngüden sonraki `printf`, `i` 4 olduğunda toplam tutar satırını yazar. `freeInvoice` önce satırların her birini, sonra satır dizisinin kendisini serbest bırakır. Satır sayısı `NUM_PRODUCTS + 1` olduğu için döngü koşulu `<=` ile yazıldı.

```c
void printInvoice(char** invoiceLines){
    int i;
    for(i=0;i<NUM_PRODUCTS;i++){
        printf(invoiceLines[i]);
    }
    printf(invoiceLines[i]);
}
void freeInvoice(char** invoiceLines){
    int i;
    for(i=0;i<=NUM_PRODUCTS;i++){
        free(invoiceLines[i]);
    }
    free(invoiceLines);
}
```

(ekrandan, 01:30:00 ve 01:40:00; makro adı önce `NUM_PRODUCT` diye eksik yazılmış, sonra düzeltilmişti)

Boşaltma işinin programın sonunda yapılması gerektiği vurgulandı. Bellek daha erken boşaltılır da sonra kullanılmaya çalışılırsa hata alınır; bellek temizliğinin düzgün olması için `free` en sona konur.

Döngü değişkeni `i` her fonksiyonda döngünün dışında tanımlandı. Kullanılan derleyici ortamında `for (int i = 0; ...)` biçimi hata verdiği için bunun unutulmaması istendi.

> **Ek bilgi (derste anlatılmadı):** `for (int i = 0; ...)` biçimi C99 standardıyla gelmiştir. Eski GCC sürümleri varsayılan olarak C89/C90 kipinde derlediği için bu satırda "for loop initial declarations are only allowed in C99 mode" hatası verir. Bu durumda değişken döngüden önce tanımlanır ya da `-std=c99` seçeneği kullanılır.

### 4.5 main ve çalıştırma

`main` içinde ürün adları bir `char*` dizisinde, birim fiyatları bir `int` dizisinde tutuldu. Fiyatların sırası ürünlerin sırasıyla birebir eşleşmelidir (soda 10, meyve suyu 15, kola 20, su 5). Miktarlar ürün sayısı kadar dönen bir `for` döngüsüyle kullanıcıdan alındı. Sonra fonksiyonlar sırayla çağrıldı.

```c
int main(){
    char* productNames[]={"Soda","Meyve Suyu","Kola","Su"};
    int unitPrices[]={10,15,20,5};
    int quantities[NUM_PRODUCTS];
    char**invoiceLines;
    int i;
        for(i=0;i<NUM_PRODUCTS;i++){

        printf("Lutfen %s miktar n girin : ", productNames[i]);
        scanf("%d",&quantities[i]);

        }
        printf("\n");
    invoiceLines=generateInvoice(quantities,productNames,unitPrices);
    printInvoice(invoiceLines);
    freeInvoice(invoiceLines);

    return 0;
}
```

(ekrandan, 01:35:00 ve 01:40:00)

İlk denemede `scanf("%d\n", &quantities[i])` yazılmıştı (ekrandan, 01:35:00). Program ilk miktarı aldıktan sonra beklenmedik biçimde bir girdi daha bekledi. Biçim dizgesindeki `\n` kaldırılınca miktarlar sırayla istendi. Biçim dizgelerindeki boşlukların ve özel karakterlerin önemli olduğu vurgulandı.

> **Ek bilgi (derste anlatılmadı):** `scanf` biçim dizgesindeki `\n` (ya da herhangi bir boşluk karakteri) "bütün boşlukları atla" anlamına gelir. `scanf`, boşluk olmayan bir karakter görene kadar okumayı sürdürür, bu yüzden Enter'a basılınca dönmez ve bir sonraki girdiyi bekler.

Miktarlar 4, 3, 1, 5 girilince çıktı şöyleydi (ekrandan, 01:40:00):

```text
Lutfen Soda miktar n girin: 4
Lutfen Meyve Suyu miktar n girin: 3
Lutfen Kola miktar n girin: 1
Lutfen Su miktar n girin: 5

PúpoúToplam tutar:130 TL
--------------------------------
Process exited after 6.832 seconds with return value 3221226356
```

Toplam tutar doğrudur: $4 \cdot 10 + 3 \cdot 15 + 1 \cdot 20 + 5 \cdot 5 = 40 + 45 + 20 + 25 = 130$ TL. Derste toplam tutarın doğru yazdırıldığı söylenerek bir sonraki konuya geçildi.

> **Ders sonrası not:** Derste yazılan kod sorunun istediği ürün satırlarını üretmiyor ve çalışırken çöküyor. (1) `sprintf` her ürün satırına ürünün tutarını değil "Toplam tutar" metnini yazıyor. (2) 01:25:00 karesinde `return invoiceLines;` döngünün içinde; bu hâliyle yalnız ilk ürün işlenir. Çıktıdaki toplam (130) bu satırın sonradan düzeltildiğini gösteriyor, ama kodun son hâli karelerde görünmüyor. (3) Çıktıda toplam satırının önündeki anlamsız karakterler, ürün satırlarının doldurulmadığını gösteriyor. (4) Dönüş değeri 3221226356, onaltılıkta `0xC0000374`'tür. Bu, Windows'ta büyük olasılıkla yığın (heap) bozulması hatasıdır: `freeInvoice` hiç ayrılmamış ya da ilklenmemiş işaretçileri `free` etmeye çalışmıştır. Ayrıca `printf(invoiceLines[i])` yerine `printf("%s\n", invoiceLines[i])` yazmak daha doğrudur; metnin içinde `%` geçerse ilk biçim hatalı çıktı verir.

Aşağıdaki düzeltilmiş sürüm derste yazılmadı. Ajan tarafından yazıldı, `gcc -Wall` ile uyarısız derlendi ve 4, 3, 1, 5 girdileriyle denendi:

```c
#include <stdio.h>
#include <stdlib.h>

#define NUM_PRODUCTS 4
#define MAX_STRING_LENGTH 100

char** generateInvoice(int* quantities, char** productNames, int* unitPrices){
    int totalAmount=0;
    int i;
    char** invoiceLines=(char**)malloc((NUM_PRODUCTS+1)*sizeof(char*));
    if(invoiceLines==NULL) exit(-1);
    for(i=0;i<NUM_PRODUCTS;i++){
        int amount=quantities[i]*unitPrices[i];
        totalAmount+=amount;
        invoiceLines[i]=(char*)malloc(MAX_STRING_LENGTH*sizeof(char));
        sprintf(invoiceLines[i],"%s: %d x %d = %d TL",
                productNames[i], quantities[i], unitPrices[i], amount);
    }
    invoiceLines[NUM_PRODUCTS]=(char*)malloc(MAX_STRING_LENGTH*sizeof(char));
    sprintf(invoiceLines[NUM_PRODUCTS],"Toplam tutar:%d TL",totalAmount);
    return invoiceLines;
}
void printInvoice(char** invoiceLines){
    int i;
    for(i=0;i<NUM_PRODUCTS;i++){
        printf("%s\n", invoiceLines[i]);
    }
    printf("%s\n", invoiceLines[NUM_PRODUCTS]);
}
void freeInvoice(char** invoiceLines){
    int i;
    for(i=0;i<=NUM_PRODUCTS;i++){
        free(invoiceLines[i]);
    }
    free(invoiceLines);
}
int main(){
    char* productNames[]={"Soda","Meyve Suyu","Kola","Su"};
    int unitPrices[]={10,15,20,5};
    int quantities[NUM_PRODUCTS];
    char** invoiceLines;
    int i;
    for(i=0;i<NUM_PRODUCTS;i++){
        printf("Lutfen %s miktarini girin : ", productNames[i]);
        scanf("%d",&quantities[i]);
    }
    printf("\n");
    invoiceLines=generateInvoice(quantities,productNames,unitPrices);
    printInvoice(invoiceLines);
    freeInvoice(invoiceLines);
    return 0;
}
```

Bu sürümün çıktısı (girdi istemleri hariç):

```text
Soda: 4 x 10 = 40 TL
Meyve Suyu: 3 x 15 = 45 TL
Kola: 1 x 20 = 20 TL
Su: 5 x 5 = 25 TL
Toplam tutar:130 TL
```

## 5. Laboratuvar 1 Sorusunun Çözümü: Ortak Anahtarların Değerlerini Toplama

### 5.1 Sorunun anlatımı

Birinci laboratuvar sorusunda iki matris vardır ve her biri iki satırdan oluşur. Sütun sayıları $N$ ve $M$ kullanıcıdan alınır. Kurallar:

- Her iki matrisin ilk satırındaki sayılar birbirinden farklı olmalı. Aynı sayı girilirse uyarı verilmeli ve kurala uygun bir sayı istenmeli.
- İkinci satırdaki sayılar, ilk satırdaki sayıların karşılık gelen değerleridir. İlk satır bir anahtar, ikinci satır onun değeri gibi düşünülebilir.
- Amaç, iki matrisin ilk satırında ortak olan sayıları bulup ikinci satırlarda karşılık gelen değerlerini toplamaktır.
- Matris elemanlarına erişimde yalnız işaretçi aritmetiği kullanılmalıdır.

Sorudaki örnek: Birinci matrisin ilk satırı 1, 5; ikinci satırı 7, 2'dir. Yani 1'in değeri 7, 5'in değeri 2'dir. İkinci matrisin ilk satırında 2, 3 ve 5 vardır. İki ilk satırda ortak olan yalnız 5'tir. 5'in birinci matristeki değeri 2, ikinci matristeki değeri 1'dir, toplamları 3'tür.

> **Hocanın vurgusu:** Bu soruda en önemli kural, matris elemanlarına yalnız işaretçi aritmetiğiyle erişilmesidir. Sonuç doğru olsa bile soruda istenen kurallara uyulmazsa çözüm eksik sayılır. Sonraki laboratuvarlarda kurallara dikkat edilmeli.

<!-- BELİRSİZ: Laboratuvar 1 sorusunun metni karelerde görünmüyor; kurallar ve örnek altyazıdan aktarıldı. Örnekteki ikinci matrisin ikinci satırının yalnız 5'e karşılık gelen değeri (1) anlatıldı. -->

### 5.2 Çözümün incelenmesi

Çözümde istenmeyen birkaç ek de vardı (örneğin Türkçe karakter desteği), bunların yazılması şart değildi. Kütüphaneler eklendi ve en büyük sütun sayısı `#define MAX 100` olarak tanımlandı. `main` içinde `setlocale(LC_ALL, "Turkish")` ile Türkçe karakterlerin ekranda düzgün görünmesi sağlandı. İki matris `int matris1[2][MAX], matris2[2][MAX];` olarak tanımlandı: her biri iki satırlı, en çok `MAX` sütunlu. Sütun sayıları için `N`, `M`; döngüler için `i`, `j`, `k`; sonuç için `toplam`, `ortak_sayi`, `deger1`, `deger2` tanımlandı. Benzersizlik kontrolü için bir de `bayrak` değişkeni eklendi (ekrandan, 01:45:00).

İşaretçi aritmetiğiyle erişim şöyle çalışır: `matris1` iki satırlı dizinin başıdır. `*(matris1)` 0. satırın başını, `*(matris1 + 1)` 1. satırın başını gösterir. `*(matris1) + i` 0. satırın `i`. elemanının adresidir, yani `&matris1[0][i]`. Bu yüzden `scanf("%d", (*(matris1) + i));` doğrudan `matris1[0][i]` hücresine okur. `*(*(matris1) + i)` ise o hücrenin değeridir.

Birinci matrisin ilk satırı şöyle okunur. Örneğin $N = 5$ ise döngü 0'dan 4'e kadar 5 kez döner. Her yeni sayıdan önce bayrak sıfırlanır (0: tekrar yok). Sayı okunur ve iç döngüyle daha önce girilen sayılarla karşılaştırılır. Karşılaştırmanın sol tarafı yeni sayıyı, sağ tarafı daha önce girilmiş sayıyı tutar. Eşitse bayrak 1 yapılır. Bayrak 1 ise kullanıcı uyarılır ve `i--` yapılır. Döngü sonunda `i++` olacağı için aynı hücreye geri dönülür ve kullanıcıdan yeniden geçerli, benzersiz bir sayı istenir.

```c
    printf("İlk matris (2xN) için N değerini girin: ");
    scanf("%d", &N);
    printf("İlk matris elemanlarını girin (ilk satır: sayılar, ikinci satır: değerler):\n");
    printf("ilk satır..\n");
    for (i = 0; i < N; i++) {
        bayrak = 0;
        scanf("%d", (*(matris1) + i)); // matris1[0][i]
        for(k=0;k< i;k++){
            if(*(*(matris1) + i) == *(*(matris1) + k)){
                bayrak = 1;
            }
        }
        if(bayrak == 1){
            printf("Matrisin ilk satırı benzersiz olmalıdır..");
            i--;
        }
    }
```

(ekrandan, 01:45:00)

İkinci matris için aynı işlemler yapılır. İkinci satırlar benzersizlik kontrolü olmadan okunur:

```c
    printf("ikinci satır..\n");
    for (i = 0; i < M; i++) {
        scanf("%d", (*(matris2 + 1) + i));
    }
```

(ekrandan, 01:50:00)

Son olarak iki iç içe döngüyle birinci matrisin ilk satırındaki her sayı, ikinci matrisin ilk satırındaki her sayıyla karşılaştırılır. Eşitlik varsa sayı `ortak_sayi`'ya, iki matristeki karşılıkları `deger1` ve `deger2`'ye atanır ve toplamları yazdırılır:

```c
    printf("\nOrtak sayılar ve toplamları:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (*(*(matris1) + i) == *(*(matris2) + j)) {
                ortak_sayi = *(*(matris1) + i);
                deger1 = *(*(matris1 + 1) + i);
                deger2 = *(*(matris2 + 1) + j);
                toplam = deger1 + deger2;

                printf("%d -> %d + %d = %d\n", ortak_sayi, deger1, deger2, toplam);
            }
        }
    }
```

(ekrandan, 01:50:00)

<!-- BELİRSİZ: Kodun 27-45. satırları (birinci matrisin ikinci satırının okunması, M'nin okunması ve ikinci matrisin ilk satırının benzersizlik kontrolü) karelerde görünmüyor. Anlatımda "ikinci matris için de aynı işlemler" dendi; test sürümünde bu kısım birinci matrisle simetrik yazıldı (ara adım eklendi). -->

### 5.3 Çalıştırma

Derste şu girdilerle denendi: Birinci matris için $N = 3$. İlk satıra önce 1, sonra yine 1 girildi ve program "benzersiz olmalı" uyarısını verdi. Ardından 2 ve 3 girildi. İkinci satır 4, 2, 1 oldu. İkinci matris için $M = 2$; ilk satır 1, 5; ikinci satır 6, 4. İki ilk satırda ortak olan sayı 1'dir. 1'in birinci matristeki değeri 4, ikinci matristeki değeri 6'dır, toplamları 10'dur. Çıktı `1 -> 4 + 6 = 10` oldu.

Eksik satırlar simetrik tamamlanarak program `gcc -Wall` ile uyarısız derlendi. Aynı girdilerle `1 -> 4 + 6 = 10` sonucu alındı.

## 6. Örnek Sorular

**Soru 1** (derste sözlü, 00:05:25): Bir diziyi `int a[5];` gibi statik tanımlamak yerine `malloc` ile dinamik tanımlamanın avantajı nedir?

> **Cevap (derste verildi):** Statik tanımda yer, kullanılsa da kullanılmasa da ayrılmış kalır. Dinamik ayırmada yalnız gereken kadar yer alınır ve iş bitince `free` ile boşaltılabilir. Sınırlı bellek daha verimli kullanılır. Boyut bir değişkenle verildiği için dizinin boyutunu değiştirmek de kolaylaşır.

**Soru 2** (ekrandan, 00:10:00): Üç zar beraber atılıyor ve üst yüze gelen rakamlar toplanıyor. Üç zarın olası her toplam sonucunu birinci kolonda, olasılığını ikinci kolonda tutacağınız bir matrisi dinamik bellek allokasyonu ile tanımlayınız. Birinci kolondaki toplam değerleri tekrar etmemelidir (ilk kolon benzersiz olmalıdır). İkinci kolondaki olasılıkları döngü, kontrol ve aritmetik işlemlerle doldurunuz; `mat[i,j] = 0.0046296` gibi elle atama yapmayınız.

> **Çözüm (derste verildi):** Bölüm 2'deki program. 16 satırlı, 2 sütunlu `float**` matris kurulur; `mat[i][0] = i + 3`. Üç iç içe döngüde her üçlü için `mat[top-3][1] += (float)1/216` yapılır. Olasılıklar: 3 ve 18 için $1/216 \approx 0.00463$, 4 ve 17 için $3/216 \approx 0.01389$, 5 ve 16 için $6/216 \approx 0.02778$, 6 ve 15 için $10/216 \approx 0.04630$, 7 ve 14 için $15/216 \approx 0.06944$, 8 ve 13 için $21/216 \approx 0.09722$, 9 ve 12 için $25/216 \approx 0.11574$, 10 ve 11 için $27/216 = 0.125$ (çalıştırılan programın çıktısından).

**Soru 3** (ekrandan, 00:40:00): $f(n) = 3n+1$ ($n$ tek), $f(n) = n/2$ ($n$ çift) olsun. Kullanıcıdan pozitif bir $n$ okuyun. `calloc` ile 2 eleman için yer ayıran bir sepet dizisi oluşturun. $n$'ye $f$'yi 1 elde edilene kadar tekrar tekrar uygulayın ve her değeri sepete yazın; sepet dolduğunda boyutunu `realloc` ile 2 katına çıkarın. Sepeti ve hafızada kapladığı alanı yazdırın, sonra sepeti `free` edin. Örnek: $N = 13$ için sepet 13 40 20 10 5 16 8 4 2 1 olmalı.

> **Çözüm (derste verildi):** Bölüm 3'teki program. $N = 13$ için 10 eleman, kapasite 2 → 4 → 8 → 16; $N = 17$ için 17 52 26 13 40 20 10 5 16 8 4 2 1, 13 eleman, kapasite 16.

**Soru 4** (derste gösterildi, 01:11:53): Kullanıcıdan soda, meyve suyu, kola ve su için miktar alın. Birim fiyatları sabittir (10, 15, 20, 5). Her ürün için miktar ile birim fiyatın çarpımını ayrı bir fatura satırı olarak, en sonda da toplam tutarı yazdırın. Satırları dinamik bellekte string olarak tutun.

<!-- BELİRSİZ: Soru metni karede okunamadı; altyazıdaki anlatımdan kuruldu. -->

> **Çözüm (derste verilmedi):** Derste yazılan kod yalnız toplam tutarı yazdırdı ve çalışırken çöktü (bkz. Bölüm 4.5). Bölüm 4.5'teki düzeltilmiş ve test edilmiş program 4, 3, 1, 5 girdileri için satırları 40, 45, 20, 25 TL ve toplamı 130 TL olarak verir.

**Soru 5** (derste sözlü, 01:40:47; laboratuvar 1): İki satırlı iki matrisin sütun sayıları $N$ ve $M$ kullanıcıdan alınır. Her matrisin ilk satırı benzersiz sayılardan oluşur (tekrar girilirse uyarı verilip yeni sayı istenir), ikinci satır bu sayıların değerleridir. İki matrisin ilk satırında ortak olan sayıları bulup karşılık gelen değerlerin toplamını yazdırın. Matris elemanlarına yalnız işaretçi aritmetiğiyle erişin. Örnek: $\begin{bmatrix}1 & 5\\ 7 & 2\end{bmatrix}$ ve ilk satırı 2, 3, 5 olan, 5'in değeri 1 olan ikinci matris için sonuç 5 → 2 + 1 = 3.

> **Çözüm (derste verildi):** Bölüm 5'teki program. Derste denenen girdilerle (ilk satırlar 1 2 3 ve 1 5; değerler 4 2 1 ve 6 4) sonuç `1 -> 4 + 6 = 10`.

## Dersin Toparlaması

Bu uygulama dersinde dinamik bellek yönetiminin dört fonksiyonu üç farklı problem üzerinde kullanıldı. Zar olasılık matrisinde iki boyutlu bir `float**` matris iki aşamada (`malloc` ile satır işaretçileri, `calloc` ile satırlar) kuruldu ve tersten boşaltıldı. `calloc`'un sıfırlaması olasılıkların `+=` ile biriktirilmesini mümkün kıldı. Collatz sorusunda dolu eleman sayısıyla kapasiteyi ayrı tutup dizi dolunca `realloc` ile kapasiteyi ikiye katlama yöntemi görüldü. Fatura sorusunda `#define` sabitleri, `char**` ile satır dizisi ve `sprintf` ile biçimli string üretimi ele alındı. Bu sorunun derste yazılan kodu eksik kaldığı için düzeltilmiş bir sürüm bu notta verildi.

Son olarak birinci laboratuvar sorusunun çözümü incelendi. Burada iki boyutlu dizilere `*(*(m + r) + c)` biçiminde işaretçi aritmetiğiyle erişim, bir bayrak değişkeniyle benzersizlik kontrolü ve `i--` ile aynı hücreye geri dönme tekniği öne çıktı. Genel mesaj, sonucun doğruluğu kadar soruda istenen yöntemlere (burada işaretçi aritmetiği) uymanın da önemli olduğudur.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
