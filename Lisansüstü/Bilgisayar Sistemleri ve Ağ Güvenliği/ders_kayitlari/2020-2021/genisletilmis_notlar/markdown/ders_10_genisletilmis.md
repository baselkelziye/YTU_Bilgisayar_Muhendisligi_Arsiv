# Ders 10 Genişletilmiş Notu: Ağ Protokollerinin Zafiyetleri ve Servis Engelleme (DoS) Saldırıları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Ağ Protokollerinin Güvenlik Açısından Tekrarı
- 2. Servis Engelleme (Denial of Service) Saldırılarına Giriş
- 3. SYN Flood
- 4. SYN Cookies
- 5. Amplification (Güçlendirme) Saldırıları
- 6. IoT Botnet'i: Mirai
- 7. Google Project Shield ve Saldırganların Cevabı
- 8. GitHub Saldırısı
- 9. Client Puzzle
- 10. Ders Sonundaki Soru: Wi-Fi El Sıkışması ve WEP

## 1. Ağ Protokollerinin Güvenlik Açısından Tekrarı

Hoca, önceki derste internet protokollerine güvenlik açısından bir giriş yapıldığını hatırlattı. Dönem boyunca işletim sistemi, programların çalıştığı ortamlar (runtime environment) ve web için yapılan güvenlik incelemesi, şimdi de ağ protokolleri için yapılıyordu. Bu derse kalınan yerden devam edildi; ama önce temel protokoller kısaca tekrar edildi.

### 1.1 Ethernet ve ARP

Yerel ağda (LAN) ve onun ötesinde metropol ağlarda en çok kullanılan fiziksel katman ve hemen üstündeki veri bağlantı katmanı (data link layer) Ethernet'tir. Ethernet'te hostlar arasındaki haberleşme MAC adresleri üzerinden olur. Biz bir hostun IP adresini bilsek bile, ona paket gönderebilmek için o hostun Ethernet (MAC) adresini de öğrenmemiz gerekir. Bunun için Address Resolution Protocol (ARP) kullanılır.

Hoca, Ethernet'in tasarımında güvenlikle ilgili hiçbir öngörü bulunmadığını vurguladı. Gizlilik (confidentiality) yoktur. Kimlik doğrulama (authentication), yani iddia ettiğiniz host olduğunuzu belgeleme yeteneği yoktur. Bütünlük (integrity) açısından da bir özellik yoktur.

Slayttaki ARP tanımı şöyleydi (ekrandan, 00:20:00):

- ARP, hostların yerel ağda birbirinin MAC adresini bulmasını sağlar.
- İstemci tüm MAC'lere yayın (broadcast) yapar: "Which MAC address has IP 192.168.1.1?"
- Yerleşik güvenlik yoktur. Saldırgan, kimliği taklit ederek ARP isteklerine cevap verebilir ya da gratuitous ARP duyurusu gönderebilir.

ARP, TCP/IP ile birlikte ortaya çıkmış ve yalnız LAN'larda değil metropol Ethernet ağlarında da kullanılan, farklılaştırılmış biçimleriyle başka katmanlarda da karşımıza çıkan yardımcı bir protokoldür. İçinde güvenlikle ilgili bir özellik olmadığı için bir host kendini başka bir host gibi gösterebilir. Bunun iki yolu vardır:

- **İsteğe önce cevap vermek:** ARP yayına dayanır ve büyük LAN'larda yayılma (propagasyon) gecikmesi vardır. Ağın ortasına yakın konumlanmış bir saldırgan, uç noktalardaki gerçek hosttan daha hızlı cevap vererek kendini o host gibi tanıtabilir.
- **Gratuitous ARP:** "Karşı tarafa iyilik olsun diye" yapılan duyurudur. Kimse sizden ARP sorgusu yapmamıştır, ama siz sorgu yapılmış gibi "benim IP adresim bu, MAC adresim bu" diye etrafa duyurursunuz. Normalde amaç, ihtiyaç duyulduğunda haberleşmenin başındaki IP'den MAC'e dönüşüm gecikmesini en aza indirmektir. Kötü niyetli bir host ise bu duyurularla kendini pek çok farklı host gibi tanıtabilir.

### 1.2 IP

IP tarafında bütün yönlendirmenin (routing) hedef adres üzerinden yapıldığı görülmüştü. IP güvenilir değildir; elinden gelenin en iyisini yapan (best effort) bir ağ altyapısıdır. Tasarımında öngörülmüş olsa da bugünkü standart uygulamasında güvenlik özelliği yoktur.

Paketlerde bir kontrol toplamı (checksum) vardır, ama kriptografik değildir ve kolayca değiştirilebilir. Üstelik yalnız paketin başlık (header) kısmıyla ilgilidir, içerikle ilgili değildir. Yani bu toplam güvenlik için değil, paket gönderilirken başlıkta bit değişikliği olup olmadığını anlamak için vardır. Kaynak (source) adres alanı da gönderen tarafından doldurulur. Bu yüzden gönderen, kaynak adresine istediği herhangi bir değeri yazabilir. Hoca bu özelliğin dersin ilerleyen kısmında saldırıların temelinde olduğunu gösterdi.

### 1.3 BGP

Border Gateway Protocol (BGP), özellikle internet servis sağlayıcılarının kendi ağlarını duyurmak için kullandığı, ülkeler ve kıtalar arası geçişte de kullanılan protokoldür. Standart halinde (bir de Secure BGP vardır) kimlik doğrulama mekanizması ve güvenlik uygulaması yoktur. Bu, bir kurumun kendisine ait olmayan bir ağ için duyuru yapabileceği anlamına gelir.

BGP kullanıcı hatalarına da hassastır. Yapılandırmada bir maske değeri ya da adres yanlış girildiğinde yalnız kendi bölgenizde değil, çok farklı bölgelerde de yönlendirmeyi yanlış yönde etkileyebilirsiniz.

### 1.4 TCP

Slayttaki TCP özeti (ekrandan, 00:25:00):

- TCP, güvenilir olmayan IP ve Ethernet üzerinde güvenilir bir veri akışı sağlar.
- Veri segmentlere bölünür; alıcı ve gönderen alınan veriyi onaylar (acknowledge), gönderen kaybolan paketleri yeniden gönderir.
- Her TCP bağlantısı üç yönlü el sıkışmayla (three-way handshake) başlar.

Segmentler ağ tarafında paketlere bölünür. Bütün TCP haberleşmesi bağlantı (connection) mantığıyla ilerlediği için başlangıçta üç paket alışverişi gerektiren bir el sıkışma vardır.

Hoca bu noktada DNSSEC ve DNS rebinding slaytlarını bir kenara koyduğunu, önce günün konusuna geçip DNS rebinding saldırısına daha sonra döneceğini söyledi. Bu derste o konuya dönülmedi.

### 1.5 Temel önlem: TLS

Hoca, internete bağlı olduğumuz her an internetten gelebilecek her türlü saldırıya açık olduğumuzu söyledi. Korunmak için ağ ve taşıma katmanı gibi farklı katmanlarda farklı önlemler gerekir. Ama en temel şey, internet üzerinden haberleşirken mutlaka taşıma katmanı güvenliğinden (Transport Layer Security, TLS) yararlanmaktır. Web güvenliği derslerinden hatırlanacak en kolay örnekler: HTTP ile değil HTTPS ile bağlanmak ve çerezlerin çalınmaması için onları yalnız güvenli HTTP ile haberleşilirken gönderilecek şekilde ayarlamak.

> **Hocanın vurgusu:** İnternet üzerinden haberleşirken mutlaka ve mutlaka TLS'ten yararlanılmalıdır.

## 2. Servis Engelleme (Denial of Service) Saldırılarına Giriş

Hoca, "başımızı çok ağrıtan" bir başka saldırı tipine geçti: servis engelleme ya da servis kesintisi saldırıları (Denial of Service, DoS). Hedef, bir servis sağlayıcının, bir sunucunun bulunduğu siteyi, oraya yönlendirilen çok yüksek kapasiteli trafikle devre dışı bırakmaktır. Bu trafiğin içinde gerçekten servis verilmesi gereken istekler de vardır, ama site hangisinin gerçek, hangisinin saldırı isteği olduğunu anlayamadığı için düzgün servis veremez.

### 2.1 Saldırganın ekonomisi

Hocaya göre kilit noktalardan biri, saldırganın çok fazla efor harcamadan saldırıyı gerçekleştirmeye çalışmasıdır. En basit haliyle şöyle düşünülebilir: saldırgan çok basit paketler, çok basit istekler yollar, ama bu isteklerin cevapları çok büyüktür. Küçük isteklerden binlercesi, on binlercesi, yüz binlercesi yollandığında, aynı sayıda ama çok daha büyük cevaplar devre dışı bırakılmak istenen hosta yönlendirilir. Böylece:

- Saldırganın kimliği açığa çıkmaz.
- Saldırgan çok fazla efor sarf etmez.
- Saldırı, işlem gücü ve bellek kapasitesi düşük cihazlardan da yapılabilir.

### 2.2 İki temel tür: DoS Bug ve DoS Flood

Slayttaki tanımlar (ekrandan, 00:30:00):

- **DoS Bug:** Tek bir makinenin bir servisi bozmasına izin veren tasarım hatası. Genellikle bir protokol asimetrisidir; örneğin istek göndermek kolay, cevap üretmek zordur. Ya da sunucuda durum (state) tutmayı gerektirir.
- **DoS Flood:** Kontrol ettiğiniz makinelerden oluşan bir botnet'ten çok sayıda istek göndermek.

DoS Bug'da karşı tarafta servis veren uygulamada tasarımla ilgili bir sıkıntı vardır ve saldırgan gönderdiği istekle bu sıkıntıyı tetikler. Sonuçta ya karşı taraf çalışamaz hale gelir ya da isteğe karşılık çok fazla işlem gücü harcaması, çok büyük bir ağ cevabı üretmesi gerekir. Burada sözü edilen protokoller genelde üst seviye uygulama protokolleridir ve sorun çoğunlukla bu protokollerdeki asimetriden kaynaklanır: istekler küçük, cevaplar büyüktür.

DoS Flood ise dersin başlarında da uzun uzun konuşulan durumdur: bir botnet üzerinden hedef siteye ardı arkası kesilmeyen istekler göndermek, oraya çok ciddi bir ağ trafiği yöneltmek.

### 2.3 DoS her katmanda yapılabilir

- **Bağlantı katmanı (link layer):** Hoca bu kısmın ağ katmanını da kapsadığını söyledi. Switch ve router'lar aşırı trafikle devre dışı bırakılabilir.
- **Taşıma katmanı:** TCP ve UDP; TCP bu konuda daha hassastır. Her şey bağlantı üzerinden ilerlediği için bağlantıların durumu yönetilemez hale getirilebilir. Her hostun aynı anda yönetebileceği bağlantı sayısında bir sınır vardır; bunun üstünde bağlantı açması ve yönetmesi istenirse devre dışı kalır.
- **Uygulama katmanı:** Sunucuların işlem gücü, bellek ya da ağ kapasitesi açısından çok pahalı sorgular yapması ya da kriptografik işlemler gerçekleştirmesi tetiklenebilir.

## 3. SYN Flood

### 3.1 Normal el sıkışma

Hoca en basit örnek olarak TCP'nin üç yönlü el sıkışmasını aldı. Önce istemciden sunucuya SYN gelir. Sunucu istemciye SYN/ACK yollar, istemci de ACK yollar. Sunucu başlangıçta dinleme (listening) konumundadır. Bir istemciden istek geldiğinde, isteğin içindeki istemci sıra numarasını ve kendi SYN/ACK paketinde yolladığı sıra numarasını kenarda saklar. Bunun nedeni, belirli bir süre içinde istemciden bu değerlere uygun bir onay (ACK) gelip gelmediğini anlayabilmektir. Cevap bu süre içinde gelirse bağlantı kurulmuş olur.

### 3.2 Saldırı

Slayttaki şemada (ekrandan, 00:35:00) tek bir istemci makineden (C) sunucuya (S) arka arkaya $SYN_{C1}$, $SYN_{C2}$, ..., $SYN_{C5}$ paketleri gidiyordu ve sunucu tarafındaki kuyruk her pakette büyüyordu. Slayttaki maddeler:

- Tek makine yeter (single machine).
- Rastgele kaynak IP adresli SYN paketleri gönderilir.
- Sunucudaki backlog kuyruğu dolar.
- Artık yeni bağlantı mümkün olmaz.

Kaynak IP adresleri rastgele seçilmiştir; zaten kaynak adresi istediğimiz gibi yazabildiğimizi biliyoruz. Sunucu tarafında kaydedilmiş, cevabı yollanmış ve üçüncü paketin gelmesi beklenen bir sürü kayıt birikir. Bağlantının başlatılabilmesi için üçüncü paketin beklendiği bu kayıtlara **backlog** denir.

Backlog doğal olarak bellekte sınırlı bir alandır. Hoca şu örneği verdi: sunucu, en fazla 1.000 açıkta duran, henüz tamamlanmamış bağlantı isteğiyle uğraşabilecek şekilde yapılandırılmış olsun. Bu durumda 1.001. istek geldiğinde sunucu cevap veremez, 1.002.'ye ve 1.003.'e de veremez. Böylece gelen gerçek isteklere de cevap veremez hale gelir. Bir sunucuyu arka arkaya gelen senkronizasyon (SYN) istekleriyle boğan bu saldırıya **SYN flood** denir. Sorun, sunucunun kaynaklarını, özellikle belleği tüketmektir; aynı anda kaç backlog kaydı olabileceği bir yapılandırma parametresidir.

### 3.3 Kötü çözümler

Hoca, zamanında uygulanmış ve uygulanabilecek en kötü iki çözümü anlattı:

- **Backlog kuyruk boyutunu artırmak:** Siz 10.000 yaparsanız karşı taraf 10.000 tane yollar; 100.000 yaparsanız 100.000 tane yollar.
- **Zaman aşımını azaltmak (decrease timeout):** Kaydın backlog'da ne kadar bekleyeceğini kısaltarak kayıtların bir an önce serbest kalması sağlanır. Ama bu durumda bağlantı kurabilmek için uzun zaman aşımına ihtiyaç duyan gerçek istemcilerle bağlantı kurulamaz.

Yapılması gereken, üç mesaj alışverişi tamamlanmadan sunucu tarafında bağlantıyla ilgili bilgi tutulmasının önüne geçmektir.

## 4. SYN Cookies

Bağlantı kurulana kadar sunucuda durum bilgisi tutulmayacaksa, bunun için sistematik bir çözüm gerekir. Bu çözümün adı **SYN cookie**'dir. Durum bilgisi sunucuda değil istemcide tutulur.

Önemli olan şudur: sunucunun istemciye gönderdiği bilgiyi gerçek istemci geri gönderecektir; saldıran "istemci" göndermeyecektir, çünkü kullanılan adresler tamamen rastgeledir ve o adreslerdeki makineler aslında hiç istek göndermemiştir. Gerçek istemci bilgiyi geri gönderdiğinde, sunucu o bilginin gerçekten kendisi tarafından gönderildiğini kontrol edebilmelidir. Bu da ancak kriptografik bir bilgi gönderilerek yapılabilir.

### 4.1 Cookie'nin yapısı

Slayttaki tanımlar (ekrandan, 00:40:00):

- **Fikir:** $SN_C$ ve $SN_S$'yi saklamak yerine istemciye bir cookie geri gönder.
- $L = MAC_{key}(SAddr, SPort, DAddr, DPort, SN_C, T)$
- key: açılış (boot) sırasında rastgele seçilir.
- $T$ = her 64 saniyede bir artırılan 5 bitlik sayaç.
- $SN_S = (T \,\|\, mss \,\|\, L)$
- Dürüst istemci $AN = SN_S$, $SN = SN_C + 1$ ile ACK gönderir. Sunucu soket için yeri yalnız $SN_S$ geçerliyse ayırır.
- Sunucu durum saklamaz (TCP seçeneklerini kaybeder).

Slaytın sağındaki şema normal el sıkışmayı gösteriyordu: SYN'de $SN_C \leftarrow rand_C$, $AN_C \leftarrow 0$; SYN/ACK'te $SN_S \leftarrow rand_S$, $AN_S \leftarrow SN_C$; sunucu bu noktada $SN_C$ ve $SN_S$'yi saklar ve bekler; ACK'te $SN \leftarrow SN_C$, $AN \leftarrow SN_S$ gelince bağlantı kurulur (established). SYN cookie bu "sakla" adımını kaldırır.

Hoca cookie'yi üç parça olarak anlattı: $L$ parçası, $T$ parçası ve maximum segment size'dan (MSS) elde edilen mss parçası. $L$, altı değerden oluşturulan bir mesaj doğrulama kodudur (Message Authentication Code, MAC): kaynak adres, kaynak port, hedef adres, hedef port, istemcinin sıra numarası ve $T$.

MAC'i oluştururken bir anahtar gerekir. Hocanın deyişiyle işin güzel tarafı, istemcinin bu anahtara ihtiyacı yoktur. İstemci sunucunun gönderdiği veriyi açmayacak, aynen geri gönderecektir. Bu yüzden anahtarı yalnız sunucunun bilmesi yeterlidir. Sunucu altı değeri alır, kendi seçtiği anahtarla güvenli bir MAC değeri üretir ve bunu $T$ değeriyle birlikte karşı tarafa, kendi sıra numarası olarak gönderir.

$T$'nin açık olarak gönderilmesinin önemi şudur: sunucu geri gelen değeri doğrularken MAC'i yeniden hesaplamak için anahtara ihtiyaç duyar; ayrıca değerin istemcinin gerçek isteğine göre oluşturulduğunu kontrol etmek için ek bir bilgiye, $T$'ye de ihtiyaç duyar. Bu birleşik değer sunucunun sıra numarası $SN_S$'dir.

Haberleşmek isteyen gerçek istemci, onay numarası (acknowledgement number, AN) alanında $SN_S$'yi gönderir ve kendi sıra numarasını bir artırır. Böylece sunucuya bin, on bin ya da yüz bin istek gelsin, sunucuda hiçbir durum bilgisi tutulmaz; durum bilgisi tamamen istemcilerdedir.

> **Ek bilgi (derste anlatılmadı):** $T$ 5 bitlik olduğu için 32 farklı değer alır ve her 64 saniyede bir arttığından sayaç büyük olasılıkla $32 \times 64 = 2048$ saniyede (yaklaşık 34 dakika) başa döner. Sunucu, ACK'teki $T$'nin güncel değere yakın olup olmadığına bakarak çok eski cookie'leri reddedebilir. "TCP seçeneklerini kaybeder" notu, sunucunun SYN'deki seçenekleri saklamamasından kaynaklanır; mss yalnız birkaç bitle kodlanabildiği için cookie'ye sığar.

### 4.2 Bedeli ve eşik mantığı

Bu yöntem güzeldir ama MAC hesabı nedeniyle sunucuya ek işlem yükü getirir, çünkü kriptografik işlemler vardır. Bu yüzden SYN cookie bazı durumlarda çalışma boyunca varsayılan olarak açık tutulurken, bazı durumlarda yalnız backlog'da bekleyen, cevabı gelmemiş bağlantı sayısı belirli bir eşik değerini aşınca devreye sokulur. Sayı ikinci bir eşik değerinin altına inince devre dışı bırakılır. Amaç, sunucuda da gereksiz yere işlem gücü kaybetmemektir.

## 5. Amplification (Güçlendirme) Saldırıları

Yine DoS başlığı altında bir başka saldırı tipi güçlendirme saldırılarıdır (amplification attacks). Güçlendirilen şey şudur: saldırgan çok basit bir istek gönderir, karşılığında çok büyük bir cevap üretilir.

### 5.1 Open DNS Resolver

Hoca, internette en çok karşılaşılan sıkıntılardan birinin açık DNS çözücüler (Open DNS Resolver) olduğunu söyledi: her kullanıcıdan gelen sorguya cevap veren DNS sunucuları. Normalde bir DNS sunucusu yalnız bulunduğu alandaki (domain) istemcilerin isteklerine cevap verecek şekilde yapılandırılmalıdır. Yapılandırmada özel bir önlem alınmamışsa ve internetteki herhangi birinden gelen isteğe cevap veriyorsa, ona açık resolver denir.

İnternette bunlardan çok vardır. Hoca uzağa gitmeye gerek olmadığını, Google'ın 8.8.8.8 adresinin de açık resolver olduğunu söyledi: dünyadaki herhangi bir kullanıcı DNS sunucu adresi olarak bu değeri verebilir. Hocaya göre aslında "DNS servis sağlayıcılığı" diye bir şey yoktur; DNS sunucusu ya da resolver, bulunduğu kurumdan gelen isteklere cevap vermelidir.

### 5.2 Saldırının işleyişi

Slayttaki şema (ekrandan, 00:45:00; görsel kaynağı Cloudflare): saldırgan (Attacker) bir bota komut verir. Bot, üç açık DNS resolver'a "DNS ANY example.com." sorgusunu sahte kaynak adresli (spoofed request) olarak gönderir. Resolver'lar birçok MX ve A kaydından oluşan büyük cevaplarını (large response) hedef kurbana (Target Victim) yollar. Şemanın altında "60-70x Increase in Size" yazıyordu.

Saldırgan kontrolündeki botları kullanarak DNS sorguları göndertir; botların her biri farklı resolver'lar kullanır. DNS sorgularındaki kaynak adres saldırılacak kurbanın adresidir, bu yüzden bütün resolver'lar cevaplarını kurbana gönderir. Hoca şöyle örnekledi: 30-40 baytlık bir sorgu yapılmış, karşılığında 3-4 KB'lık bir cevap oluşmuş ve bunlardan on binlerce, yüz binlerce gelmektedir. Slayta göre cevap içerik olarak sorgudan 60-70 kat büyük olabilir. Saldırıya bu yüzden güçlendirme (kuvvetlendirme) saldırısı denir.

### 5.3 Güçlendiriciler

- **UDP:** Güçlendirmeye çok daha uygundur; DNS servisi de UDP üzerinden yürür.
- **DNS ANY sorgusu:** Bir alan adıyla ilgili bütün kayıtları döndürür. O alana ait ne kadar kayıt varsa hepsi döndüğü için en tehlikeli güçlendiricilerden biridir.
- **NTP (Network Time Protocol):** İnternet üzerinde zaman senkronizasyonu sağlar. İçindeki monlist komutu, zamanı sorgulayan son 600'e kadar istemcinin listesini döndürür.

Güçlendirmenin işe yaraması için cevabın tek parça halinde gönderilebilmesi gerekir; parçalara bölünüyorsa pek anlamı kalmaz. Hocaya göre gözlemler, çoğu yapılandırmanın cevabın tek parça döndürülmesine izin verdiği yönündedir.

### 5.4 Gerçek saldırılar

Slayttaki rakamlar (ekrandan, 00:50:00):

- 2013: DNS üzerinden 300 Gbps üreten DDoS saldırısı.
  - 31.000 yanlış yapılandırılmış açık resolver, her biri 10 Mbps.
  - Kaynak: IP sahteciliğine (spoofing) izin veren 3 ağ.
- 2014: 4.500 NTP sunucusu kullanan 400 Gbps DDoS saldırısı.

Hoca 2013 rakamlarının yuvarlatılmış olduğunu belirtti. Hesap şöyle tutar: $31.000 \times 10\ \text{Mbps} = 310.000\ \text{Mbps} = 310\ \text{Gbps} \approx 300\ \text{Gbps}$. Hocanın dikkat çektiği karşılaştırma: 300 Gbps için 31.000 resolver gerekmişken, bir yıl sonra 400 Gbps için yalnız 4.500 NTP sunucusu yetti. Nedeni, NTP'den dönen cevabın gelen isteğe göre çok daha büyük olmasıdır.

### 5.5 Memcached saldırısı

Hoca "çok da eski değil" diyerek Mart 2018'deki memcached saldırısına geçti. Memcached, aynı web sayfasının sunucu tarafından dosya sisteminden tekrar tekrar okunup gönderilmesini engellemek ve sayfaları hızlı oluşturmak için geliştirilmiş, sonra standart haline gelmiş bir önbellek teknolojisidir. Çok basit bir istek gönderilir, örneğin bir URL'deki bir içerik (bir PDF) istenir; isteğe göre 50 bin kat daha büyük veriyle cevap verilebilir. Memcached'den sürekli bir şey dışarı çıkar, sürekli cevap vermesi gerekir; bu da inanılmaz bir bant genişliği ihtiyacı doğurur.

Hoca ardından gelen slaytta devre dışı kalan yerleri saydı: Twitter, Spotify, Amazon, GitHub, PayPal, Reddit, Netflix, New York Times, SoundCloud. Sonraki şemada solda botnet'ten gelen kötü niyetli indirme istekleri (kırmızı) ve büyük dosya indirmeleri (mavi), sağda da gerçekten servis almak isteyen kullanıcılar vardı. Yaklaşık 100.000 kötü niyetli uç noktadan istek geldiği, 1,2 Tbps'lik trafik oluştuğu iddia edilmişti. Hoca, 2013-2014'teki 300-400 Gbps'den 2016'da terabitlere çıkılmasının internetin boyutu ve hızları düşünüldüğünde normal olduğunu söyledi.

<!-- BELİRSİZ: Bu slaytların kareleri yok (00:52:13-00:53:52). Hoca site listesini memcached başlığı altında söylüyor ama 2016 yılını ve 1,2 Tbps / yaklaşık 100.000 uç nokta rakamlarını veriyor; bu rakamlar ve kesilen site listesi büyük olasılıkla Ekim 2016'daki Mirai botnet'inin Dyn saldırısına aittir, memcached saldırısına değil. -->

## 6. IoT Botnet'i: Mirai

### 6.1 Botnet'in yapısı

Hoca bunun çok özel bir saldırı tipi olduğunu söyledi. Buraya kadar botnet'lerde hep standart bilgisayarlar kullanılmıştı; bu saldırıda ise IoT cihazları kullanıldı: Wi-Fi router'lar, switch'ler, kameralar, set üstü kutular, IP telefonlar ve yapılandırma için web arayüzü ya da komut satırı arayüzü olan, internete bağlı her türlü cihaz.

Slayttaki şema (ekrandan, 00:55:00): solda "Bot Master", ortada yazıcı, router, kameralar, DVR'ler, IP telefon, set üstü kutu gibi cihazlar, bunlardan GRE, HTTP ve TLS trafiği hedeflere (OVH/Dyn/Krebs) gidiyor. Altta "≈ 200K Hosts" üstü çizilip "200K IoT devices" yazılmıştı. Slaytın altındaki not: "Not Amplification. Flood with SYN, ACK, UDP, and GRE packets."

Hoca bunun önemli olduğunu vurguladı: burada güçlendirme yapılmaz, taşkın (flooding) yapılır. Çünkü bu cihazların bir sorguya daha büyük bir paketle cevap verebilecekleri pek özellikleri yoktur, ama sürekli trafik üretmek için kullanılabilirler: SYN, ACK, UDP ya da yönlendirme paketleri, GRE paketleri.

### 6.2 İşleyiş

Mirai kötü amaçlı yazılımının saldırı komutları şunları içerir: başlat/durdur, saldırılacak IP'ler, saldırı tipi (GRE paketiyle mi, DNS ile mi, TCP ile mi flood edileceği) ve saldırının süresi. Hocaya göre çok planlanmış bir yapıdır. Adımlar:

- Önce tarama yapılır: etrafta hangi cihazlar var, bu cihazların özellikleri nedir diye bir veritabanı oluşturulur (rapor aşaması). Buna göre hangi cihaza nasıl bir saldırı yapılırsa kontrolünün ele geçeceği belirlenir.
- Loader üzerinden cihaza saldırı gerçekleştirilir. Cihaz ele geçerse Mirai botnet'inin bir parçası haline gelir.
- Saldırgan komutu yollar. Komuttan sonra saldırganın yapacağı pek bir şey yoktur: "start" komutu gönderilen cihazlar, önceden öğrendikleri hedef IP'ye, önceden bildikleri yöntemle saldırıyı başlatır.

<!-- BELİRSİZ: Mirai işleyiş şemasının karesi yok (00:56:02-00:57:33); adım numaraları (hocanın "5, 6, 7" dediği adımlar) slayttan doğrulanamadı. -->

### 6.3 Parola tahmini

Cihazlar nasıl ele geçiriliyor sorusuna hoca, saldırganların çok ciddi bir veritabanı olduğunu söyleyerek cevap verdi. Slaytta "Password Guessing" başlıklı bir tablo vardı (ekrandan, 01:00:00): farklı marka ve cihaz tiplerine göre (IP kamera, DVR, yazıcı, router, VoIP telefon, TV alıcısı vb.) üreticilerin kullandığı fabrika çıkışı varsayılan parolalar. Tablodaki değerlerin çoğu çok kısa ve tekrarlı rakam dizileri, "admin", "root", "default", "guest", "password", "support", "user" gibi yaygın kelimeler ya da marka adından türetilmiş dizilerdi; bir cihaz tipinde hiç parola yoktu. Tablonun bir kısmındaki cihaz tipi bilinmiyordu ("Unknown").

Hoca, kenardaki bir yazıcı parolasının "1234 ya da 123456 bile değil", aynı rakamın dört kez tekrarı olduğunu, bazı DVR'lerde de altı aynı rakamın kullanıldığını örnek verdi. Bunlar üreticilerin ürünü piyasaya sürerken verdiği ve doğal olarak internette herkese açık belgelerinde de yer alan değerlerdir. Sorun, kullanıcıların bunları değiştirmeyi düşünmemesidir: "nasıl olsa parola var", "nasıl olsa yalnız iç ağdan erişiliyor" diye düşünülür. Hoca, önceki haftalarda iç ağdaki bir cihaza dışarıdan nasıl erişilebileceğini ve kontrolünün nasıl ele geçirilebileceğini anlattığını hatırlattı. Bu durumda parolaları böyle bırakmak ciddi baş ağrısına yol açar. Hoca bu listenin çok basit bir örnek olduğunu, gerçekte uzayıp gittiğini söyledi.

Saldırıda ele geçen cihaz sayısı yaklaşık 600 bin olarak verildi. Hocaya göre bu çok önemli bir değerdir, çünkü bu cihazların hiçbirinin güvenlik açısından düzgün yapılandırılmadığını gösterir.

<!-- BELİRSİZ: Slaytta 200K IoT cihazı yazıyor (00:55:00), hoca ise 01:00:11'de yaklaşık 600 bin diyor; 600 bin büyük olasılıkla Mirai'nin toplamda ele geçirdiği cihaz sayısının tepe değeridir, ilgili slayt karelerde yok. -->

### 6.4 Port değiştirmek yetmez

Slaytın sağ tarafında Mirai'nin denediği TCP portları vardı: 23231, 22, 2222, 443, 5555, 6789, 8080 gibi. Hoca, bazı üreticilerin "22 çok bariz, değiştireyim" diye farklı port seçtiğini, ama bunun pek bir şey değiştirmediğini söyledi. Üreticiler internete yayımladıkları kullanım kılavuzlarında hangi porttan erişileceğini belirtir, çünkü ürünü satın alan kullanıcının cihaza erişebilmesi gerekir. Çevrimiçi kılavuza iyi niyetli kullanıcı da kötü niyetli kullanıcı da bakabilir. Hocaya göre burada önemli olan, iyi bir veri madenciliği ile bu bilgilerin toplanıp saldırıya uygun hale getirilmesidir.

<!-- BELİRSİZ: Port listesi yalnız altyazıdan (01:00:36-01:00:49); slaytın bu kısmı karelerde yok. -->

### 6.5 Krebs saldırısı

Hoca ardından meşhur güvenlik bloğuna yapılan saldırıyı gösterdi. Slayttaki grafikte değerler 600 Gbps'yi geçiyordu. Slayttaki metne göre son haftada görülen saldırıların büyüklüğü, Akamai'nin düzenli olarak gördüğü saldırıların çoğundan belirgin biçimde büyüktü. Site Akamai'de barındırılıyordu ve Akamai'ye sürekli saldırı yapıldığı için bu karşılaştırma anlamlıydı. 20 Eylül'deki saldırı Akamai'nin o güne kadar savuşturduğu en büyük saldırıydı; 22 Eylül'deki saldırı da başka herhangi bir zamanda rekor sayılacak büyüklükteydi ve 555 Gbps tepe değerine ulaştı. Grafikte 600 diye çizilmişti ama değer 555 Gbps idi. Hoca, normalde görülen 200 civarı değerle karşılaştırıldığında bunun yaklaşık üç kat olduğunu söyledi ($555 / 200 \approx 2{,}8$).

Hoca, bunun yalnız tek bir siteye yapılan saldırı olduğunu, çok büyük bir internet servis sağlayıcısına yapılan saldırının boyutunun düşünülmesi gerektiğini söyledi. Blog sahibi Brian Krebs güvenlikle ilgili yazıyordu ve bu saldırının arkasındaki projenin detaylarını, nasıl çalıştığını açıklıyordu. Saldırı, bu içeriğin karartılması, ona erişilmesinin engellenmesi için yapılmıştı. Bunun üzerine Krebs blogunu Google'a taşıdı.

## 7. Google Project Shield ve Saldırganların Cevabı

### 7.1 Project Shield

Slayttaki metin (ekrandan, 01:05:00): DDoS saldırıları sıklıkla içeriği sansürlemek için kullanılır; Mirai örneğinde Brian Krebs'in blogu saldırı altındaydı. Google Project Shield, Google'ın bant genişliğini savunmasız web sitelerini (haber, blog, insan hakları kuruluşları gibi) korumak için kullanır.

Şemada solda bot makineler "Lots-of-SYNs" gönderiyor, ortadaki "Project Shield Proxy" bunlara "Lots-of-SYN/ACKs" ile cevap veriyor, botlardan yalnız "Few ACKs" geliyor ve proxy yalnız bunları web sitesine iletiyor (forward to site).

Hoca bunu şöyle anlattı: ön tarafta, kötü niyetli istekleri durduran ve gerçek web sitesine yönlendirmeyen bir kalkan oluşturduğunuzu düşünün. SYN geldi, siz SYN/ACK gönderdiniz ama üçüncü paket (ACK) gelmedi; o zaman bunu arka tarafa iletmeye gerek yoktur, ön tarafta durdurursunuz. ACK gelirse bu gerçek bir istemcidir, siteye erişmek istemektedir ve isteği siteye iletirsiniz.

Bunu yapabilmek için fiziksel ağ bant genişliğinizin çok yüksek olması gerekir. ACK'i olmayan istekler zaten bant genişliğinizi dolduruyorsa onları filtreleme şansınız bile yoktur, çünkü normal trafik size ulaşamaz. Google'ın bunu yapabilmesinin sebebi çok yüksek kapasiteli internet bağlantısına sahip olmasıdır.

### 7.2 Saldırganların cevabı

Saldırganlar, SYN/SYN-ACK sonrasında ACK'i gelmeyen bağlantıların proxy'de durdurulduğunu fark edince şunu yaptılar: "Nasıl olsa elimizde botlar var, gerçek adreslerden saldıralım." Botların kendi adresleriyle bağlantı kurulur, yani "few ACKs" kısmı geçilir ve istek siteye ulaşır. Sitede TLS güvenli el sıkışması da yapılır; hiçbir sorun yoktur. Ama ondan sonra sitedeki olabildiğince büyük bir resim ya da içerik için GET isteği yapılır.

Hoca, pek çok sitenin reklam ya da tanıtım amacıyla ana sayfalarının en görünür yerine megabaytlarca PDF, video, animasyon koyduğunu söyledi. Siz onu istemek için diyelim ki 30 bayt harcıyorsunuz, karşılığında 10 MB indirme oluyor. Bunun gibi yüzlerce, binlerce, on binlerce istek olduğunu düşünün: sitenizden dışarı binlerce kez 10 MB çıkacaktır. Zaten çıkamayacaktır, ağınız tamamen dolmuş olacaktır. Bu örnekte istek ile cevap arasındaki oran $10 \times 10^6 / 30 \approx 333.000$ kattır (ara adım eklendi).

Ancak bu saldırıda artık rastgele IP'ler kullanılamaz, çünkü üçüncü paketin (ACK) gelmesi gerekir. IP'ler bilindiği için bunlara trafik ya da hız sınırlaması (rate limiting) uygulanabilir; kurban site botları engelleyebilir ya da hızlarını sınırlayabilir.

## 8. GitHub Saldırısı

Slayttaki metin (ekrandan, 01:10:00): GitHub'a karşı 1,35 Tbps'lik saldırı, HTTP web isteklerine enjekte edilen JavaScript ile yapıldı. Saldırının arkasında Çin hükümetinin olduğundan yaygın olarak şüphelenildi.

Şema "Javascript-based DDoS" başlığını taşıyordu: dürüst son kullanıcı (honest end user) bir sunucuya istek yapıyor, cevap yoldayken araya bir saldırgan "imageFlood.js" enjekte ediyor ve kullanıcının tarayıcısı github.com'a yoğun istek gönderiyor.

Hoca bunu şöyle açıkladı: sayfalarda sağda solda reklamlar gibi içerikler vardır ve bunlar sayfayı yüklediğinizde size gelir. Düzgün biçimde bir siteye erişmek isteyen kullanıcıya içerik gelir; o içerik kötü niyetli sunucuya istek yapar ve o da imageFlood.js'i enjekte eder. Böylece inanılmaz bir trafik oluşur. Hoca, o dönemde Çin hükümetinin bunu yaptığı yönünde çok spekülasyon olduğunu, ama ortaya bir şey çıkmadığını; hangi hükümet olduğunun da önemli olmadığını söyledi.

> **Hocanın vurgusu:** Bu saldırı, web güvenliğinde incelenen belirli kurallar uygulanmadığında çok basit biçimde gerçekleşebilir. Okuyunca "bu da atlanır mı" denecek kadar basit şeylerdir, ama bir tanesi bile atlanırsa sonuç çok ağır olabilir.

> **Ders sonrası not:** GitHub'a yönelik JavaScript enjeksiyonlu DDoS büyük olasılıkla 2015'teki "Great Cannon" saldırısıdır. 1,35 Tbps değeri ise büyük olasılıkla GitHub'ın Şubat 2018'de memcached güçlendirmesiyle aldığı saldırıya aittir. Slayt iki olayı tek maddede birleştiriyor görünmektedir.

## 9. Client Puzzle

Slayttaki "Victim site can block or rate limit bots" maddesine dönen hoca, gelen istekleri yavaşlatmak için kullanılan yöntemlerden birinin istemci bulmacası (client puzzle) olduğunu söyledi. Varsayım, istemcilerin daha düşük işlem gücüne ve belleğe sahip olduğudur. Her bağlantı için istemciye basit bir bulmaca, yani işlem gücü gerektiren bir hesaplama gönderilir.

Hocanın anlattığı örnek şöyleydi: bulmacanın istemcide hesaplanması $2^n$ işlem gerektirir ve 1 GHz'lik bir çekirdekte yaklaşık 0,3 saniye (300 ms) sürer. Sunucu bir $C$ değeri gönderir, istemci bir $X$ değeri geri gönderir. $C$ ile $X$ birleştirilip SHA-1 özeti alınır ve özetin en anlamsız (least significant) $n$ biti üzerinden kontrol yapılır.

<!-- BELİRSİZ: Bulmaca slaytı karelerde yok (01:10:52-01:12:11). Altyazıda "C ile X'in orlanması" ve "bitlerinin en tane bitini gönderecek" geçiyor. Stanford CS155 slaytında büyük olasılıkla "X'i, LSB_n(SHA-1(C || X)) = 0^n olacak şekilde bul" yazıyordu; burada || birleştirmedir, "or" değildir. 0,3 saniyenin hangi n değeri için verildiği altyazıdan anlaşılmıyor. -->

Bunun anlamı şudur: istemci arka arkaya isteklerini en hızlı 300 ms aralıklarla yapabilir, çünkü her istekte $C$ değeri değişir. Sunucu tarafında ise cevabı doğrulamak çok kolaydır: tek bir SHA-1 hesabı yapılır. Hocanın deyişiyle bu sunucu için "yükü yok gibi bir şeydir", ama istemcide gigahertz'lik bir işlemcide bile 300 ms sürer. Böylece istemci yavaşlatılmış olur.

Slayttaki değerlendirme (ekrandan, 01:15:00):

- Gerçek dünyada sık kullanılmaz.
- **Yarar:** $n$, saldırı trafiğinin miktarına göre değiştirilebilir.
- **Sınırlamalar:** Protokollerde, istemcilerde ve sunucularda değişiklik gerektirir. Saldırı sırasında düşük güçlü meşru istemcilere (örneğin telefonlar) zarar verir.

Hoca sınırlamaları açtı. Birincisi, hem istemci hem sunucu tarafında protokol değişikliği gerekir; bu parasal, zamansal ve iş gücü açısından bir maliyettir. İkincisi, kötü niyeti olmayan düşük güçlü cihazlara zarar verir. Örneğin pili ve mesaj gönderme sıklığı hesaplanarak bir yıl tek başına çalışacağı öngörülen bir cihaz, bu kriptografik hesap yüzünden üç-beş ayda pilini bitirebilir. Bugünkü bütün telefonlar için olmasa da çoğu telefon için bu hâlâ geçerlidir: telefonlar sürekli web sayfalarına ve web servislerine erişir, her şey web protokolleri üzerinden yürür ve her TCP bağlantısı için sürekli bir bulmaca çözmek işlem gücü harcar.

> **Ek bilgi (derste anlatılmadı):** Özetin son $n$ bitinin sıfır olmasını sağlayan bir $X$ bulmanın bilinen tek yolu deneme yanılmadır; bir deneme başarılı olma olasılığı $2^{-n}$ olduğundan ortalama $2^n$ deneme gerekir. $n$'yi bir artırmak istemcinin işini iki katına çıkarır, sunucunun doğrulama işi ise tek bir özet hesabı olarak kalır. Bu yüzden zorluk saldırı yoğunluğuna göre ayarlanabilir.

## 10. Ders Sonundaki Soru: Wi-Fi El Sıkışması ve WEP

Ders bitince bir öğrenci, el sıkışma paketlerini toplayıp ARP spoofing yaparak Wi-Fi parolalarının bulunmasıyla ilgili bir soru sordu.

**Soru:** Wi-Fi'da el sıkışma paketleri toplanarak ve ARP spoofing yapılarak parolalar nasıl bulunuyor; bunun altyapısı nedir?

**Cevap:** Hoca, Wi-Fi tarafındaki el sıkışmanın derste konuşulandan farklı olduğunu söyledi; derste konuşulan TCP bağlantısı kurulurken yapılan el sıkışmasıdır. Kablosuz ağda önce istemcinin erişim noktasıyla ilişkilendirilmesi (association) vardır. Kablolu bağlantıda istemci, kabloyu taktığı anda Ethernet switch ya da hub ile doğrudan konuşmaya başlar. Kablosuzda ise istemcinin erişim noktasıyla ilişkilendirilebilmesi için ağ katmanında değil, veri bağlantı katmanının içindeki ortam erişim denetimi (Medium Access Control, MAC) katmanında mesajlar gidip gelir. Normalde her istemci her erişim noktasına bağlanabilmelidir ve ilk ilişkilendirme şifresiz olmak zorundadır: şifreli haberleşmeye geçebilmek için önce temel bir haberleşme (bağlantı değil, çerçeve alışverişi) açılmalıdır. Sonra aradaki şifreleme protokolüne göre şifreli haberleşme başlar. O dönemde çok yaygın kullanılan protokol WEP idi ve bu protokolün kullandığı şifreleme yapısından kaynaklanan bir zafiyeti vardı. Hoca, zamanında hazır açık kaynak araçlarla bir erişim noktasının WEP anahtarının normal işlemci gücüyle 15-20 dakikada ele geçirilebildiğini denediklerini söyledi. Bu durumda WEP kullanmak ile şifreleme yapmamak arasında büyük bir fark kalmıyordu.

**Soru:** WEP RC4 kullanıyor, değil mi? Bu kırılma kaba kuvvet (brute force) saldırısı mı, yoksa RC4'teki bir zafiyetten mi kaynaklanıyor?

**Cevap:** WEP RC4 üzerine oturtulmuştur. Saldırı kaba kuvvet değildir, RC4'ün yapısındaki zafiyeti kullanır; bu kadar kısa sürmesinin sebebi de budur.

> **Ders sonrası not:** Hoca WEP'i "Wireless Encryption Protocol" diye açtı; standarttaki adı Wired Equivalent Privacy'dir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:47:17): DNS güçlendirme saldırısında botların açık resolver'lara gönderdiği DNS sorgularındaki kaynak adres nedir ve neden?

> **Çözüm (derste verildi):** Kaynak adres saldırılacak kurbanın adresidir. IP'de kaynak adresi gönderen yazdığı için bot sahte (spoofed) adres koyar; resolver'lar büyük cevaplarını bu adrese, yani kurbana gönderir.

**Soru 2** (derste sözlü, 00:43:07; ekrandan, 00:40:00): SYN cookie kullanan bir sunucuya bağlanmak isteyen dürüst istemci, üçüncü pakette (ACK) onay numarası ve sıra numarası olarak ne gönderir?

> **Çözüm (derste verildi):** Onay numarası olarak sunucunun gönderdiği $SN_S = (T \,\|\, mss \,\|\, L)$ değerini ($AN = SN_S$), sıra numarası olarak kendi sıra numarasının bir fazlasını ($SN = SN_C + 1$) gönderir. Sunucu $L$'yi anahtarıyla yeniden hesaplar; değer geçerliyse soket için yer ayırır.

**Soru 3** (ekrandan, 00:50:00): 2013'teki DNS saldırısında 31.000 açık resolver her biri 10 Mbps ile kullanıldı. Üretilen toplam trafik yaklaşık ne kadardır?

> **Çözüm (derste verildi):** $31.000 \times 10\ \text{Mbps} = 310\ \text{Gbps}$; slaytta yuvarlatılmış olarak 300 Gbps verilmiştir.

**Soru 4** (derste sözlü, 00:35:45): SYN flood'a karşı backlog kuyruğunu büyütmek ya da zaman aşımını kısaltmak neden iyi çözüm değildir?

> **Çözüm (derste verildi):** Kuyruğu büyütmek saldırganın daha çok paket göndermesiyle boşa çıkar (10.000'e 10.000, 100.000'e 100.000). Zaman aşımını kısaltmak, bağlantı kurmak için uzun süreye ihtiyaç duyan gerçek istemcilerin bağlanamamasına yol açar. Doğru yol, el sıkışma tamamlanmadan sunucuda durum tutmamaktır (SYN cookie).

**Soru 5** (derste sözlü, 01:18:43): WEP'in kısa sürede kırılması kaba kuvvet saldırısı mıdır?

> **Çözüm (derste verildi):** Hayır. WEP'in üzerine kurulduğu RC4'teki yapısal zafiyet kullanılır; bu yüzden anahtar normal işlemcilerle 15-20 dakikada ele geçirilebiliyordu.

## Dersin Toparlaması

Ders, Ethernet, ARP, IP, BGP ve TCP'nin güvenlik eksiklerinin kısa bir tekrarıyla başladı. Bu protokollerde gizlilik, kimlik doğrulama ve bütünlük yoktur; özellikle IP'de kaynak adresin gönderen tarafından yazılması, sonraki bütün saldırıların temelini oluşturur. Ardından servis engelleme saldırıları işlendi: tasarım hatasına ya da asimetriye dayanan DoS Bug ile botnet tabanlı DoS Flood. Sunucuda durum tutmayı sömüren SYN flood ve buna karşı durumu kriptografik bir MAC ile istemciye taşıyan SYN cookie ayrıntılı anlatıldı. Sahte kaynak adresiyle açık DNS resolver, NTP ve memcached sunucularını güçlendirici olarak kullanan saldırılar gerçek rakamlarla incelendi. Güçlendirme yerine varsayılan parolalarla ele geçirilmiş IoT cihazlarıyla taşkın yapan Mirai botnet'i ve Krebs saldırısı örneklendi.

Savunma tarafında Google Project Shield'in el sıkışmayı tamamlamayan bağlantıları ayıklaması, saldırganların buna gerçek bot adresleriyle büyük dosya isteyerek cevap vermesi ve bu durumda hız sınırlamanın mümkün hale gelmesi anlatıldı. Tarayıcılara enjekte edilen JavaScript ile yapılan GitHub saldırısı ve istemciyi yavaşlatan ama pratikte nadir kullanılan client puzzle yöntemiyle ders tamamlandı. Hoca bir sonraki derste kalınan yerden devam edileceğini söyledi; dersin başında ertelenen DNS rebinding konusu bu derste işlenmedi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
