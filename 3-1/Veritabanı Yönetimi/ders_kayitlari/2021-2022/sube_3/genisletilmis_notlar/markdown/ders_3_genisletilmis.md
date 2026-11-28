# Ders 3 Genişletilmiş Notu: Ara SQL: Join Türleri, View, Transaction, Bütünlük Kısıtları, Veri Tipleri, İndeks ve Yetkilendirme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Join Türlerinin Tekrarı
- 2. View (Görünüm)
- 3. Materialized View
- 4. Transaction
- 5. Bütünlük Kısıtları
- 6. Referential Integrity ve Foreign Key
- 7. Assertion ve Trigger
- 8. SQL Veri Tipleri ve Kullanıcı Tanımlı Tipler
- 9. SQL'de İndeks Tanımı
- 10. Yetkilendirme (Authorization)
- Örnek Sorular
- Dersin Toparlaması

Ders, Zoom üzerinden yapıldı. Hoca, "Database System Concepts" (7. baskı) kitabının 4. bölümü olan "Intermediate SQL" slaytlarını kullandı. Slaytın içerik listesi: Join Expressions, Views, Transactions, Integrity Constraints, SQL Data Types and Schemas, Index Definition in SQL, Authorization (ekrandan, 00:05:00). Slaytların yanında bir çizim tahtası ve bir metin düzenleyicide yazılan SQL örnekleri de kullanıldı.

## 1. Join Türlerinin Tekrarı

### 1.1 NATURAL JOIN ile INNER JOIN arasındaki fark

Ders, bir önceki hafta işlenen join türlerinin soru-cevapla tekrarıyla başladı.

**Soru:** NATURAL JOIN ile INNER JOIN arasındaki temel fark nedir? **Cevap:** INNER JOIN'de eşleştirme koşulunu `ON` ile, örneğin ID'leri eşitleyerek, açıkça belirtmek gerekir. NATURAL JOIN'de böyle bir koşul yazılmaz; iki tabloda aynı adı taşıyan kolonlar varsa birleştirme kendiliğinden bu kolonlar üzerinden yapılır.

**Soru:** Başka bir fark var mı? **Cevap:** Gösterim farkı vardır. INNER JOIN ile `SELECT *` yapıldığında, iki tabloda da bulunan eşleşme kolonu sonuçta iki kez görünür. NATURAL JOIN'de bu kolon zaten aynı adlı ve tekrar eden kolon olduğu için sonuçta yalnız bir kez gösterilir.

Bu fark küçük bir örnekle doğrulanabilir (ders sonrası sqlite3 ile denendi): `a(ID, name)` ve `b(ID, salary)` tablolarında `a natural join b` sonucu `ID, name, salary` kolonlarından oluşurken `a inner join b on a.ID = b.ID` sonucu `ID, name, ID, salary` kolonlarından oluşur.

### 1.2 NATURAL JOIN'in riski

**Soru:** NATURAL JOIN ne tür risklere yol açabilir? **Cevap:** Yanlış eşleştirme. NATURAL JOIN'in eşleştirirken baktığı tek şey kolonun adıdır; adlar örtüşüyor ve veri tipleri uyumluysa başka bir şeye bakmaz.

Hocanın örneği: bir öğretmen tablosunda ve bir öğrenci tablosunda ikisi de `ID` adını taşıyan, ikisi de sayısal birer kolon olsun. Bu iki tablo NATURAL JOIN ile birleştirilirse bu iki `ID` kolonu üzerinden birleştirilir. Ama öğretmen numarası ile öğrenci numarası aynı şey değildir; sonuçta anlamsız eşleşmeler ve beklenmeyen sorgu sonuçları ortaya çıkar. Bu yüzden mümkün olduğunca INNER JOIN kullanmak ya da NATURAL JOIN kullanılıyorsa `USING` gibi ifadelerle hangi kolonun kullanılacağını açıkça belirtmek gerekir.

### 1.3 OUTER JOIN neden gerekir?

**Soru:** OUTER JOIN ile INNER JOIN arasındaki fark nedir, OUTER JOIN'e hangi durumlarda ihtiyaç duyarız? **Cevap:** INNER JOIN, iki tabloda da ortak olan satırlar için sonuç döndürür. Bir taraftaki değerin karşılığı yoksa o satır sonuçta görünmez.

Hoca bunu bölüm (department) ve ders (course) tablolarıyla anlattı. `SELECT * FROM department INNER JOIN course ...` sorgusunda, henüz ders açmamış bölümlerin ID'si course tablosunda eşleşmediği için bu bölümler sonuçta görünmez. Oysa hangi bölümlerin ders açtığını, hangilerinin açmadığını görmek isteyebiliriz. Bu durumda OUTER JOIN kullanılır; OUTER JOIN eşleşmeyen satırları da karşı taraf boş olarak getirir.

### 1.4 LEFT, RIGHT ve FULL OUTER JOIN

Hoca çizim tahtasına iki tablo çizdi (ekrandan, 00:10:00): A tablosu (ID, name ve başka kolonlar) ve B tablosu (A'nın ID'sine karşılık gelen bir ID kolonu ve başka kolonlar). A'da 1, 2, 3, 4, 5 numaralı satırlar var; 1-4'ün B'de karşılığı var, 5'in yok.

**Soru:** A tablosundaki her şeyi görmek istiyorum, B'de karşılığı olabilir ya da olmayabilir. Hangi join'i kullanmalıyım? **Cevap:** LEFT JOIN. Soldaki tablonun bütün satırları istenir; sağda karşılık olmayabilir.

B tarafında A'da olmayan bir 6. satır olduğunu ve B'deki her şeyin istendiğini düşünürsek RIGHT JOIN kullanılır.

**Soru:** Hem sağda hem solda boşluk olabilir, satırın bir tarafta bulunması benim için yeterliyse ne kullanmalıyım? **Cevap:** FULL OUTER JOIN. Bir tarafın boş, diğer tarafın dolu olduğu satırların hepsi gelir.

Bu davranış ders sonrası sqlite3 ile küçük bir örnekte denendi: A'da 1, 2, 5; B'de 1, 2, 6 numaralı satırlar varken LEFT JOIN 1, 2 ve (5, NULL) satırlarını, FULL OUTER JOIN bunlara ek olarak (NULL, 6) satırını döndürür.

## 2. View (Görünüm)

### 2.1 View nedir?

View bir sanal tablodur; mantıksal bir modeldir. View'da fiziksel olarak veri tutulmaz. View, sanal bir ilişki yaratarak fiziksel olarak tutulmayan bir şeyi kavramsal olarak tutmamızı sağlar. Slayttaki tanıma göre, kavramsal modelin parçası olmayan ama kullanıcıya bir "sanal ilişki" olarak gösterilen her ilişkiye view denir (ekrandan, 00:15:00).

### 2.2 Birinci fayda: güvenlik ve veri gizleme

**Soru:** View'a neden ihtiyaç duyarız? **Cevap:** Öğrencilerin verdiği cevaplar güvenlik yönündeydi: tablonun bütün kolonlarını herkese göstermek istemeyebiliriz; örneğin maaş genelde gösterilmez.

Hoca bunu genişletti. Bir çalışan tablosunda kişi hakkında çok fazla bilgi tutulabilir: kimlik numarası, maaşı, medeni durumu, hatta annesinin kızlık soyadı gibi çok özel bilgiler. Bunların herkesin erişimine açık olması doğru değildir; yalnız erişim hakkı olanlar görebilmelidir. Öte yandan çalışan tablosu birçok uygulamada kullanılır: giriş kartı sistemi, prim hesabı, servis planlaması vb. Bütün tabloya bütün uygulamalara izin vermek doğru değildir; yalnız çalışanın adını görmesi gereken bir uygulamada kimlik numarası ve maaşın görünmesi için bir neden yoktur.

View, göstermek istenmeyen kolonları arkada filtreler. Böylece her uygulamaya ya da kişiye yalnız görmesi gerektiği kadar bilgi gösterilir. Bir tablo için birden çok view oluşturulabilir (örneğin operasyon bölümü için bir view, satış uygulamaları için başka bir view, veri analizi sistemleri için başka bir view); her birindeki kolonlar ve koşullar farklı olabilir. Ayrıca bir view tek bir tabloya bağlı olmak zorunda değildir; geçerli herhangi bir SELECT sorgusu gibi join'lerle birden çok tablodan kurulabilir.

Slayttaki örnekte, bir hocanın adını ve bölümünü bilmesi gereken ama maaşını görmemesi gereken bir kişi için şu ilişki yeterlidir (ekrandan, 00:15:00):

```sql
select ID, name, dept_name
from instructor
```

Bu sorgu başka bir tabloyla birleştirilerek hocanın verdiği dersler de gösterilebilir.

### 2.3 İkinci fayda: sorguları sadeleştirme

**Soru:** Başka hangi amaçla view yaratırız? **Cevap:** Bir öğrenci "çok sık yapılan sorgular için" dedi; neden diye sorulunca "aynı sorguları tekrar tekrar yazmamak için" diye ekledi. Hoca bunu doğruladı: view'un ikinci kullanım amacı sorguları sadeleştirmektir.

Hoca bir metin düzenleyicide adım adım karmaşık bir sorgu yazdı: employee tablosu address tablosuyla, department tablosuyla ve yöneticinin bilgisini getirmek için tekrar employee tablosuyla birleştiriliyor, sonuna bir koşul ekleniyor (örneğin 3 numaralı satış bölümü). Bu sorgu bir kez view olarak tanımlanır (ekrandan, 00:25:00):

```sql
create view employeeview as
select ID, name, email
from employee e
    Inner join address a on a.EmpID = e.ID
    Inner join department a on a.EmpID = e.ID
    LEft join employeee e2 On
Where e.departmentID = 3
```

Sonra bu view'dan doğrudan sorgu çekilir, örneğin adı Ahmet olan kişiler:

```sql
select *
from employeeview
where name = 'Ahmet'
```

Bu sorgu, arka planda önce view tanımındaki tablolara gider, verileri oradan çıkarır. Mantık ve çalışma bakımından şu sorgudan hiçbir farkı yoktur (ekrandan, 00:25:00):

```sql
select *
from (select ID, name, email
      from employee e
          Inner join address a on a.EmpID = e.ID
          Inner join department a on a.EmpID = e.ID
          LEft join employeee e2 On ...
      Where e.departmentID = 3)
where name = 'Ahmet'
```

> **Ders sonrası not:** Ekrandaki taslakta address ve department tabloları için aynı `a` takma adı kullanılmış, son join'in koşulu da tamamlanmamıştır. Hoca bunu yalnız yapıyı göstermek için yazdı; çalışan bir sorguda her tabloya ayrı takma ad verilmeli ve join koşulu yazılmalıdır.

Karmaşık sorgular tekrar tekrar elle yazıldığında hata yapma şansı çok yükselir. Aynı sorgunun başka bir versiyonunu başka bir kişi yazıyor olabilir; bu hem başka personelin, başka uygulamaların zaman kaybı demektir hem de farklı tanımların kullanılmasına yol açar. Herkes aynı view'dan gelen sonuçlara göre rapor oluşturursa tutarsızlık oluşmaz. Arkadaki join genellikle bir kez, çoğunlukla veritabanı yöneticileri tarafından oluşturulur; uygulama geliştiricinin altyapıda hangi join'lerin olduğunu bilmesi gerekmez, erişmesi gereken bilgiye view üzerinden erişmesi yeterlidir.

### 2.4 View üzerinden güncelleme yapılabilir mi?

**Soru:** View'lardaki verilerde değişiklik yapabiliyor muyuz? Yapılabiliyorsa tablo etkilenir mi? **Cevap:** Yapılmaz. View fiziksel olarak tutulmadığı için güncelleme anlamlı değildir; view çalıştırıldığında yalnız arkadaki SELECT sorgusu çalıştırılır. Tek özel durum materialized view'dur; orada güncelleme mümkün ama pek anlamlı değildir (bkz. Bölüm 3).

Değişiklik yapmak için arkadaki asıl tabloda (örneğin address, department ya da employee) UPDATE yapmak gerekir. Bunun sonucu olarak, aynı view iki dakika arayla çalıştırıldığında farklı sonuç verebilir: bu arada address tablosuna yeni bir değer gelmiş, bir değer silinmiş ya da değiştirilmiş olabilir. Her view sorgusunda alttaki SELECT yeniden çalışır.

### 2.5 Performans

Arkadaki sorgu sabit olduğu için, view'a çok sayıda sorgu geldiğinde veritabanı bu bilgileri önbelleğe (cache) almaya çalışır; sık yapılan sorgularda sonuç bazen doğrudan önbellekten gelebilir. Bu bir hızlandırıcı etki olabilir, ama normal şartlarda view ile arkadaki sorgu arasında performans farkı yoktur.

View'lar özellikle çok kullanıcılı ve kullanıcılarının farklı hak ve yetkileri olan kurumlarda çok yaygın kullanılır, çünkü hakları view üzerinde tanımlamak daha kolaydır. Ayrıca ana tabloya erişim vermek, çok üst yetkili süper kullanıcılar dışında mantıklı değildir: ana veritabanının elle değil, kullanıcıdan bağımsız olarak uygulamalar tarafından değiştirilmesi istenir.

View oluşturulduktan sonra üzerinde filtreleme (WHERE) yapılabilir, gruplama (GROUP BY) yapılabilir; view'un kendisi de toplanmış (aggregate) bir sonuç olabilir. Slayttaki örnekte `instructor` tablosundan bir `faculty` view'u oluşturuldu.

### 2.6 View'ların başka view'lar üzerine kurulması

View'lar başka view'lar üzerine kurulabilir. Hoca, yalnız İstanbul'daki adresleri gösteren bir adres view'u örneği yazdı (ekrandan, 01:30:00):

```sql
create view vwaddress as
select ID, street, city
from address
where city = 'istanbul'
```

Employee view'u da address tablosu yerine bu view ile birleştirilebilir (`Inner join vwaddress a on a.EmpID = e.ID`). Bağımlılık doğrudan ya da dolaylı (bir view'un başka bir view'a, onun da başka bir view'a başvurması) olabilir. Bir view'un kendine başvurmasına recursive denir; hoca bunun doğru bir yaklaşım olmadığını, onun yerine view üzerinde filtre uygulamanın en mantıklısı olduğunu, filtreleri ayrı view'lar olarak tanımlamanın kafa karıştırıcı olabileceğini söyledi.

Slayttaki örnek (ekrandan, 00:30:00):

```sql
create view physics_fall_2017 as
select course.course_id, sec_id, building, room_number
from course, section
where course.course_id = section.course_id
  and course.dept_name = 'Physics'
  and section.semester = 'Fall'
  and section.year = '2017';

create view physics_fall_2017_watson as
select course_id, room_number
from physics_fall_2017
where building = 'Watson';
```

İlk view 2017 güz dönemindeki fizik derslerini, ikincisi bunlar arasından Watson binasında olanları verir.

### 2.7 View'da kolon adı çakışması

Hoca çizim tahtasında employee tablosunu yöneticisiyle (`e2`) ve bölümle (`d`) birleştiren bir view yazdı; seçilen kolonlar arasında `e.ID`, `e.name`, `e2.ID`, `e2.name` ve bölüm adı vardı. Ardından bu view'un çalışıp çalışmayacağını sordu.

**Soru:** Bu view çalışır mı, ne sorun çıkar, nasıl çözülür? **Cevap:** Öğrenciler kolon adlarının çakıştığını söyledi. Hoca şunu sordu: bir tabloda, örneğin employee tablosunda, iki kez `ID` kolonu kullanılabilir mi? Kullanılamaz; bir tabloda aynı adla yalnız bir kolon olabilir. Bu kural view'lar için de geçerlidir. Burada iki `ID` ve iki `name` vardır; hangisinin kime ait olduğu belli değildir. Çözüm yeniden adlandırmadır: `e2.ID as ManagerID`, `e2.name as ManagerName`. Bundan sonra çakışma kalmaz ve view oluşturulabilir (ekrandan, 00:40:00; tahtadaki yazının yalnız bir kısmı görünüyor).

View oluşturmak sorgu yazmakla aynı mantığı taşır, ama sonuç bir tablo gibi davrandığı için tablonun kuralları burada da geçerlidir.

### 2.8 View expansion

`physics_fall_2017_watson` view'u, `physics_fall_2017` adı yerine o view'un tanım sorgusu konarak şu biçimde de yazılabilir (ekrandan, 00:35:00):

```sql
create view physics_fall_2017_watson as
select course_id, room_number
from (select course.course_id, building, room_number
      from course, section
      where course.course_id = section.course_id
        and course.dept_name = 'Physics'
        and section.semester = 'Fall'
        and section.year = '2017')
where building = 'Watson';
```

View expansion, view adının yerine aynı SELECT sorgusunu koyarak ilişkileri açmaktır. Anlam bakımından view adını kullanmakla arkadaki sorguyu kullanmak arasında hiçbir fark yoktur. Özel bir şey belirtilmezse oluşan view sanal (virtual) view'dur ve yalnız gösterimsel bir etki sağlar.

## 3. Materialized View

### 3.1 Tanım

View'un varsayılan hali sanaldır: arkada veri tutmaz, sorgu asıl tablolarda gerçekleşir, fiziksel bir veri kopyası yoktur. Materialized view'da ise sorguda çekilen veriler fiziksel olarak kopyalanıp saklanır.

Hoca bunu çizim tahtasında gösterdi (ekrandan, 00:45:00): employee view'unun arkasındaki sorgu ID, name, email, city gibi kolonlar üretiyor. Materialized view'da bu sorgunun sonucu veritabanında bir tablo gibi fiziksel olarak durur; aynı verinin birden çok kopyası oluşur. `mview` adlı bir materialized view'dan `select * from mview` ile sorgu yapıldığında yazım bakımından normal view'dan farkı yoktur, ama artık arkadaki employee vb. tablolara gidilmez; yalnız kopyadaki veriler gösterilir.

### 3.2 Neden kullanılır?

Materialized view sorguların performansını artırmak için kullanılır. Aynı sorgu tekrar tekrar çalıştırılmak yerine sonuç bir kez kopyalanır; her ardışık sorguda tablolara gidip join'i çalıştırmak yerine doğrudan bu kopyadan okunur. Join'leri her seferinde çalıştırmak uzun sürdüğü için, özellikle çok sayıda kullanıcının sürekli kullandığı view'larda çok büyük bir hız farkı elde edilir.

**Soru:** Burada neyden taviz veriyoruz, karşılığında ne kazanıyoruz? **Cevap:** Verinin ikinci bir kopyası tutulduğu için saklama alanı maliyeti vardır; karşılığında performans, yani hız kazanılır. Hoca, gerçek dünyada hızın saklama alanından genellikle daha önemli olduğunu, ama çok büyük tablolarda bu kopyaların yönetiminin sorun çıkarabileceğini ekledi.

### 3.3 Yenileme (refresh)

**Soru:** Ana tablo değişince materialized view da değişir mi? **Cevap:** Değiştiği anda değişmez. Materialized view oluşturulurken bir kopyalama işlemi yapılır ve bu kopya periyodik olarak güncellenir.

Hocanın örneği: yenileme "her gün sabah 8'de" olarak tanımlanmış olsun (tahtada "update periodic her gün saat 8:00", ekrandan, 00:45:00). Saat 8'de view önce silinir, sonra SELECT koşuluyla sıfırdan yeniden oluşturulur. Oluşturma 10 dakika sürdüyse view 8:10 civarında kullanıma açılır ve ertesi sabah 8'e kadar herkes bu versiyon üzerinde çalışır. Bu arada employee tablosu değişse, yeni kayıtlar eklense de bunlar ertesi günkü yenilemeye kadar view'a yansımaz. Yenileme saatlik de yapılabilir; o zaman ana tablodaki değişiklikler bir sonraki saatlik yenilemede yansır.

Yenilemenin iki stratejisi vardır:

- Baştan yenileme: materialized view toptan silinip yeniden oluşturulur (complete refresh).
- Artımlı yenileme: yalnız son eklenenler mevcut kayıtların üzerine eklenir. Buna FAST refresh denir; hoca bunun aslında incremental (artımlı) güncelleme demek olduğunu belirtti.

Hoca Oracle belgelerindeki materialized view yenileme sayfasını da açarak bu seçeneklerin parametrelerle verildiğini gösterdi (ekrandan, 01:15:00): yenileme yöntemi incremental olabilir ya da "out of place" olabilir; out-of-place yenileme önce view'u fiziksel olarak düşürüp (drop) yenisini oluşturmak olarak anlatıldı. Genel olarak yenileme yöntemleri fast refresh ve complete refresh'tir; true/false gibi parametrelerle seçilir.

### 3.4 Söz dizimi

Yazım olarak SELECT ifadesi aynıdır. Fark şudur: `CREATE VIEW` yerine `CREATE MATERIALIZED VIEW` yazılır ve ne sıklıkla yenileneceği belirtilir (örneğin her gün, saat 8 gibi; zaman damgası biçiminde de verilebilir). Söz dizimi veritabanından veritabanına farklılık gösterir; PostgreSQL'de ve Oracle'da hafif farklıdır. Genel yapı: `CREATE MATERIALIZED VIEW <ad> AS <SELECT ifadesi>` ve yenileme periyodu.

Materialized view her veritabanında yoktur. Oracle ve birçok sistem destekler. Hoca SQL Server'da materialized view olmadığını, yalnız sanal view oluşturulabildiğini söyledi; SQL Server'da benzer amaçla geçici tablolar (temp table) oluşturulabileceğini ya da sonuçların tablo olarak kaydedilebileceğini, fiziksel olarak tablo oluşturmakla materialized view oluşturmak arasında büyük fark olmadığını, farkın bakım maliyetleri ve kaynak kullanımında olduğunu anlattı.

> **Ders sonrası not:** SQL Server'da `MATERIALIZED VIEW` adlı bir komut yoktur, ama büyük olasılıkla aynı işi gören "indexed view" özelliği vardır: bir view üzerinde unique clustered index oluşturulduğunda view'un sonucu fiziksel olarak saklanır ve tablolar değiştikçe kendiliğinden güncel tutulur.

### 3.5 Materialized view üzerinde değişiklik

**Soru:** Materialized view'a insert yapılabilir mi? **Cevap:** Yapılabilir, ama bu insert ana tabloları etkilemez; yalnız materialized view'daki kopyada olur. INSERT, UPDATE, DELETE işlemleri yalnız materialized view üzerinde gerçekleşir.

Hoca bunun pek anlamlı olmadığını vurguladı: yalnız o anki kopya değişir ve view yenilenince yapılan değişiklikler kaybolur; hiçbir yerde kayıt altında kalmaz. Mantıklı olabileceği tek durum şudur: materialized view başka bir raporda kullanılıyor ve e-posta kolonunda bazı değerlerin NULL geldiği bir hata bulundu. O gün içindeki kullanım için, bir sonraki yenilemeye kadar, değerler view üzerinde düzeltilebilir. Ama bu asıl sorunu çözmez; ana tablodaki sorun aynen sürer ve orada çözülmelidir.

View üzerinde insert yapılırken, eksik bırakılan bir kolon NULL olamıyorsa hata alınır; NULL olabiliyorsa işlem yapılabilir.

### 3.6 View üzerinden güncellemenin belirsizliği

Slayttaki örnek (ekrandan, 01:05:00):

```sql
create view instructor_info as
select ID, name, building
from instructor, department
where instructor.dept_name = department.dept_name;

insert into instructor_info
values ('69987', 'White', 'Taylor');
```

Bu insert'in sorunları:

- Taylor binasında birden çok bölüm varsa yeni hoca hangi bölüme ait olacak?
- Taylor binasında hiç bölüm yoksa ne olacak?

Hoca bunu materialized view bağlamında anlattı: view'a "Taylor" binası ve "White" adlı bir hoca eklendiğinde, department tablosunda böyle bir bina yoksa ilişki bozulur; view'da buna imkan vardır ama asıl tabloda yoktur. Böylece view ile arkadaki tablolar birbirini tam yansıtmayabilir.

Diğer bir sorun: view yalnız tarih (history) bölümündeki hocaları gösteriyor olsun. Bu view'a biyoloji bölümünden bir hoca eklenmesini engelleyen bir şey yoktur, çünkü bu koşul department tablosunda ya da asıl tabloda bir kısıt olarak değil, yalnız view tanımında vardır.

> **Ek bilgi (derste anlatılmadı):** Standart SQL'de view tanımının sonuna `WITH CHECK OPTION` eklenirse, view'un WHERE koşulunu sağlamayan satırların view üzerinden eklenmesi ya da güncellenmesi reddedilir. Kitaptaki bu bölümde de büyük olasılıkla bu seçenek anlatılmaktadır.

### 3.7 Materialized view'un yapısı

Materialized view'larda primary key, foreign key gibi bağlantılar yoktur. Materialized view'da birden çok tablo denormalize edilir: join'ler yapılır ve join sonucu fiziksel bir tabloya kaydedilir. Bu yüzden foreign key ilişkileri ve join'ler materialized view oluşturulmadan önce sağlanmış olmalıdır.

Hoca bunu tahtada çizdi: employee, address ve department tablolarının birleştirilmiş hali materialized view'a kopyalanır. Kaynak tablolarda üçer kolon varsa materialized view çok daha fazla kolondan oluşan geniş bir yapı olabilir. Join yapıldığı için veri tekrarı da olabilir; örneğin aynı bölümdeki hocalar için bölüm kolonu tekrar eder. Amaç performans olduğu için bunda bir sakınca yoktur.

**Soru:** Materialized view ile normal view arasındaki farklar nelerdir? **Cevap:** Sanal view'da veri kaydedilmez; arka plandaki tabloya bir erişim, bir maskeleme ya da filtreleme sağlar. Materialized view da maskeleme ve filtreleme yapabilir, ama veriler fiziksel olarak kopyalanır. Yazımdaki tek fark `MATERIALIZED` sözcüğü ve yenileme periyodudur. Hoca materialized view için "tablo" demenin karışıklık yaratabileceğini, fiziksel tablo ile materialized view'un birbirinden biraz farklı olduğunu belirtti.

## 4. Transaction

### 4.1 Tanım

Bir SQL işlemi (INSERT, UPDATE, DELETE vb.) birden çok parça içeriyorsa, yani bir işlemi başka bir işlem izliyor ve bunların birlikte gerçekleşmesi gerekiyorsa, bunlar tek bir birim olarak düşünülür: ya tamamı gerçekleşir ya da hiçbiri. Bu durumda transaction kullanılır.

Slayttaki tanım (ekrandan, 01:10:00):

- Transaction, sorgu ve/veya güncelleme ifadelerinden oluşan bir dizidir ve bir iş "birimi"dir.
- SQL standardına göre transaction, bir SQL ifadesi çalıştırıldığında örtük olarak başlar.
- Transaction şu ifadelerden biriyle bitmelidir: **Commit work** (yapılan güncellemeler veritabanında kalıcı olur) ya da **Rollback work** (transaction içindeki SQL ifadelerinin yaptığı bütün güncellemeler geri alınır).
- Atomik transaction: ya tamamen yürütülür ya da hiç olmamış gibi geri alınır.
- Eşzamanlı transaction'lardan yalıtım (isolation).

### 4.2 Para transferi örneği

Hoca çizim tahtasında iki hesap tablosu çizdi (ekrandan, 01:20:00 ve 01:25:00). Birinci hesapta 500 TL var; bunun 100 TL'si bakiyesi 0 TL olan ikinci bir hesaba gönderilecek. İşlem iki adımdan oluşur:

```sql
update account
set balance = balance - 100
where ID = 15;

update account
set balance = balance + 100
where ID = 20;
```

Gönderen hesabın ID'si 15, alıcının ID'si 20 olarak alındı. İşlemin iki "bacağı" vardır: önce gönderenin hesabından para çekilir, sonra alıcının hesabına eklenir. İkisi tamamlandığında işlem tamamlanmış olur.

Sorun şudur: gönderenin hesabından para çekildikten sonra bir hata oluşursa (uygulama çöker ya da başka bir aksaklık olursa) 100 TL gönderenin hesabından silinmiş ama alıcının hesabına yatmamış olur; para "havada" kaybolur. Bunun olmaması için iki işlemin atomik, yani tek bir işlem olarak gerçekleşmesi gerekir: ya hep ya hiç. Başarılı olursa gönderenden 100 TL çıkmış ve alıcıya 100 TL girmiş olur; herhangi bir hata olursa gönderenin 100 TL'si geri gelmelidir.

İlişkisel veritabanlarında bunu sağlayan yapı transaction'dır. İki UPDATE tek bir yapı içine alınır: Update 1 ve Update 2 gerçekleşirse transaction **commit** edilir; aksi halde **rollback** edilir. Rollback'te bütün işlemler iptal edilir ve veritabanı önceki haline döner. Transaction'da iki işlem olmak zorunda değildir; örneğin üçüncü bir adımda yapılan işlemler bir log tablosuna yazılabilir. Bütün bu adımlar ya birlikte gerçekleşir ya da hiçbiri gerçekleşmez.

Söz diziminde transaction anahtar sözcüğüyle bir kod bloğu açılır ve bu blok içinde çok sayıda INSERT, DELETE ya da başka işlem yapılabilir.

## 5. Bütünlük Kısıtları

### 5.1 Neden kısıt?

İlişkisel veritabanlarında tablolar oluşturulurken kolonlara, o verinin bütünlüğünü sağlamak için kısıtlar (constraint) uygulanabilir. Hoca para transferi örneğinden devam etti: gönderenin hesabında para yoksa, bakiye sıfırsa 100 TL gönderebilmesi gerekir mi? Gerekmez. Bakiye sıfırdan küçük ya da eşitse o büyüklükte para gönderilememelidir. Bakiye kolonunun belli bir değerin altına düşmemesi denetlenmelidir (tahtada `balance {0 ≤}`, ekrandan, 01:25:00).

Başka örnekler:

- Yaş kolonu 0 ile 150 arasında olmalıdır; yaş kolonuna -100 yazılan bir INSERT kabul edilmemelidir.
- Maaş 10.000'den yüksek ya da 4 dolardan az olmamalıdır.
- Müşteri adı NULL olmamalıdır; telefon numarası ya da kimlik numarası boş olmamalıdır.

Bunlara integrity constraint (bütünlük kısıtı) denir; veritabanındaki verinin yanlışlıkla bozulmasını, kirlenmesini engellerler. Hoca bunu uygulama tarafındaki form doğrulamasına benzetti: bir web sitesinde kullanıcı adının belli şartları sağlaması istenir; kısıtlar da veri tabanı düzeyinde bir doğrulamadır.

En yaygın kısıtlar: NOT NULL, PRIMARY KEY, UNIQUE ve içine herhangi bir şart (birden çok ya da karmaşık şart) yazılabilen CHECK.

### 5.2 NOT NULL ve PRIMARY KEY

NOT NULL en bilinen kısıtlardan biridir. Bir tabloya ad giriliyorsa (personel adı, bölüm adı vb.) adın yanlışlıkla NULL girilmemesini sağlar. Genellikle tablo oluşturulurken belirtilir. Hocanın metin düzenleyicide yazdığı örnek (ekrandan, 01:30:00):

```sql
create table employee(
Id int,
name varchar(50) not null,
dept_id int null,
...
primary key (ID)
unique()
)
```

`name` en fazla 50 karakter olabilir ve NULL olamaz. NOT NULL yazılmazsa (ya da açıkça `null` yazılırsa) kolon NULL alabilir demektir. `primary key (ID)` da bir kısıttır: bu tablonun primary key'inin ID kolonu olduğunu ve değerlerinin tekil (unique) olması gerektiğini söyler.

### 5.3 UNIQUE ve aday anahtarlar

Primary key değeri zaten tekildir, ama başka kolonlar da tekil olabilir; örneğin herkesin adının farklı olması istenebilir. Unique olmak için primary key olmak gerekmez, ama primary key olmak için unique olmak gerekir.

**Soru:** Unique olan ama primary key olmak zorunda olmayan başka hangi anahtarları konuşmuştuk? **Cevap:** Aday anahtar (candidate key). Bir öğrenci foreign key'i de söyledi; hoca foreign key'in de bir anahtar olduğunu ama başka bir tablodaki bir anahtara başvurduğunu belirtti.

**Soru:** Aday anahtarın özellikleri nelerdi? **Cevap:** Unique olmasıdır; aday anahtarın temel şartı budur. Örneğin ID tek başına unique'tir, ID + name de unique'tir, ID + name + department da unique'tir; hepsi süper anahtar olabilir, ama bunlar arasından yalnız biri primary key olarak seçilir ve tercih edilen, daha da küçültülemeyen olanıdır.

Unique bir kolon NULL olabilir, ama primary key NULL olamaz. `UNIQUE` anahtar sözcüğüyle tek bir nitelik ya da birden çok niteliğin birleşimi (composite) belirtilebilir: `unique (ID, name, department)`, `unique (ID, department)` ya da yalnız `unique (department_ID)` gibi.

> **Ders sonrası not:** Hoca unique bir kolonun "bir kez" NULL olabileceğini söyledi. Bu davranış sisteme göre değişir: SQL Server'da unique kolonda yalnız bir NULL'a izin verilir, ama SQL standardında ve büyük olasılıkla PostgreSQL, Oracle ve SQLite'ta birden çok NULL'a izin verilir, çünkü NULL'lar birbirine eşit sayılmaz (SQLite'ta iki NULL satırı eklenebildiği ders sonrası denendi).

### 5.4 CHECK

CHECK daha karmaşık koşullar gerektiğinde kullanılır. Slayttaki section tablosunda primary key birden çok varchar kolondan oluşan bileşik bir anahtardı; kolonlar tek başlarına NULL olabilse de anahtarın bütünü NULL olamaz. Bu tabloda `semester` değerinin dört değerden biri (Fall, Winter, Spring, Summer) ya da NULL olması gerekir; başka bir mevsim yoktur. CHECK ile yanlış bir değer girilmesi engellenir:

```sql
check (semester in ('Fall', 'Winter', 'Spring', 'Summer'))
```

<!-- BELİRSİZ: section tablosunun tam CREATE TABLE ifadesi karelerde yok; yalnız CHECK koşulu altyazıdan kuruldu. -->

CHECK yalnız sabit kategorik değerlerle sınırlı değildir; IN listesi başka bir tablodan da gelebilir, örneğin `semester in (select name from semesters)`. Bu yüzden CHECK daha esnek bir yapı sağlar.

Ders sonrası sqlite3 ile denendiğinde `'Autumn'` değeriyle yapılan ekleme CHECK hatası verdi, NULL ile yapılan ekleme kabul edildi.

Hoca aradan önce daha karmaşık bir CHECK örneğine de değindi: section tablosundaki `time_slot_id` değerinin time_slot tablosundaki ID'lerden biri olması bir alt sorguyla denetlenebilir. Bu durumda dikkat edilmesi gereken şey, time_slot tablosu değişirse bu denetimin de etkilenmesidir; her CHECK işleminde alt sorgu yeniden çalışır. CHECK daha karmaşık koşullar için, diğer kısıtlar daha belirli durumlar için kullanılır.

> **Ek bilgi (derste anlatılmadı):** Alt sorgu içeren CHECK koşulları SQL standardında tanımlıdır, ama büyük olasılıkla çoğu yaygın veritabanı (SQL Server, PostgreSQL, Oracle, SQLite) bunu desteklemez; bu tür koşullar pratikte foreign key ya da trigger ile sağlanır.

## 6. Referential Integrity ve Foreign Key

### 6.1 Tanım

Kısıtların özel bir türü referential integrity'dir (başvuru bütünlüğü): tablolar arasındaki ilişkilerden kaynaklanan bütünlüğü sağlar. Slayttaki tanım (ekrandan, 01:35:00): bir ilişkide belirli nitelikler için görünen bir değerin, başka bir ilişkide de belirli nitelikler için görünmesini garanti eder. Örnek: "Biology", instructor ilişkisindeki bir satırda bölüm adı olarak geçiyorsa department ilişkisinde de "Biology" için bir satır vardır. Genel tanım: A bir nitelik kümesi, R ve S A'yı içeren iki ilişki ve A, S'nin primary key'i olsun. R'de geçen her A değeri S'de de geçiyorsa A, R'nin bir foreign key'idir.

Hoca bunu şöyle açıkladı: instructor ya da course tablosuna biyoloji bölümüyle ilgili bir kayıt eklenirken department tablosunda böyle bir bölüm yoksa, hoca kaydı geçerli ama bağlı olduğu bölüm geçersiz olur. Bu veride tutarsızlık yaratır. Veritabanlarında bunu kendiliğinden sağlayan mekanizmalar vardır: A tablosu B tablosuna foreign key ile bağlıysa karşılığın B'de bulunması zorunludur, aksi halde ekleme ya da silme işleminde hata alınır. Tersi de geçerlidir: department tablosundan biyoloji silinirse, ona başvuran satırlar diğer tabloda kalır ve ilişkiler arasında kopukluk oluşur.

### 6.2 Foreign key yazımı

Foreign key oluşturulduğunda referential integrity de tanımlanmış olur. Foreign key, primary key gibi yazılır; ek olarak bu tablodaki kolonun adı ve neye başvurduğu belirtilir. Örneğin instructor tablosunda `foreign key (dept_name) references department`: department tablosundaki ad ile instructor tablosundaki bölüm adı aynı şeydir ve oradaki değişiklikler burayı etkiler. Başvuru birden çok niteliği kapsayabilir; başvurulan kolon açıkça da yazılabilir.

Aynı tabloda birden çok foreign key olabilir. Hoca tahtada bir instructor tablosu çizdi (ekrandan, 01:40:00): instructor'ın primary key'i ID; `deptID` kolonu department tablosunun primary key'ine başvuran bir foreign key; bir de address tablosunun ID'sine başvuran başka bir foreign key. Aynı anahtar bir tarafta primary key, diğer tarafta foreign key'dir.

Bir öğrenci department name'in kendi tablosunda primary key olup olmadığını sordu; hoca evet, department tablosundaki primary key'e başka bir tablodan başvuruluyorsa o kolonun bizim foreign key'imiz olduğunu söyledi.

### 6.3 Şemaya bakmak

Tablo `SELECT` ile sorgulanırken yalnız kolon adları görünür; hangi kolonun foreign key, hangisinin primary key olduğu görünmez. Bunun için tablonun şemasına (schema), yani CREATE TABLE ayrıntılarına bakmak gerekir. Bu yüzden bazen unutularak silme işlemi yapılır ve ilişkiyle ilgili sorun yaşanır. Örneğin department tablosundan biyoloji yanlışlıkla silinmeye çalışılırsa ve biyolojiye başvuran satırlar varsa hata alınır: önce bu değere başvuran (foreign key olan) tablodaki satırlar silinmeli, başvuru kalmadıktan sonra asıl satır silinmelidir.

**Soru:** Foreign key'in başvurduğu kolonun primary key olması mı gerekir? **Cevap:** Unique olması gerekir; primary key olmak zorunda değildir, bileşik bir değer de olabilir. Ama genel yaklaşım primary key'e başvurmaktır, çünkü sorgular primary key üzerinden yapılır ve primary key aynı zamanda indeks yapısı için kullanıldığı için sorgular hızlı olur. Primary key dışında bir değeri seçmenin çoğu zaman mantığı yoktur.

### 6.4 Cascade işlemleri

Slayttaki örnek (ekrandan, 01:45:00):

```sql
create table course (
    (...
    dept_name varchar(20),
    foreign key (dept_name) references department
        on delete cascade
        on update cascade,
    . . .)
```

Bir referential integrity kısıtı ihlal edildiğinde normal davranış, ihlale yol açan işlemi reddetmektir. Silme ve güncellemede alternatif cascade'dir: `on delete cascade` denirse ana tablodaki silme başvuran tablodaki satırları da siler; `on update cascade` denirse ana tablodaki güncelleme başvuran tablodaki değerleri de günceller. Cascade yerine `set null` ya da `set default` da kullanılabilir.

**Soru:** Silme, başvurulan yerde mi yoksa başvuran yerde mi yapıldığında etkilidir? **Cevap:** Örnekte course tablosu department tablosuna başvuruyor. Ana tablo (department) üzerinde silme yapıldığında course'taki ilgili satırlar silinir; ana tabloda bir ID değeri güncellenirse course'ta da etkisi olur. Yani değişiklik ana tablodan başvuran tabloya yansır.

> **Hocanın vurgusu:** Cascade'i çok kullanmamak gerekir; istemeden yanlışlıkla istemediğiniz satırları silebilirsiniz. Bunun yerine daha dikkatli silmek gerekir: önce başvuran değeri NULL yapmak (kolon NULL olabiliyorsa) ya da varsayılan bir değer vermek, ya da silinmesi mantıklıysa önce başvuran tablodan silip sonra asıl satırı silmek.

### 6.5 Kendine başvuran foreign key: person tablosu

Bir tablo foreign key ile kendine de başvurabilir; hoca bunu self-join'e benzetti. Örneğin bir person tablosunda kişinin anne ve baba bilgileri tutulur; ama anne ve baba da birer kişidir, onlar da bu tabloda yer alır. Slayttaki ve hocanın metin düzenleyiciye kopyaladığı tablo (ekrandan, 01:50:00 ve 02:15:00):

```sql
create table person(
ID char(10),
name char(40),
mother char(10),
father char(10),
primary key ID,
foreign key father references person,
foreign key mother references person
)
```

Primary key ID'dir; father ve mother kolonları person tablosunun kendisine başvuran foreign key'lerdir. Bu foreign key'ler, father ya da mother olarak yazılan kişinin aynı zamanda person tablosunda bulunmasını sağlar.

Yeni bir kişi eklendiğinde annesi ya da babası tabloda değilse hata alınır. Hoca örnekte Ahmet adlı bir kişiyi, anne ve babası Jane ve Joe olacak şekilde eklemeyi düşündü; Jane ve Joe tabloda yoksa INSERT hata verir. Seçenekler (slayttaki maddeler, ekrandan, 01:50:00):

- Önce anne ve babayı eklemek, sonra kişiyi eklemek.
- Anne ve baba kolonları NOT NULL olmadığı için önce bunları NULL bırakarak kişiyi eklemek, bütün kişiler eklendikten sonra UPDATE ile anne ve babayı güncellemek (kolonlar NOT NULL tanımlıysa bu mümkün değildir).
- Kısıt denetimini ertelemek (defer constraint checking).

Hocanın metin düzenleyicide yazdığı NULL'lu ekleme (ekrandan, 02:15:00):

```sql
insert into person (name, mother, father)
value("ahmet", null, null)
```

> **Ders sonrası not:** Hoca, ID primary key olduğu için INSERT'te yazılmasına gerek olmadığını söyledi. Bu tabloda ID `char(10)` olarak tanımlı ve kendiliğinden artan bir kolon değil; primary key değeri NULL olamayacağı için ID büyük olasılıkla açıkça verilmelidir. Ayrıca standart anahtar sözcük `values`'tur ve metin sabitleri çoğu sistemde tek tırnakla yazılır: `insert into person (ID, name, mother, father) values ('1', 'ahmet', null, null)`.

> **Ders sonrası not:** `foreign key father references person` biçiminde başvurulan kolon yazılmadığında başvuru person tablosunun primary key'ine, yani ID'ye yapılır. Dolayısıyla mother ve father kolonları büyük olasılıkla kişinin adını değil ID'sini tutar. Derste örnek adlar üzerinden anlatıldı. Ders sonrası sqlite3 ile denendi: anne-babası olmayan bir kişi ID'leriyle eklenince foreign key hatası alındı; NULL'la ekleyip anne ve babayı ekledikten sonra UPDATE ile ID'leri yazmak sorunsuz çalıştı; başvurulan bir kişiyi silmek ise yine foreign key hatası verdi.

**Soru (bir öğrenci):** Burada ada bakıyoruz; bunların unique olması gerekiyor, değil mi? **Cevap:** Evet, foreign key'in başvurduğu değer unique olmalıdır. Ad tek başına unique değilse (aynı adı taşıyan ama anne-babası farklı kişiler olabilir) unique'lik ad, anne ve baba birleşiminden sağlanır; ad tek başına her kişi için unique ise yalnız ad yeterlidir.

Bir başka soruya cevaben hoca, eklenen anne ve babanın da anne-babasının tabloda olması gerektiğini, bunun kendini tekrar eden (recursive) bir durum yarattığını, pek doğru bir yaklaşım olmasa da mümkün olduğunu söyledi. İki foreign key olduğu için hem mother hem father değerinin bulunması gerekir; tek foreign key olsaydı yalnız onun bulunması gerekirdi.

## 7. Assertion ve Trigger

Assertion, bir kolon ya da nitelik üzerinde sorgu biçiminde daha karmaşık koşullar uygulamaya yarar. Slayttaki tanım (ekrandan, 02:10:00): assertion, veritabanının her zaman sağlamasını istediğimiz bir koşulu ifade eden bir yüklemdir (predicate). Slayttaki örnek kısıtlar:

- student ilişkisindeki her satır için `tot_cred` değeri, öğrencinin başarıyla tamamladığı derslerin kredileri toplamına eşit olmalıdır.
- Bir hoca aynı dönemde aynı zaman diliminde iki farklı derslikte ders veremez.

Hoca buna öğrencinin aynı anda üç farklı derslikte dersinin olmaması, maaşın negatif olmaması ya da belli bir değerden yüksek olması gibi örnekler ekledi. SQL'deki biçim:

```sql
create assertion <assertion-name> check (<predicate>);

create assertion check_salary check (10000 >= ALL (SELECT
    SUM(length) FROM Movies
    GROUP BY studioName ));
```

Slayttaki ikinci örnek, her stüdyonun filmlerinin toplam süresinin belli bir değeri geçmemesini ister.

Hoca, assertion'ın modern veritabanlarında pek kullanılmadığını, çok fazla uygulanmadığını söyledi: hem işlemleri engelleyici (blocking) etkileri olabilir hem de yavaştır. Bunun yerine genellikle trigger kullanılır. Trigger, bir tabloda INSERT, UPDATE ya da DELETE gerçekleştirildiğinde arka planda çalıştırılacak koddur; bir fonksiyon gibi düşünülebilir. Tablodaki bir satır için ekleme ya da bir kolonda güncelleme, silme olduğunda trigger kendiliğinden çalışır. Her olay için ayrı trigger yazılır (silme için bir trigger, ekleme ya da güncelleme için başka bir trigger). Trigger, silinen değeri doğrulamak ya da arka planda log tutmak gibi birçok amaçla kullanılır. Trigger'lar ilerideki derslerde ayrıntılı işlenecek.

## 8. SQL Veri Tipleri ve Kullanıcı Tanımlı Tipler

### 8.1 Tarih ve zaman tipleri

SQL'de integer gibi sayısal tiplerin ve varchar gibi karakter tiplerinin yanında tarih ve zamanla ilgili tipler de vardır:

- `date`: yıl, ay ve gün.
- `time`: saat, dakika ve saniye (saniyenin kesirleri de olabilir).
- `timestamp`: tarih ve saatin birlikte, saniyenin kesirlerine kadar tutulması. Slayttaki örnek büyük olasılıkla `2005-7-27 09:00:30.75` biçimindeydi.
- `interval`: iki zaman arasındaki süre.

<!-- BELİRSİZ: timestamp örneğinin tam değeri altyazıdan kuruldu ("2005, 727, saat 9, 30 saniye ... 751"); veri tipleri slaytı karelerde yok. Hocanın metin düzenleyicisinde yalnız 2005-7-27 görünüyor. -->

Hoca, işlemlerin gerçekleştiği tarihlerin ve özellikle log tablolarındaki izlenen kolonların timestamp olarak tutulmasının avantajlı olduğunu söyledi, çünkü aynı dakika, aynı saniye içinde birden çok işlem gerçekleşebilir. Gün düzeyinde bilgi yeterliyse date tercih edilir, çünkü daha az saklama alanı kaplar; seçim kolonun gerektirdiği ayrıntıya bağlıdır.

Tarihin veritabanında saklanma biçimi tektir, ama SELECT sırasında farklı biçimde gösterilebilir. Örneğin yıl-ay-gün biçiminde saklanan bir gönderim tarihi (shipdate) gün/ay/yıl biçiminde gösterilmek istenirse dönüştürme fonksiyonuyla biçimlendirilir. Hocanın metin düzenleyicide yazdığı taslak (ekrandan, 02:15:00):

```sql
select date("dd/mm/year", shipdate) as shipdate
```

Dönüştürme fonksiyonları ve biçim kodları sisteme göre değişir; SQL Server'da ve Oracle'da farklıdır, biçimlerin numaraları da vardır.

> **Ek bilgi (derste anlatılmadı):** Ekrandaki ifade genel bir taslaktır. Örneğin SQL Server'da `CONVERT(varchar, shipdate, 103)` (103 = gg/aa/yyyy biçim kodu) ya da `FORMAT(shipdate, 'dd/MM/yyyy')`, Oracle ve PostgreSQL'de `TO_CHAR(shipdate, 'DD/MM/YYYY')` kullanılır.

### 8.2 Büyük nesneler: CLOB ve BLOB

Bazen çok büyük verileri nesne olarak tutmak gerekir. Örneğin bir web sitesinin HTML'inin kendisi, 2 MB'lık bir metin, uzun sosyal medya gönderileri ya da başka uzun metinler CLOB (character large object) olarak tutulabilir; bunlar yapısal olmayan biçimde tutulur ve karakter sayısı çok uzundur. Video, resim (JPEG, PNG), ses ya da müzik gibi nesneler ise ikili (binary) biçime dönüştürülüp BLOB (binary large object) tipindeki bir kolonda tutulabilir. Bu nesnelerin içeriği üzerinde sorgu yapmak mümkün değildir. İçinde çok sayıda metin ayrıntısı olan bir dosya da CLOB olarak tutulabilir.

### 8.3 Kullanıcı tanımlı tipler

Kullanıcı kendi veri tipini de tanımlayabilir; buna user-defined type denir. Hoca bunu nesne yönelimli programlamada bir sınıf oluşturmaya benzetti. Slayttaki örnek (ekrandan, 02:20:00):

```sql
create type Dollars as numeric (12,2) final

create table department
(dept_name varchar (20),
 building varchar (15),
 budget Dollars);
```

Bütçe normalde numeric olarak tutulurdu; burada onun yerine Dollars tipi kullanılıyor ve bu tipteki değerler arka planda numeric şartını sağlamalıdır.

`final` sözcüğünün amacı, bu tipten başka bir tipin türetilmemesidir. `final` denmezse, örneğin Dollars'tan türetilmiş bir "cent" tipi oluşturulabilirdi; hoca bunu kalıtım (inheritance) mantığına benzetti. `final` ile Dollars başka bir tip oluşturmakta kullanılamaz.

### 8.4 Domain

Domain de kullanıcı tanımlı bir veri tipine benzer; tek farkı kısıt (NOT NULL, değer aralığı vb.) eklenebilmesidir. Örneğin Dollars'ın negatif olamaması gibi bir şart istenseydi domain oluşturmak gerekirdi. Hocanın anlattığı örnekte `degree_level` adlı, 10 karakterlik varchar tipinde bir domain tanımlanır ve değerinin Bachelors, Masters ya da Doctorate olması zorunlu tutulur; NOT NULL da eklenebilir.

<!-- BELİRSİZ: domain örneğinin tam söz dizimi karelerde yok; altyazıdan "Relevel ... 10 birimlik barcar ... Bachelor, Master ya da Doctora" diye kuruldu. -->

Hoca NOT NULL'un domain'de tanımlanmasına çok gerek olmadığını, tablo oluşturulurken de verilebileceğini, bazı veritabanlarının domain'i desteklemediğini ama hepsinde kullanıcı tanımlı tip olduğunu söyledi.

## 9. SQL'de İndeks Tanımı

Tablo oluştururken çoğu kez indeks yapıları da oluşturulur, çünkü indeksler sorguların hızlı gelmesini sağlar. İndekslerin türleri, amaçları ve performans farkları ileride ayrıntılı işlenecek; bu derste yalnız nasıl oluşturulduğu gösterildi. İndeks, tablo oluşturur gibi ama `index` komutuyla oluşturulur: `create index <indeks adı> on <tablo>(<kolonlar>)`; örneğin `idx_employee` gibi bir ad verilir ve hangi tablo ve kolonlar üzerine kurulacağı yazılır.

Slayttaki örnekte student tablosu şöyleydi (altyazıdan): ID, 20 karakterlik ve NULL olamayan name, karakter tipinde bölüm adı, varsayılan değeri 0 olan sayısal toplam kredi; primary key ID. ID üzerinde çok sorgu yapıldığını varsayarak onun için bir indeks oluşturulur:

```sql
create index studentID_index on student(ID)
```

<!-- BELİRSİZ: indeks slaytı karelerde yok; tablo tanımı ve indeks ifadesi altyazıdan kuruldu. -->

Hoca, aslında primary key tanımlanınca bu kolon üzerinde kendiliğinden bir kümelenmiş (clustered) indeks oluşturulduğunu, örneğin yalnız mantığı göstermek için verildiğini belirtti. İndeks birden çok kolon (örneğin ID + name) üzerine de kurulabilir. İndeks oluşturulduktan sonra ID kolonunu kullanan sorguların performansı ciddi ölçüde artar.

## 10. Yetkilendirme (Authorization)

### 10.1 Yetki türleri

Yetkilendirme genellikle veritabanı yöneticilerinin (database administrator, DBA) işidir. Uygulama geliştirici bu hakları kullanır ama kendisi hak vermez; ne tür hakların verileceği yöneticilerin kararıdır. Yetkiler tablo, view, prosedür, trigger, şema ya da veritabanının kendisi gibi bütün kaynaklar için ayrıntılı olarak uygulanabilir.

Slayttaki yetki türleri (ekrandan, 02:25:00):

- **Read:** veriyi okumaya izin verir, değiştirmeye izin vermez. Kullanıcı yalnız SELECT çalıştırabilir.
- **Insert:** yeni veri eklemeye izin verir, mevcut veriyi değiştirmeye izin vermez.
- **Update:** değiştirmeye izin verir, silmeye izin vermez.
- **Delete:** veri silmeye izin verir.

Bu yetkilerin her birine privilege denir. Kullanıcıya bunların hepsi, hiçbiri ya da bir bileşimi, bir ilişki ya da view gibi veritabanı parçaları üzerinde verilebilir.

Şema düzeyindeki yetkiler de vardır: indeks oluşturma ve silme yetkisi, kaynak (tablo, view, prosedür) oluşturma yetkisi, bir niteliği ekleme, silme ya da değiştirme (alteration) yetkisi ve tabloyu tümüyle düşürme (drop) yetkisi.

### 10.2 GRANT

Genel yapı (ekrandan, 02:30:00):

```sql
grant <privilege list> on <relation or view> to <user list>
```

Yetki listesi DELETE, SELECT, UPDATE, INSERT gibi yetkilerdir; `on`'dan sonra yetkinin hangi tablo ya da view üzerinde verildiği, `to`'dan sonra kime verildiği yazılır. Kullanıcı listesi bir kullanıcı kimliği, bütün geçerli kullanıcılara yetki veren `public` ya da bir rol olabilir. Hoca `public`'in genellikle tercih edilmediğini, onun yerine kullanıcı ya da rol adı verildiğini söyledi.

Kullanıcıya doğrudan yetki vermek, örneğin bir mobil uygulamadan veritabanına bağlanan "mobil kullanıcı" gibi özel bir uygulama kullanıcısına özgü hakları tanımlamak için mantıklıdır. Bunun dışında rollere yetki vermek daha uygundur: veri analistlerinin, veritabanı geliştiricilerinin, üst yöneticilerin ayrı rolleri ve belli tablolara erişimleri olur.

Örnek:

```sql
grant select on department to Amit, Satoshi
```

Bu ifade department tablosunda okuma (SELECT) yetkisini Amit ve Satoshi adlı iki kullanıcıya verir. Slayttaki önemli iki kural:

- Bir view üzerinde yetki vermek, alttaki ilişkiler üzerinde yetki vermek anlamına gelmez. department bir view olsaydı yetki yalnız view'a verilmiş olurdu, altındaki tablolara verilmezdi.
- Yetkiyi veren kişinin o öğe üzerinde bu yetkiye zaten sahip olması (ya da veritabanı yöneticisi olması) gerekir.

Birden çok kullanıcıya aynı anda yetki verilebilir (`grant select on <ilişki> to kullanıcı1, kullanıcı2, kullanıcı3`). INSERT, UPDATE gibi yetkiler aynı biçimde verilir; `grant all on ...` bütün yetkileri verir.

### 10.3 REVOKE

Kullanıcıdan yetkiyi geri almak da mümkündür. Örneğin bir şirkette çalışan ve veritabanına erişimi olan bir kişi şirketten ayrıldığında artık o tabloya ya da view'a erişimi olmamalıdır. Bunun için `revoke` kullanılır:

```sql
revoke select on student from kullanıcı1, kullanıcı2, kullanıcı3
```

Hangi yetkinin, hangi kaynak üzerinde ve kimden alınacağı yazılır; GRANT'tan farkı `to` yerine `from` kullanılmasıdır. Burada da `public` yazılabilir.

### 10.4 Roller

Yetki verme ve alma işlemleri kişi bazında değil, rol ya da yetki seviyesi bazında yapılmalıdır. Örneğin bir okulda instructor'lar, student'lar ve admin'ler ayrı rollerdir; hocalar ders içeriğini değiştirebilirken öğrenciler değiştirememelidir. Öğrencinin SELECT hakkı, hocanın ayrıca UPDATE ve INSERT hakkı olur.

İşlem sırası: önce `create role <rol adı>` ile rol oluşturulur, sonra `grant <rol> to <kullanıcılar>` ile rol kullanıcılara atanır, sonra role SELECT, UPDATE, INSERT gibi yetkiler verilir. Böylece o role sahip bütün kullanıcılara bütün bu yetkiler kendiliğinden atanmış olur; yetkiler tek tek kullanıcılara verilmez.

Slayttaki örnek (ekrandan, 02:35:00):

```sql
create role instructor;
grant instructor to Amit;
grant select on takes to instructor;

create role teaching_assistant
grant teaching_assistant to instructor;
-- instructor, teaching_assistant'ın bütün yetkilerini devralır

create role dean;
grant instructor to dean;
grant dean to Satoshi;
```

Roller kullanıcılara verilebildiği gibi başka rollere de verilebilir: teaching_assistant rolü instructor'a verildiğinde instructor, teaching_assistant'ın bütün yetkilerini devralır. Böylece yetkiler zincir biçiminde atanabilir: dean (dekan) aynı zamanda instructor olduğu için instructor yetkilerine de sahip olmalıdır; `grant instructor to dean` ile bu sağlanır ve Satoshi dean rolüne atanınca instructor'ın haklarına da sahip olur.

**Soru:** Rolleri uygulama kullanıcılarından çok DB yöneticilerinin kendi arasında düzenlemesi gerekmez mi? **Cevap:** Evet, bunu son kullanıcılar değil veritabanı yöneticileri yapar. Buradaki "veritabanı kullanıcısı" son müşteriler değil; veritabanına erişen uygulamalar ya da şirkette çalışan ve tablolara erişim hakkı olan gerçek kişilerdir (örneğin geliştiriciler). Bu yetkileri veritabanını oluşturan yöneticiler verir; kullanıcı talepte bulunur, yöneticiler ona bir rol atar. Örneğin veritabanında bir "developer" rolü varsa işe yeni giren bir geliştirici bu role atanır ve rolün bütün yetkilerini alır.

Roller ve rollerin sahipleri tablo üzerinde değil, veritabanı yönetim sisteminin ayrı bir yönetim kısmında görülür; sorgularla da yönetilebilir.

### 10.5 View'lar üzerinde yetki

View'lar yetki bakımından tablolardan farklı değildir. Örneğin jeoloji bölümü için bir view oluşturulup kullanıcılara bu view üzerinde SELECT yetkisi verilebilir. Kullanıcıların instructor tablosuna yetkisi olmasa bile view'a yetkileri varsa view'u görebilirler; ayrıca instructor tablosuna yetki vermek gerekmez.

Ancak view'u oluşturan kişiyle view'u kullanan kişi arasında fark vardır: view'u oluşturan kişinin instructor tablosu üzerinde yetkisi yoksa view'u oluşturamaz. View'a yetki verilen bir kullanıcının alttaki tabloya yetkisi olması gerekmez, ama view'u oluşturan ve yetkiyi veren kişinin alttaki tabloya yetkisi olmalıdır.

### 10.6 Yetkinin devredilmesi: WITH GRANT OPTION

Yetki başkasına devredilebilir:

```sql
grant select on department to Amit with grant option
```

`with grant option` denince Amit kendisi de bu yetkiyi başkalarına verebilir. Yetki geri alınırken `cascade` kullanılırsa Amit'in yetki verdiği kişilerin SELECT yetkisi de silinir; `restrict` kullanılırsa yalnız Amit'in kendisi yetkiden mahrum edilir, onun verdiği yetkiler silinmez. Hoca slaytta ayrıca References adlı bir yetkinin de bulunduğunu belirtti.

> **Ek bilgi (derste anlatılmadı):** `references` yetkisi, kullanıcının bir tabloya başvuran foreign key tanımlayabilmesini sağlar. Foreign key, başvurulan tablodaki silme ve güncellemeleri kısıtlayabildiği için bu yetki ayrıca verilir.

### 10.7 SQL Server'da roller

Ders sonunda hoca SQL Server'ın yönetim arayüzünde bir veritabanını açarak gösterdi: veritabanının altında tablolar ve Security bölümü bulunur. Security altında veritabanına erişen kullanıcılar (örneğin dbo, INFORMATION_SCHEMA, guest) ve veritabanı rolleri (db_accessadmin, db_datawriter, db_datareader vb.) vardır. Örneğin guest kullanıcısına db_datareader rolü atanırsa bu rolün bütün yetkileri guest'e geçer. Roller ve yetkiler yalnız veritabanı düzeyinde değil, bütün sunucu (instance) düzeyinde de (server rolleri, sunucu girişleri) verilebilir; bütün veritabanlarına erişim hakkı genellikle yalnız sistem yöneticilerinde olur ve yetkiler genellikle veritabanı düzeyinde verilir. Bu arayüzler SQL Server ile Oracle arasında farklıdır, ama genel mantık aynıdır.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:02:12): NATURAL JOIN ile INNER JOIN arasındaki temel farklar nelerdir?

> **Cevap (derste verildi):** INNER JOIN'de eşleşme koşulu `ON` ile açıkça yazılır; NATURAL JOIN aynı adlı kolonlar üzerinden kendiliğinden eşleştirir. `SELECT *` sonucunda INNER JOIN eşleşme kolonunu iki kez, NATURAL JOIN bir kez gösterir.

**Soru 2** (derste sözlü, 00:04:48): NATURAL JOIN kullanmanın riski nedir?

> **Cevap (derste verildi):** Yanlış eşleştirme. Yalnız kolon adına (ve tip uyumuna) baktığı için öğretmen `ID`'si ile öğrenci `ID`'si gibi anlamca farklı kolonları birleştirebilir.

**Soru 3** (derste sözlü, 00:10:56; tahta ekrandan, 00:10:00): A tablosunda 1-5, B tablosunda 1-4 numaralı satırlar var. A'daki bütün satırları görmek istiyorum, B'de karşılık olmayabilir. Hangi join'i kullanmalıyım? Her iki tarafta da boşluk olabiliyorsa ne kullanmalıyım?

> **Cevap (derste verildi):** İlk durumda LEFT JOIN; 5 numaralı satır B kolonları NULL olarak gelir. B'nin bütün satırları isteniyorsa RIGHT JOIN, satırın herhangi bir tarafta bulunması yeterliyse FULL OUTER JOIN.

**Soru 4** (derste sözlü, 00:13:26): View'a neden ihtiyaç duyarız, ne gibi katkıları vardır?

> **Cevap (derste verildi):** (1) Güvenlik ve gizlilik: maaş, kimlik numarası gibi kolonları gizleyip her uygulamaya gerektiği kadar veri göstermek. (2) Karmaşık ve sık kullanılan sorguları sadeleştirmek; hatayı, zaman kaybını ve tanım tutarsızlığını azaltmak.

**Soru 5** (derste sözlü, 00:31:21): employee tablosunu yöneticisi (`e2`) ve bölümle birleştiren, `e.ID, e.name, e2.ID, e2.name, d.department_Name` kolonlarını seçen bir view tanımı çalışır mı? Sorun varsa nasıl çözülür?

> **Cevap (derste verildi):** Çalışmaz; bir view'da tablodaki gibi aynı ad yalnız bir kolona verilebilir, burada iki `ID` ve iki `name` vardır. Çözüm yeniden adlandırmadır: `e2.ID as ManagerID, e2.name as ManagerName`.

**Soru 6** (derste sözlü, 00:41:20): Materialized view kullanırken neyden taviz verip ne kazanıyoruz?

> **Cevap (derste verildi):** Verinin ikinci bir kopyası tutulduğu için saklama alanından taviz verilir; karşılığında sorgu performansı, yani hız kazanılır.

**Soru 7** (ekrandan, 01:05:00): `instructor_info` view'u `select ID, name, building from instructor, department where instructor.dept_name = department.dept_name` olarak tanımlıdır. `insert into instructor_info values ('69987', 'White', 'Taylor');` ifadesi hangi sorunlara yol açar?

> **Cevap (derste verildi):** Taylor binasında birden çok bölüm varsa yeni hocanın hangi bölüme ait olacağı belirsizdir; Taylor binasında hiç bölüm yoksa ekleme asıl tablolarla tutarsız bir ilişki yaratır.

**Soru 8** (derste sözlü, 01:24:10): Bakiyesi sıfır olan bir hesaptan 100 TL gönderilebilmeli midir? Bunu veritabanında nasıl önleriz?

> **Cevap (derste verildi):** Gönderilmemelidir. Bakiye kolonunun belli bir değerin altına düşmemesini denetleyen bir bütünlük kısıtı (örneğin CHECK) kullanılır; ayrıca transfer transaction içinde yapılır.

**Soru 9** (derste sözlü, 01:29:18): Unique olan ama primary key olmak zorunda olmayan anahtarlar hangileridir? Aday anahtarın temel özelliği nedir?

> **Cevap (derste verildi):** Aday anahtarlar. Temel özellikleri unique olmalarıdır; birden çok aday anahtar olabilir ve primary key bunlar arasından, daha da küçültülemeyen biri olarak seçilir.

**Soru 10** (ekrandan, 01:50:00): `person(ID, name, mother, father)` tablosunda mother ve father, person tablosuna başvuran foreign key'lerdir. Bir kişiyi kısıt ihlali olmadan nasıl ekleriz?

> **Cevap (derste verildi):** Önce anne ve babayı eklemek; ya da mother ve father kolonları NOT NULL değilse önce NULL ile ekleyip bütün kişiler eklendikten sonra güncellemek; ya da kısıt denetimini ertelemek.

## Dersin Toparlaması

Bu derste "Intermediate SQL" konusu baştan sona işlendi. Join türlerinin tekrarıyla başlandı: NATURAL JOIN'in kendiliğinden eşleştirmesinin rahatlığı ve yanlış eşleştirme riski, INNER JOIN'in açık koşulu, OUTER JOIN'in (LEFT, RIGHT, FULL) karşılığı olmayan satırları da getirmesi. Ardından view'lar ayrıntılı ele alındı: fiziksel veri tutmayan bir sanal ilişki olarak view'un gizlilik ve sorgu sadeleştirme amaçları, view'ların birbirine dayanması, view expansion ve kolon adı çakışması kuralı. Materialized view'da sonucun fiziksel olarak kopyalanması, bunun saklama alanı karşılığında hız kazandırması, periyodik (complete ya da fast/incremental) yenileme ve view üzerinden yapılan güncellemelerin sorunları tartışıldı.

Dersin ikinci yarısında transaction'ın "ya hep ya hiç" ilkesi para transferi örneğiyle, bütünlük kısıtları (NOT NULL, PRIMARY KEY, UNIQUE, CHECK) ve foreign key ile sağlanan referential integrity cascade seçenekleri ve kendine başvuran person tablosu örneğiyle anlatıldı. Assertion'ın pratikte yerini trigger'a bıraktığı, SQL'in tarih-zaman tipleri, CLOB/BLOB, kullanıcı tanımlı tipler ve domain'ler, indeks oluşturma ve son olarak GRANT/REVOKE, roller, rol zincirleri ve `with grant option` ile yetkilendirme işlendi. İndeks yapıları ve trigger'lar ilerideki derslerde ayrıntılı ele alınacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
