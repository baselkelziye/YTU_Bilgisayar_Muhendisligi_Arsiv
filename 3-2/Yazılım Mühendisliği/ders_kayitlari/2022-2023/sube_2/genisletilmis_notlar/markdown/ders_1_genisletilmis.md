# Ders 1 Genişletilmiş Notu: Ders Tanıtımı, Yazılımın Tanımı, Yazılım Türleri ve Eski Yazılım

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Kapsamı ve Kaynakları
- 2. Yazılım Nedir?
- 3. Yaşam Döngüsü ve Yazılımın Yetersizleşmesi
- 4. Yazılım Türleri Neden Önemli?
- 5. Sistem Yazılımı
- 6. Mühendislik ve Bilimsel Yazılım
- 7. Gömülü ve Gerçek Zamanlı Yazılım
- 8. Uygulama Yazılımı ve COTS Standardı
- 9. Kurumsal Yazılım
- 10. Eski Yazılım (Legacy Software)

## 1. Dersin Kapsamı ve Kaynakları

Kaydın ilk saati büyük ölçüde dersin işleyişine ayrıldı; bu kısımlar nota alınmadı. Akademik açıdan önemli olan, hocanın dersin yapısını iki parçaya ayırmasıdır. Birinci parça teoriktir. İkinci parça uygulamalıdır ve çözümleme (analiz), tasarım ve sınama (test) konularından oluşur. Bu konuların da teorisi verilir, ama ağırlık uygulamalı örneklerdedir. Hocaya göre dersin yaklaşık %40-45'i teorik, %55'i uygulamalı kısımdır. Hoca, bir çözümleme ya da tasarım sorusunun tek bir doğru çözümü olmadığını, bu yüzden başkasının çözümüne bakmanın kendi çözümünü yazmanın yerini tutmadığını vurguladı.

Hocanın gösterdiği kaynak listesi şöyledir (ekrandan, 00:55:00):

- Roger S. Pressman, *Software Engineering: A Practitioner's Approach*, McGraw-Hill, 2014, 8. baskı.
- Craig Larman, *Applying UML and Patterns: An Introduction to Object-Oriented Analysis and Design and Iterative Development*, Prentice-Hall, 2004, 3. baskı.
- Ian Sommerville, *Software Engineering*, Pearson, 2015, 10. baskı.
- Martin Fowler, *UML Distilled*, Addison Wesley, 2003, 3. baskı.

Hoca ders notlarının dersin kapsamı için yeterli olduğunu, ama yazılım mühendisliğinde kariyer düşünenlerin bu konuları kitaplardan ayrıca çalışması gerektiğini söyledi. Fowler'ın *UML Distilled* kitabı yalnız UML öğretmekle kalmaz, nesneye yönelik modelleme hakkında önemli dersler de verir. Larman'ın kitabı daha kapsamlıdır: UML'in yanında tasarım kalıplarını da öğretir ve gerçek bir projede olduğu gibi aynı proje üzerinde birden fazla yineleme (iterasyon) gösterir. Kütüphanenin elektronik kaynakları arasında bulunan *UML 2.0 in a Nutshell* kitabı da bazı bölümlerde Larman'ın kitabının yerine kullanılabilir.

## 2. Yazılım Nedir?

Asıl konu anlatımı, dersin odak noktasının tanıtılmasıyla başladı. Bu dersin odak noktası **yazılım geliştirme yaşam döngüsüdür**. Bir yazılım mühendisi yazılım geliştirme sürecinin her aşamasında görev alabilir. Ders, yazılımın bir fikir olarak doğduğu andan emekliye ayrıldığı ana kadar geçen sürecin adımlarının hangi etkinliklerle ve nasıl yürütüleceği üzerine kuruludur. Ders notlarındaki konu sırası da bu döngüyü izler. Yazılım sürecini çalışacağımız için önce "yazılım nedir" sorusuyla başlanır.

Slayttaki tanım şöyledir (ekrandan, 01:15:00):

- Yazılım: herhangi bir boyuttaki herhangi bir tür donanımda çalışan bilgisayar programı **VE** basılı veya elektronik ortamdaki her tür dokümanı içeren üründür.
  - Dokümanlar yazılım geliştirme ekibine ve son kullanıcıya yönelik olabilir.

"Yazılım" denince akla önce çalışan bir program gelir, ama yazılım yalnız program değildir. Dokümanların bir kısmı geliştirme ekibine (teknik belgelendirme), bir kısmı da kullanıcılara (kullanıcı belgelendirmesi) yöneliktir; hocaya göre her ikisi de olabilir ve olmalıdır. Teknik ve kullanıcı belgelendirmesi neredeyse program kadar önemlidir; bunun nedenleri dersin ilerleyen bölümlerinde (bkz. eski yazılım) daha çok vurgulanacaktır.

Yazılım bir üründür, ama her zaman nihai ürün olmayabilir. Bazı yazılımlar başka ürünler geliştirmeye ya da elde etmeye yarayan araçlardır. En basit örnek IDE'lerdir: kendileri birer yazılımdır, ama onları kullanarak kendi programlarımızı geliştiririz. UML şemalarını çizip projeye tümleştirmeye yarayan araçlar da böyledir. Ayrıca yazılım bir takım işi olduğu için takımın ortak çalışmasına yönelik görev atama ve planlama yazılımları da yazılım geliştirme sürecini yürütmek için kullanılır.

## 3. Yaşam Döngüsü ve Yazılımın Yetersizleşmesi

Slayttaki tanıma göre **yaşam döngüsü**, yazılımın bir fikir olarak doğmasından kullanım dışı bırakılmasına kadar geçen süreçtir (ekrandan, 01:15:00).

Yazılım fiziksel bir ürün olmadığı için **aşınmaz**. Hoca bunu bir kalem örneğiyle anlattı: kurşun kalemi kullandıkça ucu körelir, açarsınız, sonunda kalem biter. Versatil kalemin ucunu yenileyebilirsiniz, ama zamanla yayı bozulur, bir parçası kırılır ve kullanılmaz hâle gelir. Yazılım böyle değildir. Üzerinde çalıştığı donanım platformu arızalanmadıkça ve o platforma ek sorumluluklar yüklenmedikçe yazılım aşınmadan çalışır.

Ama yazılım zamanla **yetersizleşebilir**, eksik kalmaya başlar. Bunun nedeni değişimdir:

> **Hocanın vurgusu:** Gerçek hayatta olduğu gibi yazılım mühendisliğinde de değişmeyen tek şey değişimdir. Değişimden kaçamazsınız; yazılım yaşam döngüsü boyunca ister istemez çeşitli değişikliklere uğrayacaktır.

Hoca değişikliklerin iki kaynağını anlattı:

- **Hatalar.** Yazılım geliştirmek zor bir iş olduğu için yazılımda sınama aşamasında bulunamamış hatalar olabilir; sonradan yeni hatalarla karşılaşılabilir. Bu hataları düzeltmek için kod değiştirilir. Bu değişiklikler yazılımın başka yerlerinde beklenmedik yan etkilere yol açabilir; yan etkiler de hataya dönüşürse onların da düzeltilmesi gerekir. Değişiklikler başka değişiklikleri doğurur ve biriktikçe kod en iyi tasarımdan uzaklaşır.
- **Problemin değişmesi.** Yazılımı gerçek dünyadaki bir problemi çözmek için geliştiririz ve o problem zamanla değişebilir. Bir süreci izlemek, yönetmek ya da raporlamak için bir bilgi sistemi yaptıysak, o süreçte pazar koşulları ya da kanun, kural ve yönetmelikler değişebilir. Yazılım bu değişikliklere uyum sağlamazsa eksik kalır ve müşteri onu kullanmayı bırakır. Bu uyum süreci de yönetilmesi gereken ayrı bir süreçtir ve **bakım aşaması** diye adlandırılır.

Slayttaki özet şöyledir (ekrandan, 01:15:00):

- Değişim kaçınılmazdır: yazılım yaşam döngüsü süresince değişikliklere uğrar.
- Değişiklikler yazılımda yeni hatalar oluşturabilir.
- Yeni hatalar tam olarak düzeltilmeden yeni değişiklikler gerekebilir.
- Çözüm: yazılım mühendisliği ilkelerine uyularak daha iyi tasarlanmış yazılım.

Bu etkinlikler çaba ve maliyet doğurur. Çabayı ve maliyeti en aza indirip kârı yükseltmek için yazılım mühendisliği ilkelerine uyarak daha iyi tasarlanmış yazılım elde etmeye çalışırız; dersin konusunun önemi buradan gelir.

## 4. Yazılım Türleri Neden Önemli?

Yazılım türlerinin "mutlaka şöyle sınıflandırılır" denebilecek bir standardı yoktur. Yine de türleri konuşmanın bir amacı vardır. Yazılım mühendisliği süreci gereksinimlerin belirlenmesiyle başlar; oradan bir çözümleme modeli, ondan bir tasarım modeli çıkarılır, sonra yavaş yavaş kodlama (gerçekleme) ve sınama yapılır. Sürecin temelini en kökten etkileyen şey gereksinimler olduğu için, farklı yazılım türlerinin ortak (çekirdek) gereksinimlerini bilmek, kullanılacak yazılım geliştirme sürecini ortaya çıkacak ürüne uyarlamak için önemli bir ilk bilgidir.

Slaytlardaki türler şunlardır (ekrandan, 01:25:00 ve 01:40:00): sistem yazılımı, mühendislik/bilimsel yazılım, gömülü yazılım, uygulama yazılımı ve kurumsal yazılım. Ardından kurumsal yazılımın zamanla dönüştüğü eski yazılım ayrı bir başlık olarak ele alındı.

## 5. Sistem Yazılımı

Slayta göre sistem yazılımı (system software), diğer programlara hizmet sunmak üzere hazırlanmış programlardır; derleyiciler ve işletim sistemleri örnektir (ekrandan, 01:25:00). Hoca ayrıca sunucu sanallaştırma yazılımlarını, bunların yapılandırılmasına ve sınanmasına yarayan yazılımları ve çeşitli Linux dağıtımlarındaki pencere yöneticilerini (ör. GNOME, KDE) örnek verdi. Hepsinin ortak yanı başka programlara hizmet sunmalarıdır.

Bu türün önemli bir özelliği, hizmet verdiği şeydeki değişikliklerden çok etkilenmesidir. Örneğin bir Java derleyicisi yazıyorsak Java'nın temel özellikleri bellidir ve pek değişmez; ama Java'nın her yeni sürümünde yeni yetenekler geliyorsa derleyicinin de bunları destekleyecek şekilde güncellenmesi gerekir. Bu yüzden proje planı yapılırken bu bağımlılık dikkate alınmalıdır.

## 6. Mühendislik ve Bilimsel Yazılım

Slayta göre mühendislik/bilimsel yazılım (engineering / scientific software), mühendislik ve bilimsel hesaplamalarda kullanılmak üzere hazırlanmış programlardır; büyük hacimli verilerle uğraşır ve bu nedenle "numara öğütmek / number crunching" diye anılır (ekrandan, 01:25:00).

Hocanın örnekleri:

- Bir bina tasarımının statik analizini yapan, binanın deprem, rüzgâr gibi dış etkenlere dayanıklılığını hesaplayan yazılım.
- Makine mühendislerinin tasarladığı parçaların zaman içinde ne kadar aşınacağını ya da ne kadar ısınacağını hesaplayıp bir ısı haritası üzerinde gösteren yazılım (kırmızı yerler daha sıcak ya da daha çok aşınan, mavi/yeşil yerler daha soğuk ya da daha az aşınan yerler).
- Gök cisimlerinin hareketlerinin modellenmesi ya da bir reaktördeki nükleer tepkimenin nasıl ilerleyeceğinin simülasyonu. Simülasyon sonuçları teoride üzerinde yeterince düşünülmemiş noktaları ortaya çıkarabilir; bunlar üzerinde düşünülür ve simülasyon yeniden yapılır.

Bu yazılımların ortak noktası çok sayıda ve farklı türde varlığa ait çok büyük hacimli verinin yorumlanması ve işlenmesidir. Yorumlanmamış büyük veriyi alır, "bu parça 800 saat çalıştıktan sonra kırılır mı?" gibi nispeten küçük hacimli ama değerli bir bilgi üretir. "Number crunching" adı buradan gelir.

Bu tür yazılım geliştirilirken o konu alanında uzman kişilerle birlikte çalışmak gerekir. Kimi zaman iş tersinden de yürür: üzerinde çalıştıkları problem zaten karmaşık olduğu için bilim insanları kodlamayı öğrenip yazılımlarını kendileri geliştirmeyi tercih edebilir. Ama bu tek bir kişinin işi değildir; aynı kurumdan ya da farklı kurum ve üniversitelerden araştırmacıların bir araya geldiği ulusal ya da uluslararası projeler biçiminde yürür.

> **Hocanın vurgusu:** Yazılım bir ekip işidir; ayrıntılı ve karmaşık bir iştir. Bir kişinin oturup birkaç haftada ya da ayda bir yazılım çıkardığı dönem çoktan sona erdi.

## 7. Gömülü ve Gerçek Zamanlı Yazılım

Slayta göre gömülü (embedded) yazılım donanım ile çok sıkı ilişkidedir, denetim amaçlıdır ve gerçek zamanlı uygulamalardır (ekrandan, 01:25:00). "Gömülü" denmesinin nedeni donanımla bu sıkı ilişkisidir; genellikle bir donanımı denetlemek, gütmek, sürmek için yazılır ve çoğu zaman gerçek zamanlı olması gerekir.

Hocanın örnekleri bir asansörü kontrol eden yazılım ve yeni yıkama programları ya da modları yüklenebilen akıllı çamaşır/bulaşık makineleridir.

### 7.1 Hassasiyet mi, hız mı?

Hoca gerçek zamanlılığı, bir önceki türle karşılaştırarak açıkladı. Mühendislik ya da bilimsel yazılımda hesaplama isterse bir saat, isterse bir gün, isterse bir hafta sürsün; önemli olan en hassas, en doğru sonucu üretmektir. Gerçek zamanlı yazılımda ise hesaplamaların hızlı yapılması çok önemlidir: "Yeterince hassas olmasın ama anlık ve hızlı olsun" diye düşünülür.

Bunu ısı güdümlü bir füze örneğiyle anlattı. Füze bir uçağa kilitlenip ateşlenmiştir ve uçağın ısısına doğru kendini yönlendirir. Ateş edilen uçak düz uçmaz, kaçınma manevraları yapar. Füzenin uçağın her hareketine karşılık anlık olarak yeni bir yaklaşma rotası (intercept course) hesaplaması gerekir. Füzenin uçağı tam ortasından vurması, hatta ona değmesi bile gerekmez; yeterince yaklaşıp patladığında saçılan birkaç parça bile uçağı düşürmeye yeter. Bu yüzden birkaç milimetre ya da santimetre sapmanın önemi azdır; önemli olan hedefin hareketlerini hızlıca algılayıp yeni rotayı hızla hesaplamaktır. Uçak ayrıca füzeyi aldatmak için yoğun parlayan, işaret fişeğine benzeyen parçacıklar (flare) atar; füzenin bunların flare olduğunu anlayıp yine uçağa yönelme kararını verebilmesi gerekir. Bunlar saniyelik, hatta milisaniyelik işlerdir. Bu tip yazılımları tasarlarken ve kodlarken en çok dikkat edilecek ölçüt hassasiyetten çok hızlı başarımdır.

### 7.2 Gömülü yazılımda yeniden kullanım

Aynı örnek gömülü yazılımın ikinci bir özelliğini de gösterir. Kısa menzilli ısı güdümlü bir füze için güdüm yazılımı geliştirdiğimizi, sonra orta menzilli bir füze geliştirdiğimizi düşünelim. Aynı yazılımı genelde yeni füzede kullanamayız. Menzil değişince içindeki yakıt miktarı değişir; daha çok yakıt taşıması için boyu ve ağırlığı değişir; bu yüzden belki yeni kontrol yüzeyleri (kanatçıklar) eklenir. Sistem tamamen değiştiği için kontrol yazılımı neredeyse sıfırdan yazılmak zorundadır; eski yazılımın ancak çok küçük bir kısmı kullanılabilir.

> **Hocanın vurgusu:** Benzer bir donanım için bile gömülü yazılım planlanırken yazılımın yeniden kullanımı sıfır kabul edilmeli; kaç kişiyle, ne kadar sürede biteceği bu varsayımla kestirilmelidir.

## 8. Uygulama Yazılımı ve COTS Standardı

Slayttaki bilgiler şöyledir (ekrandan, 01:40:00):

- Uygulama yazılımı: product-line, shrink-wrapped, (commercial) off-the-shelf, vb.
  - Bkz. TS/BS ISO/IEC 25051 COTS Yazılım Ürünleri standardı.
  - Bir çok mühendislik alanında olduğu gibi yazılım mühendisliği alanında da tanımlanmış standartlar vardır.
  - Erişim için kütüphaneye başvurunuz; ciddi bilgilere erişim için kütüphaneler kullanılmalıdır.
- Farklı müşteriler tarafından kullanılabilecek genel amaçlı yazılımlar.
- Cari hesap uygulamaları, çeşitli otomasyon programları, kelime işlem uygulamaları, vb.

Uygulama yazılımının (application software) özelliği, farklı müşteriler tarafından kullanılabilecek genel amaçlı yazılımlar olmasıdır. Ofis uygulamaları (kelime işlemci, hesap tablosu), çek-senet ve cari hesap uygulamaları, hastane, postane ve kütüphane otomasyonları örnektir. Bu türün birkaç lakabı vardır ve hoca bunların yazılımın geliştirilme süreci hakkında ipucu verdiğini söyledi.

### 8.1 Product-line

Uygulama yazılımları genel amaçlı olduğu için benzer alanlarda daha önce yazdığınız yazılımların kod parçalarını yeni programda birebir olmasa da az bir değişiklikle kullanabilirsiniz. Ayrıca bu yazılımlar genelde modüllerden oluşur. Örneğin bir kütüphane otomasyonunda ödünç verme modülü, kataloglama modülü ve süreli yayınlar modülü vardır. İnsan kaynağı yeterliyse bu modülleri farklı ekipler geliştirebilir; ya da ekip iş planına göre önce bir modül, sonra diğeri üzerinde çalışır. Hoca bunu fabrika belgesellerinde görülen üretim (montaj) hattına benzetti; "product-line" adı buradan gelir.

### 8.2 Shrink-wrapped ve commercial off-the-shelf

İnternet ve internet üzerinden yazılım dağıtımı yaygın değilken bu yazılımları mağaza rafından alırdık: raftan alındığı için *off-the-shelf*, ticari olduğu için *commercial*. Kutu naylon ambalajla kaplıydı; önce ambalaj açılır, içinden CD ya da DVD çıkar ve kurulum yapılırdı. "Shrink-wrapped" (naylon ambalajlı) adı buradan gelir. Off-the-shelf adı aynı zamanda yeniden kullanımın kolaylığına da işaret eder: ortaya çıkarılan uygulamanın bazı parçaları hazır açık kaynak yazılım geliştirme çerçeveleri ya da kataloglardan seçilen hazır bileşenlerle kurulabilir.

### 8.3 TS/BS ISO/IEC 25051 standardı

Hoca bu tür yazılımların gerçeklenmesi için önerilen bir standardın adını tek tek açıkladı:

- **ISO**, çeşitli mühendislik alanlarında standart oluşturan uluslararası bir kuruluştur. Standartları kendi başına belirlemez; ilgili alandaki uzman kişi ve kurumları uluslararası ölçekte davet edip görüşlerini alır, birçok revizyondan sonra standardın son hâlini çıkarır.
- **IEC** de bir standart kuruluşudur; bu standart ISO ve IEC'nin ortak çalışmasıdır.
- **TS** (Türk Standartları) öneki, Türk Standartları Enstitüsü'nün bu standardı kabul ettiğini, ulusal bağlamda geçerli saydığını ve Türkçeye çevirerek kullanıma sunduğunu gösterir.
- **BS** (British Standards) öneki İngiliz standartlar kurumunun kabulünü gösterir. Metrik sistemi kullanan ülkelerle İngiltere ve ABD'nin ölçü birimleri farklı olduğundan, fiziksel ürünlerle ilgili standartların İngiltere'deki sürümü kendi ölçü birimlerine çevrilerek uyarlanır.
- **25051** standardın numarasıdır. Ardından iki nokta üst üste ve bir yıl gelebilir; bu yıl standardın oluşturulduğu ya da güncellendiği yılı gösterir. Birden fazla yıl varsa en yenisini kullanmak en doğrusudur.
- **COTS**, commercial off-the-shelf'in kısaltmasıdır.

> **Ders sonrası not:** Hoca ISO'nun açılımını "International Standards Organization" diye verdi; kurumun resmî adı büyük olasılıkla International Organization for Standardization'dır. Hocanın derste adını hatırlayamadığı IEC'nin açılımı büyük olasılıkla International Electrotechnical Commission'dır.

Standartlara uymanın yararlarını hoca şöyle sıraladı:

- Farklı bileşenleri kendi sisteminize, ürününüze aktarmayı kolaylaştırır.
- Ürünün dayanıklılık, kullanışlılık gibi kalite ölçütlerini daha üst düzeyde yakalamasını sağlar.
- İyi tanımlanmış bir süreçle çalışıldığı için daha az çabayla daha iyi iş çıkarılır.
- Uluslararası müşterilerle çalışmayı kolaylaştırır: bir müşteri "yalnız şu standartlara uyan ürünleri satın alırım" diyebilir; uymuyorsanız o pazarda satış yapamazsınız.

> **Hocanın vurgusu:** Standartların varlığından haberdar olmanız ve onlara nasıl erişeceğinizi öğrenmeniz çok önemlidir. Ciddi bilgilere erişim için kütüphaneler kullanılmalıdır.

Hoca standarda kütüphanenin veri tabanları üzerinden erişmeyi canlı olarak denedi, ama o an erişim sağlanamadı. Bu sırada mesleğimizle ilgili elektronik dergi veri tabanlarından da söz etti: herhangi bir konuda en ayrıntılı ve güncel bilgi akademik ve teknik yayınlarda bulunur; bizim meslek için en önemli iki kaynak ACM (Association for Computing Machinery) ve IEEE'dir. IEEE, bilgisayar mühendisliği ve kardeş mesleklerde en çok ve en saygın içeriğe ulaşılabilecek kaynaktır.

## 9. Kurumsal Yazılım

Slayttaki bilgiler şöyledir (ekrandan, 01:40:00):

- Belirli ticari iş gereksinimlerine yönelik programlar.
- İş süreçleri ile ilgili bilgiye sahip olmalıdır.
- Genellikle müşteriye özel tasarlanır.
- Veri dönüştürme ve değerlendirme uygulamaları, iş süreçlerinin kimi zaman gerçek zamanlı izlenmesi, vb.
- Zamanla "eski yazılım" haline dönüşür!

### 9.1 Alan bilgisi

Kurumsal yazılım (enterprise software), iş alanıyla ilgili standartlar ve süreçler hakkında konu alanı bilgisine (domain knowledge) sahip olmalıdır. Bu yazılımı geliştirenlerin de konuya en azından aşina olması gerekir. Özellikle gereksinim belirleme ve çözümleme gibi erken aşamalarda, tercihen bütün süreç boyunca, programlamadan anlamasa bile o alanda uzman deneyimi olan biri bulunmalıdır. Her yazılım evi böyle kişileri kadrosunda çalıştıramayabilir; o zaman bu hizmet dış kaynaklı danışmanlık olarak alınır. Belirli bir iş alanına odaklanmış bir yazılım evi ise alan uzmanını kendi bünyesinde çalıştırmayı tercih edebilir. Hoca bunu, her proje için ayrı danışman tutma seçeneğiyle karşılaştırdı. <!-- BELİRSİZ: altyazıda hangi seçeneğin "çok daha avantajlı" bulunduğu net değil (01:55:13-01:55:41). -->

### 9.2 Müşteriye özel tasarım

Hocanın örnekleri: bir bankanın bireysel emeklilik fon yönetimi süreçlerine yönelik iş uygulaması, bir telekom operatörünün faturalama bilgi sistemi, makine ya da çeşitli bileşenler üreten büyük bir firmanın kurumsal kaynak planlama yazılımı. Bu yazılımlar kurumun iş sürecinin vazgeçilmez bir parçası hâline gelir. Aynı sektördeki kurumlar için ortak bir içerik olsa da her kurumun iç sistemleri ve çalışma biçimleri, ülkenin ortak kanun ve yönetmeliklerine ek olarak o kadar farklıdır ki ortak bir payda bulup onu kodlayarak dallandırmak çoğu zaman mümkün olmaz. Bu yüzden aynı yazılım başka bir müşteriye birebir uygulanamaz; o müşterinin iç süreçleri ayrıntılı incelenir ve epey özelleştirilmiş bir yazılım kurulur.

Bir yazılım evi bu işte yeterince uzun süre faaliyet gösterirse, farklı müşterilerle edindiği deneyimle hepsini kapsayan bir ürün geliştirebilir. Bu deneyim, yeni müşteriler için gerekli değişikliklerin daha az emekle ve daha hızlı yapılmasını sağlar.

Hoca bu noktada "bilgisayar mühendisi her şeyden anlar" sözüne değindi. Tek bir alana odaklanmamış, farklı kurumsal uygulama alanlarında çalışan bir yazılım evinde farklı projelere katılan bir mühendis, ister istemez bu problem alanlarının temel bilgisine ve jargonuna sahip olur. Bilgi ve tecrübe, meslek hayatında farklı konu alanlarında bilgi birikimi kazandırır.

## 10. Eski Yazılım (Legacy Software)

Kurumsal yazılımların önemli bir özelliği zamanla eski yazılıma dönüşebilmeleridir. Literatürde "legacy software" diye geçer; hoca bunu "eski yazılım" diye çevirmeyi tercih ediyor. "Legacy" kelime anlamıyla mirastır. Hoca bunu büyüklerden miras kalan bir kol saatine benzetti: artık saate telefondan bakılsa da kol saati hem bir aksesuar olarak hem de telefonun kapalı olması gereken ortamlarda zamanı izlemek için hâlâ kullanılabilen bir üründür.

Slayttaki bilgiler şöyledir (ekrandan, 02:10:00):

- İş sürecinin önemli bir parçası olan ve çok uzun süredir kullanılan yazılımlar.
- Eski yazılımda bulunabilecek olumsuzluklar:
  - Eksik veya hatalı dokümantasyon
  - Zamanla karmaşıklaşmış kod
  - Esnek olmayan yapı
  - Eski donanımla çok sıkı ilişki
  - Yazılım mühendisliğindeki gelişmelerden yoksunluk nedeniyle düşük kalite
- Eski yazılımın değiştirilmesini gerektiren nedenler:
  - İş alanındaki yeni gereksinimler
  - Güncel sistemlerle birlikte çalışabilmesi için uyumluluk kazandırılması
  - Donanımın ömrünün dolması nedeniyle daha güncel ortama taşınma gerekliliği

### 10.1 Neden hâlâ kullanılıyor?

Eski yazılım, kurumun iş sürecinin çok önemli bir parçası olduğu için uzun süredir kullanımdadır; iki üç kuşak önceki çalışanlar zamanında, 10-20 yıl önce yazılmış olabilir. Hocanın örneği, telekom operatörlerinin her ay basıp gönderdiği faturalardır: ilk sayfada genel bilgiler, istenirse arka sayfalarda bütün işlemlerin dökümü, araya reklam ya da kampanya tanıtımları. Bu fatura basma yazılımının her yıl değişmesi gerekmez. İşe yarıyorsa ve gereksinimi karşılıyorsa değiştirmek için bir neden yoktur.

Ayrıca eski yazılım bir kurumsal yazılımsa müşteriye özel tasarlandığı için pahalıya mal olmuştur; ticari bir kuruluş olarak bu yatırımdan en çok geri dönüşü almak için yazılım mümkün olduğunca uzun kullanılır. Değiştirmek istense bile yeni sisteme geçiş aşaması tek başına önemli bir çaba ve maliyet doğurur. Ama bir noktada çeşitli olumsuzluklar yüzünden yazılımın emekliye ayrılması zorunlu hâle gelebilir.

### 10.2 Olumsuzluklar

**Eksik ya da hatalı dokümantasyon.** Bu hem teknik dokümantasyon hem de son kullanıcı dokümantasyonu için geçerlidir. Kaynak kod zamanla değiştikçe yapılan değişikliklerin belgelere aktarılması zaman ve maddi baskılar yüzünden genelde atlanır. Yazılımı kurumun bilgi işlem departmanı yazmış olabilir ve yazan ekip yıllar önce emekli olmuş olabilir. Bir hatayı düzeltmek için bütün kaynak kodu incelemek çok zordur; güncel bir teknik dokümantasyon varsa önce problemle ilgili bölge dokümantasyon yardımıyla bulunur, sonra kod onun eşliğinde incelenir ve iş çok kolaylaşır. Ama dokümantasyon bayatsa işi kolaylaştıracağına zorlaştırır: geçersiz olduğu anlaşılana kadar harcanan zaman verimsiz geçer. Kullanıcı tarafında da "menüden şuraya tıklayın" diyen bir belge, menüde artık o seçenek yoksa teknik olmayan personeli işi kendi başına keşfetmek zorunda bırakır.

> **Hocanın vurgusu:** Dokümantasyonun önemi bu örnekle bir kez daha görülüyor; yazılım kullanımda kaldıkça dokümantasyonda eksik oluşma olasılığı çok büyür.

**Zamanla karmaşıklaşmış kod ve esnek olmayan yapı.** Yazılımın geçireceği bütün değişiklikleri, gereksinim değişikliklerini ve hataları önceden görebilseydik tasarımı ve kodu en baştan ona göre yapardık; ama "kristal küremiz yok". Parça parça yapılan değişiklikler kodu zamanla karmaşıklaştırır; hoca buna "yamalı bohça" dedi. Bazen eski kod silinmez, yorum satırına alınır ve yeni kod eklenir. Neden yorumlandığı, yenisinin neden eklendiği açıklanmazsa sonraki geliştirici bunu anlamakta zorlanır. Sonuçta kodun anlaşılabilirliği ve değiştirilebilirliği azalır, başarımı olabileceğinden düşük kalır. Esnek olmayan yapı için de benzer açıklama yapılabilir.

**Eski donanımla çok sıkı ilişki.** Onlarca yıl önce yazılmış bir yazılım ana çerçeve (mainframe) bilgisayarlarda, örneğin IBM'in AS/400 sisteminde Fortran ya da COBOL ile yazılmış olabilir. Bu donanımın yeni sürümleri çıkmayabilir, teknik servisi verilmeyebilir, arızalanan parçanın yerine yenisi bulunamayabilir; bu çok büyük bir risktir. Daha yeni bir sunucuya geçilecek olsa da o ortamda eski dillerin derleyicileri bulunmayabilir. Hoca, bazı firmaların kurumların ıskartaya çıkardığı eski donanımı, çalışmıyor olsa bile satın alıp parça toplayarak çalışır hâle getirdiğini ve depolarında sakladığını anlattı. Bu firmalar, o donanıma muhtaç kritik bir yazılım çalıştıran müşteriye (ör. her saati büyük kayıp demek olan bir banka ya da sigorta şirketine) bu donanımı yüksek kârla satarak iş modeli kurmuştur.

**Yazılım mühendisliğindeki gelişmelerden yoksunluk.** Eski yazılım, yazıldığı dönemin uygulama ve standartlarına göre yazıldığı için günümüzün standart ve uygulamalarından yoksundur; bu da düşük kaliteye yol açar.

Bu olumsuzluklardan biri ya da birkaçı yazılımla yaşamayı olanaksız hâle getirdiğinde eski yazılım emekliye ayrılmalı ve yerine farklı bir yazılım kullanıma alınmalıdır.

### 10.3 Geçiş nasıl yapılmalı?

Geçiş acil bir durum olarak değil, planlanmış bir süreç olarak yapılmalıdır; özellikle kurumun bilgi işlem departmanında çalışılıyorsa, çünkü o sırada yürüyen bir iş süreci vardır. Genelde belirli bir süre işlemler hem eski hem yeni sistemde **paralel** yürütülür. Yeni sistem gerçek dünya verisiyle sınanıp doğru çalıştığı görüldükten sonra veriler eskiden yeniye aktarılır, eski sistem kapatılır. Yani yumuşak, kademeli bir geçiş planlanıp uygulanmalıdır.

### 10.4 Değiştirme nedenleri ve örnekler

Buraya kadar anlatılanlar çoğunlukla iş alanında değişiklik olmayan senaryolardı. Ama değişim kaçınılmazdır ve iş alanında yeni gereksinimler çıkar:

- **İş alanındaki yeni gereksinimler.** Yeni gereksinimi eski yazılıma eklemek mümkün olmayabilir ya da çok zordur; eski programlama dilini öğrenmek ya da bilen uzmanı bulmak zor olabilir. Hocanın güncel örneği: pandeminin ilk zamanlarında ABD'de federal ve eyalet düzeyinde sosyal yardımlar verilecekti. Kimin hangi koşulda ne kadar destek alacağı, iş ve sigorta kayıtları incelenerek hesaplanmalıydı. Bu bilgi sistemleri ana çerçeve makinelerde COBOL ile yazılmıştı. Bu dili bilenler çoğunlukla emekli olmuş ya da emeklilik yaşına gelmiş kişilerdi; en acil işler bu kişiler yeniden çağrılarak yaptırıldı, gönüllü genç yazılımcılara da COBOL öğretildi. Gençler ise kariyerlerinde kullanmayacakları bir dile zaman ayırmayı genelde yararsız bulur.
- **Güncel sistemlerle uyumluluk.** Artık bütün bilgi sistemlerine internet üzerinden, önce tarayıcıdan, şimdi de mobil uygulamalardan erişilmesi beklenir. İnternetin olmadığı ya da yalnız birkaç kurumda olduğu dönemde yazılmış bir uygulamayı doğrudan internete açamazsınız; ancak ara katman sistemleri koyarak uyumluluk kazandırabilirsiniz ve bu ara sistemler çok verimsiz olur. Bu durumda yeni gereksinimler düşünülerek yeniden tasarlanmış bir yazılıma geçmek gerekir.
- **Bağımlı olunan yazılım ya da donanımın ömrünün dolması.** Hocanın örneği: 15 yıl kadar önce Microsoft'un FoxPro veri tabanıyla yazılmış bir yazılım. Microsoft FoxPro'nun geliştirilmesini ve teknik desteğini yıllar önce durdurdu. Bu yazılımın daha güncel bir ortama taşınması gerekir. Yalnız donanımın değil, yazılımın bağımlı olduğu diğer yazılım bileşenlerinin ömrünün dolması da er ya da geç taşınmayı zorunlu kılar.

## Örnek Sorular

**Soru 1** (derste sözlü, 01:17:58): Yazılım fiziksel bir ürün olmadığı için aşınmaz. O hâlde yazılım zamanla neden yetersizleşir?

> **Cevap (derste verildi):** Değişim kaçınılmazdır. Sınamada bulunamamış hatalar sonradan ortaya çıkar; bunları düzeltmek için yapılan değişiklikler beklenmedik yan etkiler doğurur ve yeni değişiklikler gerektirir. Ayrıca yazılımın çözdüğü gerçek dünya problemi (pazar koşulları, kanun ve yönetmelikler) değişir ve yazılım bunlara uymazsa eksik kalır. Değişiklikler biriktikçe kod en iyi tasarımdan uzaklaşır.

**Soru 2** (derste sözlü, 02:03:18): Bir telekom operatörünün fatura basma yazılımının her yıl değişmesi gerekir mi?

> **Cevap (derste verildi):** Hayır. Yazılım işe yarıyor ve gereksinimi karşılıyorsa değiştirmek için neden yoktur; bu yüzden 10-20 yıl önce yazılmış yazılımlar hâlâ kullanılabilir. Müşteriye özel kurumsal yazılımlar pahalı olduğu ve geçiş de ayrı bir maliyet doğurduğu için mümkün olduğunca uzun kullanılır.

**Soru 3** (derste sözlü, 02:17:09): İnternetin olmadığı dönemde hazırlanmış bir uygulamayı internete nasıl açarsınız?

> **Cevap (derste verildi):** Doğrudan açamazsınız. Ancak ara katman sistemleri koyarak eski sisteme uyumluluk kazandırabilirsiniz; bu ara sistemler de çok verimsiz olur. Bu yüzden bir noktada yeni gereksinimlerle birlikte yeniden tasarlanmış bir yazılıma geçmek gerekir.

## Dersin Toparlaması

Bu derste, dersin odağının yazılım geliştirme yaşam döngüsü olduğu belirtildikten sonra yazılımın tanımı verildi: yazılım yalnız program değil, programla birlikte geliştiriciye ve kullanıcıya yönelik bütün dokümanları içeren bir üründür. Yazılım aşınmaz ama değişim kaçınılmaz olduğu için zamanla yetersizleşir; bunun çaresi yazılım mühendisliği ilkeleriyle daha iyi tasarlanmış yazılımdır. Ardından sistem, mühendislik/bilimsel, gömülü, uygulama ve kurumsal yazılım türleri, her birinin ayırt edici gereksinimleriyle (hizmet verilen ortama bağımlılık, büyük veri ve doğruluk, gerçek zamanlılık ve düşük yeniden kullanım, genel amaçlılık ve modülerlik, alan bilgisi ve müşteriye özel tasarım) anlatıldı. COTS yazılımlar için TS/BS ISO/IEC 25051 standardı üzerinden standartların önemi vurgulandı.

Son olarak kurumsal yazılımların zamanla dönüştüğü eski yazılım ele alındı: neden uzun süre kullanıldığı, beş olumsuzluğu ve değiştirilmesini gerektiren üç neden. Ders slaytların 9. sayfasında bitti; hoca bir sonraki derste yazılımı etkileyen eğilimlerle devam edileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
