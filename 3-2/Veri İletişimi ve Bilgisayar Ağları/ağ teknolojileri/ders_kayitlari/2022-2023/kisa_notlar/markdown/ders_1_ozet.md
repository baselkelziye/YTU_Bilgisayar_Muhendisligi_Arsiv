# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin kapsamı
  - Ders, Kurose ve Ross'un "Computer Networking" (8. baskı, 2021) kitabını izler (ekrandan, 00:10:00).
  - Konular (ekrandan, 00:15:00): bilgisayar ağları ve İnternet, uygulama katmanı, taşıma katmanı, ağ katmanı (veri düzlemi), ağ katmanı (kontrol düzlemi), bağlantı katmanı ve LAN'lar, kablosuz ve mobil ağlar.
  - Ağ katmanı İnternet'in en karmaşık ve en önemli kısmı olduğu için iki bölüme ayrılmıştır: veri düzlemi ve kontrol düzlemi.
  - Güvenlik bölümü bu derste işlenmez; ayrı bir derste ele alınır. Fiziksel katmanın ayrıntısına da girilmez.
- Giriş bölümünün yol haritası
  - İnternet nedir sorusu, ağın kenarı (host'lar, erişim ağları, fiziksel ortam), ağın çekirdeği (devre anahtarlama ve paket anahtarlama), başarım (paket kaybı, gecikme, verim), protokol katmanları ve servis modelleri, güvenlik ve İnternet tarihi.
- İnternet'in "somun ve cıvata" görünümü (ekrandan, 00:25:00)
  - Milyarlarca bağlı cihaz: host = uç sistem; ağ uygulamalarını İnternet'in "kenarında" çalıştırır.
  - Paket anahtarları: paketleri (veri parçalarını) iletir; yönlendiriciler (router) ve anahtarlar (switch).
  - İletişim bağlantıları: fiber, bakır, radyo, uydu; iletim hızı = bant genişliği.
  - Ağlar: bir kurum tarafından yönetilen cihaz, yönlendirici ve bağlantılar topluluğu.
  - İnternete bağlı cihaz örnekleri: buzdolabı, güvenlik kamerası, IP telefon, kalp pili ve sağlık izleme cihazları, hava durumunu ekmeğe basan kızartma makinesi, artırılmış gerçeklik gözlükleri, akıllı saat, IP resim çerçevesi.
- İnternet: "ağların ağı" (ekrandan, 00:30:00)
  - Birbirine bağlı İSS'lerden (İnternet Servis Sağlayıcı) oluşur; her İSS ayrı bir şirket ya da kuruma aittir.
  - Protokoller her yerdedir: mesaj gönderme ve almayı denetler. Örnekler: HTTP (Web), video akışı, Skype, TCP, IP, WiFi, 4G, Ethernet.
  - İnternet standartları: RFC (Request for Comments) ve IETF (Internet Engineering Task Force).
- Servis görünümü
  - İnternet, uygulamalara servis veren bir altyapıdır; dağıtık uygulamalara bir programlama arayüzü sağlar.
  - Bu arayüz, gönderen ve alan uygulamanın İnternet'in taşıma servisini kullanarak mesaj alışverişi yapmasını sağlayan "kancalar" (hooks) içerir.
  - Sunulan servis seçenekleri posta servisine benzetilir.
- Protokol nedir? (ekrandan, 00:35:00)
  - İnsan protokolü: saati sormak, "bir sorum var" demek, tanışmak. Belli mesajlar gönderilir, mesaj alınınca belli eylemler yapılır.
  - Ağ protokolü: insanların yerine cihazlar; İnternet'teki bütün iletişim protokollerle yönetilir.
  - Tanım: Protokol, ağ varlıkları arasında gönderilen ve alınan mesajların biçimini ve sırasını, mesaj iletiminde ya da alımında yapılacak eylemleri tanımlar.
- İnternet yapısına yakından bakış (ekrandan, 00:40:00)
  - Ağ kenarı: host'lar istemci (telefon, dizüstü, masaüstü, IP telefon) ya da sunucudur; sunucular çoğunlukla veri merkezlerindedir.
  - Erişim ağları ve fiziksel ortam: kablolu ya da kablosuz bağlantılar.
  - Ağ çekirdeği: birbirine bağlı yönlendiriciler; bazı yönlendiriciler ağları başka ağlara bağlar.
- Erişim ağları
  - Uç sistem kenar yönlendiriciye üç yolla bağlanır: konut erişim ağları, kurumsal erişim ağları (üniversite, şirket), mobil erişim ağları (WiFi, 4G/5G).
  - Bakılacak iki şey: iletim hızı (saniyedeki bit) ve bağlantının paylaşımlı mı, adanmış mı olduğu.
- Kablo tabanlı erişim (ekrandan, 00:45:00)
  - Ortak koaksiyel kablo birçok ev tarafından paylaşılır. Her evde TV ve veriyi ayıran bir ayırıcı (splitter) ve kablo modem vardır; kablo, kablo başlığına (cable headend) gider.
  - FDM (frekans bölmeli çoğullama): farklı kanallar farklı frekans bantlarında iletilir. Slayttaki örnekte 1-6 video, 7-8 veri, 9 kontrol kanalıdır.
  - Başlıkta CMTS (Cable Modem Termination System) bulunur ve İSS'ye bağlıdır.
  - HFC (hibrit fiber koaks), asimetriktir: aşağı akış 40 Mbps - 1,2 Gbps, yukarı akış 30 - 100 Mbps.
- DSL (ekrandan, 00:50:00)
  - Mevcut telefon hattı, santraldeki DSLAM'a (DSL access multiplexer) kadar kullanılır. Hattaki veri İnternet'e, ses telefon ağına gider.
  - Ses ve veri, santrale giden adanmış hat üzerinde farklı frekanslarda iletilir.
  - Adanmış aşağı akış 24-52 Mbps, adanmış yukarı akış 3,5-16 Mbps.
- Ev ağları (ekrandan, 01:10:00)
  - Kablo ya da DSL modem, yönlendirici/güvenlik duvarı/NAT, kablolu Ethernet (1 Gbps), WiFi erişim noktası (54, 450 Mbps).
  - Bu cihazlar çoğu zaman tek kutuda birleşir.
- Kablosuz erişim ağları
  - Paylaşımlıdır; uç sistemi baz istasyonu (erişim noktası) üzerinden yönlendiriciye bağlar.
  - Kablosuz yerel ağ (WLAN, WiFi): bina içi ve çevresi, tipik olarak 30 m, engel yoksa 100 m'ye kadar. 802.11 standartları: b 11 Mbps, g 54 Mbps, n 450-600 Mbps, ac ve ax daha yüksek hızlar.
  - Geniş alan hücresel ağlar: 4G/5G, mobil operatörler.
- Kurumsal ağlar (ekrandan, 01:15:00)
  - Şirketler, üniversiteler; kablolu ve kablosuz bağlantıların, anahtar ve yönlendiricilerin karışımı.
  - Kurumsal yönlendirici, İSS'ye bağlanır; kurumsal e-posta ve web sunucuları çekirdek anahtara bağlıdır.
  - Ethernet: 100 Mbps, 1 Gbps, 10 Gbps; WiFi: 11, 54, 450 Mbps.
- Host'un paket göndermesi (ekrandan, 01:20:00)
  - Host uygulama mesajını alır, $L$ bitlik paketlere böler ve erişim ağına $R$ iletim hızıyla gönderir.
  - Bağlantı iletim hızı = bağlantı kapasitesi = bant genişliği (bit/s).
  - Paket iletim gecikmesi $= \dfrac{L\ \text{(bit)}}{R\ \text{(bit/s)}}$.
- Fiziksel ortam
  - Bit, verici ve alıcı çifti arasında yayılır. Kılavuzlu ortam (bakır, koaksiyel, fiber) ve kılavuzsuz ortam (radyo) vardır.
  - Bükümlü çift: iki yalıtılmış bakır tel; Cat5 Ethernet'te 1 Gbps'e, Cat6 10 Gbps'e kadar.
  - Fiber optik: ışık darbeleri taşıyan cam lif; tek modlu ya da çok modlu; her bit ışıkla temsil edilir.
  - Kablosuz radyo (ekrandan, 01:25:00): sinyal elektromanyetik spektrumda taşınır, fiziksel tel yoktur, yayın ve yarı çift yönlüdür (half-duplex). Yayılım ortamı etkileri: yansıma, nesnelerin engellemesi, girişim.
  - Radyo bağlantı türleri: WLAN (100'lerce Mbps), 4G hücresel (~10'larca Mbps), karasal mikrodalga (45 Mbps'e kadar kanallar), uydu (kanal başına 45 Mbps'e kadar, 270 ms uçtan uca gecikme, yer eşzamanlı ve alçak yörünge).

## Hocanın Özellikle Vurguladığı Kısımlar

- İnternet'in tanımı: ağların ağı
  - Ders boyunca bu tanıma dönüldü: İnternet, birbirine bağlı İSS'lerin oluşturduğu büyük bir yapıdır.
- Protokolün tanımı
  - İnsan protokolüyle (saati sorma) kurulan benzetme, protokolün mesajların biçimini, sırasını ve alınan mesaja karşı yapılacak eylemi tanımladığını gösterir.
- Erişim ağında iki soru
  - İletim hızı ne kadar ve bağlantı paylaşımlı mı, adanmış mı? Kablo erişimi paylaşımlı, DSL adanmış hattır.
- Asimetrik erişim
  - Evde aşağı akış ihtiyacı yukarı akıştan büyük olduğu için kanalların çoğu aşağı akışa ayrılır.
- Sayısal değerler ezberlenmez, mertebesi bilinir
  - Bir öğrencinin sorusu üzerine hoca, slaytlardaki hız değerlerinin kelime kelime ezberlenmesine gerek olmadığını, ama bir bilgisayar mühendisinin mertebeyi bilmesi gerektiğini söyledi: örneğin Ethernet hızının 100 Mbps ve üstü olduğu bilinmeli, hızın biriminin bit/s olduğu bilinmeli.
  - Slayttaki hızlar en iyi durum hızlarıdır; mesafe arttıkça hız düşer.

## Kısa Tekrar Notları

- İnternet = ağların ağı = birbirine bağlı İSS'ler.
- Host = uç sistem; istemci ya da sunucu; sunucular çoğunlukla veri merkezinde.
- Paket anahtarları: yönlendirici ve anahtar.
- Bant genişliği = iletim hızı = bağlantı kapasitesi, birimi bit/s.
- Standartlar: RFC ve IETF.
- Protokol: mesajların biçimi, sırası ve alındığında yapılacak eylemler.
- Kablo erişimi: paylaşımlı koaks, FDM, CMTS, HFC, asimetrik.
- DSL: adanmış telefon hattı, DSLAM, 24-52 Mbps aşağı, 3,5-16 Mbps yukarı.
- Ev ağı: modem + yönlendirici/NAT/güvenlik duvarı + WiFi erişim noktası, çoğu zaman tek kutu.
- Paket iletim gecikmesi $= L/R$.
- Kılavuzlu ortam: bükümlü çift, koaks, fiber; kılavuzsuz ortam: radyo.
- Uydu: kanal başına 45 Mbps'e kadar, 270 ms uçtan uca gecikme.

## Detaylı Açıklamalar

- **İnternet'i iki açıdan görmek.** Birinci açı donanım açısıdır: kenarda uygulama çalıştıran milyarlarca host, ortada paketleri ileten yönlendirici ve anahtarlar, bunları birbirine bağlayan fiber, bakır, radyo ya da uydu bağlantıları vardır. Her bağlantının bir iletim hızı (bant genişliği) vardır. Bu cihazlar ve bağlantılar, her biri bir kurum tarafından yönetilen ağlar oluşturur; İnternet de bu ağların, yani İSS'lerin birbirine bağlanmasıyla oluşur. Hoca kendi örneğini verdi: okulda İnternet'i üniversite, evde bir kablo operatörü sağlar; başka evlerde başka operatörler. İkinci açı servis açısıdır: İnternet, Web, e-posta, oyun gibi dağıtık uygulamalara servis veren bir altyapıdır ve uygulamalara bir programlama arayüzü sunar. Bu arayüz, posta servisinin farklı gönderim seçenekleri sunmasına benzetilir.
- **Protokol.** İnsanlar arasında da kurallı iletişim vardır: saati öğrenmek isteyen biri önce selam verir, karşılık bekler, sonra soruyu sorar ve cevabı alır. Belirli bir amaç için belirli mesajlar gönderilir, belirli cevaplar beklenir. Ağda insanların yerini cihazlar alır. Protokol, iki ya da daha çok varlık arasında alışverişi yapılan mesajların biçimini ve sırasını, bir mesaj gönderildiğinde ya da alındığında yapılacak eylemi tanımlar. HTTP, TCP, IP, WiFi, 4G ve Ethernet farklı katmanlarda çalışan protokol örnekleridir. Bu protokollerin standartları RFC belgeleri ve IETF tarafından yayımlanır.
- **Erişim ağları.** Bir uç sistemi ilk yönlendiriciye (kenar yönlendirici) bağlayan ağa erişim ağı denir. Kablo tabanlı erişimde birçok ev aynı koaksiyel kabloyu paylaşır; TV yayınları ve veri, FDM ile farklı frekans kanallarında taşınır. Kablo başlığındaki CMTS, İSS'ye genellikle fiber gibi yüksek hızlı bir bağlantıyla bağlanır. Bu yapıya HFC (hibrit fiber koaks) denir ve asimetriktir. DSL'de ise ev ile santral arasındaki mevcut telefon hattı kullanılır. Bu hat eve özel, yani adanmıştır. Ayırıcı ses ve veriyi ayırır, santraldeki DSLAM veriyi İnternet'e, sesi telefon ağına yönlendirir. Ev içinde modem, yönlendirici (NAT ve güvenlik duvarı ile) ve WiFi erişim noktası bulunur. Kurumsal ağlarda (üniversite, şirket) ise anahtarlar, yönlendiriciler, kablolu Ethernet ve kablosuz erişim noktaları bir arada kullanılır.
- **Paket iletim gecikmesi.** Uygulamaların ürettiği mesajlar, kapasiteyi verimli kullanmak için küçük parçalara, yani paketlere bölünür. Paket uzunluğu $L$ bit, bağlantı iletim hızı $R$ bit/s ise $L$ bitlik paketi bağlantıya vermek için gereken süre $L/R$ saniyedir (ekrandan, 01:20:00). Hız sonsuz olmadığı için her paketin iletimi bağlantı kapasitesine bağlı bir süre alır.
- **Fiziksel ortam.** Kılavuzlu ortamda sinyal katı bir ortam boyunca ilerler: bükümlü çift (Cat5, Cat6, Cat7; UTP, FTP), koaksiyel kablo ve fiber optik. Fiberde bitler ışık darbeleriyle taşınır. Kılavuzsuz ortamda sinyal serbestçe yayılır: radyo. Radyo yarı çift yönlüdür, yani bir taraf aynı anda ya gönderir ya alır. Yansıma, engeller ve girişim sinyali bozar. Uydu bağlantısında elektromanyetik dalganın iyonosferi geçmesi gerektiği için yüksek frekanslar kullanılır; uçtan uca gecikme 270 ms civarındadır.

<!-- BELİRSİZ: 00:36:35-00:37:07 arasında insan protokolüne karşılık gelen bilgisayar protokolü örneği (web sayfası isteme) anlatılıyor; altyazı bozuk, adımlar okunamadı. -->
<!-- BELİRSİZ: 01:22:56-01:24:10 arasında koaksiyel kablo ve fiberin özellikleri anlatılıyor; altyazı bozuk, bu anlara ait kare yok. -->

> **Ders sonrası not:** Hoca DSLAM'ı "Digital Subscriber Line Access Management Office" diye açtı (01:07:16); slaytta doğrusu "DSL access multiplexer" olarak yazar (ekrandan, 00:50:00).

> **Ders sonrası not:** Hoca iletim gecikmesini bir an "paketin kaynaktan hedefe iletilmesi için gereken süre" diye anlattı (01:20:30); slayttaki tanım "L bitlik paketi bağlantıya vermek için gereken süre"dir (ekrandan, 01:20:00). Kaynaktan hedefe toplam süre, büyük olasılıkla sonraki derste görülecek yayılım ve kuyruk gecikmelerini de içerir.

> **Ders sonrası not:** Hoca 802.11ax için bir yerde 14 Gbps, başka bir yerde 13 Gbps dedi (01:12:34, 01:25:29). 802.11ax'in teorik üst sınırı büyük olasılıkla yaklaşık 9,6 Gbps'tir; 802.11ac için söylenen "7 Gbps'e kadar" değeri ise yaklaşık 6,9 Gbps olan teorik sınırla uyumludur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
