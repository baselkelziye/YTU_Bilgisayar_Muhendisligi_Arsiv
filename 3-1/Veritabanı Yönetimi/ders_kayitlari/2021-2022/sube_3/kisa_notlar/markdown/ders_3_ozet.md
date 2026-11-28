# Ders 3 Çalışma Özeti

## Genel Konular

- Join türlerinin tekrarı
  - NATURAL JOIN, iki tabloda aynı adı (ve uyumlu tipi) taşıyan kolonlar üzerinden kendiliğinden eşleştirme yapar; INNER JOIN'de eşleştirme koşulu `ON` ile açıkça yazılır.
  - Gösterim farkı: `SELECT *` ile INNER JOIN yapıldığında eşleşen kolon iki kez görünür, NATURAL JOIN'de ortak kolon bir kez gösterilir.
  - NATURAL JOIN'in riski yanlış eşleştirmedir: örneğin hem öğretmen hem öğrenci tablosunda `ID` adlı sayısal bir kolon varsa, anlamca ilgisiz bu iki kolon üzerinden birleştirme yapılır. Bu yüzden INNER JOIN ya da `USING` ile kolonu açıkça belirtmek önerilir.
  - INNER JOIN yalnız iki tarafta da karşılığı olan satırları getirir. Ders açmamış bölümleri de görmek gibi ihtiyaçlarda OUTER JOIN kullanılır; karşılığı olmayan taraf boş (NULL) gelir.
  - LEFT JOIN soldaki tablonun bütün satırlarını, RIGHT JOIN sağdakinin bütün satırlarını getirir; FULL OUTER JOIN'de satırın herhangi bir tarafta bulunması yeterlidir.
- View (görünüm)
  - View, fiziksel veri tutmayan sanal bir ilişkidir (virtual relation); çalıştırıldığında arkasındaki SELECT sorgusu yeniden yürütülür.
  - Birinci kullanım amacı güvenlik ve gizlemedir: maaş, kimlik numarası gibi kolonları gizleyip her uygulamaya ya da gruba yalnız gerektiği kadar veri gösterilir. Bir tabloya birden çok view, bir view'a birden çok tablo (join ile) bağlanabilir.
  - İkinci amaç karmaşık sorguları sadeleştirmektir: çok sayıda join ve koşul içeren sorgu bir kez view olarak tanımlanır, sonra `SELECT * FROM employeeview WHERE name = 'Ahmet'` gibi kısa sorgularla kullanılır (ekrandan, 00:25:00). Bu, hata riskini ve zaman kaybını azaltır, farklı kişilerin farklı tanımlar kullanmasını önleyip raporları tutarlı kılar.
  - Sanal view üzerinden güncelleme yapılmaz; değişiklik asıl tablolarda yapılır. Asıl tablolar değişirse aynı view'un sonucu da bir sonraki çalıştırmada değişir.
  - Sık kullanılan sorgular veritabanı tarafından önbelleğe alınabilir; bunun dışında view ile arkadaki sorgu arasında performans farkı yoktur.
  - View'lar başka view'lar üzerine kurulabilir (`physics_fall_2017` ve onun üzerine `physics_fall_2017_watson`, ekrandan, 00:30:00). Kendine başvuran (recursive) view önerilmez.
  - View expansion: view adının yerine tanımındaki SELECT sorgusu konarak sorgu açılır; ikisi anlamca aynıdır (ekrandan, 00:35:00).
  - Bir view'da tablodaki gibi aynı kolon adı iki kez bulunamaz; çakışan kolonlar `AS` ile yeniden adlandırılır (`ManagerID`, `ManagerName` gibi).
- Materialized view
  - Sorgu sonucu fiziksel olarak kopyalanıp saklanır; sorgular asıl tablolara değil bu kopyaya gider. Amaç performanstır: saklama alanından taviz verilip hız kazanılır.
  - Asıl tablo değişince kopya hemen değişmez; periyodik yenileme (refresh) gerekir. Yenileme baştan silip yeniden oluşturma (complete, Oracle'da out-of-place seçeneği) ya da yalnız yeni eklenenleri ekleme (fast/incremental) biçiminde olabilir.
  - Söz dizimi: `CREATE MATERIALIZED VIEW ... AS SELECT ...` ve yenileme periyodu. Söz dizimi veritabanına göre değişir; Oracle ve PostgreSQL destekler.
  - Materialized view üzerinde INSERT/UPDATE/DELETE yapılabilir ama asıl tablolara yansımaz ve bir sonraki yenilemede kaybolur; asıl tablodaki sorun çözülmüş olmaz.
  - Birden çok tablonun join sonucu olduğu için denormalize ve geniş bir yapıdır, veri tekrarı içerebilir, primary key / foreign key kısıtları yoktur.
- View üzerinden güncellemenin sorunları
  - `instructor_info` (ID, name, building) view'una `('69987', 'White', 'Taylor')` eklenirse hangi bölüme ait olduğu belirsizdir: Taylor binasında birden çok bölüm varsa hangisi, hiç yoksa ne olacak? (ekrandan, 01:05:00)
  - Belirli bir bölüm için tanımlanmış bir view'a başka bölümden kayıt eklenmesini engelleyen bir kısıt yoktur.
- Transaction
  - Birden çok parçadan oluşan ve tek bir iş birimi olarak ya tamamen ya da hiç gerçekleşmesi gereken işlemler dizisidir.
  - Para transferi örneği: bir hesaptan 100 TL düşen UPDATE ile diğer hesaba 100 TL ekleyen UPDATE birlikte gerçekleşmelidir; arada hata olursa para "havada" kaybolur (ekrandan, 01:20:00).
  - Hepsi başarılıysa COMMIT ile kalıcı olur, aksi halde ROLLBACK ile bütün işlemler geri alınıp önceki duruma dönülür. Log tablosuna yazma gibi ek adımlar da aynı transaction'a girebilir.
- Bütünlük kısıtları (integrity constraints)
  - Verinin yanlışlıkla bozulmasını önleyen kurallardır: yaşın 0-150 arasında olması, bakiyenin negatife düşmemesi, müşteri adının boş olmaması gibi.
  - NOT NULL, PRIMARY KEY, UNIQUE ve CHECK en yaygın kısıtlardır. NOT NULL yazılmayan kolon NULL alabilir.
  - Primary key unique olmak zorundadır; unique bir kolonun primary key olması gerekmez. Aday anahtarlar unique olan ve daha da küçültülemeyen anahtarlardır; primary key bunların arasından seçilir.
  - UNIQUE tek kolon ya da birden çok kolonun birleşimi (composite) üzerine konabilir.
  - CHECK karmaşık koşullar için kullanılır: `semester in ('Fall', 'Winter', 'Spring', 'Summer')` gibi; IN listesi başka bir tablodan SELECT ile de gelebilir.
- Referential integrity (başvuru bütünlüğü)
  - Bir ilişkide geçen değerin başvurulan ilişkide de bulunmasını garanti eder: instructor tablosunda "Biology" bölümü varsa department tablosunda da "Biology" olmalıdır.
  - Foreign key tanımı bu kısıtı sağlar. Başvurulan değeri silmeye kalkınca hata alınır; önce başvuran satırlar silinmeli.
  - Foreign key, başvurulan tabloda genelde primary key'e, en azından unique bir anahtara başvurur.
  - `ON DELETE CASCADE` / `ON UPDATE CASCADE` asıl tablodaki silme/güncellemeyi başvuran tabloya yayar; alternatifleri `SET NULL` ve `SET DEFAULT`'tur.
  - Kendine başvuran foreign key: `person` tablosunda `mother` ve `father` yine `person`'a başvurur. Ekleme için önce anne-baba eklenir ya da bu kolonlar önce NULL bırakılıp sonra güncellenir ya da kısıt denetimi ertelenir (ekrandan, 01:50:00).
- Assertion ve trigger
  - Assertion, veritabanının her zaman sağlaması istenen bir koşulu ifade eder: `create assertion <ad> check (<koşul>)`.
  - Modern veritabanlarında pek uygulanmaz (yavaş ve engelleyici olabilir); yerine trigger kullanılır. Trigger, INSERT, UPDATE ya da DELETE olduğunda arka planda kendiliğinden çalışan koddur.
- SQL veri tipleri
  - date (yıl, ay, gün), time (saat, dakika, saniye), timestamp (tarih ve saat, saniyenin kesirleriyle), interval (iki zaman arasındaki süre).
  - Log tablolarında aynı saniyede birden çok işlem olabileceği için timestamp, gün düzeyinde yeterliyse daha az yer kaplayan date tercih edilir. Saklama biçimi tektir; gösterim biçimi sorguda dönüştürülebilir.
  - Büyük nesneler: metin için CLOB (character large object), resim, video, ses gibi ikili veriler için BLOB (binary large object). Bunların içeriği üzerinde sorgu yapılamaz.
  - Kullanıcı tanımlı tip: `create type Dollars as numeric(12,2) final` (ekrandan, 02:20:00). `final` bu tipten alt tip türetilemeyeceğini belirtir.
  - Domain, kullanıcı tanımlı tipe benzer ama kısıt (NOT NULL, CHECK) da içerebilir.
- İndeks tanımı
  - İndeks, sorguları hızlandırmak için oluşturulur: `create index <ad> on <tablo>(<kolonlar>)`. Birden çok kolon üzerine de kurulabilir. Primary key üzerinde genelde kendiliğinden bir indeks oluşur.
- Yetkilendirme (authorization)
  - Yetki (privilege) türleri: read (yalnız okuma), insert (ekleme, değiştirme yok), update (değiştirme, silme yok), delete (silme). Kullanıcıya hepsi, hiçbiri ya da bir bileşimi verilebilir.
  - `grant <yetki listesi> on <ilişki ya da view> to <kullanıcı listesi>`; kullanıcı listesi kullanıcı, `public` ya da rol olabilir. `revoke ... on ... from ...` yetkiyi geri alır.
  - View'a verilen yetki alttaki tablolara yetki vermez; ama view'u oluşturan kişinin alttaki tablolara yetkisi olmalıdır.
  - Roller: `create role instructor; grant instructor to Amit; grant select on takes to instructor;` Roller başka rollere de verilebilir ve zincir oluşturur (ekrandan, 02:35:00).
  - `with grant option` alan kullanıcının yetkiyi başkasına da verebilmesini sağlar. `revoke ... cascade` bu kullanıcının dağıttığı yetkileri de siler, `restrict` yalnız kendisininkini.

## Hocanın Özellikle Vurguladığı Kısımlar

- NATURAL JOIN'in yanlış eşleştirme riski
  - Yalnız kolon adına baktığı için anlamca farklı kolonları birleştirebilir; kolonları açıkça belirtmek gerekir.
- View'un iki temel faydası
  - Gizlilik/yetki: çok kullanıcılı kurumlarda hakları view üzerinden tanımlamak daha kolaydır; asıl tabloya erişim yalnız üst yetkililerde olmalıdır.
  - Sadeleştirme: karmaşık join'leri bir kez yazıp herkesin aynı tanımı kullanması.
- Materialized view'da taviz
  - Saklama alanından taviz verilir, hız kazanılır; gerçek dünyada hız genellikle daha önemlidir. Veri yenilemeye kadar güncel değildir.
- Materialized view üzerinde değişiklik yapmak anlamlı değildir
  - Yapılan değişiklik bir sonraki yenilemede kaybolur, asıl tablodaki sorun sürer.
- CASCADE'i dikkatli kullanmak
  - İstemeden çok sayıda satır silinebilir; önce NULL yapma, varsayılan değer verme ya da bilinçli silme tercih edilebilir.
- Yetkileri kişiye değil role vermek
  - Kişiye yetki yalnız uygulama kullanıcısı gibi özel durumlarda mantıklıdır; `public`'e yetki vermek tercih edilmez.

## Kısa Tekrar Notları

- NATURAL JOIN: aynı adlı kolonlarda otomatik eşleşme, ortak kolon bir kez görünür. INNER JOIN: `ON` ile açık koşul.
- LEFT JOIN: solun tamamı; RIGHT JOIN: sağın tamamı; FULL OUTER JOIN: iki tarafın tamamı, eksik taraf NULL.
- View = sanal ilişki, veri tutmaz, her çağrıda sorgu yeniden çalışır.
- View'da kolon adları tekil olmalı; çakışanlar `AS` ile yeniden adlandırılır.
- View expansion: view adı yerine tanım sorgusu konur.
- Materialized view = sonucu fiziksel kopya; refresh complete ya da fast (incremental).
- Transaction: ya hep ya hiç; COMMIT ya da ROLLBACK.
- Kısıtlar: NOT NULL, PRIMARY KEY, UNIQUE, CHECK, FOREIGN KEY.
- Referential integrity: başvurulan değer var olmalı; CASCADE, SET NULL, SET DEFAULT.
- Assertion yerine pratikte trigger kullanılır.
- date / time / timestamp / interval; CLOB metin, BLOB ikili veri.
- `create type`, `create domain` (domain kısıt içerebilir).
- `create index`, `grant`, `revoke`, `create role`, `with grant option`, `cascade` / `restrict`.

## Detaylı Açıklamalar

- **Join seçimi.** A tablosunda 1-5, B tablosunda 1-4 ve 6 numaralı satırlar olduğunu düşünelim. A'nın bütün satırları isteniyor, B'de karşılığı olmayabilirse LEFT JOIN kullanılır; 5 numaralı satır B kolonları NULL olarak gelir. Bütün B satırları isteniyorsa RIGHT JOIN, iki taraftan herhangi birinde bulunması yeterliyse FULL OUTER JOIN kullanılır. INNER JOIN yalnız iki tarafta ortak olan satırları getirdiği için, ders açmamış bölümler gibi karşılığı olmayan kayıtlar sonuçta görünmez.
- **View ile sorgu sadeleştirme.** Derste employee tablosunun address, department ve tekrar employee (yönetici bilgisi için) tablolarıyla birleştirildiği uzun bir sorgu örneği yazıldı (ekrandan, 00:25:00):

  ```sql
  create view employeeview as
  select ID, name, email
  from employee e
      inner join address a on a.EmpID = e.ID
      inner join department a on a.EmpID = e.ID
      left join employee e2 on ...
  where e.departmentID = 3
  ```

  Ardından `select * from employeeview where name = 'Ahmet'` sorgusu, view'un yerine tanımındaki sorgunun alt sorgu olarak yazılmasıyla aynıdır. Ekrandaki taslakta iki tablo için aynı `a` takma adı kullanılmıştır; gerçek bir sorguda her tabloya ayrı takma ad verilmelidir.
- **View tanımında kolon çakışması.** Bir tabloda aynı adlı iki kolon olamadığı gibi bir view'da da olamaz. employee ile yöneticisini (e2) birleştiren view'da `e.ID` ve `e2.ID`, `e.name` ve `e2.name` aynı adla döneceği için view oluşturulamaz; `e2.ID as ManagerID`, `e2.name as ManagerName` gibi yeniden adlandırma gerekir.
- **Materialized view yenilemesi.** Örneğin her gün sabah 8'de view silinip yeniden oluşturulursa, oluşturma bitince kullanıma açılır ve ertesi günkü yenilemeye kadar asıl tablodaki değişiklikler görünmez. Saatlik yenileme de seçilebilir. Oracle'da yenileme yöntemi (complete/fast) ve out-of-place gibi seçenekler parametrelerle verilir. Materialized view olmayan sistemlerde (derste SQL Server için söylendi) geçici tablolar ya da sonuçları kalıcı tabloya yazmak benzer amaçla kullanılır.
- **Transaction örneği.** Hesapta 500 TL var, 100 TL bakiyesi 0 olan başka bir hesaba gönderilecek:

  ```sql
  update account set balance = balance - 100 where ID = 15;
  update account set balance = balance + 100 where ID = 20;
  ```

  İki UPDATE tek transaction içinde yürütülür; ikisi de başarılıysa COMMIT, herhangi biri başarısızsa ROLLBACK yapılır. Gönderen hesabın bakiyesi yetersizse işlemin yapılmaması da bir kısıtla sağlanabilir.
- **Kendine başvuran foreign key.** Ekrandaki tablo (ekrandan, 01:50:00):

  ```sql
  create table person (
      ID char(10),
      name char(40),
      mother char(10),
      father char(10),
      primary key ID,
      foreign key father references person,
      foreign key mother references person)
  ```

  Anne ve babası henüz tabloda olmayan bir kişi eklenirse foreign key ihlali olur. Çözümler: önce anne ve babayı eklemek, ya da (kolonlar NOT NULL olmadığı için) önce NULL ile ekleyip sonra güncellemek, ya da kısıt denetimini ertelemek.
- **Yetki zinciri.** `grant select on department to Amit with grant option` ile Amit bu yetkiyi başkalarına da verebilir. Yetki geri alınırken `cascade` Amit'in verdiği yetkileri de siler, `restrict` yalnız Amit'in yetkisini alır.

> **Ders sonrası not:** `foreign key father references person` biçiminde kolon belirtilmezse başvuru `person` tablosunun primary key'ine (`ID`) yapılır; yani `mother` ve `father` kolonları büyük olasılıkla kişinin adını değil `ID` değerini tutmalıdır. Derste bu kolonlar ad üzerinden anlatıldı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
