# Ders 4 Genişletilmiş Notu: JDBC, Dinamik ve Gömülü SQL, Fonksiyonlar, Prosedürler ve Tetikleyiciler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. SQL'in Sınırları: Neden Bir Programlama Diline İhtiyaç Var?
- 2. Programdan Veritabanına Erişimin İki Yolu: Dinamik SQL ve Gömülü SQL
- 3. JDBC: Bağlantı, İfade ve Sonuç Kümesi
- 4. Empedans Uyumsuzluğu
- 5. Hazır İfade (PreparedStatement)
- 6. SQL Enjeksiyonu
- 7. Metadata, İşlemler ve Prosedür Çağırma
- 8. ODBC, Gömülü SQL ve Gömülü Veritabanları
- 9. Fonksiyonlar ve Prosedürler
- 10. Harici Dilde Yazılmış Rutinler
- 11. Tetikleyiciler (Triggers)
- Örnek Sorular

Dersin slaytları Silberschatz, Korth ve Sudarshan'ın *Database System Concepts* (7. baskı) kitabının 5. bölümüdür ("Advanced SQL") (ekrandan, 00:10:00).

## 1. SQL'in Sınırları: Neden Bir Programlama Diline İhtiyaç Var?

Hoca derse, şimdiye kadar konsolda yazdığımız SQL'in neyi yapıp neyi yapamadığını sorarak başladı. SQL bildirimsel (declarative) bir dildir. Kullanıcı yalnız sorguyu yazar; sistemin fiziksel kaynakları nasıl kullanacağı oldukça karmaşıktır, optimize edilmiştir ve kullanıcıdan bağımsızdır. Buna fiziksel bağımsızlık (physical independence) denir.

Bu yapı bir kısıtlama da getirir. Sorguyla yapabileceğimiz şeyler bellidir: Analitik bir düşünceyle bir şeyi ararız, sorgularız. Ama örneğin kullanıcıdan bir girdi alıp programın akışını dinamik olarak değiştiremeyiz; bu tipik bir prosedürel dil özelliğidir. Bir yere mesaj gönderemez, çıktı basamayız. Slaytta SQL'in genel amaçlı bir dilin ifade gücüne sahip olmadığı söyleniyor ve Fibonacci dizisinin ilk 10 teriminin hesaplanması örnek veriliyordu. Prosedürel bir dilde çok kolay yazılıp hızlı çalışacak böyle şeyleri SQL ile yazmak çok zor, belki de imkânsızdır.

> **Ders sonrası not:** Hoca Fibonacci dizisini "ilk 10 sayının toplamı" diye tarif etti. Doğrusu: Fibonacci dizisinde her terim kendinden önceki iki terimin toplamıdır (1, 1, 2, 3, 5, 8, ...).

İstatistikte de durum aynıdır. SQL'de gruplama ve grup içi toplama fonksiyonları gibi basit istatistikler yapılabilir, ama karmaşık istatistiksel analizler desteklenmez. O zaman veriyi veritabanından çekip daha güçlü bir programlama dilinde işlemek gerekir.

Hoca, recursive sorgular, window sorguları ve rank sorgularının da önemli olduğunu, bunların bu derste ayrıntılı işlenmeyeceğini, seçmeli derslerde bu eksikliğin giderilebileceğini söyledi.

## 2. Programdan Veritabanına Erişimin İki Yolu: Dinamik SQL ve Gömülü SQL

Programlar host dil (host language) denilen Java, C, C++, Python gibi dillerde yazılır ve veritabanına erişir. Laboratuvarda pgAdmin gibi bir arayüzle konsoldan bağlanırken arayüz kendi protokolüyle bağlanır. Bir Java ya da C programından bağlanmak içinse bir sürücüye (driver) ihtiyaç vardır. Sürücü programlama diline göre değişir: Java için JDBC (Java Database Connectivity), C için ODBC, Python için ayrı bir kütüphane.

Erişimde iki temel yaklaşım vardır (ekrandan, 00:10:00):

- **Dinamik SQL (dynamic SQL):** Program sürücüyü içe aktarır (Java'da import, C'de include) ve SQL'i çalışma zamanında bir string olarak kurup veritabanına gönderir.
- **Gömülü SQL (embedded SQL, statik SQL):** SQL ifadeleri program içine string olarak değil, özel işaretlerle gömülür. Program derlenirken SQL'ler de derlenir; çalışma zamanına geçildiğinde SQL'ler artık bellidir.

Slayttaki karşılaştırma şöyledir:

| Dinamik SQL | Gömülü (statik) SQL |
|---|---|
| SQL çalışma zamanında bir string içinde kurulur ve gönderilir | SQL derleme zamanında fonksiyon çağrılarına çevrilir |
| Esnek uygulamalara imkân verir | Çalışma zamanında değiştirilemez, daha az esnektir, hata ayıklaması zordur |
| Daha az verimlidir; erişim planları çalışma zamanında üretilir (PreparedStatement kullanılsa bile) | Daha verimli çalışır |
| Daha fazla güvenlik riski | Daha güvenli |
| JDBC, ODBC, ADO.NET | Embedded C, SQLJ |

Dinamik SQL'in az verimli olmasının nedeni şudur: Program derlendiğinde string içindeki SQL derlenmez. SQL veritabanına gittiğinde orada derlenir; veritabanı açısından derleme, sorgunun optimize edilmesi demektir. Sorgu optimizasyonu, veritabanı tarihi boyunca SQL ve NoSQL sistemlerin merkezinde duran zor bir konudur. Çalışma zamanında birden ortaya çıkan sorguların veritabanında derlenmesi programı biraz yavaşlatır.

Güvenlik riski ise programın çalışma zamanında dışarıdan gelen komutlara açık olmasıdır; bu komutlar zarar verebilir. Gömülü SQL'de SQL ifadeleri program içinde gömülüdür ve ne oldukları bellidir. Derleme zamanında fonksiyon çağrılarına dönüştürülürler; çalışma zamanında bu çağrılar arkada dinamik SQL olanakları sağlayan bir API ile veritabanına bağlanır. Hoca bunu dinamik SQL'in üzerindeki bir ambalaj gibi düşünmeyi önerdi.

Hoca bu karşılaştırmanın ilk anda soyut kalacağını, bu yorumların ancak birkaç ay gömülü SQL ve JDBC ile program yazdıktan sonra tam hazmedileceğini söyledi. Günümüzde, güvenlik açıkları olsa ve biraz yavaş olsa da esnekliği nedeniyle JDBC ve ODBC gibi dinamik yöntemler daha yaygındır. Dinamik SQL'i daha verimli kılmak için hazır ifade (prepared statement) kullanılır; bu Java'da, ODBC'de ve Python'da vardır.

**Soru:** (Veri büyüklüğüyle ilgili bir öğrenci sorusu; altyazıda sorunun kendisi duyulmuyor.) **Cevap:** Burada veri miktarından çok host program tarafındayız. Veriyi az ya da çok çekeceğiz ve bir web uygulaması, stok takibi gibi bir programda işleyeceğiz. Esneklikten ve verimlilikten bahsederken veritabanı tarafından değil, host program tarafından bahsediyoruz.

<!-- BELİRSİZ: 00:21:55 civarındaki öğrenci sorusunun metni altyazıda yok, yalnız hocanın cevabı var. -->

## 3. JDBC: Bağlantı, İfade ve Sonuç Kümesi

JDBC bir protokol ve standarttır; aynı zamanda bir API'dir, yani karmaşık bir sisteme bağlanıp iş yapabilmemiz için bir arayüzdür. Her üretici (Oracle, MS SQL Server, PostgreSQL) bu protokoldeki bilinen nesne ve işlemleri kendi iç işlemlerine dönüştüren bir sürücü yayımlar. Program standart JDBC çağrılarını kullanır; Oracle sürücüsü yüklüyse bu çağrılar Oracle'a özgü iç işlemlere çevrilir.

Nesneye yönelik bir dil olduğu için Java'da işler nesnelerle yapılır:

- `Connection` ile bağlantı açılır.
- `Statement` ile bir ifade oluşturulup çalıştırılır.
- Sorgunun sonucu `ResultSet` nesnesi olarak gelir.
- Sorguda ne geleceği bilinmiyorsa sonucun şeması `ResultSetMetaData` ile öğrenilir.
- Hatalar `SQLException` ile yakalanır; dönen kodlarla ağ hatası, veritabanı iç hatası ya da SQL sözdizimi hatası ayırt edilebilir.

### 3.1 Bağlantının açılması ve try-with-resources

Slayttaki örnek (ekrandan, 00:26:30):

```java
public static void JDBCexample(String dbid, String userid, String passwd)
{
    try (Connection conn = DriverManager.getConnection(
             "jdbc:oracle:thin:@db.yale.edu:2000:univdb", userid, passwd);
         Statement stmt = conn.createStatement();
        )
    {
        ... Do Actual Work ....
    }
    catch (SQLException sqle) {
        System.out.println("SQLException : " + sqle);
    }
}
```

URL'deki `db.yale.edu` bağlanılan makinedir; 2000 o makinenin dış dünyaya açılan port numarasıdır. O portta hangi veritabanı sunucusu dinliyorsa (Oracle ya da PostgreSQL) bağlantıyı o karşılar ve içindeki `univdb` veritabanına bağlanılır. `thin`, Oracle sürücüsünün birkaç bağlantı modundan biridir. Bu modlar arasında programda neler yapılabileceği, güvenlik açıkları, kaynak kullanımı, çoklu iş parçacığı gibi farklar vardır; ayrıntısına girilmedi.

Bağlanan kişi kullanıcı adı ve parolayla bağlanır. Hoca, parolanın programa açıkça yazılmasının güvenlik açısından akıllıca olmadığını, ortam değişkenleri gibi daha güvenli yolların araştırılması gerektiğini söyledi.

Bu örnekte bağlantının kapatıldığı bir satır yoktur. Oysa bağlantı açıldığında sistem kaynakları ona tahsis edilir: Gelen sorgu derlenecek, tamponlar ve bellek kullanılacaktır. Eski JDBC sürümlerinde sürücü önce elle yüklenir, iş bitince `stmt.close()` ve `conn.close()` çağrılırdı. Sorun şudur: Arada ağda, veritabanında ya da programın mantıksal akışında bir arıza olursa akış `catch` bloğuna atlar ve bağlantı kapatılamaz. Kaynak, bir zaman aşımı eşiğine kadar boşa tutulur; oysa sistemi birçok kişi kullanır ve kaynak kıymetlidir.

Java 7 ve JDBC 4 ile gelen sözdiziminde `try` parantezi içinde açılan kaynaklar (try-with-resources), blok sonunda ne olursa olsun otomatik kapanır. Slayt notunda da bütün kaynakların kapatılmasının kritik olduğu, aksi hâlde veritabanının kaynak havuzlarının tükenebileceği yazıyordu (ekrandan, 00:30:40). Ayrıca yeni sürümlerde sürücü otomatik yüklenir.

> **Ders sonrası not:** Hoca eski sözdiziminin "herhalde 4-5 sene öncesine" ait olduğunu söyledi. Java 7 büyük olasılıkla 2011'de çıktığı için bu, dersin tarihinden on yılı aşkın bir süre öncesidir.

### 3.2 Güncelleme ve sorgu

Slayttaki ikinci kod (ekrandan, 00:39:30):

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

`executeUpdate` içinde insert, update ya da delete olabilir. Dönen değer etkilenen satır sayısıdır: 3 satır eklendiyse 3, 5 satır güncellendiyse 5 döner. Yeni tablo oluşturmak ya da şemayı değiştirmek gibi veri tanımlama (DDL) ifadeleri de gönderilebilir; bu durumda dönen değer 0'dır (slayt notu, ekrandan, 00:39:30). Örnekte dönen sayıya bakılmıyor. SQL burada bir string içinde gönderildiği için bu bir dinamik SQL örneğidir.

`executeQuery` ise bir `ResultSet` döndürür. Sorgu programın içinde sabit yazıldığı için dönecek sütunlar bellidir: bir bölüm adı ve bir sayı. Bu yüzden metadata kullanılmadı; `getString("dept_name")` ile ilk sütun, `getFloat(2)` ile ikinci sütun alındı.

## 4. Empedans Uyumsuzluğu

Hoca burada iki dünyanın çalışma mantığının temelden farklı olduğunu vurguladı. Programlama dilinde bir değer tanımlar, onu bir döngü içinde işleriz; yürütme değer bazlıdır. SQL tarafında ise tablolardan yeni tablolar üretilir, iç içe sorgular vardır; yürütme tablo bazlıdır. Elektrik mühendisliğinden gelen bir kavramla buna empedans uyumsuzluğu (impedance mismatch) denir. Veri tipleri de farklı olabilir: Veritabanından gelen sayısal bir değerin programda hangi tipe (integer, double) dönüşeceği sorusu ortaya çıkar.

JDBC'de bu uyumsuzluk şöyle aşılır: `ResultSet` bize tabloyu doğrudan vermez. Kaç satır geleceği bilinmez; `next()` ile satırlar üzerinde tek tek dolaşılır ve her satırın değerleri `getString`, `getFloat` gibi fonksiyonlarla alınır.

## 5. Hazır İfade (PreparedStatement)

Dinamik SQL'de SQL string içindedir ve veritabanına gittiğinde derlenir. Gerçek uygulamalarda, örneğin bir e-ticaret sitesinde ya da bir form doldurma ekranında, aynı yapıdaki sorgular farklı parametrelerle defalarca gönderilir; üretilen SQL'ler "üç aşağı beş yukarı" bellidir. O zaman ilk sorgu için yapılan derleme veritabanında saklansın, sonraki parametreler aynı derlenmiş şablonla çalışsın. Hazır ifade (prepared statement) bunu yapar ve çok yaygın kullanılır.

Slayttaki örnek (ekrandan, 00:44:40):

```java
PreparedStatement pStmt = conn.prepareStatement(
                              "insert into instructor values(?,?,?,?)");
                              // No execution yet. Only generate access plan.
pStmt.setString(1, "88877");
pStmt.setString(2, "Perry");
pStmt.setString(3, "Finance");
pStmt.setInt(4, 125000);
pStmt.executeUpdate();
pStmt.setString(1, "88878");
pStmt.executeUpdate();    // execute !!
```

Değerlerin yerine `?` konur, gerçek değerler sonra verilir. Hoca, bazı sürücülerin (örneğin Oracle'ın) şablonu daha program çalışırken fark ettirmeden veritabanına gönderip derletebildiğini, bazılarının bunu yapmadığını söyledi. Genel olarak ilk sorgu veritabanına gittiğinde derlenir; sonraki `executeUpdate` çağrılarında yalnız değişen parametre gönderilir ve aynı derleme kararı kullanılır. Özet: "Bir kez derle, çok kez çalıştır" (compile once, execute multiple times).

> **Hocanın vurgusu:** Buradaki derleme programın derlenmesi değildir; program zaten çalışıyordur. Kastedilen, veritabanı tarafındaki derlemedir.

Hoca bir parantez de açtı: Veritabanındaki optimizer 30-40 yıllık bir birikimin ürünüdür ve çok gelişmiştir. Fakat en çok zorlandığı noktalardan biri parametreli sorgulardır. İlk verilen değerlere göre seçilen plan, başka değerler için doğru karar olmayabilir; bu sorun tamamen çözülmüş değildir.

### 5.1 Tırnak sorunu

Hazır ifade kullanılmazsa sorgu, formdan alınan değerler string içine gömülerek kurulur. Geçen hafta insert anlatılırken değerlerin tek tırnak içine yazılması gerektiği vurgulanmıştı (slaytın not kısmında `insert into course ... values ('CS-437', 'Database Systems', 'Comp. Sci.', 4)` örneği ve "tek tırnaklara dikkat" notu görülüyor, ekrandan 00:52:50). O zaman program şöyle bir string kurmak zorunda kalır (ekrandan, 00:44:40):

```java
"insert into instructor values(' " + ID + " ', ' " + name + " ', " +
    " ' " + dept_name + " ', " + balance + ")"
```

Kullanıcı formda `D'Souza` gibi bir İtalyan ya da İspanyol adı girerse, adın içindeki tek tırnak sorgunun tırnaklarıyla karışır ve sorgu hata verir. Kullanıcının tırnağı kaçış karakteriyle yazmasını bekleyemeyiz. `setString` gibi fonksiyonlar bu tırnağı kendileri kaçışlayarak gönderir; iç ayrıntısını bilmesek de sorun böylece çözülür.

## 6. SQL Enjeksiyonu

Hoca, sorgu bir kez derlenip yalnız bir kez çalışacak olsa bile hazır ifadenin yine kullanılması gerektiğini söyledi; nedeni SQL enjeksiyonudur (SQL injection) (ekrandan, 00:52:50).

Sorgu şöyle kurulmuş olsun:

```java
"select * from instructor where name = '" + name + "'"
```

Kullanıcı formda ad yerine şunu yazsın:

```text
X' or 'Y' = 'Y
```

Ortaya çıkan sorgu:

```sql
select * from instructor where name = 'X' or 'Y' = 'Y'
```

Kullanıcı son tırnağı bilerek yazmadı, çünkü programın onu kendisi ekleyeceğini tahmin ediyor. `name = 'X'` koşulu yanlıştır, ama ardından gelen `or 'Y' = 'Y'` her zaman doğrudur. Böylece bütün `instructor` tablosu görüntülenir. Bu yalnız ilk adımdır: Ad yazılması gereken yere başka SQL yazılarak bir tablo silinebilir. Program dış dünyaya açıldığında kullanıcılar programın yetkileriyle veritabanına bağlanırlar; program veritabanında ne yapabiliyorsa enjeksiyonla onlar da yapabilir.

Daha yıkıcı bir örnek de slaytta vardı:

```text
X'; update instructor set salary = salary + 10000; --
```

Burada ilk tırnak kapatılır, noktalı virgülle ifade bitirilir ve herkesin maaşını 10000 artıran bir update çalıştırılır. Sondaki `--` ise programın ekleyeceği son tırnağı yorum satırına çevirir; yoksa sorgu sözdizimi hatası verir ve çalışmazdı. Konsolda da birden çok SQL'i noktalı virgüllerle ayırıp bir işlem (begin-end) içinde çalıştırabildiğimizi hatırlayalım. Hoca, çoğu JDBC sürücüsünde tek çağrıda birden çok ifade çalıştırmanın varsayılan olarak kapalı olduğunu, ama bir sebeple açılmış olabileceğini, açıksa bu tür yıkıcı saldırıların mümkün olduğunu söyledi.

Hazır ifade sorgu yapısını veriden ayırır. `setString` tırnakları yakalar ve kaçışlar; aranan ad gerçekten `X' or 'Y' = 'Y` metni olur ve koşul yanlış çıkar. Slayttaki son uyarı: Gerçek dünyada SQL enjeksiyonuyla birçok saldırı yapılmış, birden çok finans sitesinden büyük miktarda para çalınmıştır. Hoca konunun daha ayrıntılı araştırılmasını, slaytların altındaki açıklamaların okunmasını önerdi.

## 7. Metadata, İşlemler ve Prosedür Çağırma

### 7.1 ResultSetMetaData

Dinamik olarak ortaya çıkan bir sorgunun ne döndüreceği bilinmez. Bu bilgi `ResultSetMetaData` nesnesindedir: sütun sayısı, sütun adları ve tipleri öğrenilir, sonra satırlar buna göre dolaşılır. Önceki örnekte sorgu bilindiği için buna gerek olmamıştı. Metadata özellikle pgAdmin ya da veritabanı tarayıcıları gibi genel araçlarda kullanılır. Slayta göre metadata, kullanıcının veritabanındaki tabloları bulmasını, şemayı incelemesini, satırlara bakıp seçim uygulamasını sağlayan bir veritabanı tarayıcısı yazmak için kullanılabilir ve kodu genel (generic) yapar. Benzer şekilde bir tablonun birincil anahtarı ve yabancı anahtarları da metadata fonksiyonlarıyla öğrenilebilir.

### 7.2 JDBC ile işlemler

JDBC ile host programdan işlemler (transaction) yürütülebilir: Bağlantı üzerinden otomatik commit ayarlanabilir, commit ve rollback yapılabilir, yalıtım seviyesi belirlenebilir. Hoca işlem kavramını hatırlattı: Bir işlem, bütünlük gerektiren bir veya daha çok veritabanı eylemidir. Burada asıl önemli olan select değil, update eylemleridir. Ya hepsi olacak ya hiçbiri; işlem yarıda kalırsa anlamını kaybeder.

**Soru:** Hoca "Transaction neden bir bütünlük gerektirir, örnek verebilecek olan var mı?" diye sordu. Bir öğrenci banka para transferi örneğini verdi (cevabın ayrıntısı altyazıda yok). **Cevap:** Hoca örneği doğru buldu ve şöyle genişletti: Tek bir işlem, tek kullanıcıda bile bütünlük gerektirir. Bir hesaptan 100 lira düşülüp diğerine eklenecekse bu iki güncelleme aynı anda yapılamaz, sırayla yapılır. Arada bir veritabanı iç hatası, ağ hatası ya da donanım hatası olursa 100 lira kaybolur. Ayrıca güncelleme sırasındaki tutarsız durum, yani paranın bir hesaptan düşülüp henüz diğerine eklenmediği an, dış dünyaya, diğer programlara görünmemelidir.

Bu gereksinimler ACID özellikleridir. Eş zamanlı çalışmada işlemlerin birbirinden yalıtılması gerekir (I, isolation). Değişiklikler önce ana bellekte yapılır, kalıcı bir yer olan diske ulaşmaları gerekir (D, durability). Hoca, bunların sistem gerçekleme dersinde ayrıntılı işlendiğini, ama bu dersi almayanların da işlem deyince bu kavramları bilmesi gerektiğini söyledi.

JDBC'de bağlantının yalıtım seviyesi read uncommitted, read committed, repeatable read ya da serializable olarak ayarlanabilir. Web uygulamalarında çoğu zaman read committed kullanılır; bu bir gevşekliktir, işlemler iç içe geçebilir. Hocanın örneği uçak koltuğu rezervasyonuydu: Son birkaç koltuk kalmıştır ve birçok kullanıcı aynı anda almaya çalışır. Üniversitede ders seçiminin açıldığı an ya da sepete konan ürünün onay sırasında "stokta kalmadı" çıkması da aynı durumdur. Son koltuğu herkes görür, biri alır, diğeri aldığını sanar ama onay aşamasında alamaz. Yalıtım seviyesi daha katı olsaydı, biri koltuğu tutmuş gibi göründüğü sürece diğerleri alamaz, ilk kişi vazgeçerse koltuk satılamayabilirdi. Bu yüzden yalıtım seviyesi stratejik olarak ayarlanır ve bu ayar bağlantı sırasında yapılabilir.

### 7.3 Fonksiyon ve prosedür çağırma

JDBC'den veritabanındaki fonksiyon ve prosedürler de çağrılabilir: Bağlantı üzerinden `prepareCall` çalıştırılır ve fonksiyonun parametreleri verilir. Bu, hazır ifadenin bir başka biçimidir; sorgu yerine parametreli bir fonksiyon çalıştırılır. Hoca, JDBC ve stored procedure'lerin endüstride çok iş döndüğü, kendi başına ayrı bir kurs olacak kadar geniş konular olduğunu söyledi.

## 8. ODBC, Gömülü SQL ve Gömülü Veritabanları

Java içine SQL gömüldüğünde buna SQLJ denir; bu statik SQL'dir. SQL'ler program derlenirken derlenir ve arkada dinamik SQL kütüphaneleriyle veritabanına bağlanılır. Kod içinde `#sql` işaretiyle başlayan bölgelerde SQL ifadeleri görülür. Çalışma zamanında SQL alınmadığı için esnek değildir ama her şey derlendiği için daha verimlidir. Hata ayıklamak zordur: Program içinde farklı malzemeler vardır ve SQL bölgesi sıradan bir debugger ile izlenemez.

> **Ders sonrası not:** Hoca SQLJ'yi anlatırken bir an "SQL'ler runtime'da compile ediliyor" dedi, hemen ardından program derlenirken derlendiğini söyledi. Doğrusu ikincisidir: Gömülü SQL'de ifadeler derleme zamanında çevrilir.

ODBC'de de kavramlar aynıdır: bağlantı açılır, ifade ve sorgular gönderilir, sonuçlar alınır. Hoca, C tarzı dillerle çalışanların JDBC'den çok ODBC'yi öğrenmesi gerektiğini söyledi. C kodu içine gömülü SQL'de de benzer biçimde işaretlenmiş bölgeler ve satırları tek tek almak için `fetch` gibi komutlar vardır; kavramlar aynı, gramer farklıdır.

Son zamanlarda yaygınlaşan bir başka yaklaşım gömülü veritabanıdır (embedded database). İstemci-sunucu mimarisi yoktur; uygulama, veritabanının sağladığı API ile sorgu çalıştırma, ekleme, güncelleme gibi işlemleri doğrudan yapar. JDBC gibi bir köprü olmadığı için çok daha hızlıdır; uygulama adeta veritabanının modüllerinin (optimizer, B+ ağacı vb.) içindedir. Örnekler: 2000'lerden beri kullanılan, dağıtık olmayan bir anahtar-değer deposu olan Oracle Berkeley DB; NoSQL tarzında LevelDB; MySQL'in gömülü sürümü; SQLite; Java DB.

## 9. Fonksiyonlar ve Prosedürler

Hoca bu konuda laboratuvarda birkaç hafta çalışma yapılacağını söyledi. Slayttaki temel avantaj ve dezavantaj şöyledir (ekrandan, 01:40:40):

- **Temel avantaj:** İş kuralları için tek bir değişiklik noktası sağlar (allows a single point of change for business rules).
- **Temel dezavantaj:** Yüksek düzeyde optimize edilmiş yerleşik fonksiyonlara göre optimizasyon ve paralellik eksikliği.

İş kuralı (business rule), modellenen küçük dünyaya özgü bir kuraldır. Hocanın örneği: Üniversite veritabanında bir öğrenci, ön koşul dersini almamış ya da geçmemişse o dersi alamaz. Bu kural varsayılan kısıtlarla tanımlanamaz, bir fonksiyon yazmak gerekir. Aynı kontrol uygulama seviyesinde, örneğin JDBC programında da yapılabilirdi. Ama birkaç tablo kontrolüyle yapılabilecek basit bir iş merkezde, bir stored procedure ya da tetikleyiciyle yapılırsa birçok uygulama onu kullanır; kural değiştiğinde yalnız bir yer değişir, uygulamalar değişmez.

Veritabanları bu amaçla while ve for döngüleri, değişken ve kayıt (record) tanımlama gibi, çok karmaşık olmayan programlama yapı taşları sağlar. Dezavantaj tarafında: Stored procedure içindeki SQL'ler kolay optimize edilemez ve sistemi hantallaştırır; tetikleyiciler de öyledir ve güvenlik açısından tehlike taşırlar. Tarih ve string işlemleri gibi yerleşik fonksiyonlar sisteme entegre ve çok optimizedir; kullanıcının yazdığı fonksiyonu ise sistem hemen optimize edemez, bunlar darboğaz olur.

Örnek fonksiyon (ekrandan, 01:40:40):

```sql
create function dept_count (dept_name varchar(20))
    returns integer
    begin
    declare d_count integer;
        select count (*) into d_count
        from instructor
        where instructor.dept_name = dept_name
    return d_count;
    end
```

Fonksiyon bölüm adını alıp o bölümdeki hoca sayısını döndürür ve SQL içinde kullanılabilir. Örneğin 12'den fazla hocası olan bölümlerin adı ve bütçesi:

```sql
select dept_name, budget
from department
where dept_count (dept_name) > 12
```

Bir başka dezavantaj: Yazılan stored procedure o veritabanına özgüdür. PostgreSQL'de yazılan bir prosedür Oracle'da kullanılamaz, sözdiziminin çevrilmesi gerekir. Slayttaki kırmızı madde de bunu söylüyordu: En temel prosedürel özelliklerin bile farklı ürünlerde farklı sözdizimi ya da anlamı vardır, programcı her ürün için yeni bir dil öğrenmek zorunda kalır. Hoca, kitabın her bölüm sonundaki alıştırmaların (bir kısmının cevapları da var) çok iyi bir çalışma ortamı olduğunu ekledi.

### 9.1 Tablo fonksiyonları: Parametreli görünüm

SQL standardı sonuç olarak tablo döndüren fonksiyonları destekler; bunlara tablo fonksiyonu (table function) denir. Hocaya göre diğer adı, "parametreli görünüm" (parameterized view), amaca tam hitap eden güzel bir isimdir (ekrandan, 01:42:40):

```sql
create function instructor_of (dept_name char(20))
    returns table (
        ID varchar(5),
        name varchar(20),
        dept_name varchar(20),
        salary numeric(8,2))
return table
    (select ID, name, dept_name, salary
     from instructor
     where instructor.dept_name = instructor_of.dept_name)
```

Kullanımı:

```sql
select *
from table (instructor_of ('Music'))
```

Görünüm bir tanım saklıyordu; kullanıldığında bu tanım açılıp çalıştırılıyordu, ama görünüme parametre verilmiyordu. Tablo fonksiyonunun tanımı da bir görünüm gibidir, fakat parametre alır; iki isim bu yüzden bir araya gelmiştir. Slayta göre tablo fonksiyonları kod modülerliği, sorgu esnekliği ve karmaşık mantığı kapsülleme açısından avantaj sağlar ve parametre aldıkları için dinamik sorgu üretiminde görünümlerden esnektir. Hoca bu yorumların tecrübeyle ortaya çıktığını, bu ders kapsamında somut olarak tam yaşanamayacağını söyledi.

### 9.2 Prosedürler

Değer döndürmeyen, bir işlem yapan rutinlere prosedür denir. Slayttaki örnekte prosedür, fizik bölümündeki hoca sayısını sayıp bir çıkış parametresine (`d_count`) yazar. Prosedür bir şey döndürmediği için SQL içinden doğrudan çağrılamaz, stored function'lar gibi kullanılamaz; dışarıdan çağrılır.

Fonksiyon da olsa prosedür de olsa aynı problemler vardır: Sorgu optimizasyonu ve paralellik. Günümüzde sorguların paralel çalışması ve sorgu içi paralellik (intra-query parallelism) önemli konulardır; geleneksel prosedür ve fonksiyonlarla bunlarda çok zorluk vardır. Bu yüzden prosedür ve fonksiyonlar veritabanlarında yaygın olarak çok elverişli kabul edilen yapılar değildir, yerine göre kullanılır. Slaytlarda while, repeat, for ve if-else blokları da vardı; hoca bunların ayrıntısına girmedi.

## 10. Harici Dilde Yazılmış Rutinler

Prosedürel uzantıların ürüne özgü olması sorununu aşmak için iş kuralını yazan fonksiyon harici bir dilde (C, Python, Java) yazılabilir: harici dil rutinleri (external language routines). Örneğin bir prosedür oluşturulurken dilinin C olduğu ve kaynak kodun yeri belirtilir; arkada kod derlenir ve sanki yerleşik bir fonksiyonmuş gibi veritabanına entegre edilir. Böylece aynı iş kuralı PostgreSQL'de de Oracle'da da kullanılabilir; taşınabilir olur. Bu, makineye daha hâkim olmayı ve daha ileri programlama bilgisi gerektirir.

Slayta göre (ekrandan, 01:49:00):

- **Faydaları:** Birçok işlem için daha verimlidir ve ifade gücü daha yüksektir.
- **Dezavantajları:** Fonksiyonu gerçekleyen kodun veritabanına yüklenmesi ve veritabanının adres alanında çalıştırılması gerekebilir. Bu, veritabanı yapılarının kazara bozulması ve güvenlik riski demektir.
- Daha iyi güvenlik sağlayan alternatifler vardır, ama performans kötüleşebilir. Veritabanının adres alanında doğrudan çalıştırma, verimliliğin güvenlikten önemli olduğu durumlarda kullanılır.

Hoca, son yıllarda sandbox teknikleriyle bu yolun genişletildiğini, harici derleyicilerle yazılan eklentilerin veritabanlarına bu yolla entegre edilebildiğini söyledi.

## 11. Tetikleyiciler (Triggers)

Tetikleyici (trigger) de stored procedure'e benzer: Belirli şartlar sağlandığında bir fonksiyon çalıştırılır. Benzediği diğer yapı assertion'dır. Assertion kaba bir yapıydı: Veritabanında mutlaka sağlanması gereken bir şart tanımlanır. Hocanın örneği: Üçüncü sınıf derslerinde ortalaması belli bir sınırın altında olan bir öğrenci dördüncü sınıf dersi alamaz. Assertion'da veritabanı herhangi bir eylemde bu şarta bakar. Oysa eylemi şekillendirip "şu tablonun şu niteliklerinde insert olduğunda şu koşula bak, şu eylemi yap" dersek yük çok hafifler. Bu, olay-koşul-eylem (event-condition-action) akışıdır. Hoca ayrıca PostgreSQL'de assertion olmadığını, ama tetikleyici olduğunu hatırlattı; standart her zaman bağlayıcı olmuyor.

Slayttaki kurallar (ekrandan, 01:54:30):

- Tetikleyen olay insert, delete ya da update olabilir.
- Update tetikleyicileri belirli niteliklerle sınırlandırılabilir: `after update of takes on grade`.
- Güncelleme öncesi ve sonrası değerlere erişilebilir: `referencing old row as` (delete ve update için), `referencing new row as` (insert ve update için).
- Tetikleyiciler olaydan önce (before) de çalışabilir ve ek kısıt işlevi görebilir; örneğin boş notları null'a çevirmek.

```sql
create trigger setnull_trigger before update of takes
referencing new row as nrow
for each row
    when (nrow.grade = ' ')
    begin atomic
        set nrow.grade = null;
    end;
```

`takes` tablosuna bir update geldiğinde, bu update birden çok satırı etkilemiş olabilir. `referencing new row as nrow`, güncellenen her satırın yeni hâlini gösterir. `for each row` ile her satır için bakılır: Yeni hâlin notu boşsa null yapılır. İstenseydi bu güncellemeye izin de verilmeyebilirdi; kural neyse ona göre şekillendirilir.

Gramerde `for each row` yerine `for each statement` seçeneği de vardır. Bu durumda eylem, güncellenen bütün satırlar için bir kez yapılır; daha verimlidir ama yazması daha zordur. Hoca, eski yıllarda kullandığı kitapta bunun zor bir örneği olduğunu, bu yıl çıkardığını, laboratuvarda `for each row` örnekleriyle çalışılacağını söyledi.

### 11.1 Toplam krediyi güncel tutan tetikleyici

Slayttaki ikinci örnek (ekrandan, 01:57:30):

```sql
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

Tetikleyici `takes` tablosundaki `grade` niteliği güncellendikten sonra çalışır. Her güncellenen satır için koşula bakılır. Eski not F ya da null ise (öğrenci dersi daha önce almamış, şu anda alıyor ya da önceki yıllarda F almış) ve yeni not F'den farklı ve null değilse, yani öğrenci dersten yeni geçtiyse, `course` tablosundan dersin kredisi alınır ve `student` tablosunda o öğrencinin `tot_cred` değerine eklenir.

`tot_cred` türetilmiş (derived) bir değerdir: Öğrenci ders alıp geçtikçe değişmesi gerekir, kendi kendine değişmez. Bu tetikleyici tutarlılığı (consistency) sağlar. Hoca bu örneği "ne çok zor ne çok kolay, tam orta" diye niteledi ve sorgunun iyice anlaşılması gerektiğini söyledi. Ona göre `tot_cred` hiç saklanmayıp gerektiğinde hesaplansa daha iyi olabilirdi; çünkü bu tetikleyici de `takes` her güncellendiğinde çalışarak sisteme yük getirir.

### 11.2 Tetikleyicilerin tehlikeleri

- Yabancı anahtar tanımlanırken `on delete cascade` ile, işaret edilen tablodan satır silindiğinde ona işaret eden satırların da silinmesi sağlanabilir. Bu SQL'in veri tanımlama olanağıdır. Aynı işi tetikleyiciyle yazmak daha uzun ve tehlikeli bir yoldur; hem `on delete cascade` hem tetikleyici yazmak da gereksizdir. `on update cascade` için de aynısı geçerlidir. Hoca, bu yapıların arkada büyük olasılıkla sistem tarafında tetikleyiciyle gerçeklendiğini söyledi.
- Veritabanının replikasyon, materialized view gibi kendi yapıları vardır. Bunları bilmeden benzer işlevleri tetikleyiciyle yapmak hem gereksiz kodlama olur hem de bu yapılarla çakışır.
- Tetikleyiciler zincirleme olarak başka tetikleyicileri tetikleyebilir. Çok tetikleyici yazılmışsa, dikkat edilmezse olayların sonu öngörülemez.

## Örnek Sorular

**1.** (ekrandan, 00:44:40) Sorgu `"insert into instructor values(' " + ID + " ', ' " + name + " ', ..."` biçiminde string birleştirmeyle kuruluyor. Ad `D'Souza` olursa ne olur?

Adın içindeki tek tırnak, değeri çevreleyen tek tırnağı erken kapatır; `Souza'` kısmı sorgunun geri kalanı gibi okunur ve sorgu sözdizimi hatası verir. Çözüm hazır ifade kullanmaktır: `pStmt.setString(2, "D'Souza")` tırnağı kaçışlayarak gönderir ve değer olduğu gibi eklenir. (Python ve SQLite ile denendi: Birleştirmeyle kurulan sorgu `near "Souza": syntax error` verdi, parametreli ekleme `D'Souza` değerini doğru ekledi.)

**2.** (ekrandan, 00:52:50) Sorgu `"select * from instructor where name = '" + name + "'"` biçiminde kuruluyor. Kullanıcı ad olarak `X' or 'Y' = 'Y` girerse sorgu ne olur, ne döner? Hazır ifadeyle ne değişir?

Sorgu `select * from instructor where name = 'X' or 'Y' = 'Y'` olur. `'Y' = 'Y'` her zaman doğru olduğu için `where` koşulu her satırda doğrudur ve tablonun bütün satırları döner. Hazır ifadede (`where name = ?`) girdi tek bir değer olarak gönderilir; adı tam olarak `X' or 'Y' = 'Y` olan hoca aranır ve hiçbir satır dönmez. (Python ve SQLite ile denendi: Birleştirilmiş sorgu tablodaki bütün satırları, parametreli sorgu boş sonuç döndürdü.)

**3.** (derste sözlü, 01:24:35) Bir işlem (transaction) neden bütünlük gerektirir? Örnek veriniz.

Derste verilen cevap: Banka para transferinde bir hesaptan 100 lira düşülür, diğerine eklenir. Bu iki güncelleme sırayla yapılır; arada veritabanı, ağ ya da donanım hatası olursa para kaybolur. Bu yüzden ya iki güncelleme birden yapılmalı (commit) ya hiçbiri yapılmamalıdır (rollback). Ayrıca paranın bir hesaptan düşülüp diğerine henüz eklenmediği tutarsız ara durum diğer programlara görünmemelidir (yalıtım).

**4.** (derste sözlü, 02:02:24) `on delete cascade` olmadan, bir bölüm silindiğinde o bölümdeki hocaları da silen bir tetikleyici nasıl yazılır?

Hoca bunun yapılabilecek bir örnek olduğunu söyledi, çözümünü vermedi.

> **Çözüm (derste verilmedi):** Derste gösterilen gramerle bir yazım şöyledir:
>
> ```sql
> create trigger dept_delete_cascade after delete on department
> referencing old row as orow
> for each row
> begin atomic
>     delete from instructor
>     where instructor.dept_name = orow.dept_name;
> end;
> ```
>
> Aynı mantık SQLite sözdizimiyle (SQLite `referencing` yazmaz, eski satıra `old` ile erişir) Python'da denendi: Physics bölümü silinince `instructor` tablosunda yalnız Music bölümündeki hoca kaldı. Hocanın uyarısı geçerlidir: Yabancı anahtar `on delete cascade` ile tanımlanabiliyorsa tetikleyici yazmak gereksiz ve tehlikelidir.

## Dersin Toparlaması

Bu derste SQL'in bildirimsel yapısının sınırlarından yola çıkılarak bir programlama dilinden veritabanına erişim incelendi. Dinamik SQL (JDBC, ODBC) esnek ama daha yavaş ve riskli, gömülü SQL (SQLJ, Embedded C) ise verimli ama esnek değildir. JDBC'de `Connection`, `Statement`, `ResultSet` ve `ResultSetMetaData` nesneleri, try-with-resources ile kaynakların otomatik kapatılması ve empedans uyumsuzluğu görüldü. Hazır ifadenin hem "bir kez derle, çok kez çalıştır" verimliliği hem de SQL enjeksiyonuna karşı koruması vurgulandı. JDBC ile işlem yönetimi ve yalıtım seviyeleri, gömülü veritabanları, fonksiyonlar, tablo fonksiyonları, prosedürler, harici dil rutinleri ve tetikleyiciler avantaj ve dezavantajlarıyla ele alındı.

Hoca bir sonraki derste kavramsal tasarıma, yani ER ve EER diyagramlarına ve bunların ilişkisel model tablolarına dönüştürülmesine geçileceğini söyledi. Böylece SQL, ilişkisel model ve kavramsal tasarımla dersin büyük kısmı tamamlanmış olacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
