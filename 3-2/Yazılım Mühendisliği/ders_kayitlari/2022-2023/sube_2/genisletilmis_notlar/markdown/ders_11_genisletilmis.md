# Ders 11 Genişletilmiş Notu: Yazılım Sınama Teknikleri: Sınama Türleri, Resmi Gözden Geçirme ve JUnit ile Birim Sınaması

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Yazılım Sınamasına Genel Bakış
- 2. Sınama Yaklaşımının Bileşenleri
- 3. Sınama Yaklaşımlarının Genel Özellikleri
- 4. Sınama Ekibinin Örgütlenmesi ve Sınamanın Psikolojisi
- 5. Sınama Yaklaşımının Belirlenmesi: Hedefler ve Ölçütler
- 6. Sınama Türleri: Kara Kutu ve Beyaz Kutu
- 7. Doğrulama ve Geçerleme
- 8. Birim Sınamaları
- 9. Tümleştirme Sınamaları
- 10. Geçerleme Sınamaları: Alfa ve Beta
- 11. Sistem Sınamaları
- 12. Hata Ayıklama
- 13. Yazılım Gözden Geçirme ve IEEE 1028
- 14. JUnit ile Birim Sınaması
- 15. Uygulama: Video Kaset Kiralama Örneği
- Örnek Sorular
- Dersin Toparlaması

## 1. Yazılım Sınamasına Genel Bakış

Bu derste yazılım sınama teknikleri konusuna geçildi. Hoca, sınamanın başlı başına bir uzmanlık alanı olduğunu ve bu derste yalnızca temellerin verileceğini söyledi. Bu temeller dönem projesinde yapılacak birim sınamaları için de gereklidir.

Ekrandaki ilk slayt sınamanın neden gerekli olduğunu özetliyordu (ekrandan, 00:10:00). Yazılım geliştirme karmaşık ve zihinsel olarak yoğun bir süreçtir; bu yüzden hataların ortaya çıkması kaçınılmazdır. Hata olması doğaldır; önemli olan hataları keşfetmek ve düzeltmektir.

Hocanın üzerinde durduğu ilk nokta, sınamanın yaşam döngüsünün **her aşamasında** yapılabilmesiydi. "Yazılım bitmeden ve kod çalışmadan test yapamam" düşüncesi yanlıştır. Slaytta sınanabilecek şeyler şöyle sıralanıyordu:

- Gereksinimler arasındaki tutarsızlıklar,
- Çözümleme şeması ile uygulama alanı arasındaki uyumsuzluklar: tasarladığımız sınıflar, nesneler ve aralarındaki ilişkiler gerçek dünyadaki varlıklarla örtüşüyor mu, eksik var mı?
- Tasarım hataları: tasarım gereksinimleri karşılıyor mu?
- Çalışma anı hataları: kod çalıştırıldığında hata veriyor mu, kullanım senaryolarında belirtildiği gibi çalışıyor mu?

Kod dışındaki yapıtlar (artifact) resmi teknik gözden geçirme (formal technical review) ile sınanır. Bu konu dersin sonunda işlendi.

Sınamaya erken başlamanın temel nedeni yaşam döngüsünün maliyet dinamiğidir. İlk derslerden beri söylendiği gibi, yaşam döngüsünde ilerledikçe yazılımda değişiklik yapmanın maliyeti üstel olarak artar. Hataları düzeltmek de buna bağlı olarak zorlaşır. İyi bir sınama yaklaşımı hataların erken bulunmasını sağlar, düzeltmeyi kolaylaştırıp ucuzlatır ve yazılımın kalitesini arttırır.

## 2. Sınama Yaklaşımının Bileşenleri

Literatürdeki yaklaşımlar bir temel çerçeve sunar. Her yazılım evi bu çerçeveyi kendi ayrıntılarıyla uygulayabilir. Farklı yazılım türlerinin gereksinimleri farklı olduğundan sınama etkinlikleri de yazılımın isterlerine göre farklılaşmalıdır. Slayta göre (ekrandan, 00:10:00) bir sınama yaklaşımı dört bileşeni içermelidir:

- **Planlama:** Sınamayı kimler yapacak? Daha önemlisi, sınamaya ne kadar zaman ve çaba ayrılacak? Sınama projeden bağımsız bir süreç değildir. Toplam sürenin ve toplam adam-ayın ne kadarının sınamaya ayrılacağı önceden belirlenmelidir; yoksa sonradan işler karmaşıklaşır.
- **Tasarım:** Kodun neresinin, nasıl sınanacağına karar verilir.
- **Çalıştırma:** Tasarlanan testler koşturulur.
- **Bilgi toplama ve değerlendirme:** Elde edilen bulgular gerçekten hata mı? Düzeltmeye ne zaman ayrılacak, kim yapacak, nasıl yapacak?

Hoca planlama için bir oran örneği verdi: toplam çabanın %10'u sınamaya ayrılabilir. Bu oran küçümsenmemelidir. Disiplinli biçimde ve otomatik araçlarla yürütülen sınama, harcanacak emeği azalttığı için %10 aslında iyi bir rakamdır. Hocanın gözlemine göre birçok yazılım evi %5 bile ayırmamaktadır. Uluslararası piyasada da durum farklı değildir; hoca örnek olarak o günlerde çıkmış bir oyunda kullanıcıların çok sayıda show-stopper hatayla karşılaştığını söyledi.

Planlama sürece göre de değişir. Klasik bir süreçte "şu kişiler, şu zamanlarda, şu kadar süre" diye plan yapılır. Çevik süreçte her yinelemede sınamaya zaman ayrılır; test güdümlü yaklaşım kullanılıyorsa planlama yine farklı olur.

Bu dört adım şelale modelindeki gibi birbirini izleyen adımlar değildir. Klasik süreçte bile tasarım aşamasında testler de tasarlanabilir. Ayrıca bir hatayı düzeltmek yazılımın başka yerlerinde yeni hatalara yol açabilir. Bu yüzden sınama tekrarlı ve sürekli yapılmalı, planlama da buna göre yapılmalıdır.

## 3. Sınama Yaklaşımlarının Genel Özellikleri

Slaytta sınama yaklaşımlarının genel özellikleri şöyle verildi (ekrandan, 00:20:00):

- **Sınamalar bileşen düzeyinde başlar ve sistem düzeyinde sonlanır.** Ürün yalnız bilgisayar yazılımından ibaret olmayabilir. Sistemde algılayıcılar, harici sistemler, IoT cihazları vb. bulunabilir; bunları başkası ya da biz hazırlıyor olabiliriz. NYP'de en küçük bileşen sınıftır: sınıfların bireysel sorumluluklarından başlanır, yazılımın üst düzey sorumluluklarına kadar bütün işlevler sınanır.
- **Yaşam döngüsünün değişik aşamalarında değişik sınama teknikleri uygundur.**
- **Sınamalar hem bileşeni oluşturan kişi hem de bağımsız kişiler tarafından yapılır.** Büyük ölçekli kurumlarda ayrı bir sınama ekibi (örneğin bir test bölümü) bulunabilir.
- **Sınama ve hata ayıklama ayrı işlerdir.** Sınama (testing) hata olup olmadığını kontrol etmektir. Hata ayıklama (debugging) bulunan hatayı düzeltmektir. Yine de hata ayıklama etkinliklerinin planlanması her sınama yaklaşımının önemli bir parçasıdır.
- **Resmi teknik değerlendirmeler sayesinde sınama öncesinde de hatalar belirlenebilir.** Sınama denince ilk akla gelen birim ve geçerleme sınamalarıdır; ama gereksinim belirleme aşamasında bile resmi teknik gözden geçirme yürütülebilir.

## 4. Sınama Ekibinin Örgütlenmesi ve Sınamanın Psikolojisi

Bir bileşen ilk olarak onu hazırlayan programcı tarafından sınanır, çünkü o parçayı en iyi bilen odur. Bunun yanında parçanın yazarı dışındaki kişilerce de sınanması önemlidir. Bağımsız bir sınama ekibi varsa bu işi o yürütür. Yeterli insan kaynağı yoksa iki çözüm önerilir:

- **Farklı projelerin ekipleri birbirinin kodunu sınar.** Dezavantajı şudur: bir şeyi sınayabilmek için genel yapısına belli ölçüde hâkim olmak gerekir. Kendi projesine odaklanan ekip, öbür projeyi öğrenip takip etmeye fazla zaman harcamak zorunda kalır.
- **Aynı projenin farklı alt grupları birbirini sınar.** Örneğin beş kişilik bir ekipte A'nın kodunu B, B'ninkini C, C'ninkini D, D'ninkini E, E'ninkini de A sınar. Böylece herkes bir başkasının kodunu da sınamış olur.

Hoca bunun temel motivasyonunu psikolojiyle açıkladı. Programcının çıkarı, kendi kodunun hatasız, zamanında ve bütçe dahilinde tamamlanmasıdır. Kimse hatalı iş yapmak istemez; istemeden yapılmış bir hatanın da yayılmasını, bilinmesini istemez. Oysa **sınama yıkıcı bir eylemdir**: amaç kodun hangi durumda çalışmadığını, hata yaptığını, bozulduğunu göstermektir. Kodu yazan kişi ise bilinçaltında, bilerek olmasa da kodunun çalıştığını göstermeye eğilimlidir. Hoca bunu günlük hayatla bağladı: kendi hatalarımızı çoğu zaman görmeyiz, görsek de bahaneler buluruz. Kibir gibi duygular da işe karışabilir. Bu yüzden işi profesyonelce yapmak için bileşenin başkalarınca da sınanması gerekir.

Hoca bunu bir haberle örnekledi. Bürokratik ama önemli işlerin yapıldığı bir kamu kurumunda hata oranının yüksek olduğu fark edilmiş. Önce herkesin kendi yaptığı işi geriye dönük gözden geçirmesi ve bulduğu hata başına ikramiye alması önerilmiş; doğrulukta bir iyileşme olmuş ama istenen düzeye ulaşılamamış. Sonra her memura kendisinin hazırlamadığı belli sayıda dosyayı incelemesi görevi verilmiş. Aynı ikramiye karşılığında başkalarının dosyalarındaki hataları aramak çok daha fazla hata bulunmasını sağlamış. Yani bu durum yalnız yazılıma özgü değildir.

Bunlara ek olarak yazılım, teknik ekip dışındaki üçüncü bir paydaş, yani müşteri tarafından da sınanır (geçerleme). Hatalar önünde sonunda bulunur; önemli olan onları erken bulmak ve daha az masrafla çözmektir. Bakım aşamasında ortaya çıkan her hatanın düzeltilmesi hem çok daha masraflıdır hem de prestije zarar verir.

## 5. Sınama Yaklaşımının Belirlenmesi: Hedefler ve Ölçütler

Slaytta göz önünde bulundurulması gereken konular şöyle sıralanıyordu (ekrandan, 00:30:00):

- Sınama çalışmaları en çok çaba gerektiren yazılım mühendisliği etkinlikleri arasındadır. Bir şeyi sınamak, onu kodlamaktan daha zordur ve daha ayrıntılı düşünmeyi gerektirir.
- Sınama, olası tüm hataların yakalanacağı bir "güvenlik ağı" olarak düşünülmemelidir. Ne kadar çaba gösterilirse gösterilsin, tespit edilemeyen hatalar olacaktır.
- Hedefler açıkça belirlenmelidir: testlerin kapsama alanı; sınamaya ne kadar kaynak (zaman, kişi, bütçe) ayrılacağı; yazılımın türüne göre belirlenecek diğer ölçütler (MTBF, hassasiyet vb.).
- Sınamalar otomatikleştirilmelidir.
- Sınama süreci ölçülmeli ve iyileştirilmelidir.

Hoca güvenlik ağı benzetmesini sirk cambazlarıyla açtı. Yüksekte gösteri yapan cambazlar işinin ehlidir ve genellikle düşmez; düşerlerse altlarındaki ağ onları yakalar. Sınama böyle değildir. Ne kadar iyi sınama yapılırsa yapılsın kaçan hatalar olacaktır; amaç bunları en aza indirmektir.

### 5.1 Kapsama alanı

Kapsama alanı (code coverage), bütün test senaryoları koştuğunda yazılımın yüzde kaçının üzerinden geçildiğini gösterir. Yazılımın %100'ünü sınamak bütçe ve maliyet açısından olanaksızdır. Bu yüzden %60, %70, %75 gibi bir eşik belirlenir. Gerçekleme aşamasında gecikme varsa daha düşük bir kapsama oranı kabul edilebilir. Temel ölçüt kaynaktır: kapsamı genişletmek için zaman, kişi ve bütçe kaynaklarını aşmak gerekiyorsa bu yapılmayabilir.

### 5.2 Yazılım türüne göre ölçütler

- Bilimsel uygulamalarda hassasiyet (precision) yeterli mi?
- Gerçek zamanlı uygulamalarda yanıt verme süresi (response time).
- Sahada yoğun kullanılacak, sürekli gözetlenmeyecek ya da servis kesintisinin en aza indirilmesi gereken sistemlerde **MTBF (mean time between failures)**: art arda gelen iki hata arasında ortalama ne kadar süre geçtiği (bir gün, bir ay, kaç saat gibi).
- **MTTR (mean time to repair):** bir hatanın düzeltilmesinin ortalama ne kadar sürdüğü (kaç dakika gibi). Özellikle hatayı sistemin kendisinin otomatik olarak düzeltebildiği durumlarda önemlidir.

Sınamaları otomatikleştirmek ve sınama gereçlerinden yararlanmak işi çok daha verimli kılar. Süreç, her yazılım geliştirme sürecinde olduğu gibi, ölçülmeli ve iyileştirilmelidir. Bu konu yazılım kalitesi konusunda ayrıca ele alınacaktır.

## 6. Sınama Türleri: Kara Kutu ve Beyaz Kutu

Aradan sonra sınama türlerine geçildi. Sınama türleri iki ayrı ölçüte göre sınıflandırılır: yaklaşım tarzına göre ve yürütülme sırasına göre (ekrandan, 00:55:00).

### 6.1 Kara kutu sınaması (black-box testing)

Sınanacak birim bir kara kutu olarak ele alınır: iç işleyişi bilinmez. Elimizde yalnız temel bir spesifikasyon vardır: "şu girdilere karşılık şu çıktılar elde edilmelidir". Birimin beklenen girdilere karşı beklenen çıktıları üretip üretmediğine bakılır.

Hocanın örneği bir tümdevreydi. İç yapısı bilinmeyen 16 bacaklı bir devre düşünelim. İlk 8 bacaktaki bitlerden oluşan tamsayı ile diğer 8 bacaktaki bitlerden oluşan tamsayının bitwise OR işlemine tabi tutulup sonucun çıkışa verilmesi gerekiyor. Devre açılmaya çalışılınca kendini imha ediyorsa iç yapısını inceleyemeyiz; ancak değişik veri kümeleri uygulayıp doğru sonuç alıp almadığımıza bakabiliriz. Bu durum yalnız elektronik devrelere özgü değildir: kaynak kodu elimizde olmayan yazılım bileşenleri de yalnız bu şekilde sınanabilir.

### 6.2 Beyaz kutu sınaması (white-box testing)

Bileşenin iç yapısı biliniyorsa, yani kaynak kodu elimizdeyse, beyaz kutu sınaması yapılabilir. Sınama verileri, iç işleyişteki ayrıntılar göz önünde bulundurularak ters gidebilecek durumları yakalayacak biçimde tasarlanır. Bu durumda kod kapsaması da ölçülebilir. Örneğin testler koştuğunda dört ayrı `if` dalından yalnız üçünün kapsandığı görülebilir. Dördüncü dal belki sınamaya ayrılan zaman ve bütçe aşıldığı için kapsanamamıştır.

Beyaz kutu sınaması daha masraflıdır. İç yapıyı bilip "nasıl bir değer girersem bunu bozarım" diye düşünmek daha fazla zaman ve çaba ister. Bu yüzden kaynak kod elimizde olsa bile **önemli ve kritik bileşenlere beyaz kutu, daha az kritik bileşenlere kara kutu** sınaması uygulanabilir. Böylece sınama masrafı belirlenen eşiğin içinde tutulur.

Yeniden kullanılan kod kitaplıklarında hem kara kutu hem beyaz kutu testleri zaten hazırdır. Her yeni vakada bu kitaplıklara yeni kullanım senaryoları ekleniyorsa, bakım aşamasına gelene kadar yeni kara kutu testleri, daha sonra belki beyaz kutu testleri eklenebilir. Yani taktikler duruma göre uygulanabilir.

## 7. Doğrulama ve Geçerleme

İkinci sınıflandırma yürütülme sırasına göredir: **önce doğrulama (verification), sonra geçerleme (validation)** sınamaları yapılır. İngilizcede bunlara birlikte V&V denir ve hangisinin hangisi olduğu sık karıştırılır.

Hocanın hatırlatma yöntemi şuydu: Türkçede **D**oğrulama ve **G**eçerleme alfabetik sırayla gelir; önce D, sonra G. İngilizcede ise alfabede sonra gelen verification önce yapılır. Hoca bunu, İngiltere'de trafiğin soldan akması gibi bir terslik olarak hatırlamayı önerdi.

Slayttaki tanımlar (ekrandan, 00:55:00):

- **Doğrulama sınamaları (verification tests):** Yazılım ekibi tarafından yapılır. "Yazılımı doğru mu yapıyoruz?" sorusuna yanıt aranır. Alt türleri: birim sınamaları ve tümleştirme sınamaları.
- **Geçerleme sınamaları (validation tests):** Son kullanıcılar tarafından yapılır. "Doğru yazılımı mı yapıyoruz?" sorusuna yanıt aranır; yani yazılım gerçekten istediğimiz şekilde, işimize yarayacak şekilde çalışıyor mu? Alt türleri: alfa sınaması ve beta sınaması.

Hoca bu dört sınama türünü bir Excel tablosunda karşılaştırdı. Dersin ilerleyen kısmında tablonun son hali de gösterildi (ekrandan, 01:35:00):

| | Doğrulama: Birim | Doğrulama: Tümleştirme | Geçerleme: Alfa | Geçerleme: Beta |
|---|---|---|---|---|
| Yer | Yazılım evinde yapılır | Yazılım evinde yapılır | Yazılım evinde yapılır | Müşteri ortamında |
| Yürüten | Teknik ekip | Teknik ekip | Müşteri | Müşteri |
| Haberleşme | | | Gayri resmi haberleşme | Resmi haberleşme |
| Hata bildirimi | | | Her hatanın anlık bildirimi | Hataların toplu bildirimi |

Tabloda soldan sağa ilerlemek zamanda ilerlemek demektir: önce doğrulama, sonra geçerleme. Alfa sınaması yazılım evinde yapılsa da gerçek kullanım ortamına yakın bir ortam kurulması beklenir.

## 8. Birim Sınamaları

Slayt (ekrandan, 01:00:00): birim sınaması (unit testing) en küçük yazılım bileşeninin sınanmasıdır. NYP'de bireysel sınıfların sınanmasıdır.

### 8.1 Ne zaman tasarlanır, ne zaman yürütülür?

Slayta göre birim sınamaları üç zamanda tasarlanabilir:

- **Kodlamadan önce (çevik yaklaşım, TDD):** Test güdümlü yaklaşımda birim sınamaları koddan önce tasarlanır. Gerçekleme aşamasında yalnız bu sınamaları geçecek kodu yazmaya odaklanılır; ne eksik ne fazla. Çevik süreçlerde kullanım öyküleri büyük oranda değişebilir, bazıları iptal edilebilir; bu yüzden fazladan iş yapmak boşa gidebilir. Hocaya göre geleneksel süreçte bile fazladan iş yapmak doğru değildir: değişme olasılığı yüksek bir şeye çok zaman harcamak mantıksızdır, zaten zor olan iş daha da zorlaşır. Bu yaklaşım çevik süreçlerdeki KISS (Keep It Simple) ilkesine de uyar.
- **Kodlama sırasında:** Herkes böyle çalışmak zorunda değildir. Elimizde bir tasarım vardır; testler bu tasarımdan yola çıkarak ya da kodlama sırasında da tasarlanabilir.
- **Kodlamanın ardından:** Beyaz kutu çalışılacaksa testleri kod yazıldıktan sonra tasarlamak daha mantıklıdır. Kod henüz yokken tasarım ayrıntıları bir miktar şeffaflık sağlar, ama tam anlamıyla beyaz kutu bütün kaynak kodu bilerek yapılan bir şeydir.

> **Ders sonrası not:** Slaytta TDD açılımı "Test Driven Design" olarak yazılıydı (ekrandan, 01:00:00). Yaygın kullanımda TDD büyük olasılıkla "Test Driven Development" (test güdümlü geliştirme) olarak geçer.

TDD'de başta daha çok kara kutu sınaması yapılır. Ama TDD yalnız kara kutu demek değildir: projenin ilerleyen yinelemelerinde (örneğin Scrum döngülerinde) beyaz kutu sınamaya da zaman ayrılabilir. Biraz kod yazıp yazılan kadarını sınamak ya da bileşeni kodladıktan sonra testini tasarlamak da mümkündür.

Yürütme ise kodlamadan önce olamaz; kodlama sırasında ya da kodlamanın ardından yapılır.

### 8.2 Vekil kod (stub)

Bir nesne bir sorumluluğu çoğu zaman tek başına yerine getiremez; bağlaşımda bulunduğu diğer sınıfların nesneleriyle birlikte çalışır. O zaman şu soru doğar: sınıfımızın tek başına yürütemediği sorumlulukları sınamak için ihtiyaç duyduğu sınıfların yazılmasını mı bekleyeceğiz?

O sınıfları da biz yazacaksak önce ihtiyaç duyulanı kodlayabiliriz. Ama büyük projelerde bağımlılıkların sırası karışmış bir iplik yığınına benzer; ipin ucunu bulup çekmek her zaman mümkün değildir. Üstelik ihtiyaç duyulan kodu başka programcılar kendi takvimlerine göre daha sonra yazacak olabilir. Bu durumda kendi kodumuzu yine sınarız: ihtiyaç duyulan sınıfın yerine geçecek, derleme hatası vermeyecek kadar **minimum kod** yazarız.

Slayttaki adlar (ekrandan, 01:00:00): vekil, sahte, yalancı kod/sınıf; İngilizcede stub, dummy, surrogate, proxy vb. Hoca bunların arasında teknik nüanslar olduğunu, ama bu ders için bu kadarının yeterli olduğunu söyledi.

Örnek: bir sonuç hesaplayıp `boolean` döndürecek bir metodun gövdesine doğrudan `return true;` yazılır. Böylece işlemin başarılı olduğu vakaya göre test yapılabilir. Tümleştirme sınamalarına gelindiğinde vekil kodun yerini gerçeği alır ve bütün yazılım gerçek kodlarla sınanır.

Slayttaki kurallar:

- Vekil sınıflar yalnız ihtiyaç duyulan sınıflar gerçeklenene dek kullanılır.
- Vekil sınıfların basit tutulması ek kodlama yükünü azaltır. Vekil kod karmaşıklaşırsa fazladan kodlama işi çıkar; bu da KISS ilkesine aykırıdır.
- Bu mümkün değilse, ortaklaşa yürütülen sorumlulukların sınanması tümleştirme sınamalarına bırakılır.

### 8.3 Birim sınamalarında aranacak hatalar

Hoca bu konuyu şöyle özetledi: şimdiye kadar yaptığınız hatalardan ders çıkarın ve onları bir daha yapmadığınızdan emin olacak test kodu yazın. Saydığı tipik hata kaynakları şunlardır:

- **Kalıtım ve çok biçimlilik:** Çok biçimli davranışta beklenmeyen yan etkiler olabilir.
- **Birbirinin yerine geçebilen veri alanları:** NYP kullanılmasa bile, örneğin C'deki `union` yapısında aynı bit alanına farklı bakış açılarıyla erişilebilir.
- **Enum yerine sabit kodlar:** Dilde enum yoksa (C'de olduğu gibi) değerler tamsayı sabitlerle tutulur. Örneğin kan grubu 0, A, B için 0, 1, 2 ile kodlanmış olsun. Abonelik paketleri de giriş, orta ve üst düzey için 0, 1, 2 ile kodlanmışsa, müşteriye paket satarken yanlışlıkla kan grubu değeri atanabilir. Arka planda ikisi de `int` olduğu için derleyici uyarmaz.
- **Kuvvetli tiplemesi olmayan diller:** Değişkenin türünün ona ilk atanan değere göre belirlendiği dillerde testler daha dikkatli yazılmalıdır.
- **Mantıksal işleçler:** `and`, `or`, `not` yanlış kullanılabilir. Karmaşık koşullar zaten parçalara ayrılmalıdır.
- **İşaretçiler:** Yan etkileri olabilir.
- **Operatör önceliği** ve operatörlerin çok biçimli davranışı: Java'da `+` hem string birleştirme hem aritmetik toplama yapar.
- **Döngüler:** Sonsuz döngü ya da bir eksik/bir fazla eleman işleme.

## 9. Tümleştirme Sınamaları

Slayt (ekrandan, 01:10:00): tümleştirme sınamaları (integration testing) şu soruyla başlar: "Sınıflar birim sınamalarını geçmişlerse, bir araya getirildiklerinde de doğru çalışmazlar mı?" Bu soruya "elbette çalışırlar" demek saflık olur. Tek başına doğru çalışan birimler bir araya gelince doğru çalışmayabilir.

### 9.1 Hocanın benzetmesi

Halka açık bir tuvalete kâğıt havlu, el kurutma makinesi ve kâğıt çöp kutusu konduğunu düşünelim. Hepsi tedarikçiden CE ve ISO kalite belgeleriyle gelmiştir; tek başlarına doğru çalışırlar. Ama montajı yapan kişi çöp kutusunu el kurutma makinesinin altına takarsa, kutu dolduğunda kurutucunun üflediği hava kâğıtları etrafa saçar. Parçalar bir araya geldiğinde doğru çalışmaz.

### 9.2 Yazılımda neden olur?

Slayttaki açıklamalar:

- Yazılım geliştirme sürecinin her aşamasında her ayrıntının açıkça belirlenmesi beklenemez. Alan modelleri ve şemalar ne kadar ayrıntılı çalışılsa da bazı ayrıntılar belirsiz kalır.
- Ayrı ayrı programcılar belirlenmemiş ayrıntılarda kendi karar verme yetkilerini (initiative) kullanır. Birinin bakış açısıyla diğerininki uyumsuz olabilir; bu kararlarla yazılmış kodlar bir araya gelince doğru çalışmayabilir.
- Aynı kişinin farklı ayrıntılar hakkında farklı zamanlarda verdiği kararlar bile birbiriyle uyumlu olmayabilir.

NYP'de birim ve tümleştirme sınamalarını birbirinden ayıran kesin çizgiler yoktur. Bunun bir nedeni NYP'de analiz ile tasarımın da birbirinden kesin ayrılamamasıdır. Kabaca, vekil kod kullanılıyorsa birim sınaması, kullanılmıyorsa tümleştirme sınaması denebilir. Gecikmeler yüzünden bütün kodlar istenen anda hazır olmayabilir ve tam tümleştirmeye geçilemeyebilir; ama nesneye yönelim bu esnek çalışmayı destekler.

### 9.3 Tahribat sınaması (smoke testing)

Slayt (ekrandan, 01:15:00): tahribat sınaması yüzeysel, ancak başarısız olması durumunda tüm sistemin çalışmasının olanaksız olacağı sınamalardır. Bu tür hatalara **show-stopper** (gösteriyi durduran hata) denir.

Hoca terimin daha eski mühendislik dallarından geldiğini anlattı. Bir malzeme üretildiğinde, örneğin belli kodlu bir çelik türü, gerçekten o türün değerlerini (erime noktası, sertlik vb.) taşıyıp taşımadığı sınanır. Bir motor üretildiğinde en temel işlevleri yerine getiriyor mu diye bakılır; olmaması gereken yerlerden duman çıkmıyorsa "şimdilik iyi görünüyor" denir. Bu yüzeysel bir sınamadır, ama gerçekleşirse bütün sistemi durduracak hataları arar.

IT alanındaki en bilinen örnek olarak hoca, Windows 98'in tanıtımı sırasında mavi ekran alınıp sunumun yarıda kesilmesini gösterdi. Hoca nedenine dair varsayımsal bir örnek de verdi: USB klavye beklenen bir porta fare takılması gibi çok basit bir şey bütün sistemi çökertebilir. Lansman sırasında böyle bir şeyin olması ürünün tam da en görünür anında kalması demektir.

Slayttaki diğer maddeler:

- Diğer tümleştirme sınamalarından önce yapılır. Önce show-stopper hatalar aşılır, sonra ayrıntılı konular sınanır.
- Çeşitli bileşenler, tüm gerekli yazılım elemanlarını içeren parçalar (kod, yapılandırma dosyaları, dış kütüphaneler vb.) bir araya getirilir (build) ve **günlük olarak** sınanır. Yüzeysel hataları arayan kod genellikle karmaşık değildir ve kısa sürer; bu yüzden günlük olarak çekinmeden planlanabilir.

### 9.4 Geriye dönük sınama (regression testing)

Slayt (ekrandan, 01:15:00): yazılıma yeni bir işlev veya bileşen eklendiğinde tüm sınamaların yenilenmesidir. "Regression" geriye doğru bakmak demektir.

Testler hızlı tamamlanıyorsa sorun yoktur: her yeni bileşen ya da sorumluluk eklendiğinde ilgili testler test havuzuna eklenir ve her gün hepsi yeniden çalışır. Ama senaryoların yürütülmesi uzun sürüyor ya da masraflıysa, sınamaya ayrılan çaba sınırı aşılabilir. O zaman dengeli bir çözüm kullanılır: yeni eklenen sorumlulukla ilgili parçaların sınamaları yeniden koşturulur.

Bu durumda bağımlılığın kaç düzey geriye izleneceğine karar vermek gerekir. Hocanın örneği:

- Sisteme D işlevi eklendi.
- C işlevi D'ye ihtiyaç duyuyor, bu yüzden C'nin sınamaları da yeniden koşturulur.
- B, C'ye; A da B'ye ihtiyaç duyuyor. A'ya kadar geri gidilecek mi?
- Burada bir sınır konabilir: "en fazla iki düzey geri gidilir". Bu planlamada verilecek bir karardır.

Slayttaki ifade: "Hangi ölçekte bir eklentinin geriye dönük sınamayı başlatacağının kararını vermek gerekir. **Ölçek düştükçe sınama sıklaşır ve masraf artar.**" Hoca terimlerin karıştırılmaması için uyardı: ince ölçekte çalışmak bütün sınamaları koşturmak, kaba ölçekte çalışmak bir yere kadar gitmek demektir. Bütün bu masrafları azaltmak için otomatik sınama gereçleri kullanılmalıdır.

## 10. Geçerleme Sınamaları: Alfa ve Beta

Slayt (ekrandan, 01:25:00): geçerleme sınamaları (validation testing), gereksinimler belgesinde yazılmış işlevsellikten yola çıkılarak kullanıcı tarafından yapılır.

En temel kaynak kullanım senaryosu metinleridir. Bütün paydaşlar gereksinimler belgesinde anlaştığına göre neyin nasıl yapılacağı ayrıntılı adımlarıyla bellidir. Kullanıcı ezberine güvenmez, çünkü yanlış hatırlayabilir. Senaryoyu eline alır: ön koşullar sağlandı mı, sonra ana senaryonun birinci adımından başlayarak adımları yürütür. Ardından alternatif senaryoları dener: her biri planlandığı anda ve şekilde devreye giriyor mu, istendiği gibi yürüyor mu?

### 10.1 Neden gerekli?

Teknik ekip, son kullanıcının yapabileceği beklenmedik davranışların tümünü önceden bilemez. Bunlarla en çok teknik destek ekipleri karşılaşır. Slayttaki örnekler (ekrandan, 01:25:00):

- **"Fincan tutacağının çalışmaması":** Bir kullanıcı teknik desteği arayıp bilgisayarının fincan tutacağının çalışmadığını söyler. Aslında masaüstü bilgisayarın CD/DVD sürücüsünün açılan tepsisini fincan altlığı olarak kullanmaktadır.
- **"Pencereyi açmak":** Bir telekom reklamında üniversiteli bir genç, annesine bilgisayardaki sorunu telefonla anlatırken "bir pencere aç" der; anne evin penceresini açar. Aynı reklamın devamında roller değişir: anne oğluna yemek tarifi verirken mutfak dilindeki bir deyimi kullanır, oğlan da onu harfiyen anlayıp komik bir duruma düşer.

Hocanın sonucu: kullanıcılar çok ilginç şeyler yapabilir, bu yüzden geçerleme sınamaları büyük önem taşır.

Slaytta bir ilke daha vardı: bir şeyi ne kadar çok kişi incelerse ondaki kusurlar o kadar çabuk bulunur ve düzeltilir. Eric Raymond'ın sözüyle: **"given enough eyeballs, all bugs are shallow"**; yani onu inceleyen yeterince göz varsa hiçbir hata derin değildir.

### 10.2 Alfa sınaması

Slayt (ekrandan, 01:30:00):

- Yazılım firması içerisinde, kullanıcı tarafından yapılır.
- Yazılım geliştirme ekibinin denetiminde ve izlemesiyle yapılır. Teknik ekipten en az bir kişi testi sürekli izler. Bir hata çıkarsa ekip hemen haberdar olur ve hata mümkün olan en kısa sürede düzeltilir. Müşteri bu sırada beklemez, diğer testlere devam eder.
- Yazılımın doğal kullanım ortamına en yakın koşullarda yürütülür.

Hocanın örneği bir kütüphane bilgi sistemiydi. Sistem ödünç alma ve iade işlemlerini, farklı kullanıcı türlerinin farklı sayıda ve sürede kitap alabilmesini yönetiyor. Yazılım evinin bir köşesinde küçük bir kütüphane ortamı kurulur: bir ödünç verme bankosu, arkasında sırt etiketli kitapların bulunduğu bir raf, masadaki bilgisayarda barkod ya da RFID okuyucu. Müşteri bankoda oturur; bir başkası okuyucu rolünde kitap ödünç alır, iade eder. Sistem tamamen sanalsa sınama amaçlı yapılandırılmış bilgisayarlar ya da bir sunucu çiftliğindeki sanal makineler kullanılır. Amaç gerçek koşullara mümkün olduğunca yakın bir sınama ortamıdır.

Alfa sınamasında haberleşme gayri resmidir: belirli bir zaman ya da biçim yoktur, hata çıkar çıkmaz bildirilir.

### 10.3 Beta sınaması

Slayt (ekrandan, 01:30:00):

- Müşterinin kendi yeri içerisinde, gerçek kullanım ortamında yapılır.
- Yazılım geliştirme ekibi müdahil olmaz.
- Bulunan hatalar yazılım geliştirme ekibine düzenli aralıklarla ve resmi bir biçimde bildirilir.

Hoca resmi bildirime örnek olarak şöyle bir anlaşma tarif etti. Beta sınamasında bulunan hatalar her hafta belirli bir günde, belirli kodlu bir form kullanılarak toplu olarak bildirilir. Formda şu alanlar bulunur:

- Problemin birkaç kelimeyle tarifi,
- Problemin ayrıntılı tarifi,
- Probleme yol açan işlem adımlarının sırası,
- Ortaya çıkan hata mesajının tam içeriği ya da ekran görüntüsü,
- Hangi kullanıcının, hangi bilgisayarda, hangi işletim sistemi ve sürümünde çalıştığı.

Bazı alanlar zorunludur; gerekli bilginin eksiksiz geldiğinden emin olmak için böyle yapılır. Yazılım evinin Jira gibi bir görev planlama yazılımı varsa müşteri hatayı bildirmek için orada yeni bir görev açar ve ekrandaki alanları doldurur. Yazılım evi de belli bir sürede düzeltip düzeltilmiş kodu müşteri ortamına yükler. Düzeltilemiyorsa ne zaman düzeltileceği planlanıp müşteriye bildirilir. Net kurallar çerçevesindeki bu iletişime resmi iletişim (formal communication) denir.

Hoca bir dönem Google'ın neredeyse bütün ürünlerinin, Gmail dahil, "beta" etiketiyle sunulduğunu hatırlattı. Beta sınaması, yazılım evinin az sınama yapıp işin çoğunu müşteriye yıkması olarak görülmemelidir. Böyle yapılırsa ortaya çıkan hata sayısı artar ve prestij zarar görür.

> **Hocanın vurgusu:** Alfa sınamasında gayri resmi haberleşme vardır ve her hata anında bildirilir; beta sınamasında resmi haberleşme vardır ve hatalar belli bir zamanlama çerçevesinde toplu olarak bildirilir. "Aradaki farklar bunlar, bu aklınızda olsun mutlaka."

## 11. Sistem Sınamaları

Slayt (ekrandan, 01:40:00): yazılım tek başına sistemin bütününü oluşturmayabilir (gömülü uygulamalar, ara katman yazılımları vb.). Tümleştirme sınaması yazılımın kendi sınıfları ve paketleri düzeyindeydi. Sistem sınaması ise ürünün çalışacağı tüm ortamı düşünerek sistemin tümünü her yönüyle inceleyen sınamalardır. Dört alt türü işlendi.

### 11.1 Kurtarma (recovery) sınaması

- Hatalara dayanıklı (fault tolerant) sistemler için geçerlidir.
- Bir hata ortaya çıktığında sistemin kendini toparlayarak doğru çalışmaya devam edip edemediği sınanır.
- Kurtarma işlemi belli bir süre içerisinde tamamlanmalıdır (MTTR: Mean Time To Repair).

Örnek finansal işlemlerdendi. Finansal işlemler "hareket" (transaction) olarak adlandırılır. Bir hesaptan, hele başka bir bankadaki hesaba para aktarılırken, emir karşı bankanın bilgi sistemine doğru aktarılmalı ve karşı hesabın bakiyesi o miktar kadar arttırılmalıdır. Aradaki herhangi bir adımda hata çıkarsa sistem, işlemler başlamadan önceki tutarlı durumuna geri dönebilmelidir. Yoksa kaynak hesaptan para düşmeden hedef hesapta para artabilir ya da tersi olabilir; her iki durumda da birileri zarar görür. Başa dönme işlemine rollback denir.

### 11.2 Güvenlik (security) sınaması

Slayttaki iki madde: **"Tek kural: Kural yok!"** ve **"Her güvenlik önünde sonunda aşılır!"**

Hoca, güvenlik olaylarının akla hayale gelmeyecek biçimler alabileceğini söyledi ve birkaç örnek verdi:

- Askeri haberleşme cihazlarında sinyaller şifrelenir. Düşmanın bir cihazı ele geçirilip şifre çözülmeye çalışılabilir. Ama tümdevreler açılmaya kurcalanmaya çalışıldığında küçük bir asit kapsülü kırılıp devreyi kullanılmaz hale getirecek biçimde yapılmış olabilir (kurcalamaya dayanıklı, tamper-proof). O zaman alternatif kanallardan bilgi toplanır: önce kısa, sonra orta, sonra uzun paketler gönderip veri iletiminin hangi aşamasında devrenin hangi bölgesinin daha çok ısındığını kızılötesi ölçümle izlemek bile devrenin çalışma ayrıntıları hakkında ipucu verebilir.
- Birinin ekranı doğrudan görülemese bile, loş bir ortamda ekranın arkadaki duvara düşen ışık yansımasından ekran görüntüsünü ana hatlarıyla çıkarabilen, yapay zeka teknikleri kullanan yazılımlar vardır.

Bu yüzden güvenlik sınaması "kutunun dışında düşünmeyi" (out of the box thinking) ve çok yönlü, ayrıntılı düşünmeyi gerektirir. Her güvenlik önlemi er geç aşılacağına göre amaç, aşılmanın bilginin değerini yitireceği süreden daha uzun sürmesidir:

- Karargâhtan birliklere gece saat 12'de "sabah 4'te harekâta başlayın" emri gönderiliyor; arada 4 saat var. Düşman haberleşmeyi yakalasa bile şifreyi kırmak 6 saat sürüyorsa, şifre kırıldığında harekât çoktan başlamış olur.
- Benzer şekilde bir finansal oturumun (session) kırılması 10 dakikadan uzun sürüyorsa yeterlidir: 20 dakikada kırıldığında işlem (transaction) çoktan tamamlanmıştır.

### 11.3 Zorlama (stress) sınaması

Sistemin hangi şartlar altında ne düzeyde çalışacağı, yani çalışma sınırları bellidir. Normalin dışında yüklenme durumunda sistemin nereye kadar dayanabileceğinin sınanmasına zorlama sınaması denir.

### 11.4 Başarım (performance) sınaması

- Gerçek zamanlı uygulamalarda özel öneme sahiptir.
- Program kendisinden bekleneni doğru yapabilir, ama zamanında yapamayabilir.

Hocanın örneği hedefi izleyen bir füzeydi. Hedef ani bir manevra yaptığında füze bunu yavaş fark ederse hedefi ıskalar. Kaçış yönünü %100 hassasiyetle bulması gerekmeyebilir; ama örneğin %80 hassasiyetle ve hızlı tepki vermesi gerekir. Bu limitler belirlenir ve sistemin bu limitler dahilinde kalıp kalmadığı sınanır.

## 12. Hata Ayıklama

Slayt (ekrandan, 01:45:00): yapılan türlü sınamaların sonucunda bulunan hatalar düzeltilmelidir.

Sınama ve hata ayıklama çalışmaları bazıları tarafından "angarya", "ayak işi", "sıkıcı", "ikinci sınıf" iş olarak nitelendirilebilir. Hoca bunun önemli bir yanılgı olduğunu söyledi. Slayttaki gerekçeler:

- Sınamanın önemini gördük.
- Yazılımınızdaki hatalar size ve kurumunuza prestij kaybettirir.
- Düzeltilmeyen veya düzeltilmesi uzun süren hatalar daha da çok prestij kaybettirir.
- Sınama ve güvenlik açıklarının belirlenmesi için alışılagelmiş düşünce biçiminin dışına çıkabilmek gerekir; bu özel bir yetenektir.
- Saygı duyulan ve ünlü programcılar, hata ayıklamanın kodlama yapmaktan daha zor ve daha çok yetenek isteyen bir iş olduğu görüşünde birleşmektedir.

Hoca bu işlerin yalnız stajyerlere verilmesinin yanlışlığını şöyle açıkladı: stajyer büyük olasılıkla projeye sonradan katılmıştır. Sınayabilmek için önce projeye ya da en azından ilgili modüle hâkim olması gerekir. O modül onun bilgi düzeyinin üstünde algoritmalar, veri yapıları ve tasarım kalıpları kullanılarak yazılmış olabilir. Böyle biri en fazla tahribat sınaması yapabilir. Yine de bir şeye ne kadar çok farklı kişi bakarsa o kadar iyidir. Sonuç: bu işler yalnız stajyerlere ya da yeni katılanlara yüklenmemeli, farklı deneyim ve bilgi düzeyindeki insanlara dağıtılmalıdır. Böyle görülen yerlerde durumun böyle olmaması gerektiği yüksek sesle söylenmelidir.

Slayttaki iki pratik tavsiye:

- **Bir noktada takıldığınızda biraz ara verip sorunu yeniden incelemeniz başarı şansınızı arttıracaktır.** Bilgisayarın başından kalkıp bir nefes almak, dolaşmak, bir çay ya da kahve almak; döndüğünüzde sorunun nereden kaynaklandığını çoğu zaman hemen görürsünüz.
- **Geliştirme ortamının hata ayıklama yeteneklerinden sonuna kadar yararlanın.**

## 13. Yazılım Gözden Geçirme ve IEEE 1028

### 13.1 Yazılım gözden geçirme (software review)

Slayt (ekrandan, 01:50:00):

- Yazılım sınamasından önce, sınama eylemlerinden daha az masrafla yazılım hatalarının bulunmasını amaçlar. Şimdiye kadar konuşulan sınamalar elle tutulur ürünü (kodu, sistemi) sınıyordu; gözden geçirme bu etkinliklerden önce gelir.
- Sınama çalışmalarıyla bulunabilecek tüm hatalar gözden geçirmeyle bulunamaz. Ancak gözden geçirme daha verimlidir: daha az çabayla bazı hataları, kimi zaman show-stopper türünden olanları da bulur. Hoca ilk haftayı hatırlattı: gereksinimlerin eksik belirlenmesi projenin başarısızlığına "kırmızı halı serer". Bu yüzden gözden geçirme gereklidir.
- Gözden geçirme resmi veya gayri resmi olabilir. Resmi olan belirli kurallar çerçevesinde ve yazılı yapılır; en azından yazılı etkinlikleri mutlaka vardır. Gayri resmi olan sözlüdür, gerektiğinde ve samimi bir ortamda yapılır.
  - Çalışmalar, gözden geçirme toplantılarının yapılması durumunda resmi gözden geçirmelerin daha etkili olduğunu göstermiştir.
  - Çevik süreçlerden XP'deki eşli programlama (pair programming) da bir tür gözden geçirmedir; resmi değil, daha çok gayri resmidir.
- Resmi yazılım gözden geçirme (formal software review): toplantı şeklinde yapılır, toplantının bir yöneticisi (review leader) bulunur ve bu konuda çeşitli standartlar önerilmiştir. Örneğin IEEE 1028 standardı.

### 13.2 IEEE 1028'e göre adımlar

Hoca standardın gerektirdiği formlara girmeden ana adımları anlattı (ekrandan, 01:55:00):

1. **Değerlendirme başlangıcı:** Değerlendirme yöneticisi standart bir checklist kullanarak verimli bir toplantı için gerekli koşulları sağlar. Örneğin toplantı günü ve saatinde salon ayarlanmış mı, salondaki cihazlar çalışıyor mu, bakımları ve gerekiyorsa kalibrasyonları yapılmış mı, katılımcılara en az belirli bir süre önce resmi kanaldan haber verilmiş mi?
2. **Yönetimin hazırlanması:** Sorumlu yönetim gözden geçirme için gerekli kaynakları hazırlar ve toplantının standartlara uygun yürütülmesini sağlar.
3. **Gözden geçirme prosedürlerine genel bakış:** Değerlendirme yöneticisi, tüm değerlendiricilerin gözden geçirmenin amaçlarını ve prosedürlerini anladığından emin olur. Örneğin ilk kez katılacak biri standarda yönlendirilir; belki bir çevrim içi testle anladığı ölçülür.
4. **Bireysel hazırlık:** Değerlendiricilere incelenecek malzeme verilir ya da ortak bir havuzdaki yeri bildirilir; örneğin yazılım gereksinim belgesi (SRS). Değerlendiriciler bireysel olarak hazırlanır ve malzemede hataya yol açabilecek olası bozuklukları (anomaly) arayıp ayrıntılı not eder.
5. **Grup incelemesi:** Bireysel hazırlıkların sonuçları önceden belirlenen yer ve zamandaki toplantıda bir araya getirilir. Herkes bulgularını sırayla anlatır. Her bulgu için iki sonuçtan birine varılır: ya bulguyu getiren kişi diğerlerini bunun gerçekten bir hata olduğuna ikna eder (aynı bulguyu başka değerlendiriciler de bulmuşsa destekleyici kanıtlarını ekler), ya da tartışmada bunun aslında bir hata olmadığı ortaya çıkar. Ortak karara varılana kadar konuşma sürer ve sonuç raporu üzerinde uzlaşılır.
6. **Düzenleme:** İncelenen çalışmanın yazarları ya da atanacak başka bir kişi/ekip, önceki adımda belirlenen noktaları düzeltir. Bu kod düzeyinde bir hata ayıklama olmayabilir. Örneğin "bu sınıflar şöyle ilişkili olmalı", "bu sorumluluk şu sınıfa atanmalıydı", "bu sorumluluğu şu sınıf tek başına değil, diğeriyle birlikte yerine getirmeli", "şu gereksinim bu zamanlamada yapılamaz, proje planı düzenlenmeli" gibi düzeltmeler yapılır.
7. **Sonlandırma:** Değerlendirme yöneticisi yapılan düzeltmelerin doğruluğunu, yeterliliğini ve tutarlılığını inceler. Gerekirse değerlendiricilerin ve düzeltmeyi yapan ekibin görüşünü alır. Temel sorumluluk yöneticidedir; düzeltmeler yeterliyse çevrim tamamlanmış sayılır.

Bu çalışma biçiminin daha az çabayla hata ve tutarsızlık bulduğu anlaşılmıştır.

## 14. JUnit ile Birim Sınaması

### 14.1 Genel bilgi

Slayt (ekrandan, 02:15:00):

- JUnit, Java ile yazılmış kodun birim sınamaları için bir çerçeve programdır (testing framework).
- Diğer diller için de sürümleri bulunmaktadır (genel olarak xUnit ailesi). Örneğin C# için csUnit. Hoca Python için de bir sürüm olduğunu söyledi. <!-- BELİRSİZ: Altyazıda Python sürümünün adı bozuk ("TY-unit"); büyük olasılıkla PyUnit kastediliyor. -->
- IDE desteği yaygındır: Eclipse ve NetBeans'te IDE ile hazır gelir. İstenirse junit.org adresinden indirilen JAR dosyaları projeye eklenerek de kullanılabilir.

### 14.2 JUnit 3.x ile test case hazırlamak

Slayttaki diyagram (ekrandan, 02:20:00) şu yapıyı gösteriyordu:

```text
paket junit.framework
  TestCase
    # setup()
  Assert
    + assertEquals(beklenen, sonuc : Object)
    + assertNotEquals(Object, Object)
    + assertTrue(boolean)
    + assertFalse(boolean)
    + assertNull(Object)
    + assertNotNull(Object)
  (TestCase ---bağımlı---> Assert)

paket myPackage
  AppClass1, AppClass2                 (uygulama sınıfları)
  TestAppClass1 : + testXXX()          (TestCase'ten kalıtım, AppClass1'e bağımlı)
  TestAppClass2 : + testYYY()          (TestCase'ten kalıtım, AppClass2'ye bağımlı)
  TestAll       : + suite() : Test     (TestAppClass1 ve TestAppClass2'yi toplar)
```

Slayttaki kurallar:

- Her sınıfın birim testi için ayrı bir sınıfta ayrı test case'ler hazırlanır. 3.x sürümünde test sınıfının adı `test` kelimesiyle başlamalıdır: `AppClass1` için `TestAppClass1`, `AppClass2` için `TestAppClass2`. Bu sınıflar `TestCase` sınıfından kalıtımla türetilir.
- Test sınıflarındaki birim sınaması metodlarının adı da `test` ile başlamalıdır (`testXXX()`).
- Test case'ler bir test takımı (test suite) altında toplanabilir. `TestAll.suite()` metodu statiktir.
- `TestCase.setup` metodu her `testXXX()` için yeniden çalışır.

**Assert metodları.** Bir testin başarılı olup olmadığı `Assert` sınıfının public static metodlarıyla değerlendirilir. En temel sınama kara kutu mantığıdır: verilen girdiye karşılık beklenen doğru sonuç elde ediliyor mu?

- `assertEquals(beklenen, sonuc)`: Bir yanda girdilere karşı elde edilmesi beklenen çıktıyı simgeleyen nesne, öbür yanda sınanan metodun döndürdüğü sonuç nesnesi vardır. İkisi tamamen aynıysa test başarılıdır. Parametreler `Object` türündedir; Java'da `Object` "kozmik üst sınıf" olduğundan her türlü nesne verilebilir.
- `assertNotEquals`: ters mantık. Beklenen ile elde edilen eşit değilse test başarılıdır. Her zaman gerekmez, ama gerektiği anlar olabilir. Örneğin kaydedilmemiş bir nesne arandığında sonuç dönmemelidir.
- `assertTrue(boolean)`: verilen ifade true olarak değerlendiriliyorsa test başarılıdır, aksi halde başarısızdır. `assertFalse` tam tersidir. Hoca, `boolean` döndüren metodlar için bunların doğrudan kullanılmasını tercih ettiğini söyledi.
- `assertNull(Object)`: parametre `null` ise test başarılıdır. `assertNotNull` tersidir; örneğin bir metodun döndürdüğü sonucun `null` olmaması gerektiğinde kullanılır.

> **Hocanın vurgusu:** Tercihen her test metodunda tek bir assert kullanılır. Birden çok kullanılabilir; ama o zaman testin başarılı olması için metottaki bütün assert'lerin başarılı olması gerekir, biri bile takılırsa bütün test başarısız sayılır. Mümkün olan en bireysel düzeyde sınamak en doğrusudur.

**setUp metodu.** Bir nesne tek başına bir sorumluluğu yerine getiremeyebilir. Testin yürütülmesi için önce bir "sahne" hazırlamak gerekebilir: çeşitli nesneler oluşturulur ve birbirleriyle ilişkilendirilir. Hocanın örneği: bir derse öğrenci ekleme senaryosunu sınamak için önce ders, sonra öğrenciler oluşturulur; öğrenciler tek tek derse eklenir ve kapasite dolunca eklenmemesi gerektiği sınanır. Bu hazırlığın her testten önce tekrarlanması gerekir. `TestCase` sınıfındaki `protected` `setUp` metodu her test metodundan önce yeniden çalıştırılır. Kendi test sınıfımızda bu metodu override edip sahne hazırlığını içine yazarız.

**Test takımı (suite).** Birden fazla test sınıfı bir araya getirilip bir suite oluşturulabilir. Bu isteğe bağlıdır, ama farklı türdeki regresyon çalışmalarını gruplamak için kullanışlıdır. Örneğin 10 test sınıfı varsa hepsini içeren "bütün testler" takımı ve yalnız önemli olanları içeren ayrı bir takım kurulabilir.

### 14.3 JUnit 4.x ile test case hazırlamak

Slayt (ekrandan, 02:25:00 ve 02:30:00):

- Geriye doğru uyumluluk korunmakla birlikte JUnit 4 sürümüyle annotation desteği gelmiştir. 4.x çerçevesinde 3.x tarzında test yazmaya devam edilebilir.
  - Artık sınama sınıflarının `TestCase` sınıfından kalıtımla türetilmesi ve sınıf adının `Test` ile başlaması gerekmez.
  - Sınama metodlarının adlarını `test` kelimesiyle başlatmak gerekli değildir; metodların başına `@Test` annotation'ı koymak yeterlidir.
  - `setup` adlı metodun yerine `@Before` annotation'ı gelmiştir. Hazırlık metoduna herhangi bir ad verilebilir.
- Exception tanımlanan yazılımlarda, atılması gereken exception'ların gerçekten ortaya çıkıp çıkmadığının sınanması da mümkün olmuştur.

```java
@Before
public void setUp() { /*Preparations*/ }
@Test
public void testSomething() { /*Do test*/ }
```

```java
@Test(expected=SomeException.class)
public void testTheException() throws Exception {
    doSomethingThatCreatesTheException();
}
```

Hoca slaytta annotation'ların küçük harfle (`@test`, `@before`) yazıldığını fark edip düzeltti; Java büyük-küçük harf duyarlıdır ve doğrusu `@Test`, `@Before`'dur. Düzeltilmiş slayt 02:30:00 karesinde görülüyor.

**Annotation nedir?** `@` ile başlayan satırlardır. Derleyici bunları bir tür yorum gibi değerlendirir; üzerlerinde bir işlem yürütmez. Amaçları, kaynak kod üzerinde çalışacak başka programlara bilgi ya da talimat aktarmaktır. Örneğin Eclipse'te belirli türdeki uyarıları yalnız bir sınıf için görmek istemiyorsak sınıfın başına `@SuppressWarnings("...")` yazarız; bu annotation derleyiciye yöneliktir. JUnit'e yönelik annotation'lar ise çerçeveye hangi metodun hazırlık (`@Before`), hangisinin test case (`@Test`) olduğunu bildirir. Çerçeve de ilgili metodları ilgili sırada yürütür ve değerlendirir.

**Exception sınaması.** NYP dersinden hatırlanacağı gibi exception (aykırı durum) oluşunca programın akışı kesilir. Ama bazen "şu exception ortaya çıkmışsa test başarılıdır" diye bir test yapmak isteriz. Bunun için `@Test` annotation'ına `expected=` parametresiyle beklenen exception'ın sınıfı (`İsim.class`) verilir. Metod içinde ayrıca assert yazmak gerekmez. Exception oluşursa test başarılı, oluşmazsa başarısız sayılır ve çerçeve diğer testleri yürütmeye devam eder.

## 15. Uygulama: Video Kaset Kiralama Örneği

### 15.1 Örneğin kaynağı ve amacı

Örnek, Martin Fowler'ın *Refactoring: Improving the Design of Existing Code* (Addison-Wesley, 1999) kitabından alınmıştır (ekrandan, 02:35:00). Kitap, nesneye yönelimin gerekleri eksik ya da hatalı uygulandığında ortaya çıkan sorunların (kod kokuları, code smell) nasıl tespit edilip düzeltileceğini anlatır. Yeniden düzenleme (refactoring) adım adım yapılır ve her adımda sınamalar eşliğinde ilerlenir. Çünkü daha iyi bir tasarıma götürmesi beklenen bir düzenleme bizi hatalı bir noktaya da götürebilir. Bu nedenle her düzenleme adımından sonra en azından değiştirilen sınıfın ve ona bir adım geriden bağlı sınıfların birim sınamaları (regresyon olarak) koşturulur. Gösterilen tasarım, kitaptaki düzenleme sürecinin ortasındaki bir haldir ve bilerek bazı kusurlar içerir.

### 15.2 Problem tanımı ve sınıflar

Bir video kaset kiralama sistemi: müşteriler (customer) filmleri (movie) belli bir süre için kiralayabilir. Üç film türü vardır: normal filmler, yeni çıkan filmler ve çocuk filmleri. Türlere ve sürelere göre kiralama ücretleri farklıdır; kiralamalardan farklı bonus puanlar da kazanılabilir.

Slayttaki sınıf şeması (ekrandan, 02:35:00):

| Sınıf | Üye alanlar | Metodlar |
|---|---|---|
| `Movie` | `- _priceCode : int` | `+ getCharge(daysRented : int) : double`, `+ getBonus(daysRented : int) : int` |
| `Rental` | `- _daysRented : int` | `+ getCharge() : double`, `+ getBonus() : int`, `+ getMovieTitle() : String` |
| `Customer` | | `+ statement()`, `+ getTotalCharge() : double`, `+ getTotalBonus() : int` |

İlişkiler: `Customer` 1 — * `Rental`; `Rental` * — 1 `Movie` (her kiralama bir filme bağlıdır).

Slayttaki sıralama şeması (`statement()` için) şu akışı gösteriyordu:

```text
Kullanıcı -> aCustomer : statement()
  *[for all rentals]
    aCustomer -> aRental : getMovieTitle()
      aRental -> aMovie : getTitle()
    aCustomer -> aRental : getCharge()
      aRental -> aMovie : getCharge(_daysRented)
    (not: tek kira için ücret hesabı ve makbuz satırı basımı tamamlanır)
  aCustomer -> aCustomer : getTotalCharge()
    *[for all rentals] aRental.getCharge() -> aMovie.getCharge(_daysRented)
  aCustomer -> aCustomer : getTotalBonus()
    *[for all rentals] aRental.getBonus() -> aMovie.getBonus(_daysRented)
  (not: makbuz basımı tamamlanır)
```

**Alt çizgi kuralı.** Üye alanların adları `_` ile başlar. Kod editörlerinde üye alanlar, geçici değişkenler ve parametreler farklı renklerle vurgulanır. Ama kitap siyah-beyaz basıldığından ve renkli baskı masraflı olduğundan üye alanları ayırt etmek için bu alışkanlık kullanılmıştır. Hoca bunun C programcılarından gelen bir alışkanlık olduğunu söyledi.

**`getMovieTitle()` neden `Rental`'da?** Müşteri, `Rental`'dan `Movie` nesnesini isteyip onun adını alabilirdi. Bunun yerine doğrudan `Rental`'a "seninle ilgili filmin adı neydi?" diye sormak iki nedenle daha iyidir:

- Doğrudan bağlaşımı dolaylı bağlaşıma çevirir, yani bağlaşımı azaltır.
- Haberleşme masrafını azaltır: yalnız ad için bütün nesneyi döndürmek yerine bir string döndürülür.

Bu metod, düzenleme yinelemelerinden birinde eklenmiştir.

**Tasarım eleştirisi.** `Movie`'deki `_priceCode` film türünü enum gibi tutan bir tamsayıdır: 0 normal, 1 yeni çıkan, 2 çocuk filmi. Bunun yerine Java'da enum kullanmak daha iyi olurdu. En doğrusu ise çok biçimlilik kullanmak, yani `Movie`'yi soyut bir üst sınıf yapıp normal, yeni çıkan ve çocuk filmlerini alt sınıflar olarak tasarlamaktır.

### 15.3 Kod

Hoca kodları Eclipse'te gösterdi. JUnit'i projeye eklemek için proje üzerinde **Configure Build Path → Libraries → Add Library → JUnit** seçilir. Eclipse'te JUnit 3, 4 ve 5 hazır gelir; hoca örnek için 3'ü seçti. Başka bir IDE kullanılıyorsa junit.org'dan ilgili JAR indirilip **Add External JARs** ile ya da o IDE'nin yöntemiyle projeye eklenir.

`Customer` sınıfında müşterinin adı ve kiralamaların tutulduğu bir `Vector` (`_rentals`) vardır. Ad yapıcıda (constructor) verilir, her kiralama `addRental` ile eklenir, adı `getName` döndürür. Makbuz metodu (ekrandan, 02:45:00):

```java
public String statement( ) {
    Enumeration<Rental> rentals = _rentals.elements();
    String result = "Rental Record for " + getName() + "\n";
    while (rentals.hasMoreElements()) {
        Rental aRental = rentals.nextElement();
        //show figures for this rental
        result += "\t" + aRental.getMovieTitle()+ "\t" +
            String.valueOf(aRental.getCharge()) + "\n";
    }
    //add footer lines
    result += "Amount owed is " + getTotalCharge() + "\n";
    result += "You earned " + getTotalBonus()
        + " frequent renter points";
    return result;
}
public double getTotalCharge( ) {
    double result = 0;
    for( Rental each : _rentals )
        result += each.getCharge();
    // ... (devamı karede görünmüyor; result döndürülür)
```

`statement()` kiralama listesinin elemanları üzerinde bir `Enumeration` ile dolaşır. Her kiralama için film adını, bir sekme ve kiralama bedelini satıra yazar; sonra toplam borcu ve kazanılan puanı ekler. `getTotalCharge()` ve `getTotalBonus()` her kiralamanın bedelini ya da puanını kümülatif olarak toplar. Hoca, neden `statement()`'ta `while`, diğerlerinde for-each kullanıldığı sorulabileceğini söyledi: orijinal kod böyleydi; performans ya da tasarım açısından bir farkı olmadığından değiştirilmedi.

`Rental` sınıfında ilişkili film ve kiralama gün sayısı üye alanları vardır; yapıcı ikisini birden alır, ikisi için get metodları bulunur. `Rental.getCharge()`, bedeli kendi hesaplamaz: filmin türü `Movie`'de, gün sayısı `Rental`'dadır. Bu yüzden `Rental`, kendi `_daysRented` bilgisini parametre olarak `Movie.getCharge(daysRented)`'e verir. `Movie`'de fiyat kodu için set metodu da vardır, çünkü yeni çıkan bir film belli bir süre sonra normal filme dönüşür ya da yanlış kodlanmış olabilir.

**Fiyatlandırma kuralları** (müşterinin gereksinim belgesinde istediği):

- Normal film: 2 lira karşılığında 2 gün kiralama hakkı; 2 günü aşan her gün için günlük 1,5 lira.
- Yeni çıkan film: gün başına 3 lira.
- Çocuk filmi: 1,5 lira karşılığında 3 gün; 3 günü aşan her gün için günlük 1,5 lira.

`Movie.getCharge` ve `getBonus` (ekrandan, 02:50:00 ve 03:05:00):

```java
public double getCharge( int daysRented ) {
    double result = 0;
    switch ( getPriceCode() ) {
    case Movie.REGULAR:
        result += 2;
        if (daysRented > 2)
            result += (daysRented - 2) * 1.5;
        break;
    case Movie.NEW_RELEASE:
        result += daysRented * 3;
        break;
    case Movie.CHILDRENS:
        result += 1.5;
        if (daysRented > 3)
            result += (daysRented - 3) * 1.5;
        break;
    }
    return result;
}
public int getBonus( int daysRented ) {
    if ( getPriceCode() == Movie.NEW_RELEASE && daysRented > 1 )
        return 2;
    else
        return 1;
}
```

**Bonus kuralı:** her kiralama, kaç gün olursa olsun 1 puan kazandırır. Yeni çıkan bir film 1 günden uzun (2 gün ve üstü) kiralanırsa 2 puan kazanılır.

### 15.4 Test sınıfları

En kritik metod `statement()`'tır, yani makbuzun doğru basılması. Bunu sınamak için farklı türden filmler farklı sürelerle kiralanıp makbuzun doğru olup olmadığına bakılır. JUnit 3.x kullanıldığından `TestCase`'ten türetilen `TestCustomer` sınıfı yazılır (ekrandan, 03:00:00). Örnekte müşteri adı olarak gerçek bir kişi adı kullanılmıştı; aşağıda genel bir adla (`musteri`, "Ali Yilmaz") değiştirildi:

```java
package unitTestingByFowler;
import junit.framework.*;
public class TestCustomer extends TestCase {
    private Customer musteri;
    private Movie matrix, monster, surrogate, terminator;
    protected void setUp() {
        musteri = new Customer("Ali Yilmaz");
        matrix = new Movie("The Matrix",Movie.REGULAR);
        monster = new Movie("Monsters, Inc.",Movie.CHILDRENS);
        surrogate = new Movie("Surrogates", Movie.NEW_RELEASE);
        terminator = new Movie("Terminator Salvation",Movie.NEW_RELEASE);
    }
    public void testGetName( ) {
        String sonuc = musteri.getName();
        assertEquals("Ali Yilmaz",sonuc);
    }
    public void testStatementWhenEmpty( ) {
        String sonuc = musteri.statement();
        String beklenen = "Rental Record for Ali Yilmaz\n";
        beklenen += "Amount owed is 0.0\n";
        beklenen += "You earned 0 frequent renter points";
        assertEquals(beklenen, sonuc);
    }
    public void testStatementWithMoviesLongRent( ) {
        musteri.addRental( new Rental(matrix, 3) );
        musteri.addRental( new Rental(monster, 4) );
        musteri.addRental( new Rental(surrogate, 2) );
        String sonuc = musteri.statement();
        String beklenen = "Rental Record for Ali Yilmaz\n";
        beklenen += "\tThe Matrix\t3.5\n";
        beklenen += "\tMonsters, Inc.\t3.0\n";
        beklenen += "\tSurrogates\t6.0\n";
        beklenen += "Amount owed is 12.5\n";
        beklenen += "You earned 4 frequent renter points";
        assertEquals(beklenen, sonuc);
    }
    // ... testStatementWithMoviesShortRent, testNewReleaseRentalBonus
}
```

Testlerin açıklaması:

- **`setUp()`:** Bir müşteri ve dört film (bir normal, bir çocuk, iki yeni çıkan) oluşturur. Her test metodundan önce yeniden çalışır; böylece her test nesnelerin oluşturulmuş ama henüz ilişkilendirilmemiş olduğu "temiz bir sayfa"yla başlar.
- **`testGetName()`:** Müşterinin adı doğru dönüyor mu? Hoca bunu bir tür smoke test olarak da düşünülebileceğini söyledi: kodun çalışacağı sistem Türkçe karakterleri doğru desteklemiyorsa adı Türkçe karakter içeren bir müşteriyle bu hemen ortaya çıkar.
- **`testStatementWhenEmpty()`:** Hiç film kiralamamış bir müşteriden para beklenmemeli ve puan kazanmamış olmalıdır. Beklenen makbuz kâğıt kalemle hesaplanıp string olarak kurulur ve `assertEquals` ile karşılaştırılır.
- **`testStatementWithMoviesLongRent()`:** Üç farklı türden film "uzun" sayılacak sürelerle kiralanır. Bu hâlâ kara kutu sınamasıdır: `Rental` ve `Movie`'nin kaynak koduna bakmaya gerek yoktur; beklenen değerler gereksinim belgesindeki kurallardan elle hesaplanır.
- **`testStatementWithMoviesShortRent()`** ve **`testNewReleaseRentalBonus()`:** Kısa süreli kiralamalar için aynı mantık ile 2 ve 1 puanlık bonus vakaları (iki kiralama işlemiyle) sınanır. Bu testlerin kodu karelerde görünmüyor.

> **Hocanın vurgusu:** Test metodlarının adları uzun olsun, ama neyi sınadıkları belli olsun. Böylece bir test başarısız olduğunda yalnız adına bakarak neyi sınadığı anlaşılır ve sorunun kaynağına daha hızlı ulaşılır. "test1, test2" gibi adlar vermeyin.

`TestMovie` sınıfında `testMovieTypes` adlı tek bir metod vardır. Aynı türden iki filmin (iki yeni çıkan film) fiyat kodlarının eşit, farklı türden filmlerin (çocuk ve normal film) fiyat kodlarının farklı döndüğü dört assert ile (`assertEquals`, `assertNotEquals`, `assertTrue`, `assertFalse`) sınanır. Böylece kara kutu da olsa veri kümesi açısından kapsayıcı bir test hazırlanmıştır. Hoca normalde bunların ayrı test metodlarında olmasını beklediğini; burada yalnız bir metodda birden fazla assert kullanılabileceğini göstermek istediğini söyledi.

**Test takımı.** `TestAll` sınıfında, adı `suite` olan, parametre almayan, `Test` türünden nesne döndüren public static bir metod yazılır. Bu metod içinde bir `TestSuite` nesnesi tanımlayıcı bir adla oluşturulur ve eklenmek istenen test case sınıfları `addTestSuite` metoduyla `Sınıf.class` biçiminde verilir. Hocanın takımının adı "Bütün testler" idi. <!-- BELİRSİZ: TestAll sınıfının kodu ekranda okunmadı; yapı altyazıdaki anlatımdan ve slayttaki suite(): Test imzasından kurulmuştur. -->

### 15.5 Testlerin çalıştırılması

Test sınıfı üzerinde sağ tıklayıp **Run As → JUnit Test** denir. Eclipse JUnit perspektifine geçer. **Yeşil çubuk** bütün testlerin başarılı olduğu anlamına gelir (ekrandan, 03:00:00): "Runs: 6/6, Errors: 0, Failures: 0". `TestCustomer` altında 5 test case (`testGetName`, `testStatementWhenEmpty`, `testNewReleaseRentalBonus`, `testStatementWithMoviesShortRent`, `testStatementWithMoviesLongRent`) ve `TestMovie` altında tek bir giriş görünür. `TestMovie`'de 4 assert olmasına rağmen tek bir metod olduğu için tek test sayılır.

**Hata olsaydı ne olurdu?** Hoca müşteriyi yanlış anlamış gibi yaparak kodu bilerek bozdu: normal filmlerde 2 günü aşan her gün için 1,5 yerine 1 lira hesaplanacak şekilde değiştirdi. Testler yeniden çalıştırılınca **kırmızı çubuk** göründü. Başarısız testin altı açıldığında **Failure Trace** bölümü karşılaştırma hatasını "expected ... but was ..." biçiminde verdi. Bu bilgi baştan değil, farklılaşmanın başladığı ilk noktadan itibaren verilir; farkın başladığı ve bittiği yerler köşeli parantezle işaretlenir. Bu örnekte beklenen makbuzda The Matrix için 3.5 ve toplam 12.5 varken elde edilende 3.0 ve toplam 12 vardı; makbuzun geri kalanı aynıydı.

Hesap (ara adım eklendi): 3 günlük normal kiralama doğru kuralla $2 + (3-2)\times 1{,}5 = 3{,}5$; bozuk kuralla $2 + (3-2)\times 1 = 3{,}0$. Toplam doğru kuralla $3{,}5 + 3{,}0 + 6{,}0 = 12{,}5$, bozuk kuralla $3{,}0 + 3{,}0 + 6{,}0 = 12{,}0$. Bu değerler python ile doğrulandı.

Fark yalnız The Matrix satırında ve toplamda olduğundan hoca `setUp`'a bakıp bu filmin türünü kontrol etti, `Movie.getCharge` içindeki ilgili `case` dalına gidip hatayı düzeltti. Testler yeniden çalıştırıldı; JUnit'te yalnız başarısız olanları ya da hepsini yeniden çalıştırma seçenekleri vardır. Hepsi çalıştırılınca yeşil çubuk geri geldi.

> **Ders sonrası not:** Altyazıda hoca hatanın yeri ararken The Matrix'in "yeni çıkan film" olduğunu söylüyor gibi görünüyor. Ancak `setUp` kodunda The Matrix `Movie.REGULAR` olarak tanımlı (ekrandan, 03:00:00). Hocanın bozduğu kural da normal filmin ek gün ücretiydi. Fark (3,5 yerine 3,0) normal film kuralına uyar; düzeltilen dal büyük olasılıkla `REGULAR` dalıdır. <!-- BELİRSİZ: altyazının bu kısmı bozuk. -->

Hoca dönem projesiyle bağlantı kurarak, ekipteki herkesin tasarımdaki sınıf, metod ve sıralama şemalarından yola çıkarak bu biçimde birim sınaması kodu yazabileceğini söyledi.

## Örnek Sorular

**Soru 1** (ekrandan, 01:10:00): Sınıflar birim sınamalarını geçmişlerse, bir araya getirildiklerinde de doğru çalışmazlar mı?

> **Çözüm (derste verildi):** Çalışmayabilirler. Yazılım geliştirme sürecinin her aşamasında her ayrıntı açıkça belirlenemez. Ayrı programcılar belirlenmemiş ayrıntılarda kendi inisiyatifleriyle birbirine uymayan kararlar verebilir; aynı kişinin farklı zamanlardaki kararları bile çelişebilir. Bu yüzden birim sınamalarından sonra tümleştirme sınamaları gerekir. (El kurutma makinesi ve çöp kutusu benzetmesi.)

**Soru 2** (ekrandan, 01:00:00): Birim sınamaları ne zaman tasarlanır, ne zaman yürütülür?

> **Çözüm (derste verildi):** Tasarım kodlamadan önce (çevik yaklaşım, TDD), kodlama sırasında ya da kodlamanın ardından yapılabilir. Beyaz kutu sınaması için kodlamanın ardından tasarlamak daha mantıklıdır. Yürütme ise kodlama sırasında ya da kodlamanın ardından yapılır.

**Soru 3** (ekrandan, 02:55:00): `setUp()`'ta tanımlanan filmlerle müşteri The Matrix'i (normal) 3 gün, Monsters, Inc.'i (çocuk) 4 gün, Surrogates'i (yeni çıkan) 2 gün kiralıyor. `statement()` metodunun döndürmesi beklenen makbuz nedir?

> **Çözüm (derste verildi; python ile doğrulandı):**
>
> - The Matrix: $2 + (3-2)\times 1{,}5 = 3{,}5$; bonus 1.
> - Monsters, Inc.: $1{,}5 + (4-3)\times 1{,}5 = 3{,}0$; bonus 1.
> - Surrogates: $2 \times 3 = 6{,}0$; yeni çıkan ve 1 günden uzun olduğu için bonus 2.
> - Toplam borç $12{,}5$, toplam puan $1+1+2 = 4$.
>
> Makbuz: `Rental Record for <ad>` / `\tThe Matrix\t3.5` / `\tMonsters, Inc.\t3.0` / `\tSurrogates\t6.0` / `Amount owed is 12.5` / `You earned 4 frequent renter points`.

**Soru 4** (derste sözlü, 03:01:52): Normal filmin 2 günü aşan her günü için yanlışlıkla 1,5 yerine 1 lira hesaplanırsa Soru 3'teki test ne sonuç verir, hata nasıl bulunur?

> **Çözüm (derste verildi):** Test kırmızı çubukla başarısız olur. Failure Trace beklenen ile elde edileni farkın başladığı yerden gösterir: The Matrix için 3.5 yerine 3.0, toplam için 12.5 yerine 12.0. Yalnız normal film satırı farklı olduğundan hata `Movie.getCharge` içindeki `REGULAR` dalındadır. Düzeltilip testler yeniden çalıştırılınca yeşil çubuk görülür.

## Dersin Toparlaması

Bu derste yazılım sınamasının yaşam döngüsünün her aşamasına yayılan, planlanması ve ölçülmesi gereken bir etkinlik olduğu görüldü. Sınama "yıkıcı" bir iştir ve bu yüzden kod, yazarından başka kişilerce de sınanmalıdır. Sınama hiçbir zaman bütün hataları yakalayan bir güvenlik ağı değildir; hedefler (kapsama, kaynak, MTBF/MTTR gibi ölçütler) baştan belirlenmelidir. Sınama türleri iki eksende ele alındı: kara kutu ve beyaz kutu; doğrulama (birim, tümleştirme: smoke ve regression) ve geçerleme (alfa, beta). Ardından sistem düzeyinde kurtarma, güvenlik, zorlama ve başarım sınamaları, hata ayıklamanın önemi ve IEEE 1028'e göre resmi gözden geçirmenin yedi adımı işlendi.

Dersin son bölümünde JUnit çerçevesi tanıtıldı: 3.x sürümünde `TestCase`'ten kalıtım, `test` önekli metodlar, `setUp` ve `suite`; 4.x sürümünde `@Test`, `@Before` ve `@Test(expected=...)`. Fowler'ın video kaset kiralama örneğinde gereksinim belgesindeki fiyat kurallarından elle hesaplanan beklenen makbuzlarla kara kutu birim testleri yazıldı. Eclipse'te yeşil ve kırmızı çubuk ile Failure Trace kullanılarak bir hatanın nasıl yakalanıp düzeltildiği gösterildi. Bu bilgiler dönem projesinde yazılacak birim sınamalarının temelini oluşturur.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
