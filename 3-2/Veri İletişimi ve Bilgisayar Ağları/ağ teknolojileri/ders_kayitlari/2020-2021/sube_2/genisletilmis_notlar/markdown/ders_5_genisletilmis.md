# Ders 5 Genişletilmiş Notu: Ağ Katmanında Tıkanıklık Kontrolü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Tıkanıklık Nedir ve Neden Ağ Katmanının Sorunudur
- 2. Proaktif ve Reaktif Yaklaşımlar
- 3. Goodput Eğrisi ve Tıkanıklık Çöküşü
- 4. Yaklaşımların Zaman Ölçeği
- 5. Network Provisioning
- 6. Traffic-Aware Routing
- 7. Admission Control
- 8. Traffic Throttling
- 9. Load Shedding
- 10. Hizmet Kalitesine Geçiş
- Örnek Sorular
- Dersin Toparlaması

## 1. Tıkanıklık Nedir ve Neden Ağ Katmanının Sorunudur

Ders, bir önceki haftada işlenen yönlendirme algoritmalarının devamı olarak tıkanıklık kontrolü (congestion control) konusuyla açıldı. Hoca konuya günlük hayattan bir benzetmeyle girdi: yollar belirli bir araç kapasitesine göre planlanır. Bu kapasiteden fazla araç yola çıkarsa trafik sıkışır, normal hızda gidilemez, varış süreleri uzar ve hareket hızı planlanan hızın çok altına düşer.

Aynı durum bilgisayar ağları için de geçerlidir. Ağ katmanının temel görevlerinden biri, bir topoloji içinde paketi çıkış noktasından hedef noktaya aktarmaktır. Özellikle ad hoc olmayan, kağıt üzerinde tasarlanıp kurulmuş bir topolojinin tasarım sırasında belirlenmiş bir paket aktarım kapasitesi vardır. Bu kapasite aşıldığında gerçek hayattakine benzer bir sıkışıklık oluşur: ağ paketleri aktaramaz hale gelir, hatta hiçbir şeyin ilerlemediği tam bir durma noktasına varılabilir. Bu yüzden ağ katmanı içinde bu durumun oluşmasını engelleyen ya da oluştuysa çözen mekanizmalar bulunmalıdır.

### 1.1 Üç katmanı ilgilendiren bir konu

Hoca tıkanıklık kontrolünün yalnız ağ katmanında çözülebilecek bir konu olmadığını vurguladı. Daha alttaki bağlantı (link) katmanında da, ağ katmanında da, üstteki taşıma katmanında da tedbir alınması gerekir. Bağlantı katmanındaki tıkanıklık kontrolü bu dersin değil, veri iletişimi dersinin kapsamındadır; o tarafı tazelemek isteyenlere o dersin kaynakları önerildi. Kavramsal olarak üç katmanda konuşulan şeyler birbirine çok benzer. Fark şudur: bağlantı katmanı noktadan noktaya çalışır; ağ katmanı ve taşıma katmanı ise uçtan uca çalışır, yani yönlendirmede de görüldüğü gibi birden fazla atlama (hop) ile bir başlangıç noktasından hedef noktasına ilerlenir.

Slaytta da tıkanıklıkla başa çıkmanın ağ ve taşıma katmanlarının birlikte çalışmasıyla mümkün olduğu, bu bölümde ağ katmanı kısmına bakılacağı yazıyordu (ekrandan, 00:05:00). Aynı slaytta işlenecek dört başlık sıralanmıştı:

- Traffic-aware routing
- Admission control
- Traffic throttling
- Load shedding

### 1.2 Dört başlığa ilk bakış

Hoca ayrıntıya girmeden önce dört başlığı kısaca tanıttı:

- **Traffic-aware routing:** Akıtılacak trafiğin miktarı bilinirse buna göre akıllı bir yönlendirme algoritması çalıştırılabilir ve tıkanıklık oluşması engellenebilir. Bir önceki konu olan yönlendirmeyle doğrudan ilişkilidir.
- **Admission control (kabul kontrolü):** Burada kabul edilen şey, gönderilmek üzere bir paketin ağ katmanınca teslim alınmasıdır. Ağ katmanı belirli paket teslim alma kuralları çalıştırabilir ya da uygulamalarla bir "anlaşma" yapabilir. Örneğin uygulamanın karakteristiğine göre saniyede en fazla 100, 50 ya da 1000 paket kabul eder, fazlasını kabul etmez.
- **Traffic throttling (trafiği frenleme):** "Throttle" burada yavaşlatma, frenleme anlamındadır. Gelen trafik bekletilerek çıkışa gönderilir, böylece çıkıştaki akış girişteki akıştan düşük olur. Bunun için yavaşlatmayı yapan yerde, yani yönlendiricide, ciddi bir tampon (buffer) bellek bulunmalıdır; çünkü giriş hızı çıkış hızından yüksektir ve aradaki paketlerin bekletileceği bir bölge gerekir. Belleğin de bir sınırı vardır.
- **Load shedding (yük atma):** Paketleri biriktirip yavaşlatacak tampon alanı da kalmamış ama paketler gelmeye devam ediyorsa, gelen paketler gelmemiş kabul edilir; yani paketlerden kurtulunur.

## 2. Proaktif ve Reaktif Yaklaşımlar

Ağ katmanının tıkanıklığa karşı kullanabileceği yaklaşımlar iki gruba ayrılır:

- **Proaktif (önleyici, preventatif) yaklaşımlar:** Tıkanıklık oluşmadan önce planlama yapılır, tedbir alınır ve tıkanıklığın hiç oluşmaması hedeflenir.
- **Reaktif yaklaşımlar:** Tıkanıklık oluştuktan sonra bu duruma bir tepki (reaksiyon) gösterilerek çözülür. Beklenirse durum daha da kötüleşeceği için müdahale gerekir.

Neden iki tür yaklaşım olduğu sorusuna hoca, pek çok mühendislik probleminde görülen ödünleşimle (trade-off) cevap verdi: bir şey olmasın diye tedbir alındığında başka bir şeyden taviz verilir.

### 2.1 Proaktif yaklaşımın bedeli: atıl kapasite

Bir ağın tıkanıklık olmadan çalışması öngörülüyorsa, çoğunlukla ağın kağıt üzerindeki kapasitesinin yüzde yüzü kullanılmaz; örneğin yüzde 70'inde ya da yüzde 80'inde kalınır. Böylece tıkanıklık hiç oluşmaz, ama kullanılmayan yüzde 30'luk ya da yüzde 20'lik dilim faydaya dönüşmez.

Proaktif yaklaşımlar "beyan usulü" çalışır: bir uygulama başka bir uygulamayla konuşacağı zaman "trafiğim budur, birim zamanda şu kadar bit göndereceğim" der (kilobit, megabit ya da gigabit cinsinden). Oysa bir uygulamanın durmadan, sürekli o kadar büyük bir trafik üretmesi mümkün değildir. Ses ya da görüntü akışı (streaming) gibi özel durumlarda bile bunun bir süresi vardır (5 dakika, yarım saat, 1 saat gibi); sonra trafik azalır ya da değişir. Uygulama beyanını üretebileceği en üst trafik miktarına göre yaptığı ve bu miktar ağ kapasitesinden düşüldüğü için, diğer uygulamalar açısından normal şartlarda kullanılmayan, kenarda atıl duran bir kapasite oluşur.

### 2.2 Reaktif yaklaşıma neden ihtiyaç var

Atıl kapasite olmasın, ağdan daha fazla yararlanılsın denirse bu kez başka bir sorun doğar. Tek bir uygulamadan değil, N tane uygulamadan söz edilir. Öyle anlar gelir ki birden fazla uygulamanın paket trafiği açısından tepe (peak) noktaları üst üste biner. Bu anlardaki ihtiyaçlar toplandığında ağın toplam paket aktarım kapasitesinin çok üzerine çıkılır ve tıkanıklık oluşur.

Hoca bunu evlere bağlı internet ve telefon servisleriyle örnekledi. Bu servisler ortalama bir yoğunluk hesabına (yüzde 70 ya da yüzde 80 doluluk) göre tasarlanır. Doğal afet gibi acil bir durumda herkes aynı anda birilerine ulaşıp durumunu öğrenmek, mesaj gönderip cevap almak ister. O anda telefonlar meşgul sesi bile veremez, mesajlar gidemez ve bir kilitlenme yaşanır. Planlanan kullanım yüzdesi aşıldığında artık reaktif olarak müdahale etmek gerekir.

## 3. Goodput Eğrisi ve Tıkanıklık Çöküşü

Slaytta şu ifade yer alıyordu (ekrandan, 00:20:00): ağa fazla trafik verildiğinde tıkanıklık oluşur ve kayıp ya da tekrar gönderimler (retransmission) nedeniyle performans düşer; goodput (yararlı paketler) sunulan yükün gerisinde kalır.

### 3.1 Tekrar gönderimler neden artar

Hoca bağlantı yönelimli (connection-oriented) ve bağlantısız (connectionless) servisleri hatırlattı. Bağlantı yönelimli iletişimde iki taraf el sıkışır; bir taraf paket gönderir, diğeri bu paketi bekler. Paket gelmezse alıcı açıkça yeniden ister, ya da göndericiye onay gitmediği için gönderici paketin başına bir şey geldiğini düşünüp yeniden yollar. Oysa paket aslında yoldadır, yalnız tıkanıklık yüzünden yavaş iletilmektedir. Ağ açısından görünen sonuç çok basittir: ağdaki paket sayısı artar.

### 3.2 Throughput ve goodput

Throughput (verim), bir sistemin girdiyi alıp işleyip çıkışa vermesiyle yaptığı iş miktarıdır. Goodput ise olması gereken zaman sınırları içinde, gitmesi gereken hedefe aktarılabilen paket miktarıdır.

### 3.3 Grafiğin okunması

Grafikte yatay eksen sunulan yüktür (offered load, paket/s), düşey eksen goodput'tur (paket/s). Kesikli yatay çizgi ağın kapasitesini (capacity of the network) gösterir (ekrandan, 00:20:00). Üç eğri vardır:

| Eğri | Davranış |
|---|---|
| Ideal | Kapasiteye kadar doğrusal artar, sonra kapasite çizgisinde düz devam eder. |
| Desirable response | Bir yere kadar doğrusal gider, sonra kapasiteye asimptotik olarak yaklaşır, hiç ulaşmaz. |
| Congestion collapse | Bir tepeye çıktıktan sonra yük arttıkça goodput hızla düşer. |

Eğrinin doğrusal kısmında ağa verilen yük arttıkça paketler aynı hızla hedefe teslim edilir: gecikme, kayıp ya da tekrar gönderim yoktur. İdeal durumda eğri kapasite çizgisine kadar hiç bükülmeden gidip orada düz devam etmelidir; ama bu mümkün değildir. Hatalar, bunlara bağlı kayıplar ve tekrar gönderimler mutlaka olur. Anlık sıçramalar bile ağın taşıdığı yükü oynatıp bir denge noktasından çıkardığı için salınımlar oluşur ve bu salınımlar tıkanıklığa yol açar.

Bu yüzden hedeflenen eğri "desirable response"tur: belirli bir noktaya kadar doğrusal, sonra kapasiteye sonsuzda yaklaşan bir eğri. Tıkanıklık kontrolü tam olarak bunu sağlamaya çalışır. Düzgün tedbirler ve kontroller yapılmazsa ağ, tıkanıklıktan dolayı çöker (congestion collapse).

Grafikte pembe elipsle işaretlenmiş bölge tıkanıklık başlangıcıdır (onset of congestion).

> **Hocanın vurgusu:** Kontrol için ne yapılacaksa tıkanıklık başlangıcı bölgesinde yapılmalıdır; o bölgenin bir adım ötesinde artık tıkanıklık ve kontrolsüzlük vardır.

## 4. Yaklaşımların Zaman Ölçeği

Slaytta ağın sunulan yükle elinden gelenin en iyisini yapması gerektiği, farklı zaman ölçeklerinde farklı yaklaşımlar olduğu ve düğümlerin de sunulan yükü azaltması gerektiği (taşıma katmanı) yazıyordu (ekrandan, 00:25:00). Yaklaşımlar bir eksen üzerinde soldan sağa şöyle diziliydi:

| Sıra | Yaklaşım | Konum |
|---|---|---|
| 1 | Network provisioning | En yavaş, önleyici uç |
| 2 | Traffic-aware routing | |
| 3 | Admission control | Ortada |
| 4 | Traffic throttling | |
| 5 | Load shedding | En hızlı, reaktif uç |

Eksenin sol ucu "Slower (Preventative)", sağ ucu "Faster (Reactive)" olarak etiketliydi. Hoca proaktif yaklaşımlara bazen preventatif (engelleyici) de dendiğini, çünkü bunların kağıt üzerinde tasarım yapılırken belirlendiğini söyledi.

Soldaki yöntemler daha yavaş, sağdakiler daha hızlı tepki verir. Sağa doğru gidildikçe artık tıkanıklık vardır ve bir an önce çözülmesi gerekir; çözülmezse grafikteki tıkanıklık çöküşü yaşanabilir. Hoca bunu "trafik tıkalı ama en azından akıyor" sözüyle anlattı: amaç ağın tamamen durmamasıdır. Bu yüzden sağa doğru yöntemlerin müdahalesi ve tıkanıklığın çözülme süresi hızlanır.

## 5. Network Provisioning

Ad hoc olmayan, yani düğümlerin o anda birbirleriyle haberleşerek dinamik bir topoloji kurmadığı, topolojinin önceden kağıt üzerinde planlandığı her ağ düzgün planlanmalıdır. Her ağda giriş hatları ve çıkış hatları vardır. Giriş hatlarının toplam kapasitesinin çıkış hatlarınca karşılanabileceğinden mutlaka emin olunmalıdır. Hoca bunu network provisioning, yani ağın planlanması ve konumlandırılması olarak adlandırdı. Bu başlangıçta düzgün yapılmazsa ağın ömrü boyunca farklı senaryolarda ciddi tıkanıklıklarla karşılaşmak işin doğasıdır. Düzgün yapmanın da bir bedeli vardır: maliyeti çok artırır.

### 5.1 Örnek: katman 3 anahtarın uplink kapasitesi

Ağ katmanında anahtarlama yapan, yani yönlendirici gibi çalışan katman 3 anahtarların giriş hatları ve bir üst seviyeye bağlanan çıkış hatları (uplink) vardır.

- Verilen: 48 adet 1 Gbit/s giriş portu; 4 adet 10 Gbit/s uplink (hoca bunun üreticilerde endüstri standardı olduğunu söyledi).
- Giriş toplamı: $48 \times 1 = 48$ Gbit/s.
- Dört uplink'in hepsi etkin olsa bile çıkış toplamı: $4 \times 10 = 40$ Gbit/s.
- Fark: $48 - 40 = 8$ Gbit/s.

Bu durumda anahtarın kalitesi işin içine girer: aradaki 8 Gbit/s'lik farkı tamponlaması gerekir. Ama sonsuz tampon olamayacağı için yalnız belirli süreler tamponlayabilir. Tampon yoksa ve alttaki 48 uygulama aynı anda 1 Gbit/s gönderirse tıkanıklık yaşanır. Uplink'lerin yalnız biri, ikisi ya da üçü kullanılırsa (10, 20, 30 Gbit/s) durum daha da kötüleşir. Kaç uplink kullanılacağını belirleyen çoğunlukla bütçedir. 25, 50, 100 Gbit/s gibi daha hızlı uplink seçenekleri de vardır, ama onların da maliyeti vardır.

Doğru provisioning için alttaki uygulamalardan kaç tanesinin aynı anda, en fazla ne süreyle bu yoğunlukta trafik üreteceği düzgün hesaplanmalıdır.

> **Hocanın vurgusu:** Bir anahtarı seçip bir yere bağlamak, fiberi ya da Ethernet'i takmak herkesin yapabileceği iştir. Network provisioning'i hem maliyeti optimize ederek hem de tıkanıklığı en aza indirecek şekilde yapabilmek mühendisliğin parçasıdır; işin bu tarafı iyi kavranmalıdır.

## 6. Traffic-Aware Routing

Slaytta rotaların yalnız topolojiye göre değil, trafiğe göre de seçilmesi gerektiği yazıyordu: örneğin CF yüklüyse Batı'dan Doğu'ya giden trafik için EI kullanılır; ama salınımlardan (oscillation) kaçınmaya dikkat edilmelidir (ekrandan, 00:30:00). Hoca bunun kitaptaki pek çok büyük topoloji gibi Amerika kıtasının orta bandından esinlenen bir örnek olduğunu, topolojinin Batı ve Doğu yakası olarak ikiye ayrıldığını söyledi.

### 6.1 Topoloji

Karedeki topoloji şöyledir (ekrandan, 00:30:00):

- Batı tarafı düğümleri: A, B, C, D, E
- Doğu tarafı düğümleri: F, G, H, I, J
- Batı içi bağlantılar: A-B, A-D, A-E, B-C, B-D, C-E, D-E
- Doğu içi bağlantılar: F-G, F-H, F-I, G-H, H-J, I-J
- Batı ile Doğu arasındaki iki geçiş: C-F ve E-I

Okun kalınlığı o bağlantıdaki trafiğin yoğunluğunu gösterir: karede C'den F'ye kalın, E'den I'ya ince bir ok vardır.

### 6.2 Salınım

Başlangıçta CF arasında çok yoğun trafik, EI arasında neredeyse hiç trafik yoktur. Yönlendirme algoritması trafiğe göre rota belirleyecek şekilde tasarlandığı için CF'deki trafiğin bir eşik değerine yaklaştığını görür; eşik aşılırsa tıkanıklık başlayacaktır. Bu yüzden trafiği EI'ye almak için bir rota güncellemesi yayımlar. Bu, topolojinin gerisindeki yönlendiricilere (Batı'da A, B, D; Doğu'da G, H, J) güncelleme bilgisinin gitmesi demektir. Bir süre sonra CF daha az, EI daha yoğun kullanılır: kalın ok aşağıya, ince ok yukarıya geçer.

Yönlendirme algoritması bu yeni durumu da gözlemler ve bu kez tersini yapar: trafiğin EI'den değil CF'den akması için hem Batı'da hem Doğu'da güncelleme yayımlar. Bu değişimler seyrekse büyük sorun yoktur. Ama trafik o kadar yüksekse ki EI'ye geçtikten sonraki dakikalar içinde EI dolup yeniden CF'ye geçmek gerekiyor, sonra CF dolup yeniden EI'ye geçiliyorsa, trafik iki bağlantı arasında pinpon topu gibi gidip gelir.

Bunun bedeli büyüktür. Yönlendirme dağıtık yapıldığı için (önceki haftada görülen shortest path first ya da IS-IS; hoca bu örneğin tam bir IS-IS örneği olduğunu söyledi) her değişiklikte güncelleme yayımlanır, yönlendiriciler topolojiyi ve çıkış hatlarını yeniden hesaplar, Dijkstra algoritmasını yeniden çalıştırır ve gecikme bilgilerini çok daha sık değiş tokuş eder. Yönlendiricilerin işlem gücünün büyük kısmı yönlendirme hesabına gider ve performans düşer. Bu duruma salınım (oscillation) denir: osilatörün çıkışındaki sürekli değişen dalga gibi, trafik CF, EI, CF, EI diye gidip gelir.

> **Hocanın vurgusu:** Burada önemli olan salınımın periyodudur. Periyot uzunsa büyük sorun değildir; dakikalar mertebesindeyse ciddi bir sıkıntıdır.

### 6.3 Yönleri ayırma alternatifi ve asimetrik gecikme

Bir alternatif, CF'yi bir yönde, EI'yi diğer yönde kullanmaktır: Batı'dan Doğu'ya CF, Doğu'dan Batı'ya EI. Ancak bu her zaman faydalı değildir. CF ve EI'nin gecikmeleri, hat kapasiteleri ve topolojinin diğer bağlantılarının hızları aynı olmayabilir; bu yüzden paketin gidiş süresiyle dönüş süresi farklı olabilir. Genellikle yol simetrik varsayılır: ölçülen gidiş-dönüş süresi ikiye bölünür ve yarısının gidişte, yarısının dönüşte geçtiği kabul edilir. Oysa sürenin yüzde 60'ı ya da yüzde 70'i gidişte, kalanı dönüşte geçmiş olabilir. Bu, bazı uygulamalarda beklenmedik ek gecikmelere, yol gecikmesinin yanlış hesaplanmasına ve gereksiz tekrar gönderimlerin tetiklenmesine yol açabilir. Bunu uygulama doğrudan yapmaz; ağ katmanının bir üstündeki taşıma katmanı yapar. Bu yüzden süre ölçümünün çok hassas yapılması gerekir, ama bu her zaman mümkün olmayabilir.

## 7. Admission Control

Hoca slayttaki tanımı okudu: yeni bir trafik yüküne yalnız ağda yeterli kapasite varsa izin verilir; örneğin sanal devrelerle (virtual circuits). <!-- BELİRSİZ: admission control slaytı (yaklaşık 00:37:00) kareler arasında yok; tanım ve şekil altyazıdan aktarıldı. -->

Yeterli kapasite olup olmadığını bilmek için bir noktadan diğerine gidilecek yolun önceden bilinmesi gerekir; bu da bağlantı yönelimli (connection-oriented) çalışmak demektir. Bağlantı yönelimli yapıda bu, daha önce anlatılan sanal devre mantığıyla gerçekleştirilir. Ağın da kapasite bilgisini sağlıyor olması gerekir.

Slayttaki örnekte A ve B noktaları vardır; yukarıda ve aşağıda yıldızla işaretlenmiş tıkanık bölgeler bulunur. A ile B arasında kurulacak sanal devre kesinlikle zaten dolmuş ve aşırı yükten sıkıntı yaşayan bu yönlendiricilerden ve onlara bağlı yollardan geçmemelidir. Örnekte ikisinin de devreye girmediği, arada tıkanıklık yaşanmayan ve yeterli kapasitesi olan düzgün bir yol vardır; bu yol boyunca tıkanıklık yaşanmaz.

Datagram mantığında önceden bağlantı kurulmaz, yollar belirlenmez ve her paket farklı bir yoldan gidebilir. Böyle bir yapıda admission control yapmak neredeyse mümkün değildir.

## 8. Traffic Throttling

Slaytta tıkanan yönlendiricilerin hostlara trafiği yavaşlatmaları için sinyal verdiği; ECN'nin (Explicit Congestion Notification) paketleri işaretlediği ve alıcının bu sinyali göndericiye geri döndürdüğü yazıyordu (ekrandan, 00:40:00).

Mantık şudur: bir yönlendiricinin çıkışındaki tıkanıklığı, girişine gelen trafik oluşturur. Bu yüzden tıkanıklığı durdurmak için girişinin gerisinde kalan sistemlere haber vermek gerekir; yani paketlerin gittiği yönün tersinde durdurmak gerekir.

### 8.1 İleri yönde bildirim (ECN)

Karedeki şekilde (ekrandan, 00:40:00) soldaki host sağdaki hosta paket gönderir. Paket önce birinci yönlendiriciden geçer; onun önünde tıkanık bir yönlendirici (congested router) vardır. Bu yönlendiricide biriken paket sayısı artmıştır ve onları yeterince hızlı aktaramamaktadır; aradaki bağlantı da daha yoğun trafiği göstermek için daha koyu çizilmiştir. Paket burada işaretlenir (marked packet) ve işaretli olarak hedefe gider. Hedef, kendisine işaretli paket geldiği için yolda tıkanıklık olduğunu anlar ve göndericiye bir tıkanıklık sinyali (congestion signal) döndürür: "bana daha az ya da daha seyrek paket gönder." Böylece topolojideki paket sayısı kontrollü bir şekilde azaltılır.

Paketleri durdurmanın en iyi yolu kaynağa söylemektir: paketlerin çıktığı yere "daha yavaş gönder" denir. Bunun için uygulamanın kendi tarafında tamponlama yapması gerekir. Aksi halde aradaki her yönlendiricinin tamponlamaya ya da yavaşlatmaya çalışması ve öndeki tıkanıklık gidene kadar arkayı durdurması gerekir; bu daha zordur. Bu mekanizmada bildirim ileri doğru gönderilir ama uygulamaya geri döndürülerek uygulamanın ürettiği trafiği azaltması sağlanır.

### 8.2 Geri yönde bildirim (hop-by-hop)

İkinci seçenek, tıkanık yönlendiricinin dönüş yolundaki bir önceki yönlendiriciye bunu açıkça söylemesidir. Ortadaki tıkanık yönlendirici, uygulamanın göndericiye haber vermesini beklemek yerine, soldaki bir önceki yönlendiriciye gönderdiği paketlerde bir explicit congestion notification bitini set eder. Bunu gören yönlendirici ileride tıkanıklık olduğunu anlar ve ileriye daha az paket gönderir, birim zamanda gidecek paket miktarını düşürür. O yönlendirici de kendinden bir öncekine haber verir ve bu kaynak noktaya kadar gider.

Hoca iki seçeneği şöyle karşılaştırdı:

| | İleri yönde bildirim | Geri yönde bildirim |
|---|---|---|
| Bildirimin yönü | Paketlerle ileri, hedefe; hedeften kaynağa geri | Geri yöndeki paketlerle bir önceki yönlendiriciye |
| Kapsam | Uçtan uca (end-to-end) | Atlama atlama (hop-by-hop) |
| Yavaşlatma yapılan yer | Kaynak uygulama | Yol üzerindeki her yönlendirici, kaynağa kadar |
| Hocanın kullandığı ad | Forward congestion notification | Backward congestion notification |

### 8.3 Bildirim bitle ve piggybacking ile taşınır

Hoca "bir bit set ediyoruz" sözünün üzerine basarak durdu: paketin içinde bu iş için ayrılmış bir alan kullanılır. Durumu bildirmek için ayrı paket gönderilirse, zaten paketlerden dolayı tıkanmış bir ağ daha da tıkanır. Bu yüzden paket başlığında bu iş için ayrılmış alanlar vardır (IP protokolü incelenirken bunlara özellikle bakılacağı söylendi); bu alanlardaki özel bitler yukarıdaki senaryolarda bire set edilerek tıkanıklık bildirilir.

Buna piggybacking denir. Kavram veri iletişimi dersinden, bağlantı katmanından bilinir: örneğin onay (acknowledgment) bilgisi karşı tarafa giden bir çerçevenin içindeki bir alanla taşınabilir. "Piggyback" birinin sırtına binip onunla ilerlemek demektir: zaten o yöne giden bir paket vardır ve bit onun içinde set edilir; ek trafik üretilmez.

> **Hocanın vurgusu:** Tıkanıklık bilgisi için ayrı paket gönderilmez; ayrılmış başlık biti set edilerek mevcut paketle taşınır.

## 9. Load Shedding

Şimdiye kadarki yöntemlerin hepsi yetersiz kalabilir: provisioning eksik yapılmış olabilir, traffic-aware routing her topolojide uygulanmaz, admission control her yerde uygulanamaz, explicit congestion notification ve traffic throttling etkisiz kalabilir. O zaman yapılan şey load shedding'dir: fazla yükten kurtulmak, yani paketleri düşürmek (drop), gelen paketleri gelmemiş kabul etmek.

Hoca traffic throttling ile load shedding'in birbirine benzediğini söyledi: throttling azaltma ve tamponlama üzerine kuruludur; azaltılamıyorsa ya da tamponlar yetmiyorsa load shedding uygulanır ve paketler işlenmeden devre dışı bırakılır. Boğulan yönlendiricinin bir öncekine gönderdiği bu acil durum bilgisine choke paketi denir ("choke" boğulmak demektir: "ben boğuluyorum").

Slaytta ağın, her şey başarısız olunca paket düşüreceği; bunun uçtan uca ya da bağlantı bağlantı (link-by-link) yapılabileceği ve link-by-link yöntemin hızlı rahatlama sağladığı yazıyordu (ekrandan, 00:50:00).

### 9.1 Link-by-link örneği

Şekildeki topolojide altı düğüm vardır: A, B, C, D, E, F. Bağlantılar A-B, A-E, B-C, B-F, C-E, C-D, D-F ve E-F'dir (ekrandan, 00:50:00). Ağır akış (heavy flow) A'dan E'ye, E'den F'ye, F'den D'ye gider; E-F bağlantısı kalın çizilmiştir. Bu trafiğin fazlalığı en çok F-D tarafını etkiler. Adımlar şöyledir:

1. A-E-F-D yolunda ağır akış vardır.
2. D bu trafik altında boğulur ve F'ye choke bildirimi gönderir.
3. F paket düşürmeye başlar ve choke bilgisini E'ye giden paketlerde de iletir; D'ye giden akış azalır (reduced flow).
4. E de paket düşürmeye başlar ve choke bilgisini A'ya iletir.
5. A da düşürür; yol boyunca A, E ve F paket düşürdüğü için akış her bağlantıda azalmıştır.

Rahatlama hızlıdır, çünkü bildirimin göndericiye kadar gitmesi beklenmez; sorun her bağlantının iki ucundaki iki yönlendirici arasında çözülür. Bedeli ise paketlerin kaybolması, işlenmemesi ve sonra yeniden gönderilecek olmasıdır.

### 9.2 Uçtan uca örneği

Slaytta uçtan uca yöntemin etkisinin daha geç geldiği, ama tıkanıklığın nedenini daha iyi hedefleyebildiği yazıyordu (ekrandan, 00:55:00). Adımlar:

1. A-E-F-D yolunda ağır akış vardır.
2. D, F'ye choke bildirimi gönderir.
3. F henüz bir şey yapmaz, bildirimi E'ye iletir.
4. E de henüz bir şey yapmaz, bildirimi A'ya iletir.
5. A gönderme hızını azaltır (reduced flow).
6. A'nın azalttığı akış henüz yolun sonuna ulaşmamıştır; D tarafında akış hala en yüksek hızdadır (flow is still at maximum rate).
7. Sonunda akış yolun tamamında azalır (flow is reduced).

Hoca bu süre içinde E ve F'nin de paket düşürdüğünü, A'nın da çıkış hızını azalttığını; ikisinin bir arada uzun vadede daha etkili ve düzgün bir tıkanıklık kontrolü sağladığını söyledi. <!-- BELİRSİZ: hocanın uçtan uca örnekte E ve F'nin de paket düşürdüğünü söylemesi, slayttaki "F ve E henüz bir şey yapmaz" adımlarıyla tam örtüşmüyor; anlatımdaki karışık kısım aynen aktarıldı. -->

> **Hocanın vurgusu:** Tıkanıklığın temel nedeni bir uygulamanın öngörülenden daha fazla trafik üretmesidir. Örnekte A'daki uygulama normalden fazla trafik üretiyor ve diğer trafiklerle birleşince D'nin boğulmasına neden oluyor. Paket düşürerek sağlanan rahatlamanın kalıcı olması için A'ya "yavaşla" denebilmelidir.

### 9.3 Hangi paketler düşürülmeli: süt ve şarap

Paket düşürülecekse, ve özellikle tamponda bekleyen paketler düşürülecekse (çünkü load shedding'in öncesinde traffic throttling'deki tamponlama vardır), şu soru düzgün cevaplanmalıdır: yeni gelen paketler mi, eski paketler mi düşürülecek?

Teknik terim olarak süt (milk) ve şarap (wine) kullanılır; sütün tazesi, şarabın eskisi makbuldür.

- **Süt yaklaşımı:** En son gelen paketler kaybolmamalıdır; öncekiler kaybolsa da sorun çıkmaz. Video izlerken aradaki bozukluklara rağmen son sahneden devam edilebilir. Hoca bunu analog yayınlarla örnekledi: analog televizyonda ya da uydu yayınında parazit olduğunda o sahne bozulur ama sonra düzelir ve yayın devam eder. Aşırı yağışta uydu hatları da kullanılan frekans nedeniyle havadaki nem arttığında bozulur, görüntüde kopukluk olur ama yayın sürer.
- **Şarap yaklaşımı:** Eski, ilk gelen paketler kaybolmamalıdır; yeni gelenler kaybolsa da olur. Dosya aktarımında (örneğin tarayıcıdan indirme) dosyanın sunucudaki hali istemciye aynen aktarılmalıdır. Son paketi kurtarıp eskileri atmak durumu daha da kötüleştirir, çünkü eksik paketler yeniden istenecektir; sıra bozulamaz, karşı taraftaki yapı ve sıra aynen korunmalıdır.

> **Ek bilgi (derste anlatılmadı):** Load shedding'de düşürme kararı genellikle uygulamanın paketlere öncelik işaretlemesiyle de desteklenir; böylece yönlendirici önce az önemli paketleri atabilir. Tıkanıklık iyice yerleşmeden önce paketleri erken ve rastgele düşürmeye dayanan RED (Random Early Detection) gibi yöntemler de büyük olasılıkla bu bölümün devamında ders kitabında yer alır.

## 10. Hizmet Kalitesine Geçiş

Hoca dersi şöyle toparladı: önleyici (proaktif) ve reaktif yaklaşımlar ve aralarındaki ilişkiler gözden geçirildi. Çoğu zaman bunlardan biri değil, birkaçı bir arada uygulanır. Önleyici yöntemler daha yavaş, reaktif yöntemler daha hızlı davranır. Ağ çok kontrollü ve disiplinli kullanıldığında kapasitenin önemli bir kısmı kullanılamaz; bundan vazgeçildiğinde de anlık kullanımlar tepe yaptığında tıkanıklık oluşur. Arada ince bir denge vardır.

Admission control sanal devre yapılarında çok rahat çalışır, ama datagram yapısına kesinlikle uygun değildir. Traffic throttling hem sanal devrede hem datagram ağda yapılabilir; ancak sanal devrede gerekmemelidir, çünkü daha önce admission control'den geçilmiş ve trafik belirlenmiştir: uygulama söz verdiğinden fazla trafik aktarmamalıdır. Datagram ağlarda ise traffic throttling hem ileri hem geri yönde rahatça uygulanabilir; önemli olan yönlendiricinin paketleri işaretleyip diğer yönlendiricileri ya da uçtaki uygulamayı haberdar etmesidir.

Hoca ağ katmanında birden fazla atlamadan söz edildiğini (en az 2-3 atlama), bu yüzden tıkanıklığın uzun vadede düzgün yönetilebilmesi için paketlerin çıkış noktasındaki hızının kontrol edilmesi gerektiğini söyledi. Link-by-link (hop-by-hop) çözümler uygulanabilir, ama uçtan uca çözümler daha etkilidir.

Sonraki konu hizmet kalitesidir (Quality of Service). Slayttaki başlıklar (ekrandan, 01:00:00):

- Application requirements
- Traffic shaping
- Packet scheduling
- Admission control
- Integrated services
- Differentiated services

Hoca buradaki başlıkların (traffic shaping, packet scheduling, admission control) tıkanıklık kontrolünde görülen konulara benzediğine dikkat çekti: tıkanıklık kontrol edilebildiğinde, onun bir üst ve daha rafine seviyesiyle paket aktarım kalitesi belirlenebilir, gecikme süreleri ve bant genişlikleri kontrol edilebilir.

## Örnek Sorular

**Soru 1** (derste sözlü, 01:03:47): Traffic throttling ve load shedding reaktif yöntemler mi? Admission control nerede durur?

> **Cevap (derste verildi):** Evet, traffic throttling ve load shedding reaktiftir; tıkanıklık olmadan zaten uygulanamazlar. Admission control tam ortadadır; yöntemler bir skala gibidir, sola gidildikçe önleyici (proaktif), sağa gidildikçe reaktif olur. Admission control normalde yapılmayıp tıkanıklığın başladığı ve ilerlediği fark edildiğinde devreye alınırsa reaktiftir. Tıkanıklık olsun olmasın bütün uygulamalara baştan uygulanırsa önleyici (proaktif) olur. Yani iki türlü de kullanılabilir.

**Soru 2** (derste sözlü, 01:01:05): Sanal devre (virtual circuit) ağında traffic throttling yapmaya neden gerek olmamalıdır?

> **Cevap (derste verildi):** Sanal devrede trafik başlamadan önce admission control'den geçilmiş ve trafik miktarı belirlenmiştir. Uygulama söz verdiğinden fazla trafik aktarmamalıdır ve ağ buna göre planlanmıştır. Traffic throttling ise datagram ağlarda hem ileri hem geri yönde rahatça uygulanabilir.

## Dersin Toparlaması

Bu derste ağ katmanının tıkanıklıkla nasıl başa çıktığı incelendi. Tıkanıklık, sunulan yükün kapasiteyi aşmasıyla kayıp, gecikme ve tekrar gönderimlerin artması, en kötü durumda da goodput'un çöktüğü bir durumdur. Kontrolün amacı goodput'un kapasiteye asimptotik yaklaştığı "istenen tepkiyi" elde etmek ve tıkanıklık başlangıcı bölgesinde müdahale etmektir. Yöntemler, en yavaş ve önleyici olan network provisioning'den en hızlı ve reaktif olan load shedding'e uzanan bir eksen üzerinde sıralandı: trafiğe göre rota seçimi ve salınım riski, sanal devre gerektiren kabul kontrolü, ECN ile ileri ve geri yönlü tıkanıklık bildirimi, choke paketleriyle link-by-link ve uçtan uca yük atma ile hangi paketin düşürüleceğine dair süt ve şarap yaklaşımları.

Bir sonraki konu hizmet kalitesidir (QoS). Traffic shaping, packet scheduling ve admission control gibi başlıklar, burada görülen tıkanıklık kontrolü fikirlerinin gecikme ve bant genişliği garantisi vermeye yönelik daha rafine bir devamıdır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
