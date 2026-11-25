# Ders 3 Çalışma Özeti

## Genel Konular

- Kablosuz algılayıcı ağlar (Wireless Sensor Networks, WSN) ve mobil teknolojilerdeki yeri
  - WSN, bugünkü IoT ağlarının öncülü ve mobil teknolojilerin yapı taşlarından biri olarak ele alındı. Türkçede "kablosuz algılayıcı ağ" ya da daha doğru karşılığıyla "telsiz algılayıcı ağ" denir.
  - Bir sensör düğümünün görevi ortamı algılamak (sense), küçük işlemler yapmak ve bilgiyi merkeze aktarmaktır. Düğüm üzerinde büyük işlem yapılmaz ve düğüm herhangi bir fiziksel nesneye gömülü değildir; IoT'den en önemli farkı budur.
  - Orman, tarla, askeri dağlık arazi gibi açık ve erişilmesi güç alanlarda kullanılır. Düğümler helikopter ya da araçla rastgele dağıtılabilir, bahçe gibi özel alanlarda elle yerleştirilebilir. Kapalı alanda (indoor) pek kullanılmaz.
- Sensör düğümü donanımı
  - Temel bileşenler: sensörler/eyleyiciler (actuator), işlemci, bellek/depolama, radyo alıcı-verici, güç kaynağı (pil ya da enerji hasadı) ve isteğe bağlı GPS (ekrandan, 00:25:00).
  - İşlemciler çoğunlukla 8 ya da 16 bit, 16 MHz; işletim sistemi olarak TinyOS, Contiki kullanılır. Birkaç kB RAM ve birkaç on kB flash bellek bulunur. Radyo düşük hızlı, düşük güçlü, kısa menzillidir: ISM bantlarında 50-250 kbit/s (ekrandan, 00:25:00).
  - Örnek düğüm Tmote Sky: 2,4 GHz, 250 kbps IEEE 802.15.4 CC2420 radyo, menzil onlarca metre; MSP430 mikrodenetleyici, 10k RAM, 48k flash, 1 MB harici flash, USB ile programlama, kart üzerinde nem, sıcaklık ve ışık sensörü; 3 V'ta mcu+radyo yaklaşık 20 mA, yalnız mcu yaklaşık 2 mA, bekleme 20 µA (ekrandan, 00:30:00).
- Ağ yapısı ve iletişim
  - Düğümler birbirleri üzerinden (multi-hop) merkeze bilgi taşır; doğrudan merkeze erişimleri neredeyse yoktur. Bu yüzden topoloji değişkendir.
  - Ad-hoc ağlara benzer ama eşler arası (peer-to-peer) değil, bire-çok (broadcast) iletişim vardır.
  - Sink (havuz), baz istasyonu ya da ağ geçidi (gateway) gibi çalışır; bilgiyi internet/uydu üzerinden görev yöneticisine (task manager) aktarır (ekrandan, 00:35:00). Sink sabit ya da mobil olabilir.
- WSN'lerin karakteristikleri (ekrandan, 00:40:00)
  - Çok sayıda düğüm (binler mertebesi), düğümlerin birbirine yakın olması, $20$ düğüm/m³'e varan yoğunluk.
  - Sensörlerden sink'e doğru asimetrik bilgi akışı; iletişim sorgu (query) ya da olay (event) ile tetiklenir.
  - Sınırlı enerji (çoğu uygulamada pil değiştirmek ya da şarj etmek imkânsız), çoğunlukla statik topoloji.
  - Düşük maliyet, küçük boyut, hataya yatkınlık, noktadan noktaya yerine yayın iletişimi, ağ içi işleme (in-network processing).
- Ağ gereksinimleri (ekrandan, 00:50:00)
  - Enerji verimliliği: radyonun uyku ve uyanma modları arasında periyodik geçişle (duty cycle) çalıştırılması.
  - Ölçeklenebilirlik: yüzler, binlerce düğüm.
  - Ad-hoc ağ ve kendi kendini örgütleme (self-organization): altyapı yokluğu ve güvenilmez bağlantılar/düğümler nedeniyle.
- Yerleşim (deployment), kapsama (coverage) ve bağlantılılık (connectivity)
  - Temel soru: belirli bir uygulama, bölge ve sensör kümesi için düğümler nereye ve nasıl yerleştirilmeli? Hedefler: kapsama, bağlantılılık ve maliyet/enerji gibi diğer kısıtlar (ekrandan, 00:55:00).
  - Kapsama türleri: bariyer kapsama, tüm alan kapsama, hedef (nokta) kapsama.
  - Yönlü (directional) ve her yönlü (omnidirectional) algılama; motility (kendi etrafında dönme) ve mobility (yer değiştirme).
  - İkili (binary) ve olasılıksal (probabilistic) kapsama modelleri.
  - Rastgele ve yapılandırılmış (structured) yerleşim; aşırı yerleşim (over-deployment), artımlı yerleşim (incremental deployment, redeployment) ve mobil düğümler.
- Ağ topolojileri
  - Yıldız (tek atlamalı), düz çok atlamalı örgü (flat multi-hop mesh) ve iki katmanlı hiyerarşik (cluster head'li) yapı (ekrandan, 01:45:00).
- Bakım, zorluklar ve protokol tasarımı
  - Pil değiştirmenin zorluğu, enerji hasadı (güneş paneli) (ekrandan, 01:15:00).
  - Enerji tüketimi en çok gönderme ve almada olur; algılama ve işlemci tüketimi düşüktür.
  - Protokol tasarım zorlukları: uzun ömür, yanıt verebilirlik, dayanıklılık, sinerji, ölçeklenebilirlik, heterojenlik, kendi kendini yapılandırma, kendi kendini iyileştirme ve uyarlama, sistematik tasarım, gizlilik ve güvenlik (ekrandan, 01:20:00).
- Uygulamalar
  - Askeri (keskin nişancı tespiti, sınır ihlali, NBC saldırısı, mayın tarama, denizaltı tespiti), su altı akustik ağları, drone ağları, çevre ve habitat izleme, botanik bahçeleri, sağlık (vücut alanı ağı ve kişisel alan ağı, yaşlı bakımı, düşme tespiti), afet öngörüsü, köprü ve yapı sağlığı izleme.
- WSN ile IoT karşılaştırması ve RFID/beacon'lara giriş
  - IoT cihazları fiziksel nesneye gömülüdür, IP adresiyle tek tek erişilebilir, bulut ve büyük veri ile birlikte düşünülür, simetrik veri akışı, geniş bant ve enerji kısıtının görece az olması gibi farkları vardır.
  - RFID etiketleri, QR kod, Bluetooth beacon'lar ve kapalı alan konumlandırma kısaca anıldı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sensör ağlarının hayatta kalmasının tek yolu uyumaktır
  - Düğümler sahadaki sürelerinin büyük bölümünü uyuyarak geçirir; yalnız algılamak ve komşudan gelen bilgiyi aktarmak için uyanırlar. IoT ağları böyle değildir.
- Enerji tüketimi iletişimde yoğunlaşır
  - Algılama ve işlem az enerji harcar; veri alma ve gönderme çok harcar. Köprü konumundaki düğümler enerjisini daha çabuk bitirir. Bu yüzden cluster head görevi belirli tur sayısında düğümler arasında döndürülür.
- Ağ ömrü (network lifetime)
  - Tanımlardan biri: ağın her düğümüne, düğümün enerjisi bitmeden erişilebildiği sürece ağ yaşıyordur. Amaç enerji tüketimini bütün düğümlerde dengeli azaltmaktır; önce bazı düğümleri tüketip sonra diğerleriyle devam etmek istenmez, çünkü ara düğüm ölünce uçtaki düğümlerin verisi merkeze ulaşamaz.
- Topoloji "çoğunlukla" statiktir
  - Düğümler fiziksel hasar, yağmur, bozulma ya da enerji bitmesiyle ölür; görevlerini komşularla haberleşerek başka düğümler devralmalıdır.
- Asimetrik akış WSN'yi IoT'den ayırır
  - WSN'de bilgi sensörlerden baz istasyonuna doğru akar; IoT'de merkez ile cihaz arasında karşılıklı veri alışverişi vardır.
- Kapsama modellemesi dairesel yapılır
  - $n$ her yönlü sensörün en iyi yerleşimle kapsayabileceği en büyük alan $n \pi r^2$'dir ($r$: algılama yarıçapı). Kapsama verimliliği hesaplanırken referans tüm alan değil, bu ideal değerdir.
  - Kapsama problemi literatürde çok çalışılan bir problemdir; ikili ve olasılıksal kapsama ayrımı bilinmelidir.
- Uygulamaya özgü tasarım
  - WSN'ler uygulamaya özgü ağlardır; düğümlerin yetenekleri ve yerleştirilecek sensörler hedefe (ör. yalnız hareket mi, hedefin türü mü) göre seçilmelidir.

## Kısa Tekrar Notları

- WSN düğümü: algıla, az işle, merkeze aktar. Fiziksel nesneye gömülü değil (IoT'den farkı).
- Donanım: sensör/eyleyici, işlemci, bellek, radyo, güç, isteğe bağlı GPS.
- IEEE 802.15.4, 250 kbps, menzil onlarca metre; çoklu ortam (görüntü, ses) için bant genişliği yetersiz kalır, çok yollu yönlendirme gerekir.
- Multi-hop, broadcast iletişim; sink = baz istasyonu/ağ geçidi.
- Veri toplama: sorgu ile, periyodik, olay tetiklemeli.
- Senkron uyanma: ortak zamanlayıcı + periyodik saat eşitleme; gönderici önce "göndereceğim" bilgisi yollar.
- Dinamik voltaj ölçekleme (DVS): işlemci frekansını değiştirerek enerji tasarrufu.
- Haberleşme menzili genelde algılama menzilinin yaklaşık iki katıdır.
- Kapsama: bariyer (kamp çevresi), tüm alan (orman yangını), hedef kapsama.
- Örtüşme çözümü: her yönlü sensörde hareket ettir (mobility); yönlü sensörde döndür (motility, daha ucuz).
- İdeal kapsama: $n \pi r^2$. İkili ve olasılıksal kapsama modelleri.
- Gizli terminal (hidden terminal) sorunu: birbirini görmeyen iki düğüm ortadaki düğüme aynı anda gönderirse çarpışma olur.
- Topolojiler: yıldız, düz örgü, iki katmanlı kümeli.
- Gizlilik/güvenlik: yayın iletişimi dinlenebilir; şifreleme enerji ve işlem maliyeti getirir.
- IoT: IP adresi, bulut, büyük veri, simetrik akış, geniş bant, cihazda uç işleme (edge computing).

## Detaylı Açıklamalar

Kablosuz algılayıcı ağlar, ortamdaki fiziksel büyüklükleri (sıcaklık, nem, basınç, ışık, ses, ivme vb.) toplayan çok sayıda küçük ve ucuz düğümden oluşur. Düğümler genelde açık ve tehlikeli arazilere rastgele dağıtılır ve kendi aralarında örgütlenerek bölgeden veri toplar. Her düğümün iki temel görevi vardır: algılamak ve kendisine gelen bilgiyi bir sonraki düğüme iletmek. Bilgi çok atlamalı biçimde (multi-hop) sink adı verilen ve baz istasyonu ya da ağ geçidi gibi davranan noktaya ulaşır; sink de bilgiyi internet ya da uydu üzerinden merkeze taşır. Ders boyunca kullanılan örnekte bir ormandaki yangın izleniyordu: sıcaklık belirli bir eşiği aşınca o bölgeye drone gönderilebilir, bir vana açılabilir ya da uçağa koordinat verilip su boşaltılabilir.

Düğümlerin kaynakları kısıtlıdır. İşlemci ve bellek kapasitesi düşüktür, haberleşme hızı yaklaşık 250 kbps'tir ve menzil onlarca metredir. Bu yüzden WSN'lerde işleme ağırlıklı olarak merkezde yapılır; IoT cihazlarında ise uçta işleme (edge computing, in-situ processing) mümkündür ve teşvik edilir. Zamanla bazı düğümler daha yetenekli ve daha fazla enerjili yapıldı; bu özel düğümler cluster head olarak komşularından gelen veriyi toplayıp birleştirerek (aggregation) merkeze iletir. Düğümler küçük ve açık alanda olduğu için hataya yatkındır; aynı bölgeden gelen fazla (redundant) veri, hatalı ölçümleri komşu ölçümlerle karşılaştırarak düzeltmeye ve bir düğüm bozulunca diğerinin hizmeti sürdürmesine yarar.

Enerji, WSN tasarımının merkezindedir. Algılama ve işlem az enerji harcar, ama gönderme ve alma çok harcar. Bu yüzden düğümler zamanlarının çoğunu uykuda geçirir. Senkron uyanma için bütün düğümler aynı zamanlayıcı mekanizmasını kullanır; zamanla saatlerde kayma olduğundan belirli aralıklarla haberleşip saatlerini eşitlerler. Ayrıca gönderici önce "veri göndereceğim" bilgisini yollar, alıcılar da bunu alıp veriyi alacakları moda geçer. İşlemci tarafında dinamik voltaj ölçekleme ile çalışma frekansı değiştirilerek enerji tasarrufu yapılır. Enerji hasadı (güneş, titreşim) mümkündür ama WSN'lerde kazanç sınırlıdır; çözümlerin çoğu enerjiyi verimli kullanmaya yöneliktir. Enerjisi biten bölgelere yeni düğüm göndermek de bir seçenektir.

Yerleşimde iki temel ölçüt vardır: kapsama (sahanın ne kadarının algılandığı) ve bağlantılılık (düğümün komşusu üzerinden merkeze ulaşıp ulaşamadığı). Haberleşme menzili genelde algılama menzilinden büyüktür (yaklaşık iki katı). Kapsama türü uygulamaya göre seçilir: bir askeri kampa sızma tespiti için dairenin her noktasını değil yalnız çevresini izlemek yeterlidir (bariyer kapsama); orman yangını tespitinde ise bütün alan izlenmelidir. Rastgele dağıtımda düğümlerin algılama alanları örtüşür. Her yönlü sensörlerde örtüşmeyi azaltmanın tek yolu düğümü hareket ettirmektir; yönlü sensörlerde (kamera gibi, belirli görüş açısı) düğümü döndürmek yeterli olabilir ve daha ucuzdur. Hareket yeteneği yoksa bölgeye ek düğüm gönderilir. $n$ her yönlü sensörün en iyi yerleşimle kapsayacağı alan $n\pi r^2$'dir; gerçekte elde edilen kapsama bu değere oranlanarak verimlilik ölçülür. İkili kapsamada daire içi "kapsandı", dışı "kapsanmadı" sayılır; olasılıksal kapsamada algılama olasılığı merkezden uzaklaştıkça bir eğriye göre azalır.

Gizlilik ve güvenlik de önemli bir başlıktır: düğümler yayın yaptığı için bir düşman hattındaki veri, düşman tarafından da alınabilir. Şifreleme çözüm olabilir, ama enerji ve işlem maliyeti getirdiği için akıllı çözümler gerekir. Uygulamalar askeri alandan (keskin nişancı yerinin ses sinyalleriyle bulunması, sınır ihlali, kimyasal/biyolojik silah ve radyasyon tespiti, mayın taraması) çevre izlemeye, sağlıktan yapı sağlığı izlemeye kadar uzanır. Su altında akustik sensör ağları kullanılır; ortam yoğun olduğu için veri hızı ve aktarılan veri miktarı düşüktür. Son yıllarda dronlar da üç boyutlu, mobil bir sensör ağı oluşturur, ama maliyetleri yüksektir.

Ders, WSN'nin IoT'ye evrimiyle kapandı. 2010'lardan sonra özellikle şehir hayatında bayrak IoT'ye geçti. IoT'de her cihazın teknik olarak bir IP adresi vardır ve tek tek erişilebilir; WSN'de ise yalnız coğrafi bir bölgeden bilgi toplanır. IoT bulut ve büyük veri olmadan düşünülemez, geniş bant genişliği sayesinde çoklu ortam verisini rahatça taşır ve enerji kısıtı görece azdır. WSN'ler tamamen ortadan kalkmayacak; özellikle açık alandaki uygulamaya özgü görevlerde kullanılmaya devam edecektir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
