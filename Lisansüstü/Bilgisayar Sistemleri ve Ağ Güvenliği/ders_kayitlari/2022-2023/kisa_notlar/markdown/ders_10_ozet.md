# Ders 10 Çalışma Özeti

## Genel Konular

- Dersin yeri: yönetim sorunları dizisinin son konusu
  - Önceki haftalarda güvenlik yönetimi, risk değerlendirmesi, fiziksel ve altyapı güvenliği, insan kaynakları güvenliği ve güvenlik denetimi (auditing) işlendi. Bu derste bilişim güvenliğinde yasal ve etik hususlar ele alındı.
  - Kurumlar güvenlik tedbirlerini iki nedenle alır: değerli varlıklarını (patent, çalışma, müşteri bilgisi, mali kayıt) kaybetmemek ve bir şey olduğunda haklarını yasal olarak savunabilmek. Kamu bilgisi tutan kurumlar (banka, belediye) için tedbir almak ayrıca hukuki bir yükümlülüktür.
- Bilgisayar suçu türleri: ABD Adalet Bakanlığı sınıflaması (ekrandan, 00:15:00)
  - Hedef olarak bilgisayarlar: veri bütünlüğüne, sistem bütünlüğüne, veri gizliliğine, mahremiyete veya kullanılabilirliğe yönelik saldırılar.
  - Depolama aygıtı olarak bilgisayarlar: çalınan parola listelerini, kredi kartı veya arama kartı numaralarını, özel şirket bilgilerini, pornografik görüntü dosyalarını veya korsan ticari yazılımları depolamak için bilgisayarı kullanma.
  - İletişim araçları olarak bilgisayarlar: dolandırıcılık, kumar, çocuk pornografisi ve reçeteli ilaçların, kontrollü maddelerin, alkolün veya silahların yasa dışı satışı gibi çevrim içi işlenen suçlar.
- Türk Ceza Kanunu'nda siber suçlar
  - ABD'deki gibi üç temel ayrım yoktur; suçlar TCK'nın farklı maddelerinde ve bentlerinde ayrı ayrı tanımlanmıştır.
  - Hocanın saydığı örnekler: bilişim sistemine girme (madde 243), banka veya kredi kartlarının kötüye kullanılması (madde 245), yasak cihaz veya program kullanma (madde 245/A), müstehcenlik (madde 226). <!-- BELİRSİZ: hoca 243'ten sonra "224" diye bir madde daha söyledi ama suç adı altyazıda yok; büyük olasılıkla madde 244 (sistemi engelleme, bozma, verileri yok etme veya değiştirme) kastedildi; bu slayt karelerde yok -->
- Avrupa Konseyi Siber Suçlar Sözleşmesi (ekrandan, 00:20:00)
  - Avrupa Konseyi tarafından geliştirilmiş, ABD dahil 43 ülke tarafından onaylanmıştır. Suçları tanımlar; cezaların miktarı ülkeden ülkeye değişir.
  - Madde 2, yasa dışı erişim: bir bilgisayar sisteminin tamamına veya herhangi bir kısmına hak olmaksızın erişim.
  - Madde 3, yasa dışı durdurma: elektromanyetik emisyonlar dahil, bilgisayar verilerinin kamuya açık olmayan aktarımlarının teknik yollarla haksız olarak kesilmesi.
  - Madde 4, veriye müdahale: bilgisayar verilerinin haksız yere zarar görmesi, silinmesi, bozulması, değiştirilmesi veya gizlenmesi.
  - Madde 5, sisteme müdahale: veri girerek, ileterek, zarar vererek, silerek, bozarak, değiştirerek veya gizleyerek bir sistemin işleyişinin hak olmaksızın ciddi şekilde engellenmesi.
  - Madde 6, cihazların kötüye kullanımı: madde 2-5'teki suçları işlemek amacıyla cihazların üretilmesi, satılması vb. <!-- BELİRSİZ: bu maddenin slaytı karelerde yok; altyazıda yalnız "satılması ... iki ile beş maddeler uyarınca ... cihazlar" kısmı var -->
  - Madde 7, bilgisayarla ilgili sahtecilik: verilerin girilmesi, değiştirilmesi, silinmesi veya gizlenmesiyle gerçek olmayan verilerin yasal amaçlar için gerçekmiş gibi değerlendirilmesine yol açılması.
  - Madde 8, bilgisayarla ilgili dolandırıcılık: veri girişi, değiştirme, silme ya da sistemin işleyişine hileli müdahaleyle, ekonomik çıkar amacıyla başkasının malının kaybına yol açmak.
  - Madde 9, çocuk pornografisiyle ilgili suçlar: bilgisayar sistemi aracılığıyla üretme, sunma, dağıtma, iletme, temin etme ve bulundurma.
  - Madde 11, teşebbüs ve yardım veya yataklık: sözleşmede tanımlanan suçlardan birinin işlenmesine kasten yardım ve yataklık etmek de suçtur.
- CERT 2007 E-Suç İzleme Anketi (ekrandan, 00:25:00)
  - Her suç türü için işlenen (net) yüzde ve faillerin içeriden, dışarıdan ya da belirsiz olma yüzdeleri verilir. En sık suç virüs, solucan ve diğer kötü amaçlı kodlardır (net %74; %18 içeriden, %46 dışarıdan, %26 belirsiz).
  - Tablonun genelinde dışarıdan gelen saldırıların oranı içeriden gelenlerden yüksektir; müşteri/mali kayıtların çalınması, fikri mülkiyet hırsızlığı ve hassas bilgilerin kasıtlı ifşası kalemlerinde ise içeriden gelenler daha yüksektir (sabotajda eşittir).
- Yasaların uygulanmasındaki zorluklar
  - Kolluk kuvvetlerinin caydırıcılığı, tutuklama ve kovuşturmanın başarısına bağlıdır. İnternet küreseldir, saldırgan VPN gibi araçlarla konumunu gizleyebilir.
  - Zorluklar: bilgili ve deneyimli personel eksikliği; teknoloji altyapısı ve bütçe eksikliği; suçun küresel doğası nedeniyle başka ülkelerin kolluk kuvvetleriyle eşgüdümün (gerçek zamanlı) gerekmesi.
  - Siber Suçlar Sözleşmesi ortak terminoloji ve yasaların küresel uyumu için çerçeve sunar, ama dünyadaki bütün ülkeleri kapsamaz.
- Siber suçlular ve siber suç kurbanları (ekrandan, 00:30:00)
  - Suçluların yakalanamaması sayılarının, cesaretlerinin ve operasyonların küresel ölçeğinin artmasına yol açmıştır.
  - Siber suçluların kesin bir profili yoktur; genç ve bilgisayar meraklısı olma eğilimindedirler, bir kısmı gelir için değil yeteneğini göstermek için saldırır. Davranış özellikleri geniş bir aralıktadır ve şüphelilere işaret edecek bir siber suçlu veritabanı yoktur.
  - Kurbanlar suçluların başarısından ve kolluğun başarısızlığından etkilenir; kuruluşların çoğu teknik, fiziksel ve insan faktörü kaynaklarına yeterince yatırım yapmamıştır; kolluğa güven eksikliği, kurumsal itibar ve hukuki sorumluluk endişeleri nedeniyle ihbar oranları düşüktür.
  - Üst yönetim ve güvenlik yöneticileri yasa uygulamasını bir kaynak ve araç olarak görmeli; adli soruşturma sürecini, haklarını ve soruşturmanın ihtiyaç duyduğu teknik bilgileri anlamalıdır.
- Fikri mülkiyet: telif hakkı, patent, ticari marka
  - Telif hakkı (copyright) bir fikrin somut veya sabit ifadesini korur, fikrin kendisini korumaz. Eser özgün olmalı ve somut bir forma sokulmuş olmalıdır.
  - Telif hakkı sahibinin münhasır hakları (ekrandan, 00:35:00): çoğaltma, değişiklik, dağıtım, herkese açık gösteri ve herkese açık görüntüleme.
  - Telif hakkı kapsamındaki eserler: edebi, müzikal, dramatik eserler; pandomim ve koreografik eserler; resim, grafik ve heykel; hareketli resimler ve diğer görsel-işitsel eserler; ses kayıtları; mimari işler; yazılımla ilgili işler.
  - Patent: mucide, başkalarının buluşu ilgili ülkede yapmasını, kullanmasını, satmasını veya ithal etmesini engelleme hakkı verir. Türleri: faydalı (utility) patent, tasarım patenti, bitki patenti.
  - Ticari marka (trademark): malların kaynağını gösteren ve onları başkalarından ayıran kelime, isim, sembol. Kafa karıştıracak kadar benzer markaların kullanımını engeller, ama aynı malın açıkça farklı bir markayla üretilmesini engellemez.
- Ağ ve bilgisayar güvenliğiyle ilgili fikri mülkiyet
  - Yazılım (ticari, paylaşılan, kuruma özel tescilli, kişisel), veri tabanları (ör. müşteri eğilim verileri), dijital içerik (ses, video, multimedya, web içeriği) ve algoritmalar (ör. patentlenebilir şifreleme algoritmaları).
- ABD Dijital Milenyum Telif Hakkı Yasası, DMCA (ekrandan, 00:40:00)
  - 1998'de kanunlaştı; WIPO (Dünya Fikri Mülkiyet Örgütü) anlaşmalarını uygular.
  - Telif hakkı sahiplerini teknolojik önlemler almaya teşvik eder: esere erişimi engelleyen ve kopyalanmasını önleyen tedbirler.
  - Bu önlemleri atlama girişimlerini yasaklar; cezai ve hukuki yaptırımlar uygulanır.
  - Muafiyetler: adil kullanım, tersine mühendislik, şifreleme araştırmaları, güvenlik testleri ve kişisel mahremiyet.
  - Eleştiri: meşru güvenlik ve şifreleme araştırmalarını, inovasyonu, akademik özgürlüğü ve açık kaynak geliştirmeyi baskılayabileceği endişesi.
- Türkiye'de dijital ortamda telif hakkının korunması
  - Hukuk davaları: tecavüzün ref'i (kaldırılması), tecavüzün men'i (durdurulması), maddi ve manevi tazminat.
  - Ceza davası: eseri hak sahibinin yazılı izni olmadan işleyen, değiştiren, umuma ileten, yayan ya da kişisel kullanım dışında bulunduran veya depolayan kişiye bir yıldan beş yıla kadar hapis veya adli para cezası.
  - Ders sonrası not: hoca bu hükmü Türk Ceza Kanunu'na bağladı; bu hüküm büyük olasılıkla TCK'da değil, 5846 sayılı Fikir ve Sanat Eserleri Kanunu'nun 71. maddesindedir.
- Dijital Haklar Yönetimi (DRM)
  - Dijital hak sahiplerinin açıkça tanınmasını ve eserleri için öngörülen ödemeyi almasını sağlayan sistem ve prosedürler. Tek bir DRM standardı ya da mimarisi yoktur; amaç içeriğin bütün yaşam döngüsünde ve farklı platformlarda kalıcı koruma sağlamaktır.
- Mahremiyet (ekrandan, 00:45:00)
  - Bilgisayar güvenliği ile örtüşür; toplanan ve saklanan bilgi ölçeği kolluk kuvvetleri, ulusal güvenlik ve ekonomik teşvikler nedeniyle çarpıcı biçimde artmıştır.
  - Bireyler kişisel bilgilerinin kullanımı konusunda bilinçlenmiştir; bu endişeler yasal ve teknik yaklaşımlara yol açmıştır.
- Mahremiyetle ilgili yasal düzenlemeler
  - AB Veri Koruma Direktifi: üye devletler kişisel bilgi işlenirken temel gizlilik haklarını korumalıdır. İlkeler: verinin toplandığından haberdar olma, rızanın alınması, verinin tutarlı olması, kimin erişebildiğinin bilinmesi, güvenli saklama, aktarımın ve kullanım yerinin bilinmesi. <!-- BELİRSİZ: bu slayt karelerde yok; ilke adları altyazıdan kuruldu -->
  - Ders sonrası not: hoca direktifin 1998'de kabul edildiğini söyledi; direktif (95/46/EC) büyük olasılıkla 1995'te kabul edilmiş, 1998'de yürürlüğe girmiştir.
  - ABD 1974 Gizlilik Yasası (Privacy Act): federal kurumların topladığı kişisel bilgileri kapsar; bireyler hangi kayıtların tutulduğunu öğrenebilir, başka amaçla kullanılmasını engelleyebilir, kayıtlarına erişip düzeltebilir; dava hakkı tanır.
  - Türkiye: 2016 tarihli 6698 sayılı Kişisel Verilerin Korunması Kanunu (KVKK). Özel hayatın gizliliğini korur; kişisel verilerin işlenme şartlarını, silinmesini, yok edilmesini, anonimleştirilmesini, aktarımını, veri sorumlusunun aydınlatma yükümlülüğünü, veri sahibinin haklarını ve cezai hususları düzenler.
- ISO 27002 ve kişisel veriler (ekrandan, 00:50:00)
  - Kuruluş kişisel olarak tanımlanabilir bilgilerin gizliliği ve korunması için bir veri politikası geliştirmeli, uygulamalı ve ilgili herkese iletmelidir.
  - Uyum, uygun yönetim yapısı ve kontrol gerektirir; genellikle bir gizlilik görevlisi gibi sorumlu kişi atanarak sağlanır. Uygun teknik ve organizasyonel önlemler uygulanmalıdır.
- Gizlilik ve veri gözetimi
  - Şirketlerin, hükümetlerin ve kolluk kuvvetlerinin veri talepleri yeni mahremiyet tehditleri yaratır. Bilimsel araştırma, halk sağlığı, ulusal güvenlik ve kolluk için veri toplamanın faydası ile bireyin mahremiyet hakkı arasında bir çelişki vardır.
  - Sosyal medyada kişilerin kendi isteğiyle yüklediği veriler ileride işverenler, sigorta şirketleri, özel dedektifler vb. tarafından kullanılabilir.
- Gizliliğin korunması (ekrandan, 00:55:00)
  - Hem politika hem teknik yaklaşım gerekir. Teknik olarak veri tabanı güvenliği mekanizmaları gereksinimleri kısmen karşılar.
  - Sosyal medyada teknik kontroller: verileri kimin görebileceğini yöneten gizlilik ayarları, bir kişi etiketlendiğinde ona bildirim. Bu ayarlar sürekli değiştiği için kullanıcılar zorlanır.
  - Büyük veri analizinde veriler araştırmacılara verilmeden önce anonimleştirilmeli, kişisel tanımlayıcılar kaldırılmalıdır.
  - Politika tarafında: rıza, mahremiyet ve gizlilik, mülkiyet ve yazarlık, veri paylaşımı ve sosyal fayda değerlendirmesi.
- Etik
  - Etik: belirli eylemlerin yararları ve zararları ile amaçlarının doğruluğu ve yanlışlığıyla ilgili ahlaki ilkeler sistemidir.
  - Bilgisayarların ortaya çıkardığı etik konular: bilgi depoları ve işleyicileri olarak bilgisayarlar; yeni varlık türlerinin üreticisi olarak bilgisayarlar; eylem araçları; yıldırma ve aldatma sembolleri.
  - Mesleki ve etik sorumluluklar arasında denge: bir profesyonelin işverenine sadakatle çalışma görevi, ama kamuya ya da şirkete zarar verebilecek durumlarla karşılaşma ve şahsi çıkar sağlamama.
  - Davranış kuralları (ekrandan, 01:00:00): etik kesin yasalar veya gerçekler dizisi değildir, birçok alan etik belirsizlik sunar. Profesyonel toplulukların benimsediği etik kurallar: olumlu bir uyarıcı olur ve güven aşılar; eğitici olur; bir destek ölçüsü sağlar; caydırıcılık ve disiplin aracı olur; mesleğin kamusal imajını geliştirir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Güvenlik tedbirlerinin hukuki boyutu
  - Tedbir almak hem varlığı korumak hem de bir olay olduğunda hakkı yasal olarak savunabilmek için gereklidir. Başkalarının verisini tutan kurumlar için yasal bir zorunluluktur.
- Siber suçla mücadelede en temel sorun
  - Hocaya göre en temel sebep bu suçlarla mücadelede bilgili ve deneyimli personel eksikliğidir; ikinci sebep teknoloji altyapısı ve bütçe eksikliğidir.
- Kurbanların ihbar etmemesi
  - Kurumlar güvenliğe yatırımı saldırı olana kadar ihmal eder; saldırıdan sonra müşteri gözünde itibar kaybı korkusuyla ihbar etmeyip olayı "sineye çeker". Fidye yazılımında da çoğu kurum fidyeyi ödemek zorunda kalır.
- Telif hakkı fikri değil ifadeyi korur
  - Hoca bunu iki kez tekrarladı. Yazılımda telif hakkı korumasının zayıf kaldığını, aynı iş biraz değiştirilerek başka biçimde yapılabildiğini vurguladı.
- Sosyal medyada paylaşılanların kalıcılığı
  - Bugün bilerek ve isteyerek paylaşılan bilgiler yıllar sonra iş başvurusunda kişinin başına bela olabilir.
- Etiketleme ve başkalarının mahremiyeti
  - On kişilik bir grup fotoğrafını paylaşan bir kişi diğer dokuz kişinin mahremiyetini de etkiler; bu yüzden etiketlenen kişiye bildirim gitmelidir.

## Kısa Tekrar Notları

- ABD sınıflaması: hedef olarak, depolama aygıtı olarak, iletişim aracı olarak bilgisayar.
- TCK'da tek bir sınıflama yok: 243 bilişim sistemine girme, 245 kart kötüye kullanma, 245/A yasak cihaz/program, 226 müstehcenlik.
- Siber Suçlar Sözleşmesi: madde 2 yasa dışı erişim, 3 yasa dışı durdurma, 4 veriye müdahale, 5 sisteme müdahale, 6 cihazların kötüye kullanımı, 7 sahtecilik, 8 dolandırıcılık, 9 çocuk pornografisi, 11 teşebbüs ve yardım/yataklık.
- CERT 2007: en sık suç kötü amaçlı kod (%74); çoğu kalemde dışarıdan gelen oran yüksek.
- Uygulama zorlukları: personel, teknoloji ve bütçe eksikliği, küresel eşgüdüm ihtiyacı.
- Siber suçlu profili yok; kurbanlar yatırım yapmıyor ve ihbar etmiyor.
- Telif hakkı: somut ifadeyi korur; çoğaltma, değişiklik, dağıtım, gösteri, görüntüleme hakları.
- Patent türleri: faydalı, tasarım, bitki. Ticari marka: kaynağı gösterir, benzerini engeller.
- DMCA (1998): WIPO anlaşmaları, teknolojik koruma, atlatma yasağı; muafiyetler: adil kullanım, tersine mühendislik, şifreleme araştırması, güvenlik testi, mahremiyet.
- Türkiye'de telif: ref, men, tazminat davaları; 1-5 yıl hapis ceza davası.
- DRM: tek bir standart yok.
- Mahremiyet yasaları: AB Veri Koruma Direktifi, ABD Privacy Act 1974, KVKK 6698 (2016), ISO 27002.
- Mahremiyet: kişinin bilgilerine kimin erişebileceğini bilmesi. Gizlilik: bilgiye yalnız yetkililerin erişebilmesi.
- Etik kesin kurallar dizisi değildir; davranış kuralları: uyarıcı, eğitici, destek, caydırıcılık/disiplin, kamusal imaj.

## Detaylı Açıklamalar

- Bilgisayarın suçtaki rolü
  - ABD Adalet Bakanlığı sınıflamasında ayrım bilgisayarın suçtaki rolüne dayanır. Saldırının hedefi sistemin kendisi ya da içindeki veri ise (bütünlük, gizlilik, kullanılabilirlik) bilgisayar hedeftir. Bilgisayar, çalınan parola listeleri veya kart numaraları gibi gizli bilgileri ya da yasa dışı içeriği (pornografi, korsan yazılım) saklamak için kullanılıyorsa depolama aygıtıdır. Dolandırıcılık, kumar ya da yasa dışı satış gibi suçlar ağ üzerinden işleniyorsa bilgisayar iletişim aracıdır. Hoca, yasa dışı içeriği depolamanın ve onu dağıtmanın ayrı kategorilerde değerlendirildiğini belirtti.
- Neden yasa tek başına yetmiyor
  - Suçun caydırıcılığı yakalanma ve cezalandırılma olasılığına bağlıdır. İnternet "ağların ağı" olduğundan saldırı dünyanın herhangi bir yerinden gelebilir ve VPN gibi araçlarla gizlenebilir. Suçluyu yakalamak için farklı ülkelerin kolluk kuvvetlerinin gerçek zamanlı eşgüdümü gerekir. Yakalanamayan suçlu cesaretlenir. Siber Suçlar Sözleşmesi suçları ortak bir terminolojiyle tanımlar, ama cezalandırma her ülkenin kendi yasalarına kalır ve sözleşmeyi bütün ülkeler kabul etmemiştir.
- Fikri mülkiyet ve güvenlik araştırması
  - DMCA telif hakkıyla korunan eserlere erişimi ve kopyalamayı engelleyen teknolojik önlemleri ve bunları atlamayı yasaklayan hükümleri getirir. Ancak tersine mühendislik, şifreleme araştırması ve güvenlik testleri muaftır: bir algoritmanın sahibi, başkasının o algoritmanın zayıflığını araştırmasını telif hakkı gerekçesiyle engelleyemez. Buna rağmen yasanın büyük şirketlerce açık kaynak geliştirmeye karşı gereksiz davalarda kullanılabildiği eleştirisi vardır.
- Mahremiyet ile gizlilik farkı
  - Mahremiyet bireyin kendi kişisel bilgilerine kimin erişebileceğini bilmesi ve bunu kontrol etmesidir. Gizlilik ise bilgiye yalnız yetkili kişilerin erişebilmesi ilkesidir. Büyük veri çağında toplanan veri kolluk, halk sağlığı ve ulusal güvenlik açısından faydalıdır; ama toplanan veri arttıkça bireyin mahremiyetine müdahale de artar. Bu dengeyi kurmak için hem teknik (erişim ayarları, anonimleştirme) hem politik (rıza, mülkiyet, paylaşım kuralları) önlemler gerekir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
