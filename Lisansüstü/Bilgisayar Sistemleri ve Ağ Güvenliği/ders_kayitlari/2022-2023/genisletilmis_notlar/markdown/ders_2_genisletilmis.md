# Ders 2 Genişletilmiş Notu: Bilgisayar Güvenliğine Genel Bakış

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin kapsamı ve önkoşul bilgiler
- 2. Temel güvenlik kavramları: CIA üçlüsü ve güvenlik beşgeni
- 3. Etki düzeyleri
- 4. Bilgisayar güvenliğinin zorlukları
- 5. Bilgisayar güvenliği terminolojisi
- 6. Varlıklar, güvenlik açıkları, tehditler ve saldırılar
- 7. Tehdit sonuçları ve tehdit eylemleri
- 8. Varlıklara göre tehdit örnekleri
- 9. Pasif ve aktif saldırılar
- 10. Güvenlik gereksinimleri (FIPS 200)
- 11. Temel güvenlik tasarım ilkeleri
- 12. Saldırı yüzeyleri ve derinlemesine savunma
- 13. Güvenlik stratejisi ve standartlar
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin kapsamı ve önkoşul bilgiler

Ders, lisans düzeyinde verilen bilgisayar ve ağ güvenliği dersinin devamı olarak kurgulanmıştır. Lisansüstü bir ders olduğu için yalnız teknik mekanizmalarla kalmaz; güvenliğe bir üst yönetim bakış açısıyla da bakar. Temel kaynak William Stallings ve Lawrie Brown'ın *Computer Security: Principles and Practice* kitabının 4. baskısıdır (2018). Hoca bu kitabı güvenlik alanındaki en güncel kaynaklardan biri olarak tanıttı.

Ekrandaki müfredat şöyledir (ekrandan, 00:20:00):

- Genel Bakış
- Yönetim Sorunları
  - BT Güvenlik Yönetimi ve Risk Değerlendirmesi
  - BT Güvenlik Kontrolleri, Planları ve Prosedürleri
  - Fiziksel ve Altyapı Güvenliği
  - İnsan Kaynakları Güvenliği
  - Güvenlik Denetimi
  - Bilişim Güvenliğinde Yasal ve Etik Hususlar
- Şifreleme Algoritmaları
  - Şifreleme Araçları
  - Simetrik Şifreleme ve Mesaj Gizliliği
  - Açık Anahtarlı Şifreleme ve İleti Kimlik Doğrulaması
- Ağ Güvenliği
  - İnternet Güvenlik Protokolleri ve Standartları
  - İnternet Kimlik Doğrulama Uygulamaları
  - Kablosuz Ağ Güvenliği

Hoca, bilişim sistemi güvenliğinin yalnız işletim sisteminin ya da ağın mantıksal güvenliği olmadığını, fiziksel altyapının ve sistemi kullanan ya da yöneten insanların güvenliğinin de kapsama girdiğini belirtti. Ağ güvenliği bölümünde internet kimlik doğrulama uygulamalarına örnek olarak Kerberos'u andı.

Derse gelmeden bilinmesi beklenen konular şunlardır:

- Şifreleme araçları: simetrik ve asimetrik şifreleme.
- Kimlik doğrulama ve erişim (giriş) kontrolü.
- Veri tabanı ve veri merkezi güvenliği.
- Kötü amaçlı yazılımlar: virüs, solucan, truva atı; özellikle virüs ile solucan arasındaki fark.
- Hizmet reddi (DoS) saldırısı ve tampon taşması saldırısı.
- Güvenlik duvarı (firewall), IDS ve IPS'in en azından çalışma mantığı.

> **Hocanın vurgusu:** Yönetimsel süreçler anlatılacak olsa da her birinin dayandığı sistem güvenliği konularına vakıf olmak gerekir; virüs ile solucan arasındaki farkı, hizmet reddi ve tampon taşması saldırılarının ne olduğunu en azından bilmek lazımdır.

## 2. Temel güvenlik kavramları: CIA üçlüsü ve güvenlik beşgeni

Hoca güvenliği bir benzetmeyle açtı: bir binanın, bir bankanın, bir insanın güvenliğinden söz ederken hep değerli bir şeyi korumaktan söz ederiz. Bu değerli şeye **varlık** (asset) denir. Güvenlik, bu varlığı tehditlere ve saldırılara karşı muhafaza etmektir. Bilişimde korunan varlık en genel haliyle veri ve servislerdir.

Ekrandaki beşgenin ortasında "Data and services" yazar; kenarlarında beş güvenlik hedefi vardır: Confidentiality, Integrity, Authenticity, Availability, Accountability (ekrandan, 00:25:00).

- **Gizlilik (Confidentiality):** veri gizliliği ve mahremiyet.
- **Bütünlük (Integrity):** veri bütünlüğü ve sistem bütünlüğü. Varlık hem veri hem sistem olarak düşünüldüğü için bütünlüğün de iki türü vardır.
- **Kullanılabilirlik (Availability):** bilgiye ve hizmete erişilebilmesi.

Slayttaki ifadeyle bu üç kavram genellikle **CIA üçlüsü** olarak adlandırılır ve temel güvenlik bileşenlerini oluşturur. Üçlüye iki bileşen daha eklenince beşgen elde edilir:

- **Özgünlük (Authenticity):** hakiki olma, doğrulanabilme ve güvenilir olma özelliği.
- **Hesap verebilirlik (Accountability):** bir varlığın eylemlerinin o varlığa benzersiz olarak izlenmesi gereksinimini oluşturan güvenlik hedefi. Hoca bunu, bir mesaj geldiğinde mesajı gönderenin gerçekten orada adı yazan kişi olduğunun tespit edilebilmesi örneğiyle açıkladı.

### 2.1 Tanımlar

Hoca tanımları NIST'in FIPS 199 standardına (federal bilgi ve bilgi sistemlerinin güvenlik sınıflandırması, Şubat 2004) dayandırdı:

- **Gizlilik:** kişisel gizliliğin ve özel bilgilerin korunmasına yönelik araçlar da dahil olmak üzere, bilgiye erişim ve bilginin ifşasına ilişkin yetki kısıtlamalarının korunması.
- **Bütünlük:** bilginin reddedilmemesini ve özgünlüğünü sağlamak da dahil olmak üzere, uygunsuz bilgi değişikliğine ya da tahribatına karşı korunma.
- **Kullanılabilirlik:** bilgiye zamanında ve güvenilir erişim, bilginin zamanında ve güvenilir kullanımı.

Ardından gelen slaytta diğer iki kavram açıklanır (ekrandan, 00:30:00):

- **Özgünlük:** kullanıcıların söyledikleri kişi olduklarını ve sisteme gelen her girdinin güvenilir bir kaynaktan geldiğini doğrulamak.
- **Hesap verebilirlik:** inkar etmeme, caydırıcılık, hata izolasyonu, izinsiz giriş tespiti ve önleme, eylem sonrası kurtarma (sistemi eski haline getirme) ve yasal işlemi destekleme.

> **Ek bilgi (derste anlatılmadı):** FIPS 199'un resmi adı büyük olasılıkla "Standards for Security Categorization of Federal Information and Information Systems"tır. Altyazıda standart numarası "1999" diye bozulmuştur; doğrusu 199'dur.

## 3. Etki düzeyleri

Güvenlik, korunmaya ihtiyaç duyan bir varlık üzerinden tanımlandığı için bir güvenlik zafiyeti oluştuğunda bunun o varlığa etkisinin seviyelendirilmesi gerekir. Hoca burada mühendislik bakışını vurguladı: "çok etkiledi" demek yetmez, "çok"un referansı nedir? Yükseklik örneğinde olduğu gibi birine 1 metre yüksek gelir, birine 100 metre; bir referans noktası tanımlanmalıdır. Bu yüzden üç etki düzeyi tanımlanır:

- **Düşük:** kaybın, yani güvenlik zafiyetinin, organizasyonel operasyonlar, organizasyonel varlıklar ya da bireyler üzerinde sınırlı bir olumsuz etkisi olması beklenir.
- **Orta:** aynı unsurlar üzerinde ciddi bir olumsuz etki beklenir.
- **Yüksek:** ölümcül, hayati, geri dönülemez bir etki beklenir.

### 3.1 Web sitesi örneği

Hoca kullanıcılarla ilgili bilgi tutan bir web sitesi örneği verdi:

- Sitede bir anket yapılıyor ve tutulan veriler anket verileri ya da kullanıcıyla ilgili pek de hayati olmayan veriler ise, sızıntının etkisi **düşüktür**.
- Tutulan veriler kullanıcıların adları, adresleri ve sepet içerikleri ise etki **orta** düzeydedir.
- Tutulan veriler hesap bilgileri, parasal bilgiler ya da çok gizli bilgiler ise sızıntı işin kaybedilmesine yol açabilir; etki **yüksektir**.

## 4. Bilgisayar güvenliğinin zorlukları

Ekrandaki slaytta on madde vardır (ekrandan, 00:35:00):

1. Bilgisayar güvenliği, acemilere ilk bakışta göründüğü kadar basit değildir.
2. Belirli bir güvenlik mekanizması ya da algoritması geliştirilirken her zaman bu güvenlik özelliklerine yönelik olası saldırılar göz önünde bulundurulmalıdır.
3. Belirli hizmetleri sağlamak için kullanılan prosedürler genellikle mantık dışıdır.
4. Fiziksel ve mantıksal yerleşim belirlenmelidir.
5. Güvenlik mekanizmaları tipik olarak belirli bir algoritma ya da protokolden fazlasını içerir ve ayrıca katılımcıların, bu gizli bilgilerin oluşturulması, dağıtılması ve korunması hakkında sorular ortaya çıkaran bazı gizli bilgilere sahip olmalarını gerektirir.
6. Saldırganların yalnızca tek bir zayıf noktayı bulması gerekirken, tasarımcı mükemmel güvenlik elde etmek için tüm zayıflıkları bulup ortadan kaldırmalıdır.
7. Güvenlik, tasarım sürecinin ayrılmaz bir parçası olmaktan ziyade, tasarım tamamlandıktan sonra bir sisteme dahil edilmek için hâlâ çok sık sonradan düşünülen bir şeydir.
8. Güvenlik, düzenli ve sürekli izleme gerektirir.
9. Kullanıcıların ve sistem yöneticilerinin, bir güvenlik arızası meydana gelene kadar güvenlik yatırımından çok az fayda sağlandığı algısına yönelik doğal bir eğilimi vardır.
10. Birçok kullanıcı ve hatta güvenlik yöneticisi, güçlü güvenliği bir bilgi sisteminin verimli ve kullanıcı dostu çalışmasına ya da bilgi kullanımına bir engel olarak görür.

Hoca bu maddeleri şöyle açıkladı. Güvenlik yatırımı başarılı olduğunda hiçbir saldırı yaşanmaz; ama bu yatırımla kaç saldırının önlendiğinin kaydını kimse tutmaz. Bu yüzden yatırım boşa gidiyormuş gibi görünür ve güvenlik işten anlamayana basit gelir. Prosedürler de bilmeyene mantık dışı görünür; "bunu niye yapıyoruz" sorusu sık sık çıkar.

Dördüncü maddede hoca, bilgisayar güvenliği denince yalnız dijital tarafın anlaşılmaması gerektiğini, fiziksel ve mantıksal yerleşimin de güvenliğin parçası olduğunu söyledi. Beşinci maddeyi insan faktörüyle bağladı: sistem ne kadar güvenli kurulursa kurulsun, insan zafiyeti sorun çıkarır; bu yüzden güvenlik herkesin katılımını gerektirir.

> **Hocanın vurgusu:** Güvenlik tasarımın ayrılmaz parçasıdır. Bugün çoğu zaman önce ağ kurulur, program yazılır, uygulama geliştirilir, sonra güvenliğe dönülür. Bu, önce binayı yapıp sonra depreme dayanıklı mı diye kontrol etmeye benzer; oysa zeminden başlayarak kaliteli malzemeyle yapmak gerekir.

> **Hocanın vurgusu:** Güvenlik anahtar teslim bir iş değildir; "yaptım, bitti" denemez. Kurulmalı, uygulanmalı ve sürekli izlenmelidir; aksi halde güvenlik sağlanmış olmaz.

Son maddede hoca, güçlü biçimde kurulmuş bir güvenlik mekanizmasının birçok kullanıcı, hatta güvenlik yöneticisi tarafından kullanıcı dostu olmayan, hantal bir yapı ve optimum çalışmaya engel olarak algılandığını belirtti.

## 5. Bilgisayar güvenliği terminolojisi

Terminoloji slaytı RFC 2828, İnternet Güvenliği Sözlüğü (Mayıs 2000) temel alınarak hazırlanmıştır (ekrandan, 00:40:00):

- **Adversary (düşman, tehdit ajanı):** zararlı faaliyetler yürüten ya da yürütme niyetinde olan kişi, grup, kuruluş ya da hükümet.
- **Attack (saldırı):** bilgi sistemi kaynaklarını ya da bilginin kendisini toplamaya, bozmaya, reddetmeye ya da yok etmeye çalışan her türlü kötü niyetli faaliyet.
- **Countermeasure (karşı önlem):** istenmeyen ya da düşmanca faaliyetlerin operasyonel etkinliğini bozmayı ya da casusluk, sabotaj, hırsızlık ya da hassas bilgi ya da bilgi sistemlerine yetkisiz erişimi ya da bu sistemlerin kullanımını önlemeyi amaçlayan bir cihaz ya da teknik.
- **Risk:** bir işletmenin olası bir durum ya da olay tarafından ne ölçüde tehdit edildiğinin ölçüsü; tipik olarak 1) durum ya da olay meydana geldiğinde ortaya çıkacak olumsuz etkiler ve 2) meydana gelme olasılığı ile belirlenir.
- **Security Policy (güvenlik politikası):** güvenlik hizmetlerinin sağlanması için bir dizi kriter; sistemler ve veriler için bir güvenlik koşulu sağlamak amacıyla bir veri işleme tesisinin faaliyetlerini tanımlar ve kısıtlar.
- **System Resource (sistem kaynağı, asset, varlık):** ana uygulama, genel destek sistemi, yüksek etkili program, fiziksel tesis, kritik görev sistemi, personel, ekipman ya da mantıksal olarak ilişkili bir sistem grubu.
- **Threat (tehdit):** yetkisiz erişim, bilgilerin yok edilmesi, ifşa edilmesi, değiştirilmesi yoluyla bir bilgi sistemi aracılığıyla kurumsal operasyonları (misyon, işlevler, imaj ya da itibar dahil), kurumsal varlıkları, bireyleri, diğer kuruluşları ya da ulusu olumsuz etkileme potansiyeli olan herhangi bir durum ya da olay ve/veya hizmet reddi.
- **Vulnerability (güvenlik açığı):** bir tehdit kaynağı tarafından istismar edilebilecek ya da tetiklenebilecek bir bilgi sistemi, sistem güvenlik prosedürleri, iç kontroller ya da uygulamadaki zayıflık.

### 5.1 Kavramlar arasındaki ilişki

Hoca bu kavramları bir döngüyle bağladı. Ortada varlık vardır. Varlığın bir sahibi vardır ve varlık sahibine göre bir değer taşır. Sahibin amacı varlığa yönelik tehditleri ve riskleri en aza indirmektir; bunun için önlem alır: varlık bir ağ ise güvenlik duvarı kurar, bir bina ise güvenlik görevlisi ve kamera sistemi kurar, yani yatırım yapar.

Karşı tarafta varlığı ele geçirmek isteyen saldırganlar vardır. Saldırganın amacı varlığı ifşa etmek, bozmak ya da kötüye kullanmaktır. Bunun için yollar arar ve tehdit oluşturur. Oluşan tehdit riski artırır; risk arttıkça sahip daha çok önlem almaya çalışır ve döngü sürekli devam eder. Sonunda bir yerde zayıflık kalırsa saldırgan kaynağı ele geçirir, değiştirir ya da kötüye kullanır.

## 6. Varlıklar, güvenlik açıkları, tehditler ve saldırılar

### 6.1 Varlık türleri

Bir bilişim sistemi açısından varlık şunlar olabilir:

- **Donanım:** bilgisayar sistemleri, veri işleme ve veri depolama sistemleri, iletişim cihazları.
- **Yazılım:** işletim sistemi, yardımcı programlar, uygulamalar.
- **Veri:** tablolar, dosyalar, veri tabanları, parola dosyaları gibi güvenlikle ilgili veriler, patent bilgileri.
- **İletişim hatları ve ağlar:** yerel ve geniş alan ağları, iletişim bağlantıları, köprüler (bridge), yönlendiriciler (router), anahtarlar (switch).

<!-- BELİRSİZ: veri varlıkları listesinde altyazı "paralolar" diyor; "parola dosyaları" olarak yorumlandı, slayt görülmedi. -->

### 6.2 Güvenlik açıkları, tehditler, saldırılar

Ekrandaki slayt üç başlık altında toplanır (ekrandan, 00:45:00):

- Güvenlik açıkları kategorileri:
  - Corrupted, bozuk (bütünlük kaybı).
  - Leaky, sızdıran (gizlilik kaybı).
  - Unavailable, kullanılamaz ya da çok yavaş (kullanılabilirlik kaybı).
- Tehditler:
  - Güvenlik açıklarından yararlanma yeteneği.
  - Bir varlığa yönelik olası güvenlik zararını temsil eder.
- Saldırılar (gerçekleştirilen tehditler):
  - Pasif: sistem kaynaklarını etkilemeden sistemden bilgi öğrenmeye ya da sistemden yararlanmaya çalışmak.
  - Aktif: sistem kaynaklarını değiştirmeye ya da operasyonlarını etkilemeye çalışmak.
  - Kökenine göre: insider (güvenlik çevresi içindeki bir varlık tarafından başlatılır) ve outsider (çevrenin dışından başlatılır).

Hoca açık kategorilerini CIA üçlüsüne bağladı: veri bozulursa bütünlük kaybedilir; veri iletilirken sızarsa gizlilik kaybedilir; veriye ulaşım engellenir ya da hizmet saldırgan tarafından yavaşlatılırsa kullanılabilirlik kaybedilir.

Pasif saldırıda amaç sistemi ya da bilgiyi bozmak, zarar vermek değil, yalnız bilgi edinmek ya da sistemden yararlanmaktır. İçeriden ve dışarıdan saldırı ayrımı için hoca üniversite kampüsünü örnek verdi: saldırı kampüsün güvenlik alanı içindeki biri, örneğin bir çalışan tarafından yapılırsa içeriden (insider), güvenlik çevresinin dışından gelirse dışarıdan (outsider) saldırıdır.

### 6.3 Karşı önlemler

Güvenlik saldırılarıyla başa çıkmak için kullanılan araçlara karşı önlem (countermeasure) denir. Karşı önlemin üç amacı olabilir: saldırıyı **önlemek**, **tespit etmek** ya da saldırı gerçekleşmişse **kurtarmak**. Karşı önlem bir yazılım ya da donanım olabilir.

> **Hocanın vurgusu:** Sisteme bir önlem eklemek, sisteme yeni bir bileşen eklemek demektir; eklenen bileşen de doğası gereği kendi zayıflıklarını getirebilir. Bu yüzden amaç, önlemle birlikte gelen artık risk düzeyini en aza indirmektir.

## 7. Tehdit sonuçları ve tehdit eylemleri

Ekrandaki tablo RFC 4949'a dayanır (ekrandan, 00:50:00). Sol sütun tehdit sonucunu, sağ sütun o sonuca yol açan tehdit eylemlerini (saldırıları) verir.

| Tehdit sonucu | Tehdit eylemi (saldırı) |
|---|---|
| **Yetkisiz açıklama:** bir kuruluşun yetkili olmadığı verilere erişim kazandığı bir durum ya da olay. | **Maruziyet:** hassas veriler doğrudan yetkisiz bir varlığa verilir. **Müdahale:** yetkisiz bir varlık, yetkili kaynaklar ve hedefler arasında seyahat eden hassas verilere doğrudan erişir. **Çıkarım:** yetkisiz bir varlığın, iletişimin özelliklerinden ya da yan ürünlerinden yola çıkarak hassas verilere (ancak iletişimde bulunan verilere zorunlu olarak değil) dolaylı olarak eriştiği bir tehdit eylemi. **İzinsiz giriş:** yetkisiz bir varlık, bir sistemin güvenlik korumalarını atlayarak hassas verilere erişim kazanır. |
| **Aldatma:** yetkili bir kuruluşun yanlış veri almasına ve bunun doğru olduğuna inanmasına neden olabilecek bir durum ya da olay. | **Maskeli:** yetkisiz bir varlık, bir sisteme erişim kazanır ya da yetkili bir varlık gibi davranarak kötü niyetli bir eylem gerçekleştirir. **Tahrif:** yanlış veriler yetkili bir varlığı aldatır. **Reddetme:** bir varlık, bir eylemin sorumluluğunu yanlış bir şekilde reddederek bir başkasını aldatır. |
| **Bozulma:** sistem hizmetlerinin ve işlevlerinin doğru çalışmasını kesintiye uğratan ya da engelleyen bir durum ya da olay. | **Aciz bırakma:** bir sistem bileşenini devre dışı bırakarak sistem çalışmasını engeller ya da kesintiye uğratır. **Yolsuzluk:** sistem işlevlerini ya da verilerini olumsuz yönde değiştirerek sistem çalışmasını istenmeyen şekilde değiştirir. **Engel:** sistemin çalışmasını engelleyerek sistem hizmetlerinin sunumunu kesintiye uğratan bir tehdit eylemi. |
| **Gasp:** yetkisiz bir varlık tarafından sistem hizmetlerinin ya da işlevlerinin kontrolüyle sonuçlanan bir durum ya da olay. | **Zimmete para geçirme:** bir varlık, bir sistem kaynağının yetkisiz mantıksal ya da fiziksel kontrolünü üstlenir. **Yanlış kullanım:** bir sistem bileşeninin, sistem güvenliğine zarar veren bir işlevi ya da hizmeti gerçekleştirmesine neden olur. |

Hoca maruziyet ile müdahale arasındaki farkı şöyle açıkladı: maruziyette veri hata ya da ifşa sonucu doğrudan yetkisiz kişiye verilir; müdahalede ise veri, örneğin iletim hattında transfer edilirken ele geçirilir. Müdahale ile izinsiz giriş de farklıdır: müdahale verinin aktarım sırasında elde edilmesi, izinsiz giriş ise doğrudan sisteme girilmesidir. Çıkarımda saldırgan gizli bilgiye doğrudan değil, yan ürünlerden ve yan bilgilerden yola çıkarak ulaşır.

### 7.1 Sistemsel güvenlik konuları

Hoca, bir A bilgisayar sisteminden B bilgisayar sistemine verinin uzaktan aktarıldığı bir durumu düşünerek güvenliğin dört temel konusunu sıraladı:

1. Verilere erişimin kontrol edilmesi gerekir: koruma (protection) güvenliği.
2. Bilgisayar sistemine erişimin kontrol edilmesi gerekir: kullanıcı doğrulama.
3. Verinin güvenli biçimde aktarılması gerekir: ağ güvenliği.
4. Sistemdeki verilerin bütünlüğünün garanti edilmesi gerekir: dosya bütünlüğü.

<!-- BELİRSİZ: bu bölümün slaytı (bilgisayar sistemleri arasındaki veri aktarımı şekli) karelerde görülmedi; dört konu altyazıdan alındı. -->

## 8. Varlıklara göre tehdit örnekleri

Hoca dört varlık türünü CIA üçlüsüyle eşleştirerek tehdit örnekleri verdi.

| Varlık | Kullanılabilirlik | Gizlilik | Bütünlük |
|---|---|---|---|
| Donanım | Ekipmanın çalınması ya da devre dışı bırakılması | Ekipmandaki şifrelenmemiş bilginin çalınması | (hocaya göre tehdit yok) |
| Yazılım | Programın silinmesi, kullanıcıların erişiminin engellenmesi | Yazılımın yetkisiz kopyalanması | Çalışırken başarısız olacak ya da istenmeyen işlev yapacak biçimde değiştirilmesi |
| Veri | Dosyanın silinmesi, erişimin engellenmesi | Yetkisiz okunması; istatistiksel analizle çıkarım yapılması | Mevcut dosyaların değiştirilmesi, sahte dosya üretilmesi |
| İletişim hatları | Mesajın yok edilmesi ya da silinmesi, hattın kullanılamaz hale gelmesi | Mesajın okunması | Mesajın değiştirilmesi, ertelenmesi, yeniden sıralanması, çoğaltılması; sahte mesaj üretilmesi |

<!-- BELİRSİZ: bu tablonun slaytı karelerde görülmedi; satırlar altyazıdan kuruldu. -->

Donanımda bütünlük tehdidi için hoca, ekipman çalışmayacağına göre bütünlükle ilgili bir tehditten söz edilemeyeceğini söyledi.

> **Ders sonrası not:** Hoca iletişim hattında gizlilik tehditleri arasında gönderilen mesajın "düzeninin, sırasının değişmesi"ni de saydı. Kaynak kitapta iletişim hattındaki ikinci gizlilik tehdidi büyük olasılıkla "mesaj trafiğinin örüntüsünün gözlenmesi" (trafik analizi) şeklindedir; mesaj sırasının değiştirilmesi ise bütünlük tehdididir ve hoca da onu ayrıca bütünlük altında saydı.

## 9. Pasif ve aktif saldırılar

Ekrandaki karşılaştırma şöyledir (ekrandan, 00:55:00):

- **Pasif saldırı**
  - Sistemden bilgi öğrenmeye ya da sistemden yararlanmaya çalışır, ancak sistem kaynaklarını etkilemez.
  - İletimlerin dinlenmesi ya da izlenmesi.
  - Saldırganın amacı iletilen bilgiyi elde etmektir.
  - İki tip: mesaj içeriğinin serbest bırakılması (ifşası) ve trafik analizi.
- **Aktif saldırı**
  - Sistem kaynaklarını değiştirme ya da operasyonlarını etkileme girişimleri.
  - Veri akışında bazı değişiklikler ya da yanlış bir akış oluşturulmasını içerir.
  - Dört kategori: tekrar oynatma (replay), maskeli saldırı, mesajların değiştirilmesi, hizmet reddi.

> **Ek bilgi (derste anlatılmadı):** Trafik analizinde saldırgan mesaj içeriğini okuyamasa bile (örneğin içerik şifreliyse) kimin kiminle, ne sıklıkla ve hangi boyutta mesajlaştığını gözleyerek bilgi çıkarabilir. Pasif saldırılar veride değişiklik yapmadığı için tespit edilmeleri zordur; bu yüzden onlara karşı tespitten çok önleme (örneğin şifreleme) öne çıkar.

## 10. Güvenlik gereksinimleri (FIPS 200)

Hoca güvenlik gereksinimlerini FIPS 200'e göre sıraladı. Anlatılan gereksinimler şunlardır:

- **Erişim (giriş) kontrolü:** bilgi sistemine erişimin yetkili kullanıcılarla, yetkili kullanıcılar adına hareket eden süreçlerle ya da cihazlarla ve yetkili kullanıcıların gerçekleştirmesine izin verilen işlem ve işlev türleriyle sınırlandırılması.
- **Farkındalık ve eğitim:** kurumsal bilgi sistemlerinin yöneticilerinin ve kullanıcılarının, faaliyetleriyle ilişkili güvenlik riskleri ve ilgili yasa, yönetmelik ve kurum politikaları hakkında bilgilendirilmesi.
- **Denetim ve hesap verebilirlik:** hoca, çalışanlar politikalardan ve yasalardan haberdar edilmezse denetleme ve yanlış bulunduğunda hesap sorma imkanının ortadan kalkacağını vurguladı.
- **Sertifikasyon, akreditasyon ve güvenlik değerlendirmesi.**
- **Konfigürasyon yönetimi:** sistem geliştirme yaşam döngüsü boyunca yazılım, donanım, bellenim ve belgeler dahil kurumsal bilgi sistemlerinin yönetilmesi.
- **Acil durum planlaması:** acil durumlarda kritik bilgi kaynaklarının mevcudiyetini ve operasyonların sürekliliğini sağlamak.
- **Tanımlama ve kimlik doğrulama.**
- **Olay müdahalesi:** yeterli hazırlık, tespit, analiz, sınırlama ve kurtarma.
- **Bakım.**
- **Medya koruması, fiziksel ve çevresel koruma, planlama, personel güvenliği, risk değerlendirmesi, sistem ve hizmet alımı, sistem ve iletişim koruması, sistem ve bilgi bütünlüğü.**

Bu son grubun slaytı ekranda okunabilmektedir (ekrandan, 01:00:00):

- **Medya koruması:** (i) hem kağıt hem dijital bilgi sistemi ortamını korumak; (ii) bilgi sistemi medyasındaki bilgilere erişimi yetkili kullanıcılarla sınırlandırmak; (iii) elden çıkarmadan ya da yeniden kullanım için serbest bırakmadan önce bilgi sistemi ortamını sterilize etmek ya da imha etmek.
- **Fiziksel ve çevresel koruma:** (i) bilgi sistemlerine, ekipmana ve ilgili işletim ortamlarına fiziksel erişimi yetkili kişilerle sınırlandırmak; (ii) fiziksel tesisi korumak ve bilgi sistemleri için altyapıyı desteklemek; (iii) bilgi sistemleri için destekleyici hizmetler sağlamak; (iv) bilgi sistemlerini çevresel tehlikelere karşı korumak; (v) bilgi sistemleri içeren tesislerde uygun çevresel kontrolleri sağlamak.
- **Planlama:** bilgi sistemleri için mevcut ya da planlanan güvenlik kontrollerini ve bilgi sistemlerine erişen bireylerin davranış kurallarını tanımlayan güvenlik planları geliştirmek, belgelemek, periyodik olarak güncellemek ve uygulamak.
- **Personel güvenliği:** (i) kuruluşlar içinde (üçüncü şahıs hizmet sağlayıcılar dahil) sorumlu pozisyonlarda bulunan kişilerin güvenilir olduğundan ve bu pozisyonlar için belirlenmiş güvenlik kriterlerini karşıladığından emin olmak; (ii) işten çıkarmalar ve transferler gibi personel eylemleri sırasında ve sonrasında kurumsal bilgi ve bilgi sistemlerinin korunmasını sağlamak; (iii) kurumsal güvenlik politikalarına ve prosedürlerine uymayan personel için resmi yaptırımlar uygulamak.
- **Risk değerlendirmesi:** organizasyonel bilgi sistemlerinin işleyişinden ve organizasyonel bilgilerin işlenmesi, depolanması ya da iletilmesinden kaynaklanan, organizasyonel operasyonlara (misyon, işlevler, imaj ya da itibar dahil), organizasyonel varlıklara ve bireylere yönelik riski periyodik olarak değerlendirmek.
- **Sistem ve hizmet alımı:** (i) kurumsal bilgi sistemlerini yeterince korumak için yeterli kaynakları tahsis etmek; (ii) bilgi güvenliği hususlarını içeren sistem geliştirme yaşam döngüsü süreçlerini kullanmak; (iii) yazılım kullanımı ve kurulum kısıtlamaları uygulamak; (iv) üçüncü taraf sağlayıcıların, kuruluştan sağlanan bilgileri, uygulamaları ve/veya hizmetleri korumak için yeterli güvenlik önlemleri almasını sağlamak.
- **Sistem ve iletişim koruması:** (i) bilgi sistemlerinin dış sınırlarında ve temel iç sınırlarında kurumsal iletişimleri izlemek, kontrol etmek ve korumak; (ii) kurumsal bilgi sistemlerinde etkin bilgi güvenliğini destekleyen mimari tasarımları, yazılım geliştirme tekniklerini ve sistem mühendisliği ilkelerini kullanmak.
- **Sistem ve bilgi bütünlüğü:** (i) bilgi ve bilgi sistemi kusurlarını zamanında tespit etmek, raporlamak ve düzeltmek; (ii) kurumsal bilgi sistemleri içinde uygun yerlerde kötü amaçlı kodlara karşı koruma sağlamak; (iii) bilgi sistemi güvenlik uyarılarını ve tavsiyelerini izlemek ve yanıt olarak uygun önlemleri almak.

<!-- BELİRSİZ: FIPS 200 slaytının ilk sayfası (1/2) karelerde görülmedi; erişim kontrolünden bakıma kadar olan maddeler altyazıdan alındı. -->

Hoca sistem ve hizmet alımına değinirken, bir konu kurumun kendi uzmanlık alanı değilse dışarıdan hizmet alınabileceğini, ancak bunun da güvenlik gereksinimlerine tabi olduğunu belirtti.

## 11. Temel güvenlik tasarım ilkeleri

Hoca temel güvenlik tasarım ilkelerini altyazıda şu sırayla saydı:

- **Mekanizma ekonomisi:** hoca bunu "minimum maliyetle maksimum güvenlik" diye açıkladı.
- **Güvenli varsayılanlar (fail-safe defaults):** herhangi bir arıza durumunda güvenli varsayılan değerlere dönülmesi.
- **Açık tasarım:** tasarımın açık olması ki hatalar kolaylıkla bulunabilsin.
- **Ayrıcalıkların ayrılması.**
- **En az ayrıcalık:** kişilere yalnız işini görecek kadar yetki verilmesi.
- **En az ortak mekanizma:** kişiye ve sisteme özel mekanizmaların oluşturulması.
- **Psikolojik kabul edilebilirlik.**
- **İzolasyon:** saldırı durumunda yalnız belli bir bölgenin etkilenmesi.
- **Modülerlik.**
- **Katmanlama:** bir katmandaki iyileştirmelerin ve sorunların diğer katmanları etkilememesi.
- **En az şaşırtma:** hocanın ifadesiyle güvenlikteki amaç insanları şaşırtmak değildir.

<!-- BELİRSİZ: ilkelerin slaytı karelerde görülmedi; "ayrıcalıkların ayrılması" altyazıda bozuk ("yetkili kullanıcıların aylıklaştırılması"), "en az şaşırtma" ise "milleti şaşırtmak değil" ifadesinden çıkarıldı. -->

> **Ders sonrası not:** Hoca mekanizma ekonomisini "minimum maliyetle maksimum güvenlik" diye açıkladı. Kaynak kitapta bu ilke büyük olasılıkla, donanım ve yazılımdaki güvenlik önlemlerinin tasarımının olabildiğince basit ve küçük tutulması anlamındadır; basit tasarım daha kolay test edilir ve daha az açık barındırır.

## 12. Saldırı yüzeyleri ve derinlemesine savunma

Hoca bu bölümde "masanın öbür tarafına geçerek" saldırgan bakış açısını ele aldı. **Saldırı yüzeyi**, bir sistemdeki erişilebilir ve istismar edilebilir güvenlik açıklarından oluşur: saldırgan nereden açık bulacak, nasıl saldıracak? Hocanın örnekleri şunlardır:

- Dışa bakan web ve diğer sunucuların unutulmuş, kullanılmayan, kontrol edilmeyen açık portları ya da kullanılan portları dinleyen yazılımların açıkları.
- Kullanılmayan servisler: güvenlik duvarının görevi güvenlik duvarlığı yapmaktır; üzerine e-posta sunucusu gibi başka servisler eklenirse bunlar saldırı yüzeyini büyütür.
- Gelen veriyi, e-postaları, ofis belgelerini işleyen kod.
- Dışarıdan veri kabul eden program arayüzleri ve web formları; örneğin SQL enjeksiyonu ve XSS saldırıları.
- Sosyal mühendislik: içeriden birinden geliyormuş gibi e-posta atıp hassas bilgiyi vermesini sağlamak ya da bir resim veya arkadaştan gelen bir dosya gibi görünen bir ekle casus yazılımı içeri sokmak.

Saldırı yüzeyleri üç kategoride toplanır:

- **Ağ saldırı yüzeyi:** kurumsal ağ, geniş alan ağı ya da internet üzerindeki açıklar. Bu yüzey üzerinden hizmet reddi saldırıları, iletişim bağlantılarının bozulması ve ağ protokollerini kullanarak sisteme girme gibi saldırılar yapılır.
- **Yazılım saldırı yüzeyi:** uygulama, yardımcı program ya da işletim sistemi kodundaki açıklar; burada özellikle dışa açık web sunucusu yazılımı odak noktasıdır.
- **İnsan saldırı yüzeyi:** sosyal mühendislik, insan hatası ve içeriden güvenilir kişilerin (personel ya da dışarıdan kişiler) oluşturduğu açıklar.

### 12.1 Derinlemesine savunma ve saldırı yüzeyi

Ekrandaki şekil "Figure 1.4 Defense in Depth and Attack Surface" başlıklıdır (ekrandan, 01:05:00). Dikey eksen katmanlamadır (Layering: aşağıda Deep, yukarıda Shallow), yatay eksen saldırı yüzeyidir (Attack Surface: Small, Large). Dört hücre şöyledir:

| Katmanlama \ Saldırı yüzeyi | Küçük (Small) | Büyük (Large) |
|---|---|---|
| Sığ (Shallow) | Orta güvenlik riski | Yüksek güvenlik riski |
| Derin (Deep) | Düşük güvenlik riski | Orta güvenlik riski |

Hoca şekli şöyle yorumladı: saldırgan ağı, programı ve sosyal mühendisliği birlikte kullanabildikçe saldırı yüzeyi genişler ve sistemi ele geçirme ihtimali, yani risk artar. Katmanlama ise her katmanda izolasyon sağlayıp etkiyi sınırlı tuttuğu için riski azaltır. Sonuç olarak katmanlamanın derin olması riski azaltır, sığ olması artırır; saldırı yüzeyinin küçük olması saldırının başarısını düşürür, geniş olması artırır.

## 13. Güvenlik stratejisi ve standartlar

Hoca güvenlik stratejisini dört kavramla anlattı:

- **Güvenlik politikası:** bir sistemin ya da kuruluşun hassas ve kritik sistem kaynaklarını korumak için güvenlik hizmetlerini nasıl sağladığını belirten ya da düzenleyen resmi kurallar ve uygulamalar.
- **Güvenlik uygulaması:** temel amacı önleme, tespit etme, tepki verme ve saldırıdan sonra sistemi kurtarmadır.
- **Güvence:** hem sistem tasarımını hem sistem uygulamasını kapsayan, sistemin güvenlik politikalarına uygun çalıştığına dair güvene sahip olmak için zemin sağlayan, bilgi sisteminin bir özelliği. Hoca bunu şu sorularla bağladı: ne kadar güvenli olmalı, ne kadarlık risk tolere edilebilir, ne kadarlık risk başkasına devredilir, ne kadarlık risk için güvence seviyesine yatırım yapılır?
- **Değerlendirme:** bir bilgisayar ürününü ya da sistemini belirli kriterlere göre inceleme süreci.

Güvenlikle ilgili belge ve standartların başlıca kaynakları şunlardır:

- **NIST (National Institute of Standards and Technology):** ABD merkezli, ABD özel sektör inovasyonunu teşvik etmek için standart geliştiren kurum. Hoca önce "Science" dedi, sonra adı "Standards and Technology" diye düzeltti.
- **ISOC (Internet Society):** internetin geleceğiyle ilgili konuların ele alındığı ve standartların oluşturulduğu bir topluluk.
- **ITU-T (International Telecommunication Union):** hükümetlerin ve özel sektörün küresel telekomünikasyon ağlarını ve hizmetlerini koordine ettiği bir Birleşmiş Milletler kuruluşu ve onun yayımladığı standartlar.
- **ISO (International Organization for Standardization):** çalışmaları uluslararası standartlar olarak yayımlanan ve uluslararası anlaşmalarla sonuçlanan bir sivil toplum kuruluşu.

> **Ek bilgi (derste anlatılmadı):** ISO'nun resmi İngilizce adı "International Organization for Standardization"dır; derste "International Standard Organization" diye geçti. ITU-T kısaltmasındaki "T", birliğin telekomünikasyon standardizasyonu sektörünü gösterir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:42:53): Bir güvenlik açığı sonucunda veri bozulursa CIA üçlüsünden hangi özellik kaybedilir? Veri iletilirken sızarsa ya da hizmet saldırgan tarafından yavaşlatılırsa ne kaybedilir?

> **Çözüm (derste verildi):** Veri bozulursa bütünlük, veri sızarsa gizlilik, veriye ulaşım engellenir ya da hizmet yavaşlatılırsa kullanılabilirlik kaybedilir. Bu, slayttaki bozuk/sızdıran/kullanılamaz açık kategorilerine karşılık gelir (ekrandan, 00:45:00).

**Soru 2** (derste sözlü, 00:41:42): Bir bilişim sistemi açısından baktığımızda "varlık" (asset) nedir?

> **Çözüm (derste verildi):** Donanım (bilgisayar, veri işleme ve depolama sistemleri, iletişim cihazları), yazılım (işletim sistemi, yardımcı programlar, uygulamalar), veri (tablolar, dosyalar, patent bilgileri vb.) ve iletişim hatları ile ağlar (yerel ve geniş alan ağları, köprüler, yönlendiriciler, anahtarlar).

**Soru 3** (derste sözlü, 00:48:15): Müdahale ile izinsiz giriş arasındaki fark nedir?

> **Çözüm (derste verildi):** Müdahalede yetkisiz varlık, yetkili kaynak ile hedef arasında aktarılan veriyi aktarım sırasında ele geçirir. İzinsiz girişte ise yetkisiz varlık, sistemin güvenlik korumalarını atlayarak doğrudan sisteme girer ve hassas verilere erişir (ekrandan, 00:50:00).

**Soru 4** (derste sözlü, 00:32:12): Kullanıcı bilgisi tutan bir web sitesinde (a) anket verileri, (b) kullanıcıların ad, adres ve sepet içerikleri, (c) hesap ve ödeme bilgileri sızarsa etki düzeyi nedir?

> **Çözüm (derste verildi):** (a) düşük, (b) orta, (c) yüksek.

## Dersin Toparlaması

Bu giriş dersinde bilgisayar güvenliğinin temel kavramsal çerçevesi kuruldu. Güvenlik, değerli bir varlığın tehditlere ve saldırılara karşı korunması olarak tanımlandı; bu korumanın hedefleri CIA üçlüsü (gizlilik, bütünlük, kullanılabilirlik) ve buna eklenen özgünlük ve hesap verebilirlikle güvenlik beşgeni olarak verildi. Bir zafiyetin etkisinin düşük, orta ve yüksek diye bir referansa göre seviyelendirilmesi, güvenliğin neden zor olduğu ve neden tasarımın başından itibaren düşünülüp sürekli izlenmesi gerektiği tartışıldı.

Ardından RFC 2828 ve RFC 4949'a dayanan terminoloji, varlık sahibi ile saldırgan arasındaki tehdit-önlem döngüsü, açık kategorileri, pasif ve aktif saldırılar, tehdit sonuçları ve eylemleri, FIPS 200 güvenlik gereksinimleri, temel tasarım ilkeleri, saldırı yüzeyi ile derinlemesine savunma ilişkisi ve güvenlik stratejisi ile standart kuruluşları ele alındı. Müfredata göre sonraki haftalarda bu çerçeve üzerine güvenliğin yönetimsel boyutu (risk değerlendirmesi, kontroller, fiziksel ve insan kaynakları güvenliği, denetim, yasal ve etik hususlar) kurulacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
