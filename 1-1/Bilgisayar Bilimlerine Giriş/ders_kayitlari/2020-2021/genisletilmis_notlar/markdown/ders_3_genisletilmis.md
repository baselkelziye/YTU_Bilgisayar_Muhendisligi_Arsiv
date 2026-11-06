# Ders 3 Genişletilmiş Notu: Bilgisayarın Tarihçesi, von Neumann Mimarisi, Donanım ve Yazılım

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Amacı ve Kapsamı
- 2. Kaynaklar ve Terimleri Doğru Öğrenmek
- 3. Hesaplamanın Başlangıcı: Abaküs
- 4. Bilgisayar Biliminin Hedefi: Otomasyon
- 5. Mekanik Dönem: Charles Babbage
- 6. Analog ve Dijital Veri
- 7. Analytic Engine'in Birimleri ve İlk Programcı
- 8. İlk Elektronik Bilgisayarlar ve ENIAC
- 9. Mainframe'ler
- 10. Kişisel Bilgisayarlar
- 11. Süper Bilgisayarlar ve Paralel İşlem
- 12. İnsan ve Bilgisayar Nasıl Karar Verir?
- 13. Teknolojiyi Sorumlulukla Kullanmak
- 14. Sanallaştırma
- 15. Bilgisayar Mühendisliği Eğitimi ve Programlama Dilleri
- 16. von Neumann Mimarisi
- 17. Bilgisayar Organizasyonu: Donanım
- 18. Yazılım ve İşletim Sistemi
- 19. Bellek Türleri, Giriş ve Çıkış Birimleri, Sensörler

## 1. Dersin Amacı ve Kapsamı

Bu dersin amacı, bilgisayar mühendisliğine girişteki temel bilgileri aktarmaktır. Hoca dersin cevaplayacağı soruları şöyle sıraladı: Bilgisayar mühendisi kimdir ve ne yapar? Bilgisayar nedir, onunla neler yapabiliriz? Yalnız bilgisayarla değil, elektronik cihazlarla neler başarabiliyoruz? Hocaya göre bu son soru önemlidir, çünkü günümüzde artık yalnız bilgisayarı konuşmuyoruz. Neredeyse her eşya kendi içinde bir bilgisayar gibi davranmaya başladı. Bunların bazılarında işletim sistemi vardır, bazılarında yoktur.

Derste ayrıca eski bilgisayarların boyutları ve yapabildikleri, yazılım ve donanım kavramları, bilgisayarın "iç organları" ve görevleri, bir bilgisayar mühendisinin mezun olduğunda hâkim olması gereken konular ele alınacak.

> **Hocanın vurgusu:** Dersin en önemli önceliği algoritma kavramıdır: Algoritma nedir, nasıl tasarlanır, bir problem nasıl çözülür, bilgisayara bir iş nasıl yaptırılır?

### 1.1 Konu Akışı

Hoca dönem boyunca izlenecek sırayı şöyle anlattı:

- **Bilgisayarın tarihçesi ve hesaplama makineleri:** Tam anlamıyla bilgisayar olmadan önceki mekanik cihazlar ve elektrikten sonraki elektronik cihazların nasıl evrildiği.
- **Verinin saklanması:** Bilgisayarın ikili (binary) sistemi, yani sıfırlar ve birler. Ardından 2, 8, 10 ve 16 tabanlı sayı sistemleri. Hoca bu sırada Roma rakamlarını da andı.
- **Bilgisayar mimarisi:** Bilgisayarın içi, veri üzerinde yapılabilen işlemler, tam sayıların ve kesirli sayıların bilgisayarda nasıl saklandığı.
- **Algoritma ve gösterim biçimleri:** Bu derste akış diyagramı (flowchart) kullanılacak. Şekillerle ifade edilen bir notasyondur. Bir başka notasyon olan sözde kod (pseudocode) ise daha çok yazıyla ifade edilir.
- **Giriş problemleri:** Bir algoritmaya girdinin nasıl verildiği, çıktının nasıl alındığı, iteratif işlemler ve döngüler.
- **C ile kodlama:** Algoritmik tasarımın temelleri bitip bazı problemler çözüldükten sonra, çizilen akış diyagramları kod sözdizimine (syntax) çevrilip bilgisayarda çalıştırılacak.
- **Diziler:** Bir değişkende tek değer saklanırken dizide aynı tipte birden fazla değer saklanır. Karakterlerin saklandığı dizilere, yani karakter gruplarına string denir. Metin üzerinde bir iş yapmak için karakterin bellekte nasıl saklandığı da görülecek. Çok boyutlu dizilerin iki boyutlusuna matris denir. Üç ve dört boyutluları da vardır, ama öncelik matrislerdir.
- **İşletim sistemleri ve bilgisayar ağları:** Sonlara doğru algoritmaya ara verilip işletim sisteminin ne yaptığı ve farklı tipleri konuşulacak.
- **Arama ve sıralama algoritmaları:** Hocanın bilgisayar bilimlerindeki en önemli iki konu olarak andığı bu algoritmalarla dönem bitecek.

C dili burada tam olarak öğretilmeyecek. Hoca dilin özelliklerine neredeyse hiç dokunulmayacağını, yalnız kritik kısımların paylaşılacağını söyledi. Amaç programlama dili öğretmek değil, tasarlanan algoritmaları bilgisayara anlatacak kadar programlamayı aktarmaktır. Ödev ve projeler için dilin başka özellikleri gerekirse o kadarını öğrenmek yeterli görülecek. Dil, ikinci dönemde Yapısal Programlama dersinde bütün özellikleriyle işlenecek.

### 1.2 Algoritmayı Analiz Etmek ve Dönem Sonu Beklentisi

Hoca öğrencilerin zamanla kendi problemlerini de üretmesini bekliyor: "Şöyle bir problem olsaydı bunu bilgisayara nasıl yaptırırdım?" Böylece kişi kendi problemlerini çözmeye başlar. Çözümün doğru olup olmadığının nasıl sınanacağı da bu dersin konusudur.

> **Hocanın vurgusu:** Algoritma tasarlamak çok önemlidir, ama algoritmanın doğru çalıştığını göstermek de çok önemlidir. Çizdiğiniz akış diyagramı mutlaka analiz edilmelidir: verilen girdi için istenen çıktıyı üretiyor mu?

Dönem sonunda beklenen, şu dört adımı yapabilen bir öğrencidir:

- Verilen problemi anlamak, analiz edip sınırlarını belirlemek.
- Problemi çözmek için algoritma tasarlamak.
- Tasarlanan algoritmayı analiz etmek.
- Algoritmanın kodunu yazmak.

**Soru:** Hiçbir şey bilmeden geldik, sıkıntı olur mu? **Cevap:** Hoca işin özünün zaten bu olduğunu, programın sıfırdan öğreniliyormuş gibi hazırlandığını söyledi. Biraz zorlanılabilir, ama bu aşılabilecek bir durumdur.

## 2. Kaynaklar ve Terimleri Doğru Öğrenmek

Dersin kitabı Brookshear'ın *Computer Science: An Overview* kitabıdır. Hoca bunu bilgisayar bilimleri için başucu kitabı olabilecek güzel bir kitap olarak niteledi. Ancak kitap bütün ders boyunca izlenmeyecek. Dersin toplam 5-6 haftalık kısmını net olarak içeriyor. Algoritmik problemler ise kitaptan değil, daha çok önceki yıllarda derste kullanılan örneklerden gelecek. Ek kaynak olarak Türkçe *Algoritma Geliştirme ve Programlamaya Giriş* kitabı önerildi. Hoca genelde Türkçe kaynak önermediğini, ama bu kitabın özellikle başlangıçta zorlananlara faydalı olabileceğini söyledi.

<!-- BELİRSİZ: Türkçe kitabın yazarı altyazıda söylenmiyor. Kısa nota göre ekranda Fahri Vatansever yazıyor. -->

**Soru:** *Computer Science: An Overview* kitabının Türkçesini alsak olur mu? **Cevap:** Tercih size kalmış. Kitabı satın alma zorunluluğu yok, PDF ile de ilerlenebilir. Hocanın önerisi İngilizcesini takip etmektir.

### 2.1 İngilizce ve Türkçe Terimler

Hoca derslerinde olabildiğince İngilizce kaynak takibi önerdiğini, böylece hem İngilizcenin gelişeceğini hem de terimlerin İngilizce öğrenileceğini söyledi. Örnek olarak cache kelimesini verdi. Bunu her yıl yaşanan bir problem olarak anlattı: Önceki yıllarda ders sonunda aldığı defterlerde kelimenin yanlış yazıldığını görmüş. Kelimeler yabancı olduğu için böyle not alınması doğaldır, ama doğrusunu öğrenmek gerekir.

<!-- BELİRSİZ: Hoca cache kelimesinin doğru ve yanlış yazılışını ekrana yazıp gösterdi. Yanlış yazım altyazıda yok. -->

> **Hocanın vurgusu:** İngilizce terimlerin doğrusunu öğrenmekte fayda var. Ama yalnız İngilizcesini değil, Türkçesini de bilmek önemlidir. Her iki dile de hâkim olmak gerekir.

Bilgisayar mühendisliği evrensel bir mühendisliktir. Öte yandan kendi dilimizde de her kavram için yeni kelimeler ortaya atılıyor ve yerleşiyor. Hoca bunların bir kısmının kulağa hoş geldiğini, bir kısmının kulak tırmaladığını, ilk duyulduğunda yadırganan kavramların zamanla yerleştiğini söyledi.

Araştırma yaparken de aynı öneri geçerlidir. Örneğin 2020'nin en popüler programlama dillerini ve bunların ne için kullanıldığını öğrenmek istiyorsanız aramayı İngilizce yapın ("Top 10 Programming Languages" gibi). Türkçe kaynaklardan da öğrenilecek güzel bilgiler vardır, ama güncel olan genelde İngilizce kaynaklardır.

## 3. Hesaplamanın Başlangıcı: Abaküs

Hoca tarihçeye "Bilgisayar aslında nasıl bir cihazdır, bugünlere nasıl geldik, bilgisayar bilimlerinin ilk temelleri ne zaman atıldı?" sorularıyla girdi. Hikâye abaküsle başlar. Hoca bunu Babil dönemine, M.Ö. 300 yılına bağladı. İlkokullarda da kullanılan bu boncuklu araçla toplama ve çıkarma yapılıyor, o andaki sayı boncuklarla ifade ediliyordu.

> **Ders sonrası not:** Hoca abaküsü M.Ö. 300 ile tarihledi; abaküs benzeri araçların geçmişi büyük olasılıkla daha eskidir ve kesin bir başlangıç tarihi vermek zordur.

Bütün işlerimiz aslında hesaplama (computation) ile başlar. İlk hedef iki sayıyı toplamaktır. Hocanın örneğiyle:

- **Verilen:** 4 ve 5.
- **İşlem:** $4 + 5$.
- **Sonuç:** $9$.

Bunu akıldan yapabiliriz. Asıl soru, daha büyük işlemleri kendimiz yapmak yerine bir makineye yaptırıp yaptıramayacağımızdır. Bilgisayardan beklenen de budur. Bu hikâyede verinin temsili slayttaki abaküste siyah ve beyaz boncuklarla sağlanıyordu. Yani verinin bir şekilde temsil edilmesi fikrinin ilk temelleri, farkında olmadan o yıllarda atılmış oldu. Bu konsept gelişerek bugünkü hâlini aldı.

## 4. Bilgisayar Biliminin Hedefi: Otomasyon

Tarihçeye devam etmeden önce hoca şu noktayı açtı: Bilgisayar bilimlerinin en önemli hedefi, insanın kendi yaptığı işlerin mümkün olduğunca bilgisayar tarafından yapılabilir hâle getirilmesi, yani otomatikleştirilmesidir. Bunu iki günlük hayat örneğiyle anlattı.

### 4.1 Örnek: Binaya Giriş

Eskiden bir binaya veya tesise girerken hiçbir teknoloji kullanılmazdı. Bir insan kimliğinize bakar, isim kontrolü yapar, girişinize izin verir veya sizi reddederdi. Bugün bazı noktalarda bunun için insana gerek yoktur. İş, bilgi sistemlerine geçmiştir.

**Soru:** Bu kontrolü bugün bilgisayarla nasıl yapıyoruz? **Cevap:** Öğrencilerle birlikte şu çözümler sayıldı: retina tarama, parmak izi okuma ve kartlı geçişler. Hoca bunlara cep telefonlarındaki Face ID'yi, yani yüz tanımayı ekledi. Böylece insan olmadan güvenli giriş çıkış yapılabiliyor, yetkiniz yoksa da giremiyorsunuz. Yıllarca insanın çözdüğü bir problem artık rahatça bilgisayara yaptırılıyor.

### 4.2 Elektronik Cihaz Çeşitleri

Hoca burada yalnız "bilgisayar" demenin eksik kalacağını belirtti, çünkü bilgisayar konseptinin yanına yeni konseptler eklendi: cep telefonları ve akıllı telefonlar, tabletler, sunucular, kişisel bilgisayarlar, dizüstü bilgisayarlar ve nesnelerin interneti (Internet of Things, IoT) cihazları. Neredeyse her eşya akıllı hâle gelmeye başladı. Arabalar da akıllanıyor. Akıllı evlerde evin kendi bilgi sistemi var ve giriş çıkışlar bu sistem üzerinden kontrol ediliyor. Bunların hepsi özellikle gömülü sistem (embedded system) olarak geçiyor. Hepsinin amacı insanın hayatını kolaylaştırmak ve insanın çözmesi zor olan, hesaplama yükü gerektiren problemleri çözmektir.

### 4.3 Örnek: Trafik Bilgisinin Evrimi

İkinci örnek trafik. Bugün Yandex, Google Maps veya YBB Navigasyon gibi uygulamalarla gitmek istediğiniz yere ne kadar sürede varacağınızı ve en kısa yolu öğrenebiliyorsunuz. Hoca bu işin evrimini adım adım anlattı:

- **En eskiden:** Bu bilgiyi almak mümkün değildi.
- **Cep telefonundan sonra:** O bölgeden geçen bir yakınınıza köprüde trafiğin nasıl olduğunu soruyordunuz. Yarım saat önce geçen birinden bilgi alabiliyordunuz. En fazla teknoloji cep telefonuydu.
- **Hız bilgilerinin merkeze akmasıyla:** Haritada yeşil, sarı, turuncu ve kırmızı renkleri görmeye başladınız. Yoğunluğa bakıp kendiniz kestirim yapıyordunuz. Orası tıkalıysa yola çıkmıyordunuz.
- **Bugün:** Aynı bilgiler kullanılarak en kısa yol ve varış süresi hesaplanıyor. Süre çok yüksek doğrulukla tahmin ediliyor, yola çıkmadan bakılabiliyor, yolda gelişmelere göre güncellenebiliyor.

### 4.4 Bilgisayarın Gücü ve Bilgisayar Biliminin Merkezi

Bilgisayarın en önemli gücü, bu problemleri veriyi işleyerek otomatik olarak çözmesidir. Bunun için bilgisayara veri temin etmek, yani veriyi toplamak zorundasınız. Verinin nasıl toplandığı ve sonucun insana nasıl geri döndürüldüğü ilerleyen derslerde konuşulacak.

Bilgisayar biliminin ilgilendiği birçok temel konu vardır, ama hocaya göre en merkezde algoritmalar, veri yapıları ve hesaplama kuramı bulunur. Bilgisayar dünyasındaki gelişmeler çok hızlı olduğu için değişimlere ayak uyduran yeni çözümler de bunlara eklenir.

## 5. Mekanik Dönem: Charles Babbage

Hoca, M.Ö. 300'den itibaren 1700'lere, 1800'lere kadar pek bir değişiklik olmadığını söyledi. Asıl büyük değişiklik, Charles Babbage ile 1700'lerin sonu ve 1800'lerin başında mekanik bir cihazın tasarlanmasıyla başladı.

Önce bir girişim olarak **Difference Engine** (Fark Makinesi) tasarlandı. Hoca makinenin amacını sayıların kareleri arasındaki farkı hesaplayacak bir yapı kurmak olarak anlattı ve tasarımın ayrıntılarına girmedi. Ardından **Analytic Engine** geldi. Bu tamamen mekanik bir tasarımdı, elektronik söz konusu değildi. Bir ev büyüklüğündeydi ve 6 buhar makinesiyle besleniyordu.

<!-- BELİRSİZ: Babbage'ın yaşam tarihleri (1791-1871), Difference Engine için 1821 yılı, makinenin logaritmik tablo gibi tabloları hesaplaması ve tamamlanamaması altyazıda söylenmiyor. Bunlar kısa nota göre slaytta yazıyor. Slayt görülmedi. -->

> **Ders sonrası not:** Hoca Difference Engine'in amacını karelerin farkını hesaplamak olarak özetledi; doğrusu büyük olasılıkla makinenin polinom değerlerini sonlu farklar yöntemiyle hesaplayarak tablo üretmeyi hedeflemesidir. Karelerin farkı da büyük olasılıkla bu yöntemin yalnız basit bir hâlidir. Ayrıca Babbage'ın bu tasarımları büyük olasılıkla 1700'lerin sonuna değil, 1820'ler ve sonrasına aittir.

### 5.1 O Günden Bugüne Ölçek Farkı

Hocanın buradan çıkardığı ders şuydu: İlk bilgi işleme cihazları, yani bilgisayarın ataları çok büyüktü, çok fazla enerji tüketiyordu ve çok basit işler yapabiliyordu. Bugün bir bilgisayar saniyede milyar mertebesinde iş yapabiliyor. Buradaki "iş" toplama, çıkarma veya karşılaştırma gibi temel işlemlerdir. Yaklaşık 200 yıllık bu süreçte boyutta, enerji tüketiminde ve maliyette çok büyük bir devrim oldu. Bu yüzden bu çağa teknoloji çağı ve bilgi çağı diyoruz.

### 5.2 Delikli Kartlar

Bu programlanabilir cihaza bilgi aktarmak için delikli kartlar (punched card) ve delikli kâğıtlar kullanılıyordu. Delikler bir, delik olmayan yerler sıfır gibi düşünülebilir, ya da tam tersi. Hoca bu noktada o dönemde her şeyin aslında analog yürüdüğünü söyledi ve konuyu analog ile dijital farkına getirdi.

> **Ders sonrası not:** Hoca o dönemde her şeyin analog yürüdüğünü söyledi; doğrusu büyük olasılıkla Analytic Engine'in mekanik olduğu, ama sayıları ayrık basamaklarla işlediği için analog değil, mekanik ve dijital bir tasarım sayıldığıdır. Delikli kartın delik var veya yok biçimindeki ayrık yapısı da büyük olasılıkla bununla uyumludur.

## 6. Analog ve Dijital Veri

Hoca önce öğrencilere analog ile dijital arasındaki farkı sordu.

**Soru:** Analog ile dijital arasındaki farkı kabaca nasıl yorumlarsınız? **Cevap:** Öğrencilerden şu yorumlar geldi: Analogda iki değerden fazla değer alınabilirken dijitalde yalnız sıfır ve bir vardır. Analogda belirli voltaj değerleri dönüştürülerek farklı değerler elde edilir, dijitalde ise elektrik ya var ya yoktur. Analogda bilginin fiziksel bir karşılığı olması gerekir, dijitalde buna gerek yoktur. Hoca bunları başlangıç olarak kabul edip tanımı şöyle toparladı: Analog sürekli (continuous) veriyi, dijital ayrık (discrete) veriyi ifade eder.

### 6.1 Sürekli ve Ayrık Veri

Analog veride bir bilgiyi ifade ederken sonsuz sayıda değerden faydalanabilirsiniz. Hoca bunu integral alırken alan hesaplamaya benzetti ve ekrana bir sinüs ya da kosinüs eğrisi çizdi. Bu eğrideki her noktayı en küçük parçaya, sonsuza kadar inerek bölebilirsiniz. Analog bilgi işte budur. Böyle bir eğri sürekli verilerle ifade edilir.

Sürekli veri zaman içinde ayrık veriye dönüştürülür. Bunun karşılığı sıfırlar ve birlerdir. Hocanın örneği bir resimdi:

- **Siyah-beyaz resim:** Her piksel için iki değer vardır: siyah 0, beyaz 1. Resim yalnız bu kadar ayrıntıya sahiptir.
- **8 bit gri seviye:** Daha fazla ayrıntı için gri tonlar gerekir. 8 bit ile $2^8 = 256$ farklı ton elde edilir, yani siyahtan beyaza 256 tona ayırabilirsiniz.

Bit seviyesini artırdıkça resmin ayrıntısı artar. Sürekli veride ise sonsuz derecede ifade edilebilen bir bilgiye erişirsiniz.

### 6.2 Analog Saklama: Kaset ve Film Şeridi

Eskiden müzik kayıtları kasetlerde saklanıyordu. Müzik bilgisi teyp şeritlerine yazılıyor, bilgi fiziksel olarak kasetin üzerinde duruyordu. Sinemada kullanılan, bugün de zaman zaman görülen büyük film şeritlerinde de durum aynıdır. Çekim yaptığınızda bilgiyi fiziksel olarak bu şeritlerdeki bantlara gömersiniz.

Hocaya göre bu sayede çok eski filmler, 15-20 yıl önceki dijital teknolojiyle karşılaştırıldığında çok daha kaliteli görünüyordu. Ancak bir pikseli 8 bit yerine 32, 64, 128 bitle ifade etmeye başladıkça, yani dijital derinlik arttıkça, çok daha kaliteli görüntüler ortaya çıktı. Bugün dijital, analogla yarışır hâle geldi.

### 6.3 Kopyalama, Dağıtım ve Güvenlik

Analog bilgi özünde her zaman fiziksel bir malzeme üzerindedir. Bu malzemeyi bir noktadan bir noktaya sorunsuz ve kolayca aktarmak pek mümkün değildir. Bir filmden kopya istiyorsanız o malzemeden $n$ tane üretmeniz, sonra da fiziksel olarak göndermeniz gerekir. Dijital bilgi ise tekrar tekrar, rahatça kopyalanıp dağıtılabilir. Bir filmi Amerika'daki sunuculardan kendi bilgisayarınıza indirebiliyorsunuz. Eskiden bu mümkün değildi.

Bu hızın bir bedeli vardır. Bilgi bu kadar hızlı dolaştığı için manipülasyona açıktır. Hayatı çok kolaylaştırsa da birçok noktada bilginin gerçekten orijinal olup olmadığını doğrulamaya ihtiyaç duyuyoruz. Dijital dünya, bilgiyi hızlı dolaştırma ve çok sayıda kopya saklama imkânının yanında analoga göre büyük güvenlik zafiyetleri de yarattı. Bu yüzden bugün en önemli konulardan biri bilişim güvenliği, bilgi güvenliği ve siber güvenliktir. Fiziksel olarak saklanan kaset, teyp ve film şeridi gibi bilgilerde fiziksel güvenliği sağlamak yetiyordu. Dijital bilgiyi korumak ise gerçekten zordur. Ne kadar korusanız da farklı noktalarda oluşan kopyaları engelleyemeyebilirsiniz.

### 6.4 Dönüşümün Ayrıntısı ve Gözün Sınırı

Analog bilginin derinliği yüksektir. Dijitale dönüştürürken ne kadar ayrıntıda dönüştürdüğünüze bağlı olarak analog bilginin içeriğini bazen yansıtabilir, bazen yansıtamazsınız. Hocanın örneği televizyon yayınlarıydı. Ultra HD, 4K ve 8K konuşulurken gözümüz bir noktadan sonra aradaki farkı ayırt edecek yeteneğe sahip değildir. Ama standart çözünürlüklü (standard definition) yayınla HD yayın arasındaki farkı görebilirsiniz. Standart çözünürlükteki eski dijital yayınların analog yayına göre farkı da rahatça görülür.

## 7. Analytic Engine'in Birimleri ve İlk Programcı

Hoca 1800'lere dönüp Analytic Engine'in yapısını anlattı. Makinede temelde iki birim vardı:

- **Depolama alanı:** Bilgilerin saklandığı bölge. Henüz sabit disk veya bellek gibi kavramlar yoktu. Bilgiler orada anlık olarak bulunuyor, yeni bir işlem yapıldığında üzerine yazılıyordu.
- **Hesaplama birimi:** Hesaplamaların yapıldığı, hocanın "çark" diye andığı alan.

Bilgiler delikli kartlardan alınıyor, sonuçlar yine delikli kartlarla üretiliyordu. Yıllar geçtikçe bu iki alan bellek birimi (memory unit) ve merkezi işlem birimi (CPU) olarak adlandırılmaya başlandı.

> **Ders sonrası not:** Hoca hesaplama alanına "çark" dedi; Babbage'ın kullandığı terim büyük olasılıkla "mill" (değirmen), depolama alanı için kullandığı terim ise "store"dur.

Bir sistemi tasarlamak ayrı, üzerine program yazmak ayrı bir iştir. Ada Byron, Babbage'ın makinesi üzerine ilk programı yazan kişidir. Hoca bunu 1840'lı yıllara yerleştirdi.

<!-- BELİRSİZ: "1842-1843" aralığı ve "dünyanın ilk programcısı" ifadesi altyazıda söylenmiyor. Kısa nota göre slaytta yazıyor. -->

Hoca burada elektronik ve haberleşme mühendisliği ile bilgisayar mühendisliğinin kesiştiği noktayı gösterdi. Bir taraf cihazları ve devreleri donanım olarak tasarlar. Bilgisayar mühendisliği tarafı ise bu birimleri kullanarak programlar geliştirir ve cihazları akıllı hâle getirir. Bilgisayar mühendisinin önemli amaçlarından biri, donanım yapısını iyi öğrenmek, ona uygun "akıl katan" yazılımlar üretmek, cihazların birbiriyle haberleşmesini sağlamak ve bilgileri saklayacak programlar tasarlamaktır.

## 8. İlk Elektronik Bilgisayarlar ve ENIAC

### 8.1 ABC ve Colossus

1840'lardan yaklaşık 100 yıl sonra, 1940'lı yıllara gelindiğinde, elektriğin de keşfedilmesiyle ilk elektronik bilgisayarla karşılaşıyoruz. Bu, Atanasoff ve Berry tarafından üretilen ABC adlı bilgisayardır. Prototipi 1939'da üretildi. Ardından Iowa State Üniversitesi'nde bir binanın bodrum katını kaplayan bilgisayarla dünya ilk elektronik bilgisayarla tanıştı ve hesaplamalar başladı. Hocaya göre ikincisi, hemen iki yıl sonra hayatımıza giren Colossus Mark I'dir.

> **Ders sonrası not:** Altyazıda ABC'nin üretim yılı 1947 olarak geçiyor; doğrusu büyük olasılıkla kısa notun slayttan aktardığı 1941'dir. Çünkü hoca Colossus Mark I'in "iki sene sonra" geldiğini söyledi ve kısa nota göre slayttaki yıl 1943'tür: $1941 + 2 = 1943$. 1947 alınsaydı 1949 çıkardı.

<!-- BELİRSİZ: ABC'nin üretim yılı altyazıda 1947 geçiyor, kısa notta 1941. Colossus Mark I için 1943 altyazıda söylenmiyor, kısa nottan alındı. -->

Bu tür araştırmaların merkezinde yine askeri uygulamalar vardı. Hoca askeri gereksinimin teknolojiyi ilerlettiğini, yeni teknolojilerin genelde önce askeri uygulamalarla hayatımıza girdiğini söyledi. Fizik alanında da birçok iş yapıldı, ama ilk etapta bu bilgisayarlar ordunun ağır silahları için ateşleme tabloları hesaplamakta kullanıldı. Kâğıt üzerinde uzun süren temel matematik hesaplarının bu cihazlara yaptırılmasıyla ilk programlar hayatımıza girdi.

> **Ek bilgi (derste anlatılmadı):** Hoca 1940'ların elektronik bilgisayarlarının bir amacının Almanya'nın şifreli haberleşmesini kırmak olduğunu donanım bölümünde kısaca söyleyecek. Colossus büyük olasılıkla bu amaçla, İngiltere'de II. Dünya Savaşı sırasında Alman Lorenz şifresini çözmek için geliştirilmiştir. Colossus'un varlığı büyük olasılıkla savaştan sonra uzun yıllar gizli tutulduğu için erken dönem tarih anlatımlarında daha az yer almıştır.

### 8.2 ENIAC

Yine Amerikan ordusu için 1946'da, Electronic Numerical Integrator and Calculator adı verilen ve ENIAC kısaltmasıyla bilinen ilk genel amaçlı bilgisayar üretildi. Slaytta verilen özellikleri şöyleydi:

- **Ağırlık:** 30 ton.
- **Kapladığı alan:** 167 m².
- **Maliyet:** 500 bin dolar.
- **Yaptığı işler:** Matematiksel hesaplar, hava tahmini ve atom enerjisi hesapları. Yani ağırlıklı olarak fizik ve meteorolojiyle ilgili matematik hesapları.
- **Veri girişi:** Delikli kartlar.
- **Programlama:** Kablolar kullanılarak ve anahtarların yerleri değiştirilerek.
- **Hesaplamalardaki veri:** Ondalık (decimal) veri.

> **Ders sonrası not:** Hoca açılımı "Electronic Numerical Integrator and Calculator" olarak verdi; bugün yaygın kullanılan açılım büyük olasılıkla "Electronic Numerical Integrator and Computer"dır.

Programlama bugünkü anlamda bir kod yazma değildi. Fiziksel olarak bir operatör odaya giriyor, hesaplama neyse ona uygun olarak kabloların yerini değiştiriyordu. Bu kadar büyük bir alan yalnız belirli hesapları yapmak üzere programlanıyordu ve bilgisayar o anda belirlenen tek bir problem üzerinde çalışabiliyordu. Aynı anda birden fazla program çalıştırılamıyordu. Program kurulduktan sonra makine belki saatlerce çalışıp sonunda çıktı üretiyordu ve bu sırada makineye müdahale edilemiyordu.

Hoca bu noktada, 1940'a kadar işlerin çok yavaş ilerlediğini, 1940'tan 2020'li yıllara kadar ise gelişmelerin çok hızlandığını söyledi.

## 9. Mainframe'ler

Sonraki süreçte, 1950'ler ile 1970'ler arasında mainframe adı verilen cihazlar üretilmeye başlandı. Hoca, mainframe'lerin bugün hâlâ bankalarda kullanıldığını, bölümün sunucu odasında da bu tür cihazlar bulunduğunu söyledi.

Mainframe'lerin öne çıkan özellikleri şunlardır:

- **Yüksek işlem kapasitesi:** Çok yüksek miktarda işlem yapabilirler.
- **Atomik işlem:** Birbirine bağlı birkaç iş bölünmeden gerçekleştirilir.
- **Büyük donanım:** Normal bir PC'ye göre daha büyük işlemciye, bellek alanına ve soğutma sistemlerine sahiptirler.

Milyon mertebesinde müşterisi olan bankalar düşünüldüğünde bu yapının kaçınılmaz olduğu görülür. Günümüzde daha küçük sunucular da birçok işi görüyor, ama hikâye mainframe'lerle başladı. Ortada kişisel bilgisayarlar yokken, IBM firmasının ürettiği, büyük hesaplamaları yapmak üzere tasarlanmış, sunucu kıvamındaki bilgisayarlarla başlandı.

Slaytta iki mainframe görüntüsü vardı. Soldaki resimde geniş bir alana yayılmış depolama alanları ve işlemci kutuları görülüyordu. Sağdaki resimde operatörün mainframe'i nasıl programladığını gösteren konsol vardı. Bu konsol bir monitörden çok, giriş çıkış noktalarından ve kontrol düğmelerinden ibaretti. Sanal tuşlar yoktu, hatta neredeyse klavye de yoktu. Düğmeler ve kabloların girip çıkabileceği jack noktaları vardı.

Daha sonraki mainframe görüntülerinde şerit hâlindeki yuvarlak teypler görülüyordu. O zaman yedekler (backup) bu teyplere alınıyordu. Hoca bazı noktalarda hâlâ şeritlere yedek alındığını, ama bunun oldukça azaldığını söyledi. Modern bir mainframe ise geniş bir alana yayılmak yerine sunucu kasaları boyutuna gelmiştir.

Mainframe'lerin dikkat çekici bir özelliği de şudur: İçlerinde birden fazla işletim sistemi çalışabilir. Henüz sanallaştırma yokken ve PC'lerde bir bilgisayarda birden fazla işletim sistemi çalıştırılamıyorken, mainframe'ler tek bir fiziksel ortamda farklı işletim sistemlerini destekleyebiliyordu.

<!-- BELİRSİZ: Slayttaki mainframe görselleri yalnız sözlü anlatıldı. 01:43:50-01:43:51 arasındaki altyazı bozuk ("İki aihe"); 1970'lerde mainframe'lerin mi yoksa başka bir gelişmenin mi "sekteye uğradığı" net değil. -->

## 10. Kişisel Bilgisayarlar

1980'den itibaren kişisel bilgisayar (personal computer, PC) dediğimiz yapılar hayatımıza girmeye başladı. Daha önce araştırma çalışmalarındaki ve büyük kurumlardaki problemleri çözmeye yönelik büyük yapılardan söz ediyorduk. Artık kişisel işlerimizi yapmak için bilgisayar üretimi başladı. Mainframe'ler kalmaya devam etse de ve 2020'de hâlâ önemli bir yer kaplasa da, kişisel bilgisayarlar ve akıllı telefonlarla bambaşka bir elektronik cihaz serüveni başladı.

Kişisel bilgisayarların ilk örnekleri 1980'lerden önceye gider:

- **1965, Olivetti:** Hoca ilk kişisel bilgisayarın bu yılda Olivetti tarafından üretilip piyasaya sunulduğunu söyledi. Oldukça ilkeldi, daha çok dört işlem ve çeşitli hesaplamalar yapmayı sağlıyordu. Arka arkaya sayılar yazıldığında sonucu verirdi. Hoca bunu POS cihazlarından önceki, işletmelerin belirli hesaplar için kullandığı çok basit bir hesap makinesine benzetti. Fiyatı 3200 dolardı.
- **1976, Apple:** 666 dolarlık, çok basit bir kişisel bilgisayar tasarımı. Slaytta ekranı ve klavyesi görülüyordu. Çok uzun süre kullanılmadı, işin çok ilkel, ilk zamanlarıydı.

> **Ders sonrası not:** Hoca 1965 Olivetti cihazını ilk kişisel bilgisayar olarak andı; "ilk kişisel bilgisayar" sıfatı büyük olasılıkla tartışmalıdır, çünkü bu cihaz (büyük olasılıkla Programma 101) daha çok programlanabilir masaüstü hesap makinesi olarak tanımlanır.

## 11. Süper Bilgisayarlar ve Paralel İşlem

Sonra süper bilgisayarlar konuşulmaya başlandı. Çok daha fazla işlem gerektiren karmaşık problemleri çözmek için cihazların eş zamanlı ve paralel çalışmasını sağlayan bilgisayar kümeleri oluşturuldu. Hocanın örneği: Bir resmi dört parçaya ayırıp dört parça üzerinde aynı işlemleri paralel olarak yürütebilirsiniz. Aynı anda farklı şarkılar, resimler veya videolar üzerinde de işlem yapabilirsiniz. Fikir şudur: Tek bir CPU kullanmak yerine birden fazla bilgisayar kullanalım ve yapılan işler birbiriyle senkron olsun.

Süper bilgisayarlar ilk etapta, bilgisayarın insana karşı oyun oynama yeteneğini göstermesiyle gündeme geldi. Bu da satrançla oldu. Dünya satranç şampiyonu ilk etapta kazansa da sonraki karşılaşmalarda bilgisayar Kasparov'u yendi. Hocaya göre bunun en önemli sebebi şudur: İşlem gücü arttıkça ileriye dönük hamleleri hesaplayabilirsiniz, insan beyni ise bunu bir yere kadar yapabilir. Satrançta kurallar, alan, hamle sayıları ve taşlar bellidir. Her şey belli olunca olasılıkları hesaplamak mümkün olur. Bilgisayar birçok hamle ileri gidip her hamlenin artılarını ve eksilerini ödül-ceza mantığıyla hesaplar ve hamlesini buna göre yapar.

> **Ders sonrası not:** Hoca bilgisayarın ileriye dönük bütün olasılıkları hesapladığını söyledi; doğrusu büyük olasılıkla satrançta bütün olasılıkların hesaplanamadığı, olasılık sayısı çok büyük olduğu için programların belirli bir derinliğe kadar arama yapıp konumları bir değerlendirme işleviyle puanladığıdır. Kasparov'un büyük olasılıkla bilinen yenilgisi de birçok karşılaşma değil, 1997'de Deep Blue'ya karşı kaybettiği maçtır.

## 12. İnsan ve Bilgisayar Nasıl Karar Verir?

### 12.1 Otonom Araçlar

Bugün olasılıklarını hesaplayamadığımız ya da hesaplamaya uğraştığımız problemler de var. Bunlardan biri otonom araçlardır. Otonom bir araç fiziksel dünyanın birçok değişkenini hesaplayarak karar vermek zorundadır: Trafikteki her sürücünün yapabileceği her hamleyi öngörmeli, karşısına çıkabilecek yayayı veya hayvanı tespit edip ona göre önlem almalıdır. Parametre ve olasılık sayısı çok fazladır. Bu yüzden problem üzerinde hâlâ yoğun biçimde çalışılıyor ve otonom araçlarla ilgili bazı kaza haberleri duyuluyor.

Hocaya göre insan araba kullanırken, özellikle belli bir tecrübesi varsa, bilgisayardan çok daha hızlı tepki verebilir. Örneğin bir insana çarpmakla bir engele çarpmak arasında çok hızlı karar verir. İnsan öldürmenin ya da yaralamanın çok daha kötü sonuç doğurduğunu bilir ve aracını başka bir yere çarparak işi yalnız maddi hasarla atlatabilir.

Hoca farkı şöyle özetledi: Bilgisayarlar bağlam bazında karar vermekte zorlanır. Adım adım karar verir, olasılıkları insanın yapamayacağı hızda hesaplar. İnsan ise geçmiş deneyimlerini kullanan bir karar mekanizmasına sahiptir. Bu bağlam farkındalığı, bilgisayarın hızla karar veremediği birçok problemi insanın çok daha iyi çözmesini sağlar.

> **Hocanın vurgusu:** Bilgisayar kurallar çerçevesinde hesaplama yaparak problem çözer. İnsan beyni ise bağlam farkındalığına sahiptir ve bütün deneyimlerini kullanır. Bu yüzden karmaşık bağlama sahip problemlerde insan, tekrar eden hesaplamaya dayalı işlerde bilgisayar çok daha başarılıdır.

**Soru:** Otonom araç bir manevra yaparken arkada oturan sahibini mi, yoksa yola aniden çıkan çocukları mı kurtarmalı? Burada bir etik tartışma yok mu? **Cevap:** Konu derinleştikçe bu tür maddeleri ve çok daha fazlasını içeriyor. Hayvan mı, insan mı? Hayvanın da canı var. Bir kaza olduğunda suç kimin olacak: Araba üreticisinin mi, yazılımı geliştirenin mi, arabayı satın alanın mı? Bunun hukuki boyutlarının da tanımlanması gerekiyor.

### 12.2 Yapay Zekâ ve Kendini Kodlayan Bilgisayarlar

**Soru:** Bilgisayar kendini kodlamaya başlarsa bizim için bir sıkıntı çıkar mı? **Cevap:** Hoca, Hollywood filmlerinin geleceğin teknolojilerini yıllar öncesinden önümüze sunduğunu, birçok çalışmanın arka planda yürüyüp olgunlaşınca gündeme geldiğini söyledi. Çağrı merkezinin cevapladığı soruları artık yavaş yavaş sohbet robotları (chatbot) cevaplıyor. Siri, Google Voice ve Alexa gibi kişisel asistanlar oluştu. Ama bunların hâlâ sınırı var. Onlar da öğrenmeye devam ediyor.

Hoca bunu insanın öğrenme süreciyle karşılaştırdı. İnsan da uzun bir öğrenme sürecinden gelir. 10'lu yaşlardan itibaren daha iyi kararlar vermeye başlarız. Karar verme yaşını 18 sayarsak arkada 18 yıllık bir bilgi birikimi ve yaşanmışlık vardır. Bebekler de ilk 2-3 yaşa kadar çok ciddi bir özümseme yapar. Bilgisayarlara da bilgi yüklemesi yapılarak benzer bir süreç yürütülüyor, sohbet robotları konuşma diyaloglarından öğreniyor.

Bilgisayarların kendi kendini programlamasına gelince, hoca bunun eninde sonunda olacağını, hâlihazırda örneklerinin de bulunduğunu söyledi. Ama bu işin öngörüldüğü kadar hızlı olmayacağını düşünüyor. Otonom araçların 2025-2030'lu yıllarda ciddi biçimde sahada olacağı söyleniyor, ama regülasyonlar henüz hazır değil. Elektrikli araçlar bile düşünüldüğü kadar hızlı yaygınlaşmadı. Hoca bu öngörülerde iddialı olmamak gerektiğini de ekledi.

Hoca, COVID sürecinde de genetik haritalar için süper bilgisayarlar kullanıldığını örnek verdi: virüsün mutasyonu ve geliştirilen aşının genetik dizilime verdiği tepki gibi konular bu güçle incelenebiliyor. Ama günün sonunda insan üzerindeki, müdahale edemediğiniz tepkiyi gözlemlemek zorundasınız. Üç fazı ve belirli sayıda deneği geçmek gerekir, bu kadar işlem gücüne rağmen.

Robotlar konusunda hoca, Japonların öncüler arasında olduğunu ve birçok robot yarışması düzenlendiğini söyledi. Çok ilerleme var, ama birçok yeni sorun da çıkıyor. İnsani duygular ve insanla ilgili bazı bilgiler hâlâ çözülemediği için teknolojinin bir yere kadar gireceğini ve zamana yayılarak hayatımıza gireceğini öngörüyor.

**Soru:** Etik kavramı bilgisayarlara yüklenebilecek bir özellik mi? **Cevap:** Hoca bunun çok zor bir soru olduğunu söyledi. Kurallar bazında etik tanımlanabilir ve öğretilebilir, zaman içinde öğrenilebilir de. Ama bu yine ayrık (discrete) bir yapıdır: "Bu böyleyken bu böyle." İnsandaki etik ise hormonlardan ve duygulardan etkilenir. Şu anki bilgisayarların insan kadar karmaşık bir yapıda karar verip veremeyeceğini zaman gösterecek. İnsanın duygularını modellemeye çalışan araştırmalar ve yeni konferanslar var. Ses tonundan, bakıştan, görüntüden, yürüyüşten, el kol hareketlerinden analiz yapılıyor; kişinin o gün yorgun mu, enerjik mi olduğu anlaşılmaya çalışılıyor. Üretilecek robotların duygulara sahip olmasının istendiği konuşuluyor.

**Soru:** Bilgisayarlar kendi kendini kodlamayı öğrenirse bilgisayar mühendisleri işsiz kalır mı? **Cevap:** Hoca bunun normal şartlarda meslek hayatı boyunca karşılaşılacak bir problem olduğunu düşünmüyor. Öngörüsü, bilgisayarların çok iyi karar destek sistemleri olduğu yönünde: kararlarımıza destek olur, göremediğimiz örüntüleri (pattern) gösterirler.

Bunu hava tahminiyle örneklendirdi. O gün için görülen ciddi yağış o anda gerçekleşmemişti. Modellerin hepsi bilgisayarlarla hesaplanıyor, ama iki meteoroloji uzmanı aynı çıktılara bakıp farklı yorum yapabiliyor. Biri bu kadar kar yağmayacak diyor, diğeri yarın 10 santim kar bekliyoruz diyor. Günün sonunda birinin deneyimi öne çıkıyor ve yine insani bir karar mekanizması daha iyi tahminde bulunuyor.

Bu yüzden otomatik kod yazma mekanizmaları geliştirilse bile hoca, bilgisayarların her zaman çok iyi bir "ikinci başkan" olacağını, şirketin başında ise insanın bulunacağını düşünüyor. Bunun yorumuna hafif bir öznellik katmış olabileceğini de kabul etti.

Bir öğrenci de insan ve makinenin çok iyi bir ikili olacağını, makinelerin fiziksel ölçümleri de hesaba katarak çok daha hızlı ve kaliteli karar verebileceğini söyledi. Hoca insan ömrünün uzamasına değindi: Teknolojinin tıbba girmesiyle, biyoinformatik ve biyomühendislikteki gelişmelerle, hastalıklar önceden görülüp tedavi edildikçe yaşam muhtemelen uzayacak. Yine de çok yakın zamanda beklenen gelişmelerin hep ertelendiğini görüyoruz. Google Glass bunun güzel bir örneğidir: Çok büyük projeler vardı, ama proje kapandı. Bazı teknolojiler o dönemde insana oturmuyor. Buna karşılık giyilebilir teknolojilerin en güzel örneği olan akıllı saat çok yaygınlaştı. Giysilere girmesi konuşuluyor, ama sağlık sorunları nedeniyle bu henüz yaygınlaşmadı.

Hoca bu noktada bilgisayar mühendisliği mezunlarının çok farklı alanlarda çalışma potansiyeline sahip olduğunu, her geçen gün yeni bir alanın doğduğunu söyledi.

### 12.3 Analog Bir Makine Olarak İnsan

İnsanların etiği bile aynı değildir. Herkes ailesinden gördüğünü hayata uygular, bazen kötü kararlar da alırız. Hocaya göre sonuçta bizim çalışma sistemimiz de bir algoritmaya dayalıdır. Çözülemese de müthiş bir sistemdir. Verdiğimiz kararlar içimizde gerçekleşen hormonal, biyolojik ve kimyasal tepkimelerin sonucudur. Hocanın ifadesiyle eşsiz bir makineyiz, dijital değil analog bir makineyiz. Henüz bu çözünürlükte bir karar mekanizması kurulabilmiş değil.

**Soru:** Yapay sinir ağlarında öğrenme beyne, nöronlara benzetiliyor. Nöronlar birbiriyle iletişim kuruyor. O hâlde biz de dijital çalışmıyor muyuz? **Cevap:** Hoca bunun böyle yorumlanamayacağını söyledi. Beynin yapısı incelendikçe dendritler ve nöronlar görüldü. Bunlar sinir ağlarını oluşturuyor ve iletim bu ağlar üzerinden yapılıyor. Ardından kısaca analog-dijital ayrımına geri döndü: "Bizden bir tane daha kopyalayabiliyor musunuz?" Cevap hayırdır. Yani dijital bilginin kolay kopyalanması insanda geçerli değildir.

<!-- BELİRSİZ: Sorudaki "Nöronlar birbirine eğitirse iletişim kuruyor" ifadesi altyazıda bozuk; büyük olasılıkla "elektrikle". Soru buna göre genel ifadeyle yazıldı. 02:11:32-02:12:02 arasında kayıtta boşluk var. -->

## 13. Teknolojiyi Sorumlulukla Kullanmak

Kopyalama konusu hocayı genetik kopyalamaya getirdi. Bir hayvanın kopyalanması örneğini anıp bunun çok tehlikeli bir alan olduğunu söyledi. Atom bombası da bomba olarak bulunmadı, iş atomlardan enerji üretme fikriyle başladı, ama felaket bir senaryo gerçekleşti.

<!-- BELİRSİZ: Altyazıda bozuk bir ad var ("Don'iydi galiba"); büyük olasılıkla klonlanan koyun Dolly kastediliyor. Metinde ad verilmedi. -->

> **Hocanın vurgusu:** Her keşfin müthiş bir potansiyel tehlikesi vardır. Teknoloji ilerlerken bu tehlikeyi de içinde barındırır. İnsanlığın yararına gelişmelere imza atarken insani duyguları hiç kaybetmeden karar almak gerekir.

Hoca bunu çevreyle bağladı. Teknolojik çöplük yaratmak bugün insanoğlunun en büyük problemlerinden biridir, büyük bir çevre kirliliği oluşuyor. Geri dönüştürülebilir malzeme kullanmak çok önemlidir ve şirketler artık buna dikkat ediyor. Mesleki kariyerde alınan kararlarda dünya düzeni gözetilmelidir. Değişim kaçınılmazdır, onun parçası olmaktan korkmamak ve adapte olmak gerekir, ama iyi değerleri koruyarak.

Hoca doğaya verilen zararı koronavirüsün ortaya çıkış biçimiyle de örnekledi: Hayvanların barındığı alanlar deşiliyor, hayvanlar habitatlarından çıkıyor, virüsler bir hayvanda bir araya gelip mutasyona uğruyor ve insana geçiyor. Bunun sinyali daha önce SARS ve MERS ile gelmişti. Son benzer büyük olay, hocanın "İspanyol virüsü" diye andığı, yaklaşık 100 yıl önceki salgındı. Teknolojiyi çok etkin kullansak da aşı sürecinde belli adımlar hızlandırılamıyor, çünkü vücuttaki ve hayvandaki tepkiyi belli bir süre görmek gerekiyor. Bu da insanın bazı noktalarda doğanın yarattığı problemler karşısında hâlâ çaresiz olduğunu gösteriyor.

> **Ders sonrası not:** Hoca SARS için 2000, MERS için 2010 yılını söyledi; doğrusu büyük olasılıkla SARS için 2002-2003, MERS için 2012'dir.

Öte yandan teknoloji büyük korumalar da sağlıyor. Hocanın örneği Japonya'dır: Depreme karşı yıllar boyunca geliştirilen çözümlerle birçok bina 9 şiddetindeki depremde ayakta kalabiliyor. Hoca bunun bilgisayarla değil, makine, inşaat ve malzeme mühendisliğiyle ilgili olduğunu belirtip disiplinler arası çalışmanın önemini vurguladı. Buna rağmen en acı nokta reaktörde yaşandı ve bir kaçak oldu. Yani hem insan hayatını koruyabiliyoruz, hem de bazı konularda hâlâ çaresiziz.

Hoca sözünü, daha iyi bir hayatın yolunun doğaya ve insana saygı duymaktan, teknolojiyi insanın yararına kullanmaktan geçtiğini söyleyerek bağladı. Son bölümün başında da aynı noktaya döndü: İnsan bazen başına dert açan bir icat yapar, önemli olan o icadı nasıl kullandığıdır.

## 14. Sanallaştırma

Hoca süper bilgisayarların katkılarından birinin kişisel bilgisayarlarımıza kadar geldiğini söyledi: sanallaştırma (virtualization). Boşta duran CPU'yu, boşta duran bellek alanını ve ağ bant genişliğini kullanmanın en iyi yolu, fiziksel sunucuları üst üste koymak değildir. Yeteneği çok olan, ama bu yeteneği çok az kullanılan sunucuları veya kişisel bilgisayarları daha fazla çalıştırmaktır. Bunu yapmanın en güzel yolu sanallaştırmadır. Buna ek olarak paralel işlem yeteneği de işleri hızlandırmanın yollarından biridir.

## 15. Bilgisayar Mühendisliği Eğitimi ve Programlama Dilleri

Hoca, bilgisayar mühendisinin çözmesi gereken çok fazla problem olduğunu, her geçen gün yenilerinin çıktığını, bu yüzden değişime ayak uydurmak ve geleceğe dönük konularda kendini geliştirmek gerektiğini söyledi.

Derslerde kullanılan bazı teknolojiler ve diller eski görünebilir, ama bunlar işin temelini anlatmak için kullanılır. Hedef, öğrencinin sektöre çıkınca işe yarayacak belirli bir dili öğrenmesi değildir. Hedef, şunları kavramış ve bunlar üzerinde karar verebilen mezunlar yetiştirmektir:

- Bilgisayarın programlama mantığı, birimleri ve çalışma prensibi.
- Bilgisayarların birbiriyle haberleşmesi ve karar verme mekanizması.
- Gömülü sistemler ve elektronik cihazların işletim sistemiyle nasıl çalıştığı.
- İşletim sisteminin neden önemli olduğu ve IoT cihazları için yeni bir işletim sistemi gerekirse nasıl bir yapı kurulacağı.

Güncellik önemlidir, ama programlama dili anlamında en günceli yakalamak zaten çok zordur. Hoca o dönemde Go ve Rust dillerinin çok talep gördüğünü, mobil programlamada da Kotlin'in çıktığını söyledi. Dünyada yaklaşık 600 programlama dili varmış, aktif olarak kullanılanlar 30-40 kadardır. İlk 20 sıralamasında eski ve yeni nesil diller birlikte yer alır, her biri farklı amaçlara hizmet eder. Bölümde görülecek diller şunlardır: "ata dil" olarak C, nesneye yönelik programlamayı iyi ve basit anlatmak için Java, günümüzde veri bilimi için kullanılan Python. Projelerde başka diller de kullanılacaktır.

## 16. von Neumann Mimarisi

Bilgisayar mimarisi en basit hâliyle von Neumann mimarisi olarak ifade edilir. Hocanın sorusu şuydu: Bir bilgisayardan söz edebilmek için olmazsa olmaz birimler nelerdir?

- **Giriş birimi (input device):** Veriyi dışarıdan alır.
- **Bellek:** Veriyi saklar. Burada ikincil bellekten, yani sabit diskten söz edilmiyor. Basit mekanizmada veri alındıktan sonra geçici olarak saklanır.
- **Merkezi işlem birimi (Central Processing Unit, CPU):** Veriyi işler. İki birimden oluşur:
  - Aritmetik ve mantık işlemlerini yapan birim.
  - Yapılacak işlerin kontrol adımlarını gerçekleştiren kontrol birimi.
- **Çıkış birimi (output device):** Sonucu dışarıya aktarır.

Bugün mimari içinde çok daha fazla birim kullanılıyor, ama günümüz bilgisayar mimarisinin temeli bu bakış açısıyla atıldı. Mantık basittir: Veriyi işleyecek, veriyi saklayacak, veriyi dışarıdan alacak ve sonucu dışarıya gösterecek birimlere ihtiyacımız vardır. Bunlar olduğu takdirde diğer birimler temel açıdan o kadar kritik değildir.

Bu mimarinin iki özelliği daha vurgulandı. Birincisi, hem programın hem de işlenecek verinin bulunduğu tek bir bellek mekanizması kullanılır. İkincisi, yapı ikili veri mantığıyla çalışır.

<!-- BELİRSİZ: Slayttaki mimari şeması altyazıda yalnız sözlü anlatıldı. Kısa nota göre slaytta giriş/çıkış, bellek ve aritmetik birimin merkezi işlem birimi tarafından yönetildiği de yazıyor. -->

> **Ek bilgi (derste anlatılmadı):** Programın veriyle aynı bellekte durması, büyük olasılıkla ENIAC'ta anlatılan kablo değiştirerek programlamadan en önemli farktır. Bu "depolanmış program" fikrinde program değiştirmek için büyük olasılıkla fiziksel kablolama yerine bellekteki içeriği değiştirmek yeterlidir. Mimari, adını büyük olasılıkla John von Neumann'ın 1945 tarihli EDVAC raporundan alır.

### 16.1 Kuantum Bilgisayarlar

Hoca yeni bilgisayar türlerinin ileride bu yaklaşımın önüne geçebileceğini söyledi. Kuantum bilgisayarlarda bir veri belirli bir durumda (state) ve aynı anda iki durumda bulunabilir. Bizim bilgisayarlarımızda ise veri belirli bir durumdadır: var ya da yok. Kuantum bilgisayarlar henüz olgunlaşmış değil, ama önümüzdeki on yıllarda gelişme bekleniyor.

<!-- BELİRSİZ: 02:30:34'te altyazı "nano bilgisayarları konuşuyoruz" diyor; nano mu yoksa başka bir kelime mi olduğu net değil, bu yüzden metne alınmadı. -->

> **Ek bilgi (derste anlatılmadı):** Kuantum bilgisayarlarda bilgi birimine büyük olasılıkla kübit (qubit), aynı anda birden fazla durumda bulunma özelliğine de süperpozisyon denir. Ölçüm yapıldığında kübit büyük olasılıkla tek bir duruma, 0 ya da 1'e iner.

## 17. Bilgisayar Organizasyonu: Donanım

Bilgisayar organizasyonu denince iki başlık gündeme gelir: donanım ve yazılım. Donanım bilgisayarın fiziksel birimleridir: monitör, klavye ve fare gibi giriş çıkış aygıtları, içindeki entegre devreler ve kartlar.

### 17.1 Kartlar ve GPU

Artık genelde entegre devrelerden söz ediyoruz. Ana kart üzerine birçok şey gömülüyor ve kart sayıları oldukça azaldı. Ama daha fazla ve daha sofistike iş için tasarlanan kartlar hâlâ vardır. Bunun örneği GPU'dur. Standart bir GPU ana kart üzerinde olabilirken, çok daha yetenekli bir GPU ayrı bir kart olarak tasarlanıp PC'de bir slota takılır. Dizüstü bilgisayarlarda ise birimler genelde tek bir kart üzerine entegre devreler yerleştirilerek gerçeklenir. Daha yüksek işlem kapasitesi istendiğinde masaüstü bilgisayarlara veya sunuculara yeni donanım eklenir.

### 17.2 Donanım mı, Yazılım mı? Şifreleme Örneği

Hoca bir soruyla özel donanım konusunu açtı. Önce şifrelemenin önemine değindi. 1940'ların elektronik bilgisayarlarının bir amacı da Almanya'nın şifreli haberleşmesini kırmaktı ve bununla ilgili filmler de vardır.

**Soru:** Şifreleme algoritmalarını yazılımla gerçekleyen çözümler de, donanımla gerçekleyen çözümler de var. Hangisi daha verimlidir ve tercih edilmelidir? **Cevap:** Öğrenciler donanımsal şifrelemenin daha iyi olduğunu, çünkü yazılıma uzaktan erişilebilirken donanım için yakın erişim gerektiğini söyledi. Hoca bu erişim yorumunu kısmen doğru buldu ve cevabı şöyle kurdu:

Donanımsal şifreleme, şifreleme mekanizmasını donanım olarak gerçeklemek demektir. Ancak tasarlanan bu birimi de sonunda mutlaka bir yazılımla desteklemek gerekir. Yazılımsal çözümler ise standart bir CPU üzerinde çalışır, gerekirse GPU ile desteklenir. Bankalarda özellikle kullanılan HSM (Hardware Security Module) ise bilgisayara ek olarak kullanılan, tamamen şifreleme ve şifre çözme işini yapan özel bir donanımdır. Hoca bunun iki avantajını saydı:

- **Daha güvenli:** Standart bir mimari kullanılmadığı için uzaktan erişmek ve mekanizmayı anlamak daha zordur.
- **Daha hızlı:** Bir iş için üretilen donanım, standart donanımdaki yazılım çözümünden özel durumlar dışında her zaman daha hızlı ve verimlidir. Hocaya göre en önemli fark budur.

> **Ders sonrası not:** Hoca HSM'nin güvenliğini standart mimari kullanmamaya bağladı; doğrusu büyük olasılıkla HSM güvenliğinin asıl dayanağının gizli anahtarları cihaz dışına çıkarmaması ve fiziksel müdahaleye karşı dayanıklı tasarımı olduğudur. Mimarinin bilinmemesi büyük olasılıkla tek başına yeterli bir güvenlik gerekçesi sayılmaz.

### 17.3 iOS ve Android

Hocanın bu ilke için verdiği en güzel örnek telefon işletim sistemleriydi. Android, birçok farklı donanımda çalışmak üzere tasarlanmıştır. iOS ise belirli donanımlar için tasarlanmıştır. Bu nedenle iOS, birçok noktada daha az yetenekli donanımla daha iyi performans verir, çünkü yazılım bu donanım baz alınarak geliştirilmiştir. Android tarafında Samsung, Huawei, Xiaomi ve Oppo gibi üreticilerin cihazları arasında farklılıklar vardır. Hepsinde çalışması istenen bir yazılım üretildiğinde özelleştirme gerekir, bu yüzden güncellemeler geç gelir. Hoca "örnek veriyorum" diyerek, iOS'taki 4 GB RAM performansının Android tarafında ancak 8 GB ile alınabildiğini söyledi. İşlemci hızlarında da benzer bir durum görülür: Android cihazda daha yüksek işlemci hızı, aynı performansı verir.

> **Hocanın vurgusu:** Buradan şu sonuca varmalısınız: Donanım tasarlanabiliyorsa, yapmak istediğiniz iş için özel bir donanım kullanmak işi hızlandırır ve daha güvenli bir çözüm üretir.

### 17.4 Donanım Birimleri

Donanım başlığı altında şunlar yer alır:

- CPU ve bellek (birinci bellek).
- İkinci bellek: sabit disk, SSD diskler ve harici diskler. CD-ROM ve DVD-ROM artık çok yaygın değil, ama hâlâ var.
- Kablolar: Bilgi bunlar üzerinden aktarılır.
- Kablosuz modüller: Bilginin kablosuz aktarılmasını sağlar.
- Dokunmatik ekranlar, mikrofon ve kamera.

Hoca, imkân varsa özellikle bir masaüstü bilgisayarı açıp içine bakmayı, devrenin neye benzediğini görmeyi, hangi slotlar bulunduğunu ve hangi birimlerin eklenebileceğini öğrenmeyi tavsiye etti.

## 18. Yazılım ve İşletim Sistemi

Yazılım tarafında, bilgisayarın donanımını kullanmak için ürettiğimiz kodlardan söz ediyoruz. Firmware'ler ve sürücüler (driver) alt seviyede işletim sistemiyle cihazların uyumlu çalışmasını sağlar.

### 18.1 İşletim Sistemi Nedir?

**Soru:** İşletim sistemi nedir? **Cevap:** Öğrencilerden şu tanımlar geldi:

- Donanımı kontrol eden program.
- İnsanın anlayamayacağı makineyi insanın anlayabileceği bir arayüze veya dile çeviren, makineyle insanın anlaşmasını sağlayan program.
- Girdileri donanıma gönderip çıktı vermesini sağlayan yazılım.
- Donanımı, kullanıcıyı ve programları bağlayan bir arayüz.
- Yazılım ile donanım arasındaki bağlantıyı, haberleşmeyi ve yönetimi sağlayan yapı.
- Bilgisayarla çalışan bütün donanım birimlerinin ve yazılımların yönetimini sağlayan, bilgisayarın daha kolay kullanımını sağlayan yazılım.

Hoca bunların çoğunun tanıma katkı sağladığını, kullanıcı ile donanım arasında köprü olma yorumunun da yanlış olmadığını söyledi. Son tanım daha toparlayıcıydı. Hocanın verdiği kaba tanım şudur:

> **Hocanın vurgusu:** İşletim sistemi, bilgisayarın kaynak yönetimini yapan sistem yazılımıdır. Kaynak yönetiminden sorumlu olduğu ısrarla vurgulanmalıdır.

Kaynak yönetimi, CPU'nun, belleğin ve giriş çıkış birimlerinin kullanımının, yani bütün birimlerin yönetilmesi demektir. İşletim sistemi bu birimleri kullanmamız için bir arayüz de sunar.

### 18.2 Grafik Arayüz ve Komut Satırı

Bugün her işletim sistemi grafik kullanıcı arayüzü (graphical user interface, GUI) sunsa da eskiden bazıları sunmuyordu. MS-DOS bunun geçmişte kalmış bir örneğidir. Hâlihazırda bazı işletim sistemlerini komut satırından, komutlarla yönetebiliyoruz, yani GUI'ye mutlaka ihtiyaç duymuyoruz. Özellikle sunucularda performansı artırmak için GUI paketi kurulmaz, yönetim terminal ekranından komutlarla yapılır.

### 18.3 Yazılımın Parçaları

Yazılım; sistem yazılımlarını, framework'leri ve kullanıcıların yazdığı programları içerir. Sistem yazılımlarının başında işletim sistemi gelir. Yazılım başlığı altında donanımı kullanabileceğimiz programlar geliştiririz. Ayrıntıları ileride görülecek.

## 19. Bellek Türleri, Giriş ve Çıkış Birimleri, Sensörler

Bilgisayar donanımının temel birimleri merkezi işlem birimi (central processing unit), ana bellek (main memory) ve ikincil bellektir (secondary storage).

### 19.1 Ana Bellek ve İkincil Bellek

**Soru:** Ana bellek ile ikincil bellek arasındaki fark nedir? **Cevap:** Bir öğrenci ana belleğin daha az depolama alanına sahip ve daha hızlı, ikincil belleğin ise daha fazla depolama alanına sahip ve daha yavaş olduğunu söyledi. Hoca bunun doğru olduğunu, ama asıl farkı veren başka bir bilgi olduğunu belirtti.

> **Hocanın vurgusu:** Temel fark şudur: Elektriği kestiğiniz anda bilgiyi kaybediyorsanız ana bellekten, kaybetmiyorsanız ikincil bellekten söz ediyoruz.

CPU'nun da belleği vardır. CPU'nun içinde register ve cache bulunur. Bunlar ve main memory elektrik olduğu sürece çalışır. Sabit disk, USB bellek, CD-ROM ve DVD-ROM gibi depolama birimleri ise bilgisayarı kapatsanız da bilgiyi saklar ve kaldığınız yerden devam edebilirsiniz.

> **Ek bilgi (derste anlatılmadı):** Elektrik kesilince içeriği silinen belleklere büyük olasılıkla uçucu (volatile), içeriğini koruyanlara kalıcı (non-volatile) bellek denir. Hocanın ayrımı büyük olasılıkla bu terimlere karşılık gelir. Ana bellek denince günlük kullanımda büyük olasılıkla RAM kastedilir.

### 19.2 Giriş Birimleri

Giriş birimleri, bilgisayara bilgi aktarabildiğiniz birimlerdir: mikrofon, klavye, fare, tarayıcı (scanner), kamera ve dokunmatik ekran. Her elektronik cihaz için bunlar farklı olabilir.

> **Hocanın vurgusu:** Giriş birimleri sayılırken mikrofon ve kamerayı unutmamakta fayda var. Özellikle telefonlarda bunları çok sık kullanıyoruz.

Yazıcı bir giriş birimi midir? Genellikle değildir, çıkış birimidir. Ama yazıcıyı tarayıcı olarak kullanıyorsanız o zaman giriş birimi olarak kullanıyorsunuz.

### 19.3 Çıkış Birimleri

Çıkış birimleri sonucu bize iletir: hoparlör, kulaklık, ekran, yazıcı, projektör ve telefonlarda renkli bildirim yapan LED'ler. Hoca bu birimleri insanın beş duyusuna benzetti. Bilgisayarın dışarıyla haberleşmesini sağlayan bu birimler daha çok görme, dokunma ve duyma duygularını kullanır.

### 19.4 Sensörler

Yeni elektronik cihazlarda çok daha fazlası vardır. Hoca, beş duyu organımızı temsil eden bu birimlere genel olarak ne denildiğini sordu ve cevabı verdi: sensör. Sensörler, tıpkı bizim beş duyu üzerinden dış dünyayla haberleşmemiz gibi, elektronik cihazın dış dünyayla etkileşimini sağlar. GPS, jiroskop ve ivmeölçer (accelerometer) bunlara örnektir.

Sensörler özellikle telefonlarla gündeme geldi. Dizüstü bilgisayarlarda bu çeşitlilikte sensör yoktur. Temel bir bilgisayarda bu sensörlerin hepsi bulunmaz, ama telefonu bir cep bilgisayarı olarak düşünürsek akıllı telefon donanımında çok daha fazlasını buluruz. Bu sayede elektronik cihazlar dış dünyayla çok daha fazla etkileşim içindedir ve giriş çıkış birimleri çok önem kazanmıştır. Hocanın sonucu şuydu: Bilgisayarlara artık yalnız temel birimler olarak bakmamak, elektronik cihazların sahip olduğu birimleri de iyi öğrenmek gerekir.

## Dersin Toparlaması

Bu derste önce dersin kapsamı ve hedefi görüldü: Dönem sonunda bir problemi anlayıp sınırlarını belirlemek, algoritmasını tasarlamak, analiz etmek ve kodunu yazmak. Ardından bilgisayar biliminin hedefinin insan işlerini otomatikleştirmek olduğu anlatıldı ve abaküsten Babbage'ın mekanik makinelerine, Ada Byron'ın ilk programına, ABC, Colossus ve ENIAC'a, mainframe'lere, kişisel bilgisayarlara ve süper bilgisayarlara uzanan tarihçe izlendi. Bu akış içinde analog ile dijital verinin farkı, bilgisayarın insan karşısındaki güçlü ve zayıf yanları ve mühendisin teknolojiyi kullanma sorumluluğu tartışıldı.

Dersin son bölümünde von Neumann mimarisinin temel birimleri, donanım ve yazılım ayrımı, özel donanımın genel amaçlı donanıma üstünlüğü, işletim sisteminin kaynak yönetimi rolü, bellek türleri, giriş ve çıkış birimleri ile sensörler ele alındı. Hoca bilgisayarın birimlerinde kalındığını, sonraki derste bu konuların sürdürüleceğini ve ardından dersin teorik konularına geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
