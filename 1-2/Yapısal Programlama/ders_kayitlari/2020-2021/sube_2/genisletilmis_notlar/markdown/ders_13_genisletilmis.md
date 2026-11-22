# Ders 13 Genişletilmiş Notu: Seyrek Matris Sıkıştırma, Komut Satırı Argümanları, Yapılar (struct) ve Bağlı Listelere Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Seyrek matris sıkıştırma örneğinin baştan yazılması
- 2. Derleme, test ve bellek hataları
- 3. Komut satırı argümanları
- 4. Yapılara (struct) neden ihtiyaç duyulur?
- 5. Struct tanımlama yolları ve typedef
- 6. Struct alanlarına erişim ve struct işaretçileri
- 7. Struct'ların fonksiyonlara aktarılması
- 8. Bağlı listelere giriş
- 9. Bağlı liste terimleri ve temel işlemler
- Örnek Sorular

## 1. Seyrek matris sıkıştırma örneğinin baştan yazılması

Ders, önceki derste kopyala-yapıştırla gösterilen seyrek (sparse) matris örneğinin bu kez baştan, satır satır yazılmasıyla başladı. Amaç hem dinamik bellek ve fonksiyon konularını tekrar etmek hem de kodu adım adım kurmaktı. Kod Dev-C++ ortamında yazıldı.

### 1.1 Problem

Seyrek matris, elemanlarının çoğu sıfır olan matristir. Böyle bir matrisi bütün hâliyle saklamak yer israfıdır. Sıkıştırılmış biçimde yalnız sıfırdan farklı elemanlar saklanır. Her sıfırdan farklı eleman için üç bilgi tutulur: satır indisi, sütun indisi ve değer. Örneğin orijinal matriste (4, 5) konumunda 1 varsa sıkıştırılmış matrise `4 5 1` satırı, (6, 3) konumunda 8 varsa `6 3 8` satırı yazılır. Böylece sıkıştırılmış matrisin 3 sütunu ve sıfırdan farklı eleman sayısı kadar satırı olur. Bu sayıya programda `counter` denir. Hoca satırlarla sütunların yer değiştirebileceğini de (3 satır, `counter` sütun) belirtti.

### 1.2 main ve iki boyutlu dinamik matris

`main` içinde matrisin satır ve sütun sayısı `M`, `N`; iki dinamik matris `matris` (orijinal) ve `c_matrix` (sıkıştırılmış); döngü değişkenleri `i`, `j` ve sıfırdan farklı eleman sayacı `counter` tanımlandı. `M` ve `N` önce kullanıcıdan `scanf` ile alındı (ekrandan, 00:10:00):

```c
int M, N;
int **matris, **c_matrix;
int i, j, counter = 0;
printf("M ve N "); scanf("%d %d", &M, &N);
matris = (int **) malloc(M * sizeof(int *));
for (i = 0; i < M; i++) {
    matris[i] = (int *) malloc(N * sizeof(int));
}
```

Hoca burada "Niye `sizeof` içinde `int *` yazıyoruz?" diye sordu.

**Soru:** Neden `sizeof(int *)`? **Cevap:** Bir öğrenci "satırların işaretçilerini tuttuğu için" dedi. Hoca açıkladı: matrisin `M` satırı vardır ve her satır kendi içinde ayrıca dinamik olarak açılır. Her satırın başlangıç adresi bir `int *`'tır. Bu `int *`'ları tutan dizi ikinci dereceden işaretçidir (`int **`). Dolayısıyla dış dizinin her elemanının boyutu `sizeof(int *)` olmalıdır. `int` ile `int *` boyutu her sistemde aynı olmayabileceği için `sizeof(int)` yazmak yanlış sonuç verebilir.

### 1.3 Veri girişi: enter_data ve `&` hatası

İlk fonksiyon matrise veri girer. Geriye değer döndürmediği için `void`'dir. Matrisin işaretçisi ve boyutları parametre olarak gelir (ekrandan, 00:10:00, 00:15:00):

```c
void enter_data(int **matris, int M, int N) {
    int i, j;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            printf("Matris[%d][%d]", i, j);
            scanf("%d", &matris[i][j]); // (*(matris+i)+j)
        }
    }
}
```

> **Hocanın vurgusu:** Çok yapılan bir hata: "`matris` zaten işaretçi, `&` kullanmaya gerek yok" diye düşünülür. Oysa `matris[i][j]` yazınca indisleme işaretçiden çıkıp doğrudan elemanın değerine ulaşır. `scanf` adres istediği için `&matris[i][j]` yazılmalıdır.

Diğer yol önceki derslerde gösterilen işaretçi aritmetiğidir: `*(matris+i)+j` matrisin i. satır j. sütununun adresidir; bu ifade bir kez daha `*` ile açılırsa o adresteki eleman elde edilir. Adres hâlini kullanırsanız `&` gerekmez.

### 1.4 count_data ve düşük bağlaşım, yüksek uyum

Veri girildikten sonra sıfırdan farklı eleman sayısını bulan ayrı bir fonksiyon yazıldı. Hoca her işi ayrı fonksiyona koymasının nedenini "düşük bağlaşım (low coupling), yüksek uyum (high cohesion)" ilkesiyle açıkladı: ileride bir değişiklik yapılırsa programın en az yeri etkilenmelidir. Bir öğrencinin "veri girişi neden ayrı fonksiyonda?" sorusunu da yemek benzetmesiyle cevapladı: yemek elle de yenebilir ama kaşığın bir amacı vardır; programı modüler yapma düşüncesi de böyledir.

```c
int count_data(int **matris, int M, int N) {
    int i, j, c = 0;
    for (i = 0; i < M; i++)
        for (j = 0; j < N; j++)
            if (matris[i][j] != 0)
                c++;
    return c;
}
```

`main`'de çağrı `counter = count_data(matris, M, N);` biçimindedir (ekrandan, 00:25:00).

### 1.5 display_matris

Matrisi ekrana yazan fonksiyon, hangi matrisin yazıldığını gösteren bir mesaj (string) da alır: `void display_matris(char *str, int **matris, int M, int N)`. Gönderilen string'in adresi `str` işaretçisine kopyalanır, `printf("%s", str)` ile basılır. `%s` string yazılacağını belirtir. Sayılar hizalı görünsün diye `%3d` gibi genişlikli biçim kullanıldı. Çağrılar (ekrandan, 00:25:00):

```c
display_matris("Original matrix\n", matris, M, N);
display_matris("Compressed matrix\n", c_matrix, M, N);   /* hatalı, bkz. 2.3 */
```

<!-- BELİRSİZ: display_matris fonksiyonunun gövdesi karelerde görünmedi; biçim ayrıntısı (%3d ve boşluk) altyazıdan kuruldu. -->

### 1.6 matris_compress

Sıkıştırma fonksiyonu orijinal matrisi, boyutları ve `counter`'ı alır, yeni bir matris döndürür. Önce `counter x 3` boyutunda yer açılır, sonra orijinal matriste iki döngüyle gezilir. Sıfırdan farklı her eleman için `k`. satırın 0. hücresine `i`, 1. hücresine `j`, 2. hücresine değer yazılır ve `k` bir artırılır. `k` sıfırdan başlar. İlk yazılan hâl (ekrandan, 00:20:00):

```c
int **matris_compress(int **matris, int M, int N, int counter) {
    int **m;
    int i, j, k = 0;
    m = (int **) malloc(counter * sizeof(int *));
    for (i = 0; i < counter; i++) {
        m[i] = (int *) malloc(3 * sizeof(int));
    }
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            if (matris[i][j] != 0) {
                m[k][0] = i;
                m[k][1] = j;
                m[k][1] = matrix[i][j];   /* iki hata: [2] olmalı, ad matris olmalı */
                k++;
            }
        }
    }
    return m;
}
```

Fonksiyon yeni matrisi döndürdüğü için dönüş tipi `void` değil `int **` olmalıdır; `main`'de `c_matrix = matris_compress(matris, M, N, counter);` ile atanır. Hoca, `return` yazıp dönen değeri bir değişkene atamamanın işe yaramayacağını da hatırlattı.

### 1.7 free_matris

Dinamik matris, ayrıldığı sıranın tersine bırakılır: önce satır sayısı kadar her satır işaretçisi, en son işaretçi dizisinin kendisi (ekrandan, 00:25:00):

```c
void free_matris(int **matris, int M) {
    int i;
    for (i = 0; i < M; i++) {
        free(matris[i]);
    }
    free(matris);
}
```

`main`'in sonunda `free_matris(matris, M);` ve sıkıştırılmış matris `counter` satırlı olduğu için `free_matris(c_matrix, counter);` çağrılır.

## 2. Derleme, test ve bellek hataları

### 2.1 Prototipler

İlk derlemede derleyici, fonksiyonlar `main`'den sonra yazıldığı için hata ve uyarı verdi. Fonksiyon başlıkları kopyalanıp `main`'den önce noktalı virgülle yapıştırıldı; parametre adları silindi, çünkü prototipte yalnız tipler gerekir (ekrandan, 00:45:00):

```c
void free_matris(int **, int);
int **matris_compress(int **, int, int, int);
void enter_data(int **, int, int);
void display_matris(char *, int **, int, int);
int **matrix_allocate(int, int);
```

Fonksiyonlar `main`'den önce yazılsaydı prototipe gerek olmazdı. Hoca, özellikle parametrelerinde işaretçi bulunan fonksiyonlarda prototip yazmanın gerektiğini; bazı derleyicilerin yalnız uyarı verdiğini, standarda sıkı uyan derleyicilerin ise derlemeyebileceğini söyledi. İleride başlık (header) dosyaları işlendiğinde bu prototiplerin ayrı bir dosyaya taşınacağını ekledi. Ayrıca `matrix` diye yazılan bir değişken adı "undeclared" hatası verdi; doğru ad `matris` idi.

### 2.2 İlk test ve sıkıştırma hatası

3x3 bir matrisle ilk denemede sıkıştırılmış matris yanlış çıktı. **Soru:** Bir öğrenci "`m[k][1]`'i iki kez kullandık, sorun orası olabilir mi?" diye sordu. **Cevap:** Hoca hatayı doğruladı: üçüncü atama `m[k][2] = matris[i][j];` olmalıdır. Düzeltmeden sonra şu girdiyle sonuç doğru çıktı (derste sözlü, 00:26:08):

- Orijinal matris: $\begin{pmatrix} 0 & 2 & 0 \\ 0 & 0 & 3 \\ 0 & 5 & 0 \end{pmatrix}$
- Sıkıştırılmış matris: `0 1 2` (0. satır 1. sütunda 2), `1 2 3` (1. satır 2. sütunda 3), `2 1 5` (2. satır 1. sütunda 5).

### 2.3 free gerçekten gerekli mi?

**Soru:** Bir öğrenci, yazdırma bittikten sonra program zaten sona erdiğine göre `free`'nin gereksiz olup olmadığını sordu. **Cevap:** Hoca gerekli olduğunu söyledi. Program kapatılsa bile bazı durumlarda süreç hemen ölmeyebilir, arka planda çalışmaya devam edebilir; serbest bırakılmayan bellek işgal edilmeye devam eder. Uzun süre açık kalan programlarda (örneğin çok sekme açılan tarayıcılarda) belleğin zamanla dolması bu bellek sızıntısının (memory leak) tipik görüntüsüdür; bellek kullanımını analiz eden araçlar da vardır. Özellikle çöp toplayıcısı (garbage collector) olmayan dillerde ve eski işletim sistemlerinde, program çökse bile belleğin o bölgesi kullanılıyor görünebilir.

> **Ders sonrası not:** Günümüz işletim sistemleri süreç sonlandığında o sürecin belleğini büyük olasılıkla geri alır. Asıl risk, uzun süre çalışan ya da döngü içinde sürekli bellek ayıran programlarda biriken sızıntıdır. Her `malloc`'a karşılık bir `free` yazmak yine de doğru alışkanlıktır.

### 2.4 Tekrarlanan kodu fonksiyona taşımak: matrix_allocate

Hoca, matris ayırma kodunun hem `main`'de hem `matris_compress`'te tekrarlandığını (duplicated code) gösterdi. İkisi de aynı türde bir matrisi açtığı için ortak bir fonksiyon yazıldı (ekrandan, 00:30:00):

```c
int **matrix_allocate(int M, int N) {
    int **m;
    int i;
    m = (int **) malloc(M * sizeof(int *));
    for (i = 0; i < counter; i++) {      /* hata: M olmalı */
        m[i] = (int *) malloc(N * sizeof(int));
    }
    return m;
}
```

Ayrılan yerin gerçekten ayrılıp ayrılmadığı (`NULL` denetimi) burada atlandı; hoca bu kontrollerin eklenebileceğini ama kodu uzatacağını söyledi. Döngü sınırı `matris_compress`'ten kopyalandığı için `counter` kalmıştı; `M` olarak düzeltildi. Artık `main`'de `matris = matrix_allocate(M, N);`, `matris_compress` içinde `m = matrix_allocate(counter, 3);` yazılır. Hoca, program birden fazla `.c` dosyasından oluştuğunda böyle ortak bir fonksiyonun diğer dosyalardan da erişilebilir yapılacağını ve buna ileride gelineceğini söyledi.

### 2.5 Ayrılan alanın dışına çıkmak

Değişiklikten sonraki denemede program sıfır yerine bir hata koduyla döndü. Hoca `printf("Yazdirma bitti")` gibi ara çıktılar koyarak hatanın yerini aradı ve nedeni buldu: sıkıştırılmış matris `display_matris("Compressed matrix\n", c_matrix, M, N);` ile `M x N` diye basılıyordu. Oysa sıkıştırılmış matriste `M` değil `counter` satır ve 3 sütun vardır (ekrandan, 00:35:00).

Hoca bunu iki girdiyle gösterdi. Sıfırdan farklı eleman sayısı tesadüfen 3 olduğunda (`counter` = `M` = 3) hata görülmedi. 3x3 matriste yalnız bir eleman sıfırdan farklı girildiğinde ise bir satırlık yer ayrılmış ama 3x3'lük alana erişilmeye çalışılmıştı; program "alanının dışına çıkıyorsun" hatasıyla bitti. Bu hata dinamik bellekte (heap) izin verilmeyen bir yere erişmekten kaynaklanır. Doğru çağrı:

```c
display_matris("Compressed matrix\n", c_matrix, counter, 3);
```

## 3. Komut satırı argümanları

### 3.1 main de parametre alabilir mi?

Bütün fonksiyonlar parametre alır ve çağrılırken onlara argüman gönderilir. Acaba `main` de parametre alabilir mi? Evet: program komut satırından çalıştırılırken argüman gönderilebilir. Slayttaki tanım (ekrandan, 00:40:00): her C programında ilk çalışan fonksiyon `main`'dir; `main` döndüğünde program biter; derleyici `main`'i diğer fonksiyonlar gibi ele alır, ancak çalışma anında iki argümanı sağlamak çalışma ortamının sorumluluğundadır:

- `argc` (argument count): komut satırında verilen argüman sayısı.
- `argv` (argument vector): komut satırı argümanlarını gösteren işaretçi dizisi.

Slayttaki örnek bütün argümanları alt alta basar:

```c
main(int argc, char *argv[]) {
    while (--argc > 0)
        printf("%s\n", *++argv);
    exit(0);
}
```

`argv[0]` her zaman programın adıdır; sonra programın adından sonra boşlukla ayrılarak yazılan her şey sırayla gelir. Argümanlar her zaman string olarak alınır, çünkü `argv`'nin tipi `char *[]`'dır; başka tipte alınamaz. Sonraki slaytta argümanları seçeneklerine göre işleyen, `switch-case` kullanan daha gelişmiş bir yöntem gösterildi.

### 3.2 Programı komut penceresinden çalıştırmak

Hoca, kaynak dosyayı bir klasöre kopyalayıp Dev-C++'ta "Execute > Compile" ile derledi; derleme `.exe` dosyasını oluşturur. Klasörde komut penceresi açmak için Windows Gezgini'nde sağ tıklayıp komut penceresini o yolda açmak ya da komut penceresini açıp `cd` (change directory) ile klasöre gitmek mümkündür. `dir` klasördeki dosyaları listeler, `cls` ekranı temizler (ekrandan, 00:45:00). `s1.exe` ya da yalnız `s1` yazılınca program çalışır. Ctrl+C programa bir sonlandırma sinyali gönderir; hoca bunun her zaman programı öldürmediğini, ayrıntıların işletim sistemleri dersinde anlatılacağını söyledi.

Komut satırını kullanmadan da argüman verilebilir: Dev-C++'ta "Execute > Parameters" penceresine argümanlar (örneğin `4 6`) yazılıp "Run" denir.

### 3.3 Argümanları okumak ve sayıya çevirmek

`main` şu biçimde yazıldı ve argümanlar önce string olarak basıldı (ekrandan, 00:45:00):

```c
int main(int argc, char *argv[]) {
    /*int M, N;
    M = argv[1];
    N = argv[2];*/
    printf("%s %s", argv[1], argv[2]);
    ...
}
```

**Soru:** Bir öğrenci, `argv` elemanları string olduğu için `=` yerine `strcpy` ile kopyalamak gerekip gerekmediğini sordu. **Cevap:** Hoca string işlemlerini henüz ayrıntılı anlatmadığını, buna ileride gelineceğini söyledi; şimdilik argümanlar `%s` ile doğrudan basıldı. Sonra sayıya çevirme gösterildi.

Argüman hiç verilmezse `argv[1]` olmadığı için program hata verdi. Bunu önlemek için `argc` denetlendi: yalnız program adı varsa `argc == 1`'dir (ekrandan, 00:50:00):

```c
int M, N;
if (argc == 1) {
    printf("%d sayıda argüman: Boyutlar girilmedi", argc);
}
else {
    M = atoi(argv[1]);
    N = atoi(argv[2]);
    printf("%d sayıda argüman: %d %d", argc, M, N);
}
```

String'i sayıya çevirmek için `atoi` (tamsayı) ve `atof` (ondalık sayı) fonksiyonları kullanılır. Hoca, `float`'tan `int`'e dönüşümün örtük ya da açık (implicit/explicit) yapılabildiğini, ancak string'in böyle doğrudan dönüştürülemediğini hatırlattı. Komut penceresindeki denemeler (ekrandan, 00:50:00):

- `s1` → `1 sayıda argüman: Boyutlar girilmedi`
- `s1 4 5` → `3 sayıda argüman: 4 5` (program adı, 4 ve 5)
- `atoi` eklenmeden önce `s1 aaa 5` → `3 sayıda argüman: aaa 5`
- `atoi` eklendikten sonra `s1 aaa 5` → `3 sayıda argüman: 0 5`; "aaa" sayıya çevrilemediği için 0 oldu.

> **Ders sonrası not:** Hoca `atoi`'yi "argument to integer" diye açıkladı. Adın açılımı "ASCII to integer"dır (`atof`: "ASCII to float"). Yaptığı iş aynıdır.

### 3.4 Sparse matris programına uygulama

Sonunda sparse matris programında `M` ve `N` artık `scanf` ile değil komut satırından alındı. Hoca değişken tanımlarını fonksiyonun en üstüne taşıdı ve C'de değişkenlerin her zaman en yukarıda tanımlanması gerektiğini söyledi. `s1 4 5` ile çalıştırılınca program 4x5 matrisin elemanlarını istedi. Sıkıştırılmış matrisin yazdırılmasında yine eski `M` değeri kaldığı fark edildi ve `counter` satır, 3 sütun olarak düzeltildi. Programın son hâli kısa notta derlenmiş ve denenmiş olarak verilmiştir.

> **Ders sonrası not:** "Değişkenler en başta tanımlanmalı" kuralı C89/C90 standardı içindir. C99 ve sonrasında değişkenler blok içinde herhangi bir yerde tanımlanabilir. Eski derleyici ayarlarıyla uyum için en başta tanımlamak yine güvenlidir.

### 3.5 Soru tipi hakkında akademik bir not

Hoca bu tür bir problemde fonksiyon prototiplerinin verilip içlerinin ve nasıl çağrılacaklarının yazdırılabileceğini söyledi. Fonksiyonların içindeki algoritmalar (örneğin matristeki sıfırları saymak) önceki dönemin konusudur; bu dersin ağırlığı C dilini kullanma becerisidir, algoritmalar basit tutulur (en küçük, en büyük bulma gibi).

## 4. Yapılara (struct) neden ihtiyaç duyulur?

Teori kısmı yapılar (structures) slaytlarıyla devam etti. Slayttaki konu başlıkları: struct tanımı, iç içe struct'lar, struct dizileri, struct'ların fonksiyon parametresi olarak aktarılması, bir örnek olarak bağlı liste gerçekleştirimi, union tanımı ve union'ların fonksiyona aktarılması (ekrandan, 00:55:00).

Şimdiye kadar hep tek veri tipleriyle (`int`, `char`, `float`) çalışıldı. Oysa günlük hayatta uğraştığımız nesnelerin birden çok özelliği vardır. En basit örnek karmaşık sayıdır: $a + bi$ biçiminde bir gerçel (real) ve bir sanal (imaginary) kısımdan oluşur. Bir öğrencinin adı, yaşı ve başka birçok özelliği vardır.

100 öğrenci üzerinde işlem yapacak olsak, adlar için 100 elemanlı bir dizi, yaşlar için 100 elemanlı başka bir dizi açabiliriz. Ama bu yaklaşım "temel veri tiplerine takıntı" (primitive obsession) denen bir kod kusuru doğurur: bir kişiyle ilgili bütün bilgileri bir fonksiyona göndermek için `f(ad, yas, ...)` gibi uzun parametre listeleri yazılır. Bunun yerine bütün alanları tek bir tipte toplayıp `f(kisiler)` biçiminde göndermek çok daha derli topludur (ekrandan, 00:55:00). Struct'lar bir programlama kolaylığıdır, bir veri yapısı biçimidir ve birçok veri yapısı buradan türeyecektir.

Hoca konuların birleşimine dikkat çekti: önce işaretçiler, sonra dinamik bellek (DMA), sonra fonksiyonlar görüldü; şimdi struct ekleniyor. Struct'ı fonksiyona göndermek, struct'ı dinamik oluşturmak, struct'a işaretçiyle erişmek, işaretçiyle erişilen dinamik struct'ı fonksiyona göndermek gibi farklı birleşimlerle karşılaşılacaktır.

Struct ayrıca nesneye yönelik programlamanın (OOP) tabanıdır. OOP'de sınıf (class) vardır; sınıflar alanların yanında metotlar da içerir. C'deki struct, sınıfın yalnız alanlardan oluşan, metotsuz hâli gibi düşünülebilir.

## 5. Struct tanımlama yolları ve typedef

### 5.1 Temel tanım

Struct tanımında önce `struct` anahtar kelimesi, sonra struct'ın adı yazılır; süslü parantez içinde alanlar bellekte sıralanmasını istediğimiz sırayla tek tek yazılır ve tanım noktalı virgülle biter. Slayttaki çalışan (employee) örneğinde alanlar `char name[20], surname[20]; int ID; float salary;` biçimindedir.

Struct tanımı global olabilir ya da bir fonksiyonun içinde yapılabilir; daha önce görülen kapsam (scope) kavramlarının hepsi geçerlidir. Hocanın önerisi: struct'ın tanımını global yapın, değişkenleri fonksiyonların içinde üretin.

`struct employee` ifadesi bir bütün olarak `int` gibi bir tip adıdır. Bu tipten 1000 elemanlı bir dizi, bir işaretçi ya da tek bir değişken üretilebilir. Slayttaki dizide her ismin 20 karakter olduğu ve en fazla 1000 kişi saklanabildiği belirtildi; 1001. kişi gelirse program taşar. Bu yüzden ileride dinamik bellekle kişi işaretçisi kullanılacağı söylendi.

### 5.2 typedef

Her tanımlamada `struct employee` yazmak yerine kısa bir ad kullanmak daha makuldür. `typedef` bir tipe yeni bir ad verir: `typedef int tamsayi;` yazılırsa bundan sonra `int` yerine `tamsayi` kullanılabilir. Struct için `typedef` tanımın başına yazılır, kapanan süslü parantezden sonra da yeni ad gelir (ekrandan, 01:00:00):

```c
typedef struct {
    char name[20], surname[20];
    int ID;
    float salary;
} EMPLOYEE;

EMPLOYEE employees[1000];
```

Slayta göre bu durumda `EMPLOYEE`, `struct` anahtar kelimesi dahil bütün struct tanımını temsil eder; büyük harf kullanmak, bu tür adları sıradan değişken adlarından ayırmak için bir adlandırma geleneğidir. Bir yol daha vardır: önce struct ayrı tanımlanır, sonra tek satırda `typedef struct Employee EMPLOYEE;` yazılır.

**Soru:** "Aynı programda struct'ı tekrar kullanamayız" ne demek? **Cevap:** Tanımlanan struct, `int`'in tanımı gibidir; `int`'ten istediğiniz kadar değişken üretebildiğiniz gibi bu struct'tan da istediğiniz kadar değişken üretebilirsiniz. Ama aynı adla ikinci bir struct tanımlayamazsınız; başka bir struct için başka ad vermek gerekir.

### 5.3 Kodda üç tanım yolu

Hoca karmaşık sayı için daha basit bir struct ile üç tanım yolunu aynı dosyada yazdı (ekrandan, 01:05:00, 01:10:00):

```c
#include <stdio.h>
struct Complex {
    int r;
    int i;
};
typedef struct complex {
    int r;
    int i;
} COMPLEX;
typedef struct Complex CMP;

int main() {
    struct Complex c1;
    COMPLEX c3, *c2;
    c2 = &c3;
    CMP c4[3];
    ...
}
```

`struct Complex` (büyük C) ile `struct complex` (küçük c) görünüşte aynı ama farklı iki tiptir. Üç yolla da değişken, işaretçi ve dizi üretilebilir.

> **Hocanın vurgusu:** Struct işaretçilerinde sık yapılan karışıklık: struct değişkeni (`c3`) alanların kendisini tutar; struct işaretçisi (`c2`) ise bir struct'ın adresini tutar. Tıpkı `int`'in tamsayı, `int *`'ın tamsayı adresi tutması gibi bunlar çok farklı şeylerdir. Bir dizinin başlangıç adresini tutmak istiyorsanız işaretçi kullanırsınız.

### 5.4 #define ile typedef farkı

**Soru:** Bir öğrenci aynı işin makroyla (`#define`) yapılıp yapılamayacağını sordu: `#define` ile `struct Complex` yerine kısa bir ad yazılsa olur mu? **Cevap:** Hoca önce `#define`'ın bir makro olduğunu, tip tanımlamasıyla doğrudan ilgili olmadığını söyledi ve daha önce denemediğini belirtti. Birlikte denendi. İlk denemede makronun sırası ve yazımı yüzünden "unknown type" hatası alındı. Öğrencinin önerisiyle büyük-küçük harf düzeltilince çalıştı (ekrandan, 01:15:00):

```c
#define CMP2 struct Complex
...
CMP2 c5;
c5.r = 44;
c5.i = 6;
```

Önişlemci `CMP2` gördüğü her yere `struct Complex` metnini koyar. Hocanın tercihi yine `typedef`'tir: makrolar daha çok fonksiyon benzeri kısaltmalarda, `typedef` ise tip tanımlamalarında kullanılır.

## 6. Struct alanlarına erişim ve struct işaretçileri

### 6.1 Nokta operatörü

Struct değişkeninin alanlarına nokta (`.`) operatörüyle erişilir. Editörde `c1.` yazınca alanlar seçenek olarak çıkar. Örnek (ekrandan, 01:15:00):

```c
c1.r = 4;
c1.i = 6;
c4[3].r = 0;
c4[3].i = 8;
printf("%d - %di\n", c1.r, c1.i);
printf("%d - %di\n", c4[3].r, c4[3].i);
```

Çıktıda `4 - 6i` ve `0 - 8i` görüldü. Dizi ile struct burada iç içe girdi: `c4`'ün bir elemanının gerçel kısmına gidip 0 yazıldı. Hoca bu dizilerin dinamik de olabileceğini, `malloc` için işaretçiye ihtiyaç olacağını söyledi ve tanım yollarından `typedef`'li olanı tavsiye etti.

> **Ders sonrası not:** `CMP c4[3];` üç elemanlıdır; geçerli indisler 0, 1, 2'dir. Derste yazılan `c4[3]` dizi sınırının dışındadır. Program çalışmış görünse de bu tanımsız davranıştır; `c4[2]` yazılmalıydı.

### 6.2 İşaretçiyle erişim: `->` ve `(*p).`

Struct'a işaretçiyle erişmek için iki yol vardır: ok operatörü `c2->r` ya da `(*c2).r`. İkinci yolda önce işaretçideki adres `*` ile açılır, sonra nokta ile alana gidilir. Ok operatörü bu işi daha derli toplu yapar.

> **Hocanın vurgusu:** İşaretçi önce bir yeri göstermelidir. Slayttaki bir örnekte `EMPLOYEE *e_ptr;` tanımlanmış ama bir yere bağlanmadan alanına yazılmıştı; bu yanlıştır. Önce `EMPLOYEE e;` oluşturulmalı, sonra `e_ptr = &e;` yazılmalıdır. Aynı şey `int` için de geçerlidir: `int *pa;` bir yeri göstermeden `*pa = 9;` yazılamaz. Hoca bunu "bilgisayar müneccim değil" diye anlattı: `pa`'nın nereyi gösterdiğini bilemez.

Derste önce `c2 = &c3;` satırı yorum yapıldı ve `c2.r` yazıldı; derleyici `c2`'nin struct değil işaretçi olduğunu söyleyip hata verdi. `c2->r` ile derlendi ama `c2` hiçbir yeri göstermediği için çalışma anında beklenen çıktı alınamadı. `c2 = &c3;` geri açılınca önce `c3`'ün içindeki değerler (`0 0`) görüldü, sonra `c2->r = 999;` ve `(*c2).i = 880;` ile `999 - 880i` elde edildi (ekrandan, 01:15:00).

Hoca bu sırada struct tanımlanınca alanların varsayılan olarak sıfırlandığını hatırladığını ama emin olmadığını söyledi.

> **Ders sonrası not:** Yerel (otomatik) struct değişkenlerinin alanları sıfırlanmaz, çöp değer içerir. Yalnız global ve `static` değişkenler sıfırla başlar. Derste görülen `0 0` tesadüftür.

### 6.3 Operatör önceliği: neden `(*c2).i`?

Parantez konmazsa `*c2.i` yazılmış olur. Nokta (üye erişim) operatörünün önceliği `*` (dereferans) operatöründen yüksektir; bu yüzden ifade `*(c2.i)` olarak okunur. `c2` bir taban adres tuttuğu için onun `.i` alanı diye bir şey yoktur ve derleme hatası alınır. Bu yüzden parantez şarttır. Hoca her zaman `->` kullanmayı tavsiye etti; birçok dilde benzer bir notasyon görüleceğini söyledi.

### 6.4 İç içe struct

Bir struct başka bir struct'ı alan olarak içerebilir. Örneğin kişilerin doğum ya da işe giriş tarihleri: önce içteki struct tanımlanır (`typedef struct date {...} DATE;` gün, ay, yıl), sonra çalışan struct'ında `DATE` tipinde bir alan tutulur. Bir çalışan değişkeninin `enlisted` alanının içindeki `year` alanına 2008 yazmak için `kisi.enlisted.year = 2008;` yazılır. Klavyeden okumak için başına `&` konur: `scanf("%d", &kisi.enlisted.year);`.

## 7. Struct'ların fonksiyonlara aktarılması

### 7.1 Değerle ve referansla aktarım

Değişkenlerde görülen değerle aktarım (pass by value) ve referansla aktarım (pass by reference) struct'larda da vardır. Slayttaki iki yol (ekrandan, 01:20:00):

- Struct'ın kendisini göndermek (pass by value): `EMPLOYEE emp; printReport(emp);`
- Struct'ın işaretçisini göndermek (pass by reference): `EMPLOYEE emp; increaseSalary(&emp);`

Bir struct değişkeni fonksiyona gönderilirse kopyası gider (hoca bunu "deep copy" diye adlandırdı); fonksiyondaki değişiklik çağırana yansımaz. İşaretçisi gönderilirse aynı bellek üzerinde çalışılır. Slayta göre referansla aktarım daha hızlı ve verimlidir. Fonksiyonun parametresi seçime göre struct ya da struct işaretçisi olarak tanımlanır ve gövdede `.` ya da `->` kullanılır. İşaretçi bütün struct'ı gösterir, yalnız ilk alanını değil.

### 7.2 Struct dizisini ekrana yazmak

Üç elemanlı bir karmaşık sayı dizisi bir fonksiyona gönderildi. Ekrana yazmada değişiklik olmayacağı için değerle de referansla da aktarılabilir. İlk sürüm (ekrandan, 01:30:00):

```c
void ekrana_yaz(COMPLEX c[3]) {
    int i = 0;
    for (i = 0; i < 3; i++) {
        printf("%d %dj\n", c[i].r, c[i].i);
    }
}
```

Hoca sanal birim için `i` yerine `j` yazdı; mühendislikte (sinyaller ve sistemlerde) `j` kullanıldığını hatırlattı. Derlemede döngü değişkeninin tanımlanmadığı görüldü; hoca C'de döngü değişkeninin `for` içinde değil fonksiyonun başında tanımlanması gerektiğini söyledi (bu kuralın C89'a ait olduğu için 3.4'teki ders sonrası nota bakın). Sonra fonksiyon dizi boyutunu parametre olarak alacak biçimde `void ekrana_yaz(COMPLEX c[], int N)` yapıldı. Fonksiyonlardan geriye dizi döndürülemediğini de hatırlattı.

### 7.3 Dizi, eleman ve adres göndermek

Elemanları sıfırlayan üç fonksiyon yazıldı ve prototipleri `typedef`'ten sonra eklendi (ekrandan, 01:45:00, 01:50:00):

```c
void sil(COMPLEX c[], int N);
void silref(COMPLEX *c);
void silvalue(COMPLEX c);
...
COMPLEX c[3], *c2;
int N = 5;
ekrana_yaz(c, 3);
sil(c, 3);   // array-pass by ref
printf("\n%d %d", c[2].r, c[2].i);
silvalue(c[2]);
printf("\n%d %d", c[2].r, c[2].i);
printf("\n%d %d", c[2].r, c[2].i);
silref(&c[2]);
printf("\n%d %d", c[2].r, c[2].i);
```

Gövdeler: `sil` döngüyle `c[j].r = c[j].i = 0;` yapar; `silvalue` içinde `c.r = c.i = 0;`; `silref` içinde `c->r = c->i = 0;`. Sonuçlar:

- `sil(c, 3)`: dizi gönderildiği için referansla gider, elemanlar `main`'de de sıfırlanır.
- `silvalue(c[2])`: tek eleman değerle gider; fonksiyon içindeki sıfırlama `main`'e yansımaz, `c[2]` eski değerini korur (derste `2 0` çıktısı değişmedi, ekrandan, 01:35:00).
- `silref(&c[2])`: elemanın adresi gider; `c[2]` gerçekten `0 0` olur.

Hoca bunun yalnız silme için değil, iki elemanın yerini değiştirme (swap) gibi işlemler için de aynı şekilde geçerli olduğunu söyledi. Prototipler eklenmeden önce derleyici "implicit declaration" ve "conflicting types" uyarıları verdi; struct tipinin tanımı nedeniyle prototiplerin eklenmesi gerektiğini belirtti.

### 7.4 Dinamik struct dizisi

Struct dizisi `malloc` ile de oluşturulabilir. `malloc` bir `void *` döndürür, bu `COMPLEX *` tipine dönüştürülür (cast). Sonuç, her elemanında bir gerçel ve bir sanal kısım bulunan `N` elemanlı bitişik bir dizidir (ekrandan, 01:40:00, 01:45:00):

```c
c2 = (COMPLEX *) malloc(N * sizeof(COMPLEX));
ekrana_yazv2(c2, N);
sil_v2(c2, N);
ekrana_yazv2(c2, N);
```

Fonksiyon bu kez parametreyi dizi değil işaretçi olarak alır (ekrandan, 01:40:00):

```c
void ekrana_yazv2(COMPLEX *c, int N) {
    int j = 0;
    for (j = 0; j < N; j++) {
        printf("%d %dj\n", c[j].r, c[j].i);
    }
}
```

`c[j]` j. hücrenin başlangıcına götürür; o hücrenin içinde `r` ve `i` ayrı adreslerdedir, `.r` ve `.i` bunlara ulaşır. **Soru:** Bir öğrenci, işaretçiyle gelindiğine göre noktayla değil ok işaretiyle (`->`) erişmek gerekip gerekmediğini sordu. **Cevap:** Hoca, işaretçi aritmetiğiyle `(c+j)->r` biçiminde yazıldığında ok işareti gerektiğini ve operatör önceliğinden kaynaklı karışıklığa dikkat edilmesi gerektiğini söyledi; ancak `c[j]` indislemesi işaretçi aritmetiğini kendisi yaptığı için `c[j].r` yazımı da doğrudur. Önce bilinmeyen değerler basıldı, `sil_v2` sonrasında bütün elemanlar 0 çıktı.

## 8. Bağlı listelere giriş

### 8.1 Neden bağlı liste?

`N` tane karmaşık sayı saklamak istiyoruz. Dizi ya da `malloc` ile açılan bir blok, bellekte bitişik adreslerde durur. Ama her zaman o kadar bitişik yer bulunamayabilir. Bağlı liste (linked list) bu sorunu çözer: elemanlar bellekte farklı yerlerdedir, birbirine bitişik değildir. Bitişik olmadıkları için bir yerden başlayıp bütün elemanları gezebilmek gerekir; bu yüzden her eleman bir sonrakinin yerini saklar.

Bağlı listenin her elemanına düğüm (node) denir. Düğümde istenildiği kadar veri alanı bulunabilir; ayrıca bir sonraki düğümün adresini tutan bir işaretçi alanı zorunludur. Son düğümün işaretçisi `NULL` gösterir. Yapının bütününe bağlı liste, her elemanına düğüm denir (ekrandan, 02:05:00).

Hoca meşhur bir problemi örnek verdi: `int` ya da `long` tipine sığmayan 40 basamaklı iki sayıyı toplamak. Her basamak bir liste düğümünde (ya da 40 elemanlı bir tamsayı dizisinin bir elemanında) tutulursa çok büyük sayılar üzerinde toplama, çıkarma, çarpma ve bölme yapılabilir.

### 8.2 Kendine işaret eden struct

`int a`, `int *pa`, `int **ppa` birbirinden farklı tiplerdir. Aynı mantıkla struct kendi tipinde bir işaretçi içerebilir. Slayttaki çalışan örneği (ekrandan, 02:00:00):

```c
typedef struct Employee {
    char name[20], surname[20];
    int ID;
    float salary;
    struct Employee *next;
} EMPLOYEE;
EMPLOYEE *head;
```

Hoca, struct'ın içine kendi tipinden bir alan (`struct complex c;`) koymanın sonsuz özyinelemeye yol açacağı için derlenmediğini, ama işaretçinin (`struct complex *next;`) sorunsuz derlendiğini gösterdi. Bu alana genellikle `next` adı verilir.

### 8.3 Düğümleri oluşturmak ve bağlamak

Düğümler dinamik bellekle oluşturulmalıdır. Önce `int` örneğiyle işaretçinin bir yeri göstermesi gerektiği tekrar edildi, sonra iki tek elemanlı düğüm açılıp bağlandı (ekrandan, 01:55:00):

```c
int a = 7;
int *pa;
pa = &a;
*pa = 9;

COMPLEX *c5 = malloc(1 * sizeof(COMPLEX)); c5->r = 1; c5->i = 2;
COMPLEX *c6 = malloc(1 * sizeof(COMPLEX)); c6->r = 3; c6->i = 4;
c5->next = c6;
c6->next = NULL;
printf("%d %d --- %d %d    ", c5->i, c5->r, c5->next->r, c5->next->r);
```

`c5` bir işaretçi olduğu için alanlara `.` ile değil `->` ile erişilir. `c5->next` artık `c6`'dır; `c5->next->r`, `c6`'nın gerçel kısmıdır. İlk çalıştırmada `printf` yanlış yazıldığı için (`pritnf`) bağlayıcı hatası alındı. Düzeltilince çıktı `2 1 3 3` oldu, çünkü son iki alan da `->r` yazılmıştı. Biri `->i` yapılınca `2 1 4 3` elde edildi. Yapılan tek şey struct tanımına aynı tipten bir işaretçi eklemek oldu.

Sonra `c7` (gerçel 5, sanal 6) eklendi: `c6->next = c7; c7->next = NULL;`.

### 8.4 Listeyi gezmek ve dairesel liste

Listeyi gezmek için geçici bir işaretçi kullanıldı:

```c
COMPLEX *tmp;
tmp = c5->next;
while (tmp != NULL) {
    printf("%d %d\n", tmp->i, tmp->r);
    tmp = tmp->next;
}
```

**Soru (hocadan):** Bu döngü ne yazar? **Cevap:** `tmp` önce `c5->next`'i, yani `c6`'yı gösterir; önce `c6`'nın değerleri (`4 3`) yazılır. `tmp = tmp->next` ile `c7`'ye geçilir ve `6 5` yazılır. Sonra `tmp` `NULL` olur ve döngü biter.

**Soru (hocadan):** `c7->next` `NULL` yerine `c6`'yı gösterebilir mi? **Cevap:** Evet, gösterebilir; o zaman `c6` ile `c7` birbirini gösterip durur. `c7` `c5`'i gösterirse `c5 → c6 → c7 → c5` biçiminde dairesel bir yapı oluşur. Derste `c7->next = c5;` yapılınca döngü `NULL`'a hiç ulaşamadığı için sonsuz döngüye girdi ve değerler dönüp durdu. Son düğüm `NULL`'a bağlansaydı bu olmazdı.

> **Ek bilgi (derste anlatılmadı):** Kısa nottaki derlenmiş sürümde düğümler `malloc` sonucu `(COMPLEX *)` ile dönüştürüldü ve program sonunda üç düğüm `free` edildi. C'de `void *`'tan başka işaretçi tipine dönüşüm örtük yapılabildiği için cast zorunlu değildir; C++ derleyicilerinde ise zorunludur.

## 9. Bağlı liste terimleri ve temel işlemler

Hoca bağlı listeyi OneNote üzerinde çizerek anlattı (ekrandan, 02:05:00).

- **head:** Listenin ilk düğümünü gösteren işaretçidir. Dinamik dizilerde `array++` ile işaretçi kaydırılınca dizinin başı kaybedilebiliyordu; aynı şekilde listenin başını tutan işaretçi korunmalıdır.
- **next:** Her düğüm bir sonrakini gösterir; son düğüm genellikle `NULL` gösterir.
- **last:** Listenin sonuna hızlı gitmek için ayrıca tutulan işaretçidir. Ekleme, silme, güncelleme yapıldığında `head` gibi bunun da güncellenmesi gerekir.
- **Dairesel liste (circular linked list):** Son düğüm `NULL` yerine baştaki ya da aradaki bir düğümü gösterir. Bu farklı bir gerçekleştirimdir, derste üzerinde durulmadı.
- **Çift yönlü liste (doubly linked list):** Her düğüme bir önceki düğümü gösteren ikinci bir işaretçi (`prev`) eklenir. Karmaşık sayı düğümünde alanlar `r`, `i`, `next`, `prev` olur. İleri-geri gezinmek kolaylaşır, bedeli ek bellektir.

Temel işlemler dizilerdeki gibidir: ekleme, silme, güncelleme, arama. Bazıları dizide kolay, bazıları listede kolaydır. Diziye araya eleman eklerken ya da aradan eleman silerken sağdaki ya da soldaki elemanları birer birer kaydırmak (shift) gerekir. Bağlı listede buna gerek yoktur:

- Araya ekleme: `malloc` ile tek bir düğüm oluşturulur; önceki düğümün `next`'i yeni düğüme, yeni düğümün `next`'i de sonraki düğüme bağlanır.
- Aradan silme: önceki düğümün `next`'i silinecek düğümün sonrasına bağlanır, aradaki düğüm devreden çıkar.
- Baştaki düğümü silmek biraz farklıdır, çünkü `head` değişir; ayrıntısı sonraki derslere bırakıldı.

Hoca bağlı liste gerçekleştirimine (sürekli eleman ekleme, arama, araya ekleme, silme kodlarına) bu derste girmedi; sonraki derslerde devam edileceğini söyledi.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:06:16): İki boyutlu dinamik matris açarken `matris = (int **) malloc(M * sizeof(int *));` satırında neden `sizeof(int)` değil de `sizeof(int *)` yazılır?

> **Çözüm (derste verildi):** Dış dizinin her elemanı bir satırın başlangıç adresini, yani bir `int *`'ı tutar. Bu yüzden eleman boyutu `sizeof(int *)`'tır. `int` ile `int *` boyutu her sistemde aynı değildir (örneğin 64 bitlik sistemlerde genelde 4 ve 8 bayt).

**Soru 2** (ekrandan, 00:40:00): Slayttaki örnek: "Write a function that compresses a sparse matrix. The function should take a matrix as a parameter. The function should return a new matrix ..." <!-- BELİRSİZ: slayt küçük önizlemede göründü; sorunun son cümlesi (dönen matrisin boyutu) tam okunamadı. -->

> **Çözüm (derste verildi):** Bölüm 1 ve 2'deki `matris_compress` fonksiyonu: sıfırdan farklı eleman sayısı `counter` bulunur, `counter x 3` boyutunda yeni matris açılır, her sıfırdan farklı eleman için satır, sütun ve değer yazılır, yeni matris `int **` olarak döndürülür. Derlenmiş tam program kısa nottadır.

**Soru 3** (ekrandan, 00:40:00): Slayttaki örnek: "Write a function that takes two ordered array and returns the ordered union of them." (Slaytta evde kodlanmak üzere alıştırma olarak bırakıldığı yazıyor.)

> **Çözüm (derste verilmedi):** İki sıralı dizi birleştirme (merge) mantığıyla aynı anda gezilir; küçük olan eleman sonuca eklenir, eşitse bir kez eklenir. Sonuç dizisi en fazla `n + m` elemanlı olarak dinamik açılır. Aşağıdaki kod `gcc -Wall` ile uyarısız derlendi; `{1, 3, 5, 7}` ve `{2, 3, 6, 7, 9}` için çıktı `1 2 3 5 6 7 9`.
>
> ```c
> #include <stdio.h>
> #include <stdlib.h>
>
> int *ordered_union(int *a, int n, int *b, int m, int *k) {
>     int *u = (int *) malloc((n + m) * sizeof(int));
>     int i = 0, j = 0, x;
>     *k = 0;
>     if (u == NULL) return NULL;
>     while (i < n || j < m) {
>         if (j >= m || (i < n && a[i] < b[j])) x = a[i++];
>         else if (i >= n || b[j] < a[i]) x = b[j++];
>         else { x = a[i]; i++; j++; }
>         if (*k == 0 || u[*k - 1] != x) u[(*k)++] = x;
>     }
>     return u;
> }
>
> int main() {
>     int a[] = {1, 3, 5, 7}, b[] = {2, 3, 6, 7, 9};
>     int k, i, *u = ordered_union(a, 4, b, 5, &k);
>     for (i = 0; i < k; i++) printf("%d ", u[i]);
>     printf("\n");
>     free(u);
>     return 0;
> }
> ```

**Soru 4** (derste sözlü, 00:26:41): Program bastırma işleminden hemen sonra bittiğine göre ayrılan belleği `free` etmek gereksiz değil mi?

> **Çözüm (derste verildi):** Hayır; bellek serbest bırakılmazsa süreç hemen sonlanmadığında ya da uzun süre çalışan programlarda işgal edilmeye devam eder ve bellek sızıntısı oluşur. Ayrıntı ve ders sonrası not için Bölüm 2.3'e bakın.

**Soru 5** (derste sözlü, 01:58:16): `tmp = c5->next;` ile başlayıp `while (tmp != NULL) { printf("%d %d\n", tmp->i, tmp->r); tmp = tmp->next; }` döngüsü, `c5 (1, 2) → c6 (3, 4) → c7 (5, 6) → NULL` listesinde ne yazar? `c7->next = c5;` yapılırsa ne olur?

> **Çözüm (derste verildi):** Önce `c6`'nın değerleri `4 3`, sonra `c7`'nin değerleri `6 5` yazılır ve döngü biter (derlenerek doğrulandı). `c7->next = c5` yapılırsa liste dairesel olur, `tmp` hiçbir zaman `NULL` olmaz ve döngü sonsuza girer.

## Dersin Toparlaması

Ders, önceki derste gösterilen seyrek matris sıkıştırma örneğinin baştan yazılmasıyla dinamik bellek ve fonksiyon konularını birleştirdi: iki boyutlu matrisi `int **` ile açmak, `scanf`'te `&` kullanımı, işi küçük fonksiyonlara bölmek, tekrarlanan kodu `matrix_allocate`'e taşımak, prototip yazmak ve ayrılan alanın dışına çıkınca ortaya çıkan hatayı bulmak. Ardından `main(int argc, char *argv[])` ile programa komut satırından argüman verme, `argv[0]`'ın program adı olduğu ve string argümanların `atoi`/`atof` ile sayıya çevrilmesi işlendi.

Teori kısmında struct'lar tanıtıldı: neden gerektikleri (primitive obsession), `struct`, `typedef` ve `#define` ile tanım yolları, `.`, `->` ve `(*p).` ile erişim, işaretçinin önce bir yeri göstermesi gerektiği, iç içe struct'lar ve struct'ların değerle, adresle ya da dizi olarak fonksiyona aktarılması. Son olarak kendine işaret eden struct ile bağlı listeye giriş yapıldı; düğüm, `head`, `last`, `NULL` sonu, dairesel ve çift yönlü liste kavramları ile araya ekleme ve silmenin mantığı anlatıldı. Bağlı liste işlemlerinin kodlanması sonraki derslere bırakıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
