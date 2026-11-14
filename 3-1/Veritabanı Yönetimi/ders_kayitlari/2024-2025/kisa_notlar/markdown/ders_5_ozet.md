# Ders 5 Çalışma Özeti

<!-- BELİRSİZ: Kaydın 00:41-01:37 ve 01:52-02:22 aralıklarında ses büyük ölçüde anlaşılmıyor (altyazı anlamsız ve tekrar eden satırlardan oluşuyor). Bu aralıkların içeriği yalnız ekrandaki slaytlardan alınmıştır; hocanın bu kısımlardaki açıklamaları nota girmemiştir. 01:05-01:37 arasında paylaşılan ekran da aynı slaytta (6.32) donmuş görünüyor. -->

## Genel Konular

- Veritabanı tasarım süreci
  - Kavramsal tasarım, "küçük dünyanın" kâğıda aktarılmasıdır. Önce veritabanı kullanıcılarının bakış açısından veri ihtiyaçları (data needs) belirlenir: hangi veri saklanacak?
  - Sonra fonksiyonel gereksinimler belirlenir: bu veriyle hangi işlemler yapılacak? (öğrenci derse kaydolur, dersten geçer, kalır vb.)
  - Gereksinimler bir paragraf hâlinde yazıldığında özneler çoğu zaman varlıkları, yüklemler bağıntıları ya da işlemleri verir.
  - Mantıksal tasarım (logical design): Kavramsal şema ilişkisel model şemasına dönüştürülür; tablolar, nitelikler, domenler ve anahtarlar ortaya çıkar.
  - Fiziksel tasarım (physical design): Tabloların diskteki dosya karşılıkları, indeks dosyaları ve veri yapıları (B+ ağacı, hash, LSM ağacı; büyük veri sistemlerinde sütun yönelimli Parquet, Avro gibi formatlar).
- Mantıksal tasarım neden daha kritik?
  - Fiziksel bağımsızlık sayesinde fiziksel tasarım sonradan değiştirilebilir (B+ ağacından hash'e geçmek uygulamaları değiştirmez, yalnız performansı etkiler).
  - Mantıksal tasarım ise katıdır: Kullanılan bir veritabanında tablo şemasını değiştirmek zordur. NoSQL sistemlerin çıkış noktalarından biri bu katılığa karşı esnek şema ihtiyacıdır.
  - Gerçek bir veritabanı tasarımı tek kişilik iş değildir; küçük dünyadaki rollerle iletişim ve geri besleme gerektirir.
- Tasarımda kaçınılması gereken iki tuzak
  - Fazlalık (redundancy): Aynı bilginin birden çok yerde tekrar etmesi; tutarsızlığa yol açar.
  - Eksiklik (incompleteness): Küçük dünyanın bazı gereksinimlerinin modele aktarılamaması.
  - İyi tasarım tek değildir; birçok iyi tasarım olabilir. Tasarım hem bilim hem sanattır.
- ER modelinin temel kavramları
  - Varlık (entity): Tek bir birey ya da nesne; tablodaki bir satıra karşılık gelir.
  - Varlık seti (entity set): Aynı niteliklere sahip varlıkların kümesi; ER diyagramında başlıklı dikdörtgen. Altı çizili nitelikler birincil anahtardır.
  - Bağıntı seti (relationship set): Varlıklar arasındaki bağıntıların kümesi; elmas (diamond) ile gösterilir. Örnek: `instructor` ile `student` arasındaki `advisor`.
  - Bağıntı setinin kendi nitelikleri olabilir: `advisor` bağıntısında danışmanlığın başladığı `date`, elmasa kesikli çizgiyle bağlı dikdörtgenle gösterilir (ekrandan, 00:40:00).
  - Roller: Aynı varlık seti bir bağıntıya birden çok kez katılıyorsa (özyinelemeli bağıntı, recursive relationship) roller belirtilmelidir. Örnek: `course` ile yine `course` arasındaki `prereq` bağıntısında `course_id` ve `prereq_id` rolleri.
- Bağıntı setinin derecesi (ekrandan, 00:45:30 ve 00:50:00)
  - İkili (binary) bağıntı iki varlık setini içerir; veritabanlarındaki bağıntıların çoğu ikilidir.
  - Üçlü (ternary) bağıntı örneği: Öğrenciler bir hocanın rehberliğinde araştırma projelerinde çalışır; `proj_guide` bağıntısı `instructor`, `student` ve `project` arasındadır.
- Eşleme kardinalitesi kısıtları (mapping cardinality) (ekrandan, 00:55:30 ve 01:00:00)
  - Bir varlığın bir bağıntı seti üzerinden kaç varlıkla ilişkilendirilebileceğini belirtir: bire bir, bire çok, çoka bir, çoka çok.
  - ER diyagramında yönlü çizgi (ok) "bir", yönsüz çizgi "çok" anlamına gelir.
  - Minimum ve maksimum kardinalite `l..h` biçiminde yazılabilir: Minimum 1 tam katılım (total participation) demektir, maksimum 1 en fazla bir bağıntı, `*` sınırsız demektir (ekrandan, 01:05:30).
  - Örnek: `instructor` tarafında `0..*`, `student` tarafında `1..1`: Bir hoca 0 ya da daha çok öğrenciye danışmanlık eder; her öğrencinin tam olarak bir danışmanı vardır. Bu bire çok bağıntıdır ve öğrenci tarafı tam katılımlıdır; aynı şey öğrenci tarafında çift çizgi, hoca tarafında okla da gösterilir.
- Zayıf varlık setleri (weak entity sets) (ekrandan, 01:40:00)
  - `section` varlığı `course_id`, `sec_id`, `semester` ve `year` ile tanımlanır. `section` ile `course` arasında `sec_course` bağıntısı kurulunca `section` içindeki `course_id` fazlalık olur.
  - `course_id` çıkarılınca `section`'ın kalan nitelikleri onu tek başına tanımlayamaz; böyle varlık setine zayıf varlık seti denir.
  - Zayıf varlık, varlığını belirleyen güçlü bir varlığa (identifying entity) belirleyici bağıntı (identifying relationship) ile bağlanır. İkisi de çift çizgiyle çizilir.
  - Güçlü varlık içinde zayıf varlıkları ayırt eden nitelik grubuna ayırt edici (discriminator) denir: `section` için `sec_id`, `semester`, `year` üçü birden.
  - Zayıf varlık tarafında katılım tam olmalı ve tek bir güçlü varlığa bağlanmalıdır (ok).
- Fazlalık içeren nitelikler
  - `student` ile `department` arasında `stud_dept` bağıntısı varsa `student` içindeki `dept_name` fazlalıktır, çıkarılır. Aynısı `instructor` ve `inst_dept` için geçerlidir.
- Üniversite veritabanının ER diyagramı (ekrandan, 01:46:40)
  - Slayttaki tasarım sezgisi: (1) Varlık setlerini nitelikleriyle belirle, (2) fazlalıkları tespit et.
  - `time_slot` varlığında `day`, `start_time`, `end_time` çok değerli (multivalued) bir niteliktir; bir dersin farklı oturumları olabilir.
  - Her çizginin küçük dünyada bir anlamı vardır: Örneğin `course_dept`'te ders tarafında çift çizgi (her ders mutlaka bir bölümce açılır), bölüm tarafında kısmi katılım (bir bölüm o dönem hiç ders açmamış olabilir).
- ER diyagramının ilişkisel şemalara dönüştürülmesi (ekrandan, 02:05:30, 02:10:00, 02:13:00, 02:20:00)
  - Bileşik nitelikler (composite attributes) düzleştirilir: `name` (`first_name`, `middle_initial`, `last_name`) ve `address` bileşenleri ayrı niteliklere dönüşür.
  - Çok değerli nitelik `M`, ayrı bir `EM` şemasıyla gösterilir: `inst_phone = (ID, phone_number)`. Birincil anahtarı 22222 olan ve iki telefonu olan bir hoca, `(22222, 456-7890)` ve `(22222, 123-4567)` olmak üzere iki satıra dönüşür.
  - Çoka çok bağıntı seti, iki tarafın birincil anahtarlarını ve bağıntının kendi niteliklerini içeren ayrı bir şemayla gösterilir.
  - "Çok" tarafında tam katılımlı çoka bir ve bire çok bağıntılar ayrı şema yerine "çok" tarafına "bir" tarafın birincil anahtarını yabancı anahtar olarak ekleyerek gösterilebilir: `inst_dept` için `instructor` şemasına `dept_name` eklenir.
  - "Çok" tarafında katılım kısmiyse bu yöntem boş (null) değerlere yol açabilir; ya aynı yöntem kullanılır ya da bağıntı için ayrı şema kurulur.
  - Bire bir bağıntılarda iki taraftan herhangi biri "çok" tarafı gibi seçilebilir.
  - Zayıf varlık setini güçlü varlığına bağlayan bağıntının şeması fazlalıktır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Tasarımda "iki kere iki dört" gibi kesin kurallar yok
  - Kurallar kuru ezberlenmemeli, tasarım bir meleke hâline gelmeli. Tasarım bir ağacın çekirdeği gibidir: Bütün ağaç ve meyveleri ona bağlıdır.
- İlişkisel modelin yeri
  - NoSQL ne kadar yaygın olsa da SQL sistemleri endüstrinin büyük kısmına hâkimdir; köklü (legacy) sistemlerden geçiş kolay değildir. Banka, muhasebe ve üniversite gibi ihtiyaçları net alanlar ilişkisel modele uygundur; sosyal medya ve e-ticaret gibi alanlar esnek şema ister.
- Zayıf varlık korkutmasın
  - Zayıf varlık bilakis iyi bir şeydir: Fazlalıktan kurtulmak için ortaya çıkar ve fiziksel tasarımda iki birincil anahtar yerine bir birincil anahtar ve ayırt ediciler takip edilir.
- ER diyagramını iki yönlü çalışın
  - Diyagrama bakıp gereksinim listesini çıkarmak (tersine mühendislik) daha kolaydır; gereksinim listesinden diyagram çizmek daha zordur. İkisinin de alıştırması yapılmalı, yalnız üniversite örneğinde kalınmamalıdır.
- Bire bir bağıntıda iki tarafın da tam katılımlı olması
  - Bu, iki varlık setinde aynı sayıda eleman olduğu ve her birinin karşı taraftaki tam bir elemanla eşleştiği anlamına gelir. Böyle bir kısıt küçük dünyanın gereğine bağlıdır.

## Kısa Tekrar Notları

- Tasarım aşamaları: veri ihtiyaçları, fonksiyonel gereksinimler, mantıksal tasarım, fiziksel tasarım.
- Mantıksal tasarım katı ve kritiktir; fiziksel tasarım fiziksel bağımsızlık sayesinde değiştirilebilir.
- İki tuzak: fazlalık ve eksiklik.
- Varlık seti dikdörtgen, bağıntı seti elmas, birincil anahtar altı çizili, bağıntı niteliği kesikli çizgiyle bağlı.
- Özyinelemeli bağıntıda roller gerekir (`prereq`: `course_id`, `prereq_id`).
- Çoğu bağıntı ikilidir; üçlü örnek `proj_guide`.
- Kardinalite: ok "bir", düz çizgi "çok"; çift çizgi tam katılım; `l..h` gösterimi.
- Zayıf varlık: çift çizgili dikdörtgen, çift çizgili belirleyici bağıntı, ayırt edici kesikli altı çizili; `section` için ayırt edici `sec_id`, `semester`, `year`.
- Bağıntıdan çıkarılabilen nitelik (`student.dept_name`) fazlalıktır.
- Dönüşüm: bileşik nitelik düzleşir, çok değerli nitelik ayrı şema, çoka çok bağıntı ayrı şema, "çok" tarafında tam katılımlı bire çok bağıntı yabancı anahtarla.

## Detaylı Açıklamalar

- **Gereksinimlerden varlıklara.** Hoca üniversite örneğini cümlelerle kurdu: Öğrenciler ders alır; dersler her dönem ya da bazı dönemler açılır, açıldığı dönemde birden çok şube (section) açılabilir; öğrenciler dersi bir hocadan alır, not alır, bir bölüme bağlıdır. Bu veritabanı tek bir üniversite içindir; bu yüzden "üniversite" diye bir varlık seti aranmaz. Bu cümlelerdeki özneler (öğrenci, ders, şube, bölüm) varlık setlerini, yüklemler (alır, açılır, bağlıdır) bağıntıları ya da işlemleri verir.
- **Bağıntı ve nitelikleri** (ekrandan, 00:40:00). `advisor` bağıntı setinin her elemanı bir hoca ile bir öğrenci çiftidir. Bağıntının kendi niteliği olan `date`, o hocanın o öğrenciye danışmanlık etmeye başladığı tarihtir. Aynı hoca iki öğrenciye farklı tarihlerde danışmanlık etmeye başlamış olabilir.
- **Özyinelemeli bağıntı.** Bir dersin ön koşulları da derstir. `course` ile `course` arasında `prereq` bağıntısı kurulur; aynı varlık seti iki kez katıldığı için hangi tarafın ders, hangisinin ön koşul ders olduğunu roller belirtir. Hoca, ön koşulu `course` içinde bir nitelik gibi tutmanın neden uygun olmadığını da tartıştı: Bu nitelik çok değerli olur ve değerleri yine derslerdir.

  <!-- BELİRSİZ: 01:52-01:58 arasındaki bu tartışmanın devamı altyazıda anlaşılmıyor. -->

- **Kardinalite gösterimi** (ekrandan, 01:00:00 ve 01:05:30). Bağıntı seti ile varlık seti arasındaki ok "bir", düz çizgi "çok" demektir. `instructor` ve `student` tarafında ok varsa bağıntı bire birdir: bir öğrenci en fazla bir hocaya, bir hoca en fazla bir öğrenciye bağlıdır. `l..h` gösteriminde `0..*` ve `1..1` ile ok kullanmadan hem kardinalite hem katılım anlatılır.
- **Zayıf varlık örneğinin adımları** (ekrandan, 01:40:00). (1) `course(course_id, title, credits)` ve `section(course_id, sec_id, semester, year)` oluşturulur. (2) İkisi arasında `sec_course` kurulunca `section.course_id` fazlalık olur ve çıkarılır. (3) Artık `section`'da anahtar yoktur: `sec_id` tek başına yetmez, çünkü her dersin 1, 2, 3 numaralı şubeleri olabilir; `sec_id` ve `semester` de yetmez, çünkü 2024 güz döneminde de 2025 güz döneminde de 1, 2, 3 numaralı şubeler açılır. Ancak üçü birden (`sec_id`, `semester`, `year`) bir dersin şubelerini ayırt eder. Buna anahtar değil ayırt edici denir. (4) `section` zayıf varlık seti olur, `course`'a çift çizgili `sec_course` ile bağlanır; zayıf taraf tam katılımlıdır.
- **Bütün diyagramın okunması** (ekrandan, 01:46:40). `section`'ın `sec_time_slot` ile bir `time_slot`'a bağlanması tam katılımlıdır (her şubenin bir zaman dilimi olmalı), ama bir `time_slot` numarası bir dönem kullanılmayabilir (kısmi). Hoca bir zaman dilimi numarasının birden çok oturumu olabileceğini, örneğin bu dersin iki oturumu olduğunu söyledi; bu yüzden `day`, `start_time`, `end_time` çok değerli bir niteliktir. Slayttaki kırmızı notlar, fazlalık kontrolü yapılmasaydı `student` şemasının `student(ID, name, tot_cred, dept_name, advisor, section)` ve `section` şemasının `section(course_id, sec_id, semester, year, building, room_number, time_slot_id)` olacağını gösteriyor; kalın yazılan nitelikler bağıntılardan çıkarılabildiği için fazlalıktır.
- **Bileşik ve çok değerli nitelikler** (ekrandan, 02:05:30 ve 02:10:00). Slayttaki `instructor` varlığında `name` (`first_name`, `middle_initial`, `last_name`), `address` (`street` (`street_number`, `street_name`, `apt_number`), `city`, `state`, `zip`), çok değerli `{phone_number}`, `date_of_birth` ve türetilmiş `age()` nitelikleri var. Çok değerli nitelikler dışarıda bırakılınca şema `instructor(ID, first_name, middle_initial, last_name, street_number, street_name, apt_number, city, state, zip_code, date_of_birth)` olur. Belirsizlik yoksa ön ek atılabilir (`name_first_name` yerine `first_name`). Telefon numaraları ise `inst_phone(ID, phone_number)` şemasına gider.
- **Şema fazlalığı** (ekrandan, 02:13:00). Slayttaki örnekte `inst_dept` için ayrı şema kurmak yerine `instructor` şemasına `dept_name` eklenir; çünkü her hocanın tam olarak bir bölümü vardır ve hoca tarafı tam katılımlıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
