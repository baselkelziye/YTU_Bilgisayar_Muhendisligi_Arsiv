# Ders 4 Genişletilmiş Notu: IEEE 802 Projesi, Ethernet, Token Bus, Token Ring ve FDDI

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Neden Bu Kadar Ayrıntılı Konu Öğreniyoruz
- 2. Dersin Planı ve IEEE 802 Projesi
- 3. Fiziksel Katman ve MAC Alt Katmanı
- 4. LLC Alt Katmanı ve Servis Tipleri
- 5. IEEE 802.3 Ethernet: Tarihçe ve Gelişim
- 6. Aloha ve Slotted Aloha
- 7. CSMA ve Persistent Algoritmalar
- 8. CSMA/CD
- 9. IEEE 802.3 Çerçeve Yapısı ve Fiziksel Katman
- 10. Anahtarlamalı Ethernet, Diğer Standartlar, Metro Ethernet ve PoE
- 11. Gerçek Zamanlı Sistemler ve IEEE 802.4 Token Bus
- 12. IEEE 802.5 Token Ring
- 13. FDDI
- Örnek Sorular

## 1. Neden Bu Kadar Ayrıntılı Konu Öğreniyoruz

Ders başlamadan önce bir öğrenci, işletim sistemlerindeki süreç ve iş parçacıkları ya da veri iletişimindeki CRC gibi ayrıntılı konuların nerede kullanılacağını sordu. Hocanın cevabının akademik özü şuydu: bilgisayar mühendisi sıradan bir programcı ya da sistem yöneticisi değildir. Bu konular, hazır teknolojileri kullanmak için değil, onları tasarlayabilecek hâle gelmek için anlatılır.

Hoca örnek olarak işletim sistemlerindeki zamanlama (scheduling) algoritmalarını verdi. Linux ve Windows bu algoritmaları birebir kullanır. Bir işletim sistemini başka bir donanıma taşıyan mühendis, işin karakteristiğini analiz edip uygun zamanlama algoritmasını seçebilir ya da ihtiyacına göre kendi algoritmasını yazabilir. Veri iletişiminde de aynı durum vardır: o gün konuşulacak 802 projesinde bir yöntemin farklı teknolojilerde nasıl kullanıldığı görülecektir. Kendini yalnız uygulama geliştirmekle sınırlayan biri için bile alttaki yapıyı bilmek, bir şeyin neden yavaş ya da hızlı olduğunu anlayıp doğru tasarım seçimini yapmayı sağlar. C ile yazılan kod bile işletim sisteminde öğrenilen mantık gözetilerek yazılmalıdır.

## 2. Dersin Planı ve IEEE 802 Projesi

Dersin konusu yerel alan ağlarıydı. Ethernet, Token Bus, Token Ring ve ardından kablosuz ağlar konuşulacak, bunlar üzerinden paylaşılan bir ortama erişim (Medium Access Control) yöntemleri incelenecekti.

İçerik slaytında "IEEE 802.11 Projesi" ve altında 802.11.1 ... 802.11.5 yazıyordu (ekrandan, 00:35:00). Hoca bunun yanlış olduğunu, doğrusunun 802 projesi ve 802.1, 802.2, 802.3, 802.4, 802.5 olduğunu, 802.11'in başka bir şey olduğunu söyledi.

802 projesi IEEE'nin başlattığı bir projedir. Amacı farklı ağların bir arada çalışabilmesidir. Ethernet'in ortaya çıktığı dönemde Token Ring ve Token Bus da mevcuttu ve birbirine rakipti. Birden fazla farklı teknoloji aynı ortamda bulununca bunları bir arada kullandırma ihtiyacı doğar. Hoca burada "Ethernet" deyince bugün kullanılan Ethernet'in düşünülmemesi gerektiğini, onun aslında Fast Ethernet ve sonrası olduğunu belirtti.

OSI modelinde farklı teknolojileri birleştirme işi büyük ölçüde ağ katmanında yapılır; IP her şeyi bir arada tutan kısımdır. 802 modelinde ise fiziksel katman aynen korunmuş, veri bağı katmanı ikiye bölünmüştür: Media Access Control (MAC) ve Logical Link Control (LLC). Slayttaki yapı şöyledir (ekrandan, 00:40:00):

```text
+--------------------------------------------+   +-----------------------------+
|             Diğer Katmanlar                |   | Diğer Katmanlar             |
+--------------------------------------------+   +-----------------------------+
|           802.1 Internetworking            |   | Ağ Katmanı (Network Layer)  |
+--------------------------------------------+   +-----------------------------+
|                 802.2 LLC                  |   |                             |
+--------------+--------------+--------------+   | Veri Bağı Katmanı           |
| 802.3        | 802.4        | 802.5        |   | (Data Link Layer)           |
| CSMA/CD      | Token Bus    | Token Ring   |   |                             |
+--------------+--------------+--------------+   +-----------------------------+
| 802.3        | 802.4        | 802.5        |   | Fiziksel Katman             |
| Physical     | Physical     | Physical     |   | (Physical Layer)            |
+--------------+--------------+--------------+   +-----------------------------+
```

Token Bus, Token Ring ve CSMA/CD (o dönemin Ethernet'i) için hem fiziksel katmanda hem MAC katmanında ayrı tanımlar vardır, ama LLC ortak bir katman olarak gerçeklenmiştir. Bunun üzerine ağlar arası haberleşme (internetworking) kurulabilir. 802'nin hedefi de budur.

## 3. Fiziksel Katman ve MAC Alt Katmanı

### 3.1 Fiziksel katman

Fiziksel katman, gönderilecek sinyalin iletim ortamından nasıl yollanacağını belirler. Örneksel (analog) bir işaret mi kullanılacak, kullanılacaksa faz, genlik ya da frekans üzerinden mi modülasyon yapılacak, yoksa daha önce konuşulan sayısal kodlama teknikleri mi kullanılacak; neyin neye karşılık geleceği burada belirlenir. Dağıtık sistemlerde zaman eşzamanlaması her zaman önemli ve kolay çözülemeyen bir problemdir. Ortak bir saat dışında bunun için kullanılan bir yapı varsa (ör. preamble) onu gerçekleştirmek de fiziksel katmanın görevidir. Bunun yanında bilginin ortam üzerinden gönderilmesi ve alınması da bu katmandadır.

### 3.2 MAC alt katmanı

Slayttaki tanım (ekrandan, 00:45:00): paylaşılan veri iletim ortamının nasıl kullanılacağı ile ilgilenen işlevsel yapı MAC alt katmanı içinde toplanmıştır:

- an uyumluluğunun sağlanması (synch),
- bilginin bir uçtan diğerine aktarılması için kullanılan fiziksel adresleme,
- hata kontrolünün gerçekleştirilmesi.

Yerel alan ağlarında bağlantı çok noktalıdır (multipoint) ve ortam paylaşımlıdır. Bu yüzden ortama kimin ne zaman erişeceğinin belirlenmesi gerekir. Geniş alan ağlarında (WAN) bu iş daha kolaydır, çünkü bağlantı doğası gereği noktadan noktayadır: iki uç vardır ve herhangi bir anda haberleşebilecek taraf sayısı sınırlıdır.

Hoca erişim sorununu sınıftaki konuşmaya benzetti. Hoca konuşurken bir öğrenci hocanın konuşup konuşmadığına bakmadan söze girerse ikisinin sesi üst üste biner, diğerleri için anlaşılmaz bir karışıklık (çarpışma) olur. İki taraf bunu fark edip durur, sonra biri yeniden başlar. Bu, Aloha'nın gündelik hayattaki karşılığı gibidir. Daha düzgün bir yol, konuşanın arada bir durakladığı anı beklemektir; böylece çarpışma olmaz. Ama bu bir an uyumluluğu gerektirir. Zamanı slotlara bölüp slotlar üzerinden haberleşmek (slotted Aloha) buna örnektir.

Hoca gerçek bir örnek olarak araçlar arası haberleşmeyi (inter-vehicle communication) anlattı: eşzamanlama GPS sinyaliyle her saniye başında yapılır, ortak kanaldan kimin konuşmak istediği bilgisi aktarılır, sonra kanallar arasında geçiş yapılır. Hoca bu aralığın 50 ms olduğunu düşündüğünü, emin olmadığını belirtti. GPS ile bile kaymalar (drift) olur. Böyle bir dış eşzamanlama kaynağı yoksa eşzamanlama mantıksal seviyede, yani mesajlaşmayla yapılmak zorundadır. Bu yüzden MAC dolaylı olarak bundan da sorumludur.

<!-- BELİRSİZ: Araçlar arası haberleşmedeki kanal geçiş aralığını hoca "50 milisaniye olmalı sanki" diye söyledi, kesin değil. -->

MAC adreslemeden de sorumludur. Bugünkü Ethernet'te ortama erişmek için bir MAC adresi gerekir. Çerçeve oluşturulup gönderildiğinde kaynak adres alanına kendi MAC adresiniz yazılır, ama hedefin adresinin de bilinmesi gerekir. Adres bilinmiyorsa hedefi bulmaya çalışmak da MAC katmanının işlerinden biridir.

## 4. LLC Alt Katmanı ve Servis Tipleri

### 4.1 Neden iki ayrı katman

Slayttaki gerekçe (ekrandan, 00:50:00): alışılagelmiş ağ bağlantı katmanından farklı olarak LAN'da iki ayrı katman olarak değerlendirilmesinin iki temel nedeni vardır:

- 2. katman fonksiyonları arasında paylaşımlı erişimli ortamlara (shared access medium) erişimin yönetimini sağlayacak yapının bulunmaması,
- aynı LLC için birden fazla MAC seçeneği sağlanabilmesi ile alternatif üretilebilmesi.

MAC fiziksel ortama erişimle ilgili olduğu için alt katman olarak görünür. LLC ise hattı mantıksal seviyede ele alır: oluşturulan çerçevelerin hatalı olup olmadığını, iki taraf arasındaki akışın sorunsuz yürümesini sağlar.

### 4.2 Akış kontrolü ve donanım soyutlaması

Hoca akış kontrolünü şöyle açıkladı: çerçeve gelmesinde bir sorun yoktur, ama siz bir çerçeveyi işleyemeden bir yenisi, onu da işleyemeden bir başkası gelir. Fiziksel olarak iki taraf aynı hızda (10 ya da 100 Mbps) bağlı olabilir, ama alıcının tek işi ağdan gelen paketi işlemek değildir; işlemci gücü ya da bellek kapasitesi buna yetmeyebilir. Ayrıca hat hızında çalışabilmek için veri bağı katmanı çoğu zaman doğrudan ağ arayüz kartının üzerinde gerçeklenir. Karşı tarafta böyle gerçeklenmiş ve hat hızında çalışan bir yapı, sizin tarafta yazılımla yavaş çalışan bir yapı varsa akış sorunu doğar. Bunu çözmek LLC'nin işidir.

LLC ayrıca bir donanım soyutlaması sağlar. Alt katmanlardaki her teknolojiye karşılık gelen ve aynı işi yapan bir fonksiyon ailesi üstte tanımlanır. Akış kontrolüyle ilgili bir X fonksiyonu çağrıldığında, altta hangi teknoloji varsa ona uygun fonksiyon çalışır. Böylece aynı LLC ile birden fazla farklı MAC katmanı kullanılabilir.

### 4.3 Servis tipleri

Hoca, aynı servis tiplerinin ağ teknolojileri dersinde ağ ve taşıma katmanında da karşılarına çıkacağını söyledi. Veri aktarımı bağlantılı (connection-oriented) ya da bağlantısız (connectionless) olabilir. Bağlantısız servis, alındı bilgisinin (acknowledge) olup olmamasına göre ikiye ayrılır. Alındı bilgisi, karşı tarafın bir bilgiyi aldığını geri bildirmesidir ve bağlantılı olmadan da sağlanabilir. Böylece üç servis vardır (ekrandan, 00:55:00):

- Alındı bilgisi yollanmayan bağlantısız servis (Un-ack connectionless service): akış kontrolünün ve hata kontrolünün yapılmadığı basit datagram hizmetidir.
- Bağlantılı servis (Connection oriented service): bağlantının iki taraf veri alışverişine başlamadan önce kurulmuş olması gereklidir; iletim sırasında akış ve veri kontrolü yapılabilir.
- Alındı bilgisi yollanan bağlantısız servis (Ack connectionless service): bir ön bağlantı kurma aşaması olmaksızın alındı bilgisi yollanan datagram servisidir.

### 4.4 Bugün neden onaysız bağlantısız servis tercih ediliyor

Hoca bağlantılı servisin bugün veri bağı katmanında tercih edilmediğini, ama yaygın tercihin her zaman en doğru ya da en iyi seçim olmadığını vurguladı.

İnternet bağlantımız çoğunlukla servis sağlayıcılar üzerinden döner ve servis sağlayıcı en az eforla en çok kazancı ister. Ağ cihazları genellikle üçüncü seviyeye kadar gerçeklenir. Bağlantılı servis dördüncü seviyede (taşıma katmanında) sağlanır. Bağlantılı servis, bir cihazın üzerinden geçen her akış için bilgi tutması ve bir sorun anında bu bilginin kurtarılması demektir; bu da ek bellek ve ek işlemci kullanımı, yani maliyet demektir. Bu yükün altına kimse girmek istemez; bu yüzden güvenilirlik (hoca "güvenlik değil, güvenilirlik" diye özellikle ayırdı) mekanizmalarını üst katmanda sağlamak çoğu zaman daha az maliyetlidir.

> **Hocanın vurgusu:** Bugün tercih ettiğimiz yapı her zaman en doğrusu değildir; uygulamaya göre değişir. Savunma sanayiyle ilgili bir teknolojide ya da bir denizaltıda veri bağı katmanında bile onaylı bağlantısız ya da bağlantılı servis tercih edilebilir.

### 4.5 LLC PDU'su

LLC katmanındaki veri birimine protokol veri birimi (PDU) denir. Dört temel alanı vardır: hedef adres, kaynak adres, kontrol alanı ve bilgi alanı. Bilgi alanı doğrudan kullanıcı verisidir; boyutu kullanılan teknolojiye (802.3, 802.4, 802.5) göre, hatta protokolün kendi içinde de değişebilir. Kontrol alanı, geçen hafta HDLC'de I, S ve U çerçevelerini ayırt etmek için kullanılan yapıya benzer bir işlev görür: aktarılan verinin neyle ilgili olduğunu gösterir.

## 5. IEEE 802.3 Ethernet: Tarihçe ve Gelişim

### 5.1 Tarihçe

Slayttaki bilgiler (ekrandan, 01:00:00):

- 1972'de Robert Metcalfe ve Xerox PARC araştırmacıları Ethernet'i Xerox Alto için geliştirmişlerdir.
- Bu deneysel çalışma 1973'te Alto Aloha Network olarak adlandırılmıştır.
- 1979'da Robert Metcalfe, Digital, Intel ve Xerox'u (DIX) ortak çalışmaya ve yeni Ethernet yapısını kurmaya ikna etti.
- Aynı yıl Metcalfe tarafından ismi "Ethernet" olarak değiştirilerek sistemin sadece Alto bilgisayarına has olmadığı ve her bilgisayar sisteminde uygulanabileceğine vurgu yapılmıştır.

Hoca, Xerox Alto'nun grafik arayüzlü bir sistem olduğunu ve bu sistemleri birbirine bağlamak için ağın kurulduğunu anlattı. İlk adının Alto Aloha Network olmasının nedeni, Metcalfe'ın doktora çalışmasının Aloha üzerine olması ve ağı kurarken Aloha'dan doğrudan yararlanmasıdır.

### 5.2 Kablolama ve hız

İlk hâlinde kalın koaksiyel kablo kullanılır ve 10Base-5 ile 10 Mbps'a ulaşılır. Hoca ilk deneysel hâlin hızının 10 Mbps olmadığını, iki küsur megabit olduğunu (2,8 ya da 2,94 civarı, kesin hatırlamadığını) söyledi; standartlaştıkça 10 Mbps'a çıkmıştır. Sonra ince koaksiyel (10Base-2), ardından bükümlü çift kablonun (CAT kablolar) kullanılmaya başlandığı 10Base-T ve çok modlu ya da tek modlu fiberle kullanılan 10Base-F gelir.

<!-- BELİRSİZ: Hoca Alto Aloha Network'ün ilk hızını "2.8 mi, 2.38 mi, 2.83 mü" diye kararsız söyledi; kaynaklarda büyük olasılıkla 2,94 Mbps'tır. -->

### 5.3 MAC alt katmanının gelişimi

Önce tek bir yol (bus) yapısında Ethernet vardır. Sonra yolun kablolamasını değiştiren hub'lar çıkar; mantıksal olarak hâlâ yol vardır. Bir adım sonra anahtarlamalı (switched) Ethernet gelir: herkesin birbirine bağlı olduğu yol yapısı, aktif cihazla bilgisayar arasındaki her bağlantının ayrı bir segment olduğu yapıya çevrilir; bağlantılar birbirinden bağımsız hâle gelir ama ağ anlamında hâlâ bağlıdır.

Sonra Fast Ethernet çıkar. Hoca bunu "her iş kendisine ayrılan süreyi dolduracak kadar genişler" yasasıyla anlattı: 10 Mbps ilk çıktığında efsanevi bir değerdi (56K modemden birkaç megabitlik hatta geçmek gibi), ama zamanla veri aktarım ihtiyacı bu kapasiteyi aştı. Çalışma grubu yeni bir standart yaratmak yerine Ethernet yapısını koruyup hızı artırmaya karar verdi.

> **Ders sonrası not:** Hoca bu yasayı "Robertson'un kuramı" diye andı. Bu ilke büyük olasılıkla Parkinson Yasası'dır ("iş, kendisine ayrılan süreyi dolduracak kadar genişler").

Bu gelişmeler sırasında half-duplex'ten full-duplex'e geçilmiş, paylaşımlı ortam segmentlere bölünmüş, erişim yapısı ve buna uygun protokoller değişmiştir. Slayttaki özet (ekrandan, 01:05:00):

- Ethernet'in MAC alt katmanında kullanılan teknik zaman içinde kullanım oranını mümkün olduğunca arttıracak şekilde değişmiş ve gelişmiştir.
  - Orijinal Ethernet MAC katmanı half-duplex olarak çalışacak şekilde tasarlanmıştır.
  - Kullanılan iletim ortamına bağlı olarak full-duplex çalışmaya da imkân vermektedir.
  - Aloha, Slotted Aloha, CSMA ve CSMA/CD.

## 6. Aloha ve Slotted Aloha

### 6.1 Aloha

Aloha, Hawaii Üniversitesi'nde ortaya atılmış bir protokoldür. Ana karada bir bilgisayar, diğer adalarda terminaller (klavye ve ekran) vardır. Adalarda telefon ağı yoktur, yalnız telsiz haberleşmesi vardır. Önerilen protokol şudur: verisi olan doğrudan göndersin; veri ana karadaki alıcıya ulaştıysa alıcı geri göndersin, böylece gönderen verinin doğru gittiğini anlasın.

> **Ders sonrası not:** Altyazıda "Norman Abrams" geçiyor; Aloha'yı geliştiren kişi büyük olasılıkla Norman Abramson'dır.

Sorun şudur: siz veri gönderirken başka biri de doğrudan gönderirse iki paket çakışır (collision) ve ikisi de kaybolur. Bu yüzden Aloha trafik yoğunluğu düşük ağlar için uygundur. Hoca örnek verdi: 10 terminal her biri 10 saniyede bir paket gönderiyorsa (ağda saniyede bir paket) büyük olasılıkla düzgün çalışılır; ama her biri saniyede 5 paket göndermeye çalışırsa çarpışma olasılığı çok artar.

Çarpışma, gönderilen bilginin onayının gelmemesiyle anlaşılır ve bu bir zamanlayıcı (timer) ile kontrol edilir. Çarpışma olduğuna karar verilince bir süre beklenip yeniden gönderilir. Aloha ile elde edilen kullanım oranı (bant genişliği kullanımı) yaklaşık %18'dir.

### 6.2 Slotted Aloha

Slotted Aloha kullanım oranını yaklaşık iki katına, %37'ye çıkarır. Slayttaki tanım (ekrandan, 01:10:00):

- Veri bozulması problemini kısmen de olsa azaltabilmek üzere iletim kanalı her biri çerçeve iletim süresine eşit sürelerde zaman dilimlerine (slot) bölünmüştür.
  - ortak bir zamanlama mekanizması,
  - yollayacak verisi olan istasyon zaman dilimlerinin (slot) başladığı anlarda iletime geçebilir,
  - slot boyu belirlenirken çerçevenin iletim süresine ($T_{frame}$) bir miktar ($\Delta T$) ekleme yapılır.
- Zaman aralıklarına bağlı kalınarak yapılan bu iletim ile kullanım oranı %37'leri bulmuştur.

Hoca şöyle örnekledi: her saniyede yeni bir slot başlıyor olsun. Birinci saniyenin başında veriniz yoktu, 1,2. saniyede veriniz hazır oldu. Hemen göndermez, ikinci saniyenin başını beklersiniz. Herhangi bir anda iletime geçilmediği için iletim başladıktan sonra o slotta araya girebilecek, ortam için yarışacak istasyon sayısı sınırlanmış olur. Birden fazla istasyon aynı slot başında hazırsa yine çarpışma olur, ama çakışma olasılığı azaldığı için performans artar. Yine de %37 yeterli bir kapasite değildir, daha da artırılmalıdır.

> **Ders sonrası not:** Bu değerler teorik üst sınırlardır: Aloha için $1/(2e) \approx 0{,}184$, Slotted Aloha için $1/e \approx 0{,}368$ (python ile kontrol edildi).

## 7. CSMA ve Persistent Algoritmalar

### 7.1 Taşıyıcı algılama

Aloha ve Slotted Aloha'da hattı dinleme özelliği yoktur; yalnız verici varmış gibi davranılır. CSMA'da (Carrier Sense Multiple Access) göndermeden önce hattın boş olup olmadığı kontrol edilir. Hat boş değilse beklenir; ne kadar ve nasıl bekleneceğini farklı algoritmalar belirler. Hat boşsa bilgi gönderilir. Slayttaki tanım (ekrandan, 01:20:00):

- Veri yollayacak olan istasyonun öncelikle hattın boş olup olmadığını anlayıp ona göre veri iletişimine geçmenin daha etkin bir sonuç üreteceğini göstermiştir.
- Veri yollamak isteyen birden fazla istasyonun aynı anda hattı boş olarak algılayarak iletime geçmesi de mümkündür.
- Veri bozulması sonucu iletinin yerine ulaşamaması ve bunun doğal bir sonucu olarak alındı bilgisinin dönmemesi ile gönderen taraf veri çerçevesinin bir nedenden ötürü hedefine ulaşamadığına karar verecektir.

Birden fazla istasyonun hattı boş görmesinin nedeni yayılma gecikmesidir (propagation delay). Kablolu da olsa kablosuz da olsa sinyalin bir uçtan diğerine gitmesi zaman alır. Siz iletime başladığınız anda sizden uzaktaki istasyonlar bunu hemen algılayamaz; bu süre geçene kadar hattı boş sanıp onlar da iletime başlayabilir.

### 7.2 Hat meşgulse ne yapılır

Hat dinlenip meşgul olduğuna karar verildikten sonra yapılacaklar üç temel algoritmayla tanımlanır: non-persistent, 1-persistent ve p-persistent. Hoca üçünün aslında birbiriyle ilişkili olduğunu, hepsinin p-persistent'ın özel durumları gibi görülebileceğini söyledi.

**Non-persistent CSMA** (ekrandan, 01:30:00):

- İletime geçmek isteyen istasyon öncelikle hattı dinler ve aşağıdaki adımları gerçekleştirir:
  - 1) İletim ortamı müsait ise aktarıma geç, aksi hâlde ikinci adıma geç.
  - 2) İletim ortamı meşgul ise (olasılık dağılımına bağlı olarak) biraz bekle ve birinci adıma geç.
- Rastgele bekleme süreleri doğal olarak veri bozulması (collision) problemini azaltacaktır.
  - Rastgele bekleme süresi hattın kullanılamamasına ve bir kapasite kaybına neden olur.

Rastgele bekleme, farklı düğümlerin farklı süreler beklemesini ve böylece bekleyenlerin zamana dağılmasını sağlar; çarpışma azalır, performans artar. Ama bekleme gereğinden uzunsa kapasite kaybına yol açar. Uygun bekleme hattaki trafik yoğunluğuyla ilgilidir: düğüm sayısı çok olsa bile trafik üretme sıklığı düşükse, zaten çarpışma olmayacak bir yerde boşuna beklenmiş olur.

**1-persistent CSMA:** hat müsaitse iletime geçilir. Meşgulse rastgele bekleme yapılmaz, hat dinlenmeye devam edilir ve hattın boşaldığı duyulduğu anda iletime geçilir. Daha etkin gibi görünse de sorun şudur: hat meşgulken konuşmak isteyip dinlemeye başlamış birden fazla düğüm olabilir. Bunların hepsi iletim biter bitmez harekete geçer ve çarpışma kaçınılmaz olur.

**p-persistent CSMA:** $p$ olasılıktan gelir. İletim ortamı dinlenir; boşsa $p$ olasılıkla iletime geçilir, $1-p$ olasılıkla iletim biraz ertelenir. Ortam meşgulse boşalana kadar sürekli dinlenir; boşalınca yine $p$ olasılıkla iletime geçilir. $p$'nin nasıl seçileceği üzerinde çalışılması gereken bir konudur. Bir iletim sürerken $N$ istasyon iletime geçmek isterse ve her biri $p$ olasılıkla geçecekse, toplamda $N \cdot p$ gibi bir değer oluşur. Bütün olasılıkların toplamı 1'i geçmemelidir; $p$ buna göre seçilmelidir.

> **Ders sonrası not:** Hoca önce "P-1 olasılıkla" dedi, sonra "1-P olasılıkla" diye düzeltti. Doğrusu $1-p$'dir.

### 7.3 Throughput karşılaştırması

Hoca, araştırmalarda karşılaşılacak bir grafik gösterdi: y ekseninde throughput (verim) vardır. Grafikteki sıralama şöyleydi:

- Pure Aloha en düşük seviyededir.
- Slotted Aloha belirgin bir iyileşme sağlar.
- 1-persistent CSMA, Slotted Aloha'dan daha iyidir.
- 0.5-persistent CSMA daha da iyidir.
- Non-persistent CSMA da iyi bir yerdedir.
- En iyisi 0.01-persistent CSMA'dır, yani %1 olasılıkla göndermeye başlamak.

<!-- BELİRSİZ: Throughput grafiğinin karesi okunan kareler arasında yok; eğrilerin sayısal değerleri aktarılmadı, sıralama altyazıdan alındı. -->

> **Hocanın vurgusu:** Gündelik hayatta her gün gördüğümüzün aksine burada nezaket kazanıyor; karşı tarafa ne kadar yol verirseniz o kadar etkin oluyor.

## 8. CSMA/CD

CSMA, hatta bir iletim varken çakışmayı ortadan kaldırır, ama iletim bittikten sonra iletime geçecek istasyonlar arasında çarpışma olasılığı devam eder. Daha büyük sorun, çarpışmanın olduğu an değil, bilgi karşıya gidip onay geri gelmeyince, yani çok sonra fark edilmesidir. Bunun için CSMA/CD geliştirilmiştir. Bu yazılımsal değil donanımsal bir teknolojidir, ağ arayüz kartının içinde gerçeklenir.

Çarpışma algılama kablolu ortamda mümkündür, kablosuz ortamda değildir. Kablosuzda bir antenle yayın yapılırken aynı noktada dinlenirse, sinyal orada çok güçlü olduğu için yalnızca kendi yayınınız duyulur; çarpışma olsa bile fark edilmez. Bu yüzden kablosuz sistemlerde Collision Detection değil Collision Avoidance (CSMA/CA) kullanılır.

Slayttaki akış (ekrandan, 01:35:00): CSMA tekniğinde iki veya daha fazla istasyonun hattı boş bularak iletime geçmeleri sonucunda oluşan veri bozulması ile doğan karışıklığın en kısa zamanda giderilmesi iletişimin süreklilik açısından gereklidir; bunun için veri yollayan istasyonların veri bozulmasını algılamaları ve iletimde olan istasyonların iletim sırasında hattı dinlemeleri gerekir.

```text
Bilgisayar iletime hazır  <------------------- Yeniden dene ----------------+
        |                                                                   |
        v                                                                   |
   Kanalı Dinle ---- Kanal kullanımda ----> (yeniden dene)                  |
        |                                                                   |
        v (kanal boş)                                                       |
Veriyi ilet ve kanalı dinlemeye devam et                                    |
        |                     |                                             |
        |                     +-- Çarpışma (collision) oluştu -->           |
        |                         Durumu belirleyen (jam) sinyalini yolla   |
        v                                    |                              |
 İletim tamamlandı                           v                              |
                          Exponential Binary Back-off algoritması           |
                          uyarınca bekle -----------------------------------+
```

Hoca adımları şöyle anlattı: kanal dinlenir, kullanımda değilse veri iletilir ve kanal dinlenmeye devam edilir. Sorun yoksa iletim tamamlanır. Çarpışma algılanırsa iletim durdurulur. Diğerlerinin de fark edebilmesi için bir jam sinyali oluşturulur; hoca bu kısmın biraz isteğe bağlı olduğunu söyledi. Herkes aynı adımları izlerse çarpışma tekrarlanabilir; bu yüzden fark yaratmak için Exponential Binary Back-off uygulanır. Üstel olduğu için küçük değer farkları büyük bekleme farkları üretir ve her düğüm farklı süre bekler. Sonra kanal yeniden dinlenir ve iletim denenir.

## 9. IEEE 802.3 Çerçeve Yapısı ve Fiziksel Katman

### 9.1 Çerçeve yapısı

Hoca bu çerçeve yapısının hâlâ geçerli olduğunu ve kullanıldığını belirtti. Slayttaki tanım ve tablo (ekrandan, 01:40:00):

- Çerçeve `10101010` şeklinde 7 byte uzunluğunda bir eşzamanlılık bilgisi ile başlamaktadır.
- Takip eden byte `10101011` şeklinde olup SFD (Start of Frame Delimiter) olarak adlandırılır.
- Çerçeve içinde iki adet adres alanı mevcuttur: sırası ile alıcı (Destination Address) ve gönderici (Source Address).
- Çerçeve içinde gelecek verinin ne büyüklükte olduğunu belirleyen bir bilgi de yerleştirilmiştir.

| Preamble | SFD | Dest. Addr. | Src. Addr. | Length | Data Unit | CRC |
|---|---|---|---|---|---|---|
| 7 byte | 1 byte | 2-6 byte | 2-6 byte | 2 byte | 46-1500 byte | 4 byte |

Preamble'ın 1 ve 0'ların ardışık gelmesinden oluşması, sayısal olarak salınım yapan bir işaret üretir; amacın eşzamanlılık sağlamak olduğu buradan anlaşılır. Adres alanları 2 ile 6 byte arasında tanımlanmıştır, ama biri 2 byte ise diğeri de 2 byte, biri 6 byte ise diğeri de 6 byte olmak zorundadır. Veri alanı değişken uzunlukta olduğu için bir uzunluk alanı vardır. Sonda CRC bulunur.

En uzun çerçeve, hocanın düzeltmesiyle 1526 byte'tır (hoca önce 1524 dedi). Veri alanı en az 46 byte olmalıdır, çünkü çerçevenin diğer alanlarla birlikte en az 64 byte olması gerekir. Gönderilecek veri 46 byte'tan küçükse özel tanımlanmış dolgu (padding) karakterleri eklenir.

Hesap (6 byte'lık adreslerle, python ile kontrol edildi):

- En uzun çerçeve (preamble ve SFD dahil): $7 + 1 + 6 + 6 + 2 + 1500 + 4 = 1526$ byte.
- En kısa çerçeve (preamble ve SFD hariç): $6 + 6 + 2 + 46 + 4 = 64$ byte.

### 9.2 Fiziksel katman tablosu

Slayttaki tablo (ekrandan, 01:45:00):

| | 10Base-5 | 10Base-2 | 10Base-T | 10Broad-36 | 10Base-F |
|---|---|---|---|---|---|
| Takma isim | Thick | Thin | | | |
| Standart | IEEE 802.3 | IEEE 802.3a | IEEE 802.3i | IEEE 802.3b | IEEE 802.3j |
| İletim ortamı | Coax (50 Ω) | Coax (50 Ω) | UTP (2 çift kablo) | Coax (75 Ω) | FO (850 nm) LED |
| Band genişliği | 10 Mbps Half-Duplex | 10 Mbps Half-Duplex | 10 Mbps Full-Duplex | 10 Mbps | 10 Mbps Full-Duplex |
| Segment uzunluğu | 500 m | 185 m | 100 m | 1.8 km | MMF 2 km, SMF 5 km |
| Kapsama alanı | 2.5 km | 0.925 km | 0.5 km | 3.6 km | |
| İstasyon sayısı (max) | 100 | 30 | | | 33 |
| Sinyalleşme | Baseband Manchester | Baseband Manchester | Baseband Manchester | Broadband DPSK | Manchester |

Segment uzunluğu, kesintisiz döşenebilecek en uzun kablo miktarıdır: 10Base-5'te 500 m, ince Ethernet'te 185 m, 10Base-T'de 100 m. 10Base-T ile çift kablo üzerinden full-duplex'e geçilir; sonraki anahtarlamalı ve hızlı Ethernet'te dört çift (sekiz tel) kullanılır. 100 m'nin altında ya da üstünde çalışıp çalışmaması kablonun kalitesine, ortama ve kullanılan yapıya bağlıdır.

> **Hocanın vurgusu:** 100 metre ciddi bir sınırdır. Standart 100 m diyorsa planı 90 m'ye göre yapmakta fayda vardır.

10Broad-36, LAN yerine geniş alanda kullanılan Ethernet'tir; 10Base-F fiber üzerinden Ethernet içindir.

> **Ders sonrası not:** Hoca 10Broad-36 için "1.6 km" dedi; slayttaki segment uzunluğu 1.8 km, kapsama alanı 3.6 km'dir.

## 10. Anahtarlamalı Ethernet, Diğer Standartlar, Metro Ethernet ve PoE

### 10.1 Paylaşımlı Ethernet'in sorunu

Şimdiye kadar konuşulan Ethernet paylaşımlıdır: bütün bilgisayarlar aynı hatta bağlıdır, sürekli çarpışma ve tıkanıklık (congestion) olasılığı vardır. Yol topolojisi 10 Mbps destekliyorsa ve 10 bilgisayar bağlıysa, kullanım kimin ne kadar gönderdiğine bağlı olsa da kabaca bilgisayar başına 1 Mbps düşer.

### 10.2 Anahtarlamalı (switched) Ethernet

Bu paylaşımı kaldırmak ve kapasiteyi daha etkin kullanmak için anahtar (switch) mekanizması ortaya atılmıştır. Hoca evdeki ADSL ya da fiber modem/yönlendiricinin Ethernet portlarının da anahtar işlevi gördüğünü, bu portlara bağlı bilgisayarların kendi aralarında full-duplex konuşabildiğini hatırlattı. Anahtar, farklı portlardaki cihazları doğrudan birbirine anahtarlar; çarpışma alanı anahtar ile uçtaki bilgisayar arasına daralır. Bağlantı full-duplex'tir: bir hat göndermek, bir hat almak için kullanılır. Böylece çarpışma ortadan kalkar ve CSMA/CD'ye gerek kalmaz.

Slayttaki tanım (ekrandan, 01:50:00):

- Aynı varış adresine farklı istasyonlardan gelen çerçeveler (frame) anahtar üzerinde yer alan bellek alanında tamponlanmaktadır.
- Anahtarlama birimleri çerçeveleri MAC (LAN) adreslerine bakarak gönderir (forward) ve filtreler.
  - Gönderme işlemi sırasında bir MAC adres tablosundan yararlanılır.
  - Aynı anda birden fazla düğümün kendi üzerinden çift yönlü (full-duplex) haberleşmesine izin verebilir.
- Ölçeklenme özellikleri yüksek olan bu cihazlar aynı zamanda farklı arayüzlere sahip olabilirler.

Hoca örnek verdi: 4 portlu bir anahtarın birinci portunda bir cihaz olsun; ikinci, üçüncü ve dördüncü portlardaki bilgisayarlar bu cihaza bilgi göndermeye çalışıyor. Farklı portlardan gelen çerçeveler tamponlanıp kuyruğa alınmalı, sonra birinci porttan çıkarılmalıdır. Anahtar ilk açıldığında hangi portuna kimin bağlı olduğunu bilmez. Bir porttan bilinmeyen bir hedef MAC adresine çerçeve gelirse bunu diğer portlardan yayımlar (broadcast); cevap hangi porttan gelirse o adresi o porta kaydeder. Yani hangi adrese hangi porttan erişileceği bilgisini yönetir.

### 10.3 Kademeli anahtar yapısı ve uplink oranı

Anahtarlamalı Ethernet'te çoğu zaman kademeli bir yapı kurulur. Örneğin üç kademede uçta son kullanıcıya doğrudan bağlı erişim (access) anahtarları, bir üstte bunların uplink'lerinin toplandığı dağıtım (distribution) anahtarları, en üstte omurga (core) anahtarları bulunur. Hoca üniversiteden örnek verdi: bir sınıfta ya da odada görülen Ethernet portu, bir dağıtım noktasındaki uç anahtara bağlıdır. Anahtarın alt taraftaki portlarına downlink, üst kademeye giden portuna uplink denir ve anahtarlar değerlendirilirken bu ikisinin oranına bakılır.

Örnek: alt tarafta her biri 1 Gbps olan 24 portlu bir anahtarın toplam alt kapasitesi 24 Gbps'tır. Uplink genelde sabit bir arayüz değil, GBIC gibi bir modül takılan yuvadır; 1, 10, 25, 40, 50, 100 Gbps modüller vardır. 100 Gbps'lık modül takılırsa darboğaz oluşmaz. 10 Gbps'lık modül takılırsa alt portlar tam kapasitede çalıştığında tıkanıklık kaçınılmazdır.

> **Ders sonrası not:** Altyazıda oran bozuk aktarılmış ("10 bölü 24x1024, yani 1 bölü 2"). Hesaplanırsa $24 \times 1\ \text{Gbps} / 10\ \text{Gbps} = 2{,}4$, yani alt kapasite uplink'in 2,4 katıdır (python ile kontrol edildi).

### 10.4 Diğer Ethernet standartları

Slayttaki liste (ekrandan, 01:55:00):

- IEEE 802.3a, 802.3i, 802.3j: Ethernet (10 Mbps)
- IEEE 802.3u, 802.3y: Fast Ethernet (100 Mbps)
- IEEE 802.3z, 802.3ab: Gigabit Ethernet (1 Gbps)
- IEEE 802.3ae, 802.3ak, 802.3an, 802.3aq: 10 GigE (10 Gbps)
- IEEE 802.3ba: 40/100G Ethernet (40/100 Gbps)
- IEEE P802.3bs: 200 Gbps/400 Gbps Ethernet
- IEEE 802.11 a/b/g/n/ac: Wireless Ethernet (11-600 Mbps)
- Metro Ethernet

Slaytta "801.11" yazıyordu; hoca bunun da yanlış olduğunu belirtti. Fast Ethernet altında 100Base-TX, 100Base-T2, 100Base-T4 gibi alt standartlar vardır. Hoca bunların her ayrıntısının bilinmesini beklemediğini, kulak aşinalığı için anlattığını söyledi.

Hoca 40 ve 100 Gbps standartlarıyla ilgili şunu aktardı: kapasite her yetersiz kaldığında çalışma grubu toplanır ve teknolojiyi yeniden mi yaratacağız, yoksa eskiye uyumlu mu kalacağız diye tartışır. Çoğu zaman eskiye uyum tercih edilir, çünkü kimse yapılan yatırımın çöpe gitmesini istemez. Bu yüzden her yeni standart neredeyse doğrudan şu ilkeleri içerir: 802.3 Ethernet MAC ile uyumlu olmak, ağ mimarisinde ve yönetim yapılarında değişiklik gerektirmemek, mevcut fiber ya da bakır kablolamayı kullanmaya devam edebilmek.

### 10.5 Metro Ethernet

Telefon hatlarında kablolar bir santralde toplanır ve kapasiteye göre T1, T3 gibi tek bir hat üzerinden zaman bölmeli çoğullama (TDM) ile üst kademeye aktarılır. Daha önce konuşulduğu gibi TDM veri aktarımı için çok uygun değildir. Bu yüzden Ethernet'in noktadan noktaya bağlantılarda kullanıldığı Metro Ethernet uyarlaması yapılmıştır. Metro Ethernet normal Ethernet'te doğrudan kullanılamaz; yalnız erişim, çerçeveleme ve benzeri özellikleri Ethernet'e benzer, ortam erişim kontrolü tam olarak aynı değildir.

### 10.6 Power over Ethernet

Bugün kullanılan Ethernet kabloları dört bükümlü çiftten oluşur. PoE, bu çiftler üzerinden bir cihazın elektrik ihtiyacını da karşılamaya dayanır. Bunun için genellikle power injector denen ek bir donanım kullanılır; üst segment kurumsal anahtarlarda portların doğrudan PoE desteği vardır. Ancak 48 portlu bir cihazın bütün portlarında aynı anda PoE verilirse cihazın güç ihtiyacı çok büyür. Bu yüzden portların hepsi bu özelliğe sahip olsa da aynı anda kullanılabilecek PoE port sayısı genelde sınırlanır.

## 11. Gerçek Zamanlı Sistemler ve IEEE 802.4 Token Bus

### 11.1 Neden Token Bus

Slayttaki gerekçe (ekrandan, 02:05:00): IEEE 802.3 Ethernet kötü durum senaryolarında uzun süre beklemeye neden olabilir; fabrika ortamındaki gerçek zamanlı (real-time) uygulamalarda bazı problemler doğar.

### 11.2 Gerçek zamanlı ne demek

Hoca öğrencilere gerçek zamanlı uygulamaya uygun olmamanın ne demek olduğunu sordu. "Gerçek zaman" demenin hiçbir şeyi açıklamadığını belirtti. Gerçek zamanlı sistem, işlerin bir zaman kısıtı içinde gerçekleştirildiği yapıdır.

Örnek olarak MP3 çaları verdi. MP3 dosyasındaki her kodlanmış ses parçası sırayla alınmalı, açılmalı ve çalınmalıdır. Kodlayıcı ses parçalarını belli bir süre uzunluğunda kodladıysa (hocanın örneğinde 53 ms) çözme işlemi o süre içinde tamamlanıp sonraki çerçeve hazır edilmelidir. Edilemezse cızırtı, boşluk ya da üst üste binmeler duyulur. Bu ölümcül olmayan, en fazla cihazı değiştirmekle sonuçlanan bir sorundur; buna yumuşak (soft) gerçek zamanlı kriter denir.

Öte yandan bir fren sisteminde 100 ms'de bir yapılan sık-bırak işlemi yanlış yapılırsa trafik kazasına yol açabilir. Bunun için son tarih (deadline) kesin olmalı, sistem katı (hard) gerçek zamanlı olmalıdır. Bu da yapılan işin deterministik olmasını gerektirir.

Ağ üzerinden örnek: bir çerçevenin gönderilme süresi her seferinde birbirine çok yakın olmalıdır. 9, 8, 9,5, 8,5 ms gibi değerler kabul edilebilir; ama bir seferinde 1 ms, bir seferinde 10 ms sürüyorsa, toplam işin 100 ms içinde bitip bitmeyeceği belirsiz hâle gelir. Gecikmeleri bu kadar değişken olan bir yapı gerçek zamanlı uygulamalara doğrudan uygun değildir.

### 11.3 Token Bus'ın çalışması

Bu ihtiyaçtan yola çıkılarak 802.4 Token Bus ortaya atılmıştır. Hoca bunun oldukça sofistike ve karmaşık bir tasarım olduğunu söyledi: sisteme eklenen her cihazın yanlış hatırlamıyorsa 10 civarı farklı zamanlayıcı tutması gerekir ve 24 kadar durum vardır. Ek yükü çok fazladır; bugün kullanımı çok sınırlıdır ve üzerine aktif geliştirme yapılmamaktadır. Hoca, bir ana bilgisayarda (mainframe) donanım yönetim konsolu ile işlemci arasındaki haberleşmede bu yapının kullanıldığını gördüğünü aktardı.

Slayttaki tanım (ekrandan, 02:05:00):

- Fiziksel olarak yol veya ağaç topolojisindeki bilgisayarların mantıksal (logical) bir halka oluşturması:
  - mantıksal halka kurulduktan sonra en büyük numaralı bilgisayar iletime geçer,
  - iletim hakkının kimde olduğunu belirleyen kontrol çerçevesini (jeton-token) komşusuna verir.
- Hat yayımlamalı (broadcast) yapıda kullanıldığı ve hat üzerinde iletimde olma imkânı sadece elinde jetonu bulunduran istasyonda olduğu için hiçbir şekilde bilgi bozulması (collision) mümkün değildir.

Jeton halkada komşudan komşuya geçer ve sonunda en yüksek ID'li istasyona döner. Hoca jetonu kralın asasına benzetti: asa kimdeyse kral odur. Token Bus o dönemde Ethernet ile yarışmış bir teknolojidir. Orijinal hızı hocanın hatırladığı kadarıyla 1.5 ve 10 Mbps, sonraki sürümlerde 100 Mbps'tır.

### 11.4 Token Bus çerçeve yapısı

Slayttaki tanım (ekrandan, 02:10:00):

- IEEE 802.3 çerçeve yapısında olduğu gibi IEEE 802.4'te de çerçeve preamble olarak adlandırılan zamanlama bilgisi ile başlamaktadır; bu bilgi en az 1 byte olabilir.
- SD (Starting Delimiter) ve ED (Ending Delimiter) çerçeve başlangıç ve bitişini belirlemek için kullanılmaktadır.
- FC (Frame Control) kontrol amaçlı çerçeveler ile veri çerçevelerini ayırt edebilmek için kullanılmaktadır.
- Adres alanları IEEE 802.3'te olduğu şekilde önce alıcı sonra gönderici adresi olarak kullanılır.
  - Adresler 2 veya 6 byte olabilmektedir.
  - Aynı iletişim ortamı içindeki bütün adresler eşit uzunluklarda olmalıdır.

Hoca FC alanının bir byte olduğunu, veri alanının 8182 byte'a kadar çıkabildiğini söyledi. Bu, Ethernet'in en fazla 1500 byte'lık veri alanının beş katından (7500) bile fazladır. Bunun nedenini ve Ethernet'teki 64 byte alt sınırının nedenini sordu (bkz. Örnek Sorular). Cevap, ikisinin aynı sorunun farklı ele alınışından gelmesidir.

> **Hocanın vurgusu:** Ethernet'te paylaşılan hatta her an çarpışma olabilir ve çarpışma algılamanın çalışabilmesi için çakışan çerçevelerin belli bir uzunlukta olması gerekir; 64 byte sınırı oradan gelir. Token Bus'ta jeton yalnız bir istasyondadır, çarpışma derdi yoktur; verinin çöpe gitme olasılığı olmadığından çok daha büyük veri alanı kullanılabilir.

## 12. IEEE 802.5 Token Ring

### 12.1 Çalışma ilkesi

Token Bus bir adım daha ileri götürülerek Token Ring'e çevrilmiştir. Burada fiziksel olarak da halka kurulur: bir bilgisayarın çıkışı diğerinin girişine bağlanır. Slayttaki tanım (ekrandan, 02:15:00):

- IEEE 802.5 iletime geçecek olan bilgisayarların sıra dâhilinde verilerini yollaması esasına dayanan bir teknik kullanmaktadır.
- Halka topolojisinde kurulu olan bilgisayar ağında herhangi bir veri iletimi olmasa bile 3 byte büyüklüğündeki jeton adı verilen kontrol çerçevesi dolaşmaktadır.
- Jeton veri iletimi için bekleyen bir istasyon NIC'ine geldiğinde eğer boş ise istasyon veri çerçevesini yollayabilir.
- Çerçevenin hedefine vardığı ve kopyalandığı anlaşıldığında onu halkadan çekerek daha önce halkadan kaldırdığı jetonu geri koyar.

Jeton bütün bilgisayarların ağ arayüz kartlarından sırayla girip çıkar. 3 byte'lık jetonda Start Delimiter, Access Control ve End Delimiter vardır. Access Control kısmından jetonun birine ayrılıp ayrılmadığı, kullanımda olup olmadığı, yani hattın kullanılıp kullanılamayacağı anlaşılır.

Gönderilen veri çerçevesi de halkadaki bütün kartlardan geçer. Her istasyon varış adresine bakıp çerçevenin kendisi için olup olmadığına karar verir. Kendisine aitse çerçevenin bir kopyasını alır, çerçevenin halkada devam etmesine izin verir ve yalnız sondaki kontrol kısımlarını değiştirir. Çerçeve, onu hatta koyan istasyona kadar döner; o istasyon sondaki kontrol bilgilerine bakarak çerçevenin alıcı tarafından kopyalanıp kopyalanmadığını anlar ve ne yapacağına karar verir. Veri çerçevesi jetonun bazı alanlarını da taşıdığından, jeton bir bakıma veri çerçevesine dönüştürülmüş olur.

### 12.2 Halkadaki bit sayısı

Halkada her zaman tek jeton dolaşmak zorunda değildir. Uygun jeton boyutuna karar vermek için halkaya bırakılan bitlerin fiziksel uzunluğunu bilmek gerekir. Slayttaki formüller (ekrandan, 02:20:00):

$$\text{bir bit çıkarma süresi} = \frac{1}{R\ (\text{Mbps})}$$

$$\text{bit uzunluğu} = SP\ (m/\mu s) \times \text{bir bit çıkarma süresi}\ (\mu s/\text{bit})$$

$$b = \frac{L}{\text{bit uzunluğu}}$$

Burada $R$ halkanın veri iletim hızı, $SP$ halka üzerindeki sinyalin yayılma hızı (m/µs), $L$ halkanın metre cinsinden uzunluğu, $b$ halkada aynı anda bulunabilecek bit sayısıdır. Hattan bir bit $1/R$ sürede çıkar; bu süre yayılma hızıyla çarpılınca her bitin halkada kapladığı uzunluk bulunur; halka uzunluğu buna bölünür.

Slayttaki örnek (derste sözlü, 02:21:24):

- Verilen: $R = 1$ Mbps, $SP = 200$ m/µs, $L = 1$ km $= 1000$ m.
- Bir bit çıkarma süresi: $1/1 = 1$ µs (ara adım eklendi).
- Bit uzunluğu: $200 \times 1 = 200$ m (ara adım eklendi).
- Sonuç: $b = 1000 / 200 = 5$ bit. Halkada en fazla 5 bit bulunabilir (python ile kontrol edildi).

### 12.3 Öncelik, rezervasyon ve monitör istasyon

802.5 bir önceliklendirme sağlar, ama bu sorunludur. Hoca işletim sistemlerinden bağlantı kurdu: öncelik temelli bir yapıda çok sayıda istemci aynı anda bir kaynağa erişmek istediğinde düşük öncelikli olanlar açlığa (starvation) uğrayabilir. Burada da herkesin bir ID'si ve buna bağlı önceliği vardır; yalnız öncelik mekanizması olsaydı bazı istasyonların hattı kullanması çok uzun süre ertelenebilirdi. Bunu önlemek için bir rezervasyon mekanizması vardır: hattı kullanmadan önce rezerve etmek mümkündür. Ayrıca hattın tek bir istasyon tarafından domine edilmesini engellemek için bir zaman sınırlaması mekanizması bulunur.

Jetonu alıp kendi veri çerçevesini koyan istasyon sonra bu çerçeveyi geri almalıdır. Bu sırada istasyon kilitlenir, yeniden başlar ya da kapatılırsa, hattın devamlılığı sağlanmalı ve jeton yeniden oluşturulmalıdır. Sistem çarpışmasız (collision-free) olsa da jeton dış gürültü nedeniyle bozulabilir. Bütün bunları yönetmek için bir monitör istasyon bulunur.

### 12.4 Diğer özellikler

Slayttaki bilgiler (ekrandan, 02:25:00):

- Jetonlu halka yapısında 6 byte'lık bir NIC adresi kullanılmaktadır.
- Differential Manchester kodlama tekniğinin kullanıldığı jetonlu halkanın eriştiği veri iletim hızları 4 ve 16 Mbps'dır.
  - IEEE 802.5t ile 100 Mbps,
  - IEEE 802.5v ile fiber optik kablo kullanılarak 1 Gbps.
- IEEE 802.5 jetonlu halkada, IEEE 802.3 Ethernet ve IEEE 802.4 jetonlu yoldan farklı olarak veri önce MSB gidecek şekilde yollanmaktadır.
- Jetonlu halka için tanımlı olan 3 tane çerçeve yapısı mevcuttur: veri, jeton ve durdurma (abort) çerçeveleri.

Hoca Access Control alanındaki bitlerin ayrıntısına ekstra ayrıntı olduğu için girmeyeceğini söyledi.

## 13. FDDI

### 13.1 Genel yapı

FDDI (Fiber Distributed Data Interface), fiber optik bağlantılarla 100 Mbps iletişim sağlayan, ANSI ve ITU tarafından ortaya atılan bir standarttır. Bakır kablo üzerinde aynı özellikleri sergileyen değiştirilmiş hâli CDDI'dır (Copper Distributed Data Interface). 802.4 ve 802.5'te olduğu gibi burada da haberleşmek için jetonu ele geçirmek gerekir ve bir öncelik mekanizması vardır: zamana duyarlı bilgiyi göndermek için öncelik hakkı tanınır. FDDI ağına bağlı her istasyonun hattı eşit sürelerde kullanması beklenir; bunun üzerine bir tür zaman bölmeli çoğullama yapılır.

İki tür çerçeve vardır: S-Frame (Synchronous Frame, zamana duyarlı) ve A-Frame (Asynchronous Frame).

### 13.2 Zamanlayıcılar

FDDI üç zamanlayıcıdan yararlanır:

- **Sync Allocation (SA):** halka kurulurken belirlenir, her istasyon için farklıdır; istasyonun S çerçevesi yollamak için kullanabileceği süreyi belirtir.
- **Target Token Rotation Time (TTRT):** jetonun halka boyunca iletilmesi için gereken ortalama süre, yani jetonun halkayı ne kadar sürede dolaşmasının beklendiğidir. Halka herkes için aynı olduğundan bütün istasyonlar için aynıdır ve halka kurulurken belirlenir. Jetonun gerçek dolaşma süresi bundan kısa ya da uzun olabilir ve istasyonun yapacakları buna göre değişir.
- **Absolute Maximum Time:** TTRT'nin iki katıdır. Her şeyin son noktasıdır: gönderilen jeton bu süre sonunda hâlâ önünüzden geçmediyse bir terslik vardır.

### 13.3 4B/5B kodlama

Hoca FDDI'nin sinyalleşmesinin üzerinde konuşulmaya değer olduğunu söyledi. Slayttaki tanım ve tablo (ekrandan, 02:30:00):

- FDDI'da 4B/5B olarak adlandırılan özel bir kodlama tekniği kullanılmaktadır; bu teknik uyarınca 4 bitlik veriler 5 bitlik değerler ile değiştirilir.
- Elde edilen yeni değer NRZ-I ile kodlanır.

| 5 bit | Açıklama |
|---|---|
| 00000 | Q (Quit) |
| 11111 | I (Idle) |
| 00100 | H (Halt) |
| 11000 | J (Başlangıç belirleyicisi olarak kullanılır) |
| 10001 | K (Başlangıç belirleyicisi olarak kullanılır) |
| 01101 | T (Bitiş belirleyicisi olarak kullanılır) |
| 11001 | S (Set) |
| 00111 | R (Reset) |

4 bitle $2^4 = 16$ değer ifade edilir; bu 16 sembol $2^5 = 32$ kodla ifade edilir. Neden fazladan bit kullanıldığı sorusu üzerine bir öğrenci kontrol bitlerini araya sıkıştırmak için olduğunu söyledi. Hoca bunu doğruladı: 16 kod gerekirken 32 kod kullanılır, boşta kalan 16 koda kontrol karakterleri yerleştirilebilir. Tablodaki kontroller hattın kontrolüdür: hattın boşta (idle) olduğunu bildirmek, iletimi durdurmak, çerçevenin başını ve sonunu belirtmek gibi. Bunlar verinin bütünlüğünün kontrolü değildir.

Hoca ikinci bir kazanç daha istedi: kontrol karakteri kullanılmasa bile 4 biti 5 bitle göndermenin ne kazandırdığını sordu. Açıklaması şöyleydi: 4 bitle `0000` gönderildiğinde bir bit bozulup `0001` olursa, bu da geçerli bir koddur; hatayı anlamak için ek bir kod gerekir. 5 bitle 32 olasılığın 16'sı geçerli, 16'sı geçersizdir. Geçerli 16 kod 32 olasılık arasına iyi dağıtılırsa (Hamming uzaklığı), tek bitlik bir bozulma kullanılmayan bir koda düşer ve hata doğrudan anlaşılır. İki amaç birlikte de kullanılabilir: kalan 16 koddan yalnız birkaçı kontrol için ayrılır, diğerlerine düşen geçersiz kelimeler hata yakalamayı sağlar.

> **Hocanın vurgusu:** 4 bitle ifade edilebilecek bir şeyi 5 bitle göndermek her zaman kötü değildir; fazladan kodlar hat kontrolü için, kodlar iyi dağıtılırsa hata yakalama için de kullanılabilir.

### 13.4 Çerçeve yapısı

FDDI'da iki çerçeve vardır: veri çerçevesi ve jeton çerçevesi. Jeton daha öncekilerle aynıdır: Start Delimiter, Access Control, End Delimiter. Veri çerçevesinde Start Delimiter, Frame Control (çerçevenin ek özelliklerini belirler), adresler (burada doğrudan 6'şar byte), veri (en fazla 4500 byte), Ending Delimiter ve gönderilen çerçevenin durumunun tutulduğu Frame Status bulunur. Veri alanının Ethernet'e göre büyük olması yine çarpışmasız olmasından kaynaklanır.

<!-- BELİRSİZ: FDDI çerçeve yapısı slaytının karesi okunan kareler arasında yok; alan adları ve 4500 byte değeri altyazıdan alındı. -->

### 13.5 Katmanlar, çift halka ve cihazlar

FDDI'da dört ayrı protokol katmanı varmış gibi görünür: PMD (Physical Medium Dependent), Physical, MAC ve LLC. Slayttaki bilgiler (ekrandan, 02:40:00):

- PMD (Physical Medium Dependent) iletim ortamının fiber optik veya bakır olmasına göre iletimin ışık veya elektrik akımı ile yapılıp yapılmayacağını belirler.
- FDDI çoğu zaman iki adet halkadan oluşmuştur.
  - İletim birincil halka üzerinden yapılır.
  - İkincil halka, hat veya hat üzerindeki bir istasyonda oluşan hataların iletimi etkilememesi için halkayı tamamlamak amacıyla kullanılmaktadır.
- İstasyonlar hatta MIC (Media Interface Coupler/Controller) adı verilen arabirimler yardımıyla bağlanır.

Cihaz türleri:

- **Dual attached station (DAS):** iki MIC kullanan kart. Maliyeti yüksek olduğu için her yerde kullanılmaz.
- **Single attached station (SAS):** tek MIC'li kart; genelde bu kullanılır.
- **Dual attachment concentrator (DAC):** bir anahtar gibi düşünülebilir. Tek arabirimli cihazlar bu cihaza bağlanır, iki halka da bu cihaza bağlanır; aralarında geçiş yaparak sürekliliği sağlar.
- **Single attached concentrator (SAC):** bir tarafta tek, bir tarafta çift bağlantı vardır.
- **Null attached concentrator (NAC):** doğrudan toplanma noktasını ifade eden cihazlardır.

<!-- BELİRSİZ: Hoca cihazların bağlantısını bir grafik üzerinden gösterdi, o grafik okunan kareler arasında yok. -->

## Örnek Sorular

Bu derste ekranda ayrı bir soru slaytı gösterilmedi. Aşağıdakiler hocanın derste sözlü sorduğu sorular ve slayttaki sayısal örnektir.

**Soru 1** (derste sözlü, 02:01:42): Ethernet'in gerçek zamanlı uygulamalara doğrudan uygun olmaması ne demektir? Gerçek zamanlı ne demektir?

> **Çözüm (derste verildi):** Gerçek zamanlı sistem, işlerin bir zaman kısıtı içinde tamamlandığı sistemdir. Yumuşak gerçek zamanlıda (ör. MP3 çalar) kısıt kaçarsa kalite bozulur; katı gerçek zamanlıda (ör. fren sistemi) sonuç ölümcül olabilir ve işlemin deterministik olması gerekir. Ethernet'te çarpışma ve rastgele bekleme yüzünden çerçeve gönderme süresi çok değişken olabilir (bir seferinde 1 ms, bir seferinde 10 ms), kötü durumda uzun bekleme oluşur. Bu yüzden zaman kısıtının sağlanıp sağlanmayacağı belirsizdir.

**Soru 2** (derste sözlü, 02:11:22 ve 02:11:44): 802.4 Token Bus'ta veri alanı neden Ethernet'tekinden çok daha büyük (8182 byte)? Ethernet'teki 64 byte'lık en kısa çerçeve sınırı nereden gelir?

> **Çözüm (derste verildi):** İkisi de aynı sorunun farklı ele alınışından gelir. Ethernet'te paylaşılan hatta çarpışma olabilir; çarpışma algılamanın çalışması için çakışan çerçevelerin belli bir uzunlukta olması gerekir, 64 byte'tan kısa çerçevelerde çarpışma algılanamaz. Token Bus'ta yalnız jetonu tutan istasyon iletebildiği için çarpışma yoktur; verinin çöpe gitme riski olmadığından daha büyük veri alanı kullanılabilir.

**Soru 3** (ekrandan, 02:20:00; derste sözlü, 02:21:24): Halka ağı 1 Mbps hızında, halka üzerindeki yayılma hızı 200 m/µs ve halka uzunluğu 1 km ise halkada aynı anda en fazla kaç bit bulunabilir?

> **Çözüm (derste verildi):** Bir bit çıkarma süresi $1/R = 1$ µs, bit uzunluğu $200 \times 1 = 200$ m, $b = 1000/200 = 5$ bit. Hoca sonucu "en fazla 5 bit olabiliyor" diye verdi; ara adımlar formülden kuruldu (python ile kontrol edildi).

**Soru 4** (derste sözlü, 02:30:19 ve 02:31:21): 4 bitle kaç değer ifade edilir? 4 bitle ifade edilebilecek bir şey neden 5 bitle ifade edilir?

> **Çözüm (derste verildi):** $2^4 = 16$ değer; 5 bitle $2^5 = 32$ kod vardır. Bir öğrenci fazladan kodların kontrol karakterleri için kullanıldığını söyledi, hoca doğruladı: boşta kalan 16 koda hat kontrol sembolleri (Idle, Halt, J/K başlangıç, T bitiş vb.) yerleştirilir.

**Soru 5** (derste sözlü, 02:32:09): Kontrol karakteri kullanılmasa bile 4 biti 5 bitle göndermek ne kazandırır?

> **Çözüm (derste verildi):** Hata sezme. 16 geçerli kod 32 olasılık arasına, tek bitlik bozulmalar geçersiz (kullanılmayan) kodlara düşecek şekilde dağıtılırsa, alıcı geçersiz bir kod gördüğünde hatayı doğrudan anlar. Bu, hat kontrolü için kullanılmasıyla birlikte de yapılabilir: kalan kodların bir kısmı kontrol sembolü olur, geri kalanlar hata yakalamaya yarar.

## Dersin Toparlaması

Bu derste yerel alan ağlarının IEEE 802 çerçevesinde nasıl düzenlendiği incelendi. 802 projesi farklı LAN teknolojilerini ortak bir LLC katmanı üzerinde birleştirir. Veri bağı katmanı, ortama erişimi, eşzamanlamayı ve fiziksel adreslemeyi yürüten MAC ile hata ve akış kontrolünü yürütüp donanım soyutlaması sağlayan LLC'ye ayrılır. LLC'nin üç servis tipi ve bugün neden onaysız bağlantısız servisin tercih edildiği tartışıldı.

Ethernet'in tarihçesi üzerinden ortam erişim yöntemlerinin gelişimi izlendi: Aloha (yaklaşık %18), Slotted Aloha (yaklaşık %37), CSMA ve persistent türleri, ardından iletim sırasında çarpışmayı algılayan CSMA/CD. 802.3 çerçeve yapısı, fiziksel katman standartları, anahtarlamalı Ethernet, uplink oranı, yeni Ethernet standartları, Metro Ethernet ve PoE anlatıldı. Gerçek zamanlı uygulamaların ihtiyacından doğan jeton temelli yöntemler olarak Token Bus, Token Ring (halkadaki bit sayısı hesabı, öncelik, rezervasyon, monitör istasyon) ve FDDI (zamanlayıcılar, 4B/5B kodlama, çift halka ve cihaz türleri) incelendi. Bir sonraki derste kablosuz ağlara geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
