# Ders 1 Genişletilmiş Notu: Yapay Zekaya Giriş (Devam), Tarihçe ve Etmenler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersin Hatırlatması: Turing ve Searle
- 2. Ned Block'un Soru-Cevap Ağacı
- 3. Rudolf Arnheim: Yöntem Sorunu
- 4. Hesaplama Gücü Grafiği
- 5. YZ Savunucuları: İki Ekol
- 6. YZ Karşıtları ve Turing-Searle Karşılaştırması
- 7. Yapay Zekanın Kısa Tarihi
- 8. Günümüz
- 9. Kimine Kolay, Kimine Zor
- 10. Yapay Zeka ve Doğal Zeka
- 11. Etmenler (Ajanlar) ve PEAS
- 12. Ortam Özellikleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Önceki Dersin Hatırlatması: Turing ve Searle

Bu derste geçen hafta başlanan yapay zekaya giriş slaytı tamamlandı, ardından kısa bir "etmenler" slaytı işlendi. Hoca önce geçen haftayı hatırlattı: Zekanın ne olduğu tartışılmıştı. Bir düşünce deneyi yapılmıştı: Zamanda geriye gidip birine bir bilgisayar göstersek ona zeki der mi, sonra bilgisayarın nasıl çalıştığını açıklasak yine zeki der mi? Ya da ders anlatan biri maskesini çıkarıp bir Android olduğunu gösterse ona hâlâ zeki der miyiz? Bir sisteme zeki demek için nelere baktığımız ve fikrimizi neyin değiştirdiği konuşulmuştu.

Bu tartışmada iki temel yaklaşım vardır:

- **Turing:** Bir sistemi zeki saymak için dışarıdan ölçebildiğimiz davranışlarına bakmalıyız. Dışarıdan bakıldığında zeki bir varlıktan ayırt edilemiyorsa ve o sistem bir makineyse, neyden ve nasıl yapıldığına, arka planda neler döndüğüne bakmadan ona zeki demeliyiz.
- **Searle:** Çin Odası benzetmesinde girdi gelir ve belli kurallara göre çıktı verilir. Sistem girdi hakkında hiçbir bilgiye sahip olmadan yalnız kurallarla çıktı üretir; bu yüzden ona zeki diyemeyiz. Sürece, yani düşünce şekline de bakmak gerekir.

Kısaca bir tarafta sonuç, diğer tarafta süreç vardır. Geçen hafta Turing testi, ELIZA, Searle'ün Çin Odası ve "iki öğrenci" örneği de işlenmişti. İki öğrenci örneğinde bir öğrencinin çok daha hızlı olması, yalnız sonuca odaklanırsak bazı kritik şeyleri kaçırabileceğimizi, sürecin de önemli olduğunu vurguluyordu.

## 2. Ned Block'un Soru-Cevap Ağacı

Slayttaki ifadeler şöyledir (ekrandan, 00:10:00):

- X saatten az her mümkün söyleşinin içinde yer aldığı bir ağaç yapısı.
- Belki de depolayamayacağımız kadar büyük ama varsayalım ki elimizde.
- Zeka yalnızca soruları zeki bir insandan ayırt edilemeyen bir yolla yanıtlama yeteneği değildir.
- Bir davranışı zeki diye adlandırmak bu davranışın nasıl üretildiği hakkında bir önermede bulunmaktır.

Hoca düşünce deneyini şöyle anlattı: İki insan arasında, örneğin 10 dakika içinde geçebilecek bütün diyalogları bir yerde topladığımızı varsayalım. Bu korkunç büyük bir şey olacaktır, ama toplayabildiğimizi varsayalım. Bu veritabanının üzerinde "şunu dediyse şunu de; şundan önce şunu, sonra şunu dediyse şimdi şunu de" gibi temel ve basit kurallarla girdi-çıktı üretimi yapalım. Bu tam olarak Searle'ün Çin Odası'nda yapılan şeydir. Böyle bir sistemin gerçekten mümkün olup olmadığı tartışılır, ama var olduğunu varsayarsak kural tabanlı bu yapı Turing testini geçebilir.

Block'a göre Turing testini geçmiş olması bu sistemin zeki olduğunu göstermez, çünkü arka planda yaptığı tek şey kuralları işletmektir. Bu yüzden Block, zekanın yalnızca sonuçla tanımlanamayacağını, davranışın nasıl üretildiğine de bakmamız gerektiğini söyler. Hoca, Block'un temelde Searle ile aynı şeyi söylediğini vurguladı.

## 3. Rudolf Arnheim: Yöntem Sorunu

Benzer bir fikre sahip Rudolf Arnheim kritik bir cümle kurar: Zekanın çözebildiği her problemin yalnızca zeka ile çözüleceğini söyleyemeyiz. Yani elinizdeki bir problemi zekayı kullanarak da, zeka kullanmadan da çözebilirsiniz. Bu yüzden bir sistemin zeki olup olmadığına karar vermek için problemi çözüp çözmediğine bakmak yeterli değildir.

Arnheim'ın iki koşulu vardır. Bunlar sağlanmadıkça bilgisayarların kullandığı yönteme ya da davranışlarına zeki diyemeyiz:

- **Zihinsel süreçler çıktılar aracılığıyla tanımlanmadıkça:** Yani Turing'in görüşünü kabul etmedikçe.
- **Zekanın işleyişine dair görüşümüz mekanist bir niteliğe kavuşmadıkça:** İnsan zekasının nasıl çalıştığının bir algoritmasını günün birinde bulursak bu koşul sağlanır.

Arnheim'a göre bilgisayarların kullandığı yöntem, başarılı bir tepki bulunana kadar olası birçok tepki arasında körlemesine koşmaktır. Bu bilgisayarların yalnızca daha hızlı olduğunu gösterir; "daha zeki" sıfatı onlara yakışmaz.

## 4. Hesaplama Gücü Grafiği

Hoca 1997'de çizilmiş bir grafik gösterdi (ekrandan, 00:15:00). Grafiğin başlığı "Evolution of Computer Power/Cost", dikey ekseni "MIPS per \$1000 (1997 Dollars)", yani 1000 dolarlık maliyet karşılığında saniyedeki milyon işlem sayısıdır. Eksen logaritmiktir; değerler 1 milyarda birden (1/Billion) milyona (Million) kadar uzanır. Yatay eksende 1900'den 2020'ye yıllar vardır.

Grafikteki her nokta bir bilgisayar ya da bilgi işlem sistemidir. Soldan sağa Monroe Calculator, IBM Tabulator, Burroughs Class 16, Zuse-1, ASCC (Mark 1), Colossus, ENIAC, UNIVAC I, IBM 704, IBM 7090, CDC 7600, DEC PDP-10, Apple II, IBM PC, Commodore 64, Macintosh-128K, Mac II, Gateway-486DX2/66, PowerMac 8100/80, Gateway G6-200 gibi sistemler görülür. Yıllar ilerledikçe işlem gücünün sürekli arttığı görülür. Grafiğe 1965, 1975, 1985 ve 1995 trend çizgileri eklenmiştir; zaman geçtikçe trend daha dik yükselir.

Grafiğin sağ tarafında "Brain Power Equivalent per \$1000 of Computer" başlığıyla aşağıdan yukarıya Manual Calculation, Bacterium, Nematode Worm, Spider, Lizard, Mouse, Monkey ve Human basamakları vardır. Hoca grafiğin ne anlattığını sordu.

**Soru:** Bu grafik ne anlatmaya çalışıyor? **Cevap:** Bir öğrenci, bilgisayarın hesaplama gücünün bir canlının beyin gücüyle karşılaştırıldığını söyledi. Hoca bunu doğruladı: 1965 trendine göre bilgisayarlar 2020'de maymun düzeyine, 1995 trendine göre insanın da üzerine çıkıyordu.

Hoca bu karşılaştırmayı açıkça eleştirdi. İnsan beyninin gücünü bilgisayarın işlem gücüyle karşılaştırmak makul değildir, çünkü bilgisayarlar dijital ve ayrıktır, canlıların beyni ise sürekli bir sistemdir. Sürekli bir ortamdaki işlem sayısını saymak ve "10-20 yıl sonra insan beyninin gücüne ulaşacağız" demek komik kaçar. Ayrıca çok fazla işlem yapabilmek zekanın gücünü göstermez. Grafik yalnız tarihsel bir örnek olarak gösterildi.

## 5. YZ Savunucuları: İki Ekol

Yapay zeka ile uğraşanlar iki ekole ayrılır. Burada "aşağı" donanımı, "yukarı" yazılımı temsil eder.

### 5.1 Aşağıdan yukarıya yaklaşım

Bu yaklaşıma göre beynin fiziksel yapısının önemi vardır ve onu taklit etmeliyiz. Beyin sinir ağlarından oluştuğu için işimize yarayan makineleri ancak yapay sinir ağlarıyla üretebiliriz. Yapay sinir ağları beynin fiziksel yapısının bir karikatürüdür; birebir kopyası değildir, ama belli açılardan ona benzer.

### 5.2 Yukarıdan aşağıya yaklaşım

Bu yaklaşıma göre simgesel temsil yapılarına ve düşünme kurallarına odaklanmalı, beynin fiziksel yapısına takılmamalıyız. Problem çözmek için kullanabileceğimiz yapay sinir ağları dışında birçok araç vardır. Önümüzdeki haftalarda işlenecek arama algoritmaları, mikrodünyalar ve çerçeveler (frame) bu yaklaşıma aittir.

Hoca bunu geçen hafta konuşulan uçma benzetmesiyle açıkladı: İnsanlar uçakları yaparken kuşların kanatlarını model aldılar, ama uçaklar kanat çırparak uçmaz. Doğadaki bir çözümü alıp birebir kullanmak zorunda değiliz. Amaç problem çözmektir ve tek bir yönteme takılmanın anlamı yoktur. Makine öğrenmesi ve yapay sinir ağlarına dersin son haftalarında bir miktar girilecektir.

## 6. YZ Karşıtları ve Turing-Searle Karşılaştırması

### 6.1 YZ karşıtları

- **Searle:** Sentaks tek başına, ne miktarda olursa olsun, semantiği ortaya çıkarmaz. Bilgisayar ve içerikleri simgelerin anlamlarına dair hiçbir anlayışa sahip değildir. Anlam yoksa zeka da yoktur.
- **Gödel teoremi:** Hoca Kurt Gödel'in adını duyan olup olmadığını sordu; bir öğrenci matematikçi olduğunu söyledi. Hocanın aktardığı biçimiyle teorem, insanların doğruluğunu bildiği ama makinelerin ispatlayamadığı doğruların var olduğunu matematiksel olarak gösterir. Çok büyük yankı uyandırmış ve çok farklı yorumlanmıştır.
- **John Lucas'ın yorumu:** Böyle doğrular olduğuna göre insan zihni her zaman makine kapasitesinin üzerinde kalacaktır.

> **Ders sonrası not:** Hoca teoremi "insanların doğruluğunu bildiği ama makinelerin ispatlayamadığı doğrular vardır" diye aktardı. Gödel'in eksiklik teoremi aslında yeterince güçlü ve tutarlı her biçimsel sistemde, o sistem içinde ispatlanamayan doğru önermeler bulunduğunu söyler. İnsan zihninin makineden üstün olduğu sonucu teoremin kendisi değil, büyük olasılıkla Lucas'ın (ve sonra Penrose'un) yorumudur.

### 6.2 Turing ve Searle karşı karşıya

Slayttaki ifadeler şöyledir (ekrandan, 00:20:00):

- Turing: "Makineler düşünebilir mi?" sorusu felsefi bir yaklaşımdan ziyade deneysel bir yaklaşımla ele alınmalı, çünkü ilki sonuç vermiyor.
- Searle: Deneysel bir yaklaşım olamaz, çünkü bir programı takip eden şey asla düşünemez.
- ?: İnsanlar da bir programı takip ediyor olabilirler mi?

Hoca felsefi yaklaşımın neden sonuç vermediğini açıkladı. Felsefi yaklaşım arka planda neler olup bittiğine odaklanır. Bir sistem kurup onun insan gibi düşündüğünü iddia ettiğimizi varsayalım. Bunu sonuçlara bakarak değil arka plandaki mekanizmalara bakarak ölçeceksek, bu mekanizmaların insanın mekanizmalarına benzediğini göstermemiz gerekir. Sorun şudur: İnsanın nasıl düşündüğünü henüz bilmiyoruz. Karşılaştırma yapacağımız şeye dair yeterli bilgimiz yoktur. Turing'i dışarıdan bakılan şeylere bakmaya yönelten budur. Hocaya göre Turing de kural tabanlı bir yapının zeki olmayacağını diğerleri kadar düşünebiliyordu, ama insanın konuşması, hareketleri gibi dışarıdan görülen davranışlarını ölçme imkanımız varken içeride nasıl üretildiklerini ölçme imkanımız yoktur.

Searle ise çıktıları insandan ayırt edilemiyor diye bir sisteme zeki denemeyeceğini söyler; tıpkı Arnheim'ın dediği gibi, zekayla çözülebilen bir şeyin illa zekayla çözüldüğünü iddia edemeyiz. Arka plandaki mekanizma çok basitse çıktılar insandan ayırt edilemese de buna zeki denemez.

Slayttaki soru işareti Arnheim'ın ikinci koşuluna bağlanır: İnsan düşüncesine dair bakışımız mekanist bir niteliğe kavuşursa, yani insanın da bir programı takip ettiği gösterilirse, bu tartışmaların bir anlamı kalmaz. Zeka ile yapay zeka arasında fark kalmaz, "yapay" sözcüğü kaldırılabilir. Ama hoca, ona hâlâ zeka deyip demeyeceğimizin çok tartışmalı olduğunu ekledi.

## 7. Yapay Zekanın Kısa Tarihi

Slayttaki tarih 1943'te başlar, ama insan gibi davranabilen sistemler kurma hayali çok daha eskidir. Eski teknolojiyle çok fazla bilgiyi yüksek doğrulukla ve hızla işlemek mümkün değildi.

**Soru:** Teorik olarak bir bilgisayarı tamamen tahtalardan, çarklardan, zincirlerden yapabilir misiniz, yaparsanız nasıl bir şey olur? **Cevap:** Teorik olarak yapılabilir. Ama korkunç derecede büyük olur; öğrencilerin dediği gibi çok yavaş ve pahalı olur. Ayrıca güvenilir olmaz: uzun süre çalıştırıldığında sürekli hatasız sonuç vermesi zordur. Stabil çalışan ve maliyeti uygun bir sistemin bilgi işleme kapasitesi düşük ve yavaş kalıyordu.

Fikirler birikmişti; onları uygulamak için teknolojinin gelişmesi gerekiyordu. Bu süreç 1940'ların ortasında başladı. İlk bilgisayarlar vakum tüplüydü ve çok büyüktü; transistörün icadıyla her şey küçüldü.

### 7.1 İlk adımlar (ekrandan, 00:25:00)

- **1943: McCulloch ve Pitts, ilk yapay nöron tasarımı.** Aşağıdan yukarıya yaklaşımın başlangıcıdır. Motivasyon şuydu: Bir nöron yaptık, bir tane daha, bir tane daha yapacağız; çok sayıda nöronu birbirine bağlayıp yapay bir beyin ortaya çıkaracağız.
- **1949: Hebbian öğrenme kuralı.** İki nöron aynı anda aktif olurlarsa aralarındaki bağ güçlenir.
- **1950: Turing'in makalesi.**
- **1951: İlk yapay sinir ağı bilgisayarı (Minsky ve Edmonds).** Tek bir nörondan değil çok sayıda nörondan oluşan, perceptron diye ifade edilebilecek tek katmanlı bir yapıdır; yapay sinir ağlarının atası sayılabilir.

### 7.2 Hebbian öğrenme ve Pavlov'un köpeği

Hebb kuralı bilinen bir olgunun fizyolojik olarak nasıl gerçekleştiğini açıklar. Hoca Pavlov'un köpeklerini (klasik koşullanma) hatırlattı. Bir köpeğe zil çalınır, bir şey olmaz. Sonra bir sürece başlanır: Zil çaldıktan sonra yemek verilir; ertesi gün yine aynı şey yapılır. Belli bir koşullanma sürecinden sonra köpek, yemek verilmese bile zil sesinden sonra salya akıtmaya başlar. Salya, yemeğin geleceği beklentisinin göstergesidir.

Burada zil sesi ile yemek beklentisi arasında önceden olmayan bir ilişki kurulmuştur. Hebb'e göre fizyolojik olarak şu olur: Zil sesini duyunca aktifleşen bir nöron kümesi, yemeği görünce aktifleşen ve salya salgılatmaya başlayan başka bir nöron kümesi vardır. Başlangıçta aralarında bağlantı yoktur. Koşullanma sürecinde bu iki küme aynı anda (ya da aralarında kısa bir süre farkla) aktif olur ve aralarında önceden olmayan ya da çok zayıf olan bir sinirsel yol oluşur ya da güçlenir. Bundan sonra zil çalınınca zili duyan nöronlar aktifleşir, bağlantılı oldukları yemek nöronlarına sinyal gönderir; onlar da doğal bağlantıyla bağlı oldukları salya salgılatan motor nöronlara haber verir.

Bu tanıma göre öğrenme, beynimizdeki nöronlar arasındaki bağlantıların değişmesi, güçlenmesidir. Unutmak da kabaca bağlantının giderek zayıflaması ya da kopması gibi düşünülebilir. Bu fikir yapay sinir ağları için önemlidir: Yapay sinir ağı modellerinde öğrenme, ağırlıkların değişimiyle tanımlanır ve simüle edilir.

### 7.3 1950-1966: Büyük beklentiler dönemi (ekrandan, 00:35:00)

Teknolojik gelişmeyi gören araştırmacılar çok büyük beklentilere girdi: "Yapay nöronu yaptık, yakında insan beyninin modelini yaparız." Slayttaki öngörüler şunlardır:

- **1950, Turing:** 50 yıl içinde sıradan sorgulayıcıların en az yüzde 30'u 5 dakikalık bir diyalogdan sonra doğru kararı veremeyecek. Yani Turing testi 50 yıl içinde (5 dakikalık diyalog için) geçilecekti. Bu gerçekleşmedi.
- **1957, Newell ve Simon:** On yıl içinde dünya satranç şampiyonu bir bilgisayar olacak. Bu 10 yıl içinde değil, yaklaşık 40 yıl sonra, 1997'de gerçekleşti.
- **1950-60 arası:** Otomatik dil çevirisi çok yakınımızda. Bu da yakında gerçekleşmedi. Bugün çeviri sistemleri çevirmenler kadar başarılı değil, ama üzerinde düzeltme yapmak gerekse de oldukça işe yarar araçlar haline geldiler.

### 7.4 Beklentiler neden gerçekleşmedi?

Slayt 28'de üç sebep sayılır:

- **Dünya (sağduyu) bilgisinin büyük etkisi:** İnsan zekasında dünya hakkındaki bilginin çok büyük etkisi olduğu görüldü. Bu konuya slaytın sonunda dönüldü.
- **Problemlerin karmaşıklığının üstel olması:** Satranç şampiyonunun 10 değil 40 yıl sonra yenilmesinin sebebi tamamen donanımdır. Arama uzaylarının ne kadar büyüyebildiği ve bu uzaylarda arama yapmanın maliyeti ileride oyunlar konusunda görülecektir.
- **Kısıtlı dünyaların gerçek dünyaya model olamaması:** Hoca şu örneği verdi: Ekranda bir robot kolu ve çeşitli nesneler bulunan bir simülasyonda "kırmızı küpün altındaki yeşil dikdörtgen prizmayı al, mavi üçgen prizmanın altına koy" gibi komutları anlayan bir sistem yapmak çok zor değildir, çünkü dünya kısıtlıdır ve o dünya için tanımlı her komut anlaşılabilir. Aynı sistemi gerçek dünyada uygulamaya kalkınca başınıza çok iş gelir. Simülasyon ne kadar gerçekçi olursa o kadar iyileşir, ama oradaki çözümü gerçek dünyaya doğrudan aktarmak pek mümkün değildir. Robotlarla uğraşanlar simülasyonda çalışan şeylerin gerçek dünyada o kadar iyi çalışmadığını, eğitimin farklı olması gerektiğini birinci elden gözlemlemiş olabilir.

### 7.5 1966-1973: Biraz da gerçekler (ekrandan, 00:40:00)

Slayttaki maddeler şunlardır:

- 1969: Minsky ve Papert'in yapay sinir ağlarının birçok problem türünde başarısızlığını kanıtlamaları, yapay sinir ağları çalışmalarına ayrılan fonların durdurulması.
- 1969: Bryson ve Ho, çok katmanlı yapay sinir ağlarını keşifleri, bir eğitim algoritması olmayışı sebebiyle 1980'lere kadar ilgi çekmemesi.
- Otomatik çeviri sistemlerinde hüsran: "the spirit is willing, but the flesh is weak" cümlesi İngilizceden Rusçaya çevrilip geri çevrildiğinde "the vodka is good but the meat is rotten" olmuştur.

Hoca bunu şöyle açıkladı: Minsky ve Papert'in kitabı yapay sinir ağlarının hangi problemleri çözemeyeceğini gösterdi; bu yüzden yapay sinir ağlarına ayrılan fonlar durdu, alan gözden düştü. Örneğin tek katmanlı bir sinir ağı (perceptron) doğrusal olmayan bir problemi, mesela XOR'u çözemez. Öte yandan gizli katmana sahip iki katmanlı ağların bu problemleri çözebildiği gösterildi. Ancak bu ağların nasıl eğitileceği, yani ağırlıkların nasıl belirleneceği bilinmiyordu. Bugün standart olarak kullanılan geri yayılım (backpropagation) algoritması yoktu. Çözebildikleri, ağırlıklar elle hesaplanarak gösterildi: "Şu ağırlıklara sahip bir ağ bu problemi çözebiliyor." Ama rastgele ağırlıklardan başlayıp ağırlıkları istenen yere getiren bir algoritma yoktu. Bu yüzden alan 1980'lere kadar ilgi çekmedi; 1980'lerin ortasından sonra geri yayılım algoritmasının ortaya çıkmasıyla yapay sinir ağları yeniden kullanılmaya başlandı.

Otomatik çeviride ise soğuk savaş döneminde Rusça metinlerin İngilizceye çevrilmesi çok önemliydi ve bunu yapacak yeterli insan yoktu. DARPA bu alanda çok ciddi projeler destekledi, ama o zamanın teknolojisi ve bilgisiyle istenen seviyeye ulaşılamadı.

> **Ek bilgi (derste anlatılmadı):** XOR'da $(0,0)$ ve $(1,1)$ girdileri 0, $(0,1)$ ve $(1,0)$ girdileri 1 çıktısı verir. Bu iki sınıfı düzlemde tek bir doğruyla ayırmak mümkün değildir; tek katmanlı perceptron ise yalnız doğrusal bir sınır çizebilir. Bu yüzden XOR için en az bir gizli katman gerekir.

### 7.6 1979-1990: Güzel zamanlar

Hüsran döneminden sonra uzman sistemler ortaya çıktı. Bunlar kural tabanlı, insanlar tarafından kolayca anlaşılabilen ve kısıtlı alanlarda uzmanlık görevi gören sistemlerdir. Genel amaçlı bir yapay zeka değil, belli bir problemi çözen sistemlerdir; kural tabanlı ya da başka tabanlı olmaları o kadar önemli değildir. Önemli olan kısıtlı alanlarda uzmanlık görevi gören sistemler geliştirilmeye başlanmasıdır.

Japonya 1981-1991 arasında Prolog temelli çalışan zeki makineler üretmek için Fifth Generation projesini başlattı. Buradaki "makine", Prolog'u çok daha hızlı işleyebilecek donanımsal çiplerdir; Prolog sayılar yerine doğrudan yüklemler (predicate) üzerinde çalıştığı için bunları hızlı işleyecek donanımlar hedeflendi. O dönemde Japonya minyatürleştirme, çip haline getirme ve düşük maliyetli üretimde Amerika ve Avrupa'yı geride bırakmıştı. Amerika ve Avrupa aynı yenilgiyi yapay zekada yaşamamak için yapay zeka projelerine yeniden büyük paralar yatırdı. Yazılımda yeni klişe "now with AI" oldu ve yapay zeka firmalarının sayısı büyük bir artış gösterdi. Hoca bugün de buna benzeyen bir dönemde olduğumuzu, bir sonraki hüsran döneminin ne zaman geleceğini bilmediğimizi ekledi.

### 7.7 Yaklaşık 1991-1995: YZ kışı (ekrandan, 00:45:00)

- Fifth Generation durduruldu; istenen sonuçlara ulaşılamadı.
- YZ endüstrisinde yeni odak: insanların yerini tamamen alabilecek programlar üretmeye çalışmak yerine uygun problemlere YZ tekniklerini uygulamak ve insanları destekleyen programlar üretmek. Hocaya göre bugünkü bakış açısı da kabaca budur.

Aradan sonra hoca tarihçeyi şöyle özetledi: Bir şeyler olur, büyük beklentiler oluşur; bazıları gerçekleşir, bazıları gerçekleşmez ve bir düşüş yaşanır. Sonra yeni umutlar doğar, yeniden bir yükseliş olur. Yapay zeka teknolojisinin ve uygulamalarının tarihi düz bir çizgi değil, iniş çıkışlı bir süreçtir.

## 8. Günümüz

Slayttaki maddeler şunlardır (ekrandan, 01:05:00):

- Deep Blue Garry Kasparov'u 1997'de yendi. Bunun hikayesi oyunlar konusunda anlatılacaktır.
- 2018: Go, StarCraft ile yenilgilerimiz devam ediyor. Bu oyunların karmaşıklığı ve arama uzayları satranca göre çok daha büyüktür. Yeni teknikler de geliştirildi, ama asıl etken yine donanımdır: o kadar büyük uzaylarda derinlemesine arama yapmak için çok güçlü işlem gücü gerekir.
- Sürücüsüz arabalar (DARPA yarışması, 132 mil).
- Mars'ta otonom bir robot.
- Konuşmayı yazıya çeviren programlar (Google Speech to text).
- Hava tahmin sistemleri artık daha ilerideki tarihlerde ve daha küçük zaman aralıklarında çalışıyorlar.

### 8.1 Sürücüsüz arabalar

Hikaye 1980'lere dayanır: O yıllarda yapay sinir ağlarıyla çalışan ve saniyede 10-15 santim giden ALVINN adlı bir araç vardı. 2000'lerin başında DARPA, çöldeki iki nokta arasındaki 132 millik mesafeyi sürücüsüz gidebilen araçlar için bir yarışma açtı. İlk yıl en uzağa giden takım 5 mil civarında gidebildi. Yarışmadan vazgeçilmedi; ertesi yıl birkaç takım 132 mili tamamladı ve en hızlı olana ödül verildi.

Bugün sürücüsüz araçlar görülmeye başlandı, ama tamamen sürücüsüz hale geldiklerini söylemek güçtür. Ara sokaklarda gitmek zordur; değişkenliğin çok daha az olduğu otoyollarda ve ayrılmış yollarda daha rahat ve güvenli kullanılabilirler. Değişkenlik arttıkça ve olası durumların sayısı fazlalaştıkça makinelerin doğru karar vermesi güçleşir.

> **Ders sonrası not:** Hoca DARPA'yı "Amerika'nın Savunma Bakanlığı'nın kısaltılması" diye tanıttı. DARPA (Defense Advanced Research Projects Agency), ABD Savunma Bakanlığı'na bağlı ileri araştırma projeleri ajansıdır. İlk yarışma büyük olasılıkla 2004'te, tamamlanan ikinci yarışma 2005'te yapılmıştır.

### 8.2 Mars'ta otonom robot

Otonom, kendi kararını kendisi veren demektir. Mars robotunun otonom olmasının temel sebebi iletişim gecikmesidir. Robotu elle kontrol ettiğimizi düşünelim: Kameradaki görüntü size ulaştığında robotun bir kratere, bir uçuruma doğru gittiğini görürsünüz, ama görüntü dakikalar seviyesinde gecikmeyle geldiği için robot o sırada çoktan kraterin dibinde olabilir. Bu yüzden robotun temel otonom mekanizmaları olmalıdır. Öte yandan çok pahalı bir projede yanlış giden bir şey robotu bir daha erişilemez hale getirebileceği için tamamen otonom bir sistem yapmak da kolay değildir. Hocanın hatırladığı kadarıyla Curiosity ilk zamanlarda günde yaklaşık bir metre sürülüyordu.

### 8.3 Konuşma tanıma ve hava tahmini

Konuşmayı yazıya ve yazıyı konuşmaya çeviren sistemler mükemmel değildir, ama epey işe yarar seviyededir. Hava tahmininde eskiden yalnız ertesi günün gündüz ve akşam sıcaklığı verilirken bugün saatler düzeyinde tahmin ve daha uzak tarihler için daha doğru tahminler yapılabiliyor. Bu sistemler genelde değişkenliğin yüksek olduğu mevsim geçişlerinde başarısız olur: Mart'ta sıcaklık 20 derece de olabilir 2 derece de, ama Temmuz ya da Ağustos'ta normal şartlarda böyle büyük değişiklikler olmaz. Değişkenlik ve olasılıklar arttıkça doğru tahmin olasılığı düşer.

## 9. Kimine Kolay, Kimine Zor

### 9.1 İnsanlar için zor, makineler için kolay görevler

Slayttaki ifadeler şunlardır (ekrandan, 01:10:00):

- İnsanlar için zor (çok fazla veriye göre işlem yapmak), makineler için kolay görevler:
  - Planlama (lojistik, uçuş saatleri vb.)
  - Bilgisayar oyunları (satranç vb.)
  - Formal tanımlarla tüm durumlara makineler erişebilir.

Bu görevlerin ortak yanı çok fazla veriyle rutin işlem yapmaktır: iki çok basamaklı sayıyı çarpmaktan satranç oynamaya, uçuş saatlerini ya da bir kargo şirketinin dağıtım rotalarını planlamaya kadar. Bilgisayar oyunları formal olarak tanımlı simülasyon dünyalarıdır. Her şey formal tanımlı olduğunda makinenin daha önce rastlamadığı bir durumla karşılaşma ihtimali düşüktür. Örneğin bir makinenin satrancı kendi kendine oynayarak öğrenmesi mümkündür, çünkü kurallar bellidir ve kurallara göre hareket ederek yeni durumlara erişilebilir. Teorik olarak bütün durumlara erişilebilir; pratikte bu mümkün değildir. Durum uzayları çok büyük olan böyle problemlerde makineler insanlardan bariz biçimde daha iyidir.

### 9.2 İnsanlar için kolay, makineler için zor görevler

Slayttaki ifadeler şunlardır (ekrandan, 01:20:00):

- İnsanlar için kolay, makineler için zor görevler:
  - 1 4 9 61 ?
  - Bongard problemleri
  - Dil anlama
  - Resim anlama
  - Dünya bilgisi (Ör: Balıkların kaç ayağı var?)
  - Değişkenliğin yüksek olduğu, olası tüm durumların kapsanamadığı problemler

**Sayı dizisi.** Hoca $1, 4, 9, 61, ?$ dizisinde sıradaki sayıyı sordu. Bir öğrenci 52 dedi ve sayıların karelerinin alınıp ters çevrildiğini açıkladı. Dizi böyle devam eder: $1^2=1$, $2^2=4$, $3^2=9$, $4^2=16 \to 61$, $5^2=25 \to 52$, $6^2=36 \to 63$.

Böyle bir problem makineler için hiç kolay değildir. Makinelere temelde örnekler veririz: "Bu problemin çözümü şudur", "Bu resmin etiketi şudur", "Bu ses sinyalinin metni şudur", "Bu metnin özeti şudur." Makineyi eğitmek için verilen örneklere eğitim kümesi, performansını ölçmek için verilenlere test kümesi denir. Eğitim ve test kümesi benzer bir dağılımdan geliyorsa makine eğitim örneklerinin çıktılarını kullanarak yeni ama onlara yakın bir test örneğinin çıktısını tahmin edebilir. Oysa iyi bir sayı dizisi problemi, öncekilere çok benzemeyen problem demektir. Eğitim ve test kümesi birbirinden oldukça bağımsızdır.

**Bongard problemleri.** Ekranda 62 numaralı Bongard problemi gösterildi (ekrandan, 01:15:00). Solda altı, sağda altı şekil vardır. Soldaki şekiller arasında dalgalı bir çizgi, kıvrımlı eğriler, düz bir çizgi ve sarmal; sağdakiler arasında kapanmaya yakın eğriler, sarmal ve kesişen bir çizgi bulunur. Soru şudur: Soldaki şekilleri sağdakilerden ayıran tanım nedir?

**Soru:** Soldaki şekilleri sağdakilerden ayıran şey nedir? **Cevap:** Bir öğrencinin cevabı ve hocanın onayıyla: Sağdaki şekillerde çizginin başlangıç ve bitiş noktaları birbirine yakın, soldakilerde uzaktır. Şeklin kendisinin ne olduğu önemli değildir.

Bongard problemlerinde de eğitim ve test kümesi arasında büyük bir uçurum vardır; her yeni problem mevcut problemlerden ayrıktır. Bu yüzden bugün bilinen tekniklerle makinenin bunu öğrenmesi mümkün değildir.

**Resim anlama.** Ekranda bir koridorda takım elbiseli kişilerin bulunduğu bir fotoğraf gösterildi: kişilerden biri bir tartıya basmış, arkasından biri ayağıyla tartıya bastırmakta, diğerleri gülmektedir (ekrandan, 01:20:00). Bugünkü teknoloji bu resimde insanlar olduğunu, tavanda ışıklar, solda ayna, metal dolaplar bulunduğunu, kişilerin takım elbise giydiğini ve güldüğünü söyleyebilir; kişilerin vücut pozisyonlarını, kol ve bacak açılarını, iskeletlerini çıkarabilir.

**Soru:** Günümüz sistemleri bu resimde neyi yapamaz? **Cevap:** Bir öğrenci sistemin buradaki şakalaşmayı anlamayabileceğini söyledi. Hoca soruyu "Bu resimdeki kişiler neden gülüyor?" diye somutlaştırdı; bu soruya cevap verebilecek bir sistem yoktur.

**Soru:** Kişiler neden gülüyor? **Cevap:** Öğrenciler tartıya basan kişinin farkında olmadan arkadan bastırılması yüzünden güldüklerini söyledi. Hoca, arkadaki kişi olmasa tartıya basmanın hiç komik, hatta anlamlı olmayacağını belirtti.

**Soru:** Bunun espri olduğunu anlamak için siz neleri biliyorsunuz, makinenin neleri bilmesi gerekir? **Cevap:** Bir öğrenci tartılan kişinin beklentilerini ve duygularını bildiğimizi söyledi. Hoca buna tartı mekanizmasının nasıl çalıştığını bilmeyi ekledi; bunları bilmeden espri anlaşılamaz.

Hocanın sonucu şudur: Makineler parçalara erişebilir (tartı, takım elbiseli ve gülen kişiler), ama bütün parçaların toplamından çok daha fazlasıdır. Bunu gerçekleştirebilecek makineler yoktur ve hocaya göre yakın gelecekte de olmayacaktır. Mizahı anlamak zaten çok güçtür.

Bu görevlerin ortak yönü değişkenliğin yüksek olması ve olası tüm durumların kapsanamamasıdır. Makinelere bütün mizah resimlerini ya da bütün olası Bongard problemlerini veremeyiz; yeni gelen bir örnek eskilerden ayrıktır. Buna karşılık yeni bir kedi resmi elimizdeki kedi resimlerine, yeni yazılmış bir "3" rakamı daha önce yazılmış "3"lere benzer; bu yüzden sistemler bunları tanıyabilir. Bir espriye benzeyen başka bir espri ya da bir Bongard problemine benzeyen başka bir Bongard problemi yoktur.

## 10. Yapay Zeka ve Doğal Zeka

Slayt 35'te iki sütun karşılaştırılır:

- **Yapay zeka:** Daha kalıcıdır (insan ise ölümlüdür). Kopyalanabilir, bu yüzden geniş kitlelere yayılabilir. Maliyet açısından daha ucuzdur. Duyguların etkisinde olmadığı için her zaman tutarlı ve rasyonel çalışır. Kullanılan tekniğe göre işleyişi oldukça ayrıntılı belgelenebilir.
- **Doğal zeka:** Yaratıcıdır. Tecrübelerini aktarabilir. Adapte olabilir. Bilinçli çaba olmadan modelleri öğrenir.

Hoca son maddeyi açtı: Bir şey öğrenmek için çaba göstermesek, hiçbir şey yapmadan otursak bile öğreniriz. Fizyolojik açıdan öğrenme nöronlar arasındaki bağlantıların değişmesidir ve bu, düşündüğümüz, bilinçli olduğumuz sürece, hatta uyurken bile olur. Beyin durmadan durumdan duruma geçer. Bu anlamda biz de öğrenme makineleriyiz.

## 11. Etmenler (Ajanlar) ve PEAS

### 11.1 Rasyonel ajan

İkinci slayt etmenler (ajanlar) konusudur. Hoca önce geçen haftaki dört yaklaşım tablosunu hatırlattı (ekrandan, 01:25:00):

| | Düşünmek | Hareket etmek |
|---|---|---|
| İnsan gibi | İnsan gibi düşünmek | İnsan gibi hareket etmek |
| Rasyonel | Rasyonel düşünmek | Rasyonel hareket etmek |

Bu tabloda kritik olarak "rasyonel hareket etmek" seçilmişti. Slayttaki şekilde bir ajan (agent) ve çevre (environment) vardır: Ajan çevreden algılar (percepts) alır, çevreye eylemler (actions) uygular; algılar algılayıcılar (sensors) üzerinden gelir, eylemler eyleyiciler (actuators) üzerinden yapılır; ajanın içindeki kutuda bir soru işareti vardır.

Ajan bir makine, bir yazılım, bir insan ya da bir hayvan olabilir; şekil bunların hepsini temsil eder. Hepsinde ortak olanlar şunlardır:

- **Eyleyiciler (actuators):** Ortamı etkileyen ya da etkileyebilecek uzantılardır. Kol, bacak olabilir; cep telefonunun hoparlörü, çalar saatin zili, bir yazılım için ekran ve üzerindeki değişiklikler de eyleyicidir.
- **Algılayıcılar (sensors):** Ajanın çevresini algıladığı araçlardır: göz, kulak, ses ya da uzaklık algılayıcıları, kamera, klavye, fare, mikrofon.

Ajan çevresinden aldığı bilgiyi işleyip buna göre nasıl hareket edeceğine karar verir. Bu karar verme kısmı şekildeki kutudur. Kutunun içine koyduğunuz karar mekanizmasına göre ajana rasyonel ya da irrasyonel denir. Rasyonel, bir başarı kriterine uygun hareketleri sürekli yapan anlamındadır. "Rasyonel" bir sıfattır; ajan olmak için şart değildir.

### 11.2 PEAS

Bir yazılım ajanı ya da robot tasarlarken önce karar verilmesi gereken dört parametre vardır. İngilizce baş harflerinden PEAS diye anılır:

- **P (Performance measure, performans ölçütü):** Ajanın performansını nasıl ölçeceğiz?
- **E (Environment, ortam):** Ajan nasıl bir çevrede çalışacak, bu çevrenin özellikleri neler?
- **A (Actuators, eyleyiciler):** Ortamı nasıl etkileyeceğiz?
- **S (Sensors, algılayıcılar):** Ortamı nasıl algılayacağız?

Bunlara karar verdikten sonra ajanı yapmaya başlamak çok daha mantıklıdır.

### 11.3 Örnek: Harita çıkaran robot

Hoca örneği şöyle bağladı: Bazı daha pahalı robot süpürgeler önce evin haritasını çıkarır, sonra bu haritaya göre her yeri düzgünce gezerek temizler; daha ucuz olanlar rastgele dolaşır, bir yere çarpınca döner. Aynı işi bir alışveriş merkezi için, bir mağaranın önceden haritasını çıkarmak için ya da açık ortamda üç boyutlu harita çıkaran bir drone için düşünebiliriz.

Slayttaki PEAS şöyledir (ekrandan, 01:30:00):

- **P:** Haritanın doğruluğu, işlem hızı, statik / dinamik ortamlarda çalışabilmesi.
- **E:** Duvarlar, bina içi, dış ortam, statik / dinamik, engeller.
- **A:** Tekerlerin yönü ve hızı, kamera kontrolü.
- **S:** Lazer / sonar / kızılötesi uzaklık algılayıcılar, kamera.

**Soru:** Bu robot için P neler olabilir? **Cevap:** Haritanın doğruluğu; ayrıca işlem hızı (bir evin haritasını üç günde çıkarmasını istemeyiz) ve statik ile dinamik ortamlarda çalışabilmesi. Hoca dinamik ortamı açıkladı: Kalabalık bir alışveriş merkezinde insanlar dinamik engellerdir; bir an engel gibi görünüp sonra kaybolurlar, oysa asıl bulunması gereken duvarlardır. Yeni duvar eklenmesi gibi düzenlemeler de ortamı dinamik yapar. Bina içinde haritalama yapmakla dış ortamda haritalama yapmak da bambaşka işlerdir. Eyleyiciler pervaneler gibi başka şeyler de olabilir.

### 11.4 Örnek: Otonom taksi sürücüsü

Çağırdığınızda gelen, sizi istediğiniz yere götüren otonom bir taksi düşünelim. Bu ölçütler bir insan sürücü için de bir robot için de geçerlidir. Performans ölçütü güvenilir (sizi oraya sağ salim götüren), hızlı, yasal ve konforlu bir sürüştür. Ortam yollar, trafikteki diğer araçlar, yayalar ve müşteridir. Eyleyiciler arabayı kontrol eden mekanizmalardır; bazı durumlar için korna gerekebilir. Algılayıcılar da benzer şekilde belirlenir.

<!-- BELİRSİZ: Taksi slaytının A ve S satırları ekranda yalnız küçük önizleme olarak görünüyor (direksiyon, gaz, fren, sinyal lambaları, korna; kamera, uzaklık ve hız ölçerler gibi); tam metin okunamadı. -->

Tıbbi teşhis uzmanı gibi başka ajanlar da tanımlanıp PEAS'ları çıkarılabilir. Hoca bunu kendi başınıza denemenizi önerdi.

## 12. Ortam Özellikleri

Ajanın çalışacağı ortamın çeşitli kriterleri tanımlanmıştır:

- **Fully observable / partially observable (tamamen / kısmen gözlemlenebilir):** Ajanın algılayıcıları ortamın tamamını algılayabiliyorsa ortam tamamen gözlemlenebilirdir, yalnız bir kısmını algılayabiliyorsa kısmen gözlemlenebilirdir.
- **Deterministic / stochastic (deterministik / stokastik):** Kabaca işin içinde şans olup olmadığıdır.
- **Episodic / sequential (epizodik / sıralı):** Yapılan bir hareketin ilerideki durumları etkileyip etkilemediğidir.
- **Static / dynamic (statik / dinamik):** Ajan karar verirken ortamın değişip değişmediğidir.
- **Discrete / continuous (ayrık / sürekli):** Sınırlı sayıda açıkça belirlenmiş algı ve hareket varsa ortam ayrıktır; yapılabilecek hareketler sonsuzsa süreklidir.
- **Single agent / multi-agent (tek / çok ajanlı):** Ortamda tek mi birden fazla mı ajan bulunduğudur.

**Soru:** Satranç oynayan bir ajan tamamen mi kısmen mi gözlemlenebilir bir ortamdadır? **Cevap:** Tamamen gözlemlenebilir. **Soru:** Poker oynasak? **Cevap:** Kısmen gözlemlenebilir. Okey ve pokerde kapalı taşlar ya da kartlar vardır; bazı şeyleri bilirsiniz, bazılarını bilmezsiniz.

Epizodik-sıralı ayrımı için hoca şu örnekleri verdi: Satrançta önceden yapılan bir hamle ilerisini etkiler, bu yüzden sıralıdır. Kişiselleştirme yapan bir arama motorunda önceki sorgularınız sonraki sorguların sonuçlarını etkiler, çünkü sistem neyden hoşlandığınızı öğrenir. Klasik bir arama motorunda ise bir sorgu ile sonraki arasında ilişki yoktur. Bir parmak izi tanıma sisteminde de önceki kullanımların sonrakileri pek etkilemesi beklenmez.

Slayttaki tablo şöyledir (ekrandan, 01:35:00):

| Özellik | Süreli satranç | Süresiz satranç | Taksi şoförü |
|---|---|---|---|
| Fully observable | Yes | Yes | No |
| Deterministic | Strategic | Strategic | No |
| Episodic | No | No | No |
| Static | Semi | Yes | No |
| Discrete | Yes | Yes | No |
| Single agent | No | No | No |

- Ortam türleri ajan dizaynını büyük ölçüde etkilerler.
- Gerçek dünya: partially observable, stochastic, sequential, dynamic, continuous, multi-agent.

Satranç tamamen gözlemlenebilir ve deterministiktir; taksi şoförü ise ne tamamen gözlemlenebilir ne de deterministik bir ortamdadır, çünkü dünyadan bahsediyoruz: Yaptığımız hareketler bütün süreci belirlemez, işin içine şans ve diğer ajanlar girer.

> **Ek bilgi (derste anlatılmadı):** Tablodaki "Strategic", ortamın diğer ajanların hamleleri dışında deterministik olduğunu anlatır. Süreli satrançtaki "Semi" (yarı dinamik) ise tahtanın kendisi değişmese de süre aktığı için ajanın performans puanının zamanla değişmesidir.

Hocanın vurguladığı asıl kritik nokta şudur: Her özellikte bir taraf diğerinden kolaydır.

> **Hocanın vurgusu:** Tamamen gözlemlenebilir ortam kısmen gözlemlenebilirden, deterministik ortam stokastikten, epizodik ortam sıralıdan, statik ortam dinamikten, ayrık ortam sürekliden, tek ajanlı ortam çok ajanlıdan daha kolaydır. Gerçek dünya bunların hepsinin zor tarafıdır.

Bu yüzden gerçek dünyada çalışan bir ajan yapmak çok zordur. Simülasyon dünyalarında, örneğin bir oyunda, ortamı deterministik ve tamamen gözlemlenebilir yapabilir, uzayı, algılayıcıları ve eyleyicileri ayrık hale getirebilirsiniz. Gerçek dünyaya çıktığınızda bütün kriterlerin zor tarafına geçersiniz.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:13:17; ekrandan, 00:15:00): 1997'de çizilmiş "Evolution of Computer Power/Cost" grafiği, 1000 dolarlık bilgisayarın saniyedeki milyon işlem sayısını yıllara göre gösterip sağ tarafa bakteriden insana kadar "eşdeğer beyin gücü" basamakları koyuyor. Bu grafik ne anlatmaya çalışıyor ve bu karşılaştırma ne kadar anlamlı?

> **Çözüm (derste verildi):** Grafik, trendlere göre bilgisayarların işlem gücünün belli yıllarda maymun, hatta insan beyni düzeyine ulaşacağını ima eder. Hocaya göre bu karşılaştırma anlamsızdır: Bilgisayarlar ayrık, beyin süreklidir; ayrıca çok işlem yapabilmek zeki davranabilmek demek değildir.

**Soru 2** (derste sözlü, 00:24:13): Teorik olarak bir bilgisayarı tahtalardan, çarklardan, zincirlerden yapabilir misiniz? Yaparsanız nasıl bir şey olur?

> **Çözüm (derste verildi):** Teorik olarak yapılabilir. Ancak çok büyük, çok yavaş, pahalı ve uzun süreli çalışmada güvenilmez olur.

**Soru 3** (ekrandan, 01:20:00; derste sözlü, 01:11:23): $1, 4, 9, 61, ?$ dizisinde sıradaki sayı nedir?

> **Çözüm (derste verildi):** 52. Ardışık doğal sayıların kareleri alınıp basamakları ters yazılır: $1, 4, 9, 16 \to 61, 25 \to 52, 36 \to 63, \dots$ (python ile doğrulandı: ilk yedi terim 1, 4, 9, 61, 52, 63, 94).

**Soru 4** (ekrandan, 01:15:00): Bongard problemi 62'de solda altı, sağda altı şekil vardır. Soldaki şekilleri sağdakilerden ayıran tanım nedir?

> **Çözüm (derste verildi):** Sağdaki şekillerde çizginin başlangıç ve bitiş noktaları birbirine yakın, soldakilerde uzaktır; şeklin kendisi önemli değildir.

**Soru 5** (derste sözlü, 01:16:40; ekrandan, 01:20:00): Tartıya basan bir kişinin ve gülen takım elbiseli kişilerin bulunduğu fotoğrafta günümüz sistemleri neyi yapamaz? Esprinin anlaşılması için hangi bilgiler gerekir?

> **Çözüm (derste verildi):** Sistemler parçaları (kişiler, giysiler, gülme, tartı, vücut pozisyonları) bulabilir ama kişilerin neden güldüğünü açıklayamaz. Esprinin anlaşılması için tartılan kişinin beklentilerini ve duygularını, tartının nasıl çalıştığını bilmek gerekir; bütün parçaların toplamından fazladır.

**Soru 6** (ekrandan, 01:20:00): Dünya bilgisine örnek: Balıkların kaç ayağı var?

> **Çözüm (derste verilmedi):** Balıkların ayağı yoktur. Soru, insanlar için apaçık olan sağduyu bilgisinin makinelere açıkça verilmedikçe onlar için zor olduğunu gösteren bir örnek olarak slaytta yer aldı.

**Soru 7** (derste sözlü, 01:29:25): Harita çıkaran bir robot için performans ölçütleri (P) neler olabilir?

> **Çözüm (derste verildi):** Haritanın doğruluğu, işlem hızı, statik ve dinamik ortamlarda çalışabilmesi (ekrandan, 01:30:00).

**Soru 8** (derste sözlü, 01:33:09): Satranç oynayan bir ajan tamamen mi kısmen mi gözlemlenebilir bir ortamdadır? Poker oynayan bir ajan?

> **Çözüm (derste verildi):** Satranç tamamen gözlemlenebilir, poker (ve okey) kısmen gözlemlenebilir bir ortamdır.

## Dersin Toparlaması

Ders yapay zekanın ne olduğu üzerine kavramsal tartışmayı tamamladı. Turing'in sonuca dayalı ölçütüne karşı Searle, Ned Block ve Rudolf Arnheim sürecin de önemli olduğunu savunur; Turing ise insanın nasıl düşündüğünü bilmediğimiz için süreçleri karşılaştıramayacağımızı söyler. Yapay zekanın tarihi büyük beklentiler, hayal kırıklıkları ve yeniden yükselişlerden oluşan iniş çıkışlı bir süreçtir: yapay nöron ve Hebb kuralı, Minsky ve Papert'in eleştirisi, uzman sistemler ve Fifth Generation, YZ kışı ve bugünkü "insanları destekleyen sistemler" odağı. Makineler formal olarak tanımlı, çok veri gerektiren problemlerde insanlardan iyidir; değişkenliği yüksek ve tüm durumları kapsanamayan problemlerde (sayı dizileri, Bongard problemleri, mizah, dünya bilgisi) zorlanır.

İkinci bölümde rasyonel ajan, PEAS ile ajan tasarımı ve ortam özellikleri tanıtıldı. Her ortam özelliğinin bir kolay, bir zor tarafı vardır ve gerçek dünya bütün özelliklerin zor tarafında yer alır. Gelecek hafta yapay zekanın temel konularından biri olan arama algoritmalarına başlanacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
