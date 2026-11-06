# Ders 10 Genişletilmiş Notu: Çevik Ekipler, Blok Zinciri ve Endüstri 4.0 Üzerine Makale Sunumları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Proje Planı ve Gereksinim Analizi Dokümanlarının İçeriği
- 2. 1. Sunum: Hibrit Çevik Ekiplerde Uzaktan Çalışma ve İş Birliği
- 3. 2. Sunum: Çevik Projelerde Benimseme Etmenleri ve Kritik Başarı Faktörleri
- 4. 3. Sunum: Blok Zinciri Platformu İçin Proje Yönetimi Modeli
- 5. 4. Sunum: Endüstri 4.0'ın Proje Takımlarından Beklentileri
- 6. 5. Sunum: Scrum'ın Yazılım Proje Yönetimine Etkisi

## 1. Proje Planı ve Gereksinim Analizi Dokümanlarının İçeriği

Dersin büyük bölümü öğrencilerin makale sunumlarına ayrıldı. Hoca sunumlardan önce, dönem boyunca gördüğümüz planlama konularını uygulamaya bağlayan bir çerçeve çizdi. Bir öğrencinin sorusu üzerine, bir yazılım projesinin başlangıç aşamalarında hangi dokümanların nasıl hazırlanacağını açıkladı. Hocaya göre bu, belli bir konuda proje planı ve gereksinim analizi yapılan standart bir çalışmadır.

**Soru:** Projede istenen dokümanlar ve içermesi gereken başlıklar nelerdir?

**Cevap:** Hoca önce proje planını ele aldı. İçerik olarak IEEE'nin proje planı standardı esas alınır. Plan bir proje yönetim yazılımı (paketi) kullanılarak çizilir. Derste MS Project üzerinden gidilmişti, ama başka bir program da kullanılabilir. Önemli olan planın bir proje yönetim aracıyla oluşturulmasıdır. Proje planında neler olması gerekiyorsa hepsi yer alır. Gereksinim analizi yapıldığı için bir de SRS (Software Requirements Specification, yazılım gereksinimleri belirtimi) dokümanı hazırlanır.

> **Ek bilgi (derste anlatılmadı):** Derste standardın numarası söylenmedi. Yazılım proje yönetimi planı için sık anılan standart büyük olasılıkla IEEE 1058'dir. SRS içeriği için de büyük olasılıkla IEEE 830 kullanılır. Bu standartlar sonradan büyük olasılıkla ISO/IEC/IEEE ortak standartlarıyla güncellenmiştir.

SRS dokümanının içeriği seçilen geliştirme yaklaşımına göre değişir:

- **Yapısal yaklaşım (structured approach):** Gereksinimler veri akış diyagramları (data flow diagram) ile gösterilir.
- **Nesne yönelimli yaklaşım (object-oriented approach):** Gereksinimler use case diyagramları ve use case belgeleriyle oluşturulur.

Hoca ardından bu dokümanların hangi sırayla ve hangi süreç mantığıyla birbirine bağlandığını anlattı. Proje planlamadan önce anlama ve tanımlama aşamaları vardır. Bu aşamaların bilgileri plandan önce verilmelidir. Akış şöyledir:

- Proje anlaşılır.
- Proje tanımlanır.
- Projenin planı yapılır.
- Gereksinim analizi sırasında plan bir miktar takip edilir.

Son madde önemlidir. Gereksinim analizine kadar gelindiği için planın nasıl güncellendiği ve nasıl takip edildiği de o noktaya kadar gösterilmelidir.

> **Hocanın vurgusu:** Yalnızca bir plan çizmek yetmez. Anlama ve tanımlama bilgileri plandan önce verilmeli, planın gereksinim analizine kadar nasıl güncellenip takip edildiği de gösterilmelidir.

## 2. 1. Sunum: Hibrit Çevik Ekiplerde Uzaktan Çalışma ve İş Birliği

### 2.1 Konu ve Amaç

İlk sunumda bir öğrenci, çevik (agile) takımlarda uzaktan çalışma ve iş birliği (remote working and collaboration) üzerine bir makale anlattı. Makale 2016 tarihlidir ve Amerika'da yazılmıştır. Sunucu konunun güncelliğini pandemiyle bağladı. Pandemi nedeniyle birçok yazılım firması ve bankacılık sektörü uzaktan çalışmaya geçti, bugün ekiplerin çoğu tamamen uzaktan çalışıyor. Makalenin incelediği durum ise biraz farklıdır: Ekibin bir veya iki kişisi uzaktan çalışır, geri kalanı şirket içinde birlikte çalışır.

Makalede analiz üç açıdan yapılıyor:

- Sanal eserler (virtual artifacts).
- Bilgi akışı (information flow), yani bilginin internet platformları üzerinden nasıl taşındığı.
- İş birlikçi platformlar (collaborative platforms).

İncelemede uzaktan çalışanın ve onunla aynı ekipteki arkadaşlarının bakış açıları da, ekibin ne kadar süredir birlikte çalıştığı da, uzaktan çalışan kişilerin şirket kültürüne ne kadar hâkim olduğu da dikkate alınıyor.

### 2.2 Arka Plan: Çevik Yaklaşım ve Dağıtık Ekipler

Sunucu, önceki hafta çevik yaklaşım çokça anlatıldığı için bu kısmı kısa geçti. Çevik Manifesto (Agile Manifesto) 2001 yılında yayımlandı. Yaklaşık 17 yazılımcı bir araya gelerek proje süreçlerinin nasıl daha iyi yapılabileceğine dair bir fikir ortaya attı.

Çevik yaklaşım şelale (waterfall) anlayışıyla karşılaştırıldı. Şelalede proje alınır, bitene kadar çalışılır, bittikten sonra isteyenlere "projeyi yaptık, buyurun" denir. Çevikte ise sürekli iş birliği, çalışan yazılımın düzenli teslimi ve değişime hızlı yanıt vardır. Sunucunun verdiği gerekçe şuydu: Teknoloji çok hızlı değişiyor. Proje üzerindeki değişiklikler teknolojiyle orantılı yapılırsa, proje hayata geçtiğinde teknolojinin gerisinde kalmaz ve daha verimli olur.

Dağıtık ekipler iki tür olarak ele alınıyor:

- **Tamamen dağıtık ekipler:** Üyelerin hepsi farklı yerlerde, tek başına çalışır. Bugün pek çok ekibin içinde bulunduğu durum budur.
- **Karma (hibrit) ekipler:** Bazı üyeler aynı yerde, bazıları uzaktan çalışır. Makalenin incelediği yapı budur.

Makale üç soruya cevap arıyor:

- Karma bir çevik ekip hangi sorunlarla karşı karşıya kalıyor?
- Uzaktan çalışanı olan hibrit bir çevik ekip nasıl iş birliği yapabilir?
- Uzaktan çalışanın deneyimi, aynı yerde bulunan ekip arkadaşlarınınkiyle nasıl karşılaştırılır? Yani uzaktan çalışan ne kadar verimli olabiliyor, aynı yerdekiler ne kadar verimli olabiliyor?

### 2.3 Küresel Yazılım Mühendisliği Literatüründeki Sorunlar

Dağıtık çevik ekipler için küresel yazılım mühendisliğine (Global Software Engineering, GSE) odaklanan bir literatür vardır. Bu literatürde Scrum uygulamalarının sistematik incelemesi şu başlıkları öne çıkarıyor: iletişim, iş birliği, araç desteği ve büyük ekipler.

- **Büyük ekipler ve iletişim:** Sunucuya göre çevikliğin en büyük sorunlarından biri büyük ekiplerdir. Ekip içi iletişim zorluğu kültür ve dil farklarından da kaynaklanabilir. Hem kültür farkı hem dil sorunu olan büyük bir ekip için süreç oldukça zorlaşır. Bu sorunlar yavaş ve güvenilmez bir iletişim ortaya çıkarır.
- **İş birliği araçları:** Ekibin birbirini takip edebilmesi için görev panoları (task board), hata izleyiciler (bug tracker) ve biriktirme listesi (backlog) araçları gerekir. Backlog, elimizdeki işin ne olduğunu ve o iş bitince sırada hangi işlerin geldiğini gösterir.
- **Saat dilimi farkı:** İki kişi farklı saat dilimlerinde çalışıyorsa ve işleri birbirine bağlıysa doğal olarak sorun yaşarlar.

### 2.4 Çevik Pratikler

Çevik metodolojinin iletişimi ve ekip içi sürekliliği sağlamak için belli kuralları vardır. Sunucu bunların şirketten şirkete, hatta ekipten ekibe esnetilebileceğini söyledi. Sayılan pratikler şunlardır:

- **Günlük stand-up toplantısı:** Saatini ve ortamını ekip kendisi belirler.
- **Sprint:** Ortalama 2-3 hafta olarak planlanan, bir hedefin konduğu süreçtir. "Bu sprintte bunu çalışacağız, bu hedefi gerçekleştireceğiz" denir.
- **Sürekli entegrasyon (continuous integration).**
- **Sprint planlama.**
- **Retrospektif:** Ekibin kendini değerlendirdiği toplantıdır. Bu sprintte neyi iyi yaptık, neyi daha iyi yapabiliriz, nerede iyiyiz gibi sorular cevaplanır.
- **Sprint incelemesi (sprint review):** Genelde proje sahibiyle de yapılması öncelikli olan toplantıdır. Hangi işler alındı, hangileri tamamlandı, hangileri tamamlanamadı, önümüzdeki ve proje sahibinin çözmesi gereken engeller neler, bunlar konuşulur.
- **Test odaklı geliştirme (test-driven development) ve Scrum of Scrums.**

<!-- BELİRSİZ: 00:15:17 civarında "sprintler ve iğnelemeler" geçiyor; "iğneleme" teriminin slayttaki karşılığı altyazıdan anlaşılmıyor. Olasılıkla sprint incelemesidir. -->

### 2.5 Uzaktan Çalışmanın Günlük Yüzü

Sunucu, uzaktan çalışmayı gösteren klasik fotoğraflar üzerinden fiziksel koşullara da değindi. Sürekli çevrim içi toplantıdayız, sabit duramıyor, farklı pozisyonlarda çalışıyoruz. Rahat olmayan bir ortam fiziksel sorunlara da yol açıyor. Sunucunun gözlemine göre şirketler çalışanların evden çalışma konforunu sağlamak için ellerinden geleni yapıyor.

Dağınık ekiplerle birlikte konumlanmış (co-located) ekipler şöyle karşılaştırıldı:

- **Birlikte konumlanmış ekipler:** Ekip sürekli aktif olarak konuşmaya, kendi içinde tartışmaya yatkındır. Arada bir sosyal mecra olmadığı için bilgi akışı daha basit ve açıktır. Toplantı planlamaya gerek yoktur. Bir iş, en basitinden bir çay molasında konuşulup sonuca bağlanabilir. Sosyal yapılar daha basit, iletişim daha kolaydır.
- **Dağınık ekipler:** Üyeler birbirleriyle daha çok sosyal mecralar üzerinden konuşur, bu yüzden ekibin yaptığı işler daha az anlaşılır hale gelir. Bir şey konuşmak için saat ve platform belirlemek gerekir. Uyum yoksa en büyük sorun budur: Birbirine ulaşamama, birbirinden haber alamama, işler birbirine bağlıysa projenin ilerleyişinde sorun yaşama.

Dağınık ekiplerde bir sorumluluk kayması da oluşur. Fiziksel olarak birlikte çalışırken yandaki arkadaş bazı konularda destek olabilir. Uzaktan çalışan ise ekibe bilgi verme sorumluluğunu artık kendisi üstlenmek zorunda kalır. Neyin, ne zaman ve hangi yolla paylaşılacağına ekip birlikte karar verebilir.

### 2.6 İncelenen Vaka

Makalede bir takım seçilmiş. Takımın bileşimi şöyle verildi:

- Bir Scrum ustası (Scrum Master).
- İki geliştirici. Bunlardan biri uzaktan çalışıyor.
- Yarı zamanlı (part-time) iki test mühendisi.
- Diğer takımlarla paylaşılan bir ürün sahibi (product owner). Ürün sahibi araştırmaya dahil edilmemiş.

> **Ders sonrası not:** Altyazıda takım iki kez "20 kişilik" diye geçiyor. Ancak sayılan roller 1 + 2 + 2 = 5 kişi, ürün sahibiyle 6 kişi ediyor. Bu sayı büyük olasılıkla altyazı hatasıdır, slayttan doğrulanamadı.

Ekipte tek dil İngilizce kullanılıyor ve herkes aynı saatlerde çalışıyor, farklı saat dilimi yok. Herkesin tüm toplantılara katılmasına özen gösteriliyor: gün içi toplantılar, ekip içi toplantılar, başka ekiplerle yapılan toplantılar. Uzaktan çalışan kişi de belli aralıklarla ofise giderek fiziksel temas kuruyor ve böylece ekibin iletişimi güçleniyor.

Kullanılan araçlar bir liste halinde özetlenmiş:

| Araç | Kullanım amacı |
|---|---|
| Jira | Sprint planlama, hata çözümü, proje takibi, kullanıcı hikâyelerinin (user story) ve görevlerin takibi |
| Bitbucket | Çevrim içi git deposu, kod iş birliği |
| Planning poker odaları | Sprintteki görevlerin zorluğunu ekipçe tahmin etme |
| Webex | Çevrim içi toplantı ve konferans |
| HipChat | Sohbet ve anında mesajlaşma |
| SourceTree | Git kod deposu için istemci |
| MySQL | Veri tabanı |
| E-posta ve takvim | E-posta ve takvim görünümü |
| Skype kurumsal, Appear.in | İletişim ve toplantı |
| PhpStorm | Entegre geliştirme ortamı |

Sunucu planning poker'ı şöyle anlattı: Fibonacci sayılarından oluşan bir sistemle, ekip her görev için "bu görevin zorluğu budur" diyebilir ve görevin zorluğuna ortak karar verir. Jira'dan bir görev panosu örneği ile bir kod incelemesi (code review) örneği de gösterildi.

> **Ek bilgi (derste anlatılmadı):** Planning poker'da her üye tahminini aynı anda açar. Böylece ilk konuşanın tahmini diğerlerini etkilemez. Tahminler farklıysa en düşük ve en yüksek tahmini verenler gerekçelerini anlatır, sonra oylama tekrarlanır. Fibonacci dizisinin kullanılmasının nedeni, iş büyüdükçe tahmindeki belirsizliğin de artmasıdır.

### 2.7 Veri Toplama: Grup Tartışması

Ekip üzerinde çalışmadan önce şirketin kültürü ayrıntılı olarak araştırılmış. Çünkü her şirketin uzaktan ve fiziksel çalışmada kendi kültürüne bağlı farklılıkları olabilir.

Sonra bir grup tartışması yapılmış. Yazarlar kendilerine bir çevik çalışma planı kurmuş, adeta bir sprint koşmuş. Platform üzerinden, kimin ne yazdığı belli olmayan bir sistem açılmış ve herkes yorumunu oraya yazmış. Dört soru sorulmuş:

- Neyi iyi yapıyoruz?
- Neyi yeniden düşünmemiz, revize etmemiz gerekiyor?
- Yapmadığımız neyi yapmalıyız?
- Önümüzdeki engelleyiciler neler?

Yazarlar birinci sorudan çok diğer üçü üzerinde durmuş. Çıkan yanıtlar şöyle:

- **Revize edilmesi gerekenler:**
  - Uzaktan eşli programlama (pair programming) oldukça zahmetli.
  - Büyük gruplu toplantılar zayıf iletişime yol açıyor.
  - Farkındalık açısından birden fazla kesinti, meşgul olma ve birbirine uyum sağlayamama durumları ortaya çıkıyor.
  - Bilgi paylaşımı için beyaz tahtada fikir paylaşma önerilmiş.
- **Yapmadığımız, yapmamız gerekenler:**
  - Eşli programlama. Süreçte var ama uygulanamıyor.
  - Çevrim içi bir kahve molası. Üyeler yalnız iş için değil, şirkette yaptıkları çay kahve molası gibi de iletişim kurmak istiyor.
- **Engelleyiciler:**
  - Büyük gruplar arasındaki zayıf iletişim.
  - Mevcudiyet bilinci ve arka plan farkındalığı, yani kişilerin şirket kültürüne ve süreçlerine ne kadar hâkim olduğu.

> **Ders sonrası not:** Sunucu bu tartışmayı "sprint incelemesi" olarak adlandırdı. Oysa kendi tanımına göre ekibin kendini değerlendirdiği toplantı retrospektiftir ve burada sorulan sorular da retrospektif sorularına benziyor.

### 2.8 Veri Analizi: DiCoT Çerçevesi

Verilerin analizinde DiCoT adlı bir yaklaşım kullanılmış. Sunucu bunu bağlamsal tasarımdan gelen ve dağıtık biliş (distributed cognition) ilkelerine dayanan bir çerçeve olarak tanımladı. Beş teması vardır: fiziksel düzen, bilgi akışı, eserler (artifacts), zaman içinde evrim ve sosyal yapılar. İletişimi öne çıkaran bir yaklaşımdır.

> **Ek bilgi (derste anlatılmadı):** DiCoT, Distributed Cognition for Teamwork ifadesinin kısaltmasıdır. Dağıtık biliş yaklaşımı, bir işin bilgisinin yalnızca kişilerin zihninde değil, kişiler, araçlar ve ortam arasında dağılmış olduğunu kabul eder. DiCoT bu fikri ekip çalışmasını incelemek için bir dizi temaya dönüştürür.

Sunucu temaları yüzeysel olarak şöyle özetledi:

**Fiziksel düzen.** Mekân, aktiviteyi desteklemek için kullanılır. Örneğin fiziksel ortamda sprintler ve görevler bir pano üzerinden yönetilebilir. Bu temanın kavramları algısal olma, doğallık, durum bilinci, gözlem ufku ve ekipmanın düzenlenmesidir. Gözlem ufku, bireyin görebildiği, duyabildiği ve fiziksel olarak farkında olabildiği alandır. Sunucunun örneği şöyleydi: Bir projede ilerlemekte sorun yaşıyorsunuz. Uzaktan çalışıyorsanız bunu ağırlıklı olarak kendi başınıza çözmek zorundasınız. Fiziksel ortamda ise yanınızdaki kişiyle iki dakikalık bir sohbet bakış açınızı değiştirip sizi çözüme daha hızlı götürebilir.

**Bilgi akışı.** Bu temanın kavramları şunlardır:

- Bilginin hareketliliği ve dönüşümü.
- Bilginin merkezi.
- Tamponlar: Bilginin faaliyette kesintiye yol açmadan tutulduğu yerler.
- İletişim bant genişliği: Resmi ve gayri resmi iletişimin ne kadar olduğu.
- Davranışsal tetikleyiciler: Bilgi akışının plansız gerçekleşmesi. Tıkandığımız yerde yanımızdaki arkadaştan bilgi almak buna örnektir.

**Eserler.** Aktiviteleri gerçekleştirmek için aracılık eden materyallerdir. Beyaz tahta üzerinde yapılan çalışma buna örnek verildi. Uzaktan çalışan bir kullanıcının çalışma düzeni de gösterildi: Yazılımcılar bazen çift ekran kullanabiliyor. Uzaktan çalışırken iletişim öncelikli olduğu için kullanıcı bir ekranda iletişimi sağlıyor, bir ekranda e-postalarını kontrol ediyor, bir ekranda kendi geliştirmesini yapıyor.

<!-- BELİRSİZ: Zaman içinde evrim ve sosyal yapılar temaları sunum süresi dolduğu için ayrıntılı anlatılmadı. Hoca 00:28:45'te sunucudan toparlamasını istedi. -->

### 2.9 Sonuçlar

Karma ekipte uzaktan çalışan ile aynı yerdekiler arasındaki iş birliğinin biraz daha zayıf ilerlediği bulunmuş. Fark azdır. Sunucuya göre en büyük avantaj, incelenen kişilerin şirket kültürüne ve süreçlerine hâkim olmasıdır. Bu sayede birlikte çalışanlarla uzaktan çalışan arasındaki iş birliği uyumlu yürüyor. Sunucu, kendi yorumu olduğunu belirterek şunu ekledi: Ekibe yeni katılan biri için uzaktan çalışmanın dezavantajları daha fazla olabilir.

<!-- BELİRSİZ: 00:28:58'deki karşılaştırma cümlesi altyazıda düzgün kurulmamış ("uzaktan çalışan bir ekibe göre"); karşılaştırmanın tam olarak hangi gruplar arasında yapıldığı net değil. -->

Uzaktan çalışan için makalenin ürettiği sonuçlar:

| Dezavantajlar | Avantajlar |
|---|---|
| Yalıtılmış (izole) olma | Verilen işe daha iyi odaklanma |
| Fiziksel olarak oluşan bilgi alanının dışında kalma | Kendisine sunulan bilgi setlerine daha hâkim olma |
| Resmi ve gayri resmi iletişim sorunları | Daha görünmez olduğu için stres altında hissetmeme |

İşletmelerin uzaktan çalışmayı benimsemesinin itici güçlerinden biri de uzmanlıktan yararlanmaktır. Şirketler bazı uzman kişilerden uzaktan danışmanlık alarak kendi proje süreçlerini ilerletebiliyor.

### 2.10 Hocanın Geri Bildirimi

Hoca sunumun ardından, belki birçok öğrencinin uzaktan çalıştığını hatırlatarak yaşanan özgül zorlukları sormak isteyenlere söz verdi. Soru gelmedi. Sonra makalenin tarihine dikkat çekti.

> **Hocanın vurgusu:** Makale 2016 tarihli. Uzaktan çalışma son yıllarda çok daha fazla kullanıldığı için 2020-2021 tarihli yayınlar çıkmış olabilir. Makale yazılırken bunlarla eşleştirme yapılması, özellikle son iki yılda hayata geçirilmiş deneyimleri içeren çalışmalarla bir ek yapılması iyi olur.

Sunucu da makaleyi yazarken güncel yayınlardan yararlanmak istediğini söyledi.

## 3. 2. Sunum: Çevik Projelerde Benimseme Etmenleri ve Kritik Başarı Faktörleri

### 3.1 Konu ve Yöntem

İkinci sunumu iki öğrenci birlikte yaptı. Konu, çevik projelerde benimseme etmenleri (adoption factors) ve kritik başarı faktörleridir (critical success factors). Sunumun ilk yarısı başarı faktörlerini, ikinci yarısı benimseme etmenlerini ve genel sonuçları anlattı.

İncelenen makale bir literatür taramasıdır. Araştırmacılar 32 yayını incelemiş. Bu yayınlardaki vaka çalışmaları, anketler ve röportajlar gibi farklı veri kaynaklarından yararlanmış. Hem başarı faktörlerini hem benimseme etmenlerini aynı üç boyutta değerlendirmişler.

Sunucu araştırmacılara göre Çevik Manifesto'nun dayandığı dört temel noktadan söz etmeye başladı, ama bu slayt geçildi.

> **Ek bilgi (derste anlatılmadı):** Çevik Manifesto'nun dört değeri şunlardır: süreçler ve araçlardan çok bireyler ve etkileşimler, kapsamlı dokümantasyondan çok çalışan yazılım, sözleşme pazarlığından çok müşteriyle iş birliği, plana uymaktan çok değişime yanıt verme. Manifesto, sağdaki öğelerin de değerli olduğunu, ama soldakilere daha çok değer verildiğini belirtir.

### 3.2 Üç Boyut: Proje, Takım, Kültür

Çerçeve, Agile Practice Guide adlı yayındaki üç boyuttur:

- **Proje:** Projenin yaşam döngüsü, değişimin yoğunluğu ve müşteriyle ilişkiler.
- **Takım:** Bireyler, ilişkiler ve kendi kendini yönetebilen ekipler.
- **Kültür:** Takımın içinde bulunduğu çevre, şirketin davranışları ve bunların çevikliğe adapte olabilme yeteneği.

Kültür boyutunun neden önemli olduğu bir çalışmayla gösterildi. Bu çalışmada çevikliğin uygulanmasının önündeki en büyük zorluğun şirket kültürü olduğu görülmüş. Araştırmaya katılan şirketler başarıyı müşteri tatmini ve üretilen ürünün değeri ile ölçüyor.

### 3.3 Kritik Başarı Faktörleri

Çevik projeler artımlı bir süreçle ilerler. Her süreçte müşterinin istekleri ön planda tutulur, ürün gerçekleştirilip müşterinin onayına sunulur. Bu süreci en uygun şekilde yürütmek için kritik başarı faktörlerine bakılır.

**Proje boyutu.** Projedeki başarı faktörleri stratejik başarılara ulaşmada önemli yer tutar. Çevik proje yönetiminin uygulanması mühendislik, üretim ve inşaat gibi alanlarda zorken yazılım, yazılım mimarisi ve yönetim bilimi gibi alanlarda basit ve etkili olabilir. Araştırmacılar önemli bir ayrım yapıyor: Uygun bir prototip bir sprintte tamamlanabilir, ama gerçek ürünün üretilmesi daha uzun sürebilir. Bazı aşamalarda sprint yeterli gelmez, iş genel bir sürece yayılmalıdır. Başarı böyle yakalanabilir.

<!-- BELİRSİZ: 00:35:36'da "BOK" diye geçen ifade, sprintin yetmediğini söyleyen kaynağın adı olabilir (PMBOK?); altyazıdan doğrulanamadı. -->

Proje boyutunda öne çıkan faktörler sırasıyla şunlardır:

- Dinamik ürün tanımı ve dinamik efor tahmini (%28).
- Sık değişimlere uyum.
- Ürün kabul kriterleri.
- Ürün teslimatındaki değişkenler.
- Müşteri memnuniyeti.

**Takım boyutu.** Sunucu takım planlamasıyla ilgili şu ilkeleri sıraladı:

- Biten sprintten görev kalırsa yeni sprint planı bu görev de gözetilerek yapılmalıdır.
- Kişi kaldırabileceği kadar yük almalı, ona uzmanlığına uygun görevler verilmelidir. Böylece efor tahmini olabildiğince doğru olur ve sprint daha etkin geçer.
- Görevler arası ilişkiler doğru kurulmalı ve planlama kapsamına alınmalıdır. Sunucu bunu çok önemli olarak niteledi.
- Engelleri en aza indirmek için görev uygun kişiye verilmeli, ihtiyaç halinde yardım alınacak kaynak önceden bilgilendirilmelidir.

Tablodaki takım faktörleri takım içi iletişim ve yardımlaşma (%15), görev dağılımı, takım uzmanlığı, üyelerin her an ulaşılabilir olması, müşteri memnuniyeti ve takımdaki liderliktir. Bunların yönetilmesi ve koordine edilmesi için liderlik ve yönlendirme yapabilecek bir kişi gerekir. Bu kişiye genelde Scrum Master denir. Sunucu %15'i çok önemli bir oran olarak yorumladı. Takım içi iletişim ve yardımlaşma olabildiğince artırılmalıdır.

**Kültür boyutu.** Bazı durumlarda farklı metodolojilerin uygulanmasının daha verimli olduğu görülmüş. Bazı projelerde çevik süreçlerden ayrılıp başka süreçlere geçmek daha uygun bulunmuş. Bu boyutta iki faktör öne çıkıyor:

- **Yönetimin katılımı (%9):** Yöneticilerin, müdürlerin ve gerekirse üst kademedeki kişilerin projeyi daha rahat takip edebilmesi için projede yer alması.
- **Çalışanların eğitimi (%2):** Değer küçük çıkmış. Sunucuya göre yine de çok önemlidir, çünkü çalışanların yetkinlik ve uzmanlığa ulaşması için yeterince eğitilmesi gerekir.

> **Ders sonrası not:** Sunumda bu yüzdeler "başarıyı şu oranda etkiliyor" diye verildi. Çalışma 32 yayını tarayan bir literatür incelemesi olduğu için bu oranlar büyük olasılıkla faktörün yayınlarda anılma payıdır, ölçülmüş bir etki büyüklüğü değildir. Bu, %2 çıkan eğitimin neden yine de önemli sayıldığını da açıklar. Slayttaki tablonun tanımı altyazıdan doğrulanamadı.

### 3.4 Benimseme Etmenleri

Araştırmacılar çevikliğin kurumda benimsenmesi için gerekli etmenleri yine proje, takım ve kültür bağlamında ele alarak 11 temel etmen belirlemiş.

**Proje boyutu.** En önemli etmen ürünün net tanımlanması ve efor tahmininin etkili yapılmasıdır (%17). Bunu üründe ve süreçte hızlı değişiklik yapabilme yeteneği ile artımlı teslimat izliyor. Ürün kalitesi de önemli bir etmendir.

**Takım boyutu.** En önemli faktör takım içi iletişim ve yardımlaşmadır. Sunucu bunun doğal olduğunu söyledi, çünkü çevikliğin temel ilkelerinden biri bireyler arası iletişimdir. Ardından şunlar geliyor:

- Kişilerin ulaşılabilirliği: Bir sorun olduğunda hızlıca müdahale edebilmek.
- Uzman kişilerin varlığı: Alanında yetkin, gerektiğinde diğerlerine yardım edebilecek kişiler.
- Takımın nasıl yönetildiği, kaç kişiden oluştuğu ve ne kadar büyük olduğu.

Araştırmacılar çevikliğe geçişin yumuşak yapılması gerektiğini de vurgulamış. Kurumdaki çalışanlarda kafa karışıklığından ve belirsizlikten doğan direnç olmaması için değişim yönetimi (change management) süreçlerinden yararlanılmalıdır.

**Kültür boyutu.** Literatürde bu boyutta fazla yayın yokmuş. Araştırmacılar iki etmeni öne çıkarmış: organizasyonun kültürü ve yönetimin katılımı.

### 3.5 Sonuçlar

Sık değişikliklerle karakterize edilen ortamları yönetmeye yönelik bir yaklaşım olan çevik proje yönetimine son yıllarda ilgi giderek artıyor. Araştırmacıların vardığı özet iki liste halindedir.

En öne çıkan yedi kritik başarı faktörü:

- Ürünün doğru tanımlanması.
- Efor tahmininin gerçekçi yapılması.
- Ürün kabulü için net ve anlamlı kriterlerin belirlenmesi.
- Ekip içinde etkin iletişim.
- Müşterilerle etkin ve sürekli iletişim.
- Sorunların ekip içi iş birliğiyle çözülmesi.
- Yönetimin projeye destek olması.

En temel beş benimseme etmeni:

- Ürün tanımlarının akışkanlığı.
- Ürünlerde sık değişiklik yapabilme yeteneği.
- Ürün teslimatının artımlı yapılması.
- Ekip içi iletişim ve iş birliği.
- Yönetimin destek olması.

İki liste karşılaştırıldığında ürün tanımı, ekip içi iletişim ve yönetim desteği ikisinde de yer alıyor.

### 3.6 Hocanın Değerlendirmesi

> **Hocanın vurgusu:** Bu benimseme (adoption) konusu kurumlar için önemli hale geldi.

Hoca soru olup olmadığını sordu, soru gelmedi.

## 4. 3. Sunum: Blok Zinciri Platformu İçin Proje Yönetimi Modeli

### 4.1 Konu

Üçüncü sunumu da iki öğrenci yaptı. Makalenin adı "Project Management Model Based on Consistency Strategy for Blockchain Platform" (Blok Zinciri Platformu İçin Tutarlılık Stratejisine Dayalı Proje Yönetim Modeli). Makale 2019'da yazılım mühendisliği araştırmaları, yönetimi ve uygulamaları üzerine bir IEEE uluslararası konferansında yayımlanmış ve iki yazarlıdır. Sunucular önce blok zincirinin temel kavramlarını anlattı, sonra makaleyi inceledi.

### 4.2 Blok Zincirinin Temelleri

Blok zinciri (blockchain), herhangi bir merkeze ya da otoriteye ihtiyaç duymadan verilerin dağıtık bir ağ üzerinde saklandığı kayıt teknolojisidir. İlk kripto para birimi Bitcoin ile hayatımıza girmiştir. Eski verilerde düzenleme olanağı sunmaz. Bu yüzden geleneksel veri tabanları gibi çalışmaz, işlemlerin art arda listelendiği dijital bir kayıt defteri (ledger) gibi çalışır.

Sadeleştirilmiş yapıda veriler giriş tarihine göre art arda sıralanır. Her blokta işlem bilgileri ve önceki bloğun özet kodu (hash) bulunur. Her blok kendinden öncekine bu şekilde bağlı olduğundan, herhangi birindeki değişiklik sonraki tüm bloklarda değişiklik doğurur. Verinin değiştirilmediğinden böyle emin olunur.

```
[Blok 1: işlemler]  <-- [Blok 2: işlemler + Blok 1 hash'i]  <-- [Blok 3: işlemler + Blok 2 hash'i]
```

> **Ders sonrası not:** Sunucu hash'i "şifrelenmiş özet kod" diye anlattı. Büyük olasılıkla kastedilen kriptografik özettir. Özetleme tek yönlüdür, şifreleme gibi anahtarla geri açılmaz. Sunucunun kendisi de biraz sonra hash'in tek yönlü olduğunu söyledi.

**Dağıtık ağ.** Aynı veri kaydının birbiriyle iletişim halindeki farklı bilgisayarlarda saklanmasına dağıtık ağ ya da dağıtık sistem denir. Ağdaki donanımlar tek bilgisayar gibi davranır. Bazı bilgisayarlar arızalansa bile diğer üyelerde verinin kopyası bulunduğu için sistem aksamadan çalışır. Bu yapıda verinin sahipliği bir kurum ya da otoritede değildir. Hak ağdaki kullanıcılara demokratik biçimde teslim edilir. Kayıtlı veri kimsenin tek elinde olmadığından tüm kullanıcılar erişebilir ve herkesin eşit hak iddia edebildiği bir ortam oluşur.

Slaytta üç yapı karşılaştırıldı:

| Yapı | Özellik |
|---|---|
| Merkezi (geleneksel) | Her kullanıcı aynı bilgisayara bağlanır |
| Merkeziyetsiz | Kullanıcılar kendileri için en verimli sunucuya bağlanır |
| Dağıtık | Kullanıcılar aynı zamanda veri sağlayıcısıdır |

**Hash fonksiyonu.** Sunucuların anlattığı özellikler şunlardır:

- Herhangi bir veri hash fonksiyonundan geçirildiğinde tek bir hash elde edilir.
- Çığ etkisi (avalanche effect): Tek bir harf değiştiğinde sonuç bambaşka olur.
- Veri ne kadar büyük olursa olsun hash'ler aynı uzunluktadır.
- Hash'ler tek yönlüdür. Orijinal veriye ulaşmak için kullanılamaz. Yalnızca orijinal veri için hash'in uyup uymadığını kontrol etmeye yarar.

> **Ders sonrası not:** Sunucu çığ etkisi için "tek bir harf değiştiğinde tüm veriler tamamen kullanışsız hale gelir" dedi. Doğrusu: Girdide tek harf değişince bambaşka bir hash çıkar. Bu yüzden değişiklik hemen fark edilir. Veri kullanışsız hale gelmez.

<!-- BELİRSİZ: 00:52:30'daki "Tahrifatın fark edilmesi sayılar tarafından oluşturulan uzun karakter dizilerinden oluşur" cümlesi bozuk. Olasılıkla slaytta hash'lerin uzun karakter dizileri olduğu ve tahrifatı fark ettirdiği yazıyordu. -->

**İş ispatı (Proof of Work, PoW).** Sunucu bunu, yüksek miktarda hesaplama gücünün sistemdeki kötü amaçlı oyunculara karşı kullanılmasını önlemek için geliştirilen bir algoritma olarak tanımladı. Bu ağlarda düğümler madencilik yapar.

**Hisse ispatı (Proof of Stake, PoS).** Belirli miktarda hisse veya varlık sahibi olan katılımcıların blok oluşturma ya da doğrulama hakkı elde ettiği fikir birliği (consensus) algoritmasıdır. Düğümler PoW'daki gibi madencilik yapmaz. Blok doğrulama hakkı yalnız yetki sahibi katılımcılara verilir. Kripto paralarla anlatılırsa, katılımcının sahip olduğu kripto parayı sisteme kilitlemesi karşılığında gelir elde ettiği modele stake etmek (staking) denir. İşlem doğrulamak ve gelirden pay almak isteyenler varlıklarını protokole kilitlemelidir. Doğrulayıcılar token'larını kilitli oldukları süre boyunca transfer edemez.

### 4.3 Makalenin Amacı ve Önerisi

Makale, veri açıklığı, güvenlik, istikrar ve verimlilik özelliklerine dayanarak ulusal Ar-Ge projelerinin bilgilerini paylaşmak için blok zinciri kullanmayı amaçlıyor. Geliştirilen platform şunları yapabiliyor:

- Proje planlama bilgilerini kolayca paylaşmak.
- Proje yedekliliğini gözden geçirmek.
- Araştırma sonuçlarını paylaşmak.
- Araştırma sonuçlarının tekrarını kontrol etmek.

Platformun adı PSPP'dir. Yanına PoA (Proof of Atomicity, atomiklik kanıtı) adlı yeni bir fikir birliği algoritması öneriliyor. Hedef, proje paydaşlarının tamamının projeler hakkında tam ve doğru bilgiye ulaşmasıdır.

<!-- BELİRSİZ: Altyazıda PSPP açılımı 00:55:43'te "Perfect Sharing Project Platform" diye geçiyor. Slayt görülmediği için açılım doğrulanamadı. -->

> **Ders sonrası not:** Buradaki PoA, makalenin kendi önerdiği atomiklik kanıtıdır. Literatürde yaygın olan Proof of Authority (yetki kanıtı) büyük olasılıkla aynı kısaltmayı taşıyan başka bir algoritmadır, karıştırılmamalıdır.

### 4.4 PoA Algoritması

Herkese açık blok zinciri bilgiyi tüm kullanıcılarla paylaşmanın iyi bir yoludur. Ancak bilgi üretme ve paylaşma açısından halka açık ve özel blok zincirlerini ayrıca tanımlamak gerekiyor.

<!-- BELİRSİZ: 00:56:53'teki "her kişiye özel, her elemana özel bir blok zinciri" ifadesi altyazıda net değil. -->

PoA'nın temel kuralı şudur: Genel defteri oluşturabilen yöneticilerin %100'ü onay verirse yeni blok oluşur. Eşit konumdaki katılımcılar bilgi paylaşarak bilginin güvenilirliğini artırır. Bilginin belirli kurumlarca gizlenmesi engellenir. Fikir birliği üretildiğinde, ulusal Ar-Ge projelerinin planlama aşamasında yanlış proje bilgisinin, mükerrer ve hatalı projelerin önüne geçilir. Atomiklik ve tutarlılık özellikleriyle PoA güvenilirliği ve paylaşımı artırır.

Süreç şöyle işler:

1. Ulusal Ar-Ge sistemine yeni bir proje bilgisi girilir.
2. Yönetici A bir kanıt oluşturur ve bunu diğer yöneticilere bildirir.
3. Tüm yöneticiler fikir birliğine varıp onaylarsa yeni blok oluşturulur.
4. Yöneticilerden biri bile reddederse süreç başa döner. Yeni bir kanıt oluşturulur ve çalışma oradan sürer.

### 4.5 PSPP'de Proje Yönetim Mekanizması

Platformun proje yönetim akışı şu adımlardan oluşur:

1. **BİT (ICT) teknoloji analizi:** Planlamanın bir aşaması. Gerekli teknolojiler için anahtar kelimeler ve hangi teknolojinin olacağı belirlenir.
2. **Teknik talep araştırması:** Departman, türetilen anahtar kelimelere dayanarak teknoloji talebi üzerine anket yapar.
3. **Teknik talep incelemesi:** Uzmanlar sunulan talep anketi tekliflerini analiz edip inceler.
4. **Planlama:** İncelenen anketlere ve analiz edilen teknolojiye dayanarak bir uzman grubu yeni projeleri planlar.
5. **Duyuru:** Kurum ya da kuruluş 30 günden fazla süreyle proje hakkında ilana çıkar ve başvuru sürecini başlatır.
6. **Seçim ve değerlendirme:** Bölüm, mükemmel projeleri ya da kendi kriterlerine uyan projeleri seçer.
7. **Proje yönetimi:** Departman personeli temel bilgileri ve projeleri kontrol eder, proje değişikliği yapabilir.
8. **Performans yönetimi:** Projelerin performans kaydı yapılır ve blok zincirine dahil edilir.

Projenin sonuçları, diğer proje sonuçlarıyla çoğaltma (tekrar) açısından incelenebilir. Yöneticinin onayıyla yeni blok oluşturulur. Projeler PSPP üzerinden paylaşılır, Ar-Ge sürecine dahil edilir ve diğer Ar-Ge kurumlarıyla da bu platformdan paylaşılır.

### 4.6 Kullanıcı Sınıfları ve Defter Özellikleri

Burada "defter" blok zincirindeki kayıt defteri anlamındadır. Sunucu yetki konusunu PoW ve PoS ile karşılaştırdı: PoW'da herkes defter oluşturabilir. PoS'ta hisseyi elinde tutan kişilerin yetkisi vardır. PSPP'de ise defteri güncelleyebilen bir yönetici sınıfı vardır.

Defterde her adım bir öncekinin özelliklerini içerir. Böylece bir zincir kurularak yetki devri yapılır:

| Sınıf | Yetki |
|---|---|
| Kişiler | Tüm proje planlarını ve sonuçlarını okuyup görebilir, başka yetkisi yoktur |
| Teklif verenler | Kişilerin yetkileri + kendi projesini oluşturma, paylaşma, o projede öneri ve güncelleme. Diğer projelerde işlem yapamaz |
| Uygulayıcı (kurum veya kuruluş) | Önceki yetkiler + bütün projeleri okuma, yazma ve değiştirme, bunları sisteme girme |
| Bölüm yönetimi | Üçünün görevini yapar, ayrıca blok oluşturma kısmı burada |
| Yönetici | Bütün sistem bilgilerini güncelleyip paylaşabilir |

Uygulayıcı, projeyi ya da başvuru dönemini başlatan kurum veya kuruluşun kendisidir.

### 4.7 İşlem Özellikleri

İşlemler üçe ayrılıyor:

- **Proje planlama işlemi:** Planlama belgelerini ve BİT teknoloji analiz belgelerini içerir. Defter, kimlik bilgisi ve sınıflandırma adı gibi bilgiler ilk olarak burada oluşur. Proje boyunca taşınır ve değişmez.
- **Proje yönetim işlemi:** Proje teklifini, proje değişiklik belgelerini ve değişiklik önerilerini içerir.
- **Proje performans yönetimi işlemi:** Projenin sonucunu ve proje performanslarını içeren belgeleri toplar.

Her adım projeye özgü şu bilgileri taşır: defter, kimlik numarası, sınıflandırma adı, proje adı, anahtar kelime, proje özeti, proje sonuç bilgileri, performans bilgileri ve muhasebe bilgileri. Her işlem onaya tabidir. Yöneticilerden fikir birliği çıkmadığı sürece işlem tekrarlanır, çünkü sistemdeki bütün yöneticilerin onaylaması gerekir. Yeni defter oluşturulduğunda bilgiler herkesle paylaşılır.

### 4.8 Sonuçlar ve Sunucuların Yorumu

Makalenin asıl amacı, kurum ve kuruluşların destek verdiği Ar-Ge projelerinde paydaşların tam ve doğru bilgiye ulaşmasıdır. Yazarlar yanlış bilgi ve mükerrer projeler yüzünden sıkıntı yaşamış, bunun önüne geçmek istemiş ve bu hedefe ulaştıklarını görmüşler. Bütün sistem bilgilendirildiği için, aynı projeyi yeniden yazmak isteyen kişi ya yazmamış ya da yönetici onaylamamış.

Sunucu verimlilik konusuna madencilik üzerinden değindi: Bir birim elektrik harcamasına bir birim coin kazanılıyorsa çok bir verimden söz edilemez. Bunu blok zincirinin bugünkü en büyük verimlilik sorunlarından biri olarak nitelendirdi. Yazarlar PoA'yı bu açıdan verimli hale getirmiş ve mevcut sistemlerine göre başarılı bulmuş. Aksaklıklar giderilmiş, tekrar proje önerileri azaldığı için insanların üzerindeki iş yükü de azalmış.

> **Ders sonrası not:** "Bir birim elektriğe bir birim coin" teknik bir ölçü değildir. Büyük olasılıkla yalnız PoW'un yüksek enerji maliyetine işaret etmek için kullanılmış bir basitleştirmedir.

PSPP'nin eksikleri de var. Yazarlar güvenlik ve performans açısından hâlâ sorunlar olduğunu belirtiyor ve bunlar üzerine çalışmaya devam ediyor. Sunucular çalışmanın bugünkü durumu hakkında internette bilgi bulamadıklarını söyledi.

Sunucular Türkiye açısından kendi yorumlarını da ekledi. Gördükleri kadarıyla Türkiye'de blok zinciri ile proje yönetim sistemlerini birleştiren bir mekanizma yok. BAP ve TÜBİTAK projelerinde böyle bir çalışma görmediler. Oysa ihtiyaç olduğunu düşünüyorlar, çünkü BAP projelerinde genelde birbirine benzer, mükerrer çalışmalar oluyor. Böyle bir sistem bunu otomatik olarak engelleyebilir.

Hoca bu sunuma içerik olarak ayrıca bir yorum yapmadı.

## 5. 4. Sunum: Endüstri 4.0'ın Proje Takımlarından Beklentileri

### 5.1 Makale

Dördüncü sunumda bir öğrenci, Karl Marnewick ve Annlize Marnewick'in "The Demands of Industry 4.0 on Project Teams" makalesini anlattı. Sunucuya göre yazarlardan biri proje yönetimi alanında uluslararası bir komitenin başkanıdır. Makale 50'den fazla kaynağa dayanıyor ve Ağustos 2020'de IEEE'nin bir Transactions dergisinde yayımlanmış.

> **Ders sonrası not:** Altyazıda yazarlar "Karl Mermik ve Anneliz Mermik", dergi "ITREPİ Transactions on Project Management" diye geçiyor. Doğru yazımlar büyük olasılıkla Carl Marnewick ve Annlize Marnewick, dergi de IEEE Transactions on Engineering Management'tır. Slayttan doğrulanamadı.

Makale çarpıcı bir alıntıyla açılıyor. Dan Brown'ın 2017 tarihli *Başlangıç* (Origin) romanındaki şu vurgu aktarılıyor: "Human beings will be replaced by machines or will merge with machines to create a new updated version of Homo sapiens." Yani insanlık ya makinelerle yer değiştirecek ya da makinelerle birleşip insanın yeni bir sürümünü yaratacak. Sunucuya göre Endüstri 4.0 tartışmalarında bu çokça anılıyor.

Sunum dört endüstri devrimi, proje yönetiminin kilometre taşları, Endüstri 4.0'ın etkileri ve gerektirdiği yetkinlikler, proje yönetimi için doğan zorluklar ve sonuç sırasıyla ilerledi.

### 5.2 Dört Endüstri Devrimi

**Birinci devrim.** Öncesinde iş daha çok kas gücüne dayanıyordu. Su değirmenleri ve buhar makineleriyle birlikte fabrikalaşma ortaya çıktı. En önemli özelliklerinden biri kırdan kente göçtür. Fabrikalar ve büyük iş yerleri şehirlerde açıldığı için milyonlarca insan kırdan şehre geçti. Devrim 1784'te başlayıp 86 yıl sürdü.

> **Ders sonrası not:** Altyazıda başlangıç yılı "1184" diye geçiyor. Doğrusu büyük olasılıkla 1784'tür. Sunumdaki ikinci devrimin başlangıcıyla da tutarlıdır: 1870 − 86 = 1784.

**İkinci devrim.** Enerji, malzeme, kimya ve tıp alanlarındaki buluşlarla başladı. İnsan yaşam standardı çok hızlı yükseldi. Sunucunun örneği evlere elektriğin gelmesiydi. Bunun için yolların yapılması ve elektrik hatlarının çekilmesi gerekiyordu. Tüm toplumu doğrudan etkilediği için devletler ve hükümetler çok büyük rol oynadı, çok büyük bir koordinasyonla yönetildi. Önemli avantajları hayat kalitesinin gelişmesi ve fabrika işçilerinin maaşlarının iyi olmasıydı. 1870'ten Birinci Dünya Savaşı'nın başlarına kadar yaklaşık 45 yıl sürdü.

**Üçüncü devrim.** İkinci devrimle arasında yaklaşık 50 yıl var. Araştırmacılar bu boşluğu, insanların yeni teknolojiyi en iyi şekilde kullanabilmesinin zaman gerektirmesiyle açıklıyor. Sunucu başka kaynaklardan bir not ekledi: Bu arada iki dünya savaşı var. Bazı kaynaklar, uçak ve tank yapımı gibi büyük endüstriyel faaliyetler nedeniyle ikinci devrimin İkinci Dünya Savaşı'nda da sürdüğünü savunuyor. Makale konuyu böyle ele almıyor. Üçüncü devrim bilgisayar teknolojisi, bilgi teknolojisi ve yaygın dijitalleşmeyle başladı. Zenginlik sanayileşmiş ülkeler, yükselen ekonomiler ve gelişmekte olan ülkeler arasında paylaşıldı. 1960'tan başlayarak yaklaşık 40 yıl sürdü.

**Dördüncü devrim (Endüstri 4.0).** 2011'de Alman şirketlerinin öncülüğüyle başladı. Sunucu bunu Almanların mühendislikteki öncü konumuna bağladı. Endüstri 4.0 şunlara yöneliyor:

- Teknolojilerin akıllı ve otonom çalışabilmesi için entegrasyonu.
- Merkeziyetsiz şirketlerin oluşması.
- Ürün ve servis entegrasyonu.

Nesnelerin interneti (Internet of Things, IoT) kavramı bu dönemde çıktı. Otonom araçlar ve akıllı ev sistemleri örnek verildi. Özetle Endüstri 4.0, ilgili tüm kaynakların dinamik olarak birbirine entegre çalışmasını, kendi kendine organize olmasını, gerçek zamanlı ve otonom olarak optimize edilmesini sağlamaya çalışıyor. Bazı araştırmacılar ekiplerin kendi yeterliklerini gözden geçirme vaktinin geldiğini söylüyor.

| Devrim | Başlangıç | Süre (sunumdaki) | Belirleyici unsur |
|---|---|---|---|
| 1. | 1784 | 86 yıl | Su değirmeni, buhar, fabrikalaşma |
| 2. | 1870 | Yaklaşık 45 yıl | Enerji, malzeme, kimya, tıp buluşları |
| 3. | 1960 | Yaklaşık 40 yıl | Bilgisayar, bilgi teknolojisi, dijitalleşme |
| 4. | 2011 | Sürüyor | IoT, otonomi, entegrasyon |

### 5.3 Proje Yönetiminin Tarihi

Proje yönetimi eski çağlarda üç kavramla ortaya çıktı: verimlilik (efficiency), etkililik (effectiveness) ve yenilik (innovation). Birçok kişi proje yönetiminin 20. yüzyıla ait olduğunu düşünse de Giza piramitleri, Kolezyum ve Ayasofya gibi yapıtlarda da proje yönetimi gözlemlenebilir. Kilometre taşları şöyle verildi:

- **İkinci dönem, 1950'lerin sonu:** Derste de çokça gördüğümüz kritik yol yöntemi (Critical Path Method, CPM) ve PERT ortaya çıktı.
- **Üçüncü dönem, 1980-1994:** Kişisel bilgisayarlar.
- **Dördüncü dönem, 1995'ten bugüne:** Teknolojinin daha fazla gelişimi proje yönetimi yöntemlerini değişmeye iten bir güç oldu.

Bu faktörler proje yönetiminin sürekli gelişen ve yeni teknolojilere adapte olan bir disiplin olduğunu gösteriyor.

### 5.4 Proje Yöneticisine Etkileri

Makaleye göre proje yöneticisinden şunlar bekleniyor:

- Çok disiplinli bilgi toplamak ve yaymak.
- Yeni teknolojilere sürekli uyum sağlamak ve her projede en iyi çözümleri kullanmak.
- Değişen yönetim yapılarına ve kültürlerine uyum sağlamak. Örneğin çevik dönüşümde proje yöneticisi de buna adapte olmalıdır.

Sunucu kendi deneyimini de aktardı. Çalıştığı şirkette tüm ekipler çevik yapıya dönüyor ve şirket büyük bir dönüşümün içinde. Bunu Endüstri 4.0'ın bugün görülen etkilerinden biri olarak yorumladı.

Sürekli değişim, belirsizlik ve kesintiler proje yöneticisinin hayatının parçası olacak. Bugün projelerde takım üyeleri genellikle insandır ve çözüm üretmek için bireysel yetkinliklerini kullanır. Proje yöneticisi de takım üyelerinden en iyi performansı almak için mücadele eder. Endüstri 4.0'da ise çözüm operasyonları değişiyor ve insan kontrolünden çıkıyor. Her şeyin birbirine bağlandığı bir iş ortamında çözüm oluşturuluyor. Sunucuya göre burada proje yöneticisinin rolü biraz kayboluyor ve iş daha çok Master rolüne düşüyor.

<!-- BELİRSİZ: 01:18:50'de "Master" ifadesi geçiyor, önceki sözcük maskelemeye takılmış. Olasılıkla Scrum Master kastediliyor; 2. sunumdaki koordinasyon rolüne gönderme yapılıyor. -->

### 5.5 Geleceğin Proje Takımı

Gelecekte proje takımları yine iki veya daha çok üyeli olacak, ama üyeler yalnız insan olmayacak. Yapay zekâlı robot takım üyeleri de olacak. Sunumdaki öngörüler şunlardır:

- Üyeler yine iş birliği içinde çalışacak. Bunun için robotlarla iletişim noktasında entegrasyonlar gerekecek, çünkü robotlara girdi verip onlardan çıktı alınabilmelidir.
- Yukarıdan aşağıya statik rol ve sorumluluklar, aşağıdan yukarıya dinamik biçimde yönetilecek. Sorumlulukların değişim yönetimini takım üyeleri sağlayacak.
- Çözümler yalnız insana bağlı ortamlar için değil, sürekli birbirine bağlı ortamlar için geliştirilecek.
- Robotlar insan gibi birer takım üyesi kabul edilecek. Karar verme mekanizmasına hem insanlar hem robotlar katkı verecek.
- Bazı meslekler yapay zekâ veya robotlarla yer değiştirecek. Sunucunun örneği otonom araçlar ve Tesla'ydı: Şoförlük mesleği ortadan kalkabilir. Bazı meslekler yok olurken yeni meslekler doğacak.
- Takım üyelerinin yetenekleri başarı için en önemli faktör olacak. Üyeler yeni teknolojilerin yönetimini yapabilmeli.

> **Ders sonrası not:** Sunucu "şu an insansız araçlar sürülüyor" dedi. Bu büyük olasılıkla abartılı bir ifadedir. Sürücü desteği sistemleri yaygınlaşmıştır, ama ders tarihinde şoförlüğün tamamen yerini alacak kadar yaygın bir tam otonom sürüş yoktu. Makalede de bu, gelecekle ilgili bir öngörü olarak geçiyor.

Sunucu bunu somutlaştırdı: Bir yazılım projesi yönetiyorsanız takım arkadaşınız bir yapay zekâ veya robot olabilir. Onunla iletişim halinde olmanız, girdi verip çıktı almanız ve bu çıktıyı bir takım üyesi olarak değerlendirmeniz beklenecek.

Makalede bugünün ve geleceğin takımlarını karşılaştıran bir tablo var. Sunucunun aktardığı farklar şunlardır:

| Başlık | Bugün | Gelecek |
|---|---|---|
| Takım üyeleri | İnsanlar | İnsanlar ve robotlar |
| Alan uzmanı (subject matter expert) | İnsan danışman | Robot da olabilir |
| İş birliği | Birebir, yüz yüze ve çevrim içi | Dijital iletişim ve geri bildirim entegrasyonu ile, robotları da içerecek biçimde |
| Roller | Yukarıdan aşağıya, statik | Aşağıdan yukarıya, sorumlulukları takım paylaştırır |

<!-- BELİRSİZ: Tablonun çevre (environment) ve iş yeteneği satırları için altyazıda yalnız "aynı şekilde" deniyor. Hücreler slaytta görülmedi. "Birebir, 100'e 100 ve online" ifadesi yüz yüze olarak okundu. -->

### 5.6 Takım ve Birey Düzeyindeki Zorluklar

**Takım düzeyinde.** Gelecekte takımlarda farklı jenerasyonlardan insanlar ve robotlar birlikte olacak. Proje yöneticileri proje boyunca bilgi akışını sağlamalı. Performansı iyileştirmek için belki robotların önerdiği düzenlemeleri uygulamak zorunda kalacaklar. Takımların iletişim becerileri robotlarla entegre olacak biçimde değişecek ve robotlar takım içinde geri bildirim verecek.

İnsan üyelerin problem çözme yetenekleri de çok önemli olacak. İnsanlar bir problemi her çözdüğünde bu bilgiyi robot takım arkadaşlarına aktarmaları gerekecek. Çünkü ilk zamanlarda bir şeyi bir yerden alıp bir yere koyabilen robotların, öğrenme yetisi sayesinde ileride insan gibi karmaşık problemleri de çözmesi bekleniyor.

**Birey düzeyinde.** Takım üyelerinden dört yetkinlik bekleniyor: teknik, kişisel, sosyal ve süreç yetkinlikleri. Bunların tek başına bulunması yeterli değildir. Hepsine aynı anda sahip olmak, ürünlerin hızlı ve akıllı teslimi için önemli bir avantaj sağlar.

Birçok araştırmacıya göre insanları Endüstri 4.0'a hazırlamada geleneksel eğitim yeterli olmayacak. Bu eğitimler çok teknoloji içerdiği için maliyeti geleneksel eğitimle karşılanamaz. Benesova ve bir başka araştırmacı, şirketlerin ihtiyaç duyduğu yetkin bireyleri yetiştirmek için kendi eğitim ve öğretim kurumlarını kurmalarının daha etkili olacağını öneriyor. Sunucu bugünden örnek verdi: Birçok şirket yeni mezunlara bir iki aylık bootcamp'ler yapıyor, sertifika verip yetkinlik kazandırıyor ve sonra iş fırsatı oluşturuyor.

Takımların çevik olması düşünme ve çalışma şekillerini değiştirebilme yetkinliği kazandırıyor. Takımlar Endüstri 4.0'a uyum için sürekli öğrenen ve kendini geliştiren bir yapıda olmalıdır.

### 5.7 Sonuç

Her endüstri devriminin proje takımları üzerinde kendine özgü zorlukları ve gereksinimleri vardır. Farklı jenerasyonlar ve yeni katılan robotlar takım kompozisyonuna yeni gereksinimler getiriyor: birbiriyle iletişim için entegrasyonlar, tüm üyelerin robotları yönetebilme yetkinliği gibi. Gelecekte proje takımları insanlardan ve insan olmayan üyelerden oluşacak, iç ve dış ortamlar Endüstri 4.0'a daha bağlı hale gelecek.

Soru gelmedi, hoca içerik olarak ek yorum yapmadı.

## 6. 5. Sunum: Scrum'ın Yazılım Proje Yönetimine Etkisi

### 6.1 Konu ve Arka Plan

Son sunumda bir öğrenci, çevik metodolojinin, yani Scrum'ın, yazılım proje yönetimine etkisini inceleyen 2019 tarihli bir IEEE makalesini anlattı. Çalışmanın kapsamı Pakistan yazılım endüstrisidir.

Sunucu, yazılım işlerinin birçoğunun başarısız olup battığını, yazılım endüstrisinin yeni yaklaşımlarla başarıya ulaşmaya çalıştığını ve iyi bir proje yönetiminin projeyi başarıya götürdüğünü söyleyerek başladı. Yazılım proje yönetiminde 10 bilgi alanı (knowledge area) vardır. Sunumda şöyle ayrıldı:

- **Dört çekirdek (temel) bilgi alanı:** Maliyet, zaman, kapsam ve kalite yönetimi.
- **Altı yardımcı bilgi alanı:** İnsan kaynakları, iletişim, risk, tedarik, paydaş ve entegrasyon yönetimi.

> **Ders sonrası not:** Bu ayrım sunumun kaynağına aittir. PMBOK kendi 10 bilgi alanını büyük olasılıkla böyle iki gruba ayırmaz ve entegrasyon yönetimini diğer alanları birleştiren alan olarak ele alır.

Çevik metodoloji gelecekteki gereksinim değişikliklerini barındırır. Müşteri ihtiyaçlarına göre maliyeti, kapsamı ve kaliteyi idare edebilecek bir esnekliğe sahiptir. Çevik yöntemler daha çok insanların ilişkilerine, çalışan yazılıma, müşteriyle iş birliğine ve değişikliklere odaklanır.

Scrum çevik proje yönetiminin en yaygın kullanılan çerçevesidir (framework). Gereksinimleri kontrol etme ve yönetme esnekliği sağlar. Yazılımı küçük parçalar halinde ilerleterek geliştiren bir modeldir. Hem küçük hem büyük projelere uygulanabilir. Değişken bir ortamda ekip çalışmasına ve ürün kalitesine odaklanır.

Scrum'ın temel öğeleri şöyle verildi:

- **Roller:** Scrum Master, Scrum takımı ve ürün sahibi (product owner).
- **Sprint:** Ortalama 3-4 hafta, projeye göre bazen 2 hafta.
- **Scrum toplantısı:** Yaklaşık 15 dakika. Son toplantıdan bu yana neler yapıldığı, hangi zorluklarla karşılaşıldığı ve sonraki toplantıya kadar neler yapılacağı konuşulur.

> **Ders sonrası not:** 1. sunumda sprint "ortalama 2-3 hafta", burada "ortalama 3-4 hafta" diye geçti. Büyük olasılıkla ikisi de pratikteki aralığa işaret ediyor. Scrum Guide sprinti büyük olasılıkla en fazla bir ayla sınırlar, sabit bir ortalama vermez.

### 6.2 Yöntem

Anket, Pakistan'daki 30'dan fazla yazılım şirketine dağıtılmış. Ankette Scrum'ın yazılım proje yönetimindeki etkisi, bilgi alanları üzerinden sorulmuş.

### 6.3 Anket Bulguları

| Bilgi alanı | Soru | Yanıtlar |
|---|---|---|
| Zaman ve maliyet | Scrum'ın zaman ve maliyet yönetimine olumlu etkisi var mı? | %95 evet |
| Kalite | Scrum kalite yönetimini kolaylaştırıyor mu? | Yaklaşık %70 "katılıyorum" veya "kesinlikle katılıyorum" |
| Risk | Scrum kullanırken projede risk faktörü oluşuyor mu? | %66,7 "belli oranda risk her zaman var", %14 "evet", %19 "hayır" |
| İnsan kaynakları | Scrum, insan kaynaklarının iş için personel bulmasını kolaylaştırıyor mu? | %25 katılıyorum, %25 kesinlikle katılıyorum, %25 nötr, %25 katılmıyorum tarafında |

Kalite sorusunda ölçek 1'den 5'e kadar verilmiş. Sunucuya göre 1 "kesinlikle katılıyorum", 5 "kesinlikle katılmıyorum" demektir. Risk yanıtlarının toplamı 66,7 + 14 + 19 = 99,7 ediyor. Küçük fark yuvarlamadan gelmiş olabilir. İnsan kaynaklarında yanıtların toplamı 25 + 25 + 25 + 25 = 100'dür. Sunucu bu dağılımı nötr olarak yorumladı ve olumlu ya da olumsuz bir etkiden söz edilemeyeceğini söyledi.

<!-- BELİRSİZ: 01:36:25'teki insan kaynakları sorusu altyazıda bozuk ("iş için personel olmasını kolaylaştırıyor mu"), tam ifade slaytta kaldı. -->

### 6.4 Sonuç

Çalışmaya göre Scrum, yazılım proje yönetimindeki bilgi alanlarında genel olarak olumlu etkiye sahiptir. Projenin süresi, maliyeti, kalitesi, riski ve kapsamı üzerinde olumlu etkisi var. İnsan kaynakları politikaları üzerinde olumlu ya da olumsuz bir etki saptanmamış. Yazarlara göre Scrum riski azaltıyor, maliyeti kontrol ediyor, kaliteli ürün ortaya çıkmasına ve projenin zamanında tamamlanmasına yardım ediyor.

> **Ders sonrası not:** Sunumdaki sayılarla sonuç arasında iki boşluk var. Birincisi, gösterilen risk sorusu riskin azalıp azalmadığını değil, risk oluşup oluşmadığını soruyor ve yanıtların %66,7'si riskin her zaman var olduğunu söylüyor. "Scrum riski azaltır" sonucu bu tablodan doğrudan çıkmıyor. Kapsam yönetimi için de sunumda anket sonucu gösterilmedi. İkincisi, insan kaynakları sorusunda aktarılan yanıtların %50'si olumlu tarafta. Bu yüzden "etki yok" sonucu da yalnız bu dağılımla açıklanamıyor. Değerlerin slayttaki hali görülmediği için rakamlar altyazıdan doğrulanamadı.

Sunum sonunda soru gelmedi.

## Dersin Toparlaması

Bu derste beş makale üzerinden çevik proje yönetiminin farklı yüzleri görüldü. Birinci sunum, ekip fiziksel olarak dağıldığında bilgi akışının ve iş birliğinin nasıl değiştiğini DiCoT çerçevesiyle gösterdi. İkinci sunum çevikliğin başarısını ve benimsenmesini proje, takım ve kültür boyutlarında sıraladı. Ürünün tanımı, ekip içi iletişim ve yönetim desteği iki listede de yer aldı. Beşinci sunum, Scrum'ın bilgi alanlarına etkisini sektör anketiyle ele aldı. Üçüncü sunum teknolojinin proje yönetimine doğrudan uygulanmasına örnek oldu: mükerrer Ar-Ge projelerini azaltmak için blok zinciri ve tüm yöneticilerin onayını isteyen PoA algoritması. Dördüncü sunum ise bakışı geleceğe çevirdi ve robotların üye olduğu takımların yeni iletişim ve yetkinlik gereksinimlerini tartıştı.

Hocanın dersteki iki değerlendirmesi de bu tabloyu tamamlıyor. Benimseme konusu kurumlar için önemli hale gelmiştir. Uzaktan çalışma gibi hızla değişen bir konuda 2016 tarihli bir çalışma, son iki yılın deneyimlerini içeren yayınlarla birlikte okunmalıdır. Dersin başında anlatılan plan ve SRS içeriği ise dönem boyunca görülen konuların uygulamadaki karşılığıdır: projeyi anlama, tanımlama, planlama ve planı gereksinim analizine kadar takip etme.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
