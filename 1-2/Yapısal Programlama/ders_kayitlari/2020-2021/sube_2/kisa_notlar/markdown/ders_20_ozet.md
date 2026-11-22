# Ders 20 Çalışma Özeti

## Genel Konular

- Bağlı liste uygulaması: çalışan (EMPLOYEE) kayıtları
  - Her düğümde `name[21]`, `surname[21]`, `id[11]` alanları ve bir sonraki düğümün adresini tutan `next` işaretçisi bulunur (ekrandan, 00:20:00).
  - Basit bir menü (1-Add, 2-Remove, 3-Exit) ile kayıt ekleme, silme ve listeleme yapılır.
  - Liste başı (`head`) global değil, `main` içinde yerel bir değişken olarak tanımlanır; fonksiyonlara adresi (`&head`) gönderilir.
- Kayıt ekleme: `createNode` ve `addRecord`
  - `createNode`, düğümü `malloc` ile heap bölgesinde oluşturur, kullanıcıdan id, ad ve soyadı okur ve düğümün adresini döndürür.
  - `addRecord(EMPLOYEE **phead)` yeni düğümü listenin başına ekler: `emp->next=*phead; *phead=emp;`.
  - Düğüm oluşturma ayrı bir fonksiyona alındığı için başa ekleme, sona ekleme, sıralı ekleme gibi farklı ekleme fonksiyonları aynı kodu tekrar yazmadan kullanabilir.
- Kayıt silme: `removeRecord`
  - Silinecek kaydın id'si okunur; `current` ve `prev` işaretçileriyle liste gezilir, karşılaştırma `strcmp` ile yapılır.
  - Silinen düğüm ilk düğümse `*phead=current->next`, değilse `prev->next=current->next` yapılır, ardından `free(current)` ile bellek serbest bırakılır.
  - Döngü, liste bitene ya da kayıt bulunana kadar (`current!=NULL && !found`) sürer.
- Fonksiyon işaretçisiyle genel yazdırma
  - `printRecords(EMPLOYEE *head, void (*fptr)(EMPLOYEE *))` listeyi baştan sona gezer ve her düğüm için kendisine verilen fonksiyonu çağırır.
  - `printfIdFirst` önce id'yi, `printfNameFirst` önce adı yazar; aynı gezinme döngüsü iki farklı biçim için kullanılır.
- Bağlı listede iki düğümün yer değiştirmesi (swap)
  - Yalnız `tmp=n1; n1=n2; n2=tmp;` yazmak bağlantıları koparır, aradaki düğümler kaybolur.
  - Doğru yöntemde iki düğümün öncülleri de tutulur; öncüllerin `next` alanları ve düğümlerin kendi `next` alanları güncellenir.
  - Alternatif olarak bağlantılara dokunmadan yalnız veri alanları kopyalanabilir (`next` hariç).
- Dosya işlemlerine giriş: I/O ve stream kavramı
  - Girdi yalnız klavyeden, çıktı yalnız ekrana olmak zorunda değildir; verinin program kapandıktan sonra da saklanması için diske yazılması gerekir.
  - C'de program ile dosya ya da aygıt arasındaki veri akışı bir stream üzerinden olur; stream'e erişim `FILE` yapısına bir işaretçiyle sağlanır.
  - Üç standart stream vardır: `stdin`, `stdout`, `stderr`. `printf` arka planda `stdout`, `scanf` ise `stdin` kullanır.
  - C kütüphane fonksiyonları tamponlu (buffered) I/O ile çalışır; disk ile işlemci arasındaki büyük hız farkı yüzünden veri bloklar halinde taşınır.
- Dosyanın yapısı ve türleri
  - Dosya bir 0-1 dizisidir; bu dizinin yerleşimine anlam verilince özel amaçlı bir dosya oluşur.
  - Dosyada genellikle header (tür, boyut, format bilgisi), data ve isteğe bağlı footer bölümleri bulunur.
  - Text dosyalar satırlardan oluşur ve açık metin olarak okunabilir; binary dosyalar ise ancak formatını bilen bir programla anlamlandırılabilir.
- Erişim türleri ve dosya operasyonları
  - Sıralı erişimde (sequential access) okuma baştan başlar; bit, byte, formatlı veri, satır ya da blok okunur ve konum göstergesi okunan miktar kadar ilerler.
  - Rastgele erişimde (random access) konum göstergesi aradaki veriyi okumadan istenen yere taşınabilir.
  - Temel operasyonlar: oluşturma, silme, yeniden adlandırma, okuma ve yazma (sıfırdan yazma, güncelleme, sona ekleme).
- C'de dosya açma ve okuma/yazma fonksiyonları
  - `fopen(dosya_adi, mod)` bir `FILE *` döndürür; hata durumunda `NULL` döner.
  - Modlar: `r`, `w`, `a`, `r+`, `w+`, `a+`; binary dosyalar için sonlarına `b` eklenir (ekrandan, 02:25:00).
  - Karakter: `getc/putc`, `fgetc/fputc`; satır: `fgets/fputs`; blok: `fread/fwrite`; konum: `fseek`, `ftell`, `rewind`; kapatma: `fclose`.

## Hocanın Özellikle Vurguladığı Kısımlar

- Global değişken kullanmayın
  - Liste başı gibi değişkenler global yapılmamalı, parametre olarak aktarılmalıdır.
- İşaretçi değişkenler veri değil adres saklar
  - `int *p` tanımlayıp `p=6` gibi bir atama yapmak, p'nin 6 numaralı adresi göstermesi anlamına gelir.
- Fonksiyon içinde `head` değişecekse çift işaretçi gerekir
  - `void` bir fonksiyonda liste başının güncellenmesi ancak `head`'in adresinin (`EMPLOYEE **`) gönderilmesiyle mümkündür. Diğer yol, yeni başı `return` ile döndürüp çağıran yerde atamaktır.
- Liste gezilirken `head` değil geçici bir işaretçi ilerletilir
  - Silme ve yazdırmada `current`/`tmp` kullanılır ki liste başı kaybolmasın.
- Dosya, yazıldığı gibi okunur; istendiği gibi yazılır
  - Okuyucu, dosyayı yazanın koyduğu formata (header alanları, sıralama, ayraçlar) uymak zorundadır.
  - Dosya formatı tasarlanırken okuma, yazma ve güncellemenin kolay olması, az yer kaplaması gibi performans ölçütleri göz önüne alınmalıdır.
- `w` modu tehlikelidir
  - Var olan dosya `w` ve `w+` ile açılınca içi tamamen boşaltılır; bu modda açmadan önce dosyayı yedekleyin.
- Okuma birimini ihtiyaca göre seçin
  - Byte gerekiyorsa bit bit, blok gerekiyorsa karakter karakter okumak gereksiz disk erişimi demektir; tersi de gereksiz iştir.
- İşi biten dosya kapatılmalıdır
  - Aynı anda açık tutulabilecek dosya sayısı sınırlıdır ve stream'ler karışırsa dosya içeriği bozulabilir.

## Kısa Tekrar Notları

- Bağlı listede düğüm heap'te (`malloc`) oluşturulur; yığındaki yerel bir değişken fonksiyon bitince yok olur.
- Başa ekleme: `emp->next=*phead; *phead=emp;`.
- Silme: ilk düğümse `*phead=current->next`, değilse `prev->next=current->next`; sonra `free(current)`.
- Fonksiyon işaretçisi parametresi: `void (*fptr)(EMPLOYEE *)`; çağırma `fptr(tmp)`.
- Yazdırma döngüsünün koşulu ilerletilen işaretçiye göre olmalı: `while(tmp!=NULL)`.
- `FILE *fp = fopen("ad", "mod");` başarısızsa `NULL`.
- `r`: var olan dosyayı okumak için, konum başta. `w`: yeni dosya, varsa içi silinir. `a`: yazma her zaman sona. `r+`: okuma ve yazma, konum başta. `w+`: okuma ve yazma, içi silinir. `a+`: okuma her yerde, yazma sonda.
- `fgets(s, n, fp)` en çok `n-1` karakter okur ve sonuna `'\0'` koyar; dosya sonunda `NULL` döndürür.
- `fread/fwrite(ptr, boyut, adet, fp)` okunan/yazılan eleman sayısını döndürür; `ptr` bir `void *`'dır.
- `fseek(fp, offset, whence)`; `whence`: `SEEK_SET`, `SEEK_CUR`, `SEEK_END`. Başarılıysa 0 döner. `ftell` geçerli konumu verir.
- Konumlar 0'dan başlar: `fseek(fp, 10, SEEK_SET)` 11. karakterin üzerine gelir.
- `#define SQR(x) x*x` ile `SQR(4+3)` 49 değil 19 verir.

## Detaylı Açıklamalar

- Bağlı liste örneğinde `EMPLOYEE` yapısı `typedef struct Employee {...} EMPLOYEE;` biçiminde tanımlandı. `main` içinde `EMPLOYEE *head=NULL;` ile boş bir liste başlatıldı ve `while(choice!=3)` döngüsünde menü gösterildi. Ekleme seçilince `addRecord(&head); printRecords(head,printfIdFirst);`, silme seçilince `removeRecord(&head); printRecords(head,printfNameFirst);` çağrıldı (ekrandan, 00:50:00).
- Hoca ekleme adımını adres değerleriyle çizdi: `head` 100 numaralı adreste duruyor ve başta `NULL` gösteriyor; fonksiyona gelen `phead` bu 100 değerini taşıyor. `malloc` ile 300 numaralı adreste yeni düğüm açılıyor; `emp->next=*phead` ile yeni düğümün `next`'i eski başı (`NULL`), `*phead=emp` ile `head` 300'ü gösteriyor. İkinci eklemede 500 numaralı düğüm açılıyor, `next`'i 300'ü gösteriyor ve `head` 500 oluyor. Her yeni kayıt listenin başına eklenir.
- Silmede hoca üç düğümlü bir liste üzerinden iki durumu izledi. Aranan kayıt ilk düğümdeyse `prev` hâlâ `NULL`'dır ve `*phead=current->next` ile baş bir sonraki düğüme kaydırılır. Aranan kayıt aradaysa önce `prev=current; current=current->next;` ile ilerlenir, bulununca `prev->next=current->next` ile düğüm zincirden çıkarılır. İki durumda da sonra `free(current)` yapılır.
- `printRecords` ilk yazıldığında döngü koşulu `while(head!=NULL)` olarak yazılmıştı. İlerletilen işaretçi `tmp` olduğu için `head` hiç `NULL` olmaz; `tmp` `NULL` olunca `fptr(NULL)` çağrılır ve program segmentation fault verir. Hata derste bir öğrencinin uyarısıyla bulundu ve koşul `while(tmp!=NULL)` yapılınca program doğru çalıştı. Ekleme ve silme senaryosu (a, b, c ekle; a'yı sil; d ekle; c'yi sil; aa ekle; b'yi sil) programın beklendiği gibi çalıştığını gösterdi.
- Ders sonrası not: Hoca ekleme sırasında listede "dairesel (circular) bir durum var gibi" dedi. Bu kodda liste dairesel değildir: ilk eklenen düğümün `next`'i başlangıçtaki `NULL` değerini alır ve listenin sonu `NULL` ile biter.
- Ders sonrası not: Kodda `scanf("%s %s %s",&emp->id,&emp->name,&emp->surname)` yazıldı. Dizi adı zaten adres olduğu için `%s` ile `&` kullanılmamalıdır (`emp->id`). `&` ile yazıldığında adres değeri aynı olduğu için program çalışır, ancak tür yanlıştır ve `gcc -Wall` uyarı verir. Kod, `&` olmadan `gcc -Wall` ile uyarısız derlendi ve derste girilen ekleme/silme senaryosuyla denendi.
- Swap anlatımında düğümlerin adresleri 0, 1, 2, 3, 4 diye numaralandı ve 2 ile 4 numaralı düğümler (n1, n2) yer değiştirilmek istendi. Yalnız üç satırlık takas yapıldığında 1'den sonra doğrudan 4'e geçiliyor, aradaki düğümler kayboluyor. Bu yüzden önce n1'in ve n2'nin öncülleri (`tmpPrevN1`, `tmpPrevN2`) saklanmalı, takastan sonra öncüllerin `next`'leri yeni düğümlere bağlanmalıdır. Kitaplarda sık görülen diğer yol, bağlantılara dokunmadan düğümlerin veri alanlarını `memcpy` ile kopyalamaktır; bu durumda `next` alanı kopyalanmamalıdır. Hoca, çok büyük sayıların bağlı listelerle saklanıp toplanmasını da bu tür problemlere örnek verdi.
- Dosyalara geçişte hoca, sabit diskin dakikada 7200 devirle (saniyede 120 tur) döndüğünü, işlemcinin ise GHz mertebesinde ($10^9$) çalıştığını hatırlattı. Bu hız farkı yüzünden her okumada diske gidilmez; tampon (buffer) kullanılarak bloklar halinde okuma ve yazma yapılır.
- Bir `.c` dosyası Notepad++'da açık metin olarak okunabilirken bir `.ppt` dosyası anlamsız karakterler gösterir. Bunun nedeni binary dosyanın kendi formatına göre kodlanmış olmasıdır. İşletim sistemi dosyayı hangi programın açacağını (varsayılan uygulama) bilir; asıl çözümü o program yapar.
- Hoca bir dosyayı header, data ve footer olarak üçe ayırdı. Header'da dosyanın türü, boyutu ve formatı gibi bilgiler bulunur; örneğin bir görüntü açılırken bellekte ne kadar yer ayrılacağı ve piksellerin RGB değerlerinin hangi sırayla geleceği buradan öğrenilir. Bir BMP dosyasının header'ında da ilk alanlar dosya türü ve boyutudur; ardından genişlik, yükseklik, renk sayısı gibi bilgiler gelir. CSV (virgülle ayrılmış değerler) örneğinde ise satırdaki ilk alanın ad, ikincisinin soyad, üçüncüsünün id olacağı bir kural konmuştur.
- "Dosya nasıl okunur?" sorusunun cevabı "yazıldığı gibi" oldu. Hoca bunu protein sentezine benzetti: başlatıcı kodon görülünce sentez başlar, sonra her üç baz bir amino asite karşılık gelir ve bitirici kodonla sentez durur. Dosya okuyucu da 0-1 dizisini dosyayı yazanın kuralına göre parça parça anlamlandırır. "Dosya nasıl yazılır?" sorusunun cevabı "istendiği gibi" oldu; mühendis olarak istenen şey okuma, yazma ve güncellemenin kolay, formatın sade ve yer kullanımının verimli olmasıdır. Bu konunun ayrıntısı dosya organizasyonu dersinde (B-ağaçları, 2-3-4 ağaçları, sıkıştırma) işlenir.
- `fopen` modları için slayttaki tablo (ekrandan, 02:25:00): `r` var olan bir text dosyayı okumak için açar, okuma dosyanın başından başlar. `w` yazmak için yeni bir text dosya oluşturur; dosya varsa uzunluğu sıfıra indirilir. `a` var olan dosyayı ekleme modunda açar; konum göstergesi başka yere taşınsa bile yazma dosyanın sonuna yapılır. `r+` var olan dosyayı okuma ve yazma için açar, konum başta olur. `w+` okuma ve yazma için yeni dosya oluşturur, varsa içi silinir. `a+` var olan dosyayı açar ya da yoksa oluşturur; okuma her yerden yapılabilir, yazma yalnız dosya sonuna yapılır. Binary modlarda adın sonuna `b` eklenir (`"rb"`).
- Okuma ve yazma arasında geçişte kural (ekrandan, 02:30:00): bir stream'den okuduktan sonra araya `fseek()`, `rewind()` ya da `fflush()` çağrısı koymadan yazılamaz; yazmadan okumaya geçişte de aynı kural geçerlidir.
- Karakter karakter kopyalama örneğinde iki dosya açılır (biri okuma, biri yazma için, binary modda); ikincisi açılamazsa ilki de kapatılır. Ardından `while(!feof(fp1)) putc(getc(fp1), fp2);` döngüsüyle dosya kopyalanır ve iki dosya `fclose` ile kapatılır. Slayta göre binary modda `getc`'nin dönüş değerini `EOF` ile karşılaştırmak yerine `feof()` kullanılmalıdır (ekrandan, 02:35:00). <!-- BELİRSİZ: Kopyalama örneğinin tam kodu kareye düşmedi; döngü altyazıdaki anlatımdan kuruldu. -->
- Ders sonrası not: `getc` `int` döndürür ve `EOF` (-1) hiçbir byte değeriyle (0-255) çakışmaz; sonuç `int` bir değişkende tutulduğu sürece `while((c=getc(fp1))!=EOF) putc(c,fp2);` binary dosyada da doğru çalışır. Sorun, sonucun `char`'a atanmasında ortaya çıkar. Ayrıca `while(!feof(fp1)) putc(getc(fp1),fp2);` döngüsü dosya sonuna gelindiğini ancak başarısız bir okumadan sonra anladığı için hedef dosyaya fazladan bir byte yazar: 3 byte'lık bir dosya bu döngüyle 4 byte olarak kopyalandı (`gcc -Wall` ile derlenip denendi). Slayttaki örnek döngüde (`while ((c = getc(fp1)) != EOF) putc(getc(fp1), fp2);`) her turda iki karakter okunduğu için karakterlerin yarısı da atlanır.
- `getc/putc` makro olarak, `fgetc/fputc` fonksiyon olarak tanımlanır; makrolar daha hızlıdır ama argümanlar yan etkili ya da operatörlü olursa beklenmedik sonuç verebilir. Hoca bunu `#define SQR(x) x*x` örneğiyle gösterdi: `SQR(4+3)` ifadesi `4+3*4+3` olarak açılır ve 19 verir (derlenip denendi).
- `fgets` prototipi slaytta `char *fgets(char *s, int n, FILE stream);` diye verildi (ekrandan, 02:40:00); doğrusu `FILE *stream`'dir. `fgets` yeni satıra, dosya sonuna ya da en fazla karakter sayısına ulaşınca durur ve okunan son karakterden sonra otomatik olarak `'\0'` ekler; bu yüzden `n`, dizi boyutundan bir eksik verilir. `fgets` okuduğu yeni satır karakterini de diziye alır. `fputs` simetrik fonksiyondur ve boyut almaz.
- Blok I/O'da `fread(ptr, size, n, fp)` kullanılır; `ptr` `void *` olduğu için okunacak blok karakter dizisi, `int` dizisi ya da struct olabilir, boyut genellikle `sizeof` ile verilir. Tampon boyutu 1024 byte, okunan blok 512 byte ise işletim sistemi diskten 1024 byte getirir; ilk 512 byte bu `fread`'e verilir, sonraki `fread` diske gitmeden kalan 512 byte'ı bellekten alır (ekrandan, 02:45:00).
- `fseek(FILE *stream, long int offset, int whence)` konum göstergesini taşır (ekrandan, 02:50:00). Binary dosyalarda offset byte sayısıdır; text dosyalarda 0 ya da `ftell`'in döndürdüğü bir değer olmalıdır. `SEEK_END` ile offset sıfır ya da negatif, `SEEK_SET` ile sıfır ya da pozitif olmalıdır.
- Rastgele erişim örneğinde kişi kayıtları (ad, kimlik numarası, doğum tarihi) bir dosyada tutulur. Kayıtların tamamını fiziksel olarak sıralamak yerine yalnız ad (anahtar) ve kayıt sırası (indeks) çiftleri belleğe okunur ve bunlar sıralanır (ekrandan, 02:55:00). `get_records` fonksiyonu her kaydın ilk `NAME_LEN` karakterini `fread` ile okur, `offset += sizeof(PERSONALSTAT)` ve `fseek(data_file, offset, SEEK_SET)` ile bir sonraki kaydın başına atlar (ekrandan, 03:00:00). Sıralama `qsort` ve bir karşılaştırma fonksiyonuyla yapılır; slayttaki örnek sıralanmış kayıtları yalnız ekrana yazdırır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
