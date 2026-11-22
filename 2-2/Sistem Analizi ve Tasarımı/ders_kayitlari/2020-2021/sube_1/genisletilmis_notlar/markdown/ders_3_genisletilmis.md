# Ders 3 Genişletilmiş Notu: Proje Yönetimi, Fizibilite Çalışması ve Proje Zamanlaması

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dönem projesindeki roller ve bilgi sistemi geliştirme aşamaları
- 2. Proje ekibi
- 3. Proje yönetimi, müşteri ve kullanıcı
- 4. Proje yöneticisinin görevleri ve projenin başlatılması
- 5. Proje planlama aşaması ve problemin tanımı
- 6. Fizibilite türleri
- 7. Maliyetler ve faydalar
- 8. Fizibilite çalışmasının yürütülmesi: RMO örneği
- 9. Proje takvimi: PERT/CPM ve Gantt şemaları
- Örnek Sorular

## 1. Dönem projesindeki roller ve bilgi sistemi geliştirme aşamaları

Dersin ilk bölümünde hoca, dönem projesinin amacını ders konusuyla ilişkilendirdi. Projenin amacı, gerçek hayattaki bir sistem geliştirme olayındaki rolleri yapay bir ortamda denemek ve herkesin üstlendiği rolü yürütmesidir (ekrandan, 00:10:00). Ekranda gösterilen proje tanımında bu roller "müşteri, proje müdürü, sistem analisti, uygulama geliştirici" olarak sayılıyor.

- **Sistem analisti:** analiz ve modelleme sırasında çalışır. Analiz ve tasarım tarafındaki modellemelerde bazen iki kişi çalışabilir.
- **Proje yöneticisi:** proje planlama sırasında çalışır. Proje yöneticisi aynı zamanda sistem analisti olarak da görev yapabilir.
- **Müşteri:** işin gerçek hayattaki tarafını temsil eder ve sonunda kabul testini yapar. Gerçek bir müşteri bulmak zor olduğu için bu rolü ekipten biri üstlenir.
- **Uygulama geliştirici (kodlayıcı):** programı yazar. Ekran tasarımı ve uygulama kodu ayrı kişilerce yapılabilir; yani bir rolde birden fazla kişi olabilir.

Hoca, müşterinin aynı zamanda test eden kişi olduğunu vurguladı: müşteri, yapılan yazılımın kendi gereksinimlerine uygun olup olmadığını kullanıcı testiyle kontrol eder. Rollerin ayrılması kimsenin yalnız tek bir işle sınırlı kalacağı anlamına gelmez; müşteri rolündeki kişiye kodlama sırasında da iş verilebilir.

**Soru:** Gerçek bir kurumla çalışılıyorsa müşteri rolü o kuruma bırakılabilir mi? **Cevap:** Ekipten biri yine müşteri rolünde olmalıdır. Kurum ne isteyeceğini ve sistemi nasıl test edeceğini bilemeyebilir; ekipteki kişi onların temsilcisi gibi çalışır.

Hoca projenin iki yaklaşımdan biriyle yapılabileceğini de söyledi: yapısal yaklaşım ya da nesneye yönelik yaklaşım. Hangi yaklaşım seçilirse kullanılacak diyagramlar ona göre farklı olur. Programlama dili serbesttir.

Bilgi sistemi geliştirme projesinin temel aşamaları sırasıyla şunlardır:

- Proje planlama
- Analiz
- Tasarım
- Gerçekleştirme (implementasyon)
- Destek

Bir projenin belgelerinden plan aşaması, fizibilite, analiz, sistem tasarımı ve kodlama aşamalarının izlenebilmesi gerekir.

## 2. Proje ekibi

Hoca proje ekibini bir slaytla anlattı (ekrandan, 00:20:00). Proje ekibi bir "cerrahi ekip" gibidir: her üye bütün için kritik olan uzmanlaşmış bir görevi yerine getirir. Ekip, projenin süresi boyunca değişir (proje liderliği de değişebilir):

- **Planlama aşaması:** ekipte yalnız birkaç kişi vardır, örneğin proje yöneticisi ve birkaç analist.
- **Analiz aşaması:** ekibe iş analistleri ve sistem analistleri eklenir.
- **Tasarım aşaması:** teknik uzmanlık gerektiren alanlarda başka uzmanlar gelebilir, örneğin veri tabanı ya da ağ (network) tasarımcısı. Hocanın ifadesiyle bunlar ek, kısa süreli destek olarak da gelebilir.
- **Gerçekleştirme aşaması:** programcılar ve kalite kontrolü yapan kişiler eklenir.

Planlamada az kişi, analiz ve tasarımda biraz daha fazla, gerçekleştirmede en çok kişi çalışır. Hoca, ekip yapısının bu örneğe bakılarak farklı da kurulabileceğini söyledi.

## 3. Proje yönetimi, müşteri ve kullanıcı

Slayttaki tanımlar şöyledir (ekrandan, 00:35:00):

- **Proje yöneticisi (project manager):** ekibin işleyişinden birinci derecede sorumlu kişidir.
- **Proje yönetimi (project management):** önceden belirlenmiş bir iş listesi (takvim) ve bütçe sınırları içinde, planlanan sonuca ulaşmak üzere diğer insanları organize etme ve yönlendirmedir. Hoca bunu, çalışanların yönlendirilmesinin ve organizasyonun sağlandığı bir bilim dalı olarak tanımladı.
- **İyi yönetici:** nasıl plan yapacağını, planı nasıl uygulayacağını bilir; sorunları önceden görür ve sapmalara göre ayar yapar.
- **Müşteri (client):** projeyi finanse eden kişi ya da gruptur.
- **Denetim kurulu (oversight committee):** projeyi gözden geçiren ve yönlendiren kuruldur (slaytta yer alıyor, derste ayrıca anlatılmadı).
- **Kullanıcı (user):** sistemi kullanacak kişi ya da gruptur.

Hoca proje yöneticisi için "yetkisiz sorumluluk" ifadesini kullandı. Proje yöneticisi projeden sorumludur ama çalışanların işe ya da projeye alınması çoğu zaman şirketteki asıl yönetimin işidir.

Proje yönetimi bir plan yapıp onu uygulamayı sağlar: bir işe başlarken plan yapılır, sonra çalışmaların bu plan çerçevesinde yürüyüp yürümediğine bakılır. Sorun çıktığında ya da değişiklik olduğunda yönetici bunları dengelemeye çalışır.

### 3.1 Müşteri ile kullanıcı farkı

Müşteri, projenin parasını veren ve proje sonuçlarını isteyen, kullanacak olan taraftır. Bu bir kişi de olabilir, bir grup da. Kullanıcı ise sistemi doğrudan kullanacak kişidir.

Hocanın örneği: yazılım şirketi olmayan herhangi bir işletmenin muhasebe birimine bir yazılım lazım olsun, örneğin bordro uygulaması yenilenecek. Yazılım isteğini muhasebe birimi başkanı (muhasebe müdürü) yapar. Parayı üst yönetim, yazılımı geliştirecek ekibe öder. Bordro çalışmalarını yapan memurlar ise sistemin kullanıcısıdır. Dolayısıyla kullanıcı (user) ile müşteri (client) bazen aynı kişidir, bazen bu örnekteki gibi farklıdır.

Bir bilgi sistemi geliştirme projesinde proje yöneticisi, müşteri ve kullanıcıdan başka sistem analistleri, sistem tasarımcıları ve kodlayıcılar vardır.

## 4. Proje yöneticisinin görevleri ve projenin başlatılması

### 4.1 Proje yöneticisinin görevleri

Hoca slayttaki görev listesini sıraladı:

- **Organizasyon ve planlama**
  - Projenin kapsamını (alanını) tanımlamak.
  - Ayrıntılı iş listesi ve takvimle bir plan geliştirmek.
- **Yönlendirme**
  - Projenin yürütülmesini ve projede çalışanları yönlendirmek.
  - Projeyi koordine etmek; projenin kilometre taşlarını (milestone) belirlemek ve bu noktalarda değerlendirme yapılmasını sağlamak.
- **Genel kontrol**
  - Kontrol noktalarını ve kilometre taşlarını tanımlamak.
  - İlerlemeyi izlemek.
  - Metodolojileri tanımlamak.

### 4.2 Projenin başlatılması

Bir proje üç şekilde başlayabilir (ekrandan, 00:40:00):

- **Uzun dönemli stratejik planın parçası olarak (yukarıdan aşağı):** kurumun misyon ya da hedef ifadesinden, genellikle bilgi teknolojisini içeren rekabetçi bir iş stratejisi çıkar. Slayttaki örnek: Rocky Mountain Outfitters (RMO), daha rekabetçi olmak için müşteri desteğini iyileştirmek ister ve sistemlerini İnternet tabanlı olarak yeniden geliştirmeye yönelir.
- **Aşağıdan yukarı:** ortaya çıkan acil bir ihtiyacı karşılamak için.
- **Dış bir etken nedeniyle:** örneğin vergi yapısındaki bir değişiklik faturalama sistemini etkileyebilir.

Hoca stratejik plan için şu örneği verdi: bir şirket kurulurken önce stoktaki bilgileri girecek stok yazılımı oluşturulur, sonra satın alma yazılımı, sonra müşteri bilgilerini tutan yazılım. Hangi yazılımın önce, hangisinin sonra geliştirileceğine bir stratejik plan çerçevesinde karar verilir.

## 5. Proje planlama aşaması ve problemin tanımı

Proje planlama aşamasının adımları şunlardır:

- Problemi tanımlama
- Projenin fizibilitesini doğrulama
- Proje iş listesini (takvimini) üretme
- Projede görevlileri belirleme, ekibi oluşturma
- Projeyi başlatma

Problemin tanımı, bizden ne istendiğini ve ne yapılacağını ortaya koyar. Bir önceki adımda tanımlanan problemi çözmek için nasıl bir teknik yapı düşünüldüğü anlatılır. Bu teknik yapının maliyeti ve getirisi kıyaslanarak ekonomik fizibilite yapılır; projenin kullanıcılara göre kullanılabilirlik durumu da başka bir fizibilitedir. Hoca, teknik, ekonomik ve kullanılabilirlik değerlendirmesinin bütün alternatif çözümler için yapılması gerektiğini, bunun için her alternatifin maliyetini ve faydasını gösteren tablolar hazırlanacağını söyledi.

Daha sonra iş listesi oluşturulur: projeyi gerçekleştirmek için hangi adımlarla çalışılacağı (bilgi sistemi geliştirmede analiz, tasarım, gerçekleştirme, test, destek). Ardından hangi görevlerin olması gerektiği belirlenir ve bu görevlere insan ataması yapılır.

Problemi tanımlarken iş ihtiyaçları ve faydaları gözden geçirilir, yeni sistemin beklenen yetenekleri (projenin kapsamı) tanımlanır ve kapsamı açıklamak için bir bağlam diyagramı çizilebilir.

### 5.1 RMO örneği: ihtiyaç ve işletme faydaları

Hoca, Rocky Mountain Outfitters (RMO) firmasının müşteri destek sistemi örneğini kullandı (ekrandan, 00:45:00). Slayttaki açıklamaya göre RMO'da katalog satışı küçük bir deneme olarak başlamış ve hızla büyüyen bir birime dönüşmüştür. Destek önce elle yapılan işlemlerle ve sipariş alma ve karşılamaya yardım eden basit hazır programlarla sağlanmıştır. Pazardaki fırsatlar sonucu RMO kapsamlı bir stratejik planlama başlatmıştır. Yeni stratejik planın bir parçası; satış, müşteri desteği ve envanter için uzun dönemli hedefleri destekleyecek yeni bilgi sistemlerinin geliştirilmesidir. Yeni müşteri destek sistemi, inşa edilecek kritik sistemlerin ilkidir.

Beklenen işletme faydaları (yani müşteri tarafı neden yeni sistem istiyor):

- Siparişlerin elle işlenmesinden kaynaklanan hataları azaltmak.
- Daha hızlı sipariş işlemeyle sipariş karşılamayı hızlandırmak.
- Posta ve telefonla sipariş işlemede personel düzeyini korumak ya da azaltmak.
- İnternet üzerinden yeni bir satış kanalı açmak.
- Popüler ve yavaş satan ürünlerin satışını izleyerek ciroyu artırmak.
- Kapsamlı müşteri desteği ve bilgilendirmeyle müşteri bağlılığını artırmak.

Hoca bunu "satış işlemini müşteri kaybetmeden devam ettirmek" diye özetledi.

### 5.2 RMO örneği: sistem yetenekleri

Müşterinin istediklerini yapmak için yeni sistemin yetenekleri (ekrandan, 01:00:00). Müşteri destek sistemi şu hedefleri karşılayacaktır:

- Çevrim içi müşteri, sipariş, bekleyen sipariş (back order) ve iade bilgisiyle yüksek destekli bir sistem olmak.
- Geleneksel telefon ve posta kataloğu satışlarını hızlı veri giriş ekranlarıyla desteklemek.
- Satın alma ve sipariş takibi dahil İnternet üzerinden müşteri ve katalog satışı yeteneği sunmak.
- Pazar analizini desteklemek için yeterli veri tabanı ve geçmiş bilgisi tutmak.
- Müşteri sorguları için işlem geçmişi sağlamak.
- Hacimdeki büyük artışları (yüzde 300 ya da daha fazla) performans düşüşü olmadan karşılamak.
- Yeni siparişlerin 24 saatte gönderilmesini desteklemek.
- Birden çok depodan sipariş gönderimini koordine etmek.
- Satış analizi ve pazar talebi tahmini için geçmişi saklamak.

Hoca bu iki listeyi şöyle bağladı: önce müşteri destek sisteminin tanımı ve işletme faydaları verildi, sonra bu faydaları sağlamak için sistemin hangi yeteneklerde olması gerektiği belirtildi.

### 5.3 Taslak veri akış diyagramı

Ardından sistem, taslak ya da özet veri akış diyagramı (bağlam diyagramı) ile gösterildi. Ortada müşteri destek sistemi vardır. Çevresinde sistemle bilgi alışverişi yapan birimler bulunur:

- Pazarlama birimi
- Müşteri
- Banka
- Ürün gönderme birimi
- Yönetim birimi
- Satış birimi

Diyagram, müşteri destek sisteminin bu birimlerin her biriyle hangi bilgi üzerinden iletişim kurduğunu gösterir. <!-- BELİRSİZ: Diyagramdaki okların üzerindeki veri akışı adları karelerde okunamadı; birim listesi altyazıdan alındı. -->

## 6. Fizibilite türleri

Projenin fizibilitesi doğrulanırken şu türler değerlendirilir:

- **Ekonomik fizibilite:** maliyet-fayda (cost-benefit) analizidir. Hoca, bunun genellikle yalnız maliyet hesabı gibi anlaşıldığını, oysa maliyetle faydanın kıyaslanması olduğunu vurguladı.
- **Kurumsal ve kültürel fizibilite:** sistemin kurum kültürüne uygun olup olmadığı.
- **Teknik fizibilite:** sistemin teknik gereksinimleri karşılayacak yapıda olup olmadığı, önerilen teknoloji için uzmanlık bulunup bulunmadığı.
- **Takvim (iş listesi) fizibilitesi:** bütün bunları yapmak için gerekli iş listesinin kurulup kurulamayacağı ve belirlenen süreye sığıp sığmayacağı.
- **Kaynak fizibilitesi:** çalışanlar ve bilgisayar kaynakları açısından geliştirme ekibinin sağlanıp sağlanamayacağı.

> **Ek bilgi (derste anlatılmadı):** Slayt önizlemesinde kurumsal ve kültürel fizibilite için çalışanların düşük bilgisayar okuryazarlığı ve işini kaybetme korkusu, takvim fizibilitesi için sabit bir son tarihe sahip projeler örnek veriliyor. Bu tür etkenler, teknik olarak mümkün ve kârlı bir projeyi bile başarısız kılabilir.

Ekonomik fizibilite, bilgi sistemini hazırlamak için gereken maliyet ile yeni sistemden sağlanacak faydanın kıyaslanmasıdır. Bilgi sistemini geliştirmek bir yatırımdır ve elde edilecek faydanın bu yatırıma değip değmeyeceğinin gösterilmesi gerekir. Hoca bunu "attığımız taş ürküttüğümüz kurbağaya değecek mi" deyimiyle anlattı.

## 7. Maliyetler ve faydalar

### 7.1 Maliyetler

Slayttaki maliyet sınıflaması (ekrandan, 01:05:00):

- **Geliştirme maliyetleri:** maaş ve ücretler, donanım ve kurulumu, yazılım ve lisanslar, danışmanlık ücretleri ve üçüncü taraflara ödemeler, eğitim, tesisler, altyapı ve araçlar, destek personeli, seyahat ve diğer giderler.
- **Süregelen işletim maliyetleri:** bağlantı, donanım bakımı, bilgisayar işletimi, programlama desteği, donanım amortismanı, eğitim ve sürekli destek (yardım masası), sarf malzemeleri.

Hoca burada sistemi yalnız kurmakla kalınmadığını vurguladı: kurarken geliştirme maliyeti (development cost) devreye girer, kurduktan sonra da sistemin çalışır durumda kalması için bakım, program desteği ve devam eden eğitim gibi harcamalar gerekir.

### 7.2 Somut faydalar

Somut (tangible) faydalar doğrudan paraya dökülebilen faydalardır. Hocanın saydığı örnekler:

- Otomasyon nedeniyle çalışan sayısının azalması ya da mevcut çalışanların korunması.
- İşletim harcamalarının azalması.
- Hata oranının azalması (özellikle otomasyon sistemlerinde).
- Daha düşük fiyatları yakalama.
- Envanter ve satış kayıplarının azalması. Örneğin daha iyi bir müşteri destek sistemiyle müşteriler daha iyi yönetilir ve kaçan müşteri azalır.
- Kâğıt ve iletişim maliyetlerinin azalması.

### 7.3 Somut olmayan faydalar

Somut olmayan (intangible) faydalar doğrudan paraya dökülemeyen ama önemli faydalardır. Hocanın örneği: bir hastane bilgi sisteminde hastanın güveninin kazanılması. Bir proje için doğrudan görülmeyen faydalar arasında düşük üretkenliğin, müşteri sayısının ya da satışların azalmasının önlenmesi de sayılabilir.

> **Ek bilgi (derste anlatılmadı):** Slayt önizlemesinde son örnekler (çalışan moralinin düşmesi, üretkenlik kaybı, müşteri ya da satış kaybı) bir projenin somut olmayan maliyetleri olarak da geçiyor. Yani bir proje yalnız somut olmayan fayda değil, somut olmayan maliyet de doğurabilir.

## 8. Fizibilite çalışmasının yürütülmesi: RMO örneği

### 8.1 Adımlar

Fizibilite çalışması şöyle yürütülür (ekrandan, 01:10:00):

- Her maliyet kategorisi tahmin edilir.
- Maaş ve ücretler personel ihtiyacına göre hesaplanır (ücretler, fazla mesai ücretleri: personel giderleri).
- Donanım, yazılım lisansları ve eğitim gibi diğer maliyetler tahmin edilir.
- Geliştirme maliyetlerinin ve yıllık işletim maliyetlerinin özeti çıkarılır.
- Faydaların özeti çıkarılır.
- Fayda ve maliyetlerin bugünkü değeri olan net bugünkü değer (NPV), örneğin 5 yıllık bir dönem için hesaplanır.
- Projeye devam edilip edilmeyeceğine, yani projenin kârlı olup olmadığına karar verilir.

### 8.2 Personel maliyeti hesabı

RMO örneğinde her iş grubu için kaç kişinin ne kadar süre çalışacağı ve yıllık maaşı yazılır. Proje yöneticisi 12 ay çalışır ve yıllık 90.000 alır. Sistem analistinin yıllık ücreti 75.000'dir, 3 sistem analisti 9 ay çalışır. Programcıların yıllık ücreti 50.000'dir, 6 programcı 7 ay çalışır. Toplam 462.916 olur (ekrandan, 01:15:00; tablo slayt önizlemesinden okundu, ağ tasarımcısı satırı altyazıda geçmiyor):

| Görev | Süre | Yıllık maaş | Toplam |
|---|---|---|---|
| Proje yöneticisi | 12 ay | 90.000 | 90.000 |
| Sistem analisti (3) | 9 ay | 75.000 | 168.750 |
| Programcı (6) | 7 ay | 50.000 | 175.000 |
| Ağ tasarımcısı | 5 ay | 70.000 | 29.166 |
| Toplam | | | 462.916 |

Her satırın hesabı (ara adım eklendi):

- Proje yöneticisi: $90.000 \times \frac{12}{12} \times 1 = 90.000$
- Sistem analistleri: $75.000 \times \frac{9}{12} \times 3 = 168.750$
- Programcılar: $50.000 \times \frac{7}{12} \times 6 = 175.000$
- Ağ tasarımcısı: $70.000 \times \frac{5}{12} \approx 29.166{,}67$, tabloda 29.166
- Toplam: $90.000 + 168.750 + 175.000 + 29.166 = 462.916$ (python ile doğrulandı)

Bu tabloya ek olarak araç gereç alımı, eğitim ücreti, destek çalışanları, seyahat harcamaları ve lisanslar eklenerek geliştirme maliyetinin toplamı, ayrıca yıllık işletim maliyeti bulunur. Faydalar tarafında da örneğin posta ile sipariş departmanının ve telefonla sipariş departmanının etkinliğinin artmasının ne kadar para kazandırdığı yazılır; yani fayda da sayıya çevrilir. <!-- BELİRSİZ: Geliştirme maliyeti özeti ve fayda tablolarındaki kalem kalem tutarlar karelerde görünmedi. -->

### 8.3 Net bugünkü değer tablosu

RMO maliyet-fayda analizi, indirim oranı %10 (ekrandan, 01:15:00):

| Satır | Yıl 0 | Yıl 1 | Yıl 2 | Yıl 3 | Yıl 4 | Yıl 5 |
|---|---|---|---|---|---|---|
| 1 Fayda değeri | 0 | 889.000 | 1.139.000 | 1.514.000 | 2.077.000 | 2.927.000 |
| 2 İndirim faktörü | 1,000 | 0,9091 | 0,8264 | 0,7513 | 0,6830 | 0,6209 |
| 3 Faydaların bugünkü değeri | 0 | 808.190 | 941.270 | 1.137.468 | 1.418.591 | 1.817.374 |
| 4 Geliştirme maliyeti | 1.336.000 | | | | | |
| 5 Süregelen maliyet | | 241.000 | 241.000 | 241.000 | 241.000 | 241.000 |
| 6 İndirim faktörü | 1,0000 | 0,9091 | 0,8264 | 0,7513 | 0,6830 | 0,6209 |
| 7 Maliyetlerin bugünkü değeri | 1.336.000 | 219.093 | 199.162 | 181.063 | 164.603 | 149.637 |
| 8 Net fayda-maliyetin bugünkü değeri | -1.336.000 | 589.097 | 742.107 | 956.405 | 1.253.988 | 1.667.737 |
| 9 Birikimli NPV | -1.336.000 | -746.903 | -4.796 | 951.609 | 2.205.597 | 3.873.334 |

Tablonun okunuşu (hocanın anlatımından, ara adımlar eklendi):

- **İndirim faktörü:** %10 indirim oranında $n$. yılın faktörü $\frac{1}{(1+0{,}10)^n}$ olur. Örneğin 1. yıl $\frac{1}{1{,}1} = 0{,}9091$, 2. yıl $\frac{1}{1{,}21} = 0{,}8264$.
- **Faydaların bugünkü değeri:** fayda değeri ile faktör çarpılır. 1. yıl $889.000 \times 0{,}9091 = 808.190$. Hoca da 1. yıl için 889 bin faydanın bugünkü değer olarak 808 bin olduğunu okudu.
- **Maliyetler:** 0. yılda yalnız geliştirme maliyeti vardır ve indirim uygulanmadığı için 1.336.000 olarak kalır. Süregelen maliyet her yıl 241.000'dir; 1. yılın bugünkü değeri $241.000 \times 0{,}9091 = 219.093$.
- **Net değer:** her yıl için satır 3 eksi satır 7. 1. yıl $808.190 - 219.093 = 589.097$.
- **Birikimli NPV:** net değerler yıl yıl toplanır. $-1.336.000 + 589.097 = -746.903$, $-746.903 + 742.107 = -4.796$, $-4.796 + 956.405 = 951.609$.

> **Ders sonrası not:** Hoca süregelen maliyetin 1. yılda olmadığını, 2. yıldan itibaren her yıl 241 bin dolar olduğunu söyledi. Ekrandaki tabloda ise 241.000 1. yıldan itibaren yazılıdır ve maliyetlerin bugünkü değeri de 1. yıldan başlar.

> **Ders sonrası not:** Slaytta 2. yılın birikimli NPV'si "(4,769)" yazıyor. Tablodaki değerlerden $-746.903 + 742.107 = -4.796$ çıkıyor ve slayttaki geri ödeme formülü de 4.796'yı kullanıyor; doğrusu -4.796'dır. Slaytta 4. yıl maliyet bugünkü değeri "164,6037" diye yazılmış; $241.000 \times 0{,}6830 = 164.603$ olmalıdır (python ile doğrulandı).

### 8.4 Ekonomik ölçütler

Slayttaki ve hocanın anlattığı tanımlar:

- **Net bugünkü değer (net present value, NPV):** yeni sistem gibi bir yatırımın sonraki yıllardaki fayda ve maliyetlerinin bugünkü değeridir. Örneğin 4 yıl sonra sistemin çalışmasından sağlanan faydanın bugünkü değer cinsinden karşılığı bulunur. Hoca "bir yıl sonra alacağımız 100 doların bugün ne kadar değeri var" sorusuyla anlattı.
- **Geri ödeme süresi (payback period, başabaş noktası):** harcanan paranın ne zaman faydaya döndüğünü, yani birikimli faydanın birikimli maliyeti karşıladığı anı gösterir.
- **Yatırım getirisi (return on investment, ROI):** yeni sistem gibi bir yatırımdan elde edilen kazancın oranıdır. Hoca "yüzdelik kazanım demeyelim de kazanım oranı ölçüsü" dedi.
- **Somut fayda:** ölçülebilen, parayla ifade edilebilen faydadır.
- **Somut olmayan fayda:** kantitatif olarak ölçülemeyen, değeri tahminle belirlenen faydadır.

> **Ek bilgi (derste anlatılmadı):** $n$ yıl sonra alınacak $F$ tutarının bugünkü değeri $P = \frac{F}{(1+i)^n}$ ile bulunur; $i$ indirim oranıdır. Hocanın örneğinde $i = 0{,}10$ alınırsa bir yıl sonraki 100 doların bugünkü değeri $\frac{100}{1{,}1} \approx 90{,}91$ dolardır. Tablodaki indirim faktörü bu formüldeki $\frac{1}{(1+i)^n}$ çarpanıdır.

### 8.5 RMO geri ödeme süresi ve ROI

Tablonun son iki satırı (ekrandan, 01:15:00):

- **Geri ödeme süresi:** birikimli NPV 2. yılın sonunda -4.796, 3. yılın sonunda +951.609'dur; sıfır 3. yılın çok başında geçilir. Slayttaki hesap:

$$2 + \frac{4.796}{4.796 + 951.609} = 2 + 0{,}005 \approx 2 \text{ yıl } 2 \text{ gün}$$

  Ara adım eklendi: $0{,}005 \times 365 \approx 1{,}8$ gün, yani yaklaşık 2 gün (python ile doğrulandı).

- **5 yıllık ROI:** slaytta %22,23 ve formül olarak $\frac{1.817.374 - (1.336.000 + 149.637)}{1.336.000 + 149.637}$ yazıyor.

> **Ders sonrası not:** Slayttaki ROI formülünün sonucu %22,23 değil %22,33'tür. Ayrıca formül yalnız 5. yılın fayda ve maliyetini geliştirme maliyetiyle kıyaslıyor. 5 yılın toplam bugünkü değerleriyle $\frac{6.122.893 - 2.249.559}{2.249.559}$ hesaplanırsa ROI büyük olasılıkla yaklaşık %172 olmalıdır (python ile hesaplandı). Derste ROI sayısı üzerinde durulmadı.

Bu çalışmanın sonunda, ekonomik fizibiliteye bakarak projeye başlanıp başlanmayacağına karar verilir.

## 9. Proje takvimi: PERT/CPM ve Gantt şemaları

### 9.1 Proje takvimini geliştirme

Proje iş listesi şöyle oluşturulur (ekrandan, 01:20:00):

- Her etkinlik için tek tek görevleri belirle. Bu yukarıdan aşağıya ya da aşağıdan yukarıya yapılabilir; hoca yukarıdan aşağıya örnek verdi: bilgi sistemi geliştirme projesi önce analiz, tasarım, gerçekleştirme ve test, kullanıma alma gibi büyük adımlara, sonra alt görevlere bölünür.
- Her görevin büyüklüğünü (zaman ve kaynak) tahmin et; iyimser, kötümser ve beklenen süreler kullanılabilir. Örneğin analiz kaç haftada biter, maliyeti ve harcamaları nedir?
- Görevlerin sırasını belirle: öncelik-sonralık ilişkisine göre, bir iş yapıldıktan sonra hangi işin yapılması gerektiği ve aralarındaki ilişki.
- Görevleri takvime yerleştir.
- Gösterim yöntemleri: PERT/CPM (Program Evaluation and Review Technique / Critical Path Method) ve Gantt şeması.

Slayttaki karşılaştırma şöyledir: PERT/CPM şeması görevlere ya da etkinliklere dayalı ilişkileri gösterir; hangi görevlerin eş zamanlı yapılabileceğini ve kritik yolu tanımlar. Gantt şeması her görevin takvim bilgisini çubuk grafik olarak gösterir; takvimi iyi gösterir ama bağımlılıkları o kadar iyi göstermez.

> **Ders sonrası not:** Altyazıda kısaltmanın açılımı "Project Evaluation and Review Technique" diye geçiyor. Yaygın açılım "Program Evaluation and Review Technique"tir; slaytta "Project" yazıyor.

### 9.2 RMO planlama aşamasının iş kırılımı

Hoca, planlama aşamasının adımlarını süre ve kaynaklarıyla gösteren tabloyu anlattı:

- **Problemi tanımla:** kullanıcılarla görüş (2 gün, 2 sistem analisti), kapsamı belirle, işletme faydaları ifadesini yaz, ihtiyaç ifadesini yaz.
- **Proje takvimini oluştur:** iş kırılım yapısını (work breakdown structure) geliştir, kaynakları tahmin et, PERT ve Gantt şemalarını oluştur.
- **Proje fizibilitesini doğrula:** teknik fizibilite, ekonomik fizibilite.
- **Projeye eleman ata:** kaynak planını çıkar, teknik kişileri tanımla ve görevlere yerleştir.
- **Projeyi başlat:** sunum materyallerini hazırla, yönetime sunumu (executive presentation) yap, proje olanaklarını ve destek kaynaklarını oluştur.

İlk yapılacak şey, iş adımlarını böyle seviyelere ayırmak ve her birinin kaç gün sürecek, hangi kaynaklarla yapılacak olduğunu belirtmektir. <!-- BELİRSİZ: İş kırılım tablosunun gün ve kaynak sütunları karelerde okunamadı; yalnız altyazıda geçen "kullanıcılarla görüşme 2 gün, 2 sistem analisti" alındı. -->

### 9.3 PERT şeması

PERT şemasının özellikleri (ekrandan, 01:25:00):

- Görevler dikdörtgenlerle gösterilir.
- Paralel yollardaki görevler eş zamanlı yapılabilir.
- Kritik yol, bağımlı görevlerin en uzun yoludur.
  - Bu yolda bolluk (slack) süresine izin yoktur.
  - Diğer yollarda bolluk süresi olabilir: takvimi etkilemeden kayabilen süre.

Ardışık bağlı görevlerde bir görev kesintiye uğrarsa ona bağlı görev devam edemez. Hoca PERT'te asıl önemli olanın kritik yolu bulmak olduğunu söyledi. Şema her aşamayı belirleyip ardışık olarak ilişkilendirir, tamamlanan görevleri farklı renkte gösterebilir ve kritik yolu tanımlar.

> **Ders sonrası not:** Hoca bir yerde "paralel yollar üzerinde olan tasklar eş zamanlı olarak yapılamaz" dedi (01:23:23), birkaç saniye sonra slayta uygun olarak "eş zamanlı olarak yapılabilir" diye düzeltti. Doğrusu: paralel yollardaki görevler eş zamanlı yapılabilir.

RMO müşteri destek projesinin kısmi PERT şemasında (slayt, ekrandan, 00:55:00; derste PERT anlatılırken) her kutuda görev adı, görev numarası, süre, başlangıç ve bitiş tarihi yer alır. Okunabilen görevler:

| No | Görev | Süre |
|---|---|---|
| 1 | Planlama aşaması | 30 gün |
| 2 | Problemi tanımla | 8 gün |
| 3 | Kullanıcılarla görüş | 2 gün |
| 4 | Kapsamı belirle | 2 gün |
| 5 | İşletme faydaları ifadesini yaz | 1 gün |
| 6 | İhtiyaç ifadesini yaz | 1 gün |
| 7 | Sistem yetenekleri ifadesini tanımla | 1 gün |
| 8 | Bağlam diyagramını geliştir | 1 gün |
| 10 | Somut olmayan maliyet ve faydaları belirle | 1 gün |
| 11 | Somut geliştirme ve işletim maliyetlerini tahmin et | 3 gün |
| 12 | Somut faydaları tahmin et | 2 gün |
| 13 | NPV, ROI ve geri ödemeyi hesapla | 1 gün |
| 14 | Kurumsal ve kültürel fizibiliteyi değerlendir | 1 gün |
| 15 | Teknik fizibiliteyi değerlendir | 2 gün |
| 16 | Gerekli takvimi değerlendir | 1 gün |
| 17 | Kaynak bulunabilirliğini değerlendir | 1 gün |
| 18 | Proje takvimini üret | 7 gün |
| 19 | İş kırılım yapısını geliştir | 3 gün |
| 20 | Kaynakları, süreleri ve öncelikleri tahmin et | 2 gün |
| 21 | PERT ve Gantt şemasını geliştir | 2 gün |
| 22 | Projeye eleman ata | 11 gün |
| 23 | Proje için kaynak planı geliştir | 1 gün |

Şemada 3, 4, 5, 6, 7, 8, 10, 11, 19, 20, 21, 22 ve 23 numaralı görevler kırmızı çerçeveli ve kırmızı oklarla birbirine bağlı; 12, 13, 14, 15, 16 ve 17 numaralı görevler siyah çerçevelidir. <!-- BELİRSİZ: Bazı kutuların adları kesik görünüyor (11, 12, 14); adlar okunabilen kısımdan tamamlandı. Görev 9 karede görünmüyor. -->

> **Ek bilgi (derste anlatılmadı):** MS Project'in PERT (ağ) görünümünde kırmızı kutular büyük olasılıkla kritik yol üzerindeki görevlerdir. Siyah kutulardaki görevlerin bolluk süresi vardır; biraz gecikseler de proje bitiş tarihi değişmez.

Hoca, PERT diyagramının MS Project ile nasıl çizileceğinin gösterileceğini söyledi.

### 9.4 Gantt şeması

Gantt şeması zaman ve kaynak planlaması içindir (ekrandan, 01:30:00):

- Her görev bir çubukla gösterilir. Çubuğun uzunluğu görevin ne kadar sürdüğünü gösterir.
- Takvim bölümlemeleri günlere, haftalara ya da aylara göre yapılır.
- Takvim bilgisini kolay okunur biçimde gösterir.
- Tamamlanan görevler renklendirilerek ya da koyulaştırılarak gösterilir.
- Dikey bir çizgi bugünün tarihini gösterir.

> **Ders sonrası not:** Slaytta "Tasks represented by vertical bars" (görevler dikey çubuklarla gösterilir) yazıyor. Hocanın anlattığı gibi Gantt şemasında görevler yatay çubuklardır; zaman ekseni yataydır.

Hoca RMO planlama aşamasının Gantt şemasını büyüterek anlattı. Planlama aşamasının hepsini kapsayan bir üst yatay çubuk vardır. Problemi tanımlama aşaması alt adımlardan oluşur: kullanıcılarla görüş, kapsamı belirle, işletme ifadesini yaz gibi. Problemin tanımlanması bitince proje fizibilitesinin doğrulanması ve proje iş listesinin üretilmesi gelir. Sol taraftaki iş adımları, bilgi sistemi geliştirme sürecindeki analiz, tasarım, gerçekleştirme ve test maddeleridir. Proje ilerlerken iş listesinin takip edilip edilemediği de bu şema üzerinden görülür. <!-- BELİRSİZ: Gantt şemasının çubuk tarihleri karelerde görünmedi. -->

Hoca, sonraki haftalarda bu şemaların nasıl hesaplandığıyla ilgili bir uygulama çalışması yapmayı planladığını söyledi.

## Örnek Sorular

Ders sonunda hoca, anlatılanlarla ilgili sözlü sorular sordu.

**Soru 1** (derste sözlü, 01:30:29): Geri ödeme süresi (payback period) nedir?

> **Çözüm (derste verilmedi):** Sorulan öğrencinin cevabı kayda girmedi. Derste verilen tanıma göre geri ödeme süresi, projeye harcanan paranın faydaya döndüğü andır; birikimli faydanın birikimli maliyeti karşıladığı, yani birikimli NPV'nin sıfırı geçtiği zamandır. RMO örneğinde bu süre yaklaşık 2 yıl 2 gündür.

**Soru 2** (derste sözlü, 01:30:50): Gantt diyagramı nedir?

Bir öğrencinin cevabı: proje geliştirme aşamasında yapılacak işlerin zamanlara bölünerek her aşamanın ne kadar sürede gerçekleştirileceğini gösteren bir tablodur. Hoca bunu onayladı ve Gantt diyagramının özellikle zaman planlamasında yardımcı olduğunu ekledi.

**Soru 3** (derste sözlü, 01:32:07): PERT nedir?

Bir öğrencinin cevabı: yapılacak işlerin ve bunlara ayrılacak sürelerin belirlendiği, bunun üzerinden kritik yolların bulunduğu bir diyagramdır; yapılan işler farklı renklerle gösterilir. Hoca şöyle tamamladı: PERT diyagramında projedeki etkinlikler ve her birinin ne kadar süre gerektirdiği gösterilir; böylece hiç ara verilmemesi gereken işlemlerin (kritik yol) olup olmadığı planlanır.

## Dersin Toparlaması

Bu derste bir bilgi sistemi projesinin planlama aşaması ele alındı. Proje ekibinin aşamalara göre nasıl değiştiği, proje yöneticisi, müşteri ve kullanıcı rollerinin farkı ve proje yöneticisinin organizasyon, yönlendirme ve kontrol görevleri anlatıldı. Projelerin stratejik plan, acil ihtiyaç ya da dış etkenle başlayabileceği gösterildi. Planlama aşamasının ilk adımı olan problem tanımı RMO müşteri destek sistemi üzerinden işletme faydaları, sistem yetenekleri ve taslak veri akış diyagramıyla örneklendi.

Ardından ekonomik, kurumsal, teknik, takvim ve kaynak fizibilitesi tanıtıldı. Ekonomik fizibilitede geliştirme ve işletim maliyetleri, somut ve somut olmayan faydalar, net bugünkü değer, geri ödeme süresi ve yatırım getirisi RMO tablosu üzerinden işlendi. Son olarak proje takviminin görevlere bölünerek oluşturulması ve PERT/CPM ile Gantt şemalarıyla gösterilmesi anlatıldı. Hoca bu şemaların MS Project ile çizilmesine ve nasıl hesaplandığına sonraki derslerde uygulama çalışmasıyla devam edileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
