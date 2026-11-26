# Ders 12 Çalışma Özeti

## Genel Konular

- Özyineleme (recursion)
  - Özyinelemeli fonksiyon kendi kendini çağıran fonksiyondur. Bu C'ye özgü değil, genel bir programlama stratejisidir (ekrandan, 00:10:00).
  - Slayttaki örnekte `recurse()` fonksiyonu içinde `static` bir sayaç yazdırılıp artırılır ve fonksiyon yeniden çağrılır. Kod görünüşte sonsuza kadar çağrı yapar; gerçekte her çağrı yığın (stack) belleğine dönüş bilgisi yazdığı için yığın dolunca program çalışma zamanı hatasıyla durur. Derste deneme bilgisayarında yaklaşık 43 bin iç içe çağrıdan sonra durdu.
  - Bu yüzden her özyinelemeli fonksiyonda bir durma noktası (temel durum, base case) olmalıdır.
  - Özyineleme özellikle böl ve yönet (divide and conquer) ve azalt ve yönet algoritmalarında işe yarar: problem küçük parçalara bölünür, parçalar çözülür, çözümler birleştirilir.
  - Örnekler: işlem ağacının (A*B + X/Y) prefix (preorder) gezilmesi, faktöriyel, ikili arama, derinlik öncelikli arama (DFS).
- Faktöriyelin açılımı
  - `fact(5)` → `5 * fact(4)` → `4 * fact(3)` → ... → `fact(1) = 1`. Temel duruma ulaşınca değerler geri dönerken çarpılır: 1, 2, 6, 24, 120.
- Sayının rakamlarını özyinelemeyle yazdırma
  - Yinelemeli sürüm: `x % 10` son basamağı verir, `x / 10` tamsayı bölmesiyle son basamağı atar; döngü sayı 0 olana kadar sürer.
  - Özyinelemeli sürüm: sayı 0 ise `return`; değilse `x % 10` yazdırılır ve fonksiyon `x / 10` ile yeniden çağrılır. Rakamlar tersten (birler basamağından başlayarak) yazılır.
- $x^y$ hesaplamanın dört yolu ve karmaşıklıkları (ekrandan, 00:25:00)
  - `power1`: 1'den $y$'ye kadar döngüyle $y$ kez çarpma, $O(n)$.
  - `power2`: $x \cdot x^{y-1}$ özyinelemesi, $T(n) = T(n-1) + 1$, yine $O(n)$.
  - `power3`: $x^{y/2}$ iki kez ayrı ayrı hesaplanır (`power3(x,y/2)*power3(x,y/2)`). $T(n) = 2T(n/2) + 1$; ana teoremde $a=2, b=2, d=0$ olduğundan yine $O(n)$. Aynı değeri iki kez hesapladığı için böl ve yönet olduğu halde verimsizdir.
  - `power4`: $x^{y/2}$ bir kez hesaplanıp `result` değişkeninde tutulur; çift kuvvette `result*result`, tek kuvvette `x*result*result` döner. $T(n) = T(n/2) + 1$, $a=1, b=2, d=0$, sonuç $O(\log n)$.
- Fonksiyon işaretçileri
  - Bir fonksiyon adıyla çağrılabildiği gibi adresi üzerinden de çağrılabilir. Tanım: `int (*pf)(int);` Yıldızlı ad paranteze alınmazsa (`int *pf(int);`) bu, `int*` döndüren bir fonksiyon bildirimi olur.
  - İşaretçinin dönüş türü ve parametreleri, göstereceği fonksiyonun prototipiyle uyumlu olmalıdır. `int` döndüren fonksiyon için `int` döndüren işaretçi kullanılır; `char` ya da `float` döndüren fonksiyon bu işaretçiye atanamaz.
  - Atama yalnız `pf = f1;` biçiminde yapılır. `pf = f1();` (fonksiyonu çağırıp sonucunu atar), `pf = &f1();` ve benzeri yazımlar derste yanlış olarak gösterildi.
  - Çağrı: `answer = (*pf)(n);` (ekrandan, 00:30:00).
  - Fonksiyon işaretçisi parametre olarak aktarılabilir: genel bir `sumGeneric(fp, x, y)` fonksiyonu $x$'ten $y$'ye kadar `fp(i)` değerlerini toplar. `fp` yerine `selfI` (sayının kendisi) verilirse sayılar, `squareI` verilirse karelerin toplamı bulunur. Sıralamada artan/azalan karşılaştırma fonksiyonu seçmek de aynı fikirdir.
  - Fonksiyon işaretçisi dizisi: `int (*p[4])(int, int);` gibi bir diziye toplama, çıkarma, çarpma vb. fonksiyonlar atanır; kullanıcının seçtiği işlem `p[islem](i, j)` ile çağrılır.
- void işaretçiler
  - `void *` her türden işaretçiye dönüştürülebilir; bu sayede genel (generic) fonksiyonlar yazılabilir. `malloc`'un `void *` döndürmesi bu yüzdendir.
  - Değere ulaşmak için önce uygun türe dönüştürmek gerekir: `*(int *)ptr = 10;`, `*(float *)ptr = 3.4;`, `*(char *)ptr`.
  - Thread'lere parametre gönderirken de `void *` kullanılır.
- Dosya işlemleri (I/O): genel kavramlar (ekrandan, 00:35:00-00:50:00)
  - İşletim sistemleri dosya ve aygıtlara farklı biçimlerde erişir. C, taşınabilirlik için G/Ç'yi bir dizi çalışma zamanı rutiniyle yapar; bunların bir kısmı UNIX G/Ç kütüphanesinden gelir.
  - C kütüphanesi çoğunlukla tamponlu (buffered), UNIX kütüphanesi tamponsuz G/Ç yapar. UNIX ikili ve metin dosyalarını aynı görür; diğer bazı sistemlerde ayrım önemlidir. ANSI kütüphanesinde bütün G/Ç fonksiyonları tamponludur.
  - Akış (stream): program ile dosya/aygıt arasındaki kanal. Her programda üç standart akış otomatik açılır: `stdin`, `stdout`, `stderr`. `printf` `stdout`'a yazar, `scanf` `stdin`'den okur. Bir akış dosyaya yönlendirilebilir; daha kolay yol `fprintf` ve `fscanf` ile akışı açıkça belirtmektir.
  - Dosya, verinin program kapandıktan sonra da kalıcı olması için gerekir (RAM geçicidir).
- Metin ve ikili biçim
  - Metin akışı satırlardan oluşur, her satır `'\n'` ile biter. Bazı sistemler (örneğin birçok IBM sistemi) satırları her satırın başını gösteren işaretçi diziniyle tutar; bu dosyalar metin kipinde okunurken çalışma zamanı fonksiyonları satır sonlarını kendisi ekler.
  - Metin dosyası açılınca içeriği okunabilir; ayırıcı karakterlerle (virgül, noktalı virgül) biçim belirlenir ve dosya nasıl yazıldıysa öyle okunur. İkili dosya içeriği kodlu görünür, daha az yer kaplar.
- `FILE` yapısı, dosya işaretçisi ve dosya konum göstergesi
  - `stdio.h` içinde tanımlı `FILE` yapısı dosya adı, erişim kipi, sıradaki karakterin konumu gibi alanlar tutar. Programda `FILE *fp;` tanımlanır.
  - Dosya işaretçisi (file pointer) açık bir akışı tanımlar. Dosya konum göstergesi (file position indicator) akıştaki sıradaki karakterin bayt konumunu gösterir. İkisi karıştırılmamalıdır (ekrandan, 00:50:00).
  - `stdio.h` ayrıca `stdin`, `stdout`, `stderr`, `EOF` ve `NULL` makrolarını tanımlar.
- `fopen` ve erişim kipleri (ekrandan, 01:05:00)
  - `fopen(dosya_adi, kip)` iki argüman alır. Başarılıysa `FILE *`, açılamazsa `NULL` döner.
  - `"r"`: okuma, dosya yoksa açılamaz. `"w"`: yazma, dosya yoksa oluşturulur, varsa içi silinir. `"a"`: ekleme, her zaman dosya sonuna yazılır.
  - `"r+"`: var olan dosyayı okuma ve yazma için açar. `"w+"`: okuma-yazma, dosya yoksa oluşturur. `"a+"`: okuma her yerden, yazma dosya sonundan.
  - Kipin sonuna `b` eklenirse (`"rb"`, `"wb"`) ikili, eklenmezse metin kipidir.
  - Göreli dosya adı programın çalıştığı klasöre göre aranır.
- Okuma ve yazma kuralları (ekrandan, 01:15:00)
  - Bir akıştan okuduktan sonra araya `fseek`, `rewind` ya da `fflush` çağrısı girmeden yazılamaz; yazmadan okumaya geçerken de aynı kural geçerlidir.
  - Aynı dosya hem girdi hem çıktı olacaksa okunan dosya yazmadan önce kapatılmalıdır. Dosya `fclose(fp)` ile kapatılır.
- Karakter G/Ç (ekrandan, 01:20:00)
  - `getc`/`putc` genellikle makro, `fgetc`/`fputc` fonksiyondur. Makrolar dallanma olmadığı için yaklaşık iki kat hızlıdır.
  - Makrolar yan etkiye açıktır (`putc('x', fp[j++])` tehlikelidir). Argümanda yan etkili işleç varsa `fgetc`/`fputc` kullanılmalıdır.
  - İkili dosyayı karakter karakter kopyalarken döngü `feof(fp1)` ile kontrol edilir. `getc` dönüşünü `EOF` ile karşılaştırmak ikili dosyada güvenilir değildir, çünkü okunan bir bayt `EOF` değerine eşit olabilir (ekrandan, 02:15:00).
- Satır G/Ç
  - `fgets(line, LINESIZE - 1, fp)`: `'\n'`, dosya sonu ya da en çok karakter sayısına ulaşınca durur, sonuna `'\0'` ekler; dosya sonunda `NULL`, aksi halde ilk argümanı döndürür.
  - `fputs(line, fp)`: satırı dosyaya yazar. `fgets`'te dosya yerine `stdin` verilirse klavyeden okunur.
- Blok G/Ç (ekrandan, 01:30:00)
  - `fread(ptr, boyut, adet, fp)` ve `fwrite(ptr, boyut, adet, fp)`. Hedef/kaynak `void *` olduğu için yapı, dizi ya da string verilebilir. Boyut genelde `sizeof` ile verilir.
  - `fread` okunan eleman sayısını döndürür; hata ya da EOF yoksa bu, 3. argümana eşittir. `fwrite` aynısının yazma yönündeki aynasıdır.
  - Sabit disk RAM'den çok yavaştır; karakter karakter gidip gelmek yerine bir seferde büyük blok okumak/yazmak tercih edilir. Bir yapı değişkeni tek `fwrite` ile bütün olarak yazılıp okunabilir; bunun için okuma ve yazma biçimi aynı olmalıdır.
  - Blok boyutu aygıt G/Ç sayısını değiştirmez: tampon 1024 bayt, istenen blok 512 bayt ise işletim sistemi yine 1024 bayt getirir; sonraki `fread` kalan 512 baytı diske gitmeden bellekten alır.
- Rastgele erişim: `fseek` ve `ftell` (ekrandan, 01:35:00)
  - `fseek(fp, offset, kaynak)`; kaynak `SEEK_SET` (baş), `SEEK_CUR` (bulunulan yer), `SEEK_END` (son).
  - `fseek(fp, 10, SEEK_SET)` göstergeyi 10. karaktere götürür; akış 0'dan başladığı için bu 11. karakterdir. Başarılıysa 0, değilse 0'dan farklı değer döner.
  - Salt okunur dosyada `SEEK_END` ile offset ≤ 0, `SEEK_SET` ile offset ≥ 0 olmalıdır; gösterge dosyanın dışına itilmemelidir.
  - `ftell` göstergenin bulunduğu konumu döndürür.
  - Örnek: kişi kayıtları dosyasından yalnız isim alanları `fread` ile okunur, her adımda `offset += sizeof(PERSONALSTAT)` ve `fseek(..., offset, SEEK_SET)` ile sonraki kaydın başına atlanır; isimler indeks dizisinde sıralanıp kayıtlar bu sırayla `fseek` + `fread` ile yazdırılır (ekrandan, 01:40:00).
- Dosya yönetim fonksiyonları (ekrandan, 01:45:00)
  - `remove` (dosya siler), `rename` (adını değiştirir), `tmpfile` (geçici ikili dosya oluşturur), `tmpnam` (geçici dosya için ad üretir).
- Programın bellek düzeni
  - Düşük adresten yükseğe: kod (text), ilk değer atanmış global/statik veri, ilk değer atanmamış global/statik veri, heap, yığın (stack) ve en üstte komut satırı argümanları.
  - Yığın: yerel değişkenler, fonksiyon parametreleri ve dönüş adresi. Heap: `malloc`/`realloc` ile alınan alanlar; `free` ile serbest bırakılır.
  - Yer ayrılmamış bir işaretçiye (`struct ogr *ptr;`) `fread` ile veri okunamaz; işaretçi önce `malloc` ile ayrılmış bir alanı göstermelidir.
- Makefile ve derleme otomasyonu (ekrandan, 02:45:00)
  - Çok dosyalı projede her dosyayı her seferinde `gcc` ile ayrı derlemek yerine `make` ve Makefile kullanılır.
  - Kural yapısı `hedef: bağımlılıklar` ve altında komut. Örnek: `program: deneme.o main.o` → `gcc deneme.o main.o -o program.exe`; `deneme.o:` → `gcc -c deneme.c -o deneme.o`.
  - `make` yalnız değişen dosyaları yeniden derler (bağımlılık grafiği). Dev-C++ proje derlerken kendi Makefile'ını üretir; bunda `CC`, `OBJ`, `LIBS` gibi makrolar, `all-before`, `all-after` ve `clean` hedefleri bulunur.
  - CMake daha genel bir derleme otomasyonu (build automation) aracıdır; farklı IDE'ler ve derleyicilerle ortak bir projeyi derlemeyi kolaylaştırır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Özyinelemede temel durum
  - Temel durum yazılmazsa yığın dolar ve program çöker. `malloc` sonrası NULL kontrolü gibi, yığında da sınırlı yer vardır.
- Aynı değeri iki kez hesaplayan özyineleme
  - `power3` böl ve yönet olduğu halde $O(n)$'de kalır; ara sonuç bir değişkende saklanınca (`power4`) $O(\log n)$ olur.
- Fonksiyon işaretçisinde tür uyumu ve parantez
  - `(*pf)` paranteze alınmalı ve işaretçinin türü fonksiyonun prototipine uymalıdır.
- Dosya hangi biçimde yazıldıysa öyle okunur
  - Karakter, satır ya da blok okumadan hangisinin seçileceği probleme bağlıdır. Yapı verisi için blok G/Ç en uygunudur.
- Kip seçimi
  - Okuma kipinde açılan dosyaya yazmak bazı sistemlerde çalışsa da yanlıştır; Linux gibi sistemlerde hata verir. Hangi işlem yapılacaksa o kip kullanılmalıdır.
- Bellek bölgelerini bilmek
  - Bilgisayar mühendisi programın belleğinin stack, heap ve veri bölgelerine nasıl ayrıldığını bilmelidir. Önce yer açılır, sonra işaretçi oraya yöneltilir.
- Makefile ve CMake öğrenilmeli
  - Gömülü sistemler, robotik ve düşük seviyeli programlamada IDE olmadan Makefile ile derlemek gerekebilir.

## Kısa Tekrar Notları

- Özyineleme = kendini çağıran fonksiyon + mutlaka temel durum.
- Her çağrı yığına dönüş adresi ve parametre yazar; temel durum yoksa yığın taşar.
- $x^y$: döngü $O(n)$, $x\cdot x^{y-1}$ $O(n)$, iki ayrı $x^{y/2}$ $O(n)$, tek $x^{y/2}$ saklanırsa $O(\log n)$.
- `int (*pf)(int); pf = f1; sonuc = (*pf)(n);`
- Fonksiyon işaretçisi parametre ya da dizi olarak kullanılabilir (genel toplam, işlem menüsü, sıralama yönü).
- `void *` genel işaretçidir; kullanmadan önce `(int *)` gibi dönüştürülür.
- Üç standart akış: `stdin`, `stdout`, `stderr`.
- `fopen` kipleri: `r`, `w`, `a`, `r+`, `w+`, `a+`; `b` eklenirse ikili.
- `fopen` başarısızsa `NULL` döner; her zaman kontrol edilir.
- Okuma ile yazma arasında `fseek`, `rewind` ya da `fflush` gerekir.
- `getc`/`putc` makro (hızlı, yan etkiye açık), `fgetc`/`fputc` fonksiyon.
- `fgets`/`fputs` satır, `fread`/`fwrite` blok G/Ç.
- `fseek(fp, 10, SEEK_SET)` → 11. karakter; başarıda 0 döner. `ftell` konumu verir.
- `remove`, `rename`, `tmpfile`, `tmpnam` dosya yönetim fonksiyonlarıdır.
- Yerel değişkenler stack'te, `malloc` alanları heap'te; ilk değerli ve ilk değersiz global/statikler ayrı bölgelerde.
- Makefile: `hedef: bağımlılıklar` + komut; yalnız değişen dosyalar yeniden derlenir.

## Detaylı Açıklamalar

- Özyinelemenin çalışma düzeni
  - Program başladığında `main` yığına yüklenir. Her fonksiyon çağrısında o çağrının parametreleri, yerel değişkenleri ve dönüş adresi yığına eklenir; fonksiyon bitince bu kayıt çıkarılır ve program kaldığı yerden devam eder. Slayttaki `recurse()` örneğinde temel durum olmadığı için çağrılar birikir ve yığın bitince program çöker. Derste bu kod çalıştırıldı ve sayaç yaklaşık 43 bin değerinde durdu; bu sayı bilgisayara ve yığın boyutuna göre değişir.
  - İşlem ağacında prefix gezinti "önce kök, sonra sol alt ağaç, sonra sağ alt ağaç" kuralıyla yapılır. `A*B + X/Y` ağacında kök `+`'dır; sol alt ağaç kendi içinde yeni bir köktür (`*`, A, B), sağ alt ağaç da öyledir (`/`, X, Y). Sonuç `+ * A B / X Y` olur. Her alt ağaçta aynı işin tekrarlanması problemi doğal olarak özyinelemeli yapar.
  - DFS'te bir düğümden komşusuna, oradan onun komşusuna derinlemesine gidilir; geri dönüşte yığın mantığı kullanılır.
- `power4` kodu (ekrandan, 00:25:00)

```c
int power4(int x, int y){// T(N) = T(N/2) + 1 a=1, b=2, d=0 ==> O(logN)
    int result;
    if(y == 0)
        return 1;
    result = power4(x,y/2);
    if(y % 2 == 0)
        return result*result;
    else
        return x*result*result;
}
```

  - Aynı ekranda `power3`'ün tek kuvvet satırı `return x*power3(x,y/2)*power3(x,y/2);` olarak görünüyor. Fonksiyon küçük bir `main` ile `gcc -Wall` altında derlendi; $3^0$ ile $3^7$ arası ve $2^{10} = 1024$ için `power3` ile `power4` aynı sonucu verdi.
  - Örneğin $x^6$ için iki tane $x^3$, $x^7$ için iki tane $x^3$ ve bir $x$ gerekir. `power4` $x^3$'ü bir kez hesaplayıp karesini alır.
- Fonksiyon işaretçisiyle çağrı (ekrandan, 00:30:00)

```c
#include <stdio.h>
extern int f1(int); //could be defined externally but we have coded it below
int main() {
    int n;
    int (*pf) ();
    int answer;
    printf("Bir sayi giriniz: "); scanf("%d",&n);

    pf=f1;
    answer=(*pf)(n); // calls f1() with argument a => f1(a)

    printf("%d", answer);
    return 0;
}
int f1( int a ) {
    return a+1;
}
```

  - Kod `gcc -std=c11 -Wall` ile derlenip 5 girdisiyle çalıştırıldı, çıktı 6.
  - **Ders sonrası not:** Slayttaki `int (*pf) ();` bildirimi eski C standartlarında "parametreleri belirtilmemiş" anlamına gelir. Güncel GCC'nin varsayılan standardında (C23) `()` "parametre yok" demektir ve kod derlenmez. `int (*pf)(int);` yazmak her standartta doğrudur; bu biçimle de derlenip aynı sonuç alındı.
- Dosyaya yazma denemesi (ekrandan, 01:10:00)
  - Derste önce `FILE *fp;` tanımlanıp `fprintf(fp, "%d %s", 123, "abc");` yazıldı ve dosya açılmadan yazmanın hata vereceği söylendi. Sonra `fp = fopen("emp.txt", "w+");` eklendi; ekranda bir an değişken adı `fptr` yazılı kaldı, hoca bunu `fp` olarak düzeltti. Çalıştırınca program klasöründe `emp.txt` oluştu ve içinde `123 abc` yazıldı.
  - Ardından kip `"r"` yapılıp `if (fp == NULL) printf("Dosya yok");` kontrolü eklendi (ekrandan, 02:25:00). Hocanın Windows'taki denemesinde okuma kipinde açılan dosyaya `fprintf` yine yazdı; hoca bunun doğru kullanım olmadığını ve Linux gibi sistemlerde hata alınacağını söyledi.
- Hata mesajını `stderr`'e yazma (ekrandan, 01:50:00)
  - `open_file1()` sabit adlı `"test"` dosyasını `"r"` kipinde açar; açılamazsa `fprintf(stderr, "Error opening file test\n");` yazar ve `fp`'yi döndürür.
  - `open_file2(char* file_name, char* access_mode)` dosya adını ve kipi kullanıcıdan alır. Derste var olmayan bir dosya adı `"r"` ile verilince hata `stderr` kanalından yazıldı; aynı ad `"w+"` ile verilince dosya oluşturuldu.
- Kopyalama fonksiyonlarının üç sürümü (ekrandan, 02:15:00 ve 02:20:00)
  - Sürüm 1 (karakter karakter, ikili kip): `while (!feof(fp1))` döngüsünde `getc(fp1)` ile alınan karakter `putc` ile `fp2`'ye yazılır. Derste kopyada dosya sonunda fazladan anlamsız bir karakter görüldü.
  - Sürüm 2 (satır satır): `fgets(line, LINESIZE - 1, fp1)` `NULL` dönene kadar okunur ve `fputs(line, fp2)` ile yazılır. Derste döngüye bir sayaç (`x++`) eklenip fonksiyonun bunu döndürmesi sağlandı; satır boyutu küçültülünce okuma sayısı arttı.
  - Sürüm 3 (blok): `fopen(infile, "rb")`, `fopen(outfile, "wb")`, `char block[BLOCKSIZE];` ve `fread(block, sizeof(DATA), BLOCKSIZE, fp1)` ile bir seferde 512 bayt okunup `fwrite` ile yazılır. İkinci dosya açılamazsa önce ilk dosya kapatılıp `FAIL` döndürülür.
- Kayıtları isme göre sıralı yazdırma (rastgele erişim örneği, ekrandan, 01:40:00)
  - `get_records` fonksiyonu her kişi kaydının yalnız ilk `NAME_LEN` baytlık isim alanını `fread(namei, 1, NAME_LEN, data_file)` ile okur, `strcpy` ile indeks dizisine koyar, `offset += sizeof(PERSONALSTAT);` ve `fseek(data_file, offset, SEEK_SET);` ile sonraki kaydın başına atlar. Döngü `counter < max_rec_num && nm == NAME_LEN` olduğu sürece döner.
  - Sonra indeks dizisi `strcmp` ile (derste quicksort ile) sıralanır ve her indeks için `fseek` ile ilgili kayda gidilip bir `PERSONALSTAT` `fread` ile okunur ve yazdırılır.
- Yer ayrılmamış işaretçiye okuma hatası (ekrandan, 02:25:00)
  - Ekrandaki `struct ogr *ptr; fread(ptr, sizeof(struct ogr), 1, fp);` satırları yanlıştır, çünkü `ptr` henüz geçerli bir adresi göstermez. Doğrusu önce `malloc` ile alan ayırıp işaretçiyi oraya yöneltmektir.
  - **Ders sonrası not:** Ekranda `struct ogr Ogr=malloc(N*sizeof(struct ogr));` yazıyor. `malloc` adres döndürdüğü için değişken işaretçi olmalıdır: `struct ogr *Ogr = malloc(N * sizeof(struct ogr));`. Hoca da konuşurken "tabii şurada da pointer olacak" dedi. Burada iki bellek bölgesi kullanılır: veri heap'te, onu gösteren `Ogr` işaretçisi stack'tedir.
- Makefile örneği (ekrandan, 02:45:00)
  - Derste `deneme.c`, `deneme.h` ve `main.c` dosyalarından oluşan küçük bir proje için elle Makefile yazıldı. Ekranda görülen ilk satırlar `programcalistir: program calistir`, `program: deneme.o main.o` ve `gcc deneme.o main.o -o program.exe` biçimindedir. Hoca konuşurken `deneme.o` kuralını `gcc -c deneme.c -o deneme.o`, `main.o` kuralını `gcc -c main.c -o main.o` olarak tamamladı ve `calistir` hedefinin `program.exe`'yi çalıştırdığını söyledi.
  - `make -f Makefile.win` ile çalıştırınca önce `deneme.o`, sonra `main.o` derlendi, bağlandı ve program çalıştı. Yalnız `deneme.c` değiştirilip yeniden çalıştırılınca `main.c` yeniden derlenmedi.
  - <!-- BELİRSİZ: Makefile'ın son hali ekranda tam görülmedi; `calistir` hedefinin komutu ve `.o` hedeflerindeki bağımlılıklar altyazıdan kuruldu. -->
  - Windows'ta `gcc` ve `make`'in her klasörden çalışması için derleyicinin `bin` klasörü ortam değişkenlerindeki `PATH`'e eklenir. Dev-C++ ile gelen `make` programının adı farklıdır. <!-- BELİRSİZ: Altyazıda "1032 make.exe" geçiyor; büyük olasılıkla `mingw32-make.exe`. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
