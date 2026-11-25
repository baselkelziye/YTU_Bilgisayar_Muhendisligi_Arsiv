# Ders 10 Genişletilmiş Notu: Makale Sunumları: Artırımlı Varlık Oluşturma Süreç Modeli, Küresel Yazılım Geliştirmede Genişletilmiş COCOMO II ve Çevik Pratiklerle Proje Yönetimi Karşıt Paternleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

Bu derste öğrenci makale sunumları başladı. Üç öğrenci yazılım proje yönetimiyle ilgili birer makale anlattı. Hoca sunumların arasında sınıfa sorular sordu, iş hayatındaki deneyimlerle ilişkilendirerek yorum istedi ve kısa değerlendirmeler yaptı. Aşağıda sunumlar ders sırasıyla verilmiştir. Sunum yapanlar "bir öğrenci" diye anılır.

## İçindekiler

- 1. Yazılım proje yönetimi için artırımlı varlık oluşturma süreç modeli
- 2. Sınıf tartışması: proje başarısı ve yeniden kullanım
- 3. Küresel yazılım geliştirmede genişletilmiş COCOMO II tabanlı maliyet tahmin modeli
- 4. Çevik pratikler ve yazılım proje yönetimi karşıt paternleri
- Örnek Sorular

## 1. Yazılım Proje Yönetimi için Artırımlı Varlık Oluşturma Süreç Modeli

İlk sunumda "A New Process Model of Incremental Asset Building for Software Project Management" başlıklı makale anlatıldı (ekrandan, 00:05:00). Sunum özet, giriş, araştırılabilir sorunlar, önerilen yöntem ve sonuç başlıklarından oluşuyordu.

### 1.1 Problem: neden yazılım firmaları kâr edemiyor?

Yazılım endüstrisi hızla büyüyen bir alandır ve yazılım uygulamalarına talep her geçen gün artmaktadır. Ancak makaleye göre bu sektörde hayatta kalmak, yani gelirin maliyetin üzerinde kalması kolay değildir. Slayttaki ifadeyle yazılım işi büyüdüğü halde yazılım işinin başarı oranı çok düşüktür ve insanlar yazılıma yaptıkları yüksek harcamalar nedeniyle kâr edemezler (ekrandan, 00:05:00).

Makale bu başarısızlığın ana nedenini, özelleştirilmiş yazılımların geliştirildiği geleneksel yazılım proje yönetiminin takip edilmesi olarak gösterir:

- Her müşteri için baştan özel yazılım geliştirmek gereksiz ek zaman ve kaynak harcar.
- Yeniden kullanılabilir yazılım bileşenleri azdır; daha az özelleştirmeyle yeniden kullanılabilir bileşenler oluşturulsaydı yazılım daha az zaman ve kaynakla geliştirilebilir, iş büyüyebilirdi.
- Özelleştirilmiş yazılımın toplam harcamasının tek bir müşteriye faturalanması mantıksızdır.
- Her müşteri için benzer projeleri baştan oluşturmak pahalıdır ve proje yönetiminin eksiklikleriyle birlikte başarısızlığa ve endüstriyel sürdürülebilirliğin kaybına yol açan bir zaman ve kaynak israfıdır.

Araştırılabilir sorunlar başlığında bu durum özetlendi: tek müşteriye yapılan özel projeler maliyeti çok yükseltir, yeniden kullanım fırsatını azaltır ve kâr sıfıra yaklaşır. Bu da yazılım firmalarının sürdürülebilirliğini tehdit eden temel endişedir.

### 1.2 Önerilen yaklaşım: artırımlı varlık modeli

Makale, tipik yazılım proje yönetimi yerine takip edilecek yeni bir süreç modeli önerir ve buna artırımlı varlık modeli adını verir (ekrandan, 00:20:00). Model, hedeflenen pazar segmentine dayalı olarak temel ve yeniden kullanılabilir yazılım bileşenleri oluşturur ve yazılım geliştirilirken bu bileşenleri entegre eder. Böylece yazılım en az özelleştirmeyle oluşturulur ve şirketler kaynaklarını korur. Toplam maliyet tek bir müşteri yerine benzer ihtiyaçları olan birçok müşteri arasında dağıtılır, müşteri başına ortalama maliyet düşer.

Modelin genel bakışı üç kavramla verilir (ekrandan, 00:10:00):

- **Market analizi:** Belirli bir pazarın özelliklerini belirleme, bilgileri analiz etme, projenin kapsamını tanımlama ve yeniden kullanılabilir bileşenleri oluşturma süreci.
- **Proje seçimi:** Hedeflenen pazar segmentine göre belirli bir etki alanı (domain) tabanlı proje seçme süreci.
- **Yeniden kullanılabilir bileşenler:** Yeniden kullanılabilir bileşenler geliştirme ve ürünü sonraki ve gelecekteki projelerde kullanmak üzere geliştirmek için kademeli olarak daha fazla bileşen ekleme süreci.

### 1.3 Süreç diyagramı

Model, sorumlulukları ayrı kulvarlarda gösteren bir süreç diyagramıyla verilmiştir. Kulvarlar pazar analisti, yönetici direktör (manager director), proje yöneticisi ve testçidir. Akış şöyledir:

```text
Pazar analisti : pazar analizi yap -> hedef pazarı seç
Direktör       : analiz raporuna göre proje seç
Proje yöneticisi: projenin temel bileşenlerini kontrol et
                  - bileşen mevcut mu?
                      evet -> doğrudan projeye entegre et
                      hayır -> yeniden kullanılabilir bileşen geliştir -> projeye entegre et
Testçi         : kaliteyi sağlamak için projeyi test et -> müşteriye teslim et
```

Hoca bu noktada araya girip sınıfa diyagramın hangi UML diyagramına benzediğini sordu. Cevap aktivite diyagramıydı: her aktörün (pazar analisti, direktör, proje yöneticisi, testçi) yaptığı işler ayrı bölümlerde gösterilir. Nesneye yönelik yazılım geliştirmede kullanılan aktivite diyagramında da aynı gösterim kullanılır.

> **Ek bilgi (derste anlatılmadı):** UML aktivite diyagramında sorumlulukları aktörlere göre ayıran dikey ya da yatay bölmelere "swimlane" (kulvar) ya da "partition" denir. İş süreçlerinin kimin tarafından yürütüldüğünü göstermek için sık kullanılır.

### 1.4 Aşamaların girdi, aktivite, çıktı ve eserleri

Makalede diyagramdaki her sütun için girdi, aktiviteler, çıktı ve eserler (artifact) bir tabloyla verilmiştir. Sunumda anlatılan haliyle:

- **Pazar analizi:** Girdi pazar bilgileri ve bilgi toplama teknikleridir. Aktiviteler hedef pazarı analiz etmek, konuyu tanımlamak ve uygun pazar segmentini seçmektir. Çıktı hedef pazar segmentidir. Eserler analiz raporu ve seçilen hedef pazara genel bakıştır.
- **Proje seçimi (direktör):** Girdi ilk aşamada oluşan analiz raporudur. Bu rapora göre uygun proje belirlenir, yeniden kullanılabilirlik kontrol edilir. Eserler karar verme kanıtları, proje seçim iletişimi ve proje genel bakışıdır.
- **Geliştirme (proje yöneticisi):** Girdi önceki iki aşamanın eserleridir. Aktiviteler proje kapsamını anlamak, proje bileşenlerini kontrol etmek, bileşen varsa projeye taşımak, yoksa oluşturmak, entegre etmek ve yeni projeyi test ederek güncellemektir. Eserler yeni/güncellenmiş kaynak kod ve birim test durumudur.
- **Entegrasyon ve teslim:** Girdi önceki aşamanın test durumudur. Son testlerden sonra proje teslim edilir; çıktı yeni sürüm ve sürüm notlarıdır.

<!-- BELİRSİZ: girdi-aktivite-çıktı-eser tablosu karelerde okunacak boyutta yok; içerik altyazıdaki anlatımdan aktarıldı. -->

### 1.5 Sonuç

Sonuç slaytına göre yazılım endüstrisinin evrimi şirket içi geliştirme ve yazılım projelerinin sözleşmeler olarak alınmasıyla başlamıştır (ekrandan, 00:15:00). Artık yenilik çağındayız: yeniden kullanılabilir bileşenlere sahip yenilikçi bir yazılım şirketi pazardaki varlığını sürdürebilir, çok az özelleştirmeyle aynı yazılımı birden fazla müşteriye sunabilir; böylece geliştirme maliyetleri ve yazılımın fiyatı düşer.

Bunu başarmak için pazar analizinin proje yönetimindeki ilk faaliyet olması, geliştirilecek yenilikçi yazılımın önce belirlenmesi ve proje yönetimindeki diğer faaliyetlerin ardından gelmesi önerilir. Makaleye göre yazılım şirketleri proje yönetimi stratejisinin ekonomik ölçek ve kapsamdan yararlanmaktan tamamen bağımsız olduğu için maliyeti düşürmede, kaliteyi iyileştirmede ve net kârı artırmada başarısız olmuştur; projeleri beklenen bütçe ve sürede teslim edememektedir. Artırımlı süreç modeli ve pazar analizi sayesinde proje yöneticisi yeniden kullanılabilir varlıklar oluşturma ve bunlardan yararlanma kapsamı hakkında vizyon edinebilir.

## 2. Sınıf Tartışması: Proje Başarısı ve Yeniden Kullanım

Sunumdan sonra hoca, yazılım projesi geliştiren ekiplerde çalışan öğrencilerden modeli kendi proje yönetim süreçleriyle ilişkilendirerek yorumlamalarını istedi.

### 2.1 "Yazılım projelerinin başarı oranı düşüktür" klişesi

Bir öğrenci, müşteriye özel yazılım sayısı arttıkça zaman ve maliyet açısından olumsuz bir duruma düşüldüğünü gözlemlediğini, ancak makaledeki "yazılım işinin başarı oranı çok düşüktür" cümlesine katılmadığını söyledi.

Hoca bu cümlenin yazılım proje yönetimi yazılarının başında hep kullanılan, alışılmış bir giriş olduğunu belirtti. Gartner raporlarında da böyle geçer. Başarısız proje denince ilk bakılan üç şey vardır:

- Proje zamanında bitti mi?
- Ayrılan kaynakla (maliyetle) bitti mi?
- İstenen kapsam tutturuldu mu?

Yazılım projelerinde sık sık ek süre istenmesi, ek maliyet gerekmesi ya da müşteriyle tam anlaşılamayıp kapsamın sonradan değiştirilmesi görüldüğü için "yazılım projeleri diğer projelere göre başarısızdır" demek bir klişe haline gelmiştir.

> **Hocanın vurgusu:** Bu belki eski yıllardan kalma bir alışkanlıktır; dünyadaki güncel durumu görmek için en son Gartner raporuna bakmak gerekir. Çevik süreç modelleri kullanıldıkça kapsam konusunda baştan anlaşmak kolaylaştı; bu yüzden son yıllarda başarı oranı artmış olabilir.

Öğrenci de pazar analiziyle önce hedef müşteri kitlesinin ortak ihtiyaçlarını belirleyip ortak bir yazılımla başlamanın, sonradan daha az özelleştirmeyle değişiklik yapmayı kolaylaştıracağını ekledi. Ancak firmanın büyüklüğü ve müşteri tiplerinin çeşitliliği arttıkça ortak bir çözüm kurmanın zorlaşabileceğini belirtti.

### 2.2 Genelleştirilmiş çözümün ekip içi faydası

Başka bir öğrenci, müşterilerin ihtiyaçlarına tek tek özel çözüm üretildiğinde benzer bir talep başka bir müşteriden geldiğinde işin baştan yapıldığını ve ayrı ayrı faturalandırıldığını anlattı. Genelleştirilmiş bir çözüm (örneğin ortak bir web servisi) baştan önerilseydi bu tekrarın önlenebileceğini söyledi. Ayrıca müşteriye özgü çözümlerde analiz kararlarının nasıl alındığı bilgisinin o işi yürüten kişide kaldığını, kişi ayrıldığında bu birikimin kaybolduğunu belirtti. Genelleştirme, herkesin her konuyu bilmesini sağladığı için hem yeniden kullanım hem ekip içi iletişim açısından faydalıdır; iş tek bir kişiye bağımlı kalmaz. Hoca bu yaklaşımın faydalı olduğunu onayladı.

## 3. Küresel Yazılım Geliştirmede Genişletilmiş COCOMO II Tabanlı Maliyet Tahmin Modeli

İkinci sunumun konusu "Küresel Yazılım Geliştirme Bağlamında Genişletilmiş COCOMO-II Tabanlı Maliyet Tahmin Modeli" idi (ekrandan, 00:25:00).

### 3.1 Küresel yazılım geliştirme ve projenin amacı

Küresel yazılım geliştirme (Global Software Development, GSD) projelerinin başarısı üç ölçütle değerlendirilir:

- **Kalite:** projenin gereksinimlere uygunluğu.
- **Zaman:** projedeki tarihler ve planın tutması.
- **Maliyet:** gereksinimleri karşılamak için harcanan para.

Çalışmanın amacı, GSD projelerinde mali faydalar, müşteri beklentileri, iş kalitesi ve zaman beklentisi gibi toplam maliyeti etkileyen yapıları ortaya koymak ve bunlara ek olarak kritik maliyet etkenlerini ekleyerek COCOMO II tabanlı yeni bir tahmin modeli geliştirmektir.

### 3.2 Araştırma yöntemi

Çalışmanın adımları şöyle sıralandı:

1. Genel literatür araştırması ve temel problemin belirlenmesi: GSD projelerindeki maliyet yüklerinin (cost overhead) bulunması.
2. Sistematik literatür taramasıyla maliyet etkenlerinin ve temel maliyet tahmin modelinin belirlenmesi. Elde edilen veriler sektörde doğrulanmış verilerdir.
3. Bu veriler üzerinde istatistiksel hesaplamalar.
4. Önerilen model: kritik maliyet etkenleriyle mevcut etkenlerin COCOMO II'ye eklenmesi.
5. Eklenen etkenler için yeni metriklerin hesaplanması ve formüle edilmesi, yeni bir COCOMO II tahmin denkleminin kurulması.
6. Modelin performans ölçümü (hata oranı) ve sektör uzmanlarınca anket yoluyla doğrulanması.

### 3.3 Maliyet tahmin modellerinin sınıflandırılması

Maliyet tahmin modelleri genel olarak algoritmik ve algoritmik olmayan diye ikiye ayrılır. Algoritmik modeller önceden atanmış parametre ve değerlerle matematiksel hesap yapar; COCOMO II bu gruptadır. Algoritmik olmayan modeller ise önceki projelerde elde edilen verilerden yararlanır: önceki bir projede hesaplanan değerler alınarak yeni projede kullanılır. Analoji, yapay sinir ağları, uzman yargısı, bulanık mantık, regresyon ve diğer makine öğrenmesi yöntemleri bu gruptadır.

Sunumda GSD'ye özgü maliyet tahmin modelleri bir ağaçla gösterildi (ekrandan, 00:30:00):

```text
GSD'ye özgü maliyet tahmin modelleri
├── Algoritmik
│   ├── SLIM tabanlı ........ GSD için SLIM modeli
│   └── COCOMO II tabanlı ... GSD için COCOMO II
│                             Offshoring için COCOMO II
│                             Cost Xpert modeli
├── Bileşik (composite)
│   └── COBRA tabanlı ....... Effort Overhead modeli
└── Diğer ................... Use case points
                              Analoji tabanlı
                              Makine öğrenmesi tabanlı
```

### 3.4 Önerilen modelin üç fazı

- **Faz 1:** GSD projelerindeki kritik maliyet etkenlerinin ve temel maliyet tahmin modelinin seçilmesi.
- **Faz 2:** COCOMO II'nin genişletilmesi; hesaplanacak metriklerin belirlenmesi ve formüle edilmesi, denklemin değiştirilmesi.
- **Faz 3:** Yeni COCOMO II denklemiyle tahmin yapılması ve hata oranlarının bulunması.

### 3.5 Faz 1: maliyet etkenlerinin kategorileri

Maliyet etkenleri kategorize edilip tahmin bu kategoriler üzerinden yapılır. Dört kategori vardır:

- **İnsanlarla ilgili etkenler:** kişilerin özellikleri, müşterinin projeye katılımı, ekibin iş yapma potansiyeli (bir işi ne kadar sürede yapabileceği) ve ekip içi güven (team trust).
- **Projeyle ilgili etkenler:** projenin genel başarısı; müşteri ihtiyaçlarının ne ölçüde anlaşılıp karşılandığı. Gereksinimlerin doğru anlaşılması önemli bir etkendir.
- **Dış kaynakla ilgili etkenler:** farklı ülkelerde aynı projede çalışan kişiler arasındaki zaman farkı, coğrafi farklılıklar ve dil farklılıkları maliyeti etkiler.
- **Süreçle ilgili etkenler:** süreç geliştirme metodolojileri; süreç modeli, süreç olgunluğu, süreç uyumu ve iletişim süreçleri.

### 3.6 Faz 2: metrik formülasyonu

Faz 2 iki adımdan oluşur: metrik formülasyonu ve denklem değişikliği. Metrik formülasyonuna örnek olarak müşteri katılımı etkeni gösterildi. Müşteri katılımı, müşteriyle yapılan oturum/toplantı sayısıyla ölçülür (ekrandan, 00:35:00):

| Kategori | Ölçüt (müşteriyle oturum/toplantı sayısı) | Değer |
|---|---|---|
| Low (düşük) | Ayda 2'den az | 1.25 |
| Medium (orta) | Ayda 2-4 | 1.10 |
| High (yüksek) | Ayda 4'ten fazla | 1.00 |

Müşteriyle görüşme sayısı arttıkça katılım artar ve çarpan nominal değer olan 1.00'a iner. Görüşme azaldıkça çarpan büyür; yani müşteri katılımının düşük olması tahmini eforu artırır. Örneğin düşük katılımda çarpan 1.25 olduğundan, diğer her şey aynı kalırsa tahmini efor yüksek katılıma göre %25 fazladır.

### 3.7 Faz 2: denklem değişikliği

Önce COCOMO II'nin temel denklemi anlatıldı:

$$PM = A \times Size^{E} \times \prod_{i=1}^{n} EM_i$$

- $A$, COCOMO II için belirlenmiş bir sabittir; sunumda 2.94 olarak verildi ve geçmiş proje verilerine göre ayarlandığı söylendi.
- $E$ ölçek üssüdür; beş ölçek faktörüne bağlıdır: öncelik/benzer proje deneyimi (precedentedness), geliştirme esnekliği, risk çözümü (mimari/risk giderme), ekip uyumu ve süreç olgunluğu.
- $EM_i$ efor çarpanlarıdır (maliyet etkenleri). Projenin maliyetini doğrudan ya da dolaylı etkileyen özelliklerdir; düşükten yükseğe sayısal değerlerle derecelendirilir ve çarpım olarak denkleme girer.
- Denklemin sonucu projenin eforudur.

<!-- BELİRSİZ: denklem slaytı karelerde yok; denklem altyazıdaki anlatıma ve standart COCOMO II biçimine göre yazıldı. -->

> **Ek bilgi (derste anlatılmadı):** COCOMO II.2000 sürümünde büyük olasılıkla $A = 2.94$ ve $E = B + 0.01 \sum_{j=1}^{5} SF_j$ ($B = 0.91$) kullanılır; $Size$ bin satır kod (KSLOC) cinsindendir ve $PM$ kişi-ay eforudur. Erken tasarım modelinde 7, post-mimari modelde 17 efor çarpanı vardır.

Yeni modelde bu denkleme GSD'ye özgü kritik maliyet etkenleri eklenmiştir. Eklenen 14 kritik maliyet etkeni, Faz 1'deki dört kategoriye (insan, süreç, proje, dış faktörler) aittir ve denkleme ek çarpanlar olarak girer. Yeni denklem bu etkenleri de içererek maliyet hesabında kullanılır.

### 3.8 Faz 3: tahmin ve hata ölçümü

Denklem kurulduktan sonra tahmin yapılmış ve doğruluk göreli hata büyüklüğü (Magnitude of Relative Error, MRE) ile ölçülmüştür:

$$MRE = \frac{|\text{gerçek efor} - \text{tahmini efor}|}{\text{gerçek efor}}$$

Sunucuya göre yeni denklemin hata oranı standart COCOMO II denklemine göre belirgin biçimde düşmüştür; bu düşüş eklenen kritik maliyet etkenlerinin etkisini gösterir.

<!-- BELİRSİZ: hata karşılaştırma grafiği ve sayısal değerleri karelerde yok. -->

> **Ek bilgi (derste anlatılmadı):** Birden çok projede ortalama alınan MRE değerine MMRE denir. Efor tahmini çalışmalarında büyük olasılıkla MMRE'nin 0.25'in altında olması yaygın bir kabul ölçütüdür.

### 3.9 Uzman görüşüyle değerlendirme

Model matematiksel hesabın dışında uzman görüşüyle de değerlendirilmiştir. Modeli doğrulamak için sektörden, proje yöneticisi olarak çalışan ve en az 10 yıllık deneyime sahip uzmanlar seçilmiştir. Uzmanlara maliyet etkenleriyle ilgili sorular sorulmuştur; örneğin COCOMO II'ye eklenen etkenlerle modelin genel tasarımının yeterli olup olmadığı ya da iyileştirme gerekip gerekmediği. Uzmanlar modeli kabul, ret ya da gözden geçirme olarak üç şekilde değerlendirmiştir.

Değerlendirme döngüsü bir şemayla gösterildi (ekrandan, 00:40:00):

```text
Yazar (Author) --oluşturur (create)--> Kontrol listesi (Checklist)
Kontrol listesi --iletilir (delivered to)--> Uzmanlar (Experts)
Uzmanlar --inceler (review)--> Kavramsal model (Conceptual Model)
Uzmanlar --yanıt (response)--> Yazar
Yazar <--revizyon (make revisions)--> Kavramsal model
```

### 3.10 Hocanın değerlendirmesi

Hoca, matematiksel işlemler içeren maliyet tahmin modellerinin yazılım proje yönetiminde çok eski yıllardan beri mühendislerin üzerinde durduğu bir konu olduğunu, bu sunumun da genişletilmiş COCOMO II üzerinde yapılmış bir uygulama olduğunu söyledi. Özellikle son 10 yılda maliyet tahmini yapma gerekliliğinin daha da arttığını belirtti. Bir öğrenci, müşteri isteklerinin proje boyunca çok değişken olabildiğini ve gerçekleştirilmesi zor isteklerin gereksinim analiziyle maliyetinin hesaplanmasının yapılıp yapılamayacağına karar vermede yararlı olduğunu ekledi.

## 4. Çevik Pratikler ve Yazılım Proje Yönetimi Karşıt Paternleri

Üçüncü sunumda IEEE Software dergisinde 2021'de yayımlanmış "Agile and Software Project Management Antipatterns: Clarifying the Partnership" makalesi anlatıldı (ekrandan, 01:15:00). <!-- BELİRSİZ: yazar adları altyazıda bozuk. -->

### 4.1 Problem ve kavramlar

Çevik pratiklerin her birinin bir kullanım amacı vardır. Bir geliştirme takımının çevik süreci benimsemesi, her alt pratiği uygulayacağı anlamına gelmez; çünkü projeler yalnızca başarı odaklı değildir, zaman ve maliyet de hesaba katılmalıdır.

**Karşıt patern (antipattern):** Yazılım proje yönetimi süreçlerini sekteye uğratan, ileri gidildiğinde projenin tamamen başarısız olmasına yol açan kötü yaklaşımlardır. Sorun çözme konusunda ters etki yapan, bir proje faktörünü kontrol edememeyi ya da başarısızlığı temsil eden uygulamalardır. Bunların bir standardı yoktur; yıllardır süren proje yönetimi deneyimleri, proje yöneticileri ve Scrum Master'larla yapılan görüşmeler sonucunda tanımlanmışlardır.

Makalenin dayanak noktası, proje yönetiminin yazılım geliştirmedeki başarısızlıkların ana nedeni olarak kabul edilmesidir. Alıntılanan bir IBM çalışmasına göre proje başarısızlıklarının %53'ü kötü yönetimden, yalnızca %3'ü teknik zorluklardan kaynaklanmaktadır.

Yaygın yazılım proje yönetimi hatalarının nedenleri bilgi eksikliği, tembellik, kibir ve aceleci davranmaktır. Sunucu, başlangıçta ekip üyelerine yeteneklerini incelemeden yanlış görev dağılımı yapılmasının da sık dikkat çekilen bir hata olduğunu ekledi.

Örnek bir karşıt patern: plana aşırı ayrıntılı biçimde sadık kalmak. Çevik süreçte sanki şelale modeli izleniyormuş gibi her şeyde ayrıntılı plana bağlı kalmak hem maliyet hem zaman yönetiminde sorun çıkarır ve çevikliğin kendi ilkesine terstir. <!-- BELİRSİZ: bu karşıt paternin makaledeki adı altyazıda "detaylı test/tesis plan" diye bozuk geçiyor. -->

### 4.2 Karşıt paternlerin nedenleri ve etkileri

Makaleden aktarılan üç tespit şunlardır (ekrandan, 01:05:00):

- Proje yöneticisinin bilgi eksikliği, yazılım proje yönetimindeki hatalı uygulamaların en yaygın nedenidir.
- Bu hatalı uygulamaların olumsuz etkileri müşterileri ve takım üyelerini olduğu kadar proje yöneticilerini de kapsar.
- Karşıt paternler doğrudan kontrol, motivasyon ve personel yönetimi gibi yazılım proje yönetimi faaliyetlerini olumsuz etkileyebilir.

Öte yandan çevik pratikler yazılım proje yönetimine zaman kontrolü, sürekli iyileştirme, takım memnuniyeti, işbirliği, uyum becerisi ve verimlilik artışı gibi doğrudan faydalar sağlar.

### 4.3 Yöntem

- **Çevik pratikler:** Bir sektör raporundaki pratik listesi doğrudan kullanılmamış, son 10 yılda yayımlanmış literatürle doğrulanmıştır. Bilimsel veri tabanlarında anahtar kelimelerle arama yapılmıştır. Ele alınan pratiklere örnekler: sprint planlama, retrospektif (sprint bittikten sonra sprintin nasıl geçtiğinin konuşulması), sprint review, planning poker, günlük stand-up, agile UX (kullanıcı/müşteri tarafının çevik sürece dahil edilmesi) ve single team.
- **Karşıt paternler:** 2015'te bir literatür çalışmasıyla derlenmiş 22 yazılım proje yönetimi karşıt paterninden oluşan envanter kullanılmıştır.
- **Etki tablosu:** Pratiklerle karşıt paternlerin kesişim tablosu, yazarların yüksek teknoloji girişimlerinden çok uluslu şirketlere kadar danışmanlık yaptıkları 40 yılı aşkın sektör deneyimine dayanır. Bu, 30 çevik uygulayıcıyla yapılan birer saatlik görüşmelerle desteklenmiştir. Görüşülenler bankacılık, borsa, ulaşım, sağlık ve eğitim gibi farklı sektörlerdendir ve %80'den fazlası sertifikalı Scrum Master'dır.

> **Ek bilgi (derste anlatılmadı):** Sunumda "12. çevik rapor" diye geçen kaynak büyük olasılıkla VersionOne/Digital.ai'nin yıllık "State of Agile" anketinin 12. raporudur.

Görüşülenler kişisel deneyimin ve çalışma ortamının yorumları etkilediğini kabul etmekle birlikte bazı ortak sonuçlara ulaşmıştır. Örneğin takımdaki herkesin her işi dönüşümlü yapabildiği, kimsenin bir konuda uzmanlaşmadığı single team yaklaşımının domino etkisine yol açtığını birçok kişi belirtmiştir.

### 4.4 Etki türleri

Tabloda dört sembol kullanılır (ekrandan, 01:10:00):

| Sembol | Anlamı | Oran | Örnek |
|---|---|---|---|
| Onay işareti | Pratik karşıt paterni azaltmaya katkıda bulunur (en istenen sonuç) | %42 | Daily stand-up / Absentee Manager |
| Büyüteç | Paterni kaldırmaz ama belirtilerini tespit etmeye yardım eder | %35 | Sprint Planning / Rising Upstart |
| Çarpı | Ne azaltır ne de riskin tespitine yardım eder | %22 | Sprint Review / All You Have Is a Hammer, Appointed Team, aşırı ayrıntılı plan |
| Ünlem | Paterni kötüleştirir ya da ortaya çıkmasına katkıda bulunur | %1 | Single Team / Domino Effect |

Oranların toplamı $42 + 35 + 22 + 1 = 100$'dür.

Örneklerin açıklaması:

- **Daily stand-up ve Absentee Manager:** Günlük toplantılar proje yöneticisi dahil bütün takım üyelerinin varlığını gerektirir; bu da yönetici yokluğu sorununu çözer.
- **Sprint Planning ve Rising Upstart:** Rising Upstart, bazı üyelerin yeterli bilgi edinmeden "şu görevi de alırım" diyerek hızla ve aşırı iş üstlenmesidir. Sprint planlama oturumlarında takım yapılacak görevleri tahmin edip dağıttığı için herkesin sınırları belirlenir ve aşırı iş yüklenmeye çalışan üyeler tespit edilir. Bu etki doğrudan çözüm kadar güçlü değildir, dolaylıdır.
- **Sprint Review:** Sprint review ürünü ürün sahibine/müşteriye sunmaya yöneliktir. All You Have Is a Hammer (proje yönetiminin her süreçte aynı şekilde düşünmesi, değişen durumlara uyum sağlayamaması), Appointed Team (takım uyumunu sağlayan uygulamaların eksikliği) ve aşırı ayrıntılı plana bağlılık gibi sorunlar yaşanıyorsa sprint review bunları çözmez.
- **Single Team ve Domino Effect:** Single team, herkesin herhangi bir rolü üstlenebileceği anlamına gelir. Bir kişi başka bir projeye kaydırıldığında herkesin her şeyi yapabileceği varsayımıyla oluşan rahatlık zincirleme sorunlara, yani domino etkisine yol açar. Bu yüzden her çevik pratik körü körüne uygulanmamalıdır.

### 4.5 En çok çözüm getiren pratikler ve müşteriye zararlı paternler

Sprint planlama, planning poker ve agile UX en fazla sayıda karşıt paterne çözüm getiren pratiklerdir. Müşteri için özellikle olumsuz sonuçları olan ve dikkatle ele alınması gereken paternler şunlardır:

- **Fire Drill:** Uzun süre hiçbir şey yapılmayıp teslim tarihi yaklaşınca son anda telaşla çalışılması.
- **Mushroom Management:** Müşteriyle hiç ilişki kurulmadan geliştirmenin sürdürülmesi.
- **Myopic Delivery:** Değişen faktörler dikkate alınmadan teslim planının yapılması.

Sunucu, hangi pratiğin en çok paterne çözüm getirdiğinin tek başına yeterli bir ölçüt olmadığını vurguladı. Örneğin agile UX çok sayıda paterne çözüm bulur, ama müşterinin yazılım proje yönetiminde etkin görev alması demektir; bu hem zaman hem müşteri tarafında masraf anlamına gelir.

### 4.6 Sonuç ve çıkarımlar

- Bir pratiğin uygulama maliyeti ile hatalı uygulamaları ele alabilme yeteneği arasında kâr-zarar analizi yapılmalıdır (agile UX örneğinde olduğu gibi).
- Tek bir pratik belirli bir karşıt paterni çözmeye yetmeyebilir; birkaç pratiğin birlikte uygulanması gerekebilir.
- Çevik pratikler takımları kendiliğinden yazılım proje yönetimi sorunlarından kurtarmaz. Bir karşıt paternin çözümü başka sorunlar doğurabilir; zincirleme etkiler dikkate alınmalıdır.
- Yazarlar hatalı uygulamaların yüzeye çıkarılmasını ve tartışılmasını en önemli adım olarak görür. Pratik-patern etki tablosu faydalı olabilecek uygulamaları belirlemek için kullanışlıdır.
- Her organizasyon karşıt paternlerin iş değerine olumsuz etkilerini ve ilgili riskleri belirlemekten kendisi sorumludur; her takımın kendine özgü bütçe ve zaman kısıtları vardır.

Hoca özet olarak çevik süreçlerin yazılım proje yönetimindeki karşıt paternleri azaltmak için kullanılmasının uygun olduğunun bildirildiğini söyledi ve şirketlerde çevik süreç kullanan öğrencilerden örnek istedi. Bir öğrenci, Scrum ile yürütülen projelerde sprint review ve retrospektif toplantılarının birçok sorunu önlediğini, herkesin toplantılarda bulunmasının takımın projeden kopmadan motivasyonunu korumasını sağladığını anlattı.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:07:38): Artırımlı varlık modelinin süreç diyagramı, nesneye yönelik yazılım geliştirmede kullandığımız UML diyagramlarından hangisine benzer?

> **Çözüm:** Aktivite diyagramına. Diyagram pazar analisti, yönetici direktör, proje yöneticisi ve testçinin yaptığı işleri ayrı bölümlerde (kulvarlarda) gösterir; aktivite diyagramında da aktörlerin faaliyetleri bu şekilde ayrılır.

**Soru 2** (derste sözlü, 00:14:49): Artırımlı varlık modelini iş yerinde kullandığınız proje yönetim süreçleriyle ilişkilendirerek yorumlayın.

> **Çözüm (derste tartışıldı):** Müşteriye özel yazılım sayısı arttıkça zaman ve maliyet kaybı artar; pazar analiziyle hedef kitlenin ortak ihtiyaçlarına göre genelleştirilmiş bir çözümle başlamak hem yeniden kullanımı hem ekip içi bilgi paylaşımını artırır ve işin tek kişiye bağımlı kalmasını önler. Öte yandan firma büyüdükçe ve müşteri tipleri çeşitlendikçe ortak çözüm kurmak zorlaşabilir. Hoca ayrıca "yazılım projelerinin başarı oranı düşüktür" iddiasının zaman, maliyet ve kapsam ölçütlerine dayanan bir klişe olduğunu ve güncel raporlarla kontrol edilmesi gerektiğini ekledi.

**Soru 3** (derste sözlü, 00:42:02): Maliyet tahmini yapma gerekliliği sektörde nasıl karşılanıyor?

> **Çözüm (derste tartışıldı):** Müşteri istekleri proje boyunca çok değişken olabilir ve bazıları gerçekleştirilmesi zor isteklerdir. Bu isteklerin gereksinim analiziyle maliyetinin hesaplanması, yapılıp yapılamayacaklarına karar vermeye yardım eder; bu yüzden maliyet tahmini son yıllarda daha yaygın kullanılmaktadır.

## Dersin Toparlaması

Bu derste üç makale üzerinden yazılım proje yönetiminin farklı yüzleri ele alındı. Birinci makale, her müşteriye baştan özel yazılım geliştirmek yerine pazar analiziyle başlayan, yeniden kullanılabilir bileşenleri proje projeden artırarak biriktiren bir süreç modeli önerdi; bu tartışma proje başarısının zaman, maliyet ve kapsam ölçütlerine ve genelleştirilmiş çözümlerin ekip içi bilgi paylaşımına katkısına bağlandı. İkinci makale, COCOMO II'yi küresel yazılım geliştirmeye özgü insan, süreç, proje ve dış kaynak etkenleriyle genişleterek efor tahminindeki hatayı azaltmayı ve modeli uzman görüşüyle doğrulamayı gösterdi.

Üçüncü makale çevik pratiklerin yazılım proje yönetimi karşıt paternleri üzerindeki etkisini sınıflandırdı: pratiklerin çoğu paternleri azaltır ya da görünür kılar, bir kısmı etkisizdir, bir pratik ise paterni kötüleştirebilir. Ortak ders, bir yöntemin ya da pratiğin seçiminde maliyet-fayda dengesinin, projenin bağlamının ve takımın kısıtlarının birlikte gözetilmesi gerektiğidir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
