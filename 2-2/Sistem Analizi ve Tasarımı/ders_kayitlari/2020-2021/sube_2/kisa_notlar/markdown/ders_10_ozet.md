# Ders 10 Çalışma Özeti

## Genel Konular

- GRASP: genel sorumluluk atama prensipleri (ekrandan, 00:05:00)
  - GRASP (General Responsibility Assignment Software Patterns), genel prensipler ve akla yatkın çözümlerin birleştirilmesiyle oluşturulan bir repertuardır. Her kalıba probleme getirdiği çözümü anlatan kolay bir isim verilir; bu da ekip içi iletişimi kolaylaştırır.
  - GoF kalıpları 23 adettir; bu derste 9 adet genel sorumluluk atama prensibi anlatıldı ve bunlara "Yabancılarla Konuşma" prensibi eklendi.
  - Temel soru: senaryolardaki bir sorumluluk (yapılması, bilinmesi, bulunması gereken bir iş) hangi sınıftan türeyen nesneye atanmalı?
- 1. Uzman (Information Expert) (ekrandan, 00:10:00)
  - Sorumluluk, o işi yerine getirmek için gereken bilgiye sahip olan sınıfa atanır.
  - Önce tasarımdaki yazılım sınıflarına, yoksa analiz modelindeki kavramsal sınıflara bakılır; en uygun kavramsal sınıf yazılım sınıfı olarak tasarım modeline taşınır. Böylece gerçek dünya modeli ile yazılım arasındaki fark (temsil farkı) düşük kalır.
  - Örnek: satışın toplam tutarı. `getTotal()` Sale'e, `getSubtotal()` SalesLineItem'a, `getPrice()` ProductDescription'a atanır.
- 2. Yaratıcı (Creator)
  - B, A nesnelerini içeriyorsa, kaydını tutuyorsa, yakından kullanıyorsa ya da A'yı yaratmak için gereken başlangıç verilerine sahipse A'yı B yaratmalıdır.
  - Örnek: SalesLineItem nesnelerini Register değil, onları içeren Sale yaratır.
- 3. Az Bağımlılık (Low Coupling) (ekrandan, 00:20:00)
  - Sorumluluklar sınıflar arası bağımlılık en az olacak şekilde atanır. Bağımlılık, bir sınıfın kendi işleri için başka sınıfları ne kadar kullandığı ve onlar hakkında ne kadar bilgi içerdiğidir.
  - Bağımlılık şu durumlarda oluşur: A'nın B cinsinden üyesi varsa, A B'nin metodunu çağırıyorsa, A'nın metodunda B tipinden parametre ya da değişken varsa, A doğrudan ya da dolaylı olarak B'den türetilmişse.
  - Örnek: `makePayment` Register'a gelir ama Register Payment yaratmaz; isteği Sale'e aktarır, Payment'ı Sale yaratır.
- 4. İyi Uyum (High Cohesion) (ekrandan, 00:25:00)
  - Sorumluluklar sınıf içinde birbiriyle ilgili ve aynı konuya yoğunlaşmış olacak şekilde atanır.
  - Uyumu kötü sınıfın anlaşılması, bakımı ve tekrar kullanılması zorlaşır; değişikliklerden çok etkilenir.
  - Veritabanı işlemlerini tek bir yere (tek programcıya) toplamak için ya da dağıtık sistemlerde ağ trafiğini azaltmak için iyi uyum bilinçli olarak bozulabilir.
- 5. Denetçi (Controller) (ekrandan, 00:30:00)
  - Sistem olaylarını (aktörlerin ürettiği olaylar: butona tıklama, barkod okutma) karşılayan yapay bir uzmandır. Ya bütün sistemi temsil eden bir görüntü denetçisi (facade controller) ya da her senaryo için bir senaryo/oturum denetçisi (use case/session controller) seçilir.
  - Denetçi işi kendisi yapmaz; basit denetimlerden sonra mesajı sorumlu nesneye aktarır. Arayüz katmanı ile uygulama katmanı birbirinden ayrılır ve işlemlerin sırası denetlenebilir.
- 6. Çok Şekillilik (Polymorphism)
  - Davranış sınıfa (tipe) göre değişiyorsa if/else ile seçmek yerine polimorfik metotlar kullanılır. Örnek: Visa, Mastercard, American Express ve Troy kartlarını doğrulamak tek bir sorumluluktur ama her biri farklı çalışır.
  - Dış sistemlerle konuşurken her dış sistemin önüne ortak bir arayüzü gerçekleyen bir adaptör sınıfı konur (vergi hesaplama adaptörleri gibi).
- 7. Yapay Sınıf (Pure Fabrication) (ekrandan, 00:40:00)
  - Uzman kalıbının çözümü iyi uyum ve az bağımlılıkla çelişiyorsa birbiriyle uyumlu sorumluluklar gerçekte var olmayan yapay bir sınıfa atanabilir (örneğin veritabanı işlemleri).
  - Gereğinden fazla kullanılırsa tasarım fiillerden oluşan sınıflara, yani işlevsel çözümlemeye kayar.
- 8. Dolaylılık-Arabirim (Indirection) (ekrandan, 00:45:00)
  - Kolay değişebilen iki birim arasındaki bağımlılığı azaltmak için sorumluluklar bir arabirim nesnesine atanır. Adapter, Facade ve Observer bu prensibin özel halleridir.
  - Benzetme: laptop adaptörü 220 V AC'yi 19 V DC'ye çevirir; 110 V'luk ülkede laptop değil adaptör değişir.
- 9. Değişimlerden Korunma (Protected Variations)
  - Kararsız, değişime açık noktaların etrafında kararlı bir arayüz oluşacak şekilde sorumluluk atanır. Kapsülleme, veri gizleme ve polimorfizm bu prensibe dayanır.
- Yabancılarla Konuşma (Don't Talk to Strangers) (ekrandan, 00:50:00)
  - Bir nesne yalnız tanıdıklarına mesaj göndermelidir: kendisi (this), metodun parametresi, kendi özelliği olan nesne, kendi üyesi olan bir koleksiyonun elemanı, metodun içinde yaratılan nesne.
  - `sale.getPayment().getTenderedAmount()` kötü, `sale.getTenderedAmountOfPayment()` iyi.
- Başlangıç işlemleri (ekrandan, 00:55:00)
  - Sistem ilk çalıştığında yapılacaklar ayrı bir senaryo olarak, tasarımın son aşamasında yazılır. Bir başlangıç nesnesi (initial domain object) diğer nesneleri yaratır ve bağlar.
  - Örnek: Store yaratılır, Store ProductCatalog'u, katalog ürün tanımlarını yaratır; sonra Store Register'ı yaratıp kataloğu ona verir.
- Görünürlük (visibility) (ekrandan, 01:00:00)
  - B, A'ya görünürse A B'ye mesaj gönderebilir. Özellik görünürlüğü (B, A'nın üyesi), parametre görünürlüğü (B, metodun parametresi), ayrıca yerel ve global değişkenle görünürlük.
  - Parametre görünürlüğü yalnız metot çalıştığı sürece bağımlılık yarattığı için tercih edilir; global değişkenlerden kaçınılır.
- Tasarım sınıf diyagramı (ekrandan, 01:05:00)
  - Yazılım sınıfları, özellikleri ve tipleri, metotları, parametreleri, erişim hakları ile yönlü ilişkileri (navigability) gösterir.
  - Tanıdığın tanıdığına erişim kesik çizgili bağımlılık ilişkisiyle gösterilir; bu çizgiler arttıkça tasarım kötüleşir.
- Veri tasarımı ve veritabanı tasarım aşamaları (ekrandan, 01:10:00)
  - Analiz (hangi verinin tutulacağı), kavramsal ve mantıksal tasarım (varlıklar, nitelikler, ilişkiler), normalizasyon (bu derste işlenmedi), gerçekleştirme (tablolar, kısıtlar, güvenlik ve haklar, ilk verilerin yüklenmesi, stored procedure).
- Veri modelleri (ekrandan, 01:15:00)
  - Varlık-ilişki (ER) modeli kavramsal tasarımda en çok kullanılan modeldir. Diğerleri: sıradüzensel (kayıt kütükleri), yarı yapılı (XML), nesneye dayalı (kavramsal nesneler; uygulamada yerini Object Relational Mapping aldı), yapılanmış bellek (NoSQL, MongoDB, AllegroGraph).
- Varlık-ilişki modeli (ekrandan, 01:25:00; 01:30:00)
  - Sembol: varlık dikdörtgen, nitelik elips, anahtar nitelik altı çizili, ilişki eşkenar dörtgen, bağlantılar çizgi, çoğullamalar çizgi üzerinde.
  - Varlık: var olan ve benzerlerinden ayırt edilebilen, hakkında veri tutulması gereken her şey. Tabloda her satır bir varlıktır, her sütun bir niteliktir.
  - Anahtar nitelik: değeri her varlık için farklı olan nitelik; genellikle sayısal, otomatik artan bir kod seçilir.
  - İlişkinin kendi niteliği olabilir (personel-departman "çalışan" ilişkisinde "'den beri" niteliği).
- İlişki tipleri ve tablolara dönüştürme (ekrandan, 01:35:00; 01:40:00; 01:45:00)
  - 1-1 (az kullanılır), 1-n (en yaygın), n-m (çoka çok).
  - 1-1'de anahtar taraflardan birine yabancı anahtar olarak konur. 1-n'de 1 tarafının birincil anahtarı n tarafındaki tabloya yabancı anahtar olarak eklenir.
  - n-m'de ilişki ayrı bir bağlantı tablosu olur; iki tarafın birincil anahtarları burada yabancı anahtardır. Bu ikisi yetmiyorsa yeni bir birincil anahtar (oynarID gibi) eklenir.
- Zayıf varlık kümeleri (ekrandan, 01:50:00)
  - Tüm nitelikleri alınsa bile anahtar oluşturamayan, varlığı başka bir varlığa bağlı olan küme (üniversiteye bağlı fakülte). Çift çizgili dikdörtgenle gösterilir; birincil anahtarı sahip varlığın anahtarıyla birlikte oluşturulur.

## Hocanın Özellikle Vurguladığı Kısımlar

- Uzman prensibi temel prensiptir
  - Sorumluluk bilginin sahibine verilir. Bir sorumluluğu yerine getirmek için uzmanlar birbirine sorarak iş birliği yapar (Sale, SalesLineItem'a; SalesLineItem, ProductDescription'a sorar).
- Denetçi işi yapmaz, yalnız yönlendirir
  - Bir ağ geçidi ya da dağıtıcı (hub) gibi çalışır. Denetçiyi arayüz nesnesine (Windows formu, web sayfası) koymak yeniden kullanılabilirliği azaltır; aynı uygulamaya yarın bir mobil ön yüz eklenmek istenebilir.
- Yapay sınıfları az kullanın
  - Çok kullanılırsa nesne mantığı C'deki fonksiyon mantığına döner; öncelik kavramsal sınıflardan türeyen yazılım sınıflarındadır.
- Değişim olabilecek her yerde araya bir tampon (adaptör/arabirim) koyun
  - Veritabanı MySQL'den PostgreSQL'e ya da bulut tabanlı bir NoSQL çözümüne geçse bile uygulamadaki bütün birimler elden geçirilmemelidir.
- Bağımlılık kesik çizgilerini azaltın
  - Bir sınıf değiştiğinde yalnız ona doğrudan bağlı sınıfları değil, kesik çizgiyle bağımlı olanları da kontrol etmek gerekir.
- Sorumluluk sayısı kadar etkileşim diyagramı
  - Her sorumluluk için bir etkileşim (ardışıl ya da işbirliği) diyagramı çizilir, hepsi tek bir tasarım sınıf diyagramında toplanır. Kodlama bu iki diyagramdan yapılır.
- Kodlamaya en az bağımlı sınıftan başlayın ve her sınıfa birim testi yapın
  - Test güdümlü geliştirmede test programları uygulamadan önce yazılır; bu yaklaşım yaklaşık iki, iki buçuk kat efor ister.
- Anahtar nitelik seçimi
  - Ad, baba adı, anne adı gibi nitelikleri birleştirmek benzersizliği garanti etmez; bu yüzden sayısal, tekrar etmeyen kodlar tercih edilir.

## Kısa Tekrar Notları

- GRASP'ın 9 prensibi: Uzman, Yaratıcı, Az Bağımlılık, İyi Uyum, Denetçi, Çok Şekillilik, Yapay Sınıf, Dolaylılık, Değişimlerden Korunma. Onuncusu: Yabancılarla Konuşma.
- Uzman: bilgiye kim sahipse sorumluluk onundur.
- Yaratıcı: içeren, kaydını tutan, yakından kullanan ya da başlangıç verisine sahip olan yaratır.
- Az bağımlılık: değişim diğerlerini etkilemesin, tekrar kullanım kolaylaşsın.
- İyi uyum: sınıfın sorumlulukları birbiriyle ilgili olsun.
- Denetçi: sistem olaylarını karşılayan, işi yapmayıp sorumlusuna aktaran yapay uzman.
- Çok şekillilik: tipe göre değişen davranış polimorfik metotla gerçeklenir.
- Yapay sınıf: uzman çözümü uyum ve bağımlılıkla çelişince gerçekte olmayan bir sınıf; az kullanılır.
- Dolaylılık: değişebilen iki birimin arasına arabirim; Adapter, Facade, Observer.
- Değişimlerden korunma: kararsız noktaların etrafına kararlı arayüz.
- Yabancılarla konuşma: yalnız this, parametre, özellik, koleksiyon elemanı ve metotta yaratılan nesneyle konuş.
- Başlangıç nesnesi (initial domain object) diğer nesneleri yaratır ve bağlar.
- Parametre görünürlüğü özellik görünürlüğünden daha az bağımlılık yaratır.
- ER modeli: varlık (dikdörtgen), nitelik (elips), anahtar (altı çizili), ilişki (eşkenar dörtgen), zayıf varlık (çift dikdörtgen).
- 1-n: 1 tarafının anahtarı n tarafına yabancı anahtar. n-m: ayrı bağlantı tablosu.
- Zayıf varlığın anahtarı = sahip varlığın anahtarı + kendi kısmi anahtarı.

## Detaylı Açıklamalar

- Uzman prensibi ile satış toplamı (ekrandan, 00:10:00; 00:15:00)
  - Kavramsal modelde Sale (time), SalesLineItem (quantity) ve ProductDescription (description, price, itemID) vardır. Sale ile SalesLineItem arasında 1'e 1..* "Contains", SalesLineItem ile ProductDescription arasında * ile 1 "Described-by" ilişkisi vardır.
  - Soru: "Satışın toplam bedelinin belirlenmesinden kim sorumludur?" Bütün satış satırlarını Sale bildiği için `getTotal()` Sale'e atanır. Sale her satıra (döngü, `1 *: st = getSubtotal()`) alt toplamını sorar; miktarı bilen SalesLineItem'dır. SalesLineItem fiyatı bilmez, `1.1: p := getPrice()` ile ProductDescription'a sorar.
  - Hocanın slayta yazdığı sözde kod (ekrandan, 00:15:00):

    ```text
    sale.getTotal(){
      foreach(item in salesLines){
        st=getSubTotal();
      }
    ```

  - Toplama ve vergi hesabı gibi algoritma ayrıntıları sözde kodda gösterilmedi; burada amaç sorumlulukların kime atandığını göstermektir.
- Yaratıcı ve az bağımlılık örnekleri
  - Barkod okutuldukça yeni bir SalesLineItem yaratılıp koleksiyona eklenir. Register yaratsaydı Sale'in iç ayrıntılarına bağımlı olurdu; Sale bu satırları içerdiği için yaratıcı odur.
  - Ödeme: `makePayment` Register'a gelir, Register hiçbir şey yapmadan `s.makePayment(...)` çağırır; Sale içinde `1.1` olarak `new Payment` yapılır. Böylece Register ödemeyle (ve ileride eklenebilecek başka ödeme türleriyle) bağımlı kalmaz. Aynı örnek, kasanın uyumunu bozmadığı için iyi uyum örneği olarak da verildi.
- Denetçi örneği (ekrandan, 00:35:00)
  - Kasiyer (`:Cashier`) "The FOO Store" penceresinde Item ID ve Quantity girip Enter Item butonuna basar. UI katmanındaki `:SaleJFrame` `actionPerformed(actionEvent)` olayını alır ve sistem işlemi mesajı `1: enterItem(itemID, qty)` ile alan katmanındaki `:Register`'a (denetçi) iletir. Register da `1.1: makeLineItem(itemID, qty)` ile `:Sale`'e aktarır.
  - Register yalnız barkod hane sayısı ya da negatif miktar gibi basit kontroller yapabilir; fiyat bulma, satır yaratma ve vergi hesabı uzmanların işidir.
  - Sistem büyüyüp denetçinin uyumu bozulursa satış, iade ve ödeme için ayrı senaryo denetçileri kullanılabilir.
- Çok şekillilik, adaptör ve değişimlerden korunma
  - Vergi hesabı için farklı dış sistemlerle (biri TCP soketiyle, biri REST API ile) konuşan adaptörler aynı arayüzü gerçekler; uygulama yalnız `getTaxes` gibi arayüz metoduyla konuşur.
  - Müşteri "yalnız nakit ve kredi kartı" dese bile sonradan kripto para, çek ya da yemek kartıyla ödeme isteyebilir. Ödeme gibi kararsız noktalar baştan kararlı bir arayüzün arkasına alınmalıdır; bu, uygulamanın içinde iç adaptörler kurmak gibidir.
  - Polimorfizmde hangi davranışın çalışacağı derleme zamanında değil çalışma zamanında belli olur.
- Yabancılarla konuşma (ekrandan, 00:50:00)
  - `Money amount = sale.getPayment().getTenderedAmount();` kötüdür: çağıran sınıf farkında olmadan Payment'a bağımlı olur.
  - `Money amount = sale.getTenderedAmountOfPayment();` iyidir: yalnız tanıdık olan Sale ile konuşulur, Sale'e yeni bir sorumluluk eklenir.
  - Payment'a gerçekten erişmek gerekiyorsa Payment tanıdık hale getirilir ve sınıf diyagramına bir ilişki daha eklenir.
- Başlangıç işlemleri örneği
  - Store yaratılır; Store ProductCatalog'u yaratır; katalog boş bir ürün tanımı listesi yaratır, ürün tanımlarını (belki veritabanından) okur, her ProductSpecification'ı yaratıp listeye ekler. Katalog hazır olunca Store Register'ı yaratır ve kataloğu ona verir. Katalog yaratılmadan kasanın yaratılmaması gibi mantık sırasını başlangıç nesnesi sağlar.
- Görünürlük örnekleri (ekrandan, 01:00:00)
  - Register `enterItem(id, qty)` alınca `1: spec := getSpecification(id)` ile ProductCatalog'dan ürün tanımını alır, sonra `2: makeLineItem(spec, qty)` ile Sale'e verir. Sale `2.1: create(spec, qty)` ile `sl: SalesLineItem` yaratır.
  - Sale, `spec`'i yalnız aktardığı için parametre görünürlüğünde kalır. SalesLineItem kurucusunda `productSpec = spec;` atamasıyla parametre görünürlüğü nitelik görünürlüğüne dönüşür (slayttaki not: "Çoğunlukla parametre görünürlüğü nitelik görünürlüğüne dönüşür").
  - Ders sonrası not: Hoca Register'daki `spec := getSpecification(id)` atamasını özellik görünürlüğü olarak anlattı. Larman'ın sınıflandırmasında metodun içindeki bir değişkene atanan nesne büyük olasılıkla yerel (local) görünürlük örneğidir; nesnenin bir özelliğe atanması ise özellik görünürlüğüdür.
- Tasarım sınıf diyagramı örneği (ekrandan, 01:05:00)

  | Sınıf | Özellikler | Metotlar |
  |---|---|---|
  | Store | address : Address, name : Text | addSale(...) |
  | ProductCatalog | ... | getSpecification(...) |
  | ProductSpecification | description : Text, price : Money, itemID : ItemID | ... |
  | Register | (yok) | endSale(), enterItem(...), makeNewSale(), makePayment(...) |
  | Sale | date : Date, isComplete : Boolean, time : Time | becomeComplete(), makeLineItem(...), makePayment(...), getTotal() |
  | SalesLineItem | quantity : Integer | getSubtotal() |
  | Payment | amount : Money | ... |

  - İlişkiler: Store 1 Uses 1 ProductCatalog; Store 1 Houses 1 Register; Register 1 Looks-in 1 ProductCatalog; ProductCatalog 1 Contains 1..* ProductSpecification; Register 1 Captures 1 Sale; Sale 1 Contains 1..* SalesLineItem; SalesLineItem * Describes 1 ProductSpecification; Sale 1 Paid-by 1 Payment; Store 1 Logs-completed * Sale.
  - Kesik çizgili bağımlılıklar: Register'dan ve Sale'den ProductSpecification'a.
- ER örneği (ekrandan, 01:30:00)
  - personel (sno [anahtar], isim, kazanç) "çalışan" ilişkisiyle Departman (dno [anahtar], dep_ad, bütce) varlığına bağlanır; ilişkinin niteliği "'den beri"dir. Bu bilgi personele de departmana da konamaz, çünkü bir personel birden fazla departmanda farklı tarihlerden beri çalışabilir.
- Kitapçı veritabanı (ekrandan, 01:40:00)
  - KİTAP (ISBN [anahtar], Başlık, YayınevID, Fiyat), YAZAR (YazarID [anahtar], Yazar Adı, Yazar Soyadı, Yazar Telefon No), YAYINEVİ (YayınevID [anahtar], Yayınevi Adı, Yayınevi Telefon No).
  - KİTAP ile YAZAR arasında ∞-∞ "Tarafından Yazılmış" ilişkisi, KİTAP (∞) ile YAYINEVİ (1) arasında yayınlanma ilişkisi vardır. Kitaptaki YayınevID yabancı anahtardır.
  - Hocanın yazdığı tablo: K1, K2, K3 kitapları Y1'e; K4 Y2'ye bağlıdır. Y1 "Altın", Y2 "gümüş" yayınevidir; böylece bir yayınevinin n kitabı olur.
- Çoka çok gerçekleme (ekrandan, 01:45:00)

  ```text
  Film   (filmID, filmAdi, y_tarihi, yonetmen)        birincil anahtar: filmID
  Sinema (sinemaID, sinemaAdi, adres, telefon)        birincil anahtar: sinemaID
  Oynar  (oynarID, filmID, sinemaID, tarih, saat)     birincil anahtar: oynarID
                                                      yabancı anahtar: filmID, sinemaID
  ```

  - Aynı film aynı sinemada farklı tarih ve saatlerde oynayabildiği için (filmID, sinemaID) çifti benzersiz değildir; bu yüzden oynarID eklendi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
