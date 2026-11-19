# Ders 22 Çalışma Özeti

<!-- Kayıt iki parçadır. Ders saatine göre önce ikinci parça (01:02:56 sonrası, kuram ve ilk örnek), sonra birinci parça (00:00:00-01:02:08, örneklerin devamı) gelir. Özet ders akışına göre sıralanmıştır; zaman damgaları altyazı dosyasındaki damgalardır. -->

## Genel Konular

- Dosya işlemlerinin genel yapısı ve `FILE` yapısı
  - C'de dosya işlemleri `stdio.h` içindeki `FILE` yapısı üzerinden yapılır. Programcı bir `FILE *` işaretçisi tanımlar ve bütün giriş/çıkış fonksiyonlarına bu işaretçiyi verir. Yapının iç ayrıntılarını bilmek gerekmez.
  - Dosyaya erişmek için üç bilgi gerekir: dosyanın adı (ve dizini), erişim biçimi (okuma/yazma) ve işaretçi. C dosyayı bir akış (stream), yani bayt dizisi olarak ele alır. Akış daha genel bir kavramdır (ağ bağlantısı da akış olabilir), ama derste dosyaya odaklanılır.
  - `fopen()` fonksiyonu bir dosya işaretçisi döndürür; bu işaretçiyle okunur, yazılır ve dosya kapatılır (ekrandan, 01:10:00).
  - Bir program aynı anda birden çok dosya açabilir. Kuramda sınır yoktur, ama her gerçekleme ve işletim sistemi eşzamanlı akış sayısına bir sınır koyar.
  - `FILE` yapısının alanlarından biri dosya konum göstergesidir (file position indicator): bir sonraki okunacak ya da yazılacak baytı gösterir. Her okuma/yazma işleminde işletim sistemi bu göstergeyi kendiliğinden ilerletir.
  - Dosya işaretçisi ile dosyadaki konum karıştırılmamalıdır: işaretçi akışın kendisini, konum göstergesi ise akışın hangi noktasında olunduğunu gösterir. Konum göstergesine doğrudan erişim yöntemleri taşınabilir değildir.
- `stdio.h` başlık dosyası (ekrandan, 01:15:00)
  - Bütün giriş/çıkış fonksiyonlarının prototiplerini, `FILE` yapısının bildirimini ve bazı makro sabitleri içerir: `stdin`, `stdout`, `stderr`, `EOF`, `NULL`.
  - `stdin` varsayılan olarak klavye, `stdout` ekrandır. `stderr` hata çıktısı içindir ve varsayılan olarak `stdout` gibi ekrana (komut satırına) yazar. Bunlar yönlendirilebilir.
  - `EOF` (end of file), sistem dosya sonuna ulaştığında birçok fonksiyonun döndürdüğü değerdir. `NULL` boş işaretçinin adıdır; `stdio.h` ya da `stddef.h` eklenerek kullanılabilir.
- Dosya açma: `fopen` ve erişim kipleri (ekrandan, 01:20:00)
  - `fopen` iki argüman alır: dosya adı ve erişim kipi. Kipler metin ve ikili (binary) olmak üzere iki gruptur.
  - `"r"`: var olan metin dosyasını okumak için açar; okuma dosyanın başından başlar.
  - `"w"`: yazmak için yeni metin dosyası oluşturur. Aynı adlı dosya varsa içeriği silinir (sıfır uzunluğa indirilir), yazma baştan başlar.
  - `"a"`: ekleme (append) kipi. Yazma yalnız dosya sonuna yapılır; konum göstergesi elle başa taşınsa bile yazma yine sonda olur.
  - `"r+"`: var olan dosyayı hem okuma hem yazma için açar; konum başta olur.
  - `"w+"`: okuma ve yazma için yeni dosya oluşturur; var olan dosya sıfırlanır.
  - `"a+"`: var olan dosyayı açar ya da yenisini oluşturur; yazma yalnız dosya sonuna yapılır, mevcut içerik silinmez.
  - İkili kipler aynıdır, yalnız sonuna `b` eklenir: `rb`, `wb`, `ab`, `rb+`, `wb+`, `ab+`.
  - Örnek: ilk üç kaydı koruyup sonrasını değiştirmek için ne `w` ne `a` uygundur. Önce okuma kipinde açılıp saklanacak kayıtlar okunur, dosya kapatılır, sonra `w` ile açılıp önce saklanan kayıtlar, ardından yenileri yazılır.
  - `r` ve `r+` ile açılacak dosya önceden var olmalıdır; yoksa `fopen` `NULL` döndürür.
- `fopen` dönüş değeri ve `fprintf`/`fscanf` (ekrandan, 01:25:00)
  - Başarılıysa sıfırdan farklı bir dosya işaretçisi, hata olursa `NULL` döner. Her okuma/yazmadan önce dönen işaretçinin `NULL` olup olmadığına bakılmalı, `NULL` ise program düzgün biçimde sonlandırılmalıdır.
  - `fprintf` ve `fscanf`, `printf` ve `scanf` ile aynı biçimde çalışır; tek farkları hangi akışın kullanılacağını gösteren ek bir dosya işaretçisi argümanıdır.
- Üç veri boyutunda giriş/çıkış
  - Karakter (bayt) düzeyi: `getc`/`fgetc` ve `putc`/`fputc`.
  - Satır düzeyi (yalnız metin dosyaları için anlamlı): `fgets` ("get string from file") ve `fputs` ("put string to file").
  - Blok düzeyi (daha çok ikili kipte): `fread` ve `fwrite`.
- Okuma ile yazma arasında geçiş ve `fflush`
  - Aynı dosyada okumadan yazmaya (ya da tersine) geçerken araya `fseek`, `rewind` veya `fflush` çağrısı girmelidir. `fseek` konum göstergesini belli bir yere taşır; `fflush` işletim sisteminin giriş/çıkış kuyruğunda bekleyen işlemlerin hemen yapılmasını zorlar.
  - Giriş ve çıkış akışları aynı dosyayı gösterebilir, ama bir işten ötekine geçmeden önce dosya kapatılmalıdır.
- Dosya kapatma: `fclose` (ekrandan, 01:30:00)
  - `fclose(fp)` dosyayı kapatır, `fp`'nin gösterdiği `FILE` yapısını serbest bırakır (ayrıca `free` gerekmez) ve akışa bağlı tamponları boşaltır (flush).
  - Birçok işletim sisteminde aynı anda açık akış sayısı sınırlıdır; işi biten dosya kapatılmalıdır.
  - Program normal sonlanınca açık akışlar kapanır; çoğu işletim sistemi anormal sonlanmada da kapatır, ama buna güvenilemez.
- Örnek 1: ikili kipte karakter karakter kopyalama (ekrandan, 01:35:00 ve 01:40:00)
  - `copyfile(char *infile, char *outfile)` kaynağı `"rb"`, hedefi `"wb"` ile açar; `while (!feof(fp1)) putc(getc(fp1), fp2);` döngüsüyle kopyalar, iki dosyayı kapatır, `SUCCESS` (1) ya da `FAIL` (0) döndürür.
  - İkinci dosya açılamazsa, dönmeden önce açılmış olan birinci dosya kapatılır.
  - `main` dosya adlarını `scanf("%s", ...)` ile alır. Göreli yol (çalıştırılabilir dosyayla aynı dizinde `kaynak.txt` ya da `veriler/kaynak.txt`) veya tam yol verilebilir.
  - Metin dosyası (Türkçe ve aksanlı karakterler içeren bir metin) ikili kipte doğru kopyalandı, ama sona fazladan bir karakter eklendi. Nedeni: `feof`, dosya sonu bayrağını ancak dosya sonunu aşan bir okuma denemesinden sonra kurar; son turdaki `getc` `EOF` döndürür ve bu değer de yazılır.
  - Bir PDF dosyası da aynı kodla kopyalandı ve açıldı.
- `getc` ve `fgetc`
  - `getc` bir makro, `fgetc` bir fonksiyondur. Slayta göre `getc` neredeyse iki kat hızlıdır. Makroların beklenmedik yan etkileri olabilir; fonksiyonlar tür denetimi nedeniyle daha güvenlidir.
  - Hoca, darboğaz başka yerdeyse bu farkın önemsiz olduğunu söyledi ve `fgetc`/`fputc` kullanılmasını önerdi.
- Örnek 2: metin kipinde satır satır kopyalama (ekrandan, 00:30:00)
  - Kipler `"r"` ve `"w"` olur, `#define LINESIZE 100` ve `char line[LINESIZE]` eklenir. Döngü: `while (fgets(line, LINESIZE-1, fp1) != NULL) fputs(line, fp2);`. `main` aynıdır.
  - `fgets` üç parametre alır: okunanın yazılacağı bellek alanı, en çok kaç karakter okunacağı ve dosya işaretçisi. Satır sonu (`\n`) görürse belirtilen sayıyı beklemeden durur. Okuyamazsa `NULL` döndürür.
  - Metin dosyası kusursuz kopyalandı (fazladan karakter yok). PDF ise metin kipinde kopyalanınca bozuldu: dosya açılmadı ve boyutu yaklaşık 1 KB'ta kaldı (asıl dosya 341-342 KB).
  - `fgets`'in `fgetc`'ye göre üstünlüğü, kaç karakter okunacağının belirtilebilmesidir.
- Örnek 3: ikili kipte blok blok kopyalama (ekrandan, 00:50:00)
  - `size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);` ve `fwrite` aynı parametreleri alır: `ptr` verinin bellekteki yeri (çoğunlukla `char` dizisi), `size` bir elemanın boyutu, `nmemb` eleman sayısı, `stream` dosya işaretçisi (ekrandan, 00:45:00).
  - `fread` gerçekten okunan eleman sayısını döndürür. Bu sayı `nmemb`'den küçükse ya dosya sonuna gelinmiştir ya da bir hata olmuştur.
  - Örnekte `#define BLOCKSIZE 512` ve `typedef char DATA;` tanımlanır; bayt bayt okunduğu için veri türü `char`'dır.
  - Döngü, `fread` tam blok (`BLOCKSIZE` eleman) okuduğu sürece okunanı yazar. Döngüden sonra son, eksik blok ayrıca yazılmalıdır.
  - PDF bu yöntemle kusursuz kopyalandı.

## Hocanın Özellikle Vurguladığı Kısımlar

- `fopen`'dan sonra mutlaka `NULL` kontrolü
  - Kontrol yapılmazsa program düzgün sonlanmaz. Açılamıyorsa bunu bildirip programdan düzgün çıkılmalıdır.
- Açılan her dosya kapatılmalı
  - `malloc` ile alınan bellek nasıl `free` ile geri veriliyorsa, açılan dosya da `fclose` ile kapatılmalıdır. Hocanın deneyimine göre yazma yapılıp kapatmadan çıkılırsa dosya erişilemez hale gelebilir. Hoca kodlarda dosya erişimi bitince `fclose` görmek istediğini söyledi.
  - İlk yazılan kod büyük olasılıkla hatalı çalışacaktır; işletim sisteminin kapatmasına güvenmek yerine önlem alınmalıdır.
- Dosya sonu `feof` ile denetlenmeli
  - Okunan karakterin değerine bakarak dosya sonuna gelindiğine karar verilmemelidir: `EOF` ile aynı kodlu bir karakter okunursa döngü dosya sonundan önce bitebilir. Bu davranış işletim sistemine ve sürümüne göre değişir, kod taşınabilir olmaz.
- Metin dosyası metin kipinde, ikili dosya ikili kipte işlenmeli
  - Günün özeti: metin dosyası için en iyi sonuç metin kipinde satır satır (belli karakter sayısı kadar) okuyup yazmak, ikili dosya için en iyi sonuç ikili kipte blok blok işlemektir.
- Blok okumada son eksik blok unutulmamalı
  - Döngü yalnız tam blok okunduğu sürece döner; son turda okunan eksik blok döngü içinde yazılmaz, döngüden sonra ayrıca yazılmalıdır.
- Taşınabilirlik
  - İnce ayarlarla tek bir sisteme göre yazılan kod başka işletim sisteminde ya da aynı sistemin başka sürümünde çalışmayabilir. Taşınabilir yöntemler tercih edilmelidir.

## Kısa Tekrar Notları

- `FILE *fp = fopen(ad, kip);` ile açılır, hata varsa `NULL` döner.
- Kipler: `r` (oku, var olmalı), `w` (yaz, siler), `a` (sona ekle), `r+`, `w+`, `a+`; ikili için `b` eklenir.
- `fprintf`/`fscanf` = `printf`/`scanf` + dosya işaretçisi.
- Karakter: `getc`/`fgetc`, `putc`/`fputc`; satır: `fgets`/`fputs`; blok: `fread`/`fwrite`.
- `feof(fp)` dosya sonunu ancak sonu aşan bir okuma denemesinden sonra bildirir; `while(!feof) putc(getc())` sona fazladan bir bayt yazar.
- `fgets(buf, n, fp)` en çok `n-1` karakter okur, sonuna `'\0'` koyar, okuyamazsa `NULL` döndürür.
- `fread` okunan eleman sayısını döndürür; tam blok okunmadıysa dosya sonu ya da hata vardır.
- Blok kopyalamada döngüden sonra son eksik blok yazılır.
- Metin dosyası → metin kipi + satır; ikili dosya → ikili kip + blok.
- İşi biten dosya `fclose` ile kapatılır; `fclose` tamponu boşaltır ve `FILE` yapısını bırakır.

## Detaylı Açıklamalar

- **Dosya erişim modeli.** C standart kütüphanesi, disk ve işletim sistemi ayrıntılarını `FILE` yapısının arkasına saklar. Programcı yalnız dosyanın adını, erişim kipini ve dönen işaretçiyi bilir. Okuma ve yazma işlemleri konum göstergesini kendiliğinden ilerletir. Bu yüzden karakter karakter kopyalama döngüsünde hiçbir sayaç artırılmaz: `getc` her çağrıldığında konum bir bayt ilerler. Bunu derste bir öğrenci sordu, hoca da göstergeyi fonksiyonun ilerlettiğini söyledi.
- **Kip seçimi.** `w` dosyayı sıfırlar, `a` yalnız sona yazdırır ve göstergenin başa taşınmasına izin vermez. Bu yüzden dosyanın bir kısmını koruyup kalanını değiştirmek için oku-kapat-yeniden yaz yolu izlenir. Derste bir öğrencinin sorusu üzerine, dosyanın `r` ya da `rb` ile açılmasının `fscanf` kullanımını değiştirmediği söylendi; ama bazı açma kipleriyle bazı veri biçimleri arasında uyumsuzluk olabilir. Bu uyumsuzluk aşağıdaki PDF denemesinde görüldü.
- **Karakter düzeyinde kopyalama (Örnek 1).** Kaynak `rb`, hedef `wb` ile açılır, `while (!feof(fp1)) putc(getc(fp1), fp2);` ile kopyalanır. İç içe çağrıda önce içteki `getc` çalışır, okunan karakter `putc` ile yazılır. Derste bir metin dosyası bu kodla kopyalandı. Türkçe ve aksanlı karakterler bozulmadı, ama sona fazladan bir karakter eklendi. Bir öğrencinin yazılı olarak ilettiği açıklamaya göre `feof` dosya sonu bayrağını ancak sona ulaşma denemesinden sonra kurar. Hoca bunu düzeltmenin kodu karmaşıklaştıracağını ve sisteme bağlı ince ayarların taşınabilir olmayacağını söyleyerek kodu olduğu gibi bıraktı. Aynı kodla bir PDF dosyası da kopyalandı ve açıldı.
- **Satır düzeyinde kopyalama (Örnek 2).** Metin kipi (`r`, `w`) kullanılır ve döngü `fgets` dönüşüne göre kurulur. Metinlerde `'\0'` ile bitişe güvenilemeyeceği için, satırın uzunluğu belirsiz olduğu için sabit boyutlu bir tampon (`LINESIZE 100`) kullanılır. `fgets` satır sonunu görünce erken durur. Metin dosyası bu yöntemle fazladan karakter olmadan kopyalandı. Ancak PDF metin kipinde kopyalanınca yaklaşık 1 KB'lık, açılamayan bir dosya çıktı. Bir öğrenci metin dosyasında `fputs` yerine `fputc` kullanılıp kullanılamayacağını sordu. Hoca kullanılabileceğini, ama örneğin amacının satır (blok) halinde okumayı göstermek olduğunu söyledi.
- **Blok düzeyinde kopyalama (Örnek 3).** Dosya sistemi diskten zaten sabit boyutlu bloklar halinde okur; seçilen blok boyutu başarımı biraz etkileyebilir, ama derste başarıma odaklanılmadı. `fread(block, sizeof(DATA), BLOCKSIZE, fp1)` en çok `BLOCKSIZE` eleman okur ve okuduğu sayıyı döndürür. Hoca bir öğrencinin sorusu üzerine bunu bir tabloyla açıkladı (ekrandan, 00:55:00). Kaynak dosya 6 tam 1024 baytlık blok ve sonda 512 bayttan oluşsun, blok boyutu 1024 olsun. İlk 6 okumada 1024'er bayt okunur ve döngü içinde yazılır. 7. okumada 512 bayt gelir. $512 \neq 1024$ olduğu için döngüden çıkılır ve bu 512 bayt döngü içinde yazılmamış olur. Bu yüzden döngüden sonraki ek `fwrite` satırı gereklidir. Toplam boyut $6 \times 1024 + 512 = 6656$ bayttır. Dosya boyutu blok boyutunun tam katıysa son okuma 0 eleman döndürür ve 0 elemanlık yazma sorun çıkarmaz; hoca da bu durumda kodun çalışacağını düşündüğünü söyledi.
  - Slayttaki blok döngüsü kodu karelerde görünmedi. Aşağıdaki tam program ajan tarafından anlatıma göre kuruldu (derste bu biçimde gösterildiği doğrulanamadı) ve `gcc -Wall` ile derlendi, uyarısız. 6656 baytlık ve 7000 baytlık rastgele ikili dosyalarla denendi; iki kopya da kaynakla bayt bayt aynı çıktı.

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

- Ders sonrası notlar:
  - Hoca `fwrite`'ın bir şey döndürmediğini söyledi ve slaytta da `void fwrite(...)` yazıyor (ekrandan, 00:45:00). Standart C'de `fwrite` `size_t` döndürür: başarıyla yazılan eleman sayısı. Yazmanın başarısı bu değerle denetlenebilir.
  - Hoca `fread`'in döndürdüğü değeri anlatırken eleman sayısıyla `sizeof` çarpımından da söz etti. `fread` bayt sayısını değil, okunan **eleman** sayısını döndürür. Örnekte eleman `char` olduğu için ikisi aynıdır.
  - `fgets(line, LINESIZE-1, fp1)` çağrısında `fgets` en çok `LINESIZE-2` = 98 karakter okur, çünkü `n` argümanından bir eksik okur ve `'\0'` için yer bırakır. Hoca 99 karakter okunacağını söyledi. `fgets(line, LINESIZE, fp1)` yazmak yeterli ve güvenlidir.
  - Hoca ikili güncelleme kiplerinin `wb+` biçiminde yazılması gerektiğini söyledi. Standarda göre `r+b`/`rb+`, `w+b`/`wb+` ve `a+b`/`ab+` yazımlarının ikisi de geçerlidir.
  - Hoca `a+` kipinde de geriye gidilemeyeceğini söyledi. Slayttaki tabloya göre `a+` kipinde dosyanın her yerinden okunabilir; yalnız yazma her zaman dosya sonuna yapılır (ekrandan, 01:20:00).
  - Hoca okuma-yazma arası geçişi anlatırken `fflush`'tan sonra dosyayı kapatıp öbür kipte açmaktan da söz etti. Standarda göre `+` kiplerinde yazmadan okumaya geçerken `fflush` ya da konumlandırma (`fseek`, `rewind`), okumadan yazmaya geçerken konumlandırma gerekir. Giriş akışında `fflush` tanımsızdır.
  - Örnek 1'deki fazladan karakter `getc`'nin döndürdüğü `EOF` değerinin (`-1`) `putc` ile bayta çevrilip yazılmasıdır. Bu ajanın denemesinde 40 baytlık bir metin dosyası 41 bayt olarak kopyalandı, son bayt `0xFF`. PDF kopyasının sonuna da büyük olasılıkla aynı bayt eklendi, ama PDF okuyucusu bunu tolere etti. Döngünün `int c; while ((c = getc(fp1)) != EOF) putc(c, fp2);` biçimi bu sorunu yaşamaz; hocanın uyardığı tehlike, okunan değerin `char` değişkende tutulup `EOF` ile karşılaştırılmasıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
