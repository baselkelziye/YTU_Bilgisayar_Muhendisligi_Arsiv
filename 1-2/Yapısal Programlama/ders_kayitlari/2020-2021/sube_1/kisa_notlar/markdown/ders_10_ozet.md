# Ders 10 Çalışma Özeti

## Genel Konular

- İşaretçi dizisi (array of pointers)
  - `char *ar_of_p[5];` tanımı, her biri bir `char` adresini tutacak 5 işaretçilik bir dizi oluşturur. Slayttaki bellek tablosunda dizi `0x1000` adresinden başlar ve gözler 4'er bayt arayla dizilir (`0x1000`, `0x1004`, ..., `0x1010`) (ekrandan, 00:05:00).
  - `char c0 = 'a'; char c1 = 'b';` için ayrı bellek gözleri açılır (slaytta `0x2000` ve `0x2001`).
  - `ar_of_p[0] = &c0;` ve `ar_of_p[1] = &c1;` atamalarıyla ilk iki işaretçiye `2000` ve `2001` adresleri yazılır; diğer üç göz tanımsız (undefined) kalır (ekrandan, 00:05:00).
  - İşaretçinin bir değişkeni göstermesi için işaretçinin gözüne o değişkenin adresi yazılır; bu yüzden atamada adres operatörü `&` kullanılır.
- İki boyutlu karakter dizisinin satırlarını işaretçiyle işlemek
  - `#define SIZE 5` ve `char metinler[SIZE][SIZE];` ile 5 satır, 5 sütunluk bir karakter matrisi tanımlandı; her satıra `scanf("%s", ...)` ile bir metin okundu (ekrandan, 00:15:00).
  - `listOneLineOfText(char *p)` fonksiyonu bir satırın adresini alır, `printf("%c", *p); p++;` ile karakterleri tek tek yazar (ekrandan, 00:25:00).
  - Satırı kopyalamak yerine satıra işaretçi göndermek belleği en verimli kullanan yoldur.
  - `toUpperCase` ve `toLowerCase` fonksiyonları ASCII değerleriyle çalışır: `A` = 65, `a` = 97, aradaki fark 32 (ekrandan, 00:40:00).
  - `listAllLines(char *p)` bütün matrisi tek işaretçiyle `SIZE*SIZE` adımda dolaşır; `j % SIZE == 0` olduğunda yeni satıra geçer (ekrandan, 01:25:00).
- İşaretçiyi gösteren işaretçi (pointer to pointer)
  - `int r = 5; int *q = &r; int **p = &q;` (ekrandan, 00:40:00).
  - `r = 10;` doğrudan atama, `*q = 10;` bir dolaylı atama, `**p = 10;` iki dolaylı atamadır.
  - Hoca konunun dinamik bellek ayırma örnekleriyle daha anlamlı hale geleceğini söyledi.
- Dinamik bellek yönetimi
  - Gereksinim: C'de değişken ve dizi kullanılmadan önce tanımlanmalıdır, dizinin boyutu derleme anında sabittir. Kullanıcının kaç eleman gireceği çalışma anında öğrenildiğinde bellek o anda ayrılmalıdır.
  - `void *malloc(total_size_in_bytes)`: istenen kadar bayt ayırır, bloğun başına işaretçi döndürür (ekrandan, 01:05:00).
  - `void *calloc(number_of_elements, element_size)`: malloc gibidir, ama iki parametre alır ve ayırdığı baytları sıfırlar. Toplam boyut `n * element size` olduğundan iki fonksiyonla aynı büyüklükte alan ayrılabilir.
  - `void *realloc(void *prev_ptr, total_size_in_bytes)`: daha önce ayrılmış bloğun boyutunu değiştirir. Bloğu yeni bir adrese taşıyabilir (yeni adres döndürülür). Büyütülen ek kısmın sıfırlandığı varsayılmamalıdır; önceki içerik korunur.
  - `void free(void *ptr)`: malloc, calloc ya da realloc ile ayrılmış belleği geri verir. Yalnız işaretçi alır, boyut almaz.
- Dizi için bellek ayırma (ekrandan, 01:15:00)
  - `list = (int *) malloc( n * sizeof(int) );` ya da `(int *) calloc( n, sizeof(int) );`
  - `if(list==NULL)` ise `__FILE__` ve `__LINE__` ile hata yazılır ve programdan çıkılır; iş bitince `free(list)`.
  - `sizeof` bir türün çalışılan platformda kaç bayt tuttuğunu verir; kod platformdan bağımsız olur.
  - malloc ve calloc `void *` döndürür; sonuç kullanılacak işaretçi türüne açıkça dönüştürülmelidir.
- Matris için bellek ayırma
  - Önce bütün alan ayrılır, sonra bir `for` döngüsüyle satırlara bölünür. Boşaltırken ters sırayla, önce satırlar, sonra bütün blok boşaltılır. <!-- BELİRSİZ: Matris ayırma slaytı (01:20-01:28) karelerde yok; kodun ayrıntısı görülemedi. -->
  - Genel kural: her malloc için bir karşılık gelen free bulunmalıdır; aksi halde bellek sızıntısı (memory leak) olur.
- Örnek 1: dinamik dizi ve sıralama
  - Kullanıcıdan eleman sayısı `n` alındı, `p = (int*) malloc( n * sizeof(int) );` ile yer ayrıldı, elemanlar `scanf("%d", p+i);` ile okundu (ekrandan, 01:45:00).
  - `bubbleSort(int *b, int n)` dizi gösterimiyle (`b[i]`, `b[j]`) yazıldı (ekrandan, 01:50:00).
  - Fonksiyona dizinin başlangıç adresi ile birlikte eleman sayısı da gönderilmelidir; işaretçi kaç elemanlık alan gösterdiğini tutmaz.
  - Kullanıcı bütün elemanları gireceği için burada calloc'un sıfırlaması gereksizdir; malloc daha uygundur.
- Seçmeli sıralama (selection sort) ve kabarcık sıralama karşılaştırması
  - Selection sort her turda kalan kısmın en küçüğünü seçip baştaki yerine koyar; her turdan sonra dizinin baş kısmı sıralıdır.
  - Derste yazılan sıralamada küçük değerler yukarı, büyükler aşağı doğru yavaş yavaş kayar; ara adımlarda baş kısmın sıralı olacağı garanti değildir.
  - `getPosOfMin(int *p, int n, int pos)`: `pos` konumundan başlayarak en küçük elemanın konumunu döndürür (ekrandan, 02:30:00).
  - `selectionSort(int *b, int n)` işaretçi gösterimiyle (`*(b+i)`, `*(b+minPos)`) yazıldı ve her turdan sonra `printList(b, n)` çağrıldı (ekrandan, 02:40:00).
- Örnek 2: matris çarpımı (yalnız planı yapıldı, evde yazılmak üzere bırakıldı) (ekrandan, 01:35:00)
  - Adımlar: boyutları sor, çarpılabilir mi kontrol et, yer ayır, elemanları al, çarp, sonuç matrisini yaz.
  - Çarpılabilirlik için A'nın sütun sayısı B'nin satır sayısına eşit olmalıdır.
- Metin örneğinin dinamik bellekle yeniden yazılmasına başlandı
  - Kullanıcıya kaç metin ve en fazla kaç karakter gireceği soruldu; `s = (char*) calloc(...)` ile yer ayrılacaktı (ekrandan, 02:45:00). Örnek ders bitiminde tamamlanmadı.

## Hocanın Özellikle Vurguladığı Kısımlar

- `*` ile `&` nerede kullanılır?
  - İşaretçinin gösterdiği değeri yazdırmak için `*p` yazılır. Derste `*` unutulunca anlamsız karakterler çıktı.
  - `scanf` adres ister; işaretçinin kendisi zaten adres tuttuğu için `scanf("%d", p+i)` yazılır, `*p` ya da `&p` yanlıştır.
- İşaretçiyi artırmak bir sonraki gözü gösterir
  - `p++` işaretçinin türünün boyu kadar ilerler; `int *` için genelde 4 bayt.
- Ayrılan bloğun başlangıç adresi kaybedilmemelidir
  - free yalnız başlangıç işaretçisini alır. İşaretçi ilerletilecekse başlangıç başka bir değişkende (`begin`) saklanmalıdır; ya da işaretçi hiç oynatılmadan `p+i` ile erişilmelidir.
- malloc/calloc dönüşü mutlaka NULL için kontrol edilmelidir
  - Sistemde yeterli boş bellek yoksa NULL döner; o zaman programdan çıkmak en doğrusudur.
- Tür dönüşümü (cast) kendiniz yapın
  - Derleyicinin ya da standardın otomatik dönüştürmesine güvenmeyin; C'de her şeyi kendiniz yapmanız gerekir.
- realloc'un tek garantisi eski verinin korunmasıdır
  - Yeni gelen alanda kirli (rastgele) veri olabilir; blok başka adrese taşınabilir.
- Her malloc için bir free
  - Bellek sızıntısını önlemenin genel kuralıdır.
- Fonksiyon tanımı kullanıldığı yerden önce olmalıdır
  - `printList` çağrıldığı fonksiyonlardan sonra tanımlanınca derleyici tür uyuşmazlığı uyarısı verdi; ya fonksiyon öne alınır ya da önceden prototipi (bildirimi) yazılır.
- Fonksiyonların içinde kullanılan değişkenleri fonksiyon içinde tanımlamak
  - Hoca, kullandığı değişkenleri ısrarla her fonksiyonun kendi içinde tanımladığını; böylece tanımlanmamış bir değişken kullanıldığında derleyicinin hemen hata verdiğini söyledi.

## Kısa Tekrar Notları

- `char *ar_of_p[5];` = 5 karakter işaretçisi; her gözü bir adres tutar.
- İki boyutlu dizinin bir satırı (`metinler[i]`) `char *` parametreye verilebilir; dizinin adı `metinler` doğrudan verilemedi.
- `A` = 65, `Z` = 90, `a` = 97, `z` = 122; büyük-küçük harf farkı 32.
- `int **p = &q;` işaretçiyi gösteren işaretçi; `**p = 10` iki dolaylı atama.
- malloc(bayt) / calloc(adet, boy) + sıfırlama / realloc(eski, yeni bayt) / free(ptr).
- `(int *) malloc(n * sizeof(int))`, ardından `NULL` kontrolü, iş bitince `free`.
- Matris: önce bütün blok, sonra satırlara bölme; boşaltma ters sırada.
- Sıralama fonksiyonuna adres ile birlikte eleman sayısı da gönderilir.
- Selection sort: her turda en küçüğü seç, baştaki elemanla değiştir.
- A·B çarpımı için A'nın sütun sayısı = B'nin satır sayısı.

## Detaylı Açıklamalar

- İşaretçi dizisi ve bellek tablosu
  - Derse önceki haftanın konusu olan diziler, işaretçiler ve işaretçi aritmetiğinden sonra işaretçi dizileriyle devam edildi. Slayttaki `char *ar_of_p[5];` tanımı yapıldığında `0x1000` adresinden başlayan 5 göz ayrılır; her göz bir adres tutar. Bu işaretçilerin anlamlı bir işe yaraması için bellekte bir yeri göstermeleri gerekir: en az birer karakter, daha iyisi birer karakter dizisi. `c0` ve `c1` değişkenleri `0x2000` ve `0x2001`'de durur. `ar_of_p[0] = &c0;` ataması `ar_of_p[0]` gözüne `2000` yazar; böylece işaretçi `c0`'ın simgelediği gözü gösterir (ekrandan, 00:05:00).
- Metin matrisi örneği
  - `char metinler[SIZE][SIZE];` tanımlanıp her satırına bir metin okundu. Her satırı ayrı ayrı yazdırmak için satırın kendisi kopyalanmadı, `listOneLineOfText(metinler[i])` ile satırın adresi gönderildi. Fonksiyonda önce `printf("%c", p)` yazıldığı için anlamsız karakterler çıktı; doğrusu işaretçinin gösterdiği değeri veren `*p`'dir. Bellekte matris satır satır, peşi sıra gözlerde durur; boş kalan gözlerde boş karakter (`\0`) bulunur.
  - Büyük harfe çevirmede önce aralıklar karıştırıldı; bir öğrencinin uyarısıyla küçük harflerin 97'den başladığı görüldü. Son halinde `toUpperCase` 97-123 aralığındaki karakterden 32 çıkarır, `toLowerCase` 65-91 aralığındakine 32 ekler (ekrandan, 00:35:00 ve 00:45:00).
  - `listAllLines` fonksiyonuna matrisin adı (`metinler`) verilince derleyici "incompatible pointer type" hatası verdi. Bir öğrencinin önerisiyle ilk satırın adresi (`metinler[0]`) verilince çalıştı. Hoca, dizinin adının ilk gözün adresi olduğunu konuştuklarını, ama derleyicinin iki boyutlu dizide bir satırdan başlatılmasını istediğini söyledi. <!-- BELİRSİZ: Arada denenen diğer yazımlar (adres alma vb.) altyazıdan ve karelerden tam anlaşılmıyor. -->
  - Yeni satır kontrolü (`j % SIZE == 0`) önce karakter yazdırmadan sonra konmuştu; bir öğrencinin önerisiyle döngünün başına alındı ve isimler satır satır yazıldı (ekrandan, 01:25:00).
  - Ders sonrası not: Ekrandaki aralık sınırları birer fazladır. `z` 122, `Z` 90'dır; 123 `{`, 91 `[` karakteridir. Doğru koşullar `*p <= 122` ve `*p <= 90` olmalıdır.
  - Ders sonrası not: `char metinler[5][5]` bir satırda en fazla 4 harf ve sonlandırıcı `\0` tutar. 5 harflik bir metin girilirse `\0` bir sonraki satırın ilk gözüne taşar.
- Dinamik bellek ayırma neden gerekir?
  - Önceki örnekte satır uzunluğu 5 diye sabitlendi; kullanıcı 16 karakter isterse kod değişmelidir. C'de dizi tanımı kullanıcıdan girdi alınmadan önce yapılmak zorundadır. Bu durumda çözüm, çalışma anında gerektiği kadar bellek ayırmaktır. Başka diller değişken uzunlukta tanıma izin verebilir, ama yapısal programlama dillerinin önemli bir bölümü her şeyin önce tanımlanmasını ister.
  - realloc büyütmede blok yerinde genişleyebilir ya da başka bir adrese taşınabilir; taşınırsa eski veri yeni alana kopyalanır. Programcı belleğin hangi adresten başlayacağını seçemez; derleyici ve sistem uygun boş bloğu verir.
  - free'ye kaç bayt boşaltılacağı verilmez; bu bilgi arka planda tutulur. Programcıya düşen, başlangıç işaretçisini kaybetmemektir.
- Bellek sızıntısı
  - Ayrılan alan geri verilmezse sistemden ayrılmış kalır; program tekrar tekrar çalıştırıldıkça diğer süreçlere bellek kalmaz. Matris örneğinde satır satır ayrılan alanlar önce, bütün blok sonra boşaltılır.
  - Ders sonrası not: Hoca, sızan belleğin program kapandıktan sonra bile ayrılmış kalabileceğini söyledi. Günümüz işletim sistemleri büyük olasılıkla süreç bittiğinde onun belleğini geri alır; sızıntı asıl uzun süre çalışan programlarda sorun olur.
- İşaretçi boyutu sorusu
  - Bir öğrenci `sizeof(int *)` ile `sizeof(char *)` farklı mı diye sordu; hoca evet dedi.
  - Ders sonrası not: İşaretçinin boyu gösterdiği türün boyuna bağlı değildir; aynı platformda `int *` ve `char *` büyük olasılıkla aynı boydadır (64 bit sistemlerde genelde 8 bayt). Farklı olan, işaretçinin artırıldığında kaç bayt ilerlediğidir. Ayrıca C standardına göre `sizeof(char)` her zaman 1'dir; hocanın "karakter bir platformda iki bayt olabilir" dediği durum C'de olmaz.
- Sıralama örnekleri
  - Dinamik dizi örneğinde `p` hiç ilerletilmedi; `p+i` ile erişildiği için ayrıca `begin` değişkenine gerek kalmadı. 9 sayı (11, 22, 44, 33, 55, 77, 66, 99, 88) girilip doğru okunduğu görüldü, sonra sıralandı.
  - Derste "bubble sort" diye yazılan fonksiyon `b[i]` ile ondan sonraki her `b[j]`'yi karşılaştırıp gerekirse yer değiştirir (ekrandan, 01:50:00).
  - Ders sonrası not: Klasik kabarcık sıralama yan yana elemanları (`b[j]` ve `b[j+1]`) karşılaştırır. Derste yazılan `i`-`j` karşılaştırmalı biçim, literatürde büyük olasılıkla "değiş tokuş sıralaması" (exchange sort) diye geçer. Sonuç yine doğru sıralı dizidir.
  - Selection sort derste ekranda çalıştırıldı: 34 65 12 76 43 77 87 74 37 girdisi her turdan sonra yazdırıldı ve 12 34 37 43 65 74 76 77 87 sonucuna ulaşıldı (ekrandan, 02:35:00). Kod önce dizi gösterimiyle yazıldı, düzgün çalıştığı görüldükten sonra işaretçi gösterimine çevrildi; hoca, hatanın kaynağını ayırmak için böyle ilerlediğini söyledi.
- Matris çarpımı planı
  - Hoca hangi adımlar için ayrı fonksiyon yazılması gerektiğini tartıştı: boyut alma ve bellek ayırma için gerek yok; çarpılabilirlik kontrolü, eleman alma, çarpma ve matris yazdırma için fonksiyon yazılmalı. Bellek ayırma fonksiyonu döndüreceği işaretçinin türü yüzünden işi karmaşıklaştırır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
