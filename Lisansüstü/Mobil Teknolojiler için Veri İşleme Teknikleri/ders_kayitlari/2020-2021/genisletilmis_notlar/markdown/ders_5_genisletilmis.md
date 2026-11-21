# Ders 5 Genişletilmiş Notu: Mobil Uygulamalar, Eşzamanlı Aktivite Tanıma, Pencereleme ve Mobil Cihaz Sensörleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. iOS ve Android: Farklar ve Benzerlikler
- 2. Pil Ömrü, Aktivite ve Araç İçinde Olmayı Anlamak
- 3. Aynı Anda Gerçekleşen Aktivitelerin Tanınması
- 4. Pencereleme (Windowing) ve Örtüşme Oranı
- 5. Telefonla Yapılan Aktiviteler ve Toplu Aktiviteler
- 6. Düşme Tespiti
- 7. Mobil Uygulama Kategorileri ve Uygulamaları Öne Çıkaran Etkenler
- 8. Mobil Uygulama Geliştirme Teknikleri
- 9. Mobil Cihazlardaki Sensörler
- 10. Kalibrasyon, Filtreleme ve Uyku Analizi
- 11. Mesafe Sensörleri, Işık Sensörü ve Barometre
- 12. Ders Sonunda Açılan Konular: Otonom Araçlar ve Overlay Ağlar

## 1. iOS ve Android: Farklar ve Benzerlikler

Ders, bir önceki hafta konuşulan mobil işletim sistemleri, PC ve sunucu işletim sistemleri ile mobil işletim sistemi tasarım kriterlerinin kısa bir hatırlatmasıyla başladı. Hoca, mobil uygulamaların çalıştıkları platforma ve işletim sistemine göre tasarlandığını, bu yüzden iOS ile Android arasındaki farkları bilmenin geliştirici için önemli olduğunu söyledi. Ekranda bir önceki haftanın slaytlarından mobil uygulama geliştirmenin kısıtları duruyordu: sınırlı pil; az kaynak (CPU, bellek, depolama, pil); menzil × bant genişliği; güvenlik standartları; olası tehlikeler (ekrandan, 00:10:00).

Hoca iOS'u şöyle tarif etti: donanım ve işletim sistemi birlikte ele alınmıştır, yapı tamamen kontrollüdür ve güvenlik öne çıkarılmıştır. Bu bütünlük donanımın verimli kullanılmasını ve iOS'ta pil tüketiminin toplamda daha verimli olmasını sağlar. Android telefonlarda da uzun kullanım süresi görülür, ama bu genelde pilin daha büyük olmasından kaynaklanır.

Ardından öğrencilerle bir tur yapıldı ve şu farklar toplandı:

- **Cihaz çeşitliliği ve güncellemeler:** Android çok sayıda farklı telefonda çalışmak zorundadır; iOS'ta cihazlar daha kısıtlı olduğu için daha özel işlemler yapılabilir. Hoca bunun sonucunu ekledi: iOS güncellemeleri desteklenen bütün telefonlara aynı anda ulaşır. Android'de ise üreticiler güncellemeyi kendi modifikasyonlarından ve lisans anlaşmalarından geçirdiği için her güncelleme her cihaza gelmez. Hocaya göre bu büyük bir handikaptır ve hâlâ çözülmüş değildir; bazı üreticiler belli bir sürüme kadar güncelleme garantisini satış argümanı olarak kullanır.
- **Önceden yüklü uygulamalar:** Android'de üreticilerin hazır yüklü uygulamaları olduğu için uyumluluk gerekir; iOS'ta hangi uygulamanın yüklü geleceği daha kontrollüdür, bu da güvenlik açısından avantaj sağlar.
- **Geliştirici maliyeti:** Bir uygulamayı markete koymak iOS tarafında daha yüksek ücretlidir, Android tarafında daha düşük ücretle yapılabilir.
- **Pil ve enerji verimliliği:** Bir öğrenci, Android telefonların pillerinin daha büyük olmasına rağmen iOS cihazların benzer süre dayandığını, bunun iOS'un enerjiyi daha verimli kullandığına işaret ettiğini söyledi. Sensörler için ayrı işlemciler kullanılması gibi etkenler yüzünden farkın tam oranı söylenemez.
- **Uygulama marketi:** iOS marketi daha kısıtlıdır, Android'de çok daha fazla uygulama vardır; son dönemde iOS tarafında önemli iyileştirmeler yapıldı.

### 1.1 Widget

**Soru:** iOS'un son sürümüne Android'den gelen önemli özellik neydi? Widget nedir?
**Cevap:** Widget'tır. Bir öğrenci widget'ı, uygulamayı açmadan ana ekrandan onunla etkileşim kurmayı sağlayan yapı diye tanımladı; genelde arka taraftaki bir servis katmanıyla iletişim kurar ve uygulamanın kendisi çalışmadığı için özellikleri sınırlıdır. Hoca tanımı, sık erişilen uygulamaların verisinin güncel halinin ana ekranda hızla görülmesini sağlayan yapı diye tamamladı.

Hoca widget'ın iOS'a gelmesinin çok uzun sürdüğünü, rekabetin 2007-2008'de başladığını hatırlattı. Gecikmenin nedeni yalnız patent anlaşmazlıkları değildir: her şeyi widget'a çevirmek kontrolün bir kısmını programcıya bırakmak ve işletim sisteminin performansını etkilemek demektir. Yine de yıllar içinde kullanıcı tercihleri bir çözüm bulunmasını gerektirdi.

## 2. Pil Ömrü, Aktivite ve Araç İçinde Olmayı Anlamak

**Soru:** Son 2-3 yılda iki işletim sisteminin de yeni sürümlerde vurguladığı problemler neler?
**Cevap:** Öğrencilerden iki cevap geldi: güvenlik (uygulama izinleri ve marketteki uygulamaların güvenliği) ve pil ömrü.

Pil ömrünün nasıl uzatıldığı sorulduğunda bir öğrenci Android'in Doze yöntemini anlattı: telefonun cepte olduğu ve kullanılmadığı anlaşılınca arka plan servislerinin yenileme sıklığı düşürülür, arka plandaki haberleşme azaltılır, servisler daha seyrek uyandırılır ya da uzun süre uykuya alınır. Amaç telefon kullanılmadığı sürece mümkün olan en yüksek enerji tasarrufudur. Hoca bunu anlamanın yolunun kişinin aktivitesini anlamak olduğunu vurguladı.

**Soru:** Telefonla hareket ederken araçta mı olduğumuzu, yoksa araçsız mı hareket ettiğimizi nasıl anlarız?
**Cevap:** Öğrenciler sallanmaya (yürürken telefon sallanır) ve konum değişikliğine (araçta hız farklıdır) bakılabileceğini söyledi. Hoca en önemli çözümün GPS, baz istasyonu ya da Wi-Fi üzerinden elde edilen konum değişikliğinden kişinin hızını çıkarmak olduğunu söyledi; GPS paketlerinde hız bilgisi de bulunur. Belli bir hız sınırının üstüne çıkıldığında araç hareketi tespit edilir. <!-- BELİRSİZ: Hocanın söylediği hız sınırı altyazıda anlaşılmıyor ("Saat olarak aşağı yukarı sınır belirleniyor"). -->

Hoca burada önemli bir ayrım yaptı: kişinin bir aracın içinde olduğunu anlamak, aracın içinde telefonu kullanıp kullanmadığını anlamak anlamına gelmez. Bu ayrım bir sonraki konuya, aynı anda gerçekleşen aktivitelere köprü oldu.

## 3. Aynı Anda Gerçekleşen Aktivitelerin Tanınması

Önceki derslerde aktiviteler basit ve kompleks diye ayrılmıştı. Hoca bunlara bir üçüncü grup ekledi: aynı anda gerçekleşen aktiviteler. İşin zor kısmı bunlardır. Örnekler: araba kullanırken telefonda konuşmak, telefonla mesajlaşmak, trende giderken trenin içinde yürümek, uçakta giderken uçak içinde yürümek, araç içinde yer değiştirmek, araçta oturur ya da ayakta olmak.

Mevcut çalışmalar çoğunlukla bir anda tek bir aktiviteyi anlamaya göre şekillenmiştir. Hoca, bir T anında bir kişinin birden fazla aktivite yaptığının telefon ya da saat kullanılarak anlaşılıp anlaşılamayacağını sordu ve bildiği kadarıyla bu problemi ele alıp çözen bir çalışma olmadığını söyledi.

Öğrencilerin ve hocanın önerdiği yaklaşımlar şunlardır:

- **Saat ve telefonu birlikte kullanmak:** Bir öğrenci, telefon cepteyken gövdeyle birlikte hareket ettiği için kol hareketinin saatle daha iyi yakalanacağını; ulaşım türünün telefondan, araç içindeki yürümenin saatten anlaşılabileceğini söyledi. Hoca iki cihazı birlikte kullanmanın büyük avantaj sağlayacağını kabul etti. Ancak tek bir kaynakla da yürüyüş tespiti zor değildir: cepte taşınan telefonda manyetometre, jiroskop ve ivmeölçer üçlüsüyle yürüme ve koşma çok yüksek başarıyla ayrılır. Ulaşım türü de aynı düşük enerjili sensörlerle yüksek başarıyla tanınır. Tekli ve ikili kombinasyonlara bakan çalışmalar olsa da üçlü kombinasyonun en iyi sonucu verdiği nettir.
- **Frekans bantları:** Bir öğrenci, iki hareketin farklı frekanslarda tepki oluşturduğunu, frekans bantlarını ayırarak bunların ayrılabileceğini önerdi. Hoca bunu güzel bir bakış açısı buldu.
- **Bilinen bileşeni çıkarmak ve zaman çizelgesi:** Bir başka öğrenci, tanınan bir aktivitenin üstüne yeni bir aktivite geldiğinde ya onu tanımayı hedeflediğimizi ya da parazit veri saydığımızı söyledi. Örneğin trendeki titreşim biliniyorsa veriden çıkarılabilir; kalan sinyal yürüme mi koşma mı diye değerlendirilebilir. Hoca bunu, T anındaki aktiviteyi önceki T anlarındaki bilgilerle ilişkilendirmek, yani veriyi zaman çizelgesinde işlemek diye özetledi; bu sayede çıkarılan bağlamın daha zengin ve doğru olması beklenir.
- **Farklı pencere boyutları:** Hocanın kendi önerisi farklı pencere boyutlarını aynı anda kullanmaktır. Hangi araçta olunduğunu anlamak için pencere çok kısa olduğunda algoritma zorlanır. Genelde en az 8, 16 ya da 32 saniyelik veri gerekir; 16-32 saniye daha başarılıdır, bir dakikaya çıkıldığında aracın temel karakteristiği (hızlanma, yavaşlama, durakta durma gibi döngüsü) daha iyi yakalanır. Yürüme, koşma, oturma ve durma gibi aktiviteler ise daha kısa periyotlarla tekrarlanır. Bu yüzden büyük pencere seyrek ve uzun döngülü aktiviteyi, küçük pencere sık tekrarlanan aktiviteyi yakalayabilir. Hoca bu yaklaşımla aynı anda birden fazla aktiviteyi tanıma bağlamında karşılaşmadığını ama uygulanabilir bulduğunu söyledi.

Hoca frekans domeni özniteliklerinin bir maliyeti olduğunu da hatırlattı: frekans domenine geçmek için Fourier dönüşümü gerekir ve bu her pencere için bir işlem maliyeti getirir. Pencere uzunluğu ikinin kuvveti seçilirse bu maliyet azalır.

> **Ek bilgi (derste anlatılmadı):** Pratikte kullanılan hızlı Fourier dönüşümünün (FFT) en yaygın biçimi olan radix-2 algoritması uzunluğu ikinin kuvveti olan dizilerde çalışır ve karmaşıklığı $O(N \log N)$'dir. Doğrudan ayrık Fourier dönüşümü ise $O(N^2)$ işlem gerektirir. Hocanın "ikinin katları" önerisi bu yüzdendir.

## 4. Pencereleme (Windowing) ve Örtüşme Oranı

Hoca, kişinin 2 saniyede ya da 10 saniyede hangi hareketi yaptığını anlamak için sürekli veriye mutlaka bir pencereleme uygulandığını söyledi. Pencereleme yalnız aktivite tanımada değil, zaman çizelgesindeki verinin parçalanıp analiz edildiği pek çok problemde kullanılır; sürekli verinin tamamını bir seferde analiz etme şansı yoktur, parçalar analiz edilip sonuçlar birleştirilir.

**Soru:** Bir hareketi kaçırmamak için pencerelemeyi uygularken neye dikkat etmeliyiz?
**Cevap:** Hoca soruyu şöyle somutlaştırdı: üç saniyeye bakıldı, kişi yürüyor; sonraki üç saniyede duruyor; sonraki üç saniyede koşuyor. Pencere bir dakikaya büyütülürse dakikanın 10 saniyesi oturma, 10 saniyesi ayağa kalkma olabilir ve çözünürlük kaybolur. Bir öğrenci pencerenin farklı geçişleri yakalayacak şekilde seçilmesi gerektiğini, çok küçük seçilirse de (saniyede bir) gereksiz tekrara düşüleceğini söyledi. Bir başka öğrenci kişiye etkiyen kuvvetlerin belli bir frekansta kaydedilmesi gerektiğini önerdi.

### 4.1 Tahtadaki gösterim

Hoca ekranı tahta gibi kullandı (ekrandan, 00:35:00). Zaman çizelgesinde satırlar ivmeölçer x, ivmeölçer y, ivmeölçer z, jiroskop ve manyetometredir; her sensör üç eksende değer verir ve ivmeölçer x satırına örnek olarak 3.2, 2.1, 4.8 gibi değerler yazıldı. Bu satırlar üzerinde önce 3 saniyelik bir alan alındı ve ikinci pencerenin nereden başlaması gerektiği soruldu.

Bir öğrenci, pencerenin her seferinde en küçük zaman birimi kadar kaydırılmasını önerdi (tahtada "Window 1" ve "Window 2" diye çizildi). Hoca bunun hiçbir şeyi kaçırmamak için teorik olarak doğru yaklaşım olduğunu, ama maliyetinin çok yüksek olduğunu söyledi. İki pencerenin üst üste gelen kısmı örtüşmedir (overlap) ve kritik büyüklük örtüşme oranıdır (overlap ratio). Tahtadaki ikinci örnekte pencere yaklaşık %50 örtüşecek şekilde kaydırıldı.

Pencereler hiç örtüşmeden, keskin biçimde kaydırılırsa ve yeni hareket tam iki pencerenin sınırında gerçekleşmişse bu hareket yakalanamayabilir. Bu yüzden aktivite tanıma problemlerinde örtüşme oranı önem kazanır. Tahtaya yazılan değerler şunlardır (ekrandan, 00:35:00):

- Örtüşme oranı: %40 - %60
- Pencere boyutu (window size): 3-5 saniye

Hoca bu değerlerin yürüme, koşma, oturma, kalkma gibi temel aktiviteler için geçerli olduğunu, kendi yürüttüğü birçok çalışmada da literatürdeki bu önerinin en iyi sonucu verdiğini gördüğünü söyledi.

> **Hocanın vurgusu:** Pencere boyutunda çok önemli bir ödünleşim (trade-off) vardır. Pencere çok küçük olursa yeterli veri elde edilemez ve aktivite anlaşılamaz; bir saniyelik pencere hareketin yalnız bir alt parçasını gösterir, tamamının örüntüsü görülmez. Pencere çok büyük olursa çözünürlük kaybolur; örneğin beş saniyeden uzun bir pencerede üç saniye yürüyüp oturan kişinin iki aktivitesi birbirine karışır ve kullanıcıya yeterince ayrıntılı bilgi sunulamaz.

**Soru:** Daha iyi tanıdığımız aktiviteler için daha küçük, tam tanıyamadıklarımız için daha büyük pencere mi kullanılır?
**Cevap:** Hoca bunu düzeltti: ölçüt tanıma başarısı değil aktivitenin tekrar periyodudur. Yürüme gibi sık ve kısa döngülü aktiviteler için küçük pencere; aracın kalkması, hızlanması, sabit hızla gitmesi, yavaşlaması ve durakta durması gibi uzun döngülü aktiviteler için daha büyük pencere kullanılır. Yani pencere boyutu doğrudan tanınmak istenen aktiviteye bağlıdır. Hoca bu arada aktivitelerin "saf" hallerini tanımanın da önemli olduğunu ekledi.

## 5. Telefonla Yapılan Aktiviteler ve Toplu Aktiviteler

**Soru:** Aynı anda gerçekleşebilecek aktivitelere başka hangi örnekler verilebilir? Yalnız fiziksel hareket sensörleri mi kullanılır?
**Cevap:** Bir öğrenci Marmaray'da vagonlar arasında yürümeyi örnek verdi. Hoca araç içinde hareket etmeyi ve araçtaki duruş pozisyonunu (ayakta, oturarak, yaslanarak) ekledi. Fiziksel olmayan aktiviteler de vardır: telefon hangi pozisyonda, elde mi; telefonla konuşuluyor mu, mesajlaşılıyor mu, oyun oynanıyor mu, telefonda geziniliyor mu. Bunların her biri birer aktivitedir. Başka örnekler: koşarken ya da evde bir iş yaparken müzik dinlemek, (yolcu olarak değil) bizzat araba kullanırken bir şey yapmak, video izlemek, televizyon izlerken ya da biriyle konuşurken telefonu kurcalamak. Hoca bunların kolay algılanmasa da kişinin hayatına dair çok ipucu verdiğini söyledi.

**Soru:** Telefonla yapılan aktiviteleri sensör dışında nasıl anlayabiliriz?
**Cevap:** Bir öğrenci cihazın o anki durumuna bakılabileceğini söyledi: telefon görüşmesi sistemin yayınladığı ve alınabilen bir bilgidir. Doğrudan konuşma sırasında en çok proximity sensörü kullanılır; ama bu cebe konmuş telefonla karışabilir, bu yüzden cihazın yatay/dikey pozisyonu da eklenebilir. Hoca kritik noktanın sistem seviyesindeki olayların kaydedilip bilgi olarak kullanılması olduğunu söyledi. Ara sonrasında sohbetten gelen bir yorumla telefonun hotspot olarak kullanılması da bir durum olarak eklendi.

Hoca aynı anda yapılan aktivitelerin hangilerinin hangi başarıyla ve hangi yöntemle tespit edilebileceğine dair kapsamlı bir test çalışması gerektiğini, bunun uzun süredir aklında olan bir konu olduğunu söyledi.

### 5.1 Toplu aktiviteler ve ortam zekâsı

Ortam zekâsı (ambient intelligence, çevresel zekâ) bağlamında artık tek bir kişinin aktivitesi değil, çevredeki toplu aktiviteleri anlamak da önem kazanıyor. Bunun için daha çok kamera görüntüleri kullanılır: insan sayısı, o anda yapılan aktivitenin (örneğin bir halay ya da yürüyüş) anlaşılması, birlikte hareket eden grupların tespiti.

Hoca Singapur'dan bir örnek verdi. Ülke çok sıcak olduğu için insanlar zamanlarını klimalı kapalı alanlarda geçirir. Bir grup genç birlikte hareket ettiğinde, büyük olasılıkla GSM operatörleri grup hareketini telefon sinyallerinden algılıyor ve gruba "3 pizza alana 2 pizza bedava" gibi bir mesaj gönderiliyor. Hoca bunun 4-5 yıl önceki bir örnek olduğunu, grup aktivitelerini anlayarak seçenek sunmanın pazarlamada geldiği noktayı gösterdiğini söyledi. Teknik zorluklar da vardır: sinyallerin kümelenmesi, paralel geçen iki grubun birlikte sayılması riski ve bir T anında birlikte olan kişilerin bir sonraki anda ayrılmış olabilmesi; bu yüzden ne kadar süre izlenmesi gerektiği önemlidir.

Bir öğrenci, baz istasyonlarında verinin belli aralıklarla kaydedildiğini, telefonların birden fazla baz istasyonuna bağlı olduğu için konumun nokta olarak bile kestirilebildiğini, saat ve konuma göre reklam gönderilebileceğini ekledi. Hoca son dönemde reklam stratejilerinin telefonlar üzerinden yürüdüğünü, bildirimlerin kişinin kullanım alışkanlıklarına göre farklı saatlere yayıldığını söyledi.

### 5.2 Deprem ve konum verisi

Hoca, GSM sinyallerinin KVKK kurallarına uygun biçimde, kişiden bağımsız ve anonimleştirilmiş olarak incelenmesiyle topluma katkı sağlanabileceğini söyledi. Örneğin deprem anında bir binada kaç kişi olduğu anonim konum verisinden otomatik olarak kestirilebilir; bu kurtarma çalışmalarını yönlendirebilir. Ancak etik sorunlar vardır: 3 kişilik bir bina yerine 30 kişilik binaya yönelme algısı ya da yaş bilgisine göre karar verilmesi. Hoca bunu otonom araçlardaki "insana mı hayvana mı çarpılacak, yolcuyu mu karşıdakini mi korumalı" ikilemine benzetti ve bu tür etik problemlerin otonom sistemlerde önümüzdeki yıllarda karşılaşılacak problemler olduğunu söyledi.

## 6. Düşme Tespiti

Ara sonrasında hoca, konuşulan bütün konuların mobil telefonlar ve giyilebilir cihazlarla takip edilebilecek aktiviteler olduğunu hatırlattı. Aktivite tanıma çalışmaları basit aktivitelerle başladı, ulaşım türü tanımayla devam etti; bir başka aktivite türü de düşme tespitidir (fall detection).

Düşme tespiti özellikle yaşlılar için kritiktir: düştüklerinde bayılabilir, bir yerlerini vurabilir ve yardıma ihtiyaç duyabilirler. Bir kaza ya da takılıp düşme sonrası yerde hareketsiz kalmak da benzer durumdur. Konu 2010'lu yıllarda çok çalışıldı ve çalışmaların çoğu ivmeölçer ve jiroskop kullandı.

İki yaklaşım vardır: eşik değer ve makine öğrenmesi. Eşik değer yaklaşımı basit bir kuraldır: bir ya da birden fazla `if` ile toplanan değerlerin bir eşiğin altında ya da üstünde olup olmadığına bakılır. Tek eşik çoğu çalışmada yetmez, çift eşik (double thresholding) uygulanır. Düşme tespitindeki sorun şudur: yüksek değerler kesin düşmeyi, düşük değerler kişinin hareketsiz ya da sorunsuz olduğunu gösterir; ama arada bir bölge vardır. Bu bölgedeki yüksekçe değerler düşmeden de, düşme olmayan başka bir aktiviteden de kaynaklanabilir.

Çift eşikte yüksek ve düşük değerler kesin olarak etiketlenir, arada kalan değerler daha ayrıntılı incelenir. Bunun için aradaki değerlerin bulunduğu bölgeye pencereleme uygulanır ve pencere bir makine öğrenmesi yöntemiyle örüntü açısından incelenir. Bu veri kişinin sendelemesini, düşmesini ve yerde yatmaya başladığı anı içerebilir; pencerenin bu örüntüye uyup uymadığına bakılır. Hoca bunun başarıyı oldukça yükselttiğini hem literatürde hem kendi çalışmalarında gördüğünü söyledi.

```text
Değer > üst eşik           -> kesin düşme
Değer < alt eşik           -> düşme yok
Alt eşik <= değer <= üst eşik -> pencereyi makine öğrenmesi ile incele
                               (sendeleme -> düşme -> yerde hareketsiz kalma örüntüsü)
```

Hoca düşme tespitinin büyük ölçüde başarıyla çözüldüğünü, bugün pek çok yerde acil servislere ya da aile bireylerine telefon üzerinden bildirim gönderildiğini söyledi. Kapalı mekân uygulamaları genelde videoyla yapılır; evde yalnız düşmeyi değil yaşlının başına gelebilecek başka aksilikleri de izlemek mümkündür. Dışarıda ise video imkânı yoktur, kişinin taşıdığı cihazdaki ivmeölçer ve jiroskop kullanılmalıdır. Yani iki temel yol vardır: videoyla ve taşınan cihazın sensörleriyle algılama.

Hoca son olarak uygulamaların konum ve sensör bilgisiyle pek çok karar verdiğini belirtti: banka uygulamasının saate göre "iyi akşamlar" demesi, telefonun ses seviyesini ya da bildirim modunu (titreşim gibi) otomatik değiştirmesi gibi.

## 7. Mobil Uygulama Kategorileri ve Uygulamaları Öne Çıkaran Etkenler

Hoca slaytta mobil uygulama kategorilerini gösterdi. "En sık hangi kategorideki uygulamaları kullanıyorsunuz?" sorusuna verilen cevaplar şöyleydi (ekrandan, 01:15:00):

| Kategori | 2012 (N=933) | 2014 (N=1181) |
|---|---|---|
| Social | %76 | %79 |
| Music | %72 | %74 |
| Games | %53 | %47 |
| Navigation | %48 | %57 |
| Entertainment | %47 | %52 |
| Photography | %38 | %52 |
| UCF Apps | %24 | %38 |
| Books | %19 | %27 |
| Reference | %17 | %39 |

Birden fazla seçenek işaretlenebildiği için yüzdelerin toplamı 100'ü geçer. Sonraki slaytta 2015'te en hızlı büyüyen kategoriler (2014'e göre uygulama oturumlarındaki yıllık artış) görünüyordu: kişiselleştirme (personalization) %332, haber ve dergiler %135, araçlar ve verimlilik %125, yaşam tarzı ve alışveriş %81 (ekrandan, 01:15:00).

Hoca kategorilerin yıllar içinde pek değişmediğini, birinin öne geçip diğerinin gerilediği iniş çıkışlı bir grafik olduğunu söyledi. Sorduğu soru şuydu: hâlâ benzer tipte uygulamalar üretiliyor; yeni gelen uygulama (örneğin Skype'tan sonra Zoom, sonra Google Meet) pazarlamayı bir kenara bırakırsak teknik olarak neyi değiştirerek öne geçiyor?

### 7.1 Kullanıcı deneyimi ve davranış analizi

İlk cevap kullanılabilirlikti. Hoca kullanıcı deneyiminin (UX) çok önemli olduğunu söyledi: butonun nerede duracağı, kaç buton olacağı, switch mi, toggle mı, açılır liste mi, radyo buton mu kullanılacağı, kullanıcıya kaç işlem yaptırılacağı, öğelerin ekranın altında mı üstünde mi olacağı. Ekran alanı kısıtlı olduğu için ekran kullanımı çok önemlidir. Hoca iPhone'daki yalnız sessize alma işi gören fiziksel tuşu, tasarımın kullanıcı deneyimine göre belirlendiğine örnek verdi.

**Soru:** Bir kullanıcının ekranı nasıl kullandığını ve hangi bölgeye odaklandığını incelemenin yolu var mı?
**Cevap:** Parmak hareketlerinden. Hoca Android'de dokunmatik ekranın hangi bölgesine dokunulduğu bilgisine erişilerek parmak hareketlerinin analiz edilebildiğini, ancak bunun belirli izinlere bağlı olduğunu söyledi. Bilgisayarda da bir kişinin videoyu nerede duraklattığı, ne kadar beklediği, kaçıncı dakikadan başladığı, baştan sona mı atlayarak mı izlediği gibi davranışsal analizler yapılır. Telefonda uygulama kullanım sıklığı ve süresi de işletim sistemleri tarafından rapor olarak gösterilir ("bu hafta geçen haftaya göre %20 daha fazla ekran kullandın" gibi). Hoca davranışsal analizin önümüzdeki dönemde çok dikkat çekeceğini söyledi.

**Soru:** Davranış analizinin çıktıları nerede kullanılabilir?
**Cevap:** Bir öğrenci deneyimin kişiselleştirilmesinde kullanıldığını söyledi; kullanıcıların ihtiyaçları farklı olduğu için herkese aynı deneyimi sunmak yerine özelleştirilmiş deneyim sunulur. Google Analytics gibi araçlarla kullanıcının hangi akışı izlediği, ne kadar sürede yaptığı, nereye dokunduğu ve hangi varsayılan seçenekleri değiştirdiği kaydedilip iyileştirme yapılabilir.

### 7.2 Zaman çizelgesi verisi için derin öğrenme

Hoca bu verilerin bir zaman çizelgesinde ve birbirleriyle ilişkili olarak incelenmesi gerektiğini söyledi ve bunun için derin öğrenmede hangi modelin uygun olduğunu sordu. Cevap tekrarlayan sinir ağlarıdır (recurrent neural network, RNN); bunların içinde LSTM ve GRU gibi alt türler vardır. Aktivite tanımada da bir hareketten sonra hangi hareketin geleceği sisteme öğretilebilirse zaman çizelgesindeki bilgi daha etkili kullanılır ve tanıma başarısı artar. Bu yüzden verinin önceki pencerelerle ve pencere içindeki önceki verilerle ilişkisi belli olan bu tür problemlerde LSTM/RNN yaklaşımları tercih edilir.

> **Ders sonrası not:** Hoca LSTM ve GRU'yu RNN'in giderek gelişmiş versiyonları olarak sıraladı ve bunların 2000'lerin başına dayandığını söyledi. Doğrusu büyük olasılıkla şöyledir: LSTM 1997'de önerildi; GRU ise 2014'te LSTM'nin daha az kapılı, sadeleştirilmiş bir çeşidi olarak önerildi.

Hoca makine öğrenmesinden sonra derin öğrenmenin bir trend olduğunu, ama önümüzdeki yıllarda modellerin özelleşmesi gerekeceğini söyledi. Keras'ın daha kısıtlayıcı, TensorFlow'un ağ tasarımında daha esnek olduğunu belirtti. Hazır yapıları kullanmak yerine üzerinde çalışılmış, düzenlenmiş ya da baştan tasarlanmış ağlar ve hiperparametre ayarı (fine tuning) önümüzdeki on yılın dikkat çeken konuları olacak; çünkü hazır araçlarla başarı bir yere kadar gelir.

### 7.3 Doğru zaman, teknoloji ve hedef kitle

Bir öğrenci Zoom'un pandemi başında çok sayıda kişiye görüşme imkânı sunarak öne geçtiğini, diğer araçlarda kullanıcı sınırı olduğunu söyledi. Hoca Zoom'un ihtiyaç anında doğru noktada çıkmasının kritik olduğunu kabul etti; teknolojinin, protokollerin ve API'lerin zamanla değiştiğini, uygulamayı yeni bir teknolojiyle yazmanın görsel ve teknik performansı yükselttiğini söyledi. Aynı anda bağlanabilen kişi sayısı Skype'ta bir sınırdı; Zoom bu altyapıyı sağladı.

Anlık mesajlaşmada WhatsApp dışında Telegram örneği konuşuldu: Telegram'ın daha fazla özelliği olduğu, ilk dönemde daha güvenilir bulunduğu söylendi. Hoca çok kullanılan platformun daha çok saldırıya maruz kaldığını Windows örneğiyle açıkladı. Öte yandan çok fazla özellik eklemek uygulamayı karmaşıklaştırır, performansı düşürür ve kullanıcıların dağılıp platformu terk etmesine yol açar.

Hoca uygulamaların dünyanın farklı bölgelerinde farklı kullanıldığını (bir bölgede X, diğerinde Y uygulaması) ve bunun oyun sektöründe çok gözlendiğini söyledi. Uygulama tasarlarken coğrafyanın özellikleri ve hedef kullanıcılar (öğrenciler, çalışanlar, yaşlılar, küçük çocuklar) dikkate alınmalıdır. Sistem analizi, ihtiyaç analizi ve fizibilite çalışmasında bunlar ne kadar kapsamlı irdelenirse uygulamaların o kadar tuttuğu görülüyor.

Son olarak işletim sistemlerine doğrudan eklenen, indirilmeden gelen uygulamalar konuşuldu. Bir öğrenci üreticilerle işbirliğiyle gelen hazır uygulamaları ve işletim sisteminin parçası olan ekran kaydı, ses kaydı gibi uygulamaları saydı. Hoca her iki işletim sisteminde de kişiselleştirmenin ve ek uygulamaya gerek kalmadan hareket takibinin öne çıktığını, pandemiyle eğitim uygulamalarının arttığını söyledi.

## 8. Mobil Uygulama Geliştirme Teknikleri

Slaytta uygulama geliştirme türleri bir diyagramla gösterildi: native app, generic app, cross-platform app, dedicated app, hybrid app ve bookmark app (ekrandan, 01:30:00). Hoca anlatımı dört temel yaklaşım üzerinden yaptı:

- Native geliştirme
- Cross-platform araçlarla geliştirme
- Hibrit uygulama geliştirme
- Mobil web geliştirme

> **Ders sonrası not:** Altyazıda hoca ilk yaklaşımı "Native Web Development" diye adlandırıyor gibi görünüyor; anlatımın devamından bunun native (yerel) geliştirme olduğu anlaşılıyor.

### 8.1 Mobil web geliştirme

**Soru:** Bu dört teknikten en fazla kullanıcıya ulaşma şansı olan hangisi?
**Cevap:** Öğrenciler önce cross-platform dedi. Hoca cevabın mobil web geliştirme olduğunu açıkladı. Yeni nesil web uygulamalarında tasarım ekran boyutuna göre şekil alır (responsive design). Kullanıcı uygulamayı indirmeden, markete girmeden, tarayıcıdan ya da aramadan doğrudan erişir. Bu yüzden PC, tablet ve telefondan en fazla kullanıcıya ulaşılır. Ama her uygulama mobil web ile geliştirilemez.

Mobil webin bu kadar öne çıkmasını sağlayan teknoloji sorulduğunda bir öğrenci Flutter dedi; hoca kendi gözünde cevabın HTML5 olduğunu söyledi. HTML5, eskiden HTML'in yapamadığı pek çok özelliği (özellikle multimedya) tarayıcının içine getirdi, Adobe Flash'ın sunduğu özelliklerin çoğunu sağlayıp onun yavaşlatan yanlarını devre dışı bıraktı ve Flash'ın yerini aldı.

**Soru:** Mobil webin güvenlik seviyesini ne belirler?
**Cevap:** Bir öğrenci kullanılan SSL/TLS protokollerinin ve varsa özel yazılmış protokollerin belirlediğini söyledi; hoca bunu onayladı, çünkü uygulama sonuçta tarayıcı üzerinde çalışır.

### 8.2 Native geliştirme

**Soru:** Kullanıcı deneyimi en yüksek olan geliştirme tekniği hangisi?
**Cevap:** Native. Platforma yönelik çerçeveyi Android ya da iOS'un kendisi sunar; SDK'lar (software development kit) kullanılarak cihazın bütün yetenekleri kullanılabilir. Diğer yaklaşımlar donanım yeteneklerini sınırlı kullanır.

### 8.3 Cross-platform geliştirme

Hoca cross-platform araçların son dönemde çok geliştiğini ve pek çok durumda daha avantajlı olduğunu söyledi. Birinci neden hızdır: tek kodla aynı anda birden fazla platforma kod üretilir ve markete çabuk çıkılır. İkinci neden maliyettir: C# ya da JavaScript/HTML bilen geliştirici bulmak kolaydır; native taraf için Swift/Objective-C ya da Kotlin bilen geliştirici bulmak daha zordur (Kotlin ve Java görece daha kolaydır).

Slayttaki cross-platform araçların avantajları şunlardır (ekrandan, 01:40:00):

- Gereken becerilerin azalması: ortak programlama dilleri kullanıldığı için.
- Kodlamanın azalması: kaynak kod bir kez yazılır ve desteklenen her işletim sistemi için derlenir.
- Geliştirme süresinin ve uzun vadeli bakım maliyetinin azalması.
- API bilgisi ihtiyacının azalması: her işletim sisteminin API'sini değil, yalnız aracın sunduğu API'leri bilmek yeterlidir.
- Her işletim sistemi için native uygulama yazmaya göre daha kolay geliştirme.
- Pazar payının artması ve yatırım getirisinin (ROI) yükselmesi.

**Soru:** Cross-platform'un en büyük sıkıntısı nedir?
**Cevap:** Öğrenciler donanım kaynaklarına erişim sorunlarını, aracı sağlayan firmaya bağımlılığı ve güvenlik sorunlarını söyledi. Hoca bunların doğru olduğunu, araya bir katman daha girdiği için güvenilirliğin o katmanı üreten firmanın yazılım kalitesine bağlı olduğunu ekledi. Ama asıl temel fark kaynak tüketimidir.

Cross-platform ile geliştirilen uygulamada bir yorumlama/dönüştürme adımı olmak zorundadır ve bunun sonunda iOS ve Android tarafında kod üretilir. Bu kod elle yazılsaydı çok daha verimli olabilirdi; sonuç, dönüştürmenin ne kadar sofistike yapıldığına bağlıdır. Hoca bunu derleyiciye benzetti: derleyici iyiyse assembly seviyesinde bir şey yapmaya gerek kalmaz; iyi değilse makine diline çevrilen kodun verimliliği düşer. Cross-platform ile üretilen kod genelde daha büyük boyutludur. 5-6 yıl önce ciddi performans ve kullanıcı deneyimi farkı vardı (butonların görünümü native görünümü tutmuyordu); bu fark son dönemde çok iyileşti.

Cross-platform ile üretilmiş uygulama örneği olarak öğrencilerden Instagram geldi ve hoca onayladı; Facebook'un da cross-platform bir yapı geliştirdiği söylendi. <!-- BELİRSİZ: Altyazıda "Facebook'ta bildiğim kadarıyla. Kurs Plattformu etmiş" deniyor; büyük olasılıkla React Native kastediliyor. --> Hoca sonuçta uygulamanın ihtiyaçlarının, donanım kullanma ihtiyacının ve performans gereksiniminin hangi yöntemin seçileceğini belirlediğini vurguladı.

Cross-platform araç seçim kriterleri olarak hoca şunları saydı: desteklenen mobil işletim sistemleri (bugün Android ve iOS'u desteklemek yeterli görünüyor), araç lisanslarının koşulları, çok kullanılan programlama dillerinin desteklenmesi ve native taraftaki API'lerin desteklenmesi. Dil konusunda örnek verdi: C# ile yazmayı sağlayan Xamarin akıllıca bir seçimdir, çünkü C# bilen çok kişi vardır; Go gibi az bilinen bir dille cross-platform araç yapmak mantıklı olmaz. Slayttaki araç listesinde Xamarin ve Corona gibi isimler vardı.

### 8.4 Hibrit uygulama geliştirme

**Soru:** Hibrit uygulama geliştirme nedir?
**Cevap:** Bir öğrenci, kodun temelini cross-platform yazıp bazı yerlerde platformun özel performans arttırıcı kodlarını kullanmak olduğunu tahmin etti. Hoca adın bunu çağrıştırdığını ama doğru olmadığını söyledi; arka plandaki yorumlayıcının kaldırılması tahmini de doğru değildi.

Hocanın tarifi şöyledir: hibrit uygulama HTML5, CSS ve JavaScript gibi teknolojilerle, tarayıcıda çalışacakmış gibi kodlanır. Cordova gibi hibrit platformlar bu kodu bir paket haline sarar (wrapping); uygulama sanki native bir uygulamaymış gibi markete yüklenebilir ve oradan indirilebilir. İndirilen uygulama WebKit denilen motor üzerinde ilgili HTML, CSS ve JavaScript kodlarıyla çalışır. Temel farkı budur: uygulama bir tarayıcıda çalışacakmış gibi tasarlanır, ama normalde markete konamayacak bu kod native bir kapsayıcı (native container) içine alınarak markete konur. Hoca hibrit uygulamaların bir dönem çok popüler olduğunu, artık eskisi kadar kullanılmadığını söyledi.

## 9. Mobil Cihazlardaki Sensörler

İkinci aradan sonra yeni slayt destesine geçildi: "Sensors on Mobile Devices - BLM5134 Week 5" (ekrandan, 02:00:00). Hoca amacın çevreden hangi verilerin toplanabildiğini, bunların birimlerini ve çözünürlüklerini görmek olduğunu söyledi.

Slayttaki sensör türleri listesi şöyledir (ekrandan, 02:20:00): ivme/titreşim, akustik/ultrasonik, kimyasal/gaz, elektrik/manyetik, akış, kuvvet/yük/tork/gerinim, nem/rutubet, sızıntı/seviye, makine görüşü, optik, hareket/hız/yer değiştirme, konum/varlık/yakınlık, basınç, sıcaklık.

Öğrencilerle telefonlardaki sensörler sayıldı:

- Jiroskop, ivmeölçer ve manyetometre: Hoca bu üçünün artık telefonlarda varsayılan olarak geldiğini, hareket takibini kolaylaştırdığı için giyilebilir cihazlarda da bulunduğunu söyledi.
- Işık sensörü ve kameralardaki uzaklık (derinlik) sensörleri; derinlik kamerası ve kamera da sensör sayılır.
- GPS.
- Barometre (basınç): her telefonda yoktur.
- Mikrofon.
- Parmak izi sensörü; buna benzer biyometrik sensörler olarak iris ve nabız sensörü. Nabız sensörü son dönemde özellikle saatlerde öne çıktı.
- Kandaki oksijen miktarını ölçen sensör: Bir öğrencinin hatırlattığı gibi pandemiyle akıllı saatlere geldi. Hoca, eskiden ayrı sensör yokken parmağı kameraya koyarak yaklaşık bir nabız değeri ölçüldüğünü, zamanla biyometrik sensörlerin öne çıktığını söyledi.
- Sıcaklık sensörü: Bir öğrenci cihazdaki sıcaklık sensörlerinin daha çok işlemci ve bellek sıcaklığı için kullanıldığını söyledi. Hoca telefonun bileşenleri birbirine çok yakın olduğu için ortam sıcaklığının ölçülemediğini, daha çok cihazın sıcaklığına göre frekansla oynanıp cihazın koruma moduna alındığını ekledi. Nem ölçer de bazı cihazlarda vardır.
- Dokunmatik ekran: Kapasitif ve rezistif olmak üzere iki yapı vardır, artık daha çok kapasitif kullanılır. Hangi noktaya dokunulduğunun yanında son dönemde hangi şiddetle dokunulduğu da algılanıyor ve bu yeni nesil telefonlarda ek kontrol imkânı sağlıyor.
- Ortam ışığını lüks cinsinden ölçen ışık sensörü.

Kızılötesi ve Bluetooth gibi bileşenler doğrudan fiziksel sensör değildir; hoca bunların sanal sensör olarak karşımıza çıkacağını söyledi.

Bir öğrenci, suya dayanıklı telefonların ilk çıktığı dönemde cihaza bastırıldığında barometredeki basıncın yavaş değişip değişmediğine bakılarak sızdırmazlığın test edildiğini anlattı. Hoca barometreye Singapur'dan bir örnek ekledi: alışveriş merkezlerinde kişilerin kat değişimi basınç değişikliğinden takip ediliyor; asansörle ya da merdivenle bir üst kata çıkıldığında kaçıncı katta olunduğu tespit edilebiliyor. Hoca barometrenin yaygın kullanılmasa da karar vermede pek çok noktada faydalı olduğunu düşünüyor.

### 9.1 Işık ve proximity sensörünün enerji tasarrufundaki rolü

Hoca ışık sensörünün çok basit ama enerji tasarrufunda çok kritik olduğunu söyledi: ortam ışığını algılayıp ekran parlaklığını ona göre ayarlar ve ciddi tasarruf sağlar. Proximity sensörü de öyledir: telefon kulağa götürüldüğünde ekranı kapatarak hem enerji tasarrufu sağlar hem yanlış tuşa basılmasını engeller. Proximity sensörüyle telefonun cepte ya da çantada olduğu da anlaşılabilir.

**Soru:** Telefon ne kullanılıyor ne de cepte; masanın üzerinde boşta duruyor. Proximity sensörü bir yakınlık üretmeyeceği için telefon kullanımdaymış gibi görünebilir. Boşta durduğunu nasıl anlarız?
**Cevap:** Bir öğrenci son etkileşim zamanına bakılabileceğini söyledi (ekran zaman aşımı gibi, 15-30 saniye). Hoca bunun bir yol olduğunu, ikinci yolun ivmeölçer değerine bakmak olduğunu söyledi. Telefonlarda iki tür ivmeölçer değeri vardır: normal ivmeölçer yerçekimi ivmesini de içerir; lineer ivmeölçer yerçekiminden arındırılmış ivmeyi verir.

### 9.2 Serbest düşen telefonun ivmeölçeri

**Soru:** Bir telefon yukarıdan bırakıldığında, düşme anında telefonun (normal) ivmeölçeri ne ölçer?
**Cevap:** Öğrencilerden farklı cevaplar geldi: sıfıra yakın; yerçekimine eşit ($g$); sensör aralığı sınırlıysa bir değerde takılır. Hoca doğru cevabın sıfır (sıfır küsur) olduğunu söyledi. Serbest düşme sırasında telefon yerçekimiyle birlikte hareket ettiği için telefona uygulanan ivme sıfır gibi görünür. Yerçekimi ivmesi çıkarılmış, yani lineer ivmeölçer kullanılsaydı değer değişirdi; ama soru yerçekimi dahil normal ivmeölçerin değeriyle ilgiliydi.

> **Hocanın vurgusu:** Hoca bu soruyu her yıl sorduğunu ve doğrudan "sıfır" diyen çok az kişi olduğunu, çoğu kişinin 9 küsur ya da biraz altı dediğini söyledi.

Python ile kontrol (ara adım eklendi): ivmeölçer özgül kuvveti, yani $\vec{f} = \vec{a} - \vec{g}$ değerini ölçer. $\vec{g} = (0, 0, -9{,}81)$ m/s² alınırsa:

- Telefon masada durgunken $\vec{a} = 0$, $\vec{f} = (0, 0, 9{,}81)$, büyüklük $9{,}81$ m/s².
- Serbest düşmede $\vec{a} = \vec{g}$, $\vec{f} = (0, 0, 0)$, büyüklük $0$.

**Soru:** Bir telefonun ivmeölçerinin doğru çalışıp çalışmadığını nasıl anlarız?
**Cevap:** Telefon düz bir yere farklı pozisyonlarda konur ve üç eksen ayrı ayrı kontrol edilir. Yerçekimi eksenindeki değer yaklaşık 9,81 m/s² gösteriyorsa sorun yoktur.

## 10. Kalibrasyon, Filtreleme ve Uyku Analizi

### 10.1 Kalibrasyon

Hoca 4-5 yıl önceki bir çalışmalarından bahsetti: eski bir telefonla yapılan çalışmada sürekli başarısız sonuç çıkıyordu. Sonunda telefonu kalibrasyon açısından test ettiklerinde bir eksenin 9,81 yerine yaklaşık 8,81 gösterdiğini gördüler. Hoca bunu yedek almaya benzetti: sensör kullanıyorsanız mutlaka kalibre etmelisiniz, yoksa çok tuhaf sonuçlarla karşılaşabilirsiniz. Aynı durum sağlıkta da geçerlidir: kalibre edilmemiş bir tansiyon aleti alakasız değerler üretebilir ve yanlış teşhise yol açabilir.

> **Hocanın vurgusu:** Sensörlerde kalibrasyon çok önemlidir; neye göre ve nasıl kalibrasyon yapılacağı da önemlidir. Android bazı sensörler için iki tür değer sunar: kalibre edilmiş (calibrated) ve kalibre edilmemiş (uncalibrated). Telefonlarda iki veriye de erişilebilir.

### 10.2 Akıllı saatlerdeki sensörler

Akıllı saatlerde nabız ölçer ve ivmeölçer sayıldı. Bir öğrenci son çıkan Android telefonlarda da nabız ölçer bulunduğunu söyledi; hoca iOS tarafında olmadığını belirtti. Hocaya göre nabız ölçer saatlerin satışı için kritiktir; telefondaki nabız ölçer genelde parmaktan ölçer ve hocanın bildiği kadarıyla bilekten alınan ölçüm daha doğru ve tutarlıdır (hoca bunun teyit edilmesi gerektiğini de söyledi). Sensörlerin maliyeti çok düştüğü için Android üreticileri bunları telefona da koyuyor.

### 10.3 Küçük sensörlerin hatası ve filtreleme

Hoca telefondaki sensörlerin çok küçük bileşenler olduğunu söyledi. Daha büyük cihazlardaki karşılıklarının doğruluğu genelde daha yüksektir; bileşen küçüldükçe ölçüm aralığı (range) daralır ve hata oranı artar. Yine de çok büyük bir iyileşme vardır; biyometrik sensör verileriyle hastanelerin aranabildiği bir güvenilirliğe gelinmiştir. Ama ölçümlerde hata oluşur.

**Soru:** Sensör verilerindeki hatayı azaltmak için ne kullanılır?
**Cevap:** Filtreleme. Hoca sensör verisiyle çalışırken mutlaka filtreleme yapılmasını önerdi. Genelde low-pass filtreler kullanılır; Butterworth filtreleri de kullanılır. High-pass filtreler uç noktaları daha da öne çıkardığı için pek tercih edilmez.

> **Ek bilgi (derste anlatılmadı):** Butterworth filtresi geçirme bandında dalgalanma (ripple) olmayan, mümkün olduğunca düz bir genlik yanıtı veren bir filtre tasarımıdır; low-pass, high-pass ya da band-pass olarak tasarlanabilir. Sensör verisinde low-pass filtre yüksek frekanslı gürültüyü bastırır.

### 10.4 Uyku analizi

**Soru:** Saatlerdeki uyku analizi (derin uyku gibi) nabız ölçerle mi yapılıyor?
**Cevap:** Hoca uyku analizi uygulamalarının çok arttığını ve farklı şekilde çalıştığını söyledi:

- Ses verisinden uyku analizi yapanlar.
- Bilekteki nabız ve hareket üzerinden ölçüm yapanlar.
- Telefonu yastığın altına koyup hareketi algılamaya çalışanlar (hocaya göre çok sağlıklı değil).

Uyku analizi artık akıllı saatlerle çok daha verimli yapılabiliyor. Uykuda bakılacak şeyler uykunun ne zaman başlayıp bittiği, derin uykuya geçiş, derin uykuda kalma süresi ve REM uykusudur; bunlarda hareketler ve nabız çok değerlidir.

Hoca bir hakem olarak incelediği bir projeden söz etti: mobil uygulamada mikrofonla kişinin uyku apnesi olup olmadığı anlaşılmaya çalışılıyordu. Uyku apnesinde horlama ve nefes alıp vermede çıkan ses ile bu seslerin aralıkları apnenin şiddetini belirler. Normalde bunun için laboratuvarda bir gece geçirmek ve pahalı cihazlarla ölçüm yapmak gerekir; bu cihazlar doktora teşhiste yardımcı olan bir karar destek sistemidir. Telefonla odadaki sesi dinleme fikri, kişinin evinde rahatça uyurken ucuz bir çözümle ölçüm yapmayı hedefler.

**Soru:** Uyku apnesini sesle tespit ederken karşılaşılan sorun nedir?
**Cevap:** Gürültülü veri. Yanında başka biri olabilir, dışarıdan araba sesleri gelebilir, evin içinde sesler olabilir. Bu seslerin bir kısmı horlama sesiyle karışır, bu yüzden ses filtrelemesi mutlaka gerekir. Hoca bir yüksek lisans çalışmasında belli bir oranda tespit yapabildiklerini, ama değerlerin hassas olduğunu (bir tarafı düzeltince derin uyku süresinin uzaması gibi) ve kişinin hareketlerinin de hesaba katılması gerektiğini söyledi. Yeni nabız ölçerlerle daha iyi sonuçlar beklediğini belirtti.

## 11. Mesafe Sensörleri, Işık Sensörü ve Barometre

### 11.1 Proximity sensörü

Slayttaki tanıma göre proximity sensörü yakındaki nesnelerin varlığını temas olmadan algılayabilen, kızılötesi bir LED ve bir IR ışık dedektöründen oluşan bir sensördür. Telefonun ahize kısmına yakın yerleştirilir; insan gözünün göremediği kızılötesi ışığı gönderir, ışık yakındaki bir nesneden yansır ve IR dedektörü tarafından algılanır (ekrandan, 02:25:00). Hoca proximity sensörünün yakınlık cinsinden bir mesafe döndürdüğünü, bunun bazen santimetre cinsinden, bazen de yakın/orta/uzak gibi üç kategori olarak verildiğini söyledi.

**Soru:** Proximity sensörüyle aynı amaçla çalışan, telefonda olmak zorunda olmayan başka hangi sensörler var?
**Cevap:** Ultrasonik, lazer ve radar. Bunların farklı menzilleri ve güçleri vardır. Ultrasonik sensörler en çok araçlarda, özellikle park sırasında görülür.

### 11.2 Işık sensörü ve barometre

Işık sensörü ortam ışığının parlaklığını lüks cinsinden ölçer ve telefonların çoğunda varsayılan olarak bulunur. Slaytta üst seviye Samsung Galaxy telefonların beyaz, kırmızı, yeşil ve mavi ışığı ayrı ayrı ölçebilen gelişmiş bir ışık sensörü kullandığı da yazıyordu (ekrandan, 02:30:00).

Slayta göre üst seviye telefonlarda yerleşik bir barometre bulunur; atmosfer basıncını ölçer. Ölçülen veri cihazın deniz seviyesinden yüksekliğini belirlemek için kullanılır, bu da GPS doğruluğunu artırır (ekrandan, 02:30:00).

**Soru:** Barometrenin birimi nedir?
**Cevap:** Öğrenciler atmosfer, bar ve paskal dedi. Altyazıda hocanın kesin bir cevabı yok.

> **Ders sonrası not:** Derste kesin cevap verilmedi. Basıncın SI birimi paskaldır (Pa); Android'deki basınç sensörü büyük olasılıkla hektopaskal (hPa), yani milibar cinsinden değer döndürür.

**Soru:** Barometre başka nerede kullanılabilir?
**Cevap:** Yükseklik ve bulunulan pozisyonun belirlenmesi. Hoca günlük hayattan bir örnek ekledi: yüksek ya da alçak basınçta (örneğin lodosta) sağlık sorunu yaşayan kişiler vardır; barometre basınç değişimini algılayıp kişiyi uyarabilir ya da öneride bulunabilir. Hava durumu için de kullanılabilir, ama bu tür veriler artık API'lerden alınabildiği için telefonda bu yaklaşım çok gerekli değildir.

## 12. Ders Sonunda Açılan Konular: Otonom Araçlar ve Overlay Ağlar

Ultrasonik sensörlerden yola çıkarak hoca otonom araçlara kısaca değindi. Otonomluk seviyeleri Level 1'den Level 5'e kadardır; Level 5'te bütün kararları araç verir ve hocaya göre bunu 2040'lardan önce görmemiz olası değildir. Hoca aracın kendi kendine park edebilmesinin onu üçüncü seviye yaptığını ve Level 4'te acil durumda kontrolün kullanıcıya bırakıldığını söyledi. Aracın karar veremediği kritik anda kontrolü birden sürücüye vermesinin ("al, direksiyon sende") sürücü için çok zor bir durum olduğunu vurguladı.

> **Ders sonrası not:** Hoca kendi kendine park etmenin aracı üçüncü seviye yaptığını ve Level 4'te acil durumda kontrolün sürücüye bırakıldığını söyledi. SAE J3016 tanımına göre doğrusu büyük olasılıkla şöyledir: sistemin sürüşü yapıp gerektiğinde sürücüden devralmasını istediği seviye Level 3'tür (koşullu otomasyon). Level 4'te araç tanımlı çalışma alanında sürücünün müdahalesine ihtiyaç duymaz. Otomatik park özelliği tek başına Level 3 tanımı değildir.

Hoca dronlar ve otonom araçların önümüzdeki dönemin ciddi çalışma alanları olacağını, savunma sanayindeki gelişmelerin zamanla tıp gibi sivil alanlara yansıdığını söyledi.

Dersin sonunda öğrencilerin ilgi duyduğu konular soruldu. Otonom araçlar ve cihazların internete bağlanmadan Bluetooth ya da Wi-Fi ile kendi aralarında ağ kurması (örneğin savaş ya da deprem gibi altyapının çöktüğü durumlarda haberleşme) gündeme geldi. Hoca bu yapıya overlay ağ denildiğini söyledi: cihazlar birbirleri üzerinden hop mantığıyla bilgi paylaşır; bir tür sensör ağı ya da ad hoc ağ olarak da adlandırılabilir. Amaç altyapı çöktüğünde bilginin hızla yayılmasıdır. Bu konuda çalışmalar vardır ama günlük hayatta yaygın kullanımına henüz rastlanmadı. Bir öğrenci deprem anında Bluetooth ile 100-200 metre iletişim kuran uygulamalardan söz etti. Hoca en büyük sıkıntının engeller olduğunu söyledi: araya ne kadar çok duvar girerse Bluetooth'un menzili o kadar kısalır; bütün kablosuz haberleşmeler böyledir, ama sinyal gücü düşük olanlar daha çabuk etkilenir.

## Örnek Sorular

**1. (derste sözlü, 00:09:24)** iOS ile Android arasındaki temel farklar nelerdir?

> **Cevap (derste verildi):** iOS donanım ve yazılımın birlikte tasarlandığı kontrollü, güvenlik odaklı ve enerji verimli bir yapıdır; güncellemeler bütün desteklenen cihazlara aynı anda gider. Android çok üreticili olduğu için güncellemeler parçalıdır, hazır yüklü uygulamalarla uyumluluk gerekir; markete uygulama koymak daha ucuzdur ve market daha büyüktür.

**2. (derste sözlü, 00:17:37)** Telefonla hareket eden bir kişinin araçta mı olduğunu, araçsız mı hareket ettiğini nasıl anlarız? Bu bilgi kişinin araçta telefonu kullandığını gösterir mi?

> **Cevap (derste verildi):** GPS, baz istasyonu ya da Wi-Fi'den elde edilen konum değişikliğinden hız hesaplanır (GPS paketlerinde hız da vardır) ve belli bir hızın üstü araç hareketi sayılır. Araçta olmak telefonu kullanmak anlamına gelmez; bu ayrı bir aktivitedir.

**3. (derste sözlü, 00:19:39)** Bir T anında bir kişinin birden fazla aktivite yaptığı (örneğin otobüste yürüme) telefon ya da saatle anlaşılabilir mi? Hangi yaklaşımlar kullanılabilir?

> **Cevap (derste verildi):** Açık bir araştırma problemidir. Önerilen yaklaşımlar: saat ve telefonun birlikte kullanılması; frekans domeni öznitelikleriyle farklı frekans bantlarının ayrılması; aracın bilinen titreşiminin çıkarılıp önceki pencerelerle ilişki kurulması; aynı veride büyük (uzun döngülü araç hareketi için) ve küçük (yürüme gibi kısa periyotlu hareket için) pencerelerin birlikte kullanılması.

**4. (ekrandan, 00:35:00)** Sürekli sensör verisinde bir hareketi kaçırmamak için pencereleme nasıl yapılmalıdır? Temel aktiviteler için önerilen örtüşme oranı ve pencere boyutu nedir?

> **Cevap (derste verildi):** Pencereyi en küçük birim kadar kaydırmak hiçbir şeyi kaçırmaz ama çok maliyetlidir; örtüşmesiz kaydırmada iki pencerenin sınırına düşen hareket kaçabilir. Bu yüzden pencereler örtüştürülür. Önerilen örtüşme oranı %40-%60, temel aktivitelerde (yürüme, koşma, oturma, kalkma) pencere boyutu 3-5 saniyedir. Çok küçük pencerede yeterli veri olmaz, çok büyük pencerede çözünürlük kaybolur.

**5. (derste sözlü, 01:07:39)** Düşme tespitinde çift eşik nasıl uygulanır?

> **Cevap (derste verildi):** Üst eşiğin üstündeki değerler kesin düşme, alt eşiğin altındakiler düşme yok diye etiketlenir. Arada kalan değerlerin bulunduğu pencere sendeleme, düşme ve yerde hareketsiz kalma örüntüsü açısından bir makine öğrenmesi yöntemiyle incelenir.

**6. (derste sözlü, 01:16:04)** Kullanıcı davranışlarının zaman çizelgesinde ve birbirleriyle ilişkili olarak incelenmesi gerekiyorsa derin öğrenmede hangi model ailesi uygundur?

> **Cevap (derste verildi):** Tekrarlayan sinir ağları (RNN) ve bunların LSTM, GRU gibi türleri.

**7. (derste sözlü, 01:27:09 ve 01:29:50)** Dört mobil uygulama geliştirme tekniğinden hangisi en fazla kullanıcıya ulaşır, hangisi en yüksek kullanıcı deneyimini sağlar?

> **Cevap (derste verildi):** En fazla kullanıcıya mobil web geliştirme ulaşır (responsive tasarım, indirme gerektirmez, HTML5 ile güçlendi). En yüksek kullanıcı deneyimini native geliştirme sağlar (platformun SDK'sı ile cihazın bütün yetenekleri kullanılır).

**8. (derste sözlü, 01:31:40)** Cross-platform geliştirmenin native geliştirmeye göre temel sıkıntısı nedir?

> **Cevap (derste verildi):** Kaynak tüketimi. Ara katmanın dönüştürme/yorumlama adımıyla üretilen kod elle yazılan native koddan daha az verimli ve daha büyük olabilir. Ek katman güvenlik riski ve firmaya bağımlılık da getirir.

**9. (derste sözlü, 01:35:41)** Hibrit uygulama geliştirme nedir?

> **Cevap (derste verildi):** Uygulama HTML5, CSS ve JavaScript ile tarayıcıda çalışacakmış gibi yazılır; Cordova gibi bir araç bu kodu native bir kapsayıcıya sarar, uygulama markete konur ve WebKit tabanlı motor üzerinde çalışır.

**10. (derste sözlü, 02:06:38)** Masada boşta duran bir telefonda proximity sensörü yakınlık üretmez. Telefonun kullanılmadığını nasıl anlarız?

> **Cevap (derste verildi):** Son etkileşim zamanına (ekran zaman aşımı) ve ivmeölçer değerlerine bakılır.

**11. (derste sözlü, 02:07:23)** Yukarıdan bırakılan bir telefonun normal (yerçekimi dahil) ivmeölçeri düşme anında ne ölçer?

> **Cevap (derste verildi):** Yaklaşık sıfır. Telefon yerçekimiyle birlikte ivmelendiği için ölçülen özgül kuvvet $\vec{f} = \vec{a} - \vec{g} = 0$ olur. Lineer ivmeölçer kullanılsaydı sonuç farklı olurdu. (Python ile kontrol edildi: durgunken büyüklük 9,81 m/s², serbest düşmede 0.)

**12. (derste sözlü, 02:10:22)** Bir telefonun ivmeölçerinin doğru çalıştığını basitçe nasıl test edersiniz?

> **Cevap (derste verildi):** Telefon düz bir yere farklı yönlerde konur; her eksen yerçekimi yönündeyken yaklaşık 9,81 m/s² göstermelidir. Belirgin sapma (örneğin 8,81) kalibrasyon gerektiğini gösterir.

**13. (derste sözlü, 02:16:14)** Sensör ölçümlerindeki hatayı azaltmak için ne yapılır? Hangi filtre türü tercih edilir?

> **Cevap (derste verildi):** Filtreleme yapılır; genelde low-pass filtreler (örneğin Butterworth) tercih edilir. High-pass filtreler uç değerleri öne çıkardığı için pek kullanılmaz.

**14. (derste sözlü, 02:20:18)** Telefon mikrofonuyla uyku apnesi tespitinde karşılaşılan temel sorun nedir?

> **Cevap (derste verildi):** Gürültülü veri: yanındaki kişi, dışarıdaki araç sesleri, ev içi sesler. Bu sesler horlamayla karışır, bu yüzden ses filtrelemesi gerekir.

**15. (derste sözlü, 02:22:32)** Proximity sensörüyle aynı amaçla (mesafe ölçme) kullanılan başka sensörler nelerdir?

> **Cevap (derste verildi):** Ultrasonik, lazer ve radar sensörleri. Ultrasonik sensörler en çok araçlarda park sırasında kullanılır.

## Dersin Toparlaması

Ders, mobil işletim sistemlerinin karşılaştırmasından başlayıp pil ömrü üzerinden aktivite tanımaya geçti. Aynı anda gerçekleşen aktivitelerin tanınması açık bir araştırma problemi olarak tartışıldı; frekans domeni öznitelikleri, çoklu pencere boyutu ve zaman çizelgesindeki ilişkiler çözüm yolları olarak konuşuldu. Pencerelemede örtüşme oranının %40-%60, temel aktiviteler için pencere boyutunun 3-5 saniye olması gerektiği ve pencere boyutundaki veri miktarı/çözünürlük ödünleşimi vurgulandı. Düşme tespitinde çift eşik ile makine öğrenmesinin birlikte kullanımı anlatıldı. Ardından mobil uygulama kategorileri, uygulamaları öne çıkaran etkenler (kullanıcı deneyimi, doğru zamanlama, teknoloji, hedef kitle) ve dört geliştirme tekniği (native, cross-platform, hibrit, mobil web) karşılaştırıldı.

Dersin son bölümünde mobil cihazlardaki sensörlere giriş yapıldı: ivmeölçer, jiroskop, manyetometre, proximity, ışık ve barometre başta olmak üzere sensörlerin işlevleri, serbest düşmede ivmeölçerin sıfıra yakın değer vermesi, kalibrasyonun ve low-pass filtrelemenin önemi ile uyku analizi örneği konuşuldu. Hoca bir sonraki derste sensör veri setleri üzerinde durulacağını söyledi; otonom araçlar ve overlay ağların da dönemin ilerleyen bir dersinde ele alınabileceğini belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
