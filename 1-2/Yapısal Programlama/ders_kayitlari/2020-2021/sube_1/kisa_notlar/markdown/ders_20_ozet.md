# Ders 20 Çalışma Özeti

## Genel Konular

- Bit alanlı (bit field) yapı ile bağlı liste örneği
  - Önceki haftanın çalışan bağlı listesi bu kez bit alanlı bir yapıyla kuruldu. Yapıda ad (`char ps_name[20]`), TC kimlik numarası (`char ps_tcno[11]`) ve doğum tarihi için üç bit alanı var: `unsigned int ps_birth_day : 5; ps_birth_month : 4; ps_birth_year : 11;` (ekrandan, 00:15:00).
  - Gün en çok 31 olduğu için 5 bit ($2^5 = 32$), ay en çok 12 olduğu için 4 bit ($2^4 = 16$), yıl için 11 bit ($2^{11} = 2048$) yeter.
  - TC kimlik numarası her zaman 11 hanedir, bu alanda israf olmaz. Ad alanında kısa adlar için israf olur.
  - Bit alanının adresi alınamaz. Bu yüzden değer önce geçici bir `int val` değişkenine okunur, sonra alana atanır: `scanf("%u", &val); p->ps_birth_day = val;` (ekrandan, 00:25:00 ve 01:20:00).
  - Bit alanları `unsigned int` olduğundan ekrana `%u` ile yazdırılır.
  - Düzeltme ve deneme sırasında çıkan derleme hatası eksik bir süslü paranteze bağlıydı; bir öğrenci fark etti.
- Bit alanı yapı dışında kullanılabilir mi?
  - Hoca: bit alanı sözdizimi yalnız yapı içinde kullanılır.
  - Aynı sıkıştırma istenirse, örneğin `long int` türünde bir değişken alınır ve 5+4+11 = 20 bit bitsel işlemlerle elle yerleştirilir. Bitlerin sola mı sağa mı yaslanacağına programcı karar verir, her alan için ayrı okuma fonksiyonu yazar. Kod uzar ama çok kısıtlı bellekte her bit önemliyse buna değer.
- Birlik (union) kavramı
  - Union, aynı bit alanını (bellek bölgesini) duruma göre farklı biçimlerde yorumlamayı sağlar. Böylece aynı veri yapısı farklı türden veriler taşıyabilir.
  - Slayt örneği (ekrandan, 00:40:00): `typedef union { struct { char c1, c2; } s; long j; float x; } U; U example;`
  - Union için en geniş üyeyi alacak kadar bellek ayrılır. Slaytta `long` ve `float` 4 bayt, iki `char` 2 bayttır; alan 4 bayttır.
  - `example.s.c1 = 'a'; example.s.c2 = 'b';` ilk iki bayta yazar. `example.j = 5;` ise 4 baytın hepsini kullanır ve iki karakterin üzerine yazar.
  - Union içindeki her satır, o alanın ayrı bir yorumlanma biçimidir. Üyeler aynı anda değil, biri ya da öteki olarak kullanılır.
- Yapı içinde union: gerçek hayat örneği
  - Çalışan kaydına şu bilgiler eklenmek istendi: TC vatandaşı mı? Vatandaşsa doğum şehri, değilse uyruğu. Yabancılar için TC kimlik alanına pasaport numarası yazılır (ekrandan, 00:45:00).
  - İlk tasarımda `char nationality[20]` ve `char city_of_birth[20]` ayrı alanlardır. Her kayıtta bunlardan biri tümüyle boşa gider.
  - Daha iyi tasarım: `unsigned int TCcitizen : 1;` bayrağı union dışında tutulur, iki dizi `union { char nationality[20]; char city_of_birth[20]; } location;` içinde birleşir (ekrandan, 01:05:00). 20 bayt kazanılır. Bir bitlik alan hizalama yüzünden birkaç bayt kaybettirse de toplamda kazanç vardır.
  - Bayrak union içine konamaz. Union'da aynı anda tek yorum geçerlidir, ama bayrağın her zaman şehir ya da uyruk bilgisinin yanında durması gerekir.
  - Doğum tarihi ayrı bir `DATE` yapısına çıkarıldı. Erişim `p->ps_birth_date.day` biçimindedir: `p` işaretçi olduğu için ok, `ps_birth_date` işaretçi olmadığı için nokta kullanılır.
  - Ekleme fonksiyonunda "Is this a Turkish citizen? (y/n)" sorulur; `n` ya da `N` ise uyruk, değilse doğum şehri okunur ve `TCcitizen` 0 ya da 1 yapılır (ekrandan, 01:20:00).
  - Yazdırma fonksiyonu `TCcitizen == 1` ise "Turkish Employee ... born in ... in <şehir>", değilse "<uyruk> Employee ... born in ..." yazar (ekrandan, 01:30:00).
- Özyineleme (recursion)
  - Kendini çağıran fonksiyondur. Bir örnekte fonksiyon içinde `static` bir sayaç vardı. `static` değişken çağrılar arasında değerini korur, bu yüzden her çağrıda 1, 2, 3, ... yazılır. Durma noktası olmadığı için yığın bellek bitene kadar sürer ve program hatayla durur.
  - Yığın düzeni (ekrandan, 01:40:00): `main()` başlayınca yerel değişkenleri için yığında yer ayrılır. `main` `func1()`'i çağırınca `func1`'in parametreleri ve yerel değişkenleri yığının üstüne eklenir. `func1` dönünce bu alan bırakılır. Yığın alanı yeniden kullanıldığı için içinde önceki kullanımdan kalan çöp değerler bulunur.
  - Faktöriyel (ekrandan, 01:45:00): `n <= 1` ise 1 döner (durma noktası), değilse `n * fact(n-1)`. `fact(5)` çağrıları 5'ten 1'e iner, dönüşte 1, 2, 6, 24, 120 elde edilir.
  - Faktöriyel hızlı büyür. `fact(15)` ekranda `2004310016` verdi (ekrandan, 01:50:00); gerçek değer 13 basamaklıdır. Program çökmez ama sonuç yanlıştır.
  - Ödev olarak önerilenler: Fibonacci sayıları ($F_{n+1} = F_n + F_{n-1}$), ikili arama, derinlik öncelikli arama.
- Fonksiyon işaretçileri
  - Fonksiyonları bir değişken gibi başka yerlere aktarmayı sağlar; kodlamaya esneklik getirir.
  - Tanım: `int (*pf)();` "int döndüren bir fonksiyona işaretçi" demektir. `*pf` etrafındaki parantez gereklidir; `int *pf();` int işaretçisi döndüren bir fonksiyon bildirimidir (ekrandan, 02:05:00).
  - Dönüş türü uyuşmalıdır (ekrandan, 02:10:00): `pif = if1;` ve `pcf = cf1;` geçerli; `pif = cf1;` ve `pff = if2;` tür uyuşmazlığı; `if1 = if2;` geçersiz, çünkü fonksiyon adı sabittir.
  - Örnek (ekrandan, 02:15:00): `pf = f1; answer = (*pf)(n);` çağrısı `f1(n)` ile aynıdır. Derste `f1` (bir artırır), `f2` (bir azaltır) ve iki parametreli `f3` (toplar) aynı işaretçiyle çağrıldı. 5 ve 3 girişi için 6, 4 ve 8 çıktı.
  - Kullanım alanı: farklı türlere hitap eden genel (jenerik) kod. Örnek: farklı veri türü tutan bağlı listeleri tek bir dolaşma ve listeleme fonksiyonuyla işlemek. Hoca bu örneği yeterli bulmadı.
- Dosya giriş-çıkışına (I/O) giriş
  - İşletim sistemleri dosya ve aygıtlara erişimde çok farklıdır. Bu yüzden taşınabilir I/O yazmak zordur (ekrandan, 02:25:00).
  - Tamponlu (buffered) ve tamponsuz (unbuffered) I/O. C kütüphanesi çoğunlukla tamponludur, UNIX kütüphanesi tamponsuzdur. ANSI kütüphanesinde bütün I/O fonksiyonları tamponludur, tampon boyu değiştirilebilir.
  - Metin ve ikili (binary) mod. UNIX iki türü aynı işler; bazı sistemlerde bu ayrım çok önemlidir. `.c` dosyası her baytı karakter olarak gösterilen bir metin dosyasıdır. Nesne (`.o`) ve yürütülebilir dosyada her bayt ayrı anlam taşır.
  - Akış (stream): kaynağı ve hedefi ne olursa olsun veri bir bayt dizisi olarak taşınır. Akışa erişim `stdio.h`'deki `FILE` türünden bir işaretçiyle yapılır.
  - Üç standart akış her programa otomatik açılır: `stdin` (normalde klavye), `stdout` (normalde ekran), `stderr` (hata çıktısı) (ekrandan, 02:40:00). `printf` `stdout`'a yazar, `scanf` `stdin`'den okur.
  - Akışlar `freopen()` ile dosyaya yönlendirilebilir. Daha kolay yol, akışı parametre olarak alan `fprintf()` ve `fscanf()` fonksiyonlarıdır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bit alanlarını düzenlerken toplamı 8 ya da 16'nın katına yaklaştırın, alanları dengeli dağıtın ("terazi dengesi").
  - Belleğe yerleşim derleyiciye, işletim sistemine ve işlemci mimarisine bağlıdır. Yalnız genel önlemler söylenebilir.
- Bitsel işlemlerden şikâyet eden C programcısı olmamalıdır.
  - Bit alanı yapı dışında yoktur; gerekirse aynı iş bitsel işlemlerle elle yapılır.
- Union = aynı bit alanını farklı biçimlerde yorumlamak.
  - Hangi yorumun geçerli olduğunu tutan bayrak union dışında saklanmalıdır.
- Özyinelemeli fonksiyona mutlaka uygun bir durma noktası konmalıdır.
  - Aksi halde yığın bellek tükenene kadar çağrı sürer.
- İlk değer atamanın önemi.
  - Hoca `TCcitizen` bayrağını yeniden adlandırmadı, ama sayısal alanlara ilk değer verilmezse yanlış varsayılan değerle karşılaşılabileceğini hatırlattı. Mantığın düz kurulması (1 = vatandaş) kodu okumayı kolaylaştırır.
- Fonksiyon işaretçisi tanımında dönüş türü bilinmelidir.
  - C türleri sıkı denetler; `char` döndüren fonksiyon `int` döndüren fonksiyon işaretçisine atanamaz.
- Hata ayıklamada adım adım ilerlemek en iyisidir.
  - Hoca kodu küçük adımlarla değiştirip her adımda derledi.

## Kısa Tekrar Notları

- Bit alanı: `unsigned int alan : bit_sayısı;`, yalnız yapı içinde.
- Bit alanının adresi alınamaz; `scanf` ile önce geçici değişkene oku, sonra ata.
- Union boyutu = en büyük üyenin boyutu; üyeler aynı belleği paylaşır, birine yazmak ötekini bozar.
- Yapı içinde union: ortak alanı birleştir, hangi yorumun geçerli olduğunu union dışındaki bir bayrakta tut.
- Yapı işaretçisinde `->`, yapı değişkeninde `.`; `p->ps_birth_date.day`.
- Özyineleme = kendini çağıran fonksiyon; her çağrıda yığına yeni çerçeve eklenir; durma koşulu şart.
- `fact(n) = n * fact(n-1)`, `fact(1) = 1`; `fact(5) = 120`.
- `int` taşması: büyük faktöriyeller yanlış sonuç verir, program çökmez.
- `int (*pf)();` fonksiyon işaretçisi; `int *pf();` int işaretçisi döndüren fonksiyon.
- `pf = f1; (*pf)(n);` ile `f1(n)` aynıdır; atamada dönüş türü uyuşmalıdır.
- `stdin`, `stdout`, `stderr`; `FILE *`; `fprintf`, `fscanf`; metin ve ikili mod; tamponlu ve tamponsuz I/O.

## Detaylı Açıklamalar

- **Bit alanlı bağlı liste.** Önceki haftanın çalışan listesi, `typedef struct Employee { char ps_name[20], ps_tcno[11]; unsigned int ps_birth_day : 5; unsigned int ps_birth_month : 4; unsigned int ps_birth_year : 11; struct personalstat *next; } EMPLOYEE;` biçimindeki bir yapıyla yeniden kuruldu (ekrandan, 00:15:00). Soyad alanı yerine TC kimlik numarası konuldu, doğum tarihi bit alanlarıyla eklendi. Listenin geri kalanı (`add_element`, `insert_after`, `delete_element`, `find`) önceki örnekle aynıdır (ekrandan, 00:10:00). Yalnız okuma kısmı değişti. `scanf` bir adres ister, bit alanının ise adresi yoktur. Bu yüzden `int val` geçici değişkeni kullanıldı. Hoca kodun yorumuna "ilkel ve bitfield olduğu için geçici değişken şart" yazmıştı (ekrandan, 01:20:00); derste bunun gerçekten gerekip gerekmediğinden emin olmadığını söyledi.
  > **Ders sonrası not:** Geçici değişken gerçekten gereklidir. `scanf("%u", &d.day);` gibi bir satır GCC'de `cannot take address of bit-field` hatası verir (ajan gcc -Wall ile denedi).
- **Bit alanını yapı dışında taklit etmek.** Bir öğrencinin sorusu üzerine hoca, bit alanı sözdiziminin yapı dışında kullanılmadığını söyledi. Aynı 20 bit, örneğin 32 bitlik bir `long int` içine bitsel işlemlerle yerleştirilebilir. Bu durumda gün, ay ve yıl için ayrı okuma fonksiyonları yazılır. Kod uzar ve zorlaşır, ama çok kısıtlı bellekte bir bitin bile önemi varsa buna değer.
- **Union örneği.** Slayttaki `U` birliği (ekrandan, 00:40:00) aynı 4 baytı üç biçimde yorumlar: iki karakterlik bir yapı (`s.c1`, `s.c2`), bir `long` (`j`) ve bir `float` (`x`). `example.s.c1 = 'a'; example.s.c2 = 'b';` sonrası ilk iki bayt dolar. Diğer iki bayt daha önce yazılmadıysa çöp değer taşır; bellek `calloc` ile ayrıldıysa sıfırdır. `example.j = 5;` ataması dört baytın hepsini kullanır ve iki karakteri siler. Bu iki karakter artık anlamsız (görünmeyen) karakterlere karşılık gelir.
  > **Ders sonrası not:** Hoca küçük `a`'nın ASCII kodunu "92 filandı galiba" dedi; doğrusu `'a'` = 97, `'b'` = 98 (büyük `A` = 65 doğru).

  > **Ders sonrası not:** Hoca `j = 5` sonrası iki karakterin de sıfır olacağını, öteki bayt sırasında ise `c2`'nin 5 olacağını söyledi. x86 gibi küçük sonlu (little-endian) işlemcide en düşük bayt ilk adrestedir, bu yüzden `c1` = 5, `c2` = 0 olur (ajan gcc ile denedi). Büyük sonlu (big-endian) bir işlemcide ilk iki bayt da 0 olur, 5 son baytta durur. Ayrıca 64 bit Linux'ta `long` 8 bayttır; slayttaki 4 baytlık hesap Windows ya da 32 bit sistem içindir.
- **Yapı içinde union.** Uyruk ve doğum şehri dizilerinin her ikisi de 20 bayttır, ama bir kayıtta yalnız biri anlamlıdır. Union ile birleştirilince 20 bayt kazanılır (ekrandan, 01:05:00). Derste yapı önce `DATE` adlı ayrı bir bit alanlı yapıya bölündü. Doğum tarihine erişim `p->ps_birth_date.day` biçimine dönüştü. Hoca bir yerde ok kullanıp hata aldı: `ps_birth_date` işaretçi olmadığı için nokta gerekir. Sonra `unsigned int TCcitizen : 1;` bayrağı ve `location` birliği eklendi (ekrandan, 01:15:00). Yabancı çalışan için TC kimlik alanı pasaport numarası olarak kullanıldı; okuma mesajı da buna göre değiştirildi. Bir Türk ve bir yabancı çalışan girilerek iki dalın da doğru yazdırıldığı görüldü.
- **Özyineleme ve yığın.** Her fonksiyon çağrısında, çağrılan fonksiyonun yerel değişkenleri ve parametreleri için yığının üstüne bir alan eklenir. Dönüşte bu alan bırakılır ve çağıran fonksiyon kaldığı yerden devam eder. `static` sayaçlı örnekte durma noktası yoktur: her çağrı yığına yeni bir çerçeve ekler ve yığın taşınca program hatayla durur. Faktöriyel örneğinde `n <= 1` hem matematiksel taban durum hem durma noktasıdır. Hoca kendisine düz (iteratif) düşünmenin daha kolay geldiğini söyledi. Yine de bazı algoritmalar özyinelemeyle daha doğal yazılır ve hızlı sıralama (quicksort) gibi bazıları özyinelemeyle iyi performans verir.
  > **Ders sonrası not:** Hoca yığın alanı için bir yerde "heap memory diye de diyordu" dedi; fonksiyon çağrılarının kullandığı alan yığındır (stack). Heap, `malloc`/`calloc` ile ayrılan dinamik bellektir.
- **Taşma.** Ekranda `15! is 2004310016` görüldü (ekrandan, 01:50:00). Gerçek değer $15! = 1\,307\,674\,368\,000$'dir. 32 bitlik `int` bu değerin $2^{32}$'ye göre kalanını tutar, o da 2004310016'dır.
  > **Ders sonrası not:** Hoca 10! değerinin de `int` sınırını aşacağını söyledi. Aslında $10! = 3\,628\,800$ ve $12! = 479\,001\,600$ 32 bitlik `int`'e sığar; taşma 13!'te başlar.
- **Fonksiyon işaretçileri.** Hocanın motivasyon örneği Java'daki `+` operatörüdür: iki taraf sayıysa aritmetik toplama, metinse birleştirme yapar. C'de böyle bir yorumlayıcı yazılırsa, öğelerin türüne bakılıp değerlendirme fonksiyonuna ya toplama ya birleştirme fonksiyonu işaretçi olarak verilebilir. Derste `f1`, `f2` ve `f3` aynı `pf` işaretçisine sırayla atanıp çağrıldı. Hoca, ortak noktalarının dönüş türü olduğunu ve parametre listesi farklı olsa da aynı işaretçiye atanabildiklerini söyledi.
  > **Ders sonrası not:** Bu, parametre listesi boş bırakılmış `int (*pf)();` bildirimiyle eski C standartlarında çalışır. GCC 15 varsayılan olarak C23 kullanır; burada `()` "parametresiz" demektir ve aynı kod derlenmez (ajan denedi; `-std=c17` ile derlendi). Taşınabilir yol, her imza için ayrı işaretçi tanımlamaktır: `int (*pf)(int);` ve `int (*pf2)(int, int);`.
- **Tampon (buffer).** Hoca tamponu üç benzetmeyle anlattı: ağ üzerinden hızla paket gönderilirken alıcının paketleri tampondan müsait olunca çekmesi; geniş ağızlı şişeden dar ağızlı şişeye su aktarırken huni kullanmak; diske yazılacak verinin önce RAM'deki bir tampona yazılıp disk müsait olunca aktarılması.
- **Metin ve ikili mod, taşınabilirlik.** Bir öğrenci Windows ve Unix'te dosya sonu ve satır sonu farklarını sordu. Hoca bir kelime işlemcide satır sonu (Shift+Enter) ile paragraf sonunun (Enter) farklı kodlandığını gösterdi. Dosya başka bir işletim sistemindeki başka bir uygulamada açılınca düzen bozulabilir; Türkçe karakterler farklı kodlamalar yüzünden bozuk görünebilir.
  > **Ders sonrası not:** Hoca dosya sonu için bir sistemin `\0`, ötekinin `\x1` kullandığını örnek olarak söyledi. Gerçekte Windows ve Unix arasındaki asıl fark satır sonudur: Windows `\r\n`, Unix `\n` kullanır. C'de dosya sonu bir karakter değil, `EOF` dönüş değeridir. Eski DOS/Windows metin dosyalarında dosya sonu işareti büyük olasılıkla Ctrl+Z (`0x1A`) idi.
- **Dosyaya neden yazılır?** Programda girilen çalışan bilgileri program kapanınca kaybolur. Verinin kalıcı olması için dosyalara yazılır. Bir veritabanına da yazılabilir, ama bunun için veritabanı sunucusuyla iletişim ve SQL gibi bir sorgu dili gerekir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
