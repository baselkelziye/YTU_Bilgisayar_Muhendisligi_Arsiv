# Ders 7 Çalışma Özeti

## Genel Konular

- Dizi üzerinde sıralama örneği (fonksiyon kullanmadan)
  - Sıralama gibi işler normalde ayrı bir fonksiyon olarak yazılır; kod modüler olur, kitaplığa konup başka yerlerden kullanılabilir. Fonksiyonlar henüz işlenmediği için örnek tek bir `main` içinde yazıldı. Selection sort, en küçüğü bulma işi ayrı bir sorumluluk olduğu ve fonksiyonla yazılması daha doğru olduğu için yapılmadı.
  - Selection sort hatırlatması: dizideki en küçük elemanı bul, ilk elemanla yer değiştir; sonra ikinci en küçüğü bul, ikinci elemanla değiştir; böyle $n-1$. elemana kadar devam et.
  - Bubble sort fikri: küçük elemanlar kabarcık gibi suyun yüzüne (dizinin başına), ağır elemanlar dibe (dizinin sonuna) doğru gider.
  - Eleman sayısı `#define ELEMAN_SAYISI 10` ile sabit olarak tanımlandı. Ön işlemci sabiti kullanıldığı her yere gömülür, global değişken gibi bellekte yer tutmaz.
  - Elemanlar kullanıcıdan `scanf("%d", &ar[i])` ile alınır; kullanıcıya sıra numarası `i+1` olarak gösterilir, çünkü kullanıcılar 1'den sayar (ekrandan, 00:15:00).
  - Derste yazılan döngüde her `ar[i]`, kendisinden sonraki `ar[j]` elemanlarıyla (`j = i+1`'den başlayarak) karşılaştırılır; `ar[i] > ar[j]` ise iki eleman yer değiştirir (artan sıralama).
  - İki elemanı yer değiştirmek için geçici değişken (`tmp`) gerekir: `tmp = ar[i]; ar[i] = ar[j]; ar[j] = tmp;`.
  - Dış döngü `ELEMAN_SAYISI - 1`'e kadar gider; son elemanın karşılaştırılacağı başka eleman kalmaz (off-by-one hatasına dikkat).
- Karakter katarları (string)
  - C'de hazır bir string tipi yoktur; string, karakter dizisi olarak işlenir ve en fazla kaç karakter olacağı baştan belirlenir.
  - Stringin bittiği yer null karakteriyle (`'\0'`) belirtilir. Null konmazsa dizide önceden kalan karakterler de stringin parçası gibi görünür.
  - String atama slaytı (ekrandan, 00:35:00 ve 00:40:00): `array = "not OK";` derlenmez, çünkü dizinin adı bir adrestir ve adrese değer atanamaz. `array[5] = 'A';` derlenir ama dizi doldurulmadığı için anlamsız sonuç verir. Doğru yol 0. indisten başlayıp sonuna `'\0'` koymaktır. `*ptr2 = "not OK";` tip uyuşmazlığıdır. `ptr2 = "OK";` geçerlidir.
  - Karakter ve string farkı (ekrandan, 01:00:00): `char ch = 'a';` 1 bayt; `*p = 'a';` doğru; `p = 'a';` geçersiz. `char *p = "a";` 2 bayt ayırır (`'a'` ve `'\0'`); `*p = "a";` yanlış; `p = "a";` doğru.
- `scanf` ile string okuma
  - `%s` biçimi ve önceden tanımlanmış bir karakter dizisi gerekir (`char str[MAX_CHAR]`). Dizinin adı zaten adres olduğu için `&` konmaz.
  - `scanf` sonuna `'\0'` karakterini kendisi ekler.
  - `scanf("%s")` boşlukta durur: "Yapısal Programlama" girilince yalnız ilk kelime okunur.
  - Ayrılan alandan uzun giriş tampon taşmasına (buffer overflow) yol açar. Derste 5 karakterlik diziye uzun girişler yapıldı; program bazen çalışmaya devam etti, bazen tepkisi gecikti ya da takıldı. Bir öğrencinin denemesinde core dump oluştu. Taşmanın sonucu derleyiciye ve işletim sistemine göre değişir.
- Kendi `strLen` fonksiyonumuz (ekrandan, 01:15:00)
  - Dizinin her elemanına `'\0'` görene kadar bakılır, sayaç döndürülür. `string.h`'deki `strlen` ile çakışmasın diye adı `strLen` konmuştur (camel casing).
  - Derste "BirDenemeDaha" için 13 sonucu alındı (ekrandan, 01:20:00).
- `string.h` fonksiyonları (ekrandan, 01:25:00)
  - `strcpy(hedef, kaynak)`: kaynağı hedefe kopyalar, hedefin başlangıç adresini döndürür. `strncpy`: en fazla `n` karakter kopyalar.
  - `strcat`: bir stringin sonuna diğerini ekler (concatenate); `strncat`: ilk `n` karakteri ekler.
  - `strcmp`: sözlük sırasına göre karşılaştırır; eşitse 0, ilk string büyükse pozitif, küçükse negatif döner. Büyük/küçük harf duyarlıdır (case sensitive).
  - `strstr`: bir string içinde başka bir stringi arar; bulursa başladığı yeri gösteren işaretçiyi, bulamazsa `NULL` döndürür.
- Örüntü arama (pattern matching) örneği
  - Soru: ikinci string birincinin içinde aranacak; bulunursa başladığı konum, bulunmazsa -1 döndürülecek; işaretçi işlemleri kullanılacak.
  - Birinci çözüm (`indexOfV1`, ekrandan, 01:35:00): `ptr1` ve `ptr2` ilerletilir, eşleşen karakter sayısı `matchCount`'ta tutulur; eşleşme yarıda kalırsa `ptr1 -= (matchCount-1)` ve `ptr2 -= matchCount` ile geri gidilir.
  - Dış döngü `i <= len1 - len2` koşuluyla döner; `<` yazılırsa son konum denenmez.
  - İkinci çözüm (`indexOfV2`): `strstr`'ün döndürdüğü işaretçiden büyük stringin başlangıç adresi çıkarılınca konum bulunur; çıkarma yapılmadan önce `NULL` kontrolü yapılmalıdır.
- Çok boyutlu diziler ve işaretçi aritmetiği
  - `int ar[3][5]` 3 satır 5 sütunluk bir dizidir; 5 elemanlı 3 tane tek boyutlu dizi olarak da düşünülebilir.
  - `ar[1]`, ikinci satırı (tek boyutlu diziyi) gösterir ve `*(ar+1)` ile aynıdır. Bu yüzden `ar[1][2]`, `*(ar[1]+2)` ve `*(*(ar+1)+2)` aynı elemandır (ekrandan, 02:40:00).
  - Üç boyutta: `char x[3][4][5]` için `x[1][2][3]` ile `*(*(*(x+1)+2)+3)` aynıdır (ekrandan, 02:50:00). Kaç boyut varsa yalnız işaretçiyle erişmek için o kadar `*` gerekir.
  - Çok boyutlu dizi ilklendirmede iç süslü parantezler satırları ayırır; iç parantez yoksa değerler sırayla doldurulur, satır dolunca sonrakine geçilir. Yazılmayan elemanlar 0 olur (ekrandan, 02:45:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Modülerlik
  - Elemanları okuma ve yazdırma gibi tekrar eden işler ayrı fonksiyonlarda olmalıdır; kopyala-yapıştır yapılırsa bir hata iki yerde düzeltilmek zorunda kalınır.
- Programı test etmek
  - Sıralamanın doğruluğunu yalnız çıktının sıralı görünmesine bakarak değil, girilen her elemanın çıktıda yer alıp almadığına bakarak da denetlemek gerekir; yoksa girilmemiş bir eleman gözden kaçabilir.
- Null karakteri
  - String yazarken her zaman 0. indisten başlanır ve sonuna `'\0'` konur. Stringlerle çalışmanın en sağlam yolu önce diziye yer ayırmak, sonra karakterleri yerleştirmek, en sona `'\0'` koymaktır.
- Uyarılara dikkat
  - Derleyicinin uyarısı (ör. tip uyuşmazlığı) göz ardı edilirse program yanlış sonuç verir ya da hiç çıktı vermez.
- Taşma ve platform farkı
  - Hatalı kodun davranışı derleyiciye ve işletim sistemine göre değişir; doğru olan ayrılan maksimum karakter sayısını aşmamaktır.
- İşaretçiyi geri almak
  - İşaretçiyi ilerleterek çalışırken geri dönmek de gerekebilir; ne kadar geri gidileceği hesaplanmalı ya da bir değişkende (`matchCount`) tutulmalıdır. Hoca bunu kasetçalardaki sayaca benzetti: bir şarkıyı yeniden dinlemek için başlangıçtaki sayaç değerini aklınızda tutmanız gerekir.
- İki çözümü de bilmek
  - `indexOfV1` (adım adım ilerleyip gerekince geri dönme) ve `indexOfV2` (`strstr` ile adres farkı) farklı işaretçi işlemleri içerdiği için ikisinin de öğrenilmesi yararlıdır.

## Kısa Tekrar Notları

- Yer değiştirmede geçici değişken şarttır: `tmp = a; a = b; b = tmp;`.
- Sabit için `#define` bellek harcamaz; değişken harcar.
- String = `'\0'` ile biten karakter dizisi.
- Dizinin adına (`array = "..."`) atama yapılamaz; dizi adı bir adrestir.
- `'a'` tek karakter (1 bayt), `"a"` string (2 bayt: `'a'` ve `'\0'`).
- `scanf("%s", str)`: `&` yok, boşlukta durur, `'\0'` ekler, taşmayı engellemez.
- `strcmp` eşitse 0, ilk büyükse pozitif, küçükse negatif; büyük harfler ASCII'de küçük harflerden önce gelir.
- `strstr` bulunamazsa `NULL` döner; konum = dönen işaretçi - stringin başı.
- Örüntü aramada dış döngü sınırı `i <= len1 - len2`.
- `a[i][j]` = `*(a[i]+j)` = `*(*(a+i)+j)`.
- İlklendirmede iç süslü parantezler satır sınırını belirler; eksik elemanlar 0 olur.

## Detaylı Açıklamalar

- Sıralama örneği
  - Kod Dev-C++ 4 üzerinde yazıldı. Önce `ELEMAN_SAYISI` kadar eleman okunur, girilen dizi yazdırılır, sonra iç içe iki döngüyle sıralanır ve sıralı dizi yazdırılır. Derste yazılanın dış yapısı karede görülüyor (ekrandan, 00:15:00); iç döngünün son hâli karede görünmüyor, aşağıdaki sınırlar altyazıdaki anlatımdan alındı. <!-- BELİRSİZ: iç döngünün son hâli karede yok; j=i+1 başlangıcı altyazıdan ("i-1" diye yazılmış) ve Excel izlemesinden çıkarıldı. -->
  - Aşağıdaki kod ajan tarafından derste anlatılana göre bir araya getirildi, `gcc -Wall` ile derlendi ve çalıştırıldı.

    ```c
    #include <stdio.h>
    #define ELEMAN_SAYISI 10

    int main(int argc, char *argv[]) {
        int ar[ELEMAN_SAYISI];
        int i, j, tmp;
        printf("%d eleman girilecek.\n", ELEMAN_SAYISI);
        for (i = 0; i < ELEMAN_SAYISI; i++) {
            printf("%d. elemani girin", (i + 1));
            scanf("%d", &ar[i]);
        }
        printf("Girilen dizi: ");
        for (i = 0; i < ELEMAN_SAYISI; i++)
            printf("%d ", ar[i]);
        printf("\n");
        for (i = 0; i < ELEMAN_SAYISI - 1; i++) {
            for (j = i + 1; j < ELEMAN_SAYISI; j++) {
                if (ar[i] > ar[j]) {
                    tmp = ar[i];
                    ar[i] = ar[j];
                    ar[j] = tmp;
                }
            }
        }
        printf("Sirali dizi: ");
        for (i = 0; i < ELEMAN_SAYISI; i++)
            printf("%d ", ar[i]);
        printf("\n");
        return 0;
    }
    ```

  - Derste girilen değerler 98, 45, 34, 27, 74, 68, 59, 25, 49, 77 idi (ilk yedisi ekrandan, 00:20:00) ve sıralı çıktı 25 27 34 45 49 59 68 74 77 98 oldu. <!-- BELİRSİZ: 8. ve 9. değerler (25, 49) karede yok; altyazıdan ve hocanın sıralı çıktıyı okumasından çıkarıldı. -->
  - Ders sonrası not: Hoca bu algoritmayı bubble sort olarak anlattı ve "her elemanı bir sonrakiyle karşılaştır" dedi, ama derste yazılan döngü `ar[i]`'yi `ar[j]` ($j > i$) ile karşılaştırıyor. Bu biçim büyük olasılıkla "exchange sort" diye bilinen, selection sort'a yakın bir sıralamadır. Klasik bubble sort'ta her geçişte yan yana duran `ar[j]` ile `ar[j+1]` karşılaştırılır. Sonuç yine doğru sıralı dizidir.
- String atama örnekleri
  - Slayttaki koddaki satırlar Dev-C++'ta denendi (ekrandan, 00:45:00). `array = "not OK";` "incompatible types in assignment" hatası verdi ve yoruma alındı. `*ptr2 = "not OK";` tamsayı/işaretçi dönüşümü uyarısı verdi. Hoca uyarıyı geçip programı çalıştırınca hiç çıktı alınamadı; işaretçiyle ilgili şüpheli satırlar kapatılınca dizi `OK` olarak yazdırıldı. `array[5]='A'` atandıktan sonra 0, 1 ve 2. gözlere `'O'`, `'K'`, `'\0'` konduğu için çıktı `OK` oldu. Bu satırlar olmadan yazdırıldığında ekrana anlamsız karakterler geldi; bunlar o bellek gözlerinde kalan değerlerin ASCII karşılıklarıdır, 5. gözde de `A` görünür.
  - Ders sonrası not: Karede `printf("ptr1: %s\n", *ptr1);` ve `printf("%s\n", *ptr2);` satırları görülüyor (ekrandan, 00:45:00). `%s` bir adres (`char *`) bekler, `*ptr1` ise tek bir karakterdir. Hiç çıktı alınamamasının bir nedeni büyük olasılıkla bu satırlardır. Ayrıca `char *ptr1 = "10 spaces";` C'de geçerli bir tanımdır, ama işaretçi değiştirilemeyen bir string sabitini gösterir. Bu yüzden `ptr1[8] = 'r';` tanımsız davranıştır; slayttaki "string henüz doldurulmadı" açıklamasından farklı bir nedendir.
- `scanf` ve taşma
  - `#define MAX_CHAR 80` ile dizi tanımlanıp `scanf("%s", str)` ile okundu, `printf("%s", str)` ile yazıldı. Dizi boyutu 5'e indirilip uzun girişler denendiğinde program hemen çökmedi, ama sonraki tuş basışlarına geç tepki verdi ya da takıldı. Hoca, derleyicinin arka planda küçük bir alan için de (ör. 16 bayt) yer ayırıyor olabileceğini, bu yüzden az taşmanın görünür etki yapmayabileceğini söyledi.
  - Ders sonrası not: Altyazıda hoca, 10 elemanlık dizinin tamamı doldurulunca null karakteri konmadığını ve dizinin sonunun bilindiğini söylüyor gibi. <!-- BELİRSİZ: 01:10:12 civarı altyazı bozuk. --> C'de `scanf("%s")` her zaman sonuna `'\0'` yazar; 10 karakterlik giriş `char[10]` dizisine 11 bayt yazar ve büyük olasılıkla taşmaya yol açar. `printf` de dizinin boyutunu bilmez, yalnız `'\0'` görene kadar yazar.
- `strcmp` denemeleri
  - "Baba" ile "Anne" karşılaştırılınca sonuç 1 oldu, çünkü B, A'dan sonra gelir (ekrandan, 01:30:00). İlk string küçük olacak şekilde girilince -1, iki string aynıyken 0 alındı. Aynı kelimenin küçük harfle başlayan hâli ilk, büyük harfle başlayan hâli ikinci girilince sonuç pozitif çıktı, çünkü ASCII'de büyük harfler küçük harflerden önce gelir.
  - Ders sonrası not: Dev-C++ sonucu 1 ya da -1 olarak verdi. Standart yalnızca işareti garanti eder; ajanın gcc/glibc ile yaptığı denemede küçük/büyük harf örneği 32 verdi (ASCII farkı).
- `strcpy` dönüş değeri
  - Hoca, hedef adresin neden döndürüldüğünü sordu; bir öğrenci, ilk parametre olarak `malloc` ile o anda açılan bir alan verilebileceğini, döndürülen adres sayesinde bu alanın kaybolmayacağını söyledi. Hoca bunu doğruladı; `malloc` ileride işlenecek.
- `strncpy` ve Unicode
  - Ders sonrası not: Hoca, Unicode destekli platformda bir karakter birden çok bayt olsa da `strncpy`'nin `n` karakter kopyalayacağını söyledi. `strncpy` büyük olasılıkla `n` bayt (`char`) kopyalar, çok baytlı karakterleri tanımaz. Ayrıca kaynak `n` karakterden uzunsa hedefe `'\0'` eklemez.
- `indexOfV1` izlemesi (Excel tablosu, ekrandan, 01:45:00 ve 02:20:00)
  - `str1 = "istanbul"` (indis 0-7, 8'de `'\0'`), `str2 = "ana"`. i = 0, 1, 2'de ilk karakterler tutmaz; `matchCount` 0 olduğu için `ptr1 -= (0-1)` ile `ptr1` bir ilerler, `ptr2` yerinde kalır. i = 3'te `a`=`a`, sonra `n`=`n` tutar (`matchCount` 2), `b` ile `a` tutmaz. `ptr1` 1 geri alınır (net olarak 4. indise gelir), `ptr2` 2 geri alınıp başa döner, `matchCount` sıfırlanır. i = 5'ten sonra döngü biter, sonuç -1.
  - `str2 = "anb"` için i = 3'te üç karakter de tutar; `ptr2` `'\0'`'a gelince `while` biter, `matchCount == len2` olduğu için 3 döndürülür (ekrandan, 02:15:00).
  - Derste "bul" için 5, "ula" için -1 alındı; taşma olmadı.
- `indexOfV1` ve `indexOfV2` kodu
  - `indexOfV1` slayttan alındı (ekrandan, 01:35:00); `indexOfV2` altyazıdaki anlatımdan kuruldu, yalnız başlık satırı karede görülüyor (ekrandan, 02:25:00). `main` derste ders notlarındaki hazır koddan kopyalandı; aşağıdaki `main` ajan tarafından ekrandaki istem metinlerine göre yazıldı. Kod `gcc -Wall` ile derlendi ve "istanbul" içinde ana, anb, ist, bul, ula, t aranarak çalıştırıldı (sonuçlar: -1, 3, 0, 5, -1, 2; iki sürüm aynı).

    ```c
    #include <stdio.h>
    #include <string.h>
    #define MAX 64

    int indexOfV1(char *ptr1, char *ptr2) {
        int i, matchCount = 0;
        int len1 = strlen(ptr1), len2 = strlen(ptr2);
        for (i = 0; i <= len1 - len2; i++) {
            while (*ptr1 == *ptr2 && matchCount != len2) {
                matchCount++; ptr1++; ptr2++;
            }
            if (matchCount == len2) return i;
            else {
                ptr1 -= (matchCount - 1);
                ptr2 -= matchCount; matchCount = 0;
            }
        }
        return -1;
    }

    int indexOfV2(char *ptr1, char *ptr2) {
        char *ptr = strstr(ptr1, ptr2);
        if (ptr != NULL) return ptr - ptr1;
        return -1;
    }

    int main(void) {
        char str1[MAX + 1], str2[MAX + 1];
        printf("Enter the 1st string (Max. %d characters): ", MAX);
        scanf("%64s", str1);
        printf("Enter the 2nd string (Max. %d characters): ", MAX);
        scanf("%64s", str2);
        printf("V1 found at: %d\n", indexOfV1(str1, str2));
        printf("V2 found at: %d\n", indexOfV2(str1, str2));
        return 0;
    }
    ```

- Çok boyutlu dizi ilklendirme (ekrandan, 02:45:00)
  - `int exap[5][3] = { {1,2,3}, {4}, {5,6,7} };` satırları 1 2 3 / 4 0 0 / 5 6 7 / 0 0 0 / 0 0 0 olur.
  - `int exap[5][3] = { 1,2,3, 4, 5,6,7 };` satırları 1 2 3 / 4 5 6 / 7 0 0 / 0 0 0 / 0 0 0 olur. Girinti bilgisayar için önemli değildir, iç parantezler önemlidir. Bu iki tablo ajanın `gcc -Wall` ile derleyip çalıştırdığı kodla doğrulandı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
