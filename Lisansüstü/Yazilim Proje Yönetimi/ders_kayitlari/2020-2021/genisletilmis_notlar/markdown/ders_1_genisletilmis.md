# Ders 1 Genişletilmiş Notu: Derse Giriş ve Yazılım Proje Yönetiminin Bileşenleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Yazılım Mühendisliğiyle İlişkisi
- 2. Yazılım Proje Yönetiminin Üç Bileşeni
- 3. Etkin Proje Yönetimi: 3P
- 4. Yazılım Ölçümü
- 5. İşlev Noktası (Function Point)
- 6. Maliyet Tahmini ve İnsan Kaynakları Planlaması
- 7. Proje Yönetimi Süreç Adımları
- 8. Yazılım Mühendisliği Teknikleri Proje Yönetimine Nasıl Bağlanır?
- 9. Genel Yönetim Bilgisi
- 10. Proje Yönetimi Yol Haritası
- 11. PMI, PMP ve Bilişim Projelerinin Durumu
- 12. Derste Görülecek Konular
- 13. Proje Planı, Teklif Belgeleri ve Araçlar
- 14. Alan Yazınını İzlemek

## 1. Dersin Yazılım Mühendisliğiyle İlişkisi

Hoca, bu dersin üç alanın bileşkesi olduğunu söyleyerek başladı: proje yönetimi, yazılım mühendisliği temelleri ve yönetim bilimi. Ders yazılım mühendisliğinin üzerine kuruludur. Yazılım mühendisliğinin temelleri artık bütün bilgisayar mühendisliği bölümlerinde okutulur. Bu yüzden bu bölümlerden gelenler için kavramsal zemin büyük ölçüde hazırdır, ama herkes bu kavramları farklı biçimlerde görmüş olabilir.

Başka bölümlerden gelenler için durum farklıdır. Hoca bu öğrencilerin genel bir yazılım mühendisliği kitabı edinmesini istedi ve Pressman'ın *Software Engineering* kitabını önerdi. Kavramlarda sorun yaşayan herkes bu kitabı dersle yan yana götürmelidir.

> **Hocanın vurgusu:** Bu ders yazılım mühendisliğinin üzerinde olan bir derstir. Kavramlarda eksiği olan, Pressman'ın *Software Engineering* kitabını dersin yan kitabı olarak okumalıdır.

## 2. Yazılım Proje Yönetiminin Üç Bileşeni

Yazılım proje yönetiminin üç bileşeni vardır:

- Proje yönetimi bilgi ve deneyimi
- Genel yönetim bilgisi
- Yazılım mühendisliği teknikleri

Hoca her bileşenin hangi kaynaktan besleneceğini de belirtti. Yazılım projelerinin özellikleri, yazılım mühendisliği dersinden gelen bilgilerle pekiştirilecek. Proje yönetimi bilgi ve deneyimi, genel proje yönetimi kavramlarından alınacak. Bu kısım için temel kaynak Project Management Body of Knowledge (PMBOK) olacak. Yazılım mühendisliği teknikleri ise Software Engineering Body of Knowledge (SWEBOK) kaynaklı bilgilerle karşımıza çıkacak.

<!-- BELİRSİZ: İlk slayt anlatımı ekran paylaşımı sorunu nedeniyle kesildi ve yeniden başlandı. Altyazıda yaklaşık 00:15:18-00:18:43 arasında metin yok. Birinci slaydın ayrıntıları altyazıda geçmiyor. -->

> **Ek bilgi (derste anlatılmadı):** PMBOK, Project Management Institute (PMI) tarafından yayımlanan ve proje yönetiminin genel kabul görmüş bilgi birikimini derleyen bir kılavuzdur. SWEBOK ise büyük olasılıkla IEEE Computer Society'nin yazılım mühendisliği bilgi alanlarını tanımladığı kılavuzdur. Birincisi sektörden bağımsızdır, ikincisi yazılıma özgüdür.

## 3. Etkin Proje Yönetimi: 3P

Etkin bir proje yönetimi için üç şey gerekir: insan kaynaklarını iyi yönetmek, problemi doğru anlamak ve süreci doğru yürütmek. Bu, bütün projelerin yönetimi için geçerlidir. Yazılım mühendisliği kitapları bunları 3P olarak adlandırır: insan (people), problem ve süreç (process).

### 3.1 İnsan (People)

Hocaya göre yazılım geliştirmede en önemli kaynak insan kaynağıdır. Bu başlık altında şu konular yer alır:

- Çalışanların seçimi
- Çalışanların yeteneklerinin yapacakları faaliyetlerle eşleştirilmesi
- Performans yönetimi
- Eğitim ve kariyer geliştirme
- Özellikle ekip kültürünün oluşturulması

> **Hocanın vurgusu:** Yazılım geliştirmede en fazla önemli olan insan kaynaklarıdır.

### 3.2 Problem

Proje planlaması yapılmadan önce projenin kendisi sorgulanır. Şu sorular üzerinde durulur:

- Bu projenin amacı nedir?
- Proje hangi problemi çözmek üzere belirlenmiştir?
- Alternatif çözümler nelerdir?
- Probleme özgü teknik kısıtlar var mıdır?

### 3.3 Süreç (Process)

Süreç, yazılım geliştirme sürecinin (software engineering development process) adımlarını anlatır. Bu adımlar yazılım mühendisliği dersinden bilinir: proje planlama, analiz, tasarım, gerçekleştirme ve test. Projeyi etkin yönetebilmek için bu adımlara hâkim olmak gerekir.

### 3.4 Dördüncü P

Hoca, kitapların bazen bir dördüncü P daha eklediğini söyledi. Daha genel kalmak için yalnızca bu üç temel üzerinde durdu.

> **Ek bilgi (derste anlatılmadı):** Pressman'ın kitabında yönetim yelpazesi büyük olasılıkla dört P ile anlatılır: people, product, process ve project. Burada "problem" başlığının karşılığı büyük ölçüde "product" başlığıdır.

## 4. Yazılım Ölçümü

### 4.1 Mühendislik ve Ölçme

Yazılım projelerini iyi yönetebilmek için ölçüm yapmak gerekir. Temel kavramlar yazılım mühendisliği derslerinden bilinir. Bu derste yazılım ölçümü biraz daha genişletilecek.

Yazılım mühendisliği, yazılım ürününü oluşturmaya mühendislik yaklaşımı uygulamakla ilgili teknikleri kapsar. Mühendislik yaklaşımı ise yönetme, maliyet hesabı, planlama, modelleme, analiz etme, tasarlama, gerçekleştirme ve bakım yapmayı içerir. Bu adımların hepsinde ölçme vardır. Hoca, mühendislik kelimesinin "hendese"den, yani ölçmeden geldiğini hatırlattı. Mühendislik yaklaşımında en çok öne çıkan iki işlem tasarım ve ölçümdür.

> **Hocanın vurgusu:** Yönetim konusunda her şeye şu sözle başlarız: "Ölçemediğimizi yönetemeyiz."

Yazılım ölçümü (software metrics), bu nedenle mühendislikle ilişkili temel kavramlardan biridir. Soru, ölçme işleminin yazılımda nasıl gerçekleştirileceğidir.

### 4.2 Yazılımda Ölçmek Neden Zordur?

Yazılım ürününde ölçülebilir hedef belirlemek daha zordur. Çünkü bu daha "soft" bir kavramdır. Kullanıcı bakış açısından kalite özelliklerine bakalım: kullanım kolaylığı, güvenilirlik, bakım yapılabilirlik, etkinlik. Bunların hiçbirine doğrudan bir sayısal değer veremeyiz.

Bunun iki sonucu vardır. Yazılım projelerinin gerçek maliyetini ölçmek zordur. Üretilen ürünün kalitesini ölçmek de zordur. Kalitede bu yüzden daha çok potansiyel kullanıcıların belirli bir kullanım süresinde karşılaşacağı hata olasılıkları üzerinde durulur. Kesin ölçüm sonuçları elde etmek güç olduğu için kalite hakkındaki bilgi çoğu zaman anlatım yoluyla verilir.

### 4.3 Doğrudan ve Dolaylı Ölçüm

Yazılım kalitesi ve yazılım ölçütlerinde iki tür ölçüm vardır.

- **Doğrudan ölçüm:** Bir değer doğrudan sayılarak ölçülür. Komut satırı ve hız bu türe örnektir. Bir yazılımın ne kadar büyük olduğunu anlamak için satır sayısı sayılır: "kaç bin kod satırlık bir yazılım" denir.
- **Dolaylı ölçüm:** Değer, işlev, nitelik, karmaşıklık ve etkinlik gibi özelliklerin bileşkesinden hesaplanır. Function Point bu türün ölçme birimidir. Yazılımın yaptığı işlevler, kaç veri tabanı olduğu, dosya sayısı ve arabirimler birleştirilerek bir değer elde edilir.

Bu değerler sayesinde bir projeye ne kadar gider harcanacağı konusunda tahmin yapılabilir.

<!-- BELİRSİZ: Doğrudan ve dolaylı ölçüm slaydının ilk kısmı altyazıda parçalı (yaklaşık 00:31:14-00:32:07). Slayttaki ölçüm birimlerinin tam listesi anlaşılmıyor. -->

## 5. İşlev Noktası (Function Point)

Hoca function point hesabını, yazılım mühendisliği dersinden bilindiğini varsayarak hatırlatma düzeyinde anlattı. Ayrıntısına ileriki derslerde dönülecek. Hesapta şu sayımlar kullanılır:

- Kullanıcının yazılıma yaptığı giriş sayısı
- Kullanıcının aldığı çıktı sayısı
- Sorgu sayısı
- Dosya sayısı
- Dış arabirim sayısı

Her sayım bir ağırlık faktörüyle çarpılır. Ağırlık faktörü karmaşıklığa göre değişir. Hocanın örneği dosya sayısıydı:

| Karmaşıklık | Dosya sayısının ağırlık faktörü |
|---|---|
| Basit | 7 |
| Orta | 10 |
| Karmaşık | 15 |

Function point bu sayılar ve ağırlık faktörlerinin çarpımlarının toplamından elde edilir.

<!-- BELİRSİZ: Hoca slayttaki ağırlık tablosunu gösterirken yalnız dosya sayısının ağırlıklarını söyledi. Diğer sayımların ağırlıkları altyazıda yok. Cümlenin bir kısmı da bozuk (yaklaşık 00:33:20-00:33:50). -->

> **Ders sonrası not:** Hoca ağırlığı "basit yazılım, orta karmaşıklıkta yazılım, karmaşık yazılım" diye anlattı. Standart yöntemde karmaşıklık büyük olasılıkla yazılımın bütünü için değil, sayılan her bileşen için belirlenir. Yani aynı yazılımda basit ve karmaşık dosyalar birlikte bulunabilir.

> **Ek bilgi (derste anlatılmadı):** Pressman'daki hesapta ağırlıklı sayımların toplamı önce bir ayar çarpanıyla düzeltilir: $FP = \text{sayım toplamı} \times (0{,}65 + 0{,}01 \sum_{i} F_i)$. Buradaki $F_i$ değerleri, yazılımın genel özelliklerine ilişkin soruların puanlarıdır. Ayar çarpanı sayesinde aynı sayımlara sahip iki yazılım, genel özellikleri farklıysa farklı değer alabilir.

Bu hesabın amacı maliyete ulaşmaktır. Geliştireceğimiz yazılımın büyüklüğü bilinince, bu büyüklükteki benzer yazılımlara bakılır. Onların daha önce ne kadar sürede, ne kadar maliyetle ve kaç kişinin çalışmasıyla hazırlandığı biliniyorsa, yeni proje için de bu değerler bulunabilir.

> **Hocanın vurgusu:** Function point üzerinde durmamızın sebebi maliyettir, çünkü maliyet bizim için önemlidir.

## 6. Maliyet Tahmini ve İnsan Kaynakları Planlaması

Hoca maliyet tahmin yöntemlerini de nelerle uğraşılacağını göstermek için kısaca tanıttı.

- **İstatistik modeller:** Daha önceki projelerin değerleri kullanılarak bir model geliştirilir. Yeni başlanacak projenin maliyeti bu modelle tahmin edilir.
- **Delphi yöntemi:** Birkaç uzmana soru sorularak tahmin yaptırılır.
- **Tek uzman görüşü:** Tahmin bir uzmana sorulur.
- **Bölerek tahmin:** Büyük bir yazılımın bütününe bir anda maliyet tahmini yapmak güçtür. Bu yüzden yazılım ya ürüne ya da üretim adımlarına göre bölünür. Her parçanın ne kadar zamanda ve ne kadar maliyetle gerçekleştirileceği bulunur. Örneğin yazılımın proje yönetimi, geliştirilmesi ve testinin kaç kişiyle ne kadar zamanda tamamlanacağı hesaplanır.

<!-- BELİRSİZ: Hoca istatistik modellerin önemlilerinden birini gösterirken altyazı kesiliyor (yaklaşık 00:37:28-00:37:57). Modelin adı geçmiyor. Ürüne göre bölme anlatımında da boşluk var (00:36:26-00:36:56). -->

> **Ek bilgi (derste anlatılmadı):** Delphi yönteminde uzmanların yalnızca görüşü alınmaz. Uzmanlar tahminlerini genellikle birbirinden bağımsız ve adsız verir. Sonuçlar özetlenip uzmanlara geri gönderilir ve tahminler birkaç turda birbirine yaklaştırılır. Amaç, tek bir kişinin görüşünün baskın çıkmasını önlemektir.

Proje yönetimiyle ilişkili işlemlerden biri de insan kaynakları planlamasıdır. Burada üç soru yanıtlanır: Ne kadar kişi çalışacak? Hangi türden ne kadar kişi çalışacak? Organizasyon nasıl olacak?

## 7. Proje Yönetimi Süreç Adımları

Hoca bu noktada başa döndü ve şu soruyu sordu: Yazılım mühendisliği teknikleriyle proje yönetimi tekniklerini nasıl iç içe geçiriyoruz? Önce proje yönetimi teknikleriyle ne kastedildiğini açıkladı.

Dersin bir ayağı genel proje yönetimidir. PMBOK el kitabı ve web sayfası, proje yönetim ofislerinde geçerli olan güncel kuralları ve bu kuralların nerede değiştiğini izlemeye yarar. Hangi proje yönetim süreci adımlarının uygulandığı da buradan takip edilir.

### 7.1 Başlangıç Aşaması

Proje planlanmadan önce projenin başlangıç aşamaları yapılır. Bu aşamada önce projenin yapılabilirliğine karar verilir. Şu sorular sorulur:

- Bu proje neden başlatıldı?
- Bu projeyle hangi problem çözülmeye çalışılıyor?
- Projenin yapılabilirliği nedir?
- Proje, harcamalarını ne kadar sürede karşılayabilir?
- Böyle bir projeye girmeye değer mi?

Projenin tanınması ve anlaşılması bu giriş aşamasında gerçekleşir.

<!-- BELİRSİZ: Hoca proje yöneticisinden söz ederken cümle kesiliyor (yaklaşık 00:41:19-00:41:43). Proje yöneticisinin bu aşamada belirlendiği söyleniyor olabilir; altyazıda net değil. -->

### 7.2 Planlama Aşaması

Planlama aşamasında şunlar belirlenir:

- Projenin tam olarak hangi adımlarda gerçekleştirileceği
- Projenin riskleri
- Projedeki kısıtlar
- Varsa projedeki varsayımlar
- İş adımlarına göre ne kadar ve hangi tipte insan gücü gerektiği
- Projenin yaklaşık maliyeti

Maliyeti belirlemek için PERT ve Gantt diyagramlarıyla bir zaman planı oluşturmak gerekir. Bu plan, projenin ne kadar sürede ve hangi takvim adımlarında hangi kişilerin çalışmasıyla ilerleyeceğini gösterir. İyi bir PERT analizi yapmak ve Gantt diyagramını çıkarmak, planlama aşamasının işidir ve proje yönetimi bilgi ve deneyiminin bir parçasıdır.

### 7.3 Takip Aşaması

> **Hocanın vurgusu:** Proje yönetimi demek sadece proje planlamak demek değildir.

Plan yapıldıktan sonra projenin takip edilmesi ve izlenmesi gerekir. Hoca bu aşama için project running ve project control adlarını kullandı.

> **Ders sonrası not:** Hoca project running ve project control adlarının aynı anlama geldiğini söyledi. PMBOK'ta bunlar büyük olasılıkla ayrı süreç gruplarıdır: yürütme (executing) işi yapmayı, izleme ve kontrol (monitoring and controlling) ise işin plana göre gidip gitmediğini denetlemeyi anlatır. Genel listede büyük olasılıkla beş süreç grubu sayılır: başlatma, planlama, yürütme, izleme ve kontrol, kapanış.

### 7.4 Kapanış Aşaması

Kapanış aşamasında şunlar yapılır:

- Projeden kazanımların neler olduğu belirlenir.
- Projedeki risk takibinin nasıl gittiği değerlendirilir.
- Projeden çıkan arşiv ve kazanım bilgileri kaydedilir.
- Bitmiş proje ölçülür.

Hoca, kapanışta da ölçümün yer almasının önceki bölümde ölçüm üzerinde durmasının sebebi olduğunu belirtti.

## 8. Yazılım Mühendisliği Teknikleri Proje Yönetimine Nasıl Bağlanır?

Hoca 3P başlıklarına bu kez iki alanın kesişimi açısından baktı.

**İnsan:** Yazılım mühendisliğinde hangi tür elemanların çalıştırılacağı ve bu elemanların hangi yeteneklere sahip olması gerektiği belirlenmelidir. Yazılım mühendisliği ile proje yönetiminin iç içe geçtiği noktalardan biri budur.

**Süreç:** Süreç adımları yazılım mühendisliğinden gelir: planlama, gereksinim analizi (requirement engineering), tasarım (design). Proje yöneticisinin şu soruları cevaplaması gerekir:

- Her adımda hangi işler gerçekleştirilir?
- Bu işlerin genel yazılım geliştirme içindeki yeri ve önemi nedir?
- Bu adımda hangi tip kişiler, yüzde kaç oranla çalışır?

Böylece yazılım mühendisliğinin süreç adımları proje yönetimiyle eşleştirilmiş olur.

**Problem:** Fizibilite analizi burada ortaya çıkar. Fizibilite analizi iyi yapıldı mı? Alternatif çözümler değerlendirildi mi? Amaç oluşturuldu mu? Her aşamadaki teknik ve yönetim kısıtları belirlendi mi?

## 9. Genel Yönetim Bilgisi

### 9.1 Proje Yöneticisinin Konumu

Hoca genel yönetim biliminin bu dersle ilişkisini proje yöneticisinin konumundan yola çıkarak açıkladı. Proje yöneticisi çok fazla yetkisi olmayan, ama sorumluluğu olan bir yöneticidir. Yetkisinin sınırlı olmasının sebebi, kaynakları üst yönetimden almak zorunda olmasıdır. Harcama yetkisi, çalışanların seçilmesi ve kullanılması buna örnektir. Bunlar kurumdan kuruma ve projeden projeye değişir, ama genel yöneticiden farkı genel olarak budur.

### 9.2 Ekip Yönetimi ve Üst Yönetimle İletişim

Genel yönetim bilgisi önce proje ekibi içinde devreye girer. İnsan kaynaklarında ekip kültürü geliştirme, organizasyon ve iş tasarımı konuları vardır. Genel yönetim biliminde de ekibin yönetimi, organizasyonun iyi kurulması, yetenek takibi yapılarak iş bölümünün aktarılması konuları vardır. İki alan bu noktada iç içe geçer.

İkinci önemli konu, proje çıkarları için temel yönetim kademeleriyle iletişimdir. Proje yöneticisi hangi adımda nasıl davranacağını ve hangi taktiği geliştireceğini bilmek için de genel yönetim bilgisine ihtiyaç duyar. Süreç adımları işlenirken toplantı yönetimi ve yazışmaların yönetimi gibi konularda yönetim bilimine de referans verilecek.

### 9.3 Dış Taraflar, Müşteri ve Kullanıcı

Projenin gerçekleştirilmesi için dış taraflarla da ilişki kurulur. Hoca burada dış tedarikçileri, ürün alınan firmaları ve ürünün potansiyel kullanıcılarını saydı.

> **Ders sonrası not:** Hoca potansiyel kullanıcıları da dış tedarikçiler başlığı altında saydı. Kullanıcılar tedarikçi değildir; kastedilen büyük olasılıkla genel olarak dış paydaşlardır.

Müşteri ve kullanıcının kim olduğu, yazılımın kime geliştirildiğine göre değişir:

- **Başka bir şirkete geliştirildiğinde:** Karşı şirketteki kişiler müşteri tarafıdır.
- **Aynı kurum içinde başka bir departmana geliştirildiğinde:** O departmanın yönetim ekibi müşteri tarafıdır, çalışanları ise sistemin kullanıcılarıdır.

Bu kişilerle de yönetim ilkeleri çerçevesinde iletişim kurulması gerekir.

### 9.4 Soru-Cevap: Genel Yönetim Bilimine Ağırlık

**Soru:** Bilgisayar ve yazılım mühendisliği kavramlarını lisansta çoğunlukla görüyoruz, ama genel yönetim bilimi ve proje yönetimi konusunda teorik bilgimiz yeterli olmuyor. Derste genel yönetim bilimine daha fazla ağırlık verilebilir mi?

**Cevap:** Evet. Hoca bunun eksik bir konu olduğunu kabul etti. Mezunların çalıştığı kurumlar da mezunların iş hayatıyla ilgili bilgi konusunda daha fazla desteklenmesi yönünde geri bildirim veriyor. Daha önce programlarda işletme dersi vardı. Şimdi saat kısıntısı ve bilgisayar mühendisliğindeki açılımlar yüzünden bu bilgi ancak üniversite seçimlik dersleriyle alınabiliyor.

Hoca, bu bilginin neden gerektiğini yönetim bilgi sistemleri derslerinde de söylediğini belirtti. Bilgi sistemi veya yazılım firmasında çalıştığınızda, geliştirdiğiniz sistemin kullanıcıları işletmelerin içindeki çalışanlardır. Dolayısıyla oradaki işleyişi bilmek gerekir. Süreçler, departmanlar arası ilişkiler ve iletişim açısından bu bilgiye ihtiyaç vardır. Hoca bu konulara ağırlık vermeye çalışacağını söyledi.

## 10. Proje Yönetimi Yol Haritası

Hoca dersin işleneceği çerçeveyi proje yönetimi yol haritası (project management roadmap) olarak adlandırdı. Harita daha önce anlatılan adımlardan oluşur:

1. **Projenin tanımlanması ve anlaşılması (project defining, project understanding)**
2. **Proje planlaması:** Daha çok proje teknikleri kullanılır. Yönetim kademeleriyle ilişkilerden de söz edilecek.
3. **Projenin çalıştırılması (project running)**
4. **Projenin kapatılması**

Proje ofisleri de bu işleri bazen dört adımda toplar:

1. Projeye giriş
2. Proje planlama
3. Projenin çalıştırılması ya da projenin kontrol edilmesi ve izlenmesi: Çalışma sırasında plana göre gidilip gidilmediği izlenir.
4. Proje bitince projenin kapatılmasıyla ilgili işlemler

<!-- BELİRSİZ: Hocanın sesi kesildiği için yol haritası slaydına geçiş altyazıda yok (yaklaşık 00:55:11-00:56:20). "Üçlü" olarak nitelediği yapının ne olduğu anlaşılmıyor. -->

## 11. PMI, PMP ve Bilişim Projelerinin Durumu

### 11.1 PMI ve PMP Sertifikası

Hoca, iş hayatındakilerin duymuş olabileceği bir kurum olarak Project Management Institute'u (PMI) andı. PMI'ın verdiği sertifikalardan biri PMP'dir. PMP sertifikası, proje yönetimi konusunda uzman olduğunuzu gösterir.

Yalnızca eğitim almak bu sertifika için yeterli değildir. Kaç projede ve hangi işlerde çalışıldığı da sorulur, ayrıca sınavı vardır. PMI'ın uzaktan verdiği eğitimler vardır. Böyle bir ders almış olmak da sertifika başvurusunda eğitim olarak gösterilebilir. Derste bir öğrenci, proje yöneticiliği için ayrıca saat şartı bulunduğunu dile getirdi.

<!-- BELİRSİZ: Öğrencinin söylediği saat değeri altyazıda anlaşılmıyor (yaklaşık 01:17:04). -->

> **Ders sonrası not:** Derste "PMBOK sertifikası" ifadesi geçti. PMBOK bir bilgi kılavuzudur, sertifika değildir. Kastedilen büyük olasılıkla PMI'ın PMP sertifikasıdır.

Hoca ayrıca proje yönetim ofislerinden (project management office) ve PMI'ın Türkiye'deki yapısından söz etti.

<!-- BELİRSİZ: Hocanın PMI'ın Türkiye'deki temsiliyetine ve "Uluslararası Proje Yönetim Derneği"ne ilişkin cümlesi yarım kalıyor (yaklaşık 00:59:50-01:00:19). -->

### 11.2 Bilişim Projeleri Neden Kritiktir?

Proje yönetimi kavramlarına inşaat mühendisleri de önem verir. Ancak hoca, bu organizasyonun toplantılarında ağırlıklı olarak bilişim alanındaki proje yöneticilerini gördüğünü söyledi. Sebebi şudur: Bilişim projeleri daha kritiktir. Hem maliyetlidir hem de sonucuna ulaşmak daha zordur. Yakın zamana kadar sonuçları çok başarılı gitmemiştir. Bu yüzden bu alandaki proje yöneticilerinin daha fazla eğitim alması ve şirketlerin bu konu üzerinde daha fazla durması gerekli görülmüştür.

Standish Group'un değişik yıllarda yaptığı çalışmalar, tamamlanmamış, bitmemiş ve başarısız projeler olduğunu göstermiştir. Hoca, son yıllarda hem yazılım mühendisliğine hem yazılım proje yönetimine verilen önemle durumun birçok kurumda daha olumlu hale geldiğini gözlemliyor.

### 11.3 Çevik Projeler İçin Sertifika

Son yıllarda çevik (agile) projeler çok arttığı için, bu alanda uzmanlığı gösteren ayrı bir sertifika da alınabiliyor.

> **Ders sonrası not:** Hoca sertifikanın adını söylemedi. Kastedilen büyük olasılıkla PMI'ın PMI-ACP sertifikasıdır.

## 12. Derste Görülecek Konular

Hoca bu dersin amacının dersin genel yapısını anlatmak olduğunu, bu amaçla ölçüm tarafına da girdiğini söyledi. Anlatılanların hepsi ileride ayrıntılı görülecek. Ders boyunca işlenecek başlıklar şunlardır:

- Proje nedir, ne değildir?
- Yazılım projeleri dışında genel proje yönetimi nedir?
- Genel proje yönetiminde kullanılan teknikler ve araçlar
- Bilgi sistemleri ve proje yönetimi kitapları referans alınarak yol haritasının her adımında neler yapıldığı
- Bu adımların yazılım projesi örnekleri ve yazılım mühendisliği kavramlarıyla pekiştirilmesi
- Yazılım ölçümü
- Maliyet tahmin yöntemleri
- Yazılım risk yönetimi
- Konfigürasyon yönetimi ve sürüm yönetimi (release management): Bunlar kalite ile proje yönetiminin ikisinde de öne çıkan konulardır.

## 13. Proje Planı, Teklif Belgeleri ve Araçlar

### 13.1 Proje Yönetim Araçları

Proje yönetimi teknikleri bir proje yönetim programıyla uygulanır. Hoca bu konuda iki tür aracı ayırdı. Trello'da daha çok çevik yaklaşımda yazılım geliştirme sürecinin adımları izlenir: analizden tasarıma geçiş gibi. MS Project benzeri bir ürün ise daha çok planlama sırasında kullanılır, takip aşamasında da kullanılabilir.

### 13.2 Soru-Cevap: Proje Planlama Çalışmasının Çıktısı

**Soru:** Bir yazılım projesini planlama ve takip etme çalışmasının çıktısında hangi belgeler olur? Yazılım mühendisliği çalışmasındaki SRS gibi bir belge söz konusu mu?

**Cevap:** Çıktı bir proje teklifi olabilir ve tek bir standarda uymak zorunda değildir. Hocanın saydığı örnekler şunlardır:

- Bir bitirme projesinin destek alarak geliştirilmesi için TÜBİTAK'a hazırlanan teklif
- Bir şirkette başlayacak bir projenin, proje ekibi de tanımlanarak hazırlanan planı
- Yüksek lisans tezi için BAP'a verilecek teklif
- Sanayi Bakanlığı'na hazırlanan proje teklifi

BAP tekliflerinde genelde yalnızca bir Gantt şeması istenir. Hoca burada planlama tarafının genişletilmesi gerektiğini belirtti. Proje plan dokümanında neler olması gerektiği derste verilecek. SRS için IEEE'nin tanımladığı adımlar olduğu gibi, proje planlama için de IEEE'nin bir standardı vardır.

### 13.3 Soru-Cevap: Proje Büyük Olmak Zorunda mı?

**Soru:** Proje yönetimi çalışmasında proje daha büyük ve karmaşık olmak zorunda mı?

**Cevap:** Hayır. Bu, çalışılan yere ve yapılan işe göre değişebilir. Profesyonel bir projeyi simüle etmek şart değildir. Hocanın örneği şuydu: Büyük bir proje olmayan bir bitirme projesini start-up olarak geliştirmek istiyorsunuz. Bu durumda da proje adımları yazılır ve maliyet tahmini yapılır. Risk yönetimi, pazar tahmini, projenin kimlere satılabileceği ve ne kazandırabileceği de ele alınır. Küçük bir proje böylece geliştirilerek uygulama örneği olabilir.

## 14. Alan Yazınını İzlemek

Hoca alandaki güncel çalışmaları izlemek için kütüphanenin uzaktan erişimli süreli yayınlarını önerdi. Saydığı kaynaklar şunlardır:

- **IEEE Software:** Genel ve güncel makaleler için iyi bir başlangıçtır.
- **IEEE Transactions on Software Engineering**
- **IEEE'nin Engineering Management dergisi:** Genel proje yönetimi makaleleri içerir.
- **Proje yönetimi ve proje ölçümüyle ilgili konferanslar**

Hoca, genel proje yönetiminden çok yazılım ve bilişim projeleriyle ilgili çalışmalara bakılmasını istedi. Eleman seçimi gibi konuların anlatıldığı çalışmalar yerine şu soruyu ele alan çalışmalar aranmalıdır: Yazılım proje yönetiminde yapay zekâ aracılığıyla, ya da bilgisayar mühendisliğindeki diğer yeni yaklaşımlarla nasıl ilerlemeler sağlanabilir?

## Dersin Toparlaması

Bu derste yazılım proje yönetiminin üç bileşeni tanıtıldı: proje yönetimi bilgi ve deneyimi (PMBOK), yazılım mühendisliği teknikleri (SWEBOK) ve genel yönetim bilgisi. Etkin proje yönetimi insan, problem ve süreç başlıklarıyla ele alındı. "Ölçemediğimizi yönetemeyiz" ilkesinden yola çıkılarak doğrudan ve dolaylı ölçüm, function point ve maliyet tahmin yöntemleri kısaca görüldü. Proje yönetiminin yalnızca planlama olmadığı, başlangıç, planlama, takip ve kapanış adımlarından oluşan bir yol haritası izlediği gösterildi.

Sonraki derste tam olarak konuya girilecek: Proje nedir? Neler projedir, neler değildir? Proje başarı faktörleri nelerdir, yani bir projeye başarılı demek için ne gerekir? Ardından proje yönetimi yol haritasının adımları tanıtılacak.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
