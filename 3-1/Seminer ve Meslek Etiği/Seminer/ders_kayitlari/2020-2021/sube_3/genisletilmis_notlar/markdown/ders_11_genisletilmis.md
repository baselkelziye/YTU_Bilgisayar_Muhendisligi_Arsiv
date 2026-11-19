# Ders 11 Genişletilmiş Notu: Öğrenci Sunumları: Altın Oran, Efes Antik Kenti, Büyük Veri, Bulut Oyun, Video Oyunlarında DRM, Kutsal Roma İmparatorluğu, Uçaklarda Fren Sistemleri, 2011 NBA Playoff'ları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin İşleyişi
- 2. Altın Oran
- 3. Efes Antik Kenti
- 4. Büyük Veri ve Yapay Öğrenme
- 5. Bulut Oyun (Cloud Gaming)
- 6. Video Oyunlarında DRM
- 7. Kutsal Roma İmparatorluğu
- 8. Uçaklarda Fren Sistemleri
- 9. 2011 NBA Playoff'ları
- 10. Sunum Tekniğine Dair Değerlendirmeler
- Örnek Sorular

## 1. Dersin İşleyişi

Bu ders, seminer dersinin öğrenci sunumları bölümünün devamıdır. Sekiz öğrenci kendi seçtikleri konularda yaklaşık beş-on beş dakikalık sunumlar yaptı. Konular matematikten tarihe, bilişim teknolojisinden havacılığa ve spora kadar geniş bir yelpazedeydi.

Bazı öğrenciler ekranı kendileri paylaştı; bazılarının yansılarını hoca kendi ekranından açıp sunum moduna aldı ve öğrenci "bir sonraki yansıya geçebiliriz hocam" diyerek ilerletti. Her sunumun ardından dinleyicilere soru sorma fırsatı verildi. Soru gelmediğinde hoca kendisi sordu. Hoca, bu soruların bir sınav sorusu olmadığını, doğrusu ya da yanlışı bulunmadığını, seminer kapsamında dinleyiciyle etkileşim ve tartışma ortamı oluşturmak için sorulduğunu açıkça belirtti.

## 2. Altın Oran

### 2.1 Tanım ve Matematiksel Gösterim

Bir öğrenci altın oranı anlattı. Sunum dört soru etrafında kuruldu: altın oran nedir, matematiksel olarak nasıl gösterilir, Fibonacci dizisiyle ilişkisi nedir ve hayatta nerelerde görülür.

Tanım iki çubuk üzerinden verildi. Biri uzun (uzunluğu $a$), biri kısa (uzunluğu $b$) iki çubuk düşünelim. Uzun çubuğun kısa çubuğa oranı, iki çubuğun toplam uzunluğunun uzun çubuğa oranına eşitse bu orana altın oran denir:

$$\frac{a}{b} = \frac{a+b}{a}$$

Sunumda $b = 1$ kabul edilerek denklem çözüldü. Adımlar şöyledir (ara adım eklendi):

- $b = 1$ için eşitlik $a = \frac{a+1}{a}$ olur.
- İki taraf $a$ ile çarpılınca $a^2 = a + 1$, yani $a^2 - a - 1 = 0$ elde edilir.
- İkinci derece denklemin kökleri $a = \frac{1 \pm \sqrt{5}}{2}$'dir.
- $a$ bir uzunluk olduğundan negatif olamaz; pozitif kök alınır: $\varphi = \frac{1+\sqrt{5}}{2} \approx 1{,}618$.

Bu sayı $\varphi$ (fi) harfiyle gösterilir ve irrasyoneldir: ondalık açılımı 1,618... diye sonsuza kadar devam eder.

### 2.2 Altın Spiral

Altın oranı simgeleyen spiral şöyle elde edilir. Bir altın dikdörtgenle (kenarları oranı $\varphi$ olan dikdörtgen) başlanır. Bu dikdörtgen, tıpkı çubuk örneğindeki gibi, bir kare ve daha küçük bir altın dikdörtgen olacak şekilde bölünür. Kalan altın dikdörtgen yine bir kare ve bir altın dikdörtgene bölünür ve bu böyle sürer. Sonunda her kareye bir çeyrek çember çizilir; bu çeyrek çemberler birleşerek tanıdık altın spirali oluşturur.

### 2.3 Fibonacci Dizisiyle İlişkisi

Fibonacci dizisi 0 ve 1 ile başlar; sonraki her terim son iki terimin toplamıdır: 0, 1, 1, 2, 3, 5, 8, 13, 21, ... Sunan öğrenci, dizideki ardışık iki terimin oranının terimler büyüdükçe altın orana yaklaştığını gösterdi: 2/1 = 2, 3/2 = 1,5 ve böyle devam eder. Oranlar sonsuza gidildiğinde altın oranı verir.

Oranların ilk birkaçı şöyledir (ara adım eklendi, python ile doğrulandı): 2/1 = 2, 3/2 = 1,5, 5/3 ≈ 1,667, 8/5 = 1,6, 13/8 = 1,625, 21/13 ≈ 1,615, 34/21 ≈ 1,619. Görüldüğü gibi oranlar $\varphi \approx 1{,}618$'in bir altında bir üstünde kalarak ona yaklaşır.

### 2.4 Altın Oranın Görüldüğü Yerler

Sunuma göre altın oran doğada pek çok yerde görülür: papatya, kozalak, salyangoz kabuğu (yansıdaki görselde spiral açıkça seçiliyordu), örümcek ağı, kar taneleri ve uzaydaki galaksiler. İnsan yüzünde de altın oran olduğu söylenir; örneğin yansıda yüzdeki iki uzunluğun oranı $b/a = 1{,}618...$ olarak işaretlenmişti (ekrandan, 00:05:00). Sunan öğrenciye göre bu oranlar özellikle "kusursuz" kabul edilen yüzlerde görülür.

İnsanlar altın oranı eserlerinde de kullanmıştır: Mısır piramitleri, Parthenon tapınağı, Mona Lisa tablosu ve Venüs pentagramı örnek verildi. Bu yaygınlık nedeniyle altın oranı araştıranlar ona "kutsal oran" ya da "ilahi oran" adını vermiştir.

### 2.5 Soru-Cevap

**Soru (hoca):** Altın oran küçücük bir salyangozdan galaksilere kadar çok farklı ölçeklerde görülüyor. Bu tekrarı neye yoruyorsunuz?

**Cevap:** Sunan öğrenci, bu kadar yaygın bir tekrara tesadüf demenin mantıklı gelmediğini, ancak bilimsel bir kanıtı da bulunmadığını söyledi. Hoca, eski çağlarda her şeyin ilahiyata bağlandığını, günümüzde ise her şeyin manevi boyuttan uzaklaştırılmaya çalışıldığını, ikisinin arasında bir denge bulmak gerektiğini belirtti ve şöyle bir yorum önerdi: Evren çeşitli kurallar üzerine kuruludur; altın oranın farklı ölçeklerde tekrar etmesi bu kuralların genelliğinin bir örneği olarak yorumlanabilir.

**Soru (hoca):** İnsanların altın oranı bulma tutkusunun, hatta takıntısının altında ne yatıyor olabilir?

**Cevap:** Sunan öğrenci, insanın nereden geldiğini açıklayan bir teori arayışı olabileceğini söyledi. Hoca buna insanlığın mükemmelliğe ulaşma arzusunu da ekledi.

## 3. Efes Antik Kenti

### 3.1 Giriş

Bir öğrenci Efes Antik Kenti'ni anlattı. Sunum giriş, kuruluş efsanesi, tarih, mimari ve önemli yapılar başlıklarından oluştu.

Yansıya göre Efes, antik çağın önemli liman kentlerinden biridir; Roma devrinde Asia eyaletinin başkenti ve aynı zamanda politik, ekonomik ve ticari bir merkezdir. Binlerce yıllık Ana Tanrıça kültünün devamı olarak Artemis'e adanmış tapınağı, dünyanın yedi harikasından biridir; bu yönüyle Efes önemli bir din merkezidir. Efes tarihi boyunca çeşitli nedenlerle dört kez yer değiştirmiş, bu yüzden kalıntıları çok geniş bir alana yayılmıştır ve 150 yılı aşkın süredir kazı çalışmaları sürmektedir. Bugün gezilen Efes, kentin üçüncü kez kurulduğu Bülbül Dağı ile Panayır Dağı arasındaki yerdir. Kent 2015'te UNESCO Dünya Mirası Listesi'ne alınmıştır (ekrandan, 00:10:00).

### 3.2 Kuruluş Efsanesi

Hadrianus Tapınağı'nın girişindeki yazıtta anlatıldığına göre Atina kralının oğlu Androklos bir arayışa çıkar ve sonunda kent kurulur. <!-- BELİRSİZ: efsanenin ayrıntısı 00:10:14-00:10:42 arasında altyazıda yer almıyor. -->

> **Ek bilgi (derste anlatılmadı):** Efsanenin yaygın anlatımında Androklos'a kâhin, kentin yerini bir balık ve bir yaban domuzunun göstereceğini söyler. Androklos kızartılan balığın sıçratığı ateşle çalılıkların tutuştuğunu, oradan kaçan yaban domuzunu avladığı yerde kenti kurduğunu anlatır. Bu sahne büyük olasılıkla Hadrianus Tapınağı'nın kabartmalarında yer alır.

### 3.3 Tarihçe

Bölgedeki yaşam MÖ 8000'lere kadar uzanır ve Çukuriçi Höyük'te başlar. Daha sonra yerleşim Ayasuluk bölgesine taşınır. Sunuma göre MÖ 300'lerde Büyük İskender bölgeyi fethetmiş, kentin kötü durumda olduğunu görüp yeniden taşınmasını istemiş; kent bugünkü konumuna taşınmıştır. Ardından bölgede bir general etkili olmuştur. <!-- BELİRSİZ: generalin adı altyazıda "Simkos" diye geçiyor, büyük olasılıkla Lysimakhos. -->

> **Ders sonrası not:** Büyük İskender'in Efes'e gelişi büyük olasılıkla MÖ 334'tür; kentin bugünkü yerine taşınması ise İskender'in generallerinden Lysimakhos döneminde, MÖ 3. yüzyılın başında olmuştur.

Kent Roma yönetimi altında altın çağını yaşar; sonra sırasıyla Bizans, Selçuklu, Aydınoğulları Beyliği ve Osmanlı Devleti'nin eline geçer. Bugün İzmir'in Selçuk ilçesi sınırlarındadır.

### 3.4 Mimari

Resmi ve kutsal yapılar düz alanlara, konutlar ise dağ yamaçlarına yerleştirilmiştir. Cadde ve sokaklar birbirini dik açıyla keser. Bu düzene ızgara plan denir. <!-- BELİRSİZ: kurucusu altyazıda "Hipodomus" diye geçiyor, büyük olasılıkla Miletoslu Hippodamos. --> Zamanına göre yüksek teknoloji ve ustalık gerektiren yapılar inşa edilip süslenmiştir. Efes zamanının en büyük metropollerinden biriydi; nüfusunun yaklaşık 200-250 bin olduğu tahmin edilir. Zamanla limanını kaybedince önemini de yitirmiştir.

### 3.5 Önemli Yapılar

Sunumun son bölümünde yapılar yansı yansı tanıtıldı:

- Liman Caddesi ve Büyük Tiyatro: tiyatro, zamanın önemli sahne gösterilerinin yapıldığı 25 bin kişilik bir yapıdır.
- Celsus Kütüphanesi: aynı zamanda bir anıt mezardır; Celsus'un oğlu tarafından babasını onurlandırmak için yaptırılmıştır. Cephedeki dört heykel sunuma göre fazilet, ilim ve zekâ gibi erdemleri temsil eder. <!-- BELİRSİZ: dördüncü erdem altyazıda "kader" diye geçiyor, büyük olasılıkla Whisper hatası. -->
- Agora (ticari pazar), Oktagon (Kleopatra'nın kız kardeşi IV. Arsinoe'nin mezarı olduğu düşünülür) ve Hadrianus Kapısı.
- Yamaç Evler (dönemin zenginlerinin misafir ağırladığı evler), Skolastika Hamamları ve Hadrianus Tapınağı (girişinde kuruluş efsanesinin yazısı bulunur; Roma İmparatoru Hadrianus adına yapılmıştır).
- Traianus Çeşmesi (iki katlı) ve Herakles Kapısı (sunuma göre dönemin soylularının kullandığı kapı).
- Kuretler Caddesi: hem dini hem idari işlere bakan rahiplere Kuret denirdi; caddenin girişindeki sütunlarda Kuretlerin adları yazılıdır.
- Devlet Agorası (dini ve siyasi toplantıların yapıldığı, devlet memurlarının ofislerinin bulunduğu yer) ve hamamları; ticaret merkezi Bazilika ve meclis toplantı alanı.
- Meryem Kilisesi ve dönemin belediye binası Prytaneion.

### 3.6 Soru-Cevap

Hoca, Efes'le ilişkilendirilen başka bir anlatıyı, Yedi Uyurlar mağarasının da kent yakınında olduğu iddiasını sordu. Sunan öğrenci mağaranın kentin tam içinde değil, yakınında olduğunu söyledi. Hoca, eski anlatıların kökenini ve yerini tespit etmenin kolay olmadığını, Yedi Uyurlar mağarası olduğu iddia edilen birden fazla yer bulunduğunu ve değişik toplulukların sevilen anlatıları sahiplendiğini belirtti. Sunan öğrenci ayrıca Artemis Tapınağı'nın bugün tamamen yıkılmış olduğunu ekledi. Hoca, ülkemizde yapılan her kazıda tarihi kalıntıların çıktığını (Haydarpaşa Garı yakınındaki Bizans dönemi kalıntıları örneği) ve bu toprakların değerinin bilinmesi gerektiğini söyledi.

## 4. Büyük Veri ve Yapay Öğrenme

### 4.1 Veri ve Veri Türleri

Bir öğrenci büyük veriyi ve yapay öğrenmeyle ilişkisini anlattı. Sunum veri, büyük veri, büyük verinin doğuşu ve büyümesi, yapay öğrenmeyle ilişkisi, avantajları, dezavantajları ve sınırları başlıklarından oluştu.

Verinin birçok tanımı vardır. Bilgisayar bilimleri bağlamında veri, bilgisayarların işleyebileceği bir forma dönüştürülmüş gerçekler topluluğudur. Veri kaynakları aslında sınırsızdır. Bilgisayarda saklanma biçimine göre üç tür ele alındı:

- Tablo verisi (tabular data): Excel gibi bir tabloda saklanabilecek bilgiler.
- Görüntü verisi: yapay öğrenmeye başlayan herkesin ilk karşılaştığı veri setlerinden olan, rakam görüntülerinden oluşan MNIST; 32 karelik videolardan oluşan, video üretimi çalışmalarıyla ünlenen UCF101.
- Metin verisi: sosyal medya yorumları, kitaplardaki cümleler gibi her türlü metin.

### 4.2 Büyük Verinin Tanımları ve Doğuşu

Büyük verinin bağlama göre farklı tanımları vardır. İlk tanıma göre büyük veri, normal kişisel bilgisayarlara sığmayan veridir. Yapay öğrenmedeki kullanımda ise analiz edilip sınıflandırılmış, anlamlı ve işlenebilir hale getirilmiş veriyi ifade eder.

Sunan öğrenci büyük verinin doğuşunu şöyle anlattı: 1960'larda bir ofisteki veriye herkes erişemiyordu. Verinin dijital ortamda birikmesiyle dünyanın her yerindeki insanlar veriye ulaşabilir hale geldi. Bunda, insanların kendi verilerini ücretsiz olarak sunduğu büyük şirketler öncülük etti. Yansıda bu şirketler ve topladıkları veri türleri şöyle verildi (ekrandan, 00:20:00):

| Şirket | Kuruluş | Veri türü |
|---|---|---|
| Google | 1998 | Metin, kişisel bilgiler |
| Facebook | 2004 | Metin, görüntü, kişisel bilgiler |
| YouTube | 2005 | Görüntü |
| Twitter | 2006 | Metin, kişisel bilgiler |

### 4.3 Büyük Verinin Büyümesi

Büyük veri birden fazla boyutta incelenir: hacim, hız, çeşitlilik, doğrulama ve değer. Büyümeden söz edildiğinde akla ilk gelen iki boyut hacim ve hızdır. Veri çok hızlı üretildiği için hacim de o hızla genişler; sunan öğrenciye göre bu durum ileride ciddi sorunlar doğuracaktır.

### 4.4 Yapay Öğrenmeyle İlişkisi

Veriden karara giden süreç dört adımda anlatıldı:

- Veri işlenmemiş, ham halde gelir.
- Bir veri mühendisi veriyi işler ve öğrenme algoritmalarına verilecek hale getirir.
- Yapay öğrenme algoritmaları veriden anlam çıkarır, matematiksel çıkarımlar yapar.
- Yapay zekâ sistemleri bu çıkarımlarla karar verme aşamasına gelir.

### 4.5 Avantaj, Dezavantaj ve Sınırlar

Büyük verinin avantajı, özellikle derin öğrenme algoritmalarında görülür: veri miktarı arttıkça başarı oranı da artar. Geleneksel makine öğrenmesi algoritmalarında ise başarı çok erken bir asimptota ulaşır; belli bir veri miktarından sonra daha fazla veri başarıyı pek artırmaz.

Dezavantajı işleme süresidir. Veri miktarı arttıkça işleme zamanı da çok artar. GPU ve TPU'ların ortaya çıkması bu süreyi çok kısaltmış olsa da, özellikle derin öğrenmede verinin işlenme süresi hâlâ büyük bir sorundur.

Sınırlara gelince, hem derin öğrenme hem geleneksel yöntemler eninde sonunda bir asimptota ulaşır ve algoritma daha fazla öğrenemez hale gelir. Sunan öğrenci bunu fizikteki Heisenberg belirsizlik ilkesine benzetti: konum ve momentum aynı anda tam bilinemediği gibi, makine öğrenmesi algoritmaları için de her zaman %100 başarıya ulaşılabileceği söylenemez.

> **Ek bilgi (derste anlatılmadı):** Makine öğrenmesinde ulaşılabilecek en iyi başarının sınırı genelde verinin kendisindeki gürültüyle açıklanır. Aynı girdiye farklı etiketler düşebiliyorsa hiçbir model bu hatanın altına inemez; buna indirgenemez hata ya da Bayes hatası denir. Heisenberg benzetmesi sezgisel bir benzetmedir, iki durum arasında fiziksel bir bağ yoktur.

### 4.6 Soru-Cevap: Araçlar ve Tümleştirme

**Soru (hoca):** Makine öğrenmesi ve derin öğrenmede pratik olarak hangi araçları, programlama ortamlarını kullanabiliriz?

**Cevap:** Derin öğrenmede en çok kullanılan diller Python, C++ ve Julia'dır; geleneksel makine öğrenmesinde bunlara R da eklenir. Python'da Google'ın geliştirdiği TensorFlow ve Facebook'un geliştirdiği PyTorch gibi büyük kütüphaneler vardır. C++ tarafında yine Torch kütüphanesi bulunur; sunan öğrenciye göre gömülü sistemlerle çalışıldığı için özellikle görüntü işlemede ve savunma sanayinde Python yerine C++ çok kullanılır. Julia dilinde Koç Üniversitesi'nden Deniz Yüret'in geliştirdiği Knet kütüphanesi vardır; derin öğrenmede çok hızlı çalışır ve Julia matris işlemlerinde hem Python'dan hem C++'tan hızlıdır. Bu yüzden Julia'nın bu alanda geleceği parlak görünse de şu an bir sunucuda çalıştırmak gibi konularda zorluk çıkarır.

**Soru (hoca):** Julia'nın çalışma ortamı konteyner haline getirilir, bir mikroservis olarak sunulursa taşınabilirliği ve başka sistemlerle birlikte çalışabilirliği artmaz mı?

**Cevap:** Sunan öğrenciye göre asıl sorun topluluktur. PyTorch ya da TensorFlow'un topluluğu çok geniştir; bir sorunla karşılaşıldığında çözüm kolay bulunur. Julia'nın topluluğu ise çok daha dardır. Julia'da kendine özgü paketlerle kolayca uygulama geliştirilebilir, ama Knet henüz o kadar gelişmiş değildir; bildiği kadarıyla evrişimli sinir ağları kolayca kurulabiliyor, diğer yapılarda sorun çıkıyor. Topluluğun büyümesi gerekir.

**Soru (hoca):** Python, Java ya da .NET gibi ana akım platformlarla nasıl tümleştirilebilir? Yalnız öğrenmenin sonuçlarını aktarmaktan öte, daha etkileşimli bir tümleştirme mümkün mü?

**Cevap:** Öğrenme sonucunda elde edilen sonucun bir yerde kullanılması gerekir ve Python bunun için çok imkân sunar. Pekiştirmeli öğrenmede Pygame kütüphanesi eklenerek öğrenilen davranış doğrudan bir oyun üzerinde gösterilebilir. Flask gibi kütüphanelerle hızlıca bir web sitesi kurulup sonuçlar oraya aktarılabilir. Grafik arayüz yazılabilir. Node.js ile kurulmuş bir web sitesinin NoSQL veritabanından veri çekilip öğrenme algoritmalarında kullanılabilir. Python'ın yalnız makine öğrenmesinde değil her alanda geniş bir topluluğa sahip olması, bunların hepsinin bir arada kullanılabildiği bir ortam yaratır.

Hoca bu sunumun ardından konu seçimine dair önemli bir hatırlatma yaptı (bkz. bölüm 10).

## 5. Bulut Oyun (Cloud Gaming)

### 5.1 Tanım ve Çalışma Prensibi

Bir öğrenci, uzun süredir var olan ama yeni yeni yaygınlaşan bulut oyun kavramını anlattı (ekrandan, 00:30:00). Sunumun başlıkları: bulut oyun ve çalışma prensibi, gereksinimler, avantajlar ve dezavantajlar, özet.

Bulut bilişim bugün herkesin hayatındadır: internetten dizi ve video izlemek, müzik dinlemek, dosya yedeklemek. Bulut oyun da bulut bilişimi kullanarak düşük donanımla yüksek performanslı oyun oynamayı sağlayan bir hizmettir.

Çalışma mantığı şöyledir: Kullanıcı bulut oyun servisine bağlanıp oyunu açar. Oyun aslında kullanıcının bilgisayarında değil, uzaktaki hizmet sağlayıcının sunucularında çalışır. Kullanıcı bir komut verdiğinde komut sunucuda işlenir ve çıktı kullanıcıya internet üzerinden yalnızca görüntü olarak gönderilir.

### 5.2 Gereksinimler

- İnternet bağlantısı: en önemli gereksinimdir. Yansıda bir bulut oyun servisinin (Nvidia GeForce Now) kararlı performans için önerdiği bağlantı hızları gösterildi. Gecikmeyi en aza indirmek için kablolu bağlantı avantajlıdır.
- Donanım: video oynatabilen ve internete bağlanabilen herhangi bir cihaz yeterlidir; sunan öğrenciye göre ileride de yeterli olacak gibi görünmektedir.
- Konum: gecikmeyi azaltmak için hizmet sağlayıcının sunucularına yakın bir yerde bulunmak önemlidir.

### 5.3 Avantajlar ve Dezavantajlar

Avantajlar:

- Donanım fiyatları sürekli artarken pahalı donanıma para harcamak gerekmez.
- İstenen oyun istenen platformdan oynanabilir: telefon, doğrudan televizyonun kendisi, hatta bir akıllı buzdolabı (yansıda buzdolabında Doom oynanan bir görsel vardı). Ayrı bir konsola gerek kalmaz.
- Yüzlerce gigabaytlık oyunları indirme ve depolama zahmeti ortadan kalkar; oyunlar sunucuda depolanır.
- Bazı servisler promosyon olarak her ay ücretsiz oyun verir.

Dezavantajlar:

- Çevrim dışı oynamak hiçbir şekilde mümkün değildir.
- İnternet bağlantısı güçlü ve kararlı değilse görüntüde dalgalanmalar olur, oyun deneyimi kötüleşir.
- Gecikme süresi rekabetçi oyunlar için hâlâ fazladır; hikâye tabanlı oyunlarda tatmin edici hizmet alınabilir.
- Yüksek bant genişliği gerektirdiği için kotalı internet kullananlara uygun değildir.

### 5.4 Özet ve Eğilim

Sunan öğrenciye göre eskiden müzik, film gibi her şey satın alınırken artık aylık abonelikle kiralanmaktadır (müzik ve dizi servisleri örneği). Konsollar ve bilgisayarlar da bu yöne ilerlemektedir: güçlü donanıma sahip olmak yerine güçlü bir internet bağlantısıyla bu tür hizmetlerin kullanılacağı düşünülmektedir. Yansıda bulut oyun pazarının yıllara göre milyon dolar bazında büyümesi ve beklenen büyüme gösterildi.

### 5.5 Soru-Cevap: Lisans Anlaşmazlıkları

Hoca, bulut ve dijital dağıtım alanındaki iki anlaşmazlığı sordu: bir uygulama mağazasıyla oyun motoru geliştiren bir firma arasındaki sorun ve bazı oyunların bulut servislerinden çekilmesi. Sunan öğrenci bunları şöyle açıkladı:

- Epic Games, Fortnite'ta Apple'a komisyon ödemeden oyun içi para satın alınabilecek bir sistem kurdu. Bunun üzerine Apple tepki gösterdi ve iki firma davalık oldu. Sunan öğrenciye göre bu süreçte Unreal Engine kullanan oyunlar da etkilendi, sonra bu kısım çözüldü ama Epic ile anlaşmazlık sürdü.
- GeForce Now ilk çıktığında, ilk ay içinde bazı oyun firmaları "oyunumuzu bizden habersiz yayınlıyorsunuz" diyerek oyunlarını servisten çekti. Bu, oyuncuların tepkisini çekti; zamanla bazı oyunlar geri geldi.

> **Ders sonrası not:** Apple, 2020'de büyük olasılıkla Unreal Engine kullanan bütün oyunları kaldırmadı; Fortnite'ı kaldırdı ve Epic'in Unreal Engine için kullandığı geliştirici hesabını kapatmakla tehdit etti. Mahkeme, büyük olasılıkla Unreal Engine'e yönelik bu adımı geçici olarak engelledi.

Hoca, yeni bir hizmet ortaya çıktığında mevcut süreçleri epey sarsabildiğini, ama sonunda bir orta yol bulunduğunu söyledi.

## 6. Video Oyunlarında DRM

### 6.1 DRM Nedir?

Bir öğrenci video oyunlarında kullanılan DRM sistemlerini anlattı. DRM (Digital Rights Management, Türkçesiyle dijital haklar yönetimi), film, müzik, oyun ve benzeri dijital medyalarda telifli çalışmaların lisans haklarını kontrol etmek için geliştirilmiş bir kontrol sistemidir. Genelde oyun, yazılım ve müzik şirketleri ile yayıncılar tarafından satış sonrasında korsanla mücadele için kullanılır.

### 6.2 Amaçları

- Oyunun korsan yoldan edinilmesini engelleyerek kazancı artırmak.
- Çevrim içi oyunlarda adaleti sağlamak ve hileleri engellemek.

### 6.3 Uygulamalar

Yansıda uygulamalar iki ana grupta verildi (ekrandan, 00:40:00):

- Lisans doğrulama
  - Çevrim içi aktivasyon: Tüketicinin oyunu yasal yoldan edindiğinden emin olmak için oyunu etkinleştirmesi istenir. Etkinleştirme, oyunun satın alındığı sitedeki hesap üzerinden ya da lisans anahtarı üzerinden yapılabilir. Tek seferlik olabilir.
  - Daimi çevrim içi zorunluluk (always-on DRM): Oyunun çalışması için sürekli internet bağlantısı gerekir.
- Dosya doğrulama
  - Oyuna ait dosyalar kontrol edilir; amaç daha çok hile ve benzeri durumları engellemektir. Kontrol yalnız oyun başlatılırken ya da oyun çalışırken arka planda sürekli yapılabilir.

Firmalar bir oyunda aynı anda birden fazla DRM kullanabilir.

### 6.4 Zararları

- Maliyet: Bazı firmalar kendi DRM'lerini kullanır, bazıları başka firmalarla anlaşıp onların DRM'ini kullanır. DRM eklemek için bütçe ayrılır; maliyet artınca oyun tüketiciye daha pahalı sunulur.
- Daimi çevrim içi zorunluluk: Tüketici sunucuya bağlanamazsa oyunu oynayamaz. Örnek, 2013'te çıkan SimCity'dir: oyun internet bağlantısı olmadan oynanamıyordu ve ilk günlerde sunucular satın alan kişi sayısına yetmediği için oyunu neredeyse kimse oynayamadı.
- Sürekli çalışan DRM: Oyun çalışırken arka planda sürekli çalıştığı için sisteme binen yükü artırır; oyuna ayrılan kaynak azalır ve oyun yavaşlar. En belirgin örnek Denuvo'dur; yansıdaki grafikte Abzû oyununun Denuvo ile ve DRM'siz yükleme süreleri karşılaştırıldı.
- Kernel seviyesinde DRM: Bazı DRM'ler işletim sisteminin çekirdek (kernel) seviyesinde çalışır. İşletim sistemini doğrudan etkilediği için güvenlik sorunu yaratabilir ve oyun açık olsun kapalı olsun sistem performansını etkiler.

### 6.5 Soru-Cevap

**Soru (bir öğrenci):** Yakın zamanda yeni oyununu çıkaran CD Projekt Red DRM'e karşı çıkıyor. Bunun sebebini biliyor musunuz?

**Cevap:** Firma, iyi ve kaliteli oyunların DRM'e ihtiyaç duymadan da satın alınacağını düşünüyor; sunan öğrenciye göre haklılar, son oyunları da çok sattı.

**Soru (hoca):** Sizin DRM konusundaki yaklaşımınız nedir?

**Cevap:** Sunan öğrenci, oyunların genel olarak DRM'e ihtiyacı olmadığını düşündüğünü söyledi: alacak kişi zaten alır, almayacak kişi kırılmasını bekler; çevrim içi olmayan oyunların büyük kısmı kısa sürede kırılmaktadır. Hoca bunu "hırsızlık engellenmez" sözüne benzetti. Ayrıca bir oyunun eski nesil konsollarda performans sorunu yaşadığı haberlerine değinerek, zaten performans sorunu olan bir oyuna DRM ile ek yük bindirmenin mantıklı olmadığını söyledi.

## 7. Kutsal Roma İmparatorluğu

### 7.1 Genel Yapı

Bir öğrenci Kutsal Roma İmparatorluğu'nun yapısını, ordusunu ve dinini anlattı.

Kutsal Roma İmparatorluğu 962-1806 yılları arasında, yani 844 yıl boyunca Orta Avrupa'da hüküm sürmüş bir monarşidir. Alman Krallığı temelinde kurulmuştur, ama aslında bir devletçikler bütünüdür. Tek bir hanedanın malı değildir; Habsburg, Hohenzollern, Wettin, Wittelsbach ve Oldenburg gibi Avrupa'nın farklı yerlerinden hanedanlar imparatorlukta söz sahibidir. Hanedan topraklarının dışında kilise toprakları ve özel statüye sahip imparatorluk kentleri de vardır.

Sunan öğrenciye göre imparatorlar Habsburg hanedanından seçilir. Ortaçağ imparatorları Antik Roma'nın geleneklerini taşıdıklarını söyler, ama halkı genelde Almanlardan oluşan imparatorluğun Roma ile pek ilgisi yoktur. Modern Almanya ve Avusturya'nın temellerini oluşturur. Geniş yetkili bir monarşi olarak kurulmasına rağmen zamanla küçük devletlerin ve şehir devletlerinin gevşek bir konfederasyonuna dönüşür.

I. Otto 962'de Alman kralı olarak taç giyer; bazı tarihçilere göre ilk Kutsal Roma imparatoru odur. Roma imparatoru unvanını ilk kullanan Şarlman'dır; Otto ise Karolenj hanedanından olmayan ilk imparatordur. Son Kutsal Roma imparatoru Napolyon Savaşları sırasında tahttan çekilir ve imparatorluğu fesheder.

> **Ders sonrası not:** Sunumda imparatorların yalnız Habsburg hanedanından seçildiği söylendi. Bu büyük olasılıkla 15. yüzyıldan sonrası için geçerlidir; sunumun kendisinin de belirttiği gibi I. Otto başka bir hanedandandır. Son imparator büyük olasılıkla II. Franz'dır (1806).

İmparatorluğun sınırları tarih boyunca değişir. En güçlü döneminde bugünkü Almanya, Avusturya, İsviçre, Lihtenştayn, Lüksemburg, Çekya, Slovenya, Belçika ve Hollanda'nın toprakları ile Polonya, Fransa ve İtalya'nın bir kısmını kapsar. Tarihinin büyük bölümünde yüzlerce küçük krallığı, prensliği, düklüğü, kontluğu ve şehir devletini hakimiyeti altında tutar.

### 7.2 Merkezi Olmayan Yönetim

Kutsal Roma İmparatorluğu bugünkü devletler gibi merkezi değildir. Krallıklar, düklükler, kontluklar, piskoposluklar ve manastırlar gibi onlarca, hatta yüzlerce kurum bir araya gelerek onu oluşturur; bunların yanında doğrudan imparator tarafından yönetilen bölgeler de vardır. İmparatorun yetkisi hiçbir zaman sınırsız olmaz, çok sayıda yerel kurum tarafından sınırlandırılır.

Ortaçağın sonlarından itibaren imparatorluk, yerel güçlerin egemenlik için birbiriyle mücadele ettiği gevşek bir birliğe dönüşür. Fransa ve İngiltere gibi diğer monarşilerle karşılaştırıldığında imparatorlar ülke üzerinde kontrol kazanmakta başarılı olamamıştır. Tersine, birçok imparator iktidarını güvenceye almak için yerel yöneticilere, soylulara ve piskoposlara giderek daha fazla özerklik vermek zorunda kalmıştır. Sunuma göre bu süreç 11. yüzyılda piskopos atama yetkisi üzerine yaşanan atama kavgasıyla başlamış ve 1648 Vestfalya Barışı ile sonuca bağlanmıştır. Merkezileşme girişimleri sürekli papalığın ve prenslerin direnişiyle karşılaşmıştır.

### 7.3 İmparatorluk Diyeti

Sunumun en ayrıntılı kısmı imparatorluğun meclis yapısıydı. Yansıdaki metne göre (ekrandan, 00:50:00) imparatorluk diyeti (Reichstag ya da Reichsversammlung) bugünkü meclisler gibi bir yasama meclisi değildi; üyelerinin karar verme hakkı yoktu ve müzakere için toplanan merkezi bir foruma benziyordu. Diyet teorik olarak imparatorun üstündeydi ve üç organdan oluşuyordu:

- Elektörler Meclisi (Kurfürstenrat): Roma kralını seçme yetkisi olan elektör prenslerden oluşurdu. Sayıları 1356'da çıkarılan Altın Boğa (Golden Bull) ile yedi olarak belirlendi; 1648'de Vestfalya Barışı ile sekize, 1692'de dokuza çıktı; 1777'de iki prensliğin birleşmesiyle yeniden sekize düştü.
- Prensler Meclisi (Reichsfürstenrat): Elektör olmayan prenslerden oluşurdu ve iki gruba ayrılırdı: laik prensler ve ruhani prensler. Büyük prenslerin bireysel oy hakkı vardı; küçük prenslikler coğrafi olarak "college" adıyla gruplanır ve her grup bir oya sahip olurdu. Meclisin yönetimi Salzburg Başpiskoposluğu ile Avusturya Arşidüklüğü arasında gidip gelirdi. 1800'de bu meclisteki 100 sandalyenin 37'si ruhani, 63'ü laik prensliklere aitti.
- İmparatorluk Şehirleri Meclisi (Städterat): Özgür imparatorluk şehirlerinden oluşurdu ve iki gruba ayrılırdı: Svabya ve Ren. Diğer meclislerle aynı yetkilere sahip değildi; örneğin yeni bölgelerin imparatorluğa katılması gibi konularda oy hakkı yoktu. Diyetin bir parçası sayılması Ortaçağın sonlarına doğru yaygınlaştı, ama resmi katılımı ancak 1648'de oldu.

### 7.4 Ordu ve Din

İmparatorluk ordusu (Reichsarmee) 1422'de oluşturuldu ve Napolyon Savaşları'ndan hemen önce ortadan kalktı. İmparatora ait bir ordu değildi; sunan öğrenci bunun Almanya'nın ordusuyla karıştırılmaması gerektiğini vurguladı. İmparatorluk tehlikeye düştüğünde üye devletlerin birliklerinin bir araya gelmesiyle oluşan bir orduydu; askerler daha çok kendi yerel yönetimlerine bağlıydı.

Din açısından 1555'e kadar Katolik Kilisesi tek resmi kiliseydi. Avrupa'daki mezhep savaşlarından sonra 1555 Augsburg Barışı ile Luthercilik, 1648 Vestfalya Barışı ile Kalvinizm resmi olarak tanındı. Bu iki Protestan mezhebinin dışında Anabaptizm ve Arminyanizm gibi mezhepler de vardı, ama resmi olarak tanınmıyorlardı. Augsburg Barışı'ndan sonra "cuius regio, eius religio" (kimin toprağıysa onun dini) ilkesine geçildi: bir toprağın resmi dini, o toprağın yöneticisinin dini sayıldı. İmparatorlukta ayrıca bir Yahudi azınlık da vardı.

### 7.5 Soru-Cevap

**Soru (hoca):** Diyet nasıl bir kavram ya da birimdir?

**Cevap:** İmparatorlukta genelde Avusturya'yı yöneten kişi imparatordu. Avrupa'daki prenslik ve benzeri devletler bir mecliste toplanırdı. Bunlardan tarihe göre yedi ya da sekiz tanesi elektör olarak katılır ve imparatoru seçerdi: imparator Habsburg hanedanından gelirdi, ama hanedandan kimin imparator olacağına elektörler karar verirdi. Diğer prenslikler de bir araya gelir, imparatorluk hakkında karar alınacağı zaman toplanıp aralarında konuşurlardı; ama son kararı her zaman imparator verirdi. Sunan öğrenci bunu Osmanlı'daki meşrutiyet dönemine benzetti.

Hoca bu soruyu sorma nedenini de açıkladı (bkz. bölüm 10.2).

**Soru (hoca):** Atama kavgasının 11. yüzyılda başlayıp 1648'e kadar, yani yaklaşık 650 yıl sürmesi çok uzun görünüyor. Bu nasıl açıklanabilir?

**Cevap:** Sunan öğrenci, imparatorluğun dış güçlere karşı bir araya gelmiş küçük devletlerden oluşan oldukça soyut bir yapı olduğunu, bu yüzden aralıksız bir savaş değil, her yeni imparator seçildiğinde yeniden başlayan bir yetki ve başa geçme mücadelesi söz konusu olduğunu açıkladı. Vestfalya'dan sonra da imparatorluk birkaç yüzyıl daha sürüp sona ermiştir.

Hoca o sırada bir kaynağa bakarak, atama krizinin İngiltere'de özellikle 1103-1107 yılları arasında papa ile İngiltere kralı I. Henry arasında yoğunlaştığını, Almanya'da ise yaklaşık 50 yıllık bir iç savaşa yol açtığını aktardı; yani bir tepe noktası olduğunu, sonra "yorgan gitti, kavga bitti" denene kadar sönümlendiğini söyledi.

> **Ders sonrası not:** Atama kavgası Almanya'da büyük olasılıkla 1122 Worms Konkordatosu ile resmen sona ermiştir. Sunumda 1648 Vestfalya Barışı'na bağlanan süreç, kavganın kendisi değil, büyük olasılıkla imparatorun yetkisinin prenslere karşı zayıflama sürecidir.

## 8. Uçaklarda Fren Sistemleri

### 8.1 Üç Fren Sistemi

Bir öğrenci uçakların fren sistemlerini anlattı. Uçaklarda üç fren sistemi vardır:

- Tekerleklerdeki disk frenler.
- Kanatlardaki spoiler'lar.
- Motorlardaki ters itme sistemleri (thrust reverser).

### 8.2 Disk Frenler

Disk frenler iniş takımlarındaki tekerleklerin içindedir ve uçak yere temas ettiğinde tekerlekleri frenlemek için kullanılır. Günlük hayatta kullandığımız araçlardaki disk-balata sistemine benzer. Hidrolik ya da pnömatik olarak çalışır. Hareket halindeki uçağın kinetik enerjisi frenlere aktarıldığı için, iniş sırasında frenlerin sıcaklığı sunuma göre 1400 dereceyi aşabilir. Frenler çoğunlukla çelikten üretilir; son yıllarda özellikle gelişmiş uçaklarda kullanılan karbon frenler hafif oldukları için yakıt tüketimini azaltır.

### 8.3 Spoiler'lar

Yansıya göre uçağın kanatları, uçak piste teker koyduktan sonra bile o hızlarda uçağı havalandırabilecek kaldırma kuvveti üretir. Bu yüzden inişten sonra yapılacak ilk iş, kanatların ürettiği kaldırma kuvvetini ortadan kaldırıp uçağın pistte kalmasını sağlamaktır. Bunu sağlayan elemanlara spoiler denir; basitçe kanat üst yüzeyinde bulunan, yukarı doğru açılan paneller olarak tarif edilebilir (ekrandan, 01:00:00).

İnişin akışı şöyledir: Uçak yaklaşma sırasında hızını düşürür, pilot motorlardaki gazı azaltır ve düşük hızda havada kalabilmek için flap denen yapılar açılır; bunlar kanat alanını artırarak kaldırmayı korur. Uçak yere teker koyduğu anda spoiler'lar açılır, kanat üzerinden geçen hava akışını bozar ve uçağın piste tutunmasını sağlar. Spoiler'lara "speed brake" (hız freni) de denir, çünkü havada yüksek hızlarda uçağın hızını azaltmakta da etkilidirler.

### 8.4 Thrust Reverser

Sunan öğrencinin en çok ilgisini çeken sistem budur. Thrust reverser motorların üzerinde bulunur ve motor itişinin uçağı yavaşlatmak için kullanılmasını sağlar. Neredeyse tüm modern yolcu ve kargo uçaklarında kullanılır. Tekerleklerin ve frenlerin maruz kaldığı yükü azalttığı için hem tekerlek hem fren ömrünü uzatır.

Yansıya göre bu yöntemde motordan geçen hava akışı, yönlendirici panellerin açılmasıyla yaklaşık 45 derecelik bir açıyla ön tarafa yönlendirilir. Motorda hızlandırılan hava arkaya değil öne doğru verildiği için motorlar normalde uçağı iterek hızlandırırken artık yavaşlatır (ekrandan, 01:05:00).

Uygulama biçimi motor tipine göre değişir. Yansıdaki çizimlerde iki tip gösterildi (ekrandan, 01:05:00):

- Küçük jetlerde motorun tam arkasındaki kapaklar (bucket doors) açılır; çizimde bunlar ileri itiş konumu ve ters itiş konumu olarak gösterildi.
- Büyük yolcu ve kargo jetlerinde içerideki bir panel arkaya giden soğuk hava akışını (cold stream) kapatır ve hava motor gövdesindeki bir açıklıktan ters yöne, dışarıya verilir.

### 8.5 Soru-Cevap

Hoca, büyük uçaklarda arkaya ayrı bir panel açılmamasının, hızın ve motor gücünün daha büyük olmasından kaynaklandığını, bu yüzden motorun içindeki hava akışını bozan bir yöntem kullanıldığını yorumladı.

**Soru (hoca):** Yansıdaki fotoğrafta motorun etrafında görülen şey su buharı mı, yağmurlu bir ortamda çekilmiş su zerreleri mi?

**Cevap:** Yağmurlu bir ortamdır; görülenler su zerreleridir. Normalde bu şekilde bir buhar görülmez, daha çok yağmurlu havalarda görülür.

**Soru (hoca):** Bu yöntemin savaş uçaklarında kullanımına dair bir şey biliyor musunuz?

**Cevap:** Sunan öğrenci, bildiği kadarıyla savaş uçaklarında bu yöntemin kullanılmadığını, onun yerine paraşüt sistemi kullanıldığını söyledi; motor jetin gövdesinin içinde olduğu, dışarıda ayrı bir motor bulunmadığı için bu sistemin kullanılmadığını düşünüyordu. Hoca da bunu ayrıca araştıracağını söyledi.

> **Ders sonrası not:** Savaş uçaklarının çoğu fren paraşütü kullansa da, bazı savaş uçaklarında (örneğin Panavia Tornado ve Saab Viggen) büyük olasılıkla thrust reverser bulunmaktadır.

## 9. 2011 NBA Playoff'ları

### 9.1 Sistem

Bir öğrenci 2011 NBA playoff'larını anlattı. Süre kısıtlı olduğu için yalnız ilgi çekici serilerde durdu. Sunumda baştan anlatılmayan ama soru-cevapta açıklanan sistem şöyledir: NBA, Doğu ve Batı konferansı olarak ikiye ayrılır. Her konferanstaki ilk sekiz takım playoff'a girer ve kendi aralarında seriler oynar; seriyi dört maç kazanan tur atlar. Yansılarda takım adının yanındaki parantez içi sayılar takımın konferanstaki sıralamasıdır. Her konferansta sekiz takım dörde, sonra ikiye iner; konferans şampiyonları finalde karşılaşır.

### 9.2 Batı Konferansı

- Spurs - Grizzlies: Serinin asıl önemi, Memphis'in tarihinde ilk kez bir playoff serisi kazanmasıdır. Finale gitmesi neredeyse kesin gözüyle bakılan San Antonio'nun ilk turda elenmesi ligde şok etkisi yarattı. Sunan öğrenci serinin oyuncusu olarak hücumda ve savunmada büyük katkı veren Zach Randolph'u seçti.
- Lakers - Hornets: Son iki sezonun şampiyonu Lakers, Hornets'ı rahat geçemedi; bu, takımdaki sorunların işaretiydi.
- Mavericks - Trail Blazers: Sunan öğrencinin en sevdiği maç bu serideydi. Dördüncü maçta Portland 23 sayı geriye düştü; o yıl iki dizinden ameliyat olmuş Brandon Roy yedek kulübesinden gelip maçı kazandırdı. Ancak sonraki maçlarda eski haline dönünce bir şey değişmedi ve Dallas tur atladı.
- Thunder - Nuggets: Beklenenden yakın geçti, ama süperstarı olmayan Nuggets karşısında Kevin Durant farkını ortaya koydu; seri 4-1 bitti.
- Yarı final, Thunder - Grizzlies: Yansıya göre seri 4-3 Thunder lehine bitti; kıyasıya geçen serinin son maçında ligin sayı kralı Durant 39 sayıyla takımını konferans finaline taşıdı. Serinin oyuncusu Durant'ın ortalamaları yansıda 26,4 sayı, 9,1 ribaund ve %44 şut yüzdesi olarak verildi. Memphis'in savunma basketbolu oynadığı "Grit and Grind" döneminin ilk senesi böylece başarılı bitti (ekrandan, 01:10:00).
- Yarı final, Mavericks - Lakers: Bu sene normalde Lakers ile Heat arasında bir final bekleniyordu, ama Lakers'ın sorunları aşılacak gibi değildi. Dallas, Lakers'ı farklı yendi (sunuma göre son maç 36 sayı farkla); bu seriden sonra Lakers'ın efsane koçu Phil Jackson görevi bıraktı.
- Konferans finali: Nowitzki serinin ilk maçında 24 serbest atışın 24'ünü de sokup 48 sayı attı. Dallas 2006'dan sonra ilk kez NBA finaline çıktı.

### 9.3 Doğu Konferansı

Sunan öğrenciye göre Doğu'daki seriler Batı kadar keyifli geçmedi; takımlar arasındaki kalite farkı büyüktü.

- Bulls - Pacers: Sekizinci sıradaki Pacers'ın, o sezon ligin en değerli oyuncusu (MVP) seçilen Derrick Rose'a cevabı yoktu; seri 4-1 bitti.
- Heat - 76ers: Miami'nin büyük üçlüsünü kurduğu sene; LeBron James ve Dwyane Wade neredeyse bütün sayılarda pay sahibiydi; seri 4-1 bitti.
- Celtics - Knicks: İlk turun en çok beklenen serisiydi, ama Knicks'te sakatlıklar yaşandı ve seri beklenenden keyifsiz geçti.
- Magic - Hawks: Doğu'nun ilk turundaki tek sürpriz; Orlando 4-2 yenilip elendi.
- Yarı finaller: Atlanta, Derrick Rose'a cevap veremedi (4-2 Bulls). Heat - Celtics serisi skordan (4-1) daha yakındı; önceki yıllarda hem Wade'i hem LeBron'u eleyen Celtics'i geçmek, sunan öğrenciye göre bu üçlünün kurulma nedenlerinden biriydi.
- Konferans finali: Derrick Rose beklenenden çok kötü oynadı; LeBron ve Wade onu birlikte çok iyi savundu. Miami de 2006'dan sonra ilk kez finale çıktı; final böylece 2006 finalinin rövanşı oldu.

> **Ders sonrası not:** Sunumda bir Knicks oyuncusunun bu seride yangın tüpü kutusunu yumruklayıp elini kırdığı söylendi. Bu olay büyük olasılıkla 2011'de değil, 2012 playoff'larında Miami'ye karşı yaşanmıştır.

### 9.4 NBA Finali

Herkes Miami'nin şampiyon olacağını düşünüyordu, ama Dallas'ın yan oyuncuları beklenenden iyi oynayınca seri 4-2 Dallas lehine bitti. 2006'da da 4-2 Miami kazanmıştı; Dallas böylece intikamını almış oldu. Yansıya göre Jason Terry ve DeShawn Stevenson gibi yan oyuncuların ekstra katkısına Miami cevap veremedi. Miami seride 2-1 öndeyken dördüncü maçta ligin en iyi oyuncusu gösterilen LeBron James 45 dakika sahada kalıp yalnız 8 sayı atabildi ve maç yalnızca 3 sayı farkla kaybedildi; sunan öğrenciye göre bu, LeBron'un kariyerinin en kötü serisidir. Finaller MVP'si Dirk Nowitzki oldu (26,0 sayı, 9,7 ribaund, 2,0 asist); bu onun ilk ve tek şampiyonluğudur (ekrandan, 01:15:00).

## 10. Sunum Tekniğine Dair Değerlendirmeler

Bu derste hoca, soru-cevap kısımlarını sık sık sunum tekniğine dair genel derslere bağladı.

### 10.1 Konuyu İlgi ve Deneyim Alanından Seçmek

Büyük veri sunumundan sonra hoca, konu seçerken öğrencilere kendi ilgi alanlarından ya da zaten içinde oldukları bir konudan seçim yapmalarını söylemesinin nedenini açıkladı: Bir konuda bilgi birikimi ve deneyimi ortalamanın üstünde olan kişi rahat sunar, rahat konuşur ve gelen sorulara rahat cevap verir. Bu, sunumu çok daha verimli hale getirir.

> **Hocanın vurgusu:** Konu seçiminde kendi ilgi alanınızı ya da deneyiminiz olan bir konuyu seçin; soru-cevapta fark bu şekilde ortaya çıkar.

### 10.2 Her Kavramı Kullanmadan Önce Açıklamak

Kutsal Roma İmparatorluğu sunumunda "diyet" kavramı tanıtılmadan kullanıldığı için hoca takıldı ve bunu sordu. Sunan öğrenci parlamenter yapıdan bahsedeceğini söylemişti, ama "diyet" kelimesi açıklanmadan geçmişti. Hoca, anlatılan her kavramın önce bir yerde açıklanmış olmasının en doğrusu olduğunu söyledi.

> **Hocanın vurgusu:** Bu yalnız sunumda değil, akademik yazı ya da teknik rapor hazırlarken de dikkat edilmesi gereken bir husustur; kullanılan her kavramın önceden tanımlanıp tanımlanmadığı çapraz kontrol edilmelidir.

### 10.3 Dinleyici Analizi ve Terimler

NBA sunumunda sunan öğrenci sözlü anlatımda "bench oyuncusu" dedi; hoca bunun ne demek olduğunu sordu (yedek oyuncu). Hoca, konunun genel popülerliği varsa terimlerin bilinebileceğini, ama bilinmeyen terimler de olabileceğini söyledi. Daha önceki derslerde de vurgulandığı gibi, sunuma katılacak olanların kim olduğu, arka planları ve bilgi düzeyleri önceden düşünülmeli, sunum buna göre ince ayar yapılmalıdır: hangi terimin nereye kadar açıklanacağı bu analizden çıkar. Hoca, yansıda görmediği için bu terimin açıklanması gerektiğini iddia etmediğini, ama sözlü kullanılınca merak ettiğini belirtti. Yansılardaki parantez içi sayıların anlamının da başta açıklanmamış olması aynı türden bir eksiklikti.

### 10.4 Yansı Tasarımında Tutarlılık

Hoca dinleyicilere, NBA sunumunda bazı yansıların fonunun mavi, bazılarının kırmızı olmasının nedenini sordu. Cevap: Doğu konferansı yansıları mavi, Batı konferansı yansıları kırmızıydı; NBA de genelde bu renkleri kullanır. Hoca, bir sunumun genel yapısında tutarlılığın önemli olduğunu, ilk bakışta renk değişimini bir tutarsızlık gibi algıladığını, sonra bunun Doğu-Batı ayrımını gösteren bilinçli bir kodlama olduğunu fark ettiğini söyledi. NBA'in renkleri de kırmızı, beyaz ve mavidir. Böylece konsept uygun ve anlamlı bulundu.

> **Hocanın vurgusu:** Sunumun görsel yapısında tutarlılık önemlidir; değişiklik yapılacaksa bir anlam taşımalıdır.

### 10.5 Sürenin Kullanımı

Hoca, birkaç sunumun ardından sunan öğrencinin süreyi iyi kullandığını özellikle belirtti.

## Örnek Sorular

Bu derste ekranda soru ya da alıştırma gösterilmedi. Aşağıdaki sorular derste sözlü olarak soruldu; cevaplar derste verilen cevaplardır.

1. (derste sözlü, 00:06:23) Altın oranın salyangoz kabuğundan galaksilere kadar farklı ölçeklerde görülmesini nasıl yorumlarsınız?

   **Derste verilen cevap:** Tesadüf denemeyecek kadar yaygın bir tekrardır, ama bilimsel bir açıklaması da kesin değildir. Hocanın önerdiği yorum: Evren genel kurallar üzerine kuruludur; altın oranın tekrarı bu kuralların genelliğinin bir örneğidir.

2. (derste sözlü, 00:23:48) Makine öğrenmesi ve derin öğrenmede hangi programlama dilleri ve kütüphaneler kullanılır?

   **Derste verilen cevap:** Derin öğrenmede Python (TensorFlow, PyTorch), C++ (Torch) ve Julia (Knet); geleneksel makine öğrenmesinde ayrıca R. Julia matris işlemlerinde hızlıdır ama topluluğu dardır.

3. (derste sözlü, 00:27:02) Python ile geliştirilen bir öğrenme modelinin sonuçları başka platformlarla nasıl tümleştirilebilir?

   **Derste verilen cevap:** Pygame ile oyun ortamında, Flask ile web arayüzünde, grafik arayüz kütüphaneleriyle masaüstünde gösterilebilir; Node.js ve NoSQL ile kurulmuş sistemlerden veri çekilip modelde kullanılabilir.

4. (derste sözlü, 00:42:36) Bazı oyun firmaları neden DRM kullanmaya karşı çıkıyor?

   **Derste verilen cevap:** Kaliteli oyunların DRM olmadan da satılacağını düşünüyorlar. Ayrıca DRM maliyeti artırır, performansı düşürür ve oyunlar zaten kısa sürede kırılmaktadır.

5. (derste sözlü, 00:53:22) Kutsal Roma İmparatorluğu'ndaki "diyet" nedir?

   **Derste verilen cevap:** İmparatorluğu oluşturan prenslik ve şehirlerin toplandığı, yasa yapma ya da karar verme yetkisi olmayan bir müzakere meclisidir. Elektörler Meclisi imparatoru seçer; Prensler Meclisi ve İmparatorluk Şehirleri Meclisi ile birlikte üç organdan oluşur; son kararı imparator verir.

6. (derste sözlü, 01:03:23) Thrust reverser savaş uçaklarında kullanılıyor mu?

   **Derste verilen cevap:** Sunan öğrenciye göre savaş uçaklarında genelde fren paraşütü kullanılır.

   > **Çözüm (derste verilmedi):** Savaş uçaklarının çoğunda fren paraşütü kullanılır, ancak büyük olasılıkla bazı modellerde (Panavia Tornado, Saab Viggen) thrust reverser de bulunmaktadır.

7. (derste sözlü, 01:16:22) Bir sunumda bazı yansıların fonu mavi, bazılarınınki kırmızıysa bu neden olabilir; tasarım açısından nasıl değerlendirilir?

   **Derste verilen cevap:** NBA sunumunda mavi Doğu, kırmızı Batı konferansını gösteriyordu. Renk değişimi ilk bakışta tutarsızlık gibi görünse de anlam taşıyan bilinçli bir kodlama olduğu için uygundur; sunumun görsel yapısında tutarlılık esastır.

## Dersin Toparlaması

Bu derste sekiz öğrenci sunumu dinlendi. Altın oran sunumunda $\frac{a}{b} = \frac{a+b}{a}$ tanımından $\varphi = \frac{1+\sqrt{5}}{2}$ değeri türetildi ve Fibonacci dizisindeki ardışık oranların bu değere yakınsadığı gösterildi. Efes ve Kutsal Roma İmparatorluğu sunumları tarihi yapıları; büyük veri, bulut oyun ve DRM sunumları bilişim teknolojisinin güncel konularını; uçak fren sistemleri ise üç farklı fiziksel ilkeye dayanan mühendislik çözümlerini ele aldı. NBA sunumu spor tarihinden bir örnek sundu.

Soru-cevap kısımlarında hoca sunum tekniğine dair önemli ilkeleri somut örneklerle pekiştirdi: konuyu deneyim alanından seçmek soru-cevapta rahatlık sağlar; her kavram kullanılmadan önce tanımlanmalı ve bu akademik yazıda da çapraz kontrol edilmelidir; hangi terimlerin açıklanacağı dinleyici analizine göre belirlenir; yansı tasarımındaki değişiklikler anlam taşımalı, genel yapı tutarlı olmalıdır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
