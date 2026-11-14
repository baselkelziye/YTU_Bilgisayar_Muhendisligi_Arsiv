# Ders 1 Genişletilmiş Notu: Sayısal Analize Giriş: Anlamlı Basamak, Kesme-Yuvarlama, Doğruluk-Hassaslık, Hata ve Taylor-Maclaurin Serileri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Çerçevesi: Kaynaklar ve Algoritma Kurmak
- 2. Dersin Konularına Genel Bakış
- 3. Sayısal Analiz Nedir?
- 4. Analitik Çözüm ve Sayısal Çözüm
- 5. Sayı Sistemleri
- 6. Anlamlı Basamak (Significant Digit)
- 7. Kayan Noktalı Sayılar
- 8. Ondalık Basamak (Decimal Place)
- 9. Kesme ve Yuvarlama
- 10. Kayan Noktalı Yazım Alıştırması
- 11. Doğruluk ve Hassaslık
- 12. Yanlış ve Hata
- 13. Kayan Noktalı Sayılarla İşlemler
- 14. Hata Kavramı ve Hata Çeşitleri
- 15. Taylor ve Maclaurin Serileri

## 1. Dersin Çerçevesi: Kaynaklar ve Algoritma Kurmak

### 1.1 Kaynaklar

Hoca, dersin referans kitabı olarak McGraw-Hill'in bir kitabını aldığını, slayttaki diğer iki kitabın da bölüm kütüphanesinde bulunduğunu söyledi. Sayısal analiz, yani İngilizcedeki adıyla numerical analysis, bütün mühendisliklerde okutulan bir derstir. Onlarca Türkçe, yüzlerce İngilizce kaynak vardır. Bu yüzden tek bir kitaba bağlı kalmak gerekmez.

<!-- BELİRSİZ: Slaytta gösterilen kitapların tam adları altyazıda geçmiyor. -->

Kitapların içeriği birbirinin aynısı değildir. Konu içeriklerinin yaklaşık %60-70'i ortaktır. Geri kalanı, kitabı yazanın bilim dalına göre değişir. Bir bilgisayarcı, bir matematikçi ya da bir elektronikçi kendi alanındaki yöntemleri daha ayrıntılı işler. Lisans dersinde temel konular görülür. Hocanın söylediğine göre bu dersin devamı olarak yüksek lisansta daha derin bir dersi açan üniversiteler de vardır.

### 1.2 Algoritma Kurmayı Öğrenmek

Hoca, bu dersteki yöntemleri kodlayabilmek için algoritma bilgisine ihtiyaç olduğunu söyledi. Ona göre bir bilgisayar mühendisliği öğrencisi en geç ikinci sınıfın birinci döneminde algoritma konusunu bitirmiş olmalıdır. Yani ikinci sınıfın ikinci dönemine başlarken "algoritma kuramıyorum, kod yazamıyorum" dememelidir. Bunun yolu bol bol kod yazmak ve karşılaşılan problemleri çözmektir, çünkü algoritma yalnızca tahtada dinleyerek öğrenilmez.

Hoca bunu kendi öğrencilik deneyimiyle anlattı. Birinci sınıfta hocası siyah tahtada soldan sağa akış diyagramları çizerken hiçbir şey anlamamış, bölümü bırakmayı bile düşünmüştü. Bölüm başkanının "Yapamıyorum diye bir şey yoktur, ancak çalışmıyorum diyebilirsin" sözü üzerine yanlış çalıştığını anladı. Bundan sonra akış diyagramlarını "buraya bunu neden koyduk, niçin böyle yaptık" diye analiz ederek çalıştı. Bir süre sonra "bir ışık yanıyor" ve konu çözülüyor.

> **Hocanın vurgusu:** Pratik yapmak gerçekten çok önemlidir. Kodları başka yerlerden bulmayın, kendiniz için yazın. Dördüncü sınıfın sonuna kadar her konuda bir şey bilin, ama bir alanda da kendinizi gerçekten çok iyi yetiştirin.

## 2. Dersin Konularına Genel Bakış

Hoca, dönem boyunca görülecek konuları kısa açıklamalarla sıraladı.

### 2.1 Hata ve Sayıların Okunması

İlk konu sayısal analizin ne olduğudur. Bunun içinde hata (error) ile yanlış (mistake) ayrımı, bir kayan noktalı sayının nasıl okunacağı ve noktadan sonra kaç basamakla işlem yapılacağı vardır. Sayısal hesaplamaların sonucunda oluşan hataların da çeşitleri vardır: kesme, bağıl, mutlak ve yuvarlama hataları.

Bu ders için hesap makinesi olmazsa olmazdır. Hoca, işlemlerin çoğu dört işlem olsa da büyük ve küsuratlı sayılarla yapıldığını söyledi. Bu yüzden kendi hesap makinenizin üs alma ve türev gibi işlemlerde nasıl kullanıldığını bilmelisiniz.

### 2.2 Doğrusal Olmayan Denklemlerin Çözümü

Elimizde bir fonksiyon vardır ve bu fonksiyonun kökü, yani $x$ eksenini kestiği nokta aranır. Kök, $x$ yerine konduğunda fonksiyonu sıfır yapan değerdir. Kağıt kalemle diskriminantı hesaplar; katlı, çakışık ya da sanal kökleri analitik yoldan buluruz. Fakat bilgisayar bu çözümü bizim kağıt üzerinde yaptığımız gibi yapamaz. Ona kodlanabilir bir şey vermek, yani bir sözde kod (pseudocode) çıkarıp onu bir programlama diline çevirmek gerekir.

Hocanın basit örneği üs almaktı. Kağıtta 2'nin karesi için 2'nin üzerine 2 yazarız. Bilgisayarda ise üstteki sayı kaçsa 2 sayısı o kadar kez kendisiyle çarpılır. Arka planda yapılan budur.

Bu konudaki yöntemler kapalı ve açık yöntemler diye ikiye ayrılır:

- **Kapalı yöntemler:** Grafik yöntemi, ikiye bölme (bisection) ve regula falsi.
- **Açık yöntemler:** Newton, basit iterasyon ve sekant.

Kitaplarda başka yöntemler de görülebilir, ama bir dönem hepsine yetmez. Bu derste elektrik, endüstri ve bilgisayar mühendisliği gibi alanlarda kullanılan, iyi sonuç veren yöntemler seçilmiştir.

### 2.3 Sayısal İntegral

İntegral, $f(x)$ fonksiyonu ile $x$ ekseni arasında kalan alanı bulmaktır, yani bir alan hesabıdır. Bu alan sonsuz olduğu için belirli bir aralıkla sınırlanır ve $a$'dan $b$'ye integral yazılır.

**Soru (hoca sordu):** $x^3$'ün integrali nasıl alınır? **Cevap:** Bir öğrenci önce $\frac{x^4}{3}$ dedi, ardından doğrusu olan $\frac{x^4}{4}$ söylendi.

Bunu kağıtta kolayca yaparız, ama kodla nasıl yaptıracağımız ayrı bir sorudur. Sayısal düşünürken şöyle deriz: Bu integral, fonksiyon ile $x$ ekseni arasındaki $[a, b]$ aralığındaki alandır. Öyleyse alanı küçük parçalara böleyim, parçaların alanlarını hesaplayıp toplayayım. Algoritmalar bu fikir üzerine kuruludur. Bazıları alanı küçük yamuklara, bazıları parabollere böler. Sonuçta analitik çözüme yakın, yaklaşık bir sonuç elde edilir. Derste yamuk (trapez) ve Simpson yöntemleri görülecektir. Çift katlı integrallerde de analitik çözümdeki gibi her katta Simpson ya da yamuk kullanılır.

### 2.4 Sayısal Türev

Türev, integralin tersidir ve genelde optimizasyon problemlerinde kullanılır. Bir sistemin en küçük ve en büyük noktalarını, örneğin en küçük ve en büyük ısınma noktalarını bulmak istediğimizde bize bir fonksiyon verilir ve onun en küçük ya da en büyük noktası aranır. Burada türevden yararlanılır.

Analitik yolda $2x^2$'nin türevi için "üs başa çarpılır, üs bir azalır" der, $4x$ buluruz (ara adım eklendi). Sayısal yolda ise bunu hep toplama ve çıkarmalarla gerçekleştirmeye çalışacağız.

### 2.5 Matrisler

Matematikte matrisin transpozunu alır, determinantını hesaplar, tersini buluruz. Sayısal analizde bunların nasıl yapılacağı görülecektir. Yöntemler bizden matrisi önce alt üçgen, sonra üst üçgen matrise çevirmemizi, birim matris, köşegen matris ya da bant matris hâline getirmemizi isteyecektir. Bu yüzden önce bu matris türlerinin ne olduğu anlatılacaktır.

### 2.6 Doğrusal Sistemlerin Çözümü

Burada birden fazla denklem ve birden fazla bilinmeyen vardır. Slayttaki örnekte iki değişken ($x_1$, $x_2$) ve iki denklem vardı. Amaç, iki denklemi de sağlayan $x_1$ ve $x_2$ değerlerini bulmaktır. Bu iki denklem çizildiğinde kesiştikleri nokta çözümü verir. Bulunan değerler denklemlerde yerine konunca sol taraf sağ tarafa eşit olur. Denklemlerdeki $a_1$, $c_1$ gibi katsayılar bilinen sabitlerdir.

<!-- BELİRSİZ: Slayttaki iki denklemli sistemin tam yazımı altyazıda okunmuyor; yalnız A1 ve C1 katsayıları anılıyor. -->

Bu konuda da iki grup yöntem vardır:

- **Dolaysız yöntemler:** Bir sonuç kendinden önceki sonucu kullanmaz. Yöntem başlar, adım adım ilerler ve sonuçlanır.
- **Dolaylı (indirect) yöntemler:** Her adım bir önceki adımdaki değeri kullanarak sonuca gider. Gauss-Seidel ve Jacobi bu gruptandır. Bu adlar matematikçilerin soyadlarıdır. Aynı matematikçilerin dolaysız yöntemleri de vardır.

Bunların dışında Cholesky ve Cramer yöntemleri de görülecektir. Bazıları Lineer Cebir dersinde analitik olarak gösterilir. Bu derste ise bilgisayarda nasıl kodlanacakları görülecektir.

### 2.7 Doğrusal Olmayan Denklem Takımları

İkiden fazla denklem de olabilen bu sistemler Taylor seri açılımı kullanılarak çözülür.

<!-- BELİRSİZ: 00:31:02 civarında hocanın kalemle yazdığı örnek denklem altyazıda "3x artı 4y mesela 5" olarak geçiyor; slayttaki hâli okunmuyor. -->

> **Ders sonrası not:** Hoca doğrusal olmayan denklem örneği olarak "3x artı 4y eşittir 5" dedi. Bu hâliyle $3x + 4y = 5$ doğrusaldır; doğrusal olmaması için bilinmeyenlerin kuvveti ya da çarpımı gibi terimler gerekir. Tahtadaki denklemde büyük olasılıkla altyazıya yansımayan bir üs vardı.

### 2.8 Sonlu Farklar

İnterpolasyon ve regresyon çözümlerinde sonlu farklar kavramı gerekir. Sonlu farklar özellikle interpolasyonda çok yardımcı olur. İleri, geri ve merkezi farklar, bunların birinci, ikinci ve üçüncü dereceleri ile sonlu fark tabloları görülecek ve interpolasyonda kullanılacaktır. Hoca bu konuların adlarının korkutucu göründüğünü, ama içine girince hoşa gittiğini söyledi: Bugüne kadar her şeyi hazır kullandık. Bir sonucun ortaya çıkışına kendimiz sebep olunca bakış açımız değişir.

### 2.9 Eğri Uydurma

Eğri uydurmada bize bir takım noktalar verilir ve bu noktalara en uygun fonksiyon aranır. Hocanın örneği derse katılımdı. Birinci hafta 60, ikinci hafta 65, üçüncü hafta 57 kişi katılmış, onuncu haftaya kadar benzer sayılar verilmiş olsun, onuncu haftada da 69 kişi. İstenen, bu değerlerle öyle bir fonksiyon uydurmaktır ki 13. haftada derse kaç kişinin katılacağı tahmin edilebilsin.

Sayısal analizde gerçek dünyada kesin değere ulaşılamaz. Derste verilen örneklerde sonuç tam çıkar, çünkü çözümü kolay olsun diye özel hazırlanırlar. Gerçek dünyada sıfır hatayla bir şey bulmak çok zordur. Hoca hava sıcaklığı tahminini örnek verdi: Bugün sıcaklık 11 derece, yarın için 12 tahmin ettiniz, ama sıcaklık 11.8 oldu. Tahmin $12 - 11.8 = 0.2$ derece şaştı (ara adım eklendi). Aynı yaklaşım bir fabrikanın üretim bandından çıkan ürün sayısına, bir öğrencinin ortalamasına ya da bir evin mutfak harcamalarına da uygulanabilir. Amaç, verilen değerlerden geçen bir fonksiyon uydurup sonraki günü ya da yılı yaklaşık olarak tahmin etmektir.

Eğri uydurmanın iki alt başlığı vardır: interpolasyon ve regresyon.

### 2.10 İnterpolasyon

İnterpolasyonda verilen noktalardan birebir geçen fonksiyon aranır. Hoca bunu "konu olarak daha iddialı" diye nitelendirdi. Bu noktalardan üstel bir fonksiyon, bir polinom ya da bir doğru geçebilir. Neyin geçeceğini bize kullanılan yöntem söyler: Gregory-Newton ya da Lagrange interpolasyonu çalıştırıldığında, işlemin sonunda ne tür bir fonksiyon geçtiği görülür.

Hoca slayttaki tanımı şöyle okudu:

- Hatasız veri noktalarının arasında kalan ara noktaları belirlemek için kullanılır.
- Tablo hâlinde verilen bilgiler için geçerlidir.
- Veri noktalarından doğrudan geçen bir eğri uydurmak ve bu eğriyle ara değerleri tahmin etmektir.

Örnek olarak sesi verdi. Ses analog bir veridir ve her $t$ anı için ondan örnek alınabilir. Dijital olarak işlemek için belirli $T$ aralıklarıyla örnekler alırız. Bu örneklere uyan bir fonksiyon oluşturup aralıkları tamamlayarak, belki bir Fourier serisi açarak, orijinal sese yakın bir ses elde etmeye çalışırız. Kulağımız her sesi duymaz, duyabildiği bir frekans aralığı vardır. Öyleyse duyulmayan frekansları çıkarırsak hem elimizdeki veri azalır hem de işlem kolaylaşır.

### 2.11 Regresyon

Regresyon, hesaplaması ve kullanımı interpolasyona göre daha rahat, daha esnek olan ve daha tahmini sonuçlar veren yoldur. Noktalardan geçen yaklaşık bir doğru aranır. Bazı değerler doğrunun tam üzerinde, bazıları biraz altında ya da üstünde kalır. Amaç en küçük hatayla geçen doğruyu ya da eğriyi bulmaktır. Bu bir doğru olabileceği gibi doğrusal olmayan bir fonksiyon ya da polinom da olabilir.

Tanımı şöyledir: Verilerde belirgin bir hata söz konusuysa regresyon uygulanır. Deneysel sonuçlar bu tiptedir. Verilerin genel eğilimini gösteren ve herhangi bir noktadan özellikle geçmesi gerekmeyen tek bir eğri bulunur.

İkisi arasındaki belirgin fark şudur: İnterpolasyonda verilen noktalarda hiç hata yoktur, regresyonda kullanılan değerlerde hata olabilir. Örneğin sayılar noktadan sonra 10 basamakken siz 2 basamak alarak fonksiyon uyduruyorsanız hata oranı daha yüksek olur.

Hoca şu soruyu kendisi sordu: Verilen değerlerden bir doğru mu, bir parabol mü, üstel bir fonksiyon mu geçireceğimi nereden bileceğim? Cevabı "Bilemezsin, bir cam küreye bakıp bunu söyleyemeyiz" oldu. Farklı fonksiyon tipleri denenir, en küçük hatayı veren seçilir. Örneğin hep atmosferde ısı ve basınç verileriyle çalışıyorsanız, bir iki denemeden sonra hangi fonksiyon tipinin iyi sonuç verdiğini öğrenirsiniz ve "bu verilerde en iyi sonuç parabol geçirmektir" diyebilirsiniz. Regresyonda en küçük kareler yöntemi görülecektir. Bu yöntemle doğru, polinom, trigonometrik ya da doğrusal olmayan bir fonksiyon geçirilebilir.

### 2.12 Adi Diferansiyel Denklemler

Son konu, bazı dönemlerde yetişebilen adi diferansiyel denklemlerdir. Bunların içinde hep türevler vardır. Slayttaki örnekte iki değişken ve zamana bağlı türev vardı. O anki çıktıdan yola çıkılarak sonraki çıktı tahmin edilir. İki ya da daha fazla fonksiyonun türevini içeren denklem sistemleri özellikle elektrik mühendisliği ve kontrol alanındaki yöntemlerde çok kullanılır.

<!-- BELİRSİZ: Slayttaki adi diferansiyel denklem örneği altyazıda okunmuyor. -->

### 2.13 Yöntemin Arka Planını Bilmenin Avantajı

Hoca, başka mühendisliklerde genelde MATLAB'ın hazır çözümlerinin kullanıldığını ve kod yazmaya gerek duyulmadığını söyledi. Bilgisayar mühendisinin ihtiyacı ise farklı olabilir: Elimizde bir kütüphane vardır, ama problemimizde onun girişine, çıkışına ya da aradaki bir adımına müdahale etmemiz gerekebilir. Bunun için koda bakıp anlamak gerekir. Örneğin karşımıza integralle ilgili bir kod çıktığında, integralin sayısal olarak nasıl alındığını kabaca biliyor ve algoritma okuyabiliyorsak değişikliği nereye, nasıl yapacağımızı daha kolay görürüz. Hoca, başka mühendisliklerde de merak edip iyi kod yazan kişiler olduğunu, bir bilgisayar mühendisinin de merak ederse anten gibi bir alanda çok şey öğrenebileceğini ekledi.

## 3. Sayısal Analiz Nedir?

Hoca, "Hem sayacağız hem de saydığımız şeyleri analiz mi edeceğiz?" diye başlayarak üç tanım verdi.

- **Birinci tanım:** Bilgisayar teknolojisindeki hızlı gelişmeler ve bilgisayarın mühendislikte kullanıma uygun olması sebebiyle sayısal analiz mühendislik için çok önemli hâle geldi. Hoca, 1910'lu ve 1920'li yıllarda bilgisayarın günlük işlerde kullanılabilen bir araç olmadığını hatırlattı. Amaç, bir mühendislik problemini kağıt kalem kullanmadan, zamandan kazanarak ve daha az hatayla bilgisayara çözdürmektir.
- **İkinci tanım:** Geniş çaplı matematik problemlerinin ve mühendislik sistemlerinin çözümü için kullanılan metotlar topluluğudur. Bu yöntemler matematikçiler tarafından geliştirilmiştir, çünkü örneğin integralin arkasındaki temeli ancak bir matematikçi öğretebilir. Biz o teoriyi kodlanabilir hâle getiririz.
- **Üçüncü tanım:** Fiziksel bir sistemin matematiksel gösterimini sağlamaktır. Bir takım sayılar size yalnızca sayı gibi gelebilir. Fakat bunlar $x^3 + 5x^2 + 7$ gibi bir fonksiyonu sağlıyorsa, artık onlara bir problemin girişlerine karşılık alınmış çıktılar olarak bakarsınız.

<!-- BELİRSİZ: Örnek fonksiyon altyazıda "x küp artı 5 kare artı 7" olarak geçiyor; ikinci terimin 5x^2 olduğu varsayıldı. -->

Kısacası sayısal analiz güçlü bir problem çözme aracıdır ve analitik yoldan çözülmesi imkânsız olan denklem sistemlerinin çözümünde kullanılır. Birçok probleme hazır programlarla yaklaşılamaz, bu yüzden bazen programı kendimiz yazmak zorunda kalırız. Örneğin problemimizde matris tersi alınacaksa bunun kodu gerekir. Başkaları bu yöntemleri koda döküp araçların içine koymuştur. Biz de onları kullanırız ve giriş, çıkış ya da ara işlemlerde değişiklik istiyorsak koda müdahale ederiz. Hocanın toparlaması şuydu: Sayısal yöntemler yüksek matematiği basit aritmetik işlemlere indirger.

## 4. Analitik Çözüm ve Sayısal Çözüm

Mühendislik problemlerinin çözümünde ya analitik ya da sayısal yol kullanılır. Analitik yol matematikçilerin yaptığı, teorik olan yoldur ve sonuçlarda süreklilik vardır. Mühendislik problemleri ise daha çok deneyseldir.

Hocanın örneği oda sıcaklığıydı. Odanın sıcaklığı sürekli değişir: Camı bir saniye açıp kapatırsanız ya da kapıyı aralarsanız sıcaklık anlık olarak değişir. Fakat sayısalda bu kadar sürekli bilgiyle çalışmayız, "5 dakikada bir sıcaklığı ölçün" deriz. O 5 dakikanın içinde kapı açılıp oda eski sıcaklığına dönmüş olabilir. Bu yüzden alınan örnekler kesiklidir ve hesaplamalar analitik sonuçlarla birebir örtüşmez, yani sıfır hatayı vermez.

Slayttaki iki kolonlu karşılaştırma şöyledir:

| Analitik çözüm | Sayısal çözüm |
| :--- | :--- |
| Çözüm matematiksel fonksiyonlar olarak üretilir, sonra bazı veriler için sayısal değere dönüştürülür. | Sonuçlar daima sayısaldır. |
| Karışık olmayan problemlerde kullanılır. Karmaşık problemleri elle çözmek zordur, zaman alır, çok kontrol gerektirir ve yanlış yapma ihtimali yüksektir. | Analitik çözümü olmayan ya da analitik olarak çözülemeyen karışık problemlerde tercih edilir. |
| Tek ve kesin bir sonuç elde edilir. | Yaklaşık sonuç, iteratif bir çözümle bulunur. |

İteratif çözüm şu demektir: İkinci sonucu elde etmek için birincinin, üçüncü sonucu elde etmek için ikincinin sonucu kullanılır. Sonuçlar peşi sıra kullanılarak en son sonuca ulaşılır.

Yaklaşık çözümün hassasiyetini artırmak ya da azaltmak bizim elimizdedir. İterasyon sayısını 1000 yerine 10.000 almak hassasiyeti artırır. Noktadan sonra 2 basamak yerine 10 basamakla işlem yapmak da, çok büyük olmasa bile, bir fark yaratır. Sonuç bulununca hata analizi de yapılır. Hata çok büyükse iterasyon sayısı artırılır ya da seçilen yöntemin bu girişlere uygun olmadığına karar verilip başka bir yöntem seçilir.

### 4.1 Örnek: En Küçük Noktayı Bulmak

Verilen fonksiyon $f(x) = x^2 - 3x + 2$ olsun.

<!-- BELİRSİZ: Fonksiyonun kendisi altyazıda okunmuyor. Türev 2x - 3, en küçük değer -0.25 ve kökler 1 ile 2 anlatımından, kısa notla da uyumlu olarak yazıldı. -->

**Analitik çözüm:**

1. Türev alınır: $f'(x) = 2x - 3$.
2. Türev sıfıra eşitlenir: $2x - 3 = 0$, buradan $x = 1.5$.
3. Fonksiyonda yerine konur: $f(1.5) = 2.25 - 4.5 + 2 = -0.25$ (ara adım eklendi).

Yani en küçük değer $-0.25$'tir.

**Sayısal çözüm:** Sayısal yöntemde elimizde yalnızca belirli $x$ değerleri ve bu değerlerde fonksiyonun aldığı sonuçlar vardır. Bize $x = 1.5$ sorulsun, ama tabloda 1.5 olmasın. 1.5'in hangi iki $x$ arasına düştüğünü biliyoruzdur ve o komşu sonuçlardan yaklaşık bir değer söyleriz. Slayttaki komşu sonuçların ikisi de $-0.24$ olarak görünüyordu. Hoca bu değerler 3-4 basamakla alınırsa farklılaşacağını ve aranan değerin bu arada olacağını söyledi. Orijinal değer ise $-0.25$'tir. Yani tam değeri değil, yaklaşık bir değeri buluruz.

<!-- BELİRSİZ: Slayttaki x ve f(x) tablosu altyazıda yok. -->

> **Ders sonrası not:** Hoca aranan değerin iki komşu sonuç arasında kalacağını ve $-0.25$'in bu aralığa rastlayabileceğini söyledi. Burada aranan bir en küçük nokta olduğu için değer komşularının arasında değil, altındadır: $-0.25 < -0.24$. Slayttaki komşular büyük olasılıkla $x = 1.4$ ve $x = 1.6$'dır; ikisinde de sonuç tam olarak $-0.24$ çıkar, yani basamak sayısını artırmak bu iki değeri farklılaştırmaz.

### 4.2 Denklem Çözümü Örnekleri

Hoca, sayısal analizi şöyle özetledi: Analitik çözümü mümkün olmayan denklemlerin sayısal yöntemlerle yaklaşık çözümlerinin bulunması işlemidir. Ardından slayttan üç durum gösterdi.

- **Birinci durum:** Hiç sayısal yöntem bilmeden, çarpanlara ayırarak çözülebilen bir denklem. Çarpanlar sıfıra eşitlenince kökler $x = 2$ ve $x = 1$ bulunur. Diskriminant ile de çözülebilir. Aynı denklem sayısal yöntemle de çözülebilir.
- **İkinci durum:** Analitik çözümü çok zor bir denklem. Burada $x$'e rastgele değerler verilir. $x = 1$ için bir sonuç, $x = 0$ için başka bir sonuç bulunur. Biri "$x = 0.5$ ise ne olur?" diye sorarsa, "1'den küçük, $-1.23$'ten büyük bir sayı" denir, belki $-1$ gibi bir değer söylenir. Orijinal değeri bilmeyiz, yaklaşık olarak buluruz.
- **Üçüncü durum:** Analitik yolla çözülmesi zor ya da imkânsız bir denklem. Sayısal yöntemlerle bu fonksiyonu sıfır yapan $x$ değerleri yaklaşık olarak bulunur.

<!-- BELİRSİZ: İkinci ve üçüncü durumdaki denklemler slaytta kalıyor, altyazıda okunmuyor. Birinci durumun denklemi de açıkça söylenmiyor; kökleri x^2 - 3x + 2 ile uyumludur. -->

> **Ders sonrası not:** Hoca diskriminantlı formülü "b kare artı eksi diskriminant bölü 2b" diye söyledi; büyük olasılıkla bu bir dil sürçmesidir. Doğrusu $x_{1,2} = \frac{-b \pm \sqrt{\Delta}}{2a}$, $\Delta = b^2 - 4ac$'dir.

## 5. Sayı Sistemleri

Hoca, bunların Bilgisayar Bilimlerine Giriş dersinde görülmüş olabileceğini söyleyerek kısaca hatırlattı.

- **10 tabanı (desimal):** Günlük hayatta kullandığımız sistemdir.
- **2 tabanı (binary):** Bilgisayar bilimlerinde kullanılır.
- **8 tabanı (oktal):** Bazı alanlarda kullanılır, bizim pek kullandığımız bir taban değildir.
- **16 tabanı (hexadecimal):** Bilgisayarcıların kullandığı tabandır. Alçak seviyeli programlama dersinde yazılan bir kod adım adım izlenirken (trace, debug) sonuçlar hep bu tabanda görülür. Görülen sayı çiftleri 16 tabanında yazılmıştır.

## 6. Anlamlı Basamak (Significant Digit)

Hoca, bütün dönem kullanılacak iki terim olduğunu söyledi. İlki anlamlı basamaktır. "Sonucu 5 significant digit olarak ver" denildiğinde kısaca **5S** yazılır.

5S, noktanın solundaki ve sağındaki basamakların toplamının 5 olması demektir. Noktanın solundaki 0 anlamlı bir basamak değildir, çünkü kayan noktalı sayıları zaten "sıfır virgül" diye yazarız.

**Örnek 1:** $\frac{2}{3}$ sayısını 5S olarak yazalım.

1. $\frac{2}{3} = 0.666666\ldots$ diye devreder.
2. Noktanın solundaki 0 anlamlı olmadığı için noktadan sonra 5 basamak alınır.
3. Beşinci basamaktan sonraki rakam 6'dır, yani 5'ten büyüktür. Sonuç yuvarlanır: $0.66667$.

Yani burada görünürde 6 rakam olsa da anlamlı basamak sayısı 5'tir. "Neden dört tane 6 ve bir 7 var?" sorusunun cevabı da budur: Sayı yuvarlanmıştır.

**Örnek 2:** $\sqrt{2}$ sayısını 5S olarak yazalım.

1. $\sqrt{2} = 1.41421\ldots$ diye gider.
2. Noktanın solunda 0 değil 1 vardır, bu da anlamlı bir basamaktır.
3. Bu basamak dahil toplam 5 basamak için noktadan sonra yalnız 4 basamak alınır: $1.4142$.
4. Yuvarlama istense de sonuç değişmez, çünkü 2'den sonraki basamak 5'ten küçüktür.

> **Hocanın vurgusu:** "Noktadan sonra kaç basamak alalım?" demek biraz avam bir konuşmadır. Doğrusu "Kaç anlamlı basamak alıyoruz?" diye sormaktır. "8 significant alın" denirse kaç basamak almanız gerektiğini artık bilirsiniz. Bu terimler sınavlarda da kullanılacaktır.

## 7. Kayan Noktalı Sayılar

Kayan noktalı (float) bir sayı mantis, taban ve işaretli üsten oluşur: $m \times b^{e}$. Hocanın örneğinde $12 \times 10^5$ sayısının mantisi $m = 12$, tabanı (İngilizce base'den) $b = 10$, üssü $e = 5$'tir.

Algoritma yazıp bir kayan noktalı sonucu dışarı yazdırdığımızda sayıyı olduğu gibi değil, sıfır virgül ile başlayan üstel biçimde görürüz. Hoca bunu `printf` örneğiyle anlattı ve derleyicilerin buna göre tasarlandığını söyledi. Bellekte de mantis, taban, üs ve üssün işareti tutulur.

> **Ders sonrası not:** Hoca, bellekteki tabanın hep 10 olduğunu söyledi. Bilgisayar bellekte kayan noktalı sayıları büyük olasılıkla 2 tabanında tutar. Ayrıca C'de `printf` ile `%f` biçimi sayıyı noktalı yazar (`156.780000`), `%e` biçimi ise noktanın solunda sıfırdan farklı bir basamak bırakır (`1.567800e+02`). Yani "$0.xxx$" biçimi yazdırmanın kendiliğinden sonucu değil, derste kullanılan yazım biçimidir.

Hocanın yazdığı örnekler şunlardır:

- $156.78 = 0.15678 \times 10^3$. Çünkü $0.15678$ sayısını 10 ile çarparsak $1.5678$, 100 ile çarparsak $15.678$, 1000 ile çarparsak $156.78$ olur.
- $67.42$ üç biçimde yazılabilir: $0.6742 \times 10^2$, $6.742 \times 10^1$ ve $0.06742 \times 10^3$.
- Bir başka sayı $0.125 \times 10^{-2}$ biçimindedir. Üssün $-2$ olması, sayının önüne iki sıfır geleceğini gösterir: $0.00125$ (ara adım eklendi).

<!-- BELİRSİZ: Son örneğin özgün yazımı slaytta kalıyor. Altyazıda "0,125" ve "eksi 2, önüne 2 tane 0 gelecek" deniyor; buna göre özgün sayı 0.00125 alındı. -->

Aynı sayı 10 tabanında farklı üslerle yazılabilir. Hepsi aynı sayıdır:

$$5.026 \times 10^{-17} = 50.26 \times 10^{-18} = 0.5026 \times 10^{-16}$$

## 8. Ondalık Basamak (Decimal Place)

İkinci terim ondalık basamaktır. Hoca bunu hem "decimal point" hem "decimal place" diye andı. **2D** dendiğinde noktadan sonra kaç basamak alınacağı anlaşılır. Noktanın solu ilgilendirmez, yalnız sağındaki basamak sayısına bakılır.

Örnek sayı $6.752642$ olsun:

- **3S:** $6.75$
- **2D:** $6.75$
- **3D:** $6.752$

<!-- BELİRSİZ: Sayı altyazıda "75, 26, 42" ve sonuçlar "6,75" ile "752" olarak geçiyor; 6.752642 buna göre kuruldu. -->

## 9. Kesme ve Yuvarlama

### 9.1 Tanımlar

Hoca kesme işlemini chopping sözcüğüyle açtı. Sözlükte bu sözcük "kuşbaşı gibi doğramak" anlamına gelir. Elbette sayı doğranmaz, bu daha çok sayıyı ayırma biçimidir. Programlama dillerinde bunlar `round` ve `trunc` adlı fonksiyonlardır.

- **Kesme (trunc):** İstenen basamaktan sonrası olduğu gibi atılır.
- **Yuvarlama (round):** İstenen basamaktan sonra gelen rakama bakılır. Bu rakam 5 ya da 5'ten büyükse son basamak bir artırılır.

İkisi de basamak sayısını azaltır.

### 9.2 Örnek: $\pi$

$\pi = 3.14159265\ldots$ için 4D, yani noktadan sonra 4 basamak istensin:

- **Kesme:** $3.1415$. Noktanın solu zaten alınır, sağdan 4 basamak kalır.
- **Yuvarlama:** Dört basamaktan sonra gelen rakam 9'dur, yani 5'ten büyüktür. Son basamak 5, 6 olur: $3.1416$.

İkisi de 5 anlamlı basamaktır. Soru "5S, kes" ya da "5S, yuvarla" biçiminde de sorulabilir, D ile de sorulabilir.

Bu terimlerin amacı, sonuçların hangi kuralla bir sonraki adıma aktarılacağını belirlemektir. "3 decimal place" denildiyse her adımın sonucu 3D olarak sonraki adıma girdi verilir. Kesmenin belirli hatalar oluşturduğu da görülecektir.

### 9.3 Yuvarlama Hatası (Round-off Error)

Hoca, bir sayının yuvarlanmış ve kesilmiş hâlleri arasındaki farka round-off error dediğini söyledi. $\pi$ örneğinde bu fark $3.1416 - 3.1415 = 0.0001$'dir (ara adım eklendi). Çok küçük farklar ölümcül sonuçlara yol açabilir. Hocanın örneği uzaya gönderilen roketti: Orada yuvarlamak ya da kesmek çok şeyi değiştirebilir, 4D almak hassas bir işlemi engelleyebilir, daha fazla basamak gerekebilir.

> **Ders sonrası not:** Hoca yuvarlama hatasını yuvarlanmış ve kesilmiş hâller arasındaki fark olarak anlattı. Yaygın tanım büyük olasılıkla, gerçek değer ile sınırlı sayıda basamakla gösterilen değer arasındaki farktır. Bu tanıma göre $\pi$ için $3.1416$ alınırsa hata $3.14159265 - 3.1416 = -0.00000735$ olur.

### 9.4 Tablo Alıştırması

Hoca slayttaki tabloyu sınıfla doldurdu. İlk iki sütun kesme, son iki sütun yuvarlamadır.

| Sayı | Kesme 3S | Kesme 3D | Yuvarlama 3S | Yuvarlama 3D |
| :--- | :---: | :---: | :---: | :---: |
| 34.78219 | 34.7 | 34.782 | 34.8 | 34.782 |
| 3.478219 | 3.47 | 3.478 | 3.48 | 3.478 |
| 0.3478219 | 0.347 | 0.347 | 0.348 | 0.348 |
| 0.03478219 | 0.0347 | 0.034 | 0.0348 | 0.035 |

<!-- BELİRSİZ: Sayıların tam hâli slaytta kalıyor. Altyazıdaki sonuçlarla uyumlu olan kısa nottaki değerler alındı. -->

Satırların çözümü şöyledir:

- **34.78219:** 3S'de noktanın solundaki iki basamak da sayılır, noktadan sonra bir basamak alınır: $34.7$. Yuvarlamada sonraki rakam 8 olduğu için $34.8$. 3D'de noktadan sonra üç basamak alınır: $34.782$. Sonraki rakam 1 olduğu için yuvarlama bunu değiştirmez.
- **3.478219:** 3S ile $3.47$, 3D ile $3.478$. Yuvarlamada 3S'nin sonraki rakamı 8 olduğu için $3.48$, 3D'nin sonraki rakamı 2 olduğu için yine $3.478$ (ara adım eklendi).
- **0.3478219:** Soldaki 0 sayılmaz. Hem 3S hem 3D noktadan sonra üç basamak alır: $0.347$. Yuvarlamada sonraki rakam 8 olduğu için $0.348$.
- **0.03478219:** Hoca burada noktanın sağındaki sıfırı dikkate almak gerektiğini söyledi, çünkü bu sıfır sayıyı küçültür. 3D için bu sıfır dahil noktadan sonraki üç basamak alınır: $0.034$. Sonraki rakam 7 olduğu için yuvarlama $0.035$ verir.

> **Ders sonrası not:** Altyazıya göre hoca son satırda 3S için de $0.034$ ve yuvarlamayla $0.035$ sonucuna gitti; büyük olasılıkla noktanın sağındaki sıfırı da anlamlı basamak gibi saydı. Doğrusu, ilk sıfırdan farklı rakamdan önceki sıfırlar anlamlı basamak sayılmaz. Bu yüzden 3S kesme $0.0347$, 3S yuvarlama $0.0348$'dir. Tablo bu doğru değerlerle verildi.

**Soru:** $0.3478219$ örneğinde 3S ve 3D neden aynı çıktı? **Cevap:** 3S için, soldaki 0 anlamlı olmadığından noktadan sonra üç basamak alınır. 3D için de noktadan sonra üç basamak alınır. Bu yüzden ikisi aynıdır. Noktanın solunda 1 olsaydı, 3S için bir eksik basamak alınacak, sondaki 7 alınmayacaktı. Kesilince $0.347$, sonraki rakam 8 olduğu için yuvarlanınca $0.348$ bulunur.

## 10. Kayan Noktalı Yazım Alıştırması

Hoca verilen sayıları hep "sıfır virgül" ile başlayacak biçimde yazdırdı.

- $12.35 = 0.1235 \times 10^2$.
- $0.00519 = 0.519 \times 10^{-2}$. Sınıftan "eksi sıfır" cevabı da gelince hoca bunu adım adım gösterdi. Bir tane eksi ile sayının önüne bir sıfır, ikincisiyle bir sıfır daha gelir.

<!-- BELİRSİZ: Slayttaki diğer sayılar net değil. Altyazıda "0,8 ... 10 üzeri eksi 1", "sıfır elli dokuz ... on üzeri eksi bir" ve "sıfır yirmi dokuz ... on üzeri üç" geçiyor; özgün sayılar okunamıyor. -->

Kural şudur: Virgül sola kaydırılıyorsa üs, kaydırılan basamak sayısı kadar pozitif olur. Virgül sağa kaydırılıyorsa üs, kaydırılan basamak sayısı kadar negatif olur. İlk örnekte virgül sola iki basamak kaydı, üs $+2$ oldu. İkinci örnekte sağa iki basamak kaydı, üs $-2$ oldu.

> **Ders sonrası not:** Hoca, altyazıya göre "0,007"yi $0.7$ yapmak için virgülün dört kez sağa kaydığını ve üssün $-4$ olduğunu söyledi. $0.007$ için virgül iki kez kayar: $0.007 = 0.7 \times 10^{-2}$. Üssün $-4$ çıktığı sayı $0.00007$'dir; slayttaki sayı ya da söylenen sıfır sayısı büyük olasılıkla budur.

## 11. Doğruluk ve Hassaslık

### 11.1 Hız Göstergesi Örneği

Hoca, kitapların çoğunda bulunan bir örnekle başladı. Arabada oturup hız ibresine baktığınızı düşünün. Göstergede 40, 45, 50 ve 60 gibi işaretler vardır. Aradaki küçük çizgileri sayıp "49" dersiniz. Fakat noktadan sonrası için hiçbir şey söyleyemezsiniz. Küsuratı olabilir ya da olmayabilir, bunu bilmezsiniz. Okunan değerin güvenilirliğini gösterebilmek için anlamlı basamak kavramı ortaya çıkmıştır. Bu da şu soruyu getirir: Okuduğum sayının doğruluğu ve hassaslığı nedir? Doğru olan her şey hassas mıdır, hassas olan her şey doğru mudur?

<!-- BELİRSİZ: Gösterge görseli slaytta kalıyor; okunan değerin kesin olarak 49 olup olmadığı altyazıda net değil. -->

### 11.2 Tanımlar

**Doğruluk (accuracy):** Hesaplanan ya da ölçülen değerin gerçek değere ne kadar uyduğunu ifade eder. Bulunması gereken değer 61 olsun. $59.89$ ile fark $61 - 59.89 = 1.11$, 59 ile fark $61 - 59 = 2$'dir (ara adım eklendi). Bu yüzden $59.89$ daha doğrudur.

**Hassaslık (precision):** Hesaplanan ya da ölçülen değerlerin kendi aralarında ne kadar uyumlu olduğunu ifade eder. Bir ölçümde $59.88$, başka bir ölçümde $59.891$ çıkmışsa değerler birbirine çok yakındır ve hassaslık vardır. Arada 70 ölçülmüşse hassaslık bozulmuştur. Burada mutlaka ya kişiden ya da kurulan sistemden kaynaklanan bir sorun vardır.

### 11.3 Hedef Tahtası

Dört hedef tahtası düşünün. Her birine ok atılmış olsun. Doğruluk soldan sağa, hassaslık yukarıdan aşağıya doğru artar. Hedef, tam ortayı, yani 12'den vurmaktır.

| | Doğruluk düşük | Doğruluk yüksek |
| :--- | :--- | :--- |
| **Hassaslık düşük** | 1. tahta: Oklar dağınık ve hedeften uzak. Sonuç yanlış ve belirsiz. | 2. tahta: Oklar dağınık, ama hedefe daha yakın. Sonuç belirsiz, ama daha doğru. |
| **Hassaslık yüksek** | 3. tahta: Oklar birbirine yakın, ama hedeften uzak. Sonuç yanlış, ama hassas. | 4. tahta: Oklar hem birbirine hem hedefe yakın. Sonuç hem doğru hem hassas. |

Birinci ve ikinci tahtayı karşılaştıran hoca, ikincide oklar hedefe daha yakın olduğu için doğruluğun daha yüksek olduğunu gösterdi. Yukarıdan aşağı inildiğinde de okların birbirine yaklaştığını, yani hassaslığın arttığını gösterdi.

Bu tablo iteratif çalışmayı da anlatır. Yöntem çalışmaya başladığında değerler dağınık çıkar. Amaç sonucu hedefe yaklaştırmaktır. Her iterasyonda hassaslık yükselir, doğruluk da biraz daha artar.

## 12. Yanlış ve Hata

Hoca, sokaktaki bir insanın yanlış (mistake) ile hata (error) arasındaki farkı söyleyemeyeceğini, oysa aralarında çok büyük bir fark olduğunu söyledi.

**Hata (error)** sistemden kaynaklanır. Gerçek değer ile hesaplanan değer arasındaki farktır. Bulunması gereken sonuç 1.5 iken 1.6 bulmak işlemde bir hata olduğunu gösterir. Belki birkaç iterasyon daha yapılsa 1.5 elde edilecektir. Kullanılan algoritma, çok az ondalık basamak almak ya da yuvarlamak yerine kesmek hataya yol açabilir.

**Yanlış (mistake)** insandan kaynaklanır, tamamen bizim yaptığımız şeydir. Hocanın örnekleri şunlardır:

- IBAN numaralarında arka arkaya çok sayıda sıfır olabilir. Dört sıfır varken beş sıfır yazmak.
- Bir sayıyı başka yere geçirirken iki rakamın yerini değiştirmek.
- Tekrar eden sayıları yanlış okumak.
- Matrisin satır ve sütunlarını okurken kaydırma yapmak.
- Ondalık basamağı yanlış okumak.

Hesap makinesiyle işlem yaparsanız hatalı sonuç bulabilirsiniz. Hesap makinesini kullanmadan elle işlem yaparsanız hem yanlış yapabilir hem de bu yanlış yüzünden hatalı sonuç elde edebilirsiniz.

Türkçede bu iki sözcüğü tam ayırt edemesek de İngilizcede ayrım açıktır. Bilgisayar hep "error" verir, "mistake" vermez. Yazdığınız kodda ise "mistake" olabilir, çünkü bir komutu yanlış giren sizsinizdir.

## 13. Kayan Noktalı Sayılarla İşlemler

Hoca bu kuralları bilinen şeyler olarak hızlıca geçti.

- **Toplama ve çıkarma:** İşlemden önce üsler aynı değere getirilir. Mantisler toplanır, üs aynı yazılır.
- **Çarpma:** Üsler toplanır.
- **Bölme:** Üsler çıkarılır.

<!-- BELİRSİZ: Aşağıdaki sayılar slaytta kalıyor, altyazıda yalnız "0,15" ve "2 ekliyoruz" geçiyor. Değerler kısa nottan alındı ve python ile doğrulandı. -->

**Toplama:** $3.12 \times 10^1 + 4.26 \times 10^1 = (3.12 + 4.26) \times 10^1 = 7.38 \times 10^1 = 0.738 \times 10^2$.

**Çarpma:** $4.27 \times 10^1 \cdot 3.68 \times 10^2 = (4.27 \cdot 3.68) \times 10^{1+2} = 15.7136 \times 10^3$. Bu sayı sıfır virgül biçimine çevrilirken nokta sola iki basamak gider ve üsse 2 eklenir: $0.157136 \times 10^5$.

**Bölme:** $\frac{4.27 \times 10^1}{3.68 \times 10^2} = \frac{4.27}{3.68} \times 10^{1-2} = 1.1603 \times 10^{-1} = 0.11603$.

> **Ders sonrası not:** Altyazıda hoca toplamada "üstteki dereceler toplanır" diyor; büyük olasılıkla mantisleri kastediyordu, çünkü üs toplamada değişmez. Kısa nota göre slayttaki çarpma satırında $0.157136 \times 10^{-5}$ yazıyordu; hoca da bu satırda bir yanlışlık olduğunu söyledi. Doğrusu $0.157136 \times 10^{5}$'tir.

## 14. Hata Kavramı ve Hata Çeşitleri

Kısa bir özet olarak hata, beklenen gerçek değer ile hesaplanan değer arasındaki farktır. Bu hatayı en aza indirmek sayısal yöntemlerdeki birinci amaçtır. İteratif yöntemlerde iterasyon sayısı arttıkça hatanın küçüldüğü görülecektir. Bazı problemlerde ise seçilen yöntem o veri için uygun olmadığından hata hep büyük kalır. O zaman yöntem değiştirilir.

**Örnek:** $f(x) = x^2$ ve $x = 5$ olsun. Gerçek değer 25'tir. Hesap makinesi 10 verirse aradaki $25 - 10 = 15$ fark hatadır (ara adım eklendi).

> **Ders sonrası not:** Hoca, makinenin belki derece ya da radyan modunda kaldığı için 10 vermiş olabileceğini söyledi. Bu ayar trigonometrik işlemleri etkiler, kare almayı etkilemez. 10 sonucu büyük olasılıkla $2 \cdot 5$ işleminden gelir.

Hatalar dörde ayrılır:

- **Kesme hatası (truncation error)**
- **Bağıl hata (relative error)**
- **Mutlak hata (absolute error):** Hoca bunu bağıl hatadan üretilen hata olarak andı.
- **Yuvarlama hatası (rounding error)**

Bunların ayrıntısı bir sonraki derse kaldı.

> **Ek bilgi (derste anlatılmadı):** Yaygın gösterimde mutlak hata büyük olasılıkla $|\text{gerçek} - \text{hesaplanan}|$, bağıl hata ise bu farkın gerçek değere bölümüdür. Bazı kaynaklarda bağıl hatanın mutlak değeri de kullanılır. Hocanın sözü büyük olasılıkla slaytlarındaki tanıma göredir. Kesin tanım için sonraki ders esas alınmalıdır.

## 15. Taylor ve Maclaurin Serileri

Hatalar genelde seriler üzerinde gösterilir. En çok bilinen ve kullanılan seriler de Taylor ve Maclaurin serileridir. Hoca teorisine fazla girmeden bu serilerin ne olduğunu anlattı.

### 15.1 Her Fonksiyon Seriye Açılır mı?

Hocanın cevabı hayırdı. Bir fonksiyonun seriye açılabilmesi için sonsuz kez türevinin alınabilmesi gerekir. $\sin x$ ve $\cos x$ sonsuz kez türevlenebildiği için seriye açılır.

**Örnek 1:** $f(x) = x^3 + x^2 - x$ fonksiyonunun türevlerine bakalım.

1. $f'(x) = 3x^2 + 2x - 1$
2. $f''(x) = 6x + 2$
3. $f'''(x) = 6$
4. $f^{(4)}(x) = 0$

Hoca, burada dördüncü türevde sıfıra gelindiği için bu fonksiyonun seriye açılamayacağını söyledi.

> **Ders sonrası not:** Hoca, dördüncü türevi 0 olduğu için bu polinomun seriye açılamayacağını söyledi; büyük olasılıkla açılımın sonlu kalmasını kastediyordu. Polinomlar sonsuz kez türevlenebilir, çünkü sıfır da bir türevdir. Bu yüzden polinomun Taylor serisi sonlu sayıda terimden oluşur ve polinomun kendisine eşittir. Seriye açılamama durumuna örnek, $x = 0$ noktasında türevi olmayan $|x|$'tir.

**Örnek 2:** $f(x) = e^{2x}$ için türev her alındığında öndeki sayı büyür ve $e^{2x}$ devam eder. Sonsuz kez türev alınabildiği için seriye açılabilir. Türevler şöyledir: $f'(x) = 2e^{2x}$, $f''(x) = 4e^{2x}$, $f'''(x) = 8e^{2x}$, $f^{(4)}(x) = 16e^{2x}$.

> **Ders sonrası not:** Hoca üçüncü ve dördüncü türevi $12e^{2x}$ ve $24e^{2x}$ olarak söyledi; büyük olasılıkla bir anlık işlem hatasıdır. Her türevde katsayı 2 ile çarpılır, bu yüzden doğrusu $8e^{2x}$ ve $16e^{2x}$'tir. Genel olarak $n$. türev $2^n e^{2x}$'tir.

> **Ek bilgi (derste anlatılmadı):** Sonsuz kez türevlenebilmek serinin yazılabilmesi için gereklidir. Ancak serinin fonksiyonun kendisine eşit olması için büyük olasılıkla ayrıca serinin o bölgede fonksiyona yakınsaması da gerekir. Derste kullanılan $e^x$, $\sin x$ ve $\cos x$ gibi fonksiyonlarda bu koşul sağlanır.

### 15.2 Taylor ve Maclaurin Arasındaki Fark

Aralarında küçücük bir fark vardır. Slayttaki taralı daire Taylor açılımını, onun küçük bir alt durumu da Maclaurin serisini gösteriyordu.

- **Taylor açılımı:** $f(x)$ fonksiyonunun $x = x_0$ noktasındaki seri açılımıdır. $x_0$ değeri 0, 1, 2, 3, 4 gibi herhangi bir değer olabilir.
- **Maclaurin serisi:** Taylor serisinin yalnız $x_0 = 0$ noktasında açılan özel durumudur. Bazı değişkenler kaybolduğu için daha basit bir seri gibi görünür.

### 15.3 Taylor Serisi

Sonsuz kez türevlenebilen $f(x)$ için:

$$f(x) = f(x_0) + \frac{f'(x_0)}{1!}(x - x_0) + \frac{f''(x_0)}{2!}(x - x_0)^2 + \frac{f'''(x_0)}{3!}(x - x_0)^3 + \dots + \frac{f^{(n)}(x_0)}{n!}(x - x_0)^n + \dots$$

İlk terim, fonksiyonda $x$ yerine $x_0$ koymaktır. Sonraki terimler türevin $x_0$ noktasındaki değerini, $(x - x_0)$'ın kuvvetini ve faktöriyeli içerir. Slaytta birinci terimdeki kuvvet ve $1!$ sonucu değiştirmediği için yazılmayabilir. Seriyi hiçbir zaman sonsuza kadar açamayız, belirli bir yerde keseriz. Soruda "ilk 5 terimi al" ya da "4. dereceye kadar aç" gibi bir sınır verilir.

### 15.4 Maclaurin Serisi

Maclaurin için yapılacak tek şey, Taylor serisinde $x_0$ yerine 0 koymaktır:

- $f(x_0)$ terimi $f(0)$ olur.
- Birinci türev terimi $f'(0)$ olur, $(x - 0)$ yalnız $x$ yazılır.
- İkinci türev terimi $f''(0)$ olur, $(x - 0)^2$ yalnız $x^2$ yazılır.
- $n$. terim $\frac{f^{(n)}(0)}{n!}x^n$ olur.

$$f(x) = f(0) + \frac{f'(0)}{1!}x + \frac{f''(0)}{2!}x^2 + \frac{f'''(0)}{3!}x^3 + \dots + \frac{f^{(n)}(0)}{n!}x^n + \dots$$

Hoca, Taylor serisinin nasıl açıldığını bilmenin yeterli olduğunu söyledi. Maclaurin ondan $x_0 = 0$ alınarak elde edilir.

**Soru:** Bu açılımları neden yapıyoruz? **Cevap:** İleride kesme hatası anlatılacak. Gregory-Newton interpolasyonu Taylor serisi kullanılarak yapılacak, türev hesabında da Taylor serisinden yararlanılacak. Bu bilgi önceden verilmezse "Şimdi bunu Taylor'a açtık" dendiğinde, hiç görmemiş ya da hatırlamayan biri bunun nereden çıktığını anlamaz. Bugünkü ders de bu yüzden kavramlara, ölçütlere ve terminolojiye ayrılmıştır.

### 15.5 Örnek: $e^x$'in Taylor Açılımı

**Verilen:** $f(x) = e^x$. Seriyi $x = 1$ noktasında açın ve ilk dört terimini yazın.

$x_0 = 1$ verildiği için Maclaurin açılamaz, çünkü Maclaurin için bu değerin 0 olması gerekir. Taylor açılır.

**1. Türevler hazırlanır:** $f'(x) = f''(x) = f'''(x) = e^x$. $n$. türev de $e^x$'tir.

**2. Değerler bulunur:** $x = 1$ konunca hepsi $e^1 = e$ olur: $f(1) = f'(1) = f''(1) = f'''(1) = e$.

**3. Formülde yerine yazılır:**

- 1. terim: $f(1) = e$
- 2. terim: $f'(1)(x - 1) = e(x - 1)$
- 3. terim: $\frac{f''(1)}{2!}(x - 1)^2 = \frac{e}{2!}(x - 1)^2$
- 4. terim: $\frac{f'''(1)}{3!}(x - 1)^3 = \frac{e}{3!}(x - 1)^3$

**Sonuç:**

$$e^x \approx e + e(x - 1) + \frac{e}{2!}(x - 1)^2 + \frac{e}{3!}(x - 1)^3$$

### 15.6 Hazır Fonksiyonun Arkasında Ne Var?

Hesap makinesinde $e^x$ tuşuna basıp 1 verdiğimizde $2.\ldots$ diye bir sonuç alırız. Fakat makinenin bu sonucu serinin kaç terimiyle bulduğunu bilmeyiz. Yaklaşık olarak işimizi gördüğü için kullanırız. Fakat karşımıza çok daha hassas bir $e^x$ hesabı gerektiren bir problem çıkabilir. Belki makine ilk 10 terimi kullanıyordur, bize ilk 50 terim gerekiyordur. O zaman seriyi açıp kodunu kendimiz yazarız. Belki de hazır bir kütüphanede terim sayısı bir parametredir. Varsayılanı 5 ise, 50 yapınca farklı sonuçlar alabiliriz. Çoğu zaman bunlardan haberimiz olmaz, hazırı kullanırız.

### 15.7 Örnek: $\cos x$'in Maclaurin Açılımı

**Verilen:** $f(x) = \cos x$. Maclaurin açılımının sıfırdan farklı ilk üç terimini bulun.

Hoca, bilgisayarda $\cos$ fonksiyonuna bir $x$ verdiğimizde arka planda seriye açılmış hâlin kullanıldığını, ama kaç terim açıldığını bilmediğimizi söyledi. Bir mühendis arka planda ne döndüğünü de bilmelidir.

> **Ders sonrası not:** Hoca, `cos` fonksiyonunun arka planda doğrudan serinin kendisini hesapladığını söyledi. Gerçek kütüphaneler büyük olasılıkla açıyı önce küçük bir aralığa indirir ve özel olarak seçilmiş polinom yaklaşımları kullanır. Yaklaşık hesabın polinomla yapılması fikri ise aynıdır.

Soru $x = 0$ noktasında açmayı istediği için doğrudan Maclaurin kullanılır.

**1. Türevler hazırlanır:**

- $f'(x) = -\sin x$
- $f''(x) = -\cos x$
- $f'''(x) = \sin x$
- $f^{(4)}(x) = \cos x$

**2. Terimler sırayla bulunur:**

- 1. terim: $f(0) = \cos 0 = 1$. Sıfırdan farklı birinci terim budur.
- 2. terim: $f'(0)x = -\sin 0 \cdot x = 0$.
- 3. terim: $\frac{f''(0)}{2!}x^2 = -\frac{x^2}{2!}$. Sıfırdan farklı ikinci terim budur.
- 4. terim: $\frac{f'''(0)}{3!}x^3 = 0$, çünkü $\sin 0 = 0$'dır.
- 5. terim: $\frac{f^{(4)}(0)}{4!}x^4 = \frac{x^4}{4!}$. Sıfırdan farklı üçüncü terim budur.

**Sonuç:**

$$\cos x \approx 1 - \frac{x^2}{2!} + \frac{x^4}{4!}$$

> **Hocanın vurgusu:** Matematik kitaplarındaki $\cos x$ ve $\sin x$ açılımlarını ezberlemeye gerek yoktur. Başlangıç değeri verilirse Taylor ya da Maclaurin formülüyle rahatça açılır. Fonksiyonu $\sin x$ ile başlatırsanız türevlerin sırası değişir. Aynısı $\cos 5x$ ve $\tan x$ için de geçerlidir: İfade aynıdır, yalnız konulan değerler değişir.

### 15.8 "Dereceye Kadar Aç" Ne Demek?

Soruda geçen derece, türevin derecesidir. "Üçüncü dereceye kadar aç" demek ilk dört terimi çıkarmak, "dördüncü dereceye kadar aç" demek ilk beş terimi çıkarmak demektir.

> **Ders sonrası not:** Hoca Taylor serisini anlatırken "dördüncü türeve kadar ilk dört terimi alacağım" dedi; büyük olasılıkla dil sürçmesidir. Dersin sonunda kendisinin de söylediği gibi, dördüncü dereceye kadar açılımda ilk beş terim bulunur, çünkü sıfırıncı dereceli $f(x_0)$ terimi de sayılır.

### 15.9 Sonraki Ders: Seriyi Genelleştirmek

Hoca, kalan kısmı haftaya bıraktı. Şöyle bir soru gelecektir: Bir fonksiyon veriliyor ve belirli bir noktadaki serisi isteniyor. 20 terim gerekirse teker teker 20 terim hesaplayıp toplamak yerine seriyi genel bir formül hâline getirmek istiyoruz. Böylece değeri formüle koyup sonucu hemen buluruz.

> **Ders sonrası not:** Hoca, bu genel formülde "x'in yerine 14 koyunca ilk 14 terimin toplamını" vereceğini söyledi. Buraya konan değer büyük olasılıkla $x$ değil, terim sayısıdır. Ayrıntısı bir sonraki derstedir.

## Dersin Toparlaması

Bu derste önce sayısal analizin ne olduğu ve dönem boyunca görülecek konular üzerinde duruldu: kök bulma, sayısal integral ve türev, matrisler, doğrusal ve doğrusal olmayan sistemler, sonlu farklar, interpolasyon, regresyon ve zaman kalırsa adi diferansiyel denklemler. Sayısal çözüm, analitik çözümden farklı olarak kesikli verilerle iteratif biçimde yaklaşık sonuç üretir. Bu yüzden sonuçların nasıl yazıldığı ve ne kadar güvenilir olduğu önem kazanır. Anlamlı basamak (S), ondalık basamak (D), kesme ve yuvarlama, sonuçların adımdan adıma nasıl aktarılacağını belirler. Doğruluk ve hassaslık sonucun kalitesini, hata ve yanlış ayrımı ise farkın kaynağını anlatır.

Dersin sonunda görülen Taylor ve Maclaurin serileri, bir sonraki derste hataları göstermek için, daha sonra da interpolasyon ve türev konularında kullanılacaktır. Bir sonraki derste seri genel bir formül hâline getirilecek ve hata çeşitleri ayrıntılı olarak görülecektir.

> **Hocanın vurgusu:** Bu ders, dinleyerek takip edilirse zor bir ders değildir. Dersleri biriktirirseniz konular birbirine girer. Bir formül, üzerinden defalarca geçildikçe akılda kalır. Ezberlemeyin, işlemlerin neden ve niçin yapıldığını bilin. Ara adımları bilmek, karşınıza yeni bir problem çıktığında bocalamanızı önler. Öğrendiğiniz her şeyi kendiniz için öğrenin. Yarışınız hep kendinizle olsun.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
