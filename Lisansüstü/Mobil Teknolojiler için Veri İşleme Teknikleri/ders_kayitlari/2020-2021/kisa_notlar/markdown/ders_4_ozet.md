# Ders 4 Çalışma Özeti

## Genel Konular

- Derleme (survey) makalesi nedir, nasıl hazırlanır
  - Araştırma makalesi yeni bir yöntem ya da deney sonucu sunar. Derleme makalesi ise bir alanda o güne kadar yapılmış çalışmaları tarar, gruplar, karşılaştırır ve okuyana alanın temel bilgisini verir.
  - Derleme makalesi her şeyi toplayıp sunmakla kalmamalıdır. Özgün bir bakış açısı ya da başka araştırmacıları tetikleyecek bir fikir ortaya koymalıdır; yoksa genelde kabul görmez.
  - Tipik bir derlemede 80-150 kadar çalışma taranır. Bunların hepsi ayrıntısıyla okunmaz; hangi alt alanlara girdikleri belirlenerek gruplanır.
  - Doktora öğrencisi için en büyük kazanç, alandaki açık problemleri görmektir. Derlemelerde bunun için genelde "Open Issues" bölümü bulunur.
- Derleme makalesinin yapısı ve yazım sırası
  - Önce bir taslak (outline) çıkarılır: işlenecek başlıklar ve alt başlıklar. Tarama ilerledikçe outline yeniden şekillendirilir.
  - Bölümler: Abstract, Introduction, konuya göre belirlenen 3-4 ana bölüm (ayrı bir "Related Work" bölümü olmaz), Open Issues, Conclusion.
  - Abstract ve Conclusion en sona bırakılır. Introduction da çoğunlukla sona yakın yazılır.
  - Introduction'da problem, motivasyon, alandaki çalışma türleri, yakın derlemeler ve makalenin geri kalanının akışı anlatılır.
  - Çalışmaları gruplamak (kategorize etmek) derlemenin özüdür; problemi alt problemlere indirgemek ancak böyle mümkün olur.
- Literatür tarama yöntemi
  - İlk durak Google Scholar'dır. Yayın tarihi (güncellik) ve atıf sayısına bakılır. Son beş yıl en kritik dönemdir, ama son 10-20 yılın çok atıf almış "kült" çalışmaları da atlanmamalıdır.
  - Dergi makaleleri genelde bir adım öndedir, ama iyi konferans bildirileri de gözden kaçırılmamalıdır.
  - Yayıncı veritabanları da taranır: IEEE Xplore, Scopus, ScienceDirect, Springer.
  - En büyük rakip aynı alandaki önceki derlemelerdir. Bir alanda derleme olması yenisinin yazılamayacağı anlamına gelmez: farklı bir gruplama ya da eski derlemeden sonra gelen yöntemler (örneğin klasik makine öğrenmesinden derin öğrenmeye geçiş) yeni bir derlemeyi haklı çıkarır.
  - Anahtar kelime seçimi kritiktir. Alan, akla gelmeyen başka bir terimle genişlemiş olabilir (örnek: multimedia/video sensor network aramalarının yerine "directional sensor network" kavramına ulaşmak).
  - Bulunan çalışmaların kaynakçası geriye doğru özyinelemeli taranır. Patent, kitap ve tez de kaynak olabilir.
- Trafik akış (hız) tahmini problemine bakış açıları
  - Tahmin ufku: kısa vadeli (yaklaşık 1-2 saate kadar), orta vadeli (yaklaşık 2 saat ile 5-6 saat arası), uzun vadeli (ertesi gün, 12 saat, iki gün sonrası). Literatürde en çok kısa vadeli çalışma vardır; uzun vadeli çalışma azdır.
  - Terimler: traffic prediction, traffic flow prediction, traffic speed prediction, traffic flow speed prediction, traffic flow estimation, traffic estimation.
  - Yöntem aileleri: istatistiksel yöntemler, örnek tabanlı öğrenme (instance-based learning), derin öğrenme.
  - Girdi parametreleri: zaman (saat, haftanın günü, ay), hava durumu, araç tipi, etkinlikler (maç, konser, düğün, bayram kutlamaları), doğal afetler, bayram gibi özel dönemler, yol bakım çalışmaları ve şerit kapamaları, kaza sıklığı, trafik ışıkları ve viraj gibi yapısal özellikler, komşu lokasyonların bilgisi.
  - Veri kaynakları iki anlamda düşünülür: parametrelerin alınacağı kaynaklar (açık veri, API, temin edilemeyenler) ve hız verisinin toplandığı kaynaklar (araçlar, telefonlar, Bluetooth okuyan tabelalar, yol kenarı birimleri, yola gömülü dedektörler).
  - Problem türü: geçmişteki etiketli veriden öğrenildiği için gözetimli, sürekli bir değer (hız) tahmin edildiği için regresyon problemidir. Bölgeyi kırmızı, sarı, yeşil diye etiketlemek istenseydi sınıflandırmaya indirgenebilirdi.
  - Başarım ölçütleri: karesel hata (kökü alınarak ya da alınmadan), MAE (Mean Absolute Error), MAPE (Mean Absolute Percentage Error).
  - Lokasyon başına ayrı model ile benzer lokasyonları kümeleyip ortak model kurma arasındaki seçim.
  - Tahmini en zor lokasyonları bulmak için hızların standart sapmasına bakılabilir.
  - Problemin ikinci ucu: lokasyon bazlı hız tahminleri rotalama algoritmalarıyla birleştirilerek en hızlı rota üretilir.
- Mobil hesaplama (Mobile World)
  - Mobil hesaplama, verinin, sesin ve görüntünün sabit bir fiziksel bağlantıya gerek olmadan bilgisayar ya da kablosuz bir cihaz üzerinden iletilmesini sağlayan teknolojidir (ekrandan, 01:15:00).
  - Üç bileşeni vardır: mobil iletişim, mobil donanım, mobil yazılım (ekrandan, 01:20:00).
  - Ambient intelligence kavramı, günümüzde yerini "smart" ön ekli alt alanlara (akıllı ulaşım, akıllı şehir, akıllı binalar) bırakmıştır.
  - Bugünkü anlamıyla dijital kablosuz veri iletimi yaklaşık 20 yıllık bir hikâyedir. Dönüm noktası 2007-2008'de akıllı telefonların gelişidir.
  - Mobil donanımda ARM'nin RISC mimarisi enerji verimliliği sayesinde öne çıkmıştır.
- Telefonların evrimi ve feature phone kavramı
  - Telefonların evrimi zaman çizelgesiyle gösterildi (ekrandan, 01:35:00).
  - Feature phone yalnız konuşma ve mesajlaşma yapılabilen eski tip telefondur. Bunlarda tam bir işletim sistemi değil, gömülü bir ara katman (middleware) vardır.
  - KaiOS, feature phone'ları hedefleyen ve temel uygulamaları bir mağaza üzerinden sunan işletim sistemidir.
- Mobil hesaplamanın dezavantajları ve enerji tüketimi
  - Slayttaki dezavantajlar: pahalı, kısa pil ömrü, küçük ekran, yavaş internet, ağa bağımlı iletişim, taşıma riski, güvenlik (ekrandan, 01:40:00). Hocaya göre yavaş internet artık sorun değildir, kısa pil ömrü hâlâ sorundur.
  - En çok enerji tüketenler: hücresel haberleşme ve ekran; ardından GPS, Bluetooth ve kamera.
  - Ekran enerjisini azaltma: OLED (piksellerin tek tek yanıp sönmesi), koyu tema, e-mürekkep ekranlar.
  - Diğer yöntemler: işlemci frekansını düşürmek, sensörler için ayrı bir işlemci kullanmak, arka plan işlerinin sıklığını kısmak, bildirimleri gruplamak.
- Mobil işletim sistemleri
  - İşletim sistemi kategorileri: masaüstü, mobil, sunucu, gömülü (TinyOS, Contiki gibi sensör ağı işletim sistemleri), gerçek zamanlı.
  - Mobil işletim sistemlerinin zaman çizelgesi (Symbian, LiMo, MeeGo, Tizen, webOS, Windows Mobile/Phone, bada, iOS, Android) ve güncel sistemlerin listesi (ekrandan, 02:05:00; 02:10:00).
  - Android mimarisi dört katmandır: Applications, Application Framework, Libraries + Android Runtime, Linux Kernel (ekrandan, 02:15:00).
  - Android'deki iki yenilik: APK yerine Android App Bundle (AAB) ve Dalvik sanal makinesi yerine Android Runtime (ART).
  - iOS da dört katmanlıdır: Cocoa Touch, Media Layer, Core Services Layer, Core OS Layer.
- Mobil işletim sistemi ile PC işletim sistemi arasındaki farklar (ekrandan, 02:20:00)
  - Güç: Android'de işlemci ve ekran varsayılan olarak kapanır; açık tutmak isteyen süreç "wake-lock" almalıdır.
  - Arayüz: dokunmatik ekran ana girdidir; tuş takımı ve ses destekler.
  - Bellek: Linux'taki "out of memory" desteğine ek olarak Android "Low Memory Killer" ile kullanılmayan uygulamaları sonlandırır; C kütüphanesi olarak glibc yerine bionic kullanılır.
  - İletişim işlemcisi: GPRS/EDGE/3G/LTE ayrı bir işlemci ve özel bir işletim sistemiyle yürütülür.
  - Taşınabilirlik: x86 masaüstü için, ARM gömülü sistemler için tasarlanmıştır; mobil işletim sistemleri başlıca ARM üzerinde çalışır.
- Mobil işletim sistemi tasarım ölçütleri ve güvenlik
  - Ölçütler: belleğin etkin kullanımı, performans, enerji verimliliği, kullanıcı deneyimi, güvenlik.
  - Güvenlikte iOS öndedir: donanımı ve yazılımı aynı firma üretir, donanım çeşitliliği azdır. Android ise onlarca markaya hizmet eder.
  - Zararlı yazılım tespiti: statik kod analizi, anormal davranış tespiti, sandbox ortamında çalıştırma.
  - Akıllı zararlı yazılımlar gerçek telefonda mı çalıştıklarını sınar. Buna karşı gerçek kullanıcı davranışını (arama, mesaj, GPS, ivmeölçer ve jiroskop verisi) taklit eden sandbox'lar geliştirilmiştir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Derleme makalesinin değeri açık problemleri ortaya koymasındadır
  - "Open Issues" bölümü, hem yazarın kendi araştırma yolunu çizmesini hem de okuyanların "bu alan hâlâ açık" diyerek yararlanmasını sağlar.
- Çalışmaları gruplamak
  - Tarama yapınca çok sayıda çalışma birikir. Gruplamadan problemi alt problemlere indirgemek mümkün değildir. Önceki derlemelerden farklı bir gruplama başlı başına bir katkıdır.
- Anahtar kelimeler
  - Alan beklenmedik bir terimle genişlemiş olabilir. Hoca bunu "directional sensor network" kavramıyla örnekledi: kamera ve mikrofon gibi yönlü sensörler etrafını 360 derece değil, belirli bir açıyla algılar.
- Trafik tahmininde ölçütlerin karşılaştırılabilirliği
  - Çalışmalar genelde farklı şehirlerin veri setlerini kullandığı için iki yöntemin başarısını doğrudan karşılaştırmak çoğu zaman "elma ile armut" karşılaştırmasına döner.
  - Mutlak hata ile yüzde hata farklı şeyler söyler: 30 km/sa'te 6 km/sa sapma %20, 60 km/sa'te aynı 6 km/sa sapma %10'dur.
- Kaynak (özellikle enerji) yönetimi mobil işletim sistemlerinin birinci önceliğidir
  - Bir uygulamaya kullanıcının ilk baktığı şeylerden biri pil tüketimidir. İşletim sisteminin yeteneklerini (örneğin wake-lock) bilmeden yazılan arka plan uygulaması beklendiği gibi çalışmayabilir.
- Pil teknolojisi
  - Hocaya göre devrim yaratacak alanlardan biri enerji depolamadır. Kaynak optimizasyonu probleminin kökü buradadır.

## Kısa Tekrar Notları

- Derleme makalesi: tarama, gruplama, karşılaştırma ve açık problemler; özgün bir bakış açısı şart.
- Yapı: Abstract, Introduction, 3-4 ana bölüm, Open Issues, Conclusion. Abstract ve Conclusion en son yazılır.
- Tarama: Google Scholar, IEEE Xplore, Scopus, ScienceDirect, Springer; atıf sayısı ve güncellik; kaynakçadan geriye doğru tarama.
- Trafik akış tahmini: kısa, orta ve uzun vadeli; gözetimli regresyon; ölçütler karesel hata (kökü alınmış ya da alınmamış), MAE, MAPE.
- Girdiler: zaman, hava, etkinlik, afet, özel dönem, yol çalışması, kaza sıklığı, yol yapısı, komşu lokasyonlar.
- Zor lokasyonları bulmak için hızların standart sapmasına bakılır. Benzer lokasyonlar kümelenip ortak model kurulabilir.
- Mobil hesaplama: iletişim, donanım, yazılım.
- En çok enerji: hücresel iletişim ve ekran; ardından GPS, Bluetooth, kamera.
- Ekran enerjisi: OLED ve koyu tema.
- İşletim sistemi türleri: masaüstü, mobil, sunucu, gömülü, gerçek zamanlı.
- Android: 4 katman; AAB ile cihaza özel paket; ART ile kurulumda derleme.
- iOS: Cocoa Touch, Media, Core Services, Core OS.
- Mobil ve PC işletim sistemi farkı: güç (wake-lock), arayüz, bellek (Low Memory Killer, bionic), iletişim işlemcisi, taşınabilirlik (ARM).
- Zararlı yazılıma karşı: statik analiz, davranış analizi, sandbox; gerçek kullanıcıyı taklit eden sandbox.

## Detaylı Açıklamalar

- **Derleme makalesi ve literatür taraması.** Dersin ilk bölümünde hoca, mobil ve yaygın hesaplamanın uygulama alanlarından akıllı ulaşıma bağlı bir derleme çalışmasının nasıl hazırlanacağını anlattı. Derleme makalesi yeni bir test sonucu sunmaz. Mevcut çalışmaları anlamlı gruplara ayırır, yöntemlerini ve başarılarını karşılaştırır ve alanda hâlâ çözülmemiş noktaları "Open Issues" başlığında toplar. İşe bir outline ile başlanır. Outline tarama sırasında görülenlere göre yeniden düzenlenir; "bir yerden yazmaya başlarım, sonra toparlarım" yaklaşımı iyi sonuç vermez. Taramada Google Scholar'da anahtar kelimelerle başlanır. Atıf sayısı düşük bir çalışma değersiz değildir, ama çok atıf almış güncel çalışmalar kaçırılmamalıdır. Önceki derlemeler hem rakip hem rehberdir: onların hangi bakış açısıyla gruplandığı incelenir ve farklı bir gruplama aranır. Bulunan çalışmaların kaynakçasını geriye doğru izlemek, veritabanı aramalarında çıkmayan çalışmaları da ortaya çıkarır.
- **Trafik akış tahmini problemi.** Hava durumu tahmini gibi, belirli bir lokasyonda belirli bir saat ve dakikada trafik akış hızının ne olacağı tahmin edilir. Geçmişte "şu koşullarda hız şu olmuştu" diye etiketlenmiş veri kullanıldığı için problem gözetimlidir. Tahmin edilen değer sürekli olduğu için bir regresyon problemidir. Hata için karesel hata (ya da kökü), MAE ve MAPE kullanılır. Hocanın sayısal örneği: gerçek hız 30 km/sa iken 36 km/sa tahmin edilirse sapma 6 km/sa, yüzdesel hata %20'dir; gerçek hız 60 km/sa iken 6 km/sa sapmanın yüzdesel hatası %10'dur. Düşük ve yüksek hızlardaki sapmanın etkisi farklı olduğundan hangi ölçütün daha anlamlı olduğu tartışılmalıdır. Bir şehirde eğitilen modelin başka bir şehirde aynı başarıyı verip vermeyeceği de açık bir sorudur. Büyük bir şehirde binlerce sensör lokasyonu vardır. Her lokasyona ayrı model kurmak en özel ama en maliyetli çözümdür. Trafik karakteristiği benzeyen lokasyonları kümeleyip ortak model kurmak daha verimlidir; iki yaklaşım arasındaki başarı farkı araştırılmaya değer bir konudur. Sınırlı zamanda önce en zor lokasyonlarla uğraşmak gerekiyorsa, hızların standart sapması yüksek olan lokasyonlar değişkenliği yüksek, karakteristik davranmayan yerlere iyi bir ipucudur. Ana arterler ve en çok talep edilen noktalar da öncelik ölçütü olabilir. Komşu sensörler (örneğin bir köprü girişinin arkasındaki ardışık sensörler) birbirine bağlı bir graf oluşturur; bu bağlantıların bilgisi tahmini iyileştirebilir. Hız verisi açık yolda yavaş giden bir araçtan (kamyon ya da yavaş sürücü) geliyorsa, o bölgenin olası hızı olduğundan düşük görünebilir.
- **Mobil hesaplama ve donanım.** Mobil hesaplama kullanıcıyı konumdan, zamandan ve cihazdan bağımsız hâle getirdi. Hareketlilik üç başlık getirdi: mobil iletişim (çeşitli protokoller), mobil donanım (telefonlar, giyilebilir cihazlar, gömülü sistemler) ve mobil yazılım. İşlemci tarafında ARM, azaltılmış komut kümeli (RISC) mimarisiyle enerji verimliliğinde öne geçti ve bu pazarda kalıcı oldu. Akıllı telefonu akıllı yapan; işlem gücü, çevresiyle iletişim kurabilmesi ve kamera, mikrofon ve çeşitli sensörlerdir.
- **Enerji ve kaynak yönetimi.** Mobil işletim sistemlerindeki hemen her farkın kökü kısıtlı kaynakların, özellikle pilin yönetimidir. Bir öğrencinin değindiği big.LITTLE mimarisinde güç gerektiren işler büyük çekirdeklerde, diğerleri küçük çekirdeklerde çalışır; bunu yönetmek işletim sisteminin görevidir. İletişim sıklığını ayarlamak da enerji yönetiminin parçasıdır. Ekran tarafında OLED ekranlar arka ışık gerektirmediği için tam siyah verir ve enerji tasarrufu sağlar; koyu temaların yaygınlaşması bu yüzdendir. Bir öğrenci, mobil uygulamaların çoğunun az sayıda iş parçacığı kullandığını, tek çekirdeği zorlayan bir uygulamada ısınma nedeniyle frekans düşünce çalışma süresinin birkaç katına çıkabildiğini anlattı. Hoca da donanım ile yazılımın paralel gitmediği bu tür noktaların araştırılmaya değer olduğunu söyledi. Eski telefonlar çöpe gitmek yerine birer sensör düğümü (kamera, mikrofon) ya da IoT cihazı olarak kullanılabilir; örneğin ek donanım almadan bir bebek monitörü yapılabilir.
- **Android mimarisi ve yenilikler.** En üstte uygulamalar, altında uygulama geliştirmede kullanılan yönetici ve sağlayıcıları içeren Application Framework, onun altında performans için sunulan kütüphaneler ve Android Runtime, en altta da sürücüleri ve güç yönetimini içeren Linux çekirdeği bulunur. Native Development Kit ile yazılan yerel kütüphaneler Java üzerinden (JNI ile) çağrılabilir. Android App Bundle ile bütün cihaz seçenekleri (ikon boyutları, fontlar, diller) merkezde tutulur ve indiren cihaza yalnız ona uygun parçalar gönderilir. Hocanın örneğinde 60 MB'lık bir paket yerine 10-20 MB'lık bir paket iner; indirme trafiği azalır, depoda daha az yer kaplanır ve kurulum hızlanır. Android Runtime'da kod çalışma anında yorumlanmak yerine kurulum sırasında derlenir. Kurulum yavaşlar ve daha fazla alan gerekir, ama çalışma anında performans artar.
- **Bellek yönetimi.** PC'de bellek yetmediğinde sayfalama (paging) ile veri ikincil belleğe taşınır. Mobilde flash belleğe gidip gelmek daha maliyetli olduğundan Android, aktivitenin durumuna göre kullanıcıdan onay almadan uygulamaları bellekten silebilir (Low Memory Killer). Bir öğrenci, bazı özel Android sürümlerinde swap alanı eklenebildiğini hatırlattı.
- **Güvenlik ve zararlı yazılım.** iOS'ta donanım ve yazılım aynı firmadan gelir ve donanım çeşitliliği azdır. Android'de ise çok sayıda marka vardır; her donanımı yönetecek kodu sisteme gömmek sistemi yavaşlatır, bu da güvenliği zorlaştırır. Mağazalar zararlı yazılımı statik kod analizi ve sandbox'ta çalıştırma ile yakalamaya çalışır. Akıllı zararlı yazılımlar ise gerçek bir telefonda olup olmadıklarını işlemci frekansı, ısınma, RAM performansı gibi kaynak davranışlarından, daha ileri aşamada da telefonun gerçekten bir kullanıcı tarafından kullanılıp kullanılmadığından (taşınma, arama, mesaj, GPS değişimi, ivmeölçer ve jiroskop verisi) anlamaya çalışır. Buna karşı gerçek kullanıcı davranışını modelleyen sandbox'lar geliştirilmektedir; hoca bunu güncel bir araştırma konusu olarak gösterdi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
