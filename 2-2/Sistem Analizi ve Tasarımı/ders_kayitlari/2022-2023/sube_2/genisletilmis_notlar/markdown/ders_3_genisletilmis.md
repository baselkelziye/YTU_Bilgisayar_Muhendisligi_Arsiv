# Ders 3 Genişletilmiş Notu: Ön İnceleme, Fizibilite Türleri, Ekonomik Fizibilite Yöntemleri ve MS Project ile Zaman Fizibilitesi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Ön İnceleme Safhası
- 2. Kapsam Tanımlama Belgesi (Project Charter)
- 3. Fizibilite Çalışması Nedir?
- 4. Fizibilite Tiplerine Genel Bakış
- 5. Teknik Fizibilite
- 6. Sosyal (Operasyonel) Fizibilite
- 7. Yönetim Fizibilitesi
- 8. Yasal Fizibilite
- 9. Ekonomik Fizibilite
- 10. Zaman Fizibilitesine Giriş
- 11. Fizibilite Matrisi
- 12. Gantt Şeması ve Temel Kavramlar
- 13. PERT Diyagramı
- 14. MS Project Uygulaması: Bitirme Projesi Planı
- 15. Takvim, Kaynak Maliyeti ve Ağ Diyagramı

## 1. Ön İnceleme Safhası

Dersin iki temel başlığı var: bilgi sistemi geliştirme sürecinin ilk aşaması olan ön inceleme ve ardından gelen fizibilite çalışması. Hoca, temel süreç modelini, yani şelale (waterfall) modelini kullandığımızda karşımıza ilk olarak ön inceleme safhasının çıktığını söyledi. Bu safha ayrı bir aşama olarak konumlandırılabilir ya da fizibilitenin birinci adımı olarak tanımlanabilir. Hocaya göre ikisinin birbirine üstünlüğü yoktur; projenin büyüklüğüne göre biri seçilebilir.

<!-- BELİRSİZ: Altyazıda iki seçenek için de "çok büyük bir projeyse" deniyor (00:13:32). Cümlelerden biri büyük olasılıkla "çok büyük değilse" olmalı; hangi seçeneğin hangi büyüklüğe bağlandığı net değil. -->

Ön inceleme adından da anlaşılacağı gibi problemi henüz çözmeden ele alır. Sorulan şey şudur: Bu iş nedir, evdeki mevcut imkânlarımızla ya da gerekli takviyeler sağlandığında bu ürünü geliştirebilir miyiz, bu çözümü ortaya koyabilir miyiz?

### 1.1 Ön İncelemede Sorulan Sorular

**Birinci soru: Bu sisteme gerçekten ihtiyaç var mı?** Yani bu bir ihtiyaç mı, yoksa yapmış olmak için mi yapılıyor? Soruyu "mevcut sistemi iyileştirsek ya da eksik kalan yerlerini tamamlasak yetmez mi?" diye de okuyabiliriz. İhtiyaç, teknolojilerin çok eski kalmasından, sistemin işlem hacmini artık kaldıramamasından ya da hiç bilgi sistemi bulunmamasından doğabilir. Cevap salt evet ya da hayır olmak zorunda değildir: "Evet, ama şöyle" ya da "hayır, ama şuraya şöyle bir ek yapılırsa daha iyi olur" gibi bir çıktı da üretilebilir.

**İkinci soru: Bu sistemi geliştirmek için nelere ihtiyacımız var?** Burada hoca "ben" yerine her zaman ekip olarak, "biz" diye düşünmemizi istedi. Elimizdeki geliştirme kaynakları, bilgisayar ortamları, ağ altyapıları, veri tabanı yapıları yeterli mi, başka bir teknolojiye ihtiyaç duyacak mıyız, insan kaynağı yeterli mi? Kaynaklar arasında insan kaynağı önceliklidir, teknik kaynaklar da neredeyse aynı ağırlıkta düşünülür. Henüz çok ayrıntılı bir inceleme yapılmaz. Amaç boyutları kestirebilmektir: Şu hacimde sunucu işlem gücü, şu kadar ağ altyapısı, şu kadar veri depolama gerekir gibi. Örneğin video paylaşımı yapılacaksa çok ciddi disk alanı gerekebilir. Bu kestirim beyin fırtınasıyla yapılabilir.

**Üçüncü soru: Ne kadar zamanımız var?** Hoca zamanı da çok değerli bir kaynak olarak niteledi. İki durum olabilir:

- **Esnek takvim:** Belirli işlevsellikler sağlansın; üç ayda da olur, beş ayda da. Eldeki kaynaklara göre oluşturulan takvim kabul edilebilir.
- **Kesin teslim tarihi (hard deadline):** Ne olursa olsun sistem şu tarihte, şu saatte devreye alınmış olacaktır.

**Dördüncü soru: Tahmini bütçe ne olacak?** İnsan kaynağı, teknik kaynaklar ve süre kullanılacak. Belki dış hizmet alınacak, denetleme mekanizmalarına para ödenecek. Burada kuruşuna kadar bir analiz beklenmez. Ama kabaca 10 kişinin çalışacağı, 3 ay sürecek, belli sistem gereksinimleri olan bir projenin "üç aşağı beş yukarı" kaça mal olacağı kestirilebilir.

**Beşinci soru: Fayda maliyeti karşılıyor mu?** Hızlı bir fayda-maliyet analizi yapılır: Sistemin faydaları neler, zararları ya da zorlukları neler? Hocanın deyimiyle, attığımız taş ürküttüğümüz kuşa değecek mi?

### 1.2 Safhanın Sonucu: Tamam mı, Devam mı?

Hocaya göre ön inceleme aslında ikili tek bir soruya cevap verir: tamam mı, devam mı? Sonuç şu biçimlerden biridir: Mevcut şartlarda, tanınan kaynak, süre ve bütçeyle bu projeyi yapamayız; yapabiliriz; ya da yapmak için ilaveten şunlara ihtiyaç duyulacağı değerlendirilmiştir. Bu sonuca beyin fırtınasıyla, ekibin deneyiminden yola çıkarak ve mevcut örnekleri inceleyerek ulaşılır.

## 2. Kapsam Tanımlama Belgesi (Project Charter)

Aşamanın sonunda bulguların daha resmî bir hâle getirilmesi beklenir. Bunun için projenin kapsamını tanımlayan basit bir doküman üretilir. Bu dokümanın adı kapsam tanımlama belgesidir; literatürde ve profesyonel hayatta **Project Charter** olarak da geçer. Hoca "charter" sözcüğünü başlangıç niyeti, niyet mektubu gibi okuyabileceğimizi söyledi. Belgede şunlar yer alır:

- **Kapsam:** Ürün ne? Bu projenin çıktısının ne olması isteniyor?
- **Kalite:** Çıktı ne kadar iyi olmalı? Yazılım kalite kriterlerini ne kadar karşılaması bekleniyor? Hoca bu kriterlere ilerleyen haftalarda kısa bir giriş yapacağını belirtti.
- **Zaman:** Teslim tarihi belli mi, esnek mi? Kabaca bir zaman planlaması yapılır, en azından projenin fazları yazılır: İlk ayda ya da ilk fazda şunlar, ikincide bunlar yapılacak.
- **Maliyet:** Proje bütçesi kırılımlarıyla verilir: insan kaynağı, teknik kaynaklar ve ayrıntıları, hizmet alımları, denetlemeler.
- **Kaynaklar:** Nasıl bir ekip yapısı ve iş gücü gerekir? Nasıl bir teknolojik altyapı gerekir? Yazılımlar, donanımlar, sistem yazılımları, ağ iletişimi, veri depolama ihtiyaçları kabaca yazılır. Ayrıntılandırma esas olarak teknik fizibilitede yapılır.

Hoca bu belgeyi bir **niyet beyanı** olarak tanımladı. Geliştirici ekip şunu demiş olur: Böyle bir ürünü, şu kalite kriterlerini şu kadar karşılayacak biçimde, böyle bir zaman planı içinde, şu maliyetlerle ve şu kaynakları kullanarak yapmayı öngörüyoruz.

Bundan sonra bir değerlendirme toplantısı yapılır. Yönetim ya da üst yönetim kademesi, proje yöneticisini ve gerekiyorsa ekiplerdeki kritik elemanları da alarak toplanır. Projenin yapılıp yapılmayacağına, revizyona ihtiyaç olup olmadığına karar verilir. "Tamam mı, devam mı" sorusunun nihai cevabı burada oluşur: Ya "yapamayız, hiç başlamayalım" denir ve bırakılır, ya da yola devam edilir.

## 3. Fizibilite Çalışması Nedir?

Yola devam etmeyi seçtiysek ikinci aşamaya geçeriz. Bu aşamada ne ile karşı karşıya olduğumuzu, işi nasıl yapabileceğimizi ve bunun için nelere ihtiyaç duyacağımızı daha katı ve keskin biçimde ortaya koyarız. Buna **fizibilite çalışması** denir. Temel amaç, projenin yapılıp yapılamayacağını ve yapılması için gerçekten nelere ihtiyaç olduğunu daha kapsamlı olarak ortaya koymaktır. Sonuçta yine bir rapor üretilir: **fizibilite raporu**.

### 3.1 Güneş ve Rüzgâr Santrali Örneği

Hoca, fizibilite çalışmalarının yalnız bilgi sistemlerinde değil pek çok sektörde yapıldığını hatırlattı ve elektrik üretmek için kurulacak bir güneş ya da rüzgâr santralini örnek verdi. Kararı netleştirmek için şu sorular yanıtlanır:

- Buraya ne kadar yatırım yapılacak? Cihazlar ve altyapı ne kadar maliyet getiriyor?
- Devletten ne kadar teşvik, indirim ya da vergi desteği alınabilir, devlete ne kadar ödeme yapılacak?
- Arazi satın mı alınacak, kiralanacak mı, tahsis mi edilecek? Ödeme planı ne olacak?
- Üretilen elektrik kaça mal olacak? Cihazların ve şebeke parçalarının bakım ve işletme masrafı ne kadar?
- Elektrik satılabilecek mi? Kamuya mı, özel sektöre mi satılacak, ihraç edilebilir mi?

Bütün bunlar, projenin gerçekten faydalı ve kârlı olup olmadığına, verimlilik artışı getirip getirmeyeceğine net biçimde karar verebilmek içindir.

### 3.2 Bilgi Sisteminde Fizibilite

Aynısı bilgi sistemi için de geçerlidir. Geliştirme ve işletme masrafı ne olacak, ne kadar ilk yatırım gerekecek, sistemi ayakta tutmak için sürekli ne kadar para harcanacak? Karşılığında sistem ne kadar para kazandıracak ya da verimliliği ne kadar artıracak?

Hoca önemli bir ayrım yaptı: Bir bilgi sistemi yalnız para kazandırmak zorunda değildir. İşlerin yapılış hızını çok artırdığı ya da gereken kaynak miktarını çok azalttığı için de tercih edilebilir. Örneğin 100 kişi çalıştırmak yerine "sistem artı 5 kişi" çalıştırmak, belli bir süreye kadar çok daha ucuza gelebilir. Fizibilite çalışmasının işi bu ödünleşimi (trade-off) ortaya koymaktır: Yapalım mı, yapmayalım mı, yaparsak neye mal olur, bu kadar iyi yapabilmek için ne kadar kaynak gerekir?

## 4. Fizibilite Tiplerine Genel Bakış

Bilgi sistemi geliştirirken üzerinde durulması gereken fizibilite çeşitlerine **fizibilite tipi** denir. Hoca önce hepsini kısaca tanıttı:

- **Teknik fizibilite:** Teknik altyapı gereksinimleri neler? İki aşamada düşünülür: Ortada henüz sistem yokken onu üretmek için gerekenler (üretim maliyeti ya da üretim için gerekli kaynaklar diyebiliriz) ve sistem devredeyken gerekenler (sunucular, ağ altyapısı gibi). Örneğin sunucu satın almak mı, buluttan kiralamak mı gibi alternatifler de burada karşılaştırılır.
- **Zaman fizibilitesi:** Ana adımlar ve alt faaliyetler neler, hangi sırayla ve nasıl bir takvimle yapılacak, başlangıç-bitiş ilişkileri nasıl kurgulanacak, her faaliyete hangi insan ve teknik kaynaklar atanacak? Proje yöneticisi, yönetim kademeleri ve gerekiyorsa bütün çalışanlar, gidişatı bu plan üzerinden takip eder.
- **Sosyal fizibilite:** Sistem bir kapalı kullanıcı grubuna, teknik bir gruba ya da bütün dünyaya açık son kullanıcıya hizmet edebilir. Hizmet alan taraflar sistemi kabul edecek mi, sistem onlara fayda sağlıyor mu, bunun için ne yapılmalı?
- **Yönetim fizibilitesi:** Aynı soruların yönetim kademesi açısından okunmasıdır. Sistem yönetime verimlilik sağlıyor mu, yönetimin bundan yarar görmesi için ne yapmak gerekir?
- **Yasal fizibilite:** Yasal yönden yerine getirilmesi gereken sorumluluklar ve bunların maliyetleri.
- **Ekonomik fizibilite:** Gelinen son noktadır. Her şey para cinsine çevrilir ve ortak payda para birimi olur: Kaynaklar, zaman planı, hedef kitlenin kabulü, yönetimin memnuniyeti ve yasal zorunluluklar kaça mal olur? Her şey bu paydada toplanınca projenin ekonomik fizibilitesi ve kârlılık analizi ortaya konmuş olur.

Hoca bunların hepsinin her projede aynı ölçüde gerekli olmadığını, bazen gerekli bazen gereksiz olanlar çıkabileceğini de belirtti. Sonrasında tiplerin her birini ayrı ayrı ele aldı; zaman fizibilitesini uygulamalı anlatılacağı için sona bıraktı.

## 5. Teknik Fizibilite

Teknik fizibilitede, geliştirilecek bilgi sisteminin ihtiyaç duyduğu bütün teknik olanaklar belirlenir. Hoca iki aşamayı özellikle tekrar etti: geliştirme safhası ve devrede tutulma, yani ömrü boyunca işletme süresi. Teknik fizibilitenin altında mutlaka incelenmesi gereken üç alt başlık vardır: yazılım, donanım ve iletişim (ağ).

### 5.1 Yazılım Fizibilitesi

Bilgi sistemini geliştirmek için hangi yazılım kaynaklarına ihtiyaç duyulduğu ve hangilerinin neden tercih edildiği ortaya konur. İncelenen noktalar şunlardır:

- Sistemin üzerinde çalışacağı işletim sistemi: Windows temelli mi, Linux temelli mi, başka bir şey mi?
- Yazılım geliştirme ortamları.
- Veri depolama ve veri tabanı yönetim sistemleri.
- Uygulama sunucuları, yani sistemin üzerinde çalışacağı sistem yazılımları.
- Varsa destek yazılımları.

Bazen seçim şansı yoktur. Hocanın örneği: Bir banka için çalışıyorsunuz ve ana bankacılık uygulaması bir ana bilgisayarda (mainframe) duruyor. Mainframe'in işletim sistemi bellidir, örneğin IBM'de z/OS. O zaman z/OS üzerinde çalışacak bir sistem gerçekleştirirsiniz.

Bunun dışındaki durumlarda bütün alternatifler mümkün olduğunca karşılaştırmaya dahil edilmelidir. Windows kullanılırsa lisans ve bakım bedeli ne olur, sistem gereksinimleri için altyapı hangi seviyede olmalıdır? Linux kullanılırsa maliyet ne olur, nasıl bir bakım ya da eğitim desteği gerekir? Bütün olası maliyet kalemleriyle getiri ve götürü bir tablo hâlinde karşılaştırılmalıdır.

### 5.2 Donanım Fizibilitesi

Aynı inceleme donanım için yapılır. Önce geliştirme safhası düşünülür: Bir prototip ya da çalışabilir ilk sürüm için ekibe hangi cihazlar gerekir? Uç birimler, ekranlar, barkod okuyucular, yazıcılar, bilgisayarlar, erişim noktaları (access point), ağ altyapısı ya da projeye göre gömülü sistemler olabilir.

Yazılımda olduğu gibi donanımda da yalnız geliştirme değil, sistemin devrede kalacağı yaşam ömrü için gereken ihtiyaçlar da gözetilmelidir. Hoca bunun da yetmediğini, bir **projeksiyon** yapılması gerektiğini söyledi: Kısa ve orta vadede ihtiyaçlar nasıl değişecek? Örneğin kullanıcı sayısı doğrusal artacaksa depolama alanı da doğrusal mı, yoksa üstel mi artacak? Buna göre ne kadar daha fazla para ödenecek?

> **Hocanın vurgusu:** Fizibilite yaparken yazılımın ve bilgi sisteminin yaşam ömrü her zaman göz önüne alınmalıdır. "İki arkadaşız, iki laptop bize yeter" yaklaşımı doğru değildir; sistemin çalışması için başka şeylere de ihtiyaç vardır. Hoca bunu hem bu dersteki projeler hem de sonraki bütün projeler için "basa basa" söylediğini belirtti.

### 5.3 İletişim (Ağ) Fizibilitesi

Burada da iki soru vardır: Geliştirme safhası için neye ihtiyaç var, sistemi yaşatmak ve hizmet sunar hâlde tutmak için neye ihtiyaç var? Ayrıca zaman içindeki değişim sorulur: Kullanıcı ve işlem sayısı arttıkça ne kadar yeni yatırıma, kapasite artışına ihtiyaç duyulur? Bu projeksiyonlar da bu fizibilite altında yapılır.

### 5.4 Riskler ve Teknik Yetersizlikler

Alternatifler değerlendirilirken değişim riskleri özellikle göz önünde bulundurulmalıdır. Bir yazılım geliştirme ortamını seçmek iyi olabilir, ama belki iki sene sonra kullanılmayacağı, desteğin devam etmeyeceği ya da yerine yeni bir teknolojinin geleceği biliniyordur. Donanımda da uzun süredir devrede olan mimarinin değişeceği bilgisi olabilir.

Ekibin teknik yetersizlikleri de hesaba katılmalıdır. Hocanın örneği: Geliştirme ortamı olarak .NET Core seçtiniz, ekibiniz ise Java ya da .NET'in eski sürümlerini biliyor ama .NET Core deneyimi yok. Bu durumda hem bir eğitim maliyeti hem de adaptasyon süresi doğar; ayrıca ürün normalden daha yavaş üretilir. Bu tür yetersizlikler ve riskler fizibilite içinde birer maliyet ya da zorluk olarak mutlaka gösterilmelidir. Gerekiyorsa ekonomik tarafı da etkileyecek ilave önlemler alınır.

## 6. Sosyal (Operasyonel) Fizibilite

Geliştirilen sistemin bir hedef kitlesi vardır ve sistem bu kitlenin kabul edebileceği, beklentilerini karşılayacak biçimde geliştirilmelidir. Hocanın ilk örneği, kargo işletmesinde dağıtım yapan elemanlara hizmet eden bir uygulamaydı. Bunun için sistemi kullanacak kişilerle etkileşerek girdi almak gerekir: Klavyeden girmeyi mi, bir şeylere tıklamayı mı tercih ederler? Barkod mu okumak isterler, QR kod ya da RFID'li bir çözüm mü? İşlerin aksamaması ve çalışma rutinlerinin bozulmaması için ne yapılabilir? Sistemin kullanıcı kitlesince kabul edilip edilmeyeceği ve kabul edilmesi için yapılması gerekenler bu başlıkta incelenir.

Hoca bilerek uç bir örnek verdi: Okul öncesi çocuklara renkleri ve üçgen, kare, yuvarlak gibi temel şekilleri oyunlaştırarak öğreten bir mobil oyun. Hedef kitle 3-6 yaş arası çocuklardır. Onlardan klavyeyle giriş yapmaları ya da tıklamaları beklenmemelidir. Ekranda basit bir yere basmak olabilir, belki sesle komut verdirilebilir. Hedef kitlenin kabul edip kullanabilmesi için sistemde değişiklikler ve yeni ihtiyaçlar doğabilir.

Diğer uçta muhasebe birimi vardır. Onlar için Excel'e benzeyen arayüzler ya da daha önce kullandıkları sistemin menü tasarımlarına ve akışlarına benzer bir kurgu tercih sebebi olabilir.

Bu tipe **operasyonel fizibilite** de denebilir. Temel sorular şunlardır: Kim, hangi kitle kullanacak? Sistem bu kitle için kullanılır olsun diye ne yapılmalı? İlave ihtiyaçlar neler, ne maliyet getirir? Bunlar doğrusuyla, eğrisiyle, alternatifleriyle, getirisiyle ve götürüsüyle ortaya konmalıdır.

## 7. Yönetim Fizibilitesi

Sisteme kullanıcı açısından değil, yönetici gözlüğüyle baktığımızda yönetim fizibilitesini yaparız. Sistem yönetimin iş yapış ve takip şeklini, karar verme süreçlerini nasıl etkiliyor? Yönetim bu sistemin hizmetlerinden ve çıktılarından ne kadar fayda sağlayacak?

Bunun sonucunda yeni maliyetler ya da bazı şeylerin kısılması önerilebilir. Örneğin aylık, haftalık, günlük yeni rutin raporlar ya da uyarılar istenebilir: Siparişler 3 hafta boyunca belli bir oranda azalıyorsa sistem alarm üretsin. Bunun için yeni geliştirmeler ve maliyetler oluşabilir, iş planı değişebilir, yeni modüller ya da servisler ortaya çıkabilir. Yönetimin beklediği fayda seviyesini sağlamak için gerekenler alternatifleriyle karşılaştırılır.

## 8. Yasal Fizibilite

Hocaya göre yasal fizibilite, derste ve sonraki ara ve bitirme projelerinde en sık yanlış yapılan başlıktır. Yaklaşık yüzde 80'in yazdığını söylediği cümle şudur: "Gerçekleştirdiğimiz sistem yasalara tamamen uygundur, hiçbir yasa dışı eylem gerçekleştirmemektedir." Hoca bunun yasal fizibilite olmadığını, "ben yasal fizibilite gördüm" ya da "babamın yasal fizibilitesi var" demekten farklı bir şey olmadığını söyledi.

> **Hocanın vurgusu:** "Kanunlara uygun çalışıyorum, yasa dışı iş yapmıyorum" cümlesini kurmak yasal fizibilite yapmak değildir. Uyulması gereken kanunlar, yönetmelikler, özel izinler ve lisanslar, bunların nasıl karşılanacağı, alternatifleri ve zaman ile para olarak maliyetleri ortaya konmalıdır.

Nasıl ki hitap edilen kitle için sosyal, yönetici kitlesi için yönetim, teknik gereksinimler için teknik fizibilite yapılıyorsa, yasalar açısından da aynı çalışma yapılır. İncelenmesi gerekenler şunlardır:

- **Hizmet alanındaki regülasyonlar:** Hocanın örneği, borsayı izleyip hisse senetleri konusunda yönlendirme ya da raporlama yapan bir sistemdir. Sistem o piyasanın regülasyonlarına uygun geliştirilmeli, belki belli otoritelerden izin ya da onay alınmalı, denetimden geçilmelidir. Bir protokolü, yönetmeliği ya da mevzuatı karşılamak için yeni geliştirme yapılacak ya da hizmet alınacaksa bu bir maliyettir. Bazı şeyleri yapamamanın size ne kaybettireceği de tartışılmalıdır.
- **Patent ve fikrî sınai haklar:** Patentli bir algoritma ya da çözüm yöntemi kullanacaksanız "alırım kullanırım, kim anlayacak" denmemelidir. Hak sahibiyle görüşülmeli, sözleşme imzalanmalı, belki aylık ya da yıllık lisans bedeli ödenmelidir. Mevcut hakların kullanılıp kullanılmadığı ya da ihlal edilip edilmediği de burada incelenir.
- **Özel izin ve lisanslar:** Borsa örneğinde olduğu gibi belli kaynakları kullanmak için izin ya da lisans gerekiyor mu, bunlar parasal olarak ne getirip ne götürüyor?
- **Kurumun yaptığı anlaşmalar:** Kurum ya da kuruluşun imzaladığı anlaşmalara uygun davranılıyor mu, ihlal var mı?
- **Alternatifler:** Örneğin bunun yerine açık kaynak bir şey kullanılabilir mi? Bu, zaman planında ve maliyette neyi artırır, neyi azaltır?

<!-- BELİRSİZ: 00:47:04 ile 00:47:18 arasında altyazıda boşluk var; regülasyon maliyetleri anlatımının arasında kısa bir cümle kaybolmuş olabilir. -->

### 8.1 KVKK Örneği

Hocanın "en bilindik" dediği örnek kişisel verilerdir. Kişisel verilerle ilgili düzenlemeler son yıllarda her ülkede vardır ve ülkemizde de artık dikkat edilmektedir. Kullanıcı verilerini kendi sistemlerinizde tutmanız gerekiyorsa KVKK gereğince pek çok yeni sorumluluk ve yükümlülüğünüz vardır:

- Sistem buna göre tasarlanmalı, yeni raporlamalar ve güvenlik testleri kurgulanmalıdır.
- Belli aralıklarla bakanlıklara rapor göndermek gerekebilir.
- Bir kişi kişisel verilerinin silinmesini istediğinde veriler usulüne uygun biçimde silinmelidir. Bunun için yeni geliştirmeler ve modüller gerekebilir, mevcut yapılar bile bozulabilir.

Yani doğru cümle "kanunlara uygundur" değildir. Doğru soru, KVKK için neler yapılması gerektiği ve bunun zaman, kaynak ve para olarak neye mal olacağıdır.

### 8.2 İkinci Sık Hata: Sosyal Fizibilite

Hoca, en sık yapılan ikinci hatanın sosyal fizibilitede olduğunu ekledi. Şöyle yazılıyor: "Sistem kullanıcılara gösterilmiş, kullanıcılar tarafından beğenilmiştir, herhangi bir sorun olmadığı görülmüştür."

> **Hocanın vurgusu:** Bu yanlıştır, çünkü sosyal fizibilite daha en başta yapılır. Sistemin kullanıcılarca nasıl kabul göreceği, kullanıcının neyi kabul etmeyeceği anketlerle, görüşmelerle ya da başka bilgi toplama yöntemleriyle ortaya konmalıdır. Hedef kitlenin direnç göstermemesi için neler yapılabileceği ancak böyle düzgünce ifade edilebilir.

## 9. Ekonomik Fizibilite

Ekonomik fizibiliteye, diğer bütün fizibiliteler yapıldıktan sonra geçilmesinde fayda vardır. Çünkü oluşabilecek bütün maliyet kalemleri göz önüne alınır: Teknik fizibiliteden, zaman fizibilitesinden, yasal fizibiliteden, hatta sosyal fizibiliteden gelen maliyetler, hem geliştirme hem devrede tutma aşamaları için toplanır.

Hoca bunu bir terazi olarak anlattı: Bir kefede maliyetler, öbür kefede kârlar ya da verimlilik artışları vardır. Para kazanma amacı yoksa bile sistemin işleri ne kadar ucuza, ne kadar verimli, ne kadar az kaynakla yaptırdığına bakılır. Kâr ne kadar yüksek, maliyet ne kadar azsa proje o kadar "ballı" olur. Attığımız taş ürküttüğümüz kuşa değmiyorsa bir şeyler yanlıştır: Zaman planı, kaynak planı ya da yasal taraflar gözden geçirilip başka bir çözüm geliştirilebilir.

Ekonomik fizibilite, ekonomi ve istatistik dallarındaki maliyet-fayda yöntemlerinden yararlanır. Hoca bunun bilgisayar mühendisliğinin asıl konusu olmadığını, hızlıca tanıtacağını söyledi. Amaç şudur: Bugün bir birim yatırım yapıyorum; sistem örneğin 5 yıl çalışsın; her yılın sonunda yatırımım ve kazancım ne hâle gelecek?

Pek çok yöntem olmakla birlikte en çok kullanılan dördü şunlardır: bugünkü değer yöntemi, iç verim oranı, başa baş noktası ve geri ödeme süresi. Hepsi kullanılabilir. Genellikle projenin yapılış amacına göre yönetici taraf hangisinin daha uygun olduğunu seçer.

### 9.1 Bugünkü Değer Yöntemi

Proje hem geliştirme hem de yaşam ömrü boyunca para harcatır ve kazandırır, yani nakit çıkışları ve nakit girişleri vardır. Bunlar zaman içinde değişir. Hepsini sanki bugünmüş gibi bugünkü değerine indirgersek rasyonel bir kıyas yapabiliriz. Nakit girişleri harcamalardan büyükse proje mantıklıdır, yapılır. Değilse proje yapılmaz; gözden geçirilmesi, yeni bir fizibilite çalışmasıyla daha uygun bir çözüm getirilmesi ya da işin çöpe atılması kararlaştırılır.

Paranın bugüne indirgenmesinde kullanılan orana **iskonto oranı** (indirim oranı) denir ve $i$ ile gösterilir. Bu oranı belirlemenin farklı yolları vardır. Hocanın verdiği bilinen yöntem, piyasadaki ağırlıklı sektörlerin, örneğin bilişim alanında birlikte çalıştığınız ya da sizi etkileyen sektörlerin faiz ya da enflasyon oranlarının ortalamasını almaktır. Enflasyon yüksekse oranın da yüksek, düşükse düşük olması beklenir.

$n$ yıl sonraki bir nakit akışının bugünkü değer çarpanı şudur:

$$PVIF = \frac{1}{(1+i)^n}$$

> **Ders sonrası not:** Hoca slayttaki formülü sözlü olarak "$(1+i)^n$'e bölünmesi ve $Q_0$ ile çarpılması" diye okudu; kısa nota göre slaytta $V = Q_0 \frac{Q_n}{(1+i)^n}$ yazıyordu. Bu yazım eksiktir. $n$. yılın net nakit akışı $Q_n$ ve projenin ömrü $N$ yıl ise net bugünkü değer $NBD = \sum_{n=0}^{N} \frac{Q_n}{(1+i)^n}$ olur. Burada $Q_0$, genellikle negatif olan ilk yatırımdır. $NBD > 0$ olması, hocanın "nakit girişleri harcamalardan büyükse proje mantıklıdır" ölçütünün karşılığıdır.

#### Bugünkü değer tablosu

Hoca, 1 liranın bugünkü değerini 9 yıl ve farklı iskonto oranları için gösteren slayt tablosunu okudu. Aşağıdaki tablo formülle yeniden hesaplanmıştır (satırlar yıl, sütunlar iskonto oranı):

| $n$ | %1 | %2 | %3 | %4 | %5 | %6 | %7 | %8 | %9 |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 1 | 0,990 | 0,980 | 0,971 | 0,962 | 0,952 | 0,943 | 0,935 | 0,926 | 0,917 |
| 2 | 0,980 | 0,961 | 0,943 | 0,925 | 0,907 | 0,890 | 0,873 | 0,857 | 0,842 |
| 3 | 0,971 | 0,942 | 0,915 | 0,889 | 0,864 | 0,840 | 0,816 | 0,794 | 0,772 |
| 4 | 0,961 | 0,924 | 0,888 | 0,855 | 0,823 | 0,792 | 0,763 | 0,735 | 0,708 |
| 5 | 0,951 | 0,906 | 0,863 | 0,822 | 0,784 | 0,747 | 0,713 | 0,681 | 0,650 |
| 6 | 0,942 | 0,888 | 0,837 | 0,790 | 0,746 | 0,705 | 0,666 | 0,630 | 0,596 |
| 7 | 0,933 | 0,871 | 0,813 | 0,760 | 0,711 | 0,665 | 0,623 | 0,583 | 0,547 |
| 8 | 0,923 | 0,853 | 0,789 | 0,731 | 0,677 | 0,627 | 0,582 | 0,540 | 0,502 |
| 9 | 0,914 | 0,837 | 0,766 | 0,703 | 0,645 | 0,592 | 0,544 | 0,500 | 0,460 |

Tabloyu şöyle okuruz: %1 iskonto oranıyla, bir yıl sonraki 1 liranın bugünkü değeri $1/1{,}01 \approx 0{,}990$ liradır, yani 99 kuruş. %5 oranında değerler 95 kuruştan başlar, her yıl düşer ve 9. yılda $1/1{,}05^9 \approx 0{,}645$ liraya, yani yaklaşık 65 kuruşa iner. Hoca buradan şu sonucu çıkardı: Bugünkü 1 lira bazında konuşursak yıllar sonra "kuş kadar kalmış" bir parayla konuşuyor oluruz. Dolayısıyla ileride yapılacak bir masraf hesaplanırken paranın o tarihteki değeri 1 lira değil, örneğin 65 kuruşmuş gibi değerlendirilmelidir. Hoca, günümüzdeki enflasyon düşünüldüğünde bu azalışın yıllar içinde ne kadar dramatik hâle geldiğine de dikkat çekti.

Yöntem özellikle uzun vadeli yatırımlar için, yani 10 ya da 20 yıl sonrası hedefleniyorsa uygun olabilir.

> **Ders sonrası not:** Hoca tabloyu okurken oranları önce "%10, %20, %30" ve "yüzde onsa" diye söyledi, hemen ardından doğrusunu ("%1 iskonto oranıyla") verdi. Sütunlar %1, %2, %3... şeklindedir. "9 yıl sonra 87 kuruş" sözü %1 oranı için doğru değildir: %1'de 9 yıl sonraki 1 lira $1/1{,}01^9 \approx 0{,}914$ lira, yani yaklaşık 91 kuruş eder. Kısa nota göre slaytın ilk satırının son hücresinde (%9, 1 yıl) 0,870 yazıyordu; hoca büyük olasılıkla bu satırı yıl gibi okumuştur. Aynı kısa nota göre slaytta iki hatalı değer vardır: (%9, 1 yıl) için 0,870 yerine 0,917, (%8, 4 yıl) için 0,835 yerine 0,735 olmalıdır.

> **Ders sonrası not:** Hoca "10 yıllık ömür" derken 65 kuruş değerini kullandı. 65 kuruş, %5'te 9. yılın değeridir; %5'te 10. yılın değeri $1/1{,}05^{10} \approx 0{,}614$ liradır.

### 9.2 İç Verim Oranı (Kârlılık Oranı)

Bugünkü değer yöntemine benzer bir başka yöntem, kârlılık oranı ya da **iç verim oranı**dır. Zaman değeri ve ekonomik ömür dikkate alınarak nakit girişleriyle yatırım maliyetini eşitleyen iskonto oranı aranır. Başka bir deyişle, bugünkü değeri sıfırlayan iskonto oranıdır. Formüldeki $i$ bilinen değil, aranan büyüklük olur:

$$\sum_{n=0}^{N} \frac{Q_n}{(1+i)^n} = 0$$

Bu sonucu şöyle de okuyabiliriz: Bu girdi ve çıktılar için hangi enflasyon ya da faiz oranının altı kabul edilebilir, üstü kabul edilemez? Oranın yüksek olması istenir. Faiz ve enflasyon oranları sizin için önemliyse bu yöntem kullanılabilir.

### 9.3 Başa Baş Noktası

Başa baş noktası özellikle yatırımcıların, örneğin melek yatırımcıların ve bir girişime para yatıranların çok önemsediği bir iktisadi analizdir. Proje işletme aşamasına geçtikten sonra toplam gelir ile toplam giderin nerede eşitlendiğini gösterir. Bu grafikte bütün harcamalar, maliyetler ve faydalar, sabit ve değişken kalemleriyle birlikte, aynı eksen takımında gösterilir. İki eğrinin kesiştiği nokta başa baş noktasıdır. Yatay eksen üretim hacmi de olabilir, zaman da. Bu noktadan sonra kâr elde edilmeye başlanır.

Hocanın gösterdiği grafikte satış sıfırdan başlayıp doğrusal artıyordu. Hoca bunun azalarak da değişebileceğini, grafiğin projeye ya da ürüne bağlı olduğunu söyledi. Bunun yanında her zaman sabit maliyetler ve üretim maliyetleri vardır. Üretim maliyetlerinin başta yüksek olması, sonra azalması beklenir; yani maliyet eğrisinin eğimi giderek küçülür.

Yatırımcı için önemli olan soru şudur: Parayı yatırdım; 3 yıl sonra mı, 5 yıl sonra mı kâr etmeye başlayacağım? Bu noktanın mümkün olduğunca başa yakın, grafikte sola doğru olması istenir, ama hızlar sektöre göre değişebilir. Yatırımcı kârlılığı artırarak ya da proje planına ve maliyetlere müdahale ederek noktayı sola kaydırmak isteyebilir.

<!-- BELİRSİZ: Başa baş grafiği slaytta; eksen adları ve eğrilerin biçimi altyazıda yalnızca sözlü geçiyor (01:02:10-01:02:52). -->

> **Ek bilgi (derste anlatılmadı):** Gelir ve maliyetler doğrusal varsayılırsa birim fiyat $p$, birim değişken maliyet $v$, sabit maliyet $F$ için başa baş hacmi $pQ = F + vQ$ eşitliğinden $Q^* = F/(p-v)$ olarak bulunur. Derste gösterilen eğriler doğrusal olmak zorunda değildir; o durumda nokta grafikten okunur.

### 9.4 Geri Ödeme Süresi

Dördüncü yöntem başa baş noktasına benzer. Gerekli bir yatırım ve yıllık bir yarar vardır. Soru şudur: Başta yaptığım yatırımı kaç yılda toplayacağım? Hocanın benzetmesiyle, sanki birine kredi veriyorsunuz ve o krediyi şu kadar zamanda ödeyecek. Özellikle başta toplu yatırım yapan bir yapı ya da yatırımcı varsa bu yöntem istenebilir.

$$\text{Geri ödeme süresi} = \frac{\text{Yatırım tutarı}}{\text{Yıllık net yarar}}$$

> **Ders sonrası not:** Hoca "yıllık yararları yatırım miktarına bölüyoruz" dedi. Doğrusu tersidir: Sonucun yıl birimiyle çıkması için yatırım tutarı yıllık yarara bölünür.

> **Ders sonrası not:** Hoca bu hesabın "amortisman hesabı" olarak da bilindiğini söyledi. Burada kastedilen, yatırımın kendini geri ödemesidir ("kendini amorti etme"). Muhasebede "amortisman" terimi büyük olasılıkla bir varlığın maliyetinin yıllara dağıtılması anlamında kullanılır, bu yüzden ikisi karıştırılmamalıdır.

### 9.5 Ekonomik Fizibilitenin Sonucu

Her şey, yani geliştirme, devrede tutma, güncelleme ve değişiklik gereksinimleri para cinsine çevrilip toplanır ve bu yöntemlerle analiz edilir. Tatmin edici bir değere ulaşılana kadar iş planı ya da kaynaklar revize edilir veya daha fazla paraya ihtiyaç olduğu ortaya çıkarılır. Sonuçta kaynak, süre, maliyet ve yasal, sosyal, yönetimsel sorumluluklar açısından belirli bir proje yol haritası ortaya çıkmış olur.

## 10. Zaman Fizibilitesine Giriş

Zaman planının belirlenmesi zaman fizibilitesi kapsamında yapılır. Hoca bu bölümde cevaplanacak soruları sıraladı: İş paketleri neler? Her pakette hangi alt faaliyetler yapılacak? Aralarındaki ilişkiler ve süreleri ne olacak? Hangi insan ve teknik kaynaklar nasıl atanacak? Belli noktalarda gözden geçirme yapılacak mı? Kilometre taşı dediğimiz önemli tarihler ya da geçiş noktaları var mı? Uygulamalı kısmı dersin sonunda asistan anlattı (Bölüm 12-15).

## 11. Fizibilite Matrisi

Bütün fizibilite çalışmaları sonucunda, alternatifleri belirlenmiş çeşitli çözüm önerileri ortaya çıkar. Her alternatif çözüm için ayrı bir fizibilite çalışması yapılması beklenir. Alternatifler sütunlar hâlinde yazılır: En az 2 olmak üzere, tercihen 3 ve üzeri çözüm ortaya konur. Bunların bir matris içinde karşılaştırılmasına **fizibilite matrisi** denir. Satırlarda fizibilite tipleri bulunur:

- **Teknik:** Örneğin kendi sunucularımızı satın alıp Windows kullanmak, Linux kullanmak ya da buluttan kiralamak (Amazon gibi).
- **Ekonomik:** Şöyle bir yatırımla şu kadar sürede kendini amorti eden bir sistem.
- **Zaman:** Biri 3 ay sürer ama çok insan kaynağı gerektirir, biri 5 ay sürer ama daha az insan kaynağı gerektirir.
- **Sosyal, yönetim ve diğerleri:** Her biri için ayrı değerlendirme.

Her satıra yüzde olarak bir ağırlık verilir. Proje çok teknikse teknik fizibilitenin, parasal karşılık önemliyse ekonomik fizibilitenin, zaman aşırı önemliyse zaman fizibilitesinin ağırlığı artırılır. Ağırlıkların toplamı %100 olmalıdır.

Ardından her hücreye puan verilir. Hocanın sözlü örneği teknik satırı içindi: Windows ve satın alma maliyet getirdiği için 50 puan; Linux daha ucuz olduğu ve deneyimli eleman bulunduğu için 80 puan; kiralama başta ucuz görünse de 10 yıllık yaşam ömrü ve artan kullanıcı sayısı düşünüldüğünde pahalıya geldiği için 10 puan. Zaman satırında da 20, 50 ve 10 puan verilebilir. Hoca, puanların her satırda 100'e normalize edilmesinin, yani 100 puanın alternatifler arasında paylaştırılmasının faydalı olduğunu söyledi.

Son olarak puanlar ağırlıklarla çarpılıp toplanır. Hocanın örnekleri:

- 10 puan alan bir alternatifte teknik fizibilite ağırlığı %20 ise katkı $10 \cdot 0{,}20 = 2$ puandır (ara adım eklendi).
- 80 puan alan bir alternatifte ağırlık %50 ise katkı $80 \cdot 0{,}50 = 40$ puandır.

> **Ders sonrası not:** Hoca 40 puan için "%40 puan" dedi; doğrusu 40 puandır. Sözlü örnekteki puanlar 100'e normalize değildir: Teknik satırı $50+80+10=140$, zaman satırı $20+50+10=80$ eder. İki örnekte teknik ağırlığın farklı (%20, %50) söylenmesi de yalnız hesabı göstermek içindir.

Toplamlarda örneğin 60, 85 ve 70 puan çıkarsa 85 en yüksek olduğu için o öneri tercih edilir: O zaman planı uygulanır, o ekonomik model kurgulanır, o yazılım, donanım ve ağ altyapısı kullanılır.

### 11.1 Slayttaki Örnek

Hoca slayttaki matrisi gösterdi. Değerler kısa nottan alınmıştır (kısa nota göre slayt 38):

| Fizibilite | Ağırlık | Sistem 1 | Sistem 2 | Sistem 3 |
| :--- | :---: | :---: | :---: | :---: |
| Teknik | %30 | 50 | 95 | 60 |
| Ekonomik | %30 | 60 | 85 | 90 |
| Zaman | %10 | 95 | 80 | 85 |
| Operasyonel | %30 | 60 | 100 | 100 |
| **Toplam** | %100 | **60,5** | **92** | **83,5** |

Her sistemin ağırlıklı toplamı şöyle hesaplanır (ara adım eklendi):

$$S_1 = 0{,}3\cdot50 + 0{,}3\cdot60 + 0{,}1\cdot95 + 0{,}3\cdot60 = 15 + 18 + 9{,}5 + 18 = 60{,}5$$

$$S_2 = 0{,}3\cdot95 + 0{,}3\cdot85 + 0{,}1\cdot80 + 0{,}3\cdot100 = 28{,}5 + 25{,}5 + 8 + 30 = 92$$

$$S_3 = 0{,}3\cdot60 + 0{,}3\cdot90 + 0{,}1\cdot85 + 0{,}3\cdot100 = 18 + 27 + 8{,}5 + 30 = 83{,}5$$

Hoca, burada 60 puanlı öneriyi bir kenara bırakıp en yüksek iki öneriyi birlikte yeniden değerlendirmenin de mümkün olduğunu söyledi. Yine de genellikle tek bir sütunun seçilmesi tercih edilir.

> **Ders sonrası not:** Hoca sonuçları "60, 92, 83" ve bir yerde "92 ve 84" diye okudu; hesaplanan değerler 60,5, 92 ve 83,5'tir. "Burada bir normalizasyon yapmamışız" sözü, puanlar içindir: Ağırlıkların toplamı %100'dür, ama satır puanlarının toplamları 205, 235, 260 ve 260'tır.

Farklı sistem önerilerinin parçalarını birleştirmek pek tercih edilen bir şey değildir. Örneğin teknik ve ekonomik fizibilite sizin için önemliyse, bunların ikisinde iyi olan seçenekleri baştan aynı sistem önerisinde toplamayı tercih edebilirsiniz. Hangi seçeneğin hangi öneriye yazılacağı size kalmıştır; hoca burada rasyonel davranmakta fayda olduğunu söyledi.

> **Hocanın vurgusu:** Dersi tekrar dinleyin, fizibilite tiplerini kaynaklardan ve internetten örnekleriyle inceleyin. Bunları projelerinizde pratik olarak uygulayacaksınız.

## 12. Gantt Şeması ve Temel Kavramlar

Dersin bu kısmını asistan Elçin Hoca, önce teorik olarak sonra MS Project üzerinde anlattı. **Gantt şeması** temeli 1910'lara dayanan, Henry Gantt tarafından önerilmiş bir çizelgedir. Projenin her işine **faaliyet** denir ve şema faaliyetler üzerinden oluşturulur. Faaliyetlerin süreleri, atanan kaynakları ve diğer bilgileri şemada gösterilebilir.

**Soru:** MS Project öğrencilerin kullanımına açık mı? **Cevap:** Asistan en son hatırladığı kadarıyla yazılım dağıtım sisteminde (altyazıda "Distro") yalnız akademisyenlere açık olduğunu, ama mantık aynı olduğu için farklı programların da kullanılabileceğini söyledi. Hoca, eskiden eski sürümlerin öğrenciler dahil herkese açık olduğunu, son sürüme gerek olmadığını ve açık kaynak yazılım ve platformların da işi gördüğünü ekledi.

### 12.1 Şemanın Yapısı

Örnek şemada analiz, tasarım gibi işler ve bunların altındaki işlemler vardı. Satırlara işler yazılır ve bir ana başlığın altında kırılımları verilir; iş paketleri böyle oluşur. Girintilenen işler üst başlığın alt işi olur. **Work Breakdown Structure (WBS)** sütunu her işin numarasını otomatik verir. Asistan, MS Project Türkçe kullanılırsa bu sütunun adının "çalışma çözümleme yapısı" (ÇÇY) olduğunu belirtti. En baştaki sıfır numaralı satır projenin özetidir; buraya atama yapılmaz, projenin süresi, başlangıcı ve bitişi işler girildikçe otomatik oluşur.

Başlangıç ve bitiş tarihlerini her iş için elle yazmak gerekmez. İlk işin başlangıcı verilir, süreler ve öncüller girildikçe gerisi otomatik hesaplanır (auto schedule). **Öncül** (predecessor) sütununa, bağlanacak işin ID'si yazılır. Örnek şemada analiz bitimindeki toplantının öncülü 3 numaralı iş, yani gereksinim belirleme işiydi.

Kaynak ataması da yapılır: Fizibilite çalışmasını "Analist 1" isimli bir kişinin yapması gibi. Kaynak yalnız insan değil, makine ya da teçhizat da olabilir.

<!-- BELİRSİZ: Slayttaki örnek Gantt şemasının satırları, süreleri ve tarihleri altyazıda tam okunmuyor (01:19:38-01:23:04). -->

### 12.2 Faaliyetler Arası İlişkiler

Faaliyetler arasında dört temel ilişki vardır:

- **Bitiş-başlangıç (Finish to Start, FS):** En sık kullanılan ve varsayılan ilişkidir. Bir faaliyetin başlaması için önceki bitmiş olmalıdır. Örnek: Analiz bitsin, sonra tasarım başlasın.
- **Başlangıç-başlangıç (Start to Start, SS):** Örnek: Birim testlerini başlatmak için önce kodlamanın başlamış olması gerekir. Geliştirme başlayınca birim testleri de başlar.
- **Bitiş-bitiş (Finish to Finish, FF):** Bir faaliyetin bitmesi diğerinin bitmesine bağlanır. Örnek: Birim test aşaması ancak kodlama biterse biter.
- **Başlangıç-bitiş (Start to Finish, SF):** Asistanın "ifade olarak ters gelebilir" dediği ilişkidir: Bir faaliyetin tamamlanması için başka bir faaliyetin başlamış olması gerekir.

> **Ders sonrası not:** Asistan SS için "her iki faaliyetin de başlaması için diğerinin de başlamış olmasını istiyoruz" dedi. Bu ifade iki yönlü gibi anlaşılabilir. İlişki tek yönlüdür: Ardıl faaliyet, öncül faaliyet başlamadan başlayamaz. Verdiği kodlama ve birim test örneği de bu anlamdadır.

> **Ek bilgi (derste anlatılmadı):** SF ilişkisine kısa notta yer alan örnek şudur: Yeni sistem devreye girmeden eski sistemin desteği sonlanamaz. Burada öncül, yeni sistemin devreye girmesi; ardıl, eski sistemin desteğidir.

### 12.3 Kritik Yol

Her işe süre ayrıldığında projenin toplam süresi oluşur. Bazı işlerdeki bir ya da iki günlük gecikme doğrudan toplam proje süresine yansır. Bu işlere **kritik faaliyet**, oluşturdukları yola **kritik yol** denir. MS Project'te kritik işler istenirse kırmızı, diğerleri mavi gösterilir; varsayılan görünümde hepsi mavidir. Bir kritik işin gecikmesi diğerini de etkiler ve bir gecikme silsilesi oluşur.

### 12.4 Bolluk (Slack)

Kritik olmayan bir faaliyet, bitmesi beklenen başka bir paralel iş tamamlanana kadar uzayabilir. Bu uzayabileceği miktara **bolluk** (slack) denir: Kritik yol üzerinde bulunmayan bir faaliyetin zamanlamasında yapılabilecek esnek kayma miktarı. MS Project bolluğu gri bir çizgiyle gösterir.

### 12.5 Kilometre Taşı (Milestone)

**Kilometre taşı**, proje adımlarında önemli bir noktayı ya da tarihi gösterir ve **sıfır gün** olarak girilir. Uzun süren bir iş değil, genellikle bir iş grubunun bitiminde yapılan toplantı, değerlendirme, o zamana kadar yapılan işlerin gözden geçirilmesi gibi bir olaydır. Şemada içi dolu bir elmasla gösterilir.

### 12.6 Kaynak Ataması

Kaynaklar arasında başta insan gücü olmak üzere ekipman, cihaz ve parasal kalemler sayılabilir. Kaynak atama ekranına kaynağın adı, tipi, kısaltması ve maliyeti (örneğin çalışanın haftalık ya da saatlik ücreti) yazılır. Böylece bir faaliyetin ya da bir kişinin proje boyunca ne kadar maliyet getireceği otomatik çıkarılır. Asistan, proje başarısının kaynakların doğru ve etkin kullanılmasıyla doğrudan ilişkili olduğunu, kaynak sınırlıysa planlamanın çok daha iyi yapılması gerektiğini söyledi.

## 13. PERT Diyagramı

**PERT** diyagramı (Program Evaluation and Review Technique) graf temelli bir gösterimdir. Gantt'ta işler merdiven biçiminde, paralel çubuklar olarak görünür. PERT'te ise her faaliyet bir düğüm, aralarındaki ilişkiler okla gösterilen kenarlardır. Gantt'ta az önce satır satır yazılan her faaliyet burada bir düğüme dönüşür. Düğümlerde başlangıç, bitiş, atanan kaynak ve ID bilgileri görülebilir.

Asistana göre karmaşık ilişkilerin olduğu yerde Gantt yetersiz kalabilir. PERT, hangi işin hangisinden sonra geldiğini ve dolaylı bağlantıları daha ayrıntılı gösterir.

> **Ders sonrası not:** Asistan kısaltmanın sonunu "Technics" diye okudu; doğrusu "Technique"tir.

## 14. MS Project Uygulaması: Bitirme Projesi Planı

Asistan, öğrencilerin ileride alacağı bilgisayar ya da bitirme projesi dersi için bir plan kurdu. Proje iki öğrenci tarafından yapılıyor; kaynak adları örnek olarak "Ali" ve "Veli" verilmişti.

### 14.1 Hazırlık

Project açıldığında solda satırların yazılacağı tablo, sağda Gantt şeması bulunur. Yazmaya başlanınca başlangıç olarak bugünün tarihi atanır. Şemadaki gölgeli hafta sonları, çalışma günü olmayan günlerdir. Format menüsünden **Project Summary Task** işaretlenerek özet satırı açılır.

> **Ders sonrası not:** Asistan, 10 günlük bir işin hafta sonuyla birlikte 12 günlük bir aralığı kaplayacağını söyledi. Bu, iş pazartesi başlarsa doğrudur. Plan 14 Mart 2023 salı günü başlatıldığında 10 iş günü 14 takvim gününe yayılır.

### 14.2 Literatür Taraması

İlk ana başlık literatür taramasıdır. Altına, arama yapılacak veri tabanları için dört iş yazılır: IEEE, Elsevier, SpringerLink ve Google Scholar. Üçüne 3 gün, Scholar'a 4 gün verilir. İşler seçilip Görev menüsünden girintilenince literatür taraması üst başlık olur.

İlişki verilmediği sürece bütün işler aynı günde görünür. Ali IEEE'yi bitirince SpringerLink'e, Veli Elsevier'i bitirince Scholar'a geçecektir. Bu nedenle SpringerLink'in öncül hücresine 2, Scholar'ınkine 3 yazılır. Yalnız ID yazmak yeterlidir, çünkü varsayılan ilişki FS'dir.

İşin üzerine çift tıklanınca Task Information ekranı açılır. **Predecessors** sekmesinde iş adı listeden seçilebilir ve ilişki tipi buradan da değiştirilebilir. FS dışındaki ilişkilerde öncül hücresine tip de yazılır, örneğin `2SS`.

Bu başlığın sonunda bir danışman toplantısı yapılır. Bu bir kilometre taşıdır, süresi 0 gündür. Toplantı iki işin de bitmesini bekler, ama iş biter bitmez aynı gün yapılması mantıksız olur. Bu yüzden en son biten işe (Veli'nin Scholar işi) bir gün gecikme eklenir. Yazımda öncüller noktalı virgülle ayrılır, gecikme öncülün yanına eklenir: `4;5+1 gün`. Sonra satırlar seçilip Auto Schedule yapılır; böylece tarihler öncüllere göre hesaplanır. Asistanın ekranında son iş ayın 22'sinde bitti ve toplantı ertesi güne yerleşti. Ardından **Insert Column** ile WBS sütunu eklendi.

### 14.3 Veri Seti Oluşturma

İkinci ana başlık veri seti oluşturmadır; girintisi geri alınarak ana işe dönüştürülür. Bir görüntü işleme projesi varsayılır. Görüntü toplama 5 gün, görüntü etiketleme 8 gündür.

Toplamanın öncülü 6 numaralı danışman toplantısıdır. Etiketleme ise toplamayla birlikte başlamalıdır, bu yüzden SS ilişkisi kurulur: `8SS`. Asistan bu yazımı hatırlamayanların aynı ayarı Task Information ekranından seçebileceğini gösterdi.

### 14.4 Ara Rapor Yazımı

Üçüncü ana başlık ara rapordur. Alt işleri şunlardır: özet ve giriş yazımı (4 gün), literatür ve metot yazımı (3 gün), rapor teslimi (kilometre taşı, 0 gün). İki yazım işi Ali ve Veli arasında paylaştırılır, kaynaklar farklı olduğu için eş zamanlı yürür.

Yazım, etiketleme bittikten bir gün sonra başlar: `9+1 gün`. Rapor teslimi iki yazım işinin de bitmesini bekler: `11;12`.

### 14.5 Uygulama

Son ana iş uygulamadır: 20 gün, öncülü rapor teslimi.

### 14.6 Planın Hesabı

Asistan toplam süreyi 41 gün ve bitişi 9 Mayıs olarak ekranda gösterdi. Aşağıdaki tablo, verilen süre ve öncüllerden, başlangıç 14 Mart 2023 salı alınarak ve hafta sonları çalışılmadan yeniden hesaplanmıştır (ara adım eklendi). Tablonun son satırları ve "son iş 22'sinde bitti" sözü asistanın ekranıyla uyuşur.

| ID | Faaliyet | Süre | Öncül | Başlangıç | Bitiş | Bolluk |
| :---: | :--- | :---: | :---: | :---: | :---: | :---: |
| 2 | IEEE (Ali) | 3 g | | 14 Mart | 16 Mart | 2 g |
| 3 | Elsevier (Veli) | 3 g | | 14 Mart | 16 Mart | 0 |
| 4 | SpringerLink (Ali) | 3 g | 2 | 17 Mart | 21 Mart | 2 g |
| 5 | Google Scholar (Veli) | 4 g | 3 | 17 Mart | 22 Mart | 0 |
| 6 | Danışman toplantısı | 0 g | 4;5+1 g | 23 Mart | 23 Mart | 0 |
| 8 | Görüntü toplama | 5 g | 6 | 24 Mart | 30 Mart | bkz. metin |
| 9 | Görüntü etiketleme | 8 g | 8SS | 24 Mart | 4 Nisan | 0 |
| 11 | Özet ve giriş | 4 g | 9+1 g | 6 Nisan | 11 Nisan | 0 |
| 12 | Literatür ve metot | 3 g | 9+1 g | 6 Nisan | 10 Nisan | 1 g |
| 13 | Rapor teslimi | 0 g | 11;12 | 11 Nisan | 11 Nisan | 0 |
| 14 | Uygulama | 20 g | 13 | 12 Nisan | 9 Mayıs | 0 |

ID 1, 7 ve 10 özet satırlarıdır (literatür taraması, veri seti, ara rapor). Toplam süre, kritik zincirin süreleriyle doğrulanır (ara adım eklendi):

$$3 + 4 + 1 + 0 + 8 + 1 + 4 + 0 + 20 = 41 \text{ gün}$$

Sıra şöyledir: Elsevier, Scholar, 1 gün gecikme, danışman toplantısı, etiketleme, 1 gün gecikme, özet ve giriş, rapor teslimi, uygulama. Görüntü toplama, etiketlemenin başlangıcına SS ile bağlı olduğu için başlangıcı kaçamaz (başlangıç bolluğu 0). Ama planda bitişine bağlı başka bir iş olmadığından 5 günlük süresi toplam 41 günü belirlemez.

Format menüsünden **kritik görevler** işaretlenince kritik işler kırmızı görünür. Asistan, Veli'nin 4 günlük Scholar işi yüzünden Ali'nin işinin kritik yol üzerinde olmadığını, Ali'nin bir bolluğu bulunduğunu gösterdi. Bu göstergeler tercihe göre menüden açılıp kapatılabilir.

> **Ders sonrası not:** Asistan kritik işler için "bir nevi en uzun süreli işler" dedi. Belirleyici olan tek tek işin süresi değil, gecikmeler dahil başlangıçtan bitişe en uzun süren zincirdir. Örneğin yukarıdaki tabloda 3 günlük Elsevier kritiktir, 3 günlük SpringerLink değildir.

<!-- BELİRSİZ: Ekranda gösterilen kritik işler ve bolluk miktarları altyazıda tek tek söylenmiyor. Tablodaki bolluk değerleri verilen öncüllerden hesaplanmıştır; MS Project'in görüntü toplama için ne gösterdiği altyazıdan anlaşılmıyor. -->

## 15. Takvim, Kaynak Maliyeti ve Ağ Diyagramı

### 15.1 Çalışma Zamanını Değiştirmek

Öğrencinin bitirme projesinde hafta sonu da çalışacağı varsayılırsa cumartesi ve pazar iş gününe dahil edilebilir. Bunun için **Change Working Time** ekranında **Work Weeks** sekmesine gelinir ve satıra çift tıklanır. Varsayılan saatler 08:00-12:00 ve 13:00-17:00'dir, araya bir saatlik boşluk girer. Burada saatler değiştirilebilir, bir gün tatil yapılabilir. Asistan cumartesi ve pazarı seçip saatleri elle (8'den 5'e) girdi.

Onaylandıktan sonra şemadaki gölgeli alanlar kalkar. Süre yine 41 gündür, çünkü iş miktarı değişmemiştir; değişen, bu sürenin takvime yayılışıdır. Bitiş Mayıs'tan Nisan'a gelir. 14 Mart başlangıcı ve haftanın 7 günü çalışma ile son gün 23 Nisan 2023 olur (ara adım eklendi).

> **Ders sonrası not:** Asistan saatleri okurken "13-15" dedi ve hemen "13-17" diye düzeltti; doğrusu 13:00-17:00'dir.

### 15.2 Kaynak Sayfası

Kaynaklar **Resource Name** sütununa yazılınca **Resource Sheet** görünümünde listelenir. Burada her çalışanın saatlik ücreti girilir. Asistan birine az birine çok yazdı. Gantt görünümüne dönüldüğünde her işin maliyeti ve toplam maliyet, kişilerin saat ücretleri üzerinden otomatik hesaplanır. Aynı biçimde cihazlar ve alınan hizmetler de kaynak olarak eklenip maliyetleri izlenebilir.

<!-- BELİRSİZ: Girilen saatlik ücretler ve çıkan maliyetler altyazıda söylenmiyor (01:54:47-01:55:32). -->

### 15.3 Ağ Diyagramı

Gantt Chart görünümünün seçildiği aynı listeden **Network Diagram** seçilince PERT diyagramı gelir. Her iş bir düğümdür, alt kırılımlar ve bağlantılar görülür. Kritik işler kırmızı, kritik olmayanlar açık mavi, kilometre taşları köşeli düğüm olarak gösterilir. Yakınlaştırınca düğümdeki iş, başlangıç ve bitiş tarihleri okunur. Aynı listeden Gantt görünümüne dönülür.

## Dersin Toparlaması

Bu derste bilgi sistemi geliştirmenin ilk iki aşaması görüldü. Ön inceleme "bu sisteme ihtiyaç var mı, yapabilir miyiz?" sorusuna kabaca cevap verir ve kapsam tanımlama belgesiyle biter. Fizibilite çalışması aynı soruyu teknik, zaman, sosyal, yönetim, yasal ve ekonomik açılardan ayrıntılandırır, her alternatifi fizibilite matrisinde ağırlıklı puanlarla karşılaştırır ve fizibilite raporuyla biter. Ekonomik fizibilitede bütün sonuçlar para cinsinde toplanır ve bugünkü değer, iç verim oranı, başa baş noktası ve geri ödeme süresi yöntemleriyle değerlendirilir. Zaman fizibilitesinde ise Gantt şeması, faaliyet ilişkileri, kritik yol, bolluk, kilometre taşı, kaynak ataması ve PERT diyagramı MS Project üzerinde bir bitirme projesi planıyla uygulandı.

Hoca, gelecek hafta gereksinim analizi aşamasına geçileceğini söyledi. İlk aşama olan iş analizinin ne olduğu, bilginin nasıl toplandığı, bunun iş analizi dokümanı ve kullanım senaryolarıyla fonksiyonel ya da nesneye dayalı çözümlemeye destek olacak biçimde nasıl yapıldığı ele alınacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
