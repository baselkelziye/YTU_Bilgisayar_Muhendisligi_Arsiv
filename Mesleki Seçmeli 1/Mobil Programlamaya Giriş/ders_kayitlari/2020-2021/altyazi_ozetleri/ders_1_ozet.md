# Ders 1 Çalışma Özeti

## Genel Konular

- Mobil teknolojilere giriş ve mobil cihazların tarihsel gelişimi
  - Kablosuz iletişimin mobilitenin temelini oluşturduğu; ilk olarak ev içi kablosuz telefonlardan başlayan, sonra telsiz telefonlar, hücresel ağlar (GSM) ve nihayetinde 5G'ye uzanan süreç.
  - Her bir neslin (1G, 2G, 3G, 4G, 4.5G, 5G) getirdiği yenilikler; analog haberleşmeden sayısal paket iletimine, SMS'in hayatımıza girişine, GPRS, UMTS, LTE gibi teknolojilere geçiş süreci.

- Mobil bilgi işlem (mobile computing) kavramı ve temel yapı taşları
  - Mobil bilgi işlem üç ana başlık altında incelenir: mobil iletişim (mobile communication), mobil donanım (mobile hardware), mobil yazılım (mobile software).
  - Mobil iletişim örnekleri: NFC (Near Field Communication), Bluetooth, Bluetooth Low Energy, Wi-Fi, hücresel ağlar (cellular networks) ve 5G.
  - Mobil donanımda işlemci ailesi olarak ARM mimarisi; ARM'ın RISC (Reduced Instruction Set Computing) kullandığı, Intel işlemcilerin ise CISC (Complex Instruction Set Computing) kullandığı; RISC'in daha az enerji tüketmesinin mobil cihazlarda tercih edilme sebebi olduğu.

- Mobil cihazlarda sensör ve işlemci mimarisi optimizasyonu
  - Apple cihazlarında ana işlemciye ek olarak sensör verilerini okumak için kullanılan yardımcı işlemci (co-processor) yapısı; saniyede 100-200 defa sensör okuma ihtiyacında ana işlemciyi uyutmak için düşük enerjili bir işlemci ayrılması.
  - Android işletim sisteminin Doze (uyku) mekanizması: telefon hareketsiz kaldığında arka plan işlemlerinin sıklığını azaltarak pil tüketimini minimize etmesi.

- Mobil uygulama geliştirmenin temel felsefesi
  - Bu dersin amacının "mobil programlama = Java = Android" denkleminden öteye geçmek olduğu; farklı işletim sistemleri, farklı programlama dilleri, farklı geliştirme yaklaşımlarının olduğu bir dünyada öğrencilere kavramsal bir çerçeve sunmak.
  - Web uygulaması, masaüstü uygulaması ve mobil uygulama geliştirme arasındaki farklar; pil kapasitesi, işlemci gücü, ekran boyutu gibi kısıtların mobil geliştirmeyi şekillendirmesi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Pil kapasitesinin mobil dünyadaki her şeyin belirleyicisi olduğu
  - "Bütün hikaye bu pil kapasitesini iyi kullanmakla alakalı"; eğer telefon pilleri bir ay dayansaydı, bu kadar optimizasyonla uğraşmamıza gerek kalmayacağı.
  - Bu yüzden Doze, co-processor, RISC mimarisi gibi tüm teknolojilerin asıl sebebinin pil ömrünü uzatmak olduğu.

- Mobil uygulama geliştirmenin "hemen kod yazalım"dan ibaret olmadığı
  - Dersin kurgusunun önce mobil dünyanın temellerini anlatmak, sonra kodlamaya geçmek olduğu; bu nedenle ilk haftalarda doğrudan Android kodlaması yapılmayacağı.
  - "Keşke daha önce başlasaydık" eleştirisine karşı hoca, bu beklentilerin ileri seviye bir "İleri Mobil Programlama" dersinde karşılanabileceğini belirtti.

- 5G'nin kritik önem taşıdığı senaryolar
  - Otonom araçlar için 5G'nin 1 ms gecikme süresi sunmasının hayati önem taşıdığı; yüksek gecikmenin kazaya yol açabileceği.
  - 5G'nin araçtan araca iletişim (V2V) için olmazsa olmaz bir altyapı olduğu.

- Geliştirilen uygulamanın fonksiyonel olduğu kadar görsel açıdan da kaliteli olması gerektiği
  - "Geliştirdiğiniz uygulamalar sadece fonksiyonel olmamalı, görselliği de belli oranda düzgün olmalı"; çünkü kullanıcı karmaşık bir uygulamayı görsel olarak beğenmezse kullanmıyor.
  - Ödev ve dönem projesi değerlendirmesinde görsellikten de puan alınacağı.

## Kısa Tekrar Notları

- Mobil teknoloji nesilleri: 1G analog, 2G dijital + SMS, 3G/UMTS, 4G/LTE, 4.5G, 5G (1 ms gecikme).
- Mobil bilgi işlem üç temel yapı taşı: iletişim, donanım, yazılım.
- ARM işlemciler RISC (Reduced Instruction Set), düşük enerji tüketir; mobil cihazlarda tercih edilir.
- Co-processor: sensör verilerini okumak için ana işlemciye yardımcı düşük güçlü işlemci.
- Android Doze: telefon hareketsizken arka plan işlemlerini azaltan enerji tasarruf mekanizması.
- Pil kapasitesi mobil dünyadaki en büyük kısıt; tüm optimizasyonlar buna yönelik.

## Detaylı Açıklamalar

Dersin ilk yarısı büyük ölçüde tanışma, dersin tanıtımı, değerlendirme ölçütleri (1 sınav %20, 2-3 ödev %20, dönem projesi %20, final %40), ders içeriği haftalık planı (ilk hafta mobil teknoloji kavramı, 2. hafta mobil cihazlar ve diller, Android işletim sistemi yapı taşları, MVC/MVVM, layout ve widget'lar, aktiviteler ve intent'ler, ListView/RecyclerView, sensörler, broadcast receiver'lar, arka plan işleri, lokasyon servisleri, haritalar, Google Play Store'a yükleme) gibi örgütsel içerikten oluşmaktadır. Öğrencilerden gelen sorular Zoom kamerası açma, derslere katılım, kayıtlara erişim, Classroom kullanımı gibi konularda olmuştur. Hoca, AVESIS, YOKSIS, ARBIS, USIS, GESIS gibi platformların pandemi sürecinde yarattığı yükten de söz etmiştir. Bologna bilgi paketinde dersin 3 kredi, 5 AKTS olduğu belirtilmiştir.

Dersin akademik içeriğe geçtiği ikinci bölümde mobil teknoloji kavramı ele alınmıştır. Mobilitenin aslında "mobility" kelimesinden geldiği ve kablosuz iletişim sayesinde mümkün olduğu vurgulanmıştır. Hücresel ağların gelişimi sırasıyla ele alınmış; 1G'nin analog radyo sinyalleriyle haberleşme sağladığı, cep telefonunun dijital sinyali analog sinyale dönüştürdüğü, 2G ile birlikte dijital haberleşme ve SMS'in hayatımıza girdiği, GPRS'in paket iletimini sağladığı, ardından 3G/UMTS, LTE, 4.5G ve son olarak 5G'nin geldiği anlatılmıştır. 5G'nin 2021 yılı itibarıyla belirli yerlerde kullanılmaya başlandığı ancak henüz yaygınlık kazanmadığı belirtilmiştir. 5G'nin en önemli özelliği olan 1 ms gecikme süresinin otonom araçlar için neden kritik olduğu açıklanmıştır: otonom bir aracın yüksek gecikmeyle alacağı karar ciddi bir kazaya yol açabilir. Bu nedenle araçtan araca iletişim (V2V) 5G altyapısına bağımlıdır. Mobil iletişim konusunda paket kaybı sorunlarına da değinilmiş; hareket halindeyken baz istasyonu değiştirmenin eskiden kesintilere yol açtığı, ancak günümüzde bu kesintilerin minimize edildiği belirtilmiştir. Yine de "kör noktalar"ın (blind spot) halen sorun olduğu, hücresel ağların birbiriyle kesişmediği bölgelerde bağlantı kesintileri yaşandığı vurgulanmıştır.

Daha sonra mobil bilgi işlem (mobile computing) kavramının tanımı yapılmıştır. Üç temel başlık altında incelenmiştir: mobil iletişim, mobil donanım ve mobil yazılım. Mobil iletişim örnekleri olarak NFC (yakın alan iletişimi), Bluetooth, Bluetooth Low Energy, Wi-Fi ve hücresel ağlar verilmiştir. 5G üzerinde yoğun araştırma yapıldığı, mobil iletişimin araştırma alanı olarak hâlâ çok geniş olduğu belirtilmiştir.

Mobil donanım konusunda işlemci ailesi olarak ARM mimarisi ele alınmıştır. ARM işlemcilerin RISC (Reduced Instruction Set Computing) kullandığı, Intel işlemcilerin ise CISC (Complex Instruction Set Computing) kullandığı açıklanmıştır. RISC'in daha az ve basit komut setine sahip olduğu için daha az enerji harcadığı, bu yüzden mobil cihazlarda tercih edildiği vurgulanmıştır. Performans açısından CISC'in bazı karmaşık hesaplamalarda daha iyi olabildiği, ancak enerji verimliliğinin mobil dünyada çok daha önemli bir kriter olduğu belirtilmiştir. Bataryanın doğrudan bilgisayar mühendisliği alanı olmadığı, ancak mobil donanımda kritik bir unsur olduğu söylenmiştir. Akıllı telefon ve akıllı saatlerde boyut ve enerji tüketiminin minimuma indirilmesi gerektiği, bu yüzden üreticilerin çeşitli çözümler geliştirdiği anlatılmıştır.

Apple cihazlarının ana işlemciye ek olarak bir "co-processor" (yardımcı işlemci) kullandığı, bu yardımcı işlemcinin sensörlerden gelen verileri okumak için tasarlandığı açıklanmıştır. Saniyede 100-200 defa sensör okuma gereksinimi olduğunda ana işlemci sürekli uyanık kalmak zorunda kalmakta, bu da pil tüketimini artırmaktadır. Co-processor düşük enerjiyle bu işi üstlenir, ana işlemci sadece kritik görevler için uyanır. Yazılım tarafında ise Android'in Doze mekanizması benzer bir görevi yerine getirmektedir: telefon uzun süre hareketsiz kaldığında (ekran kapalı, cihaz sabit) arka plan sorgulama sıklığını azaltır. Örneğin WhatsApp mesajlarının sunucudan çekilme sıklığı normalde 1 saniyeyken, Doze devreye girdiğinde 30 saniye veya 1 dakikaya çıkabilir. Android 7 ile birlikte Doze daha da geliştirilmiş, makine öğrenmesi teknikleri kullanılarak cihazın gerçekten "hareketsiz" mi yoksa "yanında taşınıyor" mu olduğu daha akıllı tespit edilmeye başlanmıştır.

Son olarak mobil yazılım tarafına kısaca değinilmiş; uygulamaların (applications) mobil yazılım başlığı altında incelendiği, uygulama geliştirme tekniklerinin dersin ilerleyen haftalarında detaylı olarak anlatılacağı belirtilmiştir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
