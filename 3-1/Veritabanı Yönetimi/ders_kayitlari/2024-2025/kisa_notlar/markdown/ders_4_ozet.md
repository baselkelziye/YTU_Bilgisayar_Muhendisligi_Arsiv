# Ders 4 Çalışma Özeti

## Genel Konular

- SQL'in sınırları ve programlama dilinden veritabanına erişim
  - SQL bildirimsel (declarative) bir dildir: kullanıcı yalnız sorguyu yazar, sistem kaynakları nasıl kullanacağına kendisi karar verir (fiziksel bağımsızlık).
  - Bunun bedeli, genel amaçlı bir dilin ifade gücünün olmamasıdır: kullanıcıdan girdi alıp program akışını değiştirmek, ekrana mesaj basmak, Fibonacci dizisi gibi yinelemeli hesaplar ya da karmaşık istatistiksel analizler SQL ile yapılamaz veya çok zordur.
  - Bu yüzden veri, Java, C, C++, Python gibi bir "host" dilde yazılmış programdan veritabanına bağlanılarak işlenir.
- Dinamik SQL ve gömülü (statik) SQL
  - Dinamik SQL: Program, SQL'i çalışma zamanında bir string olarak kurup veritabanına gönderir (JDBC, ODBC, ADO.NET) (ekrandan, 00:10:00).
    - Esnektir; web uygulamaları gibi esneklik isteyen sistemlere uygundur.
    - Daha az verimlidir: Erişim planı (sorgu optimizasyonu) çalışma zamanında veritabanında üretilir.
    - Daha fazla güvenlik riski taşır.
  - Gömülü SQL (embedded, statik): SQL ifadeleri program içine özel işaretlerle gömülür, derleme zamanında fonksiyon çağrılarına çevrilir; çalışma zamanında bu çağrılar arkada dinamik SQL olanaklarıyla veritabanına bağlanır (Embedded C, SQLJ).
    - Çalışma zamanında değiştirilemez, daha az esnektir, hata ayıklaması zordur.
    - Daha verimli ve daha güvenlidir.
  - Pratikte esnekliği nedeniyle dinamik SQL (JDBC/ODBC) daha yaygındır.
- JDBC
  - JDBC, Java'nın veritabanına bağlanma protokolü ve API'sidir. Her veritabanı üreticisi (Oracle, PostgreSQL, MS SQL Server) bu standart çağrıları kendi iç işlemlerine çeviren bir sürücü (driver) sağlar.
  - Temel nesneler: `Connection` (bağlantı), `Statement` (ifade), `ResultSet` (sonuç kümesi), `ResultSetMetaData` (sonucun şeması) ve hata yönetimi için `SQLException`.
  - `executeUpdate` ekleme, güncelleme ve silmede etkilenen satır sayısını, DDL ifadelerinde 0 döndürür; `executeQuery` bir `ResultSet` döndürür (ekrandan, 00:39:30).
  - Java 7 ve JDBC 4 ile gelen "try-with-resources" yapısında `try (...)` parantezi içinde açılan bağlantı ve ifade, blok sonunda hata olsa da otomatik kapanır (ekrandan, 00:26:30).
- Empedans uyumsuzluğu (impedance mismatch)
  - Programlama dili değer bazlı, SQL tablo bazlı çalışır; veri tipleri de farklı olabilir.
  - JDBC'de bu fark, `ResultSet` üzerinde `next()` ile satır satır dolaşıp `getString`, `getFloat` gibi fonksiyonlarla değer alınarak aşılır.
- Hazır ifade (PreparedStatement)
  - Değerlerin yerine `?` konur; veritabanı sorguyu ilk hazırlandığında derler, sonra farklı parametrelerle aynı planı kullanır: "bir kez derle, çok kez çalıştır" (ekrandan, 00:44:40).
  - Buradaki derleme programın değil, veritabanı tarafındaki derleme ve optimizasyondur.
  - `setString`, `setInt` gibi fonksiyonlar tırnak gibi özel karakterleri kaçışlayarak gönderir; bu yüzden `D'Souza` gibi tırnaklı adlar sorun çıkarmaz.
- SQL enjeksiyonu (SQL injection)
  - Kullanıcı girdisi string birleştirmeyle sorguya eklenirse, kötü niyetli kullanıcı `X' or 'Y' = 'Y` yazarak koşulu her zaman doğru yapar ve bütün tabloyu görür (ekrandan, 00:52:50).
  - `X'; update instructor set salary = salary + 10000; --` gibi bir girdiyle, birden çok ifade çalıştırmaya izin verilmişse, veritabanını değiştiren bir komut da çalıştırılabilir; `--` sondaki tırnağı yorum satırına çevirir.
  - Sorgu yalnız bir kez çalışacak olsa bile kullanıcı girdisi her zaman PreparedStatement parametresi olarak verilmelidir.
- JDBC'nin diğer özellikleri
  - `ResultSetMetaData`: Sütun sayısı, adları ve tipleri öğrenilir; çalışma zamanında ne döneceği bilinmeyen sorgular ve veritabanı tarayıcısı gibi genel araçlar için gereklidir. `DatabaseMetaData` ile tabloların birincil ve yabancı anahtarları öğrenilebilir.
  - İşlemler (transaction): Bağlantı üzerinden otomatik commit, commit, rollback ve yalıtım seviyeleri (read uncommitted, read committed, repeatable read, serializable) ayarlanabilir.
  - `prepareCall` ile veritabanındaki fonksiyon ve prosedürler çağrılabilir.
- ODBC, gömülü SQL ve gömülü veritabanları
  - ODBC, C ve benzeri diller için aynı kavramları (bağlantı, ifade, sorgu, sonuç) sağlar.
  - SQLJ ve Embedded C'de SQL bölgeleri özel işaretlerle (örneğin `#sql`) yazılır.
  - Gömülü veritabanı (embedded database): İstemci-sunucu mimarisi olmadan, uygulama doğrudan veritabanının kütüphane API'sini kullanır; köprü olmadığı için daha hızlıdır. Örnekler: Berkeley DB, LevelDB, gömülü MySQL, SQLite, Java DB.
- Fonksiyonlar ve prosedürler
  - Temel avantaj: İş kuralları (business rules) için tek değişiklik noktası sağlarlar (ekrandan, 01:40:40).
  - Temel dezavantaj: Yüksek düzeyde optimize edilmiş yerleşik (built-in) fonksiyonlara göre optimizasyon ve paralellik eksikliği. Ayrıca sözdizimi veritabanı ürününe özgüdür, taşınabilir değildir.
  - Örnek fonksiyon `dept_count`: Bölüm adını alıp o bölümdeki hoca sayısını döndürür; `where dept_count(dept_name) > 12` gibi SQL içinde kullanılabilir.
  - Tablo fonksiyonları (parametreli görünüm, parameterized view): Sonuç olarak tablo döndürür; görünümden farkı parametre almasıdır (ekrandan, 01:42:40).
  - Prosedürler değer döndürmez, çıkış parametresine değer yazar; SQL içinden doğrudan çağrılamaz.
- Harici dilde yazılmış rutinler (external language routines)
  - Fonksiyon C, Java, Python gibi bir dilde yazılıp veritabanına eklenir; daha verimli ve ifade gücü yüksektir, farklı veritabanlarında kullanılabilir.
  - Dezavantajı: Kod veritabanının adres alanında çalışabilir; veritabanı yapılarının bozulması ve güvenlik riski vardır. Kum havuzu (sandbox) gibi teknikler güvenlik sağlar ama performans düşebilir.
- Tetikleyiciler (trigger)
  - Olay-koşul-eylem (event-condition-action) yapısındadır: Olay insert, delete veya update olabilir; update belirli niteliklerle sınırlandırılabilir (ekrandan, 01:54:30).
  - `referencing old row as` (delete ve update için), `referencing new row as` (insert ve update için) ile satırın eski ve yeni hâline erişilir.
  - Olaydan önce (before) çalışan tetikleyici ek kısıt gibi kullanılabilir: `setnull_trigger`, boş notu `null` yapar.
  - `credits_earned` tetikleyicisi, öğrenci bir dersten geçtiğinde `student.tot_cred` değerini dersin kredisi kadar artırır (ekrandan, 01:57:30).
  - `for each row` her satır için, `for each statement` bütün ifade için bir kez çalışır; ikincisi daha verimlidir ama yazması daha zordur.
  - Tetikleyiciler, assertion'a göre daha hafif ve esnektir: Her eylemde değil, yalnız belirtilen olayda kontrol yapılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Dinamik SQL'de sorgu veritabanı tarafında çalışma zamanında derlenir
  - Sorgu optimizasyonu veritabanlarının 40 yıllık, en önemli konularından biridir. Çalışma zamanında ortaya çıkan sorguların derlenmesi programı yavaşlatır.
- Kaynakların kapatılması
  - Bağlantı açıldığında sistem kaynak (tampon, bellek) ayırır. Hata yüzünden bağlantı kapatılamazsa kaynak zaman aşımına kadar boşa tutulur. Bu yüzden try-with-resources kullanılmalıdır.
  - Parolanın program içine açık yazılması güvenli değildir; ortam değişkenleri gibi daha güvenli yollar araştırılmalıdır.
- PreparedStatement her zaman kullanılmalı
  - Verimlilikten öte asıl neden SQL enjeksiyonudur. Program dış dünyaya açıldığında kullanıcılar programın yetkileriyle veritabanına bağlanır.
  - Gerçek dünyada SQL enjeksiyonuyla finans sitelerinden büyük miktarda para çalındığı slaytta vurgulandı.
- Parametreli sorgularda optimizasyon tam çözülmüş değil
  - Optimizer'ın ilk parametre değerleriyle verdiği plan kararı, başka değerler için iyi olmayabilir.
- İşlem bütünlüğü ve ACID
  - Banka para transferinde bir hesaptan para düşülüp diğerine eklenemezse para kaybolur. Ara (tutarsız) durum dış dünyaya görünmemelidir. Tek kullanıcıda bile bu bütünlük gerekir.
  - Web uygulamalarında yalıtım seviyesi çoğu zaman read committed tutulur: Son koltuğu birden çok kişi görür, onay aşamasında bazıları alamaz.
- Tetikleyici tehlikeleri
  - `on delete cascade` gibi SQL'in zaten sağladığı bir işi tetikleyiciyle yazmak gereksiz ve tehlikelidir.
  - Replikasyon ve materialized view gibi yerleşik yapıların işini tetikleyiciyle yapmak çakışmaya yol açar.
  - Bir tetikleyici başka tetikleyicileri zincirleme tetikleyebilir; sonucun öngörülmesi zorlaşır.

## Kısa Tekrar Notları

- SQL bildirimsel; genel amaçlı bir dilin ifade gücü yok.
- Dinamik SQL: çalışma zamanında string, esnek, daha yavaş, daha riskli (JDBC, ODBC, ADO.NET).
- Gömülü SQL: derleme zamanında fonksiyon çağrısı, hızlı, güvenli, esnek değil, hata ayıklaması zor (Embedded C, SQLJ).
- JDBC nesneleri: `Connection`, `Statement`, `ResultSet`, `ResultSetMetaData`.
- `executeUpdate` etkilenen satır sayısı (DDL'de 0), `executeQuery` `ResultSet` döndürür.
- try-with-resources: parantez içinde açılan kaynaklar otomatik kapanır.
- Empedans uyumsuzluğu: değer bazlı dil ile tablo bazlı SQL arasındaki fark; `ResultSet.next()` ile aşılır.
- PreparedStatement: `?` parametreleri, bir kez derle çok kez çalıştır, SQL enjeksiyonunu önler.
- SQL enjeksiyonu: `X' or 'Y' = 'Y` koşulu her zaman doğru yapar.
- Fonksiyon: iş kuralları için tek değişiklik noktası; dezavantaj: optimizasyon ve paralellik eksikliği, taşınamazlık.
- Tablo fonksiyonu = parametreli görünüm.
- Prosedür değer döndürmez, SQL içinden çağrılamaz.
- Harici dil rutinleri: hızlı ve taşınabilir, ama adres alanı yüzünden güvenlik riski.
- Tetikleyici: olay-koşul-eylem; before/after; for each row / for each statement; old row / new row.

## Detaylı Açıklamalar

- **Neden host dil?** SQL'de kullanıcı yalnız ne istediğini söyler, sistem kaynakları kendisi yönetir. Bu, analitik sorgular için güçlü bir yapıdır, ama kullanıcıdan girdi alıp akışı değiştirmek, bir yere mesaj göndermek ya da yinelemeli hesaplar yapmak gibi işlemler yapılamaz. Bu işler için veri veritabanından çekilir ve Java, C gibi bir dilde işlenir. Konsoldan (örneğin pgAdmin) bağlanırken aracın kendi protokolü kullanılır; bir programdan bağlanırken ise programlama diline uygun bir sürücü gerekir: Java için JDBC, C için ODBC, Python için ayrı bir kütüphane.
- **JDBC programının yapısı.** Slayttaki örnekte bağlantı `DriverManager.getConnection("jdbc:oracle:thin:@db.yale.edu:2000:univdb", userid, passwd)` ile açılır (ekrandan, 00:26:30). URL, `db.yale.edu` makinesinde 2000 numaralı portta dinleyen veritabanı sunucusundaki `univdb` veritabanını gösterir; `thin`, Oracle sürücüsünün bağlantı modlarından biridir. Bağlantı ve `Statement` aynı `try (...)` parantezinde açılır; blok bitince ya da hata olunca ikisi de otomatik kapanır. Eski sürümlerde sürücü elle yüklenir, `stmt.close()` ve `conn.close()` elle çağrılırdı; arada bir hata olursa bunlar çalışmadığından kaynaklar boşa tutulurdu.
- **Güncelleme ve sorgu örneği** (ekrandan, 00:39:30):

  ```java
  try {
      stmt.executeUpdate(
          "insert into instructor values('77987', 'Kim', 'Physics', 98000)");
  } catch (SQLException sqle) {
      System.out.println("Could not insert tuple. " + sqle);
  }
  ResultSet rset = stmt.executeQuery(
      "select dept_name, avg (salary) from instructor group by dept_name");
  while (rset.next()) {
      System.out.println(rset.getString("dept_name") + " " + rset.getFloat(2));
  }
  ```

  Sorgu programın içinde sabit yazıldığı için dönecek sütunlar bilinir, metadata gerekmez. Sorgu çalışma zamanında başka yerden gelseydi sütun sayısı ve tipleri `ResultSetMetaData` ile öğrenilmeliydi.
- **PreparedStatement örneği** (ekrandan, 00:44:40):

  ```java
  PreparedStatement pStmt = conn.prepareStatement(
      "insert into instructor values(?,?,?,?)");  // henüz çalışmaz, erişim planı üretilir
  pStmt.setString(1, "88877");
  pStmt.setString(2, "Perry");
  pStmt.setString(3, "Finance");
  pStmt.setInt(4, 125000);
  pStmt.executeUpdate();
  pStmt.setString(1, "88878");
  pStmt.executeUpdate();  // aynı plan, yalnız ilk parametre değişti
  ```

  Bir web formu gibi aynı yapıdaki sorguların farklı değerlerle tekrar tekrar gönderildiği uygulamalarda veritabanı her seferinde yeniden derleme yapmaz. Slayttaki uyarı: Kullanıcı girdisi sorguya eklenirken asla string birleştirme kullanılmamalıdır. `"insert into instructor values(' " + ID + " ', ' " + name + " ', ..."` biçiminde kurulan sorguda ad `D'Souza` olursa tek tırnak sorgunun tırnaklarıyla karışır ve sözdizimi hatası çıkar.
- **SQL enjeksiyonu** (ekrandan, 00:52:50). Sorgu `"select * from instructor where name = '" + name + "'"` biçiminde kurulsun. Kullanıcı ad yerine `X' or 'Y' = 'Y` yazarsa sorgu `select * from instructor where name = 'X' or 'Y' = 'Y'` olur. `name = 'X'` yanlış olsa da `'Y' = 'Y'` her zaman doğrudur, bütün tablo döner. Kullanıcı `X'; update instructor set salary = salary + 10000; --` yazarsa, sürücü birden çok ifadeye izin veriyorsa herkesin maaşı artar. Çoğu JDBC sürücüsünde birden çok ifade varsayılan olarak kapalıdır ama açılmış olabilir. PreparedStatement sorgu yapısını veriden ayırır; tırnaklar kaçışlanır ve aranan değer gerçekten `X' or 'Y' = 'Y` metni olur, koşul yanlış çıkar.
- **Fonksiyon örnekleri** (ekrandan, 01:40:40 ve 01:42:40):

  ```sql
  create function dept_count (dept_name varchar(20))
    returns integer
    begin
      declare d_count integer;
      select count (*) into d_count
      from instructor
      where instructor.dept_name = dept_name;
      return d_count;
    end

  select dept_name, budget
  from department
  where dept_count (dept_name) > 12;

  create function instructor_of (dept_name char(20))
    returns table (ID varchar(5), name varchar(20),
                   dept_name varchar(20), salary numeric(8,2))
    return table
      (select ID, name, dept_name, salary
       from instructor
       where instructor.dept_name = instructor_of.dept_name);

  select * from table (instructor_of ('Music'));
  ```

  Görünüm bir tanım saklar ve kullanıldığında açılıp çalıştırılır; tablo fonksiyonu da böyledir, ama parametre alır. Hoca, iş kuralına örnek olarak ön koşul dersini geçmemiş öğrencinin dersi alamamasını verdi: Bu kural varsayılan kısıtlarla tanımlanamaz, uygulamada da yazılabilir, ama merkezde bir prosedürde yazılırsa kural değiştiğinde tek yerde değiştirilir ve onu kullanan uygulamalar değişmez.
- **Tetikleyici örnekleri** (ekrandan, 01:54:30 ve 01:57:30):

  ```sql
  create trigger setnull_trigger before update of takes
  referencing new row as nrow
  for each row
    when (nrow.grade = ' ')
    begin atomic
      set nrow.grade = null;
    end;

  create trigger credits_earned after update of takes on (grade)
  referencing new row as nrow
  referencing old row as orow
  for each row
  when nrow.grade <> 'F' and nrow.grade is not null
    and (orow.grade = 'F' or orow.grade is null)
  begin atomic
    update student
    set tot_cred = tot_cred +
        (select credits
         from course
         where course.course_id = nrow.course_id)
    where student.id = nrow.id;
  end;
  ```

  İkinci tetikleyici, notun eskiden F ya da boş olup yeni durumda F'den farklı ve boş olmadığı, yani öğrencinin dersten yeni geçtiği satırlarda çalışır. Dersin kredisini `course` tablosundan alıp öğrencinin toplam kredisine ekler. Hoca bu sorgunun iyi anlaşılması gerektiğini, zorluk açısından "tam orta" bir örnek olduğunu söyledi. Ayrıca `tot_cred` türetilmiş bir değer olduğu için hiç saklanmayıp gerektiğinde hesaplanmasının daha iyi olabileceğini, tetikleyicinin de sisteme yük getirdiğini belirtti.
- **Ders sonrası notlar**
  - Hoca Fibonacci dizisini "ilk 10 sayının toplamı" diye tarif etti. Doğrusu: Fibonacci dizisinde her terim kendinden önceki iki terimin toplamıdır (1, 1, 2, 3, 5, 8, ...).
  - Hoca try-with-resources yapısından önceki JDBC sürümleri için "herhalde 4-5 sene önce" dedi. Java 7 büyük olasılıkla 2011'de çıktığı için bu, dersin tarihinden on yılı aşkın bir süre öncesidir.
  - Hoca SQLJ'yi anlatırken bir an "SQL'ler runtime'da compile ediliyor" dedi, hemen ardından program derlenirken derlendiğini söyledi. Doğrusu ikincisidir: Gömülü SQL'de ifadeler derleme zamanında çevrilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
