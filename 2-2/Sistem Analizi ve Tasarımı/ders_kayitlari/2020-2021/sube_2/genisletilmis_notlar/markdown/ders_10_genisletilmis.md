# Ders 10 Genişletilmiş Notu: Sistem Tasarımı: GRASP Sorumluluk Atama Prensipleri ve Varlık-İlişki Modeli

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Sorumluluk atama sorusu ve GRASP
- 2. Uzman (Information Expert)
- 3. Yaratıcı (Creator)
- 4. Az Bağımlılık (Low Coupling)
- 5. İyi Uyum (High Cohesion)
- 6. Denetçi (Controller)
- 7. Çok Şekillilik (Polymorphism)
- 8. Yapay Sınıf (Pure Fabrication)
- 9. Dolaylılık-Arabirim (Indirection)
- 10. Değişimlerden Korunma (Protected Variations)
- 11. Yabancılarla Konuşma (Don't Talk to Strangers)
- 12. Senaryoların gerçeklenmesi ve başlangıç işlemleri
- 13. Görünürlük
- 14. Tasarım sınıf diyagramı ve bağımlılıklar
- 15. Tasarımdan kodlamaya
- 16. Veri tasarımı ve veritabanı tasarım aşamaları
- 17. Veri modelleri
- 18. Varlık-ilişki modeli: varlık, nitelik, anahtar, ilişki
- 19. İlişki tipleri
- 20. Varlık-ilişki diyagramını tablolara dönüştürme
- 21. Zayıf varlık kümeleri
- Örnek Sorular

## 1. Sorumluluk atama sorusu ve GRASP

Ders, nesneye yönelik tasarımın devamıyla başladı. Önceki derslerde hangi diyagramların neden üretildiği konuşulmuş ve sorumluluk atamaya giriş yapılmıştı. Bu dersin ilk yarısının sorusu şudur: senaryolarda bulunan sorumluluklar (eylemler, fiiller, yapılması, bilinmesi ve bulunması gerekenler) hangi sınıftan türeyen nesneye, neye dikkat edilerek atanmalıdır?

Hoca bunun için 9 genel sorumluluk atama prensibini anlattı. Bunları birebir ezberlemek beklenmiyor; amaç tasarım yaparken yol gösterici olmalarıdır. Nesneye yönelik çözümlemeden çoğu zaten biliniyor, burada daha formal tanımları veriliyor.

Slayttaki tanım (ekrandan, 00:05:00):

- GRASP Tasarım Kalıpları: genel prensipler ve akla yatkın çözümlerin birleştirilmesiyle oluşturulan repertuar.
- Probleme getirdiği çözümü belirten kolay isimler verilir (iletişimi kolaylaştırır).
- Kalıplar, tanımlı bir problem için en iyi çözümü sağlar.
- GoF kalıpları: 23 adet.
- Bu derste 9 adet genel sorumluluk atama prensibi anlatılacaktır.

Hoca GRASP'ı "General Responsibility Assignment Software Patterns", yani genel sorumluluk atama yazılım kalıpları olarak açıkladı ve bunlara temel prensipler de denebileceğini söyledi. Temel soru hep aynıdır: bir iş yapılacak, bir hizmet verilecek; bu metodu kime atamalıyım?

## 2. Uzman (Information Expert)

### 2.1 Tanım

Önceki derslerden hatırlanan örnek satışın toplam tutarının hesaplanmasıdır. Bir satışta birçok satış kalemi vardır; her birinin fiyatı ve miktarı çarpılıp toplanmalı, sonra vergi hesaplanmalı ve toplam ekranda gösterilmeli ya da muhasebe sistemi gibi başka bir sisteme aktarılmalıdır. "Toplam tutarı hesapla" sorumluluğu kime atanacak?

İlk ve temel prensip uzmandır (expert): bir sorumluluk, bilginin uzmanına atanır. Bilginin uzmanı, o işi yerine getirecek veriye sahip olan, ona erişebilen sınıftır.

Nasıl bulunur? Önce tasarımda yazılım sınıfı varsa ona bakılır. Yoksa analiz modelindeki kavramsal sınıf diyagramına dönülür (kasiyer, kasa, satış, satış satırları, ürün, ürün tanımı gibi). Bu veriye kim sahipse o kavramsal sınıf, analiz modelinden tasarım modeline, yani yazılımın gerçekleştirileceği uzaya taşınır ve yazılım sınıfı haline getirilir. Böylece gerçek dünyayı modellediğimiz hal ile yazılım arasındaki fark düşük kalır.

### 2.2 Örnek: satışın toplam bedeli

Slayttaki kavramsal model (ekrandan, 00:10:00):

| Sınıf | Nitelikler |
|---|---|
| Sale | time |
| SalesLineItem | quantity |
| ProductDescription | description, price, itemID |

- Sale 1 — Contains — 1..* SalesLineItem
- SalesLineItem * — Described-by — 1 ProductDescription

Slaytın sorusu: "Satışın toplam bedelinin belirlenmesinden kim sorumludur?" Cevap Sale'dir, çünkü satışla ilgili bütün nesnelere o sahiptir; her satırı o bilir. Bu yüzden `t = getTotal` mesajı `:Sale` nesnesine gelir ve Sale yazılım sınıfına yeni bir metot olarak `getTotal()` eklenir.

Ama Sale cevabı hemen veremez; kendisinin de öğrenmesi gereken veriler vardır. Diyagramdaki yıldız döngü demektir: Sale bütün satış satırlarına teker teker alt toplamlarını sorar (`1 *: st = getSubtotal()`). Neden? Her satırın kaç para tuttuğunu satır bilir, çünkü miktar satırdadır. Bu yüzden `getSubtotal()` SalesLineItem'a atanır.

Bu da yetmez: satış satırı ürünün fiyatını bilmez. Fiyatın uzmanı ProductDescription'dır. Bu yüzden SalesLineItem kendi içinde `1.1: p := getPrice()` çağırır ve ProductDescription'a `getPrice()` sorumluluğu atanır.

Slayttaki son durum (ekrandan, 00:15:00):

```text
t = getTotal  -->  :Sale  --1 *: st = getSubtotal()-->  lineItems[i] : SalesLineItem
                                                              |
                                                     1.1: p := getPrice()
                                                              v
                                                       :ProductDescription

Sale:               time, ...            | getTotal()
SalesLineItem:      quantity             | getSubtotal()
ProductDescription: description, price,  | getPrice()
                    itemID
```

Hoca satış satırlarını "kalem, silgi" diye örnekledi: Sale kaleme ve silgiye ayrı ayrı alt toplamını sorar ve bunları kendi metodunda toplar. Ardından slayta sözde kod yazdı (ekrandan, 00:15:00):

```text
sale.getTotal(){
  foreach(item in salesLines){
    st=getSubTotal();
  }
```

SalesLineItem tarafında da `p = productDescription.getPrice()` çağrılıp sonuç döndürülür. Hoca, bu sözde kodda değerlerin bir değişkende toplanması ya da vergi hesabı gibi algoritma ayrıntılarının yazılmadığını belirtti. Önemli olan şudur: senaryodaki bir sorumluluk bir nesneye verilir; o nesne başka bir uzmana, o da başka bir uzmana sorar. Sonuçta üç ayrı uzmana sorumluluk atanmış olur, ama senaryodaki toplam hesaplama metodunun sahibi Sale'dir.

> **Ek bilgi (derste anlatılmadı):** Slayttaki sözde kodda toplama satırı yoktur. Tam bir gerçeklemede döngü öncesinde bir toplam değişkeni sıfırlanır, her turda alt toplam bu değişkene eklenir ve döngü sonunda toplam döndürülür. SalesLineItem'ın alt toplamı da büyük olasılıkla miktar ile fiyatın çarpımıdır.

## 3. Yaratıcı (Creator)

İkinci prensip yaratma prensibidir. Soru: bir nesne örneği yaratılacaksa bunu kim yaratmalı, yani `new ...` satırı nerede yazılmalı?

Cevap: B, A nesnelerini içeriyorsa, kaydını tutuyorsa, onları (yakından) kullanıyorsa ya da A'yı yaratmak için gereken başlangıç verilerine sahipse A'nın yaratıcısı B olmalıdır.

Örnek: barkod okutuldukça her bir satış satırının (SalesLineItem) yaratılıp koleksiyona, örneğin bir diziye eklenmesi gerekir. Bunları kasa mı yaratsın? Barkodu kasa okuyor; ama kasa yaratırsa satışın iç ayrıntılarıyla gereksiz yere ilgilenmeye başlar. Çok sayıda satış satırını içeren nesne Sale'dir; bu yüzden yaratma sorumluluğu Sale'e verilir. Kasaya verilseydi Sale, `getPrice`, `getSubtotal` gibi işleri yaparken her seferinde kasaya "şunu bana ver" diye sormak zorunda kalırdı. Hoca bunu bir çeşit "yaratma uzmanı" olarak düşünmeyi önerdi: bir nesneyi yaratma sorumluluğu onu en çok kullanana, içinde barındırana verilir.

## 4. Az Bağımlılık (Low Coupling)

### 4.1 Problem ve çözüm

Slayttaki tanım (ekrandan, 00:20:00):

- Diğer sınıfların değişimlerinden etkilenmeme, tekrar kullanılabilirlik nasıl sağlanır?
- Sorumlulukları, sınıflar arası bağımlılık en az olacak şekilde atayın.
- Bağımlılık: bir sınıfın kendi işleri için başka sınıfları ne kadar kullandığı, onlar hakkında ne kadar bilgi içerdiği.
- Neden az bağımlılık?
  - Bir sınıftaki değişim diğerlerini de etkiler.
  - Sınıfları ayrı anlamak zordur.
  - Yeniden kullanmak bağımlılık yüzünden zordur.

Hoca yaratıcı örneğinde bunu zaten söylediğini hatırlattı: kasa satır yaratsaydı Sale'e bağımlı hale gelirdi. Bir sınıfın değişmesi ona bağlı sınıfların da değişmesini ve hepsinin yeniden test edilmesini gerektirir; sınıfların ayrı ayrı anlaşılırlığını ve kullanılabilirliğini azaltır. Bu yüzden mümkün olduğunca az bağımlı birimler üretilir.

### 4.2 Bağımlılık ne zaman oluşur?

Slayttaki liste (ekrandan, 00:20:00):

- A'nın B cinsinden üyesi varsa (onu barındırıyorsa),
- A, B'nin metodunu çağırıyorsa (metot bağımlılığı),
- A'nın metodunda B tipinden parametre varsa (daha kısıtlı bir parametre bağımlılığı),
- A'nın metodunda B tipinde değişken varsa,
- A, doğrudan veya dolaylı olarak B'den türetilmişse (alt sınıfıysa).

### 4.3 Örnek: ödeme

Ödeme kasaya yapılır; `makePayment` mesajı Register'a gelir. Register önce bir Payment yaratıp sonra satışa eklerse hem Payment'a hem Sale'e bağımlı olur. Bunun yerine Register hiçbir şey yapmadan isteği doğrudan satışa aktarır: içi boş bir şekilde `s.makePayment(...)` çağırır. Sale de kendi içinde `1.1` olarak `new Payment` yapar. Böylece kasa gereksiz yere ödeme işlemine bağımlı kalmaz; yarın başka türlü bir ödeme eklense bile kasa etkilenmez.

## 5. İyi Uyum (High Cohesion)

### 5.1 Tanım

Slayttaki tanım (ekrandan, 00:25:00):

- Karmaşıklık nasıl idare edilebilir?
- Sorumlulukları, sınıf içinde iyi bir uyum olacak şekilde atayın.
- Uyum: sorumlulukların birbirleriyle ilgili olması ve aynı konuya yoğunlaşmaları.
- Bir sınıf birbiriyle ilişkisi olmayan işler yapıyorsa veya çok fazla iş yapıyorsa uyum kötüdür.
  - Sınıfın anlaşılması zorlaşır.
  - Bakım yapmak zorlaşır.
  - Tekrar kullanmak zorlaşır.
  - Değişikliklerden çok etkilenir.
- Veritabanı işlemleri gibi, bir işi tek bir programcının sorumluluğuna vermek için iyi uyum bozulabilir.
- Dağıtık sistemlerde ağ trafiğini azaltmak için iyi uyum bozulabilir.

Birbiriyle ilişkisi olmayan işler yapan bir sınıf aslında bileşik bir kavramdır. Farklı hizmetler verdiği için anlaşılırlığı ve bakımı zorlaşır; başka bir yerde kullanılması da zorlaşır, çünkü orada da bütün o hizmetlerin aynı şekilde gerekmesi gerekir.

### 5.2 Bilinçli istisnalar

Uzman prensibine göre ödeme kendi kaydını veritabanına yazmalı, satış kendi kayıtlarını, vergi bileşeni kendi okumalarını yapmalıdır. Ama her sınıf veritabanı bağlantısıyla ilgili işleri kendi içinde yaparsa asıl uzmanı olduğu işten uzaklaşır ve uyumsuz işler yapmaya başlar. Veritabanı işlemlerini tek bir ekibe ya da programcıya vermek için bu işler uzmanlarından alınıp yapay bir uzmana verilebilir; bütün veritabanı işlemleri bir yerde toplanır. Bu da iyi uyumu biraz bozar.

> **Hocanın vurgusu:** Bunu her yerde yaparsanız C'deki fonksiyonlardan bir farkınız kalmaz; nesne mantığı fonksiyon mantığına dönmeye başlar. Yapay sınıfları yeteri kadar kullanın.

İkinci istisna dağıtık sistemlerde ağ trafiğini azaltma ihtiyacıdır; bu durumda da iyi uyum bozulabilir, ama mümkün olduğunca bozmamaya çalışılmalıdır.

Ödeme örneği burada da geçerlidir: kasa ödeme yaratsaydı asıl işi olmayan bir işin sahibi olurdu. `makePayment` gelince Register isteği Sale'e delege eder; ödemeyle ilgili işler Sale ile uyumlu olduğundan Payment'ı Sale yaratır ve kasanın uyumu bozulmaz. Bir sınıfta birbiriyle çok uyumsuz işler varsa büyük olasılıkla orada ayrı bir kavram, yani yeni bir yazılım sınıfı ihtiyacı vardır.

## 6. Denetçi (Controller)

### 6.1 Tanım

Slayttaki tanım (ekrandan, 00:30:00):

- Sistem olayları ile ilgili işleri yapmakla kim sorumludur?
- Sistem olaylarını algılayıp değerlendirme sorumluluğunu aşağıdaki iki seçenekten biri ile oluşturun:
  - Tüm sistemi-cihazı veya alt sistemi temsil eden bir sınıf (görüntü denetçi, facade controller)
  - Bir senaryoyu temsil eden denetçi (senaryo ya da oturum denetçisi, session or use case controller)
- Sistem olayları: aktörler tarafından üretilen, sistem işlemleri ile ilgili olaylar.
- Örneğin, sipariş et butonuna tıklanması.
- Olayı algılayıp bazı denetimler yaptıktan sonra olayları işleyecek nesnelere yönlendirirler.
- Denetçi nasıl belirlenmeli?
  - Olaylar fazla değilse tek bir denetçi uygundur.
  - Olay sayısı uyumu bozacak kadar fazlaysa birden fazla denetçi.
  - Senaryo içinde sistem kontrolleri yapılacaksa senaryo denetçisi uygun.
- İşleri denetçiler yapmaz. Uygun mesajlarla sorumlu nesnelere aktarırlar.
- Yararı:
  - Arayüzle uygulama katmanı ayrılır. Program arayüzden bağımsız olur.
  - Denetçi görevi arayüz nesnesine de verilebilir. Yeniden kullanılabilirlik ve esneklik kaybolur.
  - Senaryoda işlemlerin sırası denetim altında tutulur. Örneğin, ödeme mesajının siparişi ver'den önce gelmesi engellenir.

Olay tabanlı sistemlerde birçok olay üretilir: biri butona tıklar, barkod okutulur ("bip"), biri barkod numarasını girip Enter'a basar. Bu olayları karşılayacak kavram, kavramsal modelde yer almayan ama yazılımda gereken yapay bir uzmandır: denetçi (kontrolör). Küçük bir sistem ya da alt sistem için tek bir denetçi (facade gibi) yeterlidir; büyük sistemlerde senaryo ya da oturum denetçileri gibi daha fazla yapay uzman yaratılabilir.

Hoca denetçiyi bir ağ geçidine (gateway) benzetti: "iptale bastı, iptalin sorumlusu şu nesne, al sen bunu yap" ya da "fare bir şeyi seçti, ilgilisi şu nesne, al sen yap". Denetçi kime aktarılacağına karar verir ama hizmeti kendisi sunmaz; belki yalnız basit denetimler yapar.

Denetçiyi doğrudan bir Windows formuna ya da web sayfasına koymak mümkündür, ama ayrı tutmakta fayda vardır. Yarın aynı uygulamanın mobil bir ön yüzü istenirse arayüze gömülü denetçi yeniden kullanılamaz ve esneklik azalır. Denetçi işlemlerin sırasını da denetleyebilir; örneğin satış bitmeden ödeme yapılmaya çalışılmasını engelleyebilir.

### 6.2 Sistem denetçisi ve senaryo denetçileri

Slaytta "sistem" tipinde bir denetçi vardı; bu sorumluluklar büyük olasılıkla kasaya verilecektir: satışı tamamla, yeni ürün gir, satış başlat, ödeme yap. Kasa, market sisteminin sistem denetçisi olarak çalışabilir. Sistem büyükse ve denetçi satış, ödeme, iade gibi çok farklı sorumluluklar almaya başlayıp uyumunu bozuyorsa satış işlemleri bir satış denetçisine, iade işlemleri bir iade denetçisine, ödeme ayrı bir denetçiye konabilir. Bu tamamen problemin boyutuna bağlıdır.

### 6.3 Örnek

Slayttaki örnek (ekrandan, 00:35:00):

```text
:Cashier --presses button--> [The FOO Store penceresi: Item ID, Quantity, Enter Item, And so on...]
                                  |
                                  | actionPerformed( actionEvent )
                                  v
UI Layer:                    :SaleJFrame
                                  |
                                  | 1: enterItem(itemID, qty)      <- system operation message
- - - - - - - - - - - - - - - - - | - - - - - - - - - - - - - - - - - - - - -
Domain Layer:                :Register   --1.1: makeLineItem(itemID, qty)-->  :Sale
                             (controller)
```

Kasiyer Java ile yazılmış basit bir pencerede ürünün barkodunu ve miktarını (örneğin 3) yazıp Enter Item'a basar; gerçek marketlerde bu barkodun "bip" diye okutulmasıdır. Olay `actionPerformed` ile JFrame'de karşılanır, JFrame denetçiyi çağırır: "bir ürün girildi, barkodu bu, miktarı bu". Register ürünün fiyatını bulmaz, fiş satırını yaratmaz, KDV hesaplamaz; yalnız barkodun hane sayısı ya da negatif miktar gibi kontrolleri yapabilir ve işi Sale'e aktarır. Ön yüzden gelen bütün olayları karşılayıp ilgililerine dağıtan, bir hub gibi çalışan denetçidir.

## 7. Çok Şekillilik (Polymorphism)

Altıncı prensip çok şekilliliktir; hoca nesneye yönelik programlamadan bilindiği için ayrıntıya girmedi. Problem: tiplere bağlı alternatif davranışlar nasıl ele alınmalı, sisteme kolayca takılabilecek yazılım parçaları nasıl gerçeklenmeli? Cevap: alternatif davranışlar sınıflara bağlı olarak değişiyorsa polimorfik metotlarla gerçeklenir. if/else koşullarıyla metot seçmek iyi bir yöntem değildir. GoF tarafında strateji ve kompozit gibi ilgili kalıplar vardır ama derste onlara girilmedi. Tek bir davranış varsa ve değişmeyecekse çok şekilliliğe gerek yoktur.

Örnek: kredi kartıyla ödeme alınacak. Visa'nın bir doğrulama sistemi vardır, Mastercard okutulursa bilgi Mastercard'a gönderilmelidir; American Express başka, yerli kart sistemi Troy bambaşka bir sunucu, protokol ve parametrelerle çalışır. Ama yapılan iş tektir: kartın geçerli olup olmadığını sormak. Yarın yeni kart türleri eklenebilir. Bu yüzden kredi kartı doğrulama polimorfik olarak gerçeklenmelidir.

Dış sistemlerle konuşuluyorsa her dış sistemin önüne bir adaptör sınıfı konmalı ve uygulama yalnız bu adaptörle konuşmalıdır. Vergi hesabında, örneğin bir vergi sistemiyle konuşan adaptör bir metodu bir şekilde çağırır, başka bir sistemle konuşan başka bir sınıf başka bir yolla çalışır. Ama hepsi aynı arayüzden türemiştir ve aynı hizmeti vermekle yükümlüdür. Uygulama yalnız bu arayüzle muhataptır: "bu hizmeti nasıl verirsen ver, ben bu tipte bir dönüş bekliyorum". İçeride hangi sistemle, hangi protokolle konuşulduğu uygulama mantığından soyutlanır.

## 8. Yapay Sınıf (Pure Fabrication)

Slayttaki tanım (ekrandan, 00:40:00):

- Uzman kalıbının çözümü iyi uyum ve az bağımlılıkla çelişiyorsa sorumluluklar hangi sınıfa atanmalıdır?
- Bağımlılık azalıyor ve tekrar kullanılabilirlik artıyorsa, birbiriyle uyumlu sorumluluklar gerçekte var olmayan yapay bir sınıfa atanabilir.
- NDMT'nin temeli, yazılım unsurlarının gerçek dünyadaki varlıklara benzer tasarlanmasıdır. Bazı durumlarda uyum ve bağımlılık sorunlarına yol açabilir. Bu durumlarda yapay sınıf kullanılır.
- Örneğin veritabanı işlemleri yapay bir sınıfta gerçekleştirilir. Bunun başka projelerde kullanılma olasılığı da yüksektir.
- Yapay sınıflar gereğinden fazla kullanılmamalıdır. Eski alışkanlıklara sahip bir programcı, gerçek dünyadaki varlıklara ayırmak yerine işlevlere ayırmayı seçebilir.
- Çok kullanılırsa gerçek dünyadan uzaklaşılır, anlaşılırlık azalır, bağımlılık artar.

Uzman kalıbı "veritabanı işlemlerini satış kendisi, ödeme kendisi yapsın" der; ama bu sınıf içi uyumu bozar ve bağımlılığı artırır (satış durup dururken veritabanına bağımlı olur). Bu çelişkide sorumluluklar gerçekte var olmayan yapay bir sınıfa atanabilir. Çok kullanılırsa doğrudan işlevsel çözümlemeye gidilir: "satış hizmetleri sınıfı", "ödeme kayıt hizmetleri sınıfı", "ürün okuma hizmetleri sınıfı" gibi fiillerden oluşan sınıflar yaratılmaya başlanır. Bu yüzden yalnız gerektiğinde kullanılmalı, öncelik kavramsal sınıflardan türetilen yazılım sınıflarına verilmelidir.

## 9. Dolaylılık-Arabirim (Indirection)

Slayttaki tanım (ekrandan, 00:45:00):

- Kolay değişebilen iki birim arasındaki bağımlılık nasıl azaltılır?
- Sorumlulukları bir arabirim nesnesine atayın.
- Yapay veritabanı sınıfı, sistemle veritabanı arasında arabirimdir. Örnek: vergi adaptörleri.
- Adapter, Facade, Observer gibi kalıplar bu kalıbın özel halleridir.

Değişim tehlike demektir: bir taraf bir parametre eklerse onu çağıran taraf da değişmeli ve ona bağlı bütün sınıflar yeniden elden geçirilip test edilmelidir. Kolay değişebilecek birimler arasına bir ara birim nesnesi konarak bağımlılık azaltılır.

Veritabanı örneği: uygulamada satış, ödeme, ürünler var ve bunlar bir veritabanına kaydediliyor. Bugün MySQL kullanılırken yarın PostgreSQL'e ya da bulutta çalışan bir NoSQL çözümüne geçilebilir. Bu durumda veritabanına erişen bütün birimler elden geçirilmemelidir; onların tek ihtiyacı "oku, yaz" demektir. Veritabanı ara birimi, bugün `select ... from ...` yazarken yarın NoSQL sorgularına çevirme işini üstlenir. Bu da denetçi gibi bir yapay uzmandır; gerçek hayatta böyle bir kavram yoktur. Her şeyin arasına adaptör konmaz, gerektiği yere konur.

> **Hocanın vurgusu:** Değişim olabilecek yerde mutlaka araya bir tampon koyun.

Hocanın benzetmesi: laptop 19 volt DC ile çalışır, duvardaki elektrik 220 volt AC'dir; araya adaptör konur. Laptopla Amerika'ya gidildiğinde duvardaki gerilim 110 volttur ve adaptör çalışmaz. Laptop değiştirilmez; 110 voltla konuşan alternatif bir adaptör alınır, laptop yine 19 volt DC alır. Değişebilecek iki birim ya da sistem arasındaki bağımlılığı azaltan bu yapay sınıflara arabirim (adaptör) sınıfı denir.

Vergi örneğinde adaptör bir arayüzü gerçekler ve uygulama yalnız `getTaxes` metoduyla konuşur. Adaptörün biri TCP üzerinden soket haberleşmesi yapıyor, başka biri HTTP/REST API ile konuşuyor olabilir. Uygulama yalnız hesaplanmış toplam vergi miktarını geri alır; iş katmanı dış sistemlerin değişiminden korunur.

## 10. Değişimlerden Korunma (Protected Variations)

Dokuzuncu ve son prensip değişimlerden korunmadır; hoca bunu öncekilerin bir özeti olarak tanıttı. Problem: nesnelerdeki değişimler ve kararsızlıklar birbirini en az etkileyecek şekilde nasıl tasarlanmalı? Dış sistemlerdeki değişime karşı araya arabirim konuyordu. Uygulamanın içinde de değişime açık, kararsız noktalar varsa sorumluluklar bunların etrafında kararlı bir arayüz oluşturacak şekilde atanmalıdır.

Örnek: müşteri "nakit ve kredi kartıyla çalışıyoruz, kesin bu kadar" der. Uygulama bitmeden gelip kripto parayla, çekle ya da yemek kartlarıyla ödeme almak istediğini söyler. Ödemeyle ilgili farklılıklar oluşmaya başlar. Bu kararsız noktalar belirlenip kararlı bir arayüzün arkasına alınmalıdır; hoca bunu uygulamanın içinde iç adaptörler yapmaya benzetti.

Bu prensip kapsülleme, veri gizleme (data hiding; güvenlik anlamında değil) ve polimorfizm gibi birçok prensibin temelidir. Hocanın özetiyle amaç şudur: kendi içimizde uyumlu olalım, başkalarına mümkün olduğunca az bağımlı olalım ki onlardaki değişim bizi az etkilesin ve kendimizi az değiştirelim. Polimorfizmde hedef, hangi davranışın çalışacağının derleme zamanında değil çalışma zamanında belli olmasıdır: kredi kartı Visa, Master, Troy ya da American Express olsun, uygulama bundan etkilenmeden "kartı doğrula" ya da "provizyon numarasını ver" hizmetini alabilmelidir.

Bu prensiplere uyulmazsa kötü tasarım ortaya çıkar; uyulursa sürekli değiştirme, güncelleme, yeni sürüm çıkarma ya da hata düzeltme ihtiyacı azalır.

## 11. Yabancılarla Konuşma (Don't Talk to Strangers)

Slayttaki tanım (ekrandan, 00:50:00):

- Bir nesne ancak tanıdık (sınırlı sayıda) bir hedefe mesaj göndermelidir:
  - Kendisi (this)
  - Metodun parametresi olan nesne
  - Nesnenin üyesi (özelliği) olan nesne
  - Nesnenin üyesi olan bir grubun (liste, vektör vs) elemanı olan nesne
  - Metodun içinde yaratılan nesne
- Dolaylı (tanıdığın tanıdığı) nesneler ise yabancı nesnelerdir.
- Metot içinden yabancı nesnelere mesaj gönderilmesi bağımlılık yaratır. Görülmesi zor, olmaması gereken bir bağımlılıktır. Bu yüzden tercih edilmez.
- Örnek:

  ```text
  Money amount = sale.getPayment().getTenderedAmount();   // kötü
  Money amount = sale.getTenderedAmountOfPayment();       // iyi
  ```

- Gerçekten gerekliyse, tanıdık nesneye sorumluluk olarak atamak gerekir.

Hoca bu kalıbı da bağımlılıkla ilgili olarak ekledi. Birinci satır hızlı ve kolay göründüğü için sık yazılır ve çalışır: satışın içindeki ödemenin içindeki ödenen tutarı alır. Ama çağıran sınıf farkında olmadan Payment'a bağımlı hale gelir; Payment değişirse `amount` değişkeni yüzünden kod bozulabilir. Doğrusu yalnız tanıdık olan Sale'e sormaktır: "bana ödeme miktarını ver". Bu Sale için yeni bir sorumluluktur. Payment değişirse Sale zaten değişir; çağıran taraf ise yalnız Sale'in arayüzüyle konuşur. Payment'a gerçekten erişmek gerekiyorsa Payment tanıdık hale getirilir, ondan ödenen tutarı alma sorumluluğu verilir ve sınıf diyagramına bir ilişki çizgisi daha eklenir.

Böylece 9 prensibe bu prensip de eklenerek toplam 10 prensip anlatılmış oldu.

## 12. Senaryoların gerçeklenmesi ve başlangıç işlemleri

### 12.1 Senaryoların gerçeklenmesi

Yazılan bütün kullanım senaryoları ve varsa bütün kontratlar gözden geçirilip içlerindeki bütün sorumluluklar bu prensiplere (uzman, yaratıcı, iyi uyum, az bağımlılık, denetçi, yapay sınıf, değişimlerden korunma, arabirim, polimorfizm) uygun olarak gerçeklenir. Analiz modelindeki kavramsal sınıflardan yola çıkılarak yazılım sınıfları oluşturulur ve metotlar ilgililerine atanır. Metot burada algoritma demek değildir; yalnız hangi nesnelerin iş birliği yaparak bir hizmet sunacağı gösterilir. Metodun içindeki algoritmanın ayrıca tasarlanması gerekebilir. Her iş birliği sınıf diyagramında sınıflar arasındaki bağlantılar olarak gösterilir.

### 12.2 Başlangıç işlemleri

Slayttaki tanım (ekrandan, 00:55:00):

- Sistem ilk çalışmaya başladığında yapılacaklar ayrı bir senaryo grubu olarak yazılabilir.
- Bu işleri tasarımın en son aşamasında belirlemek uygundur.
- Bir başlangıç nesnesi (initial domain object) belirlenir.
- Program çalışmaya başlayınca bu nesne yaratılır.
- Doğrudan içerdiği diğer nesneleri yaratma ve aralarındaki bağlantıyı sağlama sorumluluğuna sahiptir.
- Tüm programın çalışmasını denetleyen temel bir nesne gibidir. Ancak bu denetim ana programda veya arayüz nesnesinde de olabilir.
- Başlangıçta arayüz nesnelerine denetçinin referansı da gönderilir.

Main metot çalıştığında ne olacağı (kim önce yaratılacak, listeyi kim yaratıp nereden okuyacak, ürün kataloğu kasaya nasıl tanıtılacak) bir senaryo grubu olarak yazılabilir. Önce iş katmanının bütün sorumlulukları bitirilir, sonra sistemin nasıl çalışmaya başlayacağı ortaya konur. Hoca bu nesneyi bir "program denetçisi" gibi düşünmeyi önerdi.

Örnek akış: önce Store yaratılır. Store kataloğu yaratır. Katalog önce boş bir ürün tanımı listesi yaratır, sonra ürün tanımlarını (belki veritabanından) okur, her ProductSpecification'ı yaratıp listeye ekler. Katalog tamamlandıktan sonra Store kasayı yaratır ve kataloğu ona verir. Katalog yaratılmadan kasanın yaratılmaması gibi mantık sırasını başlangıç nesnesi Store sağlar. Bu akış da bir etkileşim diyagramıyla modellenebilir.

## 13. Görünürlük

### 13.1 Tanım ve türleri

Görünürlük bağımlılıkla ilgilidir. B nesnesi A'ya görünürse A, B'ye erişebilir; yani A ancak B görünürse ona mesaj gönderebilir (metodunu çağırabilir). Hocanın anlattığı kademeler:

- Özellik görünürlüğü: B, A'nın bir üyesidir. A yaşadığı sürece (kendi içinde bir organ gibi) B de A'ya görünür kalır.
- Parametre görünürlüğü: B, A'nın bir metodunun parametresidir; yalnız metot çalıştığı sürece A B'ye bağımlıdır. Daha az bağımlılık demek olduğu için tercih sebebidir. "Her şeyi nesnenin içine doldurmayın, mümkün olduğunca parametrede bırakın."
- Parametre bir değişkene atanırsa parametre görünürlüğü özellik görünürlüğüne dönüşür. Nesne yerel ya da global bir değişkene de atanabilir.

> **Hocanın vurgusu:** Global değişkenlere fazla gitmeyin; ne kadar globale bağlarsanız bağımlılığınız o kadar artar.

### 13.2 Örnek

Slayttaki örnek (ekrandan, 01:00:00):

```text
enterItem(id, qty) --> :Register --2: makeLineItem(spec, qty)--> :Sale
                          |                                        |
             1: spec := getSpecification(id)              2.1: create(spec, qty)
                          v                                        v
                    :ProductCatalog                         sl: SalesLineItem
```

Slayttaki kod notları:

```text
{
makeLineItem(ProductSpecification spec, int qty)
{
  ...
  sl = new SalesLineItem(spec,qty);
  ...
}
}

{ // SalesLineItem kurucu metodu
SalesLineItem(ProductSpecification spec, int qty)
{
  ...
  productSpec = spec; // paremetreden niteliğe
  ...
}
}
```

Slayttaki not: "Çoğunlukla parametre görünürlüğü nitelik görünürlüğüne dönüşür. Örneğin SalesLineItem kurucusuna gelen spec paremetresi gibi."

Kasaya ürün okutulduğunda barkod (item ID) ve miktar bilinir. Register, ProductCatalog'dan `getSpecification(id)` çağırır ve dönen nesneyi `spec` değişkenine atar. Hoca bunu özellik görünürlüğü olarak anlattı: atadığı için nesne onunla birlikte yaşamaya devam eder. Sonra Register `spec`'i Sale'e verir; Sale onu hiçbir şey yapmadan doğrudan başka bir nesneye (yeni SalesLineItem'a) iletir. Böylece Sale, ProductSpecification'a yalnız bu metot çalıştığı süre boyunca görünür; ona bağlı değildir, onu kullanmaz. Bu parametre görünürlüğüdür ve bağımlılığı sınırlar.

> **Ders sonrası not:** Hoca Register'daki `spec := getSpecification(id)` atamasını özellik görünürlüğü olarak anlattı. Larman'ın sınıflandırmasında metodun içindeki bir değişkene atanan nesne büyük olasılıkla yerel (local) görünürlük örneğidir; özellik (nitelik) görünürlüğü ise nesnenin bir üye değişkene atanmasıdır, slayttaki `productSpec = spec;` ataması gibi.

Hoca bunu yüzde yüz bir kanun olarak değil, uyulursa iyi olacak bir öneri olarak özetledi: değişkenlere atanan nesne sayısı arttıkça sınıf onlara bağlanır; parametre seviyesinde kalmaları tercih edilir.

## 14. Tasarım sınıf diyagramı ve bağımlılıklar

### 14.1 Tasarım sınıf diyagramı

Sorumluluklar atanıp metotlar bulundukça bir yandan yazılım sınıflarından oluşan tasarım sınıf diyagramı oluşturulur. Bu diyagramda yazılım sınıfları, özellikleri ve tipleri, metotları, metotların parametreleri ve erişim hakları (eksikler kalabilse de büyük ölçüde) belirtilir. Sınıflar arasındaki ilişkiler ve bağımlılıklar yönlü olarak gösterilir (navigability): bu buna bağlıdır, bu bunu çağırır.

Slayttaki örnek (ekrandan, 01:05:00):

| Sınıf | Özellikler | Metotlar |
|---|---|---|
| Store | address : Address, name : Text | addSale(...) |
| ProductCatalog | ... | getSpecification(...) |
| ProductSpecification | description : Text, price : Money, itemID : ItemID | ... |
| Register | (yok) | endSale(), enterItem(...), makeNewSale(), makePayment(...) |
| Sale | date : Date, isComplete : Boolean, time : Time | becomeComplete(), makeLineItem(...), makePayment(...), getTotal() |
| SalesLineItem | quantity : Integer | getSubtotal() |
| Payment | amount : Money | ... |

| Kaynak | İlişki | Hedef | Çoğulluk |
|---|---|---|---|
| Store | Uses | ProductCatalog | 1 — 1 |
| Store | Houses | Register | 1 — 1 |
| Register | Looks-in | ProductCatalog | 1 — 1 |
| ProductCatalog | Contains | ProductSpecification | 1 — 1..* |
| Register | Captures | Sale | 1 — 1 |
| Sale | Contains | SalesLineItem | 1 — 1..* |
| SalesLineItem | Describes | ProductSpecification | * — 1 |
| Sale | Paid-by | Payment | 1 — 1 |
| Store | Logs-completed | Sale | 1 — * |

Kesik çizgili bağımlılıklar: Register → ProductSpecification ve Sale → ProductSpecification.

Hocanın anlatımı: dükkânın adresi ve adı, satış ekleme metodu vardır. Dükkân ürün kataloğunu kullanır; katalog n tane ürün tanımı içerir. Dükkân kasaya ev sahipliği yapar; kasa denetçidir (satışı başlatma, bitirme, ödeme alma, ürün okutma). Kasa satışı içerir; satış, satır yaratma, toplam hesaplama ve ödeme alma sorumluluklarına sahiptir; tarih, tamamlandı mı (Boolean) ve zaman nitelikleri vardır. Satış kalemlerinin miktarı ve uzman kalıbında bulunan `getSubtotal()` sorumluluğu vardır; fiyatı okuduğu için ProductSpecification'a bağlıdır. Satış ödeme aldığına göre Payment ile ilişkisi vardır.

### 14.2 Bağımlılık ilişkileri

Özellik görünürlüğüyle oluşan bağlantılar düz çizgilerle gösterilir; asıl önemli olan gizli bağımlılıklardır. Kodda "tanıdığın tanıdığına" erişildiği yerler de modelde bağımlılık ilişkisi olarak gösterilmelidir. Kasa, ürün kataloğu üzerinden ProductSpecification'a erişir; yani kasa ona bağımlıdır. Satış da satış kalemleri üzerinden ProductSpecification'a bağımlıdır. Bunlar kesik çizgilerle gösterilir.

> **Hocanın vurgusu:** Bu kesik çizgiler ne kadar fazlaysa tasarımınız o kadar kötüdür.

ProductSpecification değiştiğinde normalde yalnız ona "contains" ile bağlı katalog ve "describes" ile bağlı satış satırı kontrol edilecekti; ama Register ve Sale de ona bağımlı olduğu için onlar da kontrol edilmelidir. Bağımlılık böyle zincirleme büyür; bu yüzden kesik çizgiler yaratmamaya çalışılmalıdır.

## 15. Tasarımdan kodlamaya

Hocanın özetiyle nesneye yönelik tasarım şöyle yapılır: bütün senaryolardaki sorumluluklar bulunur; her biri bir uzmana atanır; sorumluluk yerine getirilirken hangi nesnelerin nasıl birlikte çalışacağı işbirliği ya da ardışıl diyagramlarla gösterilir. Yani sorumluluk sayısı kadar etkileşim diyagramı gerekir. Hepsi bir tasarım sınıf diyagramında gösterilir ve kodlamaya geçilir.

Kodlamada sınıf tanımları tasarım sınıf diyagramından, metotlar ise etkileşim diyagramlarındaki birlikte çalışma şeklinden oluşturulur. Diyagramlar düzgün çizilirse CASE araçları şablonları üretebilir: satış toplamındaki gibi bütün koleksiyona döngüyle mesaj gönderme kısmını otomatik oluşturur; geliştirici yalnız algoritmadaki toplama, çarpma gibi işleri kodlar.

Kodlamaya mümkün olduğunca en az bağımlı sınıftan başlayıp en çok bağımlı sınıfa doğru gidilmelidir; böylece çok bağımlı sınıf ihtiyaç duyduğu diğer sınıfları hazır bulur.

> **Hocanın vurgusu:** Her sınıfınızı mutlaka birim testinden (unit test) geçirin.

Test güdümlü geliştirmede (test driven development) test programları uygulamadan önce yazılır; test uygulaması nesneleri yaratır, bütün mesajları çalıştırıp sonuçları kontrol eder. Bu yaklaşım yaklaşık iki, iki buçuk kat efor ister.

Böylece uygulama tasarımı tamamlandı: işlevsel çözümlemede yapı diyagramları ve HIPO ile, nesneye yönelik çözümlemede kavramsal sınıf diyagramı ve kullanım senaryolarından yola çıkarak.

## 16. Veri tasarımı ve veritabanı tasarım aşamaları

Dersin ikinci yarısında yeni slayt setine geçildi (ekrandan, 01:10:00). Konu sistem tasarımının veri tarafıdır: veri modelleme ile veri yapısı ve veritabanı tasarımı. Veri nasıl modellenmeli, veri yapıları ve veritabanı nasıl ifade edilmeli, bunun için hangi diyagramlar çizilmeli?

Veritabanı tasarımının aşamaları:

- Analiz: hangi şeylerle ilgili bilgi tutulacağı burada ortaya çıkar; maliyet analizleri ve fizibilite de veritabanı tasarımına ışık tutar.
- Kavramsal ve mantıksal tasarım (ön ve ayrıntılı tasarım): işlevler, sınıflar ya da modüller oluşturulurken varlıklar, varlıkların nitelikleri ve aralarındaki ilişkiler belirlenir.
- Normalizasyon: veritabanı iyileştirilir (optimize edilir). Bunun kuralları vardır ama bu ders kapsamında değinilmedi.
- Gerçekleştirme: kodlamaya paralel olarak veritabanı tarafında tablolar ve kısıtlar yaratılır, güvenlik ve haklar tanımlanır, sistemin çalışması için gereken ilk veriler yüklenir. Kullanım senaryolarına göre bazı kodlar da veritabanında gerçekleştirilebilir; özellikle raporlamada stored procedure'lar faydalıdır.

Dersin odağı, tasarlanan sistemin verisinin nasıl tasarlanacağıdır. Veri modeli varlık-ilişki modeli (Entity Relationship, ER) ile gösterilir.

## 17. Veri modelleri

Slayttaki özet (ekrandan, 01:15:00):

- Varlık-İlişki Modeli (Entity-Relationship Model)
  - Kavramsal tasarımda veritabanında tutulacak verilerin daha üst seviyede gösterilmesi için
  - Kavramsal tasarım için en çok kullanılan ve en popüler model
  - Diğer modeller?
    - Sıradüzensel: kayıt kütükleri
    - Yarı yapılı veri modeli: XML
    - Nesneye dayalı model: kavramsal nesneler
    - Yapılanmış bellek: NoSQL, MongoDB, AllegroGraph, ...

Hocanın açıklamaları:

- Sıradüzensel model eskiden kalmadır: C'deki struct'ları bir dosyaya yazmak gibi, veriyi doğrudan dosya (kayıt kütüğü) halinde tutmaktır.
- Yarı yapılı modelin en güzel örneği XML'dir; özellikle sistemler arası veri aktarımında kullanılır. Yarı yapılıdır, çünkü veriyi tanımlayan ve geçerleyen bilgi de veriyle birlikte tanımlanır.
- Nesneye dayalı model (nesne veritabanları) 90'ların sonu ile 2000'lerde yaygınlaşmaya çalıştı ama tutmadı. Nesneye yönelik programlama fiili standart oldu, ama ilişkisel veritabanları daha eski, daha güçlü ve daha verimli olduğu için saf nesne veritabanları özellikle performans yüzünden yaygınlaşmadı. Bunun yerine Object Relational Mapping kullanılır: altta ilişkisel bir veri katmanı vardır, üstündeki dönüşüm katmanı tablolardaki verileri get/set metotları olan nesnelere çevirir. Bunu yapan hazır framework'ler vardır; kavramsal sınıfların verileri bu sayede doldurulur ya da ilişkisel tablolara kaydedilir.
- Yapılanmış bellek: NoSQL veritabanları (MongoDB), AllegroGraph gibi graf veritabanları; günümüzde Redis gibi bellek içi çözümler ve Firebase gibi çözümler de revaçtadır.

Derste bunların hiçbirine değil, en çok kullanılan varlık-ilişki modeline odaklanıldı.

## 18. Varlık-ilişki modeli: varlık, nitelik, anahtar, ilişki

### 18.1 Semboller

Hoca modelin basit olduğunu, biraz mantıklı düşünmenin yettiğini söyledi:

- Varlık (varlık kümesi): dikdörtgen.
- Nitelik (özellik, öz nitelik): elips.
- Anahtar nitelik (birincil anahtar, benzersiz tanımlayıcı): altı çizili nitelik.
- İlişki (bağıntı): eşkenar dörtgen (baklava dilimi).
- Varlıkları ve ilişkileri bağlayan çizgiler ve çizgilerin üzerindeki çoğullamalar (sınıf diyagramındaki gibi).

### 18.2 Varlık

Varlık, varlık-ilişki modelinin en temel üyesidir: var olan ve benzerlerinden ayırt edilebilen her şey. Kütüphane bilgi sisteminde kitaplar varlıktır, çünkü kitaplarla ilgili bilgi tutulmalı ve bunlarla işler yapılmalıdır (örneğin yazara göre arama). Öğrenci bilgi sisteminde öğrenci, öğretim üyesi ve ders birer varlıktır; not bir varlık olabilir de olmayabilir de, bu modele göre değişir. Araba da bir varlık olabilir. Uygulamada hakkında veri tutulması gereken her şey varlıktır.

Veritabanında bir tablo varlıklardan oluşan bir kümedir: her satırda tekil bir varlık, her sütunda o varlığın bir niteliği yer alır.

### 18.3 Nitelik

Varlıkların özelliklerine nitelik denir. Öğrenci varlığının adı, soyadı, numarası, doğum tarihi, ev adresi gibi nitelikleri olur; varlık hakkında tutulan bütün veriler niteliktir. Oval içinde adlarıyla gösterilir. Tabloda her sütun bir niteliktir.

### 18.4 Anahtar nitelik

Slayttaki tanım (ekrandan, 01:25:00): "Bir niteliğin değeri her bir varlık için farklıysa bu nitelik anahtar nitelik olarak belirlenir. Şemada niteliğin altı çizilerek gösterilir." Slayttaki örnekte Personel varlık kümesinin nitelikleri `id` (altı çizili), `ad`, `gorev` ve `maas`tır.

Sicil numarası her personel için ayrıdır; kimlik numarası gibi düşünülebilir. Veritabanındaki her tekil varlığa benzersiz olarak erişebilmek için anahtar gerekir. Hocanın örneği: ülkedeki bütün vatandaşlara tek tek erişmek için yalnız ad soyad yetmez, çünkü aynı ad soyadlı birçok kişi vardır. Baba adı eklenir, yine yetmez; anne adı, doğum yeri eklenir. Kaç niteliği birleştirmek gerekecek? Bu yüzden ID, kod numarası, sicil numarası gibi genellikle sayısal, tekrar etmeyen değerler anahtar olarak seçilir. Küçük bir personel kümesinde ad ve soyad birlikte ayırt ediciyse ikisi birlikte de anahtar olabilir. Veritabanlarında anahtarlar genellikle otomatik artan (auto increment) tanımlanır ve hiç tekrar etmez; örneğin müşterilere 1'den n'e kadar numara verilir.

### 18.5 İlişki

Varlık kümeleri arasındaki bağıntılara ilişki denir. Öğrenci bilgi sisteminde öğrenciler ders aldığı için öğrenci ile ders arasında bir "alır" (ya da "kayıt") ilişkisi vardır. İlişki eşkenar dörtgenle gösterilir, içine adı yazılır. İlişkiler her zaman bire bir, bire n (ya da n'e bir) veya n'e m şeklindedir.

Slayttaki örnek (ekrandan, 01:30:00):

```text
 (sno)  (isim)  (kazanç)          ('den beri)          (dno)  (dep_ad)  (bütce)
    \     |      /                    |                   \      |       /
    [ personel ] -------------- < çalışan > -------------- [ Departman ]

 sno ve dno altı çizili (anahtar nitelik)
```

Personelin sicil numarası (anahtar), ismi ve kazancı (maaşı) vardır. Departmanın numarası (anahtar), adı ve bütçesi vardır. Personel departmanda çalışır: "çalışan" ilişkisi.

İlişkilerin kendi nitelikleri de olabilir. Bir personelin bir departmanda hangi tarihten beri çalıştığı bilgisi ilişkinin kendisine aittir. Personele konamaz: personel birden fazla departmanda çalışabilir, sicil numarası benzersiz olduğu için personel kaydı kopyalanamaz. Departmana da konamaz: personel o departmanda çalışmıyorsa bu nasıl gösterilecek? Bu çalışma ilişkisinin kendi özelliğidir: "satış departmanında 2011'den beri, pazarlama departmanında 2014'ten beri" gibi her biri ayrı bir satır oluşturur. İlişki nitelikleri özellikle çoka çok ilişkilerde sık kullanılır.

## 19. İlişki tipleri

### 19.1 Bire bir

Bire bir ilişki çok sık görülmez. Hocanın örneği: bir tarafta erkek, bir tarafta kadın varlık kümesi ve evlilik ilişkisi; bir kümedeki her nokta diğer kümede yalnız bir noktayla ilişkilidir.

### 19.2 Bire n

En çok görülen tiplerden biridir: birinci kümedeki bir varlık diğer kümedeki birden çok varlıkla ilişkili olabilir, ama ikinci kümedeki her varlık birinci kümede en çok bir varlıkla ilişkilidir. Örnek: bölüm ile öğrenci (çift anadal olmadığı varsayılarak). Bir bölümde n öğrenci okur, ama bir öğrenci yalnız bir bölümde okur. Hoca liselerdeki alan ayrımını (fen, sosyal, Türkçe-matematik, yabancı dil) örnek verdi: aynı anda birden fazlasında olunamaz, ama bir alanda birçok öğrenci olabilir. Bu "okuma" ilişkisidir.

### 19.3 Çoka çok (n-m)

Slayttaki tanım (ekrandan, 01:35:00): "Çoka-çok ilişki: Bir ilişkide herhangi bir kümede bulunan varlıklardan herbiri diğer kümede bulunan birçok varlıkla ilintilidir. Birincil anahtarları A ve B tablolarının yabancı anahtarlarından oluşan, bağlantı tablosu diye adlandırılan üçüncü bir tablo tanımlayarak oluşturulur."

Slayttaki şekilde üç Ders kutusu (hoca 1, 2, 3 diye numaraladı) "Aldığı" ilişkisiyle üç Öğrenci kutusuna (A, B, C) bağlanır. Hoca dersleri Türkçe, matematik, müzik diye örnekledi: birinci dersi A ve B alabilir, A aynı zamanda ikinci ve hatta üçüncü dersi de alabilir. Bir tarafta n, diğer tarafta m varlık ilişkiye giriyorsa bu çoka çok ilişkidir. Hoca dersleri ayrı kutular halinde çizmenin yalnız anlatım için olduğunu, normalde böyle gösterilmediğini belirtti.

Bire n'de bir taraf sabit olduğu için ilişki kurmak kolaydır. Çoka çok ilişkide ise her varlık kümesi bir tablo olur ve çok dersi çok öğrenciyle eşleştirmek için üçüncü bir bağlantı tablosu gerekir. Bu tablonun her satırı "A öğrencisi birinci dersi şu dönemde aldı", "B öğrencisi üçüncü dersi şu dönemde aldı" gibi bir eşleşmedir. İki taraftaki varlıkların birincil anahtarları (öğrenci numarası ve ders kodu) bu tabloda yabancı anahtar olarak tutulur.

### 19.4 Örnek: kitapçı veritabanı

Slayttaki diyagram (ekrandan, 01:40:00), "Kitapçı Veritabanı (Varlık-İlişki Diyagramı)":

| Varlık | Nitelikler (anahtar ilk sırada) |
|---|---|
| KİTAP | ISBN (anahtar), Başlık, YayınevID, Fiyat |
| YAZAR | YazarID (anahtar), Yazar Adı, Yazar Soyadı, Yazar Telefon No |
| YAYINEVİ | YayınevID (anahtar), Yayınevi Adı, Yayınevi Telefon No |

- KİTAP (∞) — "Tarafından Yazılmış" — (∞) YAZAR
- KİTAP (∞) — yayınlanma ilişkisi — (1) YAYINEVİ

<!-- BELİRSİZ: KİTAP-YAYINEVİ ilişkisinin slayttaki adı karede küçük yazılı; "Yayınlanmış olma" gibi okunuyor. -->

Bir yayınevi birden fazla kitap yayınlayabilir. Bir kitabın birden fazla yazarı olabilir ve bir yazar birden fazla kitap yazabilir; bu yüzden kitap-yazar ilişkisi n'e n'dir (n ya da sonsuz işareti konabilir). "Tarafından yazılmış" ilişkisine yazım tarihi gibi bir nitelik eklenebilir.

Kitaptaki YayınevID, yayınevinin birincil anahtarıdır ve kitapta yabancı anahtar (foreign key) olarak durur; bire n ilişki bu sayede sağlanır. Hocanın slayta yazdığı tablo (ekrandan, 01:40:00):

| Kitap | Başlık | Yayınevi |
|---|---|---|
| K1 | başlık1 | Y1 |
| K2 | başlık.. | Y1 |
| K3 | baa | Y1 |
| K4 | başlık | Y2 |

| Yayınevi | Adı |
|---|---|
| Y1 | Altın |
| Y2 | gümüş |

Y1'in üç kitabı, Y2'nin bir kitabı vardır: bir yayınevi n kitap. Kitap ile yazar arasında ise bir kitap birden çok yazarla eşleşeceği için bu bilgi ayrı bir yerde tanımlanmalıdır.

## 20. Varlık-ilişki diyagramını tablolara dönüştürme

Varlık kümeleri veritabanında tablolara, nitelikler sütunlara dönüşür. Anahtar sütunlar varlık-ilişki modelindeki birincil anahtarlardan belirlenir.

### 20.1 Bire bir

Sorun yoktur: iki taraftan biri seçilir; birinin birincil anahtarı diğerinde yabancı anahtar olarak kullanılır. Hangisinin seçileceği tasarımcıya kalmıştır.

### 20.2 Bire n

n tarafındaki tabloya 1 tarafındaki tablonun birincil anahtar sütunu yabancı anahtar olarak eklenir.

Hocanın örneği: bir bölümde n personel çalışır. Bölümün ID'si ve adı, personelin ID'si, adı, soyadı, adresi ve maaşı vardır. Personel tablosunun birincil anahtarı personel ID'sidir (altı çizili). Bölüm ID'si personel tablosunda yabancı anahtardır. Hoca bu derste yabancı anahtarın üstünün çizilerek gösterildiğini, slayttaki altı çizili gösterimin yanlış olduğunu söyledi ve düzeltti.

Hocanın elle yazdığı örnek tablolar (değerler altyazıdan; kişi adları genel adlarla değiştirildi):

| Bölüm ID | Bölüm adı |
|---|---|
| 011 | Bilgisayar Mühendisliği |
| 012 | Elektronik ve Haberleşme Mühendisliği |

| Personel ID | Ad | Bölüm ID (yabancı anahtar) |
|---|---|---|
| 123 | Personel 1 | 011 |
| 124 | Personel 2 | 011 |
| 125 | Personel 3 | 012 |
| 126 | Personel 4 | 012 |

<!-- BELİRSİZ: Bu tablolar elle yazıldı ve okunan karelerde görünmüyor; personel ID değerleri altyazıdan (Whisper "1, 2, 3" diye yazmış, büyük olasılıkla 123). -->

011'lik iki personel ve 012'lik iki personel kendi bölüm satırlarına bağlanır; böylece "bir bölümde n personel çalışır" bağlantısı kurulur.

### 20.3 Çoka çok

Varlık kümeleri tablolara, ilişki de ayrı bir tabloya dönüştürülür. Nitelikler sütun olur. İki varlığın anahtar nitelikleri ilişki tablosuna sütun olarak eklenir ve orada yabancı anahtar olarak işaretlenir. İlişki tablosunun birincil anahtarı bu iki yabancı anahtarın birleşiminden oluşur; yetmiyorsa ilişki tablosunda yeni bir birincil anahtar yaratılır.

Slayttaki örnek (ekrandan, 01:45:00):

```text
 (filmID) (filmAdi)          (tarih)          (sinemaID) (sinemaAdi)
       \   /                    |                    \   /
      [ Film ] ---n--- < oynar > ---m--- [ Sinema ]
       /   \                    |                    /   \
(y_tarihi) (yonetmen)        (saat)            (adres)  (telefon)

Film   (filmID, filmAdi, y_tarihi, yonetmen)
Sinema (sinemaID, sinemaAdi, adres, telefon)
Oynar  (oynarID, filmID, sinemaID, tarih, saat)
```

Slaytta filmID, sinemaID ve oynarID altı çizili birincil anahtarlardır. Oynar tablosundaki filmID ve sinemaID yabancı anahtarlardır (hoca bunları üstlerini çizerek ve renklerle Film ve Sinema tablolarındaki anahtarlara bağlayarak gösterdi).

Bir film birden fazla sinemada, bir sinemada birden fazla film oynar; oynama ilişkisinin tarih ve saat nitelikleri vardır. Film ve Sinema tablolarında yabancı anahtar yoktur; oynama ilişkisi Oynar tablosunda kurulur.

Normalde (filmID, sinemaID) birlikte birincil anahtar olabilirdi. Ama A filmi B sinemasında bir tarih ve saatte oynarken aynı sinemada başka tarih ve saatlerde de oynayabilir; bu çift benzersiz olmaz. Bu yüzden ayrı bir birincil anahtar, oynarID seçildi. Hocanın elle yazdığı satırlar (altyazıdan):

| oynarID | filmID | sinemaID | tarih |
|---|---|---|---|
| 1 | Film 1 | Sinema 1 | 18.05.2021 |
| 2 | Film 1 | Sinema 1 | ertesi gün |
| 45 | Film 1 | Sinema 1 | 19.06.2021 |
| 67 | Film 2 | Sinema 1 | 19.06.2021 |

<!-- BELİRSİZ: Bu satırlar elle yazıldı ve okunan karelerde görünmüyor; değerler altyazıdan alındı. -->

Böylece çoka çok ilişkili iki varlık kümesi üçüncü bir ilişki tablosuyla gerçeklenir.

Hocanın özeti: varlık-ilişki diyagramının temeli varlıklar, aralarındaki ilişkiler ve bunların taşıdığı bütün niteliklerdir; veritabanında ya da dosyada saklanması gereken her şey bu şekilde tasarlanır.

## 21. Zayıf varlık kümeleri

Slayttaki tanım (ekrandan, 01:50:00):

- Mevcutluğu diğer varlık türüne bağlı olan varlık türüdür.
- Eğer bir varlık kümesinin niteliklerinin tümü alınsa bile bir anahtar oluşturmuyorsa buna zayıf varlık kümesi denir.
- Ör: Üniversite-fakülte ilişkisinde, bir fakülte üniversite olmadan olamayacağı için ve aynı fakülte isminde başka üniversitelerde fakülte olabileceği için fakülte varlık kümesi zayıf varlık kümesidir.

```text
[ Universite ] ---1--- < Aittir > ---n--- [[ Fakulte ]]
                                           (çift çizgili dikdörtgen: zayıf varlık)
```

Bir üniversitedeki fakülte isimleri benzersizdir, ama "mühendislik fakültesi" elli üniversitede vardır. Fakültenin bütün nitelikleri alınsa bile kendi başına bir anlam ifade etmiyor, ancak bir üniversiteye bağlı olarak var olabiliyorsa bu bir zayıf varlık kümesidir. Varlık-ilişki diyagramında iç içe iki dikdörtgenle gösterilir.

Gerçeklemede fakültenin birincil anahtarı yalnız fakülte numarası değil, üniversite numarasıyla birlikte oluşturulur. Hoca bu durumla sık karşılaşılmayacağını düşündüğünü, ama karşılaşılırsa zayıf varlığın, yaşamak için bağlı olduğu varlığın birincil anahtarıyla birlikte tanımlanması gerektiğini söyledi.

Özetle hakkında bilgi tutulması gereken her şey varlık, aralarındaki bağıntılar ilişki olarak modellenir; nitelikler elipslerle, çoğullamalar bağlantılarla gösterilir. Bunlar bir araya gelince veri tasarımı ifade edilmiş olur; veritabanı tabloları halinde gerçeklendiğinde de veri modeli gerçek hale dönüşür.

## Örnek Sorular

**Soru 1** (ekrandan, 00:10:00): Sale (time), SalesLineItem (quantity) ve ProductDescription (description, price, itemID) sınıflarının bulunduğu modelde satışın toplam bedelinin belirlenmesinden kim sorumludur?

> **Çözüm (derste verildi):** Uzman prensibine göre Sale sorumludur, çünkü bütün satış satırlarına sahiptir: `getTotal()` Sale'e atanır. Sale her satıra `getSubtotal()` sorar (miktarı satır bilir), satır da fiyatı `getPrice()` ile ProductDescription'a sorar.

**Soru 2** (derste sözlü, 00:17:39): Barkod okutuldukça yaratılan SalesLineItem nesnelerini kim yaratmalıdır, kasa (Register) mı satış (Sale) mı?

> **Çözüm (derste verildi):** Yaratıcı prensibine göre Sale yaratmalıdır, çünkü satış satırlarını içeren odur. Kasa yaratırsa satışın iç ayrıntılarına gereksiz yere bağımlı olur (az bağımlılık ihlali).

**Soru 3** (ekrandan, 00:50:00): `Money amount = sale.getPayment().getTenderedAmount();` satırının sorunu nedir, nasıl düzeltilir?

> **Çözüm (derste verildi):** Yabancılarla konuşma prensibini ihlal eder; çağıran sınıf tanıdığın tanıdığı olan Payment'a gizlice bağımlı olur. Doğrusu Sale'e yeni bir sorumluluk vermektir: `Money amount = sale.getTenderedAmountOfPayment();`.

**Soru 4** (derste sözlü, 01:29:10): Bir personelin bir departmanda hangi tarihten beri çalıştığı bilgisi hangi varlığa ya da ilişkiye ait olmalıdır?

> **Çözüm (derste verildi):** "Çalışan" ilişkisinin kendisine aittir. Personele konursa birden fazla departmanda çalışan personel için kayıt tekrarlanması gerekir; departmana konursa o departmanda çalışmayan personel için anlamsız olur.

**Soru 5** (ekrandan, 01:45:00): Film (filmID, filmAdi, y_tarihi, yonetmen) ile Sinema (sinemaID, sinemaAdi, adres, telefon) arasındaki tarih ve saat nitelikli n-m "oynar" ilişkisi tablolara nasıl dönüştürülür? (filmID, sinemaID) birincil anahtar olarak yeterli midir?

> **Çözüm (derste verildi):** İlişki ayrı bir tablo olur: Oynar (oynarID, filmID, sinemaID, tarih, saat); filmID ve sinemaID yabancı anahtardır. Aynı film aynı sinemada farklı tarih ve saatlerde oynayabildiği için (filmID, sinemaID) çifti benzersiz değildir; bu yüzden yeni bir birincil anahtar oynarID eklenir.

**Soru 6** (ekrandan, 01:50:00): Üniversite-fakülte ilişkisinde fakülte neden zayıf varlık kümesidir ve birincil anahtarı nasıl oluşturulur?

> **Çözüm (derste verildi):** Fakülte üniversite olmadan var olamaz ve aynı adlı fakülte başka üniversitelerde de bulunur; bütün nitelikleri alınsa bile anahtar oluşmaz. Birincil anahtarı üniversite numarası ile fakülte numarasının birleşimidir; diyagramda çift çizgili dikdörtgenle gösterilir.

## Dersin Toparlaması

Dersin ilk yarısında nesneye yönelik uygulama tasarımı tamamlandı. Senaryolardaki sorumlulukların atanmasında yol gösteren dokuz GRASP prensibi (uzman, yaratıcı, az bağımlılık, iyi uyum, denetçi, çok şekillilik, yapay sınıf, dolaylılık, değişimlerden korunma) ve onuncu olarak yabancılarla konuşma prensibi işlendi. Hepsinin ortak amacı sınıfların kendi içinde uyumlu, birbirine az bağımlı ve değişimlerden korunmuş olmasıdır. Ardından başlangıç işlemleri, görünürlük türleri, tasarım sınıf diyagramı ve gizli bağımlılıkları gösteren kesik çizgiler anlatıldı. Kodlama tasarım sınıf diyagramı ve etkileşim diyagramlarından yapılır; en az bağımlı sınıftan başlanır ve her sınıf birim testinden geçirilir.

İkinci yarıda veri tasarımına geçildi. Veritabanı tasarım aşamaları ve veri modelleri tanıtıldıktan sonra varlık-ilişki modelinin sembolleri, varlık, nitelik, anahtar nitelik ve ilişki kavramları, bire bir, bire n ve çoka çok ilişki tipleri, bunların tablolara yabancı anahtarlar ve bağlantı tablolarıyla dönüştürülmesi ve zayıf varlık kümeleri işlendi. Sonraki derste kodlama teknikleri, yazılım kalitesi, test teknikleri, yeni sisteme geçiş yöntemleri, bakım ve işlevsel ile nesneye yönelik çözümlemeyi birlikte gösteren basit bir vaka çalışması ele alınacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
