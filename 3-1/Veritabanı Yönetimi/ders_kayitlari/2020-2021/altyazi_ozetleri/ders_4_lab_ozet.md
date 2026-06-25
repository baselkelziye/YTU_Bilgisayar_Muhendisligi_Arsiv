# Ders 4 Lab Çalışma Özeti

## Genel Konular

- Veritabanı Tanımı
  - Verilerin ve aralarındaki ilişkilerin tutulduğu sistem
  - Veriler tablolar halinde organize edilir
  - Tablolara veri yazma, sorgulama ve geri çekme işlemleri yapılır
  - İlişkili tablolar oluşturarak verilere daha hızlı erişim sağlanır

- Tablo Yapısı
  - Sütunlar (dikey): Her sütunun bir adı ve veri tipi vardır
  - Satırlar (yatay): Her satır bir kaydı temsil eder
  - Excel tablosuna benzer yapıdadır

- Veritabanı Yönetim Sistemleri
  - PostgreSQL, MySQL, Microsoft SQL (MSSQL) popüler sistemlerdir
  - Ders boyunca PostgreSQL kullanılacaktır
  - pgAdmin arayüzü üzerinden sorgular yazılacaktır
  - PostgreSQL kurulumunda belirlenen şifre ile veritabanına bağlanılır

## Hocanın Özellikle Vurguladığı Kısımlar

- SQL komutları temelde ikiye ayrılır
  - **DDL (Data Definition Language):** Veri yapısını oluşturma komutları
    - CREATE: Veritabanı veya tablo oluşturma
    - DROP: Veritabanı veya tablo silme
    - ALTER: Tablo yapısında değişiklik yapma
    - RENAME: Tablo veya sütun adını değiştirme
  - **DML (Data Manipulation Language):** Kayıt işlemleri komutları
    - INSERT: Kayıt ekleme
    - DELETE: Kayıt silme
    - UPDATE: Kayıt güncelleme
    - SELECT: Kayıt sorgulama

- Veri tipi seçimi bellek ayırmayı doğrudan etkiler
  - Integer için bellekte sabit alan ayrılır
  - Varchar kullanıldığında sadece kullanılan kadar yer işgal edilir
  - Char kullanıldığında belirtilen boyut kadar sabit alan ayrılır

- DELETE komutunda WHERE koşulu kullanılmazsa tablodaki tüm kayıtlar silinir
- UPDATE komutunda WHERE koşulu kullanılmazsa tablodaki tüm aynı isimli kayıtlar güncellenir
- SQL komutlarında küçük/büyük harf duyarlılığı yoktur
- pgAdmin editöründe çalıştırma butonuna basıldığında tüm komutlar baştan itibaren çalıştırılır, sadece seçili kısım çalıştırılmak istenirse ilgili satırlar seçilmelidir

## Kısa Tekrar Notları

- **CREATE DATABASE:** `CREATE DATABASE university;`
- **CREATE TABLE:** `CREATE TABLE student (student_no INT PRIMARY KEY, first_name VARCHAR(20) NOT NULL, last_name VARCHAR(20) NOT NULL, address VARCHAR(100));`
- **DROP TABLE:** `DROP TABLE student;`
- **ALTER TABLE - Sütun ekleme:** `ALTER TABLE student ADD phone VARCHAR(15);`
- **ALTER TABLE - Sütun silme:** `ALTER TABLE student DROP COLUMN birthday;`
- **ALTER TABLE - Sütun adı değiştirme:** `ALTER TABLE student RENAME COLUMN student_no TO std_no;`
- **Tablo adı değiştirme:** `ALTER TABLE student RENAME TO ogrenci;`
- **INSERT INTO (tüm sütunlara):** `INSERT INTO student VALUES (10, 'Ali', 'Veli', 'İstanbul');`
- **INSERT INTO (belirli sütunlara):** `INSERT INTO student (first_name) VALUES ('Velı');`
- **DELETE (koşullu):** `DELETE FROM student WHERE first_name = 'Ali';`
- **UPDATE (koşullu):** `UPDATE student SET first_name = 'Veli' WHERE student_no = 10;`
- **SELECT (tüm tablo):** `SELECT * FROM student;`
- **SELECT (belirli sütun):** `SELECT first_name, last_name FROM student;`
- **SELECT - WHERE:** `SELECT student_no FROM student WHERE first_name = 'Ali';`
- **LIKE operatörü:** `SELECT * FROM student WHERE last_name LIKE '%r%';`
- **Karşılaştırma operatörleri:** `SELECT * FROM student WHERE student_no > 1044 AND student_no < 1050;`
- **BETWEEN:** `SELECT * FROM student WHERE student_no BETWEEN 1044 AND 1050;`

## Detaylı Açıklamalar

- **Veri Tipleri:** PostgreSQL'de başlıca veri tipleri integer (tam sayı), small integer, float (ondalıklı sayı), char (sabit uzunluklu karakter), varchar (değişken uzunluklu karakter) ve date'dir. Varchar ile maximum karakter sayısı belirtilir (örn. VARCHAR(20)), ancak sadece kullanılan kadar bellek işgal eder. Char ise belirtilen boyut kadar sabit alan ayırır.

- **PRIMARY KEY:** Bir sütuna primary key atandığında, o sütuna girilen değerlerin tekrar etmemesi zorunlu hale gelir. Yani her kayıt özeldir ve asla duplicates olmaz. Genellikle öğrenci numarası, TC kimlik numarası gibi alanlar primary key olarak tanımlanır.

- **NOT NULL:** Bir sütun NOT NULL olarak tanımlanırsa, o sütuna kayıt eklenirken boş bırakılamaz. Eğer boş bırakılmaya çalışılırsa hata verir. Adres gibi opsiyonel alanlarda NOT NULL tanımlanmaz.

- **INSERT INTO İki Farklı Kullanım:** Tüm sütunlara ekleme yapılacaksa sütun isimleri belirtilmeden VALUES ile tüm değerler sırasıyla yazılır. Sadece belirli sütunlara ekleme yapılacaksa, INSERT INTO tablo_adı (sütun1, sütun2) şeklinde sütun isimleri belirtilir, ardından VALUES ile sadece o sütunların değerleri girilir. Belirtilmeyen sütunlar NULL olur (eğer NOT NULL değilse).

- **DELETE vs UPDATE:** Yeni bir kayıt eklemek için INSERT kullanılır. Var olan bir kaydı değiştirmek için UPDATE kullanılır. Mevcut bir kayda eksik bilgi eklemek (örn. numara eklemek) INSERT ile değil UPDATE ile yapılır çünkü kayıt zaten mevcuttur.

- **SELECT sorguları:** Tablodaki verileri ekrana getirmek için kullanılır. `SELECT *` tüm sütunları, `SELECT sütun_adi` ise sadece belirli sütunları getirir. WHERE koşulu ile filtreleme yapılabilir. LIKE operatörü ile desen eşleştirmesi (% karakteri joker karakter olarak kullanılır). Karşılaştırma operatörleri (> < >= <=) ve BETWEEN ile aralık sorgulaması yapılabilir.

- **PGAdmin Kullanımı:** pgAdmin arayüzünden veritabanı ve tablolar oluşturulabilir, sorgular yazılabilir ve çalıştırılabilir. Sol panelden veritabanı ve tablolar görüntülenir. Query Tool ile sorgu yazma alanı açılır. Sorgular çalıştırıldığında sonuçlar alt panelde görüntülenir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
