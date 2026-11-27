# Ders 12 Çalışma Özeti

## Genel Konular

- Dersin işleyişi
  - Bu ders çevrimiçi (Zoom) öğrenci sunumlarıyla geçti. Altı öğrenci sırayla kendi seçtikleri konularda yaklaşık beşer dakikalık sunum yaptı. Her sunumdan sonra önce dinleyicilere soru için söz verildi; soru gelmeyince hoca konuyu genişleten sorular sordu.
- Docker ve konteyner teknolojisi (ekrandan, 00:05:00)
  - Docker bir konteyner teknolojisidir: aynı işletim sistemi üzerinde birbirinden izole ve bağımsız çok sayıda konteyner çalıştırılabilir.
  - Docker imajlardan (image) ve konteynerlerden oluşur. İmaj, Python, MySQL, Linux (ör. Alpine) gibi bir temel üzerine kurulur; konteyner bu imajdan çalışan örnektir.
  - Dockerfile, imajın hangi temel imajdan oluşturulacağını ve konteynerin nasıl çalışacağını belirleyen komutlar dizisidir. Projeyi başka bir bilgisayara taşımak için kaynak dosyalarla birlikte Dockerfile'ı göndermek yeterlidir.
  - Mikroservislerden oluşan bir projede her servis ayrı konteynerde çalışınca birindeki hata (çökme, runtime hatası, virüs) diğerlerini etkilemez; Docker çöken konteyneri yeniden başlatabilir.
  - Konteynerler saniyeler içinde açılıp kapanır, kolay yönetilir; Linux çekirdeği üzerinde çalışır ama Windows'ta da kullanılabilir.
  - VM ile Docker karşılaştırması (ekrandan, 00:05:00):

    | Özellik | VM (Virtual Machine) | Docker |
    |---|---|---|
    | OS | Tam işletim sistemi | Küçültülmüş işletim sistemi imajı |
    | İzolasyon | Yüksek | Daha düşük |
    | Çalışır hale gelmesi | Dakikalar | Saniyeler |
    | Versiyonlama | Yok | Yüksek |
    | Kolay paylaşılabilirlik | Düşük | Yüksek |

  - Yansıdaki katman şeması: sanal makinelerde Infrastructure, Hypervisor, her uygulama için ayrı Guest OS, Bins/Lib, App; konteynerlerde Infrastructure, Operating System, Container Engine, her uygulama için Bins/Lib, App (ekrandan, 00:05:00).
- Stokastik hesaplama (stochastic computing) (ekrandan, 00:15:00)
  - Sayılar, içindeki 1'lerin oranı değeri veren rastgele bit akışlarıyla (bit stream) gösterilir; hesaplama olasılığa dayandığı için "stokastik" adını alır.
  - Kullanılma nedeni küçük donanım ayak izidir: geleneksel hesaplamada çarpma ve bölme birimleri karmaşıktır; stokastik hesaplamada çarpma tek bir AND kapısıyla, toplama (yansıya göre) OR kapısıyla yapılır ve akış ne kadar uzun olursa olsun tek bir mantık kapısı yeterlidir.
  - Yansıdaki örnek: $0.50$ = `01010101` ve $0.50$ = `10010011` akışlarının bit bit AND'i `00010001` = $0.25$ verir (ekrandan, 00:15:00).
  - Dezavantaj: işlemler yüzde yüz doğru değildir, bit akışları arasındaki korelasyondan etkilenir. Akışlar pozitif korelasyonluysa AND kapısı çarpıcı değil minimum fonksiyonu gibi davranır.
  - Uygulama alanı olarak görüntü işleme (ör. kenar bulma) ve enerji verimli sistemler anıldı. <!-- BELİRSİZ: sunumun bu kısmı İngilizceydi ve altyazı büyük ölçüde bozuk; ayrıntılar okunamadı -->
- Yapay zekaya giriş (ekrandan, 00:25:00 ve 00:30:00)
  - Tanım: insan zekasını taklit ederek görevleri yerine getiren ve topladığı bilgilere göre kendini geliştirebilen sistemler; derin öğrenme ve doğal dil işleme gibi teknolojilerle deneyimden öğrenme sağlanır.
  - Tarihçe: Alan Turing'in "makineler düşünebilir mi?" sorusu; McCulloch ve Pitts'in yapay sinir hücreli hesaplama modeli; Hebb'in bağlantı şiddetlerinin değişmesiyle öğrenme fikri; ilk yapay sinir ağı tabanlı bilgisayar SNARC (1951); "yapay zeka" adının konduğu 1956 çalışması; Newell ve Simon'ın kuram ispatlayan programı ve Genel Sorun Çözücü'sü.
  - Üç ana dönem: nöral ağlar, makine öğrenmesi, derin öğrenme.
  - Uygulama alanları (ekrandan, 00:25:00): ses tanıma, görüntü işleme, doğal dil (lisan) işleme, muhakeme, öneri sistemleri, regresyon analizi, dil çevirileri.
- İnternet Mahir: ilk internet fenomeni (ekrandan, 00:35:00)
  - Bir öğretmen olan Mahir Çağrı'nın internetten tanıştığı kişilerin yardımıyla kurduğu, çok sade içerikli kişisel web sayfası kısa sürede dünya çapında ilgi gördü; sunumda ilk internet fenomeni olarak tanıtıldı.
  - Etkisi: dünya basınında yer alması, adına tişört, mousepad ve kahve bardağı üretilmesi (ekrandan, 00:35:00); ancak süreci iyi yönetemediği için birkaç yıl içinde unutulması.
- Formula 1 araçlarında lastikler (ekrandan, 00:40:00)
  - Günlük lastiklerle farklar (ekrandan, 00:40:00): uzun ömürlü ve kısa ömürlü; uzun ve dar ile kısa ve geniş; sıcaklıktan etkilenmez ile sıcaklık çok önemlidir; yol tutuşu az ile aşırı fazla; darbelere dayanıklı ile dayanıksız.
  - Lastik aşınması tur sürelerini uzatır; strateji, pilotun lastiği koruma becerisi ve pit stop süresi yarışı belirler.
  - Bugün tek tedarikçi Pirelli'dir; kuru zemin için soft, medium, hard setleri vardır (soft daha çok yol tutuşu, hard daha uzun ömür, medium dengeli).
- Vücut geliştirme (ekrandan, 00:50:00)
  - Tanım: ağırlık kaldırma, kalori alımı ve diğer uygulamaların bir araya getirilmesiyle kas telciklerinin geliştirilmesi; rekabete dayalı biçimde jüri önünde fiziksel görünüş sergilenir (ekrandan, 00:50:00).
  - Tarihçe: Hint askerleri arasında ağırlık kaldırma (11-16. yüzyıl), 19. yüzyılda Amerika ve Avrupa'da "strongman" gösterileri.
  - Beslenme kişiye özeldir (bulk: kalori fazlası, definasyon: kalori açığı); yeterli protein ve kalori alımı öne çıkar.

## Hocanın Özellikle Vurguladığı Kısımlar

- Konteynerler ve mikroservisler
  - Hoca, bu konuyu bütün öğrencilerin bilmesi gerektiği için özellikle üzerinde durduğunu söyledi.
  - Mikroservis yaklaşımı, uygulamayı mümkün olduğunca hafif servislere bölüp uygulamayı bu servisler üzerinden sunmaktır. Zıddı olan monolitik yaklaşım (bütün servislerin tek parça uygulamada olması) günümüzün esneklik ve çeviklik ihtiyaçlarına yetişemez.
  - Konteynerler, özellikle açık kaynak yazılımları hızla bir araya getirip kullanıma almada en yüksek çevikliği sağlar; konteynerler üzerinde çalışan mikroservislerle yazılım geliştirmeyi öğrenmeye yatırım yapılmasını önerdi.
- Konteyner kaynak yönetimi
  - Hoca, konteynerde depolama ve bellek gibi çalışma zamanı gereksinimlerinin garanti edilip edilemeyeceğini ve çalışırken artırılıp azaltılabileceğini sordu; bu, araştırılması gereken önemli bir soru olarak kaldı.

## Kısa Tekrar Notları

- Docker: imaj (şablon) + konteyner (çalışan örnek) + Dockerfile (imajı tarif eden komutlar).
- VM tam işletim sistemi ve hypervisor kullanır, dakikalarda açılır; konteyner ortak işletim sistemi ve container engine kullanır, saniyelerde açılır.
- Başka bilgisayarda çalıştırmak için gerekenler: Docker kurulu olması, kaynak dosyalar ve Dockerfile; sonra imaj build edilir, konteyner çalıştırılır.
- Konteyner + mikroservis: her servis izole, biri çökerse diğerleri çalışır, çöken yeniden başlatılır.
- Stokastik hesaplama: değer = bit akışındaki 1'lerin oranı; AND ile çarpma ($0.5 \times 0.5 = 0.25$); doğruluk akışların korelasyonuna bağlı.
- Yapay zeka dönemleri: nöral ağlar, makine öğrenmesi, derin öğrenme.
- F1 lastikleri kısa ömürlü, geniş, sıcaklığa duyarlı; tek tedarikçi Pirelli; soft, medium, hard.
- Vücut geliştirmede beslenme kişiye özeldir; bulk ve definasyon dönemleri kalori fazlası ve açığına dayanır.

## Detaylı Açıklamalar

- **Docker ve sanal makine farkı.** Sanal makinede her uygulama kendi tam konuk işletim sistemiyle (Guest OS) hypervisor üzerinde çalışır; bu yüzden izolasyon yüksektir ama açılış dakikalar sürer ve paylaşmak zordur. Docker'da konteynerler ortak işletim sistemi üzerindeki container engine'i paylaşır, yalnız kendi kütüphanelerini (Bins/Lib) taşır; küçültülmüş işletim sistemi imajı kullandığı için saniyeler içinde açılır. Binlerce konteynerin yönetildiği sistemlerde bu açılış farkı önemli hale gelir. Bir projeyi hocaya ya da başka bir ekibe göndermek için bütün kütüphaneleri kurdurmak yerine kaynak dosyalarla Dockerfile'ı vermek yeterlidir; karşı taraf Docker kuruluysa imajı oluşturup konteyneri çalıştırır.
- **Mikroservis örneği.** Sunumda bir mesajlaşma uygulaması örneği verildi: mesaj gönderme, mesaj alma ve bildirim gönderme ayrı servislerdir. Hepsi tek parça çalışırsa mesaj alma kodundaki bir hata bütün uygulamayı çökertir ve bildirim de gelmez. Servisler ayrı terminallerde çalıştırılsa bile bilgisayara bir şey olunca hepsi durur. Her servis ayrı konteynerde çalışınca bir servisteki hata yalnız o konteyneri etkiler, konteyner yeniden başlatma politikasıyla kendini ayağa kaldırır.

> **Ek bilgi (derste anlatılmadı):** Docker'da konteynerin kullanabileceği bellek ve işlemci, konteyner başlatılırken `docker run --memory=512m --cpus=1.5 ...` gibi seçeneklerle sınırlanabilir ve `docker update` ile çalışırken değiştirilebilir. Çöken konteynerin otomatik yeniden başlatılması `--restart` politikasıyla (ör. `--restart=always`) ayarlanır. Birden çok konteynerin birlikte yönetimi için Docker Compose ve Kubernetes gibi araçlar kullanılır.

- **Stokastik hesaplama.** Bu yaklaşımda bir sayı, 1 olma olasılığı o sayıya eşit olan bir bit akışıyla gösterilir. İki bağımsız (korelasyonsuz) akışın bit bit AND'i, iki olasılığın çarpımı olasılığıyla 1 olur; bu yüzden çarpma tek bir AND kapısıyla yapılır. Yansıdaki örnekte `01010101` (dört 1, $4/8 = 0.50$) ile `10010011` (dört 1, $0.50$) AND'lenince `00010001` (iki 1, $2/8 = 0.25$) elde edilir. Akışlar pozitif korelasyonluysa (1'ler aynı yerlerde toplanıyorsa) AND çıkışı çarpım yerine iki değerin küçüğünü verir. Hoca, yaklaşımın olasılık hesabına dayandığı için bir ölçüde rastgele olduğunu teyit ettirdi ve kuantum hesaplamanın olasılıksal doğasıyla bir bağlantı olup olamayacağını düşünmeyi önerdi.

> **Ders sonrası not:** Yansıda toplamanın OR kapısıyla yapıldığı yazıyor. Korelasyonsuz akışlarda OR çıkışının olasılığı $p_1 + p_2 - p_1 p_2$ olur; aynı örnekte OR sonucu `11010111` = $0.75$ çıkar, $0.5 + 0.5 = 1$ değil. Yani OR yalnız küçük değerler için yaklaşık toplama verir; stokastik hesaplamada toplama genellikle bir çoklayıcıyla (MUX) ölçeklenmiş toplama $(p_1 + p_2)/2$ olarak yapılır (büyük olasılıkla).

- **Yapay zeka ve insan karşılaştırması.** Hoca, yapay zekanın genelde belirli bir alanda uzmanlaşmış uygulamalarla anıldığını hatırlattı ve satranç örneğini verdi: insan ustayı yenen bilgisayarlar yapılmıştır, ancak bu problem yapay zeka tekniklerinden çok algoritmik yaklaşımla da çözülebilir. Bir problemi çözen yapay zekanın kapasitesi ve başarımının aynı problemi çözen insanla nasıl karşılaştırılabileceğini sordu. Sunan öğrenci, yapay zekanın girdilerle sürekli kendini geliştirdiğini, insan kapasitesinin bir sınırı olduğunu ve bazı noktalarda yapay zekanın insanın önüne geçebileceğini düşündüğünü söyledi.
- **İnternetin gücü.** İnternet Mahir sunumu sonrası hoca, bu olayın o dönemde internetin önemini ve gücünü göstermesine rağmen yeterince kavranmadığını; olayın kişilerin internet üzerinden nasıl ünlü olduğu ve insanlar üzerindeki etkisi bakımından incelendiğini belirtti.
- **F1'de tek lastik tedarikçisi.** Sunan öğrenciye göre Pirelli büyük olasılıkla 2010'dan beri tek tedarikçidir; önceki tedarikçiler Bridgestone ve Michelin'in F1 ile anlaşma yapmamasıyla bu durum oluştu. Öğrenci, geçmişte birden çok markanın rekabetinin lastiklerin gelişmesini sağladığını, tek tedarikçinin bu rekabeti azalttığını savundu. F1'de kurallar katıdır: hakemler her yarıştan önce araçları denetler, kurala uymayan parça için parça değişiminden diskalifiyeye kadar ceza verilebilir; amaç saniyenin onda birinin önemli olduğu bir sporda kural dışı zaman kazancını engellemektir.
- **Vücut geliştirmenin sakıncaları.** Hocanın sorusu üzerine sunan öğrenci, profesyonellerin uzun süre ağır yük çalışması nedeniyle ileri yaşta omurga ve kemik sorunları yaşayabildiğini, bazı kişilerde genetik yatkınlık nedeniyle küçük ağırlıklarla bile sakatlık görülebildiğini söyledi. Hoca, sakıncaların daha çok limiti aşan profesyonel çalışmadan kaynaklandığını, ölçülü fiziksel aktivitenin depresyon ve Alzheimer gibi hastalıklara karşı önemli olduğunu belirtti.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
