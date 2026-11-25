# Ders 6 Çalışma Özeti

## Genel Konular

- Karakter (char) ile string arasındaki atama farkları
  - Tek karakter her zaman tek tırnakla (`'a'`) yazılır ve bellekte 1 bayt tutar. Çift tırnaklı `"a"` ise bir stringdir; sonundaki null karakter (`'\0'`) yüzünden 2 bayt tutar (ekrandan, 00:20:00).
  - `char *p` için `*p` pointer'ın gösterdiği yerdeki değer, `p` ise bellek adresidir. Bellek adresine karakter atanamaz: `p = 'a';` geçersizdir.
  - String tarafında `p = "a";` geçerlidir, çünkü bir bellek alanının başlangıç adresi pointer'a atanır. `*p = "a";` ise yanlıştır, çünkü tek karakterlik yere adres yazılmaya çalışılır.
  - String sabitini gösteren pointer'ın içeriği değiştirilemez (immutable). Değiştirmek için `malloc` ile yer ayrılır ve `strcpy` ile içerik kopyalanır.
- `malloc` ve `void *` dönüşü
  - `malloc` istenen sayıda baytlık alanın başlangıcını `void *` olarak döndürür. Derleyici bu alanın hangi türde kullanılacağını bilemez. Bu yüzden `(char *)` ile cast edilir.
  - Ayrılan alanın `NULL` dönüp dönmediği kontrol edilmeli, iş bitince alan `free` ile bırakılmalıdır.
- String okuma ve yazma
  - `scanf("%s", str)` ile string okunur. Dizinin adı zaten adres olduğu için `&` gerekmez. `scanf` okuduğu karakterlerin sonuna kendisi null karakter ekler. Dizi girilen metni tutacak kadar uzun olmalıdır (ekrandan, 00:35:00).
  - `scanf` ilk boşlukta okumayı keser. Bu yüzden `%s` ile boşluklu metin okunamaz.
  - `printf("%s", ...)` null ile biten bir karakter dizisinin adresini bekler.
- String uzunluğu: kendi `strLen` fonksiyonu
  - Null karakter görülene kadar karakterler sayılır (ekrandan, 00:45:00). Parametre dizi yerine `char *` alınır, böylece her uzunluktaki string için aynı fonksiyon kullanılır.
  - Main'deki dizi fonksiyona verilince fonksiyondaki pointer dizinin ilk elemanını gösterir. Fonksiyon içindeki değişiklik main'deki diziyi de etkiler.
- `string.h` fonksiyonları (ekrandan, 01:15:00)
  - `strcpy(hedef, kaynak)`: kaynağı hedefin üzerine yazar. `strncpy`: yalnız ilk n karakteri kopyalar.
  - `strcat(hedef, eklenecek)`: ikinci stringi birincinin sonuna ekler (concatenate). Hedefte yeterli yer olmalıdır. `strncat`: yalnız n karakter ekler.
  - `strcmp(s1, s2)`: sözlük sırasına göre ve büyük-küçük harf ayrımıyla karşılaştırır. s1 önce geliyorsa negatif, sonra geliyorsa pozitif, eşitse 0 döner. `strncmp`: ilk n karakteri karşılaştırır.
  - Bilgisayarın "sözlüğünde" büyük harfler küçük harflerden önce gelir. Türkçe ve aksanlı harfler İngiliz alfabesinin sonuna eklenmiştir.
- Alt metin arama örneği (Pattern Matching)
  - İstenen: ikinci string birincinin içinde geçiyorsa başladığı konumu, geçmiyorsa -1 döndüren, pointer işlemleriyle yazılmış `indexOfV1`.
  - Çözüm iki pointer'ı birlikte ilerletir, eşleşme sayısını (`matchCount`) ve aramanın başladığı konumu (`from`) tutar. Eşleşme bozulursa ana stringte başlangıcın bir ilerisine, aranan stringte en başa dönülür.
  - `indexOfV2`: aynı iş hazır `strstr` fonksiyonuyla yapılır (ekrandan, 01:55:00).
- Çok boyutlu diziler
  - `int ar[5][3]` 5 satır ve 3 sütunluk bir dizidir. 3 elemanlık 5 tane dizi gibi de düşünülebilir.
  - Köşeli parantez pointer gösterimine en sağdan başlanarak çevrilir: `ar[1][2]` = `*(ar[1]+2)` = `*(*(ar+1)+2)` (ekrandan, 02:25:00).
  - İlklendirmede her iç süslü parantez bir satırdır. Yazılmayan elemanlar 0 olur.
- Pointer dizileri ve karakter matrisi örneği
  - `char *ar_of_p[5];` 5 elemanlı bir karakter pointer dizisidir. Atanmayan elemanların değeri tanımsızdır (ekrandan, 02:35:00).
  - Karakter matrisi bellekte satır satır, birbirini izleyen gözlere yazılır. Bu yüzden tek bir pointer matrisin bütün elemanlarını sırayla dolaşabilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Hangi atama geçerli, hangisi geçersiz
  - Sınavda "bu satır çalışır mı?" tipi sorular sorulabileceği için `*p = 'a'`, `p = 'a'`, `p = "a"`, `*p = "a"` arasındaki farklar bilinmelidir.
  - Derleme hatası ile bağlayıcı (linker) hatası arasındaki ayrım bu bağlamda önemli değildir.
- Kod kopyalarken tırnaklara dikkat
  - PowerPoint ya da Word'den kopyalanan biçimli (kıvrık) tırnaklar derleyicide garip hatalara yol açar. Kodda düz tek tırnak kullanılmalıdır.
- "İpin ucunu kaçırmayın"
  - String üzerinde dolaşırken pointer'ın başlangıcı kaybedilmemelidir. Ya ayrı yardımcı pointer'lar kullanılır ya da ne kadar ilerlendiği sayılarak geri dönülür.
- Off-by-one hatası
  - Alt metin aramada ana string pointer'ı `matchCount` kadar değil, `matchCount - 1` kadar geri çekilmelidir: `ptr1 = ptr1 - matchCount + 1;`. `ptr1 -= matchCount + 1;` yazılırsa önce toplama yapılır ve pointer fazla geri gider.
  - Her yeni denemede `matchCount` sıfırlanmalıdır.
- Dinamik bellekte iyi alışkanlıklar
  - `malloc` sonucu `NULL` mı diye bakılmalı, program bitmeden `free` yapılmalıdır.
- Çok boyutlu dizide yıldız ve parantez yerleri
  - Pointer gösteriminde parantez ve yıldızın yeri çok kritiktir. Bir tanesi karışırsa ifade yanlış yeri gösterir.

## Kısa Tekrar Notları

- `'a'` karakterdir (1 bayt), `"a"` stringdir (2 bayt: `'a'` ve `'\0'`).
- `*p` değer, `p` adres. Adrese karakter, karakter gözüne adres atanmaz.
- String sabitinin içeriği değiştirilemez. `malloc` + `strcpy` ile kopya üzerinde çalışılır.
- `malloc` `void *` döndürür; `(char *)` cast edilir, `NULL` kontrolü ve `free` unutulmaz.
- `scanf("%s", dizi)` boşlukta durur, sona null ekler, `&` gerekmez.
- String sonu boşluk değil null karakterdir.
- `strcpy`/`strncpy` kopyalar, `strcat`/`strncat` sona ekler, `strcmp`/`strncmp` karşılaştırır.
- `strcmp(s1, s2)`: s1 < s2 ise negatif, eşitse 0, s1 > s2 ise pozitif.
- `strstr(aranan_yer, aranan)` bulunan yerin adresini ya da `NULL` döndürür. Konum için `ptr - ptr1` farkı alınır.
- `ar[i][j]` = `*(*(ar+i)+j)`; `x[i][j][k]` = `*(*(*(x+i)+j)+k)`.
- Matris bellekte satır satır, art arda saklanır.
- Büyük harf (65-90) ile küçük harf (97-122) arasındaki ASCII farkı 32'dir. Bu kural Türkçe karakterlerde çalışmaz.

## Detaylı Açıklamalar

### Karakterler ve stringler

Slayttaki örnek iki bölümdür (ekrandan, 00:20:00):

```c
/* Chars */
char ch = 'a', *p;     // one byte is allocated for 'a'
*p = 'a';              // OK
p = 'a';               // Illegal
printf("%s\n",*p);

/* Strings */
char *p = "a";         // two bytes allocated for "a"
*p = "a";              // INCORRECT
p = "a";               // OK
printf("%s\n",p);
```

Karakter bölümünde `*p = 'a'` söz dizimi olarak doğrudur: pointer'ın gösterdiği yere bir karakter yazılır. `p = 'a'` ise adres yerine karakter atar ve derleyici "makes pointer from integer without a cast" uyarısı/hatası verir. String bölümünde `p = "a"` bir string sabitinin başlangıç adresini pointer'a atar, `*p = "a"` ise tek karakterlik göze bir adres yazmaya çalışır.

Hoca kodu Dev-C++'ta denediğinde program takıldı, sonra `printf` biçimini `%c` yaptı (ekrandan, 00:30:00).

> **Ders sonrası not:** Slayttaki karakter örneğinde `p` hiçbir yere bağlanmadan `*p = 'a'` yapılıyor. İlklendirilmemiş pointer'ın gösterdiği yere yazmak tanımsız davranıştır; derste görülen takılmanın nedeni büyük olasılıkla budur. Önce `p = &ch;` yazılmalıdır. Ayrıca `printf("%s\n", *p)` yanlıştır: `*p` bir `char` olduğu için `%c` kullanılmalıdır (gcc `-Wall` bu satırda biçim uyarısı veriyor). "OK" etiketi yalnız söz dizimi içindir.

### malloc ile değiştirilebilir string

Önceki dersten hatırlatma olarak: `p = (char *) malloc(MAX_CHAR);` ile alan ayrılır, `strcpy(p, str);` ile içerik kopyalanır. Artık `p[8] = 'r'` gibi değişiklikler yapılabilir. `strcpy` ilk parametre olarak hedefi, ikinci olarak kaynağı alır (ekrandan, 00:50:00).

### strLen

```c
int strLen( char *str ) {
    int i=0;
    while( str[i] != '\0' ) {
        i++;
    }
    return i;
}
```

(ekrandan, 00:45:00) Fonksiyon adında `L` büyük yazılmıştır, çünkü `string.h` içinde hazır `strlen` vardır. Parametre `char *` olduğu için hem dizi hem `malloc` ile ayrılmış alan verilebilir. Hoca "dizilere pointer üzerinden erişebiliriz, ama pointer'a dizi üzerinden erişemeyiz; en esnek yol pointer'dır" diyerek pointer parametresini tercih etti.

### strcmp ve strcat denemesi

`p` ve `str` ikisi de `"bol"` iken `strcmp` 0 döndü. `str[0] = 'z'` yapılınca (`"bol"` ile `"zol"`) birinci string küçük olduğu için negatif, `str[0] = 'a'` yapılınca (`"bol"` ile `"aol"`) pozitif sonuç alındı. `strcat(p, str)` sonucu `bolbol` oldu (ekrandan, 00:55:00). Hoca, en güvenli olması için hedef pointer'a `MAX_CHAR * 2` kadar yer ayrılabileceğini söyledi.

> **Ders sonrası not:** Hoca `strcmp`'in yalnız -1, 0 ya da +1 döndürdüğünü söyledi. Derste kullanılan kütüphanede böyle çıktı, ama C standardı yalnız işareti (negatif, sıfır, pozitif) garanti eder. Örneğin glibc ile `strcmp("bol", "zol")` -24 döndürür (ajan tarafından denendi). Sonuç `== -1` diye değil `< 0` diye kontrol edilmelidir.

### Alt metin arama

Ana string `babamin`, aranan `bam` örneğiyle anlatıldı (ekrandan, 01:20:00). İlk iki harf (`b`, `a`) eşleşir, üçüncüde `b` ile `m` uymaz. Bu durumda ana stringte ikinci harften, aranan stringte yine ilk harften başlanmalıdır. İki pointer'ı kaldığı yerden ilerletmeye devam etmek yanlış sonuç verir.

Derste yazılan çözümün son hali karelerde tam görünmüyor. Aşağıdaki kod, ekrandaki ara sürüm (ekrandan, 01:35:00) ve hocanın anlattığı düzeltmelerle (geri çekme ve `matchCount` sıfırlama) kurulmuştur. Ajan tarafından `gcc -Wall` ile derlenip denendi: `babamin`/`bam` için 2, `abcdefg`/`g` için 6, `abc`/`xyz` için -1 döndü.

```c
int indexOfV1( char *ptr1, char *ptr2 ) {
    int matchCount, len2, from;
    len2 = strlen(ptr2); from = 0; matchCount = 0;
    while( *ptr1 != '\0' ) {
        while( *ptr1 == *ptr2 && *ptr1 != '\0' ) {
            ptr1++; ptr2++; matchCount++;
        }
        if( matchCount == len2 ) return from;
        from++;
        ptr1 = ptr1 - matchCount + 1;
        ptr2 = ptr2 - matchCount;
        matchCount = 0;
    }
    return -1;
}
```

Hazır fonksiyonla çözüm (ekrandan, 01:55:00):

```c
int indexOfV2( char *ptr1, char *ptr2 ) {
    char *ptr;
    ptr = (char*) strstr(ptr1, ptr2);
    if( ptr != NULL )   return ptr-ptr1;
    else                return -1;
}
```

`strstr` bulunan yerin adresini döndürür. Ana stringin başlangıç adresi bu adresten çıkarılınca konum elde edilir. Slayttaki for döngülü çözüm, ana stringte en fazla `len1 - len2` konuma kadar baktığı için birkaç karşılaştırma daha az yapar.

> **Ders sonrası not:** Derste `str2 = strstr(str1, str2);` satırı "assignment makes pointer from integer without a cast" uyarısı verdi ve deneme bırakıldı (ekrandan, 02:05:00). Uyarının nedeni büyük olasılıkla `string.h` dosyasının eklenmemiş olmasıdır: bildirimi görülmeyen fonksiyonun `int` döndürdüğü varsayılır ve 64 bit sistemde adres bozulabilir. Ayrıca `str2` bu atamayla `malloc` adresini kaybeder; sonra `free(str2)` yapmak tanımsız davranıştır. Sonuç ayrı bir pointer'a atanmalıdır.

### Çok boyutlu diziler

`int ar[5][3];` için `ar[1][2]` önce `*(ar[1]+2)`, sonra `*(*(ar+1)+2)` olarak yazılır. Üç boyutlu `char x[3][4][5];` için (ekrandan, 02:30:00):

```text
x[1][2][3]
*(x[1][2]+3)
*(*(x[1]+2)+3)
*(*(*(x+1)+2)+3)
```

İlklendirmede iç süslü parantezlerin her biri bir satırı doldurur. Bir satırda eksik yazılan elemanlar ve hiç yazılmayan satırlar 0 olur. İç süslü parantez yazılmazsa değerler soldan sağa, satır satır yerleştirilir ve kalan gözler 0 olur.
<!-- BELİRSİZ: İlklendirme slaytı karelerde yok; altyazıdan 1,2,3 / tek elemanlı ikinci satır / 5,6,7 biçiminde bir örnek olduğu anlaşılıyor, ikinci satırdaki değer okunamadı. -->

### Pointer dizisi

```c
char *ar_of_p[5];
char c0 = 'a';
char c1 = 'b';
ar_of_p[0] = &c0;
ar_of_p[1] = &c1;
```

(ekrandan, 02:35:00) Slayttaki bellek resminde dizi 0x1000'den başlar ve her eleman 4 bayt yer tutar. `c0` 0x2000'de, `c1` 0x2001'dedir. `ar_of_p[0]` 2000, `ar_of_p[1]` 2001 değerini tutar, kalan üç eleman tanımsızdır.

> **Ders sonrası not:** Pointer'ın 4 bayt olması 32 bitlik sistemler içindir. 64 bitlik sistemlerde pointer genellikle 8 bayttır.

### Karakter matrisi örneği

`#define SIZE 5` ve `char metinler[SIZE][SIZE];` ile beş satırlık metin okunur. Bütün matrisi tek pointer'la dolaşan fonksiyon (ekrandan, 02:45:00):

```c
void listAllLines( char *p ) {
    int j;
    for( j=0; j<SIZE*SIZE; j++ ) {
        if( j % SIZE == 0 )
            printf("\n");
        if( ( *p >= 97 && *p <= 123 ) || ( *p >= 65 && *p <= 91 ) ) {
            printf("%c",*p);
        }
        p++;
    }
}
```

Fonksiyon `listAllLines(metinler[0])` ile çağrılır. Satır sonuna gelince pointer kendiliğinden bir sonraki satırın başına geçer, çünkü matris bellekte art arda saklanır. Harf olmayan karakterler atlanır. Derste `toLowerCase(metinler[0])` ve `toUpperCase(metinler[1])` ile tek bir satırın harfleri 32 eklenip çıkarılarak dönüştürüldü. `listOneLineOfText(&metinler[0][1])` çağrısı `qwert` ve `asdfg` girişinde `werta` yazdı (ekrandan, 03:00:00); yani bir satırın sonundan sonraki göz bir sonraki satırın başıdır.

> **Ders sonrası not:** Koşuldaki 123 ve 91 sınırları bir fazladır: `'z'` 122, `'Z'` 90'dır. 91 (`[`) ve 123 (`{`) karakterleri de harf gibi yazdırılır; doğru sınırlar `<= 122` ve `<= 90` olmalıdır. Ayrıca 5 harflik metin `char metinler[5][5]` satırına `scanf` ile okunduğunda sondaki null karakter bir sonraki satıra taşar; son satırda dizinin dışına yazılır ve bu tanımsız davranıştır. Satır uzunluğu `SIZE + 1` olmalıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
