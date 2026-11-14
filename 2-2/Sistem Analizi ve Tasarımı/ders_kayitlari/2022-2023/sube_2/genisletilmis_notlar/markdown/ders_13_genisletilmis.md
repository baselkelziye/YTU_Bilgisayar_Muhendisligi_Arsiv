# Ders 13 Genişletilmiş Notu: Dönem Projesi Sunumları 2: Market, Scooter, Bankacılık, Kütüphane ve Süpermarket

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Bu Sunumlar Nasıl Okunmalı?
- 2. Online Market Sistemi
- 3. Scooter Kiralama Otomasyonu
- 4. Online Bankacılık Sistemi
- 5. Kütüphane Masa ve Mola Takip Sistemi
- 6. Süpermarket Bilgi Sistemi
- 7. Beş Projenin Karşılaştırılması
- 8. Hocanın Geri Bildirimleri ve Çıkan Dersler

## 1. Bu Sunumlar Nasıl Okunmalı?

Bu derste yeni konu anlatılmadı. Öğrenci grupları dönem boyunca geliştirdikleri projeleri sundu, hoca da araya girerek sorular sordu. Bu not sunumları değerlendirmek için değil, dönem boyunca görülen araçların gerçek bir proje üzerinde nasıl kullanıldığını görmek için yazıldı. Gruplar ve öğrenciler adsızdır.

Sunumların çoğu aynı omurgayı izledi:

- Problem tanımı ve projeye duyulan ihtiyaç
- Teknik, ekonomik, zaman, sosyal, yasal ve yönetim fizibilitesi
- Alternatif sistemleri karşılaştıran fizibilite matrisi
- Gereksinim analizi: anket, görüşme, kullanım senaryoları
- Çözümleme: veri akış diyagramları, veri sözlüğü, süreç tanımlama formu
- Tasarım: yapı diyagramı, varlık-ilişki (ER) diyagramı ya da sınıf diyagramı
- Gerçekleştirme ve çalışan sistemin gösterimi

Bu nedenle aşağıdaki her bölüm, tek bir konunun farklı uygulaması olarak okunabilir. Bir projede kısa geçilen adım başka bir projede ayrıntılı anlatıldı. Örneğin para transferinin 2. düzey veri akışı bankacılıkta, süreç tanımlama formu markette, kullanım senaryosunun ön ve son koşulları kütüphanede en açık biçimde görülüyor.

## 2. Online Market Sistemi

### 2.1 Problem ve Ekip Rolleri

Bir grup, hem mobil uygulaması hem web sitesi olan bir online market sistemi sundu. Grubun gerekçesi üç noktaya dayanıyordu: Mevcut marketler hız ve kolaylık açısından yetersiz kalıyor, pandemi koşullarıyla insanlar evden alışverişe alışmış ve mevcut marketlerde ürün çeşitliliği az.

Beş kişilik ekipte bir proje yöneticisi, iki yazılımcı, bir sistem analisti ve hem sistem tasarımcısı hem de müşteri rolünde bir üye vardı. Ekip yedi ana toplantı ve ayrıca ara toplantılar yaptı. Müşteri rolündeki üyeyle üç görüşme yapıldı:

- **Birinci görüşme:** Müşteri isteğini iletti.
- **İkinci görüşme:** Sistemin hangi durumda ne yaptığı, nasıl işlediği anlatıldı.
- **Üçüncü görüşme:** Sistemin son hâli müşteriye sunuldu.

<!-- BELİRSİZ: Ekip rolleri 00:03:13 çevresinde bozuk geçiyor; "sistem analisti" rolü kısa nottan, altyazıda bu rol açıkça duyulmuyor. -->

### 2.2 Fizibilite Çalışmaları

**Teknik fizibilite** yazılım ve donanım olarak ayrıldı. Web için React, mobil için Swift, veri tabanı için Firebase kullanıldı. Web sitesi Windows üzerinde, mobil uygulama macOS üzerinde geliştirildi. Kullanım senaryosu diyagramları Violet UML Editor ile, veri akış, ER ve yapı diyagramları draw.io ile çizildi. Donanım tarafında ana bilgisayarlar, sunucular, kullanıcı bilgisayarları ve telefonları ile yerel ve geniş alan ağ altyapısı sayıldı. Teknik riskler de çözümleriyle birlikte verildi: Örneğin gizlilik ve güvenlik riskine karşı güvenlik önlemlerinin alınması önerildi.

**Sosyal fizibilitede** hedef kitle, marketten alışveriş yapan düşük ve orta gelirli bireyler olarak tanımlandı. Kullanıcıların beklentileri basit arayüz, yüksek güvenlik, anlaşılırlık, az adım, düzgün satın alma ve hızlı çalışma olarak sıralandı.

**Yönetim fizibilitesinde** sistemin iş süreçlerini düzenleyeceği, yöneticilere ayrıntılı bilgi vererek doğru karar almayı kolaylaştıracağı söylendi.

**Yasal fizibilitede** ticari işletme izni, vergi kaydı, tüketici hakları, elektronik ticaret, ödeme sistemleri ve reklam düzenlemeleri sayıldı. Grup, sistemin patent ve fikrî hakları ihlal etmediğini belirtti.

### 2.3 Ekonomik Fizibilite

Harcamalar çalışan maaşları ve reklam giderlerinden oluşuyordu. Toplam maliyet 97 200 TL olarak verildi. Getiri tarafında net bugünkü değer (NBD) yöntemi kullanıldı:

- Net bugünkü değer: 198 bin TL
- İç verim oranı (İVO): %74
- İskonto oranı: %20

Grup, $\%74 > \%20$ olduğu için projenin kâr edeceği sonucuna vardı. Altyazıda "iş kontrolün" diye geçen ifade iskonto oranıdır. Geri ödeme tablosundan da projenin 26 ay sonra kâra geçeceği söylendi.

<!-- BELİRSİZ: 00:07:02'deki "2,12'den 26 ay" ifadesi net değil. Maaş ve gider kalemleri ile yıllık nakit akışı tablosu slaytta kalmış, altyazıda okunmuyor. -->

> **Ek bilgi (derste anlatılmadı):** İlk yatırımı $C$, $t$. dönem net nakit akışı $A_t$ ve iskonto oranı $i$ olan bir projede $NBD = -C + \sum_{t=1}^{n} A_t/(1+i)^t$ olur. İVO, bu ifadeyi sıfır yapan orandır. İlk yatırımdan sonra akışların pozitif sürdüğü projelerde $i$ arttıkça NBD azalır. Bu yüzden İVO'nun iskonto oranından büyük olmasıyla NBD'nin pozitif çıkması aynı kararı verir.

> **Ders sonrası not:** Sunulan üç sonuç birlikte kontrol edilebilir. Yıllık akışlar eşit ($A$) ve geri ödeme süresi $T = 26/12 \approx 2{,}17$ yıl olsaydı $A/C = 1/T$ olurdu. Eşit akışta $C = A\frac{1-(1+r)^{-n}}{r} < A/r$ olduğundan İVO, proje ömrü ne kadar uzun olursa olsun $r < 1/T \approx \%46{,}15$ kalırdı. Aynı varsayımla %20 iskontoda NBD de $C(1/(0{,}2\,T) - 1) \approx 127\,108$ TL'yi geçemezdi. Dolayısıyla %74 ve 198 bin TL, 26 aylık geri ödemeyle ancak sonraki yıllarda artan akışlarda bir arada bulunabilir. Tablo altyazıda okunmadığı için akışların biçimi doğrulanamıyor.

### 2.4 Zaman Fizibilitesi ve Fizibilite Matrisi

Proje 11 Nisan'da başlayıp 21 Mayıs'ta bitti. Süre, nisandan kalan 19 gün ile mayısın 21 gününün toplamıdır (ara adım eklendi): $19 + 21 = 40$ gün. Yazılım geliştirme modeli olarak şelale (waterfall) kullanıldı, plan Gantt şemasıyla izlendi.

Fizibilite matrisinde üç seçenek vardı:

| Seçenek | Teknoloji | Grubun değerlendirmesi |
|---|---|---|
| Sistem 1 | Java ve SQL | Ekip Java biliyor ama tecrübe az, zaman sorunu çıkar |
| Sistem 2 | Mobilde Swift, webde React | Seçilen sistem |
| Sistem 3 | Flutter | Flutter bilgisi var ama tecrübe az, zaman sorunu çıkar |

<!-- BELİRSİZ: 00:07:30 çevresinde üçüncü seçenek bozuk geçiyor; önce "sadece Flutter" deniyor, ardından web için ayrı bir araç anılıyor gibi. -->

Grubun gerekçesi, ekip tecrübesinin zaman fizibilitesine etkisiydi.

### 2.5 Gereksinim Analizi ve Kullanım Senaryoları

Gereksinim analizinde önce anketle veri toplandı. Kullanım senaryosu modelinde yönetici ürün ekliyor, çıkarıyor ve ürün bilgisini güncelliyor. Müşteri kayıt olup oturum açıyor, profilini ve bakiyesini güncelliyor, kategori seçiyor, ürün arıyor, sepete ekliyor, ödeme yapıyor ve isterse değerlendirme yapıyor.

Örnek olarak **ödeme yapma** senaryosu anlatıldı:

- **Ana akış:** Müşteri giriş ekranından sisteme girer, kategori seçer, ürünlerden istediği miktarda seçer, sepet tuşuna basıp ödeme yapar.
- **Alternatif akış:** Kategori seçim ekranından doğrudan sepete geçerek de ödeme yapabilir.
- **İstisnalar:**
  - Sepet boş olabilir.
  - Müşterinin bakiyesi sepet tutarını karşılamayabilir.
  - Müşteri stokta bulunandan fazla ürün eklemeye çalışabilir.

Bu istisnalardan yetersiz bakiye durumu, gösterimde de uyarı olarak görüldü.

### 2.6 Veri Akış Diyagramları

Taslak düzey diyagramda iki kullanıcı vardı: yönetici ve müşteri. Yönetici sisteme yalnız giriş bilgisi veriyor. Müşteri giriş bilgisinin yanında değerlendirme onayı da veriyor. Sistem de müşteriye sipariş bilgisini ve değerlendirme sorusunu döndürüyor.

1. düzeyde yöneticiden 1, müşteriden 6 süreç çıkıyordu:

- **Yönetici:** ürün fiyat işlemleri
- **Müşteri:** giriş menüsü, kayıt olma, sepet işlemleri, profil ve bakiye işlemleri, sipariş işlemleri, anket ve yorum işlemi

Süreçler veri depoları üzerinden birbirine bağlanıyordu. Yöneticinin girdiği bilgiler **ürünler** deposuna yazılıyor, sepet işlemleri bu depodan okuyor. Yeni kullanıcının bilgileri **üyeler** deposuna gidiyor. Anket cevapları **sipariş kayıtlarında** tutuluyor. Değerlendirme de döngü kuruyor: Sipariş sonrası müşteriye onay soruluyor, kabul ederse anket ve yorum sürecine dönülüyor.

2. düzeyde iki süreç açıldı:

- **Ürün fiyat işlemleri:** ürünleri görüntüle, ürün ekle, ürün sil, ürün güncelle
- **Sepet işlemleri:** kategori seç, sepete ürün ekle, sepeti görüntüle, sepetteki ürün adedini güncelle, bakiye yeterlilik ve stok kontrolü

### 2.7 Veri Sözlüğü, Süreç Tanımlama Formu ve ER Diyagramı

Veri sözlüğünden 1.4 numaralı "ürün güncelle" süreci örnek verildi. Tanımı, yöneticinin sistemde var olan bir ürünün fiyatını, stok bilgisini, ismini veya resmini değiştirmesidir. Girdisi ürünler, çıktısı ürün, fiyat ve stok bilgileridir.

Süreç tanımlama formu iki süreç için gösterildi: sepet işlemleri ile ürün güncelleme. Sepet işlemleri formunun tanımında ürün ekleme, ürün çıkarma, adet artırma ve azaltma yer alıyordu. Her iki süreç de çevrim içi işliyordu ve süreç mantığı sözde kodla yazılmıştı.

ER diyagramında üç varlık vardı: müşteri, ürünler ve yönetici. Ürünler varlığının beş niteliği sayıldı: isim, id, kategori, stok ve fiyat.

<!-- BELİRSİZ: Yapı diyagramı (00:11:35) ve süreç formlarındaki sözde kod yalnız slaytta gösterildi, altyazıda içeriği yok. -->

### 2.8 Çalışan Sistem

Mobil uygulamada yönetici kendi hesabıyla yönetici paneline yönlendiriliyor. Panelde ürünler isim, kategori, fiyat ve stokla listeleniyor. Artı düğmesiyle ürün ekleniyor, kaydırarak siliniyor, üzerine tıklanınca düzenleniyor.

Kayıt sırasında iki şifrenin uyuşması ve e-posta biçimi kontrol ediliyor. Şifre sıfırlama e-postası Firebase'in kimlik doğrulama hizmeti üzerinden gönderiliyor, bağlantıya tıklayan kullanıcı yeni şifresini giriyor. Bakiyesi sıfır olan kullanıcı alışverişte yetersiz bakiye uyarısı alıyor, profil ayarlarından bakiye ekleyince alışveriş tamamlanıyor.

Bakiye güncellemesi veri tabanı ekranında da gösterildi:

- Verilen: Başlangıç bakiyesi 45 dolar, sepet tutarı 4,86 dolar
- İşlem: $45 - 4{,}86 = 40{,}14$
- Sonuç: Yeni bakiye 40,14 dolar. Veri tabanında görülen değerle aynıdır.

Alışveriş sonrası kullanıcıya değerlendirme yapmak isteyip istemediği soruluyor. Kabul ederse evet-hayır soruları cevaplıyor ve en az 10 karakterlik yorum yazarak anketi gönderiyor. Sipariş kaydında alınan ürünler ve değerlendirme sonuçları birlikte tutuluyor.

Web tarafı React ile yazıldı ve aynı veri tabanını kullanıyor. Yönetici paneli yalnız mobilde var. Grup bunu, tek yönetici olduğu için web tarafında bu ihtiyacı duymamalarıyla açıkladı. Web sürümünü yalnız alışveriş yapacak müşteriler kullanıyor.

**Soru:** Uygulamayı neden İngilizce yaptınız? (hoca) **Cevap:** Küresel kitleye hitap etmek için.

## 3. Scooter Kiralama Otomasyonu

### 3.1 Problem ve Fayda

Senaryoda, envanterinde çok sayıda scooter ve birçok merkezi olan bir işletme, yaşadığı zorluklar nedeniyle otomasyon istiyor. Beklenen fayda iki taraflı tanımlandı: Operatör için işlem ve hesaplamaların kolaylaşması, yönetim için işlemlerin ve geçmiş kayıtların incelenebilmesi.

### 3.2 Fizibilite

**Yasal fizibilitede** grup, sistemin herhangi bir sunucuyla bağlantısı olmadığı için kişisel bilgilerin güvenliği konusunda sorun olmadığını, bilgilerin KVKK kapsamında kimseyle paylaşılmayacağını söyledi. Altyazıdaki "KBKK" ifadesi KVKK'dır.

> **Ek bilgi (derste anlatılmadı):** Verinin yerel makinede tutulması ağ üzerinden erişim riskini azaltır, ama veri işleme yükümlülüğünü ortadan kaldırmaz. Müşterinin telefon ve e-posta gibi bilgileri yerel veri tabanında da kişisel veridir. Yasal fizibilitede bu nedenle "sunucu yok" gerekçesi tek başına yeterli sayılmaz.

**Sosyal fizibilitede** scooter kullanımının yaygınlaşması ve sistemin bütün araçlar için uyarlanabilmesi gerekçe gösterildi. **Yönetim fizibilitesinde** ücret hesabında yönetime düşen yükün azalması öne çıktı. **Teknik fizibilitede** Visual Studio ve Microsoft SQL Server kullanıldı, sistem Windows üzerinde çalışıyor. Bilgisayar gereksinimi, uzun süre kararlı çalışma için biraz yüksek seçildi.

**Ekonomik fizibilite** yaklaşık bir tahminle verildi:

- Verilen: Yazılım 6000 dolar, bilgisayar 1000 ile 1500 dolar arası
- İşlem: $6000 + 1000 = 7000$ ve $6000 + 1500 = 7500$
- Sonuç: Toplam 7000-7500 dolar

**Zaman fizibilitesi** Gantt diyagramıyla planlandı. Süre dört parçaya ayrıldı:

- Ön inceleme ve fizibilite: 2 hafta
- Sistem analizi: 1 hafta
- Sistem tasarımı: 2 hafta
- Kodlama: 4 hafta

Toplam (ara adım eklendi): $2 + 1 + 2 + 4 = 9$ hafta.

**Fizibilite matrisinde** ekonomik açıdan seçenekler arasında pek fark yoktu. Belirleyici olan, ekibin C# ve Microsoft SQL'e yatkın olması ve bunun süreyi kısaltmasıydı. Bu nedenle üçüncü sistem seçildi.

### 3.3 Sistem Analizi

Bilgi toplamada anket ve bireysel görüşme kullanıldı. Görüşmelerde müşterinin hem bugün hem gelecek için beklentileri soruldu, modüller buna göre belirlendi.

0\. düzey veri akış diyagramında dikkat çeken tasarım kararı şudur: Müşteri sisteme doğrudan erişmez, işlemleri bir operatör yapar. Bu yüzden diyagramdaki iki aktör müşteri değil, **operatör** ve **yöneticidir**.

- **Operatör:** kiralama ve teslim işlemleri, müşteri kaydı, müşteri listeleme, scooter envanterini görüntüleme
- **Yönetici:** operatör atama, scooter kaydı, bakım işlemleri, geçmiş bilgileri, ortak listeleme işlemleri. Kiralama işlemi yöneticiye verilmedi.

Çoğu işlem scooter numarası ve müşteri numarası üzerinden yürüyor. Scooter ya da operatör kaydında ek bilgi gerekiyor.

1\. düzeydeki veri depoları şunlardı: müşteri, bakım, operatörler, scooter kayıtları ve kiralama geçmişi.

### 3.4 Kiralama ve Teslim Akışları

Kiralama süreci 2. düzey veri akış diyagramında şöyle anlatıldı:

```text
Operatör --(scooter no, müşteri no)--> Kontrol: ikisi de var mı?
    hata varsa: uyarı verilir, işlem durur
    hata yoksa:
      Scooter kayıtları : müsaitlik "uygun" --> "kirada"
      Kiralama geçmişi  : yeni kayıt (o günün tarihi ve saati)
```

Kiralama geçmişi kaydının teslim tarihi, süre ve ücret alanları bu anda boş kalıyor. Bu alanlar teslimde dolduruluyor:

```text
Operatör --(müşteri no)--> Kontrol
    hata yoksa:
      Kiralama geçmişi  : o müşterinin son kaydı bulunur
      Hesap             : başlangıç zamanı + o anki zaman --> süre, ücret
      Kiralama geçmişi  : teslim tarihi, süre, ücret yazılır
      Scooter kayıtları : müsaitlik "kirada" --> "uygun"
```

Üçüncü örnek olarak **kiralama geçmişini görüntüleme** gösterildi: Operatör scooter numarasını girer. Böyle bir scooter varsa geçmiş deposundaki bütün kayıtları listelenir.

Görüldüğü gibi aynı kiralama kaydı iki süreçte doluyor: Başlangıç bilgileri kiralamada, teslim tarihi, süre ve ücret teslimde yazılıyor. Olmayan bir scooter ya da müşteri üzerinden işlem yapılamayacağı için doğrulama adımı diyagramda ayrıca yer alıyor.

### 3.5 Tasarım

Yapı diyagramında önce giriş ekranı geliyor. Kullanıcı adı ve şifre aşağı, onay bilgisi ile gidilecek ekran tipi yukarı akıyor. Buna göre yönetici ya da operatör ekranına geçiliyor. Scooter envanteri görüntüleme ve müşteri listeleme iki ekranda ortak.

ER diyagramında varlıklar müşteri, personel, scooter ve bakımdır. İlişkiler arasında "müşteri scooter'ı kiralar", "personel müşteriyi oluşturur", "personel scooter'ı oluşturur" sayıldı. Scooter varlığının nitelikleri marka, model, kayıt tarihi, müsaitlik durumu, scooter numarası ve scooter ID'dir. Birincil anahtar scooter ID'dir.

### 3.6 Çalışan Sistem

Giriş sonrası role göre farklı ekran açılıyor. Yönetici ekranında bütün modüller var. Personel kaydında kullanıcı türü seçiliyor. Müşteri kaydı telefon ve e-posta istiyor, kayıt sonradan düzenlenebiliyor. Scooter kaydında marka ve model giriliyor, envanter kodu veri tabanında otomatik üretiliyor. Scooter'ın durumu **uygun**, **kirada** ya da **bakımda** olabilir.

Kiralama ekranında yalnız kiraya verilmeye uygun scooter'lar listeleniyor. Bakıma gönderilen scooter için gönderilme tarihi, dönüş tarihi ve güncel durum bakım geçmişinde görülüyor.

Ücret dakika üzerinden hesaplanıyor. Gösterimde birim fiyat dakikada 5 liraydı. Kiralama bir dakikayı doldurmadığı için tutar sıfır göründü.

**Fiyat güncelleme kararı** ayrıca gösterildi. Sistem var olan fiyatın düzenlenmesine izin vermiyor. Yeni fiyat, listeye yeni bir satır olarak ekleniyor. Gerekçe sunumda söylenmedi.

> **Ders sonrası not:** Bu kararın yararı büyük olasılıkla geçmiş kiralamaların o tarihteki fiyatla doğru kalmasıdır. Var olan fiyat değiştirilseydi eski kayıtlardan hesaplanan tutarlar da bozulabilirdi. Bu gerekçe kısa notta da yer alıyor, ama altyazıda söylenmiyor.

## 4. Online Bankacılık Sistemi

### 4.1 Senaryo ve Gelir Modeli Sorusu

Bir grup, bankacılık sektörüne girmek isteyen bir yatırımcı senaryosu kurdu. Banka tamamen çevrim içi hizmet verecekti. Sistemin kaba özellikleri şunlardı:

- Para transferinde komisyon alınmayacak.
- Kredi verilmeyecek.
- Döviz ve altında alış-satış makası başlangıçta sıfır olacak, sonra açılacak.
- Elektrik, su ve doğal gaz faturaları ödenebilecek.

Hoca bu noktada sunumu durdurdu ve şunu sordu.

**Soru:** Bu adam nereden para kazanacak? Kredi vermiyor, komisyon almıyor. (hoca) **Cevap:** Grup önce sisteme para çekmeyi, müşteri kazandıktan sonra güncellemelerle gelir elde etmeyi düşündüğünü söyledi. Hoca, "sirkülasyonla mı para kazanacak?" diye sordu ve "Çamaşır makinesinde mi döndürüyorsunuz?" diye takıldı. Grup, ilk başta avantaj sunup müşteriyi başka bankalardan çekmeyi amaçladıklarını açıkladı.

Grup, yönetim fizibilitesinde aynı konuya döndü: Başlangıçta kâr amacı güdülmüyor, zamanla kredi oranları ve döviz makası açılarak gelir sağlanacak.

> **Hocanın vurgusu:** Hoca gelir kaynağı görünmeyen senaryoyu sorguladı. Ekonomik fizibilitede sistemin nereden para kazanacağı açık olmalıdır.

> **Ders sonrası not:** Senaryoda kredi verilmeyeceği söylendi, yönetim fizibilitesinde ise kredi oranları gelir kaynağı olarak anıldı. İki ifade birlikte okununca kredinin büyük olasılıkla sonraki güncellemelere bırakıldığı anlaşılıyor, ama sunumda bu açıkça söylenmedi.

### 4.2 Teknik, Zaman ve Sosyal Fizibilite

Kapsam tanımında hız, güvenlik ve kalite vurgulandı, çünkü sistem para ve çok sayıda kişisel bilgi taşıyor. Maliyet ve zamanda öngörülen sınırın aşılmaması hedeflendi.

Teknik fizibilite yazılım, donanım ve iletişim olarak üç başlıkta incelendi. Yazılımda **fonksiyonel yaklaşım** seçildi, kodlama Java ile NetBeans ortamında yapıldı. Seçim, yazılımcıların geçmiş tecrübesine dayanıyordu. İletişim fizibilitesi Java ile MySQL arasındaki iletişimi sağlayan API'larla sınırlıydı.

> **Ek bilgi (derste anlatılmadı):** Çözümleme yaklaşımı ile programlama dili aynı şey değildir. Java nesne yönelimli bir dildir, ama bir ekip analizde fonksiyonel yaklaşımı seçip veri akış ve yapı diyagramlarıyla çalışabilir. Bu grubun kullandığı diyagramlar da fonksiyonel yaklaşımla tutarlıdır. Kütüphane projesinde ise nesneye dayalı yaklaşım sınıf diyagramıyla birlikte kullanıldı.

Zaman fizibilitesinde iş parçacıklarına süre atanarak Gantt diyagramı çıkarıldı. Yazılım geliştirme modeli olarak "waterfall ve waterfall iteratif" denildi. Gerekçe olarak her aşama başarıyla tamamlanmadan diğerine geçilmemesinin kontrolü kolaylaştırdığı söylendi.

> **Ek bilgi (derste anlatılmadı):** Klasik şelale modelinde bir aşama tamamlanmadan sonrakine geçilmez ve geri dönüş öngörülmez. Yinelemeli (iteratif) şelalede ise önceki aşamalara geri dönülebilir. Bu ikisi aynı anda seçilmiş gibi söylenince projenin geri dönüşe izin verip vermediği belirsiz kalır, bu yüzden hangisinin kullanıldığı açıkça yazılmalıdır.

Sosyal fizibilite için iki seçenekli bir anket yapıldı: Sistem sade ve kullanımı kolay mı olsun, karmaşık ve çok işlevli mi? Çoğunluk sade ve kolay seçeneğini tercih etti, bu sonuç tasarımda dikkate alındı.

### 4.3 Yasal ve Ekonomik Fizibilite

Yasal fizibilitede üç başlık vardı:

- **KVKK:** Müşteriden çok sayıda kişisel bilgi alındığı için yükümlülük doğuyor. Müşteri kayıt olurken aydınlatma metni ve KVKK metni gösteriliyor. Gösterimde bu metin onaylanmadan kaydın tamamlanmadığı görüldü.
- **Sınai mülkiyet:** Tasarımın daha önce tescil edilmiş sistemlerden farklı olması gözetildi.
- **Sektör mevzuatı:** Bankacılığa girildiği için BDDK ve SPK mevzuatına uyulması gerekiyor.

> **Ders sonrası not:** Altyazıdaki "Sınav-i Mülkiyet Kanunu" büyük olasılıkla Sınai Mülkiyet Kanunu'dur.

Ekonomik fizibilitede personel, donanım ve yazılım giderleri sayıldı. Toplam yaklaşık 529 bin TL, projeye ayrılan bütçe yaklaşık 1 milyon TL olarak verildi, yani bütçe aşılmıyor.

**Soru:** Kaba taslak diyorsun, kuruşuna kadar yazmışsın. (hoca) **Cevap:** Öğrenci, bilgisayarın tükettiği elektriği de hesaba kattığını söyledi.

> **Hocanın vurgusu:** Hoca, "kaba taslak" diye sunulan bir tahminin kuruşuna kadar yazılmasına dikkat çekti. Yaklaşık bir değer yaklaşık olarak verilmelidir.

<!-- BELİRSİZ: Hocanın okuduğu tutar altyazıda "529.75 lira" diye geçiyor (00:42:49). Tam sayı ve gider kalemleri slaytta kalmış. -->

Fizibilite matrisi ise bu çalışmaların özeti olarak sunuldu. Müşteri için ekonomik ve teknik özellikler öne çıktığından birinci sistem önerisi kabul edildi. Java, güvenli ve platform bağımsız olması ve yazılımcıların tecrübesi nedeniyle tercih edildi.

### 4.4 Ekip ve Toplantılar

Ekip üç bölümden oluşuyordu: yazılım, sistem analizi ve teknik destek. Altı toplantı anlatıldı: Birincisinde müşteri talepleri alındı, ikincisinde fizibilite müşteriyle değerlendirildi, üçüncüsünde gerçekleştirme raporları incelendi, dördüncüsünde yazılım sürecinin yol haritası ve tasarım konuşuldu, beşincisinde ön yüz, arka yüz ve veri tabanı tasarımı tartışıldı, sonuncusunda proje teslim edilip görüş alındı. Test aşamasına geçiş kararı da bu toplantılarda alındı.

### 4.5 Veri Akış Diyagramları

Taslak diyagramda müşteri ve döviz kurları dış varlıklardan sisteme kişisel bilgiler ve kur bilgileri geliyor. Sistemden hesap ve admin varlıklarına döviz kuru, altın oranı, bakiye, hesap listesi ve müşteri listesi çıkıyor.

1\. düzeyde akış şöyle kuruluyor: Müşteri kişisel bilgilerini girerek kaydolur, adminden onay alır, TC bilgisi ve şifresiyle girip hesaplarını görüntüler. Bunun yanında ödemeler (doğal gaz, su, elektrik), hesap bilgilerini düzenleme ve para transferi süreçleri vardır. Para transferinde alıcı IBAN iki kaynaktan gelir: kayıtlı alıcılar ve hesaplar listesi.

2\. düzeyde para transferi açıldı:

```text
Gönderici hesap bilgisi + miktar + alıcı IBAN
   |
   v
Bakiye kontrolü: yeterli para var mı?
   |
   v
Gönderici hesaptan miktar düşülür
   |
   v
Alıcı hesaba aynı miktar eklenir
   |
   v
Hesaplar listesi deposu güncellenir
```

### 4.6 Veri Sözlüğü

Bu sunum veri sözlüğü girdisinin üç türünü de örnekledi:

| Tür | Örnek | İçerik |
|---|---|---|
| Veri akışı | Kişisel bilgiler | İsim, soy isim, TC, cinsiyet, telefon numarası, doğum tarihi. Müşteriden müşteri kaydı sürecine bileşik olarak iletilir. |
| Veri deposu | Hesaplar listesi | Hesap türü, IBAN, bakiye. Günde ortalama 20 giriş olur. |
| Veri yapısı | Para transferi | Gönderici hesap bilgileri, miktar, alıcı IBAN, güncel gönderici ve alıcı hesap bilgileri. |

Veri sözlüğünün işlevi de sunumda şöyle ifade edildi: Veri akış diyagramlarındaki bilgileri daha ayrıntılı açıklamak.

### 4.7 ER ve Yapı Diyagramı

ER diyagramında dört varlık vardı: banka hesabı, müşteri, kayıtlı hesaplar ve admin. Banka hesabının üç niteliği hesap türü, hesap bakiyesi ve IBAN'dır, IBAN anahtar niteliktir. Bir müşteri birden çok banka hesabına ve birden çok kayıtlı hesaba sahip olabilir. Admin müşteri bilgilerine erişebilir.

Yapı diyagramı iki ana panelle başlıyor: kayıt ol ve giriş yap. Girişten sonra üç süreç var: para transferi, ödemeler, hesap bilgilerini görüntüleme. Hesap görüntülemeden yatırım hesabı ya da TL hesabı açılabiliyor. Yatırım hesabı açılırken döviz bilgileri eş zamanlı alınıyor.

### 4.8 Çalışan Sistem

Gösterimde şu iş kuralları görüldü:

- **Admin onayı:** Yeni müşteri kaydı admin panelinde onay bekliyor. Onay verilmeden müşteri giriş yapamıyor.
- **Hesap silme kuralı:** Bakiyesi olan hesap silinemiyor, sistem önce parayı boşaltmayı istiyor. Boş hesap siliniyor.
- **IBAN doğrulama:** Para göndermeden önce IBAN doğrulanıyor. Geçersiz IBAN'da uyarı veriliyor ve para gönderilmiyor.
- **Yatırım işlemleri:** Dövizden TL'ye ve TL'den dövize çevrim yapılabiliyor.
- **Fatura ödeme:** Kimlik numarasıyla borç sorgulanıyor. Yetersiz bakiyeli hesapta uyarı veriliyor. Yeterli hesaptan 60 liralık gaz borcu ödenince borç 0 TL'ye iniyor.

## 5. Kütüphane Masa ve Mola Takip Sistemi

### 5.1 Problem ve Fizibilite

Bir grup, kütüphanedeki masa kıtlığı, masaların disiplinsiz kullanımı ve mola sürelerine uyulmaması sorunlarından yola çıktı. Ekipte proje yöneticisi, analist ve yazılım-tasarım rolleri vardı, üyeler aynı zamanda yazılımda da çalıştı.

**Teknik fizibilitede** Java ile nesneye dayalı yaklaşım, arayüz için JavaFX, veri tabanı için MongoDB Atlas seçildi.

**Ekonomik fizibilitede** yazılım araçları ücretsizdi, MongoDB Atlas için aylık ücret ödeniyordu. İki bilgisayar tanesi 2750 dolardan ve yazılım için 11 000 dolar sayıldı. Açıklanan toplam 17 234 dolardı.

- Bilgisayarlar: $2 \times 2750 = 5500$
- Bilgisayar ve yazılım: $5500 + 11\,000 = 16\,500$
- Açıklanan toplamla fark: $17\,234 - 16\,500 = 734$

> **Ders sonrası not:** 734 dolarlık farkın MongoDB Atlas'ın yıllık ücreti olması beklenir, ama altyazıdaki rakamlar bunu doğrulamıyor. Altyazıda ücret "aylık 12 dolar, 57 dolardan, 12'den" diye geçiyor. $57 \times 12 = 684$ ve $12{,}57 \times 12 = 150{,}84$ eder, ikisi de 734'e eşit değildir. 734 dolar için aylık ücretin $734 / 12 \approx 61{,}17$ dolar olması gerekirdi. Kesin kırılım raporun tablosunda aranmalıdır.

**Zaman fizibilitesinde** Gantt diyagramı üç alana ayrıldı: araştırma ve fizibilite, tasarım ve geliştirme, test ve sunum.

**Sosyal fizibilitede** ankete göre memnuniyetsizliğin nedenleri disiplinsiz masa kullanımı ve düzenin sağlanamamasıydı. **Yasal fizibilitede** kişisel bilgilerin KVKK gereği korunacağı, üçüncü kişilerle paylaşılmayacağı, üyelikte bu metnin kabul edileceği belirtildi. **Yönetim fizibilitesinde** sistem kütüphane yönetiminin isteğiyle geliştirildiği için sorun görülmedi.

**Fizibilite matrisinde** iki sistem karşılaştırıldı, ikinci sistem seçildi. Sosyal, yasal ve yönetimsel açıdan iki sistem arasında fark yoktu. Belirleyici olan ekonomik fizibilite ile ekibin Java'ya hâkim olması ve bir üyenin MongoDB Atlas tecrübesiydi.

<!-- BELİRSİZ: 01:00:48'de "aynı zamanda fizibilitesi de önemliydi" denen başlığın adı duyulmuyor; devamından teknik fizibilite olduğu anlaşılıyor. -->

### 5.2 Gereksinim Analizi ve Toplantılar

Gereksinim analizinin temeli kütüphane kullanıcılarına yapılan anketti. En büyük sorun olarak 56 kişiyle "boş masa bulmak için bütün kütüphaneyi dolaşmak" çıktı. Kütüphanede sıra beklemek de ayrı bir sorundu. Katılımcıların büyük çoğunluğu uygulamanın faydalı olacağını düşünüyordu.

Toplantılar, gereksinimlerin zaman içinde nasıl şekillendiğini gösteriyor:

- **4 Nisan 2023:** Müşteri konumundaki kütüphane müdürü, kullanıcı memnuniyetine göre tasarlanmış bir sistem istedi. Anket yapılmasına ve sonuçlarının en önemli öncelik sayılmasına karar verildi.
- **7 Nisan:** Anket ve fizibilite sonuçlarına dayanan iki sistem örneği sunuldu. Mola düzenleme ve takibinin önemli olduğu, boş masanın görsel olarak gösterilmesi gerektiği, kullanıcılara sıra numarası bildirilip boş masaların atanması gerektiği belirlendi.
- **18 Nisan:** Arka plan geliştirmenin ek gereksinim doğuracağı görüldü. Ön yüzü en az etkilemek için arka plan hızlandırıldı, ön yüzün ek gereksinimleri için üç gün ayrıldı.
- **Son toplantı:** Sistem müdüre sunuldu. Müşteri istenen işlevleri onayladı, sistemin biraz yavaş olduğunu söyleyip iyileştirme istedi.

### 5.3 Kullanım Senaryoları

Kullanım senaryosu diyagramında iki aktör vardı: kütüphaneye gelen kullanıcı ve kütüphane görevlisi. İkisi de doluluk oranını izleyebiliyor. Kullanıcı ayrıca sisteme giriş, mola alma, rezervasyon ve çıkış senaryolarını gerçekleştiriyor. Sisteme giriş doğrulama gerektiriyor. Mola alma sonucunda atılma olabildiği için atılma, mola almayı genişleten (extend) bir senaryo olarak çizildi. Atılma durumunda masanın boşaltılması zorunlu.

<!-- BELİRSİZ: 01:04:49'daki "kullanılacak payet işlemi" bozuk geçiyor; bağlamdan üyelik işlemi olabilir. -->

Senaryolar ön koşul, son koşul ve alternatif akışla birlikte anlatıldı:

| Senaryo | Ön koşul | Ana akış | Alternatif akış | Son koşul |
|---|---|---|---|---|
| Rezervasyon | Üye olmak, kütüphaneden atılmamış olmak | Oda ve masa seçilir, kullanıcı yerleşir | Yer yoksa sıra numarası verilir, sırası gelince boşalan masaya oturur | Seçilen masaya yerleşilmiş olması |
| Mola alma | Üye olmak, sistemde bulunmak | Mola başlatılır, bitince "molayı bitir" denir, aradaki süreye göre kredi hesaplanır | Hakkı kalmayan kişi kütüphaneden atılır | Zamanlayıcının çalışmasını tamamlaması |
| Çıkış | Üye olmak, atanmış bir masada oturmak | Kullanıcı çıkış yapar, masayı boşaltır | Sırada biri varsa masa doğrudan ona atanır | İşlemin tamamlanması, masanın rezervasyona açılması |

Her kullanıcıya bir kredi tanımlandı. Grup böylece molanın ne kadar ve ne sıklıkla aşıldığını izleyebildiğini, kredisi biten kullanıcıya uygulanacak yaptırımı da sisteme bağlayabildiğini söyledi.

### 5.4 Analiz ve Tasarım Diyagramları

Sunumda varlıklar arası bir diyagramda kullanıcı, kütüphane ve oda ana kavramlar olarak belirlendi. Kullanıcı ile kütüphane arasında rezervasyon ve mola alma, oda ile kütüphane arasında raporlama, oda ile kullanıcı arasında yerleşme ve çıkış ilişkileri vardı.

<!-- BELİRSİZ: 01:07:47'deki diyagramın adı söylenmiyor. Kavramsal sınıf ya da ER diyagramı olabilir. -->

Yapı diyagramında modüller arasında akan bilgiler şöyle anlatıldı:

- Üyelikte üyelik bilgileri gönderilir, onay döner.
- Raporlamada doluluk oranı gönderilir.
- Girişte kullanıcı bilgileri gönderilir, doğrulama döner.
- Rezervasyon ikiye ayrılır. Boş masa varsa masa ve oda bilgisi, yoksa bekleme sırası ve süre bilgisi kullanılır. Her iki dal da sonunda masa yerleştirmeye oda ve masa bilgisini gönderir.
- Mola almada mola ve zaman bilgileri gider, kredi ve mola hakkı bilgisi döner. Bu bilgiye göre çıkış ya da atılma durumu oluşur.

Nesneye dayalı yaklaşım kullanıldığı için bir de sınıf diyagramı vardı. Dört temel sınıf üye, kütüphane, sıra ve odadır. Ardından bütün senaryoları tek şemada toplayan bir ardışıl diyagram gösterildi: üye olma, giriş ve doğrulama mesajı, rezervasyon (iki dal), mola başlatma ve bitirme ile kalan mola sayısının dönmesi, kredinin bitmesi hâlinde masanın boşaltılması ve atılma bilgisi, normal çıkış.

<!-- BELİRSİZ: Altyazıda "yönel diagramı" (01:09:22) ve "ayrı şıl diagramı" (01:09:42) diye geçen adlar bağlamdan sınıf ve ardışıl diyagram olarak yorumlandı. Diyagramların kendisi slaytta. -->

### 5.5 Gerçekleştirme Kararları

Grup MongoDB Atlas'ı üç gerekçeyle seçti:

- **Altyapı:** Bulut tabanlı olduğu için donanım ve altyapı endişesi kalmıyor, veri tabanı kolayca taşınıyor.
- **Yedekleme:** Otomatik ve düzenli yedekleme sunuyor.
- **Güvenlik:** Veriler şifreli tutuluyor, kimin erişeceği belirlenebiliyor.

Dil seçiminde C ile Java arasında kalındı, sistemin nesneye yönelik olması gerektiği düşünülerek Java seçildi. Arayüz için bir üyenin daha önce denediği JavaFX kullanıldı.

<!-- BELİRSİZ: 01:11:37'de "C ve Java" geçiyor, C ya da C# olduğu belli değil. -->

### 5.6 Çalışan Sistem

Gösterim bir doluluk senaryosu üzerinden yapıldı, bu yüzden iki öğrenci sırayla çalıştırdı. Doluluk oranı adım adım izlendi:

- Başlangıç: %96 dolu. Boş masa olduğu için kullanıcı oda ve masa seçebiliyor.
- İlk kullanıcı oturunca: %98.
- Son boş masaya ikinci hesap oturunca: %100.

Doluluk %100 olunca masa seçimi yerine yeni bir "sıraya gir" düğmesi çıkıyor. Bu düğme %100'e ulaşmadan görünmüyor, masada oturan kullanıcıya da görünmüyor. Üçüncü hesap sıraya girince sıra numarası veriliyor ve bekleyen kişi sayısı artıyor. Masada oturan kullanıcı kalktığında bekleyen sayısı bir düşüyor, boşalan masa sistem tarafından sıradaki kullanıcıya otomatik atanıyor. Doluluk yine %100 kalıyor. Sıradaki kullanıcı girdiğinde kendini az önce boşalan masada görüyor.

Mola kısmında kullanıcı 15 dakikalık mola başlatıyor. Moladayken yeniden mola almaya çalışınca sistem "hâlâ moladasınız" uyarısı veriyor. Kalan mola hakkı 3'ten 2'ye düşüyor. Hak bitince yeni mola isteği reddediliyor. Veri tabanı tarafında oda bilgileri ve odalardaki masalar koleksiyonlar hâlinde tutuluyor.

## 6. Süpermarket Bilgi Sistemi

### 6.1 Problem, Gereksinimler ve Riskler

Bir grup, süpermarketlerin rekabet için dijitalleşmeye yöneldiği gerekçesinden yola çıktı. Sistem kullanıcı işlemleri, stok ve ürün işlemleri, alışveriş modülü, kampanya uygulama ve ürün yönetimini kapsıyordu. Gerçekleştirme için bilgisayar, yazılım altyapısı, güvenilir ağ, veri tabanı, kullanıcı dostu arayüz ve yetkin teknik personel gerektiği söylendi.

<!-- BELİRSİZ: 01:24:06'da "NTG veritabını" bozuk geçiyor, veri tabanının niteliği anlaşılmıyor. -->

Müşteri istek formu, bir üyenin müşteri rolü yaptığı diyalog biçiminde hazırlandı. Toplantılar koordinasyon için yapıldı, genel taslak ve program seçimi erken toplantılarda belirlendi, üçüncü toplantıda sisteme müşteri gözüyle bakılarak ne eklenebileceği soruldu.

Teknik fizibilite özetle bir bilgisayar ve kararlı bir internet bağlantısına indirgendi. Ekonomik fizibilitedeki değerlerin gerçek değil tahmini olduğu özellikle belirtildi. Hesaba göre geri ödeme süresi 2 yıl çıktı. Zaman fizibilitesinde Gantt şeması kullanıldı. Sosyal ve yasal fizibilite, grubun çoğu sistemde benzer olduğunu söylemesiyle sunumda geçildi.

Riskler ve yönetimleri:

- **Güvenlik riskleri:** Veri sızıntısı ve kimlik avı. Çözüm olarak güvenli yazılım ve güvenilir şirketlerle çalışmak söylendi, çözümün göründüğü kadar basit olmadığı eklendi.
- **Veri kaybı:** Sistem ve donanım arızaları iş sürekliliğini etkiler. Çözüm düzenli veri yedeklemedir.
- **Doğal afetler:** Sunucuda çıkan bir yangın bile birçok şeyi sekteye uğratabilir.

<!-- BELİRSİZ: 01:26:18 çevresinde "kimlik ağ" diye geçen ifade "kimlik avı" olarak okundu. -->

### 6.2 Veri Akış Diyagramları

Taslak diyagramda iki aktör vardı: kullanıcı ve admin. Kullanıcı adı ve şifresiyle giriyor, ürün adıyla arama yapıyor. Sistem ona şube, stok ve sepet bilgisini döndürüyor. Admin ürünlere yeni bilgi giriyor. Sistem ona şube, stok, ürün ve çalışan bilgisini döndürüyor.

1\. düzeyde kullanıcı üye olur, bilgileri kullanıcılar tablosunda saklanır, giriş yapar, alışveriş yapacağı şubeyi seçer. Alışveriş süreci ürünler tablosundan okur ve sepet bilgisini kullanır. Admin çalışanların izin günleri ve maaş bilgilerini görür ve değiştirir, ürün bilgilerini günceller, şube bilgilerini yönetir ve kampanya uygular. Kampanya bir tarih aralığı ile yüzdelik indirim oranı girilerek tanımlanır. Ürünün fiyatı bu aralıkta o oranda düşer.

2\. düzey diyagram büyük olduğu için yalnız kullanıcı tarafı anlatıldı:

```text
İsim, şifre --> Kayıt --> Üye bilgileri güncellenir
İsim, şifre --> Giriş --> Onay --> Şube seçimi --> Ürün seçimi
            --> Sepete ekleme --> Ödeme --> Stok güncelleme
```

### 6.3 Yapı ve ER Diyagramı

Yapı diyagramında dört ana yapı vardı: sepet işlemleri, alışveriş işlemleri, kullanıcı işlemleri ve düzenleme işlemleri. Örnek olarak sepet işlemleri açıldı: Bilgi sisteminden kullanıcı, ürün, ürün stok, istek ve sepet bilgileri bu modüle gönderiliyor. Ürün varsa stok bilgisinden kontrol edilip sepete yükleniyor, güncel sepet ile yeni stok bilgisi bilgi sistemine geri dönüyor.

ER diyagramında ürünün ID, isim ve fiyat nitelikleri, kullanıcının ID, kullanıcı adı, şifre ve rol nitelikleri sayıldı. Rol, kullanıcının admin mi normal kullanıcı mı olduğunu belirliyor. Ürün ile stok, sepet ile ürün ilişkileri ve çalışanların mesai ve izin bilgileri de gösterildi.

**Soru:** Siz bir iş ayrımı yapmadınız mı? "Galiba" ile mi oluyor bu işler? (hoca) Bu soru, bir öğrencinin sıradaki bölümü kimin anlatacağını "galiba" diyerek söylemesi üzerine geldi. **Cevap:** Grup, zaman kısıtı nedeniyle o bölümü atlayıp doğrudan uygulamaya geçmeyi tercih etti.

### 6.4 Çalışan Sistem

Uygulama Node.js ve PostgreSQL ile yazıldı. İlk ekranda ürünler isim, stok ve fiyatla listeleniyor. Her şubenin kendi ürünleri ve stok miktarları var. Bir işlem yapmak isteyen kullanıcı giriş ekranına yönlendiriliyor.

> **Ders sonrası not:** Sunumda arayüz için de Node.js kullanıldığı söylendi. Node.js bir JavaScript çalışma ortamıdır. Burada kastedilen büyük olasılıkla arayüzün Node.js üzerinde çalışan uygulama tarafından sunulmasıdır.

Sepete ürün eklenince stok miktarı hemen düşüyor, sepetten çıkarılınca geri ekleniyor. Satın alma modülü kapsam dışı bırakıldı, bu yüzden 2. düzey akıştaki ödeme adımı gösterimde yer almadı. Admin paneli tabloları doğrudan yönetiyor: şube, ürün, çalışan, stok, tedarik, vardiya, izin ve indirim. Yeni tedarik oluşturulunca stok miktarı güncelleniyor.

İndirim örneği:

- Verilen: Ürün fiyatı 111, indirim oranı %10, tarih aralığı bulunulan günü kapsıyor
- İşlem: $111 \times (1 - 0{,}10) = 99{,}9$
- Ekranda görülen: 100

> **Ders sonrası not:** Hesabın tam sonucu 99,90'dır. Ekranda 100 görünmesinin nedeni büyük olasılıkla fiyatın yuvarlanmasıdır. Fiyatın yuvarlama öncesi değeri altyazıda duyulmuyor.

## 7. Beş Projenin Karşılaştırılması

Aşağıdaki tablo, sunumlarda söylenen değerleri yan yana getirir. Süre ve benzeri değerler söylenmediyse "belirtilmedi" yazılmıştır.

| Proje | Teknoloji | Ekonomik sonuç | Zaman ve model | Seçimin gerekçesi |
|---|---|---|---|---|
| Online market | Swift, React, Firebase | 97 200 TL maliyet, 198 bin TL NBD, %74 İVO, %20 iskonto | 40 gün, şelale | Ekip tecrübesi ve zaman |
| Scooter kiralama | C#, Microsoft SQL Server | 7000-7500 dolar | 9 hafta | C# ve SQL yatkınlığı, süre kısalması |
| Online bankacılık | Java, NetBeans, MySQL | Yaklaşık 529 bin TL maliyet, yaklaşık 1 milyon TL bütçe | Süre belirtilmedi, şelale | Müşteri için ekonomik ve teknik özellikler, yazılımcı tecrübesi |
| Kütüphane | Java, JavaFX, MongoDB Atlas | 17 234 dolar | Gantt ile üç alan, model belirtilmedi | Ekonomik fizibilite, Java ve MongoDB Atlas bilgisi |
| Süpermarket | Node.js, PostgreSQL | Tahmini değerler, 2 yıl geri ödeme | Gantt, model belirtilmedi | Belirtilmedi |

Tabloda iki ortak nokta görülüyor. Birincisi, gerekçesi anlatılan dört projenin hepsinde ekibin bildiği teknoloji seçimde söz sahibi oldu. İkincisi, çözümleme yaklaşımı diyagram seçimini belirledi: Market, scooter, bankacılık ve süpermarket projeleri veri akış diyagramı, yapı diyagramı ve ER diyagramıyla çalıştı. Nesneye dayalı yaklaşımı seçen kütüphane projesi sınıf diyagramı ve ardışıl diyagramı kullandı, yapı diyagramını da korudu.

## 8. Hocanın Geri Bildirimleri ve Çıkan Dersler

### 8.1 Hocanın Sunumlarda Sorduğu Sorular

Hoca sunumların içeriğine birkaç kez doğrudan müdahale etti:

- **Gelir modeli:** Kredi vermeyen, komisyon almayan banka nereden para kazanacak? Ayrıntısı Bölüm 4.1'dedir.
- **Tahminin hassasiyeti:** Kaba taslak denen tutar neden kuruşuna kadar yazılmış? Ayrıntısı Bölüm 4.3'tedir.
- **İş bölümü:** Bir sonraki bölümü kimin anlatacağı neden "galiba" ile söyleniyor? Ayrıntısı Bölüm 6.3'tedir.
- **Hedef kitle:** Uygulama neden İngilizce? Ayrıntısı Bölüm 2.8'dedir.
- **Çalıştırılabilirlik:** Hoca bir teslimde çalıştırılabilir dosyanın açılırken exception alıp kapandığını söyledi ve bunun fark edilip edilmediğini sordu.

### 8.2 Bu Notta İşaretlenen Noktalar

Aşağıdakileri hoca sunumda tek tek düzeltmedi. Bunlar, sunumlarda geçen ifadelerin yukarıdaki ek bilgi ve ders sonrası notlarda işaretlenen hâlidir. Kendi raporunuzu yazarken kontrol listesi olarak kullanılabilirler.

- İVO, NBD ve geri ödeme süresi aynı nakit akışından çıkar, birlikte tutarlı olmalıdır (Bölüm 2.3).
- Maliyet kalemlerinin toplamı, açıklanan toplama eşit olmalıdır (Bölüm 5.1).
- Yazılım geliştirme modeli tek ve açık yazılmalıdır, klasik şelale ile yinelemeli şelale aynı şey değildir (Bölüm 4.2).
- Çözümleme yaklaşımı ile programlama dili ayrı kararlardır (Bölüm 4.2).
- Yerel veri tabanı kullanmak KVKK yükümlülüğünü kaldırmaz (Bölüm 3.2).
- Senaryoda söylenen kural ile fizibilitede söylenen gelir kaynağı çelişmemelidir (Bölüm 4.1).

## Dersin Toparlaması

Bu derste beş proje üzerinden dönem boyunca görülen adımların uygulaması izlendi: Fizibilite çalışmaları ve matrisle sistem seçimi, anket ve görüşmeyle gereksinim toplama, kullanım senaryoları, veri akış diyagramları, veri sözlüğü ve süreç formları, yapı, ER ve sınıf diyagramları, son olarak da bunların çalışan bir sistemde karşılığı. Örneklerde en net görülen bağ, analizde çizilen kontrol adımlarının gösterimde uyarı ve iş kuralı olarak ortaya çıkmasıdır: Yetersiz bakiye, olmayan scooter, geçersiz IBAN ve dolu kütüphanede sıra düğmesi bunun örnekleridir.

> **Hocanın vurgusu:** Bu dersin amacı yalnız kod geliştirmek değildir. Problem en baştan ele alınır, anlaşılır, anlaşılan biçimsel olarak ifade edilir, buna uygun bir çözüm önerisi geliştirilir ve gerçekleştirme aşaması bu öneriyi taşıyacak şekilde yapılır. Hoca, sürecin bu şekilde nasıl yürüdüğünü göstermeye çalıştıklarını söyleyerek sözünü bağladı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
