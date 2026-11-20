# Ders 12 Genişletilmiş Notu: Biyoenformatikte Görselleştirme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Görselleştirmeye Giriş
- 2. Algı ve Algı Süreci
- 3. Duyularla Alınan Bilgi
- 4. Görselleştirmenin Tanımları ve Önemi
- 5. Veri Görselleştirme ve Bilgi Görselleştirme
- 6. Bilgi Görselleştirmenin Amaçları ve Hedefleri
- 7. Sözel Bilgi ve Görsel Bilgi
- 8. Bilişim ve Göstergebilim
- 9. Görselleştirme Süreci ve İnsan-Bilgisayar Etkileşimi
- 10. Görselleştirme Yöntemlerinin Sınıflandırılması
- 11. Grafikler, Veri Türleri ve Teknik Seçimi
- Örnek Sorular
- Dersin Toparlaması

## 1. Görselleştirmeye Giriş

Ders, büyük ölçüde İngilizce anlatıldı ve sık kullanılan bir atasözüyle açıldı: "Bir resim bin kelimeye bedeldir" (a picture is worth a thousand words). Hoca, bu sunumun ana fikrinin bu atasözü olduğunu söyledi. Konu görselleştirmedir (visualization). Görselleştirme bilgisayar biliminde kendi başına önemli bir alandır ve biyoenformatiğin de önemli bir parçasıdır. Her zamanki gibi önce tanımlar, açıklamalar ve ilgili kavramlarla başlanacağı belirtildi.

Giriş slaytında iki fikir yer aldı (ekrandan, 00:15:00):

- Görselleştirme teknikleri biyoenformatiğin önemli bir parçasıdır.
- Artan veri miktarı ve bununla gelen karmaşıklık, daha iyi insan-veri arayüzlerine (human-data interfaces) ihtiyaç olduğu anlamına gelir.

Hoca, eskiden veriyi görebildiğimiz ortamın çok sınırlı olduğunu, bugün ise verinin hem saklanamayacak hem de işlenemeyecek kadar büyüdüğünü anlattı. <!-- BELİRSİZ: hocanın eski veri ortamı için kullandığı ifade altyazıda "flat disks" diye geçiyor; basılı çıktı mı disket mi kastedildiği anlaşılmıyor --> Modern biyoenformatik dünyasında çok daha etkili sunum sistemleri gerekir ve bu sistemlerin genellikle ek etkileşim (interactive) yetenekleri sunması beklenir.

### 1.1 "Görselleştirmek" sözcüğünün sözlük tanımları

Hoca önce "to visualize" (görselleştirmek) sözcüğünün sözlük anlamlarına baktı. Merriam-Webster ve Concise Oxford sözlüklerindeki tanımlar aşağı yukarı aynıdır: zihinde görsel bir imge oluşturmak (to form a mental visual image). Bir de biraz daha geniş, kapsayıcı bir tanım gösterildi. <!-- BELİRSİZ: Merriam-Webster tanımının tam metni ve geniş tanım altyazıda okunmuyor, karede yok -->

### 1.2 Görselleştirme kavramı

Sözlük tanımlarından sonra görselleştirme kavramı tanıtıldı (ekrandan, 00:20:00):

- Görselleştirme, bir veri kümesinin belirli bir özelliğini anlamaya yardım eden resimlerin üretilmesi ve sunulmasıdır; veriyi insanlar için bir anlam taşır hâle getirir.
- Bu tanım biraz fazla özeldir, çünkü resimler (görüntüler ya da grafikler) bilgiyi temsil etmenin yollarından yalnız biridir.
- Daha teknik bir tanım: verinin ya da kavramların grafik bir gösterimi (graphical representation of data or concepts).

Hoca, birinci tanımın daha fikir odaklı olduğunu, ikincisinin ise resim olsun ya da olmasın her türlü grafik gösterimi kapsayan daha teknik bir tanım olduğunu belirtti.

## 2. Algı ve Algı Süreci

### 2.1 Algı nedir?

Hoca, ilişkili bir kavram olarak algıyı (perception) sordu: "Algıdan ne anlıyorsunuz?" Sınıftan cevap gelmedi. Hoca kendisi açıkladı. Slayttaki maddeler şunlardır (ekrandan, 00:25:00):

- Algı, dünyayı duyularımızla deneyimlememizdir (sensory experience of the world).
- Görme, duyma ya da duyular yoluyla bir şeyin farkına varma yeteneğidir.
- Bir şeyin nasıl görüldüğü, anlaşıldığı ya da yorumlandığıdır.
- Bilgiyi işlemek için kullandığımız bilişsel işlevlere (cognitive functions) dayanır; örneğin bir arkadaşın yüzünü tanımak ya da tanıdık bir kokuyu fark etmek için belleği kullanmak.
- Algı süreci sayesinde çevresel uyaranları (environmental stimuli) hem tanır hem de onlara tepki veririz.

Hoca bilişsel işlevlerin beynin işlevselliğiyle ilgili olduğunu söyledi: biyolojik olarak beynimizde bazı yerleri ya da sözcükleri hatırlamamızı sağlayan bölgeler vardır. Uyaran (stimulus) da çevreden gelen ve bir tepkiyi tetikleyen etkidir. Biyolojik olarak çevresel uyaranları alan beş duyumuz vardır; hoca bazen "altıncı his" diye bir şeyden de söz edildiğini ekledi.

### 2.2 Görme duyusu için algı süreci

Çevresel uyaranlar insanın bilişsel sistemine bir algı süreciyle ulaşır. Görme duyusu düşünüldüğünde süreç şu adımlardan oluşur (ekrandan, 00:35:00):

1. **Çevresel uyaran (environmental stimulus):** Çevrede algılanma potansiyeli olan her şey.
2. **Dikkat edilen uyaran (attended stimulus):** Çevrede dikkatimizin yöneldiği belirli nesne.
3. **Retinada görüntü (image on the retina):** Kornea ve mercek birlikte çalışarak ters bir görüntüyü retinaya düşürür.
4. **Dönüştürme (transduction):** Görsel iletilerin yorumlanmak üzere beyne aktarılmasını sağlar. Hoca bunu, ters görüntünün beyne iletilecek elektrik darbelerine dönüştürülmesi olarak açıkladı.
5. **Sinirsel işleme (neural processing).**
6. **Algı (perception):** Bu noktada uyaranın bilinçli olarak farkına varırız.
7. **Tanıma (recognition):** Nesneyi yorumlama ve ona anlam verme yeteneği.
8. **Eylem (action):** Algılanan uyarana tepki olarak ortaya çıkan bir tür motor etkinlik.

Hoca eylemin birçok biçimi olabileceğini örneklerle anlattı: bir sanat eserini incelerken sonuç sanatın verdiği bir haz olabilir; size doğru bir araba geldiğini görürseniz kendinizi kurtarmak için harekete geçersiniz. Bu ikincisi tipik bir motor etkinliktir.

## 3. Duyularla Alınan Bilgi

İnsanlar bilgiyi duyularıyla algılar ve fiziksel çevreyle bu duyular aracılığıyla etkileşir. Slaytta beş duyu sıralandı: görme, duyma, koku, dokunma ve tat. Slayttaki pasta grafikte en büyük dilim görmeye aittir; duyma ikinci sıradadır, koku, dokunma ve tat küçük dilimlerdir (ekrandan, 00:40:00). Grafikte sayısal değer yazmıyor; oranlar hoca tarafından sözlü verildi (derste sözlü, 00:37:24):

| Duyu | Yaklaşık pay |
|---|---|
| Görme | %80 |
| Duyma | %10 |
| Koku | %5 |
| Dokunma | %3 |
| Tat | %2 |

Bu oranların toplamı %100'dür (ajan tarafından python ile denetlendi). Hoca bu dağılımın normal bir yetişkin için geçerli olduğunu ve istisnalar bulunduğunu vurguladı. İnsan yaşamı boyunca dağılım değişir; hoca anne karnındaki bir bebeğin bilgiyi büyük olasılıkla daha çok başka duyularla aldığını, sonraki aylarda ve yıllarda dağılımın değiştiğini anlattı. <!-- BELİRSİZ: doğmamış bebek ve ilk aylar üzerine söylenenler altyazıda bozuk; hangi duyunun öne çıktığı net değil --> Dağılım yaşa ya da kişinin fiziksel durumuna göre de değişir: görme engelli birinin algısının çoğu duyma ve diğer duyularla olur; işitme engelli biri duyma yoluyla bilgi almaz; kolu olmayan birinde dokunma duyusu yoktur. Bunlar istisnalardır.

> **Hocanın vurgusu:** Normal bir insan bilginin büyük kısmını görme yoluyla alır. Görselleştirme kavramını bu kadar önemli kılan budur.

## 4. Görselleştirmenin Tanımları ve Önemi

### 4.1 Görselleştirmenin farklı tanımları

Hoca, görselleştirmenin oldukça fazla tanımı olduğunu söyleyerek bazılarını verdi:

- **Birinci tanım:** Görselleştirme, simgesel olanı (symbolic) geometriğe dönüştürerek zihinsel bir model oluşturmayı ve beklenmedik içgörüleri (unexpected insights) desteklemeyi amaçlayan bir bilgisayar bilimi yöntemidir. Hoca bunun önemli bir tanım olduğunu söyledi: simgesel bir kavram geometriğe dönüştürülür, böylece bir zihinsel model kurulur ve beklenmedik içgörü desteklenir. Görselleştirmeyi daha çok bilgi çıkarmak için kullanırız.
- **İkinci tanım:** Doğal algı yollarımızı en iyi destekleyen yapay belleği bulmak (finding the artificial memory that best supports our natural means of perception). Hoca bunu ilginç bir tanım olarak niteledi; bilginin uzamsal ve grafik gösterimiyle ilişkilidir.

Hoca ardından değişim algılamanın (change detection) bir başka bilişsel beceri olduğuna değindi. <!-- BELİRSİZ: değişim algılama (change detection) üzerine anlatılanlar altyazıda bozuk; slaytta bir örnek gösterilmiş olabilir -->

### 4.2 Diğer duyular neden kullanılmıyor?

Slaytta şu fikir yer aldı (ekrandan, 00:45:00): Diğer insan duyularının (koku, tat, dokunma ya da duyma) biyolojik verinin temsili olarak kullanılamaması için kavramsal bir neden yoktur. Ancak çok pratik sınırlamalar vardır; ilki, uygun bir temsil yöntemine ihtiyaç duyulmasıdır. Hoca bunu bir soruyla somutlaştırdı: Bir DNA'daki bölgeleri duyabilir ya da bir mikrodizi deneyinin sonuçlarını koklayabilir miyiz? <!-- BELİRSİZ: altyazıda "DNA in transplicy sites" geçiyor; büyük olasılıkla transkripsiyon bölgeleri kastediliyor --> Hoca bazı hayvanların koku duyusunun insandan çok daha gelişmiş olduğunu da ekledi.

### 4.3 Bant genişliği

Diğer duyuların bir başka sınırı bant genişliğidir (bandwidth). Bant genişliği, birim zamanda (örneğin saniyede) iletilebilen bilgi miktarıdır. Bu bağlamda görme duyusu en yüksek bant genişliğine sahiptir; daha önce görüldüğü gibi bilginin yaklaşık %80'i görme yoluyla algılanır.

> **Ders sonrası not:** Altyazıda bu yerde "%8" geçiyor; bu, önceki slayttaki %80 değerinin Whisper tarafından bozulmuş hâlidir. Doğrusu %80'dir.

### 4.4 Örüntü tanıma

Veriyi sunmanın bir başka gerekçesi, çoğu durumda bilgiyi özetlemek ve örüntülerin fark edilmesini sağlamaktır. İnsan görme sistemi örüntü tanımada (pattern recognition) çok iyidir, çünkü milyonlarca yıl boyunca bu yetenek yönünde sürekli bir seçilim baskısı olmuştur. İnsanlar ve ataları için iyi bir görme sistemi hayatta kalmanın temel koşuluydu. Aynı görme sistemi, biyolojik veri kümelerinden türetilmiş soyut diyagramları çözümlemede de mükemmeldir; görsel gösterimlerin biyoloji bilimlerinde bu kadar yaygın olmasının nedeni budur.

### 4.5 Görselleştirme neden bu kadar önemli?

Slayttaki soru ve cevap şudur (ekrandan, 00:50:00): "Görselleştirme neden bu kadar önemli? Cevap: çünkü insanlar öyle (because people are)." Hoca bunu şöyle açıkladı: gerçek dünyada gerçekten yaratıcı olan yalnız insandır; bir fikre sahip olduğunu bilen insandır; bilimsel gelişme için kaynakları olan da insandır. Bir örüntünün algılanması çoğu zaman bir içgörünün temelini oluşturur.

### 4.6 Veri analizinde görselleştirme

Hoca, önceki derslerde tartışılan istatistiksel veri analizi kavramlarını hatırlattı: bir analize her zaman önce veriyi görselleştirerek başlamak iyidir, çünkü görselleştirme veri hakkında kaba bir fikir verir. Bu her zaman önerilen yoldur.

- Görselleştirme çoğu zaman verideki sorunların hemen ortaya çıkmasını sağlar.
- Histogram, verinin dağılımını gösteren görsel bir tekniktir. Dağılımı gördükten sonra veriyi özetleme yöntemi histogramın türüne göre seçilir.
- Uygun bir görselleştirmeyle verideki hatalar ve yapay kalıntılar (artifacts) genellikle belirgin hâle gelir. Örneğin verinin saçılım grafiği (scatter plot) çizilirse aykırı değerler (outliers) görülür.
- Bu yüzden görselleştirme veri kalite kontrolüne de yardımcı olur.

> **Hocanın vurgusu:** Önerilen yol her zaman analize görsel incelemeyle başlamaktır.

## 5. Veri Görselleştirme ve Bilgi Görselleştirme

### 5.1 Tanımlar

Hoca, bu girişten sonra veri görselleştirme ve bilgi görselleştirme için resmî tanımlar verdi:

- **Veri görselleştirme (data visualization):** Verinin resimsel ya da grafik bir biçimde sunulmasıdır. Karar vericilerin görsel olarak sunulan analizleri görmesini, böylece zor kavramları kavramasını ya da yeni örüntüleri tanımasını sağlar.
- **Bilgi görselleştirme (information visualization):** Görsel gösterimlerin incelenmesidir; karar verme için çok önemlidir.

> **Hocanın vurgusu:** Bu iki kavram birbirine karıştırılmamalıdır.

Hoca aynı ayrımı farklı sözcüklerle yeniden ifade etti. Veri görselleştirme, nicel (sayılabilir) verinin grafik gösterimidir; bilinen çizelge, grafik ya da harita türleriyle yapılır. Bilgi görselleştirme ise bazen infografik (infographic) diye de bilinir; bir ya da daha çok veri görselleştirmesini grafik ya da metin gibi veri dışı öğelerle birleştiren bir grafik gösterimdir. İnfografik, altta yatan veriyi ve bağlamını anlayarak veri görselleştirmesine yaratıcı bir süreç uygulamayı gerektirir.

### 5.2 Büyük zorluk

Slaytta bu alanın temel zorluğu şöyle özetlendi (ekrandan, 01:00:00):

- Büyük zorluk, yalnız büyük miktarda veriyi göstermenin hesaplama yöntemlerine değil, bu kadar büyük verinin hem algısına hem de bilişine (cognition) odaklanmaktır.
- Bir yön, bilgisayarla görselleştirme sürecinin doğal görselleştirme sürecini yansıtacak biçimde nasıl iyileştirilebileceğine odaklanmaktır.

Hoca, algı sistemlerimizin özellikle hayatta kalmak ve çevremizdeki geniş ortamı anlamak için tasarlandığını, soyut nesneler ve imgeler için tasarlanmadığını söyledi. Görsel analiz tıbbi görselleştirmenin de temel bir bileşeni hâline gelmektedir; çünkü karmaşık, çok boyutlu, zamanla değişen, karma kipli (mixed modality), benzetim ve çok denekli veri kümeleri hızla artmaktadır.

## 6. Bilgi Görselleştirmenin Amaçları ve Hedefleri

### 6.1 Amaçlar

Bilgi görselleştirmenin amaçları slaytta şöyle verildi (ekrandan, 01:05:00):

- **Keşfetmek/hesaplamak (explore/calculate):** analiz etmek, bilgi üzerine akıl yürütmek.
- **İletmek (communicate):** açıklamak, karar vermek, bilgi üzerine akıl yürütmek.
- **Süslemek (decorate).**

> **Ders sonrası not:** Altyazıda üçüncü amaç "declaration" diye geçiyor; slaytta "Decorate" (süslemek) yazıyor.

Bu noktada derse on dakikalık bir ara verildi.

### 6.2 Hedefler

Aradan sonra hedefler ele alındı. Daha özel olarak görselleştirme şunları yapmalıdır (ekrandan, 01:15:00):

- **Büyük veri kümelerini tutarlı (coherent) kılmak:** çok büyük miktarda bilgiyi sıkışık (compact) biçimde sunmak.
- **Bilgiyi çeşitli bakış açılarından sunmak.**
- **Bilgiyi birkaç ayrıntı düzeyinde sunmak.**

Hoca bunlara ek olarak şu hedefleri saydı:

- **Görsel karşılaştırmayı desteklemek:** bir görselleştirme bir diğeriyle karşılaştırılabilir.
- **Veri hakkında hikâye anlatmak:** görselleştirme veriyi özetlemeyi ve veri hakkında hikâyeler kurmayı sağlar.
- **Karşılaştırma araçları:** uzunluk, şekil, yön (orientation) ve doku (texture). <!-- BELİRSİZ: listenin başındaki öğeler altyazıda bozuk; konum ya da boyut gibi başka öğeler de sayılmış olabilir -->
- **Animasyon:** zamanla değişimi göstermek için kullanılır. Hoca animasyonu üçüncü boyutu zaman olan bir tür grafik olarak tanımladı: resimler zaman içinde değişir.
- **Renk:** nesneler arasında ayrım yapmaya yardım eder.
- **Estetik:** süreci daha çekici kılar.

## 7. Sözel Bilgi ve Görsel Bilgi

### 7.1 İkili kodlama kuramı

Görselleştirmenin biliş süreciyle ilişkisini tartışmak için sözel bilginin ve görsel bilginin nasıl yorumlandığına bakıldı. Slayttaki ifade şudur (ekrandan, 01:20:00): Koku bilgisi (olfactory), tat bilgisi (gustatory) ve dokunma bilgisi (haptic) bir kenara bırakılıp ikili kodlama kuramı (dual-coding theory; Paivio ve Csapo 1973) izlenirse, görsel bilgi (imgeler) ile sözel bilgi (konuşulan ve yazılan doğal dil) ayrılır. İkili kodlama kuramı, insanların sözel ve sözel olmayan bilgiyi ayrı ama ilişkili sistemlerde işlediğini ve temsil ettiğini söyleyen bir biliş kuramıdır. Örneğin beyin "ağaç" sözcüğü için, bir ağaç resmi için kullandığından farklı türde bir temsil kullanır.

### 7.2 Anlamsal belirsizlik

Hoca, "tree" sözcüğünü gördüğümüzde bunun sözel bilgi olduğunu ve anladığımızı söyledi. Doğal dildeki sorun, aynı sözcüğün farklı şeyleri temsil edebilmesidir; bu, doğal dilin anlamsal belirsizliği (semantic ambiguity) olarak bilinir. Slaytta iki resim gösterildi; biri burun akıntısıyla (running nose) ilgiliydi. Hoca, standart yaklaşımlarla bir bilgisayarın bu ifadenin farklı anlamlarını, örneğin soğuk algınlığının bir belirtisi olarak burun akıntısını ve sözcüklerin düz anlamını, ayırt edemeyeceğini söyledi. <!-- BELİRSİZ: "running nose" örneğindeki ikinci resmin ne olduğu altyazıda net değil, karede görülmedi --> Günümüzde yapay zekâda daha insana benzer yaklaşımlar yaygınlaşmaktadır, ama bu tür anlamsal belirsizlikleri yorumlama konusunda insan yeteneğine hâlâ uzağız. Bir çözüm yapay zekâ ve makine öğrenmesi yaklaşımlarındadır: makinelere bağlamı öğrenmeleri öğretilebilir ve bu yaklaşımlar gittikçe iyileşmektedir.

Sözel bilginin büyük bir sorunu anlamsallıkla karşı karşıya kalmamızdır. Anlamsal belirsizlik, bir sözcüğün çoğu zaman birden fazla anlamı olması demektir ve bu, olağan hesaplama sistemleri için sorun yaratır. Örnek olarak "cell" sözcüğü verildi (ekrandan, 01:25:00). Bu sözcüğün birçok farklı anlamı vardır:

- ünlü bilimsel dergi (Cell),
- yaşamın temel yapı taşı (hücre),
- pil hücresi,
- matematiksel topolojide Voronoi hücresi,
- mahkûm hücresi,
- bir radyo (hücresel) ağın hücresi,
- bir hesap tablosunun hücresi,
- kan hücresi ve daha fazlası.

### 7.3 İnsanın bilgi işleme süreçleri: Mayer'in modeli

Konuyu daha iyi anlamak için insanın bilgi işleme süreçlerine daha ayrıntılı bakıldı. Mayer'in çoklu ortamla öğrenme (multimedia learning) yaklaşımına göre resimler şöyle işlenir:

1. Belirli bir dikkat varsa resimler çalışma belleğinde (working memory) temsil edilir.
2. Çalışma belleği imge parçalarıyla dolduğunda (hoca bunu bilişsel aşırı yükle ilişkilendirdi), sonraki etkin bilişsel işleme bu parçaları tutarlı bir yapıya örgütler.
3. Ortaya çıkan bilgi temsili resimsel bir modeldir (pictorial model): kişinin kurduğu, resmin ana parçalarının örgütlenmiş görsel temsili. Hoca bunu beyinde bir tür büyük sıkıştırmaya benzetti.
4. Son olarak bu yeni temsili önceki bilgiyle bağlamak için etkin bilişsel işleme gerekir. Bu gerçekleşirse resim uzun süreli belleğe yerleşir.

**Yazılı metin:** Yazılı doğal dil sözcüklerden oluşur. Bütün sözcükler görsel olarak sunulduğu için önce gözle algılanır ve çalışma belleğine imge olarak girer. Sonra çalışma belleğinin işitsel kısmı tarafından zihinsel olarak işlenmeleri, yani konuşulan sözcükler gibi işlenmeleri gerekir. Sonuç olarak sözel malzeme görsel kanaldan girmek zorunda kalırsa sistem içinde karmaşık bir yol izler ve görsel kanalda paralel olarak işlenen imgelerle dikkat için yarışır.

**Kipsellik ilkesi:** Moreno ve Mayer (1999) tarafından ortaya konan kipsellik ilkesi (modality principle), deneyimi az olan öğrenenlerin ekrandaki metin yerine anlatım (narration) kullanan bilgiyi daha başarılı anladığını söyler. Hoca bunun önemli olduğunu belirtti.

**Konuşulan metin:** Doğal dil doğrudan konuşulan sözcükler olarak da alınabilir; bu durumda doğrudan işitsel sistemle işlenir ve metin ses olarak alınır (ekrandan, 01:30:00). Kişi kulağına gelen seslere dikkat ederse gelen seslerin bir kısmı sözcük ses tabanına (word sound base) alınmak üzere seçilir. Bu tabandaki sözcükler örgütlenmemiş parçalardır; sonraki adım bunları zihinsel bir yapıya dönüştürür.

### 7.4 Bir resim gerçekten bin kelimeye bedel mi?

Hoca bu soruya kesin "evet" demenin rahat olmadığını söyledi; gerçekten duruma bağlıdır. Bazı araştırmacılar bir resmin bazen bir milyar kelimeye bedel olabileceğini savunurken, bazıları bazen metnin bir imgeden daha iyi olduğunu savunur.

### 7.5 Şerit diyagramı

Bir resmin karmaşık bir fikri nasıl açıklayabileceğine örnek olarak şerit diyagramı (ribbon diagram) gösterildi. Richardson diyagramı olarak da bilinir ve protein yapısının şematik gösteriminde standart bir yöntemdir. Bu diyagramda:

- alfa sarmallar (alpha helices) kıvrık şeritler olarak,
- beta iplikler (beta strands) oklar olarak,
- tekrar etmeyen yapılar (düzensiz kıvrım ya da ilmekler) ince çizgiler olarak gösterilir.

Böylece polipeptit zincirinin yapısı tek bir resimde özetlenir.

## 8. Bilişim ve Göstergebilim

### 8.1 Göstergebilim ve dalları

Görselleştirmeyle ilgili bir başka terim göstergebilimdir (semiotics). Slayttaki tanım şudur (ekrandan, 01:35:00): Göstergebilim, işaretlerin ve simgelerin iletişimin önemli bir parçası olarak incelenmesidir. Dilbilimden farklı olarak göstergebilim dil dışı işaret sistemlerini de inceler. Göstergebilim genellikle üç dala ayrılır:

- **Anlambilim (semantics):** işaretler ile gönderme yaptıkları şeyler arasındaki ilişki; işaretlerin gösterilen anlamı.
- **Sözdizim (syntactics):** biçimsel yapılarda işaretlerin kendi aralarındaki ilişkiler.
- **Edimbilim (pragmatics):** işaretler ile onları kullanan ya da yorumlayan özneler arasındaki ilişki.

### 8.2 Görsel olduğunu söyleyen üç dil

Görsel olduğu söylenebilecek üç dil örneği gösterildi:

- **Mağara resmi:** tarihten bilgi aktarır; hoca birkaç bin yıllık olabileceğini söyledi.
- **Matematiksel bir ifade:** Hoca "bunun ne olduğunu bilen var mı?" diye sordu. Bu ifade matematiksel kavramlar hakkında bilgi aktarır; yorumlayabilmek için bu matematiksel kavramları bilmek gerekir. <!-- BELİRSİZ: ifadenin ne olduğu altyazıda net değil; "entropi" sözcüğü geçiyor, karede görülmedi -->
- **Şematik diyagram:** bir sanal ortamı ve insan-bilgisayar etkileşimini oldukça soyut düzeyde gösterir. Diyagramda sanal 3B imge, gözlere optik bağlantı, kafa izleyici (head tracker), aygıt denetleyici ve grafik denetleyici yer alır. Hoca bunun insan-bilgisayar etkileşimine iyi bir örnek olduğunu söyledi.

### 8.3 Bilgisayar bilimi ile psikoloji arasındaki boşluk

Slayttaki fikir şudur (ekrandan, 01:40:00): Bilgisayar biliminin güvenilir bir insan zihni kavramı yoktur; psikoloji biliminin ise algoritmalar ve veri yapıları için sağlam kavramları yoktur. Hoca, yapay zekâdaki son gelişmelere rağmen bilgisayar biliminin hâlâ güvenilir bir insan zihni kavramından yoksun olduğunu, psikolojinin de matematiksel ya da algoritmik bir bilim olmadığını belirtti. Bu yüzden her iki alanın da yer bulduğu bir kurama ihtiyaç vardır.

Göstergebilimde işaretin iki yüzü vardır: fiziksel taraf gösteren (signifier), psikolojik taraf gösterilen (signified) olarak bilinir. Göstergebilim işaretlerin incelenmesi olduğu için temsillerden söz edebilir. Bilişim açısından algoritmalar ve veri yapıları gösteren, son kullanıcıların yorumu gösterilen taraftır.

### 8.4 İlgili alanların tanımları

Hoca kavramları özetleyen tanımları sıraladı:

- **Görselleştirme:** simgesel olanı geometriğe dönüştürerek zihinsel model oluşumunu desteklemeyi ve içgörüyü beslemeyi amaçlayan bir bilgisayar bilimi yöntemidir. Bu yönüyle bilgi keşfi (knowledge discovery) sürecinin temel bir bileşenidir.
- **Bilgi görselleştirme:** dosyalar ve yazılımlar, veri tabanları, ağlar gibi büyük ölçekli, sayısal olmayan veri koleksiyonlarının görsel gösteriminin disiplinler arası incelenmesidir; kullanıcıların bilgiyi bir bakışta görmesini, keşfetmesini ve anlamasını sağlar. Veri yapıları, yazılım, veri tabanı, ağlar ve bilgi erişimi gibi klasik bilgisayar bilimi konularıyla bağlantılıdır.
- **Veri görselleştirme:** karmaşık verinin bilgiyi açık ve etkili biçimde iletmek için görsel olarak gösterilmesidir; veriyi yararlı ve görünür kılar.
- **Görsel analitik (visual analytics):** etkileşimli görsel arayüzlerle desteklenen, karmaşık veri üzerinde analitik akıl yürütmeye odaklanır.
- **İçerik analitiği (content analytics):** yapılandırılmamış veri (örneğin metin) için görsel analitik ve iş zekâsı (business intelligence) yöntemlerini karışık olarak kullanan genel bir terimdir.

## 9. Görselleştirme Süreci ve İnsan-Bilgisayar Etkileşimi

### 9.1 Görselleştirme bir HCI konusudur

Slayttaki ifade şudur (ekrandan, 01:45:00): Görselleştirme tipik bir insan-bilgisayar etkileşimi (HCI, human-computer interaction) konusudur. Büyük ölçekli, yüksek boyutlu verinin görselleştirilmesi, veri madenciliği ve bilgi erişiminin birçok alanında bilimsel keşif için çok değerlidir. Slayttaki örnek PlotViz'dir: büyük hacimli 2 ya da 3 boyutlu veriyi bilgisayar ekranında sanal bir uzayda noktalar olarak gösteren ve kullanıcıların bu sanal uzayı etkileşimli olarak keşfetmesini sağlayan 3B bir veri noktası tarayıcısıdır. Hoca insan-bilgisayar etkileşiminin bilgisayar biliminin çok önemli bir çekirdek konusu olduğunu belirtti.

Etkileşimli görselleştirme, veriyi kavrama ve bilgi özelliklerini anında (on the fly) etkileşimli olarak çözümleme yeteneği sağlar. Hoca bir örnek olarak tıbbi benzetimlere (simulation) değindi: acemi tıp öğrencileri kuramsal kavramları, süreçleri, ilişkileri ve girişimsel işlem becerilerini öğrenirken bu benzetimlerden yararlanır; benzetimler gerçek bir ortamı yaratan yazılımlardır.

### 9.2 Veri görselleştirme sürecinin dört aşaması

Veri görselleştirme süreci, bazı geri besleme döngüleriyle birlikte dört temel aşamadan oluşur:

1. **Verinin toplanması ve saklanması:** Açık bir adımdır; veriyi toplamanız ve saklamanız gerekir.
2. **Ön işleme:** Veriyi işlenmesi daha kolay bir biçime dönüştürmek için tasarlanmış aşamadır. Veri temizleme, veri normalleştirme, boyut indirgeme teknikleri ve veri keşfi teknikleri kullanılabilir.
3. **Eşleme (mapping):** Seçilen verinin bir görsel temsile eşlenmesi.
4. **İnsan algısı ve biliş sistemi:** Görüntü kullanıcının kendi bilgisayarında oluşturulur ve insanın algı ve biliş sistemi tarafından yorumlanır. <!-- BELİRSİZ: üçüncü ve dördüncü aşamanın ayrıntıları altyazıda bozuk -->

### 9.3 İnsan, etkileşim, bilgisayar

Bunların hepsi dikkate alındığında etkileşimli görselleştirme tipik bir insan-bilgisayar etkileşimi görevidir ve grafik olarak gösterilebilir (ekrandan, 01:55:00). Şekilde üç bölüm vardır:

- **İnsan (Human):** bilişsel uzay (cognitive space), algı, insan zekâsı.
- **Etkileşim (Interaction):** görselleştirme; ekranda iki boyutlu $\mathbb{R}^2$ gösterim.
- **Bilgisayar (Computer):** hesaplama uzayı (computational space), makine zekâsı; $\mathbb{R}^n$ boyutlu veri.

Hoca, görsel eşlemelerin, kullanıcı yorumunun ve görsel-bilişsel işlemenin bu etkileşim sisteminin insan bileşeni olduğunu söyledi. Veriyi son kullanıcı için anlaşılır kılmak tipik bir insan-bilgisayar etkileşimi görevi olarak bilinir. Bu yüzden görselleştirmenin hesaplamalı bilimlerin ortak paydası olduğu söylenebilir. Bir yanda simge yapıları ve veri işleme dönüşümleri, öte yanda klavye, fare gibi etkileşim aygıtları ve bu iki alan arasındaki etkileşimler vardır.

### 9.4 Zihinsel modeller

Görselleştirme bir bilgi oluşturma süreci olarak da görülebilir. Zihinsel modeller (mental models), görselleştirmelerin soyutlamaları olarak görülebilir. Zihinsel model ile iç temsil arasındaki ilk adım içselleştirmedir (internalization). <!-- BELİRSİZ: zihinsel model slaytının devamı altyazıda bozuk -->

### 9.5 Algısal görsel işleme modeli

Görsel işleme için üç aşamalı bir model gösterildi (ekrandan, 02:00:00):

- **Aşama 1:** Ekrandan (display) gelen görüntüden düşük düzeyli özelliklerin (features) paralel işlemeyle çıkarılması.
- **Aşama 2:** Örüntü algısı (pattern perception). Görme alanı bölgelere ve örüntülere ayrılır; şekilde bu kısım "ne" sistemi ("What" system) olarak etiketlenmiştir.
- **Aşama 3:** Görsel çalışma belleği (visual working memory), sözel çalışma belleği (verbal working memory), öz (GIST), görsel sorgu (visual query) ve benmerkezci nesne ve örüntü haritası (egocentric object and pattern map). Buradan "eylem" sistemi ("Action" system) bilgi sistemine geri döner.

Hoca, ilk aşamadaki imgenin biyolojik olarak çok kısa süre saklandığını, bir nesnenin orada yalnız kısa bir süre kaldığını belirtti.

## 10. Görselleştirme Yöntemlerinin Sınıflandırılması

### 10.1 Görselleştirme yöntemlerinin periyodik tablosu

Hoca "Kaç görselleştirme yöntemi vardır?" diye sordu. Bunun bilgisayar biliminde bir alan olduğu söylendiğine göre çok sayıda yöntem olmalıdır. Hoca bu dersin bir görselleştirme dersi olmadığını, yöntemlerin kısa bir özetinin verileceğini söyledi. Yöntemleri sıkışık biçimde aktarmak için yine bir görselleştirme tekniği kullanıldı: visual-literacy.org sitesindeki "görselleştirme yöntemlerinin periyodik tablosu" (a periodic table of visualization methods) paylaşıldı (ekrandan, 02:05:00). Tablodaki gruplar renklerle ayrılmıştır:

- **Veri görselleştirme (data visualization):** nicel verinin şematik biçimde görsel gösterimi. Örnekler: süreklilik (continuum), tablo, kartezyen koordinatlar, pasta grafik, çizgi grafik, çubuk grafik, alan grafiği, histogram, saçılım grafiği, Tukey kutu grafiği, spektrogram.
- **Bilgi görselleştirme (information visualization):** bilişi güçlendirmek için verinin etkileşimli görsel gösterimleri. Örnekler: radar grafiği (cobweb), paralel koordinatlar, Sankey diyagramı, veri haritası.
- **Kavram görselleştirme (concept visualization):** ağırlıklı olarak nitel kavramları, fikirleri, planları ve analizleri ayrıntılandırma yöntemleri. Örnekler: Gantt şeması, PERT şeması, kavram haritası.
- **Strateji görselleştirme (strategy visualization):** örgütlerde stratejilerin analizi, geliştirilmesi, oluşturulması, iletilmesi ve uygulanmasında tamamlayıcı görsel gösterimlerin sistematik kullanımı.
- **Metafor görselleştirme (metaphor visualization):** bilgiyi grafik olarak konumlandıran ve yapılandıran görsel metaforlar. Örnekler: metro haritası, hikâye şablonu.
- **Bileşik görselleştirme (compound visualization):** farklı grafik gösterim biçimlerinin tek bir şema ya da çerçevede tamamlayıcı kullanımı.

Tabloda ayrıca süreç (process) ve yapı (structure) görselleştirmesi, genel bakış (overview), ayrıntı (detail), ayrıntı ve genel bakış birlikte, ıraksak düşünme (divergent thinking) ve yakınsak düşünme (convergent thinking) işaretleri vardır. Hoca tablonun üzerinde gezinerek bazı örnekleri gösterdi; paralel koordinatlar için açılan örnek görüntü karede görülüyor. Sözlü olarak Petri ağları, akış şemaları (algoritma tasarımında yaygın kullanılır), kümeleme türü bilgi görselleştirme, veri haritaları, dinamik benzetim, veri akış diyagramları ve anlamsal ağlar da anıldı.

### 10.2 Taksonomi

Ardından bu sınıflar slaytlarla açıklandı (ekrandan, 02:10:00 ve 02:15:00):

- **Veri görselleştirme**, pasta grafikler, alan grafikleri ya da çizgi grafikleri gibi standart nicel biçimleri içerir. Bunlar nicel verinin şematik biçimdeki (eksenli ya da eksensiz) görsel gösterimleridir; genel amaçlıdır ve çoğunlukla veriye genel bir bakış elde etmek için kullanılır.
- **Bilgi görselleştirme**, anlamsal ağlar (semantic networks) ya da ağaç haritaları (tree-maps) gibi, bilişi güçlendirmek için verinin etkileşimli görsel gösterimlerinin kullanılması olarak tanımlanır. Bu, verinin bir imgeye dönüştürüldüğü, yani ekran uzayına eşlendiği anlamına gelir. İmge, kullanıcılar onunla çalıştıkça değiştirilebilir.

Hoca bu yöntemlerin çok kullanıldığını, programlarınızın sonuçlarının da büyük olasılıkla bu görselleştirmelerden biri olacağını, bu yüzden bu tekniklerin bilinmesi gerektiğini söyledi.

### 10.3 Pasta grafik ne zaman kullanılır?

Hoca örnek olarak pasta grafiği ele aldı: hangi veri için ve ne zaman kullanılır? Veri analizi kısmında veri türlerinden söz edildiğini hatırlattı: kategorik ya da sayısal veriniz olabilir; kategorik veri de nominal olabilir. Veriniz nominal ise ve toplam veri içinde kategorilerin yüzdelerini görmek istiyorsanız, örneğin $n$ farklı kategoriniz varsa ve bu kategorilerin miktarını görmek istiyorsanız pasta grafik kullanabilirsiniz. Normal işlem adımları şöyledir:

1. Kategorilerin sıklıklarını (frequencies) belirlemek.
2. Oranları, yani normalleştirilmiş sıklıkları belirlemek.
3. Bunları yüzdeye çevirmek ve pasta grafik olarak çizmek.

Bütün kategorilerin miktarını çubuk grafik olarak da gösterebilirsiniz; bu, ne iletmek istediğinize bağlıdır. Hoca, kullanılacak görselleştirme türünün çoğu durumda görselleştirilecek verinin türüyle belirlendiğini vurguladı. Kategorik veri için çizgi grafikleri uygun bir görselleştirme tekniği değildir; çizgi grafikleri sayısal veri için kullanılır. Seçim veri türüne göre yapılmalıdır; ancak o zaman bilgi son kullanıcıya özlü biçimde iletilebilir. Bilgi görselleştirme kullanmak istiyorsanız anlamsal ağlar ya da ağaç haritaları kullanılabilir.

> **Hocanın vurgusu:** Seçimi veri türüne göre yapmak zorundayız.

### 10.4 Kavram, metafor ve bileşik görselleştirme

Kavram görselleştirmeye web sayfasında örnekler görüldü: kavram haritası ya da ünlü Gantt şeması ve PERT şeması. Hoca Gantt şemasında bir sistemin geliştirme yaşam döngüsü kavramlarının görselleştirildiğini söyledi. Bunlar ağırlıklı olarak nitel kavramları, fikirleri, planları ve analizleri ayrıntılandırma yöntemleridir.

Metafor görselleştirmeye örnek olarak metro haritası ve hikâye şablonu verildi. Metafor görselleştirmeleri karmaşık içgörüleri iletmek için etkili ve basit şablonlar olarak kullanılabilir; karmaşık bir haritayı tek sayfada çizemezsiniz, ama basit çizimlerle temsil edebilirsiniz. Kullanılan metaforun temel özellikleri bilgiyi taşır.

Bileşik görselleştirme, önceki biçimlerin birkaçından oluşur. Nicel grafikler içeren kavramsal karikatürler, metaforik öğeler içeren karmaşık bilgi haritaları ya da duvar büyüklüğünde info-muraller (infomurals) bu türdendir. Tek bir çerçevede farklı grafik gösterim biçimlerinin tamamlayıcı kullanımını belirtir; iki ya da daha çok uzamsal olarak ayrı ve her biri bağımsız çalışabilen veri gösteriminden oluşur.

Hoca, yüzlerce farklı teknik olduğunu, bir grafik paketiyle oynarsanız bu kavramların çoğunu orada göreceğinizi söyledi.

## 11. Grafikler, Veri Türleri ve Teknik Seçimi

### 11.1 Grafik nedir?

Hoca bazı görsel ilkeleri ele aldı. Farklı grafik türleri ve farklı özellikleri vardır. Görselleştirmenin bir tür yalana, yani gerçeği çarpıtmaya (manipulating the truth) da neden olabileceğini belirtti.

Grafik, varlıklar arasındaki bir ya da daha çok ilişkiyi gösteren görsel bir sunumdur. Bilgiyi temsil etmenin kısa bir yoludur; bir eğilimin, örüntünün ya da karşılaştırmanın kolayca kavranmasını sağlar. Bir grafiğin bileşenleri:

- **Çerçeve (framework):** zemini hazırlar; ne tür ölçme ölçeklerinin kullanılacağını belirler.
- **İçerik (content):** işaretler, noktalar, simgeler, çizgiler, alanlar, çubuklar.
- **Etiketler (labels):** başlık, eksenler, çentik işaretleri (tick marks) vb.

### 11.2 Çizelgeler ve haritalar

- **Çizelgeler (charts):** Ayrık varlıklar varsa bu ayrık varlıklar arasındaki ayrık ilişkileri gösterir. Yapı, varlıkları birbirine bağlar; çizgiler ve göreli konum bağlantı işlevi görür.
- **Haritalar (maps):** İç ilişkiler kısmen resmedilen şeyin uzamsal ilişkileriyle belirlenir. Etiketler konumlarla eşlenir. Örnekler: nüfus sayımı verisi haritası, topografik haritalar.

### 11.3 Veri türleri

Hoca, görselleştirmelerin veriye dayandığı için temel veri türlerini hatırlatmak gerektiğini söyledi: verinin türünü bilirseniz doğru görselleştirmeyi seçebilirsiniz. Nominal ve aralık (interval) veri türleri anıldı. <!-- BELİRSİZ: veri türleri listesinin ortası altyazıda bozuk; büyük olasılıkla nominal, sıralı, aralık ve oran türleri sayıldı -->

Ardından yaygın grafik türleri üzerinde bir örnek gösterildi: günlere göre erişim sayısının çizgi grafiği, erişim sayısının nokta grafiği (dot plot) ve sayfa uzunluğu (kısa, orta, uzun) gibi değişkenler. Hoca buradaki veri türlerini tahmin etmeyi önerdi: günlere göre erişim sayısı, hangi web sayfasına kaç kez erişildiği gibi.

### 11.4 Saçılım grafikleri ve diğer teknikler

Saçılım grafikleri (scatter plots), en eski nokta tabanlı tekniklerdir; $n$ boyutlu bir uzaydaki veriyi rastgele $k$ boyutlu bir gösterim uzayına izdüşürür. Slaytta saçılım grafiğinin değişkenlerin yüksek korelasyonlu olup olmadığını nitel olarak belirlemeye yaradığı yazıyor (ekrandan, 02:30:00). Slayttaki örnekte x ekseni kariyer boyunca yapılan home run sayısı, y ekseni maaştır; noktalar vuruş sayısına göre renklendirilmiştir.

Hoca ardından başka teknikleri kısaca gösterdi:

- **Paralel koordinatlar (parallel coordinates).**
- **RadViz (radyal koordinat görselleştirme):** kuvvete dayalı (force-driven) bir nokta yerleşim tekniği.
- **Radar grafiği:** örümcek ağı grafiği, yıldız grafiği gibi farklı adlarla anılan, aynı kavramı ifade eden radyal eksenli bir tekniktir. <!-- BELİRSİZ: radar grafiğinin diğer adları altyazıda bozuk ("poligraf" diye tekrarlanıyor) -->
- **Isı haritası (heat map):** birçok alanda yaygın kullanılır; sayılar yerine renk kullanan tablo biçimli bir gösterimdir, örneğin gen ifadesi verisi için.
- **Glifler (glyphs)** ve daha birçok farklı teknik.

### 11.5 Hangi tür ne zaman kullanılır?

Elbette hangi türün ne zaman kullanılacağı önemlidir. Slayttaki öneriler (ekrandan, 02:35:00):

- **Çizgi grafik:** x ekseni nicel bir değişken gerektirir; değişkenlerin bitişik (contiguous) değerleri vardır; sıralı değişkenler arasında bilinen ya da alışılmış bir sıralama bulunur.
- **Çubuk grafik:** göreli nokta değerlerinin karşılaştırılması.
- **Saçılım grafiği:** iki değişken arasındaki ilişkinin genel izlenimini aktarmak.
- **Pasta grafik:** az sayıda değer arasındaki oran farklarını vurgulamak. Hoca daha önce verdiği örneği hatırlattı: kategorik veride kategori üyelerinin oranlarını belirlemek.

### 11.6 Başka bir sınıflandırma ve araştırma bulguları

Görselleştirmelerin bir başka sınıflandırması şöyle verildi: grafikler; tablolar (sayısal tablolar, grafik tablolar); çizelgeler (zamana bağlı çizelgeler, ağ çizelgeleri, yapı diyagramları, ağ diyagramları); haritalar; kartogramlar; simgeler; resimler.

Hoca görselleştirmelerle ilgili bazı çalışmaların ilginç bulgularını aktardı:

- Fotogerçekçi imgeler en az bilgilendirici olanlardır.
- Simge çalışmalarının sonuçlarına göre daha az karmaşık, daha şematik imgeler kullanmak daha iyidir.
- Grafik ve tablolar literatürde en çok incelenen kategorilerdir; bunları karşılaştıran sonuçlar kesin değildir.
- Kartogramları anlamak zordur.
- Uzamsal ayrımı kolaylaştırmak için noktaları çerçeveli bir dikdörtgen içine koymak daha iyidir. <!-- BELİRSİZ: bu madde altyazıda "framed rectangle to each special separation" diye bozuk geçiyor -->
- Zamansal veriyi göstermek uzamsal veriyi göstermekten daha zordur.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:20:38): Algı (perception) nedir?

> **Cevap (derste verildi):** Algı, dünyayı duyularımızla deneyimlememizdir: görme, duyma ya da duyular yoluyla bir şeyin farkına varma yeteneği; bir şeyin nasıl görüldüğü, anlaşıldığı ya da yorumlandığı. Bellek gibi bilişsel işlevlere dayanır ve algı süreci sayesinde çevresel uyaranları tanır ve onlara tepki veririz (ekrandan, 00:25:00).

**Soru 2** (ekrandan, 00:35:00): Görme duyusu için algı sürecinin adımlarını sırasıyla yazınız.

> **Cevap (derste verildi):** Çevresel uyaran → dikkat edilen uyaran → retinada görüntü → dönüştürme (transduction) → sinirsel işleme → algı → tanıma → eylem.

**Soru 3** (ekrandan, 00:45:00; derste sözlü, 00:45:15): Diğer duyular (koku, tat, dokunma, duyma) biyolojik veriyi temsil etmek için neden yaygın kullanılmaz? Bir DNA bölgesini duyabilir ya da bir mikrodizi deneyinin sonucunu koklayabilir miyiz?

> **Cevap (derste verildi):** Kavramsal bir engel yoktur, ama pratik sınırlar vardır: uygun bir temsil yöntemi gerekir. Ayrıca görme, birim zamanda en çok bilgiyi taşıyan, yani en yüksek bant genişliğine sahip duyudur.

**Soru 4** (ekrandan, 00:50:00): Görselleştirme neden bu kadar önemlidir?

> **Cevap (derste verildi):** "Çünkü insanlar öyle." Yaratıcı olan, bir fikri fark eden ve bilimsel gelişmeyi sağlayan insandır; insan görme sistemi örüntü tanımada çok iyidir ve bir örüntünün algılanması çoğu zaman içgörünün temelidir.

**Soru 5** (derste sözlü, 01:31:23): Bir resim gerçekten bin kelimeye bedel midir?

> **Cevap (derste verildi):** Duruma bağlıdır. Bazı araştırmacılar bir resmin çok daha fazlasına bedel olabileceğini, bazıları ise kimi durumlarda metnin imgeden daha iyi olduğunu savunur.

**Soru 6** (derste sözlü, 02:00:44): Kaç görselleştirme yöntemi vardır? Ana gruplar nelerdir?

> **Cevap (derste verildi):** Yüzlerce yöntem vardır. Görselleştirme yöntemlerinin periyodik tablosu bunları veri, bilgi, kavram, strateji, metafor ve bileşik görselleştirme olarak gruplar (ekrandan, 02:05:00).

**Soru 7** (derste sözlü, 02:10:35): Pasta grafik ne zaman ve hangi tür veri için kullanılır?

> **Cevap (derste verildi):** Nominal kategorik veride kategorilerin toplam içindeki paylarını göstermek için kullanılır. Önce kategorilerin sıklıkları bulunur, normalleştirilir, yüzdeye çevrilir ve çizilir. Az sayıda değer arasındaki oran farklarını vurgular (ekrandan, 02:35:00). Aynı bilgi çubuk grafikle de gösterilebilir; kategorik veri için çizgi grafik uygun değildir.

**Soru 8** (ekrandan, 02:35:00): Çizgi grafik, çubuk grafik ve saçılım grafiği hangi durumlarda kullanılır?

> **Cevap (derste verildi):** Çizgi grafik: x ekseni nicel, değerler bitişik, sıralı değişkenler arasında alışılmış bir sıra var. Çubuk grafik: göreli değerleri karşılaştırmak. Saçılım grafiği: iki değişken arasındaki ilişkinin genel izlenimini vermek; değişkenlerin korelasyonlu olup olmadığını nitel olarak görmek.

## Dersin Toparlaması

Bu derste biyoenformatikte görselleştirme konusu tanımlardan başlayarak ele alındı. Önce algı ve görme duyusundaki algı süreci anlatıldı; normal bir yetişkinin bilginin yaklaşık %80'ini görme ile aldığı, görmenin en yüksek bant genişliğine sahip duyu olduğu ve insan görme sisteminin örüntü tanımada çok güçlü olduğu vurgulandı. Ardından veri görselleştirme ile bilgi görselleştirme ayrımı, bilgi görselleştirmenin amaçları ve hedefleri, sözel ve görsel bilginin bilişte nasıl farklı işlendiği (ikili kodlama kuramı, anlamsal belirsizlik, Mayer'in modeli, kipsellik ilkesi) ve bilişimin göstergebilimle ilişkisi tartışıldı. Görselleştirme süreci dört aşamalı bir insan-bilgisayar etkileşimi görevi olarak ele alındı ve algısal görsel işlemenin üç aşamalı modeli gösterildi.

Dersin son bölümünde görselleştirme yöntemlerinin periyodik tablosu üzerinden yöntemlerin sınıflandırması yapıldı; grafiklerin bileşenleri, çizelge ve haritalar, saçılım grafiği, paralel koordinatlar, RadViz, radar grafiği ve ısı haritası gibi teknikler tanıtıldı ve hangi grafiğin hangi veri türü için seçileceği tartışıldı. Hoca kapanışta görselleştirmenin her alanda kullanıldığını, kendi algoritmik ve matematiksel teknikleri olan ayrı bir dal olması gerektiğini, bu dersin amacının ise ayrıntılara girmek değil, önemini ve temel kavramlarını göstermek olduğunu söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
