# Ders 6 Çalışma Özeti

## Genel Konular

- Yazılımların korunması (önceki haftadan kalan fikir ve sanat eserleri konusu) (ekrandan, 00:05:00)
  - Yazılıma tek başına patent verilmez. Verilseydi aynı işlevi gören, farklı tasarım ve yöntemle yazılmış başka yazılımların önü kapanırdı.
  - Bilgisayar temelli sistemlere patent verilebilir. Örneğin bilgisayar temelli bir çamaşır makinesinin yönetim birimi için hem tasarıma hem de onunla birlikte çalışan yönetim yazılımına patent alınabilir.
  - Patent yasalarına göre kullanıcı arayüzüne patent verilmez; ama fare, fare yerine geçen yüzeyler (dokunmatik yüzey) ve iki parmakla büyütme/küçültme yapan ekran ve yüzeyler patent alabilmektedir.
  - Bazı ülkelerde (örneğin ABD) yazılımlara patent ya da faydalı model belgesi verilmeye başlanmıştır; bunun için yazılımın yenilikçi ve özgün olması gerekir.
- Tersine mühendislik (reverse engineering) (ekrandan, 00:10:00)
  - Başkasının geliştirdiği bir donanımı inceleyip aynısını ya da daha gelişmişini yapma yöntemi olarak doğmuş, sonra yazılımlara da uygulanmıştır.
  - Mikrodenetleyicilerden önceki atanmış (gömülü) bilgisayarlarda donanım kolayca kopyalanabiliyor, bellekteki kod da görünüyordu; kod tersine derlenince simgesel dilde (assembly) program elde ediliyordu.
  - Mevcut bir yazılımın kodundan tasarım yapısı, akış diyagramları ve algoritmalar çıkarılabilir. Bu, asıl yazılımı hazırlayanların emeğinin çalınması demektir.
  - Başkasının programını tersine mühendislikle elde edip kullanmak ya da ondan ürün çıkarmak hukuken ve etik olarak kabul edilemez; bilgi hırsızlığıdır.
  - Kuruluşun kendi eski yazılımını günün koşullarına uydurmak için (örneğin ana bilgisayarda COBOL ile yazılmış, dosya sistemine yazan monolitik bir bankacılık uygulamasını nesne yönelimli dil ve ilişkisel veri tabanına taşımak) yapılan tersine mühendislik kabul edilebilir.
  - Tersine mühendislik yapan firmalar hukuktan kaçmak için veri tabanı ve tablo yapısını, programlama dilini, kütüphaneleri ya da arayüzü değiştirip "farklı bir yazılım ürettim" savunması yapar.
- Açık kaynak kodlu yazılımlar (ekrandan, 00:15:00)
  - Gereksinim, tasarım ve gerçekleştirme aşamalarından geçen emek ürünü bir yazılımın kodunun verilmesi beklenmez; ama bazı geliştiriciler paylaşmayı yararlı bulur.
  - Gerekçeleri: program parçalarının başkalarınca daha iyi çözülebilmesi, programcılar arası bilgi alışverişi, bileşenlerin parayla satın alınabilmesi, bakım ve destekten para kazanılabilmesi, lisans almaya üşenen firmaların kodu herkesle paylaşması.
  - GNU ("GNU's Not Unix") projesi ve açık kaynaklı Android işletim sistemi örnek verildi. Üreticiler (Samsung, Sony, LG, Huawei gibi) Android'in üzerine kendi arayüz ve tamamlayıcı yazılımlarını koyunca dağıtım kapalı hâle gelir ve her sürümü kendileri uyarlamak zorunda kalır.
- Yazılım ve insan hakları değerlendirmesi
  - Herkes bilişim dünyasına yazılım ve sistem tasarlayarak katkı yapabilir; üretilen her yazılımın maddi ve manevi hakları korunmalıdır.
  - Herkes yazılımlardan yararlanma hakkına sahiptir; ama bunun karşılığında kabul edilebilir bir bedel ödenmelidir.
- Kaynak kodu emanetçiliği (ekrandan, 00:20:00)
  - Firmadan ayrılan programcının kodun kopyasını alıp kendi firmasında aynı işlevli ürünü satması sık rastlanan bir durumdur. Manevi hak programcıda olsa da maddi hak şirkettedir.
  - Asıl firma haksız rekabet davası açar; teknik bilirkişi iki tarafın kodunu karşılaştırıp benzerlik raporu yazar (hangi modül aynı, hangisi yüzde kaç benzer). Kodlar büyük ölçüde aynıysa ikinci firma suçlu bulunur. Kararı bilirkişi değil hâkim verir.
  - Firmalar emanetçiyi iki amaçla kullanır: kaynak kodun çalınmasına karşı önlem ve yazılımın geleceğini güvenceye alma (firma kapanırsa müşteri kodu emanetçiden alabilir).
  - <!-- BELİRSİZ: Hoca Türkiye'de İTÜ bünyesinde böyle bir kod emanet hizmeti olduğunu söyledi ama adını hatırlayamadı. -->
- Meslek ve meslek kuruluşları (ekrandan, 00:30:00)
  - Meslek: kişinin yaşamını sürdürmek için yaptığı, yoğun eğitim ve çalışma gerektiren bir sürecin sonunda kazandığı beceri ve unvanın adıdır. Bu becerinin insanlık yararına kullanılması beklenir.
  - Mesleğe girmek için eğitim ve yetki belgesi gerekir; belgeyi alan kişi mesleğe kabul edilir, kurallara uymazsa meslekten atılır.
  - Ahilik: 12. yüzyılda Ahi Evran (1171-1262) tarafından sanat ve sanat ahlakı öğretmek için kurulmuştur. "Ahi" kardeş demektir. Meslek örgütlerine ahi loncaları denir; içinde çırak, kalfa, usta unvanları kazanılır.
  - Loncaya giren önce "yiğit" olur, sonra çırak, kalfa ve usta olur; ustalık bir törenle verilir. Kethüda mesleğin kurallarını bilen ve esnafın dürüstlüğünü denetleyen kişi, yiğitbaşı ise ürünlerin hileli olup olmadığını denetleyen bilirkişidir.
  - Ahi loncalarının görevleri: meslek eğitimi, meslek içi eğitimle süreklilik, muhtaç meslektaşlara yardım (orta sandığı, esnaf sandığı), meslek ahlakını öğretme ve denetleme, kalitesiz ve pahalı ürün satışını önleme, devlet ile meslek sahipleri arasındaki ilişkiyi sağlama.
  - Günümüzde bu görevi meslek odaları sürdürür: etik kuralları belirler, uymayanlara yaptırım (meslekten men, süreli men) uygular, doğru ve yanlış eylemleri tanımlar, üyeleri etik davranışa yönlendirir, işveren ile çalışan ilişkilerini düzenler.
- Meslek etiği (ekrandan, 00:40:00)
  - Mesleki davranışla ilgili neyin doğru, yanlış, haklı ya da haksız olduğu hakkındaki ilke ve kurallardır. Mesleki uygulamaların yasalara uygun olmasının yanı sıra toplumun değer yargılarını önemseyerek topluma doğru ve güvenilir bilgi sunmayı da kapsar.
  - Akademik bir alan olarak 1980'lerde ortaya çıkmıştır.
  - Temel amaçları: meslek içi rekabeti düzenlemek, yetersiz ve ilkesiz üyeleri ayıklamak, hizmet hedeflerini korumak, meslek disiplinini ve mesleğe bağlılığı sağlamak.
  - Temel ilkeleri: doğruluk, yasallık, yeterlik, güvenilirlik ve mesleğe bağlılık.
- Mühendislik ve gelişimi (ekrandan, 00:50:00)
  - Tanım: bilimsel ve matematiksel ilkeleri, deneyim ve yaratıcılığı kullanarak doğal kaynaklardan insana faydalı ürünler ortaya koyma eylemidir.
  - 20. yüzyılda yaşama katkı yapmış yirmi mühendislik konusu: elektrik, otomobil, uçak, su sağlama ve dağıtımı, elektronik, radyo ve televizyon, tarım araçları, bilgisayar, telefon, buzdolabı ve iklimlendirme, otoyollar, uzay araçları, genelağ, tıpta görüntü işleme, ev aletleri, sağlık teknolojileri, petrokimya, lazer ve fiber optik, nükleer teknolojiler, yüksek başarımlı malzemeler.
  - Mühendisliğin somut (verimlilik, hız) ve soyut (Ay'a gitmenin topluma verdiği moral) katkıları vardır; ama atom bombası ve mayın gibi zararlı ürünler de mühendislerin elinden çıkmıştır.
  - "Mühendis" Arapça hendese (hesap, ölçme-biçme, matematik) kökünden; "engineer" Latince icat etmek, yaratmak anlamındaki kökten gelir.
  - Dönemler: bilim devrimi öncesi; Leonardo da Vinci'den (16. yüzyıl) sanayi devrimine (19. yüzyıl) kadar yetenekten çok bilimin önem kazandığı dönem; ikinci sanayi devrimi (İkinci Dünya Savaşı'na kadar, kimya ve elektrik mühendisliği); savaş sonrası bilişim dönemi.
  - Bugün altı temel küme vardır: inşaat, kimya, makine, elektrik, bilgisayar, uçak-uzay; her küme kendi içinde dallara ayrılır.
- Mühendislerin görev ve sorumlulukları (ekrandan, 01:00:00)
  - Zorunluluk: mühendisin yapmakla yükümlü olduğu davranışlar; doğru, dürüst ve adil olmak zorunludur. Rolün gerektirdiği işler de zorunluluktur.
  - Sorumluluk (hesap verebilirlik): yapılan işlemi üstlere ve çevreye açıklayabilmek ve sonucunun sorumluluğunu yüklenmek.
  - Özen: işin kusursuz olması için özen; ölçütler (yanılma payı) gereksinimlerde belirlenir, aşım olursa bunun özensizlikten kaynaklanmaması beklenir.
  - Kınama ya da ödüllendirme: her işlem kınanabilir ya da övülebilir; sorumlu kişi iki sonuca da katlanır.
- TMMOB meslek etiği ilkelerine göre sorumluluklar (ekrandan, 01:10:00; 01:15:00)
  - Kendine karşı: bilim ve teknolojiyi insanlık yararına ve doğal dengeyi koruyarak kullanmak, bilgi ve yeteneği sürekli geliştirmek, en iyi hizmeti vermek, sözleşmelere uymak, yalnız yeterli olduğu alanda çalışmak, sahip olmadığı unvanı kullanmamak.
  - Topluma karşı: insan haklarına, barışa, demokrasiye saygı; ayrım gözetmeden çok kültürlü yapıyı korumak; ciddi tehlike gördüğünde önce işverene/müşteriye, dikkate alınmazsa yazılı olarak, sonuç alınmazsa meslek örgütüne, yetkili makamlara ve kamuoyuna bildirmek; teknik görüşü tam ve nesnel vermek; işçi sağlığı ve iş güvenliği önlemlerini almak.
  - Doğaya ve çevreye karşı: doğayı korumak, uygulamaların doğayla uyumlu olmasını sağlamak, doğal kaynak ve enerjiyi verimli kullanmak.
  - İşveren ve müşteriye karşı: güvenilir vekil ve danışman olmak; işverenin çıkarı için toplumun sağlık ve güvenliğini tehlikeye atmamak; armağan, para ya da iş teklifi kabul etmemek ve teklif etmemek; ticari ve teknolojik sırları izinsiz açıklamamak.
  - Mesleğe ve meslektaşlara karşı: haksız rekabet etmemek, astların gelişimine katkı, telif haklarına saygı ve katkı yapanları belirtmek, görevi yalnız zorunlu durumda uzman meslektaşa devretmek, yalnız resmî olarak kazanılmış unvanları kullanmak, ilkelere aykırı davrananlara yardımcı olmamak, meslek örgütlerini desteklemek.
- Bilgisayar mühendislerinin proje aşamalarındaki sorumlulukları (ekrandan, 01:20:00)
  - Genel dört evre: planlama ve seçim, çözümleme, tasarım, kurulum ve işletme.
  - Bilişim projesi için sekiz aşama: kavramsal çalışmalar, gereksinimlerin belirlenmesi, çözümleme, tasarım, gerçekleştirme, sınama, kurulum ve işletmeye alma, bakım.
  - Kavramsal çalışmalar: projenin gerekçe, amaç ve hedefinin belirlendiği aşamadır. Amaç ve kapsam yasalara, yönetmeliklere, ölçünlere ve etik değerlere uymuyorsa proje başlatılmamalıdır.
  - Gereksinimler: işlevsel ve işlevsel olmayan gereksinimler, donanım özellikleri ve uyulacak standartlar doğru tanımlanır (SRS raporu); ulaşılamayacak performans hedefi konmaz.
  - Çözümleme: her projenin birden çok çözümü vardır (pahalı, yüksek başarımlı, güvenli); gereksinimleri eksiksiz karşılayanlar arasından en uygunu seçilir. Herkes kendi uzmanlık alanında söz söyler; uzman, sorunu yazılı olarak ortaya koymalıdır.
  - Tasarım: ön ve ayrıntılı tasarım; kendi kafasına göre değil ekiple görüşerek yapılır, standart belgeler ve diyagramlarla belgelenir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Başkasının yazılımını tersine mühendislikle çözüp ürün yapmak ya da kullanmak etik değildir; yalnız kuruluşun kendi eski ürününü güncellemek için yapılabilir.
- Yazılımı yazan çalışan olsa bile maddi haklar şirkettedir; kodu alıp ayrılmak haksız rekabettir.
- Meslek etiği, genel etikten daha fazla sorumluluk yükler. Meslek üyeleri etik ilkelere ne kadar sıkı uyarsa mesleğin saygınlığı o kadar artar; tek bir kötü örnek bütün mesleği karalayabilir (deprem ve müteahhitlik örneği).
- Mezuniyette edilen mühendislik yemini, öğrenilenleri insanlık yararına kullanma sözüdür; mühendis bu yemine uygun çalışmalıdır.
- Toplum her zaman işverenden önce gelir: işverenin her dediği yapılmaz.
- Kavramsal aşamada etik olmayan bir projeye "hayır" denmelidir; proje bittiğinde oluşacak sorumlulukta en büyük pay kavramı geliştirenlerindir.
- Uzmanlık alanı dışında, yetkisi olsa bile kimse söz söylememelidir; uzman uyarısını yazılı olarak yapmalıdır (internet bankacılığı vakası).
- Projede tek bir doğru çözüm yoktur; güvenlik, maliyet ve kullanışlılık arasında projenin isterlerine göre denge kurulur.

## Kısa Tekrar Notları

- Yazılıma patent yok; bilgisayar temelli sisteme (ve içindeki yönetim yazılımına) patent var.
- Kullanıcı arayüzüne patent yok, ama fare, dokunmatik yüzey ve çok dokunuşlu ekranlar patent alabiliyor.
- Tersine mühendislik: başkasının yazılımında bilgi hırsızlığı; kendi eski yazılımını yenilemekte kabul edilebilir.
- Açık kaynak gerekçeleri: daha iyi çözüm, bilgi alışverişi, bakım ve destekten kazanç.
- Yazılımdan yararlanmak herkesin hakkıdır, ama kabul edilebilir bir bedel karşılığında.
- Kaynak kodu emanetçisi: çalınmaya karşı kanıt ve firma kapanırsa müşteriye güvence.
- Ahilik: Ahi Evran (1171-1262); yiğit → çırak → kalfa → usta; kethüda ve yiğitbaşı denetler.
- Meslek etiği ilkeleri: doğruluk, yasallık, yeterlik, güvenilirlik, mesleğe bağlılık.
- Yasallığın üç yönü: ürünün yasa ve yönetmeliklere, çalışmaların çalışma yasalarına, dış paydaşlarla ilişkilerin yasalara uygun olması.
- Mühendislerin görev ve sorumlulukları: zorunluluk, sorumluluk, özen, kınama ya da ödüllendirme.
- TMMOB sorumluluk halkaları: kendine, topluma, doğa ve çevreye, işveren ve müşteriye, mesleğe ve meslektaşlara.
- Tehlike bildirme sırası: işveren/müşteri → yazılı bildirim → meslek örgütü → yetkili makamlar ve kamuoyu.
- Bilişim projesinin sekiz aşaması: kavramsal çalışma, gereksinim, çözümleme, tasarım, gerçekleştirme, sınama, kurulum ve işletmeye alma, bakım.

## Detaylı Açıklamalar

- **Kaynak kodu emanetçisi ve haksız rekabet.** Bir programcı çalıştığı firmadan ayrılırken yazdığı kodun kopyasını alır, kendi firmasını kurar, renkleri ve yazı tiplerini değiştirip birkaç özellik ekleyerek ürünü eski firmanın müşterilerine daha ucuza satar. Eski firma haksız rekabet davası açar. Mahkeme kodu kendisi incelemez; teknik bilirkişi atar. Bilirkişi iki tarafın yazılımını yazılım mühendisliği ölçütleriyle tanımlar, hangi modüllerin aynı, hangilerinin yüzde kaç benzer olduğunu raporlar; karar hâkimindir. Kodunu önceden emanetçiye teslim etmiş firma "bu benimdir" savunmasını güçlendirir. Emanetçi ayrıca yazılımın son hâlini saklar; firma kapanırsa yazılımı satın almış kuruluşlar kodu oradan alabilir. Hoca bunu mahkemenin el koyduğu bir aracın teslim edildiği yediemine benzetti.
- **Ahilikten meslek odalarına.** Anadolu'da yaklaşık 700 yıl etkin olan ahi loncalarında önce ahlak, sonra beceri öğretilirdi. Etik dışı davrandığı için meslekten atılan biri ülkenin hiçbir yerinde o mesleği yapamazdı. Bugün meslek odaları benzer biçimde etik kurallar yayınlar ve uymayan üyelere meslekten men ya da süreli men cezası verebilir. Hoca, eğitim ve denetim gerektirmeden yapılabilen emlakçılık ve müteahhitlik örneklerini, meslek etiğinin işlemediği alanlar olarak eleştirdi.
- **Meslek etiğinin ilkeleri.**
  - Doğruluk: hem üstlere hem astlara karşı dürüst, adil ve tarafsız olmak; kuruluş dışında da ürün ve hizmetin özelliklerini müşteriye doğru aktarmak.
  - Yasallık: ürünün yasa, yönetmelik ve ölçünlere uyması (gıda kodeksi gibi; donanımda ekranın sağlığa zarar vermemesi, yazılımda ISO standartları), çalışmaların ulusal ve uluslararası çalışma yasalarına uyması, müşteri ve dış paydaşlarla ilişkilerin yasal olması. Yasaya aykırı bir emre "hayır" denmeli, gerekirse yetkili mercilere bildirilmelidir.
  - Yeterlik: yönetici, çalışanları yeteneklerine uygun işlere dağıtmalı ve onların kendilerini geliştirmesine imkân tanımalıdır.
  - Güvenilirlik: bütün etik kurallara uyan kişi güvenilir olur; uymayan önce müşterinin, sonra meslektaşların güvenini kaybeder, sonunda meslek örgütünden atılabilir.
  - Mesleğe bağlılık: mesleğini seven kişi kendini sürekli geliştirir, ekibin ve mesleğin saygınlığına katkı yapar.
- **Mühendisliğin hayata katkısı.** 1900'lerin başında 1.000 km'lik yol yaklaşık 20 günde gidilirken yüzyılın sonunda otoyollarla yaklaşık 10 saate, uçakla yaklaşık 1 saate indi. Telefon 1876'da icat edildi ve bir yüzyılda dünyanın temel iletişim aracı oldu; GSM 1991'de çıktı, hocanın hatırladığı kadarıyla Türkiye'ye 1994 civarında geldi ve bugün abone sayısı nüfusu aşıyor.
- **İnternet bankacılığı vakası (çözümleme).** Banka girişte müşteri numarası, parola ve SMS ile gelen tek kullanımlık parola (OTP) kullanıyordu. İş birimi, müşterilerin telefon numaralarını internet şubesinden kendilerinin değiştirebilmesini istedi. Mühendisler bunun "şifreli mektubun anahtarını aynı zarfa koymak" olduğunu söyleyip karşı çıktı, ama iş birimi kabul ettirdi. Sonra bir müşterinin numarası ve parolası oltalama ve tuş kaydedici ile çalındı; saldırgan internet şubesine girip kayıtlı telefonu kendi numarasıyla değiştirdi, havale onay SMS'leri kendisine geldi ve para aktarıldı. Dava sonunda banka haksız bulundu. Doğru tasarım, telefon numarasının yalnız şubeden ya da telefon bankacılığından değiştirilebilmesiydi. Ders: uzman, sorunu kesin biçimde ve yazılı olarak ortaya koymalı; uzman olmayan ama yaptırım gücü olan, uzmanlık alanı dışında karar vermemelidir.
- **Güvenlik, maliyet ve kullanışlılık dengesi.** Çalışan girişi için manyetik şeritli kart, fotoğraflı kart (iki seviyeli kontrol), akıllı kart ya da parmak izi, retina gibi biyometrik veri içeren kartlar kullanılabilir. Güvenlik arttıkça maliyet artar, kullanışlılık azalır. Hoca bunu x ekseni güvenlik olan bir grafikte, biri artan (maliyet) biri azalan (kullanışlılık) iki eğriyle çizdi. Kesişim noktasında mı, yoksa bir tarafta mı durulacağı projenin isterlerine göre seçilir. <!-- BELİRSİZ: Çizim 01:38-01:39 arasında yapıldı, karelerde görünmüyor; eğrilerin biçimi anlatımdan aktarıldı. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
