# Ders 8 Lab Çalışma Özeti

## Genel Konular

- Aggregate Fonksiyonların Tekrarı
  - AVG, MAX, MIN, SUM, COUNT gibi fonksiyonlar gruplama sonrasında kullanılır
  - GROUP BY ile gruplama yapıldıktan sonra belli bir grup altındaki toplam, ortalama, sıralama, sayma işlemleri yapılır
  - HAVING ifadesi aggregate fonksiyonlarla birlikte filtreleme için kullanılır; WHERE içinde aggregate fonksiyon kullanımı yasaktır
  - HAVING tek başına kullanılamaz, mutlaka GROUP BY ile birlikte gelir
  - ORDER BY ile alfabetik sıralama (A'dan Z'ye veya DESC ile Z'den A'ya) yapılır

- JDBC (Java Database Connectivity)
  - Java uygulamalarından veritabanına bağlantıyı sağlayan arayüz
  - PostgreSQL için uygun JDBC sürücüsü (JAR dosyası) indirilir ve projeye eklenir
  - Eclipse'te Properties > Build Path > Libraries > Add External JARs ile sürücü projeye dahil edilir
  - `import java.sql.*` ile tüm JDBC sınıfları ve metotları kullanıma açılır

- JDBC Bağlantı Adımları (3 Temel Nesne)
  - **Connection**: DriverManager.getConnection() ile veritabanına bağlantı kurulur; URL formatı: `jdbc:postgresql://localhost:5432/veritabaniadi`
  - **Statement**: Bağlantı üzerinden sorgu hazırlamak için createStatement() ile oluşturulur
  - **ResultSet**: Statement.executeQuery() ile çalıştırılan sorgunun sonuçlarını tutar; .next() ile satır satır okunur

- Statement vs PreparedStatement Farkı
  - Statement: Her executeQuery çağrısında sorgu tekrar gönderilir, sentaks kontrolünden geçer, çalıştırılır
  - PreparedStatement: Önce sorgu hazırlanır (sentaks kontrolü bir kez yapılır), ardından parametrelerle çalıştırılır
  - PreparedStatement tekrar eden sorgularda performans açısından daha avantajlıdır
  - Kullanıcıdan veri alırken `?` soru işareti kullanılır, setString/setInt ile değerler atanır

- DML İşlemleri ve Execute Türleri
  - SELECT sorguları için executeQuery() kullanılır
  - INSERT, UPDATE, DELETE gibi DML komutları için executeUpdate() kullanılır
  - Commit işlemi: Varsayılan olarak autocommit açıktır; birden fazla işlemi bir arada commit etmek için autocommit false yapılır, ardından manual commit yapılır

- SQL Exception Yönetimi
  - Bağlantı hataları, yanlış şifre, olmayan tablo gibi.runtime hataları için SQLException fırlatılır
  - Try-catch bloğu ile hata yakalanır; derleyici hata vermese bile bağlantı sırasında oluşabilecek hatalar böyle yakalanır
  - Java'da compile-time'da anlaşılamayan hatalar (yanlış şifre vb.) için exception mekanizması zorunludur

## Hocanın Özellikle Vurguladığı Kısımlar

- HAVING kullanırken mutlaka GROUP BY olması gerektiği ve tek başına kullanılamayacağı vurgulandı
- Aggregate fonksiyonların WHERE koşulu içinde kullanılamayacağı, bunun için HAVING'in gerektiği belirtildi
- PreparedStatement'ın tekrar eden sorgularda neden daha verimli olduğu detaylı açıklandı: sentaks kontrolü bir kez yapılır, preparesiz her seferinde tekrar kontrol edilir
- Bağlantı kurulurken URL'nin doğru yazılmasının önemi (localhost, port, veritabanı adı, kullanıcı adı, şifre)
- Result Set'te sütunlara hem indeks numarası ile hem de sütun adı ile erişilebileceği gösterildi
- INSERT sorgularında hangi sütunlara ekleme yapılacağını belirtmenin önemi vurgulandı (belirtilmezse tüm sütunlara ekler)
- ResultSet'te tek satır geleceği durumlarda if ile kontrol edilmesi, birden fazla satır geleceği durumlarda while döngüsü kullanılması gerektiği gösterildi
- Statement ve PreparedStatement nesnelerinin işlem sonunda kapatılması gerektiği belirtildi
- Autocommit mekanizması ve manual commit yapma ihtiyacı açıklandı

## Kısa Notlar

- Company DB tabloları: employee, department, dept_locations, project, works_on, dependent olmak üzere 6 tablo
- ESSN (Social Security Number) employee tablosunda kişisel kimlik numarasıdır
- PNumber proje numarasıdır, works_on tablosunda proje ile çalışan arasındaki ilişkiyi tutar
- DNumber departman numarasıdır, hem employee hem department tablolarında bulunur
- JFrame > JPanel > Components (JButton, JTextField, JLabel, JTable) Java GUI hiyerarşisi
- JTable göstermek için DefaultTableModel oluşturulur, JScrollPane içine yerleştirilir
- Scanner sınıfı ile konsoldan kullanıcı girişi alınır
- JOptionPane.showInputDialog ile GUI üzerinden kullanıcı girişi alınabilir

## Detaylı Açıklamalar

- **JDBC Bağlantı Kurulumu**: Bir Java uygulamasından veritabanına bağlanmak için öncelikle uygun JDBC sürücüsü (PostgreSQL için postgresql-xx.x.x.jar) projeye eklenir. Ardından `DriverManager.getConnection("jdbc:postgresql://localhost:5432/companydb", "postgres", "sifre")` çağrısı ile bağlantı nesnesi oluşturulur. Bu bağlantı nesnesi üzerinden Statement veya PreparedStatement oluşturularak sorgular çalıştırılır.

- **PreparedStatement Kullanımı ve Parametre Bağlama**: Kullanıcıdan veri alırken sorguda `?` soru işareti bırakılır. `p.setString(1, deger)` ile birinci bilinmeyene değer atanır. Birden fazla soru işareti varsa sırayla setString, setInt vb. metodlarıyla değerler bağlanır. Bu yöntem hem performans hem de SQL injection güvenliği açısından tercih edilir.

- **ResultSet Okuma Yöntemleri**: Sorgu sonucu ResultSet nesnesine atanır. `.next()` metodu bir sonraki satıra geçer ve boolean değer döndürür. Veriler `r.getString(1)` veya `r.getString("fname")` şeklinde hem indeks hem de sütun adı ile okunabilir. Sayısal değerler için `r.getInt()`, `r.getDouble()` kullanılır.

- **Form Uygulaması Örneği**: Bir departman numarası girilerek o departmandaki çalışanların listelendiği,_departman bilgilerinin gösterildiği ve yeni çalışan eklenebilen bir GUI uygulaması gösterildi. Arka planda iki farklı sorgu çalıştı: çalışan listesini çekmek için employee tablosundan basit bir SELECT, departman ve yönetici bilgisi için department-employee join sorgusu. Çalışan ekleme işleminde INSERT INTO sorgusu executeUpdate ile çalıştırıldı ve commit edildi.

- **Commit ve Autocommit**: Varsayılan olarak her executeUpdate sonrasında değişiklikler otomatik commit edilir. Ancak birden fazla DML işlemini bir arada çalıştırıp tek seferde commit etmek istenirse `connection.setAutoCommit(false)` yapılarak autocommit kapatılır, işlemler tamamlandıktan sonra `connection.commit()` ile manuel commit yapılır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
