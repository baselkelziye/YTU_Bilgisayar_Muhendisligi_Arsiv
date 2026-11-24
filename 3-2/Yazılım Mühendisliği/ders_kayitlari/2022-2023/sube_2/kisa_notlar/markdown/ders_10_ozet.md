# Ders 10 Çalışma Özeti

## Genel Konular

- Analizden tasarıma geçiş
  - Tasarım sıfırdan yapılmaz; analiz aşamasında üretilen yapıtların (alan modeli, kullanım şeması, kullanım senaryosu metni, etkinlik ve durum şemaları) üzerine kurulur.
  - Derste NextGenPOS perakende satış örneğinin analiz sınıf şeması kopyalanıp tasarım sınıf şemasına dönüştürüldü: üye alanlar ayrıntılandırıldı, türleri yazıldı ve metotlar eklendi.
  - Metotlar kullanım senaryosu metnindeki ve etkinlik şemasındaki eylemlerden çıkarıldı. Her eylem bir ya da birden fazla metotla hayata geçirilir.
  - Bir metodun ayrıntısı üzerinde karar verildiğinde, kararın unutulmaması için o metodun sıralama şeması (sequence diagram) çizildi.
- Kullanılan analiz yapıtları (ekrandan, 00:10:00 ve 00:45:00)
  - Kullanım şeması: Kasiyer, Satış senaryosuna bağlı; Satış `<<include>>` Yeni Satış Başlat, Kimlik Doğrulama ve Ödeme; Geçersiz Barkod ve Ürün İptal, Satış'ı `<<extend>>` eder; Provizyon, Ödeme'yi `<<extend>>` eder.
  - Etkinlik şeması: kasiyerin kimliği doğrulanır, müşteri kasaya gelir, kasiyer yeni satış başlatır, kasiyer ürün barkodu girer, [barkod geçerli] ise sistem satış maddesi oluşturur, [daha ürün varsa] barkod girişine dönülür, [else] kasiyer toplamı bildirir ve ödeme ister, ödeme tahsili, sistem fiş verir, müşteri ayrılır.
- Kasa sınıfının üye alanları (ekrandan, 00:20:00 ve 01:05:00)
  - İşlerin başladığı odak nokta Kasa sınıfıdır: kasiyer giriş yaptıktan sonra kasanın tuşlarıyla işleri yaptırır.
  - `kasiyer : Kasiyer`, `sube : Sube`, `satislar : LinkedList<Satis>`, `aktifSatis : Satis`.
  - Satışlar bağlı listede tutulur: rastgele erişim gerekmez (gün sonu raporunda bütün satışlar sırayla gezilir) ve sürekli yeni satış eklenir.
  - `satislar` listesinde yalnız tamamlanmış satışlar durur; süren satış ayrı bir üye alan olan `aktifSatis` içinde tutulur. Üye alan olduğu için başka metotlardan da erişilebilir; bu daha esnek bir çözümdür.
- Şube ve ürün kataloğu (ekrandan, 00:30:00)
  - Şube sınıfına `urunler : Hashmap<String,Urun>` eklendi. Anahtar barkod, değer ürün nesnesidir.
  - Barkoddan ürüne rastgele (doğrudan) erişim gerektiği için sıralı arama yerine eşleme (map) yapısı seçildi. HashMap çok iş parçacıklı (thread-safe) değildir; sistem katmanı düşünülmediği için yeterli görüldü.
  - Hizmet metodu: `+ urunBul( barkod:String ) : Urun`.
- Tasarım sınıf şemasının son hali (ekrandan, 01:05:00 ve 01:15:00)
  - Kasa: `login( uName, passwd : String ) : boolean`, `satisBaslat( )`, `barkodGir( barkod : String, adet : int ) : Urun`, `toplamHesapla( ) : double`, `odemeTahsil( ) : boolean`, `fisBas( ) : String`.
  - Satış: `tarih : Date`, `kalemler : LinkedList<SatisKalemi>`; `kalemOlustur( urun : Urun, adet : int )`, `toplamHesapla( ) : double`, `getTarih( ) : Date`, `urunSil( barkod : String, adet : int ) : boolean`.
  - SatışKalemi: `adet : int`, `urun : Urun`; `SatisKalemi( urun : Urun, adet : int )`, `araToplamHesapla( ) : double`, `getUrunBarkod( ) : String`; sonra `getAdet` ve `setAdet` eklendi.
  - Ürün: `barkod, tanim : String`, `fiyat, KDV : float`; dört parametreli yapıcı, `getBarkod`, `getTanim`, `getFiyat`, `getKDV`.
  - Ödeme: `miktar : double`; `Odeme( miktar : double )`, `getMiktar( ) : double`.
- Ana senaryonun sıralama şeması (ekrandan, 00:50:00 ve 00:55:00)
  - `satisBaslat()` ile Kasa, `new()` ile aktifSatis nesnesini oluşturur; aktifSatis kendi içinde `tarih = new()` yapar.
  - `urunGir(barkod:String, adet:int)`: Kasa, `sube:Sube` nesnesine `urunBul(barkod)` der ve `urun` döner. Not: `[urun==null] uyariVer() return;`.
  - Kasa, aktifSatis'e `kalemOlustur(urun, adet)` der; aktifSatis `new(urun, adet)` ile bir `:SatisKalemi` oluşturur ve kalemler listesine ekler.
  - Toplam hesaplama: Kasa'nın `toplamHesapla()` metodu aktif satışınkini çağırır; satış her kalem için (döngü, `*`) `araToplamHesapla()` çağırır; kalem ürünün fiyatını `getFiyat` ile alır ve adet × fiyat döndürür; satış kümülatif toplamı döndürür.
- Alternatif senaryo: ürün silme (ekrandan, 01:25:00)
  - Kasa `urunSil( barkod : String, adet : int )` alır ve aktifSatis'e `urunSil( barkod, silinecekAdet )` der.
  - aktifSatis kendi içinde `<<silinebilecek olanı bul>>` adımıyla listeyi gezer, bulunan kalemden `getAdet()` ile `mevcutAdet` alır.
  - `[silinecekAdet == mevcutAdet]` ise `<<silinebilecek olanı sil>>`; `[else]` ise `setAdet( mevcutAdet - silinecekAdet )`.
- Ders notundaki tasarım modeliyle karşılaştırma (ekrandan, 01:10:00)
  - Ders notunda Şube'nin ürünleri ayrı bir Katalog sınıfında (`urunler : Hashtable`) tutuluyor; derste ürünler doğrudan Şube'ye konmuştu.
  - Ders notunda kalemin bedeli `getBedel()`, derste `araToplamHesapla()`; satış kalemi ekleme `urunEkle`, derste `kalemOlustur` adını aldı.
  - Ders notunda satışta `kalemAra( barkod ) : SatisKalemi` özel (private) bir yardımcı metottur ve `urunEksilt` içinden çağrılır; satış kaleminde `miktarArttir` ve `miktarAzalt` vardır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bir iş, o işin verisi neredeyse orada yapılır
  - Satış kalemini kasa değil satış oluşturur: kasa ürünü şubeden öğrenir, ürünü ve adedi satışa verir; kalemleri saklayan satış nesnesi kalemi kendisi oluşturur. Nesneye yönelimin istediği budur.
  - Toplamı da asıl satış hesaplar; kasanın `toplamHesapla()` metodu yalnız aktif satışın aynı adlı metodunu çağırıp sonucu döndürür. Aynı adlı iki metodun gövdeleri çok farklıdır.
- Sınıf şeması ile sıralama şeması tutarlı olmalı
  - Sıralama şemasına bir metot çağrısı eklemeden önce sınıf şemasına bakılıp metodun tam adı kontrol edilmeli; ödevler ve projeler bu tutarlılığa göre değerlendirilir. Kopyala-yapıştır bunu kolaylaştırır.
  - Sıralama şeması çizerken eksik bir metot fark edilirse sınıf şemasına geri dönüp eklenir.
- Her şeyi tek şemaya sıkıştırmayın
  - Bir senaryonun ana akışını ve bütün alternatiflerini tek sıralama şemasında göstermeye çalışmanın anlamı yoktur; ürün silme ayrı bir şemaya (alternatif senaryo) bırakıldı.
  - Uzun ana senaryo da istenirse satış başlatma, ürün girme ve toplam hesaplama olarak üç ayrı şemaya bölünebilir.
- "Söz uçar, yazı kalır"
  - Sözle verilen tasarım kararları (örneğin satışın tarihi kendi yapıcısında oluşturması) şemaya yazılmalıdır.
- Gereksiz karmaşıklıktan kaçının
  - Aynı ürün ikinci kez okutulduğunda eski kalemin adedini artırmak (`miktarArttir`) gereksizdir: 2 × 2 su ile 4 × 1 su toplamı aynıdır. Miktar azaltma ise gereklidir.
  - Sıfır adetli kalem fişte kalmamalıdır; silinecek adet mevcut adede eşitse kalem listeden tamamen silinir.

## Kısa Tekrar Notları

- Tasarım = analiz yapıtları + metotlar + türler + veri yapısı kararları.
- Metotlar kullanım senaryosu ve etkinlik şemasındaki eylemlerden çıkar.
- Sıralı erişim ve sık ekleme için `LinkedList`; anahtarla doğrudan erişim için `HashMap`.
- Süren satış `aktifSatis` üye alanında, tamamlananlar `satislar` listesinde.
- `barkodGir` / `urunGir` barkodla birlikte adet de alır; tek adet özel durumdur (adet = 1).
- `urunBul` bulamazsa `null` döner; kasa null kontrolü yapar, uyarı verir ve akışı bitirir.
- Satış kalemini satış oluşturur; toplamı satış hesaplar; kalem kendi ara toplamını (adet × fiyat) verir.
- Ürün silmeye ürün nesnesi değil barkod verilir: ürün zaten kalemlerdedir, şubeye yeniden sorulmaz, daha az veri iletilir.
- Silinecek adet = mevcut adet ise kalem silinir; değilse `setAdet( mevcutAdet - silinecekAdet )`.
- Sıralama şemasında döngü `*` ile, koşul `[koşul]` ile, kendi içinde yapılan iş kendine çağrı olarak gösterilir.

## Detaylı Açıklamalar

- Derste, önceki haftalarda NextGenPOS perakende satış programı için çizilen alan modeli tasarım sınıf şemasına dönüştürüldü. Analiz şemasında sınıflar ve ilişkiler vardı ama metotlar yoktu (ekrandan, 00:15:00). Analizde Ürün (`barkod, tanim : String`, `fiyat, KDV : float`), Şube (`ad, adres, vergiNo : String`), SatışKalemi (`adet : int`), Satış (`tarih : Date`), Ödeme (`miktar : double`), Kasa ve Kasiyer sınıfları vardı. Şube ile Kasa arasında bire-çok toplama (aggregation) ilişkisi, Şube'den Ürün'e bir-çok, Satış'tan SatışKalemi'ne bir-bir ya da çok (1..*), Satış'tan Ödeme'ye bir-bir ilişki çizilmişti.
- Tasarıma kasadan başlandı, çünkü bütün işler kasada başlar. Önce üye alanların türleri koda yakın biçimde yazıldı. Kasanın yaptığı satışlar için dizi yerine bağlı liste seçildi. Dizide yer bitince genişletmek gerekir; burada belirli bir satışı sorgulama gibi bir kullanım senaryosu yoktur, gün sonu raporunda bütün satışlar sırayla gezilir ve sürekli yeni satış eklenir. Bu yüzden `satislar : LinkedList<Satis>` en uygun yapıdır.
- `login( uName, passwd : String ) : boolean` metodu kullanıcı adı ve parola alır, başarılıysa true döndürür. Parolanın açık metin gönderilmeyip özetinin (hash) gönderilmesi gerektiği, ama dersin konusunun veri güvenliği ya da sistem tasarımı olmadığı için bu ayrıntıya girilmediği belirtildi.
- `satisBaslat( )` parametre almaz; yeni satış nesnesini kendi içinde oluşturur. Satışın kimlik numarasına ihtiyaç yoktur. Java'da bir `Date` nesnesi oluşturulduğu anın gün ve saatini taşıdığı için satışın tarihi satışın kendi yapıcısında oluşturulabilir, kasanın tarih vermesine gerek yoktur. Metodun başarı bilgisi döndürüp döndürmemesi, satışın arka planda nasıl yürüdüğüne (ayrı bir iş parçacığı mı, olay bekleyen bir süreç mi) bağlıdır; bu sistem düzeyi ayrıntı şimdilik açık bırakıldı.
- Barkod girildiğinde ürünün bulunması gerekir. Müşteri odaklı analiz metinlerinde bu konu yoktu; gerçeklemede nesne ilişkileri ve tekil tanımlayıcı-nesne eşlemesi düşünülünce ortaya çıktı. Şubede satılan ürünlerin listesi Şube'de durur. Barkoddan ürüne doğrudan erişim gerektiği için `urunler : Hashmap<String,Urun>` seçildi ve Şube'ye `urunBul( barkod:String ) : Urun` hizmet metodu eklendi (ekrandan, 00:30:00).
- Bir ürünün kaç adet alındığı da düşünüldü. Ürünü iki kez okutmak ya da adedi girip bir kez okutmak kasiyerin tercihidir. Genel durum n adettir; bir adet bunun özel durumudur. Bu yüzden barkod giriş metoduna `adet : int` parametresi eklendi ve satış kalemine `SatisKalemi( urun : Urun, adet : int )` yapıcısı konuldu.
- Ana senaryonun sıralama şeması adım adım çizildi (ekrandan, 00:55:00). Kasa `satisBaslat()` ile aktifSatis'i `new()` ile oluşturur, aktifSatis kendi içinde `tarih = new()` yapar. Sonra `urunGir(barkod:String, adet:int)` gelir; kasa şubeye `urunBul(barkod)` der, `urun` döner. Ürün `null` ise kasa kendi `uyariVer()` metodunu çağırır ve döner; sıralama şemasında akışın bitişini göstermek zor olduğu için bu bir notla belirtildi. Ardından kasa aktifSatis'e `kalemOlustur(urun, adet)` der; aktifSatis `new(urun, adet)` ile SatışKalemi oluşturur ve kalemler listesine ekler.
- Toplam hesaplamada kasa aktif satışa sorar, satış her kalem için ara toplamı ister, kalem ürünün fiyatını alıp adetle çarpar. Satış bunları kümülatif olarak toplar ve sonucu kasaya döndürür. Ödeme tahsili ve fiş basma metotları yalnız sınıf şemasına eklendi: `odemeTahsil( ) : boolean` (provizyon alınamayabilir) ve `fisBas( ) : String` (fişin içeriğini metin olarak döndürme seçeneği).
- Ürün silme alternatif senaryosu ayrı bir sıralama şemasıyla çizildi (ekrandan, 01:25:00). Bu kez satışa barkod iletilir; ürün zaten bir kalemde olduğu için şubeye yeniden sormak gereksizdir. Satış, kalem listesinde barkodu eşleşen kalemi bulur, mevcut adedi öğrenir; silinecek adet mevcut adede eşitse kalemi listeden siler, değilse adedi azaltır. Adlandırmada `silinecekAdet` ve `mevcutAdet` gibi açık adlar seçildi; ikisine de "adet" demek anlam karışıklığı yaratır.
- Son olarak derste yapılan tasarım ders notundaki NextGenPOS tasarım modeliyle karşılaştırıldı. Ders notunda ayrı bir Katalog sınıfı vardır; farklı şubelerde farklı kataloglar olacaksa bu daha mantıklıdır, ama saklama maliyeti büyük değilse her şubede bütün ürünlerin bilgisinin bulunması da kabul edilebilir. Ders notunda çok iş parçacıklı kullanım için `Vector`, aksi halde `LinkedList` kullanılabileceği söylendi.
<!-- BELİRSİZ: Ders notundaki Katalog sınıfına ilişkin açıklama notu karede kesik görünüyor; tam metni okunamadı (ekrandan, 01:10:00). -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
