# Ders 17 Genişletilmiş Notu: Devre Anahtarlama, Paket Anahtarlama ve Sanal Devreler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Veri Bağı Katmanından Ağ Katmanına Geçiş
- 2. Bilgisayar Ağlarının Sınıflandırılması
- 3. Devre Anahtarlama ve Üç Aşaması
- 4. Uzay Bölmeli Anahtarlama: Crossbar ve Çok Katlı Yapılar
- 5. Zaman Bölmeli Anahtarlama, Karma Yapılar ve Yazılım Tabanlı Anahtarlama
- 6. Paket Anahtarlama ve Patlamalı Veri
- 7. Datagram Yaklaşımı
- 8. Sanal Devre Yaklaşımı: SVC ve PVC
- 9. Paket Boyutunun İletim Süresine Etkisi
- 10. Bağlantısız ve Bağlantı Yönelimli Hizmetler
- 11. Datagram, SVC ve PVC Karşılaştırması
- 12. Katmanlara Göre Ağ Cihazları
- Örnek Sorular

## 1. Veri Bağı Katmanından Ağ Katmanına Geçiş

Hoca, bir önceki hafta proje ödevi verildiği için konu sırasının değiştiğini söyledi. Normalde son haftada anlatılacak olan TCP/IP modeli ve iletişimde kullanılan cihazlar (switch, router vb.) bir hafta öne alındı. Bu hafta anahtarlama (switching) ile bağlantı yönelimli (connection-oriented) ve bağlantısız (connectionless) hizmetler anlatıldı.

Derse kadar konuların çoğu veri bağı katmanı (data link layer) üzerineydi. Hoca, dönemin başında ağ katmanını (network layer) ve üstünü ayrıntılı anlatmayacaklarını, bunların ağ teknolojileri ve ileri ağ programlama gibi derslerde görüleceğini hatırlattı. Anahtarlama ile birlikte ağ katmanına "hafifçe" giriliyor. Veri bağı katmanı yaklaşık 10 hafta anlatıldı; ağ katmanının da en az o kadar konusu var. Bu dersteki odak, paketlerin nasıl iletildiğidir.

## 2. Bilgisayar Ağlarının Sınıflandırılması

Bilgisayar ağları temelde ikiye ayrılır: yayınlı (broadcast) ağlar ve anahtarlamalı (switched) ağlar.

Yayınlı ağlar yerel alan ağlarıdır (Local Area Network, LAN). Hoca LAN'da bus, star, ring ve mesh gibi topolojileri hatırlattı. LAN'da bağlı cihaz sayısı azdır, mesafe de 50-100 metreyi geçmez. Hocanın örneği, alt kattaki bilgisayar laboratuvarıdır.

Geniş alan ağında (Wide Area Network, WAN) ise kişi İstanbul'un başka bir ucuyla ya da başka bir şehirle konuşur. Burada farklı yapılar gerekir. Anahtarlamalı ağların üç türü vardır:

- Devre anahtarlamalı (circuit switching) ağlar.
- Paket anahtarlamalı (packet switching) ağlar.
- Mesaj anahtarlamalı (message switching) ağlar.

Derste devre ve paket anahtarlama anlatıldı. Mesaj anahtarlama yalnız adıyla anıldı.

Hoca, WAN'da neden anahtarlama gerektiğini de açıkladı. Bir odada 20 bilgisayar varsa onları mesh ile bile bağlayabilirsiniz; saçma olabilir ama yapılabilir. Bus ya da ring de makuldür. Ama Erzurum ile İstanbul'u ring ya da mesh ile bağlamak mümkün değildir. Bu yüzden geniş alanda anahtarlama teknikleri geliştirilmiştir.

## 3. Devre Anahtarlama ve Üç Aşaması

Devre anahtarlamada (ve diğer yöntemlerde de benzer biçimde) üç aşama vardır:

- Bağlantının kurulması (establishing connection).
- Verinin iletimi (data transfer, transmitting).
- Bağlantının sonlandırılması (connection termination).

Hoca bu aşamaları eski, sabit hatlı ev telefonu ile anlattı. Bugün cep telefonuyla ararken VoIP (Voice over IP) kullanıldığını, burada eski model ev telefonunun düşünülmesi gerektiğini söyledi.

**Bağlantı kurma:** Ahizeyi kaldırdığınızda santralden "biip" diye bir sinyal gelir. Bu, hattın müsait olduğunu gösteren çevir sesidir. Hat meşgulse "bip bip bip" diye giden meşgul tonu gelir; bu da santralden gelir. Sonra numarayı tuşlarsınız. Her tuşun farklı bir tonu, yani farklı bir frekans değeri vardır. Hoca, bugün dokunmatik ekranlı telefonlarda tuş seslerini açınca aynı tonların duyulabildiğini söyledi. Tonlar santrale iletilir. Santral kiminle görüşmek istediğinizi anlar ve o numaranın bağlı olduğu hatta istek gönderir. Karşı telefon çalmaya başlar. Hikayenin başından karşı tarafın ahizeyi kaldırmasına kadar geçen süre bağlantı kurma aşamasıdır.

**Veri iletimi:** Ahize kaldırıldığı andan itibaren veri aktarımı başlar. İki taraf karşılıklı konuşur.

**Sonlandırma:** Taraflardan biri ya da ikisi birden telefonu kapatır. Sonradan kapatan taraf, görüşmenin bittiğini gösteren özel bir sinyal duyar; örneğin biri yüzünüze kapattığında bunu duyarsınız.

Hoca bu sinyallerin aslında insanların duyması için gerekli olmadığını vurguladı. Duymasak da bu işlemler gerçekleşirdi. Ama hatta insanların da algılayabileceği biçimde sinyalleştirilmişlerdir.

### 3.1 Telefon Çalarken Hattaki Gerilim

Hoca bir dipnot olarak şunu ekledi: Kablosuz olmayan eski telefonlara ayrıca elektrik bağlanmazdı. Gerekli enerji veri hattı üzerinden gelirdi. Telefon çaldığında, telefondan telefona değişmekle beraber, çok düşük akımda yaklaşık 70-80 voltluk bir gerilim oluşur. Bu gerilim insanı çarpacak seviyededir. Hoca, telefonların normalde 3 volt civarında çalıştığını söyledi.

> **Ders sonrası not:** Büyük olasılıkla doğru değerler şöyledir: Sabit telefon hattı boşta yaklaşık 48 V doğru gerilimle beslenir. Zil sinyali genellikle 75-90 V (etkin değer), 20-25 Hz'lik alternatif gerilimdir. Ahize kaldırılınca telefon uçlarındaki gerilim birkaç volta ile on volt civarına düşer. Hocanın "70-80 V" değeri bu aralığa yakındır.

## 4. Uzay Bölmeli Anahtarlama: Crossbar ve Çok Katlı Yapılar

### 4.1 Crossbar Anahtar

Devre anahtarlamanın temel fikri, hatların bir matris biçiminde kesişmesi ve kesişim noktalarındaki anahtarlarla bağlantı kurulmasıdır. Hocanın slaytında A, B, C giriş hatları ile 1, 2, 3, 4 numaralı çıkış hatları vardı.

A'nın 1 ile konuşabilmesi için bu matriste her giriş-çıkış çiftine bir anahtar (switch) gerekir. 3 giriş ve 4 çıkış olduğu için:

$$3 \times 4 = 12 \text{ anahtar}$$

Genel olarak $N$ giriş ve $M$ çıkış için $N \times M$ anahtar gerekir. Hoca anahtarı, evdeki lambayı açıp kapadığımız anahtar gibi düşünmemizi istedi. Kesişim noktasında transistör gibi açılıp kapanan bir eleman vardır. A'dan 1'e iletişim için o noktadaki anahtarın kapanması (close) gerekir. Anahtar kapandığında A ile 1 arasındaki devre tamamlanır. Slayttaki örnekte A–1, B–2 ve C–4 bağlantıları kapalıydı.

Bu yapının önemli bir sonucu vardır. A ile 1 arasında devre kurulduğunda, 3 numara A ile konuşmak isterse konuşamaz; meşgul tonu duyar. Ayrıca bir uç, iletişime geçmesi gereken her cihazla ayrı bir anahtar üzerinden bağlanmış olmalıdır. Karşı taraf ve kendi devresi müsaitse konuşabilir.

Hoca bunu eski telefon santrallerine benzetti. Filmlerde operatörlerin kabloları bir yerden çıkarıp başka yere taktığını görürüz. Operatör kabloyu taktığında A ile B arasındaki devreyi tamamlamış olur. Bu yapıya crossbar denir.

### 4.2 Crossbar'ın Ölçek Sorunu

Hoca, yalnız crossbar kullanılsaydı ne olacağını sordu. Türkiye'de 3000 telefon, yani 3000 uç nokta olduğunu düşünelim. Bir kişiyi bu 3000 uca bağlamak için yalnız onun adına 3000 anahtar gerekir. Geri kalan 2999 uç için de her birine 3000 anahtar gerekir. Toplam (ara adım eklendi):

$$3000 \times 3000 = 9\,000\,000 \text{ anahtar}$$

Bu karmaşa yüzünden gerçek sistemler çok katlı (multistage) yapılarla ilerler.

### 4.3 Çok Katlı Anahtarlama

Hocanın örneği şuydu: 50 yıl önce Erzurum'daki biri İstanbul'u arayacaksa önce Erzurum'daki santrale bağlanır. Erzurum santrali ile Ankara'daki santral arasında bir anahtar kapanır. Ardından Ankara santrali ile İstanbul santrali arasında bir anahtar daha kapanır. İstanbul'daki uç noktaya bu yolla ulaşılır. Hoca, "Ankara üzerinden" gitmenin esprilere bile konu olduğunu hatırlattı. Ara santralin Ankara olması şart değildir. Belirli santraller arasında çoğullama (multiplexing) yapacak, çoklu iletişime izin veren bir yapı kurulur.

Hoca bunu telefon üzerinden anlattığını, ama veri gönderiminde de durumun aynı olduğunu söyledi. Aynı hat üzerinden veri de gönderilebilir, ama düşük miktarlarda. Veri trafiği patlamalı (bursty) olduğu için devre anahtarlama yetersiz kalır. Paket anahtarlamaya bu yüzden geçilir.

## 5. Zaman Bölmeli Anahtarlama, Karma Yapılar ve Yazılım Tabanlı Anahtarlama

### 5.1 Zaman Bölmeli Anahtarlama ve TSI

Crossbar'daki anahtarlar uzayda ayrı yollar kurar; buna uzay bölmeli (space division) anahtarlama denir. Bir de zaman bölmeli (time division) anahtarlama vardır ve burada zaman bölmeli çoğullama (Time Division Multiplexing, TDM) kullanılır.

Hoca çoğullama dersini hatırlattı. A, B, C ve D adlı dört kaynak verilerini karşıya iletmek istesin. Zaman, örneğin 1 milisaniyelik dilimlere ayrılır. Dört kaynak olduğu için zaman dört parçaya bölünür ve her kaynağa özel bir zaman dilimi (time slot) verilir. Her kaynak yalnız kendi diliminde gönderebilir.

Paketlerin karşıya belirli bir sırayla ulaşması önemliyse ek bir birim gerekir. Hoca, bazı yöntemlerde sıranın garanti olmadığını, bazılarında ise paketlerin gönderildiği sırada ulaştığını ve alıcının bunu bildiğini söyledi. Burada TSI (Time Slot Interchange) denen donanım birimi kullanılır. TSI'nın içinde bir bellek vardır. Aldığı verileri bir tampona (buffer) yığar, sıralar ve sonra gönderir.

> **Ek bilgi (derste anlatılmadı):** Time Slot Interchange, büyük olasılıkla giriş çerçevesindeki zaman dilimlerini belleğe sırayla yazıp çıkışta farklı bir sırayla okuyarak çalışır. Böylece bir giriş dilimindeki veri istenen çıkış dilimine taşınır; yani TSI, zaman ekseninde bir "anahtarlama" yapar. Bu yazma-okuma işlemi en fazla bir çerçeve süresi kadar gecikme ekler.

### 5.2 Uzay ve Zaman Bölmeli Anahtarlamanın Karşılaştırılması

Hoca iki yaklaşımın artı ve eksilerini şöyle anlattı:

- **Zaman bölmeli:** TSI veriyi tamponda biriktirip sıraladığı için akla ilk gelen sorun zaman, yani gecikmedir. Ama patlamalı veri gönderiliyorsa herkese belli zaman aralıklarında gönderme imkanı veren bir yapı daha mantıklıdır.
- **Uzay bölmeli:** Bir devre anahtarlandığında, karşı taraf veri göndermeye başlar ve "hiç susmazsa", başka biri aynı uca veri gönderemez. Sürekli meşgul tonu alır. Zaman bölmeli yapının bu konuda avantajı vardır.

### 5.3 Karma (Hibrit) Yapılar

Karma (hybrid) anahtarlamada uzay bölmeli ve zaman bölmeli yapılar birlikte kullanılır. Amaç performansı artırmaktır. TSI'nın yavaşlatıcı etkisi ile uzay bölmeli yapının meşguliyet sorunu birlikte ele alınır. Farklı kombinasyonlarda yapılar geliştirilmiştir. Hoca bunların ayrıntısına girmedi.

### 5.4 Yazılım Tabanlı Anahtarlama

Bir de yazılım tabanlı anahtarlama (software switching) vardır. Hoca VoIP örneğini verdi. Cep telefonuyla birini aradığında ekranın üstünde VoIP sembolü görünebilir. Wi-Fi'ye bağlıysa arama doğrudan Wi-Fi üzerinden VoIP ile yapılır. 4.5G ya da 3G gibi hücresel bağlantılarda da büyük olasılıkla VoIP kullanılır.

### 5.5 Devre Anahtarlamanın Özeti

Hoca devre anahtarlamayı şöyle toparladı: Karşınızda transistör gibi, açık-kapalı görevi yapan bir anahtar vardır. Bu anahtarı açıp kapatarak iki makine arasında kapalı bir devre oluşturursunuz. Bir hat oluşur ve sanki iki makine arasında bir kablo varmış gibi davranır.

## 6. Paket Anahtarlama ve Patlamalı Veri

### 6.1 Ses Trafiği ile Veri Trafiği

Paket anahtarlamada sesten sonra veri gönderimine geçilir. Hoca ses verisinin "standart" olduğunu söyledi. Telefonda bazen konuşur, bazen susarız. Ama sussak bile ortamın bir sesi vardır ve gönderilen sesin frekansı hep bellidir. Karşıya da aynı biçimde ulaşır.

Veri trafiği ise patlamalıdır (bursty). Haber sitelerinde gezer, Twitter'da birkaç kısa metin okursunuz; bunlar küçük iletişimlerdir. Sonra Netflix'te 4K film izlemeye başlarsınız ve veri kullanımınızın hacmi birden değişir. Küçük bir hacimde çalışırken birden bir patlamaya sebep olursunuz. Paket anahtarlama yöntemleri özellikle bu tür patlamalı durumlar için tasarlanmıştır.

### 6.2 Faturalandırma

Devre anahtarlamada A ile C arasında devre kurulduktan sonra, iki taraf arasında "garip bir sessizlik" (awkward silence) olsa ve boş boş beklense bile ücret ödenmeye devam eder. Devre kapanana, yani üçüncü aşama bitene kadar ödeme sürer.

Paket anahtarlamada ise santraller ya da servis sağlayıcılar gönderilen paket başına ücret çıkarır: bayt, kilobayt, bugün gigabayt üzerinden. Hoca evdeki sınırsız internetin de bir faturalandırma biçimi olduğunu söyledi. Belli bir sınırı geçince hızın düşmesi de bir tür faturalandırma tekniğidir.

### 6.3 Hat Arızasına Tepki

Devre anahtarlamada C ile devre kurulmuşken hattaki kablo koparsa, kablo tamir edilene kadar o uca bir daha veri gönderilemez. Paket anahtarlamada, özellikle datagram kullanılıyorsa, uyum (adaptiflik) hızlıdır: "E'den Z'ye gidemiyorum, o zaman F'den Z'ye giderim" mantığı işler.

## 7. Datagram Yaklaşımı

### 7.1 Posta ve Kargo Benzetmesi

Hoca datagramı "tam anlamıyla posta servisi" diye tanımladı. PTT'yi ya da kargo şirketlerini düşünün. Buradan Trabzon'a, Ordu'ya, Van'a, Şırnak'a bir şey göndereceksiniz. Farklı kargo şirketlerine verseniz aynı yolu da izleyebilirler, farklı yolu da. Bitlis'e gidecek bir kargo, şoförün inisiyatifine göre önce Ankara'ya götürülüp başka bir kamyona yüklenebilir ya da doğrudan Bitlis'e gidebilir. Bildiğimiz şey şudur: Yolda bir sorun varsa (trafik kazası, üç gün kapalı yol, kar) kargo başka bir yoldan götürülür. Datagram yaklaşımı aynen bu servise benzer.

Aynı adrese, aynı hizmeti alarak dört mektup gönderdiğinizi düşünün. 1, 2, 3, 4 sırasıyla gönderirsiniz. Karşıya belki önce 3 varır. Bazısı ilk alınmasına rağmen en son ulaşır. Bazısı da başına bir şey gelir ve hiç ulaşmaz. Kargo şirketlerinde de paketler kaybolabilir. Datagramda da veriler kaybolabilir.

### 7.2 Ara Düğümlerde Yönlendirme

Bilgisayar paketleri göndermeye başlar. Paket A düğümüne gelir. A, "B'den mi gitsem, C'den mi?" diye karar verir. Ara düğümlerde nereden nereye, ne kadar mesafede, ne hızda veri gönderileceğine dair bilgiler tutulur ve bu bilgiler hattın o anki müsaitlik durumuna göre sürekli güncellenir. Her mesajın içinde de nereye gitmek istediğini gösteren bir adres bilgisi vardır. Paket bu adrese göre ağ içinde dallanarak ilerler. Hoca bu ara noktaların birer ağ elemanı olduğunu ve önümüzdeki hafta görüleceğini söyledi.

Ardı ardına gönderilen dört paket alıcıya farklı sırayla ulaşabilir, çünkü farklı yollar izleyebilirler. Hocanın örnek yolları:

- A–C–D–F–Z
- A–C–F–Z
- A–C–F–E–Z
- A–B–D–C–F–Z

Paketler aynı yoldan gidip aynı sürede de ulaşabilir; farklı yoldan gitmeleri şart değildir.

## 8. Sanal Devre Yaklaşımı: SVC ve PVC

### 8.1 Temel Fikir

Sanal devrede (virtual circuit) iki uç arasında sanki bir devre varmış gibi davranılır. Datagramda her paket, ara düğümlerdeki güncel bilgilere göre kendi yolunu bulur. Sanal devrede ise gönderici, veri göndermeye başlamadan önce devreyi belirleyecek bir paket gönderir. Bu paket, verinin ilk paketi değildir. Ağdaki düğümlerden geçerek örneğin "A'dan Z'ye en hızlı A–B–D–F–Z üzerinden gidebilirim" der. Bundan sonra bütün paketler bu yoldan gider.

Bunun iki biçimi vardır: anahtarlamalı sanal devre (Switched Virtual Circuit, SVC) ve kalıcı sanal devre (Permanent Virtual Circuit, PVC).

### 8.2 Anahtarlamalı Sanal Devre (SVC)

SVC'de ilk paket gönderilir, yol belirlenir (hocanın bu kısımdaki örneği A–C–D–F–Z) ve bütün paketler hep bu yoldan gider. Hoca, verinin bir protokol kapsamında, yedi katmandan geçerek gönderildiğini hatırlattı. Ona göre SVC'de sanal devrenin ne olacağı, oturum katmanında (session layer) bir uçtan diğerine gönderilen bir paketle belirlenir.

Yolda örneğin A ile C arasında bir kopukluk olursa, hocanın anlatımına göre ağ katmanı gönderemeyeceğini fark eder, durum üst katmanlara çıkar. Oturum katmanında oturum sonlandırılıp yeniden başlatılır. O zaman ulaşabilen farklı bir sanal devre seçilir.

> **Ders sonrası not:** Hoca SVC'nin oturum katmanında gönderilen bir paketle kurulduğunu ve yol bozulunca oturum katmanının yeni devre kurduğunu söyledi. Büyük olasılıkla doğrusu şudur: Sanal devre kurulumu ve yeniden kurulumu ağ katmanındaki çağrı kurma sinyalleşmesiyle yapılır. Örneğin X.25'te Call Request ve Call Accepted paketleri, ATM'de Q.2931 sinyalleşmesi kullanılır.

Kurulan yola bir tanımlayıcı verilir: sanal kanal tanımlayıcısı (Virtual Channel Identifier, VCI). Hoca burada devre anahtarlamayla karşılaştırma yaptı. Devre anahtarlamada iki uç doğrudan birbirine bağlıdır; adrese gerek var mı? Hayır, bir uç diğer ucun ta kendisidir. Datagramda ise paketin nereye gideceğini bilmek için adrese ihtiyaç vardır. Sanal devrede bilinen şey yalnız oluşturulan sanal kanalın tanımlayıcısıdır. Sanal devre kurulduktan sonra o devrenin bir numarası olur.

> **Hocanın vurgusu:** "Bunu geçen yıllarda hep sorduk sınavlarda": Datagramda her paketin içinde gideceği yerin adres bilgisi vardır. Sanal devrede ise paket yalnız sanal devrenin numarasını (VCI) taşır.

İlk pakette oluşturulan bu tür sanal devreye anahtarlamalı sanal devre denir.

### 8.3 Kalıcı Sanal Devre (PVC)

PVC'de bir servis sağlayıcıdan hizmet alırsınız ve çeşitli santrallere bağlısınızdır. B ile iletişim kurmak istediğinizde, aranızdaki sanal devreyi servis sağlayıcı oluşturur. Sizin oturum katmanınız gidip bir şey kurmaz; sağlayıcı bunu sizin adınıza yapar. Bu yüzden "kalıcı" (permanent) denir. O uca veri göndereceğiniz her zaman hep aynı yoldan gönderirsiniz.

Sağlayıcının önerdiği yol örneğin A–B–E–F–Z olsun ve B ile E arasındaki bağlantı kopsun. Bu sanal devrenin yenilenmesi için servis sağlayıcının olaya müdahil olması, yolu yenilemesi ve bunu size bildirmesi gerekir.

SVC'de olduğu gibi PVC'de de paketlerin üzerinde varacakları yerin adresi yoktur; yalnız sanal devrenin tanımlayıcısı vardır.

### 8.4 Üç Yaklaşımın Farkı

Hoca üç yaklaşım arasındaki farkı yeniden vurguladı:

- **Datagram:** Paketler teker teker gönderilir ve her paket gideceği yeri bilir. A'dan C'ye gidemezse A'dan B'ye gider. B'den D'ye, D'den F'ye gitmek ister; olmazsa D'den B'ye geri döner, B'den E'ye gider. Bunu her paket kendi başına yapabilir.
- **SVC:** Paketler gidecekleri yerin adresini bilmez, yalnız kurulan devrenin tanımlayıcısını bilir. Bir sorun olduğunda, yeni bir oturum (hocanın anlatımıyla) başlatılana kadar sorun çözülmez.
- **PVC:** Sorun olduğunda servis sağlayıcının müdahalesi gerekir.

## 9. Paket Boyutunun İletim Süresine Etkisi

### 9.1 Hocanın Örneği

Hoca, paket boyutunun ne olması gerektiği sorusunu bir örnekle ele aldı.

**Verilen:**

- Gönderilecek veri: 40 bayt.
- Her pakete eklenen başlık (header): 3 bayt.
- X, Y'ye gönderiyor. Arada A ve B düğümleri var. Yol: X → A → B → Y, yani 3 bağlantı (hop).

Tek paket hâlinde gönderilirse paket $40 + 3 = 43$ bayttır. X paketi gönderir; paket bir süre sonra A'ya ulaşır. A paketi tamamen aldıktan sonra hatta yeniden basar ve B'ye ulaşır. B de aynısını yapar ve paket Y'ye ulaşır.

Veri ikiye bölünürse her parça 20 bayt veri ve 3 bayt başlıkla $23$ bayt olur. Bu durumda X ilk parçayı gönderir göndermez A onu iletmeye başlar. Bu sırada X'ten ikinci parçayı alır. İkinci parçayı almayı bitirince onu da gönderir. İlk parçanın gönderimi bittiğinde ikinci parçanın gönderimi de başlamış olur. Yani düğümler aynı anda hem alıp hem gönderebilir. Bu yüzden 40 bayttan 20 bayta inildiğinde bitiş zamanı öne çekilir ve performans artar.

Sayısal karşılaştırma (ara adım eklendi): Her bağlantının hızı aynı, bir baytın iletim süresi 1 birim olsun. Yayılma ve işleme gecikmesi ihmal edilsin. Her düğüm paketi tamamen aldıktan sonra iletsin. $h$ bağlantı sayısı, $k$ paket sayısı, $s$ paket boyutu olmak üzere ilk paket $h \cdot s$ sürede varır, sonraki her paket $s$ kadar sonra gelir:

$$T = (h + k - 1)\, s$$

- **1 paket:** $s = 43$, $T = (3 + 1 - 1) \times 43 = 3 \times 43 = 129$ birim.
- **2 paket:** $s = 20 + 3 = 23$, $T = (3 + 2 - 1) \times 23 = 4 \times 23 = 92$ birim.

İkiye bölmek süreyi 129 birimden 92 birime indirir. Bu değerler python ile, düğüm düğüm adım simülasyonuyla da doğrulandı.

Hoca sonra "bunu hadi ona düşürelim" dedi ve daha da hızlı gönderildiğini gösterdi.

<!-- BELİRSİZ: "Ona düşürelim" ifadesinin paket başına 10 bayt veriyi mi (4 paket, 13 bayt) yoksa 10 paketi mi (4 bayt veri, 7 bayt) kastettiği altyazıdan anlaşılmıyor. Slayttaki bölme sayıları ve süreler altyazıda okunmuyor. -->

### 9.2 Küçültmenin Sınırı

Paket boyutunu küçültmek belli bir noktaya kadar performansı artırır. Hoca şunu sordu: O zaman birer bitlik paketler mi gönderelim? Ne kadar küçülteceğiz?

Cevap başlıktadır. Her pakete bir başlık eklenir. 3 paket gönderiyorsanız 3 başlık, 6 paket gönderiyorsanız 6 başlık iletilmelidir. Paketi belli bir değerden daha küçüğe böldüğünüzde, başlıklarla birlikte toplam veri o kadar artar ki iletim, daha az parçaya bölünmüş hâlinden bile yavaş olur. Yani paketi belli bir değerin altına bölemezsiniz ve bu sınır başlığın boyutuyla ilgilidir.

> **Hocanın vurgusu:** "Bu kısmı lütfen kafanızda güzel canlansın. Niye paket boyutu küçüldükçe daha hızlı gönderiyoruz ve onun durma noktası neye göre değişiyor? Ne kadar küçülteceğiz kısmı? Önemli konulardan birisi."

> **Ders sonrası not:** Aynı modelde (3 bağlantı, 40 bayt veri, 3 bayt başlık) python hesabı şöyledir: 4 paket ($s = 13$) için 78 birim, 5 paket ($s = 11$) için 77 birim, 10 paket ($s = 7$) için 84 birim. En kısa süre 5 pakettedir; 10 pakete bölünce süre yeniden artar. Hocanın slaytı büyük olasılıkla bu bölme sayılarını gösteriyordu, ama altyazıdan doğrulanamıyor.

## 10. Bağlantısız ve Bağlantı Yönelimli Hizmetler

### 10.1 Araba ve Tren Benzetmesi

Bağlantı sağlamada iki yaklaşım vardır. Bağlantısız (connectionless) yaklaşımda alıcı ile gönderici arasında doğrudan bir bağlantı yoktur. Hoca bunun "çok önemli" olduğunu söyledi. Paket gönderilir ve bir yoldan gider.

Hoca bunu yolculukla anlattı. Buradan Ankara'ya arabayla gitmek isterseniz farklı yollar önerilir: Bolu Dağı'ndan, Eskişehir üzerinden ya da otoyola para vermemek için Bilecik üzerinden. Otoyolda kaza varsa Eskişehir'den, Bolu Dağı'na kar yağdıysa Bilecik'ten gidilir. Bu datagramdır.

Ankara'ya trenle gitmek isterseniz ise tek bir yol vardır; alternatif yoktur. Ne zaman nereye gideceğiniz bellidir. Bu bağlantı yönelimli (connection-oriented) yaklaşımdır. Tren yolunda bir kaza olursa tren "başka tren yolundan gideyim" diyemez, çünkü tek hat vardır. Belki insan unsuru devreye girer: Gidiş hattı yarı zamanlı geliş için kullanılır, yeşil ve kırmızı bayraklarla trenler sırayla geçirilir. Ama tek hat düşünülürse tren hiçbir yere gidemez.

### 10.2 Datagramın Avantajları ve Dezavantajları

Hoca datagramın özelliklerini şöyle sıraladı:

- **Bağlantı kurma aşaması yoktur.** Sanal devrede ise SVC'de (hocanın anlatımıyla) oturum katmanı, PVC'de servis sağlayıcı bir bağlantı kurma aşaması yürütür; ilk paket gidip yolu belirler.
- **Az sayıda paket için hızlı iletim** sağlar. Çok paket gönderilmeyecekse paketler bu yolla karşıya ulaşabilir.
- **Basit bir yapıdır.** Her paket, bulunduğu ağ elemanının durumuna göre nereye gideceğine kendisi karar verir.
- **Tıkanıklığa hızlı tepki verir.** Hocaya göre en önemli avantajlardan biri budur. Hatta bir tıkanıklık (congestion) ya da kaza varsa, devre olmadığı için paket hemen başka yoldan gidebilir.

Dezavantajları:

- **Ek yük:** Her paketin üzerinde alıcı ve gönderici adresi vardır. Paketin başlığı sanal devreye göre daha büyüktür.
- **Sıra korunmaz:** Gönderici paketleri sıralı gönderir, ama varışları sırasız olabilir. Varılan yerde yeniden sıralanmaları gerekir.
- **Her düğümde karar gecikmesi:** Paket her düğüme geldiğinde "hangi yoldan gideyim?" diye bir duraksama olur. Hocanın benzetmesiyle: Bilecik'e geldim, sağa mı dönsem sola mı? Bolu'ya geldim, ne tarafa dönsem? Trenin ise direksiyonu bile yoktur.

### 10.3 Sanal Devrenin Avantajları ve Dezavantajları

Hoca çok yoğun veri akışında sanal devrenin daha makul olduğunu söyledi. Örnek olarak Japonya'daki hızlı trenleri verdi: Tren tek bir yoldan gider, ama 700 km/sa hızla gider ve aynı sürede daha çok insan taşır. Sürekli paket gönderiyorsanız sanal devreli bir yapı, az az veri gönderiyorsanız datagram daha mantıklıdır.

> **Ders sonrası not:** Hoca Japonya'daki trenlerin 700 km/sa hızla gittiğini söyledi. Büyük olasılıkla doğrusu şudur: Shinkansen hızlı trenlerinin işletme hızı en fazla yaklaşık 320 km/sa'tir. Manyetik raylı (maglev) deneme treninin rekoru yaklaşık 603 km/sa'tir. Benzetmenin ana fikri değişmez.

Sanal devrenin avantajları:

- Yol, paketler gönderilmeden önce kurulur. Bu hızlı gönderim açısından avantajdır.
- Paketlerde alıcı ve gönderici adresi değil, sanal devrenin bilgisi yazılıdır.
- Devre kurulduktan sonra ara düğümlerde yol değiştirilemez. Hızlı tren hattı gibi, hatta tıkanıklık ya da kaza yoksa bu bir avantajdır.
- Tek bir fiziksel hat birden fazla sanal devre için kullanılabilir.

Son madde için hoca tren hattı örneği verdi: İstanbul'dan Eskişehir'e, Eskişehir'den Ankara'ya, Ankara'dan Konya'ya giden bir hat olsun. Biri İstanbul ile Eskişehir arasında konuşurken, bir başkası Eskişehir ile Ankara ya da Eskişehir ile Konya arasında konuşabilir. Tek bir gerçek hat üzerinde birden çok sanal devre kurulur.

Hoca bunların servis kalitesi (Quality of Service, QoS) açısından önemli olduğunu söyledi. İki istasyon uzun süre veri alışverişi yapacaksa sanal devre şunlarla daha üstün başarım sağlar:

- Paket sırası korunur. Verinin kesin sıralı geleceğini bilen alıcı sıralamayla uğraşmaz.
- Her düğümde rotalama kararı alınmaz. Paket her düğümde "nereye gitsem" diye düşünmez.
- Hata denetimi ve yeniden iletim kolaydır. Datagramdaki hata denetim tekniklerine göre daha performanslı teknikler kullanılır.

Dezavantajları:

- Ağdaki sorunlara, tıkanıklıklara ve kazalara datagrama göre daha geç tepki verir. Uyum sağlar, çünkü sanal devre (hocanın anlatımıyla) oturum katmanında ya da servis sağlayıcı tarafında değiştirilebilir. Ama datagram kadar uyumlu değildir.
- İki düğüm arasındaki hatta sorun olması ile düğümün kendisinde sorun olması farklıdır. Düğüm çökerse, o düğümden geçen bütün sanal devreler aynı anda etkilenir ve hepsinin yeniden kurulması gerekir.

## 11. Datagram, SVC ve PVC Karşılaştırması

> **Hocanın vurgusu:** "Bu karşılaştırmalar önemli. Bunlardan sınavlarla falan da soruyoruz. O yüzden hani ben de böyle detaylı detaylı anlatıyorum."

Hoca üç yaklaşımı beş ölçüte göre karşılaştırdı:

| Ölçüt | Datagram | SVC | PVC |
| --- | --- | --- | --- |
| Bağlantı kurulumu | Gerek yok; paketler doğrudan gitmeye başlar | İlk paket iletimi sırasında kurulur | Bağlantıyı servis sağlayıcı kurar |
| Rota belirleme | Her düğümde, her paket için | İlk giden paket bir kez belirler | Servis sağlayıcının belirlediği rota |
| Adres bilgisi | Gönderici ve alıcı adresi taşınır | Adres yok; VCI taşınır | Adres yok; VCI taşınır |
| Paket sırası | Korunmaz | Korunur | Korunur |
| Değişen koşullara uyum | En hızlı | Orta | En yavaş |

Ölçütlerin açıklaması:

- **Rota:** SVC ve PVC'de yol üzerindeki hiçbir düğüm değiştirilemez.
- **Adres:** VCI, adres bilgisinden daha az yer kaplar. Bu da performansta bir iyileştirmedir.
- **Paket sırası:** Datagramda her paket farklı rotadan gidebildiği için sıra korunmaz.
- **Uyum:** Datagram en hızlı uyum sağlar, çünkü her paket ayrı ayrı uyum gösterebilir. SVC ikinci sıradadır; veri gönderimini bırakmadan yalnız oturumu yenileyerek (hocanın anlatımıyla) yeni bir sanal devre kurabilir. PVC en geridedir, çünkü servis sağlayıcının yeni bir rota vermesi gerekir; kullanıcının elinde başka rota yoktur.

## 12. Katmanlara Göre Ağ Cihazları

Hoca dersi ağ cihazlarına kısa bir girişle bitirdi. Ayrıntılar bir sonraki haftaya bırakıldı.

- **Fiziksel katman: tekrarlayıcı (repeater).** Sinyal zayıflaması (signal attenuation) olur. Zayıflayan sinyalin yinelenmesi gerekir.
- **Veri bağı katmanı: köprü (bridge).** Ağlar birbiriyle iletişim kurarken kullanılır.
- **Ağ katmanı: yönlendirici (router).** Hoca, datagram ve sanal devre anlatırken "düğüm" dediği şeylerin router olduğunu söyledi.
- **Taşıma, oturum, sunum ve uygulama katmanları: ağ geçidi (gateway).**

> **Ek bilgi (derste anlatılmadı):** Switch'ler genellikle veri bağı katmanında çalışan çok portlu köprüler olarak düşünülür. Ağ geçidi terimi, büyük olasılıkla farklı protokol yığınlarını kullanan ağlar arasında üst katmanlarda dönüşüm yapan cihazlar için kullanılır.

## Örnek Sorular

Bu derste kare yoktur. Aşağıdaki sorular hocanın derste sözlü olarak sorduğu ve cevapladığı sorulardır.

**Soru 1** (derste sözlü, 01:13:56-01:17:17): 3 giriş ve 4 çıkışlı bir crossbar kaç anahtar gerektirir? Yalnız crossbar kullanılsaydı Türkiye'deki 3000 uç noktanın birbirine bağlanması neden sorun olurdu?

> **Çözüm:** Her giriş-çıkış çifti için bir anahtar gerekir: $3 \times 4 = 12$. 3000 uçta her uç için 3000 anahtar gerekir; toplam $3000 \times 3000 = 9\,000\,000$ anahtar (ara adım eklendi). Bu karmaşa yüzünden çok katlı yapılar ve çoğullama kullanılır.

**Soru 2** (derste sözlü, 01:34:06): Devre anahtarlamada iki uç birbiriyle konuşurken pakette adrese gerek var mı? Datagram ve sanal devrede durum nedir?

> **Çözüm:** Devre anahtarlamada adrese gerek yoktur; bir uç doğrudan diğer uca bağlıdır. Datagramda her paket gideceği yerin adresini (alıcı ve gönderici adresi) taşır. Sanal devrede paket yalnız sanal devrenin numarasını, yani VCI'yı taşır.

**Soru 3** (derste sözlü, 01:41:00-01:42:05): Paket boyutu küçüldükçe iletim neden hızlanır? O zaman birer bitlik paketler mi gönderelim; küçültmenin durma noktası neye bağlıdır?

> **Çözüm:** Küçük paketlerde ara düğümler bir paketi iletirken bir sonrakini alabilir; iletim düğümlerde üst üste biner. 40 bayt veri, 3 bayt başlık ve 3 bağlantılı örnekte tek paket 129 birim, iki paket 92 birim sürer. Ama her paket ayrı başlık taşıdığı için paket sayısı arttıkça toplam başlık yükü artar. Belli bir boyutun altında iletim yeniden yavaşlar. Durma noktası başlığın boyutuna bağlıdır.

**Soru 4** (derste sözlü, 01:43:45): Tek hatlı bir tren yolunda kaza olursa tren başka bir yoldan gidebilir mi? Bu, bağlantı yönelimli hizmette neye karşılık gelir?

> **Çözüm:** Gidemez, çünkü tek hat vardır. Bağlantı yönelimli hizmette (sanal devre) yol baştan kurulur ve ara düğümlerde değiştirilemez. Yol bozulursa yeni bir devre kurulması gerekir. Datagramda ise arabayla gidiş gibi her kavşakta yeni yol seçilebilir.

**Soru 5** (derste sözlü, 01:55:13): Fiziksel katmanda tekrarlayıcı (repeater) neden kullanılır?

> **Çözüm:** Sinyal hatta ilerledikçe zayıflar (attenuation). Tekrarlayıcı zayıflayan sinyali yineler.

## Dersin Toparlaması

Bu derste veri bağı katmanından ağ katmanına geçildi. Geniş alan ağlarında uçları doğrudan bağlamak mümkün olmadığı için anahtarlama gerekir. Devre anahtarlama, telefon örneğinde olduğu gibi bağlantı kurma, veri iletimi ve sonlandırma aşamalarından oluşur ve iki uç arasında sanki bir kablo varmış gibi sabit bir yol ayırır. Bu yol crossbar gibi uzay bölmeli yapılarla, TSI kullanan zaman bölmeli yapılarla ya da ikisinin karmasıyla kurulur. Devre boşta kalsa bile ücret ödenir ve hat koparsa iletişim kesilir.

Patlamalı veri trafiği için paket anahtarlama geliştirilmiştir. Datagramda her paket adres taşır ve her düğümde ayrı yönlendirilir; paketler sırasız varabilir, ama arızalara en hızlı uyum sağlayan yöntem budur. Sanal devrede yol baştan kurulur, paketler yalnız VCI taşır ve sıralı gider. SVC'de yol her iletişimde kurulur, PVC'de servis sağlayıcı tarafından kalıcı olarak tanımlanır. Paket boyutunu küçültmek iletimi bir noktaya kadar hızlandırır, sonra başlık yükü yüzünden yavaşlatır. Bir sonraki hafta repeater, bridge, router ve gateway gibi ağ cihazları ayrıntılı anlatılacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
