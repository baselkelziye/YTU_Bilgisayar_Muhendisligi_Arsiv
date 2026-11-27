# Ders 13 Genişletilmiş Notu: Proje Sunumlarının Devamı ve Dönemin Toparlanması

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin yapısı
- 2. Restoran müşteri takip sistemi: salgın senaryosu, aktörler ve teknoloji seçimi
- 3. Kızılay bağış takip bilgi sistemi: fizibilite matrisi, düzeyli veri akış diyagramları, veri tabanı
- 4. Madencilik izleme uygulaması: ekonomik fizibilite, ön ve arka yüz UML'i, kullanım senaryosu düzeltmesi
- 5. Okul servisi yönetim sistemi: teknik ve ekonomik fizibilite, veri sözlüğü
- 6. Maç bileti satış sistemi: toplantı raporları, bağlam diyagramı, HES kodu simülasyonu
- 7. Üniversite kampüs bilgi sistemi: modüller, ardışıl diyagram, arayüz geri bildirimleri
- 8. Hastane bilgi sistemi: değişen müşteri isteği, ikinci düzey veri akış diyagramı
- 9. Dönemin toparlanması
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin yapısı

Bu ders dönemin son kaydıdır ve bir önceki derste başlayan dönem projesi sunumlarının devamıdır. Yeni bir teori konusu anlatılmadı; kalan gruplar geliştirdikleri bilgi sistemlerini sundu. Sunumların çoğu dönem boyunca işlenen sistem geliştirme sürecini izledi: müşteri görüşmesi ve isteklerin belirlenmesi, ekip yapısı ve roller (proje yöneticisi, sistem analisti, tasarımcı, yazılımcı, müşteri rolü), fizibilite çalışması, Gantt diyagramıyla zaman planı, analiz modelleri (veri akış diyagramları, kullanım senaryoları, veri sözlüğü), tasarım modelleri (yapı diyagramı, sınıf diyagramı, ardışıl diyagram, ER diyagramı) ve çalışan uygulamanın gösterimi.

Hoca sunumların arasında ve sonunda kısa geri bildirimler verdi. Bu notta her sistemin dersle ilgili kısmı, ekranda gösterilen diyagramlar ve hocanın düzeltmeleri sırayla verilir. Hocanın genel bir uyarısı da sunumun biçimiyle ilgiliydi: sunum raporun satır satır okunması değildir; ayrıntılı hesaplar raporda kalır, sunumda süreç ve sistemin temel özellikleri anlatılır.

## 2. Restoran müşteri takip sistemi: salgın senaryosu, aktörler ve teknoloji seçimi

### 2.1 Problem

İlk sunulan sistem, salgın döneminde restoranların müşteri takibini amaçlıyordu. Grup, iç mekânları üç türe ayırdı: iş yeri, toplu taşıma ve restoran. İş yerinde herkes birbirini tanıdığı için takip kolaydır; toplu taşımada maske zorunluluğu uygulanabilir. Restoranda ise müşteriler birbirini tanımaz, yemek yerken maske takılamaz ve masalar arası mesafe işletmeye kalmıştır. Bir slaytta öksürük, hapşırık ve nefesle yayılan damlacık ve aerosollerin mesafeleri gösterildi (ekrandan, 00:05:00). Grubun hedefi bulaşmayı önlemek değil, en azından "kim hangi restoranda kimle aynı anda bulundu" verisine sahip olmaktı. İç mekânda bağıl nem ve karbondioksit derişiminin izlenmesinin de önemli olduğu, yüksek karbondioksitin ortamda çok insan bulunduğunu gösterdiği anlatıldı.

### 2.2 Teknoloji seçimi ve aktörler

Grup sistemi tek bir bilgisayara bağlı kalmasın diye bulut tabanlı geliştirdi ve yayın için bir bulut barındırma hizmeti seçti. İki teknoloji yığını araştırıldı: MongoDB, Express, React ve Node'dan oluşan yığın ile Spring tabanlı Java. Bir noktadan sonra bir üst yönetim bölümü gerektiği için ikisi birlikte kullanıldı; yönetim bölümü Spring ile yazıldı. Geliştirme ortamında Tomcat sunucusu, Spring giriş sayfası ve konsolda Hibernate'in ürettiği SQL sorguları görünüyordu (ekrandan, 00:10:00).

Üst yönetim bilgi sistemi için üç aktör tanımlandı:

- Yönetici: her şeyi görebilir, bütün sayfalara erişir; müşteri izleme kısmına girip müşteri ekleyebilir ve arama yapabilir.
- Müşteri izleyen kişi: müşterilerle iletişim kuran, rezervasyonları tutan kişi; yalnız ilgili sayfaları görür.
- Çalışan: yalnız ana sayfayı görebilir.

Müşteri tarafında kullanıcı adı, şifre ve HES koduyla kayıt olunur ve giriş yapılır. Restoranlar bir harita servisinde konumlarıyla gösterilir; restoran sayfasında kapasite ve çalışma saatleri gibi bilgiler ile değerlendirme bırakma vardır.

## 3. Kızılay bağış takip bilgi sistemi: fizibilite matrisi, düzeyli veri akış diyagramları, veri tabanı

### 3.1 Sistemin amacı ve aşamalar

Slayttaki tanıma göre sistem, "Türkiye'nin her yerinden yapılan bağışların kolayca kayıt altına alınması ve takip edilmesi amacıyla Kızılay çalışanlarına yönelik oluşturulmuş bir sistemdir" (ekrandan, 00:15:00). Proje beş aşamada yürütüldü: ön inceleme, analiz, tasarım, gerçekleştirme ve test etme. Ön incelemede ekip üyeleri sırayla müşteri (kurum temsilcisi) rolüne girip istek ortaya koydu, diğerleri çözüm üretti. Belirlenen amaçlar: kan bağışı, ayni ve nakdi bağışların alınması; bağışlanan kanın hangi şehirde, hangi hastanede ve ne miktarda olduğunun takibi. Ekip uzmanlıklara göre bölündü; en uzun ve zor süreç tasarım olduğu için en çok kişi tasarıma verildi.

### 3.2 Zaman fizibilitesi ve fizibilite matrisi

Zaman fizibilitesinde her ekip üyesi her aşama için en çok ve en az gün tahmini verdi; en iyi ve en kötü durumlar değerlendirilerek aşamaların ortalama süresi bulundu. Bu tahminlerle kurulan Gantt diyagramına göre proje 33 günde bitirilecekti.

Fizibilite matrisinde üç alternatif karşılaştırıldı:

- Önerilen sistem 1: C# ve macOS. Ekibin C# bilgisi yetersiz olduğu için zaman ve maliyet sorunu çıkacak, macOS donanım masrafı doğuracaktı.
- Önerilen sistem 2: MySQL veri tabanı. Gelişmiş sürümleri için satın alma maliyeti vardı.
- Önerilen sistem 3: ekibin bildiği bir dil ve tamamen ücretsiz olan PostgreSQL; yalnız Windows ve sunucu maliyeti doğuruyordu. <!-- BELİRSİZ: üçüncü alternatifin programlama dili altyazıda bozuk ("İnden bir dil"); uygulama arayüzü Java Swing'e benziyor ama karede dil adı okunmuyor. -->

Teknik, sosyal, ekonomik ve zaman fizibilitelerine yüzde ağırlıklar verilerek her alternatif puanlandı ve en yüksek puanı alan üçüncü sistem seçildi.

> **Ek bilgi (derste anlatılmadı):** Ağırlıklı fizibilite matrisinde her ölçütün ağırlığı $w_i$ ve alternatifin o ölçütteki puanı $p_i$ ise toplam puan $\sum_i w_i p_i$ olur. Ağırlıkların toplamı genelde %100 alınır. Böylece "teknik açıdan iyi ama pahalı" gibi çelişen ölçütler tek bir sayıda birleştirilir.

### 3.3 Veri akış diyagramları

Analizde üç düzeyde veri akış diyagramı çizildi. Bağlam düzeyinde çalışan, bağışçının bilgilerini alıp bağış kaydı oluşturur ve yeni çalışan kaydı yapar. Birinci düzey diyagram ekranda şöyleydi (ekrandan, 00:20:00):

- Dış varlıklar: Bağışçı, Çalışan, Yeni Çalışan.
- Veri depoları: D1 Üyeler, D2 Çalışanlar, D3 Bağışlanan kanlar, D4 Giysiler, D5 Erzaklar, D6 Hizmetler, D7 Maddi bağışlar.
- İşlemler ve akışlar:
  - 1.0 Bağışçı ve Bağış Bilgileri Alma: Bağışçı'dan "bağışçı ve bağış bilgileri" alır, Çalışan'a iletir.
  - 2.0 Üye Ekleme: Çalışan'dan "bağışçı bilgileri" alır, "üye bilgileri"ni D1'e yazar.
  - 3.0 Kan Bağışı Alma: "kan bilgileri"ni D3'e yazar.
  - 4.0 Ayni Bağış Alma: "ayni bağış bilgileri"ni D4, D5, D6'ya yazar.
  - 5.0 Nakdi Bağış Alma: "nakdi bağış bilgileri"ni D7'ye yazar.
  - 6.0 Bağış Görüntüleme: D3, D4, D5, D6, D7'den kan, giysi, erzak, hizmet ve maddi bağış bilgilerini okuyup Çalışan'a "bağış bilgileri" verir.
  - 7.0 Kan Bağışı Takibi: Çalışan'dan "bağışçı TC kimlik numarası" alır, D3'ten bilgileri okur, "bağışlanan kanların konumu"nu döndürür.
  - 8.0 Kan Nakletme: Çalışan'dan "nakil bilgileri" alır, D3'ten "uygun kanlar"ı okur, "nakledilen kanların yeni konumu"nu D3'e yazar.
  - 9.0 Çalışan Silme, 10.0 Yeni Çalışan Ekleme, 11.0 Yeni Çalışan Bilgileri Alma: D2 Çalışanlar üzerinde çalışır.

İkinci düzeyde birinci düzeydeki bazı işlemler açıldı: 6.0 Bağış Görüntüleme üç ayrı bağış görüntülemeye, 2.0 Üye Ekleme kendi içinde üye kontrolüne, 4.0 Ayni Bağış Alma giysi, erzak ve hizmet bağışına ayrıldı. Kullanım senaryosu diyagramında birincil aktör Kızılay çalışanıdır ve sistemdeki her işleme erişir; veri tabanı da sistemle ilişkili bir öğe olarak gösterildi.

Diyagramdaki okların "Kan bilgileri", "Nakil bilgileri", "Bağışçı TC kimlik numarası" gibi veri adı taşıması, bir önceki derste vurgulanan "oklar eylem değil veri taşır" kuralına uyan bir örnektir.

### 3.4 Tasarım

Tasarımda önce yapı diyagramı çizildi: sistemin alt sistemleri, işlevleri, girdileri ve çıktıları gösterildi. Örneğin giriş ekranına kullanıcı adı ve şifre girdi olarak verilir, giriş ekranından onay ya da red bilgisi döner; onaylanırsa ana ekrana gidilir, onaylanmazsa programdan çıkılır. UML diyagramında akış şöyleydi: `main` metodu giriş ekranını açar; kullanıcı adı ve şifre yanlışsa program sonlanır, doğruysa bir pencere (frame) oluşturulur, ana ekran ve ana menü açılır. Ana menü bütün seçenekleri ekranın solunda listeler; seçilen işlem için program ilgili sınıfa yönlenir ve o sınıf gerekli arayüz öğelerini ekranın sağında oluşturur. Ardışıl diyagram da aynı sırayı (main, giriş ekranı, pencere, ana menü, bağış ekleme ekranları) gösterdi.

### 3.5 Veri tabanı, gerçekleştirme ve test

ER diyagramında güçlü ve zayıf varlıklar ile ilişkiler gösterildi, öznitelikler ayrıca tablo halinde verildi. Tasarım kararları:

- Kurum bütün bağışların tek ve eşsiz bir bağış numarasıyla tutulmasını istediği için bağışlar tablosunda bağış numarası vardır. Bu numara veri tabanındaki bir sequence (otomatik arttırıcı) ile üretilir; kullanıcı numara girmez.
- Bağışçılar tablosunun birincil anahtarı TC kimlik numarasıdır, çünkü herkesin tek ve farklı bir TC numarası vardır. Bağış kayıtları bu numarayı yabancı anahtar olarak alır.
- Kan, nakdi, ayni gibi bağış türlerinin kendine özgü öznitelikleri olduğu için her biri ayrı tabloda tutulur ve bağışlar tablosundaki bağış numarasını yabancı anahtar olarak alır.
- Kullanıcılar tablosu sisteme giriş için kullanıcı adı ve şifreyi tutar.

Gerçekleştirme aşamasında arayüz kodlandı ve veri tabanı oluşturuldu. Test aşaması iki katmanlıydı: kodlamayla birlikte test başladı, olası senaryolar çıkarılıp test edildi, sonra sistem müşteri tarafından test edildi (ekrandan, 00:25:00); ekipte her üye sırayla müşteri rolüne girip bütün fonksiyonları denedi.

Gösterimde uygulamanın menüsü bağışçı/gönüllü kaydı, bağış kaydı (kan, nakdi, erzak, kıyafet, hizmet), stok bilgileri, kan nakli, bağış takip sistemi ve personel kaydı bölümlerinden oluşuyordu. TC kimlik numarası 11 hane girilmezse hata verilir. Kan nakli ekranında kan grubu B Rh(-), kan türü tam kan, 4 ünite, mevcut şehir Çankırı, gelecek şehir Ankara seçildi (ekrandan, 00:30:00). Çankırı'da bu kandan 3 ünite olduğu için sistem "yeterli miktarda yok" uyarısıyla eldeki 3 üniteyi nakletti ve ilgili bağışın konumu Ankara olarak güncellendi. Bağış takip ekranında bir kişinin bağışının hangi şehirde, kaç ünite ve hangi tarihte olduğu görülebiliyordu.

## 4. Madencilik izleme uygulaması: ekonomik fizibilite, ön ve arka yüz UML'i, kullanım senaryosu düzeltmesi

### 4.1 Müşteri isteği ve fizibilite

Bu grup, müşteri görüşmesini video olarak hazırlamıştı. Müşteri rolündeki kişi kripto para madenciliği yapan sistemlerin sürekli yüksek performansla çalıştığı için ömrünün kısaldığını, sistemin başında sürekli bekleyemeyeceğini söyleyerek şu istekleri belirtti: sıcaklık ve hız değerlerini uzaktan izleyebileceği bir mobil uygulama ve cüzdan bilgisini kontrol edebileceği bir eklenti.

Fizibilite dört başlıktaydı:

- Yazılım fizibilitesi: Python, Android Studio, Flutter, Firebase, Visual Studio Code ve Windows 10.
- Donanım fizibilitesi: test ve geliştirme için iki bilgisayar; biri ekran kartı sayesinde madencilik makinesi (rig) olarak da kullanıldı.
- Yasal fizibilite: Visual Studio Code ve Android Studio ücretsizdir; işletim sistemi lisansı satın alındı.
- Ekonomik fizibilite: çalışan giderleri tablosu (ekrandan, 00:35:00).

| Çalışan unvanı | Çalışan sayısı | Aylık maaş |
|---|---|---|
| Yazılımcı | 2 | 1 ETH |
| Sistem analisti | 2 | 1 ETH |
| Proje müdürü | 1 | 2 ETH |

Tablodaki maaşların kişi başı olduğu varsayılırsa aylık toplam gider $2\cdot 1 + 2\cdot 1 + 1\cdot 2 = 6$ ETH olur (ara adım eklendi). İş gücü ve zaman planında analiz (veri bulma, inceleme, algoritma araştırması), tasarım (kolay kullanılır arayüz), geliştirme ve test (çıktıların kontrolü, hataların düzeltilmesi) aşamaları vardı; her sürecin sonunda toplantı yapıldı ve proje Gantt diyagramına göre 38 günde bitti.

### 4.2 UML ve diğer diyagramlar

Ön yüz UML'inde üç ana sınıf vardı: PoolStats, User ve MinerStats. User sınıfı Firebase ile iletişim kurarak kayıt olma ve giriş yapma işlemlerini sağlar; PoolStats ve MinerStats, Python ile yazılmış arka yüze bağlanıp girdi ve çıktıları sağlar. Arka yüz UML'inde de üç sınıf vardı: ön yüze bilgi veren fonksiyonları içeren main sınıfı, IP, kimlik ve port bilgisini alıp işlem yapan Miner sınıfı ve madencilik havuzunun API'sinden gelen verileri işleyip main sınıfına aktaran Wallet sınıfı.

Grup ayrıca veri akış diyagramı (kullanıcının isteklerinin izlediği yollar ve döngüler), kullanım senaryosu diyagramı, ER diyagramı ve ardışıl diyagram çizdi. Ardışıl diyagram kullanıcının gönderdiği verinin Firebase sunucusu, web sunucusu, veri tabanı, havuz sunucusu ve madencilik makinesi arasındaki iletimini ve bu sırada çalışan fonksiyonları gösteriyordu.

### 4.3 Uygulama

Uygulamanın işlevleri beş modüle ayrıldı: kullanıcı işlemleri, madencilik sistemi tanımlama, sistem takip ve kontrol, gelir-gider verileri, analiz ve raporlama. Sistem tanımlamada IP, port ve sistem adı girilir; gösterimde yerel makine ve 3333 numaralı port kullanıldı. Ön yüz bu parametrelere eşsiz kullanıcı kimliğini de ekleyip arka yüze gönderir. Böylece her kullanıcı yalnız kendi sistemlerini ve kendi cüzdanını görür, kullanıcıların sistemleri birbirine karışmaz. Takip ekranında ekran kartı, hash hızı, güç tüketimi, sıcaklık ve çalışma süresi gösterilir.

Gelir-gider ekranında ortalama ve anlık hash hızı, günlük kazanılan ETH, günlük, haftalık ve aylık dolar kazancı, havuzdan çekilen performans grafiği ve güncel ETH fiyatı vardı (ekrandan, 00:40:00). Ekrandaki değerler: günlük 0,0704 ETH, ETH fiyatı 2408,44 \$, günlük 169,49 \$, haftalık 1186,43 \$, aylık 5084,70 \$. Haftalık ve aylık değerler günlük kazancın 7 ve 30 katıdır: $169{,}49 \cdot 7 = 1186{,}43$ ve $169{,}49 \cdot 30 = 5084{,}70$ (python ile doğrulandı). $0{,}0704 \cdot 2408{,}44 \approx 169{,}55$ olup ekrandaki 169,49'dan küçük bir farkla ayrılır; büyük olasılıkla ekrandaki ETH miktarı yuvarlanmış gösterilmektedir.

### 4.4 Hocanın kullanım senaryosu düzeltmesi

Hoca videoyu bölmemek için sunum sonunda şu düzeltmeyi yaptı: kullanım senaryosu diyagramı hiyerarşik elipslerden oluşan, bütün senaryolar tek bir senaryodan türüyormuş gibi bir yapıda çizilmişti. Senaryolar sistemde yapılacak işlerdir (cüzdan ekleme gibi). Bunların hepsi giriş yapmayı gerektiriyorsa giriş kullanım durumu `include` ile bağlanır; hepsinin ondan türediği gösterilmez.

> **Hocanın vurgusu:** Ortak bir ön koşul olan giriş adımı kullanım senaryosu diyagramında `include` ilişkisiyle gösterilir, hiyerarşik bir ağaç gibi çizilmez.

## 5. Okul servisi yönetim sistemi: teknik ve ekonomik fizibilite, veri sözlüğü

### 5.1 Problem

Öğrencilere okul servisi hizmeti veren bir firma büyüdükçe öğrenci, servis ve şoför bilgilerinin kontrolü ve ödemelerin elden alınması zorlaşıyor. Sistemle öğrencilerin çevrim içi kayıt ve ödeme yapması, servislerin, çalışanların, durakların ve güzergâhların kolayca düzenlenip saklanması hedeflendi. Sistem ağırlıklı olarak yönetim kademesine hizmet eden bir bilgi sistemidir.

### 5.2 Fizibilite

Teknik fizibilite tablosu raporda şöyleydi (ekrandan, 00:45:00):

| Teknik fizibilite | 1. alternatif | Avantajları | Dezavantajları | 2. alternatif | Avantajları | Dezavantajları | Seçilen |
|---|---|---|---|---|---|---|---|
| İşletim sistemi | Windows | Kullanışlı | - | macOS | Hızlı | Kullanılması düşünülen bazı programları desteklemiyor | Windows |
| Yazılım dili | C# | Ekip tarafından biliniyor | - | Java | Pratik | Eğitim ihtiyacı oluşturuyor | C# |
| Geliştirme ortamı | Visual Studio | Kullanıldığı için alışılmış arayüz | Bazı işlemler ücret gerektiriyor | MonoDevelop | Her işletim sistemine uygun | Ekip aşina değil | Visual Studio |
| Veri tabanı | Access Database | Basit ve kullanışlı | - | MySQL | Açık kaynak | Kullanımı daha karmaşık | Access Database |

Ekonomik fizibilitede proje süresi 2 ay alındı. Raporda birinci senaryo için ortalama maliyeti 7000 TL olan 4 bilgisayar, 2 aylık 1320 TL'lik veri tabanı lisansı ve kişi başı aylık 4500 TL maaş yazıyordu; çalışanlar evden çalışacağı için ofis masrafı yoktu ve toplantılar ücretsiz bir görüntülü görüşme programıyla yapılacaktı. Toplam yatırım maliyeti 47.320 TL'dir (ekrandan, 00:45:00). Görünen kalemler $4 \cdot 7000 + 1320 = 29.320$ TL eder; kalan $18.000$ TL personel giderine karşılık gelir (ara adım eklendi). <!-- BELİRSİZ: personel sayısı ve maaşın kaç ay için hesaplandığı karede görünmüyor; 18.000 TL = 4500 TL x 4 kişi-ay. --> İkinci senaryonun maliyeti 49.384 TL olarak söylendi. Ardından beklenen gelir ve gelir artışı, her senaryo için net bugünkü değer, iç verim oranı, başa baş noktası grafiği ve geri ödeme süreleri hesaplandı.

Zaman fizibilitesinde proje 2 ayda tamamlanacak biçimde Gantt diyagramıyla planlandı. Sosyal fizibilitede öğrencilerin güzergâh bilgisine kolay erişmesi ve kolay kayıt, şirket yönetiminin de düzenli veri tutması fayda olarak sayıldı. Yasal fizibilitede sistemin kişisel bilgiler kullanacağı, bunun için izin alınacağı ve kullanılan ürünlerin lisanslı olacağı belirtildi. Fizibilite matrisinde iki senaryo ölçütlere göre oranlandı ve birinci senaryo ağır bastı.

### 5.3 Analiz: veri toplama, kullanım senaryosu, veri sözlüğü

Analizde önce firmanın gereksinimleri tanımlandı, ardından neyin gerektiğini netleştirmek için 10 soruluk kısa bir anket yapıldı. Kullanım senaryosu diyagramında iki aktör vardı:

- Yönetici: servis, durak, durak bölgesi, çalışan ve güzergâh işlemleri (her biri ekleme, güncelleme, silme); öğrenci onaylama; ödeme bilgisi görüntüleme; iletişim bilgilerini düzenleme.
- Öğrenci: kayıt başvurusu ve ödeme yapma.

Her kullanım durumu için ana senaryo ve alt senaryolar metin olarak yazıldı. Ayrıca varlık ilişki diyagramları ve veri akış diyagramları çizildi. Veri sözlüğünde dört tür giriş vardı: veri akışı sözlük girişi, veri deposu sözlük girişi, veri yapısı sözlük girişi ve veri elemanı sözlük girişi. Ekrandaki iki veri yapısı girişi şöyleydi (ekrandan, 00:50:00):

```text
Veri Yapısı Sözlük Girişi
Veri Yapı Adı   : Durak Bölgesi Ekleme
Tanım           : Yöneticinin durak bölgesi eklemek için kullandığı form
Veri Elemanları : bolgeNo(e) bolgeIl(e) bolgeIlce(e) bolgeMahalle(e) bolgeSokak(e)
Açıklama        : ...

Veri Yapısı Sözlük Girişi
Veri Yapı Adı   : Durak Bölgesi Güncelleme
Tanım           : Yöneticinin durak bölgesi güncellemek için kullandığı form
Veri Elemanları : bolgeNo(e) bolgeIl(e) bolgeIlce(e) bolgeMahalle(e) bolgeSokak(e)
Açıklama        : ...
```

Buradaki `(e)` işareti, yapının içindeki her öğenin bir veri elemanı olduğunu gösterir; her veri elemanı ayrıca kendi veri elemanı sözlük girişinde tanımlanır.

### 5.4 Uygulama

Uygulama C# ile yazıldı ve öğrenci ile yönetici olmak üzere iki ana girişe ayrıldı. Öğrenci önce sisteme kayıt olur, sonra kayıt başvurusunda ad, iletişim bilgileri, özel durumlar ile veri tabanındaki güzergâhlardan bir güzergâh ve iniş durağı seçer; başvuru yöneticinin onayına düşer. Onaylanan öğrenci ödeme ekranına geçer ve üç ödeme türünden birini seçer. Şifreler veri tabanında MD5 özetiyle saklandı; giriş alanlarında tırnak işaretleri kabul edilmeyerek SQL enjeksiyonuna karşı önlem alındı.

> **Ek bilgi (derste anlatılmadı):** MD5 hızlı bir özet fonksiyonudur ve günümüzde şifre saklamak için güvenli sayılmaz; şifreler için tuz (salt) kullanan ve bilerek yavaşlatılmış bcrypt, scrypt ya da Argon2 gibi fonksiyonlar önerilir. SQL enjeksiyonuna karşı da karakter engellemek yerine parametreli sorgular kullanmak daha sağlam bir yöntemdir.

Yönetici panelinde servis (araçların hasar ve bakım bilgileri), çalışan (çalışan tipi tanımlama dahil), durak ve güzergâh işlemleri, kayıt onaylama, ödemeler ve kurum iletişim bilgileri bulunur. Durak bölgesi tablosunda bölge numarası, il, ilçe, mahalle ve sokak sütunları vardı (ekrandan, 00:55:00). Duraklar güzergâhlar üzerinde tanımlanır; servislerin gidiş-gelişi ve öğrencinin seçimi bu duraklara bağlıdır, yani sistemin ana mantığı duraklarda kurulur. Gösterimde yapılan kredi kartı ödemesi ödeme listesinde görünmedi; veri tabanında kaydın eklendiği görüldü. Hoca bunun büyük olasılıkla bir istisnadan (exception) sonra arayüzün güncellenmemesinden kaynaklanabileceğini söyledi.

## 6. Maç bileti satış sistemi: toplantı raporları, bağlam diyagramı, HES kodu simülasyonu

### 6.1 Toplantılar ve müşteri istekleri

Grubun toplantı raporları ekranda şöyleydi (ekrandan, 01:00:00):

- 1. toplantı (02.04.2021), konu: ürün isterleri analizi. Projede kullanılacak materyaller ve yazılım dili konuşuldu; C# ve SQL kullanılmasına karar verildi.
- 2. toplantı (11.04.2021), konu: iş akışlarının belirlenmesi. Görev dağılımları yapıldı, proje süresine göre taslak çıkarıldı, şelale (waterfall) geliştirme modelinin kullanılmasına karar verildi.
- 3. toplantı (18.04.2021), konu: diyagramlar ve algoritma tasarımları. Diyagramlar kişilere paylaştırıldı, algoritmanın tasarımı yapıldı.

Sonraki toplantılarda kodlamanın durumu tartışıldı, raporlama birlikte yapıldı ve proje teslime hazırlandı. Gantt diyagramı bu toplantılarla uyumlu kuruldu.

Müşteri rolündeki üyenin istekleri: bilindik bilet satış sistemlerindeki stadyum tanımlama, maç tanımlama ve bilet düzenleme özellikleri; ayrıca salgın koşulları için kullanıcı salgın önlemi seçerse koltukların otomatik hazırlanması ve kırmızı-yeşil renklendirilmesi, bilet satışında HES kodu kontrolü. Sistemde üyelik işlemleri, yetkili girişi, maç ve stadyum tanımlama vardır; salgın önlemi seçilen maçlarda koltuklar aralarında birer boşluk kalacak biçimde otomatik dizilir. HES kodu ve ödeme işlemleri kendi veri tabanlarında simüle edildi. Stadyum kapasitesine göre koltukların ölçeklenmesi ise yapılamadı.

### 6.2 Fizibilite

Üç sistem karşılaştırıldı: Sistem 1 Windows ve C#, Sistem 2 Linux ve C#, Sistem 3 Java tabanlı. Geliştirme ortamı ekibin en iyi bildiği ortam olduğu için Sistem 1 teknik ve zaman fizibilitesinde en yüksek puanı aldı; Linux deneyimi olmadığından Sistem 2 zaman fizibilitesinde en düşük puanı aldı, Java biraz bilindiği için Sistem 3 ortada kaldı. Ekonomik ve yasal fizibilitede açık kaynaklı olduğu ve lisans gerektirmediği için Linux daha ucuzdu ve daha yüksek puan aldı. Sosyal fizibilitede Linux'un güvenlik açısından daha az sorun çıkaracağı değerlendirildi. Toplam puanlara göre Sistem 1 seçildi.

### 6.3 Veri akış ve ER diyagramları

Taslak (bağlam) veri akış diyagramı ekranda şöyleydi (ekrandan, 01:05:00):

- Merkezde tek işlem: Maç Bilet Satış Sistemi.
- Üye -> sistem: Üyelik Bilgileri, Maç ve Koltuk Seçimi, HES Kodu.
- Sistem -> Üye: Maç Bileti.
- Yönetim -> sistem: Stadyum Bilgisi, Maç Bilgisi, Takım Bilgisi, Bilet Bilgisi.
- Sistem -> Yönetim: Bilet Satış Bilgileri/Raporlamalar.

Birinci düzeyde üyelik işlemlerinin üyeler veri deposuna yazıldığı, üye girişinden sonra maç ve bilet seçiminin yapıldığı; yetkilinin maç, stadyum, takım ve bilet düzenleme işlemlerinin ilgili veri depolarına kaydolduğu gösterildi. Yetkili HES kodu da ekleyebilir; bu kodlar bir veri deposuna yazılır ve satış sırasında oradan okunur. Satış işleminde önce HES kodu kontrolü, sonra ödeme ve bilet oluşturma yapılır. ER diyagramında örneğin bir maçın birden çok bileti vardır (bire-çok ilişki).

### 6.4 Uygulama

Giriş menüsünde üye girişi, üye olma paneli ve yetkili girişi vardır. Üye, stadyumun koltuk düzenini görüp maç ve koltuk seçerek bilet alır; salgın önlemli maçlarda koltuklar boşluklu dizilir. Yetkili stadyum, takım ve maç ekleyip güncelleyebilir, bir maça istenen fiyattan otomatik bilet ekleyebilir, oynanmış maçların biletlerini toplu silebilir, üye bilgilerini kontrol edip güncelleyebilir ve HES kodu ekleyebilir.

## 7. Üniversite kampüs bilgi sistemi: modüller, ardışıl diyagram, arayüz geri bildirimleri

### 7.1 Kapsam ve fizibilite

Grup, öğrencilerin kullandığı resmi olmayan bir kampüs uygulamasından yola çıkarak ona yeni modüller ekleyen bir üniversite bilgi sistemi tasarladı. Özellikler:

- Kampüste kullanılan elektronik karta çevrim içi para yükleme.
- Kulüplere kayıt olma ve kayıt sildirme.
- Kütüphanede katalog tarama ve kitabı kısa süreliğine ayırma.
- Bilgi modülü: ring (ulaşım) ve yemekhane bilgileri.
- Mevcut bilgilerin ve istatistiklerin değerlendirilmesi.

Grup, karşılaştırılacak bir alternatif oluşturmadığını düşündüğü için fizibilite matrisi kurmadı. Yasal fizibilite kişisel verilerin korunması kanunu kapsamında incelendi ve sistemdeki kullanıcı bilgilerinin bir sorun yaratmadığı sonucuna varıldı. Sosyal fizibilite için kampüsteki mevcut sistem ve ihtiyaçlar hakkında kapalı uçlu bir anket yapıldı. Zaman fizibilitesinde Gantt planına tam uyulamadığı, bazı taşmalar olduğu belirtildi (ekrandan, 01:15:00).

### 7.2 Analiz: kullanım senaryosu ve kavramsal sınıf diyagramı

Kullanım senaryosu diyagramında ana aktör öğrencidir. Öğrenci üyelik ve hesap modülünden giriş yapar ve bakiye yükler; kulüp modülünde kulüp bilgilerini görür ve bakiyesi yeterliyse kulübe kayıt olur (kayıtta bakiyeden ücret düşülür); kütüphane modülünde kitap arar, stok bilgisini görür ve kitap varsa ayırır; bilgi modülünde günlük ring ve yemekhane bilgilerini görür. Diğer aktörler: raporlamadan sorumlu sistem geliştiricisi ve raporları görüntüleyen üniversitenin bilgi işlem yetkilisi.

Kavramsal sınıf diyagramında ana sınıf öğrencidir; kulüp modülü, kitap modülü ve bilgi modülü ayrı sınıflar olarak tanımlandı, bakiye işlemi için de ayrı bir sınıf vardı. Bilgi modülü ring ve yemekhaneye bağlıdır. Tasarımda bu diyagram ayrıntılandırılarak fonksiyonların dönüş tipleri ve parametreleri belirlendi.

### 7.3 Ardışıl diyagram

Ardışıl diyagramlar modüllere ayrılarak dört tane çizildi; Violet adlı araçla, örnek (instance) düzeninde ve yalnız temel (base case) senaryo üzerinden hazırlandı. En kötü durumların hepsini çizmek diyagramı çok karmaşıklaştırdığı için ele alınmadı. Kulüp modülünün diyagramı şöyleydi (ekrandan, 01:20:00):

- Nesneler: Ogrenci, Kulup Listesi, Kulup, Bakiye.
- Mesajlar sırasıyla:
  - Ogrenci -> Kulup Listesi: `getKulupler()`; kulüp listesi geri döner (kesikli dönüş oku).
  - Ogrenci -> Ogrenci: `getBakiye()` (kendine mesaj).
  - Ogrenci -> Kulup: `KulupUyeOl(ogrenci, kulup)`.
  - Kulup -> Kulup: `getYillikUcret()` (kendine mesaj).
  - Kulup -> Bakiye: `[!uyeMi(ogrenci, kulup) && ogrenci.getBakiye > kulup.getYillikUcret] guncelle(miktar, ogrenci)`.
  - Ogrenci -> Kulup: `KuluptenAyrilma(ogrenci, kulup)`.

Köşeli parantez içindeki ifade bekçi (guard) koşuludur: öğrenci kulübe üye değilse ve bakiyesi yıllık ücretten büyükse bakiye güncellenir, öğrenci üye yapılır. Anlatımda yıllık ücretin 10 lira olduğu örnek verildi.

> **Ek bilgi (derste anlatılmadı):** UML ardışıl diyagramında bir mesajın yalnız belli bir koşulda gönderildiği, mesajın önüne köşeli parantezle yazılan bekçi koşuluyla gösterilir. Birden fazla seçenekli dallanma için `alt`, isteğe bağlı tek dal için `opt` birleşik parçaları (combined fragment) kullanılır.

### 7.4 Uygulama ve hocanın geri bildirimleri

Uygulama Python ve Django ile yazıldı. Gerekçe, bir okul sisteminde beklenmedik bir trafik olmayacağı ve Python'ın bunu rahatça karşılayacağıydı. Kimlik doğrulama sistemi, yönetim paneli ve şifrelerin veri tabanına özetlenerek yazılması çatının hazır özelliklerinden alındı; grup bu sayede kendi modüllerine ve diyagramlara daha çok zaman ayırdı. Veri tabanı modelleri kendi sınıflarıyla tanımlandı (kullanıcı modülünde bakiye sınıfı, kulüp modülünde abonelik sınıfı gibi). Yönetim panelinde kulüp üyelikleri ve tarihleri, kitaplar, stok miktarları ve rezervasyonlar izlenebiliyor; sistem yöneticisi, kulüp yöneticisi, öğrenci, yemekhane çalışanı gibi kullanıcı grupları oluşturulabiliyordu (ekrandan, 01:25:00).

Gösterimde kulübe üye olunca bakiyeden ücret düştü; bakiye yetersizken kulübe üye olunamadı ve kitap ayrılamadı.

**Soru (hoca):** Üyelikten çıkınca para geri veriliyor mu? **Cevap:** Hayır, geri verilmiyor.

Hoca bunun üzerine her basışta cüzdandan para gittiğini, bu yüzden "emin misin, üye oluyorsun" ya da "emin misin, üyelikten çıkıyorsun" diye bir onay adımı konması gerektiğini söyledi. Yemekhane menüsünün de elle girilmesi yerine yayımlandığı sayfadan çekilmesinin daha doğru olacağını belirtti.

> **Hocanın vurgusu:** Kullanıcıdan para düşen ya da geri alınamayan işlemlerde arayüzde onay adımı bulunmalıdır.

## 8. Hastane bilgi sistemi: değişen müşteri isteği, ikinci düzey veri akış diyagramı

### 8.1 Müşteri görüşmeleri ve ön inceleme

Müşteri görüşmeleri üç görüşmeden oluşuyordu. Birincide müşteri yazılım sorumlusuna istediği sistemi ve modüllerini anlattı. İkincide yazılım teslim edildi; ancak müşteri salgın nedeniyle hastanede aşı birimi açmak istediğini söyledi ve ayrıntıları verdi: aşı iki dozdan oluşur, ikinci doz birinciden 14 gün sonra yapılır. Üçüncü görüşmede aşı biriminin modülü de teslim edildi. Bu yapı, müşterinin sonradan gelen değişiklik isteğinin sisteme yeni bir modül olarak eklenmesine bir örnektir.

Ön incelemede hastanedeki işlemlerin yönetilmesi ve kayıt altına alınması için bir bilgi sistemine ihtiyaç olduğu, bunun için yazılımcı, bilgisayar, depolama birimi ve bazı ek yazılımlar gerektiği belirtildi. Tahmini süre 3 hafta, tahmini bütçe 3000 dolar olarak verildi. Sistemle hastalar randevu alabilecek, çalışanlar yönetilebilecek, tahlil ve muayene işlemleri ve gerektiğinde aşı işlemleri yürütülebilecekti.

### 8.2 Fizibilite

- Teknik fizibilite: işletim sistemi olarak macOS ve Windows; raporlar için kelime işlemci, programlama için Java, veri tabanı için PostgreSQL, toplantılar için mesajlaşma ve görüntülü görüşme uygulamaları, Gantt diyagramı için tablolama programı. Donanım: bilgisayarlar, randevu sistemi için sunucular, veri depolama; iletişim için internet ve telefon.
- Zaman fizibilitesi: Gantt diyagramına göre 1 Nisan'da başlayıp 11 Mayıs'ta bitti, yaklaşık 40 gün (iki tarih arası 40 gündür; python ile doğrulandı).
- Sosyal fizibilite: hastalar kolayca randevu alabilmeli, hastane çalışanları randevulara erişip işlemleri kaydedebilmeli; hastalar gerektiğinde tahlil için laboratuvara, aşı için aşı merkezine yönlendirilebilmeli (ekrandan, 01:30:00).
- Yönetim fizibilitesi: hastanenin bilgi sistemi hızlı ve sorunsuz yönetilir, yöneticiler işlerini düzenli yürütür.
- Yasal fizibilite: hastaların adı, soyadı, vatandaşlık numarası, yaşı, boyu, kilosu; çalışanların adı, soyadı, vatandaşlık numarası ve maaş bilgileri kaydedilir. Bu bilgiler sistemin çalışması için gerekli olduğundan Kişisel Verileri Koruma Kanunu'na aykırı değildir (ekrandan, 01:30:00).
- Ekonomik fizibilite: donanım ve yazılımların çoğu hazırda bulunduğu için masrafı çoğunlukla çalışan ücretleri oluşturdu; her çalışana 750 dolar ve sunucu ile diğer ek masraflara da bütçe ayrıldı. <!-- BELİRSİZ: anlatılan kalemler (dört çalışan x 750 dolar + ek masraf) ön incelemedeki 3000 dolarlık bütçeyle tam örtüşmüyor; ek masraf tutarı altyazıda net değil. -->

### 8.3 Kullanım senaryosu ve veri akış diyagramları

Sistemde üç temel aktör vardır: hasta, destek personeli ve sağlık personeli (doktor, laborant, hemşire). Kullanım senaryosu diyagramında destek personeli yeni çalışan ekler ve ücret listesini görür; hasta randevu talebi verir, talep uygunsa randevu veri tabanına yazılır ve onay hastaya iletilir; doktor tahlil talebi oluşturur, laborant tahlili yapıp sonucu hastaya ve doktora iletir; doktor günlük randevuları görüp muayene kaydı oluşturur; hasta aşı randevusu alır, hemşire aşıyı yapıp kaydeder ve ikinci doz bilgisi hastaya iletilir.

Birinci düzey veri akış diyagramında beş modül vardı: 1.0 çalışan yönetimi, 2.0 hastane randevu, 3.0 laboratuvar istek ve sonuç işlemleri, 4.0 muayene izleme ve 5.0 aşı randevu izleme. İkinci düzey diyagramın ekrandaki kısmı şöyleydi (ekrandan, 01:35:00):

- 2.0 Randevu işlemleri:
  - Hasta -> 2.1 Randevu Talebi Alma: "Randevu talebi".
  - 2.1 -> 2.2 Talep Uygunluk Kontrolü: "Randevu talebi".
  - D2 Randevular -> 2.2: "Varolan randevular"; 2.2 -> D2: "Yeni randevu".
  - 2.2 -> Hasta: "Randevu onayı".
- 4.0 Muayene işlemleri:
  - D2 Randevular -> 4.1 Günlük Randevuları Listeleme: "Randevu bilgileri".
  - 4.1 -> Doktor: "Randevu listesi".
  - Doktor -> 4.2 Muayene Kaydı Oluşturma: "Muayene sonuçları".
  - 4.2 -> D4 Muayeneler: "Muayene sonuçları".
- 5.0 Aşı işlemleri:
  - Hasta -> 5.1 Aşı Randevu Alma: "Aşı talebi".
  - 5.1 -> D5 Aşı Bilgileri: "Aşı randevu bilgisi".
  - Hemşire -> 5.2 Aşı Kaydı Oluşturma: "Yapılan aşı bilgisi"; 5.2 -> D5: "Yapılan aşı bilgisi".
  - 5.2 -> Hasta: "İkinci doz bilgisi".
- D3 Tahliller laboratuvar modülünün veri deposudur. <!-- BELİRSİZ: 1.0 ve 3.0'ın ikinci düzey açılımı ve 5.0'ın sağ kısmı karede kesik; altyazıya göre 3.0 üç alt işlemden oluşur: tahlil talebi oluşturma (doktor), sonuç girme (laborant), sonuç görüntüleme (hasta ve doktor). -->

Randevu modülünde talep uygunluk kontrolü, aynı tarih ve saatte aynı çalışan için başka bir randevu olup olmadığına bakar. Grup ayrıca her modül için yapı diyagramları ve tahliller, çalışanlar, randevular, muayeneler ve aşı varlıklarını içeren bir ER diyagramı çizdi.

### 8.4 Uygulama

Uygulama basit bir konsol uygulamasıdır; ana menüde beş başlık (çalışan, randevu, muayene, laboratuvar, aşı işlemleri) vardır. Randevu işlemlerinde aynı çalışana 2021-6-8 saat 16:30 için ikinci bir talep "Randevu talebi uygun değil." yanıtını aldı; aynı çalışana 15:25 için yapılan talep "Başarılı." oldu (ekrandan, 01:40:00). Muayene menüsü doktorun o günkü randevularını listeler ve randevu kimliğiyle muayene bulgusu girilir. Laboratuvar menüsünde tahlil talebi oluşturulur, sıradaki sonucu girilmemiş tahlil gösterilir, tahlil kimliğiyle değerler girilir ve sonuç sorgulanır. Aşı menüsünde aşı randevusu alınır, randevular "yapıldı mı" ve "doz" bilgisiyle listelenir, aşı kaydı oluşturulunca bu alanlar güncellenir.

## 9. Dönemin toparlanması

Son sunumdan sonra hoca dönemi değerlendirdi. Bu derse kadar öğrencilerin gördüğü problemler bir algoritma ya da birlikte çalışan fonksiyonlar tasarlamak ölçeğindeydi. Bu derste ölçek büyüdü: modüller, birimler, alt sistemler ve dış sistemlerle haberleşme (kredi kartı onayı almak ya da bir servisten yemekhane verisini çekmek gibi). Bu ölçekte bir problem, programa `include` ya da `import` satırları yazıp kodlamaya başlayarak çözülemez. Önce problem çözümlenir, ardından çözüm tasarımlarla ifade edilir, ancak bundan sonra gerçeklemeye geçilir.

Derste önce fonksiyonel (yapısal) çözümlemenin nasıl yapıldığı ve nasıl ifade edildiği, sonra nesneye yönelik çözümlemede nelerin yapılması gerektiği ve nasıl ifade edildiği görüldü. Hoca bu konuların tanıtıcı düzeyde kaldığını, haftada iki saatle daha derine inilemediğini söyledi. İşlenmeyen konulara örnek olarak güncel yazılım geliştirme süreçlerine uygun analiz ve tasarım yaklaşımlarını verdi: çevik (agile) süreçlerde kullanım durumları bile çok kullanılmadan problem kullanıcı hikâyeleriyle (user story) modellenir; sprintlerin planlanması ve her sprintin içinde analiz ve tasarımın nasıl yapılacağı ayrı dinamikler getirir. Bunlar temel yöntemlerin üzerine kurulduğu için bu derste önce temel (fundamental) yöntemler öğrenildi. Ders projesi büyüklüğündeki çalışmalarla ekip olarak sistem boyutunda yazılım geliştirme deneyimi kazanıldı; grupların sunumları da başka grupların neyi nasıl yaptığını görüp kendi çalışmasını sorgulamak için paylaşıldı.

> **Ek bilgi (derste anlatılmadı):** Kullanıcı hikâyesi genelde "Bir <rol> olarak <amaç> istiyorum, böylece <fayda>" kalıbında yazılan kısa bir gereksinim tanımıdır. Sprint, çevik yöntemlerden Scrum'da genelde 1-4 haftalık, sonunda çalışan bir ürün parçası çıkan sabit süreli geliştirme döngüsüdür.

## Örnek Sorular

1. (derste sözlü, 00:40:38) Bir mobil uygulamanın kullanım senaryosu diyagramında bütün kullanım durumları (cüzdan ekleme, sistem tanımlama vb.) tek bir kullanım durumundan türeyen hiyerarşik elipsler olarak çizilmiştir. Bu çizimdeki sorun nedir, nasıl düzeltilir?

> **Cevap (derste verildi):** Kullanım durumları sistemde yapılacak ayrı işlerdir; birbirlerinden türemiş gibi gösterilmez. Hepsi giriş yapmayı gerektiriyorsa giriş kullanım durumu bunlara `include` ilişkisiyle bağlanır.

2. (derste sözlü, 01:08:51) Maç bileti satış sisteminde HES kodu kontrolü "simüle edildi" deniyor. Bu simülasyon nasıl çalışıyor, rastgele bir sonuç mu üretiyor?

> **Cevap (derste verildi):** Hayır. Sistem doğrulanmış HES kodlarını bir tabloda tutar; kullanıcının girdiği HES kodu bu tablodakiyle eşleşirse bilet satın alabilir. Tablo, kodların ilgili kurumdan alınmış gibi düşünülmesiyle doldurulur.

3. (derste sözlü, 01:21:31) Kampüs uygulamasında kulüp üyeliğinden çıkınca ödenen ücret geri veriliyor mu? Bu durumda arayüzde ne eksiktir?

> **Cevap (derste verildi):** Ücret geri verilmiyor. Bu yüzden her tıklamada bakiyeden para gitmemesi için üye olma ve üyelikten çıkma işlemlerinde "Emin misiniz?" onay adımı konmalıdır.

4. (derste sözlü, 00:56:28) Okul servisi uygulamasında gösterim sırasında yapılan kredi kartı ödemesi ödemeler listesinde görünmedi, ama veri tabanında kayıt eklenmişti. Bunun olası nedeni nedir?

> **Cevap (derste verildi):** Kayıt veri tabanına yazıldıktan sonra arayüz tarafında bir istisna (exception) oluşmuş ve liste güncellenmemiş olabilir. Hoca bunu bir olasılık olarak söyledi; kesin neden gösterimde bulunamadı.

5. (ekrandan, 01:20:00) Ardışıl diyagramdaki `[!uyeMi(ogrenci, kulup) && ogrenci.getBakiye > kulup.getYillikUcret] guncelle(miktar, ogrenci)` mesajı ne anlama gelir?

> **Çözüm (derste verilmedi):** Köşeli parantez içindeki ifade bekçi koşuludur. `guncelle` mesajı Kulup nesnesinden Bakiye nesnesine yalnız öğrenci o kulübe henüz üye değilse ve bakiyesi kulübün yıllık ücretinden büyükse gönderilir; bu durumda bakiyeden ücret düşülür. Sunumda anlatılan buydu: kontrol sağlanırsa bakiye güncellenir ve öğrenci üye yapılır.

## Dersin Toparlaması

Bu son derste kalan gruplar projelerini sundu ve dönem boyunca işlenen yöntemlerin gerçek sistemlerde nasıl kullanıldığı görüldü. Fizibilite tarafında alternatiflerin teknik tablolarla karşılaştırılması, ağırlıklı fizibilite matrisiyle puanlanması, ekonomik fizibilitede yatırım maliyeti, net bugünkü değer, iç verim oranı ve geri ödeme süresinin hesaplanması ve en iyi-en kötü gün tahminlerinden Gantt planı kurulması örneklendi. Analizde bağlam diyagramından birinci ve ikinci düzeye inen veri akış diyagramları, veri sözlüğü girişleri ve kullanım senaryoları; tasarımda yapı diyagramı, sınıf diyagramları, bekçi koşullu ardışıl diyagram ve birincil-yabancı anahtar kararlarıyla veri tabanı tasarımı gösterildi. Hoca kullanım senaryosunda `include` ilişkisini, arayüzde onay adımını ve dış verinin kaynağından çekilmesini vurguladı.

Dönemin sonunda hoca dersin amacını özetledi: büyük ölçekli bilgi sistemlerinde önce çözümleme ve tasarım yapılır, sonra gerçekleme gelir. Ders yapısal ve nesneye yönelik çözümlemenin temellerini verdi; çevik süreçlerdeki kullanıcı hikâyeleri ve sprint planlaması bu temellerin üzerine kurulan sonraki adımdır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
