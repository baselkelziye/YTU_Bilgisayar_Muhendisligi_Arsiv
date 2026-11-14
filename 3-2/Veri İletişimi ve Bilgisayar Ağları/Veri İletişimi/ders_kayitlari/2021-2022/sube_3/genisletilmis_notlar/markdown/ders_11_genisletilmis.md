# Ders 11 Genişletilmiş Notu: Kablosuz İletim Ortamı, Çoğullama ve Hata Algılama ile Düzeltme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Planı
- 2. Yönlendirilmemiş (Kablosuz) İletim Ortamı
- 3. Elektromanyetik Tayftaki Frekans Bantları
- 4. Çoğullama (Multiplexing)
- 5. Frekans Bölmeli Çoğullama (FDM) ve OFDM
- 6. Zaman Bölmeli Çoğullama (TDM)
- 7. Dalga Boyu Bölmeli Çoğullama (WDM)
- 8. Hataların Nedenleri ve Türleri
- 9. Hata Algılamanın Genel Fikri
- 10. VRC ve LRC
- 11. Döngüsel Artıklık Denetimi (CRC)
- 12. Sağlama Toplamı (Checksum)
- 13. Hata Düzeltme mi, Yeniden Gönderim mi?
- 14. Hata Düzeltme ve Hamming Kodu

## 1. Dersin Planı

Hoca derse, geçen hafta başlanan iletim ortamı konusunun kalan kısmıyla devam edeceklerini söyleyerek başladı. Yönlendirilmiş (guided) ortamlar bitmişti. Bu hafta yönlendirilmemiş (unguided) ortamlar, yani radyo dalgaları, mikrodalga ve kızılötesi konuşulacaktı.

İkinci konu çoğullamaydı (multiplexing) ve bunun tersi olan çoğullamayı çözme (demultiplexing). Hoca fikri şöyle özetledi: Farklı uç noktalardan gelen bilgiyi bir yerde toplayıp daha yüksek kapasiteli bir hat üzerinden aktarmaya çalışıyoruz. Elimizde düşük kapasiteli hatları kullanan istemciler var ve bunların trafiğini tek bir yüksek kapasiteli hatta taşımanın yolunu arıyoruz. İletim ortamının özelliğine göre bu iş frekansa göre, zamana göre ya da dalga boyuna göre yapılabilir.

Üçüncü konu, veri bağlantı katmanının (data link) yerine getirmesi gereken görevlerden biri olan hata denetimiydi: Hata nasıl anlaşılır, düzeltmek için ne yapılabilir?

## 2. Yönlendirilmemiş (Kablosuz) İletim Ortamı

### 2.1 Atmosfer ve Yer Dalgaları

Yönlendirilmemiş ortam derken, elektromanyetik tayf ile tanımlanan ve iletim için atmosferi kullanan teknolojilerden söz ediyoruz. Atmosfer farklı katmanlardan oluşur. Hocaya göre iletim açısından çoğu zaman bizi ilgilendiren katman iyonosferdir; iyonosferdeki değişimler iletim hatlarına çoğu zaman sorun olarak yansır. Ama her zaman iyonosfere kadar çıkan sistemlerden söz etmiyoruz. Daha çok troposfer ya da stratosfer düzeyinde kalınır. Günlük hayatta kullandığımız sistemler ise doğrudan yer dalgası (ground wave) denen, yeryüzüne yakın yayılan radyo dalgalarını kullanır.

Elektromanyetik tayfta frekans aralıklarına farklı adlar verilir. Bir banda radyo frekansı, bir başkasına mikrodalga (microwave), bir başkasına kızılötesi (infrared) denir. Bu tayfta tanıdık adlar da vardır: AM radyo, televizyon ve FM. Yaklaşık 1 GHz'e kadar olan kısım doğrudan radyo dalgası olarak adlandırılır.

### 2.2 Neden Kablosuz?

Hoca kablosuz teknolojilere neden yöneldiğimizi iki nedenle açıkladı:

- **Hareketlilik (mobility):** Yönlendirilmiş ortama bağlıysanız hareket alanınız kablonuzun uzunluğu kadardır. Kablosuz ortam bu noktada rahatlık sağlar.
- **Kurulum maliyeti:** Kablolama çalışması ve maliyeti olmadığı için çok daha verimlidir. Özellikle kenarda, uçta kalan bölgelere servis vermek ve haberleşme sağlamak için çokça tercih edilir.

### 2.3 Radyo Dalgaları

Radyo dalgalarının en önemli özelliği her yöne yayılmasıdır (omnidirectional). Radyo dalgalarını çizimlerde hep bir daireyle, kaynağın her yanına eşit yayılıyormuş gibi gösteririz. Hoca bunun gerçekte her zaman böyle olmadığını söyledi: Antenin bir yüzü daha geniş, bir yüzü daha dar bir çember oluşturur, yani yayılım daha çok ovaldir. Fakat genel kabul, bunu bir daire olarak değerlendirmektir.

Düşük ve orta frekanslı radyo dalgaları engellerden sekmek yerine engellerin içinden geçebilir. Bu sayede örneğin AM bandında yayın yapan bir radyoyu dünyanın neredeyse öbür ucundan dinleyebilirsiniz. Kapsama alanı açısından bu güzel bir özelliktir.

Kötü tarafı ise şudur: Engellerin içinden geçtiğiniz için fiziksel mekân size bir yalıtım (izolasyon) sağlamaz. Hoca evdeki modemleri örnek verdi. Modemlerin Wi-Fi arayüzleri artık 2,4 GHz'te, yani biraz daha yukarıda çalışıyor. Buna rağmen Wi-Fi arayüzünü açtığınızda komşunun, iş yerinin, kim varsa herkesin ağını görürsünüz.

Hocanın önerdiği çözüm iki türlüdür: Yayın gücünü biraz azaltmak ya da cihazınız destekliyorsa 5 GHz'e geçmek. Frekansı artırdığınızda kapsama alanınız daralır ve sinyal daha yönlü hale gelir. Daha yüksek frekansta sinyal engelin içinden geçen değil, engelden seken bir davranış göstermeye başlar.

### 2.4 Frekans Düzenlemeleri ve ISM Bandı

Cihazınızın 5 GHz'i desteklemesi tek başına yetmez. Elektromanyetik tayfın herhangi bir noktasında yayın yapacaksanız uymanız gereken kurallar ve standartlar vardır. Bunlar genellikle ulusal düzeyde belirlenir. Her ülke farklı frekans aralıklarını farklı kullanım alanlarına atar:

- Belli bir aralık tamamen askeri kullanıma ayrılır.
- Belli bir aralık FM bandına ayrılır.
- Belli bir aralık, evlerimizde rahatça kullanabildiğimiz, lisans gerektirmeyen ISM (Industrial, Scientific and Medical) bandına ayrılır.

Hoca bu atamaların ülkeden ülkeye farklılık gösterebileceğini söyledi.

> **Ders sonrası not:** Hoca "bizde ISM bandı 2,4 GHz, Amerika'da 5 GHz seviyesi" dedi. Bu ayrım büyük olasılıkla doğru değil. 2,4 GHz ISM bandı dünyanın hemen her yerinde lisanssız kullanılır. 5 GHz Wi-Fi kanalları ise ABD'de büyük ölçüde U-NII bantlarında yer alır ve Türkiye'de de belirli güç ve kanal kısıtlarıyla kullanılabilir.

Hocaya göre evinizde 2,4 yerine 5 GHz kullandığınızda kimse kapınıza gelmez. Asıl sorun, aynı bant üzerinde haberleşen başkalarıyla çakışmaya başladığınızda ortaya çıkar.

### 2.5 Kanal Çakışması: İki Örnek

**Bölümdeki Wi-Fi kurulumu:** Hoca bölümün B blokunda Wi-Fi cihazları ilk yerleştirildiğinde yaşananları anlattı. Her kata ikişer cihaz konmuş, altı kat alt alta, üst üste doldurulmuş. Sonra hiçbir şey düzgün çalışmamış. Çünkü aynı alanda yayın yapan birden fazla istasyon vardı ve hepsi aynı kanalı kullanıyordu; birbirleriyle çakışıyorlardı. Olması gereken, istasyonların kanalları belli bir sisteme göre bölüşmesiydi. Bu ayarlanınca sistem çalışmaya başlamış.

**Bluetooth ve Wi-Fi:** Bluetooth da 802.11 ile aynı frekansta, 2,4 GHz'te çalışır. Hoca ilk Bluetooth sürümlerinde frekans atlamanın (frequency hopping) düzgün yapılamadığını söyledi. Bu yüzden aynı cihazdaki Wi-Fi modülü ile Bluetooth çakışıyor, ikisi de düzgün performans vermiyordu. Sonraki sürümlerde Bluetooth bulunduğu kanalı dinlemeye başladı. Kanalda başka bir yayın varsa hemen başka kanala geçer. Ana (master) ve bağımlı (slave) tarafta önceden belirlenmiş bir kanal atlama listesi vardır. Bir kanal doluysa listedeki bir sonrakine, o da doluysa ondan sonrakine geçilir. İki taraf bu sayede birbirini bulabilir ve izleyebilir. Yani Bluetooth uyarlamalı (adaptive) bir atlama yapar.

### 2.6 Mikrodalga

Hoca kabaca radyo frekansının sınırını 1 GHz, mikrodalgayı da 1 ile 300 GHz arası olarak verdi. Bunların kesin sınırlar olmadığını, "illa buradan ayrılır" denemeyeceğini de ekledi. Mikrodalga genellikle yer ile uzay arasındaki haberleşmede kullanılır.

Mikrodalganın özellikleri ve zayıf noktaları:

- **Atmosfer etkisi:** Atmosfer katmanlarındaki değişimlerden ciddi biçimde etkilenebilir. Saatler mertebesinde çalışamama, devre dışı kalma durumları olabilir.
- **Yüksek bant genişliği:** Teknik olarak yüksek bant genişliği (bandwidth) sağlar.
- **Tek yönlü (unidirectional) antenler:** Genellikle tek yönlü antenler kullanılır. Hoca mikrodalgada çift yönlü özel bir anten hatırlamadığını, iki yönlü iletişim için iki ayrı antenle çalışıldığını söyledi.
- **Görüş hattı (line of sight):** Haberleşeceğiniz karşı tarafı bir şekilde "görebiliyor" olmanız, yani arada engel olmaması gerekir. Bu yüzden çevresel kısıtlardan etkilenir. Yüksek frekansta olduğu için bir yeri delip geçmesi de pek mümkün değildir.
- **Canlı sağlığı:** Haberleşme mesafesini artırmak için gücü artırdığınızda mikrodalga haberleşmesi canlı sağlığı açısından sorunlu hale gelir.

### 2.7 Kızılötesi

Hocaya göre kızılötesini kullanmayan yoktur: müzik setinden televizyona, kombiden klimaya birçok cihazın kumandası kızılötesi kullanır.

Kızılötesinin temel sorunu, düzgün bir ortak protokolünün olmamasıdır. Herkes kendi protokolünü kullanır. Hoca klima, televizyon ve müzik seti kumandalarını "tam bir ucube teknoloji" diye niteledi; hepsi birbirinden bağımsızdır. Bunları birleştirme projeleri var, ama her üretici kendine göre bir şey üretip devam ettiği için bir araya gelmiyor.

Güzel tarafı, genellikle noktadan noktaya (point to point) olmasıdır. Bu yüzden araya girmek, dinlemek çok kolay değildir.

Sorunlarından biri dış ortam etkilerine çok açık olmasıdır. Güneşli bir alanda kızılötesi ile bir şeyi kontrol etmek neredeyse imkânsızdır. Çünkü güneş ışınlarında da kızılötesi vardır. Ortada sizin sinyalinizi bastırabilecek çok daha güçlü başka bir sinyal olur ve karşı taraf yalnız gürültü duyar.

## 3. Elektromanyetik Tayftaki Frekans Bantları

Hoca frekans aralıklarının adlarını, etki alanlarını ve kullanım yerlerini gösteren bir tabloyu (slayttan) gezdi. Adlar en altta extremely low, super low, ultra low ve very low frequency ile başlıyor. Ardından low frequency (LF) 300 kHz'e kadar, medium frequency (MF) 3 MHz'e kadar, high frequency (HF) 30 MHz'e kadar gidiyor.

<!-- BELİRSİZ: Slayttaki frekans tablosunun tüm satırları (kullanım alanları ve diğer bantların sınırları) altyazıda okunmuyor; yalnız LF, MF, HF sınırları sözlü veriliyor. -->

Hoca bu adlandırmanın tarihsel bir sorunu olduğunu anlattı. Teknoloji ilk ortaya çıktığında mimarlarının vizyonu sınırlıymış ve 30 MHz'e "yüksek frekans" demişler. Daha sonra üst bantlar geldikçe adlar saçma bir hal almış. Hoca bunu otel reklamlarındaki "all inclusive" gibi abartılı adlara benzetti: very high, sonra ultra high, sonra super high, extremely high, tremendously high diye gidiyor.

En düşük frekanslar iletimin en zor olduğu yerde, su altında kullanılır. Frekans arttıkça atmosferin üst katmanlarına doğru çıkılır, en sonunda da uzaya kadar gidilir.

> **Ek bilgi (derste anlatılmadı):** ITU'nun bant adlandırmasında her bant bir öncekinin on katıdır: VLF 3–30 kHz, LF 30–300 kHz, MF 300 kHz–3 MHz, HF 3–30 MHz, VHF 30–300 MHz, UHF 300 MHz–3 GHz, SHF 3–30 GHz, EHF 30–300 GHz. Hocanın şaka olarak söylediği "tremendously high frequency" (THF, 300 GHz–3 THz) da gerçekten kullanılan bir addır. FM radyo VHF'de, 2,4 GHz Wi-Fi UHF'de, 5 GHz Wi-Fi SHF'de yer alır.

## 4. Çoğullama (Multiplexing)

### 4.1 Kablo Modem Örneği

Hoca çoğullamayı evdeki internet bağlantısı üzerinden anlattı. Kablo modeminiz ya da ADSL'iniz olsun. Bir grup aboneyi bir merkeze bağlarız. Kablo modemde apartmanda bir kablo modem kutusu vardır. Bu kutuyu Ethernet'teki anahtar (switch) gibi düşünebilirsiniz: Herkese ayrı bir bağlantı yapar. Anahtardan farkı, bu bağlantıların uçlarındaki kullanıcıların kendi aralarında doğrudan konuşmasına izin verilmemesidir.

Kutunun orada durmasının asıl nedeni, abonelerin bağlantısını bir üst noktaya taşımaktır. Sizin apartmanınız, yan apartman, öbür apartman derken tüm hatlar bir noktada toplanır, sonra o da bir üste çıkarılır, ta omurgaya (backbone) kadar. Her bağlantı için en baştan omurgaya kadar ayrı hat çekmek maliyetli ve zahmetlidir. Bunun yerine yüksek kapasiteli, mümkünse tek bir hat kullanılır ve düşük kapasiteli hatların ürettiği trafik onun üzerinden taşınır. Bunun için çoğullamadan yararlanırız.

### 4.2 Çoğullama İki Taraflıdır

Çoğullama tek taraflı değildir. Bir uçta çoğullama yapıyorsanız öbür uçta çoğullamanın çözülmesi (demultiplexing) gerekir. Hocanın çizimindeki yapı şöyleydi: Apartmanda herkesin ayrı hattı vardır ve çoğullayıcı (multiplexer) buraya konur. Gelen hatlar tek hatta toplanır ama doğrudan hedefe değil, bir üst bağlantı noktasına aktarılır. O noktaya başka bağlantılar da gelir; onlar da birleştirilip bir üste aktarılır. Trafik geri dönerken de her seferinde üst hattan alt hatta geçilir, her seviyede çoğullama çözülür ve trafik sonunda hedeflenen noktaya ulaşır.

Hoca bunun bir İSS (ISP) mantığı olduğunu, ama aynı yapının farklı yerlerde ofisleri olan bir şirketin iç ağ trafiğini dışarı çıkarırken de kullanılabileceğini söyledi. Elinizde yüksek kapasiteli bir hat varsa o kapasitenin kullanılması gerekir ve çoğullama bunu sağlayan yöntemlerden biridir.

### 4.3 Telefon Sistemi ve T1 Hattı

Hocanın verdiği en güzel örnek eski telefon tabanlı sistemlerdi. Abone bağlantılarının kapasitesi 9600 bps ile 64 kbps arasında değişir. Santrale bağlı cihazların trafiğini bir üste aktarmak için T1 bağlantıları kullanılır. Hoca T1'in kapasitesini "1,5 Mb" olarak verdi.

> **Ders sonrası not:** T1 hattının tam kapasitesi 1,544 Mbps'tir; hocanın "1,5 Mb" demesi bunun yuvarlanmış halidir.

Çevirmeli (dial-up) ağlar döneminde internet için başvuran birine "santralde yeriniz yok" denirdi. Hocaya göre bunun anlamı şuydu: Alt tarafta belli sayıda abone vardır ve üst taraftaki T1 hattının ya da hatlarının kapasitesi, verilen toplam kapasitenin sınırındadır. Yeni bir abonelik verilirse üst hattan taşınabilecek olandan fazlası çıkacaktır. Bu yüzden abonelik verilmezdi.

### 4.4 Üç Çoğullama Yöntemi

Hoca toplam üç yöntem olduğunu söyledi. İkisi en temel yöntemlerdir; üçüncüsü daha sonra ortaya çıkmıştır ama hayatımızda çok önemli bir yer tutar.

- **Frekans bölmeli çoğullama (FDM, Frequency Division Multiplexing):** Kullanılabilen bant aralığı bölünür, farklı frekans aralıkları farklı kullanıcılara atanır.
- **Zaman bölmeli çoğullama (TDM, Time Division Multiplexing):** Kanalın kullanımı zamana göre verilir. Bir aralık belirlenir: bir milisaniye, on milisaniye ya da beş saniye. "Beş saniye boyunca hat senin" denir, süre bitince sıra öbür kullanıcıya geçer.
- **Dalga boyu bölmeli çoğullama (WDM, Wavelength Division Multiplexing):** Frekans ya da zaman yerine hattın başka bir özelliği kullanılır. Optik iletimde ışık kullanırız ve ışığın bir spektrumu vardır. Farklı dalga boyları farklı kullanıcılara tahsis edilebilir.

Hocanın vurguladığı ortak nokta: Her yöntemde hattın farklı bir özelliği, hat kapasitesinin parçalanması ve dağıtılması için kullanılır.

## 5. Frekans Bölmeli Çoğullama (FDM) ve OFDM

### 5.1 FDM'nin Çalışması

FDM'de kaç gönderici varsa her biri için farklı bir taşıyıcı işaret (carrier) kullanılır. Her göndericinin sinyali kendi taşıyıcısıyla modüle edilir.

FDM'nin en güzel örneği radyodur. Dinlemek istediğiniz istasyonun frekansını ayarlarsınız. Düğmeyi biraz sağa ya da sola çevirdiğinizde önce bir cızırtı gelir, sonra bir sonraki istasyona geçersiniz. Aradaki cızırtı, iki atanmış (allocated) frekans arasındaki koruma bandıdır (guard band). Frekans biraz kayarsa doğrudan öbür istasyona geçilmesin diye bu boşluk bırakılır. Yani frekansla oynadığınız için frekans aralıklarının arasına, karışıklık olmasın diye koruyucu bir alan koymanız gerekir. Televizyon yayınları da FDM'nin bir örneğidir.

### 5.2 OFDM

En temel FDM'de frekans bantları birbirinden tamamen yalıtılır ve aralarına bir bariyer konur. Fakat hattın kullanımını artıran, bölebileceğiniz parça sayısını çoğaltan teknikler de vardır. Bunlardan biri dik frekans bölmeli çoğullamadır (OFDM, Orthogonal Frequency Division Multiplexing). Hoca bunu şöyle anlattı: Sinyallerin tepe noktaları çakışmayacak şekilde bantlar birbirinin üzerine bindirilir. Böylece kanal sayısı artar.

Bunun bedeli, gerçeklemenin zorlaşmasıdır. Hocaya göre OFDM her an her yerde kullanılabilecek bir teknik değildir; biraz daha fazla emek ve para gerektirir. Ama bu tekniğin varlığını bilmek gerekir.

> **Ek bilgi (derste anlatılmadı):** OFDM'de alt taşıyıcıların frekansları, sembol süresinin tersinin tam katları olacak şekilde seçilir. Bu durumda bir alt taşıyıcının spektrumu tepe yaptığı frekansta diğer tüm alt taşıyıcıların spektrumu sıfırdan geçer. Spektrumlar üst üste binse de alıcı her alt taşıyıcıyı ayrı ayrı çözebilir. Wi-Fi (802.11a/g/n/ac) ve 4G LTE OFDM tabanlıdır.

## 6. Zaman Bölmeli Çoğullama (TDM)

### 6.1 Temel Fikir ve Bekleme Sorunu

TDM'de herkese belli bir zaman ayrılır ve kullanıcının bilgisini o süre içinde göndermesi beklenir. Kanalı kaç parçaya böldüyseniz ve her parçaya ne kadar süre verdiyseniz, özel bir düzen kullanmadıysanız büyük olasılıkla döngüsel (round robin) bir çoğullama yaparsınız. Elinizde $n$ kullanıcı varsa sıra 1, 2, 3, 4, 5, 6 diye gider. Birinci kullanıcının hattı tekrar kullanması $n$. kullanıcıdan sonra mümkün olur. Dolayısıyla herkes uzun süre beklemek zorundadır.

Hoca özellikle kötü bir durumu vurguladı: Hattı kullanma sırası geldiğinde kullanıcının elinde bilgi yoksa, ama sıra kendisinden geçer geçmez gönderecek bir şeyi oluşursa, çok uzun bir süre beklemesi gerekir.

TDM eş zamanlı (senkron) ya da eş zamansız (asenkron) gerçeklenebilir.

### 6.2 Senkron TDM

Senkron TDM az önce tarif edilen yapıdır. $n$ kullanıcı için $n$ slot oluşturulur. Herkesin slotu bellidir; gönderse de göndermese de o slot ona aittir. Yani statik bir yapıdır. Sorun şudur: Gönderecek bir şeyi olmayan kullanıcıyı da bekleriz, bu yüzden yapı verimli değildir. Ayrıca çoğullama yaparken gönderilecek bilgileri bir çerçeveye (frame) oturtmak gerekir.

**Örnek (slayttan):** A, B, C, D adlı dört kullanıcı var.

- Birinci çerçeve: A1, B1, C1, D1. Dört kullanıcının da verisi var.
- İkinci çerçeve: A2, B2, C2 dolu, D'nin slotu boş.
- Üçüncü çerçeve: Yalnız A3 ve C3 dolu.
- Dördüncü çerçeve: Yalnız A4 dolu (ara adım eklendi; hocanın verdiği "16 slot, 10 dolu" sayısından ve istatistiksel TDM örneğindeki A4'ten çıkıyor).

Dört çerçevede $4 \times 4 = 16$ slot kullanılır. Dolu slot sayısı $4 + 3 + 2 + 1 = 10$'dur. Hat kullanım oranı:

$$U = \frac{10}{16} = 0{,}625$$

> **Ders sonrası not:** Hoca bu oranı "10 bölü 16, yani neredeyse %50, hadi %60 diyelim" diye söyledi. Doğru değer $10/16 = \%62{,}5$'tir.

### 6.3 İstatistiksel (Asenkron) TDM

Senkron TDM'yi daha verimli hale getirmek için eş zamansız TDM kullanılır. Buna istatistiksel zaman bölmeli çoğullama (Statistical TDM, STDM) da denir. Temel kabul, bir çerçevedeki zaman aralığı (slot) sayısının giriş sayısından az olmasıdır. Önceden herkese slot ayırmak yerine çerçeveler doldurulur. Bilgi, round robin sırasına göre değil, nasıl doldurulabiliyorsa öyle yerleştirilir.

Aynı veri istatistiksel TDM ile dört değil üç çerçevede taşınır. Hoca slayttaki çerçeve indekslerinin kaydığını fark edip derste düzeltti. Doğru dizilim şöyledir:

- Birinci çerçeve: A1, B1, C1, D1.
- İkinci çerçeve: A2, B2, C2, A3.
- Üçüncü çerçeve: C3, A4.

Buradaki sorun şudur: Senkron yapıdan farklı olarak bir slottaki bilginin kimden geldiği belli değildir. Bu yüzden her slota ek olarak adres bilgisi konması gerekir. Adres bilgisinin boyutu bir ek yük (overhead) getirir. Ama aktarılan toplam veri miktarıyla karşılaştırıldığında, özellikle adres bilgisi çok büyük değilse, yapı çok daha verimli olur.

## 7. Dalga Boyu Bölmeli Çoğullama (WDM)

Üçüncü yöntem dalga boyu bölmeli çoğullamadır. Hocaya göre kullanım yeri belli açılardan sınırlıdır: Fiber optik kablo üzerinden ışıkla haberleşirken kullanılır. Yöntem, ışığın farklı dalga boylarına (renklere) ayrılabilmesi üzerine kuruludur.

## 8. Hataların Nedenleri ve Türleri

### 8.1 Hata Nedenleri

Hoca hatta neden hata oluştuğunu sinyalin kendisinden kaynaklananlar ve dış etkenler diye iki grupta anlattı.

**Zayıflama (attenuation):** Elektromanyetik bir işareti uzak mesafeye aktarıyorsanız, dış ortam etkilerinden bağımsız olarak, yalnız iletken üzerinde ilerlediği ve iletken mesafeyle direnç gösterdiği için sinyal seviyesi düşer. Hoca RS-232'yi hatırlattı: Geçerli seviyeler $-5$ ile $-15$ V arası ve $+5$ ile $+15$ V arasıdır. Sinyal başlangıçta "jilet gibi" 15 V iken yolda 4,8 V'a düşerse artık geçerli aralığın dışına çıkar ve yanlış yorumlanır; hata oluşur.

> **Ders sonrası not:** Hoca 4,8 V'a düşen sinyalin "sıfır olarak değerlendirileceğini" söyledi. RS-232'de $\pm 5$–$\pm 15$ V vericinin çıkış aralığıdır; alıcı büyük olasılıkla $\pm 3$ V'un üzerindeki seviyeleri hâlâ geçerli kabul eder. Ayrıca RS-232'de pozitif gerilim mantıksal 0'ı temsil eder. Hocanın asıl vurgusu, zayıflayan sinyalin bir noktada eşiğin altına düşüp yanlış bit olarak okunabilmesidir.

**Gecikme bozulması:** Gönderdiğimiz sinyali Fourier serisine açtığımızda bir bileşenler grubu görürüz. Hocaya göre bazı bileşenler, örneğin 3., 5. ve 7. harmonikler, genellikle sorun çıkarır: Hatta gecikmeye neden olurlar ve bu gecikme bilginin bozulmasına yol açabilir.

> **Ders sonrası not:** Burada kastedilen büyük olasılıkla gecikme bozulmasıdır (delay distortion). Sorun belirli harmoniklerin kendisi değil, sinyalin farklı frekans bileşenlerinin ortamda farklı hızlarda ilerlemesidir. Bileşenler alıcıya farklı zamanlarda ulaşınca sinyalin biçimi bozulur.

Dış etkenler:

- **Termal gürültü:** Kabloyu ısıttığınızda ya da soğuttuğunuzda bile kablo üzerinde gürültü oluşur. Özellikle çok uzun kablolarda etkili olabilir.
- **Modülasyon gürültüsü:** Modülasyon aşamasında gürültü oluşabilir.
- **Çapraz karışma (crosstalk):** Ethernet konuşulurken çiftler arasında yakın uç ve uzak uç çapraz karışmadan söz edilmişti.
- **Dış elektromanyetik gürültü:** Örneğin büyük motorların çalıştığı endüstriyel bir ortamda mutlaka elektromanyetik gürültü olur ve hattınızı etkiler.

### 8.2 Hata Türleri

Hoca hataları üç türe ayırdı ve gerçekte en sık görülenin bunların en kötüsü olduğunu söyledi. Slayttaki örnek veri `1000111`'di.

- **Tek bitlik hata:** Verinin yalnız bir biti değişir. Hocaya göre haberleşme deyince akla kablo ya da kablosuz iletim gelse de tek bitlik hatalar daha çok bellekte görülür. Örneğin komşu bitin yazılması sırasında bozulan, ya da tümleşik devredeki bir kusur yüzünden 0 yazsanız da 1 yazsanız da 1 olarak kalan bellek hücreleri olabilir.
- **Çok bitli hata:** Bir veri bütünü içinde birbirinden bağımsız iki ya da daha fazla bit değişir. Bunların genellikle ayrı noktalarda olması beklenir.
- **Hata patlaması (burst error):** Art arda gelen bitler birlikte değişir. Gerçek hatalar genellikle bu şekilde gelir ve verinin birçok yerini aynı anda bozar.

> **Hocanın vurgusu:** Gerçek hayatta hatalar çoğu zaman tek tek değil, patlama (burst) şeklinde gelir.

## 9. Hata Algılamanın Genel Fikri

Gönderilen veriyi ve alınan veriyi birlikte bilseydik, karşılaştırarak hata olup olmadığını söyleyebilirdik. Ama alıcının buna imkânı yoktur.

Akla gelen bir alternatif, bilginin bir kez daha gönderilip iki kopyanın karşılaştırılmasıdır. Hoca bunun iki sorununu söyledi: Veri her seferinde aynı şekilde bozuluyor olabilir. Ayrıca aynı bilgiyi iki kez aktardığınız için iki kat zaman harcarsınız, yani verimli değildir.

Günümüzde kullanılan verimli yöntem şudur:

1. Gönderici veriden bir kontrol bilgisi üretir ve veriyle birlikte gönderir.
2. Alıcı veriyi ve kontrol bilgisini alır, aynı yöntemle veriden kontrol bilgisini kendisi üretir.
3. Ürettiği kontrol bilgisini gelen kontrol bilgisiyle karşılaştırır.
4. İkisi tutuyorsa verinin bozulmadığına karar verir ve veriyi kabul eder.

Hoca bu yaklaşımla çalışan dört tekniği sıraladı: dikey artıklık denetimi (VRC, Vertical Redundancy Check), boylamsal artıklık denetimi (LRC, Longitudinal Redundancy Check), döngüsel artıklık denetimi (CRC, Cyclic Redundancy Check) ve sağlama toplamı (checksum). Bunların hepsi hata algılamaya (error detection) yöneliktir: Hata var mı yok mu, onu tespit ederler. Hatayı doğrudan düzeltmek istediğimizde ise hata düzeltme (error correction) yöntemleri kullanılır; onlar bu dört tekniğin ardından anlatıldı.

## 10. VRC ve LRC

### 10.1 VRC (Eşlik Biti)

**Örnek (slayttan):** Gönderilen veri `0100110`.

Bitler sırayla XOR'lanır: $0 \oplus 1 = 1$, $1 \oplus 0 = 1$, $1 \oplus 0 = 1$, $1 \oplus 1 = 0$, $0 \oplus 1 = 1$, $1 \oplus 0 = 1$ (ara adımlar eklendi). Sonuç 1'dir; verideki 1'lerin sayısı üç, yani tektir. Bu sonuç eşlik biti (parity bit) olarak verinin sonuna eklenir ve gönderilen dizi `01001101` olur. Hocanın vurguladığı gibi bu XOR işlemi, uç noktada 1'lerin sayısının çift olmasını sağlar.

Alıcı aynı XOR işlemini eşlik biti dahil tüm bitlere uygular. Sonucun 0 çıkması gerekir.

VRC'nin sorunu şudur:

- **Tek sayıda hata:** Örneğin gönderilen `0100110` iken alınan veride bir 0, 1'e dönmüşse alıcının XOR sonucu 1 çıkar. Hata olduğu anlaşılır, ama nerede olduğu anlaşılamaz.
- **Çift sayıda hata:** Hata iki farklı noktada olduysa XOR sonucu yine 0 çıkar. Bilgi hatalı olduğu halde doğru kabul edilir.

Hoca böyle bir hatanın olasılığının ayrı bir tartışma konusu olduğunu, ama yerine kullanılabilecek daha sağlam mekanizmalar bulunduğunu söyledi.

### 10.2 LRC (İki Boyutlu Eşlik)

LRC'de aynı iş iki boyut üzerinde yapılır. Bir bayt akışı (byte stream) gönderdiğinizi düşünün. Daha önce konuşulduğu gibi hata, birinci baytın bir kısmında, sonra başka bir yerde dağınık olmaz; uzunlamasına büyük bir patlama şeklinde olur. Bunu yakalayabilmek için yapı iki eksene oturtulur.

**Örnek (slayttan):** Dört bayt alt alta yazılır.

1. Her baytın bitleri XOR'lanır ve sonuç o baytın sonuna eşlik biti olarak konur (satır eşliği).
2. Ayrıca baytların birinci bitleri, ikinci bitleri ve sekizinci bite kadar her bit pozisyonu ayrıca XOR'lanır (sütun eşliği). Böylece bir eşlik baytı oluşur.
3. Bu eşlik baytının da kendi eşlik biti hesaplanıp yanına konur.
4. Gönderirken her baytın arkasından kendi eşlik biti, en sonda da LRC eşlik baytı ve onun eşlik biti gönderilir.

<!-- BELİRSİZ: Slayttaki dört baytın değerleri altyazıda okunmuyor; hoca yalnız bir baytın eşlik bitinin 0 geldiğini söylüyor. -->

Bu yapı belli açılardan çok daha güvenlidir: Her baytın sonunda bir kontrol bilgisi, ayrıca hepsini birden kontrol eden bir kontrol baytı vardır. Örnekte 4 bayta karşılık 1 bayt kontrol bilgisi üretilmiştir; veri bu kadar az olunca ek yük fazladır. Hoca pratikte LRC'nin bu kadar az veri üzerinde değil, oranın daha verimli olması için 16, 32 ya da 64 bayt üzerinde uygulandığını söyledi.

LRC de her hatayı yakalamaz. İki baytın aynı iki bit pozisyonunda hata olursa hata görünmez. Hocanın örneği: İkinci baytın birinci ve yedinci bitlerinde, dördüncü baytın da aynı bitlerinde hata olsun. Her baytta iki bit değiştiği için satır eşlikleri değişmez. Her sütunda da iki bit değiştiği için sütun eşlikleri değişmez. Böylece hata algılanamaz. Yani LRC biraz daha güvenlik sağlasa da sistemi atlatabilecek hatalar hâlâ vardır.

> **Ders sonrası not:** Hoca örneği önce "ikinci baytın birinci ve yedinci biti, dördüncü baytın ikinci ve yedinci biti" diye söyledi, hemen ardından iki baytın aynı iki bitinde hata olması gerektiğini belirtti. LRC'yi atlatan durum, iki baytın tam olarak aynı iki bit pozisyonunda bozulmasıdır; farklı pozisyonlar sütun eşliğini değiştirir ve hata yakalanır.

## 11. Döngüsel Artıklık Denetimi (CRC)

### 11.1 Temel Fikir

CRC günümüzde çok etkin biçimde kullanılan bir yöntemdir; örneğin Ethernet'te (IEEE 802) kullanılır. Hoca yöntemi şöyle özetledi: Asal (indirgenemez) bir üreteç polinomu seçilir. Gönderilecek veri bu polinoma bölünür ve kalan, kontrol bilgisi olarak verinin sonuna yerleştirilir. Karşı taraf aldığı bilgiyi, eklenen kalanla birlikte aynı polinoma böler. Sonuç sıfır çıkarsa her şey yolundadır.

Yaygın polinomlar 13, 17 ve 33 bitliktir. Ethernet'te kullanılan 33 bitlik, yani 32. dereceden polinomdur (CRC-32):

$$G(x) = x^{32}+x^{26}+x^{23}+x^{22}+x^{16}+x^{12}+x^{11}+x^{10}+x^{8}+x^{7}+x^{5}+x^{4}+x^{2}+x+1$$

Hoca bu polinomu ezbere saydı. Python ile kontrol edildi: Terimler onaltılık `0x04C11DB7` değerini verir ve polinomun 16. dereceye kadar hiçbir çarpanı yoktur, yani gerçekten indirgenemezdir.

Hoca slaytta CRC-32 için yakalanamayan hata oranının "neredeyse sıfır" yazdığını, ama bunun sıfır demek olmadığını vurguladı. Her şeyi mutlaka yakalarız diye bir durum yoktur. Hoca 2000'li yılların başında yayımlanmış bir çalışmayı hatırladı: Bu çalışma, standart CRC-32'nin Hamming uzaklığının (Hamming distance) 4 olduğunu, daha uygun bir polinomla 6'ya çıkılabileceğini göstermişti. Hoca yazarın adını hatırlayamadı.

> **Ders sonrası not:** Hocanın kastettiği çalışma büyük olasılıkla Philip Koopman'ın 2002 tarihli "32-Bit Cyclic Redundancy Codes for Internet Applications" makalesidir. Makalede IEEE 802.3 CRC-32'nin Ethernet çerçeve boylarında Hamming uzaklığının 4 olduğu, farklı polinomlarla bunun 6'ya çıkarılabileceği gösterilir.

### 11.2 CRC Adımları

1. Üreteç polinomu $n$ bitlikse verinin sonuna $n-1$ tane 0 eklenir.
2. Elde edilen dizi üretece bölünür. Bölme işleminde çıkarma yerine XOR kullanılır (mod-2 bölme).
3. Sonunda $n-1$ bitlik bir kalan kalır. Bu kalan, başta eklenen sıfırların yerine yazılır.
4. Alıcı bir şey eklemeden gelen diziyi doğrudan aynı üretece böler. Kalan 0 ise bilgi doğru kabul edilir, değilse hata vardır.

### 11.3 Örnek

**Verilen (slayttan):** Üreteç polinomu $x^3 + x^2 + 1$, veri `100100`.

Polinomda $x^3$ için 1, $x^2$ için 1, $x$ terimi olmadığı için 0, sabit terim için 1 vardır. Üreteç `1101` olur. Dört bitlik olduğu için verinin sonuna üç tane 0 eklenir: `100100000`.

**Bölme (ara adımlar eklendi):**

```
1 0 0 1 0 0 0 0 0
1 1 0 1             XOR
-------
  1 0 0 0           (sonraki biti indir)
  1 1 0 1           XOR
  -------
    1 0 1 0
    1 1 0 1         XOR
    -------
      1 1 1 0
      1 1 0 1       XOR
      -------
        0 1 1 0     (baştaki bit 0: bir bit kaydır)
          1 1 0 0
          1 1 0 1   XOR
          -------
            0 0 1   kalan
```

**Sonuç:** CRC kalanı `001`'dir. Gönderilen dizi `100100` + `001` = `100100001` olur.

**Alıcıda kontrol:** `100100001` dizisi `1101`'e bölündüğünde kalan `000` çıkar ve veri kabul edilir. Kalan ve kontrol Python ile doğrulandı.

## 12. Sağlama Toplamı (Checksum)

Hoca slaytta checksum için bir şekil olması gerektiğini ama bulunmadığını söyleyip yöntemi sözlü anlattı. Elimizde büyük bir bilgiyi taşıyan uzun bir bit ya da bayt akışı vardır.

1. Veri $m$ bitlik parçalara bölünür: 8 bit, 16 bit ya da daha fazla olabilir. Hoca checksum'ın genellikle alt seviyede, veri bağlantı katmanında değil, taşıma (transport) katmanında kullanıldığını söyledi; bu yüzden daha büyük parçalar üzerinde çalışılabilir.
2. Parçalar alt alta konur ve bire tümleyen (one's complement) aritmetiğine göre toplanır. Sonuçta $m$ bit uzunluğunda bir değer elde edilir.
3. Bu toplamın tümleyeni alınır ve gönderilecek bilginin sonuna sağlama olarak eklenir.
4. Alıcı gelen bilgiyi $m$ bitlik parçalar halinde, sağlama alanı dahil toplar. Sonuç 0 ise bilginin hatasız geldiği, değilse hata olduğu kabul edilir.

> **Ders sonrası not:** Hoca 3. adımda toplamın "ikiye göre tümleyeninin" eklendiğini söyledi. Bire tümleyen toplamada eklenen değer toplamın bire tümleyenidir (bitlerin tersi). Alıcı tarafta da sağlama dahil tüm parçaların bire tümleyen toplamı tüm bitleri 1 olan değeri verir; bunun tümleyeni 0 çıkınca hata yok denir. Hocanın "sonuç 0 ise" demesi bu son tümleme adımını içerir.

> **Ek bilgi (derste anlatılmadı):** Bire tümleyen toplamada en anlamlı bitten taşan elde atılmaz, toplamın en sağ bitine geri eklenir (end-around carry). IP, TCP ve UDP başlıklarındaki 16 bitlik sağlama toplamı bu yöntemle hesaplanır. Checksum'ın yazılımda hesaplanması kolaydır, ancak hata yakalama gücü CRC'den zayıftır; örneğin iki 16 bitlik parçanın yer değiştirmesini fark etmez.

## 13. Hata Düzeltme mi, Yeniden Gönderim mi?

Şimdiye kadar hep hatayı algılamaktan söz edildi. Hocaya göre bu bir açıdan yeterlidir: Aldığınız bilgide hata varsa, kurduğunuz mekanizma üzerinden göndericiye hata olduğunu bildirirsiniz. Gönderici aynı bilgiyi tekrar gönderir. Yine hata olursa tekrar istersiniz. Alternatifi, gelen verideki hatanın tespit edilip alıcıda düzeltilmesidir.

Hoca öğrencilere hangi durumda düzeltmeyi, hangi durumda yalnız algılayıp yeniden gönderimi tercih edeceğimizi sordu. Tartışma şöyle ilerledi:

**Soru (hoca):** Ne zaman hatayı düzeltmek isteriz, ne zaman yalnız tespit etmek isteriz? **Cevap (öğrenci):** Hatanın yerini biliyorsak düzeltmek isteriz. **Hoca:** Elinizde örneğin 1 KB'lık bir veri var. Hatanın yerini bilmek çok büyük bir lükstür.

**Cevap (öğrenci):** Veri önemliyse düzeltmeye çalışırız, önemsizse atarız; örneğin ses aktarımında. **Hoca:** Ses aktarımında bilgi önemli ya da önemsiz değildir, zamanında gelir ya da gelmez. Gerçek zamanlı aktarımda iki çerçeve önce gelmesi gereken ses bilgisi iki çerçeve sonra gelirse artık bir anlamı kalmaz. Ama burada sorulan, zamanlama değil; gelen verinin hatalı olup olmadığını bilmediğiniz bir hatta hangi yaklaşımı seçeceğinizdir.

Hoca cevabı doğrudan paraya bağlamak yerine dolaylı yoldan düşünmeyi istedi ve iletim ortamlarının karşılaştırıldığı dersi hatırlattı. Bir hattınız var: bakır kablo da olabilir, fiber kablo da. Döşendiği ortam gürültülü bir endüstriyel ortam da olabilir, tertemiz bir ortam da. Kablonun yalıtımı muhteşem de olabilir, kötü de. Fiber elektromanyetik etkilerden etkilenmez; isterseniz yüksek gerilim hattının üstüne döşeyin. Bunlara bağlı olarak hattaki hata olasılığı değişir. Hata olasılığı değişiyorsa hata denetimine bakış açınızın da değişmesi gerekir.

**Soru (hoca):** Hata olasılığı yüksek bir hatta yalnız algılama yapar, yani hatayı fark edip yeniden gönderim istersem ne olur? **Cevap (öğrenci):** İletim hızı düşer. **Hoca:** O zaten mutlaka düşecek. **Cevap (öğrenci):** Yeniden gönderilen veri de bozuk gelebilir. **Hoca:** Doğru cevap bu.

Hocanın vardığı sonuç:

- **Hata oranı yüksekse:** Gönderilen çerçevenin bozulma olasılığı yüksektir. Yeniden gönderim isterseniz aynı şey tekrar başınıza gelir. Bunun yerine hatayı düzeltmeyi deneyip çerçeveyi kurtarmak gerekir. Aksi halde "aynı şeyleri yapıp farklı sonuç bekleyen adam" durumuna düşersiniz.
- **Hata oranı düşükse:** Hata çok küçük bir olasılıkla oluşuyorsa, düzeltmeyle uğraşmak yerine yeniden gönderim istenir. "Yıldırım aynı yere iki kez düşmez" mantığıyla bir hata olduysa bir daha olmayacağı varsayılır.

> **Hocanın vurgusu:** Hata düzeltme mi hata algılama mı kullanılacağı doğrudan kullandığınız hattın hata karakteristiğine bağlıdır ve buna uygun yapı seçilmelidir.

## 14. Hata Düzeltme ve Hamming Kodu

### 14.1 Kaç Kontrol Biti Gerekir?

Hata düzeltme için gönderilen bitlerin içine, düzeltmeyi sağlayacak ek kod bitleri konur. Hata tespiti için de benzer bir şey yapılıyordu. Ama düzeltmede, düzeltmek istediğiniz hata miktarına bağlı olarak eklenen kod miktarı hızla artar.

Hoca hesabı şöyle kurdu. $m$ bitlik bir mesajda hata birinci, ikinci, üçüncü... $m$. bitlerden herhangi birinde olabilir. Bir de hiç hata olmama durumu vardır. Toplam $m+1$ durum ayırt edilmelidir. Hata olup olmadığını ve olduysa hangi bitte olduğunu anlamak için en az $\log_2(m+1)$ kontrol biti gerekir.

**İlk deneme:** $m = 7$ için $m + 1 = 8$ ve $\log_2 8 = 3$. Buna göre en az 3 bit gerekir gibi görünür.

Fakat hata yalnız veri bitlerinde olmaz, kontrol bitlerinde de olabilir. Eklediğiniz $r$ bitin de bozulabileceği hesaba katılınca ayırt edilmesi gereken durum sayısı $m + r + 1$ olur. Koşul şudur:

$$2^r \ge m + r + 1 \quad \text{ya da} \quad r \ge \log_2(m + r + 1)$$

**Doğru hesap ($m = 7$):**

- $r = 3$: $2^3 = 8$, ama $m + r + 1 = 7 + 3 + 1 = 11$. $8 < 11$ olduğu için yetmez.
- $r = 4$: $2^4 = 16$ ve $m + r + 1 = 7 + 4 + 1 = 12$. $16 \ge 12$ olduğu için koşul sağlanır.

Koşulu sağlayan ilk tam sayı $r = 4$'tür. Yani 7 bitlik veriye 4 kontrol biti eklenir ve kod sözcüğü 11 bit olur. Hesap Python ile doğrulandı.

> **Hocanın vurgusu:** Kontrol bitleri yalnız veriyi değil kendilerini de korumalıdır. Bu yüzden hesap $m+1$ ile değil, $m+r+1$ ile yapılır.

### 14.2 Kontrol Bitlerinin Yerleşimi

Sıradaki soru, bu 4 bitin nereye konacağıdır: sona mı, başa mı, verinin içine dağıtarak mı? Genel yaklaşım, kontrol bitlerinin 2'nin kuvveti olan pozisyonlara, yani 1, 2, 4 ve 8. bitlere konmasıdır. Slayttaki tabloda üst satır bit pozisyonlarını, alt satırdaki $r$'ler kontrol bitlerini, $d$'ler veri bitlerini gösteriyordu:

| Pozisyon | 11 | 10 | 9 | 8 | 7 | 6 | 5 | 4 | 3 | 2 | 1 |
|---|---|---|---|---|---|---|---|---|---|---|---|
| Bit | $d$ | $d$ | $d$ | $r_8$ | $d$ | $d$ | $d$ | $r_4$ | $d$ | $r_2$ | $r_1$ |

<!-- BELİRSİZ: Slayttaki tablonun pozisyonları sağdan sola mı soldan sağa mı yazdığı altyazıdan anlaşılmıyor; yerleşim (1, 2, 4, 8 kontrol; 3, 5, 6, 7, 9, 10, 11 veri) hocanın anlatımından alındı. -->

### 14.3 Kontrol Bitlerinin Hesabı

Her kontrol biti belirli pozisyonlardaki bitlerin XOR'u (eşliği) olarak hesaplanır. Hoca ilk ikisini söyledi, bunların önceden belirlenmiş bir dizi olduğunu belirtti:

- $r_1$: 1, 3, 5, 7, 9, 11 pozisyonları (tek pozisyonlar).
- $r_2$: 2, 3, 6, 7, 10, 11 pozisyonları.
- $r_4$: 4, 5, 6, 7 pozisyonları (ara adım eklendi).
- $r_8$: 8, 9, 10, 11 pozisyonları (ara adım eklendi).

Alıcı, gelen kontrol bitleriyle birlikte aynı XOR hesaplarını tersten yapar. Hata yoksa hepsinin 0 çıkması gerekir.

> **Ek bilgi (derste anlatılmadı):** Kural şudur: $r_k$ kontrol biti, pozisyon numarasının ikili gösteriminde $k$ değerli biti 1 olan bütün pozisyonları kapsar. Alıcı dört denetimin sonucunu $r_8 r_4 r_2 r_1$ sırasıyla yan yana yazdığında oluşan ikili sayıya sendrom denir. Sendrom 0 ise hata yoktur; sıfırdan farklıysa değeri doğrudan hatalı bitin pozisyonunu verir ve o bit ters çevrilerek düzeltilir.

### 14.4 Sınırlar ve Diğer Kodlar

Hoca yapılan bütün bu işin 7 bitlik veri üzerinde tek bir hatanın bulunup düzeltilmesine karşılık geldiğini söyledi. Bütün olası hataları bulmak isterseniz birli, ikili, üçlü ve $n$'li bütün hata kombinasyonlarını ayırt etmeniz gerekir. Kombinasyon sayısı o kadar artar ki koymanız gereken kontrol miktarı "uçuk kaçık" bir noktaya gelir.

Bu yüzden hata düzeltmede belli bir sınırla gidilir. 7 bitlik bir bilgi gönderiyorsanız ya bir hatayı ya da en fazla iki hatayı düzeltecek şekilde tasarım yaparsınız; en azından Hamming kodu için durum budur.

Hoca alternatif yöntemler olarak Reed–Solomon kodlarını ve düşük yoğunluklu eşlik denetimi (LDPC, Low Density Parity Check) kodlarını saydı. Bunların arkasındaki aritmetik karışık olduğu için dersin kapsamına girmiyor. Ama bunların daha maliyetli yapılar olduğu unutulmamalı.

<!-- BELİRSİZ: Hocanın saydığı kodlardan biri altyazıda "binary formal regional codes" diye bozuk çıkmış; kodun adı kayıttan anlaşılamıyor. -->

## Örnek Sorular

**Soru 1** (derste sözlü, 01:11:26): Bir hatta hata düzeltme mi uygulamak istersiniz, yoksa hatayı yalnız tespit edip göndericiden bilginin yeniden gönderilmesini mi? Bu seçimi neye göre yaparsınız?

> **Çözüm (derste verildi):** Seçim, kullanılan hattın hata karakteristiğine bağlıdır. Hattın hata olasılığı kablo türüne, yalıtıma ve ortamdaki gürültüye göre değişir. Hata oranı düşükse yalnız algılama ve yeniden gönderim yeterlidir; tekrar gönderilen çerçevenin yine bozulması olasılığı düşüktür. Hata oranı yüksekse hata düzeltme kodu kullanılmalıdır.

**Soru 2** (derste sözlü, 01:17:21): Hata olasılığı yüksek bir hatta yalnız hata algılama yapılır ve her hatada yeniden gönderim istenirse ne olur?

> **Çözüm (derste verildi):** Yeniden gönderilen çerçeve de büyük olasılıkla bozuk gelir. Aynı çerçeve defalarca istenir ve hattın verimi düşer. Bu durumda çerçeveyi alıcıda düzelterek kurtarmak gerekir.

## Dersin Toparlaması

Bu derste önce kablosuz iletim ortamı tamamlandı. Düşük frekanslı radyo dalgaları her yöne yayılır ve engellerden geçer. Bu kapsama alanı sağlar ama yalıtım sağlamaz. Frekans arttıkça sinyal yönlü hale gelir: mikrodalga görüş hattı ister ve atmosferden etkilenir, kızılötesi ise kısa mesafeli, noktadan noktaya çalışır ve güneş ışığından etkilenir. Aynı kanalı paylaşan vericilerin çakışması, Wi-Fi ve Bluetooth örnekleriyle gösterildi.

Ardından düşük kapasiteli çok sayıda hattın trafiğini yüksek kapasiteli tek bir hatta taşıyan çoğullama anlatıldı: koruma bantlı FDM ve onu sıkıştıran OFDM, sabit slotlu senkron TDM ve adres bilgisi karşılığında boş slotları ortadan kaldıran istatistiksel TDM, fiberde dalga boyu bölmeli WDM. Son bölümde hataların nedenleri ve türleri, kontrol bilgisi üretme fikrine dayanan VRC, LRC, CRC ve checksum, son olarak $2^r \ge m+r+1$ koşuluyla Hamming kodu işlendi. Hoca önümüzdeki hafta veri bağlantı denetimi (data link control) ile devam edileceğini, bağlantı yönetimi ve akış denetimi (flow control) konularına geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
