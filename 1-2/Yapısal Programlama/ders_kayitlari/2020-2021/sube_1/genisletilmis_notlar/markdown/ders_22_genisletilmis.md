# Ders 22 Genişletilmiş Notu: Dosya İşlemleri: Açma Kipleri ve Karakter, Satır, Blok Düzeyinde Kopyalama

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

<!-- Kayıt iki parçadır. Ders saatine göre önce ikinci parça (altyazıda 01:02:56 sonrası: kuram ve ilk örnek), sonra birinci parça (altyazıda 00:00:00-01:02:08: örneklerin devamı) gelir. Not ders akışına göre sıralanmıştır; zaman damgaları altyazı dosyasındaki damgalardır. -->

## İçindekiler

- 1. Dosya Konusuna Giriş
- 2. Akışlar ve FILE Yapısı
- 3. stdio.h Başlık Dosyası
- 4. Dosya Açma: fopen ve Erişim Kipleri
- 5. fopen Dönüş Değeri, fprintf ve fscanf
- 6. Üç Veri Boyutunda Giriş/Çıkış
- 7. Okuma ile Yazma Arasında Geçiş
- 8. Dosya Kapatma: fclose
- 9. Örnek 1: İkili Kipte Karakter Karakter Kopyalama
- 10. Dosya Sonunu Doğru Denetlemek
- 11. Örnek 1'in Çalıştırılması: Metin ve PDF
- 12. getc ile fgetc Karşılaştırması
- 13. Örnek 2: Metin Kipinde Satır Satır Kopyalama
- 14. Blok Düzeyinde Giriş/Çıkış: fread ve fwrite
- 15. Örnek 3: İkili Kipte Blok Blok Kopyalama
- 16. Son Eksik Blok Neden Ayrıca Yazılır?
- Örnek Sorular
- Dersin Toparlaması

## 1. Dosya Konusuna Giriş

Dersin kalanında yalnız dosya konusu kaldığı için, hoca bu konuyu iki derse bölmeye karar verdiğini söyledi. Önceki derste dosya altyapısının neden karmaşık olduğundan bahsedilmişti. C kütüphaneleri ve C standartları bu karmaşıklığı programcıdan soyutlamaya çalışır. Hocaya göre, gizlemeye çalıştığı karmaşıklık ve döneminin koşulları düşünülürse bu iyi bir iştir. Ancak çeşitli yan etkiler vardır. Bu yüzden derste farklı dosya erişim kipleri ve bu kiplerde hangi tür verinin ne kadar düzgün işlenip kaydedilebildiği ve geri yüklenebildiği uygulamalarla birlikte görüldü.

Hoca anlatım tarzını da açıkladı: önce bütün kuramı anlatır, sonra uygulamalar sırasında kuramı yeniden hatırlatır.

## 2. Akışlar ve FILE Yapısı

Dosya işlemleri, `stdio.h` kütüphanesindeki `FILE` yapısıyla yapılır. `FILE` aslında bir `struct`'tır. Programcı bir `FILE` işaretçisi tanımlar ve bu işaretçiyi çeşitli giriş/çıkış fonksiyonlarına verir. Karmaşıklığın çoğunu bu işaretçi gizler; yapının iç düzenini bilmek gerekmez. Bilinmesi ve verilmesi gereken bilgiler şunlardır:

- Dosyanın adı ve bulunduğu dizin.
- Erişim biçimi: kabaca okuma ya da yazma (ayrıntıları aşağıda).
- Dosyayı temsil eden işaretçi.

C dosyayı bir akış (stream), yani bir bayt dizisi olarak ele alır. Akış daha genel bir kavramdır: örneğin bir ağ bağlantısı üzerinden de giriş/çıkış yapılabilir. Derste dosya giriş/çıkışına odaklanıldı, bu yüzden akış kısaca "dosya" diye anıldı.

Slayttaki maddeler şunlardır (ekrandan, 01:10:00):

- Programda tanımlanması gereken dosya işaretçisi, `fopen()` fonksiyonunun döndürdüğü akış tanıtıcısını tutar. C'de her şey kullanılmadan önce tanımlanmalıdır.
- Dosya işaretçisi akıştan okumak, akışa yazmak ve akışı kapatmak için kullanılır.
- Bir program aynı anda birden çok akış açabilir, ama her gerçekleme eşzamanlı akış sayısına bir sınır koyar. Hoca kuramda sınırsız olduğunu, pratikte ise işletim sisteminin bir kullanıcıya izin verdiği sayıyla sınırlı olduğunu söyledi. Bu sınır daha çok eski çok kullanıcılı ana bilgisayar (mainframe) sistemlerinde önemliydi. Ders örneklerinde en fazla iki ya da üç dosya (örneğin iki dosyayı üçüncüde birleştirme) kullanılır.
- Her `FILE` yapısının alanlarından biri dosya konum göstergesidir (file position indicator). Bir sonraki karakterin okunacağı ya da yazılacağı baytı gösterir.
- Dosyadan okundukça ya da dosyaya yazıldıkça, işletim sistemi konum göstergesini bir sonraki bayta ilerletir. Bunu programcı değil, sistem yapar. Programcıya düşen, belli bir mantık içinde okumaya ya da yazmaya devam etmektir.

Konum göstergesine doğrudan erişilemez. Bazı erişim yöntemleri vardır, ama farklı C standartlarında ve işletim sistemlerinde farklı çalıştıkları için taşınabilir değildir. Rastgele erişime yönelik bir örnek ileride görülecektir.

Karıştırılmaması gereken nokta şudur: dosya işaretçisi ile dosyanın hangi konumunda olunduğu farklı şeylerdir. Bütün işlemler işaretçi üzerinden yapılır. Konum bilgisiyle çoğu zaman uğraşmak gerekmez; işlemler konum bilgisi elde edilmeden de yapılabilir. İşaretçi akışın kendisini, konum göstergesi akışın hangi noktasında olunduğunu ifade eder.

## 3. stdio.h Başlık Dosyası

`printf` ve `scanf` için kullanılan standart giriş/çıkış kütüphanesi dosya işlemleri için de kullanılır ve mutlaka eklenmelidir. Slayta göre `stdio.h` şunları içerir (ekrandan, 01:15:00):

- Bütün giriş/çıkış fonksiyonlarının prototip bildirimleri.
- `FILE` yapısının bildirimi.
- Bazı kullanışlı makro sabitler: `stdin`, `stdout`, `stderr`, `EOF` ve `NULL`.

`stdin`, `stdout` ve `stderr` standart akışlardır. Önceki derste konuşulduğu gibi, varsayılan giriş kanalı (`stdin`) klavye, varsayılan çıkış kanalı (`stdout`) ekrandır. `stderr`, yalnız hata durumunda çıktıyı ayrı bir yere göndermek için kullanılır. Varsayılan olarak o da `stdout` gibi ekranı, yani komut satırını gösterir. Bunlar yönlendirilebilir, ama derste bunun örneği yapılmadı.

`EOF`, "end of file" sözcüklerinin baş harfleridir. Slayttaki tanıma göre sistem dosya sonu işaretine ulaştığında birçok fonksiyonun döndürdüğü değerdir. Bir dosyanın tamamı okunacaksa okuma dosya sonuna kadar sürer; bu yüzden `EOF` kullanılır.

`NULL` boş işaretçinin adıdır. Slayta göre `stddef.h` başlık dosyasında da tanımlanabilir; `NULL` kullanmak için `stdio.h` ya da `stddef.h` eklenmelidir. Daha önce bağlı listelerde listenin son düğümünün `next` alanı için kullanılmıştı. Dosya işlemlerinde de kullanılacaktır.

## 4. Dosya Açma: fopen ve Erişim Kipleri

Bir dosyada okuma ya da yazma yapmadan önce, dosya `fopen` fonksiyonuyla açılıp bir dosya işaretçisi elde edilmelidir. `fopen` iki argüman alır: birincisi dosya, ikincisi erişim biçimi (kip). Erişim kipleri temelde iki gruba ayrılır: metin dosyaları için ve ikili (binary) erişilecek dosyalar için. Her grubun alt kipleri vardır.

Slaytın sağındaki tabloda metin akışlarının kipleri verilir (ekrandan, 01:20:00):

| Kip | Anlamı |
|---|---|
| `"r"` | Var olan metin dosyasını okumak için açar. Okuma dosyanın başından başlar. |
| `"w"` | Yazmak için yeni bir metin dosyası oluşturur. Dosya zaten varsa sıfır uzunluğa indirilir. Konum göstergesi başlangıçta dosyanın başındadır. |
| `"a"` | Var olan metin dosyasını ekleme (append) kipinde açar. Yalnız dosya sonuna yazılabilir. Konum göstergesi açıkça taşınsa bile yazma yine dosya sonunda olur. |
| `"r+"` | Var olan metin dosyasını okuma ve yazma için açar. Konum göstergesi başlangıçta dosyanın başındadır. |
| `"w+"` | Okuma ve yazma için yeni bir metin dosyası oluşturur. Dosya zaten varsa sıfır uzunluğa indirilir. |
| `"a+"` | Var olan dosyayı açar ya da yenisini oluşturur, ekleme kipinde. Dosyanın her yerinden veri okunabilir, ama yalnız dosya sonuna yazılabilir. |

Hoca kipleri şöyle açıkladı. `r` ile açılan metin dosyasından okuma dosyanın başından başlar. Yazma yapılacaksa ve metin kipi isteniyorsa `w` kullanılır. Verilen adla o konumda zaten bir dosya varsa `w` onu siler ve sıfırdan yazmaya başlar. Dosyanın sonuna ekleyerek yazmak isteniyorsa `a` (append) kullanılır. `a` ile açıldığında konum göstergesi dosya sonuna yönlendirilir ve yapılan bütün yazmalar sona ekleme biçiminde olur. Programcı kod yazarak konum göstergesini başa taşımaya çalışsa bile bu yapılamaz. Kip bunu dayatır: "append mi, o zaman yalnız sona ekleyeceksin" ya da "w mi, o zaman hepsini silip sıfırdan başlıyorum".

Bunun sonucunu gösteren bir örnek verildi. Bir dosyada yalnız ilk üç kayda ihtiyaç var, sonraki kayıtlar silinip yerlerine yeni kayıtlar yazılacak. Bu iş için ne `w` ne `a` doğrudan kullanılabilir. Yapılması gereken şudur:

1. Dosya okuma amacıyla açılır.
2. Saklanmak istenen üç kayıt okunup bellekte tutulur.
3. Dosya kapatılır.
4. Dosya bu kez `w` ile açılır, önce saklanan üç kayıt, ardından yeni kayıtlar yazılır.

Bir dosya hem okuma hem yazma için de açılabilir. Bunun için `+` kipleri kullanılır. `r+` ile açılırsa konum göstergesi dosyanın başına gelir ve hem okuma hem yazma yapılabilir. `w+` ile açılırsa mevcut dosya önce sıfırlanır, sonra okuma ve yazma yapılabilir. `a+` ile hem mevcut dosya açılabilir hem yeni dosya oluşturulabilir. Yeni dosya zaten boştur; mevcut dosya açıldıysa `w`'nin aksine içerik silinmez, konum dosyanın sonuna taşınır.

> **Ders sonrası not:** Hoca `a+` kipinde de `a`'daki gibi geriye gidilemeyeceğini söyledi. Slayttaki tabloya göre `a+` kipinde dosyanın her yerinden okunabilir; geriye gidilememe kısıtı yalnız yazma için geçerlidir, yazma her zaman dosya sonuna yapılır (ekrandan, 01:20:00).

Bu altı kipin hepsi metin dosyaları içindir. Dosya ikili kipte açılmak isteniyorsa kipin sonuna `b` eklenir: `rb`, `wb`, `ab`, `rb+`, `wb+`, `ab+`. Slayttaki örneğe göre ikili bir dosyayı okuma erişimiyle açmak için `"rb"` kullanılır. Hoca `+` kiplerinin ikili sürümünün `w+b` biçiminde değil `wb+` biçiminde yazılması gerektiğini söyledi ve slayta bununla ilgili not düşmek istedi. <!-- BELİRSİZ: Altyazıda bu cümle bozuk ("V6B şeklinde değil de VB artı şeklinde"); hocanın kastı büyük olasılıkla "w+b değil wb+". -->

> **Ders sonrası not:** C standardına göre `r+b`/`rb+`, `w+b`/`wb+` ve `a+b`/`ab+` yazımlarının ikisi de geçerlidir ve aynı anlama gelir.

**Soru:** Dosya ikili kipte açılınca `fscanf` ile okuma biçimi değişiyor mu, yoksa derleyici bu işi kendisi mi hallediyor? **Cevap:** Değişmiyor. Dosyanın `r` ya da `rb` ile açılması `fscanf` ile yapılan işi değiştirmez; derleyici bu işi halleder. Ancak bazı açma kipleriyle bazı veri biçimleri arasında uyumsuzluklar olacaktır; bu da örneklerde görülecek.

Hoca kip kurallarını bir tablo biçiminde de özetledi:

- `r` ya da `r+` ile açılacak dosya önceden var olmalıdır. Yoksa `fopen` `NULL` döndürür ve o işaretçi üzerinden başka işlem yapılamaz.
- `w` ya da `w+` ile açılırsa mevcut dosyanın içeriği boşaltılır.
- `r`, `r+`, `w+` ya da `a+` ile açılırsa dosyadan okuma yapılabilir.
- `r` dışındaki herhangi bir kipte yazma yapılabilir.
- `a` ya da `a+` ile açılırsa yalnız dosya sonundan itibaren yazılabilir.

## 5. fopen Dönüş Değeri, fprintf ve fscanf

Slayttaki maddeler şunlardır (ekrandan, 01:25:00):

- `fopen()`, programın ilerisinde dosyaya erişmek için kullanılan `FILE` türünden bir dosya işaretçisi döndürür.
- Hata olursa `fopen()` boş işaretçi (`NULL`) döndürür.
- Başarılı olursa `fopen()` sıfırdan farklı bir dosya işaretçisi döndürür.
- `fprintf()` tam olarak `printf()` gibidir; tek farkı, çıktının hangi akışa gönderileceğini gösteren ek bir argüman almasıdır.

Bu yüzden `fopen`'ın başarılı olup olmadığını sınamak için, herhangi bir okuma ya da yazmadan önce dönen işaretçinin `NULL` olup olmadığına bakılmalıdır.

> **Hocanın vurgusu:** `fopen`'dan sonra `NULL` kontrolü yapılmazsa program düzgün sonlanmaz. Kontrol yapılmalı, dosyaya ulaşılamıyorsa bu bildirilip programdan düzgün biçimde çıkılmalıdır.

Dosyaya yazmak için `fprintf`, dosyadan okumak için `fscanf` kullanılır. Sözdizimleri hemen hemen aynıdır: parametre listesi ve biçim katarı (format string) aynıdır. `printf` ile `fprintf` (ya da `scanf` ile `fscanf`) arasındaki tek fark, fonksiyonun hangi akışla çalışacağını bilmesi gerektiğidir. Bu yüzden fazladan bir dosya işaretçisi alırlar; bunun dışında tamamen aynı çalışırlar.

## 6. Üç Veri Boyutunda Giriş/Çıkış

Dosya açıldıktan sonra, hangi kipte (`r`, `w`, `a` ve `+`'lı türevleri) açıldığına göre okuma ve yazma yapılır. Giriş/çıkış işlemleri üç farklı veri boyutunda yapılabilir:

- **Karakter (bayt) düzeyi:** Tek karakter ya da tek bayt okumak/yazmak için `getc` ve `putc` (ve `fgetc`, `fputc`) fonksiyonları vardır.
- **Satır düzeyi:** Dosya bir metin dosyasıysa satır satır okumak için `fgets` ve `fputs` vardır. İkili dosyalarda bunun anlamı yoktur. `fgets` "get string from file", `fputs` "put string to file" anlamındadır.
- **Blok düzeyi:** Blok blok okumak için `fread` ve `fwrite` vardır. Programcı dosyadan hangi boyda veri çekecekse blok boyutunu ona göre ayarlar.

Bunların aralarında üstünlükler ve eksiklikler vardır; derste hepsinin örneği görüldü.

## 7. Okuma ile Yazma Arasında Geçiş

Bütün giriş/çıkış düzeylerini kapsayan ortak bir kural vardır. Bir akıştan okumadan yazmaya ya da yazmadan okumaya geçerken araya `fseek`, `rewind` ya da `fflush` fonksiyonlarından biri girmelidir. `fseek` dosya konum göstergesini belli bir yere götürür. `fflush` ise, dosyaya okuma ya da yazma işlemi henüz işletim sisteminin giriş/çıkış kuyruğunda bekliyorsa, o işin hemen yapılmasını zorlayan bir çağrıdır.

Hoca bunu şöyle açıkladı. Dosya yalnız `r` ile açıldıysa, açıkken yazma kipine geçilemez. Önce bir `fflush` yapılır, sonra dosya kapatılır, ardından öbür kipte (örneğin `w`) açılır. `r+` ya da `w+` ile açıldıysa ve bir okumadan sonra yazma yapılacaksa, önce `fflush` ile kuyrukta bekleyen işlerin yapılması zorlanır, sonra devam edilir.

> **Ders sonrası not:** Standarda göre `+` kiplerinde yazmadan okumaya geçerken araya `fflush` ya da bir konumlandırma çağrısı (`fseek`, `fsetpos`, `rewind`), okumadan yazmaya geçerken ise bir konumlandırma çağrısı girmelidir. Yalnız okumak için açılmış (giriş) bir akışa `fflush` uygulamak standartta tanımsız davranıştır.

Bellek sıkıntısı yoksa, giriş akışından okunanın tamamı bellekte tutulup çıkış akışına yazılabilir. Derste gigabaytlarca büyüklükte dosyalarla çalışılmayacağı için bu sorun olmaz.

Giriş ve çıkış akışları aynı dosyayı gösterebilir. Bu, yukarıdaki kuralın başka bir anlatımıdır: okuduktan sonra yazmadan önce (ya da tersi) dosya önce kapatılmalı, sonra diğer işe geçilmelidir.

## 8. Dosya Kapatma: fclose

Dosyayla iş bitince `fclose` fonksiyonu çağrılır. Parametre olarak dosya işaretçisini alır ve dosyanın kapanmasını sağlar. Slayttaki maddeler şunlardır (ekrandan, 01:30:00):

- Dosyayı kapatmak için `fclose()` kullanılır: `fclose( fp );`
- Dosyayı kapatmak, `fp`'nin gösterdiği `FILE` yapısını serbest bırakır; böylece işletim sistemi yapıyı başka bir dosya için kullanabilir.
- Ayrıca akışa bağlı tamponları boşaltır (flush).
- Çoğu işletim sisteminde aynı anda açık olabilecek akış sayısı sınırlıdır; bu yüzden işi biten dosyaları kapatmak iyi bir fikirdir.
- Program normal biçimde sonlandığında açık akışların hepsi kendiliğinden kapanır.
- Çoğu işletim sistemi, program anormal biçimde sonlansa bile açık dosyaları kapatır, ama bu davranışa güvenilemez.

> **Hocanın vurgusu:** `malloc` ile ayrılan bütün bellek nasıl `free` ile geri verilmeliyse, açılan bir dosya da kapatılmalıdır. Hoca, C'deki deneyimine göre yazma işlemi yapılıp dosya kapatılmadan programdan çıkılırsa dosyanın erişilemez hale gelebildiğini söyledi. Okuma için açılan dosya kapatılmadan program bitse bir şey olmayabilir, ama hoca kodlarda dosya erişimi bitince `fclose` görmek istediğini söyledi.

Dosya kapatılınca ilgili `FILE` yapısı bellekten kendiliğinden silinir. Bu yüzden sonunda dosya işaretçisini `free` etmek gerekmez. `fclose` aynı zamanda `fflush`'ın işini de yapar; ayrıca `fflush` çağırıp sonra kapatmaya gerek yoktur, yalnız `fclose` yeterlidir. Aynı anda açık dosya sayısının sınırlı olması da kaynakları verimli kullanmak için işi biten dosyanın kapatılmasının bir başka nedenidir.

Program `exit(0)` ile kapanınca açık akışlar kapanır, ama buna güvenilmemelidir. Hoca, ilk yazılan kodun büyük olasılıkla hatasız çalışmayacağını, bir yerde patlayacağını hatırlattı. Okunmaya çalışılan dosyanın da hatalı bir program yüzünden kaybedilmemesi gerekir. Doğru yol, işi bitince dosyayı kapatıp sonra çıkmaktır. Hoca slayttaki "you can't depend on this behavior" cümlesini tevekkül benzetmesiyle açıkladı: önce önlem alınır, olaylar alınan önlemi aşarsa ancak o zaman yapacak bir şey yoktur denir.

## 9. Örnek 1: İkili Kipte Karakter Karakter Kopyalama

İlk örnek, ikili kipte tek karakter okuyup tek karakter yazarak dosya kopyalamaktır. Daha sonra aynı kod bir metin dosyası üzerinde de çalıştırıldı. Slayttaki kod şudur (ekrandan, 01:35:00):

```c
#include <stdio.h>
#include <stddef.h>
#define FAIL 0
#define SUCCESS 1
int copyfile(char * infile, char * outfile){
  FILE *fp1, *fp2;
  if ((fp1 = fopen(infile, "rb" )) == NULL) {
    printf("Could not open the input file\n"); return FAIL;
  }
  if ((fp2=fopen (outfile, "wb" )) == NULL) {
    printf("Could not open the output file\n"); fclose( fp1 ); return FAIL;
  }
  while (!feof( fp1 ))
    putc( getc(fp1), fp2 );
  fclose(fp1); fclose(fp2); return SUCCESS;
} //to be continued with the main method
```

Slayttaki kutuda şu açıklama yer alır: dosya sonuyla karşılaşıldığında `feof()` fonksiyonu sıfırdan farklı bir değer döndürür.

Kodun yapısı şöyledir:

- `stdio.h`, `printf`, `scanf`, `fscanf`, `fgetc`, `fputc` gibi bütün fonksiyonlar için gereklidir.
- İki makro tanımlanır: başarısızlık `FAIL` = 0, başarı `SUCCESS` = 1.
- Yapılacak iş dosya kopyalamak olduğu için bir `copyfile` fonksiyonu vardır. Başarılıysa 1, başarısızsa 0 döndürür. İki parametre alır: `infile` açılacak kaynak dosyanın konumunu ve adını, `outfile` kopyalamanın hedef dosyasının yolunu ve adını içeren katarlardır.
- Bir dosyadan okunup başka bir dosyaya yazılacağı, yani iki dosyayla çalışılacağı için iki dosya işaretçisi tanımlanır.
- Birinci işaretçi `fopen` ile elde edilir: `infile` okuma amacıyla ve ikili kipte açılır (`"rb"`). Açmaya çalışır çalışmaz işaretçinin `NULL` olup olmadığı denetlenir. `NULL` ise daha fazla ilerlenmez, ekrana "dosyayı açamadım" mesajı yazılır ve `FAIL` döndürülür.
- İkinci dosya bu kez yazma kipinde (`"wb"`) açılmaya çalışılır ve aynı biçimde denetlenir.

İkinci denetimin önemli bir ayrıntısı vardır. Programın akışı ikinci `if`'e gelebildiyse, birinci dosya başarıyla açılmış demektir; çünkü birinci dosya açılamasaydı fonksiyon `FAIL` ile dönmüş olurdu. Öyleyse ikinci dosya açılamadığında, geri dönmeden önce açık olan birinci dosyayı kapatmak unutulmamalıdır. Kodda bu yüzden `fclose( fp1 ); return FAIL;` yazılıdır.

İki dosya da düzgün açıldıysa algoritma şudur: kaynak dosyadan okunacak bilgi olduğu sürece, bir `while` döngüsü içinde hedef dosyaya yazılır. Bunun için `feof` fonksiyonundan yararlanılır. Adı "end of file"dan gelir; dosya fonksiyonları `f` ile başladığı ve `EOF` makrosuyla karışmaması için `feof` adı verilmiştir. Bu fonksiyona bir dosya işaretçisi verildiğinde, o işaretçinin dosya konum göstergesinin dosya sonuna ulaşıp ulaşmadığına bakar. Ulaşmışsa doğru (true), ulaşmamışsa yanlış (false) döndürür. `!feof(fp1)` ise okunacak bir şey olduğu sürece doğrudur.

Döngü gövdesi tek satırdır, ama iç içe iki çağrı içerir. Önce en içteki fonksiyon çalışır: `fp1`'in gösterdiği dosyadan `getc` ile bir karakter alınır. Sonra alınan karakter `putc` ile `fp2`'nin gösterdiği dosyaya yazılır. Döngüden sonra iki dosya da kapatılır ve fonksiyon biter.

**Soru:** `getc` kendiliğinden bir sonraki karaktere mi geçiyor? Kodda hiçbir şey artırılmıyor. **Cevap:** Evet. Okuma işlemi dosya konum göstergesini kendiliğinden bir karakter ilerletir; programcı değil, fonksiyon ilerletir. İşaretçinin şu an nerede olduğu genelde yalnız dosya sonuna ulaşıp ulaşmadığıyla, `feof` fonksiyonuyla denetlenir.

Fonksiyonu denemek için bir `main` yazıldı (ekrandan, 01:40:00):

```c
int main(){
  char infl[100], outfl[100];
  int result;
  printf("enter name of the input file\n");  scanf("%s", infl);
  printf("enter name of the output file\n"); scanf("%s", outfl);

  result=copyfile(infl, outfl);
  if(result == SUCCESS)
    printf("input file is copied to the output file \n");
  if(result == FAIL)
    printf("input file could not be copied to the output file \n");
  return 0;
}
```

Dosya adları için 100 karakterlik diziler yeterlidir. Dosya adı olarak göreli yol (relative path) ya da tam yol (absolute path) verilebilir. `main`'de dosya kapatmayla ilgili bir şey yapılmaz, çünkü bu işi `copyfile` içindeki `fclose` çağrıları yapar.

Hoca kodu derste Dev-C++'ta derledi (ekrandan, 00:10:00). Ekrandaki sürümde `main`'in imzası `int main(int argc, char *argv[])` biçimindeydi. Bu ajan iki parçayı slayttaki biçimiyle birleştirip `gcc -Wall` ile derledi; uyarısız derlendi ve aşağıdaki denemelerde çalıştı. Var olmayan bir kaynak dosya adı verildiğinde program "Could not open the input file" ve "input file could not be copied to the output file" yazdı.

## 10. Dosya Sonunu Doğru Denetlemek

Hoca `EOF` ile ilgili birkaç şey daha söyledi. Dosya sonu, gösterildiği biçimde `feof` fonksiyonuyla denetlenmelidir. Okunan karakterin değerine bakıp "şu değer geldiyse dosyanın sonuna gelmişimdir" dememek gerekir. Hele bu örnekte dosya ikili kipte açıldığı için böyle bir yaklaşım çalışmayacaktır.

Slayttaki bir kod parçası, okunan karakteri `EOF` ile karşılaştırarak döngü kurmaktadır. <!-- BELİRSİZ: Bu kod parçasının slayttaki tam metni karelerde görünmüyor. --> Hoca bu tür bir döngünün sakıncasını şöyle açıkladı: o işletim sisteminde `EOF` hangi karakterle kodlanmışsa, dosyanın içinde o karakterle aynı değerli bir bayt okunduğunda döngü dosyanın sonuna gelmeden bitebilir. Bu, farklı işletim sistemlerinde farklı biçimde yapılandırılabilir. İki bilgisayarın ikisi de Windows olsa bile, farklı güncellemeler yüzünden farklı çalışabilir. Böyle bir kodun taşınabilirliği yoktur.

> **Hocanın vurgusu:** Dosya sonunu her zaman `feof` fonksiyonuyla denetleyin. En yüksek taşınabilirlik için önerilen yöntemleri kullanın.

> **Ders sonrası not:** Tehlike, okunan değerin `char` türünde bir değişkende tutulup `EOF` ile karşılaştırılmasıdır: bu durumda `0xFF` değerli bir veri baytı `EOF` (`-1`) ile karışabilir. `getc`'nin dönüş değeri `int` bir değişkende tutulursa (`int c; while ((c = getc(fp1)) != EOF) putc(c, fp2);`) veri baytları 0-255 aralığında, `EOF` ise bunların dışında kalır. Bu biçim, aşağıda görülen "fazladan karakter" sorununu da yaşamaz.

## 11. Örnek 1'in Çalıştırılması: Metin ve PDF

Kod önce bir metin dosyasıyla denendi. Kaynak olarak, içinde Türkçe karakterler, büyük ve küçük harfler ve inceltme işaretli harfler gibi farklı karakterler bulunan bir metin kullanıldı. Program, kaynak dosyayla aynı dizinde çalıştırıldığı için yalnız `kaynak.txt` yazmak yeterliydi. Hoca yol türlerini şöyle açıkladı: dosya, programın altındaki `veriler` adlı bir klasörde olsaydı `veriler/kaynak.txt` yazılırdı; bu da göreli yoldur. Sürücü harfinden başlayıp bütün klasörleri sayarak yazılsaydı tam yol kullanılmış olurdu.

Sonuç: hedef dosya metin dosyası olmasına rağmen ikili kipte açılmış bir kaynaktan ikili kipte kopyalanabildi ve Türkçe ya da aksanlı karakterler bozulmadı. Ancak bir öğrencinin dikkatiyle, dosyanın sonuna fazladan bir karakter eklendiği görüldü. Hoca hiçbir düzenleme yapmadığını, kodun bir karakter fazlasıyla kopyaladığını söyledi. Bunu Windows 10'un son güncellemesinde gördüğünü, başka bir sürümde sorun çıkmayabileceğini ekledi.

Daha sonra bir öğrencinin yazılı olarak ilettiği açıklama okundu: `feof`, dosya sonuna ulaşıldı bayrağını, dosya sonuna gerçekten ulaşma (onu aşan bir okuma) denemesinden sonra kurar. Bu yüzden döngü bir tur fazla döner ve bir karakter fazla yazılır. Hoca bunu düzeltmek için `EOF`'tan bir önceki karakterde durmaya çalışmanın kodu karmaşıklaştıracağını söyledi. Ayrıca yapılacak ince ayarın Windows 10'da çalışıp Ubuntu'da, ya da Ubuntu'nun bir sürümünde çalışıp öbüründe çalışmayabileceğini belirtti. Bu yüzden kod olduğu gibi bırakıldı.

> **Ders sonrası not:** Fazladan karakter, son turda `getc`'nin döndürdüğü `EOF` (`-1`) değerinin `putc` ile `unsigned char`'a çevrilip yazılmasıdır. Bu ajanın denemesinde (Linux, `gcc`) 40 baytlık bir metin dosyası 41 bayt olarak kopyalandı ve son bayt `0xFF` çıktı. Yani bu davranış Windows sürümüne özgü değildir, standart davranıştır. Bölüm 10'daki `int c` biçimindeki döngü bu sorunu yaşamaz.

Sonra aynı kod ikili bir dosyayla denendi. Aynı metin Word'de yazılıp bazı yerleri kalın yapılarak PDF biçiminde kaydedilmişti. Bu dosya Not Defteri'nde metin olarak açıldığında anlaşılmaz karakterler görüldü: PDF biçiminin kendi yapısına ait bazı şeyler ve yazı tipi bilgileri seçiliyordu, ama metnin kendisi görünmüyordu. `kaynak.pdf` dosyası `hedef.pdf` olarak kopyalandı ve PDF okuyucusunda düzgün açıldı. Hoca, sona garip bir karakter eklenmiş olsaydı PDF okuyucusunun büyük olasılıkla "dosya biçimi bozuk" diyerek açmayacağını, PDF'in bu konuda hassas olduğunu söyledi. Kapatırken okuyucunun "kaydetmek istiyor musunuz" diye sorması hocaya ilginç geldi; dosyanın düzgün kapatılıp kapatılmadığını düşündü, ama kodda iki dosyanın da `fclose` ile kapatıldığını, kapatılmamış olsaydı dosyanın büyük olasılıkla hiç açılamayacağını belirtti.

> **Ders sonrası not:** Aynı kod PDF dosyasının sonuna da büyük olasılıkla bir `0xFF` baytı ekledi. PDF okuyucuları dosya sonundaki fazladan baytları çoğunlukla tolere eder; okuyucunun "kaydet" sorusu da büyük olasılıkla bu küçük bozukluğu onarmak istemesinden kaynaklandı.

**Soru:** Az önce PDF dosyasında değişiklik yapıp kaydetme gibi bir şey yaptık mı? **Cevap:** Hayır. Kullanılan program yalnız bir PDF okuyucusuydu; değişiklik yapılmadı.

Arayı izleyen kısımda hoca bu örneği şöyle özetledi: aslında metin olan bir dosya hem metin hem ikili kipte açılıp karakter karakter okunup yazılabildi. Metin dosyasını ikili kipte açmanın, sona eklenen küçük fazlalık dışında bir sakıncası olmadı. Taşınabilirlik konusu burada devreye girer: aynı kod ikili dosyayı düzgün kopyaladı, metin dosyasında da küçük bir kusurla epeyce düzgün çalıştı.

## 12. getc ile fgetc Karşılaştırması

Karakter düzeyinde `getc` ve `fgetc` fonksiyonları vardır. Aslında `getc` bir makro, `fgetc` bir fonksiyondur. Fonksiyon ile makro arasındaki üstünlük ve eksiklikler daha önce konuşulmuştu: makroların veri türleri üzerinde beklenmedik yan etkileri olabilir, fonksiyonlar ise güçlü tür denetimi nedeniyle bu konuda daha üstündür. Makro ise çalışma zamanına daha az ek yük getirir.

Slaytta `getc`'nin `fgetc`'den neredeyse iki kat hızlı olduğu yazar. Hoca bunu şöyle yorumladı: bir milisaniyenin iki katı iki milisaniyedir. Derste kopyalanan dosya uzun değildi ve iş hiç bekletmeden yapıldı. Daha büyük bir dosyada bir buçuk saniye ile iki saniye arasındaki fark önemliyse makro kullanılabilir. Önemli değilse sistemin darboğazı büyük olasılıkla başka bir yerdedir ve orayı iyileştirmek daha önemlidir. O nokta iyileştirildikten sonra istenirse `fgetc`'ler `getc`'ye çevrilebilir.

Hoca, makrolarda dosya işaretçisini bir sonraki birime ilerletmek gibi alışılmadık çağrıların düzgün çalışmayabileceğini, bunun bütün dosyanın okunamaz ya da yazılamaz hale gelmesine kadar gidebileceğini söyledi. Bu yüzden önerisi şudur: çok yavaş bir diskle çalışılmıyorsa, fark önemli değilse `fgetc` ve `fputc` kullanılmalıdır.

> **Ek bilgi (derste anlatılmadı):** `getc` makro olarak gerçeklenebildiği için argümanını birden fazla kez değerlendirebilir. Bu yüzden `getc(fp++)` gibi yan etkili bir argüman verilirse işaretçi beklenenden fazla artabilir. `fgetc` gerçek bir fonksiyon olduğu için argümanı bir kez değerlendirilir.

## 13. Örnek 2: Metin Kipinde Satır Satır Kopyalama

İkinci örnek, satır satır okuma ve yazmadır. Bir önceki örneğe göre en önemli fark, dosyanın ikili kip yerine metin kipinde açılmasıdır: `rb` yerine `r`, `wb` yerine `w` kullanılır. Bu durumda `feof` ile döngü kurulmaz; satır satır okunduğu için okunan satırın son satır olup olmadığına bakmak gerekir. Bu iş `fgets`'in dönüş değeriyle yapılır.

Hoca metinlerde `'\0'` ile bitişe güvenilemeyeceğini söyledi. Bir önceki derste oluşturulan metin dosyasında paragraf işaretleri vardı, ama bir dosya paragraf işaretiyle bitmeyebilir ve metin dosyasında `'\0'` karakteri bulunmaz. "Satır satır okuma" denince otomatik bir satır sonu, paragraf, `\n` ya da `\t` kastedilmez; belli uzunlukta bir karakter katarı kadar okuma ve yazma yapılır. Bu yüzden fazladan bir `LINESIZE` tanımlandı: 100 karakterlik bir tampon.

Slayttaki kod şudur (ekrandan, 00:30:00):

```c
#include <stdio.h>
#include <stddef.h>
#define FAIL 0
#define SUCCESS 1
#define LINESIZE 100
int copyfile(char * infile, char * outfile){
  FILE *fp1, *fp2; char line[LINESIZE];
  if ((fp1 = fopen(infile, "r" )) == NULL) {
    printf("Could not open the input file\n"); return FAIL;
  }
  if ((fp2=fopen (outfile, "w" )) == NULL) {
    printf("Could not open the output file\n"); fclose( fp1 ); return FAIL;
  }
  while (fgets ( line, LINESIZE-1, fp1 ) != NULL)
    fputs( line, fp2 );
  fclose(fp1); fclose(fp2); return SUCCESS;
} //the main method will be the same as the previous example
```

Slayttaki kutuda "fark `while` döngüsünde ve gövdesindedir" yazar. Hoca derste `#include <stddef.h>` satırını gerekmediği için yorum satırı yaptı (ekrandan, 00:35:00 ve 00:40:00). `NULL`, `stdio.h`'den de geldiği için bu satır olmadan da kod derlenir.

`fgets`'in üç parametresi vardır. Birincisi okunan metnin yazılacağı bellek alanıdır. İkincisi kaç karakter okunacağıdır: hoca bunu `LINESIZE`'dan bir eksik verdiğini, çünkü son karakterin `'\0'` ile sonlandırılacağını söyledi. Üçüncüsü okunacak dosyanın işaretçisidir. `fgets` düzgün bir karakter katarı döndürdüğü sürece okumaya devam edilir: önce okunan şey ikinci dosyaya yazılır, sonra yeniden okuma denenir. Bu, `fgets` artık bir satır alamayıp `NULL` döndürene kadar sürer. Geri kalan kısım ve `main` aynıdır.

`fgets`, okuma sırasında satır sonu (`\n`) görürse 100 karakteri doldurmayı beklemeden durur: o an okuduğu bloğun kaçıncı karakterinde satır sonuna denk gelmişse orada keser. Hoca `\r` (satır başı, carriage return) için de aynısının olup olmadığından emin olmadığını söyledi. `fputs` ise bir karakter işaretçisini (ya da dizisini) dosyaya yazar; argümanları daha sadedir.

> **Ders sonrası not:** Hoca `LINESIZE-1` ile 99 karakter okutulduğunu söyledi. `fgets(s, n, fp)` zaten en çok `n-1` karakter okuyup sonuna `'\0'` koyar; bu yüzden `fgets(line, LINESIZE-1, fp1)` en çok 98 karakter okur. `fgets(line, LINESIZE, fp1)` yazmak yeterli ve güvenlidir. `fgets` `\r` karakterinde durmaz, yalnız `\n`'de ya da sayı dolunca durur.

Hoca ilk denemede yazdığı kodda küçük bir yazım hatası yaptı, bir öğrencinin uyarısıyla düzeltti ve kod derlendi. Hedef dosya silinip program çalıştırıldı: `kaynak.txt` → `hedef.txt`. Bu kez sona fazladan karakter eklenmedi. Metin dosyası metin kipinde, sabit boyutlu da olsa satır satır okunduğunda hiçbir sorun çıkmadı.

Ardından aynı kodla PDF kopyalandı: `kaynak.pdf` → `hedef.pdf`. Program "kopyaladım" dedi, ama PDF açılırken hata verdi: dosya biçiminde sorun vardı. Hedef dosyanın boyutu yaklaşık 1 KB'tı, oysa önceki doğru kopya 341 KB'tı. Yani biçim uyumsuzluğu bir yana, yeterli bayt bile yazılamadı. Hocanın açıklaması şudur: ikili bir dosya metin kipinde açılıp veri okunmaya çalışılırsa iş uymaz.

> **Ek bilgi (derste anlatılmadı):** Windows'ta metin kipinde okurken `\r\n` çifti tek `\n`'ye çevrilir ve büyük olasılıkla Ctrl+Z (`0x1A`) baytı dosya sonu sayılır. İkili bir dosyada bu bayt herhangi bir yerde geçebileceği için okuma erken biter; 341 KB'lık PDF'in yalnız 1 KB kadarının kopyalanması bununla açıklanabilir. Ayrıca `fgets`/`fputs` `'\0'` ile sonlanan katarlarla çalıştığı için, veri içindeki bir `0x00` baytından sonraki kısım `fputs` tarafından yazılmaz.

> **Hocanın vurgusu:** Metinsel dosyaları metin kipinde, ikili dosyaları ikili kipte açıp işlemek en uygunudur.

**Soru:** Bu metin dosyasında `fputs` yerine, önceki örnekteki gibi `fputc` kullanılabilir miydi? **Cevap:** Kullanılabilirdi. Ama buradaki amaç metni satır satır, yani belli bir blok boyutu kadar okumayı göstermekti.

Hoca ayrıca `w` kipinin mevcut dosyanın üzerine yazdığını gösterdi. Hedef dosya açılıp sonuna "eklenti" sözcüğü eklendi ve kaydedildi. Program `kaynak.txt` ve `hedef.txt` ile yeniden çalıştırıldığında, hedef dosyanın eski hali silinip yerine yeniden kopyalandı ve eklenen sözcük kayboldu.

Hoca slaytları gözden geçirirken `fgets`'in `fgetc`'ye göre bir üstünlüğünü de vurguladı: kaç karakter okunacağı belirtilebilir. Bu ek bir yetenektir ve slaytta herhangi bir başarım kaybından söz edilmez. Bu yüzden `fgets` daha avantajlıdır. Genel öneri yine mümkün olduğunca makro değil fonksiyon kullanmaktır.

## 14. Blok Düzeyinde Giriş/Çıkış: fread ve fwrite

Daha çok ikili kipte geçerli olan blok düzeyinde giriş/çıkış işlemleri anlatıldı. Dosya söz konusuysa, arka planda en alt düzeyde diskten zaten blok blok okuma yapılır ve sabit bir blok boyutu vardır. Erişilen dosyanın bulunduğu sürücünün işletim sistemi tarafından hangi blok boyutuyla okunduğuna göre, programda seçilen blok boyutu başarımı biraz iyileştirebilir ya da kötüleştirebilir. Bu parametre çekirdek düzeyinde değiştirilebilir ve arada çok parametre vardır. Derste bu aşamada başarıma değil öğrenmeye odaklanıldı.

Slayttaki maddeler şunlardır (ekrandan, 00:45:00):

- Veriye, her biri bir dizide tutulan ve blok denen parçalar halinde de erişilebilir.
- Bir blok okunurken ya da yazılırken bloktaki eleman sayısı ve her elemanın boyutu belirtilmelidir.
- İki blok giriş/çıkış fonksiyonu `fread()` ve `fwrite()`'tır.
- `size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);`
- `void fwrite(void *ptr, size_t size, size_t nmemb, FILE *stream);`
  - `size_t`: `stdio.h`'de tanımlı bir tamsayı türü.
  - `ptr`: verinin saklanacağı dizinin (çoğunlukla `char`) işaretçisi.
  - `size`: dizideki her elemanın boyutu.
  - `nmemb`: okunacak eleman sayısı.
  - `stream`: dosya işaretçisi.

Hoca parametreleri şöyle açıkladı. `fread`'in ilk parametresi okunacak verinin yazılmaya başlanacağı adrestir. `size` ile `nmemb`'in çarpımı kadar okuma yapılır: `size` bir seferde okunacak verinin genişliği, `nmemb` dizideki eleman sayısıdır. Örneğin bir `int` dizisi okunacaksa `size` bir `int`'in boyutu, `nmemb` kaç eleman okunacağıdır. Son parametre verinin okunacağı dosya işaretçisidir. Eşleniği `fwrite`'tır: ilk parametre yazılacak verinin bellekteki başlangıç adresi, sonraki ikisi her elemanın boyutu ve eleman sayısı, sonuncusu verinin yazılacağı dosya işaretçisidir. Hoca slayta göre `fwrite`'ın bir şey döndürmediğini, yazmanın başarılı olup olmadığının buradan anlaşılamayacağını söyledi.

> **Ders sonrası not:** Slaytta `void fwrite(...)` yazar ve hoca da `fwrite`'ın bir şey döndürmediğini söyledi. Standart C'de `fwrite`'ın prototipi `size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);` biçimindedir: başarıyla yazılan eleman sayısını döndürür. Bu değer `nmemb`'den küçükse yazma hatası olmuştur.

`fread` ise gerçekten okunan eleman sayısını döndürür. Bu değer bir hata ya da dosya sonuyla karşılaşılmadıkça üçüncü argümanla (`nmemb`) aynı olmalıdır. Yani "n adet eleman oku" denmiş ve geri dönen değer bu parametreyle aynıysa, gerçekten o kadar eleman okunabilmiş demektir. Daha az eleman okunmasının iki nedeni olabilir: ya dosya sonuna gelinmiştir ve kalan eleman sayısı daha azdır, ya da bir sorunla karşılaşılmıştır. Kod buna göre yazılmalıdır.

> **Ders sonrası not:** Hoca dönen değeri anlatırken eleman sayısının `sizeof` ile çarpımından da söz etti. `fread` bayt sayısını değil, okunan eleman sayısını döndürür. Aşağıdaki örnekte eleman türü `char` (1 bayt) olduğu için ikisi aynı sayıdır.

Slaytta disk sistemlerinin blok boyutuyla ilgili bir örnek de vardı: istenen boyut diskin blok boyutundan büyükse arka planda birden çok okuma yapılır, ama bu programcıdan bağımsızdır. Programcı örneğin 1024 bayt ister; dosyada o kadar bayt kalmadıysa daha azı gelir. <!-- BELİRSİZ: Bu slaytın tam metni karelerde görünmüyor; altyazıda yalnız "iki kere okuma işlemi olacaktır" ve 1024 bayt örneği seçiliyor. -->

## 15. Örnek 3: İkili Kipte Blok Blok Kopyalama

Bu örnekte bir blok boyutu tanımlanır. Bayt bayt okunacağı ve bir bayt bir karakter boyunda olduğu için veri türü olarak `char` tanımlanır. Hoca `typedef int DATA` gibi bir tanımın burada doğru olmayacağını, okuma bayt cinsinden yapıldığı için `char` seçtiğini söyledi. Slaytın ilk kısmı şudur (ekrandan, 00:50:00):

```c
#include <stdio.h>
#include <stddef.h>
#define FAIL 0
#define SUCCESS 1
#define BLOCKSIZE 512
typedef char DATA;
//continued in the next slide
```

Örnek yine ikili kipte okur ve yazar; fark, işlemlerin `fread` ve `fwrite` ile yapılmasıdır. Bir blok verinin sığabileceği kadar alan tanımlanır: `BLOCKSIZE` elemanlık bir `DATA` dizisi. Veri oraya `sizeof(DATA)` boyutlu elemanlar halinde, yani bayt bayt, `fp1` üzerinden okunur. Gerçekten istenen sayıda karakter okunabildiyse, okunanın hepsi yazılır. Döngü bu koşulla döner: her turda `BLOCKSIZE` kadar eleman okunup yazılır.

Ancak şu durum her zaman olasıdır: son turda kaynak dosyada `BLOCKSIZE`'dan az eleman kalmıştır ve dosya sonuna ulaşılmıştır. Hoca slayttaki "notice this line" benzeri yorumlu satıra dikkat çekti: döngüden sonra, kalan elemanları hedef dosyaya yazmayı unutmamak gerekir. Bu yüzden o satır önemlidir. `main` önceki örnekle tamamen aynıdır.

<!-- BELİRSİZ: Slaytın ikinci kısmı (döngünün tam kodu, slayt 249) karelerde görünmüyor; aşağıdaki kod ajan tarafından anlatıma göre kuruldu. -->

Aşağıdaki tam program derste bu biçimde gösterildiği doğrulanamadığı için ajan tarafından, hocanın anlatımına ve slaytın görünen ilk kısmına göre kuruldu. `gcc -Wall` ile uyarısız derlendi. 6656 baytlık ($13 \times 512$) ve 7000 baytlık rastgele ikili dosyalarla denendi; iki kopya da kaynakla bayt bayt aynı çıktı.

```c
#include <stdio.h>
#include <stddef.h>
#define FAIL 0
#define SUCCESS 1
#define BLOCKSIZE 512
typedef char DATA;

int copyfile(char *infile, char *outfile) {
  FILE *fp1, *fp2; DATA block[BLOCKSIZE]; size_t num_read;
  if ((fp1 = fopen(infile, "rb")) == NULL) {
    printf("Could not open the input file\n"); return FAIL;
  }
  if ((fp2 = fopen(outfile, "wb")) == NULL) {
    printf("Could not open the output file\n"); fclose(fp1); return FAIL;
  }
  while ((num_read = fread(block, sizeof(DATA), BLOCKSIZE, fp1)) == BLOCKSIZE)
    fwrite(block, sizeof(DATA), num_read, fp2);
  fwrite(block, sizeof(DATA), num_read, fp2); /* son, eksik blok */
  fclose(fp1); fclose(fp2); return SUCCESS;
}

int main() {
  char infl[100], outfl[100];
  int result;
  printf("enter name of the input file\n");  scanf("%s", infl);
  printf("enter name of the output file\n"); scanf("%s", outfl);
  result = copyfile(infl, outfl);
  if (result == SUCCESS)
    printf("input file is copied to the output file \n");
  if (result == FAIL)
    printf("input file could not be copied to the output file \n");
  return 0;
}
```

Hoca bu örneği yalnız ikili dosya üzerinde çalıştırdı. Metin dosyasını blok blok okumanın pek anlamı yoktur, çünkü metin dosyaları için en iyi yolun metin kipinde açıp belli bir karakter sayısı kadar okumak olduğu görülmüştü. Kodda `BLOCKSIZE` ve `typedef char DATA` satırları eklendi, `LINESIZE` kaldırıldı, kipler ikili yapıldı ve döngü değiştirildi; geri kalan kısım ve `main` aynı kaldı.

Program `kaynak.pdf` → `hedef.pdf` ile çalıştırıldı. Hedef dosya 342 KB göründü ve PDF okuyucusunda hiçbir sorun olmadan açıldı; karakterler bozulmadı. Bu kez kapatırken okuyucu "kaydetmek istiyor musunuz" diye de sormadı. Yani ikili dosyayı blok blok okumak en doğru sonucu verdi.

Hoca günün özetini şöyle yaptı: buraya kadar yapılan iş aslında sırayla bütün baytları (ya da karakterleri) okuyup hedefe yazmaktı. Bütün bu farklı örnekler içinde metin tabanlı dosya için en iyi sonucu, dosyayı metin kipinde açıp belli bir karakter sayısı kadar okuyup yazmak verdi. İkili dosyalar için en iyi sonucu, dosyayı ikili kipte açıp blok blok işlemek verdi.

## 16. Son Eksik Blok Neden Ayrıca Yazılır?

**Soru:** Döngüden çıktıktan sonra `fwrite`'ı neden bir kez daha yazıyorduk? **Cevap:** Hoca bunu bir tabloyla gösterdi (ekrandan, 00:55:00). Tablonun ilk satırı kaynak dosyayı 1024 baytlık parçalar halinde gösterir: altı tane 1024 ve sonda 512. Blok boyutu (`block size`) 1024'tür. Altında "Okuma NO" ve "Okunan Byte" sütunları vardır.

Adım adım:

- 1. okuma: 1024 baytın hepsi okunabildi.
- 2. okuma: dosyada hâlâ yer var, 1024 bayt daha okundu.
- 3., 4., 5. ve 6. okuma: her birinde yine 1024 bayt okundu.
- 7. okuma: dosyada 1024 bayt kalmamıştır; `fread` yalnız 512 bayt okuyabilir ve 512 döndürür.

Döngü koşulu, `fread`'in döndürdüğü sayının `BLOCKSIZE`'a eşit olmasıdır. İlk altı turda 1024 okunur, 1024 yazılır. Yedinci turda okunan sayı 512, blok boyutu 1024'tür; $512 \neq 1024$ olduğu için döngüden çıkılır. Oysa yazma işlemi döngünün içindedir. Bu yüzden son okunan 512 bayt hedef dosyaya yazılmadan döngüden çıkılmış olur. Döngüden sonraki `fwrite`, bellekte bekleyen bu son kısmı ayrıca yazmak için gereklidir.

Toplam dosya boyutu (ara adım eklendi): $6 \times 1024 + 512 = 6144 + 512 = 6656$ bayt. Bu, 7 `fread` çağrısı ve 7 `fwrite` çağrısı (6'sı döngü içinde, 1'i döngüden sonra) demektir.

> **Ders sonrası not:** Tablodaki örnekte blok boyutu 1024, slayttaki kodda ise `BLOCKSIZE` 512'dir. Mantık aynıdır; ajanın denemesindeki 6656 baytlık dosya, `BLOCKSIZE` = 512 ile tam 13 bloktur.

**Soru:** Dosyanın boyutu blokların tam katı olsaydı (son blok da tam 1024 olsaydı) kod yine çalışır mıydı? **Cevap:** Hoca çalışacağını düşündüğünü söyledi: son okumada 0 bayt okunur ve 0 bayt yazılmaya çalışılır, bunun sorun çıkarmayacağını düşündüğünü, ama tam buna denk gelen bir örnek dosyası olmadığını ekledi. Bu ajanın denemesinde 6656 baytlık ($13 \times 512$) dosya `BLOCKSIZE` = 512 ile kopyalandı: son `fread` 0 döndürdü, 0 elemanlık `fwrite` hiçbir şey yazmadı ve kopya kaynakla bayt bayt aynı çıktı.

Rastgele erişim (random access) konusu bir sonraki derse kaldı.

## Örnek Sorular

**Soru 1** (derste sözlü, 01:38:23): Karakter karakter kopyalama döngüsünde (`while (!feof(fp1)) putc(getc(fp1), fp2);`) hiçbir sayaç artırılmıyor. Bir sonraki karaktere nasıl geçiliyor?

Çözüm (derste verildi): Her okuma işlemi dosya konum göstergesini kendiliğinden bir karakter ilerletir. İlerletmeyi programcı değil, `getc` fonksiyonu yapar. Dosya sonuna gelinip gelinmediği `feof` ile denetlenir.

**Soru 2** (derste sözlü, 00:03:08 ve 00:09:43): Örnek 1'deki kod metin dosyasını kopyalarken hedefin sonuna neden fazladan bir karakter ekliyor?

Çözüm (derste verildi): `feof`, dosya sonu bayrağını ancak dosya sonunu aşan bir okuma denemesinden sonra kurar. Son gerçek karakter okunduktan sonra `feof` hâlâ yanlış döndürür, döngü bir tur daha döner, `getc` `EOF` döndürür ve bu değer de `putc` ile yazılır.

> **Çözüm (derste verilmedi):** Yazılan bayt `EOF` (`-1`) değerinin `unsigned char`'a çevrilmiş halidir, yani `0xFF`. Bu ajanın `gcc` ile yaptığı denemede 40 baytlık dosya 41 bayt olarak kopyalandı, son bayt `0xFF` çıktı. Düzeltilmiş döngü: `int c; while ((c = getc(fp1)) != EOF) putc(c, fp2);`

**Soru 3** (derste sözlü, 01:21:46): Dosya ikili kipte açıldığında `fscanf` ile okuma biçimi değişir mi?

Çözüm (derste verildi): Değişmez; `r` ya da `rb` ile açmak `fscanf` ile yapılan işi değiştirmez. Ancak bazı açma kipleriyle bazı veri biçimleri arasında uyumsuzluk olabilir.

**Soru 4** (derste sözlü, 00:39:26): Metin dosyasını kopyalarken `fputs` yerine `fputc` kullanılabilir miydi?

Çözüm (derste verildi): Kullanılabilirdi. Örneğin amacı satır satır (belli bir blok boyutu kadar) okumayı göstermekti.

**Soru 5** (ekrandan, 00:55:00; derste sözlü, 00:53:27): Kaynak dosya altı tane 1024 baytlık parça ve sonda 512 bayttan oluşuyor, blok boyutu 1024. Blok kopyalama döngüsü kaç kez okur, her okumada kaç bayt gelir ve döngüden sonra neden bir `fwrite` daha gerekir?

Çözüm (derste verildi):

| Okuma no | Okunan bayt | Döngü koşulu (`== 1024`) | Döngü içinde yazıldı mı? |
|---|---|---|---|
| 1-6 | 1024 | doğru | evet |
| 7 | 512 | yanlış | hayır |

Yedinci okumada gelen 512 bayt döngü içinde yazılmaz; döngüden sonraki `fwrite` bu son kısmı yazar. Toplam boyut $6 \times 1024 + 512 = 6656$ bayttır.

**Soru 6** (derste sözlü, 00:57:43): Dosya boyutu blok boyutunun tam katı olsaydı kod yine çalışır mıydı?

Çözüm (derste verildi): Hoca çalışacağını düşündüğünü söyledi; son okuma 0 bayt döndürür ve 0 bayt yazmak sorun çıkarmaz.

> **Çözüm (derste verilmedi):** Ajanın denemesinde 6656 baytlık ($13 \times 512$) dosya `BLOCKSIZE` = 512 ile kopyalandı: 13 tam okumadan sonra 14. `fread` 0 döndürdü, döngüden sonraki `fwrite` 0 eleman yazdı ve kopya kaynakla bayt bayt aynı çıktı.

**Soru 7** (ekrandan, 00:30:00): `#define LINESIZE 100` ve `char line[LINESIZE];` ile `fgets(line, LINESIZE-1, fp1)` çağrısı bir seferde en çok kaç karakter okur?

> **Çözüm (derste verilmedi):** `fgets(s, n, fp)` en çok `n-1` karakter okuyup sonuna `'\0'` koyar. Burada `n` = `LINESIZE-1` = 99 olduğu için en çok 98 karakter okunur; satır sonu daha önce gelirse `\n` dahil orada durur. Hoca derste 99 dedi. `fgets(line, LINESIZE, fp1)` ile 99 karakter okunur ve dizi taşmaz.

## Dersin Toparlaması

Bu derste C'de dosya işlemlerinin temeli kuruldu. Dosyaya `stdio.h`'deki `FILE` yapısını gösteren bir işaretçi üzerinden erişilir. `fopen` dosyayı belirtilen kipte (`r`, `w`, `a`, `r+`, `w+`, `a+` ve sonlarına `b` eklenmiş ikili sürümleri) açar ve hata durumunda `NULL` döndürür. Bu yüzden her açmadan sonra `NULL` kontrolü yapılmalı, iş bitince dosya `fclose` ile kapatılmalıdır. Okuma ve yazma karakter (`getc`/`putc`), satır (`fgets`/`fputs`) ve blok (`fread`/`fwrite`) olmak üzere üç düzeyde yapılabilir. Konum göstergesini işletim sistemi ilerletir, dosya sonu `feof` ile denetlenir.

Aynı kopyalama işi üç biçimde yazılıp hem bir metin dosyası hem bir PDF ile denendi. İkili kipte karakter karakter kopyalama iki dosyayı da kopyaladı, ama `feof`'un çalışma biçimi yüzünden sona bir bayt fazla ekledi. Metin kipinde satır satır kopyalama metin dosyasını kusursuz kopyaladı, PDF'i ise bozdu. İkili kipte blok blok kopyalama PDF'i kusursuz kopyaladı; bunun için döngüden sonra son eksik bloğun ayrıca yazılması gerekir. Sonuç olarak metin dosyaları metin kipinde, ikili dosyalar ikili kipte işlenmelidir. Bir sonraki derste rastgele erişim (random access) konusuyla dosya işlemleri tamamlanacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
