# Ders 6 Genişletilmiş Notu: Yazılımların Korunması, Meslek ve Mühendislik Etiği

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Yazılımların Korunması
- 2. Tersine Mühendislik
- 3. Açık Kaynak Kodlu Yazılımlar
- 4. Yazılım ve İnsan Hakları
- 5. Kaynak Kodu Emanetçiliği
- 6. Meslek ve Meslek Kuruluşları
- 7. Meslek Etiği
- 8. Mühendislik ve Gelişimi
- 9. Mühendislerin Görev ve Sorumlulukları
- 10. TMMOB İlkelerine Göre Mühendisin Sorumlulukları
- 11. Bilgisayar Mühendislerinin Proje Aşamalarındaki Sorumlulukları
- Örnek Sorular

Dersin ilk yarısında önceki haftanın konusu olan fikir ve sanat eserlerinden kalan kısım (yazılımların korunması) tamamlandı. Sonra haftanın asıl konusu olan meslek ve mühendislik etiğine geçildi. Ders planı slaytına göre bu hafta "Meslek ve Mühendislik Etiği", sonraki hafta "Kurumsal Etik" konusudur (ekrandan, 00:25:00).

## 1. Yazılımların Korunması

Önceki derste görüldüğü gibi Fikir ve Sanat Eserleri Kanunu yazılımları da eser kabul eder; yazılımın manevi hakları yasayla korunur. Bu bölümde yazılımın bir sınai ürün olarak nasıl korunabileceği tartışıldı.

### 1.1 Yazılıma neden patent verilmez?

Slayttaki ifadeyle: "Bir yazılıma patent verilmemektedir. Verilmiş olsaydı aynı işlevi gerçekleştirecek bir başka yazılımın üretilmesinin önü kapatılmış olurdu." (ekrandan, 00:05:00). Hoca bunu şöyle açıkladı: belli bir işlevi yerine getirmek için tasarımı ve yöntemi birbirinden çok farklı, biri ötekinden daha iyi ya da daha kötü olabilen pek çok yazılım geliştirilebilir. Bir tanesine patent verilirse aynı işlevi gören bütün diğer yazılımlar engellenmiş olur.

### 1.2 Bilgisayar temelli sistemler

Bilgisayar temelli bir sistem geliştirildiğinde ise patent alınabilir. Hocanın örneği çamaşır makinesidir. Makinenin içinde bir mikrodenetleyici, yani atanmış (gömülü) bir bilgisayar vardır ve süreci yönetir: su al, deterjan al, birkaç kez sola, birkaç kez sağa çevir, sensörlerden gelen verilere bakıp kirin çıkıp çıkmadığını değerlendir, çıkmadıysa tekrar yıka, sonra sık. Bu yönetim birimi bir fikirdir ve tekniğin bilinen durumunu iyileştiriyorsa patentle korunabilir. Patent yönetim biriminin tasarımı için alınabildiği gibi, sistemle birlikte çalışan yönetim yazılımı için de alınabilir. Yani yazılım tek başına değil, ama bütünlüklü bir sistem çözümünün parçası olarak patente dahil olabilir.

### 1.3 Kullanıcı arayüzleri

Mevcut patent yasalarında kullanıcı arayüzüne patent verilemeyeceği yazar. Buna karşın fare ve fare yerine geçen yüzeyler (dizüstü bilgisayarlardaki dokunmatik yüzey, ayrı satılan trackpad) için patent alınabilmektedir. Benzer biçimde iki parmakla büyütme ve küçültme yapabilen ekran ve yüzeylere de patent verilmektedir (ekrandan, 00:05:00). Hoca, üç parmakla kaydırınca bütün uygulama pencerelerinin küçülmesi gibi hareketleri (gesture) örnek verdi.

Günümüzde bazı ülkelerde, örneğin ABD'de, yazılımlar için de patent ya da faydalı model belgesi verilmeye başlanmıştır. Bu belgeler verilirken geliştirilen yazılımın ya da bilgisayarlı dizgenin yenilikçi ve özgün olmasına, patentin bütün şartlarını sağlamasına dikkat edilir.

## 2. Tersine Mühendislik

### 2.1 Tanım ve tarihçe

Tersine mühendislik (reverse engineering), önceleri başkasının geliştirdiği bir donanımı inceleyip aynısını ya da daha gelişmişini yapmak biçiminde ortaya çıkmış, daha sonra yazılımlara da uygulanmıştır (ekrandan, 00:10:00).

Atanmış bilgisayarların ilk dönemlerinde, yani mikrodenetleyicilerin üretilmesinden önce, donanım kolayca kopyalanabiliyordu. Daha önemlisi bellekteki programın kodu görünürdü. Bellekteki makine kodu tersine derlendiğinde (decompile) simgesel dilde (assembly) program elde edilebiliyordu. Bir adım daha tersine mühendislikle de asıl koda, tasarıma ve algoritmaya geri dönülebiliyordu; yani donanıma gömülü yazılım doğrudan çözülmüş oluyordu.

Bugün de mevcut bir yazılımın kodları incelenerek tasarım yapısı çıkarılabilir: tasarım aşamasında hangi mantığın izlendiği, akış diyagramları ve algoritmalar yeniden üretilebilir. Slayttaki ifadeyle, "bir anlamda asıl yazılımı hazırlamış olanların emekleri çalınmaktadır" (ekrandan, 00:10:00). Bu yüzden başkasının yazılımına uygulanan tersine mühendislik ne hukuk ne de etik açısından kabul edilebilir bir davranıştır.

### 2.2 Gerçek hayattaki örnekler

Bilişim dünyasının önemli oyuncuları zaman zaman rakip ürünü alıp tersine mühendislikle çözmüş, alternatifini geliştirip piyasaya sürmüştür. Hoca kelime işlemci ve hesap tablosu türevi yazılımları örnek verdi; bu tür olaylar uzun süre mahkemelerde dava konusu olur. Tersine mühendislik yapan firmalar hukuktan kaçmak için genellikle veri tabanını ya da tablo yapısını, programlama dilini ya da ortamını, kullanılan kütüphaneleri ya da arayüzleri değiştirir ve "aynısını yapmadım, aynı işlevi gören farklı bir yazılım ürettim" diye savunma yapar.

Konsol oyunlarının korsan sürümleri de tersine mühendislikle kodlama ya da kimlik doğrulama aşamalarının kırılmasıyla ortaya çıkar.

### 2.3 Kabul edilebilir tersine mühendislik

Günümüzde tersine mühendislik için geliştirilmiş araçlar vardır ve bunlarla eski büyük boy yazılımlar günün olanaklarına uygun hâle getirilebilir (ekrandan, 00:10:00). Hocanın örneği bankacılıktır: ilk dönemlerde ana bilgisayarlar (mainframe) üzerinde COBOL ile yazılmış, dosya sistemine yazan eski monolitik uygulamalar vardı. Bunları Linux kümesinde çalışan, nesne yönelimli bir dille yazılmış ve ilişkisel veri tabanı kullanan bir sisteme dönüştürmek gerekir. Kuruluş kendi yazılımını iyileştirmek ve güncellemek için tersine mühendislik yaparsa bu kabul edilebilir.

> **Hocanın vurgusu:** Asıl yazılımın bilgi birikimini olduğu gibi kullanmak bilgi hırsızlığıdır. Bir başkasının yazdığı programı tersine mühendislikle elde edip kendi ürününüzü üretmek ya da onu kullanmak etik değildir. Kendi eski ürününüzü güncel hâle getirmek için yapmak zorundaysanız yapabilirsiniz.

## 3. Açık Kaynak Kodlu Yazılımlar

Sahipliğin karşısında açık kaynak (open source) yaklaşımı durur. Bir yazılım gereksinim analizi, tasarım, gerçekleştirme ve test aşamalarından geçerek büyük bir emekle üretilir. Böyle bir eserin kaynak kodunu "al, sen de kullan" diye başkasına vermek ilk bakışta mantık dışı görünebilir. Ancak bazı geliştiriciler kaynak kodun paylaşılmasını daha yararlı bulur. Slayta göre bu düşüncede olanlar kaynak kodun açık olmasıyla şunlara inanırlar (ekrandan, 00:15:00):

- Bazı program parçaları farklı kişilerce daha iyi biçimde çözülebilir.
- Programcılar arasında bilgi alışverişi sağlanır ve artar.
- Firmalar bazı program bileşenlerini açık kaynak kodlu olarak sağlayabilir ya da bu tür bileşenleri yazmış olanlardan parası karşılığı satın alabilir.
- Açık kaynak kodlu bir bileşeni kullanan firma, daha sonra bakım konusunda program parçasını hazırlayandan parası karşılığı destek isteyebilir. Hocaya göre en çok yapılan şey budur: bileşeni kullanan firma güncelleme, uyarlama ya da bakım sırasında yardıma ihtiyaç duyar ve kodu yazan kişi buradan para kazanır.
- Bazı firmalar ürettikleri program için lisans almaya üşenip kaynak kodunu herkesle paylaşabilir.

Açık kaynak kodlu programlar giderek yaygınlaşmaktadır. Açık kaynak kodlu bir işletim sistemi için R. Stallman tarafından GNU ("GNU's Not Unix") projesi başlatılmıştır. Cep telefonlarında yaygın olarak kullanılan Android de açık kaynaklı bir işletim sistemidir ve bu yüzden birçok üretici tarafından kullanılır (ekrandan, 00:15:00).

Hoca burada bir ayrıntıya dikkat çekti: Samsung, Sony, LG ya da Huawei gibi üreticiler aynı çekirdeği ve işletim sistemini kullansa da üzerine kendi kullanıcı arayüzlerini ve tamamlayıcı sistem yazılımlarını paketler. Bu değişikliklerle ürün açık kaynaktan çıkıp kapalı dağıtıma dönüşür. Android yeni bir sürüm çıkardığında her üreticinin yazılımcıları kendi sürümünü güncellemek, uyarlamak ve ardından yamalar yayınlamak zorunda kalır.

## 4. Yazılım ve İnsan Hakları

Önceki derslerde söz edilen İnsan Hakları Evrensel Beyannamesi açısından yazılım konusunda iki çıkarım yapılabilir:

- Herkes bilişim dünyasına yazılım ve sistem tasarlayarak katkı yapabilir; herkesin üretme hakkı vardır. Üretilen her yazılım ve sistemin maddi ve manevi hakları korunmalıdır.
- Herkes yazılımlardan yararlanma hakkına sahiptir. "Yazılımımı sana satmıyorum, kullanamazsın" demek etik dışı ve insan haklarına aykırıdır. Ancak bunun karşılığında kabul edilebilir bir bedel ödenmelidir, çünkü kullanan kişi bir emek ürününden yararlanmakta, belki de kazanç sağlamaktadır.

> **Hocanın vurgusu:** "Benim evrensel hakkım, insan hakkım" diyerek herkesin yazılımına bedelsiz el koymak doğru değildir; karşılığı verilmelidir.

## 5. Kaynak Kodu Emanetçiliği

### 5.1 Sorun: kodu alıp ayrılan programcı

Yazılımları korumak için tersine mühendislik, patent ve açık kaynaktan sonra bir mekanizma daha vardır. Slayta göre bir yazılım firmasında çalışan programcının firmadan ayrılıp aynı işlevi yerine getirecek bir programı kendi kurduğu firma adına üretmesi sıkça rastlanan bir durumdur; programcı çalıştığı süre içinde yazılımın kaynak kodlarını ve tasarım belgelerini kopyalayabilmektedir (ekrandan, 00:20:00). Hoca bunun Türkiye'de çok yaşandığını ve hâlâ yaşandığını söyledi.

Hocanın anlattığı tipik senaryo şöyledir: programcı "kodu ben yazdım, eser benim" diye kodun kopyasını alır ve bir firma kurar. Eski firmasında yakın çalıştığı birkaç müşteriye "aylık 10 bin lira bakım ödüyorsunuz, ben size 5 ya da 3 bin liraya yaparım" der. Ürünün renklerini ve yazı tiplerini değiştirir, birkaç özellik ekleyip çıkarır ve ürün olarak satmaya başlar. Oysa önceki derslerde tartışıldığı gibi manevi haklar programcıda olsa da maddi haklar şirkettedir.

### 5.2 Haksız rekabet davası ve teknik bilirkişi

Ürünün aslının geliştirildiği firma haklı olarak haksız rekabet davası açar. Mahkeme kodu kendisi açıp incelemez; tamamen hukuki mevzuat çerçevesinde karar verir. Teknik ayrıntıları açığa kavuşturmak için teknik bilirkişiler atanır. Bilirkişinin ilk bakacağı şey kodun gerçekten kopya olup olmadığıdır. Bilirkişi "bu kişi suçludur" diyemez; davacının ve davalının kodlarını yazılım ölçütleri ve yazılım mühendisliği açısından tanımlar, hangi modüllerin aynı olduğunu, hangilerinin yüzde 80 ya da yüzde 90 benzediğini, nerede yalnız arayüzün farklılaştırıldığını raporlar. Kararı bu benzerlik raporuna dayanarak hâkim verir. Kaynak kodları büyük ölçüde aynıysa ikinci firma suçlu bulunur ve büyük olasılıkla tazminat öder.

### 5.3 Emanetçinin iki işlevi

Slayta göre yazılım geliştiren kuruluşlar kaynak kodu emanetçisinden iki nedenle yararlanır (ekrandan, 00:20:00):

- **Kaynak kodlarının çalınmasına karşı önlem:** Kod emanetçide kayıt altında olduğu için mahkemede "bu kod zaten bana aitti, emanetçiye teslim etmiştim" savunması güçlenir.
- **Yazılımların geleceğini güvence altına alma:** Hazır yazılım satın alan kuruluşlar bakımın garanti edilmesini bekler; bakım kapsamında hatalar ayıklanır, yamalar ve güncellemeler yapılır. Yazılımı geliştiren firma kapanır ya da satılır ve bu desteği veremezse müşteri büyük sorun yaşar. Bu yüzden bazı müşteriler yazılımı alırken kaynak kodunu da ister. Emanetçi yazılımın son hâlini saklar; firma kapandığında yazılımı satın almış kuruluşlar kodu, değiştirilmediği güvencesiyle emanetçiden alabilir.

Hoca emanetçiyi yediemine benzetti: mahkemenin el koyduğu bir araç nasıl yediemine teslim edilip orada saklanıyorsa, yazılımın kodu da emanetçiye verilir. <!-- BELİRSİZ: Hoca Türkiye'de İTÜ bünyesinde böyle bir hizmet olduğunu söyledi, ancak adını ("kod havuzu", "kod deposu", "güvenli kod...") hatırlayamadı. -->

> **Ek bilgi (derste anlatılmadı):** Yediemin, uyuşmazlık konusu bir malın mahkeme ya da icra dairesi kararıyla teslim edildiği ve saklanmasından sorumlu tutulan kişi ya da kuruluştur. Yazılımda bu işleve uluslararası literatürde "source code escrow" adı verilir.

## 6. Meslek ve Meslek Kuruluşları

Haftanın asıl konusu olan meslek ve mühendislik etiğinde önce meslek ve meslek etiği tanımlandı, sonra mühendisliğe ve en son bilgisayar mühendisliğine geçildi.

### 6.1 Meslek nedir?

Slayttaki tanım: "Meslek bir kişinin yaşamını sürdürebilmek için yaptığı ve genellikle yoğun bir eğitim ve çalışmayı gerektiren sürecin sonunda kişilerin kazandığı beceri ve unvanın adı olarak tanımlanmaktadır. Bu beceriyi kazanmış olan kişinin becerisini insanlığın yararına kullanması beklenmektedir. Her mesleğin kendisine özgü değer ve etik ilkeleri vardır ve meslek üyelerinin bu ilkelere uymaları beklenir." (ekrandan, 00:30:00)

Yani meslekte yoğun eğitim ve çalışma, bunun sonunda kazanılan beceriler ve bir unvan vardır. Hoca, bu tanıma uymayan örnekler olarak emlakçılığı ve müteahhitliği verdi: hiçbir eğitim ya da deneyim olmadan emlakçı açılabiliyor; biraz sermaye ve çevresi olan biri kat karşılığı arsa bulup projeyi mimara ve mühendise çizdirerek müteahhit olabiliyor, işini büyüttükçe daha büyük projelere girebiliyor. Oysa bu mesleklerin de bir meslek odasına, bir meslek etiğine ve denetime bağlı olması gerekir. Hoca, depremde Yalova'da yıkılan binaların müteahhitliği örneğinde, meslek etiği işlemediğinde ortaya çıkan sonuçlara dikkat çekti.

Slayta göre bir mesleğin öğrenilebilmesi için belli bir eğitimin görülmesi ve sonunda bir yetki belgesinin kazanılması gerekir. Yetki belgesini kazanmış meslek sahibi o mesleğe kabul edilir; mesleğini belli kurallara uygun olarak sürdürmekle yükümlüdür ve bu yükümlülükleri yerine getirmezse meslekten atılır (ekrandan, 00:30:00).

### 6.2 Ahilik ve ahi loncaları

Slayttaki bilgiye göre Ahilik, 12. yüzyılda insanlara sanat ve sanat ahlakı öğretmek amacıyla Ahi Evran (1171-1262) tarafından kurulmuştur. "Ahi" sözcük olarak kardeş demektir. Değişik meslekler için kurulan bu örgütlere ahi loncaları denir; loncalarda insanlar çırak, kalfa ve usta unvanlarını kazanırdı (ekrandan, 00:30:00). Loncalarda meslek sahiplerine hem kuramsal hem uygulamalı eğitim verilirdi.

Loncalar meslek sahiplerine maddi destek de sağlardı. Bunun için orta sandığı, esnaf kesesi, esnaf sandığı gibi yardımlaşma kurumları vardı. Hoca, memurların emeklilik kurumuna "Emekli Sandığı" denmesinin bu gelenekten kalma bir ad olduğunu belirtti.

Loncaya giriş ve yükselme şöyle işlerdi:

- Loncaya kabul edilen kişiye önce "feta", yani yiğit denirdi.
- Lonca kişiyi öncelikle meslek ahlakı açısından geliştirirdi; yeterli yetkinliğe ulaşan kişi çırak olurdu.
- Öğrenmeye ve ahlakını geliştirmeye devam eden kişi kalfa, en sonunda usta olurdu.
- Ustalığa yükselişte bir tören yapılır ve kişiye izin (destur) verilerek usta yapılırdı. <!-- BELİRSİZ: Törenin adı altyazıda "neşet töreni" diye geçiyor; Whisper bozması olabilir. -->

Ahilikte iki önemli görev vardı:

- **Kethüda:** Mesleğin inceliklerini ve kurallarını bilen, esnafın dürüst olmasını ve çalışma düzenini denetleyen kişidir.
- **Yiğitbaşı:** Bir tür bilirkişidir; esnafın ürettiği ürün ya da hizmetin hileli olup olmadığını denetler.

Slayta göre ahi loncalarının işlev ve görevleri şunlardır (ekrandan, 00:35:00):

- Meslek eğitimi vermek
- Meslek içi eğitim vererek mesleğin sürekliliğini sağlamak
- Maddi gereksinimi olan meslektaşlara yardım sağlamak
- Meslek ahlakını öğretmek ve denetlemek
- Kalitesiz veya pahalı ürün satılmasını önlemek
- Devlet ile meslek sahipleri arasındaki ilişkiyi sağlamak

Son madde için hoca, loncanın devletle esnaf arasında dengeleyici bir mekanizma olduğunu söyledi: bir yandan devletin esnafı vergiyle ezmemesini, vergilerin insaflı toplanmasını sağlar, öte yandan esnafın başıboş kalmasını engeller.

Loncaların kuralları katıydı: etik dışı davrandığı için loncadan atılan biri ülkenin hiçbir yerinde o mesleği bir daha yapamazdı. Loncalar Anadolu'da yaklaşık 700 yıl etkin olarak çalışmıştır; önce ahlak, sonra beceri öğretilirdi.

### 6.3 Günümüzde meslek odaları

Bugün ahi loncaları yoktur, ama benzer görevleri meslek odaları sürdürür. Pek çok ülkede ve Türkiye'de pek çok meslek odası vardır. Amaçları temsil ettikleri mesleğin saygınlığını sürdürmek için etik kurallar oluşturmak ve bu kurallara uymayan üyelere yaptırım uygulamaktır. Hekimlikte, bir hastayı bilerek denek gibi kullanan bir doktorun meslekten men edilmesi buna örnektir. Son yıllarda süreli meslekten men cezaları da görülmektedir; hoca, kamuoyunda tanınan bir hekimin halkı tıbbın bazı olanaklarından uzaklaştıran açıklamaları nedeniyle tabip odasınca süreli meslekten men cezası aldığını örnek verdi. <!-- BELİRSİZ: Hoca cezanın süresini önce "üç ay", sonra "iki ay" diye söyledi; davanın sonucunu bilmediğini de belirtti. -->

Meslek odaları sivil toplum örgütü olduğu için mesleğin toplumsal sorumluluğunu üstlenir. Mesleki etik kurallarının ana hedefleri şunlardır:

- Doğru ve yanlış eylemleri ve bunların sonuçlarını tanımlamak, olacaklar için yol gösterici olmak.
- Meslek üyelerini etik davranışa yönlendirmek.
- İş yerinin sahibi, yöneticileri ve çalışanları arasındaki ilişkileri düzenlemek.

Kısacası meslek odaları, ahi loncalarının modern dünyaya uyarlanmış biçimidir.

## 7. Meslek Etiği

### 7.1 Tanım

Meslek odalarının tanımlamaya çalıştığı kavrama bugün meslek etiği diyoruz. Meslek etiği akademik bir çalışma alanı olarak 1980'lerde ortaya çıkmış (biçimlendirilmiş), zamanla pek çok meslek örgütü üyelerinin uyması gereken etik kuralları yayınlamıştır.

Slayttaki tanım (ekrandan, 00:40:00):

- Mesleki davranışla ilgili neyin doğru, neyin yanlış, neyin haklı, neyin haksız olduğu hakkında ilkeler ve kurallardır.
- Mesleki uygulamaların yasalara uygun olmasını sağlamanın yanı sıra toplumun değer yargılarını önemseyerek topluma doğru ve güvenilir bilgilerin sunulmasıdır.

Meslek etiği, genel ahlak ve genel etik kurallarının bir meslek için özelleştirilmiş biçimidir. Meslek sahibi hem genel kurallara hem de mesleğe özgü kurallara uymak zorunda olduğu için meslek etiği genel etikten daha fazla sorumluluk yükler.

Bir mesleğin üyeleri etik ilkelere ne kadar sıkı uyarsa o mesleğin saygınlığı o kadar artar. Hocanın örneği yine müteahhitliktir: müteahhitler "burada şu demiri kullanmalıyız, bahçe payı ve otopark şöyle olmalı, olmazsa bu işi yapmayız" diye davransa meslek saygın olur; "boş ver, dök betonu, biraz daha kazanalım" yaklaşımı ise mesleğin saygınlığını azaltır, hatta bütün mesleğin karalanmasına yol açabilir.

### 7.2 Meslek etiğinin amaçları

Slayta göre meslek etiğinin temel amaçları şunlardır (ekrandan, 00:40:00):

- Meslek içi rekabeti düzenlemek
- Yetersiz ve ilkesiz üyeleri ayıklamak
- Hizmet hedeflerinin korunmasını sağlamak
- Meslek disiplinini sağlamak
- Mesleğe bağlılığı sağlamak

### 7.3 Meslek etiğinin temel ilkeleri

Bu amaçlara bağlı olarak meslek etiğinin temel ilkeleri doğruluk, yasallık, yeterlik, güvenilirlik ve mesleğe bağlılıktır (ekrandan, 00:40:00).

**Doğruluk.** Başkalarıyla ilişkilerde dürüstlüktür; önceki derslerde görüldüğü gibi dürüst olmak ve doğruyu söylemek erdemli kişinin davranışıdır. Bir çalışan hem yöneticilerine hem de altındaki çalışanlara karşı dürüst olmalıdır. Dürüst, adil, eşit ve tarafsız olmak bu ilkenin içindedir; dürüst olmayan kişi kendi geleceğini tehlikeye atar. Doğruluk yalnız kuruluş içinde değil, dışında da geçerlidir: üretilen ürünün ya da sağlanan hizmetin özellikleri müşteriye doğru aktarılmalı, müşteri kandırılmamalı, gerçek dışı bilgi verilmemelidir.

**Yasallık.** Üç yönü vardır:

- Üretilen ürünlerin yasa, yönetmelik ve ölçünlere uygun olması.
- Çalışmaların ulusal ve uluslararası çalışma yasalarına uygun olması.
- Müşteriler ve diğer dış paydaşlarla ilişkilerin yasalara uygun olması.

Yasaya aykırı bir ürün üretmenin cezası zaten kanunda bellidir. Bunun yanında Türk Gıda Kodeksi gibi özel yönetmelikler ya da ölçünler varsa üretim bunlara uygun yapılmalıdır; bu gıda ve ilaç sektörlerinde çok önemlidir. Bilgisayar mühendisliği açısından örnek: bir ekran ya da yazıcının yazılımını ve donanımını tasarlıyorsanız ekran insan sağlığını bozmamalı, örneğin eski CRT ekranlarda daha belirgin olan ışınım izin verilen sınırlar içinde kalmalıdır. Daha ucuza ya da daha hızlı üretmek için insan sağlığı tehlikeye atılmamalıdır. Yazılımda donanımdaki kadar kısıt yoktur, ama yine uyulması beklenen ölçütler ve ISO standartları vardır. Üretimde sorun çıktığında da yasalara uygun davranılmalıdır; "takmayın, üretin, ben söylüyorum" gibi yasaya aykırı bir emre meslek etiğinin temel ilkesi gereği "hayır" denebilmeli, gerekirse yetkili mercilere bildirilmelidir. Çalışanların çalışma koşulları da yasalara uygun düzenlenmelidir.

**Yeterlik.** Bir yönetici farklı yeteneklere ve yetenek düzeylerine sahip çalışanları, yeterli olacakları işlere dağıtmalıdır. İnsanlar kendilerini geliştirmek ister ve geliştirirlerse iş yerine de katkı yaparlar; bu yüzden "sen bu kadarsın, böyle kal" demek yerine yeterliklerini artırmalarına imkân tanınmalıdır.

**Güvenilirlik.** Ahilikten gelen bir değerdir; hayat boyu ve meslek içinde güvenilir olmak önemlidir. Mesleki etik kuralların hepsine uyan kişi toplum tarafından güvenilir kabul edilir. Uymayan kişi önce müşterilerinin, sonra meslektaşlarının güvenini kaybeder; sonunda mesleğin saygınlığını korumak için meslek örgütü onu meslekten atabilir.

**Mesleğe bağlılık.** Mesleğe mensup olan onu sevmeli ve ona değer vermelidir. Mesleğini seven kişi kendini sürekli geliştirir, başarılı olmak için çalışır, ekip arkadaşlarının gelişimine ve mesleğin saygınlığına katkı yapar.

> **Hocanın vurgusu:** Meslek etiği nedir, neyi amaçlar, temel ilkeleri nelerdir? Bu üç soru bölümün özetidir.

## 8. Mühendislik ve Gelişimi

### 8.1 Tanım

Mühendislik bir iş ve meslek tanımı olarak sanayi devriminden sonra ortaya çıkmış, son iki yüzyılda pek çok mühendislik dalı doğmuştur. Slayttaki tanım: "Bilimsel ve matematiksel ilkeleri, deneyim ve yaratıcılığı kullanarak doğal kaynaklardan insana faydalı ürünler ortaya koyma eylemine mühendislik denir." (ekrandan, 00:50:00). Mühendisler bugün yararlandığımız ve kullandığımız teknolojileri geliştiren ve üreten kişilerdir.

### 8.2 Yirminci yüzyılın yirmi mühendislik başarısı

Slayta göre 20. yüzyılda yaşamımıza katkı sağlamış en başarılı yirmi mühendislik konusu şunlardır (ekrandan, 00:50:00):

- Elektrik, otomobil, uçak, su sağlama ve dağıtımı, elektronik, radyo ve televizyon, tarım araçları
- Bilgisayar, telefon, buzdolabı ve iklimlendirme aygıtı, otoyollar, uzay araçları, genelağ
- Tıpta görüntü işleme, ev aletleri, sağlık teknolojileri, petrokimya teknolojileri
- Lazer ve fiber optik, nükleer teknolojiler, yüksek başarımlı malzemeler

### 8.3 Somut ve soyut katkılar

Hoca mühendisliğin yaşam kalitesine katkısını ulaşım örneğiyle anlattı: 1900'lerin başında 1.000 km'lik bir yol at arabası ya da ilk otomobillerle yaklaşık 20 günde gidilebiliyordu. Yüzyılın sonunda otoyollarla bu süre yaklaşık 10 saate, uçakla yaklaşık 1 saate indi.

İletişimde de benzer bir sıçrama vardır. Telefon 1876'da Graham Bell'e atfedilen icatla ortaya çıktı ve bir yüzyıl içinde bütün dünyanın temel iletişim aracı oldu. İlk GSM 1991'de çıktı; hocanın hatırladığı kadarıyla Türkiye'ye 1994 sonu ya da 1995 başında geldi. Bugün Türkiye'de abone sayısı nüfustan fazladır, çünkü birçok kişinin birden çok hattı vardır.

Mühendisliğin soyut katkıları da vardır. İnsanın 1960'larda Ay'a gitmesinin somut katkısı uzay teknolojileridir, ama hocaya göre topluma verdiği moral, yani soyut katkısı daha büyüktür.

### 8.4 Zararlı gelişmeler

Her mühendislik gelişmesi iyi değildir. En bilinen örnek atom bombasıdır: onu da mühendisler geliştirdi ve hoca, bunu yaparken "haklıyız" düşüncesini etik açıdan nasıl değerlendirdiklerini sordu. Bir başka örnek mayındır; insanın habersizce öldüğü, en kötü silahlardan biridir. Mayını tasarlayan mühendis ya da üretim hattındaki teknisyen, bu mayının kaç kişiyi öldüreceğini ya da sakat bırakacağını düşünmek zorundadır.

Mezuniyette mühendislik yemini edilir. Bu yemin, öğrenilenlerin insanlığın yararına kullanılacağına dair bir sözdür; mühendis bu yemine uygun olarak, etik değerlere uygun çalışmalıdır.

### 8.5 Sözcüğün kökeni

"Mühendis" sözcüğü Arapçadan, hendese kelimesinden gelir. Hendese hesap demektir, ama tam karşılığı yoktur: hesap ve matematikle iş yapan, ölçen ve biçen kişi anlamını taşır.

"Engineer" ise Latince bir kökten gelir; hocanın aktardığına göre bu kök icat eden, yaratıcı, mucit anlamındadır. Hoca, sanayi devrimini başlatan buhar makinesiyle "engine" sözcüğünün bu kökten türetildiğini ve bu işi yapanlara da "engineer" dendiğini söyledi. Böylece Doğu kültürü mühendisliği hesap ve ölçme (hendese), Batı kültürü ise icat etme tarafından tanımlamıştır.

> **Ders sonrası not:** Hoca "engine" sözcüğünün buhar makinesinden sonra türetildiğini söyledi. Sözcük büyük olasılıkla çok daha eskidir: Latince "ingenium" (yetenek, buluş) kökünden Eski Fransızca üzerinden İngilizceye Orta Çağ'da girmiş, başlangıçta savaş makineleri gibi düzenekler için kullanılmıştır. Buhar makinesi sözcüğü doğurmamış, onun anlamını genişletmiştir.

### 8.6 Mühendisliğin dönemleri ve kümeleri

Hocanın anlattığı dönemler:

- **Bilim devrimi öncesi:** Leonardo da Vinci bir milat olarak alınır; ondan öncesi bilim devrimi öncesidir.
- **Bilim devrimi ile sanayi devrimi arası (16.-19. yüzyıl):** Başlarda yetenek önemlidir, sonra bilimi kullanmak yetenekten daha önemli hâle gelir.
- **Sanayi devrimi sonrası ve ikinci sanayi devrimi (İkinci Dünya Savaşı'na kadar):** Kimya ve elektrik mühendisliği çok gelişir.
- **İkinci Dünya Savaşı sonrası:** Bilişim dönemi; hâlâ bu dönemin içindeyiz, buna uzay çağı da denir.

Günümüzde mühendislik altı temel kümede toplanır: inşaat, kimya, makine, elektrik, bilgisayar ve uçak-uzay. Her küme kendi içinde dallara ayrılır: elektrik kümesinde elektrik, elektronik, haberleşme, kontrol; bilgisayar kümesinde bilgisayar, yazılım, bilişim sistemleri, bilgi teknolojileri ve bilgi güvenliği mühendislikleri gibi. Böylece mühendislik dallarının sayısı 15-20'ye çıkar. Hoca, bazı üniversitelerde bilgisayarın ayrı bir fakülte ya da enstitü olarak örgütlendiğini, bazılarında ise elektrik fakültesi altında yer aldığını belirtti.

## 9. Mühendislerin Görev ve Sorumlulukları

Mühendisler genel olarak insan hayatına olumlu katkı yapar, ama etik kurallara ve edilen yemine uyulmazsa sonuçlar kötü olabilir. Mühendisin görev ve sorumlulukları dört başlıkta incelenir (ekrandan, 01:00:00):

**Zorunluluk.** Mühendisin yapmakla yükümlü olduğu davranışlardır. Doğru, dürüst ve adil olmak mühendisler için zorunlu davranışlardır. Diğer yükümlülükler mühendislik rolünün gereğidir: yazılım mühendisinin zorunlu görevi yazılım geliştirmek, güvenlik mühendisinin zorunluluğu geliştirdiği sistemin güvenli olmasını sağlamak, bilgisayar mühendisinin zorunluluğu tasarımı düzgün yapmaktır.

**Sorumluluk.** Gerçekleştirilen bir işlem ya da eylem nedeniyle sorumluluk taşımak demektir; hesap verebilirlik olarak da adlandırılır. İşlemi ya da eylemi üstlere ve çevreye açıklayabilmek ve sorumluluğunu yüklenmektir. Bir hata olduğunda mühendis, rolü gereği hatadaki payını açıkça ve cesaretle ortaya koymalıdır. Sorumluluk sahibi kişi, "bunun hesabını vermek zorundayım" düşüncesiyle karar verir. Hoca, işini yetiştiremediği ya da hatası yüzünden biri zarar gördüğü için ağır sonuçlara katlanmayı göze alan Japon mühendisleri sorumluluk bilincinin uç örneği olarak andı.

**Özen.** Mühendisler yaptıkları işlem ve eylemin kusursuz olması yönünde özen gösterir. Her mühendislik projesinin bir yanılma payı vardır ve proje gereksinimleri belirlenirken bunlar ölçüt olarak belirlenir (örneğin "artı eksi şu kadar sapma olabilir"). Ürün geliştirme ve üretim sırasında bu ölçünlere uyulmasına özen gösterilir. Ölçünlerin belirlediği sınırların aşıldığı görülmüştür; ancak bu aşımların özensizlikten kaynaklanmaması beklenir (ekrandan, 01:00:00).

**Kınama ya da ödüllendirme.** Gerçekleşen her işlem kınanabilir ya da övülebilir; dolayısıyla sorumlu kişi iki sonuca da katlanmalıdır (ekrandan, 01:00:00).

Hoca bu başlıkları şöyle bağladı: önce insan; her zaman genel etiği ve meslek etiğini düşünün, insanı öne koyun ve doğaya saygılı olun. Mühendislik çalışmaları tek başına yapılmaz, ekip çalışmasıdır; bu yüzden ekibe karşı da sorumluluklar vardır.

## 10. TMMOB İlkelerine Göre Mühendisin Sorumlulukları

Türkiye'de TMMOB'nin (Türk Mühendis ve Mimar Odaları Birliği) mühendislik meslek etiği ilkeleri sorumlulukları beş halkada toplar. Hoca bu slaytların TMMOB'den alındığını belirtti ve halkayı "önce biz, sonra toplum, sonra çevre" diye büyüttü.

### 10.1 Kendine karşı sorumluluklar

- Bilim ve teknolojiyi insanlık yararına ve doğal dengeyi koruyacak biçimde kullanmayı temel ilke kabul etmek.
- Bilgi ve yetenekleri sürekli geliştirme düşüncesi ve çabasıyla hareket etmek.
- Meslek alanı içinde en iyi tasarım ve uygulama hizmetini vermek.
- Hizmet üretimi ve yaşam boyunca ulusal ve uluslararası boyutta adalet, eşitlik, özgürlük, dürüstlük, güvenilirlik, saygı ve hukuk alanındaki gelişmelerden sorumlu olduğu bilinciyle hareket etmek.
- İş sözleşmelerindeki kurallara uymak ve karşı taraftan da aynı anlayışı beklemek.
- Yalnız yeterli olduğu (uzman olduğu) alanda mesleki hizmet üretmek; çok disiplinli çalışmada kendi payını düzgün yapıp diğer disiplinlere saygı göstermek.
- Sahip olmadığı bir unvanı kullanmamak, olmadığı biri gibi çalışmamak.
- Mesleki davranış ilkelerine uymak, uymayanlara hoşgörülü bakmamak ve örgütsel tepkinin gelişmesine katkı yapmak.

### 10.2 Topluma karşı sorumluluklar

Slayta göre (ekrandan, 01:10:00):

- İnsan haklarına, barışa, demokrasiye ve topluma saygıyı ön planda tutarak ilişki geliştirirler.
- Din, dil, ırk, her türlü inanç, cinsiyet farklılığı, coğrafi ayrım gözetmeden çok kültürlü bir yapının korunması ve kültürel zenginliğin geliştirilmesi yönünde çaba sarf ederek hizmetleri bu anlayışla yürütürler.
- Toplumun sağlıklı gelişmesini çevreyi ön planda tutarak geliştirecek davranışları desteklerler; doğal ve toplumsal çevrenin sağlıklı gelişmesini ön planda tutarlar.
- Mesleki bilgi, beceri ve deneyimlerini toplumun ortak çıkarları, evrensel insani kazanımlar, kültürel mirasın korunması ve insan refahının gelişimi için kullanırlar. Toplumun sağlığı, güvenliği ve refahı için duydukları sorumluluk her zaman kendi kişisel çıkarlarının ve meslektaşlarının çıkarlarının üstünde yer alır.
- Kendilerinden istenen işin toplum ve çevre için ciddi bir tehlike yaratacağı sonucuna varırlarsa ve mesleki yargıları işveren ya da müşteri tarafından dikkate alınmıyorsa görüşlerini işverene ya da müşteriye yazılı olarak bildirirler; sonuç alamazlarsa meslek örgütlerini ve gerektiğinde yetkili makamları ve kamuoyunu bilgilendirirler.
- Toplumun ilgi alanındaki teknik konularda görüş ve raporlarını, konuyu araştırmış ve yeterli bilgiyle donanmış olarak, ticari ve kişisel kaygıları bir yana bırakıp doğru, tam ve nesnel biçimde açıklarlar.
- İş yerlerinde işçi sağlığını korumak ve iş güvenliğini sağlamak için gerekli önlemleri alır, çalışanları bilgilendirirler.
- İşverenlere, müşterilere, meslektaşlara ve herkese adil, dürüst ve iyi niyetle davranırlar.
- Ülkenin teknoloji ve mühendislik yeteneğinin yükselmesi için teknolojinin, uygun kullanımının ve olası sonuçlarının toplum tarafından anlaşılması için çaba gösterirler.

Hoca bu uzun listeyi "atom bombası yapmayacağız, saldırı amaçlı mayın üretmeyeceğiz" diye özetledi. Kimya mühendisi için kaçak içki ya da zararlı ilaç üretmemek de bu kapsamdadır.

Tehlike bildirme sırası hocanın özellikle üzerinde durduğu bir noktadır:

```text
1. Önce işverene ya da müşteriye sözlü olarak söylenir.
2. Dikkate alınmazsa yazılı olarak bildirilir.
3. Yine sonuç alınamazsa meslek örgütüne başvurulur.
4. Gerekirse yetkili makamlar ve kamuoyu bilgilendirilir.
```

### 10.3 Doğaya ve çevreye karşı sorumluluklar

Mühendis doğayı korur, ona zarar vermez, uygulamalarının doğayla uyumlu olmasını sağlar, doğal kaynakların ve enerjinin verimli ve tutumlu kullanılmasına özen gösterir. Hoca bu açıdan Bitcoin madenciliğinin çok fazla elektrik tüketerek doğal kaynakları zorladığını örnek verdi.

### 10.4 İşveren ve müşterilere karşı sorumluluklar

- Teknik konulardaki mesleki ilişkilerde her zaman güvenilir bir vekil ya da danışman olmak.
- İşveren ya da müşterinin çıkarı için toplumun refahını, sağlığını ve güvenliğini tehlikeye atmamak; mesleki beceri ve deneyimi sonuna kadar kullanarak uygun bir iş düzeyinde çalışmak. Yani işverenin her dediği yapılmaz; toplum ve kamu daha önceliklidir.
- İlişkileri etkileyecek armağan, para, hizmet ya da iş teklifini kabul etmemek ve başkalarına teklif etmemek; mesleki ilişkileri geliştirmek amacıyla siyasal amaçlı bağış yapmamak.
- İşverenin ve müşterinin ticari ve teknolojik sırlarını izin almadan başkalarına açıklamamak ve kişisel çıkar için kullanmamak.

Hoca, genel toplumun yanında bunun özel bir "iş toplumu" olduğunu söyledi.

### 10.5 Mesleğe ve meslektaşlara karşı sorumluluklar

Slayta göre (ekrandan, 01:15:00):

- Mesleki etkinliklerini tüm meslektaşlarının güvenini kazanacak biçimde ve mesleğin saygınlığına en üst düzeyde özen göstererek sürdürürler.
- Tüm meslektaşlarına saygıyla yaklaşırlar, haksız rekabet içinde olmazlar, astlarının gelişimi için özel çaba harcar ve onlara yardımcı olurlar; telif haklarına ve özgün çalışmalara saygı gösterir, çalışmalara katkıları ve katkıda bulunanları belirtirler.
- Yalnızca yeterli oldukları alanlarda mesleki hizmet verirler, hizmetlerini etkileyebilecek diğer uzmanlık alanlarındaki yetkililerin görüşlerine başvurur, disiplinler arası ortak çalışmayı özendirirler.
- Mesleki görev, yetki ve sorumluluklarını sadece zorunlu durumlarda ve uzman olan meslektaşlarına devrederler.
- İşlerini yalnızca kendilerine tanınmış mesleki görev, yetki ve sorumluluk çerçevesinde yaparlar; yalnızca resmî olarak hak kazanmış oldukları sıfat ve unvanları kullanırlar.
- Bu ilkelere aykırı davrananlara yardımcı olmaz, onların etkinliklerinde yer almaz, onları uyarırlar; bu konuda meslek örgütleriyle iş birliği yapar, ilkelere uygun davrananları bütün güçleriyle desteklerler.
- Meslek örgütlerinin etkinliklerine etkin olarak katılmaya çaba gösterir, onları destekler ve mesleğin gelişmesine katkıda bulunurlar.

Katkıları belirtme maddesi için hoca, "başkalarının adını yazmayın, yalnız benim adım geçsin" denmemesi, katkı yapan herkesin hakkının verilmesi gerektiğini söyledi. Unvan maddesi için de birkaç web sitesi yapıp diploması olmadan "bilgisayar mühendisi" kartı bastıranları ya da kendine "bilgisayar doktoru" diyenleri etik dışı örnek olarak gösterdi.

Hoca bu beş halkanın (kendimiz, toplum, doğa ve çevre, işveren ve müşteri, meslek ve meslektaşlar) dünyadaki bütün meslek kuruluşlarının farklı cümlelerle de olsa üzerinde uzlaştığı temel sorumluluklar olduğunu belirtti.

## 11. Bilgisayar Mühendislerinin Proje Aşamalarındaki Sorumlulukları

### 11.1 Proje türleri ve aşamalar

Bilgisayar mühendisi çok farklı ölçekte projelerde çalışabilir: bankacılık yazılımı ya da öğrenci bilgi sistemi gibi büyük boy bilgisayar kullanan geniş çaplı projeler; hazır yazılım ya da mobil uygulama gibi küçük projeler; çamaşır makinesi, asansör kontrolörü ya da araç motorunu yöneten bilgisayar gibi atanmış bilgisayar (mikrodenetleyici) projeleri; Python ile veri bilimi gibi bilimsel ve hesaplama çalışmaları.

Hangi proje olursa olsun, slayta göre en genel değerlendirmeyle bir projenin geliştirilmesi dört evrelidir (ekrandan, 01:20:00):

- Planlama ve seçim (ön inceleme ve fizibilite)
- Çözümleme (analiz)
- Tasarım (arada gerçekleştirme de vardır)
- Kurulum ve işletme (devreye alma ve hayatta tutma)

Bir bilişim projesi için bu aşamaların ayrıntısı sekiz adımdır (ekrandan, 01:20:00):

- Kavramsal çalışmalar
- Gereksinimlerin belirlenmesi
- Çözümleme
- Tasarım
- Gerçekleştirme
- Sınama
- Kurulum ve işletmeye alma
- Bakım

Bilgisayar mühendisi her aşamada görev alabilir ve görev-sorumlulukları gereği görüşünü belirtmelidir; bu görüşlerin kararları ve sonuçta ortaya çıkan ürünü etkilemesi beklenir. Süreç doğrusal değildir: tasarım içinde, geliştirme ve üretim içinde, hatta kurulum ve bakımdan geliştirmeye ya da tasarıma geri dönüşler olabilir. Bakımdan analize kadar geri dönülüyorsa analiz baştan yanlış yapılmış demektir.

### 11.2 Kavramsal çalışmalar

Slayta göre kavram geliştirme aşaması, gerçekleştirilmesi istenen projenin gerekçe, amaç ve hedeflerinin belirlendiği, yani projenin tanımlandığı aşamadır (ekrandan, 01:25:00). Hoca bunu proje başlatma belgesinin (project charter) çıkarılması olarak da andı.

Projenin amaç ve kapsamı, proje ile ilişkili yasalara, yönetmeliklere, ölçünlere ve etik değerlere uygun olmalıdır. Bunlardan birini sağlamayan proje başlatılmamalıdır. Benzer şekilde toplumun ahlak değerlerine ve genel etik değerlere ters düşen projeler de hazırlanmamalıdır.

Bu karar kolay değildir. Slayttaki ve derste anlatılan örnekler (ekrandan, 01:25:00):

- **Silah projesi:** Mikrodenetleyici kontrollü bir silah vatan savunması için üretiliyorsa kabul edilebilir, ama başkalarının ülkesini işgal için üretilecekse kabul edilemez. Silah para kazanmak amacıyla ve her isteyene satılacaksa iki kez düşünmek gerekir.
- **Uyuşturucu ya da kumar sitesi:** Uyuşturucu satmak üzere bir web sitesi kurulması ya da kumar ortamı oluşturulması bazı ülkelerde olağan karşılanırken bazılarında yasaktır; Türkiye'de yasaktır. Böyle bir iş, daha amacı söylenirken reddedilebilmelidir.
- **E-posta içeriğine göre reklam:** Genelağ hizmeti sağlayan bir işletmenin, üzerinden geçen e-postaların içeriğine bakarak (anahtar kelimelere göre) reklam yönlendirmesini sağlayacak bir proje, kişisel bilgilerin gizliliği ilkesine ters düştüğü için başlatılmamalıdır. Hoca bunun KVKK'ya, haberleşme özgürlüğüne ve İnsan Hakları Evrensel Beyannamesi'ne aykırı olduğunu söyledi.

Kavram geliştirme aşamasında bir projenin genel ve yerel yasalara uygun olup olmadığı, etik değerlerle çelişip çelişmediği ve ahlak yargılarına ters düşüp düşmediği ayrıntılı biçimde ele alınmalıdır. Proje tamamlandıktan sonra oluşacak sorumlulukta en büyük pay kavramı geliştirenlerin olacaktır (ekrandan, 01:25:00). Bu aşamaya katılan mühendis, amaç ve kapsamın yasa, yönetmelik, ölçün, etik değerler ya da ahlakla uyuşmadığını görürse önce çevresindekileri uyarmalı, uyarılar dikkate alınmazsa görevinden ayrılmalıdır. Hoca gerekirse meslek odasının ya da kamu yönetiminin bilgilendirilmesi gerektiğini de ekledi.

> **Hocanın vurgusu:** Sorumluluk başlığında görüldüğü gibi proje sonunda övgü de kınama da gelir; kavramı geliştiren, fikir sahibi olarak sorumluluğun altına girer. Bu yüzden proje en başta etik, ahlaki ve yasal açıdan değerlendirilmelidir.

### 11.3 Gereksinimlerin belirlenmesi

Amaç ve kapsam belirlendikten sonra proje tamamlandığında nelerin yapılacağı ve hangi performansla yapılacağı belirlenir: istekler, işlevsel gereksinimler ve işlevsel olmayan gereksinimler. Ulaşılamayacak performans ölçütleri konmamalıdır. Bu aşamada donanım da belirlenir; donanım bileşenlerinin teknik özellikleri düzgün tanımlanmalı, uyulması gereken ölçüt ve standartlar belirtilmelidir. Bütün bunlar genellikle bir yazılım gereksinim belirtimi (SRS, Software Requirements Specification) raporunda toplanır. Raporun yapılamayacak işler ve varılamayacak performans hedefleri içermemesi, mesleki etik ve görev-sorumluluk açısından dikkat edilmesi gereken noktadır.

### 11.4 Çözümleme

Slayta göre amaç ve kapsamı belirlenmiş, gereksinimleri çıkarılmış bir bilişim projesi için çözüm aşamasına geçilebilir. Her projenin birden çok çözümü olabilir; bazı çözümler pahalı, bazılarının başarımı yüksek, bazılarının güvenliği iyi olabilir. Projenin tamamı ya da belli kısımları için farklı çözüm olasılıkları, aynı amaca yönelik farklı çözümler bulunabilir. Önemli olan bu çözümlerden en uygun olanı belirlemektir; en uygun çözüm, proje gereksinimlerini eksiksiz karşılayan çözümler içinden seçilmelidir. En uygun çözüm araştırılırken projeyi isteyen birimler ile mühendisler arasında tartışmalar çıkabilir (ekrandan, 01:30:00). Hoca bunun gerçekten çok sık yaşandığını söyledi.

#### İnternet bankacılığı vakası

Hoca, internet bankacılığının ilk yıllarından gerçek bir olay anlattı:

- Banka internet bankacılığına geçerken önce müşteri numarası (ya da kimlik/hesap numarası) ve bir parolayla girişi düşünür. İş birimi müşteriye kolaylık olsun diye bunu ister, ama mühendisler bunun yeterince güvenli olmadığını kolayca kabul ettirir.
- Böylece "üç seviyeli güvenlik" kurulur: müşteri numarası, parola ve cep telefonuna gelen tek kullanımlık parola (OTP). Kimlik doğrulama projesi bu şekilde başlatılır.
- Sonra şubelerden gelen şikâyetler üzerine iş birimi (genel müdürlükteki internet bankacılığı tarafı) bir istekte bulunur: müşteriler sık sık hat, SIM kart ya da operatör değiştiriyor, bu yüzden telefon numaralarını internet şubesinden kendileri değiştirebilmeli.
- Bilgisayar mühendisleri buna karşı çıkar: bu, şifreli bir mektup gönderip anahtarı da aynı zarfın içine koymak gibidir. İkinci seviye güvenlik önlemi olan SMS'in gittiği telefon numarası, aynı ortamdan değiştirilebilirse şifre ile kilit aynı yoldan gönderilmiş olur.
- İş birimi "parayı ben kazandırıyorum, müşteriyle ben muhatabım, benim istediğim olacak" diye ısrar eder ve uyarılara rağmen özellik bu şekilde geliştirilir.
- Sonra bir müşterinin müşteri numarası ve parolası oltalama (phishing) ve tuş kaydedici (keylogger) ile çalınır. Saldırgan internet şubesine girip müşterinin kayıtlı telefon numarasını kendi numarasıyla değiştirir. Havale için gereken SMS onayı artık saldırgana geldiği için onu da onaylar ve müşterinin bütün parasını başka bir hesaba aktarır; para kısa sürede yurt dışına çıkarılır. Gerçek müşteri internet şubesine giremez hâle gelir ve olaydan haberi olmaz. <!-- BELİRSİZ: Altyazıda saldırganın kopya SIM kart da edindiğinden söz ediliyor; anlatımın bu kısmı karışık. -->
- Uzun süren dava sonunda banka haksız bulunur ve zarara uğrar.

Mühendislerin önerdiği doğru tasarım, telefon numarasının yalnız şubeden ya da telefon bankacılığından değiştirilebilmesi, internetten değiştirilememesiydi.

Slayttaki ilkeler (ekrandan, 01:30:00):

- Herkes kendi uzmanlık alanında söz söyleme hakkına sahiptir. Uzmanlık alanının dışında, yetkisi olsa bile söz söylememelidir.
- Konusunda uzman olan kişi çıkabilecek sorunu kesin biçimde ortaya koymalıdır. Bu konuda uzman olmayan ancak yaptırım gücü olanlara konuyu anlatmalı ve daha sonra çıkacak sorunların hesabını kendilerinin vereceğini belirtmelidir. Bunu yazılı biçimde sunmalıdır.

Bu vakada iş birimi yetkin olmadığı bir konuda yetkinmiş gibi davranıp yetkisini kullanmış; mühendisler güvenlik konusunda uyarmasına rağmen yanlış bir tasarımın ortaya çıkmasına yol açmıştır.

#### Çözüm seviyeleri: güvenlik, maliyet ve kullanışlılık

Çözüm önerilerinin seviyeleri de değerlendirilmelidir. Hocanın örneği bir şirketin çalışan giriş sistemidir:

- Yalnız manyetik şeritli kart verilebilir.
- Üzerinde fotoğraf bulunan bir kart verilip bir görevlinin kartla kişiyi karşılaştırması sağlanabilir (iki seviyeli kontrol); bu bir maliyettir.
- İçinde çok küçük bir bilgisayar bulunan ve kimlik bilgilerinin kodlandığı akıllı kart kullanılabilir; özel bir cihazla okunur, fotoğraf kontrolü eklenebilir.
- Karta parmak izi, retina gibi biyometrik veriler de gömülebilir.

Yani "kart" denince bile onlarca seçenek vardır ve ucuz bir çözüm ile yüksek güvenlik arasında seçim yapılmalıdır. Hoca bunu bir grafikle anlattı: x ekseni güvenlik; bir eğri kullanışlılık (güvenlik arttıkça azalır), diğer eğri maliyet (güvenlik arttıkça artar). İki eğrinin kesişim noktasında mı durulacağı, yoksa güvenliğin ya da maliyetin öne alındığı bölgelerden birinin mi seçileceği projenin isterlerine göre tasarım aşamasında belirlenir. Tek bir kesin doğru çözüm yoktur; birden çok doğru çözüm olabilir, ama çözümleme aşamasında bunlar mühendisler tarafından iyice değerlendirilip ortaya konmalıdır. <!-- BELİRSİZ: Grafik 01:38-01:39 arasında ekrana çizildi, kareler bu anı içermiyor; eğrilerin biçimi anlatımdan aktarıldı. -->

### 11.5 Tasarım

Tasarım aşamasında çözümlemede seçilen çözüme ilişkin ön tasarım ve ayrıntılı tasarım yapılır. Mühendis kendi kafasına göre tasarım yapmamalıdır. Zorlayıcı durumlar çıkabilir ya da daha uygun bir çözüm bulunabilir; o zaman ekiple görüşmek önemlidir ve belki çözümleme ya da ön tasarımda değişiklik yapılır. Yapılan işlemler belgelendirilmeli; bu belgeler genel kabul görmüş standart belgeler ve standart diyagramlarla sunulmalıdır. Bu da mühendisin görev ve sorumluluklarındandır.

Gerçekleştirme ve sonraki aşamalar (sınama, kurulum, bakım ve hata kaynakları) sonraki derse bırakıldı.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:49:30): Meslek etiği nedir, neyi amaçlar ve temel ilkeleri nelerdir?

> **Cevap (derste verildi):** Meslek etiği, mesleki davranışla ilgili neyin doğru, yanlış, haklı ya da haksız olduğu hakkındaki ilke ve kurallardır; yasalara uygunluğun yanında toplumun değer yargılarını önemseyerek topluma doğru ve güvenilir bilgi sunmayı kapsar. Amaçları: meslek içi rekabeti düzenlemek, yetersiz ve ilkesiz üyeleri ayıklamak, hizmet hedeflerini korumak, meslek disiplinini ve mesleğe bağlılığı sağlamak. İlkeleri: doğruluk, yasallık, yeterlik, güvenilirlik ve mesleğe bağlılık (ekrandan, 00:40:00).

**Soru 2** (derste sözlü, 00:12:34): Tersine mühendislik hangi durumda etik değildir, hangi durumda kabul edilebilir?

> **Cevap (derste verildi):** Başkasının yazdığı programı tersine mühendislikle elde edip kullanmak ya da kendi ürününü üretmek etik değildir ve bilgi hırsızlığıdır. Kuruluşun kendi eski yazılımını günün koşullarına uydurmak (örneğin COBOL ile yazılmış monolitik bir uygulamayı modern bir mimariye taşımak) için yapılan tersine mühendislik kabul edilebilir.

**Soru 3** (derste sözlü, 00:23:18): Yazılım firmaları kaynak kodu emanetçisinden hangi iki amaçla yararlanır?

> **Cevap (derste verildi):** Kaynak kodlarının çalınmasına karşı önlem (mahkemede sahipliği kanıtlama) ve yazılımın geleceğini güvence altına alma (firma kapanırsa müşterinin kodun son hâlini emanetçiden alabilmesi) (ekrandan, 00:20:00).

**Soru 4** (derste sözlü, 01:23:59): Bir genelağ hizmet sağlayıcısının yöneticileri, kullanıcıların e-postalarını okuyup anahtar kelimelere göre reklam gösterecek bir proje istiyor. Kavramsal çalışma aşamasındaki bir bilgisayar mühendisi ne yapmalıdır?

> **Cevap (derste verildi):** Proje kişisel bilgilerin gizliliğine, KVKK'ya, haberleşme özgürlüğüne ve İnsan Hakları Evrensel Beyannamesi'ne aykırıdır; başlatılmamalıdır. Mühendis önce çevresindekileri uyarmalı, uyarılar dikkate alınmazsa görevinden ayrılmalı, gerekirse meslek odasını ya da yetkili makamları bilgilendirmelidir (ekrandan, 01:25:00).

**Soru 5** (derste sözlü, 01:30:40): İnternet bankacılığında girişte SMS ile tek kullanımlık parola kullanılıyor. İş birimi, müşterilerin telefon numaralarını internet şubesinden kendilerinin değiştirebilmesini istiyor. Bu tasarımın sorunu nedir ve mühendis ne yapmalıdır?

> **Cevap (derste verildi):** Telefon numarası ikinci seviye güvenlik önleminin (SMS) gittiği yerdir; onu aynı ortamdan değiştirilebilir yapmak, şifreli mektubun anahtarını aynı zarfa koymak gibidir. Parolası çalınan bir müşterinin numarası saldırganca değiştirilir ve onay SMS'leri saldırgana gider. Numara yalnız şubeden ya da telefon bankacılığından değiştirilebilmelidir. Mühendis sorunu kesin biçimde ortaya koymalı, yaptırım gücü olanlara sonuçların hesabını kendilerinin vereceğini belirtmeli ve bunu yazılı olarak sunmalıdır.

**Soru 6** (derste sözlü, 01:41:06): Bir bilgisayar mühendisinin bir bilgi sistemi geliştirme projesi kapsamındaki görev ve sorumlulukları nelerdir ve bunlar etik açıdan nasıl değerlendirilmelidir?

> **Cevap (derste kısmen verildi):** Derste ilk dört aşama işlendi. Kavramsal çalışmada proje amacının yasa, yönetmelik, ölçün, etik ve ahlaka uygunluğu denetlenir, uygun değilse proje başlatılmaz. Gereksinimlerde ulaşılamayacak hedef konmaz, donanım ve standartlar doğru tanımlanır (SRS). Çözümlemede gereksinimleri eksiksiz karşılayan en uygun çözüm seçilir, uzman görüşü yazılı olarak verilir. Tasarımda ekiple görüşülür ve standart belge ve diyagramlarla belgelendirilir. Gerçekleştirme, sınama, kurulum ve bakım aşamaları sonraki derse bırakıldı.

## Dersin Toparlaması

Dersin ilk bölümünde fikir ve sanat eserleri konusu yazılım açısından tamamlandı. Yazılıma tek başına patent verilmez, ama bilgisayar temelli bir sistemin parçası olarak patentlenebilir. Başkasının yazılımına tersine mühendislik uygulamak bilgi hırsızlığıdır; açık kaynak ise paylaşımı bilinçli olarak seçen ayrı bir yaklaşımdır. Yazılımdan yararlanmak bir haktır ama bedeli ödenmelidir; firmalar kodlarını hem çalınmaya karşı hem de müşterilerine güvence vermek için kaynak kodu emanetçisine bırakabilir.

İkinci bölümde meslek kavramından ahilik geleneğine, oradan meslek odalarına ve meslek etiğinin amaç ve ilkelerine (doğruluk, yasallık, yeterlik, güvenilirlik, mesleğe bağlılık) geçildi. Mühendisliğin tanımı, katkıları, zararlı örnekleri ve görev-sorumlulukları (zorunluluk, sorumluluk, özen, kınama ya da ödüllendirme) incelendi; TMMOB'nin beş sorumluluk halkası aktarıldı. Son olarak bilgisayar mühendisinin bir bilişim projesinin kavramsal çalışma, gereksinim, çözümleme ve tasarım aşamalarındaki sorumlulukları örneklerle tartışıldı. Sonraki derste gerçekleştirme ve sonraki aşamalarla devam edilecek, ardından kurumsal etiğe geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
