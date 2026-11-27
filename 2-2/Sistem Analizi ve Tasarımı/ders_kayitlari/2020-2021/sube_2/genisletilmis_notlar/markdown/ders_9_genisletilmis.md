# Ders 9 Genişletilmiş Notu: Sistem Tasarımı: Ön Tasarım, Etkileşim Tasarımı, Yapı Diyagramı ve Etkileşim Diyagramları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Analizden tasarıma geçiş
- 2. Sistem tasarımı bileşenleri
- 3. Tasarım süreci ve tasarım yaklaşımları
- 4. Ön (genel) tasarım: temin seçenekleri ve işlevsel olmayan gereksinimler
- 5. Sistem mimari modellemesi
- 6. Altyapı belirleme
- 7. Çıktı tasarımı
- 8. Girdi tasarımı
- 9. Ekran ve kullanıcı arabirimi tasarımı
- 10. Sistem (uygulama) mimarisini belirleme: yapı diyagramı
- 11. Tasarım spesifikasyonları
- 12. HIPO
- 13. Nesneye dayalı tasarım modelinin oluşturulması
- 14. Etkileşim diyagramları
- 15. Senaryoların gerçeklenmesi ve sorumluluklar
- 16. GRASP tasarım kalıplarına giriş
- Örnek Sorular

## 1. Analizden tasarıma geçiş

Önceki derslerde problem anlaşılmış ve modellenmişti: kullanım senaryoları, veri akış diyagramları ve veri sözlüğüyle analiz modeli kurulmuştu. Bu derste dersin adının ikinci kısmına, sistem tasarımına geçildi. Hoca tasarımı, analizi yapılan bir sistemin gerçekleştirilmek üzere hazırlandığı ve çözümün ortaya konduğu aşama olarak tanımladı. Özellikle teknik ekip için analizden sonraki en önemli aşamadır. Analizde "problem nedir" sorusu cevaplanırken tasarımda "problem nasıl çözülür" sorusu cevaplanır; tasarımın çıktıları da çözümü anlatan doküman ve diyagramlardır.

Slayttaki yapı şöyledir (ekrandan, 00:10:00):

- Ön Tasarım
  - Alt yapı belirleme
  - Modül mimarisinin oluşturulması
- Ayrıntılı Tasarım
  - Sistem etkileşimi tasarımı
    - Çıktı tasarımı
    - Girdi tasarımı
    - Arabirim tasarımı
  - Program tasarımı
  - Veritabanı tasarımı

Ön tasarımda, gereksinim analizinden önce yapılan olabilirlik (fizibilite) etüdüne geri dönülür: orada önerilen altyapı artık gerçekten seçilir ve temin edilir. Bununla birlikte yazılımın modüllere nasıl bölüneceği belirlenir. Ayrıntılı tasarımda sistemin çıktıları, girdileri ve ara birimleri tasarlanır; program tasarımı yazılımın mimari tasarımını, veritabanı tasarımı da veri modelinin tasarımını kapsar. Veritabanı tasarımı sonraki derse bırakıldı.

## 2. Sistem tasarımı bileşenleri

Hoca sistemi oluşturan parçaları bir resim üzerinden gösterdi (ekrandan, 00:15:00). Resimde bir ağ omurgasına uygulama sunucusu, veritabanı sunucusu ve iki ofis bilgisayarı bağlıdır; internet ve başka sistemler bir güvenlik duvarının arkasından bu ağa ulaşır. Her parçanın yanında, o parçayı hangi tasarımın tanımladığı yazar:

| Parça | Tasarım | Tanımladığı şey |
|---|---|---|
| Uygulama sunucusu | Uygulama tasarımı | Bilgisayar programlarını |
| Veritabanı sunucusu | Veritabanı tasarımı | Veritabanının yapısını |
| Ofis bilgisayarı | Kullanıcı arayüz tasarımı | Ekranları, raporları, girdi/çıktı kontrollerini |
| Başka sistemler | Sistem arayüz tasarımı | Diğer sistemlerle haberleşmeyi |
| Internet bağlantısı | Güvenlik ve kontrol tasarımı | Güvenlik duvarını |

Uygulama tasarımı yazılımın ve programların nasıl olacağını, veritabanı tasarımı verinin nerede ve hangi yapıda duracağını belirler. Kullanıcı arayüz tasarımı kullanıcıyla etkileşilen bütün noktaları (girdilerin alındığı ve çıktıların verildiği ekranlar, raporlar, kontroller) kapsar. Sistem arayüz tasarımı başka sistemlerle haberleşmeyi tanımlar: hoca güncel örnek olarak web servislerini ve REST API'lerdeki istek-yanıt yapılarını verdi. Hangi verinin hangi formatta gideceği, servisin ne istediği ve ne döndürdüğü burada tasarlanır.

Güvenlik ve kontrol tasarımı bilgi sisteminin güvenliğinin nasıl sağlanacağını, yetkilendirme ve erişim kontrollerini, yani kimin hangi veriye ve hangi uygulama parçasına ne kadar erişebileceğini belirler. Hoca bu konuya ders kapsamında girilmeyeceğini, ama günümüz bilgi sistemlerinde mutlaka ele alınması gerektiğini söyledi. Özetle sistem "duvarın arkasındaki" kısımdır ve bu kısımdaki arayüzler, girdiler, çıktılar, uygulama ve veri tasarlanmalıdır.

## 3. Tasarım süreci ve tasarım yaklaşımları

### 3.1 Tasarım süreci

Gereksinim analizinden gelen girdilerle önce sistemin nasıl çalışacağı ortaya konur: veri yapıları, modüller ve kısıtlar tanımlanır ve bir ön tasarım raporu yazılır. Rapor incelenir; ya revizyona gider ya kabul edilir. Bu raporda fizibilitede seçilen şeylerin değişip değişmediği ve neden değiştiği de yazılır. Ön tasarım raporu ayrıntılı tasarımı besler. Gereksinim spesifikasyonu yazıldığı gibi tasarım için de bir tasarım spesifikasyonu yazılır; inceleme ve revizyonlardan sonra kabul edilir ve sistem tasarım raporları üretilir. Böylece problem anlaşılmış, modellenmiş ve çözüm önerisi fiziksel olarak gerçekleştirmeye hazır biçimde yazılmış ya da çizilmiş olur.

### 3.2 Tasarım yaklaşımları

Hoca sistem tasarımında birkaç farklı yaklaşım olduğunu "bilginiz olsun" diye anlattı:

- **Model güdümlü yaklaşım (Model Driven Architecture):** Geliştirilen mantıksal analiz modelleri kullanılarak tasarım modelleri oluşturulur. Alternatif tasarımlar üretilir ve bunların arasından uygun olanı seçilir.
- **Hızlı uygulama geliştirme (Rapid Application Development, RAD):** Prototipleme esastır; hoca spiral modele benzetti. Bir tasarım modeli hazırlanır, prototipi yapılır, prototip iyileştirilip yeni bir model olur, ondan yeni bir prototip çıkar. Böylece bir çekirdek modülden başlanıp bütün modüller kapsanana kadar tasarım iyileştirilerek ilerler.
- **Ortak uygulama geliştirme (Joint Application Development, JAD):** Bütün paydaşların katıldığı bir atölye ya da seminer çalışması yapılır. Hocanın benzetmesiyle herkes bir salonda masaların başına oturur (modüller ayrı masalarda olabilir ya da herkes büyük bir masayı paylaşabilir). Analiz modeli temel alınarak herkes önerisini söyler ve beyin fırtınası şeklindeki tartışmalarla ortak bir çözüm belirlenir. Büyük ve karmaşık, bir modülün başka bir modülü nasıl etkilediğinin normalde görülemeyeceği projelerde yararlıdır.

Hoca bu yaklaşımların zorunlu olmadığını, tek bir çözüm önerisi üretip onunla ilerlemenin de bir yol olduğunu söyledi. Daha kötüsü ise hiçbir şey tasarlamadan doğrudan kodlamaya geçmektir. Bu mimariye "Big Ball of Mud" (büyük çamur topu) denir: yazılım giderek spagetti koda dönüşür, sürekli günü kurtararak bir yere kadar gidilir, ama temeli olmadığı için çözüm sonunda çöker.

## 4. Ön (genel) tasarım: temin seçenekleri ve işlevsel olmayan gereksinimler

Slayttaki içerik (ekrandan, 00:20:00):

- Sistem nasıl temin edilecek?
  - Sistem sıfırdan oluşturulabilir: Kurum içi geliştirme +/-?
  - Satın alınıp ihtiyaca göre özelleştirilebilir +/-?
  - Dışarıdan (hizmet olarak) temin edilebilir +/-?
- İşlevsel olmayan gereksinimler mimari tasarımı etkiler
  - Sistem ne kadar hızlı çalışacak? Kapasitesi ne olacak? Şifreleme ve virüs kontrol ihtiyacı var mı? Vb.
  - Yeni sistemi desteklemek üzere alınacak donanım ve yazılımlara yönelik mimari kararlar

### 4.1 Sistem nasıl temin edilecek?

Ön tasarımda ilk karar, sistemde kullanılacak bileşenlerin nasıl alınacağı ve kurulacağıdır. Hoca bir öğrencinin aklına gelebilecek soruyu da kendisi sordu: "Bunu niye şimdi soruyoruz, fizibilitede zaten konuşmamış mıydık?" Cevap şudur: "Kendimiz mi yapalım, birine mi yaptıralım, hazır alıp değiştirelim mi?" sorusu ancak problem görüldükten, modellendikten ve analiz edildikten sonra sağlıklı cevaplanabilir. Bu yüzden kesin karar tasarımın başında verilir.

- **Kurum içi geliştirme.** Artısı, ürünün ve bütün bilgi birikiminin kuruma ait olması ve çözümün kurumun ihtiyaçlarına tamamen özelleştirilmesidir. Eksisi uzun sürebilmesidir; ekip başka işlerle de uğraştığı için süre daha da uzayabilir ya da başka işler sekteye uğrayabilir. Deneyim eksikliği varsa eğitim gibi ek maliyet ve zaman gerekir.
- **Hazır sistem satın alıp özelleştirme.** Para verilir, sistem alınır, kurulur, biraz özelleştirilir (customize edilir) ve kullanılır. Artısı hızlı olmasıdır. Eksisi tam olarak kuruma uymayabilmesidir; özelleştirme için o kadar emek harcanabilir ki "bu kadar uğraşacağımıza kendimiz yazardık" denebilir.
- **Dışarıdan hizmet olarak alma (outsource).** Artısı riskin karşı tarafa geçmesi ve sonuç garantili, olmazsa tazminat gibi maddeler içeren bir anlaşmayla işin bağlanmasıdır. Ancak karşı taraf riski fiyatlandırır. Hocanın örneğinde kurum içinde 15 adam-ay sürecek bir iş için hizmet veren firma 10 adam-ayı risk sigortası olarak ekleyip 25 adam-ay fatura çıkarabilir (ya da adam-ay birim maliyetini yüksek tutabilir). Eksileri: ürün kurumun değildir, istenildiği gibi olmayabilir, firma analiz modelini doğru anlamayabilir. Anlaşmaya bağlı olarak kaynak kodlar firmanın mülkiyetinde kalırsa ileride değişiklik ve bakımda sıkıntı yaşanabilir.

Bu artı ve eksiler tartılarak "yazalım mı, satın mı alalım, outsource mu edelim" sorusu genel tasarımda çözülür.

### 4.2 İşlevsel olmayan gereksinimler mimariyi belirler

> **Hocanın vurgusu:** Tasarımda çözülen en önemli problem işlevsel olmayan gereksinimlerdir (non-functional requirements). Yazılımın temel mimarisini oluşturan kabuller ve kararlar tamamen işlevsel olmayan gereksinimleri karşılamak içindir.

Hoca, ilerleyen bölümlerde yapı diyagramları, ardışıl ve aktivite diyagramları ve tasarım sınıf diyagramı gibi araçlarla işlevsel gereksinimlerin nasıl karşılanacağının zaten gösterileceğini söyledi. Ama mimariyi belirleyen şey başkadır. Bunu bir öğrenci bilgi sistemi örneğiyle açıkladı:

- İlk akla gelen çözüm, sistemi tek bir güçlü sunucuda (örneğin çift işlemcili, 32 GB RAM'li, iki gigabit ethernet bağlantılı) tutmak ve belli sayıda tabloyu, saniyede belli sayıda işlemi desteklemesini istemek olabilir.
- Biri "sistem eş zamanlı olarak 10.000 kullanıcıya en fazla 1 saniye bekleme süresiyle hizmet verecektir" derse tek sunucu önerisi bir anda çöker. Bu gereksinimi karşılamak için dağıtık bir mimariye, yani birden fazla uygulama sunucusuna geçmek gerekir.
- Burada maliyet devreye girer: sunucu başına 10.000 dolardan yükü kaldırmak için 5 sunucu, yani 50.000 dolarlık yatırım gerekir. Ama yük yalnız ders kayıt ve ders seçim dönemlerinde oluşur; dönem içinde yük yok denecek kadar azdır. Hocanın ifadesiyle 50.000 dolarlık yatırımın 45.000 dolarlık kısmı boşa çalışır.
- O zaman "yük olduğunda karşılansın" diye yeni bir işlevsel olmayan gereksinim gelir. Bu, veri akış diyagramında görünmez ama çözülmesi gerekir. Bir çözüm konteyner mimarisidir: yük arttığında yeni konteynerler ayağa kaldırılır. Bu, tamamen farklı bir fiziksel tasarımdır. Konteynerlerin orkestrasyonu ayrı bir iştir.
- Yeni bir konteyner ayağa kalkarken bile birkaç saniyelik gecikme olur; bu sırada hizmet alamayan kullanıcılar olabilir. Bu da sunucusuz (serverless) mimariye götürür: sürekli çalışan örnekler yerine yalnız fonksiyonlar (use case karşılıkları) ihtiyaca göre çalıştırılır ve bunu bir yönetim katmanı belirler.

Benzer biçimde "bu işlem şu kadar saniyede tamamlansın" ya da "bu rapor en fazla şu kadar bellekte oluşsun" gibi gereksinimler de mimari çözümü etkiler. Hoca, derste tasarımın yalnız işlevsel gereksinimleri karşılayacak kadarının görüleceğini, bunun buzdağının görünen kısmı olduğunu, görünmeyen kısımda gerçek fiziksel tasarımı etkileyen pek çok sorun bulunduğunu söyledi.

> **Ek bilgi (derste anlatılmadı):** Konteyner orkestrasyonunda büyük olasılıkla en yaygın araç Kubernetes'tir; serverless mimarinin bilinen örnekleri arasında bulut sağlayıcıların fonksiyon servisleri (örneğin AWS Lambda) vardır. Serverless yaklaşımda da büyük olasılıkla ilk çağrıda "soğuk başlangıç" gecikmesi görülebilir, yani gecikme sorunu tamamen ortadan kalkmaz.

## 5. Sistem mimari modellemesi

Slayttaki sorular (ekrandan, 00:30:00):

- Bilgi sistemi, merkezi mi yoksa dağıtık mı olacak? (Birçok sistem, ağ üzerinden dağıtık çalışmaktadır.)
- Bir ağ üzerinden depolanan verinin dağıtımı nasıl olacak? (Birçok modern veritabanı, dağıtık ya da ağ üzerinde çok kopyalı olarak bulunabilmektedir.)
- Geliştirilecek yazılım için uygulama teknolojileri ne olacak? Hangi programlama dili ve araçları kullanılacaktır?
- Satın alınabilen ticari yazılımların bütünleştirilmesi nasıl olacak? (Ticari yazılımın gereksinimlere göre düzenlenme ihtiyacı vardır.)
- Kullanıcı arayüz uygulamasında kullanılacak teknolojiler neler olacaktır?
- Diğer sistemlerle arayüz oluşturmak için kullanılacak teknolojiler neler olacaktır?

Hoca bugün sistemlerin "dağıtığın da dağıtığı" haline geldiğini ve serverless mimariye doğru gidildiğini söyledi. Veri dağıtık duruyorsa eş zamanlılığın ve veri tutarlılığının nasıl sağlanacağı çözülmelidir. Hangi dillerin, araçların, kütüphanelerin, API'lerin ve SDK'ların kullanılacağı ve neden kullanılacağı da tasarımda belirlenir.

Buna göre mimari tasarım hem yazılım hem donanım bileşenlerini kapsar:

- Yazılım bileşenleri: verinin nasıl depolanacağı ve ona nasıl erişileceği, uygulama mantığının (application logic) nasıl kurgulanacağı ve sunum katmanının (kullanıcı etkileşimi, hem girdi hem çıktı) nasıl olacağı.
- Donanım bileşenleri: istemcilerin, sunucuların ve iletişimin nasıl olacağı.

## 6. Altyapı belirleme

Hoca bu bölümü hızlı geçeceğini, ama bilinmesi gerektiğini söyledi. Fizibilitede ortaya konan ihtiyaçlar artık fiziksel olarak gerçekleştirileceği için altyapı belirlenir. Adımlar şunlardır: elde ne olduğuna bakmak (mevcut donanım ve yazılım envanteri), sistemin getireceği iş yükünü belirlemek, mevcut donanım ve yazılımın bu yükü ne kadar karşıladığını değerlendirmek, satıcıları karşılaştırmak ve satın alma şekline karar vermek.

### 6.1 Envanter ve iş yükü

Envanter belirlemede mevcut donanım çıkarılır ve fizibilitede "gerekli altyapı şudur" diye önerilen çözümle karşılaştırılır. Sonuçta mevcut altyapının yetip yetmediği, neyin değişmesi ya da güncellenmesi gerektiği raporlanır. İş yükü değerlendirmesinde donanımın kapasitesinin yeterli olup olmadığı, zaman ve maliyet açısından ne kadar süre idare edeceği test edilip karşılaştırılır; amaç gereksiz bir sistem kurulumunu engellemektir.

Hoca örnek bir iş yükü matrisi gösterdi. Matriste yapılan iş, yöntem, personel, maliyet, zamanlama (günlük, aylık), gerekli insan gücü ve gerekli bilgisayar gücü için mevcut ve önerilen değerler yer alır. Bunlardan bütün gereksinimler için ne kadar bilgisayar gücüne ve insan gücüne ihtiyaç olduğu ve eldekilerin bunun ne kadarını karşıladığı tahmin edilir. Özetle yalnız gerektiği kadarı yenilenir. <!-- BELİRSİZ: iş yükü matrisinin karesi yok; sütunlar altyazıdan alındı -->

### 6.2 Donanım değerlendirme

Slayttaki içerik (ekrandan, 00:35:00):

- İş yükü ve mevcut envantere göre proje ihtiyaçları belirlenir.
- İş yüklerinin farklı sistemlerde simülasyonu yapılarak karşılaştırılır.
- Karşılaştırma kriterleri:
  - İşlemin gerçekleşmesi için geçen ortalama süre (Bu süreye giriş verisinin sisteme girilmesi ve çıkışı elde etme de dahildir.)
  - Sistemin toplam kapasitesi (Herhangi bir problem oluşmadan aynı zamanda kaç işlem gerçekleştirildiği.)
  - CPU'nun atıl zamanı
  - Önerilen belleğin büyüklüğü

Hoca, yenilenecek sistem ortalama sürede kayda değer bir iyileşme sağlamıyorsa yeni bir satın alma yapılmaması gerektiğini söyledi. Kapasiteye örnek olarak sistemin saniyede 10.000 kullanıcıya mı yoksa yalnız 1.000 kullanıcıya ya da 1.000 kayıt işlemine mi hizmet verebildiği soruldu.

### 6.3 Yazılım değerlendirme

Mevcut ya da paket olarak alınabilecek yazılımlar altı başlıkta değerlendirilir: performans (ihtiyaç duyulan işleri ne kadar yerine getirdiği, kapasitesi, yanıt süresi), verimlilik (throughput; veriyi ve yedeklemeyi ne kadar verimli yönettiği), kullanım kolaylığı, esneklik, dokümantasyon ve üreticinin verdiği destek. Hoca bu kriterlerin kesin olmadığını, duruma göre değişebileceğini, ama hazır parçalar kullanılacaksa bu başlıklarla karar verilebileceğini söyledi.

### 6.4 Satıcı firmayı belirleme

Yeni donanım ya da yazılım alınacaksa satıcı firma şu açılardan değerlendirilir: donanım desteği, yazılım desteği, kurulum ve eğitim olanakları (kurulum, devreye alma ve sonrasında kullanım eğitimi) ve bakım hizmetleri (örneğin acil durumlarda yanıt süresi). Hoca, bir ürün kalite ve ihtiyaçları karşılama açısından iyi olsa bile müşteri hizmetleri kötüyse ya da acil durumlarda ancak 24 saat sonra yanıt veriliyorsa bunun da karşılaştırmaya girmesi gerektiğini söyledi.

### 6.5 Satın alma şeklini belirleme

Slayttaki tablo (ekrandan, 00:40:00):

| Şekil | Avantajları | Dezavantajları |
|---|---|---|
| Satın alma | Uzun dönemde leasing ve kiralamadan ucuz olması; sistemin değiştirilebilmesi; vergi indirimi sağlaması; tam kontrol | İlk ödemenin yüksek olması; eskime riski; seçimin yanlış yapılması sonucu yatırımın batma riski; tam sorumluluk |
| Leasing | Sermayenin bağlanmaması; finansmana ihtiyaç olmaması; kira bedelinden düşük olması | Sözleşme bittiğinde işletmenin sisteme sahip olamaması; ödemenin gecikmesi durumunda yüksek faiz oranı; satın almadan daha pahalı olması |
| Kiralama | Sermayenin bağlanmaması; finansmana ihtiyaç duyulmaması; sistemin kolayca değiştirilmesi; genelde bakım ve garantinin fiyat kapsamında olması | İşletmenin sistemin gerçek sahibi olmaması; satıcı kendi riskini üstlendiği için kira bedelinin çok yüksek olması |

**Satın alma.** Bir sunucu satın alındığında tamamen kurumun olur ve kuruma ayrılmıştır (dedicated). Ama yüksek bir bedel ödenir ve sunucu hızla eskiyip güncelliğini kaybedebilir.

**Leasing (finansal kiralama).** Banka ürünü alır ve kuruma kullandırır; kurum belli bir süre ödeme yapar ve sonunda ürün kurumun olur. Sermaye bağlanmaz ve kiralamadan daha düşük bir bedele gelir. Hoca slayttaki "sözleşme bittiğinde işletmenin sisteme sahip olamaması" maddesinin yanlış yazıldığını, doğrusunun "sözleşme bitene kadar sahip olamaması" olduğunu söyledi. Ödeme yapılamazsa yüksek faiz ve sistemin tamamen elden gitmesi riski vardır. Genel olarak satın almadan biraz daha pahalıdır; banka kredisiyle almaya benzer. Örneğin 3 yıl sonra sunucu kurumun olur, ama o zamana kadar büyük olasılıkla eskimiştir. Satın alma ile leasing arasındaki seçim tamamen kurumun finansal durumuna bağlıdır.

**Kiralama.** Sermaye bağlanmaz, istenildiğinde çıkılabilir ve bakım ile garantiler (örneğin çalışma süresi, uptime garantisi) genelde fiyata dahildir. Dezavantajı, kurumun hiçbir zaman sahip olmaması ve satıcı riski üstlendiği için kira bedelinin yüksek olmasıdır. Hocanın sayısal örneği:

- Verilen: 12.000 dolarlık bir sunucu, 12 ay kullanım, kiralama bedeli aylık yaklaşık 1.500 dolar.
- Satın almanın aylık karşılığı: $12000 / 12 = 1000$ dolar.
- Kiralamanın fazlası: $(1500 - 1000) / 1000 = 0{,}5$, yani yaklaşık %50 fazla.
- Karşılığında tek seferde büyük bir ödeme yapılmaz, ihtiyaç bitince bırakılır ve arıza riski kurumda kalmaz.

Hoca bu kararda net bir doğru olmadığını, duruma göre verilmesi gereken bir karar olduğunu söyledi. Özetle ön tasarımda fizibilite gerçekleştirilir: eldekilerin ne kadarının kullanılabileceği tartılır, gerekiyorsa bir kısmı ya da tamamı yenilenir, yazılım ve donanım değerlendirilir, satıcı seçilir ve satın alma şekline karar verilir.

## 7. Çıktı tasarımı

Ayrıntılı tasarıma girdi, çıktı ve arabirim tasarımıyla başlandı; hoca tersten, çıktıdan başladı. Slayttaki içerik (ekrandan, 00:45:00):

- Çıktı: Sistemin kullanıcılara verdiği bilgi, üretilen raporlar
- Amaçlar:
  - Belirlenen amaca hizmet etme
  - Kullanıcı için anlamlı olma
  - Uygun sayıda olma
  - Hangi kullanıcılara dağıtılacağının doğru belirlenmesi
  - Zamanında sağlanma (günlük, aylık, yıllık veya koşula bağlı raporlar)
  - Doğru çıktı yönteminin (ortamının) seçilmesi
- Kullanıcıyı etkileyecek yönlendirme:
  - Bilgilerin belirli kriterlere göre sıralanması
  - Sınırların belirlenmesi
  - Grafik tipi, rengi, ölçeğinin belirlenmesi

Sistem çalıştıkça bilgi ve rapor üretir ve bunları kullanıcılara sunar; bunlara çıktı denir. Hangi raporun kime gideceği doğru planlanmalı, raporlama zamanı (anlık, günlük, aylık, yıllık ya da koşula bağlı) doğru seçilmelidir. Çıktının kağıda mı, ekrana mı, grafik olarak mı verileceği de belirlenmelidir. Hoca yönlendirmeye örnek olarak kullanıcının rapor ekranında sütun başlığına tıklayıp tarihe, isme ya da başka bir alana göre sıralayabilmesini verdi. Gerekirse sınır değerler belirlenip uç değerler kesilebilir. Grafiklerde renkler, eksenlerin neyi ifade ettiği ve ölçeğin logaritmik mi doğrusal mı olacağı düzgün belirlenmelidir.

## 8. Girdi tasarımı

Hoca girdiyi "çöp girerse çöp çıkar" (garbage in, garbage out) ilkesiyle açıkladı: kaliteli çıktı üretmek için kaliteli girdi almak gerekir. Girdi bir kullanıcıdan (form ekranı, mobil ya da tablet arayüzü) ya da başka bir sistemden gelebilir. Girdi tasarımında dikkat edilecekler:

- **Amaç:** Formların ve ekranların belli bir amacı olmalı; veriler belirli bir mantık çerçevesinde, bir bütün halinde istenmelidir.
- **Doğruluk:** Analizde tanımlanan işlemleri yerine getirmek için gereken bütün veriler kullanıcıdan alınabilmelidir; eksik bir şey kalmamalıdır.
- **Ergonomi:** Kullanıcı verileri fazla zaman harcamadan sağlayabilmelidir; örneğin kopyala-yapıştıra izin verilmelidir.
- **Uyumluluk:** Bir formdan diğerine ya da bir ekrandan başka bir ekrana geçerken düzen sürekli değişmemeli, kullanıcı görmeyi beklediği düzenle karşılaşmalıdır.
- **Basitlik ve görünüş:** Karmaşık olmamalı, gereksiz ayrıntı içermemeli, düzgün ve güzel görünmelidir.

Hoca eskiden girdi ve çıktı tasarımının büyük bir problem olduğunu, Oracle Forms gibi araçlarla standartlaşmaya başladığını anlattı. Bugün etkileşim noktaları (web, mobil, tablet, kiosk, gömülü sistem arayüzü) bağımsız hale geldi ve Angular, React, Vue gibi JavaScript kütüphaneleri bu kuralların çoğunu standart olarak sunuyor; hoca Bootstrap'in artık eski kaldığını da ekledi. Endüstri standardı olan bu hazır çözümlerin kullanılmasını her zaman tavsiye ettiğini söyledi.

### 8.1 Girdi tasarımı prensipleri

Slayttaki içerik (ekrandan, 00:50:00):

- Çevrimiçi işleme ve toplu işleme girdileri uygun olarak kullanılır
- Veri, kaynağında tutulur
- Klavye tuşlamaları azaltılır
- Doğrulama ve geçerleme yapılır
  - Tamlık, Biçim, Aralık, Tutarlılık

Kullanıcı bir formdan kayıtları tek tek girebilmeli, ama isterse örneğin bir Excel dosyasından toplu yükleme (bulk input, import) de yapabilmelidir. Klavye kullanımı azaltılmalıdır: kullanıcı bütün kelimeyi yazmak zorunda kalmamalı, ilk iki üç harften sonra öneri sunulmalıdır. Girdiler olabildiğince az tıklama ve tuşlamayla verilebilmelidir.

> **Hocanın vurgusu:** Kullanıcıya hiçbir zaman güvenmeyin; aldığınız bütün girdileri doğrulayın ve geçerleyin (hem validation hem verification).

Kontrol türleri şunlardır:

- **Tamlık:** Veri tam mı, eksik alan var mı?
- **Biçim:** Örneğin bir tarih doğru formatta girildi mi?
- **Aralık:** Değer geçerli aralıkta mı? Yaş alanına -57 girilememelidir.
- **Tutarlılık:** Alanlar birbiriyle tutarlı mı? Hocanın "en beylik" dediği örnek: kullanıcıdan doğum tarihi ve evlilik tarihi alınır. Evlilik tarihinin doğum tarihinden en az 18 yıl (özel durumlarla 15 yıl) sonra olması beklenir. Doğum yılı 2000, evlilik yılı 2005 ya da 2010 girilmişse bir tutarsızlık vardır ve sistem bunu yakalamalıdır.

> **Ek bilgi (derste anlatılmadı):** Yazılım mühendisliğinde "verification" büyük olasılıkla en yaygın kullanımıyla "ürünü doğru mu yapıyoruz" (belirtime uygunluk), "validation" ise "doğru ürünü mü yapıyoruz" (gerçek ihtiyaca uygunluk) diye ayrılır. Girdi denetimi bağlamında ise iki terim çoğu zaman girdinin biçimsel ve anlamsal olarak kontrol edilmesi için birlikte kullanılır.

## 9. Ekran ve kullanıcı arabirimi tasarımı

Ekranlarda dikkat edilecekler: kolay kullanım, gereksiz bilgi olmaması, gerektiğinde açıklama sunulması, formlar ve ekranlar arasında uyumluluk (hepsinde aynı tema), fareyle ve klavyeyle ekranlar ve sütunlar arasında kolay gezinti, belirli bir düzen ve çekici bir görünüm (yazı tiplerinin her ekranda farklı olmaması). Hoca bugün görselleştirme kütüphaneleri ve CSS temelli çözümler sayesinde ekran tutarlılığının büyük ölçüde çözüldüğünü söyledi.

Kullanıcı arabirimleri yalnız girdi ve çıktı ortamlarından ibaret değildir. Doğal dil arabirimi, soru-cevap ya da sorgu arabirimi, menüler, formlar, kullanıcının komut verdiği kendine özgü bir betik (script) dili ya da bildirim alıp verme arabirimi olabilir. Bunların hepsi amaçlarına uygun olarak, etkinlik ve verimlilik gözetilerek tasarlanmalıdır. Özetle kullanıcıya dokunulan her noktada benzer tasarım kriterleri uygulanmalıdır.

### 9.1 Ekran yerleşimi

Hoca ekranda çizerek tipik bir yerleşim gösterdi (web arayüzü, monitör ya da kiosk için; mobilde biraz farklılaşır). Ekran genellikle şu bölgelere ayrılır:

```text
+-----------------------------------------------+
|  Gezinti bölgesi (menü, araç kutuları)        |
+-----------+-----------------------------------+
| İç        |                                   |
| gezinti / |  Kullanıcının sistemle etkileşime |
| modül     |  geçtiği ana alan                 |
| seçimi    |                                   |
+-----------+-----------------------------------+
|  Durum bilgisi alanı (status bar)             |
+-----------------------------------------------+
```

Sol taraftaki iç gezinti alanı üst menüyle birlikte ya da onun yerine kullanılabilir. Hoca pek çok uygulamanın ve web sitesinin de bu düzende tasarlandığını, bu yerleşimin daha iyi bir kullanıcı deneyimi sağladığını söyledi. <!-- BELİRSİZ: çizimin karesi yok; yerleşim altyazıdaki anlatımdan kuruldu -->

### 9.2 Arabirim tasarım problemleri

Slayttaki içerik (ekrandan, 00:55:00):

- Bilginin düzensiz görünümde yığınlar şeklinde olması
- Kullanıcının yürütmesi gereken çeşitli görevler arasındaki geçişin uyumlu olmaması
- Ekran üzerindeki komutlarda kullanılan terminolojinin karmaşık olması
- Sistem tarafından verilen hata mesajlarının açıklayıcı olmaması
- El kitaplarının anlaşılmaz derecede karmaşık olması

> **Hocanın vurgusu:** Hata mesajları açıklayıcı olmalıdır. "Hata oluştu" ya da "bilinmeyen hata oluştu" yerine "dosyanın adını yanlış girdiniz" ya da "dosya adını boş geçtiniz" gibi nedeni söyleyen mesajlar verilmelidir.

## 10. Sistem (uygulama) mimarisini belirleme: yapı diyagramı

Aradan sonra ayrıntılı tasarım kapsamında uygulamanın mimarisine geçildi. Slayttaki içerik (ekrandan, 01:05:00):

- Modüler program yapısı geliştirilir.
- Aralarındaki ilişkilerin denetimi belirlenir.
- Veri yapısı ve program birleştirilir, ara birimler tanımlanır.
- VAD ve veri sözlüğüne dayanan yapı diyagramı ile gösterilir.
  - Modüller: Anlaşılması ve bakımı kolay olan, mantıksal program işlem birimleri
  - Veri iletişimi: Modüller arası iletilen veri
  - Kontrol mesajları: Modüller arasında bir durumu ya da hareketi başka modüle aktarma mesajı (örneğin: dosya sonu)
  - Durumlar: Kontrol Modülünün hangi alt modülü çağıracağının gösterimi
  - Döngüler: Bir veya daha fazla tekrar eden alt modül işlemesinin gösterimi

Bu aşamada yapılan iş modüler çözümlemedir: modüler program yapısı, modüller arasındaki ilişkiler ve kontrol akışı belirlenir. Bu tasarım çok basit bir diyagram olan yapı diyagramıyla (structure chart) gösterilir.

### 10.1 Modüller

Üstteki modüle kontrol modülü denir; altındaki modüllere bağlıdır. Hocanın örneğinde bir kayıt işlemi modülünün altında zorunlu ders kaydı ve seçimlik ders kaydı gibi alt modüller olabilir. Ayrıca hazır bir paket, API, SDK ya da belli bir algoritmayı çözen hazır bir modül kullanılıyorsa bu bir kütüphane modülüdür ve kutunun iki yanına birer dikey çizgi çizilerek gösterilir.

### 10.2 Veri iletişimi ve kontrol mesajları

Slayttaki diyagram (ekrandan, 01:10:00):

```text
                    [Maintain Customer Data]
                     /                    \
   Customer Number o->                     o-> Customer Charges
   <-o Customer Status                     <-● Account Overdue
                   /                          \
     [Check Customer Status]          [Update Customer File]
```

- "Maintain Customer Data" (müşteri verisinin bakımı) kontrol modülü, "Check Customer Status" modülüne çalışması için "Customer Number" (müşteri numarası) verisini gönderir. Bu, içi boş halkalı bir okla gösterilir ve üzerine verinin adı yazılır. Hoca bunu fonksiyon parametresine benzetti.
- "Check Customer Status" geri dönüş değeri olarak "Customer Status" (müşterinin durumu) verisini gönderir; bu da içi boş halkalı oktur.
- "Update Customer File" (müşteri dosyasını güncelle) modülünü çağırmak için müşteriye fatura edilen tutarlar ("Customer Charges") veri olarak gönderilmelidir.
- "Update Customer File" bir kontrol mesajı döndürür: "Account Overdue" (hesap doldu, yani ödeyebilecek bakiyesi kalmadı). Kontrol mesajının farkı halkanın içinin dolu olmasıdır. Slaytta bu yapı "Control Couple" olarak etiketlenmiştir.

Diyagramda bütün veriler değil, çalışma ve kontrol açısından en önemli ve kritik olanlar gösterilir.

### 10.3 Durumlar ve döngüler

Slayttaki diyagramlar (ekrandan, 01:15:00):

**Durum (koşullu seçim).** "Sort Inventory Parts" (envanterdeki parçaları sırala) kontrol modülünün altında bir eşkenar dörtgen vardır ve buradan üç alt modüle ok çıkar: "Sort By Part Name", "Sort By Part Number", "Sort By Inventory Value". Eşkenar dörtgen, bu üç alt modülden yalnız birinin, kontrol modülünde verilen karara göre çalışacağını gösterir: ya isme göre, ya parça numarasına göre, ya da envanter değerine göre sıralanır.

**Döngü.** "Produce Grade Reports" (not raporlarını üret) modülünün altında, ilk iki alt modülü kapsayan kavisli bir ok vardır. Slayttaki not: "The curved arrow indicates that these modules are repeated." Akış şöyledir:

- "Get Student Grades": kontrol modülü "Student Number" gönderir; modül "Grades" verisini ve kayıtlar bitince "End of File" kontrol mesajını (içi dolu halka) döndürür.
- "Calculate GPA": kontrol modülü "Grades" gönderir; modül "GPA" (ağırlıklı not ortalaması) döndürür.
- Döngü bitince "Produce Grade Report": kontrol modülü "GPA Listing" gönderir; modül "Grade Report" döndürür.

Hoca döngünün soldan sağa okunduğunu söyledi: önce her öğrencinin notları alınır, notlar ortalama hesabına gönderilir ve ortalama geri alınır; dosya sonu gelince döngüden çıkılır. Rapor üretimi kontrol modülünün kendi içinde de yapılabilirdi, ama bu örnekte bağımsız bir alt modüle verilmiştir.

### 10.4 Bordro örneği

Hoca bir ödeme (bordro) modülü örneği de gösterdi. Ödeme oluşturma modülü bir döngü içinde sırasıyla çalışanın ödeme kayıtlarını alır ve doğrular, net ödemeyi hesaplar ve bordroyu basar. Net ödemeyi hesaplayan modül brüt ödemeyi hesaplama, indirimleri hesaplama ve kaydı güncelleme alt modüllerine ayrılır; indirim hesabı da vergi ve sosyal sigorta indirimlerine ayrılır. Her bağlantıda giden ve gelen veriler gösterilmiştir. <!-- BELİRSİZ: bordro yapı diyagramının karesi yok; modül adları altyazıdan alındı -->

### 10.5 Yapı diyagramının VAD ile ilişkisi

Veri akış diyagramındaki süreçler ve özellikle ikinci düzey ayrıntıdaki alt süreçler, onların çalışması için gereken diğer modüllerle birlikte yapı diyagramında kontrol modülleri olarak ortaya çıkar. Süreç tanımlama formuna yazılan sözde kod ve karar tabloları da bu modüllerde gerçeklenir. Yapı diyagramı yazılımın modüllere bölünüşünü ve bu modüllerin çalışması için hangi verilerin ve kontrol mesajlarının gidip gelmesi gerektiğini gösterir.

## 11. Tasarım spesifikasyonları

Tasarım süreci akışında ön tasarım ve ayrıntılı tasarım raporları vardı. Bunlara tasarım spesifikasyonu denir:

- **Ön tasarım spesifikasyonu:** Ön tasarımda yapılanlar, yazılım sisteminin genel özellikleri ve ilişkileri ile yazılım ve donanım seçimlerinin sonuçları raporlanır.
- **Mimari tasarım spesifikasyonu:** Özellikle işlevsel olmayan gereksinimlerin nasıl karşılandığı, yani sistemin yapısı ve kuruluşu için tasarım çözümleri yazılır.
- **Ayrıntılı tasarım spesifikasyonu:** Yazılımın tasarımı, problemin nasıl çözüldüğü yazılır. Yapı diyagramından sonra çizilecekler ve nesneye yönelik çözümlemeler burada yer alır.

## 12. HIPO

Slayttaki içerik (ekrandan, 01:20:00):

- HIPO
- Sistemdeki her fonksiyonun birbiriyle olan ilişkisini belirler.
- Temel fonksiyonlar belirlendikten sonra alt fonksiyonlar tanımlanarak fonksiyon hiyerarşisi oluşturulur.
- Diyagramlar:
  - Görsel içerik tablosu (Visual Table of Contents, VTOC)
  - Genel IPO (Input Process Output) Diyagramı
  - Ayrıntılı IPO Diyagramı

Yapı diyagramındaki her modülün nasıl çalışacağını ayrıntılandırmak için HIPO (Hierarchy plus Input-Process-Output) önerilmiştir. Hoca bunun çok eski olduğunu ve artık pek kullanılmadığını, ama bilinmesi için anlattığını söyledi.

**Görsel içerik tablosu.** Yapı diyagramındaki kırılım ağaç halinde gösterilir. Hocanın örneğinde "envanter güncelleme ve raporlama" kökünün altında envanter güncelleme ve raporlama vardır. Envanter güncelleme işlem girme, doğrulama, düzeltme ve dosya güncelleme; raporlama ise günlük raporlama ve özet raporlama alt fonksiyonlarından oluşur. <!-- BELİRSİZ: VTOC ağacının karesi yok; alt fonksiyon adları altyazıdan alındı -->

**IPO kartı.** Ağaçtaki her kutu için bir girdi-süreç-çıktı tanımı (kart) hazırlanır: modülün çalışması için neler girdiği (veri akışları ayrıntılarıyla), içinde neler yapıldığı (sözde kodun gelişmiş ya da ayrıntılandırılmış hali) ve modülün neler ürettiği ya da döndürdüğü. Bu kartlar ayrıntılı tasarım spesifikasyonunda yer alır.

**Ayrıntılı IPO.** Gerekirse girdilerin nereden geldiği (veritabanı dosyası, ekran, elle giriş), çıktıların nereye gittiği (rapor, ekran, dosya) ve hangi girdinin hangi süreçle ilgili olduğu ayrıntılandırılır.

Özetle süreç şöyledir: yapı diyagramıyla genel modül kırılımı gösterilir, bu kırılım görsel içerik tablosuna dönüştürülür, her alt modül için bir IPO kartı ve gerekirse ayrıntılı IPO kartı hazırlanır. Kaynak, analiz modelindeki veri akış diyagramları ve süreç tanımlama formlarıdır.

> **Hocanın vurgusu:** Bu ders kapsamında HIPO kartlarının hazırlanması beklenmiyor; yapı diyagramını bilmek yeterlidir. Ancak işlevsel dillerle birlikte oluşan yazılım modellemesinin temeli bu şekilde atıldığı için kökleri bilmek gerekir.

## 13. Nesneye dayalı tasarım modelinin oluşturulması

Slayttaki içerik (ekrandan, 01:25:00):

- Problemin mantıksal çözümü oluşturulur.
- YAZILIM SINIFLARI ve aralarındaki İŞBİRLİĞİ (etkileşim) belirlenir.
  - Tasarım Sınıf Diyagramı
  - Etkileşim Diyagramları
- Etkileşim: sınıfların davranışlarının belirlenmesi → sorumlulukların atanması

Nesneye yönelik tasarımda analizdeki kavramsal sınıflar gerçek yazılım sınıflarına, yani kodda "public class ..." diye yazılacak sınıflara dönüştürülür ve bunların arasındaki işbirlikleri ve etkileşimler belirlenir. Bunun için tasarım sınıf diyagramı çizilir; bu genellikle büyük tek bir sınıf diyagramıdır, ama sistem çok büyükse kullanım senaryolarına ya da alt sistemlere göre bölünebilir. Bununla birlikte sınıfların nasıl davrandığını ve sorumluluklarını nasıl yerine getirdiğini gösteren etkileşim diyagramları (interaction diagrams) çizilir.

Hoca, CASE (computer-aided software engineering) araçlarıyla diyagramlar düzgün oluşturulursa pek çok aracın sınıfları, metotları ve parametreleriyle kod şablonunu doğrudan üretebildiğini söyledi. Bu yüzden tasarım iyi yapılıp ifade edildiyse kodlama bugün oldukça kolaylaşmıştır; asıl zor iş tasarımın kendisidir.

Tasarımın girdisi kullanım senaryoları ve gerekiyorsa onları destekleyen kontratlardır (sözleşmeler). Analizde senaryolardaki isimlerin ve fiillerin altı çizilmişti. Fiiller sorumlulukları doğurur: bir şeylerin birileri tarafından yapılması gerekir. Bu sorumluluklar, tasarım kalıpları ve genel tasarım prensipleri ışığında ilgili sınıflara atanır. Yazılım diliyle bu, sınıfların metotlarını belirlemek ve her metodun içinde hangi nesnenin hangi metodunun hangi sırayla çağrılacağına karar vermektir; buna sorumlulukların atanması denir. Hoca tasarım kalıplarının (GoF kalıpları gibi) tek başına bir dönemlik ders konusu olduğunu, bu derste yalnız genel prensiplerin anlatılacağını söyledi.

Sorumluluklar atandıktan sonra ardışıl (sequence) ya da işbirliği (collaboration) diyagramlarıyla ifade edilir. Bütün yazılım sınıfları ortaya çıkınca bunlar aralarındaki ilişkilerle birlikte tasarım sınıf diyagramında (design class diagram, DCD) gösterilir ve uygulamanın tasarımı tamamlanmış olur.

İşlevsel çözümlemeyle karşılaştırırsak: orada modüller yapı diyagramıyla gösterilmiş, her modül için HIPO kartları bir hiyerarşi içinde oluşturulmuştu. Burada ise çözümleme sınıf bazlıdır ve sınıfların birlikte nasıl çalışacağı gösterilir.

## 14. Etkileşim diyagramları

Ardışıl ve işbirliği diyagramları birbirini tümleyen, aynı bilgiyi farklı biçimde gösteren diyagramlardır; ikisine birlikte etkileşim diyagramı denir. Sınıflardan türeyen nesnelerin sorumlulukları yerine getirmek için birlikte nasıl etkileşeceğini, örneğin bir satışta satış kaleminin nasıl yaratılacağını, kimin neyi tetiklemesi gerektiğini gösterirler. Yerine göre biri daha avantajlıdır.

Slayttaki karşılaştırma (ekrandan, 01:30:00):

- İşbirliği Diyagramları
  - Az yer kaplar
  - Dallanma paralellik ve iterasyonlar kolay gösterilir
  - Mesaj sırasını anlamak zor
- Ardışıl Diyagramlar
  - Fazla yer kaplar
  - Mesaj sırasını anlamak kolaydır

İşbirliği diyagramı düzlemde çizilir ve kompakttır. Ardışıl diyagram iki eksende (nesneler yatayda, zaman dikeyde) çizildiği için bu adı alır; daha zahmetlidir, ama kimin kimi hangi sırayla çağırdığı kolayca izlenir.

> **Ders sonrası not:** Hoca bir yerde işbirliği diyagramlarını "interaction" diye andı, sonra kendini düzelterek "collaboration, yani işbirliği diyagramı" dedi. Etkileşim (interaction) diyagramı üst kavramdır; ardışıl ve işbirliği diyagramları onun iki türüdür.

Hoca bir parantez açarak bazı kaynakların ardışıl diyagramları iş analizinde de, yani aktörler ile senaryolar arasındaki etkileşimleri ve iş akışlarını göstermek için kullandığını söyledi. Bunu görürseniz şaşırmamak gerekir; ama ders kapsamında ardışıl diyagramlar tasarım diyagramı olarak ele alınır, çünkü asıl kullanım yerleri burasıdır.

> **Ek bilgi (derste anlatılmadı):** UML 2'de (büyük olasılıkla 2005 civarındaki sürümden itibaren) işbirliği diyagramının adı "iletişim diyagramı" (communication diagram) olarak değiştirilmiştir. Bazı araç ve kaynaklarda bu yüzden iki ad birlikte geçer.

### 14.1 Mesaj sıra numaraları

Slayttaki ardışıl diyagram (ekrandan, 01:35:00) dört nesne içerir: `n1:Nesne`, `n2:Nesne`, `n3:Nesne`, `n4:Nesne`. Akış şöyledir:

- Dışarıdan bir `mesaj()` gelir ve n1'i tetikler. Bu mesaj, senaryodaki bir satırın eylemidir (örneğin "toplam tutarı hesapla").
- n1, n2'ye `mesaj1()` gönderir.
- n2, bunun içinde n3'e `mesaj2` gönderir.
- n3, bunun içinde n2'ye `mesaj3()` gönderir. Bu, `mesaj1` ile aynı metot değildir; n2'nin farklı bir metot gövdesidir.
- Bu zincir bitince n1, n4'e `mesaj4()` gönderir.

Hoca diyagramı bir sözde kod gibi okudu:

```text
n1.mesaj():
    n2.mesaj1():
        n3.mesaj2():
            n2.mesaj3()
    n4.mesaj4()
```

Her çağrı bitince çağırana bir dönüş değeri döner (hoca dönüşleri kesikli çizgiyle çizdi). Mesajların sıra numaraları, bir metodun içinde çağrıların hangi sırayla yapılacağını gösterir. Altta başka bir okla başlayan mesajlaşma ise bu metot gövdesinden bağımsız başka bir metot gövdesidir. Hoca, bir etkileşim diyagramının genellikle tek bir metot çağrısını ve onun ardından olanları, yani tek bir sorumluluğun nesnelerin işbirliğiyle nasıl yerine getirildiğini gösterdiğini vurguladı. <!-- BELİRSİZ: hocanın sözlü numaralandırması ("bu 1, bu 1.1, bu 1.2 ... bu da 2") tam anlaşılmıyor -->

> **Ders sonrası not:** UML'nin iç içe (ondalıklı) numaralandırmasına göre bu diyagram büyük olasılıkla şöyle numaralanır: `1: mesaj1`, `1.1: mesaj2`, `1.1.1: mesaj3`, `2: mesaj4`. Çünkü `mesaj2`, `mesaj1`'in içinde; `mesaj3` de `mesaj2`'nin içinde çağrılır.

### 14.2 Kendine çağrı

Bir nesne kendi başka bir metodunu çağırdığında ardışıl diyagramda yaşam çizgisi üzerinde ayrı bir etkinlik kutusu (ayrı bir metot gövdesi) görünür. Bu, o metodun çalışıp bittiği ve ardından ana metodun kaldığı yerden devam ettiği şeklinde okunur; kodda "this.metot()" diye yazılan çağrılara karşılık gelir.

### 14.3 Koşullu mesajlar

İşbirliği diyagramında koşul, mesajın önüne köşeli parantez içinde yazılır: "şart uygunsa bu işlemi yap". Ardışıl diyagramda koşullu çağrı bir "opt" (optional) kutusunun içine alınır ve koşul kutunun başına yazılır; koşul doğruysa kutudaki metot çağrılır.

if-else durumu için işbirliği diyagramında iki mesaj iki ayrı koşulla yazılır: A koşulu doğruysa bir metot, yanlışsa diğer metot çalışır (hocanın örneğinde ikinci dalın içinde bir çağrı daha vardı). Ardışıl diyagramdaki karşılığı "alt" (alternative) kutusudur: kutu kesikli bir çizgiyle iki bölmeye ayrılır; üst bölme koşul doğruyken, alt bölme koşul yanlışken çağrılacak mesajları içerir.

### 14.4 Döngüler

Slayttaki diyagramlar (ekrandan, 01:40:00):

```text
İşbirliği diyagramı:
  [n1:Nesne] ---- 1: [i=1..N]: işlemYap() ---> [n2:Nesne]

Ardışıl diyagram:
  n1:Nesne                    n2:Nesne
     |                           |
  +--loop [i=1..N]---------------+----+
  |  |---- 1: işlemYap() ------->|    |
  +-------------------------------------+
```

İşbirliği diyagramında döngü yıldız (*) ile gösterilir: bu, koleksiyondaki (liste, dizi) bütün nesneler için işlemin tek tek yapılacağı anlamına gelir. Ardışıl diyagramdaki karşılığı "loop" kutusudur. Döngü sayılı ya da koşullu olabilir; koşul ya yalnız yıldızdır ya da `[i=1..N]` gibi bir ifadedir. Belirli bir aralık için de yazılabilir, örneğin dizinin ilk 10 elemanı için.

## 15. Senaryoların gerçeklenmesi ve sorumluluklar

Bu diyagramları oluşturma işine kullanım senaryolarının gerçeklenmesi (use case realization) denir: senaryolar okunur, senaryodaki bütün durumlara bakılır ve her durumda yapılması gerekenler modellenir. Tasarım uzayında yapılan iş, yazılım sınıflarına metotlar eklemek ve bu sorumlulukları yerine getiren nesneler arasındaki mesajlaşmaları ve sıralarını belirleyip çizmektir.

### 15.1 Sorumluluk türleri

Bir nesnenin temelde iki tür sorumluluğu vardır:

- **Bilmesi gerekenler:**
  - Kendi özel verileri
  - Kullandığı, ilişkili olduğu diğer nesneler
  - Hesapla elde edebileceği veriler (bunlara erişimi olmalıdır)
- **Yapması gerekenler:**
  - Bir hesap yapmak
  - Bir nesne yaratmak ya da yok etmek
  - Başka nesneleri çağırmak, metotlarını kullanmak, harekete geçirmek
  - Başka nesnelerin çalışmasını denetlemek

### 15.2 Gerçekleme süreci

Slayttaki içerik (ekrandan, 01:45:00):

- Sorumlulukları yerine getirmek için metotlar oluşturulur
- Bir sorumluluğu yerine getirmek için bir metot başka metotlarla işbirliği yapabilir
- İlk iterasyonda senaryoların ana akışları gerçekleştirilir
- İkinci iterasyonda alternatif akışlar ele alınır ve gerçeklenir.
- Büyük senaryolar birkaç iterasyon sürebilir. Daha küçükleri bir iterasyonda bitebilir.
- Tasarımın sonunda tersine gidilerek, problem domeninin diyagramı çıkarılır. Bu sayede analiz diyagramlarının son hali de elde edilmiş olur.

Sorumlulukları yerine getirmek, sınıf diyagramındaki üçüncü bölmeyi (metotları) doldurmak demektir. Bütün senaryolardaki bütün sorumlulukları tek adımda gerçeklemek zordur; bu yüzden önce ana akış, sonra alternatif akışlar ele alınır. Bütün senaryolar bitince yazılımın nasıl çalışacağı ifade edilmiş olur.

Hoca bunun aynı zamanda problem uzayının son hali olduğunu vurguladı. Tasarım bitince geri gidilip yazılıma özgü sınıflar çıkarılır ve yalnız kavramsal sınıflar ile ilişkileri bırakılırsa analiz modelinin en güncel ve gerçeklemeye dönüştürülmüş hali elde edilir. Analizde eksik kalan, fazla yapılan ya da gereksiz eklenen kavramlar böylece temizlenmiş olur.

### 15.3 Satış senaryosu örneği

Hoca gerçeklemeye analizde kullanılan satış senaryosuyla giriş yaptı. O modelde müşteri, kasa, kasiyer, satış, satışın satırları (kalemleri), ürünler ve ürün tanımları vardı (ürün tanımları, ürünler satılıp gidince tanımları kaybolmasın diye ayrı tutulmuştu). Ana akıştaki adımlar ve doğurdukları sorumluluklar:

- Müşteri satın alacağı ürünlerle gelir. Bu, bilinmesi gereken bir şeydir: müşterinin ürünleri vardır.
- Kasiyer yeni bir satış başlatır. Bu bir nesne yaratma sorumluluğudur ve bunun için bir ardışıl diyagram çizilmesi gerekir.
- Kasiyer ürün tanımlayıcısını girer. Burada "barkod gir" gibi bir metodun çalışması beklenir.
- Sistem satış satırını oluşturur, kaydeder; ürün tanımını, fiyatını ve ara toplamı ekranda gösterir. Fiyat belirli bir fiyat kuralıyla hesaplanır.
- Kasiyer bütün ürünler bitene kadar 3. ve 4. adımları tekrar eder.
- Sistem vergilerle birlikte toplam tutarı gösterir.

Hoca anlatması kolay olduğu için son sorumluluğu seçti: ekranda örneğin "ödemeniz gereken tutar 86 lira 75 kuruş" gösterilecekse satışın toplam tutarının hesaplanması gerekir. Bunun hangi nesneye ve nasıl atanacağı GRASP prensipleriyle sonraki derste gösterilecek. <!-- BELİRSİZ: senaryo slaytının karesi yok; adımlar altyazıdan alındı -->

## 16. GRASP tasarım kalıplarına giriş

Slayttaki içerik (ekrandan, 01:50:00):

- Genel prensipler ve akla yatkın çözümlerin birleştirilmesiyle oluşturulan repertuar.
- Probleme getirdiği çözümü belirten kolay isimler verilir (iletişimi kolaylaştırır).
- Kalıplar, tanımlı bir problem için en iyi çözümü sağlar.
- GoF kalıpları: 23 adet.
- Bu derste 9 adet genel sorumluluk atama prensibi anlatılacaktır.

GRASP, "General Responsibility Assignment Software Patterns" sözcüklerinin baş harfleridir; Türkçede genel sorumluluk atama yazılım kalıpları ya da prensipleri denebilir. Hoca bunların aslında herkesin bildiği, ama belki bildiğinin farkında olmadığı akla yatkın çözümler olduğunu, nesneye yönelik çözümlemenin özünü oluşturduğunu söyledi. Kalıplara basit isimler verilmesinin nedeni takım içindeki iletişimi kolaylaştırmaktır: "Bu satışı X kalıbına göre çözelim" ya da "X ve Y kalıplarını birlikte değerlendirelim" demek yeterli olur. Kalıplar daha önce yaşanmış ve çözülmüş problemlerdir; mevcut durum için en uygun çözümü sağlayan tasarıma tasarım kalıbı denir. Bu alanın bilinen örneği "Gang of Four" (GoF) kalıplarıdır ve 23 tanedir; derste bunlara girilmeyecek. Dokuz GRASP prensibinin ayrıntısı süre yetmediği için sonraki derse kaldı.

> **Ek bilgi (derste anlatılmadı):** GRASP prensipleri büyük olasılıkla Craig Larman'ın "Applying UML and Patterns" kitabıyla yaygınlaşmıştır. Kitapta bu prensipler genellikle Information Expert, Creator, Controller, Low Coupling, High Cohesion, Polymorphism, Pure Fabrication, Indirection ve Protected Variations adlarıyla verilir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:20:00): Sistem nasıl temin edilecek? Kurum içi geliştirme, satın alıp ihtiyaca göre özelleştirme ve dışarıdan (hizmet olarak) temin etme seçeneklerinin artıları ve eksileri nelerdir?

> **Cevap (derste verildi):** Kurum içi geliştirmede ürün ve bilgi birikimi kurumundur, çözüm ihtiyaca tam uyar; ama uzun sürebilir, ekip başka işlerle meşgul olabilir, deneyim eksikliği eğitim maliyeti doğurabilir. Hazır sistem hızlıdır; ama tam uymayabilir ve özelleştirme emeği çok büyüyebilir. Outsource etmede risk karşı tarafa geçer ve sonuç sözleşmeyle güvenceye alınır; ama risk fiyatlandırılır (örneğin 15 adam-ay yerine 25 adam-ay fatura), ürün kurumun olmaz, analiz modeli yanlış anlaşılabilir, kaynak kod kurumda olmadığı için bakım ve değişiklik zorlaşabilir.

**Soru 2** (ekrandan, 00:30:00): Bir bilgi sisteminin mimarisi modellenirken cevaplanması gereken sorular nelerdir?

> **Cevap (derste verildi):** Sistem merkezi mi dağıtık mı olacak; veri ağ üzerinde nasıl dağıtılacak, eş zamanlılık ve tutarlılık nasıl sağlanacak; hangi dil, araç, kütüphane, API ve SDK kullanılacak; satın alınan ticari yazılımlar nasıl bütünleştirilecek; kullanıcı arayüzünde ve diğer sistemlerle arayüzde hangi teknolojiler kullanılacak.

**Soru 3** (derste sözlü, 00:25:57): Sistemin eş zamanlı 10.000 kullanıcıya en fazla 1 saniye bekleme süresiyle hizmet vermesi istenirse tek sunuculu bir tasarım neden yetmez, mimari nasıl değişir?

> **Cevap (derste verildi):** Bu bir işlevsel olmayan gereksinimdir ve tek sunucunun kapasitesini aşar; birden fazla uygulama sunucusuyla dağıtık mimariye geçmek gerekir. Sunucu başına 10.000 dolardan 5 sunucu 50.000 dolarlık yatırımdır; yük yalnız kayıt dönemlerinde yoğunsa yatırımın büyük kısmı boşa çalışır. Bu yüzden yük geldikçe ölçeklenen konteyner mimarisi, konteyner açılış gecikmesi de sorun oluyorsa serverless mimari düşünülür.

**Soru 4** (derste sözlü, 00:50:00): Girdi geçerlemede tutarlılık kontrolüne bir örnek verin.

> **Cevap (derste verildi):** Doğum tarihi ve evlilik tarihi alınan bir formda evlilik tarihinin doğum tarihinden en az 18 yıl (özel durumlarda 15 yıl) sonra olması beklenir. Doğum yılı 2000, evlilik yılı 2005 ya da 2010 girilirse sistem tutarsızlığı yakalamalıdır.

**Soru 5** (ekrandan, 01:35:00): Mesaj sıra numaraları slaytındaki ardışıl diyagram (n1 dışarıdan `mesaj()` alır; n1→n2 `mesaj1()`, n2→n3 `mesaj2`, n3→n2 `mesaj3()`, n1→n4 `mesaj4()`) hangi çağrı yapısını gösterir?

> **Cevap (derste verildi):** `n1.mesaj()` içinde önce `n2.mesaj1()` çağrılır; onun içinde `n3.mesaj2()`, onun içinde de n2'nin başka bir metodu olan `mesaj3()` çağrılır. Bu zincir bitince `n1.mesaj()` içinde `n4.mesaj4()` çağrılır. UML iç içe numaralandırmasıyla büyük olasılıkla 1, 1.1, 1.1.1 ve 2 numaralarını alır (numaralandırma ders sonrası eklendi).

## Dersin Toparlaması

Bu derste sistem analizi tamamlanıp tasarıma geçildi. Tasarım ön tasarım ve ayrıntılı tasarım olarak ikiye ayrıldı. Ön tasarımda sistemin nasıl temin edileceğine karar verildi; mimarinin asıl olarak işlevsel olmayan gereksinimlerle şekillendiği görüldü. Altyapı belirleme adımları (envanter, iş yükü, donanım ve yazılım değerlendirme, satıcı seçimi, satın alma şekli) ve çıktı, girdi ve arabirim tasarımının ilkeleri anlatıldı. Ardından işlevsel tasarımın aracı olan yapı diyagramı (modüller, veri iletişimi, kontrol mesajları, durumlar, döngüler) ve onu ayrıntılandıran HIPO işlendi. Son olarak nesneye dayalı tasarımda yazılım sınıflarının ve sorumlulukların nasıl belirlendiği, işbirliği ve ardışıl diyagramların gösterimleri (sıra numaraları, koşul, if-else, döngü) ve senaryoların gerçeklenmesi süreci anlatıldı.

Sonraki derste dokuz GRASP prensibi üzerinden sorumlulukların nasıl atanacağı satış senaryosundaki toplam tutar hesabı gibi örneklerle gösterilecek; ardından veri modeli tasarımı ve bilgi sistemi geliştirme sürecinin kalan adımlarına geçilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
