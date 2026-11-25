# Ders 12 Genişletilmiş Notu: Makale Sunumları: Büyük Ölçekli ve Hibrit Çevik Yöntemler, Proje Çizelgeleme, Makine Öğrenmesiyle Tahmin ve Duygusal Takım Koçluğu

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

Bu ders öğrencilerin makale sunumlarıyla geçti. Her öğrenci yazılım proje yönetimiyle ilgili bir makale ya da bildiriyi yaklaşık on beş dakikada anlattı. Hoca sunumların arasında sorular sordu ve kısa yorumlar yaptı. Aşağıda sunumlar ders sırasıyla verilmiştir. Sunum yapanlar "bir öğrenci" diye anılır.

## İçindekiler

- 1. Büyük ölçekli çevik yazılım geliştirme yöntemlerinin karşılaştırılması
- 2. Yazılım proje çizelgeleme problemi üzerine bir tarama
- 3. Şelale ve Scrum'ı birleştiren hibrit çevik model
- 4. Sistem düşüncesi: yapay sinir ağlarıyla proje başarısı tahmini
- 5. Makine öğrenmesiyle yazılım efor tahmini ve COCOMO
- 6. Yazılım geliştirmede duygusal takım koçluğu
- 7. Makine öğrenmesiyle yazılım proje yönetimi: sistematik tarama
- 8. Proje yönetiminde zaman planlaması ve kaynak tahsisi
- Örnek Sorular

## 1. Büyük Ölçekli Çevik Yazılım Geliştirme Yöntemlerinin Karşılaştırılması

İlk sunumda büyük ölçekli çevik yöntemleri karşılaştıran bir sistematik literatür taraması anlatıldı. Slaytta verilen bağlantıya göre çalışma IEEE Transactions on Software Engineering dergisinde 2021'de yayımlanmıştır (ekrandan, 00:15:00).

### 1.1 Problem ve kapsam

Çevik yöntemler ekip düzeyinde yaygınlaşıp başarılı olunca birçok yazılım kuruluşu bu başarıyı organizasyon düzeyine taşımak istedi. Bunun için birden çok ekibi koordine eden büyük ölçekli çevik çerçeveler ortaya çıktı. Mevcut literatür her yöntemi ayrı ayrı inceler, ama ampirik kanıta dayalı bir yöntemler arası karşılaştırma yoktur. Bu tarama SAFe, LeSS, Scrum at Scale, DAD ve Spotify modelini karşılaştırır. Çalışma, yöntemlerin ilke, uygulama, araç ve metriklerini standart bir biçimde analiz eden ilk çalışma olduğunu belirtir. Yalnızca özgün yöntemleri değil, sonraki araştırmalarda önerilen uzantı ve değişiklikleri de sunar. Ticari çerçevelerin yanında Nokia, Ericsson gibi kuruluşların kendine özgü yöntemleri de karşılaştırmaya girer. Böylece uygulayıcılar ihtiyaçlarına hangi ticari yöntemin, hangi bileşenin ya da hangi özel yöntemin daha uygun olduğuna daha bilinçli karar verebilir.

### 1.2 Çerçeveler

Sunumda çerçeveler slaytlarla tek tek tanıtıldı (ekrandan, 00:10:00):

- **LeSS (Large Scale Scrum):** Büyük ürün geliştirme projeleri için ölçeklenmiş Scrum'dır. Basit ve esnektir, standart Scrum ilke ve uygulamalarını temelde korur. Birden çok Scrum ekibinin bir araya gelip entegre olmasını destekler. Bir ürün için tek bir ürün sahibi bulunur.
- **SAFe (Scaled Agile Framework):** Ölçeklendirilmiş çevik uygulamaları destekleyen kapsamlı bir çerçevedir. Çok sayıda ekip ve birden fazla ürün üzerinde çalışan büyük organizasyonları hedefler. Portföy yönetimi, program yönetimi ve ekip düzeyi gibi farklı ölçeklerde katmanlar içerir. Agile Manifesto ilkelerine dayanır, ek özellik ve süreçlerle genişletilmiştir.
- **DAD (Disciplined Agile Delivery):** Çeşitli yöntem ve uygulamaları birleştiren kapsamlı bir çerçevedir. Çevik, kısmen çevik ve geleneksel yöntemlerin kombinasyonunu destekler. Proje yaşam döngüsünün tüm aşamalarında rehberlik eder, farklı roller ve süreçler içerir. Esneklik ile uyumluluk arasında denge kurmayı hedefler.
- **Scrum at Scale:** Scrum ilke ve uygulamalarını çoklu ekiplere ve büyük organizasyonlara ölçekler. Organizasyonun tamamının Scrum'ı benimsemesini hedefler. Birbiriyle entegre çalışan ve bir üst düzey ürün sahibine bağlı çok sayıda Scrum ekibini destekler. Koordinasyon için bir dizi rol ve sorumluluk tanımlar.

### 1.3 Teknik karşılaştırma

Sunucu dört açıdan karşılaştırma yaptı:

- **Ölçek:** LeSS ve Scrum at Scale büyük projelerde birden çok Scrum ekibiyle çalışmayı desteklerken, SAFe ve DAD daha geniş organizasyonları hedefler.
- **Yapı ve kapsam:** LeSS Scrum'ın temel ilkelerini koruyarak basit bir yapı sunar. SAFe katmanlı ve kapsamlıdır. DAD çeşitli yöntemleri birleştirir. Scrum at Scale Scrum'ı bütün organizasyona yayar.
- **Süreç uygulamaları:** SAFe program ve portföy yönetimi gibi ek süreçler içerir. DAD farklı yöntemlerin süreçlerini bir araya getirir. LeSS ve Scrum at Scale Scrum'ın temel süreçlerine odaklanır.
- **Esneklik:** LeSS ve Scrum at Scale Scrum'ın esnekliğini koruyarak ölçeklenir. SAFe ve DAD farklı yaklaşımları birleştirerek esneklik ve uyum hedefler.

Seçim yapılırken organizasyonun ihtiyaçları, projenin ölçeği ve kültürel uyum göz önünde bulundurulmalıdır. Her çerçevenin farklı durumlarda farklı avantajları vardır.

### 1.4 Araştırma soruları ve süreç

Çalışmanın araştırma soruları şunlardır:

- RQ1: Büyük ölçekli çevik yöntemler literatürde ampirik olarak ne ölçüde incelenmiştir?
- RQ2: Bu yöntemler hangi soyutlama düzeyinde (ilkeler, uygulamalar, araçlar, metrikler) incelenmiştir ve hangi bilgi boşlukları vardır?
- RQ3: Bu yöntemler için hangi zorluklar bildirilmiştir?
- RQ4: Bu yöntemler için hangi başarı faktörleri bildirilmiştir?

Arama stratejisinde araştırma sorularından ve eş anlamlılardan anahtar kelimeler belirlenmiş, literatür incelemelerinden de terimler toplanmıştır. Arama terimleri üç gruba ayrılıp AND ile bağlanmıştır (ekrandan, 00:15:00). Birinci grup büyük ölçekli geliştirmede kullanılan yöntem adlarıdır; bu adlar VersionOne'ın son raporundan alınmıştır. İkinci grup yazılım ve bilgi sistemleri geliştirmeyle ilgili makaleleri, üçüncü grup çevik yöntemlerin büyük ölçekli ortamlarda kullanımını tartışan makaleleri yakalar. Arama dizgeleri kapsayıcı tutulduğu için sonuçlar geniştir. Bulguların göreli gücünü değerlendirmek için 191 makale üzerinde kalite değerlendirmesi yapılmıştır.

Hoca bu noktada makalelerin arama ayrıntılarına girmeye gerek olmadığını, bulgulara geçilmesini söyledi.

### 1.5 Sonuç

Çalışma, büyük ölçekli çevik geliştirme konusundaki ampirik çalışmaların son yıllarda hızla ve istikrarlı biçimde arttığını gösterir. Önceki bir taramayla karşılaştırıldığında incelenebilen çalışma sayısı çok artmıştır. <!-- BELİRSİZ: önceki taramada 2013'e kadar kaç ampirik makale bulunduğu (altyazıda "6") ve 2019'a kadar bulunan 191 çalışmanın kaçının ampirik araştırma makalesi olduğu (altyazıda "120") Whisper bozmalı; kareden doğrulanamadı. --> Sunucuya göre bu karşılaştırmalar ileride yapılacak çalışmalara yön verecek niteliktedir.

**Soru (hoca):** Bu yöntemlerin kullanıldığı örnekler var mı, örneğin Türkiye'deki şirketlerden? **Cevap:** Sunucu, Türkiye'deki büyük şirketlerde de dünyadaki gibi çevik modele geçişin sürdüğünü, bunun dijital dönüşüm çalışmalarıyla birlikte yürüdüğünü söyledi.

## 2. Yazılım Proje Çizelgeleme Problemi Üzerine Bir Tarama

İkinci sunum, yazılım proje çizelgeleme problemi (Software Project Scheduling Problem, SPSP) üzerine yapılmış çalışmaları tarayan bir makaleydi. Makale 2018'de International Journal of Production Economics dergisinde yayımlanmıştır.

### 2.1 Giriş ve katkı

Proje yönetimi yazılım geliştirme organizasyonlarında kilit bir faaliyettir ve bu faaliyetteki başarısızlıkların maliyeti çok yüksektir (ekrandan, 00:20:00). Planlama düzgün yapılmazsa maliyet artar, proje zamanında teslim edilemez ve müşteri memnuniyeti düşer. Sunucu, makalenin bir ekonomi dergisinde yayımlanmasını bu ekonomik etkiye bağladı. Plan oluşturulurken izlenen hedeflerden biri proje maliyetinin ve süresinin en aza indirilmesidir.

Önceki tarama çalışmalarının çoğu kaynak kısıtlı proje çizelgeleme (Resource Constrained Project Scheduling, RCPS) problemine odaklanmıştır. Bu makale ise yazılım projelerine özgü çizelgeleme problemine odaklanır. İki katkısı vardır: SPSP ile ilgili ilk kapsamlı taramadır ve gelecekteki araştırmalar için genel gözlem ve öneriler sunar.

### 2.2 Yöntem: sistematik haritalama

Makaleler sistematik haritalama çalışması (systematic mapping study) yöntemiyle seçilmiştir. Adımlar şunlardır:

- Araştırma hedeflerinin belirlenmesi
- Arama dizgelerinin belirlenmesi
- Hangi arama motorlarında arama yapılacağının belirlenmesi
- Dahil etme ve dışlama ölçütlerinin belirlenmesi

Örneğin yazılım projesi üzerine yazılmış bir makale dahil edilir, 2000'den önce yazılmış bir makale dışlanır. Arama sonucunda 57 makale bulunmuş, filtrelerden sonra 30 makale kalmıştır. Bunların 16'sı konferanslarda, 14'ü dergilerde yayımlanmıştır. <!-- BELİRSİZ: yayın kaynaklarının dağılımı (ACM 6, IEEE 8, SpringerLink ...) altyazıda eksik. -->

### 2.3 Proje planlama modeli

İncelenen makaleler beş başlıkta analiz edilmiştir. Birincisi proje planlama modelidir. Bu modelde çalışanlar becerileriyle, görevler gerektirdikleri beceri ve eforla tanımlanır. Çalışanların ayrıca maaşı ve projeye ayırabildiği zaman da vardır.

**Soru (hoca):** Yani yazılım projelerinde hep kaynak çizelgeleme üzerinde mi durulmuş? **Cevap:** Sunucu, kaynak çizelgelemenin ötesinde başka konular da olduğunu, ama planlama modelinin hem çalışanın mevcut yeteneklerine hem de görevin gereksinimlerine göre kurulduğunu söyledi. Hoca, en önemli kaynak insan olduğuna göre bunun insan kaynağının planlanması olduğunu belirtti; sunucu da bunu onayladı.

> **Hocanın vurgusu:** Yazılım projelerinde en önemli kaynak insandır; çizelgeleme aslında insan kaynağının planlanmasıdır.

Bu modelde bir görevin süresi, görevin eforunun göreve ayrılan insan kaynağına bölünmesiyle bulunur. Modelin kısıtları şunlardır: hiçbir görev tamamlanmadan proje bitemez, çalışanlar projede azami çalışma süresini aşmamalıdır ve projeyi tamamlamak için gereken beceriler karşılanmalıdır. Bu modeli ilk kez Alba ve Chicano önermiştir ve model birçok araştırmada yeniden kullanılmıştır (ekrandan, 00:25:00).

> **Ek bilgi (derste anlatılmadı):** Alba ve Chicano modelinde $x_{ij} \in [0,1]$, çalışan $i$'nin görev $j$'ye ayırdığı mesai oranıdır. Görev süresi büyük olasılıkla $t_j = \dfrac{\text{effort}_j}{\sum_i x_{ij}}$ ile, proje maliyeti de çalışanların maaşlarının görevlerde harcadıkları zamanla çarpılıp toplanmasıyla hesaplanır.

Diğer çalışmalar modeli şöyle farklılaştırmıştır (ekrandan, 00:25:00):

- Chang ve arkadaşları (2008): çalışanların becerileri 0 ile 5 arasında derecelendirilir; aylık maaş ve fazla mesai ödemesi de modele girer.
- García ve Gómez (2014): çalışanların acemi, genç, kıdemli ve uzman diye beceri düzeyi vardır; görevler de gerekli bir beceri düzeyiyle tanımlanır.
- Duggan ve arkadaşları (2004): farklı görev türleri için beceri düzeyleri acemi, orta, iyi, çok iyi ve uzman olarak belirlenir.
- Shen ve arkadaşları (2018): çalışanların uygunluğu değişkendir; çalışan proje sırasında projeye girip çıkabilir, başka projeye geçip geri gelebilir. Bu dinamik modelde projenin parçalara ayrılmasının iyi yapılması gerekir.

### 2.4 Optimizasyon hedefleri

30 makalenin 18'inde tek hedef projenin maliyetini ve süresini en aza indirmektir. Diğerlerinde ek hedefler vardır:

- Fazla mesai düzeyini en aza indirmek
- Kodlama faaliyetlerindeki beklenen hata sayısını en aza indirmek; böylece sonraki hata ayıklama süreçleri kısalır
- Süreyle birlikte parçalanmayı (fragmentation) en aza indirmek

Parçalanma, projeyi yapmak için küçük alt gruplara bölmektir. Sunucuya göre proje ne kadar az parçada yapılırsa o kadar başarılı olur. Az parçada yapmak daha az kişiyle ya da daha az beceri gerektiren kişilerle yapmak anlamına da gelebilir.

**Soru (hoca):** Burada tek amaçlı mı, çok amaçlı optimizasyon mu var? **Cevap:** Sunucu, optimizasyon tipinin de ayrıca sınıflandırıldığını onayladı (tek ve çok amaçlı).

### 2.5 Algoritmalar

30 makalenin 27'sinde evrimsel algoritmalar, bunların 19'unda genetik algoritma kullanılmıştır. Bazı çözümlerde çok amaçlı genetik algoritma (MOGA) kullanılır. Çözüm $M \times N$ boyutlu bir matrisle temsil edilir; matris her çalışanın her göreve ayırdığı zamanı gösterir. Elimizdeki çalışanlarla birden fazla hedefin ne kadar iyi sağlanabildiği ölçülür.

Altı çalışmada sürü zekâsına dayalı algoritmalar kullanılmıştır: dördünde karınca kolonisi optimizasyonu, birinde parçacık sürüsü optimizasyonu, birinde ateş böceği algoritması.

### 2.6 Değerlendirme yöntemleri

İki değerlendirme yaklaşımı vardır: kıyaslama örnekleri ve parametre ayarlarının analizi. Kıyaslama örneklerinde aynı yöntem farklı örnek gruplarında denenir ve hangisinin daha iyi olduğuna bakılır.

11 çalışma Alba ve Chicano (2007) tarafından kullanılan kıyaslama örneklerini tamamen ya da kısmen kullanmıştır (ekrandan, 00:30:00). Bazı çalışmalar ise yapay veri üretmiştir: 5, 10, 15 ve 20 çalışan; 10, 20 ve 30 görev; 5 ve 10 global beceri; çalışan başına 4-5 ya da 6-7 beceri. Bu değerlerin bütün birleşimleriyle 48 yazılım projesi üretilmiştir.

$$4 \text{ (çalışan sayısı)} \times 3 \text{ (görev sayısı)} \times 2 \text{ (global beceri)} \times 2 \text{ (çalışan başına beceri)} = 48$$

(ara adım eklendi; python ile doğrulandı)

Parametre ayarları genetik algoritmadan gelir: popülasyon büyüklüğü, mutasyon oranı gibi. En sık seçilen popülasyon büyüklüğü 100'dür; 7 çalışmada 64, 5 çalışmada 60 ya da daha az, 3 çalışmada 100'den fazla kullanılmış, 5 çalışmada bilgi bulunamamıştır. <!-- BELİRSİZ: popülasyonu 100 alan çalışma sayısı altyazıda geçmiyor. --> Ebeveyn seçimi için ikili turnuva ve rulet çarkı yöntemleri kullanılmıştır.

### 2.7 Sonuçlar

- **MOCell** (çok amaçlı hücresel genetik algoritma) gerçekçi problem durumlarını simüle etmek için en uygun algoritma bulunmuştur.
- **PAES** ölçeklenebilir problemlerde, yani görev ve çalışan sayısı çok fazla olduğunda daha iyi sonuç vermiştir.
- 8 çalışmada algoritmalar isabet oranına göre değerlendirilmiştir. İsabet oranı, kısıtları ihlal etmeden uygun çözüm bulunan çalıştırmaların yüzdesidir. MOGA, bir çalışanın belirli sayıda görevi aynı anda yürütmesine izin verilen durumların çoğunda %100 isabet sağlamıştır. <!-- BELİRSİZ: "günde 2-4 veya 8 görev" ifadesinin tam anlamı altyazıda net değil. -->
- Karınca kolonisi optimizasyonu genetik algoritmadan daha yüksek başarı oranı elde etmiş, daha iyi süre ve maliyetli çözümler bulmuştur.

### 2.8 Tartışma ve sonuç

Tartışma slaytındaki gözlemler şunlardır (ekrandan, 00:35:00):

- Alba ve Chicano'nun (2007) modeli incelenen makalelerin çoğunda temel ya da referans model olarak kullanılmıştır.
- Bazı araştırmacılar çalışanları kıdemli/kıdemsiz gibi farklı beceri ve uzmanlık düzeylerine ayırmıştır. Alba ve Chicano'da bütün çalışanlar aynı düzeyde kabul edilir.
- SPSP'de en sık kullanılan optimizasyon hedefleri projenin maliyeti ve süresidir.
- Bazı araştırmacılar yeni kıyaslama örneği oluşturmak yerine Alba ve Chicano'nun örneklerini doğrudan kullanmıştır.
- İsabet oranını bildiren 6 çalışmanın 3'ünde, 30 ya da daha fazla görev içeren problemlerde sonuçlar sıfırdır. Gerçek projeler genellikle daha fazla görevden oluştuğu için bu durum yaklaşımların gerçek dünyada kullanılmasını kısıtlar.

Makalenin üç hedefi vardı ve üçü de karşılanmıştır. Birincisi SPSP'yi çözmeye yönelik proje modellerini belirlemektir; önerilen modeller Alba ve Chicano'nun özgün modeline çok benzer. İkincisi yazılım proje planlamasının optimize edilebilecek yönlerini belirlemektir; temel hedef süre ve maliyetin en aza indirilmesidir, buna ek hedefler eklenmiştir. Üçüncüsü bu problemi çözmek için en çok kullanılan algoritmaları belirlemektir; genetik algoritmalar ve çok amaçlı evrimsel algoritmalar en yaygın tekniklerdir, MOCell en iyi sonuçları üretmiştir.

## 3. Şelale ve Scrum'ı Birleştiren Hibrit Çevik Model

Üçüncü sunum bir konferans bildirisiydi: "The Waterfall Model with Agile Scrum as the Hybrid Agile Model for the Software Engineering Team". Bildiri Endonezya'da yapılmış bir çalışmayı anlatır.

### 3.1 Tanım ve önceki çalışmalar

Bildiriye göre (ekrandan, 00:40:00):

- Hibrit çevik, çevik ile çevik olmayan bir geliştirme stratejisini birleştiren bir yazılım geliştirme modelidir.
- Yazılım mühendisliği sistematik bir yaklaşımdır ve bu yaklaşımın bir süreç modeline dayanması gerekir.
- Geliştirme süreci projenin ihtiyacına göre seçilir.
- İki yöntemin birleşimi, bir yöntemin zayıflığını diğerinin güçlü yönleriyle aşmayı önerir.

Hoca, yazılım mühendisliğinde bir modelin olması gerektiğinin ders boyunca konuşulduğunu ve birleşik modellerin önceki sunumlarda da anlatıldığını hatırlattı.

Şelale modeli yönetiminin kolay olması, planlamanın proje başlamadan ayrıntılı yapılması ve tüm aşama ve faaliyetlerin açıkça tanımlanmasıyla öne çıkar. Çevik yöntemler kısa sürede geliştirmeye ve kullanıcıdan doğrudan geri bildirim almaya dayanır. Paydaş katılımıyla müşteri memnuniyetini öne alır ve kaliteli yazılımı teşvik eder. Bildiride çevik yöntem olarak Scrum ele alınmış ve Scrum'ın küçük, dinamik geliştirme ortamlarına daha uygun olduğu belirtilmiştir.

Hibrit çevik yeni bir fikir değildir. Bildiri, iki yöntemin avantajlı yanlarını birleştiren "Scrumfall" gibi önceki çalışmalara atıf yapar. Tek bir projede plan güdümlü ve çevik süreç modellerinin birlikte kullanılabileceği, hibrit çevikliğin büyük proje ekiplerine ölçeklenebileceği ve proje başarı oranını iyileştirebileceği öngörülmüştür.

### 3.2 Araştırma yöntemi

Yöntem üç adımdır:

- **Araştırma araçlarının geliştirilmesi:** Görüşme protokolü hazırlanır. Soruların konuya uyumlu ve tutarlı olması sağlanır, protokol bir uzman tarafından gözden geçirilip geri bildirime göre düzeltilir.
- **Veri toplama:** Yazılım şirketlerinde çalışan 5-10 yıl deneyimli 25 yazılım mühendisi davet edilir. Geri dönen 15 kişiden bir kısmı seçilir; reddedenler ve hibrit modelde çalışmayanlar elenir. Görüşmeler ses kaydı ve notlarla yapılır. <!-- BELİRSİZ: seçilen ve katılan kişi sayıları altyazıda karışık (8, altı, beş). Tabloda A-F olmak üzere altı katılımcı görünüyor. -->
- **Analiz:** Görüşmelerin transkripti çıkarılır, doğrulama için katılımcılarla paylaşılır ve tematik olarak analiz edilir.

### 3.3 Bulgular

Bildirideki tabloda katılımcılar, kullandıkları süreç modelleri ve rolleriyle verilmiştir (ekrandan, 00:45:00):

| Katılımcı | Süreç modeli | Rol |
|---|---|---|
| A | Waterfall and Scrum, Waterfall or Scrum | Software engineer cum project manager |
| B | Waterfall and Scrum | Software engineer |
| C | Waterfall and Scrum with Kanban board, sometimes Lean | Software engineer |
| D | Waterfall and Scrum | Senior programmer |
| E | Waterfall and Scrum | Software engineer |
| F | eXtreme Programming | Programmer |

Katılımcı F yalnızca XP kullandığı için bildirinin aradığı hibrit modele uymaz. Onun ekibi, dokümantasyon gibi daha az önemli görülen işlere zaman harcamak istemediği ve kodlamaya odaklanmak istediği için XP'yi seçmiştir. Diğer beş katılımcının şelale ve Scrum üzerinde birçok ortak noktası vardır. Beş katılımcı da paydaşların belirttiği gereksinimler nedeniyle her projede farklı yönetim yöntemleri kullanıldığını söyler.

- A, ekibin her projede aynı metodolojiyi izlemediğini, şirketin bazen şelale, bazen yalnızca Scrum, çoğu zaman da ikisini birleştiren hibrit yaklaşımı kullandığını belirtmiştir.
- C, çevik tanıtılmadan önce şelale modelinin kullanıldığını, sonra çeviğin tercih edildiğini ve o zamandan beri karma modellerin kullanıldığını söylemiştir. Ona göre Scrum ve şelale kombinasyonunun nedeni proje karmaşıklığıdır.
- B, D ve E de geliştirme modeli olarak şelale ve Scrum'ı birleştirmektedir.

Sunucu, beş kişilik örneklemle sonuçların ne kadar genellenebileceğinden emin olmadığını, ama çıkarımların büyük ölçüde mantıklı ve uygulanabilir olduğunu söyledi. Hoca, bu alanda veri toplamanın örneğin hastalık verileri gibi alanlara göre daha zor olduğunu, verinin az olmasının bundan kaynaklanabileceğini ve konferans yayınlarında bu eksikliğin daha sık görülebileceğini belirtti.

### 3.4 Tartışma ve sonuç

Bildirinin vardığı sonuçlar şunlardır (ekrandan, 00:50:00):

- Scrum ve şelale kombinasyonu yeni değildir, araştırmacılar tarafından daha önce incelenmiştir.
- Katılımcılar hibrit çevik kararında dört faktörün önemli olduğunu söyler: proje gereksinimleri, proje karmaşıklığı, model uygunluğu ve iletişim. <!-- BELİRSİZ: dördüncü faktörün tam adı altyazıda bozuk ("iletişim kanunluğu"). -->
- Tek bir metodolojinin, ne çeviğin ne de şelalenin, tüm projelere evrensel olarak uygulanamayacağı konusunda geniş bir uzlaşma vardır. Bu yüzden çevik ve çevik olmayan metodolojiler uyarlanıp entegre edilmelidir.
- Scrum'ı bağımsız bir süreç modeli olarak kullanmak, onu şelale gibi plana dayalı bir modelle birleştirmeye göre projenin ihtiyaç duyduğu en yüksek etkiyi vermez. Şelale modeli de tek başına yeterli değildir.
- Hibrit modeli seçmenin amacı planlama ve yönetim, geliştirme ve kalite dahil tüm aşamalarda daha fazla esneklik sağlamaktır. Kombinasyon geliştirmeyi hızlandırır, süreç şeffaflığını artırır ve ekipler arası iletişimi geliştirir.

## 4. Sistem Düşüncesi: Yapay Sinir Ağlarıyla Proje Başarısı Tahmini

Dördüncü sunum, yazılım projelerinde sistem düşüncesini yapay sinir ağı (YSA) yaklaşımıyla ele alan, 2020'de IEEE Access'te yayımlanmış bir makaleydi.

### 4.1 Amaç ve arka plan

Çalışmanın amacı, çok boyutlu bir yapı olarak ölçülen proje başarısını tahmin etmek için kritik başarı faktörlerinin (CSF) doğrusal olmayan davranışlarını keşfetmek ve başarının boyutları arasında denge kuracak bir araç bulmaktır. Bunun için YSA ile bir proje sonucu tahmin modeli önerilir.

Yazılım projelerinin yüksek bir başarısızlık geçmişi vardır. Slayta göre 2009'da yazılım projelerinin yalnızca %32'si başarılıdır ve başarısızlığın nedeni karmaşıklıktır (ekrandan, 00:55:00). Proje başarısızlığı araştırmalarının kökeni yirminci yüzyılın ikinci yarısına dayanır ve "yazılım krizi" terimi ilk kez 1968'de ortaya çıkmıştır. Kritik başarı faktörleri kavramı daha sonra popülerleşip proje yönetimi uygulamalarına girmiştir.

### 4.2 Proje başarısının boyutları

Yazılım proje başarısı iç ve dış paydaşların çıkarları dengelenerek elde edilir. Makaleye göre başarının en az üç boyutu vardır:

- **Proje yönetimi başarısı:** bütçe, zaman ve iç kısıtlar gibi verimlilik ölçütleriyle ölçülür.
- **Ürün başarısı:** iç ve dış paydaşlara sağlanan faydanın dengede tutulmasıdır.
- **Stratejik (iş) başarı:** şirketin gelecekteki başarısını sağlama yeteneğidir; ürünün pazarlanması, yeni pazar oluşturması gibi.

Kritik başarı faktörleri, iyi yönetildiğinde daha iyi organizasyon performansı sağlayan kilit alanlardır. Proje yönetimi bağlamında projenin başarı olasılığını doğrudan etkileyen faktörlerdir. Sistem düşüncesinde faktörler arasındaki etkileşimler hesaba katılır. Önceki tahmin modelleri CSF'leri kullanmış ama aralarındaki etkileşimi dikkate almamıştır. Bu makalenin farkı, bu etkileşimleri de modele katmasıdır.

CSF'ler beş kategoride incelenir: müşteri, teknik, proje yönetimi, organizasyon ve takım faktörleri.

### 4.3 Neden yapay sinir ağları?

Tahmin modellerinde Naive Bayes, destek vektör makineleri, lojistik regresyon ve genetik algoritmalar sık kullanılır. Bu çalışma YSA'yı şu gerekçelerle seçer (ekrandan, 01:00:00):

- YSA, proje sistemi unsurları arasındaki doğrusal ve doğrusal olmayan ilişkileri öğrenmek için yinelemeli bir eğitim süreci kullanır.
- En büyük avantajı veri kümelerinin altındaki örüntüleri yakalayıp girdi-çıktı değişkenleri arasındaki karmaşık ilişkileri modelleyebilmesidir.
- Veri kümesi türü ya da girdi-çıktı sayısı konusunda bir sınırlaması yoktur; bu da onu yazılım projelerine uygulanabilir kılar.

Önceki çalışmalar CSF'ler ile proje başarısı arasında doğrusal bir ilişki varsaymıştır. Bu makale aralarında doğrudan doğrusal bir ilişki olmadığını varsayar.

### 4.4 Veri toplama

Çalışma Sırbistan'daki yazılım şirketlerinde yapılmıştır. Sunucu, farklı bir ülkede yapılsaydı CSF'ler arasındaki etkileşimlerin farklı çıkabileceğini belirtti. Yazarlar CSF'lere ve geçmiş projelerin performans ölçütlerine ilişkin kapsamlı bir anket hazırlamıştır. Katılımcılar sektörde ortalama 14 yıl çalışmış proje yöneticileridir. Anketler her zaman doğru bilgi vermeyebileceği için yöneticilerle ayrıca birebir görüşülmüştür. Veri, büyüklük ve çalışan sayısı farklı 35 özel firmadaki 47 yazılım projesinden toplanmıştır.

### 4.5 Modeller

İki YSA modeli geliştirilmiştir:

- **Çok girdili tek çıktılı (MISO):** Girdi katmanında CSF'ler vardır (makalede 20; farklı modellerde artırılabilir). Çıktı genel proje başarısıdır. Katman sayısı testlerle belirlenmiştir. <!-- BELİRSİZ: altyazıda "altı katmanlı mimari" deniyor; bunun gizli katmandaki nöron sayısı mı katman sayısı mı olduğu kareden doğrulanamadı. -->
- **Çok girdili çok çıktılı (MIMO):** Çıktıda üç ayrı başarı değeri vardır: proje yönetimi başarısı, ürün başarısı ve stratejik başarı. Mimari yine testlerle belirlenmiştir (altyazıda "3 katmanlı").

Projeler önce K-means algoritmasıyla üç başarı boyutuna göre kümelenmiştir. Slayttaki tablo başlangıç ve son küme merkezlerini verir (ekrandan, 01:05:00):

| | Başlangıç 1 | Başlangıç 2 | Başlangıç 3 | Başlangıç 4 | Son 1 | Son 2 | Son 3 | Son 4 |
|---|---|---|---|---|---|---|---|---|
| PMS | 4.3 | 1.9 | 1.0 | 5.0 | 4.3 | 2.7 | 2.2 | 4.9 |
| PS | 5.0 | 4.8 | 1.0 | 5.0 | 4.7 | 3.9 | 1.3 | 4.9 |
| SS | 4.9 | 2.5 | 1.0 | 2.1 | 4.3 | 2.2 | 1.9 | 2.6 |

(PMS: proje yönetimi başarısı, PS: ürün başarısı, SS: stratejik başarı.) Değerler aynı ölçeğe getirilmiş, bir boyutta 4'ün üstündeki puan başarılı, altındaki başarısız kabul edilmiştir.

Eğitimde iki algoritma karşılaştırılmıştır: Resilient Backpropagation (Rprop) ve Scaled Conjugate Gradient (SCG). Karşılaştırma doğruluk ve çalışma süresi üzerinden yapılmıştır. <!-- BELİRSİZ: sunucu MISO için önce SCG'nin hem süre hem doğrulukta iyi olduğunu söyledi, sonra SCG'nin doğrulukta, diğer algoritmanın sürede iyi olduğunu söyleyerek düzeltti; MIMO için Rprop'un iki açıdan da iyi olduğu söylendi. Kesin dağılım kareden doğrulanamadı. -->

### 4.6 Sonuçlar

MISO modelinin doğruluğu yaklaşık 0,83'tür ve makale bunu kabul edilebilir bir başarı sayar. MIMO modelinin doğruluğu yaklaşık 0,72'dir. Genel olarak MISO daha iyi sonuç verir, ama MIMO'nun performansı da iyidir ve geliştirilebilir. Veri seti büyüdükçe daha iyi sonuçlar beklenir.

Sonuç slaytına göre (ekrandan, 01:10:00):

- CSF'ler arasında doğrusal olmayan ilişkiler ortaya konmuş ve bu ilişkiler kullanılarak YSA tabanlı proje sonucu tahmin modelleri oluşturulabileceği gösterilmiştir.
- Geleneksel olarak kullanılan uzman görüşü yönteminden de yararlanılmıştır.
- YSA modellerinin doğrusal modellerden daha doğru olduğu belirtilmiştir.

Hoca, bu konuda çok çalışma olduğunu, anketlerle bilgi toplamanın ve veri seti oluşturmanın zor olduğunu, sonuçları uzman görüşüyle birlikte yorumlamanın durumu çok daha netleştirdiğini söyledi.

> **Hocanın vurgusu:** Proje yönetimi araştırmalarında veri seti oluşturmak zordur; sonuçların uzman görüşüyle yorumlanması önemlidir.

## 5. Makine Öğrenmesiyle Yazılım Efor Tahmini ve COCOMO

Beşinci sunum, makine öğrenmesi teknikleriyle yazılım efor tahmini yapan 2018 tarihli bir konferans bildirisiydi (ekrandan, 01:15:00).

### 5.1 Problem

Yazılım tahmini (software estimation) yazılım mühendisliğinin en önemli faaliyetlerinden biridir. Zaman, efor ve maliyet tahmini gibi türleri vardır; bildiri efor tahminine odaklanır. Tahmin, sözleşme sürecinde ve kaynak ayrımında önemli rol oynar. Tahmin yöntemleri uzman tabanlı ve model tabanlı olabilir; fonksiyon noktası analizi, use case point analizi ve COCOMO örnektir. Bu modellerin hata payı yüksek olduğunda projeler gecikir ve ciddi bütçe aşımları olur. Bildiri yapay zekâ tabanlı modellerle daha iyi tahmin yapılıp yapılamayacağını araştırır: Naive Bayes, lojistik regresyon ve Random Forest'ın doğruluğu COCOMO ile karşılaştırılır.

### 5.2 COCOMO

COCOMO, Barry Boehm tarafından 1981'de geliştirilmiştir ve kod satırı sayısına dayanır. Projeler kod büyüklüğüne ve ekip özelliklerine göre üç tipe ayrılır. Doğruluk ve ayrıntı düzeyine göre üç model vardır:

- **Basic:** Efor yalnızca kod büyüklüğünden, deneyimle belirlenmiş $a$, $b$ sabitleriyle tahmin edilir.
- **Intermediate:** Denkleme projenin 15 özelliği eklenir. Her özelliğin önem derecesine karşılık gelen sayısal bir çarpanı vardır; bu çarpanlar Boehm'in deneyime dayalı olarak verdiği değerlerdir.
- **Detailed:** En karmaşık modeldir.

Bildiri Intermediate modeli kullanır.

> **Ek bilgi (derste anlatılmadı):** Basic COCOMO'da efor büyük olasılıkla $E = a \cdot (\text{KLOC})^{b}$ (adam-ay) biçimindedir; $a$ ve $b$ organik, yarı ayrık ve gömülü proje tiplerine göre değişir. Intermediate COCOMO'da bu değer, 15 maliyet sürücüsünün çarpımı olan efor ayarlama çarpanı (EAF) ile çarpılır: $E = a \cdot (\text{KLOC})^{b} \cdot \text{EAF}$.

### 5.3 Veri seti ve ön işleme

Veri seti NASA tarafından oluşturulmuştur. 1971-1987 arasındaki, çoğu şelale tabanlı yaklaşık 93 projenin verisini içerir. Her projenin adı, nerede geliştirildiği, gerçek eforu, kod satırı sayısı ve COCOMO sürücülerinin nominal değerleri vardır.

Ön işleme adımları (ekrandan, 01:20:00):

- COCOMO sürücülerinin nominal değerleri tabloya göre sayısal çarpanlara çevrilmiştir.
- Mod sabitleri önceden belirlenmiş COCOMO sabitlerine çevrilmiştir.
- 15 özellikten yeni bir özellik türetilmiştir: çarpanların hepsi çarpılıp logaritması alınmıştır.
- Gerçek efor üç sınıfa ayrılmıştır.
- Efor değeri çok uç olan 3 proje gürültü yarattığı için çıkarılmış, 90 proje kullanılmıştır.

Efor sınıfları tablosu (ekrandan, 01:20:00):

| Gerçek efor | Efor kategorisi | Örnek sayısı |
|---|---|---|
| Effort < 97 | Low | 30 |
| 98.8 <= Effort < 430 | Medium | 30 |
| Effort > 430 | High | 30 |

### 5.4 Sonuçlar

COCOMO bu veri setindeki projelerin önemli bir kısmında eforu kötü tahmin etmiştir. <!-- BELİRSİZ: COCOMO için söylenen hata oranı ("yüzde 21") ve "19 tanesi" ifadesinin neyi gösterdiği altyazıda net değil. --> Üç ML modeli kullanıldığında Random Forest önde gelmiştir. ROC eğrisine bakıldığında Naive Bayes, Random Forest'tan çok da kötü değildir, hatta bir miktar daha iyidir. Bildiri, bu veri setinde ML modelleriyle COCOMO'dan daha iyi efor tahmini yapılabildiğini göstermiştir.

Hoca, 2018'in bu konu için çok eski olmadığını, bu konuların 2000'lerin ortasında çok çalışıldığını söyledi. Ayrıca COCOMO II ile yapılmış bir örneğin dönemin ilk sunumlarında anlatıldığını hatırlatarak efor tahmininin önemli bir konu olduğunu belirtti.

## 6. Yazılım Geliştirmede Duygusal Takım Koçluğu

Altıncı sunum "Applying Emotional Team Coaching to Software Development" adlı, IEEE Software'de yayımlanmış bir makaleydi (ekrandan, 01:25:00). Sunucuya göre çalışma 2020'de yapılmış, 2021'de yayımlanmıştır.

### 6.1 Problem

Makalede İspanya'da bir kamu kurumu için dış kaynak (outsource) olarak çalışan, küçük ama on yılı aşkın deneyimli bir ekip incelenir. Ekip çevik yönteme (Lean Kanban) geçerek ürün çıkarma ve iş listesini tüketme açısından belli bir iyileşme sağlamıştır. Ancak bir süre sonra her iterasyondaki iyileşme istenen düzeyde olmamış, bitirilen her işten sonra bir sonraki sprintte motivasyonun düştüğü gözlenmiştir. Teoride retrospektiflerle iyileşmenin artması gerekir; bu olmadığı için duygusal takım koçluğu denenmiştir. Ekibi iki duygusal zekâ koçu analiz eder: biri psikoloji ve insan kaynakları alanında eğitimli, diğeri yazılım mühendisidir.

### 6.2 Duygusal zekâ ve takım lideri

Duygusal zekâ birden fazla zekâ türünden biridir. Kendini harekete geçirme, aksiliklere rağmen devam edebilme, dürtüleri kontrol edip tatmini erteleyebilme, ruh halini düzenleme, sıkıntının düşünmeyi engellemesine izin vermeme, empati ve umut besleme gibi yetenekleri kapsar. Bu kişisel bir özelliktir, ama ekibin de genel bir duygusal zekâya sahip olması gerekir. Ekip yalnızca bir iş ortaklığı değil, ortak hedefi olan bir bütün olmalıdır. Ortak hedef yoksa ya da ilişki yalnızca iş bazlıysa verim düşer. Üyeler arasında güven ve grup kimliği duygusu, birlikte çalışmanın ekipçe benimsenmesi gerekir.

Takım liderinin görevi ekibi teknik olarak yönlendirmenin yanında, ekipten geri bildirim alıp duygusal zekâsını geliştirecek biçimde yönlendirmektir. Lider ekibe bir ayna tutar. Koçluk yöntemlerinden ikisi kullanılır:

- **Ontolojik koçluk:** dilin ve kelimelerin dönüştürücü gücüne dayanır.
- **Sistemik koçluk:** bireysel performans yerine ekip performansını öne çıkarır.

### 6.3 ETEC süreci

Emotional Team Coaching Process (ETEC) beş oturumdan oluşur. İlk iki oturum teşhis, son üç oturum müdahale içindir. Slayttaki tablo (ekrandan, 01:30:00):

| Oturum | Amaç | Teknikler | Bulgular / sonuç |
|---|---|---|---|
| 1. İç algı | Ekibin kendini değerlendirmesi | Giriş (duygusal zekâ temel kavramları), nominal grup tekniği (NGT), TEI testi | İyi organize, verimli, iyi kişisel ilişkiler; izolasyon ve tehdit algısı, proaktivite ve dış ilişkiler geliştirilmeli |
| 2. Dış algı | Öz değerlendirmeyi dışarıdan değerlendirmeyle tamamlamak | Toplantı takibi, açık uçlu anket | İyi teknik etkileşim; iletişim sorunları, düşük çatışma çözme becerisi, dış destek eksikliği, motivasyon eksikliği, net hedeflerin yokluğu |
| 3. Büyümenin sınırları | Motivasyon eksikliğinin nedenlerini bulmak, proaktiviteyi artırmak | Takım görsel algısı, beyin fırtınası | Uzun süredir çalışmak motivasyonu düşürüyor; dış görünürlük asıl sorun |
| 4. Olası önlemler | İzolasyonu çözmek, görünürlüğü, iletişimi ve çatışma çözmeyi geliştirmek | Takım geri bildirimi, Philips 6-3-5 | Olumlu ve güvenli ortam; yeni teknolojiler, haftalık kahve toplantısı |
| 5. Eylem planı | Önceki hedeflere ulaşacak planı tanımlamak | Görsel proje planı, SMART hedefler, eylem planı takvimi | Yol haritası, takım ittifakı |

**Birinci değerlendirme (iç algı).** Ekibe anket soruları sorulur ve güçlü-zayıf yönler bulunur. Nominal grup tekniğinde herkes ekibin sorunlarını ve artılarını kâğıtlara bireysel olarak yazar, sonra bunlar oylanır. İki temel sorun çıkar: tehditlere karşı korku (proaktif davranamama) ve izole olma hissi. İzolasyon büyük olasılıkla dış kaynak olmalarından, çalıştıkları kuruma bağ hissedememelerinden kaynaklanır.

**İkinci değerlendirme (dış algı).** Koçlar da ekibi gözlemler. İki değerlendirmenin sonucu birbiriyle uyumludur: ekip içi ilişkiler iyidir ama genel bir motivasyon eksikliği vardır. Nedenler kurumsal ve bürokratik engeller, motive edici yeni projelere ihtiyaç, orta ve uzun vadeli hedeflerin yokluğudur.

**Büyümenin sınırları.** Koçlar her oturumun başında kısa bir eğitim verir, sonra ekibi kendi haline bırakıp gözlemler. Takım görsel algısında ekip üyeleri birbirini yaş ve kıdeme göre değerlendirir. Yaşın etkisi görülmez, ama kıdem arttıkça motivasyonun düştüğü gözlenir. Yeni katılanların motivasyonu görece yüksektir, ama düşük motivasyonlu kıdemli üyeler ekibi olumsuz etkiler. Beyin fırtınasında önce bağımsız, sonra birlikte fikir üretilir ve oylanır. İki eksiklik öne çıkar: ekibin görünürlüğü (yaptıkları işin kurum tarafından takdir edilmemesi, sahiplenilmemesi) ve aşırı bürokrasi.

**Olası önlemler.** Müşteriler ve danışman firma açısından ekibin görünürlük eksikliğini giderecek önlemler aranır. Ekibin geliştirmesi gerekenler proaktivite, sorun çözmede yaratıcılık, müşteri ve kendi şirketiyle ilişkilerdir (ekrandan, 01:40:00). Takım geri bildiriminde herkes diğer her üye hakkında iki olumlu ve bir geliştirilebilir yönü isimsiz olarak yazar, sonra bunlar birlikte değerlendirilir. İnsanlar olumsuz yönlerini zaten bilir ama kendilerine karşı acımasız oldukları için olumlu yönlerini göremez. Diğerlerinin gözünden olumlu yönlerini görünce motive olurlar. Philips 6-3-5 yönteminde her turda kişi başına beş dakikada üç fikir üretilir ve sonunda oylanır. Hoca bunun bir beyin fırtınası biçimi olduğunu belirtti; sunucu yöntemlerin çoğunun beyin fırtınası olduğunu, uygulanış biçimlerinin farklı olduğunu ekledi.

Slayttaki iki oylama tablosu (ekrandan, 01:40:00):

| Motivasyonu artıracak iyileştirme faktörü | Oy |
|---|---|
| Improve team visibility | 5 |
| Eliminate bureaucracy | 2 |
| Develop new projects | 1 |
| Incorporate new technology | 0 |
| Improve team policy with external staff (customer) | 0 |

| Eylem | Puan |
|---|---|
| Use of new methodologies/technologies | 6 |
| Lean coffee / work table | 4 |
| Area rotation with client | 2 |
| Increase empathy in the entire environment (client and contractor) | 1 |
| Rotation within the company (specialize) | 1 |
| Propose promotion of the direct manager | 0 |
| Group and individual positive attitude | 0 |

Ekip en çok puan alan iki eylemi seçer: yeni teknoloji ve metodolojilerin benimsenmesi ve düzenli kahve toplantıları.

**Eylem planı.** Ekip orta vadeli görsel bir proje planı hazırlar: amaç, yol haritası, sorumluluklar, kilometre taşları, aktörler ve takvim belirlenir.

### 6.4 Sonuçlar

Çalışma yaklaşık altı ay sürmüştür. Bu sürede motivasyonu düşük iki eski üye ekipten ayrılmış, yeni gelen üyeler işe daha çok sahip çıkmış ve motivasyon artmıştır. Ekip teknik bir hedef de koymuştur: bakımdaki sistemdeki her değişiklik için otomatik test yazmak. Bu hedef hem ekibin teknik doygunluğunu artırmış hem de bir meydan okuma yaratmıştır. Özetle ETEC ile ekibin ortalama motivasyonu artmış, üyelerin kariyer gelişimine ve sorun çözmedeki etkinliğine katkı sağlanmış, daha az toksik bir çalışma ortamı oluşmuştur.

Hoca bu sunuma özellikle daha fazla zaman ayırdığını, çünkü bu konunun teknik çalışanlar tarafından çoğu zaman göz ardı edildiğini ama projeleri çok etkilediğini söyledi. İnsanların kişisel durumlarının projeye etkisinin umulmayacak kadar büyük olabileceğini belirtti. Sunucu da yalnızca teknik açıdan bakmanın yetersiz kaldığını ekledi.

> **Hocanın vurgusu:** İnsanların kişisel ve duygusal durumları projeleri umulmayacak kadar etkileyebilir; bu konu teknik çalışanlarca çoğu zaman göz ardı edilir.

## 7. Makine Öğrenmesiyle Yazılım Proje Yönetimi: Sistematik Tarama

Yedinci sunum İngilizce yapıldı. Konusu "Software Project Management Using Machine Learning Techniques — A Review" adlı, 2021'de yayımlanmış bir sistematik literatür taramasıydı (ekrandan, 01:55:00). <!-- BELİRSİZ: bu sunumun ses kaydının bazı bölümlerinde altyazı Whisper tekrarlarıyla bozulmuş; bu bölümler slaytlardan ve okunabilen kısımlardan aktarılmıştır. -->

### 7.1 Taramanın kapsamı

Makale tek bir algoritmayı değil, yüzlerce makaleyi ele alır. Yazılım proje yönetiminde uygulanacak ML tekniklerini arayan araştırmacılar için bir yön haritasıdır. Slayttaki akış şemasına göre seçim şöyle yapılmıştır (ekrandan, 01:55:00):

- Sorgu: makine öğrenmesi, yapay zekâ, sınıflandırma, kümeleme, regresyon terimleri ile yazılım proje yönetimi, yazılım geliştirme, uygulama terimlerinin birleşimi
- Web of Science (n=520), ACM (n=315), IEEE Xplore (n=456); toplam 1291 makale
- Tekrarlar çıkarılır: 1291 − 426 = 865
- Başlık ve özet taraması: 865 − 519 = 346
- Tam metin okuma: 346 − 235 = 111
- Son küme: 111 makale

(Ara sonuçlar python ile doğrulandı.)

> **Ders sonrası not:** Sunucu ve slayt metni kaynakları "Web of Science, Science Direct ve IEEE Xplore" diye verdi; aynı slayttaki akış şemasında ise ikinci kaynak ACM olarak görünüyor (ekrandan, 01:55:00).

### 7.2 Yazılım proje yönetimi ve genel ML adımları

Proje yönetiminde her zaman bakılan üç kritik ölçüt vardır: proje zamanında bitti mi, bütçenin altında mı üstünde mi bitti ve beklenen çıktıyı sağladı mı. <!-- BELİRSİZ: üçüncü ölçüt altyazıda bozuk; slayt küçük resminden kalite/kapsam olduğu düşünülüyor. -->

ML'nin genel adımları şunlardır:

- **Veri toplama:** örneğin kelime belirteçleri (token).
- **Özellik çıkarma:** kelimelerin anlamını ölçmek için; örneğin terim sıklığı-ters belge sıklığı (TF-IDF).
- **Model kurma:** birçok algoritma kullanılabilir.
- **Uzman analizi:** çıktılar projelere uygulanmadan önce uzmanlarca yorumlanır.

Örnek bir süreçte farklı projelerin yöneticilerinden planlanan süre ve gerçekleşen süre toplanır, özellikler çıkarılıp model eğitilir. Eğitilmiş model başka projelerin başarı ya da başarısızlığını ölçmek için kullanılabilir.

### 7.3 Uygulama alanları

ML yazılım proje yönetiminin risk yönetimi gibi birçok alanında kullanılır. Örnekler: yazılım proje eforu ölçümünde çok katmanlı algılayıcı (MLP) ve SVM, yazılım maliyet tahmininde karar ağaçları. Her tekniğin kendi sınırlılıkları vardır. Örneğin k-en yakın komşu çok sayıda görevde otomatik efor tahmini için, sinir ağları kilit yönetim personelindeki yetkinlik açığını tahmin etmek için kullanılmıştır.

**Yazılım hata tahmini (SFP).** Slayta göre (ekrandan, 02:00:00) hata tahmini, yeni sürümler geliştirilmeden önce açık ya da gizli hataya yatkın modülleri bulmaktır. Artımlı teslime (ör. çevik) dayalı geliştirme süreyi kısaltır ve geliştiricilerle iş sahipleri arasındaki açığı azaltır, ama hızlı geliştirme hatalara yol açar. Bu yüzden SFP son kullanıcıyı memnun etmek için zorunlu bir adım olur, projeyi bitirmenin maliyetini düşürür ve sonraki sürümleri iyileştirir. Taramada atıf yapılan bir çalışmada özellik seçimi geliştirilmiş ikili güve-alev optimizasyonu (enhanced binary moth flame optimization) ile yapılmış, veri k-katlı olarak bölünmüş, modüller KNN, karar ağacı ve doğrusal ayırtaç analiziyle hatalı/hatasız diye sınıflandırılmıştır. Veri PROMISE deposundaki gerçek proje verileridir.

**Değer tabanlı karar verme.** Ürün yönetimi kararları yalnızca maliyete dayanmamalı, uzun vadeli değerleri de dikkate almalıdır; maliyet tabanlı karardan değer tabanlı karara geçiş gerekir. Bayes koşullu olasılık tablolarıyla (CPT) karar verme adımları şunlardır (ekrandan, 02:05:00):

- **A1. Şirkete özgü değer unsurlarını ortaya çıkarmak:** Paydaşlarla bireysel görüşmeler yapılır, görüşmeler yazıya dökülüp Grounded Theory ilkeleriyle analiz edilir.
- **A2. A1'in sonuçlarını karar toplantılarında araç desteğiyle kullanmak:** Paydaşlar karar toplantılarında kendi değer faktörlerini kullanır; her faktörün ölçümü, kararların bir gösterge paneliyle birleştirilmesi, toplantı başına kararların ve gerekçelerinin saklanması, paydaş görüşlerinin karşılaştırılması sağlanır.

Belirsizlik bulunduğu için Bayes CPT'leriyle değer tahmin modelleri kurulur ve bu modeller birkaç algoritmayla yarı otomatik üretilebilir. Böylece yöneticiler yeni bir özellik eklerken yalnızca sezgiyle değil, matematiksel olasılık verisiyle karar verebilir.

### 7.4 Zorluklar ve öneriler

Bir zorluk veri setidir: bulunan veri seti genel ve herkese açık olabilir, ama proje kuruma özeldir. Kurumun kendi projelerinden gelen veri ML için daha değerlidir, çünkü genel veri setleri kurumun projesini temsil etmeyebilir.

Taramanın önerileri bir şemada toplanmıştır; merkezde "Software Project Risk Assessment Recommendation" vardır (ekrandan, 02:10:00):

- **Software Effort Estimation:** hibrit model, veri homojenliği, use case point yöntemi, kümeleme yöntemleri, vaka tabanlı akıl yürütme
- **Expert Measures:** uzman paydaşların belirlenmesi, yazılım süreç modeli öneri yöntemi, kişiselleştirilmiş öneri mimarisi
- **Management Software Process:** çevik yazılımda değer tabanlı çatışmalar, çevik için otomatik tahmin yöntemi, hesaplamalı zekâ yöntemleriyle proje kontrolü, stratejik sürüm planlama (SRP)
- **Risk Prediction:** akıllı risk tahmin modeli, çevik tabanlı yazılım yönetimi, risk tahmin modelleri, credal ağa dayalı risk değerlendirmesi
- **Software Fault Prediction Models:** tahmin tabanlı yaklaşımlar, veri madenciliğiyle tahmin, maliyet kaymasını tahmin eden sınıflandırma modeli, örüntü keşfi, kusur tahmin modelleri, sınıflandırmayla arıza tahmini, projeler arası kusur tahmini (CPDP)

Hoca, ML'nin yazılım proje yönetiminde farklı alanlarda kullanıldığını, ilk olarak hata tahmininde başladığını, sonra yazılım başarısı ve kritik başarı faktörleri, risk belirleme, hata önleme ve ölçümlerde çok yaygınlaştığını söyledi. Bu sunumun bunların hepsini özetlediğini belirtti.

## 8. Proje Yönetiminde Zaman Planlaması ve Kaynak Tahsisi

Son sunum, 2019'da yayımlanmış ve proje yönetiminde zaman planlaması ile kaynak tahsisini ele alan bir makaleydi.

### 8.1 Giriş

Proje yönetimi, öngörülebilir maliyet, zaman ve nitelikle tanımlanmış değişiklikler ya da ürünler oluşturmak için özel bir düzenleme, planlama ve kontrol yoludur. Bunun için bir ekip ve gerekli araçlar gerekir. Zaman planlaması ve kaynak tahsisi projenin başarısını etkileyen iki önemli unsurdur. Kaynakların verimli yönetimi söz konusu olduğunda bunlar başarısızlığa yol açabilecek ciddi sorunlardır.

Makalede iki tür araştırma yapılmıştır. Birincisinde birkaç kurumsal kaynak planlama (ERP) sistemi incelenmiş, olumlu ve olumsuz yönleri belirlenip ölçütlere göre karşılaştırılmıştır. İkincisinde web ve grafik tasarım alanında çalışan küçük bir şirketin iş süreçleri anket ve görüşmelerle incelenmiş, kaynakları daha verimli tahsis edecek bir proje yönetim sisteminin işlevsel gereksinimleri çıkarılmıştır. Bu gereksinimlere dayanarak web tabanlı bir çözüm önerilmiştir. Çözümün amacı yöneticilerin ve ekiplerin işini kolaylaştırmak, müşteri ve geliştiricilerle iletişimi kolaylaştırmak ve projeyi başarısızlığa uğratabilecek gelişmeleri en aza indirmektir. Uygulama bağımsız bir sistem ya da bir ERP sisteminin proje yönetimi modülü olabilir.

### 8.2 Başlangıç soruları ve yöntem

Bir projeye başlarken sorulması gereken üç soru slaytta verilmiştir (ekrandan, 02:40:00):

- "Daha önce nasıldı?"
- "Nasıl olacak?"
- "Daha iyi nasıl yapılır?"

Birinci sorunun cevabı neye ihtiyaç duyulduğuna dair temel bir fikir verir. İkinci soru uygulamanın planlanması ve yapılandırılmasıyla iş süreçleri hakkında daha net bir görüş sağlar. Üçüncü soru için olası sorunlu durumlar ele alınıp değerlendirilir. Çalışmanın adımları işin gözlemlenmesi, çalışanlar ve yönetimle görüşmeler, şirket politika ve kurallarının incelenmesi, şirket belgeleri ve kullanılan yazılımlar hakkında bilgi edinilmesidir.

### 8.3 Mevcut süreç ve sorunlar

Şirketteki talep süreci şöyledir: müşteri talebini telefon ya da e-postayla yöneticiye iletir. Yönetici kısa ayrıntılarla proje yöneticisine e-posta gönderir. Proje yöneticisi teklifi hazırlar ve yönetici bunu müşteriye gönderir. Müşteri kabul ederse proje başlar, açık ve yeterli bir kapsam için müşteriyle birkaç toplantı yapılır. Kapsam hazır olunca proje yöneticisi görevleri ekip üyeleri arasında planlamaya başlar.

Gözlem ve görüşmelerle en kritik sorunlar tablolaştırılmış, her sorun için ilgilenecek kişi ve maliyet verilmiştir.

**Soru (hoca):** Buradaki maliyetlerin sembolleri ne anlama geliyor? **Cevap:** Sunucu, maliyetin sorunla ilgilenecek kişiye (proje yöneticisi ya da çalışan) göre verildiğini söyledi. <!-- BELİRSİZ: tablodaki maliyet sembolleri kareden doğrulanamadı. -->

Genel sorun şudur: çalışanlara proje hakkında çok az bilgi verilir, kendilerine verilen görevi ve günlük işlerini anlamakta güçlük çekerler. Proje yöneticileri ekip üyelerinin anlık olarak hangi görevde çalıştığını bilmek ister, ama elektronik tablolarla bu imkânsız hale gelmiştir. Bu yüzden yeni görev ve projelerin planlanması karmaşık ve öngörülemez olmuştur. Bu sorunlar yöneticileri, maliyet etkin kaynak tahsisi, daha kısa yürütme süresi ve daha yüksek gelir için yeni bir yaklaşım gerektiğine inandırmıştır.

Gecikmenin yaygın bir nedeni, müşterinin projenin belirli bir zamanda, bütçe dahilinde ve belirli performans düzeyinde bitmesini istemesidir. Bu ilişki maliyeti performans, zaman ve kapsamın fonksiyonu olarak gösteren bir denklemle ifade edilir:

$$C = f(P, T, S)$$

Burada $C$ maliyet, $P$ performans, $T$ zaman, $S$ kapsamdır. Parametrelerden birinin artması diğerlerini de etkiler; örneğin kapsamın genişlemesi kaynakları ve dolayısıyla maliyeti artırır. <!-- BELİRSİZ: denklemin slayttaki tam yazımı kareden doğrulanamadı; harfler altyazıdaki anlatımdan kurulmuştur. -->

### 8.4 Sistem gereksinimleri

Makalenin listesinden sunucunun seçtiği gereksinimler şunlardır:

- Sistem iş süreçlerinin kolay yönetimini, çalışanların faaliyetlerinin raporlanmasını ve kontrolünü sağlamalıdır.
- Hataları azaltarak, çalışma saatlerini optimize ederek ve görevleri önceliklendirerek bitmiş projeler üzerinde kontrol sağlamalıdır.
- Çalışanların kontrolü ve öz kontrolü için bir yol sunmalıdır.
- Müşterilere doğru güncellemeler ve raporlar sunabilmeli, gerekirse müşterilere dosyalarına erişim verebilmelidir.
- Görevlerin daha iyi planlanması için mevcut projelerin hızlı ve anlaşılır bir görünümünü vermelidir.
- En önemli gereksinim zaman içinde sürdürülebilirliktir: şirket büyüdükçe sistem de ihtiyaçlara göre gelişebilmeli ve şirketin gelişimini durdurmamalıdır.

### 8.5 Önerilen çözüm ve sonuçlar

Önerilen çözümün mimarisi, daha fazla modül eklemeye ve eksiksiz bir ERP sistemine genişlemeye imkân veren üç katmanlı bir mimaridir (ekrandan, 02:45:00). Nihai hedef şirketin tüm iş süreçlerini yönetebilecek kendi ERP sistemine sahip olmasıdır. ERP sistemi operasyonel ve temel modüller içerir; temel modüller, operasyonel modüllerin birlikte çalışması için gereken bütün bilgileri tutar. Web tabanlı çözümde müşteriyle ilgili birimler istemci (client) modülüne yerleştirilmiştir. Yapının esnekliği, mevcut uygulamaya zarar vermeden yeni modül eklenmesine izin verir.

Çözüm, girdi verilerini merkezde toplayıp ilgili taraflara gerçek zamanlı göstererek proje başlatma sürecini hızlandırır. İlk aşamada gereksiz e-postalara harcanan zamanı ve bilginin yanlış aktarılma olasılığını azaltır. Modüller bağımsız olsalar da sürekli senkronize çalışır; yöneticiler mevcut projeleri ve aşamalarını izleyebilir, yenilerini planlayabilir.

Sonuçlar:

- Arayüz kolay olduğu için çalışanların eğitimi kısa sürmüştür.
- Yöneticiler dosya ve belgelere kolay erişimden memnun kalmıştır.
- Bütün proje ve görevler şirketin toplam yükünü gösteren tek bir plan şemasında izlenebilmiş, yeni proje ve teslim tarihlerinin planlanması daha öngörülebilir olmuştur.
- Yeni bir talebi işleme koyma ve teklif verme süresi kısalmış, reddedilen sipariş sayısı azalmıştır. <!-- BELİRSİZ: teklif süresindeki azalma oranı altyazıda "8 eski" diye bozuk. -->
- Şirket web tabanlı çözümler geliştirdiği ve uzaktan çalışmaya izin verdiği için web tabanlı çözüm seçilmiştir; sistem konum, cihaz ya da ağ kısıtı olmadan erişim sağlar.

Makaleye göre önerilen çözüm küçük ve orta ölçekli işletmeler içindir, ama büyüklük ve proje sayısından bağımsız olarak her işletmenin ihtiyacına göre dönüştürülüp genişletilebilir.

## Örnek Sorular

**1.** (derste sözlü, 00:22:27) Yazılım proje çizelgeleme çalışmalarında asıl planlanan kaynak nedir?

> **Cevap (derste verildi):** Yazılım projelerinde en önemli kaynak insandır. Çizelgeleme modelleri çalışanların becerilerini, maaşlarını ve ayırabildikleri zamanı görevlerin gerektirdiği beceri ve eforla eşleştirir; yani asıl yapılan insan kaynağının planlanmasıdır.

**2.** (derste sözlü, 00:27:59) Yazılım proje çizelgeleme probleminde optimizasyon tek amaçlı mı, çok amaçlı mı yapılır?

> **Cevap (derste verildi):** İkisi de vardır. İncelenen 30 makalenin 18'inde hedef yalnızca maliyet ve süredir; diğerlerinde fazla mesai, beklenen hata sayısı ya da parçalanma gibi ek hedefler eklenir ve çok amaçlı genetik algoritma (MOGA) gibi çok amaçlı yöntemler kullanılır.

**3.** (ekrandan, 00:30:00) 5, 10, 15 ve 20 çalışan; 10, 20 ve 30 görev; 5 ve 10 global beceri; çalışan başına 4-5 ya da 6-7 beceri seçenekleriyle kaç farklı yapay proje örneği üretilir?

> **Çözüm (derste verilmedi):** Seçenek sayıları çarpılır: $4 \times 3 \times 2 \times 2 = 48$. Bu sonuç slayttaki 48 yazılım projesiyle uyumludur.

**4.** (ekrandan, 01:55:00) Taramada üç veri tabanından 520, 315 ve 456 makale bulunmuş; 426 tekrar, başlık-özet taramasında 519 ve tam metin okumada 235 makale elenmiştir. Son kümede kaç makale kalır?

> **Çözüm (derste verilmedi):** $520 + 315 + 456 = 1291$; $1291 - 426 = 865$; $865 - 519 = 346$; $346 - 235 = 111$. Son kümede 111 makale kalır.

**5.** (ekrandan, 02:40:00) Bir projeye başlarken sorulması gereken üç soru nedir ve her biri ne sağlar?

> **Cevap (derste verildi):** "Daha önce nasıldı?" sorusu neye ihtiyaç duyulduğuna dair temel fikri verir. "Nasıl olacak?" sorusu planlama ve yapılandırmayla iş süreçlerini netleştirir. "Daha iyi nasıl yapılır?" sorusu olası sorunlu durumların ele alınmasını sağlar.

**6.** (derste sözlü, 02:41:42) Sorun tablosundaki maliyetler neye göre belirlenmiştir?

> **Cevap (derste verildi):** Maliyet, sorunla ilgilenecek kişiye (proje yöneticisi ya da çalışan) göre verilmiştir. <!-- BELİRSİZ: tablonun kendisi kareden doğrulanamadı. -->

## Dersin Toparlaması

Bu derste sunulan makaleler yazılım proje yönetiminin üç ana eksenini birlikte gösterdi. Birinci eksen süreç modelleridir: büyük ölçekli çevik çerçeveler (SAFe, LeSS, Scrum at Scale, DAD) ve şelale ile Scrum'ı birleştiren hibrit modeller, tek bir metodolojinin her projeye uymadığını ve modelin proje ölçeğine, karmaşıklığına ve kültüre göre seçilmesi gerektiğini gösterdi. İkinci eksen planlama ve tahmindir: yazılım proje çizelgeleme problemi insan kaynağının görevlere atanması olarak modellenip genetik ve sürü zekâsı algoritmalarıyla çözülüyor; efor tahmini ve proje başarısı tahmini için COCOMO gibi klasik modellerin yerini giderek YSA, Random Forest gibi makine öğrenmesi yöntemleri alıyor. Zaman planlaması ve kaynak tahsisi için web tabanlı, ERP'ye genişletilebilir sistemler küçük şirketlerde bile somut kazanç sağlıyor.

Üçüncü eksen insan faktörüdür. Duygusal takım koçluğu sunumu, motivasyon, görünürlük ve bürokrasi gibi teknik olmayan etkenlerin ekip verimini doğrudan belirlediğini gösterdi. Hoca da bu konunun teknik çalışanlarca çoğu zaman göz ardı edildiğini ama projeleri umulmayacak kadar etkilediğini vurguladı. Bütün sunumlarda ortak bir sorun olarak, proje yönetimi araştırmalarında güvenilir veri toplamanın zorluğu ve sonuçların uzman görüşüyle yorumlanmasının önemi öne çıktı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
