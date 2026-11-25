# Ders 14 Genişletilmiş Notu: Dönem Projesi Proje Planı Sunumları: Kabul ve Kısıtlar, İş Kırılım Yapısı, Gantt Çizelgesi ve Risk Planı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

Bu derste öğrenciler dönem projelerinin proje planlarını sundu. Bazı öğrenciler kendi tasarladıkları bir projeyi, bazıları daha önce yaptıkları ya da yürütülen bir projeyi proje planı biçimine dönüştürerek anlattı. Hoca her sunumda proje tanımını kısa tutturup planın kendisine geçilmesini istedi ve özellikle kabul ve kısıtları, süreç modelini, iş kırılım yapısını, Gantt çizelgesini, kilometre taşlarını ve risk tablosunu sordu. Sunumlar aşağıda ders sırasıyla verilmiştir; sunum yapanlar "bir öğrenci" ya da "bir grup" diye anılır. Hocanın sunumlar boyunca tekrar ettiği genel ilkeler son bölümde toplanmıştır.

## İçindekiler

- 1. Toptan alışveriş e-ticaret sistemi
- 2. Web sitesi değişikliklerini izleyen Telegram botu
- 3. Hidroponik tarım için dijital veri takip sistemi
- 4. Araç finansmanı başvurusunun dijital kanala taşınması
- 5. Hastane yönetim sistemi
- 6. Bir kamu bilgi sisteminde duyuru yönetim modülü
- 7. POS cihazı yazılımı
- 8. İHA sürüsü ile kol uçuşu
- 9. Göğüs kanseri histopatoloji görüntülerinin sınıflandırılması
- 10. Erasmus öğrencileri için ders denkliği platformu
- 11. Türkçe yazım denetimi ve değerlendirme aracı
- 12. Mobil imza platformu
- 13. Uzaktan algılama ile av balığı yoğunluğu tahmini
- 14. İş güvenliği raporu paylaşım platformu
- 15. Metinlerin çizge veri tabanında tutulması
- 16. Online sağlıklı beslenme rehberi
- 17. Benzin istasyonlarında dağıtık yazılım güncelleme
- 18. Hocanın proje planı için genel ilkeleri
- Örnek Sorular

## 1. Toptan Alışveriş E-Ticaret Sistemi

### 1.1 Tanım ve gereksinimler

İlk sunum, toptan alışverişi hedefleyen bir e-ticaret sistemiydi. Sunucuya göre çıkış noktası, salgın döneminde ortaya çıkan lojistik ve tedarik zinciri sorunlarıdır: bir alıcı her zamanki toptancısından mal tedarik edemediğinde alternatif toptancıları hızlıca bulabilmelidir. Kullanıcılar sisteme kayıt olur, ürün seçer, satın alır, sonra ürünü ve toptancıyı değerlendirir.

İşlevsel gereksinimler dört modüle ayrıldı (ekrandan, 00:10:00):

- Kullanıcı kayıt modülü: kullanıcıların takibi için. Kayıtta ad, soyad, adres ve telefon alınır, kayıt yöneticiler tarafından onaylanır.
- Ürün modülü: toptancılar stok miktarlarını kendileri girer; ürünler alt kategorilere ayrılabilir (örneğin iplik rengine ya da cinsine göre, tişört kumaşına göre).
- Satın alma modülü: ilk aşamada yalnız kredi kartıyla ödeme; ileride havale ve vadeli ödeme eklenebilir.
- Yönetici modülü: argo, küfür ya da hakaret içeren yorumlar filtreye takılır ve yönetici onaylamazsa yayımlanmaz; ürün ekleme ve kaldırma da yönetici onayındadır. Buradaki yönetici, toptancının kendi yönetim ekranıdır.

İşlevsel olmayan gereksinimler verimlilik, kullanılabilirlik, güvenilirlik, memnuniyet ve arayüzün işlevselliğiydi. Verimlilik için sistemin yaklaşık 10 bin kullanıcıyı destekleyebilmesi hedeflendi. Kullanılabilirlikte kullanıcının aradığı ürünü alt kategoriler içinde rahatça bulabilmesi istendi. Güvenilirlik için, bir toptancıdan mal yanlış ya da geç geldiğinde analistlerin durumu inceleyip bir kez bile olsa hata durumunda o toptancıyla çalışmayı bırakması öngörüldü.

### 1.2 Ekip ve plan

Ekip iki yazılımcı, iki analist, bir sistem mimarı ve bir test uzmanından oluşuyordu. Analistler saha araştırması yapacak ve alıcılarla toplantıları organize edecekti.

Kabul ve kısıtlar birlikte verilmişti: proje en fazla 3 ayda kullanıcıya açılmalı, mevcut ekiple tamamlanmalı, kullanıcı ve kredi kartı bilgileri nedeniyle güvenlik üst düzeyde olmalı ve altyapı 10 bin aktif kullanıcıya göre kurulmalıydı. Hoca burada kabullerin ve kısıtların ayrı ayrı gösterilmesinin daha uygun olduğunu, bunu bir önceki derste de söylediğini hatırlattı.

Süreç modeli olarak şelale (waterfall) seçildi. Gözden geçirme kuralları: analiz, tasarım, gerçekleştirme ve test aşamalarının her birinin sonunda (kilometre taşlarında) bütün ekibin katıldığı bir gözden geçirme yapılacak ve sonuçlar yazılı raporlanacaktı.

### 1.3 Aktivite listesi

Aktivite listesi, bir iş kırılım listesi tablosu olarak verildi (ekrandan, 00:15:00). Sütunlar WBS numarası, görev adı, süre, başlangıç, bitiş, öncüller (predecessors) ve kaynak adlarıydı. Tablonun ana satırları şöyleydi:

| WBS | Görev | Süre | Başlangıç | Bitiş |
|---|---|---|---|---|
| 0 | E-Ticaret Sistemi | 71 gün | 13.05.2023 | 19.08.2023 |
| 1 | Analiz | 7 gün | 13.05.2023 | 21.05.2023 |
| 1.1 | Fizibilite çalışması (teknik, ekonomik, zaman) | 6 gün | 13.05.2023 | 20.05.2023 |
| 1.2 | Gereksinimlerin belirlenmesi | 4 gün | 16.05.2023 | 21.05.2023 |
| 1.3 | Analizin bitmesi | 0 gün | | |
| 2 | Tasarım (ön tasarım, ayrıntılı tasarım) | 22 gün | 22.05.2023 | 20.06.2023 |
| 2.3 | Tasarımın bitmesi | 0 gün | 20.06.2023 | 20.06.2023 |
| 3 | Gerçekleştirme (kodlama, veri tabanı kodlama) | 19 gün | 26.06.2023 | 22.07.2023 |
| 3.3 | Gerçekleştirmenin bitmesi | 0 gün | 04.07.2023 | 04.07.2023 |
| 4 | Test (birim, bütünlük, sistem, alfa-beta) | 17 gün | 26.07.2023 | 19.08.2023 |
| 4.5 | Testlerin tamamlanması | 0 gün | 19.08.2023 | 19.08.2023 |

Ön tasarım modüllerin ve kısıtların belirlenmesini, ayrıntılı tasarım alt modüllerin belirlenmesini, arayüz tasarımını, veri tabanı tasarımını ve use case diyagramlarını içeriyordu. Süresi 0 gün olan "bitiş" görevleri her aşamanın sonundaki dönüm noktasını gösterir.

> **Ders sonrası not:** Ana aşama süreleri toplamı (7 + 22 + 19 + 17 = 65 gün) 71 günden azdır; aradaki fark büyük olasılıkla aşamalar arasındaki boşluklardan (21.05 → 22.05, 20.06 → 26.06, 22.07 → 26.07) gelir. Tabloda "Gerçekleştirmenin Bitmesi" 04.07.2023'te görünürken gerçekleştirme 22.07.2023'te bitiyor; bu da büyük olasılıkla tablodaki bir tutarsızlıktır.

### 1.4 Gantt, kaynaklar ve diğer belgeler

Hoca Gantt diyagramını görmek istedi ve nerede hazırlandığını sordu. Gantt Excel'de hazırlanmıştı; hangi işin hangisi bitince başladığı görünüyordu (analiz bitmeden tasarım başlamıyor, tasarım bitince gerçekleştirme başlıyor), ama tarihler çizelgeye eklenmemişti. Hoca kilometre taşlarının çizelgede olmadığını belirtti; sunucu bunları metinde yazdığını, çizelgeye eklemediğini söyledi.

Kaynak ve maliyet planlamasında en önemli kaynak insan kaynağı olarak alındı. Use case diyagramlarında dört modül gösterilmişti; hoca extend ve include ilişkilerini gördüğünü söyleyip ayrıca bir use case belgesi olup olmadığını sordu. Test planında kodlama sırasında birim test, sonraki aşamalarda bütünlük ve sistem testleri ile kullanıcı kabul testi vardı. Risk planında beş önemli risk belirlenmişti; hoca sınavda da seçilen projenin risk planının yazılmasının istendiğini hatırlattı. Plan, projenin kapatılması bölümüyle bitiyordu.

## 2. Web Sitesi Değişikliklerini İzleyen Telegram Botu

### 2.1 Tanım ve kapsam

İkinci sunum, kullanıcıların verdiği web adreslerindeki değişiklikleri hem yapısal hem görsel olarak belirli aralıklarla kontrol eden bir Telegram botuydu. Telegram'ın masaüstü, web ve mobil platformların hepsinde bulunması sayesinde tek bir altyapı ile bütün cihazlarda çalışmak ve uyumluluk sorununu azaltmak amaçlanıyordu.

Proje kapsamı belgeden okundu (ekrandan, 00:20:00): veri girdileri ve çıktıları Telegram API kütüphanesi üzerinden gerçekleşir. Kullanıcı bota giriş yaptıktan sonra izlemek istediği sayfanın adresini ve izleme aralığını uygun komutlarla verir; değişikliklerin hash değeri tabanlı mı yoksa görsel tabanlı mı izleneceğini seçer. Görsel izlemede bot, son kontrolden bu yana değişen noktaları işaretleyen bir görüntü; hash tabanlı izlemede ise sayfanın hash değeriyle birlikte değişiklik durumunu döndürür.

### 2.2 Kabuller, kısıtlar ve gereksinimler

Kabuller (ekrandan, 00:20:00):

- Dört kişilik proje ekibinden proje süresince eksilme olmayacaktır.
- Bütçe planında belirtilen bütçe aşılmayacaktır.
- Sunucu günlük en az %99,9 çalışma süresine (uptime) sahip olacaktır.
- Bot Telegram üzerinde çalışacağından sistem güvenliği yüksek kabul edilmiştir.

Kısıtlar: sistem başlangıçtan en geç 3 ay sonra son kullanıcıya hazır olmalıdır; bütçe kısıtı nedeniyle sunucu performansı sınırlı olduğundan en fazla 200 eşzamanlı kullanıcıya hizmet verilebilir. Teslim edilecekler proje dokümanı, kaynak kodlar ve veri tabanı dosyalarıydı; hoca kaynak kodun da teslim edileceğini not etti.

İşlevsel gereksinimlerden örnekler: kullanıcı daha önce gönderdiği ve henüz dönüş almadığı talepleri güncelleyebilmeli, iptal edebilmeli ve listeleyebilmelidir; sunucu Telegram servisine her zaman bağlı olmalı ve güncellemeleri düzenli çekmelidir. İşlevsel olmayan gereksinimler performans, güvenlik, uygunluk, bakım, taşınabilirlik ve kullanım kolaylığıydı. Performans eşzamanlı isteklerin darboğaza girmeden karşılanması için önemliydi. Güvenlik, Telegram'ın güvenlik politikalarına dayandığı için öncelikli görülmedi, ancak veri tabanı güvenliği önemliydi. Bakım ise Telegram'ın sık güncellemelerine uyum için önemliydi.

Use case diyagramında bildirim talebi girme, görüntüleme, güncelleme (silme de eklenmeliydi), sorgulama sıklığı (polling frekansı) ve adres girme vardı. Varlık-ilişki diyagramında kullanıcı, kullanıcı istekleri ve bir sitenin o anki halini tutan anlık görüntü (snapshot) tabloları yer alıyordu.

### 2.3 Ekip, iş kırılımı ve Gantt

Ekip bir proje yöneticisi, iki yazılımcı ve bir test mühendisinden oluşuyordu. Proje yöneticisi planlama, temin ve organizasyonda görev alıp müşteriyle periyodik görüşmeler yapacaktı. Teknik planda araçlar belirtilmişti: sürüm kontrolü için Git, geliştirme için Eclipse.

İş kırılım yapısı grafik olarak oluşturulmuştu. Hoca burada önemli bir not düştü:

> **Hocanın vurgusu:** İş kırılım yapısı (Work Breakdown Structure) grafik ağaç olarak da, sayılarla iç içe numaralı liste olarak da gösterilebilir. İkisi de doğrudur; ikisi de WBS'nin gösterim şeklidir.

İş kırılımı analiz, tasarım, geliştirme, test, teslimat ve bakım aşamalarından oluşuyordu; analizde fizibilite, gereksinim analizi ve analiz sonu toplantısı, tasarımda sistem mimarisi, nesneye dayalı tasarım ve veri tabanı tasarımı vardı. Şelale seçildiği için yapı bu aşamalara göre kurulmuştu.

Gantt çizelgesi yaklaşık 12 haftalık bir projeyi gösteriyordu (ekrandan, 00:25:00). Çizelgede ana aşamalar (Analiz, Tasarım, Geliştirme, Test) ardışık çubuklarla, her aşamanın sonundaki kilometre taşı sarı elmasla gösterilmişti. Geliştirme altında Telegram API entegrasyonu, Selenium WebDriver entegrasyonu, iş parçacığı havuzu (thread pool) yapısının kodlanması ve veri tabanı entegrasyonu; test altında birim, entegrasyon, sistem ve kullanıcı testleri; en sonda teslimat kilometre taşı ve proje teslim toplantısı vardı. Çizelge çevrimiçi, açık kaynaklı bir araçla hazırlanmıştı.

### 2.4 Bütçe ve risk

Bütçede personel (yazılım ve test mühendislerinin maaşları), bakım giderleri, bilgisayarlar ve sunucular vardı. Bakım kaleminin gerekçesi, proje bittikten sonra da Telegram güncellemelerine uyum için personele ödeme yapılması gerekmesiydi.

Risk planı:

- Personelin projeden ayrılması: etkisi büyük, olasılığı düşük. Önlem: ekip motivasyonunu artırma, çalışma koşullarını iyileştirme.
- Ekipmanın yetersiz kalması (teknik risk): etkisi orta, olasılığı yüksek. Önlem: daha yüksek performanslı donanım temini.
- Kütüphanelerin yeni güncellemelerle çalışmaz hale gelmesi (teknik risk): etkisi büyük, olasılığı yüksek. Önlem: düzenli denetim ve bakım.
- Pazar riski, kullanıcı sayısının öngörülerin altında kalması: olasılığı ve etkisi orta. Önlem: internet reklamları.

## 3. Hidroponik Tarım İçin Dijital Veri Takip Sistemi

### 3.1 Tanım

Üçüncü sunum, daha önce hobi olarak kovalarla mekanik biçimde kurulan bir topraksız (hidroponik) tarım düzeneğinin dijital veri takipli, ileride otonom bir versiyonunu planlıyordu. İlk etapta marul yetiştirilmesi, bitki için önemli olan pH, EC (elektriksel iletkenlik), ışık ve nem gibi parametrelerin en uygun aralıkta tutulması hedefleniyordu. İlk amaç dijital verileri toplayıp en uygun değerleri bulmak; sonraki aşamada sistem bir uyarı verdiğinde otonom olarak kendini ayarlayacaktı. Genel amaçlar sürdürülebilirlik, suyun etkin kullanımı ve verimliliğin artırılmasıydı.

Veriler Arduino ekosistemiyle alınacak, kart olarak ESP32 kullanılacaktı. ESP32 seçiminin nedeni Wi-Fi ve Bluetooth desteğiydi; böylece veriler hem web platformundan hem mobil uygulamadan izlenebilecekti.

### 3.2 Gereksinimler, kabul ve kısıtlar

Kullanılabilirlik gereksinimleri olarak anlık veriye ulaşma, geçmiş verilerin tutulması ve istenen tarihteki verilerin görüntülenip indirilmesi, belirli bir zamana not ekleyebilme, kolay arayüz ve bütün platformlardan erişim yazılmıştı (ekrandan, 00:30:00). Sürdürülebilirlik başlığı altında kurulumun ayrıntılı ve estetik olmaması, kurulum ve bitki bakımı için ek bilgi gereksinimi belirtilmişti.

Kabuller: mevcut ekiple sürdürülmesi, belirlenen zaman aralığında ve her platformda çalışması. Elektronik bir sistem olduğu için devre arızası ve elektrik kesintisi gibi sorunların önceden kontrol edilmesi gerektiği belirtildi. Kısıtlar: bir sensörün bozulması gibi durumların bütçe ve zaman sorununa yol açabilmesi.

SWOT analizinde güçlü yan olarak kolay erişim, ekip içi iletişim ve yazılım deneyimi; fırsat olarak suyun öneminin arttığı bir çağda sürdürülebilirliğe katkı; tehdit olarak elektrikli bir sistemde donanım arızası sayıldı.

### 3.3 Süreç modeli, iş kırılımı ve risk

Tek bir deney düzeneği yapılacağı için şelale seçildi. Altı deney setiyle denemek düşünülmüş, ancak maliyet nedeniyle vazgeçilmişti; deney setlerinin artırılması aşamasında çevik yönteme dönülmesi planlanıyordu. Ekipte bitkinin büyümesini izleyecek bir biyolog, devre ve Arduino için elektrik-elektronik ekip üyeleri, bir programcı ve verileri analiz edecek bir analist vardı.

İş kırılım listesinde kilometre taşları koyu renkle işaretlenmişti: başlangıçta gereksinimler, analiz, fizibilite ve bütçe planlaması; tasarımda donanım (kova, boru düzeneği) ve yazılım tasarımı; gerçekleştirmede sensörler, veri tabanı iletişimi, Wi-Fi üzerinden veri alımı için API'ler ve bunların entegrasyonu; ardından test ve bakım. Test süresi yedi hafta olarak uzun tutulmuştu, çünkü bitki büyümesi zaman alır; bitki büyümesinin takibi bütün süreci kapsayan ayrı bir satır olarak konmuştu. Gantt Excel'de hazırlanmıştı.

Risk tablosu (ekrandan, 00:35:00):

| No | Risk tanımı | Risk seviyesi | Alınacak tedbir (B planı) |
|---|---|---|---|
| 1 | Yanlış sensör kullanımı, devre problemi, kısa devre, voltaj uyum problemi | Düşük | Donanım ve sistem bilgilerinin başlamadan önce ayrıntılandırılması ve sürekli test |
| 2 | Entegrasyon sorunu (donanım-yazılım uyumu) | Yüksek | Sistem kurulmadan önce sürüm ve uyum bilgilerinin ayrıntılandırılması |
| 3 | Teknik sorun (elektrik-su kaçağı, yangın vb.) | Orta | Olasılıkların hesaba katılarak sistemin izole edilmesi |
| 4 | Sistemin olağan dışı çalışıp bitki büyümesine engel olması | Düşük | Günlük veri takibiyle değişimin gözlenmesi |
| 5 | Uyarı sisteminin normal dışı tepki vermesi | Düşük | Sürekli yazılım-donanım kontrolü |
| 6 | Bütçenin yetersiz gelmesi | Düşük | Sponsor sayısının artırılması |

Hoca risk seviyesinin olasılık ve etki belirlenmeden mi yazıldığını sordu; sunucu belirlemeden yazdığını kabul etti.

> **Hocanın vurgusu:** Risk seviyesi "kafadan" yazılmaz; önce olasılık ve etki ayrı ayrı belirlenmeli, seviye bunlardan çıkarılmalıdır.

Bütçede yalnız sensör, kova gibi teknik malzemeler hesaba katılmış, tek bir sistem için yaklaşık 12 bin (birim söylenmedi) gibi bir bütçe çıkmıştı. Projenin kapanış hedefi, bir sonraki otonom sistem için en uygun değerleri elde etmekti.

## 4. Araç Finansmanı Başvurusunun Dijital Kanala Taşınması

Dördüncü sunum, bir bankacılık sisteminde şubeden başlatılan araç finansmanı başvurusunun dijital kanala taşınmasıydı. Müşteri şubeye gitmeden mobil uygulamadan başvurudan ödemeye kadar bütün işlemleri yapabilecek, satıcı da bir web sitesinden süreci izleyebilecekti. Hedefler kolay ve hızlı bireysel finansman, genel müdürlük ve şubelerde operasyonel verimlilik, müşteri deneyiminin artması ve üçüncü taraflarla hızlı entegrasyondu.

Proje iki fazdan oluşuyordu: ilk fazda yalnız başvuru mobilden yapılacak, ikinci fazda uçtan uca bütün süreç mobilden tamamlanacaktı. Akış şöyle anlatıldı: müşteri önce bir ön onaydan geçer (riskli meslek, yaş sınırları, finansmana uygunluk gibi kontroller); sonra satın alacağı aracın bilgileri (sıfır ya da ikinci el, model yılı, marka, model, satış bedeli, plaka), ardından istenen finansmanın bilgileri (vade, taksit sayısı, ilk taksit tarihi) girilir; sözleşme ve belge ekleme adımlarından sonra başvuru yetkililer tarafından değerlendirilir. Müşteri için bir safha izleme ekranı tasarlanmıştı (ekrandan, 00:40:00). Hoca bununla ilgili use case diyagramı olup olmadığını sordu; çizilmemişti.

Proje paydaşları (ekrandan, 00:40:00): proje sponsoru, genel müdür yardımcılarından oluşan iki kişilik bir proje yönlendirme komitesi ve müdürlerden oluşan, on kişiden fazla bir proje yürütme komitesi. Ekipte altı bilgi teknolojileri ekibi, iş birimi, test mühendisleri ve üçüncü taraf firmalar vardı; ekipler arası bağımlılıklar fazla olduğu için planlama buna dikkat edilerek yapılacaktı.

Çalışma metodolojisi çevikti (agile). Faz 1 için yaklaşık 4 aylık, faz 2 için yaklaşık 12 aylık bir geliştirme süreci, yalnız bilgi teknolojileri ekipleri için toplam yaklaşık 2000 adam-günlük bir iş planlanmıştı. Aşamalar gereksinimlerin çıkarılması, ön analiz, kullanıcı deneyimi (UX) tasarımı, analiz, geliştirme ve testti. İletişimde bütün ekip haftalık toplanacak, yönlendirme ve yürütme komiteleriyle ihtiyaç halinde görüşülecekti. Plan Gantt yerine bir şema olarak çevrimiçi bir araçla gösterilmişti.

Riskler: şubeye düşen işlemlere geç dönüş yapılmasının müşteri memnuniyetsizliğine yol açması, bir paydaşın ayrılmasının gecikme ve kalite düşüşüne yol açması, tamamen dijital süreç tasarımında müşteri deneyiminin çok değişmesi. Kazanımlar: kasko değeri gibi kontrollerin çalışanın inisiyatifinden çıkıp sisteme bağlanması ve hataların azalması; şubeye gitmeden yaklaşık iki saatte finansmanın sonuçlanması.

## 5. Hastane Yönetim Sistemi

Beşinci sunum İngilizce yapıldı ve büyük veriyle çalışan bir hastane yönetim sistemini anlattı. Slayt başlıkları şunlardı (ekrandan, 00:45:00 ve 00:50:00): proje alanı, fizibilite analizi, yazılım geliştirme süreç modeli, risk tablosu, Gantt diyagramı, proje organizasyon yapısı, yazılım gereksinim analizi ve sistem analizi, use case belgesi ve sınıf diyagramı.

Proje alanı slaytında üç madde vardı: büyük miktarda veri, optimal yazılım ve kamu sağlık sistemlerinin kötü ve kullanımı zor olması. Proje organizasyon yapısı olarak bir proje yönlendirme komitesi seçilmişti; yapı şu rollerden oluşuyordu: proje yönlendirme komitesi, müşteri onaylayıcısı, müşteri proje yöneticisi, kullanıcı temsilcileri ve proje yöneticisi. Sunucuya göre yönlendirme komitesi, kapsam ya da bütçe değiştiğinde süreç hakkında rehberlik ve yön veren paydaşlardan oluşur. Ekipte ön yüz (front-end), arka uç (back-end) ve veri tabanı mühendisleri ile proje yöneticisi vardı; araçlar arasında Java, Eclipse ve SQL sayıldı. Use case belgesindeki roller doktor, yönetici (admin), denetçi ve müdürdü.

Hoca proje planındaki kilometre taşını sordu; grup analiz sonunu (end of analysis) kilometre taşı olarak gösterdi.

<!-- BELİRSİZ: Bu sunumun altyazısı (yaklaşık 00:45:20 ile 00:51:30 arası) Whisper tarafından bozulmuş; süreç modeli, risk tablosu ve Gantt ayrıntıları okunamadı. -->

## 6. Bir Kamu Bilgi Sisteminde Duyuru Yönetim Modülü

### 6.1 Problem, kapsam ve tanımlar

Altıncı sunum, dernekler için kullanılan bir kamu bilgi sisteminde duyuru yönetim panelinin bulunmaması problemine çözüm olarak geliştirilen bir modüldü. Amaç, merkez ve taşra birimlerinin sistemi kullanan derneklere ve teşkilata gerekli bilgilendirmeleri yapabilmesiydi. Kapsam duyuru yönetimi için analiz çalışmalarını ve sistemin mikroservis yapısını içeriyordu.

Tanımlar bölümünde (ekrandan, 00:55:00) sivil toplum kuruluşu kullanıcısı, dernek (kanunlarla yasaklanmamış, belirli ve ortak bir amacı gerçekleştirmek üzere en az yedi gerçek veya tüzel kişinin oluşturduğu tüzel kişiliğe sahip topluluk), dernek şubesi, federasyon (kuruluş amaçları aynı olan en az beş derneğin oluşturduğu üst kuruluş) ve konfederasyon (en az üç federasyonun oluşturduğu üst kuruluş) tanımlandı. Hoca tanımların geçilmesini istedi.

### 6.2 Süreç ve ekran tasarımı

Duyuruyu yapabilecek kullanıcılar merkez ve il/ilçe düzeyindeki yetkililerdi; use case diyagramında bu roller duyuru yapma ve var olan duyuruyu değiştirme işlemleriyle gösterilmişti. Duyuru ekranında şunlar seçiliyordu: uygulama, duyurunun gösterileceği il ve ilçeler, gönderim yolu (derneklere ya da teşkilata), kaç gün yayında kalacağı (aktif gün), ileri bir tarihe ayarlanabilen gönderim tarihi, öncelik durumu (yüksek, normal), eklenecek dosya, başlık ve duyuru metni. Ekran adımları ayrıca bir akış diyagramına ve madde madde iş kurallarına dökülmüştü; örneğin sayfayı kullanacak kişinin yetkisi önceden tanımlanmış olmalı, ilçe birimleri yalnız kendi teşkilatı içinde duyuru yapabilmeliydi.

### 6.3 Yaklaşım ve süreç modeli

Süreç modeli olarak şelale seçildi. Gerekçe Stacey matrisine dayanıyordu: ihtiyaçlar açık ve teknoloji biliniyor, dolayısıyla problem basit (simple) bölgededir; aşamaları belli olan bir problemde her aşamayı bitirip sonrakine geçmek etkilidir. Yaklaşımlar slaytına göre (ekrandan, 01:00:00) çalışmada klasik bir şelale yöntemi denenmiş, çıktılar ve isterler belliydi; duyuru yönetim modülü bir mikroservis olarak, web API kullanılarak tasarlanmıştı; yazılım geliştirme yaşam döngüsü planlama, analiz, tasarım, gerçekleştirme, bakım ve destek aşamalarından oluşuyordu.

> **Ek bilgi (derste anlatılmadı):** Stacey matrisi, gereksinimler üzerindeki uzlaşma ile teknolojinin kesinliğini iki eksende ele alır. İkisi de netse problem "basit" bölgededir ve öngörücü (plan güdümlü) yaklaşımlar uygundur; belirsizlik arttıkça "karmaşık" bölgeye geçilir ve çevik yöntemler daha uygun hale gelir.

### 6.4 Riskler ve hocanın yorumu

Zorluklar ve riskler: sistemi çok sayıda dernek kullandığı için yeni modüllerin sisteme entegrasyonu ve personelin eğitilmesi gerekir; yeni modüllerde test hataları sonucu hatalar (bug) çıkabilir; mikroservis modülünün analizi ve geliştirilmesi zordur. Hoca bir risk tablosu istedi; riskler yalnız madde madde sıralanmıştı. Sunumda ayrıca SWOT (güçlü yan: yeni teknoloji ve güçlü yazılım ekibi; zayıf yan: kullanıcıların eğitimsiz olması ve duyurudaki hiyerarşi), PEST ve balık kılçığı analizleri vardı.

Hoca balık kılçığı diyagramının özelliğini sordu (bkz. Örnek Sorular). Zaman planı ve Gantt sorulduğunda, proje zaten gerçekleştirilmiş olduğu için zaman planı konmadığı söylendi. Hoca bunu eksik saydı:

> **Hocanın vurgusu:** Proje gerçekleştirilmiş olsa bile plan, proje baştan başlıyormuş gibi oluşturulmalı ve zaman planı eklenmelidir.

## 7. POS Cihazı Yazılımı

Yedinci sunum, bankaların ödemelerini API'lerle gerçekleştiren POS cihazları için bir yazılımın planıydı. Proje iki ayda geliştirilip müşteriye teslim edilecek biçimde kapsamlandırılmıştı. Kapsam içinde iş gereksinimleri (business requirements), donanım ve yazılım gereksinimleri ile sistem fonksiyonlarının açıklamaları vardı. Hoca use case diyagramı sordu; çizilmemişti.

Geliştirme yöntemi olarak çevik Scrum seçilmişti. Plan tasarım, geliştirme ve diğer aşamalardan oluşan dört bölüme ayrılmış, kilometre taşları konmuştu. Sürüm verildikten sonra sürümlerin tutulacağı bir tablo, müşteri tarafında hata oluştuğunda hangi kanaldan bildirileceği ve hata takibi için bir hata takip sistemi tanımlanmıştı. Riskler tablo yerine liste halindeydi: sürüm değişiminde yedek alınması ve saklanması, POS bileşenleri değiştiğinde kapsamın gözden geçirilmesi gibi.

Hoca, sunulan belgenin şirkette oluşturulan teknik yapının doğrudan kendisi olduğunu belirtti ve bunun bütün sınıf için geçerli bir ilke olduğunu söyledi:

> **Hocanın vurgusu:** Şirkette yaptığınız bir işi sunabilirsiniz, ama oradaki genel belgeyi değil; derste verilen formata ya da bir proje destek başvurusu/teklif raporuna yakın biçimde, projeye yeni başlıyormuş gibi hazırlanmış bir plan sunulmalıdır. Kitaptaki şablon özetlenip istenen kısımlar genişletilerek sunulmalıdır.

## 8. İHA Sürüsü ile Kol Uçuşu

### 8.1 Proje özeti ve özgün değer

Sekizinci sunum iki kişilik bir gruptu ve planı bir araştırma projesi başvuru formu üzerinden anlattı. Konu küçük ölçekli insansız hava araçlarının (İHA) kol ya da formasyon uçuşuydu. İHA'lar petrol, gaz, tarım ve güvenlik gibi alanlarda kullanılır; tek İHA kullanımında yük kapasitesi, pil ömrü, arıza ve hız gibi sorunlar vardır. Kol uçuşu, İHA'ların belirli bir hedefe ulaşmak için koordineli uçuşudur ve İHA durumlarını birleştiren, yöneten ve yapıyı koruyan bir algoritmayla gerçekleştirilir.

Sunucuya göre literatürdeki çalışmalar sürüyü tamamen merkezden yönetir; ancak İHA'lar kontrol istasyonundan çok uzaklaştığında iletişim güvenliği ve elverişliliği bozulur. Önerilen çözümde yer istasyonu yalnız lider İHA ile haberleşir; diğer İHA'lar durum ve algı bilgilerini lidere iletir ve liderin kararlarını uygular. Bu yaklaşım literatürde lider-takipçi (master-slave) olarak bilinir. Dezavantajı, lider bozulduğunda sürü kontrolünün kaybolmasıdır; bu yüzden projede hataya dayanıklı lider seçimi de ele alınacaktı. Lider yapısı sürü içi kontrol mesajlarını azaltacak ve istasyona sürünün daha net anlık konum ve şekil bilgisini iletecekti.

### 8.2 Hedefler ve yöntemler

Hedefler: kol uçuşunda görev alabilecek İHA tasarımı, İHA'lara komut gönderip veri toplayan bir yer istasyonu, uçuş kontrol algoritması, sürü algoritmaları için simülasyon ortamı, sürü haberleşme sistemi, lider seçme algoritması ve rota planlama algoritması. Yöntemler belgeden okundu (ekrandan, 01:15:00):

1. Proje şelale yazılım geliştirme metodolojisiyle geliştirilecektir.
2. H1 için hazır iskelet, elektronik ve mekanik parçalar kullanılacak; uçuş kontrolcüsü için ARM tabanlı bir SoC (system on chip) seçilecek. SoC üzerinde Zigbee ve Bluetooth gibi wireless mesh protokollerini destekleyen bir RF bulunması, sürü haberleşmesi için şarttır.
3. H2 için İHA'ya komut gönderen ve gelen veriyi görselleştiren Qt tabanlı bir masaüstü uygulaması geliştirilecek.
4. H3 için PID tabanlı bir uçuş kontrol algoritması H1'deki SoC üzerinde gerçekleştirilecek.
5. H4 için Gazebo ile simülasyon ortamı oluşturulacak.
6. H5 için sürü içi haberleşme wireless mesh ağ üzerinde kurulacak; takipçi İHA'lardan lidere ve tersi yönde veri aktarılacak.
7. H6 için oylama tabanlı bir lider seçim algoritması (Raft) kullanılacak; sürü belirli aralıklarla oylama yaparak liderin konumunu güncelleyecek.
8. H7 için lider merkezli rota planlama komutları takipçi İHA'lara iletilecek; takipçiler gelen yörünge komutlarına göre pozisyonunu korumaya çalışacak.

> **Ek bilgi (derste anlatılmadı):** Raft, dağıtık sistemlerde bir küme içinde lider seçimi ve kayıt çoğaltması için tasarlanmış bir uzlaşma (consensus) algoritmasıdır. Lider belirli süre mesaj göndermezse düğümler aday olup oy toplar; çoğunluğun oyunu alan düğüm yeni lider olur. Bu özellik, liderin bozulmasına karşı dayanıklılık sağlar.

### 8.3 Gantt, iş paketleri, risk ve çıktılar

Gantt çizelgesi açık kaynaklı bir web uygulamasıyla hazırlanmıştı. İş üç temel parçaya ayrılmıştı: İHA'ların oluşturulması, yer istasyonu ve formasyon uçuşu. İHA oluşturma kendi içinde üç ana başlık ve bir kilometre taşından oluşuyordu (parça tedariki, montaj, motor testi gibi). Aynı anda yürüyebilen işler paralel, birbirini beklemesi gereken işler ardışık yerleştirilmişti; örneğin parça tedariki sırasında ekip başka işlere başlayabiliyordu. Başvuru formunda yedi ana iş paketi vardı; her hedef bir iş paketine karşılık geliyordu. Hoca planın şelaleye göre hazırlandığını onayladı ve gereksinimlerin form dışında use case ile belirtilip belirtilmediğini sordu; belirtilmemişti. Bütçenin iş paketlerine göre mi verildiğini sordu; bütçe malzeme tabanlıydı.

Risk tablosunda altı risk vardı; formda yalnız risk ve alınacak tedbirler istendiği için grup olasılığı kendisi eklemişti. Hoca "Peki etki nerede?" diye sordu; grup etkinin de eklenebileceğini söyledi. Tablodaki risklerden biri İHA ile yer istasyonu arasındaki haberleşmenin kopmasıydı; tedbir, belirli süre haberleşme paketi alamayan İHA'ların eve dönme ya da uygun yere iniş algoritmalarının uygulanmasıydı (ekrandan, 01:20:00).

Araştırma olanakları tablosunda kullanılacak ekipman, adetleri ve kullanım amaçları listelenmişti (ekrandan, 01:20:00): 2 adet i7 işlemcili 32 GB RAM'li dizüstü bilgisayar, 4 adet 22 inç monitör, 30 adet quadcopter iskelet ve motor kiti (geliştirme ve testler), 2 adet osiloskop, 1 adet multimetre, 3 adet MPU9250 sensör (9 eksen), 3 adet GPS ve uçuş kontrolcü kartının geliştirilmesi için 2 adet CC2652R7 LaunchPad. Öngörülen çıktılar: bilimsel olarak mesh ağ üzerinde dinamik lider merkezli uçuş üzerine bir makale, ekonomik olarak formasyon uçuşu yapabilen kontrolcü ve yer istasyonu ürünü; sonuçların teknoloji festivalleri ve savunma fuarları gibi etkinliklerde ilgili firmalara sunulması.

## 9. Göğüs Kanseri Histopatoloji Görüntülerinin Sınıflandırılması

Dokuzuncu sunum, öznitelik çıkarma yöntemleriyle göğüs kanseri görüntülerinin sınıflandırılması projesinin proje planına dönüştürülmüş haliydi. Veri kümesinde dört görüntü sınıfı vardı: normal, iyi huylu (benign), in situ ve invaziv. Veri kümesi göğüs kanseri histoloji görüntülerinden oluşuyordu.

> **Ek bilgi (derste anlatılmadı):** Altyazıda "BAH" diye geçen veri kümesi büyük olasılıkla BACH (BreAst Cancer Histology) veri kümesidir; bu kümede histopatoloji görüntüleri tam olarak bu dört sınıfa (normal, benign, in situ karsinom, invaziv karsinom) ayrılmıştır.

PERT ve Gantt diyagramında veri kümesinin ve makine öğrenmesi modellerinin araştırılması, görüntü işleme adımında hücre içeren bölgelerin yağ dokusundan ayrılması, uzamsal öznitelik çıkarma (HOG, SIFT, SURF, yerel ikili örüntü LBP) ve makine öğrenmesiyle sınıflandırma, ardından test ve birim testleri yer alıyordu. Gantt, Microsoft'un bir Gantt eklentisiyle hazırlanmıştı. Kabul ve kısıtlar birlikte yazılmıştı; hoca bunları ayırmanın daha iyi olacağını söyledi.

Risk analizinde beş risk vardı ve her biri için olasılık, etki, tür, açıklama ve önlem verilmişti (ekrandan, 01:25:00). Örnekler:

- Veri kümesinin bulut depolamadan okunurken hata vermesi (teknik): önlem, görüntülerin bulunduğu dosya yolunun kontrol edilmesi.
- Risk 3, görüntüleri yanlış sınıflandırma hatası: olasılık orta, etki yüksek, teknik; önlem, görüntülerin doğrulama veri kümesiyle önceden sınıflandırılmasının kontrolü.
- Risk 4, hücre görüntülerinden parça çıkarma işlemindeki hatalar: olasılık orta, etki yüksek, teknik; önlem, çıkarılan parçaların hücre içinden alınıp alınmadığının tespiti. Sunucu, yağ dokusunda hücre bulunmadığı için bu bölgelerin sınıflandırmaya alınmasının performansı çok düşürdüğünü anlattı.
- Risk 5, bulut tabanlı not defteri ortamında RAM yetersizliği.

Uzamsal öznitelik çıkarmada hata riski de orta olasılıklı ve yüksek etkili sayılmıştı, çünkü bu adımdaki hata doğrudan sınıflandırma performansını etkiler; önlem olarak öznitelikler çıkarıldıktan sonra ayrıca test edilmeleri öngörülmüştü. Ayrıca risklerin olasılık-etki grafiği çizilmişti; hoca hangi risklerin takip edileceğinin belirtildiğini not etti.

Kullanım senaryosu sırasıyla hücre tespiti, yağ dokusunun ayrıştırılması, görüntülerin farklı boyutlara çevrilip veri tabanına kaydedilmesi, öznitelik çıkarma ve sınıflandırmadan oluşuyordu. Varlık-ilişki diyagramında görüntüler üç boyutta (64×64, 128×128, 256×256) ve dört sınıf altında saklanıyordu. Hoca planın biraz daha dönüştürülmesinin daha iyi olacağını söyledi; sunucu risk analizi ve kullanım senaryolarını sonradan eklediğini belirtti.

## 10. Erasmus Öğrencileri İçin Ders Denkliği Platformu

Onuncu sunum, değişim programı kazanan üniversite öğrencilerinin ders denkliği, dersin öğretim dili ve bölüme göre ülke seçimi sorunlarına çözüm getirmeyi amaçlayan bir platformdu. Öğrenciler bölüm ve okul bilgileriyle üye olacak, hangi okullara gidebileceklerini ve derslerin hangi oranda İngilizce verildiğini görebilecekti. Dersi tam İngilizce olmadığı için alamayan öğrenciler için çevrimiçi kayıtlı derslerin altyazılı olarak sistemde tutulması da öngörülüyordu. İleride yurt dışındaki diğer okulları da kapsayan uluslararası bir proje olması amaçlanıyordu.

İşlevsel gereksinimler süreç ve yazılım diye ayrılmıştı; hoca bu ayrımı not etti. Süreçte öğrencinin gitmek istediği ülkelerdeki ders müfredatlarının ve üniversitelerin öğretim dili yüzdelerinin öğrenilmesi; yazılımda üyelik sayfası, öğrenci profili ve izlenen üniversitenin müfredatı değiştiğinde öğrenciye bildirim gönderilmesi vardı.

Metodoloji olarak Scrum seçildi: test etme ve sürüm kontrolü sayesinde hatalar erken bulunur ve hızlıca giderilir, erken çözülen sorunlar maliyet artışını önler, düzenli Scrum toplantılarıyla takımdaki herkes birbiriyle iletişimde olur ve kimin ne yaptığı belli olur. Ekip bir proje yöneticisi, bilgisayar mühendisleri, test uzmanı ve grafik tasarımcıdan oluşuyordu. Proje plan takvimi işletmenin kurulması, pazar analizi, gereksinim analizi, geliştirme ve demo-pazarlama aşamalarını aylara yayıyordu. İş kırılım listesinde başlangıç (talep dokümanı, başlangıç toplantısı), planlama, analiz, tasarım ve kodlama aşamaları vardı; kilometre taşları bu listenin devamındaydı.

Aktiviteler arası ilişkiler şöyle yazılmıştı (ekrandan, 01:35:00):

- Analiz bitmeden tasarım başlayamaz (F/S).
- Tasarım bitmeden kodlama başlayamaz (F/S).
- Analiz, planlama bitmeden bitemez (F/F).
- Analizle veri tabanı oluşturma aynı anda yürüyebilir (S/S).
- Dokümantasyon, kodlama bitmeden bitemez (F/F).
- Proje tamamlanmadan test tamamlanmalıdır (S/F).

> **Ek bilgi (derste anlatılmadı):** Dört bağımlılık türü şunlardır: bitiş-başlangıç (F/S, öncül bitmeden ardıl başlayamaz; en yaygını), başlangıç-başlangıç (S/S, öncül başlamadan ardıl başlayamaz), bitiş-bitiş (F/F, öncül bitmeden ardıl bitemez) ve başlangıç-bitiş (S/F, öncül başlamadan ardıl bitemez). Son maddedeki "proje tamamlanmadan test tamamlanmalıdır" ifadesi bu tanımlara göre büyük olasılıkla bir F/F ilişkisidir (testin bitişi projenin bitişini sınırlar); slayttaki S/F etiketi tartışmaya açıktır.

Risk tablosu (ekrandan, 01:35:00):

| No | Açıklama | Etkisi | B planı | C planı |
|---|---|---|---|---|
| 1 | Uygun mühendis bulunamaması | Yüksek | Farklı üniversitelerle iletişime geçilmesi | Proje süresinin uzatılması |
| 2 | İsteklerin değişmesi | Yüksek | Tüm isteklerin projeye başlamadan dokümante edilmesi | |
| 3 | Gerçekçi olmayan beklentiler | Orta | Beklentilerin önceden konuşulup netleştirilmesi | |
| 4 | Yeni ve bilinmeyen teknoloji | Düşük | Kullanılacak teknolojilerin önceden belirlenmesi | Yeni teknoloji kullanılacaksa önceden hazırlık yapılması |
| 5 | Kritik önemdeki personel kaybı | Orta | Personelin düzenli doküman hazırlaması | Yazılımcıların birlikte çalışması ve tüm akışa hakim olması |

Hoca risklerde olasılığa yer verilmediğini, etkinin olasılık düşünülerek mi belirlendiğinin belli olmadığını söyledi. Sürdürülebilirlik bölümünde proje bitince iki gelir modeli planlanmıştı: değişim programına gitmek isteyen öğrencileri anlaşmalı aracılık firmalarına yönlendirme ve reklam geliri.

## 11. Türkçe Yazım Denetimi ve Değerlendirme Aracı

On birinci sunum, yaygın bir İngilizce yazım asistanının Türkçe desteği olmamasından yola çıkan, Türkçe metinlerde yazım ve dil bilgisi hatalarını bulup kullanıcıya geri bildirim veren bir editör projesiydi. Günlük yazışmalarda ve resmî belgelerde Türkçe dil bilgisinin zorluğu nedeniyle sık hata yapıldığı, bir editörle bu hataların en aza indirilmesinin amaçlandığı anlatıldı.

Kabuller: belirtilen bütçenin aşılmaması ve ekibin proje sonuna kadar tam zamanlı çalışması. Kısıtlar: 12 aylık süre ve teslimde belirlenen performans ve başarım ölçütlerinin karşılanması. Yöntem olarak çoğunlukla Python ile yapay zeka dil modelleri geliştirilecek; Türkçe desteği olan BERT yapısı üzerine metin türü ve duygu sınıflandırma, varlık adı tanıma (NER) gibi modeller kurulacak, arka uç Java ile yazılacaktı. Bir mimari çizim ve kullanıcı arayüzü taslakları hazırlanmıştı. Use case diyagramı çizilmemiş, ancak gereksinimler use case adımları gibi maddelenmişti: doküman oluşturma ve düzenleme, doküman yükleme ve indirme, yazım denetim modellerini filtreleme, model analiz sonuçlarının kullanıcıya bildirilmesi. İşlevsel olmayan gereksinimler arasında arayüzün akıcı olması ve modellerin hızlı çalışması vardı.

Proje plan takvimi yedi iş paketi, her birinin projenin başarısındaki önem yüzdesi ve 12 aylık dağılımıyla verildi (ekrandan, 01:50:00):

| İP | İş paketi | Önem (%) | Aylar |
|---|---|---|---|
| 1 | Metin türü ve duygu sınıflandırma | 10 | 1-3 |
| 2 | NER, büyük harf ve eklerin yazımı | 10 | 1-3 |
| 3 | Dil modelleri karşılaştırılması ve bağlamsal yazım denetimi | 30 | 4-5 |
| 4 | Yapay zeka modellerinin servisleştirilmesi | 10 | 6-8 |
| 5 | Back-end | 20 | 7-9 |
| 6 | Front-end | 15 | 8-10 |
| 7 | Test ve iyileştirme | 5 | 11-12 |

Önem yüzdelerinin toplamı 100'dür (python ile doğrulandı). Süreç modeli şelaleydi; gerekçe, projenin doğrudan bir müşterisi olmaması, sık geri bildirimle hızlı değişiklik gerektirmemesi ve iş paketlerinin birbirinin çıktısıyla ilerlemesiydi. Hoca iş adımlarının şelaleye göre gösterilmediğini not etti.

Ekip bir proje yürütücüsü, bir front-end ve bir back-end geliştirici, iki yapay zeka geliştiricisi ve veri seti hazırlamada çalışacak bir yardımcı personelden oluşuyordu. Dört risk öngörülmüştü: model eğitimi için veri bulunamaması, modellerde istenen başarımın yakalanamaması, uygulamanın istenen akıcılıkta çalışmaması ve editörün istenen özellikleri sağlayamaması; her biri için olasılık, tedbir ve etki tablolaştırılmıştı. Bütçede personel, bilgisayarlar, grafik kartı ve yardımcı personel vardı.

> **Hocanın vurgusu:** Bütçede "donanım", "destek" gibi üst kalemler kullanılıp bilgisayar ve grafik kartı gibi öğeler donanımın alt kırılımları olarak gösterilmelidir.

## 12. Mobil İmza Platformu

### 12.1 Amaç ve kapsam

On ikinci sunum, operatör tarafında çalışan bir mobil imza platformunun planıydı. Salgınla birlikte işlemlerin dijital ortama taşınması hızlanmış, ıslak imza gerektiren bürokratik işlemler için elektronik ve mobil imza kullanımı önem kazanmıştı. Kapsam, 5070 sayılı Elektronik İmza Kanunu'na ve kanunun eksik kalan kısımlarını dolduran BTK mevzuatına uygun bir platform geliştirmekti.

### 12.2 Modüller ve gereksinimler

İşlevsel gereksinimler modüller halinde verildi:

- Kayıtçı modülü: bir müşterinin mobil imza abonesi olabilmesi için önce sertifikası olmalıdır. Bu modül sertifika sağlayıcılarla entegre olur, sertifikaları yönetir: süresi dolana yenisini oluşturur, ödeme yapılmadığında askıya alır, ödeme yapılınca askıdan çıkarır.
- Mesajlaşma modülü: müşteri, cep telefonunda PIN girerek imzalar; sertifika ve imzalama işlemi SIM kartın üzerindedir. Operatörle SIM kart arasındaki tek kanal SMS olduğu için modül SMS merkeziyle haberleşir; SIM kart kısa bir numaraya mesaj atar, modül bu numarayı dinler.
- Doğrulama modülü: gelen imzanın doğru olup olmadığını denetler.

İşlevsel olmayan gereksinimlerde güvenlik örneği verildi: özel anahtar (private key) SIM kartta tutulduğu için platform açık anahtarla (public key) doğrulama yapmalıdır. Yasal gereksinim olarak 5070 sayılı kanuna uyum gerekiyordu. Grafik arayüz yoktu, çünkü platform doğrudan kurumların hizmetlerine entegre olarak çalışır; işlem bir firmada başlar, web servisleriyle operatöre, oradan SIM karta gidip gelir. Hoca gereksinimlerin yazımı hakkında şunu söyledi:

> **Hocanın vurgusu:** Gereksinimler belirtilirken her biri kısa bir cümle olmalı ve madde madde yazılmalıdır. İşlevsel olmayan gereksinimlerde de örneğin "performans için şunlar gereklidir" diye tek tek maddeler yazılmalıdır.

### 12.3 Plan

Kabuller (ekrandan, 02:00:00): projenin hassasiyeti nedeniyle geliştirme ekibinin kıdemli yazılımcılardan oluşması; mobil imza sertifikası ile ilgili yükümlülüklerin nitelikli elektronik sertifika hizmet sağlayıcıları tarafından karşılanması; abonelerin mobil imza uygulamasına (applet) sahip SIM karta sahip olması; entegre olunan sertifika sağlayıcılarının doğrulama servislerinin 7/24 çalışması; müşterinin operatörün kapsama alanında bulunması; kurum ve firmaların entegratörler üzerinden ya da kendi yazılımlarını geliştirerek entegre olabilmesi.

Süreç modeli şelaleydi, çünkü projenin ayrıntıları kanunda ve mevzuatta belli, son kullanıcıyla etkileşen SIM uygulaması zaten mevcuttu. Önce analiz ve isterler netleştirilip tasarım dokümanı yaklaşık 20 günde bütün ekip tarafından oluşturulacak, ardından üç modül üç ayrı yazılımcı tarafından paralel geliştirilecekti. En küçük modül olan mesajlaşma modülü erken biteceği için o geliştirici iç testlerde kullanılacak bir test imzalama uygulaması da yazacaktı (15 gün). Ardından modül testleri yapılacaktı. Hoca kilometre taşlarının gösterilmediğini belirtti.

Bütçe beş kişilik ekip için beş bilgisayar, imzalama kritik bir işlem olduğundan hizmet kesintisine karşı coğrafi yedekli iki sunucu ve iki veri tabanı ile personel maaşlarından oluşuyordu. Use case diyagramı uygulamanın kullanımını gösteriyordu; platformun doğrudan kullanıcı etkileşimi olmadığı için kendine ait bir use case diyagramı yoktu.

Riskler ve önlemler: uyumlu SIM kartın bulunmaması (yeni müşteri kazanılamaz; uyumlu telefonu olanlar e-SIM'e yönlendirilebilir), sunucu maliyetlerinin artması (başta belirlendiği için maliyet artmadan erken temin), çalışan ayrılması (farklı bir alan olduğu için eğitimle farkındalık; kıdemli personel ve kısa proje süresi nedeniyle ihbar süresi içinde bitirme hedefi), mevzuat değişikliği (her yıl değerlendirme toplantısı). Projenin kapanışında doğruluğun kontrolü ve aktif abonelerin imzalayabilmesi öngörülüyordu.

## 13. Uzaktan Algılama ile Av Balığı Yoğunluğu Tahmini

On üçüncü sunum iki kişilik bir gruptu. Amaç, uzaktan algılama yöntemleriyle av balıklarının anlık bölgesel tahminini yapan bir yazılımdı: endüstriyel balıkçıların kısa mesafeli sonar sistemlerinden çok daha uzaktaki balık popülasyonlarını görebilmesi ve su ürünleri yetiştiriciliği (akuakültür) için uygun alanların tespiti. Uydu verileri ya da drone üzerindeki çok bantlı (multispektral) ve hiperspektral kameralarla plankton yoğunluğu, akıntı, sıcaklık ve diğer oşinografik veriler analiz edilecekti. Gerekçe besin zinciriydi: alg bulunan yerde onu izleyen bitkisel ve hayvansal tek hücreliler, onları izleyen çok hücreliler ve sonunda balık ya da kabuklular bulunur; bu süreç bir algoritmaya dökülerek balığın yeri bulunabilir.

İşlevsel gereksinimler (ekrandan, 02:10:00): veri toplama, veri işleme ve analiz, veri setlerinin eğitim ve test olarak ayrılması, gerçek zamanlı işleme (tahmin modelinin gerçek zamanlı veri akışıyla hızlı ve anlık sonuç üretmesi), kullanıcı arayüzü (teknede, masaüstünde ve mobilde tahmin ve koordinat görüntüleme), uyarı ve raporlama (bir bölgede yoğunluk önemli ölçüde değiştiğinde otomatik uyarı), veri saklama ve yedekleme (balıkçıların av rotası ile tahminin uyumuna ilişkin geri bildirimler dahil) ve entegrasyon yetenekleri. İşlevsel olmayan gereksinimler performans, güvenilirlik, veri güvenliği, ölçeklenebilirlik, kullanılabilirlik, uyumluluk, bakım ve destekti. Hoca gereksinimlerin madde madde söylenmesinin yeterli olduğunu, SWOT analizinin de geçilebileceğini, çünkü yapılacak işin ve gereksinimlerin buna göre belirlendiğini söyledi.

Hoca metodolojiyi sorduğunda önce model seçimi (ResNet, U-Net gibi modeller deneysel belirlenecek) anlatıldı; hoca yazılım geliştirme süreç modelini sorduğunu açıkladı. Seçim şelaleydi; gerekçe, iş paketlerinin birbirine bağlı olması ve geri dönmeden ilerlenmesiydi: önce MODIS ve Sentinel gibi uydulardan alınan verilerin işlenebileceği bir arayüz, sonra bentik, nektonik ve planktonik veri analizi. Ekipte bir mobil geliştirici, iki bilgisayar mühendisi, bir su ürünleri mühendisi ve bir harita (geomatik) mühendisi vardı. Proje 18 ay sürecekti ve beş ana iş paketi vardı (ekrandan, 02:15:00):

1. MODIS ve yer gerçeklik verilerinden derin öğrenme modelinin oluşturulması (12 ay).
2. Deniz taban yüzey modelinin oluşturulması.
3. Bentik, nektonik, planktonik veri analizi.
4. Modül entegrasyonu ve web, mobil uygulama geliştirme.
5. Av karar sisteminin devreye alınması, en az iki balıkçı ile beta testleri, sorunların giderilmesi ve sonuçların değerlendirilmesi.

Gantt çizelgesinde ilk dört iş paketi aynı tarihte başlayan paralel çubuklarla çizilmişti (ekrandan, 02:15:00). Hoca Gantt'ın nasıl işlediğini ve şelalenin nerede görüldüğünü sordu ve "şelalenin ardışıklığını burada takvimde göremiyoruz" dedi. Ardından kilometre taşını sordu (bkz. Örnek Sorular).

Riskler (ekrandan, 02:15:00): proje çıktılarının planlanan doğruluk değerlerinin altında kalması (tedbir: uydu verilerinin yer gerçekliği verilerinden kimyasal ve fiziksel analizle doğrulanması), bedelli ve bedelsiz uydu görüntüsü sağlayıcılarının hizmet aksaklıkları ve fiyat istikrarsızlıkları (tedbir: tedarikçi çeşitliliğini artırmak), görüntülerde düşük çözünürlük ve kayıplar (tedbir: görüntü iyileştirme, filtreleme, geometrik ve atmosferik düzeltme algoritmaları). Bütçede personel, hizmet alımı, makine-teçhizat ve seyahat giderleri vardı.

## 14. İş Güvenliği Raporu Paylaşım Platformu

On dördüncü sunum, bir müşteri şirketin birlikte çalıştığı firmalarla iş güvenliği raporlarını paylaşabileceği bir web platformuydu. Doğrudan e-postayla göndermek, raporlar farklı firmalara ve kategorilere ait olduğunda zorlaştığı için bu platform isteniyordu. Üç kullanıcı tipi vardı: yönetici (rapor oluşturur, düzenler, siler), şirket çalışanı (oluşturur ve düzenler, silemez) ve firma çalışanı (yalnız kendine atanmış raporları okur). Hoca projenin hedefini sordu; hedef, raporların kategorilere ve firmalara göre basitçe paylaşılmasıydı.

Proje kabulleri (ekrandan, 02:20:00): kullanıcılar rapor gönderebilen bir web uygulamasına erişebilecek; uygulama üç kullanıcı tipini destekleyecek; yönetici rapor oluşturma, silme ve izin yönetimi yetkisine sahip olacak; şirket çalışanları atandıkları firmalar için rapor oluşturup güncelleyebilecek; firma çalışanları yalnız kendi firmalarına atanmış raporları okuyabilecek; girişte bağlı firmaların listesi ve her firmaya özel kategorilendirilmiş raporlar görüntülenecek. Kısıtlar: belirlenen bütçe ve zaman içinde tamamlanma ve kimlik numarası gibi kişisel veriler nedeniyle güvenlik ve veri gizliliği önlemlerinin alınması.

Ekip proje yöneticisi, front-end, back-end ve veri tabanı geliştiricisinden oluşuyordu; test ekibini müşteri kendisi kuracaktı. Arka uç için başlangıçta Amazon Web Services, ön yüz için React.js düşünülmüştü (entegrasyon kolaylığı nedeniyle). Basit bir use case diyagramı kullanıcı tiplerine göre yetkileri gösteriyordu. İş kırılımı proje yönetimi, tasarım (önce prototip, müşteri onayından sonra mimari tasarım), yazılım geliştirme ve test-bakım olarak dört başlıktı. 16 haftalık planda proje şelale gibi başlayıp, müşteri geliştirmeye katılmak istediği için çevike dönüşüyordu; test ve bakım, test ekibi müşteri olduğu için geliştirmeyle paralel bir döngüye dönüştürülmüştü. Dört risk de teknikti ve tabloda etki seviyesi en yüksek olandan başlanarak sıralanmıştı: güvenlik açığı ve verilerin bozulması ya da sızması en yüksek etkili, performans kaybı ve arayüz kullanılabilirliği müşterinin basit bir uygulama istemesi nedeniyle orta etkili sayılmıştı.

## 15. Metinlerin Çizge Veri Tabanında Tutulması

On beşinci sunum, tek kişinin geliştirdiği bir yazılım projesiydi. Fikir, her kelimeyi bir düğüm (node), kelimeler arasındaki ilişkileri kenar (edge) olarak düşünüp bütün metinleri merkezi bir çizge veri yapısında depolamaktı. Taranan kaynaklardaki bütün metinler tek yerde tutulursa her konu için tek elden analiz yapılabilecekti. Teknolojiler Play Framework, Scala, bir JSON kütüphanesi ve en önemli bileşen olarak Neo4j çizge veri tabanıydı. Modelin farklı uygulamalarda kullanılabildiğini göstermek için iki uygulama geliştirilmişti: bir akademik dergi platformundan alınan makaleler üzerinde karşılaştırma ve arama motoru işlemleri, ve spor haberleri sitelerinden alınan verilerin aynı düğümlere aktarılıp analiz edilmesi. Gereksinimler use case yerine akış diyagramlarıyla gösterilmişti (ekrandan, 02:30:00); örneğin cümledeki her kelime için "daha önce eklenmiş mi" kontrolüyle kelimeyi ekleme ya da özniteliklerini güncelleme döngüsü ve bir makalenin özetini veri tabanındaki makalelerle cümle cümle karşılaştırma akışı.

Kabul ve kısıt tartışması derste önemli bir noktaya bağlandı. Çok fazla veri tarandığında depolama alanı yetmeyebilir. Eğitim setinde akademik makale ve spor haberleri kullanıldığı için argo içerik olmadığı varsayılmış, argoya özel bir filtreleme geliştirilmemişti; sunum bunu önce kısıt, sonra kabul olarak düşünmüştü.

> **Hocanın vurgusu:** "Argo içerik yoktur" demek bir varsayımdır; olumlu bir durumun var olduğunu ya da olmadığını kabul ediyorsunuz. Bu yüzden kısıt değil kabul (varsayım) olarak yazılır. Filtreleme ise ayrı bir iştir.

Ekip yapısı konmamıştı, çünkü çalışma tek kişilikti. Hoca tek kişi yapsa da bir yazılım geliştirildiğini, işin nasıl bölündüğünün, hangi aşamalarda değerlendirme yapıldığının ve kilometre taşlarının belirtilmesi gerektiğini söyledi. Gantt çizelgesi Microsoft'un çevrimiçi bir aracıyla hazırlanmıştı; kilometre taşları çizge modelinin tamamlanması ve eğitilmiş veri setinin hazırlanmasıydı. Plan teknoloji taramasıyla başlayıp sürüyordu. Metodoloji temelde Scrum'dı, ancak süreç boyunca uygulamadan bağımsız demo uygulamalar yazılması (örneğin yeni sürümlere uyumluluk gibi riskleri sürekli analiz etmek için) nedeniyle spiral modeli de andırıyordu. Son adımlar uygulamaların geliştirilmesi, performans ölçümü ve kaynak kodun dağıtımıydı.

Riskler olarak tek kişinin hastalanması ve açık kaynak yazılımların sonradan ücretli ya da lisanslı hale gelmesi sayıldı; sunucu ikincisinin, ücretli hale gelmeden önceki son sürüm kullanılabildiği için düşük bir risk olduğunu belirtti. Hoca böyle bir çalışmada da çalışma ortamının uymaması, donanım hataları, danışman görüşmeleri gibi birçok risk çıkabileceğini söyledi.

## 16. Online Sağlıklı Beslenme Rehberi

On altıncı sunum, yoğun çalışan insanların beslenme düzenini ayarlamasına yardım eden bir uygulamaydı. Diyetisyenlerden alınan bilgiler sisteme girilecek, kullanıcının haftalık planına göre beslenme planı oluşturulacak, kullanıcı isterse sistemdeki diyetisyenlerden görüşme talep edebilecekti. Roller genel kullanıcı, sistem yöneticisi ve diyetisyendi. Proje sıfırdan başlayacak, başka bir projenin devamı değildi. Üst seviye görünüm, her rolün yapabileceği işlemler ve sıraları genel akış diyagramlarıyla gösterilmişti.

İşlevsel gereksinimler modüller, her modülde alınacak girdiler ve yapılacak işlemler olarak verildi. Genel kullanıcı kayıt modülünde ad, soyad, e-posta, doğum tarihi ve adres zorunlu; boy, kilo ve beden ölçüleri isteğe bağlıydı (doldurulursa daha iyi plan önerilebileceği belirtiliyordu). Egzersiz planı için meslek bilgisi de alınıyordu: masa başında çalışan birine daha ağır, ayakta çalışan birine daha hafif günlük egzersiz verilebilir. Diyetisyen kayıt modülünde diploma bilgisi önemliydi; diplomayı yönetici kontrol edip onaylıyordu. Temel modüllerin arayüzleri hazırlanmıştı.

Kabul ve kısıtlar ayrı yazılmıştı; hoca bunu onayladı. Kabuller: sistemin başlangıçtan en fazla 3 ay sonra kullanıcıya açılması ve mevcut ekiple tamamlanması. Kısıt: sistemin aynı anda 10 bin kullanıcıya hizmet verebilmesi (gerekirse kapasite artırılabilir). Süreç modeli şelaleydi; gözden geçirme kuralları ve şelaleye uygun bir aktivite listesi vardı. Gantt MS Project'te hazırlanmıştı. Kaynaklar maliyet, gereken miktar ve kullanım amacıyla listelenmiş, alt yükleniciler belirtilmişti. Ayrıca bir use case diyagramı (örneğin üye olma işlemi için), test planı, risk tabloları ve projenin kapatılması bölümü vardı.

## 17. Benzin İstasyonlarında Dağıtık Yazılım Güncelleme

Son sunum, benzin istasyonlarındaki pompalarda çalışan farklı yazılımların belirli aralıklarla güncellenmesi için bir dağıtık güncelleme sistemiydi. Literatürde bu ihtiyaca yönelik açık kaynaklı bir proje bulunamadığı belirtildi. İşlevsel gereksinimler sunucu (uygulama ve yapılandırma dosyalarını barındırır, istemcilerin isteklerine yanıt verir) ve istemci (uygulamaların çalıştığı, hizmete devam ederken güncellemeleri takip eden cihaz) olarak ayrılmıştı. İşlevsel olmayan gereksinimlerde sunucu ile istemci arasındaki her bağlantının minimum yanıt süresine sahip olması ve çakışmayı önleyecek hızda yanıt vermesi istenmişti (ekrandan, 02:45:00).

Süreç modeli şelaleydi; gerekçe projenin çok büyük olmaması ve kullanıcıyla doğrudan ilişkisinin bulunmamasıydı. Ekip proje yöneticisi, bir programcı-analist ve test ekibinden oluşuyordu. Kabuller: proje 12 ay sürecek ve sonra istasyonlarda kullanılacak, mevcut ekiple tamamlanacak, istasyonlar sistemi aktif kullanacak; sistem aynı anda bin cihaza hizmet verebilecek, tek seferde birden çok uygulama indirilip güncellenebilecek, her güncelleme ayrı işlendiği için sorun yalnız ilgili uygulamada ele alınabilecek. Kısıtlar: internet bağlantısı koparsa dosya indirme ve güncelleme sorunları; açık kaynak olacağı için Linux işletim sisteminde kullanım; istasyonların az kullanıldığı gece saatlerinde güncelleme.

Aktivite listesinde gereksinimlerin belirlenmesine ve analize birer ay, gerçekleştirmeye dört ay, teste (canlı ortamda sorun çıkabileceği için) dört ay, bakıma bir ay ayrılmıştı; Gantt çizelgesi şelaleye uygun biçimde biri bitince diğeri başlayacak şekilde çizilmişti. Test planında kodlama süresince birim test, sonra bütünlük ve sistem testleri vardı. Bütçe bir sunucu kiralama, 12 ay boyunca ekip maaşları ve bilgisayarlardan oluşuyor, toplam yaklaşık 800 bin TL ediyordu. Riskler: çalışan ayrılması (düşük olasılık, yüksek etki; önlem: başta yeterli eleman), bütçe yetersizliği (olası yatırımcılarla görüşme), alt yüklenici sorunları (yedekleme ve alternatif barındırma hizmetleri), teknik sorunlar (düzenli testlerle hataların canlıya çıkmadan düzeltilmesi). Projenin kapatılmasında başlangıçtaki tahminler sonuçlarla karşılaştırılır; maliyet, risk analizi ve zaman planı değerlendirilir, ekibin yeterliliği değerlendirilir ve proje kapatılır.

<!-- BELİRSİZ: Aktivite listesinde tasarım aşamasına ayrılan süre altyazıda net değil; 12 aylık toplam düşünülürse büyük olasılıkla bir aydır. -->

## 18. Hocanın Proje Planı İçin Genel İlkeleri

Sunumlar boyunca hocanın tekrar ettiği yorumlar, bir proje planında nelere dikkat edilmesi gerektiğini özetler:

- Kabuller ve kısıtlar ayrı başlıklarda yazılmalıdır. Olumlu bir durumun var olduğunu ya da olmadığını kabul etmek varsayımdır.
- Proje tanımı kısa tutulmalı, asıl ağırlık plana verilmelidir: süreç modeli, iş kırılımı, Gantt, bütçe, risk.
- Süreç modeli gerekçesiyle seçilmeli ve plana yansımalıdır. Şelale seçildiyse Gantt'ta aşamaların ardışıklığı görünmelidir.
- Gantt'ta tarihler, bağımlılıklar ve kilometre taşları bulunmalıdır. Hoca her sunumda Gantt'ın hangi araçla hazırlandığını sordu (Excel, MS Project, Microsoft'un çevrimiçi aracı, açık kaynaklı web araçları).
- İş kırılım yapısı grafik ağaç ya da numaralı liste olarak gösterilebilir.
- Risk tablosunda olasılık ve etki ayrı sütunlar olarak bulunmalı, seviye bunlardan çıkarılmalı; riskler liste değil tablo halinde verilmelidir.
- Gereksinimler kısa cümlelerle madde madde yazılmalı; işlevsel gereksinimler use case diyagramı ve belgesiyle desteklenmelidir.
- Bütçe kalemleri alt kırılımlarıyla gösterilmelidir.
- Daha önce yapılmış ya da şirkette yürütülen bir proje sunuluyorsa, plan sıfırdan başlıyormuş gibi derste verilen formata göre hazırlanmalıdır.
- Tek kişilik bir projede de yöntem, aşamalar, değerlendirme noktaları ve kilometre taşları belirtilmelidir.

## Örnek Sorular

**Soru 1** (derste sözlü, 01:03:00): Balık kılçığı diyagramının özelliği nedir?

> **Çözüm (derste verildi):** Ana problem balığın baş tarafına yazılır. Bu ana problem alt dallara (nedenlere) ayrılır; her alt dala ayrı ayrı odaklanıp her alt probleme bir çözüm getirerek ana problem çözülmüş olur. Derste verilen örnekte ana problem bir duyuru sisteminin sorunlarıydı; alt dallar yavaşlık, süreksizlik, yönetsel sorunlar ve eski teknolojiydi. Yavaşlık dalına çözüm olarak hızlı iletişim ve hızlı duyuru önerildi.

**Soru 2** (derste sözlü, 02:14:24): Kilometre taşı (milestone) nedir? Bu planda kilometre taşı var mı?

> **Çözüm (derste verildi):** Bir öğrencinin cevabı: kilometre taşları proje akışındaki belirli yapı taşları, yani dönüm noktalarıdır. Hoca bu cevabı kabul edip risklere geçti. Derste görülen örneklerde kilometre taşları her aşamanın sonundaki 0 günlük "bitiş" görevleri (ekrandan, 00:15:00) ve Gantt'ta elmasla işaretlenen noktalardı (ekrandan, 00:25:00).

**Soru 3** (derste sözlü, 02:13:35): Gantt diyagramınız nasıl işliyor? Şelaleyi burada nasıl görebiliyoruz?

> **Çözüm (derste verildi):** Şelalede bir aşama bitmeden sonraki başlamaz; bu yüzden Gantt'ta çubuklar basamak biçiminde ardışık yerleşmelidir. Sunulan çizelgede iş paketleri aynı tarihte başlayan paralel çubuklar olduğu için hoca "şelalenin ardışıklığını burada takvimde göremiyoruz" dedi (ekrandan, 02:15:00). Ardışık bir şelale çizelgesi örneği derste ikinci sunumda görüldü (ekrandan, 00:25:00).

**Soru 4** (derste sözlü, 00:35:09): Risk seviyesini olasılığı ve etkiyi belirlemeden mi yazdın?

> **Çözüm (derste verildi):** Risk seviyesi olasılık ve etki belirlenerek çıkarılmalıdır; yalnız "düşük, orta, yüksek" diye seviye yazmak yeterli değildir. Derste örnek alınabilecek bir tabloda her risk için olasılık, etki, tür, açıklama ve önlem ayrı ayrı verilmişti (ekrandan, 01:25:00).

**Soru 5** (derste sözlü, 02:11:20): Yazılım geliştirme süreç modeli olarak ne seçtiniz ve neden?

> **Çözüm (derste verildi):** Derste verilen gerekçeler: şelale için iş paketlerinin birbirine bağlı olması ve geri dönmeden ilerlenmesi; ihtiyaçların ve teknolojinin belli olması (Stacey matrisinde basit bölge); ayrıntıların kanun ve mevzuatta önceden belirlenmiş olması; doğrudan müşteri etkileşiminin bulunmaması. Çevik için müşterinin geliştirmeye katılmak istemesi, geri bildirime göre hızlı değişiklik gerekmesi, erken test ve düzenli toplantılarla iletişim.

**Soru 6** (derste sözlü, 00:17:45; sınavda sorulduğu belirtildi): Seçtiğiniz projenin risk planını yazın.

> **Çözüm (derste verilmedi, derste görülen örneklerden kuruldu):** Bir risk planı en az şu sütunları içeren bir tablodur: risk numarası, risk tanımı, türü (teknik, personel, bütçe, pazar vb.), olasılık, etki, seviye ve alınacak tedbir (B planı, gerekirse C planı). Örneğin bir web uygulaması için: "Personelin projeden ayrılması: olasılık düşük, etki yüksek; tedbir: başta yeterli eleman ve düzenli dokümantasyon" ve "Kullanılan kütüphanelerin güncellemelerle çalışmaz hale gelmesi: olasılık yüksek, etki büyük; tedbir: düzenli denetim ve bakım."

## Dersin Toparlaması

Bu derste dönem boyunca işlenen proje planlama kavramları, öğrencilerin farklı alanlardaki projeleri üzerinde uygulandı: e-ticaret, bot, gömülü sistemler, bankacılık, kamu bilgi sistemleri, İHA, görüntü işleme, doğal dil işleme, mobil imza, uzaktan algılama ve dağıtık güncelleme. Projeler farklı olsa da hocanın yorumları hep aynı noktalarda toplandı: kabul ve kısıtların ayrılması, süreç modelinin gerekçelendirilmesi ve Gantt'ta görünür olması, kilometre taşlarının belirtilmesi, risklerin olasılık ve etkiyle tablolaştırılması, gereksinimlerin kısa maddeler ve use case ile verilmesi, bütçenin alt kırılımlarla gösterilmesi.

Bu ders dönemin son uygulama sunumu oturumuydu. Bir proje planı hazırlarken yukarıdaki ilkeler bir kontrol listesi olarak kullanılabilir; özellikle var olan bir projeyi plana dönüştürürken belgenin yeni başlayan bir proje gibi kurulması gerektiği unutulmamalıdır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
