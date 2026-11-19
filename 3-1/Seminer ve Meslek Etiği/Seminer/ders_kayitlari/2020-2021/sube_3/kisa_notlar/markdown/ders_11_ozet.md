# Ders 11 Çalışma Özeti

## Genel Konular

- Öğrenci sunumları ve sunum sonrası tartışma
  - Bu derste sekiz öğrenci kısa sunumlarını yaptı. Her sunumdan sonra soru-cevap açıldı; dinleyicilerden soru gelmediğinde hoca soru sordu, konuyu genişletti ya da sunum tekniğine dair geri bildirim verdi.
- Sunum 1: Altın oran (ekrandan, 00:05:00)
  - Tanım: Bir bütün uzun ve kısa iki parçaya bölündüğünde, uzun parçanın kısa parçaya oranı bütünün uzun parçaya oranına eşitse bu orana altın oran denir: $\frac{a}{b} = \frac{a+b}{a}$.
  - $b = 1$ alınınca $a^2 - a - 1 = 0$ denklemi çıkar; uzunluk pozitif olduğundan pozitif kök alınır: $\varphi = \frac{1+\sqrt{5}}{2} \approx 1{,}618...$ Altın oran $\varphi$ ile gösterilen irrasyonel bir sayıdır.
  - Altın spiral: Bir altın dikdörtgen bir kare ve daha küçük bir altın dikdörtgene bölünür; işlem tekrarlanır ve her kareye çeyrek çember çizilerek spiral elde edilir.
  - Fibonacci dizisi 0 ve 1 ile başlar, her terim önceki iki terimin toplamıdır. Ardışık iki terimin oranı (2/1 = 2, 3/2 = 1,5, 5/3, 8/5 ...) terimler büyüdükçe altın orana yaklaşır.
  - Sunuma göre altın oranın görüldüğü yerler: papatya, kozalak, salyangoz kabuğu, örümcek ağı, kar tanesi, galaksiler, insan yüzü (yansıda $b/a = 1{,}618...$ oranları; ekrandan, 00:05:00), Mısır piramitleri, Parthenon, Mona Lisa ve Venüs pentagramı. Bu yaygınlık nedeniyle "ilahi oran" diye de anılır.
- Sunum 2: Efes Antik Kenti (ekrandan, 00:10:00)
  - Antik çağın önemli liman kentlerinden biridir; Roma devrinde Asia eyaletinin başkenti, politik, ekonomik ve ticari merkezdir. Artemis Tapınağı (dünyanın yedi harikasından biri) sayesinde önemli bir din merkezidir. Kent tarihi boyunca dört kez yer değiştirmiş, bugün gezilen Efes Bülbül Dağı ile Panayır Dağı arasındaki üçüncü kuruluş yeridir. 2015'te UNESCO Dünya Mirası Listesi'ne girmiştir (ekrandan, 00:10:00).
  - Kuruluş efsanesine göre Atina kralının oğlu Androklos kenti kurmuştur; efsane Hadrianus Tapınağı'nın girişindeki yazıtta anlatılır. <!-- BELİRSİZ: efsanenin ayrıntısı 00:10:14-00:10:42 arasında altyazıda yok. -->
  - Yerleşim MÖ 8000'lere, Çukuriçi Höyük'e uzanır; sonra Ayasuluk'a taşınır. Kent Roma döneminde altın çağını yaşar, sonra Bizans, Selçuklu, Aydınoğulları ve Osmanlı yönetimine geçer; bugün İzmir'in Selçuk ilçesindedir.
  - Mimari: resmi ve kutsal yapılar düzlükte, konutlar yamaçtadır; caddeler birbirini dik keser (ızgara plan). Nüfusu yaklaşık 200-250 bin olan büyük bir metropoldü; limanını kaybedince önemini yitirdi.
  - Yapılar: Liman Caddesi, 25 bin kişilik Büyük Tiyatro, Celsus Kütüphanesi (Celsus'un oğlu tarafından babasını onurlandırmak için yaptırılmış, aynı zamanda anıt mezar; sunuma göre fazilet, ilim ve zekâ gibi erdemleri temsil eden dört heykel <!-- BELİRSİZ: dördüncü erdem altyazıda "kader" diye geçiyor, büyük olasılıkla Whisper hatası. -->), Agora, Oktagon (Kleopatra'nın kız kardeşi IV. Arsinoe'nin mezarı olduğu düşünülür), Hadrianus Kapısı, Yamaç Evler, Skolastika Hamamları, Hadrianus Tapınağı, Traianus Çeşmesi, Herakles Kapısı, Kuretler Caddesi, Devlet Agorası, Bazilika, meclis binası, Meryem Kilisesi ve belediye binası Prytaneion.
- Sunum 3: Büyük veri ve yapay öğrenme (ekrandan, 00:20:00)
  - Veri, bilgisayar bilimleri bağlamında bilgisayarın işleyebileceği forma dönüştürülmüş gerçekler topluluğudur. Depolama biçimine göre üç tür ele alındı: tablo verisi, görüntü verisi (MNIST rakam veri seti, UCF101 video veri seti) ve metin verisi.
  - Büyük verinin iki tanımı: tek bir kişisel bilgisayara sığmayan veri; yapay öğrenme bağlamında analiz edilip anlamlı ve işlenebilir hale getirilmiş veri.
  - Doğuşu: Verinin dijital ortamda birikmesi ve büyük şirketlerin kullanıcı verisini toplamasıyla (Google 1998, Facebook 2004, YouTube 2005, Twitter 2006; metin, görüntü ve kişisel bilgiler) dünyanın her yerinden erişilebilir hale geldi (ekrandan, 00:20:00).
  - Büyük verinin boyutları: hacim, hız, çeşitlilik, doğrulama ve değer. Büyümede en belirgin olanlar hacim ve hızdır.
  - Akış: ham veri, veri mühendisi tarafından işlenir; yapay öğrenme algoritmaları veriden çıkarım yapar; yapay zekâ sistemi karar verir.
  - Avantaj: Derin öğrenmede veri arttıkça başarı artar; geleneksel makine öğrenmesinde başarı erken bir asimptota ulaşır. Dezavantaj: veri miktarı arttıkça işleme süresi çok uzar; GPU ve TPU'lar bunu azaltsa da sorun sürer. Sınır: Her iki yaklaşımda da başarı eninde sonunda bir asimptota ulaşır, %100 başarı garanti edilemez.
  - Araçlar: Derin öğrenmede Python, C++ ve Julia; geleneksel makine öğrenmesinde ayrıca R. TensorFlow (Google), PyTorch (Facebook); C++ için Torch; Julia için Koç Üniversitesi'nden Deniz Yüret'in geliştirdiği Knet kütüphanesi. Julia matris işlemlerinde hızlıdır ama topluluğu dardır.
- Sunum 4: Bulut oyun (cloud gaming) (ekrandan, 00:30:00)
  - Bulut bilişimi kullanarak düşük donanımla yüksek performanslı oyun oynatan hizmettir. Oyun kullanıcının cihazında değil, hizmet sağlayıcının sunucusunda çalışır; kullanıcının komutu orada işlenir, çıktı internet üzerinden görüntü olarak gönderilir.
  - Gereksinimler: hızlı ve kararlı internet (kablolu bağlantı gecikmeyi azaltır), video oynatıp internete bağlanabilen herhangi bir cihaz, sunucuya coğrafi yakınlık.
  - Avantajlar: pahalı donanıma gerek kalmaz, her platformdan (telefon, televizyon, akıllı buzdolabı) oynanabilir, yüzlerce gigabaytlık indirme ve depolama gerekmez, bazı servisler ücretsiz oyun verir.
  - Dezavantajlar: çevrim dışı oynanamaz, bağlantı zayıfsa görüntü bozulur, gecikme rekabetçi oyunlar için hâlâ yüksektir, yüksek bant genişliği ister.
  - Genel eğilim: satın almadan kiralamaya geçiş (müzik ve dizi servisleri gibi); güçlü donanım yerine güçlü bağlantı.
- Sunum 5: Video oyunlarında DRM (ekrandan, 00:40:00 ve 00:45:00)
  - DRM (Digital Rights Management, dijital haklar yönetimi), telifli dijital medyanın lisans haklarını kontrol eden sistemdir; satış sonrası korsanla mücadelede kullanılır. Oyunlarda amaç korsanı engellemek ve çevrim içi oyunlarda hileyi önleyip adaleti sağlamaktır.
  - Uygulamalar: lisans doğrulama (çevrim içi aktivasyon ya da daimi çevrim içi zorunluluk, "always-on DRM") ve dosya doğrulama (oyun başlarken ya da sürekli arka planda) (ekrandan, 00:40:00). Bir oyunda birden fazla DRM bulunabilir.
  - Zararlar: DRM lisansı oyunun maliyetini ve fiyatını artırır; daimi bağlantı isteyen oyunlar sunucu yetmezse oynanamaz (2013 SimCity örneği); sürekli çalışan DRM sistem kaynağı tüketir (Denuvo, Abzû oyunundaki yükleme süreleri); kernel seviyesindeki DRM güvenlik ve performans sorunu yaratır.
- Sunum 6: Kutsal Roma İmparatorluğu (ekrandan, 00:50:00 ve 00:55:00)
  - 962-1806 arasında (844 yıl) Orta Avrupa'da hüküm süren, Alman Krallığı temelli ama birçok hanedan, prenslik, piskoposluk ve imparatorluk şehrinden oluşan gevşek bir yapıdır. Modern Almanya ve Avusturya'nın temelidir.
  - I. Otto 962'de taç giydi; son imparator Napolyon Savaşları sırasında tahttan çekilip imparatorluğu feshetti.
  - İmparatorun yetkisi yerel güçlerce sınırlandırıldı; merkezileşme girişimleri papalık ve prenslerin direnciyle karşılaştı. Süreç 11. yüzyıldaki atama kavgasıyla başlar, 1648 Vestfalya Barışı ile sonuçlanır.
  - İmparatorluk diyeti (Reichstag) yasama meclisi değil, müzakere forumudur; üç organdan oluşur: Elektörler Meclisi (sayı 1356 Altın Boğa ile 7, 1648'de 8, 1692'de 9, 1777'de yeniden 8), Prensler Meclisi (laik ve ruhani prensler; 1800'de 100 sandalyenin 37'si ruhani, 63'ü laik) ve İmparatorluk Şehirleri Meclisi (Svabya ve Ren grupları; resmi katılım 1648) (ekrandan, 00:50:00).
  - Ordu (Reichsarmee) 1422'de kuruldu; imparatorun değil, tehlike anında üye devletlerin birliklerinin birleşmesiyle oluşan bir orduydu.
  - Din: 1555'e kadar yalnız Katoliklik resmîydi; 1555 Augsburg Barışı ile Lutherci, 1648 Vestfalya ile Kalvinist mezhep tanındı. "Cuius regio, eius religio" ilkesiyle bir toprağın resmi dini o toprağın yöneticisinin dini sayıldı.
- Sunum 7: Uçaklarda fren sistemleri (ekrandan, 01:00:00 ve 01:05:00)
  - Üç fren sistemi: tekerleklerdeki disk frenler, kanatlardaki spoiler'lar ve motorlardaki ters itme (thrust reverser).
  - Disk frenler hidrolik ya da pnömatik çalışır; kinetik enerji ısıya dönüşür, sunuma göre sıcaklık 1400 dereceyi aşabilir. Çelik yerine kullanılan karbon frenler hafiftir, yakıt tüketimini azaltır.
  - Spoiler'lar kanat üst yüzeyindeki panellerdir; teker koyduktan sonra kanadın hâlâ ürettiği kaldırma kuvvetini bozarak uçağın pistte kalmasını sağlar (ekrandan, 01:00:00). Havada hız kesmede de kullanıldıkları için "speed brake" de denir. Yaklaşmada ise flap'ler açılarak düşük hızda kaldırma korunur.
  - Thrust reverser, motor itişini yaklaşık 45 derecelik açıyla öne yönlendirerek uçağı yavaşlatır; fren ve tekerlek ömrünü uzatır. Küçük jetlerde motor arkasındaki kapaklar (bucket doors) açılır; büyük yolcu jetlerinde soğuk hava akışı (cold stream) motor gövdesindeki açıklıktan öne yönlendirilir (ekrandan, 01:05:00).
- Sunum 8: 2011 NBA playoff'ları (ekrandan, 01:10:00 ve 01:15:00)
  - Her konferanstan ilk sekiz takım playoff'a girer; parantez içindeki sayılar konferans sıralamasıdır. Doğu yansıları mavi, Batı yansıları kırmızı fonla verildi.
  - Batı: 8. sıradaki Memphis, Spurs'ü eleyerek tarihindeki ilk playoff serisini kazandı; Lakers, Hornets'ı zor geçti; Dallas, Portland'ı geçti (Brandon Roy'un dördüncü maçtaki dönüşü); Thunder, Nuggets'ı 4-1 yendi. Yarı finalde Thunder, Grizzlies'i 4-3 yendi (Durant son maçta 39 sayı; ekrandan, 01:10:00); Dallas, Lakers'ı süpürdü.
  - Doğu: Bulls (MVP Derrick Rose), Heat (LeBron James, Dwyane Wade ve Chris Bosh üçlüsü), Celtics ve Hawks tur atladı; konferans finalinde Heat, Bulls'u 4-1 yendi.
  - Final: Mavericks 4-2 Heat; Finaller MVP'si Dirk Nowitzki (26,0 sayı, 9,7 ribaund, 2,0 asist); LeBron James dördüncü maçta 45 dakikada 8 sayıda kaldı (ekrandan, 01:15:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Konuyu ilgi ve deneyim alanından seçmek
  - Bilgi birikiminin ortalamanın üstünde olduğu bir konuda sunum yapan kişi rahat konuşur ve gelen sorulara rahat cevap verir; büyük veri sunumu bunun örneği olarak gösterildi.
- Her kavramı kullanmadan önce açıklamak
  - "Diyet" kavramı açıklanmadan kullanıldığı için takılan hoca, her kavramın ilk kullanımdan önce tanıtılması gerektiğini, bunun akademik yazı ve teknik raporda da çapraz kontrol edilmesi gerektiğini vurguladı.
- Dinleyici analizi ve terimler
  - Sunumun kime yapıldığı, dinleyicinin bilgi düzeyi önceden düşünülür; hangi terimin açıklanacağı buna göre ayarlanır ("bench" terimi örneği).
- Yansı tasarımında tutarlılık
  - Bir sunumun genel yapısında tutarlılık önemlidir. Fon renginin değişmesi ilk bakışta tutarsızlık gibi görünse de bir anlam taşıyorsa (Doğu mavi, Batı kırmızı) bilinçli ve uygun bir konsepttir.
- Soru-cevabın amacı
  - Seminer kapsamında sorulan soruların doğrusu yanlışı yoktur; amaç dinleyiciyle etkileşim ve tartışmadır.

## Kısa Tekrar Notları

- Altın oran: $\frac{a}{b} = \frac{a+b}{a}$, $\varphi = \frac{1+\sqrt{5}}{2} \approx 1{,}618$; ardışık Fibonacci terimlerinin oranı $\varphi$'ye yakınsar.
- Efes: Asia eyaleti başkenti, Artemis Tapınağı, ızgara plan, Celsus Kütüphanesi, 2015 UNESCO.
- Büyük veri: hacim, hız, çeşitlilik, doğrulama, değer; derin öğrenme veriyle ölçeklenir, geleneksel makine öğrenmesi erken doyar; işleme süresi büyük sorun.
- Bulut oyun: oyun sunucuda çalışır, kullanıcıya görüntü akar; gecikme ve bant genişliği temel kısıt.
- DRM: lisans doğrulama ve dosya doğrulama; maliyet, daimi bağlantı, performans ve kernel seviyesi güvenlik sorunları.
- Kutsal Roma İmparatorluğu: 962-1806, gevşek konfederasyon, diyetin üç meclisi, 1555 Augsburg, 1648 Vestfalya.
- Uçak frenleri: disk fren, spoiler (kaldırmayı bozar), thrust reverser (itişi öne yönlendirir).
- Sunum tekniği: konu seçimi, kavramı önce tanımlama, dinleyiciye göre terim açıklama, görsel tutarlılık.

## Detaylı Açıklamalar

- Altın oran sunumunda tanım, iki parçalı bir çubuk üzerinden kuruldu. Uzun parça $a$, kısa parça $b$ ise $\frac{a}{b} = \frac{a+b}{a}$ eşitliği yazılır. $b = 1$ alınınca $a = 1 + \frac{1}{a}$, yani $a^2 - a - 1 = 0$ bulunur. Kökler $\frac{1 \pm \sqrt{5}}{2}$'dir; uzunluk negatif olamayacağından $\varphi = \frac{1+\sqrt{5}}{2} \approx 1{,}618$ seçilir. Fibonacci dizisi (0, 1, 1, 2, 3, 5, 8, 13, ...) ile bağlantı ardışık terim oranlarından görülür: 2/1 = 2, 3/2 = 1,5, 5/3 ≈ 1,667, 8/5 = 1,6, 13/8 = 1,625; oranlar $\varphi$'nin iki yanında salınarak ona yaklaşır. Hoca, altın oranın salyangozdan galaksilere kadar farklı ölçeklerde görülmesini evrenin genel kurallar üzerine kurulu olmasının bir örneği olarak yorumlamayı önerdi; insanların bu orana ilgisini de mükemmelliğe ulaşma arzusuna bağladı.
- Büyük veri sunumunda veriden karar almaya giden zincir anlatıldı: ham veri toplanır, veri mühendisi temizler ve işler, öğrenme algoritması örüntü çıkarır, yapay zekâ sistemi karar verir. Derin öğrenmenin geleneksel yöntemlere göre üstünlüğü büyük veride ortaya çıkar: veri arttıkça başarı artmaya devam eder. Bedeli işleme süresidir. Hocanın sorusu üzerine pratik araçlar tartışıldı; hoca Julia'nın taşınabilirlik sorununun çalışma ortamını konteyner ya da mikroservis haline getirerek aşılabileceğini önerdi; sunan öğrenci asıl sorunun dar topluluk ve kütüphanelerin olgunlaşmaması olduğunu söyledi. Python'ın başka platformlarla tümleşmesi için Pygame (pekiştirmeli öğrenme sonuçlarını oyunda gösterme), Flask (web arayüzü), grafik arayüz kütüphaneleri ve Node.js/NoSQL üzerinden veri çekme örnekleri verildi.
- Bulut oyun sunumunun soru-cevabında hoca, yeni bir hizmetin mevcut iş süreçlerini sarstığını, lisans anlaşmazlıklarının (bazı oyunların bulut servisinden çekilmesi, uygulama mağazası ile oyun firması arasındaki komisyon anlaşmazlığı) bunun örneği olduğunu ve zamanla bir orta yol bulunduğunu belirtti.
- DRM sunumunda doğrulama yöntemleri ile zararlar birlikte değerlendirildi. Daimi çevrim içi zorunluluk, sunucu kapasitesi yetersiz kaldığında oyunu satın alan herkesi oyundan mahrum bırakır. Sürekli arka planda çalışan doğrulama oyuna ayrılan kaynakları azaltır. Kernel seviyesinde çalışan DRM işletim sistemini doğrudan etkilediğinden oyun kapalıyken bile güvenlik ve performans riski taşır. Tartışmada DRM kullanmayan yayıncıların iyi oyunun DRM olmadan da satılacağı görüşü aktarıldı; hoca, zaten performans sorunu olan bir oyuna DRM ile ek yük bindirmenin mantıklı olmadığını söyledi.
- Kutsal Roma İmparatorluğu sunumunda imparatorluğun merkezi bir devlet olmadığı vurgulandı. Diyet, bugünkü parlamentolar gibi yasa yapmaz; elektörler imparatoru seçer, prensler ve şehirler müzakere eder, son kararı imparator verir. Sunan öğrenci bunu Osmanlı meşrutiyetine benzetti. Hoca atama kavgasının yaklaşık 650 yıl sürdüğü izlenimini sorguladı; sunan öğrenci bunun aralıksız bir savaş değil, her imparator seçiminde yeniden alevlenen bir yetki mücadelesi olduğunu açıkladı.

> **Ders sonrası not:** Sunumda atama kavgasının 1648 Vestfalya ile sonuçlandığı söylendi. Atama kavgası (investiture controversy) Almanya'da büyük olasılıkla 1122 Worms Konkordatosu ile sona ermiştir; hocanın derste baktığı kaynak da İngiltere'de 1103-1107 arasına yoğunlaşan bir anlaşmazlıktan söz ediyordu. 1648 ise büyük olasılıkla prenslerin özerkliğinin kalıcılaştığı tarihtir.

> **Ders sonrası not:** Sunumda imparatorların yalnız Habsburg hanedanından seçildiği söylendi; bu büyük olasılıkla yalnız 15. yüzyıldan sonrası için geçerlidir. Sunumun kendisi de ilk imparatorlardan I. Otto'nun başka bir hanedandan olduğunu belirtti.

- Uçak frenleri sunumunda üç sistemin farklı fiziksel ilkelere dayandığı görüldü: disk fren sürtünmeyle kinetik enerjiyi ısıya çevirir; spoiler kanat üstündeki hava akışını bozarak kaldırma kuvvetini yok eder ve tekerleklerin yere basmasını sağlar; thrust reverser motorun itişini ters yöne çevirir. Hocanın sorusu üzerine sunan öğrenci, savaş uçaklarında bu yöntemin bildiği kadarıyla kullanılmadığını, onun yerine fren paraşütü kullanıldığını söyledi.

> **Ders sonrası not:** Bazı savaş uçaklarında da (örneğin Panavia Tornado, Saab Viggen) büyük olasılıkla thrust reverser bulunmaktadır; derste hoca da bunu ayrıca araştıracağını söyledi.

- NBA sunumunun soru-cevabı sunum tekniğine dönüştü. "Bench" (yedek oyuncu) teriminin ve yansılardaki parantez içi sayıların (konferans sıralaması) açıklanmamış olması, dinleyicinin arka planına göre hangi terimlerin açıklanacağının önceden planlanması gerektiğini gösterdi. Fon renklerinin Doğu için mavi, Batı için kırmızı seçilmesi ise görsel tutarlılığın anlam taşıyan bir kodlamayla sağlanabileceğinin örneği oldu.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
