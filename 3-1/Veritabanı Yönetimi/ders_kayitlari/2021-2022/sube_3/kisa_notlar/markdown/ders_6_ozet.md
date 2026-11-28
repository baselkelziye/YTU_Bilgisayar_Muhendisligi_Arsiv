# Ders 6 Çalışma Özeti

> Kayıt iki parçadır; arşivde parçalar yanlış sırada birleştirildiği için altyazıdaki sıra düzeltildi ve saat damgaları düzeltilmiş altyazıya göredir.

## Genel Konular

- Veritabanı tasarım süreci
  - Şimdiye kadar kullanılan şemaların (öğrenci kayıt, üniversite, company) nereden geldiği sorusuyla kavramsal tasarıma geçildi. Gerçek sistemlerde tablo sayısı, fonksiyonlar ve yetkilendirme ayarları ders örneklerinden çok daha kapsamlıdır.
  - Süreç: küçük dünyanın (miniworld) incelenmesi, gereksinimlerin toplanması ve analizi, kavramsal tasarım (ER), mantıksal tasarım (ilişkisel model tablolarına dönüşüm, data model mapping), fiziksel tasarım (indeksler, yardımcı görünümler, yetkilendirme) (ekrandan, 00:12:15).
  - Paralel dal: fonksiyonel gereksinimler, fonksiyonel analiz, uygulama programı tasarımı ve transaction implementation. Şemadaki kesikli çizginin üstü DBMS'ten bağımsız, altı DBMS'e özgüdür; PostgreSQL, Oracle, SQL Server ve SQLite gibi sistemlerde operatörler ve saklı yordamlar farklılaşabilir.
  - Süreç tek yönlü değildir: yeni gereksinimler ortaya çıktıkça mantıksal ve fiziksel tasarıma geri dönülüp ince ayar (tuning) yapılır.
  - Database life cycle: farklı kullanıcı görünümleri (retail salesperson view, customer view) önce ayrı alt şemalar olarak modellenir, sonra birleştirilerek (view integration) büyük şema elde edilir (ekrandan, 00:17:15).
- ER modelinin temel kavramları
  - Varlık: var olan ve diğerlerinden ayırt edilebilen nesne; benzer varlıkların kümesi varlık kümesi (entity set) (ekrandan, 00:27:15).
  - Nitelik (attribute): varlıkları birbirinden ayıran özellikler. Her niteliğin bir değer alanı (domain) vardır: tip, değer aralığı ve format bu kapsamdadır.
  - Bağıntı: iki ya da daha çok varlık arasındaki "olay"; aynı türdeki bağıntıların kümesi bağıntı kümesi. Küçük dünya tarif edilirken özneler varlığa, fiiller bağıntıya adaydır ("öğrenci dersi alıyor").
  - Kavramsal tasarımın zorluğu tek bir doğru tasarım olmamasıdır.
- ER gösterimleri
  - Varlık: dikdörtgen; zayıf varlık: çift çizgili dikdörtgen; bağıntı: eşkenar dörtgen; nitelik: elips.
  - Altı çizili nitelik: anahtar. Çift çizgili elips: çok değerli (multivalued). Alt niteliklere ayrılan nitelik: birleşik (composite). Kesikli elips: türetilmiş (derived) nitelik.
  - CAR örneği: Registration (State, Number) birleşik anahtar, Vehicle_id ayrı bir anahtar, Color çok değerli (ekrandan, 00:32:15).
- Bağıntı kümesi sınırlamaları (ekrandan, 00:42:15)
  - Bağıntı ismi, bağıntıdaki varlıklar (aynı ya da farklı), bağıntının derecesi (2, 3, ...), eleman sayıları (1-1, 1-N, N-1, N-N), rol tanımlama.
  - Aynı varlık kümesi üzerinde tanımlanan bağıntı recursive (unary) bağıntıdır; rol tanımı en çok burada gerekir (manager / subordinate).
- Var olma bağımlılığı (existence dependency)
  - B'deki her varlık A'daki bir varlıkla mutlaka bağıntı kurmak zorundaysa B, A'ya var olma bağımlıdır (total participation, çift çizgi). Değilse kısmi (partial, tek çizgi) (ekrandan, 00:47:15).
  - Bu kavram eleman sayısından bağımsızdır.
- Anahtarlar
  - Super anahtar: varlıkları birbirinden ayıran herhangi bir nitelik grubu. Aday anahtar (BA): hiçbir öz alt kümesi super anahtar olmayan, yani minimal super anahtar. Birincil anahtar: aday anahtarlardan seçilen biri (ekrandan, 01:02:15).
- Zayıf varlık kümesi
  - Bütün nitelikleri birlikte bile anahtar olamayan varlık kümesi. Güçlü bir varlık kümesiyle 1-1 ya da N-1 tipinde var olma bağımlı bir bağıntı kurar; aynı güçlü varlığa bağlı varlıkları ayırmak için ayırt edici nitelik (AN) tanımlanır.
  - Anahtarı: güçlü varlık kümesinin BA'sı + AN (ekrandan, 01:16:23).
- Bağıntıların anahtarları
  - N-N: bağıntıdaki varlık kümelerinin anahtarlarının hepsi. 1-N: N tarafındaki varlığın anahtarı. 1-1: herhangi bir tarafın anahtarı (ekrandan, 01:16:23).
  - Üçlü bağıntılarda: 1-1-1'de herhangi iki varlığın anahtarı, 1-1-N ve 1-N-N'de N tarafını içeren uygun ikili, N-N-N'de üçünün birden anahtarı.
- Üçlü bağıntı ile ikili bağıntıların farkı
  - SUPPLY(Supplier, Part, Project) üçlü bağıntısı, üç ikili bağıntıyla (SUPPLIES, CAN_SUPPLY, USES) aynı bilgiyi taşımaz: $(s,j,p) \neq (s,p)(j,p)(s,j)$ (ekrandan, 01:36:23).
  - Araç üçlü bağıntıya izin vermiyorsa SUPPLY zayıf varlık yapılıp üç güçlü varlığa 1-N tanımlayıcı bağıntılarla bağlanabilir; zayıf varlık da istenmiyorsa SUPPLY kendi anahtarı olan güçlü bir varlık yapılır.
- EER (genişletilmiş ER)
  - Genelleme / "IS A" (ait olma) bağıntısı: süper varlık (supertype) ve alt varlıklar (subtype). Süper varlığın nitelikleri ve anahtarı alt varlıklarda da geçerlidir (ekrandan, 01:46:23).
  - Katılım kısıtlaması: zorunlu (total) ya da seçimli (partial). Ayrıklık kısıtlaması: disjoint (d) ya da overlap (o). Böylece dört farklı kısıtlama tanımlanabilir.
  - Alt varlık kullanmak, ilgisiz niteliklerin NULL kalmasını önler.
- Aggregation
  - Bir bağıntı kümesinin, başka bir bağıntıya katılmak için varlık kümesi gibi ele alınmasıdır. Örnek: Employees, Departments ile Projects arasındaki Sponsors bağıntısını Monitors bağıntısıyla izler (ekrandan, 01:51:23).
- UML ile modelleme
  - Sınıf kutusu (ad, nitelikler, operasyonlar); ilişkiler: association, generalization, aggregation (part_of), composition (ekrandan, 01:56:23).
  - Çokluklar 1, 0..1, 0..*, 1..* gibi yazılır; var olma kısıtı da çoklukla (0 olup olmamasıyla) gösterilir. Bağıntının nitelikleri bağıntıya kesikli çizgiyle bağlanan bir kutuda yazılır.
  - Composition'da parçalar bütünden bağımsız anlam taşımaz (zayıf varlığa benzer); aggregation'da parçalar kendi başına anlamlıdır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bağıntı anahtarı kurallarının nedeni anlaşılmalı
  - Kuralları ezberlemek yerine bağıntı kümesinde bir varlığın kaç kez geçebileceğine örnek kümeler üzerinden bakmak gerekir. Bundan sonraki konular bu kurallara dayanır.
- Eleman sayıları üçlü bağıntıda iki varlıktan birer numune alınarak okunur
  - Örneğin bir teknisyen ve bir proje sabitlendiğinde kaç notebook olabileceği, notebook tarafındaki sayıyı verir.
- Tasarım kararları küçük dünyadan gelir
  - Hangi niteliğin anahtar olduğu, eleman sayıları ve katılım durumları gereksinim analizinden (müşteriyle görüşme) çıkar; ezbere konmaz.
- Tanımlar basit ama üst üste konunca zorlaşır
  - Temel kavramlar sağlam anlaşılmazsa üstüne kurulan tasarım yıkılır.
- Kavramsal tasarımdaki kararlar veritabanının bütün hayatını etkiler
  - Hoca bunu ağacın çekirdeğine benzetti: çekirdek bozuksa meyve de istenen gibi olmaz.
- Zayıf varlık kullanmak iyi bir tasarımdır
  - Sisteme ek bir birincil anahtar ve bu anahtarın benzersizliğini denetleme yükü getirmez.

## Kısa Tekrar Notları

- Tasarım aşamaları: gereksinim toplama ve analiz, kavramsal (ER), mantıksal (tablolar), fiziksel (indeks, yetkilendirme).
- Dikdörtgen varlık, çift dikdörtgen zayıf varlık, eşkenar dörtgen bağıntı, elips nitelik, altı çizili anahtar, çift elips çok değerli, kesikli elips türetilmiş.
- Çift çizgi total katılım (var olma bağımlılığı), tek çizgi kısmi katılım.
- Super anahtar, aday anahtar (minimal super anahtar), birincil anahtar.
- Zayıf varlık anahtarı = güçlü varlığın BA'sı + AN.
- Bağıntı anahtarı: N-N tüm anahtarlar, 1-N N tarafı, 1-1 herhangi biri.
- Üçlü bağıntı: 1-1-1'de herhangi iki varlık, N-N-N'de üçü birden.
- Üçlü bağıntı, üç ikili bağıntıyla aynı bilgiyi taşımaz.
- Aynı kişi aynı kursu farklı yıllarda alabiliyorsa yıl da anahtara girer.
- EER: total/partial ve disjoint/overlap kısıtları; alt varlıklar NULL'ları önler.
- UML'de 0..1, 1, 0..*, 1..* çoklukları; composition bütüne bağımlı parça, aggregation bağımsız parça.

## Detaylı Açıklamalar

- Bağıntı anahtarlarının nedeni
  - 1-1 is-managed-by bağıntısında örnek küme $(d_1,e_1),(d_2,e_2),(d_3,e_3)$ gibidir. Bir departman da bir çalışan da en fazla bir kez geçer, bu yüzden departman numarası ya da çalışan numarası tek başına bağıntının anahtarıdır.
  - 1-N departman-çalışan bağıntısında $(d_1,e_1),(d_1,e_2),(d_1,e_3)$ olabilir ama $(d_1,e_1),(d_2,e_1)$ olamaz. Çalışan en fazla bir kez geçtiği için anahtar N tarafındaki çalışanın anahtarıdır.
  - N-N çalışan-proje bağıntısında $(e_1,p_1),(e_1,p_2),(e_3,p_1)$ olabilir; iki taraf da tekrar ettiği için anahtar iki anahtarın birleşimidir.
- Üçlü bağıntı örnekleri (ekrandan, 01:26:23 ve 01:31:23)
  - 1-1-1 (Technician, Project, Notebook): bir teknisyen bir projede tam bir notebook kullanır, bir notebook bir projede tek teknisyene aittir. Slayttaki fonksiyonel bağımlılıklar: emp-id, project-name -> notebook-no; emp-id, notebook-no -> project-name; project-name, notebook-no -> emp-id. Anahtar herhangi iki varlığın anahtarıdır.
  - 1-1-N (Project 1, Employee N, Location 1): emp-id, loc-name -> project-name; emp-id, project-name -> loc-name. Anahtar (Employee, Location) ya da (Employee, Project).
  - 1-N-N (Manager 1, Engineer N, Project P): project-name, emp-id -> mgr-id. Anahtar (Engineer, Project).
  - M-N-P (Employee, Skill, Project): fonksiyonel bağımlılık yok, anahtar üçünün birleşimi.
- Zayıf varlık örnekleri (ekrandan, 01:07:15)
  - LİSE (isim anahtar) 1 - kayıtlı - N ÖĞRENCİ (öğrNo ayırt edici nitelik). Lise isimleri benzersizdir ama aynı öğrenci numarası farklı liselerde kullanılabilir. Hoca, kayıtlı bağıntısının da var olma bağımlı olduğu için çift çizgili çizilmesi gerektiğini belirtti.
  - SatışFormu (satışno anahtar, tarih, geneltoplam türetilmiş) 1 - SS - N Satır (Satırno ayırt edici). Satır numarası yalnız bir satış formu içinde benzersizdir; Satır'ın anahtarı satışno + Satırno olur.
- EER örnekleri (ekrandan, 01:46:23)
  - GEMİ (gNo, ağırlık) disjoint ve total olarak YOLCUGEMİSİ (yolcuSayısı, kaliteSınıfı) ve YÜKGEMİSİ (yükKapasitesi, yükTürü) alt varlıklarına ayrılır. Alt varlık kullanılmasaydı bütün nitelikler GEMİ'de toplanır, yolcu gemileri için yük nitelikleri NULL kalırdı.
  - Employee: Manager, Engineer, Technician, Secretary (disjoint, partial). Individual: Employee, Customer (overlap, total).
- Aggregation ve üçlü bağıntı (ekrandan, 01:51:23)
  - Monitors kendi niteliği (until) olan ayrı bir bağıntı olduğu için aggregation en uygunudur. Üçlü bağıntıyla tasarlansaydı Sponsors'un since niteliği her izleme için tekrar ederdi. until saklanmayacaksa üçlü bağıntı kullanılabilir.
- UML örneği (ekrandan, 02:06:23)
  - KİŞİ (kişiNo BA) 0..* - katılır - 0..* KURS (kNO BA), bağıntı nitelikleri yıl ve başarı. Bir kişi aynı kursu farklı yıllarda tekrar alabiliyorsa bağıntı kümesinin anahtarı kişiNo + kNO + yıl olur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
