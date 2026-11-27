# Ders 12 Genişletilmiş Notu: Proje Sunumları ve Analiz-Tasarım Diyagramlarının Değerlendirilmesi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin yapısı ve sunumlardan beklenenler
- 2. Market fiyat karşılaştırma sistemi: fizibilite, gereksinim toplama, kavramsal sınıf diyagramı
- 3. Hayvanat bahçesi bilgi sistemi: veri akışlarının adlandırılması ve ER diyagramı
- 4. Otel bilgi sistemi: anket, veri akış diyagramı düzeyleri, yapı diyagramı
- 5. Yemek sipariş sistemi: Gantt, veri akış ve UML diyagramları, iki yaklaşımın birlikte kullanılması
- 6. Dijital oyun abonelik sistemi: eksik analiz modeli
- 7. Konfeksiyon deposu yönetim sistemi: Gantt, Chen gösterimli ER diyagramı, kritik stok
- 8. Online tren bileti sistemi: fizibilite, veri akış diyagramları, veri sözlüğü, ER
- 9. Kütüphane otomasyon sistemi: fizibilite, kullanım senaryosu, UML sınıf ve ardışıl diyagram
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin yapısı ve sunumlardan beklenenler

Bu derste yeni bir konu anlatılmadı; grupların dönem boyunca hazırladığı bilgi sistemi projeleri sunuldu. Sunumlar dönem boyunca işlenen sistem geliştirme sürecini izliyordu: ekip yapısı ve roller (proje yöneticisi, analist, tasarımcı, programcı, müşteri), müşteri toplantıları, fizibilite çalışması, Gantt diyagramıyla zaman planı, sistem analizi (veri akış diyagramları ya da kullanım durumları), sistem tasarımı (yapı diyagramı, sınıf diyagramı, ardışıl diyagram), veri tabanı ve son olarak çalışan uygulamanın gösterimi.

Hoca sunumların arasına girerek kısa yorumlar yaptı ve bu yorumların yalnız o gruba değil bütün gruplara yönelik olduğunu, "doğrumuzu, yanlışımızı görmek için" paylaşıldığını belirtti. Bu notta sunumların içeriği, diyagram örnekleri ve hocanın düzeltmeleri sırasıyla verilir. Bir de küçük bir sunum kuralı hatırlatıldı: sunum hocaya değil, bütün dinleyicilere yapılır.

## 2. Market fiyat karşılaştırma sistemi: fizibilite, gereksinim toplama, kavramsal sınıf diyagramı

### 2.1 Sistem ve fizibilite

İlk sunulan sistem, kullanıcının oluşturduğu alışveriş sepetini üç marketin fiyatlarıyla karşılaştıran bir masaüstü uygulamasıydı. Grup fizibiliteyi sistemin "şu anki hali" (yalnız kişisel bilgisayarda çalışan bir prototip) ve "olmasını istedikleri hali" (çevrim içi bir hizmet) için ayrı ayrı değerlendirdi:

- Teknik fizibilite: şu anki hali için kişisel bilgisayar yeterli, çevrim içi hali için sunucu gerekir.
- Sosyal fizibilite: sistem kullanıcıya tasarruf sağlamak için tasarlanmıştır.
- Yasal fizibilite: prototip olduğu için yasal yükümlülük yoktur; kullanıcıdan alınan bilgiler bir işlemde kullanılmadığı için Kişisel Verilerin Korunması Kanunu çiğnenmez. Uygulamaya açılırsa ürün verileri kullanılan marketlerle anlaşma yapılması gerekir (ekrandan, 00:05:00).
- Ekonomik fizibilite: raporda masraflar bir tabloyla verilmişti (ekrandan, 00:05:00). Gelirler (reklam ve anlaşma gelirleri) tahmin edilemediği için tabloya eklenmemişti.

| Masraflar | Miktar |
|---|---|
| Sunucu (aylık) | 340,00 TL |
| Programcı (saatlik) | 30,00 TL |
| Analist (saatlik) | 35,00 TL |
| Tasarımcı (saatlik) | 25,00 TL |
| Öngörülen toplam masraf | 3940,00 TL |

Grup Gantt diyagramında beş iş paketi planladığını, ama buna tam uyamadığını anlattı: nesneye yönelik bir proje olduğu hâlde veri akış diyagramı da çizmişler, kodlamaya ayrılan 7 gün de beklenenden uzun sürmüştü.

> **Hocanın vurgusu:** Bu çok hızlı, çok özet bir fizibilite. Normalde daha ayrıntılı, karşılaştırmalı, alternatifleri değerlendiren bir çalışma gerekir. Ekonomik fizibilitede "ne zaman kâra geçeceğimizi bilmiyoruz" deyip bırakmak yerine sistemin ne kadar maliyet faydası ve nasıl bir verim artışı sağlayacağı analiz edilmelidir.

### 2.2 Analiz: kullanım senaryosu modeli

Kullanım senaryosu modelinde tek aktör vardı: kullanıcı. Kullanım durumları şunlardı: sisteme giriş yapma, üye olma, kullanıcı adı ve şifre değiştirme, ad-soyad değiştirme, öneri ve şikâyetler için geri bildirim gönderme, sepet oluşturma (ürün ekleme) ve sistemin asıl amacı olan fiyat karşılaştırma. Planlanan indirim takibi modülü, veriler internetteki sitelerden çekilemediği için gerçekleştirilememişti.

Hoca burada gereksinim toplama konusunu sordu. Kitleye hitap eden bir fiyat karşılaştırma uygulamasında kullanıcıların sistemden ne beklediğini öğrenmek için bir anket beklenirdi: hangi işlevler olsun, kullanıcı için önem sırası nedir (fiyat mı, kalite mi, yüksek puan mı). Grup müşteriyle anket yerine açık bir sohbet şeklinde görüştüğünü ve bunu rapora koymanın doğru olup olmadığını bilemediğini söyledi.

> **Hocanın vurgusu:** En azından bu görüşmeyi yaptığınızı, hangi verilere ulaştığınızı ve gereksinimlerin, use case'lerin nasıl oluştuğunu göstermeniz gerekir. Ayrıca use case diyagramı var ama use case'lerin kendisi (metinleri) yok.

### 2.3 Kavramsal sınıf diyagramı ve tasarım

Grup "kavramsal sınıf diyagramı" başlığı altında metotlarıyla birlikte son yazılım sınıflarını göstermişti. Bunun nedeni, kodlamaya önceden başlayıp sınıfları önce oluşturmalarıydı.

> **Hocanın vurgusu:** Kavramsal sınıf diyagramında davranışlar yer almaz. Analizde davranışların ne olacağını henüz bilmeyiz; yalnız kavramları ve aralarındaki ilişkileri ortaya çıkarırız. Davranışları ve sorumlulukları olan bir diyagram, tasarımın sonunda oluşan yazılım sınıf diyagramıdır.

Varlık ilişki modelinde iki varlık vardı: Kullanıcı (birincil anahtar kullanıcı adı; ad, soyad, şifre) ve Ürün (birincil anahtar ürün adı; kategori ve üç marketin ayrı fiyatları). İkisi arasında "tarafından seçilir" ilişkisi 1-n kardinaliteyle çizilmişti: bir kullanıcı birden fazla ürün seçebilir (ekrandan, 00:10:00). Ardışıl diyagram örneği olarak giriş işlemi anlatıldı: kullanıcı kullanıcı adı ve şifresini bir giriş denetleyici (controller) sınıfına gönderir, bu sınıf veri tabanındaki kullanıcıları bir diziye alıp arar, bulursa kullanıcıya girişin yapıldığı mesajını döner. Veri tabanı olarak MySQL kullanılmış, ürün verileri internetten çekilemediği için Excel'de hazırlanıp veri tabanına aktarılmıştı.

Gösterimin sonunda hoca raporlama özelliği (en çok alınan ürünler, en popüler ürünler gibi) olup olmadığını sordu; grup veriler doğrudan sitelerden çekilemediği için bunu yapamadığını söyledi.

## 3. Hayvanat bahçesi bilgi sistemi: veri akışlarının adlandırılması ve ER diyagramı

### 3.1 Sistem ve fizibilite

İkinci sistem, hayvanların, çalışanların ve ziyaretçilerin bilgilerini yöneten bir hayvanat bahçesi bilgi sistemiydi. Dört ana modül vardı: kafes ve hayvan işlemleri, ziyaretçi işlemleri, istatistik ve raporlama, hayvan-ziyaretçi-çalışan tabloları. Fizibilitede teknik olarak Java (projeye uygunluğu ve ekibin bilgisi nedeniyle) ve Microsoft SQL Server 2019, kod takibi için özel bir GitHub deposu seçilmişti. Zaman fizibilitesinde müşteri toplantısından sonra yedi haftalık bir süreç planlanmıştı. Yönetim fizibilitesinde üç kullanıcı tipi tanımlanmıştı: yönetim (her şeye erişir), çalışan (sınırlı bilgiye erişir) ve müşteri (yalnız bilet alır).

> **Hocanın vurgusu:** Fizibilitede yine bir matris, bir karşılaştırma beklerdim: neden Java, neden bu SQL. Fizibilitede asıl beklenti "bunu nasıl yaparız, en iyi nasıl yapabiliriz" sorusunun cevabını ortaya çıkarmaktır.

### 3.2 Taslak veri akış diyagramı ve okların adlandırılması

Taslak (bağlam) diyagramında ortada "Hayvanat Bahçesi Bilgi Sistemi", çevresinde Yönetim, Müşteri ve Çalışan dış varlıkları vardı (ekrandan, 00:20:00). Okların adları şöyleydi:

| Kaynak | Hedef | Ok üzerindeki ad |
|---|---|---|
| Sistem | Yönetim | Kullanıcı Bilgisi Çek, Hayvan Bilgisi Çek, Çalışan Bilgisi Çek |
| Sistem | Müşteri | Bilet Al |
| Müşteri | Sistem | Bakiye Ekle |
| Çalışan | Sistem | Cage Ekle, Maaş Güncelle, Hayvan Ekle/Güncelle |

Hoca bu diyagramdaki temel hatayı gösterdi: veri akışlarına eylem adları verilmişti. Bir veri akışı, adı üstünde, veridir; işlem değildir. Çalışandan sisteme gelen şey örneğin "hayvan bilgisi"dir, müşteriden gelen "para"dır, müşteriye giden "bilet"tir; yönetim hayvan bilgilerini ve çalışan bilgilerini alır.

> **Hocanın vurgusu:** Veri akışlarına "çek, ekle, yap, yaz, et" gibi fiiller yazılmaz. Bunu gözden kaçırmayın, bu konuda bir daha dikkat edin.

Birinci düzey diyagramda yönetimin bilgi çekme işlemleri ilgili veri depolarından okuyup yönetime iletiyor, çalışanın kafes ekleme, maaş güncelleme ve hayvan ekleme/güncelleme işlemleri ilgili depolara yazıyordu. İkinci düzeyde maaş güncelleme işlemi açılmıştı: önce mevcut maaş bilgisi alınır, sonra yeni maaş bilgisi girilir, en son güncelleme yapılıp veri deposuna kaydedilir. UML diyagramında bir veri tabanı bağlayıcı sınıfı üzerinden Animal, Cage, Customer ve Employee sınıflarına erişiliyor; Employee'den kalıtımla bakıcı, güvenlik ve veteriner alt sınıfları türetiliyordu.

### 3.3 Tablo görünümü ER diyagramı değildir

Grup "ER diyagramı" başlığıyla şu tabloları ve alanlarını gösterdi (ekrandan, 00:25:00):

| Tablo | Alanlar (anahtar simgeli olan ilk yazıldı) |
|---|---|
| EmployeeShift | citizenCard; shift_time |
| VisitedCage | customer_id, cage_id |
| Cage | id |
| Customer | citizenCard; first_name, last_name, age, card_balance |
| CustomerTimeLog | citizenCard, enter_time, exit_time |
| Animal | id; animal_name, animal_type, feed_frequency, cageId, care_taker |
| Employee | citizenCard; first_name, last_name, employee_type, salary |

Grubun anlatımına göre kafes ile hayvan arasında bire bir ilişki vardı (bir kafeste bir hayvan), müşterinin yaşı yaşa göre indirimli bilet fiyatı için tutuluyordu (12 yaşından küçükler 5 TL, 12-18 yaş 7,5 TL, büyükler 10 TL) ve giriş-çıkış kayıtları ziyaretçilerin hangi gün ve saatlerde geldiğini analiz etmek için saklanıyordu.

Hoca bunun bir ER diyagramı olmadığını açıkladı. Bu görünüm, veri tabanı yönetim araçlarının (SQL Server, MySQL vb.) veri tabanını görselleştirmek için ürettiği bir araç çıktısıdır; burada tablolar ve alanları görülür, ilişkiler ve nitelikler düzgün izlenemez. Özellikle N-N ilişkiler, ilişki tablosu sıradan bir tablo gibi göründüğü için takip edilemez; ER diyagramında ise ilişki baklava (eşkenar dörtgen) biçiminde görülmelidir.

> **Hocanın vurgusu:** Aynı bilgiyi farklı bir biçimde veriyor, ama bu "database dump" denen bir görünümdür. Çalışma hayatınızda da ER denince sık sık bunu çıkarıp vereceksiniz; ama bu aslında ER değildir.

## 4. Otel bilgi sistemi: anket, veri akış diyagramı düzeyleri, yapı diyagramı

### 4.1 Senaryo ve gereksinim toplama

Bu grubun senaryosu, artan talep nedeniyle büyüyen küçük bir aile pansiyonunun kayıtlarını elle tutmaktan dijital bir otel yönetim bilgi sistemine geçmesiydi. Gereksinimler toplantılarda ekip üyelerinin kendilerini müşteri yerine koymasıyla belirlenmiş, sonuçta sistemin hızlı ve kolay bir arayüze sahip olması gerektiğine karar verilmişti. Ayrıca bir tanıtım web sitesi ve müşteri beklentilerini toplamak için bir anket hazırlanmıştı (hangi yoldan bilgi almak istersiniz, indirimlerden haberdar olmak ister misiniz gibi sorular).

### 4.2 Veri akış diyagramları

- Taslak düzey: Müşteri, Resepsiyon ve Otel Bilgi Sistemi. Müşteri müşteri bilgilerini sisteme gönderir, sistem rezervasyon bilgilerini müşteriye döner; resepsiyonla sistem arasında oda bilgileri ve rezervasyon bilgileri akar.
- Birinci düzey: müşterinin üyelik bilgileri alınıp kayıt veri deposuna yazılır; rezervasyon istekleri "uygun odaları belirle" işlemine gider, resepsiyon müşterinin talebine göre oda seçer, seçilen oda oda durumları deposuna yazılır ve oda bilgisi rezervasyon işlemine geçer; sonunda müşteriye rezervasyon özeti verilir.
- İkinci düzey (uygun odaları belirle): fiyat aralığına uygun odalar listelenir, önceki müşterinin çıkış günü kontrol edilir (pandemi koşulları nedeniyle çıkış ile yeni giriş arasında bir süre bırakılır), sonra odanın temizlik ve dezenfeksiyon durumu kontrol edilir; temizlik durumu uygun oda belirleme işlemine döner ve seçilen oda kaydedilir.
- İkinci düzey (oda rezervasyonu) (ekrandan, 00:40:00): "Otel oda durumları veritabanı" deposundan ve "uygun odaları belirle" işleminden gelen seçilen oda bilgisi "Oda ayrıntıları" işlemine girer; buradan fiyat bilgisi "ödeme yap" işlemine gider; Müşteri ödeme bilgilerini "ödeme yap" işlemine verir; ödeme yapıldıktan sonra fatura bilgisi "fatura oluştur" işlemine geçer ve rezervasyon özeti Müşteri'ye verilir.

Hoca ikinci düzeylerin uzun uzun anlatılmasına gerek olmadığını, gösterilip tasarıma geçilmesini istedi.

### 4.3 Yapı diyagramı ve veri modeli

Yapı diyagramında otel modülünün altında müşteri kaydı (kayıt onaylama), müşteri talepleri ve oda rezervasyonu modülleri vardı; müşteri taleplerinden uygun odaların belirlenmesine, oradan oda seçeneklerine iniliyor, rezervasyonun altında ödeme yer alıyordu. Veri modelinde müşteri (anahtar: ID; ad, soyad, kimlik numarası, doğum tarihi), resepsiyon (ID, ad, soyad, maaş), oda (ID; resepsiyon ID yabancı anahtar; oda türü, temizlik durumu, son müşterinin çıkış zamanı, kat numarası) ve müşteri-oda ilişki tablosu (rezervasyonun başlangıç ve bitişi) vardı.

## 5. Yemek sipariş sistemi: Gantt, veri akış ve UML diyagramları, iki yaklaşımın birlikte kullanılması

### 5.1 Problem ve zaman planı

Telefonla sipariş alıp kâğıda kaydeden bir restoran, pandemiden sonra artan sipariş sayısına yetişemediği için çevrim içi bir paket servis sistemine geçmek istiyordu. Grup Gantt diyagramını proje başında tasarlamış, görev sürelerini tahmin edemedikleri için sonradan düzeltmişti. Diyagram görev, süre, başlangıç, bitiş, öncül görev, kaynak ve maliyet sütunlarından oluşuyordu (ekrandan, 00:45:00):

| No | Görev | Süre | Öncül | Kaynak | Maliyet |
|---|---|---|---|---|---|
| 1 | Yemek sipariş (tüm proje) | 42 gün | | | 10.160 TL |
| 2 | Ön inceleme ve fizibilite | 3 gün | | | 960 TL |
| 3-5 | Toplantı-1; ekip yapısı ve organizasyon şeması; Gantt diyagramı oluşturma | 1'er gün | 3, 4 | Proje yöneticisi | 320'şer TL |
| 6 | Sistem analizi | 3 gün | 2 | | 720 TL |
| 7-9 | Taslak, 1. düzey, 2. düzey veri akış diyagramı | 1'er gün | 7, 8 | Sistem analisti | 240'ar TL |
| 10 | Tasarım | 7 gün | 6 | | 1.760 TL |
| 11-13 | Yapı diyagramı (3 gün); E-R diyagramı (3 gün); Toplantı-2 (1 gün) | | 11, 12 | Sistem analisti / proje yöneticisi | 720 TL, 720 TL, 320 TL |
| 14 | Gerçekleştirme | 27 gün | 10 | | 6.400 TL |
| 15-16 | Fiziksel veritabanı (5 gün); Kodlama (15 gün) | | 15 | Programcılar | 1.600 TL, 4.800 TL |
| 17 | Test | 2 gün | 14 | | 320 TL |
| 18-19 | Müşteri değerlendirmesi; Toplantı-3 | 1'er gün | 18 | Müşteri / proje yöneticisi | 0 TL, 320 TL |

Ana görevlerin maliyetleri alt görevlerin toplamıdır: $3 \times 320 = 960$, $3 \times 240 = 720$, $720 + 720 + 320 = 1760$, $1600 + 4800 = 6400$, $0 + 320 = 320$ ve proje toplamı $960 + 720 + 1760 + 6400 + 320 = 10160$ TL (python ile doğrulandı).

Hoca fizibilitede yalnız zaman fizibilitesi mi yapıldığını sordu; grup diğer türlerin raporda olduğunu, sunuma koymadıklarını söyledi.

### 5.2 Analiz ve tasarım diyagramları

- Veri akış diyagramları: sıfırıncı düzeyde müşteri ve restoran aktörleri; birinci düzeyde beş işlem ve D1-D5 veri depoları; ikinci düzeyde örneğin 2.0 işleminin dört alt işlemi (restoran seçme, ürün ekleme, ürün çıkarma, sipariş oluşturma). Veri sözlüğünden her türe bir örnek verildi (örneğin müşteriler veri deposu girişi).
- Varlık ilişki diyagramı: gereksinim analizine göre önce varlıklar, sonra ilişkiler, sonra nitelikler belirlenmiş; altı çizili nitelikler birincil, "#" işaretliler yabancı anahtar. Bir müşteri n sipariş verebildiği için ilişki ucu buna göre çizilmiş. Uygulamada gerçekleştirilemeyen "sipariş değerlendirme" son hâlden çıkarılmıştı.
- Kullanım senaryosu diyagramı: aktörler müşteri ve restoran; "ödeme yap" ve "sipariş değerlendirme" uygulamada gerçekleştirilememişti.
- UML sınıf diyagramı: ürün ile sipariş arasında aggregation (zayıf bütün-parça), sipariş ile müşteri arasında composition (güçlü bütün-parça); restoran ve müşteri ortak bir üyelik sınıfından kalıtım alıyor; restoran ile sipariş ve ürün arasında bire çok ilişki.
- Yapı diyagramı: üye olma ve üye girişi alt modülleri; girişten sonra kullanıcı türüne göre müşteri için restoran ürünlerini görüntüleme, sipariş verme ve uygulamayı 1-5 arası değerlendirme; restoran için ürün ekleme ve çıkarma.
- Ardışıl diyagram (ekrandan, 00:50:00): `:Urun` nesnesi `aUrun:Urun` nesnesine sırasıyla `Urun(String ad, double fiyat)` yapıcı çağrısını, `getAd()` (dönüş `String ad`), `getFiyat()` (dönüş `double Fiyat`) ve `setFiyat(double fiyat)` mesajlarını gönderir; her çağrının dönüşü kesikli okla gösterilir.

### 5.3 Yapısal ve nesneye yönelik çözümleme birlikte

Hoca grubun hem fonksiyonel (yapısal) çözümlemeyi hem nesneye yönelik çözümlemeyi birlikte yaptığını fark edip nedenini sordu. Grup raporda yazan her şeyi yaptığını söyledi; hoca ödev tanımında "ya bu ya bu" diye yazdığını, birini yapmanın yeterli olduğunu açıkladı ve fazladan yapılmış saydı.

## 6. Dijital oyun abonelik sistemi: eksik analiz modeli

Bu grup bir dijital oyun abonelik sistemi geliştirmişti. Süreç toplantı raporlarıyla anlatıldı: müşteri belirleme, müşteriyle görüşme, diyagramların çizilip müşteriye sunulması ve geri bildirimle son hâle getirilmesi, kodlama, birleştirme ve test, uygulamanın müşteriye tanıtılması ve projenin kapanış toplantısı. Ardışıl diyagramlar (admin girişi, abone işlemleri, fiyat değişimi), genel UML sınıf diyagramı (kullanıcı, oyun, oyun yöneticisi gibi sınıflar ve form sınıfları) ve kullanıcı-oyun ilişkisini gösteren ER diyagramı gösterildi. Uygulamada oyun listeleme, yükleme-silme, puanlama, profil ve otomatik abonelik yenileme ile bir admin paneli (abonelik fiyatını güncelleme, oyun ekleme-silme) vardı; veriler metin dosyalarında tutuluyordu (ekrandan, 01:00:00).

Hoca grubun analizi nasıl yaptığını, verileri nasıl topladığını ve senaryolarını göremediğini söyledi; gösterilen ardışıl diyagramların davranışları gösterdiğini, yani tasarıma ait olduğunu, analiz modelinin ise sunumda bulunmadığını belirtti.

> **Hocanın vurgusu:** Fizibilite çalışması ile sistem analizi ayrı konulardır; ikisini birleştirmeyin. Gantt diyagramı da zaman fizibilitesi için yapılır.

## 7. Konfeksiyon deposu yönetim sistemi: Gantt, Chen gösterimli ER diyagramı, kritik stok

### 7.1 Problem ve çözüm

Bu grup sunumunu önceden kaydedilmiş bir video olarak gösterdi. Problem: konfeksiyon mağazaları stok tükenmesine karşı ürünleri bir depoda tutmalı, gerektiğinde mağazalara göndermeli ve kayıt altına almalıdır; depo iyi yönetilmezse önemli mali kayıplar doğar. Çözüm: ürün giriş-çıkışını kaydeden, mağaza raflarındaki ürünlerin kritik stok takibini yapan, tükenmekte olan ürün için otomatik sipariş oluşturan, deponun doluluk oranını izleyen ve şubeler arası satış karşılaştırması sunan bir web tabanlı bilgi sistemi. Hedef kitle birden fazla şubesi olan büyük ve orta ölçekli konfeksiyon firmalarıydı.

### 7.2 Gantt diyagramı

Görevler üç ana başlıkta toplanmıştı (ekrandan, 01:05:00): Analiz (10 gün: müşteriden proje ayrıntılarının alınması, analiz birimi giriş toplantısı, fizibilite çalışması, benzer sistemlerin gözden geçirilmesi, ara toplantı, gereksinimlerin belirlenmesi, gerekli verilerin toplanması, analiz birim toplantısı), Tasarım (15 gün: giriş toplantısı, modüller için ön tasarım, modüller için ayrıntılı tasarım, arayüz tasarımı, tasarım birimi toplantısı) ve Geliştirme ve Test (27 gün: arka plan geliştirme, modüler test, sistem testi, kullanıcı testi, teslim toplantısı). Toplam süre $10 + 15 + 27 = 52$ gündür.

Fizibilitede yazılım ve donanım gereksinimleri (sunucu kiralama, diller ve çatılar), hedef kitle, gelir-gider hesabı ve yasal konular (kullanılan kütüphanelerin lisansları, çalışanlarla gizlilik sözleşmesi) ele alınmıştı. Veri akış diyagramlarında kargo, depo ve mağaza dış varlıkları; birinci düzeyde depo işlemleri, sipariş işlemleri ve kargo işlemleri ile depo mal kayıtları, mağaza stok kayıtları ve kargo kayıtları veri depoları vardı.

### 7.3 ER diyagramı (Chen gösterimi)

Bu grup ER diyagramını hocanın beklediği gösterimle çizmişti (ekrandan, 01:10:00): varlıklar dikdörtgen, nitelikler elips, ilişkiler "has" baklavası, anahtar nitelikler altı çizili.

| Varlık | Nitelikler | İlişki |
|---|---|---|
| User | userid, username, password | User 1 - N Branch; User 1 - 1 Store |
| Branch | branchid, userid, branchname, adress | Branch 1 - N Salerecords; Branch 1 - N Product |
| Salerecords (çift çerçeve, zayıf varlık) | branchid, count, productname | |
| Store | storeid, userid, storename, capacity | Store 1 - N Storeproduct |
| Storeproduct | storeid, productname, quantity | |
| Product | pid, branchid, productname, quantity, state | Product 1 - 1 Approval |
| Approval | pid, productname, state | |

Kritik stok mantığı gösterimde şöyle çalıştı: bir şubedeki ürün sayısı tanımlı kritik seviyenin (örnekte 50) altına indiğinde büyük depodan o şubeye otomatik sipariş oluşur; kargo süreci gerçekleştirilemediği için sipariş "onay bekliyor" durumuna düşer, onaylanınca ürün şubeye eklenip depodan düşülür. Şubede yeterli ürün yoksa satış uyarı verir. Satış raporunda şubelerin satışları karşılaştırılır. Hoca uygulamanın bir paket program gibi gerçekleştirildiğini olumlu karşıladı.

## 8. Online tren bileti sistemi: fizibilite, veri akış diyagramları, veri sözlüğü, ER

### 8.1 Fizibilite

Amaç bilet satışını hızlandırmak, işlemleri çevrim içi yapmak ve pandemi koşullarına uyum sağlamaktı. Fizibilite ayrıntılıydı:

- Teknik: arayüz için Python ve PyQt5 (Designer ortamı), veri tabanı için PostgreSQL ve pgAdmin; use case için Visio, VAD, ER ve UML için draw.io; donanım kaynakları ve donanımdan doğabilecek teknik riskler ile çözümleri.
- Sosyal: her yaştan kullanıcıya hitap edeceği için sistemin basit olması; HES kodu sorgulaması ve koltuk doluluk oranının pandemi kurallarına göre izlenmesi; kullanıcı beklentileri (güvenlik, basitlik, anlaşılabilirlik, kısa adımlar).
- Zaman: Gantt diyagramı Microsoft Project ile.
- Yasal: anayasaya uygunluk; ekonomi, ticaret, istihdam, vergilendirme ve muhasebe konularında uygunluk.
- Ekonomik: Gantt'taki görev sürelerine ve rollerin ücretlerine göre maliyet analizi; slaytta toplam maliyet 41.035,00 TL olarak gösterildi ve proje yöneticisi, iş analisti, sistem analisti, iki arayüz geliştirici ve veri tabanı geliştirici için fiili, kalan ve temel maliyet sütunları vardı (ekrandan, 01:20:00).

### 8.2 Veri akış diyagramları ve veri sözlüğü

Taslak diyagramda müşteri kart bilgileri, ödeme seçenekleri ve kişisel bilgilerini sisteme verip bilet alıyor, demir yolu şirketi sefer ekleyip müşteri bilgileri, sefer ayrıntıları ve ödeme bilgilerini alıyordu. Birinci düzeyde kayıt olma, ödeme yapma, sefer arama ve sefer seçimi modülleri vardı; sefer seçimi koltuk tipi seçimi, koltuk seçimi (pandemi kuralına göre çapraz), saat seçimi gibi alt aşamalara ayrılıyordu. İkinci düzeyde ödeme yapma, sefer arama ve sefer seçimi açılmıştı.

Veri sözlüğü beş kategoriden birer örnekle verildi:

- Veri akışı: müşteriden kayıt olma işlemine giden kişisel bilgiler (ad, soyad, e-posta, şifre, telefon, cinsiyet, kimlik numarası, HES kodu).
- Veri yapısı: müşteri ayrıntıları (kayıt için gerekli kişisel bilgiler).
- Veri deposu: üyeler (kayıtlı üyelerin kişisel bilgileri).
- Veri elemanı: HES kodu; alfanümerik, uzunluk 10.
- İşlem: kayıt olma; girdi kişisel bilgiler, bilgiler eksiksizse üyeler deposuna kaydedilir, eksikse hata verilir; çıktı üye bilgileridir.

Kullanım durumlarında hata durumları ayrıca ele alınmıştı: yanlış e-posta ya da parola, daha önce kullanılmış e-posta, 11 haneli olmayan kimlik numarası, eksik bilgi, riskli HES kodu ve kurala uymayan koltuk seçimi.

### 8.3 ER diyagramı

ER diyagramında (ekrandan, 01:25:00) Sefer varlığı (sefer_id altı çizili, ek_vagon_id, bus_vagon_id; iki "Sahip" ilişkisiyle vagon varlıklarına bağlı), Guzergahlar varlığı (guzergah_num altı çizili, kalkis_yeri, varis_yeri, ucret) ve aralarında çift çizgili baklava ile gösterilmiş "Seferler" ilişkisi (nitelikleri guzergah_no, gun, sefer1-sefer4) vardı; Guzergahlar tarafı çift çizgiyle bağlanmıştı. Anlatıma göre altı güzergâh vardı ve her güzergâh için her gün dört sefer tanımlanıyordu. Yolcu tablosunda e-posta birincil anahtardı ve yolcu HES kodu tablosuyla ilişkiliydi (risk 0 risksiz, 1 riskli).

## 9. Kütüphane otomasyon sistemi: fizibilite, kullanım senaryosu, UML sınıf ve ardışıl diyagram

### 9.1 Sistem ve fizibilite

Üç temel aktör vardı: kullanıcı (üye), kütüphane görevlisi ve sistem admini. Üye kitap arar, müsaitse ödünç alır, değilse rezervasyon yapar, iade eder ve ceza öder; görevli kullanıcıları ve envanteri yönetir; admin görevlileri ekler ve çıkarır. Fizibilite slaytı (ekrandan, 01:35:00):

- Teknik fizibilite: ekipte yeterli teknik bilgi ve donanım, internet bağlantısı ve bilgisayarlar mevcut; proje nesneye yönelik olduğu için Java kullanılacak.
- Yönetim fizibilitesi: benzer projeleri daha önce gerçekleştirmiş bir ekip olduğu için yönetim sıkıntısı yok; yönetim projeye olumlu bakıyor.
- Zaman fizibilitesi: proje teklifi 23 Mart-2 Nisan; ön inceleme/fizibilite raporları 2-7 Nisan; yapılabilirlik kabulü 7 Nisan; use case ve UML diyagramlarının hazırlanması 8-18 Nisan; proje taslak kabulü 18 Nisan; yazılım ekibinin çalışmaları 19 Nisan-25 Mayıs; test süreci 25-29 Mayıs; proje teslimi 1 Haziran.

Yasal fizibilitede kullanılan yazılımların özel lisans gerektirmediği, ekonomik fizibilitede proje bedelinin 75.000 TL, giderin 37.500 TL ve net gelirin 37.500 TL olduğu söylendi.

> **Ders sonrası not:** Sunumda gider "53 gün ve kişi başı 150 TL" ile 37.500 TL olarak verildi. $53 \times 150 = 7950$ ettiği için bu hesap anlatıldığı haliyle tutmuyor; 37.500 TL büyük olasılıkla kişi sayısı ve gün sayısının birlikte çarpılmasıyla bulunmuştur ($37500 / 150 = 250$ kişi-gün). Net gelir $75000 - 37500 = 37500$ TL'dir. <!-- BELİRSİZ: giderin hesaplanma biçimi altyazıdan net çıkmıyor -->

### 9.2 Kullanım senaryosu

Bir kullanım senaryosu metin olarak verildi. Üyenin beklentisi kitabın depoda bulunması ve ödünç alma ya da rezervasyon işleminin gerçekleşmesidir. Temel akış: üye giriş yapar, kitabı arar, kitap müsaitse ödünç alır. Alternatif akışlar: üyelik bilgisi yanlış girilirse, kitap bulunamazsa ya da üye alabileceği en fazla kitap sayısına ulaştıysa işlem yapılamaz ve sistem hata mesajı verir.

### 9.3 UML sınıf diyagramı

Sınıf diyagramı (ekrandan, 01:40:00):

| Sınıf | Nitelikler | Metotlar |
|---|---|---|
| Account | id, password, name, email, phone (string) | resetPassword(): bool |
| Librarian (Account'tan türer) | | addBookItem(), blockMember(), unblockMember(): bool |
| Member (Account'tan türer) | totalBooks: int, currentBooks: list<Book> | getCurrentBooks(): list<Book> |
| Book | ISBN, title, subject, language, publisher, authorID (string) | getTitle(), getAutor(): string |
| BookItem (Book'tan türer) | bookID: string, publicationDate: date, status: string | getStatus(): string |
| BookBorrowing | bookISBN, memberID: string, borrowDate, dueDate: date | getDueDate(): date |

İlişkiler: Member 1 - 0..5 BookItem ("borrows"), Member 1 - 0..5 BookBorrowing ("makes"), Librarian'dan BookItem'a "add/update". Kalıtım içi boş üçgen okla ("Extends") gösterilmiş.

Ardışıl diyagramda kitap ödünç alma sayfası sınıfı bir veri tabanı bağlantı sınıfı oluşturup veri tabanına bağlanıyor ve ödünç alma kaydını ekleyen metodu çağırıyordu. Veri tabanında (PostgreSQL) üç tablo vardı: hesaplar (hesap türü sütunuyla admin, görevli ya da normal kullanıcı ayrımı), etkinlikler (ödünç alma, rezervasyon gibi işlemler) ve kitaplar (ID, ISBN, başlık, tür, dil). Uygulamada ödünç alınan kitaba 15 günlük iade tarihi atanıyor, geç iadede gün başına 2 TL ceza hesaplanıyor (örnekte iki gün gecikme), müsait olmayan kitap için önceki ödünç alanın iade tarihine göre rezervasyon yapılıyordu.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:09:14): Bir projede use case diyagramı çizilmiş ama use case'lerin kendisi verilmemiş. Eksik olan nedir?

> **Çözüm (derste verilmedi):** Diyagram yalnız aktörleri ve kullanım durumlarının adlarını gösterir. Her kullanım durumu için senaryo metni (birincil aktör, ön koşullar, temel olay akışı, alternatif akışlar) yazılmalıdır. Kütüphane sisteminin ödünç alma senaryosu (9.2) bu biçime bir örnektir.

**Soru 2** (derste sözlü, 00:09:22): Kavramsal sınıf diyagramına metotlar konabilir mi?

Cevap (derste verildi): Hayır. Kavramsal sınıf diyagramı analizde çizilir; davranışlar henüz bilinmez, yalnız kavramlar ve ilişkiler gösterilir. Metotları ve sorumlulukları olan diyagram tasarımın sonunda oluşan yazılım sınıf diyagramıdır.

**Soru 3** (ekrandan, 00:20:00; derste sözlü, 00:20:55): Hayvanat bahçesi sisteminin taslak veri akış diyagramındaki oklar "Bilet Al", "Bakiye Ekle", "Maaş Güncelle", "Hayvan Ekle/Güncelle", "Kullanıcı Bilgisi Çek" diye adlandırılmış. Bu adlandırmadaki hata nedir, nasıl düzeltilir?

Cevap (derste verildi): Veri akışları eylem değil veridir. Oklar üzerinde fiil kullanılmaz. Müşteriden sisteme "para", sistemden müşteriye "bilet", çalışandan sisteme "hayvan bilgisi" akar; yönetim "hayvan bilgileri" ve "çalışan bilgileri" alır.

**Soru 4** (ekrandan, 00:25:00; derste sözlü, 00:25:48): Veri tabanı yönetim aracının ürettiği, tabloları ve alanlarını gösteren diyagram ER diyagramı mıdır?

Cevap (derste verildi): Hayır. Bu bir veri tabanı görünümüdür (database dump). İlişkiler ve nitelikler düzgün izlenemez, N-N ilişkiler ayrı bir tablo olarak görünür. ER diyagramında ilişki eşkenar dörtgenle (baklava) gösterilmelidir.

**Soru 5** (derste sözlü, 00:45:25): Fizibilitede yalnız zaman fizibilitesi yapmak yeterli midir?

> **Çözüm (derste verilmedi):** Hayır. Sunumlarda görüldüğü gibi teknik, ekonomik, yasal, sosyal (operasyonel), zaman ve yönetim fizibiliteleri birlikte değerlendirilir. Gantt diyagramı yalnız zaman fizibilitesinin aracıdır.

**Soru 6** (derste sözlü, 00:49:31): Bir projede hem fonksiyonel (yapısal) hem nesneye yönelik çözümleme birlikte yapılmalı mı?

Cevap (derste verildi): Gerek yoktur; ödevde ikisinden biri istenmişti ve birini yapmak yeterlidir.

**Soru 7** (derste sözlü, 01:01:22): Ardışıl diyagramlar analiz modeli yerine geçer mi?

Cevap (derste verildi): Hayır. Ardışıl diyagramlar nesnelerin nasıl davrandığını gösterir ve tasarıma aittir. Analiz modelinde verilerin nasıl toplandığı, senaryolar ve gereksinimler yer almalıdır. Fizibilite çalışması ile sistem analizi de ayrı konulardır.

## Dersin Toparlaması

Bu derste sekiz bilgi sistemi projesi sunuldu ve hocanın geri bildirimleri dönem boyunca anlatılan kuralları pratik hatalar üzerinden tekrar etti. Fizibilitede seçimler alternatiflerle karşılaştırılarak gerekçelendirilmeli, ekonomik fizibilitede maliyet faydası ve verim artışı analiz edilmelidir. Analiz aşamasında gereksinimlerin kaynağı (anket, görüşme) ve use case metinleri gösterilmeli, fizibilite ile sistem analizi birbirine karıştırılmamalıdır.

Diyagram kurallarında üç nokta öne çıktı: veri akış diyagramında oklar eylem değil veri taşır; kavramsal sınıf diyagramında metot bulunmaz, metotlu diyagram tasarımın ürünüdür; veri tabanı aracının tablo görünümü ER diyagramı değildir, ER'de ilişkiler baklavayla gösterilir. Ayrıca yapısal ve nesneye yönelik yaklaşımdan birini seçmek yeterlidir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
