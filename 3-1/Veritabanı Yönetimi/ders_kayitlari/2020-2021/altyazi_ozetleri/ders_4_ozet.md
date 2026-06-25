# Ders 4 Çalışma Özeti

## Genel Konular

- ER Diyagramları ile Kavramsal Tasarım Örnekleri
  - Futbol müsabakası tasarımı: Takım, Oyuncu, Oyun varlıkları ve aralarındaki bağıntılar
  - Banka hesabı işlem tasarımı: Hesap ve İşlem varlıkları, zayıf varlık olarak işlem
  - Uçak rezervasyonu sistemi: Havalimanı, Uçak, Uçuş, Uçuş Ayağı (Flight Leg), Uçuş Instansı, Koltuk ve Rezervasyon varlıkları
  - Çalışan özelleştirme (specialization) örnekleri: Yönetici, maaşlı/sözleşmeli çalışan ayrımı
  - Parça üretimi ve tedarik: overlap ve disjoint alt tipler
  - Üniversite çalışan yapısı: Alumni, Student, Employee ve Teaching/Research Assistant
  - Müzik dağıtım şirketi veritabanı: Artist, Composer, Lyricist, Musician, Song, Album, Retail vb.

- İlişkisel Veri Modeli (Relational Model)
  - Edgar F. Codd tarafından 1970'te tanımlanmış, 1981'de ACM Turing Award almıştır
  - 50+ yıllık, günümüzde en yaygın kullanılan veri modeli
  - İlişkisel model deterministik ve hızlıdır; her şey katalog/şema içinde tanımlıdır
  - NoSQL ile karşılaştırma: NoSQL şemasız ve esnek, ilişkisel model şemalı ve hızlı
  - Deklaratif (bildirim esaslı) veri işleme: SQL programlama dili değil, "ne istiyorum" sorusuna cevap verir
  - Veri bağımsızlığı (data independence) sağlar: Fiziksel ve mantıksal bağımsızlık

- İlişkisel Model Temel Kavramları
  - İlişki (Relation) / Tablo: Küme (set) kavramı üzerine kuruludur
  - Satır / Tuple: Her satır bir tuple; tekrarına izin verilmez (set esaslı)
  - Sütun / Nitelik / Attribute: Her niteliğin bir ismi ve yalın (atomic) değeri olmalı
  - Domain: Her niteliğin veri tipi ve formatı; örn. VARCHAR(25), DATE, 10 haneli decimal digit
  - NULL değeri: Belirsizlik; bilinmiyor, uygulanmıyor veya geçerli değil anlamına gelir
    - NULL = NULL sorusunun cevabı NULL'dur (ne True ne False)
    - İki NULL birbirine eşit olabilir, eşit olmayabilir; karşılaştırma sonucu belirsiz
  - Tablo derecesi (degree): Nitelik sayısı
  - Database şeması: Tüm tablo şemalarının bütünü

- Anahtar Kavramları
  - Süper Anahtar (Super Key): Tablodaki satırları birbirinden farklı kılan herhangi bir nitelik/nitelik grubu
  - Anahtar (Key) / Minimal Süper Anahtar: Süper anahtar olmakla birlikte, herhangi bir niteliği çıkarıldığında anahtar olma özelliğini kaybeden minimal süper anahtar
    - Her anahtar aynı zamanda süper anahtardır; ama her süper anahtar anahtar değildir
    - Bir anahtarı içeren her nitelik kümesi süper anahtardır
  - Aday Anahtar (Candidate Key): Tüm minimal süper anahtarların kümesi
  - Birincil Anahtar (Primary Key): Aday anahtarlar arasından seçilen tek anahtar
    - En küçük candidate key seçilmeli (performans açısından)
    - Kandidat key bulunamıyorsa yapay (artificial) anahtar eklenebilir, ancak bu sisteme yük getirir
  - ER diyagramında anahtar altı çizilerek gösterilir

- Kısıtlar (Constraints)
  - Anahtar Kısıtı (Key Constraint): Her tablonun satırları birbirinden farklı kılacak bir anahtarı olmalı
  - Varlık Bütünlük Kısıtı (Entity Integrity): Primary key'in hiçbir niteliği NULL olamaz
    - Composite key durumunda, key'i oluşturan hiçbir alt nitelik NULL olamaz
    - NULL belirsizlik taşıdığı için birincilik anahtarında bulunamaz
  - İma Bütünlük Kısıtı (Referential Integrity): Yabancı anahtar değeri, işaret edilen tablodaki mevcut bir primary key değerine eşit olmalı veya NULL olmalı
    - Logical (mantıksal) bir bağlantıdır; fiziksel pointer değildir
    - Yabancı anahtarın boyutu, işaret edilen tablonun primary key boyutu kadar olmalı
    - Yabancı anahtar aynı zamanda primary key'in parçasıysa NULL olamaz
  - Domain Kısıtı: Nitelik değerleri tanımlı domain'e uygun olmalı; NULL olabilir veya domain kuralına uymalı
  - Semantik Kısıtlar (Business Rules): Küçük dünyaya özel kurallar; örn. bir çalışan haftada en fazla 56 saat çalışabilir
    - Bu kısıtlar trigger, stored procedure gibi yapılarla sağlanır

- CRUD Operasyonları ve Kısıt İhlalleri
  - Create (Insert), Read (Retrieve/Select), Update (Modify), Delete
  - Read işlemi hiçbir zaman kısıt ihlali doğurmaz
  - Insert, Delete, Update işlemlerinde kısıt ihlali mümkündür
  - İhlal durumlarında sistem tepkileri:
    - Reject: İşlemi reddet ve kullanıcıya geri döndür
    - Cascade: Zincirleme olarak diğer tabloda da güncelleme/silme yap
    - Set NULL: İlgili yabancı anahtar değerini NULL yap
    - Set Default: İlgili yabancı anahtar değerini varsayılan değere ayarla
  - SQL'de ON DELETE ve ON UPDATE ile bu davranışlar şekillendirilebilir

## Hocanın Özellikle Vurguladığı Kısımlar

- ER tasarımında "küçük dünya" analizi çok önemlidir
  - Her maddeyi tek tek analiz edip bağıntıları kurmak gerekir
  - Cardinality (bire-çok, bire-bir, çok-çok) belirleme kritik
  - Tek çizgi (kısmi katılım) ve çift çizgi (tam katılım) ayrımı dikkatli yapılmalı
  - Zayıf varlık mı güçlü varlık mı sorusu, primary key bulunup bulunamadığına bağlıdır

- Primary key seçimi ve zayıf varlık belirleme
  - Nitelikler bir araya getirildiğinde unique kılıyorsa güçlü varlık
  - Unique kılamıyorsa zayıf varlık yapılır; güçlü varlığa bağlanır
  - Zayıf varlık yapmak mümkünse tercih edilmeli; yapay anahtar sisteme yük getirir

- İlişkisel modelin temel kısıtları çok önemli ve sınavlarda sorulur
  - Anahtar kısıtı, varlık bütünlük kısıtı, ima bütünlük kısıtı
  - Tanımları iyice anlamak ve örneklerle pekiştirmek gerekir

- Yabancı anahtar (foreign key) mantıksal bir bağlantıdır
  - Fiziksel pointer olmadığı için fiziksel tasarım esnektir
  - Sistem arka planda ima bütünlüğünü kontrol etmeli

- Tasarım kalitesi tüm veritabanının ömrünü etkiler
  - "Ağacın çekirdeği bozuksa meyveleri de çürür" benzetmesi
  - Tasarımdaki kararlar (anahtar seçimi, zayıf/güçlü varlık, katılım tipi) performansı ve doğruluğu etkiler

- Tasarım yeteneği pratikle kazanılır
  - Çok sayıda ER diyagramı örneği çözülmeli
  - Gereksinim listesinden ER diyagramına, ER'den ilişkisel modele dönüşüm hızlı yapılabilmeli

## Kısa Tekrar Notları

- ER diyagramında varlıklar dikdörtgen, nitelikler elips/oval, bağıntılar eşkenar dörtgen ile gösterilir
- Cardinality: Bire-çok (1:N), Çok-çok (M:N), Bire-bir (1:1)
- Zayıf varlık çift dikdörtgen, ayırt edici nitelik kesikli çizgi ile çizilir
- Specialization (özelleştirme): disjoint (ayrık) veya overlap (örtüşen); total veya partial
- Disjoint: Bir üst varlık en fazla bir alt tipe ait olabilir
- Overlap: Bir üst varlık birden çok alt tipe aynı anda ait olabilir
- Total: Üst varlıktaki her eleman en az bir alt tipe ait olmak zorunda
- İlişkisel modelde tablo = relation = çizelge; satır = tuple; sütun = attribute
- Tablo derecesi = nitelik sayısı
- NULL = belirsiz; NULL = NULL → NULL (ne true ne false)
- Süper anahtar ⊇ Key (anahtar) ⊇ Candidate Key → bir tanesi Primary Key
- Her anahtar süper anahtardır; tersi doğru değildir
- Entity Integrity: PK'daki hiçbir nitelik NULL olamaz
- Referential Integrity: FK değeri ya referans edilen tablodaki PK değerlerinden biri ya da NULL olmalı
- FK, PK'in parçasıysa NULL olamaz
- Semantik kısıtlar trigger/stored procedure ile sağlanır
- CRUD: Insert/Delete/Update kısıt ihlali doğurabilir; Read ihlal doğurmaz
- İhlal tepkileri: Reject, Cascade, Set NULL, Set Default

## Detaylı Açıklamalar

### ER Diyagramı Örnekleri ve Tasarım Prensipleri

Ders boyunca farklı küçük dünyalar için ER diyagramları çizilmiştir. Futbol müsabakası örneğinde Takım ve Oyuncu varlıkları arasında bire-çok bağıntı kurulmuştur (bir takımın çok oyuncusu olabilir, bir oyuncu en fazla bir takımda yer alabilir). Oyun varlığı başlangıçta güçlü varlık olarak düşünülmüş, ancak tarih ve sonuç niteliklerinin birlikte bile oyunları unique kılamayacağı fark edilince zayıf varlık olarak iki takıma bağlanmıştır. Burada tarih, ayırt edici nitelik (discriminator) olarak kullanılmıştır.

Banka işlemi örneğinde, bir hesapta birden çok işlem olduğu için Hesap-İşlem arasında bire-çok bağıntı kurulmuştur. İşlem için tüm nitelikler (miktar, tip, gün, saat) bir araya getirilse bile unique kılınamadığından işlem zayıf varlık olarak tanımlanmış; hesap güçlü varlık, gün ve saat ise ayırt edici nitelik olmuştur.

Uçak rezervasyonu sistemi en kapsamlı örnek olmuştur. Uçuş (Flight), Uçuş Ayağı (Flight Leg), Uçuş Instansı (Leg Instance), Uçak (Airplane), Koltuk (Seat) ve Rezervasyon varlıkları tanımlanmıştır. Planlanan uçuş bilgileri ile gerçek zamanlı uçuş bilgileri ayrı varlıklar olarak modellenmiştir. Tüm bu varlıklar zayıf varlık olarak Flight'a bağlanmış ve anahtarları, güçlü varlığın anahtarı ile birlikte belirlenmiştir.

### Specialization ve Generalization

Çalışan veritabanı örneğinde specialization (özelleştirme) kavramı işlenmiştir. Çalışanlar yönetici/maaşlı/sözleşmeli olarak ve mühendis/teknisyen/sekreter olarak iki farklı boyutta özelleştirilmiştir. İlk özelleştirme partial (total değil), ikinci özelleştirme disjoint ve partial'dır. Disjoint olduğu için bir çalışan aynı anda hem mühendis hem teknisyen olamaz; ancak farklı özelleştirme boyutlarından olduğu için bir mühendis aynı zamanda yönetici olabilir.

Sendika bağıntısının sadece sözleşmeli çalışanlarla ilişkilendirilmesi, specialization'ın bağıntıları daha doğru tanımlamada nasıl yardımcı olduğunu göstermiştir. Özelleştirme yapılmadığında, bağıntı tüm çalışanlarla tanımlanmak zorunda kalınır ve birçok NULL değer ortaya çıkar.

Parça (part) örneğinde overlap gösterilmiştir: Bir parça hem fabrikada üretilebilir hem de dışarıdan tedarik edilebilir. Üniversite örneğinde alumni, student ve employee arasında overlap vardır: Bir mezun aynı zamanda çalışan veya öğrenci olabilir.

### İlişkisel Model ve Temel Yapı

İlişkisel model, küme teorisi üzerine kuruludur. Her tablo bir kümedir; kümede tekrar eden eleman olmaz. Pratikte (bag/multiset) tekrar olabilir, ancak formal tanımda satırlar unique olmalıdır. Her nitelik yalın (atomic) bir değer içermelidir; adres gibi birden çok alt değer içeren nitelikler formal tanıma uygun değildir.

NULL değeri belirsizlik anlamına gelir: Ya o satır için geçerli değildir, ya da değeri bilinmemektedir. İki NULL değeri karşılaştırılamaz; NULL = NULL ifadesinin sonucu NULL'dur (ne true ne false). Bu durum, primary key'de NULL bulunmaması kuralının mantıksal temelini oluşturur.

### Anahtar Hiyerarşisi

Anahtar kavramları katmanlı bir hiyerarşi oluşturur:
1. **Süper Anahtar**: Satırları farklı kılan herhangi bir nitelik kümesi (çok geniş, pratik değeri sınırlı)
2. **Key (Minimal Süper Anahtar)**: Herhangi bir niteliği çıkarıldığında anahtar olma özelliğini kaybeden süper anahtar
3. **Candidate Key**: Tüm minimal süper anahtarların kümesi
4. **Primary Key**: Candidate key'lerden seçilen tek anahtar

Araba tablosu örneğinde: {State, Registration No} bir minimal süper anahtardır (şehir içinde plakalar unique). {Serial No} da başka bir minimal süper anahtardır (fabrika çıkış numarası dünya çapında unique). {Serial No, Make} süper anahtardır ama minimal değildir (Serial No tek başına yeterli). {Make, Model} süper anahtar değildir (aynı marka ve modelden birden çok araç olabilir).

### İma Bütünlüğü ve İhlal Yönetimi

Yabancı anahtar, ER diyagramındaki bağıntıların ilişkisel modele taşınmış halidir. Bir tablodaki yabancı anahtar, başka bir tablonun primary key'ine işaret eder. Bu mantıksal (logical) bir bağlantıdır; fiziksel pointer değildir. Bu sayede tabloların fiziksel yerleri bağımsız olarak değişebilir.

İma bütünlük kısıtı ihlali durumunda sistem default olarak işlemi reddeder. Ancak SQL'de ON DELETE ve ON UPDATE ile farklı davranışlar tanımlanabilir: Cascade (zincirleme güncelleme/silme), Set NULL (NULL yap), Set Default (varsayılan değere ayarla). Hangi davranışın seçileceği, iş kurallarına ve küçük dünyanın gereksinimlerine bağlıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.