# Ders 11 Genişletilmiş Notu: Aktif Veritabanları (Tetikleyiciler) ve Veritabanı Güvenliği (Yetkilendirme, Zorunlu Erişim Denetimi, Örtülü Kanallar)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Kapsamı
- 2. Genel Kısıtlar: Assertion
- 3. Tetikleyicilerin Genel Yapısı
- 4. Basit Tetikleyici Örnekleri
- 5. Türetilmiş Nitelik ve Tutarlılık: Total_sal
- 6. Satır Düzeyinde ve Komut Düzeyinde T2
- 7. Yetkilendirme: Takdire Bağlı ve Zorunlu
- 8. Roller ve Nitelik Düzeyinde Yetkiler
- 9. SQL Komutlarının Gerektirdiği Yetkiler
- 10. View ile İnce Ayar
- 11. Assertion, Yabancı Anahtar ve REFERENCES Yetkisi
- 12. WITH GRANT OPTION, Grant Diyagramları ve REVOKE
- 13. Zorunlu Erişim Denetimi
- 14. Örtülü Kanallar ve OLAP'ta Çıkarım
- Örnek Sorular

## 1. Dersin Kapsamı

Hoca önceki derslerin akışını hatırlattı: Normalizasyon bitirilmiş, sonra NoSQL veritabanları hakkında genel bilgi verilmiş, ardından fiziksel tasarım ve indeksler işlenmişti. Bu derste iki konu vardı: Aktif veritabanları (active databases) başlığı altında daha kapsamlı tetikleyiciler ve güvenlik konusunun eksik kalan kısımları.

Hoca güvenliğin son yıllarda siber güvenliğin bir alt başlığı olarak çok geniş bir alan olduğunu, bir haftaya sığmayacağını, eski ders notlarından düzenlediği bazı kısımları paylaşacağını söyledi. Bunların bir kısmı SQL ile yapılabilecek şeylerdir (grant, revoke, `REFERENCES` yetkisi). Ek olarak zorunlu erişim denetimi (mandatory access control) ve istatistiksel veritabanlarında örtülü kanallar (covert channels) denen, sistemin açık noktalarından ilginç bilgi sızdırma teknikleri ele alındı. Hocanın vurguladığı gibi, yetkilendirme ve kimlik doğrulama yapılsa bile bu açık noktalardan veri dışarı sızabilir.

Sunu "Veri Bütünlüğü Programlama ve Güvenlik" başlıklıdır (ekrandan, 00:08:05). Hoca sunuların yaklaşık 40 sayfa olduğunu, yine Elmasri ve Navathe'nin kitabından yararlanıldığını söyledi. Öğrenci kayıt veritabanı örnekleri ise başka bir kitaptan alınmıştır.

<!-- BELİRSİZ: Öğrenci kayıt veritabanı örneklerinin alındığı kitabın adı altyazıda geçmiyor. -->

## 2. Genel Kısıtlar: Assertion

Tetikleyicilere geçmeden önce hoca daha önce görülen basit assertion örneklerini hatırlattı. Assertion'ların grameri oldukça basittir; ama yetki isteyen bir işlemdir: `REFERENCES` yetkisi gerektirir (bkz. Bölüm 11). Hoca bunu iki sınavda da sorduğunu söyledi. Sebebi, kötü niyetli bir assertion ile veritabanının kullanılamaz hâle getirilip bütün kullanıcılara zarar verilebilmesidir.

Hoca derste üç örnek veritabanı olduğunu hatırlattı: Derste ve laboratuvarda kullanılan COMPANY veritabanı, Silberschatz'ın üniversite veritabanı ve başka bir kitaptaki bu öğrenci kayıt veritabanı. Sorgulara geçmeden önce şemayı hazmetmek, anahtarları ve yabancı anahtarları kafada canlandırmak gerekir. Slayttaki şema şöyledir (ekrandan, 00:08:05):

```text
STUDENT(SId, SName, GradYear, MajorId)
DEPT(DId, DName)
COURSE(CId, Title, DeptId)
SECTION(SectId, CourseId, Prof, YearOffered)
ENROLL(EId, StudentId, SectionId, Grade)
```

Öğrenciler bölümlere bağlıdır (`MajorId`); dersler bir bölümde açılır; derslerin altında şubeler (section) açılır, her şubeyi bir hoca verir ve şube belli bir yılda açılır; öğrenciler şubelere kayıt olur. Hocaya göre bu şema derste kullanılan üniversite veritabanına benzer, ama adlandırma farklı ve tasarım biraz daha kabadır.

Slayttaki assertion:

```sql
create assertion SmallSections
  check (not exists
           select e.SectionId
           from ENROLL e
           group by e.SectionId
           having count(e.EId) > 30)
```

Slayttaki açıklamaya göre bu, "hiçbir şubede 30'dan fazla öğrenci olamaz" bütünlük kısıtının SQL ifadesidir.

> **Ders sonrası not:** Hoca bu örneği anlatırken "her şubenin mutlaka 30 öğrenci alması" dedi; slayttaki açıklamaya ve sorguya göre doğrusu, hiçbir şubede 30'dan fazla öğrenci olmamasıdır.

Hoca assertion'ların formatının genelde `check (not exists ...)` ya da `check (exists ...)` biçiminde, ilişkili (correlated) sorgu tarzında olduğunu söyledi. Bir öğrencinin aynı şubeyi birden çok almaması ya da bir dersi en fazla bir kez alması gibi daha kritik kısıtlar da böyle yazılır; slaytlarda bunların açıklamaları vardır.

## 3. Tetikleyicilerin Genel Yapısı

### 3.1 Tarihçe ve tutum

Hoca tetikleyicilerin genel literatürde "olmazsa olmaz ama uzak durulması gereken" bir şey olarak geçtiğini söyledi. Tarihçesi veritabanlarının ilk zamanlarına dayanır; yeni bir kavram değildir. Günümüzde NoSQL veritabanlarında karmaşık işler (karmaşık join'ler, tetikleyici tarzı işler) çoğunlukla uygulamaya havale edilir, veritabanı basit bir iskelet olarak tutulur. Buna karşın geleneksel veritabanlarında tetikleyicilerin kullanılması bazı durumlarda zaruridir ve kapsamı geniş olabilir; bu durumda sistem verimiyle ilgili noktalara dikkat etmek gerekir. Dersin bu kısmının konusu da budur.

### 3.2 Olay, koşul, eylem

Tetikleyicinin temel yapısı olay, koşul, eylem (event, condition, action) biçimindedir. Hoca bunu assertion ile karşılaştırdı: Assertion her harekette, her etkinlikte denetlenir; bu yüzden sisteme büyük bir yük getirir. Tetikleyicide ise bir olayla denetim şekillendirilir: "Şu tablonun şu kolonunda `insert` olduğunda" ya da "şu tabloda şu nitelikler üzerinde `update` olduğunda" gibi. Olay gerçekleşince koşula bakılır, koşul sağlanırsa eylem yapılır.

### 3.3 Sözdizimi

Temel gramerde `create trigger` yerine `create or alter` da kullanılabilir. Mevcut bir tetikleyicinin tanımı değiştirilip `create trigger` komutu yeniden çalıştırılırsa, tetikleyici zaten var olduğu için hata alınır; ya önce `drop` edilmeli ya da `create or alter` kullanılmalıdır. Hoca aynı biçimin fonksiyonlarda, prosedürlerde ve view'larda da olduğunu söyledi.

> **Ek bilgi (derste anlatılmadı):** `CREATE OR ALTER` sözdizimi SQL Server'a özgüdür. Oracle ve PostgreSQL'de aynı iş `CREATE OR REPLACE` ile yapılır; PostgreSQL'de tetikleyiciler için `CREATE OR REPLACE TRIGGER` 14. sürümle büyük olasılıkla eklendi.

Tetikleyiciye bir ad verilir. Ardından olay gelir: `after insert on <tablo>`, yani tabloya ekleme yapıldıktan sonra. Hoca öncesi ve sonrasının önemli olduğunu hatırlattı: `after` tetikleyicisinde koşul, işlemden sonra ortaya çıkan tablo üzerinde değerlendirilir ve oradaki veri kullanılır.

### 3.4 Satır düzeyi ve komut düzeyi

`for each row` ile değişen her satır için koşul denetlenir ve eylem yapılır. Hoca burada asıl konuya bağlantı kurdu: Bazı eklemeler `insert into` ile tek tek yapılır, ama veritabanlarında toplu (bulk) yükleme imkânları da vardır; `COPY` gibi komutlar veriyi çok daha verimli yükler. Toplu güncelleme, toplu yükleme ve toplu silmelerde (bulk delete, bulk update, bulk insert) hem işlemin kendisi veritabanında optimize edilerek gerçeklenebilir hem de ona bağlı bir tetikleyici varsa, eylemi her satır için ayrı ayrı yapmak yerine bütün eklemeler için bir kez yapmak çok daha elverişli olur.

### 3.5 Tetikleyici türleri

Yaygın kullanılan türler: `before insert`, `after insert`, `before update`, `after update`, `before delete`, `after delete` ve son olarak `instead of`. Hoca `instead of` türünü şöyle açıkladı: Bir view üzerinde işlem yapılmak istendiğinde, işlem view üzerinde değil, view'un bağlantılı olduğu temel tablolarda yapılır; "instead of" adı buradan gelir. Hoca bunun genelde materialized view'larda kullanıldığını söyledi, sonra hem materialized hem normal view için örnek verdi. Sunularda örneği yoktur. Hoca türler arasındaki farkın davranışı çok değiştirdiğini ve bunu sınavlarda sorduğunu belirtti.

> **Ders sonrası not:** `instead of` tetikleyicileri büyük olasılıkla en çok sıradan, doğrudan güncellenemeyen view'larda kullanılır; örneğin PostgreSQL'de `INSTEAD OF` tetikleyicisi yalnız view'larda tanımlanabilir.

## 4. Basit Tetikleyici Örnekleri

### 4.1 Not değişikliklerinin günlüğü

Slayttaki ilk tetikleyici (ekrandan, 00:16:30):

```sql
create trigger LogGradeChange
  after update of Grade in ENROLL
  for each row
  referencing old row as oldrow, new row as newrow
  when oldrow.Grade <> newrow.Grade
    insert into GRADE_LOG(UserName, DateChanged, EId,
                          OldGrade, NewGrade)
    values(current_user, current_date, newrow.EId,
           oldrow.Grade, newrow.Grade)
```

Slayttaki açıklama: Öğrenci notlarındaki değişiklikleri günlüğe kaydeden bir SQL tetikleyicisi. Hoca akışı şöyle anlattı: `ENROLL`'da bir not güncellendiğinde, değişen her satır için eski satır `oldrow`, yeni satır `newrow` olarak tanımlanır. Notta gerçekten bir değişiklik varsa, değişiklik bir günlük tablosuna kopyalanır. Olay `after update of Grade in ENROLL`, koşul `when oldrow.Grade <> newrow.Grade`, eylem `insert into GRADE_LOG ...` kısmıdır.

Hoca bu tür günlüklerin sistem düzeyinde zaten tutulduğunu (bu, veritabanı sistem gerçeklemede görülür), örnekte ayrıca kullanıcı düzeyinde de tutulmak istendiğini söyledi.

### 4.2 Mezuniyet yılının denetlenmesi

İkinci örnekte yeni bir öğrenci eklendiğinde, eklenen her satır için mezuniyet yılı (`GradYear`) geçerli yıla göre denetlenir; koşul sağlanmıyorsa `GradYear` yerine null atanır. Hoca bunu bir giriş yılı ve dört yıl sonrası üzerinden örneklendirdi.

<!-- BELİRSİZ: Hocanın anlatımında koşulun yönü ("şu andaki tarihten 4 sene sonradan daha fazla olması lazım; değilse null") ve örnek yıllar (2000 girişte 2004, 2024-2026) birbiriyle tutarlı değil; slayttaki tetikleyici kodunun karesi okunmadı. -->

## 5. Türetilmiş Nitelik ve Tutarlılık: Total_sal

### 5.1 Şema

Hoca bu kısımda öğrencilerin tanıdığı COMPANY veritabanının biraz değiştirilmiş bir şemasını kullandı. `EMPLOYEE` tablosunda maaş (`Salary`), bölüm numarası (`Dno`) ve yönetici (`Supervisor_ssn`) zaten vardı; `DEPARTMENT` tablosunda da `Dno` ve `Mgr_ssn` vardı. Bu sefer `DEPARTMENT`'a her bölümdeki toplam maaşı tutan `Total_sal` niteliği eklendi. Hoca bunun normalizasyonu bozan türden bir değişiklik olmadığını, masum görünen bir ekleme olduğunu söyledi.

Ama `Total_sal` aslında türetilmiş (derived) bir bilgidir: Kavramsal tasarımda da söylendiği gibi, gerektiğinde hesaplanabilir. Hoca bunu fiziksel olarak saklamanın tehlikeli olabileceğini daha önce söylediğini hatırlattı: Yaş yerine doğum tarihi saklanmalıdır; toplam kredi yerine öğrencinin aldığı her dersin kredisi saklanır ve not ortalaması istendiğinde hesaplanır (bir tetikleyici ya da saklı yordamla). Türetilmiş bilgiyi saklamak, onun tutarlılığını sağlamak zorunda olmak demektir.

### 5.2 Tutarlılığı bozan olaylar

**Soru:** `DEPARTMENT.Total_sal`'ın `EMPLOYEE` tablosuyla tutarlı kalması gerekir. Bu tutarlılığı tehdit eden işlemler nelerdir? **Cevap:** Hoca dört olayı sıraladı:

- T1, yeni çalışan ekleme: Bir bölüme yeni çalışan eklenince bölümün `Total_sal`'ı yeni çalışanın maaşını içermelidir. Bunun için `after insert on Employee` olayına bir tetikleyici gerekir; eklenen her satır için bölüm güncellenir. Koşul: Eklenen çalışanın bölüm numarası girilmemişse eylem gerekmez. `Dno` üzerinde `not null` kısıtı yoksa, çalışan bir bölüme henüz atanmadan yalnız adı, SSN'i, adresi ve yöneticisiyle eklenebilir. 100 çalışan eklenip hiçbirinin bölüm numarası yoksa tutarlılık zaten bozulmaz.
- T2, maaş değiştirme: Örneğin maaşı belli bir değerin altındaki herkese %5 zam yapılırsa, tek bir `update` komutuyla 100 kişinin maaşı değişebilir. Maaşı değişen her satır için, kişinin bölümü null değilse bölümün toplamı güncellenmelidir.
- T3, çalışan silme: Silinen çalışanlardan en az biri bir bölüme bağlıysa, o bölümün toplamı çıkan kişinin maaşı kadar azalmalıdır.
- T4, bölüm değiştirme: Bir çalışanın bölümü değişirse önceki bölümün toplamından kişinin maaşı çıkarılır, yeni bölümün toplamına eklenir.

Hoca buradan şu sonucu çıkardı: Bir tabloya tek bir nitelik eklemek hafif bir işlem değildir; bu güncelleme ya uygulamaya havale edilir ya da tetikleyicilerle sağlanır. Dört durum `for each row` ile, grameri dikkatli kullanarak kolayca yazılabilir; `for each statement` ise daha zordur ama daha verimlidir.

### 5.3 T1

Slayttaki T1 (ekrandan, 00:27:30):

```sql
CREATE TRIGGER Total_sal1
  AFTER INSERT ON Employee
  FOR EACH ROW
  WHEN (NEW.Dno is NOT NULL)
    UPDATE DEPARTMENT
    SET Total_sal = Total_sal + NEW.Salary
    WHERE Dno = NEW.Dno;
```

Slaytta `AFTER INSERT ON Employee` olay, `WHEN (NEW.Dno is NOT NULL)` koşul, `UPDATE DEPARTMENT ...` eylem olarak işaretlenmiştir. Eklenen çalışanın bölümü null ise hiçbir şey yapılmaz; değilse `DEPARTMENT`'ta `NEW.Dno` bölümü bulunur ve toplamına eklenen yeni satırın maaşı eklenir. `NEW` burada ayrıca tanımlanmamıştır, varsayılan addır.

Hoca gösterimin Oracle tarzı olduğunu, merak edenlerin PostgreSQL formatına çevirebileceğini söyledi; geçmiş yıllarda bunu proje ya da ödev olarak verdiğini, bu yıl vermediğini ama öğrenmek isteyenlerin yazabileceğini ekledi.

## 6. Satır Düzeyinde ve Komut Düzeyinde T2

### 6.1 Satır düzeyi

Slayttaki satır düzeyi T2 (ekrandan, 00:33:00):

```sql
CREATE TRIGGER Total_sal2
  AFTER UPDATE OF Salary ON EMPLOYEE
  REFERENCING OLD ROW AS O, NEW ROW AS N
  FOR EACH ROW
  WHEN ( N.Dno IS NOT NULL )
    UPDATE DEPARTMENT
    SET Total_sal = Total_sal + N.salary - O.salary
    WHERE Dno = N.Dno;
```

Hoca akışı şöyle açıkladı: `EMPLOYEE` tablosunda `Salary` güncellenince, maaşı değişen çalışanların eski hâlleri `O`, yeni hâlleri `N` olur. Bu tetikleyicide yalnız maaş değiştirildiği, bölüm numarası değiştirilmediği varsayıldığı için null denetiminde `N`'ye ya da `O`'ya bakmak yeterlidir. Bölüm null değilse bölümün toplamından eski maaş çıkarılır, yeni maaş eklenir; yani toplam aradaki fark kadar değişir. Fark pozitif ya da negatif olabilir, çünkü maaş artırılmış da azaltılmış da olabilir.

Maaşı güncellenen yüzlerce kişi varsa bu tetikleyici daha uzun sürer, çünkü koşul ve eylem her satır için ayrı çalışır. Hoca bunun çok korkunç bir gecikme olmayabileceğini, kendisinin bununla ilgili bir laboratuvar ölçümü yapmadığını, merak edenleri bakmaya teşvik ettiğini söyledi. Anlamlı bir performans ölçümü için tablolarda yeterli veri olmalıdır: 80-100 kayıtla ölçüm yapmanın anlamı yoktur; tabloların en az 10-20 MB, hatta 80-100 MB olması gerekir. Bir iki kişinin maaşı değişiyorsa komut düzeyinin karmaşıklığıyla uğraşmaya değmez; veritabanı yüklüyse komut düzeyi yazmak akıllıcadır.

### 6.2 Komut düzeyi

Slayttaki komut düzeyi T2 (ekrandan, 00:33:00):

```sql
CREATE TRIGGER Total_sal2
  AFTER UPDATE OF Salary ON EMPLOYEE
  REFERENCING OLD TABLE AS O, NEW TABLE AS N
  FOR EACH STATEMENT
  WHEN EXISTS ( SELECT * FROM N WHERE N.Dno IS NOT NULL ) OR
       EXISTS ( SELECT * FROM O WHERE O.Dno IS NOT NULL )
    UPDATE DEPARTMENT AS D
    SET D.Total_sal = D.Total_sal
        + ( SELECT SUM (N.Salary) FROM N WHERE D.Dno=N.Dno )
        - ( SELECT SUM (O.Salary) FROM O WHERE D.Dno=O.Dno )
    WHERE Dno IN ( ( SELECT Dno FROM N ) UNION ( SELECT Dno FROM O ) );
```

Hoca bunu ekranda kalemle çizdiği şekillerle anlattı. Arkadaki veri öbekleri şöyle hayal edilebilir: `EMPLOYEE`'nin esas tablosu; maaşı değişenlerin yeni hâllerini içeren `N` tablosu (örneğin 100 kişi); aynı 100 kişinin maaşı değişmeden önceki hâllerini içeren `O` tablosu; ve bu `update`'e hiç maruz kalmayan, maaşı değişmeyenler. Maaşı değişmeyenlere hiç dokunulmaz.

Koşul: `O`'da ya da `N`'de bölüm numarası null olmayan en az bir kayıt varsa eylem yapılmalıdır. Örneğin bunlardan yalnız biri bir bölüme bağlıysa o bölüm güncellenmelidir.

Eylemin bir kez çalışması için dikkat edilmesi gereken nokta kümülatif işlemlerdir: Maaşı değişenlerin yeni maaşlarının toplamı ve eski maaşlarının toplamı her bölüm için ayrı hesaplanır. Bir bölüm `N` ya da `O` içinde geçiyorsa o bölümde bir şey olacak demektir: O bölüme `N` tablosundaki yeni maaşların toplamı eklenir, `O` tablosundaki eski maaşların toplamı çıkarılır. Hoca burada büyük resmin kaçırılmaması gerektiğini vurguladı: Değişen 100 kişiden 20'si o bölümdeyse, tek bir kişinin değil 20 kişinin toplamı işlenir. Bu kurgu kümülatif fonksiyonlarla tek bir sorguda yazılabilir.

### 6.3 Örnek veriyle doğrulama

Hoca sunuya eklediği örnek veriyle bunu somutlaştırdı (ekrandan, 00:38:25). Olay: Yalnız maaş değişiyor.

```text
Old O                 New N
Salary  DNO           Salary  DNO
200     1             700     1
300     2             900     2
```

Bölüm 1'de bir kişinin maaşı 200'den 700'e, bölüm 2'de bir kişinin maaşı 300'den 900'e çıkıyor. Hoca bunun temsili olduğunu, gerçekte birçok kişinin bir değerden başka değere geçebileceğini söyledi. Eylem, her bölüm için eski değerlerin toplamını çıkarıp yeni değerlerin toplamını ekler:

- Bölüm 1: $\text{Total\_sal} \leftarrow \text{Total\_sal} + 700 - 200 = \text{Total\_sal} + 500$ (ara adım eklendi).
- Bölüm 2: $\text{Total\_sal} \leftarrow \text{Total\_sal} + 900 - 300 = \text{Total\_sal} + 600$ (ara adım eklendi).

Bu değişen satırların bölüm numaraları null olsaydı, hem eski hem yeni versiyonda null olacaklardı; koşul sağlanmaz, hiçbir bölüm güncellenmezdi. Yani bu satırlar dışarıda bırakılırdı.

### 6.4 Neden iki EXISTS?

Hoca bir inceliğe dikkat çekti: Aynı `update` komutunda hem `Salary` hem `Dno` değişebilir. `Salary`'nin güncellenmesi bu daha kapsamlı olayın bir alt olayı olduğu için T2 yine tetiklenir. Bu yüzden komut düzeyinde yalnız bir tabloya bakılmamış, hem `N` hem `O` denetlenmiştir; eylemde de bölüm `N` ya da `O` içinde geçiyor mu diye bakılır. Slaytın notunda gerekçe şöyle yazılıdır (ekrandan, 00:33:00): Maaşla birlikte bölüm numaraları da değiştirilir ve hepsi null'a çekilirse, yalnız `N`'ye bakan bir koşul maaş değişikliklerini kaçırır.

Slaytta ayrıca hem maaşın hem bölüm numarasının değiştiği durum için bir örnek veri sayfası da vardır; hoca bunun kümülatif fonksiyonlarla doğrulanabileceğini söyledi.

> **Hocanın vurgusu:** Komut düzeyinde iki geçici tablo (`O` ve `N`) üzerinde kümülatif fonksiyonlar kullanılarak, maaş güncellemesi tek bir eylemle çok daha verimli yapılabilir. Hoca bunun kâğıt üzerinde örnek veriyle ve makinede (Oracle sözdizimi PostgreSQL'e çevrilerek) denenmesini önerdi. Komut düzeyi biçimin yalnız T2 için yazıldığını; T1, T3 ve T4'ü de komut düzeyine çevirmenin, doğruluğunu bir veri kümesinde sınamanın ve büyük veride (örneğin 100 MB'lık veride 500-1000 kayıt değişirken) hız farkını ölçmenin güzel bir laboratuvar çalışması olacağını söyledi.

Hoca bölümü yine bir uyarıyla kapattı: Tetikleyiciler veritabanında tehlikeli nesneler olarak görülür; özellikle NoSQL veritabanlarında böyle karmaşık işleri uygulamaya havale etmenin daha temkinli olduğuna dair birçok yorum vardır.

## 7. Yetkilendirme: Takdire Bağlı ve Zorunlu

Güvenlik kısmında hoca önce terimleri ayırdı: Konu kimlik doğrulama (authentication) değil, yetkilendirmedir (authorization). Elbette bir kişiye yetki vermeden önce o kişinin gerçekten o kişi olduğunun doğrulanması gerekir. Çok kullanıcılı bir ortamda (5-10 kişi de olabilir, 5-10 milyon kişi de) gerçek zamanlı uygulamalarda bu işlere bakan ayrı sunucular ve servis sağlayıcılar vardır (authorization server, authentication server gibi).

İki tür yetkilendirme vardır:

- Takdire bağlı (discretionary) yetkilendirme: Önceki derslerde öğrenilen yöntemdir. Tablolar ya da tabloların nitelikleri üzerinde kullanıcılara ya da rollere yetkiler (privilege) verilir; bu yetkiler başkalarına dağıtılabilecek şekilde de verilebilir. SQL bunu `grant` ve `revoke` ile kolayca yapar.
- Zorunlu (mandatory) yetkilendirme: Daha katı ama daha güvenlidir; sistemin açık noktalarını (loophole) daha dikkatli kapatır. SQL'in desteklediği bir şey değildir. Uygulamalar ve başka sistemler içinde güvenlik sınıflarının belirlenmesi ve koordinasyonu gerektirir; bu yüzden derste daha önce anlatılmamıştı. Ama siber güvenliğin veritabanına bakan tarafında önemli bir konudur.

## 8. Roller ve Nitelik Düzeyinde Yetkiler

Bir tabloyu oluşturan kişi onun üzerindeki bütün yetkilere sahiptir: Silebilir, değiştirebilir, üzerinde istediği sorguyu yapabilir. Bilinen yetkiler `SELECT`, `INSERT`, `UPDATE`, `DELETE`'tir. Bunlarla birlikte `REFERENCES` oldukça güçlü bir yetkidir. Tetikleyici oluşturma ve fonksiyon çalıştırma yetkileri de vardır. Hoca slayttaki `UNDER` ve `USAGE` gibi yetkileri hatırlamadığını, bunların SQL standardında olup sistemlerde olmayabileceğini söyledi.

### 8.1 Rol esaslı yetkilendirme

Slayttaki öğrenci kayıt veritabanında yetkiler küçük dünyanın gerektirdiğine göre dekan, kayıt ofisi (registrar), kabul ofisi (admission office), profesör ve öğrenci gibi rollere dağıtılmıştır; tabloların tamamı ya da belli nitelikleri rollere verilmiştir.

Hoca çoğu veritabanında yetkilendirmenin rol esaslı olduğunu ve bunun koordinasyon için çok elverişli olduğunu söyledi. Rollerin sayısı kullanıcı sayısından azdır ve daha üst düzeyli bir resim verir. Bir dekan rolü vardır ama tek bir dekan yoktur: 100 fakülte varsa 100 kişi dekan rolü altındadır. Bir kullanıcı oluşturulup (`create user`) rollere atanınca o rollerin yetkileri otomatik olarak ona geçer. Bir kişi hem dekan hem profesörse iki rolün yetkilerinin birleşimini (union) alır. Roller kolay kolay değişmez; kullanıcılar ise rollere girip çıkabilir, birden çok rol alabilir ya da hiçbir rolü olmayıp ayrıca yetki verilmiş bir kullanıcı olabilir. Rol ve kullanıcı tanımları bu açıdan çok esnektir.

### 8.2 Nitelik düzeyinde yetki

`grant select on ENROLL to ...` gibi bir yetki hocanın deyişiyle kabaca "ya hep ya hiç"tir. Bunun yerine ayrıntılandırılabilir:

```sql
grant select(StudentId, Grade) on ENROLL to dean, professor;
```

Bu rollerdeki kişiler yalnız `StudentId` ve `Grade` üzerinde okuma yetkisi alır; `ENROLL`'daki diğer ayrıntıları görmeleri gerekmez. Küçük dünya neyi gerektiriyorsa yetkiler o şekilde ayrıntılandırılır.

## 9. SQL Komutlarının Gerektirdiği Yetkiler

Slayttaki kurallar (ekrandan, 00:54:15):

- `select`, sorguda geçen her alanda `select` yetkisi gerektirir.
- `insert` (`update`), eklenecek (değiştirilecek) alanda `insert` (`update`) yetkisi ve buna ek olarak `where` kısmında geçen her alanda `select` yetkisi gerektirir.
- `delete`, `delete` yetkisi ve `where` kısmında geçen her alanda `select` yetkisi gerektirir.

Slayttaki tablo, komutları çalıştırmak için gereken en az yetkileri verir:

```text
Komut                                             Gereken yetkiler
select s.SId, s.SName, count(e.EId)               select(SId, SName) on STUDENT
from STUDENT s, ENROLL e                          select(EId, StudentId, Grade) on ENROLL
where s.SId = e.StudentId and e.Grade = 'A'
group by s.SId, s.SName

select c.*                                        select on COURSE
from COURSE c                                     select(DId, DName) on DEPT
where c.DeptId in
  (select d.DId from Dept d
   where d.DName = 'math')

delete from SECTION                               select(SectId) on SECTION
where SectId not in                               delete on SECTION
  (select e.SectionId from ENROLL e)              select(SectionId) on ENROLL
```

Hoca ilk komutta herhangi bir güncelleme olmadığı için yalnız erişilen niteliklerde `select` yetkisinin yeterli olduğunu; ikinci komutta `COURSE`'un bütün niteliklerine erişildiği için `select on COURSE`, `DEPT`'te ise yalnız `DId` ve `DName`'e erişildiği için bu iki nitelikte `select` gerektiğini; üçüncüde `delete` yetkisinin ve okunan tablolarda `select` yetkisinin gerektiğini açıkladı.

### 9.1 Kör yazma

Slaytın altında bir soru vardır: Profesöre `GRANT update(Grade) ON ENROLL to professor` verilmişse, profesör şunları yapabilir mi?

```sql
UPDATE ENROLL e SET e.Grade = 100;
UPDATE ENROLL e SET e.Grade = e.Grade + 1;
```

Hoca bazı `update`'lerin `select` de gerektirebileceğini, yalnız `update` yetkisinin yetmeyebileceğini açıkladı. İlk komut `ENROLL`'daki bütün notlara 100 verir; bu işlemde hiçbir okuma yoktur. Buna kör yazma (blind write) denir: Eski not okunmaz, "eski notu bir artır" ya da "yarıya böl" gibi bir işlem değildir. Bu yüzden `select` yetkisine gerek yoktur. İkinci komut ise kör yazma değildir: Bir puan yanlış kırılmış ve bir puan ekleniyor gibi, eski not okunur. Bu durumda profesöre verilen `update` yetkisi yetmez; `select` yetkisi de gerekir. Hoca ayrıntıya inildiğinde yetkilerin yeterli olup olmadığına dikkat etmek gerektiğini vurguladı.

## 10. View ile İnce Ayar

Tablo esaslı ve nitelik esaslı yetkiler de yetmeyebilir. `ENROLL` tablosunda birçok profesörün notu vardır; her profesörün yalnız kendi verdiği derslerin notlarına bakabilmesi gerekir. Öğrenci için de benzer şekilde, her öğrenci yalnız kendi notuna bakabilmelidir. Doğrudan `grant select(Grade) on ENROLL to professor` dendiğinde bu sağlanamaz.

Slayttaki açıklama (ekrandan, 00:58:20): `GRANT update(Grade) on ENROLL to professor` gibi kolon yetkileri rollere çok fazla güç verir; bir profesör başka bir profesörün verdiği notu değiştirebilir. Çözüm: Profesörlerin `ENROLL` üzerindeki önceki yetkileri geri alınır ve şu view üzerinde yetki verilir:

```sql
create view PROF_ENROLLMENTS as
  select e.*
  from ENROLL e
  where e.SectionId in
        (select k.SectId
         from Section k
         where k.Prof = current_user);

grant select        on PROF_ENROLLMENTS to professor;
grant update(Grade) on PROF_ENROLLMENTS to professor;
```

Hoca bunu şöyle açıkladı: `current_user`, o anda sisteme bağlı olan, konsoldaki profesördür. View, profesörün verdiği şubelerin `ENROLL`'daki kayıtlarını içerir. Hoca bunun ilişkili bir sorgu olmadığını, küme esaslı bir sorgu olduğunu belirtti. Profesör bu kayıtları hem okuyabilir hem notlarını güncelleyebilir.

Slaytta ikinci bir örnek de vardır:

```sql
Create view CurrYearGrades AS
  Select YearOffered, Grades
  From ENROLL e, SECTION s
  Where e.SectionId = s.SectId and YearOffered = extract(YEAR, current_date);

GRANT select ON CurrYearGrades to DEAN;
```

Slayt notuna göre bu örnekte dekan yalnız bu yılın notlarını görebilir, "hangi öğrenci hangi notu aldı" bilgisini göremez (ekrandan, 00:58:20).

## 11. Assertion, Yabancı Anahtar ve REFERENCES Yetkisi

Aradan sonra hoca assertion'ın neden ayrı bir yetki gerektirdiğini gösteren örneğe geçti. Daha önce assertion'ın tehlikeli olabileceğinden söz etmişti. Slayttaki örnekte yazılması çok kolay bir assertion, `student` tablosunda yalnız belirli bir ad ve sıfır mezuniyet yılı içeren veriye izin verir; bunun dışında hiçbir şeye izin vermez. Böylece kimse tabloya hiçbir şey ekleyemez, hiçbir şeyi değiştiremez; zararlı tek bir sorguyla tablo kullanılamaz hâle getirilir.

<!-- BELİRSİZ: Slayttaki kötü niyetli assertion'ın tam metni altyazıdan çıkmıyor ("ABC ve 0 grad year"); karesi okunmadı. -->

Bu yüzden "grant assertion" diye bir yetki yoktur. Hem assertion tanımlamak hem yabancı anahtar tanımlamak için `GRANT REFERENCES` biçiminde, daha güçlü bir yetki vardır; böyle bir yetki yalnız güvenilir kişilere verilmelidir. Hoca yabancı anahtar örneğini de sınavda sorduğunu söyledi.

Yabancı anahtar tanımlanırsa, yabancı anahtarın işaret ettiği tablodaki etkinlikler kısıtlanmış olur. Örneğin `ENROLL` tablosu `STUDENT`'a işaret eden bir yabancı anahtarla ve `on delete no action` kısıtıyla oluşturulursa, `STUDENT`'ın kendi sahibi kısıtlanmış olur, çünkü silme yapması engellenir. Hoca `cascade` gibi daha hafif seçenekler kullanılsaydı sorun olmayacağını söyledi. Yabancı anahtar ve assertion'da başka bir tabloya "referans" anlamı vardır: Başka birinin tablosu üzerinde kısıtlar konur. Bu yüzden `select` yetkisi yeterli değildir; `GRANT REFERENCES` gerekir. Slaytta böyle bir tablo tanımının neden reddedildiği ve `REFERENCES` yetkisi verildikten sonra tablonun oluşturulabildiği gösterilir. Hoca bunun konsoldan denenmesini önerdi: Sistem bir kullanıcının, sahibi olmadığı başka bir tabloya `REFERENCES` yetkisi olmadan referans vermesine izin vermemelidir.

## 12. WITH GRANT OPTION, Grant Diyagramları ve REVOKE

### 12.1 WITH GRANT OPTION

`WITH GRANT OPTION` kritiktir, çünkü daha güçlüdür: Bir tablonun belli niteliklerine erişme ya da ekleme yetkisiyle birlikte bu yetkileri başkalarına devretme yetkisini de verir. Yetki böylece bütün veritabanına, bütün kullanıcılara yayılabilir. Bu yüzden yalnız güvenilir kişilere verilmelidir.

### 12.2 Grant diyagramları

Bu yüzden grant diyagramları ortaya çıkar. Hoca bunların mantıksal gösterimler olduğunu, sistemde fiziksel olarak graflarla değil erişim matrisleri ya da erişim denetim listeleri (access control list, ACL) gibi veri yapılarıyla tutulduğunu söyledi; sisteme fazla yük olmaması, verimli gerçeklenmesi gerekir. Birçok rol ve kullanıcı birbirine yetki verdikçe, devretme yetkisi verdikçe ya da yetkiyi kaldırdıkça çok karmaşık bir graf ortaya çıkar.

Gösterimde bir düğüm yetkiyi ve kullanıcıyı tarif eder. Çift yıldız (`**`) kullanıcının nesnenin sahibi olduğunu, tek yıldız (`*`) sahibi olmadığını ama yetkiyi devretme hakkı olduğunu gösterir. Örneğin nesnenin sahibi olan U kullanıcısı bir yetkiyi `with grant option` ile V'ye verirse, U'dan V'ye bir kenar çizilir.

Slayttaki örnek (ekrandan, 01:14:00):

```text
admin kullanıcısı:       GRANT select, insert ON ENROLL to prof, asistan WITH GRANT OPTION
prof rolündeki kullanıcı: GRANT select, insert ON ENROLL to sekreter
asistan rolündeki kullanıcı: GRANT select, insert(EId) ON ENROLL to sekreter

Düğümler ve kenarlar:
Admin: S on E (**)  ->  Prof: S on E (*),  Asist: S on E (*)
Admin: I on E (**)  ->  Prof: I on E (*),  Asist: I on E (*)
Prof: S on E   ->  Sek: S on E
Prof: I on E   ->  Sek: I on E
Asist: S on E  ->  Sek: S on E
Asist: I on E  ->  Sek: I(EId) on E
```

Hoca yeşil düğümlerin tabloları oluşturan admin olduğunu, aslında daha fazla yetkisi olabileceğini ama yalnız `select on ENROLL` ve `insert on ENROLL`'un yazıldığını söyledi. Her yetki için ayrı düğüm çizilir, çünkü bir yetki birine, öteki başka birine devredilebilir; bu yüzden graf karmaşıklaşır.

### 12.3 REVOKE: CASCADE ve RESTRICT

Slaytta `REVOKE <yetki listesi> ON <nesne> FROM <kullanıcılar/roller> CASCADE | RESTRICT` sözdizimi ve anlamları vardır. Hocanın açıklamasına göre `CASCADE`, belirtilen yetkiyi ve yalnız o yetki sayesinde verilmiş yetkileri zincirleme kaldırır; sahiplik düğümünden erişilemez hâle gelen her düğüm silinir. `RESTRICT` ise yalnız ilk adımdaki yetkinin kaldırılmasıdır.

Slayttaki örnek (ekrandan, 01:17:30): Admin `REVOKE select, insert ON ENROLL FROM asistan CASCADE` yapar. Asistanın iki düğümü kalkar. `CASCADE` yüzünden asistanın sekretere verdiği yetkiler de kalkar: `Sek: I(EId) on E` düğümü silinir ve asistandan `Sek: S on E` düğümüne giden kenar kaldırılır. Geriye admin'in iki düğümü, prof'un iki düğümü ve sekreterin prof'tan gelen `S on E` ile `I on E` düğümleri kalır.

Slayttaki bir başka örnekte U kullanıcısı V'ye `R` üzerinde `insert` yetkisi, sonra `R`'nin `A` niteliği üzerinde yetki verir; ikinci adımda `RESTRICT` ile bir yetki geri alınır ve yalnız o yetki kalkar, öteki kalır. Hoca bu çözümlü örneklerin ve bir grant diyagramının oluşturulmasını isteyen alıştırmanın, `CASCADE` ve `RESTRICT`'in anlamı iyice anlaşılarak çözülebileceğini söyledi.

<!-- BELİRSİZ: RESTRICT örneğinde hangi yetkinin kaldırılıp hangisinin kaldığı altyazıdan tam çıkmıyor; slaytın karesi okunmadı. -->

> **Ek bilgi (derste anlatılmadı):** SQL standardında `REVOKE ... RESTRICT`, kaldırılacak yetkiye bağlı başka yetkiler (devredilmiş yetkiler) varsa komutu reddeder; bağımlı yetki yoksa yalnız o yetki kalkar. `CASCADE` ise bağımlı yetkileri de kaldırır.

## 13. Zorunlu Erişim Denetimi

### 13.1 Takdire bağlı yöntemin açığı

Hoca şimdiye kadar görülen yöntemin takdire bağlı olduğunu, zorunlu modelde ise açık noktaların (loophole) kapatılmasının hedeflendiğini söyledi. Slayt kötü niyetli (malicious) bir profesörden söz eder: Profesör de olsa zararlı biri olabilir. Bu profesöre `ENROLL` tablosunda notlara bakma ve değiştirme yetkileri verilmiş olsun. Profesör şu işlemleri yapar (ekrandan, 01:25:00):

```sql
create table TakeAPeek(StudentId int, Title varchar(20),
                       Grade varchar(2));
insert into table TakeAPeek(StudentId, Title, Grade)
  select e.StudentId, c.Title, e.Grade
  from ENROLL e, SECTION k, COURSE c
  where e.SectionId=k.SectId and k.CourseId=c.CId;
```

Profesör bu tabloyu oluşturur ve public yapar. Hoca public'i daha önce anlatmadığını, bir tablo public yapılınca herkesin ona `select` ile erişebildiğini söyledi. Sonra `ENROLL`'da erişebildiği notları bu tabloya kopyalar. Böylece kendi not verdiği öğrencilerin notlarını tamamen dış dünyaya açmış, `ENROLL` üzerinde kurulan bütün yetkilendirmeyi çok basit işlemlerle alt üst etmiş olur. Oysa o notları başka profesörler bile göremiyordu.

Hoca buradan şu sonucu çıkardı: Takdire bağlı yöntemde kişiye güven esası vardır. Slayttaki ilk cümle de bunu söyler: Takdire bağlı erişim denetimi kullanıcıların güvenilir olduğunu varsayar. Kişiye güvenilemezse, tabloyu kopyalayıp public yapmak kolaydır. Profesör `ENROLL`'un yetkilerini değiştiremez, onları değiştirebilen tablonun sahibidir; ama bilgileri başka bir tabloya kopyalayıp o tabloyu public yaparak özel olanı açık hâle getirir.

### 13.2 Güvenlik seviyeleri

Zorunlu erişim denetimi buna engel olur. Hem kullanıcılara hem veriye bir gizlilik (confidentiality) seviyesi atanır; bunlara sınıflandırma seviyesi (classification level) denir. Slayttaki tanıma göre her kullanıcıya (subject, $S$) ve her nesneye ($O$; tablo, kayıt) bir yetki derecesi (clearance) ve güvenlik seviyesi atanır (ekrandan, 01:25:00):

- Top secret (TS)
- Secret (S)
- Classified (C)
- Unclassified (UC)

Hoca unclassified'ın public'e benzediğini, herkesin okuyabileceğini söyledi. Genel olarak farklı protokoller vardır; güvenlik bilgisayar biliminin ayrı bir alt dalıdır, bu yüzden anlatılanın yalnız bir fikir vermek için olduğunu belirtti.

### 13.3 Bell-LaPadula modeli

Slayttaki kurallar (ekrandan, 01:25:00):

- Okuma özelliği: $S$, ancak ve ancak $\text{class}(S) \ge \text{class}(O)$ ise $O$'yu okuyabilir. Kullanıcı bir nesneyi ancak seviyesi en az nesnenin seviyesi kadar yüksekse okuyabilir.
- Yazma özelliği: $S$, ancak ve ancak $\text{class}(S) \le \text{class}(O)$ ise $O$'ya yazabilir. Kullanıcı bir nesneye ancak seviyesi en fazla nesnenin seviyesi kadarsa yazabilir. Bilgi düşük güvenlik seviyesinden yükseğe akmalıdır.

Hoca okuma kuralını şöyle açıkladı: Secret bir kişi secret, classified ya da unclassified veriyi okuyabilir; top secret biri hepsini okuyabilir; classified biri secret veriyi okuyamaz. Yazma kuralını anlatırken önce ters söyledi, sonra düzeltti: Okuma ancak kendi seviyesi ve daha düşük seviyelerde yapılır; yazma ancak kendi seviyesi ve daha yukarılara yapılır. Aksi hâlde üst seviyedeki biri alt seviyedeki bir nesneye yazsa gizli bilgi aşağı doğru akmış olurdu.

### 13.4 TakeAPeek ve zorunlu model

Slayttaki seviyeler: $\text{class}(\text{Prof}) = S$, $\text{class}(\text{TakeAPeek}) = S$; öğrenciler gibi diğer kullanıcılar $C$ seviyesindedir ve okuma özelliği yüzünden `TakeAPeek`'i okuyamazlar (ekrandan, 01:25:00). Hoca `ENROLL`, `SECTION` ve `COURSE` tablolarına da seviyeler verdi (örnek olarak `ENROLL` secret, `SECTION` classified, `COURSE` unclassified).

Secret seviyesindeki profesörün oluşturduğu tablo secret olur. Profesör onu public yapsa bile artık yalnız grant yetkilendirmesi geçerli değildir; üstünde zorunlu erişim denetimi vardır. Veri secret olduğu için classified kullanıcılar onu okuyamaz.

### 13.5 Uygulama kodu açığı

Slayttaki ikinci açık şöyledir: Kötü niyetli bir kullanıcı ("Tricky"; artık profesör kötü niyetli değil) bir `T` tablosu oluşturur, profesöre bu tabloda `insert` yetkisi verir ve profesörün notları girdiği, veritabanı dışındaki uygulamanın kodunu değiştirir. Profesör `ENROLL`'a not girdiğinde notlar otomatik olarak `T`'ye de kopyalanır. Takdire bağlı yetkilendirmeyle bu yapılabilir. Zorunlu modelde ise yapılamaz: Tricky classified, profesör secret seviyesindedir. Profesörün uygulaması secret seviyesinde çalıştığı ve `T` tablosu daha düşük seviyede (classified) olduğu için uygulamadan `T`'ye veri akamaz; uygulama kodu değiştirilse bile model bu kopyalamaya izin vermez. Hoca zorunlu erişim denetiminin bazı açık noktaları böyle kapattığını söyledi.

## 14. Örtülü Kanallar ve OLAP'ta Çıkarım

### 14.1 Örtülü kanal

Son konu örtülü kanallardır (covert channels). Slayttaki tanıma göre bunlar daha yüksek güvenlik seviyesindeki veritabanı nesneleri hakkında bilginin çıkarımıdır (inference); zorunlu modelde, istatistiksel veritabanlarında (OLAP, veri ambarı) ve daha karmaşık senaryolarıyla dağıtık veritabanlarında görülür (ekrandan, 01:33:00). Hocanın ifadesiyle zorunlu model kullanılsa bile bazı çıkarımlarla veri dışarı sızabilir.

Slayttaki örnekte bir tablonun her kaydının ayrı bir güvenlik seviyesi vardır. Slayta göre U seviyesindeki kullanıcılar hiçbir kaydı, S ya da TS seviyesindekiler iki kaydı, C seviyesindekiler bir kaydı görebilir. C seviyesindeki bir kullanıcı S seviyesindeki 101 anahtarlı kaydı göremez. Bu kullanıcı 101 anahtarlı bir kayıt eklemeye çalışır. Ekleme kabul edilirse birincil anahtar ihlali olur; reddedilirse, yani sistem birincil anahtar ihlali hatası verirse, kullanıcı 101'i görmediği hâlde onun var olduğunu çıkarır. Bu bir örtülü kanaldır. Hoca böyle çıkarımlar biriktikçe, daha güçlü olan zorunlu model kullanılsa bile bilgi sızmasının tehlikeli boyutlara varabileceğini söyledi.

### 14.2 İstatistiksel veritabanında çıkarım

Slayttaki son örnek bir istatistiksel (OLAP) veritabanıdır (ekrandan, 01:37:45). Slaytta OLTP ve OLAP karşılaştırması da vardır: OLTP'de çok sayıda işlem, hızlı işleme, normalize veri, çok tablo ve "X'i kim aldı" türü sorgular; OLAP'ta büyük veri, yavaş sorgular, denormalize veri, az tablo ve "X'i kaç kişi aldı" türü sorgular. Örnek tablo:

```text
Sid   SName    Major  Age  GPA
101   Mehmet   10     24   2,36
102   Ahmet    12     35   3,7
```

OLAP yalnız istatistiksel sorgulara izin verir; tek bir kayda erişen "who bought X" türü sorgulara izin vermez. Herkes Ahmet'in en yaşlı öğrenci olduğunu biliyor; bu gerçek hayattan bilinebilecek bir bilgidir. Ama Ahmet'in yaşı bilinmiyor ve GPA'sı public değil; zorunlu ya da takdire bağlı yetkilendirmeyle kapatılmış. Kötü niyetli kullanıcı ("User-Tricky") Ahmet'in yaşını ve GPA'sını öğrenebilir mi?

- Q1, tekrar tekrar: "Yaşı $X$'ten büyük ya da eşit kaç öğrenci var?" Cevap 1 olana kadar $X$ artırılır. Hoca bunu `SELECT COUNT(*) FROM STUDENT WHERE Age >= X` gibi bir sorgu olarak örneklendirdi: $X$ büyüdükçe 100, 50, 8, ... kayıt çıkar; sonunda tek kayıt kalır. O kayıt en yaşlı kişidir, yani Ahmet; bulunan değer $X = 35$'tir.
- Q2: "Yaşı 35'ten büyük ya da eşit öğrencilerin en yüksek GPA'sı nedir?" Bu kümede yalnız Ahmet olduğu için Tricky Ahmet'in GPA'sını (3,7) öğrenir.

Hoca bütün sorguların kümülatif olduğuna dikkat çekti: Hiçbiri doğrudan tek bir kayda erişmiyor, hepsi OLAP tarzı istatistiksel sorgu.

### 14.3 Önlem ve aşılması

Slayttaki önlem (ekrandan, 01:41:45): Her sorgu çalışmak için en az $N$ satırı kapsamalıdır. Hocanın açıklamasıyla kümeleme fonksiyonu en az $N$ satır üzerinde çalışmalıdır; OLAP veritabanlarında böyle bir sınır büyük olasılıkla varsayılan olarak da bulunur. Q2'de yalnız bir kişi kaldığı için bu kısıtla Q2 başarısız olur; Q1 ise çalışır.

Ama slaytın deyişiyle Tricky kararlıdır, vazgeçmez:

- Q1, tekrar tekrar: "Yaşı $X$'ten büyük ya da eşit kaç öğrenci var?" Bu sefer cevap $N$ olana kadar $X$ artırılır; örnekte $X = 28$. Tek kişiye inmeden $N$ kayıtlık bir küme bulunur ve bu kümede Ahmet vardır.
- Q3: "Yaşı 28'den büyük ya da eşit bütün öğrencilerin GPA toplamı nedir?" Sonuç Ahmet'in GPA'sını içerir.
- Q4: "Ahmet dışındaki, yaşı 28'den büyük ya da eşit ve kendisini (Tricky) de içeren öğrencilerin GPA toplamı nedir?" Ahmet çıkarılıp Tricky eklendiği için küme yine en az $N$ kişiliktir.
- Ahmet'in GPA'sı = Q3 − (Q4 − Tricky'nin kendi GPA'sı). Tricky Ahmet'in GPA'sını (3,7) elde eder.

Hoca bunun dikkat gerektiren bir işlem olduğunu söyledi: Yalnız kümülatif sorgular kullanılabiliyor ve kümülatif işlemin yapılacağı kümenin en az $N$ elemanlı olması gibi bir güvenlik kısıtı konmuş; buna rağmen belli bir küme bulunup Ahmet çıkarılarak ve yerine kendisi konarak iki toplam karşılaştırılıyor ve aradaki farktan Ahmet'in GPA'sına ulaşılıyor. Hoca bu tür örneklerin çoğaltılabileceğini, örtülü kanalların ne kadar yetkilendirme kısıtı konsa da akıllıca sorgularla hedefe ulaşmayı sağlayan ilginç bir konu olduğunu ve merak edenlerin varyantlarını araştırabileceğini söyledi.

> **Ek bilgi (derste anlatılmadı):** İstatistiksel veritabanlarında bu tür saldırılara "izleyici" (tracker) saldırısı denir. En az $N$ satır kısıtının yanında, iki sorgunun kümeleri arasındaki örtüşmeyi sınırlamak, sonuçlara gürültü eklemek ya da veriyi örneklemek gibi önlemler büyük olasılıkla kullanılır; günümüzde diferansiyel gizlilik (differential privacy) bu yaklaşımın biçimsel çerçevesidir.

## Örnek Sorular

**1.** (ekrandan, 00:08:05) `create assertion SmallSections check (not exists select e.SectionId from ENROLL e group by e.SectionId having count(e.EId) > 30)` hangi kısıtı ifade eder?

Cevap (slayttan): Hiçbir şubede 30'dan fazla öğrenci olamaz. `ENROLL` şubeye göre gruplanır; kayıt sayısı 30'u aşan bir şube varsa `not exists` yanlış olur ve kısıt ihlal edilir.

**2.** (ekrandan, 00:16:30) `LogGradeChange` tetikleyicisinde olay, koşul ve eylem hangi kısımlardır?

Cevap (derste verildi): Olay `after update of Grade in ENROLL`, koşul `when oldrow.Grade <> newrow.Grade`, eylem `insert into GRADE_LOG(...) values(current_user, current_date, newrow.EId, oldrow.Grade, newrow.Grade)`. `for each row` olduğu için değişen her satır için ayrı çalışır.

**3.** (derste sözlü, 00:21:46-00:26:51) `DEPARTMENT` tablosuna eklenen `Total_sal` niteliğinin `EMPLOYEE` ile tutarlılığını hangi işlemler bozar? Hangi durumda eylem gerekmez?

Cevap (derste verildi): Yeni çalışan ekleme (T1), mevcut çalışanın maaşını değiştirme (T2), çalışan silme (T3) ve çalışanın bölümünü değiştirme (T4). İlgili çalışanların bölüm numarası null ise bölüm toplamı etkilenmez, eylem gerekmez.

**4.** (ekrandan, 00:38:25) Komut düzeyi T2'de tek bir `update` ile bölüm 1'deki bir çalışanın maaşı 200'den 700'e, bölüm 2'deki bir çalışanın maaşı 300'den 900'e çıkıyor. Hangi bölümlerin `Total_sal` değeri ne kadar değişir? Bu satırların bölüm numaraları null olsaydı ne olurdu?

Cevap (derste verildi): Her bölüm için `N`'deki yeni maaşların toplamı eklenir, `O`'daki eski maaşların toplamı çıkarılır. Bölüm numaraları null olsaydı koşul sağlanmaz, hiçbir bölüm güncellenmezdi.

> **Çözüm (derste verilmedi):** Bölüm 1: $700 - 200 = +500$. Bölüm 2: $900 - 300 = +600$. Eylem tek bir `UPDATE` ile iki bölümü birlikte günceller.

**5.** (ekrandan, 00:33:00; derste sözlü, 00:40:12-00:41:14) Komut düzeyi T2'nin koşulunda neden hem `N` hem `O` için `EXISTS` vardır?

Cevap (derste verildi, slayt notuyla): Aynı `update` maaşla birlikte bölüm numarasını da değiştirebilir ve T2 yine tetiklenir. Maaşı değişen satırların bölüm numaraları null'a çekilirse yalnız `N`'ye bakan koşul yanlış olur ve maaş değişiklikleri (eski bölümlerden eski maaşların düşülmesi) kaçırılır.

**6.** (ekrandan, 00:54:15) Aşağıdaki komutları çalıştırmak için gereken en az yetkiler nelerdir? (a) `select s.SId, s.SName, count(e.EId) from STUDENT s, ENROLL e where s.SId = e.StudentId and e.Grade = 'A' group by s.SId, s.SName` (b) `select c.* from COURSE c where c.DeptId in (select d.DId from Dept d where d.DName = 'math')` (c) `delete from SECTION where SectId not in (select e.SectionId from ENROLL e)`

Cevap (slayttan): (a) `select(SId, SName) on STUDENT`, `select(EId, StudentId, Grade) on ENROLL`. (b) `select on COURSE`, `select(DId, DName) on DEPT`. (c) `select(SectId) on SECTION`, `delete on SECTION`, `select(SectionId) on ENROLL`.

**7.** (ekrandan, 00:54:15; derste sözlü, 00:55:16-00:56:25) Profesöre `GRANT update(Grade) ON ENROLL to professor` verilmiştir. Profesör `UPDATE ENROLL e SET e.Grade = 100` ve `UPDATE ENROLL e SET e.Grade = e.Grade + 1` komutlarını çalıştırabilir mi?

Cevap (derste verildi): İlki kör yazmadır (blind write), eski not okunmaz; `update` yetkisi yeter. İkincisi eski notu okuduğu için `update` yetkisi yetmez, `Grade` üzerinde `select` yetkisi de gerekir.

**8.** (derste sözlü, 01:08:05-01:11:30) Neden ayrı bir "grant assertion" yetkisi yoktur da assertion ve yabancı anahtar tanımlamak `REFERENCES` yetkisi gerektirir?

Cevap (derste verildi): Assertion ve yabancı anahtar, başka bir kullanıcının tablosu üzerinde kısıt koyar. Kötü niyetli bir assertion tabloya neredeyse hiçbir değerin girilmesine izin vermeyerek onu kullanılamaz hâle getirebilir. `on delete no action` ile tanımlanan bir yabancı anahtar da işaret edilen tablonun sahibinin silme yapmasını engeller. Bu yüzden `select` yetmez, güçlü bir yetki olan `REFERENCES` gerekir.

**9.** (ekrandan, 01:14:00 ve 01:17:30) Admin `GRANT select, insert ON ENROLL to prof, asistan WITH GRANT OPTION` verir; prof `GRANT select, insert ON ENROLL to sekreter`, asistan `GRANT select, insert(EId) ON ENROLL to sekreter` verir. Sonra admin `REVOKE select, insert ON ENROLL FROM asistan CASCADE` yapar. Sekreterde hangi yetkiler kalır?

Cevap (derste verildi, slayttan): Asistanın iki düğümü ve asistanın sekretere verdiği `insert(EId)` yetkisi kalkar. Sekreterde prof'tan gelen `select on ENROLL` ve `insert on ENROLL` kalır; `select` yetkisi asistandan da gelmişti, ama prof'tan geldiği için düğüm silinmez.

**10.** (ekrandan, 01:25:00; derste sözlü, 01:20:10-01:31:52) Kötü niyetli bir profesör `TakeAPeek` tablosunu oluşturup `ENROLL`'daki notları içine kopyalar ve tabloyu public yapar. Takdire bağlı ve zorunlu erişim denetiminde sonuç ne olur?

Cevap (derste verildi): Takdire bağlı yöntemde herkes notları okuyabilir; yöntem kullanıcıya güvenmeye dayandığı için bütün yetkilendirme boşa çıkar. Zorunlu modelde $\text{class}(\text{Prof}) = S$ olduğu için `TakeAPeek` de $S$ olur; $C$ seviyesindeki kullanıcılar okuma özelliği ($\text{class}(S) \ge \text{class}(O)$) yüzünden okuyamaz. Uygulama kodu değiştirilip notlar $C$ seviyesindeki bir tabloya kopyalanmak istense bile yazma özelliği ($\text{class}(S) \le \text{class}(O)$) buna izin vermez.

**11.** (ekrandan, 01:33:00; derste sözlü, 01:32:38-01:33:40) C seviyesindeki bir kullanıcı S seviyesindeki 101 anahtarlı kaydı göremez. Bu kullanıcı kaydın varlığını nasıl öğrenebilir?

Cevap (derste verildi): 101 anahtarlı bir kayıt eklemeye çalışır. Sistem birincil anahtar ihlaliyle reddederse 101'in var olduğunu çıkarır. Bu bir örtülü kanaldır.

**12.** (ekrandan, 01:37:45 ve 01:41:45) Yalnız istatistiksel sorgulara izin veren bir OLAP veritabanında herkes Ahmet'in en yaşlı öğrenci olduğunu biliyor. (a) Ahmet'in GPA'sı nasıl öğrenilir? (b) "Her sorgu en az $N$ satırı kapsamalı" kısıtı konunca saldırı nasıl sürdürülür?

Cevap (derste verildi): (a) Q1 "yaşı $\ge X$ olan kaç öğrenci var?" sorusu cevap 1 olana kadar $X$ artırılarak sorulur, $X = 35$ bulunur; Q2 "yaşı $\ge 35$ olanların en yüksek GPA'sı" ile 3,7 öğrenilir. (b) Q1 cevap $N$ olana kadar sorulur ($X = 28$). Q3: Yaşı $\ge 28$ olanların GPA toplamı (Ahmet dahil). Q4: Ahmet hariç, kendisi dahil, yaşı $\ge 28$ olanların GPA toplamı. Ahmet'in GPA'sı = Q3 − (Q4 − kendi GPA'sı) = 3,7.

> **Çözüm (derste verilmedi):** Kümenin geri kalanının GPA toplamı $R$, Ahmet'inki $A$, Tricky'ninki $T$ olsun. Tricky'nin yaşı 28'in altındaysa Q3 $= A + R$, Q4 $= R + T$ olur; Q3 − (Q4 − $T$) $= A$ (ara adım eklendi). Formül, Tricky'nin Q3 kümesinde olmamasını varsayar.

## Dersin Toparlaması

Bu derste önce aktif veritabanları başlığı altında tetikleyiciler daha kapsamlı ele alındı. Assertion'ın her işlemde denetlenen yükü karşısında tetikleyicinin olay, koşul, eylem yapısı, `before`/`after`/`instead of` türleri ve satır ile komut düzeyi ayrımı anlatıldı. Türetilmiş bir nitelik olan `Total_sal`'ı tutarlı tutmak için gereken dört olay belirlendi; T1 ve T2'nin satır düzeyi biçimleri ile T2'nin `OLD TABLE`/`NEW TABLE` ve kümülatif toplamlar kullanan, toplu güncellemelerde çok daha verimli komut düzeyi biçimi örnek veriyle işlendi.

İkinci kısımda güvenlik ele alındı: Kimlik doğrulama ile yetkilendirme ayrımı, rol esaslı ve nitelik düzeyinde yetkiler, SQL komutlarının gerektirdiği en az yetkiler ve kör yazma, view ile satır düzeyinde ince ayar, `REFERENCES` yetkisinin gerekçesi, `WITH GRANT OPTION`, grant diyagramları ve `REVOKE CASCADE`/`RESTRICT`. Takdire bağlı yöntemin kullanıcıya güvene dayanan açığı `TakeAPeek` örneğiyle gösterildi; Bell-LaPadula kurallarına dayanan zorunlu erişim denetiminin bu açığı nasıl kapattığı anlatıldı. Son olarak zorunlu model altında bile birincil anahtar ihlali ve OLAP'ta istatistiksel sorgularla bilgi sızdıran örtülü kanallar işlendi. Hoca bununla dönemin konularının tamamlandığını belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
