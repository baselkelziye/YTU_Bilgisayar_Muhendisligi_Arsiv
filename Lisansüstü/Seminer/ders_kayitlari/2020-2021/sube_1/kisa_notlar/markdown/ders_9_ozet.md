# Ders 9 Çalışma Özeti

## Genel Konular

- Seminer sunumları
  - Bu derste üç öğrenci, yaptıkları literatür taramasını sundu. Konular: heterojen robot sürülerinin koordinasyonu ve formasyonu, mikroservis tabanlı büyük veri ve makine öğrenmesi uygulamaları üzerine sistematik literatür taraması, çoklu robot sistemlerinde harita gösterimi ve harita birleştirme yöntemleri.
  - Her sunumdan sonra hoca kaynakların güncelliği, atıf sayıları ve slayt düzeni üzerine geri bildirim verdi.
- Sürü (swarm) robot sistemlerinin temel özellikleri
  - Sürü, aynı amaç için bir araya gelmiş ve birbiriyle iletişim hâlinde olan büyük bir robot grubudur. Karınca, arı ve kuş sürülerinden esinlenir.
  - Avantajları: geniş alan tarama ve keşifte hız, tek robotun yapamayacağı işleri birlikte yapma, farklı görevlerde özelleşmiş bireylerle daha başarılı sonuç.
  - Dezavantajı: birey sayısı arttıkça yönetim, formasyon ve konfigürasyon zorlaşır.
- Sürü türleri (ekrandan, 00:15:00)
  - Bireylerin özdeş olup olmadığına göre: homojen (aynı donanım ve yazılım) ve heterojen (farklı donanım ve/veya yazılım). Heterojen sürülerde robotların birbirini modellemesi zordur, bu yüzden çalışmalarda daha az tercih edilir.
  - Yönetim biçimine göre: merkezi (centralized), merkezi olmayan (decentralized) ve hibrit.
- Sürülerde beklenen davranışlar ve konular
  - Self-organization, ölçeklenebilirlik (scalability), sağlamlık (robustness), formasyon ve bağlantı topolojisi, enerji tasarrufu.
  - Formasyon için graf teorisi, Voronoi diyagramları ve potansiyel alanlar (potential fields) kullanılır.
- Swarm çalışmalarının yoğunlaştığı konular (ekrandan, 00:20:00)
  - Yönetim biçimi optimizasyonu; self-organization davranışı ve dezavantajlarının giderilmesi; ölçeklenebilir ve sağlam sistemler; etkin enerji kullanımıyla işe en uygun formasyonu bulma; yol planlama ve engelden kaçınma; obje taşıma; enerjinin tükendiği noktada tüm sistemin devre dışı kalmasına çözüm.
- İncelenen sürü çalışmaları
  - İki katmanlı formasyon sistemi (2020, homojen sürü): graf tabanlı formasyon, yol planlama katmanı ve formasyon takip katmanı.
  - Swarmanoid (2013): foot-bot, hand-bot ve eye-bot'tan oluşan heterojen robot sürüsü.
  - Heterojenliğin sürü davranışlarındaki performansa etkisi (2015): BEECLUST algoritması ve genetik algoritma ile davranışsal heterojenlik.
  - Görev odaklı optimizasyonla heterojen sürü kurma ve açık problemler.
- Mikroservis mimarileri
  - Uygulamayı, kendi içinde tutarlı iş fonksiyonu içeren, tek amaçlı, küçük ve hafif servislere ayırmaya dayanan yazılım mimarisi stili.
  - Faydaları ve zorlukları slayttan alındı (ekrandan, 00:50:00).
- Makine öğrenmesi uygulamaları ve büyük veri
  - Makine öğrenmesi uygulamalarında veri ve algoritma kritik; gerçek sistemlerde ML kodu, çevresindeki altyapının küçük bir parçasıdır.
  - Zorluklar: kalite güvence, veri ve model yönetimi, konuşlandırma, izleme ve veri etiketleme (ekrandan, 00:55:00).
- Sistematik literatür taraması yöntemi
  - Araştırma soruları, arama süreci, seçim kriterleri, kalite değerlendirme, veri toplama, veri sentezi (ekrandan, 01:00:00).
  - Snowballing ile atıf yapan ve atıf yapılan makaleler de incelendi; kalite puanlamasıyla 45 makaleye inildi.
- Harita gösterimi ve harita birleştirme
  - SLAM (eş zamanlı konum belirleme ve haritalama) çoklu robotlarda harita birleştirme problemini doğurur.
  - Harita gösterimleri: doğrudan gösterim, özellik tabanlı gösterim, doluluk ızgarası (occupancy grid) gösterimi.
  - Harita birleştirme: araç poz tahmini tabanlı yöntemler ve harita tutarlılığına dayalı yöntemler (özellik tabanlı, ICP, ODO).

## Hocanın Özellikle Vurguladığı Kısımlar

- Kaynakların güncelliği
  - Literatür taramasında okunan makalelerin yayın tarihlerinin güncel olması, günümüze yakın tarihli makalelerin bulunması çok önemlidir.
- Atıf sayıları
  - Hoca, referans listesindeki her kaynağın sonuna parantez içinde kaç atıf aldığının yazılmasını istedi.
  - Yeni çıkmış bir makalenin atıf sayısının az olması doğaldır; atıf sayısı yayın tarihiyle birlikte değerlendirilir.
- Kısaltmaların açık hâli
  - ICP, ODO gibi kısaltmalar kullanıldığında açık hâli de verilmeli; özellikle kısaltma slayt başlığı yapılmışsa açık hâli başlığa yazılmalı.
- Örnek bir arama tekniği
  - Hoca, sistematik literatür taramasındaki arama ve makale eleme sürecini örnek bir çalışma olarak nitelendirdi.
- Soru sormanın önemi
  - Seminerin amacı fikir alışverişidir; dinleyicilerin soruları, sunan kişinin aklına gelmeyen noktalarda ona fikir verebilir.

## Kısa Tekrar Notları

- Homojen sürü: aynı donanım ve yazılım. Heterojen sürü: farklı donanım ve/veya yazılım.
- Merkezi yönetim: tüm robotlar bir yöneticiye bağlı; yöneticinin kaybı sürüyü dağıtır; global haritalama görevlerinde tercih edilir.
- Merkezi olmayan yönetim: robotlar bilgi aktarımı, görev dağılımı ve konumlanmayı birbirine göre kendileri yapar; karmaşıklık birey sayısından bağımsızdır, global bilgi isteyen görevlerde başarısızdır.
- Hibrit yönetim: yerelde komşularla iletişim ve formasyon robotlarda, tüm sürünün davranışı bir yönetici ya da yönetici grubunda.
- Enerji tasarrufu: şarj istasyonları, dolaylı iletişim (bir robotun bıraktığı iz), start-stop sayısını ve bağlantı alanını küçültme.
- İki katmanlı formasyon: RIPF ile graf tabanlı formasyon, kenar sayısı $E = 2V - 3$, Delaunay üçgenlemesi, lider seçimi; yol planlamada gradient descent; takipte model öngörülü kontrol.
- Swarmanoid: foot-bot (tekerlekli taşıyıcı), hand-bot (iki kollu, tırmanır ve tutar), eye-bot (quadrotor, 12 m içinde range and bearing iletişimi).
- BEECLUST + genetik algoritma: aynı donanımla davranışsal heterojenlik; 15 robotluk simülasyonda heterojen sürü homojen sürüden önde.
- Mikroservis zorlukları: servis keşfi ve kayıtlanma, güvenlik, mesajlaşma ve entegrasyon, veri yönetimi (eventual consistency).
- Büyük veri mimarisi örüntüleri: Lambda ve Kappa; literatürde çoğunlukla Lambda.
- Veri tabanı örüntüleri: database per service ve shared database.
- Harita birleştirmede araç poz tahmini tabanlı yöntem üç adımdır: algılama, ilişkilendirme, göreceli poz tahmini.
- ICP iki adımı yineler: en yakın nokta eşleşmesi, sonra toplam mesafeyi en aza indiren hizalama tahmini.

## Detaylı Açıklamalar

- Birinci sunum heterojen robot sürülerinin koordinasyonu ve formasyonu üzerineydi. Sürü robotiği terimi robotikte ilk kez 1989'da kullanılmış, ama sürü sistemleri üzerine çalışmalar 1940'lara kadar uzanıyor. Sürüler askeri uygulamalarda ve orman yangını taraması gibi geniş bölge keşif görevlerinde kullanılır. Merkezi yönetimde yönetici, hangi robotun hangi görevi yapacağını belirler ve robotlardan gelen bilgiyi bir merkezde birleştirir; bu yüzden her robotun kendi alanını haritaladığı ve haritaların ortak bir yerde birleştirildiği haritalama görevlerinde tercih edilir. Merkezi olmayan yönetimde robotlar çoğunlukla en yakın komşularına göre hareket eder. Self-organization, çevre değişince, sürüye yeni bir robot katılınca, bir engel çıkınca ya da bir robot arızalanınca sürünün kendi başına yeniden uyum sağlaması demektir. Ölçeklenebilirlik, sürünün birkaç bireyle de binlerce bireyle de aynı şekilde çalışabilmesidir; sağlamlık ise doğru çalışabilmesi olarak tanımlanmıştır.
- Sunumda incelenen derlemeye göre, yoğunlaşılan konuların hepsini kapsayan bir çalışma yoktur; en fazla beş tanesini kapsayan çalışmalar vardır. Bunun bir nedeni uçtan uca (end-to-end) bir sistem örneğinin olmamasıdır: çalışmalar belli varsayımlar altında sistemin bazı noktalarını çalıştırır, gerçek dünyada bir sürü kurup koşturan ve sonuç alan çalışma henüz yoktur.
- İki katmanlı formasyon çalışmasında (2020) önce formasyona uygun topoloji otomatik oluşturulur. Sürü yönlü bir graftır: robotlar düğüm, komşu robotlar arası bağlantılar kenardır; bir robottan diğerine kenar gidiyorsa hedefteki robot kaynaktaki robot tarafından yönlendirilir (lead edilir). Formasyon robotların ilk pozisyonlarından kısıtlar altında kurulur: çarpışmayı önlemek için her robot farklı konumda olur, her robot komşularından $D$ uzaklıkta olur, bir robotu en fazla iki komşu robot yönlendirir ve kenar sayısı $E = 2V - 3$ olur. Algoritma ilk pozisyonlardan Delaunay üçgenlemesi kurar, bağıntıya göre fazla kenarları siler ve bir robotu lider atar. Yol planlama katmanında bir sonraki adım gradient descent ile bulunur; engele güvenli mesafeden fazla yaklaşılmaz, engel geçilince eski yola dönülür ve dönüş açısını küçültmek için bir referans yol tanımlanır (ekrandan, 00:25:00). Formasyon takip katmanında mevcut ve beklenen durum arasındaki hata tanımlanır ve model öngörülü kontrol ile her adımda optimizasyon yapılarak optimal kontrol girdisi üretilir. Sonuçlarda takip hatası başta dalgalanıp sıfıra yakınsar.
- Swarmanoid (2013) uçtan uca heterojen bir sürü kurmak için üç robot üretti. Foot-bot iki ayrı motorlu tekerlekle hareket eder ve RGB LED'lerle haberleşir. Hand-bot yerde sabit duran bir platforma bağlı iki koldan oluşur; dikey tırmanır, objeleri tutup kaldırır, görev yerine foot-botlarca taşınır. Eye-bot iç mekân için optimize edilmiş bir quadrotordur; dışarıda GPS, içeride kamera ve lazer sensörleriyle konumunu bulur, range and bearing sistemiyle 12 m içindeki robotlarla veri alışverişi yapar, görev yerini bulup foot-bot ve hand-botlara iletir (ekrandan, 00:30:00). Gösterilen görevde raftaki bir kitap başka bir rafa taşındı. Daha fazla deney için ARGoS simülasyon ortamı geliştirildi.
- Heterojenliğin etkisi çalışmasında (2015) robotların donanımı aynı tutuldu, heterojenlik davranışla sağlandı; amaç homojen donanımın ucuzluğunu korurken heterojen davranış elde etmekti. Bal arılarının yaşa göre random walker, wall follower, goal finder ve hareketsiz (immobile) davranışlar sergilediği gözleminden yola çıkıldı. Homojen sürüler için geliştirilmiş BEECLUST algoritması genetik algoritmaya entegre edildi; arı deney sonuçlarına uygun davranışlar ödüllendirilip uygunluk fonksiyonu maksimize edildi (ekrandan, 00:35:00). 15 robotluk simülasyonda homojen ve heterojen sürüler karşılaştırıldı; ısıtılmış hedef bölge deneylerinde homojen sürü heterojen sürünün gerisinde kaldı.
- Açık problemler: görevler karmaşıklaştıkça alt gruplara ayırma (coalition formation, alt sürü kurma) hâlâ çoğunlukla insanla yapılıyor; otonom makine öğrenmesinin parametre ayarı ve dinamik çevre tahmininde kullanımı; simülasyon ile gerçek dünya deneyleri arasındaki açık; transfer öğrenme ile önceki deneyimlerden yararlanma.
- İkinci sunum mikroservis tabanlı büyük veri ve makine öğrenmesi uygulamaları üzerine bir sistematik literatür taramasıydı. Mikroservislerde servisler farklı teknolojilerle ve farklı ekiplerce geliştirilebilir, birbirleriyle haberleşerek uygulamayı oluşturur. Bir serviste hata varsa yalnız o servis düzeltilip yeniden konuşlandırılır, diğer servislere dokunulmaz; derleme ve test süreleri kısalır. Zorluklar: servislerin birbirini bulması için bir kayıt merkezine kayıt ve servis keşfi; çok sayıda dağıtık servisin güvenliği; nesne çağrısı yerine servis çağrısı ve mesajlaşma altyapısının entegrasyon maliyeti; transactional bütünlük gerektiren verinin artık eventual consistency ile asenkron tutarlı hâle getirilmesi. Atomik işlem gerektiren durumlarda servis sınırları buna göre belirlenmelidir. Sunumda, uygulamayı yalnız konteynere koymanın onu bulut yerlisi (cloud native) yapmadığı, Kubernetes gibi araçların ancak uygulama düzeyinden başlayan bütüncül tasarımla işe yaradığı vurgulandı.
- Makine öğrenmesi modelleri çoğunlukla büyük veriyle daha iyi sonuç verir, ama verinin boyutundan önce kalitesi önemlidir. Büyük veri hesaplama maliyetini artırdığı için small data ve transfer öğrenme gibi yaklaşımlar popülerleşiyor. Sunumda NeurIPS 2020 atölyesinde yayımlanan bir derlemeden (Paleyes ve ark.) veri ve model izlemenin ve alarm üretmenin açık bir problem olduğu aktarıldı (ekrandan, 00:55:00). Google'ın "Hidden Technical Debt in Machine Learning Systems" çalışmasındaki şekle göre gerçek ML sistemlerinde ML kodu küçük bir kutudur; çevresinde veri toplama, veri doğrulama, özellik mühendisliği, konfigürasyon, izleme, sunum altyapısı gibi geniş bir altyapı vardır (ekrandan, 01:05:00).
- Sistematik literatür taramasında beş araştırma sorusu soruldu. "Mikroservis + big data" ve "mikroservis + machine learning" sorgularıyla beş veri kaynağı tarandı, ilk elemeyle 104 makaleye inildi, snowballing ve tam metin okumayla kalite değerlendirmesi yapıldı ve 45 makale kaldı. Bunların 37'si konferans bildirisi, 8'i dergi makalesiydi; yayın sayısı her yıl artıyor. Bulgular: büyük veri mimarisinde Lambda (çoğunlukla) ve Kappa örüntüleri; işlem katmanı ve servis katmanının mikroservis olarak konuşlandırılması; asenkron, reaktif haberleşme; database per service ve shared database örüntüleri; uygulama alanı olarak IoT ve Endüstri 4.0; temel problemler olarak konuşlandırma, servis orkestrasyonu ve değerlendirme; yazılım ürün hattı için bağımlılıklara göre servis alt kümesi seçme ve multi-tenant kullanım. ML uygulamalarına özgü değerlendirme ölçütü sunan çalışma bulunamadı.
- Üçüncü sunum çoklu robotlarda harita birleştirme üzerineydi. Robotlar okyanus derinlikleri, aktif volkanlar, afet bölgeleri, maden arama, hasarlı binalar, denizaltı ve uzay keşfi gibi insan için tehlikeli ya da erişimi güç yerlerde kullanılır. Ortam büyüdükçe haritalama uzar ve hata olasılığı artar; bu yüzden çoklu robotlu SLAM gerekir. Doğrudan gösterim ham sensör taramalarını saklar, sensör verisi dönüşümünden muaftır; ama boş alan gibi belirsizlikleri ve sensörün doğrudan ölçemediği alanı modellemek ve haritayı yönetmek zordur (ekrandan, 01:15:00). Özellik tabanlı gösterim yapay işaretler, ağaçlar, çizgi bölümleri gibi özellikleri saklar, az bellek ister, ama genel ortam hakkında bilgi vermez. Doluluk ızgarası ortamı hücrelere böler; hücre değeri 1'e yakınsa dolu, 0'a yakınsa boş olma eğilimindedir; genel ortamı temsil eder ve belirsizliği modeller.
- Harita birleştirme, kısmi haritalardan tek tutarlı harita oluşturmaktır. Araç poz tahmini tabanlı yöntemler araçtan araca göreceli poz tahminine dayanır (algılama, ilişkilendirme, göreceli poz tahmini); GPS hataları gibi konum hataları bu yöntemleri zorlar. Harita tutarlılığına dayalı yöntemler göreceli pozun doğru tahminini gerektirmez, iki haritayı bir tutarlılık ölçüsüne göre doğrudan birleştirir (ekrandan, 01:20:00). ICP yöntemleri özellik çıkarmadan çalışır ve en yakın nokta eşleşmesi ile toplam mesafeyi en aza indiren hizalama adımlarını yineler. ODO yöntemleri harita hizalamasının tutarlılık derecesini bir amaç fonksiyonu olarak tanımlar ve optimal hizalamayı bir optimizasyon tekniğiyle arar. Sunumun sonucuna göre çoklu robot çalışmalarında harita birleştirme için genelde ICP kullanılıyor ve hangi birleştirme yönteminin seçileceği çözülmeyi bekleyen bir sorun (ekrandan, 01:25:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
