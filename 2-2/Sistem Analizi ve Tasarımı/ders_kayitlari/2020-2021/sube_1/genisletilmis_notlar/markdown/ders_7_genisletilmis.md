# Ders 7 Genişletilmiş Notu: Alan Modeli, Use Case Diyagramları ve Belgeleri, Varlık-Nesne Farkı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin yeri: nesneye yönelik analize devam
- 2. Alan modeli (domain model)
- 3. Nesneye yönelik analizde aşamalar ve kaynaklar
- 4. Use case kavramı ve use case ile VAD farkı
- 5. Use case seviyeleri ve use case diyagramı
- 6. Use case belgesi: fully dressed format
- 7. Nesneye yönelik analiz: uygulama alanı, gereksinim belgesi ve kullanım öyküsü
- 8. Use case'lerden sınıflara: CRC ve ATM örneği
- 9. Veri varlığı ile nesne arasındaki fark
- 10. Yapısal yaklaşımla gereksinim analizi ve VAD kurallarının tekrarı
- Örnek Sorular

## 1. Dersin yeri: nesneye yönelik analize devam

Önceki derste analiz aşamasında nesneye yönelik analiz ile nesne ve varlık kavramları arasındaki fark ele alınmıştı. Bu ders aynı konuyla devam eder. Hoca bu konuların daha sonra nesneye yönelik programlama ve yazılım mühendisliği derslerinde de karşılarına çıkacağını söyler. Dersin ilk yarısında Craig Larman'ın kaynaklarına dayanan İngilizce slaytlarla alan modelleme ve use case konuları, ikinci yarısında bölümün Türkçe slaytlarıyla nesneye yönelik analiz, varlık-nesne farkı ve veri akış diyagramlarının (VAD) tekrarı işlenir.

## 2. Alan modeli (domain model)

### 2.1 Tanım ve amaç

Alan modelinde "alan", bilgi sistemi hazırlanacak sistemin uygulama alanıdır. Örneğin bir hastane bilgi sistemi kurulacaksa hastane alanında hangi nesnelerin olduğu ve bu nesneler üzerinde hangi işlemlerin yapıldığı sorulur: hastalar hakkında bilgi tutulur, doktorlar hakkında bilgi tutulur, yapılan işlemler hakkında bilgi tutulur.

Slayttaki tanım şöyledir (ekrandan, 00:05:00):

- Alan modeli, önemli kavramları ya da nesneleri UML sınıf diyagramı notasyonuyla görselleştirir.
  - Bir tür "görsel sözlük"tür (visual dictionary).
  - Yazılım sınıflarının resmi *değildir*.
- Önemli bilgiyi tanımlamaya, ilişkilendirmeye ve görselleştirmeye yardım eder.
- Sonradan yazılım tasarım sınıflarının oluşturulmasına ilham verir ve "temsil boşluğunu" (representational gap) azaltır.

Hoca, modelin sınıfları birbirine bağlaması ve arada boşluk bırakmaması gerektiğini vurgular: sınıflar arasındaki ilişkilerin ve sınıfların birbiriyle nasıl bağlantı kurduğunun modelden görülebilmesi gerekir. Sonuçta hedef, bir UML sınıf diyagramı yazabilmek ve yazılmış bir diyagramı okuyup anlayabilmektir.

### 2.2 Video kiralama mağazası örneği

Dersin ana örneği videoların müşterilere kiralandığı bir mağazadır. Mağazanın müşterileri vardır, müşteriler video kiralar ve mağazanın hangi videoların bulunduğunu gösteren stokları vardır. Bunlar arasında "bire çok, ama en az bir" gibi kurallarla tanımlanan ilişkiler vardır.

Bir alan modeli kurulurken önce bir aday kavram listesi çıkarılır. Analiz aşamasındaki bu sınıf diyagramına kavramsal sınıf diyagramı denir. Diyagram mümkün olduğunca basit haliyle kurulur, sonra eklemelerle geliştirilir.

### 2.3 Bağlantılar ve çokluluk

Bağlantı (association) çizgisinin üzerindeki ad ok yönünde okunur: "Video mağazası videoları depolar." Bağlantının bir ucunda `1`, diğer ucunda `*` varsa "bir video mağazası çok sayıda video saklar" diye okunur.

Çokluluk gösterimleri:

- `*`: sıfır ya da daha çok.
- `1..*`: bir ya da daha çok.
- `0..1`: sıfır ya da bir; zorunluluk yoktur, seçimliktir.
- Belirli bir sayı ya da aralık da yazılabilir, ama çok kullanılmaz. Genellikle `*`, `1` ve `0` kullanılır.

Hoca örnek diyagramı iki yönde okur: müşteri mağazaya üye olmuştur ve çok sayıda video kiralayabilir; ters yönden okununca bir videoyu şimdiye kadar hiçbir müşteri kiralamamış olabilir. <!-- BELİRSİZ: bu bağlantıların slayttaki tam çokluluk değerleri karelerde görünmüyor. -->

Hoca bu kavramların nesneye yönelik programlama dersinde de görüldüğünü, yine de bir kez daha üzerinden geçildiğini belirtir.

### 2.4 Nitelikler ve bir yönerge

Kavram kutusu basit tutulur: üstte nesnenin adı, altında özellikleri yer alır. Örneğin ödeme (payment) kavramının özellikleri tarih, zaman ve ödenen miktardır.

Slaytta nitelik yazımıyla ilgili bir yönerge "Why??" sorusuyla gösterilir (ekrandan, 00:10:00):

| Durum | Gösterim |
|---|---|
| Daha kötü (Worse) | `Customer` sınıfında `rentedVideos: List of Video` niteliği; `Video` sınıfında `renter : Customer` niteliği |
| Daha iyi (Better) | `Customer` ile `Video` arasında `Rents` bağlantısı; `Customer` ucunda `1`, `Video` ucunda `1..*` |

Yani başka bir kavramsal sınıfı gösteren bilgi nitelik olarak gömülmez, iki sınıf bir bağlantıyla ilişkilendirilir.

### 2.5 Tamamlanmış alan modeli

Video mağazasının tamamlanmış modelinde ana iş akışı şudur: mağaza videoları depolar, müşteri video kiralar. Müşteri nakit ödeyebilir; video kiralama işlemi ödemeden sonra gerçekleşir ve kiralamada hangi tarihte ve hangi saatte kiralandığı bilgisi tutulur. Mağazanın bir kataloğu vardır; depodaki videolar bu katalogda yer alır ve video tanımları kategorilere ayrılabilir. Müşteri üye olabilir ya da yalnız bir kerelik alım yapabilir; müşteri ile üyelik arasında bire bir ilişki vardır.

Slaytın son kısmındaki hedefler ekranda şöyle listelenir (ekrandan, 00:15:00): alan modeli için UML sınıf diyagramı notasyonunu okuyup yazabilmek, bir alan modeli oluşturabilmek, yönergeleri uygulayabilmek ve alan modelini diğer ürünlerle (artifact) ilişkilendirebilmek.

## 3. Nesneye yönelik analizde aşamalar ve kaynaklar

### 3.1 Üç aşama

Hoca süreci üç aşamada özetler:

- İş modelleme (business modeling): alan modeli çıkarılır. Müşterilerden bilgi toplandıkça alan modeli oluşur; önce uygulamada neler hakkında bilgi tutulacağı belirlenir ve her iterasyonda model geliştirilir.
- Gereksinimler (bizim "sistem analizi" dediğimiz aşama): use case'ler metin olarak yazılır, use case diyagramları oluşturulur. Hangisinin önce yapılacağına ekip karar verir; belgeler ve diyagramlar paralel de yürütülebilir. Bundan sonra sistem sıralama (sequence) diyagramının modeli oluşturulmaya başlanabilir.
- Tasarım: tasarım modeli gelir.

Her iterasyonda bu aşamalara yeni şeyler eklenebilir.

### 3.2 Tasarım kalıpları

Slaytlarda kalıplar (patterns), yani tasarım kalıpları da geçer. Hoca bunların ileride görüleceğini, bu derste yalnız tasarım aşamasında tasarım kalıplarının var olduğunun belirtileceğini söyler.

### 3.3 Kaynaklar

Veri modelinin nasıl oluşturulacağıyla ilgili önerilen kaynaklar da slaytta verilir; hoca dersteki referansların şimdilik yeterli olduğunu, bunların ek kaynak olduğunu söyler. Use case kısmında Alistair Cockburn'ün yaklaşımının popüler olduğu ve Larman'ın "Applying UML and Patterns" kitabının bu tarzı izlediği gösterilir; kitabın use case bölümleri Cockburn ile birlikte yazılmıştır (ekrandan, 00:20:00). Hoca ayrıca UML yaklaşımının ilk çalışanları olarak Booch, Jacobson ve Rumbaugh üçlüsünü anar ve tasarım kalıplarının da yine bu yaklaşım içinde başladığını söyler.

> **Ders sonrası not:** Altyazıda "LARMA" diye geçen ad ekrandaki kitap kapağına göre Craig Larman'dır; "Butch Jacobson, Rambo" diye geçen adlar UML'nin kurucuları Grady Booch, Ivar Jacobson ve James Rumbaugh'dur. Tasarım kalıplarını yaygınlaştıran "Design Patterns" kitabı ise büyük olasılıkla Gamma, Helm, Johnson ve Vlissides'e ("Dörtlü Çete") aittir; hocanın kalıpların bu üçlü tarafından başlatıldığı sözü bu açıdan tam doğru değildir.

## 4. Use case kavramı ve use case ile VAD farkı

### 4.1 Use case nedir

Use case'ler işlevsel gereksinimleri yakalamanın bir yoludur. İşlevsel gereksinimden kasıt, sistemde hangi işlemlerin gerçekleştiğidir. Use case'ler sistemi kullanan "hikayeler"dir.

Bu konuda öğrenilecekler şöyle sıralanır:

- Use case seviyelerini tanımlamak: önce genel olarak sistemde ne olduğu, sonra işlemlerin ayrıntıları.
- Farklı use case formatlarından birini seçmek; formatlar arasında küçük farklar vardır.
- Use case yönergesindeki kuralları uygulamak.
- Use case diyagramlarını "okur yazar" olmak.

> **Hocanın vurgusu:** Okur yazar olmak, karşınıza bir use case diyagramı geldiğinde ne dediğini anlayıp tasarıma aktarabilmek ve düz yazıyla yazılmış bir hikaye geldiğinde bunu use case diyagramına çevirebilmek demektir.

### 4.2 Soru: use case ile veri akış diyagramı arasındaki fark

**Soru:** Akış diyagramlarında da sistemin nasıl çalıştığını anlatıyorduk; buradaki fark nedir?

**Cevap:** VAD'lerde de aynı şey yapılır. Fark, varlık tanımı ile nesne tanımı arasındadır. Use case diyagramları klasik yaklaşımda da kullanılabilir, ama esas olarak nesneye yönelik yaklaşımda analiz aşamasında kullanılır. Hakkında bilgi tutulacak şeyler varlık olarak tanımlanıp onlara hangi işlemlerin uygulandığı ayrıntısına girilmediğinde klasik yaklaşım kullanılmış olur. Klasik yaklaşımda VAD'lerle aşama aşama ve daha sistematik ilerlenir: önce bağlam (context) diyagramında sistemin hangi varlıklarla ilişkiye girdiği gösterilir, sonra birinci düzey ayrıntılı diyagramda bütün sistemin alt işlemleri, ardından her alt işlem ayrıca gösterilir. Klasik yaklaşımda varlıklar ve işlemler ayrı tanımlanıp birleştirilir. Nesneye yönelik yaklaşımda ise nesneler ilişkilendirilir ve hangi hikayelerde birlikte çalıştıkları görülür; nesnenin hem özellikleri hem ona uygulanan işlemler tanımlanır. Varlıklarda yalnız varlığın adı ve özellikleri belirtilir, işlemler ve işlem hiyerarşisi VAD'lerde gösterilir.

Hoca bu sorunun önemli olduğunu, dersin ilk uygulama dersi olarak yazılım geliştirmenin bütün evrelerinden geçtiğini ve hem klasik hem nesneye yönelik yaklaşımı tanıtmak istediklerini söyler; farkı dersin sonunda ayrı bir slaytla yeniden gösterir (bkz. Bölüm 9).

### 4.3 Hedef ve aktörler

Bir use case'te bir hedef belirlenir ve sistemin bu hikayeyi nasıl gerçekleştirdiği gösterilir. Hikayenin birincil (primary) aktörü ve onu destekleyen aktörler verilir.

Video kiralama hikayesinde bir görevlinin kimliği vardır ve müşterilere video kiralar. Sistem her işlemden bir çıktı üretir; görevli kiralama raporlarını almak ister ve sistem bu çıktıları verir. Müşteri ile videolar arasında ilişki kurulur. Bu senaryo hem use case diyagramıyla hem use case belgesiyle anlatılır.

## 5. Use case seviyeleri ve use case diyagramı

### 5.1 Seviyeler

Nesneye yönelik analizde use case diyagramları UML sınıf diyagramlarıyla ilişkilendirilir. Veri akış diyagramlarında nasıl seviyeler varsa use case'lerde de vardır: üstten bakışta alttaki ayrıntıyı görmeden ne olduğunu görmek, sonra aşağıdaki ayrıntıyı görmek.

Slaytta sorulan soru şudur (ekrandan, 00:25:00): yaygın bir zorluk, use case'leri yararlı bir hedef seviyesinde belirlemektir; aşağıdakilerden hangisi yararlı seviyededir?

- Negotiate a Supplier Contract (tedarikçi sözleşmesi müzakere etmek)
- Rent Videos (video kiralamak)
- Log In (giriş yapmak)
- Start Up (sistemi başlatmak)

Hoca, en başta bütün ayrıntının verilmesinin doğru olmadığını, bütün organizasyonu tek bir ayrıntılı use case'te vermenin karmaşıklık yarattığını söyler. Aynı şekilde VAD'lerde de ikinci düzey ayrıntının hepsi tek diyagramda birleştirilirse diyagram takip edilemez olur; karmaşıklık çıkmasın diye kademe kademe gidilir.

Bu kademeli çalışma sistem analizindeki aşamalarla da örtüşür: bilgi toplama, modelleme ve raporun oluşturulması. Toplanan bilgiye göre use case'ler aşama aşama ayrıntılandırılır. Hem bir metin belge hem bir diyagram üretilir. Belgede tanımlar belli bir formatta ve sırayla verilir. Diyagramda da VAD'deki gibi önce bağlam düzeyinde genel bir diyagram çizilir, sonra use case'ler daha fazla diyagramla ayrıntılandırılır.

### 5.2 Video mağazası use case diyagramı

Slayttaki diyagram şöyledir (ekrandan, 00:30:00):

```text
Sistem sınırı: Video Store Information System

Clerk (çöp adam)          -> Pay Fines, Rent Items, Manage Memberships, Log In
Customer (çöp adam)       -> Pay Fines, Rent Items, Manage Memberships
Administrator (çöp adam)  -> Log In, Manage Inventory, Manage Users
«actor» Credit Authorization Service (dikdörtgen, sağda) -> Pay Fines, Rent Items
```

Görevli kiralama işlemi yapar, üyelikleri yönetir, sisteme girer; müşteri ödeme yapar, kiralar ve üyelik işlemlerini gerçekleştirir; yönetici sisteme girer, envanteri yönetir ve kullanıcıları belirler. Kredi onay servisi başka bir yazılım olabilir; örneğin bir ev güvenlik sisteminde bu bir sensör olabilirdi. Bunlar sisteme destek verdikleri için aktördür ve dikdörtgenle gösterilir.

Slaytın yanındaki uyarı: "Diyagrama fazla zaman harcamayın. Use case çalışması diyagram çizmek değil, metin yazmaktır." Hoca bunu, temel sembollerle diyagramı bir başlangıç olarak çizip asıl emeği use case belgelerine vermek diye açıklar.

### 5.3 Semboller

- Elips: use case, yani sistemde gerçekleşen bir alt işlem. Her biri bir hikayeden çıkar.
- Çöp adam: canlı aktör.
- Dikdörtgen ya da kare: sisteme girdi sağlayan, canlı olmayan aktör.
- Büyük dikdörtgen: bütün uygulama; içindeki işlemlerin aynı sistem içinde gerçekleştiğini gösterir.

Birincil aktör genellikle solda, destek aktörleri sağda çizilir. Use case'lerde başlangıç ve bitiş belirtilmelidir: başlangıçtaki koşullar (ön koşullar) ve use case'in bittiğinin nasıl anlaşılacağı.

## 6. Use case belgesi: fully dressed format

### 6.1 Video kiralama belgesi

Belgenin ilk kısmında use case adı (video kiralama), birincil aktör (görevli) ve ön koşullar yer alır. Ön koşul, görevlinin tanıtılması ve doğrulanmasıdır, yani işlemi yapanın gerçekten görevli olup olmadığının denetimi.

Paydaşlar ve ilgileri şöyle verilir:

- Görevli: doğru ve hızlı giriş yapmak ister.
- Müşteri: videoları en az çabayla hızlı almak, hızlı servis ister.
- Muhasebe: kayıtların doğru tutulmasını ister.
- Pazarlama: daha sonra satış değerlendirmesi yapacağı için müşterinin alışkanlıklarını izleyebilmek ister.

Uygulama bunların hepsini desteklemelidir.

### 6.2 Ana başarılı senaryo

Aktörler ve paydaşlar belirlendikten sonra temel akış ("happy path") yazılır. Müşteri kiralamak üzere gelir; görevli müşteri kimliğini ve kiralama tanımlayıcı bilgilerini girer ve aldığı her ürün için 3. ve 4. adımları tekrarlar. Sonunda toplam fiyat çıkar, müşteriye bildirilir ve müşteri öder. Görevli sistemden kiralama raporunu ister, çıktıyı alır ve müşteriye verir. Müşteri kiraladıklarıyla ve raporla işi tamamlar. Bu, hiçbir sorun olmadığı durumdur.

### 6.3 Uzantılar (alternatif akışlar)

Sorun çıkabilecek durumlar da belirtilmelidir. Slayttaki uzantılar şunlardır (ekrandan, 00:35:00):

```text
Extensions (or Alternatives):
a*. Herhangi bir anda sistem çökerse:
    1. Görevli sistemi yeniden başlatır
    2. giriş yapar
    3. önceki durumdan kurtarma ister
1a. Yeni müşteri:
    1. Manage Membership use case'ini çalıştır.
2a. Müşteri kimliği bulunamadı:
    1. Kasiyer kimliği doğrular. Giriş hatasıysa yeniden girer,
       değilse Manage Membership.
2b. Müşterinin ödenmemiş cezası var (genellikle geç iade için):
    1. Pay Fines.
```

Uzantı numarası ana senaryodaki hangi adımdan ayrıldığını gösterir; `a*` her adımda olabilecek bir durumdur. Uzantılar başka use case'lere (Manage Membership, Pay Fines) gönderme yapabilir.

### 6.4 Temel ve somut use case

Slayt (ekrandan, 00:40:00) "Arayüzü dışarıda tutun" der:

- Temel (essential) use case'ler kullanıcı arayüzü ayrıntılarını erteler ve aktörlerin *niyetlerine* odaklanır.
- Temel yazım: "Clerk enters Customer ID." (Görevli müşteri kimliğini girer.)
- Somut (concrete) yazım, daha kötü: "Clerk takes Customer ID card and reads the bar code with laser scanner." (Görevli müşteri kartını alır ve barkodu lazer okuyucuyla okutur.)

### 6.5 Tamamlanmış belge ve use case'in değeri

Aktörlerin tanımı, her aktörün gerçekleştirdiği işlemler ve sistemde gerçekleşen işlerin sırası verildiğinde tamamlanmış bir use case belgesi elde edilir. Use case modeli bir uygulamayla ilgili bütün hikayeleri gösterir, rahat kullanılır ve teknik olmayan kişilerce de kolay takip edilir. Slaytta "Use Cases: Requirements in Context" kitabından hareketle use case'lerin ilgili gereksinimleri bir araya getirdiği ve onlara daha çok bütünlük ve bağlam kazandırdığı belirtilir (ekrandan, 00:50:00). Gereksinimler önce bir taslakta özet olarak verilip sonra genişletilmelidir. Alan modeli, gereksinimler ve tasarım üçlüsünde her iterasyonda daha fazla ayrıntı eklenebilir.

> **Hocanın vurgusu:** Use case seviyelerini oluşturabilmek, use case diyagramlarını okuyup yazabilmek ve diyagram kurallarını doğru okuyabilmek gerekir.

## 7. Nesneye yönelik analiz: uygulama alanı, gereksinim belgesi ve kullanım öyküsü

### 7.1 Çözümleme ve uygulama alanının çözümlenmesi

Nesneye yönelik analizde çözümleme (analiz), bir şeyi anlayabilmek için parçalarına ayırmaktır. Uygulama alanının çözümlenmesi (domain analysis) ilk İngilizce slaytlardaki alan modellemenin karşılığıdır (ekrandan, 00:55:00):

- Amaç, uygulama alanını anlamak ve elde edilen bilgileri analiz modeline taşımaktır.
- Uygulama alanı hakkında bilgi edinilecek kaynaklar: teknik literatür, mevcut uygulamalar, müşteri anketleri, uzman tavsiyeleri.
- Mevcut ve gelecekteki gereksinimler ortaya çıkarılır.

### 7.2 Doğal dille gereksinim belgesi

Gereksinimler belirlenirken müşterinin programdan beklentilerini doğal konuşma diliyle anlatan bir belge oluşturulur. Derste okunan örnek bir perakende satış programıdır:

- Önceki satış programı web üzerinden satışı desteklemediği için yenilenmesi gerekiyor.
- Program kasada yapılan alışveriş işlemlerine yardım eder; yapılan her işlem saklanmalıdır.
- Mali bilgiler harici bütçe sistemine, mal çıkış bilgileri harici envanter sistemine iletilmelidir.
- Saklanan işlemler üzerinde daha sonra raporlama ve analiz yapılabilmelidir.
- Sistem alışveriş karşılığında müşteriye fiş vermelidir; her satış için KDV hesaplanıp ayrıca belirtilmelidir.
- Şirketin birden fazla şubesi vardır ve şubelerin işlemleri merkezi sunucuya iletilmelidir.

Analist müşteriyle konuşur ve bunların yapılması gerektiğini anlar; bu belge buradan çıkar.

### 7.3 Kullanım öyküsü

Kullanım öyküleri (use case'ler), programın yapacağı işleri ayrıntılı adımlarla ve belli kurallara uyarak anlatan belgelerdir. Ürünün sağlaması beklenen işlevleri ve çalışma ortamını belirtirler. Amaçları son kullanıcı ile yazılım ekibi arasında bir anlaşma zemini oluşturmak, sistemle kullanıcının nasıl etkileşeceğini tanımlamak ve testler için zemin hazırlamaktır: kullanıcı testi yapılırken isterlerin nasıl belirlendiği bu belgelerden anlaşılır.

### 7.4 Satış işlemi kullanım öyküsü

- Birincil aktör: kasiyer. Satış işlemini o yapar.
- İlgililer ve ilgileri:
  - Kasiyer doğru ve hızlı giriş ister; kasa açığı maaşından kesildiği için ödeme hatası istemez.
  - Satıcı, yani mağazada dolaşıp satışa yardım eden ve satış yaparsa komisyon alan kişi, diğer ilgililer arasındadır.
  - Müşteri en az çabayla en hızlı hizmeti ister; ürün iadesi gerektiğinde bunun yapılabilmesi için fiş ister.
- Ön koşul: kasiyerin kimliği doğrulanır; kasiyer kasayı açmak için kimlik doğrulaması yapar.
- Son koşul: ödeme tahsil edilir, satış kaydedilir ve fiş yazılır.

Ana öykü 11 adımdır (ekrandan, 01:00:00):

```text
1. Müşteri kasaya alacağı ürünlerle gelir.
2. Kasiyer yeni bir satış işlemi başlatır.
3. Kasiyer ürünün barkodunu girer.
4. Sistem bir satış kanalı maddesi oluşturur. Bu maddede ürün tanımı,
   fiyatı ve toplam bedel (aynı maldan birden fazla alınmış olabilir) yer alır.
5. Kasiyer 3. ve 4. adımları müşterinin alacağı tüm ürünler için tekrarlar.
6. Sistem toplam bedeli vergi iadesi ile birlikte hesaplar.
7. Kasiyer müşteriye toplamı bildirir ve ödeme ister.
8. Müşteri ödemeyi yapar ve sistem ödemeyi tahsil eder.
9. Sistem tamamlanan işlemin kaydını tutmayı tamamlar ve harici envanter
   ile mali sistemlere gerekli bilgileri gönderir.
10. Sistem fiş verir.
11. Müşteri ürünlerle birlikte ayrılır.
```

> **Ders sonrası not:** Slaytta ve anlatımda "vergi iadesi" geçiyor; Larman'daki karşılığı büyük olasılıkla "vergiler hesaplanmış toplam"dır (total with taxes calculated). Burada kastedilen iade değil, satışa eklenen vergidir (KDV). "Satış kanalı maddesi" de büyük olasılıkla "satış kalemi" (sales line item) anlamındadır.

Adımların sırası önemlidir: alan modellemede müşterilerden işlerin nasıl yürüdüğü nasıl dinlendiyse sıra öyle olmalıdır. Maddeler belirlenirken algoritmalardaki gibi her maddenin tek bir temel işi anlatması istenir. Dokuzuncu adımda sistem bütçe programına ve envanter programına yapılan işlemin bilgilerini gönderir.

### 7.5 Alternatif öyküler

Bu ana öykü sorunsuz akıştır (önceki slaytlardaki "happy path"). Sorun çıkarsa alternatif öyküler oluşur:

- `3a` Geçersiz barkod: sistem uyarı mesajı verir ve kayıt girişini reddeder.
- `3-7` Müşteri bir kalemi alışverişten çıkarmak ister: 3. ile 7. adımlar arasındaki herhangi bir anda olabilir. Örneğin 7. adımda kasiyer toplamı bildirdiğinde müşteri bir ürünün çok pahalı olduğunu fark edip çıkarmak isteyebilir. Kasiyer satıştan çıkarılacak ürünün barkodunu okutur ve sistem güncel toplamı bildirir.

## 8. Use case'lerden sınıflara: CRC ve ATM örneği

### 8.1 Sınıfların ve üyelerin belirlenmesi

Kullanıcı gereksinimleri belgesinden ve kullanım senaryolarından sınıflar elde edilir: hangi sınıfların olduğu, hangi bilgilerin saklandığı ve hangi hizmetlere gerek duyulduğu belirlenir; gereken varlıklar böylece ortaya çıkar. Üyeler belirlenirken sorumluluklar tanımlanır. Bunun için CRC (Class, Responsibility, Collaboration) kartları kullanılır: her sınıfın sorumluluğu nedir ve bu sınıf hangi sınıflarla iş birliği içindedir. Bu, use case'lerden sınıf diyagramına geçiştir.

Sorumluluklar dağıtılmalı, bir yerde yoğunlaşmamalıdır; tek bir şey hakkındaki bilgi tek bir sınıfta toplanmamalıdır.

> **Ek bilgi (derste anlatılmadı):** CRC kartı genellikle küçük bir kağıt karttır: üstte sınıf adı, solda sınıfın sorumlulukları (bildiği ve yaptığı şeyler), sağda bu sorumlulukları yerine getirmek için birlikte çalıştığı sınıflar yazılır. Ekip kartları masada senaryoları canlandırarak sınıflar arası sorumluluk dağılımını sınar.

### 8.2 ATM örneği

Kullanım senaryosunun temel öğeleri ATM'den para çekme örneğiyle gösterilir (ekrandan, 01:05:00):

```text
ATM Use Cases Inception          package OpenUP (1/2)
Sistem sınırı: atm: ATM

'Bank Customer' (solda)      -> 'Withdraw Cash', 'Transfer Funds', 'Deposit Funds'
'Maintenance Person' (solda) -> 'Refill Machine'
'Bank' (sağda, çöp adam)     -> 'Withdraw Cash', 'Transfer Funds', 'Deposit Funds'
```

Banka müşterisi bankamatikten nakit çekebilir, fon transferi ve para yatırma yapabilir; bakım personeli makineye yeniden para doldurur.

**Soru:** Banka neden canlı aktör (çöp adam) olarak çizilmiş?

**Cevap:** Burada bankadaki memur bu işi yapıyormuş gibi düşünülmüş. Ama bankamatiğin arkasında bir sistem vardır ve para çekme işini memurlar değil otomatik banka sistemi gerçekleştirir. Kaynak kitapta böyle çizilmiş olsa da kare (dikdörtgen) olarak gösterilmesi daha uygundur.

## 9. Veri varlığı ile nesne arasındaki fark

### 9.1 Soru: nesneler, varlık dediğimiz şeyler mi?

**Soru:** Nesneler, birinci düzey ayrıntılı şemalarda varlık dediğimiz şeyler miydi?

**Cevap:** Oralarda kullanılan varlıklar, buradaki nesnelerin yapısına karşılık gelir; fark aşağıda anlatılır.

### 9.2 Veri varlıkları ve nesneler

Bilgi sistemlerinde, özellikle geleneksel yaklaşımda, sistemde hakkında veri saklanması gereken şeylere veri varlığı ya da kısaca varlık denir. Varlıklar varlık ilişki (ER) diyagramlarıyla modellenir ve ilişkisel veri tabanında işlenir; ER diyagramları veri tabanı dersinde de görülecektir. Nesneye yönelik yaklaşımda ise nesnelerde hem davranışlar hem özellikler saklanır.

- Sınıf: hakkında bilgi tutulan şeyin tipi.
- Nesne: bu sınıfın özel bir hali (örneği).
- Metotlar: nesnelerin davranışları.

Hocanın asıl göstermek istediği şekil iki mimariyi karşılaştırır. Geleneksel yaklaşımda veri varlığı ayrı bir yerde, uygulamadaki işlemler ayrı bir yerde durur. Varlıklar veri tabanından alınarak programda İşlem 1, İşlem 2, İşlem 3 içinde kullanılır, işlendikten sonra veri tabanına geri yazılır. Nesneye yönelik yaklaşımda nesneler metotlarını kapsüller (encapsulation); nesneye ait veri ve bu veriyi işleyecek yöntemler nesne tanımı içinde verilir. Bu metotları çalıştırmak için mesaj alışverişi olur: gelen mesaj işlemin çalışmasını tetikler. <!-- BELİRSİZ: karşılaştırma şeklinin karesi yok; anlatım altyazıdan. -->

### 9.3 ER diyagramı örneği

Varlıklar arasındaki ilişkiler ER diyagramında görülür (ekrandan, 01:15:00):

```text
Customer  |----------O<  Order
- Bir müşteri sıfır ya da daha çok sipariş verebilir (Order ucunda halka + çatal).
- Bir sipariş tam olarak bir müşteri tarafından verilir (Customer ucunda tek çizgi).
```

Bunun devamında müşteri, sipariş ve sipariş kalemi ilişkisi anlatılır: kasiyerin yaptığı işlemde müşteri bir sipariş başlatır, ama bir siparişte bir mal da olabilir, on beş mal da; bir sipariş çok sayıda ürünle ilişkilidir. Gerçek örneklerle bir müşterinin iki siparişi olabilir ve her birinde üçer ürün bulunabilir, başka bir müşterinin tek siparişinde üç ürün olabilir.

Sınıf diyagramı çizilse bile veri sonunda ilişkisel veri tabanına kaydedilecekse uygulamanın son halinde sınıf diyagramı ER diyagramına çevrilebilir.

### 9.4 Sınıf diyagramı: hiyerarşi ve bütün-parça

Sınıflar veri varlıklarından farklıdır: genelleştirme ve özelleştirme hiyerarşileri kurulabilir, alt sınıflar oluşturulabilir ve alt sınıflarda kalıtıma izin verilir. Ortak karakteristikleri paylaşan üst sınıflara süper sınıf denir.

- Genelleştirme/özelleştirme: sedan bir araba çeşididir ve arabanın bütün özelliklerini taşır; bir üste çıkınca araba bir motorlu taşıttır ve motorlu taşıtın bütün özelliklerini taşır. Spor araba da arabanın bir alt sınıfıdır.
- Bütün-parça (aggregation): bir bütünün parçaları arasındaki ilişkidir; örneğin bilgisayar ve ek parçaları, bütünü bilgisayar gösterir.

### 9.5 Varlık sembolü ile sınıf sembolü

Varlığın iki bölmesi vardır: varlığın adı ve özellikleri. Sınıf sembolünün üç bölmesi vardır (ekrandan, 01:20:00):

| Bölme | Örnek (`Customer`) | Açıklama |
|---|---|---|
| Sınıf adı | `Customer` | Sınıfın adı |
| Nitelikler | `name`, `address`, `phone` | Sınıftaki bütün nesnelerin bunların her biri için bir değeri vardır |
| Metotlar | `addNew`, `delete`, `change`, `connectToAccount` | Sınıftaki bütün nesnelerin nasıl yapacağını bildiği işler |

Banka hesabı sistemi sınıf diyagramı iki sınıf arasındaki ilişkiyi gösterir: bir müşterinin hiç hesabı olmayabilir ya da çok sayıda hesabı olabilir. Hoca sınıflar arasındaki bu bağlantıların ER diyagramındaki ilişkilere çok benzediğini belirtir. <!-- BELİRSİZ: banka hesabı sınıf diyagramının ayrıntıları (alt sınıflar, nitelikler) karede görünmüyor. -->

## 10. Yapısal yaklaşımla gereksinim analizi ve VAD kurallarının tekrarı

### 10.1 Hangi yaklaşım, hangi diyagramlar

Bir öğrencinin hangi konuya en çok çalışılması gerektiği sorusuna hoca analiz aşamasında en önemli şeyin VAD'leri okur yazar olmak, yani verilen bir durumun (case) VAD'sini çizebilmek olduğunu söyler; bir pakette üç kademe vardır. Use case'lerden sonra VAD'lerin unutulmaması için onları yeniden açar.

**Soru:** Bir çalışmada bu iki yaklaşımdan birini mi seçeceğiz?

**Cevap:** Evet. Ekip nesneye yönelik ya da klasik (yapısal) yaklaşımı seçer ve seçtiği yaklaşımın diyagramlarını kullanır. Yapısal yaklaşımda tasarım aşamasında yapı diyagramı ve ER diyagramı kullanılır. Nesneye yönelik yaklaşımda tasarım aşamasında sıralama (sequence) diyagramı ve sınıf diyagramı kullanılır.

### 10.2 Yapısal gereksinim analizi modeli

Yapısal yaklaşımla gereksinim analizi modelinde bir veri sözlüğü, bir varlık ilişki diyagramı ve bir veri akış diyagramı hazırlanır. Süreç tanımı VAD ile, veri tanımı ERD ile yapılır. Slayttaki model iç içe halkalardan oluşur (ekrandan, 01:25:00):

```text
Merkez:    Veri Sözlüğü
İç halka:  Varlık İlişki Diyagramı | Veri Akış Diyagramı | Durum Geçiş Diyagramı
Dış halka: Veri Nesne Tanımı       | Süreç Spesifikasyonu | Kontrol Spesifikasyonu
```

- Veri sözlüğü, yazılımın kullandığı ve ürettiği bütün veri nesnelerinin tanımını içerir.
- Varlık ilişki diyagramı veri modelleme aşamasında kullanılır.
- Veri akış diyagramları sistem analizi boyunca fonksiyonların modellenmesinde kullanılır.

Bağlam diyagramları da sistemin dış birimlerinin sistemle ilişkisini basitçe gösterir.

### 10.3 VAD kuralları

Örnek bir birinci seviye diyagram üzerinden kurallar yeniden anlatılır (ekrandan, 01:30:00):

```text
Varlıklar:  Öğrenci | Öğretim Üyeleri | Öğrenci (ikinci kez çizilmiş)
İşlemler:   Ders Seç | Sınav sonuçlarını sisteme ekle | Sınav sonucu görüntüle
Veri depoları: Öğrenci-Ders veritabanı tablosu | Öğrenci-Not veritabanı tablosu

Öğrenci -> Ders Seç : Ders Seçimi
Ders Seç -> Öğrenci-Ders veritabanı tablosu : Öğrenci-seçilen dersler bilgisi
Ders Seç -> Sınav sonuçlarını sisteme ekle : Öğrenci-seçilen ders bilgileri
Sınav sonuçlarını sisteme ekle -> Öğretim Üyeleri : Sınıf listesi
Öğretim Üyeleri -> Sınav sonuçlarını sisteme ekle : Sınav sonuçları
Sınav sonuçlarını sisteme ekle -> Öğrenci-Not veritabanı tablosu : Sınav sonuçları
Sınav sonuçlarını sisteme ekle -> Sınav sonucu görüntüle : Öğrenci-not bilgisi
Öğrenci-Not veritabanı tablosu -> Sınav sonucu görüntüle : Sınav sonuçları
Sınav sonucu görüntüle -> Öğrenci : Sınav sonuçları
```

Kurallar:

- Varlıktan varlığa doğrudan veri aktarımı olmaz; bir kareden bir kareye okla veri aktarılamaz, arada mutlaka bir işlem olmalıdır. Örneğin öğrenciden doğrudan öğretim üyesine veri gidemez.
- Bir varlıktan veri saklama ortamına (öğrenci not veri tabanı tablosu gibi) doğrudan veri girişi olamaz; arada işlem olmalıdır.
- Veri saklama ortamından varlığa ya da başka bir veri saklama ortamına da veri kendiliğinden aktarılamaz; aktarmayı anlatan bir işlem eklenmelidir. Veri bir dosyadan başka dosyaya "kendi kafasına göre" gidemez.
- İşlemden işleme veri akabilir. İşlem kenarları yuvarlatılmış dikdörtgenle gösterilir.
- Diyagram karışmasın diye bir varlık ikinci kez çizilirse, ikinci kullanımın ucuna daha önce kullanıldığını gösteren bir çizgi konur. Bu örnekte öğrenci ikinci kez çizildiği halde işaretlenmemiştir; bu bir hatadır.
- Giden ve gelen her veri ayrı bir okla gösterilir ki ok üzerindeki veri adları karışmasın.
- Bağlam (özet) diyagramında tek bir işlem vardır; o da bütün sistemi anlatır (örneğin "faturalama sistemi").
- Bağlam diyagramı ile birinci düzey diyagram arasında mantıksal tutarlılık olmalıdır: birinde sisteme üç varlık bağlanıyorsa diğerinde beş varlık bağlanmışsa diyagram hatalıdır.

> **Hocanın vurgusu:** Size hatalı bir diyagram verildiğinde doğrusunu belirleyebilmeniz gerekir. Veri kendiliğinden gidiyorsa diyagram hatalıdır; arada mutlaka bir işlem olmalıdır.

Bir öğrenci kural olarak "bir seferde tek bir işlem gerçekleşebilir, bir okun yanına başka bir şey eklenemez" dediğinde hoca bunu düzeltir: bir işleme başka veri akışları da eklenebilir; "tek işlem" kuralı yalnız bağlam diyagramı için geçerlidir.

### 10.4 Birinci ve ikinci düzey ayrıntılı VAD

Birinci düzey ayrıntılı VAD örneğinde varlıklar doktor, hasta (ikinci kez çizilmiş ve işaretli) ve sigorta şirketidir. İşlemlerin üzerindeki 1.0, 2.0, 3.0, 4.0 numaraları işlemleri ve sırasını gösterir; D1, D2, D3, D4 veri saklama ortamlarıdır (bir veri tabanı ya da dosya olabilir). İşlemden işleme veri aktarımı da vardır. Birinci düzey VAD'nin en önemli özelliği uygulamadaki bütün işlemlerin burada tanımlanmasıdır. <!-- BELİRSİZ: birinci düzey hasta-sigorta VAD'sinin karesi yok; ayrıntı altyazıdan. -->

İkinci düzey ayrıntılı VAD, birinci düzeydeki her işlemi (ayrıntısı olanları) alt işlemleriyle gösterir. İşlem başka işlemlerden girdi alıyorsa bunlar da gösterilmelidir. Slayttaki örnek 2.0 işleminin açılımıdır (ekrandan, 01:35:00):

```text
2.0 içinde:
  2.1 Hastanın Sigorta Durumunun İncelenmesi
  2.2 Listelenen Miktarla Faturayı Kıyaslama
  2.3 Hastanın Ödemesi Gereken Tutarın Faturalanması

Hasta -> 2.1 : Sigorta Formu
1.0 Muayene Kaydı İnceleme ve Ücret Hesabı -> 2.1 : Doğrulanmış Ücret
2.1 -> 2.2 : Sigorta ve Ücret Bilgisi
D3 Sigorta Şirketleri -> 2.2 : Sigorta Şirketi Adı ve Adresi
2.2 -> Sigorta Şirketi : Sigorta Faturası
2.2 -> 2.3 : Hastanın Ödemesi Gereken Tutar
D2 Hastalar -> 2.3 : Hasta Adresi
2.3 -> Hasta (tekrar çizilmiş, işaretli) : Hasta Faturası
```

Burada 1.0 işleminden gelen girdi ve D2, D3 veri depoları da gösterilmiştir; tekrar çizilen Hasta varlığının köşesindeki çizgi ikinci kullanımı belirtir.

## Örnek Sorular

**Soru 1** (derste sözlü, 01:29:03): Örnek birinci seviye diyagram üzerinden VAD kurallarını sayabilir misiniz?

> **Çözüm (derste verildi):** Varlıktan varlığa doğrudan veri akmaz; varlık ile veri saklama ortamı arasında ve iki veri saklama ortamı arasında doğrudan veri akmaz, arada mutlaka bir işlem bulunur. İşlemden işleme veri akabilir. Tekrar çizilen varlık işaretlenir. Her veri ayrı okla gösterilir. Bağlam diyagramında tek işlem vardır. Bağlam diyagramı ile birinci düzey diyagram tutarlı olmalıdır. "Bir seferde tek işlem" ifadesi yalnız bağlam diyagramı için doğrudur.

**Soru 2** (ekrandan, 01:30:00): "Örnek birinci seviye diyagram"da (Öğrenci, Öğretim Üyeleri; Ders Seç, Sınav sonuçlarını sisteme ekle, Sınav sonucu görüntüle) kural hatası var mı?

> **Çözüm (derste verildi):** Öğrenci varlığı diyagramın sağında ikinci kez çizilmiş, ama ikinci kullanım olduğunu gösteren işaret (köşedeki çizgi) konmamış. Bu hatalıdır; ikinci öğrenci kutusuna "daha önce kullanıldı" işareti eklenmelidir.

**Soru 3** (ekrandan, 00:25:00): Şu use case adaylarından hangisi yararlı hedef seviyesindedir? Negotiate a Supplier Contract, Rent Videos, Log In, Start Up.

> **Çözüm (derste verilmedi):** Larman'ın yaklaşımında yararlı seviye, büyük olasılıkla tek oturumda bir kişinin yaptığı ve ölçülebilir iş değeri üreten "temel iş süreci" (elementary business process) seviyesidir. Buna uyan "Rent Videos"tur. "Negotiate a Supplier Contract" birçok kişi ve günler süren bir iş sürecidir, fazla üst seviyededir. "Log In" ve "Start Up" tek başına iş değeri üretmeyen alt seviye adımlardır; genellikle ayrı use case olarak değil, başka use case'lerin parçası olarak ele alınır.

**Soru 4** (ekrandan, 00:10:00): Alan modelinde `Customer` sınıfına `rentedVideos: List of Video`, `Video` sınıfına `renter : Customer` niteliği yazmak neden "daha kötü", iki sınıfı `Rents` bağlantısıyla bağlamak neden "daha iyi"dir?

> **Çözüm (derste verilmedi):** Alan modeli kavramlar arasındaki ilişkileri görünür kılmak için vardır. Başka bir kavramsal sınıfı gösteren bilgi nitelik olarak gömülürse ilişki diyagramda görünmez, iki yönde tekrar edilir ve çokluluk bilgisi kaybolur. `Customer 1 — Rents — 1..* Video` bağlantısı ilişkiyi tek yerde, adıyla ve çokluluğuyla gösterir. Bu yüzden alan modelinde nitelikler sayı, tarih, metin gibi basit veri türleriyle sınırlı tutulur, sınıflar arası ilişkiler bağlantıyla gösterilir.

**Soru 5** (derste sözlü, 01:05:11): ATM use case diyagramında "Bank" neden canlı aktör (çöp adam) olarak gösterilmiş?

> **Çözüm (derste verildi):** Kitapta bankadaki memurun işi yaptığı düşünülerek çöp adam çizilmiş. Ama para çekme işini bankamatiğin arkasındaki otomatik banka sistemi yapar; bu yüzden canlı olmayan aktör olarak dikdörtgenle gösterilmesi daha uygundur.

## Dersin Toparlaması

Bu derste nesneye yönelik analizin üç adımı izlendi. Önce uygulama alanındaki kavramlar ve aralarındaki bağlantılar, UML sınıf notasyonunu kullanan bir "görsel sözlük" olan alan modeliyle çıkarıldı. Sonra işlevsel gereksinimler use case'lerle yazıldı: use case seviyeleri, aktör ve use case sembolleri, video mağazası ve ATM diyagramları, fully dressed belgenin bölümleri (paydaşlar, ön ve son koşullar, ana akış, uzantılar) ve arayüzü dışarıda tutan temel use case yazımı ele alındı. Türkçe slaytlarda aynı süreç uygulama alanının çözümlenmesi, doğal dilli gereksinim belgesi, 11 adımlı satış işlemi öyküsü ve CRC kartlarıyla sınıflara geçiş olarak tekrarlandı.

Dersin son bölümü klasik ve nesneye yönelik yaklaşım arasındaki temel farkı netleştirdi. Varlıkta yalnız ad ve özellikler vardır ve işlemler VAD'lerde ayrıca gösterilir; nesnede veri ile onu işleyen metotlar birlikte kapsüllenir. Yapısal yaklaşımda veri sözlüğü merkezli modelde ERD, VAD ve durum geçiş diyagramı kullanılır; tasarımda yapı diyagramı ve ERD gelir. Nesneye yönelik yaklaşımda tasarımda sıralama ve sınıf diyagramları kullanılır. VAD kuralları, özellikle varlık ve depolar arasında doğrudan veri akmaması ve tekrar çizilen varlıkların işaretlenmesi, örnek diyagramlar üzerinde yeniden gösterildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
