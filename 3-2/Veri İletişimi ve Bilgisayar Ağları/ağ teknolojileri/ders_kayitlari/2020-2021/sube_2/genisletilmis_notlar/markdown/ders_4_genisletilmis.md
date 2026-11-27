# Ders 4 Genişletilmiş Notu: Yönlendirme Algoritmaları: Optimallik İlkesi, Flooding, Uzaklık Vektörü, Bağlantı Durumu ve Hiyerarşik Yönlendirme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Alt Katmanların Önemi
- 2. Yönlendirme ve İletme
- 3. Optimallik İlkesi ve Sink Tree
- 4. En Kısa Yol Algoritması
- 5. Flooding
- 6. Merkezi ve Dağıtık Yönlendirme
- 7. Uzaklık Vektörü Yönlendirmesi
- 8. Sonsuza Sayma Sorunu
- 9. Bağlantı Durumu Yönlendirmesi
- 10. Hiyerarşik Yönlendirme
- 11. Broadcast, Multicast ve Anycast Yönlendirme
- 12. Ad Hoc Ağlarda Yönlendirme ve Sonraki Konu
- Örnek Sorular

## 1. Alt Katmanların Önemi

Ders başlamadan önce sohbetten gelen bir soru üzerine, veri iletişimi dersinin konularını bilmeyen biri için hangi konuların gözden geçirilmesi gerektiği konuşuldu. Hocanın cevabı genel ama nettir: alt katmanlar, yani fiziksel katman, veri bağı katmanı ve ortam erişim kontrolü (medium access control) iyi çalışılmalıdır. Katmanlar bir bütündür. Veri bağı katmanında çerçeveleme (framing), hata kontrolü ve akış kontrolü vardır; ama hata kontrolü ve akış kontrolü tek bir katmanda yapılan işler değildir, diğer katmanlarla birlikte gerçekleşen operasyonlardır. Bu derste üst katmanlardaki akış kontrolü konuşulacağı için aşağıda neler uygulandığını bilmek önemlidir.

Ağlar OSI referans modeli üzerinden anlatılır. Yedi katman vardır, ama uygulamaya, TCP/IP'ye bakıldığında daha az katman konuşulur. Ders kitabının modelinde fiziksel katman dahil altı katman vardır; bunların ilk üçü veri iletişimi dersinde, kalanları bu derste işlenir.

## 2. Yönlendirme ve İletme

Konu listesi slayttan şöyledir (ekrandan, 00:05:00): optimality principle, shortest path algorithm, flooding, distance vector routing, link state routing, hierarchical routing, broadcast routing, multicast routing, anycast routing, routing for mobile hosts, routing in ad hoc networks. Ağ katmanı, paketleri birden çok bağlantı üzerinden uç noktalar arasında taşımaktan sorumludur (ekrandan, 00:10:00).

Elimizde birbirine bağlı ağ cihazlarından oluşan bir ağ vardır. Bu cihazlar haberleşmek için kendilerine gelen bir paketin bir sonraki adımda nereye gönderileceğine karar vermelidir. Bu işleme **yönlendirme (routing)**, kararı oluşturan yapıya **yönlendirme algoritması** denir. Paketin belirlenen yöne gönderilmesine ise **iletme (forwarding)** denir.

Slayttaki tanımlar şöyledir (ekrandan, 00:25:00):

- Yönlendirme, ağ yollarını keşfetme sürecidir.
  - Ağ, düğümler ve bağlantılardan oluşan bir graf olarak modellenir.
  - Neyin optimize edileceğine karar verilir (ör. adillik ya da verimlilik).
  - Topolojideki değişikliklere (ör. arızalar) göre rotalar güncellenir.
- İletme, paketlerin bir yol boyunca gönderilmesidir.

Slayttaki şekilde X ile X' arasında ortak bir hat ve bu hatta A'dan A''ya, B'den B''ye, C'den C''ye giden akışlar gösterilir.

Hoca bu ilişkiyi işletim sistemindeki zamanlayıcı (scheduler) ile dağıtıcı (dispatcher) arasındaki ilişkiye benzetti. Zamanlayıcı bir sonraki çalışacak süreci seçer, dağıtıcı bu kararı uygular. Benzer şekilde yönlendirme, karar için gereken bilginin toplanması ve bu bilgiye göre kararın verilmesidir; iletme ise paketi tampondan alıp hattın kuyruğuna koymak, yani kararı uygulamaktır.

### 2.1 Optimizasyon ölçütü

Bir karar verileceğine göre bir ölçüt gerekir: verimlilik mi, adillik mi? Ağdaki her hattın bir kapasitesi vardır ve bu kapasitenin ne kadar verimli kullanıldığı bir ölçüt olabilir. Hatlar, evde birbirine bağladığımız cihazlar gibi geçişin bedava olduğu hatlar olmak zorunda değildir. İnternetin yapısında servis sağlayıcılar (ISS) vardır; bunlar IXP (Internet Exchange Point) noktalarında, çoğu zaman neredeyse mesh yapısında birbirine bağlanır. Bir servis sağlayıcının ağından diğerine geçerken aradaki anlaşmalara bağlı olarak bir maliyet oluşur. Bu yüzden linkleri değerlendirirken ölçütlerden biri doğal olarak maliyettir.

Toparlarsak, yönlendirme ağ katmanı yazılımının, gelen bir paketin hangi çıkış hattından gönderileceğini belirleyen kısmıdır. Bu yazılım:

- Hatların özelliklerini toplar ve bunlarla ilgili bir bilgi oluşturur.
- Seçilen ölçüte göre optimizasyon yapar.
- Ağdaki değişikliklere kendini uyarlar.

Bunu yaparken **proaktif** (yönlendirme bilgisini ihtiyaç duyulmadan önce, periyodik olarak toplar) ya da **reaktif** (bilgiyi ihtiyaç anında toplayıp karar verir) davranabilir.

## 3. Optimallik İlkesi ve Sink Tree

Slayttaki ilke (ekrandan, 00:30:00): "En iyi yolun her parçası da en iyi yoldur; bir yönlendiriciye giden en iyi yolların birleşimi sink tree denen bir ağaçtır." Örnekte "en iyi", en az hop demektir.

Slaytın solunda A'dan O'ya kadar adlandırılmış düğümlerden oluşan bir ağ, sağında bu ağda B yönlendiricisine giden en iyi yolların sink tree'si vardır. Sink tree'nin bağlantıları şunlardır:

```text
B - A      B - C
A - D      A - F
D - G      D - H
F - K      K - L
C - I      C - J
J - E      J - N
N - M      N - O
```

Optimallik ilkesine göre B'den M'ye en iyi yol B-C-J-N-M ise, bu yol üzerindeki her parça da en iyidir: J ile N arasındaki yol da, J ile M arasındaki yol da en iyidir. Öyle olmasaydı daha iyi başka bir yol bulunmuş ve seçilmiş olması gerekirdi. Bu bize büyük kolaylık sağlar: bir başlangıç noktasından bir varış noktasına kadar yalnız iki uç için değil, aradaki düğümler için de yönlendirme bilgisi çıkarılmış olur.

Burada konuşulan tek yöndür. Ağ çift yönlü haberleşir ve ters yöndeki trafiğin en iyi yolu, linklerin karakteristiklerine bağlı olarak farklı olabilir.

Örnekte B başlangıç noktası kabul edilmiştir. A, C, J ya da E başlangıç noktası olsaydı sink tree'leri farklı olurdu.

> **Hocanın vurgusu:** Topolojideki her yönlendirici ve her host kendini başlangıç noktası kabul edip kendi sink tree'sini oluşturur. Yani topolojide birden fazla sink tree vardır; bunu hiçbir zaman unutmayın. Herkesin ağacı kendine özeldir.

## 4. En Kısa Yol Algoritması

Yönlendirme için kullanılan yöntemler veri yapıları ve algoritmalar derslerinde görülen graf algoritmalarıdır, çünkü topoloji bir graftır. Graf tek yönlü ya da çift yönlü olabilir. İşi kolaylaştırmak için başlangıçta bütün bağlantıların çift yönlü olduğu kabul edilir: A'dan B'ye yol bulunduğunda B'den A'ya da aynı yolun ters yönde kullanılacağı varsayılır, bir tarafı çözmek yeterlidir.

Ama gerçekte gidiş ve dönüş yolları aynı olmayabilir. Güvenlik, güvenilirlik, para, aradan geçilen servis sağlayıcıların ücretlendirmesi, politik nedenler, kurumlar arası rekabet ya da teknoloji bunun sebebi olabilir. Örneğin uydu bağlantısında uyduya veri gönderme imkanı olmayabilir ama uydu size gönderir; dönüş yolu karasal hat (landline) üzerinden olabilir. Uydudan aşağıya (downlink) göndermenin maliyeti her anlamda düşük, aşağıdan uyduya göndermenin maliyeti ise çok yüksektir. Yani bir yöndeki ağırlık ile diğer yöndeki ağırlık farklı olabilir.

Slayttaki tanım (ekrandan, 00:35:00): Dijkstra algoritması graf üzerinde bir sink tree hesaplar.

- Her bağlantıya negatif olmayan bir ağırlık/uzaklık atanır.
- En kısa yol, toplam ağırlığı en düşük olan yoldur.
- Bütün ağırlıklar 1 alınırsa en az hoplu yollar bulunur.

Algoritma:

- Sink'ten başla, diğer düğümlerin uzaklığını sonsuz yap.
- Diğer düğümlere uzaklıkları gevşet (relax).
- En düşük uzaklıklı düğümü seç, sink tree'ye ekle.
- Bütün düğümler sink tree'ye girene kadar tekrarla.

> **Hocanın vurgusu:** Ağırlığı kesinlikle kilometre, metre ya da gidilecek yol cinsinden bir mesafe olarak düşünmeyin; bunu bir maliyet olarak düşünün.

En kısa yol, aynı yere giden birden fazla yol varsa ağırlıkları uç uca eklendiğinde en düşük toplamı veren yoldur. Bazen iş hop seviyesine indirilir: her linkin ağırlığı 1 alınır, her geçiş bir hop sayılır. Optimallik ilkesi örneğine hop ile bakılırsa B'den M'ye C 1, J 2, N 3, M 4 hoptur; B ile M arasındaki en kısa yol 4 hoptur. B ile E arasındaki en kısa yol B-C, C-J, J-E olup 3 hoptur. Kavramsal olarak bir şeyin çalışıp çalışmadığını anlamak için önce hop ile başlanır, sonra güvenilirlik, güvenlik ya da maliyet gibi farklı ağırlıklar işe katılır.

Slaytlarda A'dan D'ye en kısa yolun adım adım hesaplandığı bir Dijkstra örneği ve algoritmanın bir gerçeklemesi de vardır; bunlar derste ayrıntılı anlatılmadı, algoritmalar dersindeki bilginin burada kullanılacağı söylendi. <!-- BELİRSİZ: Dijkstra adım adım örnek slaytı ve gerçekleme slaytı karelerde yok. -->

## 5. Flooding

Slayttaki tanım (ekrandan, 00:40:00):

- Bir paketi bütün ağ düğümlerine göndermek için basit bir yöntemdir.
- Her düğüm, bir giriş hattından aldığı yeni paketi diğer bütün hatlara göndererek taşırır.
- Taşırmayı durdurmak için düğümlerin taşırılan paketlerin kaydını tutması gerekir; hop sınırı kullanmak bile üstel büyümeye yol açabilir.

Flooding ağ açısından şu nedenle önemlidir: bir düğümden çıkan bilginin topolojideki bütün çökmelere ve aksaklıklara rağmen diğer bütün hostlara ulaşması isteniyorsa, uygulanacak en güvenilir, en garantili yöntem flooding'dir. Hoca bunu sel taşkınına benzetti: sel önüne ne katarsa her tarafa dağılır ve her yere erişir.

Ama en güvenilir yöntem en verimli yöntem değildir. Sel ne kadar zarar veriyorsa flooding de topolojiye o kadar zarar verir, çünkü ağı aşırı yükler. Unicast için, yani bir düğümden tek bir düğüme bilgi göndermek için kullanılırsa, bir arkadaşınıza bir şey iletmek için herkesin birbirinin kulağına söylemesi gibidir.

Flooding iki nedenle önemlidir. Birincisi, bir yönlendirme algoritması geliştirildiğinde güvenilirlik ve teslim oranı (delivery rate) gibi açılardan karşılaştırılacak en temel algoritmadır. İkincisi, birçok akıllı yönlendirme algoritması kontrollü bir flooding ile başlar; sonra bu flooding ortalığı yakıp yıkmadan, kontrollü bir şekilde söndürülür ve daha seyrek mesajlaşmaya dönülür. Yerel ağlardaki karşılığı **broadcast storm** olarak bilinir: bilgi kulaktan kulağa, herkesten herkese yayılır.

### 5.1 Flooding'i iyileştirmek

Hoca optimallik ilkesi slaytındaki ağa geri dönerek açıkladı. B'nin iki komşusu, A'nın üç komşusu, D'nin dört komşusu (A, G, H, I) vardır. Hiçbir kontrol yapılmazsa B, A'dan geleni C'ye ve geldiği yere bakmaksızın A'ya da gönderebilir. D her geleni dört yere birden göndermek zorunda kalır. Gelen paketi geldiği yöne bakmadan bütün bağlantılara yeniden göndermek flooding'in en basit, kontrolsüz halidir.

Flooding bile kendi içinde optimize edilebilir:

- **Geldiği hatta geri gönderme:** B'ye paket A linkinden geldiyse A bunu zaten biliyordur; B paketi yalnız A dışındaki linklere gönderir. D'ye I'dan geldiyse I'ya geri gönderilmez; H, G ve A'ya gönderilir.
- **Tekrar geleni düşürme:** D'ye paket önce A'dan geldi ve D onu G, H ve I'ya gönderdi diyelim. Aynı paket dönüp dolaşıp I'dan J'ye, J'den E'ye, E'den H'ye, H'den yeniden D'ye gelebilir. Bu yüzden düğümler bir tampon tutar ve paketi daha önce alıp almadığını kontrol eder; aldıysa paketi söndürür. Bunun için pakette tekil bir tanımlayıcı (identifier) olmalıdır.

> **Hocanın vurgusu:** Flooding ortalığı yakıp yıkan bir algoritma olabileceği gibi, basit dokunuşlarla optimize edilerek kontrollü ve çok faydalı bir algoritmaya da dönüşebilir. Flooding'i aklınızın bir kenarında tutun; önemli bir algoritmadır.

## 6. Merkezi ve Dağıtık Yönlendirme

Flooding dışında akıllı yönlendirme algoritmalarına ihtiyaç vardır. Yönlendirme algoritması **merkezi (centralized)** ya da **dağıtık (distributed)** olabilir.

Merkezi yönlendirmede bir merkez, bir koordinatör vardır. Topoloji bilgisi bu merkeze gelir; merkez bir yönlendirme algoritması çalıştırarak A'dan O'ya kadar her düğüm için sink tree'yi çevrim dışı (offline) oluşturur ve bunları düğümlere ayrı ayrı dağıtır. Topoloji küçükse ve sık değişmiyorsa (kopma, ekleme, arıza az ise) bu yöntem uygundur. Bazı topolojiler yıllarca değişmez; bunlarda yönlendirme tasarım sırasında (by design) elle bile hesaplanabilir. Merkezi yaklaşımın güzelliği topoloji hakkında ayrıntılı bilgiye sahip olmaktır. Dağıtık algoritmalarda ise düğüm yalnız kendi çevresinden haberdardır, bir adım ötesini göremez ve başkalarından aldığı bilgiyle tahmin yürütür; bu da sorun durumlarında toparlanmayı zorlaştırabilir.

Merkezi yaklaşımın sorunu büyük topolojilerde ortaya çıkar. Milyarlarca düğümün yönlendirmesini merkezi yapmak isterseniz, bütün bağlantı bilgisini dünyanın her yerinden tek bir yere taşımak için bile yönlendirmeye ihtiyacınız vardır. Bunu yapsanız bile hesaplayıp dağıtırken bir yerde elektrik kesilir, başka bir yerde bir cihaz çöker; dağıtmayı tamamlayamadan topoloji değişir, yetişmek mümkün olmaz.

Çözüm, bilgisayar biliminde sık kullanılan **böl ve yönet (divide and conquer)** yaklaşımıdır: yönlendirme dağıtık yapılır. Bedeli, düğümlerin (router ya da host) yalnız çevrelerindeki belirli bir bölgeyi görmesidir. Hoca bunu şöyle anlattı: İstanbul'da yaşıyor ve Ankara'da bir adrese gidecekseniz, ilk gördüğünüz benzinlikte Ankara'daki sokağa nasıl gidileceğini sormazsınız; Ankara'ya hangi taraftan çıkılacağını, çevre yoluna nasıl bağlanılacağını sorarsınız. Düğümler de çevrelerindeki düğümleri bilir ve onlarla konuşursa, dış dünyaya bağlantı sağlayanlar üzerinden dışarı çıkabilir.

## 7. Uzaklık Vektörü Yönlendirmesi

Uzaklık vektörü (distance vector) yönlendirmesi, internetin tasarımı üzerinde çalışan akademisyenlerin ortaya attığı bir algoritmadır. Benzer dönemlerde paralel çalışan iki araştırmacının, Bellman ve Ford'un, fikirleri çok benzediği için algoritma ikisinin adıyla anılır.

> **Ders sonrası not:** Hoca algoritmanın 1975 civarında tasarlandığını söyledi. Bellman-Ford algoritması büyük olasılıkla 1950'lerde yayımlandı; uzaklık vektörü yönlendirmesi ise büyük olasılıkla ARPANET'in ilk yönlendirme algoritması olarak 1969'dan itibaren kullanıldı.

Slayttaki tanım (ekrandan, 00:50:00): uzaklık vektörü dağıtık bir yönlendirme algoritmasıdır; en kısa yol hesabı düğümler arasında paylaştırılır.

Algoritma:

- Her düğüm komşularına olan bağlantıların uzaklığını bilir.
- Her düğüm, bildiği en düşük uzaklıklardan oluşan vektörü bütün komşularına duyurur.
- Her düğüm aldığı vektörlerle kendi vektörünü günceller.
- Bu periyodik olarak tekrarlanır.

Uzaklık hop cinsinden olabileceği gibi bir maliyet de olabilir: yolu kullanmak için servis sağlayıcıya ödenen para, gecikme, hata oranı vb. En temel uzaklık hop'tur. Vektörü çiftler gibi düşünebilirsiniz: optimallik ilkesi ağında B'nin komşuları A ve C'dir; B, iki komşusuna da kendi uzaklık bilgisini gönderir. Herkes periyodik olarak herkese bilgi gönderdiği için belirli anlarda kontrollü bir flooding gibi bir durum oluşur; bu anlar yönlendirmenin güncelleme zamanlarıdır.

> **Hocanın vurgusu:** Bu algoritma yaklaşık 50 yıllık, kapanmış bir defterdir. "Şöyle mi yapsaydık, niye böyle yapmamışlar" ile uğraşmayın; algoritma nasıl tasarlandıysa hatalarıyla, sorunlarıyla birlikte anlatılacak, sonra bu sorunların çözümü için yapılanlara bakılacak.

Yine de uzaklık vektörü bazı koşullarda, örneğin ad hoc ağlarda uygulanabilir. Ad hoc ağ, kağıt üzerinde önceden tasarlanmayan, daha çok kablosuz ortamda karşımıza çıkan; düğümlerin çalışır hale gelip kablosuz bağlantılarla haberleşmesiyle yolların anlık belirlendiği ağdır.

### 7.1 J düğümünün vektörü (sayısal örnek)

Slayttaki topolojide A'dan L'ye kadar düğümler vardır; yeni vektörü hesaplanan düğüm J'dir. J'nin komşuları A, I, H ve K'dir (derste sözlü, 00:55:26). <!-- BELİRSİZ: Bu örneğin slaytı karelerde yok; bütün değerler altyazıdan alındı. -->

**Verilen:** J'nin komşularına ölçtüğü gecikmeler: J-A = 8, J-I = 10, J-H = 12, J-K = 6. Bu değerleri J doğrudan ölçebilir, çünkü bunlar doğrudan komşularıdır.

A'dan gelen vektör:

| Hedef | A | B | C | D | E | F | G | H | I | J | K | L |
|---|---|---|---|---|---|---|---|---|---|---|---|---|
| A'nın uzaklığı | 0 | 12 | 25 | 40 | 14 | 23 | 18 | 17 | 21 | 9 | 24 | 29 |

Hoca bu değerleri tek tek okuduktan sonra kritik bir noktaya dikkat çekti: A'nın gönderdiği bu vektörde A'nın gerçekten emin olabileceği değerler yalnız kendisine (0) ve doğrudan komşularına olan uzaklıklardır; hoca kendisi dahil dört değer saydı. Diğerlerinin hepsi komşulardan gelen bilgiler üzerinden hesaplanmıştır. <!-- BELİRSİZ: Hocanın saydığı dört değerin hangi komşular olduğu altyazıda net değil (kendisi, B, E ve bir komşu daha). -->

**İşlem (B hedefi için):** J, her komşusu için "komşuya gecikme + komşunun B'ye bildirdiği uzaklık" toplamını hesaplar:

- A üzerinden: $8 + 12 = 20$
- I üzerinden: $10 + 36 = 46$
- H üzerinden: $12 + 31 = 43$
- K üzerinden: $6 + 28 = 34$

**Sonuç:** en küçüğü 20'dir; J'nin B'ye yeni uzaklığı 20, çıkış hattı A'dır.

> **Ders sonrası not:** Hoca I üzerinden yolu "36 artı 8, 44" diye hesapladı; J-I gecikmesi 10 olduğu için doğrusu $36 + 10 = 46$'dır. En küçük değer (20, A üzerinden) değişmez.

**İşlem (C hedefi için):**

- A üzerinden: $8 + 25 = 33$
- I üzerinden: $10 + 18 = 28$
- H üzerinden: $12 + 19 = 31$
- K üzerinden: $6 + 36 = 42$

**Sonuç:** en küçüğü 28'dir; J'nin C'ye yeni uzaklığı 28, çıkış hattı I'dır. Böylece J'nin yeni vektörü oluşur ve J bir sonraki turda bunu komşularına gönderir.

Genel kural şöyle yazılabilir (ara adım eklendi):

$$D_J(y) = \min_{v \in \{A, I, H, K\}} \left( d(J, v) + D_v(y) \right)$$

> **Hocanın vurgusu:** Bir düğüme komşularından gelen vektörlerdeki bazı değerler, düğümün emin olamayacağı değerlerdir. Düğüm yalnız kendisine doğrudan bağlı olanlarla ilgili değerleri garanti edebilir. Diğer uzaklıkların B üzerinden mi, E üzerinden mi, J üzerinden mi oluştuğunu bilmez.

## 8. Sonsuza Sayma Sorunu

Tasarım sırasında fark edilmeyen bir sorun vardır, çünkü her topolojide ortaya çıkmaz, yalnız belirli topolojilerde çıkar. Düğümlerin çökmesi, linklerin kopması, yönlendiricinin yeniden başlaması gibi hata durumları uzaklık vektöründe **sonsuza sayma (count-to-infinity)** sorununa yol açabilir. Hoca bu sorunun gerçek bir çözümü olmadığını söyledi: literatür bu konuda birçok araştırmayla doludur, ama sonunda uzaklık vektörü kenara konup yerine yeni bir algoritma getirilmiştir.

Slayttaki başlık (ekrandan, 01:00:00): "Arızalar, uzaklık vektörünün ulaşılamayan bir düğüme yol ararken sonsuza saymasına yol açabilir."

### 8.1 İyi haber hızlı yayılır

A-B-C-D-E bir zincir oluşturur; başlangıçta A ağda yoktur. A ağa katılınca B, A'ya bir hopla ulaştığını görür ve bunu C'ye gönderir. C, "B'ye 1 hopla ulaşıyordum, B de A'ya 1 hopla ulaşıyormuş, o halde ben 2 hopla ulaşırım" der ve bunu D'ye gönderir; D 3, E 4 olur.

| Durum | B | C | D | E |
|---|---|---|---|---|
| Başlangıç | • | • | • | • |
| 1 değişimden sonra | 1 | • | • | • |
| 2 değişimden sonra | 1 | 2 | • | • |
| 3 değişimden sonra | 1 | 2 | 3 | • |
| 4 değişimden sonra | 1 | 2 | 3 | 4 |

(• ulaşılamaz/sonsuz demektir.) Dört değişimden sonra ağdaki herkes A'ya erişebilir durumdadır.

### 8.2 Kötü haber yavaş öğrenilir

Şimdi A'nın bağlantısı kopar. B, A'ya doğrudan ulaşamaz; ama C'den A için "2 uzaklıkta" bilgisi gelir. B, "C'ye 1 uzaklıktayım, o halde A bana 3 uzaklıkta" diye düşünür. Bunu C'ye gönderir; C, "B A'ya 3 ile erişiyormuş, ben B'ye 1 ile erişiyorum, demek ki A bana 4 uzaklıkta" der. Bir sonraki turda B 5, C 6, B 7 yapar; D ve E de C'den gelen bilgiler yüzünden artmaya devam eder.

| Durum | B | C | D | E |
|---|---|---|---|---|
| Başlangıç | 1 | 2 | 3 | 4 |
| 1 değişimden sonra | 3 | 2 | 3 | 4 |
| 2 değişimden sonra | 3 | 4 | 3 | 4 |
| 3 değişimden sonra | 5 | 4 | 5 | 4 |
| 4 değişimden sonra | 5 | 6 | 5 | 6 |
| 5 değişimden sonra | 7 | 6 | 7 | 6 |
| 6 değişimden sonra | 7 | 8 | 7 | 8 |
| ... | ... | ... | ... | ... |
| Sonunda | • | • | • | • |

Hoca bunu gerçek hayattaki "kötü haber tez duyulur" sözünün tersi olarak anlattı: burada iyi haber tez duyulur, kötü haber çok gecikmeli gelir. Uzaklığın sürekli artması ağda bir sorun olduğuna dair ipucu verir, ama topolojinin kaç hop genişliğinde olduğu (20, 30, 40 hop?) bilinmez.

### 8.3 Pratik çözüm: 16 hop

Sorunun çözümü maksimum hop sayısında bulundu: vektör değişimlerinden sonra bir düğümün uzaklığı 16 hop olursa o düğüm sonsuzda, yani ulaşılamaz kabul edilir. 16 değeri o dönem kullanılan topolojilerin boyutlarına göre seçilmiştir; başlangıçta topolojide 5 cihaz vardı, sonra 8, 10, 15 civarına çıktı. Bugünün ağlarında bu değerin kat kat büyük olması gerekirdi. Sonsuzu 16 ile sınırlamak, "count to infinity" adının da kaynağıdır.

> **Ek bilgi (derste anlatılmadı):** 16 hop sınırı, uzaklık vektörü tabanlı RIP protokolünde kullanılan değerdir; RIP'te 15 hop en uzak ulaşılabilir uzaklık, 16 ise sonsuzdur.

## 9. Bağlantı Durumu Yönlendirmesi

Uzaklık vektörü sonsuza sayma sorunu yüzünden kullanılabilir olmaktan çıktı ve yerine **bağlantı durumu (link state)** yönlendirmesi getirildi. Hoca bunun 80'li yıllarda ortaya çıktığını ve günümüzde hâlâ kullanıldığını söyledi. Açık standartlar (RFC, Request for Comments) kapsamında iki biçimde karşımıza çıkar: OSPF ve IS-IS.

- **OSPF (Open Shortest Path First):** Buradaki "open", açık kaynaktaki "open" ile aynıdır; "en kısa yolu önce aç" anlamına gelmez. Gerçekleme herkese açıktır, referans gerçekleme vardır, para ya da lisans ücreti ödenmeden şartlarına uygun kullanılabilir.
- **IS-IS:** Hoca bunu "inter-system routing" diye açtı ve aynı algoritmanın sistemler arasında kullanılan, biraz değiştirilmiş hali olarak anlattı.

> **Ders sonrası not:** IS-IS'in açılımı büyük olasılıkla "Intermediate System to Intermediate System"dir. IS-IS de OSPF gibi büyük olasılıkla bir özerk sistem içinde kullanılan (iç ağ geçidi) protokoldür.

> **Ders sonrası not:** ARPANET'te uzaklık vektöründen bağlantı durumuna geçiş büyük olasılıkla 1979'da oldu.

Slayttaki tanım (ekrandan, 01:25:00): bağlantı durumu, uzaklık vektörüne bir alternatiftir.

- Daha fazla hesaplama ama daha basit dinamik.
- İnternette yaygın kullanılır (OSPF, IS-IS).

"Daha fazla hesaplama" ifadesi şöyle açıklandı: 1975'teki işlemci hızı, bellek kapasitesi ve ağ hızı çok düşüktü; 64 kbps, 128 kbps hatlardan söz ediliyordu. Sonra 1,5 ve 2 megabitlik standartlarla hızlar arttı, işlemci hızı ve adreslenebilir bellek de arttı. Böylece yerel bir yönlendiricinin yapabileceği hesap arttı ve hesaplama karmaşıklığı biraz daha yüksek bir algoritma kullanılabilir hale geldi.

Algoritma:

- Her düğüm komşularıyla ilgili bilgiyi LSP'ler (Link State Packet) içinde flooding ile dağıtır; bütün düğümler tam ağ grafını öğrenir.
- Her düğüm, her hedef için izlenecek yolu bulmak üzere Dijkstra algoritmasını çalıştırır.

Bu, kavramsal sink tree'nin birebir uygulamaya geçirilmesidir: topoloji bilgisi bütün düğümlere dağıtılır, her düğüm kendi sink tree'sini kendisi oluşturur. Merkezi yapılması tartışılan iş artık dağıtık yapılmaktadır. Bir düğüme 5 hopla gidiliyorsa, hangi düğümler üzerinden gidileceği de bilinir. Algoritma, daha önce söylendiği gibi kontrollü bir flooding ile başlar.

### 9.1 LSP'ler

Slayttaki ağ ve LSP'ler (ekrandan, 01:30:00). Ağdaki bağlantılar ve ağırlıkları:

| Bağlantı | Ağırlık |
|---|---|
| A-B | 4 |
| A-E | 5 |
| B-C | 2 |
| B-F | 6 |
| C-D | 3 |
| C-E | 1 |
| D-F | 7 |
| E-F | 8 |

Bir düğümün LSP'si komşularını ve onlara ulaşmak için bağlantı ağırlıklarını listeler. Her LSP'de önce Seq. ve Age alanları, sonra komşu-ağırlık çiftleri bulunur:

| Düğüm | Komşu, ağırlık |
|---|---|
| A | B 4, E 5 |
| B | A 4, C 2, F 6 |
| C | B 2, D 3, E 1 |
| D | C 3, F 7 |
| E | A 5, C 1, F 8 |
| F | B 6, D 7, E 8 |

LSP'lere eklenen iki önemli alan sıra numarası (sequence) ve yaştır (age). Age alanı zamanla farklı bir terimle, **time to live** (yaşam süresi) olarak anılmaya başlandı. Bu iki alan bazı karmaşaları ortadan kaldırmak için gereklidir.

**Sıra numarası:** Bilgiler belirli aralıklarla (örneğin 3 ya da 5 saniyede bir) sürekli yayınlanır. Paketlerde sıra numarası olmazsa, topolojinin büyüklüğüne, sorunlara ve gecikmelere bağlı olarak eski ve yeni paketler birlikte kullanılabilir. Eski ile yeni arasında topoloji değişmiş olabilir ama düğüm paketin eski mi yeni mi olduğunu bilemez; elde edilen sink tree bazı düğümlere ulaşmayı sağlamak yerine engelleyebilir. Hesap yapılırken sıra numaralarının uyumlu olması, bir eşzamanlılık oluşması gerekir. Flooding bölümünde söylenen "bu paketi daha önce ilettim mi" kontrolü için gereken tekil tanımlayıcı da bu sıra numarasıdır.

**Age:** Bir paketi tekrar iletmemek ayrı, paketin ağda sonsuza dek dolaşmasını engellemek ayrı bir iştir. Topolojideki durum yüzünden bir paket B'den C'ye, C'den E'ye, E'den F'ye, F'den D'ye, D'den C'ye tekrar tekrar dolaşabilir. Age alanı başlangıçta saniye cinsinden verilmiş ve her saniye azaltılmış; sonra bunun verimli olmadığı görülmüş ve hop sayısına çevrilmiştir. Hocanın anlatımıyla günümüzde bu alan hop cinsinden verilir, paket her düğümden geçtiğinde bir azaltılır ve sıfıra gelince paket ömrünün sonuna gelmiş olur.

> **Ders sonrası not:** Hop başına azaltılan alan IP başlığındaki TTL için doğrudur. OSPF'te LSA yaşı ise büyük olasılıkla saniye cinsinden tutulur ve en fazla 1 saate (MaxAge) kadar artar.

Paketi düşürmek (drop) teknik olarak şudur: ağ kartından bir paket gelir, başlığı incelenir, TTL alanı sıfır görülür ve paketle ilgili hiçbir şey yapılmamasına karar verilir. Paket gelmemiş kabul edilir.

Slayttaki ilkeler:

- Sıra numarası ve age, güvenilir flooding için kullanılır.
- Yeni LSP'ler alındıkları hatta onaylanır (acknowledge): düğüm gönderen komşusuna "bu paketi senden aldım" der ve paketi o komşu dışındaki komşularına gönderir. Böylece hem kontrollü hem güvenilir bir flooding yapılır.

Sonraki slaytta B yönlendiricisindeki LSP veritabanı gösterildi; bayraklar paketin onaylanıp onaylanmadığını, iletilip iletilmediğini göstermek için gönderme ve onay tarafları olarak tutulur. <!-- BELİRSİZ: B'nin LSP veritabanı tablosu karelerde yok, değerleri aktarılamadı. -->

### 9.2 Bağlantı durumunun üstünlükleri

Bağlantı durumunda bütün yönlendiriciler topolojinin tamamına sahiptir ve sink tree'yi bu bilgi üzerinden dağıtık olarak hesaplar. Her biri aynı hesabı kendi bakış açısıyla yapar ve kimin kimin üzerinden bağlı olduğunu bilir. Bu yüzden uzaklık vektöründeki sonsuza sayma durumunun oluşma şansı yoktur.

Yük de dağıtılmıştır: bir merkezin bütün yönlendiriciler için sink tree'yi ayrı ayrı hesaplayıp dağıtması gerekmez; merkezi yapıda ek işlemci gücüne ve belleğe ihtiyaç vardır. Bilgi dağıtılır ve sink tree hesaplanır; ağ sıra numaralarıyla eşzamanlanmış, sıra numaralarının ulaşma hızına bağlı "yarı eşzamanlı" bir biçimde çalışır.

Burada önemli tek ölçüt güncellemenin ne sıklıkla yapılacağıdır. Çok sık güncelleme yapılırsa flooding tarafı ağır basar ve bağlantı durumu değil flooding yapılıyormuş gibi olur. Çok seyrek yapılırsa ağdaki değişikliklerden haberdar olunmaz. Bu ayar ağın büyüklüğüne, altyapısına, kullanılan teknolojilerin güvenilirliğine ve hata oranlarına, yönlendiricilerin açılıp kapanma, yeniden başlama ve çökme sıklığına bağlıdır. Hoca yerel ağlar için OSPF dokümanlarında bu değerin 3 saniye olarak verildiğini, IS-IS'te sistemler arası hiyerarşik yönlendirmede ağın boyutuna, hatların hızına ve güvenilirliğine göre çok daha uzun olabileceğini söyledi.

> **Ders sonrası not:** OSPF'te yayın ağlarında varsayılan Hello aralığı büyük olasılıkla 10 saniye, LSA'ların periyodik yenilenme süresi büyük olasılıkla 30 dakikadır; derste söylenen 3 saniye bu değerlerle örtüşmüyor.

## 10. Hiyerarşik Yönlendirme

Dersin başındaki İstanbul-Ankara örneği burada yeniden kullanıldı: İstanbul'dan yola çıkarken Ankara'daki bir yolu buradaki birine sormazsınız; önce Ankara'ya gidersiniz, sonra Ankara'da yolu sorarsınız. Yönlendirmede de bu mantık uygulanmalıdır.

Slayttaki ilke (ekrandan, 01:35:00): "Hiyerarşik yönlendirme rota hesaplama işini azaltır ama düz (flat) yönlendirmeye göre biraz daha uzun yollara yol açabilir."

### 10.1 Sayısal örnek

**Verilen:** Topolojide beş bölge (region) vardır. Bölgelerdeki yönlendirici sayıları: Bölge 1'de 3 (1A, 1B, 1C), Bölge 2'de 4 (2A, 2B, 2C, 2D), Bölge 3'te 2 (3A, 3B), Bölge 4'te 3 (4A, 4B, 4C), Bölge 5'te 5 (5A, 5B, 5C, 5D, 5E).

**İşlem:** $3 + 4 + 2 + 3 + 5 = 17$ yönlendirici.

**Sonuç:** Düz yönlendirmede Bölge 1'deki 1A, kendi bölgesinde yalnız 3 yönlendirici olmasına rağmen 17 yönlendirici için bilgi tutar; 14'ü gereksizdir. Üstelik bu yönlendiricilerin bilgisinin 1A'ya ulaşması ve komşulara aktarılması gerekir. Böylece LSP'ler büyür, bant genişliği kaybedilir; trafik paket aktarmak için değil, yönlendirme algoritmasının ihtiyaçları için harcanır. Bölge 1'in kendi içinde yönlendirme yaparken bilmesi gereken tek şey, dışarı çıkmak için iki seçeneği olduğudur: 1B ya da 1C.

1A'nın tam (flat) tablosu (ekrandan, 01:35:00):

| Hedef | Hat | Hop |
|---|---|---|
| 1A | – | – |
| 1B | 1B | 1 |
| 1C | 1C | 1 |
| 2A | 1B | 2 |
| 2B | 1B | 3 |
| 2C | 1B | 3 |
| 2D | 1B | 4 |
| 3A | 1C | 3 |
| 3B | 1C | 2 |
| 4A | 1C | 3 |
| 4B | 1C | 4 |
| 4C | 1C | 4 |
| 5A | 1C | 4 |
| 5B | 1C | 5 |
| 5C | 1B | 5 |
| 5D | 1C | 6 |
| 5E | 1C | 5 |

1A'nın hiyerarşik tablosu:

| Hedef | Hat | Hop |
|---|---|---|
| 1A | – | – |
| 1B | 1B | 1 |
| 1C | 1C | 1 |
| 2 | 1B | 2 |
| 3 | 1C | 2 |
| 4 | 1C | 3 |
| 5 | 1C | 4 |

Tablo 17 satırdan 7 satıra iner; hoca bunu yaklaşık 2,5 kat küçülme olarak ifade etti ($17/7 \approx 2{,}43$). Slayttaki işarete göre Bölge 5 için seçilen 1C hattı, 5C dışındaki Bölge 5 düğümleri için en iyi seçimdir; tam tabloda 5C'ye 1B üzerinden gidilir. Bu, hiyerarşik yönlendirmenin bazen biraz daha uzun yol vermesinin örneğidir. Topoloji büyüdükçe ve bölge sayısı arttıkça hiyerarşik yönlendirme daha da verimli hale gelir.

Hiyerarşik yönlendirmenin söylediği şudur: bulunduğun bölgeyle ilgili yönlendirme bilgisini en ince ayrıntısıyla tut; diğer bölgelerin içini bilmene gerek yok, yalnız o bölgelere nasıl gideceğini bil. İnternette TCP/IP ayrıntılarına girildiğinde tamamen hiyerarşik yönlendirme uygulandığı görülecektir. Hoca kampüs örneği de verdi: kampüsteki başka bir fakültenin içindeki her ayrıntıyı bilmezsiniz; kendi fakültenizi, kendi bölümünüzü bilirsiniz, başka yere gidince sorarak öğrenirsiniz.

Özetle bir yanda LSP kullanan bağlantı durumu yönlendirmesi (OSPF, IS-IS), diğer yanda hiyerarşik yönlendirme vardır.

## 11. Broadcast, Multicast ve Anycast Yönlendirme

### 11.1 Broadcast yönlendirme ve reverse path forwarding

Broadcast, bir bilginin bütün düğümlere gönderilmesidir. Bilgi ağda her yere yayılırken üzerinden geçtiği düğümlerin bilgisi pakete eklenirse, son gittiği yerden geriye doğru yol bulunmuş olur. Hoca bunu Hansel ile Gretel masalındaki ekmek kırıntılarına benzetti: gidilen yola kırıntı bırakılır, dönüşte kırıntılara bakılır. Hiç gitmediğiniz bir yere bir arkadaşınız gidip dönmüşse, ona nasıl gittiğini sorarsınız ve size tarif eder.

Önce bilginin ileri yönde yayılması (broadcast, yani flooding'in teknik terimle ifadesi), sonra yolun geri yönde oluşturulması gerekir. Bu yöntem **reverse path forwarding** olarak bilinir: geri dönüşte oluşturulan yol, paketleri ileri göndermek için kullanılır. Önce broadcast edilir, sonra geri dönüşler toplanır ve herkes bunlar üzerinden yollarını bulur.

> **Ders sonrası not:** Reverse path forwarding'in kitaptaki tanımı büyük olasılıkla şöyledir: bir broadcast paketi yönlendiriciye, yönlendiricinin kaynağa paket gönderirken kullandığı hattan gelmişse yönlendirici paketi diğer bütün hatlara iletir; başka bir hattan gelmişse paketi büyük olasılıkla kopya sayıp atar.

### 11.2 Multicast yönlendirme

Broadcast bilginin herkese, multicast ise bir alt kümeye gitmesidir. Slayttaki tanım (ekrandan, 01:45:00): "Multicast, grup denen bir düğüm alt kümesine gönderir; her grup ve kaynak için farklı bir ağaç kullanır." İnternet için geliştirilmiş multicast protokollerinde "grup" kelimesi görülürse, multicast'in hedef alt kümesi kastedilir.

Slayttaki yoğun (dense) durum örneğinde düğümlerin bir kısmı grup 1'e, bir kısmı grup 2'ye, bir kısmı her ikisine (1, 2) aittir. Şekiller sırasıyla şunları gösterir:

- Grup 1 ve 2 üyeleri olan ağ.
- S kaynağından kurulan yayılan ağaç (spanning tree).
- S'den grup 1'e multicast ağacı: yayılan ağaçtan yalnız grup 1 üyelerine giden dallar kalır.
- S'den grup 2'ye multicast ağacı: yayılan ağaçtan yalnız grup 2 üyelerine giden dallar kalır.

Her kaynak ve her grup için ayrı bir sink tree oluşturmak gerekir.

**Seyrek (sparse) durum:** Bazen gruplar az üyelidir. Hoca bunu seyrek matrislere benzetti: elemanların çoğu sıfır, azı sıfırdan farklıdır. Bu durumda her kaynak için ayrı ağaç kurmak yerine bir omurga kurulur; buna **çekirdek (core)** denir. Ağaç, mümkün olduğunca bütün üyelere dokunacak, yakınlarından geçecek şekilde kurulur.

**Soru:** Ağaç ile grafın farkı nedir? **Cevap:** Ağaçta kapalı çevrim (döngü) yoktur ve ağaç bir noktadan başlayıp diğer noktalara doğru ilerler.

Slaytta göndericinin konumu iki senaryoyla gösterildi: <!-- BELİRSİZ: Sparse case (core-based tree) slaytı karelerde yok; anlatım altyazıdan alındı. -->

- Gönderici çekirdeğe bir hop uzaklıktaysa paketi doğrudan çekirdeğe gönderir. Çekirdek paketi ağaç üzerinde hop hop multicast eder; her üyeye ayrı ayrı mesaj göndermez.
- Gönderici çekirdeğe iki hop uzaklıkta ama ağaç üzerindeki bir düğüme daha yakınsa paketi o düğüme gönderir. O düğüm paketi bir yandan ağaçta kendi tarafına iletirken, diğer yandan çekirdeğe iletir. Çekirdek paketi ağacın diğer tarafına dağıtır ama paketi kendisine gönderen düğüme geri göndermez, çünkü o düğüm paketi kendi tarafındaki düğümlere zaten göndermiştir.

### 11.3 Anycast yönlendirme

"Any" herhangi bir demektir: broadcast herkese, multicast bir gruba, anycast ise herhangi bir taneye gider. Slayttaki tanım (ekrandan, 01:50:00): "Anycast, bir paketi grubun bir (en yakın) üyesine gönderir; bir düğümün birçok yerde bulunduğu durumda normal yönlendirmeden kendiliğinden çıkar." Slaytın solunda grup 1'e anycast rotaları (her düğüm en yakın grup 1 üyesine yönelir), sağında grup 1 üyelerinin tek bir "1 düğümü" gibi göründüğü görünür topoloji ve bu düğüme giden sink tree vardır.

Hoca bunu şöyle örnekledi: ders saatinin gecikeceğini sınıftaki herkese tek tek söylemek yerine öğrencilerden herhangi birine söylenir, o da diğerlerine yayar. Hocaların herhangi birine söylemesi kısmı anycast'tır.

Kullanım alanları:

- **Coğrafi anycast (geo-anycast):** Araçlar arası haberleşmede bir araç kaza yaptığında ya da frene bastığında bu bilginin otobanda arkasındaki araçlardan herhangi birine gitmesi yeterlidir; o araç bilgiyi diğerlerine aktarır.
- **Yük dengeleme ve hata toleransı:** Birbirine eşdeğer çalışan bir DNS sunucu grubunda herhangi birine gelen sorgunun cevabı aynıdır. Sorgu hep aynı sunucuya gönderilmek yerine anycast adresine gönderilir; sorgular sırayla farklı sunuculara gider. Böylece yük dengeleme ve hata toleransı sağlanır.

## 12. Ad Hoc Ağlarda Yönlendirme ve Sonraki Konu

Listedeki "mobil hostlar için yönlendirme" konusuna bu derste girilmedi; ilgili konu geldiğinde ayrıca konuşulacağı söylendi.

Ad hoc ağlarda, örneğin kablosuz algılayıcı ağlarında AODV gibi protokoller kullanılır. Hoca bunu, kapatılıp kenara konmuş algoritmaların yeni bir teknoloji ve yeni koşullar altında yeniden karşımıza çıkmasının örneği olarak verdi. Uzaklık vektöründeki sonsuza sayma, düğümlerin bir ip gibi art arda dizildiği ve birbirine bağlı olduğu durumlarda ortaya çıkıyordu. Algılayıcı ağlarında arada kablolu hat yoktur, haberleşme tamamen kablosuzdur ve düğümlerin böyle bağlanma ihtimali çok düşüktür. Uzaklık vektörünün yükü hafif ve kendisi basit olduğu için algılayıcı ağlarında kullanılabilir.

> **Ders sonrası not:** Hoca AODV'yi "ad hoc distance vector" diye açtı; doğrusu "Ad hoc On-demand Distance Vector"dür.

Ad hoc ağlar "tasarısız" ağlardır: kim kiminle bağlanacak önceden kağıt üzerinde hesaplanmaz, topoloji çizilmez. Ağı oluşturan düğümler açıldıkları anda kablosuz bağlantılarla ağın parçası olur ve komşularını sanal olarak belirler; böylece kablosuz linkler oluşur.

Ders, ağ katmanında tıkanıklık kontrolünün (congestion control) giriş slaytıyla kapandı (ekrandan, 01:55:00): tıkanıklığı yönetmek ağ ve taşıma katmanlarının birlikte sorumluluğudur ve burada ağ katmanı kısmına bakılacaktır. Alt başlıklar traffic-aware routing, admission control, traffic throttling ve load shedding'dir. Konuya sonraki derste devam edilecektir.

> **Ek bilgi (derste anlatılmadı):** Ders boyunca kullanılan slaytlar, Tanenbaum ve Wetherall'ın "Computer Networks" kitabının 5. baskısının ağ katmanı bölümüne aittir (slayt altbilgisinden). Slaytlar kitaptaki bilginin küçük bir kısmını özetler.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:56:28): J düğümüne A'dan gelen vektör A 0, B 12, C 25, D 40, E 14, F 23, G 18, H 17, I 21, J 9, K 24, L 29'dur. Bu vektördeki değerlerin hangileri A için güvenilirdir?

> **Çözüm:** Yalnız A'nın kendisine (0) ve doğrudan komşularına olan uzaklıklar A tarafından doğrudan ölçülebilir; hoca kendisi dahil dört değer saydı. Diğer bütün değerler komşulardan gelen vektörler üzerinden hesaplanmıştır ve A bunların hangi yol üzerinden oluştuğunu bilmez. <!-- BELİRSİZ: Komşuların hangileri olduğu altyazıda net değil. -->

**Soru 2** (derste sözlü, 00:57:28): J'nin komşularına gecikmeleri A 8, I 10, H 12, K 6'dır. Komşuların B'ye bildirdiği uzaklıklar A 12, I 36, H 31, K 28'dir. J'nin B'ye yeni uzaklığı ve çıkış hattı nedir? "En düşüğü hangisi çıktı?"

> **Çözüm:** $8+12=20$, $10+36=46$, $12+31=43$, $6+28=34$. En küçüğü 20'dir; çıkış hattı A'dır.

**Soru 3** (derste sözlü, 00:57:50): Aynı gecikmelerle, komşuların C'ye bildirdiği uzaklıklar A 25, I 18, H 19, K 36 ise J'nin C'ye yeni uzaklığı nedir?

> **Çözüm:** $8+25=33$, $10+18=28$, $12+19=31$, $6+36=42$. En küçüğü 28'dir; çıkış hattı I'dır.

**Soru 4** (ekrandan, 00:30:00 ve derste sözlü, 00:36:15): B için sink tree'de, bütün ağırlıklar eşit (hop) alındığında B ile M ve B ile E arasındaki en kısa yollar kaç hoptur?

> **Çözüm:** B-C-J-N-M yolu 4 hoptur; B-C-J-E yolu 3 hoptur.

**Soru 5** (derste sözlü, 01:46:36): Ağaç ile grafın farkı nedir?

> **Çözüm:** Ağaçta kapalı çevrim yoktur ve ağaç bir noktadan başlayıp diğer noktalara doğru ilerler.

## Dersin Toparlaması

Bu derste ağ katmanında yönlendirme algoritmaları işlendi. Önce yönlendirme (yolu bulma kararı) ile iletme (kararın uygulanması) ayrıldı ve optimallik ilkesiyle her düğümün kendi sink tree'sine sahip olduğu gösterildi. Dijkstra'nın en kısa yol algoritması hatırlatıldı ve ağırlıkların mesafe değil maliyet olarak düşünülmesi gerektiği vurgulandı. Flooding en güvenilir ama en yükleyici yöntem olarak tanıtıldı ve basit iyileştirmelerle nasıl kontrollü hale getirildiği gösterildi. Uzaklık vektörü yönlendirmesinin dağıtık yapısı sayısal bir örnekle anlatıldı; sonsuza sayma sorunu ve 16 hop sınırı tartışıldı. Ardından bu sorunun oluşmadığı bağlantı durumu yönlendirmesi (LSP'ler, sıra numarası ve age alanları, OSPF ve IS-IS), yönlendirme tablolarını küçülten hiyerarşik yönlendirme ve broadcast, multicast, anycast yönlendirme türleri işlendi.

Ad hoc ağlarda uzaklık vektörünün yeniden kullanılmasıyla eski algoritmaların yeni koşullarda geri döndüğüne değinildi. Sonraki derste ağ katmanında tıkanıklık kontrolüne devam edilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
