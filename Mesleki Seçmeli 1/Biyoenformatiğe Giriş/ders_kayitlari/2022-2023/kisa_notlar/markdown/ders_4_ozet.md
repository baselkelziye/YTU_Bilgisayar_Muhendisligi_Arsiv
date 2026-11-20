# Ders 4 Çalışma Özeti

## Genel Konular

- Perl operatörleri
  - Aritmetik operatörler (toplama, çıkarma, çarpma, bölme, mod, üs), atama operatörleri (`=` ve "işlem yap ve ata" biçimleri), artırma/azaltma (`++`, `--`) diğer dillerdekine çok benzer.
  - Dizgi operatörleri: `.` dizgileri birleştirir, `.=` birleştirip atar (ekrandan, 00:10:00).
  - Sayısal karşılaştırma, dizgi karşılaştırma ve mantıksal operatörler (ve, veya, değil) vardır. Hoca, eşitlik için kullanılan çift eşittir işaretinin atama işaretinden farklı olduğunu hatırlattı.
- Perl'de fonksiyonlar (alt yordamlar)
  - Perl'de fonksiyonlara "subroutine" denir. Tanım `sub` ile başlar; argüman listesi, deyimler ve dönüş değeri içerir.
  - Örnek olarak üçgen alanını hesaplayan bir alt yordam gösterildi. <!-- BELİRSİZ: alt yordamın kodu karelerde görünmüyor. -->
- Eşleştirme (pattern matching) ve düzenli ifadeler
  - Perl'de desen eşleştirme, HTML şablonlarında bilgi değiştirme, log dosyalarında ya da web sayfalarında belirli kelime veya dizileri arama gibi işlerde kullanılır; karmaşık arama ifadeleri "düzenli ifadeler" (regular expressions) kategorisine girer (ekrandan, 00:15:00).
  - Bir eşleştirme için üç şey gerekir: aranan metin, aranan desen ve bu ikisini bağlayan mekanizma.
  - `=~` bağlama (binding) operatörüdür; aranan dizgiyi desene bağlar. `m/success/` eşleştirme operatörüdür; `m` "match" kısaltmasıdır, `/` karakterleri sınırlayıcıdır. Eşleşme varsa 1, yoksa 0 döner. Negatif eşleştirme de vardır.
  - `()` desen öğelerini gruplar; `*` önceki öğenin sıfır, bir ya da çok kez geçebileceğini belirtir (ekrandan, 00:20:00). `+` en az bir kez, `?` sıfır ya da bir kez demektir.
  - Köşeli parantez tek karakterlik bir sınıfla eşleşir: tek bir rakam, bir ya da daha çok rakam, küçük harfli kelime, büyük harfli kelime; `^` ile başlayan sınıf "bunlar dışındaki" karakterlerle eşleşir.
  - Süslü parantez tekrar sayısını kesin verir: örneğin tam 6 rakam ya da 6 ile 10 arası rakam.
  - Özel karakterler sözcük anlamıyla aranacaksa ters bölü ile kaçışlanır.
  - `\s` boşluk karakteridir; `[ \t\n\r\f]` sınıfıyla aynıdır (boşluk, sekme, yeni satır, satır başı, sayfa besleme). `\x` ve iki onaltılık rakam bir karakteri belirtir; `\x1b` ESC karakteridir. `|` VEYA demektir (ekrandan, 00:25:00).
- Katılık (strictness)
  - Perl değişkenlerin ve alt yordamların bildirilmeden kullanılmasına izin verir; değişkenler varsayılan olarak globaldir.
  - `my` ile bildirilen değişken sözcüksel (lexical) olur; bildirildiği yerden içinde bulunduğu bloğun sonuna kadar yaşar.
  - `use strict;` satırı programın başına eklenince `my` kullanımı zorunlu olur (ekrandan, 00:30:00). Kurallara uymayan program çalışmaz, hata mesajı verir; değişkenler `my` ile bildirilince sorun kalkar.
  - Programlar büyüdükçe bakımı zorlaşır; bu yüzden katılık kullanmak her zaman daha güvenlidir. Ayrıca `use subs` yönergesi ve uyarılar için `-w` anahtarı anıldı.
- Perl tek satırlıkları (one-liners)
  - Perl betik dili olarak da kullanılabilir. `-e` anahtarı komut satırından tek satırlık bir program çalıştırır: `perl -e 'print "Hello from a Perl one-liner.\n";'` (ekrandan, 00:35:00).
  - `-n` anahtarı `-e` ile birlikte kullanıldığında tek satırlığı bir döngüyle sarmalanmış gibi çalıştırır; EMBL veri dosyası üzerinde koşullu yazdırma örneği, eşdeğer `while` döngüsüyle ve Unix `grep` komutuyla karşılaştırıldı.
  - `-n` ile `-p` birleşince döngünün sonuna bir `print` eklenir. Örnek: EMBL veri dosyasında dört rakamla bitmeyen satırları yazdıran tek satırlık. Bunu Unix `grep` ile yapmak daha zordur.
  - Başka seçenekler: otomatik bölme (autosplit), Unicode özellikleri, sözdizimi denetimi, programı hata ayıklayıcı altında çalıştırma.
- Perl'den başka programları çalıştırma
  - `system` alt yordamı: çağıran program, çağrılan programın başarılı olup olmadığını öğrenir.
  - Ters tırnak (backticks) ve `qx` operatörü: çağrılan programın çıktısı çağıran programa döner.
  - DOS'taki `dir` komutu üç yolla çağrıldı; çıktıda dizin içeriği üç kez listelendi, `system` çağrısının sonucu `0` olarak yazdırıldı (ekrandan, 00:45:00).
- Hata yakalama ve sıralama
  - `die` ve `eval` ile hata yakalama (exception handling): program hata olunca çıkmadan durumu kurtarabilir.
  - `sort` ve `reverse` ile dizgi ya da sayı listeleri artan, azalan ya da özel sırada sıralanır. Dört kısa DNA dizisinden oluşan bir dizi üzerinde sıralama, azalan sıralama ve ters sıralama örnekleri gösterildi; sayılar üzerinde de sıralama yapıldı.
  - Bir şiire satır sıralama programı uygulanınca şiirin yapısı bozuldu (Türkçe karakterler de doğru görünmedi).
- "Here document" yapısı
  - Metni ekranda program içindeki biçimiyle aynen göstermek için arka arkaya `print` deyimleri yerine "here document" kullanılır; hoca bunu daha iyi bir yol olarak gösterdi. <!-- BELİRSİZ: here document örneğinin kodu karelerde görünmüyor. -->
- Veri kümelerini indirme
  - Yerel kopyanın üstünlükleri: güvenilirlik (uzak bağlantıda veri kaybı olabilir), kararlılık, esneklik ve güvenlik.
  - Sakıncaları: bayat veri (yerel kopya belirli bir anın görüntüsüdür), ek depolama ihtiyacı ve başarım (uzak sunucular daha güçlü, paralel sistemlere sahip olabilir).
  - İndirme yolları: hazır dizi analizi programları (EMBOSS), Linux'taki ücretsiz `wget` programı ve web üzerinden indirme. Web üzerinden indirme oldukça etkileşimlidir, tek tek veri dosyalarını indirmek için kullanışlıdır (ekrandan, 01:10:00).
- Veritabanı kavramları
  - Veritabanı: bir ya da daha çok ilişkili tablonun topluluğu. Tablo: bir ya da daha çok satırın topluluğu. Satır: sütunlar halinde düzenlenmiş bir ya da daha çok veri öğesi.
  - Modern bilgisayar sistemleri büyük miktarda yapılandırılmış veri saklar; bu veri genellikle bir veritabanı sisteminde tutulur (ekrandan, 01:20:00).
  - Veritabanı sistemi: bir ya da daha çok veritabanını tanımlamak (oluşturmak) ve işlemek için mekanizma sağlayan program ya da programlar topluluğu; veritabanı, tablo ve sütunların oluşturulmasına, adlandırılmasına ve yapıların tanımlanmasına izin verir.
  - Veritabanı sistemleri ölçek, maliyet ve platforma göre sınıflandırıldı: kişisel (PC üzerinde küçük ölçekli), kurumsal (çok pahalı, güçlü platform ve büyük bellek ister) ve açık kaynak (ücretsiz, Linux'ta yaygın, PC sürümleri de var).
  - SQL iki olanak sunar: DDL (veri tanımlama dili, veritabanı oluşturma) ve DML (veri işleme dili, tablodaki veriyi değiştirme, silme, ekleme).
  - Perl'de veritabanı programlamak için DBI (database interface) modülü kullanılır; MySQL ile birlikte anıldı.
- Web teknolojileri
  - Web altyapısının bileşenleri: web sunucusu, web istemcisi (tarayıcı), taşıma protokolü HTTP, içerik dili HTML, veri (veritabanı); ayrıca istemci tarafı ve sunucu tarafı programlama.
  - Web sayfası oluşturmanın üç yolu: elle (metin düzenleyiciyle HTML yazmak), hazır görsel araçlarla (Dreamweaver gibi) ve web programlamayla (içerik zamanla değişecekse dinamik sayfa; PHP, Python, Perl).
  - Perl'de web sayfası: here document içinde HTML yazmak ya da standart CGI modülünün `start_html`/`end_html` gibi fonksiyonlarını kullanmak. Dinamik sayfa örneği: her çağrıldığında o anki saati gösteren sayfa.
  - Güvenlik: programın başındaki `-T` seçeneği Perl'ün "taint mode"unu açar ve programın davranışına özel güvenlik denetimleri uygular (ekrandan, 01:45:00).
  - Web otomasyonu: Mechanize modülü bir web sitesiyle etkileşimi otomatikleştirir (örneğin uzak bir veri dosyasını 100 kez açmak/indirmek).
- İkili dizi hizalamaya giriş
  - Sonraki haftaların konusu: ikili dizi hizalama, nokta matrisi (dot matrix), skor matrisleri, boşluk cezaları ve dinamik programlama yaklaşımları.
  - Moleküler biyolojide sık sorulan soru, iki dizinin ilişkili olup olmadığıdır; en yaygın yol ikisini karşılaştırıp benzer olup olmadıklarına bakmaktır (ekrandan, 02:10:00).
  - "pear" ve "tear" örneği: anlam bakımından ilişkisizdir, ses bakımından uyaklıdır, harf harf karşılaştırınca dört harften üçü ortaktır. Benzerlik bakış açısına bağlıdır; biyoenformatikteki skor şemaları bu bakış açılarını temsil eder.
  - Benzer biyolojik diziler genellikle ilişkilidir (ortak ata). Benzerlik çalışmaları işlev, yapı ve evrimsel ilişki hakkında bilgi verir.
  - Homolog: ortak bir atadan gelen, iki farklı organizmadaki benzer diziler. Ortolog: türleşme olayıyla ortaya çıkan, iki farklı organizmadaki benzer diziler (işlev korunur). Paralog: tek bir organizmada gen eşlenmesiyle (duplication) ortaya çıkan benzer diziler. Ksenolog: yatay aktarım olaylarıyla (simbiyoz, virüsler) ortaya çıkan benzer diziler.
  - Benzerlik aramalarında protein dizileri tercih edilir: DNA dizileri daha az bilgi taşır (ekrandan, 02:20:00); DNA 4 bazdan, proteinler 20 amino asitten oluşur, bu yüzden rastgele eşleşme şansı daha azdır; amino asit benzerliği skorlanabilir (mutasyon sayısı, kimyasal benzerlik, PAM matrisleri); protein veri bankaları DNA veri bankalarından çok daha küçüktür.
  - Terimler: dizi özdeşliği (aynı konumda tam olarak aynı amino asit ya da nükleotit), dizi benzerliği (benzer kimyasal özellikli yer değiştirmeler dahil), dizi homolojisi (ortak atadan gelen evrimsel akrabalık).
  - Evrim örneği: ata dizi ABCD; B→C mutasyonuyla ACCD, C'nin silinmesiyle ABD oluşur (ekrandan, 02:30:00). Hizalama bir optimizasyon problemidir; en iyi hizalama bir ölçüte göre belirlenir.
  - Hizalamada üç durum: eşleşme (match), uyuşmazlık (mismatch) ve ekleme/silme (indel, tire ile gösterilir). Örnek protein ve DNA hizalamalarında yıldızlar eşleşmeleri gösterir (ekrandan, 02:35:00).
- Mesafe ölçüleri
  - DNA ve protein dizileri kategorik veridir. Kategorik veri için ilk akla gelen ölçü düzenleme mesafesidir (edit distance); diziler sayısala dönüştürülürse sayısal yöntemler de kullanılabilir.
  - Mesafe benzemezliği (dissimilarity), korelasyon benzerliği ölçer.
  - Hamming mesafesi uyuşmazlıkları sayar; "pear" ile "tear" arasındaki Hamming mesafesi 1'dir (ekrandan, 02:45:00).
  - Boşluklu hizalama (gapped alignment): diziler farklı uzunluktaysa ya da zamanla eklenmiş/silinmiş bölgeler varsa gerekir. "alignment" ve "ligament" örneğinde tek uyuşmazlık vardır (Hamming 1); Levenshtein mesafesi boşlukları da sayar ve 2 olur (ekrandan, 02:50:00).
  - Hizalamada dört durum özetlendi: eşleşme, uyuşmazlık (yer değiştirme/mutasyon), birinci dizide boşluk (birinci diziden karakter silinmesi) ve ikinci dizide boşluk (birinci diziye karakter eklenmesi).

## Hocanın Özellikle Vurguladığı Kısımlar

- Düzenli ifadeler
  - Perl'in desen eşleştirmesinin tamamı düzenli ifadelere dayanır; düzenli ifadeler herhangi bir metin desenini belirsizliksiz ifade etmenin standart yoludur ve bilgisayar biliminde ayrı kitaplara konu olan bir alandır.
  - Biyoenformatik büyük ölçüde DNA ve amino asit veri tabanlarında metin işleme olduğu için bu yetenekler önemlidir.
- Dile özgü kolaylıklar
  - Her platform ve dil klasik yaklaşımların yanında işleri kolaylaştıran alışılmadık yollar sunabilir (Perl tek satırlıkları gibi). Kullanılan ortamı iyi tanımak ve amaca en uygun dili seçmek gerekir.
- Sıralama
  - Sıralama programlama öğrenirken ilk öğrenilen kavramlardandır; algoritma sınavlarında hemen her zaman sıralamayla ilgili bir iki soru olur.
- Hamming mesafesi neyi sayar?
  - Hoca bunu "test sorusu" olarak sordu: eşleşmeleri mi, uyuşmazlıkları mı, indel'leri mi? Cevap: uyuşmazlıkları.
- Mesafe ve benzerlik farkı
  - Mesafe benzerliği değil benzemezliği ölçer; benzerlik ölçüsü korelasyondur. Mesafe 0 ise diziler tamamen aynıdır.
- Skor şeması
  - Skor şemasındaki değişiklik hizalamaların sıralamasını değiştirebilir; aynı en yüksek skora sahip birden çok hizalama olabilir.

## Kısa Tekrar Notları

- `.` dizgi birleştirme, `.=` birleştirip atama.
- Perl fonksiyonu = subroutine, `sub` ile tanımlanır.
- `=~` bağlama operatörü, `m/.../` eşleştirme operatörü; eşleşme varsa 1, yoksa 0.
- `*` sıfır ya da daha çok, `+` en az bir, `?` sıfır ya da bir; `{6}` tam 6, `{6,10}` 6 ile 10 arası.
- `\s` = `[ \t\n\r\f]`; `\x1b` ESC; `|` VEYA.
- `my` sözcüksel değişken; `use strict;` bildirimi zorunlu kılar.
- `perl -e` tek satırlık; `-n` döngü ekler; `-p` döngüye `print` ekler.
- `system` başarı durumunu, ters tırnak ve `qx` çıktıyı döndürür.
- `die`/`eval` hata yakalama; `sort`/`reverse` sıralama.
- Yerel veri kopyası: güvenilir, kararlı, esnek, güvenli; ama bayat olabilir, yer ve başarım sorunu.
- Veritabanı = ilişkili tablolar; tablo = satırlar; satır = sütunlardaki veri öğeleri.
- Veritabanı sistemleri: kişisel, kurumsal, açık kaynak. SQL = DDL + DML. Perl'de DBI modülü.
- Web altyapısı: sunucu, istemci, HTTP, HTML, veri. `-T` taint mode.
- Homolog, ortolog (türleşme), paralog (gen eşlenmesi, tek organizma), ksenolog (yatay aktarım).
- Benzerlik aramasında protein dizisi DNA dizisinden daha bilgilendiricidir (20 amino asit, 4 baz).
- Hizalama durumları: match, mismatch, indel.
- Hamming = uyuşmazlık sayısı; Levenshtein = uyuşmazlık + boşluk (derste verilen tanımla).
- pear/tear: Hamming 1. alignment/-ligament: Hamming 1, Levenshtein 2.

## Detaylı Açıklamalar

- Perl'de desen eşleştirme üç parçadan oluşur: aranan metin, desen ve bağlama. bir dizgi değişkeni ile `m/success/` deseninin `=~` ile bağlandığı ifadede `=~` dizgiyi desene bağlar, `m/.../` ise deseni tanımlar. Bu ifade bir `if` deyiminde kullanılarak "bulundu" ya da "bulunamadı" mesajı yazdırılabilir. Desen içinde nicelik belirteçleri (`*`, `+`, `?`, `{n}`, `{n,m}`), karakter sınıfları (`[...]`, `[^...]`), kaçış dizileri (`\s`, `\t`, `\n`, `\x1b`) ve VEYA (`|`) birlikte kullanılarak neredeyse her türlü metin deseni yazılabilir. Karede gösterilen örnek, kullanıcının cevabının "y", "yes" ya da "yeah" ile başlayıp başlamadığını büyük/küçük harf ayırmadan denetler (ekrandan, 00:25:00):

  ```perl
  if ($answer =~ /^y|^yes|^yeah/i ) { print "Affirmative!"; }
  ```

- Katılık, büyüyen programlarda hataları önlemek içindir. `use strict;` eklenmiş bir programda `my` ile bildirilmemiş bir değişken kullanılırsa Perl katılık kurallarının çiğnendiğini bildirir ve program çalışmaz; değişkenler `my` ile bildirilince program sorunsuz çalışır.
- Perl tek satırlıkları Unix ve C geleneğinden gelir. `-n` ile yazılan bir tek satırlık, dosyanın her satırını okuyan bir `while` döngüsüne eşdeğerdir; `-p` ayrıca her satırı yazdırır. Aynı işler `grep` ile de yapılabilir, ama dört rakamla bitmeyen satırları seçmek gibi işler `grep` ile daha zahmetlidir.
- Başka programları çağırmanın iki temel yolu vardır: çağrılan programın başarılı olup olmadığını öğrenmek (`system`) ve çağrılan programın çıktısını almak (ters tırnak, `qx`). Karedeki örnekte `system` ile çağrılan `dir` komutunun çıktısı doğrudan ekrana yazılır ve sonucu 0 olarak yazdırılır; ters tırnak ve `qx//` çağrıları ise dizin listesini program içine döndürür.
- Veri kümesini yerel indirmek mi, uzaktan kullanmak mı sorusu bir ödünleşimdir. Yerel kopya bağlantı sorunlarından etkilenmez ve güvenlidir; ama bir anın görüntüsü olduğundan zamanla bayatlar, büyük veritabanları için disk ister ve uzak sunucuların yüksek başarımlı paralel donanımından yararlanılamaz.
- Web altyapısı sorusunda bileşenler sırayla kuruldu: önce bir sunucu gerekir; sunucu bir istemciye hizmet eder; ikisinin konuşması için HTTP protokolü, birbirini anlaması için HTML içerik dili gerekir; arka planda da veritabanı bulunur.
- Dizi hizalama, iki diziyi karşılıklı yerleştirme işidir. Hizalamanın kendisi hesaplama açısından kolaydır, ama olası hizalama sayısı çoktur; en iyisini bulmak için hepsini incelemek ve bir skorla değerlendirmek gerekir. Bu yüzden hizalama bir optimizasyon problemidir ve sonuç seçilen ölçüte bağlıdır. "pear"/"tear" örneğinde olduğu gibi, anlam ölçüt alınırsa kelimeler ilgisiz, ses ya da harf ölçüt alınırsa çok benzerdir.
- Hamming mesafesi aynı hizadaki farklı harflerin sayısıdır. Boşluklu hizalamalarda boşlukları da hesaba katmak için Levenshtein mesafesi kullanılır; derste bu, uyuşmazlık ve boşluk sayılarının toplamı olarak tanımlandı. "alignment" ile "-ligament" hizalamasında N/A uyuşmazlığı ve baştaki boşluk vardır; Hamming 1, Levenshtein 2 olur.
- Ders sonunda iki DNA dizisi (ACGGACT ve ATCGGATCT) için iki geçerli hizalama verildi ve hangisinin daha iyi olduğu soruldu (ekrandan, 02:55:00). Cevap için önce bir ölçüt (Hamming ya da Levenshtein mesafesi) seçmek gerekir; konu sonraki derste sürecek.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
