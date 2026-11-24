# Ders 2 Genişletilmiş Notu: Yazılımı Etkileyen Eğilimler, Yanılgılar, CASE ve İlk Süreç Modelleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Yazılımı Etkileyen Eğilimler
- 2. Yazılım Hakkındaki Yanılgılar: Müşteri Açısından
- 3. Yazılım Hakkındaki Yanılgılar: Programcı Açısından
- 4. Yazılım Projelerinin Başarı Oranları
- 5. Yazılım Hakkındaki Yanılgılar: İdari Açıdan
- 6. Yazılım Süreçlerinin Genel Adımları
- 7. CASE Sistemleri
- 8. Dördüncü Kuşak Teknikleri
- 9. Yazılım Geliştirme Süreç Modellerine Giriş
- 10. Şelale Modeli
- 11. Ön Ürün (Prototip) Modeli
- 12. Hızlı Uygulama Geliştirme (RAD)
- Örnek Sorular
- Dersin Toparlaması

## 1. Yazılımı Etkileyen Eğilimler

Geçen hafta "eski yazılım" (legacy) konusuyla biten giriş bölümü bu derste tamamlanıyor. Önce yazılımı ve dolayısıyla yazılımcının işini etkileyen eğilimlere bakılıyor. Slaytta ilk üç eğilim ayrıntılı, son üçü "Ayrıca" başlığı altında listelenmiş (ekrandan, 00:20:00). Hoca ilk üçünü ders kitabında yer alan klasik eğilimler, son üçünü daha güncel eğilimler olarak tanıttı. Bu eğilimler çoğu zaman fark edilmeden etrafımızı sarar. Gösterildiğinde "evet, böyleymiş" denir, ama farkında olmak gerekir.

### 1.1 Yaygınlaşan bilgi işlem

Slayttaki tanım: hesaplama gücünün giderek küçülen alanlara sıkıştırılabilmesi, bilişimin günlük yaşantımızla daha kolay bütünleşmesine olanak sağlıyor. Hoca bunu Moore yasasıyla bağladı: işlem gücü belli aralıklarla iki katına çıkıyor ve bu eğilim kabaca hâlâ sürüyor. Üretim teknolojileri nanometre düzeyine indi. Silisyumun bir sınıra dayanacağı düşünülse de başka yarı iletken malzemeler ve karbon tabanlı malzemeler üzerinde çalışılıyor.

> **Ders sonrası not:** Hoca Moore yasasının periyodunu "6 ayda bir mi, senede bir mi" diye hatırlamaya çalıştı. Moore yasası büyük olasılıkla şöyle bilinir: bir tümdevredeki transistör sayısı yaklaşık iki yılda bir (sık alıntılanan bir biçimde 18 ayda bir) iki katına çıkar.

### 1.2 Yaygınlaşan haberleşme ağı

Slayttaki tanım: kablosuz ağların yaygınlaşması bilişimin günlük yaşantımızla daha kolay bütünleşmesine olanak sağlıyor. 1990'larda bu durum yoktu. 2000'lerde internet evlere yeni giriyordu. 2010'lardan beri 3G, 4G, 5G mobil ağlar her yerde, bu sayede yerel bilgi işlem kaynakları sürekli birbiriyle iletişimde. Hocanın örnekleri:

- Cep telefonundaki mobil uygulamadan banka hesabına girip para göndermek.
- Kurum bilgisayarlarına uzaktan bağlanıp çalışmak.
- Saatlik araç ya da skuter kiralamak: aracı bulmak, kullanmak, ödemesini yapmak ve istenen yere bırakmak.

Hoca bu eğilimlerin birbiriyle etkileşip sinerji oluşturduğunu vurguladı: parçalar bir araya geldiğinde ortaya çıkan etki parçaların tek tek ağırlıklarının toplamından büyüktür. Özellikle ilk iki eğilim birbirini besler.

### 1.3 Özgür yazılım ve açık kaynak yazılım

Hoca önce bu iki kavramın aynı olmadığını belirtti. Özgür yazılımın İngilizcesi *free software*, açık kaynak yazılımınki *open source software*.

Açık kaynak yazılımda kaynak kodu herkes tarafından incelenebilir. Ama bu, kodla istediğinizi yapabileceğiniz anlamına gelmez. Literatürde farklı açık kaynak lisansları ve bunların sürümleri vardır. <!-- BELİRSİZ: Altyazıda lisans adları "Open Software Foundation lisansı, GNU lisansı, GTL lisansı" diye geçiyor; Whisper bozması olabilir (ör. GPL). --> Lisanslar farklı izinler verebilir:

- Ticari gelir elde etmiyorsanız kaynak kodu kendi kullanımınız için istediğiniz gibi değiştirip kullanabilirsiniz.
- Yaptığınız değişiklikleri aynı lisansla toplulukla paylaşırsanız istediğinizi yapabilirsiniz.

Lisans kuralları çerçevesinde açık kaynak yazılım bir firmanın iş modeline de aktarılabilir. Yazılım evleri bir projenin bazı kısımlarını açık kaynak yazılımlarla kurabilir. Bazı firmalar tamamen açık kaynak sistemleri bir araya getirip aralarına kendi yazdıkları ara katman (birleştirme) yazılımlarını koyarak, açık kaynak bileşenleri değiştirerek ya da hiç değiştirmeden kurumsal, büyük ölçekli çözümler sunar.

Hocanın anlatımına göre özgür yazılımda ise adı üzerinde, kısıtlama, sınırlama ya da lisans kuralı olmadan istediğinizi yapabilirsiniz.

> **Ders sonrası not:** Hoca özgür yazılımı "hiçbir lisans kuralı olmayan yazılım" diye anlattı. Özgür yazılım hareketinin tanımında büyük olasılıkla durum farklıdır: özgür yazılım da lisanslıdır (ör. GNU GPL). "Özgür" sözcüğü fiyatı değil, kullanıcının yazılımı çalıştırma, inceleme, değiştirme ve dağıtma özgürlüklerini anlatır. GPL gibi lisanslar bu özgürlükleri korumak için değiştirilmiş sürümlerin de aynı lisansla dağıtılmasını şart koşar.

#### Gevşek ekip

Slaytta: "Gevşek bir ekip tarafından geliştirilen yazılım, daha anlaşılır ve geliştirilebilir olmalıdır." (ekrandan, 00:20:00). Açık kaynak projeleri farklı yaşlardan, kültürlerden ve anlayışlardan insanların oluşturduğu ekiplerce geliştirilir. Bu kişilerin paralel çalışması da gerekmez: bir grup yazılımı bir sürüme getirir, başka bir grup yeni özellikler ekleyip yeni sürüm çıkarır.

Ekip bu kadar dağınık olunca yazılımın iç kalite ölçütleri çok daha önemli hale gelir:

- Yazılım iyi tasarlanmalıdır.
- Kodlama standartlarına uyularak anlaşılır biçimde kodlanmalıdır.
- Teknik belgelendirme eksiksiz ve güncel olmalıdır.

Aynı ofiste çalışan küçük ve sıkı bir ekipte, tasarımda ya da kodda takılan biri ekip arkadaşına hemen sorup yanıt alabilir. Gevşek ekipte araya bir haberleşme süresi girer. Kişiler farklı zaman dilimlerindeyse ve başka sorumlulukları varsa bir sorunun yanıtı çok uzun sürebilir. Bu yüzden hocaya göre bir açık kaynak yazılımın kalitesini en çok belirleyen şey, adanmış, hızlı yanıt veren ve belgelendirmeyi sağlam tutan bir topluluğun olup olmamasıdır.

### 1.4 Takım çalışması zorunluluğu

Bilgisayar sistemlerinin ilk zamanlarında bir kişi oturup birkaç hafta ya da birkaç ayda dönemin ihtiyaçlarını karşılayan bir yazılım hazırlayabiliyordu. Bu dönem on yıllar önce geride kaldı. Bilgi sistemleriyle giderek daha zor problemler çözülüyor ve işin hacmi tek bir kişiyi çoktan aştı. Yazılım evleri farklı disiplinlerden çalışanlara farklı sorumluluklar verip onları projenin parçası yapıyor. Farklı uygulama alanlarında konu uzmanlığı da çok önemli, yani ortaya çıkan iş çok disiplinlidir.

> **Hocanın vurgusu:** "Ben bilgisayar mühendisiyim, bilgisayarlarla çalışırım, insanlarla değil" diye düşünüyorsanız yanılıyorsunuz. Sosyal yeteneklerinizi ve ekip çalışması yeteneklerinizi mutlaka geliştirmeniz gerekiyor. Bireysel oyuncu değil, takım oyuncusu olmalısınız. Hoca bu yüzden üniversite yıllarında öğrenci kulüplerinde etkinliklere katılmayı önerdi: farklı insanlarla farklı alanlarda çalışmak profesyonel hayatta gereken yetenekleri şimdiden geliştirir.

### 1.5 Küreselleşme

Hoca küreselleşmeyi siyasi ya da uluslararası ilişkiler anlamında değil, ekonomik ve lojistik anlamda kullandığını özellikle belirtti. İki yönü var:

- **Tedarik:** Ürününüzün alt bileşenlerini kendiniz ve kendi ülkenizde üretmek zorunda değilsiniz. Bileşenler dünyanın dört bir yanında bazen daha ucuza, bazen daha kaliteli, bazen ikisi birden üretiliyor. Çoğu zaman birden fazla tedarikçi alternatifi de vardır. Bu durumda tedarik zincirinin yönetimi önem kazanır. Bu alan endüstri mühendisliğinin bir alt alanıdır (lojistik), dolayısıyla yazılımcılar tedarik zincirinden sorumlu endüstri mühendisleriyle birlikte çalışabilir.
- **Müşteri ve ekip:** Yazılımı yalnız kendi ülkenizde satarsanız tek bir ülkedeki müşterilere hitap edersiniz. İhraç ederseniz olası hedef kitleniz ve geliriniz katlanarak artar. Bunun için yazılımın farklı dilleri desteklemesi ve satılacağı ülkelerin kanun, kural, mevzuat ve pazar eğilimlerine uyması gerekir. Bu uyum ek çaba ister, ama karşılığında çok daha fazla gelir elde edilir. Bazı ülkelerde pazar payı yakalanırsa oralarda önce temas ya da satış ofisi, zamanla yazılım geliştirme ofisi açılabilir. Böylece kendinizi çok uluslu bir ekibin üyesi olarak bulabilirsiniz. Hocaya göre bu yüksek olasılıkla karşılaşılacak bir durumdur.

### 1.6 Ekonomik krizler

Araştırmalara göre bir kurum finansal zorlukla karşılaşınca tasarrufa ilk olarak bilgi işlem departmanından ve yazılım projelerinden başlıyor. Projeler ya hiç başlatılmıyor ya da ilk aşamalardaysa doğrudan sonlandırılıyor. Sonlandırma sonucunda ortaya çıkan fazla personel de işten çıkarılıyor. Hoca bunun hem Türkiye'de hem uluslararası ölçekte geçerli olduğunu, anketlerin bunu gösterdiğini söyledi.

Bu bir tehdittir, ama fırsata da çevrilebilir: aynı işi aynı kalitede ama daha verimli, daha ucuza ve daha az kaynakla yapmayı sağlayan yazılımlar ve sistemler üreten firmalar kriz dönemlerinde önemli avantaj kazanır.

## 2. Yazılım Hakkındaki Yanılgılar: Müşteri Açısından

Yanılgılar üç bakış açısından inceleniyor: müşteri, teknik personel (programcı) ve işveren (yönetim). Hoca bu yanılgılara düşen birini gördüğünüzde müdahale etmeniz gerektiğini söyledi.

Slayt (ekrandan, 00:40:00):

- "Programın yazılmasına başlanması için amaçları genel olarak belirlemek yeter, ayrıntılar sonra kararlaştırılabilir. Nasıl olsa yazılım esnektir."
  - Belirsiz gereksinimler, çürük atılmış temele benzer.
- "Yazılım esnektir. Değişen gereksinimler kolayca sisteme uyarlanabilir."
  - Yazılım yaşam döngüsünde ilerledikçe değişen gereksinimleri yazılıma uyarlamanın bedeli üstel olarak artar.
- Sonuç: Yazılım esnek bir oyun hamurundan çok kil veya cam gibidir.
  - Çevik süreçlerle esnekliğin artırılması hedeflenmektedir.

### 2.1 Belirsiz gereksinimler

Bir inşaatta temel sağlam zemine ve sağlam malzemeyle atılmazsa bina en ufak sorunda çökebilir. Gereksinimlerdeki belirsizlik de yazılım projesinin başarısızlığına davetiye çıkarır. Hoca başarının ölçüsünü burada kısaca tanımladı: yazılımın önceden belirlenen süre içinde, önceden belirlenen bütçeyle, önceden belirlenen bütün işlevleri karşılayarak tamamlanması.

Hoca bu yanılgıların kökünün İngilizce *software* sözcüğünde olduğunu söyledi: *hardware*'in karşısında *soft* geçtiği için yazılımın esnek olduğu düşünülür.

### 2.2 Değişiklik maliyetinin üstel artışı

> **Hocanın vurgusu:** Can alıcı nokta şu: yazılımın yaşam döngüsünde ilerledikçe değişen gereksinimleri yazılıma uyarlamanın bedeli üstel olarak artar. Bütün yanılgılar bu temel dinamiği bilmemekten kaynaklanır.

Hoca bunu slayt üzerine elle çizdiği bir grafikle gösterdi (ekrandan, 00:40:00): yatay eksen zaman ($t$), dikey eksen maliyet ($\$$). Yatay eksende eşit aralıklarla (örneğin birer ay) birkaç nokta işaretledi ve her birinde yapılacak bir değişikliğin maliyetini giderek daha yüksek çizdi. Noktaları birleştiren eğri hızla yükselen bir eğridir: zamandaki küçük ilerleme maliyette büyük artışa yol açar. Hoca çizimin tam istediği gibi olmadığını, ama olayın bu olduğunu belirtti.

Somut karşılaştırma:

- Analiz aşamasında yapılan işler çoğu zaman bir kelime işlemcide belli kurallara uyarak yapılan düzenlemelerdir. Kullanım ihtiyaçlarını UML kullanım durumu (use case) şemalarıyla çizerken yeni bir ihtiyaç eklemek bir iki tıklamayla yeni bir elips ya da ilişki eklemektir. Kimin neyi yapacağını değiştirmek, bir aktörle kullanım durumu arasındaki ilişkiyi alıp başka bir yere bağlamaktır.
- Tasarıma, oradan da kodlamaya geçildikçe aynı hatayı düzeltmenin maliyeti çok daha yüksektir.

### 2.3 Kil ve cam benzetmesi

Çocukların oyun hamuruna istediğiniz şekli verebilir, parçaları koparıp yapıştırabilir, farklı renkleri karıştırabilirsiniz. Cam ve kil öyle değildir:

- Cam, çok yüksek sıcaklıkta akışkan hale getirilen malzemenin döndürülerek, çevrilerek ve soğutularak şekillendirilmesiyle yapılır.
- Kilden bardak ya da vazo yapılırken çamur halindeki malzeme dönen bir tezgâhta elle şekillendirilir.
- Malzeme sertleştikten sonra yapılabilecek değişiklikler kozmetiktir: üstünü boyamak, deseni beğenmezseniz silip yeniden çizmek gibi.
- Vazonun ya da bardağın biçimini beğenmezseniz tek yol kırmaktır. Camı yeniden ısıtıp aynı malzemeyle baştan başlayabilirsiniz. Seramikte ise hocanın bildiği kadarıyla böyle bir olanak yok, yeni malzemeyle baştan başlanır.

Sonuç: yazılım düşünüldüğü kadar esnek değildir. Yazılım projelerinin esnekliğini artırmaya çalışan yaklaşımlar vardır. Bunların başında çevik (agile) süreçler gelir ve ilerleyen haftalarda bu süreçlerin hangi tekniklerle esneklik kazandırdığı ayrıntılı ele alınacak.

## 3. Yazılım Hakkındaki Yanılgılar: Programcı Açısından

Slayt (ekrandan, 00:45:00):

- Yazılımı tamamlayıp müşteriye teslim edince işimiz biter.
  - Yazılım üstünde harcanan çabanın yarısından fazlası, yazılımın müşteriye ilk teslimatından sonra harcanmaktadır.
- Yazılımı tamamlamadan kalitesini ölçemem.
  - Kalite güvence yöntemleri yazılım hayat döngüsünün her aşamasında uygulanabilir.
  - Çözümleme sürecinde dahi kullanılabilecek kalite ölçütleri bulunmaktadır.
- Yazılım eşittir program.
  - Gereksinim analizi başlı başına bir emektir.
  - Dokümantasyon ve sınama çalışmalarını da unutmayın!
  - Bazı durumlarda entegrasyon çalışmaları da gerekmektedir.
- Yazılım mühendisliğinin gereklerini uygulayarak boşuna çaba harcıyoruz.
  - Haritası olmayan yolunu kaybeder.
  - Kalite için harcanan çaba, karşılığını yazılım hayat döngüsünün ilerleyen aşamalarında fazlasıyla ödeyecektir.
  - Küresel ölçekte yazılım projelerinin %50'si başarısızlığa uğramaktadır.

### 3.1 "Teslim edince işimiz biter"

Hocaya göre teslimatla iş bitmez, asıl o zaman başlar. Çabanın en az yarısı, çoğunlukla yarısından fazlası ilk teslimattan sonra harcanır. Nedenleri:

- Değişiklik maliyetinin zamanla üstel olarak artması (en önemli etken).
- Sahaya sürmeden önce ne kadar çok, ne kadar düzgün ve ne kadar yüksek kod kapsama oranıyla test edilirse edilsin, fark edilemeyen hatalar olacaktır. Bu, işin doğasıdır.
- Yazılımın hitap ettiği problem alanında değişiklikler olur: mevzuat değişiklikleri, müşterinin üst yönetiminin önceliklerinin ya da çalışma biçiminin değişmesi gibi. Bunlar ilk zamanlarda az olur, ama orta vadede mutlaka olur ve yazılıma eklenmesi beklenir.
- Yazılım sahaya çıktığında proje zaman ekseninde epey ilerlemiştir, dolayısıyla her değişiklik epey çaba ister.

Ek zorluklar: Yazılımı tasarlayıp kodlayan ekip ile bakımını yapan ekip çoğu zaman farklıdır. Teknik belgelendirme eksikse sorun çok daha ciddi boyutlara ulaşır. Hoca burada bakım aşamasını tanımladı: yazılım sahaya sürüldüğü ya da müşteriye özel yazılımsa müşteride kullanılmaya başlandığı andan itibaren yapılan bütün işlemler bakım aşamasındadır.

> **Hocanın vurgusu:** Yazılım yalnız koddan ibaret değildir. İster teknik ister son kullanıcıya yönelik olsun, belgelendirme yazılımın çok önemli bir parçasıdır.

### 3.2 "Tamamlamadan kalitesini ölçemem / test edemem"

Bu da bir yanılgıdır. Yazılım yaşam döngüsünün her aşamasında uygulanabilecek kalite güvence yöntemleri vardır. Gereksinim analizi (çözümleme) aşamasında bile kullanılabilecek kalite ölçütleri ve sınama yöntemleri bulunur. Hoca ölçmenin önemini şöyle bağladı: ölçemediğiniz bir şeyi yönetemez ve değerlendiremezsiniz. Bir konuda somut ölçüt yoksa o konudaki kalite güvence çalışmaları havada kalır.

Bu yüzden kalite güvence ve sınama gibi etkinliklere "şemsiye süreçler" gibi bakmak gerekir: şemsiye geniş ve kapsayıcıdır, bu etkinlikler de geliştirme sürecinin her aşamasında uygulanabilen başlı başına etkinliklerdir.

### 3.3 "Yazılım eşittir program"

Gereksinim analizi etkinlikleri bile başlı başına bir emektir. Derste bunların önce teorisi, sonra uygulaması görülecek. Belgelendirme ve sınama çalışmaları unutulmamalıdır. Bazı durumlarda tümleştirme (entegrasyon) çalışmaları da gerekir: geliştirilen yazılım çoğu zaman başka sistemlerle birlikte çalışmak zorundadır. Burada kastedilen basit veri aktarımı değil, koordineli biçimde birlikte çalışma zorunluluğudur. Gereksinim belirleme aşamasında tümleştirme gereksinimleri iyi tespit edilmeli, tasarım ona göre yapılmalı ve sınamalara mutlaka sistem testleri eklenmelidir.

### 3.4 "Yazılım mühendisliği boşuna çaba"

"Bu kadar şeyi yapana kadar kaç satır kod yazardım" diye düşünülebilir. Hocanın yanıtı "haritası olmayan yolunu kaybeder" deyimiyle başladı. Yazılım projeleri daha önce çalışılmış benzer konularda bile olsa her biri farklı bir deneyim, farklı bir maceradır. Aynı yolu tekrar gitmek gibi değildir.

Kalite için, yazılım mühendisliği öğretilerini kullanarak harcanan çaba geleceğe yapılan bir yatırımdır. Bu gelecek uzak da değildir: yazılımın müşteriye teslim edildiği, yani bakım aşamasının başladığı andan itibaren başlar. Bakımı kolaylaştırmak için yapılan her etkinlik kendini fazlasıyla amorti eder. Önemli bir gerçek olarak, yalnız Türkiye'de değil küresel ölçekte yazılım projelerinin yüzde ellisi başarısızlığa uğruyor.

## 4. Yazılım Projelerinin Başarı Oranları

Hoca bu oranı göstermek için bir konferans sunumundan (UYMS 2015) iki slayt açtı.

### 4.1 Dr. Dobb's Journal 2013 IT Project Success Survey

Slaytta (ekrandan, 00:55:00) beş süreç türü için yatay yığılmış çubuk grafik var. Renkler:

- **Başarılı (yeşil):** bütçe, süre ve işlev yönlerinin üçünde de başarı. Öngörülen bütçe içinde, öngörülen zamanda ve öngörülen bütün işlevlerle sahaya çıkmak.
- **Zorlanılmış (sarı):** slayttaki tanımla, bütçe, süre, işlev yönlerinden en azından birinde başarısızlık.
- **Başarısız (kırmızı).**

Satırlar, projeyi geliştiren yazılım evinin kullandığı süreci gösterir. Grafikten okunan yaklaşık değerler (çubuk uzunluklarından tahmin, kesin sayılar slaytta yazmıyor):

| Süreç | Başarılı (yaklaşık) | Başarılı + zorlanılmış (yaklaşık) |
|---|---|---|
| Lean (yalın) | %72 | %93 |
| Iterative (yinelemeli) | %65 | %93 |
| Agile (çevik) | %64 | %94 |
| Ad-Hoc | %50 | %85 |
| Geleneksel | %49 | %82 |

<!-- BELİRSİZ: Tablodaki yüzdeler kareden göz kararı okundu; slaytta sayı yazmıyor. -->

Hocanın yorumu: Tam başarı geleneksel süreçlerde yaklaşık %50, diğerlerinde %65-70'e kadar çıkıyor. Zorlanılmış başarı da sayılırsa resim iyileşiyor: geleneksel süreçlerde %80 dolayı, çevik süreçlerde %90'ın biraz üstü. Ama yalnız yeşil kısma, yani tam başarıya bakılırsa oran kabaca %50'dir.

Süreç türleri ilerleyen haftalarda tek tek görülecek. Geleneksel süreç şelale (waterfall) sürecidir ve ilk olarak o ele alınacak. Çevik süreçler üzerinde ayrıca uzun durulacak. *Ad hoc* ise "topa gelişine vurmak" ya da "kervan yolda düzülür" gibidir: o anda neye ihtiyaç varsa o yapılır, belli bir düzen ve sistematik yoktur. Süreç çalışanların deneyimine, alışkanlıklarına ve eğilimlerine bağlıdır. Aynı ekip bile farklı projelerde farklı biçimde çalışabilir.

### 4.2 Türkiye'de çevik projelerin başarı oranları

İkinci slayt (ekrandan, 01:00:00) Türkiye'de çevik yazılım geliştirme üzerine bir incelemeden (UYMS 2014) alınmış bir pasta grafiğidir. Soru: "Kurumunuzda gerçekleştirilen çevik projelerin başarı oranları". Dilimlerdeki ilk sayı yanıt sayısı, ikincisi yüzdedir:

| Başarı oranı aralığı | Yanıt sayısı | Yüzde |
|---|---|---|
| %10'dan az | 2 | %6 |
| %10-%25 | 4 | %12 |
| %26-%50 | 5 | %14 |
| %50-%75 | 13 | %37 |
| %76-%100 | 11 | %31 |

Hesap (python ile kontrol edildi):

- Toplam yanıt: $2+4+5+13+11 = 35$.
- %75 ve üstü başarı: $11/35 \approx \%31$. Hoca önce "%32" dedi, sonra "%30" diye düzeltti; slayttaki değer %31'dir.
- Esnetilmiş başarı (%50 ve üstü): $(13+11)/35 = 24/35 \approx \%68{,}6$, slaytta $\%37 + \%31 = \%68$.

Hocanın yorumu: çevik süreçlerde esnetilmiş başarı yaklaşık %68-70. Önceki uluslararası çalışmaya göre biraz daha düşük, ama paralellik gösteriyor. Yani "işimiz kolay değil."

### 4.3 Başarı oranı neden hâlâ düşük?

1960'larda "yazılım krizi" (software crisis) diye bir olgu gözlemlendi ve yazılım projelerinin disiplinli bir süreç içine alınması gerektiği anlaşıldı. Ardından çeşitli yazılım geliştirme süreçleri üzerinde çalışılmaya başlandı. Aradan 50-60 yıl geçti ve başarı oranı hâlâ ortalama %50 dolaylarında. Hocaya göre neden şu: bilgi sistemleri giderek daha zor ve daha büyük ölçekli problemlerin çözümünde kullanılıyor. Eski projelerin çözmeye çalıştığı problemlerin hacmiyle bugünkü projelerinki arasında çok büyük fark var. Hedef sabit kalmıyor, istekler sürekli yükseliyor ve yazılım mühendisliği de sürekli yükselen bu çıtayı aşmaya çalışıyor. Yani alan yerinde saymıyor, ama çözülmeye çalışılan problemler de yerinde saymıyor.

## 5. Yazılım Hakkındaki Yanılgılar: İdari Açıdan

Slayt (ekrandan, 01:20:00):

- İşler yetişmiyorsa takıma yeni programcılar ekleriz.
  - Yazılım hayat döngüsü içerisinde ilerledikçe, yeni elemanların yazılıma hakim olması üstel olarak zorlaşır. İşler daha da gecikir.
- Geliştirmesini üstlendiğim yazılımı tamamen veya kısmen fason yaptırırım.
  - Proje ilerlemesini kendi içinde denetleyemeyen bir firma, dışarıya verdiği işi izlemekte de zorlanacaktır.
- Açık kaynak yazılım üretirsem kar edemem.
  - Danışmanlık hizmetleri ile kar edilebilir.
  - Başka iş modelleri de vardır.

### 5.1 Geciken projeye eleman eklemek

Hoca bunu en büyük, en yaygın ve en sık gördüğü yanılgı olarak tanıttı. Yazılım inşa etmek duvar örmeye benzemez. Bir işçi bir duvarı on günde örüyorsa on işçi aynı duvarı bir günde örebilir. Yazılımda bu orantı yoktur. Takıma yeni programcı eklemek projeyi hızlandırmaz, tersine daha çok sarkıtır.

Neden: Projenin dışından, aynı firmadan bile olsa, yeni katılan çalışan anlamlı iş yapabilmek için o zamana kadar neyin nasıl yapıldığını öğrenmek zorundadır. Aksi halde üstüne bir şey ekleyemez ve düzeltme yapamaz. Zamanın yetişmeyeceği de genelde projenin yarısından sonra anlaşılır. O noktada öğrenilmesi gereken bilgi birikimi çok fazladır ve bu birikimi özümsemek doğrusal değil üstel biçimde zorlaşır. Yeni katılanların elbette değerli katkıları olur, ama yazılıma hakim olmaları için geçen süre eklenince işin sonu daha da gecikir.

> **Hocanın vurgusu:** Süre yetişmiyorsa yapılacak iki şey vardır: ya bazı işlevlerden vazgeçilir ya da süre uzatılır. Bu, müşteriyle anlaşarak yapılır. Eleman ekleyerek bu sorun çözülmez. Henüz gerçeklenmemiş kısımların açık kaynak ya da hazır bileşenlerle karşılanma olasılığı da çok düşüktür. Karşılansa bile uyarlama çabası gerekir ve bu da işi ayrıca riske atar.

> **Ek bilgi (derste anlatılmadı):** Bu gözlem literatürde büyük olasılıkla Brooks yasası olarak bilinir: "Geciken bir yazılım projesine insan eklemek onu daha da geciktirir." Fred Brooks bunu 1975 tarihli *The Mythical Man-Month* kitabında dile getirmiştir.

### 5.2 Fason yaptırma (dış kaynak kullanımı)

Yönetim yazılımın bir kısmını ya da tamamını dış kaynağa yaptırmayı düşünebilir. Olabilir, ama bir yazılım evi kendi içindeki proje ilerlemesini düzgün denetleyemiyorsa dışarıya yaptırdığı işi hiç izleyemez. Hoca ilerleyen haftalarda görülecek yazılım süreç olgunluk modelleri arasında dış kaynak kullanımına yönelik başlı başına bir model bile olduğunu söyledi. Bu da işin ne kadar ciddi olduğunu gösterir.

### 5.3 Açık kaynak üretip kâr etmek

Birincisi, açık kaynak yazılımı da lisanslar yönetir. Esas kâr yolu ise danışmanlık hizmetleridir. Günümüzün büyük ölçekli problemlerine hitap eden bir yazılımın kaynak kodu açık olsa bile müşterinin ona tamamen hakim olması zordur. Çoğu müşterinin bunun için insan kaynağı yoktur. Bilgi işlem departmanı ya yoktur ya da az sayıda çalışanla ancak günlük operasyonel ihtiyaçları karşılar. Bu yüzden yazılımı geliştiremez, bir sorunla karşılaştığında çözemez. Burada danışmanlık, servis ve bakım anlaşmaları devreye girer.

Hocanın örneği: Pek çok Linux dağıtımı ücretsizdir. Ama 7/24 çalışan, ayrıntılı raporlama ve anlık izleme gerektiren bir bilgi sisteminde Linux sunucularda bir sorun çıktığında ya da ölçek artırmak gerektiğinde kurum bunu kendi kaynaklarıyla yapabilecek düzeyde olmayabilir. Bu çok doğal ve sık karşılaşılan bir durumdur. Yazılımı en iyi bilen onu üreten kurumdur, sorunları en hızlı ve verimli o çözer, bunu da bakım anlaşması ücreti karşılığında yapar. Kurum kendi kaynakları yeterliyse kendisi de yapabilir, maliyet hesabına göre ne kadar hizmet alacağına karar verir. Hizmet almaya karar verenlerin sayısı yüksek olduğu için yazılım evleri bu yolla sağlam ve düzenli gelir elde eder. Slayta göre başka iş modelleri de vardır.

## 6. Yazılım Süreçlerinin Genel Adımları

İlerleyen haftalarda farklı süreç modelleri görülecek. Hepsinde işler farklı biçimlerde, farklı ağırlıklarla ele alınır, ama ortak işler beş başlık altında toplanabilir. Bu başlıklar klasik modeldeki yürütülme sırasıyla da paraleldir (ekrandan, 01:30:00):

- Çözümleme (Analysis)
- Tasarım (Design)
- Gerçekleme (Implementation)
- Sınama (Testing)
- Bakım (Maintenance)

### 6.1 Çözümleme

Slayt (ekrandan, 01:30:00):

- Çözümleme: Bir şeyi **anlayabilmek** için parçalarına ayırmak.
- Gerçeklenecek sistemi **anlamaya** yönelik çalışmalardan ve **üst düzey planlama eylemlerinden** oluşur.
  - Uygulama alanı
  - Kullanıcı gereksinimleri
  - Program parçaları arasındaki üst düzey ilişkiler ve etkileşimler (NYP'deki parçalar: sınıflar ve nesneler)
- "Bir sorunu anlamadan çözemezsiniz."

Yazılım gerçek dünyadaki bir problemi çözmek, kolaylaştırmak ya da izlemek için yazılır. Anlaşılmayan şey çözülemeyeceği için önce problem alanı anlaşılır. Sonra bu problemi çözecek sistemin ne yapması ve hangi özelliklere sahip olması gerektiği, yani ihtiyaçlar anlaşılır. Nesneye yönelik yaklaşımda program parçaları sınıflar, nesneler ve aralarındaki ilişkilerdir.

Üst düzey planlama, projenin ne kadar sürede, ne kadar maliyetle, ne kadar adam-ay çabayla tamamlanacağını ve hangi kaynakların kullanılacağını belirlemektir. Hangi işi kimin ne zaman yapacağı gibi ayrıntılar daha alt düzeydir ve zamanla ayrıntılanır. Ana plana bağlı kalınmaya çalışılır, ilerleyen aşamalarda üst düzey planda değişiklik yapmamaya çalışılır.

### 6.2 Tasarım

Slayt (ekrandan, 01:35:00):

- Tasarım: Bir araştırma ve/veya geliştirme sürecinin çeşitli dönemlerinde izlenecek yol ve işlemleri tasarlayan çerçeve.
- Çözümleme ile anlaşılan sorun tasarım aşamasında kağıt üzerinde (!) çözülür.
- Yazılım ↔ tasarıma yönelik şemalar (NYP'de bazı tür UML şemaları), elektronik ↔ devre şemaları, mimari ↔ kat planları.

Çözümlemede **ne** yapılacağı, tasarımda **nasıl** yapılacağı keşfedilir. "Kağıt üzerinde" ifadesindeki ünlem şunu anlatır: gerçekten kâğıt kalem kullanmak gerekmez, teknik belgelendirme yazılımlarıyla çeşitli şemalar çizilir. Bu araçlar ücretsiz basit gereçlerden, geliştirme ortamıyla tam bütünleşik ve çift yönlü çalışan (belgedeki değişikliği koda, koddaki değişikliği belgeye otomatik yansıtan) araçlara kadar uzanır.

Hoca başka mesleklerle benzetme yaptı. Bilgisayar mühendisliği görece yeni bir meslek: modern kökeni İkinci Dünya Savaşı'ndaki kod kırma çalışmalarına (öncesinde Analytical Engine gibi makinelere) dayanır, yani yaklaşık 60 yıllık bir uzmanlaşmadır. Mimarlık ve inşaat mühendisliği ise binlerce yıl öncesine, piramitlere kadar gider. Bu yüzden benzetmeler kaçınılmazdır:

- Mimarlar kat planları çizer, inşaat mühendisleri statik ve dinamik hesapları yapar, işçiler inşa eder.
- Elektrik-elektronik mühendisleri devre şemaları çizer, simülasyonda çalıştırıp doğrular, sonra fiziksel devreyi üretir.
- Yazılım mühendisliğinde de tasarıma yönelik şemalar vardır ve tasarım bu şemalarla ortaya konur.

### 6.3 Gerçekleme

Eldeki tasarım bir programlama diliyle kodlanır (ekrandan, 01:35:00). Hoca bu aşamada fazla durmadı, çünkü öğrenciler önceki dönemlerde farklı derslerde zaten gerçekleme yaptılar. Dersin odağı gerçekleme dışındaki aşamalardır.

Tasarım, kullanılacak programlama yaklaşımı düşünülerek yapılmalıdır: yapısal programlama mı, nesneye yönelik programlama mı, yoksa daha farklı bir yaklaşım mı kullanılacağı belirlenmiş olmalıdır. Bu karar aslında çözümleme aşamasında, problemi çözmeye en uygun araçlar belirlenirken verilir.

> **Ders sonrası not:** Hoca "daha egzotik programlama yaklaşımları" için "dinamik programlama" örneğini verdi. Dinamik programlama büyük olasılıkla bir programlama paradigması değil, bir algoritma tasarım tekniğidir. Paradigma örnekleri olarak fonksiyonel ya da mantıksal programlama verilebilir.

### 6.4 Sınama

Yazılımın sınanması çok önemlidir. Temel neden yine aynıdır: yaşam döngüsünde ilerledikçe ortaya çıkan hataların giderilme maliyeti üstel olarak artar. Üstelik hataların çoğunun kökeni gereksinimlerin belirlenmesi aşamasına, o olmasa da tasarımda verilen yanlış kararlara uzanır. Eskiye dayanan hataların çözümü daha zordur. Bu yüzden:

- Hatalar olabildiğince erken bulunmalıdır, yani sınamaya erken başlanmalıdır. Sınama yazılımın ilk aşamalarında bile başlayabilir.
- Sınama olabildiğince sık yapılmalıdır.
- Sınama başlı başına bir çaba olduğu için onu kolaylaştıran süreçler ve yazılımlar kullanılmalıdır.

Bu konular ilerleyen haftalarda sınama başlığında örneklerle görülecek, öğrenciler de kendi test senaryolarını yazıp çalıştıracak.

### 6.5 Bakım

Slayt (ekrandan, 01:40:00):

- Yazılımın faaliyete geçirilmesinden sonra sistemde yapılan değişikliklerdir.
  - Yazılım hatalarının düzeltilmesi:
    - Kodlama hataları
    - Tasarım hataları (!)
    - Gereksinim ve analiz hataları (!!)
  - Sistemin işlevlerini değiştirme veya işlevlere eklemeler/çıkarmalar,
  - Yazılımın farklı bir ortama taşınması (programlama dili, işletim sistemi, donanım, iklim, vb.) (porting)

Ünlemlerin anlamı: tasarım hataları daha ciddi, gereksinim ve analiz hataları çok daha ciddidir, çünkü hata ne kadar geriye uzanıyorsa düzeltmek o kadar zordur. Hata çok geriye gitmesin diye umulur, ama bu durumla sık karşılaşılır. Gereksinimler de koşullar değiştikçe ister istemez değişir.

Yazılımın başka bir dile, işletim sistemine ya da donanıma taşınması gerekebilir. Hoca iklimin bile bakım gereksinimi doğurabileceğini örneklerle anlattı:

- Gömülü bir sistem yazılımı, donanımın farklı fiziksel ortamlarda farklı çalışma koşullarına maruz kalmasından etkilenebilir. Örneğin bir araba motorunun sıcak ve soğuk iklimde farklı ayarlanması.
- Bir helikopterin motor gücünü ayarlayan parçanın yüksek irtifada ve sıcak iklimde yeterince verimli çalışamaması.

Toplam çabanın ortalama %50'si bakım aşamasında harcanır.

### 6.6 Yeniden mühendislik

Yeniden mühendislik (refactoring, software reengineering) de bakım etkinliği sayılır. Teknik olarak tanımı: yazılımın işlevlerini, arayüzlerini değiştirmeden iç yapısını değiştirmek.

Tersine mühendislikle karıştırılmamalıdır. Tersine mühendislik hazır bir ürünü parçalarına ayırıp inceleyerek onun bir benzerini, sıfırdan başlamak yerine incelemeden elde edilen kazanımları kullanarak üretmektir.

Yeniden mühendisliğe neden ihtiyaç duyulur:

- **Belgelendirme:** Belgelendirme aksatılmışsa (özellikle zaman sıkıntısında insanlar belgelendirmeyi azaltma eğiliminde olur) yazılımı belgelendirmek için yapılabilir. Hoca bunu anlamadığını söyledi: belgelendirme ne kadar sağlamsa sonraki işler o kadar kolay yapılır.
- **Tasarımı iyileştirmek:** Ortaya çıkan gereksinim değişiklikleri mevcut tasarımla verimli karşılanamıyorsa, baştan yeni yazılım yazmak yerine tasarımın bazı kısımları uyarlanır.
- **Farklı ortama taşımak:** İşletim sistemi ya da donanım değişikliği.

Hoca bütün bu aşamaların İngilizce karşılıklarını bilmenin önemli olduğunu vurguladı: bu konulardaki en güncel ve kapsamlı literatür büyük ölçüde İngilizcedir.

## 7. CASE Sistemleri

### 7.1 Tanım

Slayt (ekrandan, 01:45:00):

- CASE (Computer Aided Software Engineering); yazılım mühendisliği görevlerinin, bilgisayar yardımı ile otomatik olarak (!) gerçekleştirilmesidir.
- CASE ortamı, belirli bir sorunun çözümü ya da bir kurumun yönetim bilişim sistemi için gerekli yazılımı otomatik olarak geliştiren bir bilgisayar sistemidir.
  - Bu sistem; otomatik yazılım araçlarının ve yapısal yöntemlerin bir kombinasyonu olup, yazılım geliştirme sürecini adım adım izleyerek gerçekleştirmekte ve yazılımı üretmektedir.
  - Avrupa ülkelerinde "bütünleşik programlama desteği ortamı" anlamında IPSE (Integrated Programming Support Environments) adı da verilir.

"Otomatik" sözcüğündeki ünlemin nedeni: Her şey otomatik yapılabilseydi yazılım mühendislerine ve programcılara ihtiyaç kalmazdı, gereksinimler verilir ve sistem hepsini kodlardı. Hocaya göre ChatGPT gibi sistemler bile aslında Stack Overflow gibi kaynaklardan belirli problemlerin çözüm parçalarını bulup veriyor. Bunları bütüncül bir yazılım sistemine dönüştürmek 50 yıldır vaat ediliyor, ama gerçekçi değil. Yine de iyi tanımlanmış bazı etkinliklerin bilgisayar desteğiyle yürütülmesi avantajlıdır ve yapılmalıdır: projelerin başarısızlık riski yüksek ve sistemler sürekli büyüyor, alınabilecek her desteğe ihtiyaç var.

CASE sistemine bir girdi verilmelidir. Temel girdi, sürecin nasıl yürütüleceğinin bilgisidir. Hedeflerden biri bu girdilerin yalnız bir programcı tarafından değil, bir konu alanı uzmanı tarafından da girilebilmesidir.

### 7.2 CASE sisteminin öğeleri

Slayt (ekrandan, 01:50:00):

- CASE sisteminin 3 öğesi:
  - İşlemler: Yazılımın geliştirme sürecini düzenlemekte kullanılan yöntem bilimi
  - Yöntemler: Projenin gerektirdiği standart tasarım teknikleri ve yöntemleri
  - Bütünleşik otomatik yazılım geliştirme araçları
- İşlemler ve yöntemlere ait bilgiler bir ansiklopedik arşivde saklanmaktadır.
- Bu bilgileri kullanarak, otomatik araçlar, diyagram çizimi ve betimleme, tasarım analizi, kodlama işlemlerini gerçekleştirmektedirler.
- İşlemlerin yürütülmesinde etkileşim ve ekrandan yararlanılmaktadır.
- Her basamakta elde edilen sonuçlar, sırası geldiğinde kullanılmak üzere ansiklopedik arşivde saklanmaktadır.

Çalışma döngüsü şöyledir: Programcı ya da konu uzmanı arşivdeki bilgileri ve otomatik araçları kullanarak diyagramlar çizer, betimlemeler ve tasarımlar yapar. CASE sistemi tasarımı tanımlı ölçütlere göre değerlendirir ve zayıf bulduğu noktalar hakkında geri bildirim verir. Kullanıcı tasarımını ve gerçeklemesini buna göre düzenler, tekrar geri bildirim alır. Döngü son üründen memnun olunca biter. Etkileşim klavye ve fareyle yapılır. Her basamağın sonuçları otomatik olarak arşive eklendiği için CASE sistemi problem çözdükçe başka problemleri çözebilecek şekilde adım adım daha yetkin hale gelir.

### 7.3 CASE teknolojisi ve bölümleri

Slayttaki şema (ekrandan, 01:55:00) metin olarak:

```text
Grafik Görüntü (bilgisayar)
   <-> Üst CASE bölümü  -> Diyagram Çizimi ve Tanımlama Araçları
   <-> Orta CASE bölümü -> Tasarım Analizi
   <-> Alt CASE bölümü  -> Kod Çeviricisi
Üç bölümün araçları  <->  Ansiklopedik Arşiv (silindir)
                           - Fonksiyonlar
                           - İşlevler
                           - Veri modelleri
                           - Veri sözlüğü
```

Slayttaki açıklamalar:

- Üst CASE bölümü: Bilgisayara dayalı diyagram çizim araçları şeklinde arayüz üzerinden kullanılan, iş mantığını betimleyen gereçler.
- Orta CASE bölümü: Sistem analizi ve tasarımı gereçleri.
- Alt CASE bölümü: Kod üretim gereçleri.
- Orta ve alt bölümlerde ölçüm ve belgelendirme ile hata ayıklama gereçleri de yer almaktadır (otomatik).

Üst bölümde iş akış süreçleri ya da bu derste görülecek UML şemaları gibi diyagramlar çizilir ve neyin nasıl yapılacağı CASE sistemine anlatılır, yani iş mantığı betimlenir. Hoca iş süreçlerinin modellenmesinde CASE'e özgü olmayan, başka birçok araçta da kullanılan iki yaygın standart dili tahtaya yazdı:

- **BPMN** (Business Process Model and Notation)
- **BPEL** (Business Process Execution Language)

<!-- BELİRSİZ: Hocanın yazdığı an kareye düşmedi; altyazıda kısaltmalar "BPMN" ve "BPL, Windows Process Execution Language" diye geçiyor. Bağlamdan BPEL (Business Process Execution Language) olduğu anlaşılıyor. -->

Bir CASE aracının bu standartları desteklemesi beklenir. Kendine özgü bir yöntem de kullanabilir, ama hoca bunu tercih etmemeyi önerdi: yaygın standartlarla çalışıldıkça belirli bir sisteme mahkûm kalma riski azalır. Bu önemli bir karar ölçütü olmalıdır.

Orta CASE bölümü üst bölümden aldığı girdiyi kullanan sistem analizi ve tasarım gereçlerine sahiptir. Alt CASE bölümünde üst ve orta bölümlerden gelen girdiler çalıştırılabilir koda dökülür (kod çevirme).

Üç bölüm de ansiklopedik arşivden yararlanır. Arşiv şemada silindirle gösterilmiş. Klasik gösterimde silindir bir veri deposunu (dosya, veritabanı vb.) simgeler. Arşivin içeriği:

- **Fonksiyonlar:** Temel işlemler. Şemalar üzerinden yapılan tasarımlar koda döküldüğünde tek kullanımlık değildir, arşive kaydedilir. Hazır gelen fonksiyonlara zamanla yenileri eklendikçe geniş bir fonksiyon arşivi oluşur.
- **İşlevler:** Biraz daha üst düzey sorumluluklar, birkaç fonksiyonun bir araya gelmesi gibi düşünülebilir.
- **Veri sözlüğü:** Farklı problem alanlarındaki varlıkların ve bileşenlerin tanımlandığı, açıklandığı bileşen.
- **Veri modelleri:** Verinin hangi yapılarda saklanacağını simgeler. Özünde veri yapıları olarak düşünülebilir. Veri farklı biçimlerde organize edilebilir, her biçimin artısı ve eksisi vardır. Sistemin ihtiyaçlarına ve en sık kullanımına uygun yapı seçilmelidir, çünkü verinin organizasyonu problemin verimli çözümü için büyük önem taşır.

Orta ve alt bölümlerdeki ölçüm, belgelendirme ve hata ayıklama gereçleri olabildiğince otomatik çalışır. Bir tasarımdan hesaplanabilecek ölçütler (metrikler) otomatik toplanır, raporlanır, izlenir, değerlendirilir ve iyileştirme önerileri üretilir. Yazılım ölçütleri dersin son haftalarında görülecek. Sınama gereçleri de bu bölümlerde, belirlenen parametrelere göre sürekli çalışır.

### 7.4 CASE bugün

Hocaya göre CASE sistemleri yurt dışında daha fazla rağbet gördü. Türkiye'de CASE araçlarıyla çalışan yazılım evleri yaygın değil. CASE bir süre popüler oldu, ama bu yaygınlık kalıcı olmadı. Hocanın yorumu: hedef aşırı yüksek ve gerçekçi değildi, işlerin tamamen otomatik yapılması mümkün olmuyor.

Bugün CASE yerine, bu derste görülecek teknik belgelendirme ve uygulama etkinliklerinin tek bir bütünleşik ortamda yapılabildiği takım odaklı yazılım geliştirme sistemleri yaygın olarak kullanılıyor:

- Microsoft'un ortamı: adı zaman içinde Team Server, Team System, Team Foundation Server oldu, bugün Azure DevOps (.NET platformu için).
- IBM Rational (Java platformu için).

Hoca CASE sistemlerini öğrenip denemek yerine bu sistemleri tanıyıp öğrenmenin geleceğiniz için daha doğru bir yatırım olacağını önerdi. Ama bütün bunların kökünün CASE teknolojisine dayandığını bilmek gerekir.

## 8. Dördüncü Kuşak Teknikleri

Slayt (ekrandan, 02:05:00):

- 4. Kuşak diller (4th Generation Language: 4GL) olarak tanımlanan diller kullanılarak, grafik arayüzler üzerinden yazılımın kaynak kodunun değiştirilebilmesini sağlayan gereçlerin (4GT) kullanıldığı tekniklerdir.
- 4GL diller doğal dile yakın dillerdir. 4GT gereçler komutları yerine getirebilecek bir gösterim üzerinden (şemalar, akış diyagramları gibi) kaynak kod üretebilmektedir.
- Şema ile kod arasında çift yönlü dönüşüm söz konusudur.
- Programlama bilmesi gerekmeyen konu uzmanlarının ve üst yöneticilerin kolaylıkla yazılıma müdahale edebilmesi avantajını vaat etmektedir.
  - Yine de algoritmik düşünme yeteneği olmadan kullanılamazlar.
- Bu araçlar günümüzde sadece bazı özel alanlarda ve sınırlı olarak kullanılabilmektedir.

### 8.1 Dil kuşakları

- **1. kuşak:** Sıfır ve birlerle kodlanan makine dili.
- **2. kuşak:** Bu sıfır ve birlerin üç harfli sembollerle ifade edildiği assembly dili.
- **3. kuşak:** BASIC, Pascal, Fortran ile başlayıp C, C++, Java ve benzerleriyle devam eden diller.
- **4. kuşak:** İlk üç kuşak dilleri kullanmak yerine kısmen grafiksel şemalarla, kısmen sürükle bırak teknikleriyle, kısmen bileşenleri birbirine bağlayarak, kısmen de doğal dile ya da problem alanına yakın bir söz dizimiyle yazılım geliştirmeyi sağlayan diller. Belirli bir platform üzerinde çalışan, belirli bir ihtiyaca yönelik kapsamlı projeler oluşturmayı hedefler.

4GL dilleriyle çalışılan geliştirme ortamlarına 4th Generation Tools (4GT) denir. Hoca 4GT'yi, geniş kapsamlı CASE yaklaşımının çok daha dar ve odaklanmış bir sürümü olarak düşünmeyi önerdi.

### 8.2 Örnekler

- **SQL:** SQL bildirimleri bir 4. kuşak örneğidir. Bir ilişkisel veritabanı sisteminde SQL komutları ve saklı yordamlar (stored procedure) kullanılarak baştan sona bir uygulama yazılabilir.
- **Büyük platform sahibi yazılım evleri:** Oracle ve SAP gibi firmaların ürünlerini özelleştirmek ve üzerlerinde proje geliştirmek için kendilerine özel, kapalı 4. kuşak dilleri ve gereçleri vardır. Özellikle ERP (kurumsal kaynak planlama) sistemlerinde mevcut programlar bu dillerle değiştirilebilir ya da yenileri yazılabilir.

Şemalar ve akış diyagramlarıyla kod arasında çift yönlü dönüşüm vardır: şemada yapılan değişiklik kodu, dolayısıyla sistemin çalışmasını değiştirir. Kodda yapılan değişiklik de ilgili şemalara otomatik yansır. Bu, teknik belgelendirmeyi özellikle kolaylaştırır.

Hocanın değerlendirmesi: Programlama bilmeyen konu uzmanları bile algoritmik düşünme yeteneği olmadan bu gereçleri kullanamaz. Ama konu uzmanları kendi alanlarındaki süreçleri iyi bildikleri için bu gereçlere genelde hızlı alışır, algoritmik düşünmeye yatkınlarsa daha da başarılı olur. Bu teknikler genel amaçlı yazılım geliştirmede değil, ERP gibi özel uygulama alanlarında kullanılır. SQL bu bağlamda en yoğun ve yaygın kullanılan örnektir.

## 9. Yazılım Geliştirme Süreç Modellerine Giriş

Bu bölüm yeni bir slayt grubuyla başlıyor (ekrandan, 02:25:00: "Yazılım Geliştirme Süreç(Model)leri").

Yazılım geliştirme bir süreç olarak ele alınır. Süreç, önceden belirlenmiş adımlardan oluşan iş akışıdır. Yazılım geliştirme süreç modeli de yazılım geliştirme sürecinin yapısını ve adımlarını belirler. Önceden iyi planlanmış bir süreç kullanmak ürünün zamanında ve kaliteli elde edilmesini sağlar.

Literatürde çok farklı modeller önerilmiştir, her birinin kendine özgü artıları ve eksileri vardır. Bazıları kullanımdan düşmüş, ama güçlü noktaları kullanımda kalan modellere eklenmiştir. Bu modelleri bilmek gerekir, çünkü yürütülecek projeye en uygun modeli, artı ve eksileri değerlendirerek seçmek mühendisin sorumluluğudur. Artık kullanılmayan modellerin hangi güçlü yanlarının başka modellere aktarıldığını bilmek de yararlıdır.

## 10. Şelale Modeli

Slayt (ekrandan, 02:30:00):

- Ardışıl Model / Şelale Modeli (Sequential / Waterfall)
  - Adımlar: Çözümleme → Tasarım → Kodlama → Sınama → Bakım.
  - Bir adımın tamamlanmasından sonra diğerine geçilir.
  - Eksiklikler veya hatalar fark edilirse bir önceki adıma geçilir.
- Artılar:
  - En eski model, yaygın kullanımda.
  - İyi tanımlanmış adımlar.
- Eksiler:
  - Son ürünün eldesi uzun süreceğinden müşteri sabırlı olmalıdır.
  - Adımları geride bıraktıkça, ilerleyen aşamalarda karşılaşılan hataların düzeltilmesi üstel olarak zorlaşmaktadır.
  - Bir çok 'müşteri' de gereksinimleri eksiksiz ve kesin belirtmekte zorlanmaktadır.
- Sonuç: Hiç model kullanmamaktan iyidir!
  - Önceden bir çok kez başarıya ulaştırılmış projelere benzer yeni projelerin yürütülmesi için kullanılabilir (rutin projeler).

### 10.1 İşleyiş

Şelale modeline ardışıl (sequential) model ya da klasik model de denir. Literatürde önerilen ilk ve en eski modeldir. Adımlarının sırası tesadüf değildir: bir önceki ders saatinde görülen genel geliştirme etkinliklerinin bu sırayla yürütülmesidir.

Bir adım tamamen bitmeden diğerine geçilmez. Belli bir anda proje yalnız tek bir aşamadadır ve yalnız o aşamanın işleri yapılır. Ya bütün ekip o işi yapar ya da yalnız o aşamada uzman olanlar çalışır. Diğer çalışanlar boş durmaz. Örneğin çözümleme sürerken sınama hazırlığı yapabilir ya da en azından çözümleme çalışmalarını izlerler. Bu önemlidir, çünkü tasarım çözümleme çıktılarının üzerine kurulacaktır ve bu çıktıların hangi kararlarla oluştuğunu bilmek gerekir. Aksi halde tasarım ekibi önce çözümlemeye hakim olmak için ek çaba harcar ve süre uzar.

Hata durumunda bir önceki adıma dönülür. Örneğin tasarım belli bir yere gelmişken çözümlemeden kaynaklanan bir hata bulunursa tasarım etkinlikleri tamamen durdurulur, çözümleme aşamasına dönülür. Hata düzeltilir, diğer çözümleme bileşenlerine olası etkileri değerlendirilir ve giderilir, sonra tasarıma geri dönülür. Kodlamada bir hata bulunursa ve bu yazılımcının hatası değil de tasarımdan kaynaklanıyorsa tasarıma dönülür. Tasarımdaki hatanın nedeni de çözümlemeye dayanıyorsa oradan çözümlemeye dönülür.

### 10.2 Artılar

En eski model olduğu için hem yaygın kullanımdadır hem de hangi adımda ne yapılacağı çok iyi belirlenmiş, tanımlanmış ve belgelenmiştir. Modelin püf noktalarını anlatan pek çok kaynağa kolayca erişilebilir. Her adımın açık ve net çizgilerle tanımlanmış olması, işin belirsizliğe ve soru işaretine yol açmadan yürütülmesini sağlar.

### 10.3 Eksiler

Hocaya göre bu eksiler olmasaydı kullanılan tek süreç bu olurdu.

- **Son ürün geç elde edilir:** Müşterinin ürünü denemeye ve geri bildirim vermeye başlayabileceği an ancak kodlama aşamasının ortasından sonrasına, çoğu zaman kodlamanın neredeyse tamamen bitmesine denk gelir. Geri dönüşler ve belli bir anda yalnız tek bir adımda olmak, çalışabilir bir şeyin ortaya çıkmasını geciktirir.
- **Üstel maliyet:** Adımlar geride bırakıldıkça ilerleyen aşamalarda karşılaşılan hataların düzeltilmesi üstel olarak zorlaşır.
- **Eksik gereksinimler:** Müşterilerin çoğu gereksinimlerini eksiksiz ve kesin belirtmekte zorlanır (gereksinim mühendisliği konusunda ayrıntılı görülecek). Eksikler müşteri tarafından ancak kodlamanın sonlarına doğru ya da sınamanın başında fark edilir. Müşteriden daha erken geri bildirim alınabilse bu sorunların çözümü çok daha kolay olurdu, ama bu çalışma biçimi geri bildirimi geç vakitlere iter.

### 10.4 Sonuç

Hiç model kullanmamaktan elbette iyidir. Önceden kazanılmış başarıları tekrarlamak, yani rutin projeler için uygun bir modeldir: işi daha önce yapmışsınızdır, olası sorunları ve çözümlerini bilirsiniz. Bu durumda ayrıntılı ve iyi tanımlanmış şelale modeli başarı şansını yükseltir. İlk kez çalışılan bir problem alanında, araştırma ağırlıklı bir Ar-Ge projesinde ya da yepyeni bir ürün çıkarılmaya çalışılırken ise modelin ağır işleyişi genelde başarısızlığa yol açar. Önceki saatte görülen grafikte de klasik modelin net başarı oranı yaklaşık %50 idi, çevik süreçlerden düşüktü.

## 11. Ön Ürün (Prototip) Modeli

Slayt (ekrandan, 02:40:00):

- Ön ürün modeli / Prototip modeli
  - Adımlar: Müşteriyi dinle – Ön ürün oluştur – Müşteri ön ürünü dener, sonra ok yeniden "Ön ürün oluştur" adımına döner.
- Artılar:
  - Kullanıcı gereksinimlerinin daha iyi elde edilmesi.
  - Kullanıcının erkenden ürünü değerlendirmeye başlayabilmesi.
- Eksiler:
  - Ön ürün mükemmel değildir.
  - Eksik ürün zaman ve maliyet kısıtlamaları nedeniyle olgunlaşmadan canlı kullanıma alınabilmektedir.
- Sonuç: Prototip oluşturmayı başlı başına bir model olarak kullanmamalı, daha olgun bir modelin analiz aşamasında kullanılacak bir araç olarak ele almalı ve prototip ürünü silip atmalı.

### 11.1 İşleyiş

Bu model şelalenin "çalışan ürün geç elde edilir" sorununa odaklanır. İngilizcesi *prototyping*. Adımlar:

1. Müşteri dinlenir, ne istediği ve nasıl istediği anlaşılmaya çalışılır.
2. Dinlenenlerden yola çıkılarak bir ön ürün oluşturulur.
3. Müşteri ön ürünü dener.
4. Müşteri yeniden dinlenir: ön üründe neyin iyi, doğru, eksik ya da yanlış olduğu öğrenilir.
5. Bu bilgilere göre ön ürün düzeltilir ya da geliştirilir, müşteri yeniden dener.

Döngü, müşteri ürünü yeterli bulup "kullanıma alırım" diyene kadar sürer.

### 11.2 Artılar ve eksiler

En önemli artı, kullanıcı gereksinimlerinin daha iyi elde edilmesidir. Kullanıcı ürünü erkenden değerlendirmeye başlar. Neye ihtiyacı olup olmadığını, neyin doğru, eksik ya da yanlış olduğunu daha net görür ve bunu projenin olabilecek en erken zamanında söyler. Bu yüzden düzeltme de daha kolay ve verimlidir.

İki önemli eksi vardır. Ön ürün nihai ürün değildir, ama çoğu zaman öyle kalabilir. Zaman ya da maliyet baskısında müşteri "bu da idare eder" diyebilir ve yeterince olgunlaşmamış ürün sahada kullanılmaya başlanır. Bu, yazılımın düzeltmenin çok daha zor olduğu bakım aşamasına geçmesi demektir. Bu yüzden modele alaycı ve eleştirel biçimde **build and fix** (yap ve düzelt) modeli de denir: yap, dinle, düzelt, yap, dinle, düzelt.

### 11.3 Doğru kullanım

Prototipi başlı başına bir yazılım geliştirme modeli olarak kullanmak doğru değildir. Şelale, ileride görülecek çevik süreçler ya da başka bir modelin analiz aşamasında gereksinim belirleme aracı olarak kullanılmalıdır.

> **Hocanın vurgusu:** Prototip ürünün kaynak kodu silinip atılmalıdır. Silinmezse prototip kodunun üzerine geliştirmeye devam etme olasılığı yükselir ve çalışma biçimi yeniden "build and fix"e döner.

Hocanın önerisi, prototipi nihai ürünün kodlanacağı dil ya da platformdan farklı bir dil ya da platformda yazmaktır. Örnek: Proje Java ile yazılacak olsun. Java'da grafik kullanıcı arayüzü yapmak, özellikle geleneksel Swing kütüphanesiyle ek araç kullanmadan, hızlı ve verimli değildir. Prototip .NET ile sürükle bırak yöntemiyle ve "şuna tıklanınca şu olsun" türünden kod bloklarıyla hızlıca hazırlanır. Müşteri ekran akışlarını, veri akışlarını ve iş akışlarını dener. Asıl kodlama Java ile sürdürülür. Prototip farklı bir platformda yazıldığı için nihai ürünün parçası olamaz.

## 12. Hızlı Uygulama Geliştirme (RAD)

Slayt (ekrandan, 02:45:00):

- Kısa geliştirme çevrimleri üzerinde duran artımsal bir model.
- Ön koşullar:
  - Uygulamanın yaklaşık/ortalama 3 aylık bölümlere ayrılabilmesi,
  - Yeterli sayıda bölümün eşzamanlı ilerlemesinin sağlanabilmesi,
  - Yazılımın bileşenlerden kurulabilmesi.
- Artılar:
  - Bu sürece uygun yazılım projelerinde verimliliğin artması.
- Eksiler:
  - Büyük ölçekli çalışmalarda yeterli sayıda bölümü eşzamanlı ilerletebilecek sayıda çalışanın bulunamaması.
  - Çalışanlar hıza uyum sağlayabilmelidirler.
  - Yüksek teknik risklere uygun değil.
- Sonuç:
  - Prototip geliştirmede kullanılması veya ana fikirlerinin diğer süreçlere uygulanması yerinde olacaktır.

### 12.1 İşleyiş ve ön koşullar

RAD (Rapid Application Development) kısa geliştirme çevrimlerine odaklanan artımsal bir modeldir: sürekli küçük yeni parçalar ekleyerek ilerler. Kullanılabilmesi için planlanan yazılımın yaklaşık 3 aylık alt bölümlere ayrılabilmesi gerekir. Bu bölümler birbirine olabildiğince az bağımlı olmalıdır (tam bağımsızlık olmaz) ki paralel yürütülebilsin. Ekip de her paralel bölümde analiz, tasarım ve kodlama yapacak kadar geniş olmalıdır. Böylece ürün şelale ya da prototip modeline göre çok daha kısa sürede ortaya çıkar.

> **Hocanın vurgusu:** RAD bir süreçtir, ürün değildir. 1990'larda ve 2000'lerde Microsoft Visual Basic, Borland Delphi ve C++ Builder gibi ürünler "hızlı uygulama geliştirme aracı" diye pazarlandı. Bu araçlarda bir paletten bileşen seçip sürükle bırak yapılır, bileşene tıklanınca hangi kodun çalışacağı yazılır, bir grid bileşeni bir tabloyla eşleştirilir. Bu hızlı kod yazmaktır, RAD süreci değildir. RAD sürecinin getirdiği hızlı tempoya uymak için bu araçlar elbette kullanılabilir, ama "RAD" denince süreç mi araç mı kastedildiğini iyi ayırt etmek gerekir.

### 12.2 Hocanın sayısal örneği

Hoca ideal durum ile gerçek durumu karşılaştırdı:

- **Verilen:** Sıralı yapılsa 12 ay sürecek bir iş, 3'er aylık 4 bölüme ayrılıyor.
- **İdeal (teori):** Dört bölüm paralel yürürse iş $12/4 = 3$ ayda biter, yani sürenin dörtte biri kadar. Ne kadar çok bölüme ayrılabilirse o kadar hızlanır.
- **Gerçekte:** Problemler genelde böyle bölümlere ayrılamaz. Ayrılsa bile parçalar ara adımlarda birbirine o kadar bağımlıdır ki kazanç çok daha mütevazı kalır. Hoca kazancı "ben diyeyim %10, siz deyin %15, en fazla %20" diye verdi: 12 ay yerine en iyi durumda 10 ya da 9 ay.

> **Ders sonrası not:** Python ile kontrol: 12 ayda %10 kazanç 10,8 ay, %15 kazanç 10,2 ay, %20 kazanç 9,6 ay eder. Hocanın söylediği "9 ay" büyük olasılıkla yuvarlamadır, tam 9 ay %25 kazanca karşılık gelir.

### 12.3 Eksiler

- **İnsan kaynağı:** Paralel alt problemler üzerinde çalıştırılacak kadar çalışan olmayabilir, çoğu zaman kısıtlayıcı etken budur.
- **Tempo:** Modelin hızlı çalışma biçimine her insan uyum sağlayamayabilir.
- **Yüksek teknik risk:** İşi bağımsız parçalara bölebildiniz ve yeterli çalışanınız da var diyelim. Bir parçada çözülmesi mümkün olmayan ya da ancak aşırı çabayla, uygulanabilir (feasible) olmayan bir sürede çözülebilen bir sorunla karşılaşırsınız. Diğer üç parça tamamlanmış olsa da anlamlı bir ürün için dördüne birden ihtiyaç vardır. Proje zamanında kullanıma alınamaz ya da satılamaz, pazarı rakiplere kaptırırsınız. Bu bir pazar başarısızlığıdır. Biten parçalar başka uygulamalarda yeniden kullanılabilirse çabanın bir kısmı kurtarılır, ama yine de hatırı sayılır bir çaba boşa gider.

### 12.4 Sonuç

RAD prototip geliştirmede kullanılabilir, çünkü orada ortaya çıkan ürün zaten tam ve eksiksiz çalışması beklenmeyen bir ön üründür. Ya da ana fikirleri başka süreçlere uyarlanabilir. Hoca 3 aylık bölümlerin bile büyük bir lokma olduğunu, işin çok daha küçük lokmalara ayrıldığı çevik süreçlerin sonraki derste görüleceğini söyledi.

RAD'de yazılımın bir kısmının hazır bileşenlerden kurulabilmesi de önemlidir. Benzer problemlerde kullanılmış kod parçaları kütüphaneden eklenip include ya da import edilmek yerine, kara kutu (black box) yaklaşımıyla, belirli girdilere belirli çıktılar üreten ve değiştirilmeden doğrudan kullanılabilen bileşenler (component) olarak kullanılabiliyorsa işi kolaylaştırır. Bileşenlerle bütün süreci yönetmeyi ele alan bileşen tabanlı modeller bir sonraki derste görülecek.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:33:00): Bir kurum finansal zorluklarla karşılaşmaya başladığında tasarruf tedbiri olarak ilk önce nereden kısar?

> **Cevap (derste verildi):** Bilgi işlem (IT) departmanından ve yazılım projelerinden. Projeler ya hiç başlatılmaz ya da ilk aşamalardaysa sonlandırılır. Ortaya çıkan fazla personel de işten çıkarılır. Öte yandan aynı işi daha verimli ve ucuza yapmayı sağlayan yazılımlar üreten firmalar bu dönemde avantaj kazanır.

**Soru 2** (ekrandan, 01:00:00): Türkiye'de çevik projelerin başarı oranları anketinde yanıt sayıları şöyledir: %10'dan az: 2, %10-%25: 4, %26-%50: 5, %50-%75: 13, %76-%100: 11. Kaç yanıt toplanmıştır? %75 ve üstü başarı oranı bildiren yanıtların payı nedir? "Esnetilmiş başarı" %50 ve üstü kabul edilirse oran nedir?

> **Cevap (derste verildi, python ile kontrol edildi):** Toplam $2+4+5+13+11=35$ yanıt. %75 ve üstü: $11/35 \approx \%31$. %50 ve üstü: $(13+11)/35 = 24/35 \approx \%68{,}6$ (slaytta $\%37+\%31=\%68$).

**Soru 3** (derste sözlü, 01:00:28): Yazılım süreçleri 1960'lardaki yazılım krizinden beri çalışılıyorsa, başarı oranı neden hâlâ yaklaşık %50 dolaylarındadır?

> **Cevap (derste verildi):** Çünkü bilgi sistemleriyle giderek daha zor ve büyük ölçekli problemler çözülmeye çalışılıyor. Hedef sabit kalmıyor, istekler sürekli yükseliyor. Yazılım mühendisliği ilerliyor, ama çözülen problemler de büyüyor.

**Soru 4** (derste sözlü, 02:41:06): Prototip modelinde oluşturulan ön ürünün kaynak kodu neden silinip atılmalıdır?

> **Cevap (derste verildi):** Ön ürün nihai ürün değildir. Silinmezse onun üzerine geliştirmeye devam etme olasılığı yükselir ve çalışma biçimi "build and fix" modeline döner. Bu riski tamamen kaldırmak için prototip nihai üründen farklı bir dil ya da platformda yazılabilir.

**Soru 5** (derste sözlü, 02:47:57): 12 ay sürecek bir proje 3'er aylık 4 bölüme ayrılıp RAD ile paralel yürütülürse teoride ne kadar sürer? Gerçekte kazanç neden bu kadar büyük olmaz?

> **Cevap (derste verildi):** Teoride $12/4 = 3$ ay. Gerçekte problemler bağımsız parçalara ayrılamaz, parçalar arası bağımlılıklar kazancı yaklaşık %10-20'ye düşürür (12 ay yerine yaklaşık 10 ya da 9 ay). Ayrıca paralel bölümlerde çalışacak yeterli insan kaynağı bulunmayabilir.

## Dersin Toparlaması

Bu derste yazılım mühendisliğine giriş bölümü tamamlandı. Yazılımı etkileyen eğilimler (yaygınlaşan bilgi işlem ve haberleşme, açık kaynak, takım çalışması, küreselleşme, ekonomik krizler) ve müşteri, programcı ve yönetim açısından yazılım hakkındaki yanılgılar ele alındı. Bütün yanılgıların arkasındaki temel dinamik, değişiklik ve hata düzeltme maliyetinin yaşam döngüsünde ilerledikçe üstel olarak artmasıdır. Yazılım oyun hamuru gibi değil, kil ya da cam gibi esnektir. Çabanın yarıdan fazlası bakımda harcanır ve geciken projeye eleman eklemek gecikmeyi artırır. Uluslararası ve yerel anketler projelerin yaklaşık yarısının tam başarıya ulaşamadığını, çevik süreçlerin ise daha başarılı olduğunu gösteriyor.

Ardından süreçlerin ortak beş adımı (çözümleme, tasarım, gerçekleme, sınama, bakım), yeniden mühendislik, CASE sistemlerinin yapısı ve dördüncü kuşak teknikleri görüldü. Son bölümde süreç modellerine giriş yapıldı: şelale modeli rutin projelere uygundur, prototip modeli bir analiz aracı olarak kullanılmalıdır, RAD ise ancak bağımsız parçalara ayrılabilen ve teknik riski düşük projelere uygundur. Sonraki derste bileşen tabanlı modellerle devam edilecek, ardından çevik süreçlere geçilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
