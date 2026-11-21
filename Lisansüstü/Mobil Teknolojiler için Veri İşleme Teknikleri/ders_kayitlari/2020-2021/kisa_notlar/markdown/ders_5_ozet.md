# Ders 5 Çalışma Özeti

## Genel Konular

- iOS ve Android karşılaştırması
  - iOS donanım ve işletim sisteminin birlikte ele alındığı, kontrollü ve güvenliği öne çıkaran bir yapıdır. Donanımı verimli kullandığı için daha küçük pille benzer kullanım süresi sağlar. Android'deki uzun kullanım süresi daha çok büyük pil kapasitesinden gelir.
  - Android çok sayıda farklı üreticinin cihazında çalışmak zorundadır. Güncellemeler üreticinin modifikasyonundan ve lisans anlaşmalarından geçtiği için her cihaza ulaşmaz. iOS'ta güncelleme bütün desteklenen cihazlara aynı anda gelir.
  - Uygulamayı markete koymanın maliyeti iOS tarafında daha yüksektir. iOS'un uygulama marketi daha kısıtlıdır, Android'de daha çok uygulama vardır.
  - Widget, uygulamayı açmadan ana ekrandan sık erişilen verinin güncel halini gösteren ve sınırlı etkileşim sağlayan yapıdır. Android'de uzun zamandır vardı, iOS'a yakın zamanda geldi. Hocaya göre gecikmenin nedeni yalnız patent değildir: widget kontrolün bir kısmını programcıya bırakır ve işletim sisteminin performansını etkiler.
  - Son yıllarda iki tarafın da odaklandığı problemler güvenlik ve pil ömrüdür. Android'in Doze özelliği telefonun kullanılmadığını anlayıp arka plan servislerini daha seyrek uyandırır. Bunu yapmanın yolu kişinin aktivitesini anlamaktır.
- Araç içinde olmayı anlamak
  - En önemli ipucu konum değişikliğinden (GPS, baz istasyonu, Wi-Fi) hesaplanan hızdır. GPS paketlerinde hız bilgisi de bulunur. Belli bir hız eşiğinin üstü araç hareketi sayılır. <!-- BELİRSİZ: Hocanın söylediği eşik değeri altyazıda anlaşılmıyor ("Saat olarak aşağı yukarı sınır belirleniyor"). -->
  - Kişinin araçta olduğunu anlamak, araçta telefonu kullanıp kullanmadığını anlamak anlamına gelmez.
- Aynı anda gerçekleşen aktivitelerin tanınması
  - Aktiviteler basit, kompleks ve aynı anda gerçekleşen aktiviteler diye ayrılmıştı. En zoru aynı anda gerçekleşenlerdir: araba kullanırken telefonda konuşmak, trende ya da uçakta giderken araç içinde yürümek, metroda giderken mesajlaşmak, koşarken müzik dinlemek, televizyon izlerken telefonu kurcalamak gibi.
  - Mevcut çalışmalar çoğunlukla bir anda tek bir aktiviteyi tanımaya odaklanır. Hocaya göre bu problemi ele alan bir çalışma bilmiyor ve konu araştırmaya açık.
  - Derste önerilen yaklaşımlar: saat ve telefonu birlikte kullanmak; hareketlerin farklı frekans bantlarında iz bırakmasından yararlanıp frekans domeni öznitelikleri çıkarmak; aracın bilinen titreşimini veriden çıkarıp kalanı incelemek (zaman çizelgesinde önceki pencerelerle ilişki kurmak); farklı pencere boyutlarını aynı anda kullanmak.
  - Telefonla yapılan aktiviteler (konuşma, mesajlaşma, oyun) sistem seviyesindeki olaylardan (arama durumu gibi) ve proximity sensöründen anlaşılabilir.
  - Ortam zekâsı (ambient intelligence) açısından toplu aktivitelerin tanınması da önem kazanıyor. Bunun için daha çok kamera görüntüsü kullanılır. Hocanın verdiği bir örnekte birlikte hareket eden bir gruba telefon sinyallerinden yola çıkılarak kampanya mesajı gönderiliyor.
  - Deprem durumunda anonimleştirilmiş konum verisiyle binadaki kişi sayısını tahmin etme fikri tartışıldı; bunun KVKK ve etik sorunları (kurtarma önceliğini kişi sayısına ya da yaşa göre belirleme) vurgulandı.
- Pencereleme (windowing)
  - Sürekli sensör verisi (ivmeölçer, jiroskop, manyetometre, her biri 3 eksen) parçalara bölünerek incelenir; tamamını bir seferde analiz etmek mümkün değildir.
  - Pencereyi en küçük birim kadar kaydırmak hiçbir geçişi kaçırmaz ama maliyeti çok yüksektir. Pencereler hiç örtüşmeden kaydırılırsa iki pencerenin sınırına düşen hareket kaçırılabilir.
  - Örtüşme oranı (overlap ratio) için %40-%60 önerilir; temel aktivitelerde (yürüme, koşma, oturma, kalkma) pencere boyutu 3-5 saniyedir (ekrandan, 00:35:00).
  - Pencere boyutunda bir ödünleşim vardır: çok küçük pencerede yeterli veri olmaz ve hareketin tamamının örüntüsü görülmez; çok büyük pencerede birden fazla geçiş aynı pencereye girer ve çözünürlük kaybolur.
  - Sık ve kısa periyotla tekrarlanan aktiviteler (yürüme) küçük pencereyle, uzun döngülü aktiviteler (aracın kalkması, hızlanması, durakta durması) büyük pencereyle (8, 16, 32 saniye, hatta bir dakika) daha iyi tanınır.
  - Frekans domenine geçmek için Fourier dönüşümü gerekir ve bunun bir işlem maliyeti vardır. Pencere uzunluğu ikinin kuvveti seçilirse bu maliyet azalır.
- Düşme tespiti (fall detection)
  - Özellikle yaşlılar için kritiktir. 2010'lu yıllarda yoğun çalışıldı; çoğunlukla ivmeölçer ve jiroskop kullanılır.
  - Eşik değer (threshold) ve makine öğrenmesi yaklaşımları vardır. Tek eşik yeterli olmayabilir; çift eşik (double thresholding) ile yüksek değerler kesin düşme, düşük değerler kesin düşme değil diye etiketlenir. Arada kalan değerlerin penceresi makine öğrenmesiyle örüntü (sendeleme, düşme, yerde yatma) açısından incelenir.
  - Kapalı mekânda video, dışarıda giyilebilir/taşınan cihazdaki sensörler kullanılır.
- Mobil uygulama kategorileri ve başarının etkenleri
  - Slayttaki ankette en sık kullanılan kategoriler 2012'de sosyal %76, müzik %72, oyun %53; 2014'te sosyal %79, müzik %74, navigasyon %57 idi (ekrandan, 01:15:00). 2015'te en hızlı büyüyen kategori kişiselleştirme (%332) oldu.
  - Aynı tipteki uygulamalar arasında farkı kullanıcı deneyimi (UX), yeni teknolojiler/protokoller, doğru zamanda ihtiyaca cevap vermek, coğrafyaya ve hedef kitleye göre tasarım belirler. Gereksiz özellik eklemek uygulamayı karmaşıklaştırır ve kullanıcıyı kaçırır.
  - Dokunma noktaları, video izleme davranışı, uygulama kullanım süresi gibi verilerle davranış analizi yapılır. Bu tür zaman çizelgesi verisi için tekrarlayan sinir ağları (RNN, LSTM, GRU) uygundur.
- Mobil uygulama geliştirme teknikleri
  - Dört temel yaklaşım: native geliştirme, cross-platform araçlarla geliştirme, hibrit uygulama geliştirme ve mobil web geliştirme.
  - Mobil web (responsive tasarım, HTML5) en fazla kullanıcıya ulaşır; kurulum gerektirmez ama her uygulama bu yolla geliştirilemez. Güvenlik seviyesini kullanılan SSL/TLS gibi protokoller belirler.
  - Native geliştirme platformun SDK'sını kullandığı için en iyi kullanıcı deneyimini ve donanıma tam erişimi sağlar; ancak Swift/Objective-C/Kotlin geliştiricisi bulmak daha zordur.
  - Cross-platform araçlar hız ve maliyet avantajı sağlar. En büyük sıkıntısı kaynak tüketimidir: ara katmanın ürettiği kod elle yazılan native koddan daha az verimli ve daha büyük olabilir (derleyici benzetmesi). Ek katman güvenlik açığı riski de getirir.
  - Hibrit uygulama HTML5, CSS ve JavaScript ile yazılır; Cordova gibi araçlar bu kodu bir native kapsayıcıya sarar (wrapping), uygulama markete konabilir ve WebKit tabanlı bir motor üzerinde çalışır.
- Mobil cihazlardaki sensörler
  - Telefonlarda ivmeölçer, jiroskop ve manyetometre artık standarttır. Diğerleri: GPS, ışık sensörü, proximity sensörü, barometre, kamera ve derinlik kamerası, mikrofon, parmak izi, nabız, kandaki oksijen ölçümü, sıcaklık, nem, dokunmatik ekran (kapasitif, son dönemde basınç şiddeti de algılanıyor).
  - Bluetooth ve kızılötesi gibi bileşenler doğrudan fiziksel sensör değildir, sanal sensör olarak ele alınır.
  - Işık sensörü ekran parlaklığını ortama göre ayarlayarak enerji tasarrufu sağlar. Proximity sensörü görüşme sırasında ekranı kapatır ve telefonun cepte olduğunu anlamaya yardım eder.
  - Barometre atmosfer basıncını ölçer; yükseklik ve GPS doğruluğunun artırılması, binada kat tespiti, basınç değişimine duyarlı kişilere uyarı gibi amaçlarla kullanılabilir (ekrandan, 02:30:00).
  - Telefon içindeki sıcaklık sensörü ortamı değil daha çok cihazın sıcaklığını ölçer.

## Hocanın Özellikle Vurguladığı Kısımlar

- Serbest düşen telefonun ivmeölçeri yaklaşık sıfır gösterir
  - Hoca bu soruyu her yıl soruyor ve çoğu kişi 9 küsur diyor. Doğru cevap sıfırdır, çünkü telefon yerçekimiyle birlikte hareket eder. Yerçekiminden arındırılmış lineer ivmeölçer kullanılsaydı sonuç farklı olurdu.
- Pencere örtüşme oranı ve pencere boyutu
  - %40-%60 örtüşme ve temel aktivitelerde 3-5 saniyelik pencere, hocanın kendi çalışmalarında da en iyi sonucu verdi.
  - Pencere boyutu tanınmak istenen aktiviteye göre seçilir.
- Kalibrasyon
  - Sensörle çalışırken mutlaka kalibrasyon yapılmalıdır. Hocanın ekibinin eski bir telefonla yaptığı çalışmada bir eksenin 9,81 yerine yaklaşık 8,81 göstermesi başarısız sonuçlara yol açmıştı. Android bazı sensörler için kalibre edilmiş ve edilmemiş (uncalibrated) iki değer sunar.
- Filtreleme
  - Küçük sensör komponentlerinin aralığı dar, hata oranı daha yüksektir. Sensör verisinde mutlaka filtre kullanılmalıdır; genelde low-pass (örneğin Butterworth) tercih edilir, high-pass uç değerleri öne çıkardığı için pek kullanılmaz.
- Aynı anda gerçekleşen aktiviteler açık bir araştırma problemidir.
- Cross-platform ile native arasındaki temel fark kaynak tüketimidir.

## Kısa Tekrar Notları

- iOS: kontrollü, güvenli, enerji verimli; güncelleme her cihaza aynı anda. Android: çok üretici, parçalı güncelleme, daha büyük market.
- Doze: kullanılmayan telefonda arka plan servislerini seyrekleştirir.
- Araç tespiti: konumdan hız; araçta olmak telefonu kullanmak demek değildir.
- Eşzamanlı aktivite: frekans domeni öznitelikleri, çoklu pencere boyutu, önceki pencerelerle ilişki, saat+telefon.
- Overlap ratio %40-%60, pencere 3-5 s (temel aktiviteler); araç türü için 8-32 s veya daha uzun.
- FFT maliyeti: ikinin kuvveti uzunluk maliyeti azaltır.
- Düşme tespiti: çift eşik + aradaki değerler için makine öğrenmesi.
- Geliştirme teknikleri: native (en iyi UX), cross-platform (hız/maliyet, kaynak tüketimi), hibrit (web kodu + native kapsayıcı, Cordova), mobil web (en geniş erişim, HTML5).
- Serbest düşmede ivmeölçer ≈ 0; düz zeminde her eksende ≈ 9,81 m/s² testi.
- Sensör verisi: kalibrasyon ve low-pass filtre.
- Proximity benzeri mesafe sensörleri: ultrasonik, lazer, radar.

## Detaylı Açıklamalar

- **Pencereleme.** Sensörlerden akan sürekli veri zaman ekseninde pencerelere bölünür ve her pencere için bir aktivite kararı verilir. Hoca bunu tahtada ivmeölçer x/y/z, jiroskop ve manyetometre satırlarından oluşan bir zaman çizelgesiyle gösterdi (ekrandan, 00:35:00). Bir öğrenci pencerenin en küçük birim kadar kaydırılmasını önerdi; hoca bunun teorik olarak hiçbir şeyi kaçırmadığını ama çok maliyetli olduğunu söyledi. Pratikte ikinci pencere birincinin bir kısmıyla örtüşecek şekilde kaydırılır ve bu oran örtüşme oranıdır. Örtüşme olmazsa iki pencerenin sınırında başlayan bir hareket kaçırılabilir. Literatürde ve hocanın deneyiminde %40-%60 örtüşme ile 3-5 saniyelik pencere temel aktivitelerde en iyi sonucu verir. Bir saniyelik pencere yalnız hareketin bir parçasını görür; beş saniyeden uzun pencere ise üç saniye yürüyüp oturan kişinin iki aktivitesini birbirine karıştırır.
- **Aynı anda iki aktivite.** Otobüs içinde yürüyen biri için iki hareket üst üste biner. Bir öğrencinin önerisiyle hareketlerin farklı frekans bantlarında iz bıraktığı, frekans domeni öznitelikleriyle ayrılabileceği konuşuldu. Bir başka öneri, aracın bilinen titreşimini veriden çıkarıp kalanı yürüme/koşma açısından değerlendirmekti. Hoca buna ek olarak iki farklı pencere boyutunu aynı veride gezdirmeyi önerdi: büyük pencere aracın uzun döngüsünü (kalkış, hızlanma, durma), küçük pencere yürüme gibi kısa periyotlu hareketi yakalar. Hoca bu yaklaşımla karşılaşmadığını ama uygulanabilir bulduğunu söyledi.
- **Düşme tespitinde çift eşik.** Tek bir eşik düşmeyi düşme olmayan sert hareketlerden ayıramayabilir. Çift eşikte üst eşiğin üstü kesin düşme, alt eşiğin altı kesin düşme değil diye etiketlenir. Aradaki değerlerin olduğu pencere sendeleme, düşme ve yerde hareketsiz kalma örüntüsünü içerip içermediğine göre bir makine öğrenmesi yöntemiyle incelenir. Hoca bunun başarıyı belirgin biçimde artırdığını kendi çalışmalarında da gördüğünü söyledi.
- **Cross-platform ve kaynak tüketimi.** Cross-platform araçlarla yazılan kod bir yorumlama/dönüştürme adımından geçerek iOS ve Android kodu üretir. Hoca bunu derleyiciye benzetti: derleyici iyiyse elle assembly yazmaya gerek kalmaz, değilse üretilen kod yavaş ve büyük olur. Bu fark son yıllarda çok azalsa da hâlâ temel farktır. Mobil web ise tarayıcıda çalışır; hibrit uygulama aynı web teknolojileriyle yazılıp Cordova gibi bir araçla native bir kapsayıcıya sarılır ve markete konabilir.
- **Serbest düşme sorusu.** İvmeölçer yerçekimi dahil özgül kuvveti ölçer. Telefon masada dururken toplam büyüklük yaklaşık 9,81 m/s² olur; serbest düşmede telefon yerçekimiyle birlikte ivmelendiği için ölçülen değer sıfıra yakındır. Lineer ivmeölçer (yerçekimi çıkarılmış) kullanılsaydı sonuç farklı olurdu. Aynı mantıkla bir ivmeölçerin doğru çalışıp çalışmadığı, telefonu düz zemine farklı yönlerde koyup her eksende yaklaşık 9,81 okunup okunmadığına bakılarak test edilir.
- **Uyku analizi.** Uyku analizi ses (mikrofon), bilekteki nabız ve hareket ya da yastık altına konan telefonun hareket algılaması ile yapılır. Uyku evreleri için saat daha verimlidir. Uyku apnesinde horlama ve nefes seslerinin aralıkları önemlidir; burada ortam gürültüsü (yanındaki kişi, dışarıdaki araçlar, ev içi sesler) en büyük sorundur ve ses filtrelemesi gerekir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
