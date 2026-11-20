# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin kapsamı ve kaynakları
  - Ders, mobil teknolojiler hakkında genel bilgi verdikten sonra Android'de native uygulama geliştirmenin temel yapı taşlarını tanıtmayı amaçlar: uygulama yaşam döngüsü, Activity, Intent, layout türleri, arayüz bileşenleri, aktiviteler ve uygulamalar arası veri taşıma, veri saklama, sensörler, BroadcastReceiver, bildirimler, arka plan görevleri, konum tabanlı servisler, haritalar ve uygulama mağazaları.
  - Ana kaynak `developer.android.com` sayfasıdır. Ders kitabı Bill Phillips ve Brian Hardy'nin "Android Programming: The Big Nerd Ranch Guide" (3. baskı) kitabıdır. Yardımcı kitap Dawn ve David Griffiths'in "Head First Android Development: A Brain-Friendly Guide" (O'Reilly, 2014) kitabıdır (ekrandan, 00:10:00).
  - Android'de üç temel dil vardır: Java, Kotlin ve C++. Derste Java kullanılır; Kotlin, Java'nın hantal yapısından arındırılmış, Google'ın yatırım yaptığı daha sade bir dildir. Temel native programlama mantığı iki dilde de aynıdır.
  - Uygulamaların emülatörde de çalıştırılabileceği, ama mümkünse gerçek bir cihazda test etmenin avantajlı olduğu belirtilir.
- Pervasive (ubiquitous) computing
  - Slayttaki tanım: hesaplama yeteneğinin (genelde mikroişlemci biçiminde) günlük nesnelere gömülmesi; böylece nesneler etkin biçimde haberleşir ve kullanıcının bilgisayarla "bilgisayar olarak" etkileşim ihtiyacını en aza indirerek yararlı işler yapar. Bu cihazlar ağa bağlıdır ve sürekli erişilebilirdir (ekrandan, 00:30:00).
  - Slogan: "Anywhere, Anytime, Any Device, Any Network, Any Data" (ekrandan, 00:40:00).
  - İşi sabit bir noktadan değil, herhangi bir cihazdan kaldığı yerden sürdürmek; bunu bulut bilişim (cloud computing) sağlar. Eskiden iş USB bellek ya da harici diskle taşınıyordu.
  - Cihazların gelişimi: el terminalleri (handheld) → cep telefonu → tablet → akıllı saat, bileklik ve giyilebilir teknolojiler (baret, eldiven, giysi).
  - Bir akıllı telefon onlarca cihazın (kamera, video kaydedici, not defteri, kitap, el feneri, sağlık izleme) yerini tutar. VR (Virtual Reality) ve AR (Augmented Reality) bu teknolojilere eşlik eder.
- Kablosuz haberleşme ve kısıtlar
  - Mobil cihazın en önemli yeteneklerinden biri kablosuz haberleşmedir: GPS (en çok enerji tüketenlerden), hücresel ağlar (2G, 3G, 4G/LTE, 5G; 6G çalışmaları), Wi-Fi (erişim noktasına yıldız topoloji), Bluetooth, NFC.
  - Her protokolün enerji tüketimi, veri aktarım kapasitesi ve bağlanabilecek cihaz sayısı farklıdır.
  - En büyük kısıt pildir. Uygulamanın kaynak, özellikle pil konusunda "cimri" olması beklenir.
- Kablosuz sensör ağlarından (WSN) IoT'ye
  - WSN: özel donanıma sensör yerleştirilerek bir ortamdan (orman, okyanus, hayvan sürüsü, askeri bölge) veri toplamak için kurulan ağlardır. Veri düğümlerden merkeze akar, bant genişliği dardır, enerji kısıtı çok önemlidir; düğümler zor coğrafyaya bir kez (uçakla vb.) bırakılır.
  - İnsan için beş duyu ne ise elektronik cihaz için sensörler odur (kamera, mikrofon, ivmeölçer, jiroskop, Wi-Fi ve baz istasyonu paketleri). Örnek: yakınlık sensörü, telefon kulağa götürülünce ekranı kapatır (enerji tasarrufu ve yanlışlıkla tuşa basmayı önleme).
  - Ortamdan bilgi alıp ortamın durumunu anlayan uygulamalar Ambient Intelligence (çevresel zeka) olarak adlandırılır; bu kavram bugün IoT uygulamalarına dönüşmüştür.
  - WSN düğümlerini hareketli yapmak zor ve pahalıdır; telefon doğal olarak hareket eden bir sensör grubu oluşturur. WSN düğümlerinin IP adresi yoktu; nesnelere IP adresi verilince doğrudan erişim mümkün olur ve IoT doğar.
  - IPv4 32 bit olduğu için adresler tükenmiştir; 128 bitlik ve güvenlik açısından daha güçlü IPv6 gelecekte kaçınılmaz olacaktır. IoT, makineler arası iletişimin (machine to machine) önünü açar.
- Pervasive computing'in alt alanları ve evrimi
  - Pervasive computing'den cloud computing, IoT, büyük veri (big data) ve veri bilimi (data science) gibi alt alanlar çıkar.
  - Evrim: Distributed Computing → Mobile Computing → Pervasive Computing (ekrandan, 01:00:00). Mobile computing üç ana başlıktır: mobile hardware, mobile software, mobile communication.
  - Eğitilmiş bir derin öğrenme modeli telefonda ya da saatte çalıştırılabilir; eğitim için ise GPU gibi güçlü donanım gerekir. Yeni eğilim, eğitimi telefonlara dağıtmaktır (hocanın deyişiyle "Federated Computing").
  - Katmanlı yapı: sensörler, gömülü hesaplama, düşük maliyetli ve düşük güçlü bağlantı (ubiquitous mobility) → akıllı malzeme ve tasarım, IoT uygulamaları (IoT) → pervasive computing uygulamaları (multi-device experience) (ekrandan, 01:05:00).
- Gömülü sistemler ve mobil işletim sistemleri
  - IoT cihazlarında çoğunlukla işletim sistemi yoktur; oyun konsollarında bir framework vardır; belirli işleri adanmış biçimde yapan cihazlar (çamaşır makinesi vb.) gömülü sistemdir.
  - Telefonlar masaüstü işletim sistemini taşıyamaz (pil dakikalar içinde biter); sadeleştirilmiş işletim sistemleri kullanılır. Android, sadeleştirilmiş Linux çekirdeği üzerine; iOS ise BSD tabanlı Unix türevi bir yapı üzerine kurulur. Akıllı telefonlar 2007-2008'den itibaren yaygınlaşmıştır.
  - Yaygın işletim sistemleri Android ve iOS'tur; düşük profilli telefonlar için KaiOS da vardır.
- Mobil uygulamalar ve geliştirme yaklaşımları
  - Telefon, tablet, akıllı saat ve akıllı TV gibi her platformun bir uygulama marketi vardır. Tarayıcı eklentileri de benzer mantıkla çalışır.
  - Yaklaşımlar: native (platformun SDK'sı ile cihazın bütün yeteneklerine erişim), cross-platform (tek kodla birden fazla platform), Progressive Web App ve hybrid. Seçim hedefe, kullanılacak cihaz özelliklerine, hedef kitleye, ekibe ve bütçeye bağlıdır.
  - Ekranda bir karar akış şeması gösterildi: ucuzluk, donanım (kamera, GPS) gereksinimi, sınırlı performansın kabulü, e-ticaret uygulaması olup olmadığı ve iki ayrı ekip kurmaya hazır olunup olunmadığı sorularına göre hybrid, cross-platform, PWA ya da native seçilir (ekrandan, 01:10:00).
  - Uygulama kategorileri: sosyal medya, mesajlaşma, oyun, sağlık, konum tabanlı. SMS'ten anlık mesajlaşmaya, oradan sosyal medyaya geçiş.
  - Toplanan veriyle yapılan çıkarımlar: trafik süresi tahmini, hava durumu ve mevsimsel tahmin, sosyal medya analizleri, kestirimci bakım (predictive maintenance).

## Hocanın Özellikle Vurguladığı Kısımlar

- Bugün mobil uygulama geliştirmek teknik olarak zor değildir
  - Kütüphaneler, SDK'lar ve cross-platform araçlar çok gelişmiştir. Değerli olan, uygulama fikri üretmek, toplanan veriden çıkarım yapmak ve insan hayatını kolaylaştıran uygulamalar geliştirmektir.
- İyi bir mobil uygulamanın ölçütleri
  - Az enerji ve kaynak tüketmek; kullanıcı deneyimi (UX) yüksek, arayüzü (UI) sade ve anlaşılır olmak; özellikleri iyi organize etmek.
  - Veri saklama ve merkeze aktarma, yedekleme gibi işlerin pil durumu ve şarja bağlı olup olmama gibi telefonun durumu gözetilerek yapılması uygulamayı tercih edilir kılar.
- Mobil teknolojilere ait terminoloji
  - Dersin amaçlarından biri terminolojiyi aktarmaktır: IoT, kablosuz sensör ağları, mobil işletim sistemleri gibi kavramların bilinmesi beklenir.
- Pil kısıtı
  - Uygulamanın ne sıklıkla kullanılacağı, enerji tüketimine ne kadar dikkat edilmesi gerektiği ve cross-platform aracın native'e göre kaynak tüketimini değiştirip değiştirmediği önemli sorulardır.

## Kısa Tekrar Notları

- Pervasive computing = ubiquitous computing: hesaplamanın günlük nesnelere gömülmesi; cihazlar ağa bağlı ve sürekli erişilebilir.
- Slogan: Anywhere, Anytime, Any Device, Any Network, Any Data.
- Evrim: Distributed → Mobile → Pervasive Computing.
- Mobile computing: hardware, software, communication.
- Kablosuz haberleşme: GPS, hücresel (2G-5G), Wi-Fi, Bluetooth, NFC.
- WSN: veri merkeze akar, dar bant, enerji kısıtı; düğümlerin IP adresi yok.
- IoT: nesnelere IP adresi; IPv4 32 bit (tükendi), IPv6 128 bit.
- Ambient Intelligence: ortamı algılayan uygulamalar; bugün IoT.
- Gömülü sistem: belirli bir işi adanmış biçimde yapan cihaz, çoğu zaman işletim sistemsiz.
- Android: Linux çekirdeği; iOS: BSD tabanlı Unix türevi. Düşük profilli telefonlar: KaiOS.
- Android dilleri: Java, Kotlin, C++.
- Geliştirme yaklaşımları: native, cross-platform, PWA, hybrid.
- Eğitilmiş model telefonda çalışır; eğitim güçlü donanım ister; eğitimi cihazlara dağıtmak yeni eğilimdir.

## Detaylı Açıklamalar

- Pervasive computing kavramı, hesaplamanın masadaki bilgisayardan çıkıp her yere yayılmasını anlatır. Kullanıcı artık işini tek bir makineye bağlı kalmadan, bulutta saklanan veriye her cihazdan erişerek sürdürür. Telefonlar, saatler, bileklikler, akıllı TV'ler ve araçlar bu ekosistemin parçalarıdır. Bu cihazların değeri büyük ölçüde çevrim içi olmalarından gelir; bu yüzden kablosuz haberleşme yetenekleri (GPS, hücresel ağ, Wi-Fi, Bluetooth, NFC) merkezîdir. Her protokolün enerji tüketimi, hızı ve bağlanabilen cihaz sayısı farklıdır ve pil en büyük kısıttır.
- Hikayenin başlangıcı kablosuz sensör ağlarıdır. Bu ağlar özel donanımla, belirli bir ortamdan veri toplamak için kurulur; veri düğümler üzerinden merkeze akar. Orman yangınını önlemek için sıcaklık izlemek ya da askeri bölgeye izinsiz girişi tespit etmek tipik örneklerdir. Düğümleri hareket ettirmek zor ve pahalıdır ve düğümlere tek tek erişilemez, çünkü IP adresleri yoktur. Telefon, sahibiyle birlikte doğal olarak hareket eden bir sensör grubu olarak bu boşluğu doldurmuştur. Ardından var olan nesnelere sensör, işlem yeteneği ve IP adresi kazandırma fikri IoT'yi doğurmuştur. IPv4'ün 32 bitlik adres alanı bu kadar cihaza yetmediği için 128 bitlik IPv6'ya geçiş kaçınılmazdır.
- Pervasive computing bir çiçek gibi açılarak cloud computing, IoT, büyük veri ve veri bilimi gibi alt alanlar üretmiştir. Büyük verinin işlenmesi işlem gücü ve bellek ister; bugün telefonlar birkaç gigabaytlık bellekle 15 yıl önceki bilgisayarların disk kapasitesine yaklaşmıştır. Derin öğrenme modelleri telefonda çalıştırılabilir, çünkü bir sinir ağı ne kadar büyük olursa olsun çıkarım aşamasında basit matematiksel işlemler yapar; eğitim ise GPU gibi güçlü donanım ister. Eğitimi merkezî bir sunucu yerine çok sayıda mobil cihaza dağıtmak yeni bir araştırma eğilimidir.
- Telefonlar gömülü sistem olmaktan çıkmış, kendi işletim sistemleri olan cihazlardır. Ancak masaüstü işletim sistemi telefonda pili dakikalar içinde bitirir, çünkü işletim sistemi cihazın olmayan yeteneklerini de yönetmeye çalışır. Bu yüzden Android sadeleştirilmiş bir Linux çekirdeği üzerine, iOS ise BSD tabanlı Unix türevi bir yapı üzerine kurulmuştur.
- Mobil uygulama geliştirirken native, cross-platform, PWA ve hybrid yaklaşımlarından biri seçilir. Ekranda gösterilen karşılaştırma tablosuna göre native uygulama cihazın ve işletim sisteminin bütün özelliklerine erişir ve güçlü performans verir, ama her platform için ayrı kod tabanı ister; hybrid uygulama tarayıcı motoruyla çalışır, geliştirme maliyeti düşüktür ama performansı ve işletim sistemi özelliklerine erişimi sınırlıdır; cross-platform uygulama tek kod tabanıyla farklı işletim sistemlerini destekler ve arayüz performansı native'e yakındır (ekrandan, 01:20:00). Ayrıntılı karşılaştırma sonraki derse bırakılmıştır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
