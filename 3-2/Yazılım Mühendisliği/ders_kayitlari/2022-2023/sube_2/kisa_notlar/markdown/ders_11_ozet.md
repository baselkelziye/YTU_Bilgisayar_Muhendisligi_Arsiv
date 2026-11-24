# Ders 11 Çalışma Özeti

## Genel Konular

- Yazılım sınamasının (testing) önemi ve genel bilgiler (ekrandan, 00:10:00)
  - Yazılım geliştirme karmaşık ve zihinsel yoğunluğu yüksek bir süreç olduğundan hataların ortaya çıkması kaçınılmazdır. Önemli olan hataları keşfetmek ve düzeltmektir.
  - Yazılım, yaşam döngüsünün her aşamasında sınanır; kod yazılmadan da sınama yapılabilir:
    - Gereksinimler arasındaki tutarsızlıklar,
    - Çözümleme şeması ile uygulama alanı arasındaki uyumsuzluklar (sınıflar ve ilişkiler gerçek dünyadaki varlıklarla örtüşüyor mu?),
    - Tasarım hataları ve çalışma anı hataları.
  - Kod dışındaki yapıtların (artifact) sınanması resmi teknik gözden geçirme (formal technical review) ile yapılır.
  - Yaşam döngüsünde ilerledikçe değişiklik yapmanın maliyeti üstel olarak artar; bu yüzden sınamaya erken başlanmalıdır. İyi bir sınama yaklaşımı hataların erken bulunmasını sağlar ve yazılımın kalitesini arttırır.
- Bir sınama yaklaşımının dört bileşeni
  - Planlama: sınamayı kim yapacak, toplam proje çabasının ne kadarı sınamaya ayrılacak? Örneğin çabanın %10'u sınamaya ayrılabilir; disiplinli ve otomatik araçlarla yapılan sınamada bu iyi bir orandır.
  - Tasarım: kodun neresinin, nasıl sınanacağına karar verilir.
  - Çalıştırma: testler koşturulur.
  - Bilgi toplama ve değerlendirme: bulunanlar gerçekten hata mı, düzeltmeye ne zaman ayrılacak, kim yapacak?
  - Bu adımlar şelale gibi sıralı değildir. Sınama tekrarlı ve sürekli bir etkinliktir, çünkü bir hatanın düzeltilmesi başka hatalara yol açabilir.
- Sınama yaklaşımlarının genel özellikleri (ekrandan, 00:20:00)
  - Sınama bileşen düzeyinde başlar ve sistem düzeyinde biter. Ürün yalnız yazılımdan oluşmayabilir; algılayıcılar, harici sistemler, IoT cihazları olabilir.
  - NYP'de sınıfların bireysel sorumluluklarından başlanıp yazılımın üst düzey sorumluluklarına kadar bütün işlevler sınanır.
  - Yaşam döngüsünün farklı aşamalarında farklı sınama teknikleri uygundur.
  - Sınama hem bileşeni yazan kişi hem de bağımsız kişiler tarafından yapılır; büyük kurumlarda ayrı bir sınama ekibi bulunabilir.
  - Sınama (testing) ile hata ayıklama (debugging) ayrı işlerdir; ancak hata ayıklama her sınama yaklaşımının önemli bir parçasıdır.
- Sınama ekibinin örgütlenmesi
  - Bağımsız sınama ekibi yoksa ya farklı projelerin ekipleri birbirinin kodunu sınar ya da aynı projenin kişileri döngüsel olarak birbirini sınar (A'nınkini B, B'ninkini C, ..., sonuncununkini A).
  - Neden başkası sınamalı? Sınama "yıkıcı" bir etkinliktir: amaç kodun çalışmadığı durumları bulmaktır. Kodu yazan kişi bilinçaltında kodun çalıştığını göstermeye eğilimlidir.
- Sınama yaklaşımının belirlenmesi (ekrandan, 00:30:00)
  - Sınama, en çok çaba gerektiren yazılım mühendisliği etkinliklerindendir.
  - Sınama, bütün hataların yakalanacağı bir "güvenlik ağı" değildir; ne kadar çaba harcansa da yakalanamayan hatalar olacaktır.
  - Hedefler açıkça belirlenmelidir: testlerin kapsama alanı (code coverage, örneğin %60-75 gibi bir eşik), ayrılacak kaynak (zaman, kişi, bütçe), yazılımın türüne göre ölçütler (bilimsel uygulamada hassasiyet, gerçek zamanlı uygulamada yanıt süresi, MTBF, MTTR).
  - Sınamalar otomatikleştirilmeli; sınama süreci ölçülmeli ve iyileştirilmelidir.
- Sınama türleri (ekrandan, 00:55:00)
  - Yaklaşım tarzına göre: kara kutu (black-box) ve beyaz kutu (white-box) sınaması.
  - Yürütülme sırasına göre: önce doğrulama (verification), sonra geçerleme (validation) sınamaları.
- Doğrulama sınamaları: birim ve tümleştirme sınamaları (ekrandan, 01:00:00 ve 01:10:00)
  - Birim sınamaları en küçük bileşenin, NYP'de bireysel sınıfların sınanmasıdır.
  - Gerekli diğer sınıflar hazır değilse vekil (stub, dummy, surrogate, proxy) kod kullanılır.
  - Tümleştirme sınamaları, tek başına doğru çalışan birimlerin bir arada da doğru çalışıp çalışmadığını sınar. Türleri: tahribat sınaması (smoke testing) ve geriye dönük sınama (regression testing) (ekrandan, 01:15:00).
- Geçerleme sınamaları: alfa ve beta (ekrandan, 01:25:00 ve 01:30:00)
- Sistem sınamaları: kurtarma, güvenlik, zorlama, başarım (ekrandan, 01:40:00)
- Hata ayıklama (debugging) (ekrandan, 01:45:00)
- Yazılım gözden geçirme ve IEEE 1028'e göre resmi gözden geçirme adımları (ekrandan, 01:50:00 ve 01:55:00)
- JUnit ile birim sınaması (ekrandan, 02:15:00 - 02:25:00)
  - JUnit, Java kodunun birim sınaması için bir çerçeve programdır (framework). Diğer diller için de sürümleri vardır (örneğin C# için csUnit). Eclipse ve NetBeans'te hazır gelir.
  - 3.x sürümünde adlandırma kuralları, 4.x sürümünde annotation desteği.
- Uygulama: Fowler'ın video kaset kiralama örneği üzerinde JUnit test case'leri (ekrandan, 02:35:00 - 03:05:00)

## Hocanın Özellikle Vurguladığı Kısımlar

- Sınama yalnız kod üzerinde yapılmaz
  - Gereksinim belirleme aşamasında bile, örneğin gereksinimler arası tutarsızlık için, sınama (gözden geçirme) yapılabilir. "Kod bitmeden test yapılamaz" düşüncesi yanlıştır.
- Sınama yıkıcı bir eylemdir
  - Kodu yazan kişi kodun çalıştığını göstermeye, sınayan ise çalışmadığı durumu bulmaya çalışır. Bu yüzden bir bileşen yazarından başka kişilerce de sınanmalıdır.
  - Hoca bir kamu kurumu örneği verdi: çalışanlardan kendi dosyalarındaki hataları bulmaları istendiğinde sınırlı iyileşme oldu; başkasının dosyalarını incelemeleri istendiğinde çok daha fazla hata bulundu.
- Sınama bir güvenlik ağı değildir
  - Sirk cambazlarının altındaki güvenlik ağı gibi bütün hataları yakalamaz. Amaç kaçan hata sayısını en aza indirmektir.
- Doğrulama önce, geçerleme sonra yapılır
  - Doğrulama: "Yazılımı doğru mu yapıyoruz?", yazılım ekibi yapar. Geçerleme: "Doğru yazılımı mı yapıyoruz?", son kullanıcı yapar.
  - Hatırlatma: Türkçede D (doğrulama) G'den (geçerleme) önce gelir. İngilizcede ise alfabede sonra gelen verification önce yapılır. "Önce doğrulama, sonra geçerleme" diye hatırlanmalıdır.
- Alfa ve beta sınamasının farkı
  - Hoca farkları bir tabloyla özetledi ve "bu aklınızda olsun" dedi (ekrandan, 01:35:00): alfada gayri resmi haberleşme ve her hatanın anlık bildirimi, betada resmi haberleşme ve hataların toplu bildirimi.
- Sınama ve hata ayıklama "angarya" değildir
  - Bu işler ikinci sınıf ya da ayak işi gibi görülmemeli, yalnız stajyerlere ya da yeni başlayanlara bırakılmamalıdır. Ünlü programcılara göre hata ayıklama kod yazmaktan daha zordur ve daha çok yetenek ister.
- Test metodlarına açıklayıcı adlar verilmelidir
  - "test1, test2" yerine neyi sınadığını anlatan uzun adlar (örneğin `testStatementWhenEmpty`) seçilmelidir. Test başarısız olunca sorunun kaynağına daha hızlı ulaşılır.
- Her test metodunda tercihen tek bir assert
  - Birden çok assert kullanılabilir, ama biri bile başarısız olursa bütün test başarısız sayılır. En bireysel düzeyde sınamak en doğrusudur.

## Kısa Tekrar Notları

- Sınama yaklaşımının bileşenleri: planlama, tasarım, çalıştırma, bilgi toplama ve değerlendirme.
- Sınama bileşen düzeyinde başlar, sistem düzeyinde biter.
- Sınama ≠ hata ayıklama. Sınama hatayı arar, hata ayıklama düzeltir.
- Kara kutu: iç yapı bilinmez; yalnız girdi/çıktı spesifikasyonuna bakılır. Beyaz kutu: iç yapı bilinir, kod kapsaması ölçülebilir, daha masraflıdır. Kritik bileşenlere beyaz kutu, daha az kritik olanlara kara kutu uygulanabilir.
- Doğrulama (birim + tümleştirme): yazılım evinde, teknik ekip yürütür.
- Geçerleme (alfa + beta): müşteri yürütür. Alfa yazılım evinde, beta müşteri ortamında yapılır.
- Birim sınaması: TDD'de kodlamadan önce, ya da kodlama sırasında ya da sonrasında tasarlanır; kodlama sırasında ya da sonrasında yürütülür.
- Vekil (stub/dummy/surrogate/proxy) kod basit tutulmalı (örneğin `return true;`). Basit tutulamıyorsa ortak sorumlulukların sınanması tümleştirmeye bırakılır.
- NYP'de birim ve tümleştirme sınamalarını ayıran kesin çizgi yoktur.
- Smoke testing: yüzeysel ama başarısız olursa bütün sistemi durduran (show-stopper) hataları arar; günlük derleme (build) ile her gün yapılır.
- Regression testing: yeni işlev eklenince sınamaların yeniden koşturulması. Ölçek düştükçe sınama sıklaşır, masraf artar.
- Sistem sınamaları: kurtarma (MTTR), güvenlik, zorlama (stress), başarım (performance).
- IEEE 1028 resmi gözden geçirme adımları: değerlendirme başlangıcı, yönetimin hazırlanması, prosedürlere genel bakış, bireysel hazırlık, grup incelemesi, düzenleme, sonlandırma.
- JUnit 3.x: test sınıfı `TestCase`'ten türetilir, sınıf ve metod adları `test` ile başlar, `setUp()` her test metodundan önce yeniden çalışır, `suite()` ile test takımı kurulur.
- JUnit 4.x: kalıtım ve adlandırma zorunluluğu kalkar; `@Test`, `@Before`, `@Test(expected=X.class)` kullanılır.
- Yeşil çubuk: bütün testler başarılı. Kırmızı çubuk: en az bir test başarısız; Failure Trace "expected ... but was ..." farkı gösterir.

## Detaylı Açıklamalar

- Planlama ve kapsama
  - Sınama projeden bağımsız değildir; toplam süre ve toplam adam-ayın ne kadarının sınamaya ayrılacağı önceden belirlenmelidir. Hoca %10'luk bir payın küçümsenmemesi gerektiğini, uygulamada %5 bile ayrılmadığını söyledi. Örnek olarak yakın zamanda çıkan bir oyunda çok sayıda show-stopper hata görülmesini verdi.
  - Yazılımın %100'ünü sınamak bütçe açısından olanaksızdır; %60, %70, %75 gibi bir kapsama eşiği seçilir. Gerçekleme gecikmişse daha düşük bir kapsama kabul edilebilir; temel ölçüt kaynaktır.
  - MTBF (mean time between failures): art arda gelen iki hata arasındaki ortalama süre. MTTR (mean time to repair): bir hatanın düzeltilmesinin ortalama ne kadar sürdüğü.
- Kara kutu ve beyaz kutu
  - Kara kutu örneği: iç yapısı bilinmeyen bir tümdevre. İlk 8 bacaktaki bitlerle oluşan tamsayı ile diğer 8 bacaktakinin bitwise OR'u çıkışa veriliyorsa, devre açılınca kendini imha ediyorsa, yalnız farklı girdilerle sınanabilir. Yazılımda kaynak kodu elde olmayan bileşenler de böyle sınanır.
  - Beyaz kutu sınamada kod kapsaması bilinebilir. Örneğin 4 dallı bir `if` yapısında testlerin yalnız 3 dalı kapsadığı görülebilir.
  - Yeniden kullanılan kod kitaplıklarında testler zaten hazırdır. Yeni kullanım senaryoları eklendikçe önce kara kutu, daha sonra beyaz kutu testleri eklenebilir.
- Birim sınaması
  - TDD'de birim testleri koddan önce tasarlanır; kodlama yalnız bu testleri geçecek kodu yazmaya odaklanır. Bu, çevik süreçlerdeki KISS (Keep It Simple) ilkesine uyar. Fazladan iş yapmak, değişme olasılığı yüksek gereksinimler yüzünden boşa gidebilir.
  - Beyaz kutu çalışılacaksa testleri kod yazıldıktan sonra tasarlamak daha mantıklıdır. TDD'de başta kara kutu ağırlıklı başlanır; sonraki döngülerde beyaz kutuya zaman ayrılabilir.
  - Bir nesne sorumluluğunu bağlaşımda bulunduğu diğer nesnelerle birlikte yerine getirir. Bağımlılıklar "karışmış bir iplik yığını" gibidir ve gereken sınıflar başka programcıların takviminde olabilir. Bu yüzden vekil kod yazılır: örneğin boolean döndüren bir metodun gövdesine yalnız `return true;` yazılır. Tümleştirme aşamasında vekilin yerini gerçek kod alır.
  - Birim testlerinde aranacak tipik hatalar: kalıtım ve çok biçimlilikte yan etkiler; C'deki `union` gibi aynı bellek alanına farklı bakış açıları; enum yerine sabit tamsayı kullanınca farklı anlamdaki değerlerin karışması (örneğin abonelik paketi kodu ile kan grubu kodunun aynı `int` ile tutulması); kuvvetli tiplemeli olmayan dillerde tür sorunları; `and/or/not` mantık hataları; işaretçi yan etkileri; operatör önceliği; Java'da `+` operatörünün hem toplama hem string birleştirme yapması; sonsuz döngü; bir eksik/bir fazla eleman işleme. Hocanın özeti: şimdiye kadar yapılan hatalardan ders çıkarıp bunları yakalayacak test yazmak.
- Tümleştirme sınaması
  - Hocanın benzetmesi: halka açık bir tuvalette el kurutma makinesi ve çöp kutusu ayrı ayrı kalite belgelerine sahip olabilir; ama çöp kutusu kurutucunun altına takılırsa üflenen hava kâğıtları etrafa saçar. Parçalar tek başına doğru, birlikte yanlış çalışır.
  - Yazılımda bunun nedeni, her ayrıntının önceden belirlenememesi ve programcıların belirsiz noktalarda kendi inisiyatifleriyle farklı kararlar vermesidir. Aynı kişinin farklı zamanlarda verdiği kararlar bile çelişebilir.
  - Smoke testing: terim eski mühendislik dallarından gelir; motor çalıştırılınca olmaması gereken yerden duman çıkmıyorsa "şimdilik iyi" denir. Hoca IT alanından örnek olarak Windows 98'in tanıtımında mavi ekran alınmasını gösterdi. Kod, yapılandırma dosyaları ve dış kitaplıklar bir araya getirilip (build) günlük olarak sınanır.
  - Regression testing: testler hızlı koşuyorsa her eklemede hepsi koşturulur. Yavaş ya da masraflıysa yalnız etkilenen parçalar koşturulur ve bağımlılık zincirinde kaç düzey geri gidileceğine karar verilir. Örnek: D işlevi eklendi; C, D'ye bağımlı; B, C'ye; A, B'ye. "En fazla iki düzey geri gidilir" gibi bir sınır planlamada belirlenir.
- Geçerleme sınaması
  - Kullanıcı, gereksinimler belgesindeki işlevselliğe, özellikle kullanım senaryosu metinlerine dayanarak sınar: ön koşullar, ana senaryonun adımları ve alternatif senaryolar tek tek denenir.
  - Teknik ekip son kullanıcının beklenmedik davranışlarını öngöremez: "bilgisayarımın fincan tutacağı çalışmıyor" (DVD sürücüsünün tepsisini fincan altlığı sanan kullanıcı), "pencereyi aç" denince evin penceresini açmak gibi.
  - Eric Raymond: "given enough eyeballs, all bugs are shallow", yani yeterince göz bakarsa hiçbir hata derin değildir.
  - Alfa: kullanıcı, yazılım firmasında, geliştirme ekibinin denetimi ve izlemesiyle sınar; doğal kullanım ortamına en yakın koşullar kurulur. Örnek: kütüphane bilgi sistemi için banko, raf, barkod/RFID okuyucu ile küçük bir kütüphane ortamı.
  - Beta: müşterinin kendi yerinde, gerçek kullanım ortamında yapılır, geliştirme ekibi müdahale etmez. Hatalar düzenli aralıklarla, resmi biçimde (form ya da Jira benzeri görev sistemi ile) bildirilir. Formda hatanın kısa ve ayrıntılı tarifi, yol açan adımlar, hata mesajı veya ekran görüntüsü, kullanılan bilgisayar ve işletim sistemi bulunur. Betayı "az sınayıp işi müşteriye yıkmak" diye kullanmak prestij kaybettirir.
- Sistem sınamaları
  - Yazılım tek başına sistemin bütünü olmayabilir (gömülü uygulamalar, ara katman yazılımları).
  - Kurtarma (recovery): hatalara dayanıklı (fault tolerant) sistemler için. Örnek: bankalar arası para aktarımında bir adımda hata olursa sistem işlemler başlamadan önceki tutarlı duruma geri dönebilmeli (rollback). Kurtarma belli bir sürede (MTTR) tamamlanmalıdır.
  - Güvenlik (security): "Tek kural: kural yok", "Her güvenlik önünde sonunda aşılır". Örnekler: açılınca asit kapsülüyle kendini bozan tümdevrelere karşı ısı ölçümü gibi yan kanallarla bilgi toplama; ekranın duvara düşen yansımasından görüntü çıkaran yazılımlar. Amaç, kırılma süresinin bilginin değerli olduğu süreden uzun olmasıdır: gece 12'de gönderilen ve sabah 4'te uygulanacak bir emrin şifresini kırmak 6 saat sürüyorsa emir güvendedir.
  - Zorlama (stress): normalin dışındaki yüklenmede sistemin nereye kadar dayanabildiği sınanır.
  - Başarım (performance): gerçek zamanlı uygulamalarda önemlidir; program doğru sonucu üretebilir ama zamanında üretemeyebilir. Örnek: ani manevra yapan hedefi izleyen bir füzenin yönü belki %80 doğrulukla ama hızlı bulması gerekir.
- Resmi teknik gözden geçirme
  - Sınamadan önce ve daha az masrafla hata bulmayı amaçlar. Sınamayla bulunabilecek bütün hataları bulamaz, ama daha verimlidir. Gereksinimlerin eksik belirlenmesi projeyi başarısızlığa götürdüğü için önemlidir.
  - Resmi gözden geçirme belli kurallar çerçevesinde ve yazılı yapılır. Gayri resmi olan sözlü ve gerektiğinde yapılır. Çalışmalar resmi olanın daha etkili olduğunu göstermiştir. XP'deki eşli programlama da bir tür (gayri resmi) gözden geçirmedir.
  - Toplantı biçiminde yapılır, bir yöneticisi (review leader) vardır. IEEE 1028 adımları:
    - Değerlendirme başlangıcı: yönetici standart bir checklist ile toplantının koşullarını (salon, cihazlar, katılımcılara zamanında bildirim) sağlar.
    - Yönetimin hazırlanması: gerekli kaynaklar hazırlanır, toplantının standarda uygun yürütülmesi sağlanır.
    - Prosedürlere genel bakış: bütün değerlendiricilerin amaçları ve prosedürleri anladığından emin olunur.
    - Bireysel hazırlık: değerlendiriciler malzemeyi (örneğin gereksinim belgesini) inceler ve olası bozuklukları (anomaly) not eder.
    - Grup incelemesi: bulgular toplantıda paylaşılır; her bulgunun gerçekten hata olup olmadığı tartışılarak uzlaşıya varılır.
    - Düzenleme: yazarlar ya da atanan başka bir ekip düzeltmeleri yapar (örneğin bir sorumluluğun başka sınıfa taşınması, proje planının düzenlenmesi).
    - Sonlandırma: yönetici düzeltmelerin doğruluğunu, yeterliliğini ve tutarlılığını inceler.
- JUnit 3.x yapısı (ekrandan, 02:20:00)
  - `myPackage` içindeki `AppClass1` için `TestAppClass1`, `AppClass2` için `TestAppClass2` sınıfları yazılır. Bu test sınıfları `junit.framework.TestCase`'ten kalıtımla türetilir ve test metodlarının adı `test` ile başlar.
  - `TestAll` sınıfının statik `suite(): Test` metodu test case'leri bir test takımında (suite) toplar.
  - `Assert` sınıfının public static metodları: `assertEquals(beklenen, sonuc: Object)`, `assertNotEquals(Object, Object)`, `assertTrue(boolean)`, `assertFalse(boolean)`, `assertNull(Object)`, `assertNotNull(Object)`.
  - `assertEquals` beklenen nesne ile sonuç nesnesi aynıysa testi başarılı sayar. Parametreler `Object` türündedir, çünkü Java'da her sınıf `Object`'in alt sınıfıdır.
  - `TestCase.setUp()` (protected) her `testXXX()` metodundan önce yeniden çalışır. Gerekli nesneler (sahne) burada oluşturulur ve ilişkilendirilir; örneğin bir derse öğrenci ekleme senaryosu için önce ders ve öğrenciler oluşturulur.
- JUnit 4.x (ekrandan, 02:25:00 ve 02:30:00)
  - Geriye doğru uyumluluk korunmuştur. Kalıtım ve `test` öneki zorunlu değildir; test metodlarının başına `@Test`, hazırlık metodunun başına `@Before` konur (hoca slayttaki küçük harfli yazımı düzeltti; doğrusu büyük harfle `@Test`, `@Before`).
  - Annotation'lar derleyici için bir tür yorumdur; kaynak kod üzerinde çalışan başka programlara bilgi verir (örneğin `@SuppressWarnings` derleyiciye yöneliktir).
  - Exception sınaması: `@Test(expected=SomeException.class)` yazılan metodda o exception oluşursa test başarılı sayılır.

```java
@Before
public void setUp() { /*Preparations*/ }
@Test
public void testSomething() { /*Do test*/ }

@Test(expected=SomeException.class)
public void testTheException() throws Exception {
    doSomethingThatCreatesTheException();
}
```

- Video kaset kiralama örneği (ekrandan, 02:35:00)
  - Kaynak: Martin Fowler, *Refactoring: Improving the Design of Existing Code*, Addison-Wesley, 1999. Kitap, kod kokularının (code smell) nasıl tespit edilip düzeltileceğini anlatır. Yeniden düzenleme (refactoring) adım adım yapılır ve her adımdan sonra birim sınamaları (geriye dönük olarak) koşturulur.
  - Sınıflar: `Customer` (`statement()`, `getTotalCharge(): double`, `getTotalBonus(): int`), `Rental` (`_daysRented: int`, `getCharge(): double`, `getBonus(): int`, `getMovieTitle(): String`), `Movie` (`_priceCode: int`, `getCharge(daysRented: int): double`, `getBonus(daysRented: int): int`). İlişkiler: bir `Customer` çok sayıda `Rental`'a, her `Rental` bir `Movie`'ye bağlıdır.
  - Üye alanların `_` ile başlaması, kitabın siyah-beyaz basılmasında üye alanları ayırt etmek içindir.
  - `getMovieTitle()` `Rental`'da tutulur: müşteri filmin adını kiralama nesnesinden ister. Böylece doğrudan bağlaşım dolaylı olur ve bütün `Movie` nesnesi yerine yalnız bir string döner.
  - Hocanın tasarım eleştirisi: fiyat kodunu `int` ile tutmak yerine enum, daha iyisi `Movie`'yi soyut üst sınıf yapıp normal, yeni çıkan ve çocuk filmlerini alt sınıflar olarak tasarlamak (çok biçimlilik).
  - Fiyatlandırma (ekrandan, 02:50:00 ve 03:05:00): normal film 2 lira ile 2 gün, sonrası günde 1,5; yeni film günde 3; çocuk filmi 1,5 lira ile 3 gün, sonrası günde 1,5. Bonus: her kiralama 1 puan; yeni film 1 günden uzun kiralanırsa 2 puan.
  - Örnek test (ekrandan, 02:55:00): normal film 3 gün (3,5), çocuk filmi 4 gün (3,0), yeni film 2 gün (6,0); toplam borç 12,5, toplam 4 puan. Python ile doğrulandı.
  - Eclipse'te JUnit: proje → Configure Build Path → Add Library → JUnit (3, 4, 5 hazır) ya da junit.org'dan indirilen JAR'ı "Add External JARs" ile eklemek. Çalıştırma: Run As → JUnit Test.
  - Hata gösterimi: hoca normal filmin ek gün ücretini bilerek yanlış kodladı. Kırmızı çubuk çıktı ve Failure Trace beklenen ile elde edileni farkın başladığı yerden köşeli parantezle gösterdi (normal filmde 3,5 yerine 3,0; toplamda 12,5 yerine 12). Kod düzeltilip bütün testler yeniden koşturulunca yeşil çubuk görüldü.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
