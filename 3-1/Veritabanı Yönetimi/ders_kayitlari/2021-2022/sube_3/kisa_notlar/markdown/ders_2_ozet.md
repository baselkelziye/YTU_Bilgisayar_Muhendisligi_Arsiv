# Ders 2 Çalışma Özeti

## Genel Konular

- Küme karşılaştırma: `SOME` (ANY) yan cümlesi
  - `F <comp> some r`, r'de koşulu sağlayan en az bir t varsa doğrudur; `<comp>` şunlardan biri olabilir: `<`, `<=`, `>`, `=`, `<>` (ekrandan, 00:10:00).
  - Örnek: Biyoloji bölümündeki en az bir hocadan fazla maaş alan hocalar. Aynı sorgu öz-birleştirme (self join) ile de yazılır (ekrandan, 00:05:00):
    - `select distinct T.name from instructor as T, instructor as S where T.salary > S.salary and S.dept_name = 'Biology';`
    - `select name from instructor where salary > some (select salary from instructor where dept_name = 'Biology');`
  - Slayttaki örnekler: `5 < some {0,5,6}` doğru, `5 < some {0,5}` yanlış, `5 = some {0,5}` doğru, `5 <> some {0,5}` doğru (çünkü 0 ≠ 5) (ekrandan, 00:10:00).
  - `= some` ile `in` denktir; ama `<> some` ile `not in` denk değildir.
  - `> some`, sağdaki kümenin en küçüğünden büyük olmak gibi düşünülebilir.
- Küme karşılaştırma: `ALL` yan cümlesi
  - Sağdaki kümenin bütün elemanları için koşul sağlanmalıdır; `> all`, kümenin en büyüğünden büyük olmak demektir.
  - `<> all` ile `not in` denktir; `= all` ile `in` denk değildir.
- `EXISTS` ve `NOT EXISTS`
  - `exists r`, r boş değilse doğru; `not exists r`, r boşsa doğrudur.
  - Örnek: Hem 2017 Güz hem 2018 Bahar döneminde açılan dersler (ekrandan, 00:20:00):
    - `select course_id from section as S where semester = 'Fall' and year = 2017 and exists (select * from section as T where semester = 'Spring' and year = 2018 and S.course_id = T.course_id);`
  - Dış sorgudaki S değişkenine korelasyon adı (correlation name), içteki sorguya ilişkili alt sorgu (correlated subquery) denir.
  - Aynı sorgu `course_id in (select course_id from section where semester = 'Spring' and year = 2018)` ile de yazılır; `IN` kullanılınca ayrıca `S.course_id = T.course_id` eşitlemesi gerekmez (ekrandan, 00:40:00).
  - `NOT EXISTS` örneği: Biyoloji bölümünün açtığı bütün dersleri almış öğrenciler. Biyoloji derslerinden öğrencinin aldığı dersler çıkarılır (`except`); sonuç boşsa öğrenci hepsini almıştır ($X - Y = \emptyset \iff X \subseteq Y$) (ekrandan, 00:30:00).
- `UNIQUE` yan cümlesi
  - Alt sorgunun sonucunda tekrar eden satır yoksa doğru döner.
  - Örnek: 2017'de en fazla bir kez açılan dersler; iç sorguda `R.course_id = T.course_id` eşitlemesi yapılmazsa sorgu derslerle eşleşmez.
  - Aynı iş `GROUP BY course_id` ile ders başına açılma sayısı hesaplanıp 1'e eşit olanlar seçilerek de yapılabilir.
- `FROM` içinde alt sorgu
  - Alt sorgunun sonucu normal bir tablo gibi kullanılır, başka tablolarla birleştirilebilir (ekrandan, 00:35:00):
    - `select dept_name, avg_salary from (select dept_name, avg(salary) as avg_salary from instructor group by dept_name) where avg_salary > 42000;`
  - Bu sorguda `HAVING` gerekmez; ama aynı sorgu `GROUP BY dept_name HAVING avg(salary) > 42000` ile de yazılabilir.
  - `GROUP BY` kullanılırken `SELECT`'te toplama fonksiyonu içinde olmayan her kolon `GROUP BY`'da da yer almalıdır.
- `WITH` yan cümlesi
  - Yalnız içinde geçtiği sorguda geçerli geçici bir ilişki tanımlar (ekrandan, 01:00:00):
    - `with max_budget (value) as (select max(budget) from department) select department.name from department, max_budget where department.budget = max_budget.value;`
  - Karmaşık örnek: Toplam maaşı, bütün bölümlerin toplam maaşlarının ortalamasından büyük olan bölümler; `dept_total` ve `dept_total_avg` adlı iki geçici ilişki virgülle ayrılarak tanımlanır (ekrandan, 01:10:00).
  - `WITH`'ten sonraki kolon listesi zorunlu değildir; hesaplanan kolon iç sorguda `as value` ile adlandırılabilir.
- Skaler alt sorgu
  - Tek bir değer beklenen yerde kullanılır; birden çok satır dönerse çalışma zamanı hatası verir (ekrandan, 01:15:00).
  - Örnek: Her bölüm ve bölümdeki hoca sayısı: `select dept_name, (select count(*) from instructor where department.dept_name = instructor.dept_name) as num_instructors from department;`
  - İçteki `where` eşitlemesi yazılmazsa her bölümün yanına okuldaki toplam hoca sayısı yazılır.
- Veri değiştirme: `DELETE`, `INSERT`, `UPDATE`
  - `DROP` tabloyu şemasıyla siler; `DELETE` satırları siler ve `WHERE` ile seçim yapılabilir; `TRUNCATE` tablonun bütün satırlarını siler, tabloyu bırakır.
  - `DELETE`'te kolon yazılmaz (`delete from instructor where ...`), çünkü satır satır siler.
  - Alt sorgulu silme: Watson binasındaki bölümlerin hocaları; ortalamanın altında maaş alan hocalar (ekrandan, 01:20:00).
  - Ortalama sorunu: Satır silindikçe ortalama değişir. SQL önce `avg(salary)` değerini hesaplar ve silinecek satırları bulur, sonra ortalamayı yeniden hesaplamadan bunları siler.
  - `INSERT`'te bütün kolonlara değer verilecekse kolon listesi yazılmayabilir; eksik kolon varsa kolon adları yazılmalı, değer verilmeyen kolon NULL olabilmelidir. `INSERT INTO ... SELECT ...` ile sorgu sonucu eklenebilir.
  - `UPDATE`'te `WHERE` unutulursa bütün satırlar güncellenir; önce aynı koşulla `SELECT` yazıp etkilenecek satırları görmek önerildi (ekrandan, 01:30:00).
  - İki ayrı güncellemenin sırası önemlidir (önce %3, sonra %5); ters sırada bazı hocalar iki kez zam alır.
- `CASE` ile koşullu güncelleme
  - `update instructor set salary = case when salary <= 100000 then salary * 1.05 else salary * 1.03 end` (ekrandan, 01:35:00).
  - Koşullar sırayla denenir; ilk sağlanan dal uygulanır, diğerleri atlanır. Bu yüzden her hoca bir kez zam alır ve koşulların sırası önemlidir.
  - Skaler alt sorgulu güncelleme: Öğrencilerin `tot_cred` değeri, geçtikleri derslerin kredileri toplanarak yeniden hesaplanır; hiç ders almamış öğrenci için NULL yerine 0 yazmak için `case when sum(credits) is not null then sum(credits) else 0 end` kullanılır (ekrandan, 01:45:00).
- Birleştirmeler (joins)
  - Türler: natural join, inner join, outer join (left, right, full outer).
  - Natural join, aynı adlı bütün ortak kolonlar üzerinde eşleştirir ve her ortak kolonu sonuçta bir kez tutar (ekrandan, 02:05:00).
  - Inner join'de birleştirme koşulu `ON` ile açıkça yazılır; `select *` ile iki tablonun ID kolonu da gelir.
  - Natural join istenmeyen kolonlar üzerinden de eşleştirebilir; `USING (course_id)` ile kolon sınırlanabilir; ama hoca açıkça `INNER JOIN ... ON` yazmayı önerdi.
  - Left outer join sol tablodaki bütün satırları getirir, sağda karşılığı olmayanların sağ kolonları NULL olur; right outer join tersidir; full outer join ikisinin birleşimidir.
  - Left ve right join arasında yalnız tabloların yeri değişir; tablolar yer değiştirilerek biri diğerinin yerine kullanılabilir.
- Görünümler (views)
  - Görünüm, bir sorgunun sanal ilişki olarak tanımlanmasıdır; içinde veri tutmaz, her sorgulandığında tanımındaki sorgu çalışır.
  - Kullanım: Bazı kolonları (maaş, kimlik numarası gibi) gizlemek ve karmaşık sorguları sadeleştirmek.
  - `create view faculty as select ID, name, dept_name from instructor;` sonra `select name from faculty where dept_name = 'Biology';`
  - Bir görünüm başka bir görünüm tanımında kullanılabilir; v1 tanımında v2 geçiyorsa v1, v2'ye doğrudan bağımlıdır; kendine bağımlı görünüme özyinelemeli (recursive) denir (ekrandan, 02:45:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- `= some` ile `in` denktir ama `<> some` ile `not in` denk değildir; `<> all` ile `not in` denktir.
  - `5 <> some {0,5}` doğrudur, ama `5 not in {0,5}` yanlıştır.
- İlişkili alt sorgularda dış ve iç sorgudaki değerler iç sorguda eşleştirilmelidir.
  - `EXISTS` ve `UNIQUE` örneklerinde eşitleme yazılmazsa iç sorgu dış satırla ilgisiz bir küme döndürür ve sonuç yanlış olur.
- İç sorgu önce bir kez çalışır, sonucu sabit bir değer gibi kullanılır.
  - SQL bildirimsel bir dildir, iç sorguyu döngü gibi satır satır yeniden çalıştırmaz.
- `UPDATE`, `DELETE`, `INSERT` öncesinde aynı koşulla `SELECT` yazıp etkilenecek satırlar görülmelidir.
- `CASE` dalları küçükten büyüğe sıralanmalıdır; en geniş koşul başa yazılırsa sonraki dallar hiç çalışmaz.
- Natural join yerine `INNER JOIN ... ON` ya da `LEFT/RIGHT OUTER JOIN ... ON` açıkça yazılmalıdır.
  - Sorgular okunabilir olmalı; tablolardaki kolon adları sonradan hatırlanmayabilir, sorguyu başkaları da kullanacaktır.
  - Yabancı anahtar kolonları `student_ID` gibi tablo adıyla adlandırılmalı, `name` gibi belirsiz adlardan kaçınılmalıdır.
- Skaler alt sorgu birden çok satır döndürürse hata verir.
- `INSERT ... SELECT *` yerine kolon adlarını tek tek yazmak önerildi.

## Kısa Tekrar Notları

- `> some`: en küçüğünden büyük; `> all`: en büyüğünden büyük.
- `= some` ≡ `in`; `<> all` ≡ `not in`.
- `exists`: alt sorgu boş değilse doğru; `not exists`: boşsa doğru.
- "Bütün X'leri alan" sorgusu: `not exists (X except alınanlar)`.
- `unique`: alt sorguda tekrar yoksa doğru.
- `FROM` içindeki alt sorgu tablo gibi kullanılır; `HAVING` ile de aynı sonuç elde edilebilir.
- `WITH`: yalnız o sorguda geçerli geçici ilişki; birden çok tanım virgülle ayrılır.
- Skaler alt sorgu: tek değer; çok satır dönerse hata.
- `DROP` tablo + şema, `DELETE` seçilen satırlar, `TRUNCATE` bütün satırlar.
- Ortalama altını silmede ortalama önce bir kez hesaplanır.
- `UPDATE` sırası önemli; çözüm `CASE WHEN ... THEN ... ELSE ... END`.
- Natural join: aynı adlı bütün kolonlar, ortak kolon bir kez; inner join: `ON` zorunlu, `select *` ile iki kopya.
- Left outer join: sol tablonun bütün satırları + eşleşmeyenlerde NULL.
- View: sanal ilişki, veri tutmaz; gizleme ve sadeleştirme için.

## Detaylı Açıklamalar

- `SOME` ve `ALL`, bir değeri alt sorgunun döndürdüğü kümeyle karşılaştırır. Tahtadaki örnekte bölüm ve maaş tablosu şöyleydi: Biyoloji 70.000, Bilgisayar 50.000, Fizik 90.000, Biyoloji 30.000, Kimya 60.000 (ekrandan, 00:15:00). İç sorgu Biyoloji maaşlarını, yani {70.000, 30.000} kümesini döndürür. `salary > all (...)` için maaşın 70.000'den büyük olması gerekir; yalnız 90.000 (Fizik) gelir. `salary > some (...)` için en az bir Biyoloji maaşından, yani 30.000'den büyük olmak yeter; 70.000, 50.000, 90.000 ve 60.000 olmak üzere 4 satır gelir. 30.000'lik hoca kendisine eşit olduğu, 70.000'den de küçük olduğu için gelmez. Sonuçlar sqlite3'te `MIN`/`MAX` karşılıklarıyla denendi ve doğrulandı (sqlite3 `SOME`/`ALL` desteklemez).
- `EXISTS` yalnız alt sorgunun boş olup olmadığına bakar. 2017 Güz ve 2018 Bahar örneğinde `S.course_id = T.course_id` koşulu kaldırılırsa, 2018 Baharda herhangi bir ders açıldığı sürece iç sorgu boş olmaz ve 2017 Güzdeki bütün dersler listelenir. Bu yüzden ilişkili alt sorguda eşleştirme koşulu şarttır. `IN` ile yazıldığında ders kimliklerinin iç kümede bulunması zaten istendiği için ayrıca eşitleme gerekmez.
- `NOT EXISTS` ile "bütün Biyoloji derslerini almış öğrenciler" sorgusu tersten kurulur: Biyoloji derslerinden öğrencinin aldığı dersler çıkarılır. Kalan küme boşsa öğrenci bütün dersleri almıştır. Slaytta bu sorgunun `= all` ile yazılamayacağı da not edilmiştir (ekrandan, 00:30:00).
- `FROM` içinde alt sorgu kullanıldığında sonuç, adı verilmiş bir tablo gibidir. Hoca ekranda bölüm ortalamaları tablosunu (Bilgisayar 50, Fizik 45, bin cinsinden) yazıp 42.000 filtresinden sonra bu iki satırın kaldığını gösterdi; bu tablo `instructor` ile `inner join` yapılarak hocaların adları da getirilebilir (ekrandan, 00:40:00).
- `WITH` ile tanımlanan ilişki bir ön işlem gibidir: önce en yüksek bütçe ya da bölüm toplamları hesaplanır, sonra bunlar asıl sorguda tablo gibi birleştirilir. Aynı işi `FROM` içinde iç içe alt sorgularla yapmak mümkündür ama karmaşık sorgularda okunabilirlik düşer.
- Ortalama altı silme örneğinde bir öğrenci, satırlar silindikçe ortalamanın değişip değişmeyeceğini sordu. Hoca iç sorgunun önce bir kez çalıştığını, örneğin 55.300 gibi tek bir değer bulunduktan sonra her satırın bu sabit değerle karşılaştırıldığını anlattı. Slayttaki çözüm de aynıdır: önce ortalama hesaplanır ve silinecek satırlar bulunur, sonra bunlar ortalama yeniden hesaplanmadan silinir (ekrandan, 01:20:00).
- Zam örneğinde önce 100.000'den fazla alanlara %3, sonra kalanlara %5 zam yapılır. Sıra ters olsaydı %5 zamla 100.000'i geçen hocalar bir de %3 zam alırdı. `CASE` bunu önler, çünkü her satır için yalnız ilk sağlanan dal uygulanır. Hoca ekranda dört dallı bir örnek de yazdı: `<= 30000`, `<= 70000` (×1.04), `<= 100000` (×1.03), `else` (×1.03) (ekrandan, 01:40:00). <!-- BELİRSİZ: ilk dalın çarpanı karede seçili olduğu için okunamıyor. --> Dallar küçükten büyüğe sıralı olduğu için çakışma olmaz; `<= 100000` dalı başa yazılsaydı 100.000'in altındaki herkes o dala girer, diğer dallar anlamsız kalırdı.
- Tahtadaki join örneğinde `student` tablosunda 115, 113, 112, 110 kimlikli öğrenciler, `takes` tablosunda 115 iki kez, 113 ve 112 birer kez vardı (ekrandan, 02:25:00). Inner join 4 satır getirir (115 iki kez); 110'un karşılığı olmadığı için gelmez. Left outer join 5 satır getirir; 110'un `takes` kolonları NULL olur. Right outer join bu veride inner join ile aynı 4 satırı getirir, çünkü `takes`'te olup `student`'ta olmayan kimlik yoktur. Bu sayılar sqlite3 ile doğrulandı.
- Slayttaki `course` ve `prereq` örneğinde `course natural right outer join prereq` sonucu BIO-301 (Genetics, Biology, 4, BIO-101), CS-190 (Game Design, Comp. Sci., 4, CS-101) ve CS-347 (null, null, null, CS-101) satırlarıdır; CS-347'nin `course` tablosunda bilgisi olmadığı için ders bilgileri NULL gelir (ekrandan, 02:30:00). Left outer join'de ise ön koşulu olmayan CS-315'in `prereq_id` değeri NULL olur.
- Görünüm, bir tabloya arayüz gibidir. Hoca, çalışan tablosundaki kimlik numarası ve maaş gibi kolonları uygulama geliştiricilere açmak yerine yalnız ID, ad ve e-posta kolonlarını içeren bir görünüm tanımlamayı örnek verdi. `select * from employee_view` çalıştırıldığında arka planda görünüm tanımındaki sorgu çalışır; görünüm yer kaplamaz (ekrandan, 02:40:00).
- Ders sonrası not: Hoca `FROM student, takes` gibi virgülle yazılan tabloların natural join olarak çalıştığını söyledi. Doğrusu: virgül, koşul yazılmazsa Kartezyen çarpım üretir; natural join için `NATURAL JOIN` açıkça yazılmalıdır. Slaytta da virgüllü sorgu `where student.ID = takes.ID` koşuluyla birlikte gösterilmektedir (ekrandan, 02:05:00).
- Ders sonrası not: Hoca outer join'de `ON`/`USING` yazılmazsa natural kabul edildiğini söyledi. Standart SQL'de `LEFT/RIGHT OUTER JOIN` için `ON`, `USING` ya da `NATURAL` gerekir; yazılmazsa sözdizimi hatası alınır.
- Ders sonrası not: Hoca hocası olmayan yeni bir bölüm için skaler alt sorgunun NULL döndüreceğini söyledi. `count(*)` boş küme için 0 döndürür; bu örnekte o bölümün yanına 0 yazılır (sqlite3 ile denendi).
- Ders sonrası not: Hoca görünümler üzerinde `INSERT`, `UPDATE`, `DELETE` yapılamayacağını söyledi. Basit görünümler (tek tablo, toplama ve `GROUP BY` içermeyen) çoğu sistemde güncellenebilir; değişiklik alttaki tabloya yansıtılır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
