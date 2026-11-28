# Ders 4 Çalışma Özeti

## Genel Konular

- Ders kaynağı ve kapsam
  - Ders, "Database System Concepts" (7. baskı) kitabının 5. bölümü olan "Advanced SQL" slaytlarıyla işlendi (ekrandan, 00:10:00). Anlatımı bir çizim tahtası ve SQL Server Management Studio üzerinde gösterilen bir saklı yordam örneği tamamladı.
  - İşlenen konular: programlama dillerinden SQL'e erişim (JDBC, ODBC, SQLJ, gömülü SQL), kullanıcı tanımlı fonksiyonlar, saklı yordamlar (stored procedure) ve tetikleyiciler (trigger). Özyinelemeli sorgular ve sıralama (ranking) gibi ileri özellikler bu derste işlenmedi, yalnız adı geçti.
- SQL neden tek başına yetmez: host dil ihtiyacı
  - SQL bildirimsel (declarative) bir dildir. Java, C, C++, C# gibi prosedürel dillerde olan döngüler, değişken üzerinde adım adım işlem, kullanıcıdan girdi alma, ekrana yazdırma, grafik arayüz gibi yetenekler SQL'de yoktur.
  - Bu yüzden SQL, genel amaçlı bir programlama dilinin (host dil) içinden kullanılır. Host dilin veritabanına erişmesinin iki ana yolu vardır:
    - Sürücü (driver) ya da bağdaştırıcı (adaptör) aracılığıyla bir API kullanmak: JDBC (Java), ODBC (dil bağımsız standart).
    - Gömülü SQL (embedded SQL): SQL ifadeleri host dilin içine yazılır; derleme sırasında fonksiyon çağrılarına dönüştürülür.
- Uygulama mimarisi (çizim tahtası, ekrandan, 00:15:00 ve 01:35:00)
  - İstemciler (client) HTTP üzerinden uygulama sunucusuna (app server) bağlanır; birden çok uygulama sunucusu olabilir.
  - Uygulama sunucusunda bir web uygulaması (arayüz/UI, controller, model) çalışır. Örnek: formdaki bilgilerle `save(person)` çağrılır ve sonuç veritabanındaki `Person` tablosuna yazılmalıdır.
  - Veritabanı genellikle ayrı bir DB sunucusundadır (Oracle, MySQL, IBM, SQL Server vb.). İki taraf farklı teknolojiler ve farklı fiziksel sunucular olabilir; bunları konuşturan katman sürücüdür (JDBC/ODBC). Sürücü bir bağlantı (connection) açar, ifade (statement) oluşturur ve çalıştırır (execute).
  - Bağlantı için gereken bilgiler: sunucunun IP ya da web adresi, veritabanı örneği (instance) ya da adı, kullanıcı adı ve parola.
- JDBC (ekrandan, 00:20:00)
  - JDBC, SQL destekleyen veritabanlarıyla iletişim için bir Java API'sidir. Sorgulama, güncelleme, sonuç alma ve metadata sorgulama işlevleri sağlar.
  - İletişim modeli: bağlantı aç, `Statement` nesnesi oluştur, sorguları bu nesneyle gönderip sonuçları al, hataları istisna (exception) mekanizmasıyla yönet.
  - Eski Java/JDBC sürümleri için kod iskeleti (ekrandan, 00:25:00): `Class.forName("oracle.jdbc.driver.OracleDriver")` ile sürücü sınıfı yüklenir, `DriverManager.getConnection("jdbc:oracle:thin:@db.yale.edu:2000:univdb", userid, passwd)` ile bağlanılır, `conn.createStatement()` ile ifade oluşturulur, iş bitince `stmt.close()` ve `conn.close()` çağrılır, `SQLException` yakalanır. Slayttaki nota göre `Class.forName` JDBC 4'ten itibaren gerekmez; Java 7'den itibaren try-with-resources sözdizimi tercih edilir.
  - Güncelleme: `stmt.executeUpdate("insert into instructor values('77987', 'Kim', 'Physics', 98000)")` (ekrandan, 00:30:00).
  - Sorgu ve sonuç: `executeQuery` bir `ResultSet` döndürür; `while (rset.next())` ile satır satır dolaşılır, değerler `getString("dept_name")` gibi kolon adıyla ya da `getFloat(2)` gibi kolon sırasıyla alınır (ekrandan, 00:35:00).
  - Boş (null) değerler ayrıca ele alınmalıdır.
- `Statement` ile string birleştirerek sorgu yazmanın sorunları
  - Sorgu metnindeki hatalar (örneğin fazladan tırnak) derleme zamanında değil, çalışma zamanında ortaya çıkar.
  - SQL injection riski doğar.
  - Her çağrıda sorgu yeniden kurulduğu için önbellekleme ve optimizasyon yapılamaz; performans düşer.
- SQL injection (ekrandan, 00:40:00)
  - Sorgu `"select * from instructor where name = '" + name + "'"` biçiminde kuruluyorsa ve kullanıcı ad yerine `X' or 'Y' = 'Y` girerse sorgu `select * from instructor where name = 'X' or 'Y' = 'Y'` olur; koşul her zaman doğru olduğu için tablonun tamamı döner.
  - Kullanıcı `X'; update instructor set salary = salary + 10000; --` da girebilir; böylece ikinci bir komut çalıştırılır. Tablo silme, veritabanını silme, yetki değiştirme de mümkün olur.
  - Prepared statement girdiyi kaçışlı (escape) hale getirir: `"select * from instructor where name = 'X\' or \'Y\' = \'Y'"`. Kural: kullanıcı girdisi her zaman parametre olarak verilmelidir.
- Prepared statement
  - Sorgu `?` yer tutucularıyla bir kez yazılır, parametreler tip belirten `setString`, `setInt` gibi metotlarla verilir. <!-- BELİRSİZ: slayttaki PreparedStatement kod örneğinin tam metni karelerde okunamadı (yalnız küçük önizleme görünüyor). -->
  - Avantajları: SQL injection'a karşı koruma (beklenen tipte olmayan girdi hata verir), sorgunun sabit kalması nedeniyle daha iyi performans, yazım kolaylığı.
- Metadata (ekrandan, 00:45:00 ve 01:05:00)
  - `ResultSetMetaData rsmd = rs.getMetaData()` ile sonuç kümesinin kolon sayısı (`getColumnCount`), kolon adları (`getColumnName`) ve tipleri (`getColumnTypeName`) alınır.
  - `DatabaseMetaData dmd = connection.getMetaData()` ile veritabanı hakkında bilgi alınır: `getColumns` (katalog, şema, tablo, kolon desenleri; `%` "hepsi" anlamında), tablo listesi ve `getPrimaryKeys("", "", tableName)`. `KEY_SEQ`, birincil anahtar birden çok nitelikten oluşuyorsa niteliğin anahtar içindeki sırasını verir.
  - Kullanım amacı: veritabanı şeması uygulamadan habersiz değişirse (kolon silinmesi, yeni kolon) ortaya çıkan kırılmaları önceden yakalamak. Bunun da her işlemde ek bağlantı maliyeti vardır.
- JDBC'de transaction denetimi (ekrandan, 01:10:00)
  - Varsayılan olarak her SQL ifadesi ayrı bir transaction olarak otomatik commit edilir; çok güncellemeli işlemler için bu kötü bir fikirdir.
  - `conn.setAutoCommit(false)` ile otomatik commit kapatılır; sonra `conn.commit()` ya da `conn.rollback()` açıkça çağrılır. `conn.setAutoCommit(true)` otomatik commit'i yeniden açar.
- Diğer JDBC özellikleri (ekrandan, 01:15:00)
  - Fonksiyon ve yordam çağırma: `conn.prepareCall("{? = call some function(?)}")` ve `conn.prepareCall("{call some procedure(?,?)}")` ile `CallableStatement`.
  - Büyük nesneler: `getBlob()` ve `getClob()`, `getString()` gibi çalışır ama `Blob` ve `Clob` nesneleri döndürür; veri `getBytes()` ile alınır; büyük nesneyi güncellemek için `blob.setBlob(int parameterIndex, InputStream inputStream)` ile bir akış bağlanır.
  - BLOB ikili (binary) veri içindir: resim, ses, video. CLOB uzun metin içindir: kullanıcı yorumları, gönderiler, web sayfası içeriği.
- SQLJ (ekrandan, 01:20:00)
  - JDBC aşırı dinamiktir, hataları derleyici yakalayamaz. SQLJ, Java'ya gömülü SQL'dir; `#sql iterator deptInfoIter (String dept name, int avgSal);` ile bir yineleyici tanımlanır, `#sql iter = { select dept_name, avg(salary) from instructor group by dept name };` ile sorgu tırnak içine alınmadan yazılır, `iter.next()` ile dolaşılır, sonunda `iter.close()` çağrılır. Kolon adı ya da sözdizimi hatası derleme sırasında yakalanır.
- ODBC
  - Open Database Connectivity: birçok programlama dilinden veritabanına erişim için tanımlanmış standart bir API. JDBC'ye çok benzer: bağlantı aç, sorgu/güncelleme gönder, sonuçları al.
  - Özellikle Microsoft araçlarında (C#, Visual C++) yaygındır; ama SQL Server, MySQL, Oracle gibi birçok veritabanının ODBC sürücüsü vardır. Excel, Access ve raporlama araçları da veritabanına arka planda ODBC ile bağlanır.
- Gömülü SQL (ekrandan, 01:25:00 ve 01:30:00)
  - SQL standardı SQL'in C, C++, Java, Fortran, PL/1 gibi dillere gömülmesini tanımlar. SQL'in gömüldüğü dile host dil, izin verilen SQL yapılarına gömülü SQL denir. Temel biçim System R'ın PL/1'e gömülmesinden gelir.
  - `EXEC SQL <embedded SQL statement>;` ifadesi ön işleyiciye (preprocessor) gömülü SQL isteğini bildirir. COBOL'da noktalı virgül yerine `END-EXEC` kullanılır; Java'da `# SQL { .... };` biçimi kullanılır.
  - Bağlantı `EXEC SQL CONNECT TO ...` ile kurulur; host değişkenler `declare section` içinde tanımlanır ve SQL içinde başına `:` konarak kullanılır.
  - İmleç (cursor): `declare c cursor for <sorgu>` ile tanımlanır, `open` ile sorgu çalıştırılır, `fetch` ile satırlar tek tek host değişkenlere alınır, `close` ile kapatılır. Veri bittiğinde SQLCA içindeki SQLSTATE `'02000'` olur. `close` sorgu sonucunu tutan geçici ilişkiyi siler. <!-- BELİRSİZ: imleç tanımı ve fetch slaytlarının kod metni karelerde yakalanmadı; anlatım altyazıdan. -->
  - İmleç üzerinden güncelleme de yapılabilir: hocanın örneğinde dönen her eğitmenin maaşı 1000 artırılıyor.
  - C# tarafında LINQ ve Entity Framework gibi araçlar da benzer biçimde sorguların derleme zamanında denetlenmesini sağlar.
- Fonksiyonlar ve yordamlar
  - Kullanıcı tanımlı fonksiyon ve yordamlar, sık kullanılan iş mantığını veritabanında bir nesne olarak tutar. Uygulama yalnız adını ve parametrelerini gönderir.
  - Fonksiyon girdi alır ve her zaman bir değer döndürür. Yordamın değer döndürmesi zorunlu değildir; birden çok işlem yapabilir.
  - Mantık tek yerde tutulduğu için bir değişiklik (örneğin not ortalaması hesaplama yönteminin değişmesi) tek noktadan yapılır; kod tekrarı ve uygulamalar arası tutarsızlık önlenir.
- SQL fonksiyonu örneği (ekrandan, 01:40:00)
  - `dept_count(dept_name varchar(20)) returns integer`: bölümdeki eğitmen sayısını `select count(*) into d_count from instructor where instructor.dept_name = dept_name` ile hesaplar ve `return d_count;` ile döndürür.
  - Kullanımı: `select dept_name, budget from department where dept_count(dept_name) > 12`. Fonksiyon olmasaydı aynı iş bir alt sorguyla yapılmalıydı.
  - Ders sonrası not: Hoca sorguyu "en az 12 eğitmeni olan bölümler" diye okudu; slayttaki koşul `> 12` olduğu için doğrusu "12'den fazla eğitmeni olan bölümler"dir.
  - Tablo döndüren fonksiyonlar da vardır: hocanın örneğinde bir bölüm adını alıp o bölümün eğitmenlerini (`ID`, `name`, `dept_name`, `salary`) tablo olarak döndüren fonksiyon `select * from table(instructor_of('Music'))` gibi kullanılıyor. <!-- BELİRSİZ: tablo fonksiyonu slaytı karelerde yakalanmadı; fonksiyon adı ve kolon tipleri altyazıdan çıkarıldı. -->
  - Varsayılan ve en yaygın tür skaler değer döndüren fonksiyondur.
- Saklı yordamlar (stored procedure)
  - `create procedure ... begin ... end` ile tanımlanır; standart sözdiziminde parametreler `in`/`out` ile işaretlenir, sözdizimi veritabanına göre değişir. Çağrı `call` ya da (SQL Server'da) `EXEC` ile yapılır.
  - Yordam ve fonksiyonlar dinamik SQL'den de çağrılabilir. Aynı adlı birden çok yordam, argüman sayıları farklı olduğu sürece tanımlanabilir; yordam ad ve argüman sayısıyla tanınır (ekrandan, 02:15:00).
  - SQL Server'da yordamlar, fonksiyonlar, kullanıcı tanımlı tipler ve veritabanı tetikleyicileri "Programmability" klasöründe tutulur; tablo tetikleyicileri tablonun altında görünür. Örnek yordam `EXEC GetProductDesc_withparameters 1` ile çalıştırıldı (ekrandan, 02:10:00). Var olan yordamı değiştirmek için `create` yerine `alter` kullanılır.
- Tetikleyiciler (ekrandan, 02:20:00 ve 02:25:00)
  - Tetikleyici, veritabanında bir değişikliğin yan etkisi olarak sistem tarafından otomatik çalıştırılan bir ifadedir. Tasarlarken hangi koşulda çalışacağı ve ne yapacağı belirtilir. SQL:1999 ile standarda girdi; daha önce de çoğu veritabanında standart dışı sözdizimiyle vardı.
  - `insert`, `update`, `delete` olayları üzerine tanımlanır. Güncellemede satırın eski ve yeni hali, eklemede yeni hali, silmede eski hali `referencing old row as` / `referencing new row as` ile kullanılabilir.
  - Kullanım alanları: doğrulama (validation), denetim/log tutma (kim, ne zaman, hangi değişikliği yaptı), türetilmiş değerleri güncel tutma.
  - `for each row` yerine `for each statement` ile ifade düzeyinde tetikleyici de yazılabilir.
- Tetikleyicinin riskleri (ekrandan, 02:30:00)
  - Performansı düşürür; uygulama tarafından görünmez, unutulabilir ve bakım maliyeti yaratır.
  - Yedekten veri yükleme, uzak sitede güncellemeleri çoğaltma ya da toplu yükleme gibi işlemlerde istenmeden çalışabilir; bu işlemlerden önce devre dışı bırakılmalıdır.
  - Tetikleyiciyi başlatan kritik transaction'ın hata nedeniyle başarısız olmasına yol açabilir; zincirleme (cascading) çalışma, kilitlenme (deadlock) riski doğurabilir.
  - Özet veri tutmak için materialized view gibi daha iyi yollar olabilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kullanıcı girdisi asla string birleştirmeyle SQL'e gömülmez
  - Hoca bunu dersin en önemli uyarısı olarak defalarca tekrarladı: kullanıcıdan parametre alınıyorsa ya prepared statement ya da saklı yordam kullanılmalıdır. SQL injection, saldırganların ilk denediği yöntemlerden biridir ve dakikalar içinde veritabanını ele geçirmeye yetebilir.
- Uygulamadan `select *` ile sorgu çekilmez
  - Bütün kolonları açığa çıkardığı için güvenlik, parametre okuma ve performans açısından sorunludur; her zaman kolon adları yazılmalıdır.
- Kapatma işlemleri `finally` içinde daha doğrudur
  - Bir öğrencinin sorusu üzerine hoca, slayttaki kodda `close` çağrılarının `try` içinde durmasının büyük sorun yaratmadığını, ama daha uygun olanın `finally` bloğuna yazmak olduğunu söyledi; çünkü bağlantı kurulduktan sonra da hata çıkabilir.
- Otomatik commit transaction mantığına aykırıdır
  - Birden çok işlemin atomik yapılması gerekiyorsa (para transferi, müşteri ile ürününün birlikte eklenmesi) `setAutoCommit(false)` ve açık `commit`/`rollback` gerekir.
- Saklı yordamlar uzun vadede çok rahatlatır
  - Avantajları: SQL injection'a karşı çift taraflı tip ve boyut denetimi (örneğin `varchar(20)` parametreye uzun bir sorgu sığmaz), veritabanı kodu ile uygulama kodunun ayrılması, DBA ile geliştirici arasında iş bölümü, tek noktadan güncelleme (uygulamaları yeniden derleyip dağıtmadan), yürütme planının önbellekte tutulmasıyla tekrarlanan çağrılarda performans.
  - Dezavantajı: tablonun içinde görünmediği için unutulabilir; çok basit ya da az kullanılan uygulamalarda yazma maliyeti karşılığını vermeyebilir.
- Tetikleyiciler dikkatli kullanılmalı
  - Gerekli değilse kullanılmamalı; veri doğrulama bazen uygulama tarafına alınabilir, özet veriler materialized view ile tutulabilir.

## Kısa Tekrar Notları

- SQL bildirimseldir; arayüz, girdi/çıktı ve döngü için host dil gerekir.
- Erişim yolları: sürücü/API (JDBC, ODBC) ya da gömülü SQL (SQLJ, `EXEC SQL`).
- JDBC adımları: bağlantı, `Statement`, `executeUpdate`/`executeQuery`, `ResultSet` üzerinde `next()`, `getString`/`getFloat`, istisna yönetimi, `close`.
- JDBC'de sorgu hataları çalışma zamanında çıkar; SQLJ ve gömülü SQL derleme zamanında yakalar.
- SQL injection: `X' or 'Y' = 'Y` her satırı döndürür; `X'; update ... --` ek komut çalıştırır. Çözüm: prepared statement ya da saklı yordam.
- Metadata: `getMetaData()`, `getColumns`, `getPrimaryKeys`, `KEY_SEQ`.
- Transaction: varsayılan otomatik commit; `setAutoCommit(false)` + `commit()`/`rollback()`.
- `CallableStatement`: `{? = call f(?)}`, `{call p(?,?)}`.
- BLOB ikili veri (resim, ses, video), CLOB uzun metin.
- Fonksiyon her zaman değer döndürür; yordam döndürmek zorunda değildir.
- `dept_count` örneği: `select count(*) into d_count ... return d_count;`, kullanım `where dept_count(dept_name) > 12`.
- Tablo fonksiyonu: `select * from table(f(param))`; yaygın olan skaler fonksiyondur.
- Tetikleyici: olay (`insert`/`update`/`delete`), koşul (`when`), eylem; `referencing old/new row`, `for each row`/`for each statement`.
- Tetikleyici riskleri: performans, görünmezlik, toplu yüklemede istenmeyen çalışma, zincirleme çalışma.

## Detaylı Açıklamalar

- Host dil ile veritabanının ayrılması
  - Hoca, gerçek bir uygulamayı çizim tahtasında katmanlara ayırarak anlattı. Kullanıcı tarayıcıdan bir forma bilgi girer ve gönderir. Uygulama sunucusundaki controller bu isteği karşılar, model katmanı `save(person)` gibi bir işlem çağırır. Veri ise başka bir sunucudaki ilişkisel veritabanında, örneğin bir `Person` tablosunda tutulur. Uygulama Java ya da C# ile, veritabanı ise Oracle ya da SQL Server ile çalışıyor olabilir. Bu iki farklı dünyanın ağ üzerinden konuşmasını, sorguların doğru ve verimli çalışmasını sürücü sağlar. Sürücü zorunlu değildir ama bu işi standart ve kolay hale getirir. Her veritabanının bağdaştırıcısında küçük sözdizimi farkları olduğundan, hoca kullanılacak veritabanının ve dilin sürücü belgelerine bakılmasını önerdi.
- JDBC'de bir sorgunun yaşam döngüsü
  - Önce sürücü yüklenir ve `DriverManager.getConnection` ile bağlantı dizesi (connection string), kullanıcı adı ve parola verilerek bağlanılır. Slayttaki örnekte bağlantı dizesi `jdbc:oracle:thin:@db.yale.edu:2000:univdb` biçimindedir: sürücü türü, sunucu adresi, port ve veritabanı adı (ekrandan, 00:25:00). Sonra `createStatement()` ile bir ifade nesnesi oluşturulur. Yalnız işlem yapılıyorsa (`insert`, `update`, `delete`) `executeUpdate`, sonuç bekleniyorsa `executeQuery` çağrılır. `executeQuery` bir tablo döndürür; örnekteki `select dept_name, avg(salary) from instructor group by dept_name` sorgusu her bölüm için bir satır döndürür. Hoca sonucu tahtada "Computer Science 45000, Biyoloji 40000" gibi satırlarla canlandırdı. Değerler kolon adıyla ya da sırasıyla alınabilir; hoca kolon adını tercih etti, çünkü sıra karışıklık yaratabilir.
- Neden derleme zamanı denetimi önemlidir
  - Hoca slayttaki `insert` ifadesine fazladan bir tırnak ekleyerek gösterdi: Java derleyicisi string içeriğini bilmediği için bu hata derlemede yakalanmaz, kullanıcı çalışma sırasında karşılaşır (ekrandan, 00:35:00). Hatanın en ucuz yakalandığı yer derleme zamanıdır. Bir öğrenci modern IDE'lerin veritabanına bağlanarak bu denetimi yapabildiğini söyledi; hoca bunun tasarım sırasında işe yaradığını, ama şema sonradan değişirse yakalanamayacağını belirtti.
- SQL injection ve prepared statement
  - Kullanıcının bir giriş kutusuna ad yerine `X' or 'Y' = 'Y` yazması, birleştirilen sorguyu her zaman doğru bir koşula çevirir ve tablonun tamamını döndürür. Noktalı virgülle ikinci bir komut eklenip ardından `--` ile kalan kısım yorum yapılırsa saldırgan maaşları güncelleyebilir, tablo silebilir ya da yetkileri değiştirebilir. Prepared statement'ta ise sorgu sabittir; parametreler tipleriyle (`setString`, `setInt`) verilir ve veritabanı tarafından veri olarak ele alınır. Girdideki tırnaklar kaçışlı hale getirilir ve sorgu yapısı değişmez. Ayrıca sorgu metni sabit kaldığı için tekrar tekrar çağrıldığında daha hızlı çalışır.
- Fonksiyon ile view karşılaştırması
  - Bir öğrenci tablo döndüren fonksiyon yerine view yazmanın daha mantıklı olup olmadığını sordu. Hoca, genelde view'in daha yaygın kullanıldığını ve kendisinin de view tercih ettiğini söyledi. Tablo fonksiyonunun avantajı, parametre alarak yalnız ilgili satırları döndürebilmesi ve ara değişken tanımlayıp hesaplama gibi view'de yapılamayan karmaşık mantığı içerebilmesidir. View ise her şeyi döndürür, filtreleme sonradan `where` ile yapılır.
- `select ... into` neden gerekir
  - Bir öğrencinin sorusu üzerine hoca, `dept_count` fonksiyonunda `count(*)` sonucunun önce `into d_count` ile bir değişkene atandığını, `return` ifadesinin bu değişkeni döndürdüğünü açıkladı. Sorgu doğrudan `return` içine de yazılabilirdi.
- Tetikleyici örneği: `credits_earned` (ekrandan, 02:25:00)
  - `create trigger credits_earned after update of takes on (grade)` tetikleyicisi `takes` tablosundaki not güncellemelerinde çalışır. `referencing new row as nrow` ve `referencing old row as orow` ile satırın yeni ve eski hali adlandırılır, `for each row` ile her güncellenen satır için çalışır. Koşul: yeni not `'F'` değil ve boş değil, eski not ise `'F'` ya da boş. Yani öğrenci dersi ilk kez geçtiğinde çalışır. Eylem (`begin atomic ... end`): `student` tablosunda `tot_cred` değeri, `course` tablosundan bulunan o dersin kredisi kadar artırılır.
  - Bu mantık ders sonrası SQLite sözdizimine uyarlanarak denendi: 4 ve 3 kredilik iki derste notlar boş ve `'F'` değerinden geçer nota çevrilince toplam kredi 7 oldu; zaten geçilmiş bir dersin notu yeniden değiştirildiğinde kredi tekrar eklenmedi.
  - Hoca bu tür özet değerlerin tabloda sürekli güncellenmesinin her zaman doğru olmayabileceğini, toplam kredilerin bir materialized view ile hesaplanmasının daha mantıklı olabileceğini de ekledi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
