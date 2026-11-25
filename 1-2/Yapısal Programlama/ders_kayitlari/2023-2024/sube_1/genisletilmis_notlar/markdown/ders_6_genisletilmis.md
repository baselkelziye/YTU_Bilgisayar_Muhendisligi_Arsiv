# Ders 6 Genişletilmiş Notu: String İşlemleri, Alt Metin Arama ve Çok Boyutlu Diziler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki dersten: değiştirilebilir string ve malloc
- 2. Karakter ve string atamalarında doğru ve yanlış
- 3. Kullanıcıdan string okuma
- 4. String uzunluğu: kendi strLen fonksiyonumuz
- 5. string.h fonksiyonları: kopyalama, ekleme, karşılaştırma
- 6. Alt metin arama (Pattern Matching)
- 7. strstr ile çözüm ve dinamik bellekle main
- 8. Çok boyutlu diziler
- 9. Pointer dizileri
- 10. Karakter matrisi üzerinde işlemler
- Örnek Sorular
- Dersin Toparlaması

## 1. Önceki dersten: değiştirilebilir string ve malloc

Ders, bir önceki haftada kalınan yerden başlar. Bir pointer'a doğrudan string sabiti atandığında (`char *p = "...";`) bu stringin içeriği değiştirilemez (immutable). İçeriği değiştirebilmek için kendi bellek alanımızı ayırmamız gerekir.

Bunun yolu `malloc` fonksiyonudur (memory allocation). `malloc`, istenen sayıda baytlık bir alan ayırır ve bu alanın başlangıcını gösteren bir pointer döndürür. Döndürdüğü pointer `void *` türündedir. Bunun nedeni şudur: ayrılan alan herhangi bir veri türünü saklamak için kullanılabilir ve derleyici bu anda hangi türün saklanacağını bilemez. Biz `(char *)` dönüşümüyle (casting) bu alanda karakter saklayacağımızı beyan ederiz.

Alan ayrıldıktan sonra `strcpy` ile içerik kopyalanır. `strcpy`'nin ilk parametresi hedef pointer'dır, ikinci parametresi kaynak metindir. Kopyalamadan sonra metin üzerinde istediğimiz değişikliği yapabiliriz; örneğin 8. indisteki karakteri başka bir harfle değiştirebiliriz. `strcpy`'nin ve `malloc`'un başka biçimleri de vardır; bunlar ilerleyen derslerde görülecektir.

## 2. Karakter ve string atamalarında doğru ve yanlış

### 2.1 Slayttaki örnek

Ekrandaki "Strings vs. Chars" slaytı iki bölümden oluşur (ekrandan, 00:20:00):

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

Tek karakterle çalışırken her zaman tek tırnak kullanılır. `char ch = 'a';` ile bir karakter değişkeni tanımlanır ve bellekte 1 bayt yer tutar. Yanına tanımlanan `char *p` artık karakter adreslerini gösterebilen bir pointer'dır.

Hoca burada iki gösterimi yeniden hatırlatır: pointer'ın başına yıldız koyunca pointer'ın gösterdiği yerdeki değer (yönlendirdiği yer, "indirection") kastedilir; pointer'ın adı tek başına yazılınca bellek adresi kastedilir. Bu yüzden:

- `*p = 'a';` pointer'ın gösterdiği yere `a` karakterini yazar. Söz dizimi olarak doğrudur.
- `p = 'a';` bir bellek adresinin yerine karakter yazmaya çalışır. Bellek adresine böyle bir değer atanamaz; derleyici hata verir. Bu satır geçersizdir (illegal).

String bölümünde durum farklıdır. `"a"` çift tırnaklı olduğu için bir stringdir ve birden fazla karakterden oluşan bir bellek alanının başlangıcı olarak değerlendirilir. C'nin null ile sonlanma (null termination) kuralı yüzünden `"a"` için 2 bayt ayrılır: ikinci bayt null karakteridir.

- `p = "a";` bir bellek alanının başlangıç adresini pointer'a yazar. Geçerlidir.
- `*p = "a";` tek karakterlik bir göze bir adres yazmaya çalışır. Yanlıştır.

Hoca normalde string'e doğrudan `=` ile değer atamanın çok sık yapılan bir şey olmadığını, ama sınavda "bu kod satırı çalışır mı, çalışmaz mı?" tipinde sorulabileceğini söyler.

> **Hocanın vurgusu:** Sınavda verilen bir kodda hangi satırın çalışıp hangisinin çalışmadığı sorulabilir; karakter ve string atamalarındaki bu farklar bilinmelidir.

### 2.2 Dev-C++'ta deneme

Hoca slayttaki kodu Dev-C++ editörüne aktarır (ekrandan, 00:25:00). Burada önemli bir uyarı yapar: PowerPoint ya da Word'den kopyalanan biçimli (kıvrık) tırnaklar kodda beklenmedik hatalara yol açar; kodda düz tek tırnak kullanılmalıdır.

`p = 'a';` satırı açık bırakıldığında derleyici "makes pointer from integer without a cast" mesajını verir. Hoca bu satırı yorum satırı yapınca program derlenir ama çalışırken takılır; terminal penceresi kapatılıp yeniden çalıştırıldıktan sonra `%c` ile yazdırma düzgün çalışmaya başlar (ekrandan, 00:30:00). Hoca derleme hatası ile bağlayıcı (linker) hatası arasındaki ayrımın burada önemli olmadığını, ikisine de "derleme hatası" denebileceğini söyler.

> **Ders sonrası not:** Slayttaki karakter örneğinde `p` hiçbir yere bağlanmadan `*p = 'a'` yapılıyor. İlklendirilmemiş bir pointer'ın gösterdiği yere yazmak tanımsız davranıştır; derste görülen takılmanın nedeni büyük olasılıkla budur. Önce `p = &ch;` gibi geçerli bir adres atanmalıdır. Ayrıca `printf("%s\n", *p)` yanlıştır: `*p` bir `char` olduğu için `%c` kullanılmalıdır (gcc `-Wall` bu satır için biçim uyarısı veriyor). Slayttaki "OK" etiketi yalnız söz dizimi içindir.

String bölümünde de `*p = "a"` satırı açık bırakılınca derleyici "integer from pointer without a cast" türünde bir uyarı verir; bu satır kapatılınca `%s` ile yazdırma sorunsuz çalışır.

## 3. Kullanıcıdan string okuma

Elle metin girmek güzel ama asıl önemli olan metni kullanıcıdan almaktır; hoca "kullanıcıdan veri almayan bir program işe yaramaz" der. İlk olarak dizi üzerinden gidilir (ekrandan, 00:35:00):

```c
#include <stdio.h>
#define MAX_CHAR 80
int main(int argc,char *argv[]){
    char str[MAX_CHAR];
    printf("Enter a string: ");
    scanf("%s",str);
    printf("You wrote:");
    printf("%s\n",str);
    return 0;
}
```

Slayttaki kurallar şunlardır:

- `scanf()` ile string okunabilir. Veri argümanı, girilen metni tutacak kadar uzun bir karakter dizisinin adresi olmalıdır.
- `scanf()` okuduğu karakterlerin sonuna otomatik olarak null karakter ekler, böylece okunan şey düzgün bir string olur.
- `printf()` ile string yazdırılır. Veri argümanı null ile biten bir karakter dizisinin adresi olmalıdır.

Dizinin adı zaten adres olduğu için `scanf`'te `&` yazılmaz. Derste Türkçe karakterli bir girişin komut satırında sorunsuz okunup yazıldığı görüldü (ekrandan, 00:40:00). Hoca, Türkçe karakterler kodun içine elle yazılsaydı karakter kodlama standardı farklı olacağı için sorun çıkabileceğini söyler.

`scanf`'in bir huyu da ilk boşlukta okumayı kesmesidir. Boşluklu bir metin girildiğinde yalnız ilk kelime okunur.

Hoca burada bir uyarı ekler: string'in sonunu boşluk karakterine göre düşünmemek gerekir. Elle atama yapıldığında ya da `strcpy` ile kopyalandığında boşluk da metnin geçerli bir parçasıdır. Düzgün bir stringin sonu null karakteridir.

## 4. String uzunluğu: kendi strLen fonksiyonumuz

Bir stringin kaç karakter olduğunu bulmak için dizinin elemanları tek tek kontrol edilir; null karaktere gelince sona ulaşılmış olur (ekrandan, 00:45:00):

```c
int strLen( char *str ) {
    int i=0;
    while( str[i] != '\0' ) {
        i++;
    }
    return i;
}
```

Fonksiyonun adında `L` harfi bilerek büyük yazılmıştır, çünkü hepsi küçük harfli `strlen` zaten `string.h` içinde hazır olarak vardır. Hoca, hazırını göstermeden önce aynı işi kendimizin yapmasını ister.

### 4.1 Parametre neden pointer?

Main'de bir dizi tanımlanmış olsa da fonksiyon parametresi dizi değil `char *` olarak seçilir. Dizi parametresinde boyut verilmesi gerekebilir; her farklı uzunluktaki string için ayrı fonksiyon yazmak istemeyiz. Pointer'a da dizi gibi string atanabilir, diziye de. Ama hocanın ifadesiyle "dizilere pointer üzerinden erişebiliriz, pointer'a dizi üzerinden erişemeyiz". En yüksek esnekliği pointer verir. Hoca ayrıca boyutsuz dizi parametresinin bazı derleyicilerde çalışmayabileceğini, taşınabilirlik açısından emin olmadığını söyler.

### 4.2 Parametre aktarımı

`str` main fonksiyonunda tanımlanmış yerel bir dizidir. `strLen(str)` çağrısıyla fonksiyona verildiğinde, fonksiyondaki `str` pointer'ı dizinin ilk elemanını, yani dizinin bellekteki başlangıcını gösterir. Main'deki dizi ile fonksiyondaki pointer eşleşmiş olur. Bu yüzden fonksiyonun içinde metin üzerinde değişiklik yapılırsa bu değişiklik main'deki diziye de yansır.

### 4.3 malloc ile birlikte

Hoca aynı programa bir `char *p` ekler, `p = (char*)malloc(MAX_CHAR);` ile yer ayırır, okunan diziyi `strcpy(p, str);` ile kopyalar ve `p`'yi yazdırır (ekrandan, 00:50:00). Derste `string.h` eklenmeden `strcpy` kullanılabildiği görüldü; hoca derleyicinin arka planda bunu kendi standart kütüphanesinden bulduğunu tahmin eder ve sonra `string.h`'yi ekler.

> **Ek bilgi (derste anlatılmadı):** Eski C derleyicileri bildirimi görülmeyen bir fonksiyon çağrısına izin verip onun `int` döndürdüğünü varsayar ("örtük bildirim"). Bu yüzden `string.h` eklenmeden de kod derlenebilir, ama adres döndüren fonksiyonlarda bu varsayım hatalı sonuç verebilir. Güncel derleyiciler bunu hata sayar; kullanılan her kütüphane fonksiyonunun başlık dosyası eklenmelidir.

## 5. string.h fonksiyonları: kopyalama, ekleme, karşılaştırma

Slaytta `string.h` içindeki diğer fonksiyonlar listelenir (ekrandan, 01:15:00):

```c
char* strcpy(char* szCopyTo, const char* szSource)
char* strncpy(char* szCopyTo, const char* szSource, size_t sizeMaxCopy)
char* strcat(char* szAddTo, const char* szAdd)
char* strncat(char* szAddTo, const char* szAdd, size_t sizeMaxAdd)
int strcmp(const char* sz1, const char* sz2)
int strncmp(const char* sz1, const char* sz2, size_t sizeMaxCompare)
```

Slaytta adların neden böyle olduğu da gösterilir: copy, concatenate, compare.

### 5.1 Kopyalama

`strcpy` kaynağın tamamını hedefin üzerine yazar; hedefteki eski içerik ne olursa olsun silinir. `strncpy`'nin üçüncü parametresi bir tam sayıdır ve kaynaktan hedefe kaç karakter kopyalanacağını belirtir. Kaynağın tamamını değil yalnız baştan belli sayıda karakteri kopyalamak istiyorsak `strncpy` kullanılır.

### 5.2 Ekleme

Hedefin üzerine yazmak yerine sonuna eklemek istiyorsak `strcat` kullanılır. "cat", concatenation yani sona ekleme, birleştirme demektir. Hoca, C ile Unix'in yakınlığını hatırlatır: `cat` bir Unix komutudur, bu yüzden C tasarlanırken "concat" yerine kısaca "cat" denmiştir. `strcat` de `strcpy` gibi iki parametre alır: ilk parametre hedef, ikincisi kaynaktır. `strncat` ise kaynaktan yalnız n karakteri hedefin sonuna ekler.

Ekleme yaparken ilk stringte yeterli yer olmalıdır. Hedef ister dizi olsun ister `malloc` ile ayrılmış pointer, ekleme sonunda oluşacak daha uzun stringi barındıracak kadar bellek olduğundan emin olmak gerekir. Hoca, en güvenli yol olarak hedef pointer'a `MAX_CHAR * 2` kadar yer ayrılabileceğini söyler.

### 5.3 Karşılaştırma

`strcmp` iki string alır ve birinci parametredeki stringi ikinciyle karşılaştırır. Karşılaştırma sözlük sırasına göre ve büyük-küçük harf ayrımıyla yapılır. Bilgisayarın sözlüğünde önce büyük harfler, sonra küçük harfler gelir: önce `A`-`Z`, sonra `a`-`z`.

- Birinci string sözlükte daha önde ise (daha küçükse) negatif bir sayı döner.
- İkinci string daha önde ise pozitif bir sayı döner.
- İki string tamamen eşitse 0 döner.

Hoca bunu "pivot noktası birinci string" diye özetler: birinci parametre küçükse negatif, büyükse pozitif.

Hoca ilk saatte söylemeyi unuttuğu bir noktayı ikinci saatin başında ekler: Türkçe ve diğer aksanlı karakterler İngiliz alfabesinin normal harflerinin sonuna eklenmiştir. Büyük `Z`'den sonra büyük `Ç`, büyük `Ş` gibi harfler gelir. Bu yüzden bizim alfabemizde `Ç` harfi `D`'den önce gelse de bilgisayarın sıralamasında `D` her zaman `Ç`'den öncedir.

`string.h` içinde `str` ile başlayan başka fonksiyonlar da vardır; merak edilenler oradan incelenebilir.

### 5.4 Derste yapılan deneme

Pointer üzerinden gidilir. `p` ve `str` ikisi de `"bol"` iken `strcmp(p, str)` 0 döndürür. Sonra `str[0] = 'z'` yapılır: `"bol"` ile `"zol"` karşılaştırılır, birinci metin daha küçük olduğu için negatif sonuç alınır. Ardından `str[0] = 'a'` yapılır: `"bol"` ile `"aol"` karşılaştırılır, birinci metin daha büyük olduğu için pozitif sonuç alınır. Hoca, dönen değerin harfler arasındaki fark kadar olmadığını, yalnız -1, +1 ya da 0 olduğunu gözlemler.

Ardından `strcat(p, str)` denenir. Sonuç ekranda `Resulting string:bolbol` olarak görünür (ekrandan, 00:55:00). Hoca araya boşluk istenirse bir `strcat` daha yapılabileceğini söyler.

> **Ders sonrası not:** Hoca `strcmp`'in yalnız -1, 0 ya da +1 döndürdüğünü söyledi. Derste kullanılan kütüphanede böyle çıktı, ama C standardı yalnız işareti (negatif, sıfır, pozitif) garanti eder. Örneğin glibc ile `strcmp("bol", "zol")` -24 döndürür (ajan tarafından denendi). Bu yüzden sonuç `== -1` diye değil `< 0` diye kontrol edilmelidir.

## 6. Alt metin arama (Pattern Matching)

### 6.1 Problem

Slayttaki problem şudur: kullanıcıdan iki string alınır; ikinci stringin birincinin içinde geçip geçmediği aranır. Geçiyorsa ilk geçtiği yerin konumu (kaçıncı harften itibaren başladığı), geçmiyorsa -1 döndürülür. Bu işte pointer işlemleri kullanılmalıdır. Fonksiyonun imzası `int indexOfV1(char *ptr1, char *ptr2)` olarak seçilir.

### 6.2 Algoritmanın fikri

Hoca algoritmayı bir tabloda çizerek anlatır (ekrandan, 01:20:00). Ana string `babamin`, aranan string `bam`:

```text
ptr1:  b  a  b  a  m  ı  n
ptr2:  b  a  m
```

- İki string'in birinci harfleri karşılaştırılır: ikisi de `b`, uyuyor. İki pointer birlikte ilerletilir.
- İkinci harfler: ikisi de `a`, uyuyor. İlerlemeye devam edilir.
- Üçüncü harfler: ana stringte `b`, aranan stringte `m`. Uymuyor; demek ki bu başlangıç noktasında aranan metin yok.

Şimdi karşılaştırmaya nereden başlanmalıdır? Ana büyük stringin ikinci harfinden, ama aranan küçük stringin birinci harfinden. İki pointer'ı kaldığı yerden birer artırarak devam etmek yanlış olur; karşılaştırılması gereken harfler atlanır ve var olan bir eşleşme bulunamaz. Her yeni denemede (hoca buna "ralli" de der) ana stringte denemeye başladığımız yerin bir ilerisine, aranan stringte ise en başa dönmek gerekir.

Hoca bunu "ipin ucunu kaçırmayın" diye anlatır: string, ip gibidir; `ptr1` ve `ptr2`'nin başlangıçlarını kaybetmemek gerekir. İki yol vardır:

- Ayrı karşılaştırma pointer'ları (`cmp1`, `cmp2`) tanımlamak.
- Ek pointer kullanmak yerine `ptr1` ve `ptr2`'yi ilerletip ne kadar ilerlendiğini saymak, sonra o kadar geri çekmek.

Derste ikinci yol, yani sayı tutma yolu seçilir. Her eşleşmede `matchCount` artırılır. Eşleşme sayısı aranan stringin uzunluğuna ulaşırsa metin bulunmuştur ve o denemenin başladığı konum döndürülür.

### 6.3 Kodun adım adım kurulması

Gereken değişkenler: `matchCount` (eşleşme sayısı), `len2` (aranan stringin uzunluğu) ve `from` (ana stringte o anki denemenin başladığı konum). Hoca `from` adını "şu karakterden itibaren" anlamında seçer. Başta `len2 = strlen(ptr2); from = 0; matchCount = 0;` yapılır.

Ana döngü, `ptr1` sonuna (null karaktere) gelmediği sürece döner. İçindeki döngü, iki pointer'ın gösterdiği harfler eşit olduğu ve `ptr1` sona gelmediği sürece iki pointer'ı ve `matchCount`'u birlikte artırır. Ekrandaki ara sürüm şöyledir (ekrandan, 01:35:00):

```c
int indexOfV1( char *ptr1, char *ptr2 ) {
    int matchCount, len2, from;
    len2 = strlen(ptr2); from = 0; matchCount = 0;
    while( *ptr1 != '\0' ) {
        while( *ptr1 == *ptr2 && *ptr1 != '\0' ) {
            ptr1++; ptr2++; matchCount++;
        }
    }
    if( matchCount == len2 )    return from;
    else return -1;
}
```

Hoca iç döngüden çıkış nedenlerini sayar: ya harfler uyuşmamıştır, ya da iki pointer'dan biri sona gelmiştir. `ptr2` sona gelip de hâlâ birlikte gidiliyorsa metin bulunmuş demektir; bu durumda `matchCount`, `len2`'ye eşittir ve `from` döndürülür. Aranan metin en baştaysa `from` 0'dır.

Aksi hâlde pointer'lar doğru yerlerine geri çekilir:

- `from` bir artırılır.
- `ptr1`, `matchCount` kadar geri çekilir, ama bir ilerisine gidilmelidir.
- `ptr2`, `matchCount` kadar geri çekilerek en başa alınır.

Hoca burada bir "off by one" (bir eksik/bir fazla) hatası yapmamak için örnek üzerinden kontrol eder: iki karakter eşleşip üçüncüde eşitlik bozulduysa `matchCount` 2'dir. `ptr1` 2 geri giderse yine denemenin başına döner; oysa bir ilerisine gitmesi gerekir. Bu yüzden şöyle yazılır:

```c
ptr1 = ptr1 - matchCount + 1;
ptr2 = ptr2 - matchCount;
```

> **Hocanın vurgusu:** `ptr1 -= matchCount + 1;` yazılırsa önce `matchCount + 1` hesaplanır ve pointer bir fazla değil iki fazla geri gider. Bu yüzden ifade açık yazılmalıdır.

İlk denemede kod ilk baştaki eşleşmeyi buldu, ama ortadaki eşleşmeyi bulamadı (ekrandan, 01:40:00; `babamin`/`bam` için -1). Hoca eksiği bulur: geri dönerken `matchCount` sıfırlanmamıştır. Her yeni karşılaştırmaya başlarken `matchCount` tekrar 0 yapılmalıdır, ama geri çekme işlemlerinden sonra; önce sıfırlanırsa geri çekme yanlış olur.

Derste yazılan son hâl karelerde tam görünmüyor. Aşağıdaki kod, ekrandaki ara sürüm ve hocanın anlattığı düzeltmelerle kurulmuştur. Ajan tarafından `gcc -Wall` ile derlenip denendi.

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

### 6.4 Test durumları

Hoca düzeltmeden sonra kodu farklı durumlarla dener:

- Baştan eşleşme: aranan metin ana stringin başında. Konum 0.
- Ortada eşleşme: `babamin` içinde `bam` 2. konumda bulunur (0, 1, 2 diye sayarak).
- Sonda eşleşme: 4. konumda bulunan bir örnek.
- Olmayan metin: -1.
- Tek harf, son harf: 6. konumda bulunur (0'dan 6'ya sayarak).
- İkinci string birinciden uzun: bulunamaz, -1. Çünkü ikinci string birincinin içinde aranır, tersi değil.

Hoca öğrencilere başka test durumu önerip önermediklerini sorar. Ajanın aynı kodla yaptığı denemelerde `babamin`/`bam` için 2, `bambam`/`bam` için 0, `abcdefg`/`g` için 6, `abc`/`xyz` için -1, `ab`/`abc` için -1 elde edildi.

### 6.5 Slayttaki for döngülü çözüm

Slayttaki hazır çözüm (Answer 1) aynı mantıkla, ama `for` döngüsüyle yazılmıştır. Döngü değişkeni, ana string üzerinde aramanın kaçıncı konumdan başladığını tutar ve 0'dan `len1 - len2`'ye kadar gider. Örneğin 7 karakterlik stringte 3 karakterlik metin aranıyorsa son 3 karakterin başından sonra aramaya başlamanın anlamı yoktur, çünkü yeterli harf kalmamıştır. Hocanın çözümü ise sona kadar devam ettiği için 2-3 fazla karşılaştırma yapar; hoca "2-3 işlem az yapmak kârdır, ama çok da dert değil" der.
<!-- BELİRSİZ: Slayttaki "Answer 1" kodunun tam metni karelerde görünmüyor; yalnız anlatımı aktarıldı. -->

## 7. strstr ile çözüm ve dinamik bellekle main

### 7.1 Hazır fonksiyon var mı?

**Soru:** Bunun hazır bir fonksiyonu yok mu? **Cevap:** Var; `string.h` içindeki `strstr`. Hoca bunu `string.h` dosyasını açarak gösterir (ekrandan, 01:45:00 ve 01:50:00):

```c
char*   strstr (const char* szSearch, const char *szFor);
```

Hoca önce `strstr`'in konum döndürdüğünü sanıp denediğinde beklediği sonucu alamaz; parametrelerin yerini değiştirmeyi de dener. Sonra fonksiyonun bir bellek adresi (`char *`) döndürdüğünü görür. Bu esneklik sağlar; kendi fonksiyonumuz da istersek `char *` döndürebilir.

### 7.2 Slayttaki Answer 2

(ekrandan, 01:55:00)

```c
int indexOfV2( char *ptr1, char *ptr2 ) {
    char *ptr;
    ptr = (char*) strstr(ptr1, ptr2);
    if( ptr != NULL )   return ptr-ptr1;
    else                return -1;
}
```

Slayta göre `strstr` ya `szFor`'un `szSearch` içinde ilk geçtiği yerin başlangıcını gösteren geçerli bir pointer, ya da null pointer döndürür. Null dönmüşse metin yoktur. Değilse bulunan konumdan ana stringin başlangıç adresi çıkarılır. Bulunan konum ana stringin başlangıcına eşit ya da ondan ileride olacağı için büyükten küçük çıkarılır ve sonuç konumu verir. Hoca bu çözümün daha kolay ve verimli olduğunu, ama `strstr` diye bir fonksiyon olduğunu bilmeyi gerektirdiğini söyler. Derste iki fonksiyon aynı girdilerle çalıştırılıp aynı sonuçları verdiği görüldü.

Hoca, bir pointer'ın adresini yazdırmak için `%p` biçimini de araştırıp gösterir: `%p`, pointer türündeki verilerin değerini yazdırmak için kullanılır ve adresi onaltılık (hexadecimal) yazar. İki adresin farkı ise bir tam sayıdır ve `%d` ile yazdırılır.

### 7.3 Main'i pointer'larla yazmak

Bu kez `str1` ve `str2` dizi değil pointer olarak tanımlanır ve `malloc` ile yer ayrılır (ekrandan, 02:00:00 ve 02:05:00):

```c
char *str1, *str2;
str1 = (char*) malloc(MAX_CHAR);
if( str1 == NULL ) { printf("Out of memory"); exit(1); }
str2 = (char*) malloc(MAX_CHAR);
if( str2 == NULL ) { printf("Out of memory"); exit(1); }
printf("Enter the 1st string (Max. %d characters): ", MAX_CHAR);
scanf("%s",str1);
printf("Enter the 2nd string (Max. %d characters): ", MAX_CHAR);
scanf("%s",str2);
printf("Found at: %d\n", indexOfV1(str1,str2));
printf("Found at: %d\n", indexOfV2(str1,str2));
...
free(str1); free(str2);
```

Hoca burada iyi bir alışkanlığı vurgular: dinamik bellek yönetiminde sistemde yeterli boş bellek olmayabilir ve `malloc` null dönebilir. Bu kontrol edilmeli, null ise uygun bir mesaj verilmelidir. Programdan çıkmadan önce de `free` ile alanlar boşaltılmalıdır. `scanf`'e doğrudan pointer verilebildiği de görülür.

> **Hocanın vurgusu:** `malloc` sonrası null kontrolü ve sonda `free` şimdiden alışkanlık hâline getirilmelidir.

Hoca son olarak `str2 = strstr(str1, str2);` yazıp `str2 - str1` farkını yazdırmayı dener. Derleyici "assignment makes pointer from integer without a cast" uyarısı verir ve hoca bu denemeyi bırakır.

> **Ders sonrası not:** Uyarının nedeni büyük olasılıkla `string.h` dosyasının eklenmemiş olmasıdır: bildirimi görülmeyen `strstr`'in `int` döndürdüğü varsayılır ve 64 bitlik sistemde adres bozulabilir. Ayrıca `str2` bu atamayla `malloc`'tan gelen adresi kaybeder (bellek sızıntısı); sonra `free(str2)` yapmak, `malloc`'un döndürmediği bir adresi serbest bırakmak olur ve tanımsız davranıştır. `strstr`'in sonucu ayrı bir `char *` değişkene atanmalıdır.

## 8. Çok boyutlu diziler

### 8.1 Neden gerekli?

Bir metin yalnız tek satırdan oluşmaz, birden fazla satırı olabilir. Böyle bir durumu modellemek için iki boyutlu karakter dizileri (karakter matrisleri) gerekir. Hoca sınavlarda bu konudan genelde bir soru sorulduğunu söyler.

> **Hocanın vurgusu:** Tek boyutlu dizilerde köşeli parantezle yapılan işin pointer artırarak nasıl yapıldığını biliyoruz; çok boyutlu dizilerde de köşeli parantezlerin pointer operatörleriyle nasıl yazıldığı ayırt edilebilmelidir. Bu önem verilecek bir konudur.

### 8.2 İki boyutlu dizi ve pointer gösterimi

`int ar[5][3];` tanımı 5 satır, 3 sütunluk bir dizi oluşturur: satır indisleri 0-4, sütun indisleri 0-2'dir. Hoca bunu Excel'de bir tabloyla gösterir (ekrandan, 02:25:00) ve `ar[1][2]` gözünü işaretler. Slayta göre `ar`, 3 elemanlı dizilerden oluşan 5 elemanlı bir dizidir. Yani `ar[1]` satırı kendi içinde 3 elemanlık tek boyutlu bir dizi gibi düşünülebilir.

Çeviri her köşeli parantez ayrı düşünülerek ve en sağdan başlanarak yapılır:

- `ar[1][2]` ifadesinde `ar[1]` tek boyutlu bir dizi gibi ele alınır. Normal pointer aritmetiğiyle `ar[1] + 2` o satırın 2. sütununu gösterir; değerini almak için başa yıldız konur: `*(ar[1]+2)`.
- Sonra `ar[1]` de aynı mantıkla `*(ar+1)` olarak yazılır. Parantez unutulmamalıdır.
- Sonuç: `*(*(ar+1)+2)`.

### 8.3 Üç boyutlu örnek

Slaytta `char x[3][4][5];` için "x, 5 elemanlı dizilerden oluşan 4 elemanlı dizilerin 3 elemanlı dizisidir" denir. Hoca `x[1][2][3]` gözünü adım adım pointer gösterimine çevirir (ekrandan, 02:30:00):

```text
x[1][2][3]
*(x[1][2]+3)
*(*(x[1]+2)+3)
*(*(*(x+1)+2)+3)
```

Her adımda en sağdaki köşeli parantez "artı indis" olarak yazılır ve önceki kısmın tamamı parantez içine alınıp başına yıldız konur. Hoca, yıldızı bir kez yanlış yere koyup düzeltir ve bütün parantezlerin ve yıldızların yerinin çok kritik olduğunu söyler.

### 8.4 İlklendirme

5 satır, 3 sütunluk matris "5 tane 3 elemanlık dizi" gibi düşünülebildiği için ilklendirme de böyle yazılır. Her matris satırı kendi süslü parantez bloğu içinde yazılır:

- İlk süslü parantez bloğu (1, 2, 3) birinci satıra yerleşir.
- İkinci blokta üç eleman yazılabilecekken yalnız bir eleman yazılmıştır. Kalan elemanlar 0 olur.
- Üçüncü blok (5, 6, 7) üçüncü satır olur. Orada 7 yazılmasaydı o göz 0 olurdu.
- Hiç yazılmayan satırlar tamamen 0 kalır.

İç süslü parantezler yazılmazsa değerler soldan sağa sırayla okunur. Satır sonu ve boşluklar (whitespace) bilgisayar için bir anlam taşımaz; yalnız bizim okumamızı kolaylaştırır. 1, 2, 3, 4, 5, 6, 7 değerleri ilk gözden başlayarak satır satır yerleştirilir, bir satır dolunca diğerine geçilir ve ilk 7 eleman dolduktan sonra kalan gözler 0 olur.
<!-- BELİRSİZ: İlklendirme slaytı karelerde yok; ikinci satıra yazılan tek değer altyazıdan okunamadı. -->

> **Ek bilgi (derste anlatılmadı):** `int b[5][3] = {1,2,3,4,5,6,7};` gibi iç süslü parantezsiz ilklendirme geçerlidir, ama gcc `-Wall` ile "missing braces around initializer" uyarısı verir. Okunabilirlik için iç süslü parantezler yazılmalıdır.

## 9. Pointer dizileri

Şimdiye kadar elemanları ilkel türden (karakter, tam sayı) olan dizilerle çalışıldı. Bir dizinin elemanları pointer da olabilir. Saklanacak değerlerin türü neyse pointer dizisinin türü de o seçilir; karakter saklanacaksa `char *` kullanılır. Bunun bir pointer dizisi olduğunu belirtmek için addan önce mutlaka yıldız konur (ekrandan, 02:35:00):

```c
char *ar_of_p[5];
char c0 = 'a';
char c1 = 'b';

ar_of_p[0] = &c0;
ar_of_p[1] = &c1;
```

Slayttaki bellek resmi:

| Eleman | Adres | Değer |
|---|---|---|
| `ar_of_p[0]` | 0x1000 | 2000 |
| `ar_of_p[1]` | 0x1004 | 2001 |
| `ar_of_p[2]` | 0x1008 | undefined |
| `ar_of_p[3]` | 0x100C | undefined |
| `ar_of_p[4]` | 0x1010 | undefined |
| `c0` | 0x2000 | `'a'` |
| `c1` | 0x2001 | `'b'` |

`ar_of_p[0]` de bir pointer'dır, yani ilk göz bir karakter değil bir adres tutar. Pointer dizisinin elemanları 4'er bayt artan adreslerde yer alır, çünkü örnekte bir pointer 4 bayt yer tutar. Dizinin ilk elemanının `c0`'ı göstermesi için tek pointer'da olduğu gibi adres alma operatörü kullanılır: `ar_of_p[0] = &c0;`. Böylece `ar_of_p[0]` gözünde `c0`'ın adresi (2000), `ar_of_p[1]` gözünde `c1`'in adresi (2001) yer alır.

Diğer üç elemanın değeri tanımsızdır (undefined). `malloc` ile yer ayrılmadığı ve atama yapılmadığı için null bile değildirler; bellekte o anda ne kaldıysa o değeri taşırlar. Onları kullanmaya çalışmak programın donmasına ya da çökmesine yol açabilir.

> **Ders sonrası not:** Pointer'ın 4 bayt olması 32 bitlik sistemler içindir. 64 bitlik sistemlerde pointer genellikle 8 bayttır, dolayısıyla eleman adresleri 8'er bayt artar.

## 10. Karakter matrisi üzerinde işlemler

### 10.1 Program yapısı

Slaytta incelenmesi önerilen örnek kodlar üzerinden, karakter matrisiyle çalışan bir program yazılır. `#define SIZE 5` ile kare bir matris kullanılır: `char metinler[SIZE][SIZE]`. Kullanıcıdan her satır için en çok 5 harflik bir metin istenir (ekrandan, 02:55:00):

```c
for( i=0; i<SIZE; i++ ) {
    printf("Enter text %d: (max %d letters)", i, SIZE);
    scanf("%s",&metinler[i]);
}
```

Hoca ayrıca ASCII kodlarını hatırlatır: büyük `A` 65, küçük `a` 97'dir; aradaki fark 32'dir. Teoride bir harfi büyükten küçüğe çevirmek için değerine 32 eklenir, küçükten büyüğe çevirmek için 32 çıkarılır. Bu yöntem Türkçe, Almanca gibi dillerin aksanlı karakterlerinde çalışmaz.

### 10.2 Bütün satırları tek pointer'la yazdırmak

`listAllLines` fonksiyonu bir başlangıç adresi alır ve oradan itibaren bütün matrisi yazar (ekrandan, 02:45:00):

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

Buradaki asıl soru şudur: tek bir pointer matrisin başlangıcına atanıp birer birer ilerletildiğinde, ilk satırın sonuna gelince ikinci satıra geçebilecek mi? Cevap evettir. Matris için ayrılan alan bellekte birbirini izleyen gözlerdir: birinci satırın elemanları yazıldıktan sonra sıradaki göze ikinci satırın ilk elemanı gelir. Biz matrisi iki boyutlu düşünür ve öyle görselleştiririz, ama günün sonunda elemanlar sırayla birbirini izleyen gözlere yazılır.

Satır sütun görünümünü korumak için, indisi `SIZE`'a tam bölünen elemanlardan (0, 5, 10, ...) önce yeni satıra geçilir. Gözdeki değer yazılabilir bir harfse yazılır, sonra pointer bir ilerletilir. Hoca, matristeki doldurulmamış gözlerde kalan anlamsız değerlerin ekrana basılmaması için bu harf kontrolünü koyduğunu söyler.

Fonksiyon önce `listAllLines(metinler)` diye çağrılınca derleyici "incompatible pointer type" uyarısı verir. Hoca `metinler[0]` yazarak düzeltir; bu, 0. satırın başlangıcıdır ve mantıksal olarak aynı yeri gösterir.

Derste girilen satırlar `qwert`, `asdfg`, Türkçe harflerden oluşan bir satır, sembollerden oluşan `-+*!@` ve `zxcvb` idi. Çıktıda sembol satırı boş kaldı, Türkçe harfli satırdan yalnız İngiliz alfabesinde olan `i` yazıldı (ekrandan, 02:50:00). Harf olmayan karakterler atlanır, atlanan yere boşluk da basılmaz. Hoca, harf olmayanların yerine boşluk basılmasını isteseydik bir `else` ile tek boşluk yazdırabileceğimizi söyler.

> **Ders sonrası not:** Koşuldaki 123 ve 91 sınırları bir fazladır: `'z'` 122, `'Z'` 90'dır. 91 (`[`) ve 123 (`{`) da harf gibi yazdırılır; doğru sınırlar `<= 122` ve `<= 90` olmalıdır. Ayrıca 5 harflik metin `char metinler[5][5]` satırına `scanf` ile okunduğunda sondaki null karakter bir sonraki satırın ilk gözüne taşar; son satırda dizinin dışına yazılır ve bu tanımsız davranıştır. Satır uzunluğu `SIZE + 1` olmalı ya da `scanf("%5s", metinler[i])` gibi sınırlı okuma yapılmalıdır. `&metinler[i]` yerine `metinler[i]` yazmak da tür açısından doğrusudur.

### 10.3 Bir satırı küçük ya da büyük harfe çevirmek

`toLowerCase` fonksiyonuna çevrilmek istenen satırın başlangıcı parametre olarak verilir. Fonksiyon sütun sayısı (`SIZE`) kadar eleman üzerinde döner. Eleman gerçekten büyük harfse 32 eklenerek küçük harfe çevrilir. Zaten küçük harfse ya da harf değilse hiçbir şey yapılmaz; kontrol yapılmadan çıkarma ya da ekleme yapılırsa harf olmayan bir koda düşülebilir. `toUpperCase` da aynı mantıkla, küçük harfleri 32 çıkararak büyük harfe çevirir.
<!-- BELİRSİZ: toLowerCase ve toUpperCase fonksiyonlarının kodu karelerde görünmüyor; yalnız anlatımı aktarıldı. -->

Derste `toLowerCase(metinler[0]);` ve `toUpperCase(metinler[1]);` çağrıldı (ekrandan, 02:55:00). Karışık büyük-küçük harfli girişlerle denendiğinde birinci satır tamamen küçük, ikinci satır tamamen büyük harf oldu; zaten küçük ya da büyük olan harflerde sorun çıkmadı ve diğer satırlarda veri kaybı olmadı. Bütün satırlar için aynı işlem bir `for` döngüsüyle yapılabilir.

Hoca bu sırada editörde bir yorum satırının renklendirilmesinde görsel bir hata (renklendirme bug'ı) olduğunu fark eder; derleme açısından bir sorun yoktur.

### 10.4 Tek satır yazdırmak ve satır sınırını aşmak

`listOneLineOfText` fonksiyonu verilen başlangıç adresinden itibaren yalnız bir satır (`SIZE` karakter) yazar. Beş kez çağrılarak bütün matris de yazdırılabilir. Hoca sonunda `\n` yazdırmadığı için sonraki çıktının aynı satırda devam ettiğini görür.

Hoca sonra şunu merak eder: başlangıç olarak satırın başı değil de ikinci karakteri verilse ne olur? Önce `metinler[0][1]` yazılır; bu bir karakter olduğu için derleyici parametre uyuşmazlığı bildirir. Başına `&` konunca adres verilmiş olur: `listOneLineOfText(&metinler[0][1]);`. Girişler `qwert` ve `asdfg` iken çıktı `werta` olur (ekrandan, 03:00:00). Fonksiyon 0. satırın 1. sütunundan başlayıp 5 harf yazar; 0. satırın son harfinden sonra 1. satırın ilk harfine geçer. Bu da matrisin bellekte art arda saklandığını gösterir. Hoca, fonksiyon parametresine yapılan atamayı "eşitliğin sağ tarafındaki değer parametreye atanıyor" gibi düşünmeyi önerir.

Ders bu noktada biter; pointer'larla aynı yöntemlerin nasıl yazılacağı sonraki derse kalır.

## Örnek Sorular

### Soru 1: Hangi atama geçerli?

(ekrandan, 00:20:00) Aşağıdaki satırlardan hangileri geçerlidir?

```c
char ch = 'a', *p;
*p = 'a';
p = 'a';
char *q = "a";
*q = "a";
q = "a";
```

Derste verilen cevap: `*p = 'a'` söz dizimi olarak geçerli, `p = 'a'` geçersiz (adrese karakter atanıyor); `*q = "a"` yanlış (karakter gözüne adres atanıyor), `q = "a"` geçerli. `'a'` 1 bayt, `"a"` 2 bayt yer tutar.

> **Çözüm (derste verilmedi):** gcc `-Wall` ile `p = 'a'` satırı "makes pointer from integer without a cast", `*q = "a"` satırı "makes integer from pointer without a cast" hatası verdi (ajan tarafından denendi). `*p = 'a'` derlenir ama `p` ilklendirilmediği için çalışma anında tanımsız davranıştır; önce `p = &ch;` gerekir.

### Soru 2: Alt metin arama

(ekrandan, 01:20:00 ve 01:55:00) İki string alan, ikinci stringin birincinin içinde ilk geçtiği konumu, geçmiyorsa -1 döndüren `int indexOfV1(char *ptr1, char *ptr2)` fonksiyonunu pointer işlemleriyle yazın. Aynı işi `strstr` ile yapan `indexOfV2`'yi yazın.

Çözüm derste verildi; bkz. Bölüm 6.3 ve 7.2. Örneğin `babamin` içinde `bam` 2. konumda bulunur.

### Soru 3: Hazır fonksiyon

(derste sözlü, 01:43:54) Bir öğrenci sohbetten sordu: **Soru:** Bunun kendi fonksiyonu yok mu? **Cevap:** Var, `strstr`. Bulunan yerin adresini ya da `NULL` döndürür; konum için ana stringin başlangıç adresi çıkarılır.

### Soru 4: Çok boyutlu diziyi pointer gösterimine çevirme

(ekrandan, 02:25:00 ve 02:30:00) `int ar[5][3];` için `ar[1][2]`'yi ve `char x[3][4][5];` için `x[1][2][3]`'ü yalnız pointer operatörleriyle yazın.

Derste verilen cevap: `ar[1][2]` = `*(ar[1]+2)` = `*(*(ar+1)+2)`; `x[1][2][3]` = `*(*(*(x+1)+2)+3)`.

### Soru 5: Satır sınırını aşan yazdırma

(ekrandan, 03:00:00) `char metinler[5][5]` matrisine ilk iki satır olarak `qwert` ve `asdfg` girildiğinde, bir başlangıç adresinden itibaren 5 karakter yazan `listOneLineOfText(&metinler[0][1])` çağrısı ne yazar?

Derste görülen cevap: `werta`. 0. satırın 1-4. gözleri (`w`, `e`, `r`, `t`) ve ardından bellekte hemen gelen 1. satırın ilk gözü (`a`) yazılır. Ajanın derlediği eşdeğer programda da aynı çıktı alındı.

## Dersin Toparlaması

Bu derste karakter ile string arasındaki fark atamalar üzerinden netleştirildi: tek tırnaklı karakter 1 bayt, çift tırnaklı string null karakterle birlikte daha fazla yer tutar; pointer'ın adına adres, yıldızlı hâline değer yazılır. Ardından `scanf`/`printf` ile string okuma-yazma, null karaktere kadar sayan kendi `strLen` fonksiyonu ve `string.h` içindeki `strcpy`, `strncpy`, `strcat`, `strncat`, `strcmp`, `strncmp` fonksiyonları görüldü. Dersin merkezindeki örnek, iki pointer'ı birlikte ilerletip eşleşme bozulunca doğru yere geri çeken alt metin arama algoritmasıydı; aynı iş `strstr` ile çok daha kısa yazıldı ve `malloc` sonrası null kontrolü ile `free` alışkanlığı vurgulandı.

Son bölümde çok boyutlu dizilerin pointer gösterimine en sağdaki indisten başlayarak nasıl çevrildiği, ilklendirme kuralları, pointer dizileri ve bellekte satır satır art arda saklanan karakter matrisi üzerinde tek pointer'la dolaşma örnekleri işlendi. Karakter matrisindeki işlemlerin pointer'larla nasıl yazılacağı sonraki derste devam edecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
