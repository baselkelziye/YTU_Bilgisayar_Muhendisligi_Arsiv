# Ders 1 Genişletilmiş Notu: Bitirme Projesi Görüşmesi: Akademik Kadro, Yayın ve Kırık Link Tarayıcısı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Projenin Tanıtımı
- 2. Uygulamanın Arayüzü ve Kod Yapısı
- 3. Kırık Link Taramasında Sonsuz Döngü Sorunu
- 4. Kırık Linklerin Raporlanması
- 5. Performans Analizi: Karmaşıklıktan Ölçüme
- 6. Java'da Çalışma Süresi Ölçmek
- Örnek Sorular
- Dersin Toparlaması

## 1. Projenin Tanıtımı

Bu kayıt, bir öğrencinin bitirme projesini danışmanına gösterdiği yaklaşık 18 dakikalık birebir çevrim içi görüşmedir. Danışman görüşmenin başında projenin tez kitabını okuduğunu, kitabın genel olarak iyi göründüğünü ve yalnız performans analizi kısmında bir ekleme isteyeceğini söyledi. Ardından öğrenci ekranını paylaşarak uygulamayı çalıştırdı.

Proje, bir üniversite bölümünün web sitesi üzerinde çalışan bir otomasyon aracıdır. Üç işi vardır:

- Bölüm sayfasındaki akademik kadro listesini otomatik olarak okumak.
- Her öğretim üyesinin yayınlarını, kadro sayfasından alınan bağlantılarla üniversitenin akademik veri sistemindeki yayın sayfalarından toplamak ve belirli kriterlere göre raporlamak.
- Sitedeki kırık bağlantıları (açılmayan linkleri) bulmak.

Ekrandan görülen teknoloji yığını şöyledir (ekrandan, 00:05:00 ve 00:10:00):

- **Dil ve arayüz:** Java, Swing bileşenleri. Arayüz formları JFormDesigner eklentisiyle tasarlanmıştır (`Application.jfd` form dosyası ve bileşen ağacında `JTabbedPane`, `JScrollPane`, `GroupLayout` panelleri).
- **Geliştirme ortamı ve derleme:** IntelliJ IDEA, Maven (`pom.xml`).
- **Web otomasyonu:** Selenium WebDriver ve ChromeDriver. Konsolda ChromeDriver'ın başlatıldığı, Selenium'un `ProtocolHandshake createSession` ile oturum açtığı ve Chrome DevTools Protocol (CDP) sürümünün en yakın eşleşmeyle bulunduğu satırlar görülür.

> **Ek bilgi (derste anlatılmadı):** Selenium, bir web tarayıcısını program içinden sürmeye yarayan bir kütüphanedir; sayfa açma, düğmeye basma, metin okuma gibi işlemleri insan yerine yapar. ChromeDriver, Selenium komutlarını Chrome tarayıcısına ileten ayrı bir sürücü programıdır. Konsoldaki "CDP sürümü için tam eşleşme bulunamadı" uyarısı, büyük olasılıkla Selenium kütüphanesinin yüklü Chrome sürümünden biraz eski olduğunu gösterir ve genelde çalışmayı engellemez.

## 2. Uygulamanın Arayüzü ve Kod Yapısı

### 2.1 Sekmeler

Uygulama penceresinde üç sekme vardır (ekrandan, 00:05:00):

- **Akademik Kadro:** "Taramayı Başlat" düğmesi, bir ilerleme çubuğu ve tarama sürerken "İşleminiz devam ediyor..." mesajı. Öğrenci, kadro listesinin elle girilmediğini, doğrudan bölüm sayfasındaki kadro bölümünden alındığını söyledi. Tarama başlatıldığında liste istisnasız tüm kadro için çekilir.
- **Akademik Çalışmalar:** "Akademik Kadro" açılır listesi (tek bir öğretim üyesi ya da tüm kadro seçilebilir), "Yıl" alanı, "Arama Kriteri" açılır listesi (ör. "SCI Index"), "Taramayı Başlat" ve "İndir" düğmeleri (ekrandan, 00:10:00). Öğrenci iki arama kriteri olduğunu belirtti. Program, kadro sayfasından aldığı bağlantılarla her öğretim üyesinin yayın sayfasına gider. Konsolda taranan sayfanın adresi ve bulunan yayın sayısı "TOPLAM SAYI" olarak yazdırılır.
- **Kırık Link:** Bir "URL" alanı ve arama düğmesi bulunur (ekrandan, 00:10:00). Tarama sonucunda kırık bağlantılar bir metin alanında listelenir.

### 2.2 Koddan görülenler

Öğrencinin ekranında açık olan ana sınıfta tarama düğmesinin olay işleyicisi ve "İndir" düğmesinin işleyicisi görülür (ekrandan, 00:05:00). Tarama bitince arayüz bileşenleri yeniden etkinleştirilir ve tarayıcı sürücüsü kapatılır:

```java
academicPublicationTab.setEnabled(true);
publicationTabProgressPanel.setVisible(false);

setAllTabsEnabled(true);
publicationCrawlButton.setEnabled(true);
staffComboBox.setEnabled(true);
yearTextField.setEnabled(true);
staffCrawlButton.setEnabled(true);
publicationCriteriaComboBox.setEnabled(true);
tearDownDriver();
downloadPublicationButton.setEnabled(true);
```

"İndir" düğmesine basıldığında, bulunan proje (yayın) sayısına göre iki farklı Excel raporundan biri yazılır: SCI kriterinde "SCI Raporu" adlı dosya ve "SCI REPORT" sayfası, kitap kriterinde "Kitap & Kitap Bölümü Raporu" adlı dosya ve "BOOK REPORT" sayfası. Dosya adına ve sayfa başlığına yıl alanındaki değer eklenir. Hiç kayıt yoksa bir `JOptionPane` mesajı gösterilir (ekrandan, 00:05:00). Buradan arama kriterlerinin SCI indeksli yayınlar ile kitap ve kitap bölümleri olduğu anlaşılır.

Bu yapıda dikkat çeken tasarım kararı, uzun süren tarama sırasında kullanıcının başka bir düğmeye basıp ikinci bir tarama başlatmasını önlemek için bütün sekme ve düğmelerin devre dışı bırakılması, iş bitince geri açılmasıdır. Tarama işi arayüzü dondurmamak için arka planda yürütülür; kodda gecikme parametresi `1000` olan bir lambda görülür.

<!-- BELİRSİZ: arka plan işinin hangi Swing mekanizmasıyla (Timer, SwingWorker vb.) yürütüldüğü karede tam görünmüyor -->

## 3. Kırık Link Taramasında Sonsuz Döngü Sorunu

### 3.1 Sorunun tarifi

Öğrenci, görüşmeden hemen önce kırık link taramasını çalıştırdığını ve taramanın sitenin duyurular kısmında takıldığını anlattı. Program 154. sayfaya kadar gitmiş, hâlâ devam ediyordu. Normalde yaklaşık 10 dakika süren tarama 15 dakikayı geçmişti.

**Soru:** Duyurular fazla uzun mu sürdü, yoksa bir yerde takılıp ilerleyemedi mi?
**Cevap:** Duyurular normalde 6 sayfadır. Fakat son sayfadan sonra da "sonraki" düğmesine basıldığında site boş bir sayfa göstermeye devam ediyor. Program bu boş sayfaları da yeni sayfa sanıp sayfa numarasını artırmayı sürdürüyor, bu yüzden sonsuz döngüye giriyor.

Danışman bunun ilginç bir durum olduğunu belirtti. Öğrenci taramayı yeniden başlattığında bu kez tarama tamamlandı ve hatalı bağlantılar listelendi; öğrenci listelenenlerin hatalı linkler olduğu için kontrol edilemediğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Sayfalı içerik taranırken durma koşulu yalnız "sonraki bağlantısı var mı?" sorusuna bağlanırsa, sitenin boş sayfa döndürdüğü durumda döngü bitmez. Güvenli bir tarayıcıda genelde ek koşullar kullanılır: sayfada hiç öğe yoksa durmak, daha önce görülen içerik tekrar ederse durmak ya da en fazla sayfa veya öğe sayısını sınırlamak.

### 3.2 Danışmanın önerisi: ayarlanabilir sınır

Danışman, ilanların bir süre sonra tarihinin dolduğunu, tarihi dolmuş ilan sayfalarını ayrıntılı incelemeye gerek olmadığını söyledi. Bu yüzden önce sayfa başına kaç ilan olduğunu sordu; öğrenci bir sayfada 18 kadar ilan olduğunu söyledi. Danışman, ilanlar kısmında yalnız en son belirli sayıda ilana bakılmasını ve bu sayının sabit kodlanmak yerine bir ayar olarak bir yerde tutulmasını önerdi ("en son ilanlar kısmında şu kadar ilana bak" şeklinde).

<!-- BELİRSİZ: önerilen sınır altyazıda "18 şartlı ya da 80 tane" diye geçiyor; danışmanın 18 mi 80 mi dediği kesin anlaşılamadı -->

Bu öneri iki sorunu birden çözer: tarama süresi kısalır ve boş sayfalar yüzünden oluşan sonsuz döngü riski ortadan kalkar, çünkü taranacak öğe sayısı en baştan sınırlıdır.

## 4. Kırık Linklerin Raporlanması

Danışman, konsolda hatalı bağlantıların adreslerini gördüğünü, ama uygulamanın kullanıcıya bunu nasıl raporlayacağını sordu.

**Soru:** Bu uygulama bana nasıl bir rapor verecek? Kırık link sekmesinde bir liste mi olacak, yoksa konsola yazar gibi bir metin dosyası mı oluşturacak?
**Cevap:** Kırık Link sekmesinde kırık bağlantılar bir liste halinde gösteriliyor ve bunlar bir dosyaya da yazdırılabilir.

Danışmanın önerisi, listelemenin yanına bir "dosyaya kaydet" düğmesi eklemekti. Düğmeye tıklanınca metin alanının içeriği olduğu gibi bir dosyaya yazılır. Bu, ayrı bir rapor formatı tasarlamaktan daha kolay ve hızlı bir çözümdür.

> **Hocanın vurgusu:** Yeni bir özellik eklerken mevcut çalışan sürümü bozma. Çalışan hâlini ayrıca bir yere kaydet, yeni işi başka bir kopya üzerinde yap. Danışman bunun birçok öğrencinin başına gelen bir durum olduğunu belirtti; öğrenci de projenin üç ayrı yerde yedeği olduğunu söyledi.

## 5. Performans Analizi: Karmaşıklıktan Ölçüme

### 5.1 Eksik olan kısım

Danışman, tez kitabının performans analizi bölümünde yalnız işin karmaşıklığından bahsedildiğini söyledi. Bir yazılım projesinin performans analizinde çalışma zamanının ve başarının bir şekilde ölçülmesi de gerekir.

Ölçümün nasıl kurulacağını düşünmek için önce programın temelde ne yaptığını hatırlattı: program öğretim üyelerinin sayfalarına gidip yayınları okuyor. Kadro listesi bölüm sayfasından alınıyor, yayınlar her öğretim üyesinin yayın sayfasından toplanıyor.

### 5.2 Önerilen deney

Danışmanın önerdiği deney şöyledir:

- Program her öğretim üyesi için tek tek çalıştırılır.
- Her öğretim üyesi için iki değer kaydedilir: yayın sayısı ve o öğretim üyesinin sayfasının işlenip yayınlarının getirilmesinin kaç milisaniye sürdüğü.
- Bu değerler bir tabloya yazılır ve bir grafiğe dökülür.

Neden tek tek? Çünkü her öğretim üyesinin yayın sayısı farklıdır. Yayın sayısı az olan bir öğretim üyesinin sayfasının işlenmesiyle yayın sayısı çok olanınki arasında milisaniye cinsinden ne kadar fark olduğu bu şekilde görülür. Danışmanın ifadesiyle bu, "en temel çalışma zamanı performansını inceleme" yoludur ve tez kitabının performans analizi bölümüne eklenmelidir.

### 5.3 Ölçümü tekrarlamak

> **Hocanın vurgusu:** Her öğretim üyesinin süresini yalnız bir kez ölçme. Üç kez ölç, toplamı üçe böl, yani aritmetik ortalamasını al. Ölçüm sırasında bilgisayarda başka şeyler de çalışır; antivirüs programı devreye girip çıkar, anlık başka olaylar olur. Üç ölçümün ortalaması bu dalgalanmaları düzeltir.

Bu tekrar elle yapılıp sonuçlar bir kenara yazılabilir ya da program içinde otomatik yapılabilir. Ortalama süre $\bar{t}$, üç ölçüm $t_1, t_2, t_3$ için

$$\bar{t} = \frac{t_1 + t_2 + t_3}{3}$$

ile hesaplanır.

> **Ek bilgi (derste anlatılmadı):** Web tarayan programlarda süreyi en çok ağ gecikmesi ve sayfanın yüklenme süresi belirler; bu yüzden aynı sayfanın ölçümü bile çalıştırmadan çalıştırmaya değişebilir. Tekrarlı ölçümün ortalamasının yanında en küçük ve en büyük değeri de vermek, dalgalanmanın büyüklüğünü göstermeye yardımcı olur.

## 6. Java'da Çalışma Süresi Ölçmek

Danışman öğrenciye süre tutmayı bilip bilmediğini sordu; öğrenci bilmediğini söyleyince danışman kendi ekranını paylaşarak bir geliştirme ortamında küçük bir örnek gösterdi.

### 6.1 `System.currentTimeMillis()`

`System` sınıfının `currentTimeMillis()` metodu statik bir metottur. 1 Ocak 1970 saat 00:00'dan itibaren kaç milisaniye geçtiğini `long` türünde döndürür. Bu komut çalıştırıldığında değişkene o anın milisaniye değeri gelir.

Süre ölçmek için yöntem şudur:

1. Ölçülecek işten hemen önce o anın değeri `begin` değişkenine alınır.
2. Bütün işlemler bittikten sonra aynı çağrı tekrar yapılır ve değer `end` değişkenine alınır.
3. `duration = end - begin` işin kaç milisaniye sürdüğünü verir.
4. Sonuç ekrana yazdırılır.

Danışmanın anlattığı kalıp şöyledir (altyazıdaki anlatımdan kuruldu):

```java
long begin = System.currentTimeMillis();

// ... süresi ölçülecek işlemler ...

long end = System.currentTimeMillis();
long duration = end - begin;
System.out.println("Time elapsed: " + duration);
```

<!-- BELİRSİZ: danışmanın ekranda yazdığı kod karelerde görünmüyor; değişken adları ve çıktı metni altyazıdan alındı -->

Danışman örneği bir test metodu içinde çalıştırdı. Ölçülen iş çok kısa olduğu için sonuç 0 ile 1 milisaniye arasında çıktı. Bu da milisaniye çözünürlüğünün çok kısa işler için yetersiz kalabileceğini gösterir; ama öğretim üyesi sayfalarının taranması gibi saniyeler süren işlerde yeterlidir.

> **Ek bilgi (derste anlatılmadı):** `currentTimeMillis()` duvar saatine bağlıdır ve sistem saati değişirse etkilenebilir. Çok kısa süreleri ölçmek için Java'da `System.nanoTime()` kullanılır; bu değer bir başlangıç anına göre nanosaniye cinsinden artar ve yalnız iki çağrı arasındaki farkı ölçmek için anlamlıdır. Kullanım kalıbı aynıdır: `long d = System.nanoTime() - start;`.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:03:17): Kırık link taraması duyurular kısmında 154. sayfaya kadar gidip durmadı. Bu, işin uzun sürmesinden mi, yoksa bir yerde takılmasından mı kaynaklanıyor?

> **Cevap (derste verildi):** Duyurular 6 sayfadır, ama son sayfadan sonra da "sonraki" düğmesi boş sayfalar getirmeye devam ettiği için tarama durma koşuluna ulaşmıyor. Çözüm olarak yalnız en son belirli sayıda ilanın taranması ve bu sayının ayarlanabilir olması önerildi.

**Soru 2** (derste sözlü, 00:05:21): Uygulama kırık bağlantıları kullanıcıya nasıl raporlayacak?

> **Cevap (derste verildi):** Kırık bağlantılar Kırık Link sekmesindeki metin alanında listeleniyor. Bunun yanına, metin alanının içeriğini bir dosyaya yazan bir "dosyaya kaydet" düğmesi eklenmesi önerildi.

**Soru 3** (derste sözlü, 00:07:29): Tez kitabının performans analizi bölümüne karmaşıklık analizinin yanında ne eklenebilir; çalışma zamanı nasıl ölçülebilir?

> **Cevap (derste verildi):** Her öğretim üyesi için yayın sayısı ve sayfanın işlenme süresi (ms) ölçülür, tabloya yazılır ve grafiğe dökülür. Süre `System.currentTimeMillis()` ile işten önce ve sonra alınan değerlerin farkı olarak hesaplanır; her ölçüm 3 kez yapılıp ortalaması alınır.

## Dersin Toparlaması

Bu görüşmede bir bitirme projesinin son aşaması ele alındı: Java, Swing ve Selenium ile yazılmış, bir bölümün akademik kadrosunu ve yayınlarını tarayan, sitedeki kırık bağlantıları bulan bir masaüstü uygulaması. Uygulamanın çalışan bir sürümü vardı; görüşmede ortaya çıkan sorun, sayfalı duyuru içeriğinde boş sayfalar yüzünden taramanın sonsuz döngüye girmesiydi. Danışman bunun için taranacak ilan sayısının bir ayar olarak sınırlanmasını, kırık link sonuçları için de metin alanını dosyaya kaydeden bir düğme eklenmesini önerdi.

Görüşmenin akademik açıdan en öğretici kısmı performans analiziydi. Karmaşıklık analizi, gerçek çalışma süresi ölçümüyle desteklenmelidir. Bunun için her girdi (öğretim üyesi) için girdi büyüklüğü (yayın sayısı) ve süre birlikte kaydedilir, tabloya ve grafiğe dökülür. Süre Java'da `System.currentTimeMillis()` farkıyla ölçülür, her ölçüm birkaç kez tekrarlanıp ortalaması alınarak arka plan işlerinin yarattığı dalgalanma azaltılır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
