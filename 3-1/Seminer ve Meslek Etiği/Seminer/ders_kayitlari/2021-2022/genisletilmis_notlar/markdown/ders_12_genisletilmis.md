# Ders 12 Genişletilmiş Notu: Öğrenci Sunumları: Docker, Stokastik Hesaplama, Yapay Zeka, İnternet Mahir, Formula 1 Lastikleri ve Vücut Geliştirme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin İşleyişi
- 2. Sunum: Docker ve Konteyner Teknolojisi
- 3. Sunum: Stokastik Hesaplamaya Genel Bakış
- 4. Sunum: Yapay Zekaya Giriş
- 5. Sunum: İnternet Mahir
- 6. Sunum: Formula 1 Araçlarında Lastikler
- 7. Sunum: Vücut Geliştirme
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin İşleyişi

Bu ders, öğrenci sunumlarının yapıldığı haftalardan biridir ve çevrimiçi (Zoom) yapıldı. Altı öğrenci sırayla kendi seçtikleri konularda yaklaşık beşer dakikalık sunum yaptı; sunumlarını kendi ekranlarını paylaşarak yürüttüler. Sunumlardan biri İngilizce yapıldı. Her sunumdan sonra hoca önce dinleyicilere soru için söz verdi; soru gelmediğinde kendisi konuyu genişleten sorular sordu ve kısa yorumlar yaptı.

Sunum tekniğiyle ilgili bir ayrıntı da derste geçti: ekran paylaşımında PowerPoint'in tasarım görünümü yerine sunum modunun görünmesi için paylaşım tek pencere yerine tüm ekran olarak açılmalıdır. Bağlantı zayıfsa sunucu konuşurken ekran paylaşımını kapatmak bant genişliğini daha verimli kullanmayı sağlar.

## 2. Sunum: Docker ve Konteyner Teknolojisi

### 2.1 Docker nedir?

Docker bir konteyner teknolojisidir. Aynı işletim sistemi üzerinde yüzlerce, hatta binlerce birbirinden izole ve bağımsız konteyner çalıştırılabilir. Docker iki temel kavramdan oluşur: **imaj** (image) ve **konteyner**. İmaj; Python, MySQL, Linux gibi bir temel üzerine kurulmuş şablondur, konteyner ise bu imajdan çalıştırılan örnektir. İmajlardan üretilen konteynerler aynı işletim sistemi üzerinde birbirinden bağımsız çalışır.

Sunumda verilen günlük örnek şudur: bir ödev ya da proje geliştirirken birçok kütüphane ve framework kurulmuş olabilir ve bunlar projeyi çalıştıracak kişinin bilgisayarında bulunmayabilir. Proje için bir Dockerfile hazırlanırsa, kaynak dosyalarla birlikte yalnız bu dosyayı göndermek yeterli olur; karşı taraf onu derleyip (build) çalıştırabilir. Bu yüzden Docker ile hazırlanan projelere ulaşmak ve onları dağıtmak kolaydır.

### 2.2 Dockerfile

Dockerfile, aslında verilen bir dizi komuttur. Bu komutlarla imajın hangi temel imaj üzerinden oluşturulacağı ve konteynerin çalışma şekli belirlenir. İçine ne kurulacağı, nasıl çalıştırılacağı gibi her şey bu dosyadan yönetilebildiği için Docker kolay yönetilen bir yapıdır.

### 2.3 Neden konteyner?

Sunum, konteynerlerin avantajlarını şöyle sıraladı:

- **İzolasyon:** birbirine bağlı birçok mikroservisten oluşan bir projede bir servisteki hata, diğerlerinde de runtime hatasına yol açabilir. Servisler ayrı konteynerlere bölünüp izole çalıştırılırsa biri çökse, dursa ya da virüs bulaşsa bile diğerleri etkilenmez.
- **Kendini yeniden başlatma:** Docker çöken bir konteyneri kendi kendine yeniden başlatabilir.
- **Hız:** imajın oluşturulmasından konteynerin başlamasına kadar süreç çok hızlıdır; konteyner saniyeler içinde açılır ve kapanır.
- **Temizlik:** çok dosyaya ihtiyaç duyan bir şey tek bir konteyner içinde kurulup kullanılabilir; ihtiyaç kalmayınca yalnız konteyneri silmek yeterlidir.
- **Platform:** Docker Linux çekirdeği üzerinde çalışan bir teknolojidir, ama Windows üzerinde de kullanılabilir.

### 2.4 Sanal makine ile Docker karşılaştırması

Yansıda iki yaklaşım hem tabloyla hem katman şemasıyla karşılaştırıldı (ekrandan, 00:05:00):

| Özellik | VM (Virtual Machine) | Docker |
|---|---|---|
| OS | Tam işletim sistemi | Küçültülmüş işletim sistemi imajı |
| İzolasyon | Yüksek | Daha düşük |
| Çalışır hale gelmesi | Dakikalar | Saniyeler |
| Versiyonlama | Yok | Yüksek |
| Kolay paylaşılabilirlik | Düşük | Yüksek |

Katman şeması aşağıdan yukarıya şöyledir (ekrandan, 00:05:00):

```text
Virtual Machines                     Containers
App 1    | App 2    | App 3          App 1    | App 2    | App 3
Bins/Lib | Bins/Lib | Bins/Lib       Bins/Lib | Bins/Lib | Bins/Lib
Guest OS | Guest OS | Guest OS       Container Engine
Hypervisor                           Operating System
Infrastructure                       Infrastructure
```

Sanal makine tam bir işletim sistemi kullanır; bir sanal makinenin açılması, normal bir bilgisayarın açılması gibi dakikalar sürer. Docker ise Python, MySQL ya da Alpine gibi küçültülmüş bir işletim sistemi imajını kullanır ve saniyeler içinde çalışır hale gelir. Tek bir sistem için bu fark küçük görünse de bin tane konteynerden söz edildiğinde önemli bir ayrıntı olur. Paylaşım da kolaydır: Docker yüklü herhangi bir bilgisayara kaynak dosyalar ve Dockerfile götürülüp build edilmesi yeterlidir.

### 2.5 Soru-cevap

**Soru:** Bir yazılım projesi bir Docker imajı üzerinde gerçekleştirildiyse, başka bir bilgisayarda çalışabilmesi için o bilgisayarda ne olması gerekir?

**Cevap:** Konteyner kendi içindeki Linux üzerinde çalıştığı için proje işletim sisteminden bağımsızdır, ama bilgisayarda Docker'ın kurulu olması gerekir. Projeyi aktarırken hem kaynak dosyalar hem de hazır bir Dockerfile bulunmalıdır. Taşıdıktan sonra Dockerfile'dan imaj build edilir, ondan konteyner oluşturulup çalıştırılır. Her konteyner sunucuda kendi içinde kapalı biçimde çalıştığından, koda bir sözdizimi ya da runtime hatası girse bile konteyner kendini yeniden başlatır ya da diğerlerini etkilemez.

**Soru:** Docker üzerinde önce bir işletim sistemi, üstüne çeşitli yazılımlar eklenerek full stack bir sistem kurulabiliyor. Bu sistemin belli bir depolama alanı ya da bellek kapasitesi gibi çalışma zamanı gereksinimleri olabilir. Bunları garanti etmenin, hatta çalışma sırasında artırıp azaltmanın bir yolu var mıdır?

**Cevap:** Sunan öğrenci, kendi kullandığı projelerde gereksinimlerin düşük olduğunu, en fazla TensorFlow üzerine kurulmuş bir görüntü işleme konteyneri kullandığını, bellek, GPU ya da CPU kullanımını değiştiren bir ayarı daha önce kullanmadığını ama mutlaka ayarlanabildiğini düşündüğünü söyledi. Konteynerin kapasitesini kendisinin mi ayarladığı yoksa kullanıcının mı verdiği sorusunu araştırmaya değer buldu.

> **Ek bilgi (derste anlatılmadı):** Docker'da konteynerin kullanabileceği bellek ve işlemci, başlatılırken `docker run --memory=512m --cpus=1.5 ...` gibi seçeneklerle sınırlanabilir; `docker update` ile bu sınırlar konteyner çalışırken değiştirilebilir. Sınır verilmezse konteyner ana makinenin kaynaklarını paylaşır. Kalıcı depolama için konteynerin dışında tutulan volume'ler kullanılır.

**Soru:** Konteynerler ve mikroservisler genellikle el ele gider. Birbirlerini tamamlayan yönleri ve birlikte kullanılmalarının avantajları nelerdir?

**Cevap:** Sunan öğrenci bir mesajlaşma uygulaması örneği verdi (örneğin büyük bir sosyal ağdaki mesajlaşma bölümü). Arka planda mesaj gönderme, mesaj alma, bildirim gönderme gibi ayrı servisler çalışır.

- Hepsi tek parça halinde çalıştırılırsa mesaj alma kodundaki bir hata bütün kodu çökertir ve bildirim de gelmez.
- Servisler ayrı ayrı, örneğin farklı terminallerde çalıştırılırsa biri çöktüğünde diğerleri çalışmaya devam eder; ama bilgisayara bir şey olursa yine hepsi durur.
- Her servis ayrı bir konteynerde çalıştırılırsa (sunucuda ya da kendi bilgisayarında fark etmez) birinde hata olduğunda o konteyner yeniden başlatma yöntemiyle kendini ayağa kaldırır; servisler birbirinden izole olduğu için birine virüs bulaşması ya da birinin çökmesi diğerlerini etkilemez.

> **Ek bilgi (derste anlatılmadı):** Çöken konteynerin otomatik yeniden başlatılması `--restart` politikasıyla (ör. `--restart=always` ya da `--restart=on-failure`) ayarlanır. Birden çok konteynerden oluşan bir uygulamayı tek dosyayla tanımlayıp birlikte başlatmak için Docker Compose, çok sayıda makinede konteynerleri ölçeklemek ve yönetmek için Kubernetes gibi orkestrasyon araçları kullanılır.

### 2.6 Hocanın yorumu: mikroservis mimarisi

> **Hocanın vurgusu:** Hoca bu konunun üzerinde öğrencilerin bilmesi gerektiği için özellikle durduğunu söyledi. Konteynerler ve mikroservisler üzerinden dinamik hizmet sunmak, şu anda en hızlı ivme kazanan mimari yaklaşımlardan biridir; öğrencilerin bu konuda küçük uygulamalı (hands-on) çalışmalar yapmaya başlamasını önerdi.

Hocanın özetine göre konteynerler, yazılımları (özellikle açık kaynak yazılımları) hızla bir araya getirip kullanıma almada günümüzde en yüksek çevikliği ve esnekliği sunar. **Mikroservis** yaklaşımı, bir uygulamanın mümkün olduğunca hafif servislere bölünmesi ve uygulamanın bu servisler üzerinden sunulmasıdır. Bunun zıddı olan **monolitik** yaklaşımda bütün servisler tek bir bütün uygulamanın içindedir. Monolitik model daha eski bir yaklaşımdır ve önemli dezavantajları vardır; günümüzün esneklik ve çeviklik ihtiyaçlarına yetişemez. Bu yüzden konteynerler üzerinde çalışan mikroservislerle yazılım geliştirmeyi öğrenmeye yatırım yapılmasını tavsiye etti.

## 3. Sunum: Stokastik Hesaplamaya Genel Bakış

Bu sunum İngilizce yapıldı ve stokastik hesaplamaya (stochastic computing) basit bir genel bakış sundu. Altyazının bu bölümü büyük ölçüde bozuk olduğu için anlatım ekrandaki yansıdan ve okunabilen İngilizce cümlelerden kuruldu. <!-- BELİRSİZ: yaklaşık 00:13:00-00:17:00 arası altyazı tekrarlı ve anlamsız; sunumun tanım, tarihçe ve uygulama kısımlarının ayrıntısı okunamadı -->

### 3.1 Temel fikir ve kullanım nedeni

Stokastik hesaplamada sayılar rastgele bit akışlarıyla (bit stream) gösterilir; bir akışın temsil ettiği değer, içindeki 1'lerin oranıdır. Hesaplama olasılığa dayandığı için yöntem "stokastik" adını alır.

Yöntemin kullanılmasının başlıca nedeni küçük donanım ayak izidir (smaller hardware footprint). Yansıdaki açıklama şöyledir (ekrandan, 00:15:00): geleneksel taban (radix) hesaplamanın aksine aritmetik birimlerin donanımı çok basittir. Örneğin çarpma bit bit AND işlemiyle, toplama bit bit OR işlemiyle yapılabilir; yani akış ne kadar uzun olursa olsun tek bir mantık kapısı yeterlidir. Sunan öğrenci, geleneksel hesaplamada aritmetik birimlerin, özellikle çarpma ve bölmenin, donanım tarafında çok karmaşık olduğunu vurguladı.

### 3.2 AND ile çarpma örneği

Yansıdaki örnek (ekrandan, 00:15:00):

```text
0.50   0 1 0 1 0 1 0 1
       &&
0.50   1 0 0 1 0 0 1 1
-----------------------
0.25   0 0 0 1 0 0 0 1
```

Adım adım (ara adım eklendi): birinci akışta 8 bitin 4'ü 1'dir, değeri $4/8 = 0.50$. İkinci akışta da 4 bit 1'dir, değeri $0.50$. Bit bit AND alındığında yalnız iki akışın da 1 olduğu 4. ve 8. konumlar 1 kalır; sonuç akışında 2 tane 1 vardır, değeri $2/8 = 0.25 = 0.50 \times 0.50$. Sunan öğrenci, bu örnekteki iki akışın tamamen korelasyonsuz (perfectly uncorrelated) olduğunu belirtti; çarpmanın doğru çıkması buna bağlıdır.

> **Ders sonrası not:** Yansıda toplamanın OR kapısıyla yapıldığı yazıyor. Korelasyonsuz akışlarda OR çıkışının 1 olma olasılığı $p_1 + p_2 - p_1 p_2$'dir; aynı örnekte OR sonucu `11010111` = $6/8 = 0.75$ çıkar, $0.5 + 0.5 = 1$ değil. OR yalnız küçük değerler için yaklaşık toplama verir; stokastik hesaplamada toplama genellikle bir çoklayıcıyla (MUX) ölçeklenmiş toplama, yani $(p_1 + p_2)/2$ biçiminde yapılır (büyük olasılıkla).

### 3.3 Dezavantajlar ve uygulama alanları

Aritmetik işlemler yüzde yüz doğru değildir, çünkü bit akışları arasındaki korelasyondan etkilenebilir. Örneğin iki akış pozitif korelasyonluysa, çarpıcı gibi davranması beklenen AND kapısı minimum fonksiyonu gibi davranır.

> **Ek bilgi (derste anlatılmadı):** Pozitif korelasyonun en uç durumunda iki akışın 1'leri hep aynı konumlardan başlar; bu durumda AND çıkışındaki 1 sayısı, iki akıştaki 1 sayısının küçüğü olur. Örneğin `11110000` ($0.5$) ile `11000000` ($0.25$) AND'lenince `11000000` ($0.25 = \min(0.5, 0.25)$) çıkar, çarpım olan $0.125$ değil. Bu yüzden stokastik devrelerde bağımsız rastgele sayı üreteçleri kullanmak önemlidir.

Sunumda yöntemin görüntü işlemede (özellikle kenar bulmada) ve enerji verimli sistemlerde kullanıldığı anıldı. <!-- BELİRSİZ: uygulama örneklerinin ayrıntısı altyazıda bozuk -->

### 3.4 Soru-cevap

**Soru:** Bu yaklaşım olasılık hesabına dayandığı için bir ölçüde rastgele midir?

**Cevap:** Evet; yöntemin "stokastik" diye anılmasının nedeni de budur.

**Soru:** Stokastik hesaplamanın olasılıksal doğası ile kuantum hesaplama arasında bir ilişki kurulabilir mi? <!-- BELİRSİZ: sorunun tam metni altyazıda bozuk; hocanın kuantum hesaplamayla bağlantıyı sorduğu anlaşılıyor -->

**Cevap:** Sunan öğrenci bunu araştıracağını söyledi. Hoca, kuantum hesaplamada da bir elektronun ya da parçacığın tam olarak nerede olduğunun bilinmediğini, bir olasılık dağılımıyla çalışıldığını; iki alanın da olasılıksal bir doğası olduğu için aralarında iyi uyumlar bulunabileceğini, bunun yalnız kendi aklına gelen bir düşünce olduğunu belirtti.

## 4. Sunum: Yapay Zekaya Giriş

Sunan öğrenci, yapay zekanın çok derin bir konu olduğunu belirterek üç temel başlıkla bir giriş yapmayı seçti: yapay zeka nedir, geçmişten bugüne yapay zeka ve uygulama alanları.

### 4.1 Tanım

Yapay zeka, görevleri yerine getirmek için insan zekasını taklit eden ve topladığı bilgilere göre kendini geliştirebilen sistemlerdir. Makinelerin deneyimden öğrenmesini, yeni girdilere uyum sağlamasını ve insana özgü zihinsel işlevleri gerektiren görevleri yapmasını mümkün kılar. Bunu derin öğrenme ve doğal dil işleme gibi teknolojilerle sağlar.

### 4.2 Tarihçe

Sunumdaki tarihçe şu sırayla anlatıldı:

- Yapay zeka, Alan Turing'in ortaya attığı "makineler düşünebilir mi?" sorusuyla başlar.
- İkinci Dünya Savaşı sırasında (sunumda 1943 anıldı) üretilen bazı makineler, bilgisayar bilimi, yapay zeka ve makine zekası kavramlarının oluşmasına öncülük etti.
- İdealize edilmiş tanımıyla yapay zeka konusundaki ilk çalışmalardan birini McCulloch ve Pitts yaptı; bu araştırmada yapay sinir hücrelerini kullanan bir hesaplama modeli üretildi ve ağ yapıları uygun tanımlanırsa öğrenme becerisi kazanabileceği ileri sürüldü.
- Bir nöropsikolog (Hebb), sinir hücreleri arasındaki bağlantıların şiddetinin değişmesiyle yapay sinir ağlarının öğrenebileceğini öne süren bir kural ortaya attı.
- İlk yapay sinir ağı tabanlı bilgisayar SNARC 1951'de üretildi.
- 1956'da iki aylık bir çalışma toplantısı düzenlendi; birçok önemli ilerleme kaydedildi ve "yapay zeka" adı bu çalışmada kondu. İlk kuram ispatlayan programlardan biri burada Newell ve Simon tarafından tanıtıldı.
- Aynı bilim insanları insan gibi düşünme yaklaşımına göre ilk programı, Genel Sorun Çözücü'yü (General Problem Solver) geliştirdi; fiziksel simge sistemi varsayımının ortaya atılmasıyla insandan bağımsız zeki sistemler yapma çalışmaları hızlandı.

Sunuma göre yapay zekanın tarihi üç ana döneme ayrılabilir: nöral ağlar, makine öğrenmesi ve derin öğrenme.

> **Ek bilgi (derste anlatılmadı):** Altyazıda bozuk geçen adlar büyük olasılıkla şunlardır: McCulloch ve Pitts (1943, yapay nöron modeli), Donald Hebb (1949, Hebb öğrenme kuralı), Marvin Minsky'nin SNARC'ı (1951), Dartmouth Konferansı (1956), Allen Newell ve Herbert Simon'ın Logic Theorist ve General Problem Solver programları.

### 4.3 Uygulama alanları

Yansıda yedi uygulama alanı listelendi (ekrandan, 00:25:00): ses tanıma, görüntü işleme, doğal dil (lisan) işleme, muhakeme, öneri sistemleri, regresyon analizi ve dil çevirileri.

- **Ses tanıma:** ses mikrofonla dijital hale getirilir ve frekanslara ayrılır; bu frekanslardan harf ya da kelimeler çıkarılmaya çalışılır ve sayılara dönüştürülür. Böylece sistem sesi tanıyabilir, anlayabilir ve cevap verebilir. Örnekler: Siri, Echo, Cortana.
- **Görüntü işleme:** görüntüler sayısal verilere dönüştürülüp yapay zeka algoritmalarıyla yorumlanır; örnek olarak sürücüsüz araçlar verildi. <!-- BELİRSİZ: bu maddenin başı altyazıda eksik -->
- **Doğal dil işleme:** insan-bilgisayar etkileşimini geliştirmek ya da farklı dilleri konuşan insanlar arasındaki iletişimi kolaylaştırmak için çözümler üretir. Makine öğrenmesi, istatistiksel analiz ve kural tabanlı yaklaşımlar kullanılır. Yazım hatası düzeltme, otomatik çeviri, dil öğrenme uygulamaları ve kişisel asistanlar bu sayede çalışır.
- **Muhakeme:** mevcut verileri kullanan algoritmalarla yapay zeka kendi başına yargıya varabilir ve insan kadar olmasa da belirli bir seviyede rasyonel karar verebilir.
- **Öneri sistemleri:** kullanıcıların geçmiş davranışlarından çıkarım yapılarak yeni içerik önerilir; sosyal medyada arkadaş önerileri, mağazalarda ürün önerileri, haber sitelerinde haber önerileri örnektir.
- **Regresyon analizi:** geçmiş verilere dayanarak bir değişkenin gelecekteki değeri tahmin edilir; ekonomik öngörüler ve üretim miktarı tahminleri örnektir.
- **Dil çevirileri:** iki farklı dildeki cümle ve kelimelerin birbirine çevrilmesinde yapay zeka kullanılır.

Yansıdaki kaynakça genel tanıtım sayfalarından oluşuyordu (Türkçe Vikipedi, büyük yazılım şirketlerinin "yapay zeka nedir" sayfaları) (ekrandan, 00:30:00).

### 4.4 Soru-cevap

**Soru:** Yapay zeka genelde belirli bir alanda uzmanlaşmış uygulamalarla anılıyor. Örneğin satrançta insan ustayı yenen bilgisayarlar yapıldı, ama bu problem yapay zeka tekniklerinden çok algoritmik yaklaşımla da çözülebilir. Bir problemi çözen yapay zekanın kapasitesi, performansı ve başarımı, aynı problemi çözebilen bir insanla ne düzeyde karşılaştırılabilir?

**Cevap:** Sunan öğrenci, yapay zekanın verilen girdilerle sürekli kendini geliştirebilen bir sistem olduğunu hatırlattı. İnsanın kendini geliştirmesinin belli bir noktada sınırlandığını, yapay zekanın ise farklı öğrenme yöntemleri sayesinde çok ucu açık göründüğünü söyledi. Gelişimi daha sistematik ve teknolojik ilerlediği için bazı noktalarda yapay zekanın insandan bir adım öne geçebileceğini düşündüğünü belirtti. Hoca, yapay zekanın bilim kurgu kitaplarında ve filmlerinde de çok işlenen bir konu olduğunu ekledi.

## 5. Sunum: İnternet Mahir

### 5.1 İlk internet fenomeni

Sunum, "İnternet Mahir" olarak bilinen Mahir Çağrı'yı tanıttı. Anadolu'nun birçok yerinde öğretmenlik yapmış biri olan Mahir Çağrı, interneti sohbet programları aracılığıyla keşfediyor ve herkesin kişisel bir web sayfası olduğunu görünce internetten tanıştığı kişilerin yardımıyla kendi sitesini kuruyor. Site çok ilkel ve az içeriklidir: "Welcome to my page" başlığı, kendini ve hobilerini tanıtan birkaç satır, birkaç fotoğraf ve ünlü "I kiss you" ifadesi.

Site çok kısa sürede büyük ilgi görüyor: sunuma göre ilk gün 50 bin kez tıklanıyor ve dünyanın birçok ülkesinden telefonlar gelmeye başlıyor. Kısa sürede dünya basınında yer alıyor; sunuma göre Forbes'a dayanarak yaklaşık 800 milyon kişi tarafından tanınıyor, İngiltere'de internet ödülleri alıyor ve Guinness Rekorlar Kitabı'na giriyor. Sunan öğrenci, internetin henüz yeni geliştiği, haberin bugünkü kadar hızlı yayılmadığı bir dönemde bir kişinin bu kadar ünlü olmasının çok olağan dışı olduğunu ve bu nedenle onun ilk internet fenomeni sayılabileceğini vurguladı.

### 5.2 Ticari etki ve sonrası

Yansıya göre dünyanın birçok yerinde bir "Mahir sektörü" oluşuyor; adına tişört, mousepad ve kahve bardakları üretilmeye başlanıyor (ekrandan, 00:35:00). Ancak bir ekibi ya da menajeri olmadığı için bu gelirden pay alamıyor; banner reklamı ve film tekliflerini kabul etmiyor. Sunuma göre süreci iyi yönetemediği için 5-6 yıl sonra unutuluyor. Sunumun sonunda, bir filmdeki karakterin onun tavır ve kıyafetlerine çok benzediği ve bu yüzden dava açtığı da anlatıldı.

### 5.3 Hocanın yorumu

Hoca, bu olayın internetin önemini ve gücünü erken dönemde gösterdiğini, ancak o dönemde yeterince kavranmadığını belirtti. Olay, bir kişinin internet üzerinden nasıl bu kadar ünlü olduğu ve insanlar üzerindeki etkisi bakımından birçok makale ve çalışmaya konu oldu; hocaya göre sonraki sosyal medya uygulamalarının ortaya çıkışıyla da ilişkilendirildi. Haberin önce yurt dışındaki büyük gazetelerde çıkması, içeride önemin geç fark edildiğini gösteriyordu.

## 6. Sunum: Formula 1 Araçlarında Lastikler

### 6.1 Günlük lastiklerle farklar

Sunum, F1 lastiklerini günlük hayatta kullanılan araç lastikleriyle karşılaştırarak başladı (ekrandan, 00:40:00):

| Günlük araç lastiği | F1 lastiği |
|---|---|
| Uzun ömürlü | Kısa ömürlü |
| Uzun ve dar | Kısa ve geniş |
| Sıcaklıktan etkilenmez | Sıcaklık çok önemlidir |
| Yol tutuşu az | Yol tutuşu aşırı fazla |
| Darbelere dayanıklı | Darbelere dayanıksız |

- F1 lastikleri yaklaşık 20-40 tur dayanacak şekilde tasarlanır.
- Kısa ve geniş olmaları, yol ile lastik arasındaki temas alanını artırıp yol tutuşunu yükseltmek içindir.
- Sıcaklık belli bir aralıkta tutulmalıdır: aralığın üstünde yol tutuşu yüksek olsa da aşınma çok artar, altında ise yol tutuşu çok azalır.
- Darbelere çok dayanıksızdırlar; kazalardan kalan parçalarla bile patlayabilirler.

Lastiklerin böyle tasarlanmasının temel nedeni virajlardan çok hızlı dönebilmektir.

### 6.2 Strateji ve lastik aşınması

Yarış boyunca takım stratejistleri lastik türlerine ve aşınmaya göre stratejiler belirler ve pilotlara iletir; pilotlar bu stratejiyi uygulayarak yarışı en kısa sürede bitirmeyi ya da belirli pozisyonları almayı hedefler. Bu stratejilerde pilotun lastiği koruma becerisi çok önemlidir: lastik ne kadar korunursa o kadar az aşınır ve pilot o kadar uzun süre hızlı tur atabilir. Pit stop süresi de belirleyicidir; lastik değişimi için pitte geçen süre uzadıkça yarışta zaman kaybedilir.

Lastikler yarış ilerledikçe kuvvet ve sıcaklık nedeniyle aşınır; aşınma aracı yavaşlatır ve turlar daha uzun sürede tamamlanır. Bu yüzden araçlar her yarışta en az bir kez daha hızlı lastik takmak için pite girer. Yarışta kullanılacak lastik setleri tedarikçi tarafından önceden belirlenir ve takımların başka set kullanması yasaktır.

### 6.3 Tarihçe ve günümüz lastikleri

Geçmişte F1'de bugün sporda bulunmayan birçok lastik markası yer aldı; sunumda Avon, Firestone, Continental, Dunlop, Englebert ve Michelin gibi markalar sayıldı. <!-- BELİRSİZ: marka listesinin bir kısmı altyazıda bozuk --> Geçmişte birden çok tedarikçi bulunduğu için takımlar araçlarına uygun lastiği seçebiliyor, markalar arasında rekabet oluşuyordu. İstatistik olarak en başarılı markalar Goodyear, Pirelli ve Bridgestone'dur. Sunumda, lastik sorunları yüzünden yalnız 6 aracın yarışa başladığı 2005 ABD Grand Prix'si de ilginç bir olay olarak anıldı.

Bugün F1'e tek tedarikçi olarak yalnız Pirelli lastik sağlar. Pirelli her yarıştan önce pistin özelliklerine göre kuru hava için üç temel set belirler: soft, medium ve hard. Soft daha yüksek yol tutuşu sağlar, hard daha uzun süre aşınmadan kullanılabilir, medium ise ikisi arasında dengeli bir lastiktir. Ağır yağış durumları için ayrı lastikler kullanılır. Her yarış hafta sonu için seans bazında lastik setleri belirlenir; bir seansın setleri başka bir seansta kullanılamaz, ancak yarışta sıralama turlarındaki (Q1, Q2, Q3) lastikler de kullanılabilir.

### 6.4 Soru-cevap

**Soru:** Şu anda tek lastik tedarikçisi Pirelli. Bunun nedeni nedir? Organizasyon farklı yıllarda farklı üreticilerle mi anlaşma yapıyor?

**Cevap:** Anlaşmalar yalnız tek yıllık değildir, çok yıllık kontratlar da yapılabilir. Sunan öğrenciye göre Pirelli büyük olasılıkla 2010'dan beri tek tedarikçidir; bunun nedeni, önceki iki tedarikçi Bridgestone ve Michelin'in F1 ile anlaşma yapmamasıdır.

**Soru:** Bridgestone ve Michelin'in işine mi gelmedi, yoksa şartlarda mı anlaşamadılar?

**Cevap:** Öğrenci Michelin hakkında bilgisi olmadığını, Bridgestone'un ise daha çok başka yarış serilerine ağırlık verdiği için F1'den çekildiğini düşündüğünü söyledi. Hoca, farklı yarış serilerinin (F1, F3 gibi) bulunduğunu ekledi.

**Soru:** Lastiklerin tek tedarikçiye ve üç tipe indirilmesi, motor ve araçla birlikte mekanik tarafın çok standartlaşmasına yol açtı; buna karşı çıkanlar ve çıkmayanlar var. Bunu nasıl değerlendiriyorsunuz?

**Cevap:** Öğrenci de standartlaşmaya karşı olduğunu söyledi: geçmişte birden çok markanın olması rekabeti artırıyor, markaları daha performanslı ve teknolojik lastik üretmeye itiyordu; tek tedarikçi olmak bu rekabeti azaltıp gelişmeyi yavaşlattı. Öte yandan F1'de kurallar çok katıdır: her yarıştan önce hakemler araçları denetler ve regülasyona uymayan bir parça ya da mekanizma bulursa parça değişiminden yarıştan ya da sezondan diskalifiyeye kadar ceza verebilir. Bunun nedeni, saniyenin onda birinin önemli olduğu bir sporda kural dışı zaman kazancını engellemektir.

## 7. Sunum: Vücut Geliştirme

### 7.1 Tanım

Yansıdaki tanıma göre vücut geliştirme, ağırlık kaldırma, kalori alımı ve diğer uygulamaların bir araya getirilmesiyle kas telciklerinin geliştirilmesi işlemidir; bu aktiviteyle uğraşan kişiye vücut geliştirici denir. Rekabete dayalı bir spor olarak vücut geliştirmede sporcular, jüri önünde fiziksel görünüşlerini çeşitli hareket serileriyle sergiler (ekrandan, 00:50:00). Sunan öğrenciye göre herkes kendi sağlık durumuna göre vücut geliştirme yapabilir; profesyonel düzeyde ise kişiye özel bir programla birlikte yürütülmelidir.

### 7.2 Tarihçe

Sunuma göre ilkel ağırlıklarla, daha büyük ve güçlü görünmek için bilinçli olarak vücut geliştiren bilinen bir topluluk Hintlilerdir: 11. yüzyıldan 16. yüzyıla kadar ağırlık kaldırarak vücut geliştirmek Hint askerleri arasında yaygındı. Amaç estetik değil güçlü ve iri görünmek olsa da modern vücut geliştirmenin öncüleri olarak gösterildiler. Refah düzeyinin yükselmesi ve bilimin gelişmesiyle insanlar vücutlarının sınırlarını merak etmeye başladı; 19. yüzyılda Amerika'da ve yaklaşık aynı dönemde Avrupa'da "strongman" adıyla, sirklerde ve meydanlarda ağır cisimleri kaldırıp çekerek güç gösterisi yapan kişiler ortaya çıktı.

### 7.3 Beslenme ve faydalar

Vücut geliştirmede beslenmenin önemi çok büyüktür; antrenmanla zorlanan kasların kendini yenilemesi gerekir. Beslenme programları kişiye özel hazırlanır: **bulk** dönemi kalori fazlasına, **definasyon** dönemi kalori açığına dayanır. Sunan öğrenciye göre en önemli nokta yeterli protein ve kalori almaktır.

Sunumda sayılan faydalar: insülin dengesinin ve kan şekerinin düzenlenmesi, kanser riskinin azalması, depresyonun önlenmesi, duruşun düzelmesi, kemik yoğunluğunun artması ve kaliteli uykunun desteklenmesi.

### 7.4 Soru-cevap

**Soru:** Vücut geliştirmenin yararlarından bahsettiniz. Zararları ya da dezavantajları var mı?

**Cevap:** Profesyonel olarak uzun süre ağırlık çalışan kişiler, sporu bıraktıktan sonra ve ileri yaşta omurga ağrıları ve kemik sorunları yaşayabilir; vücut uzun süre ağır strese maruz kalır. Hoca bunun daha çok belli bir limitin üstünde çalışan profesyonellere özgü bir sakınca olduğunu, ölçülü fiziksel aktivitenin depresyon ve Alzheimer gibi hastalıklara karşı çok önemli olduğunu belirtti; aktif bir yaşam için futbol, basketbol ya da yürüyüş bile yeterlidir. Öğrenci buna, bazı kişilerin genetik yatkınlık nedeniyle küçük ağırlıklarla bile sakatlanabildiğini ve profesyonellerin sorunlarının büyük ölçüde limitleri zorlamak için kullandıkları maddelerden kaynaklandığını ekledi.

## Örnek Sorular

**1.** (ekrandan, 00:15:00) Stokastik hesaplamada $0.50$ değerini temsil eden `01010101` ve `10010011` bit akışlarına bit bit AND uygulanıyor. Sonuç akışı ve temsil ettiği değer nedir?

> **Çözüm (yansıda verildi):** AND sonucu `00010001`; 8 bitin 2'si 1 olduğu için değer $2/8 = 0.25 = 0.50 \times 0.50$. İki akış korelasyonsuz olduğu için AND kapısı çarpıcı gibi davranır.

**2.** (derste sözlü, 00:05:43) Bir yazılım projesi bir Docker imajı üzerinde gerçekleştirildiyse, başka bir bilgisayarda çalışabilmesi için o bilgisayarda ne bulunmalıdır?

> **Cevap (derste verildi):** Bilgisayarda Docker kurulu olmalı; projenin kaynak dosyaları ve hazır bir Dockerfile aktarılmalıdır. Ardından imaj build edilir ve konteyner oluşturulup çalıştırılır.

**3.** (derste sözlü, 00:06:58) Bir konteynerin depolama ve bellek gibi çalışma zamanı gereksinimleri garanti edilebilir mi, çalışırken artırılıp azaltılabilir mi?

> **Çözüm (derste verilmedi):** Evet. Bellek ve işlemci sınırları konteyner başlatılırken `docker run --memory=... --cpus=...` seçenekleriyle verilir ve `docker update` ile çalışırken değiştirilebilir. Kalıcı depolama konteyner dışında tutulan volume'lerle sağlanır. Çok sayıda konteynerin kaynaklarını otomatik ölçeklemek için Kubernetes gibi orkestrasyon araçları kullanılır (büyük olasılıkla).

**4.** (derste sözlü, 00:08:40) Konteynerler ve mikroservisler birbirini nasıl tamamlar, birlikte kullanılmalarının avantajları nelerdir?

> **Cevap (derste verildi):** Uygulama mesaj gönderme, mesaj alma, bildirim gibi hafif servislere bölünür ve her servis ayrı konteynerde çalışır. Bir servisteki hata yalnız kendi konteynerini etkiler, konteyner kendini yeniden başlatır; servisler birbirinden izole olduğundan virüs ya da çökme diğerlerine yayılmaz. Tek parça (monolitik) yapıda ise tek bir hata bütün uygulamayı durdurur.

**5.** (derste sözlü, 00:18:54) Stokastik hesaplama olasılık hesabına dayandığı için rastgele bir yaklaşım mıdır? Kuantum hesaplamayla ilişkilendirilebilir mi?

> **Cevap (derste verildi):** Evet, olasılığa dayanır ve bu yüzden stokastik adını alır. Kuantum hesaplama da olasılık dağılımlarıyla çalıştığı için iki alan arasında bağlantı olabileceği bir araştırma sorusu olarak bırakıldı.

**6.** (derste sözlü, 00:27:00) Belirli bir problemi çözen bir yapay zekanın kapasitesi ve başarımı, aynı problemi çözen bir insanla nasıl karşılaştırılabilir?

> **Cevap (derste verildi):** Sunan öğrenciye göre yapay zeka girdilerle sürekli kendini geliştirdiği için insanın sınırlı kapasitesine karşı bazı alanlarda öne geçebilir. Hoca, satranç gibi örneklerin yapay zeka tekniklerinden çok algoritmik yaklaşımla da çözülebildiğini hatırlattı.

**7.** (derste sözlü, 00:44:38) F1'de tek lastik tedarikçisi olmasının nedeni nedir ve bu standartlaşma nasıl değerlendirilebilir?

> **Cevap (derste verildi):** Önceki tedarikçiler Bridgestone ve Michelin anlaşma yapmayınca Pirelli tek tedarikçi kaldı. Sunan öğrenciye göre tek tedarikçi rekabeti ve dolayısıyla lastik teknolojisindeki gelişmeyi azalttı; katı kurallar ise kural dışı zaman kazancını engellemek içindir.

**8.** (derste sözlü, 00:53:09) Vücut geliştirmenin zararları ya da dezavantajları var mıdır?

> **Cevap (derste verildi):** Uzun süre ağır yükle çalışan profesyonellerde ileri yaşta omurga ve kemik sorunları görülebilir; genetik yatkınlık sakatlık riskini artırabilir. Ölçülü yapılan fiziksel aktivite ise sağlık için yararlıdır.

## Dersin Toparlaması

Bu derste altı öğrenci farklı alanlardan sunumlar yaptı. Bilgisayar mühendisliğiyle doğrudan ilgili sunumlar öne çıktı: Docker sunumu imaj, konteyner ve Dockerfile kavramlarını, sanal makineyle farklarını ve konteynerlerin mikroservis mimarisindeki rolünü anlattı; hoca bu konunun bütün öğrenciler için önemli olduğunu vurgulayıp monolitik ve mikroservis yaklaşımlarını karşılaştırdı. Stokastik hesaplama sunumu, sayıların bit akışlarıyla gösterilmesi sayesinde çarpmanın tek bir AND kapısıyla yapılabildiğini, buna karşılık akışlar arasındaki korelasyonun doğruluğu bozduğunu gösterdi. Yapay zeka sunumu alanın tanımını, tarihçesini ve uygulama alanlarını özetledi.

Diğer sunumlar internetin erken döneminde ortaya çıkan ilk internet fenomenini, Formula 1'de lastik teknolojisi ile stratejisini ve vücut geliştirmenin tarihçesi, beslenmesi ve faydalarını ele aldı. Her sunumdan sonra yapılan soru-cevaplar, konuları sunumda değinilmeyen yönlerden (kaynak yönetimi, olasılıksal hesaplama ile kuantum hesaplama ilişkisi, yapay zekanın insanla karşılaştırılması, standartlaşma ve rekabet, sporun sakıncaları) genişletti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
