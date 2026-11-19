# Ders 4 Çalışma Özeti

## Genel Konular

- Elektronik posta (e-posta) sisteminin bileşenleri
  - E-posta, İnternet'in en eski uygulamalarındandır; İnternet'in kurulma amacı kullanıcılar ya da makineler arasında mesaj alışverişidir.
  - Üç ana bileşen vardır: kullanıcı aracısı (user agent), posta sunucusu (mail server) ve SMTP (Simple Mail Transfer Protocol).
  - Kullanıcı aracısı ("mail reader") mesaj yazmak, düzenlemek ve okumak için kullanılır. Örnekler: Outlook, telefonlarda hazır gelen iPhone e-posta istemcisi. Gelen ve giden mesajlar sunucuda saklanır, kullanıcı aracısı bunlara erişir.
  - Posta sunucusunda kullanıcı posta kutuları (mailbox, gelen mesajlar) ve giden mesajların bekletildiği mesaj kuyruğu (message queue) bulunur (ekrandan, 00:15:00).
  - SMTP, posta sunucuları arasında mesaj gönderen protokoldür. Gönderen sunucu istemci, alan sunucu "sunucu" rolündedir (ekrandan, 00:15:00).
- Alice'ten Bob'a e-posta senaryosu (altı adım)
  - 1) Alice kullanıcı aracısıyla Bob'un adresine mesaj yazar. 2) Kullanıcı aracısı mesajı Alice'in posta sunucusuna gönderir, mesaj kuyruğa girer. 3) Alice'in sunucusunun istemci tarafı Bob'un posta sunucusuna TCP bağlantısı açar. 4) Mesaj TCP bağlantısı üzerinden SMTP ile gönderilir. 5) Bob'un sunucusu mesajı Bob'un posta kutusuna koyar. 6) Bob kullanıcı aracısıyla mesajı okur.
  - TCP kullanılmasının nedeni e-postanın güvenilir aktarım gerektirmesidir.
- SMTP (RFC 5321)
  - Açık, uygulama katmanı protokolüdür; standardı RFC 5321'dedir (ekrandan, 00:20:00).
  - TCP ile güvenilir aktarım yapar, port 25 kullanır. Aktarım doğrudandır: gönderen sunucu (istemci gibi davranır) alan sunucuya bağlanır.
  - Üç aşama: el sıkışma (selamlaşma), mesaj aktarımı, kapanış.
  - HTTP gibi komut/yanıt etkileşimi vardır: komutlar ASCII metindir, yanıt bir durum kodu ve açıklama ifadesi (phrase) içerir. Mesajlar 7 bit ASCII olmalıdır (ekrandan, 00:20:00).
- Örnek SMTP etkileşimi
  - Sunucu (hamburger.edu) ile istemci (crepes.fr) arasında HELO, MAIL FROM, RCPT TO, DATA, QUIT komutları ve 220, 250, 221 gibi durum kodlarıyla ilerleyen insan tarafından okunabilir bir diyalog anlatıldı. Mesaj gövdesi satır satır gönderilir, tek başına bir "." içeren satır mesajı bitirir.
  <!-- BELİRSİZ: Örnek diyalog slaytı karelerde yok; bazı durum kodları (DATA sonrası yanıt, kabul yanıtı) altyazıda net değil. -->
  - Kendiniz deneyin: `telnet <servername> 25` ile bağlanıp 220 yanıtı görülür, sonra HELO, MAIL FROM:, RCPT TO:, DATA, QUIT komutlarıyla e-posta istemcisi kullanmadan mesaj gönderilebilir. Bu, yalnız sunucu 25 numaralı porta telnet bağlantısına izin veriyorsa çalışır; güvenlik nedeniyle giderek nadirleşmektedir (ekrandan, 00:25:00).
- SMTP ile HTTP karşılaştırması
  - İkisi de açık, ASCII tabanlı, okunabilir, komut/yanıt etkileşimli ve durum kodu kullanan protokollerdir.
  - HTTP çekme (pull), SMTP itme (push) mantığıyla çalışır.
  - HTTP'de her nesne kendi yanıt mesajında taşınır; SMTP'de birden çok nesne çok parçalı (multipart) bir mesajla gönderilebilir.
  - SMTP kalıcı (persistent) bağlantı kullanır ve başlık ile gövdenin 7 bit ASCII olmasını ister. Sunucu mesaj sonunu CRLF.CRLF ile (tek başına nokta içeren satır) anlar.
- E-posta mesaj biçimi
  - SMTP mesaj alışverişi protokolünü (RFC 5321), RFC 822 ise mesajın kendi sözdizimini tanımlar (HTTP ile HTML ilişkisine benzer).
  - Başlıkta To:, From:, Subject: satırları bulunur; başlık ile gövde boş bir satırla ayrılır. Gövde yalnız ASCII karakterlerden oluşur.
- Posta erişim protokolleri
  - SMTP, mesajı alıcının sunucusuna teslim etmek ve saklamak için kullanılır (hem kullanıcı aracısından gönderen sunucuya hem sunucular arasında).
  - Posta erişim protokolü sunucudan mesaj almak içindir. IMAP (Internet Mail Access Protocol, RFC 3501): mesajlar sunucuda saklanır; IMAP alma, silme ve sunucudaki mesajları klasörlerde düzenleme sağlar (ekrandan, 00:30:00).
  - HTTP: Gmail, Hotmail, Yahoo! Mail gibi servisler SMTP (gönderme) ve IMAP ya da POP (alma) üzerine Web tabanlı arayüz sağlar.
- DNS (Domain Name System)
  - İnsanların TC kimlik numarası, ad, pasaport numarası gibi birçok tanımlayıcısı vardır. İnternet'te hostlar ve yönlendiriciler 32 bitlik IP adresiyle, insanlar ise "hasanbalik.com" gibi adlarla tanımlanır (ekrandan, 00:35:00).
  - Soru: IP adresi ile ad arasında, iki yönde, nasıl eşleme yapılır? Cevap: DNS. DNS, birçok ad sunucusundan oluşan bir hiyerarşi şeklinde uygulanmış dağıtık bir veritabanıdır.
  - DNS bir uygulama katmanı protokolüdür: hostlar ve ad sunucuları adları çözmek (adres/ad çevirisi) için haberleşir. İnternet'in çekirdek bir işlevidir ama uygulama katmanında gerçeklenir; karmaşıklık ağın "kenarında"dır.
  - DNS ayrıca yük dağıtımı için kullanılır: birçok Web sunucusu tek bir ada karşılık gelen birçok IP adresine sahip olabilir.
- DNS neden merkezi değil?
  - Tek merkez tek hata noktası (single point of failure) olur; bütün sorgular tek noktaya yığılır (trafik hacmi); uzak merkezi veritabanı ve bakım sorunu vardır; ölçeklenemez.
  - Ölçek örneği: ABD'deki ISP Comcast'in DNS sunucuları tek başına günde 600 milyar ($600 \times 10^9$) DNS sorgusu karşılar.
- DNS hiyerarşisi
  - En üstte kök (root) DNS sunucuları, ikinci seviyede üst düzey alan (TLD: .com, .org, .edu ...) sunucuları, üçüncü seviyede yetkili (authoritative) sunucular (yahoo.com, amazon.com, pbs.org, nyu.edu, umass.edu) bulunur (ekrandan, 00:40:00).
  - Birinci yaklaşım: www.amazon.com'un IP adresini isteyen istemci önce kök sunucuya sorup .com sunucusunu, sonra .com sunucusuna sorup amazon.com DNS sunucusunu, en son amazon.com DNS sunucusuna sorup IP adresini öğrenir (ekrandan, 00:40:00).
  - Kök ad sunucuları, adı çözemeyen ad sunucularının başvurduğu son noktadır. DNSSEC kimlik doğrulama ve mesaj bütünlüğü sağlar. Kök DNS alanını ICANN (Internet Corporation for Assigned Names and Numbers) yönetir. Dünyada 13 mantıksal kök ad sunucusu vardır ve her biri birçok kez çoğaltılmıştır.
  - TLD sunucuları .com, .org, .net, .edu gibi alanlardan ve .fr, .jp, .tr gibi ülke alanlarından sorumludur.
  - Yetkili DNS sunucuları kurumun kendi ad-IP eşlemelerini tutar; kurum ya da servis sağlayıcı işletebilir.
- Yerel DNS ad sunucuları (ekrandan, 00:45:00)
  - Hiyerarşiye tam olarak ait değildir. Her ISP (ev ISP'si, şirket, üniversite) en az bir tane işletir; "varsayılan ad sunucusu" da denir.
  - Host DNS sorgusunu yerel DNS sunucusuna gönderir. Yerel sunucuda yakın zamandaki ad-adres çiftlerinin önbelleği vardır (güncel olmayabilir). Yerel sunucu vekil (proxy) gibi davranır, sorguyu hiyerarşiye iletir.
- Ad çözümleme yöntemleri
  - Yinelemeli sorgu (iterated query): engineering.nyu.edu'daki host gaia.cs.umass.edu'nun IP adresini ister. Yerel DNS sunucusu (dns.nyu.edu) sırasıyla kök sunucuya, TLD sunucusuna, yetkili sunucuya (dns.cs.umass.edu) sorar; her biri bir sonraki sunucunun adresini söyler, sonuç hosta iletilir.
  - Özyinelemeli sorgu (recursive query): sorgu kökten TLD'ye, oradan yetkili sunucuya zincirleme iletilir ve yanıt aynı yoldan geri döner. Çözümleme yükünü sorulan ad sunucusuna bindirir, üst seviyedeki sunucular ağır yük altında kalır.
- Önbellekleme ve güncelleme (ekrandan, 00:50:00)
  - Bir ad sunucusu eşlemeyi öğrenince önbelleğe alır; kayıtlar bir süre (TTL) sonra silinir. TLD sunucularının adresleri genelde yerel ad sunucularında önbellektedir, bu yüzden kök sunuculara sık gidilmez.
  - Önbellekteki kayıt güncel olmayabilir (en iyi çaba ile ad-adres çevirisi): bir host IP adresini değiştirirse, bütün TTL'ler dolana kadar bu İnternet çapında bilinmeyebilir. Güncelleme/bildirim mekanizmaları IETF standardı RFC 2136'dadır.
- DNS kayıtları ve mesajları
  - Kaynak kaydı (RR) biçimi: (name, value, type, ttl). Type = A ise name host adı, value IP adresidir.
  - Sorgu ve yanıt mesajları aynı biçimdedir: 16 bitlik tanımlama (identification) alanı sorguyla yanıtı eşler; bayraklar sorgu/yanıt, özyineleme isteniyor (recursion desired), özyineleme mevcut (recursion available), yanıt yetkili mi bilgisini taşır; ardından sorular ve cevaplar gelir.
  <!-- BELİRSİZ: DNS veritabanına kayıt ekleme örneği (00:53:29) altyazıda okunamıyor. -->
- DNS güvenliği (ekrandan, 00:55:00)
  - DDoS saldırıları: kök sunucuları trafikle bombardıman etmek (şimdiye dek başarılı olmadı; trafik filtreleme ve yerel sunucuların TLD adreslerini önbellekte tutması kökü atlamayı sağlar); TLD sunucularını bombardıman etmek (potansiyel olarak daha tehlikeli).
  - Yönlendirme saldırıları: ortadaki adam (DNS sorgularını yakalama), DNS zehirleme (önbellekleyen DNS sunucusuna sahte yanıt gönderme).
  - DNS'i DDoS için kullanma: kaynak adresi hedef IP olarak sahtelenmiş sorgular gönderme; yükseltme (amplification) gerektirir. Önlemler DNSSEC belgesinde anlatılır.
- Eşler arası (P2P) mimari
  - Sürekli açık sunucu yoktur; uç sistemler doğrudan haberleşir, eşler hizmet ister ve karşılığında hizmet verir. Eşler aralıklı bağlanır, IP adresleri değişebilir; yönetim karmaşıktır.
- Dosya dağıtımı: istemci-sunucu ve P2P (ekrandan, 01:15:00)
  - $F$ boyutlu dosya bir sunucudan $N$ eşe dağıtılacaktır. $u_s$ sunucunun yükleme kapasitesi, $u_i$ ve $d_i$ $i$. eşin yükleme ve indirme kapasitesidir; ağ bant genişliği bol kabul edilir.
  - İstemci-sunucu: sunucu $N$ kopyayı sırayla yüklemeli ($NF/u_s$), en yavaş istemci dosyayı $F/d_{min}$ sürede indirir. $D_{c-s} \ge \max\{NF/u_s,\ F/d_{min}\}$; $N$ ile doğrusal artar.
  - P2P: sunucu en az bir kopya yüklemeli ($F/u_s$), her istemci bir kopya indirmeli ($F/d_{min}$), toplamda $NF$ bit indirileceğinden ve en yüksek toplam yükleme hızı $u_s + \sum u_i$ olduğundan $D_{P2P} \ge \max\{F/u_s,\ F/d_{min},\ NF/(u_s + \sum u_i)\}$.
  - Örnek grafik: istemci yükleme hızı $u$, $F/u = 1$ saat, $u_s = 10u$, $d_{min} \ge u_s$. İstemci-sunucu süresi $N$ ile doğrusal artarken (N = 32'de yaklaşık 3,2 saat) P2P süresi yavaş artar (N = 32'de yaklaşık 0,76 saat) (ekrandan, 01:20:00).
- BitTorrent
  - Dosya 256 Kb'lik parçalara (chunk) bölünür. Torrent, dosyanın parçalarını değiş tokuş eden eşler grubudur; tracker torrente katılan eşlerin kaydını tutar.
  - Yeni katılan eş başta hiç parçaya sahip değildir, tracker'dan eş listesi alır, eşlere bağlanır ve zamanla parça biriktirir. Dosyayı tamamlayınca ayrılabilir (bencilce) ya da kalıp başkalarına dağıtmayı sürdürebilir.
  - Parça isteme: her eşte farklı parça alt kümesi vardır; eş düzenli olarak komşularından parça listesini ister ve eksik parçaları ister.
  - Parça gönderme (tit-for-tat): eş, kendisine en yüksek hızla parça gönderen dört eşe parça gönderir; her 30 saniyede rastgele bir eşi "iyimser olarak açar" (optimistically unchoke). Yeni seçilen eş ilk dörde girebilir. Daha yüksek yükleme hızı daha iyi ticaret ortakları ve dosyayı daha hızlı almak demektir.
- Video akışı ve CDN
  - Video akışı İnternet trafiğinin en büyük tüketicisidir; 2020'de ev ISP trafiğinin yaklaşık %80'i Netflix, YouTube, Amazon Prime'a aitti. Kullanıcı sayısı yaklaşık 1 milyara ulaşabilir; tek dev sunucu çözüm değildir, çözüm dağıtık, uygulama seviyesinde bir altyapıdır.
  - Video, sabit hızda gösterilen görüntü dizisidir; her görüntü piksellerden oluşur. Kodlama, görüntü içindeki (uzamsal, spatial) ve ardışık görüntüler arasındaki (zamansal, temporal) fazlalığı kullanarak bit sayısını azaltır (ekrandan, 01:30:00).
  - CBR (sabit bit hızı) ve VBR (değişken bit hızı). Örnekler: MPEG-1 (CD-ROM) 1,5 Mbps, MPEG-2 (DVD) 3-6 Mbps, MPEG-4 (İnternet) 64 Kbps - 12 Mbps (ekrandan, 01:30:00).
  - Depolanmış video akışı: istemci, sunucu sonraki kısımları gönderirken erken kısmı oynatmaya başlar. Sürekli oynatma kısıtı vardır; değişken ağ gecikmesi (jitter) nedeniyle istemci tarafında tampon ve oynatma gecikmesi gerekir. Durdurma, ileri-geri sarma gibi etkileşimler de zorluk yaratır (ekrandan, 01:35:00).
  - DASH (Dynamic Adaptive Streaming over HTTP): sunucu videoyu parçalara böler, her parçayı farklı hızlarda kodlayıp ayrı dosyalarda saklar; manifest dosyası parçaların URL'lerini verir. İstemci bant genişliğini ölçer, o anki bant genişliğinde sürdürülebilir en yüksek kodlama hızındaki parçayı ister; zekâ istemcidedir (ne zaman, hangi hızda, hangi sunucudan).
  - CDN: tek dev sunucu tek hata noktası ve tıkanıklık yaratır, ölçeklenmez. Seçenek 2: videoların birden çok kopyasını coğrafi olarak dağıtık sitelerde saklamak. "Enter deep" (Akamai: 2015'te 120'den fazla ülkede 240.000 sunucu, kullanıcıya yakın) ve "bring home" (Limelight: erişim ağlarına yakın POP'larda az sayıda büyük küme) yaklaşımları (ekrandan, 01:40:00).
  - Netflix örneği: içerik kopyaları CDN düğümlerinde saklanır; abone içeriği ister, manifest dosyasını alır, en yakın ya da en uygun kopyadan parçaları çeker; ağ hızı değişince başka düğüme geçebilir. OTT (over the top): hangi CDN düğümünden içerik alınacağı, tıkanıklıkta ne yapılacağı ve hangi içeriğin hangi düğüme konacağı sorunları.

## Hocanın Özellikle Vurguladığı Kısımlar

- E-postanın TCP kullanması
  - E-posta güvenilir aktarım istediği için SMTP TCP üzerinde çalışır ve önce üç yönlü el sıkışma yapılır; port 25 vurgulandı.
- SMTP ile HTTP'nin benzerliği ve farkı
  - İkisi de ASCII, okunabilir, durum kodlu protokollerdir; asıl fark HTTP'nin çekme, SMTP'nin itme mantığıdır.
- DNS'in uygulama katmanı protokolü olması
  - DNS İnternet'in çekirdek işlevidir ama ağ katmanında değil uygulama katmanında, uç sistemlerde gerçeklenir.
- DNS'in neden dağıtık olduğu
  - Tek hata noktası, trafik hacmi, bakım ve ölçeklenme sorunları; Comcast'in tek başına günde 600 milyar sorgusu örneği ("milyon değil, milyar" vurgusuyla).
- P2P'nin ölçeklenmesi
  - İstemci-sunucu dağıtım süresi istemci sayısıyla doğrusal artar, P2P'de ise yeni eşler yükleme kapasitesi de getirdiği için artış yavaştır.
- DASH'te zekânın istemcide olması
  - Bant genişliğini ölçen ve hangi kodlamadaki parçayı isteyeceğine karar veren istemcidir.

## Kısa Tekrar Notları

- E-posta bileşenleri: kullanıcı aracısı, posta sunucusu (posta kutusu + mesaj kuyruğu), SMTP.
- SMTP: RFC 5321, TCP, port 25, üç aşama (el sıkışma, aktarım, kapanış), 7 bit ASCII, komut/yanıt.
- Mesaj sonu: tek başına "." içeren satır.
- SMTP itme, HTTP çekme; SMTP kalıcı bağlantı ve çok parçalı mesaj.
- Mesaj biçimi: To/From/Subject başlıkları, boş satır, ASCII gövde.
- Posta erişimi: IMAP (RFC 3501) ya da HTTP (Web posta); POP da anılır.
- DNS: dağıtık, hiyerarşik veritabanı; uygulama katmanı protokolü; yük dağıtımı da yapar.
- Hiyerarşi: kök (13 mantıksal, ICANN yönetir) → TLD → yetkili; yerel DNS hiyerarşi dışında, vekil gibi.
- Yinelemeli sorguda yerel sunucu her seviyeye kendisi sorar; özyinelemelide sorgu zincirleme iletilir ve üst sunuculara yük biner.
- Önbellek kayıtları TTL ile silinir; güncelleme RFC 2136.
- RR: (name, value, type, ttl); type A: ad → IP.
- DNS mesajı: 16 bit kimlik, bayraklar, sorular, cevaplar.
- DNS saldırıları: DDoS (kök/TLD), ortadaki adam, zehirleme, sahte kaynak adresli yükseltme.
- $D_{c-s} \ge \max\{NF/u_s, F/d_{min}\}$, $D_{P2P} \ge \max\{F/u_s, F/d_{min}, NF/(u_s+\sum u_i)\}$.
- BitTorrent: 256 Kb parça, tracker, en iyi dört eş, 30 saniyede bir iyimser açma.
- Video: uzamsal ve zamansal kodlama; CBR/VBR; MPEG-1 1,5 Mbps, MPEG-2 3-6 Mbps, MPEG-4 64 Kbps-12 Mbps.
- İstemci tamponu jitter'ı telafi eder; DASH uyarlanabilir hız seçer, manifest URL'leri verir.
- CDN: enter deep (Akamai) ve bring home (Limelight).

## Detaylı Açıklamalar

- E-posta yolculuğu baştan sona
  - Alice mesajını kullanıcı aracısında yazar ve gönderir; mesaj önce Alice'in posta sunucusundaki giden kuyruğuna girer. Sunucunun istemci tarafı Bob'un sunucusuna 25 numaralı porttan TCP bağlantısı açar, el sıkışmadan sonra mesajı SMTP komutlarıyla aktarır ve bağlantıyı kapatır. Bob'un sunucusu mesajı Bob'un posta kutusuna koyar. Bob mesajı okurken SMTP değil, IMAP ya da HTTP gibi bir erişim protokolü kullanır. Yani SMTP yalnız "itme" yönünde (gönderen aracıdan sunucuya ve sunucudan sunucuya) çalışır.
- SMTP diyaloğunun mantığı
  - Bağlantı açılınca sunucu 220 koduyla kendini tanıtır. İstemci HELO ile selam verir, MAIL FROM ile göndereni, RCPT TO ile alıcıyı bildirir; sunucu her birini 250 ile onaylar. DATA komutundan sonra istemci mesajı satır satır yollar ve tek başına bir nokta içeren satırla bitirir. Sunucu mesajın teslim için kabul edildiğini bildirir, istemci QUIT der, sunucu 221 ile bağlantıyı kapatır. Bütün komut ve yanıtlar ASCII olduğu için telnet ile elle denenebilir.
- DNS'te ad çözümleme
  - Host önce yerel (varsayılan) DNS sunucusuna sorar. Cevap önbellekte yoksa yerel sunucu hiyerarşiye gider. Yinelemeli yöntemde kök sunucu "bilmiyorum, şu TLD sunucusuna sor" der, TLD sunucusu yetkili sunucuyu gösterir, yetkili sunucu IP adresini verir; bütün soruları yerel sunucu sorar. Özyinelemeli yöntemde her sunucu sorguyu bir sonrakine kendisi iletir ve cevabı geri taşır; bu, üst seviyedeki sunuculara büyük yük bindirir. Önbellekleme sayesinde TLD adresleri genelde yerelde bulunur ve kök sunuculara nadiren gidilir; ancak TTL dolana kadar eski kayıtlar kullanılabilir.
- P2P dağıtım süresinin yorumu
  - İstemci-sunucu modelinde sunucu her istemci için ayrı bir kopya yüklemek zorunda olduğundan süre $N$ ile doğrusal büyür. P2P modelinde her yeni eş indirme talebiyle birlikte kendi yükleme kapasitesini de getirir; payda $u_s + \sum u_i$ da $N$ ile büyüdüğü için $NF/(u_s+\sum u_i)$ terimi bir üst sınıra yaklaşır. Slayttaki örnekte bu terim $N/(10+N)$ saat olur: N = 10 için 0,5 saat, N = 32 için yaklaşık 0,76 saat; istemci-sunucuda aynı değerler 1 ve 3,2 saattir (değerler python ile doğrulandı).
- Video akışında tampon ve DASH
  - Sunucu videoyu sabit hızda gönderse de ağ gecikmesi değiştiği için kareler istemciye düzensiz aralıklarla gelir. İstemci oynatmayı bir süre geciktirip gelen veriyi tamponda biriktirirse oynatma orijinal zamanlamayla sürekli yapılabilir. Bant genişliği zaman içinde değiştiğinde ise DASH devreye girer: istemci ölçtüğü bant genişliğine göre manifest dosyasındaki URL'lerden uygun kalitedeki parçayı ister, böylece tampon ne boşalır ne taşar. CDN'ler de aynı içeriğin kopyalarını kullanıcıya yakın sunuculara koyarak bu parçaların kısa ve tıkanıklığı az bir yoldan gelmesini sağlar.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
