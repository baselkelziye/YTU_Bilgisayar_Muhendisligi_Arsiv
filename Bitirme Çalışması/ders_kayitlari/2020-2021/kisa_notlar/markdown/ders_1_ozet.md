# Ders 1 Çalışma Özeti

## Genel Konular

- İncelenen bitirme projesi: akademik kadro, yayın ve kırık link tarayıcısı
  - Bir öğrencinin bitirme projesi, danışmanla yapılan birebir görüşmede ekran paylaşılarak gösterildi. Proje, bir bölümün web sitesindeki akademik kadro listesini otomatik olarak okuyan, her öğretim üyesinin yayınlarını üniversitenin akademik veri sisteminden toplayan ve sitedeki kırık bağlantıları bulan bir masaüstü uygulamasıdır.
  - Uygulama Java ile yazılmış, arayüzü Swing bileşenleriyle bir form tasarım aracı (JFormDesigner) kullanılarak hazırlanmıştır. Proje IntelliJ IDEA'da Maven projesi olarak (pom.xml) geliştirilmiştir (ekrandan, 00:05:00 ve 00:10:00).
  - Web sayfalarının taranması Selenium ile yapılır. Konsolda ChromeDriver'ın başlatıldığı ve Selenium oturumunun açıldığı görülür (ekrandan, 00:05:00).
- Uygulamanın arayüzü ve işleyişi
  - Pencerede üç sekme vardır: "Akademik Kadro", "Akademik Çalışmalar" ve "Kırık Link" (ekrandan, 00:05:00).
  - Akademik Kadro sekmesi: "Taramayı Başlat" düğmesi, bir ilerleme çubuğu ve "İşleminiz devam ediyor..." mesajı bulunur. Kadro listesi elle girilmez, doğrudan bölüm sayfasından alınır.
  - Akademik Çalışmalar sekmesi: bir öğretim üyesi ya da tüm kadro seçilir, yıl girilir ve arama kriteri seçilir (ör. "SCI Index"). "Taramayı Başlat" ve "İndir" düğmeleri vardır (ekrandan, 00:10:00). Yayınlar, kadro sayfasından alınan bağlantılarla her öğretim üyesinin yayın sayfasından toplanır. Konsolda bulunan çalışma sayısı "TOPLAM SAYI" olarak yazdırılır.
  - Kodda sonuçlar `saveToExcel(...)` ile Excel dosyasına yazılır; SCI raporu ve "Kitap & Kitap Bölümü" raporu için ayrı dosya adları vardır. Tarama bitince düğmeler yeniden etkinleştirilir ve `tearDownDriver()` ile tarayıcı sürücüsü kapatılır (ekrandan, 00:05:00).
  - Kırık Link sekmesi: bir URL alanı ve arama düğmesi bulunur (ekrandan, 00:10:00). Tarama sonunda kırık bağlantılar bir metin alanında listelenir.
- Karşılaşılan sorun: duyurular sayfasında sonsuz döngü
  - Kırık link taraması duyurular bölümünde durmadan devam etti. Duyurular normalde 6 sayfadır, ama "sonraki" düğmesine basıldıkça boş sayfalar gelmeye devam ediyor ve tarayıcı sayfa numarasını artırmayı sürdürüyor. Normalde 10 dakika kadar süren tarama 15 dakikayı geçmiş ve 154. sayfaya kadar gitmişti.
  - Tarama yeniden başlatıldığında bu kez tamamlandı ve hatalı bağlantılar listelendi.
- Danışmanın önerileri
  - İlan ve duyurularda tarih geçtikten sonra eski sayfaları incelemeye gerek yoktur. Bu yüzden yalnız en son belirli sayıda ilana bakılmalı ve bu sayı programda ayarlanabilir bir değer olmalıdır. <!-- BELİRSİZ: altyazıda sayfa başına ilan sayısı "18 tane" ve sınır "18 ya da 80" diye geçiyor; kesin değer anlaşılamadı -->
  - Kırık link listesinin yanına bir "dosyaya kaydet" düğmesi konmalı; tıklanınca metin alanının içeriği bir dosyaya yazılmalıdır.
  - Yeni özellik eklerken çalışan sürüm ayrıca yedeklenmeli, yeni iş başka bir kopya üzerinde yapılmalıdır.
  - Tez kitabındaki performans analizi bölümünde yalnız algoritmanın karmaşıklığından bahsedilmiş. Buna çalışma zamanı ölçümü eklenmelidir.
- Çalışma zamanı ölçümü (Java)
  - Her öğretim üyesi için ayrı ayrı yayın sayısı ve o öğretim üyesinin sayfasının işlenip yayınlarının getirilmesinin kaç milisaniye sürdüğü ölçülmeli, bir tabloya yazılıp grafiğe dökülmelidir. Böylece yayın sayısı farklı öğretim üyelerinde sürenin nasıl değiştiği görülür.
  - Süre `System.currentTimeMillis()` ile ölçülür: işten önce ve sonra çağrılır, fark işin süresini milisaniye olarak verir.
  - Her ölçüm 3 kez yapılıp aritmetik ortalaması alınmalıdır; çünkü bilgisayarda aynı anda çalışan başka işler (ör. antivirüs programı) anlık dalgalanmalar yaratır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Performans analizi deneysel ölçümle desteklenmeli
  - Karmaşıklık analizi tek başına yeterli değildir; çalışma süresi ve başarı bir şekilde ölçülmelidir. En temel çalışma zamanı analizi, her girdi (öğretim üyesi) için yayın sayısı ve süreyi içeren bir tablo ile bunun grafiğidir.
- Ölçümleri tekrarla ve ortalamasını al
  - Tek bir ölçüm, işletim sisteminin ya da başka programların anlık etkisiyle yanıltıcı olabilir. Üç ölçümün ortalaması bu dalgalanmayı azaltır. Bu tekrar elle ya da program içinde yapılabilir.
- Sınırsız tarama yerine ayarlanabilir sınır
  - Sayfalı içerikte (ilanlar, duyurular) "sonraki sayfa" boş olsa bile devam edebilen bir yapıda tarama sonsuz döngüye girebilir. Taranacak ilan sayısının bir ayar olarak tutulması hem süreyi kısaltır hem de bu riski ortadan kaldırır.
- Çalışan sürümü bozma
  - Yeni özellik eklemeden önce çalışan kodun kopyası ayrı bir yere kaydedilmelidir.

## Kısa Tekrar Notları

- Proje: Java + Swing (JFormDesigner) + Selenium/ChromeDriver ile akademik kadro, yayın ve kırık link tarayıcısı; Maven projesi.
- Sekmeler: Akademik Kadro, Akademik Çalışmalar (kadro, yıl, arama kriteri; tarama ve Excel'e indirme), Kırık Link (URL girilir, kırık bağlantılar listelenir).
- Kadro listesi bölüm sayfasından otomatik alınır; yayınlar her öğretim üyesinin yayın sayfasından toplanır.
- Sorun: duyurularda "sonraki" boş sayfalara gitmeye devam ettiği için tarama durmadı.
- Çözüm önerisi: en son N ilana bak, N bir ayar olsun.
- Raporlama önerisi: kırık link listesini dosyaya kaydeden düğme.
- Performans: öğretim üyesi başına yayın sayısı ve süre (ms) tablosu + grafik; her ölçüm 3 kez, ortalama alınır.
- `long begin = System.currentTimeMillis(); ... long end = System.currentTimeMillis(); long duration = end - begin;`
- `currentTimeMillis()` statik bir metottur; 1 Ocak 1970 00:00'dan bu yana geçen milisaniyeyi döndürür.

## Detaylı Açıklamalar

- **Uygulamanın yapısı.** Uygulama, bölümün web sitesini bir tarayıcıyı otomatik süren Selenium ile gezer. Önce kadro sayfasındaki öğretim üyesi listesi ve her birinin profil bağlantısı okunur. Akademik Çalışmalar sekmesinde kullanıcı tek bir öğretim üyesi ya da tüm kadroyu, bir yılı ve bir arama kriterini (ör. SCI indeksli yayınlar) seçer. Program, kadro sayfasından aldığı bağlantılarla her öğretim üyesinin yayın sayfasına gider, kritere uyan yayınları sayar ve sonucu Excel dosyasına aktarır. Kodda biri SCI yayınları, diğeri kitap ve kitap bölümleri için olmak üzere iki ayrı rapor dosyası üretildiği görülür (ekrandan, 00:05:00). Tarama sürerken düğmeler devre dışı bırakılır, bitince yeniden etkinleştirilir ve tarayıcı sürücüsü kapatılır.
- **Kırık link taraması ve sonsuz döngü.** Kırık Link sekmesinde sitenin adresi verilir ve program sayfalardaki bağlantıları tek tek dener; açılmayanlar bir listede gösterilir. Duyurular bölümünde sayfalama, son sayfadan sonra da "sonraki" bağlantısının boş sayfalar döndürmesine yol açıyordu. Program bu yüzden durma koşuluna hiç ulaşmadı. Danışman, ilanların zamanla geçerliliğini yitirdiğini, bu yüzden eski sayfaların incelenmesine gerek olmadığını söyledi ve yalnız en son belirli sayıda ilana bakılmasını, bu sayının bir ayar olarak tutulmasını önerdi.
- **Raporlama.** Kırık bağlantılar şu anda arayüzdeki bir metin alanında listeleniyor. Danışman, listelemenin yanına bir "dosyaya kaydet" düğmesi eklenmesini, tıklanınca metin alanının içeriğinin bir metin dosyasına yazılmasını önerdi; bu, ayrı bir rapor dosyası formatı tasarlamaktan daha kolaydır.
- **Performans analizi.** Tez kitabının performans analizi bölümünde algoritmanın karmaşıklığı anlatılmıştı. Danışman buna deneysel ölçüm eklenmesini istedi: program her öğretim üyesi için ayrı çalıştırılır, o kişinin yayın sayısı ve sayfasının işlenip yayınların getirilmesinin süresi milisaniye cinsinden kaydedilir. Bu değerler bir tabloya yazılıp grafiğe dökülürse, yayın sayısı arttıkça sürenin nasıl değiştiği görülür. Her ölçüm 3 kez yapılıp ortalaması alınır, böylece arka planda çalışan programların yarattığı dalgalanma azalır.
- **Java'da süre ölçme.** Danışman kendi ekranını paylaşarak bir geliştirme ortamında küçük bir örnek gösterdi. `System.currentTimeMillis()` statik bir metottur ve 1 Ocak 1970 saat 00:00'dan bu yana geçen milisaniye sayısını `long` olarak döndürür. Ölçülecek işten önce bu değer `begin` değişkenine, iş bittikten sonra `end` değişkenine alınır; `duration = end - begin` işin kaç milisaniye sürdüğünü verir ve ekrana yazdırılır. Örnekte ölçülen iş çok kısa olduğu için sonuç 0 ile 1 milisaniye arasında çıktı. <!-- BELİRSİZ: danışmanın ekranda yazdığı kod karelerde görünmüyor; kod altyazıdaki anlatımdan kuruldu -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
