# Ders 4 Genişletilmiş Notu: Sınıflar, Nesneler ve Üyeler: UML Gösterimi, Görünürlük, static/final ve Kurucular

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Nesne ve Kapsülleme
- 2. Sınıf Kavramı
- 3. Örnek: Araba Nesnesi, Nitelikler ve Eylemler
- 4. Üye Alan Türleri ve Terminoloji
- 5. UML'de Sınıf ve Nesne Gösterimi
- 6. Her Nesne Farklı Bir Bireydir
- 7. Mesaj Gönderme ve Üye Erişimi
- 8. Sıralama Şemasında Metot Çağrısı
- 9. Paketler
- 10. Görünürlük Kuralları ve Bilgi Gizleme
- 11. UML Sınıf Şeması
- 12. Üyelerin Özel Durumları: static ve final
- 13. Kurucular ve Sonlandırıcılar
- 14. Denetim Akışı ve main Metodu
- 15. Uygulama: Car Sınıfı
- 16. Car Sınıfının Sıralama Şeması

## 1. Nesne ve Kapsülleme

Derste nesne yönelimin temel ilkeleri işlendi: sınıf nedir, nesne nedir, üye alanlar ve üye metotlar nedir, erişim metotları nelerdir. Yöntemin adı "nesneye yönelik programlama" olduğu için işin odağında nesneler vardır. Hoca bu ders boyunca her zaman nesneler cinsinden düşünmeyi önerdi; böyle yapıldığında konular daha iyi anlaşılır.

Nesne temel programlama elemanıdır. Nesne çeşitli nitelikler (attributes) ve bu nitelikler üzerinde çalışan eylemler (tasks) içerir; eylemlerin diğer adı metottur (method). Program, gerçek dünyadaki bir problemi çözmek için yazılır. Bu yüzden problem alanındaki varlıklar ve onların dinamikleri programa aktarılmalıdır. Nesne yönelim kullanılıyorsa gerçek dünya problemindeki her varlık kodda bir nesne olarak karşılık bulur.

Slaytta nesne için "Object ≈ a real-world entity" yazılıdır. Yapısal programlama alışkanlığıyla nesne bir değişkene benzetilebilir. Slayttaki espriyle: "Similar to variables but Superman is similar to mere mortals, too!" (ekrandan, 00:10:00). Bu benzetme çok basit ve eksiktir, çünkü bir nesne kendi verisi ve o veri üzerinde çalışan metotlarıyla ayrılmaz bir bütündür.

### 1.1 Veri ve metot halkası

Slaytın sağında bir daire vardır: ortadaki küçük dairede "Data", çevresindeki dört dilimde "Method" yazar (ekrandan, 00:10:00). Hoca bunun bir UML gösterimi ya da standart olmadığını, yalnız konuyu anlatmak için çizdiği bir şekil olduğunu söyledi. Dairenin tamamı tek bir nesnedir. Çekirdekte veri, yani nitelikler vardır; çevresinde o veriyle çalışan metotlar bulunur. Şekil iki boyutlu düşünülürse veriye giden her yol bir metottan geçer. Şeklin iki amacı vardır: veriye metotlar üzerinden erişildiğini ve bir nesnenin verisiyle metotlarının bir bütün olduğunu göstermek.

Yapısal programlamada fonksiyonlarla çalışılıyordu. Sonra `struct` ile birbiriyle ilişkili verileri bir araya toplamak öğrenildi; bu veriler genelde problemdeki bir varlıkla ilgili bütün verilerdi. Ama `struct` ayrı bir yerde, onu parametre olarak alan ya da almayan fonksiyonlar ayrı bir yerde tanımlanıyordu. Aynı `.c` dosyasında olsalar bile birbirinden ayrıydılar. Nesne yönelimde ise varlıklar, yani nesneler, verileri ve metotlarıyla bir bütündür.

Bir nesnenin metotlarına başka sınıflardan nesneler verilerek o metotların başka nesnelerin verileriyle de çalışması sağlanabilir. Ama bu durumda da veriye doğrudan değil, yine metotlar üzerinden erişilir. Bunun yolları ve kuralları ders boyunca öğrenilecek. Slayttaki maddeler de bunu söyler: her metot nesnenin her niteliğine ve verilen her parametreye erişebilir, "ama birçok kural vardır" ve amaç bu kuralları öğrenmektir.

Veri ile metotların ayrılmaz bir bütün oluşturmasına literatürde **kapsülleme (encapsulation)** denir. Slayttaki tanım: "Encapsulation: The data and the methods of an object cannot be separated. Data is accessed through methods." (ekrandan, 00:10:00)

## 2. Sınıf Kavramı

Sınıf, nesneleri tanımlamak için yazılan bir tür şablondur; yani program kodudur. Hocanın benzetmesiyle nesneler kurabiyelere, sınıflar ise hamurdan kurabiyeleri kesmekte kullanılan kalıplara benzer. Sınıf kodu, ortaya çıkacak nesneyi tanımlayan bir şablondan ibarettir. Kod yazarken tabii ki sınıf kodu yazılır, ama yine de her zaman nesneler üzerinden düşünülmelidir.

Java'da sınıf kodu `class` anahtar kelimesiyle başlar, ardından bir boşluk ve sınıf adı gelir, sınıfın kodu kıvrık parantezler arasına yazılır. Bu blok yapısı C'ye benzer. `class` anahtar kelimesi küçük harfle yazılır. Genel olarak kullanılan kodlama standardına göre yalnız sınıf adları büyük harfle başlar, geri kalan her şey küçük harfle başlar. Slayt örneğinde de sınıf adı küçük harfle başlıyordu; hoca bunu ders sırasında büyük harfe çevirdi.

## 3. Örnek: Araba Nesnesi, Nitelikler ve Eylemler

Hoca örnek nesne olarak belirli bir arabayı verdi: yüz yüze derste olsalardı pencereden dışarı bakıp "şuradaki şu renk, şu marka, şu model araba" diye göstereceğini söyledi. Bu belirli araba programda bir nesne olarak ifade edilir; onu tanımlamak için de bir sınıf kodu yazılır.

### 3.1 Nitelikler probleme göre seçilir

Arabanın rengi, markası, modeli, plaka numarası gibi birçok niteliğinden söz edilebilir. Ama koda yalnız çözülecek problemle ilgili nitelikler alınır. Örneğin otoparka giriş ve çıkış saatlerine göre ücret hesaplayan bir otopark bilgi sistemi için aracın rengini bilmek gerekmez. Bir araç tescil bilgi sistemi için ise renk gereklidir.

### 3.2 Tekil tanımlayıcı

Bu nitelikler arasında plaka numarasının özel bir önemi vardır, çünkü plaka numarası **tekil tanımlayıcıdır (unique identifier)**. Aynı cinsten diğer varlıklar arasında belirli bir varlığı ayırt etmeye yarayan üye alandır. Bu görevi nedeniyle özel önem taşır ve her nesnenin bir tekil tanımlayıcısı olmasına dikkat edilir. Bununla ilgili mutlaka yapılması gerekenler sonraki haftalarda konuşulacak.

### 3.3 Eylemler de probleme göre seçilir

Öğrenciler genelde ilk akla gelen eylem olarak "arabayı çalıştırmak" der. Ama eylemler de problemle ilgili olanlardan seçilmelidir. Tescil ya da otopark sistemi için arabayı çalıştırmak ilgilenilen bir eylem değildir; bir yarış simülasyonunda ise arabayı çalıştırmak ve hareket ettirmek ilgilenilen eylemlerdir. Arabayı satmak, yani eski sahibinden yeni sahibine geçirmek, tescil sisteminde gerekli bir eylemdir; otopark sisteminde işe yaramaz. Otopark sisteminde otoparka giriş ve çıkış eylemleri gerekir.

Hangi problem olursa olsun, hep belirli bir varlığın belirli bir eylemi yapması izlenir. Burada tekil tanımlayıcıyı elde edebilmek devreye girer. Üye alanlara doğrudan erişim olmadığı için, yalnız metotlar olduğu için, bir varlığın tekil tanımlayıcısını öğrenme eylemi diğerleri arasında öne çıkar. Bu, basit bir `return` komutundan ibaret ama çok önemli bir metottur.

Sınıf için genel bir tür adı olarak "otomobil" sınıfı denebilir. Bu sınıfın kodunda ilgilenilen nitelikler ve eylemler kodlanır. Bir sınıftan istenildiği kadar nesne oluşturulabilir. Nesneye yönelik bir program da çeşitli nesneler arasındaki metot çağrıları şeklinde yürür.

## 4. Üye Alan Türleri ve Terminoloji

### 4.1 İlkel ve ilkel olmayan üyeler

Bir nesnenin nitelikleri kavramsal olarak iki gruba ayrılır:

- **İlkel (primitive) üyeler:** Tek bir birim bilgi içerir. Örnekler: tam sayılar (aracın model yılı), gerçek (ondalıklı) sayılar (motor hacmi, 1.5 litre gibi), mantıksal değerler (true ya da false), tek bir karakter.
- **İlkel olmayan (non-primitive) üyeler:** Herhangi bir sınıftan herhangi bir nesne. İstenildiği kadar sınıf yazılabildiği için aslında sınırsız sayıda üye türü vardır, ama kaba bir ayrımla ilkeller ve ilkel olmayanlar diye iki gruptan söz edilir.

### 4.2 Terminoloji

Hoca buraya kadar yapısal programlamadan benzetmeler yaptığını, bundan sonra doğru terimleri kullanacağını söyledi. Slayttaki liste (ekrandan, 00:20:00):

- Data = **Member field** = field = attribute. Türkçesi üye alan. Derste tercih edilen terim member field'dır; kısaca field da denir. Hoca "veri" ve "fonksiyon" gibi adların yapısal programlamadan kalma olduğunu belirtti.
- State: bir nesnenin tüm niteliklerinin değerlerinin kümesidir; nesnenin durumudur.
- Task = Action = function = Method = **Member method** (üye metot).
- **Members** of a class/object = Methods + fields. "Nesnenin üyeleri" dendiğinde hem üye alanlar hem üye metotlar kastedilir.
- **Class** = type. Bazı kaynaklarda, özellikle akademik ağırlıklı olanlarda, sınıf yerine tür ya da tip denir.
- o, C sınıfından bir nesneyse "o is an **instance of** C", yani "o bir C örneğidir" de denebilir.

Durum kavramı için verilen örnek: bir insan nesnesinin üye alanları isim, yaş ve cinsiyet olarak tanımlanmışsa, bu üç alanın değerleri o kişinin durum bilgisidir. Bir yıl sonra yaş bir artacağı için durum bilgisi değişir, ama isim değişmez.

## 5. UML'de Sınıf ve Nesne Gösterimi

Ders kapsamında UML sınıf şemaları ve UML sıralama şemaları (sequence diagram) da öğrenilecek. UML sınıf şemasında bir sınıf, içine sınıf adı yazılmış bir dikdörtgenle gösterilir (ekrandan, 00:20:00: `Car` kutusu, "A class shown in a class diagram"). Üye alanlar ve metotlar ileride alt bölmelerde gösterilecek.

Nesneler ise sıralama şemalarında gösterilir: `nesneAdı : SınıfAdı` biçiminde ve **altı çizili** (ekrandan, 00:20:00: `kitt : Car`, "An object shown in a sequence diagram").

> **Hocanın vurgusu:** Kâğıt kalemle çizerken alt çizgi ya da iki nokta üst üste unutulabiliyor. Bu ayrıntılara özen gösterilmeli. Notasyondaki her işaretin bir anlamı vardır ve onların bilindiği şemada gösterilmelidir.

Hoca bunu Violet UML Editor'de gösterdi. Bir sıralama şeması açıp nesne yaşam çizgisi (object lifeline) ekledi ve adını `kitt : Car` yaptı; araç adın altını otomatik olarak çizdi (ekrandan, 00:25:00). Araçla çizerken alt çizgiyi unutmak mümkün değildir, ama elle ya da başka bir araçla çizerken unutulabilir. Sınıf şemasında da yalnız dikdörtgen içine sınıf adı yazıldığı için, nesneyi sınıftan ayıran şey alt çizgidir. Activation bar'lar ve yaşam çizgileri de nesneyi belli eder, ama yine de alt çizgi gösterilmelidir.

Nesne gösteriminin üç biçimi vardır (ekrandan, 00:55:00: `kitt : Car`, `: Car`, `myCar` kutuları):

- `kitt : Car`: nesne adı ve sınıf adı birlikte.
- `: Car`: nesnenin adı önemli değil, yalnız türü önemli.
- `myCar`: addan türün anlaşıldığı durumda iki nokta üst üste ve sınıf adı yazılmayabilir (kısaltma).

**Soru (hocanın sorusu):** Kısaltma kullanıldığında bu kutuyu bir sınıftan ayıran nedir? **Cevap:** Alt çizgi. Üç gösterimin hepsinde ortak nokta nesne adının altının çizili olmasıdır.

### 5.1 Etkileşim şemaları

UML'de üst şema türü olarak **etkileşim şeması (interaction diagram)** tanımlıdır ve iki çeşidi vardır: sıralama şeması (sequence diagram) ve işbirliği şeması (collaboration diagram). İkisinin de amacı aynıdır: nesnelerin yaptığı metot çağrılarını ve bunların sırasını göstermek. İşbirliği şemaları daha kompakttır, ama çağrıların sırasını hem çizmek hem izlemek daha zordur; bu yüzden sektörde pek kullanılmaz. Sıralama şemalarının dezavantajı sağa doğru uzamasıdır, ama metotları ve çağrı sırasını daha net gösterdiği için tercih edilir. Derste yalnız sıralama şemaları işlenecek; hoca "etkileşim şeması" derse sıralama şemasını kastetmiş olacak.

## 6. Her Nesne Farklı Bir Bireydir

Slayt başlığı: "EACH OBJECT IS A DIFFERENT INDIVIDUAL!" (ekrandan, 00:30:00). Hoca bunun önemli bir slogan olduğunu söyledi.

Aynı sınıftan iki nesne düşünelim, örneğin yan yana park etmiş iki araba. İkisi de araba nesnesidir, yani aynı türden üyeleri ve aynı türden metotları vardır: ikisinin de plakasını öğrenme, çalıştırma ve satma metotları; model yılı ve renk üye alanları vardır. Durum bilgisinin bileşenleri aynıdır, ama bu bileşenlerin değerleri farklıdır: plakaları, renkleri, markaları, modelleri farklıdır. Yani durumları (state) farklıdır.

### 6.1 Aynı duruma sahip iki nesne olabilir mi?

Bir teknoparkta firmaların filo kiralamayla aldığı aynı marka, model ve renkte arabalar yan yana durabilir. Slayttaki örnek: aynı sarı Anadol STC'leri görseniz bile plakaları farklıdır (ekrandan, 00:30:00). Bir plaka sahtekârlığı (counterfeiting) yapılıp plakalar aynı yapılsa bile şasi numaraları farklıdır; şasi numarası da değiştirilse bir arabayı çalıştırınca öbürü kendiliğinden çalışmaz, birine çarpınca öbürü hasar görmez. Bunlar ayrı varlıklardır. Slayt bunu "sürücüleri farklı olacaktır" diye bağlar.

Yazılımda da durum budur. Plaka gibi bir tekil tanımlayıcının tekilliğini JVM kendisi takip etmez; bunu programcının yazacağı kod sağlamalıdır. Programcı bilerek ya da bilmeyerek aynı tekil tanımlayıcıya sahip iki nesne oluştursa bile JVM bu nesneleri ayrı yönetir. Yönetim işlemleri şunlardır: nesne için bellekte yer ayırmak, nesneye olan başvuruların sayısını tutmak, hiçbir nesne tarafından işaret edilmeyen nesneyi silinebilir olarak işaretlemek ve bellek azalınca silmek, bir metot çağrıldığında bellekteki sınıf kodunda ilgili koda gidip bytecode'u çalıştırmak. Bunların hepsi programcıya şeffaftır; Java programcısı bellek yönetimiyle uğraşmaz.

Bu yönetim için JVM her nesneye bir **evrensel tekil tanımlayıcı (universal unique identifier, UUID)** verir. Programcı bu tanımlayıcıya hiçbir şekilde müdahale edemez. Slayttaki ifade: "so transparent that you cannot interfere with" (ekrandan, 00:30:00). Durumu tamamen aynı iki nesne oluşturulsa bile JVM'nin atadığı evrensel tanımlayıcılar farklıdır.

> **Ek bilgi (derste anlatılmadı):** Java'da her nesne için JVM'nin içeride tuttuğu kimlik, programcıya doğrudan açık bir "UUID" alanı olarak sunulmaz; pratikte nesnenin bellekteki ayrı varlığı `==` karşılaştırmasıyla sınanır. `java.util.UUID` adlı ayrı bir sınıf da vardır, ama o programcının kendi tanımlayıcıları üretmesi içindir. Hocanın anlattığı tanımlayıcı büyük olasılıkla bu iç kimliktir.

### 6.2 Aynı mesaja farklı yanıt

Terminolojide bir nesneye mesaj göndermek, o nesnenin bir metodunu çağırmakla aynı anlamdadır. Aynı türden iki farklı nesneye aynı mesaj gönderilse de yanıtlar farklı olabilir, çünkü durumları farklıdır. Bir arabanın plaka öğrenme metodu çağrılınca 34 ile başlayan bir plaka, öbürününki çağrılınca 06 ile başlayan bir plaka döner. İkisinin de plakası ve plaka öğrenme metodu vardır, ama farklı bireylerdir. Ayrıca metotlara parametre tanımlanabilir; aynı türden farklı nesnelerin aynı metotları farklı parametrelerle çağrılırsa sonuçlar da elbette farklı olur.

## 7. Mesaj Gönderme ve Üye Erişimi

Slayt başlığı: "SENDING MESSAGES TO OBJECTS" (ekrandan, 00:40:00). Bir nesneye neden mesaj gönderilir, yani neden metodu çağrılır? İki temel neden vardır:

- Nesneye bir şey yaptırmak.
- Nesnenin bir üyesine erişmek.

Üye alanlara doğrudan erişilmediği, metotlar üzerinden erişildiği için üye alana erişim (member access) iki amaçla yapılır:

- Değerini değiştirmek: bu işleme **setting**, bunu yapan metoda **setter** metot denir.
- Değerini okumak: bu işleme **getting**, bunu yapan metoda **getter** metot denir.

Bir üye metoda erişmek ise o metodu, isteğe bağlı olarak parametre vererek, çağırmaktır. Bir metodu çağırmak C'de bir fonksiyon çağırmaya benzer. Ama şu hiç unutulmamalıdır: aksi belirtilmedikçe bir nesnenin metodu o nesnenin kendi üye alanlarıyla, kendi verisiyle çalışır. Slaytta "How come otherwise? Wait until you learn the different kinds of relationships between objects." yazar (ekrandan, 00:40:00). Nesneler arasında farklı ilişki türleri kurulabilir; bu ilişkiler sayesinde bir nesne başka nesnelerin varlığından haberdar olur ve onların metotlarını çağırabilir. Bu ilişki türleri sonraki haftalarda işlenecek.

Slayttaki terminoloji (ekrandan, 00:45:00): bir nesne başka bir nesnenin üyesine, o nesneye mesaj göndererek erişir; nesneye yönelik bir program nesneler arasında iletilen mesajlar şeklinde yürür.

## 8. Sıralama Şemasında Metot Çağrısı

### 8.1 Temel gösterim

Slayttaki şemada iki nesne vardır: `client` ve `kitt : Car` (ekrandan, 00:45:00). `kitt`'in plakasını tutan üye alanın adı `plate` olsun. Bu üye alanı okuma işlemi getting olduğu için metodun adı `getPlate` olur.

Şemanın öğeleri şunlardır:

- Metot çağrısı, düz çizgili ve ucu siyah kapalı okla gösterilir; metodun adı çizginin üstüne yazılır: `getPlate( )`.
- Bir nesnenin metodu çalıştığı süre ince uzun bir dikdörtgenle gösterilir. Bir nesne metodu çağrıldığı anda **aktif** olur; metodu çağrılmadığında yalnız bellekte durur ve bir çağrı bekler.
- Sıralama şemalarında Y ekseninde aşağı inildikçe zamanda ileri gidilir.
- Metodun dönüşü, kesikli çizgili ve ucu açık okla gösterilir. Metot bir şey döndürüyorsa dönen şey bu okun üstüne yazılır: `plate`.

Bu şemayı oluşturan komut `kitt.getPlate();` biçimindedir. C'deki fonksiyonlarda olduğu gibi metotlar parantezlerle gösterilir; metot parametre almasa da boş parantez yazılır. Normalde her zaman belirli bir nesnenin belirli bir metodu `nesne.metot()` biçiminde çağrılır; istisnaları ileride görülecek. `kitt` nesnesinin bir yerde tanımlanıp oluşturulması da gerekir; bu da ileride görülecek.

Slayttaki "Meaning of this figure" listesi şemayı şöyle okur: `client` adlı bir nesne var, sınıfı önemsiz; `kitt` adlı bir nesne var, sınıfı `Car`; `Car` sınıfının `getPlate` adlı bir metodu var; `client`, `kitt`'e `getPlate` mesajını gönderir; `kitt` de plakasını yanıt olarak döndürür (ekrandan, 00:50:00).

### 8.2 Adlandırma: camel casing

Metot adları küçük harfle başlar. Birden fazla kelime birleştirilerek ad oluşturulduğunda ikinci kelimeden itibaren her kelimenin ilk harfi büyük yazılır (`getPlate`). Buna **camel casing** denir: büyük harfler satırdan yukarı çıkarak devenin hörgücüne benzer. Bu, adın okunup anlaşılmasını kolaylaştırır.

### 8.3 client kimdir?

Bir öğrencinin sohbetten sorduğu soru üzerine hoca `client`'ı açıkladı. `client`'ın kim olduğu, türü önemli değildir; başka bir `Car` nesnesi de olabilir, başka bir sınıftan bir nesne de. Metotlara iki temel erişim kuralından biri verilir: `public` metot herkes tarafından çağrılabilir, `private` metot yalnız aynı türden nesneler tarafından çağrılabilir. Bir nesnenin public metodu çağrıldığında nesne, çağıran kim olursa olsun metodu yürütüp sonucu döndürmekle yükümlüdür. Hatta normalde metodu kimin çağırdığını bilmez. Bunu bilmesinin tek yolu, çağıranın kendisini o metoda parametre olarak vermesidir.

Hoca şemada `client`'ı çizmeyebileceğini, yalnız `kitt`'e giren `getPlate` okunu ve `plate` dönüş okunu çizmenin yeterli olduğunu söyledi. `client`'ı çizmesinin iki nedeni vardır: her metodun bir çağıranı olduğunu göstermek ve Violet UML Editor'de başlangıç ucu boşta kalan bir ok çizilememesi. Araç yalnız kaynağın activation bar'ından hedefin activation bar'ına ok çekmeye izin verir. `client` silinince ona bağlı metot okları da silinir.

**Soru:** `client`'ın okları neden activation bar'ın ortasından başlıyor? **Cevap:** Ok, elle çizerken üst köşeye denk getirilmek zorunda değildir; biraz aşağıdan da başlayabilir. Özellikle bir nesne ilklendirilirken oku hedef dikdörtgenin üst köşesine denk getirmeye biraz özen gösterilir. Ortadan başlamasının nedeni, hocanın tahminine göre, metot çağrılmadan önce `client`'ta da bir şeyler yapılmış olmasıdır; hiçbir şey yapılmasa bile çağrıyı başlatmak için arka planda yürütülen bytecode'lar vardır. Önemli olan, ok başlangıcını dikdörtgenin üst çizgisiyle aynı hizada çizmemektir.

**Soru:** Activation bar hangi durumlarda kullanılır? **Cevap:** Bir nesnenin başka bir nesneye metot çağrısı yaptığı ya da bir nesnenin metodunun çağrıldığı durumlarda kullanılır; diğer zamanlarda kullanılmaz.

### 8.4 İkinci çağrı: getModelYear

Hoca şemaya ikinci bir çağrı ekledi: `client` önce `getPlate( )` ile plakayı, sonra `getModelYear( )` ile model yılını alıyor, dönüşte `modelYear` yazıyor (ekrandan, 00:55:00). Bu durumda `client`'ın activation bar'ı (yaşam çizgisi de denir) hiç bölünmez, ama `kitt`'in activation bar'ı iki parçaya bölünür; hoca bunu nunçakuya benzetti. Activation bar nesnenin aktif olduğu süreyi gösterir.

Farkın iki nedeni vardır:

- Sıralama şemasında yalnız metot çağrıları gösterilir. Bir nesnenin kendi metodu içinde yaptığı atamalar gibi işlemler gösterilmez. `client` plakayı aldıktan sonra belki ekrana yazdırmıştır; bu gösterilmez. Ekrana yazmak için `System` sınıfının statik `out` üyesinin `println` metodu çağrılır, ama şemaya bir `System.out` nesnesi çizilip `println` çağrısı gösterilmez. Yalnız problem alanındaki nesneler arasındaki çağrılar gösterilir.
- `getPlate` ile `getModelYear` çağrıları arasında `client`'ta da başka komutlar yürütülmüştür; bu yüzden `client` bütün akış boyunca aktiftir. `kitt` ise yalnız metodu çağrıldığı ve işlendiği sürece aktiftir; metot bitince yalnız bellekte durur.

## 9. Paketler

Aynı amaca yönelik sınıflar ya da aynı problemin farklı parçaları olan sınıflar **paket (package)** adı verilen soyut kapsayıcılarda toplanabilir (ekrandan, 01:10:00). Fiziksel olarak paket bir klasöre denk gelir. Sınıf şemalarında paket, etiketi olan büyük bir dikdörtgen (klasör) olarak çizilir ve içine sınıfların dikdörtgenleri çizilir. Paket içinde paket olabilir. Slayttaki örnekte `package1` içinde `ClassA`, `ClassB` ve `package2` vardır; `package2` içinde de `ClassC` vardır.

Bu sınıfları kendi kodumuzda kullanmak için `import` komutu verilir; C'deki `#include`'a karşılık gelir. Slayttaki komutlar (ekrandan, 01:10:00):

```java
import package1.ClassA;
import package1.*;
import package1.package2.*;
```

- `import package1.ClassA;` yalnız `ClassA`'yı yazılan sınıf koduna dahil eder; artık `ClassA`'dan nesne oluşturulup kullanılabilir.
- `import package1.*;` `package1`'deki tüm sınıfları dahil eder. Yalnız `ClassA` kullanılsa bile tüm paketi import etmenin bir sakıncası ya da ek yükü yoktur, çünkü yalnız kodda kullanılan sınıfların bytecode'larıyla ilişkilendirme yapılır.
- Yıldız, alt paketleri ve onların sınıflarını **kapsamaz**. `ClassC` gerekiyorsa `import package1.package2.*;` ya da `import package1.package2.ClassC;` yazılmalıdır.

Paketlerin bir yararı, farklı paketlerdeki aynı adlı sınıfların karışmadan kullanılabilmesidir. Java'nın sınıf kitaplığındaki `java.io` paketinde bir `File` sınıfı vardır (ileriki haftalarda görülecek). Daha yetenekli ya da farklı yetenekli bir `File` sınıfı yazılıp `com.fileWizard` adlı bir pakete konabilir; çakışma olmaz. Projede bu iki paketten yalnız biri dahil edilmişse yalnız `File` yazmak yeter. İkisi birden aynı dosyada kullanılacaksa her seferinde hangi `File`'ın kastedildiği uzun uzun yazılmalıdır. `paketAdı.SınıfAdı` biçimindeki bu tam ada **fully qualified name** denir.

**Soru:** `java.io.File` için makro gibi bir şey tanımlayıp tek bir sözcükle ifade edebilir miyiz? **Cevap:** Hayır. İki kütüphane de import edilmiş ve ikisi birden kullanılıyorsa her seferinde tam ad yazılmak zorundadır.

> **Ek bilgi (derste anlatılmadı):** Java'da C'deki `#define` gibi bir makro mekanizması yoktur. Bu durumda yaygın yol, sınıflardan birini import edip kısa adıyla, öbürünü her yerde tam adıyla kullanmaktır; yani yalnız birinin tam adla yazılması da yeterlidir.

Her paket diskte bir klasördür. `com.fileWizard` paketindeki `File` sınıfının kodu, proje dizininin altındaki `com` klasörünün içindeki `fileWizard` klasöründe bulunan `File.java` dosyasındadır. Slayttaki gösterim: `com.fileWizard.File -> com\fileWizard\File.java` (ekrandan, 01:10:00).

## 10. Görünürlük Kuralları ve Bilgi Gizleme

Slayt başlığı: "VISIBILITY RULES AND INFORMATION HIDING" (ekrandan, 01:25:00). Hoca bunu nesne yönelimdeki çok önemli bir kural olarak tanıttı.

Temel dinamik şudur: bir nesne kendi sınıfından olan tüm diğer nesnelerin tüm üyelerine, hiçbir kısıtlama olmadan, her zaman erişebilir. Aynı türden nesnelerin birbirinin üye alanlarına ve metotlarına erişimi ne yapılırsa yapılsın kısıtlanamaz. Farklı türden nesnelerin bazı üyelere erişimi ise kapatılabilir ya da kısıtlanabilir, ve kısıtlanmalıdır da.

### 10.1 Bilgi gizleme ilkesi

Bunun nedeni **bilgi gizleme ilkesidir (information hiding principle)**. Bu ilke nesneleri bir kara kutu gibi kullanmayı sağlar. Bir nesnenin iç çalışma ayrıntılarıyla ilgili üyeler saklanır, erişime kapatılır. Böylece o nesneyi kullanmak isteyen diğer nesneler onun iç yapısını bilmek zorunda kalmaz, yalnız dışarıya açtığı erişim yollarını kullanarak onunla çalışır.

Hocanın televizyon benzetmesi: televizyonu açıp kullanmak için kumandadaki evrensel işaretli düğmeleri (açma-kapama, kanal ileri-geri, ses) tanımak yeter. Eski tüplü bir televizyonda katot tüpü ekrana elektron gönderir, görüntü sol üst köşeden başlanarak satır satır taranır, bu tarama saniyede elli ile altmış kez arasında tekrarlanır; PAL ve NTSC gibi farklı standartlar vardır. Yeni bir LCD televizyonda her nokta kırmızı, yeşil ve mavi üç küçük sıvı kristalden oluşur ve uygulanan akıma göre ilgili noktacık etkinleşir. Kullanıcının bunların hiçbirini bilmesi gerekmez. Gerekseydi her yeni televizyon türü icat edildiğinde onun da iç yapısını öğrenmek gerekirdi. Mühendisler iç yapıyı gizlediği için birkaç temel tuşla kullanılabilir. İleri düzey özellikler için kumandada daha ayrıntılı tuşlar vardır; bunlar markadan markaya değişebilir, ama aynı markanın modellerinde genelde aynı yerdedir.

Hocanın ikinci, "teknik olarak tam doğru değil ama akılda kalıcı" benzetmesi: biri borç para isterse ona cüzdandan istenen miktar verilir; kredi kartı ve şifresi verilmez. Kart ve şifre verilirse karşı taraf hesaptaki tutarı görür, belki para çekip kaybolur, ya da hesap sahibinin mali durumu ortaya çıkar. Bunun yerine borç isteyen kişi "borç iste" metodunu çağırır, karşı taraf da "borç ver" metoduyla istenen miktarı döndürür. Teknik olarak doğru olmayan yan şudur: aynı türden nesneler birbirinin her üyesine erişebildiği için, insanlar aynı sınıftan bilgisayar nesneleri olsaydı her şeyleri birbirine açık olurdu.

### 10.2 public ve private

Temel iki görünürlük kuralı (access modifier, visibility rule) vardır (ekrandan, 01:25:00):

- **public:** "There are no access restrictions to public members." Her türden nesne public üyelere istediği zaman erişebilir.
- **private:** "Objects of different types cannot access each other's private members." Farklı türden nesneler birbirinin private üyelerine erişemez.

### 10.3 Diğer kurallar: protected ve package

Slaytta bu iki kuralın derste sorumluluk dışı olduğu yazılıdır ("you are not responsible from those in this class"), ama bilinmeleri gerekir (ekrandan, 01:25:00):

- **protected** (UML'de `#`): Kalıtımla ilgilidir. Hoca bunu "normalde private gibi davranır, kalıtımla türetilen alt sınıflar (subclass) için public gibi davranır" diye anlattı. Java, C#, C++ gibi birçok nesne yönelimli dilde vardır.
- **package** (UML'de `~`): Java'ya özgüdür. Aynı paketteki tüm sınıflardan nesneler için public, farklı paketlerdeki sınıflar için private gibi davranır.

> **Ders sonrası not:** Hoca protected'ı yalnız alt sınıflara açık olarak anlattı. Slaytta da yazdığı gibi ("visible to package and subclasses"), Java'da protected üyeler alt sınıflara ek olarak aynı paketteki tüm sınıflara da açıktır.

Ne yazık ki package, Java'daki varsayılan kuraldır: bir üye için public, private ya da protected yazılmazsa üye package kuralına sahip olur. Package aynı paketteki tüm sınıflara public gibi davrandığı için bilgi gizleme ilkesine uymaz. Ayrıca sınıflar bir paket altında toplanıp kod dağıtılırken paket mühürlenmezse (sealed), dışarıdan bir programcı o pakete kendi sınıflarını ekleyebilir ve package kurallı üyelere istediği gibi erişip bilerek ya da bilmeyerek yanlış işler yapabilir.

> **Hocanın vurgusu:** Yazılan Java kodlarında her üye için `public` ya da `private` anahtar kelimesi açıkça yazılmalı, şemada da `+` ya da `-` konmalıdır. Konmazsa bilgi gizleme ilkesine zararlı yan etkiler ortaya çıkar.

### 10.4 Ne private, ne public olur?

Bir nesnenin en iç ayrıntıları üye alanlarıdır. Bu yüzden üye alanlar **her zaman private** tanımlanır. Metotlar ise genelde herhangi bir türden nesneye hizmet vermek için yazılır, bu yüzden genelde public tanımlanır. İstisna: çağrılması nesnenin durumunu normalde ulaşmaması gereken noktalara taşıyabilecek, dışarıdan keyfi bir sırada çalıştırılırsa nesnenin iç düzenini bozacak kritik metotlar private yapılır, hem UML şemasında hem kodda. Temel kural, varlığın iç yapısıyla ilgili üyelerini private yapmaktır; hangi metodun public, hangisinin private olacağına çözülen probleme göre karar verilir. Bu karar her zaman mükemmel verilemeyebilir, ama elden gelen yapılır.

Bilgi gizlemenin bir yararı daha vardır. Bir sınıf başka bir sınıfı kullanıyorsa ona bağımlıdır. Kullanılan sınıfın kodunda değişiklik yapılırsa, onun metotlarını çağıran sınıflar bundan olumsuz etkilenebilir; örneğin onlardaki bazı hesaplamalar artık hatalı sonuç verebilir, başka yerlerde hatalar (bug) ortaya çıkabilir. Nesne kara kutu olarak, iç ayrıntılarına bağımlı olmadan kullanılıyorsa, iç ayrıntılarda yapılan değişikliklerin ona bağımlı nesnelerde hataya yol açma olasılığı düşer.

Getter ve setter metotlarının ikisine birlikte **erişim metotları (access methods)** denir. Setter bir üye alanın değerini değiştirmek için, getter değerini değiştirmeden öğrenmek için kullanılır. Adları, üye adının başına `get` ya da `set` eklenerek ve camel casing'e uyularak verilir.

## 11. UML Sınıf Şeması

### 11.1 Üç bölmeli dikdörtgen

UML sınıf şemasında dikdörtgen üç bölmeye (kompartman) ayrılır (ekrandan, 01:25:00):

- Üst bölmede yalnız sınıf adı bulunur; genelde ortalanır.
- Orta bölmede üye alanlar bulunur.
- Alt bölmede üye metotlar bulunur.

Slayttaki şablon:

```text
ClassName
-----------------------------------------------------------
- aPrivateField : TypeOfField
-----------------------------------------------------------
+ aPublicVoidMethod( )
+ aPublicMethod( ) : ReturnType
+ aMethodWithOneParameter( param1 : Param1Type )
+ manyParameteredMethod( param1 : P1Type, param2 : P2Type )
```

Kurallar:

- Private `-`, public `+` ile gösterilir.
- Üye alan `ad : Tür` biçiminde yazılır.
- Metot adından sonra, parametre almasa bile, parantezler yazılır. Metot bir şey döndürmüyorsa dönüş türü yazılmaz (`aPublicVoidMethod( )`).
- Metot değer döndürüyorsa kapanış parantezinden sonra iki nokta üst üste ve dönüş türü yazılır.
- Parametreler parantez içinde `ad : Tür` biçiminde, birden fazlaysa virgülle ayrılarak yazılır.
- Dikdörtgen yalnız üç bölmelidir. Bazı öğrenciler her üyenin altına çizgi çekiyor; hoca bunun doğru olmadığını söyledi.

### 11.2 Örnek: Car sınıfı

Slayttaki örnek (ekrandan, 01:35:00):

```text
Car
--------------------------
- plate : String
--------------------------
+ getPlate( ) : String
+ setPlate( String )
```

Sınıf adı `Car` büyük harfle başlar. Private üye alan `plate`, aracın plakasıdır; türü `String`'dir. `String`'deki S büyüktür, çünkü `String` bir sınıftır: `java.lang` paketindedir ve karakter katarlarını modellemeye yarar. `getPlate` metodu `plate` alanının getter'ıdır; plakayı döndürdüğü ve plakanın türü `String` olduğu için `String` döndürür. `setPlate` bir şey döndürmez, gerek de yoktur; yalnız "yeni plakan şudur" diye bir atama yapar ve bunun başarısız olması söz konusu değildir. Parametre olarak yeni plakayı, yani bir `String` alır. UML'de bu parametrenin yalnız türü yazılmış, adı yazılmamıştır; asıl önemli olan türdür.

Slaytta erişim izinlerinin kolayca değiştirilebileceği anlatılır (ekrandan, 01:35:00):

- Plakanın değiştirilmesi kısıtlanacaksa slayta göre `setPlate` koddan kaldırılır; hoca bunu sözlü olarak `setPlate`'i private yapmak diye anlattı. Böylece başka sınıftan hiçbir nesne bir arabanın plakasını keyfince değiştiremez.
- Yalnız aynı paketteki sınıfların değiştirmesine izin verilecekse `setPlate`'in görünürlüğü package yapılır.

Akla gelen soru: setter private yapılırsa araç ilk oluşturulurken plaka nasıl verilecek? Bunun cevabı kurucu metotlardır (Bölüm 13). Önemli olan, `plate` private tanımlandığı sürece bu seçeneklerin hepsinin programcının elinde olmasıdır. `plate` public yapılırsa hiçbiri elde kalmaz, isteyen istediği gibi plakayı değiştirir.

## 12. Üyelerin Özel Durumları: static ve final

Buraya kadar anlatılan normal davranışlardı: her nesne farklı bir bireydir, durumları farklıdır, aynı metoda farklı yanıt verebilir. Bazen bu davranışların farklı işlemesi gerekir. Bunlar üyelerin özel durumlarıdır (special cases of members).

### 12.1 static üye alanlar

`static`'in anlamı **ortak kullanımdır (sharing)**. Slaytta "share" kelimesi koyu ve altı çizili yazılmıştır (ekrandan, 01:40:00).

> **Hocanın vurgusu:** Bu kavramlar Türkçe karşılıklarıyla akılda tutulmamalı, yoksa final ile karışır. static = ortak kullanım.

Bazı durumlarda aynı türden bütün nesnelerin ortak bir üye alanı paylaşması istenebilir. Bu durumda üye alan `static` anahtar kelimesiyle işaretlenir ve o sınıftan her nesne tarafından ortak olarak kullanılır. Madem tüm nesneler kullanıyor, bu üye alana nesneden bağımsız olarak, `SınıfAdı.üyeAdı` biçiminde erişilebilir (slayt: `ClassName.memberName`, "not via the objects").

Örnek: her otomobilin dört tekerleği vardır; üç ya da beş olamaz. Bir yarış oyununda arabalar ekrana çizilirken dört tekerlek çizilir (bakış açısına göre biri görünmese de). Tekerlek sayısı normal bir üye alan olsaydı, her araba nesnesi için bellekte ayrıca yer ayrılırdı. Hepsinde değer 4 olduğu halde her nesne için bir tam sayı kadar yer (hoca 4 bayt dedi) harcanırdı; bu israftır. Ayrıca yeni bir araba oluşturulduğunda tekerlek sayısını 4'e atamak unutulabilirdi. Alan statik tanımlanınca tüm araba nesnelerinin bu üyesi bellekte aynı yeri gösterir; bellekten tasarruf edilir ve yanlış değer atanması bir ölçüde engellenir.

Ama yazılacak yarış simülasyonunda bir lastiğin patlaması gibi durumlar olacaksa tekerlek sayısını statik yapmak doğru olmaz.

### 12.2 static üye metotlar

Normalde aynı türden iki nesne aynı mesaja farklı yanıtlar verebilir. Bazı durumlarda ise aynı türden tüm nesnelerin belli bir metodunun tamamen aynı biçimde çalışması istenebilir. Bu metot da `static` ile tanımlanır ve nesne üzerinden değil, doğrudan `SınıfAdı.metot()` biçiminde çağrılabilir. Slaytta ek olarak, statik bir metot içinde yalnız statik üyelerin kullanılabileceği yazar: "You may only use static members of an object within a static method of this object." (ekrandan, 01:45:00)

Hoca bunu eski bir Türk filmi serisiyle örnekledi. Bir Osmanlı akıncısı yakalanıp Bizans zindanına atılır. Bizanslılar onu yüzünden tanımaz. Gardiyan kapıyı açıp "Kara Murat kim?" diye sorduğunda zindandaki bütün Türk mahkumlar "Kara Murat benim" der. Yani her mahkum nesnesinin `getName` metodu çağrıldığında, kendi adından bağımsız olarak, hepsi aynı yanıtı döndürür. Statiğin anlamı budur.

### 12.3 main neden statiktir?

Bir önceki derste "Merhaba Dünya" yazdırmak için `main` metodu statik işaretlenmişti. Nedeni: program başlarken henüz hiçbir nesne oluşturulmamıştır. Nesneye yönelik program nesnelerin metotlarının çağrılmasıyla yürür, ama ortada nesne yoktur. Bu yumurta-tavuk meselesi, denetim akışının başlangıç metodu olan `main`'in statik tanımlanmasıyla çözülür. Sınıfın bytecode'u belleğe yüklenmiştir ve `main`'e sınıf adı üzerinden erişilebilir. Yapısal programlamada böyle bir dert yoktur: fonksiyon tanımlıysa adıyla çağrılır. Nesne yönelimde ise nesne ve metotları ayrılmaz bir bütün olduğu için bir metodu çağırmadan önce nesnenin oluşturulmuş olması gerekir.

### 12.4 final üye alanlar ve metotlar

Final üye alanın anlamı: üye alana **yalnız bir kez** değer atanabilir ve bu değer daha sonra hiçbir zaman değiştirilemez (ekrandan, 01:50:00). Tekil tanımlayıcılar için genelde böyle bir durum vardır. Örneğin kimlik numarası bir kez atanır, kişinin hayatı boyunca ve öldükten sonra da değişmez, kayıt hep aynı numarayla tutulur. Slayttaki örnek şasi numarasıdır: fabrikada şasiye kazınır ve sonra değiştirilemez.

Bu tek atama genelde nesne ilk oluşturulurken yapılır. Nesne oluşturmak için kurucu metotlar tanımlanıp çağrılır (Bölüm 13).

Final üye metotların kalıtımla ilgisi vardır. Kalıtımla türetilen yeni sınıflar mevcut sınıfın bazı metotlarının gövdesini değiştirme hakkına sahiptir; ama bir metot `final` tanımlanırsa alt sınıflarda yeniden tanımlanamaz, gövdesi değiştirilemez. Slayt: "These cannot be overridden (inheritance will be taught later)." Kalıtım işlendiğinde bu konu yeniden anlatılacak.

### 12.5 Dikkat edilecek noktalar

Slayttaki "POINTS TO CONSIDER" (ekrandan, 01:50:00):

- Bir üye aynı anda hem `final` hem `static` olabilir.
- final ile static karıştırılmamalı: **final = yalnız bir kez (only once)**, **static = ortak kullanım (shared usage)**.
- UML sınıf şemasında gösterimi: `aMember : Type {final,static}`.

Hem final hem static olan bir üye alan evrensel sabit niteliğindedir; örneğin pi sayısı (3.1416...). Her yerde ortak kullanılır ve asla değişmez. `Math` sınıfında bir pi üye alanı tanımlanıyorsa hem final hem static tanımlanabilir ve **public** yapılmasında sakınca yoktur: final olduğu için değiştirilemez, private yapıp erişim metodu vermenin anlamı yoktur. Bu tek istisnadır; aksi halde üye alanlar hep private tanımlanır.

UML'de final ya da static durumu, ilgili üyenin yanına kıvrık parantez içinde yazılır: yalnız final ise `{final}`, yalnız static ise `{static}`, ikisi birden ise `{final,static}`. Hoca bu kıvrık parantezlerin metot gövdesiyle karıştırılmaması gerektiğini söyledi.

## 13. Kurucular ve Sonlandırıcılar

Slayt başlığı: "CONSTRUCTORS AND FINALIZERS" (ekrandan, 02:05:00).

### 13.1 Kurucu metot

Constructor Türkçeye ilklendirici, yapılandırıcı ya da kurucu diye çevriliyor; ortak bir uzlaşı yok. Hoca "kurucu" demeyi tercih ediyor. Kurucu metotlar, bir nesne oluşturulacağı zaman programcının açıkça (explicitly), kodda yazarak çağırdığı metotlardır. Bir nesnenin üye alanlarına ilk değerlerini atamak için kullanılır ve bunun için en uygun yerdir. Slayt: "We will pay a significant attention to constructors in this class."

### 13.2 Sonlandırıcı metot

Sonlandırıcı (finalizer) metot, C++ jargonundaki destructor'a karşılık gelir. Bir nesne bellekten tamamen kaldırılacağı, yok edileceği zaman JVM tarafından örtük olarak (implicitly) çağrılır; kurucunun aksine programcı onu çağırmaz. Adı `finalize`'dır. Sınıfta yalnız bir tane olabilir (kurucu ise birden fazla olabilir); parametre almaz, bir şey döndürmez. C/C++'ın aksine Java programcıları bellek yönetimiyle uğraşmak zorunda olmadığı için derste sonlandırıcılar daha fazla işlenmeyecek.

Bir nesne artık kullanılmadığında, örneğin bir bağlı listeden çıkarılan ve artık hiçbir şeyin işaret etmediği bir düğüm, bellekte yer tutmasına gerek kalmaz. Ama JVM bir nesne geçersiz olur olmaz devreye girmez. Arka planda **çöp toplayıcı (garbage collector)** adı verilen bir süreç çalışır; hiçbir işaret almayan nesneleri silinebilir olarak işaretler. Nesneler ancak JVM'ye ayrılan bellek azalmaya yüz tuttuğunda gerçekten silinir.

Hoca, bir Java uygulaması varsayılan ayarlarla çalıştırıldığında JVM'ye 256 MB bellek ayrıldığını söyledi. Bu yüzden `finalize`'ın çalıştığını görmek için milyonlarca nesne oluşturup bırakmaya çalışmak zahmetlidir; 256 MB'ı tüketmek kolay değildir. Daha fazla bellek gereken işlerde (örneğin görüntü işleme) JVM bir parametreyle daha büyük bellekle başlatılabilir.

> **Ders sonrası not:** JVM'nin varsayılan en büyük yığın (heap) boyutu sabit 256 MB değildir; güncel JVM'lerde büyük olasılıkla makinenin fiziksel belleğinin yaklaşık dörtte biridir. Bellek sınırı `-Xmx` parametresiyle (örneğin `-Xmx2g`) değiştirilir. Ayrıca `finalize` metodu Java 9'dan beri kullanımdan kaldırılmış (deprecated) durumdadır.

### 13.3 Kurucu kuralları

Kurucu tanımlarken uyulması gereken kurallar vardır; uyulmazsa derleme hatası alınır ya da metot kurucu olmaz, sıradan bir metot olur:

- **public olurlar.** Hoca derste private kurucu tanımlanmayacağını söyledi. Private kurucunun işe yaradığı kısıtlı alanlar vardır (örneğin Singleton tasarım kalıbı), ama derste gerekmeyecek. Normalde sınıflar nesne oluşturup kullanmak için yazılır; bir sınıfın kurucuları private olursa o sınıftan dışarıda hiç nesne oluşturulamaz.
- **Adı sınıfın adıyla aynıdır.** `Car` sınıfının kurucusu büyük C ile `Car` adlı metottur.
- **Dönüş türü yoktur.** Kurucular nesne oluşturmak için kullanılsa da gövdelerinde `return` verilmez. Normalde bir şey döndürmeyen metoda `void` yazılır, kurucuda `void` bile yazılmaz; yalnız `public SınıfAdı(...)` diye başlanır.
- **new ile çağrılır.** Örneğin daha önce tanımlanmış `kitt` adlı `Car` nesnesini ilklendirmek için `kitt = new Car();` yazılır.

> **Ders sonrası not:** Hoca "private kurucu tanımlayamayız" diye başladı, sonra Singleton gibi istisnalardan söz etti. Java dili kurucuların `private`, `protected` ya da package görünürlüğünde olmasına izin verir; "public olur" kuralı bu dersin kuralıdır.

Parametre almayan kurucuya **varsayılan kurucu (default constructor)** denir. Çoğu zaman varsayılan kurucular yetmez, parametreli kurucular yazılır.

### 13.4 Nesneyi örneklendirmek

Slayt: "Defining an object is not enough to use it, you need to *instantiate* it by executing its constructor." (ekrandan, 02:10:00). Bir nesneyi tanımlamak onu kullanmak için yetmez, ilklendirmek (instantiate, örneklendirmek) gerekir. Bu da yalnız kurucu çağrılarak yapılır.

Sıralama şemasında ilklendirme, nesnenin dikdörtgenine giren ve üstünde `new` yazan bir okla gösterilir. Kurucunun adını yazmaya gerek yoktur, `new` yeterlidir; parametre varsa parantez içinde verilir. Ardından dönüş oku çizilir. Slayttaki şema PowerPoint'te çizildiği için okun başlangıç ucu boştadır. Hoca, Violet UML Editor'de çizip resim olarak kaydettikten sonra baştaki kısmı bir resim düzenleyiciyle kesmenin de bir yol olduğunu söyledi.

### 13.5 Üye alan olarak nesne ve geçici nesne

Slayttaki iki kod (ekrandan, 02:10:00):

```java
public class AClass {
   private Car kitt;

   someMethod( ) {
      kitt = new Car();
   }
}

public class AnotherClass {
   someMethod( ) {
      Car kitt = new Car();
   }
}
```

- **AClass:** `kitt`, `Car` türünden bir üye alandır ve `private` tanımlanmıştır. Her nesne farklı bir birey olduğu için her `AClass` nesnesinin `kitt` alanı bellekte farklı bir yeri gösterir. Sınıfın bir metodunda bu alan varsayılan kurucuyla ilklendirilir. Bir `AClass` nesnesi yaşadığı sürece `kitt`'e erişilebilir.
- **AnotherClass:** Üye alanlarında `Car` geçmez. Bir metodun içinde `kitt` hem tanımlanır hem hemen varsayılan kurucuyla ilklendirilir. Başına `public` ya da `private` yazılmaz, çünkü bu bir üye alan değil, metot içinde tanımlanmış **geçici nesnedir**. Geçerliliği yalnız metot çalışırken sürer; akış metot gövdesinin kapanış parantezine gelince bellekten silinmek üzere işaretlenir.

Görünürlük kuralları yalnız üyelere, yani üye alanlara ve üye metotlara özgüdür; geçici nesnelerde kullanılmaz.

> **Ek bilgi (derste anlatılmadı):** Slayttaki `someMethod( )` tanımlarında dönüş türü yazılmamıştır; slayt kavramı göstermek için kısaltılmıştır. Gerçek Java kodunda bu metotlar örneğin `void someMethod( )` biçiminde yazılmalıdır, yoksa derleyici onları geçersiz bir kurucu tanımı sayıp hata verir.

### 13.6 Varsayılan kurucu ve aşırı yükleme

Slayttaki maddeler (ekrandan, 02:15:00):

- Varsayılan kurucu parametresiz kurucudur. Programcı hiç kurucu yazmazsa otomatik ve örtük olarak tanımlanır.
- Parametreli kurucularda parametreler ilk değer atamak için kullanılır. Programcı açıkça parametreli bir kurucu yazarsa varsayılan kurucu otomatik oluşturulmaz; gerekiyorsa programcı yazar. Ama iş mantığı genelde parametreli kurucu gerektirir ve varsayılan kurucuyu yasaklar.
- Bir sınıfın türleri ve sayıları farklı parametreler alan birden fazla kurucusu olabilir. Buna **constructor overloading** denir. Sıradan metotlar da aşırı yüklenebilir.

Otomatik eklenen varsayılan kurucunun yaptıkları: nesnenin tüm durumu ve metot kodlarıyla bellekte saklanabileceği yeri ayırır, nesneyi oluşturur, programcıdan şeffaf bir evrensel tekil tanımlayıcı oluşturup nesneyle ilişkilendirir, üye alanlara ilk değer atar: sayısal ilkellere 0 ya da 0.0, mantıksal alanlara false, nesne türündeki alanlara null. Tek yaptığı budur ve bu yetmeyecek. Programcı kendi varsayılan kurucusunu da yazabilir; o zaman otomatik olan eklenmez. Ama nesnelerin bir tekil tanımlayıcısı olacağı ve ona parametreyle ilk değer verilmesi gerekeceği için varsayılan kurucular bu derste genelde tercih edilmeyecek.

> **Ders sonrası not:** Hoca varsayılan kurucuyu "Java sanal makinesi bytecode olarak ekler" diye anlattı. Bu kurucuyu büyük olasılıkla JVM değil, derleme sırasında Java derleyicisi (`javac`) `.class` dosyasına ekler.

Aşırı yüklemede kurucuları birbirinden ayıran şey parametre listesidir; listede önemli olan parametrelerin türleridir. Aynı adlı ama parametre listeleri farklı birden fazla metot tanımlamaya **overloading**, bu metotlara **overloaded** metot denir. Bu yalnız kurucular için değil, her metot için geçerlidir.

> **Hocanın vurgusu:** Kurucular o kadar önemlidir ki, bir soruda verilen UML sınıf şemasında kurucu gösterilmemiş olsa bile sınıfın kaynak kodu istendiğinde kurucu da yazılmalıdır. Bunun nedeni yalnız ders değil, iş mantığıdır.

## 14. Denetim Akışı ve main Metodu

Denetim akışı (control flow), komutların yürütülüş sırasıdır. `if` gibi karar komutları ve `for`, `while` gibi döngülerle doğrusal akış dallanmalı ya da döngülü akışa çevrilir. Java programında denetim akışının başlangıç noktası `public static void main` metodudur.

Bir sınıfa `main` metodu yazmak, onun mutlaka çağrılacağı anlamına gelmez; bu her metot için böyledir. Sınıf yazılır, içine metotlar eklenir; başka bir sınıfta bu sınıftan nesne oluşturulup kullanılabilir, ama yazılan bütün metotların çağrılacağının da çağrılmayacağının da garantisi yoktur. Birden fazla sınıftan oluşan bir yazılımın bir özel başlangıç noktası vardır, ama içindeki farklı sınıfların `main` metotları o sınıfları tek tek test etmek için kullanılabilir.

**Soru:** Bir paket içinde birden çok sınıfta `main` olursa hata almaz mıyız? **Cevap:** Hayır. Her `main` yalnız kendi sınıfına aittir; A sınıfının `main`'i ile B sınıfının `main`'i farklıdır. Yalnız aynı sınıfa birden fazla `main` yazılamaz, çünkü aynı metot imzasına sahip tek bir metot olabilir. İkinci bir `public static void main(String[] args)` yazılırsa yineleme (duplicate) derleme hatası alınır. Parametre listesi değiştirilirse de o metot artık denetim akışının başlangıcı olma özelliğini kaybeder.

## 15. Uygulama: Car Sınıfı

Hoca Eclipse'te bir proje içinde `hafta02` adlı bir paket açtı ve içine `Car` sınıfını yazdı. Ders notlarındaki tüm kodların paylaşıldığını, ama burada baştan yazacağını söyledi.

### 15.1 Üye alan ve kurucu

Tek üye alan `private String plate;` biçiminde yazıldı. Eclipse yeni açılan her blokta otomatik olarak bir adım girinti bırakır; her blokta girinti kullanmak okunabilirliği önemli ölçüde artırır.

UML ile Java arasında bir sıra farkı vardır: UML'de `görünürlük ad : Tür` (`- plate : String`), Java'da `görünürlük Tür ad;` (`private String plate;`) yazılır. Bu sıralar birbirine karıştırılmamalıdır.

Kurucu `public Car( String plateNr )` olarak yazıldı: `public`, ardından dönüş türü yazılmadan doğrudan sınıf adı. Parametre önce tür, sonra ad biçiminde yazılır. Gövdede `plate = plateNr;` ile parametre üye alana atanır. Kurucuda yapılan iş budur: üye alanlara ilk değerlerin atanması. Birden fazla üye alan varsa, ilk değeri kritik olmayanları kurucuya parametre olarak vermek zorunlu değildir. Ama plaka gibi tekil tanımlayıcılar ya da nesnenin doğru çalışması için ilk değeri önemli olan alanlar kurucuya parametre olarak verilmelidir.

### 15.2 Getter

UML'de dönüş türü metodun sonunda, Java'da ise `public`'ten hemen sonra yazılır: `public String getPlate()`. Gövdede yalnız `return plate;` vardır. `return` yazılmadan önce Eclipse "String döndüreceğini söyledin ama döndürmedin" diye derleme hatası gösterir. Getter'ın kesinlikle parametre almasına gerek yoktur, çünkü metodu çağrılan nesne kendi plakasını zaten bilir.

### 15.3 Setter ve this

Setter parametre almak zorundadır, çünkü üye alana yeni bir değer atanacaktır. `public void setPlate( String plate )` yazıldı. UML'de parametre adı yazılmamıştı, ama kodda parametre adı vermek zorunludur. Hoca parametreye kasten üye alanla aynı adı, `plate`'i verdi ve gövdeye `plate = plate;` yazdı.

**Soru (hocanın sorusu):** Bu kod neden çalışmaz? **Cevap:** Bilgisayarlar aptal aletlerdir, zekâlarını programcılar verir. Üye alan da parametre de `plate` adını taşır. Derleyici en son, en içte tanımlanan adı hatırlar. Metodun içinde `plate` denince yalnız parametre anlaşılır; programcının eşitliğin solundaki `plate` ile üye alanı kastetmesini derleyici anlamaz. Sonuçta parametre kendine atanır ve setter hiçbir arabanın plakasını değiştiremez.

Eşitliğin solundaki `plate`'in üye alan olduğunu açıkça göstermek için **`this`** işaretçisi kullanılır: `this.plate = plate;`. `this`, metodu çağrılan nesne anlamına gelir; yönetimini JVM kendisi yapar. Parametre olarak gelen `plate` ile üye alan olan `plate` ancak bu şekilde ayırt edilir. `this` yazılmadan önce Eclipse bir uyarı (warning) gösteriyordu; `this` eklenince uyarı kalktı. Eclipse üye alanları mavi renklendirir: kurucu ve getter'daki `plate` maviydi, setter'daki değildi; `this.` yazılınca mavi oldu. Ayrıca Eclipse tıklanan adın geçtiği her yeri vurgular; bu özellik "Toggle Mark Occurrences" düğmesiyle açılıp kapatılır.

**Soru:** Kurucudaki ya da `getPlate`'teki `plate`'e de `this` yazsak sorun olur mu? **Cevap:** Hiçbir sorun olmaz, yalnız gerek yoktur. Hoca `this`'in özellikle gerektiği yeri göstermek için diğerlerini sildi.

Bu kodu ajan çalıştırıp denedi: setter'da `this` yazılmazsa ve `main`'de plaka değiştirilmeye çalışılırsa çıktı ilk plaka olarak kalır (aşağıdaki kodda `this` kaldırılıp yorum satırı açıldığında `My license plate is 34 RA 440`).

### 15.4 introduceSelf ve main

Son olarak, nesnenin komut satırına kendini tanıtan bir iki satır yazmasını sağlayan `introduceSelf` metodu eklendi. Parametre almaz, çünkü nesne kendi verisiyle çalışır. Eclipse'te `sysout` yazıp Ctrl+Space'e basınca `System.out.println` tamamlanır.

İki metni birleştirmek için `+` işleci kullanılır. `+` normalde sayısal bir işleçtir: iki yanında sayı varsa toplama yapar. İki yanından biri `String` ise öbür yan sayı bile olsa metin gibi ele alınır ve iki metin art arda eklenir.

Java'da dizi parametresindeki köşeli parantez dizi adının solunda ya da sağında yazılabilir (`String[] args` ya da `String args[]`); C'de yalnız sağ taraf geçerlidir.

`main` içinde önce `Car aCar;` ile nesne tanımlandı. Yalnız tanımlamak yetmez, kurucusu çağrılarak ilklendirilmelidir: `aCar = new Car("34 RA 440");`. Sonra `aCar.introduceSelf();` çağrıldı. Eclipse'in kod tamamlama özelliği, nesne adından sonra nokta yazılınca o nesnenin metotlarını listeler ve yazdıkça seçenekleri azaltır.

Kod (ekrandan, 02:40:00 ve 02:45:00):

```java
package hafta02;

public class Car {
    private String plate;

    public Car( String plateNr ) {
        plate = plateNr;
    }
    public String getPlate() {
        return plate;
    }
    public void setPlate( String plate ) {
        this.plate = plate;
    }
    public void introduceSelf( ) {
        System.out.println("My license plate is " + getPlate() );
    }
    public static void main( String[] args ) {
        Car aCar;
        aCar = new Car("34 RA 440");
        //aCar.setPlate("35 İZ 35");
        aCar.introduceSelf();
    }
}
```

Çıktı: `My license plate is 34 RA 440` (ekrandan, 02:40:00). Bu kod ajan tarafından Java 25'in tek dosyalı kaynak başlatıcısıyla (`java hafta02/Car.java`) çalıştırıldı ve aynı çıktıyı verdi; sistemde `javac` bulunmadığı için ayrı derleme yapılmadı.

`introduceSelf` içinde ilk önce `plate` yazılmıştı (ekrandan, 02:40:00), sonra `getPlate()` yapıldı. Hoca `getPlate()` dedi, çünkü sıralama şemasında bir nesnenin kendi metodunu çağırmasının nasıl gösterildiğini anlatmak istiyordu. `plate`, `this.plate` ya da `this.getPlate()` yazmak da sorunsuz çalışır ve aynı sonucu verir, çünkü nesne kendi üye alanına doğrudan erişebilir.

### 15.5 Plakayı değiştirmek

Kendini tanıtmadan önce `aCar.setPlate("35 İZ 35");` satırı eklendi. Program artık `My license plate is 35 İZ 35` yazdı (ajan tarafından da doğrulandı). Ekrandaki son kodda bu satır yorum satırı yapılmıştır.

### 15.6 Kurucunun adı değiştirilirse

**Soru:** `Car` kurucusunun adını değiştirsek sorun olur mu? **Cevap:** Olur; kurucunun kuralı sınıfla aynı adı taşımasıdır. Hoca adı `mar` yaptı. Bu durumda derleyici onu normal bir metot sayar ve normal metotlarda dönüş türü ya da `void` gerektiğini söyleyerek hata verir. `void` yazılınca `mar` artık normal bir metottur ve `new Car("34 RA 440")` kullanılamaz.

Sınıfta hiç kurucu kalmadığı için varsayılan kurucu devreye girer ve `new Car()` derlenir. `setPlate("35 İZ 35")` çağrısı açıkken araç yine kendini bu plakayla tanıtır: varsayılan kurucu yer ayırır, sonra plaka set edilir. Hoca `setPlate` satırını da yorum satırı yaptığında program `My license plate is null` yazdı: plakası olmayan bir araç ortaya çıktı (hocanın deyişiyle "öyle bir araç da olamaz, cezaya çekilir"). Değer atanmamış nesne türündeki alanların değeri null'dur. Ajan bu senaryoyu da çalıştırdı ve aynı çıktıyı aldı.

Doğrusu, plaka numarasını parametreli kurucuyla vermektir. Yoksa plakayı set etmeyi unutmak ya da kötü niyetle bilerek set etmemek mümkün olur; ikisi de yanlıştır.

## 16. Car Sınıfının Sıralama Şeması

Hoca `main` metodunun sıralama şemasını Violet UML Editor'de birlikte çizdi (ekrandan, 02:50:00).

### 16.1 Şemanın kurulması

Araç bir nesneye boşluktan ok çizmeye izin vermediği için önce `:JVM` adlı bir nesne konur. Hangi sınıfın `main` metodu çağrılıyor? `Car` sınıfının. `main` statik bir metot olduğu için ikinci kutuya yalnız `Car` yazılır. İkisine de activation bar konur ve `:JVM`'den `Car`'a `main( ... )` oku çizilir. Parametre listesine bir şey verilmediği için içine üç nokta yazılabilir ya da hiçbir şey yazılmayabilir; bu aşamada önemli değildir.

`main` içinde önce `aCar` adlı `Car` nesnesi tanımlanıp ilklendirilir. Bunun için `aCar : Car` adlı yeni bir nesne konur ve `Car`'dan ona `new("34 RA 440")` oku çizilir; parantezi kapatmayı unutmamak gerekir. Kurucunun içinde başka metot çağrısı olmadığı için kesikli dönüş oku hemen `main`'e çizilir.

Yorum satırındaki `setPlate` devrede değildir. Sonra `aCar`'a `introduceSelf( )` mesajı gönderilir. Ok, kurucunun dönüşünden sonra ama activation bar'ın içinde bir noktadan başlatılır.

### 16.2 Nesnenin kendi metodunu çağırması

`println` çağrıları gösterilmez. Ama `introduceSelf` içinde nesne kendi `getPlate` metodunu çağırır. Bu, nesnenin activation bar'ından kendisine bir mesaj oku çizilerek gösterilir: mevcut activation bar'ın üstüne ek bir dikdörtgen (yaşam çizgisi) eklenir ve ok kanca biçiminde çizilir. Okun üstüne `getPlate( )` yazılır. Kendi kendine çağrılan metodun bitişi için kesikli dönüş çizgisi gerekmez; ek dikdörtgenin alt kenarı metodun bitiş noktası sayılır.

`introduceSelf` içinde başka bir şey yapılmadığı için metot biter ve denetim akışı çağırana, `main`'e döner. `main`'de de başka çağrı olmadığı için `main` biter.

Şemanın son hali (ekrandan, 02:50:00 ve 02:55:00):

```text
:JVM              Car                   aCar : Car
 |                 |                        |
 |--- main(...) -->|                        |
 |                 |-- new("34 RA 440") --->|
 |                 |<- - - - - - - - - - - -|
 |                 |-- introduceSelf( ) --->|
 |                 |                        |--+ getPlate( )
 |                 |                        |<-+  (ek dikdörtgen)
 |                 |<- - - - - - - - - - - -|
 |<- - - - - - - - |                        |
```

### 16.3 İç içe çağrılar ve hizalama

Y ekseninde aşağı inildikçe zamanda ileri gidilir. Kurucu ve `introduceSelf` çağrıları `main` okunun başlangıcı ile dönüşü arasında yer alır, çünkü bu metotlar `main`'in içinde çağrılır; tıpkı koddaki `main` gövdesinin başlangıç ve bitiş parantezleri arasında yer almaları gibi. Yani iç içedir (nested). Kurucu çağrılıp biter, sonra `introduceSelf` çağrılıp biter, sonra `main` biter. Kurucu ile `introduceSelf` birbirine göre ardışıktır (sequential), ama ikisi de `main` içinde gömülüdür.

> **Hocanın vurgusu:** Özellikle elle çizerken `main` oku ile `new` oku aynı hizadan başlatılmamalı, aralarında görünür bir boşluk bırakılmalıdır. `main`'e girer girmez hiçbir gecikme olmadan kurucu çağrılmaz; arada başka işler yapılır. Daha büyük bir hata, `new` okunu `main` okundan daha yukarıdan başlatmaktır; bu zamanda geri gitmek gibidir ve kesinlikle yapılmamalıdır.

### 16.4 Ders sonu soruları

**Soru:** `aCar` nesnesi sonra siliniyor mu? **Cevap:** `main` bitince `aCar` silinecektir. Zaten JVM de sonlandığı için ona ayrılan kaynakları işletim sistemi geri alır; bu anlamda evet, silinir.

**Soru:** JVM'yi şemaya yazmak zorunda mıyız? **Cevap:** Hayır. Hoca, okun ucunu boşta bırakamadığı için JVM'yi yazdı; kâğıtta çizerken baştaki bu kutuyu yazmaya gerek yoktur.

**Soru:** İlkel türler şemada nasıl gösterilir? <!-- BELİRSİZ: Sorunun metni altyazıda net değil; cevaptan ilkel türlerle ilgili bir soru sorulduğu anlaşılıyor. --> **Cevap:** İlkellerin metotları yoktur, çağrılmazlar. Örneğin `Car`'ın bir model numarası alanı olsaydı ve `println` içinde getter kullanılmadan doğrudan yazdırılsaydı, şemada gösterilmezdi. Bir metot içinde yapılan toplama, çıkarma gibi işlemler de gösterilmez; yalnız metot çağrıları gösterilir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:26:15): Sıralama şemasında bir nesne yalnız `myCar` biçiminde (iki nokta üst üste ve sınıf adı olmadan) gösterildiğinde, bu kutuyu sınıf şemasındaki bir sınıf kutusundan ayıran nedir?

> **Çözüm:** Alt çizgi. Nesne adları her üç gösterimde de (`kitt : Car`, `: Car`, `myCar`) altı çizili yazılır; sınıf kutusundaki ad altı çizili değildir.

**Soru 2** (derste sözlü, 00:50:07): Sıralama şemasında `client`'tan çıkan çağrı okları neden activation bar'ın üst kenarından değil de ortasından başlıyor?

> **Çözüm:** Okun dikdörtgenin üst köşesine denk getirilmesi gerekmez. Hocanın açıklamasına göre çağrıdan önce `client`'ta başka komutlar (en azından çağrıyı hazırlayan bytecode) yürütülmüştür. Ok, dikdörtgenin üst çizgisiyle aynı hizada başlatılmamalıdır.

**Soru 3** (derste sözlü, 01:12:21): `java.io.File` ve `com.fileWizard.File` aynı dosyada kullanılıyorsa, uzun adı tek bir sözcüğe bağlayan makro benzeri bir tanım yapılabilir mi?

> **Çözüm:** Hayır. İki sınıf birden kullanılıyorsa tam ad (fully qualified name) yazılmak zorundadır.

**Soru 4** (derste sözlü, 02:21:17): Bir paketteki birden çok sınıfın her birinde `main` metodu olursa hata alınır mı?

> **Çözüm:** Hayır. Her `main` kendi sınıfına aittir. Yalnız aynı sınıfta aynı imzalı ikinci bir `main` yazılırsa derleme hatası alınır.

**Soru 5** (derste sözlü, 02:30:30): `setPlate( String plate )` metodunun gövdesi `plate = plate;` olarak yazılırsa setter neden plakayı değiştiremez? Nasıl düzeltilir?

> **Çözüm:** Metodun içinde `plate` adı parametreyi gösterir (parametre üye alanı gölgeler), bu yüzden parametre kendine atanır ve üye alan değişmez. Düzeltme: `this.plate = plate;`. Ajanın denemesi: `this` olmadan `aCar.setPlate("35 İZ 35")` çağrısından sonra çıktı `My license plate is 34 RA 440` kalır; `this` ile `My license plate is 35 İZ 35` olur.

**Soru 6** (derste sözlü, 02:34:27): Kurucudaki ya da `getPlate`'teki `plate`'in başına da `this.` yazılırsa sorun olur mu?

> **Çözüm:** Olmaz; bu yerlerde gölgeleyen bir parametre olmadığı için `this` gereksizdir ama zararsızdır.

**Soru 7** (derste sözlü, 02:40:33): `Car` kurucusunun adı değiştirilirse ne olur?

> **Çözüm:** Metot artık kurucu sayılmaz; dönüş türü ya da `void` yazılmadıkça derleme hatası verir. `void` yazılırsa sıradan bir metot olur, sınıfta hiç kurucu kalmadığı için varsayılan kurucu eklenir, `new Car()` çalışır ama plaka atanmaz. `setPlate` de çağrılmazsa çıktı `My license plate is null` olur (derste gösterildi, ajan tarafından da çalıştırıldı).

**Soru 8** (derste sözlü, 02:54:22): `main` bittikten sonra `aCar` nesnesi siliniyor mu?

> **Çözüm:** Evet. `main` bitince nesne silinebilir hale gelir; JVM de sonlandığı için ayrılan kaynakları işletim sistemi geri alır.

**Soru 9** (derste sözlü, 02:54:42): Sıralama şemasında ilk çağrıyı yapan JVM kutusunu çizmek zorunlu mu?

> **Çözüm:** Hayır. Hoca, Violet UML Editor ok ucunun boşta kalmasına izin vermediği için JVM kutusunu ekledi; elle çizerken gerekmez.

## Dersin Toparlaması

Bu derste nesne yönelimin temel yapı taşları kuruldu. Nesne, verisi ve metotlarıyla ayrılmaz bir bütündür (kapsülleme). Sınıf bu nesneleri üreten şablondur. Her nesne farklı bir bireydir: durumu kendine özgüdür, JVM ona müdahale edilemeyen bir kimlik verir, ama problem alanındaki tekil tanımlayıcının (plaka gibi) tekilliğini programcı sağlamalıdır. Nesneler birbirine mesaj göndererek, yani metot çağırarak çalışır. Üye alanlar bilgi gizleme ilkesi gereği her zaman private tutulur ve getter/setter erişim metotlarıyla kullanılır. `static` ortak kullanımı, `final` tek seferlik atamayı ifade eder; ikisi birlikte public sabitler için kullanılır. Kurucular nesneyi örneklendirir ve özellikle tekil tanımlayıcıya ilk değer vermek için parametreli olarak yazılır. Paketler sınıfları gruplar ve ad çakışmalarını önler.

Aynı kavramlar UML'de de çizildi: üç bölmeli sınıf şeması (`+`/`-` görünürlük, `ad : Tür`, `{final,static}`) ve altı çizili nesnelerle, çağrı/dönüş oklarıyla, activation bar'larla, kendi kendine çağrı kancasıyla ve iç içe zaman sırasıyla sıralama şeması. Ders `Car` sınıfının Eclipse'te yazılıp çalıştırılması ve `main` metodunun sıralama şemasının çizilmesiyle bitti. Hoca nesneler arasındaki farklı ilişki türlerinin, kalıtımın (protected ve final metotlar) ve kurucuların daha ayrıntılı kullanımının sonraki haftalarda işleneceğini belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
