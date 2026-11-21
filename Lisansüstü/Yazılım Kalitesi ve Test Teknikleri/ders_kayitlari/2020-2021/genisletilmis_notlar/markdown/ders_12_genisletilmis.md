# Ders 12 Genişletilmiş Notu: Öğrenci Makale Sunumları (Kalite Tahmini, Test Kâhini, Test Önceliklendirme, Model ve Risk Tabanlı Test)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Yapısı
- 2. GitHub Depolarında Yazılım Benzerliği
- 3. Çevik Yaklaşımla Kritik Sistemlerde Güvenlik ve Kalite Güvencesi
- 4. Otomatik Yazılım Onarımı
- 5. Makine Öğrenmesiyle Yazılım Kalite Tahmini
- 6. Kötü Koku, Yeniden Düzenleme ve Kullanıcı İncelemeleri
- 7. Test Edilemeyen Sistemler ve Test Kâhini Problemi
- 8. Modern Yazılım Sistemlerinde Test Senaryosu Önceliklendirme
- 9. Dağıtık Sürekli Çevik Testte Geliştirici ile Test Uzmanı İletişimi
- 10. Açık Kaynaklı Yazılımda Kalite Güvencesi
- 11. Model Tabanlı ve Risk Tabanlı Testin Karşılaştırılması
- Örnek Sorular

## 1. Dersin Yapısı

Bu ders bütünüyle öğrencilerin makale sunumlarına ayrılmıştır. Her sunum yaklaşık 12-15 dakika sürmüştür. Hoca zaman zaman sunucudan dersle tekrar eden giriş kısımlarını (kalite tanımı, kalite faktörleri, açık kaynak kavramı gibi) atlamasını ve doğrudan makalenin özgün kısmına geçmesini istemiştir. Aşağıda her sunum, derste anlatılan sırayla ve yalnız akademik içeriğiyle verilmiştir.

Sunumlardan ikisinin (otomatik yazılım onarımı ve dağıtık çevik test) ses kaydı büyük ölçüde anlaşılmazdır. Bu iki bölüm daha çok ekrandaki slaytlara ve anlaşılan birkaç cümleye dayanır.

## 2. GitHub Depolarında Yazılım Benzerliği

### 2.1 Neden benzer depolar aranır?

Sunucu konuyu, açık kaynak dünyasında kendi projemize benzeyen depoları bulmayı sağlayan otomatik bir yaklaşım olarak tanıtmıştır. Açık kaynak depolardaki hazır parçaları uyarlayarak yeni sistem geliştirmek yaygın bir pratiktir. Bu depolarda değerli bilgi vardır ve bu bilginin çıkarılması (mining) gerekir. Benzer projelerin yeniden kullanımı maliyet açısından fayda sağlar. Sunumdaki bir alıntıya göre, mevcut bir projeden yeniden kullanılan kodun kalitesi, sıfırdan yazılmış bir kodun ilk sürümlerinden daha iyidir.

Depo madenciliğinin amacı, geliştiriciye geçmiş deneyime dayanan anlamlı öneriler sunmaktır. Örneğin yeni bir proje üzerinde çalışan geliştirici, benzer projelerle karşılaştırma sonucu hangi kütüphaneleri kullanması gerektiğini görebilir. Geliştiriciyi izleyerek öneri yapan geliştirme ortamları da yapılabilir.

Kopyala-yapıştır kodun çalınmasının da önünü açar. Ancak "bir kod şu koşulları sağlıyorsa kesin kopyalanmıştır" demek zordur, çünkü benzerlik türü kullanılan karşılaştırma yöntemine bağlıdır. Açık kaynak yazılımlar farklı alanlarda olsalar bile aynı soyutlamayla açıklanan özellikleri uyguluyorlarsa benzer kabul edilir.

### 2.2 İçerik tabanlı ve işbirlikçi filtreleme

Benzerlik kavramı öneri sistemlerinin temelidir. Sunucu bunu bir yemek sipariş uygulamasıyla anlatmıştır:

- **İçerik tabanlı filtreleme:** Yemeklerin içeriği (malzemeleri, kalorisi) önceden biliniyorsa kullanıcıya sipariş ettiği yemeğe benzer yemekler önerilir.
- **İşbirlikçi filtreleme:** Sistemin yemekler hakkında hiç bilgisi yoksa, kullanıcınınkine benzer siparişler veren ya da benzer yaşta ve konumda olan kullanıcılar bulunur. Onların siparişleri üzerinden öneri yapılır.

### 2.3 Düşük ve yüksek seviyeli benzerlik

- **Düşük seviyeli benzerlik:** Kod bazındaki benzerliktir; iki kodun birbirine benzemesi.
- **Yüksek seviyeli benzerlik:** Koddan bağımsız meta verilere dayanır: README dosyaları, yorum satırları, aynı kullanıcılar tarafından yıldızlanma gibi.

### 2.4 Önceki yaklaşımlar

**MudaBlue (2004).** Kaynak kodu kullanır. Ön işleme aşamasında değişken ve fonksiyon adları gibi tanımlayıcıları çıkarır, yorum satırı gibi etkisiz öğeleri siler. Sonra Latent Semantic Analysis (LSA) uygular: yazılım bir belge, her tanımlayıcı bir kelime gibi değerlendirilir. LSA geniş bir metin topluluğuna istatistiksel hesaplar uygulayarak kelimelerin bağlamsal anlamını çıkarır; sunucu bunu doğal dil işlemeye benzetmiştir.

**CLAN (2012).** McMillan, Grechanik ve Poshyvanyk'in çalışmasıdır. Benzer Java uygulamalarını otomatik bulmak için paket ve sınıf hiyerarşilerine karşılık gelen anlamsal katmanları kullanır. Varsayımı şudur: iki uygulama aynı soyutlamayla açıklanan gereksinimleri uygulayan API çağrılarına sahipse benzerdir. Ekrandaki slayt şöyledir (ekrandan, 00:10:00):

- CLAN, bir uygulamanın benzerliğini hesaplamak için API çağrılarını anlamsal bağlantı (semantic anchor) olarak kullanır.
- Girdi olarak yazılım uygulamasının tamamını kullanır ve kaynak kod dosyalarını bir terim-belge matrisi (TDM) olarak temsil eder.
- TDM'de her sütun bir belgeye, her satır bir terime karşılık gelir.
- Matristeki her hücre, karşılık gelen terimin belgede görünme frekansıdır.

MudaBlue ve CLAN ikisi de kod bileşenlerini (değişkenler, fonksiyon adları, API çağrıları) TDM ile temsil edip LSA uygular. CLAN yalnız API çağrılarını dikkate aldığı için daha yüksek hassasiyet elde ettiğini iddia eder.

**RepoPal (2017).** Diğer ikisinin aksine yüksek seviyeli benzerlik kullanır; girdi olarak yalnız depo meta verilerini alır. İki GitHub deposu benzer README dosyalarına sahipse, benzer ilgi alanlı kullanıcılarca yıldızlanmışsa ve kısa süre içinde aynı kullanıcılarca yıldızlanmışsa benzer sayılır.

- Yıldız tabanlı benzerlikte iki kullanıcı arasındaki benzerlik, yıldızladıkları depo kümelerinin Jaccard indeksidir.
- Zaman tabanlı benzerlikte, bir kullanıcı iki depoyu kısa süre içinde yıldızladıysa (örneğin bir araştırma yaparken) iki depo benzer kabul edilir.
- Toplam benzerlik bu benzerliklerin çarpımıdır.

> **Ek bilgi (derste anlatılmadı):** İki küme $A$ ve $B$ için Jaccard indeksi $J(A,B) = \dfrac{|A \cap B|}{|A \cup B|}$ biçiminde tanımlanır. Değer 0 ile 1 arasındadır. Ortak eleman yoksa 0, kümeler aynıysa 1 olur.

### 2.5 CrossSim: graf tabanlı hibrit yaklaşım

Sunulan makalenin yaklaşımı CrossSim'dir. Graflar esnek veri entegrasyonuna izin verdiği ve çok sayıda benzerlik ölçümünü kolaylaştırdığı için seçilmiştir. Hem düşük hem yüksek seviyeli benzerliği tek modelde kullanır. Açık kaynak ekosistemindeki varlıklar arasındaki ilişkiler (bir sınıfın başka bir sınıfı genişletmesi, bir kütüphanenin bir projede kullanılması, bir geliştiricinin bir sınıfı geliştirmesi, bir kullanıcının bir projeyi yıldızlaması) graf kenarları olur. Graf benzerliğinde sezgisel bir tanım örneği: 1 ve 2 numaralı düğümler, ikisi de 5 numaralı düğüm tarafından işaret edildiği için benzerdir.

## 3. Çevik Yaklaşımla Kritik Sistemlerde Güvenlik ve Kalite Güvencesi

### 3.1 Karmaşık sistemler

Güvenlik açısından kritik sistemler, bileşen sayısı, bileşenler arası etkileşim ve gömüldükleri daha geniş sistemlerle etkileşim arttıkça karmaşıklaşır. Böyle bir ortamda güvenlik, bileşenlerden ve aralarındaki etkileşimlerden ortaya çıkan bir özelliktir. Bu yüzden kritik sistemler öngörülemeyen biçimlerde başarısız olabilir. Çevik yöntemler faydalarına rağmen kritik sistemlerde henüz yaygın değildir. Bu sistemlerin güvenliği için bazı kalite güvencesi uygulamalarının çevik geliştirmeye eklenmesi gerekir.

Karmaşıklığın ve yeniliğin ana kaynağı yazılımdır. Örneğin tıbbi cihazlardaki yeniliklerin çoğu yazılım bileşenindedir. Sunumda verilen veriye göre 2011'de ABD'deki tıbbi cihaz hatalarının %24'ü yalnız yazılım hatalarına bağlanmıştır. Bu orana ilk akla gelen tepki yenilik süreçlerindeki denetimi artırmaktır. Asıl sorun, karmaşık sistemlerdeki yeniliklerden doğan zarar risklerinin nasıl tespit edilip kontrol edileceğidir.

### 3.2 Cynefin çerçevesi

Cynefin çerçevesi farklı sistem ve durum türlerini belirtileri ve uygun yanıtlarıyla birlikte tanımlar. Beş durum vardır: basit, komplike, karmaşık, kaotik ve düzensizlik. Sunum konuyla ilgili iki duruma odaklanmıştır.

**Komplike durum.** Neden ile sonuç arasında sabit bir ilişki vardır, ama açık değildir; görmek için uzman bilgisi ya da analiz gerekir. Durum bilinebilir, ancak nasıl algılanacağını ve en iyi nasıl yanıt verileceğini belirlemek birkaç uzmanın bilgisini gerektirebilir. İyi uygulamaların kullanılması ve süreçler oluşturulması pratik yaklaşımlardır. Önerilen model "algıla, analiz et, yanıtla"dır. Yazılımda örneği konfigürasyon yönetimidir, çünkü konfigüre edilebilir öğeler arasında çok sayıda ilişki vardır.

**Karmaşık durum.** Slayttaki tanım şöyledir (ekrandan, 00:20:00):

- Karmaşık sistemlerle karşılaşıldığında düzensizlik söz konusudur.
- Bu sistemlerde neden-sonuç ilişkisini önceden açıklamak mümkün değildir.
- Problem karmaşık olduğunda doğru cevabı ya da neyin doğru cevabı üreteceğini tahmin etmek zorlaşır.
- Örneğin yazılım geliştirme planlaması bir görevin ne kadar süreceğine dair tahmin gerektirir; bu tahmini yapmak zordur.
- Bu durum, hem problem hem çözümler hakkında bilgi edinmek için Cynefin'in önerdiği "Dene (Probe) - Algıla (Sense) - Yanıtla (Respond)" öğrenme yaklaşımına uygundur.

Karmaşık durumda pratik yaklaşım soruna adım adım yaklaşmak ya da kısa tekrarlar üzerinde çalışmaktır.

### 3.3 Yazılım tasarımı ile yazılım üretimi ayrımı

Sunucu farkı anlatmak için yazılım tasarımı ile yazılım üretimini ayırmıştır, çünkü her biri farklı yaklaşım ve farklı kalite kontrolü gerektirir.

- **Yazılım tasarımı** karmaşıktır. Uygun strateji, çevik yöntemlerde tipik olan artımlı geliştirmeyle yapılan bir araştırmadır. Bu yüzden "dene-algıla-yanıtla" tasarım için uygundur.
- **Yazılım üretimi**, tamamlanmış bir tasarımı çalışan yazılıma dönüştürmektir. Komplike olabilir ama karmaşık değildir, çünkü sonucun nihai durumu, araçlar zor olsa ya da birkaç uzmanın emeği gerekse bile tahmin edilebilir. Geçmiş üretimin algılandığı, verinin analiz edildiği ve yöntemin buna göre iyileştirildiği "algıla-analiz et-yanıtla" modeline uygundur.

### 3.4 Çevik geliştirmenin güçlü ve zayıf yanları

Çevik geliştirme her biçiminde sistemin küçük bir bölümünü üretip değerlendirir, öğrendiğini sonraki geliştirmede kullanır. Olası çözümleri üretip test ederek sorunu araştırır. Sürekli test ve müşteri taleplerine hızlı yanıt mantığı vardır. Riski, uygulanabilir görünen bir çözümün sonradan yalnız bazı durumlar için uygulanabilir olduğunun ortaya çıkmasıdır. Çevik ekipler genellikle küçük, kendi kendini yöneten ve çoğu deneyimli geliştiricilerden oluşan ekiplerdir.

Tartışmalarda çoğu zaman eksik kalan nokta şudur: çevik geliştirmede hız ve yanıt verebilirlik için plan tabanlı geliştirmenin titizliğinden ödün verilir. Çevik geliştirme doğrulama önyargısına da açıktır. Ekip yazılımın neyi amaçladığını bildiği için, yazılımın amaçlananı yaptığını doğrulayan kanıt arama eğilimindedir. Bu ihmal ya da yetersizlik değil, kanıtı yerleşik bir düşünceye göre yorumlamaktır. Bunu önlemek ve bağımsız bir denetim yapabilmek için geliştiricinin gereksinimleri, uygulama kararlarını ve gerekçelerini belgelemesi, kodun da kendini belgelemesi gerekir.

Çalışmanın sonucu: kritik sistemlerde karmaşık problemlerle başa çıkmak için çevik yaklaşım kaçınılmaz olarak benimsenecektir, çünkü problem çözmeyi ve tasarımı plan tabanlı yöntemlerden daha iyi destekler. Karmaşık sistemleri tasarlamak için "dene-algıla-yanıtla", tasarımı belirlenmiş bir sistemi üretmek için "algıla-analiz et-yanıtla" uygundur.

## 4. Otomatik Yazılım Onarımı

Bu sunumun ses kaydının büyük kısmı anlaşılmazdır. Aşağıdaki içerik ekrandaki slaytlardan ve anlaşılan İngilizce cümlelerden derlenmiştir.

### 4.1 İki yaklaşım: healing ve repairing

Program hatalarıyla otomatik başa çıkmanın bilinen iki yaklaşımı vardır (ekrandan, 00:30:00):

1. Yazılım iyileştirme (software healing)
2. Yazılım onarımı (software repairing)

İkisi ilke olarak benzerdir ama amaçları ve hatayı ele alma yolları farklıdır. Slayttaki şemaya göre her ikisi de hata algılamayla (failure detection) başlar:

- **İyileştirme süreci** iyileştirme (healing) ve doğrulama (verification) adımlarından oluşur. İyileştirme adımı, algılanan başarısızlığı önleyebilecek ya da etkisini azaltabilecek işlemi çalıştırır. Sonuç ya "başarılı çalışma / hatalı program" ya da "başarısız çalışma / hatalı program" olur. İlki, çalışma kurtarılmış ama programın hâlâ hatalı olduğu anlamına gelir; aynı hata yeniden ortaya çıkabilir.
- **Onarım süreci** yerelleştirme (localization), yama üretimi (patch/fix) ve doğrulama adımlarından oluşur. Yerelleştirme hatanın nerede oluştuğunu bulur. Yama adımı o konumdaki yazılımı değiştiren düzeltmeler üretir. Sonuç "başarısız çalışma / düzeltilmiş program" ya da "başarısız çalışma / hatalı program" olabilir.

**Soru:** Healing işlemleri, çalışma sırasında hatayı özümseyip hataya rağmen çalışmayı sürdüren ve o anda düzelten işlemler diyebilir miyiz? **Cevap:** Evet. Sunucu bunu hatayı yalnız örten bir yara bandına benzetmiştir.

### 4.2 Genel ve hataya özgü teknikler

Slayta göre onarım teknikleri genel ya da hataya özgü (fault-specific) olarak tasarlanabilir (ekrandan, 00:35:00). Genel teknikler belirli bir hata sınıfını hedeflemez ve bir programdaki herhangi bir hata sınıfını onarabilir. Hataya özgü teknikler belirli hata sınıflarını ele almak için tasarlanır; kapsamları dar, verimleri yüksektir.

Sunucu Java için iki araç adı vermiştir. Bunlardan biri tek bir koşul ifadesindeki (if ya da döngü koşulu) hataları düzeltir. Diğeri yazılımın çalışma sırasındaki davranışını gözlemleyip karşılaştırarak çalışır.

<!-- BELİRSİZ: Araç adları altyazıda "Noble" ve "Bacica" diye geçiyor. İlki büyük olasılıkla Nopol'dür; ikincisinin adı çıkarılamadı. -->

### 4.3 Yama üretimi: üret-ve-doğrula ve anlam güdümlü yaklaşım

Yama üretiminde iki yaklaşım anılmıştır: üret-ve-doğrula (generate and validate) ve anlam güdümlü (semantic-driven) yaklaşım. Anlam güdümlü yaklaşımın şeması şöyledir (ekrandan, 00:40:00):

```text
Girdiler: test senaryoları, program spesifikasyonu, özgün program P

davranış analizi (behavioral analysis)
    -> anlamsal bilgi üretir
problem üretimi (problem generation)
    -> onarım probleminin biçimsel kodlamasını üretir
yama üretimi (fix generation)
    -> sonuç: "çözüm yok" ya da "onarılmış program S"
```

Sunucunun anlatımına göre ilk adım (davranış analizi) problemi analiz eder. Sonuçta teknik, problemi düzeltmenin yollarını önererek yazılımı hatadan onarır.

<!-- BELİRSİZ: Sunumun 00:26-00:43 arasının büyük kısmı ses kaydında anlaşılmıyor; ara slaytların içeriği notta yok. -->

Hoca sunumun ardından konunun IEEE Transactions on Software Engineering dergisinden alındığını, bu dergideki makalelerin karmaşık konuları derinlemesine incelediğini ve özetlemesinin zor olduğunu söylemiştir.

## 5. Makine Öğrenmesiyle Yazılım Kalite Tahmini

Bu sunumda iki öğrenci, makine öğrenmesiyle yazılım kalite tahmini yapan birkaç makaleyi birlikte incelemiştir.

### 5.1 Neden kalite tahmini?

Yazılım küçük işletmelerden büyük kurumlara, eğitimden ticarete her alanda kullanılır; bu yüzden kalitesinin güvence altına alınması çok önemlidir. Kaliteyi sağlamak için doğru zamanda doğru işlem yapılmazsa maliyet ciddi boyutlara ulaşır. Sunumda, yazılım arıza ve hatalarının yıllık ortalama maliyetinin 59 milyar dolar civarında olduğu tahmini aktarılmıştır. Güvence ne kadar geç sağlanırsa maliyet o kadar büyür. Kaliteyi erken tahmin etmek geliştiriciye kolaylık, kullanıcıya güven sağlar ve kaynakların verimli kullanılmasına yardım eder.

### 5.2 Tahmin akışı, faktörler ve metrikler

ISO standardına dayalı akışta önce kaliteyi belirleyen ölçüm yöntemleri seçilir. Sonra bu ölçümler bir fonksiyon ya da algoritmayla birleştirilip işlenir ve tahmin yapılır. İncelenen çalışmalarda analiz adımındaki fonksiyonlar makine öğrenmesi modelleridir.

Derste görülen işlevsel olmayan kalite faktörlerinden (güvenilirlik, sürdürülebilirlik, işlevsellik, taşınabilirlik vb.) bu çalışmalarda öne çıkanlar güvenilirlik ve sürdürülebilirliktir:

- **Güvenilirlik:** Yazılımın belirtilen kaynaklarla ve belirtilen ortamda çalışabilmesine ilişkin güven ölçüsüdür. Hata tahmini yapılarak ölçülebilir.
- **Sürdürülebilirlik:** Teslimden sonra yapılan değişikliklere harcanan efor olarak görülebilir.

Hata ve sürdürülebilirlik tahmini için kalite metriklerinden yararlanılır. İncelenen makalede, literatür çalışmasına dayanarak bir tür özellik seçimi yapılmış ve 13 metrik seçilmiştir (ekrandan, 00:50:00):

1. Weighted Methods Per Class (WMC)
2. Lines of Code (LOC)
3. Coupling Between Objects (CBO)
4. Depth of Inheritance Tree (DIT)
5. Number of Children (NOC)
6. Lack of Cohesion in Methods (LCOM)
7. Response for Class (RFC)
8. Inheritance Coupling (IC)
9. Coupling between Methods (CBM)
10. Message Passing Coupling (MPC)
11. Data Abstraction Coupling (DAC)
12. SIZE1
13. SIZE2

Hoca bunların çoğunun CK metrikleri çerçevesinde olduğunu belirtmiş, sunucu da çoğunluğun nesneye yönelik metrikler olduğunu doğrulamıştır. LOC, programın yorum dışı kaynak kod satırlarını ölçer.

**Soru:** En sondaki SIZE1 ve SIZE2 nedir? **Cevap:** SIZE1 bir sınıftaki çalıştırılabilir öğe sayısının ölçüsü, SIZE2 ise sınıftaki öznitelik sayısı ile yerel metot sayısının toplamıdır.

> **Ders sonrası not:** Sunucu SIZE1'i "bir sınıftaki çalıştırılabilir dosya sayısı" diye tanımladı. Bu metrikler büyük olasılıkla Li ve Henry'nin metrikleridir; orada SIZE1 bir sınıftaki noktalı virgül (yani ifade) sayısıdır, dosya sayısı değildir. SIZE2'nin tanımı sunucunun söylediğiyle aynıdır.

### 5.3 Veri kümeleri ve ön işleme

Çalışmada PROMISE deposundan alınan hata tahmini kümeleri ve sürdürülebilirlik tahmini kümeleri kullanılmıştır (ekrandan, 00:55:00).

| Proje | Sürüm | Örnek sayısı | Hata yüzdesi (yaklaşık) |
|---|---|---|---|
| Ant | 1.7 | 745 | 22 |
| Tomcat | 6.0 | 858 | 9 |
| Velocity | 1.6 | 229 | 34 |
| Ivy | 2.0 | 352 | 11 |
| Jedit | 4.3 | 492 | 2 |
| Poi | 3.0 | 442 | 63 |
| Forrest | 0.8 | 32 | 18 |
| Workflow | 1 | 39 | 51 |

| Proje | Örnek sayısı | Toplam değişiklik | Değişiklik yüzdesi |
|---|---|---|---|
| UIMS | 39 | 1826 | 43% |
| QUES | 71 | 4560 | 23% |

Hata kümelerindeki örnekler sınıflardır ve her sınıfın hatalı olup olmadığı etiketlidir. Sürdürülebilirlik kümelerinde hedef, değişen kod satırı sayısıdır.

İşlem adımları:

- **Ön işleme ve dönüştürme:** Eksik değerleri doldurmak (imputation) ve normalizasyon. İncelenen çalışmada boş değerler bir yöntemle değil, elle (özellik mühendisliğiyle) doldurulmuştur; bu çok zahmetli bir iştir. Normalizasyon sayısal öznitelikleri 0-1 ya da -1-1 aralığına ölçekler; eğitimi hızlandırmak ve başarıyı artırmak için yapılır.
- **Eğitim ve test kümesi seçimi:** Eğitimde yalnız POI kümesi kullanılmıştır, çünkü hatalı sınıfa ait örnek oranı en yüksek olan kümedir (%63). Diğer kümelerde hatalı örnek az olduğu için onlar test amaçlı kullanılmıştır.
- **Değerlendirme ölçütleri:** Hatalı ve hatasız sınıf dağılımı dengesiz olduğu için precision ve recall kullanılmıştır.
- **Doğrulama:** Örnek sayısı az olduğu için 10 katlı çapraz doğrulama yapılmıştır.

### 5.4 Kullanılan yöntemler

- **Karar ağacı:** Denetimli bir yöntemdir. Veriyi olabildiğince homojen gruplara ayırmayı amaçlar. Her düğüm bir öznitelik ve bir eşikten oluşan bir karardır. Ağaç bilgi kuramından yararlanarak, genelde entropi değerleriyle optimize edilir. J48 bir karar ağacı yöntemidir.
- **Rastgele orman (random forest):** Birden fazla karar ağacı kullanan bir topluluk (ensemble) yöntemidir. Farklı öznitelikler seçerek ya da bagging/bootstrapping ile örnek seçerek farklı ağaçlar üretir. Ağaçların kararları çoğunluk oylamasıyla (majority voting) birleştirilir; her ağacın oyu eşit sayılır.
- **Bayes ağı:** Naive Bayes bütün özniteliklerin birbirinden bağımsız olduğunu varsayar. Bayes ağında ise birbiriyle ilişkili özniteliklerin koşullu olarak bağımlı olduğu varsayılır. Sunumdaki bir örnekte gereksinim etkinliği ile gereksinim süreci kalitesi gibi parametrelerin koşullu bağımlılıkları gösterilmiştir.
- **Kural tabanlı sınıflandırma:** Eğer-ise (if-then) kalıplarıyla, bütün eğitim verisini kapsayacak kurallar oluşturur. Karar ağaçlarına benzer. Sunucunun örneği: "uçabiliyor mu?" sorusunun evet cevabı kuşu, "yüzebiliyor mu?" sorusunun evet cevabı balığı verir. PART kural tabanlı bir yöntemdir.
- **K en yakın komşu (KNN):** Test örneğinin sınıfına karar verirken eğitim verisini kullanır. Öklid ya da Manhattan gibi mesafe ölçülerine göre komşular bulunur ve çoğunluk oylamasıyla sınıf belirlenir.
- **Genetik programlama:** Genetik algoritma mantığının bilgisayar programlarına aktarılmış hâlidir. Birden çok programdan bir popülasyon oluşturulur, her programın uygunluk (fitness) değeri hesaplanır, çaprazlama ve mutasyonla (bir fonksiyonu ya da parametreyi değiştirerek) yeni programlar üretilir. İşlem tekrarlanarak en kaliteli program elde edilir.
- **Destek vektör makinesi (SVM):** İki sınıfı ayıran en uygun karar sınırını bulan ayırt edici bir yöntemdir. Sınıfların sınıra en yakın uç noktalarına destek vektörleri denir; yöntemin adı buradan gelir.
- **Yapay sinir ağı:** Girdileri düğümlerde tutar, düğümler birbirine ağ gibi bağlanır. Gizli katmanlardaki ağırlıklar güncellenerek eğitilir. Hata (loss) hesaplanır ve geriye doğru bütün ağırlıklar güncellenerek en aza indirilir.
- **AdaBoost:** Bir boosting yöntemidir; kendi başına bir sınıflandırıcıdan çok bir öğrenme algoritmasıdır. İteratiftir: önce az öğrenilen örnekler tespit edilir, sonra bu örneklerin ağırlığı artırılarak öğrenilmeleri sağlanır. Böylece eğitim setindeki zor örneklere odaklanılır.
- **Bagging:** Veri kümesinden rastgele örnek seçimine dayalı tekrarlı öğrenmedir. Birden fazla model oluşur, kararları çoğunluk oylamasıyla birleştirilir.

> **Ders sonrası not:** Sunucu AdaBoost'un amacını "azınlık sınıfa ait örneklerin daha fazla öğrenilmesi" diye anlattı. AdaBoost aslında sınıfına bakmadan bir önceki adımda yanlış sınıflandırılan örneklerin ağırlığını artırır. Sunucunun en sonda söylediği "zor örneklere odaklanma" ifadesi bu anlamda doğrudur.

### 5.5 Performans ölçütleri

Sınıflar dengesiz olduğu için accuracy gibi bir ölçüt yanıltıcıdır; bu yüzden precision ve recall kullanılmıştır. Bazı çalışmalarda ayrıca ROC eğrisinin (doğru pozitif oranına karşı yanlış pozitif oranı) altında kalan alan (AUC) kullanılmıştır.

> **Ders sonrası not:** Sunucu precision'ı "olması gereken sonuçlardan kaç tanesinin doğru olduğu", recall'u "tahmin ettiğimiz sonuçlardan kaç tanesinin gerçekten doğru olduğu" diye tanımladı. Bu iki tanım yer değiştirmiştir. Doğrusu: $\text{Precision} = \dfrac{TP}{TP + FP}$ (pozitif tahmin edilenlerin ne kadarı gerçekten pozitif) ve $\text{Recall} = \dfrac{TP}{TP + FN}$ (gerçek pozitiflerin ne kadarı bulundu).

### 5.6 Sonuçlar

Reddivari ve arkadaşlarının çalışmasının sonuçları (ekrandan, 01:05:00):

| Teknik | Hata: Precision | Hata: Recall | Hata: AUC | Sürd.: Precision | Sürd.: Recall | Sürd.: AUC |
|---|---|---|---|---|---|---|
| J48 | 0.755 | 0.626 | 0.720 | 0.649 | 0.590 | 0.702 |
| Random Forest | 0.740 | 0.654 | 0.801 | 0.537 | 0.527 | 0.814 |
| Naive Bayes | 0.616 | 0.558 | 0.711 | 0.604 | 0.522 | 0.633 |
| Bayesian Network | 0.777 | 0.696 | 0.849 | 0.693 | 0.492 | 0.626 |
| PART | 0.776 | 0.619 | 0.760 | 0.586 | 0.573 | 0.742 |
| KNN | 0.807 | 0.621 | 0.790 | 0.774 | 0.520 | 0.755 |
| SVM | 0.394 | 0.499 | 0.499 | 0.719 | 0.557 | 0.681 |
| ANN | 0.729 | 0.632 | 0.740 | 0.464 | 0.515 | 0.645 |

Tablonun okunuşu (python ile kontrol edildi):

- Hata tahmininde SVM'in başarısı çok düşüktür (AUC 0.499, yani rastgele tahmin düzeyi). Rastgele ormanın AUC değeri 0.801'dir. En yüksek AUC 0.849 ile Bayes ağındadır.
- Sürdürülebilirlik tahmininde en yüksek AUC 0.814 ile rastgele ormandadır. En düşük AUC değerleri Naive Bayes (0.633) ve Bayes ağındadır (0.626).

Sunucu bir başka sonuç tablosunda yüzdelerin bütün yöntemler için %60 ile %68 arasında değiştiğini, Naive Bayes ile Bayes ağının yine en düşük kaldığını, rastgele ormanın %67 ile istikrarını koruduğunu, J48, PART ve yapay sinir ağının %68 ile en yüksek olduğunu söylemiştir.

<!-- BELİRSİZ: %60-%68 aralığındaki ikinci tablonun karesi yok; değerler yalnız sunucunun anlatımından alındı. -->

Malhotra ve arkadaşlarının çalışmasında da rastgele orman ve karar ağacı tabanlı bagging en yüksek başarıyı vermiştir. ROC eğrilerinde AdaBoost ve rastgele ormanın eğri altı alanı genel olarak daha büyüktür; bagging de bunlara yakındır.

Özet sonuçlar:

- Kaliteyi belirlemede en çok katkısı olan metrikler belirlenmiştir.
- Hata ve sürdürülebilirlik tahmini için en güvenilir yöntemler rastgele orman ve bagging bulunmuştur.
- Bayes ağı hata tahmininde başarılı olsa da sürdürülebilirlik tahmininde en düşük başarıya sahiptir. Bu, kaliteyi belirlerken hangi faktöre bakıldığının önemli olduğunu gösterir.
- Genel olarak karar ağacı temelli teknikler en etkili yöntemlerdir.

> **Hocanın vurgusu:** Bu konuda çok fazla çalışma yapılmaktadır. Yazılım mühendisliğinde akıllı sistemler, yazılım mühendisliğinde yapay zekâ uygulamaları, makine öğrenmesi ve yazılım mühendisliği gibi özel adlı konferanslar düzenlenmektedir.

## 6. Kötü Koku, Yeniden Düzenleme ve Kullanıcı İncelemeleri

Bu sunumu da iki öğrenci birlikte yapmıştır. Hoca kalite tanımı ve kalite faktörleri gibi derste görülen giriş kısımlarını atlayıp doğrudan kötü kokudan başlamalarını istemiştir.

### 6.1 Kötü koku (code smell)

Kötü koku, programın kaynak kodunda bir soruna işaret eden yapılardır. Temel tasarım ilkelerinin ihlal edildiğini gösterir ve kaliteyi olumsuz etkiler. Kötü koku tespiti, yazılım kalitesini ve bakımını iyileştirmek için yapılan önemli bir etkinliktir.

Farklı tespit yaklaşımlarının farklı sonuç vermesinin nedenleri:

- Geliştiriciler kokuları öznel yorumlayabilir ve farklı biçimde tespit edebilir.
- Dedektör programlarının birbiriyle uyumu düşüktür; farklı araçlar ya da kurallar aynı kod öğesi için farklı sonuç çıkarabilir. Sunucunun örneğine göre farklı kod analiz araçları çoğu zaman farklı sonuçlar verir.
- Bir kokuyu tanımlayan eşik değeri dedektörden dedektöre değişebilir. Örneğin aynı if yapısı bir araçta koku sayılırken başka bir araçta sayılmayabilir.

Referans alınan makaleler (ekrandan, 01:15:00):

- Fontana ve arkadaşları (2016) 32 farklı makine öğrenmesi algoritmasıyla %95'in üzerinde doğruluk ve F-skoru elde etmiştir. Ancak sonradan bu veri kümesinin bazı sınırlamalar yüzünden gerçek dünyayı temsil etmediği belirtilmiştir.
- Di Nucci ve arkadaşları (2018) Fontana'nın veri kümelerini sınıf ve metot düzeyinde birleştirerek yeniden yapılandırmış ve algoritmaları yeniden çalıştırmıştır. Doğruluk %76'ya kadar düşmüştür. Bu çalışma, veri kümesi gerçek senaryoyu temsil ettiğinde makine öğrenmesi performansının azaldığını göstermiştir. Metot düzeyinde birleştirilmiş kümede feature envy (özellik kıskançlığı) kokusunun tek bir değişkene bakılarak sınıflandırıldığı da gösterilmiştir.

Kötü kokular sürdürülebilirlik ve anlaşılabilirlik gibi kalite yönlerini düşürür. Kodun anlaşılmasını ve dolayısıyla bakımını zorlaştırarak geliştirme sürecini engeller. Sunumda anılan bir çalışma, koku tespit tekniklerini yedi kategoride toplamıştır: kooperatif tabanlı, görselleştirme tabanlı, arama tabanlı, olasılık tabanlı, metrik tabanlı, belirti (semptom) tabanlı ve manuel teknikler.

### 6.2 Yeniden düzenleme (refactoring)

Yeniden düzenleme, kodun dış davranışını değiştirmeden iç yapısını iyileştirme sürecidir. Genellikle kod seviyesinde uygulanır. Dış davranış değişmediği hâlde yapılmasının nedeni daha iyi okunabilirlik ve daha az karmaşıklıktır; bu da hataların daha kolay bulunup düzeltilmesini sağlar. Yeniden düzenleme gerekliliği kod kokularının varlığıyla belirtilir; bunu Fowler ve arkadaşları 1999'da ortaya koymuştur.

İncelenen derleme makalesi, refactoring zamanını ve eforunu azaltmak için önerilen araçları incelemiştir. Makaleler, kalite sorularına verilen puanlarla filtrelenmiş ve 41 makale seçilmiştir. Bulgular:

- Yeniden düzenleme yalnız kod değil, tasarım ve gereksinim seviyesinde de olabilir; son dönemde bu seviyelerdeki yayınlar artmıştır.
- Refactoring test güdümlü ve çevik geliştirmede önemli bir yer tutar.
- Değerlendirme iki türlüdür. **Metrik tabanlı** değerlendirmede araç tarafından önerilen refactoring uygulandığında önceden belirlenmiş metrikler kaliteyi artırmışsa refactoring başarılı sayılır. **Uzman tabanlı** değerlendirmede aracın önerisi bir uzmana sorulur.
- Literatürde en çok kullanılan ve en başarılı yaklaşım arama tabanlı algoritmalardır; kolaylık, esneklik ve çeşitlilik nedeniyle başarılıdırlar.

Slayttaki özet (ekrandan, 01:20:00): Yeniden düzenleme kaynak kodun sürdürülebilirliğini, bakım yapılabilirliğini, değiştirilmesini, test edilebilirliğini ve hataları düzeltmeyi kolaylaştırabilir; asıl amacı olan verimliliği artırarak yazılım kalitesine katkıda bulunur.

### 6.3 Kullanıcı incelemeleri

Kullanıcı incelemeleri, kullanıcıların ürün hakkındaki deneyim ve yorumlarıdır. Genelde gönüllü yazılır ve hem diğer kullanıcılara hem geliştiricilere önemli bilgi sağlar. İncelenen makale mobil uygulama incelemelerine odaklanır. Temel fayda, kullanıcı gereksinimlerini anlamak ve hatalı kısımları bulmaktır.

Uygulamalar binlerce yorum aldığı için bunları okumak uzun zaman alır; bu yüzden gerekli bilgiyi otomatik çıkaran algoritmalar önerilir. "Çok iyi uygulama" ya da "hiç sevmedim" gibi yorumların kaliteye faydası yoktur. Yorumlar kısa ve resmi olmayan bir dille yazıldığı için önce veri ön işleme ve doğal dil işleme teknikleri uygulanır. Ardından problem bir sınıflandırma problemi olarak ele alınır. Sınıflar hata bildirimi, özellik isteği, bilgi verme ve bilgi arama gibi sınıflardır. Özellik seçimi için bilgi kazancı ve ki-kare yöntemi kullanılmış, bu da sınıflandırıcıların performansını önemli ölçüde artırmıştır. Makale bir derleme değildir; yazarlar kendi algoritmalarını önermiş ve Naive Bayes, karar ağacı, lojistik regresyon gibi temel algoritmalarla karşılaştırmıştır. Önerilen algoritma precision, recall, F-skoru ve doğrulukta en başarılı sonucu vermiştir.

<!-- BELİRSİZ: Önerilen algoritmanın adı altyazıda "ICRM" diye geçiyor; doğruluğu kareden kontrol edilemedi. -->

Sonuç olarak incelemeler sınıflandırılıp yorumlanarak gerekli bilgi çıkarılabilir, yeni kullanım senaryoları belirlenebilir ve daha kaliteli yazılım üretilebilir.

## 7. Test Edilemeyen Sistemler ve Test Kâhini Problemi

Sunum, Software Quality Journal'da 2018'de yayımlanan, test edilemeyen sistemlerin test edilmesine ilişkin bir haritalama çalışmasına dayanır (ekrandan, 01:25:00). Çalışma beş tekniği etkinlik, verimlilik, kullanılabilirlik ve maliyet açısından karşılaştırır.

### 7.1 Temel kavramlar

Bir test şöyle işler: test edilen sistem için bir test girdisi oluşturulur, bu girdi için beklenen çıktı belirlenir, sistem bu girdiyle çalıştırılır ve gerçek çıktı beklenenle karşılaştırılır. Tutarsızlık varsa test başarısızdır. Beklenen çıktıyı tahmin etmekten ve karşılaştırmayı yapmaktan sorumlu mekanizmaya **test kâhini (test oracle)** denir.

Yazılım testi her zaman bir kâhinin bulunduğu varsayımına dayanır. Kâhin doğru ve yanlış sistem davranışını ayırt eder. Kâhinin uygulanamadığı ya da etkisiz kaldığı durumda **test edilemeyen sistem** ortaya çıkar. "Kâhin problemi" ve "test edilemeyen sistem" birbirinin yerine kullanılan terimlerdir. Geleneksel test teknikleri burada işe yaramaz.

> **Ek bilgi (derste anlatılmadı):** Tipik test edilemeyen sistem örnekleri bilimsel hesaplama programları, makine öğrenmesi modelleri ve simülasyonlardır. Bu programlar zaten sonucu bilinmeyen bir şeyi hesaplamak için yazılır, bu yüzden beklenen çıktı önceden bilinemez.

### 7.2 N-versiyon testi

$S$ test edilen sistem, $S_R$ de aynı işlevi uygulayan başka bir sistem olsun; $S_R$'ye $S$'nin **referans uygulaması (RI)** denir. N-versiyon testinde $S$ ve $S_R$ aynı test girdisiyle çalıştırılır, çıktılar karşılaştırılır ve fark varsa hata bildirilir. Bu test, test uzmanının sistem hakkında ayrıntılı bilgi sahibi olmasını gerektirmez.

**Etkinlik.** N-versiyon testi temelde bir kara kutu testidir; bu yüzden olayların akışını test edemez, daha işlevsel ve yüzeyseldir. Çıktılar yerine program spektrumlarının karşılaştırıldığı bir çeşidinde ise beyaz kutu testi gibi davranabilir ve sistemin iç yapısını inceleyebilir.

**İlişkili başarısızlık.** $S$ ve $S_R$ aynı girdi için aynı yanlış çıktıyı verirse karşılaştırma fark göstermez ve hata yakalanamaz. Buna ilişkili başarısızlık (correlated failure) denir. Azaltmak için yönergeler:

- **Bağımsız geliştirme ekipleri:** Aynı ekip iki sistemi de geliştirirse bir hatanın ikisinde de tekrarlanma olasılığı yüksektir.
- **Sistemleri çeşitlendirmek:** Her sistem için farklı platform, algoritma, tasarım yöntemi, mimari ya da programlama dili kullanmak.
- **Test girdilerini seçmek:** Bazı girdiler ilişkili başarısızlığa yol açar, bazıları açmaz. Hata yakalama şansı bu iki tür girdinin oranına bağlıdır.

**Kullanılabilirlik.** Tek elle yapılan iş RI'yi temin etmek ve hataları ayıklamaktır. RI geliştirmek önemli ölçüde zaman ve çaba ister (ekrandan, 01:30:00). Bu yükü azaltan üç öneri:

1. RI'yi performanstan çok hızlı geliştirilecek biçimde tasarlamak. Üst düzey dillerde yazılan bir RI yavaş çalışsa da daha hızlı geliştirilir.
2. Aynı sistemin önceki sürümlerini ya da aynı işlevi uygulayan benzer sistemleri RI olarak seçmek.
3. Bileşen hasadı: istenen uygulamanın sözdizimsel ve anlamsal tanımlarıyla çevrimiçi kod havuzlarında arama yaparak RI temin etmek. RI ararken titiz davranmak gerekir.

**Maliyet.** Tartışmalıdır. Bazı uzmanlar RI tedariki pahalı olduğu için yöntemin pahalı olduğunu söyler. Öte yandan manuel testte senaryolar elle yürütülürken N-versiyon testi otomatik yapılır ve süreci hızlandırır. Bakım sonrası RI'lerin de güncellenmesi gerekir. Uygun teknik, maliyet-etkinlik oranına bakılarak seçilir.

> **Ders sonrası not:** Sunucu yöntemi altyazıda "M-versiyon testi" diye söylüyor; slaytlarda ve literatürde adı N-versiyon testidir.

### 7.3 Metamorfik test

Metamorfik testte "metamorfik test grubu" adı verilen bir dizi test durumu oluşturulur. Grupta iki tür test durumu vardır:

- **Kaynak test senaryoları:** Herhangi bir test oluşturma stratejisiyle, isteğe bağlı olarak oluşturulur.
- **Takip test senaryoları:** Belirli kaynak senaryolardan ve bir metamorfik nitelikten türetilir.

Metamorfik nitelik, kaynak ve takip senaryoların sonuçları arasında beklenen ilişkidir. Test grubu ile nitelik birlikte **metamorfik ilişki (MR)** olarak adlandırılır. MR'ler, test grubunu çalıştırıp çalıştırmalar arasında niteliğin korunup korunmadığına bakarak değerlendirilir.

**Etkinlik.** Metamorfik test de kâhin problemini azaltmak için geliştirilmiştir; özellikle ön bilgi eksikliğinden test sonucunun tahmin edilemediği durumlar içindir. Deneylerde %5 ile %100 arasında değişen mutasyon puanları elde edilmiştir. Etkinliği etkileyen faktörler:

- **Kapsam:** MR seçimi test grubunun kapsamını kısıtlayabilir. Kısıtlayıcı MR'lerin kullanımı sınırlanarak kapsam artırılabilir.
- **Özellikler:** soyutlama düzeyi, ayrıntı düzeyi, anlam, güç, sıkılık ve sağlamlık.
  - Uygulama düzeyinde tanımlanan MR'ler, fonksiyon düzeyinde tanımlananlardan daha fazla hata bulabilir.
  - Sistemin anlamını daha doğru yansıtan MR daha etkilidir.
  - Daha sıkı bir MR doğruluğu daha kesin tanımlar. Sunucunun örneği: $x = 2y$ biçimindeki ilişki tek bir doğru cevaba izin verir; $x > 2$ gibi gevşek bir ilişki daha az etkili olabilir.
  - Bütün girdi değerleri için tutması beklenen MR daha sağlamdır.
- **Problem alanı ve hatalar** (ekrandan, 01:35:00):
  - MT birden çok MR kullanınca daha etkili olur. MR'ler alana özgü olduğu için X problem alanındaki potansiyel MR sayısı Y'dekinden fazla olabilir; bu durumda X alanında MT daha etkilidir.
  - MT ve varyantları çok çeşitli hataları bulabilir; örneğin konfigürasyon parametrelerindeki hataları. Ancak MR'ler spesifikasyona göre tasarlanmışsa aynı spesifikasyon hataları teste de yayılmış olabilir. Bu durumda MT ilişkili başarısızlık yüzünden bazı spesifikasyon hatalarını bulamaz.

**Kullanılabilirlik.** MT'nin kavranması diğer tekniklerden zordur, çünkü geniş bir beceri seti gerektirir. Alan uzmanları, uzman olmayanlara göre daha etkili ve verimli MR belirleyebilir. Sunumda anılan bir çalışmada, belirli bir MR'yi sergileyen kodu tanımak için makine öğrenmesi sınıflandırıcıları eğitilmesi önerilmiştir. Böyle bir sınıflandırıcı görülmemiş bir kodun bir MR'yi sergileyip sergilemediğini tahmin edebilir. Sonuçlar umut vericidir, yanlış pozitif oranı düşüktür ve sistemde hata olsa bile MR belirleyebilir.

<!-- BELİRSİZ: Bu çalışmanın yazarları altyazıda "Cannavela ve Bayman" diye geçiyor; büyük olasılıkla Kanewala ve Bieman'dır. -->

**Verimlilik.** Test senaryosu oluşturma ve yürütmenin bir zaman maliyeti vardır ve bu maliyet MR'den MR'ye değişir. MT kâhinleri, N-versiyon tabanlı kâhinlerden daha hızlı ve kolay geliştirilir; bu yüzden onların yerine tercih edilebilir.

### 7.4 Bildirimler (assertions)

Bildirimler doğrudan kaynak koda yerleştirilen Boolean ifadelerdir ve programın durum değişkenlerine dayanır. Sistem çalışırken kontrol edilir; yanlış çıkarsa hata vardır. N-versiyon ve metamorfik testin aksine bildirimler aslında kâhin problemini hafifletmek için tasarlanmamıştır. Ancak bir bildirimi değerlendirmek için test sonucunu tahmin etmek gerekmez; bu yüzden sonucu tahmin etmenin mümkün olmadığı durumlar için oldukça uygundur.

- Kaynak koda eklendikleri için ek yük (overhead) ve olası zaman aşımlarına neden olabilir.
- Okunabilirlik sorunlarında çok biçimlilik kullanılabilir: bildirim üst sınıfta yazılıp alt sınıflarda yeniden kullanılır.
- Programın belli noktalarında yalnız sınırlı sayıda özelliği denetleyebilir. Etkinliği artırmak için sisteme yardımcı değişkenler eklenebilir.
- Verinin bütünlüğünü tehlikeye atan hataların testinde kullanılır.
- Yalnız tek bir yürütmeyi kontrol edebilir; çoklu yürütmeye uygun değildir.
- Bildirim yazma çabası, istenen ayrıntı düzeyine ve programlama dilinin ifade gücüne bağlıdır. Bazı dillerde `assert` anahtar sözcüğü vardır; değişmez (invariant) algılama araçları bildirimleri otomatik oluşturabilir.

### 7.5 Makine öğrenmesi kâhinleri

İki kullanım biçimi vardır. Birincisinde algoritma, başarısızlıkla ilişkili kalıpları öğrenmek için bir eğitim veri setinde eğitilir; sonra bir test senaryosunun yürütmesinde bu kalıpları aramak için kullanılır. İkincisinde algoritma sistemin bir modeli olacak biçimde eğitilir; bu durumda N-versiyon testindeki referans uygulamaya benzer ve ilişkili başarısızlığa yol açabilir.

Etkinliği etkileyen faktörler (ekrandan, 01:40:00):

- Birinci grup eğitim veri setinin yapısıyla ilgilidir. Başarılı ve başarısız senaryoların dengesinin test etkinliğinde sapmaya (bias) yol açabileceği bildirilmiştir.
- Daha büyük veri setleri daha az sapmaya sahiptir ve gürültünün olumsuz etkilerine daha az duyarlıdır.
- Eğitim veri setinin biçimi nadiren makine öğrenmesine uygun olduğu için set, bir ya da daha fazla özellik çıkarıcıyla, onu karakterize eden özelliklere indirgenir.
- İkinci grup, kullanılan özellik çıkarıcıların sayısı ve çeşitliliğiyle ilgilidir.

ML kâhinleri temelde kara kutu testinde kullanılır ve olayların akışını test edemez. Bazı araştırmalar beyaz kutu testinde de kullanılabileceklerini bildirmiştir. Denetimli öğrenme kullanılırsa uzmanların her eğitim örneğini elle etiketlemesi gerekebilir; büyük veri setlerinde bu ciddi çaba ister. Birden çok uzman kullanılırsa anlaşmazlık çıkabilir ve bunların çözümü toplam çabayı artırır.

### 7.6 İstatistiksel hipotez testi

Test edilen sistem birçok kez çalıştırılır ve çok sayıda çıktı, ortalama ve varyans gibi özet istatistiklerle bir araya getirilir. Bu değerler çıktı dağılımını karakterize eder ve beklenen dağılımı tanımlayan değerlerle karşılaştırılır. Önemli fark çıkmaması sistemin doğru davrandığına, önemli fark çıkması tersine kanıt sayılır.

Deterministik olmama, bir sistemin tek bir çalıştırmanın sonucunu tahmin edilemez kılabilir; bu tür sistemler kâhin probleminin örnekleridir. Yöntem, bu sistemlerin tipik bir çıktı dağılımı olabileceğini ve bu dağılım hakkındaki bilginin çalıştırmadan önce mevcut olabileceğini kabul eder.

- Etkinlik istatistiksel test seçimine bağlıdır; her zaman en etkili ve uygulanabilir test seçilmelidir.
- Dağılımı karakterize eden istatistik de önemlidir. Sunumda anılan bir çalışmada varyansın ortalamadan daha etkili olduğu, ilginç olarak ikisinin farklı mutantları yakaladığı bulunmuştur. Bu, birden çok özet istatistik kullanılması gerektiğini gösterir.
- Dikkate alınan veri miktarı artırılmalıdır. Yanlış pozitif ve yanlış negatifler yüksektir.
- Test eden kişi önem seviyesini kontrol eder. Daha yüksek önem seviyesi daha fazla yanlış pozitif, daha az yanlış negatif verir; tersi de geçerlidir. Hangi senaryoların yanlış olduğu belirsiz kalır ve her birinin elle incelenmesi gerekebilir.

### 7.7 Tekniklerin karşılaştırılması

Makaledeki karşılaştırma tablosu (ekrandan, 01:45:00):

| Teknik | İlişkili başarısızlık yaşayabilir mi? | Tesadüfi doğruluk için etkili mi? | Kâhin tasarımında yapılabilecek seçim örneği |
|---|---|---|---|
| N-versiyon testi | Doğru | Yanlış | RI'nin yazıldığı dilin, test edilen sistemin diliyle aynı olup olmayacağı |
| Metamorfik test | Doğru | Yanlış | MR'nin sıkılığı |
| Bildirimler | Bilinmiyor | Bilinmiyor | Yardımcı değişkenlerin kullanılması |
| ML kâhinleri | Doğru | Yanlış | Hangi özellik çıkarıcıların kullanılacağı |
| İstatistiksel hipotez testi | Doğru | Yanlış | Hangi istatistiksel testlerin yürütüleceği |

Tablonun son sütunu kapsamın kısıtlandığı yollara örnek verir: N-versiyon testi bir kara kutu tekniğidir ve beyaz kutu kâhin bilgisini kullanamaz; bazı MR'ler kaynak test senaryolarına kısıt getirir; bildirimler tek bir yürütmeyi kontrol eder; istatistiksel hipotez testi, sistem deterministikse rastgele test senaryosu oluşturmayı zorunlu kılar.

Kullanılabilirlik bağlama göre değişir. N-versiyon testinde bazen RI'yi sıfırdan yazmak gerekir, bazen gerekmez. Metamorfik testte alan uzmanı yoksa test uzmanı alanı öğrenmek için ek çaba harcar. Bildirim yazma çabası kullanılan dile bağlıdır. Makine öğrenmesinde bazı görevler bazı durumlarda gereklidir, bazılarında gereksizdir. İstatistiksel hipotez testinde veri dönüşümü gibi görevler bazen gerekir.

Çalışmanın sonucu: test edilemeyen sistemlerdeki işlevsel hataları bulabilen beş otomatik teknik etkinlik, verimlilik ve kullanılabilirlik açısından haritalanmıştır. Bu malzeme, uygulayıcıların bağlamlarına en uygun tekniği seçmelerine ve onu en faydalı biçimde uygulamalarına yardım edebilir.

## 8. Modern Yazılım Sistemlerinde Test Senaryosu Önceliklendirme

Sunum IEEE'de yayımlanmış, modern yazılım sistemlerinde test senaryosu önceliklendirme (TCP) tekniklerini inceleyen ampirik bir çalışmaya dayanır.

### 8.1 Temel kavramlar

**Regresyon**, yazılımda yapılan değişikliklerle ortaya çıkan hatalardır. **Regresyon testi** bu hataları tespit etmek ve kontrol etmek için yapılan testler bütünüdür. Test senaryosu (derste görülen ön koşul, adımlar, son koşul) bilinen bir kavramdır. **Test senaryosu önceliklendirme**, senaryoların verimliliğini artırmak için belirli bir yöntemle sıralanmasıdır. Sorulan soru şudur: hangi testi önce yaparsam bana en çok fayda sağlar?

İki tür önceliklendirme vardır:

- **Genel önceliklendirme:** Programın bütününe bakar; çoğu değişiklikte işe yarayacak senaryolar öne alınır. Sürüm bilgisi kullanılmaz.
- **Sürüme özgü önceliklendirme:** Belirli bir sürüme özgü senaryolar öncelik alır.

### 8.2 Teknikler

**Statik teknikler:**

- **Çağrı grafı tabanlı:** Her test senaryosunun çağırdığı metotları içeren bir çağrı grafı oluşturulur. Çok sayıda metot çalıştıran senaryo öne alınır.
- **String tabanlı:** Senaryolar arasındaki farka, metin mesafesine (örneğin Manhattan mesafesi) bakılır. Kümedekilerden en çok farklı olan senaryo öne alınır ve bütün senaryolar bu biçimde sıralanır.
- **Konu (topic) tabanlı:** Anlamsal konu modelleri oluşturulur. Daha önce yapılmış testlerden farklı konudaki test öne alınır. Sunucunun örneği: testlerin çoğu veriyi kontrol ederken biri arayüzü kontrol ediyorsa o öne alınır.
- **Diğer:** bilgi erişimi (information retrieval) ve gereksinim tabanlı teknikler.

**Dinamik teknikler** (ekrandan, 01:50:00):

- **Açgözlü (greedy):** İki strateji vardır. Total stratejide her senaryonun toplam kod kapsamına bakılır. Additional (ek) stratejide her senaryonun henüz kapsanmamış koda kattığı ek kapsama göre sıralanır.
- **Uyarlanır rastgele test (ART):** Rastgele bir aday küme seçilir. Daha önce önceliklendirilmiş kümeye en uzak olan aday o kümeye eklenir. Bütün senaryolar bitene kadar sürer.
- **Arama tabanlı:** Arama algoritmalarıyla sıralama yapılır. Tepe tırmanma (hill climbing) tekniğinde test uygunluğunu en çok artıran senaryo öne alınır. Genetik teknikte önceden tanımlanan koşulu karşılayan senaryolar aranır.
- **Diğer.**

### 8.3 Çalışmanın düzeni

Çalışma GitHub'dan toplanan 58 modern yazılım projesi üzerinde yapılmıştır. Dinamik ve statik yöntemlerin farkı ve çeşitli etkenlerin etkisi incelenmiştir.

Ölçütler:

- **APFD (Average Percentage of Faults Detected):** bulunan hataların ortalama yüzdesi. Formülde $TF_i$, $i$. hatayı ilk bulan senaryonun sıradaki konumudur ve bu konumların toplamı alınır.
- **APFDc (cost-cognizant APFD):** APFD'ye senaryo yürütme maliyetini ve hata ciddiyetini (fault severity) katar.
- **Mutasyon analizi:** Mutasyon operatörleri programa küçük hatalar (mutant) yerleştirir. Testlerin bu hataları bulması beklenir. Çalışmada mutasyonların önceliklendirme performansını değiştirip değiştirmediğine bakılmıştır.

<!-- BELİRSİZ: APFD formülü slaytta gösterildi ama o anın karesi yok; aşağıdaki formül derste ekrandan doğrulanamadı. -->

> **Ek bilgi (derste anlatılmadı):** APFD'nin yaygın tanımı $\text{APFD} = 1 - \dfrac{TF_1 + TF_2 + \dots + TF_m}{n \cdot m} + \dfrac{1}{2n}$ biçimindedir. Burada $n$ test senaryosu sayısı, $m$ hata sayısıdır. Değer 0 ile 1 arasındadır; hatalar ne kadar erken bulunursa 1'e o kadar yakın olur.

İncelenen teknikler 5 statik ve 4 dinamiktir (ekrandan, 01:55:00):

- Statik: TPcg-tot (çağrı grafı, total), TPcg-add (çağrı grafı, additional), TPstr (string mesafesi), TPtopic-r ve TPtopic-m (konu tabanlı; aynı teknik iki farklı araçla uygulanmış).
- Dinamik: TPtotal, TPadd, TPart, TPsearch.

### 8.4 Bulgular

**Test ayrıntı düzeyinin etkisi.** Her teknik hem sınıf hem metot seviyesinde, 58 programın her biri için APFD ve APFDc değerleriyle incelenmiştir (ekrandan, 01:55:00). Ortalamalar, her programın değeri toplanıp 58'e bölünerek bulunmuştur.

- Test sınıfı seviyesinde çağrı grafı tabanlı teknikler diğerlerinden, hatta dinamik tekniklerden daha iyi sonuç vermiştir.
- APFDc'nin değer aralığı APFD'ninkinden geniştir; programların boyutu ve çalışma biçimine göre yürütme süresi değiştiği için.
- Kodda anlamsız parametre ve değişken adları varsa string tabanlı teknikler daha kötü sonuç verir.
- Metot seviyesinde konu tabanlı tekniğin performansı kullanılan araca göre değişir; yani konu tabanlı teknikler araca bağımlıdır.
- Metot seviyesinde bütün teknikler sınıf seviyesine göre daha iyi sonuç vermiştir. Daha ince ayrıntı düzeyinde daha fazla detay olduğu için önceliklendirme daha net yapılabilir.

**Program boyutunun etkisi.** Genel olarak belirgin bir etkisi yoktur. Büyük programlarda teknikler biraz daha başarılıdır; bunun açıklaması, elde daha fazla senaryo olduğu için optimizasyon olanağının artmasıdır.

**Yazılım evriminin etkisi.** Sürümler ilerledikçe önceliklendirme performansında belirgin bir değişim görülmemiştir.

**Mutasyonların etkisi.** Mutasyon türü ve sayısı performansı önemli ölçüde etkiler. Bazı mutant türlerinde teknikler daha iyi çalışır, bazılarında fark azdır. Sunucunun örneği: negatif sayıları değiştiren bir mutasyon operatörü yalnız negatif değerli durumları etkilediği için az fark yaratır.

**Statik tekniklerin maliyeti.** Slayttaki bulgular (ekrandan, 02:00:00):

- Bütün tekniklerin ön işleme sırasındaki yürütme maliyetlerinin benzer olduğu görülmüştür.
- Önceliklendirme aşamasında sınıf seviyesinde maliyetler benzerken metot seviyesinde farklılaşır. Çağrı tabanlı teknikler daha az maliyetli ve verimlidir; string ve konu tabanlı tekniklerin maliyeti daha yüksektir.

| Teknik | Önceliklendirme ort. (sınıf/metot) | Önceliklendirme toplam (sınıf/metot) |
|---|---|---|
| TPcg-tot | 0.20 / 0.41 | 11.37 / 23.78 |
| TPcg-add | 0.18 / 0.64 | 10.59 / 37.02 |
| TPstr | 4.03 / 1,359.24 | 233.76 / 78,835.97 |
| TPtopic-r | 0.15 / 832.95 | 8.50 / 48,310.93 |
| TPtopic-m | 0.19 / 268.51 | 10.95 / 15,573.71 |

Sunucu bu farkı şöyle açıklamıştır: konu tabanlı teknik anlamsal bir model, string tabanlı teknik metin karşılaştırması kullandığı için maliyetleri farklıdır.

<!-- BELİRSİZ: Tablonun ön işleme sütunlarında çağrı grafı teknikleri için ortalama 244.14 görünürken string ve konu tabanlılar için 0.35-1.51 görünüyor; slayttaki "ön işleme maliyetleri benzer" cümlesiyle çelişiyor. Birimler karede yazmıyor. -->

**Geçerlilik tehditleri.** Yazarlar şunları kabul etmiştir: çok basit mutasyonlar APFD değerlerini şişirebilir; gerçek hataları değil yalnız yapay mutantları dikkate almıştır; bazı projelerde yeterli test senaryosu yoktur; aynı tekniklerin farklı uygulamaları sonucu etkilemiş olabilir.

**Özet.**

- Ayrıntı düzeyi önceliklendirmenin verimini ve performansını etkiler; ayrıntı arttıkça verim artar.
- Performans programın özelliklerine (karmaşıklık, kütüphaneler, kodun yazım biçimi) göre değişir; kötü yazılmış kodda önceliklendirme daha kötü sonuç verir.
- Büyük programlarda biraz daha iyi çalışır ama genel etkisi düşüktür.
- Mutasyon türü ve sayısı performansı önemli ölçüde etkiler.
- Statik tekniklerin performansı sınıf ve metot seviyesinde farklıdır. Genel olarak statik teknikler dinamiklerden biraz daha iyidir.

## 9. Dağıtık Sürekli Çevik Testte Geliştirici ile Test Uzmanı İletişimi

Bu sunumun ses kaydının büyük kısmı anlaşılmazdır. Sunum İngilizce yapılmıştır ve konusu, dağıtık sürekli çevik testte geliştiriciler ile test uzmanları arasındaki iletişimdir. Hoca, çevik manifestonun dört değeri gibi bilinen kısımların atlanmasını istemiştir.

İncelenen vaka çalışmaları şöyledir (ekrandan, 02:10:00):

- Araştırma sorularını cevaplamak için Daniela S. Cruzes ve arkadaşları, dört yıllık bir projenin parçası olarak iki ekibi 18 ay boyunca izlemiş ve eylem araştırması (action research) yapmıştır.
- Vakalar, merkezleri Norveç'te olan iki yazılım şirketindeki iki dağıtık ekibe dayanır. Geliştiriciler ve test uzmanları Norveç, Polonya ve İsveç gibi ülkelere dağılmıştır; şirketlerden birinin Çin'de bir test merkezi vardır.
- Araştırmacılar her şirkette farklı rollerle, geliştiriciler ile test uzmanları arasındaki iletişim hakkında görüşmeler yapmıştır.

Dağıtık geliştirmenin fırsatları slaytta şöyle sıralanmıştır (ekrandan, 02:05:00): kültürler arası ve kültür içi çeşitliliğin artması, esnek çalışma planları, saat dilimlerini aşabilme, engelli ve hareket kısıtlı bireylerin katılabilmesi, artan refah düzeyi, azalan seyahat masrafı, çevik yaklaşımın yinelemeli fikri, geniş insan kaynağı havuzu ve azalan ofis alanı.

Sunucu iletişim araçları olarak e-posta, sesli ve görüntülü konferans, yazılım araçları ve bunların karışımını anmıştır. Sonuç cümlesine göre dağıtıklık, daha fazla eşzamansız iletişim ve dolayısıyla geliştiriciler ile test uzmanları arasında daha az gayriresmî iletişim yaratarak test işini etkiler.

<!-- BELİRSİZ: Sonuç cümlesi altyazıda "distribution does not affect the work of testing by creating more asynchronous communication" diye geçiyor; cümlenin mantığına göre "affects" olması gerekir, kare yok. Sunumun 02:03-02:13 arasının büyük kısmı anlaşılmıyor. -->

## 10. Açık Kaynaklı Yazılımda Kalite Güvencesi

Bu sunumda iki öğrenci, açık kaynaklı yazılımda (AKY) kalite güvencesi üzerine bir derleme makalesini incelemiştir. Hoca açık kaynak kavramını herkesin bildiğini söyleyerek kısa geçilmesini istemiştir.

### 10.1 Açık kaynaklı yazılım

Açık kaynaklı yazılım, kapalı yazılımlara alternatif ürünler sağlar. Örnekler Apache, PHP, Nginx ve MySQL'dir. Genelde eş inceleme (peer review) kullanılır ve dünyanın her yerinden katkı yapılabilir. Belirsiz gereksinimler, belgelemeye az önem verilmesi ve zayıf proje ve kalite yönetimi yüzünden kalite güvencesini sağlamak zordur. Buna karşılık hataları daha hızlı çözme gibi avantajları vardır.

Genel özellikleri: özgürce paylaşılması ve değiştirilebilmesi, dağıtık geliştirme, ücretsiz olması, kaynak kodun erişilebilir olması, geliştiricilerin internet üzerinden iletişim kurması, geliştiricilerin aynı zamanda kullanıcı olması ve çok sayıda ücretsiz gönüllünün katkısı.

### 10.2 Soğan modeli

AKY geliştiricileri, içten dışa dört katmanlı bir soğan modeliyle anlatılır:

1. **Çekirdek geliştiriciler:** Yüksek kaliteli kod yazarak sistemin temel işlevlerinden sorumlu küçük bir uzman grubudur. Sistemi yönetir; planları, hedefleri ve yol haritasını tanımlar.
2. **Katkıda bulunan (ortak) geliştiriciler:** Geliştirmeyi doğrudan etkileyen daha büyük bir gruptur. Yeni özellik ekler, hata düzeltir, eş inceleme yapar.
3. **Hata raportörleri:** Sistemin test edilmesinden sorumludur. Önemli bir görevleri, sistemin birçok farklı platformda test edilmesini sağlamaktır.
4. **Kullanıcılar:** Sistemi kullanan kişilerdir; aynı zamanda geliştirici de olabilirler.

### 10.3 Artılar ve eksiler

Slayttaki artılar (ekrandan, 02:20:00):

- **Kullanıcılar için:** esneklik, güçlü değer, kodun kullanılabilirliği, kodu değiştirme imkânı, topluluk aracılığıyla bilgi paylaşımı ve artan motivasyon.
- **Geliştiriciler için:** özelleştirilebilir çözümler yaratma yeteneği, mevcut birçok parçayı ve işlevi yeniden kullanma potansiyeli, azalan üretim süresi ve artan motivasyon.
- **Sistem için:** daha hızlı hata algılama ve düzeltme, daha fazla güvenilirlik, özelleştirme özgürlüğü, maliyet etkinliği, yeniden kullanılabilirlik, hızlı gelişim, taşınabilirlik ve çok sayıda lisanslama seçeneği.

Eksiler:

- **Kullanıcılar için:** eksik ya da kötü belgeleme, yapılandırılmamış geliştirme yöntemleri, sorumsuz kişilerin bulunması.
- **Geliştiriciler için:** yeni geliştiricilerle işbirliği yapmanın ve büyük projeleri gözden geçirmenin zorluğu.
- **Sistem için:** resmî sürecin, merkezi yönetimin ve belgelemenin olmaması, zayıf tasarım, sorunlar için tek bir sorumlunun olmaması, sürüm çoğalması, insan gücü ihtiyacının zor tahmini, karmaşık lisanslar ve kısa vadeli maliyet.

### 10.4 Uygulama alanları ve büyüklük

Birçok platform, dünyanın her yerinden geliştirilen kod depolarına erişmeye ve kodu push, pull ve fork etmeye olanak tanır. SourceForge'da 18 uygulama kategorisi vardır; sunucu oyun ve eğlence grubunun %9.3 olduğunu aktarmıştır. Projelerin %70'inden fazlası hâlâ erken aşamalarda ya da yaşam döngüsünün sonlarındadır. SourceForge projelerinin çoğunun az sayıda geliştiricisi vardır; projelerin yalnız %1'inin 16'dan fazla geliştiricisi vardır ve bunların çoğu büyük projelerdir.

<!-- BELİRSİZ: Sunucunun aktardığı "%86.2" oranının neyi gösterdiği ve kategori yüzdelerinin tamamı altyazıdan net çıkmıyor. -->

### 10.5 AKY'de kalite güvencesi

Yazılım kalite güvencesi, yazılım sürecinin kullanıma uygun bir ürün üretebildiğine kanıt sağlayan sistematik faaliyetler dizisidir. Yaşam döngüsünün her aşamasının parçası olmalıdır. AKY'de kalite güvencesi için sürdürülebilir topluluk, kod modülerliği, proje yönetimi, belgeleme ve test süreci yönetiminin ve bunların birbirleriyle ilişkisinin anlaşılması gerekir.

Kalite yönetimi açısından AKY ile kapalı kaynak arasındaki farklar:

| Açık kaynak geliştirme | Kapalı kaynak geliştirme |
|---|---|
| Tanımlanmış ya da belgelenmiş bir geliştirme yöntemi yoktur | İyi belgelenmiş, tanımlı geliştirme yöntemleri vardır |
| Proje belgelemesi zayıftır | Proje belgelemesi eksiksizdir |
| Yapılandırılmamış, gayriresmî test ve kalite güvencesi | Resmî ve yapılandırılmış test ve kalite güvencesi |
| Resmî risk değerlendirmesi yoktur | Resmî risk değerlendirme ve izleme süreçleri vardır |
| Az belgelenmiş ya da ölçülebilir hedefler | Analiz edilmiş, tanımlı gereksinimler ve tasarımlar |

### 10.6 AKY geliştirme çerçevesi

Çerçeve üç süreçten oluşur: hata tespiti, hata doğrulaması ve çözüm doğrulaması.

**Hata tespiti.** Kullanıcılar ve geliştiriciler sistemi kullanırken karşılaştıkları hataları bildirir; bu yüzden AKY'de hata bulma süreci kara kutu testine benzer. Hata bulan kullanıcı üç şeyden birini yapar:

1. Hatayı görmezden gelip bildirmeden kullanmaya devam eder.
2. Hata izleme sisteminde bir form doldurup hatayı açıklar.
3. E-posta listesi ya da tartışma forumu aracılığıyla diğer kullanıcıları ve geliştiricileri bilgilendirir.

Ardından daha deneyimli geliştiriciler hatanın basit analizini yapar, doğrular ve hata izleyiciye ekler. Doğrulanmamış hatalar bir sonraki sürece kadar listede bekler.

**Hata doğrulaması.** Hata toplama ve hata düzeltmeden oluşur. Toplanan hataların gerçek olup olmadığı doğrulanır: bir ya da daha fazla geliştirici raporu okur, kodu inceler, yorum yapar, gerekirse ek bilgi ister ve hatayı dört durumdan biriyle işaretler: açık, devam ediyor, yinelenen (duplicate) ya da geçersiz. Doğrulanan hatalar bir listeye alınır. Bir geliştirici hatanın sahipliğini üstlenir ve kısa vadeli bir düzeltme planı yapar, sonra kodu geliştirir.

**Çözüm doğrulaması.** Çözüm kodunun incelenmesine odaklanır. Geliştirici çözüm geliştirirken kendi kodunu sürekli gözden geçirip test eder (kendi kendine kod incelemesi). Hata giderildiyse değişikliği topluluğa gönderir. Hâlâ hata varsa ya da çözüm yeni bir hata doğurduysa hata izleyiciyle bildirir ve hata doğrulaması sürecine geri dönülür. Gönderilen çözümü diğer geliştiriciler eş incelemeyle (peer review) gözden geçirir. Spesifikasyona uygunsa onaylanır; yeni kusur oluşuyorsa reddedilir ve hata "yeniden açık" ya da "yeni" gibi bir durumla hata izleyiciye geri gönderilir. Süreç, hata doğrulanmış biçimde kapatılana kadar devam eder.

**Sonuç.** AKY birçok kurumda, devlette ve kritik uygulamada kullanılmaktadır; bu yüzden kalite güvencesi çok önemlidir. Kara kutu testi gibi temel görevleri ya da kullanıcı geri bildirimini ihmal eden birçok AKY projesi vardır. Bu alan daha fazla araştırma gerektirir.

## 11. Model Tabanlı ve Risk Tabanlı Testin Karşılaştırılması

Sunum, 2017'de yayımlanan ve model tabanlı test (MBT) ile risk tabanlı testi (RBT) karşılaştıran bir makaleye dayanır. Bu sunumu da iki öğrenci birlikte yapmıştır.

### 11.1 Giriş

Yazılım her yerdedir ve yaşam döngüsünde testin önemi artmıştır. Test güdümlü yaklaşımda önce test, sonra kod yazılır; bu testin kodun önüne geçtiğini gösterir. Test edilmeden kullanıcıya gönderilen yazılımın maddi ve manevi sonuçları olabilir. Sunucu makaleden üç örnek aktarmıştır: kanser tedavisinde kullanılan bir yazılımın yanlış çalışmasının ölümlere yol açması, bir uçak arızasıyla ilgili maddi kayıp ve banka kartı sistemindeki bir hatanın yol açtığı maddi kayıp. Yazılım testi, beklenen sonuç ile gerçek sonucun karşılaştırılmasıdır.

### 11.2 Model tabanlı test

Model, bir sistemin işlev, yapı ve davranışının biçimsel belirtimidir. Modeller karmaşık sistemleri soyutlayarak daha esnek gösterir ve çoğunlukla UML'e dayanır. Model tabanlı geliştirmede kod üretilmeden önce her şey modellenir. Amaç gereksinimlere doğru çözüm üretmek ve yapıyı ortak bir dille anlatmaktır.

MBT süreci beş adımdır:

1. **Gereksinim yönetimi:** Müşteri ihtiyaçlarını, isteklerini ve kısıtlarını toplamak, yönetmek ve gereksinim olarak sınıflandırmak. Toplama, analiz, önceliklendirme, doğrulama, tanımlama ve kontrol bu adımdadır. Sürecin potansiyel olarak en önemli adımıdır.
2. **Modelleme** (ekrandan, 02:35:00): Temel amaç sistem gereksinimlerini modellemek, yani test edilen sistemin beklenen davranışını tanımlayan ve test amaçlarına uygun bir davranış modeli oluşturmaktır. Model, gereksinim yönetimi adımından gelen gereksinimlerle bir test uzmanı tarafından oluşturulur. Diyagram, tablo, metin ya da başka gösterimlerle tanımlanabilir ve matematiksel bir biçimle ifade edilebilir.
3. **Üretim:** Model ve test analistinin seçtiği test seçim kriterleri girdi olarak alınır. Modelden soyut test senaryoları ve gereksinim izlenebilirlik matrisi (requirements traceability matrix) üretilir. Bu matris, testler ile kapsadıkları model öğeleri arasındaki bağlantıyı gösterir.
4. **Somutlaştırma:** Soyut test senaryoları, test edilen yazılım (software under test) üzerinde çalıştırılabilecek somut senaryolara dönüştürülür.
5. **Yürütme:** Somut testler çalıştırılır.

Makale MBT yaklaşımlarını dörde ayırmıştır: gereksinimleri temsil eden model UML diyagramlarıyla tanımlanır; gereksinimleri temsil eden model UML olmayan gösterimle tanımlanır; iç yapıyı temsil eden model UML diyagramlarıyla tanımlanır; iç yapıyı temsil eden model UML olmayan gösterimle tanımlanır.

### 11.3 Risk tabanlı test

Risk, gelecekte olumsuz sonuçlara yol açacak bir olayın gerçekleşme olasılığıdır. Risk seviyesi olayın olasılığı ve etkisiyle (zararıyla) belirlenir: riskin olma olasılığı nedir ve olursa ne zarar verir? Risk bir projenin başarısız olmasına ya da gecikmesine yol açabilir.

- Bir hatanın etkisi yüksek ve olma olasılığı yüksekse risk yüksektir; testlerde ve hata çözümünde öncelik bu alana verilir.
- Etkisi düşük, olasılığı düşük ya da orta olan bir sorunun hemen çözülmesi genellikle gerekmez.

RBT riski test planlamasının temeli olarak kullanır. Yazılım kapsamlı test edilemediğinde, daha az zaman ve kaynakla ve kaliteyi düşürmeden seçici test yapmayı sağlar. Test yürütme sırasında uygun testleri seçmek, önceliklendirmek ve yönetmek, sonuçta en önemli şeyleri test etmek için risk kullanılır. Riskin değerlendirilmesinde projenin takvimi, maliyeti ve şirkete etkisi gibi etkenler göz önüne alınır.

RBT süreci:

1. **Gereksinim yönetimi:** Sistem özelliklerinden gereksinimler çıkarılır.
2. **Risk belirleme:** Hangi risklerin olduğu, olasılıkları ve verecekleri zararlar belirlenir.
3. **Analiz ve değerlendirme:** Riskler olasılık ve etkiye göre sınıflandırılır.
4. **Risk azaltma:** Riskin etkisini ya da olasılığını azaltmak için testler planlanır.
5. **Yürütme:** Bu testler uygulanır.

Makaledeki RBT yaklaşımları sınıflandırması: risk analizi ile testi genel düzeyde birleştiren yaklaşımlar, model tabanlı risk tahminine odaklananlar, test senaryosu oluşturmaya odaklananlar, test vaka analizine odaklananlar, otomatik kaynak kodu analizine dayananlar, belirli bir programlama paradigmasını hedefleyenler ve ölçümü hedefleyenler.

### 11.4 Destek araçları

İki teknikten de tam yararlanmak için mümkün olduğunca otomasyon gerekir. MBT'de zorluk, insan müdahalesi olmadan test senaryosu oluşturmaktır. RBT'de ise testin nasıl yönlendirileceği, seçileceği ve değerlendirileceği belirlenmelidir. Araçlar araç kategorisine, model türüne ve test tipine göre sınıflandırılmıştır.

- **Spec Explorer:** Microsoft'un MBT aracıdır. Visual Studio içinde, sistemin beklenen davranışını açıklayan bir model tanımlamaya izin verir ve bu modelden Visual Studio test çerçevesi ya da başka birim test çerçeveleri için otomatik test üretir. Test tekniği fonksiyonel testtir: her işlevin gereksinimlere uygun çalışıp çalışmadığı doğrulanır, kaynak koda bakılmaz (kara kutu). Model tipi soyut durum makinesi ya da sonlu durum makinesidir (FSM).
- Bir başka araç, faaliyet (activity) diyagramlarından otomatik sistem test senaryoları üretir ve bunları riske göre önceliklendirir. Model tipi UML faaliyet diyagramıdır.
- **HP Quality Center:** HP'nin ticari test yönetimi aracıdır. Gereksinim yönetimi, test yönetimi ve iş süreci testi dahil yazılım kalite güvencesi sunar.

<!-- BELİRSİZ: Faaliyet diyagramlarından risk tabanlı test üreten aracın adı altyazıda "Right Tape Tool" diye geçiyor; doğru adı kareden kontrol edilemedi. -->

### 11.5 Sınırlar ve avantajlar

MBT için tablo (ekrandan, 02:45:00):

- **Kalan sorunlar (sınırlar):**
  - Yazılım geliştikçe güncel olmayan gereksinimler yönetilemiyor.
  - Pratik sınırlardan biri test uzmanının becerisidir; model tasarımcıları uygulama alanında uzman olmanın yanı sıra model tasarlayabilmelidir.
  - Oluşturulan testlerden biri başarısız olduğunda başarısız testi analiz etmek zordur.
  - Test edilen sistemin bazı kısımlarını modellemek zordur.
  - Testi gerçekleştirmek için resmî bir şartname ya da model gerekir.
  - Test durumları modele sıkı sıkıya bağlıdır; model değişikliği tamamen farklı test durumları doğurur.
  - Sistemin dinamik yönlerini kapsayan test durumlarını yazmak mühendis uzmanlığına bağlıdır.
  - Model ile uygulama arasındaki bütün farkları tespit etmek zordur.
- **Çözülmüş sorunlar (avantajlar):**
  - Test edilen sistemdeki hataların algılanmasını iyileştirir.
  - Test süresini ve maliyetini azaltır.
  - Test kalitesini ve dolayısıyla yazılım kalitesini artırır.
  - Modelin gereksinimlerden türetilmesi, testin yaşam döngüsünde çok erken başlamasına ve gereksinimlerdeki varsayımların tespitine izin verir.
  - Üretim aşamasında oluşturulan izlenebilirlik matrisiyle gereksinimler ve soyut model arasında izlenebilirlik yönetimi sağlanır.
  - Model, sistemdeki yeni değişikliklere kolayca uyarlanır ve test senaryoları yeniden üretilir; bu, gereksinim değişimine uyumu kolaylaştırır ve bakım maliyetini azaltır.
  - Yüksek düzeyde otomasyon ve yüksek hacimli, tekrarlı olmayan faydalı testlerin üretilmesine olanak tanır.

RBT'nin sınırları gereksinim ile test arasındaki izlenebilirliği yönetmenin zorluğu ve risk değerlendirmesi için doğru dağılımın zorluğudur. Avantajları, risk sırasına göre test yapıldığı için hataların bulunma olasılığının yüksek olması, yüksek riskli hataların önce test edilmesi ve risk azaltmayı kolaylaştırmasıdır. Sunucuya göre RBT neyin test edileceğini önceliklendirir ve uygulamanın iç yapısına bakmadan inceleyen bir kara kutu yöntemidir.

### 11.6 MBT yaklaşımlarının sınıflandırma kriterleri

Çalışmada MBT yaklaşımları dört kritere göre sınıflandırılmıştır:

- **Test tipi:** fonksiyonel, fonksiyonel olmayan ve yapısal testler.
- **Test seviyesi:** sistem, entegrasyon, birim ve regresyon testi.
- **Test kaynağı:** yazılımın iç yapısını ya da gereksinimlerini test kaynağı olarak kullanma.
- **Gösterim türü:** grafik gösterim, komut dosyası ya da sembolik gösterim.

### 11.7 Sonuç

Çalışma iki teknik üzerinde durmuştur. MBT, sistemin ve ortamının soyutlamalarını otomatik test senaryosu üretmek için kullanır. RBT, yazılım risklerini ve test sorunlarını en aza indirmeyi amaçlar; riskler olasılık ve etkiye göre önceliklendirilir ve test senaryoları buna göre seçilir. Makale model ve risk tabanlı bir meta-model önermiş, bazı test sorunlarının üstesinden gelmek için iki tekniğe dayanan ampirik bir çalışma yapılması gerektiğini belirtmiştir.

## Örnek Sorular

Bu derste ekranda ayrı bir soru ya da alıştırma gösterilmemiştir. Aşağıdaki sorular derste sunumlar sırasında sözlü sorulmuştur.

**Soru 1** (derste sözlü, 00:33:08): Otomatik yazılım onarımı sunumunda anlatılan healing (iyileştirme) işlemleri, çalışma sırasında hatayı özümseyip hataya rağmen çalışmayı sürdüren ve o anda düzelten işlemler olarak tanımlanabilir mi?

> **Çözüm:** Evet. Sunucunun cevabına göre healing hatayı yalnız örten bir yara bandı gibidir. Slayttaki şemaya göre healing çalışmayı kurtarır ama programın hatalı kodunu değiştirmez. Bu yüzden sonuç çoğu zaman "başarılı çalışma / hatalı program" olur ve aynı hata yeniden ortaya çıkabilir. Hatanın kalıcı giderilmesi onarım (repair) sürecinin işidir: yerelleştirme, yama üretimi ve doğrulama.

**Soru 2** (derste sözlü, 00:51:01): Kalite tahmininde kullanılan 13 metrik arasındaki SIZE1 ve SIZE2 metrikleri neyi ölçer?

> **Çözüm:** Sunucuya göre SIZE2, sınıftaki öznitelik sayısı ile yerel metot sayısının toplamıdır. SIZE1 ise sınıfın büyüklüğünü çalıştırılabilir öğe sayısıyla ölçer. Bu metrikler büyük olasılıkla Li ve Henry'nin metrikleridir; orada SIZE1 sınıftaki noktalı virgül (ifade) sayısı olarak tanımlanır.

## Dersin Toparlaması

Bu derste yazılım kalitesi ve testin güncel araştırma konuları öğrenci sunumlarıyla taranmıştır. Kalite tarafında depo benzerliği ve yeniden kullanım, kritik sistemlerde çevik geliştirme ile kalite güvencesinin dengesi (Cynefin), kötü koku ve yeniden düzenleme, makine öğrenmesiyle güvenilirlik ve sürdürülebilirlik tahmini ve açık kaynakta kalite güvencesi ele alınmıştır. Kalite tahmini sunumu, derste görülen CK metriklerinin ve kalite faktörlerinin pratikte tahmin modellerine nasıl girdi olduğunu göstermiştir.

Test tarafında beklenen çıktının bilinmediği sistemler için kâhin teknikleri (N-versiyon, metamorfik test, bildirimler, ML kâhinleri, istatistiksel hipotez testi), regresyon testinde senaryo önceliklendirme ve APFD ölçütü, otomatik yazılım onarımı, dağıtık çevik ekiplerde geliştirici ile test uzmanı iletişimi, model tabanlı ve risk tabanlı test incelenmiştir. Son sunumdaki risk = olasılık × etki yaklaşımı ve gereksinim izlenebilirlik matrisi, derste daha önce görülen risk yönetimi ve test planlama konularıyla doğrudan bağlantılıdır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
