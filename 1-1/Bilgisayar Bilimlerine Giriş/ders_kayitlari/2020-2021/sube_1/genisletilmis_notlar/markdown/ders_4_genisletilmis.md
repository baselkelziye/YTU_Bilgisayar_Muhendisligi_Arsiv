# Ders 4 Genişletilmiş Notu: CPU, Bellek Hiyerarşisi, Veri Boyutları ve Bilgisayar Organizasyonu

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Merkezi İşlem Birimi ve GPU
- 2. Bellek Piramidi
- 3. Register, Cache ve Ana Bellek
- 4. Manyetik Disk
- 5. SSD ve Okuma-Yazma Ömrü
- 6. Optik Sürücüler
- 7. Disketler, Flash Bellekler ve Harici Diskler
- 8. Seri ve Paralel Veri Aktarımı
- 9. Manyetik Teypler ve Hiyerarşinin Değerlendirmesi
- 10. Ana Belleğin Yapısı, Bit ve Byte
- 11. Analog Veriden Dijital Veriye: ADC
- 12. İkili Sistemde Bilgi Boyutları
- 13. Volatile ve Non-Volatile Bellek
- 14. Sanal Bellek
- 15. Rastgele ve Sıralı Erişim
- 16. ROM, BIOS ve Firmware
- 17. Bilgisayar Organizasyonu
- 18. İşlemci Mimarileri ve Komut Setleri
- 19. İşletim Sistemi ve Yazılım Türleri
- 20. Programlama Dillerinin Nesilleri

## 1. Merkezi İşlem Birimi ve GPU

Ders, bir önceki hafta başlanan bilgisayar birimleri konusunun devamıdır. Son olarak merkezi işlem birimine (CPU) gelinmişti. Von Neumann mimarisinde de görüldüğü gibi CPU iki birimden oluşur: kontrol birimi ve aritmetik-mantık birimi.

Kontrol birimi, komutların işlem sırasını ve CPU tarafından işlenmesini denetler. Yani iş akışını yönetir: O anda gelen komut nedir, ne yapılacak, ondan sonra nereye gidilecek, bunlara bakar. Aritmetik-mantık birimi (ALU) ise hem aritmetik hem de mantık işlemlerinden sorumludur. Kısacası birimlerden biri işlerin neler olduğunu ve hangi sırayla yapılacağını kontrol eder, diğeri işlerin bizzat kendisini yapar. Dersin başında sayılan dört işlem, `if` ile karar verme ve döngü gibi işler bu birimin sorumluluğundadır.

Bütün işler genelde CPU'da gerçekleşir, ama son dönemde bir birim daha kullanılmaktadır: GPU. GPU, ekran kartı görevini yürüten ve görüntü, video işleme gibi işleri gerçekleştiren birimdir. Son yıllarda, özellikle derin öğrenme kavramının yaygınlaşmasıyla birlikte, GPU'ya iş devretmek önem kazandı. Çekirdek (core) sayısı çok fazla olduğundan işleri paralelleştirme potansiyeli CPU'ya göre daha yüksektir, gerçi paralelleştirme CPU'da da mümkündür. Bu sayede, özellikle resim ya da video işlenirken yoğun hesaplamalar GPU üzerinden yönetilebilir.

Yine de merkezde CPU vardır. İşleri GPU'ya delege eden ve GPU'daki işler bittikten sonra sonucu tekrar işleyen CPU'dur. Bununla birlikte GPU'nun da önemli bir işlem gücü potansiyeli olduğu unutulmamalıdır. Her ikisi de işleri gerçekleştirebilir.

> **Ders sonrası not:** Hoca GPU'nun açılımını "Graphical Processing Unit" olarak söyledi; yaygın kullanılan açılım büyük olasılıkla "Graphics Processing Unit"tir.

## 2. Bellek Piramidi

İşleri yapmak kadar, dışarıdan alınan ya da içeride işlenen bilgileri saklamak da kritiktir. Bellekler bu noktada bir piramit olarak düşünülür. Piramidin üstüne çıktıkça parçaların maliyeti ve hızı yükselir, kapasitesi ise azalır.

Slaytta piramit üç katmana ayrılmıştır:

- **Kart üzerindeki bellek (inboard memory):** register, cache, ana bellek (main memory).
- **Harici depolama (outboard storage):** manyetik disk, CD-ROM, CD-RW, DVD+RW, DVD-RAM.
- **Çevrim dışı depolama (off-line storage):** manyetik teyp, MO, WORM.

<!-- BELİRSİZ: Piramit slaydı altyazıda okunmuyor; katman adları ve MO, WORM, DVD-RAM gibi öğeler kısa nottaki ekran bilgisinden (00:08:30) alındı. -->

Hoca konuya girerken öğrencilere bildikleri bellek birimlerini sordu. Bir öğrenci micro SD kartları, normal SD kartları, SSD'leri, sabit diskleri ve SSD ile benzer mantıkla çalışan flash bellekleri saydı; SSD'lerin de normal SSD ve NVMe gibi tipleri olduğunu ekledi. Başka bir öğrenci RAM'leri, register ve cache'i, ayrıca ROM'u ekledi. Hoca bunları ayrıntılandırmak gerektiğini söyleyip register'la başladı.

<!-- BELİRSİZ: 00:09:16'da öğrencinin saydıkları arasında "NME" ve "SSD DVD" geçiyor. "NME" NVMe olarak yazıldı; "SSD DVD" anlaşılamadığı için alınmadı. -->

## 3. Register, Cache ve Ana Bellek

### 3.1 Register

CPU'da işlem yapılmadan önce verinin bellekten ya da cache bölgesinden register'lara alınması gerekir. Register, CPU'nun içinde yer alan bellek birimidir. Bilinen en hızlı ve en pahalı, ama aynı zamanda kapasitesi en düşük bellek birimidir. CPU'ya gelen, yapılacak işler için kullanılacak bilgiler burada saklanır. Türkçe karşılığı **yazmaç**tır.

### 3.2 Cache (Ön Bellek)

Cache, CPU'nun ön belleği olarak geçer. Ön bellekte, çok sık erişme ihtimaliniz olan bilgileri, yani o anda çalıştırdığınız programa ait bilgileri tutarsınız. Böylece her seferinde ana belleğe gitmek gerekmez. Cache'in belli bir kapasitesi vardır. Çok sık erişilen bilgiler CPU'nun içinde ya da hemen yakınındaki bu belleğe çekildiğinde işler çok daha hızlı yürür.

Cache, zaman içinde getirilmiş bir ara çözümdür. Eskiden register'lar vardı, ama ön bellekler bu kadar yaygın değildi. Bugün ön belleklerin L1, L2 ve L3 olmak üzere seviyeleri vardır. Bu seviyeler kademelidir, erişim hızları da aynı şekilde kademeli olarak değişir.

### 3.3 Ana Bellek (RAM)

Cache'ten sonra bildiğimiz RAM bölgesi, yani Random Access Memory gelir. RAM'in zaman içinde geliştirilmiş çeşitli sürümleri vardır.

Buraya kadar anlatılan üç bellek de elektrik olduğu sürece aktiftir. Elektrik olmadığında üzerlerindeki bilgiler kaybolur. Kapasiteleri, ikinci bellek denilen manyetik disk ve SSD gibi disklere göre görece düşüktür; buna karşılık hem maliyetleri hem de bilgiye erişim hızları daha yüksektir.

Hız sırası şöyledir: En hızlısı register, sonra cache, sonra ana bellek. Bunlar genelde birinci bellek olarak adlandırılır. Daha doğrusu birinci bellek denince ağırlıklı olarak ana bellek kastedilir, register ve cache ise CPU bölgesindeki bellek birimleri olarak anılır.

## 4. Manyetik Disk

Bilgisayarı sürekli açık tutmak sunucular için geçerlidir, ama her bilgisayar sürekli açık tutulmaz. Elektrik istenmeyen bir sebeple de kesilebilir. Bilgilerin elektrik kesildiğinde de saklanması gerekir. Bunun için en sık karşılaşılan birim manyetik disktir.

Manyetik diskte bilgi manyetik plakalar üzerinde saklanır ve mekanik bir sistem üzerinden erişilir. Plakaların dönmesi gerekir. Küçük bir kol da bu plakalar üzerinde hareket ederek veriye ulaşır.

Disklerin dönüş hızı RPM ile ifade edilir. Hocanın saydığı düzeyler 5400 RPM, 7200 RPM ve biraz daha yukarıda 10.000 RPM'dir. Bundan sonrası kişisel bilgisayarların dışına çıkar: Dönüş hızı daha yüksek olan SCSI diskler daha çok sunucularda tercih edilir.

> **Ders sonrası not:** Altyazıda sunucu diskleri için "15400" geçiyor; büyük olasılıkla doğru değer 15.000 RPM'dir.

**Soru:** RPM'in açılımı nedir? **Cevap:** Bir öğrenci dakikadaki dönüş sayısı olması gerektiğini söyledi, hoca bunu doğruladı ve "rotation per minute" olarak adlandırılabileceğini söyledi. Bir dakikada kaç dönüş yapıldığını gösterir. Bu sayı arttıkça bilgiye erişim hızı da artar.

> **Ders sonrası not:** Hoca açılımı "rotation per minute" olarak verdi; yaygın kullanılan açılım büyük olasılıkla "revolutions per minute"tır. Anlam aynıdır.

Disk üzerinde sektörler vardır ve bilgiler bu sektörlerde saklanır. Birbiriyle ilişkili veriler genelde aynı sektörde saklanmalıdır, çünkü farklı sektörlere her gidişte kolun mekanik hareketi belirli bir zaman alır.

Mekanik bir cihaz olduğu için disk ses de çıkarır. Bazen tıkır tıkır bir ses, bazen daha yüksek bir ses duyulur, bu ses zaman içinde artabilir. Hepsi kol hareketinden kaynaklanır. Bu mekanik yapı, veriye erişim hızını bir yere kadar taşıyabilir. Eski tip bilgisayarlarda maliyeti de düşük olduğu için ağırlıklı olarak manyetik diskler tercih edilmiştir.

## 5. SSD ve Okuma-Yazma Ömrü

Yeni tip bilgisayarlarda, maliyet biraz yükselse de manyetik diskin yerini SSD (Solid State Disk) alır. SSD tamamen elektronik devrelerden oluşur. Kol hareketi ya da herhangi bir mekanik hareket yoktur. Bu da çok büyük bir hız kazancı sağlar.

> **Ders sonrası not:** Hoca açılımı "Solid State Disk" olarak söyledi; yaygın kullanılan açılım büyük olasılıkla "Solid State Drive"dır.

SSD'nin boyutu genelde birçok manyetik diske göre çok daha küçüktür, ama zaman içinde büyümüştür. En önemli etken maliyettir. Maliyet yüksek olduğu için bilgisayarlarda hibrit bir yapı da tercih edilebilir ve ikisi birlikte bulunabilir: Daha sık erişilen bilgiler ve işletim sistemi SSD'de tutulur, yedek (backup) niteliğindeki büyük veriler ise arka planda manyetik diskte saklanır.

**Soru:** SSD'nin manyetik diske göre dezavantajı nedir? **Cevap:** Öğrencilerden iki cevap geldi: Daha hızlı eskidiği, birkaç yıl içinde eskisi kadar hızlı çalışmadığı ve daha pahalı olduğu için depolama alanının daha düşük olduğu. Hoca eskimenin nereden kaynaklandığını sordu ve konuyu okuma-yazma ömrü üzerinden açıkladı.

SSD gibi yapılar ve USB flash bellekler için belirli bir okuma-yazma ömrü vardır. Bu ömür yüz binler mertebesindedir. Bu kadar sayıda okuma-yazmanın sonunda, SSD'de yazılmaya çalışılan ilgili blok işlevini yitirir. Demek ki SSD'lerin belli bir ömrü vardır.

Ama bu, diskin kısa sürede bozulacağı anlamına gelmez. 100 bin defa okuyup yazmak çok yüksek bir rakamdır, 3-5 senede tükenecek bir sayı değildir. Çünkü burada söz edilen okuma-yazma, SSD'nin bütününe yapılan bir işlem değil, içindeki ilgili her bir byte'ın ya da bitin saklandığı bölgeye yapılan işlemdir. Hocanın örneğinde 256 GB'lık bir SSD kullanılıyor, belli bir alanı boş, belli bir alanına okuma-yazma yapılıyor. Teorik olarak o alanlarda belli bir süre sonra yüz binler mertebesinde bir bozulma sınırı vardır. Pratikte ise hocaya göre insan muhtemelen ömrü boyunca bir SSD'de bu sayıya ulaşamaz. Yani yakın bir tarihte bu yüzden eskime ihtimali yoktur.

> **Ders sonrası not:** Hoca sınırı okuma-yazma için yüz binler mertebesinde verdi; büyük olasılıkla aşınmayı asıl yazma ve silme işlemleri yaratır, tüketici SSD'lerinde bu sınır da hücre türüne göre çoğunlukla binler mertebesindedir. Bu yüzden büyük olasılıkla "ömür boyu ulaşılamaz" ifadesi her kullanım için geçerli değildir, yine de normal kullanımda sınır uzaktır.

## 6. Optik Sürücüler

Hala kullanılan eski tip bellek birimleri arasında CD-ROM, CD-Writer ve DVD-Writer vardır. Bunlar farklı bir teknoloji kullanır. Hocanın sorusuna bir öğrenci lazer teknolojisi cevabını verdi. Bu nedenle bunlara optik okuyucu da denir.

Çalışma mantığı, bilgisayarların ilk yıllarında kullanılan delikli kartlara (punch card) benzer. Disk yüzeyinde, gözle fark edilemeyecek tümsekler ve boşluklar vardır. CD-ROM diski döndürürken lazer ışığı bu çöküntülere ve normal yüzeye denk gelir, bunları 1 ve 0 olarak okur.

Kapasiteler şöyledir:

| Ortam | Kapasite |
|---|---|
| CD | yaklaşık 700 MB |
| DVD | 4,7 GB |
| Blu-ray | yaklaşık 25 GB (birden fazla formatı vardır) |

<!-- BELİRSİZ: 00:23:32'de "700 megabit" ve anlaşılmayan "RTX'in 100 megabit diyelim" geçiyor. Birim, kısa nota ve bağlama göre MB yazıldı; ikinci ifade alınmadı. -->

> **Ders sonrası not:** Altyazıda CD kapasitesi "700 megabit" diye geçiyor; doğrusu büyük olasılıkla 700 megabyte'tır.

Hoca, CD ile DVD arasındaki kapasite farkının nereden geldiğini sordu. Cevaba göre fark katmanlardan kaynaklanır: DVD ve Blu-ray tarafında daha fazla katman kullanılabilir. Buna ek olarak kullanılan lazerin dalga boyu da CD-ROM ile DVD arasındaki kapasite farkını yaratır.

> **Ders sonrası not:** Hoca farkı önce katman sayısına bağladı; 4,7 GB ve yaklaşık 25 GB büyük olasılıkla tek katmanlı disklerin değeridir, yani temel fark büyük olasılıkla daha kısa dalga boyunun izin verdiği daha sık yerleşimden gelir. Ayrıca büyük olasılıkla 1 ve 0, çukur ve düz alanın kendisinden değil, aralarındaki geçişlerden okunur.

**Soru:** Yeniden yazılabilir (rewritable) disklerde yazılan bölge yakılınca eski haline mi getiriliyor, bu nasıl çalışıyor? **Cevap:** Rewritable disklerin de belli bir ömrü vardır, çünkü ilgili bölgenin belirli bir kapasitesi vardır. Hoca bunu parke üzerinde yapılan bir işleme benzetti: O bölgeye her yazıldığında üzerine ince bir katman işlenmiş olur. Bu yüzden rewritable disklerin belirli bir yazma miktarı vardır, onun üzerinde tekrar yazılamaz.

<!-- BELİRSİZ: 00:24:57'deki parke benzetmesinin tamamı altyazıda bozuk; "belli bir süreç yapabildiğinizde" ifadesi net değil. -->

> **Ders sonrası not:** Hoca yeniden yazmayı üst üste işlenen ince katmana benzetti; büyük olasılıkla rewritable disklerde katman eklenmez, kayıt tabakası lazerle ısıtılarak iki farklı fiziksel durum arasında değiştirilir (faz değişimi) ve ömrü bu tabakanın yıpranması sınırlar.

## 7. Disketler, Flash Bellekler ve Harici Diskler

Eskiden disketler (floppy disk) vardı. Hoca "1.44, 3.5'luk, 5 küsurluk" diye saydı. Disketler de manyetik yapı kullanır. Onları okuyan disk sürücüleri çok eski bilgisayarların bulunduğu bazı yerlerde hala görülebilir. Çok kısıtlı miktarda veri saklayabildikleri için kullanımdan düşmüşlerdir.

Yeni nesil ikinci bellekler öğrenciler için çok da yeni değildir, belki onlarla büyümüşlerdir. Bunların başında USB portunu kullanan USB flash bellekler gelir. SD kartlar da bu gruptadır. Yalnız bilgisayarlarda ilgili aparatla okunmakla kalmaz, fotoğraf makinelerinde ve telefonlarda da kullanılırlar. Çok küçük bir boyuta çok büyük miktarda veri sığdırma şansı verirler. Telefonlarda gigabyte'lar mertebesinde kullanılırlar; bu daha çok Android işletim sistemi yüklü telefonlarda karşımıza çıkar, buralara ek bellek takılabilir.

<!-- BELİRSİZ: 00:26:33'te "USB bellek ayrı, flash disk ayrı biliyorsunuz" geçiyor; ayrımın ne olduğu altyazıda açıklanmıyor. -->

Bir de harici sabit diskler vardır. Bunlar genelde USB portu üzerinden, bir USB flash bellek gibi çalışır, ama içerideki temel yapı manyetik sabit diskin yapısıdır. Dahili (internal) değil harici (external) bir sabit disktir ve bilgiyi USB portu üzerinden aktarır.

## 8. Seri ve Paralel Veri Aktarımı

Hoca buradan bir soruya geçti: Dahili disklerde bilgi diskten alınıp belleğe ve CPU'ya aktarılırken nasıl taşınır? Bir öğrencinin SATA portu cevabı üzerine SATA'nın seri aktarımla ilişkisini ve seri ile paralel aktarım arasındaki farkı konuştular.

SATA ve PATA arayüzlerinden biri seri, diğeri paralel aktarımı destekler. Bazı yazıcılarda da paralel aktarım vardır. Paralel aktarımda veri aynı anda birden fazla yol üzerinden gider; örneğin 8 hat olsun, data hattı üzerinde 8 aktarım noktası vardır ve veri bu hatlardan birlikte aktarılır. Seri aktarımda ise veri tek bir hat üzerinden gider.

Ancak bu, paralelin daha hızlı olduğu anlamına gelmez, çünkü ikisinin aktarım protokolleri farklıdır. Birçok giriş ve çıkış cihazı verilerini seri haberleşme üzerinden aktarır. Bilgisayarın içine takılmış dahili manyetik disklerde de seri haberleşme son dönemde yaygındır. Daha farklı portlar da vardır, ama bunlar ilerideki derslerde görülecektir.

> **Ek bilgi (derste anlatılmadı):** Derste SATA'nın açılımı sorulmuş, kesin bir cevap söylenmemişti. Büyük olasılıkla SATA "Serial ATA", PATA ise "Parallel ATA" demektir. Buradaki ATA da büyük olasılıkla "AT Attachment" kısaltmasıdır.

## 9. Manyetik Teypler ve Hiyerarşinin Değerlendirmesi

Piramidin bir sonraki katmanında manyetik teypler vardır. Hocanın dersin başında gösterdiği, eski filmlerin sarılı olduğu şeritlere benzer şekilde tekerlek gibi sarılı şeritlerdir. Veriler bu şerit üzerinde saklanır. Uzun yedekler (backup) almak, büyük verileri saklamak için eskiden çok sık kullanılan bir yapıydı.

Bugün bu yapılar eskisi kadar tercih edilmez, çünkü yer anlamında belirli bir saklama maliyetleri vardır. Artık daha çok ikinci bellekler üzerinde saklama tercih edilmektedir. Terabyte boyutunda veriler ev ortamında saklanabilir, petabyte'lar da normalleşmeye başlamıştır. Gigabyte'lar bir zamanlar ulaşılamaz noktadayken bugün normal kabul edilmektedir. RAM için de gigabyte normal bir boyuttur. Hocanın karşılaştırmasıyla, bundan yaklaşık 20 yıl önce 10 GB'lık bir sabit disk, bugünkü 1 TB'lık bir sabit disk kadar değerliydi. Bugün benzer boyutlara terabyte'larca bilgi sığdırılabilmektedir.

<!-- BELİRSİZ: 00:31:27'de "çok tercih edilebiliyoruz" geçiyor; bağlam gereği "tercih edilmiyor" olarak yorumlandı. Hoca 01:06:09'da teyplerin hala kullanıldığını da söylüyor. -->

> **Hocanın vurgusu:** Bellek hiyerarşisi önemlidir ve bilinmesi gerekir. En hızlı bellek hangisi, maliyeti en yüksek bellek hangisi, kapasitesi en düşük bellek hangisi, bunlar bilinmelidir.

Hoca bu sıralamanın göreceli olduğunu da ekledi. Yani kapasite karşılaştırmasında istisnalar görülebilir, ama hiyerarşi ağırlıklı olarak bu şekilde kabul görmektedir.

## 10. Ana Belleğin Yapısı, Bit ve Byte

### 10.1 Hücreler

RAM, Random Access Memory'nin kısaltmasıdır ve rastgele erişimli bellek demektir. Ana bellekte her bir hücre bir byte'lık veri saklar. Hücrelere byte bazında erişilir. Hücreye eriştikten sonra üzerinde bit bazında işlem yapılabilir.

### 10.2 Bit ve Byte

Bilgisayar dünyasındaki en küçük birim bittir. Hoca bitin açılımını sordu. "0 ve 1'lerden oluşan ikililer" cevabı yanlış değildi, ama istenen açılım **binary digit**'ti. Bit bu ifadenin kısaltmasıdır. Bir binary digit'te iki değer saklanabilir: ya 0 ya da 1.

Bit ile byte üniversitenin başında bazen karıştırılır. Hoca bunun için bir hatırlatma önerdi: "Bit" kelimesinin Türkçedeki diğer anlamı düşünülürse bitin en küçük birim olduğu kolayca akılda kalır.

Bir byte'ta 8 bit vardır. Ancak bellekte hücrelere byte byte erişilir.

$$1 \text{ byte} = 8 \text{ bit}$$

Bazı değişkenler 1 byte, bazıları 2 byte, bazıları 4 byte yer kaplar. İşlemci veriyi buna göre bellekten çeker. Örneğin tam sayı tipinde (integer), o mimaride 4 byte yer kaplayan bir değer saklanıyorsa, onunla işlem yapılırken işlemci otomatik olarak bellekten 4 byte'ı birden okur ve register'a alıp işlemi yapar. Saklama sırasında ise bu 4 byte, birer byte'lık hücrelere arka arkaya yerleşir.

### 10.3 Adresler ve Sayı Sistemleri

Her bellek hücresinin bir adresi vardır. Bellekteki verilere bu adresler üzerinden ulaşılır. Adresler onaltılık (hexadecimal) sayılarla ifade edilir. Bellek hücrelerini ikili sayı sistemiyle ifade etmek gerekseydi çok uzun sayılar yazmak gerekirdi. Bu yüzden daha makul olan onaltılık sistem kullanılır. Ders boyunca ikili ve onaltılık sistem çok sık kullanılacak, bazen sekizlik sayı sistemine de ihtiyaç olacaktır.

### 10.4 Hücrelerde Ne Saklanır?

Bellek hücrelerinde veri de komut da saklanabilir, fark etmez. Çalıştırılan program ikinci bellekten ana belleğe gelir ve ana bellekte çalışan bir kopyası oluşturulur. Her adımda hangi komutun çalışacağı bellekte yer alır, programın kullanacağı veriler de yine belleğe yerleşir. Bellek yerleşimi ilerleyen derslerde daha ayrıntılı görülecektir.

Sonuçta saklanan resim, video, ses, metin ve sayıların hepsi bellekte 0 ve 1'ler olarak tutulur. A harfi de 0 ve 1'ler olarak saklanır, bir resme ait renk bilgileri de. Bunların çeşitli kurallara göre dönüşümleri vardır. Bir bilgi verildiğinde arka planda bu kurallara göre 0 ve 1'lere dönüştürülür.

## 11. Analog Veriden Dijital Veriye: ADC

**Soru:** Dışarıdaki analog bir resmi ya da ses bilgisini dijitale çeviren, fotoğraf makinesinde veya telefonda bulunan birim hangisidir? **Cevap:** Öğrencilerden önce RGB ve kodek cevapları geldi. Hoca RGB'nin bir renk uzayı olduğunu, kodeklerin ise bir bilgiyi kodlamak için kullanıldığını söyledi. Doğru cevap **ADC (Analog to Digital Converter)** oldu.

ADC, dış ortamdan toplanan veriyi, özellikle kameradan gelen veriyi, ses verisini ya da başka bir girişten gelen analog veriyi dijital veriye çevirir. Ayrıntıları zamanı geldiğinde görülecektir. Hoca, vakit olursa ADC'nin ne olduğuna bakılmasını önerdi; böylece analog ve dijital kavramlarının da üzerinden bir kez daha geçilmiş olur.

## 12. İkili Sistemde Bilgi Boyutları

Bilgisayar ikili sistemle çalıştığı için bilgi boyutlarında ikinin kuvvetleri kullanılır. Slaytta verilen birimler şunlardır:

| Birim | İkinin kuvveti | Byte karşılığı |
|---|---|---|
| 1 kilobyte | $2^{10}$ | 1.024 |
| 1 megabyte | $2^{20}$ | 1.048.576 |
| 1 gigabyte | $2^{30}$ | 1.073.741.824 |
| 1 terabyte | $2^{40}$ | 1.099.511.627.776 |

<!-- BELİRSİZ: Altyazıda yalnız KB ve MB değerleri söyleniyor; GB ve TB satırları kısa nottaki ekran bilgisinden (00:52:30) alındı ve python ile doğrulandı. -->

> **Hocanın vurgusu:** 1 kilobyte 1000 byte değil, gerçekte 1024 byte'tır. Hesaplar hep ikinin kuvvetleri üzerinden yapılmalıdır. 1 megabyte ifade edilirken buna dikkat edilmelidir.

Hoca derste "1 megabyte kaç kilobyte'tır?" diye sordu. Gelen cevaplar arasında "bin" de vardı, ama doğrusu 1024'tür. Adım adım:

$$1 \text{ MB} = 2^{20} \text{ byte}, \qquad 1 \text{ KB} = 2^{10} \text{ byte}$$

$$\frac{1 \text{ MB}}{1 \text{ KB}} = \frac{2^{20}}{2^{10}} = 2^{10} = 1024 \quad \text{(ara adım eklendi)}$$

Yani $1 \text{ MB} = 1024 \text{ KB}$ ve bu da $1024 \times 1024 = 1.048.576$ byte eder.

> **Ders sonrası not:** Hoca kilobyte'tan megabyte'a geçişi "bir 10 katı kadar yukarı" ve "onar onar büyüyor" diye anlattı; büyüyen üstür. Üs 10 artar, değer ise 1024 katına çıkar. Altyazıda dizinin başında "iki üzeri bir" de geçiyor; hocanın devamında saydığı $2^{10}, 2^{20}$ dizisine bakılırsa büyük olasılıkla bu bir söyleyiş ya da altyazı hatasıdır.

### 12.1 Depolama Üreticileri Neden 1000 Alıyor?

**Soru:** Depolama üreticileri bu birimleri neden $10^3$ üzerinden alıyor, bunun teknik bir sebebi var mı? Örneğin 16 GB'lık bir flash bellek alındığında, işletim sistemi 1024 kullandığı için daha düşük görünüyor. **Cevap:** Hoca bu konuda kesin bir bilgisi olmadığını, yanlış bir şey söylemek istemediğini belirtti ve bunun sektörle ilgili olabileceğini söyledi. Bir öğrenci yuvarlamadan kaynaklanabileceğini, kapasitenin zaten yazıldığından biraz düşük çıktığını ekledi, hoca bunu "olabilir" diye karşıladı. Hocanın yorumu algıyla ilgiliydi: Birine 1 kilobyte'ın kaç byte olduğu sorulsa genelde "bin" cevabı alınır, 1024 cevabını almak pek mümkün değildir. 1.048.576 yerine "1 megabyte kabaca 1 milyon byte" demek daha anlaşılırdır. Sektör bu yüzden böyle kullanıyor olabilir, ama sebebin bu olduğundan emin değildir. Ucuza kaçma yorumu için de bir şey söyleyemeyeceğini, sonuçta arada çok büyük bir fark oluşmadığını ve bunu çok dert etmeye değmeyeceğini söyledi.

<!-- BELİRSİZ: 00:53:13'te öğrencinin sayıları "16.000 GB" ve "10.000 GB" olarak geçiyor; 16 GB olarak yorumlandı. -->

> **Ek bilgi (derste anlatılmadı):** Üreticilerin kullandığı $10^3$ tabanlı önek büyük olasılıkla SI standardına uygundur; 1024 tabanlı birimler için de büyük olasılıkla KiB, MiB, GiB gibi ayrı adlar tanımlanmıştır. Öğrencinin örneğinde 16 GB, $16 \times 10^9$ byte demektir. İşletim sistemi $2^{30}$'a bölerse $16 \times 10^9 / 2^{30} \approx 14{,}9$ görünür.

### 12.2 Terabyte'tan Sonrası

Bitten byte'a, oradan kilobyte, megabyte, gigabyte ve terabyte'a gelindi. Terabyte'tan sonra petabyte gelir. Hoca sonrasında zettabyte, yottabyte ve exabyte'ı saydı. Muhtemelen önümüzdeki yıllarda petabyte daha çok kullanılacak, sonraki 10 yılda zettabyte kullanılacak, belki ondan sonra da exabyte ve yottabyte konuşulmaya başlanacaktır.

> **Ders sonrası not:** Hoca sırayı zetta, yotta, exa gibi karışık saydı; doğru sıra büyük olasılıkla petabyte ($2^{50}$), exabyte ($2^{60}$), zettabyte ($2^{70}$), yottabyte ($2^{80}$) şeklindedir. Yani exabyte zettabyte'tan önce gelir.

Bugün terabyte'lar günlük hayatta rahatça konuşulmaktadır. İkinci bellek denince ağırlıklı olarak terabyte'lar, ana bellekte günlük kullanımda gigabyte'lar söz konusudur. Sunucu seviyesinde ana bellek terabyte düzeyine çıkabilir; bu tek bir parçayla değil, birden fazla parçanın bir araya gelmesiyle elde edilir.

## 13. Volatile ve Non-Volatile Bellek

> **Hocanın vurgusu:** Volatile ve non-volatile terimleri not alınmalıdır.

Bilgisayar kapatıldığında bilgilerin silindiği belleklere **volatile memory** denir. Bilgisayar kapatıldığında bilgiler silinmiyorsa **non-volatile memory** denir.

Ana bellekten silinen bilgiler, o anda açık olan programlar ve kaydedilmediyse bu programlarla yapılan işlerin sonuçlarıdır. Örneğin bir program çalıştırıp sonunda bir hesap yaptınız. Program bunu kendiliğinden kaydetmiyorsa ve siz de kaydetmediyseniz sonuç kaybolur. Bir öğrencinin verdiği örnekte olduğu gibi, Word açıkken bir şeyler yazıp kaydetmediyseniz yaptıklarınız genelde bellekte durur.

Son dönemlerde bunu önlemenin yöntemleri vardır. Kayıt işi kullanıcıya bırakılmaz, bilgiler program tarafından düzenli olarak diske yazılır. Word'deki otomatik kaydetme (auto save) buna örnektir: Bu özellik etkinleştirilirse yazılanlar belirli aralıklarla diske yazılır ve sürekli kaydetmeye gerek kalmaz.

Web tabanlı uygulamalarda da benzer bir durum vardır. Bazıları bunu destekler, bazıları desteklemez. Uzunca bir yorum yazdınız, sonunda bağlantı koptu ya da bir tuşa bastığınız anda ağınızdan veya sunucudan kaynaklanan bir sorun oldu. Otomatik kaydetme yoksa metin kutusundaki yazılarınız kaydedilmemiş olur. Kopyala-yapıştır ile de almadıysanız o kısım tamamen kaybolur. Bir form doldururken bir sonraki sayfaya geçecekken de aynı şey olabilir.

> **Hocanın vurgusu:** Bilgisayar mühendisinin önemli taraflarından biri budur: Kullanıcı tarafında ya da günlük hayatta oluşabilecek hataları öngörerek program yazmak gerekir.

Bunlar zaman içinde deneyimlenerek öğrenilmiştir. Örneğin artık formların birçoğunda cevap verilen sorular arka planda genelde otomatik kaydedilir. Bir kesinti olduğunda aynı soruları tekrar yanıtlamak gerekmez.

## 14. Sanal Bellek

Bir öğrenci diskin bazı kısımlarının bellek olarak kullanıldığını yazınca hoca sanal bellek (virtual memory) kavramını açıkladı. Ana bellek o anda yapılan işler için yeterli kapasitede değilse, sayfalama (paging) denilen yaklaşımla parça parça ikinci belleği ana bellekmiş gibi kullanan yapı devreye girer.

> **Hocanın vurgusu:** Bu nokta önemlidir: Bundan işletim sistemi sorumludur.

Hocanın sayısal örneği şöyledir:

- **Verilen:** RAM 4 GB. Birden fazla program çalıştığı için bellekte 2 GB boş kalmış. İşlenecek programın verisi 4 GB.
- **İşlem:** Programın ihtiyacı boş alanı aşıyor: $4 \text{ GB} - 2 \text{ GB} = 2 \text{ GB}$ eksik var (ara adım eklendi).
- **Sonuç:** İşletim sistemi programı "kullanılamaz" diye reddedemez, bu doğru olmaz. Bunun yerine veriyi ana bellek ile ikinci bellek arasında yer değiştirme (swap) mantığıyla taşır.

Böylece bellek o anda yetersiz olsa da program çalışır. Tek dezavantajı yavaşlamadır. Çünkü bilgiler parça parça ikinci bellekten ana belleğe taşınmalı, onlarla iş bitince de tekrar ikinci belleğe yazılmalıdır. Bunlar zaman içinde ayrıntılı öğrenilecektir.

**Soru:** İki adet 1 GB'lık RAM'den birinin arızalı olması, eski tip bir makinede güç gelmesini kesebilir mi? Arızalı bellek çıkarılınca güç geri gelmiş. **Cevap:** Büyük olasılıkla bir kaçak ya da kısa devre söz konusudur. Sorun belleğin kendisinde olabileceği gibi takıldığı slotta da olabilir. Bunların hepsi elektrikle çalıştığı için küçük bir kısa devre, ya da bir birimdeki kaçak bile anakarttaki bütün sistemi bloke edecek noktaya ulaşabilir. Çok sık rastlanan bir durum değildir, ama olabilir.

## 15. Rastgele ve Sıralı Erişim

Hoca ikinci belleklerin özetine dönerek bilgilerin kalıcı olduğunu ve erişimin rastgele ya da sıralı olabileceğini söyledi, sonra bu ikisi arasındaki farkı açıkladı.

Rastgele erişimde istenen bilgiye herhangi bir noktadan ulaşılır. Manyetik diskte disk kolu belli bir yere konumlandırılır, ana bellekte ise belleğin adresi söylenir. Sıralı erişimde ise bir bilgiye erişmeden diğer bilgiye geçilemez, adım adım ilerlemek gerekir. Örneğin bir dosyanın sonuna gitmek için dosyanın en başındaki bilgiden yola çıkılır. Bunun bir maliyeti vardır. Bu yüzden son yıllarda çok sık kullanılan bir yapı değildir.

Bunun en güzel örneklerinden biri veri yapılarındaki dizi ve bağlı liste (linked list) kavramlarıdır. Dizide, bellekte olduğu gibi adres belirtilerek dizinin istenen gözüne doğrudan gidilir. Buna rastgele erişim denir. Bağlı listede ise birbirine bağlı sayılar düşünün. En sondaki sayıya gitmek için bütün sayıların üzerinden adım adım geçmek gerekir. Buna sıralı erişim denir. Yeri geldiğinde bu konu daha net konuşulacaktır.

Hoca daha önce anlatılan sürücüleri de kısaca hatırlattı. Disk sürücüleri arasında sabit disk ve disket (floppy disk) vardır. Disketler eskide kalmıştır, ama sabit diskler ve manyetik teypler hala kullanılmaktadır. Optik sürücüler de lazer okuma-yazma sistemi kullanan ikinci belleklerdir. RAM'de ise rastgele erişim mümkündür ve okuma-yazma yapılabilir.

## 16. ROM, BIOS ve Firmware

Şimdiye kadar konuşulmayan bir birim ROM'dur (Read Only Memory). ROM'da genelde işletim sisteminin sıfırdan çalışmasını sağlayacak bilgiler ve BIOS (Basic Input Output System) ayarları bulunur. İşletim sistemi çöktüğünde ya da sıfırdan başlatılacağı zaman hangi bellek bölgesine erişileceği, hangi bilginin alınacağı burada saklanır. İşletim sistemi ilk açılırken belirli bir program yükleme mantığıyla açılır: İkinci bellekteki bir bilgi belleğe getirilir. Bunun hangi noktadan yapılacağı ve ne kadarlık bilgi getirileceği ROM'da kayıtlıdır.

ROM genelde yalnızca okunma yönünde çalışır. Son yıllarda ise silinebilir (erasable) ROM türlerine dönüşmüştür. Bunlar belirli bir yazılıp silinme miktarını destekler.

<!-- BELİRSİZ: 01:07:22'de "app ROM" ve "pair ROM" geçiyor; bunlar büyük olasılıkla EPROM ve EEPROM adlarının bozuk yazımı. -->

> **Ek bilgi (derste anlatılmadı):** Altyazıda bozuk geçen ROM türleri büyük olasılıkla EPROM (Erasable Programmable ROM) ve EEPROM (Electrically Erasable Programmable ROM) türleridir. Bu türlerden ilkinin içeriği büyük olasılıkla morötesi ışıkla, ikincisinin içeriği ise elektrik sinyaliyle silinir.

ROM'a yazma ihtiyacı firmware kavramından doğar. Bir donanımın donanımsal yeteneği olduğu hâlde yazılımsal olarak yapamadığı işler olabilir. Bu yeteneği kazandıran yeni bir yazılım geliştirildiğinde, firmware ROM üzerine yazılır ve cihazın çalışma yetenekleri artırılır. Çok eski bilgisayarlarda, yalnız okunabilir bellekler varken firmware güncelleme şansı yoktu; bilgisayar geldiği hâliyle kalırdı. Zamanla cihazların yeteneklerinin uzaktan artırılması mümkün olunca firmware güncellemeleri gelmeye başladı.

Akıllı televizyonlar buna örnektir. İlk çıktığında belli yeteneklere sahip olan televizyona sonra bir yazılım güncellemesi gelir. Burada söz edilen, gömülü sistemin donanımsal yeteneğidir. Firmware denince normal bir yazılım güncellemesi değil, cihazın standart görevlerine ek yetenekler kazandıran, ROM üzerinde yapılan güncelleme kastedilir.

Bütün eski cihazlara yeni firmware yüklenemez. Örneğin belli bir sürüme kadar güncelleme yapılabilir. Belirli bir sürümden sonra cihazın donanım kapasitesi yeni yazılım özelliklerini destekleyemeyeceği için firma o cihazlara güncelleme göndermez. Cep telefonlarında bu sık görülür: Hocanın örneğine göre belirli bir süredir eski iOS cihazları desteklenmiyor. Bu cihazlar en son aldıkları sürümle çalışmaya devam eder.

<!-- BELİRSİZ: 01:09:34'te "bütün eski cihazlar üzerine ... yapılabilir" geçiyor; devamı gereği "yapılamaz" olarak yazıldı. -->

> **Ders sonrası not:** Altyazıda "iOS 6S'den eski versiyonlar ya da 6'dan eski versiyonlar" geçiyor; 6S bir işletim sistemi sürümü değil, büyük olasılıkla iPhone 6S modelidir.

Giriş ve çıkış birimleri geçen ders konuşulmuştu. Klavye, fare ve tarayıcı ile dışarıdan bilgi alınır; monitör ve yazıcı ile dışarıya bilgi aktarılır.

## 17. Bilgisayar Organizasyonu

Bilgisayar organizasyonunda en alt kademede donanım vardır: ekran kartı, ses kartı, anakart, işlemci, ana bellek ve ikinci bellek gibi. Slayttaki mikroprogramlama (micro programming) katmanını hoca, belki sürücülerin (driver) donanımları yetenekli hâle getirmesi olarak aktarılabileceğini, ama bunun ayrı bir konu olduğunu söyleyip geçti.

> **Ders sonrası not:** Hoca mikroprogramlama katmanını temkinli biçimde sürücülere benzetti; büyük olasılıkla bu katman sürücü yazılımı değil, makine komutlarını işlemci içinde daha küçük adımlara bölen katmandır.

Üstünde makine dili vardır. Makine dili 0 ve 1'lerden oluşur. Bu 0 ve 1'lerin anlamlandırılmasıyla bütün bilgisayar ve elektronik cihazlarda işler döner. Makine diline en yakın kullanılabilir dil assembly dilidir ve literatürde alt seviye programlama dili olarak geçer. Farklı mimariler için farklı komut setleri vardır.

Makine dilinin üzerinde işletim sistemi yer alır. Hemen arkasından derleyiciler, editörler, yorumlayıcılar ve veritabanları gibi temel yazılımlar gelir. Bunlar ağırlıklı olarak sistem yazılımlarıdır. En üst katmanda müzik çalma, video gösterme uygulamaları, Notepad, Word ve Excel gibi uygulamalar bulunur. Bunlar, sistem yazılımlarından farklı olarak programcılar tarafından geliştirilen ve günlük hayattaki işleri yapmayı sağlayan ek yazılımlardır.

Yapı aşağıdan yukarı şöyle özetlenir:

- Donanım
- Donanımı kullanmayı sağlayan makine dili
- Makine diliyle ortak çalışan işletim sistemi
- Sistem yazılımları
- Uygulama yazılımları (application software)

## 18. İşlemci Mimarileri ve Komut Setleri

Hoca öğrencilere farklı işlemci mimarilerine örnek sordu. x86 ve ARM cevapları geldi. x86, Intel işlemci mimarisi kapsamındadır ve ağırlıklı olarak kişisel bilgisayarlarda kullanılır. ARM ise daha çok mobil cihazlarda kullanılır. ARM'in ağırlıklı olarak mobilde kullanılması bir kısıt değildir; hoca, Apple'ın bunu planladığının bilindiğini söyledi. Başka üreticilerin de kendi işlemcileri ve mimarileri vardır.

<!-- BELİRSİZ: 01:12:39'da "ABD'nin işlemcileri var, onların işlemci üniversitesi var" geçiyor; büyük olasılıkla "AMD'nin işlemcileri, işlemci mimarisi" kastediliyor. -->

İşlemciler belli komutlarla çalışır ve bu komutlar komut setini oluşturur. Dünyada temelde iki tip komut seti ağırlıklı olarak kullanılır:

- **RISC (Reduced Instruction Set):** Daha basit komutlar vardır. Karmaşık işler, basit komutları bir araya getirerek yapılır.
- **CISC (Complex Instruction Set):** Karmaşık komutlar vardır ve komut seti daha fazla komuttan oluşur. Karmaşık işler doğrudan bu komutlarla yapılır.

İkisinin artı ve eksileri ilerleyen derslerde, işletim sistemleri konusuna yakın bir yerde konuşulacaktır. Hoca bu konuya öğrencilerin kendilerinin de bakabileceğini söyledi.

> **Hocanın vurgusu:** İşlemci mimarisi önemlidir, çünkü işletim sistemi dahil bütün yazılımlar bilgisayara bu mimariye göre kurulur.

Yazılımların işlemci mimarisinin yapısına uygun tasarlanması gerekir. Uygun olmayan bir işletim sistemi yüklenmeye kalkılırsa zaten otomatik olarak bir hata mesajı alınır.

## 19. İşletim Sistemi ve Yazılım Türleri

### 19.1 İşletim Sisteminin Görevleri

Bilgisayardaki en ana ve en büyük sistem yazılımı işletim sistemidir. Kaynak yönetiminden sorumludur. Bazı elektronik cihazlarda da işletim sistemi bulunur. Görevleri şunlardır, ayrıntıları işletim sistemi konusunda görülecektir:

- Süreç yönetimi (process management)
- Bellek yönetimi (memory management)
- Dosya yönetimi
- Cihaz yönetimi (device management)
- Giriş/çıkış yönetimi (I/O management)

### 19.2 Sistem Yazılımları

Yazılımlar kabaca ikiye ayrılır: sistem yazılımları ve uygulama yazılımları. Sistem yazılımları sistemi doğrudan ilgilendirir. İşletim sistemi kaynakları yönetmek için kullanılır. Derleyiciler, yazılan programları makine diline çeviren sistem yazılımlarıdır. Yorumlayıcılar (interpreter) da aynı işi yapar, ama derleyici ile yorumlayıcı arasında fark vardır. Bu fark önümüzdeki dönemlerde konuşulacaktır.

### 19.3 Uygulama Yazılımları

Uygulama yazılımları daha çok belirli bir alana (domain) özeldir. Sistemle doğrudan ilgisi yoktur. Programcıların, farklı mesleklerdeki ve farklı ihtiyaçlara sahip kişilerin işlerini görmek için yazdığı yazılımlardır. Oyunlar, eğitim uygulamaları, AutoCAD gibi çizim uygulamaları ve istatistik hesaplamaları yapan paketler ile kütüphaneler bunlara örnektir.

## 20. Programlama Dillerinin Nesilleri

Son konu programlama dillerinin seviyeleridir. Slaytta nesiller şöyle sıralanır:

- 1\. nesil: makine kodu
- 2\. nesil: assembly dilleri
- 3\. nesil: yöntemsel (procedural) diller
- 4\. nesil: uygulamaya özel diller
- 5\. nesil: kısıtlı diller

### 20.1 Birinci Nesil: Makine Kodu

Makine kodu (machine code), 0 ve 1'lerle kodlamayı mümkün kılar. Hocanın örneklemesiyle, toplama için 0100, çarpma için 110 gibi bir dizi yazılır ve derdinizi bilgisayara bu dille anlatırsınız. Daha önce görülen kablolamalar da buna örnektir: 1950'li yıllarda elektronik hatta mekanik sürümlerde kablo bir yere takılır ya da boş bırakılır, boş bırakmak 0 anlamına gelecek şekilde kodlama yapılırdı.

Bugün 0 ve 1'lerle kodlama yapmak pek mümkün değildir. Kombinasyonlar o kadar çoktur ki bir yerden sonra bunları arka arkaya yazmak mümkün olmaktan çıkar, okumak bile zordur. Slaytta iki sayıyı toplayan bir makine kodu gösterilmiştir. Hangi sayıların toplandığını ya da hangi kısmın toplama komutu olduğunu anlamak çok zordur.

<!-- BELİRSİZ: 01:20:32'de slayttaki makine kodu okunmuyor, altyazıda rakamları geçmiyor. 01:18:33'teki 0100 ve 110 örnekleri de temsilîdir; gerçek işlem kodu olarak alınmamalıdır. -->

İşlemciler ise hala bu yapıları kullanır. Onlar için 0 ve 1'lerin kombinasyonlarını yorumlamak çok kolaydır, çünkü belirli bir kural dahilinde çalışırlar. O kombinasyon geldiğinde ne yapılacağı komut setinde bilindiği için iş otomatik yapılır ve "tıkır tıkır" ilerler. Kısacası makine kodunu insanın anlaması zordur ve hata yapmak kolaydır.

### 20.2 İkinci Nesil: Assembly Dilleri

Hemen arkasından assembly dilleri geldi. Bunlar 1950'li yıllara uzanır. Makine koduna en yakın, ama insanın da anlayabileceği komutlar kullanılır: `ADD`, `SUB`, `MUL`, store ve load gibi rakamlardan uzak, nispeten anlaşılır ifadeler. Bunlar alt seviye (low level) programlama dilleri olarak geçer. Hoca "alçak seviye" ifadesinin tam doğru olmadığını, "alt seviye" denmesi gerektiğini belirtti.

İki sayıyı toplamak için `ADD` komutu kullanılır:

```
ADD AX, BX
```

Bu, AX register'ındaki ve BX register'ındaki değerleri al ve topla anlamına gelir. Biraz önce çok uzun yazılan ifade daha basit hâle gelmiştir. Yine de matematik yazımından ve günlük kullanımdan uzaktır.

Bilgisayar yalnız makine kodunu anladığı için, derleyici gibi bir ara dönüştürücü gerekir. Bu dönüştürücüye **assembler** denir. Görevi, assembly dilinde yazılan programı alıp bilgisayarın anlayacağı makine diline çevirmektir. Yazılan kod object koda çevrilir ve işlemci bu kodu alarak işleri gerçekleştirir.

Assembly'nin de sınırları vardır. Bir iş yapılırken çok fazla alt ayrıntı içerir, üç satırlık bir iş yirmi satırda yazılmak zorunda kalınır. İşler karmaşıklaştıkça kodlar uzar ve kodlama maliyetli hâle gelir. Daha basit, konuşma diline daha yakın dillere ihtiyaç doğmuştur.

Bir sorun daha vardır: Farklı mimariler farklı assembly komutları kullanır, bu yüzden her mimari için yeni bir komut seti öğrenmek gerekir. Hocanın benzetmesi şöyledir: Bu, her ülkedeki vatandaşla o ülkenin dilinde konuşmak gibidir, İspanyolca öğrenmeniz, Fransızca öğrenmeniz gerekir. Bunun yerine bir üst seviye yazılırsa, yani araya Google Translate gibi bir çevirmen konursa, siz tek bir dil konuşursunuz. Çevirmen sizin dilinizi alıp karşıdakinin ana diline çevirir, iş de çok hızlanır.

### 20.3 Üçüncü Nesil: Yöntemsel Diller

İşte bu noktada ileri seviye (high level) programlama dilleri devreye girer. Slaytta Fortran, Algol, Pascal, C ve Java sayılır. Hoca, bu derste yıllarca Fortran ve Pascal ile başlandığını, Pascal'ın 3-4 yıl önce bırakıldığını ve artık C dilinin gösterildiğini söyledi. Bu yöntemsel dillerde çok daha az komutla çok daha fazla iş yapılır. Derste de C ile toplama, çıkarma gibi işlerin ne kadar kolay yapılabildiği görülecektir.

Yine de C, sistem seviyesinde bir dil olarak alt katmanlara yakındır. Ondan çok daha kolay diller vardır, C ile yazılmış olan Python gibi. Python'da 3 satırlık bir iş C'de belki 15-20 satır sürer. Yani dili sadeleştirmek her zaman mümkündür, ama bunun için araya mutlaka bir dönüştürücü koymak gerekir. Bu dönüştürücü bir derleyici ya da yorumlayıcı olabilir.

Bunun bedeli de çevirmenin kalitesidir. Çevirmen ne kadar iyiyse söyledikleriniz karşı tarafa o kadar verimli aktarılır. Kötü bir derleyici yazılan kodu makine koduna kötü çevirirse performansı düşük programlar kullanmak zorunda kalınabilir.

> **Hocanın vurgusu:** Aradaki dönüştürücünün başarılı ve verimli çalışması gerekir. Yüksek seviyeli dillere çıkıldığında tercih edilen dönüştürücüler programın performansını doğrudan etkiler.

### 20.4 Dördüncü ve Beşinci Nesil

Yöntemsel dillerden sonra uygulamaya özel diller ve kısıtlı diller gelmiştir. Hoca bunların ayrıntısına ileride bakılacağını söyledi.

### 20.5 Ders Sonunda Gelen Soru

**Soru:** Rastgele erişim ve sıralı erişim arasındaki fark nedir? **Cevap:** Rastgele erişimde (direct access), erişilmek istenen bellek bölgesinin istenen noktasına gidilip doğrudan erişim yapılır. Sıralı erişimde ise gidilmek istenen bölge ilk sırada değilse, örneğin $n$. sıradaysa, $n$. sıraya gidene kadar diğer bilgileri de almak (fetch) gerekir. Bunlara eriştikten sonra ilgili bölüme ulaşılır. Doğal olarak rastgele erişim, sıralı erişime göre çok daha hızlıdır.

## Dersin Toparlaması

Ders, CPU'nun kontrol birimi ve ALU'dan oluşan yapısıyla başladı, GPU'nun neden önem kazandığını gösterdi ve bellek hiyerarşisine geçti. Piramidin tepesinde register, cache ve ana bellek vardır; aşağı indikçe manyetik disk, SSD, optik diskler, flash bellekler ve manyetik teypler gelir. Yukarı çıktıkça hız ve maliyet artar, kapasite azalır. Ana bellek byte'lık hücrelerden oluşur, hücrelere adresleriyle erişilir, adresler onaltılık yazılır ve her tür bilgi 0 ve 1 olarak saklanır. Bilgi boyutları ikinin kuvvetleriyle ilerler, bu yüzden 1 KB 1024 byte'tır. Volatile ve non-volatile ayrımı, sanal bellek, rastgele ve sıralı erişim, ROM ve firmware bu tabloyu tamamlar.

Dersin ikinci yarısı bilgisayar organizasyonuna ayrıldı. Donanımın üzerinde makine dili, işletim sistemi, sistem yazılımları ve uygulama yazılımları yer alır. İşlemciler RISC ya da CISC komut setleriyle çalışır. Programlama dilleri makine kodundan assembly'ye, oradan yöntemsel dillere doğru insana yaklaşır; bunun karşılığında iyi bir çevirici ihtiyacı doğar. Kalan slaytlardan sonra sıradaki konu verinin nasıl saklandığıdır: hangi tiplerin kullanıldığı, tam sayıların, kesirli sayıların ve harflerin bilgisayarda nasıl tutulduğu konuşulacak, boyutların üzerinden de bir kez daha geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
