# Ders 2 Genişletilmiş Notu: Etmenler (Ajanlar), Ortam Özellikleri ve Arama Problemlerinin Formülasyonu

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Zekayı Ölçme Tartışmasının Tekrarı
- 2. Rasyonel Ajan: Sensörler, Aktüatörler ve Eşleme
- 3. Ajan Türleri
- 4. Ajan Türlerine Örnekler: Grup Çalışması
- 5. PEAS: Ajan Tasarımının Parametreleri
- 6. Ortam Özellikleri
- 7. Arama Problemleri ve Formülasyon
- 8. Çiftçi, Kurt, Keçi ve Kabak Problemi
- 9. Su Bidonları Problemi
- 10. 8-Puzzle
- 11. Arama ile İlgili Tanımlar
- 12. Arama Neden Zor?
- 13. Arama Stratejileri ve Değerlendirme Ölçütleri
- 14. Enlemesine Arama (Breadth-First Search)
- Örnek Sorular
- Dersin Toparlaması

## 1. Zekayı Ölçme Tartışmasının Tekrarı

Ders, bir önceki haftada konuşulanların tekrarıyla başladı. Önceki derste bir sisteme "zeki" demenin ölçütü tartışılmıştı ve iki temel görüş öne çıkmıştı.

Birinci görüşe göre sistem dışarıdan gözlenebilen davranışlarına bakılarak değerlendirilir. Sistemin hareketlerini, tepkilerini, yani sonuçlarını gözler ve buna göre "bu sistem zekidir" ya da "değildir" deriz. Bu yaklaşıma **fonksiyonellik** denir. Bunun en bilinen örneği Turing testidir: Başka bir odadaki bir sistemle yazışarak iletişim kurarsınız, verdiği cevaplara, yani çıktılarına bakarak karşınızdakinin zeki olup olmadığına karar verirsiniz.

İkinci görüş ise sonuca değil, o davranışın **nasıl üretildiğine** bakılması gerektiğini söyler. Zeka, sürecin bir sıfatıdır. Bu görüşü destekleyen örnekler arasında Searle'ün Çin odası deneyi ve önceki derste anlatılan soru-cevap ağacı gibi düşünce deneyleri vardı. Ortak fikir şudur: Dışarıdan bakıldığında çok bilgili, insandan ayırt edilemeyen bir sistemin arkasında çok basit bir mekanizma çalışıyor olabilir. Bir programla yapılan böyle bir şey zeki sayılamaz.

<!-- BELİRSİZ: Altyazıda "Galatasaray'ın sınıf arkadaşı" ve "Netblock'un soru cevap ağacı" diye geçen örneklerin doğru adları anlaşılamadı (00:09:15). -->

Hoca burada bir soru sordu: Biz insanlar, bir arkadaşımızın ya da herhangi bir sistemin zeki olup olmadığını nasıl ölçüyoruz? Bir öğrenci "probleme bakış şekli, çözüm üretme şekli" diye cevap verdi. Hoca bunların da dışarıdan gözlenen şeyler olduğunu belirtti. Bir insanın beynindeki süreçlere, hangi sinirden hangi sinire sinyal gittiğine ne kendimizinkinde ne de başkasınınkinde erişebiliriz. Dolayısıyla insanlar olarak biz de aslında Turing testindekine benzer bir şey yaparız: Bir davranışı görürüz ve çıktılarına bakarak o davranışın zeki olup olmadığına karar veririz.

Hocanın örneği Kasparov'du. Kasparov bir zamanlar dünya satranç şampiyonuydu ve muhtemelen zeki birisidir. Ona zeki dememizin sebebi dünya şampiyonu olmasıdır, bu da dışarıdan gözlenebilir bir şeydir. Fakat o zaman şu soru gelir: Kasparov'u yenen bir sisteme, örneğin Deep Blue'ya zeki demeli miyiz? Satranç performansını zekanın ölçütü kabul edersek Deep Blue Kasparov'dan daha zeki olur. Bugünkü programlar ise çok daha "zeki" sayılır. Oysa bunlar birer programdır. Dersin oyunlar kısmında görülecek algoritmaları kullanan, programı takip eden sistemlerdir. Tartışma bu iki görüş arasında gidip gelir.

Önceki derste yapay zekanın tarihçesi ve "kime kolay, kime zor" slaytları da işlenmişti. Ders buradan etmenler (ajanlar) konusuna geçti.

## 2. Rasyonel Ajan: Sensörler, Aktüatörler ve Eşleme

Etmen ve ajan aynı anlama gelir. Önceki derste gösterilen dört kutulu tablo hatırlatıldı (ekrandan, 00:15:00):

| | İnsan gibi | Rasyonel |
|---|---|---|
| Düşünmek | İnsan gibi düşünmek | Rasyonel düşünmek |
| Hareket etmek | İnsan gibi hareket etmek | **Rasyonel hareket etmek** |

Derste rasyonel hareket etmek merkeze alınır, yani **rasyonel ajan** incelenir. Ajan, kendi başına bir şeyler yapabilen bir sistemdir. Fiziksel (donanım) ya da yazılımsal olması önemli değildir.

Her ajanın **sensörleri** ve **aktüatörleri** (eyleyicileri) vardır:

- **Sensörler** dış ortamı, çevreyi algılamak için kullanılır. Bilgisayarın klavyesi, mikrofonu, kamerası, dokunmatik arayüzü birer sensördür. Lidar ve mesafe ölçerler, üç boyutlu kameralar, GPS sensörleri de sensörlere örnektir.
- **Aktüatörler** ajanın çevreye verdiği cevapları iletmek için kullandığı manipülatörlerdir. Kol, bacak, tekerlek olabilir. Ama her zaman böyle bir şeye gerek yoktur: Ekran da bir aktüatördür, çünkü ortama bir çıktı üretir. Hoparlör ya da otonom bir araçtaki korna da aktüatördür.

Ajan bir ortamın (environment) içinde hareket eder. Slayttaki şekilde ortamdan ajana algılar (percepts), ajandan ortama hareketler (actions) gider. Ajanın ortasında bir soru işareti vardır. Amacımız, sensörlerden gelen girdilere göre aktüatörlere bir şeyler yaptırmaktır. Yani girdileri çıktılara dönüştüren bir **eşleme (mapping) mekanizması** kurmak isteriz. Kabaca düşünülürse insan ya da herhangi bir canlı da bu şemaya uyar: Dışarıdan bir şeyler algılar ve dışarıya bir şeyler yapar. Asıl soru, sensörlerden aktüatörlere geçişin nasıl yapılacağıdır, yani o soru işaretli kısımdır. Bunun için pek çok fikir, yöntem ve algoritma vardır ve ders boyunca bunlar incelenecektir.

## 3. Ajan Türleri

Soru işaretinin içi farklı biçimlerde doldurulabilir. Slayttaki ayrımlar şunlardır (ekrandan, 00:20:00). Hoca, bir ajanın bu türlerden yalnız birine girmek zorunda olmadığını, birden fazlasına girebileceğini vurguladı.

### 3.1 Refleksif, tam eşleme

Slayttaki tanım: "O ana kadarki tüm girdi sekansına / mevcut girdiye karşılık gelen hareketi uygula (durum → hareket ikilileri)". Bazı sistemler yalnız anlık girdiye karşı çıktı üretir, bazılarının ise o ana kadar gelen bütün sensör verilerine bakması gerekir. Her iki durumda da elimizde bir tablo olduğunu düşünelim. Tabloda durum-hareket ikilileri vardır: "Şöyle bir girdi varsa şu çıktıyı uygula." Girdi tablodaki bir durumla tam olarak eşleştiğinde o satırdaki hareket uygulanır. Bu, tam eşlemeli refleksif ajandır.

Hoca böyle bir sistemin problemini sordu. Bir öğrenci "girdi sekansı çok uzun olabilir" dedi. Hoca bunun büyük bir sıkıntı olmadığını, uzun bir sekansın bir şekilde depolanabileceğini söyledi. Başka bir öğrenci asıl problemi buldu: Girdiye tam uyan bir satır her zaman bulunamayabilir. Öyle bir sensör bilgisi gelebilir ki tabloda ona dair hiçbir şey yoktur. O zaman ne yapılacaktır?

Bunu çözmek için tablonun büyütülmesi, bütün olası durumları kapsaması gerekir. Olası durumların sayısı çok büyük değilse bu yapılabilir. Çok büyükse yapılabilecek fazla bir şey kalmaz. Belki en sık karşılaşılan durumlar için tabloya ayrı satırlar yazılır, geri kalan bütün durumlara tek bir hareket verilir.

### 3.2 Refleksif, yaklaşık eşleme

Tam eşlemenin karşılığı yaklaşık eşlemedir: Girdiye en çok benzeyen durum belirlenir ve bu duruma karşılık gelen hareket uygulanır. Girdi tablodaki hiçbir duruma tam uymuyorsa, bir benzerlik ölçüsüyle en yakın durum bulunup onun hareketi kullanılır.

### 3.3 Hafızalı ve hafızasız

Slayttaki tanım: Zamanla değişebilen bir iç durumun var olup olmaması. Hafızalı bir ajan aynı girdi için her zaman aynı çıkışı üretmeyebilir.

Hoca bunu iki örnekle açıkladı. Birincisi satranç: Bir bilgisayarın en iyi hamleyi yapması için tahtanın son hali yeterli midir, yoksa tahtanın daha önceki hallerine de ihtiyaç var mıdır? Öğrenciler son konumun yeterli olduğunu söyledi. Bilgisayar açısından son tahta, ne yapılabileceğine dair gerekli çıkarımı yapmaya yeter.

İkinci örnek borsada otomatik alım satım yapan bir sistemdi. Sistem bir hissenin değerinin çıkıp çıkmayacağını tahmin etmelidir. Burada hoca eğitim sürecinden değil, çalışma anından söz ettiğini özellikle belirtti. Çalışırken tek bir anlık değer yetmez. Bir trendi görmek, bir pencerenin içindeki değerlere bakmak gerekir. Yani tarihçe bilgisine ihtiyaç vardır.

Kişiselleştirilmiş arama motoru da hafızalı bir sistemdir. Aynı kelimeyi siz yazdığınızda bir sonuç, başkası yazdığında başka bir sonuç çıkar. Size göre özelleşmiş bu mekanizmalar içeride hafıza tutmak zorundadır.

### 3.4 Kendi öğrenen ve öğretilen

Slayttaki tanım: Karar mekanizmasını çevre ile etkileşerek optimize eden / karar mekanizması insanlar tarafından oluşturulmuş. Öğretilen sistemlere örnek olarak kural tabanlı uzman sistemler verilebilir. Standart bir hesap makinesi de böyledir: Girdiden çıktının nasıl üretileceği, insanların donanım seviyesinde oluşturduğu programla belirlenmiştir. Hesap makinesi aynı zamanda tam eşlemeli bir sistemdir, orada yaklaşık eşleme diye bir şey yoktur.

### 3.5 Öğrenimi hep süren ve sürmeyen

Slayttaki tanım: Karar mekanizmasının değişimi devam eden / bir kere öğrenildikten sonra değişmeyen. Hocanın örneği Zoom'daki arka plan ayırmaydı. Resimlerde insan yüzünü algılayan ve ön plan ile arka planı ayıran bu sistem önce uzun bir eğitimden geçer. Eğitildikten sonra sabit kalır ve öyle çalışır. Çalışırken kendini güncellemez.

Ayrımın kriteri tam olarak budur: **Sistem çalışırken (test zamanında) kendi parametrelerini güncelliyor mu?** Çalışırken gelen girdilerin bir yere kaydedilip, daha sonra geri bildirimlerle eğitim kümesine eklenip modelin yeniden eğitilmesi bu anlama gelmez. Bu kavrama "lifelong learning" denir. Hoca, makineler için yapılan bu ayrımı insanlara uygularsak insanların öğreniminin her zaman sürdüğünü söyledi: İstemesek de sürekli bir şeyler öğrenir, durmadan değişiriz.

## 4. Ajan Türlerine Örnekler: Grup Çalışması

Hoca öğrencileri 12 gruba ayırdı ve her gruptan bu ajan türlerine örnek bulmasını istedi. Sonra grupların sözcüleri bulduklarını anlattı, hoca da örnekleri tek tek tartıştı. Bu bölümde öne çıkan örnekler ve hocanın düzeltmeleri bir araya getirilmiştir.

### 4.1 Tam eşleme mi, yaklaşık eşleme mi?

- **Robot süpürge ve otonom araç:** Bir grup bunları refleksif ajan olarak önerdi. Hoca, gerçek dünyada çalışan ve ortamı sensörleriyle algılayan bir sistemin tam eşleme yapmasının düşük bir ihtimal olduğunu söyledi. Gerçek dünyada sürekli aynı şeylerle karşılaşmak çok olası değildir, dünya durmadan değişir. Bu tür sistemler yaklaşık eşleme yapmalıdır.
- **Parmak izi:** Bir grup parmak izi eşlemeyi tam eşleme olarak önerdi. Hoca, sistemde kayıtlı parmak izi ile o anda okunan izin birebir aynı olmasının neredeyse imkansız olduğunu söyledi. Hiçbir sensör o doğrulukta çalışamaz. Eşleme yapılır, ama bu yaklaşık eşlemedir.
- **Çeviri sistemleri:** Bir grup Google Translate gibi çeviri sistemlerini tam eşlemeye örnek verdi. Hoca, tam eşleme olması için çevrilebilecek bütün cümlelerin içeride tek tek kodlanması gerektiğini söyledi. Girdi uzayının ne kadar büyük olacağı düşünülürse bu tam eşleme olamaz.
- **Maden arayan robot / Mars keşif aracı:** Bu örnek de tam eşleme için önerildi. Hoca burada da tam eşlemenin mümkün olmadığını, bu işlerin yaklaşık eşleme gerektirdiğini söyledi.
- **Kabul edilen tam eşleme örnekleri:** Hesap makinesi, telefondaki alarm (ayarlanan saatte çalar), telefon araması ya da komut konsolları, klavye (bir tuşa basınca o tuşun karakteri çıkar, başka bir alfabe için o alfabeye göre hazırlanmış bir klavye gerekir) ve oda sıcaklığını sabit bir değere ayarlayan termostat.
- **Yaklaşık eşleme örnekleri:** Yüklenen fotoğrafa en çok benzeyen ünlüyü bulan uygulamalar, öneri sistemleri, ELIZA tarzı botlar ve bir hayvan resminin hangi hayvan olduğunu bulan sınıflandırıcılar.

### 4.2 Hafızalı mı, hafızasız mı?

- **Sohbet botları:** Bir grup sohbet botlarını hafızasız olarak önerdi. Hoca bunun botun tipine bağlı olduğunu söyledi. ELIZA tamamen hafızasızdır, yalnız kullanıcının son yazdığına bakarak cevap verir. Bu yüzden hafızasız ve yaklaşık eşlemeli bir sistem olarak düşünülebilir. Diyalog içinde kullanıcının daha önce söylediklerini ya da kendi söylediklerini kullanarak sıradaki cevabını üreten bir bot ise hafızalıdır. Hukuk sorularına cevap veren bir botun hafızasız olması için de yalnız kullanıcının son cümlesine bakması, önceki cümleleri dikkate almaması gerekir.
- **Robot süpürge:** Evin planı ona verilmiş ve gideceği yol önceden hesaplanmışsa nereyi süpürdüğünü bilmesine gerek olmayabilir. Ama bilinmeyen bir eve bırakıldığında haritasını kendisi çıkarıyorsa, nereyi süpürüp nereyi süpürmediğini aklında tutması gerekir. Bir odadan çıkıp başka bir odaya geçtiğinde aynı odaya geri dönmemelidir. Bu durumda hafızaya ihtiyaç vardır.
- **Hava durumu tahmini:** Bir grup bunu hafızalı sisteme örnek verdi. Hoca nedenini şöyle açıkladı: Kışın ölçülen 19 derece ile yazın ölçülen 19 derece farklı anlamlara gelir. Birinde hava ısınmış, diğerinde çok soğumuştur. Sistemin geçmişi, bir pencereyi kullanması gerekir.
- **Reklam önerisi, Spotify ve Netflix gibi öneri sistemleri:** Kullanıcının geçmiş bilgilerini kullandıkları için hafızalıdır.
- **Hafızasız örnekler:** Yüz tanıma ve maske tespiti sistemleri. Bir girdiyi değerlendirmek için önceki girdileri hiçbir şekilde kullanmazlar, yalnız o anki girişe göre karar verirler. Dama ve satranç gibi tahta oyunları da (son tahta yeterli olduğu için) hafızasız olarak kabul edildi.

### 4.3 Kendi öğrenen mi, öğretilen mi?

Bu ayrımda en çok karışıklık çıkan nokta, "öğretilen" kavramının anlamıydı. Hoca birkaç kez şu açıklamayı yaptı: Öğretilen derken karar mekanizmasının, yani "girdiler şöyle olduğunda çıktı şöyle olsun" yapısının **insanlar tarafından** konmasından bahsedilir. Kendi öğrenen ise bu mekanizmayı **örneklerden ya da etkileşimlerden kendisi** öğrenir.

**Soru:** Normalde eğittiğimiz modeller kendi öğrenen sistemlere mi girer?
**Cevap:** Evet. Etiketli ya da etiketsiz verilerle bir model eğitiyorsanız bu kendi öğrenendir. Ama insanlar "şu durumda şunu yap" gibi kuralları kodlayıp içeri veriyorsa ve sistem bu kurallarla çalışıyorsa öğretilendir.

**Soru:** Daha önce Prolog'da yaptığımız şeyler o zaman öğretilen mi oluyor?
**Cevap:** Evet. Prolog'da hangi durumda ne yapılacağını tamamen kural tabanlı olarak yazıyoruz.

Tartışılan örnekler:

- **Yüz tanıma:** Bir grup yüz tanımayı, önceden büyük bir eğitimden geçtiği için öğretilen olarak önerdi. Hoca, mekanizmayı insanlar kurduysa öğretilen, etiketli bir eğitim kümesi verilip öğrenmesi sisteme bırakıldıysa kendi öğrenen olduğunu söyledi.
- **Siri, Google Asistan gibi sesli asistanlar:** Bir grup bunları öğretilen olarak önerdi. Hoca, bu sistemlerde gerçekten insanların yazdığı kısımlar olduğunu anlattı: "Evli misin, kaç yaşındasın, seni kim yarattı" gibi herkesin sorduğu standart sorulara ilginç cevaplar yazan insanlar vardır. Böyle bir soru sorulduğunda sistem bu cevaplardan birini rastgele seçer. Bu kısım hem tam eşlemeli hem öğretilendir. Ama geri kalan kısımlarda böyle kural tabanlı bir yapı yoktur, arka planda eğitim kümeleriyle eğitilmiş modeller çalışır. Yani bu tür sistemler tek parça değildir. Duruma göre tam eşleme, duruma göre yaklaşık eşleme yaparlar.
- **Face ID ve parmak izi:** Bir grup bunları, kullanıcı başta parmağını birkaç kez okuttuğu için öğretilen olarak önerdi. Hoca bunların öğretilen sistemler olmadığını söyledi.
- **Otonom araçlar:** Hoca, bir sistemin otonom çalışmasının onun kendi öğrenen olduğunu göstermediğini vurguladı. Otonom bir aracın karar mekanizması insanlar tarafından kurallarla yazılmış olabilir. Etiketli örneklerle eğitildiyse kendi öğrenen olur. Belirleyici olan, eğitim sürecinin nasıl yapıldığıdır. Test sırasında nasıl çalıştığı bu ayrımı belirlemez.
- **Spam filtresi:** İnsanlar "içinde şu kelimeler varken spam, şunlar yokken değil" gibi kurallar yazdıysa öğretilen, örneklerle eğitildiyse kendi öğrenendir. Hoca, yalnız uygulamanın adını söylemenin yetmediğini, sistemin nasıl eğitildiğini söylemenin çok daha net bir cevap olacağını ekledi.
- **Labirent çözen sistem:** Mekanizmayı insanlar kurallar aracılığıyla verdiyse öğretilen, pekiştirmeli öğrenme (reinforcement learning) gibi bir mekanizmayla çalışıyorsa kendi öğrenendir.
- **Navigasyon:** Bir grup navigasyonu öğretilen olarak verdi. Hoca kabul etti: En kısa yolu bulma mekanizması insanlar tarafından kodlanmıştır.
- **Basit bilgisayar oyunu yapay zekaları:** Oyuncunun hareketine karşı yapılacak hareket koda gömülü (hard-coded) ise öğretilendir.
- Bir grup, oyun yapay zekalarının "önce eğitilip canlıya alındıktan sonra öğrenmeyi bırakmasını" öğretilene örnek olarak verdi. Hoca bunun öğretilene değil, öğrenimi sürmeyene örnek olduğunu söyledi.

> **Hocanın vurgusu:** Eğitimin sürüp sürmemesi ayrı bir boyuttur, sistemin kendisinin öğrenmesi ya da başkasının öğretmesi başka bir boyuttur.

### 4.4 Öğrenimi hep süren mi, sürmeyen mi?

- **Borsa tahmini yapan sistem:** Bir grup, bir hisse için tahmin yapan, bir iki ay sonraki duruma göre tahminini değiştiren sistemi önerdi. Hoca bunu şöyle netleştirdi: Bir tahminde bulunursunuz, sonra tahminin gerçekleşmediğini görürsünüz, buradan tahmini üreten mekanizmayı güncellemeniz gerektiğini anlarsınız. Bu öğrenimin sürmesi demektir.
- **Yüz tanıma ve geri bildirim:** Bir grup, tanıma sonucu hakkında geri bildirim verildiğinde kendini güncelleyen bir yüz tanıma sistemini önerdi. Hoca burada kriteri yineledi: Modeller her zaman güncellenir. Bir şeyi eğitirsiniz, bir süre kullanırsınız, eskir ve güncellemeniz gerekir. Bu, öğrenimin hep sürdüğünü göstermez. Önemli olan güncellemenin test zamanında, çalışırken, insan müdahalesi olmadan yapılmasıdır.
- **Satranç:** Bir grup, her maçtan sonra o maçta yaptıklarına, rakibin hamlelerine ve maçın sonucuna göre kendini yeniden eğiten bir satranç programını öğrenimi hep süren olarak önerdi. Hoca kabul etti.
- **Arama motorları:** Sürekli yeni gelen sitelerin içeriklerini kontrol edip anlamlandıran ve gerekirse sıralamayı değiştiren sistemler öğrenimi hep süren olarak önerildi.
- **Transfer piyasası sistemleri:** Oyuncuların değerlerini yaş ve yetenek değiştikçe güncelleyen bir sistem önerildi. Hoca, bu değişikliklerin nasıl yapılacağının kurallarla kodlanmış da olabileceğini hatırlattı.
- **Öğrenimi sürmeyen örnekler:** Bir kez eğitilip test zamanında hiç güncellenmeyen görüntü sınıflandırma modelleri, doğal dil işlemede bir kez eğitilen varlık ismi tanıma modelleri, fabrikalarda hep aynı işi yapan robot kolları, basit sohbet botları ve kurallarla programlanan micromouse (labirent yarışması robotları).

## 5. PEAS: Ajan Tasarımının Parametreleri

Aradan sonra hoca, bir ajanı tasarlamadan önce karar verilmesi gereken parametrelere geçti. Bunların baş harfleri **PEAS** kelimesini oluşturur:

- **P (Performance measure):** Ajanın performansını nasıl ölçeceğiz?
- **E (Environment):** Ajan nasıl bir ortamda çalışacak? Ortamın özellikleri neler?
- **A (Actuators):** Aktüatörlerimiz neler olacak? Ortamı nasıl değiştireceğiz?
- **S (Sensors):** Sensörlerimiz neler olacak? Ortamı nasıl algılayacağız?

Bunlar ajanı tasarlamaya başlamadan önce bilinmesi gereken şeylerdir. Zamanla güncellenebilirler.

### 5.1 Harita çıkaran robot

İşi karmaşıklaştırmamak için tek katlı bir binanın içinin haritasını çıkaran bir robot düşünelim (ekrandan, 01:35:00):

- **P:** Haritanın doğruluğu, işlem hızı, statik / dinamik ortamlarda çalışabilmesi.
- **E:** Duvarlar, bina içi, dış ortam, statik / dinamik, engeller.
- **A:** Tekerleklerin yönü ve hızı, kamera kontrolü.
- **S:** Lazer / sonar / kızılötesi uzaklık algılayıcılar, kamera.

Haritanın doğruluğu açıktır: Harita ne kadar doğru çıkarıldı? İşlem hızı da önemlidir: Haritayı bir günde çıkarmak ile bir saatte çıkarmak farklı şeylerdir.

Statik ve dinamik ortam ayrımı burada açıklandı. **Statik** ortamda ajan dışında ortamı değiştiren başka bir nesne yoktur. Boş bir binanın haritasını çıkarmak statik bir ortamdır. Çalışma saatinde, içinde insanların gezdiği bir AVM katının haritasını çıkarmak ise **dinamik** bir ortamdır. İçeride başka robotlar varsa, örneğin birden fazla ajan aynı katın haritasını işbirliği içinde çıkarmaya çalışıyorsa, ortam yine dinamik olur.

Ortam bir kampüs olursa tanım değişir: Bina içi ve dış ortam birlikte olabilir, ortamda geçilebilen ve geçilemeyen engeller bulunur. Kamera sabit değil de hareketli olacaksa kamerayı hareket ettiren motorlar da kontrol edilmelidir. Bu da aktüatörlere eklenir.

### 5.2 Otonom taksi sürücüsü

- **P:** Güvenli olmalı, hızlı gidebilmeli (çok yavaş gitmesi iyi değildir), ama yasal olmalı. Konforlu olmalı, yani çok ani ivmelenmeler ve ani dönüşler yapmamalı.
- **S:** Kameralar, uzaklık ölçerler, hız ölçerler, motor sensörleri. Müşterinin gideceği yeri tarif etmesi için mikrofon, klavye-fare ya da cep telefonundaki bir arayüz de sensör sayılır.

Hoca bütün araçlar otonom olursa korna gibi şeylere gerek kalmayacağını, araçların kendi aralarında haberleşerek çok daha sessiz bir iletişim yolu bulabileceklerini söyledi.

<!-- BELİRSİZ: Otonom taksi slaytının E ve A maddeleri karelerde yok; altyazıda yalnız P ve S maddeleri anlatıldı (01:35:35). -->

Slaytlarda tıbbi teşhis uzmanı, banttan geçen balıkları türlerine göre ayıran ajan ve İngilizce öğretmeni için de PEAS örnekleri vardı. Hoca bunları öğrencilerin kendisinin incelemesini istedi.

## 6. Ortam Özellikleri

Ortamlar çeşitli ölçütlere göre sınıflandırılır (ekrandan, 01:40:00):

- **Fully observable / partially observable:** Ajanın sensörleri ortamın tamamını algılayabiliyorsa ortam tam gözlenebilir (fully observable), algılayamıyorsa kısmen gözlenebilirdir.
- **Deterministic / stochastic:** Ortamın bir sonraki durumu yalnız şu anki durum ve ajanın yaptığı hareketle belirleniyorsa deterministiktir. İçinde şans varsa stokastiktir. Slaytta ayrıca, ortamın bir sonraki durumuna diğer ajanların hareketleri de etki ediyorsa bunun "strategic" bir ortam olduğu yazıyor.
- **Episodic / sequential:** Yapılan bir hareket ileriye doğru etki etmiyorsa ortam epizodiktir. Slayttaki örnekler klasik arama motoru ve parmak izi tanımadır. Arka arkaya yapılan hareketler süreci etkiliyorsa ortam sequential'dır.
- **Static / dynamic:** Ajan dışında ortamı değiştiren bir şey olup olmaması (bkz. Bölüm 5.1).
- **Discrete / continuous:** Algılar ve hareketler sınırlı sayıda ve açıkça belirtilmişse ortam ayrıktır (discrete). Sonsuz sayıdaysa süreklidir (continuous).
- **Single agent / multi agent:** Ortamda bir ya da birden çok ajan bulunması.

Tam gözlenebilirlik için hoca örnek istedi. Bir öğrenci, bir labirente tepeden bakıp aşağıdaki bir araca yol gösteren bir drone önerdi. Drone labirentin tamamını gördüğü için ortam tam gözlenebilir olur. Hoca bunu kabul etti ve daha basit örnekler verdi: Satranç motoru için ortam tamamen gözlenebilirdir. Okey oynayan bir ajan için ise ortam kısmen gözlenebilirdir, çünkü rakiplerin eli görülemez.

> **Hocanın vurgusu:** Gerçek dünya kısmen gözlenebilir, stokastik, sequential, dinamik, sürekli ve çok ajanlıdır. Her ölçütte zor olan taraftadır: Kısmen gözlenebilir, tam gözlenebilirden; stokastik, deterministikten; sequential, epizodikten; dinamik, statikten; sürekli, ayrıktan; çok ajanlı, tek ajanlıdan daha zordur. Yani gerçek dünya üzerinde çalışılabilecek en zor ortamdır. Simülasyon ve oyun dünyaları bu açıdan harikadır.

## 7. Arama Problemleri ve Formülasyon

Ajanlardan sonra arama konusuna geçildi. Hoca aramanın yaklaşık beş hafta süreceğini, her hafta bir türüne bakılacağını söyledi. Bu hafta aramanın temelleri anlatıldı: Problemler bir arama problemi olarak nasıl ifade edilir ve çözmek için nasıl formüle edilir?

### 7.1 Planlama: Bloklar dünyası

Problem, masadaki küpleri mevcut dizilişlerinden istenen dizilişe getirmektir. Başlangıçta A, B, C küpleri belli bir dizilişte durur ve amaç onları başka bir dizilişe getirmektir. Olası hareketler şunlardır: küpü tutmak, küpü yere koymak, küpü başka bir küpün üzerine koymak. Çözüm bir **hareket sırası** olacaktır. Örneğin "önce B'yi al, A'nın üstüne koy, sonra C'yi al, B'nin üstüne koy" gibi sıralı bir hareketler dizisi aranır.

<!-- BELİRSİZ: Bloklar dünyası slaytındaki başlangıç ve hedef dizilişleri karelerde okunmuyor. -->

### 7.2 Robot yol planlama

Slayttaki problem (ekrandan, 01:45:00):

- Başlangıç noktasından (B) hedef noktasına (H) gitmek.
- Olası hareketler: sola, sağa, aşağıya, yukarıya.
- Olası hareketlerin maliyetleri birbirinden farklı olabilir.
- En az maliyetli hareketler dizisini bulmak.

Slaytta kırmızı hücrelerin geçilemeyen yerler olduğu bir ızgara labirent var. Hoca maliyetlerin neden farklı olabileceğini şöyle açıkladı: Labirent yatay değil de dikey bir düzlemde olsun. Yukarı gitmek daha fazla enerji harcatır, aşağı gitmek daha az. Sağa ve sola gitmek muhtemelen birbirine eşittir. Yani en ucuzu aşağı, sonra sağa-sola, en pahalısı yukarı gitmek olabilir.

Çözüm yine olası hareketlerin bir dizisidir: sağa git, sağa git, aşağı git ve sonunda bir yol bulunur. Bunun gibi pek çok çözüm bulunabilir ve aralarından en iyisini bulmak da mümkündür.

> **Hocanın vurgusu:** Çözüm bulmak ile en iyi çözümü bulmak aynı şey değildir.

## 8. Çiftçi, Kurt, Keçi ve Kabak Problemi

Slaytta "Cin Ali Nehirde" başlığıyla verilen bu problemde Ali adında birinin küçük bir sandalı vardır. Ali kurdunu, keçisini ve kabağını nehrin karşı tarafına geçirmek ister. Kısıtlar şunlardır:

- Sandal Ali ile birlikte en fazla bir nesne taşıyabilir.
- Sandal tek başına gidemez, Ali içinde olmak zorundadır.
- Keçi-kabak ve kurt-keçi ikilileri, Ali yanlarında değilken nehrin aynı tarafında olmamalıdır. Yoksa keçi kabağı ya da kurt keçiyi yer. Ali yanlarındaysa onları durdurur.

Amaç, hiçbir yeme olayı gerçekleşmeden herkesi diğer tarafa geçirmektir.

### 8.1 Problemin gösterimi

Önce neyin ifade edilmesi gerektiğine karar verilir. Dört nesne vardır: Ali, kurt, keçi ve kabak. Sandal da vardır, ama gösterilmesine gerek yoktur. Çünkü sandal her zaman Ali ile birlikte olmak zorundadır. Sandala "sen karşıya geç" ya da "buraya gel" diyemeyiz. Ali ve sandal her zaman birlikte hareket eder, bu yüzden sandal modelden çıkarılır.

Her nesnenin nehrin kuzeyinde ($N$) ya da güneyinde ($S$) olduğu kodlanır. Başlangıçta hepsi güneydedir. Durum, (çiftçi, kurt, keçi, kabak) sırasıyla dört harfle gösterilir. Başlangıç durumu $(S, S, S, S)$, hedef durumu $(N, N, N, N)$ olur.

Hoca burada kaç olası durum olduğunu sordu. Bir öğrenci önce 8 dedi, sonra 16 cevabı geldi. Her nesne iki yerde olabildiğine göre toplam $2^4 = 16$ durum vardır (ekrandan, 01:50:00).

### 8.2 Yasak durumlar

Yasak durumlar geçmememiz gereken durumlardır. Slaytta bunlar kalıplar halinde verilmiştir. Bazı kalıplarda bir konumun önemsiz olduğu (yerine $N$ de $S$ de gelebileceği) belirtilir. Örneğin kurt ve keçi ikisi de güneydeyken Ali kuzeyde olmamalıdır, ikisi de kuzeydeyken Ali güneyde olmamalıdır. Bu durumda kabağın yeri önemsizdir, yani her kalıp iki durumu ifade eder. Keçi ile kabak için de aynı şekilde iki kalıp vardır. Hoca toplam 8 yasak durum saydı: bir başlangıç durumu, 8 yasak durum ve bir hedef durumu, toplamda 16 durum içinde.

> **Ders sonrası not:** Dört kalıbın her biri iki durum verdiği için slaytta 8 satır vardır. Ancak $(N, S, S, S)$ hem kurt-keçi hem keçi-kabak kalıbına, $(S, N, N, N)$ de her ikisine birden uyar. Bu yüzden birbirinden farklı yasak durum sayısı 6'dır (python ile sayıldı). Hocanın "8 yasak durum" demesi büyük olasılıkla kalıp satırlarının sayısıdır.

<!-- BELİRSİZ: Yasak durumların listelendiği slayt karelerde yok; kalıplar altyazıdaki anlatımdan kuruldu (01:48:16). -->

### 8.3 Operatörler

Durumları birbirine dönüştüren şeylere aksiyon, hareket ya da operatör denir. Üçü de aynı anlama gelir. Örnek olarak "keçiyi kuzeye taşımak" operatörü (ekrandan, 01:50:00):

- Başlangıç durumu: keçi güneyde.
- Bitiş durumu: keçi kuzeyde.
- Diğer nesnelerin yerinin önemi yok.

Gösterimi:

```text
Move(Goat, North)
(S, ?wolf, S, ?cabbage) => (N, ?wolf, N, ?cabbage)
```

Burada `?wolf` kurdun yerini gösteren bir değişkendir. Kurdun yeri neyse sonuçta da aynı kalır, kabak için de aynı şey geçerlidir. Operatör yalnız çiftçinin ve keçinin taşındığını gösterir. Slayta göre değişken kullanımı bizi çok sayıda kural yazmaktan kurtarır: Burada 4 kural yerine 1 kural yeter (kurt ve kabağın her birinin iki olası yeri için ayrı ayrı kural yazmak gerekirdi).

### 8.4 Örnek çözüm

Hoca slayttaki çözümü adım adım anlattı. Python ile yapılan kontrolle durumlar şöyledir (sıra: çiftçi, kurt, keçi, kabak):

```text
(S, S, S, S)  başlangıç
(N, S, N, S)  Move(Goat, North): keçi kuzeye
(S, S, N, S)  Move(Farmer, South): çiftçi tek başına geri döner
(N, N, N, S)  kurt kuzeye
(S, N, S, S)  keçi geri, güneye getirilir
(N, N, S, N)  kabak kuzeye
(S, N, S, N)  çiftçi tek başına geri döner
(N, N, N, N)  keçi kuzeye, hedef
```

Kurt kuzeye götürüldükten sonra çiftçi tek başına dönerse kurt ile keçi aynı yerde kalır. Bu yüzden çiftçi bu kez keçiyi geri getirir: Az önce götürdüğü keçiyi şimdi geri getirmektedir. Sonra kabağı götürür ve en sonunda keçiyi tekrar götürür. Bu, problemin formüle edilmiş halidir.

<!-- BELİRSİZ: Slayttaki çözümün son adımları altyazıda "vs. vs." diye geçildi; son üç adım python ile yapılan genişlik öncelikli aramanın bulduğu 7 adımlık çözümden alındı. -->

## 9. Su Bidonları Problemi

Hoca bu problemin bir filmde de geçtiğini söyledi. Elinizde 3 ve 4 galonluk iki boş bidon ve bir su pompası var. İstenen, 4 galonluk bidona tam 2 galon su koymaktır. Bidonların şekli düzensiz olduğu için göz kararı yapılamaz, ortada bir tartı da yoktur. Elinizde yalnız bunlar vardır ama kesin bir sonuç elde etmeniz gerekir.

### 9.1 Durumların gösterimi

Önce durumlar ifade edilir. Pompadaki su sınırsız olduğu için onu göstermeye gerek yoktur. İki bidondaki su miktarı yeterlidir. Bir durum iki sayıyla gösterilir: $(x, y)$. Burada $x$ 4 galonluk bidondaki, $y$ 3 galonluk bidondaki su miktarıdır.

- Başlangıç durumu: $(0, 0)$, iki bidon da boş.
- Hedef durumu: $(2, n)$. $n$'nin ne olduğu önemsizdir, istenen 4 galonluk bidonda 2 galon olmasıdır.

Örnek durumlar: $(2, 3)$, $(3, 3)$, $(0, 3)$, $(1, 0)$ gibi. $(2, 4)$ ise bir durum değildir, çünkü 3 galonluk bidonda 4 galon su olamaz.

### 9.2 Operatörler

Durumlar tanımlandıktan, başlangıç ve hedef belirlendikten sonra durumlar arası geçişi sağlayan operatörler tanımlanır. Her operatörün bir uygulanma koşulu ve bir dönüşümü vardır (ekrandan, 01:55:00):

```text
1  (x,y) -> (4,y)              if x < 4                 4 galonluk bidonu pompa ile doldur
2  (x,y) -> (x,3)              if y < 3                 3 galonluk bidonu pompa ile doldur
3  (x,y) -> (0,y)              if x > 0                 4 galonluk bidonu yere boşalt
4  (x,y) -> (x,0)              if y > 0                 3 galonluk bidonu yere boşalt
5  (x,y) -> (4, y - (4 - x))   if x + y >= 4 and y > 0  4 galonluk bidon dolana kadar 3 galonluk bidondan su doldur
6  (x,y) -> (x - (3 - y), 3)   if x + y >= 3 and x > 0  3 galonluk bidon dolana kadar 4 galonluk bidondan su doldur
7  (x,y) -> (x + y, 0)         if x + y <= 4 and y > 0  3 galonluk bidondaki suyun tamamını 4 galonluk bidona boşalt
8  (x,y) -> (0, x + y)         if x + y <= 3 and x > 0  4 galonluk bidondaki suyun tamamını 3 galonluk bidona boşalt
```

<!-- BELİRSİZ: 7 ve 8 numaralı operatörlerin slaytı karelerde yok. Tanımları altyazıdaki anlatımdan (01:55:57), koşulları operatörün anlamından yazıldı; hoca koşulu "x artı y dörtten küçük" diye okudu. -->

Hoca koşulların anlamını açıkladı. Birinci operatörde $x < 4$ şartı vardır, çünkü 4 galonluk bidon zaten doluysa onu doldurmanın bir anlamı yoktur. Operatör hiçbir şeyi değiştirmeyecektir. 5 numaralı operatörde 3 galonluk bidondan 4 galonluğa su boşaltılır ve 4 galonluk dolunca durulur. Bunun için $x + y \geq 4$ olmalıdır (yoksa dolana kadar su yoktur) ve 3 galonluk bidonda su olmalıdır ($y > 0$). Sonuçta $x$ 4 olur. 3 galonluktan $4 - x$ kadar su gittiği için $y$ de $y - (4 - x)$ olur.

### 9.3 Örnek çözüm

Amaç, başlangıçtan hedefe götüren operatör dizisini bulmaktır. Slayttaki çözüm adım adım şöyledir (python ile kontrol edildi):

| Adım | Durum $(x, y)$ | Uygulanan operatör | Anlamı |
|---|---|---|---|
| 0 | $(0, 0)$ | 2 | 3 galonluğu pompayla doldur |
| 1 | $(0, 3)$ | 7 | 3 galonluğun tamamını 4 galonluğa boşalt |
| 2 | $(3, 0)$ | 2 | 3 galonluğu tekrar doldur |
| 3 | $(3, 3)$ | 5 | 4 galonluk dolana kadar 3 galonluktan boşalt |
| 4 | $(4, 2)$ | 3 | 4 galonluğu yere boşalt |
| 5 | $(0, 2)$ | 7 | 3 galonluğun tamamını 4 galonluğa boşalt |
| 6 | $(2, 0)$ | | hedef |

$(3, 3)$ durumunda 5 numaralı operatör uygulanınca 4 galonluk bidona 1 galon gider ve dolar. 3 galonlukta 2 galon kalır: $(4, 2)$. Sonra 4 galonluk boşaltılır, kalan 2 galon 4 galonluğa aktarılır ve hedefe ulaşılır.

Bu çözümde 8 operatörün hepsi kullanılmadı. Hepsinin kullanılması da gerekmez. Bu dizi bir çözümdür. Optimal, yani en kısa çözüm olup olmadığı ayrı bir konudur ve ileride tartışılacaktır.

> **Ek bilgi (derste anlatılmadı):** Aynı operatörlerle genişlik öncelikli arama yapıldığında hedefe yine 6 adımda ulaşılır, yani derste gösterilen çözüm de en kısa çözümlerden biridir (python ile kontrol edildi). Aramanın bulduğu diğer 6 adımlık çözüm 1, 6, 4, 8, 1, 6 operatör sırasıdır ve $(2, 3)$ durumunda biter.

Hoca bu noktada aklımıza gelebilecek soruyu da dile getirdi: Operatörleri tanımladık, ama bu sırayı nereden bulacağız? Asıl iş budur. Bu sıraları üreten algoritmalar ilerleyen derslerde görülecektir.

## 10. 8-Puzzle

8-puzzle genelde 15'lik puzzle olarak bilinir. Bir resim 16 parçaya bölünür, bir parçası çıkarılıp yerine boş bir kare konur. Resim karıştırılır ve siz onu orijinal haline getirmeye çalışırsınız.

Slayttaki başlangıç ve hedef durumları (ekrandan, 02:00:00):

```text
S0:            G:
4 3 6          1 2 3
2 1 8          4 5 6
7 _ 5          7 8 _
```

<!-- BELİRSİZ: S0'ın orta satır sağ hücresi karede fare imleciyle kısmen örtülü; geri kalan taşlar 1-7 olduğu için bu hücre 8 olarak yazıldı. -->

### 10.1 Operatörlerin tanımlanması

Hoca, bir taşın kaç farklı şekilde hareket ettirilebileceğini sordu. Cevap 4'tür: sağa, sola, yukarı, aşağı. Operatörleri taşlar üzerinden tanımlarsak ("1'i aşağı çek", "7'yi sağa çek" gibi) 8 taş × 4 yön = 32 operatör olur.

Karmaşıklığı azaltmak için taş hareketleri **boş karenin hareketleri** olarak temsil edilebilir. Herhangi bir durumda boş kareyi hareket ettirmek, ona komşu bir taşı hareket ettirmekle aynı şeydir. Böylece yalnız 4 operatör kalır:

- $L$: boş kare sola
- $R$: boş kare sağa
- $U$: boş kare yukarıya
- $D$: boş kare aşağıya

Bütün operatörlerin maliyeti aynıdır: $C(L) = C(R) = C(U) = C(D) = 1$.

Hoca burada önemli bir noktaya değindi: Bu 4 operatörle $S_0$'dan $G$'ye varabilir miyiz? Varamayabiliriz de. Bir problem size verildi diye mutlaka çözülebilir olduğu bilinmez. Labirent örneğinde başlangıç ile hedef arasındaki her yer kırmızılarla dolu da olabilir.

> **Ek bilgi (derste anlatılmadı):** 8-puzzle'da her başlangıç durumundan hedefe ulaşılamaz. Olası dizilişlerin yalnız yarısından belirli bir hedefe ulaşılabilir. Bu, taşların sıralamasındaki ters çevrimlerin (inversion) sayısının tek ya da çift olmasıyla belirlenir.

### 10.2 Arama ağacı

Slaytta 8-puzzle'ın arama ağacı gösterildi (ekrandan, 02:05:00). Kökteki durumda boş kare ortadadır, bu yüzden 4 hareket de uygulanabilir: Up, Left, Down, Right. Her biri farklı bir çocuk durum üretir. İkinci seviyede, örneğin Up uygulanmış durumda boş kare üst kenarın ortasındadır. Orada üç hareket mümkündür, ama Down uygulanırsa geri dönülür. Tekrarlı durum oluşmaması için şekilde yalnız iki çocuk (Left, Right) gösterilmiştir. Diğer dallarda da aynı şey geçerlidir. Ağaç bu şekilde, her durumda uygulanabilen hamleler bulunarak adım adım genişletilebilir.

Slayttaki değerler: 8-puzzle için ortalama çözüm adım sayısı 22, ortalama dallanma sayısı 2,67'dir. Yani bir durumdan ortalama 2,67 yeni durum çıkar. Bu durumda yaklaşık $2{,}67^{22}$ durum oluşur. Slayta göre bu, tekil olmayan 2,7 milyar durumdur. Bu durumların hepsi farklı değildir, aynı duruma farklı yollardan gidilebilir. Ama 22 adım ilerlendiğinde çok büyük bir ağaçla karşılaşılacağı açıktır.

> **Ders sonrası not:** $2{,}67^{22} \approx 2{,}42 \times 10^9$ çıkar (python ile hesaplandı). Slayttaki 2,7 milyar büyük olasılıkla yuvarlanmış bir değerdir. Mertebe aynıdır.

## 11. Arama ile İlgili Tanımlar

Ders boyunca geçen tanımlar bir arada verildi:

- **Durum uzayı, arama uzayı, arama ağacı (state space, search space, search tree):** Durumları, aralarındaki geçişleri, geçiş parametrelerini ve kısıtları gösteren graf ya da ağaç. Ağaçta bir durumdan diğerine hangi operatörle geçildiği gösterilir. Ağaç ilerledikçe bir yerlerde çözüm bulunur. Amacımız o çözüme hangi yoldan gidileceğini bulmaktır.
- **Operatörler:** Durumlar arası geçişleri sağlar.
- **Başlangıç durumu:** $S_0$.
- **Hedef durumu:** $G$.
- **Maliyet (cost):** Operatörü uygulamanın maliyeti.
- **Çözüm yolu (solution path):** Başlangıç durumundan hedef duruma giden yol.
- **Optimum yol (optimal path):** En düşük maliyetli çözüm yolu. Birden fazla optimum yol olabilir.

## 12. Arama Neden Zor?

Hoca aramanın zorluğunu bir tabloyla gösterdi. Varsayımlar şunlardır:

- Bir durumdan gidilebilecek durum sayısı (dallanma sayısı) 10.
- Saniyede işlenen durum sayısı 1000.
- Bir durumu (düğümü) tutmak için gereken bellek 100 bayt.

Derinlik $d$ olan bir çözüme kadar işlenen durum sayısı $1 + 10 + 10^2 + \dots + 10^d$ olur:

| Çözüm derinliği | İşlenen durum sayısı | Zaman | Bellek |
|---|---|---|---|
| 0 | 1 | 1 milisaniye | 100 bayt |
| 2 | 111 | yaklaşık 0,1 saniye | yaklaşık 11 kilobayt |
| 12 | yaklaşık $10^{12}$ | yaklaşık 35 yıl | yaklaşık 111 terabayt |

Çözüm başlangıçtaysa ($d = 0$) yalnız 1 durum işlenir. $d = 2$ olduğunda $1 + 10 + 100 = 111$ durum işlenir. $d = 12$ olduğunda süre 35 yıla çıkar.

> **Ders sonrası not:** Hoca derinlik 12 için gereken bellek miktarını "111 kilobayt" olarak söyledi. Aynı varsayımlarla $1{,}11 \times 10^{12}$ düğüm × 100 bayt ≈ $1{,}11 \times 10^{14}$ bayt, yani yaklaşık 111 terabayt gerekir. Süre de $1{,}11 \times 10^{12} / 1000$ saniye ≈ 35,2 yıl çıkar (ikisi de python ile hesaplandı).

<!-- BELİRSİZ: Tablonun ara satırları (derinlik 4, 6, 8, 10, 14) karelerde yok ve altyazıda okunmadı; tabloya yalnız derste söylenen satırlar alındı. -->

Sorun şudur: Her seviyede işlenecek durum sayısı bir öncekinin 10 katıdır, yani üstel olarak artar. Saniyede işlenen durum sayısını bin yerine bir milyar, bir trilyon, bir katrilyon yapsanız, süper bilgisayarlar kullansanız bile çözümün derinliği 20 civarına geldiğinde süre yine yüzlerce yıla çıkar.

Dolayısıyla derinlik ne kadar fazlaysa ve dallanma sayısı ne kadar büyükse problemi çözmek o kadar güçleşir. "Güçleşir" derken, çözümü bulmak için gereken kaynak miktarının arttığı kastedilir: daha uzun süre ve daha fazla bellek.

## 13. Arama Stratejileri ve Değerlendirme Ölçütleri

Arama stratejileri (arama algoritmaları), bir durumdan diğerine giderken olası durumlar arasından hangisine gidileceğinin nasıl seçildiğini belirler.

Bir arama stratejisi dört boyutta değerlendirilir:

- **Tamlık (completeness):** Bir çözüm varsa mutlaka bulunur mu? Bazı algoritmalar çözüm olsa bile onu bulamayabilir. Çözüm yoksa zaten yapacak bir şey yoktur. Burada sorulan, çözüm varken onun bulunup bulunmadığıdır.
- **Zaman karmaşıklığı (time complexity):** Aramanın alacağı süre.
- **Hafıza karmaşıklığı (space complexity):** Arama için gereken bellek miktarı.
- **Optimumluk (optimality):** Algoritmanın bulduğu **ilk** çözümün en düşük maliyetli çözüm olması.

> **Hocanın vurgusu:** Bir algoritmanın optimum olduğunu söylüyorsanız, o algoritmanın ilk bulduğu çözümün optimum olduğunu söylüyorsunuz demektir.

Zaman ve hafıza karmaşıklığı ölçümlerinde kullanılan kavramlar:

- $b$: dallanma sayısı (branching factor).
- $d$: en az maliyetli çözümün derinliği.
- $m$: arama uzayının en büyük derinliği.

### 13.1 Kör arama algoritmaları

İlk arama türü kör aramadır. Slaytta bu türün diğer adları da verilir: kör, mekanik, bilgisiz (blind, uninformed). Altında altı kör arama algoritması vardır:

- Enlemesine arama (Breadth-first search)
- Düşük maliyetli arama (Uniform cost search)
- Derinlemesine arama (Depth-first search)
- Sınırlı derinlikli arama (Depth-limited search)
- Artan derinlikli arama (Iterative deepening search)
- Çift yönlü arama (Bidirectional search)

Bu algoritmaların neye "kör" olduğu ilerleyen derslerde görülecektir.

## 14. Enlemesine Arama (Breadth-First Search)

### 14.1 Temel fikir

Slayttaki ana noktalar şunlardır (ekrandan, 02:15:00):

- Ağaç / durumlar en başta elimizde yoktur, zaman içinde oluşur.
- Çözüm bir durum sırasıdır, durum açma sırası da bir sıradır, ama bunlar birbirinden farklı şeylerdir.
- Enlemesine aramayı gerçekleştirmek için kuyruk kullanılır: ilk giren ilk çıkar (FIFO).

Önce bütün ağacı oluşturup sonra onun üzerinde arama yapmak etkili bir strateji değildir. Çünkü ağacın ne kadar büyük olacağını, derinliğin ne kadar olacağını baştan bilmezsiniz. Bu yüzden ağacın arama algoritması tarafından dinamik olarak, zaman içinde oluşturulması çok daha mantıklıdır. Hocaya göre ağacı en baştan üreten bir algoritma yoktur. Veri yapısı olarak bir ağaç tutmak da şart değildir.

Enlemesine arama her zaman **köke en yakın** açılmamış düğümü açar. Başlangıçta kök vardır. Kökten gidilebilecek iki durum üretilir. Bunlardan ilki açılır ve ondan gidilebilecek durumlar üretilir. Sonra ikincisi açılır. Daha sonra bir alt seviyedekiler soldan sağa açılır. Slayttaki numaralı şekilde açılma sırası 1, 2, 3, 4, 5 diye gider. Sıradakiler 6 ve 7 olacaktır. Daha derindeki bir düğümün, daha sığdaki bir düğümden önce açılma ihtimali yoktur.

### 14.2 Algoritma

Hocanın anlattığı algoritma şöyledir:

```text
kuyruk <- [kök durum]
bulundu <- false
while kuyruk boş değil and bulundu = false:
    n <- kuyruğun başındaki durumu çek
    if n hedef durum ise:
        bulundu <- true
    else:
        n'den gidilebilecek tüm durumları kuyruğun sonuna ekle
```

Bir durumun hedef olup olmadığı anlaşılabilir, çünkü başlangıç ve hedef durumları bilinir. Bilinmeyen, aradaki yoldur. Örnekte önce 1 kuyruğa atılır ve çekilir. 1'den gidilebilecek 2 ve 3 kuyruğa eklenir. Sonra 2 çekilir ve onun çocukları eklenir. Sonra 3 çekilir ve onun çocukları eklenir. Sonra 4, sonra 5, sonra 6 çekilir ve süreç böyle ilerler.

### 14.3 Analiz

- **Tam mı?** Dallanma sayısı $b$ sonsuzsa tam olması mümkün değildir. $b$ sonluysa evet. Ağacın içinde bir yerde bir çözüm varsa ve algoritmaya yeterince zaman verilirse, o çözüme mutlaka ulaşır.
- **Zaman:** $1 + b + b^2 + b^3 + \dots + b^d = O(b^d)$. Son terim, kendisinden önceki bütün terimlerin toplamından büyük olduğu için baskındır. Öncekilerin büyük O gösteriminde etkisi yoktur.
- **Hafıza:** $O(b^d)$. Her düğüm hafızada tutulur. Burada kastedilen kuyruğun büyüklüğüdür.
- **Optimum mu?** Her adımın maliyeti eşitse evet. Algoritma her zaman köke daha yakın olanları önce seçtiği için, sığ bir seviyede çözüm varken daha derindeki, daha fazla maliyetli bir çözümü önce bulmaz. Ama bu, operatörlerin (örneğin sağa ya da sola gitmenin) maliyetleri birbirine eşitse geçerlidir.

> **Hocanın vurgusu:** Enlemesine aramada hafıza, zamandan daha büyük bir problemdir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:18:20): Tam eşlemeli refleksif bir ajanın (durum → hareket tablosuyla çalışan) problemi nedir ve nasıl çözülebilir?

> **Cevap (derste verildi):** Gelen girdiye tam uyan bir satır tabloda olmayabilir. Çözüm, tablonun bütün olası durumları kapsamasıdır. Durum sayısı çok büyükse bu mümkün olmaz. O zaman yalnız en sık karşılaşılan durumlar için satır yazılır, geri kalan bütün durumlara tek bir hareket verilir ya da yaklaşık eşlemeye geçilir.

**Soru 2** (derste sözlü, 00:21:02): Satranç oynayan bir bilgisayar için tahtanın son hali en iyi hamleyi yapmaya yeter mi? Borsada alım satım yapan bir sistem için son değer yeter mi?

> **Cevap (derste verildi):** Satrançta son tahta yeterlidir, önceki hallere ihtiyaç yoktur. Borsa sisteminde ise çalışma anında tek bir değer yetmez, trendi görmek için bir pencere içindeki geçmiş değerlere bakmak gerekir. Bu yüzden borsa sistemi hafızalı olmalıdır.

**Soru 3** (derste sözlü, 00:25:40): Refleksif tam eşleme, yaklaşık eşleme, hafızalı, hafızasız, kendi öğrenen, öğretilen, öğrenimi hep süren ve sürmeyen ajanlara birer örnek bulun.

> **Cevap (derste verilen örneklerden):** Tam eşleme: hesap makinesi, telefon alarmı. Yaklaşık eşleme: ELIZA tarzı botlar, hayvan resmi sınıflandırıcı. Hafızalı: öneri sistemleri, kendi haritasını çıkaran robot süpürge. Hafızasız: yüz tanıma, maske tespiti. Kendi öğrenen: etiketli veriyle eğitilen sınıflandırıcı, pekiştirmeli öğrenmeyle labirent çözen sistem. Öğretilen: kural tabanlı uzman sistem, kuralları koda gömülü oyun yapay zekası. Öğrenimi hep süren: her maçtan sonra kendini yeniden eğiten satranç programı. Öğrenimi sürmeyen: bir kez eğitilip test zamanında güncellenmeyen görüntü sınıflandırıcı.

**Soru 4** (derste sözlü, 01:37:43): Ajanın, içinde çalıştığı ortamın tamamını sensörleriyle algılayabildiği bir örnek verin. Satranç ve okey için ortam tam gözlenebilir mi?

> **Cevap (derste verildi):** Satranç motoru için ortam tamamen gözlenebilirdir. Okey oynayan bir ajan için ortam kısmen gözlenebilirdir, çünkü rakiplerin eli görülemez. Bir öğrencinin önerdiği, labirente tepeden bakıp aşağıdaki araca yol gösteren drone da tam gözlenebilir ortama örnek olarak kabul edildi.

**Soru 5** (derste sözlü, 01:47:14): Çiftçi, kurt, keçi ve kabak probleminde her nesnenin nehrin kuzeyinde ya da güneyinde olduğu kodlanırsa kaç olası durum vardır?

> **Cevap (derste verildi):** 4 nesne vardır ve her biri 2 yerde olabilir: $2^4 = 16$ durum.

**Soru 6** (ekrandan, 01:55:00): 4 ve 3 galonluk iki boş bidon ve sınırsız bir pompa ile 4 galonluk bidona tam 2 galon su nasıl konur? Durumları ve operatörleri tanımlayıp bir çözüm verin.

> **Cevap (derste verildi):** Durum $(x, y)$, başlangıç $(0, 0)$, hedef $(2, n)$. Operatörler Bölüm 9.2'deki 8 kuraldır. Bir çözüm: $(0,0) \xrightarrow{2} (0,3) \xrightarrow{7} (3,0) \xrightarrow{2} (3,3) \xrightarrow{5} (4,2) \xrightarrow{3} (0,2) \xrightarrow{7} (2,0)$.

**Soru 7** (derste sözlü, 02:00:00): 8-puzzle'da bir taş kaç farklı şekilde hareket ettirilebilir? Operatörler taşlar üzerinden tanımlanırsa kaç operatör olur? Bu sayı nasıl azaltılabilir?

> **Cevap (derste verildi):** Bir taş 4 yönde hareket edebilir. 8 taş için $8 \times 4 = 32$ operatör olur. Taşlar yerine boş kare hareket ettiriliyormuş gibi düşünülürse yalnız 4 operatör ($L, R, U, D$) kalır.

**Soru 8** (ekrandan, 02:05:00): Dallanma sayısı 10, saniyede 1000 durum işlenen ve düğüm başına 100 bayt bellek gereken bir aramada, çözüm derinliği 2 ise kaç durum işlenir, ne kadar sürer ve ne kadar bellek gerekir?

> **Cevap (derste verildi):** $1 + 10 + 100 = 111$ durum işlenir. Süre $111 / 1000 \approx 0{,}1$ saniye, bellek $111 \times 100 = 11\,100$ bayt, yani yaklaşık 11 kilobayttır.

## Dersin Toparlaması

Ders, zekayı ölçmeye dair iki görüşün (çıktıya bakan fonksiyonellik ve sürece bakan yaklaşım) kısa bir tekrarıyla başladı ve rasyonel ajan kavramına geçti. Bir ajan, sensörleriyle ortamı algılayan ve aktüatörleriyle ortama etki eden bir sistemdir. Asıl soru, ikisinin arasındaki eşlemenin nasıl kurulacağıdır. Ajanlar tam ya da yaklaşık eşleme, hafızalı ya da hafızasız olma, kendi öğrenen ya da öğretilen olma ve öğreniminin sürüp sürmemesine göre sınıflandırıldı. Grup çalışmasında bu ayrımların, özellikle de "öğretilen" ve "öğrenimi hep süren" kavramlarının neye göre yapıldığı örnekler üzerinden netleştirildi. Ardından ajan tasarımında PEAS parametreleri ve ortamların özellikleri anlatıldı. Gerçek dünyanın bu özelliklerin hepsinde en zor tarafta olduğu vurgulandı.

Dersin ikinci yarısında problemlerin arama problemi olarak nasıl formüle edileceği görüldü: durumların gösterimi, başlangıç ve hedef durumları ve ön koşullarıyla birlikte operatörler. Çiftçi problemi, su bidonları ve 8-puzzle bu formülasyonun örnekleriydi. Aramanın, derinlik ve dallanma sayısıyla üstel olarak büyüdüğü için zor olduğu gösterildi. Arama stratejilerini değerlendirmek için tamlık, zaman, hafıza ve optimumluk ölçütleri tanımlandı. Kör arama algoritmalarının ilki olan enlemesine arama ve analizi anlatıldı. Sonraki derste diğer kör arama algoritmalarına (düşük maliyetli, derinlemesine, sınırlı derinlikli, artan derinlikli ve çift yönlü arama) geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
