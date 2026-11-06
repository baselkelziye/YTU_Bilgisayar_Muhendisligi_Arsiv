# Ders 10 Genişletilmiş Notu: Proje Önerisi Sunumları I: Sağlıkta Yapay Zekâ, Blok Zincir Diploma ve Mobil Robotlar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Yapısı ve Sunuma Hazırlık
- 2. 1. Sunum: COVID-19 Tanısında Derin Öğrenmenin Tarafsızlığı
- 3. Soru-Cevap Neden Sunumun Parçasıdır?
- 4. 2. Sunum: Biyomedikal Sensörlerle Anomali Tespiti ve Erken Uyarı
- 5. 3. Sunum: Görme Engelliler İçin Giyilebilir Asistan
- 6. 4. Sunum: Federe Öğrenme ile Sağlık Verileri
- 7. 5. Sunum: Blok Zincir Tabanlı Dijital Diploma
- 8. 6. Sunum: Deprem Enkazında Arama Kurtarma Robotu
- 9. 7. Sunum: Mobil Robotlar İçin Görüntü Tabanlı Konum Belirleme
- 10. 8. Sunum: Yeniden Kimlik Tespiti
- 11. Hocanın Genel Geri Bildirimleri

## 1. Dersin Yapısı ve Sunuma Hazırlık

Bu derste konu anlatımı yoktur. Ders, öğrencilerin hazırladığı araştırma projesi önerilerinin sunulduğu haftaların ilkidir. Öneriler TÜBİTAK 1002 Hızlı Destek Programı başvuru formuna göre hazırlanmıştır. Bu yüzden sunumların çoğu aynı iskeleti izler: konunun önemi ve özgün değeri, amaç ve hedefler, yöntem, iş paketleri, risk yönetimi, çıktılar ve yaygın etki, bütçe. Bu derste sekiz sunum yapılmıştır.

Hoca sunumlara başlamadan önce iki noktayı hatırlattı. İkisi de sunuma hazırlığın bir parçasıdır.

- **Kamera:** Sunum yapan kişinin kamerası açık olmalıdır. Hoca bunu önceden söylediğini ve sunuma hazırlığın bir parçası saydığını belirtti.
- **Süre:** Her sunumun süresi 10 dakikadır. Hoca kimseye sunum sırasında "tamam, yeter, bitti" demek istemediğini söyledi. Sunan kişinin süresine kendisinin sığabilmesi gerekir. Sunum sayısı fazla olduğu için bu yıl süre biraz sıkışmıştır.

> **Hocanın vurgusu:** "Sunum sürenize sığabiliyor olmanız lazım." Hoca süreye uymayı sunum işinin bir parçası saydığını özellikle belirtti.

## 2. 1. Sunum: COVID-19 Tanısında Derin Öğrenmenin Tarafsızlığı

### 2.1 Konu ve Özgün Değer

Bir grup, COVID-19 tanısında kullanılan derin öğrenme yöntemlerinin tarafsızlığını inceleyen bir proje önerdi. Grubun çıkış noktası şudur: Yapay zekânın sağlıkta en yaygın kullanımı hastalık teşhis sistemleridir. Doğru teşhis, tedavinin başarısı için önemlidir ve hastanın hayatının geri kalanını da etkiler. Bu yüzden yapay zekâ ile alınan kararlar şeffaf, açıklanabilir ve denetlenebilir olmalı, adil olmalı ve yanlılık (bias) içermemelidir.

Grup yanlılığın iki tanımını verdi. Birincisi, bir fikir veya şeye karşı orantısız eğilim ya da önyargıdır. İkincisi, bir öğrenme algoritmasındaki hatalı kararlardan kaynaklanan hatadır. Grubun vardığı sonuç, iyi bir model isteniyorsa önce yanlılığın ne olduğunun anlaşılması ve varlığının kabul edilmesi gerektiğidir. Proje, veri setinden kaynaklanan yanlılıkları farklı senaryolarla denemeyi ve önyargısız bir model için gereken özellikleri belirlemeyi hedefler.

> **Ders sonrası not:** Grup yanlılığın tanımlarını Wikipedia'dan verdi. Akademik bir başvuruda tanımlar büyük olasılıkla hakemli kaynaklara dayandırılmalıdır.

### 2.2 Amaç

Grubun motivasyonu, bilgisayar destekli teşhis sistemlerine ihtiyacın artması ve bu sistemlerin denetlenebilir olmasının da önem kazanmasıdır. Amaçlar şöyle sıralandı:

- COVID-19 teşhisinde yanlılık oluşturmayacak bir veri seti elde etmek.
- Veri setinde değişiklik yaparak farklı sonuçları incelemek.
- Farklı denemelerle farklı metrik sonuçları almak.
- Veri setinin meta verisine (cinsiyet, yaş) göre sonuçların nasıl değiştiğini incelemek.
- Literatürde başarı elde etmiş önceden eğitilmiş derin sinir ağlarının sonuçlarını karşılaştırmak.

### 2.3 Yöntem

Sistemin akışı şöyledir. Kullanıcı, web kazıma (web scraping) ile toplanmış veri setini ya da kendi verisini sisteme yükler. Sistem, verinin meta verilere göre dağılımını gösterir. Kullanıcı bu meta verilerle veri analizi yapar ve bir meta verinin yanlılığa yol açıp açmayacağını inceler. Sonra literatürdeki modellerle, meta verilere göre farklı oranlarda oluşturulmuş eğitim setleri üzerinde deney yapar.

Grubun verdiği örnek cinsiyettir. Model yalnızca erkek hastaların görüntüleriyle eğitilir. Sonra biri kadın, biri erkek hastaların görüntülerinden oluşan iki ayrı kümeyle test edilir. İki test sonucu karşılaştırılarak cinsiyet bilgisinin modelde yanlılık oluşturup oluşturmadığı görülür. Grup burada önemli bir ayrımı özellikle belirtti: Cinsiyet görüntünün bir özniteliği (feature) değil, görüntüye ait bir meta veridir.

### 2.4 İş Paketleri

- **1. iş paketi, veri toplama ve veri tabanı:** Veri, literatürde kullanılmış kaynaklardan web kazıma ile toplanır. Kullanıcının kendi verisini kullanabileceği bir arayüz de sağlanır.
- **2. iş paketi, veri analizi modülü:** Eğitim setindeki bazı özellikler yanlılığa yol açabilir. Bu, verinin meta verilere göre dağılımı incelenerek tespit edilir. Dengesizlik potansiyel bir yanlılıktır. Örnek olarak bir COVID-19 verisindeki 166 erkek, 134 kadın dağılımı verildi. Bu dağılımın sonuçlara etkisi araştırılır ve en iyi oran belirlenir. Farklılıklar iki boyutlu bir uzayda gösterilir. Öznitelik çıkarımından sonra kümeleme algoritmalarıyla da fark gözlenebilir.
- **3. iş paketi, derin öğrenme modelleri ve performans metrikleri:** COVID-19 çalışmalarında veri setinin küçüklüğü sık görülen bir sorundur. Bu yüzden çok daha büyük verilerle önceden eğitilmiş mimariler kullanılır. Grup altı mimari kullanır. Hangi meta verinin, hangi oranda sorun oluşturduğu senaryolarla analiz edilir. Metrikler doğruluk (accuracy), eğri altında kalan alan (AUC), kesinlik (precision) ve geri çağırmadır (recall). Grup, cinsiyet yanlılığı açısından ve sağlık hizmetleri için son ikisinin önemli olduğunu söyledi.
- **4. iş paketi, kullanıcı arayüzü:** Kullanıcı veri yükler, meta verilere göre analiz yapar, oran belirleyerek deney kurar, model parametrelerine karar verir ve sonuçları gözler.

<!-- BELİRSİZ: Altı mimarinin adları yalnızca slaytta; altyazıda geçmiyor. -->

### 2.5 Risk ve Beklenen Etki

Grup projede çok fazla risk görmüyor. Belirttiği risk, analize uygun veri setinin toplama aşamasında elde edilememesidir. Çözüm olarak başka kaynaklardan kazıma yapılabileceğini söyledi.

Bilimsel çıktı, teşhis sistemlerinde yanlılığın etkilerini ve yapay zekâya güveni artıran yolları inceleyen bir çalışmadır. Sosyal çıktı olarak, alanda henüz deneyimli olmayan kişiler de parametreleri değiştirerek başarıyı etkileyen şeyleri görebilir. Yanlılığın açıklanması ve önlenmesiyle ilgilenen araştırmacılara da fikir sunulur. Proje bir yüksek lisans öğrencisine de deneyim kazandırır.

Hoca, anlatımı birçok açıdan iyi bulduğunu, bir iki küçük sıkıntı dışında genel olarak olumlu olduğunu söyledi.

## 3. Soru-Cevap Neden Sunumun Parçasıdır?

İlk sunumdan sonra hoca soru sordu, kimse cevap vermedi. Bunun üzerine soru-cevabın neden önemli olduğunu açıkladı. Soru gelmezse sunanların konuya ne kadar hâkim olduğu görülemez. Sessizlik yalnız sunanlara değil, dinleyenlere de olumsuz yansır. "Kimse kimseye soru sormasın" tavrının kimseye faydası yoktur. Hoca bu kısmın her yıl özellikle atlandığını, bu yüzden üzerinde durduğunu söyledi.

> **Hocanın vurgusu:** Bir sunumda soru-cevap süsleme değildir. Sunan kişinin konusuna hâkimiyeti en iyi sorulara verdiği cevaplarda anlaşılır. Dinleyicinin de bir sorumluluğu vardır: dinlemek ve soru sormak.

## 4. 2. Sunum: Biyomedikal Sensörlerle Anomali Tespiti ve Erken Uyarı

### 4.1 Konu ve Motivasyon

Bir grup, biyomedikal sensörler için derin öğrenme tabanlı bir anomali tespit ve erken uyarı sistemi önerdi. Hedef, yoğun bakımdaki ve gözetim altındaki hastaların 7/24 takibini kolaylaştıran, gerçek zamanlı veri alan ve anomalileri yüksek başarımla bulan bir sistemdir.

Grubun gerekçesi şudur: COVID-19 ile hastaneye yatış oranı ve personel ihtiyacı çok arttı. Personelin yükünü azaltacak otomatik sistemler gerekir. Bunlar IoT ve derin öğrenme ile kurulacaktır. Motivasyon olarak dünyada 1,7 milyon kişinin hatalı ölçümden etkilendiği, bunların 83.000'inin ölümle sonuçlandığı söylendi. Bu rakamın kaynağı altyazıda geçmiyor.

### 4.2 Literatür ve Özgünlük

Tıpta sensör kullanımı analog ve manuel sensörlerle başlamış, sonra çok ilerlemiştir. Kablosuz sensör ağları ve vücut sensör ağları ile hastalar izlenir. Giyilebilir sensörlerden gelen veri bulut tabanlı sistemlerde saklanır ve doktorlar inceler. Grubun literatür özeti şudur: Medikal sensörlerden toplanan veri IoT cihazlarıyla merkezi bir yönetim sistemine taşınır, gerisi doktorun incelemesine kalır.

Projenin özgünlüğü, bu zincire bir katman eklemektir. Merkezi sistemdeki veriler üzerinde gerçek zamanlı anomali tespiti yapılacaktır. Bunun için LSTM tabanlı, denetimsiz (unsupervised) bir model geliştirilecek ve zaman serilerindeki anomaliler anlık olarak bulunacaktır. Buna paralel olarak geliştirilecek sensör ve iletim donanımı, herhangi bir medikal cihazdan bağımsız çalışacaktır.

> **Ek bilgi (derste anlatılmadı):** LSTM ile denetimsiz anomali tespitinde genellikle etiket kullanılmaz. Model, normal zaman serisinin bir sonraki değerini tahmin etmeyi ya da seriyi yeniden oluşturmayı öğrenir. Gerçek değerle modelin çıktısı arasındaki hata belirli bir eşiği aşarsa o nokta anomali sayılır. Bu yüzden modelin başarısı, eğitim verisinin gerçekten "normal" davranışı temsil etmesine ve eşiğin iyi seçilmesine bağlıdır.

### 4.3 Amaç ve Başarı Kriterleri

Amaç, periyodik hasta takibinin kalitesini artırmak, 7/24 kesintisiz takip sağlamak, tedaviyi daha güvenli yapmak ve sağlık personelinin iş gücünü doğru yere yönlendirmektir. Grup dört başarı kriteri verdi:

- Sensörlerle veriyi ölçen bir donanım geliştirmek.
- Bu verileri toplayan bir merkezi yönetim sistemi geliştirmek.
- Bu büyük veriyi kullanan LSTM tabanlı anomali tespit algoritmaları geliştirmek.
- Sonuçları akademik ortamda paylaşılabilir hâle getirmek.

### 4.4 Yöntem ve İş Paketleri

Yöntem üç bileşenden oluşur:

- **Sensör donanımı:** Raspberry Pi ve Arduino gibi mikrodenetleyicilerle ateş ve kan basıncı gibi ölçümleri yapan sensörlerden oluşur. Bunlar medikal cihazlara bağlanan IoT probları olur ve veriyi merkeze iletir.
- **Merkezi veri yönetimi yazılımı:** Sağlık personeline bir gösterge paneli (dashboard) sağlar. Anomali tespit sonuçları da burada görünür.
- **Anomali tespit sistemi:** LSTM yapısında ve denetimsizdir. Herhangi bir sensörden gelen veride anomaliyi otomatik bulur.

İş paketleri ise hastane ve personelle sürekli görüşmeleri içeren araştırma çalışması, medikal cihazdan bağımsız donanım geliştirme, merkezi yönetim yazılımı, anomali tespit yazılımı ve hastanelere entegrasyondur.

### 4.5 Riskler

Grup üç risk belirledi ve her birine bir önlem yazdı:

- **Tedarik:** Sistem donanıma bağlıdır. Mikrodenetleyici ve sensör probları bulunamayabilir. Önlem, parça tedarikçisi firmalarla görüşmektir.
- **Yazılımsal ve siber güvenlik:** Önlem, sistemi hastane içi yerel ağda çalıştırmaktır. Her sensör ve merkezi yönetim sistemi bu ağın içinde olur.
- **Kullanıcı reddi:** Bazı hastalar veya yakınları sistemi kullanmak istemeyebilir. Önlem, kriterleri sağlayan daha çok hastane ve poliklinikle iletişime geçip testleri çok sayıda hastada yapmaktır.

> **Ders sonrası not:** Sağlık verisi işleyen bu projede etik kurul onayı ve KVKK uyumu büyük olasılıkla ayrı bir iş paketi veya risk olarak yazılmalıdır. Sunumda bu kalem anılmadı.

### 4.6 Bütçe ve Beklenen Etki

Teçhizat listesinde Raspberry Pi, Arduino, oksimetre, kalp atış sensörü, kızılötesi termometre, kasa basmak için bir 3B yazıcı ve RTX 2080 Ti GPU'lu bir sunucu vardır. Bütçe şöyle verildi:

- Teçhizat: 28.500 TL.
- Sarf (5 kg filament): 500 TL.
- Bursiyer: 14.700 TL.
- Söylenen toplam: 43.800 TL.

> **Ders sonrası not:** Grup toplamı 43.800 TL dedi. Sayılan kalemlerin toplamı $28.500 + 500 + 14.700 = 43.700$ TL'dir. Aradaki 100 TL'lik fark altyazıdan açıklanamıyor. Bütçe tablolarında kalemlerin toplamı başlık rakamıyla tutmalıdır.

Projede iki yüksek lisans öğrencisi 12 ay, bir lisans öğrencisi de web uygulaması için 2 ay çalışır. Ayrıca medikal cihazlar konusunda danışmanlık hizmeti alınır.

Bilimsel çıktı, International Conference on Medical Devices konferansında bir bildiridir. Ticari ve sosyal çıktı, şirkete dönüşebilecek bir üründür. Araştırmacı yetiştirme de çıktılar arasındadır. Etkiler sağlık sisteminin kalitesinin artması, ülkeye akademik katkı, şirketleşme ve istihdam, ithalatın azalmasıyla ekonomik katkı olarak sıralandı.

**Soru:** (Hoca sordu) "10 dakikanız olacağını biliyorsunuz. 20 slayt sizce uygun bir sayı mı?" **Cevap:** Grup, slaytların sonlara doğru biraz fazla olduğunun farkında olduğunu söyledi. Hoca "sadece o farkında mısınız?" diye sordu. Slayt sayısı konusuna ders sonunda geri döndü.

## 5. 3. Sunum: Görme Engelliler İçin Giyilebilir Asistan

### 5.1 Konu ve Motivasyon

Bir grup, projenin sosyal bir boyutu da olsun istediğini söyleyerek görme engellilerin hayatını kolaylaştıran "Rehber Pay" adlı giyilebilir bir asistan önerdi. Grup önce görme engelliliği tanımladı: Tüm düzeltmelere rağmen görme keskinliği 1/10 veya daha az olan, ya da görme alanı 20 dereceyi geçmeyen bireyler görme engelli sayılır.

Grubun verdiği rakamlar şunlardır: Dünya Sağlık Örgütü'nün 2010 çalışmasına göre dünyada 285 milyon görme engelli vardır, 39 milyonu tamamen kördür. Aile, Çalışma ve Sosyal Hizmetler Bakanlığı'nın 2011 çalışmasına göre Türkiye'de 1 milyon 39 bin görme engelli yaşamaktadır.

Mevcut çözümler olarak mobil uygulamalar ve giyilebilir cihazlar anıldı. Japonya'da hazırlanan OTON GLASS prototip aşamasında kalmıştır; gözlükteki kamera, düğmeye basınca önündeki dokümanı sesli okur. eSight 4 cihazı doküman okur, nesne tanır ve sesli asistanla arama yapar. İki ürün de Türkiye'de satılmaz, eSight 4'ün internetteki fiyatı 5950 dolardır. Grup bu yüzden düşük maliyetli bir prototip önerdi.

### 5.2 Araştırma Sorusu ve Amaç

Araştırma sorusu şudur: Görme engelli bireylerin, tek kart bilgisayar, ona uyumlu kamera, kulaklık ve internet erişimi kullanarak çevresindeki insanlara bağımlılığı azaltılabilir mi? Amaç, yazılı yayınlara erişimi artırmak, bağımlılığı azaltmak ve yaşam kalitesini yükseltmektir. Bunun için sesli komutla çalışan dört mod planlanır: doküman okuma, yürüyüş, renk tespiti ve alışveriş.

### 5.3 İş Paketleri

Proje 12 ay sürer ve 6 iş paketi vardır. Ortalama her paket 2 ay alır.

**1. iş paketi, çalışma ortamı:** Çözüm Raspberry Pi 4 üzerinde, Raspberry Pi OS ile çalışır. 8 megapiksellik kamera modülü, 3B yazıcıda basılan gözlüğe takılır. Python ve OpenCV kurulur. Kaynak kod Bitbucket'ta sürümlenir, belgeler Confluence'ta tutulur.

**2. iş paketi, sesli komut:** Açık kaynak Jasper platformu kullanılır. Kullanıcı "Rehber Pay" dediğinde uygulama devreye girer ve ana menüdeki modları sesli sayar. Kullanıcı modun adını tekrar edince o moda girilir. "Dur" komutu moddan çıkarıp ana menüye döndürür. Ana menüde "kapat" denirse uygulama uyku moduna geçer. Yeniden uyandırmak için yine "Rehber Pay" demek yeter.

**3. iş paketi, doküman okuma:** Gözlükteki kamera dokümanın fotoğrafını çeker. Doküman net taranamıyorsa 30 saniyede bir "doküman bulunamadı" uyarısı verilir. Tarandıysa Tesseract OCR motoru metni çıkarır, metinden sese (text-to-speech) dönüştürme ile okunur.

**4. iş paketi, yürüyüş modu:** Görme engellilerin kullandığı bastona bir QR kod yapıştırılır. Kişi yürürken bir nesneyi tanımak istediğinde, önce o bölgenin taranması gerekir. Bu tarama QR kodla tetiklenir: QR kod okununca gözlükteki kamera görüntü çeker, görüntü YOLO mimarisi ve OpenCV ile işlenir. Nesne bulunduysa adı söylenir, bulunamadıysa "nesne tanımlanamadı" denir. QR kod okunamazsa, okunana kadar uyarı verilir. QR kodu okumak için ZBar kütüphanesi kullanılır.

**5. iş paketi, renk tespiti:** Grup, görme engelli biri için rengin neden önemli olduğunu kendisi sordu. Cevabı şuydu: Örneğin çamaşır yıkarken giysilerin rengi önem kazanır. Kişi "renk tespiti" dediğinde kamera elindeki nesnenin fotoğrafını çeker ve rengi söylenir.

> **Ders sonrası not:** Grup "yedi ana renk" dedi, ama saydığı renkler sarı, mavi, mor, lacivert, yeşil, kırmızı, beyaz ve siyah olmak üzere sekiz tanedir. Listenin doğru sayısı raporda netleştirilmelidir.

<!-- BELİRSİZ: Renk modundaki "boyut algılaması" ve "boyutun dışına girerse arka tarafta başka mimariler devreye girer" açıklaması altyazıda net değil. -->

**6. iş paketi, alışveriş:** Amaç kâğıt paraları tanımaktır. İstanbul Teknik Üniversitesi'nde hazırlanmış bir veri seti ve çalışma kullanılır. DenseNet-121 mimarisiyle 5, 10, 20, 50, 100 ve 200 TL'lik kâğıt paralar tanınıp söylenir.

### 5.4 Risk Yönetimi

Grup riskleri paketlere bağlayarak sıraladı:

- **Hava şartları:** Gözlük ve elektronik yapı bozulabilir. Önlem, 3B yazıcıda dayanıklı bir filament kullanmaktır.
- **Gürültü:** Gürültülü ortamda sesli komut anlaşılamayabilir. Önlem, eğitim verisine gürültülü sesler eklemektir.
- **Telaffuz:** Komutlar doğru söylenmeyebilir. Önlem, sık söylenen biçimleri telaffuz sözlüklerine eklemektir.
- **Aydınlatma ve doküman kalitesi:** Görüntü çok karanlık veya parlak çıkabilir, harfler seçilemeyebilir. Önlem, yoğunluk dönüşümü (intensity transformation) gibi görüntü işleme teknikleridir.
- **QR kodun okunamaması:** Kullanıcıya bastonu doğru tutması için yönlendirme yapılır.
- **Yanlış sınıflandırma:** Modelin güven oranı kullanıcıya söylenir. Grubun örneği: "%100 bu gösterdiğin şey şemsiye" ile "%20 bu gösterdiğin şey şemsiye" aynı şey değildir. Kullanıcı düşük oranı duyunca sonucun güvenilmez olduğunu bilir.
- **Karışık renkler:** Tek renk olmadığı kullanıcıya bildirilir.
- **Yıpranmış para:** Paranın doğru tahmin edilemediği kullanıcıya bildirilir.

<!-- BELİRSİZ: Dayanıklı filamentin adı altyazıda "kopolistar" diye geçiyor; büyük olasılıkla kopolyester, slayttan doğrulanamadı. -->

### 5.5 Beklenen Etki ve Bütçe

Grup, sesin metne ve metnin sese dönüştürülmesi, görüntü işleme ve karakter tanıma birlikte kullanıldığı için özellikle Türkçe literatüre katkı beklediğini söyledi. Ekonomik olarak prototip ürüne dönüşebilir, patent alınabilir, seri üretilebilir. Dört modülün bir arada olduğu bir çalışmaya rastlamadıklarını, farklı dil desteğiyle yurt dışına da satılabileceğini belirttiler. Toplumsal etki, görme engellilerin kendi dokümanını okuması, yürürken başkasına daha az ihtiyaç duyması ve parayla ilgili dolandırılma riskinin azalmasıdır. Ulusal güvenlik başlığında grup, doküman okumada kişisel bilgilerin dışarı çıkabileceğini bir risk olarak andı. Bütçe olarak TÜBİTAK'tan yaklaşık 5400 TL beklendiği, bunun teçhizat ve sarf giderlerini kapsadığı söylendi. Bu sunumun ardından soru gelmedi.

<!-- BELİRSİZ: Ulusal güvenlik cümlesindeki "hazır hafif kullanarak" ifadesi altyazıda bozuk; hazır bir servisin kullanılmasından söz ediliyor olabilir. -->

## 6. 4. Sunum: Federe Öğrenme ile Sağlık Verileri

### 6.1 Konu ve Problem

Bir grup, federe öğrenmenin (federated learning) mahremiyet gerektiren sağlık verilerine uygulanmasını önerdi. Grubun anlatımı veri probleminden başlar. Telefonlar, akıllı arabalar, IoT cihazları, sosyal medya ve uygulamalar her gün çok büyük miktarda veri üretir. Ses tanıma, doğal dil işleme, tavsiye sistemleri ve görüntü işleme uygulamaları bu veriyle eğitilir. Bunun için verinin toplanması ve etiketlenmesi gerekir.

Verilerin kötüye kullanımı ve güvenlik tehditleri yüzünden devletler kişisel verileri koruma kanunları çıkardı; Türkiye'de bu KVKK'dır. Kurumlar veri paylaşmamaya başladı. Grup bunu "veri, yapay zekâ endüstrisinin petrolü hâline geldi" sözüyle anlattı. Sağlık verisi mahrem olduğu için hastaneler paylaşmaz, modeller de az veriyle eğitildiği için iyi başarım veremez.

### 6.2 Çözüm, Amaç ve Başarı Kriterleri

Federe öğrenmede veri paylaşılmaz. Herkesin verisi kendi yerel sunucusunda kalır ve model orada eğitilir. Merkezde yalnızca ağırlıklar (weights) tutulur. Böylece taraflar arasında bilgi alışverişi olur, ama veri alışverişi olmaz.

Projenin amacı, hastanelerin hasta verilerini paylaşmadan merkezi bir sistemde ortak bir makine öğrenmesi modeli kurmaktır. Hedef, doktorlara yardımcı olacak ortak bir karar destek sistemidir. Grup özgün değeri, federe öğrenmenin hastane iş birlikleriyle ülkede ilk kez bu projeyle uygulanması olarak açıkladı. Başarı kriterleri şunlardır:

- Federe öğrenme modelinin belli tip veriler için değil, tüm medikal veriler için uygulanabilir olması.
- Mahremiyet gerektiren hiçbir veri alışverişinin olmaması.
- Modellerin gördüğü veri arttığı için performansın artması.

> **Ders sonrası not:** Grup "ülkemizde ilk kez uygulanacak" dedi. Böyle bir özgünlük iddiası büyük olasılıkla bir literatür ve uygulama taramasıyla desteklenmelidir; altyazıda bu tarama anlatılmıyor. "Tüm medikal veriler" kriteri de ölçülebilir bir başarı ölçütü olmak için büyük olasılıkla fazla geniştir.

### 6.3 Federe Öğrenmenin İşleyişi

Grup süreci adım adım anlattı:

1. Merkezi sunucudaki model yerel makinelere gönderilir. Merkezdeki ve yereldeki modeller eşitlenir.
2. Her yerel makine modeli kendi sağlık verisiyle eğitir.
3. Yerel modellerin ağırlıkları merkeze gönderilir. Hassas verinin paylaşılmaması bu adımda sağlanır.
4. Merkezi model gelen ağırlıklarla güncellenir ve yeni ağırlıklar yerel makinelere gönderilir.
5. Döngü belirlenen kriter sağlanana kadar sürer. Kriter, yerel modellerin ya da merkezi modelin performansının belirli bir eşiği geçmesi olabilir.

### 6.4 İş Paketleri

Altı iş paketi vardır. Grup her paket için süre ve kişi profilini de verdi.

| İş paketi | İçerik | Söylenen zaman | Kişi |
|---|---|---|---|
| 1. Proje yönetimi | İşlev ve gereksinimlerin belirlenmesi, dokümanlar | 1. ve 2. ay | 3 yazılım mühendisi |
| 2. Federe öğrenme altyapısı | Kütüphane, program ve ortam kurulumu | 3. ve 12. ay | 1 sistem mühendisi |
| 3. Makine öğrenmesi modeli | Algoritmaların seçimi ve veriye uygulanması | 4. ve 5. ay | 2 veri bilimci |
| 4. Sunucu-istemci mimarisi | Bilgi alışverişi mimarisinin kurulması | 6., 7. ve 12. ay | 3 yazılımcı |
| 5. Federe öğrenme modeli | Algoritmalar, durma ve ağırlık alma kriterleri | 8., 9. ve 10. ay | 3 veri bilimci |
| 6. Test | Doğrulama ve geçerleme süreci | 11. ay | 1 test mühendisi |

<!-- BELİRSİZ: 2. ve 4. paketlerde "3. ve 12. ay", "6., 7. ve 12. ay" ifadeleri ay aralığı anlamında olabilir; 4. paketteki kişi profili altyazıda bozuk ("üç yılın vermesiyle"). -->

### 6.5 Riskler ve Beklenen Etki

İki risk verildi. Birincisi yanlış etiketlemedir. Doğru etiket model başarımını çok etkiler, kişisel deneyim yetmeyebilir. Önlem, uzman doktor veya radyolog desteğidir. İkincisi, sistemin iyi anlaşılamaması yüzünden hastane yönetiminin çekinmesidir. Önlem, çalışan kısa bir demo göstermektir.

Beklenen çıktılar SCI indeksli bir dergide makale, hastanelerde yaygın kullanım, farklı tıp alanlarında da eğitilebilirliğin gösterilmesi ve doktorlar için ortak bir karar destek sistemidir. Grup, veri mahremiyeti korunduğu için uluslararası iş birliğinin de destekleneceğini söyledi.

### 6.6 Soru-Cevap

**Soru:** Federe öğrenmede ağırlıklar merkeze gönderiliyor. Bu kurumlar açısından sorun olmaz mı? Model karşı tarafın eline geçebilir mi? **Cevap:** Grup sorun olmaması gerektiğini söyledi. Gönderilen şey görüntü veya verinin içeriği değil, sayılardan oluşan ağırlıklardır. Bunların dışarıdan bakan biri için anlamı yoktur, hassas veri oluşturmaz.

> **Ders sonrası not:** Grubun "ağırlıklar dışarıdan bakan için anlamsızdır" cevabı büyük olasılıkla eksiktir. Gradyan sızıntısı (gradient leakage), model tersine çevirme (model inversion) ve üyelik çıkarımı (membership inference) saldırılarıyla ağırlıklardan eğitim verisi hakkında bilgi elde edilebildiği bilinmektedir. Bu yüzden federe öğrenme genellikle diferansiyel mahremiyet (differential privacy) veya güvenli toplama (secure aggregation) ile birlikte kullanılır. "Hiçbir hassas bilgi sızmaz" yerine bu risk öneride açıkça ele alınmalıdır.

## 7. 5. Sunum: Blok Zincir Tabanlı Dijital Diploma

### 7.1 Konu ve Özgün Değer

Bu tek kişilik sunumda, blok zincir (blockchain) tabanlı dijital diploma oluşturma, paylaşma ve doğrulama konusu önerildi. Sunum önce blok zinciri tanımladı: Veriyi üçüncü tarafların müdahalesi olmadan depolamayı, doğrulamayı ve iletmeyi sağlayan, dağıtık defterlere dayanan bir teknolojidir. Her defter bir fikir birliği (consensus) mekanizmasıyla çalışır. Yeni bir blok üretilince ağa yayınlanır ve onay alındıktan sonra zincire eklenir.

> **Ders sonrası not:** Sunumda bloğun ağdaki "diğer tüm bloklara" yayınlandığı söylendi; doğrusu büyük olasılıkla ağdaki diğer düğümlere (node) yayınlanmasıdır. Ayrıca blok zincirin "mevcut verinin değiştirilmesi" için kullanıldığı söylendi. Blok zincirin temel özelliği büyük olasılıkla tam tersine, yazılan kaydın sonradan değiştirilmesinin çok zor olmasıdır.

Problem diploma sahteciliğidir. Diploma hem iş hem akademik yaşamda önemli bir belgedir. Bugünkü güvenlik önlemleri hologram, ıslak imza ve kabartmadır ve kolayca taklit edilebilir. Proje, üniversite diplomalarının blok zincirde saklanması için gereken analizleri yapmayı amaçlar. Özgün değer iki noktaya dayandırıldı: Ulusal literatürde blok zincir konusunda yeterli araştırma yoktur ve Türkiye'de aktif kullanılan, blok zincirde saklanan bir diploma sistemi yoktur.

> **Ek bilgi (derste anlatılmadı):** Blok zincirler genel olarak izinsiz (permissionless) ve izinli (permissioned) diye ikiye ayrılır. İzinsiz ağa herkes katılabilir. İzinli ağda ise yalnız yetkili kurumlar kayıt yazabilir veya onay verebilir. Diploma gibi bir belgeyi yalnız yetkili kurum verebildiği için böyle bir senaryoda izinli yapılar sık tartışılır. Soru-cevaptaki "onayı hangi kurum verecek?" sorusu da bu tasarım kararına bağlanır.

### 7.2 Hipotez, Amaç ve Başarı Kriterleri

Hipotez şudur: Diplomaların dijital olarak oluşturulup blok zincirde saklanabilmesi için gereken altyapı ve güvenlik nitelikleri analiz edilirse, diplomalar güvenle saklanabilir ve farklı taraflarca doğrulanabilir. Genel amaç, sahteciliği önlemek için gereken teknolojinin ayrıntılarını araştırmak ve temel teknik analizi yapmaktır. Bu nedenle proje bir ürün değil, temel araştırma projesi olarak sunuldu. Başarı kriterleri gereksinim analizinin, süreç analizinin ve sistem tasarımının yapılması; önerilen sistemin modelinin ve gelecekteki geliştirmeler için yol haritasının çıkarılmasıdır.

### 7.3 İş Paketleri ve Ekip

Dört iş paketi vardır, toplam süre 8 aydır. Ekip, proje yürütücüsü ile bir araştırmacıdan oluşur; biri blok zincir, biri kriptoloji uzmanı iki danışman destek verir.

- **Gereksinim analizi (1 ay):** Dijital diplomanın ve doğrulama sisteminin sahip olması gereken özellikler belirlenir. Bu özellikler belirlenince paket başarılı sayılır.
- **Süreç analizi (1 ay):** Temel adımlar belirlenir: dijital diplomanın oluşturulması, blok zincirde yayınlanması, farklı taraflarla paylaşılınca doğrulanması.
- **Sistem tasarımı:** Her adımdaki sistem davranışı akış diyagramlarıyla gösterilir, kullanılacak altyapı ve teknolojiler belirlenir. Bu paketin süresi altyazıda bozuktur. Söylenen 8 aylık toplamdan $8 - 1 - 1 - 4 = 2$ ay çıkar (ara adım eklendi).
- **Teknik analiz (4 ay):** Altyapı, güvenlik ve şifreleme algoritmaları incelenir. Grup bunu projenin en önemli ve en uzun adımı olarak tanımladı.

### 7.4 Risk, Çıktılar ve Etki

Tek risk, teknik analiz paketine bağlandı: Aranan teknik bilgiye mevcut danışmanlıklarla ulaşılamayabilir. B planı, eksik konuda eğitim almak, farklı bir danışmana gitmek ya da seminer veya konferansa katılmaktır.

Bilimsel çıktı olarak 6. ile 8. aylar arasında bir kongre sunumu ve Science veya IEEE dergilerinden birinde makale öngörüldü. Ekonomik ve ticari çıktı, 4. ile 8. aylar arasında çıkacak ve sonraki ürün geliştirme projelerinde kullanılabilecek bir modeldir. Etkiler ülke genelinde sahtecilik sorununa çözüm, alanda yeni araştırmaların teşviki ve dışa bağımlılığın azalmasıdır. Sunumda bu etkilerin çoğunun ancak modelin ürüne dönüşmesinden sonra görülebileceği özellikle belirtildi.

### 7.5 Bütçe

TÜBİTAK'tan istenen tutar yalnız danışmanlık içindir: 18.000 TL. Son 4 ay destek verecek kriptoloji danışmanı için yaklaşık 6000 TL, proje geneline destek verecek blok zincir danışmanı için 12.000 TL ayrıldı. Kontrol: $6000 + 12.000 = 18.000$ TL. Öneren kuruluş olan üniversite de iki bilgisayar sağlar; bu katkı 12.000 TL olarak gösterildi.

### 7.6 Soru-Cevap

**Soru:** Bu çalışma, iş başvurularındaki fotokopi ve noter onayı gibi süreçleri de azaltabilir. Ama blok zincirde doğrulamayı bir kurumun sağlaması gerekmez mi? Bu kurum üniversite mi olacak, YÖK mü? **Cevap:** Bu henüz araştırılacak bir konudur. Diplomayı üniversiteler verdiği için onayı onlar verir, ortak bir çalışma olabilir. Belki akıllı sözleşmeler (smart contract) yoluyla üniversite YÖK'e gönderir, YÖK onaylayınca blok zincirde yayınlanır.

**Soru:** Kişi diplomasının basılı çıktısını alabilecek mi? **Cevap:** Mobil uygulama geliştirilirse öğrenci diplomasını görüntüleyebilir ve çıktısını alabilir. Ama fiziksel çıktıya dönüşen belge yine kopyalanabilir, çünkü güvenliği sağlayan şey belgenin blok zincirde olmasıdır.

Soruyu soran öğrenci buna karşı bir öneri getirdi: Bu tür belgelerde barkod ya da QR kod bulunur. Tarama sırasında QR kod korunursa çıktıda da sorun çıkmaz. Sunan kişi bu ayrıntıyı henüz düşünmediğini ve yöntemin mantıklı olabileceğini söyledi.

## 8. 6. Sunum: Deprem Enkazında Arama Kurtarma Robotu

### 8.1 Konu ve Amaç

Bu sunumun İngilizce ilk bölümü altyazıda büyük ölçüde anlaşılmıyor. Yalnızca robot teknolojisinin askerî ve biyomedikal gibi birçok alanda kullanıldığı, projenin bir arama kurtarma robotu olduğu seçilebiliyor. Kısa nottaki slayt bilgisine göre amaç, depremden sonra enkaz alanında kazazedeleri hızla bulmak, konumlarını ve sağlık durumlarını belirlemek, arama kurtarma süresini kısaltıp başarı oranını artırmaktır. Sunumun geri kalanı Türkçe ve anlaşılırdır.

<!-- BELİRSİZ: 01:11:18-01:14:33 arası İngilizce kısım altyazıda döngülü ve bozuk. Yalnızca dört motor ile "VNH" diye başlayan iki motor sürücüsü seçilebiliyor; model adı net değil. -->

### 8.2 Özgünlük: Potansiyel Alan ile Yol Planlama

Projenin özgün kısmı yol planlamadır. Literatürde `A*` türü algoritmalar bir maliyet haritası (cost map) çıkarır ve yolu bunun üzerinden planlar. Hiperparametreler iyi ayarlanmazsa robot engellere çok yaklaşır ve engelden kaçınmada sorun çıkar.

<!-- BELİRSİZ: Algoritma adları altyazıda "All Star, Least Star" diye geçiyor. İlki büyük olasılıkla A*; ikincisi net değil. -->

Grubun önerisi potansiyel tabanlı bir yaklaşımdır. Engeller robota itici, hedefler (burada kazazedeler) çekici bir kuvvet uygular. Robot bu kuvvetlerin bileşkesiyle hareket eder. Slayttaki potansiyel alan haritasında yüksek ve düşük bölgeler görünür; kırmızı yol, robotun düşük potansiyelli noktalardan geçerek çizdiği yoldur. Grup bu yaklaşımın dinamik engellerden kaçınmayı da sağladığını söyledi. Bu önemlidir, çünkü enkazda çökme ve yangınlar sürebilir, yani ortam sürekli değişir.

> **Ders sonrası not:** Yapay potansiyel alan yöntemi büyük olasılıkla yerel minimumlara (local minima) takılabilir: Kuvvetlerin dengelendiği bir noktada robot hedefe varmadan durabilir. Sunumda bu sınırlılık anılmadı; risk planında yer alması beklenir.

### 8.3 Sistem Bileşenleri

Grup sistemi beş başlıkta anlattı:

- **Mekanik tasarım:** Ortam şartlarına uygun, sağlam ve işlevsel bir yapıdır. Sensörleri ve kameraları korur.
- **Elektrik ve sensörler:** Sensörler ve kameralar birlikte kullanılarak kazazedenin konumu ve sağlık durumu bulunur. Veriler arama kurtarma ekibine bilgisayar üzerinden iletilir.
- **Motorlar:** DC motor kullanılır; gereken gücü üretmek için her tekere bir motor konur.
- **Kontrol sistemi:** Bir Arduino Mega ve bir Raspberry Pi kullanılır. Arduino Mega sensörlerden gelen lazer ve kamera verisini işler. Raspberry Pi hesaplamaları yapar, keşif ve yol planlamayı yürütür, kazazede ile ekip arasındaki iletişimi sağlar.
- **Yazılım ve haberleşme:** Kullanıcı arayüzü Java veya C# ile, hızlı olması gereken keşif ve planlama algoritmaları C ve C++ ile yazılır. Robot hem operatörle kullanılabilir hem de otonom olarak enkazda arama yapabilir.

<!-- BELİRSİZ: Grubun söylediği toplam sayı "5-6 sistem", sayılan beş başlık. Otonom keşif algoritmasının adı altyazıda bozuk ("4 parti keşif"). -->

### 8.4 Gerekçe ve Beklenen Etki

Enkaz altındaki insanlar için ilk 3-4 gün kritiktir; sonrasında hayatta kalma oranı çok düşer. Grup, insanlar ne kadar çabuk bulunur, konumu ve yaralanma durumu ne kadar çabuk öğrenilirse can kaybının o kadar azalacağını söyledi. İstanbul'da olabilecek bir depremin enkazının kısa sürede kaldırılamaması büyük can ve mal kaybı demektir. Grup depremi bu yüzden ulusal güvenlik tehdidi olarak da andı.

Akademik olarak görüntü işleme, yol planlama ve haritalama alanında yeni çalışmalar beklenir. Enkazın büyüklüğü düşünülürse çok robot gerekir, bu da seri üretime ve alana yeni şirketlerin girmesine yol açabilir. Araştırmacı yetiştirme için iki lisans öğrencisi, toplam 8 aylık süreçte bursiyer olarak çalışır.

**Soru:** Termal sensör kullanmayı planladınız mı? **Cevap:** Evet, sunumda atlanmış olabilir. Termal sensör canlıların tespiti için kullanılacak.

## 9. 7. Sunum: Mobil Robotlar İçin Görüntü Tabanlı Konum Belirleme

### 9.1 Amaç ve Özgünlük

Mobil robot, sabit bir platforma bağlı olmadan çevrede serbest hareket eden robottur. Bir grup, birden fazla kamera ve görsel yöntemlerle bir mobil robotun iç ortamda iki boyutlu konumunu metrik olarak bulan algoritmalar önerdi. Bir kamera robotun önüne, biri arkasına, biri tavana bakar. Hedefler şunlardır:

- İç ortamda iki boyutlu konumu ±5 cm hassasiyetle bulmak.
- Konum verisinin SLAM haritalama yöntemleriyle birlikte kullanılabilmesini sağlamak.
- Algoritmaları en az 4 çekirdekli, 2,5 GHz işlemcili, 8 GB RAM'li bir bilgisayarda çalıştırmak.
- Proje sonunda bir prototip çıkarmak.

> **Ders sonrası not:** Sunumda işlemci için "2.5 GB CPU" denildi; işlemci hızı için doğru birim GHz'dir.

Özgünlük, kamera verisinin birleştirilme biçimindedir. Grubun anlatımına göre normalde kameralardan gelen veriler birleştirilir ve tek bir görsel konumlandırma yapılır. Bu projede ise her kameradan ayrı bir konum çıkarılır ve bu konumlar en sonda sensör füzyonu (sensor fusion) ile tek konuma indirilir. Böylece kameralar birbirini doğrular ve konumun doğruluğu artar.

### 9.2 Geliştirme Ortamı

- **Ubuntu:** Geliştirmeyi kolaylaştırdığı ve diğer araçlar onunla doğal biçimde çalıştığı için seçilmiştir.
- **ROS (Robot Operating System):** Simülasyondaki ve gerçek dünyadaki bileşenler arasındaki haberleşmeyi sağlar, hazır kütüphaneler sunar.
- **Gazebo:** Gerçek testlerdeki kazaları maddi kayıp olmadan görmeyi ve malzemeler gelene kadar denemeyi sağlayan simülasyon ortamıdır. Araçların ve sensörlerinin kopyaları vardır, sensör verisi ROS'a aktarılır.
- **RViz:** Verileri üç boyutlu olarak görselleştirir, hata ayıklamayı ve sonuçların yorumlanmasını kolaylaştırır.

### 9.3 Görsel Odometri ve Döngü Kapatma

Grubun planı, ardışık kareler arasındaki geçişten odometri verisi çıkarmaktır. Bunun için birçok özellik çıkarma yöntemi incelenmiş, maliyet ve başarı nedeniyle SIFT, SURF ve ORB kalmıştır. SIFT ve SURF en iyi sonucu verir, ama ticari kullanımda lisans sorunu vardır. Bu yüzden ticarileşme aşaması için ORB de listeye alınmıştır.

> **Ders sonrası not:** Sunumda SIFT için de lisans sorunu olduğu söylendi. SIFT'in patenti büyük olasılıkla Mart 2020'de sona ermiş, OpenCV 4.4'ten beri ana modüle alınmıştır. Lisans kısıtı büyük olasılıkla SURF için geçerlidir.

Slayttaki görselde iki resimden çıkarılan özellikler ve bunları eşleyen sarı çizgiler görünür. Eşleşen özelliklerin iki resim arasında ne kadar ve hangi düzlemde hareket ettiği bulunur ve aracın ne yöne kaydığı tahmin edilir. Elde edilen rota, gerçek rotadan (ground truth) zamanla sapar. Bu sapmayı azaltmak için döngü kapatma (loop closure) yapılır: Robot daha önce gördüğü bir yere dönüp aynı özellikleri görünce "burayı daha önce görmüştük" der, biriken kaymayı bu bilgiyle düzeltir ve daha başarılı bir odometri sonucu elde edilir.

### 9.4 Füzyon: Kalman Filtresi

Birden çok kamera birden çok konum verir, bunların birleştirilmesi gerekir. Grup birçok yöntem arasından Kalman filtresini seçti, çünkü hedef bilgisayarda görüntü sürekli işlenecek ve maliyet düşük olmalıdır. Filtre, aracın yapabileceği hareketleri de hesaba katarak konum tahminini iyileştirir. Slayttaki örnekte sarı çizgi tekerlek odometrisidir ve aracın kinematiğine uygundur. Görsel odometride robotun fiziksel olarak yapamayacağı sıçramalar varsa filtre bunları eler.

> **Ek bilgi (derste anlatılmadı):** Kalman filtresi iki adımda çalışır. Tahmin adımında sistemin hareket modeliyle bir sonraki durum ve belirsizliği hesaplanır. Güncelleme adımında gelen ölçüm, tahminle belirsizliklerine göre ağırlıklandırılarak birleştirilir. Hesabı özyinelemeli olduğu ve tüm geçmişi tutmadığı için düşük işlem gücüyle çalışabilir. Temel biçimi doğrusal sistemler içindir; doğrusal olmayan hareket modellerinde genişletilmiş Kalman filtresi (EKF) gibi türevleri kullanılır.

### 9.5 İş Paketleri ve Riskler

Dört iş paketi ve 12 aylık bir plan vardır:

| İş paketi | İçerik | Söylenen zaman |
|---|---|---|
| 1. Teknik analiz ve kavramsal tasarım | Teçhizat tedariki, geliştirme ortamının hazırlanması | 1-4. ay |
| 2. Görsel yöntemlerle özellik çıkarma | Ortamdan ayırt edici özelliklerin kameralarla çıkarılması | 1-5. ay |
| 3. Görsel yöntemlerle konum bulma | Bu özelliklerden metrik konum elde edilmesi | 5-12. ay |
| 4. Konum verilerinin füzyonu | Kamera başına bulunan konumlardan tek konum üretilmesi | 6-12. ay |

Riskler iş paketlerine bağlanmıştır:

- **2. pakette:** Tavana bakan kamera, tavanın uzaklığı nedeniyle özellik çıkaramayabilir. B planı, daha yüksek çözünürlüklü bir kameradır.
- **4. pakette:** Füzyonla istenen metrik başarım elde edilemeyebilir. B planı, GTSAM gibi farklı bir yöntemdir.

### 9.6 Beklenen Etki ve Bütçe

Bilimsel çıktı, IROS veya ICRA gibi bir konferansta bildiridir. Ekonomik çıktı, patentlenebilir ve ticari ürüne çevrilebilir bir konumlandırma yöntemidir; grup görüştüğü müşterilerin böyle bir ürün beklediğini söyledi. İki bursiyer de görsel yöntemler, sensör füzyonu ve konum bulma alanında yetişecektir. Proje başarılı olursa 1505 Üniversite-Sanayi İşbirliği programıyla ürün üretilmesi düşünülür.

Bütçe olarak makine ve teçhizat için 3.668 TL (3 kamera, 1 mini bilgisayar) ve iki yüksek lisans bursiyeri için 13.200 TL söylendi. Toplam istenen tutar 18.868 TL olarak verildi.

> **Ders sonrası not:** Sayılan kalemlerin toplamı $3.668 + 13.200 = 16.868$ TL'dir. Söylenen toplam 2000 TL daha fazladır. Fark, altyazıda söylenmeyen bir kalemden ya da bir rakam hatasından kaynaklanıyor olabilir; slayttan doğrulanamadı.

Bu sunumun ardından soru gelmedi.

## 10. 8. Sunum: Yeniden Kimlik Tespiti

### 10.1 Konu ve Literatür

Son grup, yeniden kimlik tespiti (person re-identification) için bir model optimizasyonu önerdi. Yeniden kimlik tespiti, bir kişinin farklı kameralardan veya farklı açılardan çekilmiş görüntüleri arasında ilişki kurma alanıdır. Elde bir kişinin tek fotoğrafı varsa ve o kişi farklı hareketlerin görüntülerinde bulunmak isteniyorsa yine bu alanın yöntemleri kullanılır.

Grubun problemi şudur: Mevcut yöntemler bazı durumlarda çok başarılı, bazı durumlarda başarısızdır. Literatür analizinde yaklaşık 10 makaleden 6 yöntem çıkarılmıştır: tamamlayıcı yöntem, ayrımcı yöntem, benzerlik rehberlikli sinir ağı yöntemi, parça tabanlı kayıp yöntemi, uyarlanabilir çizge gösterimi öğrenme yöntemi ve Top-DB-Net. Grup iki tanesini açıkladı:

- **Parça tabanlı kayıp:** Geleneksel yöntemler kişinin görüntüsünden tek bir harita çıkarıp benzerlik arar. Bu yöntemde kişinin parçaları ayrı ayrı tespit edilir ve benzerlik bu parçalar üzerinden kurulur.
- **Top-DB-Net:** Burada da parçalar tespit edilir, ama her parçaya bir önem ağırlığı verilir ve benzerlik oranı bu ağırlığa göre hesaplanır.

### 10.2 Özgün Değer, Araştırma Sorusu ve Amaç

Grubun özgünlük iddiası, mevcut modellerin şimdiye kadar tek bir veri kümesi üzerinde test edilmiş olmasına dayanır. Grup farklı modelleri farklı veri kümelerinde test edecek, başarı oranlarını hesaplayacak, hangi modelin hangi durumda iyi olduğunu ve hangi modellerin birlikte kullanılabileceğini bulacaktır.

Araştırma sorusu, yeniden kimlik tespitinde daha başarılı ve daha verimli bir model optimize edilip edilemeyeceğidir. İki hedef uygulama verildi: şüpheli tespiti ve futbol ile basketbol sahalarında oyuncuların hareketlerini izleyerek performans analizi yapan bir ürün.

Yöntem adımları şunlardır: modelleri belirlemek, başarılı modellerde etkili olan faktörleri çıkarmak, performans analizi yapmak, kendi modelini kurmak, müşteri profilini belirlemek, bu profile uygun arayüzler geliştirmek ve ürünü ticarileştirmek.

### 10.3 Proje Planı

Plan MS Project ile hazırlanmış, her aşamada nasıl bir çalışan profiline ve kaç güne ihtiyaç olduğu ayrıntılandırılmıştır. Üç ana kilometre taşı vardır.

**Tasarım:** Modele hangi yöntemlerin dahil edileceği ve hangi test kriterlerinin kullanılacağı belirlenir. Yöntemler performans analizinden geçirilir. Sonuçlar analitik hiyerarşi süreci (Analytic Hierarchy Process, AHP) gibi bir karar verme yöntemine girilir ve hangi modelin ne zaman devreye gireceği netleşir.

> **Ek bilgi (derste anlatılmadı):** Analitik hiyerarşi süreci, çok ölçütlü karar verme yöntemlerindendir. Karar verici ölçütleri ve seçenekleri ikişer ikişer karşılaştırır. Bu karşılaştırmalardan bir matris kurulur ve her seçenek için göreli ağırlıklar çıkarılır. Yöntem, karşılaştırmaların birbirini ne kadar tuttuğunu gösteren bir tutarlılık oranı da verir.

**Uygulama:** Kod yazılır, ama grup bunun tek başına yetmediğini söyledi; pazar araştırması da gerekir. Pazarlar (savunma sanayii, iç güvenlik, spor, eğlence) büyükten küçüğe sıralanır. Pazarın büyük olması en iyi fayda anlamına gelmediği için SWOT analizi yapılır ve hedef pazar seçilir. Ürün hedef pazara göre uyarlanır: Örneğin savunma sanayiinde bir drone'a eklenti, sporda ise kullanıcıya uygun arayüz düğmeleri geliştirilir.

**Satış:** Fiyat politikası, tanıtım, demo sürüm ve sözleşme formatı hazırlanarak ürün ticarileştirilir.

Hoca bu kısımda sunumu kısaca böldü. Ekranda gördüğü ile anlatılanın uyuşmadığını düşündüğünü söyledi. Sunan kişi, slaytı okumadan konuyu aktardığını ve aynı içerikten bahsettiğini belirtti. Hoca sorunun okumamak olmadığını, konunun dışına çıkıldığını düşündüğünü söyleyip özür diledi ve devam etmesini istedi. Hoca, sorunun slaytı okumamak değil, anlatılanın ekrandakinden uzak görünmesi olduğunu belirtmiş oldu.

<!-- BELİRSİZ: Hocanın ekranda gördüğünü söylediği slayt başlığı altyazıda bozuk. -->

### 10.4 Risk Yönetimi

Grup her aşamada "şeytanın avukatlığı" yaparak olası riskleri çıkardığını söyledi. Erken fazda yakalanan sorunların telafisi kolay, geç fazda yakalananların telafisi zordur. Yöntem belirleme aşamasında risk görülmemiş, test kriterlerinde atlanan bir nokta olursa fazla mesaiyle telafi planlanmıştır. Kadro, aksiliklere karşı geniş tutulmuştur. Proje aşamalarının dışında COVID-19 salgını, hastalık ve ekonomik durumlar için de B planı ve projenin sigortalanması gibi çözümler düşünülmüştür.

<!-- BELİRSİZ: Kadro sayıları altyazıda tutarsız: "iki yüksek lisans, iki doktora öğrencisi", "üç kişi ekstra ekip", bütçede "3 bursiyer". -->

### 10.5 Çıktılar ve Etkiler

Önce algoritmanın patenti alınacak, ardından tanınmış bir dergide makale yayımlanıp sunum yapılacaktır. Grup "sunumdan önce patent almamız gerektiğini biliyoruz" diye özellikle belirtti. Yazılımı satacak, geliştirecek ve müşteri şikâyetleriyle ilgilenecek bir girişim (start-up) kurulması düşünülür. Bir prototip demo yazılım çıkarılır. Araştırmada çalışacak kişilerle iki yüksek lisans ve bir doktora tezi hedeflenir.

> **Ders sonrası not:** "Yayından önce patent" fikri doğru yöndedir. Türkiye'de 6769 sayılı Sınai Mülkiyet Kanunu, büyük olasılıkla buluş sahibinin kendi açıklamasına 12 aylık bir hoşgörü süresi tanır. Avrupa Patent Ofisi'nde büyük olasılıkla böyle genel bir süre yoktur. Bu yüzden en güvenli yol, yayından önce başvuru yapmaktır.

Etkiler dört başlıkta sayıldı. Toplumsal etki, savunma ve iç güvenlikte kullanılırsa daha güvenli bir ortamdır. Akademik etki, üniversite-sanayi iş birliğiyle başka Ar-Ge çalışmalarını tetiklemektir; drone eklentileri ve sporcu analizinde zorlanmaların tespiti örnek verildi. Ekonomik etki, milli bir ürünle savunma sanayiinde avantaj ve girişimle istihdamdır. Ulusal güvenlik etkisi ise iç ve dış güvenliğe katkıdır.

> **Ders sonrası not:** Kişi takibi yapan ve savunma uygulamalarını hedefleyen bir öneride etik kurul onayı, KVKK uyumu ve teknolojinin kötüye kullanım riski büyük olasılıkla bir iş paketi veya risk olarak yazılmalıdır. Sunumda bu başlık anılmadı.

### 10.6 Bütçe

Grup 1002 programının destek üst sınırını 45.000 TL olarak verdi. Dağılım makine ve teçhizat için %35, bursiyer için %25, hizmet alımı için %27 olarak söylendi. Seyahat ve geçici görev giderine yer verilmedi; gerekirse kendileri karşılayacaklarını söylediler. Teçhizat kalemi, üç bursiyer için aynı özellikte dizüstü bilgisayarlardan oluşur. Ticarileştirme tarafında bir pazarlama ajansıyla anlaşma düşünülür. Motivasyon için telefon ve internet gideri de ayrılmıştır. Çalışmayan bursiyerlerin ücreti bütçeyi aştığı için çalışan bursiyerler tercih edilmiştir.

> **Ders sonrası not:** Söylenen yüzdelerin toplamı $35 + 25 + 27 = 87$'dir. Kalan %13 altyazıda açıklanmıyor; büyük olasılıkla telefon ve internet gibi diğer kalemlerdir. Böyle kalemler bütçe tablosunda açıkça gösterilmelidir.

Bu sunumun ardından soru gelmedi.

## 11. Hocanın Genel Geri Bildirimleri

Son sunumdan sonra hoca, gün boyunca not ettiği ortak sorunları sıraladı. Sunumların bir kısmının hâlâ düzeltilebileceğini, bu yüzden bunları hatırlatmakta fayda gördüğünü söyledi.

### 11.1 Slayt Metni ve Okuma

Görülen sorunlardan biri, rapordaki blok paragrafları olduğu gibi slayta koymaktır. İkincisi, sonra bu paragrafları olduğu gibi okumaktır. Hoca, kalabalık slaytların etkisini daha önce de konuştuklarını hatırlattı.

> **Hocanın vurgusu:** "Sunum dediğimiz şey slayttaki yazanları okumak değil." Slaytın otomatik olarak geçtiği bir yapı da aynı işi görür. Bu yüzden sunan kişinin slayta bir şey katıyor olması gerekir.

### 11.2 Slayt Sayısı ve Konuşma Hızı

Slayt sayısı önceden planlanması gereken bir şeydir. Herkesin insanların anlayabileceği bir konuşma hızı olmalıdır ve 10 dakikalık süre bilindiğine göre slayt sayısı buna göre ayarlanmalıdır. Hocaya göre slayt sayısı hem ön hazırlığın ne kadar iyi yapıldığını gösterir, hem de teknik olarak konuşmayı ve süre kullanımını etkiler. 2. sunumdaki "10 dakikaya 20 slayt uygun mu?" sorusu bu noktaya işaret eder.

### 11.3 Kendini Tanıtmak

Kim olduğunuzu, ne yaptığınızı, neyi anlatacağınızı söylemek çok önemlidir. Takım arkadaşınız varsa onu da tanıtırsınız. Söz ona geçtiğinde o da kendini kısaca yeniden tanıtmalıdır.

### 11.4 Kapanış

Hocanın benzetmesi şuydu: "Nasıl hoş geldin diyorsan, giderken de güle güle diyorsun insanlara." Yani slaytların sonunda en azından bir teşekkür bulunmalı ve sorular kabul edilirken bu bilgi slaytta yer almalıdır.

Hocanın öğütlerini bir kontrol listesi olarak toplarsak:

- Kamera açık, süre içinde kalınmış mı?
- Slayt sayısı süreye uygun mu, konuşma hızı anlaşılır mı?
- Slaytlar raporun blok paragraflarından arındırılmış mı, sunan kişi slayta bir şey katıyor mu?
- Sunan kişi ve takım arkadaşı kendini tanıtmış mı?
- Sonda teşekkür ve soru bilgisi var mı?
- Sunan kişi sorulara, dinleyici de soru sormaya hazır mı?

## Dersin Toparlaması

Bu derste sekiz proje önerisi dinlendi: COVID-19 tanısında veri kaynaklı yanlılık, yoğun bakımda anomali tespiti, görme engelliler için giyilebilir asistan, federe öğrenme, blok zincir diploma, arama kurtarma robotu, görüntü tabanlı robot konumlandırma ve yeniden kimlik tespiti. Konular farklı olsa da öneriler aynı soruları cevaplamak zorundadır: Sorun neden önemli, öneri literatürden nerede ayrılıyor, amaç nasıl ölçülecek, iş nasıl paketlere bölünüyor, her risk için B planı ne ve bütçe bu işi karşılıyor mu? Sunumlarda en sık görülen güçlü alışkanlık, riskleri iş paketlerine bağlamak ve her biri için bir önlem yazmaktı.

Hocanın asıl vurgusu ise içerikten çok aktarımdaydı. Sunum, raporun okunması değildir. Süre, slayt sayısı, konuşma hızı, tanıtım, kapanış ve soru-cevap sunum hazırlığının parçasıdır. Hoca, önümüzdeki hafta da sunumların aynı biçimde süreceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
