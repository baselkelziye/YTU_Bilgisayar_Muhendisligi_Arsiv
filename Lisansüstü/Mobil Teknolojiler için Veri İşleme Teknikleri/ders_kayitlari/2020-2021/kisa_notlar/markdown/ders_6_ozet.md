# Ders 6 Çalışma Özeti

## Genel Konular

- Hareket sensörlerinin tekrarı: manyetometre, ivmeölçer ve sinyal vektör büyüklüğü
  - Manyetometre, dünyanın manyetik alanına göre konumu ve yönü bulmayı sağlar; pusula da bu ilkeyle çalışır. Ulaşım türünü (metro, otobüs, uçak) tanımada ivmeölçere ek olarak yön ve yönelim bilgisi katarak başarıyı artırır.
  - İvmeölçer m/s² cinsinden ölçer ve x, y, z olmak üzere üç ekseni vardır. Literatürde sinyal vektör büyüklüğü (signal vector magnitude, SVM) üç eksenin karelerinin toplamının karekökü olarak tanımlanır: $SVM = \sqrt{x^2 + y^2 + z^2}$.
  - SVM birçok problemde "dördüncü eksen" olarak kullanılır. Aynı yaklaşım jiroskop ve manyetometre için de uygulanabilir. Pencere üç eksen yerine tek eksen üzerinde gezdirildiği için hesap azalır ve yine yüksek başarı elde edilebilir.
- Jiroskop
  - Jiroskop açısal hızı ölçer; yönelim bilgisini ivmeölçerden daha hassas verir. Slaytta Android'in Photo Sphere özelliğinin telefonun ne kadar ve hangi yöne döndürüldüğünü bu sensörle bulduğu, Google Sky Map'in de telefonun hangi takımyıldıza doğrultulduğunu bu sensörle anladığı yazıyordu (ekrandan, 00:10:00).
  - Üç boyutta açılı hareket eden her nesne ya da kişide işe yarar: merdiven inip çıkma, yokuş, taşıtlı ve taşıtsız hareketlerin tanınması ve sürüş analizi.
- Sürüş analizi
  - Yoldaki çukur, tümsek, viraj gibi bozuklukların tespiti ve bunların sürüş konforuna etkisi.
  - Sigorta şirketlerinin sürüş alışkanlığına göre kişiye özel poliçe sunması: eski yaklaşım kural tabanlıydı (kazasız yıl sayısına göre indirim); yeni yaklaşım fren kullanımı, hızlanma ivmesi, ani şerit değiştirme gibi davranışları izler.
  - Sürüşün alt aktiviteleri (manevralar): hızlanma, yavaşlama, sabit hızla gitme, dönme (sağa, sola, U dönüşü), durma, şerit değiştirme, geri gitme, park etme.
  - Motivasyonlar: sigorta, belediye ekiplerinin bozuk yollara yönlendirilmesi, risk haritası ve sürücünün sesli uyarılması, anlık trafik yoğunluğu, yakıt tüketimi ve otonom araç yazılımlarının değerlendirilmesi.
  - Sürüş konforu puanlaması: teoride A noktasından B noktasına düz bir çizgide, sabit hızla, trafiksiz gidiş 100 puandır ve ivme sıfırdır. Pratikte hız sabitleyici bile küçük hızlanmalar üretir. Kaliteli düz yolda ölçülen ivme referans alınır; ölçülen sürüş buna ne kadar yakınsa puan o kadar yüksektir. Başka sistemler her ani fren ve dönüş için 100'den puan düşer.
  - İvmenin öne çıkma nedeni $F = m \cdot a$ ilişkisidir: kişiye etki eden kuvvet ivmeyle doğru orantılıdır.
  - Biyosensörler: kas yorgunluğunu ölçen ve vücuda bağlanan sensörler, nabız, beyin aktivitesini ölçen başlıklar. Sorunları müdahaleci (intrusive) olmalarıdır.
  - Sürücü ile yolcunun yorgunluğu farklıdır: yüksek hızda sürücü sürekli dikkat vermek zorundadır. Bu yorgunluk göz takibi (kırpma sıklığı, göz açıklığı), ayna kontrol sıklığı ve baş hareketlerinin kamerayla izlenmesiyle tahmin edilebilir (sürücü davranış analizi).
  - Yeni araçlarda CAN bus üzerinden devir, ivme ve yakıt tüketimi gibi standart veriler alınır. Yolun konforu dijital haritadan (eğim, viraj keskinliği) kabaca tahmin edilebilir; çukur ve asfalt kalitesi ise ancak o yoldan geçen araçların verisiyle bulunur. Böylece bir "sürüş konforu haritası" çıkarılabilir.
  - ADAS (Advanced Driver Assistance Systems): sürücüyü fark etmediği hatalar konusunda uyaran karar destek sistemleri. Araçtan araca (vehicle-to-vehicle) ağlarla yakındaki araçların güvenlik düzeyi paylaşılabilir. Kameranın en büyük sorunu KVKK ve GDPR gibi yasal kısıtlardır.
- Diğer sensörler
  - Termometre ve higrometre: telefonda vardır ama telefonun kendi ısısından etkilendiği için verimli kullanılmaz; telefon bir yere sabit bırakılırsa işe yarar.
  - Parmak izi sensörü ve Face ID: eşleştirmede ham pikseller değil, belirli ayırt edici noktalar (nirengi noktaları) karşılaştırılır. Ses tanıma ve Shazam, SoundHound gibi şarkı tanıma uygulamaları da sinyalin "parmak izini" çıkarıp yalnız onu karşılaştırır.
  - Hava nem sensörü, pedometre (diğer fiziksel sensörlerden türetilen sanal sensör), nabız ölçer, radyasyon, hava kalitesi, alkol, glikoz, nefes analizi sensörleri; sağlık başlığı altında tek kanallı EKG, vücut sıcaklığı, kan şekeri, nabız, kan oksijen satürasyonu, vücut yağ oranı ve stres seviyesi (ekrandan, 01:05:00).
  - Stres seviyesi yüz ifadesi, ses tonu, kan basıncı ve nabızdan tahmin edilebilir. Duygu farkındalığı (emotion awareness) PerCom gibi konferanslarda ayrı bir çalışma alanıdır.
- Konum belirleme
  - Dış mekânda GPS (ve GLONASS gibi diğer uydu sistemleri), alternatif olarak baz istasyonu üçgenlemesi ve Wi-Fi erişim noktaları. Enerji tüketimi en yüksekten en düşüğe: GPS, baz istasyonu, Wi-Fi.
  - İç mekân konumlama teknikleri (ekrandan, 01:15:00): Wi-Fi/WLAN parmak izi, Bluetooth (menzil 10-30 m, hassasiyet 5-10 m), RFID (200 m'ye kadar menzil), UWB (<0,3 m hassasiyet, düşük menzil, yüksek maliyet), Zigbee, ultrason (~1 cm), kızılötesi (~1 mm, görüş hattı gerektirir).
  - Sensör kitleri: Sensordrone gibi akıllı telefona bağlanan çok sensörlü kitler (gaz, temassız termometre, nem, ışık, renk, basınç, yakınlık sensörleri) (ekrandan, 01:20:00).
  - Park yeri tespiti: AVM'lerde kızılötesi ya da ultrason sensörleri; sokaklarda yola gömülen sensörler (pahalı); büyük açık otoparklarda yüksek bir direğe konan tek bir çok yönlü (omnidirectional) kamera.
- Sensörlerin sınıflandırılması (ekrandan, 01:30:00)
  - Cihaz yaklaşımı (telefon, aktivite takip cihazı, sağlık cihazları), algılama uygulaması yaklaşımı (hareket, yakınlık, gaz algılama) ve pazar/iş yaklaşımı (maliyet, değer, patent ve lisans).
- Zaman ve frekans domeni öznitelikleri
  - Zaman domeni: histogram (değerlerin tekrar sayısı), ardışık örnekler arası değişim miktarı, ortalama, standart sapma, varyans, medyan, RMS, kovaryans/öz vektörler ve sıfır geçiş oranı.
  - Sıfır geçiş oranı (zero crossing rate): sinyalin pozitiften negatife ya da negatiften pozitife geçiş sayısıdır; sinyalin değişkenliği hakkında bilgi verir. Ortalama ya da medyan geçiş oranı ve birden fazla eşik çizgisi de kullanılabilir.
  - Frekans domeni: önce Fourier dönüşümü gerekir; spektral enerji ve FFT katsayılarının toplamı gibi öznitelikler. Mobil cihazlarda maliyeti yüksek olduğu için zaman domeni tercih edilir.
  - Ayırt edici öznitelikler (discriminative features) az ve ayırt ediciliği yüksek olmalıdır; korelasyonlu öznitelikler elenir. Öznitelik veriyi toplayan cihazda çıkarılır (in situ / yerinde işleme), sunucuya yalnız öznitelik gönderilir.
- Yapay zekâ, makine öğrenmesi, derin öğrenme, veri madenciliği ve veri bilimi
  - En üstte yapay zekâ vardır. Makine öğrenmesi, geçmiş veriden ve deneyimden öğrenen sistemlerdir ve yapay zekânın alt kümesidir. Derin öğrenme, katman ve nöron sayısının arttığı, büyük veri ve GPU ile mümkün olan sinir ağlarıdır.
  - Veri madenciliği verideki ilişkileri ortaya çıkarır; makine öğrenmesi ve derin öğrenmeyle ilişkilidir ama ayrı bir alan olarak düşünülür. Veri bilimi bunların hepsini veri üzerinde kullanan, farklı bir kümeye konan geniş bir kavramdır.
  - Veri bölme: eğitim, doğrulama, test. Yaygın oranlar 6-2-2 ve 8-1-1; 70-15-15 de kullanılır.
- Veri ön işlemeye giriş
  - Gerçek veri kirli olabilir ve anlamsız örüntülere yol açar. Nedenleri: eksik veri, gürültülü veri (hata ve aykırı değer), tutarsız veri (ekrandan, 02:30:00).
  - Ön işleme adımları: gürültü temizleme, eksik veriyle baş etme, mantıksal aralık dışındaki hatalı verinin düzeltilmesi ya da atılması, normalizasyon, dönüşüm ve entegrasyon (örneğin farklı para birimlerinin tek birime çevrilmesi), tutarlılık kontrolü (yaş ve doğum tarihi) ve veri azaltma.
  - Normalizasyon genelde [0, 1] ya da [-1, 1] aralığına yapılır; [0, 1] için en küçük ve en büyük değer bulunur. Amaç farklı aralıktaki özniteliklerin öğrenmeye eşit ağırlıkla etki etmesidir.
  - Aykırı değer tespiti: çeyrekler açıklığı, veriye özgü kurallar, kümeleme ve uzaklık tabanlı yöntemler. Aykırı değer kararı bozuyorsa atılır, katkı sağlıyorsa tutulur.
- Kural tabanlı, makine öğrenmesi ve derin öğrenme yaklaşımları mobil cihazlarda
  - Telefon ve akıllı saatlerde hibrit yapı tercih edilir: kararın net olduğu yerde kural tabanlı, belirsiz bölgede makine öğrenmesi ya da derin öğrenme kullanılır. Düşme tespitinde eşiğin üstü ve altı kural ile, aradaki değerler öğrenme modeliyle karara bağlanır; bu ciddi enerji tasarrufu sağlar.

## Hocanın Özellikle Vurguladığı Kısımlar

- Ayırt edici öznitelikler ve yerinde işleme
  - Kaynak kısıtlı cihazlarda her özniteliğin hesaplanması bir maliyettir. Ham veri yerine yalnız öznitelikleri göndermek iletişim maliyetini düşürür. Önce problem çözülür, sonra öznitelik sayısı azaltılmaya çalışılır.
- Mobil cihazlarda zaman domeni öznitelikleri tercih edilir
  - Frekans domenine geçmek, FFT kullanılsa bile, her pencere için ayrı bir dönüşüm ve enerji demektir.
- Kaliteli veri, algoritmadan bile önemlidir
  - Kurumsal şirketlerin verisinde bile kirlilik vardır (kullanıcı girişi, hızlı kayıt zorunluluğu, standardı belirlenmemiş alanlar). Temiz veriyle çalışmak başarının birinci anahtarıdır.
- Normalizasyonun matematiğini bilmek
  - Hazır fonksiyonlar olsa da arka plandaki basit matematik unutulmamalıdır.
- Derin öğrenme her şeyi çözmez
  - Derin öğrenmenin başarısız olduğu ya da klasik yöntemlerle başa baş kaldığı durumlar vardır.
- Hibrit modeller giyilebilir cihazlarda daha iyi performans verir.

## Kısa Tekrar Notları

- $SVM = \sqrt{x^2+y^2+z^2}$, dördüncü eksen olarak kullanılır.
- Jiroskop: açısal hız; yönelim bilgisini ivmeölçerden daha hassas verir.
- Sürüş alt aktiviteleri: hızlanma, yavaşlama, sabit hız, dönme, durma, şerit değiştirme, geri gitme, park.
- Sürüş konforu referansı: düz yol, sabit hız, sıfıra yakın ivme ($F = m \cdot a$).
- Konum: enerji sırası GPS > baz istasyonu > Wi-Fi.
- İç mekân: Bluetooth 10-30 m menzil ve 5-10 m hassasiyet; UWB <0,3 m; ultrason ~1 cm; kızılötesi ~1 mm ve görüş hattı.
- Sıfır geçiş oranı: işaret değiştirme sayısı; ortalama ve medyan geçiş, çoklu eşik.
- Zaman domeni: ortalama, varyans, standart sapma, medyan, RMS, sıfır geçiş. Frekans domeni: spektral enerji, FFT katsayıları toplamı.
- Hiyerarşi: Yapay zekâ ⊃ makine öğrenmesi ⊃ derin öğrenme; veri madenciliği ve veri bilimi ayrı kümeler.
- Veri bölme: 8-1-1 ya da 6-2-2.
- Kirli veri: eksik, gürültülü, tutarsız.
- Normalizasyon: [0, 1] ya da [-1, 1].
- Mobilde hibrit karar: net bölgede kural, belirsiz bölgede öğrenme.

## Detaylı Açıklamalar

- Sinyal vektör büyüklüğü ile işlem azaltma: Üç eksenli bir sensörde her eksen için ayrı pencere gezdirmek ve öznitelik çıkarmak üç kat hesap demektir. Eksenlerin karelerinin toplamının karekökü alınarak oluşturulan SVM ekseni, cihazın yönelimden bağımsız toplam hareket büyüklüğünü verir. Hoca, yalnız bu eksenle bile birçok problemde yüksek başarı alındığını söyledi. Aynı fikir jiroskop ve manyetometre için de geçerlidir.

- Sürüş analizi ve konfor: Sürüş, alt aktivitelerden (manevralardan) oluşan bir aktivitedir. Bu manevralar aracın fiziksel hareketinden ivmeölçer ve jiroskopla çıkarılır. Elde edilen bilgi sigorta primleri, yol bakım planlaması, risk haritaları, trafik yoğunluğu ve yakıt tüketimi için kullanılabilir. Ani hızlanma ve yavaşlama hem konforu hem güvenliği düşürür hem de yakıt tüketimini artırır. Otonom araçlar yaygınlaştığında aynı analiz sürücüyü değil aracın yazılımını değerlendirmek için kullanılacaktır. Konfor puanı için hoca ideal sürüşü A'dan B'ye düz, sabit hızlı ve ivmesiz bir hareket olarak tanımladı; pratikte düz ve kaliteli bir yolda ölçülen küçük ivme referans alınır. İvme, kişiye uygulanan kuvvetle doğru orantılı olduğundan konforun doğal ölçüsüdür. Koltuk, araç ağırlığı, ses yalıtımı gibi etkenler aynı ivmenin hissedilişini değiştirir; bunu ölçmek için kas gerginliği sensörleri gibi biyosensörler denenir ama bunlar müdahalecidir.

- Sürücü yorgunluğu ve dikkat: Aynı hızla giden araçta sürücü, çevresindeki tüm etkenleri izlemek zorunda olduğu için yolcudan daha çok yorulur. Bu dikkat yükü doğrudan ölçülemez; göz kırpma sıklığı, göz açıklığı, aynalara bakma sıklığı ve başın ne kadar süre yana ya da arkaya döndüğü kamerayla izlenerek tahmin edilir. ADAS sistemleri ve araçtan araca ağlar ileride çevredeki araçların güvenlik düzeyini de paylaşabilecektir.

- Parmak izi kavramı: Face ID, parmak izi okuyucu, ses tanıma ve şarkı tanıma uygulamalarında ham veri değil, ayırt edici noktalardan oluşan bir "parmak izi" karşılaştırılır. Örneğin sesin belirli bir frekans bandında olduğu bilindiği için bu bandın dışı atılabilir. Bu yaklaşım ayırt edici öznitelik fikrinin özüdür: ne kadar az ve ne kadar ayırt edici öznitelik kullanılırsa işlem yükü o kadar azalır. Öznitelikleri veriyi toplayan cihazda (uçta) çıkarıp yalnız onları göndermek, iletişim maliyetini de düşürür.

- İç mekân konumlama karşılaştırması: Slayttaki karşılaştırmaya göre Wi-Fi parmak izi, sinyal veritabanı ve iç mekân haritalarıyla birlikte doğruluğu artırır. Bluetooth 10-30 m menzilde 5-10 m hassasiyet verir ve çok erişim noktası ister. RFID 200 m'ye kadar menzile sahiptir. UWB çok hassastır (<0,3 m) ama menzili düşük ve maliyeti yüksektir. Ultrason ~1 cm hassasiyet verir ama girişime açıktır. Kızılötesi ~1 mm hassasiyet verir ama görüş hattı gerektirir (ekrandan, 01:15:00). Hoca, Bluetooth sinyalinin kalın duvarlardan çok etkilendiğini; ultrasonun araçlarda park sensörü olarak, pasif kızılötesinin (PIR) otomatik kapılarda ve apartmanlarda kullanıldığını ekledi.

- Zaman domeni öznitelikleri: Slayttaki tanımlar (ekrandan, 01:35:00): sıfır geçişleri, sinyalin sinyal aralığının yarısına karşılık gelen belirli bir değeri kestiği nokta sayısıdır; kaynaktaki çalışmada bu değer pencerenin ortalamasıdır. RMS, $n$ ayrık değerden oluşan sinyal için hesaplanır. Ortalama penceredeki tüm örneklerin ortalaması, varyans örneklerin ortalamadan farklarının karelerinin ortalaması, standart sapma varyansın karekökü, medyan pencereyi üst ve alt yarıya bölen değerdir. Frekans tarafında spektral enerji, spektral katsayıların karelerinin toplamının pencere uzunluğuna bölünmesidir; FFT katsayıları toplamında ana frekans bileşenlerini içeren ilk beş katsayı alınır. Hoca, sıfır geçiş oranının değişkenlerini de anlattı: ortalama ya da medyan geçiş oranı ve x eksenine paralel birden fazla eşik çizgisi. Sinyal bazen bir bantta sıkışıp gidip gelir; sıfır geçiş bunu göstermeyebilir ama ek çizgiler bir örüntü verir.

- Yapay zekâ kavramlarının ilişkisi: Yapay zekâ, insan beyninin problem çözme biçiminin bilgisayara öğretilmesidir ve en geniş kümedir. Makine öğrenmesi geçmiş veriden ve deneyimden öğrenir. Derin öğrenme, katman ve nöron sayısının arttığı, yeni ağ türlerinin ve büyük verinin GPU ile işlendiği sinir ağlarıdır; özellikle doğrusal olmayan problemlerde başarılıdır. Veri madenciliği verideki ilişkileri ortaya çıkarır (örneğin satılan ürünler arasındaki ilişki). Veri bilimi ise bu yöntemleri veri üzerinde kullanan herkesin alanı olarak geniş ve farklı bir kümeye konur.

- Veri ön işleme: Ön işleme, bilgi çıkarma algoritmalarından önce kaliteli veriyi ortaya çıkarma işidir (ekrandan, 02:20:00). Hoca normalizasyonun nedenini şöyle örnekledi: 0-10 aralığındaki 9 ile 0-100 aralığındaki 9'un etkisi farklıdır; aynı aralığa indirgenmezse bir öznitelik öğrenmeye daha çok etki eder. [-1, 1] aralığı genelde pozitif-negatif karşıtlığı olan verilerde tercih edilir. Aykırı değerlerin gerçek olup olmadığına karar vermek tecrübe ister: gerçek hayatta var olan uç değerler kararı bozmuyorsa tutulur, bozuyorsa atılır.

- Mobil cihazda karar yaklaşımı: Kural tabanlı yaklaşım en az kaynak tüketir. Başarı tatmin ediciyse kural tabanlı sistem en akıllıca seçimdir. Düşme tespitinde eşiğin üstü ve altı net karar verir, aradaki belirsiz bölge daha gelişmiş bir modele gönderilir. Bu hibrit yapı, her şeyi makine öğrenmesine göndermeye göre ciddi enerji tasarrufu sağlar.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
