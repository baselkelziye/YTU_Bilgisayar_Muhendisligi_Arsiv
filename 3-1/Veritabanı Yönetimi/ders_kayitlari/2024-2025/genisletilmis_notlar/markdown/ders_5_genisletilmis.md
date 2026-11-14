# Ders 5 Genişletilmiş Notu: Veritabanı Tasarım Süreci ve Varlık-Bağıntı (ER) Modeli

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

<!-- BELİRSİZ: Kaydın 00:41-01:37 ve 01:52-02:22 aralıklarında ses büyük ölçüde anlaşılmıyor; altyazı bu aralıklarda anlamsız ve tekrar eden satırlardan oluşuyor. Bu kısımlar yalnız ekrandaki slaytlardan yazıldı; hocanın açıklamaları aktarılamadı. 01:05-01:37 arasında paylaşılan ekran da 6.32 numaralı slaytta donmuş görünüyor, bu aradaki slaytlar (6.33-6.37) görülemedi. -->

## İçindekiler

- 1. Kavramsal Tasarıma Giriş
- 2. Tasarım Süreci: Gereksinimlerden Fiziksel Tasarıma
- 3. Mantıksal Tasarımın Katılığı ve NoSQL
- 4. İki Tuzak: Fazlalık ve Eksiklik
- 5. ER Modelinin Temel Kavramları
- 6. Bağıntı Setleri, Nitelikleri ve Roller
- 7. Bağıntının Derecesi
- 8. Eşleme Kardinalitesi ve Katılım
- 9. Zayıf Varlık Setleri
- 10. Fazlalık İçeren Nitelikler ve Üniversite ER Diyagramı
- 11. ER Diyagramından İlişkisel Şemalara
- Örnek Sorular

## 1. Kavramsal Tasarıma Giriş

Bu derste kitabın 6. bölümüne (ER diyagramları) geçildi; önceki bölüm (Advanced SQL) bitmişti. Slaytlar yine Silberschatz, Korth ve Sudarshan'ın *Database System Concepts* (7. baskı) kitabındandır (ekrandan, 00:40:00).

Hoca bölümün içeriğini şöyle özetledi: tasarım süreci; ER diyagramı ve kavramsal tasarımı kâğıda dökmek için kullanılan şekiller; karmaşık nitelikler, kardinaliteler ve birincil anahtarın nasıl ifade edildiği; zayıf varlık; daha iyi bir ER diyagramı çizmeye yönelik dönüşümler; özelleştirme (specialization), genelleştirme (generalization) ve birleştirme (aggregation) gibi kavramları içeren genişletilmiş ER (EER); ve kavramsal tasarımın ilişkisel model tablolarına dönüştürülmesi. ER bir tür standarttır: Burada çizilen bir diyagrama yurt dışındaki biri baktığında da onu anlar.

Hoca ayrıca UML'den (Unified Modeling Language) bahsetti. UML bir yazılım mühendisliği kavramıdır; modelleme yapıldığı için veritabanı dünyası da ondan payını almıştır ve UML ile de tasarım yapılabilir. Ancak veritabanının klasik tarzı ER ve EER'dir; çoğu veritabanı kitabında bunlar görülür.

Bir sonraki bölüm (Chapter 7) normalizasyondur; veri bütünlüğüyle (data integrity) ilgilidir ve tanımlarla formalize edilmiştir. Bu derste 1NF, 2NF, 3NF ve BCNF işlenecek, 4NF ve 5NF gibi ağır teorili kısımlara girilmeyecek.

## 2. Tasarım Süreci: Gereksinimlerden Fiziksel Tasarıma

Kavramsal tasarımda başa dönüyoruz: Küçük bir dünyamız var ve onu kâğıda aktaracağız.

### 2.1 Veri ihtiyaçları

İlk adım, veritabanı kullanıcılarının bakış açısından veri ihtiyaçlarını (data needs) belirlemektir: Bu küçük dünyadaki kullanıcılar hangi veriyi istiyor, hangi veriyi saklamam lazım? Üniversite veritabanında öğrenciler, hocalar, dersler, her dönem açılan şubeler (section) vardır.

Hoca bunu cümlelerle anlattı: Öğrencilerimiz var, öğrenciler ders alıyor. Dersler her dönem ya da bazı dönemler açılıyor; açıldığı dönem birden çok şube açılabiliyor. Öğrenciler dersi bir hocadan alıyor, not alıyor, belli bir bölüme bağlılar. Bunu bir kompozisyon gibi yazdığımızda öznelerin çoğu zaman varlıklarımız olduğunu görürüz.

Hocanın vurguladığı bir ayrıntı: Bu veritabanı tek bir üniversite içindir. Tek bir üniversitedeki bölümler, öğrenciler, dersler saklanır; ülkedeki üniversiteleri listelemek gibi bir ihtiyaç yoktur. Bu yüzden "üniversite" bir varlık seti olarak aranmaz. Gereksinim listesini düzgün ifade etmek ve oradan hangi veriye ihtiyaç olduğunu çıkarmak gerekir.

### 2.2 Fonksiyonel gereksinimler

İkinci adım, bu veriyle ne yapılacağıdır (functional requirements): Öğrenciler derse kaydolacak, dersten geçecek ya da kalacak. Cümlelerdeki yüklemler burada işlemleri verir. Bu işlem bir bütünlük gerektiren, işlem (transaction) tarzı bir şey olabilir; basit bir şeyse ilişkilerle ifade edilir. Örneğin "öğrenci şu dersi aldı" bağlantısı ER diyagramında bir elmasla gösterilir.

### 2.3 Mantıksal ve fiziksel tasarım

Kâğıda aktarılan tasarım daha sonra makineye taşınır. Mantıksal tasarımda (logical design) hangi ilişkisel şemanın, hangi tabloların, hangi niteliklerin, hangi domenlerin ve hangi anahtarların olacağı ortaya çıkar.

Fiziksel tasarımda (physical design) ise tablolarımızın makinedeki yansımalarına bakılır. Veritabanı diskte olduğu için her tablo diskte bir dosyada saklanır. Bu dosyaların biçimi, indeks dosyaları ve kullanılan veri yapıları buradaki konulardır: B+ ağacı, hash, büyük veri sistemlerinde kullanılan LSM ağacı gibi. Büyük veri platformlarında sütun yönelimli (column-oriented) Parquet ve Avro gibi farklı dosya formatları vardır. Bir sorguya hemen cevap gelmesini ve herkesin aynı anda sistemi kullanabilmesini sağlayan algoritmalar bu katmanda çalışır.

## 3. Mantıksal Tasarımın Katılığı ve NoSQL

Hocaya göre iki tasarım da zordur ve tecrübe ister; tasarım küçük bir fonksiyon yazmak gibi değildir. Bir ağacın çekirdeği gibidir: Bütün ağacın meyveleri o çekirdeğe bağlıdır. Veritabanı belki yıllarca kullanılacaktır; tasarım kötüyse performanslı olmaz ve kullanılmaz. Üniversitedeki tek kişilik projelerde tasarım çoğu zaman bir prototiptir; ama gerçek hayatta geleneksel ilişkisel model tarzında bir veritabanı tasarımı tek kişinin işi değildir. Başka bir küçük dünyaya gittiğimizde o dünyayı öğrenmemiz gerekir: Kimler ne yapacak, hangi veriler var? Bu yüzden tasarım, o rollerle iletişim kuran ve geri beslemeli bir ekip çalışmasıdır.

Mantıksal tasarım fiziksel tasarımdan daha kritiktir. Fiziksel tasarım daha esnektir: B+ ağacı kullanıyordum, hash'e geçtim; LSM kullanıyordum, başka bir şeye geçtim. Bu geçişler yalnız performansı etkiler; veritabanını "tune ederiz". Uygulamalar değişmez, çünkü fiziksel veri bağımsızlığı (physical data independence) vardır. Oysa birçok kişinin kullandığı bir veritabanında tablonun şemasını değiştirmek zordur; ilişkisel model katıdır.

NoSQL'in çıkış noktalarından biri de bu katılıktır. Gerçek hayat üniversitenin küçük dünyası gibi katı ve deterministik değildir. Sosyal medya platformlarındaki veriler, film izleyenlerin verdiği puanlar, farklı türdeki filmlerin farklı özellikleri, e-ticaret sitesinde her ürün için farklı nitelik setleri esnek şema ister. Banka, muhasebe ve üniversite gibi ihtiyaçları net alanlar ise ilişkisel modele çok daha uygundur.

> **Hocanın vurgusu:** NoSQL ne kadar yaygın olsa da SQL sistemleri endüstrinin büyük kısmına (hocanın tahminiyle %70-80'ine) hâkimdir. Köklü (legacy) sistemlerden geçiş kolay değildir; kimse birkaç yıl içinde ilişkisel sistemlerin kalkacağını söylemiyor. Sistem ihtiyaca göre seçilir; esnek şema ve dağıtık veri gerektiren yeni sistemlerde NoSQL tercih edilir.

## 4. İki Tuzak: Fazlalık ve Eksiklik

Mantıksal tasarımda kötü tasarımdan kaçınmak için esaslar vardır; bunlar ileride (normalizasyonda) maddeler hâlinde görülecek. Ancak bu esaslara uyulsa bile iyi tasarım tek değildir; üç beş, on tane farklı iyi tasarım olabilir ve hangisinin seçildiği ileride performansı etkiler. Bu yüzden tasarım hem bilim hem sanattır: Mühendislik esasları vardır, ama bir yere kadar; gerisi meleke ve tecrübedir.

Slayta göre tasarımda iki büyük tuzaktan kaçınmak gerekir:

- **Fazlalık (redundancy):** Bazı bilgilerin birden çok kez tekrar etmesi. Bunu önlemek için tablolar parçalanır. Tasarım yapıldıktan sonra geri beslemeyle test edilip azaltılır; büyük veritabanı tasarımlarında daha çok karşımıza çıkar.
- **Eksiklik (incompleteness):** Küçük dünyada istenen her şeyin modele tam aktarılamaması. Hoca, bazı şeylerin veri modeline değil fonksiyonel olarak (uygulamada) aktarılmasının daha uygun olabileceğini de ekledi.

Hoca, tasarım sonrası normalizasyon kurallarıyla bir "tuning" yapılacağını, bunun veri bütünlüğü ve veri kaybı olmaması için gerekli olduğunu söyledi. "Bir tasarımda nasıl veri kaybı olur?" sorusunun ilginç olduğunu ve normalizasyonda bununla ilgili çarpıcı örnekler göreceğimizi belirtti.

## 5. ER Modelinin Temel Kavramları

ER diyagramında üç temel yapı vardır: varlık setleri (entity sets), bağıntı setleri (relationship sets) ve nitelikler (attributes).

**Varlık (entity)** tek bir bireydir: bir kişi, bir öğrenci, bir hoca. Fiziksel olarak tablodaki bir satıra karşılık gelir. **Varlık seti** ise aynı niteliklere sahip varlıklardan oluşan kümedir; örneğin `instructor` varlık seti (`ID`, `name`, `salary`) ya da `course` (`course_id`, `title`, `credits`). Küme (set) benzersiz elemanlardan oluştuğu için her elemanı tek olarak tanımlayan bir nitelik ya da nitelik grubuna, yani anahtara ihtiyaç vardır.

Hoca anahtar kavramlarını hatırlattı: Bir varlık setinde birden çok anahtar (aday anahtar, candidate key) olabilir. Birincil anahtar (primary key) bunlar arasından veritabanını tasarlayan kişinin yaptığı seçimdir; birincil anahtar bir tanedir. Bu kavramlar fonksiyonel bağımlılıklarda tekrar kullanılacak.

ER diyagramında varlık seti başlıklı bir dikdörtgendir; altında nitelikler yazılır ve altı çizili olanlar birincil anahtarı oluşturur. Birincil anahtar seçimi daha kavramsal tasarım aşamasında yapılır.

Nitelik türleri (basit ve bileşik, tek değerli ve çok değerli, türetilmiş), zayıf ve güçlü varlık setleri, bağıntıların kardinalitesi (bire bir, bire çok, çoka çok) ve tam katılım (total participation) da bu bölümün konularıdır.

## 6. Bağıntı Setleri, Nitelikleri ve Roller

**Bağıntı (relationship)** iki varlık arasındaki bir ilişkidir; **bağıntı seti** bu ilişkilerin kümesidir. Slayttaki `advisor` bağıntı setinde her eleman bir hoca-öğrenci çiftidir: Bir hoca bir öğrencinin danışmanıdır, başka bir hoca iki farklı öğrencinin danışmanıdır. ER diyagramında bağıntı seti iki varlık setini bağlayan bir elmasla (diamond) gösterilir.

Bağıntı setinin de nitelikleri olabilir. Varlık setlerinin `ID`, `name` gibi nitelikleri olduğu gibi, birden çok varlıktan gelen bilgilerin toplandığı bağıntının da kendi niteliği olabilir: `advisor` bağıntısında danışmanlığın başladığı tarih (`date`). Her bağıntı elemanının kendi tarihi vardır; aynı hoca iki öğrenciye farklı tarihlerde danışmanlık etmeye başlamış olabilir. ER diyagramında bu nitelik, elmasa kesikli çizgiyle bağlanan bir dikdörtgenle gösterilir (ekrandan, 00:40:00):

```text
 instructor            date              student
+-----------+           :            +-----------+
| ID        |           :            | ID        |
| name      |------< advisor >-------| name      |
| salary    |                        | tot_cred  |
+-----------+                        +-----------+
```

Bağıntılarda roller de tanımlanabilir. `advisor` bağıntısında `instructor` danışman rolünde, `student` öğrenci rolündedir; rol, bağıntının anlamını açığa çıkarır. İkili bağıntılarda roller çoğu zaman açıktır. Ama bazı bağıntılar özyinelemelidir (recursive): Bir varlık seti kendisiyle bağıntı içindedir. Örneğin her dersin ön koşul dersleri olabilir ve ön koşul da bir derstir. Bir dersin ön koşullarını saklamak için `course` ile yine `course` arasında `prereq` bağıntısı kurulur. Aynı varlık seti iki kez katıldığı için hangi tarafın ders, hangi tarafın ön koşul olduğu rollerle (`course_id` ve `prereq_id`) belirtilmelidir.

## 7. Bağıntının Derecesi

Slayta göre (ekrandan, 00:45:30):

- **İkili (binary) bağıntı** iki varlık setini içerir (derecesi ikidir). Bir veritabanındaki bağıntı setlerinin çoğu ikilidir.
- İkiden fazla varlık seti arasındaki bağıntılar nadirdir. Örnek: Öğrenciler bir hocanın rehberliğinde araştırma projelerinde çalışır. `proj_guide` bağıntısı `instructor`, `student` ve `project` arasında üçlü (ternary) bir bağıntıdır.

Bazı durumlarda bağıntıyı ikili olmayan biçimde göstermek daha uygundur (ekrandan, 00:50:00). Slayttaki diyagramda `proj_guide` elması `instructor`, `student` ve `project` dikdörtgenlerine bağlıdır.

<!-- BELİRSİZ: Hocanın üçlü bağıntıyla ilgili açıklamaları (00:44-00:47 civarı, "T1 projesi", "danışman" gibi kırık ifadeler) altyazıda anlaşılmıyor. -->

## 8. Eşleme Kardinalitesi ve Katılım

**Eşleme kardinalitesi kısıtları** (mapping cardinality constraints), bir varlığın bir bağıntı seti üzerinden kaç varlıkla ilişkilendirilebileceğini belirtir; en çok ikili bağıntıları tanımlarken işe yarar. İkili bir bağıntı setinin eşleme kardinalitesi şunlardan biri olmalıdır (ekrandan, 00:55:30):

- Bire bir (one to one)
- Bire çok (one to many)
- Çoka bir (many to one)
- Çoka çok (many to many)

ER diyagramında kardinalite, bağıntı seti ile varlık seti arasına çizilen yönlü çizgiyle (ok, "bir") ya da yönsüz çizgiyle ("çok") ifade edilir (ekrandan, 01:00:00). `instructor` ile `student` arasındaki `advisor` bağıntısında iki tarafta da ok varsa bağıntı bire birdir: Bir öğrenci `advisor` üzerinden en fazla bir hocayla, bir hoca da en fazla bir öğrenciyle ilişkilidir. Slaytta ayrıca bir öğrencinin `stud_dept` üzerinden en fazla bir bölümle ilişkili olduğu örneği vardı.

Daha karmaşık kısıtlar için bir çizgiye minimum ve maksimum kardinalite `l..h` biçiminde yazılabilir; `l` minimum, `h` maksimum kardinalitedir (ekrandan, 01:05:30):

- Minimum değerin 1 olması tam katılım (total participation) demektir.
- Maksimum değerin 1 olması varlığın en fazla bir bağıntıya katıldığı demektir.
- Maksimum değerin `*` olması sınır olmadığı demektir.
- Bu gösterimde ok kullanılmaz; `l..h` hem kardinaliteyi hem katılımı anlatır.

Slayttaki örnekte `instructor` tarafında `0..*`, `student` tarafında `1..1` yazar: Bir hoca 0 ya da daha çok öğrenciye danışmanlık edebilir; bir öğrencinin tam olarak bir danışmanı olmalıdır, birden çok danışmanı olamaz. Bu bire çok bir bağıntıdır ve öğrenci tarafı tam katılımlıdır. Aynı şey, hoca tarafında ok ve öğrenci tarafında çift çizgiyle de gösterilir:

```text
 instructor  0..*            1..1  student
+---------+                       +---------+
| ID      |------< advisor >------| ID      |
| name    |                       | name    |
| salary  |                       | tot_cred|
+---------+                       +---------+

eşdeğer gösterim:
 instructor <------ < advisor > ====== student
             (ok: "bir")       (çift çizgi: tam katılım)
```

<!-- BELİRSİZ: Slayt 6.32'den sonraki kısımda (01:05-01:37) ekran donmuş ve ses anlaşılmıyor; tam ve kısmi katılım, nitelik türleri ve zayıf varlık girişine dair hocanın anlatımı aktarılamadı. -->

## 9. Zayıf Varlık Setleri

Ses 01:37'de tekrar anlaşılır hâle geliyor. Hoca zayıf varlık setini (weak entity set) üniversite veritabanındaki `section` örneğiyle anlattı (ekrandan, 01:40:00).

Dersler `course(course_id, title, credits)` tablosundadır. Her dönem bir dersin birden çok şubesi açılır; şubeler `section(course_id, sec_id, semester, year)` ile ifade edilebilir. `section` ile `course` arasında bire çok bir `sec_course` bağıntısı kurulabilir, çünkü şubedeki dersin ayrıntılı bilgileri `course`'tadır. Ama o zaman `course_id` hem `section`'da hem bağıntıda bulunur; bu bir fazlalıktır.

Tasarımda varlık setlerini oluşturup bağıntıları kuruyoruz; bu noktada `course_id`'yi `section`'dan çıkarırsak `section`'ın anahtarı kaybolur. `course_id` kalsaydı anahtar `course_id` ve `sec_id` birlikte olurdu; ikisi de tek başına anahtar olamazdı. `course_id` çıkınca `sec_id` tek başına anahtar olamaz, çünkü her dersin şubeleri vardır. Slaytta da bu fazlalıkla başa çıkmanın bir yolunun `sec_course` bağıntısını atmak olduğu, ama bu durumda `section` ile `course` arasındaki ilişkinin bir nitelik içinde örtük kalacağı ve bunun istenmediği yazıyordu.

Bu durumda `section`'a zayıf varlık seti denir. Zayıf varlık setindeki varlıkları birbirinden ayırt etmek için anahtarı olan güçlü bir varlığa, yani belirleyici varlığa (identifying entity) bir bağıntı kurulur; bu bağıntıya belirleyici bağıntı (identifying relationship) denir. Hem zayıf varlık seti hem belirleyici bağıntı çift çizgiyle çizilir.

Güçlü bir varlığın altındaki zayıf varlıkları ayırt etmek için hangi niteliklere ihtiyaç vardır? `sec_id` yetmez: Bir dersin şube numaraları her dönem değişmez; bu dönem 1, 2, 3 numaralı şubeler açıldıysa bahar döneminde de 1, 2, 3 açılır. `sec_id` ve `semester` de yetmez: 2024 güz döneminde de 2025 güz döneminde de 1, 2, 3 numaralı şubeler açılır. Ancak üçü birden (`sec_id`, `semester`, `year`) şubeleri ayırt eder. Buna anahtar değil, ayırt edici (discriminator) denir.

Zayıf varlık setinin tanım gereği biçimi şöyledir:

- Bir ayırt edicisi olmalıdır.
- Belirleyici bağıntıya katılımı tam olmalıdır (çift çizgi): Her zayıf varlığın mutlaka bir güçlü varlığı olmalıdır.
- Tek bir güçlü varlığa bağlanmalıdır; bu yüzden güçlü taraf ok ile gösterilir.
- Bazı tasarımlarda bir zayıf varlık birden çok güçlü varlığa bağlanabilir, ya da zayıflar geçişli olarak bir araya gelip bir güçlüye bağlanabilir.

```text
 course                                section
+-------------+                      +================+
| course_id   |<----<< sec_course >>=| sec_id  (ayırt)|
| title       |                      | semester(ayırt)|
| credits     |                      | year    (ayırt)|
+-------------+                      +================+
(<< >> ve ===: çift çizgili belirleyici bağıntı ve zayıf varlık)
```

> **Hocanın vurgusu:** Zayıf varlıklar bizi korkutmasın; zayıf olması bilakis daha iyi bir şeydir. Fazlalıktan kurtulmak için ortaya çıkar. Fiziksel tasarımda iki dosyada ayrı birincil anahtar kısıtı takip etmek yerine bir birincil anahtar ve onun altında ayırt ediciler takip edilir; yük hafifler.

## 10. Fazlalık İçeren Nitelikler ve Üniversite ER Diyagramı

Tasarımda bir başka fazlalık türü, bağıntıdan çıkarılabilen niteliklerdir. `student` varlığında `ID`, `name`, `tot_cred` vardır. `department` varlığında `dept_name`, `building`, `budget` vardır. Öğrenciler bir bölüme bağlı olduğu için `student` ile `department` arasında `stud_dept` bağıntısı kurulur. Bu bağıntı her öğrencinin bir bölümü olduğunu, bir bölümde birçok öğrenci olduğunu söyler. O zaman `student` içindeki `dept_name` fazlalıktır; bu bilgi bağıntıdan çıkarılabilir ve `dept_name` `student`'tan çıkarılır. Aynısı `instructor` için de geçerlidir: Hocanın bağlı olduğu bölümün bilgilerini elde etmek için `inst_dept` bağıntısı kurulmalıdır, kurulunca `instructor` içindeki `dept_name` çıkarılır.

Bu esaslarla bütün üniversite ER diyagramı çizilebilir (ekrandan, 01:46:40). Slayttaki tasarım sezgisi iki adımdır: (1) Varlık setlerini nitelikleriyle belirle; (2) fazlalıkları tespit et. Slayttaki kırmızı notlar, fazlalık kontrolü yapılmasaydı şemaların `student(ID, name, tot_cred, dept_name, advisor, section)` ve `section(course_id, sec_id, semester, year, building, room_number, time_slot_id)` olacağını gösteriyor; bağıntılardan çıkarılabilen nitelikler kalın yazılmış.

Diyagramdaki varlık setleri `department`, `instructor`, `student`, `course`, `section`, `time_slot` ve `classroom`; bağıntılar `course_dept`, `inst_dept`, `stud_dept`, `advisor`, `teaches`, `takes` (niteliği `grade`), `prereq`, `sec_course`, `sec_time_slot` ve `sec_class`'tır.

Hoca birkaç çizgiyi okudu:

- `section`'ın güçlüsü `course`'tur; `prereq` ise `course` üzerindeki özyinelemeli bağıntıdır.
- Her şubeye bir `time_slot_id` verilir. Bir zaman dilimi numarasının birden çok oturumu olabilir; örneğin bu dersin bir zaman dilimi numarası ve iki oturumu vardır. Bu yüzden `day`, `start_time`, `end_time` çok değerli (multivalued) bir niteliktir (slaytta "Dersin farklı oturumları olabilir" notu).
- `sec_time_slot`'ta şube tarafı tam katılımlıdır: Her şubenin bir zaman dilimi olmalıdır. Ama bir zaman dilimi numarası bir dönem kullanılıp başka dönem kullanılmayabilir; o taraf kısmidir.
- `course_dept` bire çoktur: Bir ders tek bir bölüm tarafından açılır, iki bölüm ortak açmaz. Bir bölüm birden çok ders açabilir, ama hiç ders açmamış bir bölüm de olabilir (kısmi). Ders tarafındaki çift çizgi, açılan her dersin bir bölüm bünyesinde açıldığını söyler.

Hoca, diyagramdaki her çizginin küçük dünyada bir anlamı olduğunu söyledi. Diyagrama bakıp gereksinim listesini yazmak (tersine mühendislik, reverse engineering) daha kolaydır; gereksinim listesinden diyagram çizmek ise tasarım yapmak olduğu için daha zordur. İki yönde de alıştırma yapılmalıdır; kitabın sonundaki örnekler oldukça standarttır.

Hoca son olarak dersin ön koşullarını `course` içinde `prerequisites` diye bir nitelik olarak tutmayı tartıştı: Bu nitelik çok değerli (multivalued) olurdu, ama değerleri yine derslerdir. Bu yüzden ön koşul bir nitelik değil, `course` üzerinde bir bağıntı olarak modellenir.

<!-- BELİRSİZ: Bu tartışmanın 01:53'ten sonraki kısmı altyazıda anlaşılmıyor; yukarıdaki son cümle slayttaki `prereq` bağıntısına dayanıyor. -->

## 11. ER Diyagramından İlişkisel Şemalara

Bu kısmın sesi büyük ölçüde anlaşılmıyor (01:52-02:22); aşağıdakiler ekrandaki slaytlardandır.

### 11.1 Bileşik nitelikler

Slayttaki `instructor` varlığında şu nitelikler var (ekrandan, 02:05:30):

```text
instructor
  ID
  name
    first_name
    middle_initial
    last_name
  address
    street
      street_number
      street_name
      apt_number
    city
    state
    zip
  { phone_number }
  date_of_birth
  age ( )
```

`name` ve `address` bileşik (composite) niteliklerdir; `{phone_number}` çok değerlidir; `age()` türetilmiştir (doğum tarihinden hesaplanır). Bileşik nitelikler, her bileşen için ayrı bir nitelik oluşturularak düzleştirilir. `name`'in bileşenleri `first_name` ve `last_name` ise şemada `name_first_name` ve `name_last_name` olur; belirsizlik yoksa ön ek atılır (`first_name`). Çok değerli nitelikler dışarıda bırakılınca genişletilmiş `instructor` şeması:

```text
instructor(ID,
           first_name, middle_initial, last_name,
           street_number, street_name,
           apt_number, city, state, zip_code,
           date_of_birth)
```

### 11.2 Çok değerli nitelikler

Bir `E` varlığının çok değerli niteliği `M`, ayrı bir `EM` şemasıyla gösterilir (ekrandan, 02:10:00). `EM`, `E`'nin birincil anahtarına karşılık gelen nitelikleri ve `M`'ye karşılık gelen bir niteliği içerir. Örnek: `instructor`'ın çok değerli `phone_number` niteliği şu şemayla gösterilir:

```text
inst_phone = (ID, phone_number)
```

Çok değerli niteliğin her değeri, `EM` ilişkisinde ayrı bir satıra karşılık gelir. Birincil anahtarı 22222 olan ve telefon numaraları 456-7890 ile 123-4567 olan bir hoca iki satıra dönüşür: `(22222, 456-7890)` ve `(22222, 123-4567)`.

### 11.3 Bağıntı setleri ve şema fazlalığı

Çoka çok bir bağıntı seti, katılan iki varlık setinin birincil anahtarlarını ve bağıntının tanımlayıcı niteliklerini içeren bir şemayla gösterilir; örneğin `advisor = (s_id, i_id)` (ekrandan, 02:10:00, sonraki slayt önizlemesi).

Slayta göre (ekrandan, 02:13:00), "çok" tarafında tam katılımlı çoka bir ve bire çok bağıntı setleri ayrı şema yerine "çok" tarafına, "bir" tarafının birincil anahtarını içeren ek bir nitelik (yabancı anahtar) eklenerek gösterilebilir. Örnek: `inst_dept` için ayrı şema kurmak yerine `instructor` şemasına `dept_name` eklenir.

Devam slaytına göre (ekrandan, 02:20:00):

- "Çok" tarafında katılım kısmiyse, şemanın "çok" tarafına ek nitelik koymak boş (null) değerlere yol açabilir. İki seçenek vardır: Önceki durumdaki gibi (tam katılımlı N tarafı) yapmak ya da bağıntı için yeni bir şema kurmak.
- Bire bir bağıntılarda iki taraftan herhangi biri "çok" tarafı olarak seçilebilir; ek nitelik iki varlık setinin tablolarından herhangi birine eklenebilir.
- Sonraki slayt önizlemesine göre, zayıf varlık setini belirleyici güçlü varlığına bağlayan bağıntının şeması fazlalıktır: `section` şeması, `sec_course` şemasında bulunacak nitelikleri zaten içerir.

Ders sonunda (02:24) hoca bir soruyu cevapladı: Bire bir bağıntıda iki tarafın da tam katılımlı olmasının anlamı, iki varlık setinde aynı sayıda eleman olması ve her elemanın karşı taraftaki tam bir elemanla eşleşmesidir; 1000 eleman varsa karşıda da 1000 eleman vardır. Hoca, böyle bir kısıtın küçük dünyanın gereğine bağlı olduğunu, "bire birse tam olmalı" ya da "bire çoksa kısmi olmalı" gibi bir kural olmadığını, yalnız üniversite örneğiyle kalmayıp farklı örneklere bakılması gerektiğini söyledi.

## Örnek Sorular

**1.** (derste sözlü, 01:43:11) `section` zayıf varlık setinde, aynı dersin şubelerini birbirinden ayırt etmek için hangi nitelikler gerekir? Neden?

Derste verilen cevap: `sec_id` yetmez, çünkü şube numaraları her dönem yeniden 1, 2, 3 diye verilir. `sec_id` ve `semester` de yetmez, çünkü farklı yılların aynı döneminde aynı şube numaraları kullanılır. Ancak `sec_id`, `semester` ve `year` üçü birden şubeleri ayırt eder; bu nitelik grubu ayırt edicidir (discriminator). Şubenin tam tanımı için güçlü varlığın anahtarı `course_id` de gerekir: `section` şemasının birincil anahtarı `(course_id, sec_id, semester, year)` olur.

**2.** (ekrandan, 02:10:00) Birincil anahtarı 22222 olan bir hocanın 456-7890 ve 123-4567 olmak üzere iki telefon numarası var. Çok değerli `phone_number` niteliği şemaya nasıl dönüştürülür ve bu hoca için hangi satırlar oluşur?

Slayttaki çözüm: Ayrı bir `inst_phone = (ID, phone_number)` şeması kurulur. Hoca için iki satır oluşur: `(22222, 456-7890)` ve `(22222, 123-4567)`.

**3.** (derste sözlü, 02:24:18) Bire bir bir bağıntıda iki tarafın da tam katılımlı olması ne anlama gelir?

Derste verilen cevap: Her iki varlık setinde aynı sayıda eleman vardır ve her eleman karşı taraftaki tam bir elemanla eşleşir. Bu kısıt küçük dünyanın gereğine göre konur ya da konmaz; kardinalite ile katılım arasında zorunlu bir bağ yoktur.

## Dersin Toparlaması

Bu derste veritabanı tasarım süreci (veri ihtiyaçları, fonksiyonel gereksinimler, mantıksal ve fiziksel tasarım) ve mantıksal tasarımın neden daha kritik olduğu anlatıldı. Fazlalık ve eksiklik tuzakları, ER modelinin varlık seti, bağıntı seti ve nitelik kavramları, bağıntı nitelikleri, roller ve özyinelemeli bağıntılar, bağıntının derecesi, eşleme kardinalitesi ve `l..h` gösterimi görüldü. Zayıf varlık setleri `section` örneğiyle ayırt edici ve belirleyici bağıntı kavramlarıyla işlendi; bağıntıdan çıkarılabilen niteliklerin fazlalık olduğu gösterildi ve bütün üniversite ER diyagramı okundu. Son olarak ER diyagramının ilişkisel şemalara dönüştürülmesine başlandı: bileşik ve çok değerli nitelikler ile bağıntı setlerinin dönüşümü ve şema fazlalığı.

Hoca bir sonraki derste genişletilmiş ER'nin (EER) bitirileceğini ve normalizasyona geçileceğini söyledi; konunun kitaptan mutlaka okunmasını önerdi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
