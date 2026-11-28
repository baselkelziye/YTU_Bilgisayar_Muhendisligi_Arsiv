# Ders 4 Genişletilmiş Notu: İleri SQL: Programlardan Veritabanı Erişimi (JDBC, ODBC, Gömülü SQL), Fonksiyonlar, Saklı Yordamlar ve Tetikleyiciler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. SQL ve Host Programlama Dili
- 2. Uygulama Mimarisi ve Sürücüler
- 3. JDBC
- 4. JDBC ile Sorgu Yazmanın Sorunları ve SQL Injection
- 5. Prepared Statement
- 6. Metadata
- 7. JDBC'de Transaction Denetimi
- 8. Diğer JDBC Özellikleri: Callable Statement ve Büyük Nesneler
- 9. SQLJ, ODBC ve Gömülü SQL
- 10. Fonksiyonlar ve Yordamlar
- 11. Saklı Yordamlar (Stored Procedure)
- 12. Tetikleyiciler (Trigger)
- Örnek Sorular
- Dersin Toparlaması

Ders Zoom üzerinden yapıldı. Hoca "Database System Concepts" (7. baskı, Silberschatz, Korth ve Sudarshan) kitabının 5. bölümü olan "Advanced SQL" slaytlarını kullandı (ekrandan, 00:10:00). Slaytların yanında bir çizim tahtası ve SQL Server Management Studio'da gösterilen bir saklı yordam örneği kullanıldı. Özyinelemeli sorgular (recursive queries) ve gelişmiş birleştirme/sıralama özellikleri bu derste işlenmedi.

## 1. SQL ve Host Programlama Dili

### 1.1 Bildirimsel ve prosedürel diller

Hoca derse bir hatırlatma sorusuyla başladı: SQL neden klasik bir programlama dili gibi kullanılmaz, Java ya da Python'daki hangi özelliklere sahip değildir?

Prosedürel dillerde (Java, C, C++, C#) karmaşık ve yinelemeli işlemler yapılabilir, döngüler kurulabilir, kullanıcıdan girdi alınabilir, bir hesaplamanın sonucu ekrana yazdırılabilir. Bu dillerde bir değer önce bir değişkende tutulur ve üzerinde adım adım değişiklik yapılarak sonuca ulaşılır. SQL ise bildirimsel (declarative) bir dildir: var olan veri üzerinde ne istendiğini söyler; döngü mantığı ya da değişken üzerinden adım adım veri işleme yoktur.

Bu eksiklik yüzünden kullanıcıdan girdi almak, bir arayüzden veri girişi yapmak, sonuçları göstermek gibi işler SQL ile yapılamaz. Bunun için SQL, genel amaçlı bir programlama dilinin parçası olarak çalışır. Bu dile **host programlama dili** denir.

### 1.2 Host dilin veritabanına erişme yolları

**Soru:** Bir web sitesi, mobil uygulama, bir tablolama programı ya da başka bir üçüncü parti uygulama veritabanına nasıl erişir? **Cevap:** İki ana yöntem vardır:

- Veritabanına erişim için geliştirilmiş genel amaçlı bir ara program, yani bir **sürücü (driver)** ya da **bağdaştırıcı (adaptör)** kullanmak. JDBC ve ODBC bu türdendir.
- **Gömülü SQL (embedded SQL)** kullanmak. SQL ifadeleri host dilin içine yazılır; derleme aşamasında fonksiyon çağrılarına dönüştürülür, çalışma zamanında veritabanına gidip sonucu getirir.

## 2. Uygulama Mimarisi ve Sürücüler

### 2.1 Çizim tahtasındaki mimari

Hoca bir uygulamanın veritabanıyla nasıl konuştuğunu çizim tahtasında anlattı (ekrandan, 00:15:00 ve 01:35:00). Tahtadaki yapı şöyledir:

```text
İstemci tarafı        Sunucu tarafı                         DB sunucusu
--------------        -------------------------------       ----------------------
istemciler --HTTP-->  Uygulama sunucusu (app server)        Veritabanı
                      [web uygulaması:                       (Oracle / MySQL /
                       UI, controller, model]                 IBM / SQL Server)
                         |  save(person);                    Person tablosu
                         v
                      Sürücü (JDBC / ODBC):
                       connection -> statement -> exec  ---> fonksiyon / yordam
istemciler --HTTP-->  Uygulama sunucusu 2
```

İstemciler (siz, ben ya da çok sayıda kullanıcı) HTTP üzerinden uygulama sunucusuna bağlanır. Birden çok uygulama sunucusu ve her birinde birden çok uygulama olabilir. Sunucudaki web uygulamasında bir arayüz (örneğin bir form ve "gönder"/"iptal" düğmeleri), arka planda bir controller ve bir veri modeli vardır. Kullanıcı formu gönderdiğinde model, örneğin yeni bir müşteriyi kaydetmek için `save(person)` gibi bir işlem çağırır. Bu bilgiler sonunda veritabanındaki `Person` tablosuna (ID, ad ve diğer kolonlar) yazılmalıdır; bu yeni bir kayıt ya da var olan kaydın güncellenmesi olabilir.

Veritabanı genellikle uygulama sunucusuyla aynı makinede değil, ayrı bir DB sunucusunda tutulur. Uygulama Java ya da C# tabanlı, veritabanı Oracle, MySQL, SQL Server, IBM, Teradata gibi herhangi bir ilişkisel veritabanı olabilir. Bu iki tarafı konuşturan arayüze **sürücü** denir: iki farklı teknoloji arasında bağlantı kuran, API sağlayan bir bağdaştırıcı ya da özel bir kod parçası.

### 2.2 Sürücünün yaptığı iş

Uygulama sürücüyü kendi içinden çağırır. Bir sorgu yapıldığında sürücü:

1. Veritabanına giderek bir **bağlantı (connection)** oluşturur.
2. Çalıştırılacak SQL'i içeren bir **ifade (statement)** oluşturulur.
3. İfade **çalıştırılır (execute)**; veritabanında çalışan sorgu bir sonuç üretir. Bu sonuca **result set** denir.
4. Host dil bu sonucu satır satır okuyarak analiz edebilir, filtreleyebilir, gösterebilir.

Java için JDBC kullanılır. Başka dillerden (C, C++, C#, Python) erişim için farklı bağdaştırıcılar vardır. ODBC daha standart bir SQL bağdaştırıcısıdır; ODBC'yi uygulayan herhangi bir veritabanına (SQL Server, MySQL, Oracle) herhangi bir dilden bağlanılabilir. Microsoft araçları daha çok ODBC, Java tabanlı sistemler JDBC kullanır. Her veritabanının bağdaştırıcısı farklılık gösterir; örneğin MySQL'in ODBC bağdaştırıcısı SQL Server'ınkinden farklıdır. İlk adım her zaman sürücüyü yüklemektir.

Bağlantı için gerekenler (tahtada, ekrandan, 01:35:00): sunucunun IP ya da web adresi, veritabanı örneği (instance) ya da adı, kullanıcı adı ve parola.

## 3. JDBC

### 3.1 Tanım

Slayttaki tanıma göre (ekrandan, 00:20:00):

- JDBC, SQL destekleyen veritabanı sistemleriyle iletişim için bir Java API'sidir.
- Veri sorgulama, güncelleme ve sorgu sonuçlarını alma için çeşitli özellikler sunar.
- Metadata sorgulamayı da destekler: veritabanındaki ilişkiler, niteliklerin adları ve tipleri.
- İletişim modeli: bağlantı aç; bir "statement" nesnesi oluştur; bu nesneyle sorguları gönder ve sonuçları al; hataları istisna (exception) mekanizmasıyla yönet.

Bir öğrencinin sorusu üzerine hoca, bu ders için Java bilmenin zorunlu olmadığını, Java örneği üzerinden anlatıldığını söyledi.

İletişim ağ üzerinden yapıldığı için veritabanına o anda erişilemeyebilir, internet bağlantısı kopabilir; bu hataları yönetecek bir istisna yakalama mekanizması gerekir. Sürücüler, ağ iletişimini ve sorguların doğru, verimli çalışmasını hazır kodla sağladığı için işi büyük ölçüde kolaylaştırır.

### 3.2 JDBC kod iskeleti

Slayttaki eski Java/JDBC sürümleri için örnek (ekrandan, 00:25:00):

```java
public static void JDBCexample(String dbid, String userid, String passwd)
{
  try {
    Class.forName ("oracle.jdbc.driver.OracleDriver");
    Connection conn = DriverManager.getConnection(
        "jdbc:oracle:thin:@db.yale.edu:2000:univdb", userid, passwd);
    Statement stmt = conn.createStatement();
      ... Do Actual Work ....
    stmt.close();
    conn.close();
  }
  catch (SQLException sqle) {
    System.out.println("SQLException : " + sqle);
  }
}
```

Slayttaki nota göre `Class.forName` JDBC 4'ten itibaren gerekli değildir; Java 7'den itibaren önceki slayttaki try-with-resources sözdizimi tercih edilir. Hoca, sorgunun hata çıkabileceği için `try`/`catch` içine alındığını anlattı. `DriverManager.getConnection` ile bağlantı dizesi (connection string) verilir; örnekteki dize sürücü türünü, sunucu adresini, portu (2000) ve veritabanı adını içerir. Ardından kullanıcı adı ve parola verilir. Bağlandıktan sonra `createStatement()` ile bir ifade nesnesi oluşturulur ve içine `insert`, `update`, `delete` gibi yapılacak SQL işlemleri yazılır. Eski sürümlerde sürücü sınıfının (Oracle sürücüsü mü, başka bir sürücü mü) `Class.forName` ile belirtilmesi ve iş bitince önce ifadenin, sonra bağlantının açıkça kapatılması gerekir.

**Soru:** İfade ve bağlantıyı kapatma kodu `finally` bloğuna yazılsa daha iyi olmaz mı? **Cevap:** Olur. Burada büyük bir fark yoktur, çünkü bağlantı kurulamadığında kapatılacak bir şey de yoktur. Ama daha uygun olanı `finally` içinde yazmaktır; çünkü bağlantı kurulduktan sonra da bir sorun çıkabilir ve `finally` her durumda çalışır.

### 3.3 Güncelleme ve sorgu

Slayttaki örnek (ekrandan, 00:30:00):

```java
try {
  stmt.executeUpdate(
    "insert into instructor values('77987', 'Kim', 'Physics', 98000)");
} catch (SQLException sqle)
{
  System.out.println("Could not insert tuple. " + sqle);
}

ResultSet rset = stmt.executeQuery(
                   "select dept_name, avg (salary)
                    from instructor
                    group by dept_name");
while (rset.next()) {
  System.out.println(rset.getString("dept_name") + " " +
                     rset.getFloat(2));
}
```

Yalnız işlem yapılıyorsa `executeUpdate` çağrılır. Bir sonuç üretilecekse `executeQuery` çağrılır ve bir `ResultSet` döner. Örnekteki sorgu `instructor` tablosundan her bölümün adını ve ortalama maaşını gruplayarak getirir. Hoca sonucu tahtada şöyle canlandırdı: `dept_name` ve ortalama `salary` kolonları; "Computer Science 45000", "Biyoloji 40000" gibi her bölüm için bir satır, toplam n satır.

Sonuç bir tablo olduğu için satır satır işlemek gerekir. `while` döngüsünde `next()` her çağrıldığında bir sonraki satıra geçer. Değer string ise `getString`, sayı ise `getInt`/`getFloat` gibi metotlarla alınır. Kolon adı (`"dept_name"`) ya da sırası (`2`, yani dönen satırın ikinci kolonu) kullanılabilir. Hoca adı yazmayı daha iyi buldu, çünkü sıra karışıklık yaratabilir.

Sorgu hiçbir şey döndürmeyebilir (örneğin tablo boşsa) ya da bir değer null olabilir. Null değerler önceden ele alınmalıdır, aksi halde tip dönüşümü hata verebilir.

## 4. JDBC ile Sorgu Yazmanın Sorunları ve SQL Injection

### 4.1 Hatalar çalışma zamanında ortaya çıkar

Hoca slayttaki `insert` ifadesinde `'Physics'` değerinin sonuna fazladan bir çift tırnak ekleyerek sorguyu bozdu (ekrandan, 00:35:00). Bu sorgu çalışmaz ama Java derleyicisi string'in içeriğini bilmediği için hatayı derleme sırasında yakalamaz.

**Soru:** Bu hata ne zaman ortaya çıkar? **Cevap:** Çalışma zamanında. Bu bir sorundur, çünkü amaç hatayı derleme sırasında yakalamaktır; kullanıcının çalışma sırasında hatayla karşılaşması iyi değildir. Hatayı derlemede yakalamak en az maliyetli yoldur.

### 4.2 Başka sorunlar

**Soru:** Sorguyu `Statement` içinde string olarak yazmanın başka ne sorunu olabilir? **Cevap (bir öğrenci):** SQL injection olabilir. Hoca bunu doğruladı: SQL injection, saldırganların ilk denediği yöntemlerden biridir; çok basittir ve birkaç dakikada bütün bilgiler çalınabilir ya da veritabanı çökertilebilir.

**Soru:** Başka? **Cevap (hoca):** Performans. Aynı `select` farklı kullanıcılar tarafından defalarca çağrılıyorsa, her seferinde sorgu yeniden oluşturulur, bağlantı gider, veritabanı çalışır ve döner. Derleyici string'in içinde ne olduğunu bilmediği için her sorgu ayrı bir kod parçası gibi değerlendirilir; önbellekleme ya da optimizasyon yapılamaz.

Özetle string olarak yazılan sorgunun üç sorunu vardır: güvenlik (SQL injection), hataların derlemede yakalanmaması ve performans.

### 4.3 SQL injection örneği

Slayttaki örnek (ekrandan, 00:40:00):

- Sorgu şöyle kurulsun: `"select * from instructor where name = '" + name + "'"`
- Kullanıcı ad yerine şunu girsin: `X' or 'Y' = 'Y`
- Ortaya çıkan ifade: `"select * from instructor where name = '" + "X' or 'Y' = 'Y" + "'"`, yani `select * from instructor where name = 'X' or 'Y' = 'Y'`
- Kullanıcı şunu da girebilirdi: `X'; update instructor set salary = salary + 10000; --`
- Prepared statement içeride şunu kullanır: `"select * from instructor where name = 'X\' or \'Y\' = \'Y'"`
- Her zaman prepared statement kullanın, kullanıcı girdilerini parametre olarak verin.

Programcı web uygulamasında bir giriş kutusuna kullanıcının adını, örneğin "Ahmet" yazmasını bekler.

**Soru:** Kullanıcı `X' or 'Y' = 'Y` yazarsa ne olur? **Cevap (bir öğrenci):** Bütün kayıtlar gelir. Hoca doğruladı: `'Y' = 'Y'` her zaman doğru olduğu için `where` koşulu her satır için doğrudur ve `instructor` tablosundaki her şey görünür.

Bu davranış ders sonrası Python'un sqlite3 modülüyle küçük bir tabloda denendi: birleştirilmiş sorgu üç satırın üçünü de döndürdü; aynı girdi `?` parametresiyle verildiğinde hiçbir satır dönmedi.

**Soru:** Bu sorguda başka ne yanlış? **Cevap:** `select *` kullanımı. Bütün kolonları açığa çıkarır; parametre okumada, güvenlikte ve performansta sorun yaratır.

> **Hocanın vurgusu:** Web ya da mobil fark etmez, uygulamadan veritabanına bağlanılıyorsa asla `select *` ile sorgu çekilmez; her zaman kolon adları yazılır.

İkinci girdide ilk `select` hiçbir şey getirmez ama noktalı virgülden sonraki komut da çalışır: bütün eğitmenlerin maaşı 10000 artırılır. `--` kalan kısmı yorum satırına çevirir. Aynı yolla tablolar, hatta bütün veritabanı silinebilir ya da erişim hakları değiştirilebilir.

> **Hocanın vurgusu:** Kullanıcıdan parametre alınıyorsa asla ve asla sorgu string birleştirmeyle (dinamik SQL olarak) kurulmaz. Her zaman prepared statement ya da saklı yordam kullanılır.

## 5. Prepared Statement

JDBC'de sorgular parametreli olarak da yazılabilir. Bütün sorguyu string parçalarını birleştirerek yazmak hem zordur hem hataya açıktır (bir öğrencinin cevabı); ikinci ve daha büyük sorun SQL injection'dır (yine bir öğrencinin cevabı). Kullanıcı bir ID yerine başka bir SQL parçası gönderip tabloyu silebilir ya da verileri çekebilir.

Prepared statement'ta sorgu `?` yer tutucularıyla bir kez yazılır. Parametreler sonradan, tipini belirten metotlarla verilir: örneğin üçüncü parametre kullanıcıdan gelen bölüm adıysa `setString(3, ...)`, bir tamsayı bekleniyorsa `setInt(...)`. String beklenen yere başka bir şey, tamsayı beklenen yere bir SQL parçası gönderilirse hata alınır. Böylece SQL injection önlenir. <!-- BELİRSİZ: slayttaki PreparedStatement kod örneğinin (parametre değerleri dahil) tam metni karelerde okunamadı; yalnız slayt önizlemesi görünüyor. -->

Prepared statement'ın bir avantajı da performanstır: sorgu metni sabit kalır, yalnız parametreler değişir. Oysa string birleştirmede kullanıcıdan "Ahmet" ya da "Mehmet" alındığında sorgunun kendisi de değişmiş olur.

> **Ek bilgi (derste anlatılmadı):** Kitabın bu bölümündeki standart örnekte `conn.prepareStatement("insert into instructor values(?,?,?,?)")` ile ifade hazırlanır, `setString(1, ...)`, `setInt(4, ...)` gibi çağrılarla parametreler verilir ve `executeUpdate()` ile çalıştırılır. Büyük olasılıkla derste gösterilen slayt da bu örnektir.

## 6. Metadata

### 6.1 Neden metadata?

JDBC'de yazılan sorgular, kullanılan tabloların ve kolonların veritabanında var olduğu ön koşuluna dayanır. Bu ön koşulu doğrulamak için metadata sorgulanabilir.

Bir öğrenci modern IDE'lerin (örneğin IntelliJ) veritabanına bağlanarak bu denetimi yapabildiğini söyledi. Hoca, programcının veritabanı yapısını bilmeden ve sorguları test etmeden kod yazmasının zaten büyük bir sorun olduğunu, bu bilginin baştan bilinmesi gerektiğini belirtti.

**Soru:** Peki metadata hangi açıdan anlamlı olabilir? **Cevap:** Bir öğrenci hata ayıklamayı (debug) önerdi. Hoca ek olarak şunu söyledi: veritabanları sabit değil, dinamik yapılardır. Uygulamanın bilgisi dışında bir kolon silinmiş ya da tablo değiştirilmişse, kodda sabit yazılmış sorgular kırılır. IDE'ler tasarım sırasında denetler ama sonradan yapılan değişikliği yakalayamaz. Aslında her veritabanı değişikliğinde ona bağlı bütün uygulamaların güncellenmesi ve test edilmesi gerekir; bu gözden kaçarsa metadata sorgulamak bir önlem olabilir. Bunun da bir maliyeti vardır: her işlemde ayrıca veritabanına bağlanıp denetim yapmak zaman kaybettirir.

### 6.2 ResultSet metadata

Slayttaki örnek (ekrandan, 00:45:00):

```java
ResultSetMetaData rsmd = rs.getMetaData();
for(int i = 1; i <= rsmd.getColumnCount(); i++) {
    System.out.println(rsmd.getColumnName(i));
    System.out.println(rsmd.getColumnTypeName(i));
}
```

Sorgu çalıştırılıp bir `ResultSet` alındıktan sonra `getMetaData()` ile sonuç kümesindeki kolonların sayısı, adları ve tipleri öğrenilebilir.

### 6.3 Database metadata

Bağlantı üzerinde `getMetaData()` çağrılarak veritabanının kendisiyle ilgili metadata alınır. `getColumns` çağrısının argüman sırası: katalog (örnek/instance), şema (veritabanı), tablo deseni ve kolon deseni. `%` işareti `like` operatöründeki gibi "herhangi biri ya da hepsi" anlamına gelir. Örneğin `univdb` şemasındaki `department` tablosunun bütün kolonları ve tipleri, kolon deseni `%` verilerek alınır ve bir `while` döngüsüyle yazdırılır. Benzer şekilde veritabanındaki bütün tabloların adları listelenebilir; eklenecek ya da sorgulanacak tabloların var olup olmadığı görülebilir. <!-- BELİRSİZ: getColumns ve tablo listeleme slaytlarının kod metni karelerde yakalanmadı; anlatım altyazıdan. -->

Birincil anahtarları bulmak için slayttaki örnek (ekrandan, 01:05:00):

```java
DatabaseMetaData dmd = connection.getMetaData();

// Arguments below are: Catalog, Schema, and Table
// The value "" for Catalog/Schema indicates current catalog/schema
// The value null indicates all catalogs/schemas
ResultSet rs = dmd.getPrimaryKeys("", "", tableName);

while(rs.next()){
   // KEY_SEQ indicates the position of the attribute in
   // the primary key, which is required if a primary key has multiple
   // attributes
   System.out.println(rs.getString("KEY_SEQ"),
                      rs.getString("COLUMN_NAME"));
}
```

**Soru:** Birincil anahtar bilgisine hangi amaçla ihtiyaç duyulabilir? **Cevap:** Bir öğrenci yeni bir birincil anahtar üretmeyi önerdi. Hoca şunları ekledi: tabloda birincil anahtar kolonu olup olmadığını öğrenmek; anahtar otomatik artan (auto increment) ise `insert` sırasında değer vermemek; anahtar birden çok kolondan oluşan bileşik (composite) bir anahtarsa hangi kolonları içerdiğini ve değişip değişmediğini görmek. Ayrıca birincil anahtar bir indeks oluşturduğu için sorguları anahtar kolonlar üzerinden yazmak hız kazandırır.

> **Hocanın vurgusu:** Bu uç bir kullanımdır ve çok uygulanan, çok geçerli bir yöntem değildir. Normalde uygulama geliştirilmeden önce kullanılacak tablolar, kolonlar, birincil ve yabancı anahtarlar bilinmeli ya da uygulama tasarlanırken veritabanı da birlikte tasarlanmalıdır.

## 7. JDBC'de Transaction Denetimi

### 7.1 Transaction neden gerekir?

**Soru:** Transaction ne yapar, neden gerekir? **Cevap (bir öğrenci):** Birden fazla işlem yapıldığında arada bir yerde sorun çıkarsa en başa dönmek gerekir. Hoca bunu örneklerle genişletti. Para çekme ve yatırma gibi işlemler birbirini izleyen birden çok adımdan oluşur. Birden çok işlemin atomikmiş gibi, ya hep ya hiç biçiminde yapılması gerektiğinde transaction kullanılır.

Hocanın örneği: bir sigorta şirketinde biri ürün almadan müşteri olamaz. Yeni müşterinin eklenmesi ve müşteriye ürün eklenmesi iki ayrı `insert` işlemidir. Ayrı ayrı yapılırsa arada bir sorun çıktığında sahibi olmayan bir ürün ya da ürünü olmayan bir müşteri oluşabilir. İki `insert` bir transaction içinde atomik olarak yapılmalıdır.

Para gönderme örneği: Ahmet'e para gönderildiğinde para havada kaybolmamalıdır. Ya Ahmet'in hesabına geçer ve gönderenin hesabından çıkar, ya da ulaşmazsa gönderenin hesabından hiç çıkmaz.

### 7.2 Otomatik commit

Slayttaki bilgiler (ekrandan, 01:10:00):

- Varsayılan olarak her SQL ifadesi ayrı bir transaction olarak ele alınır ve otomatik commit edilir. Bu, birden çok güncelleme içeren transaction'lar için kötü bir fikirdir.
- Bir bağlantıda otomatik commit kapatılabilir: `conn.setAutoCommit(false);`
- Bu durumda transaction'lar açıkça commit ya da rollback edilmelidir: `conn.commit();` ya da `conn.rollback();`
- `conn.setAutoCommit(true)` otomatik commit'i yeniden açar.

Hoca, otomatik commit açıkken her işlemin ayrı commit edildiğini, bunun transaction mantığına aykırı olduğunu anlattı. Otomatik commit kapatılınca transaction içine alınan kod bloğunun sonunda, her şey başarıyla gerçekleşmişse `commit`, aksi durumda `rollback` çağrılır.

## 8. Diğer JDBC Özellikleri: Callable Statement ve Büyük Nesneler

### 8.1 Fonksiyon ve yordam çağırma

Slayttaki bilgiler (ekrandan, 01:15:00):

```java
CallableStatement cStmt1 = conn.prepareCall("{? = call some function(?)}");
CallableStatement cStmt2 = conn.prepareCall("{call some procedure(?,?)}");
```

Hoca, parametreleri sorgunun içine yazmak yerine daha akıllıca bir yöntem anlattı: yapılacak işlem veritabanında bir fonksiyon ya da saklı yordam olarak tutulur, uygulama yalnız parametre gönderir. Örneğin `insert_person` adlı bir yordam ad ve bölüm gibi parametreleri alır ve veritabanında `insert` işlemini kendisi yapar. Uygulama tarafında yalnız var olan yordam çağrılır.

**Soru:** Bu yöntemde neden SQL injection olmaz? **Cevap (bir öğrenci):** Parametreler yine tipli `set...` metotlarıyla verilir. Hoca doğruladı ve bir güvence daha ekledi: yordamın parametrelerinin tipi SQL tarafında da (`varchar`, `integer` vb.) belirtilir. Böylece hem uygulama tarafında hem veritabanı tarafında çift taraflı tip denetimi yapılır; uymayan girdi hata verir ve işlem gerçekleşmez.

> **Hocanın vurgusu:** Kullanıcı parametreleri ya prepared statement ile ya da veritabanında tanımlanmış bir saklı yordama parametre olarak gönderilir. Saklı yordam daha verimli ve daha mantıklı yöntemdir; prepared statement da kabul edilebilir. Ama kullanıcıdan alınan girdi asla string birleştirmeyle SQL'e gömülmez.

### 8.2 Büyük nesneler (BLOB ve CLOB)

Slayttaki bilgiler (ekrandan, 01:15:00):

- `getBlob()` ve `getClob()`, `getString()` metoduna benzer ama sırasıyla `Blob` ve `Clob` tipinde nesneler döndürür.
- Bu nesnelerden veri `getBytes()` ile alınır.
- Büyük nesneleri güncellemek için Java `Blob` ya da `Clob` nesnesine açık bir akış (stream) bağlanır: `blob.setBlob(int parameterIndex, InputStream inputStream)`.

**Soru:** BLOB ile CLOB arasındaki fark neydi? **Cevap (bir öğrenci):** BLOB ikili (binary) bir dizi gibidir, CLOB karakterleri tutar. Hoca doğruladı.

**Soru:** Hangi veriler ikili olarak tutulur? **Cevap:** Bir öğrenci resim dedi. Hoca resim, ses dosyası, video (MP4, MP3) gibi normal veri tipleriyle tutulamayan verileri saydı. Bunlar serileştirilip ikili veri bloğu olarak saklanır. Resim Base64 gibi bir metne çevrilip de tutulabilir ama verimli olmaz; sıkıştırma ve çözünürlük açısından ikili tutmak daha uygundur. CLOB ise uzun metinler içindir: kullanıcı yorumları, sosyal medya gönderileri, web sayfası içerikleri, blog yazıları.

Hoca son olarak, kullanılacak veritabanının ve dilin bağdaştırıcı belgelerinin okunmasını önerdi; Oracle, SQL Server ve MySQL bağdaştırıcıları arasında küçük sözdizimi farkları vardır.

## 9. SQLJ, ODBC ve Gömülü SQL

### 9.1 SQLJ

JDBC'nin temel sorunu, sorguların içeriğinin dinamik olması yüzünden hataların derleme zamanında değil yalnız çalışma zamanında ortaya çıkmasıdır. Gömülü SQL bunu önler. Slayttaki örnek (ekrandan, 01:20:00):

- JDBC aşırı dinamiktir, hatalar derleyici tarafından yakalanamaz.
- SQLJ: Java'ya gömülü SQL.

```java
#sql iterator deptInfoIter ( String dept name, int avgSal);
deptInfoIter iter = null;
#sql iter = { select dept_name, avg(salary) from instructor
              group by dept name };
while (iter.next()) {
    String deptName = iter.dept_name();
    int avgSal = iter.avgSal();
    System.out.println(deptName + " " + avgSal);
}
iter.close();
```

Önce bir yineleyici (iterator) tipi tanımlanır ve değişkeni null'a eşitlenir. Sorgu, JDBC'deki gibi tırnak içinde bir string olarak değil, doğrudan yazılır. Sonra yineleyiciyle satırlar sırayla dolaşılır ve sonunda yineleyici kapatılır. Bunun öncesinde bir veritabanı bağlantısının kurulmuş olması gerekir. SQL Java'ya entegre olduğu için `group by` ya da kolon adları yanlış yazılırsa derleme sırasında hata alınır; bu sorunlar çalışma zamanında yaşanmaz.

> **Ders sonrası not:** Slayttaki kodda `dept name` iki yerde boşluklu yazılmış; geçerli tanımlayıcı `dept_name` olmalıdır. Bu büyük olasılıkla slayttaki bir yazım hatasıdır.

### 9.2 ODBC

ODBC (Open Database Connectivity), birçok programlama dilinden veritabanına erişim için tanımlanmış standart bir API'dir ve JDBC'ye çok benzer. Özellikle Microsoft araçlarında (C#, Visual C++) kullanılır ama SQL Server, MySQL ve birçok başka veritabanının ODBC bağdaştırıcısı vardır. İşleyiş aynıdır: önce bağlantı kurulur, sonra sorgular, güncellemeler ve eklemeler gönderilir, sonuçlar alınır. Excel, Access ve raporlama araçları da veritabanına arka planda ODBC ile bağlanır; örneğin Excel'den SQL Server'a bağlanıp veri çekilebilir. <!-- BELİRSİZ: altyazıda Excel ile ilgili "QMIT table" diye geçen terim büyük olasılıkla "pivot table"dır. -->

### 9.3 Gömülü SQL

Slayttaki bilgiler (ekrandan, 01:25:00):

- SQL standardı, SQL'in C, C++, Java, Fortran ve PL/1 gibi çeşitli programlama dillerine gömülmesini tanımlar.
- SQL sorgularının gömüldüğü dile **host dil**, host dilde izin verilen SQL yapılarına **gömülü SQL** denir.
- Bu dillerin temel biçimi, System R'da SQL'in PL/1'e gömülmesini izler.
- Host dilde gömülü SQL isteğini ön işleyiciye (preprocessor) belirtmek için `EXEC SQL` ifadesi kullanılır: `EXEC SQL <embedded SQL statement >;`
- Bu dile göre değişir: COBOL gibi bazı dillerde noktalı virgül yerine `END-EXEC` kullanılır; Java'da gömme `# SQL { .... };` biçimindedir.

Gömülü SQL'in avantajı, yazılan sorguların hatalarının önceden tespit edilebilmesidir. Hocanın anlattığı akış şöyledir:

1. **Bağlantı:** `EXEC SQL CONNECT TO` ile sunucu belirtilir; kullanıcı ve parola gibi bilgiler `using` ile verilir.
2. **Host değişkenler:** Host dilden gelen değişkenler önce bir `declare section` içinde tanımlanır (örneğin bir tamsayı). SQL içinde kullanılırken SQL'in kendi adlarından ayrılsın diye başına iki nokta (`:`) konur. <!-- BELİRSİZ: altyazıda "Credit M6" diye geçen değişken adı büyük olasılıkla kitaptaki :credit_amount değişkenidir. -->
3. **İmleç (cursor) tanımı:** `declare ... cursor for` ile bir sorgu bir imlece bağlanır. Hocanın örneğinde imleç, kredisi host dilden gelen bir değerden büyük olan öğrencilerin ID ve adlarını tutar; sonuç 10, 100 ya da 1000 satır olabilir.
4. **open:** İmleç açılınca sorgu veritabanında çalışır ve sonuç üretilir.
5. **fetch:** Her satır, `fetch` ile host değişkenlere alınır; bu tekrar tekrar çalıştırılarak satırlar tek tek işlenir.
6. **close:** İş bitince imleç kapatılır.

<!-- BELİRSİZ: imleç tanımı, open ve fetch slaytlarının kod metni karelerde yakalanmadı; adımlar altyazıdan. -->

Slayttaki devam bilgileri (ekrandan, 01:30:00):

- SQL iletişim alanındaki (SQLCA) SQLSTATE adlı değişken, başka veri kalmadığını belirtmek için `'02000'` değerini alır.
- `close` ifadesi, veritabanı sisteminin sorgu sonucunu tutan geçici ilişkiyi silmesini sağlar: `EXEC SQL close c ;`
- Bu ayrıntılar dile göre değişir; örneğin Java gömmesi sonuç satırlarında ilerlemek için Java yineleyicileri tanımlar.

Gömülü SQL ile güncelleme ve silme de yapılabilir. Hocanın örneğinde bir imleç `instructor` tablosunu getirir ve dönen her satır için maaş 1000 artırılır; aynı şekilde `delete` ve `insert` de yapılabilir.

> **Ek bilgi (derste anlatılmadı):** Standartta imleç üzerinden güncelleme, imleç `for update` ile tanımlanıp `update instructor set salary = salary + 1000 where current of c` biçiminde yazılır. Büyük olasılıkla derste gösterilen slayt bu yapıdadır.

### 9.4 LINQ ve diğer çerçeveler

Hoca, C# tarafında LINQ'nun da gömülü SQL mantığında çalıştığını anlattı: sorgular host dil içindeki bir kütüphane ya da çerçeve gibi LINQ sözdizimiyle yazılır, arka planda bir bağlantıyla veritabanında çalıştırılır ve derlenebildiği için hataları önceden tespit edilir; `group by` gibi işlemler de yapılabilir. Entity Framework gibi çerçeveler de arka planda bağdaştırıcıları ya da gömülü SQL'i kullanır ama veritabanı erişimini çok sadeleştirir.

Hangi yöntemin (gömülü SQL, dinamik SQL, JDBC, ODBC) nasıl kullanılacağı dile ve veritabanına özgüdür; Java için geçerli olan C ya da C# için aynı sözdizimiyle geçerli değildir, Python'un da kendi kütüphaneleri vardır. Ama genel yöntem ikidir: ya bir sürücü ya da gömülü SQL.

## 10. Fonksiyonlar ve Yordamlar

### 10.1 Tanım ve fark

Burada konu, kullanıcı tanımlı (user defined) fonksiyon ve yordamlardır. Veritabanı yönetim sisteminin kendi hazır fonksiyonları bu konunun dışındadır. Sık kullanılan bir formül ya da işlem için iş mantığını içeren sorgular fonksiyon ya da yordam olarak tanımlanır.

- **Fonksiyon:** Girdi alır ve bir çıktı döndürür; fonksiyonlar her zaman bir sonuç döndürür.
- **Yordam (procedure):** Bir sonuç döndürmek zorunda değildir; daha karmaşık olabilir, döndürebilir de.

Sözdizimi standart değildir; programlama diline ve veritabanına göre değişir. Ama ortak olan şudur: fonksiyon ve yordamlar veritabanında bir nesne olarak tutulur; uygulamanın değil, veritabanının parçasıdır.

### 10.2 Hocanın tahta örneği

Hoca çizim tahtasında (ekrandan, 01:35:00) `insert_person` adlı bir yordamı anlattı. Yordamın üç parametresi vardır: a, b ve c. Uygulama bunlara kendi değişkenlerini, örneğin ad, bölüm ve bütçe değerlerini (Ahmet, Computer Science ve bir bütçe) gönderir ve hangi yordamın çalışacağını belirtir; başka bir şey göndermez. Bütün işlem veritabanı tarafında gerçekleşir. Uygulama tarafı yordamın içindeki sorguları ve iş mantığını bilmez.

Bunun faydaları:

- SQL injection önlenir, çünkü parametreler string ya da integer olarak tanımlanıp gönderilir, yordam içinde de tipleri tanımlıdır.
- Performans artar.
- Mantıksal ayrım sağlanır: veritabanıyla ilgili kod veritabanında, uygulamaya özgü kod uygulamada durur. Hoca bunu oldukça önemli bir ayrım olarak niteledi.

### 10.3 Neden fonksiyon?

Sık kullanılan bir mantık düşünelim: bölümdeki eğitmen sayısını hesaplamak ya da öğrencilerin genel ağırlıklı not ortalamasını (GPA) hesaplamak. Bu kod hem SQL tarafında hem uygulamada defalarca yazılıyorsa:

- Hesaplama yöntemi değiştiğinde kodun yazıldığı her yerin tek tek güncellenmesi gerekir; bu ciddi bir iş yüküdür.
- Dokuz uygulamadan sekizi güncellenip biri unutulursa o uygulama GPA'yı yanlış hesaplar.
- Kopyala-yapıştır daha çok yer kaplar ve kopyalar arasında farklılıklar oluşabilir.
- Kod merkezi bir yerde tutulmaz; mantığın nasıl işlediğini anlamak için her yere bakmak gerekir.

Veritabanı tarafında bir fonksiyon yazmak bu sorunları önler.

### 10.4 Skaler fonksiyon örneği: `dept_count`

Slayttaki örnek (ekrandan, 01:40:00): bir bölüm adı verildiğinde o bölümdeki eğitmen sayısını döndüren fonksiyon.

```sql
create function dept_count (dept_name varchar(20))
    returns integer
    begin
    declare d_count integer;
        select count (* ) into d_count
        from instructor
        where instructor.dept_name = dept_name
    return d_count;
end
```

`dept_count` fonksiyonu, 12'den fazla eğitmeni olan bütün bölümlerin adlarını ve bütçelerini bulmak için kullanılabilir:

```sql
select dept_name, budget
from department
where dept_count (dept_name ) > 12
```

Fonksiyon `create function` ile tanımlanır; adı, parametresinin adı ve tipi, döndüreceği değerin tipi (`returns integer`) yazılır. `begin` ile mantık başlar: geçici bir `d_count` değişkeni tanımlanır, `instructor` tablosunda o bölümdeki eğitmenlerin sayısı bu değişkene atanır ve `return` ile döndürülür.

Artık fonksiyon hem `select` hem `where` içinde kullanılabilir. `department.dept_name` fonksiyona girdi olarak verilir; örneğin CS bölümünde 15 eğitmen varsa koşulu sağlar. `select` listesine virgülle `dept_count(dept_name)` de eklenerek her bölümün eğitmen sayısı gösterilebilirdi. Fonksiyon olmasaydı ayrı bir alt sorgu yazılması gerekirdi; bu hem sorguyu karmaşıklaştırır hem iş mantığını tek bir yerde toplamaz.

> **Ders sonrası not:** Hoca sorguyu "en az 12 tane hocası olan bölümler" diye okudu; slayttaki koşul `> 12` olduğu için doğrusu "12'den fazla eğitmeni olan bölümler"dir.

Fonksiyon veritabanında bir nesne olduğu için defalarca çağrıldığında veritabanı onu önbellekte tutarak daha optimize çalıştırabilir.

**Soru:** Fonksiyonda `into d_count` yazıp sonra `return d_count` dedik; doğrudan `return count` yazılamaz mıydı? **Cevap:** `count(*)` bir sorgunun sonucudur; bu değerin bir değişkene atanması gerekir. `into` ile değer geçici değişkene atanır ve `return` onu döndürür. `into` olmadan sorgu sonucu yalnız yazdırılır, döndürülmez. Ama sorgu doğrudan `return` ifadesinin içine de yazılabilirdi.

### 10.5 Tablo döndüren fonksiyonlar

Fonksiyonlar tek bir değer yerine bir tablo da döndürebilir. Hocanın gösterdiği örnekte fonksiyon `varchar(20)` tipinde bir bölüm adı parametresi alır ve dönüş tipi olarak bir tablo yapısı tanımlanır: `ID varchar(5)`, `name varchar(20)`, `dept_name`, `salary` gibi kolonlar. Fonksiyonun gövdesindeki `select` bu parametreye göre o bölümün eğitmenlerini döndürür. Kullanımı:

```sql
select *
from table(instructor_of('Music'))
```

<!-- BELİRSİZ: tablo fonksiyonu slaytı karelerde yakalanmadı; fonksiyon adı (altyazıda "instructor of"), kolon tipleri ve kullanım altyazıdan çıkarıldı. -->

Hoca bu örneğin basit olduğunu, gerçekte daha karmaşık sorgular için anlamlı olduğunu belirtti. Kullanıcı tanımlı fonksiyonlar varsayılan olarak bir skaler değer (bir integer, bir string) döndürür; tablo döndürme de mümkündür.

**Soru:** Tablo döndüren bir fonksiyon yerine view yazmak daha mantıklı değil mi? **Cevap:** Genelde bunun için view kullanılır ve daha yaygındır; hoca da kendi çalışmasında daha çok view kullandığını söyledi. Tablo fonksiyonunun avantajı belli durumlarda ortaya çıkar: parametre girişi ve filtreleme önemliyse fonksiyon yalnız ilgili satırları döndürür, oysa view her şeyi döndürür ve filtreleme sonradan `where` ile yapılır. Ayrıca fonksiyonda ara değişken tanımlayıp hesaplama yapmak gibi view'de yapılamayan karmaşık mantık kurulabilir. Yine de tablo fonksiyonu yaygın değildir; çok yaygın olan skaler fonksiyondur.

## 11. Saklı Yordamlar (Stored Procedure)

### 11.1 Genel yapı

SQL yordamları fonksiyonlardan farklı olarak bir değer döndürmek zorunda değildir; çıktı döndürebilir de, döndürmeyebilir de. Genel yapıda `create procedure` ile yordam tanımlanır. Hocanın anlattığı örnek bir bölüm sayımı yordamıdır: girdi parametresi bölüm adı, çıktı parametresi sayı (`d_count`) olabilir. Yordam hiç çıktı döndürmeden yalnız bir `insert` de yapabilir.

Standart sözdiziminde parametreler `in` ve `out` sözcükleriyle işaretlenir; bazı sistemlerde yalnız parametre adı ve tipi yazılır. Yordamın gövdesi `begin` ve `end` arasına yazılır. Gövde tek bir sorgudan ibaret olmak zorunda değildir: aynı anda bir `insert` yapılabilir, bir log tablosu güncellenebilir, başka tablolara değer yansıtılabilir. Yordam çağrılırken adı ve parametreleri verilir. <!-- BELİRSİZ: yordam tanımı slaytının kod metni karelerde yakalanmadı; anlatım altyazıdan. -->

Slayttaki ek bilgiler (ekrandan, 02:15:00):

- Yordam ve fonksiyonlar dinamik SQL'den de çağrılabilir.
- SQL, aynı adı taşıyan yordamların argüman sayıları farklı olduğu sürece birden çok yordama izin verir.
- Yordamı tanımlamak için ad ile birlikte argüman sayısı kullanılır.

Uygulama tarafında yordamlar JDBC örneğindeki gibi `CallableStatement` ile, yordamın adı ve parametreleri verilerek çağrılır. ODBC, Entity Framework ve diğer kütüphanelerde de sözdizimi farklı olsa da yordam çağırma vardır; bazen `call`, bazen `exec` kullanılır.

### 11.2 SQL Server örneği

Hoca kendi oluşturduğu örnek bir veritabanında yordamları gösterdi (ekrandan, 02:10:00). SQL Server Management Studio'da yordamlar, fonksiyonlar, kullanıcı tanımlı veri tipleri, kütüphaneler (assembly) ve veritabanı tetikleyicileri "Programmability" klasöründe ayrı nesneler olarak tutulur. Tablo üzerindeki tetikleyiciler ise tablonun altında görünür.

Yordam `create procedure` komutuyla yazılır. SQL Server'da `in`/`out` yazmak gerekmez; komutla birlikte verilen parametreler zaten girdidir. Hocanın örneğinde parametre `integer` tipindedir; başka bir tipte değer gelirse hata verir ve böylece SQL injection engellenir. Gövdede bir `select` ile sonuç gösterilir. Hoca, bunun öncesine örneğin bir ürünün adını ve kategorisini değiştiren bir `update` de eklenebileceğini ekranda yazarak gösterdi; altındaki `select` değişikliği gösterir. Gövde çok daha uzun olabilir: log tutma, başka güncellemeler vb.

Yordam kaydedilince veritabanında bir nesne olarak oluşur. Var olan yordamı görmek ve değiştirmek için "Modify" seçilir; bu durumda tanım `create` yerine `alter` ile açılır, çünkü var olan bir nesne değiştirilmektedir. Yordam SQL tarafında `EXEC` ile çalıştırılır:

```sql
EXEC GetProductDesc_withparameters 1
```

<!-- BELİRSİZ: yordamın gövdesi karelerde görünmüyor; yalnız EXEC çağrısı ve sonuç tablosu görünüyor. -->

### 11.3 Saklı yordamların avantajları

**Soru:** Saklı yordamların avantajları nelerdir? Cevaplar soru-cevap içinde toplandı:

1. **SQL injection'ı engeller.** Kod veritabanında tanımlıdır ve parametreler tipli alınır; beklenenden farklı tipte bir değer hata verir. Hem tip hem boyut denetlenir: örneğin `varchar(20)` beklenen bir parametreye 20 karakterden uzun bir sorgu sığmaz.
2. **İş bölümü.** Bir öğrenci, iç mantığı bilmeden yordamın kullanılabileceğini, kutuyu yalnız dışarıdan görmenin yettiğini söyledi. Hoca doğruladı: yordamın içindeki mantığı bilmesi ve bakımını yapması gereken kişi geliştirici değil, DBA'dır (bir öğrencinin cevabı). Geliştirici yalnız hangi parametreleri göndereceğini ve ne alacağını bilir; arka planda log tutulup tutulmadığını, hangi tablonun değiştiğini bilmek zorunda değildir.
3. **Tek noktadan güncelleme.** Bir öğrenci, değişikliğin her yerde ayrı ayrı değil tek yerden yapıldığını söyledi. Hoca örnekledi: kullanıcılar bir ürünü mobil uygulamadan, web uygulamasından ya da acenteler üzerinden alabilir; hepsi aynı yordamı çalıştırır. Kod uygulamanın içine gömülmüşse her veritabanı değişikliğinde bütün uygulamaların yeniden derlenmesi ve dağıtılması gerekir. Bu hem kırılma riski hem senkron güncelleme maliyeti doğurur; bazı yerler unutulabilir. Büyük bir uygulamayı küçük bir kolon değişikliği için yeniden dağıtmak test, planlama ve canlıya alma süreçleri yüzünden bir hafta ya da daha uzun sürebilir.
4. **Performans.** Yordam veritabanında bir nesne olarak tutulduğu için veritabanı yürütme planını (execution plan) bir kez hesaplar ve önbellekte tutar. İlk çağrıda sorgu motoru planı oluşturmak zorunda olduğu için biraz yavaş olabilir; ama ikinci, üçüncü ya da beş yüz bininci çağrıda (örneğin "Ahmet" ve "Mehmet" parametreleriyle aynı yordam) aynı plan kullanılır. Sık kullanımda uzun vadede ciddi fark oluşur.

> **Hocanın vurgusu:** Veritabanı kodu ile uygulama kodu ayrı tutulmalı, etkileşim parametrelerle sağlanmalıdır. Saklı yordamlar gerçekten çok iyidir; uygulama yazılıyorsa kesinlikle saklı yordamlarla yazılmalıdır, bu uzun vadede çok rahatlatır.

### 11.4 Dezavantajlar

Hoca, çok basit uygulamalarda (örneğin bir "Hello World" uygulaması) ya da çok az kullanılacak özelliklerde yordam yazmanın harcanan zamana değmeyebileceğini söyledi.

**Soru:** Başka dezavantajı var mı? Bir öğrenci çalışma performansını önerdi. Hoca performansın dezavantaj değil, avantaj olduğunu söyledi. Asıl dezavantaj gözden kaçabilmeleridir: yordam tablonun içinde görünmez, ayrı bir bölmede nesne olarak tutulur; güncellenmesi gerektiği unutulabilir. Aynı durum tetikleyiciler için de geçerlidir. Bu bir bakım maliyetidir ama mantığı uygulama koduna gömmenin bakım maliyetiyle karşılaştırıldığında çok küçüktür.

## 12. Tetikleyiciler (Trigger)

### 12.1 Assertion hatırlatması ve tetikleyicinin mantığı

**Soru:** Geçen hafta görülen assertion ne için kullanılırdı? **Cevap (bir öğrenci):** Doğrulama (validation) için; ekleme gibi bir işlemin yapılabilmesi için belli bir koşulun sağlanması gerekir. Hoca doğruladı: belli bir şart varsa, örneğin eklenen değerin geçerli bir ay ya da mevsim olup olmadığı, bunu denetlemek için kullanılır. Tetikleyiciler de bu amaçla kullanılır ama çok daha karmaşık işler de yapabilir.

Slayttaki tanım (ekrandan, 02:20:00):

- Tetikleyici, veritabanında yapılan bir değişikliğin yan etkisi olarak sistem tarafından otomatik çalıştırılan bir ifadedir.
- Bir tetikleyici mekanizması tasarlamak için tetikleyicinin hangi koşullarda çalışacağı ve çalıştığında hangi eylemlerin yapılacağı belirtilmelidir.
- Tetikleyiciler SQL standardına SQL:1999 ile girdi, ama çoğu veritabanı daha önce de standart dışı sözdizimiyle destekliyordu.
- Burada gösterilen sözdizimi bir veritabanında aynen çalışmayabilir; sistem belgelerine bakılmalıdır.

Hoca, bugün bütün ilişkisel veritabanlarında tetikleyici yapısı bulunduğunu söyledi. Tetikleyici bir eyleme bağlanır; o tablo üzerinde `insert`, `update` ya da `delete` gerçekleşirken otomatik olarak tetiklenen bir kod bloğudur.

### 12.2 Kullanım alanları

- **Log ve denetim:** Bir kullanıcı müşterileri silmişse kimin, ne zaman sildiğini veritabanı loglarından izlemek çok zordur. Tetikleyiciyle olması gerekenin dışında bir işlem yapılıp yapılmadığı, kimin ne zaman yaptığı kaydedilebilir. Örneğin bir tabloya "Ahmet" adlı kullanıcının hangi kaynaktan ve kim tarafından eklendiğini tutmak için tetikleyici, ikinci bir `insert` ile ayrı bir izleme (monitoring/log) tablosuna kayıt ekleyebilir.
- **Doğrulama:** Kullanıcıların girdiği veri çoğu zaman hatalı olur; tetikleyici doğrulama için kullanılabilir.
- **Türetilmiş değerleri güncel tutma:** Örneğin toplam kazanılan kredi.

Bankacılık gibi denetimin önemli olduğu yerlerde (kim kime para gönderdi, yanlışlıkla yapılan bir işlemi kim nasıl yaptı) bu logların denetim zamanında elde olması önemlidir.

### 12.3 Eski ve yeni satıra erişim

Tetikleyici, işlemin gerçekleştiği andaki kaydı tutar. `update` işleminde satırın hem güncelleme öncesi hem sonrası, `insert` işleminde yeni hali, `delete` işleminde eski hali bilinir. Bunlara `old row` ve `new row` gibi sözcüklerle başvurulur.

Hocanın anlattığı ilk örnekte `setnull` adlı bir tetikleyici bir tablo üzerindeki güncellemede çalışır, yeni girilen satıra başvurur (`for each row` ile satırın bütün kolonlarına erişilir) ve satırdaki `grade` değeri boşluk olarak girilmişse onu null yapar. <!-- BELİRSİZ: setnull tetikleyici slaytının kod metni karelerde yakalanmadı; tablo adı ve koşul altyazıdan. -->

### 12.4 Örnek: `credits_earned` tetikleyicisi

Slayttaki örnek (ekrandan, 02:25:00):

```sql
create trigger credits_earned after update of takes on (grade)
referencing new row as nrow
referencing old row as orow
for each row
when nrow.grade <> 'F' and nrow.grade is not null
   and (orow.grade = 'F' or orow.grade is null)
begin atomic
    update student
    set tot_cred= tot_cred +
        (select credits
         from course
         where course.course_id= nrow.course_id)
    where student.id = nrow.id;
end;
```

Tetikleyici `takes` tablosundaki `grade` güncellemelerinde çalışır. Satırın eski hali `orow`, yeni hali `nrow` diye adlandırılır. Her güncellenen kayıt için koşul denetlenir: yeni not `'F'` değil ve null değil, eski not ise `'F'` ya da null. Koşul sağlanırsa `student` tablosunda o öğrencinin toplam kredisi, `course` tablosundan bulunan o dersin kredisi kadar artırılır. Böylece öğrenci dönem dönem ders alıp notları girildikçe, kalınmadığı sürece kazanılan krediler toplanır.

Ders sonrası doğrulama (ara adım eklendi): mantık SQLite sözdizimine uyarlanıp (`NEW`/`OLD` ile) Python'un sqlite3 modülüyle denendi. Bir öğrencinin 4 kredilik bir dersteki notu null'dan `'A'`ya, 3 kredilik bir dersteki notu `'F'`den `'B'`ye güncellendi; toplam kredi $0 + 4 + 3 = 7$ oldu. Ardından ilk dersin notu `'A'`dan `'A+'`ya değiştirildi; eski not ne `'F'` ne null olduğu için koşul sağlanmadı ve toplam 7'de kaldı.

Tetikleyici `delete` ya da `insert` üzerine de tanımlanabilirdi. Satır düzeyi yerine ifade düzeyinde de yazılabilir: bunun için `for each row` yerine `for each statement` kullanılır.

### 12.5 Tetikleyicilerin maliyeti ve riskleri

Tetikleyiciler bazı açılardan çok kullanışlıdır, çünkü logları başka türlü tutmak ya da ayrıntılı doğrulama yapmak mümkün olmayabilir. Ama her zaman kullanmak doğru değildir:

- **Performans:** Tetikleyici her işlemde arka planda çalışır; uygulama tarafından tabloda tetikleyici olup olmadığı bilinmez. İşlemler yavaş gerçekleşiyorsa sebeplerden biri tetikleyici olabilir. Gerekli değilse kullanılmamalı; veri doğrulama bazen uygulamaya alınabilir.
- **Özet veriler:** Özet verileri tabloda sürekli güncellemek doğru olmayabilir; toplam krediler için bir materialized view oluşturmak daha mantıklı olabilir.
- **İstenmeyen çalışma:** Slayttaki örnekler (ekrandan, 02:30:00): yedekten veri yükleme, uzak bir sitede güncellemeleri çoğaltma. Bu tür işlemlerden önce tetikleyici çalışması devre dışı bırakılabilir. Hoca toplu yükleme (bulk load/insert) ve toplu silme öncesinde de tetikleyicilerin durdurulmasını önerdi.
- **Diğer riskler (slayttan):** tetikleyiciyi başlatan kritik transaction'ların hata nedeniyle başarısız olması; zincirleme (cascading) çalışma. Hoca zincirleme çalışmayı açtı: bir tablodaki tetikleyici başka bir tabloya ekleme yapar, oradaki tetikleyici de başka birine; işlemler birbirini tetikleyerek tekrar tekrar çalışabilir, tabloları kilitleyebilir (deadlock) ve istenmeyen çoklu değişikliklere yol açabilir.
- **Bakım:** Tetikleyicinin olup olmadığını bilmenin tek yolu tablonun altına gidip bakmaktır; çok sayıda tablo ve tetikleyici varken unutulabilir.

> **Hocanın vurgusu:** Tetikleyicilerin kullanıldığı yerler vardır ama kullanırken çok çok dikkatli olmak gerekir.

### 12.6 İleri konulara kısa bakış

Hoca dersin sonunda işlenmeyen ileri konulara kısaca değindi: SQL'de yinelemeli döngü doğrudan kurulamaz; bunun için özyinelemeli sorgular ve imleç yapısı kullanılabilir. Sorguları sıralamak için de `rank() over (...)` biçiminde bir sıralama (ranking) yapısı vardır. Hoca özellikle sıralama ve imleç yapısına öğrencilerin kendilerinin bakmasını önerdi.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:04:28): SQL neden bir prosedürel programlama dili olarak kabul edilmez? Java veya Python'daki hangi özelliklere sahip değildir?

> **Cevap (derste verildi):** SQL bildirimseldir. Döngü, değişken üzerinde adım adım işlem, kullanıcıdan girdi alma, ekrana yazdırma, arayüz gibi yetenekleri yoktur. Bu yüzden bir host programlama dilinin içinden kullanılır.

**Soru 2** (derste sözlü, 00:08:10): Bir uygulama (web sitesi, mobil uygulama, tablolama programı) veritabanına hangi yollarla erişebilir?

> **Cevap (derste verildi):** İki yolla: bir sürücü/bağdaştırıcı API'si (JDBC, ODBC) ya da gömülü SQL.

**Soru 3** (derste sözlü, 00:29:48): Sorguyu JDBC `Statement` içinde string olarak yazmanın sorunları nelerdir?

> **Cevap (derste verildi):** Sorgu hataları derlemede değil çalışma zamanında ortaya çıkar; SQL injection riski vardır; sorgu her seferinde yeniden kurulduğu için önbellekleme ve optimizasyon yapılamaz, performans düşer.

**Soru 4** (ekrandan, 00:40:00): Sorgu `"select * from instructor where name = '" + name + "'"` biçiminde kuruluyor. Kullanıcı ad yerine `X' or 'Y' = 'Y` girerse ne olur? Bu sorguda başka ne yanlıştır?

> **Cevap (derste verildi):** Sorgu `select * from instructor where name = 'X' or 'Y' = 'Y'` olur; koşul her zaman doğru olduğu için tablodaki bütün satırlar döner. `X'; update instructor set salary = salary + 10000; --` gibi bir girdiyle ek komut da çalıştırılabilir. Çözüm prepared statement ya da saklı yordamdır. Ayrıca `select *` kullanımı yanlıştır; kolon adları yazılmalıdır.

**Soru 5** (derste sözlü, 00:45:05): Metadata sorgulamak hangi açıdan anlamlı olabilir?

> **Cevap (derste verildi):** Hata ayıklamada ve özellikle veritabanı şeması uygulamanın bilgisi dışında değiştiğinde (kolon silinmesi, tablo değişikliği) ortaya çıkacak kırılmaları önceden yakalamakta. Bunun her işlemde ek bağlantı maliyeti vardır.

**Soru 6** (derste sözlü, 01:04:53): `getPrimaryKeys` ile alınan birincil anahtar bilgisi hangi amaçla kullanılabilir?

> **Cevap (derste verildi):** Birincil anahtar kolonunun olup olmadığını öğrenmek, otomatik artan anahtarda `insert` sırasında değer vermemek, bileşik anahtarın hangi kolonlardan oluştuğunu görmek, sorguları indeksli anahtar kolonlar üzerinden yazarak hız kazanmak.

**Soru 7** (derste sözlü, 01:08:04): Transaction neden gerekir? JDBC'de bunun için ne yapılmalıdır?

> **Cevap (derste verildi):** Birden çok işlemin atomik olarak, ya hep ya hiç biçiminde yapılması için (para transferi, müşteri ile ürününün birlikte eklenmesi). JDBC'de varsayılan otomatik commit `conn.setAutoCommit(false)` ile kapatılır ve işlemlerin sonunda `conn.commit()` ya da `conn.rollback()` çağrılır.

**Soru 8** (derste sözlü, 01:13:42): `CallableStatement` ile saklı yordam çağrıldığında neden SQL injection olmaz?

> **Cevap (derste verildi):** Parametreler uygulama tarafında tipli `set...` metotlarıyla verilir ve yordamın parametre tipleri SQL tarafında da tanımlıdır; çift taraflı tip denetimi yapılır, uymayan girdi hata verir.

**Soru 9** (derste sözlü, 01:16:20): BLOB ile CLOB arasındaki fark nedir? Hangi veriler BLOB olarak tutulur?

> **Cevap (derste verildi):** BLOB ikili veri, CLOB karakter verisi tutar. Resim, ses ve video BLOB olarak; kullanıcı yorumları, gönderiler, web sayfası içerikleri gibi uzun metinler CLOB olarak tutulur.

**Soru 10** (derste sözlü, 02:10:58): Saklı yordamların avantajları ve dezavantajları nelerdir?

> **Cevap (derste verildi):** Avantajlar: SQL injection'a karşı tip ve boyut denetimi, DBA ile geliştirici arasında iş bölümü, tek noktadan güncelleme (uygulamaları yeniden derleyip dağıtmadan), yürütme planının önbelleğe alınmasıyla performans. Dezavantajlar: tablonun içinde görünmediği için unutulabilir; çok basit ya da az kullanılan uygulamalarda yazma maliyetine değmeyebilir.

**Soru 11** (derste sözlü, 02:19:20): Assertion ne için kullanılırdı? Tetikleyici ne işe yarar?

> **Cevap (derste verildi):** Assertion, bir işlemin yapılabilmesi için belli bir koşulun sağlanıp sağlanmadığını denetler (doğrulama). Tetikleyici de doğrulama için kullanılır, ama ayrıca `insert`/`update`/`delete` sırasında otomatik çalışarak log tutma, denetim ve türetilmiş değerleri güncel tutma gibi daha karmaşık işler yapar.

## Dersin Toparlaması

Bu derste SQL'in bildirimsel yapısı nedeniyle tek başına uygulama geliştirmeye yetmediği, bu yüzden bir host dilin içinden kullanıldığı görüldü. Host dilin veritabanına iki erişim yolu ayrıntılı işlendi. Birincisi sürücü/API yaklaşımıdır: JDBC'de bağlantı, ifade, çalıştırma ve sonuç kümesi adımları; metadata sorgulama; otomatik commit'in kapatılarak transaction denetimi; `CallableStatement` ile fonksiyon/yordam çağırma; BLOB/CLOB ile büyük nesneler. ODBC de bunun dil bağımsız standart karşılığıdır. İkincisi gömülü SQL'dir: SQLJ ve `EXEC SQL` ile yazılan sorgular derleme zamanında denetlenir, sonuçlar imleçlerle satır satır işlenir. Dersin en çok vurgulanan noktası, kullanıcı girdisinin string birleştirmeyle sorguya gömülmesinin SQL injection'a yol açtığı ve bunun yerine prepared statement ya da saklı yordam kullanılması gerektiğiydi.

Dersin ikinci yarısında veritabanında nesne olarak tutulan kullanıcı tanımlı fonksiyonlar (skaler `dept_count` ve tablo döndüren fonksiyonlar), saklı yordamlar ve bunların güvenlik, iş bölümü, tek noktadan bakım ve performans avantajları işlendi. Son olarak tetikleyicilerin tanımı, eski/yeni satıra erişim, `credits_earned` örneği ve performans, görünmezlik, istenmeyen ya da zincirleme çalışma gibi riskleri anlatıldı. Özyinelemeli sorgular ve sıralama (ranking) ileri konular olarak bırakıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
