# Ders 2 Genişletilmiş Notu: Bilgi Sistemi Tipleri, Sistem Geliştirme Yaşam Döngüsü ve Sistem Analisti

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Sistem örnekleri üzerinden sistem kavramının tekrarı
- 2. Sistem analizi, sistem tasarımı ve sistem analisti
- 3. Bilgi sistemi tipleri
- 4. Sistem geliştirme ve sistem geliştirme yaşam döngüsü (SDLC)
- 5. Analiz ve tasarım neden önemli: ağaç salıncağı örneği
- 6. Bilgi sistemi tarafları
- 7. Sistem analistinin gerekli yetenekleri
- 8. Örnek Sorular

## 1. Sistem örnekleri üzerinden sistem kavramının tekrarı

Önceki derste sistemin tanımı ve öğeleri (elemanlar, elemanlar arası ilişkiler, sınır, çevre, girdi, çıktı, geri besleme, hedef) üniversite örneği üzerinden anlatılmıştı. Bu derse, öğrencilerden çevrelerinde gördükleri bir sistemi bu öğelere göre tanımlamaları istenerek başlandı. Hocanın amacı sistem kavramının oturması ve öğrencilerin etraflarına bakıp sistem örnekleri seçebilmesiydi.

### 1.1 Araba kiralama sistemi

Bir öğrenci araba kiralama sistemini alt sistemleri üzerinden anlattı:

- Rezervasyon ekibi: müşterinin rezervasyon için ilk ulaştığı birim.
- Satış ve kiralama ekibi: ödemeyi, rezervasyonu ve faturayı düzenler.
- Envanter kontrol ekibi: istenen aracın envanterde olup olmadığını kontrol eder.
- Müşteri bilgilendirme ekibi: aracın olup olmadığını müşteriye bildirir.
- Ödeme kontrol ekibi: ödemeyi doğrular.
- Sipariş oluşturma ekibi: bütün kontrolleri tamamlar ve müşteriyi en son bilgilendirir.

Girdiler kiralama isteği, ödeme ve rezervasyon; çıktılar fatura, araç, stok bilgisi ve müşteriye verilen son geri bildirimdi. Hoca alt sistemlerin ve aralarındaki ilişkilerin sayılmasını yerinde buldu, ancak üniversite örneğinde yapıldığı gibi sistemin sınırının ve çevresinin de açıkça belirtilmesi gerektiğini hatırlattı: "elemanları şunlardır, sınırı budur, çevresinde şunlar vardır" biçiminde bir tanıtım ve bir geri besleme olup olmadığının sorgulanması beklenir.

### 1.2 Motor kontrol sistemi

İkinci örnek, yakıtı güce çeviren motor sistemi ve onu yöneten elektronik kontrol ünitesiydi (ECU). Ekranda paylaşılan çalışmada şu öğeler vardı (ekrandan, 00:10:00):

- Girdiler:
  - Hava sıcaklığı (air temperature)
  - Motor soğutma suyu sıcaklığı (coolant temperature)
  - Gaz kelebeği konumu (throttle position) ve manifold basıncı (manifold pressure): bu ikisi motor üzerindeki yükü belirler.
  - Motor devri (engine RPM): motorun ne kadar hızlı döndüğünü gösterir.
- Çıktılar:
  - Aracı çalıştıracak gücü sağlamak (provide power to run the car)
  - Rölanti devrini kontrol etmek (control the idle speed)
  - Aksesuarlar için güç (power for accessories), örneğin klima
- Varlıklar (entities): sensörler, hava, yakıt, motor.
- Elemanlar arası ilişki (interrelationship): look-up table.

ECU, sensörlerden aldığı veriyi içindeki arama tablolarına (look-up table) bakarak değerlendirir ve yakıt enjeksiyon sistemine gerekli karışım oranını, ateşleme sistemine de doğru ateşleme zamanını gönderir. Ekrandaki örnek tablo, bir ekseni devir (RPM, 0-7000), diğer ekseni gaz kelebeği konumu (0-0,8) olan ve bu ikisini yakıt karışımına eşleyen üç boyutlu bir yüzeydi ("RPM & Throttle Position mapped to Fuel Mixture"). Tablodaki değerler o araç için en verimli çalışmayı sağlayacak şekilde önceden deneyle bulunmuştur.

Hoca, tekerlekleri döndürecek torku üretmenin hem bir çıktı hem de sistemin amacı olarak görülebileceğini belirtti ve hedeflere "bunları mümkün olduğu kadar az yakıt harcayarak yapmak" maddesinin de eklenebileceğini söyledi. Öğrenci, vites sistemi gibi yakıt tüketimini çok etkileyen sistemlerin bu çalışmada ele alınmayan yan sistemler olduğunu ekledi.

### 1.3 Aile sistemi

Bir başka örnekte aile bir sistem olarak düşünüldü. Elemanlar bireyler (anne, baba, çocuk) ve konaklama yeri olan evdi. Elemanlar arası ilişkiler yazılı (kanunlar) ve yazılı olmayan (ahlaki) kurallar olarak ikiye ayrıldı. Girdi olarak çocuk, hedef ve çıktı olarak da kendisine ve dünyaya yararlı bireyler yetiştirmek düşünüldü. Öğrenci, aile üzerinde düşündükçe sistemin ilk göründüğünden daha karmaşık hale geldiğini belirtti.

### 1.4 Hastane sistemi

Hastane örneğinde elemanlar hastalar, doktorlar, hemşireler, teknisyenler, güvenlik görevlileri ve stajyerlerdi. Randevu, muayene, ameliyat, tahlil ve fizik tedavi sistemin işlevleri; MR ve röntgen gibi görüntüleme birimleri, laboratuvarlar, ilaç geliştirme laboratuvarları ve yönetim birimi alt sistemleriydi. Elemanlar arası ilişkiler, üniversitede olduğu gibi yönetmelik ve tüzüklerle sağlanır. Çıktılar iyileşmiş ya da bilgilendirilmiş hasta ve hastanede eğitim alıp mezun olan sağlık öğrencileriydi.

Hoca burada iki noktayı vurguladı. Birincisi, üniversite örneğinde de söylendiği gibi sistem yalnız canlı elemanlardan oluşmaz; canlıların işini yapabilmesi için kullanılan sınıflar, görüntüleme odaları gibi elemanlar da sistemin parçasıdır. İkincisi, hedef ölçülebilir biçimde yazılabilir: bir hastanenin amacı, belirli periyotlar içinde mümkün olan en fazla iyileşmiş hasta ve en az kayıp hasta çıkarmaktır.

### 1.5 Öğrenci kulübü sistemi

Bir öğrenci kulübü için çizilen şema şöyleydi (ekrandan, 00:15:00):

- Girdiler (sistem sınırının dışında): Öğrenciler, Üyelik Ücreti. Öğrenciler oku Üyelik Ücreti'ne gider.
- Sistem sınırı içindeki elemanlar: Üyeler, Kulüp Yönetim Kurulu, Kulüp Bütçesi.
- Oklar (ilişkiler):
  - Öğrenciler → Üyeler; Üyelik Ücreti → Kulüp Bütçesi.
  - Üyeler → Kulüp Yönetim Kurulu.
  - Üyeler → Etkinlikler ve Üyeler → Eğitimler (katılım).
  - Kulüp Yönetim Kurulu → Etkinlikler ve → Eğitimler (düzenleme).
  - Kulüp Bütçesi ↔ Etkinlikler ve ↔ Eğitimler (bütçe destekler, etkinlikler bütçeye katkı sağlar).
  - Üyeler, Etkinlikler ve Eğitimler → Geri Bildirim → (Geri Besleme) → Kulüp Yönetim Kurulu.
- Çıktılar: Etkinlikler, Eğitimler.

Öğrenciler kulübe üye olur; üyeler zamanla yönetim kuruluna geçebilir. Üyelik ücreti kulüp bütçesini oluşturur; bütçe etkinlik ve eğitimleri destekler, etkinlik ve eğitimler de bütçeye katkı sağlayabilir. Yönetim kurulu etkinlik ve eğitimleri düzenler (tek yönlü ilişki), üyeler bunlara katılır. Üyelerden ve etkinliklerden alınan geri bildirim, geri besleme olarak yönetim kuruluna döner; yönetim de etkinlikleri ve eğitimleri iyileştirir. İç ilişkiler kulüp tüzüklerine göre belirlenir.

Hoca geri beslemeyi şöyle somutlaştırdı: dönemsel toplantılar ya da üyeler üzerinde anketler yapılarak değerlendirme yapılır; bunun sonucuna göre üyelik kabulü değiştirilebilir, genel tüzük dışında kalan kendi kurallar değiştirilebilir, yapılan işlere yenileri eklenebilir.

### 1.6 Doğadaki besin zinciri

Besin zinciri örneğinde sistemin sınırı hayvanların yaşadığı çevre, amacı doğal döngünün sürmesi ve hayatta kalmaktı. Elemanlar arası ilişki yeme-yenilme; girdi, onlar olmadan sistemin sürmeyeceği üreticilerdi. Geri besleme olarak bir türün sayısındaki artışın diğerini etkilemesi verildi (örneğin karga sayısının artmasıyla çekirge sayısının azalması). Hoca insanın bu düzende yer alıp almadığını sordu; neredeyse her şeyi yiyebildiği için zincire konmadığı cevabı verildi. Hoca, sisteme dışarıdan pek kimsenin karışamayacağını ama insanın koyduğu avlanma yasakları gibi düzenlemelerin bir tür geri besleme ya da müdahale olarak düşünülebileceğini ekledi.

### 1.7 Otomobil

Son örnekte otomobilin geneli ele alındı: girdi petrol ya da elektrikli araçlarda elektrik, çıktı hareket enerjisi ve egzozdan çıkan gazlar, amaç aracın hareket etmesi ve taşımanın sağlanması.

## 2. Sistem analizi, sistem tasarımı ve sistem analisti

Örneklerden sonra ders planına dönüldü. Önceki hafta sistem analizinin ne olduğu, başka bölümlerdeki benzer derslerden farkı ve sistem tanımı işlenmişti. Bu hafta sistem tipleri, bilgi sistemi tarafları ve sistem geliştirme süreci ele alındı. Dersin çerçevesinde sistem geliştirme süreci, bir bilgi sisteminin (yazılım sisteminin) geliştirme sürecidir; bu süreç yazılım mühendisliğinde daha ayrıntılı modellerle anlatılır.

Sistem analizi ve tasarımında önce analiz, sonra tasarım yapılır, ardından sistem oluşturulur. Slayttaki tanımlar şöyledir (ekrandan, 00:25:00):

- **Sistem analizi (System Analysis):** bilgi sisteminin ne yapması gerektiğini anlama ve ayrıntılı olarak belirleme süreci. Kısacası kurulacak sistemin gerçekte ne yaptığını doğru anlamak; doğru anlarsak sistemi doğru kurarız.
- **Sistem tasarımı (System Design):** bilgi sisteminin birçok bileşeninin nasıl gerçekleştirileceğini ayrıntılı olarak belirleme süreci. Parçaları nasıl belirlersek ve nasıl gerçekleştirirsek daha başarılı olacağını tasarlamak.
- **Sistem analisti (System Analyst):** analiz ve tasarım tekniklerini kullanarak (bilgi teknolojisi içeren) iş problemlerini çözen uzman. Hoca, derste daha çok işletmecilik problemlerine çözüm arandığını, ancak analistin mühendislik ve teknik problemler dahil her türlü problem için çalışabileceğini belirtti.

Analistin işi şöyle özetlendi: bir işi kolaylaştıracak bir bilgi sistemi yaratılmak isteniyor. Önce analiz aşamasında bu işin gerçek hayatta ne yaptığı ve nasıl çalıştığı anlaşılır. Tasarım aşamasında bu işi çözecek yazılım ve bütün bilgi sistemi için tasarımlar yapılır: önce işin modeli kurulur, bu model üzerinde denemeler yapılarak gerçek çalışan yazılımın nasıl üretileceğine karar verilir. Büyük ve kurumsal firmalarda bu görevler uzmanlaşır; sistem analistinin yanında yazılım mimarları, veri tabanı tasarımcıları ve ağ tasarımcıları da yer alır.

> **Hocanın vurgusu:** Dersin ana teması, etkin bir bilgi sistemi geliştirmenin yalnızca bilgisayar programı yazmaktan çok daha fazlası olduğudur. Problemi doğru anlamak, bilgisayar teknolojisini bilmek ve teknolojinin probleme nerede "oturduğunu" görüp ikisini birbirine uydurmak gerekir (slaytta: "involves cognitive skills in understanding problems and knowing where computer technology best fits in").

### 2.1 "Sistem" gibi düşünmek

Önceki derste sistem özellikleri, süper sistem ve alt sistemler gibi bir sistem ortamının yapısı görülmüştü. Bunun özeti olarak gösterilen slayt, sistem düşüncesinin bileşenlerini sıralar (ekrandan, 00:30:00):

- Bir şeyi sistem olarak tanıyabilmek
- Alt sistemlerini belirleyebilmek
- Sistemin özelliklerini ve işlevlerini belirleyebilmek
- Sınırların nerede olduğunu (ya da olması gerektiğini) belirleyebilmek
- Sistemin girdi ve çıktılarını belirleyebilmek
- Alt sistemler arasındaki ilişkileri belirleyebilmek

Bir sistemin çevresiyle arasında sınırları vardır. Sistemdeki rutin işlerin daha hızlı ve daha doğru yapılmasını sağlayan kısım ise bilgi sistemidir. Sıradaki soru, kurumlarda bilgi sistemlerinin hangi tiplerde görüldüğüdür.

## 3. Bilgi sistemi tipleri

### 3.1 İşlemsel bilgi sistemleri (TPS)

En temel, en alt seviyedeki tip **Transaction Processing System**, Türkçesiyle işlemsel bilgi sistemidir. Kurumu etkileyen işlemlerle ilgili bilgiyi yakalar, toplar, kaydeder ve üzerinde işlem yapar (ekrandan, 00:40:00; slayttaki örnekler: bir ürünün satışı, ATM'den para çekme). Derste verilen örnekler ATM'den para çekme, bordro hazırlanması ve muhasebe fişi hazırlanmasıdır; bunların her biri ayrı bir işlemsel bilgi sistemidir. Örneğin bordro sistemi, bir kurumda çalışanların aylık maaşını her ay, çok sayıda kişi ve kayıt için hesaplar.

TPS, günlük hayattaki rutin işleri daha hızlı, daha güvenli ve daha hatasız yapabilmek için, tek bir işlemi gerçekleştirmeye yönelik sistemlerdir.

### 3.2 Yönetim bilgi sistemleri (MIS)

**Management Information System**, işlemsel bilgi sistemlerinin topladığı bilgiyi alır ve yönetimin işi planlamak ve kontrol etmek için ihtiyaç duyduğu raporları üretir (ekrandan, 00:40:00). Hedefi, kurumun iş süreçlerini daha iyi planlaması ve kontrol etmesidir. Bu yüzden bütün firmayı toparlaması gerekir: aynı veri havuzundan ya da birbiriyle uyumlu veri tabanlarından bilgi alarak yönetime raporlar ve bütün yönetim kademelerinin daha iyi planlama, kontrol ve izleme yapmasını sağlar.

MIS'te de veri tabanı kullanılır ve çıktılar, raporlar genellikle önceden tanımlanmış sorgulara cevap verir; yani müşteri hangi raporları isteyeceğini sistem kurulurken baştan belirtir. Hoca TPS ile MIS arasındaki farkı bordro örneğiyle açıkladı:

- TPS düzeyinde: her ay maaş bordrolarının çıkarılması ve bu raporların yönetime gönderilmesi istenir.
- MIS düzeyinde: yönetici her ayın ayrıntı raporunu değil, çalışanların maaşlarının departmanlara göre dökümünü ister. Daha ileri bir örnekte maaş verisinden yalnızca satış temsilcileri ayrılır, onların hangi satışları yaptığı ve bu satışlardan şirketin ne kadar kâr sağladığı çıkarılır. Böylece bordro programından satış ve müşteri ilişkileri verisine geçilmiş olur. Yöneticilere karşılaştırmalı bir liste gider ve karar vermede kullanılır; ama böyle bir liste isteneceği, bilgi sistemi kurulurken önceden belirtilmiştir.

TPS'lerin bir arada toplandığı ve birleşerek yönetime daha doğru, daha akılcı kararlar verdirdiği yapı MIS'tir.

### 3.3 Üst yönetim bilgi sistemleri (EIS)

**Executive Information Systems**, üst yöneticilere stratejik planlamada kullanacakları bilgiyi sağlar; bu bilgi kurumsal veri tabanından ya da borsa raporları gibi dış kaynaklardan gelebilir (ekrandan, 00:35:00). Üst yönetimin hızlı ve anlık sorularına cevap verecek şekilde bilgiye erişmesini sağlar.

Burada önemli olan, üst yöneticinin araya bir aracı koymadan, kendisi bilgisayara baktığında anlık sorularına cevap alabilmesidir. Bu yüzden EIS daha esnek olmalı, önceden tanımlanmamış sorulara da cevap verebilmelidir. Bu da altta kullanılan veri tabanının arşiv verisini de tutan, daha ayrıntılı bir veri ambarı biçiminde olmasını ve ileride veri madenciliği dersinde görülecek türden esnek sorgulamalara cevap verebilmesini gerektirir.

> **Ek bilgi (derste anlatılmadı):** Veri ambarı (data warehouse), işlemsel veri tabanlarından gelen verilerin geçmişiyle birlikte, analiz ve raporlama amacıyla bir araya getirildiği veri deposudur. İşlemsel veri tabanı güncel işlemlere, veri ambarı ise zaman içindeki eğilimleri sorgulamaya göre düzenlenir.

### 3.4 Karar destek sistemleri (DSS)

**Decision Support Systems**, insanın karar vermesini destekler ve kullanıcının mevcut seçeneklerin ya da kararların olası etkisini incelemesine izin verir; örneğin "what if" (ne olur?) sorusu sorulabilir (ekrandan, 00:35:00). Slayta göre uzman sistemlerle (expert systems) ve bilgi tabanlı sistemlerle (knowledge-based systems) yakından ilişkilidir. Derste en çok what if analizleri ve goal seeking (hedef arama) analizleri anılmıştır.

Karar destek sistemlerinin perspektifi çok geniştir: bir Excel tablosunda what if senaryosuyla bir karar mekanizmasını işletmek de, büyük veri üzerinde bir uzman sistem kurmak da karar destek sistemidir. DSS'yi yöneticiler doğrudan ya da yardımcı danışmanları aracılığıyla kullanabilir.

> **Ek bilgi (derste anlatılmadı):** What if analizinde bir ya da birkaç girdi değiştirilip sonucun nasıl değiştiği izlenir. Goal seeking bunun tersidir: istenen sonuç (hedef) verilir ve bu sonuca ulaşmak için bir girdinin hangi değeri alması gerektiği bulunur. İkisi de elektronik tablo programlarında hazır araç olarak bulunur.

Hoca, bu sistemlerin hangi tip veriyi kullandığı, kimin kullandığı, hangi araçlarla ve hangi hedeflerle çalıştığı açısından aralarındaki farklılık ve benzerliklere, örnekler arttıkça daha sonra döneceklerini belirtti.

## 4. Sistem geliştirme ve sistem geliştirme yaşam döngüsü (SDLC)

### 4.1 Proje ve bilgi sistemi geliştirme projesi

Slayttaki tanımlar şöyledir (ekrandan, 00:50:00):

- **Proje:** başlangıcı ve sonu olan, önceden belirlenmiş bir sonuç ya da ürün üreten planlı çalışma.
- **Bilgi sistemi geliştirme projesi:** bir sistem üreten planlı çalışma.
- **Yeni bir sistemin geliştirilmesindeki temel etkinlikler:**
  - Analiz: bilgi ihtiyaçlarını anlamak.
  - Tasarım: ihtiyaçlara dayanarak sistem mimarisini tanımlamak.
  - Gerçekleme (implementation): sistemin fiilen kurulması, yani bilgi sisteminin ya da yazılım sisteminin gerçek halinin oluşturulması.

Bir bilgi sistemi geliştirme projesindeki bu etkinliklerin bütününe sistem geliştirme yaşam döngüsü denir. Sistem geliştirme yaşam döngüsü, yeni bir bilgi sistemini geliştirme sürecini tanımlamak için kullanılan genel bir terimdir; geliştirmenin hangi yapıda, hangi yöntemlerle ve hangi kontrollerle yürütüleceğini belirler.

> **Ders sonrası not:** Hoca kısaltmayı "Software Development Life Cycle" diye açtı; slaytlardaki başlık "System Development Life Cycle (SDLC)" biçimindedir (ekrandan, 00:45:00). Hocanın da sonra belirttiği gibi, bu derste döngü yalnız yazılımı değil bütün bilgi sistemini kapsadığı için "sistem (bilgi sistemi) geliştirme yaşam döngüsü" adı daha uygundur.

### 4.2 SDLC'nin aşamaları

Birbiriyle ilişkili etkinlikler aşamalar (phases) halinde düzenlenir (ekrandan, 00:45:00):

1. Proje planlama aşaması (project planning phase)
2. Analiz aşaması (analysis phase)
3. Tasarım aşaması (design phase)
4. Gerçekleme aşaması (implementation phase)
5. Destek aşaması (support phase)

Slayta göre "klasik" yaşam döngüsünde bu aşamalar sıralıdır, ama ileride görüleceği gibi farklı varyasyonları da vardır. Hoca, bu haftaki konuyu şelale (waterfall) modeline göre tanımladıklarını söyledi: proje planlama, analiz, tasarım, gerçekleme ve destek aşamalarından biri bittiğinde diğeri başlar.

### 4.3 Planlama aşaması

Planlama aşamasının etkinlikleri (ekrandan, 01:00:00):

- Problemi ve kapsamını tanımlamak: neyin sistemi kurulacak?
- Proje fizibilitesini doğrulamak.
- Proje takvimini, yani hangi işlerin yapılacağını gösteren iş listesini çıkarmak.
- Projeye personel atamak: projede kimler çalışacak?
- Projeyi başlatmak.

Kapsam tanımlanıp fizibilite çalışması yapıldıktan sonra plan gözden geçirilir; onaylanırsa proje başlatılır. Ön inceleme ve fizibilite analizinin ayrıntıları sonraki derse bırakıldı.

### 4.4 Analiz aşaması

Analiz aşamasının temel hedefi, yeni sistemin bilgi gereksinimlerini ve işlem gereksinimlerini anlamak ve belgelemektir. Hoca bunu hastane bilgi sistemi örneğiyle açıkladı: hastalardan hangi bilgiler alınıyor, hastalara hangi raporlar veriliyor, hangi işlemler gerçekleşiyor? Hasta gelir, randevu alır, kaydolur, istediği doktora gider; analizin hedefi bu işleyişi anlamaktır.

Analiz aşamasında yapılanlar:

- Görüşmeler ve gözlemlerle bilgi toplamak.
- Sistem gereksinimlerini tanımlamak ve diyagramlarla modellemek.
- Gereksinimleri keşfetmek için prototip hazırlamak.
- Gereksinimleri müşterilerden almak ve önceliklendirmek.
- Çözüm seçenekleri üretmek ve değerlendirmek.

<!-- BELİRSİZ: Analiz, tasarım ve gerçekleme aşamalarının slaytları karelerde yalnız küçük önizleme olarak görünüyor; bu üç aşamanın maddeleri altyazıdan kurulmuştur. -->

### 4.5 Tasarım aşaması

Tasarım aşamasının hedefi çözümün tasarlanmasıdır. Bu gerçekleme değildir: programın yazılması değil, programın nasıl yazılacağının tasarlanmasıdır. Tasarımda yapılanlar:

- Uygulamalar arasında nasıl bir ağ kurulacağını ve sistemin ağla nasıl bütünleşeceğini tasarlamak.
- Kullanıcı ara birimlerini, yani ekran yapılarını tasarlamak.
- Sistem ara birimlerini tasarlamak.
- Veri tabanı yapısını tasarlamak.
- Tasarım ayrıntıları için bir prototip yapmak.
- Sistem kontrollerini tanımlamak.

### 4.6 Gerçekleme aşaması

Gerçekleme (implementation) aşamasında gerçek program yazılır, doğru çalışıp çalışmadığı test edilir ve sistem kurulur. Bu aşamada yazılım bileşenleri oluşturulur, testler hazırlanır ve uygulanır, prototiplerle uyumluluk sağlanır, veri dönüşümü yapılır, kullanıcı belgeleri hazırlanır, kullanıcılara eğitim verilir ve sistemin kurulumu yapılır.

### 4.7 Destek aşaması

Destek aşamasının hedefi, bilgi sistemini kurulduktan sonra çalışır durumda tutmaktır (ekrandan, 01:05:00). Etkinlikler:

- Son kullanıcılara destek sağlamak:
  - Yardım masaları (help desks)
  - Eğitim programları
- Bilgisayar sistemini bakımını yapmak ve zenginleştirmek:
  - Basit program hatalarını düzeltmek
  - Kapsamlı iyileştirmeler
  - Sürüm yükseltmeleri (upgrades)

Ders sırasında aşamaların hızlı geçildiği düşünülerek öğrencilerin isteğiyle beş aşama baştan kısaca tekrar edildi: planlamada ön inceleme ve fizibilite; analizde yeni sistemin bilgi ve işlem gereksinimlerini anlayıp belgelemek; tasarımda ağ, ara birimler, veri tabanı ve prototip; gerçeklemede tasarlanan yapının kurulması; destekte eğitim, yardım mekanizmaları ve hata düzeltme.

## 5. Analiz ve tasarım neden önemli: ağaç salıncağı örneği

Sistem analizi bilgi sisteminin ne olduğunu anlamak, sistem tasarımı da gerçekleştirilecek bilgi sisteminin bütün parçalarının nasıl hazırlanacağını belirlemektir. Bu aşamalar iyi yapılmadan bir sistem geliştirilirse ortaya çıkan yazılım da hatalı olur. Hoca bunu, slaytlardaki ünlü ağaç salıncağı karikatürüyle gösterdi (ekrandan, 01:20:00). Slaytların alt yazıları şöyledir:

- "How the customer explained it" (müşterinin anlattığı)
- "How the project leader understood it" (proje liderinin anladığı)
- "How the analyst designed it" (analistin tasarladığı)
- "How the programmer wrote it" (programcının yazdığı): karede ağacın gövdesine bağlanmış, dallardan sarkmayan ve sallanamayan bir salıncak görünüyor.
- Sonraki slaytta salıncağın hiç görünmediği bir resim var; altyazısı karede net okunmuyor. <!-- BELİRSİZ: altıncı slaytın alt yazısı okunamadı; hocanın anlatımına göre belgelemeyle ilgili. -->

Bu zincirde müşteri işini doğru anlatmalı, proje yöneticisi projeyi doğru anlamalı, analist anlatılan işi doğru tasarlamalı, programcı da tasarımdaki işleri sağlayacak şekilde programı yazmalıdır. Örnekte müşteri isteğini o kadar ayrıntılı anlatır ki istek tamamen yanlış anlaşılır; proje lideri bunu biraz toparlasa bile analist tamamen hatalı tasarlayabilir, programcı da ondan daha hatalı yapabilir. Oysa müşterinin gerçekte istediği, çocukların sallanacağı basit bir salıncaktır.

Belgeleme de bu örneğin parçasıdır. Analizin ve tasarımın nasıl yapıldığı belgelenmemiş ve kullanıcılara doğru bir yönerge verilmemişse, o projede hiçbir iş yapılmamış sayılır; sonradan değişiklik ve bakım yapmak çok güçleşir, düzeltmelerin nasıl yapılacağı ve müşterinin gerçekte ne istediği anlaşılamayabilir.

> **Hocanın vurgusu:** Bunların doğru yapılması için analiz ve tasarımın bütün kademelerinde çalışan kişilerin birbiriyle ve özellikle müşteriyle koordineli bir iletişim içinde çalışması gerekir.

## 6. Bilgi sistemi tarafları

Bilgi sistemi tarafları, bilgi sistemi geliştirilirken rol alan kişilerdir. Küçük projelerde bu roller aynı kişilerde toplanabilir; büyük projelerde ve kurumsal şirketlerde her görev için tanımlı çalışanlar olur.

- **Müşteri:** en önemli gruptur; işin parasal karşılığını sağlayan taraftır. Bir yazılım firması bir bankaya yazılım hazırlıyorsa banka, yazılım firmasının müşterisidir.
- **Kullanıcılar:** yazılımı kullanacak kişilerdir; banka örneğinde banka memurları ya da bankanın müşterileri. Müşteri ile kullanıcı bazen aynı kişiler ya da gruplar olabilir.
- **Sistem analisti.**
- **Proje yöneticisi:** küçük uygulamalarda aynı zamanda sistem analisti olabilir.
- **Yazılım geliştiriciler ve teknik çalışanlar.**
- **Test ekibi (testerlar):** kullanıcılardan seçilen ya da kullanıcıyı temsil eden gruplardan alınan, kullanıcı açısından yapılan testleri gerçekleştiren kişiler.

Hoca ikinci bir örnek verdi: bir iletişim şirketinde yazılım geliştirme biriminin yanında muhasebe, insan kaynakları gibi başka departmanlar da vardır. Yazılım birimi muhasebe birimine bir yazılım geliştiriyorsa, muhasebe biriminin yöneticisi bu yazılım projesi ekibinin hem müşterisi hem sponsorudur, çünkü işi veren odur. Muhasebe biriminde bu programı kullanacak çalışanlar ise yazılımın kullanıcılarıdır.

## 7. Sistem analistinin gerekli yetenekleri

Dersin kapsamıyla en ilgili taraf sistem analistidir; küçük bir kurumda analistin aynı zamanda proje yöneticiliği de yaptığı düşünülür.

### 7.1 Teknik bilgi ve beceriler

Slayttaki liste (ekrandan, 01:25:00):

- Bilgisayarlar ve genel olarak nasıl çalıştıkları
- Programlama dilleri
- Bilgisayarla etkileşen cihazlar
- İletişim ağları
- Veri tabanları ve veri tabanı yönetim sistemleri
- İşletim sistemleri ve yardımcı programlar

**Araçlar (tools):** analiz ve tasarım belirtimlerini ve tamamlanmış sistem bileşenlerini geliştirmeye yardım eden yazılımlar; örneğin Microsoft Access, tümleşik geliştirme ortamları (IDE) ve bilgisayar destekli sistem mühendisliği (CASE) araçları.

Hoca, günümüzde ağ, programlama dilleri, veri tabanı yönetimi ve donanım seçimi konularının hepsini tek bir kişinin ancak genel düzeyde bilebileceğini belirtti. Önemli olan, analistin bir grup içinde bu uzmanlardan destek alarak ve onların toplu bilgisini kullanarak doğru seçimi yaptırabilmesidir.

### 7.2 İşletmecilik bilgi ve becerileri

Analistler genellikle işletmecilik alanında çalıştığı için işletmecilik bilgisi ve deneyimi gerekir (ekrandan, 01:35:00):

- Kurumlar hangi etkinlikleri ve süreçleri yürütür?
- Kurumlar nasıl yapılandırılır?
- Kurumlar nasıl yönetilir?
- Kurumda ne tür bir iş yapılır (örneğin hastane, banka)?
- Bu etkinlikleri yapan "aktörler" kimlerdir?

Analistin, sistem geliştireceği kurum hakkında da şunları bilmesi gerekir: kurumun tam olarak ne yaptığı, onu başarılı kılan şeyler, stratejileri ve planları, geleneği ("kültürü") ve değerleri.

Bunun faydası şudur: muhasebeyle ilgili bir uygulama anlatılırken biraz işletmecilik bilen bir analist müşteriyi daha kolay anlar. Böyle bir eğitimi yoksa bile başlayacağı işle ilgili terim çalışması yapmalıdır ki müşteriyle aynı dili konuşabilsin. Yazılım her zaman işletmecilik alanında olmayabilir; mühendislik alanında da yazılımlar geliştirilir. O durumda analistin o alan hakkında bilgi sahibi olması ya da o alanda daha önce yazılım yapmış olarak deneyim kazanmış olması gerekir.

### 7.3 İnsan bilgi ve becerileri

Slayttaki liste (ekrandan, 01:30:00):

- En önemli tek kişilerarası beceri: başkalarıyla açık ve etkili iletişim kurmak.
- Analistler ekip üyeleri, müşteriler vb. ile birlikte çalıştığı için insanlar hakkında şunları anlamalıdır:
  - İnsanlar nasıl düşünür
  - Nasıl öğrenir
  - Değişime nasıl tepki verir
  - Nasıl iletişim kurar
  - Nasıl çalışır ("etkinlikler" ve "aktörler")
- Diğer alanlar:
  - Görüşme yapma, dinleme ve gözlem becerisi
  - İyi yazılı ve sözlü sunum
  - Ekip içinde çalışabilmek

Hoca, analistin yalnızca gözlem yaparak değil insanlarla konuşarak, doğru soruyu sorup doğru cevabı kavrayarak çalıştığını, bazen doğru değerlendirme için anket yapmak gerekebileceğini söyledi. Proje yöneticisi tarafı düşünüldüğünde ekip yönetimi ve değişime karşı tepkileri yönetmek, müşteri tarafı düşünüldüğünde müşteriyle ve yönetimle iletişim kurmak da bu becerilerin parçasıdır.

### 7.4 Problem çözme yaklaşımı

Analistin bir başka gerekli özelliği problem çözme yaklaşımı ve problemler üzerinde analitik düşünme yeteneğidir. Analistin problem çözmeye yaklaşımı şu adımları izler:

1. Problemi anlamak ve araştırmak (bunun için analitik düşünce gerekir).
2. Problemin çözümüyle nasıl bir fayda sağlanacağını kanıtlamak.
3. Olası ve alternatif çözümleri ortaya koymak.
4. En iyi çözüme karar vermek.
5. Seçilen çözümün ayrıntılarını vererek tasarlamak.
6. Çözümün programını yazmak.
7. İstenen sonuçların elde edilip edilmediğini test etmek.

### 7.5 Tipik iş unvanları

Analistlik işleri firmalarda farklı unvanlarla ilan edilebilir (ekrandan, 01:40:00): programcı/analist, iş sistemleri analisti, sistem irtibat sorumlusu (system liaison), son kullanıcı analisti, iş danışmanı, sistem danışmanı, sistem destek analisti, sistem tasarımcısı, yazılım mühendisi, sistem mimarı. Hoca, bu konuyla ilgili bir örneği sonraki derse bıraktı.

## 8. Örnek Sorular

**Soru 1** (derste sözlü, 00:01:03): Çevrenizdeki bir sistemi seçin ve sistem tanımındaki öğelere göre tanımlayın: elemanları (alt sistemleri), aralarındaki ilişkiler, sınırı ve çevresi, girdileri, çıktıları, geri beslemesi ve hedefi nelerdir?

> **Çözüm (derste öğrenci örnekleri üzerinden tartışıldı):** Örnek olarak öğrenci kulübü: girdiler öğrenciler ve üyelik ücreti; sınır içindeki elemanlar üyeler, kulüp yönetim kurulu ve kulüp bütçesi; ilişkiler kulüp tüzüğüyle belirlenir; çıktılar etkinlikler ve eğitimler; geri besleme, üyelerden ve etkinliklerden toplanan geri bildirimin (anket, dönemsel toplantı) yönetim kuruluna dönüp etkinlikleri iyileştirmesidir (ekrandan, 00:15:00). Hastane örneğinde hedef ölçülebilir yazılabilir: belirli periyotta en fazla iyileşmiş, en az kayıp hasta çıkarmak.

**Soru 2** (derste sözlü, 01:05:15): Analiz aşamasının hedefi nedir ve analiz aşamasında hangi etkinlikler gerçekleştirilir?

> **Cevap (derste verildi):** Bir öğrenci gereksinimlerin saptanması diye cevap verdi; hoca tamamladı: analizde hedef, bilgisayar yazılımını düşünmeden, sistemin gerçekte ne iş yaptığını anlamaktır. Örneğin bir öğrenci bilgi sisteminde sistemin genel kapsamı, altındaki tek tek işlerin yapısı, bu işlerin hangi veriyi kullandığı ve hangi raporların istendiği anlaşılır. Etkinlikler: görüşme ve gözlemle bilgi toplama, gereksinimleri tanımlama ve diyagramlarla modelleme, gereksinimleri önceliklendirme, çözüm seçenekleri üretme.

**Soru 3** (derste sözlü, 01:08:01): Tasarım aşamasında ne yapılır?

> **Cevap (derste verildi):** Tasarımda yazılım sistemi gerçeklenmez, modellenir. Analizde anlaşılan işlerin yazılımının nasıl hazırlanması gerektiği belirlenir: ağ yapısı, kullanıcı ve sistem ara birimleri, veri tabanı yapısı, prototip ve sistem kontrolleri.

## Dersin Toparlaması

Bu derste önce sistem kavramı öğrencilerin seçtiği örneklerle (araba kiralama, motor kontrol, aile, hastane, öğrenci kulübü, besin zinciri, otomobil) pekiştirildi ve bir sistemi tanımlarken elemanların yanında sınır, çevre, girdi, çıktı, geri besleme ve ölçülebilir bir hedefin de belirtilmesi gerektiği vurgulandı. Ardından sistem analizi (ne yapılacağını anlamak), sistem tasarımı (nasıl gerçekleştirileceğini belirlemek) ve sistem analisti tanımlandı; kurumlardaki bilgi sistemi tipleri TPS, MIS, EIS ve DSS olarak sıralandı ve TPS'ten MIS'e geçiş bordro örneğiyle gösterildi.

Dersin ikinci yarısında sistem geliştirme yaşam döngüsünün beş aşaması (planlama, analiz, tasarım, gerçekleme, destek) şelale modeline göre hedef ve etkinlikleriyle anlatıldı; ağaç salıncağı örneğiyle iletişim ve belgelemenin önemi gösterildi. Son olarak bilgi sistemi tarafları ve sistem analistinin teknik, işletmecilik ve insan becerileri ile problem çözme yaklaşımı ele alındı. Sonraki derste bilgi sistemi taraflarına devam edilmesi ve ön inceleme ile fizibilite aşamasının işlenmesi planlandı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
