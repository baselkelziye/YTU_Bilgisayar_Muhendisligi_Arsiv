# Ders 10 Genişletilmiş Notu: Veri Depolama Yapıları, Dosya Organizasyonu ve İndekslemeye Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Fiziksel Tasarıma Giriş ve İndeks Fikri
- 2. Dosyalar, Kayıtlar ve Disk Sayfası
- 3. Sabit Uzunluklu Kayıtlar
- 4. Değişken Uzunluklu Kayıtlar
- 5. Dosya Organizasyonları
- 6. Partitioning
- 7. Veri Sözlüğü (Katalog)
- 8. Depolama Erişimi ve Tampon
- 9. İndekslemeye Giriş: Temel Kavramlar
- 10. Sıralı İndeksler: Clustering ve Secondary
- 11. Dense ve Sparse İndeksler
- 12. İndeksin Maliyeti: Clustering ve Nonclustering
- Örnek Sorular
- Dersin Toparlaması

Ders Zoom üzerinden yapıldı. Hoca ders kitabının (Database System Concepts, 7. baskı, Silberschatz, Korth ve Sudarshan) 13. bölüm (Data Storage Structures) PowerPoint sunusunu, aradan sonra da 14. bölüm (Indexing) sunusunun ilk 11 slaytını kullandı (ekrandan, 00:10:00; 02:05:00). Bu konuların daha ayrıntılı hali (dosya erişim yapıları, SQL'in arka planda nasıl çalıştığı) veritabanı sistem gerçekleme dersinde işleniyor; bu derste amaç terminolojiye bir giriş yapmaktır.

## 1. Fiziksel Tasarıma Giriş ve İndeks Fikri

Bir tabloda binlerce, milyonlarca kayıt olabilir; bir tablo megabaytlardan gigabaytlara kadar büyüyebilir. Bu kadar veride aranan kaydı makul sürede bulmak için verinin belli bir yapıda, belli bir düzende saklanması gerekir. Tablo çok büyükse daha küçük dosyalara bölünebilir. Bu da bir fiziksel tasarım yaklaşımıdır. Bölme satır esaslı olabilir (örneğin tablo beş parçaya, her parçada bir grup satır olacak şekilde ayrılır) ya da sütun esaslı olabilir (örneğin 20 sütunlu bir tablonun 5 sütunu ayrı bir tabloya yazılır).

İlişkisel modeldeki tablolar arka planda elbette dosyalarda saklanır. Ama bu dosyalar kullanıcının açıp doğrudan okuyabileceği metin dosyaları değildir. Veritabanı sisteminin kendi denetimindeki, daha iyi optimize edilmiş ikili (binary) dosyalardır. Belli bir yapıda saklanmalarının en önemli nedeni erişimin hızlı olmasıdır. Bu hızlı erişimin arkasındaki yapı indekstir.

### 1.1 Kitap indeksi benzetmesi

Hoca indeksi bir kitabın indeksine benzetti. Büyük bir kitapta bir kelime ya da konu aranırken kitabın sonundaki indekse bakılır. Bu indeks kitaba göre çok küçüktür (5-10 sayfa) ve sıralıdır (A ile başlayan kelimeler, sonra B ile başlayanlar...). Sıralı olduğu için aranan kelimeyi orada bulmak kolaydır. Kelimenin yanında sayfa numarası yazar; bu sayede kitabın başından itibaren sayfa sayfa aramak yerine doğrudan o sayfaya gidilir.

Veritabanında da durum aynıdır. Tablo kitaptır. Tabloya ait indeks tabloya göre çok küçüktür ve sıralıdır. Bir arama yapılırken aranan değer, o nitelik üzerindeki indeks yapısında aranır. Bulunan değerin yanında kaydın adres bilgisi vardır ve bu adresle tablodaki kayda doğrudan erişilir. Hoca, indeks denince akla hızlı erişimin gelmesi gerektiğini ve bu haftaki ile gelecek haftaki konuların nihai hedefinin bu olduğunu söyledi.

## 2. Dosyalar, Kayıtlar ve Disk Sayfası

Veritabanı bir dosyalar topluluğu olarak saklanır. Her dosya bir kayıt dizisidir, her kayıt da bir alan (nitelik) dizisidir (ekrandan, 00:10:00). Bir dosyadaki kayıtlar sabit uzunluklu ya da değişken uzunluklu olabilir. Kayıtta varchar gibi değişken uzunluklu bir nitelik varsa kayıt değişken uzunluklu olur. Bir dosyada farklı tablolara ait kayıtlar da bulunabilir; örneğin iki tablo üzerinde çok sık join yapılıyorsa, sistem hızlandırmak için bu kayıtları aynı dosyaya alabilir.

Slayttaki ilk yaklaşım en basit durumdur: kayıt boyu sabittir, her dosyada tek türde kayıt vardır ve farklı tablolar için farklı dosyalar kullanılır. Böylece bir dosyadaki bütün kayıtlar aynı şemaya sahiptir. Hoca, gerçeklemesi kolay olduğu için içinde değişken nitelik olsa bile sabit uzunluklu gerçeklemenin yaygın olduğunu, değişken uzunluklu gerçeklemenin dezavantajları düşünülünce bunun büyük bir kayıp olmayacağını belirtti.

### 2.1 Disk sayfası

Kitabın 12. bölümü diski anlatır ama bu derse dahil edilmedi. Yine de bilinmesi gereken temel nokta şudur: veri diskten **disk sayfası** birimiyle çekilir. İstenen veri parçası ne kadar küçük olursa olsun diskten gelen parça, disk ile ana bellek arasındaki aktarım biriminin büyüklüğündedir. Örneğin 100 baytlık bir veri istendiğinde sistem bunu 4 KB'lık bir sayfa içinde gönderir; Linux ve Windows'da disk sayfası tipik olarak 4 KB'dir. Veritabanı sistemlerinde ise varsayılan sayfa boyutu çoğunlukla 8 KB'dir; hoca PostgreSQL ve MS SQL'de, belki Oracle'da da varsayılanın 8 KB olduğunu söyledi.

Örneğin 100 numaralı öğrencinin adı isteniyor olsun. İstenen yalnızca birkaç baytlık bir addır, ama bu baytları diskten tek başına okumak hiçbir zaman mümkün değildir; o kaydın bulunduğu 8 KB'lık sayfanın tamamı gelir.

Aynı içerik bulunduğu yere göre farklı adlar alır: diskte **disk block**, ana bellekte **page**, tampon havuzunda **buffer** ya da **frame**. İçerik değişmez, adı bulunduğu yere göre değişir.

### 2.2 Kayıt boyu ve sayfa

Slayttaki son varsayım, kayıtların bir disk bloğundan küçük olduğudur (ekrandan, 00:10:00). Birkaç varchar(30) ve birkaç integer içeren 8-10 nitelikli bir tablonun kaydı tipik olarak 100-200 bayttır. 8 KB'lık bir sayfaya böyle kayıtlardan onlarca sığar.

> **Ders sonrası not:** Hoca hesabı yaparken "sekiz yüz byte içerisine kırk tane" dedi; kastedilen 8 KB (8192 bayt) olmalıdır. 200 baytlık kayıtla $\lfloor 8192/200 \rfloor = 40$, 100 baytlık kayıtla $\lfloor 8192/100 \rfloor = 81$ kayıt sığar.

Çok büyük nesneler (binary large object, character large object, BLOB/CLOB, büyük metinler) sayfayı aşabileceği için ayrı organizasyonlar gerektirir. Derste önce en basit durum ele alındı.

## 3. Sabit Uzunluklu Kayıtlar

### 3.1 Kayda erişim

Slayttaki örnek dosya instructor tablosunun 12 kaydıdır (ekrandan, 00:25:00):

| Kayıt | ID | name | dept_name | salary |
|---|---|---|---|---|
| record 0 | 10101 | Srinivasan | Comp. Sci. | 65000 |
| record 1 | 12121 | Wu | Finance | 90000 |
| record 2 | 15151 | Mozart | Music | 40000 |
| record 3 | 22222 | Einstein | Physics | 95000 |
| record 4 | 32343 | El Said | History | 60000 |
| record 5 | 33456 | Gold | Physics | 87000 |
| record 6 | 45565 | Katz | Comp. Sci. | 75000 |
| record 7 | 58583 | Califieri | History | 62000 |
| record 8 | 76543 | Singh | Finance | 80000 |
| record 9 | 76766 | Crick | Biology | 72000 |
| record 10 | 83821 | Brandt | Comp. Sci. | 92000 |
| record 11 | 98345 | Kim | Elec. Eng. | 80000 |

Basit yaklaşımda i. kayıt $n \cdot (i-1)$ baytından başlar; $n$ her kaydın boyudur. Kayda erişim basittir ama kayıtlar blok sınırını aşabilir. Bir değişiklik olarak kayıtların blok sınırını aşmasına izin verilmeyebilir (ekrandan, 00:25:00).

Hoca bunu temsili bir örnekle şematize etti: bir disk sayfasına 3 kayıt sığıyorsa bu 12 kayıt 4 disk sayfasına yerleşir. Kayıt boyunu da nitelik boyutlarından hesapladı ve 28 bayt buldu. <!-- BELİRSİZ: Hocanın 28 bayta hangi nitelik boyutlarıyla ulaştığı altyazıda net değil. -->

> **Ders sonrası not:** Hoca 5. kayda "28×5" ofsetiyle erişileceğini söyledi. Kayıtlar slayttaki gibi 0'dan numaralanırsa record 5 gerçekten $28 \cdot 5 = 140$. bayttan başlar. Slayttaki $n \cdot (i-1)$ formülü kayıtları 1'den numaralar; bu numaralamayla 5. kayıt $28 \cdot (5-1) = 112$. bayttan başlar.

Bu adres isteği nereden gelir? Son kullanıcı bir SQL sorgusu yazar; sistem, istenen kaydın adresini elde eder. Hoca örnek olarak 33456 numaralı kişinin bölümünü bulmayı gösterdi (tablonun instructor tablosu olduğunu da belirtti). Arka planda "kapalı kutu" olan indeks, "aradığın kayıt bu dosyada, ikinci blokta, şu ofsette" der. Sistem o disk sayfasına erişir, ofsete gider ve bölüm bilgisini okur. İndeksin bu adresi nasıl bulduğu sonraki konularda doldurulacak.

### 3.2 Page spanning

Bir disk sayfasına tam sayıda kayıt sığmayabilir. O zaman ya kalan baytlar boş bırakılır ya da bir sonraki kaydın bir kısmı oraya yazılır. İkinci yola **page spanning** denir; iki sayfa birbirine zincirlenir ve yer kaybı olmaz.

Hoca gerçekçi olmayan küçük değerlerle bir örnek verdi:

- Verilen: sayfa 300 bayt, her kayıt 80 bayt.
- Spanning yoksa: bir sayfaya 3 kayıt sığar, $3 \cdot 80 = 240$ bayt dolar, $300 - 240 = 60$ bayt boş kalır. Sonraki 3 kayıt diğer sayfaya yazılır ve her sayfada 60 bayt boş kalır.
- Spanning varsa: dördüncü kaydın 60 baytı ilk sayfaya, kalan $80 - 60 = 20$ baytı sonraki sayfaya yazılır. Sayfalar tam dolar ama bir kayıt artık iki sayfaya dağılmış olur.

Kayıt disk bloğundan büyükse page spanning zaten kaçınılmazdır.

### 3.3 Güncelleme, ekleme ve silme

Sabit uzunluklu dosyada güncelleme sorun çıkarmaz; örneğin bölüm alanı char(10) ise bir hocanın bölümü değiştiğinde değer aynı yere yazılır. Asıl soru, ekleme ve silmelerde kayıtların nereye yazılacağı ve silmeden sonra dosyanın ne olacağıdır. Bunun için sezgisel (intuitive), karmaşık algoritma gerektirmeyen stratejiler vardır. Slayttaki silme seçenekleri (ekrandan, 00:35:00):

- $i+1, \dots, n$ kayıtlarını $i, \dots, n-1$ konumlarına kaydırmak (shift): hiç boşluk kalmaz ama bütün kayıtlar yer değiştirir.
- Son kaydı ($n$) boşalan $i$ konumuna taşımak: kaydırmak yerine yalnız boşluk doldurulur ve dosya fiziksel olarak da yekpare kalır. Örnekte record 3 silinince yerine record 11 gelir.
- Kayıtları taşımamak, bütün boş kayıtları bir **free list** ile bağlamak.

Üçüncü yolda dosyanın başında bir **header** (başlık) bölgesi vardır. Başlıkta dosyanın adı, kaç kayıt içerdiği, sona ekleme yapılıyorsa son ekleme noktasının ofseti gibi bilgilerle birlikte boş alan listesinin başlangıcı da tutulur. Hoca bu tür başlıkların sistem dosyalarında tipik olduğunu söyledi. Slayttaki örnekte record 1, 4 ve 6 silinmiştir: başlık record 1'e, record 1 record 4'e, record 4 de record 6'ya işaret eder (ekrandan, 00:35:00).

Bu yaklaşımda yeni kayıt dosyanın sonuna eklenmez, ilk boş yere yazılır. Sabit uzunluklu olduğu için kayıt bu boşluğa mutlaka sığar ve dosya sırasız olduğu için herhangi bir arama yapmaya gerek yoktur. Sabit uzunluklu gerçeklemenin önemli bir avantajı burada görünür.

**Soru:** Son anlatılan yer (free list stratejisi) tekrar anlatılabilir mi?
**Cevap:** Hoca, sabit uzunluklu ve sırasız bir dosyada ekleme ve silmelerin farklı stratejilerle yapılabileceğini tekrarladı. Üçüncü stratejide boşluklar yerinde kalır ama izlenir: başlıktaki işaretçi ilk boş kayda, o kayıt bir sonraki boş kayda işaret eder. Bunun amacı yeni gelen kaydı dosyanın sonuna eklemek yerine boşluklara yazarak dosyayı kompakt tutmaktır. Boşluklar çoğaldıkça kayıtlar diskte farklı sayfalara, silindir ve izlere (track) dağılır; yeni kayıtlar komşu yerlere yazılırsa arama daha hızlı olur.

### 3.4 Disk sayfası boyutunda bölme sorusu

**Soru:** Kayıtlar bellekten 8 KB'lık disk sayfaları olarak çekiliyorsa, bir tabloyu 8 KB'lık parçalara bölmek daha verimli bir veritabanı sağlar mı? Bunu kullanıcı mı yapmalı, sistem kendisi mi yapar?
**Cevap:** Böyle bölmek mantıklı değildir. 100 sayfalık bir tablo 100 ayrı dosya olurdu; her dosyanın takibi, güvenlik ayarları ve erişimle ilgili ek bilgileri vardır. Bu karar veritabanı sistemine bırakılır. Ama büyük dosyaların bölünmesi (partitioning) fikri doğrudur. Örneğin en çok erişilen sütunlar ayrı bir tabloya alınabilir; bu daha küçük bir dosya demektir ve yoğun iş yükünde akıllıca olur. Ya da hava raporlarını tutan bir tabloda en çok son günlerin raporları sorgulanır; tablo 3 günlük parçalara bölünürse arama tüm tablo yerine son 3 günü içeren küçük dosyada yapılır. Bu satır esaslı bir bölmedir. Ancak tek sayfalık dosyalar olmaz; o zaman milyonlarca dosya oluşur. 8 KB'lık bir veri zaten ana bellekte işlenir. Hoca soruyu düşünerek sorulduğu için övdü.

## 4. Değişken Uzunluklu Kayıtlar

### 4.1 Nereden çıkar?

Slayta göre değişken uzunluklu kayıtlar şu durumlarda ortaya çıkar (ekrandan, 00:45:00):

- Bir dosyada birden fazla kayıt türünün saklanması.
- Bir ya da daha fazla alanın değişken uzunlukta olmasına izin veren kayıt türleri (örneğin varchar).
- Tekrar eden alanlara izin veren kayıt türleri (bazı eski veri modellerinde).

varchar(100) bir nitelik için kullanıcı 1 bayt da 100 bayt da girebilir. Daha uzun bir değer girilirse sistem ya hata verir ya da yalnız ilk 100 baytı yazar; hoca hangi sistemin nasıl davrandığını denemeyi önerdi ve PostgreSQL ile MS SQL'in farklı davranabileceğini söyledi. 100 bayttan kısa bir değer girildiğinde ise fiziksel olarak 100 bayt değil, girilen kadar yazılabilir.

En kolay yol varchar'ı da sabit uzunluklu gerçeklemektir; ama o zaman yer kaybedilir. Örneğin varchar(100) adres alanına bazı adresler 20, bazıları 80 bayt gelir, ama her biri için 100 bayt ayrılmış olur. Buna karşılık dosya yönetimi (güncelleme, silme, adres hesabı, boş alan takibi) çok kolay kalır. Değişken uzunluklu gerçeklemede ise organizasyon gerekir; bu da arkada kod, artan karmaşıklık ve düşünülmesi gereken ince noktalar demektir. Hoca, varchar çok büyük değilse (örneğin 500 bayt düzeyinde değilse) sistemlerin içeride onu sabit uzunluklu gerçekleyebileceğini tahmin ettiğini söyledi. Bu son kullanıcıyı etkilemez ama çok kayıt ya da çok erişim varsa performansı etkileyebilir.

### 4.2 (offset, uzunluk) gösterimi

Slayttaki kurallar (ekrandan, 00:45:00): nitelikler sırayla saklanır; değişken uzunluklu nitelikler sabit boyutlu (offset, length) çiftleriyle temsil edilir ve asıl veri bütün sabit uzunluklu niteliklerden sonra saklanır; null değerler bir null-value bitmap ile gösterilir. Slayttaki kayıt:

| Bayt | 0 | 4 | 8 | 12 | 20 | 21 | 26 | 36 |
|---|---|---|---|---|---|---|---|---|
| İçerik | (21, 5) | (26, 10) | (36, 10) | 65000 | 0000 | 10101 | Srinivasan | Comp. Sci. |

Okuma şöyledir: ilk çift "21. baytta 5 baytlık bir değer var" der; bu 10101'dir. İkinci çift "26. baytta 10 baytlık değer var" der; bu Srinivasan'dır. Üçüncü çift 36. baytta 10 baytlık Comp. Sci. değerini gösterir. 12-20 arası sabit uzunluklu salary (65000), 20. bayt 1 baytlık null bitmap'tir. Hoca her çiftin iki short integer (2'şer bayt) olduğunu, ilkinin ofseti, ikincisinin uzunluğu tuttuğunu açıkladı ve buradan ID'nin bu kayıtta 5 karakterlik değişken bir alan olduğunun anlaşıldığını belirtti. Başka bir kayıtta karakter sayıları farklı olacağı için bu sayılar da farklı olur.

### 4.3 Ayırıcı karakter

Performansı pek değiştirmeyen başka bir strateji ayırıcı (delimiter) kullanmaktır: nitelik değerlerinde geçmesine izin verilmeyen özel bir karakter, örneğin # ya da *. Kayıt bayt bayt okunurken ayırıcı gelince bir niteliğin bittiği, sonrakinin başladığı anlaşılır. Böylece aynı kayıttaki nitelikler birbirinden ayrılır.

### 4.4 Slotted page yapısı

Değişken uzunluklu kayıtlar sayfa düzeyinde **slotted page** ile düzenlenir (ekrandan, 00:50:00). Blok başlığı (block header) şunları içerir:

- kayıt girişlerinin sayısı (# Entries),
- bloktaki boş alanın sonu (End of Free Space),
- her kaydın konumu ve boyu (location, size).

Başlık blok başında, kayıtlar blok sonundadır; arada boş alan (free space) vardır. Kayıtlar aralarında boşluk kalmayacak şekilde sayfa içinde kaydırılabilir; bu durumda başlıktaki giriş güncellenmelidir. Bu yüzden işaretçiler kayda doğrudan değil, başlıktaki kayıt girişine işaret etmelidir.

Hoca bunu erişim akışıyla bağladı: indeks, "aradığın kayıt şu blokta ve şu numaralı kayıt" der. Sayfa boyu sabit olduğu için bloğa gitmek kolaydır (örneğin 10. blok için $10 \times 8$ KB). Ama blok içindeki kayıtlar artık sabit uzunluklu olmadığı için blok başlığındaki küçük bir "indeks" kullanılır; o giriş kaydın ofsetini verir. Kaydın içindeki niteliklere de (offset, uzunluk) çiftleriyle ulaşılır. Yani organizasyon içinde organizasyon vardır.

### 4.5 Büyük nesneler ve TOAST

Binary ve character large object'ler bu düzene sığmaz, farklı bir organizasyon gerekir. Hoca derste kullanılan PostgreSQL'in **TOAST** adlı düzenini örnek verdi: büyük bir metin ya da görüntü gibi bir değer varsa ayrı bir alanda tutulur, kayıtta ona bir işaretçi kalır. Böylece dosya sabit uzunluklu kayıtlarla gerçeklenebilir; sorguda istendiğinde değer o alandan getirilir.

## 5. Dosya Organizasyonları

Özetle: tablo bir dosyadır, dosyada disk sayfaları vardır, sayfalarda kayıtlar vardır, kayıtlar da sabit ya da değişken uzunluklu niteliklerden oluşur. Kayıtların dosya içinde nasıl düzenlendiğine göre dosya türleri şunlardır (ekrandan, 00:55:00):

- **Heap:** kayıt dosyada boş yer olan her yere konabilir.
- **Sequential:** kayıtlar her kaydın arama anahtarı (search key) değerine göre sıralı saklanır.
- **Multitable clustering:** birden fazla tablonun kayıtları aynı dosyada saklanabilir. Amaç, ilişkili kayıtları aynı blokta tutarak G/Ç'yi (I/O) azaltmaktır.
- **B+ ağacı dosya organizasyonu:** ekleme ve silmelerde bile sıralı saklama.
- **Hashing:** arama anahtarı üzerinde bir hash fonksiyonu hesaplanır; sonuç, kaydın dosyanın hangi bloğuna konacağını belirtir.

Hoca, SQL ya da NoSQL, PostgreSQL, MongoDB ya da Oracle, hangi sistem olursa olsun arka planda bu dosya türlerinin kullanıldığını söyledi. Her birinin avantajları ve dezavantajları vardır; erişim tarzına göre bazen B+ ağacı, bazen hashing avantajlıdır. Bunları bilmek özellikle veritabanı yöneticisi (admin) için önemlidir.

"Sequential" kelimesi kaynaktan kaynağa değişir; "sorted" ya da "ordered file" da denir. Bu derste sequential dosya, bir niteliğe göre sıralı dosya olarak tanımlandı.

### 5.1 B+ ağacı ve hashing: ilk akla gelmesi gerekenler

B+ ağacı duyulunca ilk akla gelmesi gereken kilit fikir sıralamadır: kayıtlar küçükten büyüğe (ya da tersi) sıralanır. Hashing ise sıralama esaslı değildir; kayıtlar bir niteliğe göre kovalara (bucket) dağıtılır (hash edilir).

Bir dosyada ekleme ve silmelerle birlikte sıralılığı korumak kolay değildir. Doğrudan yol kaydırmaktır (shift), ama milyonlarca kayıt varken araya gelen her kayıt için bütün kayıtları kaydırmak sistemi çok hantallaştırır. B+ ağacı, sıralılığı ekleme, silme ve güncellemelerde de koruyan akıllıca bir ağaç organizasyonudur; ayrıntısı sonraki derse bırakıldı.

> **Hocanın vurgusu:** B+ ağacı sıralama esaslı olduğu için aralık sorgularında çok başarılıdır; hashing aralık sorgularında kullanılması mümkün olmayacak kadar verimsizdir.

Bu iki yapı çok ileri (advanced) organizasyonlardır ve her yerde bulunurlar (ubiquitous): yalnız veritabanlarına özgü değildir; cep telefonundan işletim sistemine kadar, arama gerektiren her bilgi işleme ortamında, diskteki veriye en son erişim noktasında bu yapılar vardır.

Avantajları arama türüne göre ortaya çıkar. Örneğin "ortalaması 2 ile 2.3 arasında olan öğrenciler" bir aralık sorgusudur; arama anahtarı GPA'dır. GPA üzerinde bir B+ ağacı indeksi varsa sistem onu kullanır. Kullanıcı bunu SQL'de yazmaz, tamamen sistemin arka planında olur. "ID'si 100 olan öğrencinin adı" gibi bir eşitlik sorgusunda ise hash esaslı erişim daha avantajlıdır ya da kullanılma olasılığı daha yüksektir.

### 5.2 Heap dosyası

Slayta göre (ekrandan, 01:05:00): kayıtlar dosyada boş yer olan her yere konabilir; yerleştikten sonra genelde yer değiştirmez; dosyada boş yeri verimli bulabilmek önemlidir. Ekleme ve silme hızlıdır: kayıt sona eklenir, dosya ara sıra sıkıştırılır (compaction).

Boş yer bir **free-space map** ile izlenebilir: blok başına bir giriş tutan bir dizi. Her giriş birkaç bitten bir bayta kadardır ve bloğun ne kadarının boş olduğunu kaydeder. Slayttaki örnekte giriş başına 3 bit vardır ve değerin 8'e bölümü bloğun boş kısmını gösterir:

```text
Birinci düzey: 4 2 1 4 | 7 3 6 5 | 1 2 0 1 | 1 0 5 6
İkinci düzey:     4    |    7    |    2    |    6
```

İkinci düzey haritanın her girişi birinci düzeyin dört girişinin en büyüğünü tutar: $\max(4,2,1,4)=4$, $\max(7,3,6,5)=7$, $\max(1,2,0,1)=2$, $\max(1,0,5,6)=6$ (ekrandan, 01:05:00). Yeni kayıt geldiğinde hangi bloğa konacağına bu dizine bakılarak karar verilir. Harita diske belli aralıklarla yazılır; bazı girişlerin eski (yanlış) değerde olması kabul edilir, bunlar sonradan fark edilip düzeltilir. Boş alanlar bağlı listelerle de izlenebilir.

PostgreSQL'de boş alanları toplayan **VACUUM** operatörü vardır. Sistem bunu belli aralıklarla kendisi yapar; yoğun bir işlemden sonra kullanıcı da çalıştırabilir. Hoca adı elektrikli süpürgeye benzetti: süpürge tozu nasıl çekiyorsa VACUUM da tablodaki boş alanları çeker, heap dosyaları sıkışık ve tek parça kalır, sistem daha yüksek performansla çalışır.

### 5.3 Sequential dosya

Sununun başındaki örnekler heap dosyasıydı. Sequential dosya, bütün dosyanın sırayla işlenmesini gerektiren uygulamalar için uygundur; dosyadaki kayıtlar bir arama anahtarına göre sıralıdır. Örnekte kayıtlar ID'ye göre sıralıdır. Sequential dosyada kayıtlar fiziksel olarak da bitişiktir (contiguous). Bu ayrı bir konudur: bir dosya mantıksal olarak sıralı görünse de kayıtları diskte farklı sayfalara dağılmış olabilir.

Organizasyon ne kadar kısıtlanırsa işlemler o kadar karmaşıklaşır:

- Silme: işaretçi zincirleri kullanılır; boşalan yer zincirle izlenir.
- Ekleme: kaydın girmesi gereken konum bulunur. Orada boş yer varsa kayıt oraya yazılır. Boş yer yoksa kayıt bir **taşma (overflow) bloğuna** yazılır; kaydırma yapılmaz. Her iki durumda da işaretçi zinciri güncellenir.

Hoca örnek verdi: iki kayıt arasına 32222 gibi bir değer gelirse onu araya koymak sonraki bütün kayıtları kaydırmak demektir. Bunun yerine bir taşma alanı açılır ve kayda işaretçi zinciriyle ulaşılır. Böylece dosya mantıksal olarak sıralı kalır ama fiziksel sıralılık bozulur. Bu yüzden dosyanın zaman zaman yeniden düzenlenip fiziksel sıranın geri getirilmesi gerekir; PostgreSQL'de bu da VACUUM ile yapılabilir.

> **Ders sonrası not:** Hoca fiziksel sıranın PostgreSQL'de VACUUM ile geri getirilebileceğini söyledi. VACUUM boş alanları geri kazanır ama kayıtları sıralamaz; tabloyu bir indekse göre fiziksel olarak yeniden sıralayan komut büyük olasılıkla CLUSTER'dır.

### 5.4 Multitable clustering dosya organizasyonu

Şimdiye kadarki en düz tasarımda ilişkisel modeldeki her tablo (öğrenci, bölüm, proje...) için arkada bir dosya vardır ve çoğu zaman da böyledir. Ama sistemin iş yükünde (workload) örneğin öğrenci ve bölüm tabloları çok sık birleştiriliyorsa durum değişir. Join pahalı bir işlemdir; özünde kartezyen çarpım, yani bütün kayıtların eşleştirilmesi vardır. O zaman bu kayıtlar farklı dosyalar yerine aynı dosyaya yazılabilir: her bölümün kaydından hemen sonra o bölümün öğrencileri, ardından diğer bölüm ve öğrencileri. Şeması farklı kayıtlar içeren bu heterojen dosyalara multitable clustering dosya organizasyonu denir.

Slayttaki örnek (ekrandan, 01:10:00):

department:

| dept_name | building | budget |
|---|---|---|
| Comp. Sci. | Taylor | 100000 |
| Physics | Watson | 70000 |

instructor:

| ID | name | dept_name | salary |
|---|---|---|---|
| 10101 | Srinivasan | Comp. Sci. | 65000 |
| 33456 | Gold | Physics | 87000 |
| 45565 | Katz | Comp. Sci. | 75000 |
| 83821 | Brandt | Comp. Sci. | 92000 |

department ve instructor'ın ortak dosyası:

```text
Comp. Sci. | Taylor     | 100000
10101      | Srinivasan | Comp. Sci. | 65000
45565      | Katz       | Comp. Sci. | 75000
83821      | Brandt     | Comp. Sci. | 92000
Physics    | Watson     | 70000
33456      | Gold       | Physics    | 87000
```

"Computer Science bölümünde kaç hoca var?" ya da "Computer Science bölümünde maaşı 7000'den büyük olanlar" gibi sorgular bu düzenden yararlanır. Hoca, bu örnekte bölüm adı instructor tablosunda da geçtiği için join gerekmediğini, ama bölüm bir ID ile bağlansaydı join gerekeceğini belirtti; bu durumda kayıtların aynı yerde olması performansı önemli ölçüde artırır.

Slayta göre bu organizasyon department ile instructor'ı birlikte isteyen sorgular ve tek bir bölümle o bölümün hocalarını isteyen sorgular için iyidir; yalnız department'ı isteyen sorgular için kötüdür. Tek department tablosunda yapılacak taramada bütün bölüm kayıtları yan yana olsaydı daha avantajlı olurdu; burada o avantaj kaybedilir. instructor için de benzer bir kayıp vardır. Bu düzen değişken uzunluklu kayıtlara da yol açar.

## 6. Partitioning

Aradan sonra kalan iki organizasyonun (B+ ağacı ve hashing) 14. bölümde olduğu hatırlatıldı ve partitioning kavramına geçildi. Slayta göre (ekrandan, 01:40:00):

- **Table partitioning:** bir tablonun kayıtları ayrı saklanan daha küçük tablolara bölünebilir.
- Örneğin transaction tablosu transaction_2018, transaction_2019 vb. olarak bölünebilir.
- transaction üzerinde yazılan sorgular bütün bölümlere erişmek zorundadır; ancak sorguda year = 2019 gibi bir seçim varsa yalnız bir bölüm gerekir.
- Partitioning boş alan yönetimi gibi bazı işlemlerin maliyetini azaltır ve farklı bölümlerin farklı depolama aygıtlarında saklanmasına izin verir; örneğin güncel yılın bölümü SSD'de, eski yıllarınki manyetik diskte.

Hoca ana fikri şöyle açıkladı: sorgular sene bazlı geliyorsa tablo fiziksel olarak sene niteliğine göre parçalanır; bütün karışık veriyi aramak yerine yalnız ilgili senenin tablosunda arama yapılır. Bölümleme sıralamadan farklı bir kavramdır; her bölüm kendi içinde sıralı olabilir ya da heap olarak kalabilir. Ekleme ve silmeler çoğunlukla son senenin tablosunda olacağı için boş alan takibi de yalnız bu küçük dosyada yapılır. En sık sorgulanan yakın geçmiş daha hızlı bir aygıtta (SSD) tutulursa sorgu performansı önemli oranda artar. Partitioning'in en önemli amacı sorguları hızlandırmaktır.

## 7. Veri Sözlüğü (Katalog)

Sistemde veri dosyalarının yanında katalog dosyaları da önemli bir yer tutar. İlişkisel modelde **data dictionary** (katalog) veri hakkında veridir (metadata): tablo adları, tablolardaki niteliklerin adları ve türleri, görünümlerin (view) adları ve tanımları, birincil ve yabancı anahtar gibi bütünlük kısıtları. Fiziksel organizasyon için en önemli bilgiler de buradadır: istatistikler ve her tablonun hangi dosyada, hangi organizasyonla saklandığı (heap mi, sequential mı, B+ ağacı mı, hash mi).

Bu kararlar performansı çok etkiler, ama hiçbir yapı her zaman en iyisi değildir. Örneğin WHERE ile hiçbir koşul konmamış bir SELECT ... FROM sorgusunda bütün kayıtlara erişilir (table scan); indeks ya da hash yapısı üzerinden erişmek mantıklı olmaz. ORDER BY varsa sequential dosya, yoksa heap dosya daha iyi olur. Yani bu organizasyonların hiçbiri gereksiz değildir; sorgulama ve erişim tarzına göre avantajlı olurlar. Hangi dosya türünün ve hangi erişim yolunun kullanılacağına sistemin ana modüllerinden olan sorgu işleyici, sorgu optimizer'ı ve planlayıcı (planner) karar verir; indeksleri kullanıp kullanmamaya da bunlar karar verir. Bu konular kitabın 15. ve 16. bölümlerindedir.

Katalog da ilişkisel tablolarla temsil edilir (ekrandan, 01:45:00). Slaytta diskte ilişkisel gösterim ve bellekte verimli erişim için özel veri yapıları kullanıldığı yazar. Slayttaki katalog tabloları:

- Relation_metadata(relation_name, number_of_attributes, storage_organization, location)
- Attribute_metadata(relation_name, attribute_name, domain_type, position, length)
- Index_metadata(index_name, relation_name, index_type, index_attributes)
- View_metadata(view_name, definition)
- User_metadata(user_name, encrypted_password, group)

Attribute_metadata ve Index_metadata, relation_name üzerinden Relation_metadata'ya bağlıdır. Hoca, şimdiye kadar tasarlanan küçük dünyalarda (şirket ve üniversite veritabanları) tablolar nasıl birbirine bağlıysa katalog tablolarının da kendi içinde ilişkisel bir model oluşturduğunu söyledi. Relation_metadata'da sistemdeki (PostgreSQL diliyle o cluster'daki) bütün veritabanlarının bütün tabloları, Attribute_metadata'da bütün nitelikler vardır; kullanıcılar ve erişim bilgileri de katalogdadır.

Katalog sistemin en sık erişilen "sıcak noktası"dır: her sorguda önce kataloğa bakılır. Örneğin student tablo adı bir harfi eksik yazılırsa sorgu, optimizer devreye girmeden katalogda böyle bir tablo bulunamadığı için hemen hata döner. Slaytta görünmese de katalogda istatistiksel bilgiler de vardır: bir niteliğin değer dağılımı, hangi değer aralığında kaç kayıt olduğunu gösteren histogramlar. Bunlar sorgu planlayıcısının kullandığı kritik bilgilerdir.

## 8. Depolama Erişimi ve Tampon

Buffer yönetimindeki kurban seçim algoritmaları sistemin merkezinde ve çok önemlidir, ama derste yalnız tamponun anlamı tanımlandı. Slayta göre (ekrandan, 01:50:00):

- Bloklar hem depolama ayırma hem de veri aktarım birimidir.
- Veritabanı sistemi disk ile bellek arasındaki blok aktarımı sayısını en aza indirmeye çalışır. Mümkün olduğunca çok bloğu ana bellekte tutarak disk erişimi azaltılabilir.
- **Buffer:** ana belleğin, disk bloklarının kopyalarını saklamaya ayrılmış kısmı.
- **Buffer manager:** ana bellekte tampon alanı ayırmaktan sorumlu alt sistem.

Slayttaki şemada bellekteki tampon diske bağlıdır; yanında "Buffer Manager - Hash Table" kutusu vardır (ekrandan, 01:50:00).

Blok aktarım biriminin yanında yer ayırma birimi de olduğu, dosya boyutlarında görülür: bir tabloya tek kayıt yazılsa da tablonun boyu 8 KB görünür. 8193 baytlık veri yazılırsa, yani 8 KB'ı bir bayt aşınca, ikinci sayfa açılır ve tablo iki sayfalık olur.

Günümüzde sunucularda ana bellek gigabaytlardan terabaytlara çıktı. Diskten gelen verinin en sık kullanılacak olanlarını ana bellekte tutmak performans için çok önemli bir ölçüttür. Örneğin katalog dosyaları her sorguda uğranan dosyalar olduğu için tamponda tutulmalı, öncelikleri daha yüksek olmalıdır. Hoca, gerçekte tampon havuzunun bölündüğünü, bir bölümün katalog dosyalarına ayrıldığını ve bu bölümün kendi kurban seçim algoritması olduğunu ekledi.

Disk erişimi ana bellek erişiminden yaklaşık 100.000 kat yavaştır; hoca bunu birkaç saniyede yapılacak bir işi bir günde yapmaya benzetti. Tampon bu uçurumu kapatır. Ama aynı veri hem diskte hem bellekte bulunduğu için tutarlılık sorunu doğar. Bir güncelleme önce bellekte yapılır; o anda diskteki veri farklıdır. Tam o anda elektrik kesilirse veri bütünlüğü bozulur. Sistem yeniden ayağa kalktığında kurtarma (recovery) modülünün bunu düzeltmesi, gerekirse geri sarması gerekir. Tampon hem olmazsa olmazdır hem de sistemin karmaşıklığını artırır.

Tampon havuzu dolunca yeni gelen sayfaya yer açmak için bazı sayfaların kurban edilmesi gerekir. Çok yaygın kullanılan algoritma **LRU**'dur (least recently used, en uzun süredir kullanılmayan). Veritabanı sistemlerinde LRU, LRU-K, CLOCK ya da veritabanına özgü daha iyi algoritmalar kullanılır. Ayrıntılar sistem gerçekleme dersine bırakıldı.

Hoca bu konuların çok kapsamlı olduğunu, derste kavram düzeyinde kalınacağını söyledi: dersin ana içeriği ilişkisel model ve SQL'dir, ama indeksin ne olduğu ve amacı da bilinmelidir.

Hoca ayrıca indeks konusunu pekiştirmek için PostgreSQL (pgAdmin) üzerinde bir tablo oluşturup indeks oluşturmayı ve etkisini gösteren internet örneklerini denemeyi önerdi.

## 9. İndekslemeye Giriş: Temel Kavramlar

14. bölümde temel kavramlar, sıralı indeksler ve B+ ağacı indeksleri işlenecek. B+ ağacında nereye bakılırsa bakılsın sıralama görülür; bu yüzden aralık sorgularında (örneğin ortalaması 2 ile 2.3 arasındaki öğrenciler) daha elverişlidir. Eşitlik sorgularında ise hash daha elverişlidir. Boyut açısından hashing daha kompakttır, B+ ağacı yer verimliliğinde biraz daha zayıftır. Yaygınlık açısından B+ ağacı hashing'den çok daha yaygındır.

Hoca PostgreSQL'de hashing'in 10. sürümden sonra teşvik edildiğini, yapılan iyileştirmelerle optimizer'ın hash içeren daha iyi planlar bulabildiğini, öncesinde hashing'in daha çok teorik kaldığını söyledi. Bu yapılar 80'ler ve 90'lardan beri tanımlı olsa da hashing ancak birkaç yıl önce aktif olarak kullanılmaya başlandı. B+ ağacı ise sistemin merkezinde olan bir veri yapısıdır; o olmadan veritabanı kullanılamaz.

> **Ders sonrası not:** Hoca PostgreSQL 10'un "2-3 sene önce" çıktığını, tam hatırlamadığını belirterek söyledi. PostgreSQL 10 büyük olasılıkla Ekim 2017'de yayımlandı; hash indekslerin WAL ile kayıt altına alınması da büyük olasılıkla bu sürümle geldi. Ders tarihinde güncel sürüm 14'tü.

İndeksleme veriye erişimi hızlandırmak için kullanılan en önemli mekanizmadır (partitioning de bir hızlandırma yoludur). Slayttaki temel kavramlar (ekrandan, 02:05:00):

- İndeksleme mekanizmaları istenen veriye erişimi hızlandırmak için kullanılır; örneğin kütüphanedeki yazar kataloğu.
- **Search key (arama anahtarı):** bir dosyada kayıt aramak için kullanılan nitelik ya da nitelik kümesi.
- **Index file:** (search-key, pointer) biçiminde **index entry** adı verilen kayıtlardan oluşur.
- İndeks dosyaları genelde ana dosyadan çok daha küçüktür.
- İki temel indeks türü vardır: **ordered index** (arama anahtarları sıralı saklanır) ve **hash index** (arama anahtarları bir hash fonksiyonuyla kovalara düzgün dağıtılır).

### 9.1 Arama anahtarı WHERE koşulundadır

Hoca arama anahtarının sorgudaki yerini örneklerle açıkladı. `SELECT T.A FROM T WHERE T.B = 10` sorgusunda B niteliği 10 olan kayıtlar aranır ve bu kayıtların A niteliğine erişilir. Erişilen nitelik A'dır ama arama anahtarı B'dir.

Gerçekçi bir örnek: `SELECT instructor.name FROM instructor WHERE salary > 10000`. Burada aranan ad değildir; maaşı 10.000'den büyük olan hocalar aranır. Bu kayıtlar bulununca adlarına zaten ulaşılmış olur. Arama salary üzerinde yapılır, name üzerinde yapılmaz.

> **Hocanın vurgusu:** Bir sorgu için anlamlı olan, sorguyu hızlandıracak indeksler WHERE koşulunda geçen nitelikler (arama anahtarları) üzerindeki indekslerdir.

Arama anahtarı üzerinde bir indeks varsa optimizer onu kullanabilir, ama kullanmayabilir de; indeks sorguya tam uymayabilir ya da başka nedenler olabilir.

### 9.2 İndeks dosyası küçüktür

İndeks aramayı hızlandırdığına göre küçük bir dosya olmalıdır ve genelde öyledir. Uç bir istisna: birkaç kayıtlık bir tablo indekslenirse indeks dosyası tablodan büyük olabilir, çünkü tabloda zaten veri yoktur ve ayrıca bir dosya daha oluşturulmuştur. İhtiyaç, tablo binlerce kayda, 30-40 MB'a ulaşınca ortaya çıkar: WHERE koşullu basit bir sorgu yavaşlamaya başlar ve indeks oluşturulunca hızlandığı görülür. 100 kayıtlık bir tabloya indeks konunca bir şey değişmez; sistem bu kadar küçük bir dosya için indeksi zaten kullanmaz.

Ordered index'lerde arama anahtarları sıralı saklanır; hash index'lerde ise bir hash fonksiyonuyla kovalara dağıtılır. İndekslerin kullanılıp kullanılmamasında optimizer'ın erişim maliyeti ve yer kaybı gibi birçok kriteri vardır; indeksler bu kriterlere göre değerlendirilir.

## 10. Sıralı İndeksler: Clustering ve Secondary

Slayttaki tanımlar (ekrandan, 02:10:00):

- **Ordered index:** indeks girişleri arama anahtarı değerine göre sıralı saklanır.
- **Clustering index:** sıralı (sequentially ordered) bir dosyada, arama anahtarı dosyanın sıralama düzenini belirleyen indeks. **Primary index** de denir. Primary index'in arama anahtarı genelde ama zorunlu olarak değil birincil anahtardır.
- **Secondary index:** arama anahtarı dosyanın sıralama düzeninden farklı bir düzen belirleyen indeks. **Nonclustering index** de denir.
- **Index-sequential file:** bir arama anahtarına göre sıralı olan ve bu anahtar üzerinde clustering index bulunan sequential dosya.

Hoca tanımları şöyle açtı: sequential dosya bir niteliğe göre sıralıydı. Bir indeksin arama anahtarı ana dosyada da sıralı olan nitelikse bu indekse clustering (primary) index denir. Bir dosya ancak tek bir niteliğe göre sıralı olabilir; aksi halde dosyanın birçok kopyası gerekir ve bu ayrı bir karmaşa yaratır. Bu yüzden bir dosyada en fazla bir clustering index olabilir. İndeksin arama anahtarı ana dosyada sıralı değilse bu bir secondary index'tir. Bu adlar farklı performans gösteren türleri ayırmak içindir: secondary index'in avantajı daha azdır, adı da bunu gösterir; ama primary index yoksa ya da kullanılamıyorsa secondary index kullanılabilir. Hoca bu konuda literatürün tam olarak aynı terimleri kullanmadığını, derste kitabın tanımlarına uyulacağını belirtti.

Index-sequential file tanımı clustering index tanımının tamamlayıcısıdır: üzerinde clustering index bulunan sequential dosyaya index-sequential file denir.

**Soru:** Burada aslında primary key'in indeks olarak seçildiği söylenebilir mi?
**Cevap:** Çoğu zaman öyle olduğu için kitap "primary index" adını da veriyor; ama slayta göre primary index'in arama anahtarı genelde ama zorunlu olarak değil birincil anahtardır. Clustering index çok değerlidir ve çoğunlukla birincil anahtar üzerinde oluşturulduğu için bu ad verilmiş olabilir.

**Soru:** Birincil anahtar üç farklı sütunun birleşiminden oluşuyorsa indeks tablonun küçük bir kopyası gibi olmaz mı? Bunu yapmak yerine tablodan okumak daha mantıklı olmaz mı?
**Cevap:** Hoca soruyu düşünerek sorulduğu için tebrik etti. Birincil anahtar her zaman tek nitelik değildir; tasarım ve normalizasyon nedeniyle iki, üç ya da daha fazla nitelik olabilir. Bunun üzerine kurulan clustering index bu niteliklerin kombinasyonuna göre sıralıdır: nitelikler A, B, C ise önce A'ya, A'nın tekrar eden değerleri içinde B'ye, onların içinde de C'ye göre sıralanır. Bu durumda ABC, BAC, CBA gibi altı farklı sıralama mümkündür ve hepsi performansı farklı etkiler. Tabloda yalnız bu üç nitelik varsa ve üçü birden birincil anahtarsa, dosya zaten bu anahtara göre sıralı olduğu için üzerine ayrıca bir clustering index kurmak anlamını kaybeder. Ama bu uç bir örnektir; çoğu zaman tabloda birincil anahtar dışında başka nitelikler de vardır ve primary index avantajlıdır.

Ardından hoca sınıfa sıralamanın erişime ne faydası olduğunu sordu (bkz. Örnek Sorular). Cevap ikili aramadır (binary search): sıralı bir dizide ortadaki elemana bakılır, sonra kalan yarının ortasına bakılır; her adımda veri kümesinin yarısı elenir ve arama asimptotik olarak $\log_2 N$ adımda biter. Sıralılık bu yüzden erişimi hızlandırır; clustering index'te de bu nedenle ikili arama yapılabilir.

## 11. Dense ve Sparse İndeksler

### 11.1 Dense index

Slayta göre **dense index**'te dosyadaki her arama anahtarı değeri için bir indeks kaydı bulunur. Örnek: instructor tablosunun ID niteliği üzerindeki indeks (ekrandan, 02:15:00).

```text
İndeks         Veri dosyası (ID'ye göre sıralı)
10101  ---->   10101  Srinivasan  Comp. Sci.  65000
12121  ---->   12121  Wu          Finance     90000
15151  ---->   15151  Mozart      Music       40000
22222  ---->   22222  Einstein    Physics     95000
32343  ---->   32343  El Said     History     60000
33456  ---->   33456  Gold        Physics     87000
45565  ---->   45565  Katz        Comp. Sci.  75000
58583  ---->   58583  Califieri   History     62000
76543  ---->   76543  Singh       Finance     80000
76766  ---->   76766  Crick       Biology     72000
83821  ---->   83821  Brandt      Comp. Sci.  92000
98345  ---->   98345  Kim         Elec. Eng.  80000
```

İndekste arama niteliğinin değeri ve o değeri içeren kayda erişimi sağlayan bir işaretçi vardır. Hoca bu işaretçiye record ID (RID) dendiğini söyledi. Her kayıttaki nitelik değeri için bir indeks kaydı oluşturulduğu için bu dense (yoğun) bir indekstir. Aynı zamanda clustering index'tir, çünkü ID dosyada da sıralıdır; dosya da index-sequential dosyadır.

Sonraki slaytta dept_name üzerinde dense index ve dept_name'e göre sıralı instructor dosyası vardır. dept_name birincil anahtar değildir ve değerleri tekrar eder. Dosya dept_name'e göre sıralıysa her farklı değer için bir indeks kaydı yazılır. Dosya bu niteliğe göre sıralı olmasaydı (Computer Science, History, Finance kayıtları dosyaya dağınık olsaydı) her kayıt için ayrı bir indeks girişi ve işaretçi gerekirdi. Hoca bu örneğin sparse indekse benzediği için biraz yanıltıcı olduğunu belirtti ve ayrıntıya girmedi.

### 11.2 Sparse index

**Sparse index** yalnız bazı arama anahtarı değerleri için indeks kaydı içerir ve yalnız kayıtlar arama anahtarına göre sıralıysa uygulanabilir; yani clustering index'ler için geçerlidir. Anahtar sıralı olduğu için her blok için tek bir indeks girişi yeterlidir.

Arama şöyle yapılır: aranan değerden küçük ya da ona eşit olan en büyük indeks girişi bulunur (milyonlarca girişte ikili aramayla $\log_2$ adımda), o girişin işaret ettiği bloğa gidilir ve blok içinde aranır. Hoca 15151 aramasını örnek verdi: indeks dense olmadığı için 15151 indekste yoktur, ama 10101 ile 32343 arasındadır. Bu iki giriş "10101 ile 32343 arasındaki kayıtlar şu bloktadır" der; o bloğa gidilince 15151 bulunur. <!-- BELİRSİZ: Sparse index slaydı karelerde tam görünmüyor; değerler hocanın anlatımından ve önceki dense index slaydından alındı. -->

Sparse indeksin avantajı daha küçük olmasıdır. Ama arama mutlaka veri dosyasına gidilerek tamamlanmalıdır: 15151'in var olup olmadığına indeksten karar verilemez. Bunu mümkün kılan, niteliklerin ana dosyada sıralı olmasıdır. Her bloğun başındaki değer indekse alınınca "bu iki giriş arasındaki değerler bu bölgededir" denmiş olur. Hoca, B+ ağacının ana fikrinin de bu olacağını söyledi.

Slayta göre dense indekse kıyasla sparse indeks ekleme ve silmelerde daha az yer ve daha az bakım yükü getirir, ama kayıt bulmada genelde daha yavaştır. Neden yavaş olduğu: dense indekste bir kaydın olmadığı indekste kalınarak anlaşılabilir; sparse indekste mutlaka ana dosyaya gidip o bloğun içinde aranan değerin olup olmadığına bakmak gerekir. İyi bir denge (good tradeoff), clustering index için dosyadaki her blok başına bir giriş tutan, girişin de bloktaki en küçük arama anahtarı değerine karşılık geldiği sparse indekstir.

### 11.3 Secondary index örneği

Secondary indekslerde arama anahtarı ana dosyada sıralı değildir; bu yüzden değerler dosyada farklı yerlere dağılır. Hoca şekilleri karşılaştırarak anlattı: clustering index şekillerinde işaretçiler birbirine paraleldir, çünkü nitelik hem indekste hem dosyada sıralıdır. Secondary index şeklinde ise işaretçiler birbirini keser; bu şekle bakarak ezbere bunun secondary index olduğu söylenebilir.

Slayttaki örnek instructor tablosunun salary alanı üzerindeki secondary indekstir (ekrandan, 02:30:00). Dosya ID'ye göre sıralıdır; indeks girişleri ise 40000, 60000, 62000, 65000, 72000, 75000, 80000, 87000, 90000, 92000, 95000 değerleridir. Her indeks kaydı, o arama anahtarı değerine sahip bütün gerçek kayıtların işaretçilerini içeren bir kovaya (bucket) işaret eder. Örneğin 80000 maaşı iki kayıtta (Singh ve Kim) bulunduğu için 80000'in kovasında iki işaretçi vardır. Hoca 62000 girişini izleyerek kovadaki record ID ile dosyadaki Califieri kaydına varıldığını gösterdi. Slayta göre secondary indeksler dense olmak zorundadır.

İndeks küçük bir dosyadır ve içinde ikili aramayla arama yapılabilir. İndeks ikili aramayla aranamayacak kadar büyür, ana belleğe de sığmazsa B+ ağacı olarak düzenlenir. Bunun öncesinde çok düzeyli (multilevel) indeks konusu gelir. Çok düzeyli indeks ve B+ ağacı sonraki derse bırakıldı.

## 12. İndeksin Maliyeti: Clustering ve Nonclustering

Konu bütünlüğü için hoca bir slayt daha işledi (ekrandan, 02:35:00):

- İndeksler kayıt ararken önemli faydalar sağlar.
- AMA indeksler veritabanı değişikliklerine ek yük getirir: bir kayıt eklenir ya da silinirse tablodaki her indeks güncellenmelidir; bir kayıt güncellenirse güncellenen nitelik üzerindeki her indeks güncellenmelidir.
- Clustering index kullanarak sıralı tarama verimlidir, ama secondary (nonclustering) index kullanarak sıralı tarama manyetik diskte pahalıdır: her kayıt erişimi diskten yeni bir blok çekebilir ve manyetik diskte her blok çekme yaklaşık 5-10 milisaniye sürer.

> **Hocanın vurgusu:** İndeksin önemli bir dezavantajı vardır ve bunu konunun başında söylemek gerekirdi. İndeks disk esaslı bir veri yapısıdır ve sonuçta bir veri tekrarıdır: arama anahtarı hem ana dosyada hem indekste geçer. Bu yüzden indekslenmiş bir nitelik güncellenince indeksler de güncellenmelidir.

Diğer dezavantaj yer kaplamaktır. Hoca bunun göz yumulabilecek düzeyde olduğunu, bir indeksin ana dosyanın yaklaşık %1'i kadar yer kapladığını söyledi. Asıl önemli olan sistemin karmaşıklığı ve güncelleme performansıdır.

Sequential scan, tablodaki bütün kayıtlara erişmek demektir. Hiçbir filtre yoksa en avantajlısı hiçbir indeks kullanmadan tabloyu taramaktır. Slayttaki "sequential scan" ifadesiyle kastedilen aslında aralık sorgusudur. Belli bir aralıktaki kayıtlar istendiğinde clustering index aralığın başlangıç değerini hızla bulur; ondan sonra kayıtlar fiziksel olarak bitişik olduğu için sıralı erişimle (sequential access) okunur. Secondary indekste ise aralıktaki kayıtlar dosyanın farklı bölgelerindedir ve rastgele erişim (random access) gerekir. Rastgele erişim, fiziksel olarak bitişik kayıtlara erişmek anlamındaki sıralı erişimden pahalıdır. Bu yüzden secondary indeksin avantajı aralık büyüdükçe azalır.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:10:41): Kitabın sonundaki indekse baktığınızda, bulduğunuz kelimenin yanında ne yazar?

> **Çözüm (derste verildi):** Sayfa numarası. Bu sayede kitabın başından itibaren aramak yerine doğrudan o sayfaya gidilir. Veritabanı indeksinde bunun karşılığı, arama anahtarının yanındaki kayıt adresidir (işaretçi, record ID).

**Soru 2** (derste sözlü, 00:34:38): Kayıtlar 8 KB'lık disk sayfaları olarak çekiliyorsa, bir tabloyu 8 KB'lık parçalara bölmek daha verimli olur mu? Bunu kullanıcı mı yapmalı, sistem kendisi mi yapar?

> **Çözüm (derste verildi):** Hayır. Tablo yüzlerce ayrı dosyaya dönüşür; her dosyanın takibi, güvenlik ve erişim bilgileri ek yük getirir. Bu karar sisteme bırakılır. Büyük tablolar ise erişim tarzına göre sütun ya da satır esaslı bölünebilir (örneğin hava raporları için 3 günlük bölümler), ama tek sayfalık dosyalar oluşturulmaz.

**Soru 3** (derste sözlü, 01:54:14): Tampon havuzu dolduğunda yeni gelen sayfa için hangi sayfa kurban edilmelidir? Çok yaygın kullanılan kurban seçim algoritması hangisidir?

> **Çözüm (derste verildi):** LRU (least recently used): en uzun süredir kullanılmayan sayfa kurban edilir. Veritabanlarında LRU-K, CLOCK ve veritabanına özgü algoritmalar da kullanılır.

**Soru 4** (derste sözlü, 02:15:08): Birincil anahtar birden fazla sütundan oluşuyorsa üzerine kurulan indeks tablonun küçük bir kopyası gibi olmaz mı?

> **Çözüm (derste verildi):** İndeks nitelik kombinasyonuna göre sıralanır (önce A, A içinde B, B içinde C). Tabloda yalnız bu nitelikler varsa ve hepsi birincil anahtarsa, dosya zaten bu anahtara göre sıralı olduğu için ayrıca clustering index kurmak anlamsızdır. Ama tabloda başka nitelikler de varsa (olağan durum) clustering index avantajlıdır.

**Soru 5** (derste sözlü, 02:19:37): Bir dosya üzerinde indeks oluştururken sıralamanın erişime ne faydası vardır?

> **Çözüm (derste verildi):** Sıralı veride ikili arama (binary search) yapılabilir: her adımda kümenin yarısı elenir, arama $\log_2 N$ adımda biter. Örneğin bir milyon kayıtta yaklaşık $\log_2 10^6 \approx 20$ adım yeter.

## Dersin Toparlaması

Bu derste fiziksel tasarımın temelleri işlendi. Tablolar, veritabanı sisteminin denetimindeki dosyalarda saklanır; dosyalar disk sayfalarından, sayfalar kayıtlardan, kayıtlar niteliklerden oluşur. Veri diskten her zaman sayfa birimiyle (veritabanlarında çoğunlukla 8 KB) okunur. Sabit uzunluklu kayıtlarda adres hesabı ve boş yer yönetimi (kaydırma, son kaydı taşıma, free list) basittir. Değişken uzunluklu kayıtlarda kayıt içinde (offset, uzunluk) çiftleri ve null bitmap, sayfa içinde slotted page yapısı kullanılır; büyük nesneler için PostgreSQL'de TOAST gibi ayrı düzenler vardır. Dosya organizasyonları heap, sequential, multitable clustering, B+ ağacı ve hashing'dir. Partitioning büyük tabloları sorgu tarzına göre küçük parçalara böler. Katalog veri hakkındaki veriyi ilişkisel tablolarda tutar. Tampon da disk ile bellek arasındaki büyük hız farkını kapatır, ama tutarlılık ve kurtarma sorunları getirir.

İkinci bölümde indekslemeye giriş yapıldı: arama anahtarı, indeks girişi, ordered ve hash index, clustering (primary) ve secondary (nonclustering) index, dense ve sparse index. İndeks okumayı hızlandırır ama her değişiklikte güncellenmesi gereken bir veri tekrarıdır. Clustering index aralık sorgularında çok verimlidir; secondary index'in avantajı ise aralık büyüdükçe kaybolur. Bir sonraki derste çok düzeyli indeksler ve B+ ağacı birkaç örnekle işlenecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
