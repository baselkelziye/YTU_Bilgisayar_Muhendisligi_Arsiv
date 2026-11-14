# Ders 1 Genişletilmiş Notu: Ders Tanıtımı, Birimler, Temel Tanımlar (Yük, Akım, Gerilim, Güç), Devre Elemanları ve Ohm Kanunu

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Konusu ve Yol Haritası
- 2. Laboratuvar Deneylerinin Konuları ve Mantığı
- 3. Birimler ve Yuvarlama
- 4. Elektrik, Elektron Hareketi ve Potansiyel
- 5. Devre Elemanlarına Genel Bakış
- 6. Bağımsız Kaynaklar
- 7. Bağımlı Kaynaklar
- 8. Pasif Elemanlar: Direnç, Endüktans, Kapasite
- 9. Kablo, Ground, Anahtar ve Sigorta
- 10. Gerilim ve Akım Kaynaklarının Temel İlkeleri
- 11. Yük ve Akım
- 12. DC ve AC
- 13. Gerilim, Güç ve Enerji
- 14. Güç İşareti ve Referans Yönleri
- 15. Ohm Kanunu
- 16. Referans Noktası ve Açık Devre
- 17. Son Örnek: 10 V Kaynak ve 4 kΩ Direnç

## 1. Dersin Konusu ve Yol Haritası

Dersin konusu devre teorisidir. Genel devre elemanlarının tanıtılmasıyla başlanır, DC devre çözümleme teorileri incelenir, sonra bunların AC sürekli sinüzoidal hâldeki karşılıkları görülür. En sonunda çözüm, herhangi bir kaynak durumu için genelleştirilmeye çalışılır.

Bütün bu konularda ilgilendiğimiz temel şey, herhangi bir devre elemanının gerilim ve akım değerleridir. Hoca bunu şöyle özetledi: Bir soruyla karşılaştığınızda sizden istenen, ya bir elemanın üzerinden geçen akım ya da elemanın düğümleri arasındaki gerilim olacaktır. Elemanın harcadığı veya devreye verdiği güç de buradan yola çıkılarak bulunur.

Dönem boyunca izlenecek konu sırası şöyledir:

1. **Temel tanımlar:** Yük, akım, gerilim, güç. Bağımsız ve bağımlı kaynaklar, pasif elemanlar, birimleri ve şematik sembolleri. Ohm yasası ve direnç elemanının matematiksel tanımı.
2. **Kirchhoff'un akım ve gerilim yasaları:** Tek çevreli devreler, seri ve paralel bağlama, gerilim ve akım bölücüler.
3. **Düğüm gerilimleri ve çevre akımları yöntemleri:** Çok gözlü devrelerin çözüm yöntemleri. Denklemlerin matris biçiminde yazılması ve çözülmesi. Süper düğüm ve süper çevre gibi özel durumlar.
4. **Devre teoremleri:** Önce devre elemanlarının doğrusallık ve toplamsallık sağladığı gösterilir. Ardından kaynak dönüşümü, Thevenin ve Norton teoremleri, maksimum güç teoremi gelir. Bu teoremler yalnız DC'de geçerli değildir. AC sürekli sinüzoidal hâlde ve herhangi bir kaynak durumunda da tanımlanabilir, yani bir kez öğrenildiğinde uygulaması genelleştirilebilir.
5. **İşlemsel kuvvetlendirici (op-amp):** Şimdiye kadarki elemanlardan farklı olarak çok terminalli bir elemandır ve analog bilgisayarın temelindedir. Toplama, çıkarma, fark alma işlemleri yapılır, başka elemanlarla birleştirilerek integral ve türev de alınabilir. Elemanın tanım bağıntısı, ideal çalışma mantığı ve gerçek bir op-amp'ın nasıl modellendiği görülür.
6. **RL ve RC devreleri:** Tek çevrimli ve kaynaksız durumlar. Anahtarlama mantığı, yani devreye bir anda gerilim verildiğinde veya gerilim bir anda kesildiğinde devrenin nasıl davrandığı.
7. **Sinüzoidal analize giriş:** Kaynağın sinüzoidal olduğu özel AC durumu. Sürekli sinüzoidal hâlde elemanların tanım bağıntıları ve frekans düzleminde analiz.
8. **Sürekli sinüzoidal hâlde devre teoremleri:** DC için görülen teori ve teoremler burada tekrarlanır ve geçerli oldukları görülür.
9. **Frekans cevabı:** Q faktörü, Bode diyagramları ve süzgeç (filtre) devreleri. Burada bir tasarım da söz konusudur: Belli bir frekans bandını geçiren veya süzen bir filtre tasarlamak istenir.
10. **Laplace dönüşümü ve s-domeni:** Herhangi bir genel kaynak için devre çözümü sağlayan yöntem. Laplace ve ters Laplace dönüşümü ile devre elemanlarına uygulanışı. Hoca, konu akışında yetişmezse bu kısmın kapsam dışında bırakılabileceğini söyledi.

<!-- BELİRSİZ: 00:10:55 civarında integral ve türev alma için "RL, RLC devresiyle" denildi; hangi elemanların kastedildiği altyazıdan net değil. Bu yüzden metinde "başka elemanlarla" yazıldı. -->

Dersin temel kaynağı *Engineering Circuit Analysis* kitabının dokuzuncu baskısı, yardımcı kaynağı *Introduction to Electric Circuits* kitabının dokuzuncu baskısıdır.

## 2. Laboratuvar Deneylerinin Konuları ve Mantığı

Beş deneyin konuları sırasıyla şöyledir:

1. Ohm kanunu.
2. Kirchhoff akım ve gerilim kanunu üzerinden devre çözümleme.
3. Devre teoremleri.
4. RC devreleri.
5. İşlemsel kuvvetlendiriciler.

**Soru:** Deneylerde tam olarak ne yapacağız?

**Cevap:** Bir devre şeması verilir. Yüz yüze eğitimde bu şema deney setleri üzerinde fiziksel olarak kurulur, ölçüm alınır ve teorik hesapla ölçümün nasıl örtüştüğü incelenir. Yüz yüze eğitim olmadığında aynı devre simülasyon ortamında kurulur ve ölçümler simülasyon şematiği üzerinden yapılır. Simülasyon programı olarak Proteus 6.9 planlanmıştır. Devreyi kurar, ölçüm yapar, teorik işlemleri yapar ve ölçümle teori arasında fark varsa bunu açıklamaya çalışırsınız. Özellikle RC devresi deneylerinde, devrede arka planda ne olup bittiğinin de anlatılması istenir.

## 3. Birimler ve Yuvarlama

### 3.1 SI Birim Sistemi

Birimler bizim için önemlidir, çünkü formüllerde doğru biçimde verilmeleri gerekir. Derste SI birim sistemi kullanılacak. Bu, 1960 yılında standartlaşmış ve temel fiziksel ölçümler için birimler tanımlayan bir sistemdir.

Formüllerde değerleri orijinal birimleriyle kullanmakta fayda vardır. Hocanın örneği: Bir devre şemasında 1 kΩ'luk bir direnç olsun. Ohm kanununda akım, gerilim bölü direnç olarak hesaplanırken gerilim volt, direnç ohm cinsinden verilir. Dolayısıyla kilo-ohm olarak verilen eleman, formüle 1000 Ω olarak girilmelidir.

Slaytta sayılan birimler uzunluk için metre, kütle için kilogram, zaman için saniye, akım için amper, sıcaklık için kelvin, aydınlatma için kandela ve yük için coulomb idi. Derste ayrıca endüktans için henry, kapasite için farad birimleri tanımlanacaktır.

> **Ders sonrası not:** Hoca coulomb'u bu listede temel birimlerle birlikte saydı. Büyük olasılıkla SI'ın yedi temel birimi metre, kilogram, saniye, amper, kelvin, mol ve kandeladır; coulomb ise türetilmiş bir birimdir ($1\ \text{C} = 1\ \text{A} \cdot \text{s}$). Büyük olasılıkla kandela da "aydınlatma"nın değil, ışık şiddetinin birimidir.

### 3.2 Ön Ekler

Değerler çok küçük veya çok büyük olabilir. Bunları $10$'un kuvvetleriyle yazmak yerine kısaca göstermek için birimin başına ön ek getirilir.

| Ön ek | Çarpan | Ön ek | Çarpan |
|---|---|---|---|
| kilo | $10^{3}$ | santi | $10^{-2}$ |
| mega | $10^{6}$ | mili | $10^{-3}$ |
| giga | $10^{9}$ | mikro | $10^{-6}$ |
| tera | $10^{12}$ | nano | $10^{-9}$ |
| peta | $10^{15}$ | piko | $10^{-12}$ |
| eksa | $10^{18}$ | femto | $10^{-15}$ |
|  |  | atto | $10^{-18}$ |

Bu derste karşılaşma ihtimali yüksek olanlar küçük tarafta mili, mikro, nano ve piko, büyük tarafta kilo ve megadır. Örneğin kapasite elemanlarıyla işlem yaparken $10^{-12}$ mertebesinde pikofarad değerleri kullanılabilir.

> **Hocanın vurgusu:** $10^{-3}$ mili, $10^{-6}$ mikro, $10^{-9}$ nano, $10^{-12}$ piko, $10^{3}$ kilo ve $10^{6}$ mega değerlerini bilmekte ve hatırlamakta fayda var.

### 3.3 Birim Dönüşümü Örneği

Hız, birim zamanda kat edilen mesafedir. Hocanın örneğinde bir cisim 1 dakikada 4000 metre yol alıyor.

Hoca önce şu uyarıyı yaptı: Doğrudan "mesafe bölü süre" diyerek 4000 metre bölü 1 dakika işlemi yapılırsa hatalı bir sonuç elde edilir. Çünkü SI'da mesafenin temel birimi metre olsa da süre saniye cinsinden verilmelidir. Hız km/sa olarak isteniyorsa da ilgili dönüşüm yapılmalıdır.

- **Verilen:** $4000$ m, $1$ dk.
- **Mesafenin dönüşümü:** $4000\ \text{m} = 4\ \text{km}$.
- **Sürenin dönüşümü:** 1 saat 60 dakika olduğuna göre $1\ \text{dk} = \frac{1}{60}\ \text{sa}$.
- **İşlem:** 4 kilometre, saatin 60'ta birinde kat ediliyor:

$$
\frac{4\ \text{km}}{\frac{1}{60}\ \text{sa}} = 240\ \text{km/sa}
$$

Sonuç python ile hesaplandı: 240 km/sa.

Hoca buradan üç kural çıkardı. İstenen sonucun birimi net olarak verilmişse o birim üzerinden hareket edilir. Verilmemişse işlem standart birimlerle yapılır. Üçüncü yol olarak, işleme hangi birimlerle girildiyse sonucun da o birimlerden çıktığı hatırlanmalıdır.

> **Ders sonrası not:** Hoca 4000 m bölü 1 dk işlemine "hatalı" dedi. Bu işlemin kendisi yanlış değildir, sonucu 4000 m/dk'dır. Hatalı olan, bu sayıyı m/s veya km/sa gibi başka bir birimde okumaktır. Hocanın sıraladığı üçüncü kural da bunu söyler.

### 3.4 Diğer Birim Sistemi ve Standartlar

Yalnız SI sistemi yoktur. CGS sisteminde uzunluk metre yerine santimetre, kütle kilogram yerine gram cinsindendir. Doğrudan dersin konusu olmadığı için referans olarak bırakıldı. Birim dönüşüm tabloları, kuvvet formülleri ve gösterim standartları da slaytta referans olarak bırakılıp geçildi.

<!-- BELİRSİZ: 00:33:48-00:37:49 arasında CGS tablosu, dönüşüm tablosu, kuvvet formülleri ve gösterim standartları slaytta geçiyor, içerikleri altyazıda okunmuyor. -->

Birimlerin kendisi de birer standarttır. Hoca bunları gözleme dayalı standartlar olarak anlattı:

- **Metre:** Işığın vakum ortamında kat ettiği mesafeyle birlikte tanımlanır.
- **Kütle:** 4 derecedeki suyun belirli bir hacminin kütlesi olarak tanımlanır.
- **Saniye:** Bir sezyum atomunun ışınımıyla ilgili olarak tanımlanmış bir süredir.

Diğer birimler de bu standartlar referans alınarak tanımlanır. Hocaya göre günümüzde bu tanımlar, daha az değişime uğrayan atomik veya elementer yapılarla değiştirilmiştir, ama temelde gözleme dayalı standartlar olarak ortaya çıkmışlardır.

> **Ders sonrası not:** Hoca saniye tanımında "radyoaktif" sezyum atomu dedi. Büyük olasılıkla tanımda kullanılan sezyum-133 kararlı bir izotoptur, radyoaktif değildir.

> **Ek bilgi (derste anlatılmadı):** Kısa nottaki tanımlara göre metre büyük olasılıkla ışığın boşlukta $\frac{1}{299\,792\,458}$ saniyede aldığı yoldur. Saniye büyük olasılıkla sezyum-133 atomunun belirli bir geçişinde yayılan ışımanın $9\,192\,631\,770$ periyodudur. Kilogram da büyük olasılıkla 2019'dan beri Planck sabitiyle tanımlanmaktadır.

### 3.5 Yuvarlama

Hesaplarda anlamlılık ve yuvarlama konusuna da dikkat etmek gerekir. Yuvarlama yaparken gördüğümüz en düşük anlamlı basamak 5 veya üzerindeyse bir üst basamak artırılır.

Hocanın slayttaki örneği 3,186 sayısıdır:

- **Ondalıktan sonra iki basamak:** Son basamak 6 olduğu için bir üst basamak yukarı yuvarlanır: 3,19.
- **Ondalıktan sonra tek basamak:** 3,19'daki 9 yukarı yuvarlanır: 3,2.

Hoca, en düşük basamaktan başlayarak adım adım gelmekte fayda olduğunu söyledi.

> **Ders sonrası not:** Hoca ilk adımı "iki basamak anlamlılık" diye adlandırdı; 3,19 sonucu ondalıktan sonra iki basamak demektir. Adım adım yuvarlama önerisi de genel olarak güvenli değildir. Hocanın 3,186 örneğinde iki yol da 3,2 verir. Kısa nottaki 3,146 örneğinde ise adım adım yol 3,15 üzerinden 3,2 verirken, doğrudan bir ondalık basamağa yuvarlama 3,1 verir. İki sonuç da python ile hesaplandı. Yuvarlamayı doğrudan asıl sayıdan yapmak gerekir.

## 4. Elektrik, Elektron Hareketi ve Potansiyel

### 4.1 Elektrik Akımının Yönü

Elektrik, yüklerin taşınımıyla ortaya çıkan bir durumdur. Aslında hareket eden şey elektrondur, ama elektronun hareket yönü ile elektrik akımının yönü birbirine terstir. Bunu şöyle düşünebiliriz: Negatif yükler sol tarafa doğru birikirken, tersinden bakınca pozitif yükler sağ tarafa ilerliyor gibidir.

### 4.2 Elektron Hareketinin Kaynakları

Elektronun hareketini sağlayan iki temel etki vardır: ortam sıcaklığı ve uygulanan elektriksel gerilim farkı. Oda sıcaklığında bir tele lokal olarak bakarsak elektronların belirli bir hareketi olduğunu görürüz, ama ortalamada bu net bir akım oluşturacak seviyede değildir. Benzer biçimde pozitif ve negatif yüklü iyonlar da bir gerilim farkı oluşturacağı için elektron hareketini sağlayabilir. Her durumda elektron hareketinin ters yönü, elektrik akımının yönü olarak tanımlanır.

### 4.3 Su Benzetmesi

Elektrik akımını gözümüzde canlandırmak için suyun yüksekten akışını düşünebiliriz. Su yüksek noktadan alçak noktaya, yani yüksek potansiyelden düşük potansiyele doğru hareket eder. Suyun akışı için gereken potansiyel enerjiyi yükseklik farkı sağlar. Bunun elektrikteki karşılığı gerilim, yani potansiyel farktır. Elektriksel seviyeler arasında bir fark oluşturarak veya mevcut bir farkı uygulayarak bu potansiyel enerji elde edilir ve hareketle birlikte kinetik enerjiye dönüşür.

### 4.4 Referans Noktası ve Voltaj

Çizeceğimiz her devre şematiğinde bir referans noktası olacak ve bütün gerilimler bu noktaya göre tanımlanacak. Bu noktanın değeri 0 V kabul edilir. Düğümler bu referansa göre daha yüksek veya daha düşük bir potansiyelde olabilir. Referansa göre farklı bir elektrik potansiyeline sahip noktanın bu değerine voltaj denir ve büyük $V$ harfiyle gösterilir. Su benzetmesindeki gibi, elektrik akımını ortaya çıkaran şey bu potansiyel farktır.

### 4.5 Akımı Artıran Etkenler

Hoca iki etken saydı. Serbest elektron miktarı ne kadar fazlaysa o kadar fazla akım sağlanabilir. Elektronlara kuvvet uygulayan potansiyel ne kadar yüksekse akım da o mertebede yüksek olur. Yani elektronun hareket miktarı doğrudan potansiyelle ilişkilidir.

## 5. Devre Elemanlarına Genel Bakış

### 5.1 Aktif ve Pasif Elemanlar

Standart devre elemanları aktif ve pasif olarak iki ana başlıkta incelenir. Aktif elemanlar devreye enerji veren elemanlardır. Bağımsız kaynaklar ve bağımlı kaynaklar olarak ikiye ayrılırlar, ikisinin de gerilim ve akım kaynağı versiyonları vardır.

- **İdeal bağımsız gerilim kaynağı:** Üzerinden geçen akım ne olursa olsun sabit bir gerilim sağlar.
- **İdeal bağımsız akım kaynağı:** Üzerindeki gerilim düşümü ne olursa olsun, bağlı olduğu kolda üzerinde yazılı değerde akım sağlar.
- **Bağımlı kaynak:** Devrenin başka bir kolundaki veya düğümündeki gerilime ya da akıma bağlı olarak gerilim veya akım üretir.

Pasif elemanlar devrede güç tüketen elemanlar olarak tanımlandı. Bunlar direnç (rezistör), kapasite (kapasitör) ve endüktans (indüktör) elemanlarıdır.

> **Ders sonrası not:** Hoca pasif elemanların hepsine "güç tüketen" dedi. Direnç için bu doğrudur. Endüktans ve kapasite ise büyük olasılıkla enerjiyi harcamaz, depolar ve sonra devreye geri verebilir; kısa not da "harcar veya depolar" ifadesini kullanır.

### 5.2 Ampermetre ve Voltmetre

Ölçüm için ampermetre ve voltmetre kullanılır. İdeal ampermetre kısa devre elemanı gibi, ideal voltmetre açık devre elemanı gibi çalışır. Hoca bunları, tersini varsayınca ne olacağını düşündürerek anlattı.

**Ampermetre.** Ölçüm yapmak için devredeki bir tel bağlantısından koparılır ve kopan bağlantı ampermetre üzerinden tamamlanır. Bu yüzden ampermetre devreye **seri** bağlanır. Kısa devre gibi çalışmasaydı devreye sanki bir direnç bağlamışız gibi etki ederdi. Yanlış olarak açık devre gibi düşünseydik, teli kopardığımız yerde bağlantı kopuk kalır, devreden akım akmaz ve ölçecek bir şey kalmazdı.

**Voltmetre.** İki ucu vardır. Hangi iki düğüm arasındaki gerilimi ölçmek istiyorsak uçları bu iki düğüm arasına **paralel** bağlanır. Yanlış olarak kısa devre gibi düşünelim: Bir direncin uçlarına voltmetreyi bağladık. Akım direnç yerine kısa devre gibi davranan voltmetre üzerinden geçerdi. Direnç üzerinden akım geçmeyince üzerinde gerilim düşümü de olmaz ve ölçülen değer sıfır çıkardı.

### 5.3 Ground (Referans) Kavramı

Devre şematiğinde bütün gerilimler bir referans noktasına göre tanımlanır ve bu nokta 0 V kabul edilir. Devre kendi başına bir sistemdir, referansın neresi olduğu fark etmez, herhangi bir nokta seçilebilir. Ama bir kez belirlendikten sonra devre içinde değiştirilmez ve bütün gerilim ölçümleri bu noktaya göre yapılır.

### 5.4 Sigorta

Fiziksel bir devre kurarken kablolar, düğmeler ve koruyucu elemanlar da kullanılır. Bunlardan biri sigortadır (fuse). Üzerinde desteklediği en yüksek akım değeri yazar.

**Soru (hocadan):** Devreyi korumak için sigorta devreye nasıl bağlanmalıdır?

**Cevap:** Seri. Üzerinde yazılı değere kadar akım geçişine izin verir. Bu değerin üzerindeki akımlarda yanarak açık devre hâline gelir ve devrede akım akmasını engeller.

**Soru:** Sigortalar yalnız akımı mı sınırlıyor, gerilim sınırlama gibi bir özellikleri var mı?

**Cevap:** Gerilimle ilgili özelliği yoktur, sigorta yalnız akım koruması sağlar. Gerilim koruması için farklı yapılar vardır. Örneğin diyotlu devreler kurularak, gerilim belirli bir değerin üzerine çıktığında kendi üzerinden kısa devre yapan ve bu limitin üzerindeki gerilimin devreye uygulanmasını engelleyen sistemler oluşturulur.

**Soru:** Sigorta belirli bir akımın üzerinde nasıl davranır?

**Cevap:** Hızlı ve yavaş tepki gösteren versiyonları vardır. Hızlı tepki veren sigorta, akımdaki küçük değişimlerden bile etkilenebilecek devreler içindir ve ufak bir değişimde bile yanarak devreyi korur. Yavaş tepki veren sigorta ise belirli bir toleransı olan yapılar içindir. Anlık küçük değişimlerden etkilenmez, ama akım uzun süre eşik değerinin üzerinde kalırsa devreyi korumaya alır.

Sigorta yandıktan sonra değiştirilmesi gerekir. Hoca bunu multimetre örneğiyle anlattı. Bazı multimetrelerde sigortanın uçları iki sokete sıkıca oturur ve kolayca çıkarılıp yenisi takılır. Daha ucuz multimetrelerde ise sigorta karta lehimlidir, değiştirmek için lehimle sökmek gerekir.

## 6. Bağımsız Kaynaklar

### 6.1 Gösterim

Bağımsız bir DC kaynak, uzun ve kısa iki çubukla gösterilebilir. Yuvarlak sembol de kullanılır ve içinde artı ile eksi terminaller işaretlenir. Kaynak AC ise yuvarlağın içinde bir dalga şekli, kare dalga ise kare dalga şekli yer alır. Yani gösterim, kaynağın sisteme verdiği sinyalin tipine göre değişir.

> **Hocanın vurgusu:** Çizeceğiniz devre şematiklerinde kaynağın artı ve eksi terminallerini mutlaka ve mutlaka düzgün bir şekilde işaretleyin.

Bağımsız akım kaynağı da yuvarlak sembol içinde bir ok ile gösterilir. DC ise ek bir işarete gerek yoktur, AC ise okun üzerinde bir dalga sembolü bulunur. Okun yönü, akımın aktığı yöndür. Kaynak bir elemana bağlandığında, koldaki akım yönünü okla uyumlu işaretlemek referans açısından uygun olur.

<!-- BELİRSİZ: 00:55:47-00:59:44 arasındaki sembol çizimleri slaytta; altyazıda yalnız sözlü tarif var. -->

### 6.2 Temel Özellikler

Bağımsız gerilim kaynağı devreye bağlı olduğu için üzerinden belirli bir akım akar. Bu akımın yönünden ve miktarından bağımsız olarak, üzerinde yazılı değer kadar gerilim oluşturur.

Bağımsız akım kaynağında durum tersidir. Üzerinde bir gerilim düşümü oluşur. Bu düşümün miktarından ve yönünden bağımsız olarak, bağlı olduğu koldaki akımı kaynağın kendisi belirler ve o kolda mutlaka o akım akar. Farklı elemanlarla ve kaynaklarla etkileşim olsa da kaynak bunu kendi üzerindeki gerilim düşümüyle kompanze eder.

### 6.3 Örnek: 3 A Akım Kaynağı ve 1 V Düşümlü Eleman

Tek çevrimli bir devrede bir bağımsız akım kaynağı ile iki terminalli bir eleman (slaytta kırmızı) var. Elemanın üst ve alt terminalleri arasında 1 V gerilim farkı bulunuyor. Akım kaynağı kola 3 A veriyor.

Akım kaynağı bu 1 V'luk farkı kendi üzerinde 1 V düşüm oluşturarak kompanze eder. Gerilim farkı başka bir değerde olsaydı yine kendi üzerindeki düşümle kompanze edip 3 A vermeye devam edecekti.

Hoca burada referans yönleri için iki pratik öneri verdi. Akım kaynağı olan kolda akım yönü kaynağın yönüyle aynı alınır. Pasif elemanda ise eleman üzerinden geçen akım yönüne göre artı ve eksi terminaller belirlenir. Tersi yapılırsa da aynı sonuç çıkar, ama "eksinin eksisi" ile uğraşmak gerekir.

- **Verilen:** Çevre akımı $I = 3$ A, eleman üzerindeki gerilim $V = 1$ V.
- **Kırmızı eleman:** Akım artı uçtan girip eksi uçtan çıkıyor:

$$
p_{\text{eleman}} = (1\ \text{V})(3\ \text{A}) = 3\ \text{W}
$$

  Güç pozitif olduğu için eleman devreden 3 W tüketir.

- **Akım kaynağı:** Akım eksi terminalden girip artı terminalden çıkıyor, yani akım $-1$ V'luk düşümden geçiyor:

$$
p_{\text{kaynak}} = (-1\ \text{V})(3\ \text{A}) = -3\ \text{W}
$$

  Güç negatif olduğu için kaynak devreye enerji sağlar.

- **Toplam güç:** Tek çevrimli devre kapalı bir sistem gibi düşünülebilir. Enerjinin korunumu gereği üretilen ve tüketilen enerjilerin toplamı sıfır olmalıdır:

$$
p_{\text{eleman}} + p_{\text{kaynak}} = 3 - 3 = 0
$$

Sonuçlar python ile hesaplandı. Hoca, referanslar tamamen ters alınsaydı da kırmızı elemanın gücünün yine pozitif, akım kaynağının gücünün yine negatif çıkacağını ekledi. Bu toplam ideal durum içindir. Gerçekte ölçemediğimiz ısıl kayıplar nedeniyle toplam ideal değerden farklılaşır.

### 6.4 Örnek: Eleman 1 V'luk Gerilim Kaynağı Olsaydı

Önceki örnekte kırmızı elemanın ne olduğu söylenmemişti, yalnız uçları arasında 1 V olduğu biliniyordu. Hoca bu elemanın 1 V'luk bir DC gerilim kaynağı olduğunu varsaydı. Hiçbir şey değişmez: Devreye enerji veren yine 3 A'lik akım kaynağıdır, enerji tüketen ise 1 V'luk gerilim kaynağıdır. Akım kaynağı gerilim kaynağını sürmektedir. Yani bir gerilim kaynağı olması, devrede mutlaka güç veren eleman olması demek değildir.

<!-- BELİRSİZ: 01:09:27 civarındaki "daha yüksek bir potansiyele ve daha fazla sisteme enerji vermesiyle ilgili" cümlesinin neyi kastettiği altyazıdan net değil. -->

**Soru:** Gerilim artarsa akım kaynağı yine 3 A verecek dediniz. Bunu nasıl yapıyor, direncini mi değiştiriyor?

<!-- BELİRSİZ: 01:10:04 soru altyazıda "iş direnceli mi değiştiriyor" diye geçiyor; "direnci" olarak okundu. -->

**Cevap:** Bu ideal akım kaynağı için böyledir. Gerçekte fiziksel bir akım kaynağı 3 A'i yalnızca belirli bir gerilim aralığında sağlayabilir, bunun üzerine çıkıldığında zarar görebilir.

**Soru:** Devrede bir bağımsız akım kaynağı ve bir bağımsız gerilim kaynağı olunca gücü üreten her zaman bağımsız akım kaynağı mı olur?

**Cevap:** Bu şematikte akım kaynağı, verilen referans yönleri itibarıyla gerilim kaynağını sürüyor. Gerilimin değerinin değişmesi bu durumu etkilemez. Farklı bir etki ancak gerilim kaynağının yönü değiştiğinde olabilir.

> **Ders sonrası not:** Hoca, gerilim kaynağının yönü değişirse "ikisi de devreye katkı sağlamış olabilir" dedi. Bu örnekte ikisi birden güç veremez, çünkü toplam güç sıfırdır. Gerilim kaynağının kutupları ters çevrilirse akım onun eksi ucundan girer ve kaynak $-3$ W ile güç verir; akım kaynağı ise $+3$ W ile güç çeker. Sonuçlar python ile hesaplandı. Dolayısıyla gücü üreten her zaman akım kaynağı değildir, kutuplara bağlıdır.

## 7. Bağımlı Kaynaklar

Bağımlı kaynaklar baklava dilimi biçiminde bir sembolle gösterilir. Gerilim kaynağıysa içinde artı ve eksi terminaller, akım kaynağıysa verdiği akımın yönünü gösteren bir ok bulunur. Dört türü vardır:

- **Gerilim kontrollü gerilim kaynağı:** Bağlı olduğu yere, başka bir düğümdeki gerilime göre gerilim sağlar.
- **Akım kontrollü gerilim kaynağı:** Sistemin herhangi bir kolundaki akıma göre gerilim sağlar.
- **Gerilim kontrollü akım kaynağı:** Bağlı olduğu kola, devrenin başka bir düğümündeki gerilime göre akım sağlar.
- **Akım kontrollü akım kaynağı:** Bağlı olduğu kola, devrenin başka bir kolundaki akıma göre akım sağlar.

Bunlar ideal durumlardır. İdeal elemanlar bütün aralıklarda çalışıyor görünür, gerçekte ise yalnız belirli aralıklarda çalışırlar. Hoca, op-amp ve kuvvetlendirici gibi elemanlarda bağımlı kaynakların uygulamaları olduğunu ve bunların yalnız belirli akım aralıklarında çalıştığını söyledi.

> **Ek bilgi (derste anlatılmadı):** Kısa nottaki gösterimle dört tür büyük olasılıkla şöyle yazılır: VCVS için $v = \mu v_x$, CCVS için $v = r i_x$, VCCS için $i = g v_x$, CCCS için $i = \beta i_x$. Burada $v_x$ ve $i_x$ devrenin başka bir yerindeki kontrol büyüklükleridir, $\mu$, $r$, $g$, $\beta$ ise sabit katsayılardır.

Hoca bu bölümü, aktif elemanların sisteme enerji verdiğini ve güçlerinin negatif çıktığını, pasif elemanların ise enerji tükettiğini ve güçlerinin pozitif çıktığını söyleyerek bitirdi.

> **Ders sonrası not:** Aktif elemanların gücü her zaman negatif çıkmaz. Hocanın kendi 6.4 örneğinde 1 V'luk gerilim kaynağı $+3$ W ile güç çeker. Gücün işareti, elemanın türünden değil akım ve gerilimin o devredeki yönlerinden gelir.

## 8. Pasif Elemanlar: Direnç, Endüktans, Kapasite

Ders boyunca görülecek üç temel pasif eleman direnç, endüktans ve kapasitedir. Sembolleri slaytta verildi.

Hoca sembollerle ilgili önemli bir şeyi şimdiden söyledi. Endüktans elemanı sürekli bir tel olarak çizilir, bu yüzden DC durumda kısa devre elemanı gibi çalışır. Kapasite elemanının ise iki ucu birbirinden ayrıktır, bu yüzden DC koşullarda açık devre elemanı gibi davranır. Bu iki eleman asıl AC işaretlerde etki gösterir. Konu ilerleyen derslerde tekrar ele alınacak.

> **Ek bilgi (derste anlatılmadı):** Bu davranış büyük olasılıkla DC sürekli hâl içindir. Tanım bağıntıları büyük olasılıkla $v = L\frac{di}{dt}$ ve $i = C\frac{dv}{dt}$ olduğundan, sabit akım ve gerilimde türevler sıfır olur. Kısa not da "DC sürekli hâlde" ifadesini kullanır. Anahtarlama anından sonraki geçici sürede ise iki eleman böyle davranmaz.

Birimler şöyledir:

- **Direnç:** Birimi ohm, sembolü Yunan alfabesindeki $\Omega$.
- **Endüktans:** Birimi henry, sembolü H. Ders boyunca mH mertebesinde kullanılacak: $1\ \text{mH} = 10^{-3}\ \text{H}$.
- **Kapasite:** Birimi farad, sembolü F. Mili, mikro, nano veya piko mertebelerinde kullanılabilir.

> **Hocanın vurgusu:** Endüktans ve kapasite değerlerinde birim dönüşümüne özellikle dikkat edin.

## 9. Kablo, Ground, Anahtar ve Sigorta

### 9.1 Ground ile Toprak Hattının Farkı

Kablo sürekli bir çizgiyle gösterilir. "Ground" sözü ise iki farklı şeyi ifade edebilir. Biri, evi kaçak akımlardan korumak için bütün prizlerde bulunan toprak hattıdır. Bu hattın ucu kalın bir bakır kazıkla toprağa çakılır, iletim iyi olsun diye de çakıldığı yere biraz tuz ve su verilir. Bu topraklamadır ve farklı bir şeydir. Ders boyunca kullanılacak ground ise kapalı bir sistem içindeki bütün gerilimlerin tanımlandığı referans noktasıdır. Şematikte bunun için slayttaki sembollerden en alttaki kullanılacak.

<!-- BELİRSİZ: 01:33:43-01:33:53 arasında sözü edilen referans sembolü slaytta; altyazıdan biçimi okunmuyor. -->

### 9.2 Anahtar

Anahtarda terimler günlük kullanıma göre karışabilir. Anahtarın **açık** olması bağlantıyı keser ve akım akmaz. Anahtarın **kapalı** olması iletimi sağlar ve devrede akım akar. Anahtar üzerinden akım yalnız ve yalnız anahtar kapalıyken akabilir.

> **Hocanın vurgusu:** Terimi ders boyunca bu şekilde kullanacağız, karıştırmamaya dikkat edin: Açık anahtar iletimi keser, kapalı anahtar iletimi sağlar.

### 9.3 Sigorta Gösterimi

Sigorta için ders kapsamında tercih edilen sembol, slaytta gösterilen IEEE standardındaki semboldür. Sigortaların hızlı ve yavaş tepki veren türleri olduğu ve tek kullanımlık olduğu burada tekrar hatırlatıldı.

<!-- BELİRSİZ: 01:30:14 civarındaki sigorta sembolü slaytta; altyazıda biçimi tarif edilmiyor. "I-Tripleen" ifadesi IEEE olarak okundu. -->

### 9.4 Kablo Seçimi

Derste simülasyon üzerinden ilerlenecek, ama fiziksel ve karmaşık bir sistem kurulduğunda kablo seçimi önem kazanır. Kablo, sistemde desteklenmesi istenen akıma göre seçilir.

Hocanın örneği şöyleydi: Sistemde yüksek kapasiteli bir lipo pil ile bir motor sürüyoruz. Motoru zorladığımızda motor yüksek akım çekmek ister ve batarya bunu sağlayabilir. Ama uygun olmayan kablo bu akımı desteklemeyebilir. Bu durumda kablo yanabilir, yangın çıkabilir.

İletkenlerde yarıçap arttıkça akım taşıma kapasitesi artar. Yüksek akım ihtiyacı için daha büyük çaplı kablolar kullanmak gerekir. Bunun için Amerikan standardı olan AWG vardır. Bu standartta belirli çaplar, bunların kesit alanları ve destekledikleri yaklaşık akım miktarları bulunur. Gerçek kablolar ideal olmadığı için birim uzunluk başına bir dirençleri de vardır. Bu yüzden gereksiz yere uzatılan her kablo sistemde ısıl kayba yol açabilir ve bu küçük direnç değerleri de önemli olur.

<!-- BELİRSİZ: 01:32:47-01:33:17 arasındaki AWG tablosu slaytta; altyazıda değer verilmiyor. "minimetrik direnç" ifadesi "çok küçük direnç" olarak okundu. -->

## 10. Gerilim ve Akım Kaynaklarının Temel İlkeleri

İdeal durumda kablo bir kısa devre elemanı olarak düşünülür, üzerinde direnç olmadığı varsayılır. Dolayısıyla bir kablo üzerindeki bütün noktaların gerilimi eşittir.

Bir gerilim kaynağının sağladığı şey, **uçları arasındaki gerilim farkıdır**. Bu, 5 V'luk bir kaynağın artı terminalinin gerilim değerinin 5 V olduğu anlamına gelmez. Hoca bunu üst üste bağlanmış iki kaynakla gösterdi.

**Örnek.** Alt uç ground'a bağlı 3 V'luk bir kaynağın üstüne 5 V'luk ikinci bir kaynak bağlanıyor, üst terminaller artı uçlardır.

- **Verilen:** Ground $= 0$ V, alt kaynak $3$ V, üst kaynak $5$ V.
- **Ara düğüm:** $0 + 3 = 3$ V (ara adım eklendi).
- **Üst düğüm:** $3 + 5 = 8$ V.
- **Kontrol:** Üst kaynağın uçları arasındaki fark $8 - 3 = 5$ V'tur (ara adım eklendi). Kaynak kendi uçları arasındaki farkı sağlamıştır.

Sonuç python ile hesaplandı: 8 V. Buradaki 5 V'luk kaynağın artı ucu 5 V değil, 8 V'tur.

> **Hocanın vurgusu:** Gerilim kaynağı kendi uçları arasındaki gerilim farkını sağlar. Bağlı olduğu düğümün gerilim değeri ise diğer elemanlara göre belirlenebilir. Buna dikkat etmemiz gerekiyor.

> **Ders sonrası not:** Hoca 00:48:56 ve 01:00:37 civarında kaynağın "bağlı olduğu düğümde" üzerinde yazılı gerilimi oluşturduğunu söyledi. Doğrusu, burada kendisinin de söylediği gibi, bu değerin kaynağın iki ucu arasındaki fark olmasıdır.

Ardından ilkeler şöyle toparlandı:

- Referans olarak kullanılan düğüm her zaman 0 V'tur.
- Elektrik akımı yüksek potansiyelden düşük potansiyele doğru akar.
- Bir direnç üzerinden geçen akım, uygulanan gerilimle doğru orantılıdır.
- Gerilim kaynağının üzerinden geçen akımı kaynağın kendisi değil, diğer elemanlar belirler. Gerilim kaynağı uçları arasındaki farkı sabitler.
- Akım kaynağı ise üzerinden geçen akımı kendi değerine sabitler.

> **Ders sonrası not:** Hoca 01:35:36 civarında "bir gerilim kaynağı üzerinden akan akım ideal durumda üzerindeki değere eşit" dedi. Bu cümle yanlıştır. Aynı bölümde 01:36:49'da söylediği doğrudur: Gerilim kaynağının akımını diğer elemanlar belirler, akımı sabitleyen eleman akım kaynağıdır.

## 11. Yük ve Akım

### 11.1 Yük

Atomik yapılarda elektronlar negatif, protonlar pozitif yüklüdür. Tek tek pozitif ve negatif yüklü parçalar oluşturulabilir ve bu parçalar yüklerinden dolayı birbirine kuvvet uygular. Bir elektronun üzerindeki yük $1{,}6 \times 10^{-19}$ coulomb olarak verilir.

> **Ders sonrası not:** Hoca değeri $1{,}6 \times 10^{-19}$ C olarak söyledi. Kısa notta yer aldığı gibi daha hassas değer büyük olasılıkla $-1{,}602 \times 10^{-19}$ C'dir. Eksi işareti, derste söylenen negatif yükten gelir.

Yük $q$ harfiyle gösterilir. Sabit bir yük büyük $Q$ ile, zamana göre değişen yük küçük $q$ ile yazılır. Bu kural akım, gerilim, güç ve enerji için de geçerlidir: Büyük harf sabit değerleri, küçük harf zamana bağlı değişen değişkenleri gösterir.

### 11.2 Akım

Birim zamanda belirli bir kesit alanından geçen yük miktarına akım denir. Belirli bir kesit alanı için bu, yükün zamana göre türevidir:

$$
i = \frac{dq}{dt}
$$

Tersinden düşünürsek, akımın belirli bir zaman aralığındaki integrali o kesit alanından geçen net yükü verir:

$$
q = \int i\, dt
$$

## 12. DC ve AC

DC ve AC, doğru akım ve alternatif akım kavramlarından gelir. DC analizde değişkenler için büyük harfler ($V$, $I$), AC durumlarda küçük harfler kullanılır.

Grafiksel fark şudur: DC bir kaynak zamana bağlı olarak değişmez. AC kaynağın verdiği değer ise zamanla azalıp artabilir, periyodik de olabilir, yani bir dalgalanma gösterir. Derste önce DC analiz, sonra AC analiz görülecek. Pasif elemanlar da önce DC analizde, sonra AC kaynak durumunda incelenecek.

## 13. Gerilim, Güç ve Enerji

### 13.1 Gerilim

Su benzetmesiyle anlatılan gerilimin formal tanımı şöyledir: Bir birim yüke bir birim enerji verildiğinde bu yükteki potansiyel değişimi 1 volttur. Yani gerilim, enerjinin yüke göre türevidir:

$$
v = \frac{dw}{dq}
$$

Hoca bu enerjiyi "elektromotor kuvvet" olarak da adlandırdı ve yüklerden dolayı etki eden kuvvet diye tarif etti.

> **Ders sonrası not:** Hoca elektromotor kuvveti enerji ve kuvvet olarak tarif etti, 00:42:18 civarında da voltu noktanın "kuvveti" diye andı. Adında "kuvvet" geçse de elektromotor kuvvet büyük olasılıkla ne enerji ne de mekanik anlamda kuvvettir; birim yük başına enerji olarak volt cinsinden ölçülür. Bu, hocanın yukarıdaki $v = dw/dq$ tanımıyla da uyumludur.

### 13.2 Güç

Güç, enerjinin zamana göre türevidir. Bu türev zincir kuralıyla farklı yazılabilir:

$$
p = \frac{dw}{dt} = \frac{dw}{dq} \cdot \frac{dq}{dt}
$$

Burada $dq$'lar sadeleşince yine $dw/dt$ elde edilir, ama bu yazım şunu sağlar: $dw/dq$ gerilim, $dq/dt$ akımdır. Dolayısıyla hem AC hem DC durumda:

$$
p = v \cdot i
$$

Gücün birimi watt, gerilimin birimi volttur.

### 13.3 Enerji

Tersinden düşünürsek, birim zamanda harcanan enerji gücü verdiğine göre, belirli bir zaman aralığında gücün integrali harcanan enerjiyi verir. Güç yerine gerilim çarpı akım yazılabilir:

$$
w = \int p\, dt = \int v\, i\, dt
$$

Enerji için temel olarak kWh, mertebeye göre Wh birimi kullanılır.

## 14. Güç İşareti ve Referans Yönleri

Pozitif ve negatif güç tamamen referans yönleriyle ilişkilidir. Belirli bir referans verildikten sonra tutarlı biçimde uygulanması gerekir. Akım kaynakları, eleman veya kol üzerindeki akım yönünü belirler. Elemanlar üzerindeki gerilim düşümleri de akımın yönüne göre verilir: Akımın elemana girdiği uç artı, çıktığı uç eksidir.

- **Akım elemana artı uçtan girip eksi uçtan çıkıyorsa:** Güç pozitiftir, eleman devrede güç tüketir. Slayttaki iki pasif elemanda da, biri aşağıdan yukarı akım yönüyle çizilmiş olsa bile, akım artıdan eksiye gittiği için güç pozitif çıkar.
- **Akım elemana eksi uçtan girip artı uca ilerliyorsa:** Hesap negatif çıkar. Eleman aktiftir, devreye güç verir.

Kapalı bir sistemde toplam güç sıfır olmalıdır. Devre şematiklerini ideal durumda kapalı sistem olarak düşünebiliriz.

<!-- BELİRSİZ: 01:45:07-01:45:47 arasında sözü edilen sol ve sağ eleman çizimi slaytta; yönler altyazıdaki sözlü tarife göre yazıldı. -->

Hoca aynı kuralı dersin sonlarına doğru bir kez daha, bağımlı ve bağımsız kaynaklar ile pasif elemanların hepsi için geçerli olduğunu belirterek tekrar etti. Diğer elemanların etkisiyle oluşan gerilim ve akımlar da hesaba katıldığında, kural referans işaretlerine göre aynı şekilde uygulanır.

## 15. Ohm Kanunu

### 15.1 Devrede Akımı Ne Belirler?

1 V'luk bir gerilim kaynağı ile 1 Ω'luk bir direnç düşünelim. Akım, kaynağın pozitif ucundan çıkıp negatif ucuna doğru dolaşır. Elektronların dolaşma yönü bunun tersidir, ama elektron negatif yüklü olduğu için akımın yönü oklarla gösterildiği gibi alınır.

Bu devrede akımı belirlemekte etkili olan eleman dirençtir. Hocanın benzetmesiyle direnç, devrede akacak akımı bir **dar boğaza** sokarak sınırlar.

Deneysel olarak şöyle yapılabilir: Gerilim kaynağının değeri artırılarak akım not edilir. Sonra gerilim sabitlenip direnç artırılarak akım not edilir. Bunlar grafiğe döküldüğünde, akım ile gerilim arasında doğrudan bir ilişki ve eğimi direncin değerine bağlı bir doğru görülür. Ohm kanunu buradan ortaya çıkar.

### 15.2 Kanun

Bir direnç elemanı üzerindeki gerilim düşümünün elemanın direnç değerine oranı, eleman üzerinden geçecek akımı belirler:

$$
I = \frac{V}{R}
$$

> **Ders sonrası not:** Hoca 01:48:36 ve 01:49:56 civarında akımın direnç değeriyle "doğrudan orantılı" olduğunu söyledi. Kendi yazdığı $I = V/R$ formülüne göre akım gerilimle doğru, dirençle **ters** orantılıdır. 01:36:34 civarında geçen "eğim direnç değeridir" sözü de eksenlere bağlıdır: Yatay eksende akım, düşey eksende gerilim varsa eğim $R$, eksenler tersse $1/R$ olur.

### 15.3 Örnek: 2 Ω Direnç

Elemanın bir terminali $x + 4$ V, diğer terminali $x$ V olsun.

- **Gerilim düşümü:** $(x + 4) - x = 4$ V. Yüksek potansiyelli taraf artı, diğeri eksi işaretlenir.
- **Akım:** Akım artıdan eksiye doğrudur:

$$
I = \frac{4\ \text{V}}{2\ \Omega} = 2\ \text{A}
$$

Sonuç python ile hesaplandı. Dikkat edilirse sonuç $x$'in değerine bağlı değildir, yalnız iki uç arasındaki fark önemlidir.

### 15.4 Örnek: 1 V ve 1 Ω

Aynı potansiyele sahip noktalar üzerinde direncin yerinin değişmesi hiçbir şeyi etkilemez. Direnç kaynağın hemen sağına da altına da konulabilir, ne devrenin yapısı ne akım ve gerilim değerleri değişir.

$$
I = \frac{1\ \text{V}}{1\ \Omega} = 1\ \text{A}
$$

Sonuç python ile hesaplandı. Tek çevrim olduğu için bu 1 A devreyi tamamlayan bütün elemanlardan geçer: gerilim kaynağından, kablolardan, dirençten ve direncin altındaki kablolardan. Devrenin her yerinde aynı 1 A dolaşır.

## 16. Referans Noktası ve Açık Devre

### 16.1 Referans Tanımlanmamış Devre

Aynı 1 V ve 1 Ω'luk devrede referans gösterilmemiş olsun. Bu, sistemin referansının başka bir yerde olduğu ve devreyle ilişkisinin bilinmediği anlamına gelir. Bütün gerilimler o referansa göre tanımlıdır. Bu durumda gerilimler şöyle bulunur:

1. Kaynağın alt ucundaki düğüme $x$ V denir.
2. Gerilim kaynağı iki ucu arasında 1 V fark oluşturmak zorunda olduğu için üst düğüm $x + 1$ V olur.
3. İdeal kabloda gerilim düşümü olmadığından, alt kablo başka bir elemana gelene kadar her yerde $x$ V, üst kablo her yerde $x + 1$ V'tur.
4. Bu değerler direncin uçlarına taşınır. Direncin iki terminali arasında $(x + 1) - x = 1$ V fark oluşur.

### 16.2 Ground Eklenmesi

Ek bir $x$ değişkeninden kurtulmak için devreye referans (ground) tanımlanır:

1. Referans değerimiz 0 olduğu için kaynağın alt ucu 0 V'tur.
2. Bağımsız kaynağın terminalleri arasında 1 V fark olması gerektiğinden üst uç 1 V'tur.
3. Üst kablodaki bütün noktalar 1 V olduğundan direncin üst ucu 1 V'tur.
4. Direncin alt ucu, referans ve kablo sayesinde 0 V'tur.

Direncin uçları arasında yine 1 V'luk gerilim düşümü elde edildi, üstelik fazladan bir değişken kullanılmadan.

> **Hocanın vurgusu:** Ground ile yapılan bu gösterim, ekstra bir değişkene gerek bırakmadığı için daha pratiktir. Bu yüzden önemlidir.

### 16.3 Açık Devrede Gerilimler

Üst kol koparılmış bir devre düşünelim. Referans gerilimi yine var ve bütün düğümler buna göre tanımlı. İki durum incelendi.

**Direnç referans tarafında.** Referansa bağlı uç 0 V'tur. Direncin diğer ucu hiçbir yere bağlı değildir. Akım akmadığı için direnç üzerindeki gerilim düşümü sıfırdır, dolayısıyla direncin boştaki ucu da 0 V'tur. Gerilim kaynağının boştaki ucu ise, kaynaktan dolayı 1 V'luk potansiyele sahiptir.

**Direnç kaynağın üst tarafında.** Kaynağın alt ucu referanstan dolayı 0 V, üst ucu kaynaktan dolayı 1 V'tur ve bu değer kablo boyunca gelir. Direncin diğer ucu hiçbir yere bağlı olmadığından akım sıfırdır. $V = IR$'den direnç uçları arasındaki gerilim farkı $0$ V olur. Fark sıfır olduğu için direncin boştaki ucunda da 1 V görülür.

<!-- BELİRSİZ: 01:54:01-01:55:27 arasındaki iki açık devre çizimi slaytta; elemanların yerleşimi altyazıdaki sözlü tarife göre yazıldı. -->

Hoca, kafa karıştırmamak için üzerinde durmadan bir noktayı daha söyledi: İşaret referansları ters çevrilip değer de ters çevrilirse, "negatifin negatifi" alınmış olur ve aynı şey ifade edilir.

## 17. Son Örnek: 10 V Kaynak ve 4 kΩ Direnç

İki elemandan oluşan tek çevrimli bir devrede 10 V'luk bir gerilim kaynağı ile 4 kΩ'luk bir direnç var. Devrede akan akımı kim belirler? Gerilim kaynağı ve direnç birlikte belirler. Yani gerilim kaynağından akacak akımı aslında diğer elemanlar belirlemiş olur.

- **Direnç üzerindeki gerilim:** Kaynak nedeniyle direncin uçları arasındaki düşüm 10 V olmak zorundadır.
- **Akım:**

$$
I = \frac{10\ \text{V}}{4\ \text{k}\Omega} = \frac{10}{4000}\ \text{A} = 2{,}5\ \text{mA}
$$

- **Kaynağın gücü:** Akım, bağımsız kaynağın eksi referansından artı referansına doğru ilerliyor, yani $-10$ V ile karşılaşılır:

$$
p_{\text{kaynak}} = (-10\ \text{V})(2{,}5\ \text{mA}) = -25\ \text{mW}
$$

  Negatif değer, kaynağın devreye enerji verdiğini gösterir.

- **Direncin gücü:** Akım direncin pozitif terminalinden negatif terminaline ilerliyor:

$$
p_{\text{direnç}} = (10\ \text{V})(2{,}5\ \text{mA}) = 25\ \text{mW}
$$

  Pozitif değer, direncin bu gücü tükettiğini gösterir.

- **Toplam (ara adım eklendi):** $-25 + 25 = 0$ mW.

Sonuçlar python ile hesaplandı.

> **Ders sonrası not:** Hoca 01:57:39 civarında akımı bir kez "2,5 amper" diye söyledi. Doğrusu 2,5 mA'dir. 25 mW sonucu ve hemen sonraki direnç hesabındaki 2,5 mA doğrudur; 2,5 A alınsaydı güç 25 W çıkardı.

Direnç için referans yönleri şöyle belirlenir: Eleman üzerinde kaynaklar nedeniyle oluşan gerilim farkı hangi doğrultudaysa, yüksek potansiyelli taraf artı, düşük potansiyelli taraf eksi işaretlenir. Akım yönü de artıdan eksiye tanımlanır. Bu durumda direnç, doğal olarak pozitif güç değerli, yani güç tüketen bir eleman çıkar.

## Dersin Toparlaması

Bu derste devre analizinin temel sorusu ortaya kondu: Bir elemanın akımı ve uçları arasındaki gerilim nedir, buradan harcadığı veya verdiği güç nasıl bulunur? Bunun için SI birimleri ve ön ekler, yük, akım, gerilim, güç ve enerji tanımları, $i = dq/dt$, $v = dw/dq$, $p = vi$ bağıntıları görüldü. Aktif ve pasif elemanlar, bağımsız ve bağımlı kaynaklar, ampermetre, voltmetre, sigorta, anahtar, kablo ve ground tanıtıldı. Referans yönleri tutarlı seçildiğinde gücün işaretinin elemanın tükettiğini veya verdiğini gösterdiği ve kapalı bir devrede güçlerin toplamının sıfır olduğu örneklerle gösterildi.

Ohm kanunu ve ground kavramıyla tek çevrimli basit devrelerde düğüm gerilimleri ve akım bulunabilir hâle geldi. Dersin başındaki yol haritasına göre bir sonraki adım, Kirchhoff'un akım ve gerilim yasaları, tek çevreli devreler, seri ve paralel bağlama, gerilim ve akım bölücülerdir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
