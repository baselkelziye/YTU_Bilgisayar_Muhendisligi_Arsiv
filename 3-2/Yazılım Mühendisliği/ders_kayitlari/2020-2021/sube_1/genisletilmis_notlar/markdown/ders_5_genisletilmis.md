# Ders 5 Genişletilmiş Notu: Nesneye Yönelik Analiz: Kullanım Öyküleri, Use Case Diyagramları ve Sınıf Diyagramları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersle Bağlantı: SRS ve İşlevsel Olmayan Gereksinimler
- 2. Nesneye Yönelik Analiz Yaklaşımı
- 3. Uygulama Alanının Çözümlenmesi (Domain Analysis)
- 4. Doğal Dille Yazılmış Gereksinimler Belgesi: NextGenPOS Örneği
- 5. Kullanım Öyküleri (Use Case Belgeleri)
- 6. Örnek Kullanım Öyküsü: Satış İşlemi
- 7. Alternatif Öyküler
- 8. Sınıfların Belirlenmesi
- 9. Kullanım Senaryosu Diyagramları
- 10. Veri Varlıkları ile Nesneler Arasındaki Fark
- 11. Sınıf Diyagramı
- 12. Analiz Aşamasının Özeti
- Örnek Sorular
- Dersin Toparlaması

## 1. Önceki Dersle Bağlantı: SRS ve İşlevsel Olmayan Gereksinimler

Bu haftanın konusu nesneye yönelik analizdir. Konu, daha önce sistem analizi dersinde ve nesneye yönelik programlama dersinde kısmen görülmüştü; bu derste yazılım mühendisliği açısından yeniden ele alınır.

Önceki hafta gereksinim analizi ve özellikle gereksinim spesifikasyonu işlenmişti. Gereksinim analizinde amaç, üzerinde çalışılacak uygulamayla ilişkili sistemin yapısını anlamaktır. Bu yapının anlaşılması için SRS (Software Requirements Specification) raporunun ayrıntılı ve gerçekçi biçimde hazırlanması gerekir. SRS'te işlevsel (fonksiyonel) ve işlevsel olmayan (non-functional) gereksinimler ayrı ayrı verilir. Önceki derste anlatılan yazılım kalite özellikleri, işlevsel olmayan gereksinimlerin kaynağıdır: bu özelliklerden hangilerinin söz konusu uygulamada öne çıktığı, işlevsel olmayan gereksinimler bölümünde irdelenir.

Analiz aşamasında bilgi toplamadan sonra modelleme yapılır. Nesneye yönelik modellemede use case diyagramları ve use case belgeleri kullanılır; ilerleyen haftalarda bunlarla bütünlüklü bir örnek çalışma da oluşturulacaktır.

## 2. Nesneye Yönelik Analiz Yaklaşımı

Slayttaki tanım şöyledir (ekrandan, 00:05:00):

- Çözümleme (Analiz): Bir şeyi anlayabilmek için parçalarına ayırmak.
  - Uygulama/problem alanının anlaşılması.
  - Kullanıcı gereksinimlerinin anlaşılması.
  - Koddaki sınıflar ve nesneler ile bunların arasındaki üst düzey etkileşimlerin belirlenmesi: çözümleme modelinin oluşturulması.

Yani nesneye yönelik analizde önce problem alanı ve kullanıcının istekleri anlaşılır, ardından bu anlayış sınıflar, nesneler ve onların etkileşimleri biçiminde bir modele dönüştürülür. Bu modele çözümleme modeli denir.

## 3. Uygulama Alanının Çözümlenmesi (Domain Analysis)

Nesneye yönelik analizde uygulama alanının çözümlenmesine domain analizi denir. Amaç, uygulama alanını anlamak ve elde edilen bilgileri analiz modeline taşımaktır.

Uygulama alanı hakkında bilgi edinilebilecek kaynaklar (ekrandan, slayt listesi 00:05:00 karesindeki küçük önizlemeden ve anlatımdan):

- Teknik literatür
- Mevcut uygulamalar
- Müşteri anketleri
- Uzman tavsiyeleri
- Mevcut ve gelecekteki gereksinimler

Örneğin ticari bir yazılım (muhasebe, satış analizleri vb.) hazırlanacaksa önce o konunun literatürü, daha teknik bir yazılım geliştirilecekse o teknik alanın literatürü incelenir. Bu incelemede alanın anahtar kelimeleri çıkarılır; bir anlamda o alanda geçerli olan ve analistin bilmediği terimlerden bir sözlük oluşturulur. Başka ekiplerin yaptığı ya da şu anda kullanılan uygulamalar incelenir, müşteri anketleri ve uzman tavsiyeleri değerlendirilir. Şu andaki çalışanlar ve kullanıcılarla görüşülerek mevcut ve gelecekteki gereksinimler hakkında bilgi edinilir.

Bu bilgi toplama yolları sistem analizi dersinde daha ayrıntılı görülmüştü. Slaytta yer almasa da iki önemli yol daha vardır:

- **Görüşme (interview):** Olaya farklı bakış açılarıyla ilişkisi olan kişilerle görüşülür ve onların üzerinde çalıştıkları sistem anlaşılmaya çalışılır.
- **Yerinde inceleme:** Kullanıcıların mevcut sistemle nasıl çalıştığı, yerinde yaşanarak ve görülerek incelenir.

## 4. Doğal Dille Yazılmış Gereksinimler Belgesi: NextGenPOS Örneği

Gereksinimlerin belirlenmesinde ilk adım bir gereksinimler belgesidir: müşterinin programdan beklentilerini anlatan, doğal konuşma diliyle yazılmış bir belge. Bu belge için ya müşteri dinlenip not alınır ya da müşteriden yaptığı işle ilgili bir paragraf, doğal dilde bir yazı istenir.

Derste kullanılan örnek NextGenPOS perakende satış programıdır. Örnek, Larman'ın nesneye yönelik analiz ve tasarım (UML ve tasarım kalıplarının uygulanması) kitabından kısaltılarak alınmıştır; örneklerin daha ayrıntılı hali bu kitapta bulunabilir.

Slayttaki örnek gereksinimler belgesi (ekrandan, 00:10:00):

> NextGenPOS Perakende Satış Programı: Eski yazılım ihtiyaçlarımızı karşılayamadığından, yenilenecek donanımla birlikte perakende satış programımızın da yenilenmesine gerek duyuyoruz. Program kasada yapılan alış-veriş işlemlerine yardımcı olmalıdır. Yapılan her işlem program tarafından saklanmalı; mali bilgiler harici bütçe sistemine, mal çıkış bilgileri ise harici envanter sistemine iletilmelidir. Saklanan işlemler üzerinde daha sonra raporlamalar ve analizler yapılabilmelidir. Sistem yapılan alış-verişler karşılığında müşteriye fiş vermelidir. Yapılan her satış için KDV de hesaplanarak ayrıca belirtilmelidir. Şirketimizin birden fazla şubesi olup tüm şubelerdeki işlemler merkezi sunucuya iletilmelidir.

Bu metinden şunlar anlaşılır: bütçe ve envanter sistemleri bu programın dışında çalışan harici sistemlerdir; program envanter ya da bütçe işlemi yapmaz, yalnız bu sistemlere girdi aktarır. Program yalnız satış işlemlerini yürütür ve müşteriye fiş verir; satışlar üzerinde raporlama ve analiz yapılabilmesi hedeflenir.

Doğal dille yazılmış gereksinimler sistemi çok ayrıntıya girmeden ama çerçevesini çizecek kadar anlatır. Bu metin tamamen kullanıcıya bırakılırsa kullanıcı, kendisi için önemli olduğunu düşündüğü ama sistem için gereksiz ayrıntılara da yer verir. Bu nedenle metni analistin kendisinin hazırlaması ya da yönlendirmesi daha faydalıdır.

Slaytın son maddesi bir sonraki adımı gösterir: doğal dille yazılmış gereksinimler belgesinden kullanım öykülerine geçiş.

## 5. Kullanım Öyküleri (Use Case Belgeleri)

Gereksinimler belirlenirken kullanım öyküleri oluşturulur. Kullanım öyküleri (use case belgeleri) sistem analizi dersinde de görülmüştü. Slayttaki tanım ve amaçlar şunlardır (ekrandan, 00:15:00):

- **Kullanım öyküleri:** Programın yapacağı işleri ayrıntılı adımlarla ve belli kurallara uyarak anlatan belgeler.
- Kullanım öykülerinin oluşturulmasındaki amaç:
  - Ürünün sağlaması beklenen işlevleri ve ürünün çalışma ortamını belirlemek,
  - Son kullanıcı ve yazılım ekibi arasında bir anlaşma zemini belirlemek,
  - Son kullanıcı ve sistemin birbirleri ile nasıl etkileşimde bulunacağını açık ve belirsizlikten uzak olarak tanımlamak,
  - Doğrulama testleri için bir zemin oluşturmak.

> **Hocanın vurgusu:** Bir projede başka hiçbir belge olmasa bile gereksinim analizi raporu (SRS) mutlaka bulunmalıdır, çünkü SRS müşteriyle yazılım ekibi arasında sözleşme niteliği taşır.

Tanımların mümkün olduğunca net yapılması gerekir. Doğrulama testi (validation) kullanıcı tarafından yapılan testtir: kullanıcı bu rapora bakarak sistemi adım adım deneyebilmelidir.

Bir kullanım öyküsünün bölümleri (ekrandan, 00:15:00):

- **Giriş bölümü:** Sistemin neyi, hangi koşullar ve sınırlar içerisinde yapması gerektiğini anlatır. Burada kullanım öyküsünün adı, birincil aktörü, diğer ilgilileri, sistemin çalışmaya başlaması için gereken ön koşul ve çalışmasını bitirmesi için gereken son koşul belirtilir.
- **Ana senaryo / ana başarılı akış:** Her şeyin yolunda gitmesi halinde yürütülecek eylemler, zaman sırasıyla.
- **Alternatif senaryolar:** Bir aksilik olması halinde yapılacak işlemler.

## 6. Örnek Kullanım Öyküsü: Satış İşlemi

### 6.1 Giriş bölümü

Slayttaki kullanım öyküsü (ekrandan, 00:20:00):

- KULLANIM ÖYKÜSÜ: Satış İşlemi
- Birincil Aktör: Kasiyer.
- İlgililer ve İlgi Alanları:
  - Kasiyer: Doğru ve hızlı giriş ister, kasa açığı maaşından kesildiğinden ödeme hataları istemez.
  - Satıcı: Satış komisyonlarının güncellenmesini ister.
  - Müşteri: En az çaba ile hızlı hizmet ister. Ürün iadesinde kullanmak üzere fiş ister.
- Ön Koşullar: Kasiyerin kimliği doğrulanır.
- Son Koşullar: Ödeme tahsil edilir. Satış kaydedilir. Fiş yazılır.

Use case yapısında işlemler ve aktörler vardır. Aktörler use case diyagramında çöp adamla çizilir. Aktörün her zaman canlı olması gerekmez: birincil aktörün dışındaki ilgililer bir sensör ya da kasadaki işlemlerin yapıldığı bir birim de olabilir.

İlgililerin istekleri şöyle açıklanır:

- **Kasiyer** ürünleri kasadan geçirir ve fatura kesimini yönetir. Kasa açığı maaşından kesildiği için programdan iki şey bekler: şu anda yaptığından daha hızlı çalışmak ve hiç ödeme hatası olmaması.
- **Satıcı**, mağazada müşteriyle ilgilenip satışı yapan kişidir. Bu uygulamada kasada hangi satıcının işlem yaptığının kodu girilir (her mağazada böyle olmaz, ama bu örnekte vardır); satıcı komisyonlarının doğru güncellenmesini ister.
- **Müşteri** birincil aktör değildir ama olayla ilgilidir. En az çabayla hızlı hizmet ister; ürün iadesi yapabilmek için fişin doğru ve hızlı hazırlanmasını ister.

Son koşul işin bittiğini belirtir: ödeme tahsil edilir, satış kaydedilir, fiş yazılır. Ayrıca satış ilgili yerlere aktarılır: mali bilgiler bütçe sistemine, mal çıkış bilgileri envanter sistemine.

### 6.2 Ana senaryo

Ana senaryodaki adımlar aynı zamanda işlevsel (fonksiyonel) gereksinimlerdir. Anlatıma göre adımlar şunlardır:

<!-- BELİRSİZ: Ana senaryo slaytı karelerde yalnız küçük önizleme olarak görünüyor; 11 adım olduğu önizlemeden ve anlatımdan anlaşılıyor, adımların metni altyazıdan kuruldu. 5. ve 6. adımların numarası anlatımdan çıkarıldı. -->

1. Müşteri kasaya alacağı ürünlerle gelir.
2. Kasiyer yeni bir satış işlemi başlatır.
3. Kasiyer ürünün barkodunu girer veya okutur.
4. Sistem bir satış kalemi oluşturur. Bu kalemde ürünün tanımı, fiyatı ve toplam bedeli (aynı maldan birden fazla alınmış olabilir) yer alır.
5. Kasiyer 3. ve 4. adımları bütün ürünler için tekrarlar.
6. Sistem toplam bedeli vergiyle (KDV) birlikte hesaplar.
7. Kasiyer müşteriye toplamı bildirir ve ödeme ister.
8. Müşteri ödemeyi yapar, sistem ödemeyi tahsil eder.
9. Sistem tamamlanan işlemin kaydını tutar; harici envanter sistemine ve mali sisteme gerekli bilgiyi gönderir.
10. Sistem fişi verir.
11. Müşteri işi bitmiş olarak ayrılır.

> **Hocanın vurgusu:** Adımlar birleştirilmez, her biri ayrı bir işlem olarak yazılır. Böylece daha sonra kontrol ederken her adımın doğru çalışıp çalışmadığına ayrı ayrı bakılabilir.

8. adım iki işlem gibi görünse de ödeme yapıldığı anda sistem tahsil eder. Sistem parayı aldıktan sonra kaydı tamamlayabilir ve bilgileri envanter ve mali sisteme gönderebilir.

## 7. Alternatif Öyküler

Ana senaryo her şeyin düz gittiği durumu gösterir; use case belgesinin tamamlanması için alternatif öykülerin de yazılması gerekir. Alternatif öyküler, ana senaryodaki ilgili adımın numarasıyla adlandırılır. Slayttaki alternatif öyküler (ekrandan, 00:25:00):

- **3a. Geçersiz barkod:**
  1. Sistem uyarı mesajı verir ve kayıt girişini reddeder.
- **3-7a. Müşteri bir kalem malı alışverişten çıkartmak ister:**
  1. Kasiyer satıştan çıkarmak üzere ürünün barkodunu okutur.
  2. Sistem güncel toplamı bildirir. ...

3a'da barkod okunamadığında sistem uyarı verip girişi reddeder ve barkod okutma adımı tekrarlanır. 3-7a, 3. ile 7. adımlar arasında herhangi bir anda geçerlidir. Örneğin kasiyer toplamı bildirip ödeme istediğinde müşteri parasının yetmediğini görüp bazı malları çıkarmak isteyebilir; bu durumda 7a işletilir ve akış geri dönerek ilgili adımların bir kısmı tekrarlanır.

## 8. Sınıfların Belirlenmesi

Kullanıcı gereksinimleri belgesinden ve kullanım senaryolarından uygulamadaki aday sınıflar elde edilir. Bu sırada şu sorular sorulur:

- **Saklanan bilgi nedir?** Sistemin çalışması süresince her bir varlığın durumu saklanmalıdır.
- **Hangi hizmetler gerekir?** Bir varlığın hizmetlerine ihtiyaç duyan başka varlıklar olabilir. Problemin çözümüyle ilgili bilgi üreten ve problemin çözümü için bilgi tüketen varlıklar belirlenir.

Bu varlıklar için nesne ve sınıf tanımları yapılır; böylece sistemin tanımı gerçekleştirilmiş olur.

Slayttaki sınıf belirleme adımları (ekrandan, 00:30:00):

- Üyelerin belirlenmesi:
  - Sıfat ve eylemlerin taranması
  - Sorumlulukların belirlenmesi (CRC kartları)
- Sorumlulukların dağıtılması:
  - Sorumlulukların bir yerde yoğunlaşmaması
  - Sorumlulukların genelden özele doğru tanımlanması (kalıtım hiyerarşisinde genelden özele gidilmesi)
  - Bir bilgi ile ilgili davranışların, o bilgi ile aynı sınıfta yer alması (encapsulation)
  - Tek bir şey hakkındaki bilginin tek sınıfta yer alması

CRC kartları (Class, Responsibility, Collaboration) çevik yaklaşımda, özellikle XP'de görülmüştü: her sınıfın sorumluluklarını ve hangi sınıflarla iş birliği yaptığını belirten kartlardır. Sorumlulukların genelden özele tanımlanması, önce sınıfın temel özelliklerinin belirlenmesi ve bu sınıfa ait bütün nesnelerin (alt sınıfların) hangi genel özellikleri kalıtımla alacağının belirlenmesi demektir. Encapsulation ise bir bilgiyle ilgili davranışların o bilgiyle aynı sınıfta tutulmasıdır.

Böylece gereksinimler belirlenip kullanım öyküleri tamamlandığında uygulamada hangi sınıfların bulunduğu, bu sınıfların özellikleri, hangi sınıfların diğerleriyle iş birliği içinde olduğu ve hangi eylemlerin gerçekleşeceği belirlenebilir.

## 9. Kullanım Senaryosu Diyagramları

### 9.1 Temel elemanlar

Kullanım senaryosu belgesinin yanında kullanım senaryosu diyagramı da çizilir. Slayttaki şekil "Şekil 7.1 Kullanım senaryosu temel elemanları" başlığını taşır (ekrandan, 00:35:00). Şekilde ortada "Sistem" yazılı bir dörtgen, dörtgenin içinde "Use case" yazılı bir elips ve dörtgenin iki yanında elipse çizgiyle bağlı birer "Aktör" (çöp adam) vardır.

- **Aktör:** Çöp adamla gösterilir. Aktör başka bir sistemse kutu (kare) ile de gösterilebilir.
- **Use case:** Aktörlerin gerçekleştirdiği bir eylemdir; elipsle gösterilir.
- **Sistem sınırı:** Bütün sistem bir dörtgen içine alınabilir; bu her zaman gerekli değildir.

**Soru:** Şekilde iki çöp adam olması iki ayrı işlem olduğunu mu gösteriyor?

**Cevap:** Hayır. Use case, gerçekleşen işlemi anlatır; şekilde bu işlemle ilişkili iki aktör vardır. Bunlardan yalnız biri birincil aktör olarak belirlenir, ikisi birden birincil aktör değildir. Satış örneğinde birincil aktör satış fişini kesen kasiyerdir; müşteri ve komisyon bekleyen satıcı da ilgilidir. Bunlara aktör denebilir ama birincil aktör değildirler. Şekil NextGenPOS'a özgü değildir, genel yapıyı gösterir.

### 9.2 Genelden ayrıntıya

Veri akış diyagramlarında olduğu gibi use case diyagramlarında da özetten ayrıntıya gidilir. Önce bütün uygulama bir sistem dörtgeni içinde gösterilir; sistemin temel olarak kaç alt senaryosu (örneğin iki, üç ya da dört temel use case) olduğu ve bunların hangi aktörlerle ilişkili olduğu genel use case diyagramında çizilir. Sonra her use case ayrı diyagramlarda daha açıklamalı olarak çizilebilir.

### 9.3 ATM örneği

Sözlü olarak anlatılan genel diyagram örneği bir ATM sistemidir. Aktörler: banka müşterisi, bankanın ana merkezinde işleri yöneten banka memuru ve makineye para dolduran bakım personeli. Müşteri para çektiğinde nakit para çekimi, fon transferi ve başka işlemler gibi senaryolar yürür; müşteri tuşlara bastıkça banka memuru tarafı da kontrol eder. Bakım personeli şube içinde ya da dışında gelip para bittikçe makineyi doldurur. Bu, ATM'nin nasıl çalıştığını gösteren genel use case diyagramıdır; buradaki işlemlerin her biri için daha ayrıntılı diyagramlar hazırlanabilir.

<!-- BELİRSİZ: ATM diyagramının çizildiği slayt karelerde görünmüyor; aktör ve use case adları altyazıdan alındı. -->

Buraya kadar olan bölümde kullanım senaryoları, kullanım senaryo belgesi ve kullanım senaryo diyagramlarıyla işlevsel gereksinimler nesneye yönelik kavramlarla gösterilmiş olur.

## 10. Veri Varlıkları ile Nesneler Arasındaki Fark

Nesneye yönelik kavramlarda işin bir de veri tarafı vardır: hangi sınıflar kullanılıyor ve bunlar arasındaki ilişkiler nelerdir? Bu derste analiz ve tasarım nesneye yönelik yaklaşımla ele alınır. Klasik (yapısal) ve nesneye yönelik yaklaşımın farkı şudur:

- **Yapısal yaklaşım:** Veri bir yerde tutulur, işlemler başka bir yerde yapılır. İşlem veriyi kullanmak istediğinde verinin o işleme aktarılması gerekir.
- **Nesneye yönelik yaklaşım:** Bir sınıf tanımlandığında hem özellikleri (yapısal yaklaşımdaki varlıklarda olduğu gibi) hem de bu nesneye uygulanabilecek işlemler tanımlanır. Bu işlemler sınıf tanımında belirtilir ve hangi metotlarla çağrılacakları da belirlenmiş olur.

Bu konu sistem analizi dersinde kullanılan kitabın (Satzinger, Jackson ve Burd, *Systems Analysis and Design in a Changing World*, 2. baskı) slaytlarıyla hatırlatılır. Slayttaki veri varlıkları tanımı (ekrandan, 00:50:00):

- Data Entities:
  - Things the system needs to store data about in traditional IS approach (geleneksel bilgi sistemi yaklaşımında sistemin hakkında veri saklaması gereken şeyler)
  - Modeled with entity-relationship diagram (varlık-ilişki diyagramıyla modellenir)
  - Generally used with relational database development (genellikle ilişkisel veritabanı geliştirmede kullanılır)

Geleneksel yapıda varlıklar, varlıklar arasındaki ilişkiler ve özellikler vardır (veritabanı dersinde görüldüğü gibi). Örneğin müşteri varlığının bütün özellikleri ve diğer varlıklarla ilişkileri ER diyagramında gösterilir.

Nesneye yönelik yaklaşımda nesneler hem davranışlarını hem özelliklerini saklar. Bir sınıf bir varlık tipidir; nesne onun özel halidir. Nesnelere uygulanan davranışlar metotlarla tanımlanır. Yapısal yaklaşımda veri varlığı ile süreçler (işlem 1, işlem 2, işlem 3; girdiler ve çıktılar) arasında ilişki vardır ama ikisi ayrı yerlerdedir: veritabanındaki veri varlığına işlemler dışarıdan uygulanır. Nesneler ise veriyi enkapsüle eder ve bu veri nesnenin kendi metotlarıyla işlenir. Nesne tanımında önce nesneye ait veri (özellikler), altında bu veriyi işleyen metotlar tanımlanır; metotlar nesnelere gönderilen mesajlarla başlatılır.

ER diyagramında varlıklar arasında kurulan ilişkilerin benzerleri sınıf diyagramında sınıflar arasında kurulur. Use case belgeleri ve diyagramlarından sonra, analiz aşamasında genel bir sınıf diyagramına geçilir.

> **Hocanın vurgusu:** Analizde hazırlanan sınıf diyagramında metotlara çok girilmez; metotlar tasarım sırasında ayrıntılandırılır.

## 11. Sınıf Diyagramı

Sınıf diyagramı veri varlıklarından fazlasını içerir: sınıflar veri varlıkları yerine nesneleri modeller; genelleştirme/özelleştirme hiyerarşileri (genel süper sınıflar ve özelleştirilmiş alt sınıflar) bulunur ve süper sınıfın özellikleri alt sınıflara kalıtımla geçer; bütün-parça (aggregation) hiyerarşileri bulunur, yani sınıflar parçalarıyla ilişkilidir ve parçalarıyla tanımlanabilir.

### 11.1 Genelleştirme/özelleştirme

Slayttaki örnek "A Generalization/Specialization Hierarchy for Motor Vehicles, Figure 5-29" şeklidir (ekrandan, 00:55:00):

```text
MotorVehicle
├── Truck
├── Car
│   ├── SportsCar
│   ├── Sedan
│   └── SportUtility
└── Tractor
```

Oklar (içi boş üçgen uçlu) alt sınıftan süper sınıfa doğrudur. Örneğin Sedan, arabanın (Car) bütün özelliklerini kalıtımla alır; Car da MotorVehicle'ın özelliklerini alır. Hiyerarşide yukarı doğru genelleştirme, aşağı doğru özelleştirme vardır.

### 11.2 Aggregation (bütün-parça)

Aggregation, bir bütünün parçalarıyla ilişkisini gösterir. Slayttaki örnekte bir bilgisayar ile elemanları arasındaki ilişkiler tanımlanır.

<!-- BELİRSİZ: Aggregation şekli (Figure 5-31) karelerde yalnız küçük önizleme olarak görünüyor; parça sınıflarının adları okunamadı. -->

### 11.3 Sınıf sembolü

Sınıf sembolü üç bölümlü bir kutudur: en üstte sınıfın adı, ortada özellikleri (o sınıfın bütün nesnelerinin değer taşıdığı nitelikler), altta metotları (o sınıfın nesnelerinin yapabildiği işlemler). Slayttaki örnek müşteri (Customer) sınıfıdır: müşterinin özellikleri ve müşteriye uygulanacak işlemler gösterilir.

<!-- BELİRSİZ: Sınıf sembolü şekli (Figure 5-32) yalnız küçük önizlemede görünüyor; Customer sınıfının nitelik ve metot adları okunamadı. -->

### 11.4 Banka hesap sistemi sınıf diyagramı

Banka muhasebe sistemi sınıf diyagramı hem genelleştirme/özelleştirmeyi (kalıtım) hem de sınıflar arasındaki ilişkileri gösteren, analiz sırasında çizilmiş bir diyagramdır. Müşterinin hiç hesabı olmayabilir ya da birden fazla hesabı olabilir; bu, ilişkinin hesap ucuna yazılan 0..* çokluğuyla gösterilir. Böylece ER diyagramındaki bire bir, bire çok ilişkiler sınıf diyagramında farklı bir gösterimle ifade edilir.

Hesap (Account) üst sınıftır; farklı hesap türleri bu genelleştirmenin altındadır ve farklı hesap türlerine farklı işlemler uygulanabilir. Örneğin alt hesap türlerinden biri Account'un bütün özelliklerine sahiptir ve ek olarak bir faiz oranı (interest rate) özelliği taşır.

<!-- BELİRSİZ: Banka hesap sistemi şekli (Figure 5-33) yalnız küçük önizlemede görünüyor; alt sınıf adları ve diğer nitelikler okunamadı. -->

### 11.5 Derse kayıt sınıf diyagramı (ilişki sınıfı)

Slayttaki son örnek "Enrollment Class Diagram with Association Class" şeklidir (ekrandan, 01:00:00). Sınıflar ve üyeleri:

| Sınıf | Nitelikler | Metotlar |
|---|---|---|
| Course | courseNumber, title, creditHours | addCourse |
| CourseSection | sectionNumber, startTime, roomNumber | openSection, closeSection |
| Student | studentID, name, major | admitStudent, recordDegree |
| CourseEnrollment (ilişki sınıfı) | grade | postGrade |

İlişkiler:

- Course (1) - CourseSection (0..*): Bir dersin hiç şubesi olmayabilir ya da birden fazla şubesi olabilir; her şube tek bir derse aittir.
- CourseSection (0..*) - Student (0..*): Bir öğrenci hiç ders şubesi seçmemiş olabilir ya da birden fazla şube seçmiş olabilir; bir şubeyi de hiçbir öğrenci seçmemiş olabilir ya da çok sayıda öğrenci seçmiş olabilir.
- CourseEnrollment bu çoka çok ilişkiye kesikli çizgiyle bağlıdır. Öğrenci ile ders şubesi arasındaki ilişki, not (grade) özelliği ve not girme (postGrade) işlemiyle tanımlanır.

> **Ek bilgi (derste anlatılmadı):** İlişki sınıfı (association class), iki sınıf arasındaki ilişkinin kendisine ait nitelik ve işlemleri olduğunda kullanılır. Not, ne yalnız öğrenciye ne de yalnız şubeye aittir; belirli bir öğrencinin belirli bir şubedeki kaydına aittir. Bu yüzden ilişki sınıfında tutulur.

## 12. Analiz Aşamasının Özeti

Gereksinim analizi ve spesifikasyon hazırlama görüldükten sonra bu hafta nesneye yönelik analizin ilk kademesi işlenmiştir. Bu kademe gereksinim analizi sırasında use case belgelerinin oluşturulmasıdır. Sıra şöyledir:

1. Kullanıcıdan konuşma dilinde bir hikaye alınır. Hikayenin doğru alınması için analist kullanıcıyı yönlendirmelidir.
2. Bu hikayeden use case belgesi oluşturulur ve use case diyagramı çizilir. Hangisinin önce yapılacağı analistin tercihidir: ikisi aynı anda yürütülebilir ya da önce diyagramla genel yapı kurulup sonra belge ayrıntılandırılabilir.
3. Belgeden ve diyagramdan sınıflar belirlenir ve analiz aşamasının sınıf diyagramı oluşturulur.

Analiz aşamasındaki sınıf diyagramı kabadır: sınıf tanımındaki işlemlere çok girilmeden hangi sınıfların olduğu, hangi özelliklere sahip oldukları ve aralarındaki ilişkiler genel bir yaklaşımla çizilir. Bu ayrıntılar tasarım aşamasında iyileştirilir ve araya tasarım kalıpları (design patterns) eklenerek tasarım geliştirilir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:05:28): Uygulama alanı hakkında hangi kaynaklardan bilgi edinilebilir?

> **Çözüm:** Teknik literatür (alanın anahtar kelimelerinden bir sözlük oluşturulur), mevcut uygulamalar, müşteri anketleri, uzman tavsiyeleri ve mevcut ve gelecekteki gereksinimler için çalışanlarla/kullanıcılarla görüşme; ayrıca görüşme (interview) ve yerinde inceleme.

**Soru 2** (derste sözlü, 00:20:57): Satış İşlemi kullanım öyküsünde ön koşul ve son koşul nedir?

> **Çözüm:** Ön koşul: kasiyer kasayı açtığında kimliği doğrulanır. Son koşul: ödeme tahsil edilir, satış kaydedilir, fiş yazılır; satış bilgileri ilgili yerlere (mali bilgiler bütçe sistemine, mal çıkış bilgileri envanter sistemine) aktarılır.

**Soru 3** (derste sözlü, 00:25:11): Satış işleminde ana senaryonun dışında hangi alternatif öyküler vardır?

> **Çözüm:** 3a: barkod geçersizse sistem uyarı mesajı verir ve kaydı reddeder, okutma tekrarlanır. 3-7a: müşteri 3. ile 7. adımlar arasında bir kalem malı çıkarmak isterse kasiyer o ürünün barkodunu satıştan çıkarmak üzere okutur ve sistem güncel toplamı bildirir (ekrandan, 00:25:00).

**Soru 4** (derste sözlü, 00:32:28): Kullanım senaryosu temel elemanları şeklinde iki çöp adam olması iki ayrı işlem olduğunu mu gösterir?

> **Çözüm:** Hayır. Şekildeki tek use case tek bir işlemi anlatır; iki çöp adam bu işlemle ilişkili iki aktördür. Bunlardan yalnız biri birincil aktördür.

## Dersin Toparlaması

Bu derste nesneye yönelik analizin ilk kademesi işlendi. Analiz, problemi anlamak için parçalarına ayırmaktır; önce uygulama alanı literatür, mevcut uygulamalar, anketler, uzman görüşleri, görüşme ve yerinde inceleme ile çözümlenir. Ardından müşterinin beklentileri doğal dille bir gereksinim metnine dökülür (NextGenPOS örneği), bu metinden giriş bölümü, ana senaryo ve alternatif senaryolardan oluşan kullanım öyküleri yazılır ve use case diyagramları çizilir. Kullanım öykülerinden sıfat ve eylem taraması ve CRC kartlarıyla sınıflar bulunur, sorumluluklar dağıtılır.

Veri tarafında, yapısal yaklaşımdaki veri varlıkları ile nesneye yönelik yaklaşımdaki nesneler karşılaştırıldı ve sınıf diyagramının genelleştirme/özelleştirme, aggregation, çokluklu ilişkiler ve ilişki sınıfı gibi öğeleri örneklerle gösterildi. Analiz aşamasında sınıf diyagramı kaba çizilir; metotların ayrıntılandırılması ve tasarım kalıplarının eklenmesi bir sonraki konu olan tasarım aşamasında yapılacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
