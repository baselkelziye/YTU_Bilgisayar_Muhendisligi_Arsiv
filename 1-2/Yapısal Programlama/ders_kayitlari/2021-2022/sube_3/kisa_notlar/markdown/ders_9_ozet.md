# Ders 9 Çalışma Özeti

## Genel Konular

- Fonksiyonlara parametre aktarımı: değerle (pass by value) ve adresle (pass by reference)
  - Değerle aktarımda argümanın kopyası çıkarılır (derste "deep copy" diye anıldı). Fonksiyon içindeki değişiklik çağıran yere yansımaz. Örnek: `swap(int a, int b)` main'deki değişkenleri değiştirmez.
  - Adresle aktarımda yalnız adres aktarılır (derste "shallow/shadow copy" diye anıldı). Hem bellek ve kopyalama maliyeti azalır hem de fonksiyon çağıranın değişkenini değiştirebilir.
  - Aktarım biçimi performansı, doğruluğu (accuracy) ve fonksiyondan kaç değer alınabileceğini etkiler (ekrandan, 00:10:00).
- Fonksiyondan dönen değer sayısı ve virgül operatörü
  - C'de bir fonksiyon `return` ile tek bir değer döndürür.
  - `return x, y;` yazılırsa hata alınmaz. Virgül burada operatördür ve en sağdaki ifadenin değeri döner (`return 3, 8;` için 8).
  - Birden fazla sonuç gerekiyorsa çıkış değişkenleri işaretçiyle aktarılır.
- İşaretçiyle birden fazla sonuç döndürme (ekrandan, 00:20:00)
  - `int f(int a, int *pa, int *pb)` içinde `a += 8; *pa = x + 7; *pb = y + 3; return a;` (`x = 5`, `y = 7`).
  - `c = 6` ile `x = f(c, &a, &b);` çağrısından sonra çıktı `14 12 10 6` olur. `c` değişmez, `a` ve `b` adres üzerinden değişir.
- `const` ile işaretçi parametreleri
  - `const int *pa`: gösterilen değer değiştirilemez (`*pa = ...` "assignment of read-only location" hatası verir). Hızlı aktarım istenip değerin değişmesi istenmediğinde kullanılır.
  - `int * const pa`: işaretçinin kendisi sabittir, başka bir adresi gösteremez.
  - `const int * const pa`: ikisi birden sabittir.
- Bellekte stack ve heap
  - Yerel değişkenler stack bölgesinde, `malloc` ile ayrılan alanlar heap bölgesinde tutulur.
  - Yerel değişken adresleri ardışık ve düzenlidir. Ekranda (ekrandan, 00:30:00) `int a, b; char d; int c;` için adresler `62FE1C`, `62FE18`, `62FE17`, `62FE10` olarak görüldü: tanımlanan her değişken bir öncekinin altına yerleşti.
- Fonksiyon bildirimi, tanımı ve çağrısı
  - Bildirim (declaration/prototip), tanım (definition, gövde) ve çağrı (call) ayrı kavramlardır. Başka bir yerde tanımlı fonksiyonun bildirimine slaytta "allusion" denir; `extern` bunu belirtir (ekrandan, 00:35:00).
  - Fonksiyon çağrılırken gönderilene argüman, tanımda alınana parametre denir.
  - Program `main`'den başlar; diğer fonksiyonlar `main`'in akışına göre çağrılır. Prototipler (ya da tanımlar) `main`'den önce yazılır; prototiplerin sırası çağrı sırasını belirlemez.
- İşaretçi döndüren fonksiyonlar ve yaşam süresi
  - Yerel değişkenin ya da yerel dizinin adresini döndürmek hatalıdır; fonksiyon bitince o değişkenin ömrü biter.
  - `static` yerel değişkenin ve `malloc` ile ayrılan alanın adresi güvenle döndürülebilir; bunlar program boyunca (ya da `free` edilene kadar) yaşar.
- Dizilerin fonksiyona aktarımı
  - Parametre `int dizi[MAX]`, `int dizi[]` (boyutla birlikte) ya da `int *dizi` biçiminde yazılabilir. Çağrı `dizi` ya da `&dizi[0]` ile yapılır (ekrandan, 00:45:00).
  - C sınır denetimi yapmaz; boyutu ayrı parametre olarak göndermek programcının işidir.
  - Dizi her zaman adres olarak gittiği için fonksiyondaki değişiklik asıl diziyi değiştirir; bu yüzden sıralama fonksiyonu `void` olabilir.
  - Eleman sayısı `sizeof(x) / sizeof(x[0])` makrosuyla bulunur (yalnız dizinin tanımlandığı yerde).
- Fonksiyondan dizi döndürmek
  - C'de dizi türünde dönüş yoktur. Çözüm, fonksiyonda `malloc` ile alan açıp işaretçiyi döndürmektir.
  - Örnek: iki diziyi birleştirme (4, 8, 2 ve 6, 6, 5, 4 → 4, 8, 2, 6, 6, 5, 4). Alternatifte (ekrandan, 01:10:00) sonuç dizisi çağıran tarafından `size1 + size2` boyutunda açılıp parametre olarak gönderilir; büyük veride stack'te yer bulunamayabileceği için önerilmedi.
- Seyrek (sparse) matris
  - 9×9 bağlantı matrisinde 81 hücrenin çoğu 0'dır. Yalnız sıfırdan farklı hücreler (satır, sütun, değer) üçlüleriyle tutulursa 10 değer için 10×3 = 30 hücre yeter.
- `main` fonksiyonuna argüman (komut satırı argümanları)
  - `int main(int argc, char *argv[])`: `argc` argüman sayısı, `argv` her biri bir string'i gösteren karakter işaretçileri dizisidir (ekrandan, 01:20:00).
  - `argv[0]` programın adıdır. Argümanlar string gelir; sayıya `atoi`, `atof` ile çevrilir.
  - Parametre sırası önce `argc`, sonra `argv` olmalıdır. `gcc kaynak.c -o program` komutundaki her parça da bir argümandır.
- Yapılar (struct): soyutlama ve tanım
  - Diziler tek türde veri tutar; gerçek dünyadaki nesneler (öğrenci, çalışan) farklı türlerde niteliklerden oluşur. Yapı, bu nitelikleri üye değişkenler olarak bir araya getiren kullanıcı tanımlı türdür.
  - Değişken üretimi: tek değişken, sabit dizi (`struct employee e[1000]`) ya da `malloc(n * sizeof(struct employee))` ile dinamik dizi.
  - `typedef` bir türe yeni ad verir. Yapı için üç yazım vardır: `struct polinom p1;`, `typedef struct polinom1 {...} POLINOM1;`, `typedef struct {...} POLINOM2;`. Derste ikincisi önerildi.
  - Yapı türünden işaretçi, işaretçinin işaretçisi, dizi, işaretçi dizisi ve matris tanımlanabilir (ekrandan, 01:55:00).
- Üyelere erişim
  - Yapı değişkeninde nokta (`p1.derece`), işaretçide `(*p2).derece` ya da ok (`p2->derece`) kullanılır. `*p2.derece` hatalıdır, çünkü nokta önce uygulanır.
  - İşaretçi kullanılmadan önce bir yeri göstermelidir (`p2 = &p1;`).
  - `scanf` için üyenin adresi verilir: `&p1.derece`, `&p2->derece`. `->` ve `.` önceliği `&`'den yüksektir.
  - Yapının adresi ilk üyesinin adresiyle aynıdır; sonraki üye ilk üyenin boyutu kadar ileridedir.
- İç içe yapılar (nested structure) ve polinom örneği
  - Polinom ile terim ayrı kavramlardır: `TERIM { double katsayi; int derece; }`, `POLINOM { TERIM *terimler; int terimsayisi; }` (ekrandan, 02:50:00).
  - Terimler `p1.terimler = (TERIM*) malloc(N * sizeof(TERIM));` ile açılır; erişim `p1.terimler[i].katsayi` ya da `p2->terimler[i].katsayi` biçimindedir.
  - Slayttaki örnekte `EMPLOYEE` yapısının içinde `DATE enlisted` üyesi vardır; erişim `x.enlisted.year = 2008;` biçimindedir.
- Dinamik matris uygulaması (dikdörtgen kenarları)
  - N×2 matris `int**` ile açılır, her satır ayrıca `malloc` ile ayrılır. Kare olan satırların adresleri `int**` türünde ikinci bir dizide tutulur, en sonda önce satırlar sonra işaretçi dizileri `free` edilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Adresle aktarım
  - Pek çok dilde karşılaşılan temel kavramdır; değer kopyalamak hem yavaştır hem de veri tutarsızlığına yol açabilir.
- İşaretçi döndürürken ne döndürüldüğüne dikkat
  - Yerel değişkenin adresi döndürülmez; dizi döndürülecekse `malloc`, tek değişken döndürülecekse `static` kullanılır.
- Yapılar dersin özüdür
  - Yapıları dizilerle, dinamik bellekle ve fonksiyonlarla birlikte kullanabilmek dersin ana amacıdır; yapılar öncekilerden kopuk bir konu değildir, sadece kullanıcının tanımladığı bir türdür.
  - Bir yapının hangi üyelerden oluşacağı iyi tasarlanmalıdır; ayrı bir kavram olan nitelik (terim, ders, tarih) ayrı yapı olarak tanımlanmalıdır.
- Bellek çizerek çalışmak
  - Neyin dizi, neyin işaretçi olduğu ve neyin nereyi gösterdiği kağıda çizilerek izlenmelidir.
- Kod yazma pratiği
  - Kodu ezberlemek yerine bilgisayarda yazıp derleyici hatalarını görmek gerekir; işaretçi operatörlerindeki (`*`, `&`) karışıklıklar pratik eksikliğinden doğar.
- Biçim belirteçleri
  - `double` üye `scanf` ile `%lf` ile okunur; `%d` ile okunup yazılırsa değer yanlış görünür.

## Kısa Tekrar Notları

- Değerle aktarım kopyalar, değişiklik yansımaz; adresle aktarım değiştirebilir.
- `return a, b;` yalnız `b`'yi döndürür.
- `const int *p`: değer sabit; `int * const p`: adres sabit; `const int * const p`: ikisi de sabit.
- Yerel değişkenler stack'te, `malloc` alanları heap'te.
- Yerel değişkenin adresini döndürme; `static` ya da `malloc` kullan.
- Diziler fonksiyona adres olarak gider; boyut ayrıca gönderilir.
- Eleman sayısı: `sizeof(x) / sizeof(x[0])`.
- Fonksiyondan dizi: `malloc` ile açıp işaretçi döndür, işi bitince `free`.
- `main(int argc, char *argv[])`; `argv[0]` program adı; `atoi`/`atof` ile sayıya çevir.
- `typedef struct ad { ... } AD;` önerilen yazımdır.
- `p.uye`, `(*p).uye`, `p->uye`; `scanf("%d", &p->uye)`.
- Polinom = terimler dizisi + terim sayısı; terim = katsayı + derece.
- Matris boşaltma: önce satırlar, sonra satır işaretçileri dizisi.

## Detaylı Açıklamalar

- Değerle ve adresle aktarım
  - Ekrandaki örnekte (ekrandan, 00:15:00 ve 00:20:00) `main`'de `int a, b, c = 6;` tanımlanır ve `x = f(c, &a, &b);` çağrılır. `f` içinde `a` (c'nin kopyası) 8 artırılarak 14 olur ve döndürülür; `*pa = 5 + 7 = 12`, `*pb = 7 + 3 = 10` yazılır. Ekrana `14 12 10 6` gelir: `c` hâlâ 6'dır, çünkü değerle gitmiştir. Böylece `return` ile bir, işaretçilerle iki değer çağırana aktarılır. Kod derlenip çalıştırıldı ve bu çıktı doğrulandı.
  - Slayttaki `increaseRegular(int aa, int bb)` ve `increasePointer(int *aa, int bb)` örneğinde (ekrandan, 00:25:00) `a = 3, b = 5` ile ilk fonksiyon kendi içinde 8 yazar ama main'de `a` 3 kalır; ikinci fonksiyon `a`'nın adresini aldığı için main'de de `a` 8 olur. Kod derlenip çalıştırıldı, çıktı bu sırayla doğrulandı.
  - `g(const int *pa, int *pb)` içinde `*pa`'ya atama yapılınca derleyici "read-only location" hatası verir; `*pb = *pa + 3` gibi okuma serbesttir (ekrandan, 00:20:00).
- Yerel değişkenlerin adresleri
  - `%p` ile yazdırılan adreslerde (ekrandan, 00:30:00) `a` için `62FE1C`, `b` için 4 bayt aşağısı `62FE18`, `char d` için 1 bayt aşağısı `62FE17`, `c` için `62FE10` görüldü. `d` ile `c` arasındaki boşluk hizalamadan (padding) kaynaklanır. Fonksiyondaki işaretçi parametrelerin adresleri ise 8'er bayt farkla dizildi <!-- BELİRSİZ: bu adresler karede görülmedi, altyazıdan alındı -->.
- Fonksiyondan işaretçi döndürmek
  - Fonksiyon içinde `int x;`, `static int y;` ve `int *px = malloc(...)` olsun. `&y` ve `px` döndürülebilir; `&x` ya da yerel `int d[10]` dizisinin adresi döndürülemez, çünkü fonksiyon bitince bu alanların ömrü (duration) biter.
- Diziyi birleştirme
  - `malloc` sürümünde fonksiyon `size1 + size2` elemanlık alanı heap'te açar, önce birinci diziyi sonra ikinci diziyi kopyalar ve işaretçiyi döndürür. Çağıran taraf boyutları `SIZE_OF_ARRAY` makrosuyla hesaplar, sonucu yazdırır ve `free(ptr)` ile serbest bırakır. Alanın başka fonksiyonda açılmış olması `free` için sorun değildir; heap'teki alan, onu gösteren işaretçi üzerinden bırakılır.
- Komut satırı argümanları
  - Ekrandaki programda (ekrandan, 01:20:00) argüman sayısı ve `for (i = 0; i < argc; i++)` ile her argüman `%s` ile yazdırılır. Programı `program 1 ABC xyz` gibi çalıştırınca argüman sayısı 4 olur ve 0. argüman program adıdır. `atoi(argv[3])` ile 444 sayıya çevrilip 1 artırılınca 445 elde edilir.
- Yapı adresleri
  - Ekranda (ekrandan, 01:55:00) `printf("Struct Adress =%p, Derece= %p , Katsayi = %p\n", &p1, &p1.derece, &p1.katsayi);` ile yapının adresinin ilk üye olan katsayının adresiyle aynı olduğu görüldü. Katsayı `int` iken derece 4 bayt, `double` yapılınca 8 bayt ileriye yerleşti.
- Polinom programı
  - Ekrandaki son sürüm (ekrandan, 02:35:00, 02:40:00, 02:45:00): terim sayısı `N` okunur, `p1.terimsayisi = N`, terimler `malloc` ile açılır. Dereceler `i`, katsayılar `1 + rand() % 4` ile doldurulur. Yazdırmada döngü `terimsayisi - 1`'e kadar `"%2.2lf X ^ %d + "` yazar, son terim döngüden sonra `+` olmadan yazılır; böylece sondaki fazla `+` kalkar. Ters sırada yazdırmak için döngü `i = terimsayisi - 1`'den `i > 0` iken azaltılır ve son olarak 0. terim yazılır.
  - Kod derlenip `3` terim ve `1 1 2 2 3 3` girdisiyle çalıştırıldı; çıktı `1.00 X ^ 1 + 2.00 X ^ 2 + 3.00 X ^ 3` oldu.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
