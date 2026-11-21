# Ders 11 Çalışma Özeti

## Genel Konular

- Akıllı telefonlarda enerji tüketimi ve ölçümü
  - Bir makine öğrenmesi uygulamasının enerji tüketimi tek bir bileşene bağlı değildir: sensörden veri toplama, ön işleme (pre-processing), özellik çıkarımı (ortalama, medyan, standart sapma gibi istatistikler) ve sınıflandırma adımlarının her biri enerji harcar.
  - Enerji ölçümü donanımsal ya da yazılımsal yapılabilir. Android'in kendi aracı Battery Stats'tir; çok kısa süren bir kodun etkisi bu araçla görülemez, kod uzun süre tekrar tekrar çalıştırılıp ortalama alınmalı ya da sonuç süreyle orantılı verilmelidir.
  - Donanımsal ölçüm için Monsoon adlı, telefonun bağlandığı ve enerji tüketimini doğrudan ölçen ücretli bir cihaz kullanılır. Hocanın hatırladığına göre literatürdeki bazı yazılımsal çözümler donanımsal ölçüme %1-4 hata payıyla yakın sonuç verir.
  - Testler aynı şartlarda yapılmalıdır. Telefonun şarjda olup olmaması enerji yöneticisinin (governor) modunu değiştirdiği için ya hep şarjda ya hep pilde ölçülmeli, mümkünse iki durum ayrı ayrı raporlanmalıdır. Arka planda (servis olarak) çalışmakla uygulama açıkken çalışmak arasında da ciddi fark vardır. Sıcaklık gibi enerjiyle ilişkili (korele) metrikler ve işin başlangıç-bitiş sistem zamanı da kaydedilebilir.
- Crowdsourcing ile problem çözme süreci
  - Problem çözmede dört adım: Intelligence (fikirlerin toplanması), Design (fikirlerin birleştirilip yaratıcı bir çözüme dönüştürülmesi), Choice (oylama ve karar), Implementation.
  - Crowdsourcing süreç akışı: problem → görevlerin (task) oluşturulup çözücülere dağıtılması → üyelerin aynı ya da farklı görev parçalarını işlemesi → üretilen verinin geri gönderilmesi → değerlendirme, birleştirme ya da filtreleme → sonucun problemi ortaya atan kişiye aktarılması.
- Crowdsourcing uygulamaları (ekrandan, 00:30:00)
  - Waze ile trafik izleme, VTrack2 ile yol gecikmesi tahmini, telefon mikrofonlarıyla gürültü haritası (Ear-Phone3, NoiseTube4), titreşim ve konum verisiyle çukur tespiti (PotHole5), konum tabanlı oyunlarla coğrafi veri toplama (CityExplorer6), trafik ışığı zamanlama tavsiyesi (SignalGuru7), Wi-Fi sinyal gücüyle iç mekan konumlama (Airplace8).
  - Konum tabanlı oyunlar (Pokemon Go ve takımların bölge ele geçirdiği oyunlar) bireysel ve grup hareketine dayalı crowdsourcing örnekleridir.
  - Denizde baz istasyonu kapsaması zayıftır. Teknelerden gelen sinyal gücü bilgileri merkezde toplanarak deniz haritası üzerinde kapsama haritası çıkarılabilir; bu fırtına, karaya oturma, yangın gibi acil durumlar için önemlidir.
  - Havalimanı kuyruk bilgisi, etkinlik ve stat girişi kuyruk bilgisi, yol durumu yorumları gibi uygulamalar da crowdsourcing mantığıyla çalışır.
- Mobil crowdsourcing uygulamalarının sınıflandırması (ekrandan, 00:35:00)
  - Tablo boyutları: Web-extend, Involvement (Participatory / Opportunistic / Both), Data wisdom (Individual / Collective), Contribution quality (Heterogeneous / Homogeneous), Incentives (Monetary, Service, Ethical, Entertainment), Human skill, Sensors, Location.
  - Örnek: Gigwalk.com ve Jana.com participatory, individual, heterogeneous, monetary; Waze.com "Both", collective, ethical/service, kamera; SmartP2P opportunistic, collective, homogeneous, service.
- Akıllı telefonun enerji profili (ekrandan, 00:40:00)
  - Slayttaki tablo (mW = mJ/s): CPU minimal kullanım 35, CPU standart kullanım 175, CPU pik 469, Wi-Fi boşta (bağlı) 34, Wi-Fi konumlama (dakika ortalaması) 125, Wi-Fi pik (uplink 123 Kbps, -58 dBm) 400, 3G konumlama 300, 3G meşgul 900, GPS açık (sabit) 275, OLED ekonomi modu 300, OLED tam parlaklık 676.
  - CPU standart kullanım minimal kullanımın 5 katı, pik kullanım yaklaşık 13,4 katıdır (python ile doğrulandı). Hoca bunu "12-13 kata kadar" diye aktardı.
  - Crowdsourcing'e katılmak (periyodik konum paylaşımı vb.) kullanıcıya bir enerji maliyeti getirir.
- SmartP2P (ekrandan, 00:45:00)
  - Cihazlar arası (P2P) paylaşımda bir Optimizer sunucusu kullanılır. Optimizer, üye telefonların konum bilgilerini ve hangi nesnelere sahip olduklarını bir look-up table'da tutar. Kullanıcı istediği resmi, dosyayı ya da videoyu Optimizer'a sorar, Optimizer en yakın telefonu bildirir ve indirme o telefondan yapılır.
  - Şemadaki adımlar: (a) Query, (b) Optimization (PF), (c) Decision making, (d) QRT, (e) Search, (f) Results of interest.
  - Hedefleri: aramada enerji tüketimini en aza indirmek, sorgu cevap süresini en aza indirmek, sorgunun recall oranını en yükseğe çıkarmak (ekrandan, 00:50:00).
  - Kullanım alanları: konferanslarda fotoğraf ve video paylaşımı (buluta gidip gelmek yerine yerelde), proxy sunucuların telefonlardaki karşılığı, afet anında baz istasyonu olmadan telefonların hop-by-hop haberleştiği ad hoc ağlar, kalabalık statlar. Röle (hop) olmak telefona maliyet getirdiği için kullanıcının bunu kabul etmesi gerekir.
  - Statlarda ve konserlerde binlerce telefonun senkron ışık gösterisi yapması da bir crowd uygulamasıdır; gecikme ve senkronizasyon zor bir problemdir.
- Sporda veri bilimi
  - Sporcuların üzerine sensörler bağlanarak kas hareketleri, takım koordinasyonu, harcanan enerji, laktik asit gibi bilgiler toplanır.
  - İyi oyuncunun vuruş ya da atış hareketi sensörlerle izlenip yeni öğrenenlerin hareketiyle karşılaştırılabilir (motor öğrenme).
- Mobile crowdsensing ve teşvikler (ekrandan, 00:55:00 ve 01:20:00)
  - Mobile crowdsensing, çok sayıda katılımcının telefonlarındaki ivmeölçer, jiroskop, pusula, mikrofon, kamera, GPS ve kablosuz ağ arayüzleriyle çevreyi algılamasıdır.
  - Teşvikler: Entertainment, Service, Money; başka bir çalışmada Altruism, Enjoyment, Reputation, Service, Payment.
- Crowdsensing problemleri (ekrandan, 01:30:00)
  - Katılımcı cihazların harcadığı fazla enerji (öğrenci önerisi, hoca kabul etti); blockchain de crowdsourcing örneği olarak görülebilir ve en büyük sorunu enerji tüketimidir.
  - Imbalanced data: veri belli yer ve saatlerde yığılır, diğer yerlerde eksik kalır.
  - Unreliable data: kasıt olmadan hatalı veri (bozuk sensör, konuda uzman olmayan kullanıcının yorumu).
  - Malicious data: sistemi yanıltmak için kasıtlı üretilen veri (sahte yorumlar).
  - Unbalanced crowd: veriyi üretecek grubun dengesiz dağılması (genç nüfusun ağırlıkta olması, anketin tek bölgede yapılması).
  - Lack of crowd: kişi ya da kaynağın az olduğu yerler (kırsal bölgeler, gidilmemiş yerler, yorumsuz ürünler). Baz istasyonu seyrekse konum doğruluğu da düşer.
- Çözüm yaklaşımları
  - Kimlik doğrulama: e-Devlet gibi güvenilir merkezler üzerinden giriş, cep telefonu numarasıyla doğrulama.
  - LoA (Level of Assurance): SMS ile OTP en yaygın yöntemdir; ileri seviyeler (LoA 4'e doğru) SIM kart düzeyinde şifrelenmiş doğrulamaya gider (Mobile Connect). SMS havadan gittiği için ele geçirilebilir; SIM kartı manipüle etmek telefon yazılımını manipüle etmekten zordur.
  - Satın almadan ya da kalmadan yorum yapılamaması, kullanıcının geçmişine göre ağırlık verilmesi (çok yerde kalmış, puanları dağılımlı kullanıcı daha güvenilir), verinin güncelliği.
- Grup seviyesi teşvik (ekrandan, 01:40:00)
  - Kullanıcılar gruplar hâlinde bir kredi veritabanına katkı yapar; grubun bir üyesinin kazandığı krediden diğer üyeler de yararlanır (aile içinde park uygulaması örneği). Bu, katkıyı hızlandırır.
  - Servis teşvikleri tablosu: park bilgisi (GPS), mobil gözetim videosu, ürün fiyatı paylaşımı (kamera), yeme alışkanlığı önerisi, sensör ağlarından veri toplama (ekrandan, 01:45:00).
  - Duty free fiyat paylaşımı ve market fişlerinin okutulmasıyla en uygun alışveriş listesi çıkarma örnekleri.
  - Parasal teşvik başlıkları: Online Mechanism Design, Task Assignment, Quality Control, Privacy Tradeoff (ekrandan, 01:50:00).
- MCN genel mimarisi (ekrandan, 01:50:00)
  - Service provider katmanında task decomposition, task recommendation, distribution, recomposition ve storage vardır. Sensing crowd (giyilebilir cihazlar, akıllı araçlar, telefon kullanıcıları) ve computing crowd (laptop kullanıcıları dahil) RSU, baz istasyonu ve Wi-Fi AP üzerinden bağlanır; son kullanıcılar request gönderir, result alır.
  - Zorluklar: katılımcıyı sistemde tutmak, dinamik topoloji (katılımcıların girip çıkması), bilginin heterojen kaynaklardan toplanması.
- Uygulama örnekleri (ekrandan, 01:55:00)
  - Hava kirliliği, su kalitesi, baz istasyonu ve Wi-Fi yayılım seviyeleri, akıllı navigasyon, akıllı park, akıllı trafik ışığı, sağlık izleme, hastalık teşhisi, yemek önerisi.
  - Güvenlik ve gizlilik zorlukları: Privacy Threats ve Reliability Threats (ekrandan, 02:05:00).
- Telsiz algılayıcı ağlara (wireless sensor networks) giriş
  - Askeri uygulamalarla başlamış ve bugünkü IoT'nin başlangıç noktası sayılır. Düğümler işlemci, haberleşme ve algılama birimi taşır; elle yerleştirilir ya da helikopter, uçak, mancınıkla saçılır.
  - Düğümler sabit, kendi etrafında dönen ya da hareketli olabilir. Hareket enerji ve donanım olarak maliyetlidir, bu yüzden statik düğüm tercih edilir; ama aynı bölgeye düşen düğümler aynı alanı kapsadığı için verim düşer.
  - İki kapsama alanı: algılama (sensing) ve haberleşme (communication). Algılama mesafesi genelde haberleşme mesafesinin yarısı kadardır (1:2).
  - Algılama yönü: omnidirectional (360 derece) ve directional (kamera, mikrofon gibi pasta dilimi).
  - Algılama modeli: binary (0/1) ve probabilistic (uzaklaştıkça olasılık 1, 0,9, 0,8 diye azalır, belli bir mesafeden sonra keskin düşer).
  - Kapsama problemleri: area coverage (en büyük alan), target coverage (en çok hedef), border coverage (giriş-çıkışı algılama). 3D kapsama problemleri yaygınlaşıyor.
  - Ağ türleri: underwater acoustic sensor networks, multimedia sensor networks. Haberleşmede ZigBee (IEEE 802.15.4) kullanılır.
  - Ağ ömrünü uzatma: fiziksel koruma, enerji hasadı (güneş, rüzgar, su, basınç, gönderilen dalga), uyku-uyanma döngüleri, veriyi düğümde işleyip yalnız önemli olanı gönderme.

## Hocanın Özellikle Vurguladığı Kısımlar

- Enerji testlerinde eşit şartlar
  - Ölçümler aynı ortamda, aynı şarj durumunda yapılmazsa sonuçlar karşılaştırılamaz. Android'de enerji ölçümünü bilimsel çalışmada yayımlamak dikkat ister.
- Crowdsourcing'de iş veriyi toplamakla bitmez
  - Toplanan veri olduğu gibi kullanılırsa hayal kırıklığı yaratır. En kritik konulardan biri verinin güvenilirliğidir; manipülasyon açıktır.
- Güvenilir sistem kurmak
  - Hoca bu konuların teknik görünmese de crowdsourcing sistemi kurarken çok iyi hesaplanıp uygulanması gerektiğini, kullanıcının sisteme olan güveninin çok önemli olduğunu söyledi. Ne kadar çok kullanıcı oylarsa, oylayan ne kadar çok oylama yaptıysa ve dağılım ne kadar genişse güvenilirlik o kadar net söylenebilir.
- Opportunistic ile participatory ayrımı
  - Kişinin emek harcamadan, doğal hareketinden ya da cihazından gelen veri opportunistic; geri bildirim vermek ya da veri toplamak için aktif katıldığı durum participatory'dir. Bütün yorumlar participatory'dir.
- Unreliable ve malicious data farkı
  - Birinde kasıt vardır (sistemi yanıltmak), diğerinde kasıtsız hata (bozuk sensör). Imbalanced data ile unbalanced crowd da farklıdır: biri verinin, diğeri veriyi üreten grubun dengesizliğidir.
- Kapsama sensör ağlarının temelidir
  - Kapsama düzgün sağlanamazsa sensör ağının anlamı kalmaz.
- Sensör ve sensör düğümü farklıdır
  - Düğüm bütün birimleri içerir; bir düğüm üzerinde birden fazla sensör olabilir. Algılamak ile haberleşmek bağımsızdır; düğümün haberleşme birimi uyurken algılama sürebilir.

## Kısa Tekrar Notları

- ML uygulamasında enerji: veri toplama + ön işleme + özellik çıkarımı + sınıflandırma.
- Ölçüm: yazılımsal (Battery Stats ve literatürdeki araçlar) ya da donanımsal (Monsoon). Aynı şartlar, şarj durumu sabit.
- Problem çözme: Intelligence → Design → Choice → Implementation.
- Enerji tablosu: CPU 35 / 175 / 469 mW; GPS 275; 3G meşgul 900; OLED tam parlaklık 676.
- SmartP2P: Optimizer + look-up table; hedef az enerji, kısa cevap süresi, yüksek recall.
- Teşvik: eğlence, servis, para (ayrıca altruism, reputation).
- Problemler: imbalanced data, unreliable data, malicious data, unbalanced crowd, lack of crowd (+ enerji).
- Çözümler: güvenilir kimlik (e-Devlet, telefon, LoA/SIM), satın alma/konaklama şartı, kullanıcı ağırlığı, güncellik.
- Grup seviyesi teşvik: ortak kredi veritabanı.
- MCN: service provider; sensing crowd ve computing crowd.
- WSN: algılama mesafesi ≈ haberleşme mesafesinin yarısı; binary ve probabilistic algılama; area, target, border coverage; ZigBee (IEEE 802.15.4); ağ ömrü için uyku-uyanma ve enerji hasadı.

## Detaylı Açıklamalar

- Enerji ölçümünde dikkat edilecekler
  - Telefonlarda enerji tüketimi bileşen bazındadır: CPU, Wi-Fi, hücresel radyo, GPS ve ekran farklı güç çeker. Slayttaki tabloya göre 3G meşgulken 900 mW ile en yüksek değerdir; OLED ekran tam parlaklıkta 676 mW, ekonomi modunda 300 mW çeker; GPS sürekli açıkken 275 mW harcar. Bu yüzden konum sürekli sorgulanırsa yüksek enerji tüketilir. <!-- BELİRSİZ: Hoca 00:39:45-00:40:09 arasında 3G ile Wi-Fi'yi karşılaştırdı ("yarısı kadar"); altyazı bozuk olduğu için karşılaştırmanın hangi satırlar arasında yapıldığı net değil. -->
  - Slaytta sütun başlığı "Megawatts of power (mW = mJ/s)" diye yazılmıştı. Ders sonrası not: mW miliwatt'tır (megawatt değil); hoca da değeri "35 milivat" diye doğru okudu.
  - Kısa süreli ölçümler araçların çözünürlüğü altında kalır. Bu yüzden aynı iş çok kez tekrarlanır, toplam tüketim tekrar sayısına bölünür ya da süreyle orantılanır.
- SmartP2P'nin mantığı
  - Her telefona tek tek sorgu atmak hem zaman hem enerji kaybıdır. Optimizer, üye telefonların konumunu ve sahip oldukları nesneleri bildiği için sorguyu en yakın kaynağa yönlendirir. Böylece konferans, stat ya da afet bölgesi gibi kalabalık ortamlarda buluta gitmeden yerel paylaşım yapılır. Afette esas darboğaz olayın yaşandığı yerdedir; veri hop-by-hop bu bölgeden çıkarılabilirse sonrası kolaydır.
- Veri güvenilirliği ve manipülasyon
  - Bir otelin kendi işletmecilerinin ya da tanıdıklarının yazdığı yorumlar, ürünü satan firmada çalışan birinin yüksek puanı, uygulamayı trollemek için topluca verilen düşük puanlar gerçek kullanıcılardan gelse bile veriyi bozar. Bunlar ancak ortak hareketlerin akıllı algoritmalarla incelenip filtrelenmesiyle dengelenebilir. Her yere 10 veren ya da her yere 2 veren kullanıcının puanı da aynı ağırlıkta değerlendirilmemelidir.
  - Verinin güncelliği kritiktir: bir restoran zamanla kötüleşebilir, iyileşebilir ya da formunu koruyabilir. Bu nedenle farklı puanlar ve kategoriler zaman içinde izlenmelidir.
- Lack of crowd ve konum doğruluğu
  - Telefonun konumu en az üç baz istasyonundan gelen sinyal gücüyle üçgenleme mantığıyla hesaplanır. Baz istasyonlarının kilometrelerce seyrek olduğu kırsal bölgelerde hem veri toplanamaz hem de gelen konumun doğruluğu düşer.
- Akıllı trafik ışığı
  - Hoca dinamik trafik ışığı yönetimini henüz yaygın görmediğini söyledi. Burada bir ödünleşim (trade-off) vardır: ışık süreleriyle çok oynanırsa yeşil dalga bozulur ve akış aksar, daha çok yakıt harcanır. Yeşil dalga sabit bir programdır, anlık trafik karakteristiğini öğrenmez; gece saatleri gibi trafiğin değiştiği zamanlarda dinamik ayar daha uygulanabilir.
- Sensör ağlarında enerji
  - Düğümler sahaya atıldıktan sonra kolay yenilenemez, bu yüzden ağ ömrü (network lifetime) en uzun tutulacak şekilde konumlandırma ve veri akışı tasarlanır. Uyku-uyanma zaman dilimleriyle yapılabilir; gönderen düğüm, alıcının uyanık olduğu periyotta bir sonraki turda veri göndereceğini bildirebilir. Sıcaklık izlemede 30 saniye-1 dakika geç algılamak sonucu değiştirmez, ama düşman giriş-çıkışı izleniyorsa düğüm uzun süre uyutulamaz.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
