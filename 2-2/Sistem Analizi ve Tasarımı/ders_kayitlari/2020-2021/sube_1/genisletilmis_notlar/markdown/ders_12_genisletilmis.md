# Ders 12 Genişletilmiş Notu: Proje Sunumları ve Analiz-Tasarım Diyagramlarının Değerlendirilmesi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin yapısı ve sunumlardan beklenenler
- 2. Etkinlik bilgi sistemi: yapısal analiz ve tasarım örneği
- 3. Dijital oyun mağazası: fizibilite ve diyagramların yeri
- 4. Takım elbise kiralama sistemi: ardışıl diyagramlar
- 5. Kafe/restoran yönetim sistemi: VAD ve nesneye yönelik modeller birlikte
- 6. Film değerlendirme sistemi: VAD kuralları ve sınıf yapısı
- 7. Sanal market sistemi: kullanım senaryoları
- 8. Özel ders platformu: kavramsal ve UML sınıf diyagramı, veri tabanı, Gantt
- 9. Freelance hizmet sistemi: üç kullanıcı tipi ve sınıf diyagramı
- 10. Hocanın geri bildirimlerinden çıkan genel kurallar
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin yapısı ve sunumlardan beklenenler

Bu ders, dönem boyunca gruplar halinde yürütülen sistem analizi ve tasarımı projelerinin sunumlarına ayrıldı. Her grup bir müşteri rolü belirleyerek gerçekçi bir bilgi sistemi geliştirmiş, proje yönetimi rollerini (proje müdürü, baş analist, analist, tasarımcı, yazılım geliştirici, veri tabanı uzmanı, test uzmanı, müşteri) aralarında paylaşmıştı. Hoca sunumlarda modelin anlatılmasını istedi; programın çalışan hali ayrıca, ayrı bir oturumda gösterilecekti.

Sunumların ortak iskeleti dersin daha önceki haftalarında anlatılan sistem geliştirme yaşam döngüsünü izliyordu:

- Ön inceleme ve planlama: müşteriyle toplantılar, problem tanımı, ekip yapısı ve organizasyon şeması, Gantt diyagramı.
- Fizibilite: teknik (yazılım ve donanım), ekonomik, zaman, sosyal ve yasal fizibilite.
- Sistem analizi: gereksinimler, modüller, veri akış diyagramları ya da kullanım durumu diyagramları ve senaryoları, kavramsal sınıf diyagramı.
- Sistem tasarımı: yapı diyagramı, ER diyagramı, arayüz tasarımı ya da ardışıl diyagramlar ve ayrıntılı UML sınıf diyagramı.
- Gerçekleştirme ve test: kullanılan teknolojiler, kod parçaları, ekran çıktıları.
- Müşteri değerlendirmesi.

Hoca her sunumda özellikle diyagramların hangi aşamaya ait olduğunu sorguladı ve müşteri değerlendirmesi bölümünün nasıl kurulması gerektiğini birkaç kez açıkladı. Bu notta sunumlar, derste geçtiği sırayla, akademik açıdan öğretici yanlarıyla aktarılmıştır. Sunanlar "bir grup" ya da "grup" diye anılmıştır.

## 2. Etkinlik bilgi sistemi: yapısal analiz ve tasarım örneği

### 2.1 Problem ve müşteri istekleri

İlk grup, kullanıcıların şehir bazında etraflarındaki etkinlikleri görebileceği ve yeni etkinlik ekleyebileceği bir Android mobil uygulaması geliştirdi. İlk toplantıda müşteri ile analist bir araya gelmiş; müşterinin istekleri uygulamaya özel kullanıcı hesapları, etkinliklerin ana ekranda listelenmesi ve her etkinliğin kapasite, isim, yer, zaman gibi ayrıntılarıyla birlikte yorum ve tartışmaların da görüntülenebilmesi olarak belirlenmişti.

İkinci toplantının özeti ekranda şöyleydi (ekrandan, 00:10:00): fizibilite çalışmalarının sonuçları müşteriyle paylaşılmış, önceki toplantıda müşterinin isteklerinde olağan dışı görülen kısımlar müşteriye bildirilmiş ve ekibin kendi çözümleri sunulmuştu. Analist uygulamayı programlamak için Java dilini önermiş, müşteri onaylamıştı. Müşterinin bu toplantıdaki istekleri, kullanıcıların etraflarındaki etkinlikleri ayrıntılarıyla birlikte ekleyebilecekleri bir modül (kapasite, isim, yer, zaman bilgileri kullanıcılarca girilecek) ve sade bir kullanıcı arayüzüydü.

Hoca toplantı tutanaklarının tamamının okunmasına gerek olmadığını, genel olarak ne yapıldığının görülmesinin yeterli olduğunu söyledi. Gantt diyagramında aşamalar ön hazırlık, analiz, tasarım, geliştirme ve test olarak verilmişti; hoca diyagramın hangi araçla çizildiğini sordu.

### 2.2 Analiz: modüller ve toplanacak bilgiler

Analiz aşamasında gereksinimler ve modüller belirlenmişti:

- Kullanıcı işlemleri modülü: sisteme kayıt olma, giriş yapma, üyelik bilgilerini görme.
- Etkinlik listeleme modülü: kullanıcıların şehir bazında etraflarındaki etkinlikleri listeleyen, uygulamanın ana ekranını oluşturan modül.
- Etkinlik ekleme modülü: kullanıcıların etkinlikleri ayrıntılarıyla ekleyebildiği modül.

Kullanıcıdan alınacak bilgiler de tanımlanmıştı: üyelik için isim, soyisim, yaş, şehir ve e-posta; etkinlik oluşturmak için etkinliğin adı, tarihi, zamanı, kapasitesi ve tanımı.

### 2.3 Veri akış diyagramları ve aşama düzeltmesi

Grup veri akış diyagramlarını "tasarım aşamasında çizdik" diye sundu. Hoca burada durup sordu: veri akış diyagramını hangi aşamada çizeriz? Cevap "tasarım" olunca düzeltti:

> **Hocanın vurgusu:** Veri akış diyagramlarını sistem analizi aşamasında çiziyoruz. Tasarım aşamasında yapı diyagramı çiziyoruz.

Grubun VAD seti üç düzeyden oluşuyordu:

- Taslak (bağlam) VAD: sistemin en basit hali; kullanıcı etkinliğe katılabilir ve yeni etkinlik oluşturabilir.
- Birinci düzey VAD: kullanıcı üye olduğunda bilgileri kaydedilir; etkinlikleri görüntüleyebilir, katılabilir, yeni etkinlik oluşturabilir; kendi etkinliklerini ve geçmişte gittiği ya da gelecekte gideceği etkinlikleri görebilir; etkinliğe katılmaktan vazgeçebilir. Bu işlemlerin gerektirdiği bilgiler veri tabanına gönderilir ya da oradan çekilir.
- İkinci düzey VAD: işlemler daha ayrıntılı tasarlanmış. Kullanıcı bilgilerini girerek giriş yapar ya da üye olur; girişten önce bilgiler kontrol edilir, üye değilse üye olabilir. Kullanıcı katılmak istediği etkinliğin bilgilerini girer, etkinlik aranır ve sonuçlar listelenir. Daha önce katılmadıysa etkinliğe katılır. Yeni etkinlik için etkinlik bilgileri girilir.

Hoca ikinci düzeyin mantığını gördüğünü söyleyip ayrıntıların geçilmesini istedi.

### 2.4 Tasarım: yapı diyagramı

Tasarım aşamasına geçen grup yapı diyagramını gösterdi (ekrandan, 00:15:00). Diyagramın modül hiyerarşisi şöyledir:

```text
Event Information System
├── Login
│   ├── Register                         (yukarı: "Registration is done")
│   └── Current User take Information    (aşağı: "User Information")
│       └── Check Database               (yukarı: "USER INFORMATION VALID")
└── Select Operation
    ├── Finding an Event                 (yukarı: "Event Lists")
    │   └── Join the Event
    │       ├── Save User's information          ("User Information")
    │       └── Cancel Participating in the Event ("User Information", "Event calendar")
    ├── Create New Event                 ("Event Information", "Event calendar")
    │   ├── Save the Event's information  ("Entering event information", "Event calendar")
    │   └── Cancel creating new Event     (yukarı: "Canceled successfully")
    └── Show past Events attended        (yukarı: "List of past Events attended")
        └── Events List                   (yukarı: "List of past Events attended")
```

Kökten `Login` ve `Select Operation` modüllerine giden bağlantıların üzerinde "ENTRY INFORMATION VALID" (giriş bilgisi geçerli) bilgisi taşınıyor. `Event Information System`, `Login`, `Select Operation` ve `Create New Event` kutularının altındaki eşkenar dörtgen, alt modüllerden birinin koşula göre seçildiğini gösteriyor. Bağlantı okları üzerindeki küçük daireli oklar modüller arasında taşınan bilgiyi gösteriyor.

Grup sunumda bu yapıyı şöyle anlattı: sistemde işlem yapmadan önce koşullu bir giriş vardır; kullanıcı kayıtlı değilse önce yeni kayıt oluşturur, sonra işlem seçimine geçer. İşlem seçiminin üç dalı vardır: etkinlik bulma (etkinlik bilgileri gelir, bulunursa etkinliğe katılma seçeneği vardır), yeni etkinlik oluşturma ve geçmiş etkinlikleri görme.

> **Ek bilgi (derste anlatılmadı):** Yapı diyagramında içi boş daireli küçük oklar veri çiftini (data couple), içi dolu daireli oklar ise kontrol bilgisini, yani işareti (flag) gösterir. "Kayıt tamamlandı" ya da "bilgi geçerli" gibi evet/hayır türü bilgiler normalde işaret olarak çizilir. Modülün altındaki eşkenar dörtgen koşullu çağrıyı (seçimi) gösterir.

### 2.5 ER diyagramı

Grup tasarımda bir ER diyagramı da gösterdi. Kullanıcı varlığının özellikleri isim, şifre, e-posta ve kullanıcı ID; etkinlik varlığının özellikleri başlık, açıklama, tarih, kapasite, etkinlik ID ve şehirdi. <!-- BELİRSİZ: altyazıda "depth" geçiyor, büyük olasılıkla "date" (tarih) --> Ayrıca kullanıcının katıldığı eski etkinlikleri göstermek için bir ilişki kurulmuştu. Hoca kolon isimlerinin elipsle çizilip çizilmediğini sordu; grup evet dedi. Diyagramın bir çevrim içi çizim aracıyla hazırlandığı belirtildi.

Grup ek olarak bir aktivite (akış) diyagramı da hazırlamıştı. Hoca akış diyagramını istemediğini, ama teşekkür ettiğini söyledi. Son olarak giriş sayfası, etkinlik listesi, etkinlik ayrıntısı, yeni etkinlik oluşturma, favoriler ve profil sayfalarından oluşan arayüz tasarımı gösterildi.

### 2.6 Teknik fizibilite: Firebase ve Android

Yazılım geliştirme kısmında görev alan üyeler teknik fizibiliteyi anlattı. Veri tabanı olarak Firebase seçilmişti; gerekçeleri şunlardı:

- Kullanıcı dostudur, sorguları standart SQL'e göre daha kolay anlaşılır.
- Android Studio ile kullanılabilecek kütüphanesi zengindir.
- Sorgu gecikmesi (latency) düşüktür, sorgulara hızlı yanıt verir.
- Küçük çaplı projeler için, çok fazla veri saklanmadığı sürece ücretsizdir.
- Android Studio ile bağlantısı kolaydır; ikisi de aynı şirketin ürünü olduğu için entegrasyonları rahattır.

Firebase'in iki bileşeni kullanılmıştı. Authentication, kullanıcının e-posta adresini ve şifresini kontrol ederek giriş yapmasını sağlar; telefon numarası ve popüler sosyal hesaplarla giriş seçenekleri de vardır. Cloud Firestore ise ekrandaki tanıma göre iOS, Android ve web uygulamalarının yerel SDK'lar aracılığıyla doğrudan erişebildiği, bulutta barındırılan bir NoSQL veri tabanıdır; belgeler içinde alt koleksiyonlar oluşturulabilir ve veri tabanı büyüdükçe ölçeklenen hiyerarşik veri yapıları kurulabilir (ekrandan, 00:20:00). Uygulamada etkinlik ve kullanıcı bilgileri burada saklanmıştı.

Uygulama platformu olarak Android seçilmişti, çünkü kullanıcılara ulaşmak kolaydır. Android uygulaması geliştirmek için Java ve Kotlin olmak üzere iki seçenek vardır; ekibin Java deneyimi daha fazla olduğu ve Java'nın kütüphanesi ve kaynağı daha bol olduğu için Java tercih edilmişti. Arayüz XML dosyalarıyla tasarlanıp koda bağlanmış <!-- BELİRSİZ: altyazıda "egzemeller", büyük olasılıkla XML -->, hatalar hata ayıklayıcıyla (debugger) çözülmüştü.

Müşteri değerlendirmesinde programın istenen görevi yerine getirdiği, etkinlik ekleme ve listelemenin kolay olduğu, arayüzün istendiği gibi sade olduğu belirtildi.

## 3. Dijital oyun mağazası: fizibilite ve diyagramların yeri

### 3.1 Sistem ve fizibilite

İkinci grup, oyunların fiziksel disk yerine internetten satın alındığı bir dijital oyun mağazası tasarladı. Sistemin amacı kullanıcının mağaza mağaza dolaşmaması, disklerin fiziksel zarar görmemesi ve kolayca oyun alabilmesiydi; ayrıca arkadaşlarla iletişim kurma gibi sosyal bir yönü vardı.

Fizibilite kısmı şöyle özetlendi:

- Teknik fizibilite: program Java ile geliştirilmiş, kod yedi sınıftan oluşuyordu.
- Ekonomik fizibilite: satılan her oyundan %20, oyun içi satın alımlardan (in-game transaction) %30 gelir öngörülmüştü. Çalışan maaşları çeyrek yıllık (Q: quarter, 3 ay) dönemler halinde verilmiş ve gelir arttıkça maaşların da arttığı gösterilmişti.
- Sosyal fizibilite: kolay ve güvenli kullanım hedeflenmiş, tanıtım için reklam planlanmıştı.
- Zaman fizibilitesi: Gantt diyagramında en çok zamanın kodlamaya gittiği görülüyordu.

### 3.2 Sistem analizi

Analiz kısmında sistemin amacı kolay kullanılabilen bir dijital oyun mağazası sunmak ve kullanıcıların arkadaşlarıyla iletişim kurmasını sağlamak olarak verildi. Sistemin elemanları mağaza, oyunlar, kütüphane, istek listesi, arkadaşlık sistemi ve hesap bilgileriydi. Analizin adımları şöyle anlatıldı:

- Bilgi toplama: piyasadaki benzer çevrim içi oyun kütüphaneleri incelendi.
- Gereksinimlerin belirlenmesi: incelenen sistemlere göre hangi yapı taşlarının kullanılacağı seçildi.
- Önceliklendirme: önce hesap bilgileri, en son arkadaşlık sistemi.
- Alternatif çözümlerin değerlendirilmesi: bazı platformlarda arkadaşlık sistemi ya da oyun içi eşya satışı vardı, bazılarında yoktu; artı ve eksilere bakılarak sade bir sistemde karar kılındı.

Sistem elemanları arasındaki ilişkiler de açıklandı: mağazadan satın alınan ürünler kullanıcının kütüphanesinde kullanılabilir (mağaza-kütüphane ilişkisi), mağazadaki ürünler istek listesine eklenebilir (mağaza-istek listesi ilişkisi).

### 3.3 Ardışıl diyagram, use case ve aşama sorusu

Grup önce bir ardışıl (sequence) diyagram gösterdi: mağazada oyunlar türüne ve puanına göre listelenip sıralanabiliyor, arkadaşa hediye edilebiliyor, istek listesine eklenebiliyor ve satın alınınca kütüphaneye ekleniyordu. Hoca projenin bütünüyle nesneye yönelik yapılıp yapılmadığını sordu; grup evet dedi.

Ardından use case diyagramı gösterildi (ekrandan, 00:30:00). Diyagramda iki aktör, Main, Mağaza, Kütüphane, Oyun, Hesap ve Arkadaş adlı elipsler ve bir veritabanı simgesi vardı; elipsleri bağlayan çizgilerin üzerinde "Mağaza", "Kütüphane", "Oyunlar", "Hesaplar", "İstek Listesi" gibi etiketler, iki aktör arasında da "Hediye" bağlantısı bulunuyordu.

Hoca bu noktada sordu: use case diyagramını hangi aşamada çizeriz? Grup önce "tasarım", sonra "analiz aşamasında prototip oluştururken" dedi. Hoca düzeltti:

> **Hocanın vurgusu:** Use case diyagramı prototip için değil, analiz aşamasında kullanıcının ne iş yaptığını öğrenmek için çizilir. Kullanıcının ne iş yaptığını doğru anladık mı, hangi işlemleri yapıyor, onu gösterir.

Hoca tasarımda neyin çizildiğini sordu; grup emin olamayınca, az önce gösterdikleri ardışıl diyagramı hatırlattı: ardışıl diyagram tasarıma aittir. Grup ikisini ters sıraya koymuştu.

> **Ek bilgi (derste anlatılmadı):** Kullanım durumu diyagramında elipsler genellikle aktörün sistemle yaptığı bir işi anlatan fiil öbekleriyle adlandırılır ("oyun satın al", "istek listesine ekle" gibi). Mağaza, oyun, hesap gibi isimler daha çok sınıf ya da alt sistem adıdır ve sınıf diyagramında yer alır. Veri tabanı da kullanım durumu diyagramında bir aktör ya da kullanım durumu olarak gösterilmez.

### 3.4 Müşteri değerlendirmesinin kurgusu

Grubun müşteri değerlendirmesinde müşterinin eksik bulduğu noktalar anlatıldı; örneğin oyunlara puan verme yalnızca kütüphane üzerinden yapılabiliyordu, müşteri bunun mağazadaki oyun profilinden de yapılabilmesini istemişti. Hoca bu bölümün nasıl olması gerektiğini açıkladı:

> **Hocanın vurgusu:** Müşteri değerlendirmesinde bir tarafa sistem analizindeki müşteri isteklerini (gereksinim belgesi gibi) koymanız, diğer tarafa bunlardan hangisinin gerçeklendiğini, hangisinin yapılamadığını yazmanız gerekir. Müşterinin bu konudaki görüşü de verilmelidir; yani değerlendirme sistem analiziyle karşılaştırmalı olmalıdır.

## 4. Takım elbise kiralama sistemi: ardışıl diyagramlar

### 4.1 Sistem tanımı ve fizibilite

Üçüncü grup bir takım elbise kiralama işletmesi için sistem geliştirdi. Sistem tanımı şuydu: elbiseleri görüntüleme, zamana göre ücretlendirme, teslim gecikmesinde ücret artırma, kullanım sırasında oluşan hasarda ücret artırma ve kiralanan kıyafeti raporlama modüllerine dayanarak müşterilere elbise kiralayan sistem.

Fizibilite çalışmasının sonuçları:

- Teknik fizibilite: ekibin eksiği yok; programlama dili olarak Java seçildi.
- Zaman fizibilitesi: Gantt diyagramında planlama, analiz, tasarım, geliştirme ve test evrelerine belirli günler verildi.
- Sosyal fizibilite (ekrandan, 00:35:00): çevre değerlendirmelerine göre insanların geneli yılda 3-4 kez giyeceği için takım elbise almaya sıcak bakmıyor, ama özel günlerde takım elbise giymek istiyor. Bu nedenle kiralama sistemi bir ihtiyaç olarak görülüyor ve sistemin beklentileri karşılayacağı düşünülüyor.
- Yasal fizibilite: sistem mevcut kanun ve yönetmeliklere uygun.
- Ekonomik fizibilite: sistemin kârlı olduğu görüldü.

### 4.2 Analiz ve sınıflar

Sistem analisti işleyişi anlattı. İşletme sahibi elbise ekleme modülüyle sisteme elbise ekler. Kiralama modülünde önce müşteri seçilir; müşteri yoksa eklenir. Ardından depo görüntülenir, bir elbise seçilir, kaç gün kiralanacağı belirlenir ve elbise kiralanır; sonunda rapor oluşur. İade modülünde de en sonda rapor oluşur, ancak elbisenin hasarlı olup olmadığı ve gecikme durumuna göre ücret artırılabilir. Elbise sınıfında ad, renk, model, beden ve fiyat bilgileri bulunur. Tasarım için metot adlarını da gösteren bir UML sınıf diyagramı hazırlanmıştı.

### 4.3 Ardışıl diyagramlar

Üç ardışıl diyagram anlatıldı:

- Elbise ekleme: bir elbise nesnesi oluşturulur ve elbise sınıfının içindeki statik elbiseler dizisine eklenir.
- Kiralama: elbise sınıfından elbiseler listesi, müşteriler sınıfından müşteriler listesi alınır. Bu ikisinden bir müşteri ve bir elbise seçilerek bir "kiralanmış" nesnesi oluşturulur. Elbise, tekrar kiralanamasın diye elbiseler listesinden çıkarılır. Yeni nesne kiralanmışlar listesine eklenir ve tutarı hesaplamak için tutar metodu çağrılır.
- Kiralama iadesi: kiralanmışlar listesi yazdırılıp bir kayıt seçilir ve iade edilir. İade edilince içindeki elbise elbiseler listesine geri eklenir. Sonunda raporlama yapılır.

### 4.4 Müşteri değerlendirmesi

Müşteri rolündeki üye değerlendirmeyi sözlü yaptı: programın açık, sade ve anlaşılır olması, hasar durumunun ve iade sürecinin iyi raporlanması, ceza ücretinin sistemli girilmesi, fiyatın uygunluğu ve teklif tarihi ile teslim tarihi arasındaki farkın tek eksik olması. Hoca burada da aynı uyarıyı yaptı: müşteri görüşünde bir tarafta sistem analistinin ya da SRS (yazılım gereksinim belirtimi) belgesinin istekleri, diğer tarafta gerçekleştirilenler olmalıydı. Sözlü anlatım değil, bu karşılaştırma bekleniyordu.

## 5. Kafe/restoran yönetim sistemi: VAD ve nesneye yönelik modeller birlikte

### 5.1 Sistem ve ekip

Dördüncü grup bir kafe/restoran için bilgi ve yönetim sistemi geliştirdi. Sistem finans yönetimi, bütçe yönetimi, çalışan bilgileri, stok yönetimi ve sipariş kayıtlarını kapsıyordu; hedef kullanıcılar yöneticiler ve çalışanlardı. Ekip rolleri anlatılırken hoca analist sayısının fazla olduğuna dikkat çekti. Gantt diyagramı MS Project'te hazırlanmıştı.

### 5.2 Ek çalışma olarak klasik VAD

Grup projeyi nesneye yönelik yaklaşımla tasarlamış, ancak başlamadan önce ek çalışma olarak klasik bir veri akış diyagramı da çizmişti (ekrandan, 00:45:00). Slaytta iki düzey vardı.

Özet (bağlam) düzeyi, başlığı "Kafe Yönetim Sistemi - Veri Akış Diyagramı":

```text
Müşteri  --Sipariş-->  Sipariş Yönetim Sistemi
Sipariş Yönetim Sistemi  --Fatura-->  Müşteri
Sipariş Yönetim Sistemi  --Sipariş-->  Barista, Mutfak
Barista, Mutfak  --Ürün-->  Teslimat Sistemi
Teslimat Sistemi  --Ürün-->  /Müşteri
```

1. düzey:

```text
Müşteri            --Sipariş-->         1.0 Sipariş Sistemi
1.0 Sipariş Sistemi --Sipariş-->        Barista, Mutfak
1.0 Sipariş Sistemi --Ücret-->          2.0 Finans Yönetimi
2.0 Finans Yönetimi --Fatura-->         Müşteri
2.0 Finans Yönetimi --Maaş-->           Barista, Mutfak
2.0 Finans Yönetimi --Malzeme İsteği--> 3.0 Stok Yönetimi
Ürün Tedarikçisi   --Malzeme-->         3.0 Stok Yönetimi
Barista, Mutfak    --Rapor-->           3.0 Stok Yönetimi
3.0 Stok Yönetimi  --Malzeme Durumu-->  Barista, Mutfak
Barista, Mutfak    --Ürün-->            4.0 Teslimat Sistemi
4.0 Teslimat Sistemi --Ürün-->          /Müşteri
```

Diyagramda "/Müşteri" biçimindeki ikinci kutu, aynı dış varlığın diyagramda ikinci kez çizildiğini gösteriyor. Grup bağlam ve birinci düzeyin yanında ikinci düzey VAD de hazırlamıştı.

> **Ek bilgi (derste anlatılmadı):** Bu diyagramda veri depoları (sürekli veri) gösterilmemiş; stok, sipariş ve bütçe kayıtları normalde 1. düzey VAD'de açık uçlu dikdörtgen ya da numaralı veri deposu olarak çizilir. Ayrıca sistemin içinde çalışan bir birim olan "Barista, Mutfak" bir dış varlık gibi kare ile çizilmiş; sistemin içindeki birimlerin yaptığı işler genellikle işlem olarak modellenir.

### 5.3 Kullanım senaryosu, UML sınıf ve ardışıl diyagram

Kullanım senaryosu diyagramında üç aktör vardı: müşteri, çalışan ve tedarikçi. Müşteri sipariş verir; "sipariş ver" kullanım durumu "menü seçme" ve "ödeme" kullanım durumlarını içerir (include). Çalışan stok durumuna bakar ve stok güncellemesi yapar; eksik malzeme isteği oluşturup ödemeyi yapar ve tedarikçiye gönderir. Müşteri sistemden faturayı ve ürünü teslim alır.

UML sınıf diyagramında `worker`, `order`, `stock item` ve `budget item` sınıfları ile veri tabanı bağlantısını sağlayan bir bağlantı sınıfı vardı. Sınıflar arasında kalıtım ya da başka bir ilişki yoktu; bütün bilgi bağlantı sınıfındaki get metotlarından alındığı için bu yapı tercih edilmişti. Her sınıfta özellikler ve metotlar gösterilmişti.

Ardışıl diyagramın akışı şöyleydi: müşteri çalışana sipariş verir; çalışan sipariş miktarına göre stok durumuna bakar. Stokta varsa gerekli malzemeler alınır, stok kendini günceller (malzeme azalır) ve stok durumu çalışana bildirilir; ürün müşteriye teslim edilir. Stokta yoksa müşteriye yalnızca "ürün stokta kalmamıştır" bildirimi gider. Siparişin faturasını çalışan alır ve tutar bütçeye eklenir. Bütçe sistemi çalışanların bilgisini de tutar ve her ay sonunda maaşları öder.

### 5.4 Gerçekleştirme

Veri tabanı olarak PostgreSQL seçilmişti: açık kaynak olduğu için aylık ödeme ya da lisans ücreti gerekmez, grubun bilgisi bu yöndedir ve öğeler arasındaki ilişkiler en iyi ilişkisel bir SQL veri tabanında saklanır. Kodlama Java ile yapılmıştı. Hoca test ekran çıktılarıyla mı yapıldı diye sordu; grup üç farklı bilgisayarda test ettiklerini söyledi.

## 6. Film değerlendirme sistemi: VAD kuralları ve sınıf yapısı

### 6.1 Müşteri talepleri ve modüller

Beşinci grubun sisteminde müşteri filmlerin yönetmen, yapım yılı, hikaye özeti gibi bilgilerini içeren ve kullanıcıya film öneren bir sistem istemişti. Kullanıcı filmlerin bilgilerini görüntüleyebilecek, kendi izleme listesine ekleyebilecek ve filmleri beğenebilecekti; beğeni sayısı diğer kullanıcılara tavsiye işlevi görecekti. İlk toplantıda belirlenen modüller: kayıt ve giriş, profil güncelleme, beğeni, izleme listesi ve görüntüleme.

### 6.2 Fizibilite

Fizibilite altı başlıkta ele alınmıştı: yazılım, donanım, ekonomik, zaman, sosyal ve yasal. Sunan üye fizibilitenin tanımıyla başlayınca hoca araya girdi:

> **Hocanın vurgusu:** Fizibilitenin ne olduğunu değil, gerçekleştirdiklerinizi anlatın; neleri seçtiniz, onu anlatın.

Grubun seçimleri şunlardı: veri tabanı PostgreSQL; donanım açısından fazla yük yok; ekonomik açıdan başlıca maliyet kalemi ekibin bilgisayarları, belli kullanıcı sayısına kadar çevrim içi veri tabanı ek yük getirmiyor, aylık yaklaşık 100 bin kullanıcıda maliyet 1000 dolara kadar çıkabiliyor. Zaman fizibilitesinde program ayrıntılı planlanmış, zaman çizelgesi Gantt diyagramı olarak hazırlanmış ve görevler Trello panosunda izlenmişti; kritik yol ve darboğazlar belirlenmişti. Sosyal fizibilite (ekrandan, 00:55:00) müşteriyle görüşmeden şu özellikleri çıkarmıştı: basit bir arayüz, kolay anlaşılabilirlik, hızlı çalışma, gerektiğinde yardım bulunması ve sistemi yapan ekibe en az ihtiyaç duyulması. Yasal fizibilitede sistemin kanun ve yönetmeliklere uygun olduğu ve fikri hak ihlali olmadığı görülmüştü.

### 6.3 Akış şeması ve VAD

Akış şeması algoritmanın temelini anlatıyordu: kullanıcı kayıtlıysa bilgileri girer, doğruluğu kontrol edildikten sonra sisteme girer; hesabı yoksa hesap oluşturur. Giriş sonrası isim, soyisim ve şifre bilgilerini güncelleyebilir; film oylama, izleme listesi oluşturma ve sıralama işlemlerini yapabilir.

Birinci düzey VAD hakkında grup iki kurala dikkat çekti:

- Varlıktan varlığa doğrudan veri aktarımı yapılmamış, aktarım araya bir işlem konarak sağlanmıştır.
- Diyagramda daha önce kullanılmış bir varlık tekrar çizilirken kenarına ek çizgi konmuş bir dörtgen kullanılmıştır.

Sistem için beş işlem tanımlanmıştı.

### 6.4 Use case ve senaryolar

Use case diyagramında kullanıcı profil güncelleme, film değerlendirme, izleme listesi oluşturma ve kayıt/giriş işlemlerini yapabiliyordu; ayrı bir yönetici girişi yoktu. Senaryolar tablo halinde verilmişti. Örnek senaryo: "Profil oluşturma"; aktör kullanıcı; ön koşul yok; kullanıcı adı, ad, soyad ve şifre girilerek üyelik tamamlanır.

### 6.5 Tasarım: sınıf diyagramı ve sunum sırası

Grup gerçekleştirmeye, veri tabanının fiziksel modeline geçince hoca durdurdu ve önce tasarım aşamasındaki sınıf diyagramını görmek istedi:

> **Hocanın vurgusu:** Önce analizi anlatacaksınız, sonra tasarımı anlatacaksınız. Kodlamaya geçmeden tasarımı anlatın.

Projede toplam 12 sınıf vardı: 8'i programdaki sayfalar, 1'i veri tabanı bağlantısı ve veri tabanı metotları, 2'si veri alışverişinde kullanılan `Kullanici` ve `Movie`, 1'i programın giriş noktası olan `MovieRatingSystem`. Ekrandaki örnek sınıf diyagramı (ekrandan, 01:00:00) şöyleydi:

```text
Movie
  - movieName: String
  - year: int
  - director: String
  - likes: int
  - genre: String[]
  - summary: String
  + getMovieName(): String, getYear(): int, getDirector(): String,
    getLikes(): int, getGenre(): String[], getSummary(): String
  + setMovieName(String), setYear(int), setDirector(String),
    setLikes(int), setGenre(String[]), setSummary(String)

Kullanici
  - username: String
  - name: String
  - surname: String
  - gender: String
  + getUsername(): String, getName(): String, getSurname(): String, getGender(): String
  + setUsername(String), setName(String), setSurname(String), setGender(String)

GununTavsiyesiEkrani            MovieRatingSystem
  + movie: Movie                  + kullanici: Kullanici
  main(String[] args)             main(String[] args)

GununTavsiyesiEkrani ---> Movie      (düz çizgi, açık uçlu ok)
MovieRatingSystem    ---> Kullanici  (düz çizgi, açık uçlu ok)
```

Çalışma mantığı: kullanıcı giriş yaptığında `Kullanici` sınıfından bir örnek oluşturulur ve program kapanana kadar veri tabanıyla iletişim bu örnek üzerinden yürür. Film ayrıntı sayfasına geçerken de bir `Movie` örneği üretilir ve veri aktarımı bu örnekle yapılır.

Örnek ardışıl diyagram, veri tabanına sorgu gönderen ortak metodu gösteriyordu: sorgu metni (string) metoda parametre olarak verilir, cevap `ResultSet` olarak alınır; bu metot programda yoğun kullanılıyordu. Gösterilen kod parçası, izleme listesindeki filmlerde türe göre arama yapıp sonuçları tabloda gösteriyordu: butona tıklanınca `actionPerformed` metodu çalışıyor, metin kutusundan tür adı alınıp veri tabanında aranıyordu.

### 6.6 Müşteri değerlendirmesi

Grup müşteri değerlendirmesinde programın nasıl çalıştığını anlatmaya başlayınca hoca yine aynı noktayı vurguladı: istenen özelliklerin yapılıp yapılmadığını gösteren bir kontrol listesi bekleniyordu. Müşteri geri dönüşleri olarak kullanım dokümantasyonu sayesinde kolay adaptasyon, sade arayüz ve filmlere dağınık araştırma yapmadan ulaşma anlatıldı.

## 7. Sanal market sistemi: kullanım senaryoları

### 7.1 Sistem

Altıncı grup bir sanal market sistemi geliştirdi. Ürün çeşitliliği, indirimler, hızlı teslimat ve zaman tasarrufu nedeniyle insanların sanal marketlere yöneldiği, sistemin özellikle evden çalışanlara, yaşı ilerlemiş bireylere ve risk altındaki kişilere hizmet edeceği belirtildi. İki kullanıcı grubu vardı:

- Müşteri: iletişim bilgileriyle kayıt olur (bilgileri veri tabanına eklenir), giriş yapar, kategoriye göre filtreleme yapar, ürünleri sepete ekler ya da çıkarır, sipariş verir, satın aldıktan sonra ürünleri değerlendirir, önceki değerlendirmeleri görür; sistem ilgisini çekebilecek ürünleri önerir.
- Satıcı: ürünleri kategori, stok ve fiyat bilgileriyle ekler, günceller ya da siler.

### 7.2 Analiz ve fizibilite

Sistem analizinde hem satış yapacak kişilerle hem potansiyel tüketicilerle görüşülmüş, ürünlerin önceki puanlarını görmeye imkan veren ve zaman tasarrufu sağlayan bir sistem gerektiği sonucuna varılmıştı. Müşteri talepleri metotlar halinde gruplanmıştı: kategoriye göre filtreleme, ürün ayrıntısını görüntüleme, sepet oluşturma ve görüntüleme, sepetten ürün çıkarma, ürün puanlama ve ürün önerme. Ekrandaki "Sistem Analizi" slaytında (ekrandan, 01:10:00) problem çözümü için en uygun ve en kısa yolun saptandığı, ayrıntılı bilgi için sistem analizi yöntemlerinden müşteriyle çevrim içi görüşmenin seçildiği ve gereksinim analizinin yapıldığı yazıyordu.

Teknik fizibilitede Java ve nesneye yönelik yaklaşım, arayüz için Java Swing, veri tabanı olarak MySQL seçilmişti; alıcı ile satıcı arasındaki iletişim için sunucu kiralanmıştı. Ekonomik fizibilitede uygulama süresi 40 gün olarak belirlenmiş, personel giderleri günlük bazda, yazılım ve sunucu giderleri aylık olarak hesaplanmıştı. Yasal fizibilitede müşterilerin kullanıcı adı ve şifre gibi özel bilgilerinin korunması ve veri tabanında güvenli saklanması gözetilmişti.

### 7.3 Kullanım senaryoları

Grubun kullanım senaryoları, senaryo metninin nasıl yazılacağına iyi bir örnektir:

- Senaryo 1, kayıt olma. Aktörler: kullanıcı ve sistem. Sağlanması gereken koşullar: kullanıcı adı, şifre ve adres bilgileri. "İptal" tuşuyla giriş sayfasına dönülebilir. Alternatif senaryo: tüm alanların doldurulması zorunludur, eksik bilgi girilirse uyarı alınır.
- Senaryo 2, satıcının (admin) ürün eklemesi. Aktörler: admin ve sistem. Ön koşul: adminin doğru kullanıcı adı ve şifre girmesi. Temel olay akışı: admin girişi seçilir, kullanıcı adı ve şifre formu doldurulur, giriş yapılır; ürünün kategori, ID, fiyat ve stok bilgisi girilip "ekle" tuşuna basılarak ürün sisteme eklenir.
- Senaryo 3, ürün çıkarma ya da güncelleme. Aktörler: satıcı ve sistem. Temel olay akışı: satıcı sayfasındaki tabloda listelenen ürünlerden biri seçilir, "güncelle" ya da "çıkar" butonuna basılır.
- Senaryo 4, sipariş verme. Aktörler: kullanıcı ve sistem. Temel olay akışı: müşteri giriş yapar, kategori seçer, açılan sayfadan bir ürünü sepete ekler; sepet sayfasında eklenen ürünleri görür, vazgeçtiği ürünü çıkarır; sepetin yanında önerilen ürünü de ekleyebilir; "ödeme yap" butonuna basar. Alternatif senaryolar: bakiye yetersizse ödeme yapılamaz ve sipariş iptal edilir; ürün stokta yoksa sepete eklenirken hata verir.
- Senaryo 5, siparişi değerlendirme. Aktörler: müşteri ve sistem. Temel olay akışı: sipariş verildikten sonra müşteri otomatik olarak puan verme sayfasına yönlendirilir, 1 ile 5 arasında puan verir ve ana sayfaya döner.

### 7.4 Tasarım diyagramları ve değerlendirme

Ardışıl diyagramlar kayıt olma ve müşterinin veri tabanına eklenmesini; adminin satıcı paneline girip ürün eklemesini, çıkarmasını ve güncellemesini; kullanıcının giriş, kategori seçme, sepete ekleme ve çıkarma, önerilen ürünü ekleme, ödeme ve puan verme akışını gösteriyordu. Kavramsal sınıf diyagramında oluşturulan sınıflar, UML sınıf diyagramında ise bütün sınıflar, metotları ve veri tabanı bağlantıları gösterilmişti.

Değerlendirme bölümünde müşterinin talep ettiği fonksiyonların (filtreleme, ürün ayrıntısı, sepet, sepetten çıkarma, puanlama, öneri) hepsinin gerçekleştirildiği belirtildi. Kullanıcı geri dönüşlerinde artılar (kullanışlı arayüz, filtreleme, sepeti görüntüleme, puan görüntüleme, öneri sistemi, geniş ürün yelpazesi) ve eksiler (eski siparişleri görememe, yorum kısmının olmaması, indirim miktarını görememe) sıralandı. Hoca grubun da nesneye yönelik yaklaşımla çalıştığını teyit etti.

## 8. Özel ders platformu: kavramsal ve UML sınıf diyagramı, veri tabanı, Gantt

### 8.1 Sistem ve fizibilite

Yedinci grup öğrencilerin internet üzerinden özel ders satın alabildiği bir platform geliştirdi. Modüller: kullanıcı kaydı, girişi ve yönetimi; öğretmenin ders eklemesi; öğrencinin ders satın alması; öğrencinin öğretmeni derecelendirmesi; öğretmenin rapor oluşturması. Dersler video bağlantısı olarak ekleniyor, öğrenci öğretmenin puanına ve fiyatına bakarak bakiye yükleyip ders satın alabiliyordu.

Teknik fizibilitede Java, arayüz için JavaFX, IDE olarak IntelliJ, veri tabanı olarak SQLite seçilmişti. Ekonomik fizibilitede proje müdürü, sistem analisti ve uygulama geliştirici ücretlerine lisans ücretleri eklenince toplam yaklaşık 18.295 lira bulunmuştu.

Zaman fizibilitesi slaytı (ekrandan, 01:20:00) işlerin tahmini süresini 45 gün olarak veriyordu:

| İş | Süre | Başlangıç | Bitiş |
|---|---|---|---|
| İlk Toplantı | 1 gün | 30.03.2021 | 31.03.2021 |
| Fizibilite Analizleri | 3 gün | 01.04.2021 | 04.04.2021 |
| Organizasyon Şeması | 2 gün | 05.04.2021 | 07.04.2021 |
| Sistem Analizi | 4 gün | 08.04.2021 | 12.04.2021 |
| 2. Toplantı | 2 gün | 13.04.2021 | 15.04.2021 |
| Tasarım | 8 gün | 16.04.2021 | 24.04.2021 |
| Gerçekleştirme | 12 gün | 25.04.2021 | 07.05.2021 |
| Test | 4 gün | 08.05.2021 | 12.05.2021 |
| 3. Toplantı | 1 gün | 13.05.2021 | 14.05.2021 |

Tablodaki her süre bitiş tarihi ile başlangıç tarihi arasındaki farka eşittir (örneğin Tasarım: 24.04 − 16.04 = 8 gün). İşler ardışık; her iş bir öncekinin bitişinin ertesi günü başlıyor. İlk işin başlangıcından son işin bitişine kadar geçen süre 30.03.2021'den 14.05.2021'e 45 gündür, iş sürelerinin toplamı ise $1+3+2+4+2+8+12+4+1 = 37$ gündür (python ile kontrol edildi). Aradaki 8 günlük fark, sekiz iş geçişinin her birinde araya giren birer günden gelir. En uzun iş 12 günlük gerçekleştirmedir; grup da en çok sürenin kodlamaya gittiğini söyledi.

### 8.2 Analiz: piyasa incelemesi, use case, kavramsal sınıf

Analizde piyasadaki benzer uygulamaların fonksiyonları ve işleyişleri incelenmiş, bunlara göre sistemin işleyişi ve farklılaştırıcı avantajları belirlenmişti. Kullanım senaryosu diyagramı, programı kullanan profillerin (öğrenci, öğretmen, admin) hangi fonksiyonlara sahip olduğunu gösteriyordu: öğrenci için giriş, kayıt, profil düzenleme, bakiye ekleme; öğretmen için ders ekleme, silme, fiyat belirleme.

Grup sınıf diyagramlarını iki düzeyde ayırmıştı:

- Kavramsal sınıf diyagramı: sınıfların neyi temsil ettiğini, aralarındaki ilişkileri ve genel özelliklerini gösterir.
- UML sınıf diyagramı: programın bütün sınıflarını, her sınıfın metotlarını ve sınıflar arasındaki ilişkileri daha ayrıntılı gösterir.

Ardışıl diyagram ise sınıf diyagramından farklı olarak nesneler arasındaki etkileşimi zamana göre, bilgi akışı ve etki-tepki olayları biçiminde gösterir. Grup kendi diyagramındaki bir eksiği de belirtti: öğrenci ders isteği gönderdiğinde uygunluk kontrolü yapılabilmesi için öğretmenin ders ekleme adımının diyagramda yer alması gerekiyordu.

### 8.3 Veri tabanı tasarımı

Program nesne tabanlı olduğu için ilişkisel bir veri tabanı (SQLite) seçilmişti. Üç kullanıcı tipi, ders ve konu nesneleri karşılık gelen tablolara dönüştürülmüştü. Ders ve konu gibi ilişkili tablolar yabancı anahtar (foreign key) ile bağlanmıştı. Öğretmen oylaması ve ders kayıtları gibi çoka çok (many-to-many) ilişkiler için ayrı ilişki tabloları oluşturulmuştu. Veri tabanı işlemlerini kolaylaştırmak için tablolardaki birincil anahtar (primary key) koddaki nesnelere de alan olarak eklenmişti.

Yazılım teknolojileri Java 16, JavaFX 16 ve SQLite'tı. Açık kaynak bir OpenJDK dağıtımı ve grafik arayüz için OpenJFX seçilmişti. Proje çevrim dışı bir veri tabanıyla gerçeklenmiş, çevrim içi sunulması durumunda açık kaynak ve yüksek performanslı olduğu için PostgreSQL düşünülmüştü. Performansı bozmadığı sürece açık kaynak yazılım seçmek lisans maliyetini ortadan kaldırmıştı.

### 8.4 Müşteri değerlendirmesi

Müşteri değerlendirmesi slaytında (ekrandan, 01:25:00) istenen dersin satın alınıp o konuda kolayca bilgi edinildiği, öğretmenin ders raporunda dersi kaç kişinin aldığını görebildiği, öğrencinin istediği zaman istediği dersi izleyebildiği yazıyordu; müşteri, listelenen derslerin öğretmen derecelendirmesine göre sıralanmasının sonraki sürüme eklenmesini istiyordu. Grup gerçekleştiremediği işleri de ayırdı: bakiyenin yalnız yüklenebilmesi (çekilememesi) ve derslerin kategorilere göre sıralanamaması. Sunum sonunda hoca analiz ve tasarım diyagramlarına (kavramsal sınıf, UML sınıf, ardışıl diyagram) geri dönülmesini istedi ve bunları tek tek gördü.

## 9. Freelance hizmet sistemi: üç kullanıcı tipi ve sınıf diyagramı

### 9.1 Sistem tanımı

Son grup bir freelance hizmet sistemi sundu. Ekrandaki tanım (ekrandan, 01:30:00): freelance sistemi kullanıcıların hizmete ya da müşteriye ulaşma süresini çok büyük ölçüde azaltan, müşteri-satıcı ilişkilerini en aza indirgemeye çalışan, geri bildirime çok önem verilen ve gerekli aksiyonların en kısa zamanda alındığı, kullanıcı memnuniyetini en üstte tutan bir alışveriş sistemidir. Kullanıcılar müşteri ve satıcı olarak ikiye ayrılır: satıcı yapacağı hizmetleri listeler, müşteri listelenen hizmetlerden istediğini satın alır. Beklenmeyen bir durum çıkarsa sistemin üçüncü kullanıcısı olan moderatör devreye girer; moderatör kullanıcılar arasındaki iletişimi en aza indirerek soruna en hızlı şekilde çözüm bulmayı amaçlar.

Ekip yapısında dört ana rol tanımlanmıştı: proje yöneticisi (projenin yönetimi, kontrolü, açılması ve kapatılması), analist (kurumun ihtiyaçlarına uygun çözümlemeler), tasarımcı ve uygulama geliştirme uzmanı (iş ihtiyaçlarına göre yazılım tasarlama ve geliştirme, mevcut sistemlerin performansını izleme ve iyileştirme). Teknik fizibilite yazılım ve donanım olmak üzere iki kısımda, yasal fizibilite kullanılan araçların lisanslarının nereden temin edildiği açısından incelenmişti. Gantt diyagramı analiz, tasarım, geliştirme ve test başlıklarına ayrılmış, alt işler ve kilometre taşları gösterilmişti.

### 9.2 Sınıf diyagramı ve program yapısı

Program konsol tabanlıydı. Açılışta veriler dosyalardan okunup her nesne bellekte (RAM'de) listelerde tutuluyor, böylece veri tabanı benzeri bir yapı kuruluyordu. Sınıf diyagramından görünen kısım (ekrandan, 01:35:00):

```text
InformationSystem
  - urunlerListesi: UrunListesi
  - musterilerListesi: MusteriListesi
  - freeListesi: FreelancerListesi
  - sipList: SiparisListesi
  - sorList: SorunListesi
  - mod: Moderator[]
  - freesayac: int
  + main(String[]): void

Urun
  - ID: int, urunAdi: String, fiyat: double, aciklama: String,
    sure: String, puan: double, yorumSayisi: int
  + Urun(), Urun(int ID, String urunAdi, double fiyat, String aciklama, String sure)
  + Puanla(double gelenpuan)
  + get/set metotları, toString(): String

UrunListesi
  - urunler: Urun[]
  + UrunListesi(), UrunEkle(Urun urun), UrunleriListele(),
    urunAra(int urunID): Urun, urunAra(String urunAdi): UrunListesi,
    urunListesiDosyayaYaz(), urunListesiDosyadanOku()

SorunListesi
  - sorunlar: Sorun[]
  + SorunListesi(), SorunEkle(Sorun yeniSorun), SorunlariListele(),
    tamamlanmamisSorunListele(), sorunaBak(int sira),
    siradanTamamla(int sira, boolean hakliMi)

Sorun
  - sorunSahibi: Musteri, sorunluSiparis: Siparis,
    problem: String, tamamlandi: boolean

MusteriListesi
  - musteriler: Musteri[]
  + MusteriListesi(), musteriEkle(Musteri musteri), musterileriListele(), ...

Urun  <>---- UrunListesi        (içi boş eşkenar dörtgen: bütün-parça)
UrunListesi, SorunListesi, MusteriListesi, ... - - -> InformationSystem  (kesikli ok)
Sorun - - -> SorunListesi, Musteri - - -> MusteriListesi                 (kesikli ok)
```

`Urun` sınıfındaki `Puanla` metodu, müşterinin verdiği yeni puanı ürüne daha önce verilen puanların ortalamasıyla birleştirip yeni ortalamayı hesaplamak için kullanılıyordu.

> **Ek bilgi (derste anlatılmadı):** Böyle bir yürüyen ortalama, önceki ortalama $\bar{p}$ ve yorum sayısı $n$ ise yeni puan $x$ geldiğinde $\bar{p}_{yeni} = \dfrac{n\,\bar{p} + x}{n+1}$ ile hesaplanır ve ardından $n$ bir artırılır. Bu yüzden sınıfta hem `puan` hem `yorumSayisi` alanının tutulması gerekir.

### 9.3 Use case ve değerlendirme

Use case diyagramında müşteri hesap oluşturma ve giriş dışında bakiye yükleme, sipariş verme, geçmiş siparişleri listeleme ve sorun bildirme işlemlerini yapıyordu. Freelancer üye olup giriş yapabiliyor, diğer freelancer'ları listeleyebiliyor, sisteme ürün (hizmet) ekleyip müşterilerin siparişlerine bakarak teslim edebiliyordu. Moderatör giriş yapıp müşterilerin bildirdiği sorunları listeliyor, inceliyor ve müşteri haklıysa para iadesi yaptırıyordu.

Müşteri beklentileri ve yapılanlar bir tabloda karşılaştırılmıştı: bakiye görüntüleme ve ekleme, sipariş sonrası puanlama, geçmiş siparişleri listeleme, memnun olunmayan sipariş için geri bildirim ve para iadesi yapılmış; moderatör geri bildirime göre iadeyi onaylıyor ya da reddediyordu. Her freelancer'ın yalnız kendi yeteneğine uygun işleri yapması isteği karşılanamamış (her freelancer her işi yapabiliyor), iade sonrası freelancer bakiyesinin azalması da gerçekleştirilememişti. Bu grup, hocanın diğer gruplardan beklediği "istenen - yapılan" karşılaştırmasına en yakın değerlendirmeyi sundu.

## 10. Hocanın geri bildirimlerinden çıkan genel kurallar

Sunumlar boyunca hocanın yaptığı düzeltmeler, dönem boyunca anlatılan yaşam döngüsü bilgisinin uygulamadaki karşılığını toparlıyor:

- Diyagramların aşamaları:
  - Yapısal yaklaşım: VAD analizde, yapı diyagramı tasarımda çizilir. ER diyagramı analizde başlar, tasarımda ayrıntılanır.
  - Nesneye yönelik yaklaşım: use case diyagramı ve senaryoları analizde, ardışıl diyagram tasarımda çizilir. Kavramsal sınıf diyagramı analizin, ayrıntılı UML sınıf diyagramı tasarımın ürünüdür.
- Use case diyagramının amacı prototip değildir; kullanıcının yaptığı işleri doğru anlayıp anlamadığımızı göstermektir.
- Sunumda ve raporda sıra analiz, tasarım, gerçekleştirmedir. Kodlamaya tasarım diyagramları gösterildikten sonra geçilir.
- Fizibilite bölümünde kavramın tanımı değil, grubun yaptığı seçimler ve gerekçeleri yazılır.
- Müşteri değerlendirmesi, gereksinim belgesindeki (SRS) isteklerle gerçekleştirilenlerin karşılaştırıldığı bir kontrol listesi olmalı; yapılamayanlar da açıkça belirtilmeli ve müşterinin görüşü eklenmelidir.
- İstenmeyen ek diyagramlar (ör. akış diyagramı) değerlendirmenin odağı değildir; beklenen diyagram seti seçilen yaklaşıma uygun olmalıdır.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:12:28): Veri akış diyagramını hangi aşamada çizeriz?

> **Cevap (derste verildi):** Sistem analizi aşamasında. Tasarım aşamasında ise yapı diyagramı çizilir.

**Soru 2** (derste sözlü, 00:16:14): ER diyagramında kolon (özellik) isimleri elipsle mi çizilir?

> **Cevap (derste verildi):** Grubun diyagramında özellikler elipsle çizilmişti ve grup bunu onayladı.

**Soru 3** (derste sözlü, 00:29:34): Use case diyagramını hangi aşamada çizeriz? Tasarımda hangi diyagramı çizeriz?

> **Cevap (derste verildi):** Use case diyagramı analiz aşamasında, kullanıcının ne iş yaptığını, hangi işlemleri yaptığını doğru anladığımızı göstermek için çizilir; prototip için çizilmez. Tasarımda ardışıl (sequence) diyagram çizilir.

**Soru 4** (derste sözlü, 00:31:24 ve 00:39:30): Proje raporundaki müşteri değerlendirmesi bölümü nasıl kurulmalıdır?

> **Cevap (derste verildi):** Bir tarafta sistem analizindeki müşteri istekleri (gereksinim belgesi / SRS), diğer tarafta bunlardan hangilerinin gerçekleştirildiği ve hangilerinin yapılamadığı yer almalı; müşterinin görüşü eklenmeli. Değerlendirme sözlü bir memnuniyet anlatımı değil, kontrol listesi biçiminde bir karşılaştırma olmalıdır.

**Soru 5** (ekrandan, 01:20:00): Özel ders platformunun Gantt tablosunda iş süreleri toplamı ile projenin toplam süresi neden farklıdır?

> **Çözüm (derste verilmedi):** Her iş süresi bitiş − başlangıç farkıdır ve süreler toplamı $1+3+2+4+2+8+12+4+1 = 37$ gündür. Her iş, bir öncekinin bitişinin ertesi günü başladığı için sekiz geçişte birer gün eklenir: $37 + 8 = 45$ gün. Bu da 30.03.2021 ile 14.05.2021 arasındaki farka eşittir ve slayttaki 45 günlük tahmini doğrular (python ile kontrol edildi).

## Dersin Toparlaması

Bu derste dönem boyunca öğrenilen sistem analizi ve tasarımı yöntemleri, sekiz grubun gerçekçi projeleri üzerinden uygulamalı olarak gözden geçirildi. Gruplar ön inceleme ve fizibiliteden başlayıp analiz, tasarım, gerçekleştirme ve müşteri değerlendirmesine kadar bütün yaşam döngüsünü sundu. Yapısal yaklaşımın örnekleri (bağlam ve düzeyli VAD'ler, yapı diyagramı, ER diyagramı) ile nesneye yönelik yaklaşımın örnekleri (use case diyagramı ve senaryoları, kavramsal ve UML sınıf diyagramları, ardışıl diyagramlar) yan yana görüldü.

Hocanın düzeltmeleri iki noktada toplandı: her diyagram doğru aşamada çizilmeli (VAD ve use case analizde; yapı diyagramı ve ardışıl diyagram tasarımda) ve müşteri değerlendirmesi gereksinimlerle gerçekleşenlerin karşılaştırması olmalı. Bu ilkeler hem proje raporlarının hem de sistem analizi ve tasarımı sorularının temelini oluşturur.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
