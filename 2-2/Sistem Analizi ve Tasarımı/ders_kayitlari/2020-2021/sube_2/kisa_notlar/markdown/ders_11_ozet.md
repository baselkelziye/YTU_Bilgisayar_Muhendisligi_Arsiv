# Ders 11 Çalışma Özeti

## Genel Konular

- Kodlama (gerçekleştirme) aşaması (ekrandan, 00:10:00)
  - Kodlamaya tasarım tamamlanıp diyagramlar, algoritmalar ve sözde kodlar oluşturulduktan sonra geçilir. Büyük ölçekli bir bilgi sisteminde formal olarak ifade edilmiş bir çözüm önerisi (tasarım) olmadan kodlamaya başlanmaz.
  - Ardışıl (sıralama) diyagramları nesnelerin birlikte nasıl çalıştığını gösterir ama algoritmayı göstermez; algoritmalar için akış diyagramı ve sözde kod gerekir.
  - Nesneye yönelik kodlamada en az bağımlı birimden başlayıp en çok bağımlı (en karmaşık) birime doğru ilerlemek daha doğrudur.
  - Kodlama spesifikasyonlara (şirket politikası, ISO/IEEE gibi standartlar) uymalı, kolay okunabilmeli, düzenlenebilmeli, test edilebilmeli ve başkaları tarafından değiştirilebilmelidir.
  - Kodlama standartlarında öne çıkan kurallar: açıklama satırları kullanılmalı, kod yazım deseni kullanılmalı (bütün projede tutarlı), anlamlı isimlendirmeler yapılmalı.
- Programlama dili ve ortamının seçimi (ekrandan, 00:15:00)
  - Gereksinimlere uygun dil(ler) teknik fizibilitede seçilip ön tasarım aşamasında kesinleştirilir.
  - Dil seçiminde dikkat edilecek faktörler: genel uygulama alanı, algoritma ve veri yapılarının karmaşıklığı, yazılımın kullanılacağı ortam, uygulama koşulları, personelin bilgi düzeyi, yapılacak yatırım miktarı, müşteri koşulları.
- Yazılım kalitesi (ekrandan, 00:25:00)
  - Kalite: işlevsel gereksinimlere, geliştirme standartlarına ve beklenen tüm özelliklere tamamen uygun yazılım.
  - Kalite büyük ölçüde işlevsel olmayan gereksinimlerle ilgilidir; işlevsel olmayan gereksinimler tasarımı da değiştirir (örneğin çok sayıda eş zamanlı video yayını için dağıtık/paralel bir tasarım gerekir).
  - Kalite faktörleri: doğruluk, güvenilirlik, verimlilik, güvenlik, kullanışlılık, hata bulma kolaylığı, esneklik, sınama kolaylığı, taşınabilirlik, tekrar kullanılabilirlik, bağlanabilirlik.
- Yazılımda kalitenin sağlanması (ekrandan, 00:30:00)
  - Planlama aşamasında kalite kontrolü yöntem ve araçları belirlenmeli; geliştirme sürecinde durak noktalarında (gözden geçirme kilometre taşları) yapılanlar gözden geçirilmeli; kaynak program sınanmalı; gerçekleştirilen projenin gereksinimleri karşılaması gözden geçirilmeli.
  - Bunlar plan dahilinde yapılır: yazılım inceleme planı, kaynak programı sınama planı, kabul muayene planı.
- Test türleri ve test adımları (ekrandan, 00:40:00)
  - Test türleri: fonksiyonel (işlev) testler, performans testleri, dayanıklılık (stres) testleri, yapısal testler.
  - Test adımları: ünite (birim) testi, bütünleme testi, onaylama (kabul) testi, sistem testi. Spiral (salyangoz) şemada her test bir geliştirme katmanını sınar.
- Yeni sisteme geçiş (ekrandan, 00:45:00)
  - Geçiş adımları: ön tasarımda belirlenen donanımın kurulumu, ağ yapısının oluşturulması, kayıtların yeni sisteme aktarılması, eğitim (sistemle ilgilenecekler, uç kullanıcılar, üst yönetim), devreye alma.
  - Beş geçiş yöntemi: doğrudan, paralel, dereceli, prototip ve dağıtılmış geçiş (ekrandan, 00:50:00).
- Bakım (ekrandan, 01:05:00)
  - Yazılım yaşayan bir süreçtir, evrimleşir. Kullanıma geçişten sonra yazılımdaki değişikliklere bakım denir.
  - İhtiyaç değişimi: iyileştirici bakım. Altyapı değişimi: uyarlayıcı bakım. Testlerde fark edilmeyen hatalar: düzeltici bakım.
- Örnek vaka çalışması: spor salonu sistemi (ekrandan, 01:10:00)
  - Problem tanımı, veri toplama (anket örneği), BRD, bağlam diyagramı, 1. ve 2. seviye veri akış diyagramları, veri sözlüğü, varlık ilişki diyagramı, use case diyagramı ve senaryo dokümanı, kavramsal sınıf diyagramı, yapı diyagramı, tasarım sınıf diyagramı ve ardışıl diyagram üzerinden analiz ve tasarımın uçtan uca kısa bir gösterimi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Tasarım olmadan büyük sistem kodlanmaz
  - Küçük ödevlerde doğrudan kodlamaya başlanabilir; ancak büyük ölçekli bir bilgi sisteminde iş bölümü ve bütünleştirme formal bir çözüm önerisi olmadan yapılamaz.
- Açıklama satırları ve tutarlı desen
  - Bir satır kod için bazen on satır açıklama yazılabilir. Standart bir desene göre yazılan açıklamalardan API dokümantasyonu otomatik üretilebilir; böylece ayrı bir dokümantasyon yazma ve bakımını yapma yükü ortadan kalkar.
  - Değişken adlarının dili (Türkçe/İngilizce) ve yazım biçimi (örneğin camel case) ne olursa olsun bütün projede tutarlı olmalıdır.
  - A, B, C, X, Y, Z gibi anlamsız adlar bir süre sonra kodu okunamaz hale getirir.
- "Ürünü doğru yaptım mı" ile "doğru ürünü yaptım mı" farkı
  - Birim ve bütünleme testleri ürünün doğru çalıştığını gösterir; onaylama (kabul) testi ise gereksinimleri karşılayan doğru ürünün yapılıp yapılmadığını gösterir.
- Kabul testinde çıkan analiz hatası pahalıdır
  - Problem uzayında (analizde) değişiklik gerektiren bir hata analiz, tasarım, kodlama ve bütün testlerin yeniden yapılmasını gerektirir; maliyeti her zaman daha yüksektir.
- Düzeltici bakımın maliyeti geliştiriciye aittir
  - İyileştirici ve uyarlayıcı bakım, değişiklik isteği iş bittikten sonra geldiği için müşteriye ücretlendirilebilir. Düzeltici bakım ise geliştiricinin kendi hatasıdır, ücretlendirilemez; bu yüzden geliştirici açısından tehlikelidir.
- Ardışıl diyagram algoritma değildir
  - Ardışıl diyagramın amacı sorumluluğun nesnelerin birlikte çalışmasıyla nasıl yerine getirildiğini göstermektir, algoritmayı göstermek değildir.
  - Her sorumluluk için ayrı bir ardışıl diyagram çizilmelidir; slaytta yer darlığı yüzünden üç sorumluluk tek diyagramda gösterilmiştir.

## Kısa Tekrar Notları

- Kodlama, tasarım (diyagram, algoritma, sözde kod) bittikten sonra başlar.
- Kod: spesifikasyona uygun, okunabilir, düzenlenebilir, test edilebilir, değiştirilebilir olmalı.
- Kodlama standartları: açıklama satırı, tutarlı yazım deseni, anlamlı isimlendirme.
- Dil seçimi faktörleri (7): uygulama alanı, algoritma/veri yapısı karmaşıklığı, kullanım ortamı, uygulama koşulları, personel bilgisi, yatırım miktarı, müşteri koşulları.
- Kalite = işlevsel gereksinimlere + geliştirme standartlarına + beklenen tüm özelliklere tam uygunluk.
- 11 kalite faktörü: doğruluk, güvenilirlik, verimlilik, güvenlik, kullanışlılık, hata bulma kolaylığı, esneklik, sınama kolaylığı, taşınabilirlik, tekrar kullanılabilirlik, bağlanabilirlik.
- Kalite planları: yazılım inceleme planı, kaynak programı sınama planı, kabul muayene planı.
- Test türleri: fonksiyonel, performans, dayanıklılık (stres), yapısal.
- Test adımları ve sınadıkları katman: ünite testi → kodlama; bütünleme testi → tasarım; onaylama testi → sistem gereksinimleri; sistem testi → sistem geliştirme sürecinin tamamı.
- Bütünleme testi genellikle artımlı yapılır; hepsini bir kerede birleştirip test etmek zordur.
- Geçiş adımları: donanım kurulumu, ağ, veri aktarımı (data migration), eğitim, devreye alma.
- Geçiş yöntemleri: doğrudan (riskli, çift iş yok), paralel (güvenli, çift iş), dereceli (modül modül, iki sistemin birlikte çalışması gerekir), prototip (eski sistem sürerken prototip olgunlaştırılır, sonra doğrudan geçiş), dağıtılmış (departman departman doğrudan geçiş).
- Bakım: iyileştirici (ihtiyaç değişti), uyarlayıcı (altyapı değişti), düzeltici (gizli hata).

## Detaylı Açıklamalar

- Kodlama ve dil seçimi
  - Programlama dili ve geliştirme ortamı teknik fizibilitede karşılaştırılıp seçilir, ön tasarımda kesinleşir (gerekirse alım ve kurulum yapılır). Seçimde dilin hangi alana uygun olduğu (web, matematiksel hesap, veri depolama ve sorgulama, işlem tabanlı uygulamalar), gereken veri yapılarının ve kütüphanelerin dilde hazır bulunup bulunmadığı önemlidir.
  - Kullanım ortamı belirleyicidir: COBOL gibi işlem ve kayıt tabanlı uygulamalar için tasarlanmış bir dil bankacılıkta hâlâ etkilidir ama mobil uygulama için uygun değildir. Sanal makine üzerinde çalışan, ara kod üreten diller (Java, .NET) taşınabilirlik nedeniyle yaygınlaşmıştır. iOS ve Android için hibrit ortamlar (React Native, Flutter) vardır ama cihaz sensörlerine derin erişim gerekiyorsa yerel (native) bir dil (örneğin Kotlin) gerekebilir.
  - Ekibin bilmediği bir dil, eğitim ve öğrenme süreci gerektirir ve iyi bilinen bir dil kadar etkin kullanılamaz. Lisans bedelleri ekonomik fizibiliteyi sarsabilir. Müşteri belli bir teknolojiyi (örneğin sunucu tarafında yalnız PHP) şart koşarsa diğer kriterler geri planda kalır; en uygun seçim her zaman teknik olarak en iyi seçim değildir.
- Kalite faktörleri
  - Doğruluk: doğru girdiden doğru çıktı üretmek, hatasız çalışmak ya da hatalı işlemleri kontrol edip engellemek.
  - Güvenilirlik: sistemin hangi stres altında hizmet vermeye devam edebildiği (örneğin aynı anda kaç öğrencinin ders seçebildiği).
  - Verimlilik: bellek, işlemci ve diğer kaynakları ölçülü kullanmak.
  - Güvenlik: yetkisiz işlemleri ve yasal olmayan erişimleri engellemek.
  - Kullanışlılık: kullanıcının girdisini hızlı ve etkin biçimde verip hizmeti alabilmesi.
  - Hata bulma kolaylığı, esneklik (değişen koşullara uyum), sınama kolaylığı (test otomasyonuna, regresyon testlerine uygunluk), taşınabilirlik (farklı ortamlarda çalışma), tekrar kullanılabilirlik (bir sınıfı, API'yi ya da adaptör grubunu başka uygulamada kullanabilme), bağlanabilirlik (dış sistemlerin az koşulla bağlanabilmesi) teknik personel açısından da önemlidir.
- Test türleri ve adımları
  - Fonksiyonel test girdi-işlem-çıktı döngüsünün doğruluğunu ve uç değerleri (örneğin negatif sayının karekökü) sınar. Performans testi tepki süresi, bellek kullanımı, iletişim hızı gibi darboğazları bulur. Dayanıklılık (stres) testi aşırı yük ya da bant genişliği düşüşü gibi durumlarda sistemin davranışını sınar. Yapısal test, parçaların ve modüllerin mantıksal çalışma yollarının ve senaryolarının doğru işleyip işlemediğini sınar.
  - Birim testi her kod için mutlaka yapılır. Bütünleme testi tasarımı sınar; hoca bunu motor parçalarının önce tek tek, sonra motor monte edilip ilk çalıştırıldığında birlikte test edilmesine benzetir. Onaylama testi (kullanıcı kabul testi, UAT) use case'ler ya da BRD'deki süreçler gibi gereksinimlerin karşılanıp karşılanmadığını müşteri gözüyle sınar. Sistem testi (güvenlik, dayanıklılık, performans, darboğaz analizi) geri kalan kalite kriterlerini bütün sistem üzerinde sınar.
  - Testlerde bulunan hatalar kod hatasıysa kod, tasarım hatasıysa tasarım ve gerçekleştirme güncellenip yeniden test edilir; süreç kabul görene kadar yinelemeli devam eder.
- Geçiş yöntemleri
  - Doğrudan geçişte belli bir anda eski sistem kapatılıp yeni sisteme geçilir (örneğin bir akşam mesai bitiminde eski sistemin fişi çekilir, ertesi sabah yeni sistemle çalışılır). İş iki kez yapılmaz ama yeni sistemde gözden kaçmış bir hata varsa geri dönülecek sistem yoktur.
  - Paralel geçişte $t_0$ ile $t_1$ arasında iki sistem eş zamanlı kullanılır; bu aralık bir tampon (yedek) bölgedir. Yeni sistemde sorun çıkarsa iş aksamaz, gerekirse $t_1$ ötelenir. Bedeli her işin (örneğin sipariş girişinin) iki sisteme de girilmesidir; genellikle eski sistem gerçek hizmet veren sistem olarak tutulur.
  - Dereceli geçişte yeni sistemin modülleri en basit, en risksiz ve en az bağlantılı olandan başlayarak adım adım devreye alınır, eski sistemin karşılık gelen kısımları kapatılır; $t_1$ anında eski sistem tamamen kapanır. İş iki kez yapılmaz ama iki sistemin birbiriyle uyumlu çalışması (ortak veri tabanı ya da birbirinin verisine erişim) gerekir; bu ek geliştirme isteyebilir.
  - Prototip geçişte eski sistemle gerçek iş sürerken yeni sistemin prototipi eş zamanlı kullanılarak olgunlaştırılır; prototip yeterince olgunlaşınca eski sistem bir anda kapatılır. Paralel ve doğrudan geçişin birleşimi gibidir.
  - Dağıtılmış geçişte iş birimleri (insan kaynakları, pazarlama, satış, depo, üretim, muhasebe gibi) teker teker yeni sisteme alınır; her departman için ayrı bir doğrudan geçiş gibidir. Bir süre iki sistemin birlikte çalışabilmesi gerekir.
- Bakım
  - İyileştirici bakım değişen ihtiyaçlara uyumdur: örneğin harf notu sisteminin bir yönetmelik değişikliğiyle başka bir ölçeğe geçmesi ya da yeni bir güvenlik düzenlemesinin şifrelerin belli bir algoritma ve anahtar uzunluğuyla saklanmasını şart koşması.
  - Uyarlayıcı bakım altyapı değişimine uyumdur: örneğin bir veri merkezindeki kümeden bulut hizmetlerine taşınma ya da yatay ölçeklendirme. Dikey ölçeklendirme nispeten kolaydır; yatay ölçeklendirme için tasarımın buna uygun olması, eş zamanlama ve orkestrasyon sorunlarının çözülmesi gerekir.
  - Düzeltici bakım testlerde fark edilmemiş hataların giderilmesidir.
  - Bir bilgi sistemi ihtiyaçları ya da artan işlevsel olmayan gereksinimleri karşılayamaz hale gelince yeni bir sistem tasarlanır ve fizibiliteden bakıma kadar aynı döngü yeniden başlar.
- Örnek vaka: spor salonu sistemi
  - Problem tanımı (ekrandan, 01:15:00): artan müşteri sayısı ve genişleyen ders içerikleri nedeniyle yeni bir yönetim sistemi gerekmektedir. Üyeler çevrim içi üye olabilmeli, derslere ait sınıfların takvim ve eğitmen bilgilerini görüntüleyebilmeli, sınıflara kayıt olabilmelidir. Her ay sabit üyelik ücreti alınır; pilates, dans gibi ders sınıfları ekstra ücretlidir; özel ders ücreti grup ücretinden farklı hesaplanır.
  - Veri toplama için anket örneği (ekrandan, 01:20:00): kapalı uçlu (evet/hayır, modül seçimi) ve açık uçlu sorular birlikte kullanılır.
  - İşlevsel yaklaşımda BRD, bağlam diyagramı, 1. ve 2. seviye veri akış diyagramları, süreç formları, veri sözlüğü ve varlık ilişki diyagramı; nesneye yönelik yaklaşımda use case diyagramı, senaryo dokümanları ve kavramsal sınıf diyagramı hazırlanır. Tasarımda işlevsel yolda yapı diyagramı (ekrandan, 01:30:00), nesneye yönelik yolda tasarım sınıf diyagramı ve ardışıl diyagramlar çizilir.
  - Ardışıl diyagramdaki borç hesaplama örneğinde üye borcunu spor salonundan öğrenir; spor salonu sınıflardan ödenecek tutarları, sınıflar da derslerden saat ücretini ve katılım süresini alır; tutar saat ücreti çarpı katılım süresidir.
  <!-- BELİRSİZ: BRD tablosu, bağlam diyagramı, DFD'ler, veri sözlüğü, use case, senaryo dokümanı, sınıf ve ardışıl diyagram slaytları karelerde yoktur; ayrıntıları altyazıdaki anlatımdan alınmıştır. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
