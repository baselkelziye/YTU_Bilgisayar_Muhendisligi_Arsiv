# Ders 3 Genişletilmiş Notu: Kablosuz Algılayıcı Ağlar (WSN): Özellikler, Yerleşim, Kapsama ve Uygulamalar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kablosuz algılayıcı ağlara giriş
- 2. Sensör düğümü donanımı
- 3. Ağ yapısı, enerji ve ağ ömrü
- 4. WSN'lerin tarihçesi ve IoT'ye geçiş
- 5. WSN'lerin karakteristikleri
- 6. Kablosuz ağ zorlukları ve ağ gereksinimleri
- 7. Yerleşim, kapsama ve bağlantılılık
- 8. Ağ topolojileri ve bakım
- 9. Protokol tasarım zorlukları, gizlilik ve güvenlik
- 10. WSN uygulamaları
- 11. WSN ile IoT karşılaştırması, RFID ve beacon'lar
- Örnek Sorular

## 1. Kablosuz algılayıcı ağlara giriş

Bu derste kablosuz algılayıcı ağlar (Wireless Sensor Networks, WSN) işlendi. Konu başlı başına ayrı bir ders olacak genişliktedir, ama mobil teknolojilerin yapı taşlarından biridir: bugün sensörlerden ve IoT ağlarından söz ediyorsak, bunun ilk adımı WSN'lerdir. Türkçede "kablosuz algılayıcı ağ" denir; hoca daha doğru karşılığın "telsiz algılayıcı ağ" olduğunu belirtti. Ders slaytları başka bir üniversitenin kablosuz sensör ağları dersinden alınmıştı (slaytlarda "CMPE 58C" altbilgisi görünüyor). Dersin amacı WSN'lerin hangi problemleri içerdiğini, hâlâ kullanılıp kullanılmadığını ve zamanla IoT'ye nasıl evrildiğini görmekti.

Bir WSN düğümünün amacı önce ortamı algılamak (sense), yani etraftaki bilgiyi toplamak, bu bilgi üzerinde küçük işlemler yapmak ve bilgiyi merkeze aktarmaktır. Tek görevi budur. Düğümler, IoT cihazları gibi üzerinde büyük işlemler yapılsın diye tasarlanmamıştır ve herhangi bir fiziksel nesneye gömülü (entegre) değildir. Hoca bunu IoT ile en önemli farklardan biri olarak vurguladı.

Düğümler özellikle açık ve erişilmesi güç alanlardan bilgi toplamak için kullanılır: orman, tarla, askeri operasyon yapılan dağlık arazi gibi. Araçlarla ya da helikopterle bölgeye bırakılabilir, bahçe gibi özel alanlarda elle yerleştirilebilirler. Kapalı alanda (indoor) pek kullanılmazlar; asıl kullanım alanları açık alandır (outdoor). Enerji ve kaynak kısıtları vardır, düşük veri hızıyla (low data rate) haberleşirler ve bilgiyi birbirleri üzerinden merkeze taşırlar. Doğrudan merkezle haberleşme yetenekleri neredeyse yoktur; bu da topolojisi değişken bir ağ ortaya çıkarır. Düğümler o bölgeden veri toplayacak biçimde kendilerini örgütler.

WSN'ler kablosuz ad-hoc ağlara benzer. Ama ad-hoc ağlarda eşler arası (peer-to-peer) iletişim varken, WSN'de bire-çok (one-to-many) ya da yayın (broadcast) iletişimi gerçekleşir: bir düğüm bilgiyi etrafındaki düğümlere gönderir, onlar da diğer düğümlere göndererek bilgiyi merkeze kadar ulaştırır. Günün sonunda ortama dağıtılan düğümlerden gelen bilgiler bölgenin izlenmesini sağlar: tarımsal alanda sulama gerekip gerekmediği ya da askeri alanda bir düşman hareketi olup olmadığı anlaşılabilir.

## 2. Sensör düğümü donanımı

### 2.1 Temel bileşenler

Bir sensör düğümünün temel donanımı slaytta bir blok diyagramla gösterildi (ekrandan, 00:25:00):

```text
                 Sensors/Actuators
                        |
Memory/Storage ---- Processor ---- (GPS, isteğe bağlı)
                        |
                 Radio Transceiver

        Power Source: Battery/Harvest
```

Slayttaki açıklamalar:

- Sensörler: sıcaklık, ışık, nem, akustik, basınç, kimyasal sensörler, ivmeölçerler vb.; çıkış birimleri olarak hoparlör, LED, buzzer.
- İşlemci: çoğunlukla 8 ya da 16 bit, 16 MHz; işletim sistemi TinyOS, Contiki.
- Bellek: birkaç kB RAM ve birkaç on kB flash bellek.
- GPS: ölçümlerin konum damgalı olması için (isteğe bağlı, kesik çizgiyle gösterilmiş).
- Radyo: düşük hızlı, düşük güçlü, kısa menzilli; ISM bantlarında 50-250 kbit/s.
- Güç kaynağı: pil ya da enerji hasadı (harvest).

Hoca radyo alıcı-vericinin haberleşme, güç kaynağının enerji için olduğunu söyledi. Zamanla düğümler yalnız algılamakla kalmayıp bilgi geldiğinde fiziksel bir iş yapmak, aksiyon almak için eyleyiciler (actuator) de taşımaya başladı. Sensörler genelde mobil değildir, atıldıkları yerde kalırlar. Ama kendi etrafında dönebilen kamera ve mikrofon gibi, maliyeti yüksek olsa da hareket yeteneği olan mobil sensör ağları da kullanıldı.

Düğümler çok küçük oldukları için hataya yatkındır; zamanla bozulabilirler ve ürettikleri veri hatalı olabilir. Bu yüzden aynı bölgeden gelen fazla (redundant) veriden yararlanılır: hatalı bir veri üretildiğinde diğer verilerle karşılaştırılarak düzeltilebilir. Bir bölgede birden fazla sensör olması, biri bozulunca diğerinin hizmeti sürdürmesi anlamına da gelir. Düğümler rastgele dağıtıldığı için, elle yerleştirmedeki gibi her yeri mükemmel kapsayan bir yerleşim oluşmaz; bunun için alınan önlemler yerleşim bölümünde anlatıldı.

### 2.2 Örnek düğüm: Tmote Sky

Gerçek bir düğüm olarak Tmote Sky gösterildi. Üzerine nem, sıcaklık gibi farklı sensörler ve radyo dalgalarını gönderip alacak bileşenler yerleştirilmiştir. Slayttaki özellikler (ekrandan, 00:30:00):

- 2,4 GHz, 250 kbps IEEE 802.15.4 CC2420 radyo, menzil: onlarca metre
- MSP430 mikrodenetleyici, 10k RAM, 48k flash
- 1 MB harici flash
- USB ile programlama
- Kart üzerinde nem, sıcaklık ve ışık sensörleri
- 3 V'ta güç tüketimi: mcu+radyo yaklaşık 20 mA, yalnız mcu yaklaşık 2 mA, bekleme (standby) 20 µA

Hoca haberleşme yeteneğinin çok sınırlı olduğunu vurguladı: yaklaşık 250 kilobit/saniye, IEEE 802.15.4 standardı ve onlarca metre mertebesinde menzil. Bu hız, WSN'ler ilk çıktığında nem, sıcaklık, basınç gibi fiziksel verileri aktarmaya yetiyordu. Ama zamanla ortamdan görüntü, video ve ses taşıyan kablosuz çoklu ortam sensör ağları (wireless multimedia sensor networks) ortaya çıkınca bu bant genişliği yetmemeye başladı. Bu ağlarda veri tek bir rota üzerinden değil, çok yollu (multi-path) yönlendirmeyle gönderilmeye çalışılır.

Düğümler zamanla küçüldü, bozuk para boyutuna kadar inebildi; ama bütün düğümler böyle değildir, daha büyükleri de tasarlandı. Hoca, nano ağlar ve nano iletişim devreye girdikçe bu yapıların insan üzerinde de bir ağ oluşturacak biçimde kullanılacağını söyledi.

## 3. Ağ yapısı, enerji ve ağ ömrü

### 3.1 Algılama ve iletme görevleri

Bir düğümün iki temel görevi vardır: algılamak ve kendisine gelen bilgiyi iletmek (forward). Algılama çok enerji tüketmez, ama veriyi alma ve gönderme çok enerji ister. Bu yüzden bu işi sık yapan, yani ağda köprü konumunda olan düğümler enerjilerini daha çabuk bitirir. Çözüm olarak iletme görevinin başka düğümlere devredildiği algoritmalar geliştirilir. Örneğin 10 sensörü temsil eden bir küme başı (cluster head) varsa, bu görev belirli tur sayısında değiştirilir; bir düğüm 10 turda enerjisinin bir kısmını harcadıktan sonra görev diğerlerine geçer.

### 3.2 Ağ ömrü (network lifetime)

Ağ ömrünün farklı tanımları vardır. Derste verilen tanıma göre ağın her düğümüne, düğümün enerjisi bitmeden erişilebildiği sürece ağ yaşıyordur. Ağdaki herhangi bir düğüme erişilemediğinde ağ ömründe düşüş başlar. Amaç, bütün ağdaki düğümlerin enerji tüketimini dengeli biçimde azaltmaktır.

"Önce beş düğümü bitirelim, sonra geri kalanlarla devam edelim" gibi bir yaklaşım tercih edilmez. Bir ara düğümün başka alternatifi yoksa, o düğüm öldüğünde ona bağlı uçtaki sensörler veri üretse bile bu veri merkeze ulaştırılamaz. Ağ ömrünü bu anlamda en uzun yapmak için çeşitli çözümler vardır.

### 3.3 İşlem kapasitesi ve uçta işleme

Düğümlerin üzerindeki mikroişlemciler hem işlem gücü hem saklanabilecek bilgi miktarı açısından düşük kapasitelidir. IoT cihazları ise çoğu durumda sürekli güce bağlıdır ve veriyi ciddi biçimde işleyebilir. Bu yüzden IoT'de uçta ya da yerinde işleme (edge computing, in-situ processing) yapılabilir ve teşvik edilir; sensör ağlarında bu sınırlıdır, bilgi çoğunlukla merkeze gelir ve merkezde işlenir. Zamanla bazı düğümlerin daha yetenekli ve daha fazla enerjili yapılması, bu özel düğümlerin bir ölçüde işlem yapmasını mümkün kıldı. Ama genel olarak WSN'de bu işleri ancak heterojen yapıdaki daha yetenekli düğümler yapabilir.

## 4. WSN'lerin tarihçesi ve IoT'ye geçiş

WSN'lerin tarihi 1993 yılına kadar gider. O günlerden 2010'lara kadar yükselen bir trendle kullanıldılar. IEEE 802.15.4 hâlâ onlar için haberleşme standardıdır. 2010'dan sonra, özellikle şehir hayatında, bayrağı ağırlıklı olarak IoT'ye devrettiler.

Bunun birkaç sebebi var. Birincisi, WSN'de tek bir düğüme doğrudan erişme şansı yoktur; IoT'de ise her cihazın teknik olarak bir IP adresi vardır. Sensör ağlarında yalnız coğrafi olarak belirli bir bölgeden bilgi toplanır, belirli bir düğümün bilgisi talep edilemez. Bu kısıtı aşmak için IoT ağlarına yönelim arttı ve IoT ağları WSN'leri kapsayan yeni bir sürüm hâline geldi. Hoca, IoT'nin WSN'nin yerini tamamen aldığını söylemenin doğru olmadığını, çünkü IoT ağlarının içinde hâlâ WSN'lerin kullanılabildiğini belirtti: WSN, yeni yetenekleriyle yeni bir biçime büründü.

### 4.1 Tipik bir WSN: orman yangını örneği

Slaytta tipik bir WSN gösterildi (ekrandan, 00:35:00): iki ayrı sensör bulutu (düğüm kümesi) vardır; her bulutta düğümler çok atlamalı bir yol üzerinden bir sink'e bağlanır. İki sink de "Internet, Satellite" bulutuna, o da görev yöneticisine (Task Manager) bağlıdır. Slaytta anahtar sözcükler "Ad Hoc and Multi-hop" olarak verilmiş.

Görev bir ormanda yangın olup olmadığını izlemek olsun. İki farklı bölgedeki ormandan bilgi gelir. Her düğüm ya kendi üzerinden ya da bir küme başında toplanan bilgiyle veriyi merkeze gönderir; böylece hangi bölgede hangi sıcaklığın olduğu izlenir. Belirli bir sıcaklığın aşıldığı tespit edilirse o bölgeye (tek bir düğüme değil, bölgeye) bir drone gönderilebilir, bölgede bir vana varsa açılabilir ya da koordinat uçağa verilip pilotun bölgeye su boşaltması sağlanabilir. Ağ içindeki iletişimin çok atlamalı olduğu görülür.

Sink, baz istasyonu gibi düşünülebilir; bir ağ geçidi (gateway) olarak da değerlendirilebilir. Bilginin merkeze aktarılmasını ve bir yerde toplanmasını sağlar; IP adresi olan merkezle haberleşilen ara noktadır. Sink sabit de mobil de olabilir.

### 4.2 Mobil sink örneği: vahşi yaşam izleme

Afrika'da vahşi yaşamı izleyen zoologlar sensörleri hayvanların üzerine yerleştirir; balinaların üzerine yerleştirildiği de olur. Bu, mobil sensör ağı için güzel bir örnektir. Altı ay gibi uzun bir süre izleme yapılacaksa düğümlerin bilgi saklayabilmesi önemlidir. Bilgi belirli periyotlarla toplanabilir ya da altı ayın sonunda düğüm üzerinde saklanmış olarak alınabilir.

**Soru:** Düğümlerin belirli bir bellek kapasitesi yok mu? **Cevap:** Var. Bu yüzden düğüm altı ay sahada kalacaksa bilginin toplanma sıklığı da değişir; ne kadarlık bilginin ne kadar süre saklanacağı buna göre en iyi hâle getirilmelidir.

Sahrada ya da ormanlık alanda cipe kurulu mobil baz istasyonlarıyla gezen ekipler, hayvanlara yerleştirilen çiplerdeki veriyi toplayabilir. Haftalık ya da aylık toplamayla düğümlerin kısıtlı belleğindeki bilgi alınır ve bellek boşaltılarak yeniden yer açılır.

## 5. WSN'lerin karakteristikleri

Slayttaki karakteristikler (ekrandan, 00:40:00):

- Çok sayıda düğüm, çoğu zaman binler mertebesinde
- Düğümlerin birbirine yakın olması gerekir
- $20$ düğüm/m³'e varan yoğunluklar
- Genellikle sensör düğümlerinden sink'e doğru asimetrik bilgi akışı
- İletişim sorgular (query) ya da olaylar (event) ile tetiklenir
- Sınırlı enerji (pek çok uygulamada pili değiştirmek ya da şarj etmek imkânsızdır)
- Çoğunlukla statik topoloji

Hoca her maddeyi açtı. Bir sensör ağından söz ediliyorsa en az onlar, hatta yüzler ve binler mertebesinde düğümden söz edilir. Gerçekte bu kadar çok kullanılmadığını, her ormana yüzlerce düğüm atılsa çok fazla elektronik atık oluşacağını, ama ağların prensipte bu ölçekte çalışacak biçimde tasarlandığını söyledi; zooloji ve botanik bahçelerinde örnekleri vardır. Düğümler birbirinden uzak olmaz: 100 metre aralıkla yerleştirmek pek istenmez, kilometre mertebesinde aralık hiç olmaz.

> **Ders sonrası not:** Hoca yoğunluğu "metrekareye 20 düğüm" diye okudu; slaytta birim $\text{nodes/m}^3$ (metreküp) olarak yazılı (ekrandan, 00:40:00).

> **Hocanın vurgusu:** WSN'de bilgi akışı asimetriktir, sensörlerden baz istasyonuna doğrudur. Bu çok önemlidir, çünkü IoT'de simetrik bilgi akışı vardır: merkez ile IoT cihazı arasında karşılıklı veri alışverişi olur. WSN'de sensörler programlanır ve sensörler rapor eder; çok özel durumlarda sensörlere sorgu gönderilir.

### 5.1 Veri toplama biçimleri

Hoca slaytta iki yazılı olmasına rağmen üç tür veri toplama biçimi olduğunu söyledi:

- Sorgu (query) göndermek: merkez belirli anlarda sorgu atar.
- Periyodik toplama: örneğin "her saat başı bilgi gönder" diye programlanır; geri kalan zamanda düğüm uyur.
- Olay tetiklemeli: ilgilenilen bir olay olduğunda (yangın, sıcaklığın eşiği aşması) düğüm merkezi bilgilendirir.

> **Hocanın vurgusu:** Sensör ağlarının hayatta kalabilmesinin yegâne sebebi, sahada oldukları sürenin büyük bölümünü uyuyarak geçirmeleridir. Başka türlü hayatta kalma şansları yoktur. IoT ağları böyle değildir. Sensörler yalnız algılamak ve algıladıkları bilgiyi yandaki düğüme aktarmak ya da yandan gelen bilgiyi alıp başka düğüme iletmek için uyanır.

### 5.2 "Çoğunlukla" statik topoloji

Topoloji statik kabul edilir, ama hoca "mostly" (çoğunlukla) kısmının çok önemli olduğunu belirtti, çünkü zamanla bazı düğümler ölür. Bir taş gelmesi, yağmurun elektronik devreye zarar vermesi gibi fiziksel tahribat, zamanla bozulma ya da enerjinin bitmesi topolojiyi değiştirir. Ölen düğümün görevini başka düğümler devralmalıdır. Düğümler birbirleriyle haberleşerek yeni bir yapı kurmalıdır: "Daha önce sen bana gönderiyordun, ben öldüm, sen kendine yeni bir komşu bul." Bunu düğüm, etrafıyla haberleşerek anlamalıdır.

Ek karakteristikler: düşük maliyet, küçük boyut ve en düşük ağırlık beklenir; düğümler hataya yatkındır ve çabuk etkilenir; noktadan noktaya iletişim yerine yayın iletişimi yapılır; özel düğümler aracılığıyla ağ içi işleme (in-network processing) yapılır: bilgi daha yetenekli düğüme, yani küme başına aktarılır, o da örneğin beş düğümün bilgisini toplayıp birleştirerek (aggregate) merkeze iletir. Güç, hesaplama ve bellek açısından sınırlar bir kez daha vurgulandı.

### 5.3 Enerji hasadı

Bir sensör ağıyla çalışırken enerji çok verimli kullanılmalıdır. Enerji hasadı (energy harvesting) yapılabilir: güneşten enerji alma potansiyeli vardır. Ortamdaki enerjiden bir miktar çekmek mümkündür ama yüksek oranda yapılamaz; RFID etiketlerinde bu daha olasıdır. Sensör ağlarında elde edilen kazanç çok fazla olmadığı için sık kullanılmaz. Yeraltına yerleştirilen ve ortamdaki titreşimden enerji üretmeye çalışan sensörler de vardır. En verimli yöntem güneş enerjisidir. Ama sensör ağlarının çoğunda çözümler enerji üretmekten çok enerjiyi verimli kullanmaya yöneliktir. Enerjisi bitmeye yakın bölgelere yeni düğümler göndermek de bir seçenektir.

## 6. Kablosuz ağ zorlukları ve ağ gereksinimleri

### 6.1 Kablosuz ağ zorlukları

WSN'ler geleneksel kablosuz ağların zorluklarını paylaşır (ekrandan, 00:45:00):

- Her düğümde sınırlı enerji: enerji verimli iletişim mekanizmaları gerekir.
- Bant genişliği sınırlı, hataya yatkın iletişim kanalları: yalnız düşük veri hızlı uygulamalar desteklenebilir.
- Kablosuz ortam paylaşımlı/yayın kanalıdır: aynı kanalda ve aynı uzamsal bölgede eş zamanlı iletimler birbirleriyle çakışmaya (girişim/çekişme/çarpışma) yol açabilir; verimli ortam paylaşım mekanizmaları gerekir.

Çıkış güçleri yüksek olmadığından veri taşınırken diğer düğüme hatalı ulaşabilir; bu yüzden hata tespit edici yöntemler uygulanır.

İletişim dağıtık olduğu için, birbirini görmeyen iki düğüm ortalarındaki bir düğüme aynı anda bilgi göndermeye çalışırsa çarpışma (collision) oluşur ve iki göndericinin bilgisi de kaybolur. Yayın tabanlı haberleşmede bu gizli terminal (hidden terminal) problemi mutlaka çözülmeli, çarpışma engellenmelidir.

<!-- BELİRSİZ: Altyazıda "hidden pause problemi" geçiyor; bağlamdan "hidden terminal" olduğu anlaşılıyor. -->

> **Ek bilgi (derste anlatılmadı):** Gizli terminal problemine kablosuz ağlarda yaygın bir çözüm, göndericinin önce kısa bir "gönderme isteği" (RTS) yollaması ve alıcının "göndermeye hazır" (CTS) yanıtıyla diğer komşuları susturmasıdır. Bu yaklaşım büyük olasılıkla en bilinen biçimiyle IEEE 802.11'de kullanılır; WSN'ye özgü MAC protokolleri de benzer fikirleri uyku-uyanma çizelgeleriyle birleştirir.

Ardından farklı haberleşme teknolojilerinin çalışma frekansları, güç tüketimleri ve veri hızlarını karşılaştıran bir tablo gösterildi. Hoca bir tarafta 250 kilobit varken diğer tarafta megabitlerden söz edildiğini, 5G ile hem hız hem gecikme (latency) açısından farklı bir boyuta geçileceğini, ama WSN'lerin hâlâ IEEE 802.15.4 üzerinden haberleştiğini söyledi.

<!-- BELİRSİZ: Frekans/güç/veri hızı karşılaştırma tablosu karelerde görünmüyor; tablonun satırları ve değerleri aktarılamadı. -->

### 6.2 İletişim örüntüleri ve veri toplama modelleri

İletişim örüntüleri olarak çok noktaya yayın (multicast) ve yerel haberleşme hatırlatıldı. Veri toplama modelleri: sürekli veri toplama, belirli periyotlarla toplama ve sorgu ile merkezden bilgi alma. Örneğin bir bölgede hareketlilik tespit edildiğinde merkez o bölgeden görüntü talep edebilir. Görüntü çok enerji tüketeceği için sürekli akmaz. Düşman hattına yerleştirilen bir sensör ağında, kamptaki nöbetçi bir hareket görünce o bölgeden görüntü isteyebilir. Ya da bir olay olduğunda, örneğin sıcaklık belirli bir seviyeyi aşınca yangın raporlanıp merkez bilgilendirilir.

### 6.3 Senkron uyanma

Düğümler enerji verimli çalışmalıdır; ne zaman uyuyup ne zaman uyanacaklarına ve diğer düğümlerle nasıl senkron olacaklarına karar vermeleri gerekir. Hoca burada sınıfa nasıl senkron uyandıklarını sordu (Örnek Sorular, 1. soru). Bir öğrencinin zamanlayıcı önerisi en sık kullanılan yöntemlerden biri olarak doğrulandı: hepsi aynı zamanlayıcı mekanizmasını kullanır, ama zamanla saatlerde kayma (sarkma) olduğu için belirli aralıklarla zamanlayıcılarını eşitlemeleri gerekir; bunun için de haberleşmeleri gerekir. Diğer bir yöntemde gönderici, karşı tarafa önce bilgi göndereceği bilgisini aktarır; alıcılar bunu alıp veriyi alacakları bir moda geçer.

İşlemci tarafında dinamik voltaj ölçekleme (dynamic voltage scaling) ile işlemcinin çalışma frekansı değiştirilir; böylece işlemci daha az ve daha verimli enerji kullanır.

### 6.4 Ağ gereksinimleri

Slayttaki gereksinimler (ekrandan, 00:50:00):

- Enerji verimliliği: radyo iletişimi en iyi hâle getirilmelidir. En yaygın yöntem radyoyu, uyku ve uyanma modları arasında periyodik geçişle görev döngüleri (duty cycle) hâlinde çalıştırmaktır.
- Ölçeklenebilirlik: yerleştirilen düğüm sayısı yüzler ya da binler mertebesinde olabilir.
- Ad-hoc ağ ve kendi kendini örgütleme: altyapı eksikliği ve ağ dinamikleri, örneğin güvenilmez iletişim bağlantıları ya da güvenilmez düğümler nedeniyle.

Onlarca düğümde bile sorun çıkabilir; yüzlerce, binlerce düğümde bu mekanizmaların çalışması için ölçeklenebilir bir yapı gerekir. En önemlisi, çözümleri merkezi bir yapıda örgütlemek yerine dağıtık ve yerel çözen, kendi kendini örgütleyen (self-organizing) yapılar kurmaktır. Böylece bir düğüm yalnız kendi etrafını bilse bile, herkes kendi etrafını bildiği sürece bütün sistem çalışır. Günlük hayattaki kablolu yapılarda (LAN, MAN gibi yerel ve metropoliten alan ağları) herkes herkesin bilgisine sahiptir; bütün ağın haritasını bilmek sensör ağlarında uygulanamaz, uygulanırsa ciddi sorunlar çıkar.

## 7. Yerleşim, kapsama ve bağlantılılık

### 7.1 Yerleşimin hedefleri

Slayttaki temel soru (ekrandan, 00:55:00): belirli bir uygulama bağlamı, bir çalışma bölgesi ve bir kablosuz sensör kümesi verildiğinde düğümler nasıl ve nereye yerleştirilmeli? Hedefler:

- Kapsama (coverage): ağdaki sensörlerin ortamdan elde ettiği bilginin uygulamaya özgü kalitesi.
- Bağlantılılık (connectivity): bilginin iletilebileceği ağ topolojisi.
- Diğerleri: donanım maliyeti, enerji kısıtları vb.

Düğümler yerleştirildiğinde iki temel noktaya bakılır: sahayı ne kadar kapsadıkları ve yakınlarında, üzerinden merkeze bağlanabilecekleri başka bir sensör olup olmadığı. Hoca burada algılama menzilinin mi haberleşme menzilinin mi daha uzun olduğunu sordu (Örnek Sorular, 2. soru). Cevap haberleşme menzilidir: genelde bir sensör algılamada bir birim kapsıyorsa haberleşmede iki birim kapsar; oran bire ikidir. Yerleşim bu iki özellik birlikte gözetilerek yapılmalıdır.

> **Ek bilgi (derste anlatılmadı):** Literatürde, haberleşme yarıçapı algılama yarıçapının en az iki katıysa ($R_c \geq 2R_s$), dışbükey bir alanın tam kapsanmasının ağın bağlantılı olmasını da büyük olasılıkla garanti ettiği gösterilmiştir. Hocanın verdiği "bire iki" oranı bu yüzden yerleşim çalışmalarında sık kullanılan bir varsayımdır.

### 7.2 Kapsama türleri

Kapsamanın biçimi, hangi bilginin ne sıklıkla toplanmak istendiğine göre şekillenir. Hoca iki örnekle bunu sordu (Örnek Sorular, 3. soru):

- Bariyer kapsama (barrier coverage): bir askeri kamp kuruldu ve etraftan gelebilecek tehlikeler belirli uzaklıkta yakalanmak isteniyor. Kampın çevresine bir çember çizilir. Dairenin her noktasını kapsamak gerekmez; çevresini izlemek yeterlidir. Belirli bir hat kapsanıp oradan giriş-çıkışlar yakalanabiliyorsa ağ görevini tam yapmış olur.
- Tüm alan kapsama: orman yangını tespitinde bütün alana bakmak gerekir. Bu durumda düğümlerin örtüşmeyecek ve kapsanmayan alan kalmayacak biçimde yerleştirilmesi istenir. Rastgele dağıtımda bu mümkün değildir: yan yana düşen iki sensörün algılama ya da bağlantı alanları belirli ölçüde örtüşür ve kesişim kümeleri oluşur.
- Hedef kapsama: amaç bütün alanı ya da bir bariyeri değil, belirli hedefleri izlemek olabilir. Bu durumda hedefler görüş alanına (field of view) alınacak biçimde konumlandırma yapılır ya da düğümler hareket ettirilir.

### 7.3 Yönlü ve her yönlü algılama; motility ve mobility

Kameralar belirli bir açıyla algılar; buna yönlü algılama (directional sensing) denir. Sıcaklık, nem gibi sensörler her yönlüdür (omnidirectional), 360 derece veri toplar. Hoca örtüşme durumunda ne yapılacağını sordu (Örnek Sorular, 4. soru) ve cevabı kendisi verdi:

- Her yönlü sensörler örtüşüyorsa kesişim kümelerini ortadan kaldırmak için birini hareket ettirmek gerekir; başka şans yoktur.
- Yönlü sensör ağlarında her sensörün belirli bir görüş alanı vardır; bunu bir dairede pasta dilimi ya da bir üçgen gibi düşünmek gerekir. Kameralar döndürülerek, düğümler yerinden oynatılmadan örtüşen alan en aza indirilebilir.

Kendi etrafında dönme yeteneğine motility, yer değiştirme yeteneğine mobility denir. İkisinin de maliyeti vardır: kendi etrafında dönmenin maliyeti görece düşük, düğümü fiziksel olarak hareket ettirmenin maliyeti oldukça yüksektir.

Hareket yeteneği olmayan düğümlerle alan yeterince kapsanamıyorsa bölgeye ek düğüm gönderilir. Buna yeniden yerleşim (redeployment) denir; rastgele yerleşimin yarattığı sorun bu şekilde giderilip kapsama artırılır.

### 7.4 Kapsama oranı ve en iyi yerleşim

Bir alan kapsanmaya çalışıldığında, o anda alanın yüzde kaçının kapsandığı hesaplanabilir. Hoca, alana atılan $n$ her yönlü sensör en iyi biçimde yerleştirilseydi ne kadar alan kapsayacağını sordu (Örnek Sorular, 5. soru).

Çözüm derste adım adım kuruldu:

- Verilen: $n$ sensör, her biri yarıçapı $r$ olan bir daire içini algılıyor ($r$: algılama yarıçapı, sensing radius); en iyi yerleşimde kesişme yok.
- Bir sensörün kapsadığı alan: dairenin alanı $\pi r^2$.
- $n$ sensör kesişmeden yerleştirilirse: en fazla $n \pi r^2$.

Bir öğrenci farklı bir bakış önerdi: her daire $2r \times 2r$ boyutlu bir kareye yerleştirilirse, karenin alanı $4r^2$ olur ve daire bu karenin $\dfrac{\pi r^2}{4r^2} = \dfrac{\pi}{4} \approx 0{,}785$'ini kapsar. Hoca bunun üzerine, sensör ağlarında modellemenin her zaman dairesel yapıldığını, bu yüzden hesabın $\pi r^2$ üzerinden yapıldığını belirtti.

Kapsama verimliliği hesaplanırken referans değer tüm alan değildir; "bu düğümler elle yerleştirilseydi ne kadar alan kapsardı" sorusunun cevabıdır. Kesişmeler hesaba katılarak bulunan gerçek kapsama alanı, en iyi değere ($n\pi r^2$) oranlanır ve alanın ne kadar verimli kapsandığı ortaya konur:

$$\text{Kapsama verimliliği} = \frac{\text{gerçekte kapsanan alan}}{n \pi r^2}$$

Kendi etrafında dönebilen yönlü sensör ağlarında ve hareket edebilen düğümlerle bu verimlilik yükseltilebilir.

### 7.5 İkili ve olasılıksal kapsama

İki kapsama modeli vardır:

- İkili kapsama (binary coverage): bir nokta dairenin içindeyse kapsanır, dışındaysa kapsanmaz; 0-1 mantığı vardır.
- Olasılıksal kapsama (probabilistic coverage): dairenin merkezinde bir olay %100 olasılıkla algılanırken dışa doğru bu oran bir eğriye göre azalır; hesap bu eğriye göre yapılır.

> **Hocanın vurgusu:** İki modelin farkını bilmek önemlidir, çünkü kapsama problemi literatürde çok sık çalışılan bir problemdir.

### 7.6 Yerleşim stratejileri

Ağırlıklı olarak rastgele dağıtımdan söz edildi. Bunun karşısında yapılandırılmış yerleşim (structured deployment) vardır: düğümler elle ya da otonom bir robotla yerlerine yerleştirilir ya da kendileri yerleşir. Açık ve tehlikeli arazilerde elle yerleştirme imkânı olmadığından genelde rastgele yerleşim tercih edilir.

Rastgele yerleşimin eksiklerini gidermek için aşırı yerleşim (over-deployment) ve artımlı yerleşim (incremental deployment) stratejileri vardır; bunlar baştan fazla düğüm atma ya da sonradan ek düğüm yerleştirme anlamına gelir. Alternatif olarak mobil sensör düğümleri kullanılabilir. Hoca, maliyeti yüksek olsa da mobil düğümlerin en avantajlı çözümlerden biri olduğunu söyledi: tekrar tekrar yerleşimde bazı düğümler aynı alanı boşuna kapsayarak orada kalmaya devam eder; mobil sensör ağlarında ise her düğüm konumlandırılabildiği için düğümlerden en yüksek verim alınır.

## 8. Ağ topolojileri ve bakım

### 8.1 Tipik ağ topolojileri

Slaytta iki topoloji yan yana gösterildi (ekrandan, 01:45:00):

- Yıldız (star), tek atlamalı topoloji: ortadaki gri düğüme (sink) bütün düğümler doğrudan bağlıdır. Artısı: tasarımı önemli ölçüde basitleştirir. Eksisi: ölçeklenebilirliği ve dayanıklılığı zayıftır.
- Düz çok atlamalı örgü (flat multi-hop mesh): düğümler birbirine bağlıdır ve veri komşular üzerinden sink'e ulaşır.

Hoca bunlara ek olarak yapılandırılmış iki katmanlı hiyerarşik bir topolojiden söz etti. Sensör ağlarında genelde bu yapı uygulanır: küme başları iletişim yükünü üstlenir, diğer düğümler de sırayla küme başı görevini alır. Böylece ağın ömrü uzun süre en iyi biçimde devam eder.

### 8.2 Bakım seçenekleri

Slayttaki sorular (ekrandan, 01:15:00):

- Sensör düğümlerinin bakımı uygulanabilir ya da pratik mi? Örneğin pilleri değiştirmek mümkün mü? Yoksa bakımsız (unattended) çalışma mı? İmkânsız ama önemsiz mi, çünkü görev süresi çok kısa olabilir?
- Enerji kaynağı: yerleşim anındaki enerjiyle sınırlı mı? Yoksa bir tür şarj, ortamdan enerji toplama (ör. güneş hücreleri) var mı?

Hoca pil değiştirmenin kolay olmadığını, çünkü açık ve tehlikeli araziye çıkmanın makul olmayabileceğini söyledi. Bu yüzden genellikle enerjiyi verimli kullanmak ya da enerji hasadıyla (ör. güneş panelleri) enerji toplamak tercih edilir.

## 9. Protokol tasarım zorlukları, gizlilik ve güvenlik

### 9.1 Genel zorluklar ve güç tüketimi

Önceki başlıklara ek olarak verinin dağıtık işlenmesi, gürültülü ölçümlerin giderilmesi için çeşitli yöntemler ve gerçek zamanlı veri aktarımı gerekiyorsa buna göre rota belirlenmesi önemlidir. Güç tüketimi açısından algılamanın ve işlemcinin tüketimi çok düşüktür, ama iletişimde, gönderme ve alma sırasında ciddi güç harcanır. Bu yüzden düğümü mümkün olduğunca uzun süre uyku modunda tutmak önemlidir.

### 9.2 Protokol tasarım zorlukları

Slaytlardaki başlıklar (ekrandan, 01:20:00; önceki iki slayt aynı karede küçük resim olarak görünüyor):

- Uzun ömür (extended lifetime): tipik bir alkalin pil yaklaşık 50 watt-saat enerji taşır; sürekli çalışmada bir aydan az dayanır. Enerji hasadı ve daha iyi pil tasarımıyla birkaç yıl çalışma hedeflenir.
- Yanıt verebilirlik (responsiveness): uyku ve uyanma modlarıyla görev döngüsü, yanıt verebilirliği azaltır.
- Dayanıklılık (robustness): ucuz cihazlar arızaya yatkındır, yerleşim alanları zorlu ve düşmancadır; sistem tek tek cihaz arızalarına duyarsız olmalıdır.
- Sinerji (synergy): depolama, hesaplama ve iletişim kaynaklarının ortak kullanımı.
- Ölçeklenebilirlik: on binlerce, uzun vadede belki milyonlarca düğüm.
- Heterojenlik: hesaplama, iletişim ve algılama açısından.
- Kendi kendini yapılandırma (self-configuration): bakımsız, dağıtık sistemler.
- Kendi kendini iyileştirme ve uyarlama (self-optimization and adaptation): zamanla toplanan sensör ve ağ ölçümlerinden öğrenip bu öğrenmeyi performansı sürekli iyileştirmek için kullanmak.
- Sistematik tasarım: uygulamaya özgü ağlar; yeniden kullanıma, modülerliğe ve çalışma anında uyarlamaya izin veren sistematik tasarım yöntemleri gerekir.
- Gizlilik ve güvenlik: bilginin hassasiyeti, düşmanca konumlarda yerleşim.

Hoca bu maddeleri şöyle açıkladı: sonuçların doğru yorumlanabilmesi için güvenilir olması (robustness), istenen sürede ortamdan bilgi toplanabilmesi, istenen anda bilgi alınabilmesi (responsiveness) ve ağın mümkün olan en uzun süre yaşaması gerekir. Tek bir düğüm değil birden çok düğüm olduğu için birlikte hareket edebilmeleri, bir bilgiyi taşıyamayacak durumdaki düğümün diğerinin depolama, hesaplama ve iletişim yeteneğini kullanabilmesi beklenir. Düğüm sayısı arttıkça yapı ölçeklenebilir olmalı, düğümler yerelde birbirleriyle haberleşerek kendilerini yapılandırabilmelidir.

### 9.3 Gizlilik ve güvenlik

Bir bölgeden veri toplanırken veri havadan gönderildiği için saldırıya maruz kalma olasılığı yüksektir. Örneğin düşman hattındaki bilgi kendi merkezinize akarken, yayın yapıldığı ve sinyal çevreye yayıldığı için düşman tarafına da akabilir. Veriyi şifrelemek bir çözüm olabilir, ama şifreleme enerji ve işlemci açısından bir maliyettir. Bu yüzden bu tür durumlarda akıllı çözümler üretmek gerekir. Özellikle kritik askeri uygulamalarda düşman hattındaki verinin başkasının eline geçmemesi önem kazanır.

## 10. WSN uygulamaları

WSN'ler uygulamaya özgü ağlardır: her WSN'yi her uygulamada kullanamazsınız. Tasarım ve kullanılacak düğümlerin yetenekleri uygulamaya göre ayarlanmalıdır. Kullanım alanları: tarım ve orman izleme, sağlık, gözetleme, deprem öncesi ve sırası, lojistik. Köprülere ve fiziksel yapılara yerleştirilen ağlarla yapının sağlamlığı izlenebilir; yollarda buzlanma olup olmadığı gibi bilgiler toplanabilir. WSN'ler hayatımıza ilk olarak askeri uygulamalarla girdi.

### 10.1 Askeri uygulamalar

Slayttaki askeri uygulamalar listesi (ekrandan, 01:25:00, küçük resim): kuvvetlerin ve teçhizatın izlenmesi, savaş alanı gözetimi; hedefleme ve hedef izleme sistemleri; nükleer, biyolojik ve kimyasal (NBC) saldırı tespiti; sızma tespiti (sınırlar, mayın tarlaları); ateş eden silahın (hafif silahlar) yerinin tespiti; karşı keskin nişancı tespiti; gelişmiş navigasyon ve lojistik sistemleri; denizaltı tespiti.

Hoca örnekleri şöyle açtı:

- Keskin nişancının nereden ateş ettiği, alınan ses sinyalleri kullanılarak belirlenir. Sınır bölgesinde ateş altındaysanız nişancıyı ne kadar hızlı bulursanız operasyonu o kadar başarılı yürütürsünüz. Ani bir ateşin hangi yönden geldiğini tespit etmek de benzer bir yaklaşımdır.
- Belirli bir bölgeye giriş-çıkış olup olmadığı, sınır ihlali yapılıp yapılmadığı tespit edilir.
- Biyolojik ya da kimyasal silah kullanılıp kullanılmadığı: dronlarla bölgeye düğüm bırakılır, alınan numuneyle maske takılması gerekip gerekmediği anlaşılır. Radyasyon da tespit edilebilir.
- Hareket eden mobil sensör ağlarıyla mayın taraması yapılabilir.

Denizaltı tespiti de bu listededir. Sensör ağları karada olduğu gibi denizde ve suda da kullanılır; orada derinlik daha önemli olduğu için üç boyut daha çok devreye girer. Su altı akustik sensör ağlarında (underwater acoustic sensor networks) ortamın yoğunluğu fazla olduğundan sinyal havadaki kadar hızlı iletilmez; veri hızı düşüktür ve aktarılan veri miktarı sınırlıdır.

Son beş yılda dronlar da bir sensör ağı oluşturmaya başladı. Dronlar hem mobildir hem havada üç boyutlu konumlardadır; drone ağları için pek çok uygulama tasarlanmaktadır. Ama bunları gerçeklemek kolay değildir, çünkü bir dronun maliyetiyle onlarca, belki yüzlerce düğüm alınabilir. Su, hava ve kara gibi farklı ortamlarda sensör ağlarının iletişim yetenekleri de değişir.

### 10.2 A Line in the Sand (ExScal) projesi

Askeri bir alana yerleştirilmiş bir ağ örneği gösterildi (ekrandan, 01:25:00): çöl gibi, fiziksel arazinin asker ya da araç hareketini kısıtlamadığı her yere "tuzak teli" (tripwire) koyup sızanları tespit etmek, sınıflandırmak ve izlemek amaçlanır. Proje Ohio State University tarafından geliştirilmiştir (küçük resimden). Slayttaki ayrıntılar:

- Bilinen konumlara 90 düğüm yerleştirilmiş; aralarında manyetometre ve mikro güçlü darbe radarı (micro-power impulse radar) sensörleri var.
- Sistem her sızanı tespit eder (detects).
- Sistem her sızanı bilinen sızan türlerinden birine ya da hiçbirine sınıflandırır (classifies).
- Senaryolar: "silah" taşıyan asker (patikalarda hattı yürüyerek/koşarak geçer); araç (patikalarda hattı 5-20 mph hızla geçer); sivil (patikada hattı yürüyerek geçer).

Hoca, hareket eden askeri araçların geçtiği noktalara yerleştirilen sensörlerle güvenli bir hat kurulduğunu, ilerleyen hattın sağından ya da solundan yaklaşan bir şey olup olmadığının tespit edilmeye çalışıldığını anlattı. Burada hattı delecek düşmanın ne ile geldiğini iyi öngörmek gerekir: araçla yaklaşmasını tespit etmek ayrı, yürüyerek yaklaşmasını tespit etmek ayrıdır. Yaklaşan kişinin sivil mi asker mi olduğunu, üzerinde silah olup olmadığını anlamak da önemlidir.

> **Hocanın vurgusu:** Sensör ağlarında hedefin ne olduğu iyi belirlenmelidir: yalnız bir düşman hareketini mi gözlemlemek istiyorsunuz, yoksa düşmanın türü hakkında da fikir mi sahibi olmak istiyorsunuz? Düğümlere yerleştirilecek sensörler buna göre önem kazanır.

### 10.3 Çevresel uygulamalar

Ekosistemleri incelemek, kirlilik analizi yapmak ve özellikle akarsulardaki kirliliği analiz etmek için çeşitli noktalara düğümler yerleştirilip numuneler alınır, yaşam koşullarıyla ilgili bilgi toplanır. Bir örnekte bir adadaki kuşların yaşam alanları incelenmiş; yaklaşık 200 düğüm yerleştirilmiş ve ışık, basınç, sıcaklık ve nem ölçülerek habitat hakkında bilgi toplanmıştır. Bir botanik bahçesine yerleştirilmiş düğümler de gösterildi; bunlar genelde denetimli biçimde elle yerleştirilir.

### 10.4 Sağlık uygulamaları

Hoca sağlık alanındaki uygulama sayısının artacağını söyledi. Sağlık alanındaki sensörleri IoT ağı olarak düşünmemek gerekir, çünkü her birine tek tek IP üzerinden erişmeye gerek yoktur. Kişinin üzerine yerleştirilen düğümlerden alınan bilgiler pek çok hastalığın tespitine katkı sağlar. Özellikle huzurevindeki yaşlıların ya da evde yalnız yaşayan hastaların yaşamıyla ilgili bilgi sahibi olmak önemlidir. Burada giyilebilir cihazlara (akıllı saat, akıllı bileklik) doğru geçilir; bazen evdeki kamera sistemleri de kullanılarak yaşlı kişinin başına gelebilecek olumsuz bir durum hızla merkeze ya da yakınına iletilir. Tıbbi bakımdaki WSN'lerin boyutları küçülüyor: oksimetre artık saatlerde bile var; kalp atışı ve oksijen seviyesi izlenip raporlanabiliyor.

Slaytlarda gösterilen bir evde bakım sistemi (WeCare) mimarisinde vücut alanı ağı (Body Area Network), kişisel alan ağı (Personal Area Network), ağ geçidi ve uygulama katmanı yer alır; sistemin yaşlılara kablosuz sensör ağlarıyla bütünleşik bir evde bakım çözümü sunması amaçlanır (ekrandan, 01:30:00, küçük resim). Aynı karede sistemin denendiği bir test ortamının (oturma odası, mutfak, yatak odası ve donanım) fotoğrafları görünüyor. Kişinin üzerindeki sensörler vücut alanı ağını, çevresindeki sensörler kişisel alan ağını oluşturur. Bu ağlarla kişinin düşüp düşmediği, hangi odada ne kadar kaldığı, uyuyup uyumadığı ve belirli bir süreden fazla hareketsiz kalıp kalmadığı izlenebilir.

Hoca bu alanlarda çözümlerin hâlâ müdahaleci (intrusive) olduğunu belirtti: sensör konması, açılarının ayarlanması gerekir. Hedef ise sensörlerin standart bir cihazda, fiziksel bir nesnede yer alması ve herhangi bir yapılandırmaya gerek kalmadan bir tuşa basınca devreye girmesidir. Kamera gizlilik açısından çok sorunlu olduğu için kişilerin taşıyacağı giyilebilir cihazlar öne çıkar.

Düşme tespiti (fall detection) için çeşitli çözümler var; artık saat ve telefonla da yapılabiliyor. Bir örnekte koltuğa yerleştirilen sensörler gösterildi: ivmeölçer, titreşim sensörü ve kuvvete duyarlı (force resistive) sensörlerle donatılmış akıllı bir koltuk, kişilerin koltukta oturarak, uzanarak ya da kestirerek geçirdiği süreyi izler ve günlük rutinlerinden sapmaları tanır (ekrandan, 01:35:00, küçük resim). Hoca, dünyadaki çip krizine de değinerek artık araçlar dahil pek çok eşyada çip kullanıldığını, gelecekte eşyaların çoğunda elektronik yeteneğin doğrudan bulunacağını ve ayrıca bir mikrodenetleyici eklemek gerekmeyeceğini söyledi.

### 10.5 Afet ve yapı izleme

Volkan patlaması, sel, orman yangını ya da sismik aktivite sensör ağlarıyla izlenerek büyük felaketler önceden öngörülebilir ve tahliye yönetilebilir. Özellikle sellerde son yıllarda ciddi kayıplar yaşandığını, dere yataklarındaki evleri hızla uyaran, hatta su seviyesi belirli bir yere çıkınca kalkanları devreye sokan çözümlerin yurt dışında görüldüğünü söyledi. Maliyetli işler olsa da teknolojinin insan hayatını koruduğu önemli çözümlerdir.

Köprülerin üzerine yerleştirilen düğümlerle köprüler izlenebilir. Son yıllarda zaman zaman ani köprü çökmeleri yaşanmaktadır. Uzun yıllardır ayakta olan binaların, köprülerin ve tünellerin bu şekilde izlenmesi, çökme olmadan önce ipucu vermesi ve yapının kapatılıp onarılabilmesi için değerli bilgi sağlar.

### 10.6 Dersin slaytlarındaki toparlama

Slaytların son sayfası (ekrandan, 01:35:00):

- Temel konular: enerji verimliliği, ölçeklenebilirlik, ad-hoc ağ.
- Uzaktan algılama içeren her uygulama: sınır gökyüzü!
- Araştırma eğilimleri: kablosuz ağ iletişiminden bilgi işlemeye doğru; akıllı telefon sensörleriyle katılımcı algılama (participatory sensing).

## 11. WSN ile IoT karşılaştırması, RFID ve beacon'lar

### 11.1 IoT'ye geçiş

Hoca sensör ağlarının IoT'ye geçişte önemli bir anahtar olduğunu söyledi. WSN'lerden sonra akıllı telefonlar IoT'ye ilham verdi; IoT fikri 2000'lerin başında dile getirilse de IoT ağları 2010'lu yıllardan itibaren yoğunlaştı. Ardından sınıfa IoT ağlarının sensör ağlarından nasıl ayrıldığını sordu (Örnek Sorular, 6. soru). Derste ortaya çıkan farklar:

- Fiziksel nesneye bağlılık: IoT'de bir fiziksel nesne ile ilişki kurulur; nesnenin üzerine bir mikrodenetleyici konumlandırılır ya da nesneyle bütünleşik sunulur. Bir öğrenci bulaşık makinesi örneğini verdi; hoca bulaşık makinesinin zaten kendisinin bir IoT cihazı olduğunu, elektronik yeteneği sayesinde ağa otomatik katılıp uzaktan erişilebildiğini belirtti. Eve gelmeden yarım saat önce klimanın uzaktan açılması, bugün yaygınlaşan akıllı evlerin basit ama etkili özelliklerinden biridir; arabalarda da aynısı yapılabilir.
- Erişilebilirlik: her cihaz erişilebilir olduğu için istenen zamanda, istenen noktada cihazdan veri toplamak daha kolaydır.
- Bulut ve büyük veri: WSN'de bir bulut yapısından söz edilmez; IoT ağı bulutsuz düşünülemez. IoT'de büyük veri de vardır, çünkü çok fazla veri üretilir ve hemen atılmaz; bulutta bir süre saklanıp analiz edilir. Bu yüzden bulut ile IoT'nin birlikte çalışması gerekir.
- Yerel ve küresel iletişim: WSN'de yerel iletişim ve elden ele (multi-hop) iletme vardır; IoT'de çok atlamalı olsa bile ağ geçidi üzerinden cihaza doğrudan erişilir.
- Enerji ve bant genişliği: WSN'de enerji kısıtı vardır, IoT'de böyle bir kısıt yoktur. IoT'de bant genişliği geniştir ve erişim hızlıdır; çoklu ortam verisi rahatça taşınır. WSN'de çoklu ortam verisi için çok yollu yönlendirme gibi özel çözümler gerekir.
- Uçta işleme: WSN'de uçta işleme yalnız belirli düğümlerde yapılabilir; IoT'de ilgili cihaz üzerinde rahatça yapılabilir.

**Soru:** WSN'de de veriyi bir sunucuya göndermiyor muyuz? **Cevap:** Gönderilir, ama WSN daha küçük çaplı bir uygulamadır ve başka amaçla çalışan diğer WSN'lerle iletişim hâlinde olmadığı için bulut tarzı bir yapılanma pek yapılmaz. IoT ile WSN birleştiriliyorsa, yani IoT'nin içinde WSN'ler varsa yine buluttan söz edilir. Tek bir WSN basit bir bulut ortamı olmadan da çalışabilir. Bu, WSN'de bulut kullanılmaz demek değildir; ama kavram olarak bulut IoT ile özdeşleşir, WSN ile özdeşleşmez.

### 11.2 RFID, QR kod ve beacon'lar

**Soru:** Bazı sensörler (ör. bir telefon üreticisinin akıllı etiketleri) verilerini cep telefonu üzerinden ağa aktarıyor; bunlar hangi kategoriye giriyor? **Cevap:** Bunlar etiket (tag) teknolojileridir ve bir sonraki derste IoT ağlarıyla birlikte RFID, barkod ve QR kod konularında ele alınacaktır.

RFID etiketleri çok önemlidir; RFID ile WSN birleşimini konu alan çalışmalar vardır. Özellikle tedarik zincirinde ürünlerin bir kısmı barkodla, bir kısmı RFID etiketiyle etiketlenir; ürünlerin yolculuk sırasındaki rotaları ve yolda bir şey olup olmadığı bilgisi bu etiketler üzerinden izlenir. RFID etiketlerini bir WSN olarak adlandırmak pek mümkün olmasa da benzer bir yapı vardır. Genelde pasif etiketler kullanılır; aktif etiketler çok pahalıdır ve mekanizmaları daha karmaşıktır. Okuyucunun (reader) gönderdiği sinyalle pasif etiketlerden bilgi alınır. Bugün pek çok tedarik zincirinde yoğun olarak kullanılır, ama QR koda göre maliyeti yüksektir; bu yüzden RFID'nin gerekmediği alanlarda QR kod çok sık kullanılır. Örneğin anahtarın üzerine konan bir etiketle, anahtar kaybolunca yeri telefon üzerinden bulunabilir.

**Soru:** Kayıp eşya bulmak için satılan AirTag'ler hangi ağ tipine giriyor? **Cevap:** Hoca bunların da bir tür etiket olduğunu söyledi ve buna ek olarak Bluetooth ile haberleşen beacon'ların günümüzde çok sık kullanıldığını belirtti. Öğrenci AirTag'lerin Bluetooth ile haberleştiğini hatırlatınca hoca, sonuçta hepsinin radyo frekansı üzerinden haberleştiğini, farkın taşıdıkları frekanslarda ve protokolün getirdiği bant genişliği ve haberleşme yeteneğinde olduğunu açıkladı. Beacon kavramı önce iBeacon ile hayata girdi, sonra genel olarak beacon adıyla yayıldı. AirTag'ler kişinin eşyalarının konumunu izlemeye yönelik yeni bir yapıdır ve iş kullanımında da yaygınlaşacaktır, ama maliyetleri yaygınlaşmayı yavaşlatır.

> **Ders sonrası not:** Hoca AirTag'leri "yine RFID tag'lar" diye niteledi. AirTag'ler büyük olasılıkla RFID değil, Bluetooth Low Energy (ve ultra geniş bant, UWB) ile çalışan aktif, pilli cihazlardır; yakındaki telefonlar üzerinden konum bildirirler. Hocanın sonradan yaptığı "hepsi radyo frekansı üzerinden haberleşir" açıklaması bu açıdan doğrudur.

> **Hocanın vurgusu:** RFID etiketleri, AirTag'ler ve beacon'lar kapalı alan (indoor) konum tespiti için çok önemli hâle gelecektir.

> **Ek bilgi (derste anlatılmadı):** Bluetooth beacon'larıyla kapalı alan konumlandırmada büyük olasılıkla en yaygın yaklaşım olarak alınan sinyal gücü (RSSI) kullanılır: birden çok beacon'dan ölçülen sinyal gücünden uzaklık kestirilip üçgenleme yapılır ya da önceden toplanmış bir sinyal haritasıyla eşleştirme (fingerprinting) yapılır.

IoT bundan sonra WSN'den daha yoğun biçimde hayatımızda olacak, ama WSN'ler algılama kabiliyetleriyle tamamen çıkmayacak; özellikle açık alandaki uygulamaya özgü görevlerin izlenmesi ve sorunlarının çözülmesinde kullanılmaya devam edecektir.

## Örnek Sorular

**1. (derste sözlü, 00:47:54)** Sensör düğümleri aynı anda, senkron biçimde nasıl uyanır?

> **Cevap (derste verildi):** En sık kullanılan yöntem ortak bir zamanlayıcı mekanizmasıdır. Zamanla saatlerde kayma olduğundan düğümler belirli aralıklarla haberleşip zamanlayıcılarını eşitler. Diğer yöntemde gönderici önce "veri göndereceğim" bilgisini yollar; alıcılar bunu alıp veriyi alacakları moda geçer.

**2. (derste sözlü, 00:51:02)** Bir sensörün algılama menzili mi, haberleşme menzili mi daha uzundur?

> **Cevap (derste verildi):** Haberleşme menzili. Genelde algılama bir birim kapsıyorsa haberleşme iki birim kapsar (oran bire iki). Yerleşim iki özellik birlikte gözetilerek yapılmalıdır.

**3. (derste sözlü, 00:52:01)** Bir askeri kampın etrafından gelebilecek sızmaları tespit etmek için kampın çevresindeki dairenin her noktasını kapsamak gerekir mi? Orman yangını tespitinde nasıl bir kapsama hedeflenir?

> **Cevap (derste verildi):** Kamp için yalnız çevreyi izlemek yeterlidir; buna bariyer kapsama denir. Orman yangınında ise bütün alanın kapsanması gerekir; düğümler örtüşmeyecek ve kapsanmayan alan bırakmayacak biçimde yerleştirilmelidir (rastgele dağıtımda bu mümkün değildir).

**4. (derste sözlü, 00:53:59)** Her yönlü (omnidirectional) sensörlerin algılama alanları örtüşüyorsa ne yapmak gerekir? Yönlü (directional) sensörler örtüşüyorsa ne yapmak gerekir?

> **Cevap (derste verildi):** Her yönlü sensörlerde örtüşmeyi gidermek için düğümlerden birini hareket ettirmek gerekir (mobility). Yönlü sensörlerde (ör. kameralar) düğümü yerinden oynatmadan döndürerek (motility) örtüşen alan en aza indirilebilir. Döndürmenin maliyeti hareket ettirmekten düşüktür. Hareket yeteneği yoksa bölgeye ek düğüm gönderilir.

**5. (derste sözlü, 00:58:24)** Alana algılama yarıçapı $r$ olan $n$ adet her yönlü sensör atıldı. Rastgele atılmasaydı, en iyi yerleşimle ulaşılabilecek en büyük kapsama alanı ne olurdu?

> **Cevap (derste verildi):** Kesişme olmadığında bir sensör $\pi r^2$ alan kapsar; $n$ sensör en fazla $n\pi r^2$ alan kapsar. Bu değer, gerçek kapsamanın verimliliği hesaplanırken referans olarak kullanılır. (Bir öğrencinin önerdiği $2r \times 2r$ karede dairenin payı $\pi/4 \approx 0{,}785$'tir; ama sensör ağlarında modelleme dairesel yapılır.)

**6. (derste sözlü, 01:33:49)** Bir IoT ağı, bir sensör ağından nasıl ayrılır?

> **Cevap (derste verildi):** IoT cihazları fiziksel nesneye gömülüdür ve IP ile tek tek erişilebilir; IoT bulut ve büyük veriyle birlikte düşünülür; bilgi akışı simetriktir; bant genişliği geniştir ve çoklu ortam verisi taşınabilir; enerji kısıtı görece azdır; uçta işleme cihaz üzerinde yapılabilir. WSN'de ise yerel, çok atlamalı ve asimetrik iletişim, enerji kısıtı ve sınırlı bant genişliği vardır.

## Dersin Toparlaması

Bu derste kablosuz algılayıcı ağlar baştan sona ele alındı: algılama, küçük işlem ve iletme görevli, kaynakları kısıtlı düğümlerin donanımı; çok atlamalı ve yayın tabanlı iletişim; enerjinin en çok iletişimde harcanması ve bu yüzden uyku-uyanma döngülerinin ağın hayatta kalmasındaki rolü; ağ ömrü tanımı ve küme başlarının dönüşümlü kullanımı. Ardından WSN'lerin karakteristikleri (çok sayıda ve yoğun düğüm, asimetrik akış, sınırlı enerji, çoğunlukla statik topoloji), ağ gereksinimleri (enerji verimliliği, ölçeklenebilirlik, kendi kendini örgütleme) ve yerleşim problemi işlendi. Kapsama ile bağlantılılık ilişkisi, bariyer, tüm alan ve hedef kapsama, yönlü ve her yönlü algılama, motility ile mobility, en iyi kapsamanın $n\pi r^2$ olarak hesaplanması ve ikili ile olasılıksal kapsama modelleri dersin merkezindeydi.

Dersin son bölümünde topolojiler, bakım seçenekleri, protokol tasarım zorlukları, gizlilik ve güvenlik ile askeri, çevresel, sağlık ve yapı izleme uygulamaları anlatıldı. Kapanışta WSN'nin IoT'ye evrimi tartışıldı ve IoT'nin fiziksel nesneye gömülülük, IP ile erişim, bulut ve büyük veri gibi farkları ortaya kondu. Bir sonraki derste IoT ağları, RFID, barkod ve QR kod teknikleri ile büyük veri konularının işleneceği belirtildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
