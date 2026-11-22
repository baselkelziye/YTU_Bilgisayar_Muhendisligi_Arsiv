# Ders 4 Çalışma Özeti

## Genel Konular

- Proje ekibi ve proje yöneticisinin rolü (tekrar)
  - Proje ekibi "cerrahi ekip" gibi çalışır: her üye bütün için kritik olan özel bir görevi yerine getirir. Ekip, projenin aşamalarına göre değişir (ekrandan, 00:05:00).
    - Planlama: proje yöneticisi ve birkaç analist.
    - Analiz: sistem analistleri ve iş analistleri eklenir.
    - Tasarım: veri tabanı ve ağ tasarımı gibi teknik uzmanlar gelebilir.
    - Gerçekleştirme: programcılar ve kalite kontrol çalışanları eklenir.
  - Proje yönetimi, önceden hesaplanmış iş listesi ve bütçe çerçevesinde planlanan sonucu elde etmek için ekipteki insanları organize etme ve yönlendirme işidir. İyi yönetici planı yapmayı, işletmeyi ve sorunlarda planı ayarlamayı bilir.
  - Müşteri projeye destek ve para sağlayan kişi ya da gruptur; kullanıcı sistemi doğrudan kullanacak gruptur. Küçük projelerde sistem analisti proje yöneticiliğini de üstlenebilir.
  - Proje yöneticisi planlar, organize eder, yönlendirir, kontrol eder; kilometre taşlarını önceden tanımlar, kaynakları düzenler, rolleri belirler.
- Proje planlama aşaması: problemin tanımlanması
  - Projenin başlangıcında problem tanımlanır, fizibilite oluşturulur, ekip belirlenir, projenin başlatılmasına karar verilir.
  - Problemin tanımı üç parçadan oluşur: iş ihtiyacı ve beklenen iş faydaları, yeni sistemden beklenen yetenekler (kapsam) ve gerekirse kapsamı gösteren bir bağlam (context) diyagramı.
  - Örnek: RMO (Rocky Mountain Outfitters) dış giyim şirketinin müşteri destek sistemi. Ekranda gösterilen beklenen iş faydaları (ekrandan, 00:10:00):
    - Elle sipariş işlemeden kaynaklanan hataları azaltmak.
    - Daha hızlı sipariş işleyerek sipariş karşılamayı hızlandırmak.
    - Posta ve telefon siparişlerindeki personel düzeyini korumak ya da azaltmak.
    - İnternet üzerinden yeni bir satış kanalı açmak.
    - Popüler ve yavaş satan ürünleri izleyerek devir hızını artırmak.
    - Kapsamlı müşteri desteği ve bilgiyle müşteri sadakatini artırmak.
  - Beklenen yetenekler (anlatımdan): internet ve diğer siparişlere açık olma, pazar analizi için geçmiş satış verisini saklama ve kolay erişim, büyük veri miktarıyla çalışma, kesintisiz sipariş alma, birden fazla depodan gönderimi koordine etme.
  - Bağlam diyagramı, veri akış diyagramının en genel halidir: işlem ayrıntısı yoktur, yalnız sistem ve dış varlıklar arasındaki veri akışları gösterilir (ekrandan, 00:15:00). RMO'da dış varlıklar: Customer, Marketing, Credit bureau, Merchandising (sales), Management, Shipping, Bank.
- Fizibilite (yapılabilirlik, olurluluk) türleri
  - Ekonomik fizibilite: maliyet-fayda analizi.
  - Kurumsal ve kültürel fizibilite: sistemin kurumun alışkın olduğu iş düzenine uyması.
  - Teknolojik fizibilite: önerilen teknolojik gereksinimler ve gereken uzmanlık.
  - Zaman (schedule) fizibilitesi: iş listesinin zamanında bitip bitemeyeceği.
  - Kaynak fizibilitesi: ekip üyelerinin ve kaynakların sağlanabilirliği.
- Maliyetler ve faydalar
  - Geliştirme maliyetleri: ücretler, ekipman ve kurulum, yazılım ve lisanslar, danışmanlık ve üçüncü taraf ödemeleri, eğitim, tesisler, araçlar, destek personeli, seyahat ve diğer giderler (ekrandan, 00:20:00).
  - İşletim maliyetleri: bağlantı, ekipman bakımı, bilgisayar işletimi, programlama desteği, ekipman amortismanı, eğitim ve süren yardım masası, sarf malzemeleri (ekrandan, 00:20:00).
  - Sayılabilir (tangible) faydalar paraya dökülebilir: personel sayısı ya da ücretlerin azalması, işletim harcamalarının azalması, hata oranlarının düşmesi.
  - Sayılamayan (intangible) faydalar paraya dökülemez: müşteri memnuniyeti, kullanıcıların sisteme güveni gibi.
- Fizibilite çalışmasının yürütülmesi (ekrandan, 00:30:00)
  - Her maliyet kategorisi tahmin edilir; ücretler personel ihtiyacına (kim, ne kadar süre, hangi oranda) göre hesaplanır.
  - Geliştirme ve yıllık işletim maliyetlerinin, sonra faydaların özeti çıkarılır.
  - Net bugünkü değer (NPV) örneğin 5 yıllık dönem için hesaplanır; sonra projeye devam edilip edilmeyeceğine karar verilir.
  - Geri ödeme süresi (payback): sistemin kendini karşıladığı, kazanç ve giderin başa baş geldiği noktaya ulaşma süresi.
- İş kırılım yapısı (WBS) ve iş listesi
  - RMO planlama aşamasının iş kırılım yapısı ekranda gösterildi: her görevin gün olarak süresi ve kaynak sayısı (ekrandan, 00:35:00).
- Gantt şeması (uygulama örneği: kitap satış web sitesi)
  - Her iş adımı bir faaliyettir; başlangıç-bitiş zamanları ve kaynaklar belirlenir.
  - WBS ile faaliyetler hiyerarşik numaralandırılır (1, 1.1, 1.2, 1.3 ...). WBS numarası ile satır numarası farklıdır; öncül sütununda satır numarası kullanılır.
  - Başlangıç tarihi ve süre verilince bitiş tarihi otomatik hesaplanır.
  - Kilometre taşı (milestone) süresi 0 gün olan faaliyettir, eşkenar dörtgenle gösterilir.
- Faaliyetler arası ilişkiler
  - Bitiş-Başlangıç (FS): varsayılan ilişki; örneğin tasarım için analizin bitmesi gerekir.
  - Başlangıç-Başlangıç (SS): örneğin birim testlerin başlaması için geliştirmenin başlamış olması gerekir.
  - Bitiş-Bitiş (FF): örneğin birim testlerin bitmesi için kodlamanın bitmiş olması gerekir.
  - Başlangıç-Bitiş (SF): az kullanılır; hoca yazılımdan örnek vermenin zor olduğunu söyledi.
- Kritik yol ve bolluk
  - Kritik yol üzerindeki bütün faaliyetler zamanında gerçekleşmelidir; biri X gün gecikirse proje de en az X gün gecikir. Kritik faaliyetler Gantt'ta kırmızıdır (ekrandan, 01:00:00).
  - Bolluk (slack), kritik yolda olmayan faaliyetin projeyi geciktirmeden kayabileceği süredir. Kritik olmayan faaliyet mavi, bolluk gri uzun çizgiyle gösterilir (ekrandan, 01:35:00).
- Kaynak atamaları
  - Kaynak, proje faaliyetlerinin ilerlemesi için gereken her şeydir: insan, ekipman, para (ekrandan, 01:40:00). En önemli kaynak personeldir.
  - MS Project'te kaynak tipi Work (kişi) ya da Material olabilir; saat ücreti ve çalışma oranı girilir, maliyet buradan hesaplanır (ekrandan, 01:10:00).
- MS Project ve PERT diyagramı
  - MS Project bir yazılım geliştirme aracı değil, her türlü proje için kullanılan bir proje yönetimi programıdır. Benzer açık kaynak araçlar da kullanılabilir.
  - PERT, graf temelli bir yöntemdir: faaliyetler düğümler, bağlantılar kenarlarla gösterilir (ekrandan, 01:20:00). Kırmızı kutular kritik görevlerdir.
  - Gantt paralelliği iyi gösterir, faaliyetler arasındaki dolaylı bağımlılığı göstermekte yetersizdir.
  - PERT süre belirsizliğini iyimser, kötümser ve en olası süreyle hesaba katar; CPM'de süreler kesindir, bu yüzden daha basittir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Ekonomik fizibilite yalnız maliyet değildir
  - Birçok öğrenci ekonomik fizibilite denince yalnız maliyeti çıkarıyor. Ekonomik fizibilite maliyet ile faydanın kıyaslanmasıdır.
- Problemin tanımı sırayla yapılmalı
  - Önce çözülecek problem, sonra işletme açısından faydalar maddeler halinde, sonra sistemin sahip olması gereken yetenekler ve sistemin hangi varlıklarla hangi veriyi alışverişi yaptığı yazılır.
- İşleri doğru kademelendirmek
  - Gantt şemasını doğru kurmak için analiz, tasarım, geliştirme ve test altında hangi işlerin olduğunu bilmek gerekir; bu, dersin özümsenip özümsenmediğini gösterir. Her işin süresi ve hangi işe bağlı olduğu doğru tasarlanmalıdır.
- MS Project bir yazılım geliştirme aracı değildir
  - Hoca bunu birkaç kez tekrarladı: her türlü projenin yönetimi için kullanılan bir programdır.
- Kaynakların hepsini %100 yazmak gerçekçi değildir
  - Bazı kişiler başka projelerde de çalışır; %80, %60 gibi oranlar verilebilir.

## Kısa Tekrar Notları

- Problem tanımı: iş ihtiyacı ve faydalar, beklenen yetenekler, bağlam diyagramı.
- Bağlam diyagramı: tek süreç (0 numaralı sistem) ve dış varlıklarla veri akışları.
- Fizibilite türleri: ekonomik, kurumsal-kültürel, teknolojik, zaman, kaynak.
- Maliyet: geliştirme ve işletim. Fayda: sayılabilir ve sayılamayan.
- NPV: gelecekteki fayda ve maliyetin bugünkü para değeri. Payback: başa baş noktasına ulaşma süresi.
- WBS: hiyerarşik iş kırılımı ve numaralandırma.
- Milestone: 0 günlük faaliyet, eşkenar dörtgen.
- İlişkiler: FS (varsayılan), SS, FF, SF.
- Kritik yol: bolluğu olmayan, gecikmesi projeyi geciktiren faaliyetler; kırmızı.
- Bolluk: kritik olmayan faaliyetin kayabileceği süre; mavi faaliyet, gri çizgi.
- Kaynak: kişi, ekipman, malzeme, para; ücret ve oranla maliyet hesaplanır.
- PERT: graf temelli, olasılıklı süre; CPM: kesin süre.

## Detaylı Açıklamalar

- Bu ders, bir önceki derste anlatılan proje planlama ve fizibilite konularının üzerinden geçerek Gantt ve PERT diyagramlarının bir örnek üzerinde uygulanmasına ayrıldı. İlk bölümde İngilizce ders slaytları (RMO örneği), ikinci bölümde Türkçe uygulama slaytları (kitap satış web sitesi) kullanıldı.
- RMO bağlam diyagramında müşteri destek sistemi ortada tek bir süreç olarak (0 numaralı) durur (ekrandan, 00:15:00). Müşteriden sisteme New order, Item return info, Customer change notice akar; sistemden müşteriye Back order notice ve Shipment BOL gider. Merchandising (sales) sisteme Catalog updates gönderir, sistemden Sales reports ve Performance reports alır. Management'a Fulfillment reports, Sales reports ve Activity reports gider. Shipping'e Order details gider; Shipping'den Order fulfillment ve Back order notice gelir. Bank'a Deposit information gider. Credit bureau ile Credit verification alışverişi vardır. Marketing ile Prospective Cust Info ve Promotion package info akışları vardır. <!-- BELİRSİZ: Marketing akışlarının ok yönleri karede net okunmuyor. -->
- Ücret maliyetleri kişinin projede ne kadar süre ve hangi oranda çalıştığına göre hesaplanır: bir çalışan zamanının tamamını değil, örneğin 0,5 ya da 0,3 adam-ay kadarını projeye ayırabilir. Derste RMO örneğinde 3 sistem analistinin 9 ay (yıllık 75 bin), 6 programcının 7 ay (yıllık 50 bin) çalıştığı söylendi. Bu değerlerle analist ücreti $3 \times 75000 \times 9/12 = 168750$, programcı ücreti $6 \times 50000 \times 7/12 = 175000$ olur (ara adım eklendi). <!-- BELİRSİZ: Maliyet tablosunun slaytı karelerde yok; değerler altyazıdan alındı. -->
- Net bugünkü değer, sistemin örneğin iki yıl sonra sağlayacağı faydanın bugünkü para birimine çevrilmesidir; böylece projenin üzerinde çalışmaya değip değmediği değerlendirilir.
- Kitap satış web sitesi Gantt şeması (ekrandan, 00:50:00):

| Satır | WBS | Görev | Süre | Başlangıç | Bitiş | Öncül | Kaynak |
|---|---|---|---|---|---|---|---|
| 0 | 0 | KİTAP SATIŞ WEB SİTESİ | 27 gün | 24.03.21 | 29.04.21 | | |
| 1 | 1 | Analiz | 6 gün | 24.03.21 | 31.03.21 | | |
| 2 | 1.1 | Fizibilite Çalışması | 4 gün | 24.03.21 | 29.03.21 | | Analist-1 |
| 3 | 1.2 | Gereksinimlerin Belirlenmesi | 5 gün | 25.03.21 | 31.03.21 | 2SS+1 day | Analist-2 |
| 4 | 1.3 | Analiz Bitimi Toplantı | 0 gün | 31.03.21 | 31.03.21 | 3 | |
| 5 | 2 | Tasarım | 7 gün | 1.04.21 | 9.04.21 | | |
| 6 | 2.1 | Ön Tasarım | 3 gün | 1.04.21 | 5.04.21 | 4 | Yazılımcı-1 |
| 7 | 2.2 | Ayrıntılı Tasarım | 4 gün | 6.04.21 | 9.04.21 | 6 | Yazılımcı-2 |
| 8 | 2.3 | Tasarım Bitimi Toplantı | 0 gün | 9.04.21 | 9.04.21 | 7 | |
| 9 | 3 | Geliştirme&Test | 14 gün | 12.04.21 | 29.04.21 | | |
| 10 | 3.1 | Ön Yüz Geliştirme | 8 gün | 12.04.21 | 21.04.21 | 8 | Yazılımcı-1 |
| 11 | 3.2 | Arka Plan Geliştirme | 10 gün | 12.04.21 | 23.04.21 | 8 | Yazılımcı-2 |
| 12 | 3.3 | Birim Test | 10 gün | 12.04.21 | 23.04.21 | 11FF;10SS | Test Uzmanı |
| 13 | 3.4 | Sistem Testi | 2 gün | 26.04.21 | 27.04.21 | 12 | Test Uzmanı |
| 14 | 3.5 | Kullanıcı Testleri | 4 gün | 26.04.21 | 29.04.21 | 12 | Test Uzmanı |
| 15 | 4 | Proje Teslim Toplantısı | 0 gün | 29.04.21 | 29.04.21 | 14 | |

- Tablodaki süreler iş günüdür (hafta sonları sayılmaz); tarihler python ile iş günü sayılarak kontrol edildi ve tutarlıdır. "2SS+1 day", gereksinimlerin belirlenmesinin 2. satırın başlangıcından bir gün sonra başlayacağı anlamına gelir. Öncül sütununda yalnız sayı yazıyorsa ilişki varsayılan FS'dir. Birim testin "11FF;10SS" öncülü, arka plan geliştirmeyle bitiş-bitiş, ön yüz geliştirmeyle başlangıç-başlangıç ilişkisidir.
- Kritik yol görünümünde 2 günlük Sistem Testi mavi (kritik olmayan) görünür (ekrandan, 01:00:00). Aynı öncüle bağlı Kullanıcı Testleri 4 gün sürdüğü için Sistem Testi'nin bolluğu $4 - 2 = 2$ gündür (ara adım eklendi).
- Kaynak tablosu (ekrandan, 01:10:00): Analist-1 ve Analist-2 (Work, A, %100, 30 ₺/saat), Yazılımcı-1 ve Yazılımcı-2 (Work, Y, %100, 50 ₺/saat), Test Uzmanı-1, 2, 3 (Work, T, %100, 30 ₺/saat), Hosting Service (Material, H, 1.000 ₺). Kısaltmalar (A, Y, T, H) Gantt'ta isim yerine kullanılabilir. MS Project'te ayrıca cumartesinin iş günü olup olmadığı, günlük çalışma saati ve resmi tatiller gibi genel takvim tanımları yapılır.
- PERT diyagramında her düğümde görev adı, başlangıç ve bitiş tarihi, ID, süre ve kaynak görülür; kilometre taşları altıgen biçimli kutularla gösterilmiştir (ekrandan, 01:25:00). PERT'te bir görevin süresi iyimser, kötümser ve en olası sürelerden hesaplanır. Derste fizibilite çalışması için en iyimser 3 gün, en kötümser 7 gün verildi; en olası süre 4 ile çarpılarak ağırlıklı ortalama alınır ve 4 gün bulunur.

> **Ders sonrası not:** Hoca PERT'in açılımını "Project Evaluation and Review" diye söyledi; doğrusu slayttaki gibi Program Evaluation and Review Technique'tir. Ağırlıklı ortalama formülü $t_e = \frac{a + 4m + b}{6}$ biçimindedir ($a$ iyimser, $m$ en olası, $b$ kötümser); 6'ya bölme derste açıkça söylenmedi. $a=3$, $b=7$ ile $t_e = 4$ olması için $m = 3{,}5$ gün olmalıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
