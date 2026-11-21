# Ders 9 Genişletilmiş Notu: Seminer Sunumları: Robot Sürüleri, Mikroservis Tabanlı Makine Öğrenmesi ve Harita Birleştirme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Akışı
- 2. Birinci Sunum: Heterojen Robot Sürülerinin Koordinasyonu ve Formasyonu
- 3. İkinci Sunum: Mikroservis Tabanlı Büyük Veri ve Makine Öğrenmesi Uygulamaları
- 4. Üçüncü Sunum: Çoklu Robotlarda Harita Gösterimi ve Harita Birleştirme
- 5. Hocanın Sunumlara Genel Geri Bildirimleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Akışı

Bu ders, dönemin son haftalarında yapılan öğrenci seminer sunumlarından biriydi. Her sunum için yaklaşık yarım saat ayrıldı. Sunumlarda öğrenciler, kendi araştırma alanlarıyla ilgili yaptıkları literatür taramasını tanıttı. Üç sunum yapıldı: heterojen robot sürülerinin koordinasyonu ve formasyonu, mikroservis tabanlı büyük veri ve makine öğrenmesi uygulamaları üzerine bir sistematik literatür taraması, çoklu robot sistemlerinde harita gösterimi ve harita birleştirme yöntemleri. Her sunumdan sonra hoca, kaynakların seçimi ve sunulması üzerine geri bildirim verdi ve dinleyicileri soru sormaya çağırdı.

## 2. Birinci Sunum: Heterojen Robot Sürülerinin Koordinasyonu ve Formasyonu

Sunumun başlığı "Coordination and Formation of Heterogeneous Robotic Swarm Systems" idi (ekrandan, 00:10:00). Sunum üç bölümden oluştu: sürü sistemlerinin genel özellikleri, literatürdeki heterojen sürü çalışmaları ve bir derlemeden alınan açık problemler. Sunumun dayandığı sekiz kaynağın ikisi derlemeydi; biri sürü robotiğini genel olarak, diğeri işbirlikçi heterojen çoklu robot sistemlerini inceliyordu.

### 2.1 Sürü Nedir?

Sürü (swarm), aynı amaç için bir araya gelmiş ve birbirleriyle iletişim hâlinde olan büyük bir robot grubudur. Bazı çalışmalarda robotlar birbirine karşı mücadele eder, ama çalışmaların büyük kısmında aynı amaç için birbirlerine yardım ederler. Terim robotikte ilk kez 1989'da kullanılmaya başlanmış, ancak sürü sistemleri üzerine çalışmalar 1940'lara kadar uzanıyor. Sürü sistemleri doğadaki sürülerden esinlenir: karınca sürüleri, arı kolonileri, kuş sürüleri. Sunumda incelenen çalışmalardan biri de arı davranışlarından esinlenmişti.

Sürüler askeri çalışmalarda ve orman yangını taraması gibi çok geniş bölgelerin taranması ve keşfi görevlerinde kullanılır.

- **Avantajlar:** Birden fazla robot birlikte taradığı için keşif görevleri daha hızlı biter. Tek bir robotun kendi başına yapamayacağı işler birlikte yapılabilir. Farklı görevlerde özelleşmiş bireyler bir araya geldiğinde işler daha başarılı hâllolur.
- **Dezavantajlar:** Sürüdeki birey sayısı arttıkça yönetim çok zorlaşır. Bu yüzden bu tür robot gruplarının hem formasyonunda hem konfigürasyonunda ciddi zorluklar vardır. Ayrıca aşağıdaki türlere göre farklı dezavantajlar ortaya çıkar.

### 2.2 Sürü Türleri

Slaytta sürü türleri iki ölçüte göre verildi (ekrandan, 00:15:00).

**Bireylerin özdeş olup olmadığına göre:**

- **Heterojen (heterogeneous):** Farklı donanım ve/veya yazılım içeren robotlardan oluşur. Farklı donanımlı, farklı yazılımlı ya da aynı donanımlı ama farklı yazılımlı robotlar olabilir. Robotların birbirlerini modellemeleri ve modellerine göre birbirlerine bilgi sağlamaları daha zordur, bu yüzden çalışmalarda genelde tercih edilmezler.
- **Homojen (homogeneous):** Aynı donanım ve yazılıma sahip robotlardan oluşur.

**Yönetim biçimine göre:**

- **Merkezi (centralized):** Global ortamdaki görev tanımlarını ve bilgi aktarımını sağlayan bir yönetici vardır, tüm robotlar bu yöneticiye bağlıdır. Yönetici hangi görevi hangi robotun yapacağını belirleyip robotları yönlendirir, robotlardan gelen bilgileri merkezde toplayıp birleştirir. Global bilgi gerektiren haritalama görevlerinde tercih edilir: her robot kendi alanını tarayıp haritasını çıkarır, haritalar ortak bir yerde birleştirilir. Yöneticinin kaybı sürüyü dağıtır.
- **Merkezi olmayan (decentralized):** Robotlar bilgi aktarımını, görev dağılımını ve konumlanmayı birbirlerine göre kendileri yapar, çoğunlukla en yakın komşularına göre hareket ederler. Bilgi aktarımındaki gecikmelerden arınmışlardır ve sistemin karmaşıklığı birey sayısından bağımsızdır. Ancak global bilgi gerektiren görevlerde başarısız olurlar ve sürünün davranışını tahminlemek zordur.
- **Hibrit:** İki düzeyde yönetim vardır. Yerelde komşularla iletişimi ve formasyonu robotlar kendileri sağlar, tüm sürünün davranışını bir yönetici ya da yönetici grubu yönlendirir. Yönetici örneğin oluşturma ya da parçalama gibi üst düzey kararları verir, robotları çoğunlukla kendi başlarına bırakır. Merkezi yönetime göre daha yumuşak bir yönetimdir.

### 2.3 Sürülerden Beklenen Temel Davranışlar

**Self-organization:** Çevre değiştiğinde, sürüye yeni bir robot katıldığında, bir engel çıktığında ya da bir robotun başına bir iş geldiğinde sürünün yeni duruma kendi başına uyum sağlamasıdır.

**Ölçeklenebilirlik (scalability):** Sürünün birkaç bireyden de binlerce bireyden de oluşsa aynı şekilde çalışmaya devam edebilmesidir. Merkezi olmayan sürülerde bunu sağlamak çok daha kolaydır.

**Sağlamlık (robustness):** İncelenen kaynakta sürünün doğru çalışabilmesi olarak tanımlanmış.

**Formasyon ve bağlantı şekilleri:** Burada bağlantı, robotlar arasındaki ağ (network) demektir. Bağlantı şekilleri lisans derslerinde görülen ağ topolojilerine benzer. Topoloji hangi robotun hangisiyle bağlı olacağını belirler; yalnız aralarında kenar (edge) bulunan robotlar birbirine bağlıdır. Formasyonları oluşturmak için graf teorisinden yaygın biçimde yararlanılır; bunun dışında Voronoi diyagramları ve potansiyel alanlar (potential fields) da kullanılır.

**Enerji tasarrufu:** Sürekli birbirine bağlı ve mesajlaşan robotlar bataryayla çalıştığı için enerji tasarrufu ciddi bir konudur. Kullanılan yöntemler:

- Robot süpürgelerin kendini şarj ettiği istasyonlara benzer şekilde ortama şarj istasyonları yerleştirmek.
- Doğrudan iletişim yerine dolaylı iletişim kullanmak: bir robot geçerken bir iz bırakır, sonraki robot görevi bu izden yararlanarak sürdürür.
- Robotların başla-dur (start-stop) sayılarını kısıtlamak, bağlantı alanlarını küçültmek ya da veriyi basit dalga formunda göndermek.

> **Ek bilgi (derste anlatılmadı):** Robotların bıraktığı iz üzerinden dolaylı iletişime literatürde büyük olasılıkla "stigmergy" denir. Terim, karıncaların feromon izleriyle birbirlerini yönlendirmesinden gelir.

### 2.4 Swarm Çalışmalarına Genel Bakış ve Açık Nokta

İncelenen derlemeye göre çalışmalar şu konularda yoğunlaşıyor (ekrandan, 00:20:00):

- Yönetim biçimi optimizasyonu
- Self-organization davranışı ve dezavantajlarının giderilmesi
- Ölçeklenebilir (scalable) ve sağlam (robust) sistemler oluşturma
- Etkin enerji kullanımıyla işe en uygun formasyonu bulma
- Yol planlama ve engelden kaçınma
- Obje taşıma
- Enerjinin tükendiği noktada tüm sistemin devre dışı kalmasına çözüm arayışları

Sorun şudur: bu konuların hepsini kapsayan bir çalışma yoktur; en fazla beşini kapsayan çalışmalar vardır. Bunun bir nedeni uçtan uca (end-to-end) bir sistem örneğinin olmamasıdır. Çalışmalar belli varsayımlar (assumption) altında sistemin yalnız bazı noktalarını çalıştırabiliyor. Gerçek dünyada bir sürü kurup koşturan ve sonuçlarını alan bir çalışma henüz bulunmuyor.

### 2.5 İki Katmanlı Formasyon Sistemi (2020)

Bu çalışma (Xiao, Chen ve Yu, Neurocomputing, 2020) sürüyü homojen kabul ettiği için heterojen çalışmalardan önce anlatıldı (ekrandan, 00:40:00). Motivasyon şudur: genelde önce bir topolojiye karar verilir, sonra ona uygun formasyon tanımlanır; ama sahada bu formasyon tutmazsa sorun çıkar. Bu yüzden yazarlar formasyona uygun topolojiyi otomatik geliştirmeyi hedefledi. Daha önceki bir çalışmalarında (sunucunun hatırladığına göre 2013) önerdikleri RIPF (Relation Invariable Persistent Formation) formasyon yöntemini iki katmanlı bir mekanizmaya entegre ettiler.

**Graf tabanlı formasyon:** Sürünün tamamı yönlü bir graftır (directed graph). Her robot bir düğümdür (vertex), komşu robotlar arasındaki bağlantı kenardır. Bir robottan diğerine kenar gidiyorsa, kenarın ulaştığı robot önceki robot tarafından yönlendirilir (lead edilir). Formasyon robotların ilk pozisyonlarından şu kısıtlar altında oluşturulur:

- Çarpışmayı (collision) engellemek için her robot farklı bir pozisyonda olur.
- Her robot komşularından $D$ mesafesi uzaklıkta olur.
- Bir robotu en fazla iki komşu robot yönlendirir.
- Graftaki kenar sayısı $E$ ile düğüm sayısı $V$ arasında $E = 2V - 3$ bağıntısı olur, yani kenar sayısı düğüm sayısının iki katının üç eksiğidir.

> **Ek bilgi (derste anlatılmadı):** $E = 2V - 3$ koşulu büyük olasılıkla düzlemde minimal katı (minimally rigid) graflar için bilinen Laman sayımıdır. Bu sayıda kenarla, uygun yerleşimde, robotlar arası mesafeler korunduğunda formasyonun şekli bozulmaz ve gereksiz kenar kalmaz.

**Formasyon oluşturma algoritması:**

- Her robotun ilk pozisyon bilgisi alınır.
- Bu pozisyonlardan Delaunay üçgenlemesi oluşturulur.
- $E = 2V - 3$ bağıntısına göre fazla olan kenarlar silinir.
- Gruptan bir robot lider olarak atanır.

Sunumda gösterilen şekilde rastgele dağılmış robotlardan Delaunay üçgenleri kuruldu, fazla kenarlar silindi ve bir robot lider yapıldı; sonra sürü iki engel bulunan bir ortamda hareket etti.

**Birinci katman (yol planlama, path planning level):** Sürü harekete başladığında gideceği yol belirlenir. Yolun başlangıcı formasyonun oluşturulduğu ilk pozisyonlardır. Bir sonraki adımı bulmak için formasyonun kısıtları kullanılır; bu kısıtlara göre atılacak bir sonraki adım gradient descent ile belirlenir. Engellerden kaçınmak için robotların engel etrafından dolaşmasını sağlayan bir çarpışma engelleyici kural tanımlanmıştır: engele belli bir güvenli mesafeden fazla yaklaşılmaz, robot oradan yön değiştirip engelin etrafından geçer ve engel geçildikten sonra eski yola geri döner. Robotların özellikle dönüşle birlikte ilerleme hareketlerini yumuşatmak için engel öncesi ve sonrası arasında bir referans yol tanımlanır; böylece dönüş açısı küçültülür, robot sert dönmek yerine azar azar döner (ekrandan, 00:25:00).

**İkinci katman (formasyon takibi):** Robotların formasyonu nasıl izleyeceğini belirler. Mevcut durum (state) ile olması beklenen durum arasındaki hata tanımlanır, hataya göre robotların uyacağı hızlanma formüle edilir. Çalışmada tekerlekli robotların kinematik ve hareket modelleri kullanılmıştır. Bu katmanın kontrolü model öngörülü kontrol (model predictive control) stratejisiyle yapılır: mevcut ve bir sonraki pozisyon arasında bir bağıntı kurulur, bu bağıntı kullanılarak her adımda bir optimizasyon yapılır ve optimal kontrol girdisi üretilir. Kontrol girdisi, robota verilen "$X_1$'den $X_2$'ye git" türünden bir komuttur.

**Sonuçlar:** Grafiklerde robotların doğrusal hızları ($x$ ve $y$ düzleminde) ve açısal hızları (dönme hızları) gösterildi. En önemli sonuç takip hatasıdır (tracking error): başta bir dalgalanma olsa da mevcut durum ile istenen durum arasındaki fark sıfıra yakınsıyor.

### 2.6 Swarmanoid (2013)

Heterojen sürü çalışmalarından en çok bahsedilenlerden biri Swarmanoid'dir (Dorigo ve ark., IEEE Robotics & Automation Magazine, 2013). Adı, sürü (swarm) ile insansı robotun (humanoid) birleşiminden gelir. Amaç uçtan uca bir heterojen robot sürüsü yapmaktı; bunun için üç farklı robot ve kendi yazılım mimarileri geliştirildi (ekrandan, 00:30:00).

- **Foot-bot:** Birbirinden bağımsız hareket eden iki küçük motorlu tekerlekle yerde hareket eder. RGB LED'lerle diğer robotlarla haberleşir.
- **Hand-bot:** Yerde sabit duran bir platforma bağlı iki koldan oluşur. Dikey tırmanabilir, yerden objeleri tutup kaldırabilir. Görev yerine foot-botlar tarafından taşınır. Diğer hand-botlara ya da foot-botlara tutunabilir. RGB LED'ler sayesinde diğer robotlara sinyal gönderebilir.
- **Eye-bot:** Quadrotor yapısındadır, iç mekân için optimize edilmiş, küçültülmüştür. Dışarıda GPS, içeride kamera ve lazer sensörleriyle global pozisyon tespiti yapar. Diğer robotlarla range and bearing sistemiyle bağlantıdadır; buna göre 12 m içindeki tüm robotlarla veri alışverişi yapabilir. Görevi, görev yerini tespit edip foot-bot ve hand-botlara iletmek ve görevi yerine getirmelerini sağlamaktır.

Gerçek dünya deneyinde bir odadaki raflardan birinde bulunan bir kitabın başka bir rafa taşınması istendi. Eye-bot kitabın yerini buldu, foot-bot hand-botu taşıdı ve görev tamamlandı. Daha fazla deney yapabilmek için ARGoS adlı bir simülasyon ortamı geliştirildi; bu ortam Gazebo gibi hâlâ kullanılıyor.

### 2.7 Heterojenliğin Sürü Davranışlarındaki Performansa Etkisi (2015)

Bu çalışmada (Kengyel ve ark., PRIMA, 2015) robotların donanımı aynıdır. Çalışmanın gerekçesi, aynı donanımlı robotların daha ucuz olmasıdır. Heterojenlik davranışla sağlanır: her robot bir davranışı öğrenerek ona özelleşir. Böylece homojen sürü gibi aynı donanım kullanılırken heterojen sürü gibi farklı davranışlar elde edilir.

Çalışma bal arısı gözlemiyle başlar: bal arısı yaşa göre farklı davranışlar sergiler. Önce rastgele dolaşır (random walker), sonra duvara yakın yerlere yönelir (wall follower), sonra sıcak yeri bulur (goal finder), daha ileri yaşta çok az hareketli ya da tamamen durur (immobile).

Yöntem slayttan şöyle özetlendi (ekrandan, 00:35:00): homojen sürüler için geliştirilmiş BEECLUST algoritması genetik algoritmaya entegre edildi. Arı deney sonuçları doğru davranış (ground truth) olarak verildi. Doğru davranışlar ödüllendirildi: wall-follower için duvara yönelmek, goal-finder için sıcak ortama yönelmek, immobile için durmak ya da yavaşlamak. Böylece bir uygunluk (fitness) fonksiyonu elde edildi ve bu fonksiyon maksimize edildi.

Deneyler simülasyon ortamında 15 robotluk bir sürüyle yapıldı. Aynı şartlarla önce homojen sürü (hepsi aynı görevde, örneğin 15 robotun tamamı wall follower), sonra heterojen sürü denendi. Simüle edilen odanın bir bölümü ısıtıldı ve robotların oraya yönelmesi beklendi. Bir deneyde heterojen gruptan duvara yönelen robot sayısı izlendi ve yaklaşık 10 robotun uyum sağladığı görüldü. Başka bir deneyde iki bölge sıcak kabul edildi: biri global hedef bölge, diğeri yerel hedef bölge; robotların hangisini seçeceği incelendi. Sonuçlarda homojen grup heterojen grubun gerisinde kaldı.

### 2.8 Görev Odaklı Optimizasyon ve Açık Problemler

Süre darlığı nedeniyle kısa geçilen bir başka çalışma, verilen bir görevi yapabilecek optimum heterojen sürüyü bulmayı amaçlıyordu (referans listesinde Nishikawa, Suzuki ve Arita, 2016). <!-- BELİRSİZ: Bu çalışmanın sonucu altyazıda anlaşılmıyor ("optimize edilmiş olanlar arasında bir asimetri" gibi bir ifade geçiyor). -->

Derlemeden alınan açık problemler:

- Görevler gün geçtikçe karmaşıklaşıyor; görevleri alt gruplara ayırıp daha etkin çözümler üretmenin yolu açılabilir.
- Otonom makine öğrenmesi, parametre ayarlamalarında kullanıldığı gibi dinamik çevre faktörlerini tahminlemede de kullanılabilir.
- Koalisyon oluşturma (coalition formation): bir görevi yapmak için küçük bir alt sürü kurulması. Birçok çalışmada bu hâlâ insan eliyle yapılıyor.
- Simülasyon ile gerçek dünya deneyleri arasında ciddi bir açık var.
- Transfer öğrenme: iki kez aynı senaryoyla karşılaşma olasılığı düşük olsa bile önceki deneyimlerden öğrenilen bilgiler yeni kararlar vermede ve onları geliştirmede kullanılabilir.

## 3. İkinci Sunum: Mikroservis Tabanlı Büyük Veri ve Makine Öğrenmesi Uygulamaları

Sunumun konusu mikroservis tabanlı büyük veri ve makine öğrenmesi uygulamaları üzerine yapılan bir sistematik literatür taramasıydı. Sunum planı: mikroservis mimarileri, makine öğrenmesi uygulamaları, büyük veri (big data), yazılım ürün hatları, değerlendirme yaklaşımları, sistematik literatür taraması, sonuçlar ve gelecek çalışmalar (ekrandan, 00:45:00).

### 3.1 Motivasyon

Yazılımda iki büyük kayma yaşanıyor. Birincisi mikroservis mimarisine geçiş: büyük şirketler uygulamalarını mikroservis mimarisine taşıdı, akademide de yazılım mimarisi ve yazılım mühendisliği konferanslarında bu konuda çok yayın yapılıyor. İkincisi yapay zekâ: makine öğrenmesi artık yalnız akademik bir alan değil, uygulamalı bir alana evrildi. Bu yüzden makine öğrenmesi uygulamalarının yazılım mühendisliği bağlamında, mimarisi ve süreçleriyle ele alınması gerekiyor. Burada şu sorular öne çıkıyor: makine öğrenmesi uygulamaları nasıl daha başarılı hâle getirilir, yakıtı olan veri nasıl yönetilir? Büyük veri, çok çeşitli, farklı hızlarda ve hacimlerdeki verinin yönetimini sağlayan teknoloji ve mimari yaklaşımları kapsar; verinin kalitesi makine öğrenmesi uygulamalarının başarısını doğrudan etkiler.

Ayrıca yazılım ürün hatları (bileşenlerin yeniden kullanımıyla farklı ürünler geliştirme) ve değerlendirme yaklaşımları (bu mimarilerin hangi ölçütlerle değerlendirileceği, başarının nasıl ölçüleceği) da araştırma sorularına katıldı.

### 3.2 Mikroservis Mimarileri

Ağ teknolojilerinde hızın ve güvenliğin artmasıyla yazılım sistemleri ağ üzerinden erişilebilir, yönetilebilir ve dağıtık makinelere konuşlandırılabilir hâle geldi. Bu dönüşümü en çok hızlandıran unsurlar bulut bilişim, sanallaştırma ve konteyner teknolojileri oldu. IoT ve Endüstri 4.0 gibi trendler ve internet servislerine artan ihtiyaç karmaşık sistemlere olan ihtiyacı artırdı. Mikroservis mimarisi, bu ihtiyaçların yazılım mimarisi boyutundaki izdüşümü olarak ortaya çıktı. Kısaca, yazılım sistemini kendi içinde tutarlı iş fonksiyonları içeren, tek bir amacı olan küçük ve hafif servislere ayırmaya odaklanır.

Slayttaki faydalar ve zorluklar (ekrandan, 00:50:00):

- **Faydaları:** ölçeklenebilirlik, idame edilebilirlik, çeviklikteki artış, geliştirici üretkenliğindeki artış, dayanıklılık, güvenilirlik, ilgilerin ayrıştırılması, kolay konuşlandırma.
- **Zorluklar:** servis keşfi ve kayıtlanma, güvenlik, mesajlaşma ve entegrasyonlar, veri yönetimi.

Faydalar şöyle açıklandı. Servisler dağıtık ve küçük olduğu için farklı teknolojilerle, farklı geliştiriciler ve ekipler tarafından geliştirilebilir; servisler birbirleriyle haberleşerek uygulamayı oluşturur. Teknolojiler değiştikçe eski (legacy) sistemlere yeni servisler eklenebilir. Daha küçük kod tabanlarıyla çalışmak hem kod kalitesini hem geliştirici motivasyonunu artırır. Kolay konuşlandırma şu demektir: servis dar kapsamlı ve tek iş fonksiyonlu olduğu için bir hata varsa yalnız o servise düzeltme (hotfix) yapılıp yeni sürümü CI/CD hattından geçirilir; üretim ortamında diğer servislere dokunulmaz. Derleme ve test süreleri de daha kısadır.

Zorluklar şöyle açıklandı:

- **Servis keşfi:** Dağınık yapıdaki servislerin haberleşmesi için bir servisin diğerinin adresini, sağlık durumunu, ayakta olup olmadığını ve replika sayısını bilmesi gerekir. Bunun için servislerin merkezî bir kayıt noktasına kaydolması gerekir.
- **Güvenlik:** Uygulama artık tek bir süreçle ayağa kalkmadığı için, belki yüzlerce servisten oluşan dağıtık yapının güvenliğini sağlamak zorlaşır.
- **Mesajlaşma ve entegrasyon:** Haberleşme artık süreç içi (in-process) değildir; A nesnesinin B nesnesini çağırması yerine A servisi B servisini çağırır. Bu, bir mesajlaşma altyapısı üzerinden yürür ve geliştiriciler için ciddi bir entegrasyon maliyeti getirir.
- **Veri yönetimi:** Senkron ve transactional bütünlüğü olması gereken veriyi farklı ele almak gerekir. Bir servisin transaction sınırında kaydedilen veri diğer serviste senkron olarak elde edilemez; bunun yerine eventual consistency kavramıyla verinin daha sonra asenkron olarak tutarlı olacağı garanti edilir, o anda garanti edilemez. Bu, programlama düşüncesini temelden değiştirir. Finans gibi atomik işlem zorunluluğu olan alanlarda servis sınırları buna göre belirlenmelidir; bu, mikroservis ayrıştırmasında önemli bir tasarım ölçütüdür.

Tüm fayda ve zorluklara rağmen endüstri bu stile ciddi biçimde adapte oldu ve mikroservis mimarisi artık fiilî (de facto) bir yazılım mimarisi stilidir. Sunumda endüstrinin bu stile gereğinden fazla adapte olduğu, trendlerin teknik ekipleri zorladığı da dile getirildi. Örnek olarak bir uygulamayı buluta taşımak için onu yeniden, bulut yerlisi (cloud native) olarak tasarlamak gerektiği; uygulamayı yalnız bir konteynere koymanın sorunu çözmediği söylendi. Kubernetes gerçekten pek çok şeyi çözer ve konteyner orkestrasyonunu yönetir, günümüzün bulut tabanlı işletim sistemi gibidir; ama önce uygulama düzeyinden başlayarak, veri ve uygulama koduyla bütüncül bir tasarım düşünülmelidir. Bu araçlar yalnız araçtır.

### 3.3 Makine Öğrenmesi Uygulamaları

Makine öğrenmesi uygulamaları, geçmiş verilerden öğrenerek tahminleme, planlama ve tanıma gibi karmaşık görevleri yapabilen uygulamalardır. Sunumda bu uygulamaların iş süreçlerine uyarlanmasının her yıl %25 arttığı aktarıldı. İki önemli unsur veri ve algoritmadır; ikisi de model performansı için kritiktir. Algoritmalar akademide çok çalışılıyor, ama verinin yönetimi, işlenmesi, depolanması ve kalite kontrolü gibi konular farklı boyutlarda ele alınması gereken konulardır.

### 3.4 Büyük Veri

Eğitilen makine öğrenmesi modelleri çoğunlukla büyük veriyle daha iyi sonuç verir. Veri kümesinin boyutu önemlidir ama önce kaliteli olması gerekir: verinin kaliteli biçimde toplanması, işlenmesi ve sorgulanabilmesi uygulamaların etkili olmasını sağlar. Bunu sağlayan araçlar artık gelişmiş durumdadır. Ancak veri büyüdükçe gereken hesaplama gücü çok artar; sunumda doğal dil işleme modellerinin eğitim maliyetinin küresel ısınmaya katkısını tartışan yayınlar olduğu da söylendi. Bu yüzden small data ve transfer öğrenme gibi yaklaşımlar popülerleşiyor.

### 3.5 Makine Öğrenmesi Uygulamalarını Geliştirmenin Zorlukları

Slayta göre makine öğrenmesinin akademideki ele alınışı ile gerçek yaşam problemlerine uygulanışı arasında önemli farklar vardır (ekrandan, 00:55:00):

- **Kalite güvence:** Canlı bir sistemde ve üretim ortamında çok önemlidir, çünkü uygulama iş süreçlerini doğrudan etkiler; bir anomali ya da arıza durumunda sonuçları ağırdır.
- **Veri ve model yönetimi:** Mimaride artık veri ve model gibi yeni unsurlar vardır; bunların tüm yaşam döngüsü boyunca yönetilmesi gerekir.
- **Konuşlandırma:** Uygulama ölçeklenebilir, erişilebilir ve güvenilir olmalıdır.
- **İzleme ve veri etiketleme:** İleri düzeyde bir izleme altyapısı gerekir; eğitim setinde kullanılan verinin etiketlenmesi ve doğru etiketlenmesi gerekir.

Bunlar klasik yazılım mühendisliğinde karşılaşılmayan, yapay zekâ uygulamasına özgü yeni problemlerdir. Slaytta Paleyes ve arkadaşlarının NeurIPS 2020 kapsamındaki bir atölyede yayımlanan "Challenges in Deploying Machine Learning: a Survey of Case Studies" derlemesinden şu alıntı vardı: topluluk, izlenmesi gereken veri ve model metriklerini ve bunlara nasıl alarm üretileceğini anlamanın erken aşamasındadır; değişen girdi verisinin, tahmin yanlılığının (prediction bias) ve modelin genel performansının izlenmesi açık bir problemdir (ekrandan, 00:55:00). Sunumun yaklaşımı, bu zorlukları bütüncül bir yaklaşımla gidermek için yazılım mimarisi yaklaşımlarına odaklanmaktı.

### 3.6 Neden Mikroservis?

En naif çözüm bilinen yazılım mimarisi örüntülerini bu ihtiyaçlara göre özelleştirmektir. İlk akla gelen örüntü servis yönelimli mimarilerdir (SOA); ama bunlar sahada çok yansıma bulmadı ve merkezî yapıları yüzünden ölçeklenme konusunda endişe yaratıyor. Onun yerine tamamen dağıtık, otonom ve bağımsız mikroservislerle bu sorunlar giderilebilir. Araştırmanın hedefi, veri keşfi, veri kümesi hazırlama, model eğitimi, konuşlandırma ve başarı ölçümü gibi makine öğrenmesi unsurlarını mikroservis mimarileri özelinde konumlandırmak ve mikroservislerin üretim ortamındaki sorunlara nasıl çare olduğunu incelemektir.

### 3.7 Yazılım Ürün Hatları ve Değerlendirme Yaklaşımları

Yazılım ürün hattı, araba üretimindeki üretim hattına benzer bir yaklaşımdır. Ortak bileşenler ve değişen bileşenler vardır; değişen bileşenler yönetilip konfigüre edilerek bir yazılım ürünü elde edilir. Bu yaklaşım yeniden kullanılabilirliği çok artırır, maliyeti düşürür ve daha kaliteli uygulama geliştirmeyi sağlar; bileşenler tekrar tekrar kullanıldığı için kalite güvencesi daha iyi sağlanır. Araştırma sorularından biri bu tekniğin makine öğrenmesi sistemlerinde nasıl kullanılacağıydı.

Değerlendirme yaklaşımları için yazılım mühendisliğinden gelen gelişmiş geleneksel yöntemler vardır. Ancak makine öğrenmesi uygulamalarının yeni ihtiyaçlarına göre hangi değerlendirme metrikleri ve kriterleri gerektiğinin belirlenmesi ve mikroservis tabanlı ML uygulamalarının başarısının mimari perspektiften nasıl değerlendirileceği ayrı bir araştırma sorusu oldu.

### 3.8 Sistematik Literatür Taramasının Yöntemi

Yöntem şu adımlardan oluştu (ekrandan, 01:00:00): araştırma soruları, araştırma süreci, seçim kriterleri, kalite değerlendirme, veri toplama, veri sentezi ve sonuçlar.

- Beş araştırma sorusu tanımlandı.
- Arama sorguları "microservice" ile "big data" ve "microservice" ile "machine learning" kelime çiftlerinden ve bunların farklı yazımlarından kuruldu. Beş farklı veri kaynağı tarandı.
- Belirlenen kriterlere göre ilk eleme yapıldı ve 104 makaleye inildi.
- Snowballing süreci yürütüldü: bu makalelere atıf yapan ve bu makalelerin referans gösterdiği makaleler de incelendi.
- Seçilen makaleler tam metin okunarak nicel bir kalite değerlendirmesinden geçirildi ve 45 makaleye inildi. Puanlama tablosu uzun olduğu için sunuma konmadı. Yalnız 9-16 aralığında puan alan makaleler tutuldu. <!-- BELİRSİZ: Altyazıda "8'den aşağı olan tüm makaleleri eledik" deniyor; 8 puanın elendiği mi tutulduğu mu net değil. -->
- Belirlenen anahtar kelimelerle veri çıkarımı yapıldı, makaleler sınıflandırıldı ve bulgular araştırma sorularına göre toparlandı.

Kalite değerlendirmesinde makalelerin büyük kısmının elendiği, alanın endüstri tarafından sürüklenmesinin literatürdeki kaliteyi düşürmüş olabileceği yorumu yapıldı.

45 makalenin 37'si konferans bildirisi, 8'i dergi makalesiydi ($37 + 8 = 45$). Yayın sayısı her yıl artış eğiliminde ve çoğunluğu konferans bildirisi.

### 3.9 Bulgular

**Birinci soru: büyük veri mimarileri ile mikroservisler aynı mimaride nasıl yer alabilir?** Büyük veri mimarisinde iki temel örüntü öne çıkıyor: Lambda ve Kappa. Literatürde çoğunlukla Lambda mimarisi raporlanmış, bir de farklı ve spesifik bir mimari önerisi var. Lambda mimarisinin temel unsurları akan veri için hız katmanı (speed layer), toplu işlem katmanı (batch layer) ve sunum katmanıdır (serving layer); bunların merkezinde değişmez (immutable), yalnız okunan arşiv verisinin tutulduğu bir veri depolama katmanı vardır. Literatürdeki en tipik kullanımda işlem katmanındaki her işlem birimi bir mikroservis olarak konuşlandırılır; servis katmanında ise analitik yapan ve veriyi dış tüketicilere API ya da başka bir arayüzle sunan mikroservisler bulunur. Servisler arası haberleşme çoğunlukla asenkrondur, bu yüzden bu yapılar çoğunlukla reaktif mikroservis olarak tanımlanır. Bazı çalışmalarda hesaplama katmanında asenkron işçiler (async worker) mikroservis olarak konumlandırılmış; bazılarında veri tabanı servisin bünyesinde müstakil tutulmuş ve tüm servisler bir mesajlaşma altyapısı üzerinden asenkron haberleşmiş. Veri tabanı açısından iki örüntü öne çıkıyor: database per service ve shared database (ortak veri katmanı).

> **Ek bilgi (derste anlatılmadı):** Lambda mimarisinde aynı veri hem toplu işlem hem akış işleme yolundan geçer ve sonuçlar sunum katmanında birleştirilir. Kappa mimarisi ise büyük olasılıkla toplu işlem katmanını kaldırıp tüm veriyi tek bir akış işleme hattıyla işler.

**İkinci soru: makine öğrenmesi uygulamaları mikroservis mimarisine nasıl uyarlanabilir?** Google'ın "Hidden Technical Debt in Machine Learning Systems" çalışmasındaki şekle göre gerçek ML sistemlerinin yalnız küçük bir kısmı ML kodudur; çevresindeki altyapı geniş ve karmaşıktır (ekrandan, 01:05:00). Şekildeki bileşenler: konfigürasyon, veri toplama, veri doğrulama, özellik mühendisliği, test ve hata ayıklama, kaynak yönetimi, model analizi, süreç yönetimi, metadata yönetimi, otomasyon, sunum altyapısı ve izleme; ortada küçük bir kutu olarak ML kodu. Sunumda gösterilen bir örnek çalışmada (S4, genel ML hatlarını destekleyen bir mikroservis mimarisi önerisi) REST API'li servisler vardı: akış kontrol servisi, veri toplayıcı servis, orkestratör servis, veri işleyici servis, özellik (features) servisi, tahmin (predict) servisi ve son işlem (post processing) servisi; veri ve modeller ortak bir depolama biriminde tutuluyordu (ekrandan, 01:05:00). Bu örnekte birçok unsur eksikti; araştırmanın amacı hangi unsurların bulunması gerektiğini ve değerlendirme ölçütlerini ortaya koymaktır.

**Üçüncü soru: mikroservis tabanlı makine öğrenmesi uygulamaları hangi endüstri alanlarına yönelmiş ve hangi zorluklarla karşılaşılmış?** En çok IoT ve Endüstri 4.0 bağlamında uygulamalar görüldü. İncelenen 45 makalede temel problemler konuşlandırma, servis orkestrasyonu ve değerlendirme yöntemleriydi.

**Dördüncü soru: yazılım ürün hattı yöntemleri nasıl uygulanabilir?** Servislerle bileşenleştirme yaklaşımı öne çıkıyor. Servisler arası kod ve çağrı bağımlılıkları ele alınıyor; bu bağımlılıklar gözetilerek servislerin bir alt kümesi seçiliyor ve bu küme bir ürünü oluşturuyor. Her servis multi-tenant biçimde kullanılarak yeniden kullanılıyor: farklı kiracılar için farklı konfigürasyon parametreleri geçirilerek aynı kod tabanına sahip servis çalıştırılabiliyor. Bu konuda dört makale bulundu; farklı araştırma grupları olsa da aynı yöntemi kullanmışlar.

**Beşinci soru: mikroservis tabanlı makine öğrenmesi uygulamaları için değerlendirme ölçütleri ve kriterleri nelerdir?** Doğrudan ML uygulamalarına yönelik bir çalışma bulunamadı; bu yüzden yalnız mikroservisler için önerilen değerlendirmelere bakıldı. Bunlar klasik yazılım mühendisliğinden gelen yaklaşımlardır: kalite özelliklerinin tanımlanması, servis özelliklerinin tanımlanması ve metriklerin tanımlanması. Metrikler genelde servis çağrıları ve senkron/asenkron haberleşme gibi konulardır. Oysa veri ve modelin öne çıktığı uygulamalarda verinin nasıl sürüm kontrolünde tutulacağı ve kalitesinin nasıl ölçüleceği gibi pek çok açık soru vardır; idame edilebilirlik gibi kalite özelliklerini karşılayan yeni metrikler önerilebilir.

### 3.10 Gelecek Çalışmalar

Sistematik literatür taramasının ortaya koyduğu açık problemler üzerine yeni yaklaşımlar, örüntüler ve değerlendirme yöntemleri geliştirmek; bir kavram kanıtı (proof of concept) uygulaması ve vaka çalışmasıyla deneysel kanıt sunmak hedefleniyor.

## 4. Üçüncü Sunum: Çoklu Robotlarda Harita Gösterimi ve Harita Birleştirme

Sunum başlıkları: konuya giriş, harita gösterimi, harita gösterim çeşitleri, harita birleştirme yöntemleri ve sonuç.

### 4.1 Giriş: Neden Robot ve Neden Harita Birleştirme?

Haritalama robotik için önemli bir problemdir. Tek robot için çözümler vardır; ama birlikte çalışan çoklu robotlar söz konusu olunca harita birleştirme bir sorun olarak gündeme gelir.

Robotlar, insanlar için tehlikeli olabilecek ve insanların yapmakta zorlanacağı işlerde kullanılır: okyanus derinlikleri, aktif volkanların çevresi, doğal afetlerde arama tarama, yer altı maden arama, deprem sonrası hasarlı binalar, denizaltı keşifleri ve uzay araştırmaları.

Bu bağlamda ilk karşılaşılan konu SLAM'dir (Simultaneous Localization and Mapping, eş zamanlı konum belirleme ve haritalama) (ekrandan, 01:10:00). SLAM ile zorlu koşullarda çalışan otonom robotlar için haritalar üretilir; kısmen bilinen ya da hiç bilinmeyen bir ortamda eş zamanlı haritalama ve konum belirleme yapılabilir. Haritalanacak ortamın boyutu haritalama sürecini etkileyen kritik bir faktördür: ortam büyüdükçe veri toplamak ve haritayı oluşturmak uzar ve hata olasılığı artar. Bu yüzden haritalamayı en az hata ve sürede tamamlamak için çoklu robotlu SLAM teknolojilerine ihtiyaç duyulur. Ortam haritalama süreci ortamı algılama, özniteliklerin çıkarılması ve verilerin gösterimi aşamalarından oluşur.

### 4.2 Harita Gösterim Çeşitleri

Sunumda iki boyutlu haritalar ele alındı. Literatürde genelde iki boyutlu haritalar tercih ediliyor; üç boyut üzerinde daha az çalışılıyor, bunun nedeni büyük olasılıkla derinlik boyutunun işi zorlaştırmasıdır. İki boyutlu haritalar için üç gösterim tekniği vardır.

**Doğrudan gösterim (direct representation):** Ham sensör taramalarının kayıtlı bir listesi olarak temsil edilir. Slayta göre doğrudan gösterim, algılama sistemini sensör verisi dönüşümünden muaf tutar (ekrandan, 01:15:00). Dezavantajları: boş alanı modellemek gibi harita belirsizliklerini ve sensörün doğrudan ölçemediği alanı modellemek zordur; haritayı yönetmek zordur.

**Özellik tabanlı gösterim (feature-based):** Sensör verilerinden çıkarılan bir özellik grubunu temsil eder. Bu özellikler yapay işaretler ya da dış mekândaki ağaçlar veya nesnelere ait çizgi bölümleri gibi doğal işaretler olabilir. Düşük bellek gerektirdiği ve harita ayarlamasında yüksek esnekliğe sahip olduğu için tercih edilir. Dezavantajı, gösterim yalnız belli özellikler çerçevesinde yapıldığı için genel ortam hakkında bilgi vermemesidir.

**Doluluk ızgarası gösterimi (occupancy grid):** Ortam dikdörtgen hücrelere bölünür, yani iki boyutlu bir matris olarak düşünülür. Her hücre, nesnenin işgal ettiği ya da boş olan hücrenin durumunu gösteren 0 ile 1 arasında bir değerle ilişkilendirilir. Hücre değeri ne kadar büyükse hücre dolu olma eğilimindedir (1'e yakın), ne kadar küçükse boş olma eğilimindedir (0'a yakın). <!-- BELİRSİZ: Altyazıda bilinmeyen durumu gösteren değer söyleniyor ama değer kaçmış; büyük olasılıkla 0,5. --> Bu gösterim genel ortamı temsil etme ve harita belirsizliğini modelleme açısından avantaj sağlar.

### 4.3 Harita Birleştirme

Harita birleştirme, bir dizi kısmi haritadan ortamın tek ve tutarlı bir haritasını oluşturmaktır. Çalışmada iki boyutlu veriler üzerinde durulmuştur. Verileri tamamen yeniden işlemek yerine mevcut, tamamlanmamış haritaları yeniden kullanması ve parçalı bir yönetim stratejisi uygulanabilmesi gibi avantajları vardır. Genel olarak iki tür yöntem vardır: araç poz tahmini tabanlı yöntemler ve harita tutarlılığına dayalı yöntemler.

**Araç poz tahmini tabanlı yöntemler:** Bir aracın diğer aracı algılamasından ve bu algılamadan çıkarılan göreceli (relatif) poz tahminlerinden yararlanır; araçtan araca (vehicle-to-vehicle) ilişki kurma prensibiyle çalışır. Süreç üç adımdır: algılama, ilişkilendirme ve göreceli poz tahmini. Her araç evrensel bir konum bilgisine erişebiliyorsa farklı araçlar yerel konum bilgilerini algılayıcılar aracılığıyla ortak bir konumla ilişkilendirebilir. Ancak her aracın hassas, gerçek konum bilgisine erişmesi güçtür. GPS ile donatılmış araçlarda bile konum belli bir artı-eksi hatayla ölçülür; yüksek hassasiyetli GPS kullanıldığında bile ortamdaki sinyal bozulmaları gibi nedenlerle hatalar oluşabilir.

**Harita tutarlılığına dayalı yöntemler (map consistency based methods):** Araç duruşunun ya da araçtan araca göreceli pozun doğru tahminini gerektirmez. Haritalar arasındaki belirli bir tutarlılık ölçüsüne göre iki haritayı doğrudan birleştirmeye çalışır. Üç kategoride incelenir (ekrandan, 01:20:00):

- Özellik tabanlı yöntemler
- Yinelemeli en yakın nokta (Iterative Closest Point, ICP) yöntemleri
- Doğrudan optimizasyona dayalı (Overall Direct Optimization, ODO) yöntemler

**Özellik tabanlı yöntemler:** Birleştirmeyi kolaylaştırmak için doğal ya da yapay olarak belirlenen özellikler üzerinde çalışır. Nesnelere ait şekil, renk, boyut gibi özellikler göz önünde bulundurularak ilişkilendirme kurulur. Özellik tabanlı gösterimde özelliklerin varlığı, algıları ilişkilendirme sürecini kolaylaştırır.

**ICP yöntemleri:** Haritalardan özellik çıkarmadan birleştirme yapar ve iki adımlı bir yinelemeden oluşur. Birinci adımda en yakın nokta kuralına göre iki algı arasında bir karşılıklılık (nokta eşleşmesi) dizisi kurulur. İkinci adımda bu dizideki noktalar arasındaki toplam mesafe en aza indirilerek algı hizalaması tahmin edilir. Uygun bir başlangıç değeri verildiğinde iki adımın yinelenmesiyle hizalama tahmini yakınsar; yinelemeli yapı sayesinde hata en aza indirilir.

> **Ek bilgi (derste anlatılmadı):** ICP'nin ikinci adımı büyük olasılıkla $\min_{R,t} \sum_i \lVert R\,p_i + t - q_i \rVert^2$ biçiminde yazılır: $p_i$ bir haritadaki nokta, $q_i$ ona eşleştirilen en yakın nokta, $R$ dönme ve $t$ öteleme. Yöntem yerel minimuma takılabildiği için iyi bir başlangıç hizalaması önemlidir; sunumdaki "uygun başlangıç değeri" vurgusu buna karşılık gelir.

**ODO yöntemleri:** İki adımdan oluşur. Birinci adımda harita hizalaması girdi olarak alınır ve bu hizalamanın genel tutarlılık derecesini gösteren bir değer amaç fonksiyonu (objective function) olarak tanımlanır. İkinci adımda belirli bir optimizasyon tekniğiyle optimal harita hizalaması aranır.

### 4.4 Sonuç

Sunumun sonuç slaytındaki noktalar (ekrandan, 01:25:00):

- Afet bölgelerinde arama kurtarma, askerî amaçlı mühimmat taşıma, denizaltı keşifleri gibi insanlar için tehlikeli olabilecek yerlerde robotlar önemli görevler üstleniyor.
- Robotlar, diğer robotların çevre haritasını kendi bireysel haritalarıyla birleştirerek ortamın diğer bölümlerinin iç yapısı hakkında bütünleşik bilgi edinebilir.
- İşbirliğine dayalı harita oluşturma, birlikte hareket eden robotlar için sürüş güvenliğini ve verimliliğini artırmak için önemlidir.
- Çalışmada işbirliği içinde çalışan otonom robotlar için harita birleştirme yöntemleri ele alındı.
- Bir harita birleştirme yöntemi ele alındığında, birleştirilen haritanın doğruluğunu değerlendirmek için hangi yöntemin tercih edileceği çözülmeyi bekleyen bir sorundur.
- Çoklu robotlarla yapılan çalışmalarda harita birleştirme için genelde ICP yöntemi üzerinde duruluyor.

Robotlar birlikte çalıştığında ortak bir görevin parçalarını üstlenir; aralarında iletişim kurulduğunda süreç daha sağlıklı yönetilir. Sunumda literatürdeki iki güçlük de belirtildi: konu dağınık olduğu için harita birleştirme yöntemlerini toplu olarak sunan bir kaynağa erişmek zor; çalışmaların ağırlıkla iki boyutlu haritalar üzerinde olması literatürü sınırlıyor. Ayrıca uydu görüntülerinden iki boyutlu haritalara kadar farklı harita türlerinin her birini ayrı değerlendirmek zaman alıyor ve robotların kamera, sensör gibi algılayıcılardan aldığı bilginin doğruluğu ikinci bir problem olarak ortaya çıkıyor.

## 5. Hocanın Sunumlara Genel Geri Bildirimleri

**Kaynak sayısı ve güncellik:** Birinci sunumda sekiz makalenin okunup değerlendirilmesi ayrıntılı bir inceleme olarak görüldü. Hoca kaynakların yayın tarihlerine baktı; günümüze yakın tarihli makalelerin bulunmasını çok önemli buldu. Üçüncü sunumun referanslarında da tarihleri tek tek inceledi; en yeni kaynakların 2018, 2019 ve 2020 tarihli olduğunu gördü.

> **Hocanın vurgusu:** Okunan makalelerin güncel olması, günümüze yakın tarihli makalelerin de bulunması çok önemli.

**Atıf sayıları:** Hoca referans listesinde her satırın sonuna, parantez içinde o kaynağın kaç kez atıf aldığının yazılmasını istedi. 2020'de çıkmış bir makalenin atıf sayısının az olması doğaldır; atıf sayıları yayın tarihiyle ilişkilendirilerek değerlendirilir.

**Kısaltmalar:** Üçüncü sunumda ICP ve ODO kısaltmaları açılmadan kullanılınca hoca, kısaltmaların açık hâlinin de verilmesini, özellikle kısaltma slayt başlığı yapıldıysa açık hâlinin başlığa yazılmasını önerdi.

**Arama tekniği:** Hoca ikinci sunumdaki sistematik arama ve makale eleme sürecini en çok beğendiği bölüm olarak gösterdi ve örnek bir çalışma olarak nitelendirdi.

**Soru sorma:** Hoca dinleyicileri çekinmeden soru sormaya çağırdı. Seminerin amacı fikir alışverişidir; bir dinleyicinin sorusu, sunan kişinin aklına gelmeyen bir noktada ona fikir verebilir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:40:00): Literatür taramasında incelediğin makalelerin atıf sayılarına baktın mı?

> **Cevap (derste verildi):** İncelenen çalışmaların atıf sayıları 25-26 civarındaydı, derlemelerin atıf sayısı ise yüzleri aşıyordu; kaynaklar atıf sayılarına göre seçilmişti. Hoca, her kaynağın atıf sayısının referans listesinde satır sonuna parantez içinde yazılmasını, yeni makalelerin atıf sayısının ise yayın tarihiyle birlikte değerlendirilmesini istedi.

**Soru 2** (derste sözlü, 01:22:57): Slayttaki ICP kısaltması neyin kısaltmasıdır?

> **Cevap (derste verildi):** Iterative Closest Point, yani yinelemeli en yakın nokta yöntemi.

**Soru 3** (derste sözlü, 01:23:18): Slayttaki ODO kısaltması neyin kısaltmasıdır?

> **Cevap (derste verildi):** Overall Direct Optimization, yani doğrudan optimizasyona dayalı yöntemler. Hoca, kısaltma slayt başlığında kullanıldığında açık hâlinin de başlığa yazılmasını önerdi.

## Dersin Toparlaması

Bu derste üç seminer sunumu üzerinden literatür taramasının farklı biçimleri görüldü. Birinci sunum, robot sürülerinin temel kavramlarını (homojen ve heterojen sürüler, merkezi, merkezi olmayan ve hibrit yönetim, self-organization, ölçeklenebilirlik, enerji tasarrufu) verip seçilmiş çalışmaları (iki katmanlı formasyon sistemi, Swarmanoid, BEECLUST ile davranışsal heterojenlik) ve açık problemleri tanıttı. İkinci sunum, mikroservis mimarilerinin fayda ve zorluklarını, makine öğrenmesi uygulamalarının üretim ortamındaki zorluklarını ve bunların kesişimini inceleyen, arama, eleme, snowballing ve kalite puanlaması adımlarıyla yürütülmüş bir sistematik literatür taramasını anlattı. Üçüncü sunum, çoklu robotlu SLAM bağlamında harita gösterimlerini (doğrudan, özellik tabanlı, doluluk ızgarası) ve harita birleştirme yöntemlerini (araç poz tahmini tabanlı, özellik tabanlı, ICP, ODO) karşılaştırdı.

Hocanın geri bildirimleri bir literatür taramasında nelere dikkat edileceğini özetliyor: kaynaklar güncel olmalı, atıf sayıları raporlanmalı ve yayın tarihiyle birlikte yorumlanmalı, kısaltmalar açık hâliyle verilmeli, arama ve eleme süreci sistematik ve açık biçimde anlatılmalı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
