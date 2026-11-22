# Ders 13 Çalışma Özeti

## Genel Konular

- Seyrek (sparse) matris sıkıştırma örneğinin baştan yazılması (ekrandan, 00:05:00 - 00:35:00)
  - Çoğu elemanı sıfır olan bir matriste yalnız sıfırdan farklı elemanlar saklanır. Sıkıştırılmış matrisin her satırında üç sütun vardır: satır indisi, sütun indisi, değer. Satır sayısı sıfırdan farklı eleman sayısı (`counter`) kadardır.
  - Program küçük fonksiyonlara bölündü: `enter_data`, `count_data`, `display_matris`, `matris_compress`, `matrix_allocate`, `free_matris`. Gerekçe "düşük bağlaşım, yüksek uyum" ilkesidir: ileride bir değişiklik yapılırsa en az yer etkilenir.
  - İki boyutlu dinamik matris: önce `int **` için `M * sizeof(int *)` kadar satır işaretçisi, sonra her satır için `N * sizeof(int)` kadar yer açılır (ekrandan, 00:10:00).
  - `scanf` ile `matris[i][j]` okunurken `&` gerekir: `matris[i][j]` bir değerdir, adres değildir. Alternatif yazım `*(matris+i)+j` adresidir, onda `&` gerekmez (ekrandan, 00:15:00).
  - `count_data`: iki döngüyle bütün hücreler gezilir, sıfırdan farklı her elemanda sayaç artırılır ve sayaç döndürülür.
  - `matris_compress`: `counter x 3` boyutlu yeni matris açılır; sıfırdan farklı her eleman için `m[k][0]=i`, `m[k][1]=j`, `m[k][2]=matris[i][j]`, `k++` yapılır; yeni matris `int **` olarak döndürülür (ekrandan, 00:20:00, 00:30:00).
  - `free_matris`: önce her satır `free(matris[i])`, en sonda `free(matris)` ile bırakılır (ekrandan, 00:25:00).
  - Tekrarlanan bellek ayırma kodu (duplicated code) `int **matrix_allocate(int M, int N)` fonksiyonuna taşındı; hem orijinal matris hem sıkıştırılmış matris bununla açılır.
- Derste karşılaşılan hatalar ve düzeltmeleri
  - Prototipler yazılmadığı için derleyici uyardı; prototipler `main`'den önce, parametre adları olmadan yazıldı (ekrandan, 00:45:00).
  - `m[k][1]` iki kez yazılmıştı; üçüncü satır `m[k][2]=matris[i][j]` olmalı (bir öğrenci fark etti).
  - `matrix_allocate` içinde döngü sınırı `counter` kalmıştı; `M` olmalı (ekrandan, 00:30:00).
  - Sıkıştırılmış matris `M x N` diye basılınca ayrılan alanın dışına çıkıldı ve program sıfırdan farklı bir değerle bitti. Doğrusu `display_matris(..., c_matrix, counter, 3)`.
- Komut satırı argümanları (`main(int argc, char *argv[])`) (ekrandan, 00:40:00 - 00:50:00)
  - `argc` argüman sayısını, `argv` argümanları string olarak tutan diziyi verir. `argv[0]` programın adıdır, sonra boşlukla ayrılmış argümanlar gelir.
  - Program komut penceresinden çalıştırıldı (`cd` ile klasöre gidip `dir`, `s1 4 5`). Dev-C++'ta "Execute > Parameters" ile de argüman verilebilir.
  - `argv` elemanları string olduğu için sayıya `atoi` (tamsayı) ve `atof` (ondalık) ile çevrilir. `s1 aaa 5` girilince `atoi("aaa")` 0 verdi.
  - `argc == 1` ise "Boyutlar girilmedi" yazdırılıp çıkılır. Böylece sparse matris programı boyutları kullanıcıdan `scanf` ile değil, komut satırından aldı.
  - Ctrl+C çalışan programa bir sonlandırma sinyali gönderir.
- Yapılar (struct) (ekrandan, 00:55:00 - 01:20:00)
  - Günlük hayattaki nesnelerin birden çok özelliği vardır (ad, yaş, maaş, kimlik no). Her özellik için ayrı dizi tutmak ve fonksiyona tek tek göndermek "temel veri tiplerine takıntı" (primitive obsession) kod kusurudur. `struct` bu alanları tek bir tipte toplar.
  - Struct, nesneye yönelik programlamadaki sınıfın (class) metotsuz hâli gibidir.
  - Tanım genelde global yapılır, değişkenler fonksiyon içinde üretilir.
  - Üç tanım yolu gösterildi: `struct Complex {int r; int i;};`, `typedef struct complex {...} COMPLEX;`, `typedef struct Complex CMP;`. Dördüncü olarak bir öğrencinin önerisiyle `#define CMP2 struct Complex` denendi ve çalıştı (ekrandan, 01:05:00, 01:10:00, 01:15:00).
  - Tavsiye edilen yol `typedef`'tir; `#define` önişlemci makrosudur.
  - Alan erişimi: değişkende `c1.r`, işaretçide `c2->r` ya da `(*c2).r`. `*c2.r` yazılamaz, çünkü `.` operatörünün önceliği `*`'dan yüksektir.
  - İşaretçi önce bir struct'ı göstermelidir (`c2 = &c3;`); göstermeden alanına yazmak hatadır.
  - İç içe struct: tarih (gün, ay, yıl) struct'ı başka bir struct'ın alanı olur; `kisi.enlisted.year = 2008` biçiminde erişilir.
- Struct'ların fonksiyona aktarılması (ekrandan, 01:20:00 - 01:45:00)
  - Struct değişkeni değerle (pass by value) gider; fonksiyondaki değişiklik çağırana yansımaz (`silvalue`).
  - Adresi gönderilirse (`silref(&c[2])`) değişiklik yansır; işaretçi bütün struct'ı gösterir, yalnız ilk alanı değil.
  - Struct dizisi gönderilirse (`sil(c, 3)`) dizi olduğu için referansla gider.
  - Dinamik struct dizisi: `c2 = (COMPLEX *) malloc(N * sizeof(COMPLEX));`; fonksiyona `COMPLEX *c` olarak gönderilir, `c[j].r` ya da `(c+j)->r` ile erişilir.
- Bağlı listeye (linked list) giriş (ekrandan, 01:55:00 - 02:05:00)
  - Dizi elemanları bellekte bitişiktir; yeterli bitişik yer olmayabilir. Bağlı listede düğümler (node) dağınık durur, her düğüm bir sonraki düğümün adresini tutar.
  - Struct kendi tipinde bir alan içeremez (sonsuz özyineleme), ama kendi tipinde bir işaretçi içerebilir: `struct complex *next;`.
  - `c5`, `c6`, `c7` düğümleri `malloc` ile açılıp `next` alanlarıyla bağlandı; son düğümün `next`'i `NULL` yapıldı; `tmp` işaretçisiyle `while (tmp != NULL)` döngüsünde gezildi.
  - Son düğüm başa bağlanırsa dairesel (circular) liste olur; `NULL`'a ulaşılmadığı için gezinme döngüsü sonsuza girer.
  - Terimler: ilk düğümü gösteren `head`, sona hızlı gitmek için `last`, bir önceki düğümü de tutan çift yönlü (doubly) liste.
  - Araya ekleme ve silmede dizideki gibi kaydırma (shift) gerekmez; yalnız bağlantılar değiştirilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- `sizeof` içinde `int *` yazmak
  - Satır işaretçilerinin dizisi açılırken `sizeof(int *)` yazılmalıdır; `int` ile `int *` boyutu aynı olmayabilir.
- `scanf` ve `&`
  - "Çok yapılan bir hata": `matris` işaretçi diye `&` unutulur. `matris[i][j]` değerdir, `&` gerekir.
- Bellek mutlaka `free` edilmeli
  - Bir öğrenci program bitiyorsa `free`'nin gereksiz olup olmadığını sordu. Hoca, belleğin serbest bırakılmazsa işgal edilmeye devam edebileceğini, uzun süre çalışan programlarda bellek sızıntısının (memory leak) belleği doldurduğunu söyledi.
- İşaretçi önce bir yeri göstermeli
  - "Çok çok yapılan hata": işaretçi bir yeri göstermeden `*pa = 9` ya da `c2->r = ...` yazılır. Önce `pa = &a;`, `c2 = &c3;`.
- Konuları birlikte düşünün
  - İşaretçi, dinamik bellek, fonksiyon ve struct'ın farklı birleşimleri: struct'ı fonksiyona göndermek, struct'ı dinamik oluşturmak, struct'a işaretçiyle erişmek, dinamik struct'ı fonksiyona göndermek.
- Bu dersin önemi
  - Bu konular veri yapıları, algoritma analizi, işletim sistemleri ve nesneye yönelik programlama derslerinin altyapısıdır.

## Kısa Tekrar Notları

- Sparse matris: yalnız sıfır olmayanlar `(satır, sütun, değer)` üçlüsü olarak `counter x 3` matriste saklanır.
- 2B dinamik matris: `m = malloc(M * sizeof(int *))`, her satıra `malloc(N * sizeof(int))`; bırakırken önce satırlar, sonra `m`.
- Tekrarlanan kodu fonksiyona taşı (`matrix_allocate`).
- Fonksiyon `main`'den sonra yazılıyorsa prototipi `main`'den önce yazılır.
- `main(int argc, char *argv[])`: `argv[0]` program adı; argümanlar string; sayıya `atoi`/`atof` ile çevrilir.
- `typedef struct {...} AD;` ile her seferinde `struct` yazmaktan kurtulunur.
- Değişkende `.`, işaretçide `->` ya da `(*p).alan`.
- Struct değerle gider; değişiklik için adresini gönder. Struct dizisi referansla gider.
- Bağlı liste düğümü: veri alanları + `struct tip *next`. Son düğüm `NULL` gösterir.
- Dairesel listede `NULL` kontrolüyle gezinme sonsuz döngüye girer.

## Detaylı Açıklamalar

- Sparse matris programının son hâli (ekrandan, 00:25:00, 00:30:00, 00:35:00; boyutların komut satırından alındığı sürüm, 00:50:00). `display_matris` gövdesi karelerde görünmedi; aşağıda anlatıma göre yazıldı. Kod `gcc -Wall` ile uyarısız derlendi, `3 3` argümanı ve `0 2 0 / 0 0 3 / 0 5 0` girdisiyle denendi: sıkıştırılmış matris `0 1 2 / 1 2 3 / 2 1 5` çıktı. Derste de aynı girdiyle "0'a 1'de 2, 1'e 2'de 3, 2'ye 1'de 5" sonucu görüldü (00:26:08).

```c
#include <stdio.h>
#include <stdlib.h>

void free_matris(int **, int);
int **matris_compress(int **, int, int, int);
void enter_data(int **, int, int);
int count_data(int **, int, int);
void display_matris(char *, int **, int, int);
int **matrix_allocate(int, int);

int main(int argc, char *argv[]) {
    int M, N;
    int **matris, **c_matrix;
    int counter = 0;

    if (argc == 1) {
        printf("%d sayida arguman: Boyutlar girilmedi\n", argc);
        return 1;
    }
    M = atoi(argv[1]);
    N = atoi(argv[2]);

    matris = matrix_allocate(M, N);
    enter_data(matris, M, N);
    counter = count_data(matris, M, N);
    display_matris("Original matrix\n", matris, M, N);
    c_matrix = matris_compress(matris, M, N, counter);
    display_matris("Compressed matrix\n", c_matrix, counter, 3);

    free_matris(matris, M);
    free_matris(c_matrix, counter);
    return 0;
}

int **matrix_allocate(int M, int N) {
    int **m;
    int i;
    m = (int **) malloc(M * sizeof(int *));
    for (i = 0; i < M; i++) {
        m[i] = (int *) malloc(N * sizeof(int));
    }
    return m;
}

void enter_data(int **matris, int M, int N) {
    int i, j;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            printf("Matris[%d][%d]", i, j);
            scanf("%d", &matris[i][j]);   /* ya da *(matris+i)+j */
        }
    }
}

int count_data(int **matris, int M, int N) {
    int i, j, c = 0;
    for (i = 0; i < M; i++)
        for (j = 0; j < N; j++)
            if (matris[i][j] != 0)
                c++;
    return c;
}

void display_matris(char *str, int **matris, int M, int N) {
    int i, j;
    printf("%s", str);
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++)
            printf("%3d ", matris[i][j]);
        printf("\n");
    }
}

int **matris_compress(int **matris, int M, int N, int counter) {
    int **m;
    int i, j, k = 0;
    m = matrix_allocate(counter, 3);
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            if (matris[i][j] != 0) {
                m[k][0] = i;
                m[k][1] = j;
                m[k][2] = matris[i][j];
                k++;
            }
        }
    }
    return m;
}

void free_matris(int **matris, int M) {
    int i;
    for (i = 0; i < M; i++) {
        free(matris[i]);
    }
    free(matris);
}
```

- Ayrılan alanın dışına çıkma: Sıkıştırılmış matris yanlışlıkla `M x N` boyutunda basılınca, sıfırdan farklı eleman sayısı az olduğunda (örneğin 3x3 matriste tek eleman) `counter x 3` alanın dışındaki satırlara erişildi ve program hata koduyla bitti. Girilen sıfırdan farklı eleman sayısı tesadüfen `M` kadar olduğunda hata görünmedi. Bu tür hata dinamik bellekte (heap) izinsiz bir yere erişmekten kaynaklanır.
- Komut satırı argümanları: Slayttaki örnek bütün argümanları basar (ekrandan, 00:40:00): `while (--argc > 0) printf("%s\n", *++argv);`. Derste yazılan sürümde `argc == 1` ise "Boyutlar girilmedi" yazılır; değilse `M = atoi(argv[1]); N = atoi(argv[2]);` yapılır. Komut penceresindeki denemeler (ekrandan, 00:50:00): `s1` → "1 sayıda argüman: Boyutlar girilmedi"; `s1 4 5` → "3 sayıda argüman: 4 5"; `atoi` öncesi `s1 aaa 5` → "aaa 5", `atoi` sonrası → "0 5". Bir öğrenci `argv` string olduğu için `=` yerine `strcpy` gerekip gerekmediğini sordu; hoca string işlemlerinin ileride ayrıntılı işleneceğini söyledi ve sayıya çevirme için `atoi` kullandı.
- Struct tanımları ve erişim (ekrandan, 01:10:00, 01:15:00). Aşağıdaki sürüm derlenip denendi; derste dizi indisi `c4[3]` yazılmıştı, burada `c4[2]` kullanıldı (aşağıdaki ders sonrası nota bakın). Çıktı: `4 - 6i`, `0 - 8i`, `44 - 6i`, `999 - 880i`.

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
#define CMP2 struct Complex

int main() {
    struct Complex c1;
    COMPLEX c3, *c2;
    CMP c4[3];
    CMP2 c5;

    c1.r = 4;
    c1.i = 6;
    c4[2].r = 0;
    c4[2].i = 8;
    c5.r = 44;
    c5.i = 6;
    printf("%d - %di\n", c1.r, c1.i);
    printf("%d - %di\n", c4[2].r, c4[2].i);
    printf("%d - %di\n", c5.r, c5.i);

    c2 = &c3;
    c2->r = 999;
    (*c2).i = 880;
    printf("%d - %di\n", c2->r, (*c2).i);
    return 0;
}
```

- `struct Complex` ile `struct complex` farklı tiplerdir (C büyük-küçük harf duyarlıdır); içerikleri aynı olsa da birbirlerinin yerine kullanılamaz.
- Struct'ları fonksiyona gönderme (ekrandan, 01:30:00 - 01:50:00): `ekrana_yaz(COMPLEX c[], int N)` diziyi `"%d %dj\n"` biçiminde basar (mühendislikte sanal birim için `j` kullanılır). `sil(COMPLEX c[], int N)` bütün elemanları sıfırlar ve değişiklik `main`'e yansır. `silvalue(COMPLEX c)` içinde `c.r = c.i = 0;` yazılsa da `main`'deki `c[2]` değişmez. `silref(COMPLEX *c)` içinde `c->r = c->i = 0;` ile `c[2]` gerçekten sıfırlanır. Dinamik dizi için `ekrana_yazv2(COMPLEX *c, int N)` ve `sil_v2(COMPLEX *c, int N)` yazıldı. Prototipler `typedef`'ten sonra yazılmadığında derleyici "implicit declaration" ve "conflicting types" uyarıları verdi (ekrandan, 01:35:00, 01:40:00).
- Bağlı liste örneği (ekrandan, 01:55:00). Derste `c5 (1, 2)` ve `c6 (3, 4)` önce bağlandı, sonra `c7` eklendi. Aşağıdaki sürüm derlenip denendi, çıktı `2 1 --- 4 3`, `4 3`, `6 5`:

```c
#include <stdio.h>
#include <stdlib.h>
typedef struct complex {
    int r;
    int i;
    struct complex *next;
} COMPLEX;

int main() {
    COMPLEX *c5, *c6, *c7, *tmp;
    c5 = (COMPLEX *) malloc(1 * sizeof(COMPLEX)); c5->r = 1; c5->i = 2;
    c6 = (COMPLEX *) malloc(1 * sizeof(COMPLEX)); c6->r = 3; c6->i = 4;
    c7 = (COMPLEX *) malloc(1 * sizeof(COMPLEX)); c7->r = 5; c7->i = 6;
    c5->next = c6;
    c6->next = c7;
    c7->next = NULL;
    printf("%d %d --- %d %d\n", c5->i, c5->r, c5->next->i, c5->next->r);

    tmp = c5->next;
    while (tmp != NULL) {
        printf("%d %d\n", tmp->i, tmp->r);
        tmp = tmp->next;
    }
    free(c5); free(c6); free(c7);
    return 0;
}
```

- Büyük sayı örneği: `long` tipine sığmayan 40 basamaklı iki sayıyı toplamak için her basamak bir liste düğümünde (ya da bir dizi elemanında) tutulabilir; toplama, çıkarma, çarpma bu yapı üzerinde yapılır.
- Ders sonrası not: Derste `CMP c4[3];` tanımlanıp `c4[3].r = 0;` yazıldı. Üç elemanlı dizinin geçerli indisleri 0, 1, 2'dir; `c4[3]` dizi sınırının dışındadır. Program çalışmış görünse de bu tanımsız davranıştır.
- Ders sonrası not: Hoca, struct tanımlanınca alanların varsayılan olarak sıfırlandığını sandığını, ama emin olmadığını söyledi. Doğrusu: yerel (otomatik) struct değişkenlerinin alanları sıfırlanmaz, çöp değer içerir; yalnız global ve `static` değişkenler sıfırla başlar. Derste görülen `0 0` değerleri tesadüftür.
- Ders sonrası not: Hoca `atoi`'yi "argument to integer" diye açıkladı. Adın açılımı "ASCII to integer"dır (`atof`: "ASCII to float"). İşlev aynıdır: string'i sayıya çevirir.
- Ders sonrası not: Hoca C'de değişkenlerin her zaman en yukarıda tanımlanması gerektiğini söyledi. Bu kural C89/C90 standardı içindir; C99 ve sonrasında değişken blok içinde herhangi bir yerde tanımlanabilir. Yine de eski derleyici ayarlarıyla uyum için en başta tanımlamak güvenlidir.
- Ders sonrası not: Hoca, `free` edilmeyen belleğin program kapandıktan sonra da işgal edilebileceğini söyledi. Günümüz işletim sistemleri süreç sonlandığında o sürecin belleğini büyük olasılıkla geri alır; asıl sorun uzun süre çalışan programlarda (tarayıcı, sunucu) ve döngü içinde sürekli bellek ayıran kodda biriken sızıntıdır. `free` alışkanlığı yine de doğru uygulamadır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
