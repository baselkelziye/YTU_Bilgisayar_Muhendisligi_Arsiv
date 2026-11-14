# Ders 1 Genişletilmiş Notu: Tanışma: Dersin Müfredattaki Yeri, Algoritma Öğrenmek ve Programlama Ortamı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. İlk Dersin Amacı
- 2. Dersin Müfredattaki Yeri
- 3. Bilgiye Birinci Elden Ulaşmak
- 4. Algoritma Bu İşin Temelidir
- 5. Etkileşimli Ders Ne Demektir?
- 6. Bu Ders Nasıl Çalışılır?
- 7. Not Tutmak ve Kodu Kendin Yazmak
- 8. Programlama Ortamı ve C Standardı
- 9. Kitaplar ve Diğer Kaynaklar
- 10. Bilgisayar Bilimlerine Giriş Dersini Almamış Olanlar
- 11. C Bilgisi Azsa Ne Yapmalı?
- 12. Hangi C Derleyicisi İndirilmeli?

## 1. İlk Dersin Amacı

Bu ders, dönemin ilk buluşmasıdır ve bir tanışma dersi olarak yapıldı. Normalde bu saatler laboratuvar saatidir. Hoca, teoride bir şey görmeden laboratuvar yapmanın pek anlamı olmadığını, bu yüzden tanışma görüşmesini bu saate aldığını söyledi. Bu derste yapısal programlama konularına geçilmedi. Dersin içeriği bir sonraki derste tanıtılacak. Bu derste dersin öncesi ve sonrası, yani müfredattaki yeri ve dersten nasıl verim alınacağı konuşuldu.

Dersin adı Yapısal Programlamaya Giriş'tir (BLM1012). Dersin eski adı Bilgisayar Bilimlerine Giriş 2'ydi. Hoca bölümde yaklaşık 8 yıldır çalıştığını, 2013'ten beri bu dersin laboratuvar uygulamalarına yardımcı olduğunu ve dersi teorik tarafıyla ilk kez resmi olarak verdiğini söyledi.

## 2. Dersin Müfredattaki Yeri

Bilgisayar Mühendisliği lisans programındaki derslerin bilgilerine Bolonya sayfasından ulaşılır. Hocanın gösterdiği program 2018'de oluşturulmuş yeni programdır. Hocaya göre bu programın da güncellenmesi gerekir, ama şu an takip edilen müfredat budur. BLM1012, birinci dönemde görülen Bilgisayar Bilimlerine Giriş (BLM1011) dersinin devamı niteliğindedir.

Hoca burada dersin içeriğinden çok şu soru üzerinde durdu: Bu ders kariyerimizde nereye oturuyor, neler açısından önemli?

### 2.1 Önceki Dönemde Ne Görüldü?

Birinci sınıfa gelen bir öğrenci lisede bilgisayarla belki en fazla oyun oynamış, Word'de ya da Excel'de ödev hazırlamış, internete girmiştir. Birinci dönemle birlikte bilgisayara bir bilgisayar mühendisi gözüyle bakmayı sağlayan bilgi ve beceriler edinilmeye başlanır.

BLM1011'de şu sorulara cevap arandı: Bilgisayar nedir? Bilgisayar sisteminin temel bileşenleri nelerdir? Bilgisayar sistemi nasıl çalışır? Niçin bilgisayar kullanırız? Hocanın tahminine göre 5. ve 6. haftadan sonra akış diyagramları (flowchart), algoritmalar ve C programlamaya giriş geldi.

Bu konular kimine çok kolay, kimine zor geldi. Hoca, birçok öğrencinin dersi üniversite sınavından kalan alışkanlıkla çalıştığını, bu çalışmanın da pek işe yaramadığını söyledi. Üniversite sınavı mantığında çeşitli soru tipleri görülür ve test çözülür. Burada ise hoca, öğrencinin daha önce görmediğini düşündüğü bir soru sorar. "Daha önce hiç böyle bir soru çözmedik" tepkisi hocaya göre normaldir, çünkü bu bir mesleğin ilk adımıdır.

### 2.2 Bu Dersin Amacı

Yapısal Programlamaya Giriş, geçen dönem edinilen altyapıyı alıp algoritma geliştirmeyi daha ileri bir noktaya taşıyan bir derstir. Dersin adından da anlaşılacağı gibi ana tema yine programlamadır, algoritma geliştirme programlamayla desteklenir. Derste, nasıl daha çözüme odaklı düşünüleceği ve nasıl daha iyi algoritmalar geliştirileceği üzerine bilgi ve beceri kazanılır.

> **Ek bilgi (derste anlatılmadı):** Bu derste "yapısal programlama" teriminin tanımı yapılmadı. Terim büyük olasılıkla, programı sıra, seçim ve döngü gibi temel denetim yapılarıyla ve fonksiyonlara bölerek yazma yaklaşımını anlatır. C bu yaklaşımla kod yazmaya büyük olasılıkla uygun bir dildir. Dersin kendi tanımı için dersin ilerleyen kısımlarına bakın.

### 2.3 Bu Ders Hangi Derslere Temel Oluşturuyor?

Hoca dersin etkisini üç aşamada anlattı. Birinci aşama hemen sonraki dönemdir, yani ikinci yılın güz yarıyılı:

- Yapısal Programlama
- Alt Seviye Programlama
- Ayrık Matematik
- Sinyaller ve Sistemler (bilgisayar mühendisleri için verilen ders)

Bu derslerin altyapısı burada oluşur. Hoca, kendi kanaatine göre gelecek dönemki Yapısal Programlama dersinin içeriğinin bu dönem de verilebileceğini, ama müfredatın daha sade gitmesi ve öğrene öğrene ilerlenmesi için böyle düzenlendiğini söyledi.

İkinci aşama ikinci yılın bahar yarıyılıdır. Bu derslerde doğrudan bu dersin üzerine bir şeyler koyulur:

- Nesne Yönelimli Programlama
- Sistem Analizi ve Tasarımı
- Veri Yapıları ve Algoritmalar

Üçüncü aşamada ise daha sonraki dersler vardır: Algoritma Analizi, İşletim Sistemleri, Veri Tabanı Yönetimi ve üçüncü sınıfta Mikroişlemciler. Hoca özellikle Algoritma Analizi'ni vurguladı. Burada anlatılan C konuları Algoritma Analizi'nde de, Veri Yapıları'nda da gerekir, İşletim Sistemleri'nde zaten gereklidir. Yani bu derslerin hepsinin temeli birinci sınıf derslerinde atılır.

Hoca dersi, birinci dönemle üçüncü ve dördüncü dönemler arasında bağlantı kuran bir "dolgu" gibi düşünmeyi önerdi. Temelin birkaç derse bölünmüş olmasının da bir avantajı vardır: Bir derste ya da bir hocadan anlaşılmayan bir konu, bir başkasından daha iyi anlaşılabilir. Geçen dönem Bilgisayar Bilimlerine Giriş'te büyük bir eksiği olmayan biri için bu dersi geçmek hocaya göre kolaydır. Eksiği olanlar da bu dönem eksiklerini rahatça kapatabilir.

### 2.4 Ön Koşul Yok

Hocanın bildiği kadarıyla dersin ön koşulu yoktur. Bu yüzden ders, geçen dönem Bilgisayar Bilimlerine Giriş'i almamış olanlar, başka bir bölümden yatay ya da dikey geçişle gelenler ve yapısal programlamayla, C programlamayla ilk kez burada tanışacak olanlar için de önemlidir. Bu konuya hoca dersin sonunda yeniden döndü (Bölüm 10).

### 2.5 Farklı Hoca, Farklı Bakış Açısı

Ders bir de farklı bir bakış açısı sağlar. İlk dönem dersine giren hocalardan farklı bir kadro vardır. Soru stilleri ve dersteki bakış açıları farklı olabilir. Hoca yıllardır birlikte çalışsalar da "her yiğidin yoğurt yiyişi farklıdır" diyerek bunun bir zenginlik olduğunu söyledi.

Hoca bununla da yetinmemeyi önerdi. Coursera ve edX gibi platformlarda bu konuların anlatıldığı çevrimiçi dersler vardır ve bunların da takip edilmesini tavsiye etti. Böylece belli bir kaynağa bağlı kalmadan hem daha kapsamlı bilgi hem de tecrübe kazanılır.

## 3. Bilgiye Birinci Elden Ulaşmak

Hoca kendi derslerinde hep söylediği bir kuralı burada da tekrarladı: Merak edilen şey, doğrudan birinci şahıstan öğrenilmelidir. İkinci el bilgiye güvenilmez. Akademide de durum böyledir. Birinin okuyup özetlediği bir makalenin özetini okuyarak o makale hakkında sağlıklı bilgiye ulaşılamayabilir. Bir kitap özetinden de ancak özeti yazan kişinin anladığı kadarı, hatta daha azı öğrenilir.

Gündelik bir problemi çözmek için bilgiye ulaşırken bu çok sorun olmayabilir. Ama önemli konularda ikinci dereceden ve daha yüksek dereceden kaynaklar sıkıntı çıkarır. Arkadaştan duyulan ya da başka bir grubun dersinde söylendiği aktarılan bir bilgi, belirli şartlar altında söylenmiş olabilir. Doğru da olabilir, ama doğrudan güvenilmemelidir.

> **Hocanın vurgusu:** Hayatınızın hiçbir yerinde ikinci el bilgiye doğrudan güvenmeyin. Birinci el bilgi kaynağı vazgeçilmeziniz olmalıdır.

## 4. Algoritma Bu İşin Temelidir

Hoca kendi çalışma alanından yola çıkarak algoritmanın önemini anlattı. Sinyal işleme, müzik sinyal işleme, derin öğrenme, makine öğrenmesi ve yapay zeka gibi konularda çalıştığını söyledi. Bilgisayar bölümü olan bir meslek lisesinden mezun olduğunu, bugün yaptığı çalışmaların hepsinin orada ve birinci sınıfta öğrendiği algoritma dersleri sayesinde olduğunu belirtti.

### 4.1 Algoritma Geliştirmenin Algoritması Yok

Hocaya göre algoritma geliştirmenin bir algoritması yoktur. Bu yüzden bu konuda "oldum" denemez: "Oldum derseniz öldüm demektir." Sürekli yeni şeyler öğrenerek ve yeni problemler çözerek gelişmek gerekir. Hiçbir zaman "tamam, her şeyi hallettim" denemez.

Bu yönüyle algoritma, matematikteki üstlü sayılar ya da fizikteki basınç gibi bitirilebilen bir konuya benzemez. Hocanın benzetmesi yabancı dil öğrenmektir. İngilizcede yalnız grameri öğrenmek, okuduğunu tam anlamaya, yazmaya, konuşmaya ya da dinlediğini anlamaya yetmez. Daha çok kelime öğrenmek gerekir ve kelimenin ucu bucağı yoktur. Daha çok pratik yapmak, daha çok kitap okumak gerekir. Ortalamanın üzerindeki bir seviyeye geçilince bunun meyveleri yenir. Algoritma da böyledir, ama "zirve noktasındayım" denebilecek bir yer yoktur. Hocanın kendisi için de durum aynıdır: Zor bir problem gelir, çözülemez ya da anlaşılamaz. Bunlar normaldir.

### 4.2 Üniversite Mesleğin Mantığını Öğretir

Üniversitenin sağlayacağı şey, belirli bir problem türünün nasıl çözüleceği ya da belirli bir programlama dilinin nasıl öğrenileceği değildir. Amaç, bir meslek kavramı ve meslek nosyonu kazandırmaktır.

Hoca burada hukuk fakültesi örneğini verdi. Hukuk fakültesinde kanun ya da anayasa maddeleri değil, anayasanın ruhu ve mantığı öğretilir. Maddeler ezberletilirse, yasa değiştiğinde o bilgi eskir. Mantığı öğretilirse insan değişikliğe göre kendini güncelleyebilir.

Bilgisayar mühendisliği de böyledir. Bazen mantığın kendisi de değişir ve daha önce karşılaşılmamış yeni bir şey çıkar, onun da mantığı öğrenilir. Eskiden elektrik ve elektronikle birlikte olan, "hesap kürsüsü" gibi adlar taşıyan bölümlerden bugün oturmuş bir branş ortaya çıkmıştır. Bu branş artık kendi içinden yazılım, veri bilimi ve yapay zeka gibi yeni dallar çıkarmaktadır. Mesleğin mantığını ve nosyonunu öğrenmek, insanı bu işte sürekli taze tutar.

## 5. Etkileşimli Ders Ne Demektir?

Hoca, öğrencilerden sık gelen "ders daha etkileşimli olsun" isteğinde etkileşimin ne anlama geldiğinin tam anlaşılmadığını düşündüğünü söyledi. Dersleri işleyişlerine göre ayırdı:

- **Kavram dersleri:** Biri kavramlar üzerine konuşur, dinleyenler not alır ve özet çıkarır. Özellikle sosyal derslerde böyledir, mühendislikte de böyle dersler vardır.
- **Matematiksel dersler:** Tahtada ya da grafik tablette işlem yapılır.
- **Kod yazılan dersler:** Ders kod yazarak işlenir.

Sadece hoca konuşursa etkileşim bir yere kadar sağlanır. Etkileşim için karşılıklı katılım gerekir. Hoca soru sorduğunda el kaldırarak, mikrofonla ya da yazarak cevap vermek dersin etkileşimini artırır. Hoca kendisinin "monolog sanatçısı" olmadığını, tek başına konuşmak gibi bir yeteneği bulunmadığını söyledi.

Hocanın anlatım yöntemi de sorulara dayanır. Bilinenden bilinmeyene, kolaydan zora gitmenin anahtarı, hocanın anlayışında bu kapıları sorularla açmaktır. Bir soru sorulur, bir cevap gelir. Cevabın içinden fark edilmemiş yeni sorular ve yeni kavramlar çıkar. Bu yüzden önemli olan sorulara bir şekilde cevap gelmesidir. Cevap "bilmiyorum" da olabilir, bunda utanılacak bir şey yoktur.

## 6. Bu Ders Nasıl Çalışılır?

Hoca, yaklaşık 8 yıllık tecrübesine dayanarak birkaç tavsiye verdi.

> **Hocanın vurgusu:** Bu ders ilgi gerektirir. Ezberlenecek bir ders değil, anlaşılacak ve pratik yapılacak bir derstir.

### 6.1 Aktif Katılım

Bir eksiği kapatmak için başkasının ders notu ya da internette bulunan bir kurs faydalı olabilir, ama derste anlatılanlar için birinci dereceden kaynak derse katılmaktır. Hoca, dersten başarısız olanlara baktığında en sık gördüğü durumun derse aktif katılmamak olduğunu söyledi. Bu kişiler ya derse gelmez, ya sınıfta olup ilgisiz kalır, ya da uzaktan eğitimde yalnızca bağlı görünür.

### 6.2 Anlaşılmayanı Sormak

İkinci önemli etken anlaşılmayan şeyi sormaktır. Hoca, bilinmeyen bir şeyi sormaktan çekinmemek gerektiğini söyledi. Ekrana bakarak ders anlatmak sınıfta anlatmaktan zordur ve hoca da ders içinde yanlış yapabilir. Öğrencilerden gelen düzeltmeler hem yanlışı giderir hem de dikkati gösterir.

### 6.3 Düzenli Pratik

Ders başta izlenip çok çalışılmazsa, son iki üç günde telafi edilemez. Ezberlenecek bir şey olsaydı ezberlenip geçilebilirdi, ama burada pratik yapmak gerekir.

> **Hocanın vurgusu:** Ders saati dışında haftada 2-3 saat kodlama yapın, yani C üzerinde kod yazın.

Derste çözülen sorulara ek olarak, pratik amaçlı çalışma soruları da hazırlanacak.

## 7. Not Tutmak ve Kodu Kendin Yazmak

Hoca not tutmayı tavsiye etti. Özellikle bir şey yazıp "bunu not edin, lazım olur" dediğinde not almak iyi olur. Kişinin kendi tuttuğu notlar, ileride bir şeyi hatırlamak gerektiğinde yardımcı olur. Ama derste her şey not edilmez. Hocanın yazdığı programı deftere geçirmeye gerek yoktur.

Öğrenciler sık sık hocanın yazdığı programların kaynak kodunu ister. Hoca bu kodları gönderdiğini, ama ekran alıntısı aracıyla görüntü olarak gönderdiğini söyledi. Amacı kodun kopyalanması değil, yeniden yazılmasıdır. Noktalı virgülün nerede kullanıldığı, `printf`'in ve `scanf`'in nasıl çalıştığı, hocanın anlattığı bir yer değiştirme (swap) işleminin ya da bir sıralama algoritmasının nasıl yapıldığı en iyi yazarak öğrenilir. Bunun için hata yapmak da gerekir. Yapılan hatayı geliştirme ortamı (IDE) söyler.

**Soru:** Öğrenmek için deftere not almak yeterli olur mu? **Cevap:** Sadece defter çok iyi bir çözüm değildir. Hatta hiç defter tutmadan sürekli kod yazan, bu sayede hatalarını gideren ve çok güzel program yazan öğrenciler vardır.

<!-- BELİRSİZ: Öğrencinin sorusu altyazıda geçmiyor, sohbet penceresinden sorulmuş olmalı. Soru metni hocanın cevabından çıkarıldı (00:51:56). -->

## 8. Programlama Ortamı ve C Standardı

Hoca, sorun yaşanmaması için kodun CodeBlocks ya da Dev-C++ üzerinde yazılmasını tavsiye etti. Linux, Ubuntu ve macOS gibi ortamlarda da benzer uygulamalar vardır ve onlardan biri tercih edilebilir. Asıl şart, derste anlatılan C standardına uygun kod yazmaktır. Hoca bu standartları gerektiği yerde ayrıca vurgulayacağını söyledi.

### 8.1 C ile C++'ı Karıştırmamak

Derste C kodu beklenir, C++ kodu değil. Kod, derste anlatılan özelliklere göre denetlenir. Lisede ya da başka bir yerde C++ öğrenmiş olanlar iki dili karıştırabilir. C derleyicilerinin standartları farklı olabilir ve C ile C++ çok sık karışır. Bu yüzden herkesin "aynı dili konuşması" gerekir. Bu ders C programlama dili dersidir, Java, C++ ya da Python kullanılmaz.

> **Ek bilgi (derste anlatılmadı):** C dilinin büyük olasılıkla C89, C99 ve C11 gibi farklı standart sürümleri vardır ve bir kodun derlenip derlenmemesi seçilen sürüme bağlı olabilir. Bir IDE, `.cpp` uzantısıyla kaydedilen dosyayı büyük olasılıkla C++ olarak derler. Bu yüzden C kodunun büyük olasılıkla `.c` uzantısıyla kaydedilmesi gerekir. Kod C++'a özgü bir yapı içeriyorsa bu fark derleme sırasında ortaya çıkabilir.

### 8.2 Sorular: Hangi Ortam Kullanılmalı?

**Soru:** Windows'ta hangi ortam kullanılmalı? **Cevap:** Windows kullanılıyorsa Dev-C++ ya da CodeBlocks yeterlidir. Visual Studio kullananlar da var, ama onun yapılandırması farklıdır. Dev-C++ hem daha küçük bir programdır hem de hocaya göre bu ders için daha uygundur.

**Soru:** macOS'ta Xcode kullanılabilir mi? **Cevap:** Xcode üzerinde yazılabilir, ama derste anlatılan standarda dikkat edilmelidir.

<!-- BELİRSİZ: Bu iki soru da altyazıda geçmiyor, sohbet penceresinden sorulmuş olmalı. Soru metinleri hocanın cevaplarından çıkarıldı (00:53:18, 00:53:45). -->

Hoca, başka bir platformda yazılan kodun bir de çevrimiçi bir IDE'de çalıştırılmasını önerdi. Örnek olarak OnlineGDB sitesini verdi. Hocaya göre oradaki standartlar derste anlatılan standartlarla uyuşur. Kod orada da çalışıyorsa standart sorunu yaşanmamış olur.

## 9. Kitaplar ve Diğer Kaynaklar

### 9.1 Introduction to Algorithms

Dersin izlencesinde, yani Bolonya sayfasında, *Introduction to Algorithms* kitabı yer alır. Hoca kitabı "MIT'nin algoritmaya giriş kitabı" diye tanıttı. Bu kitap algoritma analizine kadar bütün konuları içerir. Hocaya göre bu dönem kitabın belki yüzde 15'i ya da yüzde 20'si kadarıyla meşgul olunacaktır.

> **Ders sonrası not:** Hoca kitabı "MIT'nin kitabı" olarak andı. Kitap büyük olasılıkla Cormen, Leiserson, Rivest ve Stein'ın yazdığı, MIT Press'ten çıkan kitaptır.

MIT'nin sayfasındaki *Introduction to Algorithms* dersine bakılırsa dersin içeriğine ait notlara ulaşılabilir. Kitap bu dersle uyumludur. Kitap C programlama öğretmez. Algoritma kavramını sözde kod (pseudocode, yapay kod) üzerinden anlatır. Hoca kitabın ağır olduğunu ve biraz zor olduğunu da söyledi.

> **Ek bilgi (derste anlatılmadı):** Sözde kod büyük olasılıkla belirli bir programlama dilinin söz dizimine bağlı olmayan, algoritmanın adımlarını insanın okuyacağı biçimde anlatan bir gösterimdir ve bilgisayarda doğrudan derlenip çalıştırılmaz. Bu yüzden kitaptaki bir algoritmayı denemek için büyük olasılıkla önce C gibi bir dile çevirmek gerekir.

### 9.2 C Kitapları

Hoca, C ile ilgili Türkçe kitapların faydalı olabileceğini, ama derste yapılan kodlamaların ve çalışmaların bu kitapları okumaya gerek bırakmayacak içerikte olduğunu söyledi. Ayrıca destek olarak birkaç öğretici (tutorial) site paylaşacağını belirtti. Hocaya göre Türkçe kitapların çoğunun seviyesi lise düzeyindedir: Mükemmel sayı bulmak için bir kod yazılmıştır, altına cevabı ya da ekran görüntüsü konmuştur. Girdi verip çıktı almaktan ibaret programlardır. `if` nasıl kullanılır, `for` nasıl kullanılır, fonksiyon nasıl yazılır, pointer nedir, bunların hepsi zaten derste anlatılır.

Yabancı kitaplar arasında hoca önce programlama tarafında slaytları çoğunlukla kullanılacak bir kitabı andı. Altyazıda yazarın adı "Data" olarak geçiyor. Hoca bu kitaba da çok gerek olacağını düşünmüyor.

> **Ders sonrası not:** Altyazıda "Data" olarak geçen ad büyük olasılıkla, C programlama kitabıyla tanınan Deitel'dir.

<!-- BELİRSİZ: Hocanın söylediği yazar adı altyazıda "Data" olarak geçiyor (00:57:26, 00:57:28). -->

Tercih yabancı dilde yazılmış kitaplardan yana olursa, hocanın örneği *Problem Solving and Program Design in C* kitabıdır. Hoca yazarların aynı zamanda algoritma ve veri yapıları üzerine kitapları olduğunu, bunların kaliteli kitaplar olduğunu söyledi.

> **Ders sonrası not:** Hoca yazarı "Henry Koffman" olarak andı, "Henley diye yazılıyor" dedi. Kitabın yazarları büyük olasılıkla Jeri R. Hanly ve Elliot B. Koffman'dır.

Hocaya göre kitap okumak, meslekte daha çok bir aktivite, bir hobi olmalıdır. Bu kitaplardan da bu amaçla faydalanılır. Derste anlatılanlar ve yapılan çalışmalar, dersten beklenen başarı için yeterlidir.

### 9.3 Ek Paylaşımlar

Dersin kaynakları, ders koordinatörü Fatih Hoca'nın sayfasında yer alacak. Hoca bunlara ek olarak faydalı bulduğu öğretici siteleri, YouTube kanallarını ve başka üniversitelerin ders notu sayfalarını da paylaşacağını söyledi. Bu paylaşımlar dersin doğrudan içeriği değil, ek kaynaklardır.

## 10. Bilgisayar Bilimlerine Giriş Dersini Almamış Olanlar

Geçen dönem Bilgisayar Bilimlerine Giriş'i almamış olmak biraz sorun yaratabilir, çünkü algoritmanın ve programlamanın ne olduğu oradan biliniyor varsayılır. Ama hoca bir sonraki dersten itibaren geçen dönemin bir anlamda tekrarını yapacağını söyledi. Bu derste de algoritmanın ne olduğu, nasıl geliştirilmesi gerektiği ve iyi algoritmanın ne olduğu üzerinde çalışılacak. Bu yüzden büyük bir eksik kalmaz.

Hocanın benzetmesiyle o dersi almış olmak, yarışa 100-200 metre önden başlamak gibidir. Almamış olmak yarışı kaybetmek demek değildir. Öyle olsaydı bölüm o dersi bu dersin ön koşulu yapardı. Hoca, ayrık matematiği üstten alanların algoritmaya tam vakıf olmadıkları için biraz zorlandığını da ekledi. Ancak bu ders, bilinmeyen ya da daha önce tecrübe edilmemiş şeyleri öğretmeye yöneliktir.

<!-- BELİRSİZ: Ayrık matematiği üstten alanlardan söz edilen cümlenin başı altyazıda bozuk ("100 döneminden baktığımda", 00:59:30). -->

Uzaktan eğitimin de bir avantajı vardır: Dersler diğer gruplardan da takip edilebilir. Hoca, kendisinden anlaşılmayan bir konunun Fatih Hoca'dan da dinlenmesini tavsiye etti, çünkü öğrenme böyle olur.

## 11. C Bilgisi Azsa Ne Yapmalı?

**Soru:** C kodu konusunda bilgim çok az. Pratik kazanmak için bir kitap ya da kurs önerir misiniz? **Cevap:** C, birinin anlatması ve dinlemekle çok fazla öğrenilmez. Burada anlatılanlar uygulanırsa, para verilerek öğrenilecek birçok kursun içeriği burada alınmış olur. Bu yüzden kursa gerek yoktur.

Hoca, temel C'nin bu bölümü kazanan herkesin, programlama geçmişi olmasa da, rahatça öğrenebileceği bir dil olduğunu söyledi. Ekstra bir kurs hem maddi yük getirir hem de zaman maliyeti doğurur. "Bir koltuğa iki karpuz sığmaz" diyerek, dönemde zaten yedi sekiz ders alınırken paralel bir özel kursu gereksiz bulduğunu belirtti.

## 12. Hangi C Derleyicisi İndirilmeli?

**Soru:** Hangi C derleyicisini (compiler) indirelim? **Cevap:** Dev-C++ ya da CodeBlocks kullanılacak. Ama bunlar derleyici değil, IDE'dir. İçlerinde derste kullanılan standartlara uygun C derleyicileri bulunur. Bunlardan biri yeterlidir.

> **Ek bilgi (derste anlatılmadı):** IDE büyük olasılıkla kod düzenleyici, derleyici ve hata ayıklayıcı gibi araçları tek bir programda toplayan geliştirme ortamıdır ve kodu çeviren parça da derleyicidir. Dev-C++ ve CodeBlocks büyük olasılıkla GCC tabanlı derleyicilerle birlikte kullanılır. CodeBlocks'un büyük olasılıkla derleyici içeren ve içermeyen kurulum paketleri vardır, bu yüzden indirirken derleyicili olan seçilmelidir.

## Dersin Toparlaması

Bu tanışma dersinde yapısal programlama konularına girilmedi. Dersin müfredattaki yeri ve dersten nasıl verim alınacağı konuşuldu. BLM1012, BLM1011'den alınan altyapıyı algoritma geliştirme ve C programlamayla ileri taşır ve sonraki yılların programlama ve algoritma derslerine temel olur. Algoritma öğrenmek yabancı dil öğrenmek gibi bitmeyen bir süreçtir. Bu yüzden ders ezberle değil, anlayarak ve haftada birkaç saat kendi kodunu yazarak çalışılır. C kodu Dev-C++ ya da CodeBlocks gibi bir IDE'de, derste anlatılan standarda uyularak ve C++ ile karıştırılmadan yazılır.

Bir sonraki derste dersin konuları tanıtılacak ve birinci dönemin algoritma konularının tekrarına başlanacak. Dersin devamında algoritmanın ne olduğu, nasıl geliştirileceği ve iyi algoritmanın ne olduğu işlenecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
