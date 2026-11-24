# Ders 13 Genişletilmiş Notu: Yazılım Proje Yönetimi: Planlama, Risk Yönetimi, Kişi Etkenleri, Ölçüm ve Maliyet Tahmin Yöntemleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Yazılım Proje Yönetimine Giriş
- 2. Proje Ölçeği ve Araçlar
- 3. Planlama Yaklaşımları ve İlkeleri
- 4. Risk Yönetimi
- 5. Proje Yönetiminde Kişi Etkenleri
- 6. Proje Yönetiminde Ölçüm
- 7. Maliyet Tahmin Yöntemleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Yazılım Proje Yönetimine Giriş

Bu derste yazılım proje yönetimiyle ilgili anahtar noktalar işlendi. Hoca, ilk haftalarda yazılım projelerinin başarı oranının ancak %50 dolayında olduğunun konuşulduğunu hatırlattı ve bu başarısızlığın arkasındaki zorlukları sıraladı (ekrandan, 00:25:00).

### 1.1 Yazılım projelerindeki zorluklar

- **Yazılım geliştirmedeki zorluklar:** Yazılım geliştirmek başlı başına entelektüel, zihinsel çaba gerektiren bir iştir.
- **Ölçek büyüklüğünden kaynaklanan zorluklar:** Çözülecek problemin, ortaya çıkacak yazılımın ve projede çalışacak kişilerle bütün paydaşların sayıca çokluğu. İşe ne kadar çok kişi girerse onları organize biçimde çalıştırmak ve onlarla organize biçimde etkileşmek o kadar zorlaşır. En iyi uygulamalar (best practices) ve yazılım araçlarıyla bu ölçek sorunları çözülmeye çalışılır, ama ölçek sürekli büyüdüğü için bu tempoya ayak uydurmak gerekir.
- **Kestirimdeki zorluklar:** Bir projenin ne kadar sürede tamamlanacağına ilişkin istatistiksel yöntemler vardır (dersin sonunda işlendi), ama bunlarla da yüksek hassasiyette tahmin yapmak kolay değildir. Ölçme sonuçlarını değerlendirmek de zordur.
- **İnsanlarla çalışmadaki zorluklar:** İnsanlar mantıklı varlıklar olsa da duygusal yanları vardır; farkında olmadıkları eğilimlerden kaynaklanan sorunlar çıkabilir. Farklı ülkelerden, farklı çalışma kültürlerine sahip insanlarla çalışmak da ayrıca zordur.
- **Teknolojideki değişimler:** Teknoloji sürekli değişir ve ona uyum sağlamak kolay değildir.
- **Gereksinimlerdeki değişimler:** Kaçınılmazdır; daha önce de vurgulanmıştı.
- **Politik değişimler:** Hoca burada politikanın yalnız ülke yönetimi anlamında olmadığını, şirket politikalarının da en az onun kadar etkili olduğunu söyledi.
- **Mali değişimler:** Küresel, ülke ya da firma düzeyindeki mali dalgalanmalar. Bunları önceden tahmin etmek ve gerçekleştiklerinde etkilerini azaltmak kolay değildir.

Yazılım proje yönetimi, sayılan bu zorlukların çözümüne odaklanan ilgi alanıdır.

### 1.2 Proje yönetiminin ilgi alanları

Önem sırasına göre proje yönetiminin ilgi alanları şunlardır (ekrandan, 00:25:00):

1. **Kişiler**
2. **Ürün**
3. **Süreç**
4. **Proje**

> **Hocanın vurgusu:** Odak noktasında her zaman ilk sırada kişiler vardır. İşi ortaya çıkaracak olan kişilerdir. Diğer alanlarda ne kadar disiplinli ve mükemmel olunursa olunsun, kişiler doğru yönetilemiyor, bir takım ruhu etrafında hedefe kenetlenemiyor ve yeterince güdülenemiyorsa iş başarısız olur.

Kişilerden sonra ürün gelir: amaç işe yarayan, kullanışlı, kaliteli bir ürün ortaya çıkarmaktır. Üçüncü sırada kullanılan yazılım geliştirme süreci ve alt adımlarının verimli, doğru yürütülmesi vardır. En sonda projenin bütünü gelir. Hoca, adı "proje yönetimi" olduğu için ilk odağın proje sanılmaması gerektiğini, projenin son sırada olduğunu özellikle belirtti.

### 1.3 Disiplinler arası bir alan

Yazılım proje yönetimi disiplinler arası bir iştir ve üç ayrı alanda bilgi ve deneyim ister: yazılım mühendisliği, projenin problem alanı ve proje yönetimi. Hoca bunu üç ayaklı bir "sacayağı" olarak nitelendirdi; yazılım proje yönetimi bu üç alanın kesişimidir ve bu yüzden zor bir iştir. <!-- BELİRSİZ: Bu slaytın karesi yok; üç alanın adları altyazıdan tam duyulmuyor, "problem alanı" bağlamdan çıkarıldı. -->

## 2. Proje Ölçeği ve Araçlar

Yazılım projesinin büyüklüğüne göre uygulanacak yönetim ve denetimin düzeyi, kullanılacak araç tipleri ve teknoloji gereği farklılık gösterir. Hoca aşağıdaki sınırların keskin değil, ortalama değerler (rule of thumb) olduğunu söyledi (ekrandan, 00:30:00):

- **Küçük ölçekli projeler:**
  - Çok küçük: 1-2 kişi içeren çok kısa süreli (1-2 ay) projeler.
  - Küçük: 2-3 kişi içeren kısa süreli (2-3 ay) projeler.
  - Basit bir kullanıcı uygulama programı tekniğiyle düzenlenebilir. Hoca, basit bir görev listesinin, hatta hangi işin ne zaman yapılacağını bir hesap tablosunda izlemenin yeterli olabileceğini söyledi.
- **Büyük ölçekli projeler:**
  - 5-20 kişilik bir ekip tarafından 2-3 yılda tamamlanabilir.
  - Çok sayıda alt sistemden oluşur.
  - Başka sistemlerle tümleştirme gereksinimleri vardır.
  - İş planlama ve kod yönetim uygulamalarının kullanılması zorunludur.

Hocaya göre günümüzde Ar-Ge destekli yazılım projelerinde süreler daha çok 6 ay ile 1 yıl arasındadır. Bunun nedeni, ortaya çıkacak ürünün kendi içinde anlamlı ve yararlı iş yapabilen fazlara ayrılmasıdır: 4 ya da 6 fazlık bir ana planda her faz ayrı bir proje olarak ele alındığında 6 ay gibi görünür, bütününe bakıldığında 2-3 yıla çıkabilir. Ayrıca günümüzün hızlı temposunda proje süreleri kısalma eğilimindedir.

### 2.1 İş planlama yazılımları

İş planlama yazılımları proje kapsamında hangi işlerin, kimler tarafından, ne zaman yapılacağını planlamaya yarar. İş kalemleri arasında "şu bitmeden şu bitmez" ya da "şunun belli bir kısmı tamamlanmadan şuna başlanamaz" gibi bağımlılıklar vardır ve bunları gözeterek planlama yapmak kolay değildir. IBM Rational ya da Microsoft Azure gibi bütüncül yazılım geliştirme ortamlarında bu işe yarayan bileşenler bulunduğu gibi bağımsız açık kaynak araçlar da vardır.

### 2.2 Kod yönetim yazılımları

Git ve SourceForge gibi bir kod havuzu oluşturulur; havuza katkı belirli kurallara bağlanır, belirli eşikleri geçemeyen kod havuza kabul edilmez ve proje yöneticisi istediği anda yeni sürümler oluşturup önceki sürümleri dondurarak saklayabilir.

Hoca bunun hayat kurtarıcı olabileceği bir durum anlattı: Aktif olarak geliştirilen bir projede kullanıcıya demo yapılacakken, yeni eklenen bazı kodlar smoke testin başarısız olmasına yol açabilir. Bu durumda smoke testi geçmiş önceki sürüme hemen geçip demoyu onunla yapmak mümkün olur.

## 3. Planlama Yaklaşımları ve İlkeleri

Slaytta ilk olarak şu hatırlatma vardı: Temel amacın kullanıcılara bir yarar sağlamak olduğunu hiçbir aşamada unutmayın (ekrandan, 00:35:00).

### 3.1 Üç planlama yaklaşımı

- **Basitlik yaklaşımı:** Geleceğin getireceği değişiklikler çoğu zaman ayrıntılı planlama gereğini ortadan kaldırır. Ayrıntılı planlar değişikliğe daha hassastır, zamanla hızla geçersizleşir ve yeniden ağır ağır plan yapmak gerekir; bu iş sürekli tekrarlanır.
- **Geleneksel yaklaşım:** Planlama proje için bir yol haritası belirler; harita ne kadar ayrıntılıysa kaybolma olasılığı o kadar düşer.
- **Çevik yaklaşım:** İki tarafın da haklı olduğu noktalar vardır. Ön hazırlık gereklidir, ancak asıl harita proje ilerledikçe çizilir (ekrandan, 00:35:00).

Hoca kendisinin çevik yaklaşımdan yana olduğunu, ancak yazılım evinin çalışma süreçlerine ve projenin ölçeğine göre diğer ikisine de kayılabileceğini söyledi: küçük ölçekli, hızlı değişen projelerde basitlik yaklaşımı; şelale modeliyle yürüyen daha büyük projelerde geleneksel yaklaşım daha uygun olur.

### 3.2 Planlama ilkeleri

Hangi yaklaşım seçilirse seçilsin akılda tutulması gereken ilkeler şunlardır (ekrandan, 00:40:00):

- **Projenin sınırlarını belirleyin:** Nereye gideceğinizi bilmezseniz kaybolursunuz. Ne kadar ilerlemeniz gerektiğini bilmiyorsanız ya az ilerleyip yarı yolda kalırsınız ya da gereksiz yere "çöllerde kaybolursunuz".
- **Müşteriyi planlama eylemlerine katın:** Öncelikleri, sınırları ve zamanlamayı müşteri belirler; ancak gerçekçiliği korumak amacıyla yazılım ekibi pazarlık yapar. Müşteri "şu kadar sürede şuna ihtiyacım var" der; o süre yeterli değilse ya süre uzatılır ya da iş alt fazlara bölünür. Böylece planın ayakları yere basar. Bunun ayrıntısı kullanılan sürece ve iki kurumun kültürüne göre değişir.
- **Planlamanın doğası yinelemelidir:** Plan asla taşa yazılmaz; planlar değişecektir.
- **Bildiklerinizi kullanarak kestirimde bulunun:** Bilginin kapsamı, doğruluğu ve belirginliği kestirimin doğruluğunu doğrudan etkiler. Hoca, çeşitli proje tahmin yöntemleri olsa da geçmiş deneyime dayanan tahminlerin de matematiksel modellere yakın sonuçlar verebildiğini, bu yüzden tecrübenin önemli olduğunu söyledi.
- **Planın her aşamasına risk değerlendirmesini ekleyin:** Teknik, mali, kişisel, politik riskler.
- **Gerçekçi olun: Yazılımcı süpermen veya robot değildir.** Herkesin belli bir kapasitesi vardır. Bu kapasite çok çalışmayla ve güdülemeyle bir noktaya kadar artırılabilir, ama sınırsız artmaz.

### 3.3 Planlama ayrıntı düzeyi ve izleme

Planlar ince ayrıntılı mı, yoksa ana hatlarıyla mı yapılmalı? Hoca ikisinin de yapılması gerektiğini söyledi: **kısa vadeli planlar ince ayrıntılı, uzun vadeli planlar daha genel ayrıntıyla** yapılır. Uzun vadeli planların zamanla değişme olasılığı daha yüksek olduğu için en mantıklı çözüm budur. Zaman ilerledikçe genel bırakılan noktalar o anki duruma göre ince ayrıntıya geçirilir.

Diğer noktalar:

- Kalite güvence eylemleri mutlaka plana eklenmelidir.
- Değişikliklerin nasıl kabul edileceğinin müşteriyle sözleşmeye bağlanması, iki taraf için de en az baş ağrıtan yöntemdir; bu konuda standartlar ve öneriler vardır, çevik süreçlerde bu zaten sürecin bir parçası olarak tanımlanmıştır.
- Plan yapılıp bırakılmaz, sürekli izlenir: Planın içinde miyiz, sapıyor muyuz? Sapma varsa nedeni nedir? Gereksinimlerdeki zorunlu değişikliklerden kaynaklanıyorsa yeniden planlama gerekebilir.

<!-- BELİRSİZ: Bu bölümün (yaklaşık 00:40:00-00:41:50) slaytının karesi yok; kısa/uzun vadeli plan, kalite güvence ve değişiklik yönetimi maddeleri altyazıdan alındı. -->

> **Hocanın vurgusu:** Sınırların önemine örnek olarak hoca Charles Babbage'ın Analitik Makinesi'ni (Analytical Engine) verdi. Makinenin Babbage'ın yaşamı boyunca tamamlanamamasının en büyük nedeni, nerede duracağını bilmemesiydi: "şu da olmalı, bu da yapılabilir" diye sürekli yeni özellikler eklenip tasarım değiştikçe ortaya çalışan bir ürün çıkmadı. Çıkabilseydi insanlık bilişim teknolojileriyle çok daha erken tanışabilirdi; hoca, bunun neye yol açabileceğini hayal eden "steampunk" adlı bir bilim kurgu alt türü olduğunu da ekledi.

## 4. Risk Yönetimi

Hoca, risk değerlendirmesinin proje ödevleri kapsamında da yapıldığını hatırlatıp konunun ayrıntılarına geçti.

### 4.1 Risk ile uğraşma taktikleri

Slayttaki maddeler şunlardır (ekrandan, 00:45:00):

- **Sonradan (Reactive):** Risk gerçekleşince çaresine bakmak.
- **Önceden (Proactive):** Riskleri daha gerçekleşmeden önlemeye çalışmak.
- "Nasrettin hoca: Kızını dövmeyen dizini döver!"
- İtfaiyeci ve işçi/elektrikçi.
- Derste proaktif yaklaşımlar işlenir.

Hoca itfaiyeci benzetmesini şöyle açtı: Bir binada elektrik altyapısındaki bir sorun yüzünden yangın çıkarsa itfaiyeci gelir, yangını söndürür ve kayıpları azaltmaya çalışır; bu reaktif yaklaşımdır. Oysa binanın inşaatı sırasında işçiler ve teknisyenler kablolamayı düzgün yapsaydı, elektrikçiler sigorta ve elektrik panolarını dikkatle bağlasaydı, planı yapan elektrik mühendisi planı çeşitli simülasyonlardan geçirseydi ve müteahhit kaliteli malzeme kullansaydı, yani herkes riskin varlığını önceden bilip işini ona göre yapsaydı, itfaiyecinin reaktif müdahalesine gerek kalmayacaktı.

### 4.2 Risk tanımı

Risk tanımında tam bir uzlaşı yoktur. Uzlaşılan iki özellik şudur (ekrandan, 00:45:00):

- **Olasılık:** Belirli bir risk ortaya çıkabilir ya da çıkmayabilir; %100 olasılıkla ortaya çıkacak bir risk yoktur.
- **Kayıp:** Risk ortaya çıktığında istenmeyen sonuçlar ve kayıplar doğurur.

Kayıpların nereyi etkilediğine göre üç genel risk çeşidi vardır: **proje riskleri, teknik riskler ve iş (işletme) riskleri**. Farklı risk sınıflandırmaları ve risk işleme önerileri için SEI, ISO, ANSI, makaleler ve kitaplara bakılabilir. Hoca bunlardan bazılarının belirli problem alanlarına, ekip özelliklerine ya da süreçlere özgü olabileceğini; sizin durumunuz onlara uyuyorsa önerilerini uygulamanın yararlı olacağını söyledi.

### 4.3 Risk çeşitleri

Slayt içeriği (ekrandan, 00:50:00):

- **Proje riskleri:** Proje planını tehdit eder. Gerçekleşirse zamanlama ileri tarihlere sarkar ve maliyet artar. Örnekler: bütçe riskleri, zaman riskleri, personel riskleri.
- **Teknik riskler:** Üretilen yazılımın kalitesini ve zamanında bitirilmesini etkiler. Gerçekleşirse yazılımı gerçeklemek zorlaşır ya da imkânsızlaşır. Çözümleme, tasarım, gerçekleme ve bakım aşamalarıyla ilgilidir. Örnek: "son teknoloji" ürünler yüksek teknik riske sahiptir: Bug'lar var mı? Dokümantasyonu tam mı? Bu teknolojiyi tam anlayabildik mi? Yarın da bu teknoloji hayatta olacak mı?
- **İşletme riskleri:** Pazar riskleri (ürüne talep olur mu? Slayttaki örnek: tıraş bıçağı, tıraş makinesi), satış riskleri (pazarlama ekibi ürünü nasıl satacağını biliyor mu?). Bunlar MIS/MBA konularıdır.

**Proje riskleri.** Süre uzadığında projede çalışan personele daha uzun süre ödeme yapılır; kadrolu personel olsa bile o projeye ayrılan iş gücü uzadığı için projenin maliyeti artar. Bütçe riskine örnek: şirketin nakit akışında sıkıntı varsa ve projenin ilerlemesi için gereken nakit sağlanamıyorsa proje batar. Zaman riskleri çoğunlukla kestirim hatalarından kaynaklanır. Hoca personel riskinin çok önemli olduğunu, yazılım alanında nitelikli personeli bulmanın ve kurumda tutmanın giderek zorlaştığını, gençlerde hızlı iş değiştirme eğilimi de olduğunu ve insan kaynakları ekiplerinin bununla ciddi biçimde uğraşması gerektiğini söyledi.

**Teknik riskler.** Hoca bunların proje riskleriyle karıştırılmaması gerektiğini vurguladı. Örnek olarak ilk kez kullanılacak bir kütüphane ya da çatıyı (framework) verdi. Öğrenme eğrisi yüksekse onu projede işe yarayacak düzeyde öğrenmek ek çaba ister. Plana bu çaba için zaman ayrılmış olsa bile beklenenden zor çıkabilir; o zaman teknik risk gerçekleşmiş olur. Son teknoloji ürünlerde risk daha da yüksektir. Hoca şöyle bir senaryo anlattı: Büyük veri uygulamalarında genelde Apache Kafka kullanılırken yeni çıkmış, çok yetenekli görünen açık kaynak bir ürün kullanılmaya karar veriliyor. Ancak:

- Yeni olduğu için hatalarını daha önce kimse fark etmemiş olabilir; hatalar ilk kez sizin projenizde çıkabilir. Açık kaynaksa kendiniz çözmeye çalışabilirsiniz, ama plana böyle bir çaba konmamıştır.
- Teknik dokümantasyon varsa bir noktaya kadar destek olur, ama okuyup anlamak da zaman alır; belki hiç bulunamaz.
- Bu teknolojiyi tam anlayıp ona uygun biçimde kullanabiliyor muyuz?
- Belki en önemli soru: Yarın bu teknoloji hayatta olacak mı? Örneğin 0.8 sürümü çok yetenekli görünen bir ürün birkaç yıl içinde 1.0 sürümüyle çıkar, sonra kimse projeye destek vermez olur. Bakımı yapılmayan bu ürün zamanla yeni araç ve tekniklerle uyumsuz hale gelir ve kullanımından vazgeçmek zorunda kalınır; yapılan yatırım boşa gider.

**İşletme riskleri.** Hoca bu konularda uzman olmadığını, bunların daha çok yönetim bilişim sistemleri (MIS) ve işletme yüksek lisansı (MBA) konuları olduğunu söyledi. Pazar riski: Ortaya çıkacak ürünün bir pazarı var mı, talep olur mu? Satış riski: Pazarlama ekibi (varsa; küçük girişimlerde olmayabilir) ürünün güçlü yönlerini, rakiplerden farklarını ve müşteriye ne kazandıracağını yeterince biliyor mu? Bilmiyorsa satamaz.

### 4.4 Risk tablosu oluşturma

Slayt içeriği (ekrandan, 00:55:00):

- Tüm ekip ya da risk işleme ekibinin tüm üyeleri olası riskleri adlandırsın.
- Risklerin çeşitlerini belirleyin (proje, teknik, iş).
  - Herkes kendi uzmanı olduğu risk alanında riskleri alt türlere ayırsın.
  - Örnek (teknik): planlanandan daha düşük yeniden kullanım, kullanılan gereçlerde deneyimsizlik vb.
- Risklerin gerçekleşme olasılıklarını belirleyin: düşük, orta, yüksek gibi kategoriler.
- Risklerin etkilerinin büyüklüğünü değerlendirin: "Küçük bir sıyrık, haydi gayret, siz beni bırakın", "küçük kıyamet, büyük kıyamet".
- Bu bilgilerden bir tablo yapın: ID, ad, çeşit, olasılık, etki.
  - Listeyi bir yerden sonra kesin (düşük olasılık ve etkileri atın).
  - Ele alacağınız riskler için risk bilgi sayfaları oluşturun. Bu sayfa risk hakkında bilgiler ve önleme yollarını, önlenemeyen riskler için ise alternatif planları içersin.

Hoca, risk işleme biriminin genelde farklı departmanlardan kişilerin bir araya gelmesiyle (cross-cutting) oluştuğunu, herkesin kendi uzmanlık alanındaki riskleri daha çok ortaya çıkarmasının beklendiğini söyledi.

Planlanandan düşük yeniden kullanım riskini şöyle açıkladı: Yeni proje eski projelere benzediği için eski koddan yararlanılabileceği fark edilmiş ve yeni kodun %30'unun mevcut kod portföyünden karşılanacağı planlanmış olsun. Hoca bu oranın uluslararası alanda da fayda-maliyet açısından genelde ulaşılabilecek en yüksek değerlerden biri olduğunu belirtti. Bu oranda yeniden kullanım yapılamayacağı, yani tahminin yanlış olduğu ortaya çıkarsa ya ek mesai yapılacak ya plan ötelenecek ya da başka bir önlem alınacaktır.

Olasılık ve etki 3, 4 ya da 5 basamaklı Likert ölçeğiyle değerlendirilebilir: 3 basamakta düşük-orta-yüksek, 5 basamakta çok düşük, düşük, orta, yüksek, çok yüksek.

### 4.5 Olasılık-etki grafiği

Örnek tabloda 9 risk belirlenmiş; her riskin adı, çeşidi (proje, teknik, iş), etkisi (küçük, orta, büyük) ve gerçekleşme olasılığı (düşük, orta, yüksek) 3 basamaklı ölçekle yazılmıştır. Tablodan sonra bir eksende olasılık, diğer eksende etki (zarar) olacak biçimde bir grafik çizilir ve riskler ID'leriyle yerleştirilir. Grafik dört bölgeye ayrılır:

- **Sağ üst (olasılık yüksek, etki büyük):** Bu bölgedeki riskler (örnekte 9 numaralı risk) mutlaka izlenmelidir.
- **Sol alt (olasılık düşük, etki küçük):** Örnekte 4, 7 ve 8 numaralı riskler. Bunlar hiç izlenmez; çünkü risk izleme ayrı bir proje etkinliğidir, çaba ister ve bu bölgede harcanan çaba yeterli getiri sağlamaz. Hoca bunu "attığın taş ürküttüğün kurbağaya değmez" deyimiyle açıkladı.
- **Sağ alt (olasılık yüksek, etki küçük):** Ekip "bunu göze alırım" diyorsa işlemeyebilir.
- **Sol üst (olasılık düşük, etki büyük):** Örneğin firmanın mali durumu iyi değilse ve bu yazılımın satış gelirleri hayatta kalmak ve yeni projelere yatırım için şartsa, ya da teknik riskleri yüksek bir projeyse, "olasılığı düşük ama gerçekleşirse bizi öldürür, izleyeceğiz" denebilir. Denmeyebilir de.

Diğer köşelerdeki riskleri işleyip işlememek projenin, yazılım evinin ve müşterinin durumuna göre seçilir. İzlenmesine karar verilen her risk için ayrıntılı risk bilgi sayfası hazırlanır.

<!-- BELİRSİZ: 9 riskli örnek tablo ve grafiğin karesi yok; tablo satırları aktarılamadı, risk numaralarının bölgelere dağılımı altyazıdan alındı. -->

### 4.6 Örnek risk bilgi sayfası

Ekrandaki örnek risk bilgi sayfası şöyledir (ekrandan, 01:00:00):

```text
RİSK #09: Pazarlama
Olasılık: Yüksek      Etki: Büyük      Türü: Ticari
Açıklama: Firmamız sadece yazılım geliştiricilerden oluşan çekirdek kadroyla
çalışmaktadır. Ortaya çıkaracağımız yazılımın piyasada çok fazla alternatifi vardır.
İşaretleri:
1. Müşteri adayları ile görüşmede dinleyicilerin ilgisizliği ve "Biz zaten X
   yazılımını kullanıyoruz. Neden sizi seçelim?" türü yorumları.
2. Bakım aşamasının ilk altı aylık süresince ürünümüzün kendisini amorti etme
   oranının %50'nin altında kalması.
Önlemler:
1. Bir programcımıza MBA yaptırmak.
2. Gereksinim mühendisliği aşamasında konu uzmanlığı odaklı danışmanlık hizmeti almak.
3. Bir ya da iki firma ile pilot uygulama yapmak ve bu firmalara ürünü özel indirim ile satmak.
```

**İşaretler.** Riskin gerçekleşmeye yaklaştığının işaretleri (sinyalleri) mutlaka belirlenip yazılmalıdır; risk yönetimi projeyi kapsayan bir etkinliktir ve bu işaretlerin görülmeye başlayıp başlamadığı izlenir. Başladıysa önlemler devreye sokulur.

Hoca birinci işaretin biraz öznel olduğunu söyledi: Dinleyicinin ilgisizliğinin başka nedenleri olabilir; o gün başka bir sorunu olabilir, belki ürünü aslında beğenmiştir. İkinci işaret ise nesneldir: süre, miktar ve oran bellidir. Yazılımın bir yıl içinde kendini tamamen amorti etmesi ve sonrasında kâra geçmesi planlandıysa, bu bir yılın yarısı olan ilk altı ayda amorti oranının yaklaşık %50, ilk üç ayda yaklaşık %25 olması beklenir. Bu ara hedeflerden çok geride kalındıysa önlemleri devreye sokmanın zamanı gelmiştir.

> **Hocanın vurgusu:** Bu reaktif değildir. Hedefe henüz ulaşılmadı; hedefe giden yolda ara noktalarda kontrol yapılıyor ve sürekli takiple önlem alınıyor. Bu, proaktif planlamadır.

**Önlemler.** Bir programcının akşam saatlerinde MBA yapmasına izin verilebilir, sınav günlerinde izin ve hatta maddi destek sağlanabilir. Konu uzmanlığı odaklı danışmanlık daha önce gereksinim mühendisliğinde de anılmıştı. Pilot uygulama ise bir kazan-kazan durumudur: Sınama konusunda görüleceği gibi bir ürün ne kadar çok ve ne kadar farklı kişi tarafından, sahada gerçek çalışma ortamlarında sınanırsa hataların bulunma ve erken bulunma olasılığı o kadar artar. Hataların önlenmesiyle elde edilecek tasarrufun ve kârın bir kısmı, saha sonuçları ve uzman kullanıcı bildirimi sunan pilot müşterilerle özel indirim yoluyla paylaşılmış olur.

## 5. Proje Yönetiminde Kişi Etkenleri

### 5.1 Takım yöneticisi

Proje yönetiminin üç ayrı konuda bilgi gerektirdiği daha önce söylenmişti; takım yöneticisi de bu konularda deneyimli ve bilgili olmalıdır. Slayt içeriği (ekrandan, 01:20:00):

- **Takım yöneticisi:**
  - Teknik ekibin bir parçası olduğundan teknik yetenekleri yüksek olmalıdır.
  - Ağırlıklı olarak insanlarla ilgili eylemlerde bulunacağından sosyal ve yönetimsel yetenekleri de yüksek olmalıdır.
- **İyi bir teknik yöneticinin özellikleri:**
  - Teknik ekibi istekli kılabilmelidir.
  - Kişileri ve yazılım geliştirme sürecini, üzerinde çalışılan ürüne/ürün parçasına göre düzenleyebilmelidir; düzenleme küçük veya büyük ölçekte olabilir.
  - Ürün ve süreç sınırları belli olsa da ekibini yaratıcı fikirler üretmeye teşvik edebilmelidir.
  - İyi bir sorun çözücü olmalıdır: hem teknik hem yönetimsel sorunlarla uğraşabilmeli, sorunlara tanı koyabilmeli ve uygun çözüm üretebilmeli, seçilen çözüm tıkandığında ısrarcı olmamalıdır.
  - Sorumluluk alabilmelidir.

**Teknik ve teknik olmayan proje yöneticisi.** Hoca hem yurt içinde hem yurt dışında iki yaklaşım görüldüğünü söyledi. Ders kapsamında daha çok teknik proje yöneticisi anlatılır. Teknik olmayan proje yöneticisi projenin genel yönetiminden ve izlenmesinden sorumludur. Endüstri mühendisliği, işletme ya da işletme mühendisliği gibi alanlardan gelebilir; bazen yazılımın konu alanında uzmandır (örneğin CAD/CAM yazılımı üreten bir firmada makine mühendisi). Aynı anda birden fazla projeyi yönetebilir; süreçleri izler, değerlendirir, önlem alır. İki yaklaşımın da avantajları ve dezavantajları vardır. Bazen ekibin içindeki, teknik risk ve konulara odaklanmış bir teknik yönetici ile genel süreci yöneten bir proje yöneticisi birlikte çalışır. Bu durumda sınırlar çok iyi belirlenmelidir; yoksa yetki çatışmaları çıkar ve bu, takım ruhunu bozan önemli bir etkendir.

**Yaratıcı fikirler.** Hoca bunun "projenin sınırlarına sadık kalın" ilkesiyle çelişmediğini açıkladı. Yaratıcı fikirler teknik zorlukların çözümüne, olası değişikliklerden etkilenme olasılığını azaltmaya ya da işi daha verimli yapmaya yönelik olabilir; gereksinimlerde bir şeyin daha iyi yapılabileceği fark edilirse müşteriye danışarak değiştirme önerisi de olabilir.

**Sorun çözücülük.** Sorunlar teknik, yönetimsel ya da kişisel olabilir. Ayrı bir genel proje yöneticisi varsa teknik olmayan yönetimsel sorunları o üstlenebilir. Hoca teknik yöneticiden çok şey beklendiğini ve bunların kolay olmadığını söyledi. Görüştüğü bir teknik yöneticinin, kendini "bir yanda müşteri, bir yanda teknik ekip arasında sıkışmış bir sünger" gibi hissettiğini söylediğini aktardı; çünkü müşterinin ve teknik ekibin çıkarları kimi noktada çatışabilir.

### 5.2 Teknik ekip ve takım ruhu

Slayt içeriği (ekrandan, 01:25:00):

- **Yazılım geliştirme ekibi (teknik ekip) takım ruhuna uygun kişilerden oluşmalıdır:**
  - Takım üyeleri birbirine saygı duymalıdır.
  - Takım üyeleri ortak amaç etrafında kenetlenebilmelidir.
  - Takım üyeleri birbirlerini tamamlayan yeteneklere sahip olmalıdır.
- **Takım ruhunu bozan etkenler:**
  - Telaşlı iş ortamı.
  - Sık ortaya çıkan hayal kırıklıkları ve başarısızlıkların takım üyeleri arasındaki sürtüşmeyi arttırması.
  - Doğru yönetilemeyen yazılım geliştirme süreci.
  - Takım yapısının ve rollerinin belirsiz tanımlanması.

Takım ruhu çevik süreçlerde çok daha önemlidir, ama klasik süreçlerde de önemlidir. Ortak amaç, çalışan ve doğru yazılımı vaktinde müşteriye sunmaktır. Başarısızlık olursa "sen şöyle yaptın, ben böyle yaptım" diye suçlamak yerine birlikte ders çıkarılmalı; birlikte üzülüp birlikte sevinebilmelidir. Birbirini tamamlayan yeteneklere örnek: ayrıntıya önem veren, dikkatli biri ile yaratıcı düşünen biri birbirinin zayıf yanını kapatarak daha iyi bir iş ortaya koyar. Sosyal, yönetsel ve teknolojik yeteneklerin, dayanıklılık gibi özelliklerin de birbirini tamamlaması yararlıdır.

**Telaşlı iş ortamı.** Son dakikada gelen bir iş ya da çözülmesi gereken acil bir hata heyecanla, telaş moduyla aşılabilir; ama ardından gelen zihinsel yorgunluk kolay atlatılamaz. O yorgunluk geçmeden yeni bir acil sorun çıkarsa iş yürümez. "Biz robot değiliz."

**Hayal kırıklıkları ve başarısızlıklar.** Hem takımın genel motivasyonunu bozar hem sürtüşmeyi artırır; çünkü insanlar çoğu zaman kusuru kendilerinde değil başkalarında, takım arkadaşlarında arar. Hoca burada genel bir hayat dersi olarak, başkasında görülen bir kusurun bir ölçüde kişinin kendisinde de bulunduğunu, çünkü insanın bilmediği bir şeyi algılayıp tanımlayamayacağını söyledi.

Bunun önlenmesi için hoca şu örneği verdi: Takım ruhuna uygun, başarılı ve yetenekli bir ekibe bütün zor işler hep onlar başarılı olduğu için verilirse takım zamanla yıpranır ve uyumsuzlaşmaya başlar; başarısızlık riski artar ve takım artık sıkı örülmüş, organik bir takım olarak çalışamaz. Bu yüzden en zor işler hep aynı takıma verilmemeli, zaman zaman nispeten kolay işler de verilmelidir: "Çekici bile çok kullanırsanız yıpranır."

**Doğru yönetilemeyen süreç.** Klasik süreçlerde iş tanımları ve hangi aşamada ne yapılacağı bellidir ve sıkı denetim mekanizmaları vardır. Proje ya da teknik yönetici bu gereklilikleri yerine getiremezse veya denetimi yeterince sıkı tutamazsa başarısızlık olasılığı yükselir ve takım yapısı da etkilenir. Ayrıca bir süreç kendi ana kavramları ve çalışma biçimleriyle bir bütündür; parçaları için alternatifler önerilebilir, ama bunlar da sürecin bütünü gözetilerek seçilmelidir. Bütünlüğü bozan değişiklikler takım ruhunu olumsuz etkiler.

**Belirsiz yapı ve roller.** Sorumluluklar net tanımlanmazsa ya yetki çatışması çıkar ("bu benim sorumluluğum, ben yapacağım") ya da tam tersi, "bu benim işim değil, zaten üstümde bir sürü iş var" denerek yapılması gereken bir iş ortada kalır. Bu ancak ona bağlı işler aksamaya başlayınca fark edilir; proje yöneticisi o zaman işi birine atar, ama araya zaman kaybı girmiştir.

### 5.3 Takım yapıları

Hoca bir takımı kurarken dört yaklaşım olduğunu söyledi. <!-- BELİRSİZ: Kapalı, rastgele ve açık yaklaşımların slaytının karesi yok; bu üç yaklaşım altyazıdan alındı. -->

- **Kapalı yaklaşım:** Şelale gibi geleneksel süreçlerle çalışırken en uygun yapıdır. Geleneksel yetki hiyerarşisi ve denetim mekanizmaları vardır. Geçmişteki başarılı projelere benzer projelerde o başarıyı tekrarlamakta başarılıdır. Dezavantajı, yaratıcı fikirler ortaya çıkarmaya uygun olmamasıdır. Şirket, ülke ya da akademik camia için bir yenilik çıkarması beklenen Ar-Ge projelerinde, yaratıcılığı ve bu projelerin doğasındaki belirsizliklerle baş etmeyi engelleyen bir yapısı vardır.
- **Rastgele (random) yaklaşım:** Takım üyeleri bireysel ve teknik yeteneklerine göre kendi aralarında örgütlenir. Bunun için birbirlerinin tamamlayıcı niteliklerini iyi bilmeleri gerekir. Yaratıcı fikirler için en uygun yaklaşımdır, ama disiplin ve düzen sağlamak zor olabilir. Kapalı yaklaşımın tam karşı ucundadır.
- **Açık yaklaşım:** Kapalı ve rastgele yaklaşımlar arasında kendini konumlandırır ve ikisini dengelemeyi amaçlar, ama her takım ve firmaya uymaz. Denetim mekanizmaları vardır ama yapılanma serbesttir; daha demokratik bir yapıdır ve karmaşık problemlerin çözümüne çok uygundur. Son söz yalnız yöneticinin değildir, herkese sorulur. Örneğin proje yöneticisi ve 6 kişiden oluşan 7 kişilik bir takımda oylar 3-3 bölünürse eşitliği takım yöneticisinin oyu bozar. Dezavantajı verimliliği sağlamanın zor olmasıdır: Farklı görüşlerin sahipleri ısrarcı olup uzlaşamazsa tartışma uzar gider. Bu noktada takım yöneticisi, her görüşün dile getirildiğini ve artık aynı şeylerin tekrarlandığını görüp "kifayet-i müzakere" (tartışma yeterlidir) diyerek eşitliği bozan oyunu kullanabilir. Ama bunu her zaman yapamayabilir.
- **Eşzamanlı (synchronous) yaklaşım** (ekrandan, 01:35:00):
  - Problemin takımın üzerine düşen bölümünün de alt parçalara ayrılabildiği durumlarda kullanılabilir.
  - Takım kendi içinde problemin alt parçalarını paylaşır.
  - Alt takımlar arasında etkileşim azdır.

Eşzamanlı yaklaşım her problemde uygulanamaz; hoca RAD (Rapid Application Development) sürecinin avantaj ve dezavantajlarının burada da geçerli olduğunu söyledi.

### 5.4 Takım içi ve takımlar arası haberleşme

Slayt içeriği (ekrandan, 01:35:00):

- **Resmi yollar:** Yazı ile, zamanlı mesajlaşma ile, kurallı ve zamanlanmış toplantılar ile.
- **Gayrı resmi yollar:** Sözlü iletişim, kişisel etkileşimler, gün içerisinde gerektikçe.

Resmi haberleşmede ya da resmi gözden geçirmede iş yazı ile yürür; yazı illa kâğıt kalem değildir, e-posta da yazıdır. Mesajlaşma belli bir form üzerinden, belli bir protokole göre yapılır (hoca, beta sınamasındaki kuralları örnek gösterdi). Toplantılar da "şu gün, şu saatte, şu gündemle" diye zamanlanır. Gayri resmi yollarda ise sözlü iletişim ve kişisel etkileşim tercih edilir; gün içinde ihtiyaç olduğunda, yalnız ilgili kişilerin katılımıyla yapılır.

## 6. Proje Yönetiminde Ölçüm

### 6.1 Proje ölçümü ve süreç ölçümü

Proje yönetimi bağlamında ölçüm etkinlikleri iki alt alanda incelenir (ekrandan, 01:40:00):

- **Proje ölçümü:**
  - Proje ilerlemesi ve proje çıktısı olacak yazılımın ölçülmesidir (ayrıca incelenecek).
  - Odak: teknik düzey.
  - Amaç: iç kalite ölçütlerini yüksek tutmak.
  - Yöntem: ölçüm sonuçlarına göre yazılım geliştirme ekibini iyiye doğru yönlendirmek.
- **Süreç ölçümü:**
  - Yazılım geliştirme sürecinin ölçülmesidir.
  - Odak: yönetimsel düzey.
  - Amaç: dış kalite ölçütlerine yöneliktir.
  - Yöntem: sürecin tüm aşamalarında tutulan istatistiklere göre hem teknik hem yönetimsel açıdan süreçleri iyileştirmek.

**İç kalite ölçütleri** yazılımı gerçekleştiren ekibin ilgi alanına giren kalite bileşenleridir. **Dış kalite ölçütleri** ise yazılımın kullanıcılarını ilgilendiren kalite özellikleridir.

Hoca burada bir "tavuk-yumurta" sorunu olduğunu belirtti: Proje yönetiminde ölçme önemlidir, ölçmede de proje yönetimi bilgisi önemlidir. Ölçme önce anlatılırsa risk yönetimi çok sarkar, ikisi iç içe anlatılırsa konular karışır; bu yüzden gerektikçe ileri-geri referans verilerek anlatılması tercih edilmiştir.

Süreç ölçümüne örnekler:

- Hata bulma etkinliği düşükse, bunu yükseltmek için otomatik test durumu (test case) oluşturma ve yönetme araçları incelenip birine geçilebilir.
- Hata yönetim prosedüründe bazı kritik hatalara geri dönüşler aksıyorsa hatalara önem düzeyi derecelendirmesi getirilip her dereceye farklı emek ve geri dönüş süresi ayrılabilir.

Amaç, istatistiklerle nerede aksandığını keşfedip orayı iyileştirmektir. Hoca bunun CMM'nin 5. düzeyi (optimizing) için söylenenlerle koşut olduğunu belirtti.

### 6.2 Kaliteyle ilgili etkenler

Slayt içeriği (ekrandan, 01:45:00):

- **Kişiler:** Çalışanların yetenek ve istekliliği en önemli etkendir.
- **Ürün:** Ürünün karmaşıklığı kaliteye olumsuz etki eder. Karmaşıklıkla artan zorluk düzeyi takımın maneviyatını kırabilir.
- **Teknoloji:** Yazılım geliştirme araçları ve donanım bileşenlerinin kalitesi (olgunluk, yeterlilik, etkinlik, eğitimsel belgeler vb.).
- **Çevresel koşullar:** Ana etkenlerle de ilişkilendirilebilir.
  - Müşterinin özellikleri: iletişim yeteneği, işbirliği yeteneği vb.
  - İş koşulları: iş akışı kuralları, şirket kültürü vb.

Ürün karmaşıklığı için hoca şöyle açıkladı: Karmaşık olduğu için zordur, zor olduğu için hata olasılığı yüksektir; hatalar çoğaldıkça ve işler güçleştikçe takımın morali bozulabilir. Bunun için iş alt parçalara bölünebilir ya da daha önce söylendiği gibi zor işler hep aynı takıma verilmez.

Teknolojide yeterlilik, araçların projenin ihtiyaçlarını karşılayıp karşılamadığıdır. Etkinlik, bunu ne kadar verimli yaptıklarıdır: az çabayla çok iş yapılabiliyor mu? Eğitimsel belgeler, aracı öğrenmek ve onunla çalışmak için gereken dokümantasyondur.

Çevresel koşullarda müşterinin iletişim ve işbirliği yeteneği çok önemlidir. Kolay ve verimli iletişim kurulabilen kişilerle süreç hızlanır. Çevik süreçlerde müşteri sürecin ayrılmaz bir parçasıdır: Bu parça yeterli katkıyı sağlayabiliyor mu, kenetlenmiş bir ekiple birlikte hareket edebiliyor mu, yoksa "yola taş mı koyuyor"? Hoca bu etkenlerin "kişiler" başlığıyla da ilişkilendirilebileceğini, çünkü müşterinin de bir kişi olduğunu; sınıflandırma konusunda farklı görüşler bulunduğunu söyledi. İş koşullarına firmanın personel memnuniyetini artırma ve personel kaybını önleme çabaları da girer.

### 6.3 Ölçüt toplama ve gizlilik düzeyleri

Slayt içeriği (ekrandan, 01:45:00):

- **Ölçüt toplama ve gizlilik düzeyleri:**
  - Bireysel düzey: kişiye özel olmalıdır.
  - Takım düzeyi: takıma özel olmalıdır.
  - Proje düzeyi: tüm çalışanlara özel olmalıdır.
- **Gizlilik düzeyi tartışması:**
  - Üstün, astlarının ölçütlerini izleyebilmesi ancak denklerin birbirlerinin ölçütlerini görememesi ise bir başka yaklaşımdır.
  - Amaç insanları utandırmak, övmek veya tehdit etmek olmamalı.

Bireysel ölçüm sonuçlarını ayrıntılı olarak yalnız kişinin kendisi görmelidir. A takımının üyeleri A takımının takım düzeyi ölçütlerini görebilir, B takımının üyeleri göremez. Yapıcı bakış açısı şudur: Proje planına ve kalite hedeflerine sadık mıyız? Aksıyorsak nereyi desteklemeliyiz?

Örnek bireysel ölçüt: **yazılan bin satır kod başına bulunan hata sayısı**. Hangi kodu kimin yazdığı bellidir. Herkes birbirinin bu sonucunu görürse, hem denkler hem üst amir tarafından "en çok hata senden çıkıyor, bize ayak bağı oluyorsun" türünden utandırma potansiyeli doğar. Sosyal yetenekleri yüksek bir teknik yönetici kök nedeni araştırmalıdır: Hata oranı en yüksek kişi belki en yetenekli, en deneyimli kişidir ve en zor problemler hep ona verildiği için hata oranı yüksektir. Böyle değerli birine haksız ithamlarda bulunup takım ruhunu bozmak ve onu şirketten kaybetmek istenmez.

> **Hocanın vurgusu:** Ölçüm ve izleme önemlidir, ama ölçümlerin kimlere görünür olduğu ve sonuçlarla ne yapılacağı da en az onlar kadar önemlidir.

### 6.4 Süreç ölçütleri

Slayt içeriği (ekrandan, 01:50:00):

- **Hata sayısı:** Bulunan hata sayısı.
  - Bakım aşamasından önce ve sonra bulunan hataların sayısı ayrı öneme sahiptir.
  - Hata giderme etkinliği:
    - $\text{HGE} = \dfrac{\text{TÖ}}{\text{TÖ} + \text{TS}}$
    - $\text{TÖ}$: Ürünün müşteriye tesliminden önce bulunan hata sayısı.
    - $\text{TS}$: Teslimden sonra (bakım aşamasında) bulunan hata sayısı.
    - $\text{TÖ}$ ve $\text{TS}$ yerine yazılım geliştirme sürecinin ardışıl adımları olan $A(i)$ ve $A(i+1)$ kullanılabilir. Örneğin $A(i)$: çözümlemede bulunan hata sayısı; $A(i+1)$: tasarımda bulunan çözümleme kaynaklı hata sayısı.
- **Doğruluk:** Bulunan hata sayısının proje boyutuna oranı.
- **Bakım kolaylığı:** Bir hatanın bulunması ile giderilmesi arasında geçen zaman.
- **Güvenlik:** Bulunan güvenlik açıkları, açıkların ciddilik düzeyi vb. gibi veriler üzerinde yapılan ölçümler.
- Ve diğer dış kalite ölçütleri.

**Hata giderme etkinliği.** Önemli olan hataları bakım aşamasından önce bulmaktır; önce bulunan hatalar çok daha kolay düzeltilir, sahaya çıkmış yazılımda hata düzeltmek çok daha zordur. $\text{TÖ} + \text{TS}$ toplam bulunan hata sayısıdır. Teslimden önce bulunan hata sayısı yükseldikçe $\text{HGE}$ %100'e yaklaşır; teslimden sonra bulunan hataların artması paydayı büyüttüğü için etkinliği düşürür.

Klasik süreçte ardışık adımlar gereksinim, çözümleme, tasarım gibi aşamalardır; çevik süreçte ardışık iterasyonlar kullanılabilir. Çözümleme aşaması için:

$$\text{HGE}_{\text{çözümleme}} = \frac{A(i)}{A(i) + A(i+1)}$$

Projede her aşama için hata giderme etkinliği hesaplanır. Etkinlik azalma eğilimine girmişse yazılım sınamasına daha fazla zaman ayırmak, ek iterasyon ayırmak ya da daha fazla regresyon testi yapmak gibi önlemler düşünülebilir.

**Doğruluk.** Kod satırı (line of code) başına hata sayısı bir doğruluk ölçütü olarak kullanılabilir.

**Bakım kolaylığı.** Tüm hatalar için bulunma ile giderilme arasındaki süre ölçülüp ortalaması alındığında yazılımın ne kadar kolay bakılabildiği görülür. Ancak bakım ekibinin niteliği de etkilidir: Geçmiş projelerde bakım kolaylığı yüksek çıkmışsa bunun nedeni ürünün değil, bakım ekibinin yetenekli olması olabilir. Bu konuda ayrıca çok sayıda ölçüm yöntemi ve akademik çalışma vardır.

### 6.5 Süreç ölçütlerinin kullanımı

Slayt içeriği (ekrandan, 01:55:00):

- Ölçütler amaç değil, araç olmalı.
- Şirketin boyutu ve hatta proje boyutu ile ölçüm yapmaya ayrılan çaba orantılı olmalı.
- Öncelikleri ve hedefleri belirleyip ona uygun ölçütler kullanılmalı; amaca yönelik ölçümler yapılmalı.
- SEI (Software Engineering Institute) ve SPC (Software Productivity Center)'nin önerdiği ölçüt geliştirme yaklaşımları mevcuttur; ve daha başkaları.
- Süreç iyileştirme modelleri çeşitli ölçütlerin kullanılmasını da gerektirir.

Hoca, küçük ölçekli bir projede çok kapsamlı ölçüm işlemleri yapmanın anlamsız olduğunu söyledi. Ayrıca her ölçüt her proje, ekip ve süreç için uygun değildir; kullanılan programlama yaklaşımı da önemlidir. Örnek: **kalıtım ağacının derinliği (Depth of Inheritance Tree)** ölçütü, nesneye yönelik programlama dersinde görülmüştü. Kod kalıtım kullanmadan yazılmışsa bu ölçütün bir anlamı olmaz.

## 7. Maliyet Tahmin Yöntemleri

### 7.1 Neden maliyet tahmini?

Belirli bir müşteri için hazırlanan projelerde de, büyük kurumların yazılım ihalelerine girerken de yapılacak işin ne kadara mal olacağını bilmek gerekir. Yazılım evi ticari bir kuruluştur ve kâr etmek ister; başka türlü hayatta kalamaz. Teklif vermek için maliyetin bilinmesi gerekir. Pazara ürün çıkarırken de ürünün kendini amorti etme süresi, fiyatlandırma ve başa baş noktası hesapları firmalar için kritiktir. %100 hassasiyete ulaşılamayabilir, ama tahmin yapmak hiç yapmamaktan iyidir. Tahmin doğruluğu bilgi ve deneyimle artar; eski projelerin sonuçlarına bakarak sonraki tahminler iyileştirilir.

Bu amaçla geliştirilmiş yöntemlerden derste şunlar incelendi: bilirkişi takdiri, Delphi yöntemi, analiz yöntemi ve istatistiksel modeller.

### 7.2 Bilirkişi takdiri (Expert Estimation)

Bilirkişi takdiri, daha önce tamamlanmış ve maliyeti ile bitirme süresi bilinen projelerle tahmin yapılacak projenin karşılaştırılmasıyla yapılır. Eski ve yeni projenin maliyet kalemleri belirlenir, aralarındaki farkların oransal yüzdeleri bulunur ve "bu proje şu kadar sürecek, şu kadara mal olacak" denir. Tahminin hassasiyetini artıran en önemli iki şey, bilirkişilerin deneyimi ve iki proje arasındaki farklılıkları doğru hesaplamalarıdır.

### 7.3 Delphi yöntemi

Slayt içeriği (ekrandan, 02:15:00):

- Bir koordinatör yönetiminde bilirkişi ekibi tarafından birkaç kez yinelenen yazılı takdir miktarlarına göre ortak bir tahmin yapılmaktadır.
- Bu yöntem aslında sosyal bilimlerde kullanılan bir anket şeklinin proje takdiri için uyarlanmış halidir.
- Yöntem:
  - Koordinatör bilirkişilere "sistemi tanımlama" belgelerini ve birer "tahmin formu" verir.
  - Bilirkişiler birbirinden habersiz, nedenleri ile birlikte tahminlerini yazılı olarak koordinatöre bildirir.
  - Koordinatör ortanca ve aykırı tahmin sonuçlarını bilirkişilere vererek yeni tahminde bulunmalarını ister.
  - Ortak bir değere yaklaşıncaya kadar bu işlem yinelenmektedir.

Delphi, bilirkişi takdiriyle birlikte kullanılabilir. Temel fikir, tahmini tek kişiye bağımlı olmaktan çıkarıp daha çok kişiye dayandırarak hata düzeyini düşürmektir. Sistem tanımlama belgeleri yazılım gereksinim belirtimidir (software requirements specification). Bilirkişiler tahminlerinin gerekçelerinde önceki projelerle benzerlikleri, farkları, neyin değiştiğini açıklar.

Tahminler birbirine yakınsa ortalamaları alınır. Aykırı (outlier) tahminler varsa koordinatör ortalamayı ve aykırı tahminleri bilirkişilerle paylaşır ve tahminlerin revize edilmesini ister. Gerekçeler paylaşıldıkça yüksek tahmin yapan birinin ortalama tahmin yapanların aklına gelmeyen bir şeyi gördüğü ya da tam tersi ortaya çıkar ve taraflar ortak bir noktaya yaklaşır. Herkesin tam aynı sonucu vermesi gerekmez; belirli bir oranda (örneğin %10) yakınsama yeterlidir ve buna koordinatör karar verir. Hocanın sözlü örneği aşağıda "Örnek Sorular" bölümündedir.

### 7.4 Analiz yöntemi

Slayt içeriği (ekrandan, 02:20:00):

- Analiz yöntemi; ürün veya işlemi hiyerarşik olarak öğelerine ayırarak, en alt öğelerden başlayıp yukarı doğru her öğe için gider takdir etmeye dayanır.
- Bu amaçla önce ürüne ve/veya üretime dayalı analiz kartı düzenlenir.

Yöntem yukarıdan aşağı ayrıştırma, aşağıdan yukarı toplama biçiminde işler. İki ayrı açıdan analiz yapılır: ortaya çıkacak ürün ve bu ürünü üretme biçimi, yani yapılacak teknik faaliyetler. Ekrandaki kartlar şöyledir (ekrandan, 02:20:00):

```text
Ürün analiz kartı
ÜRÜN
├── Girdi Sistemi
│   ├── Oku Modülü
│   └── Veri Yapıları Alt Sistemi
├── Değiştirme Alt Sistemi
│   ├── Veri Denetimi
│   └── Bilgisayar Sonuçları
└── Çıktı Alt Sistemi

Üretim analiz kartı
Üretim
├── Proje Yönetimi
│   ├── Plan
│   └── İnceleme
├── Geliştirme
│   ├── Tasarım
│   ├── Kodlama
│   └── Birim Testi
├── Sınama
│   ├── Birleştirme
│   └── Kabul
├── Servisler
│   ├── Yayın
│   └── Bakım
└── Garanti
```

<!-- BELİRSİZ: Ürün analiz kartında "Bilgisayar Sonuçları" kutusunun hangi alt sisteme bağlı olduğu karedeki çizgilerden net okunmuyor; hoca değiştirme alt sisteminin altında saydığı ve çıktı alt sisteminin alt bileşeni olmadığını söylediği için böyle yazıldı. -->

Ürün kartında, örneğin oku modülü ile veri yapıları alt sisteminin süre ya da maliyet toplamı girdi sisteminin değerini verir; bunlara ek olarak yapılacak başka bir iş varsa o da eklenir. Böylece en alttan yukarı toplanarak ürün maliyeti bulunur. Üretim kartında da benzer süreç yürütülür. Birim testi sınama altında değil geliştirme altındadır, çünkü onu kodu yazan kişi yapar. Sınama altında birleştirme (integration) sınamaları ile geçerleme sınamaları ve kabul sınamaları yer alır. Servisler; yayın, bakım ve başka servislere veri açma gibi işleri, garanti ise karşılaşılan hataların önem seviyelerine göre en geç ne kadar sürede çözüleceği ve sonraki işletim sistemi ya da platform sürümlerine (ör. Java ya da .NET'in yeni sürümleri) belirli bir süre (ör. 2 yıl) uyumluluk sağlanacağı gibi taahhütleri kapsar. Ürün ve üretim maliyetleri toplanarak projenin maliyeti ve süresi bulunur.

Her alt basamağın gideri takdir edilirken büyüklük ölçüleri olan KLOC (Kilo Line of Code, bin kod satırı) ya da FP (Function Point, fonksiyon noktası) ve kişi-ay ölçüleri kullanılır. Büyüklükten kişi-ay bulunur; kişi-ay mevcut kişi sayısına bölünerek süre tahmin edilir. Gider kalemleri geçmiş projelerdeki ortalamalardan yararlanılarak ya da Delphi alt yöntem olarak kullanılarak takdir edilebilir.

Bir kalem için birden fazla tahmin varsa ve bunlar Delphi ile birleştirilmiyorsa, en kötü tahmin 1, en iyimser tahmin 1, ortada kalan (en olası) tahmin 4 ağırlıkla alınır ve toplam 6'ya bölünür:

$$E = \frac{a + 4m + b}{6}$$

Burada $a$ en kötü, $m$ en olası, $b$ en iyimser tahmindir. En kötü ve en iyimser tahmin $1/6$, en olası tahmin $4/6$ ağırlıkla sonuca katılır. <!-- BELİRSİZ: Bu formülün slaytının karesi yok; ağırlıklar altyazıdan alındı, sembol adları (a, m, b) ajan tarafından konuldu. -->

### 7.5 İstatistiksel modeller

Slayt içeriği (ekrandan, 02:25:00):

- İstatistik modeller, doğrudan ölçülmeyen bir değeri ($y$), ölçülebilen bağımsız bir değişken ($x$) yardımı ile kestirmek amacı ile kurulan $y = f(x)$ şeklindeki fonksiyonlardır.
- Yazılım proje tahmininde genellikle $y = a x^b$ biçiminde üslü bir fonksiyon modeli kurulmaktadır. Bu fonksiyonda:
  - Bağımsız değişken ($x$) adayları: bin kod satırı (KLOC), fonksiyon noktası (FP), proje süresi (T), iş hacmi (H) değerleri alınmaktadır.
  - Kestirilmesi istenilen olası bağlı değişkenler ($y$): iş hacmi (H), proje süresi, belge sayfası (B), KLOC olabilmektedir.
  - Fonksiyon katsayıları ($a$ ve $b$), geçmişteki uygulama sonuçlarına ($x$ ve $y$) dayanılarak en küçük kareler yöntemine göre belirlenmektedir.

Ne kestirilecekse o değişken bağımsız değişken olarak kullanılmaz: iş hacmi kestirilirken iş hacmi, süre kestirilirken süre kullanılmaz; ama çaba hesaplanırken süre bağımsız değişken olabilir. Belge sayfası, proje yönetim dokümantasyonu ve son kullanıcı dokümantasyonunun hacmidir. $a$ ve $b$ katsayıları kendi şirketin tamamlanmış projelerinden ya da veri paylaşan kaynaklardan (hoca Kaggle'ı örnek verdi; ondan önceki dönemlerde araştırmacı ve uygulayıcıların yayımladığı veriler) eğri uydurularak hesaplanır. En küçük kareler yöntemi herhangi bir istatistik kitabından incelenebilir; ayrıntısına girilmedi.

#### Walston-Felix modeli

Walston ve Felix, 4.000 ile 467.000 satır kod arasında değişen 60 yazılım projesini inceleyip şu formülleri çıkarmıştır: <!-- BELİRSİZ: Bu slaytın karesi yok; katsayılar altyazıdan alındı. İşgücü formülünün katsayısı altyazıda "0.4" gibi duyuluyor; aynı slaytın başka bir yıl kaydında 0,54 olduğu görüldüğü için 0,54 yazıldı. -->

- İş hacmi (kişi-ay): $H = 5{,}2 \cdot KLOC^{0{,}91}$
- Proje süresi (ay): $T = 4{,}1 \cdot KLOC^{0{,}36}$ ya da iş hacmi hesaplandıysa $T = 2{,}47 \cdot H^{0{,}35}$
- İşgücü talebi (kişi sayısı): $I = 0{,}54 \cdot H^{0{,}06}$
- Belge hacmi (sayfa): $B = 49 \cdot KLOC^{1{,}01}$

Hoca bu katsayıların Walston ve Felix'in incelediği projelerden çıktığını, kendi firmanızın başarıyla tamamlanmış projelerinden en küçük kareler yöntemiyle farklı katsayılar bulabileceğinizi vurguladı. Benzer başka modeller de vardır, ama hepsi $a x^b$ biçiminde olduğu için ayrıntıya girilmedi.

#### COCOMO modeli

Slayt içeriği (ekrandan, 02:30:00):

- H. Boehm, COCOMO (COnstructive COst MOdel) adını verdiği bir yazılım proje hesabı tahmin modeli geliştirmiştir.
- Model hiyerarşik olarak üç basamak halinde uygulanmaktadır:
  - Temel COCOMO.
  - Orta COCOMO: Temel modele EAF (Effort Adjustment Factor: çaba düzeltme çarpanı) serbest değişkeni eklenir.
  - İleri COCOMO: Kullanılan yazılım geliştirme sürecinin her aşaması için ayrı ayrı özel fonksiyonlar kullanılır.

İleri COCOMO'da örneğin şelale modeli kullanılıyorsa gereksinim, analiz, tasarım, kodlama, sınama aşamalarının her biri için ayrı fonksiyon vardır; derste buna girilmedi, temel ve orta COCOMO incelendi.

**Temel COCOMO.** KLOC'a dayanarak iş hacmini, oradan da proje süresini hesaplar:

$$H = a \cdot KLOC^{b}, \qquad T = c \cdot H^{d}$$

Boehm katsayıları 63 yazılım projesinin sonuç değerlerine bakarak ve farklı görüşleri ortak noktada toplayarak belirlemiştir. Farklı yazılım türleri için farklı katsayılar önerir; hoca bunun ilk derste konuşulan yazılım türlerinin farklı ihtiyaçlarıyla tutarlı olduğunu söyledi. <!-- BELİRSİZ: Temel COCOMO katsayı tablosunun karesi yok; değerler altyazıdan alındı. -->

| Yazılım türü | İş hacmi $H$ | Süre $T$ |
|---|---|---|
| Uygulama programları | $2{,}4 \cdot KLOC^{1{,}05}$ | $2{,}5 \cdot H^{0{,}38}$ |
| Yardımcı programlar (utility) | $3{,}0 \cdot KLOC^{1{,}12}$ | $2{,}5 \cdot H^{0{,}35}$ |
| Sistem yazılımları | $3{,}6 \cdot KLOC^{1{,}20}$ | $2{,}5 \cdot H^{0{,}32}$ |

Hocanın yorumu: Üstel katsayılara bakıldığında uygulama programlarının gereksinimleri nispeten basit (straightforward) olduğu için üs en küçüktür ($1{,}05$); en zor ve kritik olan sistem yazılımlarında üs en büyüktür ($1{,}20$); yardımcı programlar arada kalır. Çarpan katsayıları da benzer biçimde yorumlanabilir. Süre formülünde ise uygulama programlarının üssü ($0{,}38$) sistem yazılımlarınınkinden ($0{,}32$) büyüktür. Hoca bunu uygulama programlarında gereksinimlerin çok daha hızlı değişmesiyle açıkladı. Sistem yazılımında ise girdi ve çıktı bellidir, belli bir girdiye karşılık hangi çıktının üretileceği zaman içinde değişmez.

**Orta COCOMO.** Temel modele çaba düzeltme çarpanı (EAF) eklenir. Boehm, EAF'ın duruma göre 0,90 ile 1,40 arasında alınmasını önerir (ekrandan, 02:35:00). Ekrandaki örnek "Örnek Sorular" bölümünde çözülmüştür. EAF'ın nasıl seçileceği sorusuna hoca, geçmiş deneyimlerden yola çıkarak uygun aralığın belirlenebileceğini ve Boehm'in çalışmasında bazı temel öneriler bulunduğunu söyledi; ayrıntısına girilmedi.

#### PNR (Putnam-Norden-Rayleigh) modeli

PNR modeli yıllık iş hacmini bin satır kod sayısına (KLOC), bir teknoloji katsayısına ($C_k$) ve yıl olarak geliştirme süresine bağlı olarak hesaplar; geliştirme süresi formülde 4. kuvvetiyle yer alır. Teknoloji katsayısı için öneri şöyledir:

- Düşük teknoloji ortamında: $C_k = 2000$
- İyi teknoloji ortamında: $C_k = 8000$
- Otomatik yazılım araçlarının kullanıldığı ortamda: $C_k = 12000$

<!-- BELİRSİZ: PNR slaytının karesi yok; formülün tam biçimi altyazıdan okunamadı, yalnız sürenin 4. kuvveti ve C_k değerleri duyuluyor. -->

> **Ek bilgi (derste anlatılmadı):** Putnam'ın yazılım denkleminden türetilen biçim büyük olasılıkla $H = \dfrac{KLOC^3}{C_k^3 \cdot t^4}$ şeklindedir. Burada $C_k$ paydada olduğu için gelişmiş, otomatik araçların kullanıldığı ortamlarda aynı kodu aynı sürede üretmek için gereken iş hacmi azalır; süre de 4. kuvvetiyle paydada olduğundan süreyi kısaltmak iş hacmini çok hızlı artırır.

Model, proje boyunca toplam işgücünün yüzdesinin zamana göre dağılımının eşit (homojen) olmadığı gözlemine dayanır; Putnam, Norden ve Rayleigh adlı üç araştırmacı bu eğriye dayanarak formüllerini önermiştir. İşgücü ihtiyacı proje süreci basamaklarına ve sürecin başından o ana kadar geçen zamana bağlıdır. Kodlama ve gerçekleme aşamasında personel ihtiyacı tepe yapar, sonraki sınama aşamalarında daha az personel gerekir. Uygulamada yazılım geliştirme bitince personelin bir kısmı yeni projelere verilip birkaç kişi eski projenin sınama aşamalarında çalıştırılmaya devam eder. Hoca PNR'yi COCOMO'dan hemen sonra anlattığını, çünkü yaklaşımlarının benzer olduğunu söyledi. COCOMO 2 farklı bir yaklaşımdır ve derste işlenmedi.

### 7.6 Araçlarla ilgili hatırlatma

Dersin sonunda hoca proje yönetimi bölümünü toparlarken araçlara ilişkin daha önce konuşulanları hatırlattı: sınama için JUnit üzerinde ayrıntılı çalışılmıştı; dersin başında sürüm kontrol sistemlerinden bahsedilmişti. Modelleme araçlarının koddan şemaya ve şemadan koda çift yönlü dönüşüm yetenekleri ne kadar iyiyse işler o kadar kolaylaşır. IBM Rational ve Microsoft Team System (Azure DevOps) gibi bütünleşik ortamların yetenekleri daha önce konuşulmuştu. Hangi araçların kullanılacağına da projenin ölçeğine göre karar verilmelidir.

## Örnek Sorular

### Soru 1: Orta COCOMO ile iş hacmi ve süre hesabı (ekrandan, 02:35:00)

**Soru:** Bir mikroişlemcide uzaktan haberleşme amacıyla kullanılacak 10.000 satır kodlu gömülü (embedded) sistem yazılımı için düzeltme faktörü EAF = 1,17 alınırsa iş hacmi ve proje süresi ne olur?

**Çözüm (derste verilen):**

- Verilen: $KLOC = 10$, EAF $= 1{,}17$. Gömülü yazılım sistem yazılımı sayıldığı için sistem yazılımı katsayıları kullanılır: $a = 3{,}6$, $b = 1{,}20$, $c = 2{,}5$, $d = 0{,}32$.
- İş hacmi: $H = 3{,}6 \cdot 10^{1{,}20} \cdot 1{,}17$. Ara adım (ara adım eklendi): $10^{1{,}20} \approx 15{,}85$; $3{,}6 \cdot 15{,}85 \approx 57{,}06$; $57{,}06 \cdot 1{,}17 \approx 66{,}8$ programcı-ay. Hoca bunu yaklaşık 67 kişi-ay olarak da ifade etti.
- Proje süresi: $T = 2{,}5 \cdot 66{,}8^{0{,}32} \approx 9{,}6$ ay.

Değerler python ile doğrulandı ($H \approx 66{,}76$, $T \approx 9{,}59$).

### Soru 2: Delphi yönteminde aykırı tahminler (derste sözlü, 02:16:08)

**Soru:** Beş bilirkişi bir projenin süresini tahmin ediyor. Tahminler 6 ay, 5 ay, 6 ay, 9 ay ve 3 ay. Koordinatör ne yapar?

**Çözüm (derste verilen):** 9 ve 3 ay tahminleri ortalamadan uzak, aykırı tahminlerdir; ama tahmin edenlerin kendi gerekçeleri vardır. Koordinatör ortalama tahmini ve aykırı tahminleri bilirkişilere bildirip bu bilgiler ışığında tahminlerini revize etmelerini ister. Her bilirkişi tahminini revize eder; tahminlerin birbirine yaklaşması beklenir, yaklaşmadıysa işlem yinelenir. Tahminler ortak bir değere belirli bir oranda (ör. %10) yaklaşınca durulur. Bu ilk turun ortalaması (ara adım eklendi): $(6 + 5 + 6 + 9 + 3)/5 = 5{,}8$ ay.

### Soru 3: EAF değeri nasıl seçilir? (derste sözlü, 02:34:49)

**Soru:** Orta COCOMO'da EAF'ı kaç alacağımızı nereden bileceğiz?

**Cevap (derste verilen):** Geçmiş deneyimlerden yola çıkarak uygun katsayının hangi aralıkta olduğu belirlenebilir. Boehm'in çalışmasında da bu konuda temel öneriler vardır; Boehm, EAF'ın duruma göre 0,90-1,40 arasında alınmasını önerir.

## Dersin Toparlaması

Bu derste yazılım proje yönetimi baştan sona işlendi. Proje yönetiminin ilgi alanlarının önem sırası kişiler, ürün, süreç ve proje olarak verildi; proje ölçeğine göre araç gereksinimi, basitlik, geleneksel ve çevik planlama yaklaşımları ile planlama ilkeleri anlatıldı. Risk yönetiminde proaktif yaklaşım, risk çeşitleri (proje, teknik, işletme), risk tablosu, olasılık-etki grafiği ve örnek risk bilgi sayfası incelendi. Kişi etkenlerinde iyi bir teknik yöneticinin özellikleri, takım ruhu ve onu bozan etkenler, kapalı, rastgele, açık ve eşzamanlı takım yapıları ile resmi ve gayri resmi haberleşme konuşuldu. Ölçüm bölümünde proje ve süreç ölçümü, kaliteyle ilgili etkenler, ölçütlerin gizlilik düzeyleri ve hata giderme etkinliği gibi süreç ölçütleri ele alındı. Son olarak maliyet tahmin yöntemlerinden bilirkişi takdiri, Delphi, analiz yöntemi ve Walston-Felix, COCOMO ve PNR istatistiksel modelleri işlendi.

Hoca, proje yönetimi bölümünün bu derste tamamlandığını, geriye yazılım ölçütleri ve yazılım kalitesi konularının kaldığını söyledi; fonksiyon noktası (function point) gibi büyüklük ölçütleri o bölümde ayrıntılı ele alınacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
