# Ders 12 Çalışma Özeti

## Genel Konular

- İnternette ağ katmanının genel görünümü (ekrandan, 00:05:00)
  - Slayttaki tanım: İnternet, IP protokolüyle bir arada tutulan, birbirine bağlı çok sayıda ağın topluluğudur.
  - Şekilde bir ABD omurgası (backbone) ve bir Avrupa omurgası, Asya'ya giden kiralık hatlar ve Atlantik ötesi kiralık hatlar, bölgesel ağ (regional network), mobil ağ (WiMAX ile bağlanan dizüstü bilgisayar), ulusal ağ (national network), şirket ağı (company network, Ethernet) ve kabloyla bağlanan ev ağı (home network) yer alır.
  - Omurgadaki bağlantılar daha kalın çizilmiştir: trafik uç noktalardan toplanarak yukarıya, omurgaya doğru akar ve dünyanın bir noktasından diğerine omurga üzerinden taşınır.
  - Evlerde "ADSL router" denen cihazlar aslında bir uç bağlantı noktasıdır. Gidilecek tek bir yer olduğu için statik yönlendirme yapar; hesaplanacak bir yönlendirme kararı yoktur. Birden fazla bağlantı varsa aralarındaki seçim ya üçüncü bir cihazla ya da elle yapılır. Şirket ağlarında ise farklı kampüs ve bölgeler nedeniyle yapı daha geneldir.
- IPv4 başlığı (ekrandan, 00:20:00)
  - Başlık 32 bitlik satırlardan oluşur: 5 sabit satır (20 bayt) ve 0 ya da daha fazla 32 bitlik kelimeden oluşan değişken uzunlukta Options alanı.
  - Alanlar sırasıyla: Version (4 bit), IHL (4 bit), Differentiated Services (8 bit), Total length (16 bit); Identification (16 bit), ayrılmış bit, DF, MF, Fragment offset (13 bit); Time to live (8 bit), Protocol (8 bit), Header checksum (16 bit); Source address (32 bit); Destination address (32 bit); Options.
  - Version: 4 bit olduğu için 0-15 arası 16 farklı değer alabilir. Kullanımda olan sürümler 4 ve 6'dır.
  - IHL (Internet Header Length): 4 bit, en çok 15; birimi 32 bitlik kelimedir. Başlık en çok $15 \times 4 = 60$ bayt olabilir; 20 bayt sabit, 40 bayt seçeneklere ayrılmıştır. IHL = 5 ise seçenek yoktur, 6 ise bir kelime, 7 ise iki kelime seçenek vardır; en çok $15 - 5 = 10$ kelime.
  - Differentiated Services: başlangıçta Type of Service olarak tanımlanmıştı. İlk 6 bit paketin servis sınıfını (QoS konusundaki expedited ve assured forwarding) belirtir, son 2 bit ek bir kontrol mekanizması içindir.
  - Total length: 16 bit, bayt cinsinden başlık + seçenekler + veri; en çok 65535 bayt.
  - Identification, DF (Don't Fragment), MF (More Fragments) ve Fragment offset parçalamayı (fragmentation) yönetir.
  - Time to live: başlangıçta saniye cinsinden tanımlanmıştı (en çok 255 s). Saniye tutmak hem işlem yükü getirdiği hem de yönlendiriciler arasında kusursuz saat eşzamanlaması sağlanamadığı için alan atlama (hop) sayısına dönüştürüldü. Her yönlendiricide bir azaltılır, sıfıra inince paket atılır.
  - Protocol: 8 bit; IP'nin taşıdığı üst protokolü belirtir (256 farklı değer). IP'nin kendisinin de bir protokol numarası vardır.
  - Header checksum: yalnız başlığın doğruluğunu korur, verinin değil. Başlıkta bir alan değişince (her atlamada TTL değiştiği için) yeniden hesaplanması gerekir.
  - Source address ve Destination address: her biri 32 bit; mektuptaki gönderen ve alıcı gibi her IP paketinde mutlaka bulunur.
- Bayt sırası: big endian ve little endian
  - IP, 32 bitlik SPARC işlemcili ve SunOS çalıştıran makinelerde geliştirildi. SPARC big endian olduğu için TCP/IP'de her şey big endian üzerine kuruludur.
  - Bu yüzden "network byte order" her zaman big endian'dır; "host byte order" ise işlemciye göre değişir. Bugün en yaygın olan Intel işlemciler little endian olduğu için her paket alanında dönüşüm gerekir. Bu dönüşümler hızlı olsun diye fonksiyon değil makro olarak gerçeklenmiştir.
- Parçalama alanları
  - Farklı veri bağı özelliklerine (farklı çerçeve boyutlarına) sahip ağlardan geçen bir paket, daha küçük çerçeveye sığmazsa parçalanır.
  - Identification: aynı özgün pakete ait parçaları tanımlar; bütün parçalar aynı değeri taşır.
  - DF: kaynaktan hedefe kadar parçalama istenmediğini bildirir. Yoldaki bir ağ paketi taşıyamazsa göndericiye hata mesajı döner ve gönderici kendini ona göre ayarlar.
  - MF: sonuncusu dışındaki bütün parçalarda 1'dir; sonuncuda 0 olduğu için son parçanın geldiği anlaşılır.
  - Fragment offset: 16 bitten 3 bayrak biti çıkınca 13 bit kalır; parçanın özgün paketteki yerini gösterir.
- IPv4 seçenekleri (Options)
  - Seçenek alanı 32 bitlik sınırlara tamamlanır; tek baytlık bir seçenek bile 4 bayta doldurulur.
  - Protokole ek özellik kazandırmak, deneme yapmak ve yeni sürümlere geçişi kolaylaştırmak için tasarlandı.
  - Beş seçenek: Security (paketin gizlilik düzeyini işaretler; ama hassas paketi işaretleyip hedef haline getirdiği için güvenlik açısından mantıklı değildir), Strict source routing (yoldaki bütün yönlendiriciler tek tek verilir), Loose source routing (geçilmesi istenen yönlendiriciler verilir, arada başkalarından da geçilebilir), Record route (geçilen yönlendiriciler kaydedilir) ve Timestamp (yönlendirici adresiyle birlikte zaman damgası eklenir).
  - 40 baytlık seçenek alanına en çok 10, seçenek başlığıyla birlikte yaklaşık 9 adres sığar. Bugünkü İnternette yollar bundan çok uzun olduğu için Record route ve Timestamp pratikte anlamlı değildir.
- Sınıflı adresleme (classful addressing) (ekrandan, 00:50:00)
  - Eski adresler sabit boyutlu bloklar (A, B, C) halinde dağıtılıyordu; blok boyutu adresin içinde taşınıyordu ama esneklik yoktu.
  - A sınıfı: ilk bit 0, 7 bit ağ, 24 bit host; 1.0.0.0-127.255.255.255.
  - B sınıfı: ilk bitler 10, 14 bit ağ, 16 bit host; 128.0.0.0-191.255.255.255.
  - C sınıfı: ilk bitler 110, 21 bit ağ, 8 bit host; 192.0.0.0-223.255.255.255.
  - D sınıfı: ilk bitler 1110, çok noktaya yayın (multicast); 224.0.0.0-239.255.255.255. Ağdaki yazıcıların bir çok noktaya yayın adres bölgesine gelen sorgulara cevap vermesi ve böylece işletim sisteminin yazıcıyı adresini bilmeden bulması buna örnektir.
  - E sınıfı: ilk bitler 1111, gelecekte kullanım için ayrılmış; 240.0.0.0-255.255.255.255.
  - Tasarım yalnız ABD düşünülerek yapıldı; İnternet bütün dünyaya yayılınca bu sabit bloklar anlamını yitirdi ve sınıfsız (classless) kullanıma geçildi.
- Önekler (prefixes) ve alt ağ maskesi (ekrandan, 00:45:00)
  - Adresler önek denen bloklar halinde dağıtılır; önek, adresin ağ kısmıdır. Yazılış adres/uzunluk biçimindedir, örnek: 18.0.31.0/24.
  - 32 bitin ilk L biti önek (ağ), kalan $32 - L$ biti hosttur.
  - Alt ağ maskesinde önek bitleri kesintisiz 1, host bitleri 0'dır. 1'lerin arasına 0 giremez, çünkü adres maskeyle VE (AND) işlemine sokularak ağ kısmı ayrılır.
- Alt ağlara bölme (subnetting)
  - Bir kuruma /16 önekiyle adres verildiyse ilk 16 bite dokunamaz, ama kalan 16 host bitini kendi içinde alt ağ ve host olarak yeniden bölebilir.
  - Alt ağın önek uzunluğu, kuruma gelen önekten büyük olmak zorundadır.
  - Derste bir üniversite örneğinde bir bölüme /18, bir bölüme /17, sanat bölümüne /19 ayrıldı; önek ne kadar uzunsa host kısmı o kadar küçüktür. <!-- BELİRSİZ: alt ağ slaytı karelerde yok; adres değerleri doğrulanamadı -->
- Birleştirme (aggregation) (ekrandan, 01:00:00)
  - Birden fazla IP öneki tek bir büyük önekte birleştirilerek yönlendirme tablosunun boyutu küçültülür.
  - Örnek: Londra'daki ISS, Cambridge'e 192.24.0.0/21, Oxford'a 192.24.16.0/20, Edinburgh'a 192.24.8.0/22 vermiştir; New York'a ise tek bir birleşik önek, 192.24.0.0/19 duyurur.
  - Bu hem yönlendirme tablosunun belleğini hem arama süresini azaltır; adres sorarken önce şehri, sonra mahalleyi sormak gibidir.
- En uzun önek eşleşmesi (longest matching prefix)
  - Bir adres birden fazla girdiye uyuyorsa en uzun öneke (en küçük bloğa) uyan girdiye göre yönlendirilir. Londra'daki yönlendirici /19 yerine /20, /21, /22 girdilerinden hangisi uyuyorsa paketi oraya gönderir.
  - Karşılaştırma kodunu biraz karmaşıklaştırır ama adreslerin hiyerarşik olarak bölünmesini ve birleştirilmesini sorunsuz kılar.
- NAT ve PAT (ekrandan, 01:05:00)
  - IPv4'ün en büyük sorunu 32 bitlik (yaklaşık 4 milyar) adres alanının dünyadaki bağlanma ihtiyacına yetmemesidir.
  - Klasik NAT: İnternete bakan yönlendiricideki gerçek adres havuzundan, içeriden çıkan her bağlantıya o an boşta olan bir adres eşlenir. İçeride, dışarıda başka yerlerde kullanılan adresler serbestçe yeniden kullanılabilir; ama dışarıda bir adres bloğu sürekli bağlı kalır.
  - PAT (port address translation): Uygulamalar dışarı bir taşıma katmanı protokolüyle (TCP, UDP vb.) çıktığı için port numarası da kullanılır. Port 16 bittir; bir adres $2^{16}$ farklı uygulama bağlantısını ayırt edebilir. Bugün endüstri bu yönteme kısaca NAT der.
  - Slayttaki örnek: içerideki paket IP = 10.0.0.1, port = 5544; NAT kutusundan (NAT box/firewall) sonra IP = 198.60.42.12, port = 3344. Yönlendirici bu eşlemeyi tablosunda tutar, dönen cevabı geri çevirir.
  - Benzetme: dışarıya tek hattı olup içeride dahili numaralar dağıtan telefon santrali.
  - NAT katmanlamayı çiğner: taşıma katmanına ait port bilgisi ağ katmanının işi için kullanılır. Yine de evlerde ve kurumlarda çok yaygındır.
  - Yalnız iç ağlarda kullanılacak adres blokları (10, 172.16 ve 192.168 ile başlayanlar) üreticilerce İnternette yönlendirilmez; ülkeler arası yönlendiriciler bu adresleri taşımaz.
- IPv6 (ekrandan, 01:20:00 ve 01:25:00)
  - Hedefler: 4 milyardan çok daha fazla hostu desteklemek, yönlendirme tablolarını küçültmek, güvenliği protokolün doğal bir parçası yapmak, hizmet türü (QoS) desteğini düzenlemek, adres değişmeden mobil dolaşımı (roaming) desteklemek ve IPv4 ile bir arada yaşayabilmek.
  - Başlık 128 bitlik adresleriyle daha uzun ama daha basittir: Version, Diff. Serv., Flow label; Payload length, Next header, Hop limit; 16 baytlık Source address ve 16 baytlık Destination address.
  - Flow label ile akışlar birbirinden ayırt edilir; ancak bunun bütün dünyadaki yönlendiricilerde tanımlı olması gerekir.
  - Diğer işlevler uzantı başlıklarıyla (extension headers) sağlanır: Hop-by-hop options, Destination options, Routing (gevşek yönlendirici listesi), Fragmentation, Authentication, Encrypted security payload.
  - Jumbo paketler: IPv4'ün 65535 baytlık sınırını aşan büyük paketlere izin verir; veri merkezlerindeki 40-100 Gbit/s hızların doyurulması için önemlidir.
  - Geçiş, adres sıkıntısı NAT ile çözüldüğü için yavaş ve sancılı ilerlemektedir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Network byte order her zaman big endian'dır
  - IP big endian bir işlemcide tasarlandığı için bugün kullanılan little endian işlemcilerin neredeyse hepsi her pakette dönüşüm yapmak zorundadır. Hocalar bunun üzerine özellikle bastırdı.
- Header checksum çok önemlidir
  - Yalnız başlığı korur; her atlamada TTL azaldığı için her yönlendiricide yeniden hesaplanır.
- En iyisi parçalamanın hiç olmamasıdır
  - DF biti bunu sağlamak için vardır: paket parçalanmadan geçemiyorsa göndericiye hata döner.
- En uzun önek eşleşmesini unutmayın
  - Adresleri hiyerarşik olarak bölmenin ve birleştirmenin dayandığı temel kuraldır.
- NAT katmanlamaya aykırıdır
  - Taşıma katmanının port bilgisini ağ katmanında kullanır; "çok yanlış ama çok yaygın" bir yaklaşımdır.

## Kısa Tekrar Notları

- IPv4 başlığı: 20 bayt sabit + en çok 40 bayt seçenek = en çok 60 bayt.
- Version 4 bit, IHL 4 bit (birim 32 bitlik kelime), DS 8 bit, Total length 16 bit (en çok 65535 bayt).
- Identification 16 bit, DF ve MF bayrakları, Fragment offset 13 bit.
- TTL 8 bit, bugün atlama sayısı; Protocol 8 bit; Header checksum 16 bit, yalnız başlık için.
- Kaynak ve hedef adresler 32 bit.
- Seçenekler: Security, Strict source routing, Loose source routing, Record route, Timestamp.
- Sınıflar: A (0), B (10), C (110), D (1110, multicast), E (1111, ayrılmış).
- Önek gösterimi: adres/uzunluk; maskede önek bitleri kesintisiz 1.
- Alt ağ öneki, kuruma verilen önekten uzundur.
- Birleştirme: 192.24.0.0/21, /20, /22 parçaları dışarıya 192.24.0.0/19 olarak duyurulur.
- Yönlendirme en uzun önek eşleşmesine göre yapılır.
- PAT: iç adres:port ile dış adres:port eşlenir (10.0.0.1:5544 → 198.60.42.12:3344).
- IPv6: 128 bitlik adres, sade başlık, uzantı başlıkları, flow label, jumbo paketler.

## Detaylı Açıklamalar

- IPv4 başlığının boyutu ve IHL
  - Başlığın ilk beş satırı her pakette bulunur; her satır 32 bit (4 bayt) olduğu için sabit kısım 20 bayttır. IHL alanı 4 bit olduğundan en çok 15 değerini alabilir. Bu değer bayt değil 32 bitlik kelime sayısıdır, dolayısıyla başlık en çok 60 bayt olabilir. 20 bayt sabit kısım çıkınca seçeneklere 40 bayt kalır. IHL'nin 5 olması hiç seçenek olmadığını, 6 olması bir kelimelik, 7 olması iki kelimelik seçenek olduğunu gösterir.
- Toplam uzunluk ve taşınabilecek veri
  - Total length başlık, seçenekler ve veri dahil paketin bütün uzunluğunu bayt cinsinden verir ve 16 bit olduğu için 65535'i geçemez. Buna göre bir IP paketinin taşıyabileceği veri, seçenek yoksa en çok $65535 - 20 = 65515$ bayt, başlık 60 bayt olduğunda $65535 - 60 = 65475$ bayttır.
  - > **Ders sonrası not:** Altyazıda bu hesap karışık aktarılmış ("minimum da 65535-60"); doğru ifade yukarıdaki gibidir: en büyük veri miktarı başlık boyutuna göre 65475 ile 65515 bayt arasında değişir.
- Bayt sırası dönüşümü
  - Big endian bir işlemcide bir değerin en anlamlı baytı en düşük adreste durur; bellek görüntüsü kağıda yazılan sayıyla aynıdır. Little endian'da ise tersidir. Bit düzeyinde işlem yapılan protokol alanlarında karışıklık olmasın diye ağ üzerindeki sıra (network byte order) big endian olarak sabitlenmiş, her makine kendi sırasıyla (host byte order) bu sıra arasında dönüşüm yapar. Dönüşüm bayt yer değiştirme ve kaydırma işlemleri gerektirdiğinden, çağrı maliyeti olmasın diye makro olarak gerçeklenir.
- Parçalama ve DF/MF
  - Paket bir ağdan diğerine geçerken çerçeve boyutu küçülürse parçalara bölünür; ikiye değil beşe, ona, yirmiye de bölünebilir. Bütün parçalar aynı Identification değerini taşır, sonuncusu hariç hepsinde MF biti 1'dir. Her parçanın özgün paketteki yeri Fragment offset ile belirtilir. Hocalar daha önceki derslerde konuşulan sonucu hatırlattı: en iyisi hiç parçalanmamaktır. Her yerde aynı teknoloji kullanılamayacağına göre çözüm DF bitidir.
  - > **Ders sonrası not:** Derste Fragment offset'in bayt cinsinden olduğu söylendi; doğrusu 8 baytlık birimler cinsindendir. 13 bitlik alan $2^{13} \times 8 = 65536$ baytlık bir paketin her yerini gösterebilir.
- TTL
  - Paket her yönlendiriciden geçerken TTL bir azaltılır, sıfıra inince paket atılır; böylece döngüye giren paketler ağda sonsuza kadar dolaşmaz. 8 bitlik alan en çok 255 olabildiği için bir paket en çok 255 atlama yol alabilir.
  - > **Ders sonrası not:** Derste TTL'in 255 ile başladığı söylendi; başlangıç değerini gönderici belirler, büyük olasılıkla işletim sistemine göre 64, 128 ya da 255 gibi değerler kullanılır. 255 yalnız üst sınırdır.
- Header checksum
  - Checksum yalnız yönlendirme için gereken başlık alanlarının doğruluğunu garanti eder. Hoca hesabı "16 bitlik değerleri sırayla işleme sokup en sonunda tekrar işleme sokmak; alıcı aynı işlemi yapınca 0 çıkıyorsa hata yoktur" diye anlattı. Başlıkta herhangi bir alan, en basitinden TTL, değiştiğinde checksum yeniden hesaplanmalıdır.
  - > **Ders sonrası not:** Derste işlem XOR olarak anlatıldı; IPv4 başlık sağlama toplamı XOR değil, 16 bitlik kelimelerin birler tümleyeni (one's complement) toplamının tümleyenidir. Alıcı aynı toplamı checksum dahil hesaplayınca sonuç tümüyle 1 olur (tümleyeni 0).
- Seçenekler ve kısıtları
  - 40 baytlık seçenek alanında 4 baytlık adreslerden en çok 10 tane, seçeneğin kendi başlık baytlarıyla birlikte 9 civarı sığar. İlk tasarımda İnternetin düğüm sayısı çok azdı, bu sınır yeterliydi; bugün bir üniversiteye ulaşmak için bile bundan fazla yönlendiriciden geçildiği için Record route ve Timestamp seçenekleri pratikte işe yaramaz. Derste günümüzde fiilen kullanılanın yalnız ping ve traceroute gibi ölçüm araçlarıyla ilişkili kullanım olduğu da söylendi.
- Sınıflı adreslemedeki sayılar
  - A sınıfında ilk bit 0 olduğu için ağ kısmında 7 bit kalır: $2^7 = 128$ ağ. B sınıfında $2^{14} = 16384$ ağ ve her birinde $2^{16} = 65536$ adres vardır. C sınıfında ilk üç bit 110 olduğu için $2^{21} = 2097152$ ağ ve her birinde $2^8 = 256$ adres vardır. Tasarım mantığı şuydu: birkaç yüz büyük kurum A sınıfı, orta ölçekli kurumlar B sınıfı, küçük kurumlar C sınıfı alacaktı.
  - > **Ders sonrası not:** Derste A sınıfı bir ağda "1 milyon host" olduğu söylendi; 24 bitlik host kısmı $2^{24} = 16777216$ adres verir, yani yaklaşık 16,7 milyon.
- Birleştirme örneğinin doğrulanması
  - 192.24.0.0/19 bloğu 192.24.0.0-192.24.31.255 aralığını kapsar. Cambridge'in /21 bloğu 192.24.0.0-192.24.7.255, Edinburgh'un /22 bloğu 192.24.8.0-192.24.11.255, Oxford'un /20 bloğu 192.24.16.0-192.24.31.255 aralığındadır; üçü de /19 bloğunun içindedir (python ile kontrol edildi).
- NAT ile PAT farkı
  - Derste verilen örnekte (gerçek bir kurum ayrıntısı değil, açıklama amaçlı) dış bacakta 5 tane C sınıfı blok olduğu düşünüldü; bu durumda içeriden aynı anda dışarı çıkabilecek bağlantı sayısı bu havuzdaki adres sayısı kadardır ve her çıkış bir dış adresi bağlar. PAT'ta ise dış adresle birlikte bir port ayrıldığı için tek bir dış adres binlerce iç bağlantıyı taşıyabilir.
  - > **Ders sonrası not:** Derste 5 C sınıfı blok için "1250 adres" denildi; 5 × 256 = 1280 adres, kullanılabilir host olarak 5 × 254 = 1270 adres eder.
- IPv6'nın yavaş benimsenmesi
  - IPv6'ya geçiş için birçok kez tarih konuldu ve ertelendi. Adres sıkıntısı NAT ile geçici olarak çözülebildiği sürece kimse geçişin riskini almak istemedi; NAT ise kendi güvenlik açıklarını ve sorunlarını getirdi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
