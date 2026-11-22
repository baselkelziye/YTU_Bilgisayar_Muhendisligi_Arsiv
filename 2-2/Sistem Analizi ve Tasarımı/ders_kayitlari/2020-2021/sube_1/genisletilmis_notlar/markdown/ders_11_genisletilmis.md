# Ders 11 Genişletilmiş Notu: Dönem Projesi Sunumları: Analiz ve Tasarım Modellerinin Uygulanması

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Oturumun amacı ve sunumların kapsamı
- 2. Proje başlatma, roller ve müşteriyle gereksinim belirleme
- 3. Fizibilite çalışmaları
- 4. Analiz modelleri: kullanım durumu ve senaryo dokümanı
- 5. Analiz modelleri: veri akış diyagramları
- 6. Tasarım modelleri: sınıf ve sıralama diyagramları
- 7. Tasarım modelleri: yapı diyagramı
- 8. Veri tasarımı: E-R diyagramı ve koleksiyon tasarımı
- 9. Ara birim tasarımı
- 10. Gerçekleştirme: teknoloji seçimi ve güvenlik tasarımı
- 11. Örnek alan bilgisi: sıralı oylama ve Schulze yöntemi
- 12. Hocanın genel geri bildirimleri: yaklaşım ve diyagram tutarlılığı

## 1. Oturumun amacı ve sunumların kapsamı

Bu ders, teorik anlatımın yerine öğrenci gruplarının dönem projesi sunumlarına ayrılmıştır. Gruplardan proje raporlarındaki şu kısımları anlatmaları istenmiştir: projeye giriş, zaman planlaması, fizibilite ve analiz ile tasarım aşamalarında hazırladıkları modeller. Her grup üyesi kendi yaptığı kısmı anlatmıştır. Programın nasıl çalıştığının ayrıntılı gösterimi bu oturumun konusu değildir; sunumlarda uygulamaya yalnız kısaca değinilmiştir.

Sunumlar, dönem boyunca işlenen konuların (sistem kavramı, yazılım geliştirme yaşam döngüsü, proje yönetimi, fizibilite, Gantt ve PERT, analiz modelleme, veri akış diyagramı, kullanım durumu, sistem tasarımı ve yapı diyagramı) bir projede birlikte nasıl kullanıldığını göstermesi açısından bir tekrar niteliğindedir. Oturumda dört örnek sistem sunulmuştur:

- Kurum çalışanlarının seçenekleri sıralayarak oy verdiği bir oylama sistemi.
- Birden çok kütüphaneyi ortak bir veri tabanıyla tek merkezde toplayan bir katalog ve ödünç alma uygulaması.
- Gişe görevlisinin kullandığı bir otopark takip sistemi.
- Bir üniversitedeki öğrenci kulüplerinin evrak ve etkinlik işlemlerini çevrim içi yürüten bir kulüp yönetim sistemi.

Sunumların ortak akışı şöyledir: sistemin amacı ve neden gerekli olduğu, ekip yapısı ve roller, müşteriyle yapılan toplantılar, fizibilite, analiz modelleri, tasarım modelleri, veri tabanı tasarımı, arayüz ve kısa bir uygulama gösterimi.

## 2. Proje başlatma, roller ve müşteriyle gereksinim belirleme

### 2.1 Ekip rolleri

Gruplar, derste anlatılan proje ekibi rollerini kendi aralarında paylaştırmıştır: proje yöneticisi, sistem analisti, sistem tasarımcısı, programcılar (ön yüz ve arka uç), veri tabanı tasarımcısı, belgeleme ve test sorumlusu. Bazı gruplarda bir üye müşteri rolünü üstlenmiş, istekleri o belirlemiş ve uygulama bitince kabul testlerini de müşteri olarak yapmıştır. Bir grupta görev dağılımının keskin olmadığı, üyelerin birden çok aşamada çalıştığı belirtilmiştir. Bir otopark projesinde ekip yapısı üç sistem programcısı, iki sistem analisti ve bir sistem tasarımcısı olarak verilmiş; ayrıca bir üye proje yöneticiliğini, bir üye de gerektiğinde müşteri rolünü üstlenmiştir.

### 2.2 Toplantılar ve aşama geçişleri

Bir otopark projesinin toplantı akışı aşamaların nasıl birbirine bağlandığını iyi gösterir. İlk toplantıda sistemin yapısı, amaçları ve ihtiyaçları konuşulmuş, kaba bir sistem taslağı kurulmuş ve roller belirlenmiştir. İkinci toplantıya analistler fizibilite çalışmalarıyla gelmiş; bu çalışmalar sonucunda programın Java ile nesneye yönelik yazılmasının daha avantajlı olacağına karar verilmiş, programcıların eksikleri olsa da programlama başlayana kadar giderilebileceği değerlendirilmiştir. Üçüncü toplantıda tasarım bitmiş ve programcıların başlamasına hazır hâle gelinmiştir; bu arada müşteriyle görüşülerek revizyonlar yapılmıştır (örneğin otopark kapasitesinin düşürülmesi, bazı alanların abonelere ayrılması). Son toplantı teslimden önce rapor ve sunum provası içindir.

### 2.3 Müşteri isteklerinin listelenmesi ve uzlaşma

Bir kütüphane projesinde müşteri istekleri bir tabloda "Müşteri İstekleri" ve "Gerçekleştirilme Durumu" sütunlarıyla izlenmiştir (ekrandan, 00:30:00). Tablodaki istekler şunlardır:

- Okuyucunun birden fazla kütüphane ve kitap bilgisine tek bir uygulama üzerinden ulaşması.
- Uygulamada üyelik sistemi olması ve üyeliklerin mail üzerinden gerçekleştirilmesi.
- Kitapları sistem üzerinden ödünç almak.
- Ödünç alınan kitapların konumunu görmek.
- Aranan kitaplara benzer kitapların önerilmesi.
- Kitaplara okuyucuların yorum yapması ve yorumları okuması.
- Daha önce okunan kitapların kullanıcı profilinde saklanması.
- Kitap bağışı yapabilmek.
- Kullanım kolaylığı ve anlaşılabilirlik için basit bir arayüz.
- Kullanıcıyı sıkmayacak şekilde arayüzde farklı renk seçenekleri.
- Uygulamanın 15 gün içinde hazır olması.
- Olmayan kitaplar için sıraya girmek ve mail yoluyla bilgilendirilmek.
- Kitap teslim süresinin 20 gün ile sınırlandırılması.
- Kitap iade süresi geçtiğinde okuyucunun 15 gün kitap alamama ile cezalandırılması.
- Kredi sistemi ile belirli bir krediye ulaşan okuyuculara istediği bir kitabın hediye edilmesi.

Bu isteklerin hepsi kabul edilmemiştir. Müşterinin istediği 15 günlük sürenin yetersiz olduğu gerekçesiyle anlatılmış ve süre konusunda uzlaşılmıştır. Olmayan kitap için sıraya girme ve mail bildirimi isteğinin geliştirme sürecini zorlaştıracağı ve maliyeti artıracağı açıklanınca müşteri bu istekten vazgeçmiştir. Bu örnek, analistin müşteri isteklerini fizibilite açısından değerlendirip müşteriyle pazarlık yapmasının somut bir uygulamasıdır.

Başka bir grup müşteriyle bir çevrim içi form üzerinden düzenli haberleşmiş, ara sürümleri müşteriye göstermiş ve isteklere göre revizyon yapmıştır. Grup bunu çevik (agile) yaklaşımı seçmelerinin gerekçesi olarak anlatmıştır: müşteriyle sürekli iletişim hâlinde kalarak geliştirme yapmak.

Kulüp yönetim sistemi projesinde ise gerçek bir müşteriyle, bir üniversite birimiyle çalışılmıştır. Ekip, kulüp evrak işlerinde gördüğü sorunları (evrakların uzun sürede işleme alınması, küçük bir hatada formun defalarca yeniden doldurulması, kâğıt israfı) birime iletmiş, birim böyle bir sisteme ihtiyacı olduğunu söylemiş, kurumun bilgi işlem biriminin güvenlik kaygıları giderildikten sonra proje başlamıştır. Sonraki toplantılarda müşteri istenmeyen durumları bildirmiş ve yeni özellikler istemiştir; örneğin elektronik belge yönetim sistemine entegrasyon sağlanana kadar belgelerin PDF çıktısının alınabilmesi isteği sonradan eklenmiştir.

> **Hocanın vurgusu:** Gerçek bir uygulamada kullanıcıyla iletişim kurmak, gereksinim toplama ve revizyon sürecini çok daha gerçekçi hâle getirir.

## 3. Fizibilite çalışmaları

### 3.1 Teknik fizibilite

Teknik fizibilitede hangi platformun, dilin ve veri tabanının kullanılacağı ve seçeneklerin avantajları ile dezavantajları değerlendirilmiştir. Otopark projesinde sistemin doğrudan araç sahiplerine mi yoksa yalnız gişe görevlisine mi açılacağı tartışılmış; sistemi gişe görevlisi kullanacağı için herkese açık bir web sitesi yerine daha basit arayüzlü bir masaüstü programı yapılmasına karar verilmiştir. Bir oylama projesinde teknoloji analizi, hangi platformların kullanılmasının en fazla fayda sağlayacağı sorusu olarak ele alınmıştır.

### 3.2 Ekonomik fizibilite

Ekonomik fizibilite kapsamında maliyet ve kazanç tabloları oluşturulmuştur: toplam geliştirme maliyetleri, çalışanların yıllık ücret maliyetleri, yıllık yürütme maliyetleri ve gelir tablosu. Maliyet fayda analizinde net bugünkü değer (net present value), geri ödeme süresi (payback period) ve yatırımın beş yıllık geri dönüş oranı hesaplanmıştır.

Bir sunumdaki yıllık yürütme maliyetleri tablosu (ekrandan, 00:10:00):

| Tekrarlayan harcamalar | Miktar |
|---|---|
| İnternet bağlantısı | 16.000 \$ |
| Ekipman bakım ve onarımı | 18.000 \$ |
| Bilgisayar işlemleri / programlama | 45.000 \$ |
| Eğitim ve sürekli destek (yardım masası) | 14.000 \$ |
| Ekipman amortismanı | 22.000 \$ |
| Kaynaklar | 16.500 \$ |
| **Toplam** | **131.500 \$** |

Toplam kontrol edildiğinde $16.000 + 18.000 + 45.000 + 14.000 + 22.000 + 16.500 = 131.500$ çıkar. Aynı sunumda işletme döneminin ilk üç yılı için (ekrandan, 00:15:00):

- Toplam gider: 690.026 \$
- Toplam gelir: 772.260 \$
- Ek kâr: $772.260 - 690.026 = 82.234$ \$ (geliştirmeler için kullanılacak)

> **Ders sonrası not:** Altyazıda ek kâr "82.224 dolar" olarak geçiyor; slaytta ve hesapta doğru değer 82.234 \$'dır.

Otopark projesinde ise geliştirme maliyeti şöyle bulunmuştur: her geliştiricinin, analistin ve tasarımcının saatlik ücreti belirlenmiş, günde 8 saat çalışılacağı varsayılmış ve zaman fizibilitesinde planlanan gün sayılarıyla çarpılmıştır; buna donanım maliyeti eklenmiştir. Satış fiyatı ve kaç müşteriye satılacağı henüz bilinmediği için geri ödeme süresi analizi yapılmamıştır. Grup bu analizin yapılışını, yıl sonunda satış geliri belirlendikten sonra geliri maliyete oranlamak olarak açıklamıştır.

> **Ek bilgi (derste anlatılmadı):** Geri ödeme süresi, yatırımın birikimli net nakit akışıyla kendini geri kazandığı süredir. Net bugünkü değer ise gelecekteki nakit akışlarının bir iskonto oranıyla bugüne indirgenip yatırım maliyetinin düşülmesiyle bulunur; pozitif çıkması projenin ekonomik olarak uygun olduğunu gösterir. Bu iki ölçüt dersin fizibilite konusunda işlenmişti.

### 3.3 Kaynak ve zaman fizibilitesi

Kaynak fizibilitesi kapsamında proje ekip yapısı ve organizasyon şeması çizilmiş, kaynak atamaları çalışan ve materyal olarak standart ücretleriyle listelenmiş ve her aşamada kullanılacak yazılım kaynakları planlanıp toplam maliyetleri belirlenmiştir. Zaman fizibilitesinde Gantt şeması (başlangıç ve bitiş tarihleri, kilometre taşları, kaynak atamaları) ve PERT diyagramı (planlama, analiz, tasarım, gerçekleştirme ve test aşamalarının süreleri) hazırlanmıştır.

Otopark projesinin Gantt şemasındaki iş kırılım yapısı (ekrandan, 00:50:00):

| WBS | İş adı | Süre (gün) | Başlangıç | Bitiş |
|---|---|---|---|---|
| 0 | Otopark araç kayıt sistemi | | | |
| 1 | **Analiz** | 6 | 1.05.2021 | 7.05.2021 |
| 1.1 | İlk toplantı | 0 | 1.05.2021 | 1.05.2021 |
| 1.2 | Problemin tanımı, sistemin planlanması | 1 | 1.05.2021 | 2.05.2021 |
| 1.3 | Fizibilite çalışması | 4 | 2.05.2021 | 6.05.2021 |
| 1.4 | Sistem gereksinimlerinin belirlenmesi | 1 | 6.05.2021 | 7.05.2021 |
| 1.5 | Analiz bitimi toplantısı | 0 | 7.05.2021 | 7.05.2021 |
| 2 | **Tasarım** | 8 | 8.05.2021 | 16.05.2021 |
| 2.1 | Genel tasarım | 3 | 8.05.2021 | 11.05.2021 |
| 2.2 | Ayrıntılı tasarım | 5 | 11.05.2021 | 16.05.2021 |
| 2.3 | Tasarım bitimi toplantısı | 0 | 16.05.2021 | 16.05.2021 |
| 3 | **Geliştirme ve test** | 13 | 17.05.2021 | 30.05.2021 |
| 3.1 | Ön yüz geliştirme | 7 | 17.05.2021 | 24.05.2021 |
| 3.2 | Arka plan geliştirme | 7 | 17.05.2021 | 24.05.2021 |
| 3.3 | Birim test | 7 | 17.05.2021 | 24.05.2021 |
| 3.4 | Sistem testi | 2 | 26.05.2021 | 28.05.2021 |
| 3.5 | Kullanıcı testleri | 4 | 26.05.2021 | 30.05.2021 |
| 4 | **Proje teslim toplantısı** | 0 | 31.05.2021 | 31.05.2021 |

Şemada süresi 0 olan toplantılar kilometre taşı (yıldız) olarak gösterilmiş, ön yüz geliştirme, arka plan geliştirme ve birim test paralel yürütülmüş, sistem testi ve kullanıcı testleri geliştirme bittikten sonra başlamıştır. Grup, gecikme için pay bırakmalarına karşın plana uyduklarını belirtmiştir.

Bir kütüphane projesinin Gantt şeması ise ana başlıklar hâlinde anlatılmıştır: analiz (müşteri görüşmesinin değerlendirilmesi, gerçekleştirilebilirlik ve maliyet incelemesi, analiz bitimi toplantısı), kavramsal tasarım (veri akış ve yapı diyagramlarıyla programın işleyişinin taslağı), algoritma tasarımı, arayüz ve veri tabanının modüllerden önce kodlanması, modüllerin ekip içinde paylaştırılarak kodlanması ve müşteriyle birlikte test. Grup, arayüz ve veri tabanını modüllerden önce hazırlamanın modül kodlamasını kolaylaştırdığını fark ettiklerini anlatmıştır.

### 3.4 Pazar, finansman, satış ve yasal fizibilite

Bir oylama projesi fizibilite raporuna pazar analizi (çalışanların fikirlerinin alınmasına yönelik beklentinin artması), teknoloji analizi ve finansman analizi (bir küçük işletme teknoloji destek programına başvuru, geri ödemesiz ve geri ödemeli kısımlar) eklemiştir. Hoca bu noktada destek programının başvuru formatının gerçekten incelenip incelenmediğini sormuştur. Satış ve üretim programında kurumsal ve bireysel paketler, aylık ve yıllık abonelik seçenekleri, üretim aşamaları (ihtiyaçların belirlenmesi, ara birim tasarımı, gerçekleştirme, geliştirme) ve pazarlama stratejisi (tanıtım, eğitim, demo, satış, kampanya) anlatılmıştır. Otopark projesinde sistemin uyması gereken yasal koşullar da araştırılmıştır.

## 4. Analiz modelleri: kullanım durumu ve senaryo dokümanı

### 4.1 Oylama sistemi

Nesneye yönelik analiz yapan bir grup use case diyagramı ve senaryo dokümanı hazırlamıştır. Müşterinin beklentisi, şirketteki herkesin kullanabileceği basit ve sade bir sistemdi. Bu yüzden sistem üç aktörle kurulmuştur: çalışanlar, yetkililer ve yöneticiler. Profil düzenleme, oy verme ve oy sonucu görme bütün aktörlerce yapılır; oylama oluşturma yalnız yetkililere ve yöneticilere aittir; yöneticiler ayrıca diğer çalışanların yetkilerini değiştirebilir. Senaryo dokümanında her senaryo için senaryonun adı, aktörler, aktörlerin beklentileri, koşullar, ana akış ve ana akışta bir sorun çıkarsa izlenecek alternatif akış yazılmıştır.

### 4.2 Otopark sistemi

Otopark sisteminin use case diyagramında ana aktör gişe görevlisidir; araç sahibinden de bilgi alındığı için araç sahibi de diyagramda yer alır. Asıl işlemler araç giriş ve çıkışıdır. Abonelik işlemi ve otopark yer sorgulama bu işlemlerin uzantısı gibi, yani yan modüller olarak "extend" ilişkisiyle gösterilmiştir. Otopark yer seçimi, araç park giriş işleminin bir parçası olduğu için girdi olarak gösterilmiştir.

Sistemin genel akışı use case belgesinde şöyle yazılmıştır:

```text
1. Araç sahibi gelir.
2. Abone değilse plaka ve diğer bilgilerini verir; aboneyse yalnız plakayı söyler.
3. Gişe görevlisi bilgiyi sisteme girer ve park yerini seçer.
4. (İsteğe bağlı, extend) Abonelik işlemi ya da boş yer sorgulama yapılır.
5. Çıkışta araç sahibi plakayı verir.
6. Sistem ücreti hesaplar, görevli ücreti bildirir; senaryo sonlanır.
```

Senaryo dokümanında birinci aktör otopark görevlisi, ilgililer araç sahibi ve otopark takip programıdır. İlgililerin beklentisi, araç sahibinin doğru bilgi vermesi ve görevlinin aldığı bilgiyi eksiksiz ve doğru girmesidir. Alternatif akışa örnek olarak yanlış plaka girildiğinde sistemin hata mesajı vermesi yazılmıştır.

> **Ek bilgi (derste anlatılmadı):** UML'de "extend" ilişkisi, bir kullanım durumunun belirli bir koşulda başka bir kullanım durumuna ek davranış kattığını gösterir; ok genişleten durumdan temel duruma çizilir. "include" ise temel durumun her çalışmada zorunlu olarak içerdiği ortak davranışı gösterir.

## 5. Analiz modelleri: veri akış diyagramları

### 5.1 Kütüphane sistemi bağlam ve birinci düzey diyagramı

Bir kütüphane projesinin taslak veri akış diyagramında kullanıcı, kütüphane bilgi sistemine bağış isteği, kitabın fiziksel konum isteği, kitap isteği ve üye kaydı isteği gönderir. Sistem bunlara karşılık kitap önerisi, istenen kitap ve kitap bildirimi döndürür. Örneğin kitap isteği geldiğinde sistem önce kitap veri tabanına bakar, kitap varsa "var", yoksa "yok" bildirimini kullanıcıya iletir. Kullanıcı bir kitabı iade ettikten sonra son iade ettiği kitaba göre öneri alabilir. Sistem kütüphaneler arası olduğu için kitabın hangi kütüphanede bulunduğunu ve fiziksel konumunu da döndürür. Ceza sistemi ödünç alma tarihine göre çalışır: belirlenen süre içinde iade edilmezse kullanıcının kredisi düşürülür, kredi sıfırlanınca kullanıcı kitap alamaz. Bağışta bağışlanan kitap kitap veri tabanına işlenir.

### 5.2 Kütüphane sistemi ikinci düzey diyagramları

İkinci seviye veri akış diyagramlarının bir kısmı ekranda görülmektedir (ekrandan, 00:35:00):

```text
Süreç 1.0 (Giriş / kayıt)
  Kullanıcı --Giriş Bilgileri--> 1.1 Giriş bilgilerinin veri tabanı ile karşılaştırılması
  1.1 --Kullanıcı Bilgileri--> 1.2 Üye girişi / Yeni üye kaydı
  1.2 --Giriş Bilgileri--> [Üye Listesi]
  [Üye Listesi] --Üye Bilgisi--> 1.2

Süreç 2.0 (Ödünç alma)
  Kullanıcı --Kitap İsteği--> 2.1 Kitabın veri tabanında aranması
  [Kitaplık] --Kitap Bilgisi--> 2.1
  2.1 --Kitap Stok Bilgisi--> 2.2 Kullanıcı mevcut ceza kontrolü
  2.2 --Kitap ve Kullanıcı Bilgisi--> [Ödünç Kitap Kayıt Listesi]
  ... --Bildirim Mesajı--> Kullanıcı
```

Sunumda modüllerin ikinci düzeydeki işleyişi şöyle anlatılmıştır:

- Giriş ve kayıt: Kullanıcının bilgileri alınır ve veri tabanında bu bilgilere ait kayıt olup olmadığı kontrol edilir. Giriş sekmesinde kayıt varsa giriş onaylanır; kayıt sekmesinde kayıt yoksa üye kaydedilir ve giriş onaylanır. İki sekme aynı kontrolü zıt yönde kullanır.
- Ödünç alma: Kullanıcı seçtiği kitap için istek gönderir. Kitap stokta yoksa kullanıcı bunu görür ve işlem biter; stokta varsa kullanıcının ceza durumuna göre kitap verilir ya da uyarı gösterilir.
- İade ve ceza: İade edilen kitap ödünç kayıtlarına "iade edildi" olarak işlenir, sistem tarihi ödünç alma tarihiyle karşılaştırılır, geç iade varsa üyenin kaydına ceza işlenir.
- Bağış: Kitap veri tabanında yoksa eklenir ve kütüphaneye verilir; varsa o kütüphanedeki kopya sayısı artırılır.
- Konum bulma: Kütüphanelerin ortak kitap yerleştirme düzenine göre kitabın seçilen kütüphanedeki yeri hesaplanır ve bir kroki resmi olarak kullanıcıya iletilir.
- Yönetici kitap ekleme: Yönetici hesabıyla giriş yapılarak yeni kitap eklenir.

### 5.3 Otopark sistemi birinci ve ikinci düzey diyagramları

Otopark grubu nesneye yönelik tasarım yapmasına rağmen modüllerin daha rahat anlaşılması için taslak, birinci düzey ve ikinci düzey veri akış diyagramları da hazırlamıştır. Birinci düzeyde programı gişe görevlisi kullanır ve üç temel işlem vardır: otoparkın durumunu görme, abonman işlemleri ve park işlemleri. İkinci düzeyde bu işlemlerin altındaki yöntemler ve işlemlerin nasıl yapıldığı ayrıntılı gösterilmiştir.

> **Hocanın vurgusu:** İkinci düzeyde bütünlük yoktur, ayrıntı verilir. Birinci düzeyde bütün uygulama bir arada görünür; ikinci düzeyde her süreç için ayrı bir diyagram çizilir. Bütün sistem tek bir ikinci düzey diyagramda birleştirilmez. İki üç süreç için örnek vermek yeterli olabilir.

## 6. Tasarım modelleri: sınıf ve sıralama diyagramları

Nesneye yönelik tasarım yapan gruplar UML sınıf diyagramı ve sıralama diyagramı hazırlamıştır. Oylama projesinde oylama, oy ve kişi için ayrı nesneler tanımlanmış, ardından bunlara göre sıralama diyagramı çizilmiş ve geliştirmeye bu iki diyagramla geçilmiştir. Otopark projesinin sınıf diyagramında koddaki bütün sınıflar, metotlar ve değişkenler gösterilmiştir.

Otopark sisteminin sıralama diyagramı (ekrandan, 00:55:00) şu yaşam çizgilerini içerir: `JVM`, `:Arayüz`, `:SisAn`, `:Otopark`, `:Abonman`, `:OtoparkDurum`, `:AbonmanDurum`, `:Araç`, `:Hakkimizda`. Diyagramdaki mesaj akışı:

```text
JVM        -> :Arayüz        main(...)
:Arayüz    -> :SisAn         new
:SisAn     -> :Otopark       <<create>>
:Arayüz    -> :Otopark       new
:Otopark   -> :Abonman       new
:Abonman   -> :AbonmanDurum  AbonmanDurum()
:Otopark   -> :Araç          <<create>>
:Otopark   -> :Araç          AracParkEt()
:Otopark   -> :Otopark       AracGiris()
:Otopark   -> :Otopark       AracCikis()
:Otopark   -> :Otopark       AbonmanGiris()
:Otopark   -> :Otopark       AbonmanHakSorgula()
:Otopark   -> :Otopark       UcretSorgula()
:Otopark   -> :OtoparkDurum  OtoparkDurum()
:Arayüz    -> :Hakkimizda    new
:Hakkimizda --> :Arayüz      return
```

Diyagramda nesne oluşturma `<<create>>` ve `new` mesajlarıyla, nesnenin kendi metodunu çağırması kendine dönen oklarla, geri dönüş ise kesikli okla gösterilmiştir.

## 7. Tasarım modelleri: yapı diyagramı

### 7.1 Kütüphane sisteminin yapı diyagramı

Bir kütüphane grubu yapı diyagramını anlatırken, yapı diyagramlarında veri akış yaklaşımından farklı olarak koşul ifadelerinin yer alabildiğini belirtmiştir. Örnek olarak giriş bilgilerinin alınması ile kütüphane temel işlemlerinin birbirine bağlı çalıştığını, giriş bilgileri geçerli olmadan kullanıcının temel işlemlere geçemeyeceğini göstermiştir.

### 7.2 Kulüp yönetim sisteminin yapı diyagramı

Kulüp yönetim sistemi grubunun yapı diyagramı (ekrandan, 01:10:00) modül hiyerarşisini ve modüller arasında taşınan veri çiftlerini gösterir:

```text
Kulüp Yönetim Sistemi
  -> Veri Tabanı          (gönderilen: Object ID; dönen: Data)
  -> Giriş Ekranı         (gönderilen: Kullanıcı Bilgileri; dönen: Token)
  -> Ana Sayfa            (gönderilen: Kulüp ve Etkinlik Bilgileri, Token; dönen: İşlem)
       -> Kullanıcı Profili   (Kullanıcı Bilgileri / Yeni Kullanıcı Bilgileri)
            -> Kullanıcı Bilgileri Değiştirme (Eski / Yeni Kullanıcı Bilgileri)
       -> Kulüp Profili       (Kulüp Bilgileri, Geçmiş Etkinlikler)
            -> Eski Etkinlikler  (Geçmiş Etkinlikler)
       -> Etkinlikler         (Etkinlik Bilgileri)
            -> Etkinlik Başvuru Formu (Yeni Etkinlik)
            -> Etkinlik Sayfası       (Etkinlik Bilgileri / Etkinlik Durumu)
                 -> Etkinlik Durumu   (Etkinlik Bilgisi, Etkinlik Durum Bilgisi / Yeni Etkinlik Durumu)
                      -> Etkinlik Onayla
                      -> Etkinlik Sil
                      -> Etkinlik Red
```

Giriş ekranından gelen kullanıcı bilgileri sisteme gider, onaylanırsa bir token döner; sonraki işlemlerde bu token veri tabanından doğrulanır. Ana sayfadan etkinliklere, kulüp profiline ve kullanıcı profiline geçilir; etkinlik bölümünde etkinlik sayfası ve başvuru formu vardır.

## 8. Veri tasarımı: E-R diyagramı ve koleksiyon tasarımı

### 8.1 İlişkisel tasarım örneği

Bir kütüphane grubu ilişkisel bir veri tabanı ve sunucu gerektirmeyen gömülü bir SQL motoru (SQLite) kullanmıştır. E-R diyagramındaki tablolar (ekrandan, 00:40:00):

| Tablo | Alanlar |
|---|---|
| Users | UserId, Name, Surname, Email, Password, LateReturnStatus |
| Books | BookId, Title, Author, PublishDate, PageCount, Isbn13, Overview |
| Libraries | LibraryId, Name, Address, PhoneNumber, Email, EmailPrivateKey, StartPointX, StartPointY, RowCount, ColumnCount, ShelfWidth, ShelfHeight, ShelfHorizontalGap, ShelfVerticalGap |
| BookCopies | BookCopyId, BookId, LibraryId, CopyCount |
| BookLoans | UserId, BookCopyId, LoanDate, IsReturned |
| Comments | UserId, BookId, Comment |
| BookGenres | BookId, Genre |

Users, Books ve Libraries ana tablolardır; ara tablolardaki bilgilere bunların birincil anahtarlarıyla ulaşılır. Comments tablosu, kullanıcı ile kitap arasındaki çoka çok ilişkiyi tanımlayan bir bağlantı tablosudur; UserId ve BookId ile bir kullanıcının bir kitaba yaptığı yoruma erişilir. BookCopies, bir kitabı bir kütüphaneye kaydeder ve o kütüphanedeki kopya sayısını tutar. BookLoans, kullanıcının hangi kopyayı hangi tarihte aldığını tutar; iade sırasında ceza alınırsa kullanıcının geç iade alanına işlenir ve böylece cezalı olduğu anlaşılır. BookGenres bir kitabın birden çok türünü tutmak için kullanılır (bir kitaba çok tür). Libraries tablosundaki raf koordinatı ve ölçü alanları, kitabın kütüphanedeki konumunun hesaplanıp kroki olarak gösterilmesi için kullanılır.

### 8.2 Belge tabanlı tasarım örneği

Kulüp yönetim sistemi grubu belge tabanlı (NoSQL) bir veri tabanı (MongoDB) kullanmıştır. Belge tabanlı veri tabanında farklı yapıdaki veriler aynı koleksiyonda saklanabilir. Kulüp başkanı, yardımcısı ve saymanın kulüp bilgisine ihtiyacı varken departmanların ve üst birimin yoktur; ama hepsi aynı kullanıcı sınıfının alt türleri olduğu için tek bir kullanıcı koleksiyonunda tutulmuştur. Veri tabanında kullanıcı, kulüp ve sohbet koleksiyonları vardır. Etkinlikler kulüplere bağlı olduğu için ayrı koleksiyon açılmamış, kulüp belgesinin içinde saklanmıştır. Grup sunucu tarafında bir REST API kurmuş; kullanıcı sınıflarında nesneye yönelik, gelen isteklerin onaylanmasında yapısal bir bakış kullanıldığını ve ikisinin arka uçta birleştirildiğini anlatmıştır.

Bu grup ayrıca E-R diyagramında danışman, departman, üst birim ve kulüp yönetimi (başkan, sayman, yardımcı) varlıklarının etkinlik ve evrak işlemleri üzerinden etkileştiğini göstermiştir. Kullanıcı grupları ve yetkileri şöyle tanımlanmıştır (ekrandan, 01:05:00):

- Kulüp yönetimi: kulüp başkanı, yardımcısı ve sayman; hepsi aynı yetkiye sahiptir, kulüp üyelerini görüntüleyip düzenleyebilir, evrak ve etkinlik başvurusu yapabilir ve taslakları düzenleyebilir.
- Danışmanlar: her kulübün en az bir danışmanı vardır; kulübün işlemlerini onaylar ya da reddeder, kulüp yönetimini değiştirebilir, onayladığı etkinlikler ilgili departmana iletilir.
- Departmanlar: kendilerine ulaşan etkinlikleri denetler, bütün kulüplerle iletişime geçebilir, onayladığı etkinlikler üst birime iletilir.
- Üst birim: bütün kulüpleri denetler, etkinlik ve evrakların ulaştığı son birimdir; kulüp yönetimlerini değiştirebilir, yeni kulüp açabilir ve var olanı kapatabilir.

Bu yetki zinciri, bir onay iş akışının (kulüp, danışman, departman, üst birim) analizde aktörler ve sorumluluklar olarak nasıl tanımlanacağına iyi bir örnektir.

## 9. Ara birim tasarımı

Bir oylama grubu ara birim tasarımına kâğıt üzerinde mobil ekran eskizleriyle başlamış, ardından web arayüzünü bir tasarım aracında (Figma) hazırlamıştır. Dikkati dağıtmamak için mavi tonları ve soluk renkler, sade bir düzen seçilmiştir. Tasarım ekranlarında giriş ekranı, aktif oylamalar listesi (her oylamada açıklama, oy sayısı ve kalan süre), sonuçlanan oylamalar (kazanan seçenek ve sonuçlanma tarihi) ve seçeneklerin sıralanarak oy verildiği oylama ekranı yer alır (ekrandan, 00:20:00). Kullanıcıların uygulamada uzun süre geçirmesi istenmediği için arayüz yalnız gerekli işlevlerle sınırlanmıştır.

Bir kütüphane grubu arayüzü ekran ekran anlatmıştır: tema seçeneği olan giriş ekranı, üyelik ekranı, kullanıcının aldığı kitapların görüldüğü ana sayfa, kitap alma ve kütüphaneleri görme ekranı, bağış ekranı ve kullanıcının elindeki kitapları ve bütün yorumlarını gösteren profil ekranı. Otopark grubu gişe görevlisinin işlerini kolaylaştırmak için abonman işlemleri, park işlemleri ve otopark durumu için ayrı açılır pencereler tasarlamıştır.

## 10. Gerçekleştirme: teknoloji seçimi ve güvenlik tasarımı

### 10.1 Teknoloji seçimi gerekçeleri

Sunumlarda teknoloji seçimleri gerekçeleriyle anlatılmıştır. Bu gerekçeler, tasarım aşamasındaki teknik fizibilite kararlarının örnekleridir:

- Mobil uygulama için React Native: geniş topluluk ve kütüphane desteği; tek kod tabanından Android, iOS ve Windows uygulaması çıkarabilme; arada emülasyon katmanı olmadan doğrudan sistemle haberleşme.
- Ön yüz için Flutter (Dart): tek seferde web, Android ve iOS uygulaması tasarlayabilme; dilin Java'ya benzemesi.
- Arka uç için FastAPI (Python): güvenlik araçları (şifreleme, özetleme), modeller ve şemalarla nesneler arası ilişkileri kurma kolaylığı, çok sayıda eş zamanlı kullanıcıyı destekleyecek asenkron çalışma.
- Arka uç için Java (Jersey, Spring Boot): ekip üyelerinin çoğunun Java bilmesi; web servislerini kolay geliştirme.
- PostgreSQL: nesneler arası ilişkilerin modellenmesinde performans ve güncel asenkron kütüphaneler.
- MongoDB: belli boyuta kadar ücretsiz kullanım, kullanıcı sayısı sınırlı bir sistem için yeterli.
- SQLite: sunucu yazılımı gerektirmeyen bir SQL motoru, geliştirme ekibine kolaylık.
- Veri tabanı ve sunucunun ayrı Docker konteynerlerinde çalışması: biri ele geçirilse bile saldırganın diğer tarafa geçmesi zorlaşır.

### 10.2 Güvenlik tasarımı örneği

Kulüp yönetim sistemi grubu güvenlik tasarımını şöyle anlatmıştır. Arka uç veri tabanına nesne kimlikleri üzerinden erişir, ancak ön yüzün bu kimliklere erişimi yoktur; ön yüz, grubun geliştirdiği bir algoritmayla üretilen ayrı bir genel kimlik (public ID) ile çalışır. Kullanıcı adı ve parolayla giriş yapan kullanıcıya bir token verilir ve sonraki bütün isteklerde bu token istenir. Token, kullanıcının nesne kimliği, zaman damgası ve rastgele sayıların SHA-256 ile özetlenmesiyle oluşur. Kullanıcı kimlik bilgilerini yalnız bir kez girer. İki farklı yerden giriş yapılırsa son girişin olduğu adresle devam edilir. 30 dakika boyunca istek göndermeyen kullanıcı sistemden atılır. Kulüp yönetimi yalnız kendi kulübüyle ilgili kısımlara istek gönderebilir. Sunucu bellekte her oturum için token, nesne kimliği, son giriş ve son etkinlik zamanını tutar. Bir oylama grubu ise kullanıcı kaydı sırasında parolanın özetlenerek saklandığını göstermiştir.

> **Ek bilgi (derste anlatılmadı):** Parolalar genelde SHA-256 gibi hızlı özet fonksiyonlarıyla değil, tuzlama (salt) yapan ve kasıtlı olarak yavaş çalışan bcrypt, scrypt ya da Argon2 gibi algoritmalarla saklanır. Hızlı özet fonksiyonları token üretimi gibi işlerde uygundur, ancak parola saklamada kaba kuvvet denemelerini kolaylaştırır.

## 11. Örnek alan bilgisi: sıralı oylama ve Schulze yöntemi

Bir oylama projesi, sistemin çekirdeğindeki Schulze yöntemini kısaca anlatmıştır (proje kapağı, ekrandan, 00:05:00). Klasik oylamada her seçmen tek bir adaya oy verir; bu da çoğunluğun %51 ile kazandığı, kalan %49'un temsil edilmediği sonuçlara yol açabilir. Schulze yönteminde ise seçmen bütün adayları tercih sırasına dizer. Oylar toplanınca adaylar ikişer ikişer karşılaştırılarak bir matris kurulur: her (A, B) hücresine A'yı B'ye tercih eden seçmen sayısı yazılır. Bazı oylama sistemleri bu matrisle yetinir; Schulze yöntemi bir adım ileri gider ve bu matristen yönlü bir graf kurar.

Grafta amaç adaylar arasındaki en güçlü bağlantıyı (en güçlü yolu) bulmaktır. Sunumdaki örnekte B ile D arasındaki en güçlü bağlantı doğrudan bağlantıdır ve gücü 33'tür. A ile C arasında ise doğrudan bağlantının gücü 26 iken, D üzerinden geçen A-D-C yolunun gücü 28'dir; yani A'dan C'ye en güçlü bağlantı 28 olur. Bütün çiftlerin bağlantı güçleri bu şekilde belirlendikten sonra adaylar birbirine göre sıralanır ve birinci, ikinci, üçüncü belirlenir. <!-- BELİRSİZ: Sunumdaki tercih matrisi ve graf ekranda okunmuyor; örnekteki 33, 26 ve 28 değerleri altyazıdan alınmıştır. -->

> **Ek bilgi (derste anlatılmadı):** Schulze yönteminde bir yolun gücü, yol üzerindeki en zayıf bağlantının gücüdür; iki aday arasındaki güç ise bütün yollar arasında en güçlü olanın gücüdür (en geniş yol problemi). Bu güçler Floyd-Warshall algoritmasına benzer bir yöntemle hesaplanır. A'dan B'ye güç, B'den A'ya güçten büyükse A, B'nin önünde sıralanır.

## 12. Hocanın genel geri bildirimleri: yaklaşım ve diyagram tutarlılığı

Sunumlar boyunca hocanın yaptığı en önemli yorum, analiz ve tasarımda seçilen yaklaşımın bütün belgelerde tutarlı olması gerektiğidir. Bir kütüphane grubu tasarımını yapı diyagramıyla anlatırken hoca yazılımın nesneye yönelik mi yoksa yapısal mı hazırlandığını sormuştur. Grup nesneye yönelik hazırladığını söyleyince, yapı diyagramının iyi hazırlandığını ama sıralama diyagramının da hazırlanıp hazırlanmadığını sormuş, hazırlanmadığını öğrenmiştir.

> **Hocanın vurgusu:** Yazılımı nesneye yönelik hazırlıyorsanız tasarım da nesneye yönelik olacak. Yapısal yaklaşımla hazırlıyorsanız her şey yapısal yaklaşımla olacak.

**Soru:** Kullandığımız dil Java, yani nesneye yönelik bir dil; ama nesne özelliklerine pek ihtiyaç duymadık, yalnız arayüz kısmında kullandık. Bu durumda yazılım nesneye yönelik mi sayılır? **Cevap:** Java kullansanız da yazılımı yapısal yaklaşımla hazırladığınızı söyleyebilirsiniz. Belirleyici olan dil değil, sizin yaklaşımınızdır. Kitap işlemleri nesnelerle pek ilgili olmadığı için yapısal yazıldıysa, bunu yapı diyagramıyla belgelemek doğrudur.

Otopark grubunun ikinci düzey veri akış diyagramı üzerine hoca, ikinci düzeyde bütünlük olmadığını, her süreç için ayrı ve ayrıntılı bir diyagram çizildiğini hatırlatmıştır (Bölüm 5.3). Bu grup nesneye yönelik tasarım yaptığı hâlde veri akış diyagramlarını da hazırlamıştı; hoca bunu da kayda geçirmiştir. Kulüp yönetim sistemi grubunun sunumundan sonra hoca veri tabanı tasarımını yeniden görmek istemiş, sınıf diyagramı ya da E-R diyagramı olup olmadığını sormuştur; grup bütün diyagramları raporda verdiğini belirtmiştir.

Oturumun sonunda hoca üç farklı örnek görüldüğünü belirterek sonraki sunumlar için şu öneriyi yapmıştır: sunuma başlamadan önce projenin yapısal mı yoksa nesneye yönelik mi hazırlandığı düşünülmeli ve sunuma hangi diyagramların konacağına buna göre baştan karar verilmelidir.

## Örnek Sorular

- (derste sözlü, 00:37:20) Bir proje ekibi tasarımını yapı diyagramıyla belgelemiş, ama yazılımı nesneye yönelik hazırladığını söylüyor. Bu belgeleme tutarlı mıdır, eksik olan nedir?

  > **Çözüm:** Tutarlı değildir. Nesneye yönelik hazırlanan bir yazılımın tasarımı da nesneye yönelik modellerle (UML sınıf diyagramı, sıralama diyagramı) belgelenmelidir; yapı diyagramı yapısal yaklaşımın tasarım modelidir. Eksik olan sıralama (ve sınıf) diyagramıdır. Yazılım gerçekte nesne özellikleri kullanılmadan yazıldıysa, yapısal yaklaşımla hazırlandığı söylenip yapı diyagramıyla belgelenebilir.

- (derste sözlü, 00:38:23) Programlama dili Java olan bir projede yaklaşım otomatik olarak nesneye yönelik mi sayılır?

  > **Çözüm:** Hayır. Belirleyici olan dil değil, geliştiricinin yaklaşımıdır. Nesne kavramları (sınıf, kalıtım, nesneler arası mesajlaşma) tasarımda kullanılmadıysa yazılım yapısal yaklaşımla hazırlanmış sayılabilir ve analiz ile tasarım belgeleri buna göre seçilir.

- (derste sözlü, 00:51:20) İkinci düzey veri akış diyagramı bütün sistemi tek diyagramda mı göstermelidir?

  > **Çözüm:** Hayır. Birinci düzey diyagram bütün uygulamayı bir arada gösterir. İkinci düzey diyagram ayrıntı vermek içindir ve birinci düzeydeki her süreç için ayrı ayrı çizilir; bütün sistem tek bir ikinci düzey diyagramda birleştirilmez.

- (derste sözlü, 00:59:05) Bir proje sunumuna hangi diyagramların konacağına nasıl karar verilir?

  > **Çözüm:** Önce projenin yapısal mı yoksa nesneye yönelik mi hazırlandığına bakılır. Yapısal yaklaşımda bağlam (taslak) ve düzeyli veri akış diyagramları ile yapı diyagramı; nesneye yönelik yaklaşımda kullanım durumu diyagramı ve senaryo dokümanı, sınıf diyagramı ve sıralama diyagramı konur. Veri tabanı tasarımı (E-R diyagramı) ve fizibilite ile zaman planı (Gantt, PERT) her iki yaklaşımda da yer alır.

## Dersin Toparlaması

Bu oturumda dönem boyunca işlenen sistem analizi ve tasarımı adımları öğrenci projeleri üzerinden bütün olarak görülmüştür: müşteriyle gereksinimlerin toplanıp fizibilite açısından değerlendirilmesi ve pazarlıkla kapsamın netleştirilmesi; teknik, ekonomik, kaynak, zaman ve yasal fizibilite; nesneye yönelik analizde kullanım durumu diyagramı ve senaryo dokümanı, yapısal analizde düzeyli veri akış diyagramları; tasarımda sınıf ve sıralama diyagramları ya da yapı diyagramı; E-R diyagramı ve koleksiyon tasarımı; ara birim tasarımı ve teknoloji seçimlerinin gerekçelendirilmesi.

Hocanın bütün sunumlar için geçerli ana mesajı, seçilen yaklaşımın analizden tasarıma kadar tutarlı uygulanması ve belgelerin bu yaklaşıma göre seçilmesidir. Dil seçimi yaklaşımı belirlemez; ikinci düzey veri akış diyagramları her süreç için ayrı çizilir. Sonraki oturumda kalan grupların sunumlarına devam edilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
