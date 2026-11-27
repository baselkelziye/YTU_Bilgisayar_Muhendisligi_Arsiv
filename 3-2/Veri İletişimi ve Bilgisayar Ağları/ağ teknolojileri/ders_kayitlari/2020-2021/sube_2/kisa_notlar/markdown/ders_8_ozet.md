# Ders 8 Çalışma Özeti

## Genel Konular

- Hizmet kalitesine (Quality of Service, QoS) giriş
  - Ders, bir önceki haftada işlenen tıkanıklık kontrolünün devamı olarak hizmet kalitesine ayrıldı. Bölümün başlıkları slaytta şöyle sıralanıyor (ekrandan, 00:05:00): application requirements, traffic shaping, packet scheduling, admission control, integrated services, differentiated services.
  - Bütün uygulamaların ağdan beklentileri aynı olsaydı QoS'tan söz etmek anlamsız olurdu. Uygulamalar ihtiyaçlarına göre kategorilere ayrılabildiği için ağın bu kategorilere farklı davranması gerekir.
  - QoS yalnız kullanıcının ya da uygulamanın hizmet kalitesi değildir; servis sağlayıcının bütün ağının (topolojinin) kalitesi olarak da görülmelidir. Trafik, uygulamanın çıkışından bağımsız olarak ağ katmanında şekillendirilir.
  - Trafiği host kendisi düzenlerse buna trafik şekillendirme (traffic shaping), servis sağlayıcı ağın girişinde denetlerse trafik polisliği (policing) denir.
  - İşletim sistemlerindeki işlemci zamanlamasına benzer biçimde, ağda da paylaşılan kaynak olan paket iletimi için bir zamanlama (packet scheduling) yapılır.
- Aşırı kapasite (over-provisioning) ve QoS
  - Ağ gereğinden çok geniş tasarlanırsa (örneğin karasal telefon ağında hep çevir sesi alınması) QoS ile uğraşmaya gerek kalmaz.
  - Ama "gereğinden fazla"nın ne kadar olduğu bilinemez; bugün fazla olan kapasite birkaç yıl sonra yetersiz kalabilir. Bu yüzden sonunda QoS mekanizmalarına ihtiyaç duyulur.
- Uygulama gereksinimleri tablosu (ekrandan, 00:25:00)
  - Ölçütler: bant genişliği (bandwidth), gecikme (delay), gecikmenin değişimi (jitter) ve kayıp (loss).
  - Tablodaki "High", değerin yüksek olması değil, o ölçüt açısından talebin zorlayıcı olması demektir (örneğin düşük gecikme istenmesi).

    | Uygulama | Bandwidth | Delay | Jitter | Loss |
    |---|---|---|---|---|
    | Email | Low | Low | Low | Medium |
    | File sharing | High | Low | Low | Medium |
    | Web access | Medium | Medium | Low | Medium |
    | Remote login | Low | Medium | Medium | Medium |
    | Audio on demand | Low | Low | High | Low |
    | Video on demand | High | Low | High | Low |
    | Telephony | Low | High | High | Low |
    | Videoconferencing | High | High | High | Low |

  - E-posta: asenkron bir uygulamadır, gönderim ile cevap zaman olarak birbirinden ayrıdır; bant genişliği, gecikme ve jitter talebi düşüktür. Asıl sorun veri kaybıdır, çünkü kayıpta yeniden gönderim gerekir.
  - Telefon ve ses konferansı: kaliteyi belirleyen gecikme ve jitter'dır; sesin bant genişliği ihtiyacı düşüktür.
  - Dosya paylaşımı: baskın ölçüt bant genişliğidir; yerel diskler çok hızlandığı için ağdan veri alırken de olabildiğince yüksek hız istenir.
  - Video on demand ile videokonferansın farkı gecikmedir: kayıtlı videoda istemci tamponlayabildiği için gecikmenin etkisi düşüktür, canlı görüşmede yüksektir.
- Gürültücü komşu (noisy neighbor) sorunu
  - Ağda aynı anda farklı tipte uygulamaların paketleri akar. Bulduğu bütün bant genişliğini kullanmaya eğilimli bir uygulama (örneğin dosya paylaşımı) sınırlanmazsa kaynakları tekeline alır ve diğerlerini rahatsız eder.
  - Bu yüzden ağ, uygulamanın tipini anlayabilmeli ve her biri için uygun parametreleri sağlayabilmelidir.
- Ağ hizmet kategorileri (ekrandan, 00:35:00)
  - Slayttaki örnek ATM ağlarından alınmıştır:

    | Ağ hizmeti | Uygulama |
    |---|---|
    | Constant bit rate (CBR) | Telephony |
    | Real-time variable bit rate | Videoconferencing |
    | Non-real-time variable bit rate | Streaming a movie |
    | Available bit rate (ABR) | File transfer |

  - ATM (Asynchronous Transfer Mode), 53 baytlık hücrelerle çalışan, paket anahtarlamanın daha küçük birimli bir biçimidir. Küçük birim QoS'un daha hassas uygulanmasını sağlar. ATM'nin uyarlama katmanı (AAL5) ADSL içinde hâlâ kullanılır.
  - CBR: telefon gibi bit hızı sabit olan trafik. Konuşma sesinin üst frekansı yaklaşık 4 kHz olduğu için örnekleme teoremine göre 8 kHz ile örneklenir; kanal ihtiyacı sabittir.
  - Real-time VBR: videokonferans. Sahne değiştikçe (ışık, renk, hareket) sıkıştırılmış görüntünün bit ihtiyacı anlık değişir, ama gecikme küçük olmalıdır.
  - Non-real-time VBR: kayıtlı video izleme. Bit hızı yine değişkendir ama istemci önden tamponlayabildiği için gerçek zaman kısıtı kalkar.
  - ABR: önce CBR, sonra gerçek zamanlı ve gerçek zamanlı olmayan VBR karşılanır; geriye kalan kapasite ABR trafiğe (örneğin dosya indirme) verilir. Ağ üst kategorilerce yoğun kullanılınca indirmeler yavaşlar.
- Trafik şekillendirme (ekrandan, 00:45:00 ve 01:00:00)
  - Trafik şekillendirme, ağa giren verinin ortalama hızını (R) ve ani artışını (burst, B) düzenler ve garanti verilebilmesini sağlar.
  - Burst istenmez, çünkü her ağ cihazının arayüz tamponu sınırlıdır; farklı hızdaki hatlardan ve birden fazla arayüzden gelen yoğun trafik tamponu doldurur ve paket düşürülür.
  - Leaky bucket (sızdıran kova): kovanın altındaki deliğin çapı, yani çıkış hızı sabittir. Kova taşarsa yeni gelen paketler düşer. Sabit bit hızlı (CBR) trafiğe uygundur.
  - Token bucket (jeton kovası): kovaya R hızıyla jeton dolar, en çok B kadar birikir. Paket göndermek için jeton harcanır. Birikmiş jeton varken paketler beklemeden çıkar (burst), jeton bitince çıkış jeton üretim hızına iner. Değişken bit hızlı (VBR) trafiğe uygundur.
  - Kova boyutu B, izin verilen burst miktarını belirler. B = 0 olursa token bucket, leaky bucket gibi davranır.
- Paket zamanlama (ekrandan, 01:10:00 ve 01:15:00)
  - FIFO kuyrukta saldırgan (greedy) bir akış kuyruğu doldurup diğer akışları ezer. Alternatif, kuyruklardan sırayla paket alan round-robin hizmettir.
  - Klasik round-robin paket sayısına göre adildir, bit sayısına göre değil: büyük paket gönderen kuyruk birim zamanda daha fazla bit çıkarır.
  - Fair Queueing bit düzeyindeki adaleti yaklaşık olarak sağlar; kuyruklara ağırlık verilince Weighted Fair Queueing (WFQ) elde edilir. Paketler varış sırasından farklı sırayla gönderilebilir; sıranın düzeltilmesi varış noktasının işidir.
  - Sanal bitiş zamanı: $F_i = \max(A_i, F_{i-1}) + L_i / W$ (ekrandan, 01:15:00). Paketler bitiş zamanı küçükten büyüğe gönderilir.
- Kabul kontrolü (admission control) ve akış tanımı (ekrandan, 01:20:00 ve 01:25:00)
  - Ağa girecek trafiğin bir akış tanımıyla (flow specification) ifade edilmesi gerekir; router bu bilgiyle akışı taşıyıp taşıyamayacağına karar verir.
  - Örnek akış tanımı parametreleri: token bucket rate (bayt/s), token bucket size (bayt), peak data rate (bayt/s), minimum packet size (bayt), maximum packet size (bayt).
  - Router kaynakları (tampon, işlem gücü, bant genişliği) yetiyorsa akışı kabul eder, yetmiyorsa reddeder ya da daha düşük bir değer önerebilir. Sanal devre kurulurken yol bu parametrelere uygun router'lar üzerinden adım adım seçilir.
  - Akış (flow): iki uygulama arasında paket paket aktarılan ve gönderen ile alan açısından aynı sırada olan ardışık paketlerdir; ağ içinde sıralı ya da sırasız ilerleyebilir.
  - Bant genişliği B ve gecikme D garantisi için: kaynak (R, B) token bucket ile şekillendirilir, router'larda WFQ ağırlığı $W / \sum w > R / C$ olacak şekilde çalıştırılır; bu bütün trafik desenleri ve topolojiler için geçerlidir. Bütün yol üzerindeki router'lar bunu ortak uygulamalıdır.
- Integrated Services (IntServ) ve RSVP (ekrandan, 01:30:00)
  - Her akış için ayrı QoS parametresi verilebilir; çok noktaya yayın (multicast) trafiği de diğer trafikle birlikte desteklenir. Kabul kontrolü zorunludur.
  - Kaynak ayırma protokolü RSVP'dir (Resource Reservation Protocol). Rezervasyonu alıcılar başlatır.
  - Örnekte alıcı 3, kaynak 1'den J-H-E-A yolu üzerinden, kaynak 2'den J-H-E-C yolu üzerinden bant genişliği ayırır. Alıcı 5 kaynak 1'i istediğinde yeni bir akış kurulmaz; ayırma H noktasında alıcı 3'ünkiyle birleşir ve H-L-5 dalı eklenir.
- Differentiated Services (DiffServ) (ekrandan, 01:35:00)
  - Akış başına değil, sınıf başına hizmet verilir. En basit hali sıradan ve aciliyeti yüksek iki sınıftır (Expedited Forwarding).
  - Assured Forwarding: birden fazla hizmet sınıfı ve her birinde ayrı düşürme sınıfları vardır; slayttaki şekilde dört öncelik sınıfı ile on iki öncelik/düşürme sınıfı görülür.
  - Uygulanışı: müşteri pakete istediği sınıfı işaretler, servis sağlayıcı işaretlerin karşılığının ödendiğinden emin olmak için trafiği şekillendirir, router'lar farklı hizmet düzeyleri için WFQ kullanır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Tablodaki "High" anlamı
  - "High", bant genişliğinin ya da gecikmenin yüksek olduğu anlamına gelmez; o ölçütün uygulamanın kalitesi üzerindeki etkisinin büyük, talebin zorlayıcı olduğu anlamına gelir.
  - Hocalar slayttaki tabloda Video on demand satırının bant genişliği "High" değerinin işaretlenmeyi unutulduğunu belirtti.
- Constant bit rate
  - Hoca CBR'ın telefon örneğiyle akılda tutulmasını özellikle istedi; bu ayrımların gerçek hayatta karar vermeyi kolaylaştıracağını söyledi.
- Burst'ün neden zararlı olduğu
  - Ani artışlar cihaz tamponlarını doldurur, paket düşürmeye ve sonunda tıkanıklığa yol açar. Trafik şekillendirme bunu yalnız düzenlemekle kalmamalı, garantili biçimde düzenlemelidir.
- Leaky bucket ve token bucket farkı
  - Leaky bucket katıdır, çıkış hızı hiç değişmez. Token bucket uyarlanabilirdir; biriken jeton bitene kadar burst'e izin verir, sonra sabit hıza iner. Bu bir emniyet valfi gibidir.
  - Burst miktarı da tampon boyutuyla sınırlanmalıdır ki bir sonraki router'a gereksiz yük bindirilmesin.
- Akış tanımı (flow specification)
  - Hoca bu terimin akılda tutulmasını istedi. TCP/IP'ye geçildiğinde bir akışın kaynak adresi, hedef adresi, kaynak portu, hedef portu ve protokol ile tanımlandığı ayrıntılı görülecek.
- Formüller kitapta
  - Leaky bucket ve token bucket ile ilgili formüller slaytlarda yok, kitapta var; hoca bu kısmın kitaptan ayrıca okunmasını istedi.

## Kısa Tekrar Notları

- QoS ölçütleri: bandwidth, delay, jitter, loss.
- "High" = zorlayıcı talep. Telefon: delay ve jitter. Dosya paylaşımı: bandwidth. Videokonferans: bandwidth, delay ve jitter.
- ATM hizmet kategorileri: CBR (telefon), RT-VBR (videokonferans), NRT-VBR (film izleme), ABR (dosya aktarımı). ATM hücresi 53 bayt.
- Trafik şekillendirme ortalama hızı (R) ve burst'ü (B) sınırlar. Host yaparsa shaping, ISP yaparsa policing.
- Leaky bucket: sabit çıkış hızı, CBR'a uygun. Token bucket: jeton birikimi kadar burst, VBR'a uygun. B = 0 ise token bucket leaky bucket olur.
- Round-robin paket sayısında adildir, bit sayısında değil. WFQ: $F_i = \max(A_i, F_{i-1}) + L_i/W$, küçük bitiş zamanı önce gider.
- Akış tanımı: token bucket rate, token bucket size, peak data rate, min ve max paket boyutu.
- Garanti için: kaynak (R, B) token bucket ile şekillendirilir, WFQ'da $R < W \cdot C / \sum w$.
- IntServ: akış başına rezervasyon, RSVP, alıcı başlatır, multicast'te ayırmalar birleşir.
- DiffServ: sınıf başına hizmet; Expedited Forwarding ve Assured Forwarding; müşteri işaretler, ISP şekillendirir, router WFQ uygular.

## Detaylı Açıklamalar

- Neden QoS gerekir?
  - Bir topolojinin birim zamanda aktarabileceği paket miktarı sınırlıdır; aşılırsa tıkanıklık başlar. Aynı anda farklı tipte uygulamaların paketleri aynı topolojiden geçtiği için, mühendislik açısından yapılması gereken bu paketleri birbirinin ayağına en az basacak biçimde bir araya getirip aktarmaktır.
  - Uygulama ile servis sağlayıcı arasında bir anlaşma vardır: uygulama bant genişliği, hız ve gecikme ihtiyacını beyan eder ve bu kurallara uyar; ağ da paketleri bu ihtiyaçlara uygun taşır. Bu, tıkanıklık kontrolündeki kabul kontrolünün devamıdır.
  - Servis sağlayıcı açısından trafiği tanımak başka amaçlar için de kullanılır: bazı trafik türlerini (örneğin eşler arası paylaşım ya da sağlayıcının kendisi dışındaki IP üzerinden ses) sınırlamak, düşürmek ya da farklı fiyatlandırmak.
- Ses ve video trafiği
  - Ders sırasında hocalardan birinin sesinin zayıf gelmesi canlı bir örnek olarak kullanıldı: o anki ses aktarımının kalitesini teknik olarak gecikme ve jitter belirler.
  - Video sıkıştırmada (durağan görüntüde JPEG, hareketli görüntüde MPEG) görüntü parçalara bölünür ve parçalardaki değişim fark (delta) olarak aktarılır. Karanlık bir sahnede aktarılacak bilgi neredeyse sıfırken sahne aydınlanınca bit ihtiyacı birden artar; bu da burst demektir.
  - Görüntülü görüşmede gecikme fark edilir: kafa hareketi karşı tarafta bir saniye sonra görünürse beyin bunu yadırgar. Bu yüzden videokonferans gerçek zamanlı VBR'dır. Kayıtlı videoda istemci, o an izlenen saniyenin ilerisini tamponlayarak gerçek zaman kısıtını ortadan kaldırır.
- Asimetrik erişim hatları (öğrenci sorusu üzerine)
  - İndirme ve yükleme hızlarının farklı olması kullanılan altyapıyla ilgilidir. ADSL'deki "A" asimetrik demektir: ev kullanıcısı servis sağlayıcı değil, hizmet alan taraf olduğu için eve gelen yöne daha fazla kapasite verilir. Kablo modemde de durum benzerdir.
  - Kablosuz ve uydu bağlantılarında da fiziksel katman ne olursa olsun, üst katmanlarda bant genişliği sınırlaması ve ağa kabul yapılabilir. Bölgedeki kullanıcı sayısı arttıkça paylaşılan kapasite nedeniyle kullanıcı başına hız düşer. Hoca konuyla ilgilenenlere eski bir uydu telefon projesi olan Iridium'u okumayı önerdi.
- Leaky bucket ayrıntısı
  - Kova, her host, router ve ağ arayüzünün tamponunu temsil eder. Deliğin çapı tampondan veri çıkarma hızıdır ve sabittir. Musluk kapatılmadan su verilmeye devam edilirse kova taşar; bu, tamponun dolması ve yeni paketlerin düşürülmesi demektir. Kova taşsa bile çıkış hızı değişmez.
- Token bucket ayrıntısı
  - Çaycıdaki pul benzetmesi: pulun varsa çay alırsın, pul bitince yeni pul almadan çay gelmez. Burada da her jeton üretim süresinde bir jeton üretilip kenara konur. Örneğin 10 tur boyunca trafik gelmezse 10 jeton birikir; ardından gelen trafik bu 10 jetonun karşıladığı miktar kadarsa hiç beklemeden çıkar. Jetonlar bitince trafik sabit hızla devam eder.
  - Bir slaytta (kareye düşmedi) aynı kaynak trafiğinin farklı kova boyutlarıyla (16000 KB, 9600 KB, 0) nasıl şekillendiği gösterildi. Kova büyüdükçe burst daha uzun sürer; B = 0 iken trafik doğrudan sabit hızla çıkar. <!-- BELİRSİZ: Traffic Shaping (3) slaytı kareye düşmedi; altyazıda 200 Mbps hız ve "125 ms için 125 Mbps" ifadesi geçiyor, birimler doğrulanamadı. -->
- Round-robin ve WFQ ayrıntısı (ekrandan, 01:10:00 ve 01:15:00)
  - Round-robin örneğinde üç giriş kuyruğundan sırayla paket alınır; paket kutularının genişliği paket boyutunu gösterir. Üçüncü kuyruk büyük paketler gönderdiği için iki tur sonunda diğerlerinden daha fazla bit çıkarmış olur. Bant genişliği bit/s ile ölçüldüğü için bu dengesizliktir.
  - Bir çözüm bütün paketleri aynı boyuta getirmektir; bir topoloji için maksimum paket boyutu belirlenip her yerde uygulanırsa son paket dışındakiler neredeyse eşit boyutta olur.
  - WFQ'da kuyruklara işletim sistemlerindeki çok düzeyli kuyruklara benzer biçimde ağırlık verilir. Ağ katmanı paketleri sırasız iletme hakkına sahip olduğu için, aynı turda farklı kuyruklardan uzunluğu birbirine yakın paketler seçilebilir. Diğer bir yaklaşım, bekleme sürelerini paket uzunluğuna göre normalize etmektir.
  - Slayttaki WFQ örneği (ekrandan, 01:15:00), üçüncü kuyruğun ağırlığı 2:

    | Paket | Varış | Uzunluk | Bitiş | Çıkış sırası |
    |---|---|---|---|---|
    | A | 0 | 8 | 8 | 1 |
    | B | 5 | 6 | 11 | 3 |
    | C | 5 | 10 | 10 | 2 |
    | D | 8 | 9 | 20 | 7 |
    | E | 8 | 8 | 14 | 4 |
    | F | 10 | 6 | 16 | 5 |
    | G | 11 | 10 | 19 | 6 |
    | H | 20 | 8 | 28 | 8 |

  - Kuyruklar: 1. kuyrukta A, F; 2. kuyrukta B, D, H; 3. kuyrukta (W = 2) C, E, G. F, D'den sonra gelmesine rağmen önce gider; H geç gelir. Tablodaki bitiş zamanları ve sıra formülle python ile kontrol edildi ve tuttu.
- Kabul kontrolü ve IntServ ayrıntısı
  - Router'lar kendi kapasitelerini akış tanımı parametreleri cinsinden bildikleri için yeni bir isteği karşılayıp karşılayamayacaklarına kolayca karar verir. Router'daki her akış uygun bir kuyruğa eşlenir ve round-robin/WFQ mantığıyla çıkarılır.
  - RSVP örneğinde 1 ve 2 kaynak (yayıncı), 3, 4 ve 5 izleyicilerdir. Rezervasyon izleyiciden kaynağa doğru giden bir istekle yapılır; izleyici yayına bir tür abone olur. Alıcı 5 daha düşük çözünürlükte izliyorsa ve alıcı 3 daha büyük bir bant genişliği ayırmışsa, 5 numaranın isteği mevcut ayırmaya dahil edilir.
- DiffServ ayrıntısı
  - Günlük hayattan benzetme: kargo firmasında normal ve hızlı gönderim, eğlence parkında normal kuyruk ve ek ücretle hızlı geçilen kuyruk. Aciliyeti yüksek trafik için kaynak önceden ayrılır ve bu paketler sıradan trafiğin karmaşasına girmeden iletilir.
  - Servis sağlayıcılar bu mantığı kullanır: örneğin bir operatörün IPTV kutusunun bağlı olduğu port yapılandırmada etiketlenir ve bu trafik ayrı sınıfta taşınır; tabletlere özel veri hatlarının trafiği de benzer biçimde etiketlenir. Bu, DiffServ'in statik bir uygulamasıdır.
  - Slayttaki altın, gümüş, bronz sınıfları kitabın örneğidir; sınıfların adı önemli değildir, sınıflandırma mantığı önemlidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
