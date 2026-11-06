# Ders 11 Genişletilmiş Notu: Proje Önerisi Sunumları II: Rota Optimizasyonu, Enerji Ticareti, Bulut Güvenliği ve Düşme Tespiti

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Çerçevesi
- 2. Birinci Sunum: Geliştirilmiş Genetik Algoritma ile Turizm Rotası
- 3. İkinci Sunum: Raylı Sistemlerde İstasyon ve Vagon Öneri Sistemi
- 4. Üçüncü Sunum: Blok Zincir Tabanlı Eşler Arası Enerji Ticareti
- 5. Dördüncü Sunum: Eğitim Yönetim Sistemi
- 6. Ekran Paylaşımı Aksaklığı
- 7. Beşinci Sunum: Video Boyama
- 8. Altıncı Sunum: E-Öğrenme Verisinin Bulutta Güvenli Paylaşımı
- 9. Yedinci Sunum: Akciğer Tomografisinden COVID-19 Enfeksiyon Oranı
- 10. Sekizinci Sunum: Yaşlı Bakım Evlerinde Düşme Tespiti ve Acil Müdahale
- 11. Hocanın Genel Değerlendirmesi
- 12. Sunumda Ek Materyal Göstermek

## 1. Dersin Çerçevesi

Bu ders, dönem projesi sunumlarının ikinci haftasıdır. Hoca derse "sunumlara kaldığımız yerden devam edeceğiz" diyerek başladı. Yeni bir konu anlatılmadı. Gruplar, TÜBİTAK 1002 Hızlı Destek Programı biçiminde hazırladıkları araştırma projesi önerilerini sırayla sundu.

Bu derste sekiz sunum yapıldı. Konular optimizasyondan görüntü işlemeye, blok zincirden bulut güvenliğine kadar geniş bir alana yayıldı. Yine de sunumların iskeleti birbirine benziyordu. Çoğunda şu başlıklar geçti:

- Konunun önemi, özgün değeri ve literatür.
- Araştırma sorusu, hipotez, amaç ve hedefler.
- Yöntem.
- Proje yönetimi: iş paketleri, görev dağılımı, riskler ve B planları.
- Yaygın etki: bilimsel, ekonomik, toplumsal, ulusal güvenlik.
- Bütçe.

Bu yüzden ders, aynı proje önerisi formunun farklı konularda nasıl doldurulduğunu karşılaştırma fırsatı verir. Hocanın en önemli katkısı dersin sonundaki genel değerlendirmedir. Bu değerlendirme 11. bölümdedir.

Sunumların bir kısmı İngilizcedir. Bu kısımlarda altyazı yer yer bozuk veya döngülüdür. Anlaşılmayan yerler boş bırakılmış, tahmin yürütülmemiştir. Bazı yerlerde kısa nota slayt karesinden aktarılmış bilgiler kullanılmış ve bu durum metinde belirtilmiştir.

## 2. Birinci Sunum: Geliştirilmiş Genetik Algoritma ile Turizm Rotası

### 2.1 Konu ve Amaç

Grubun temel amacı, gezgin satıcı problemini (traveling salesman problem, TSP) gerçek dünyaya uyarlamaktır. Problemin çözümü için birçok algoritma vardır. Grup bunlar arasından genetik algoritmayı seçti ve onun performansını ve hızını artırmayı hedefledi. Bu gelişmiş algoritmayla, ülkedeki turistik yerler için en kısa güzergâhı bulan bir uygulama geliştirilecektir.

Sunumda TSP şöyle tanımlandı: Herhangi bir noktadan başlanır, her noktadan yalnızca bir kez geçilir ve başlangıç noktasına dönülür. Amaç, bu noktaların tamamını kapsayan en kısa yolu bulmaktır. Grubun uyarlamasında noktalar, bir turistin şehir içinde veya şehirler arasında gezeceği yerlerdir.

### 2.2 Literatür

Grup, genetik algoritmanın benzer problemlere uygulandığı çalışmalardan örnek verdi:

- 2010, Adana: Bir fabrikada dağıtım rotaları üzerine genetik algoritma tabanlı çalışma.
- 2018, İstanbul: Toplu taşıma denetim ekibi için en uygun güzergâhı bulan genetik algoritma tabanlı uygulama.
- 2012, Endülüs Özerk Bölgesi: Turistlerin istek ve ihtiyaçlarına göre bir uygulama.
- 2018, Çin: Bir şehirdeki doğal alanlar ve turistlerin kaldığı oteller arasında en uygun güzergâh çalışması.
- 2020, Çin: Başka bir şehirde turistler için gezilecek yer planlaması.

### 2.3 Yöntem: Adaptasyon Süreci

Genetik algoritma doğal süreçlerden esinlenen bir arama ve optimizasyon yöntemidir. Klasik süreçleri seçim, çaprazlama ve mutasyondur. Literatürde bu süreçlerin her biri için farklı operatörler vardır ve operatör seçimi performansı etkiler. Grubun söylediğine göre algoritma, problemin çözüm uzayı büyüdükçe bazı problemlerde yetersiz kalmaktadır.

Grubun özgün önerisi şudur: Klasik süreçlerin arasına, canlıların çevreye uyumundan esinlenen yeni bir adaptasyon süreci eklemek. Bu süreç için farklı adaptasyon operatörleri de önerilecektir. Sunumda operatörlerin nasıl çalışacağı ayrıntılandırılmadı.

> **Ders sonrası not:** Sunumda genetik algoritmanın "evren teorisi" ilkelerine dayandığı söylendi. Büyük olasılıkla kastedilen evrim teorisidir; söyleyiş veya altyazı hatası olabilir.

> **Ek bilgi (derste anlatılmadı):** TSP'de nokta sayısı arttıkça olası tur sayısı çok hızlı büyür. Bu yüzden büyük örneklerde tüm turları denemek pratik değildir. Genetik algoritma gibi sezgisel (metaheuristic) yöntemler bu durumda iyi bir yaklaşık çözüm arar. En kısa turu bulmayı garanti etmezler. Bir önerinin "performansı artırdı" diyebilmesi için bilinen test problemlerinde mevcut yöntemlerle karşılaştırma yapması gerekir.

### 2.4 Uygulama ve Beklenen Etkiler

Uygulamaya Android ve iOS üzerinden erişilecektir. Kullanıcı gezmek istediği yerleri seçer. Uygulama da en kısa ve verimli yolu bildirir. Trafik bilgisini de alarak kullanıcıyı trafiğin az olduğu bölgeye yönlendirir.

Grup beklenen etkileri şu başlıklarla anlattı:

- **Yaşam kalitesi:** Gezilecek yerler hakkında fikir edinme ve zaman tasarrufu.
- **Çevre:** Trafikte daha az kalma, daha az yakıt ve karbondioksit.
- **Akademik etki:** Algoritmanın geliştirilmeye açık olması ve bu alanda çalışmaların sürmesi.
- **Sektör:** Yurt içi ve yurt dışında turizm işletmeleri ve acenteler, programlarını daha kısa sürede hazırlayabilir.
- **İstihdam:** Uygulamanın güncel kalması ve algoritmanın iyileştirilmesi için yazılım alanında istihdam.
- **Rekabet:** Uygulamadan fayda gören bir firma karşısında diğer firmalar da benzer bir araç kullanmak veya üretmek zorunda kalır.
- **Ulusal güvenlik:** Siber ve sınır güvenliğiyle doğrudan ilgisi yoktur. Grup bu başlığı yakıt tüketimindeki azalmaya bağladı.

Son olarak projeyi oluşturan işlerin payları verildi. Algoritmanın geliştirilmesi %25, gezilecek yerlerin keşfi ve rotaların oluşturulması %10, uygulamanın son kullanıcıya ulaştırılması %65'tir. Bu payların toplamı %100'dür.

<!-- BELİRSİZ: Bu payların verildiği başlık altyazıda "proje ölçük ve proje katkısı" diye geçiyor; slayttaki tam başlık bilinmiyor. -->

Sunumun sonunda hoca soru olup olmadığını sordu. Soru gelmedi.

## 3. İkinci Sunum: Raylı Sistemlerde İstasyon ve Vagon Öneri Sistemi

Sunumu grubun bir üyesi tek başına yaptı. Projenin adı, derin öğrenme ve görüntü işleme tekniklerini kullanarak raylı sistemlerde yolculara istasyon ve vagon öneri sistemi geliştirmektir.

### 3.1 Problem ve Literatür

Grup, COVID-19 döneminden üç bulgu aktardı:

- Metro İstanbul'un 2020 verilerine göre yolcu sayısı önemli ölçüde azaldı.
- Birleşik Krallık'ta Mayıs-Haziran 2020'de yapılan bir anket, seyahatlerde düşüş ve trenle seyahatte güven kaybı gösterdi.
- Wuhan'da raylı sistemler üzerine 2020'de yapılan bir çalışmaya göre, bulaşma oranı mesafe arttıkça azalıyor, birlikte geçirilen süre arttıkça artıyor.

Bu bulgulardan şu sonuç çıkarıldı: Güvenli sosyal mesafeyi sağlamak, istasyon ve trenlerde bulaşma riskine karşı temel önlemlerden biridir.

### 3.2 Araştırma Soruları ve Hipotez

Grubun iki sorusu vardı:

- İstasyondaki yolcular için bir vagon öneri sistemi, yolcuları daha güvende hissettirir mi ve bulaşma riskini azaltır mı?
- Kullanıcı, istasyon dışından bir mobil uygulamayla yoğunluğu anlık görüp ulaşım tercihini buna göre yapabilir mi?

Hipotez şudur: İstasyon ve trenlerdeki yoğunluk önceden belirlenirse kullanıcılar yolculuğunu planlayabilir. Vagon doluluk oranları hesaplanırsa yolcular daha boş vagonlara yönlendirilebilir. Böylece sosyal mesafe artar, bulaşma riski azalır, yolcuların raylı sisteme güveni artar.

### 3.3 Yöntem

Araştırma kısmı üç aşamadan oluşur: görüntü ön işleme, insan tespiti ve yoğunluk analizi için insan sayma. Teknik seçimler şunlardır:

- **Nesne tespiti:** Konvolüsyonel sinir ağı kullanan YOLO algoritması. Görüntü ağdan tek seferde geçtiği için hızlı olması seçim gerekçesidir.
- **Veri seti:** Model COCO veri setiyle eğitilecektir.
- **Yazılım:** Python, OpenCV ve NumPy. Kameradan anlık kare OpenCV ile alınır.
- **Donanım:** Vagonlardaki iki kapıya giriş ve çıkış tespiti için kamera yerleştirilir.
- **Yoğunluk hesabı:** İnsan sayısı vagon hacmine göre yoğunluğa çevrilir ve ağırlıklandırılır. Belirlenen eşiklere göre renklendirilir.
- **İletişim:** Sonuçlar istasyondaki bilgi ekranlarına ve uygulamaya MQTT protokolüyle aktarılır. Veriler bulut sisteminde depolanır.
- **Mobil uygulama:** Flutter ile geliştirilir. Çapraz platform olduğu için iOS ve Android için hızlı geliştirme ve maliyet tasarrufu sağlar.

Değerlendirme de planlandı. Kullanıcılara bir değerlendirme anketi sunulacaktır. Uzman desteğiyle yarı yapılandırılmış gözlem formu hazırlanacak ve sahada veri toplanacaktır. İlgili paydaşlarla yarı yapılandırılmış görüşme formuyla görüşülecektir.

### 3.4 Proje Yönetimi, Riskler ve Etkiler

Görevler aşamalara bölündü: ihtiyaç analizi ve paydaşlarla iletişim, sunucu ve bulut ortamının kurulumu, derin öğrenme modelinin eğitimi ve değerlendirilmesi, mobil uygulama geliştirme, ekipmanların vagon ve istasyonlara entegrasyonu, testler ve geri bildirimlerin değerlendirilmesi.

Riskler şöyle sayıldı: derin öğrenme algoritmasının yetersiz veya yavaş kalması, sunucu depolamasının yetmemesi, takvime uyulamaması, ekipmanların yetersizliği veya arızası, kullanıcıların uygulamaya erişim sorunu.

Beklenen çıktılar bir bildiri ve indeksli bir dergide makaledir. Toplumsal etki olarak yolcuların rahat ulaşımı ve sağlık sisteminin aksamaması gösterildi. Akademik etki olarak sistemin tüm ulaşım türlerine yayılması ve gelecekteki salgınlara destek olması söylendi. Ekonomik etki olarak ülkenin benzer krizleri daha az zararla atlatması, ulusal güvenlik etkisi olarak da pandemide güvenilir ulaşım gösterildi.

### 3.5 Soru-Cevap

**Soru:** Yolcu sayısını bildirmenin yanı sıra, belli bir kapasitenin üzerinde vagon kapılarının açılmaması gibi bir sistem düşünüldü mü?

**Cevap:** Sunan kişi böyle bir şey düşünmediklerini söyledi. Amaçları yoğunluğu belirlemek ve yolcunun binmeden önce uzaktan görüp plan yapmasını sağlamaktır. Mesai giriş-çıkışları veya maç günleri gibi durumlar buna örnektir. Kapıların açılıp kapanmasına müdahale etmek ters tepebilir.

Hoca kısa bir ekleme yaptı: "Açmazsak inecek olanlar inemez." Soruyu soran kişi bunu düşünmediğini söyledi. Bu küçük örnek, bir önerinin etkisini sistemin bütününde düşünmek gerektiğini gösterir.

## 4. Üçüncü Sunum: Blok Zincir Tabanlı Eşler Arası Enerji Ticareti

### 4.1 Konu ve Fikir

Sunumun ilk bölümü İngilizcedir ve altyazının büyük kısmı anlaşılmıyor. Anlaşılabilen kısımda blok zincir, bir işlemi kaydetmeyi ve iş ağı içinde izlemeyi destekleyen paylaşımlı bir dağıtık defter (distributed ledger) olarak tanımlandı. Eşler arası (peer-to-peer, P2P) enerji ticareti ise enerji kaynaklarını dağıtık biçimde paylaşmaya yarayan yeni bir eğilim olarak anlatıldı.

Kısa nota aktarılan slayta göre fikir şudur: Sanal güç santrali (virtual power plant, VPP) içindeki blok zincir akıllı sözleşmeleri verimli, şeffaf ve ekonomik bir P2P enerji ticareti sağlar. Şekilde enerji üreten ve tüketen ajanlar, bir P2P ticaret koordinatörü, teknik VPP, piyasa operatörü, enerji depolama sistemi ve dizel jeneratör vardır.

<!-- BELİRSİZ: 00:24-00:29 arasındaki İngilizce anlatım altyazıda döngülü. Şekil ve VPP bilgisi altyazıdan değil, kısa nottaki slayt aktarımından alındı. -->

Uygulama için Ethereum, Ethereum Sanal Makinesi (Ethereum Virtual Machine, EVM), MetaMask ve Solidity anıldı. Ethereum, eksiksiz bir akıllı sözleşme platformu olarak tanıtıldı.

### 4.2 Proje Yönetimi ve Riskler

Sunumun Türkçe bölümünde proje yönetimi anlatıldı. Proje önce analiz, sonra tasarım, sonra üretim ve test aşamalarından oluşur.

<!-- BELİRSİZ: Analiz aşamasının süresi altyazıda "üçte beşte biri kadar" diye geçiyor; oran anlaşılmıyor. -->

Riskler şöyle sayıldı:

- Santral sistemlerinin arızaları ve sanal tesislerdeki sistemsel hatalar.
- Blok zincirin merkeziyetsiz yapısına güvenilmemesi. Merkezî sunucu yoktur, bağlantı eşler arasıdır.
- Solidity'de yazılım hataları. Grup, Solidity'nin çok bilinen bir dil olmadığını belirtti.
- Hastalık ve ölüm gibi nedenler.
- Ekonomik kriz nedeniyle bütçenin karşılanamaması.
- Fiziksel alanların zarar görmesi.
- İç savaş gibi olaylar.

Risk gerçekleşirse şartların yeniden test edilip projeye kaldığı yerden devam edilmesi planlandı.

### 4.3 Beklenen Etkiler

- **Sosyal ve kültürel:** Temiz enerji transferi, sürdürülebilir bir sistem, eşlerin kendi aralarında enerji transferi yapabilmesi.
- **Akademik:** Yeni araştırma konuları ve projeler, uluslararası iş birlikleri, enerji kurumlarıyla ortak çalışma, üniversite-sanayi iş birliği.
- **Ekonomik:** Üçüncü kişi veya aracı olmadığı için ek gider oluşmaz. Grup, taşıma bedeli ve KDV gibi kalemlerin olmayacağını söyledi.
- **Sektör:** Kırsal ve bölgesel temiz enerji gelişimi, sistemin ihraç edilebilmesi.
- **Ulusal güvenlik:** Blok zincirin güvenlik yöntemleri sayesinde veri güvenliği. Grup, SHA-256 kullanıldığını ve zinciri kırmanın imkânsız olduğunu söyledi.

> **Ders sonrası not:** Sunumda SHA-256 ile "şifreleme" yapıldığı ve zincirin kırılmasının "imkânsız" olduğu söylendi. Bu ifade büyük olasılıkla hatalıdır. SHA-256 bir özet (hash) fonksiyonudur, şifreleme değildir. Zincirin güvenliği, geçmiş blokları değiştirmenin pratikte çok maliyetli olmasına dayanır. Ayrıca Ethereum'da büyük olasılıkla Keccak-256 kullanılır; SHA-256 daha çok Bitcoin ile anılır. Sunumda verilerin herkes tarafından görülebileceği de söylendi. Yani blok zincir tek başına gizlilik sağlamaz.

> **Ders sonrası not:** "Taşıma bedeli ve KDV olmaz" iddiası büyük olasılıkla abartılıdır. Akıllı sözleşme ticaretteki aracıyı azaltabilir. Ama elektrik yine fiziksel şebeke üzerinden taşınır ve vergi yükümlülüğü yazılımla ortadan kalkmaz.

Sunumun sonunda soru gelmedi.

## 5. Dördüncü Sunum: Eğitim Yönetim Sistemi

### 5.1 Problem ve Amaç

Proje, uzaktan ve örgün eğitimde öğretmen, öğrenci, veli ve okul idaresinin karşılaştığı sorunlardan yola çıkar. Hedef, öğrencinin derse aktif katılımını sağlayan ve velinin öğrenciyi takip edebildiği bir mobil uygulamadır.

Grup gerekçe olarak iki kaynak verdi. Milli Eğitim Bakanlığı'nın 2020 küresel salgın dönemi uzaktan eğitim izleme ve değerlendirme raporuna göre tüm öğrencilerin derse katılım oranı %23,6'dır. Uzaktan eğitime hiç katılma imkânı olmayanların oranı ise %13'tür. Grup bundan, katılma imkânı olup da katılanların oranının düşük olduğu sonucunu çıkardı. İkinci kaynak, aktif öğrenme yöntemini 203 makale üzerinden inceleyen bir çalışmadır. Bu çalışmada %95 oranında olumlu sonuç bulunduğu aktarıldı.

Bunlara dayanarak iki amaç belirlendi. Birincisi öğrenci merkezli ve aktif katılımı artıran bir eğitim aracıdır. Grup bunu, Kahoot gibi uygulamaların bütününü kapsayan bir mobil uygulama diye özetledi. İkincisi yerli bir ürün geliştirmektir. Böylece okullar yurt dışı kaynaklı uygulamalara bağımlı kalmaz, kişisel veriler ve kaynaklar yurt dışına çıkmaz.

### 5.2 Özellikler

- Anlık quiz.
- Ders konularının tartışıldığı bir forum ortamı.
- Konuları özetleyen zihin haritaları.
- Akıllı tahta yönetimi.
- Öğrenci-öğretmen mesajlaşması.
- E-öğrenme içerikleri.
- Anket.
- Ders dışı etkinlik planlama ve duyurular.
- Okul idaresi için ders ve ders programı yönetimi.

### 5.3 Ekip ve İş Paketleri

Proje altı kişiyle yürütülecektir: proje yürütücüsü, kıdemli yazılım tasarım ve geliştirme mühendisi, ikinci bir tasarım ve geliştirme mühendisi, yalnız geliştirmede çalışan bir mühendis, geliştirme ve testte çalışan bir mühendis, yalnız testte çalışan bir mühendis. İkinci tasarım mühendisinin gerekçesi önemlidir: Yazılım tasarımındaki hatalar, geri dönüşü en maliyetli hatalardır.

Dokuz iş paketi vardır:

- **1. Muadil yurt dışı ürünlerin incelenmesi:** En önemli karşılaştırma ürünü EduPage'dir. Çıktı, sistem gereksinimleri belgesidir.
- **2. Sistem mimarisi ve yazılım tasarımı:** En kritik paketlerden biridir. UML diyagramları hazırlanır, tasarım toplantıları yapılır, işi parçalara bölmek için mikroservis yaklaşımı kullanılır.
- **3. Tasarım ve test belgeleri:** Mühendislere sözlü anlatım yetmez. Belgenin sağlanması önemli bir ölçüttür.
- **4. Bulut servisi, backend ve API geliştirme:** 45 gün sürer.
- **5. Yönetici ve kullanıcı arayüzü geliştirme:** 4. paketin 15. gününde başlar. Amaç, önce backend'in temelini oturtmak ve arayüzü bunun üzerinde test edilebilir biçimde geliştirmektir.
- **6. Backend ve arayüz entegrasyonu:** 4. ve 5. pakette çalışan herkes katılır. Sunumda en uzun paket olarak anıldı ve 40 gün olarak verildi.
- **7. Tasarım doğrulama testleri:** Test ortamı ve ayrıntılı test belgesi hazırlanır.
- **8. Sistem entegrasyon testleri:** Bileşenlerin girdi ve çıktıları izlenerek tasarlandığı gibi çalışıp çalışmadığına bakılır.
- **9. Son kullanıcı belgeleri:** Projedeki herkes katılır.

İlk üç paket seri ilerler, aralarında paralellik yoktur.

> **Ders sonrası not:** Sunumda EduPage'in "hatırladığım kadarıyla" İspanya merkezli olduğu söylendi. Büyük olasılıkla Slovakya merkezlidir.

> **Ders sonrası not:** 6. paket "en uzun süren" paket olarak 40 gün verildi. Oysa aynı sunumda 4. paket 45 gündür. Anlatılan rakamlar birbiriyle uyuşmuyor. Slayttaki takvim altyazıdan görülemediği için doğru değer belirlenemedi.

### 5.4 Riskler ve B Planları

- **Nitelikli eleman bulunamaması veya geç bulunması:** İş bulma siteleri, sosyal medya ve üniversitelerin ilgili bölümlerinde ilan.
- **Nitelikli elemanın proje sırasında kaybı:** Hızlı işe alım, hızlandırılmış oryantasyon, tecrübeli personelle birebir çalışma.
- **Testlerde performans eksikliği:** Grubun en önemli gördüğü risktir. Maliyetten ödün verilerek tecrübeli bir yazılım mimarı danışman alınır ve modüller performans açısından yeniden değerlendirilir.
- **Satış ve pazarlamaya zaman ve bütçe ayrılamaması:** Teknik tecrübesi yüksek çalışanların pazarlamada aktif rol alması, düzenli pazarlama materyali, teknik bilgisi olan satış personeli.
- **Yabancı ürünlere daha çok güvenilmesi:** Büyük firmalarla çalışıp referans kazanmak, sektörün önde gelen şirketleriyle iş birliği yapmak, yurt dışı pazarlara açılmak.

### 5.5 Çıktılar, Etkiler ve Bütçe

Bilimsel çıktı, geliştirilecek yöntemlerle bir makaledir. Ekonomik çıktı, yabancı ürünlerin yerini alabilecek bir üründür. Bu ikisi için 12-18 aylık bir öngörü verildi. Araştırmacı yetiştirme çıktısı ise ilk altı ay için planlandı.

Toplumsal etki olarak öğrencilerin kazanım eksiklerinin daha kolay tespiti ve eğitim kalitesinin artması söylendi. Ekonomik etki, maliyet, esneklik, entegrasyon ve teknik destek bakımından yabancı ürünlerin yerini almaktır. Ulusal güvenlik etkisi, öğrencilerin kişisel verilerinin yurt dışına çıkmasını engellemektir.

Bütçede iki bilgisayar, bir Android ve bir iOS cihaz vardır. TÜBİTAK'tan talep edilen toplam tutar 24.091 TL'dir.

> **Ders sonrası not:** Sunumda "akademik etki yok" denildi. Oysa aynı sunumda bilimsel çıktı olarak makale planlanıyor. Bu iki ifade birbiriyle çelişiyor. TÜBİTAK 1002 bir araştırma programı olduğu için akademik etkinin boş bırakılması büyük olasılıkla önerinin zayıf noktasıdır.

Soru gelmedi.

## 6. Ekran Paylaşımı Aksaklığı

Sıradaki grup ekranını paylaşamadı. Öğrenci kendisine yetki verilip verilmediğini sordu. Hoca paylaşımın herkes için açık olduğunu söyledi ve yolu tarif etti: "Share Screen" seçilir, açık olan sunumun ekranı seçilir. Sunumu F5 ile başlatmış olmak daha iyi olur.

Sorun çözülemedi. Grup bilgisayar değiştirmek için süre istedi, sıradaki gruba geçildi ve bu sunum dersin sonuna kaldı. Bu sunum, not içinde sekizinci sunum olarak yer alır. Hoca dersin sonunda sunum hazırlığından söz ederken bu tür aksaklıkların sunanı bağladığını söyledi. Bu konu 12. bölümdedir.

## 7. Beşinci Sunum: Video Boyama

Sunum İngilizcedir ve altyazının büyük bölümü anlaşılmıyor. Aşağıdakiler anlaşılabilen kısımlardan ve kısa nottaki slayt aktarımından derlenmiştir.

<!-- BELİRSİZ: 00:52:54-00:54:36, 00:57:32-00:58:02 ve 00:58:32-01:02:03 arası altyazı döngülü veya boş. Harris dedektörünün anlatımı, örtme analizi ve sonuç kısmı bu aralıkta kaldı. -->

### 7.1 Konu

Projenin adı, örtme tutarlılığı (occlusion consistency) gözeten, mean-shift izleyici ve Harris dedektörü kullanan bir video boyama (video inpainting) önerisidir. Kısa nota göre amaç, videodaki bir nesneyi kaldırıp yerini arka planla doldurmaktır.

### 7.2 İş Paketleri

Anlaşılabilen kısımda üç paket geçer:

- İlk paket projenin %10'udur. Kısa nota göre ekonomik ve teknik analizi kapsar.
- İkinci paket beklenti ve strateji belgelerinin hazırlanmasıdır. Projenin %20'sidir.
- Üçüncü paket nesne tespiti, arka plan çıkarma, bölütleme ve nesnelerin etiketlenmesidir. Projenin %35'idir.

Bu üç payın toplamı %65'tir. Kalan paketler altyazıda anlaşılmıyor.

<!-- BELİRSİZ: Paket sürelerinin altyazıdaki karşılığı "about two more", "about three more" biçiminde; büyük olasılıkla ay sayısı ama kesin değil. -->

### 7.3 Yöntemin Akışı

Sunumda önerilen akış şu adımlarla sayıldı:

- Video girişi ve videonun karelere ayrılması.
- Ön plan nesne tespiti (foreground object detection).
- Nesne takibi (object tracking).
- Örtme analizi (occlusion analysis).
- Köşe noktası tespiti (corner point detection).
- Nesnenin boyanması (object inpainting).
- Çıktı videosunun birleştirilmesi.

### 7.4 Arka Plan Tahmini ve Takip

Arka plan tahmini için birikimli histogram (accumulation histogram) kullanılır. Kareler bloklara ayrılır. Tüm karelerde en sık görülen blok arka plan bloğu sayılır. Gerekçe basittir: Nesne videoda hareket ettiği için, bir konumda en sık görünen içerik büyük ölçüde arka plana aittir. Kısa nota aktarılan slayta göre ölçüt olarak ortalama ve varyans kullanılır. Önerilen yöntem 3x3 blokla, mevcut yöntemler 2x2 blokla çalışır. Sonrasında bir pikselin nesneye mi arka plana mı ait olduğuna karar verilir.

Takip aşamasında mean-shift izleyici kullanılır. İzleyici nesne için bir hedef model (target model) kurar ve başka bir pencerede aday modeli (candidate model) tahmin eder. Bu pencere hedef modelden daha büyüktür.

> **Ek bilgi (derste anlatılmadı):** Mean-shift izleyicide nesne genellikle bir renk dağılımıyla modellenir. Her yinelemede pencere, hedef modele daha çok benzeyen yöne kaydırılır. Benzerlik ölçüsü olarak sıklıkla Bhattacharyya katsayısı kullanılır. Harris dedektörü ise parlaklığın iki yönde birden güçlü değiştiği noktaları köşe olarak seçer. Köşeler kareler arasında iyi eşlendiği için takipte ve örtme durumlarında yararlıdır.

Sunumun sonunda hoca "Sanırım soru yok, her zaman olduğu gibi" dedi. Bu söz, dinleyicilerin soru sormadaki pasifliğine bir göndermedir.

## 8. Altıncı Sunum: E-Öğrenme Verisinin Bulutta Güvenli Paylaşımı

Sunum İngilizcedir. Bazı kısımlar altyazıda anlaşılmıyor. Projenin adı, e-öğrenme bilgisinin bulut depolamayla güvenli paylaşımı için bir mekanizmadır.

<!-- BELİRSİZ: Mekanizmanın adı altyazıda "Technique Relationship Protected", kısaltması "TRB" olarak geçiyor. Slayttaki doğru yazım doğrulanamadı. -->

### 8.1 Problem ve Hipotez

Grup önceki modelleri incelediğini ve çoğunda ekonomik veya güvenlik sorunları bulduğunu söyledi. Bulut depolama güçlü ve talebe göre ölçeklenen bir hizmettir. Fakat donanım ve yazılım arızaları, insan hataları ve ağdaki siber saldırılar yüzünden verinin bütünlüğü (integrity) kolay garanti edilemez. Bu nedenle, bulut ile kullanıcı arasında aktarılan verinin bütünlüğünü ve doğruluğunu sağlayacak denetçilere (auditor) ihtiyaç vardır.

Hipotez şudur: Önerilen güvenli yöntem, bilginin aktarımını ve güvenilir biçimde saklanmasını sağlayabilir. Projenin hedefi, e-öğrenme sistemi ile bulut depolama arasında paylaşılan veride denetimi destekleyerek mahremiyeti korumaktır.

### 8.2 Bulutun Sunulan Avantajları

- **Esneklik:** Sağlayıcılar, depolama ve bant genişliğini kolayca artırıp azaltmaya izin veren paketler sunar.
- **Veri kurtarma:** Veri genellikle birden çok konumda saklanır. Bir sunucuda sorun çıkarsa başka bir konumdaki kopya kullanılır.
- **Bakım:** Grup, bakımın sağlayıcı tarafından yapıldığını, kullanıcı için maliyet veya emek gerekmediğini söyledi.
- **Kolay erişim ve yüksek güvenlik:** Bunlar da avantaj olarak sayıldı.

> **Ders sonrası not:** Sunumda bulutun "bakım gerektirmediği" ve güvenliğinin yüksek olduğu söylendi. Aynı sunumda bütünlüğün kolay garanti edilemediği de söylendi; bu iki ifade birlikte düşünülmelidir. Bulutta büyük olasılıkla paylaşılan sorumluluk modeli (shared responsibility model) geçerlidir. Erişim yönetimi ve şifreleme kullanıcının da sorumluluğundadır.

### 8.3 Sistem ve Denetçinin Çalışması

Yöntem iki aşamadan oluşur: tasarım ve model simülasyonuyla uygulama. Sistem modelinde dört rol vardır: yönetici (admin), veri sahibi, veri kullanıcısı ve denetçi. Kısa nota aktarılan slayta göre rollerin görevleri şöyledir:

- **Yönetici:** Kullanıcıları, veri sahiplerini ve denetçileri oluşturur.
- **Veri sahibi:** Dosyaları şifreleyip buluta yükler. Anahtar ve dosya bilgisi kullanıcılara e-posta (SMTP) ile gönderilir.
- **Kullanıcı:** Dosyaları buluttan indirir.
- **Denetçi:** Yüklenen ve indirilen dosyaların bozulup bozulmadığını kontrol eder.

<!-- BELİRSİZ: Rollerin görev ayrıntıları ve SMTP bilgisi altyazıda geçmiyor (01:11:31-01:12:29 arası anlaşılmıyor); kısa nottaki slayt aktarımından alındı. -->

Denetçinin çalışması altyazıda daha nettir. Denetçi, e-öğrenme ortamı ile bulut arasında taşınan veriyi veri tipi, dosya adı ve verinin alınması için belirlenen zaman gibi bilgilere bakarak denetler. Bu bilgilerde bir kusur görürse işlemi yetkisiz sayar. Bunu, araya giren bir saldırganın işareti olarak değerlendirir. Aktarımı iptal eder, işlemin iptal edildiğini veri sahibine hemen bildirir ve sistemden işlemi tekrarlamasını ister.

> **Ders sonrası not:** Dosya adı, tipi ve zamanı gibi üst bilgilere bakmak büyük olasılıkla veri bütünlüğünü kanıtlamaya yetmez. İçerik değişip bu bilgiler aynı kalabilir. Bütünlük için özet değeri, mesaj doğrulama kodu (MAC) veya dijital imza gerekir. Aynı şekilde, AES tek başına genellikle gizlilik içindir, bütünlüğü sağlamaz.

> **Ek bilgi (derste anlatılmadı):** Bu konu literatürde üçüncü taraf genel denetim (third-party public auditing) ve kanıtlanabilir veri sahipliği (provable data possession) başlıklarıyla çalışılır. Bu yaklaşımlarda denetçi, dosyanın tamamını indirmeden verinin sunucuda bozulmadan durduğunu kriptografik olarak sınar. Denetçinin verinin içeriğini öğrenmemesi de ayrı bir tasarım hedefidir.

### 8.4 Gereksinimler, İş Paketleri ve Bütçe

Sistem için üç temel gereksinim sayıldı:

- **E-öğrenme ortamı:** Yönetici, veri sahibi, kullanıcı ve denetçiyi içeren bir model.
- **Mahremiyet ve koruma mekanizması:** Bilgi ve gizli anahtar paylaşımı, erişim için kimlik doğrulama, AES ile şifreleme ve çözme, denetçinin çalışması.
- **Depolama:** Bulut depolama platformu.

İş paketleri, gereksinimlere ve gereken süreye göre sıralandı. İlk paketlerde ekonomik ve teknik analiz ile beklenti, hedef ve strateji planı belgesinin hazırlanması geçer. Çıktılar iki maddedir: makale ve konferans gibi nitelikli akademik yayın ve projenin farklı bilim ve teknoloji alanlarında kullanılması.

Bütçe için ayda yaklaşık 50 terabaytlık bulut alanından söz edildi. Bulut hizmeti ve ek hizmetlerle hesaplanan toplam tutar 24.000 TL'dir.

Soru gelmedi.

## 9. Yedinci Sunum: Akciğer Tomografisinden COVID-19 Enfeksiyon Oranı

### 9.1 Amaç

Proje, bilgisayarlı tomografi (BT) taramalarında akciğerdeki zatürreye bağlı COVID-19 enfeksiyonunu çıkarmayı ve değerlendirmeyi hedefler. Enfekte bölgeler görüntü işleme yöntemleriyle bulunur. Enfeksiyon oranı, akciğerin tamamına göre piksel oranı olarak hesaplanır:

$$
\text{Enfeksiyon oranı} = \frac{\text{enfekte piksel sayısı}}{\text{akciğer piksel sayısı}}
$$

Grup bu oranın test görüntülerini sınıflandırmada da yardımcı olacağını söyledi.

### 9.2 Test Yöntemleri

Sunumda test yöntemleri üç kategoride toplandı: nükleik asit tabanlı testler, serum tabanlı testler ve röntgen ile tomografiyi içeren diğer yöntemler. En yaygın olanı PCR testidir.

PCR'ın anlatımı şöyleydi: Hastanın burnundan veya boğazından örnek alınır ve RNA çıkarılır. RNA'dan DNA elde edilir. DNA polimeraz, DNA'nın kopyalanmasına yardımcı olan bir enzimdir. Prob bölgesine geldiğinde floresan bir madde açığa çıkarır. DNA kopyalandıkça floresan seviyesi artar.

> **Ders sonrası not:** Sunumda floresan seviyesi belli bir eşiği "geçmezse" testin pozitif olduğu söylendi. Bu büyük olasılıkla bir söyleyiş veya altyazı hatasıdır. Doğrusu büyük olasılıkla şudur: Sinyal belirli sayıda döngü içinde eşik değerini aşarsa test pozitif sayılır. Sunumdaki "RNA'dan DNA elde etme" adımı da ters transkripsiyon (reverse transcription) olarak bilinir.

Röntgen ve tomografi yalnızca COVID-19 için değil, başka hastalıklar için de kullanılır. Grup, bu yaygınlık nedeniyle erişimin kolay olduğunu söyledi ve projeyi tomografi üzerine kurdu.

### 9.3 Yöntem

Yöntem kısmı İngilizce anlatıldı ve MATLAB kullanıldı. Önce BT görüntüsünün özellikleri sayıldı: Akciğerler her zaman koyu renktedir. Çevredeki görüntüde gri, beyaz ve bazen siyah tonlar vardır. Sağlıklı bir tarama, COVID-19 enfeksiyonlu bir taramayla yan yana gösterildi.

Sonra işlem adımları anlatıldı. Altyazının anlaşılabilen kısımlarına göre akış şöyledir:

- **Yoğunluk analizi:** Piksel yoğunluk dağılımı incelenir ve bir yoğunluk eşiği belirlenir.
- **Kenar tespiti:** MATLAB'ın yerleşik kenar tespit fonksiyonu Sobel filtresiyle çalıştırılır. Yalnız kenarlardan oluşan ikili (binary) bir görüntü elde edilir.
- **Maskeler:** Ardışık maskelerle akciğer bölgesi ayrılır ve kalan gürültü temizlenir. Akciğerler sağlıklıysa üçüncü maske yalnızca gürültü üretir. Dördüncü maskenin sağlıklı ve hasarlı akciğeri ayırması beklenir.
- **Son işlem:** Kenarlar birkaç piksel içeri taşınır. Sonra boşluklar doldurulur. Son maske görüntüye uygulanır.
- **Sayma:** Son görüntü ikiliye çevrilir ve siyah olmayan pikseller sayılır.

<!-- BELİRSİZ: 01:21:38-01:22:08, 01:22:43-01:25:35 ve 01:26:32-01:27:02 arası altyazı döngülü. Maskelerin tam tanımı, "by 2 pixels" adımının ayrıntısı ve üçüncü BT özelliği (altyazıda "sörting scars ... blood parcels") anlaşılmıyor. -->

### 9.4 Prototip ve Sınırlılıklar

Grup prototipin ekran görüntülerini gösterdi. Tomografi görüntüsü verilir, akciğerler bölütlenir ve enfekte bölgeler daha beyaz boyanarak son görüntü elde edilir. İlk örnekte oran %36, ikinci örnekte %15 çıktı.

En büyük risk olarak gürültülü görüntülerde akciğer bölütlemenin başarısız olabilmesi gösterildi. Nedeni, gri ton değerleri arasındaki farkın düşük olması ve bunları ayırt edecek bir fonksiyon kurmanın zorluğudur. Bu yüzden grup, sistemi kesin bir uzman sistem olarak değil, doktora yardımcı bir asistan program olarak önerdi. Sonuç ne olursa olsun değerlendirme doktorundur. TÜBİTAK desteği, prototipi gerçek zamanlı çalışabilir hale getirmek için istenmektedir.

> **Ders sonrası not:** Enfeksiyon oranı büyük olasılıkla tek başına tanı koymaya yetmez. COVID-19 dışındaki zatürreler de tomografide benzer görünümler verebilir. Grubun "son karar doktorun" vurgusu bu açıdan yerindedir.

Soru gelmedi.

## 10. Sekizinci Sunum: Yaşlı Bakım Evlerinde Düşme Tespiti ve Acil Müdahale

Ekran paylaşımı sorunu nedeniyle ertelenen sunum bu kez yapıldı. Projenin adı, yaşlı bakım evlerinde anomali tespitiyle kasıtsız yaralanmalara acil müdahale sistemidir.

### 10.1 Kavramlar

Sunum yaralanmanın tanımıyla başladı. Yaralanma, insan bedeninde aniden ortaya çıkan, fizyolojik tolerans eşiğinin üzerindeki enerjiye karşı oluşan fiziksel hasardır. Dünya Sağlık Örgütü'nün açıklamalarında yaralanmalar kasıtlı ve kasıtsız olarak ikiye ayrılır. Düşme, trafik kazası ve boğulma kasıtsız yaralanmadır.

Proje fikri aslında düşmelere acil müdahale sistemi olarak doğdu. Grup, literatür taramasında bunun "kasıtsız yaralanma" adıyla anıldığını gördüğü için başlıkta bu terimi kullandı.

### 10.2 Problemin Büyüklüğü

Grup düşmeleri ciddi bir halk sağlığı sorunu olarak sundu. Düşmeler özellikle çocuklarda ve 65 yaş üstünde kalıcı sonuçlar doğurur. Sayısal veriler şunlardır:

- Ölümcül olmayan yaralanmalar listesinde düşmeler %46 ile ilk sıradadır.
- Türkiye'de 2020 baz alındığında yaşlı nüfus toplam nüfusun %8,5'idir. Bu kesimin %13,4'ü bakıma muhtaçtır.
- Yaş ilerledikçe düşmeye bağlı yaralanmaların ciddiyeti artar.
- Dünyada ortalama 684 bin ölümcül düşme olur. Kasıtsız yaralanmalarda trafik kazaları ilk, düşmeler ikinci sıradadır.
- Devlete bağlı huzurevi sayısı 153'tür.

Düşmeler sakat kalma, yatağa bağımlılık, bilinç ve hafıza kaybı gibi sonuçlara yol açar. Bunun bireye etkisinin yanında sağlık sistemine de ciddi bir maliyeti vardır.

> **Ders sonrası not:** Sunumda 2020 için yaşlı nüfus oranı %8,5 verildi. TÜİK verilerine göre 2020 için oran büyük olasılıkla yaklaşık %9,5'tir. %8,5 büyük olasılıkla daha eski bir yılın verisidir.

### 10.3 Amaç ve Yöntem

Grubun amacı düşmeyi önlemek değildir. Grup bunun farklı bir çalışma olabileceğini söyledi. Amaç, düşmeden sonra acil müdahaleyi hızlandırmaktır. Huzurevlerinde hastalar sürekli gözetim altında görünse de belli saatlerde ziyaret edilir. Düşen bir hasta bir süre fark edilmeyebilir ve bu süre içinde oksijensiz kalabilir veya kan kaybedebilir.

Yöntem şu adımlardan oluşur:

- **Veri toplama:** Anlaşılan huzurevlerinde her hastanın odasına kapalı devre kamera konur. Günlük hareketler izin dahilinde 7/24 kaydedilir. Bu aşama yaklaşık 8 ay sürer.
- **Veri seti oluşturma:** 7/24 kaydın tamamını işlemek zaman ve maliyet açısından anlamsızdır. Yalnız olayın geçtiği sahneler kesilir. Grup, 50 saniyelik bir düşme için öncesi ve sonrasıyla 70 saniyelik ham video örneğini verdi.
- **Ön işleme:** Gürültü temizleme, yakınlaştırma, uzaklaştırma ve aynalama gibi tekniklerle görüntü iyileştirilir.
- **Etiketleme:** Faydalı kısımlar denetimli öğrenme için etiketlenir.
- **Model:** Rastgele orman (random forest), k-en yakın komşu (k-NN) ve destek vektör makineleri (SVM) denenir. En yüksek başarıyı veren algoritma sonraki aşamalarda kullanılır.
- **Bildirim:** Örneğin sürekli tekerlekli sandalyede oturan bir hastanın aniden yere düşmesi anormal bir davranıştır. Sistem bunu personele bildirir.

> **Ders sonrası not:** Sunumda "50 saniye sürüyorsa 10 dakika öncesi, 10 dakika sonrası, yani 70 saniyelik video" denildi. Bu ifade tutarsızdır. $50 + 10 + 10 = 70$ olduğu için kastedilen büyük olasılıkla 10 saniye öncesi ve 10 saniye sonrasıdır.

> **Ek bilgi (derste anlatılmadı):** Grup kayıtların "izin dahilinde" yapılacağını söyledi. Odalara 7/24 kamera konması güçlü bir mahremiyet müdahalesidir. Bu tür çalışmalarda genellikle yaşlının veya vasisinin bilgilendirilmiş onamı, etik kurul onayı ve kişisel verilerin korunması mevzuatına uyum gerekir. Bu nedenle etik süreç, bir proje önerisinde ayrı bir iş adımı veya risk olarak planlanmalıdır.

### 10.4 Takvim, Riskler ve Etkiler

Proje yaklaşık 12 ay sürer ve üç aşamaya ayrılır:

- **Veri toplama (1-8. ay):** Grubun en önemli aşamalarından biridir.
- **Kodlama:** Video kayıtlarından düşme tespitine yarayan kısımlar ayrılır, etiketlenir ve model oluşturulur.
- **Test (yaklaşık 2 ay):** Huzurevlerinde gerçek ortamda çalışılır. Tespit edilen olayın gerçekten düşme olup olmadığına ve gerçek düşmelerin yakalanıp yakalanmadığına bakılır. Geri dönüşlere göre model iyileştirilir.

İki risk öngörüldü. İlki, yeterli düşme verisi toplanamamasıdır. Bu durumda sentetik veri üretilir. İkincisi, projedeki kişilerin sağlık gibi nedenlerle çalışamamasıdır. Bu durumda süreyi aksatmayacak yeni bir kişi alınır.

Bilimsel çıktı olarak 6. ve 12. aylar arasında makale ve bildiri planlandı. Etkiler üç başlıkta toplandı:

- **Toplumsal ve kültürel:** Bildirim sonucu acil müdahaleyle hayat kurtarma, yaşam kalitesi ve ömre katkı.
- **Akademik:** Özgün modelin sonraki çalışmalara ışık tutması, verilerin akademik makalelerde kullanılması, özel sektör ve üniversiteleri bir araya getirmesi.
- **Ekonomik:** Doğrudan bir etki yoktur. Sakat kalma ve ölümlerin önlenmesiyle sağlık sistemine gelen yük azalır. İleride anaokulları ve açık alanlarda kullanım, yurt dışına satış da mümkündür.

### 10.5 Soru-Cevap

**Soru:** Bu konuda örnek, açık kaynak veri setleri var mı? İlk 8 ayda kod altyapısı bunlarla mı kurulacak?

**Cevap:** Grup, literatürde düşmeye ait açık kaynak bir veri setine rastlamadığını söyledi. Böyle bir veri seti olursa veri toplama aşamasının kısalacağını belirtti. Grubun diğer üyesi şunu ekledi: Anomali tespiti için çok sayıda veri seti vardır. Metro istasyonlarında yere düşen veya raylara atlayan kişileri tespit eden sistemler buna örnektir. Ama huzurevlerinde bakıma muhtaç kişilerin sağlık nedeniyle düşmelerine özgü bir veri seti bulunmamaktadır. Soruyu soran kişi, önceden eğitilmiş (pre-trained) bir model kullanılabilirse diye sorduğunu söyledi.

> **Ders sonrası not:** Grubun "açık kaynak düşme veri setine rastlamadık" sözü büyük olasılıkla eksik bir tarama sonucudur. Kamera tabanlı açık düşme veri setleri büyük olasılıkla vardır. Örnekler: UR Fall Detection, Le2i Fall Detection, UP-Fall Detection, Multiple Cameras Fall Dataset. Teknik literatürde de "düşme tespiti" (fall detection) terimi yaygın olarak kullanılır. Bu kaynaklar huzurevine özgü olmasa da ön eğitim ve karşılaştırma için kullanılabilir.

## 11. Hocanın Genel Değerlendirmesi

Sekiz sunum bitince hoca genel bir değerlendirme yaptı. Bu sözlerin son gruba değil tüm sınıfa yönelik olduğunu özellikle belirtti. Değerlendirme, proje sunumu yapacak bir araştırmacı için akademik öğüt olarak okunabilir.

### 11.1 Örnek Sunumlardan Ders Çıkarmak

Hoca, ilk haftanın sunumlarının izlendiğini, artı ve eksilerin görülmüş olması gerektiğini söyledi. İlk haftanın sonunda neyin hatalı olduğu da konuşulmuştu. Yine de bundan pek ders alınmadığını gördüğünü söyledi. Araştırmacı için öğüt şudur: Başkalarının sunumunu izlemek, kendi sunumunu düzeltmek için bir fırsattır.

### 11.2 Slayttan Okumamak

> **Hocanın vurgusu:** Slayda olabildiğince metin koyup onu dinleyiciye okumanın "hiçbir esprisi yok".

Hoca bir noktaya daha dikkat çekti. Sunum önceden hazırlanmışsa, üzerinde çalışmak için fazladan zaman var demektir. Buna rağmen sunum hâlâ kâğıttan, başka bir yerden veya slayttan okunuyorsa bu, işe yeterli özenin gösterilmediğini söyler. Yani avantaj dezavantaja döner. Prova yapmak, sunumun doğal bir parçasıdır.

### 11.3 Kendini İfade Etme

Hoca, dinleyicilerin lisans seviyesini çoktan geçmiş yüksek lisans ve doktora öğrencileri olduğunu hatırlattı. Kendini ifade etme, derdini anlatma ve iletişim kurma becerileri bu seviyede çok daha iyi olmalıdır. Oysa hem İngilizce hem Türkçe sunumlarda konuşma akıcılığında ciddi sıkıntı gördüğünü söyledi.

### 11.4 Süreyi Yönetmek

Hoca sunumlarda 20 hatta 30 slayt olabileceğini, bunun olmaması gerektiğini ama olmuş olsa bile bir çözüm üretilebileceğini söyledi. Bazı slaytlar atlanarak süre daha makul kullanılabilirdi.

> **Hocanın vurgusu:** Herkese 10 dakika verilmişken 17 dakika sunum yapmanın hiçbir anlamı yoktur. Bu, belli açılardan ciddi saygısızlık olarak görülür. "Kimseye eziyet etmenin bir anlamı yok. Artı kimse sizden daha değersiz değil."

Hoca, süre imkân verdiği sürece sunumları kesmeden dinlediğini de söyledi. Yani süreye uymak, sunanın kendi sorumluluğudur.

### 11.5 Dinleyici Olmak

Hoca ikinci bir saygısızlık unsuru olarak dinleyicilerin davranışını gösterdi. Başkasının sunumu sırasında mikrofonu açık bırakmak ve oradan gürültü duyulması hoş değildir. Bunun tekrarlanmamasını diledi.

Sunumlar sırasındaki iki kısa an da bu başlıkla ilgilidir. Hoca birkaç kez kameraların açılmamasına dikkat çekti ve soru gelmemesini "her zaman olduğu gibi" diye andı. İyi bir akademik ortamda dinleyici de sunuma katkı veren taraftır.

## 12. Sunumda Ek Materyal Göstermek

Değerlendirmeden sonra bir öğrenci, sunum sırasında başka bir belge veya site göstermenin olumsuz karşılanıp karşılanmayacağını sordu.

**Soru:** Teslim edilen sunumda yer almayan bir şeyi başka bir belge veya siteden göstermek sorun olur mu?

**Cevap:** Hoca, nasıl yapıldığına bağlı olduğunu söyledi. Sunum değiştirilemez, yani başka bir sunum yapılamaz. Ama sunum içinde ek bir bilgiyi göstermek, referans olması için bir şey izletmek mümkündür. Bunun iki koşulu vardır:

- **Süre:** Bu da süreden yer. Planı ve programı buna göre yapılmalıdır.
- **Hazırlık:** Hoca, sunumla ilgili konuşulanların en başında hazırlığın geldiğini hatırlattı. Hangi cihaz ve ekipmanın kullanılacağı bilinmelidir.

> **Hocanın vurgusu:** Videonun görünüp görünmemesi, ekranın açılıp açılmaması gibi problemlerin tamamı sunanı bağlar. Bu tip bir şey yapılacaksa önceden mutlaka test edilmelidir.

## Dersin Toparlaması

Bu derste sekiz proje önerisi dinlendi: genetik algoritmayla turizm rotası, raylı sistemlerde vagon önerisi, blok zincirle eşler arası enerji ticareti, eğitim yönetim sistemi, video boyama, bulutta güvenli e-öğrenme verisi, tomografiden COVID-19 enfeksiyon oranı ve huzurevlerinde düşme tespiti. Sunumlar aynı proje formunun farklı alanlarda nasıl doldurulduğunu gösterdi. Bazı önerilerde araştırma sorusu ve hipotez açıkça kuruldu. Bazı önerilerde ise risk planı ve görev dağılımı öne çıktı.

Hocanın değerlendirmesi ise içerikten çok sunumun kendisine yöneldi: slayttan okumamak, prova yapmak, süreye uymak, dinleyiciye saygı göstermek ve kullanılacak ekipmanı önceden denemek. Sunumlar sonraki haftalarda da sürecektir; hoca dersi "haftaya görüşmek üzere" diyerek kapattı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
