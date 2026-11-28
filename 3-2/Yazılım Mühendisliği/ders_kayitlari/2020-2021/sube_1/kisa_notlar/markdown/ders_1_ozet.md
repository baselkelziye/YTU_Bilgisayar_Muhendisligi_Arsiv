# Ders 1 Çalışma Özeti

> Kayıt iki parçadır; arşivde parçalar yanlış sırada birleştirildiği için altyazıdaki sıra düzeltildi ve saat damgaları düzeltilmiş altyazıya göredir.

## Genel Konular

- Dersin kapsamı ve sistem analizi dersiyle ilişkisi
  - Yazılım Mühendisliği, sistem analizi dersinde fizibilite çalışmasından bilgi sisteminin kullanıma alınmasına kadar bütünsel olarak görülen geliştirme sürecinin devamıdır; bu derste analiz ve tasarıma daha fazla ağırlık verilir, proje yönetimi daha geniş ele alınır ve sistem analizinde girilmeyen test tarafı da işlenir.
  - Dersin ana konuları: yazılım mühendisliğine giriş, süreç modelleri (klasik modeller: şelale, spiral vb.; çevik modeller), gereksinim mühendisliği, yazılım tasarımı, nesneye yönelik çözümleme ve tasarım, yazılım kalite özellikleri ve ölçütleri, yazılım mimarisi, test teknikleri, yazılım proje yönetimi, risk yönetimi ve konfigürasyon yönetimi; zaman kalırsa yeniden mühendislik (*re-engineering*) ve tersine mühendislik (*reverse engineering*) (ekrandan, 00:10:45).
  - Analiz ve tasarım nesneye yönelik yaklaşımla yapılır; belirli bir programlama dili şart değildir.
- Gereksinim mühendisliğinin önemi
  - Sistem analizinde gereksinim aşaması "bilgi toplama, modelleme, raporlama" diye düz bir bakışla görülmüştü; bu derste gereksinim analizi (*requirement analysis*) daha kapsamlı ele alınıp alt başlıklara bölünecek (Pressman'ın *Requirements Engineering* bölümü).
  - Problem alt problemlere ayrılır, problemle ilgili taraflar (paydaşlar) incelenir, her tarafın problemi nasıl gördüğü ve anlattıkları toplanır ve bunların kesişim noktaları yakalanır.
  - Problem yanlış anlaşılırsa çözüm de tasarım da yanlış olur; bu yüzden önce doğru anlamak ve doğru alt başlıklara ayırmak gerekir. Sektörde bu adıma giderek daha çok önem verilmektedir.
- Kaynak kitaplar (ekrandan, 00:45:45)
  - Roger S. Pressman, *Software Engineering: A Practitioner's Approach*, McGraw-Hill, 2014, 8. baskı (derste ağırlıklı olarak izlenen kitap).
  - Craig Larman, *Applying UML and Patterns: Intro. OOAD & Iterative Development*, Prentice-Hall, 2004, 3. baskı.
  - Ian Sommerville, *Software Engineering*, Pearson, 2015, 10. baskı.
  - Martin Fowler, *UML Distilled*, Addison-Wesley, 2003, 3. baskı.
- Yazılım mühendisliğinin tanımı (ekrandan, 00:50:45)
  - "Kaliteli yazılımı en ekonomik olarak hazırlamak üzere mühendislik araçlarını ve yeteneklerini kullanan bilim dalıdır." Tanımdaki altı çizili üç kavram: **kaliteli yazılım**, **en ekonomik**, **mühendislik**.
  - Kaliteli yazılım: kullanıldığı sürece hatayı en aza indiren, kullanıcının istediğini gerçekleştiren ve kalite özelliklerini sağlayan yazılım. Bu, testin iyi yapılmasını gerektirir; yeterli testle hatalar büyük ölçüde arındırılır ama tamamen yok edilemez. Kalite özellikleri ileride IEEE'nin ve McCall'ın tanımlarına göre işlenecek.
  - En ekonomik: en ucuz demek değildir; harcama ile fayda arasındaki en uygun dengedir. Sistem analizindeki ekonomik fizibilite ile bağlantılıdır; iyi zaman ve kaynak planlamasına (en önemli kaynak: geliştiriciler, test uzmanları, analistler) dayanır.
  - Mühendislik: mühendisin en önemli iki aracı/yeteneği **tasarım** ve **ölçüm**dür. Ölçme sayesinde biten bir ürün sonraki ürünlerle kıyaslanabilir ve yeni ürünün maliyeti tahmin edilebilir.
- Yazılım mühendisliğinin alt başlıkları (ekrandan, 01:19:08)
  - Yazılım geliştirme süreçleri; yazılım kalitesi ve test; yazılım proje yönetimi ve planlaması; mühendislik araç ve yetenekleri (tasarım, ölçüm). Tasarım genişletilerek yazılım mimarisi olarak da ele alınır.
- Yazılımın tanımı ve yaşam döngüsü (ekrandan, 01:19:08; ekrandan, 01:10:45)
  - Yazılım: herhangi bir boyuttaki herhangi bir tür donanımda çalışan bilgisayar programı **ve** basılı veya elektronik ortamdaki her tür dokümanı içeren üründür; dokümanlar yazılım geliştirmeye (bakım yapacaklara) ve son kullanıcıya yönelik olabilir. İlişkili veri hakkındaki bilgi de yazılıma dahildir.
  - Yazılım bir üründür, ancak başka ürünler geliştirmeye veya elde etmeye yarayan bir araç da olabilir.
  - Yaşam döngüsü (*software life cycle*): yazılımın bir fikir olarak doğmasından kullanım dışı bırakılmasına kadar geçen süreç (geliştirme, kullanım, bakım, son buluş).
  - Yazılım fiziksel bir ürün olmadığı için aşınmaz, ancak zamanla yetersizleşebilir: değişim kaçınılmazdır, değişiklikler yeni hatalar oluşturabilir, yeni hatalar tam düzeltilmeden yeni değişiklikler gerekebilir. Çözüm: yazılım mühendisliği ilkelerine uyularak daha iyi tasarlanmış yazılım.
- Yazılım türleri
  - Sistem yazılımı (işletim sistemleri gibi), mühendislik yazılımı, gömülü (*embedded*) yazılım (donanımla sıkı ilişkili, örneğin araçların içinde çalışan), işletmecilik/kurumsal yazılımlar (ERP, CRM gibi; yönetim bilgi sistemleri dersinde ayrıntılı görülür), uygulama yazılımları.
  - Uygulama yazılımları genellikle işletmecilik ya da mühendislik alanında kullanılır; iş gereksinimleri için sürekli bakımda tutulur ve zamanla eski yazılıma (*legacy software*) dönüşebilir.
- Eski yazılım (*legacy software*) (ekrandan, 01:24:08)
  - İş sürecinin önemli bir parçası olan ve çok uzun süredir kullanılan yazılımlar.
  - Olumsuzluklar: eksik veya hatalı dokümantasyon (en kötü tarafı), zamanla karmaşıklaşmış kod, esnek olmayan yapı, eski donanımla çok sıkı ilişki, yazılım mühendisliğindeki gelişmelerden yoksunluk nedeniyle düşük kalite.
  - Değiştirilmesini gerektiren nedenler: iş alanındaki yeni gereksinimler, güncel sistemlerle birlikte çalışabilmesi için uyumluluk, donanımın ömrünün dolması nedeniyle güncel ortama taşınma. Altyapıyı bilen az kişi kaldığı için güncelleme zordur.
- Yazılımı etkileyen eğilimler (ekrandan, 01:29:08)
  - Yaygınlaşan bilgi-işlem: hesaplama gücünün giderek küçülen alanlara sıkıştırılabilmesi bilişimi günlük yaşamla bütünleştiriyor.
  - Yaygınlaşan haberleşme ağı: kablosuz ağların yaygınlaşması aynı bütünleşmeyi destekliyor.
  - Özgür / açık kaynak yazılım: gevşek bir ekip tarafından geliştirilen yazılım daha anlaşılır ve geliştirilebilir olmalıdır.
  - Ayrıca: takım çalışması zorunluluğu, küreselleşme, ekonomik krizler.
- Yazılım geliştirmedeki paydaşlar ve yanılgılar
  - Paydaşlar: müşteri, yönetici, programcı (teknik ekip) ve kullanıcı. Müşteri yazılımı satın alan/hizmet alan taraftır (örneğin bankaya yazılım geliştiriliyorsa banka yönetimi); kullanıcı (*end user*, uç kullanıcı) yazılımı fiilen kullananlardır (banka memurları ya da banka müşterileri).
  - Müşteri açısından yanılgılar (ekrandan, 01:34:08): "amaçları genel olarak belirlemek yeter, ayrıntılar sonra kararlaştırılır" (belirsiz gereksinimler çürük atılmış temele benzer); "yazılım esnektir, değişen gereksinimler kolayca uyarlanır" (yaşam döngüsünde ilerledikçe değişikliğin bedeli üstel olarak artar). Sonuç: yazılım esnek bir oyun hamurundan çok kil veya cam gibidir; çevik süreçlerle esnekliğin artırılması hedeflenir. Ayrıca "ne istediğimi söyledim, gerisi yazılımcının işi" yanılgısı: müşterinin her adımda bilgi vermesi ve ara ürünleri kontrol etmesi gerekir.
  - Programcı açısından yanılgılar (ekrandan, 01:39:08): "teslim edince işimiz biter" (çabanın yarısından fazlası ilk teslimattan sonra harcanır); "tamamlamadan kalitesini ölçemem" (kalite güvence yöntemleri her aşamada uygulanabilir, çözümlemede bile kullanılabilecek kalite ölçütleri vardır); "yazılım eşittir program" (gereksinim analizi, dokümantasyon, sınama ve bazen entegrasyon da yazılımın parçasıdır); "yazılım mühendisliği gereklerini uygulayarak boşuna çaba harcıyoruz" (haritası olmayan yolunu kaybeder; kalite için harcanan çaba ileride fazlasıyla karşılık bulur; küresel ölçekte yazılım projelerinin %50'si başarısızlığa uğramaktadır).
  - Yönetici açısından yanılgılar: "işler yetişmiyorsa takıma yeni programcı ekleriz" (proje planlamayla başlanmalı, eleman plana göre eklenmeli); "yazılımın tamamını veya bir kısmını fason yaptırabilirim" (alt yükleniciler baştan planlanmalı, takibi ve kontrolü iyi yapılmalı); açık kaynaklı yazılım konusundaki yanılgılar.
- Yazılım süreçlerinin genel adımları (ekrandan, 01:44:08; ekrandan, 01:49:08)
  - Çözümleme (*Analysis*), Tasarım (*Design*), Gerçekleme (*Implementation*), Sınama (*Testing*), Bakım (*Maintenance*). Bu adımlar planlama, proje yönetimi, konfigürasyon yönetimi, risk yönetimi ve kalite yönetimi gibi destek etkinlikleriyle iyileştirilir.
  - Çözümleme: bir şeyi anlayabilmek için parçalarına ayırmak; gerçeklenecek sistemi anlamaya yönelik çalışmalardan ve üst düzey planlama eylemlerinden oluşur (uygulama alanı, kullanıcı gereksinimleri, program parçaları arasındaki üst düzey ilişkiler ve etkileşimler; NYP'deki parçalar: sınıflar ve nesneler). "Bir sorunu anlamadan çözemezsiniz." "Ne" sorusuna cevap aranır.
  - Tasarım: gereksinim analizinde alınan veriye göre çözümü planlama ve model oluşturma; plan ve şemalar hazırlanır.
  - Gerçekleme: tasarımın bir programlama diliyle kodlanması.
  - Sınama: süreçte ilerledikçe hataların giderilme maliyeti üstel olarak artar; hataların büyük çoğunluğunun kökeni isteklerin belirlenmesi ve tasarım aşamalarındaki sorunlardır; bu yüzden erkenden, sık sık ve kolay sınama yapılmalıdır.
  - Bakım: kod, tasarım veya analiz hatalarının düzeltilmesi, değişen işlevlere uyum, yazılımın daha etkin hale getirilmesi. Yeniden mühendislik (*re-engineering*) ve yeniden düzenleme (*refactoring*): işlevi değiştirmeden iç yapıyı değiştirmek, belgelemek, tasarımı iyileştirmek, farklı bir ortama taşımak.

## Hocanın Özellikle Vurguladığı Kısımlar

- Yazılım, program demek değildir
  - Gereksinim analizinden başlayarak hazırlanan bütün dokümanlar, test çalışması ve veri bilgisi programla birlikte yazılımı oluşturur. Hoca bunu hem yazılım tanımında hem de programcı yanılgılarında tekrar vurguladı.
- Gereksinimlerin baştan doğru belirlenmesi
  - Gereksinimleri sonradan eklemek iş gücünü artırır; değişiklikler baştan gözden geçirme ya da yeniden yapma gerektirebilir. Yazılım mühendisliği gereklerini (dokümantasyon, tasarım, iyi gereksinim analizi) "işi boşuna uzatmak" sanmak en önemli yanılgılardan biridir; temel sağlam kurulmazsa projeler başarısız olur.
- "Ekonomik" en ucuz değildir
  - Harcama ile fayda arasındaki en uygun noktadır; ekonomik fizibiliteyle ve iyi planlamayla ilgilidir.
- Mühendisliğin iki temel aracı: tasarım ve ölçüm
  - Ölçme, yapılan işi değerlendirmeye ve gelecekteki ürünlerin maliyetini tahmin etmeye yarar.
- Hatalar ne kadar geç bulunursa o kadar pahalıdır
  - Bu nedenle yazılım ara gözden geçirmelerle (*review*) ve erken, sık sınamayla denetlenmelidir; kalite ölçütleri tamamlanmadan da uygulanabilir (örneğin kod karmaşıklığı ve güvenilirlik ölçüleri).

## Kısa Tekrar Notları

- Yazılım mühendisliği: kaliteli yazılımı en ekonomik olarak hazırlamak üzere mühendislik araçlarını ve yeteneklerini kullanan bilim dalı.
- Yazılım = program + basılı/elektronik dokümanlar (+ ilişkili veri bilgisi).
- Yaşam döngüsü: fikir olarak doğuştan kullanım dışı bırakılmaya kadar geçen süreç.
- Yazılım aşınmaz, ama değişikliklerle biriken hatalar yüzünden yetersizleşir.
- Legacy software: kritik ama hantal; eksik/hatalı dokümantasyon en büyük sorunudur.
- Eğilimler: yaygınlaşan bilgi-işlem, kablosuz ağlar, açık kaynak, takım çalışması, küreselleşme, ekonomik krizler.
- Yanılgılar üç bakış açısından: müşteri, programcı, yönetici.
- Müşteri ile kullanıcı farklı olabilir: müşteri yazılımı alan kurum/yönetim, kullanıcı (uç kullanıcı) fiilen kullanan kişi.
- Yazılım oyun hamuru değil, kil veya cam gibidir; değişiklik maliyeti üstel artar.
- Süreç adımları: çözümleme, tasarım, gerçekleme, sınama, bakım; destek etkinlikleri: planlama, proje/konfigürasyon/risk/kalite yönetimi.
- Çözümleme "ne" sorusunu cevaplar: "Bir sorunu anlamadan çözemezsiniz."
- Erkenden, sık sık ve kolay sınama yapın.
- Bakım: düzeltme, uyum, iyileştirme; re-engineering ve refactoring işlevi değiştirmeden iç yapıyı değiştirir.

## Detaylı Açıklamalar

- Ders, yazılım mühendisliğini sistem analizi dersinin üzerine kurar. Sistem analizinde bir bilgi sisteminin ön inceleme ve fizibilite çalışmasından kullanıma alınmasına kadar olan süreç tanıtılmış ve gerçek hayata benzer bir grup projesi geliştirilmişti. Bu derste de bir proje vardır, ancak analiz ve tasarım nesneye yönelik yaklaşımla ve daha profesyonel biçimde yapılacak, proje yönetimi daha geniş tutulacak ve test etkinlikleri de eklenecektir. Gereksinim mühendisliği bu açıdan özel bir yer tutar: problem alt başlıklara ayrılır, her paydaşın bakış açısı ayrı ayrı incelenir ve bu bakış açılarının ortak noktaları bulunur. Problemin yanlış anlaşılması, ne kadar iyi kodlanırsa kodlansın yanlış bir çözüm demektir.
- Yazılım mühendisliği tanımındaki her kavram dersin bir alt başlığına karşılık gelir. "Kaliteli yazılım" kalite özellikleri ve test konularını, "en ekonomik" proje yönetimi ve planlamasını, "mühendislik araçları ve yetenekleri" ise tasarım (ve onun genişletilmiş hali olan yazılım mimarisi) ile ölçüm konularını kapsar. Süreçlerin nasıl kurulacağı da yazılım geliştirme süreçleri başlığında görülür. Ekonomik olmak, maliyeti ne olursa olsun yazılım üretmek ya da en ucuz yolu seçmek değil; fayda ile harcamayı dengelemektir. Bunun için zaman ve kaynak planlaması, özellikle de insan kaynağının iyi kullanılması gerekir.
- Yazılımın fiziksel ürünlerden farkı, aşınmaması ama zamanla yetersizleşmesidir. Yaşam döngüsü boyunca değişiklik kaçınılmazdır; her değişiklik yeni hatalara yol açabilir ve bu hatalar tam düzeltilmeden yeni değişiklik istekleri gelebilir. Uzun süre bu şekilde yaşayan yazılımlar eski yazılıma (*legacy software*) dönüşür: kurumun kritik işlerini yürütürler, ancak kodları düzeltmelerle karmaşıklaşmış, yapıları esnekliğini yitirmiş, eski donanıma sıkı bağlanmış ve dokümantasyonları eksik ya da hatalıdır. Yeni iş gereksinimleri, güncel sistemlerle birlikte çalışma ihtiyacı ve donanımın ömrünün dolması bu yazılımların değiştirilmesini zorunlu kılar; altyapıyı bilen kişi sayısı az olduğundan bu değişiklik zordur.
- Yazılım geliştirmede farklı paydaşların farklı yanılgıları vardır. Müşteri, gereksinimleri sonra netleştirebileceğini ve yazılımın her değişikliğe kolayca uyacağını düşünebilir; oysa belirsiz gereksinimler çürük bir temel gibidir ve değişikliğin maliyeti zamanla üstel olarak artar. Bu yüzden yazılım oyun hamurundan çok kil ya da cama benzetilir. Çevik süreçler müşteriyi baştan sürece katarak esnekliği artırmayı hedefler. Programcı, teslimatla işin bittiğini, kalitenin ancak sonda ölçülebileceğini, yazılımın yalnız koddan ibaret olduğunu ya da mühendislik disiplininin zaman kaybı olduğunu düşünebilir; bunların hepsi yanlıştır ve küresel ölçekte projelerin yaklaşık yarısının başarısız olması bu yanılgıların bedelini gösterir. Yönetici ise geciken işe yeni programcı ekleyerek ya da işi fason yaptırarak sorunu çözebileceğini düşünebilir; oysa eleman ekleme ve alt yüklenici kullanımı baştan planlanmalı ve iyi denetlenmelidir.
- Yazılım sürecinin genel adımları çözümleme, tasarım, gerçekleme, sınama ve bakımdır; bu adımlar şelale modelinde olduğu gibi sırayla dizilebilir ya da başka modellere göre düzenlenebilir. Çözümleme sistemi anlamaya ve üst düzey planlamaya yöneliktir; nesneye yönelik yaklaşımda üst düzey parçalar sınıflar ve nesnelerdir. Tasarım çözümün modelini ve şemalarını üretir, gerçekleme bu tasarımı kodlar. Sınamanın önemi, hataların giderilme maliyetinin süreçte ilerledikçe üstel olarak artmasından ve hataların büyük kısmının aslında gereksinim ve tasarım aşamalarından kaynaklanmasından gelir. Bakım; hata düzeltme, değişen işlevlere uyum ve iyileştirme işlerini kapsar, gerektiğinde yeniden mühendislik ve yeniden düzenleme ile yazılımın işlevi değiştirilmeden iç yapısı iyileştirilir ya da yeni bir ortama taşınır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
