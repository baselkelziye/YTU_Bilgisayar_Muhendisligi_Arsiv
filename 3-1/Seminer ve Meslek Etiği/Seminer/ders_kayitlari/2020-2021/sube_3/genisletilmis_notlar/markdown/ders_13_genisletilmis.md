# Ders 13 Genişletilmiş Notu: Öğrenci Sunumları: Li-Fi Teknolojisi ve Asus; Yaşam Boyu Öğrenme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin İşleyişi
- 2. Sunum: Li-Fi (Light Fidelity) Teknolojisi
- 3. Sunum: Asus Şirketi
- 4. Sunum Sonrası: Asrock, TUF ve AnandTech
- 5. Yaşam Boyu Öğrenme
- 6. Yaşam Boyu Öğrenme Üzerine Alıntılar
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin İşleyişi

Bu ders, öğrenci sunumlarının son haftalarından biridir. İki öğrenci kısa sunumlarını yaptı; birinin yansılarını hoca kendi bilgisayarından paylaştı, diğeri ekranını kendisi paylaştı. Hoca sunumlar için süre tuttu ve her sunumdan sonra soru-cevaba zaman ayırdı. Önce dinleyicilerden soru bekledi, gelmediğinde kendisi soru sordu ya da konuyu genişleten bilgiler verdi. Sunumlar bittikten sonra hoca, ders notlarında henüz işlemediği üç konudan (yaşam boyu öğrenme, girişimcilik, sürdürülebilir kalkınma) ilkine, yaşam boyu öğrenmeye geçti.

## 2. Sunum: Li-Fi (Light Fidelity) Teknolojisi

### 2.1 Tarihçe

Li-Fi, "Light Fidelity" kısaltmasıdır ve görünür ışıkla veri aktarımına dayanır. Sunan öğrenci, fikrin kökünü 1880'lerde Graham Bell'in icat ettiği fotofona bağladı. Fotofondan sonra bu yaklaşım uzun süre sessizliğe gömüldü. Günümüze yakın ilk büyük çalışma 2003'te Japonya'da bir üniversitenin laboratuvarında yapıldı: görünür frekansta LED ışığıyla ilk kez veri aktarıldı.

Sunuma göre ardından bir telekomünikasyon enstitüsü ile Siemens'in ortak çalışmasında LED ışığıyla yaklaşık 5 metrelik mesafede saniyede 500 megabit hıza ulaşıldı; mesafe uzadıkça hız düştü ve yaklaşık 100 megabite indi. <!-- BELİRSİZ: altyazıda mesafe "5 metrekare" diye geçiyor; enstitünün adı anlaşılmıyor --> Son olarak 2011'de Edinburgh'da düzenlenen TED Global konferansında Harald Haas, Li-Fi teknolojisini resmî olarak duyurdu.

> **Ek bilgi (derste anlatılmadı):** Bell'in fotofonu büyük olasılıkla sesi bir ayna yüzeyinde titreştirip güneş ışığına bindiren ve uzaktaki bir selenyum hücresiyle yeniden sese çeviren bir düzenekti. Bu yüzden ışıkla kablosuz iletişimin ilk örneklerinden sayılır. Büyük olasılıkla Haas'ın 2011 konuşmasından sonra "Li-Fi" adı yaygınlaştı; teknolojinin genel adı "görünür ışık iletişimi" (visible light communication, VLC) olarak da geçer.

### 2.2 Çalışma prensibi

Hocanın paylaştığı "Çalışma Prensibi" yansısında şu maddeler vardı (ekrandan, 00:10:00):

- Li-Fi teknolojisi de Wi-Fi gibi veriyi elektromanyetik yolla aktarır, ancak bunu yaparken radyo dalgaları yerine görünür frekanstaki ışığı kullanır.
- Donanım olarak bir foto-alıcı ve ışık sinyalini işleyebilen bir ekipman kullanılır.
- LED lambaların yarı iletken özellikleri kullanılarak gönderilen enerji, insanların algılayamayacağı kadar kısa sürelerde azaltılıp artırılabilir.
- Bu enerji farkları bir fotodiyot ile toplanır ve işlenerek binary tipi veriye dönüştürülür.

Öğrenci bunu Wi-Fi ile kıyaslayarak açıkladı. Wi-Fi'de nasıl bir kablosuz alıcı ve onu işleyen bir kart varsa, Li-Fi'de de bir foto-alıcı ve ışık sinyalini işleyen bir ekipman vardır. Sinyal iletebilmek için ışıkta bir dalgalanma olması gerekir. LED lambalar bu dalgalanmayı insan gözünün fark edemeyeceği kadar kısa sürelerde yapabildiği için ışık sabit yanıyormuş gibi görünürken veri taşınır. Alıcıdaki fotodiyot bu enerji farklarını toplar, sinyal işlenir ve kullanılabilir veriye dönüşür.

Sonraki yansıda bir sistem diyagramı vardı. Öğrenciye göre lamba sürücüsüne (lamp driver) kadar olan kısım Wi-Fi ile aynıdır; yalnız sonraki ekipman değişir, mantık aynı kalır. Yayıcı olarak bir LED lamba kullanılır, fotodetektörle alınan veri bir sinyal işleme sürecinden geçerek bilgisayara aktarılır.

### 2.3 Wi-Fi'ye göre avantajları

Öğrencinin saydığı avantajlar şunlardır:

- Veri iletişimi ve aydınlatma aynı cihaz üzerinden sağlanır. (Öğrenci bunun dezavantaj yarattığı durumlar olduğunu da belirtti: gece internet kullanırken ışığın açık olması gerekir.)
- Radyo dalgası kullanılmaz. Öğrenciye göre Wi-Fi'nin zararı da ancak çok uzun süreli maruziyette görülür, ama Li-Fi'de bu zarar sıfıra iner.
- Sunuma göre 224 Gbit/s'ye kadar hıza ulaşabilir; öğrenci bunu en hızlı Wi-Fi'nin yaklaşık 200 katı olarak andı.
- Tek dağıtıcı ile birçok cihaza iletim yapılabilir; tek şart cihazın ışığı görmesidir. Bu yüzden nesnelerin interneti (IoT) alanında büyük kolaylık sağlar.
- Daha güvenlidir, çünkü iletişim yalnız ışık ile cihaz arasında olur.
- Maliyeti düşüktür.

### 2.4 Dezavantajları

- Lambanın sürekli açık olması gerekir; geceleri çalışmak zorlaşır.
- Işığın fiziksel özelliği nedeniyle duvarın arkasına geçemez. Wi-Fi'deki gibi arka odadan bağlanılamaz, yalnız ışığın gördüğü yerlerden bağlanılabilir.

Öğrenciye göre teknoloji şu sıralar daha çok ofislerde ve uçaklarda kullanılmak üzere geliştirildiği için bu kısıt büyük bir sorun yaratmıyor.

### 2.5 Hız karşılaştırması

Son yansıda Bluetooth, Wi-Fi, 4G, USB 3.0 ve Li-Fi'nin hızlarını karşılaştıran bir çubuk grafik vardı (ekrandan, 00:15:00, yansı küçük resmi). Öğrenci Bluetooth'un eski ve yavaş bir teknoloji olduğunu, Wi-Fi'nin ve ondan biraz daha hızlı 4G'nin internet iletim teknolojileri olduğunu söyledi. Bilgisayara takılan USB 3.0'ın hızı 5 Gbit/s'ye kadar çıkarken Li-Fi'nin 10 Gbit/s'ye kadar ulaşabildiğini, yani bir USB bağlantısından bile hızlı olduğunu belirtti. <!-- BELİRSİZ: altyazıda bu cümlede "Wi-Fi teknolojisinin hızı 10 GB'e kadar" geçiyor; bağlamdan büyük olasılıkla Li-Fi kastediliyor; grafikteki değerler karede okunamıyor -->

> **Ders sonrası not:** Sunumda iki farklı hız değeri geçti: 224 Gbit/s ve grafikte 10 Gbit/s. 224 Gbit/s büyük olasılıkla laboratuvar koşullarında ulaşılan bir rekordur; grafikteki değer daha gerçekçi bir karşılaştırma içindir. USB 3.0'ın 5 Gbit/s hızı bit cinsindendir, altyazıdaki "GB" yazımı byte değil, gigabit olarak okunmalıdır.

Kaynakça yansısında bir Türkçe teknoloji haber sitesindeki "Wi-Fi'ın yerini alacak Li-Fi teknolojisi nedir" yazısı ile Wikipedia'nın "Li-Fi" ve "Visible light communication" maddeleri vardı (ekrandan, 00:15:00). Öğrenci, zaman yetmediği için fotofona fazla değinemediğini söyleyip merak edenler için sohbete bir bağlantı bıraktı.

### 2.6 Soru-cevap

**Soru:** Li-Fi insana sağlık açısından zarar veriyor mu?
**Cevap:** Sunan öğrenciye göre hayır, çünkü bilinen LED lambalarla çalışıyor. Wi-Fi radyo dalgası kullandığı için düşük de olsa bir zararı var, ama o da çok uzun süreli maruziyetten kaynaklanıyor.

Hoca bu konuya ekleme yaptı. Kablosuz ağların radyo dalgalarıyla çalıştığını, elektrik-elektronik alanındaki bazı hocaların bile akşam yatarken kablosuz modemi kapatmayı önerdiğini söyledi; bu açıdan ışık çok daha sağlıklı sayılabilir. Tek olası etki, belirli bir ışık frekansına uzun süre maruz kalmanın gözleri yorabilmesi ve uyku düzenini biraz etkileyebilmesidir; hoca bunu jet lag ile ilişkilendirilen bir durum olarak andı ve bunların daha seyrek, daha küçük etkiler olduğunu söyledi. <!-- BELİRSİZ: hocanın andığı ışık türü altyazıda "mağrı ışık" diye geçiyor; büyük olasılıkla mavi ışık -->

Hoca, sunumun başında uçak görselini gördüğünü hatırlattı: uçak gibi elektromanyetik ve radyo dalgalarının girişim yapabileceği, sıkı denetlenmesi gereken ortamlarda Li-Fi önemli bir avantaj sağlar. Aydınlatmanın bol olduğu hastanelerde de avantajlıdır. En büyük dezavantajı ise duvardan geçmemesidir.

**Soru (hoca):** Duvardan geçememe sorunu tekrarlayıcı (repeater) gibi araçlarla giderilebilir mi?
**Cevap:** Öğrenciye göre Li-Fi LED lambalarla yapıldığı için çok düşük maliyetlidir. Bu yüzden var olan sinyali başka bir yere taşımaktansa yeni bir noktada yeni bir sinyal kaynağı oluşturmak daha ucuz olabilir; örneğin bir hastanede ya da ofiste her bilgisayarın üzerine bir lamba yerleştirilebilir.

**Soru (hoca):** Türkiye'de bir uygulamasına rastladınız mı?
**Cevap:** Öğrenci araştırmasında Türkiye'de bir örnek görmediğini, yurt dışında birkaç örneğe rastladığını söyledi. Teknoloji 2011'de duyurulduğu için hâlâ gelişme aşamasındadır. Türkiye'ye gelirse ilk aşamada büyük olasılıkla ofis gibi ortamlarda kullanılacağını, sonra sokak lambaları, uçaklar ve otobüsler gibi ışığın sorun yaratmayacağı yerlere yayılabileceğini düşündüğünü belirtti. Hoca otobüs örneğini destekledi: uzun yolda yolcu yalnız kendi tepe lambasını açar, o ışık üzerinden internete bağlanır, isterse kitabını okur.

## 3. Sunum: Asus Şirketi

### 3.1 Ürünler

İkinci sunum Asus şirketinin tarihi, kurumsal vizyonu ve ürünleri üzerineydi. "Şirket Ürünleri" yansısında ekran kartı, harici optik sürücü, akıllı saat, sunucu kartı, masaüstü bilgisayar ve monitör, dizüstü bilgisayar, netbook, akıllı telefon, tablet, kasa, yönlendirici, anakart ve projektör görselleri vardı (ekrandan, 00:20:00). Öğrenci Asus'un masaüstü bilgisayar, netbook, dizüstü bilgisayar, cep telefonu, ağ ekipmanı, monitör, Wi-Fi yönlendirici, projektör, anakart, ekran kartı ve optik depolama cihazları ürettiğini; en önemli ürünlerinden birinin anakart olduğunu söyledi.

Sunuma göre Asus 2005'te toplam 50 milyon anakart ihraç etti; bu, o yıl her üç kişisel bilgisayardan birinde Asus marka anakart kullanıldığı anlamına gelir. Şirket akıllı telefon sektörüne de kendi markalarıyla girdi. <!-- BELİRSİZ: telefon markalarının adları altyazıda okunmuyor -->

### 3.2 Adın kökeni

Asus adı, Yunan mitolojisinde bilgi ve ilhamın simgesi olan kanatlı at Pegasus'tan gelir. Öğrenciye göre şirket bu mitolojik yaratığın gücünü, yaratıcı ruhunu ve saflığını kendi bünyesinde birleştirerek ürettiği her ürünle bu özellikleri bir üst basamağa taşımayı amaçlamıştır.

### 3.3 Şirket bilgisi

Asus'un genel merkezi Tayvan'dadır; çok uluslu bir bilgisayar donanımı ve tüketici elektroniği şirketidir. 1989'da kurulan şirket, hedefini bugünün ve yarının dünyası için üretmek olarak belirlemiştir. Sunuma göre bugün dünyanın en büyük anakart üreticisidir ve bir oyun markası, tüketici bilgisayarı sağlayıcısıdır.

### 3.4 Green Asus ve vizyon

Green Asus, şirketin çevreye yönelik programıdır. Sunuma göre devlet kurumları ve bağımsız kuruluşlar bu programı hızla benimsedi; 2007'de bir araştırma kuruluşu Asus'u bilgisayar ve çevre birimleri sektöründe en çevre dostu firma olarak seçti ve Asus bu ödülü alan ilk Tayvanlı bilişim markası oldu. <!-- BELİRSİZ: kuruluşun adı altyazıda "Asus EO, Ecom, Research AG" diye bozuk -->

Kurumsal vizyon, müşterilerin hayatını kolaylaştıran ve onların bütün potansiyellerinin farkına varmalarını sağlayan yenilikler sunan, bütünleşik çözüm sağlayıcısı olmaktır. Ürünlerin her yaşam biçimine uyum sağlayan üstün performans ve estetik sunması hedeflenir.

### 3.5 Covid-19 döneminde

"ASUS koronavirüse karşı" yansısında (ekrandan, 00:25:00) öğrenci şirketin sağlık çalışanlarına yardım için ürün bağışladığını, sağlık tesislerinin işleyişine dijital altyapı sağladığını ve salgından çok etkilenen bölgelerdeki okullara cihaz bağışı planladığını anlattı.

## 4. Sunum Sonrası: Asrock, TUF ve AnandTech

Hoca, Asus adının Pegasus'tan geldiğini bilmediğini, ilginç bulduğunu söyledi. Kendi kısa araştırmasında baştaki "Peg" kısmının neden atıldığına dair bir açıklama gördüğünü aktardı: A harfiyle başlayan bir ad alfabetik sıralamalarda öne çıkar.

Hoca Asus'un 2000'lerde fiyat, fiyat-performans ya da "entüziyast" (bir alanı tutkuyla yakından takip eden kişi) kullanıcı kesiminde kendini iyi konumlandırmış bir marka olduğunu, kullandığı bileşenlerin daha uzun ömürlü ve dalgalanmalara karşı daha dayanıklı (korumalı, İngilizce "shielded") olduğunu söyledi.

**Soru (hoca):** Asrock diye bir marka vardı; Asus ile bir ilgisi var mıydı?
**Cevap:** Sunan öğrenci araştırmamıştı. Hoca açıkladı: Asrock ilk başta Asus'un daha uygun fiyatlı, fiyat odaklı pazarda rekabet edebilmek için kurduğu bir yan firmaydı; hocanın araştırmasına göre daha sonra ayrıldı. Bir başka öğrenci, Asus'un bugün daha ucuz ürünler için TUF adlı bir alt markası olduğunu ekledi; hoca adın "kuvvetli, sağlam" anlamındaki İngilizce "tough" sözcüğünü çağrıştırdığını söyledi.

Ardından hoca donanım takibi için AnandTech sitesini önerdi ve ekranda gösterdi (ekrandan, 00:30:00). Sitede kişisel bilgisayarlar, mobil cihazlar, sunucu bileşenleri ve kurumsal BT gibi bölümler vardır. Hocanın öne çıkardığı yanı, benchmark (karşılaştırmalı başarım ölçümü) üzerinden yapılan uzun karşılaştırmalı inceleme makaleleridir; ekranda "Best AMD Motherboards" ve "Best Intel Motherboards" rehberleri ile ayrı bir benchmark (Bench) bölümü vardı. Hoca hangi platformda hangi anakartın daha iyi olduğunu görmek için bu siteyi kurcalamayı önerdi.

## 5. Yaşam Boyu Öğrenme

Hoca bu bölümün notlarını, Sakarya Üniversitesi'nin eğitim dergisinde yayımlanmış bir makaleden hazırladığını söyledi ve konunun çok zengin bir içeriği olduğunu belirtti. Bölümde üç şey ele alındı: yaşam boyu öğrenmenin tanımları, neden ihtiyaç duyulduğu ve kapsamı.

### 5.1 Tanımlar

Yaşam boyu öğrenmenin farklı tanımları vardır ve hepsi geçerlidir; her biri kavramın farklı bir yönünü öne çıkarır. Yansıdaki tanımlar şunlardır (ekrandan, 00:40:00):

- İnsanın "resmî" öğrencilik sıfatını taşıdığı sürenin ardından, tüm hayatı boyunca sürdürdüğü öğrenme etkinliğidir. (Hoca en çok bu tanımı sevdiğini söyledi.)
- Farklı zaman ve farklı yerlerde esnek, çeşitli ve kullanılabilir, yaşam boyu sürdürülecek olan öğrenme etkinliğidir.
- Kulich (1982), yaşam boyu öğrenmeyi bireye yaşamları boyunca eğitimin sunulması olarak tanımlamıştır.
- White (1982), bireylerin yaşamlarını yönetebilmeleri için gerekli bilgileri edinmesi şeklinde ele almıştır.

Yansıya göre 1970'lerde UNESCO'nun politikası olan yaşam boyu öğrenme, OECD başta olmak üzere bütün eğitimciler ve eğitim politikacıları arasında "sürekli eğitim" kavramı olarak popülerleşmiştir. UNESCO, Birleşmiş Milletler Eğitim, Bilim ve Kültür Örgütü'dür (The United Nations Educational, Scientific and Cultural Organization); hoca Fransızca gibi dillerde kısaltmanın harf sırasının değişebildiğini, ama İngilizce literatürde UNESCO olarak geçtiğini söyledi. OECD ise Ekonomik Kalkınma ve İşbirliği Örgütü'dür (The Organisation for Economic Co-operation and Development).

Hoca iki kurumun bu konuyla neden ilgilendiğini şöyle açıkladı: UNESCO'nun odağı zaten eğitimdir. OECD'nin ilgisi ise White'ın tanımından anlaşılır: yaşamı yönetmenin maddi ve sağlık yönleri de vardır. Maddi yön için gerekli becerileri kazanmak ve ekonominin bir parçası olmak düşünüldüğünde, bir ekonomik kalkınma örgütünün neden devreye girdiği görülür.

> **Ders sonrası not:** Hoca UNESCO ve OECD'yi "Birleşmiş Milletler'in iki kurumu" diye andı. UNESCO bir BM ihtisas kuruluşudur, ama OECD BM'ye bağlı değildir; büyük olasılıkla bağımsız bir uluslararası örgüttür (1961'de kuruldu, merkezi Paris'te).

### 5.2 Üç eğitim biçimi

Hoca, yaşam boyu öğrenmeyi konumlandırmak için üç eğitim biçimini tanımladı.

**Örgün eğitim** resmî eğitimdir. Resmî olarak planlanmış ve ardışık biçimde yürür. Öğretmenin ve öğrencinin görev ve sorumlulukları kanun ve yönetmeliklerle açıkça tanımlanmıştır. Öğretmen öğrenciyi eğitmek amacıyla yönlendirir ve sorumluluk alır; öğrencinin de sorumlulukları vardır. Öğrencinin bu eğitime yazılması, kaydolması ya da alınmasıyla ilgili süreçler tanımlı ve nettir. Okul öncesinden lise sonuna kadar herkesin almak zorunda olduğu eğitim ile sonrasında seçimlik olan üniversite ve lisansüstü eğitim örgün eğitimdir.

**Yaygın eğitim**, öğrencinin kayıt ya da kabul işlemlerini gerektirmeyen veya bunların isteğe bağlı olduğu, ama bir program ve müfredat üzerinden verilen eğitimdir. Hoca örnek olarak belediyenin meslek ve sanat kurslarını ve üniversitelerin sosyal sorumluluk kapsamında verdiği eğitimleri gösterdi. Açık öğretimi ise yaygın eğitim saymadı, çünkü açık öğretim de resmî olarak planlıdır, süreçleri tanımlıdır, kayda ve çeşitli kurallara bağlıdır.

**Üçüncü biçim**, gündelik hayatın bir parçası olan öğrenmedir. Hoca bunu şöyle açıkladı: bilinç sahibi, zeki varlıklar olarak sürekli bir öğrenme süreci içindeyiz; etrafımızdan, komşularımızdan, arkadaşlarımızdan ve tecrübelerimizden öğreniriz. <!-- BELİRSİZ: bu biçimin adı altyazıda "algın eğitim" diye geçiyor; büyük olasılıkla "informal (serbest) eğitim"; ilgili yansı karelerde yok -->

Yaşam boyu öğrenme bu üç eğitim biçiminin tümünü içerir; farklı oranlarda ya da ağırlıklarda, ama hepsini içerir.

> **Ek bilgi (derste anlatılmadı):** Eğitim literatüründe bu üçlü genellikle "formal", "non-formal" ve "informal" öğrenme diye adlandırılır. Türkçede formal karşılığı örgün, non-formal karşılığı yaygın eğitimdir; informal öğrenme için büyük olasılıkla "serbest" ya da "informal" eğitim terimleri kullanılır.

### 5.3 Yaşam boyu öğrenmeyi örgün eğitimden ayıran özellikler

Hoca üç farka dikkat çekti:

- **Birey merkezlidir.** Örgün eğitimde bireyden çok toplumun geneli odak alınır; herkes aynı müfredattan geçer. Yaşam boyu öğrenmede ise birey kendi özel ihtiyaçlarına göre öğrenme etkinliklerini seçer ve kendisi koordine eder.
- **Okul dışı öğrenmeye önem verir.**
- **Belirli bir zaman dilimiyle sınırlı değildir.** Örgün eğitimde ders saatleri bellidir ve onların dışına çıkılmaz; yaşam boyu öğrenmede birey ne zaman müsaitse o zaman öğrenir. Hoca bu özelliğin de birey merkezlilikten kaynaklandığını belirtti.

### 5.4 Yaşam boyu öğrenmeye neden gereksinim duyulur?

Yansıya göre yaşam boyu öğrenmenin ortaya çıkmasında sosyal, ekonomik ve kişisel nedenler yatar (ekrandan, 00:45:00):

- Sanayinin ve toplumun hızlı değişen ihtiyaçlarına yanıt vermede örgün eğitimin yeterli çevikliği gösterememesi.
- Yaşam boyu öğrenmenin öğrenmede fırsatlar yaratarak bireylerin kişisel gelişimini sağlaması.
- Yaşam boyu öğrenmenin toplumsal bütünleşmeyi kolaylaştırması (özellikle yoğun göç hareketlerinde).
- Yaşam boyu öğrenmenin ekonomik büyümeye ve istihdama olumlu katkıda bulunması.

**Örgün eğitimin çevikliği.** Hoca bilgisayar mühendisliği eğitiminden örnek verdi. Öğrenciler dört yıl boyunca eğitim alır, ama sektörde çok farklı araçlar ve yöntemler kullanılır. Dört yıllık eğitimin amacı bunların hepsini öğretmek değil, sahada ne kullanılıyor olursa olsun onları kısa sürede öğrenip kullanabilecek altyapıyı kazandırmaktır. Hoca bir düşünce deneyi de anlattı: farklı firmalardan birçok kişi getirilip öğrencilere hangi seçmeli derslerin verilmesini istedikleri sorulsa 80 ders çıkar; ama bu 80 dersin 40'ını iki yıl sonra artık istemezler. Bu yüzden örgün eğitime ek olarak yaşam boyu öğrenmeye ihtiyaç vardır.

**Fırsat yaratma.** Bir eğilimi ve ortaya çıkan bir ihtiyacı fark eden kişi, o konuda kendini yetiştirerek tercih edilen, talep gören bir çalışan olabilir.

**Göç ve toplumsal bütünleşme.** Hoca yoğun göç hareketlerinin üzücü ama hayatın bir gerçeği olduğunu söyledi ve Suriye'deki savaştan kaynaklanan insan hareketliliğini ve Türkiye'nin zamanında Almanya'ya işçi göndermesini örnek verdi. Yer değiştiren kişi yeni bir çevreye geçer; o çevrenin koşullarını, gerekliliklerini, kültürünü ve hareket tarzını öğrenmesi gerekir. Aksi halde hayatını sürdürmekte zorlanır, sosyal bir varlık olarak da kendi dar çevresine sıkışıp kalır. Bu tür durumlarda bireylerin uyumu yaşam boyu öğrenme yöntemleriyle sağlanır.

**Ekonomi ve istihdam.** Bireylerin artan yetenekleri istihdama ve ekonomik büyümeye olumlu katkı yapar. Hoca pandemi koşullarını örnek gösterdi: ihtiyaç duyulan yetenekler farklılaştı, bazı mesleklere daha az, bazı uzmanlık alanlarına daha çok ihtiyaç duyulmaya başlandı. Veri ve yazılım alanındaki mühendislere talep arttı; hoca bu açıdan mesleğin avantajlı olduğunu söyledi.

> **Hocanın vurgusu:** Yansıda altı çizili olarak: "Özellikle hızlı gelişen meslek alanlarında yaşam boyu öğrenmenin önemi büyüktür. Bilgisayar mühendisliği ise en hızlı gelişen uzmanlık alanlarından biridir." (ekrandan, 00:45:00) Hoca bu yüzden yaşam boyu öğrenmenin bu meslekte diğer mesleklerden daha da önemli olduğunu ve öğrencilerin bu durumun farkında olmasını istediklerini özellikle vurguladı.

### 5.5 Yaşam boyu öğrenmenin kapsamı

"Yaşam Boyu Öğrenmenin Kapsamı" yansısında şunlar yazıyordu (ekrandan, 00:50:00):

- Yaşam boyu öğrenme; kişisel, sivil, sosyal ve/veya istihdam ile ilişkili bir bakış açısı içinde bilgi, beceri ve yetkinlikleri geliştirmek amacıyla tüm yaşam boyunca üstlenilen her türlü öğrenme etkinliğini kapsar.
- Örgün öğrenmeyi, yaygın öğrenmeyi, teknik eğitim ve becerilerin kazanılmasını sağlayan kursları, iş yerinde kazanılan mesleki becerileri ve diğer becerilerin kazanılmasına yol açan öğrenmeyi de içerir.
- Bu yüzden yaş, statü ya da eğitim seviyesine bakılmaksızın okullarda, üniversitelerde, evde, işte ya da toplum içinde herhangi bir yerde gerçekleştirilebilir.
- Yeni bir kavram olan yaşam boyu öğrenmenin Türk eğitim sistemine girmesi, 1960'ta toplanan, içinde Türkiye'nin de bulunduğu OECD ülkelerinin aldığı kararla olmuştur.
- Avrupa Birliği çapında ve ulusal düzeyde birçok rapor ve girişim için sunumun kaynağı incelenebilir.

Hoca kapsamın çok geniş olduğunu, amaçlar farklı olsa da sonuçta bilgi, beceri ve yetenekleri geliştirmenin hedeflendiğini söyledi. Arka plandaki nedenler kişisel, sosyal ihtiyaç ya da istihdam olabilir. İş yerlerinde verilen iş sağlığı ve güvenliği eğitimlerini de yaşam boyu öğrenmeye örnek gösterdi; üniversite çalışanlarının da yakın zamanda böyle bir eğitimden geçtiğini anlattı.

Türkiye'nin bu konuya girişi için hoca, UNESCO'nun 1960'ların sonu, 1970'lerin başında konuya ağırlık verdiğini, Türkiye'nin de 1960'larda bu çalışmaların içine girdiğini ve bunun geç sayılmayacağını söyledi. UNESCO ve OECD'nin konuyla ilgili neden-sonuç ilişkilerini gösteren birçok rapor ve analizi, bunların Türkçe çevirileri vardır; eğitim bilimleri alanındaki birçok süreli yayında da bu konuda yazılar bulunabilir.

## 6. Yaşam Boyu Öğrenme Üzerine Alıntılar

Hoca bölümü bir dizi alıntıyla kapattı. Yansıdaki alıntılar şunlardır (ekrandan, 00:55:00):

- "21. yüzyılın cahilleri okuma yazması olmayanlar değil; öğrenmeyi, unutmayı ve yeniden öğrenmeyi beceremeyenler olacaktır." (Alvin Toffler)
- "Eğitim; dünyayı değiştirmek için kullanabileceğiniz en güçlü silahtır." (Nelson Mandela)
- "Öğrenmeyi bıraktığınızda, ölmeye başlarsınız!" (Albert Einstein)
- "Bilim ve fen nerede ise oradan alacağız ve her ulus kişisinin kafasına koyacağız. Bilim ve fen için kayıt ve şart yoktur." (Mustafa Kemal Atatürk)
- "İlim ve fennin yaşadığımız her dakikadaki safhalarının gelişmesini kavramak ve izlemek şarttır." (Mustafa Kemal Atatürk)
- "Çocukken fakirdim. İki kuruş elime geçince bir kuruşunu kitaba verirdim. Eğer böyle olmasaydı, bu yaptıklarımın hiç birini yapamazdım." (Mustafa Kemal Atatürk)
- "İnsan eğitimle doğmaz ama eğitimle yaşar." (Cervantes)
- "Bana bir harf öğretenin kırk yıl kölesi olurum." (Hz. Ali)
- "Bir kişiye iyilik yapmak istiyorsan ona balık verme, balık tutmayı öğret." (Konfüçyüs)

### 6.1 Toffler: öğrenmek, unutmak, yeniden öğrenmek

Hoca Toffler'ı bir fütürist olarak tanıttı ve sözünü ayrıntılı açtı. Psikolojide **ileriye ket vurma** diye bir kavram vardır: eskiden öğrenilen becerilerin, ileride yeni becerilerin kazanılmasını zorlaştırmasıdır. Bu etki bazı insanlarda daha güçlü, bazılarında daha zayıftır, ama herkeste vardır.

Hoca meslekten bir örnek verdi. Önce yapısal programlama öğrenilir; yapısal programlamanın istediği bazı yöntemler ve doğru kullanım biçimleri vardır. Bunlar çok kullanılıp ezberlenirse, sonra öğrenilecek nesneye yönelik programlamada sorun çıkar: nesneye yönelik programlamanın bazı ilkeleri yapısal programlamayla paraleldir, bazıları farklılaşır. Farklılaştığı noktalarda hâlâ yapısal programlamadan gelen alışkanlıklar sürdürülürse yeni konu öğrenilemez ve uygulanamaz. Öğrenmek ve benimsemek pratikten, uygulamadan geçer; yanlış uygulanan şey yanlış öğrenilir. Hoca bu tür hataların küçük ölçeklisine "code smell", büyük ölçeklisine "anti-pattern" dendiğini söyledi.

Bu yüzden önce öğreniriz; sonra yeni bir şey öğrenirken eskisinin yenisiyle çelişen kısımlarını "unuturuz". Aslında unutmayabiliriz, aklımızın bir köşesinde kalır, ama artık uygulamayız. Elimizdeki problemi çözmek ya da yeni çalışma biçimine ayak uydurmak için hangi yeni yetenekler gerekiyorsa onları kullanmaya başlarız.

> **Ek bilgi (derste anlatılmadı):** "Code smell", kodun çalıştığı ama daha derin bir tasarım sorununa işaret eden yüzeysel belirtisidir (çok uzun metot, tekrar eden kod gibi). "Anti-pattern" ise sık başvurulan ama genellikle kötü sonuç veren bir tasarım ya da çözüm kalıbıdır. Nesneye yönelik bir dilde bütün işi tek bir dev sınıfta toplamak ("God object") büyük olasılıkla yapısal programlama alışkanlığından gelen bir anti-pattern örneğidir.

### 6.2 Mandela ve eğitimin toplumsal etkisi

Hoca Mandela'nın sözünü bireylerin eğitimiyle toplum düzeyinin iyileşmesine bağladı. Türkiye özelinde kadınların eğitiminin daha geniş etki yarattığını söyledi: bir kadın eğitildiğinde anne olarak çocuklarına, eş olarak eşine ve akrabalarına bu eğitimi yayabilir. Hoca yaşam boyu öğrenmenin cinsiyetten bağımsız olarak bütün bireylerin hakkı olduğunu ve kimsenin bu haktan mahrum bırakılmaması gerektiğini ekledi.

### 6.3 Einstein

Hoca Einstein'ın sözünü şöyle yorumladı: şartların gerektirdiği yeni becerileri kazanamayan kişi rekabetin gerisinde kalır; ölmez ama geride kalır.

### 6.4 Atatürk'ün sözleri

Hoca "Bilim ve fen için kayıt ve şart yoktur" sözündeki iki kavramı açtı. "Kayıt olmaması", bilimin belli kalıplara sıkıştırılamaması demektir. "Şart olmaması" ise yaşam boyu öğrenmeye vurgu yapar: bilgi illa belli bir biçimde, illa belli zamanlarda ya da illa örgün eğitimle öğrenilmez. Örgün eğitim önemli bir bileşendir, ama öğrenmeyi hayat boyuna yaymak gerekir.

Kitaplarla ilgili sözü için hoca, Atatürk'ün Ankara'daki kişisel kütüphanesindeki kitapların kenarlarına notlar aldığını, okuduklarını başka fikirlerle karşılaştırıp çapraz referanslar verdiğini anlattı.

### 6.5 Cervantes, Hz. Ali ve Konfüçyüs

Hz. Ali'nin sözünü hoca şöyle açıkladı: burada kastedilen tek bir harf değildir; bütün ilmin kaynağı harftir, bilgi harflerle aktarılır ve kalıcılığı böyle sağlanır. Sözlü iletişim de önemlidir, ama bilgi birikiminin yazılı saklanması büyük önem taşır. Okuma yazma oranının düşük olduğu dönemlerde, okuma yazma bilen esirlerin belirli sayıda kişiye öğretmeleri şartıyla serbest bırakıldığı uygulamalar olduğunu da ekledi.

Konfüçyüs'ün sözü, bireyin kendi kendine yetebilmesini hedefler. Hoca bu sözleri, yaşam boyu öğrenmeyle ve yaşamayı öğrenmeyle çok örtüştükleri için seçtiğini söyledi.

## Örnek Sorular

### Soru 1 (derste sözlü, 00:14:04)

Li-Fi insana sağlık açısından zarar verir mi?

**Derste verilen cevap:** Sunan öğrenciye göre bilinen bir zararı yoktur, çünkü sıradan LED aydınlatmayla çalışır; Wi-Fi'nin radyo dalgalarından kaynaklanan zararı da düşüktür ve ancak çok uzun maruziyette görülür. Hocaya göre ışık radyo dalgalarına kıyasla çok daha sağlıklıdır; tek olası etki, belirli bir ışık frekansına uzun süre maruz kalmanın göz yorgunluğu ve uyku düzeninde küçük bozulmalar yapabilmesidir.

### Soru 2 (derste sözlü, 00:15:38)

Li-Fi'nin duvarlardan geçememe sorunu nasıl giderilebilir?

**Derste verilen cevap:** Hoca tekrarlayıcı (repeater) önerdi. Öğrenciye göre LED tabanlı vericiler ucuz olduğu için sinyali taşımak yerine her odaya ya da her bilgisayarın üzerine ayrı bir lamba koymak daha ekonomik olabilir.

### Soru 3 (derste sözlü, 00:15:10)

Li-Fi hangi ortamlarda Wi-Fi'ye göre özellikle avantajlıdır?

**Derste verilen cevap:** Radyo dalgalarının girişim yapabileceği ve sıkı denetlenmesi gereken ortamlarda (uçak, hastane) ve aydınlatmanın zaten bol olduğu yerlerde. Uzun yol otobüsünde her yolcunun kendi tepe lambası üzerinden bağlanması da derste verilen bir örnektir.

### Soru 4 (derste sözlü, 00:27:09)

Asrock markasının Asus ile ilişkisi nedir?

**Derste verilen cevap:** Asrock, Asus'un daha uygun fiyatlı pazarda rekabet etmek için kurduğu bir yan firmaydı; hocanın araştırmasına göre sonradan ayrıldı. Asus'un bugün ucuz ürünler için TUF adlı bir alt markası vardır.

### Soru 5 (ekrandan, 00:40:00 ve 00:45:00)

Yaşam boyu öğrenme nedir ve ona neden gereksinim duyulur?

> **Çözüm (derste verilmedi, yansılardan derlendi):** Yaşam boyu öğrenme, resmî öğrencilik süresinden sonra da tüm hayat boyunca, farklı zaman ve yerlerde esnek biçimde sürdürülen; örgün, yaygın ve gündelik öğrenmeyi birlikte kapsayan öğrenme etkinliğidir (Kulich 1982: bireye yaşamı boyunca eğitimin sunulması; White 1982: bireyin yaşamını yönetmesi için gerekli bilgileri edinmesi). Gerekçeleri: örgün eğitimin sanayinin ve toplumun hızlı değişen ihtiyaçlarına yeterince çevik yanıt verememesi, bireye kişisel gelişim fırsatı sunması, göç hareketlerinde toplumsal bütünleşmeyi kolaylaştırması ve ekonomik büyümeye ve istihdama katkısı. Bilgisayar mühendisliği gibi hızlı gelişen alanlarda önemi daha da büyüktür.

### Soru 6 (derste sözlü, 00:51:43)

Toffler'ın "öğrenmeyi, unutmayı ve yeniden öğrenmeyi" sözündeki "unutmak" neden gereklidir? Mesleğimizden bir örnek veriniz.

**Derste verilen cevap:** İleriye ket vurma nedeniyle eski alışkanlıklar yeni becerilerin kazanılmasını zorlaştırır. Yapısal programlama alışkanlıklarını, ilkelerin farklılaştığı noktalarda nesneye yönelik programlamaya taşımak yeni paradigmanın öğrenilmesini engeller ve code smell ya da anti-pattern denen hatalara yol açar. Bu yüzden eski bilginin yeniyle çelişen kısımları bırakılmalı, yeni çalışma biçiminin gerektirdiği beceriler uygulanmalıdır.

## Dersin Toparlaması

Dersin ilk yarısında iki öğrenci sunumu dinlendi. Li-Fi sunumu, görünür ışıkla veri aktarımının tarihçesini (fotofondan 2011'deki duyuruya), LED ve fotodiyotla çalışan prensibini ve Wi-Fi'ye göre artılarını ve eksilerini anlattı; tartışmada teknolojinin radyo girişiminin sorun olduğu ortamlardaki avantajı ve duvardan geçememe kısıtının çözüm yolları konuşuldu. Asus sunumu şirketin ürünlerini, adının kökenini, çevre programını ve vizyonunu tanıttı; hoca Asrock ilişkisini açıkladı ve donanım karşılaştırmaları için AnandTech'i önerdi.

İkinci yarıda ders notlarının yeni bölümü olan yaşam boyu öğrenmeye geçildi: tanımlar, örgün, yaygın ve gündelik öğrenme ayrımı, yaşam boyu öğrenmenin birey merkezli ve zamanla sınırsız yapısı, ona duyulan sosyal, ekonomik ve kişisel gereksinim ve kapsamı. Hoca özellikle bilgisayar mühendisliğinin en hızlı gelişen alanlardan biri olduğunu ve "öğrenmek, unutmak, yeniden öğrenmek" döngüsünün bu meslekte kaçınılmaz olduğunu vurguladı. Ders notlarının kalan iki konusu olan girişimcilik ve sürdürülebilir kalkınmanın bir sonraki derste işleneceği söylendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
