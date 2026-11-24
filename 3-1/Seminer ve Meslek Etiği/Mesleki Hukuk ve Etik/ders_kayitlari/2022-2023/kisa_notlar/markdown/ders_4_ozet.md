# Ders 4 Çalışma Özeti

## Genel Konular

- Kişinin özeli konusuna giriş
  - İnsanlar toplum hâlinde yaşamaya başladığından beri başkalarının hayatlarıyla ilgilenir: merak, çıkar ya da başkasının durumundan yararlanma ve ona zarar verme amacıyla.
  - Devlet yönetimleri de vatandaşları daha kolay yönetmek ve olası zararları öngörmek için insanlar hakkında bilgi toplar. 20. yüzyılda diktatörlük, faşist ve komünist yönetimler bu konuda çok katı uygulamalar yapmıştır.
  - Ticari kuruluşlar da rakiplerin gizli bilgilerini ele geçirip (örneğin bir ihalede) kendi lehlerine kullanabilir.
  - Eskiden bilgiler kâğıt ortamında arşivlenirdi. Bugün kişisel veriler dağıtık veri tabanlarında durur (kimlik bilgileri MERNİS'te, mali bilgiler vergi veri tabanlarında, çalışma hayatı SGK'da). Bu veriler veri madenciliği ve makine öğrenmesi yöntemleriyle birleştirilip anlamlandırılabilir; bu da yeni etik ve hukuk sorunları doğurur.
- Veri ve bilgi ayrımı
  - Veri bilgiyi temsil eder; bilgi ise veriyi anlamlandırır. Anlam kazanmış veriye bilgi denir.
  - Örnek: başlıksız sütunlarda E/K harfleri, 8-9-10 gibi sayılar, 120-125-117 gibi sayılar, saç ve göz renkleri, hobiler ve 85-80-77 gibi notlar yalnız veridir. Sütunlara "cinsiyet, yaş, boy (cm), saç rengi, göz rengi, hobi, not ortalaması" başlıkları konunca veri anlam kazanır. Bu verilerden "basketbol oynayanların çoğu erkek ve uzun boylu" gibi bir çıkarım yapılınca bilgi elde edilir ve yeni gelen biri için tahmin yapılabilir. <!-- BELİRSİZ: çıkarımdaki yüzde ve boy eşiği altyazıda bozuk (00:13:30). -->
  - Kanun "kişisel veri" dese de bu öğeler aslında bilgidir; dilde "kişisel veri" yerleşmiştir.
- Bireysel bilgilerin üç yaşam alanı (ekrandan, 00:10:00)
  - Genel yaşam alanı: bireyin herkesle paylaşabileceği bilgileri içeren, kamuya açık yaşam alanıdır.
  - Özel yaşam alanı: bireyin belli kişilerle belli ölçüde paylaşabildiği bilgileri içeren alandır.
  - Sır yaşam alanı: bireyin yalnız kendisinin bildiği, başkalarıyla paylaşmak istemediği ve sır olarak sakladığı bilgileri içeren alandır. Eski dildeki "mahrem" sözcüğü bu alana denk gelir.
  - Hoca bunu iç içe üç halka olarak çizdi: en içte sır, onu kapsayan özel, en dışta genel yaşam alanı.
- Temel tanımlar (ekrandan, 00:20:00)
  - Kişisel veriler: bireyin genel, özel ve sır yaşam alanına ilişkin bilgilerin tümü.
  - Bireyin özeli (privacy): bireyin özel ve sır yaşam alanı içinde kalan bilgileri. Bunların bazıları gerektiğinde paylaşılabilir; paylaşma kararını bilginin sahibi verir.
  - Kuruluşlar için de aynı ayrım yapılır: AR-GE ile elde edilen teknoloji sırları sır alanı; son üç ayın kâr-zarar gidişatı gibi çalışanların bir kısmının bildiği bilgiler özel alan; çalışma alanı, müşteriler, halka açık şirketin açıkladığı mali tablolar genel alandır.
  - Anahtar bilgiler (sensitive data): bireye ya da kuruluşa ilişkin bilinmesi, değiştirilmesi ya da silinmesi durumunda önemli etkisi olacak bilgiler.
  - Gözetleme (surveillance): bir bireyin ya da kuruluşun özeline ilişkin bilgilerin öğrenilmeye çalışılması eylemi; merak, ticari çıkar ve düzeni denetim altına alma amacıyla yapılır.
  - Veri tabanı: verilerin bilişim ortamında belli düzende tutulduğu, erişilebilen, güncellenebilen ve üzerinde hesap yapılabilen alanlar.
  - Veri ambarı: yapısı veri tabanına benzer, ama çok daha yüksek hacimli veri tutar; erişim ve hesap yapılabilir, ama güncelleme ve silme yapılmaz. Amacı veriler arasındaki ilişkileri bulmaktır.
  - Veri madenciliği: veri ambarındaki verilerde açıkça görülmeyen ilişkileri ayrıntılı analiz ve algoritmalarla ortaya çıkarma.
- Bireysel bilgilerin önemi ve kategorileri (ekrandan, 00:25:00)
  - Nüfus bilgileri: kimlik bilgileri genel yaşam alanı bilgisi değildir. Yalnız ad-soyad (kuruluşlarda ticari unvan) geneldir; T.C. kimlik numarası, doğum tarihi ve yeri, anne-baba adı, soy ağacı, din bilgisi özeldir. Kişi isterse anne-baba adı gibi bilgileri genel alana taşıyabilir (bazı ülkelerdeki ad geleneklerinde olduğu gibi), ama kimlik numarası özel kalmalıdır.
  - Sağlık bilgileri: özel, hatta sır yaşam alanında saklanması gereken bilgilerdir (kalıtsal hastalıklar, geçirilen hastalık ve kazalar, tedaviler, kullanılan ilaçlar). Askerlik ve iş başvurularında bu bilgilerin açığa çıkması ağır sonuçlar doğurabilir.
  - Biyolojik bilgiler: parmak izi, avuç içi deseni, retina gibi bilgiler insanı tanımlamada çok güçlü kanıt niteliği taşır; sır niteliğindedir ve üst derecede güvenlikle saklanmalıdır. Sayısallaşmış bir parmak izi sızarsa sahte izle kimlik doğrulama sistemleri aldatılabilir.
  - Mali bilgiler: özellikle kuruluşların mali bilgileri sır niteliğindedir; rakip firma bunları bilirse ihalede ya da zor durumdaki firmayı ucuza ele geçirmede avantaj sağlar.
  - Teknik bilgiler: teknoloji geliştiren kuruluşların AR-GE çalışmalarını öğrenmek rakipler için çok önemlidir; bunu ele geçirmeye teknoloji casusluğu denir.
  - Önemsiz görülen bilgiler: sanıldığından çok daha önemli sonuçlara yol açabilir.
  - Slayttaki sonuç: bir kişiye ilişkin bilgileri toplamak için artık dedektif gerekmez; kişi bu bilgileri farkında olmadan kendisi verir.
- Gözetleme (ekrandan, 00:50:00)
  - Toplumu tanımak ve düzeni sağlamak gibi masum gerekçelerle birey ve kuruluşları izleyip haklarında bilgi toplamaktır. Kamu kuruluşlarınca sürekli ve düzenli yapılır; yasal ya da yasa dışı yollarla olabilir.
  - Üç tür: yönetsel (nüfus, ikamet kayıtları; kuruluşların mali ve yerleşke kayıtları), istatistiksel (nüfus sayımları, kaynak araştırmaları), bilgiye dayalı (hukuki soruşturma amacıyla kolluk kuvvetlerince toplanan bilgiler).
  - Toplumu iyi tanımak planlama için yararlıdır, ama ayrıntı düzeyi sınırlı olmalıdır; aksi hâlde herkesin özel yaşamına girilir.
- Gözetleme ve tepkiler: kamunun isteği ile bireyin tepkisi tablosu (ekrandan, 00:55:00)
  - Kara para, ikamet, sağlık, iletişim içeriği, iletişim trafiği, nüfus kayıtları, kameralar, trafik fotoğrafları, hamilelik ve çocuk sayısı konularında kamu ile birey arasında denge kurulması gerekir.
- Günümüzde gözetleme (ekrandan, 01:00:00)
  - Cep telefonu, kredi kartı, e-posta ve sosyal ağ kullanan herkes sürekli gözetlenir (HTS kayıtları, baz istasyonu konumu, kart harcamaları).
  - Uyuşturucu örgütlerinin izlenmesinde iletişim trafiğindeki artış bir eylem hazırlığının işareti olarak kullanılır; kara para aklamanın izi bilgi teknolojileri ve veri madenciliğiyle sürülür.
  - George Orwell'in 1984 romanındaki "Big Brother" fikri bugün büyük ölçüde gerçek olmuştur.
- Gönüllü gözetlenme
  - Tarayıcı ve arama motorları (ekrandan, 01:05:00): reklam geliri anlaşılabilir, ama gezilen sayfaları izleyerek ilgi alanlarını, ürün tercihlerini, sosyal-kültürel yapıyı, siyasi görüşü ve inancı öğrenirler. Hiçbir ticari kuruluş bir hizmeti ücretsiz sunmaz; kullanıcı bilgilerini satarak büyük paralar kazanırlar.
  - E-posta hizmetleri (ekrandan, 01:10:00): bazı yaygın e-posta hizmetlerinin her e-postanın içeriğini incelediği anlaşılmıştır. Evrensel İnsan Hakları Bildirgesi'nin 12. maddesi haberleşmenin gizliliğini korur; e-posta trafik bilgileri belli süre saklanabilir, ama içeriğe asla bakılmamalıdır.
  - Sosyal ağlar: duygu ve düşüncelerden duygu analizi yapılıp ürün yorumları ve beğeni oranları firmalara, yöneticilere, konaklama ve yemek firmalarına, kolluk kuvvetlerine satılabilir.
  - Mesajlaşma hizmetleri (ekrandan, 01:15:00): 1995-96 yıllarında yaygın kullanılan bir mesajlaşma programının bir ülkenin istihbarat kuruluşuna hizmet verdiği sonradan anlaşılmıştır. Reklam geliri olmayan bir programın milyarlarca liraya satılmasının bir nedeni vardır.
  - Navigasyon uygulamaları: kim olduğunuz ve herhangi bir anda nerede olduğunuz saniyesine kadar izlenebilir.
  - Danışmanlık siteleri: örneğin sağlık forumlarında paylaşılan hastalık ve ilaç bilgileri ilaç üreticilerine aktarılıp para kazanılabilir.
  - Özet: bedava hizmet alırken bedava bilgi verirsiniz.
- Gönüllü gözetlenmenin sonuçları (ekrandan, 01:20:00)
  - Ücretsiz hizmet veren kuruluşların asıl amaçlarını araştırmak kamunun görevidir. Sorulacak sorular: istenen bilgilerin niteliği (genel, gizli ya da sır), bireyin bilgisi dışında bilgi toplanıyor mu, ne amaçla, onay alınıyor mu, elde edilecek sonuçlar bireye bildiriliyor mu, ne sonuçlar üretiliyor, ticari amaçla kullanılıyor mu, başka firmalara satılıyor mu (hoca: yurt dışına aktarılıyor mu?).
  - Kullanıcı sözleşmeleri küçük puntolu ve çok uzun olduğu için kimse okumadan onaylar; onaylamadan hizmet de kullanılamaz.
  - Bireylerin bilgisizliğini ya da iyi niyetini sömürerek para kazanılmasının önüne geçilmelidir; bu, mali müfettişler için yeni bir görev alanı olabilir.
- Bireysel bilgilerin korunması (ekrandan, 01:25:00)
  - İnsanlar verdikleri bilgilerin başka amaçla kullanılacağını, farklı kuruluşlardaki bilgilerin birleştirileceğini ve ilgisiz kişilerce görülebileceğini düşünmezler.
  - Dünyada tek bir uzlaşı yoktur: Avrupa çok sıkı korur (GDPR); hocaya göre Kanada yalnız sağlık bilgilerini özel sayar, ABD anayasasında özel yaşamın gizliliği anayasal hak olarak yer almaz.
    - Ders sonrası not: Kanada ve ABD hakkındaki bu ifadeler büyük olasılıkla fazla basitleştirilmiştir. Kanada'da özel sektör için genel bir kişisel veri koruma yasası (PIPEDA) vardır; ABD'de genel bir federal yasa yoktur, ama sağlık (HIPAA) gibi alanlarda sektörel yasalar bulunur.
  - Hukuki yaklaşımlar: mülkiyet hakkı görüşü (pek benimsenmez), fikri mülkiyet hakkı görüşü, günümüzde genel kabul gören insan hakları yaklaşımı (temel özgürlükler ve insan onuru).
  - Özgür bir kişi onurlu bir kişi olarak kabul edilir; bildirdiği bilgilerin nerede saklandığını, kimlerce görüleceğini ve paylaşılacağını bilme hakkı vardır. Bu hak yoksa özgür karar veremez; örneğin toplantı ve yürüyüşe katılanların görüntü kaydına alınması insanları katılmaktan caydırabilir.
  - Bu hak sonsuz değildir: zorunlu ve gerekli durumlarda yasalara uyularak bilgiler kullanılabilir ve paylaşılabilir.
- Bireysel bilgilerin gizliliği ve düşünceyi açıklama özgürlüğü (ekrandan, 01:30:00)
  - Bireysel bilgilerin gizliliği ile basın özgürlüğü zaman zaman çarpışır. Sanat ve spor dünyasının ünlüleri bilinmeyi kendileri ister; basın da topluma mal olmuş kişilerin özel hayatının bilinmek isteneceğini savunur ve bazen sır alanına ilişkin bilgileri bile yayımlar.
  - Ünlülere ilişkin bilgiler yayımlanırken bireysel bilgilerin korunması ile basın özgürlüğü ilkeleri karşılaştırılıp denge kurulmalıdır.
- Uluslararası çalışmalar (ekrandan, 01:35:00 ve 01:40:00)
  - Tarihsel kökler: Hipokrat yemini (MÖ 5. yüzyıl, hekimin hasta sırrını saklaması), Katolik papazların günah çıkarmada duyduklarını saklama yükümlülüğü.
  - Önemli bildirgeler: BM Evrensel İnsan Hakları Bildirgesi, BM Uluslararası Bireysel ve Siyasal Haklar Sözleşmesi (17. madde, İnsan Hakları Komitesi 16. genel yorum), Avrupa İnsan Hakları Sözleşmesi.
  - OECD'nin ilkeleri (ilk çalışma): bilgi toplama sınırlı, bilgiler belli nitelikte, amaç belli, kullanım alanı sınırlı, güvenlik sağlanmalı, kullanımda açıklık, bilgiler üzerinde sahibinin hakkı, toplayan kuruluş hesap verebilir olmalı.
  - İnsan Hakları Bildirgesi Madde 12: "Hiç kimse özel yaşamına, ailesine, konutuna ya da haberleşmesine yönelik keyfî müdahalelere ya da onur ve şöhretine yönelik saldırılara maruz bırakılmayacaktır. Herkesin bu tür müdahale ya da saldırılara karşı yasa ile korunma hakkı vardır." (ekrandan, 01:35:00)
  - BM 1990, Bilgisayara Geçirilmiş Kişisel Veri Dosyalarına İlişkin Rehber İlkeler: yasal ve dürüst toplama, doğruluk, amacın belli olması, ilgili kişinin erişimi, ayrımcılık yapılmaması, güvenlik, saklayan kuruluşun denetlenebilir ve yaptırım uygulanabilir olması, diğer ülkelere güvenli aktarım (ekrandan, 01:40:00).
  - Avrupa Konseyi kişisel verilerin korunması sözleşmesi: bilgiler belirli ve nitelikli olmalı, anahtar bilgiler özel olarak korunmalı, güvenlik sağlanmalı, ilgili kişinin bilgi alma, verilere ulaşma ve düzeltme hakkı olmalı.
  - Ülkeler arası aktarım hâlâ kesin çözüme ulaşmamış bir konudur.
- Türkiye'deki düzenlemeler
  - 6698 sayılı Kişisel Verilerin Korunması Kanunu (KVKK): AB uyum yasaları çerçevesinde 24 Mart 2016'da kabul edildi, 7 Nisan 2016'da Resmî Gazete'de yayımlanarak yürürlüğe girdi; Avrupa Konseyi ilkelerine uygun yazılmıştır.
  - Anayasa madde 20 (özel hayatın gizliliği), madde 21 (konut dokunulmazlığı), madde 22 (haberleşme hürriyeti).

## Hocanın Özellikle Vurguladığı Kısımlar

- Kimlik numarası genel bilgi değildir
  - Hoca kimlik fotokopisi alınmasını yanlış bir uygulama olarak niteledi; doğrulama yalnız kimlik numarası üzerinden sistem entegrasyonuyla yapılmalıdır.
  - Bankaların istediği anne kızlık soyadı ya da yakının kimlik numarası gibi güvenlik bilgileri ele geçirilirse kişinin adına vergi sistemine girilip yanlış beyanlar verilebilir.
- Sağlık bilgileri sır alanındadır
  - Yanlış hastaya ait bir tahlil raporunun eve postalanması ve babanın okuması örneği: kızının hamile olduğunu sanan tutucu bir baba evlatlıktan reddetme noktasına gelir; sonradan raporun başka hastaya ait olduğu anlaşılır. Hoca bunun çok daha kötü sonuçlar doğurabileceğini vurguladı.
  - Bir kişinin antidepresan kullandığının bilinmesi, işinde başarılı olsa bile işe alınmamasına yol açabilir.
- Önemsiz görülen bilgiler de zarar verebilir
  - Kuyumcunun sadakat kartı veri tabanındaki "eşin doğum günü" bilgisiyle bir yıl sonra eve hediye yollaması, aile yaşamını sarstı.
  - Bir öğretim üyesinin notları adlarla birlikte açık bir Excel dosyasında yayımlaması, yıllar sonra öğrencinin iş başvurusunda aleyhine kullanıldı. Notlar giriş yapılan kapalı bir sistemden ya da yalnız numara ile duyurulmalıdır.
- "Bedava hizmet alırken bedava bilgi veriyorsunuz"
  - Ücretsiz tarayıcı, arama motoru, e-posta, sosyal ağ, mesajlaşma, navigasyon ve danışmanlık hizmetlerinin arkasında bilgi satışı vardır. Hoca bu hizmetleri veren kuruluşların nasıl bu kadar para kazandığının hiç akıldan çıkarılmaması gerektiğini söyledi.
- Kamu ile birey arasında denge
  - Gözetlemenin kapsamı ve ayrıntısı arttıkça hür toplumdan uzaklaşılır; Nazi Almanyası ve Sovyetler Birliği en kötü örnekler olarak bilinir.
  - İletişim içeriği ve trafiği ancak hukuki soruşturma kapsamında hâkim izniyle izlenebilir.
- Anayasanın 20, 21 ve 22. maddeleri kişinin özeli konusunda temel maddelerdir.

## Kısa Tekrar Notları

- Veri bilgiyi temsil eder, bilgi veriyi anlamlandırır.
- Üç yaşam alanı: genel (herkes), özel (belli kişiler, belli ölçüde), sır (yalnız kişi; "mahrem").
- Kişisel veri = genel + özel + sır alanındaki tüm bilgiler; bireyin özeli (privacy) = özel + sır.
- Anahtar bilgi (sensitive data): bilinmesi, değiştirilmesi ya da silinmesi önemli etki yaratan bilgi.
- Veri ambarında güncelleme ve silme yapılmaz; veri madenciliği gizli ilişkileri bulur.
- Kategoriler: nüfus, sağlık, biyolojik, mali, teknik, önemsiz görülen bilgiler.
- Gözetleme türleri: yönetsel, istatistiksel, bilgiye dayalı.
- Gönüllü gözetlenme: tarayıcı/arama motoru, e-posta, sosyal ağ, mesajlaşma, navigasyon, danışmanlık siteleri.
- Hedefli reklam örneği: genel reklam gösterim başına 1 sent, çok dar kırılımlı hedef kitle için 1 dolar, yani 100 kat.
- Korunma yaklaşımları: mülkiyet hakkı, fikri mülkiyet hakkı, insan hakları (genel kabul gören).
- Koruma hakkı sonsuz değildir; zorunlu durumlarda yasaya uygun paylaşım olabilir.
- OECD ilkeleri, BM 1990 Rehber İlkeleri, Avrupa Konseyi sözleşmesi; GDPR ve KVKK bu ilkeleri neredeyse birebir taşır.
- KVKK: 6698 sayılı, kabul 24.03.2016, yürürlük 07.04.2016.
- Anayasa: md. 20 özel hayatın gizliliği, md. 21 konut dokunulmazlığı, md. 22 haberleşme hürriyeti.

## Detaylı Açıklamalar

- **Bilgi neden bu kadar değerli hâle geldi?** Eskiden bir kişinin özel ve sır alanına ilişkin bilgi toplamak dedektiflik gibi ciddi insan emeği gerektirirdi ve bu bilgiler istihbarat olduğu için paylaşılmazdı. Bugün bir e-ticaret alışverişinde bile kimlik numarası, kredi kartı, ödeme gücü ve adres bilgileri birçok veri tabanına kaydedilir. Sosyal medyada sevdiğimiz sanat etkinlikleri, meraklarımız, becerilerimiz ve beğenilerimiz üç yaşam alanının hepsinden bilgi barındırır. Ticari kuruluşlar "doğum gününüzde indirim" gibi masum havuçlarla doğum tarihi gibi özel bilgileri toplar. Farklı kurumlardaki bu dağınık bilgiler birleşince kişi hakkında kapsamlı bir gözetleme oluşur.

- **Nüfus bilgileri ve kimlik numarası.** Ad ve soyad genel alandadır; diğer tüm nüfus bilgileri özeldir. MERNİS veri tabanında soy ağacı ve din bilgisi de bulunur ve hocaya göre bu kayıtlar 1923'ten bu yana bütün Türk vatandaşları için tutulmaktadır. Hoca, kimlik numaralarının düzenleniş biçiminden yola çıkarak soy ağacındaki diğer kişilerin numaralarına ve kişinin kökenine ulaşılabileceği yönündeki bir söylentiyi aktardı ve bu nedenle kimlik numarasının özel kalması gerektiğini söyledi.
  > **Ek bilgi (derste anlatılmadı):** T.C. kimlik numarasının son iki hanesi ilk dokuz haneden hesaplanan denetim haneleridir. Numaradan akrabalık ilişkisi çıkarılabileceği iddiası resmî olarak doğrulanmış bir bilgi değildir, büyük olasılıkla bir söylentidir; hoca da bunu "söylenti ya da varsayım" diye sundu.

- **Biyolojik bilgilerin riski.** Parmak izi bir tabancanın üzerinde bulunursa güçlü kanıt sayılır. Ama sayısal ortamda saklanan bir parmak izi ele geçirilirse silikon bir etikete basılıp başka birinin parmağına yapıştırılabilir ve kimlik doğrulama sistemleri aldatılabilir. Hoca, ülkelerin giriş-çıkışlarda ve pasaport işlemlerinde parmak izi almasıyla bu bilginin birçok veri tabanına girdiğini, sızma durumunda kötü niyetle kullanılabileceğini anlattı. İmza biyolojik olmasa da benzer bir kanıt değeri taşır.

- **Mali bilgiler ve ihale örneği.** Rakibin borçlu ve sıkıntıda olduğunu bilen fırsatçı bir firma onu düşük bedelle ele geçirmeye çalışabilir. Hoca güncel bir örnek olarak bankacılık krizinde zor duruma düşen Credit Suisse'in UBS tarafından çok düşük bir bedelle alınmaya çalışılmasını verdi.
  > **Ders sonrası not:** Hoca bedeli "1 milyar ... para birimi" diye belirsiz söyledi; anlaşma büyük olasılıkla Mart 2023'te yaklaşık 3 milyar İsviçre frangı üzerinden duyurulmuştur.

- **Gözetleme ve tepkiler tablosu (ekrandan, 00:55:00).** Kamu kara para için banka hesaplarını, düzen için ikameti, toplum sağlığı için sağlık durumunu, düzen için iletişim içeriğini ve trafiğini, toplumun yapısı için nüfus kayıtlarını, kötü kişiler için kameraları, trafik ihlali için fotoğrafları, nüfus planlaması için hamilelik ve çocuk sayısını izlemek ister. Birey ise her birinde bunun özel ya da sır alana girdiğini, iletişim hakkının evrensel olduğunu, kendi kararının kamuya bırakılamayacağını savunur. Hız kamerası fotoğrafında sürücünün yanındaki kişinin görünmesi gibi olaylardan sonra kayıtlarda ön cam bulanıklaştırılarak gösterilmeye başlanmıştır.

- **Hedefli reklamın ekonomisi.** Tarayıcı ve arama motoru firmaları kullanıcıları izleyerek çok ince kırılımlar oluşturur. Hocanın örneğinde genel reklam için gösterim başına 1 sent alınırken, "18-23 yaş, ailesinden uzakta yaşayan, makine mühendisliği okuyan üniversite öğrencileri" gibi dar bir kitle için gösterim başına 1 dolar istenir; bu 100 kat fazladır (1 dolar = 100 sent).

- **Korunma hakkının temeli.** İnsan hakları yaklaşımı bireysel bilgilerin korunmasını yalnız kişisel çıkar olarak değil, temel özgürlükler ve insan onuru açısından görür. Kişi bilgilerinin nasıl kullanılacağını bilmezse özgür karar veremez; bilgileri elinde tutanların baskı kurabileceği düşüncesi onu toplumsal yaşamdan uzaklaştırabilir.

- **Avrupa Konseyi sözleşmesinin tarihi.** Hoca sözleşmenin 28 Ocak 2007'de hazırlandığını söyledi.
  > **Ders sonrası not:** Avrupa Konseyi'nin Kişisel Verilerin Otomatik İşlenmesi Karşısında Bireylerin Korunması Sözleşmesi (108 sayılı sözleşme) büyük olasılıkla 28 Ocak 1981'de imzaya açılmıştır; 28 Ocak, 2007'den beri Veri Koruma Günü olarak kutlanmaktadır.

- **Anayasa maddeleri.** Madde 20: "Herkes, özel hayatına ve aile hayatına saygı gösterilmesini isteme hakkına sahiptir. Özel hayatın ve aile hayatının gizliliğine dokunulamaz." İstisna adli soruşturma ve kovuşturmadır. Madde 21: "Kimsenin konutuna dokunulamaz." Millî güvenlik, kamu düzeni, suç işlenmesinin önlenmesi gibi sebeplerle hâkim kararı ya da gecikmede sakınca olan hâllerde yetkili merciin yazılı emri olmadıkça konuta girilemez, arama yapılamaz, eşyaya el konulamaz. Madde 22: "Herkes, haberleşme hürriyetine sahiptir. Haberleşmenin gizliliği esastır."

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
