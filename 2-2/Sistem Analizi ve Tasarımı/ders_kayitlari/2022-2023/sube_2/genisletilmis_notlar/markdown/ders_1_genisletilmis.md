# Ders 1 Genişletilmiş Notu: Sistem ile Bilgi Sistemi Kavramlarına Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Kaynakları
- 2. Dersin Konu Haritası: Bir Bilgi Sisteminin Yolculuğu
- 3. "Sistem" Kelimesi: Sözlükten Bilgi Sistemine
- 4. Bilgi Neden Bu Kadar Değerli?
- 5. Bilgisayar Programı ile Bilgi Sistemi Arasındaki Fark
- 6. Sistemin Tanımı
- 7. Sistemin Temel Özellikleri
- 8. Sistem ve Ortam
- 9. İki Sistem Örneği: Ev Sinema Sistemi ve Restoran
- 10. Bilgi Sisteminin Tanımı
- 11. Bilgi Sisteminin Bileşenleri: D-Y-İ-V-A
- 12. Alt Sistemler ve Katmanlı Yapı
- 13. Sistemlerin Teorik Özellikleri
- 14. Ders Sonrası Alıştırma ve Soru

## 1. Dersin Kaynakları

Hoca iki kaynak gösterdi. Birincisi, Oya Hoca ile birlikte yazdıkları *Bilgisayar Bilimlerinde Sistem Analizi ve Tasarımı* kitabıdır. Kitabın artık basımı yapılmıyor, yeni bir baskı için içerik de genişletilemedi. Hoca bu kaynağı dersin bir el kitabı, bir özeti gibi düşünmemizi istedi. Derste aynı konuları daha ayrıntılı ve kitapta olmayan eklerle anlatacağını söyledi.

İngilizce kaynak olarak Satzinger'in *Systems Analysis and Design in a Changing World* kitabını önerdi. Kitabın 7, 8, 9, 10 gibi daha yeni baskıları da var. Ancak ders 6. baskının içeriğini temel alıyor, çünkü amaç işin temellerini de öğretmek. Sonraki baskılar tamamen nesneye dayalı yaklaşıma gidiyor. 6. baskıda ise hem geleneksel yaklaşım, yani fonksiyonel çözümleme, hem de nesneye yönelik yaklaşım bir arada ele alınıyor. Dersin akışı da bu yüzden bu baskı üzerine kurgulandı.

> **Ders sonrası not:** Altyazıda kitabın adı "System Analysis and Design in a Changing World" diye geçiyor. Adın doğrusu, kısa notta da yazıldığı gibi, büyük olasılıkla *Systems Analysis and Design in a Changing World* (Satzinger, Jackson, Burd) biçimindedir.

## 2. Dersin Konu Haritası: Bir Bilgi Sisteminin Yolculuğu

Hoca 14 haftalık planı anlatırken aslında bir bilgi sisteminin baştan sona geçirdiği aşamaları da özetledi. Bu yüzden plan yalnızca bir takvim değil, dersin kavram haritası gibi okunabilir. Hoca, konuların haftalar arasında sarkabileceğini ama mümkün olduğunca paketlenmeye çalışılacağını belirtti.

### 2.1 Giriş ve Bilgi Sistemi Türleri

İlk hafta sistem, bilgi sistemi ve bilgi sisteminin özellikleri gibi temel kavramlar görülüyor. Hoca, bundan sonra "sistem" dediğinde bunun her seferinde bir bilgi sistemi anlamına geleceğini söyledi.

İkinci haftada bilgi sistemlerinin tipleri ele alınacak. Sorular şunlar: Bu tipler nelerdir, onları kategorize etmenin ne faydası vardır, kategoriler arasında ne gibi bağlantılar vardır? Hangi bilgi sistemi türü ne gibi çıktılar üretir ve bunları başka bilgi sistemlerine girdi olarak nasıl sağlar?

Aynı hafta bilgi sisteminin **tarafları** da görülecek. Taraf; bilgi sisteminden faydalanan, onu kullanan, ona hizmet eden veya ondan hizmet alan herkes olabilir. Hem verici hem alıcı tarafta bulunulabilir. Bir sistem geliştirilirken bu tarafların nasıl bir iş paylaşımı yaptığı, her rolün görev ve sorumluluğunun ne olduğu ve birlikte nasıl çalıştıkları incelenecek.

### 2.2 Geliştirme Süreci ve Yaşam Döngüsü

Hocaya göre bir bilgi sistemi geliştirmek "hadi arkadaşlar yapıyoruz, başlayalım, devam edelim, hadi bitti" denebilecek bir iş değildir. Mutlaka belirli, tanımlı, ölçülebilir, süreleri ve içindeki faaliyetleri belli olan etaplardan oluşmalı ve adım adım ilerlemelidir. Bu zaman akışına **geliştirme süreci**, özellikle de **bilgi sistemi geliştirme süreci** denir.

Daha da ileri gidilerek buna **bilgi sistemi yaşam döngüsü** de denir, çünkü sistemler yaşayan organizmalar gibidir. Hocanın benzetmesi şöyledir:

- **Oluşum:** Sistem, bir bebeğin annesinin karnında büyümesi gibi oluşturulur.
- **Doğum ve büyüme:** Sistem doğar, gitgide kullanılır, büyür.
- **Bakım:** Araya, hastaneye gitmek gibi bakımlar, değişiklikler, belki farklı operasyonlar girer.
- **Son:** Bir yerde yaşamı tamamlanır, sistem emekliye ayrılır.

Ama iş orada bitmez. Aynı hizmetler yeni bir sistemle, güncellenerek verilmeye devam eder. Sistem geliştirme süreci ise özellikle sıfırdan bir bilgi sisteminin kullanılabilir hale geldiği ana kadarki dönemi kapsar. Derste her adım için şu sorulara bakılacak: Burada ne yapılır, neden yapılır, ne çıkar ve bu çıktı neye hizmet eder?

### 2.3 Ön İnceleme ve Fizibilite

Üçüncü haftadan itibaren geliştirme sürecinin adımları tek tek açılıyor. İlk adım **ön inceleme**dir: Bir bilgi sistemi geliştirme projesinde nelere bakılır, "yol yakınken nasıl kaçılır" ya da bu işe nasıl girilir?

İkinci adım **fizibilite** çalışmasıdır. Kelime anlamı yapılabilirliktir ve Türkçeye yapılabilirlik etüdü olarak çevrilir. Hoca tek cümleyle şöyle tanımladı: Elimizdeki mevcut altyapı, insan ve diğer kaynaklarla, bize tanınan zaman çerçevesi içinde bu sistemi ortaya koyabilir miyiz? Koyabiliyorsak bu bize neye mal olur? Koyamıyorsak ilave olarak nelere ihtiyacımız var?

Fizibilitenin alt dalları vardır ve hepsine değinilecek. Özellikle **zaman fizibilitesi** üzerinde durulacak. Çünkü bu çalışmada geliştirme sürecinin tamamı planlanır. Bütün faaliyetler, alt faaliyetler, sorumlular, kullanılacak altyapı, yazılım ve donanım burada birbiriyle eşleştirilir.

### 2.4 Sistem Analizi

Dördüncü ve beşinci haftalarda sistem analizi aşamasına geçiliyor. Burada şu sorular sorulur: Bu işi nasıl yaparız, burada neler oluyor, problem nedir, bu problemi nasıl çözmeliyiz? Sistem analizi genellikle iki aşamadan oluşur.

Birinci aşama **iş gereksinimleridir (business requirements)**. Burada verinin nasıl toplanacağı, yapılan mevcut işlerin nasıl analiz edilip yazılımcılar gibi teknik insanların anlayacağı dile nasıl tercüme edileceği ve nasıl dokümante edileceği görülür. Geleneksel yaklaşımın yanında, nesneye dayalı yaklaşım için de **kullanım senaryoları (use case)** öğrenilir: Nasıl bulunurlar, nasıl yazılırlar?

İkinci aşama **çözümleme**dir ve beşinci ve altıncı haftalarda işlenir. Burada problem net olarak tanımlanır ve teknik tarafın tasarım üretebilmesi için gereken girdiler üretilir. Önce geleneksel, yani işlevsel ya da fonksiyonel çözümlemeyle bu işin nasıl yapıldığına, ne gibi diyagramların neden çizildiğine bakılır. Altıncı haftada ise kullanım senaryolarından yola çıkılarak nesneye dayalı çözümleme yapılır ve senaryoların yazılım uzayına taşınmaya nasıl hazırlandığı görülür.

### 2.5 Sistem Tasarımı

Yedinci haftada sistem tasarlanmaya başlanıyor: mimari tasarım, genel tasarım ve ayrıntılı tasarım. Fonksiyonel ve nesneye yönelik yaklaşımda hangi çıktıların üretileceği üzerinde durulacak. Sekizinci haftada tasarımın kalan unsurları geliyor: Girdiler, çıktılar ve kullanılacak veri yapıları nasıl tasarlanmalıdır? Diğer sistemlerle ve uçlarla etkileşecek **ara birimler** nasıl tasarlanmalıdır?

### 2.6 Veri Tabanı Tasarımı

Bilgi sistemleri doğal olarak verilerle çalışır ve verileri işleyerek bilgiye dönüştürür. Verileri yaratmak, saklamak, değiştirmek ve silmek için bir yerde tutmak ve bunun için bir yapı kurmak gerekir. Onuncu haftada özellikle **ilişkisel model** ve bir bilgi sistemindeki verilerin birbiriyle nasıl ilişkili bir model oluşturacağı görülecek.

Hoca bunu herkesin bildiği OBS (öğrenci bilgi sistemi) üzerinden örnekledi. Sistemde öğrenci, hoca, ders, derslik ve eğitim planı bilgileri vardır ve bunlar birbiriyle ilgilidir. Bir dersin kendine has verileri vardır: kodu, adı, kredisi, AKTS'si, 14 haftalık planı, kaç sınavı, ödevi, projesi olduğu gibi. Bir öğrenci bu dersi seçtiğinde aslında bir ilişki kurulmuş olur: Bu öğrenci bu dersle ilişkilendi. Ders bir derslikle, derslik bir fakülteyle, ders bir ders programıyla, yani gün ve saatle ilişkilidir. Pek çok veri birbiriyle ilişki halinde durmak zorundadır ve bunları tasarlamanın da bir yolu yordamı olmalıdır. Bu konuya bir hafta ayrıldığı için çok derinlere inilmeden temelleri görülecek.

### 2.7 Gerçekleştirme, Test, Geçiş, Bakım ve Destek

Fizibilite, analiz ve tasarım bittikten sonra sistem çalışma şekliyle, verisiyle, girdisi, çıktısı ve ara birimiyle tasarlanmış olur. Artık gerçekleştirilmesi gerekir. On birinci haftada yapısal programlama dersine dönülmeyecek, daha üst seviyeden bakılacak: Bir tasarımdan kodlamaya geçerken nelere dikkat edilir, nereden başlanır, önce neresi oluşturulur?

Sonraki adım **test**tir: Bir sistem neye göre test edilir, hangi test ne için vardır? Testlerden sonra geriye dönmek gerekebilir. Hata gerçekleştirmede, tasarımda ya da analizde olabilir. Hoca, analizde her şeyin yanlış anlaşılmış olmasının durumu daha da tehlikeli hale getireceğini söyledi.

Ardından **yeni sisteme geçiş** gelir. Hoca bunun kolay olmadığını vurguladı: Genellikle var olan bir bilgi sistemi, orada duran veri ve canlı işlemler vardır. Bunların bir yerde durup yeni sisteme geçilmesi gerekir ve bu çok sancılı bir süreçtir. Geçiş çeşitleri ile avantaj ve dezavantajları tartışılacak. Son olarak yeni sistemin hayatı boyunca yapılacak **bakım** çeşitleri ve **destek** aktiviteleri görülerek süreç tamamlanacak.

Sonraki hafta, iki saate sığacak basit bir **vaka çalışması (case study)** üzerinden bütün süreç tekrar izlenecek: problem nasıl alınır, ön incelemesi ve fizibilitesi nasıl yapılır, analizden tasarıma, tasarımdan gerçekleştirmeye nasıl geçilir? Hoca dönemin bu şekilde tamamlanan 14 haftalık bir yolculuk olduğunu söyledi.

## 3. "Sistem" Kelimesi: Sözlükten Bilgi Sistemine

Konu anlatımı "Sistem ne demektir?" sorusuyla başladı. Hocaya göre bu soruyu cevaplamak için ilk yapılacak şey Türkçe sözlüğü açmaktır. TDK sözlüğüne göre *sistem* bir isimdir ve dilimize Fransızcadan gelmiştir. Hoca sözlükteki altı anlamı tek tek okudu ve her birinden bilgi sistemi için bir sonuç çıkardı.

**1. Düzen.** Sözlükteki örnekte "yeni bir ücretlendirme sistemi" geçer, yani ücretlendirme düzeni. Demek ki bir sistem düzenli olmalı, bir düzen içermelidir. Bilgi sistemi dediğimizde de bilgileri düzenleyen bir mekanizmadan söz ederiz.

<!-- BELİRSİZ: Birinci anlamın TDK örnek cümlesi altyazıda bozuk ("FETEKİ'nden açıklamasının arkasında yeni bir ücretlendirme sistemi getirdiğini"). Örneğin tamamı ve kaynağı okunamıyor. -->

**2. Bir sonuç elde etmeye yarayan yöntemler düzeni.** Sözlükteki örnek Halide Edip'ten alınmıştır: "Servet nasıl kazanılmış olursa olsun onun kontrolüne girecek rejim ve sistem memleketi mahvedecektir." Bilgi sistemi yine bilgileri düzenler, ama bu düzenlemenin bir amacı vardır: yararlı, faydalı bir sonuç, bir çıktı üretmek. Demek ki bilgi sistemi mutlaka sonuç üretmelidir.

**3. Yol, yöntem.** Örnek: "eski bir sistem". Buradan, bir işin yapılmasına destek olurken izlenecek yol, yöntem ve süreç tanımlarının olması gerektiği anlaşılır. Bilgi sistemlerinde mutlaka süreçler, bir akış bulunmalıdır.

**4. Bir aracı oluşturan düzen, düzenek, tertibat.** Örnek: fren sistemi. Sistemin ahenk içinde, uyum içinde çalışan parçaları vardır. Bir bilgi sisteminde de tanımlı bir işe yarayan ve bir arada çalışarak sonucu üreten bileşenler bulunmalıdır. Tasarım yaparken bu parçaların neler olması gerektiğini ve uyum içinde nasıl çalışacaklarını bulup ortaya çıkarmamız gerekecek.

**5. Model, tip.** Örnek: "Son sistem pırıl pırıl bir rotatif almışlar." Buradaki "son sistem", son model, en son tip demektir. Demek ki bir bilgi sisteminin birden fazla tipi, modeli olabilir. Aynı işi yapan daha eski ya da basit bir bilgi sistemi olabileceği gibi, daha sofistike, daha karmaşık ya da daha yeni bir bilgi sistemi de olabilir.

<!-- BELİRSİZ: Beşinci anlamın örnek cümlesinin kaynağı altyazıda "[öğrenci]'tan" diye maskelenmiş. Bu büyük olasılıkla sözlükte alıntılanan bir yazarın adıdır; ad okunamıyor. -->

Hoca bu örnek vesilesiyle "rotatif" kelimesini de açıkladı. Rotatif bir matbaa baskı makinesi teknolojisidir. Özellikle gazete, mecmua ya da fasikül tarzı yayınların basımında kullanılır. Kâğıt tek parça ve çok büyük bir rulo halindedir; hoca bunu tuvalet kâğıdının dev modeline benzetti. Rulo arkadan baskı makinesine yüklenir, makine basar ve bastıkça keser. Gazete yaprakları üst üste konulur ve katlanır. Fasikülleri üst üste koyarak kitap da elde edilebilir.

**6. Dizge (felsefe).** Hocanın okuduğu sözlük anlamı şudur: Bir bütün sağlayacak biçimde karşılıklı olarak birbirine bağlı öğelerin kurduğu düzen. Hoca bunun felsefe açısından 2. ve 3. anlamların bir arada okunmasına benzediğini söyledi.

Hoca ek olarak, öz Türkçede bizim yazdığımız program kodlarına da "dizge" dendiğini belirtti. Gerekçesi şuydu: Kodlar sıralı olarak birbirine bağlı öğelerdir, bir düzen içinde yer alır ve çalışarak bir sonuç üretir.

> **Ders sonrası not:** Hoca program kodlarına öz Türkçede "dizge" dendiğini söyledi. Kısa notta da belirtildiği gibi, "dizge" büyük olasılıkla "sistem" karşılığıdır; "program" için önerilen karşılık büyük olasılıkla "izlence", karakter dizisi (string) için kullanılan terim ise büyük olasılıkla "dizgi"dir.

Hoca bölümü şu gözlemle bağladı: Sistem kelimesini sözlükte okuduğumuzda bunları hemen bilgi sistemi olarak yorumlamayabiliriz. Ama yorumlanabilir. Sözlükteki anlamlar, bilgi sistemi dediğimizde az çok tanımladığımız şeylerle örtüşür. Yani aslında doğal bir tanım yapıyoruz.

## 4. Bilgi Neden Bu Kadar Değerli?

Hoca bilgi sistemine geçmeden önce kaynak kavramı üzerine bir soru sordu: Dünya savaşları neden çıktı? Sohbet şöyle ilerledi:

- **Birinci Dünya Savaşı:** Hocaya göre sanayi devriminden sonra ham madde ihtiyacı arttı ve ham madde kaynaklarının paylaşımı kavgası savaşa yol açtı.
- **İkinci Dünya Savaşı:** Bir öğrenci "yine benzer sebeple, birincide yeterince paylaşamadıkları için" cevabını verdi. Hoca bunu harika bir cevap ama doğru cevap değil diye karşıladı. Sanayi ilerlemeye devam etti ve üretim arttı. Üretilen mal birilerine satılmalıydı: "Pazar nerede?" Hocaya göre pazar paylaşımı İkinci Dünya Savaşı'nın sebebini oluşturdu. Büyük Buhran'ın da bunu barındırdığını ekledi.
- **Üçüncü Dünya Savaşı:** Hocaya göre ham maddeler ve pazarlar paylaşıldıktan sonra sıra bilgidedir. Enerji darboğazı yüzünden de savaş çıkabilir. Hoca, o tarihte birinci yılını doldurmuş olan Rusya-Ukrayna savaşının temel sorununun enerji paylaşımı olduğunu söyledi. Öğrencilerden gelen yapay zekâ ve su kaynakları önerilerini de önemli buldu.

Hocanın asıl söylemek istediği şuydu: Bilgi, dünya savaşına sebep olabilecek kadar kuvvetli bir kaynak haline gelmiştir.

> **Ders sonrası not:** Hoca savaş nedenlerini bilginin önemini anlatmak için tek bir kaynağa indirgedi. Savaşların nedenleri büyük olasılıkla tarihçilerce çok daha karmaşık değerlendirilir; bu sınıflama bir tarih bilgisi olarak değil, derste kurulan bir benzetme olarak okunmalıdır. Altyazıdaki "Birinci Dünya Savaşı'nda sanayi devrimi oldu" cümlesi de büyük olasılıkla bir dil sürçmesidir, çünkü Sanayi Devrimi büyük olasılıkla savaştan çok önceye, 18. ve 19. yüzyıllara dayanır. Aynı cümlenin devamında hoca da sıralamayı "sanayi devriminden sonra" diye kurdu.

Elinizde bilgi varsa ve onu doğru kullanıyorsanız bu size çok büyük bir rekabet avantajı sağlar. Bunun için de ayrı ayrı çözülmesi gereken problemler vardır:

- Bilgi nasıl üretilecek?
- Bilgi nasıl dağıtılacak?
- Bilgi nasıl işlenecek?
- Bilginin güvenliği nasıl sağlanacak?
- Bilgi nerede, nasıl saklanacak?

Bugün internet, geçmiş yüzyıllarda üretilen verinin kat kat fazlasını otomatik olarak üretiyor. Nesnelerin interneti de buna ekleniyor. Veri o kadar çok ki organizasyonunun ve kullanımının maliyeti de artıyor. Hoca, zettabayt ve yottabayt gibi söylemesi bile zor miktarlardan söz etti. Bu veriyi anlamlı hale getirip anlamlı çıktılar üretecek bir dönüşümden geçirmek gerekir. Bu dönüşümü yapan yapılar bilgi sistemleridir: **Bilgi sistemleri veriyi bilgiye dönüştürür.**

## 5. Bilgisayar Programı ile Bilgi Sistemi Arasındaki Fark

Hoca akla gelebilecek bir itirazı kendisi dile getirdi. Bir bilgisayar programında da kullanıcıdan iki string ya da iki dizi okuruz, karekök alırız, bir yerle çarparız, bir dönüşüm yapıp çıktı üretiriz. Böylece anlamlı bir bilgi üretmiş oluruz. O zaman biz de bilgi sistemi yapmış olmuyor muyuz?

Hocanın cevabı **ölçek**tir. Bir bilgisayar programını tek kişi birkaç saatte, birkaç günde, çok büyük bir programsa birkaç ayda yapabilir. Bir bilgi sistemini ise bir kişinin bu kadar sürede üretmesi imkânsızdır. Bir ekip için bile çoğu zaman kolay bir iş değildir.

Bilgi sisteminde bir arada çalışan çok fazla bileşen vardır, dış sistemlerle çok fazla etkileşim gerekir ve çok sayıda anlamlı sonuç üretilmesi beklenir. Bunu yalnızca bir programa indirgemek fazla basit kalır. Bilgi sistemlerinin içeriği, bir bilgisayar programıyla karşılaştırıldığında çok daha geniştir.

## 6. Sistemin Tanımı

Hoca slayttaki şekil üzerinde tanımın parçalarını tek tek işaretleyerek ilerledi. Şekilde "terliksi hayvan"a benzettiği, sınırı çizilmiş bir sistem vardı.

> **Hocanın vurgusu:** Sistemin tanımı tam olarak şudur: Belli bir amacı gerçekleştirmek için bir arada çalışan, birbiriyle ilişkili parçalardan oluşan, girdi ve çıktıları olan, sınırları belirlenmiş bütün yapı, oluşum veya çözüme **sistem** adı verilir.

<!-- BELİRSİZ: Slayttaki "terliksi hayvan" şeklinin tam çizimi altyazıda yalnızca sözlü olarak anlatılıyor. Hangi bileşenin nerede durduğu ve okların yönü okunamıyor. -->

Tanım parçalarının şekildeki karşılığı şöyledir:

- **Amaç:** Amacı olmayan bir sistem yoktur.
- **Sınır:** Şeklin çevresinde çizilmiş bir sınır vardır. Sınır sistemi ortamdan ayırır. Hoca bunu bir hücre duvarına benzetti.
- **Bileşenler:** Sistemin içinde bir arada, birbiriyle ilişkili çalışan parçalar vardır. Örneğin biri verilerin bir yerden okunmasından, biri belli bir aritmetik işlemden, biri de sonuçlardan rapor üretmekten sorumlu olabilir.
- **İlişkiler:** Bileşenler arasındaki çizgilere ilişki adı verilir.
- **Ortam:** Sistem bir ortamda yer alır. Ortamda başka sistemler de bulunabilir ve sistem onlarla etkileşebilir.
- **Girdi ve çıktı:** Sistem çalışmak için başka sistemlerden ya da ortamdan girdi alabilir. Başka sistemlerin ya da ortamın faydalanması için çıktı üretebilir.
- **Ara birim:** Başka sistemlerle birlikte çalışılıyorsa ya da insan etkileşimi gerekiyorsa bir ara birim de olmalıdır.

> **Hocanın vurgusu:** Bu öğelerin hepsine sahip bir yapınız varsa ona rahatlıkla sistem diyebilirsiniz. Bunlardan biri ya da birkaçı yoksa bir sistemden söz edemezsiniz.

## 7. Sistemin Temel Özellikleri

Hoca bir sonraki slaytta bu özellikleri teker teker açtı ve şekilde değinmediği değişkenleri de ekledi.

- **Bileşen:** Sistemi oluşturan parçalardır.
- **Değişken:** Bilgi sistemi çalışıp işlevlerini yürütürken değişik değerleri tutan özelliklerdir. Bir programın içindeki değişkenlere benzer.
- **Parametre:** Sistemin sabitleridir. Programlamadaki `final` ve constant tanımları gibi düşünülebilir.
- **İlişki:** Bileşen, değişken ve parametre arasındaki bütün bağlantılardır.
- **Sınır:** Sistemi ortamdan ayıran çizgidir.
- **Ara birim:** Sistemin bir ortamla, alt sistemlerle ya da başka sistemlerle karşılaştığı, konuştuğu noktalardır.
- **Kısıt:** Değişkenlerin alabileceği değerler ve varsa çeşitli kaynak ayırımlarının sınırlarıdır.
- **Ölçüt:** Sistemin amacını ne kadar iyi gerçekleştirdiğini ölçmeyi sağlayan metriklerdir.
- **Ortam:** Sistemin dışında kalan her şeydir.
- **Geri besleme (feedback):** Çıktının ve ölçümlerin sistemi iyileştirmek üzere tekrar girdi olarak verilmesidir.

Hoca bunlardan birkaçını örnekle genişletti.

### 7.1 Ara Birim ve API

Günümüzde çok sayıda bilgi sistemi, API (Application Programming Interface) denen ara birim standardı üzerinden haberleşir. API, bir uygulamanın ya da sistemin başkalarına hangi hizmetleri hangi koşullarla açtığını belirtir. Hoca bunu bir **kontrat** olarak düşünmemizi istedi: "Bu hizmeti alabilirsin, ama bunun için şunu vermen lazım, karşılığında da sana bu tip bir çıktı veririm."

### 7.2 Ölçüt: Saniyede Bin Kayıt

Metrikler çok farklı olabilir. Hoca akla ilk gelenlerden olan performans metriğiyle örnek verdi. Sistemin amacı öğrencileri tek bir derse, Sistem Analizi dersine, kaydetmek olsun. Bu küçük bir alt sistem ya da modüldür.

"Saniyede bin öğrencinin kaydını yapabilmeli" diye bir ölçüt tanımlandıysa tasarım da ona göre yapılmalıdır. Bin öğrencinin getirdiği veri miktarı ve yapılması gereken toplam işlem miktarı göz önüne alınarak çözüm kurulmalıdır. Bu sayının 1000, 500, 100 ya da 10 olması, problemin ve çözümün ölçeğini tamamen değiştirir. Ölçüt bu işe yarar.

### 7.3 Ortam ve Geri Besleme

Hoca ortamı kısaca "her şey eksi sistem" diye özetledi: Bizim dışımızda kalan her şey ortamdır.

Geri beslemenin ise bütün kaynaklarda söylenmese bile bir sistemde mutlaka olması gereken bir özellik olduğunu söyledi. Sistemin bir çıktısı ve ölçme değerlendirme ölçütleri vardır. Bunlar sisteme tekrar girdi olarak verilir. Amaç süreci iyileştirmektir: Çıktı ölçülür, "bu çok da iyi olmamış, şurayı şöyle değiştirelim" denir. Böylece süreç akışları ve iş yapış şekli iyileştirilir, sistem bu yolla değiştirilir.

## 8. Sistem ve Ortam

### 8.1 Sistem Başka Bir Sistemin Üzerindedir

Sistemler bulundukları ortamlara bağlıdır. Bir sistem de genellikle başka bir sistemin üzerinde durur. Hoca bunu öğrenci bilgi sistemiyle gösterdi:

- Öğrenci bilgi sistemi, en nihayetinde çok fazla bileşeni olan dev bir yazılımdır ve sunucu ortamında durur.
- Sunucu ortamında yazılım, işletim sistemi katmanının üzerindedir.
- İşletim sisteminin altında, bilgisayarın ilk açılışındaki BIOS dediğimiz temel kod parçası olabilir.
- İşletim sistemi de donanım sisteminin üzerinde durur.

Böylece fiziksel ortama kadar inen ortamlardan söz edilebilir. Sistemle ortamı arasında doğrudan ya da dolaylı ilişkiler olmak zorundadır, yoksa sistem etkileşmiyor demektir.

### 8.2 Sistem Ortamını Değiştirebilir

Sistem ortamda değişiklik de yapabilir. Üretilen bilgi bir yerde depolanır: işletim sisteminin dosya yöneticisi üzerinden sabit diskte ya da bir veri tabanı yönetim sisteminde. Başka hiçbir şey olmasa bile, fiziksel ortamdaki manyetik alanlarda sıfırlar bire, birler sıfıra dönüşür.

### 8.3 Bina Örneği

Gündelik hayattan örnek bir binadır. Binada ısıtma, güvenlik, enerji, aydınlatma ve su sistemleri vardır. Bunlar birbiriyle etkileşir:

- Isıtma sistemi enerjiyi ve suyu kullanır.
- Aydınlatma enerjiyi kullanır.
- Güvenlik enerjiyi kullanır; yangın güvenliğiyse suyu da kullanıyor olabilir.

Bu sistemler binada durur, bina da kendi içinde bir sistemdir. Yani bunlar binanın alt sistemleridir ve binada değişiklik de yapabilirler. Bina caddede, cadde şehirde, şehir ülkede durur. Hocaya göre bu zincir fiziksel ortam olarak evrene kadar taşınabilir.

<!-- BELİRSİZ: Bina örneğindeki kutu şeması altyazıda yalnızca sözlü geçiyor. Hocanın çizdiği bağlantıların tamamı okunamıyor. -->

### 8.4 Ortam Değişince Sistem de Değişir: Zoom

Bir sistem mutlaka belli bir ortamda işletilmek üzere tasarlanır. Hoca kendi durumunu örnek gösterdi: x86 mimarisinde, Windows çalıştıran bir dizüstü bilgisayardan Zoom ile ders anlatıyor. Zoom; kamera, mikrofon, disk ve ekranla etkileşim içindedir ve internete çıktılar üretir. Dinleyenler de bu çıktıları kendi Zoom sistemlerinde girdi olarak alır.

Tabletten, örneğin iPad'den ya da bir Android telefondan dinleyen birinin kullandığı Zoom ise hocanınkiyle birebir aynı sistem değildir. Aynı görünse ve arka taraftaki pek çok bileşeni aynı olsa da başka bir ortamda çalışır. Ortam etkileşimini yönetebilmek için farklı sistemler olarak tasarlanması gerekir.

## 9. İki Sistem Örneği: Ev Sinema Sistemi ve Restoran

Hoca slaytta bir **ev sinema sistemi** gösterdi. Fotoğrafta hoparlörler (hoca 8 tane saydı), büyük bir ekran, bir amfi ve DVD oynatıcı gibi cihazlar vardı. Burada ses, görüntü ve video sistemleri bir aradadır, tıpkı binadaki ısıtma, güvenlik, enerji ve aydınlatma gibi. Hoca, kutularla çizilince iptidai duran şeyin fotoğrafta etkileyici göründüğünü söyledi. Eskiden çok moda olan bu sistemleri artık herkesin elden çıkarmaya çalıştığını, Netflix ile birlikte izlemenin cepten yapılır hale geldiğini de ekledi.

Bir başka örnek **restoran**dır:

- **Girdiler:** Malzeme, para, alet ve edevat.
- **Çıktı:** Yiyecek.
- **Bileşenler:** Depo, büro, mutfak, yemek salonu, müşteri hizmetleri.

Bu yapı çok farklı şekillerde çizilip ayrıştırılabilir. Önemli olan şudur: Birbiriyle ilişkili, uyum içinde çalışan bileşenler, ara birimler, girdiler, çıktılar ve bir amaç olsun. Bunlar düzgün bir şekilde bir araya geldiğinde bir sistem oluşur.

## 10. Bilgi Sisteminin Tanımı

Sistem tanımından sonra sıra bilgi sistemindedir. Slayttaki tanım işletmeleri öne çıkarır, ama hoca oluşumun işletme olmak zorunda olmadığını, bireysel ya da kamuya ait de olabileceğini söyledi. Bu yüzden "bir oluşum" demek daha doğrudur.

> **Tanım:** Bir oluşumun ihtiyaçlarını desteklemek, çözmesi gereken problemlere destek olmak için verileri toplayan, işleyen ve depolayan; bu süreçte insan, veri, iş akışı ve bilgi teknolojilerinin etkileşimle bir arada çalıştığı ve bileşenler halinde bulunduğu yapılara **bilgi sistemi** denir.

Demek ki bir bilgi sistemi yalnızca girdi, işlem, depolama (storage), çıktı ve veriden oluşmaz. İnsanlar, iş akışları ve farklı bilgi teknolojilerinin etkileşimi de onun parçasıdır. "Veriyi aldık, sunucuda işledik, veri tabanı da sunucuda duruyor, çıktıyı ekrana, yazıcıya ya da borsadaki bir uygulamaya belli bir formatta verdik, devam ediyoruz" demek yetmez. İnsanlar süreçte özellikle yer almak zorundadır.

## 11. Bilgi Sisteminin Bileşenleri: D-Y-İ-V-A

Temel bileşenler beş kaynak türüdür: donanım, yazılım, insan, veri ve ağ.

> **Hocanın vurgusu:** Baş harfleriyle D, Y, İ, V, A. Hoca bunu ezberlemeye gerek olmadığını, çünkü hatırlamasının çok kolay olduğunu söyledi.

### 11.1 Donanım Kaynakları

Elle tutulabilen her şeydir: sunucu, bilgisayar, monitör, klavye, yazıcı, tablet, barkod okuyucu, sanal gözlük gibi aklımıza gelen bütün sayısal ürünler.

### 11.2 Yazılım Kaynakları

Bilgi sisteminde kullanılan bütün yazılım kütüphaneleri, hazır uygulamalar, veriyi düzenlemek, işlemek ve analiz etmek için kullanılan programlar ve bunların süreçleri yazılım kaynağıdır.

Hoca bunu bir üretim fabrikasıyla örnekledi. Fabrikada bir makine parkı vardır. Makinelerin izlenmesi, hata olup olmadığının takip edilmesi, üretimdeki artış ve azalmaların görülmesi, bakım periyotlarının izlenmesi gerekir. Üretim için girdi alınıp depolanmalıdır, yani stok ve satın alma işleri vardır. Muhasebe tarafında fatura takibi, maaş ödemeleri ve para girdi çıktısı vardır.

Bu tesisin sürecini yöneten bir bilgi sistemi geliştirirken kimse muhasebe işlemlerini sıfırdan yazmaz. Muhasebe bambaşka bir uzmanlık alanıdır. Hazır bir muhasebe bilgi sistemi alınır ya da entegre edilir. Benzer şekilde mektup ve rapor üretmek için Word gibi bir uygulama gerekiyorsa oturup editör yazılmaz, örneğin OpenOffice paketi alınıp kullanılır. Sistemin içine gömülen, kullanılan, yararlanılan bütün bu yazılımlar yazılım kaynağıdır.

### 11.3 İnsan Kaynakları

İnsan kaynakları aslında bilgi sisteminin taraflarıdır: sahibi, tasarlayanlar, kuranlar, kullananlar, bakımını yapanlar gibi.

### 11.4 Veri Kaynakları

Kullanılan ve üretilen veriler nerede duruyorsa orası veri kaynağıdır: bir veri tabanı, bilgi tabanı, veri ambarı, dağıtık bir yapı, NoSQL dediğimiz bir ortam ya da Mongo Atlas gibi bir yer. Verinin nerede, nasıl tutulduğu, depolandığı ve nasıl erişildiği de bu başlığa girer.

> **Ek bilgi (derste anlatılmadı):** NoSQL, ilişkisel tablo modeli dışındaki veri modellerini kullanan veri tabanlarının genel adıdır. Hocanın andığı Mongo Atlas ise büyük olasılıkla MongoDB'nin bulut üzerinde sunulan veri tabanı hizmetidir.

### 11.5 Ağ Kaynakları

Bileşenler entegre ya da çok dağıtık olabilir. Her durumda haberleşme, yani ağ protokolleri kullanılarak bir arada çalışacaklardır. Bu yüzden onları bir araya getiren kaynaklara ihtiyaç vardır. İşletme içi ve dışı birimlerin bağlandığı yapıları oluşturan bu kaynaklara network ya da ağ kaynakları denir.

## 12. Alt Sistemler ve Katmanlı Yapı

Hoca slaytta üretim yapan bir işletme örneği gösterdi. Bir sipariş sistemi vardır: Siparişler gelir, karşılama işlemleri ve akış verileri oluşur. Bir stok sistemi vardır: Stoka göre sipariş üretimi ya da hangi ürünün üretileceği planlanır. Ayrıca üretim alt sistemi ve ham madde stok alt sistemi bulunur.

Bunlar birer modül olabilir. Sistem çok büyükse birer alt sistem olurlar ve bu alt sistemlerin içinde de kendi modülleri bulunabilir. Bir modülün çıktısı başka bir modüle girebilir, modüller birbiriyle etkileşebilir. Hocanın vardığı sonuç şudur: Bütün sistemler aslında katmanlıdır.

<!-- BELİRSİZ: Üretim örneğindeki diyagram ve hocanın fareyle gösterdiği akışlar altyazıda "şuraya giriyor, buna giriyor" diye geçiyor. Hangi modülün hangisine bağlandığı okunamıyor. -->

## 13. Sistemlerin Teorik Özellikleri

Hoca işin teorik tarafını şu maddelerde topladı.

**1. Girdiyi çıktıya dönüştürür.** Bilgi sistemleri açısından bu, verilerin bilgiye dönüştürülmesidir.

**2. Disiplinler arasıdır.** Bir daldaki ürün başka bir dalda kullanılabilir. Çok farklı disiplinlerdeki sistemler birbiriyle etkileşebilir.

**3. Elemanları arasında etkileşim vardır.** Bir bileşendeki bozulma ya da değişim, ona bağlı bileşenleri de mutlaka etkiler.

> **Hocanın vurgusu:** Bu, sistem tasarlarken en dikkat etmemiz gereken noktalardan biridir: Değişimlerden mümkün olduğunca kendimizi korumak.

Bir şey değiştiğinde ona bağlı olan her şeyi gözden geçirmek ve güncellemek gerekir. Onlara bağlı başka bileşenler de vardır, onların da güncellenmesi gerekir. Hocanın benzetmesi suya atılan taştır: Dalgalar büyüye büyüye gider ve sonunda bütün bileşenlere bakmak zorunda kalınır. Bu yüzden mümkün olduğunca değişimlerden etkilenmeyecek tasarımlar yapmaya gayret edilir.

**4. Farklı elemanlardan oluşur.** Bir taşımacılık sistemi demir yolunu, deniz yolunu ve hava yolunu bir arada kullanabilir. Zoom'un masaüstü ve mobil uygulamaları da bir arada kullanılabilir.

**5. Hiyerarşiktir.** Hoca bundan derste defalarca söz ettiğini hatırlattı.

**6. Ortama göre düzenlenir.** Zoom örneğindeki gibi Windows, mobil, Android ve tablet sürümleri ayrıdır. Windows'ta çalışan bir sistem Linux'a da doğrudan taşınamayabilir. Bunun için bir değişiklik, bir adaptasyon gerekir. Burada ortam olarak işletim sistemi kastedilmektedir.

Hoca bu maddede ortamla olan ilişkiye entropi dendiğini söyledi. Entropi kavramının veri ve bilgi bilimine gittiğini ve isteyenlerin bu tarafı araştırabileceğini ekledi.

> **Ders sonrası not:** Hoca "ortamla olan ilişkiye entropi diyoruz" dedi. Doğrusu büyük olasılıkla şudur: Sistem teorisinde entropi, sistemin düzensizliğe ve çözülmeye doğru gitme eğilimidir. Açık sistemler ortamdan enerji, madde ya da bilgi alarak bu eğilimi yavaşlatır; bu karşı eğilime negatif entropi denir. Yani ortamla etkileşim entropinin adı değil, entropiyle başa çıkmanın yoludur.

> **Ek bilgi (derste anlatılmadı):** Hocanın değindiği bilgi bilimi tarafında entropi, Shannon'ın bilgi kuramında bir kaynağın ürettiği iletilerdeki ortalama belirsizliğin ölçüsüdür.

**7. Amaca yöneliktir.** Her sistemin belli bir amacı olmalıdır. Amacı olmayan sistem olmaz.

## 14. Ders Sonrası Alıştırma ve Soru

Hoca dersi bir alıştırma önerisiyle kapattı. Bu derste kutucuklu, terliksi hayvan biçimli ya da fotoğraflı çok hızlı örnekler görüldü. Şimdi kendimize bir bilgi sistemi seçip şu soruları düşünmemizi, hatta istediğimiz biçimde yazmamızı istedi:

- Bileşenleri nelerdir?
- Ortamı nedir, sınırı nedir?
- Ara birimleri nelerdir?
- Nasıl işler, ne gibi süreçleri vardır?
- Tarafları, yani insan kaynakları kimlerdir?
- Ağ kaynakları nelerdir?

Hocanın kitabındaki çok basit hastane sistemi örneği gibi bir sistem de seçilebilir. Hoca bunu sistem, sistem bileşenleri ve teorik özellikler kavramlarını oturtmak için bir "beyin jimnastiği" olarak önerdi.

**Soru:** Hangi yazılım dillerini kullanabiliriz? **Cevap:** Dil konusunda bir kısıt yok. Size uygun olanı, daha doğrusu fizibilite çalışması sonucunda uygun gördüğünüz dili kullanabilirsiniz.

## Dersin Toparlaması

Bu derste "sistem" kelimesinin sözlük anlamlarından yola çıkılarak bir bilgi sisteminin düzen, amaç, süreç, bileşen, model farkı ve bütünlük taşıması gerektiği görüldü. Ardından sistem tanımlandı: amacı olan, birbiriyle ilişkili parçalardan oluşan, girdi ve çıktıları olan, sınırları belirlenmiş bütün yapı. Bileşen, değişken, parametre, ilişki, sınır, ara birim, kısıt, ölçüt, ortam ve geri besleme kavramları bu tanımın üzerine oturdu. Sistemlerin ortamlarına bağlı olduğu, genellikle başka bir sistemin üzerinde durduğu ve katmanlı olduğu örneklerle gösterildi.

Bilgi sistemi ise veriyi bilgiye dönüştüren, donanım, yazılım, insan, veri ve ağ kaynaklarından oluşan ve bir bilgisayar programından ölçek bakımından ayrılan bir yapı olarak tanımlandı. Tasarımın temel kaygısı olarak da değişimlerin bağlı bileşenlere yayılmasını sınırlamak öne çıktı. Gelecek hafta bilgi sistemlerinin tipleri, tarafları ve bilgi sistemi geliştirme sürecinin temeli ile bunu çeşitlendiren yeni yaklaşımlar görülecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
