# Ders 4 Genişletilmiş Notu: Perl'de Düzenli İfadeler, Veritabanı ve Web Teknolojileri; İkili Dizi Hizalamaya Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Perl Operatörleri
- 2. Perl'de Alt Yordamlar
- 3. Eşleştirme ve Düzenli İfadeler
- 4. Katılık (Strictness)
- 5. Perl Tek Satırlıkları
- 6. Perl'den Başka Programları Çalıştırma
- 7. Hata Yakalama ve Sıralama
- 8. Here Document
- 9. Veri Kümelerini İndirme
- 10. Veritabanı Kavramları
- 11. Web Teknolojileri ve Perl
- 12. İkili Dizi Hizalamaya Giriş
- 13. Benzerlik, Homoloji ve Hizalama Terimleri
- 14. Mesafe Ölçüleri: Hamming ve Levenshtein
- Örnek Sorular
- Dersin Toparlaması

## 1. Perl Operatörleri

Ders, bir önceki haftada başlanan Perl anlatımının devamıyla açıldı. Hoca, Perl'deki operatörlerin C ya da başka dillerdekilerle neredeyse aynı olduğunu, burada "süslü" bir şey olmadığını söyledi. Bu yüzden operatörleri hızlıca geçti.

### 1.1 Aritmetik ve atama operatörleri

Aritmetik operatörler matematiksel işlemler içindir: toplama, çıkarma, çarpma, bölme, mod ve üs alma. Slaytta bu operatörlerin birlikte kullanıldığı tipik bir Perl deyimi gösterildi; örnek, iki skaler değişkenin toplanıp bir değişkene atanmasıydı.

Atama operatörleri değişkenlere değer atamak içindir. Düz atamanın yanında "işlem yap ve ata" biçimleri vardır: topla ve ata, çıkar ve ata, çarp ve ata, böl ve ata, mod al ve ata, üs al ve ata. Bunlara ek olarak artırma (bir ekle) ve azaltma (bir çıkar) operatörleri bulunur.

### 1.2 Dizgi operatörleri

Perl'de dizgiler için iki temel operatör vardır (ekrandan, 00:10:00):

| Operatör | İşlev |
|---|---|
| `.` | Dizgileri birleştirir (concatenate) |
| `.=` | Birleştirir ve atar |

Slaytta bu iki operatörün kullanımını gösteren basit bir örnek de vardı.

### 1.3 Karşılaştırma ve mantıksal operatörler

Sayısal değerleri karşılaştırmak için sayısal karşılaştırma operatörleri kullanılır. Hoca, eşitlik denetimindeki çift eşittir işaretinin tek eşittir (atama) işaretinden farklı olduğunu hatırlattı. Dizgileri karşılaştırmak için ayrı bir operatör takımı vardır: eşit, eşit değil, büyük, küçük, büyük ya da eşit, küçük ya da eşit. Hoca, öğrencilerin bu operatörlere başka dillerde rastladığını düşünerek açıklamaları atladı. Son olarak mantıksal operatörler gösterildi: mantıksal VE, mantıksal VEYA ve mantıksal DEĞİL.

> **Ek bilgi (derste anlatılmadı):** Perl'de sayılar `==`, `!=`, `<`, `>`, `<=`, `>=` ile; dizgiler ise harfli operatörlerle karşılaştırılır: `eq`, `ne`, `lt`, `gt`, `le`, `ge`. Mantıksal operatörler `&&`, `||`, `!` (ve okunaklı karşılıkları `and`, `or`, `not`) biçimindedir. Bir dizginin desenle eşleşmediğini sınamak için `=~` yerine `!~` kullanılır.

## 2. Perl'de Alt Yordamlar

Fonksiyonlar, bir argüman listesi verilerek kolayca yapılandırılabilen kod ya da deyim topluluklarıdır. Bir fonksiyon bir kez yazıldıktan sonra adıyla çağrılır, yeni parametreler verilir ve yeni sonuçlar alınır. Bazı dillerde bunlara "subroutine", bazılarında "function" denir; Perl'de fonksiyonların adı alt yordamdır (subroutine).

Bir alt yordamın genel sözdizimi `sub` anahtar sözcüğüyle başlar. Ardından fonksiyona aktarılacak argüman listesi, deyimler ve dönüş değerleri gelir. Slaytta örnek olarak üçgenin alanını bulan bir alt yordam ve bu alt yordamın çağrılması gösterildi. <!-- BELİRSİZ: üçgen alanı alt yordamının kodu karelerde görünmüyor; kod nota alınmadı. -->

## 3. Eşleştirme ve Düzenli İfadeler

### 3.1 Neden desen eşleştirme?

Hoca eşleştirmenin genel olarak düzenli ifadeler (regular expressions) çerçevesinde ele alındığını söyledi. Düzenli ifadeler bilgisayar biliminde ayrı bir alandır ve Perl'in bunları uygulamak için çok güçlü fonksiyonları vardır.

Slayttaki gerekçeler şöyleydi (ekrandan, 00:15:00): HTML şablonlarını açıp ziyaretçiye ait bilgileri yerleştirebilmek gerekir; bunu yapmanın yolu önce eşleştirmek, sonra yerine koymaktır. Log dosyalarında ya da web sayfalarında belirli kelime veya dizileri aramak gibi pek çok yönetim işinde de desen eşleştirme kullanılır. Perl'de desen eşleştirme, metin bölümlerinde belirli kelimeleri, kelime içindeki harfleri, karakter dizilerini, sayıları, sayı dizgilerini ve HTML etiketlerini arama sürecidir. Bu daha karmaşık arama ifadeleri "düzenli ifadeler" kategorisine girer.

### 3.2 Bağlama ve eşleştirme operatörleri

Bir desen eşleştirmesi için üç şey gerekir: içinde arama yapılan metin, aranan desen ve deseni arama metnine bağlayan yol. Slayttaki örnekte bir dizgi değişkenine bir cümle atanmış, ardından bir `if` deyimiyle eşleştirme yapılmıştı. Eşleşme varsa ekrana "bulundu", yoksa "bulunamadı" anlamında bir mesaj yazdırılır.

Bu yapıdaki `=~` işaretine bağlama operatörü (binding operator) denir. Aranan dizgiyi, aramayı belirleyen desene bağlar. `m/success/` yapısı ise eşleştirme operatörüdür: `m` "matching" sözcüğünün kısaltmasıdır, `/` karakterleri sınırlayıcıdır, aradaki `success` aranan harf dizisidir. Bağlama ve eşleştirme operatörlerinin birleşimi desen eşleştirmeyi verir. Eşleştirme ifadesi eşleşme varsa 1, yoksa 0 değerini döndürür. Negatif eşleştirme de mümkündür, yani desenin bulunmadığını sınamak.

### 3.3 Nicelik belirteçleri ve gruplama

Slaytta şu kurallar verildi (ekrandan, 00:20:00):

- `()` desen öğelerini gruplar.
- `*` önceki karakterin, öğenin ya da öğe grubunun sıfır kez, bir kez ya da çok kez geçebileceğini belirtir.
- `+` önceki öğenin en az bir kez geçmesi gerektiğini belirtir.
- `?` sıfır ya da bir kez eşleşir.

Hoca bunlara dair örnekler gösterdi ve seçeneklerin çok fazla olduğunu, ayrıntı için Perl kılavuzuna bakılması gerektiğini söyledi. <!-- BELİRSİZ: 00:20:47-00:21:14 arasındaki örnek desenler karede görünmüyor; altyazıda yalnız bir desenin "front" ve "back" ile eşleşip "frnd" benzeri bir dizgiyle eşleşmediği duyuluyor. -->

### 3.4 Karakter sınıfları ve tekrar sayısı

Köşeli parantezler tek karakterlik bir sınıfla eşleşir. Gösterilen örneklerde bir desen herhangi bir tek rakamla eşleşiyordu ve hoca bunun başka bir gösterimle aynı olduğunu söyledi; bir başkası bir ya da daha çok rakamdan oluşan diziyle, bir başkası küçük harfli herhangi bir kelimeyle, bir diğeri büyük harfli bir kelimeyle eşleşiyordu. Sınıfın başına konan işaretle "bunlar dışındaki karakterler" anlamı elde edilir.

Süslü parantezler tekrar sayısının daha kesin belirtilmesini sağlar. Örneklerden biri tam 6 rakamlık bir diziyle, diğeri 6 ile 10 arası rakamdan oluşan bir diziyle eşleşiyordu. Hocanın deyişiyle olasılıklar sonsuzdur.

> **Ek bilgi (derste anlatılmadı):** Bu örneklerin Perl'deki yaygın yazımları şunlardır: tek rakam `[0-9]` ya da eşdeğeri `\d`; bir ya da daha çok rakam `[0-9]+`; küçük harfli kelime `[a-z]+`; büyük harfli kelime `[A-Z]+`; sınıf dışı karakter `[^...]`; tam 6 rakam `\d{6}`; 6 ile 10 arası rakam `\d{6,10}`.

### 3.5 Kaçış karakterleri, boşluk ve VEYA

Çoğu karakter kendisiyle eşleşir; ama bazı karakterler desende özel anlam taşıdığı için sözcük anlamıyla aranacaksa önüne ters bölü konarak kaçışlanmalıdır. Ters bölünün kendisi de buna dahildir.

Slayttaki kurallar (ekrandan, 00:25:00):

- `\s` boşluk karakterini belirtir; `[ \t\n\r\f]` karakter sınıfıyla aynıdır (boşluk, sekme, yeni satır, satır başı, sayfa besleme).
- Bir karakter onaltılık tabanda `\x` ve ardından iki onaltılık rakamla belirtilebilir; `\x1b` ESC karakteridir.
- `|` dikey çizgisi VEYA anlamına gelir. Slayttaki örnek:

```perl
if ($answer =~ /^y|^yes|^yeah/i ) { print "Affirmative!"; }
```

Bu satır, `$answer` değişkeninin "y", "yes" ya da "yeah" ile başlayıp başlamadığını denetler; sondaki `i` büyük/küçük harf ayrımını kaldırır ve eşleşme varsa "Affirmative!" yazdırılır.

### 3.6 Düzenli ifadelerin yeri

Hoca, Perl'deki bütün desen eşleştirmenin düzenli ifadeler kavramına dayandığını vurguladı. Düzenli ifadeler, neredeyse her metin desenini belirsizlik olmadan ifade etmenin standart yoludur. Bir karakter dizgisi kümesinden belirli dizgileri seçme mekanizmasıdır; bir arama deseninde bir dizgiyi ya da dizgi grubunu tanımlayan karakterler, meta karakterler ve operatörler topluluğudur.

> **Hocanın vurgusu:** Düzenli ifadeler bilgisayar biliminin önemli bir parçasıdır ve yalnızca bu konuya ayrılmış kitaplar vardır.

## 4. Katılık (Strictness)

Perl, değişkenlerin bildirilmeden önce kullanılmasına izin verir. Birçok dilde bir değişkeni kullanmadan önce türünü program başlamadan bildirmek gerekir; C'de de bütün fonksiyonlar ve değişkenler başta bildirilir. Perl'de bu zorunlu değildir. Aynısı alt yordamlar için de geçerlidir.

Perl'de bütün değişkenler varsayılan olarak globaldir. `my` ile bildirim, global bir değişkeni sözcüksel (lexical) bir değişkene çevirir. Böyle bir değişken `my` ile bildirildiği yerden içinde bulunduğu bloğun sonuna kadar yaşar. Varsayılan olarak `my` kullanımı isteğe bağlıdır; ama Perl'e `my` kullanımında ısrar ettirilebilir ve bu ısrara katılık (strictness) denir. Katılık programın başına şu satır eklenerek açılır (ekrandan, 00:30:00):

```perl
use strict;
```

Katılık açıkken bütün alt yordamlar ve fonksiyonlar da çağrılmadan önce bildirilmiş ya da tanımlanmış olmalıdır. Programlar büyüdükçe bakımı zorlaşır; bu yüzden hocaya göre katılık yapısını kullanmak her zaman daha güvenlidir.

Hoca bir örnek program gösterdi: başında `use strict;` olan ama değişkenlerini `my` ile bildirmeyen bir program çalıştırılmak istendiğinde Perl katılık kurallarının çiğnendiğinden yakınır, hata mesajı verir ve program çalışmaz. Bu derleme hataları, kullanılan skaler değişkenler başta `my` ile bildirilerek giderilir; düzeltilmiş kod yeniden çalıştırıldığında mesaj ya da hata olmadan çalışır.

Ayrıca `use subs` yönergesinden ve daha önce anılan, uyarıları açan `-w` anahtarından söz edildi. Bir başka anahtarın da bir modülün doğru kurulup kurulmadığını denetlediği söylendi. <!-- BELİRSİZ: modül denetimi için kullanılan anahtar ve `use subs` örneği altyazıda bozuk, karelerde görünmüyor. -->

## 5. Perl Tek Satırlıkları

Hoca, Perl'in derlenen bir dil gibi kullanılabildiği gibi bir betik (scripting) dili olarak da kullanılabildiğini hatırlattı: betik yazılıp çalıştırılabilir. Bu bağlamda "Perl tek satırlıkları" (one-liners) denen yapılar vardır.

### 5.1 `-e` anahtarı

`-e` anahtarıyla program komut satırına tek tırnak içinde yazılır. Slayttaki örnek (ekrandan, 00:35:00):

```text
perl -e 'print "Hello from a Perl one-liner.\n";'
```

Bu satır komut satırından çalıştırıldığında ekrana "Hello from a Perl one-liner." yazılır. Slaytta başka örnekler de vardı.

### 5.2 `-n` ve `-p` anahtarları

`-n` anahtarı `-e` ile birlikte kullanıldığında tek satırlığı bir döngüyle sarılmış gibi çalıştırır. Hocanın gösterdiği örnekte `perl -ne` ardından tek tırnak içinde bir `print if` deyimi ve bir karakter dizgisi, son olarak da EMBL veri dosyasının adı yazılıydı. Bu tek satırlık, dosyanın satırlarını tek tek okuyan bir `while` döngüsüne eşdeğerdir. Çalıştırıldığında dizgiyi içeren satırlar çıktı olarak üretilir. Hoca, Perl'in Unix ve C'den çok şey ödünç aldığını, aynı işin Unix'teki `grep` ile de yapılabileceğini gösterdi.

`-n` anahtarı `-p` ile birleştirildiğinde döngünün sonuna bir `print` deyimi de eklenir. Slayttaki örnek, EMBL veri dosyasından yalnız dört rakamla bitmeyen satırları yazdıran bir tek satırlıktı. Hoca bunun Unix'te `grep` ile yapılmasının biraz daha zor olduğunu, aynı sonucu almak için daha çok şey yazmak gerektiğini söyledi. <!-- BELİRSİZ: `-ne` ve `-p` örneklerinin tam komutları karelerde görünmüyor. -->

Hocaya göre bu yapı klasik programlar yazılırken de kullanılabilir: geleneksel `while` yapısı yerine tek satırlıklar kullanılarak çok daha kısa programlar elde edilir. Daha fazlası için Perl yardım dosyalarına ve kılavuzlarına bakılmalıdır.

### 5.3 Diğer komut satırı seçenekleri

Başka komut satırı seçenekleri de vardır (ekrandaki slayt başlığı "Perl One-Liners: More Options", 00:40:00). Hoca bunlardan otomatik bölme (autosplit), Unicode özelliklerini etkinleştirme, sözdizimi denetimi ve programı hata ayıklayıcı altında çalıştırmayı saydı. <!-- BELİRSİZ: seçeneklerin harfleri 00:40:00 karesinde okunmuyor. -->

## 6. Perl'den Başka Programları Çalıştırma

Perl içinden başka programlar çalıştırılabilir. İki temel yol vardır:

- Program, çalışma bittikten sonra çağıran programın çağrılan programın başarıyla çalışıp çalışmadığını anlayabileceği biçimde çağrılır. Bu, yerleşik `system` alt yordamının davranışıdır.
- Program, çalışma bittikten sonra çağrılan programın sonuçlarının çağıran programa döneceği biçimde çağrılır. Bu, ters tırnak (backticks) ve `qx` operatörünün davranışıdır.

Hoca örnek için DOS işletim sisteminin `dir` komutunu kullandı. `dir`, "directory" sözcüğünün kısaltmasıdır ve geçerli dizinin içeriğini verir; Windows komut isteminde yazılınca dizindeki dosyaları listeler. Perl programı içinden bu komut önce `system` ile (joker karakterlerle), sonra ters tırnakla, sonra `qx` ile çağrıldı. Hoca bu sırada bir yazımın çalışacağını, bir başka yazımın çalışmayacağını belirtti. <!-- BELİRSİZ: 00:44:07'de çalışan ve çalışmayan yazımların hangileri olduğu karelerde görünmüyor. -->

Program çalıştırıldığında dizin üç kez listelenir (ekrandan, 00:45:00). Çıktıda önce `dir` listesi doğrudan ekrana basılır ve "The result of the system call was as follows:" satırının altında `0` yazar; yani `system` çıktıyı değil, başarı durumunu döndürmüştür. Ardından "The result of the backticks call was as follows:" ve "The result of the qx// call was as follows:" başlıklarının altında dizin listesi yeniden görünür; bu iki yol komutun çıktısını programa döndürmüştür.

## 7. Hata Yakalama ve Sıralama

### 7.1 Hata yakalama

Perl'de hatalardan kurtulmak mümkündür; bu, programcıya program üzerinde denetim verir. Program bir hatayla karşılaştığında programdan çıkmadan hatadan kurtulabilir. Bunun için `die` fonksiyonu kullanılabilir; bu işe istisna yakalama (exception handling) denir. Slaytta bir örnek kod ve çalıştırıldığında alınan çıktı gösterildi; ardından değerlendirme fonksiyonu (`eval`) ile istisna yakalama örneği geldi. <!-- BELİRSİZ: istisna yakalama örneklerinin kodu karelerde görünmüyor; altyazıda bir disk dosyasının açılmasıyla ilgili olduğu seziliyor. -->

### 7.2 Sıralama

> **Hocanın vurgusu:** Sıralama, bir programlama dili öğrenilirken ilk öğrenilen kavramlardandır. Algoritma sınavlarında hemen her zaman sıralamayla ilgili bir iki soru olur.

Perl'de sıralama için iki güçlü fonksiyon vardır: `sort` ve `reverse`. Bunlarla dizgi ya da sayı listeleri artan, azalan ya da herhangi bir özel sıraya göre sıralanabilir.

Slayttaki programda dört kısa DNA dizisinden oluşan bir liste bir diziye atandı ve önce sıralanmadan ekrana yazdırıldı. Ardından:

- `sort` ile sıralama yapıldı.
- "b'den a'ya" karşılaştırmayla azalan sıralama yapıldı.
- `reverse sort` ile ters sıralama yapıldı.

Hoca, ilk durumda azalan sıra için "b'den a'ya" karşılaştırma kullanıldığını, "a'dan b'ye" karşılaştırmanın da kullanılabileceğini ya da doğrudan `reverse sort` yazılabileceğini anlattı: aynı kavramı uygulamanın her zaman başka yolları vardır.

İkinci örnekte sıralama sayılar üzerinde yapıldı; ilk örnek karakterler/dizgiler üzerindeydi. Hoca, her karakter bir sayıyla temsil edildiği için karakter sıralamasının sayılar üzerinde de çalıştığını söyledi. Sıralama hakkında daha fazla bilgi komut satırından Perl kılavuzu çağrılarak alınabilir.

> **Ders sonrası not:** Hoca karakter sıralamasının sayılarda da çalıştığını söyledi. Perl'de `sort` varsayılan olarak dizgi karşılaştırması yapar; bu yüzden sayılar karakter karakter karşılaştırılır ve `10`, `9`'dan önce gelir (`sort (10, 9, 2)` sonucu `10, 2, 9`; perl ile denetlendi). Sayısal sıralama için `sort { $a <=> $b } @liste` yazılır; dizgi karşılaştırmasıyla artan sıra `{ $a cmp $b }`, azalan sıra `{ $b cmp $a }` ile elde edilir.

Son olarak hoca, bir dosyanın satırlarını sıralayan bir programı ünlü bir şiire uyguladı. Türkçe karakterler doğru görüntülenmedi; programın çıktısında şiirin satırları alfabetik sıraya dizildiği için şiirin yapısı bozuldu.

## 8. Here Document

Ders arasından sonra hoca, bir metni program içinden ekrana tam olarak gösterildiği biçimde yazdırma gereksinimini ele aldı. Bu, arka arkaya `print` deyimleri kullanılarak yapılabilir; slaytta bu yol ve çıktısı gösterildi. Ancak daha iyi yol Perl'deki "here document" kavramıdır. Hocanın gösterdiği örnekte bir pompalı tüfek dizileme (shotgun sequencing) mesajı, bir başlangıç etiketiyle bitiş etiketi ("EndShotgunMessage" benzeri) arasına olduğu gibi yazılıp `print` ile basılıyordu. Böylece metin program içindeki biçimiyle aynen ekrana çıkar. <!-- BELİRSİZ: here document örneğinin tam kodu karelerde görünmüyor; etiket adı altyazıdan tahmin edildi. -->

## 9. Veri Kümelerini İndirme

### 9.1 Yerel kopyanın üstünlükleri ve sakıncaları

Veri kümesini indirip yerelde saklamanın üstünlükleri şunlardır:

- Güvenilirlik: uzak bağlantıda veri kaybı olabilir, yerel kopya daha güvenilirdir.
- Kararlılık.
- Esneklik.
- Güvenlik: internete bağlı olunmadığı için.

Her şeyin üstünlükleri yanında sakıncaları da vardır:

- Bayat veri: yerel kopya, veri kümesinin belirli bir andaki tek seferlik görüntüsüdür; güncel olmayabilir.
- Depolama: veritabanı çok büyükse yerel diskte ek yer gerekir.
- Başarım: uzak sunucuların çoğu zaman çok daha iyi donanımı, paralel işleme sistemleri ve daha hızlı, yüksek başarımlı hesaplama sistemleri vardır.

### 9.2 İndirme yolları

Veri kümeleri birkaç yolla indirilebilir. Birincisi hazır (off-the-shelf) dizi analizi programlarıdır; hoca bunlardan EMBOSS'u andı ve web sitesini gösterdi. Bunlar indirme için özel yöntemler sunar. İkincisi `wget` programıdır; her Linux dağıtımında bulunan ücretsiz bir yazılımdır. Hoca slaytlarına `wget` kullanımına dair bilgi koyduğunu ama amacının Linux öğretmek olmadığı için bu bölümü atladığını, ilgilenenlerin Linux'ta programı deneyebileceğini söyledi.

Web üzerinden indirme de bir yoldur: oldukça etkileşimli bir mekanizmadır ve tek tek veri dosyalarını indirmek için kullanışlıdır (ekrandan, 01:10:00). Ardından gelen "Mirroring a dataset" (bir veri kümesini aynalamak) başlıklı slayt da bütünlük için tutulmuş slaytlardandı (ekrandan, 01:15:00).

Hoca, Protein Data Bank'e, daha önce anlattığı veri dosyası yapılarına ve veritabanlarına ait slaytları da atladı. Veri madenciliği, veri küratörlüğü (curation), veri temizleme ve fazlalık (redundancy) gibi konuların veri bilimi derslerinde öğrenildiği gibi biyoenformatik veritabanları için de geçerli olduğunu belirtti.

## 10. Veritabanı Kavramları

Hoca, biyoenformatikte çok büyük veritabanlarıyla çalışıldığı için veritabanlarına ait bazı temel kavramları hatırlatmak istedi; konunun dersin kapsamı dışında olduğunu, bu yüzden üzerinde çok durmayacağını belirtti. Slayttaki giriş şöyleydi (ekrandan, 01:20:00): modern bilgisayar sistemlerinin çoğu çok büyük miktarda yapılandırılmış veri saklar ve bu veri genellikle bir veritabanı sisteminde tutulur.

### 10.1 Veritabanı, tablo, satır

Hoca "veritabanı nedir?" diye sordu (bkz. Örnek Sorular). Tanımda anahtar sözcük "tablo"dur:

- Veritabanı: bir ya da daha çok ilişkili tablonun topluluğu.
- Tablo: bir ya da daha çok veri satırının topluluğu.
- Satır: sütunlar halinde düzenlenmiş bir ya da daha çok veri öğesinin topluluğu.

Bu farklı varlıklar arasındaki ilişki bir veritabanını oluşturur. Slaytta bir örnek tablo da gösterildi.

### 10.2 Veritabanı sistemi

Hoca ikinci olarak veritabanı sisteminin ne olduğunu sordu. İlişkisel ve nesneye yönelik gibi farklı veritabanı türleri olduğunu, ama burada türlerin önemli olmadığını söyledi. Veritabanı sistemi, verileri ya da veritabanlarını denetleyen bir yazılımdır. Daha kesin tanımla, bir ya da daha çok veritabanını tanımlamak (oluşturmak) ve işlemek için mekanizma sağlayan bir bilgisayar programı ya da programlar grubudur. Bir veritabanı sistemi veritabanlarının, tabloların ve sütunların oluşturulmasına ve adlandırılmasına, yapıların tanımlanmasına izin verir.

### 10.3 Mevcut veritabanı sistemleri

Hoca hangi veritabanı sistemlerinin bulunduğunu sordu; öğrenciler Oracle gibi örnekler verdi. Hoca tek tek ad saymak yerine sistemleri sınıflandırmanın daha iyi olduğunu söyledi. Sınıflandırma ölçütleri veritabanının ölçeği, maliyeti ve üzerinde çalıştığı hesaplama platformudur:

- Kişisel veritabanı sistemleri: kişisel bilgisayarlarda (PC) çalışmak üzere tasarlanmış küçük ölçekli programlar.
- Kurumsal (enterprise) veritabanı sistemleri: genellikle büyük şirketlerin alabildiği, binlerce hatta milyonlarca dolara mal olan sistemler. Güçlü hesaplama platformları ve çok büyük bellek gerektirir.
- Açık kaynak veritabanı sistemleri: hoca üçüncü sınıfı tahmin etmelerini istedi, öğrenciler Postgres gibi örnekler verdi. Bunlar ücretsizdir, Linux sistemlerinde çok yaygındır, PC sürümleri de vardır; büyük olasılıkla öğrencilerin küçük projelerinde kullandığı sistemlerdir.

Hangi veritabanı sisteminin seçileceği birçok etkene, örneğin veri miktarına bağlıdır. <!-- BELİRSİZ: 01:29:58-01:30:20 arasında sayılan diğer seçim etkenleri altyazıda bozuk. -->

### 10.4 SQL ve Perl DBI

Veritabanlarının dili SQL'dir (Structured Query Language). SQL iki olanak sağlar:

- Veri tanımlama dili (DDL): veritabanlarının oluşturulması için mekanizma sağlar.
- Veri işleme dili (DML): tablolardaki veriyle çalışmak, yani veriyi değiştirmek, silmek, eklemek için mekanizma sağlar.

Perl, veritabanlarıyla çalışmayı da destekler. Bu iş için indirilebilecek pek çok modül vardır; slaytta mavi yazıyla gösterilen modül DBI (database interface, veritabanı arayüzü) modülüdür ve MySQL ile birlikte anıldı. DBI ile veritabanları programlanabilir; veritabanlarını işlemek için pek çok yararlı fonksiyonu vardır. Hoca ayrıca biyoenformatikçilerin kullandığı dizi erişim sistemlerinden (sequence retrieval systems) söz etti.

## 11. Web Teknolojileri ve Perl

### 11.1 Web altyapısının bileşenleri

Birçok şey web sistemlerine dayandığı için hoca web teknolojilerini de hatırlattı. Dünya Çapında Ağ (World Wide Web), hocaya göre 1991'de Tim Berners-Lee tarafından icat edildi. Bu da büyük ve kapsam dışı bir konudur, ama temel web teknolojilerini hatırlamak yararlıdır.

> **Ders sonrası not:** Hoca WWW'nin 1991'de icat edildiğini söyledi. Tim Berners-Lee önerisini büyük olasılıkla 1989'da CERN'de yazmış, ilk web sitesi ve web'in kamuya açılması 1991'de gerçekleşmiştir; iki tarih de kaynaklarda geçer.

Hoca bir web altyapısı kurmak için nelerin gerektiğini sordu ve cevapları öğrencilerle birlikte kurdu (bkz. Örnek Sorular). Sonuçta bileşenler şöyle sıralandı:

- Web sunucusu: bir programdır; slaytta örnekleri vardı.
- Web istemcisi: web tarayıcısıdır (Chrome, Mozilla, Explorer gibi).
- Taşıma protokolü: HTTP. Sunucu ile istemci arasında bir el sıkışma olmalıdır.
- Web içeriği: HTML (hypertext markup language).
- Veri: arka planda veritabanı.
- Ek bileşenler: istemci tarafı programlama, sunucu tarafı programlama.

> **Ders sonrası not:** Hoca HTTP'yi "hypertext transport protocol" diye açtı; doğrusu "Hypertext Transfer Protocol"dür.

### 11.2 Web sayfası oluşturmanın üç yolu

- Elle oluşturma: HTML'e hâkim olan biri herhangi bir metin düzenleyiciyle sayfayı HTML biçiminde yazıp yayımlayabilir. Slayttaki nota göre bu yol zaman alıcı ve sıkıcı olabilir, çünkü sayfayı yazan kişi içeriği yazmanın yanında hangi etiketlerin nerede kullanılacağına da karar vermek zorundadır (ekrandan, 01:40:00).
- Hazır araçlar: Dreamweaver gibi programlarla sayfa görsel olarak oluşturulur; Microsoft araçlarıyla da durağan sayfalar yapılabilir.
- Web programlama: sayfa içeriğinin zamanla değişmesi gerekiyorsa dinamik sayfa gerekir ve bunun programlanması gerekir. PHP, Python ya da Perl gibi herhangi bir dil kullanılabilir.

### 11.3 Perl ile web sayfası

Perl'in durağan ve dinamik web sayfası oluşturmak için kapsamlı desteği vardır. En basit yol, daha önce anlatılan here document içine HTML kodunu yazmaktır; program basit bir HTML belgesi üretir ve bu belge yayımlanır. Bir başka yol Perl'in standart CGI modülüdür. Bu modülün web sayfası oluşturmak için yararlı fonksiyonları vardır: örneğin HTML'yi başlatan ve bitiren fonksiyonlar (`start_html` ve `end_html`) arasına sayfanın gövdesi yazılır. Slaytta programın ürettiği basit bir dosya da gösterildi.

> **Ders sonrası not:** Hoca CGI'ı tereddütle "Common Gate Interface" diye açtı; doğrusu "Common Gateway Interface"tir.

Dinamik sayfa için sunucu tarafı programlama gerekir. Örnek olarak tarih ve saatin değiştiği bir sayfa gösterildi: "what time" programı her çağrıldığında o anki saat görülür, bir sonraki çağrıda gerçek saat değişmiş olur. Bunun için dinamik sayfa, yani web programlama gerekir.

### 11.4 Güvenlik ve web otomasyonu

Web sayfalarında bir başka önemli nokta güvenliktir. Perl web'de daha güvenli olmak için bazı olanaklar sunar. Slayttaki not şöyleydi (ekrandan, 01:45:00): programın başında `-T` komut satırı seçeneği kullanılırsa Perl'ün "taint mode"u açılır; bu da programın davranışı üzerinde bir dizi özel güvenlik denetimi etkinleştirir. Hoca bu bölümün ayrıntısını atladı.

Bir diğer kavram web otomasyonudur. Perl, Mechanize adlı bir modül sağlar; bu modül programcının herhangi bir web sitesiyle etkileşimi otomatikleştirmesine izin verir. Örneğin uzaktaki bazı veri dosyalarını 100 kez indirmek ya da açmak gerekiyorsa bunu otomatikleştiren basit bir mekanizma Mechanize ile kurulabilir.

### 11.5 Perl bölümünün kapanışı

Hoca Perl'i anlatmasının nedeninin, Perl'in alışılmış programlama dillerinden farklı kavramlar içermesi olduğunu söyledi. Bir öğrencinin sorusuna verdiği cevapta şu dersi çıkardı:

> **Hocanın vurgusu:** Her hesaplama platformu ya da programlama dili klasik yaklaşımların yanında işleri kolaylaştıran alışılmadık yaklaşımlar sunabilir; bunları kullanın. Kullandığınız ortamı ve platformu anlarsanız işler çok kolaylaşır. Amacınıza en uygun dili bulmaya çalışın.

## 12. İkili Dizi Hizalamaya Giriş

### 12.1 Konunun kapsamı

Ders arasından sonra biyoenformatiğin ilk asıl konusuna geçildi: ikili dizi hizalama (pairwise sequence alignment). Hoca bu konunun bir iki hafta süreceğini söyledi. İkili hizalama teknikleri hesaplamalı yaklaşımlardır ve bilgisayar mühendisliği becerileriyle doğrudan ilgilidir. Ele alınacak kavramlar: nokta matrisi (dot matrix), skor matrisleri, boşluk cezaları (gap penalties) ve dinamik programlama yaklaşımları.

### 12.2 İki dizi ilişkili mi?

Slayttaki giriş şöyleydi (ekrandan, 02:10:00): moleküler biyolojide sık sorulan bir soru, iki dizinin ilişkili olup olmadığıdır. Bunu anlamanın en yaygın yolu, dizileri birbiriyle karşılaştırıp benzer olup olmadıklarına bakmaktır. Soru: iki dizi ilişkili mi? Yöntem: iki diziyi karşılaştır, benzer mi bak.

Hoca soruyu açtı: iki dizi aynı mı? Değilse ilişkililer mi? Hangi bakımdan ilişkililer: yapısal olarak mı, işlevsel olarak mı? Bu karşılaştırmalar DNA ya da amino asit veritabanları üzerinde yapıldığı için derslerin başında metin işlemenin önemi vurgulanmış ve Perl anlatılmıştı; ama Java, C ya da başka herhangi bir dil de kullanılabilir.

> **Hocanın vurgusu:** Dizi hizalama biyoenformatiğin temel aracıdır.

### 12.3 "pear" ve "tear" örneği

Hoca örnek olarak "pear" ve "tear" kelimelerini aldı ve bunların ilişkili olup olmadığını sordu. Bir öğrenci "hayır" dedi. Hoca "hayır" diyorsak bir gerekçe vermemiz gerektiğini söyledi. Temsil ettikleri şey bakımından ilişkili değillerdir: biri bir meyvedir (armut), diğeri bir sıvıdır (gözyaşı). Anlamları farklıdır; yani burada bir ölçüt kullanılmıştır.

Ama bu iki kelime bir şiirde kullanılırsa ses bakımından ilişkilidir: çok benzer seslenirler ve uyak oluştururlar. Harf harf karşılaştırılırsa dört harften üçü ortaktır; bu bakımdan da çok benzerdirler. Yani benzer olup olmadıklarına karar vermek bakış açısına bağlıdır. Hocaya göre biyoenformatikteki benzerlik kavramı da bu yaklaşıma çok benzer; ileride görülecek bütün algoritma ve teknikler buna dayanır.

## 13. Benzerlik, Homoloji ve Hizalama Terimleri

### 13.1 Benzerlikten ne öğrenilir?

Biyolojiden bilindiği gibi benzer biyolojik diziler bir şekilde ilişkili olma eğilimindedir. Evrim kuramına göre bazı türler ortak bir atadan gelebilir; bu yüzden benzer biyolojik dizilere sahiptirler ve bu bilgi onların ilişkili olduğuna inanmamızı sağlar. Benzerlik çalışmaları üç tür bilgi çıkarabilir: işlevsel bilgi, yapısal bilgi ve evrimsel ilişki.

### 13.2 Homolog, ortolog, paralog, ksenolog

Hoca bazı biyolojik kavramları hatırlattı:

- Homologlar: ortak bir ata diziden türemiş, iki farklı organizmadaki benzer dizilerdir. İki ayrı tür ortak atadan geliyorsa bunlara ait dizilere homolog diziler denir.
- Ortologlar: bir türleşme (speciation) olayı sonucunda ortaya çıkmış, iki farklı organizmadaki benzer dizilerdir. Burada işlev korunur.
- Paraloglar: bir gen eşlenmesi (gene duplication) olayı sonucunda ortaya çıkmış, tek bir organizma içindeki benzer dizilerdir.
- Ksenologlar: yatay aktarım olaylarıyla (simbiyoz, virüsler vb.) ortaya çıkmış benzer dizilerdir.

Bunların hepsi organizmalarda gerçekleşen biyolojik, kimyasal ya da elektrokimyasal süreçlerdir. Slaytta homolog, ortolog ve paralog ilişkileri bir ağaç üzerinde de gösterildi.

### 13.3 Neden protein dizileri?

Benzerlik aramalarında protein ya da DNA dizileri kullanılır. Slayt başlığı "Benzerlik aramalarında protein dizilerini kullanın" idi ve ilk madde şuydu (ekrandan, 02:20:00): DNA dizileri protein dizilerinden daha az bilgilendirici olma eğilimindedir. Hocanın açıklamaları:

- DNA'da dört baz vardır, protein dizileri ise 20 amino asitle oluşur; bu bakımdan rastgele benzerlik şansı proteinlerde daha azdır.
- Amino asitlerin benzerliği skorlanabilir: mutasyon sayısı, kimyasal benzerlik ya da ileride görülecek PAM gibi skor matrisleriyle.
- Protein veri bankaları DNA veri bankalarından çok daha küçüktür.
- Sonuç olarak rastgele eşleşme daha azdır.

Benzerlik, farklı dizilerin ikili hizalanmasıyla belirlenir. Hoca bu kavramların bazılarının henüz tanıdık gelmeyebileceğini, zamanla tanıdık hale geleceğini söyledi.

### 13.4 Hizalamanın doğası

İki dizinin (DNA ya da protein) hizalanması görece kolay, doğrudan bir hesaplama problemidir. Ancak hizalamanın anlamlılığı (significance) da değerlendirilmelidir; bu ileride ele alınacak. Hizalamalar skorlanmalıdır. İki dizi verildiğinde pek çok olası hizalama vardır ve çoğu zaman aynı skora sahip birden çok çözüm bulunur. Hizalama kavramı, iki dizinin karşılıklı yerleştirilmesidir.

### 13.5 Özdeşlik, benzerlik, homoloji

- Dizi özdeşliği (identity): aynı konumda tam olarak aynı amino asit ya da nükleotit bulunması.
- Dizi benzerliği (similarity): harfler ya da kalıntılar (residue) hizalanır; bazı farklar benzer kimyasal özellikli yer değiştirmelerden kaynaklanabilir. Kalıntılar kimyasal maddeler olduğu için bir madde benzer özellikli başka bir maddeyle yer değiştirmiş olabilir.
- Dizi homolojisi: diziler arasındaki evrimsel akrabalığı gösteren genel terim; ortak atadan gelme.

### 13.6 Hizalamada dikkat edilecekler

- En iyi hizalamayı bulmak için bütün olası hizalamaları incelemek gerekir.
- Olası hizalamaların niteliğini yansıtmak için skorlanmaları gerekir.
- Aynı en yüksek skora sahip farklı hizalamalar olabilir.
- Skor şemasındaki değişiklikler hizalamaların sıralamasını değiştirebilir.

Hoca son maddeyi "pear"/"tear" örneğine bağladı: bakış açısı anlamsa sonuç tamamen farklı, ses ya da ortak harfse sonuç çok yakın çıkar. Skor şemaları bu bakış açılarını temsil eder ve ileride ele alınacak.

### 13.7 Evrimsel örnek: ABCD

Slayttaki kurgusal örnek (ekrandan, 02:30:00):

```text
           Ata dizi: ABCD
          /              \
   ACCD (B -> C)      ABD (C -> ø)
     mutasyon            silme
```

Ata dizideki B, C'ye dönüşmüş ve yeni bir alt tür dizisi ACCD ortaya çıkmıştır; buna mutasyon denir: bir kimyasal madde başka birine dönüşür. Diğer alt tür ABD ise ata diziden bir kalıntı kısadır; büyük olasılıkla C bir mutasyon ya da başka bir nedenle kimyasal olarak çıkarılmıştır; buna silme (deletion) denir.

ACCD ile ABD karşılaştırılırken bir olası hizalama gösterildi; birden çok hizalama mümkündür. Hoca, dizi hizalamanın bir optimizasyon problemi olduğunu söyledi: bir ölçüte göre en iyi hizalama belirlenmek istenir. Bir hizalama diğerinden daha olası olabilir, ikisi de mümkün ya da doğru olabilir; bu tamamen hizalamaları değerlendirdiğimiz ölçüte bağlıdır. <!-- BELİRSİZ: ACCD ile ABD için gösterilen hizalamaların tam yazımı karelerde görünmüyor. -->

### 13.8 Eşleşme, uyuşmazlık ve indel

Slaytta bir protein ve bir DNA dizi hizalaması gösterildi (ekrandan, 02:35:00):

```text
Protein hizalaması:
MSTGAVLIY--TSILIKECHAMPAGNE-----
---GGILLFHRTHELIKESHAMANDEGGSNNS
   *  *    *  **** ***

DNA hizalaması:
attcgttggcaaatcgcccctatccggccttaa
att---tggcggatcg-cctctacgggcc----
***   ****  **** **    ******
```

Hizalamayı değerlendirmenin ilk yolu eşleşen harfleri (amino asit kalıntılarını) saymaktır. Yıldızla işaretlenen konumlar eşleşmedir. Terimler şöyledir:

- Eşleşme (match): ikili hizalamada iki harf aynıysa.
- İndel: tireler ekleme (insertion) ya da silme (deletion) sonucudur; bunlara indel denir.
- Uyuşmazlık (mismatch): harfler farklıysa. Yıldızı olmayan bütün harf çiftleri uyuşmazlıktır.

Protein hizalamasında karedeki yıldız satırı 10 eşleşme gösterir; python ile yapılan sayım da 10 eşleşme, 12 uyuşmazlık ve 10 indel sütunu verir. DNA dizisi dört harften oluşur; hoca DNA hizalamasında aynı harfleri eşleşme, farklı harfleri (örneğin ilk boşluktan sonraki bölgedeki a/g çiftleri) uyuşmazlık olarak işaretledi ve tireleri yine indel olarak gösterdi. <!-- BELİRSİZ: DNA hizalamasının harfleri düşük çözünürlüklü kareden okundu; karedeki yıldız satırı 19 eşleşme gösteriyor, ama okunan harflerle yapılan sayım 18 eşleşme veriyor (son yıldız grubundaki 25. sütunda c/g görünüyor). Bir harf yanlış okunmuş olabilir. -->

## 14. Mesafe Ölçüleri: Hamming ve Levenshtein

### 14.1 Hangi ölçü?

Hoca bir ikili hizalamayı nesnel olarak değerlendirmek için hangi ölçütün kullanılabileceğini sordu. Diziler temelde iki dizgi ya da iki karakter dizisidir; bunların benzer olup olmadığını görmek için hangi metrik kullanılır? Bir öğrenci düzenleme mesafesi (edit distance) dedi; hoca bunun doğru bir cevap olduğunu söyledi. Burada kullanılacak kavramlar veri madenciliği ve makine öğrenmesindeki kavramlara çok benzer.

Önce verinin türü belirlenmelidir. Hoca DNA dizilerinin veri türü bakımından ne olduğunu sordu (bkz. Örnek Sorular). Veri biliminde iki genel veri türü vardır: sayısal (nicel) ve kategorik (nitel). Sayısal verinin iki alt türü ayrık ve süreklidir; kategorik verinin iki alt türü nominal ve sıralıdır (ordinal). Amino asit ve DNA dizileri kategorik veridir. Kategorik veri için akla gelen ilk metrik düzenleme mesafesidir; dizilerin benzerlik derecesini nicel olarak belirtmenin en basit yollarından biridir. Başka bir yaklaşım, kategorik dizileri bir şekilde sayısal dizilere dönüştürüp sayısal veri için kullanılan metrikleri ve teknikleri uygulamaktır.

### 14.2 Mesafe benzemezliği ölçer

Hoca mesafenin neyi ölçtüğünü sordu. Bir öğrenci "dizilerin benzerliğini" dedi; hoca bunun yanlış olduğunu söyledi.

> **Hocanın vurgusu:** Mesafe, dizilerin benzemezliğini (dissimilarity) ölçen bir ölçüdür. Benzerlik ile benzemezlik arasında fark vardır. Benzerlik için korelasyon kullanılır; korelasyon benzerlik, mesafe benzemezlik metriğidir.

### 14.3 Hamming mesafesi

Hoca, Hamming ya da düzenleme mesafesinin eşleşmeleri mi, uyuşmazlıkları mı, indel'leri mi sayarak bulunduğunu bir test sorusu olarak sordu. Cevap: Hamming mesafesinde uyuşmazlıklar sayılır. Uyuşmazlık sayısı sıfırsa mesafe sıfırdır; bu, iki dizinin tamamen aynı olduğu anlamına gelir.

Slayttaki ifade (ekrandan, 02:45:00): dizi benzerliğini belirlemenin en basit yöntemi iki dizi arasındaki düzenleme mesafesini bulmaktır. "pear" ve "tear" örneğinde bu iki kelime ne kadar benzerdir? Hamming mesafesi, iki kelimenin farklı olduğu en az harf sayısıdır. Kelimeler iki satıra alt alta yazılıp harfler çiftlenir:

```text
p e a r
t e a r
x
```

Yalnız ilk konumda fark vardır; Hamming mesafesi 1'dir. Böylece elimizde bir metrik olur.

### 14.4 Boşluklu hizalama ve Levenshtein mesafesi

Önceki örnekte harfler doğrudan alt alta yazılmıştı. Ama boşluk içeren hizalamalar da vardır; bunlara boşluklu hizalama (gapped alignment) denir. Slayttaki açıklama (ekrandan, 02:50:00): biyolojik dizilerde çoğu zaman farklı uzunluktaki ya da zamanla eklenmiş veya silinmiş bölgeler içeren iki diziyi hizalamak gerekir. Bu yüzden boşluk kavramı getirilmelidir; boşluklar `-` ile gösterilir. Önceki hizalamalardaki tireler bu boşluklardır.

Örnek "alignment" ve "ligament" kelimeleridir. Bunlar iki farklı kelimedir ("ligament" vücuttaki bağ dokusudur), ama bir hizalaması şöyledir:

```text
A L I G N M E N T
- L I G A M E N T
```

Burada baştaki tire bir boşluktur (indel). Büyük olasılıkla özgün kelimeden A silinmiş ve "ligament" ortaya çıkmıştır; hizalamada A'ya bir tire karşılık gelir.

Hoca bu hizalamanın düzenleme mesafesini sordu. Sınıfta 2 cevabı da duyuldu; hoca yalnız uyuşmazlıkları saymayı hatırlattı. Harfler tek tek karşılaştırılınca (L-L, I-I, G-G, N-A, M-M, E-E, N-N, T-T) tek uyuşmazlık N/A çiftidir; Hamming mesafesine göre hizalama skoru 1'dir.

Ama bu bir boşluklu hizalamadır. Boşlukları hesaba katmak için Levenshtein mesafesi önerilmiştir. Levenshtein mesafesi boşlukları da sayar; derste verilen tanımla uyuşmazlıklar artı boşluklar Levenshtein mesafesini verir. Bu hizalama için Levenshtein mesafesi $1 + 1 = 2$'dir.

> **Ek bilgi (derste anlatılmadı):** Hamming mesafesi esas olarak eşit uzunluktaki dizgiler için tanımlıdır. Levenshtein mesafesi ise bir dizgiyi diğerine dönüştürmek için gereken en az tek karakterlik ekleme, silme ve yer değiştirme sayısıdır; yani belirli bir hizalamanın maliyeti değil, bütün hizalamalar arasındaki en küçük maliyettir. "alignment" ile "ligament" için bu en küçük değer de 2'dir (python ile denetlendi). Bu en küçük değer, ileride anlatılacağı belirtilen dinamik programlamayla hesaplanır.

### 14.5 Hizalamanın olası sonuçları

Hoca özet olarak bir hizalamanın her sütunda şu durumlardan birini üretebileceğini söyledi:

- İki karakter arasında eşleşme.
- İki karakter arasında uyuşmazlık: biyolojide yer değiştirme (substitution) ya da mutasyonu temsil eder.
- Birinci dizide boşluk: birinci diziden bir karakterin silinmesi, yani özgün türden bir kimyasal maddenin çıkarılması olarak düşünülebilir.
- İkinci dizide boşluk: birinci diziye bir karakterin eklenmesi, yani birinci diziye bir kimyasal maddenin eklenmesi olarak düşünülebilir.

Bunlar hizalamalarda temsil edilen olası kalıntı durumlarıdır.

### 14.6 Hangi hizalama daha iyi?

Ders, kavramları pekiştirmek için bir soruyla bitti: iki dizi ve iki geçerli hizalama verildi ve hangisinin daha iyi olduğu soruldu (soru metni ve çözüm için bkz. Örnek Sorular). Hoca, birinci ya da ikinci demeden önce bir ölçütle değerlendirme yapmak gerektiğini söyledi. Şimdiye kadar görülen ölçütler Hamming ve Levenshtein mesafeleridir; şimdilik bu düzenleme mesafeleri seçim ölçütü olarak alınır, mesafe hesaplanır ve hangi skorun daha iyi olduğuna karar verilir. Başka bir skor metriği de kullanılabilir; konu bir sonraki derste sürecek.

## Örnek Sorular

**Soru 1** (ekrandan, 02:55:00): ACGGACT ve ATCGGATCT nükleik asit dizileri için aşağıdaki iki hizalama geçerlidir. Hangisi daha iyi hizalamadır?

```text
Hizalama 1:
A - C - G G - A C T
|   |   |       | |
A T C G G A T - C T

Hizalama 2:
A T C G G A T C T
|   | | |     | |
A - C G G - A C T
```

> **Çözüm (derste verilmedi):** Ölçüt olarak derste verilen tanımlar alınırsa (Hamming = uyuşmazlık sayısı, Levenshtein = uyuşmazlık + boşluk sayısı):
>
> - Hizalama 1: 5 eşleşme (A, C, G, C, T), 1 uyuşmazlık (G/A), 4 boşluk. Hamming 1, Levenshtein $1 + 4 = 5$.
> - Hizalama 2: 6 eşleşme (A, C, G, G, C, T), 1 uyuşmazlık (T/A), 2 boşluk. Hamming 1, Levenshtein $1 + 2 = 3$.
>
> Hamming mesafesi iki hizalamayı ayırt edemez (ikisi de 1). Boşlukları da sayan Levenshtein ölçütüne göre mesafe küçük olan Hizalama 2 daha iyidir. Sayımlar python ile denetlendi. Bu iki dizi arasındaki en küçük Levenshtein mesafesi 2'dir (ATCGGATCT'den iki T silinerek ACGGACT elde edilir); yani bu iki hizalamadan daha iyisi de vardır.

**Soru 2** (derste sözlü, 02:42:08): Hamming ya da düzenleme mesafesi eşleşmeler mi, uyuşmazlıklar mı, indel'ler mi sayılarak bulunur?

Cevap (derste verildi, 02:45:12): Hamming mesafesinde uyuşmazlıklar sayılır. Uyuşmazlık sayısı sıfırsa mesafe sıfırdır ve diziler tamamen aynıdır.

**Soru 3** (ekrandan, 02:45:00): "pear" ve "tear" kelimeleri ne kadar benzerdir?

Cevap (derste verildi): Anlam bakımından ilgisizdirler (meyve ve gözyaşı), ses bakımından uyaklıdırlar, harf bakımından dört harften üçü ortaktır. Hamming mesafesi 1'dir.

**Soru 4** (derste sözlü, 02:49:38): "alignment" ile "-ligament" hizalamasının düzenleme mesafesi nedir?

Cevap (derste verildi): Yalnız uyuşmazlıklar sayılırsa tek uyuşmazlık N/A çiftidir; Hamming mesafesi 1'dir. Boşluğu da sayan Levenshtein mesafesi 2'dir.

**Soru 5** (derste sözlü, 02:37:56): Veri biliminde kaç genel veri türü vardır? DNA ve amino asit dizileri hangi türdendir?

Cevap (derste verildi): İki genel tür vardır. Sayısal (nicel) verinin alt türleri ayrık ve sürekli; kategorik (nitel) verinin alt türleri nominal ve sıralıdır. DNA ve amino asit dizileri kategorik veridir.

**Soru 6** (derste sözlü, 02:42:39): Mesafe ne tür bir ölçüdür, neyi değerlendirmek için kullanılır? Benzerlik neyle ölçülür?

Cevap (derste verildi): Mesafe benzemezliği (dissimilarity) ölçer. Benzerliği ölçmek için korelasyon kullanılır.

**Soru 7** (derste sözlü, 01:36:02): Bir web altyapısı geliştirmek için neler gerekir?

Cevap (derste öğrencilerle birlikte kuruldu): Önce bir sunucu; sunucunun hizmet ettiği bir istemci (tarayıcı); ikisinin konuşması için bir protokol (HTTP); birbirlerini anlamaları için içerik dili (HTML); arka planda veritabanı. Ek olarak istemci ve sunucu tarafı programlama.

**Soru 8** (derste sözlü, 01:18:41): Veritabanı nedir?

Cevap (derste verildi): Bir ya da daha çok ilişkili tablonun topluluğudur; anahtar sözcük tablodur. Tablo satırların, satır ise sütunlarda düzenlenmiş veri öğelerinin topluluğudur.

**Soru 9** (derste sözlü, 01:24:43): Mevcut veritabanı sistemleri nelerdir?

Cevap (derste verildi): Tek tek ad saymak yerine sınıflandırılır: kişisel (PC, küçük ölçek), kurumsal (pahalı, güçlü platform) ve açık kaynak (ücretsiz, Linux'ta yaygın). Sınıflandırma ölçek, maliyet ve platforma dayanır.

## Dersin Toparlaması

Dersin ilk yarısı Perl anlatımını tamamladı: operatörler, alt yordamlar, düzenli ifadelere dayanan desen eşleştirme, `use strict` ile katılık, komut satırı tek satırlıkları, `system`/ters tırnak/`qx` ile başka programları çağırma, `die`/`eval` ile hata yakalama, `sort`/`reverse` ile sıralama ve here document. Ardından biyoenformatik verileriyle çalışmanın altyapısı hatırlatıldı: veri kümelerini yerel indirmenin artı ve eksileri, veritabanı ve veritabanı sistemi kavramları, SQL'in DDL ve DML bileşenleri, Perl'in DBI modülü, web altyapısının bileşenleri, CGI ile web sayfası üretimi, taint mode ve Mechanize ile web otomasyonu. Hocanın genel mesajı, kullanılan dilin ve platformun alışılmadık kolaylıklarını tanıyıp amaca en uygun aracı seçmekti.

İkinci yarıda dersin asıl konusu olan ikili dizi hizalamaya girildi. İki dizinin ilişkisinin benzerlikle anlaşıldığı, benzerliğin bakış açısına (skor şemasına) bağlı olduğu "pear"/"tear" örneğiyle gösterildi. Homolog, ortolog, paralog ve ksenolog kavramları, protein dizilerinin benzerlik aramasında neden tercih edildiği, eşleşme/uyuşmazlık/indel terimleri ve hizalamanın bir optimizasyon problemi olduğu anlatıldı. Kategorik veri için mesafe ölçüleri olarak Hamming (uyuşmazlık sayısı) ve Levenshtein (uyuşmazlık + boşluk) tanıtıldı. Derste bir sonraki hafta bu konuya devam edileceği, ardından nokta matrisi, skor matrisleri, boşluk cezaları ve dinamik programlama yaklaşımlarının ele alınacağı belirtildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
