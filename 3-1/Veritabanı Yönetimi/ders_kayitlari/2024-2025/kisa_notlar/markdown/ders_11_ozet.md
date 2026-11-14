# Ders 11 Çalışma Özeti

## Genel Konular

- Dersin kapsamı
  - Aktif veritabanları başlığı altında daha kapsamlı tetikleyiciler (trigger) ve güvenlik konusunun eksik kalan kısımları: SQL ile yetkilendirme (grant diyagramları, `REFERENCES` yetkisi), zorunlu erişim denetimi (mandatory access control) ve istatistiksel (OLAP) veritabanlarında çıkarımla bilgi sızdıran örtülü kanallar (covert channels).
  - Sunu "Veri Bütünlüğü Programlama ve Güvenlik" başlıklıdır (ekrandan, 00:08:05). Hoca bunun Elmasri ve Navathe'nin kitabından ve başka bir kitaptaki öğrenci kayıt veritabanı örneklerinden derlendiğini söyledi.
  <!-- BELİRSİZ: Öğrenci kayıt örneklerinin alındığı "başka kitap"ın adı altyazıda geçmiyor. -->
- Genel kısıtlar: Assertion (ekrandan, 00:08:05)
  - Şema: `STUDENT(SId, SName, GradYear, MajorId)`, `DEPT(DId, DName)`, `COURSE(CId, Title, DeptId)`, `SECTION(SectId, CourseId, Prof, YearOffered)`, `ENROLL(EId, StudentId, SectionId, Grade)`.
  - `create assertion SmallSections check (not exists (select e.SectionId from ENROLL e group by e.SectionId having count(e.EId) > 30))`: Hiçbir şubede 30'dan fazla öğrenci olamaz.
  - Assertion'lar genelde `check (not exists ...)` ya da `check (exists ...)` biçiminde, ilişkili (correlated) sorgu tarzında yazılır. Bir öğrencinin bir dersi en fazla bir kez alması gibi kısıtlar da böyle ifade edilir.
  - Assertion her işlemde denetlendiği için sisteme büyük yük getirir; tetikleyicide ise olay (event) ile denetim daraltılır.
- Tetikleyicilerin genel yapısı
  - Tetikleyiciler veritabanının ilk zamanlarından beri vardır. Literatürde "olmazsa olmaz ama uzak durulması gereken" nesneler olarak anılır; NoSQL dünyasında karmaşık işler (karmaşık join'ler, tetikleyiciler) çoğunlukla uygulamaya havale edilir.
  - Yapı olay, koşul, eylem (event, condition, action, ECA) biçimindedir: Belli bir tabloda, belli kolonlarda `insert` ya da `update` olunca, koşul sağlanırsa eylem yapılır.
  - `create or alter` (sistemlere göre `create or replace`) mevcut tetikleyiciyi değiştirmeye yarar; yoksa aynı adlı nesne zaten var diye hata alınır ve önce `drop` gerekir. Aynı biçim fonksiyon, prosedür ve view'larda da vardır.
  - Türler: `before`/`after` + `insert`/`update`/`delete` ve view'lar için `instead of`. `instead of` tetikleyicisi, işlemi view üzerinde değil view'un dayandığı temel tablolarda yapar.
  - `for each row` her değişen satır için, `for each statement` bütün komut için bir kez çalışır. `COPY` gibi toplu (bulk) yüklemelerde, toplu güncelleme ve silmelerde eylemi bir kez çalıştırmak çok daha verimlidir.
- Basit tetikleyici örnekleri (ekrandan, 00:16:30)
  - `LogGradeChange`: `ENROLL`'da `Grade` güncellenince her satır için eski ve yeni not farklıysa `GRADE_LOG(UserName, DateChanged, EId, OldGrade, NewGrade)` tablosuna `current_user`, `current_date`, `newrow.EId`, eski ve yeni not eklenir. Olay `after update of Grade in ENROLL`, koşul `when oldrow.Grade <> newrow.Grade`, eylem `insert into GRADE_LOG ...`.
  - Yeni öğrenci eklenince mezuniyet yılının (GradYear) geçerli yıla göre denetlenip geçersizse null yapıldığı ikinci bir örnek.
  <!-- BELİRSİZ: Mezuniyet yılı tetikleyicisinin koşulu altyazıdan net çıkmıyor (hoca "şu andaki tarihten 4 sene sonradan daha fazla olması lazım" dedi); slaytı okunmadı. -->
- Türetilmiş bir niteliğin tutarlılığı: `DEPARTMENT.Total_sal`
  - Basitleştirilmiş COMPANY şemasında `DEPARTMENT` tablosuna her bölümün toplam maaşını tutan `Total_sal` eklenir. Hoca bunun türetilmiş (derived) bir bilgi olduğunu, yaş yerine doğum tarihi saklamak gibi, fiziksel olarak saklamanın tehlikeli olduğunu hatırlattı: Saklanırsa tutarlılığı sağlanmalıdır.
  - Tutarlılığı bozan dört olay: T1 yeni çalışan ekleme, T2 mevcut çalışanın maaşını değiştirme, T3 çalışan silme, T4 çalışanın bölümünü değiştirme. Her birinde çalışanın bölüm numarası null ise eylem gerekmez.
  - T1 (ekrandan, 00:27:30): `CREATE TRIGGER Total_sal1 AFTER INSERT ON Employee FOR EACH ROW WHEN (NEW.Dno IS NOT NULL) UPDATE DEPARTMENT SET Total_sal = Total_sal + NEW.Salary WHERE Dno = NEW.Dno;`
  - T2, satır düzeyi (ekrandan, 00:33:00): `AFTER UPDATE OF Salary ON EMPLOYEE REFERENCING OLD ROW AS O, NEW ROW AS N FOR EACH ROW WHEN (N.Dno IS NOT NULL) UPDATE DEPARTMENT SET Total_sal = Total_sal + N.salary - O.salary WHERE Dno = N.Dno;`
  - T2, komut düzeyi (ekrandan, 00:33:00): `REFERENCING OLD TABLE AS O, NEW TABLE AS N FOR EACH STATEMENT WHEN EXISTS (SELECT * FROM N WHERE N.Dno IS NOT NULL) OR EXISTS (SELECT * FROM O WHERE O.Dno IS NOT NULL) UPDATE DEPARTMENT AS D SET D.Total_sal = D.Total_sal + (SELECT SUM(N.Salary) FROM N WHERE D.Dno = N.Dno) - (SELECT SUM(O.Salary) FROM O WHERE D.Dno = O.Dno) WHERE Dno IN ((SELECT Dno FROM N) UNION (SELECT Dno FROM O));`
  - Gösterim Oracle tarzıdır; hoca PostgreSQL'e çevirmenin iyi bir alıştırma olduğunu söyledi.
- Takdire bağlı (discretionary) yetkilendirme
  - Kimlik doğrulama (authentication) ile yetkilendirme (authorization) ayrıdır; konu yetkilendirmedir. Gerçek sistemlerde bu işler için ayrı sunucular ve servis sağlayıcılar vardır.
  - Tablo ya da nitelik düzeyinde kullanıcılara ve rollere yetkiler verilir: `SELECT`, `INSERT`, `UPDATE`, `DELETE`, güçlü bir yetki olan `REFERENCES`, tetikleyici oluşturma, fonksiyon çalıştırma (`USAGE`, `UNDER` gibi standartta olup sistemlerde olmayabilen yetkiler de var).
  - Rol esaslı yetkilendirme: Roller (dekan, kayıt ofisi, profesör gibi) daha az sayıdadır ve kolay değişmez; kullanıcılar rollere girip çıkar, birden çok rol alabilir ve rollerin yetkilerinin birleşimini (union) alır.
  - Nitelik düzeyinde yetki: `grant select(StudentId, Grade) on ENROLL to dean, professor` gibi "ya hep ya hiç" yerine ayrıntılı yetki.
- SQL komutlarının gerektirdiği yetkiler (ekrandan, 00:54:15)
  - `select`, sorguda geçen her alanda `select` yetkisi ister. `insert` ve `update`, ilgili alanda kendi yetkisine ek olarak `where` kısmında geçen her alanda `select` yetkisi ister. `delete`, `delete` yetkisine ek olarak `where` kısmındaki alanlarda `select` ister.
  - Kör yazma (blind write): `UPDATE ENROLL e SET e.Grade = 100` eski değeri okumaz, `update(Grade)` yeter. `UPDATE ENROLL e SET e.Grade = e.Grade + 1` eski notu okuduğu için `select` yetkisi de gerekir.
- View ile ince ayar (ekrandan, 00:58:20)
  - `update(Grade)` yetkisi profesöre başka bir profesörün verdiği notu değiştirme imkânı da verir. Çözüm: Profesörlerin `ENROLL` üzerindeki yetkileri geri alınır, yalnız kendi şubelerindeki kayıtları gösteren bir view üzerinde yetki verilir:
  - `create view PROF_ENROLLMENTS as select e.* from ENROLL e where e.SectionId in (select k.SectId from Section k where k.Prof = current_user)`; `grant select on PROF_ENROLLMENTS to professor`; `grant update(Grade) on PROF_ENROLLMENTS to professor`.
  - Slayttaki ikinci örnekte dekana yalnız bu yılın notlarını (öğrenci bilgisi olmadan) gösteren `CurrYearGrades` view'u üzerinde `select` verilir.
- `REFERENCES` yetkisi
  - Kötü niyetli bir kullanıcı, örneğin bir tabloda neredeyse hiçbir değere izin vermeyen bir assertion yazarak tabloyu kullanılamaz hâle getirebilir. Bu yüzden ayrı bir "grant assertion" yetkisi yoktur; assertion ve yabancı anahtar tanımlamak için `REFERENCES` yetkisi gerekir.
  - Yabancı anahtar da işaret ettiği tablodaki etkinlikleri kısıtlar: `ENROLL`, `STUDENT`'a `on delete no action` ile işaret ederse `STUDENT`'ın sahibi kendi tablosundan silme yapamaz. Bu yüzden `select` yetkisi yeterli değildir.
- `WITH GRANT OPTION`, grant diyagramları ve `REVOKE` (ekrandan, 01:14:00 ve 01:17:30)
  - `WITH GRANT OPTION` yetkiyi devretme yetkisini de verir; yetki bütün veritabanına yayılabileceği için yalnız güvenilir kişilere verilmelidir.
  - Grant diyagramında her düğüm "yetki + kullanıcı/rol"dür; `**` sahibi, `*` devretme yetkisi olanı gösterir. Sistem bunları fiziksel olarak erişim matrisleri ve erişim denetim listeleriyle (access control lists, ACL) tutar.
  - `REVOKE ... CASCADE` yetkiyi ve yalnız bu yetki sayesinde verilmiş yetkileri zincirleme kaldırır; `RESTRICT` yalnız ilk adımdaki yetkiyi kaldırır (devredilmiş yetki varsa).
- Zorunlu erişim denetimi (ekrandan, 01:25:00)
  - Takdire bağlı yöntem kullanıcılara güvenmeye dayanır. Kötü niyetli bir profesör `TakeAPeek` adlı bir tablo oluşturup herkese açabilir (public) ve `ENROLL`'daki notları içine kopyalayarak bütün yetkilendirmeyi boşa çıkarabilir.
  - Zorunlu modelde her kullanıcıya (subject) ve her nesneye (tablo, kayıt) bir güvenlik seviyesi atanır: Top secret (TS), secret (S), classified (C), unclassified (UC).
  - Bell-LaPadula modeli: Okuma özelliği, $S$ ancak $\text{class}(S) \ge \text{class}(O)$ ise $O$'yu okuyabilir. Yazma özelliği, $S$ ancak $\text{class}(S) \le \text{class}(O)$ ise $O$'ya yazabilir. Bilgi düşük seviyeden yükseğe akmalıdır.
  - Örnekte profesör S seviyesindedir, oluşturduğu `TakeAPeek` de S olur; C seviyesindeki öğrenciler okuma özelliği yüzünden onu okuyamaz.
  - Kötü niyetli kullanıcı uygulama kodunu değiştirip profesörün girdiği notları kendi C seviyesindeki tablosuna kopyalatmaya çalışsa bile, S seviyesindeki uygulama daha düşük seviyedeki tabloya yazamaz.
  - Zorunlu erişim denetimi SQL'in desteklediği bir şey değildir; SQL'de grant ve revoke ile takdire bağlı yetkilendirme yapılır.
- Örtülü kanallar ve OLAP'ta çıkarım (ekrandan, 01:33:00, 01:37:45 ve 01:41:45)
  - Zorunlu model kullanılsa bile, daha yüksek seviyedeki nesneler hakkında çıkarımla (inference) bilgi sızabilir; bu özellikle istatistiksel veritabanlarında (OLAP, veri ambarı) ve dağıtık veritabanlarında görülür.
  - Kayıt düzeyi örnek: C seviyesindeki kullanıcı S seviyesindeki 101 anahtarlı kaydı göremez. 101 ile ekleme yapmaya çalışır; birincil anahtar ihlali alırsa 101'in var olduğunu çıkarır.
  - OLAP yalnız istatistiksel sorgulara izin verir ("how many people bought X" gibi). Herkes Ahmet'in en yaşlı öğrenci olduğunu biliyor. Q1: "Yaşı $\ge X$ olan kaç öğrenci var?" sorusu cevap 1 olana kadar $X$ artırılarak sorulur, $X = 35$ bulunur. Q2: "Yaşı $\ge 35$ olan öğrencilerin en yüksek GPA'sı nedir?" sorusuyla Ahmet'in GPA'sı (3,7) öğrenilir.
  - Önlem: Her sorgu en az $N$ satır üzerinde çalışmalıdır. Kötü niyetli kullanıcı yine vazgeçmez: Cevap $N$ olana kadar $X$'i artırır (örnekte $X = 28$). Q3: Yaşı $\ge 28$ olanların GPA toplamı (Ahmet dahil). Q4: Ahmet dışındaki ve kendisi dahil, yaşı $\ge 28$ olanların GPA toplamı. Ahmet'in GPA'sı = Q3 − (Q4 − kendi GPA'sı) = 3,7.

## Hocanın Özellikle Vurguladığı Kısımlar

- Assertion ve `REFERENCES` yetkisi
  - Assertion yazmak çok kolaydır ve kötü niyetle bir tabloyu bütün kullanıcılar için kullanılamaz hâle getirebilir; bu yüzden güçlü bir yetki olan `REFERENCES` gerekir. Yabancı anahtar için de aynısı geçerlidir. Hoca bunu sınavlarda da sorduğunu söyledi.
- Satır düzeyi ve komut düzeyi tetikleyici
  - `for each row` yazmak kolaydır; `for each statement` daha zordur ama toplu güncellemelerde çok daha verimlidir. Komut düzeyinde eylemin tek seferde doğru çalışması için kümülatif (`SUM`) işlemler ve eski/yeni geçici tablolar kullanılır.
  - Bir iki satır değişiyorsa komut düzeyinin karmaşıklığına değmez; çok veri ve yoğun yük varsa komut düzeyi akıllıcadır. Performans farkı küçük tablolarda (80-100 kayıt) ölçülemez, en az onlarca MB'lık tablolar gerekir.
- `before`/`after` ve tetikleyici türleri
  - Tetikleyicinin türü (önce/sonra, satır/komut) davranışı çok değiştirir; hoca bunu da sınavlarda sorduğunu söyledi.
- Tetikleyicilerin tehlikesi
  - Tetikleyiciler veritabanında tehlikeli nesneler olarak görülür; özellikle NoSQL dünyasında karmaşık işlerin uygulamaya havale edilmesinin daha temkinli olduğuna dair çok görüş vardır.
- Kör yazma
  - Bir `update`'in yalnız `update` yetkisiyle yapılıp yapılamayacağı, eski değeri okuyup okumamasına bağlıdır. Ayrıntıya inince yetkilerin yeterli olup olmadığına dikkat etmek gerekir.
- Takdire bağlı yöntemin zayıflığı
  - Kullanıcıya güven esasına dayanır; tabloyu kopyalayıp herkese açmak gibi basit işlemlerle bütün yetkilendirme alt üst edilebilir. Zorunlu model bu açığı kapatır, ama örtülü kanallar onu da aşabilir.

## Kısa Tekrar Notları

- Assertion: genel kısıt, `check (not exists ...)`; her işlemde denetlenir, sisteme yüklüdür.
- Tetikleyici: olay, koşul, eylem; `before`/`after`, `insert`/`update`/`delete`, view için `instead of`.
- `for each row` her satıra bir kez; `for each statement` komuta bir kez, toplu işlemlerde verimli.
- Satır düzeyinde `OLD ROW`/`NEW ROW`, komut düzeyinde `OLD TABLE`/`NEW TABLE`.
- Türetilmiş nitelik (`Total_sal`) saklanırsa ekleme, maaş değişikliği, silme ve bölüm değişikliğinde güncellenmeli.
- Komut düzeyi T2: `SUM(N.Salary) - SUM(O.Salary)` her bölüm için; koşulda iki `EXISTS`.
- Authentication ≠ authorization.
- Rol esaslı yetki: kullanıcı rollerin yetkilerinin birleşimini alır.
- `select` sorgudaki alanlarda; `insert`/`update`/`delete` ayrıca `where` alanlarında `select` ister.
- Kör yazma (`Grade = 100`) yalnız `update` ister; `Grade = Grade + 1` ayrıca `select` ister.
- Satır düzeyinde ince yetki için view (`PROF_ENROLLMENTS`, `current_user`).
- Assertion ve yabancı anahtar için `REFERENCES` yetkisi.
- `WITH GRANT OPTION` devretme yetkisi; grant diyagramında `**` sahip, `*` devredebilir.
- `REVOKE ... CASCADE` zincirleme kaldırır; `RESTRICT` yalnız ilk adımı.
- Zorunlu erişim denetimi: TS > S > C > UC; okuma aşağı doğru ($\text{class}(S) \ge \text{class}(O)$), yazma yukarı doğru ($\text{class}(S) \le \text{class}(O)$).
- Örtülü kanal: Birincil anahtar ihlalinden gizli kaydın varlığını çıkarmak.
- OLAP çıkarımı: Q1 ile yaş, Q2 ile en yüksek GPA; "en az $N$ satır" kısıtı Q3/Q4 farkıyla aşılır.

## Detaylı Açıklamalar

- Assertion örneği
  - Slayttaki `SmallSections` assertion'ı, `ENROLL` tablosunu şubeye göre gruplayıp kayıt sayısı 30'u aşan bir şube olup olmadığına bakar; böyle bir şube yoksa kısıt sağlanır (ekrandan, 00:08:05).
  - Ders sonrası not: Hoca bu kısıtı anlatırken "her şubenin mutlaka 30 öğrenci alması" dedi; slayttaki açıklamaya göre doğrusu "hiçbir şubede 30'dan fazla öğrenci olamaz"dır.
- `instead of` tetikleyicileri
  - Hoca `instead of` türünün genelde materialized view'larda kullanıldığını söyledi, sonra hem materialized hem normal view için örnek verdi.
  - Ders sonrası not: `instead of` tetikleyicileri büyük olasılıkla en çok sıradan (güncellenemeyen) view'larda kullanılır; örneğin PostgreSQL'de `INSTEAD OF` tetikleyicisi yalnız view'larda tanımlanabilir.
- T2'nin satır ve komut düzeyi biçimleri (ekrandan, 00:33:00 ve 00:38:25)
  - Satır düzeyinde maaşı değişen her satır için, bölüm numarası null değilse bölümün `Total_sal`'ına yeni maaş eklenip eski maaş çıkarılır; fark pozitif ya da negatif olabilir. Yüzlerce kişinin maaşı tek bir `update` ile değişirse koşul ve eylem yüzlerce kez çalışır.
  - Komut düzeyinde `O` tablosunda değişen satırların eski hâli, `N` tablosunda yeni hâli bulunur; değişmeyen satırlara dokunulmaz. Koşul, `N` ya da `O` içinde bölüm numarası null olmayan en az bir satır olmasıdır. Eylem, `N` ya da `O`'da geçen her bölüm için yeni maaşların toplamını ekleyip eski maaşların toplamını tek bir `UPDATE` ile çıkarır.
  - Slayttaki örnek veride iki satır değişir: Bölüm 1'de maaş 200'den 700'e, bölüm 2'de 300'den 900'e (ekrandan, 00:38:25). Bölüm 1'in `Total_sal`'ı $700 - 200 = 500$, bölüm 2'ninki $900 - 300 = 600$ artar (ara adım eklendi). Bu satırların bölüm numaraları null olsaydı hiçbir bölüm güncellenmezdi.
  - Koşulda iki `EXISTS` olmasının nedeni (slayt notundan, ekrandan, 00:33:00): Aynı `update` maaşla birlikte bölüm numarasını da değiştirebilir; maaşı değişen bütün satırların bölüm numarası null'a çekilirse yalnız `N`'ye bakan koşul maaş değişikliklerini kaçırır.
- Grant diyagramı örneği (ekrandan, 01:14:00 ve 01:17:30)
  - Admin, `GRANT select, insert ON ENROLL to prof, asistan WITH GRANT OPTION` verir. Prof rolündeki kullanıcı `GRANT select, insert ON ENROLL to sekreter`, asistan rolündeki kullanıcı `GRANT select, insert(EId) ON ENROLL to sekreter` verir.
  - Admin `REVOKE select, insert ON ENROLL FROM asistan CASCADE` yapınca asistanın iki düğümü ve asistanın sekretere verdiği `insert(EId)` yetkisi kalkar. Sekreterin `select` yetkisi prof'tan da geldiği için kalır; prof'tan gelen `insert` yetkisi de kalır.
- Zorunlu model ve uygulama kodu açığı (ekrandan, 01:25:00)
  - Hoca okuma ve yazma kurallarını anlatırken önce yazma kuralını ters söyledi, sonra düzeltti: Bir özne kendi seviyesindeki ya da daha düşük seviyedeki veriyi okuyabilir, ama yalnız kendi seviyesindeki ya da daha yüksek seviyedeki nesneye yazabilir. Aksi hâlde gizli bilgi aşağı doğru akardı.
  - `TakeAPeek` tablosu profesör (S) tarafından oluşturulduğu için S seviyesindedir; profesör onu public yapsa da C seviyesindeki kullanıcılar okuma kuralı yüzünden okuyamaz.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
