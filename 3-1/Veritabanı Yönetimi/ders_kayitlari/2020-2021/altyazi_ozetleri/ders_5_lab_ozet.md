# Ders 5 Lab Çalışma Özeti

## Genel Konular

- Birden fazla tablo üzerinde sorgulama (çoklu tablo sorguları)
  - Geçen hafta tek tablo üzerinden SELECT-FROM-WHERE kalıbı ile sorgular çalışılmıştı
  - Bu ders itibarıyla iki ve daha fazla tabloyu birleştirerek sorgulama öğreniliyor
  - PostgreSQL üzerinde pgAdmin arayüzü kullanılarak uygulama yapılıyor

- Company DB veritabanının tanıtılması ve kurulması
  - 6 tablodan oluşan örnek bir şirket veritabanı
  - Tablolar: Employee, Department, Dept_Locations, Project, Works_On, Dependent
  - Şema (CREATE TABLE) ve data (INSERT INTO) SQL dosyaları ayrı ayrı import ediliyor

- İki tablo arasındaki eşleme (Join mantığı)
  - FROM'a birden fazla tablo adı yazıldığında arka planda笛卡尔 çarpımı oluşturulur
  - WHERE koşuluyla eşleşen satırlar filtrelenir
  - Bu işlem gerçek bir tablo oluşturmaz, sadece sorgu için geçici bir birleşim yapılır

## Hocanın Özellikle Vurguladığı Kısımlar

- Tabloları birleştirirken ortak sütunlar üzerinden eşleme yapılması gerektiğini vurguladı
  - Örneğin Employee.D_no = Department.D_number gibi koşullar verilmeli
  - Eşleme yapılmazsa笛卡尔 çarpımı oluşur ve anlamsız sonuçlar doğurur

- Aynı isimde sütunlar olduğunda tablo adı belirtilmesi gerektiğini anlattı
  - İki tabloda da "D_number" varsa `department.d_number = dept_locations.d_number` şeklinde yazılmalı
  - Tablolara alias (kısaltma) verilerek kod okunabilirliği artırılabilir: `FROM department d, dept_locations dl`

- Operating System projesi örneğinde dikkat edilmesi gereken bir noktaya değindi
  - Doğrudan departman numarası üzerinden eşleme yapılmamalı
  - Proje adından proje numarasına, oradan Works_On tablosuna, oradan Employee'ye gidilmeli
  - Bir çalışanın çalıştığı projenin departmanı ile kendi departmanı farklı olabilir

- DISTINCT kelimesinin kullanımını anlattı
  - Tekrarlayan kayıtları tekil olarak göstermek için kullanılır
  - Örneğin aynı departman adı birden fazla kez döndürülüyorsa DISTINCT ile tekrarlar kaldırılır

- JOIN komutunun varlığını ama derslerde WHERE tabanlı yöntemin tercih edileceğini belirtti
  - INNER JOIN, LEFT JOIN, RIGHT JOIN, FULL OUTER JOIN türleri mevcuttur
  - INNER JOIN sadece kesişim kümesini, FULL OUTER JOIN ise her iki tablonun tamamını döndürür

## Kısa Tekrar Notları

- `SELECT sutun1, sutun2 FROM tablo1, tablo2 WHERE tablo1.ortak_sutun = tablo2.ortak_sutun AND ek_kosul`
- Tablolara alias verme: `FROM department d, dept_locations dl` ardından `d.d_number = dl.d_number`
- İçinde belirli bir metin geçen kayıtları bulma: `WHERE adres LIKE '%Atlanta%'`
- Tekil sonuç için: `SELECT DISTINCT sutun_adi`
- Büyüktür/küçüktür operatörleri: `>`, `<`, `>=`, `<=`
- Maaş gibi numeric değerlerle karşılaştırma: `salary > 70000`

## Detaylı Açıklamalar

- **Tek tablo sorgusu hatırlatması:** Örneğin Student tablosundan ismi Ali olan öğrencilerin numaralarını çekme: `SELECT student_number FROM student WHERE first_name = 'Ali'`. Yıldız işareti kullanılırsa (`SELECT *`) tüm sütunlar döndürülür.

- **İki tablo örneği (Employee-Department):** Jared James'in çalıştığı departmanın adını bulmak için Employee ve Department tabloları FROM'a yazılır, `WHERE employee.d_no = department.d_number AND employee.first_name = 'Jared' AND employee.last_name = 'James'` koşulu verilir, select'te `d_name` istenir.

- **Arka planda neler olduğu:** FROM'da iki tablo belirtildiğinde, veritabanı her bir satırı diğer tablonun her bir satırıyla eşleştirir (笛卡尔 çarpımı). WHERE koşuluyla yalnızca anlamlı eşleşmeler filtrelenir. Bu geçici tablo sadece sorgu sırasında oluşur.

- **Company DB tablo yapısı:**
  - **Employee:** F_name, L_name, Minit, SSN (kimlik no), BDate, Address, Sex, Salary, Super_SSN (yönetici no), D_no
  - **Department:** D_name, D_number, Mgr_SSN, Mgr_start_date
  - **Dept_Locations:** D_number, D_location (departmanın bulunduğu şehirler)
  - **Project:** P_name, P_number, P_location, D_number
  - **Works_On:** ESSN (çalışan no), P_no (proje no), Hours (çalışma saati)
  - **Dependent:** ESSN, Dependent_name, Sex, BDate, Relationship (akraba bilgisi)

- **Üç tablolu sorgu örnekleri:**
  - Atlanta'da yaşayan çalışanların departman adları: Employee (adres LIKE ile) + Department (D_no eşleme)
  - Operating System projesinde çalışanlar: Project (P_name) + Works_On (P_no eşleme) + Employee (SSN eşleme)
  - Kızının ismi Alice olan çalışanların departman adları: Dependent (name + relationship) + Employee (ESSN=SSN) + Department (D_no)
  - Maaşı 70.000'in üzerinde olanların çalıştığı projeler: Employee (salary) + Works_On (SSN) + Project (P_no)

- **JOIN türleri hakkında genel bilgi:**
  - **INNER JOIN (JOIN):** İki tablonun yalnızca eşleşen satırlarını döndürür (kesişim)
  - **LEFT JOIN:** Sol tablonun tüm satırlarını, sağ tabloyla eşleşenleri de ekler
  - **RIGHT JOIN:** Sağ tablonun tüm satırlarını, sol tabloyla eşleşenleri de ekler
  - **FULL OUTER JOIN:** Her iki tablonun tüm satırlarını, eşleşmeyenleri NULL ile döndürür

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
