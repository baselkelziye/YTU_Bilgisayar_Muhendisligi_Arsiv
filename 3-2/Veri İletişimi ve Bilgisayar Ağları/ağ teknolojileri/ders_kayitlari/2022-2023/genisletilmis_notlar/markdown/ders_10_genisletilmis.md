# Ders 10 Genişletilmiş Notu: Ağ Katmanı: Veri Düzlemi, Yönlendirici Mimarisi ve IP Adresleme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Ağ Katmanına Giriş
- 2. İletme ve Yönlendirme
- 3. Veri Düzlemi ve Kontrol Düzlemi
- 4. Ağ Katmanı Hizmet Modeli
- 5. Yönlendirici Mimarisi ve Giriş Portu
- 6. Hedefe Dayalı İletme ve En Uzun Önek Eşleştirme
- 7. Anahtarlama Dokusu
- 8. Giriş ve Çıkış Portu Kuyruklaması
- 9. Tampon Boyutu, Tampon Yönetimi ve Paket Zamanlaması
- 10. Ağ Tarafsızlığı
- 11. IP: Ağ Katmanının Bileşenleri ve IPv4 Datagram Biçimi
- 12. IPv4 Adresleme, Alt Ağlar ve CIDR
- 13. DHCP
- 14. Hiyerarşik Adresleme ve Adres Bloklarının Dağıtımı
- Örnek Sorular

## 1. Ağ Katmanına Giriş

Ders, TCP/IP katmanlarına göre ilerleyen planın devamıydı: uygulama katmanı ve taşıma katmanı bitmiş, sıra ağ katmanına gelmişti. Hoca ağ katmanını ağın çekirdeği olarak tanımladı. İnternet "ağların ağı"dır ve bu ağları birbirine bağlayan katman ağ katmanıdır; bu yüzden ağdaki her cihaz bu katmanda çalışmak zorundadır. Ağ katmanının asıl işi yönlendiricilerde ve çekirdek cihazlarda yapılır.

Konu çok geniş ve ayrıntılı olduğu için yöntemine göre iki parçaya ayrılır: veri düzlemi (data plane) ve kontrol düzlemi (control plane). Bu dersin hedefleri şunlardı: ağ katmanı hizmetlerini anlamak, iletme (forwarding) ile yönlendirme (routing) arasındaki farkı görmek, bir yönlendiricinin içinde neler olduğunu ve hedefin nasıl bulunduğunu incelemek, ardından internetteki uygulamaya, yani IP protokolüne geçmek. Bu çerçevede NAT ve ara kutular (middlebox) gibi konular da başlık olarak anıldı.

### 1.1 Ağ katmanının hizmeti

Hoca, önceki bölümlerden tanıdık olan ağ resmini yeniden gösterdi (ekrandan, 00:15:00): mobil ağ, ev ağı, ulusal ya da küresel ISP, veri merkezi ağı ve kurumsal ağ. Bu cihazların bir kısmı hücresel ağla, bir kısmı erişim noktalarıyla, bir kısmı kablolu bağlantılarla bağlıdır. Örnek senaryoda evdeki dizüstü bilgisayar kurumsal ağdaki bir web sunucusuna ulaşmak ister.

Gönderici taraf taşıma katmanından gelen segmentleri datagramlara kapsüller, sonra datagram bağlantı katmanına iner. Alıcı taraf segmentleri taşıma katmanına teslim eder; taşıma katmanı da port numarasına bakarak segmenti ilgili uygulamaya iletir. Gönderici ile alıcı arasında doğrudan bir bağlantı yoktur. Ağ katmanı protokolleri uç cihazlar dahil her internet cihazında, yani ana bilgisayarlarda ve yönlendiricilerde çalışmalıdır.

Yönlendirici, içinden geçen bütün IP datagramlarının başlık alanlarını inceler. Bir giriş portuna gelen datagramı iletme tablosuna (forwarding table) göre uygun çıkış portuna yönlendirir. Böylece datagram uçtan uca yol boyunca ilerler. Hoca bunu "hedefe ulaşmak için doğru yolu bulmaya çalışmak" diye özetledi.

## 2. İletme ve Yönlendirme

Ağ katmanının iki temel işlevi vardır (ekrandan, 00:20:00).

- **İletme (forwarding):** paketleri bir yönlendiricinin giriş bağlantısından aynı yönlendiricinin uygun çıkış bağlantısına taşımak. Burada tek bir yönlendiriciden söz edilir; iletme tek yönlendiricinin içinde olur.
- **Yönlendirme (routing):** paketlerin kaynaktan hedefe izleyeceği yolu belirlemek. Bunun için kaynak ile hedef arasındaki doğru yolu bulan bir algoritma, yani yönlendirme algoritması gerekir.

Hoca farkı bir yolculuk benzetmesiyle anlattı. İstanbul'dan Erzurum'a uzun bir yolculuğa çıktığınızı düşünün. Yolculuğun tamamını, hangi yoldan gideceğinizi planlamak navigasyon gibidir; bu yönlendirmedir. Yol üzerindeki her şehirden geçerken kavşaklardan, dönel kavşaklardan doğru çıkışı almanız ise iletmedir. İletme her bir şehirde ya da kasabada yerel olarak yapılır; yönlendirme İstanbul'dan Erzurum'a tüm güzergâhı belirler.

## 3. Veri Düzlemi ve Kontrol Düzlemi

### 3.1 Veri düzlemi

İletme tek bir yönlendiricide olduğu için veri düzlemi yereldir; yönlendirici başına bir işlevdir. Bir yönlendiricinin giriş portlarından birine bir datagram geldiğinde yönlendirici başlık değerine bakar ve datagramı hangi çıkış portuna göndereceğine karar verir.

### 3.2 Kontrol düzlemi

Kontrol düzlemi ağ genelinde bir mantıktır. Kaynaktan hedefe büyük bir yönlendirme planıdır: datagramın uçtan uca yol üzerinde yönlendiriciler arasında nasıl yönlendirileceğini belirler. Ağ genelinde düşünen iki kontrol düzlemi yaklaşımı vardır:

- Geleneksel yönlendirme algoritmaları: yönlendiricilerin içinde çalışır.
- Yazılım tanımlı ağ (software-defined networking, SDN): daha yeni yaklaşımdır, uzak sunucularda çalışır.

### 3.3 Yönlendirici başına kontrol düzlemi

Geleneksel yaklaşımda her yönlendiricide ayrı bir yönlendirme algoritması bileşeni çalışır ve bu bileşenler kontrol düzleminde birbirleriyle etkileşir (ekrandan, 00:25:00). Her yönlendiricinin yerel bir iletme tablosu vardır. Slayttaki tablo 4 bitlik başlık değerlerini çıkış portlarına eşler:

| Başlık | Çıkış |
|---|---|
| `0100` | 3 |
| `0110` | 2 |
| `0111` | 2 |
| `1001` | 1 |

Gelen paketin başlığındaki değer `0111`'dir. Tabloda üçüncü satır `0111` → 2 olduğu için paket 2 numaralı çıkış portuna gönderilir (ekrandan, 00:25:00).

> **Ders sonrası not:** Hoca tablonun son satırını "0101, port 1" diye okudu; slaytta bu satır `1001` → 1'dir (ekrandan, 00:25:00).

Kaynaktan hedefe doğru yolu bulmak için geleneksel yaklaşımda her yönlendirici yönlendirme algoritmasını çalıştırır ve yerel iletme tablosunu günceller. Ayrıca yönlendiriciler, kullanılan yönlendirme algoritmasının kurallarına göre tablo bilgilerini birbirleriyle paylaşır ve aldıkları mesajlara göre tablolarını günceller. Slayttaki kesikli çizginin altı, yani gelen her datagramın iletilmesi veri düzlemidir; üstteki yönlendirme algoritması kontrol düzlemidir.

### 3.4 Yazılım tanımlı kontrol düzlemi (SDN)

SDN'de de bir datagram yönlendiricilerden birine gelir ve veri düzlemi aynı şekilde çalışır. Fark, kontrol düzlemindedir: yönlendiricilerde yönlendirme algoritması çalışmaz. Üstte uzak denetleyiciler (remote controller) vardır. Her yönlendiricide bir kontrol ajanı (control agent) bulunur; bu ajan uzak denetleyiciyle konuşarak yönlendiricinin iletme tablosunu günceller. Her yönlendiricide olan biten yine veri düzlemi, üstteki yönetim mekanizması kontrol düzlemidir. Geleneksel yönlendirme ile SDN arasındaki temel fark budur.

## 4. Ağ Katmanı Hizmet Modeli

Göndericiden alıcıya datagram taşıyan "kanal" için hangi hizmet modeli olabilir? Hoca olası hizmetleri saydı:

- Garantili teslim.
- Belirli bir gecikmenin altında garantili teslim.
- Sıralı teslim garantisi.
- Akış için garantili en düşük bant genişliği.
- Paketler arası aralıktaki değişime sınır konması.

İnternetin ağ katmanı modeli ise "en iyi çaba" (best effort) hizmetidir:

- Datagramın hedefe başarıyla teslim edileceğine dair garanti yoktur.
- Teslimin zamanlamasına ya da sırasına dair garanti yoktur.
- Uçtan uca akış için kullanılabilir bant genişliğine dair garanti yoktur.

O halde video akışı, video konferans, IP üzerinden ses gibi uygulamalar böyle bir ağda nasıl çalışıyor? Hoca hatırlattı: TCP, güvenilir olmayan bu hizmetin üzerinde güvenilir bir hizmet sağlar.

### 4.1 Hizmet modellerinin karşılaştırılması

Slayttaki tablo, farklı ağ mimarilerinin hizmet kalitesi (QoS) garantilerini karşılaştırır (ekrandan, 00:30:00):

| Ağ mimarisi | Hizmet modeli | Bant genişliği | Kayıp | Sıra | Zamanlama |
|---|---|---|---|---|---|
| Internet | best effort | none | no | no | no |
| ATM | Constant Bit Rate | Constant rate | yes | yes | yes |
| ATM | Available Bit Rate | Guaranteed min | no | yes | no |
| Internet | Intserv Guaranteed (RFC 1633) | yes | yes | yes | yes |
| Internet | Diffserv (RFC 2475) | possible | possibly | possibly | no |

Hoca satırları şöyle yorumladı. İnternet best effort olduğu için hiçbir garanti vermez. ATM'nin sabit bit hızı (CBR) modeli sabit hız verir; kaynak bu akışa ayrıldığı için paket kaybı olmaz, teslim sıralıdır ve sabit hız sayesinde zamanlama da garantilidir. ATM'nin kullanılabilir bit hızı (ABR) modeli yalnız en düşük hızı garanti eder; bazı paketler kaybolabilir ve zamanlama garantisi yoktur, ama ATM bağlantısı ayrılmış olduğundan teslim sıralıdır. Intserv Guaranteed bir zamanlar RFC 1633 ile yayımlanmış kuramsal bir modeldir ve dört garantinin hepsini verir. Diffserv de bir RFC ile tanımlanmıştır.

> **Ders sonrası not:** Hoca Diffserv için "RFC 2470" dedi; slaytta RFC 2475 yazıyor (ekrandan, 00:30:00).

Bu modeller yaygınlaşmadı; hâlâ best effort ağ kullanılıyor.

### 4.2 Best effort neden bu kadar yaygın?

Hoca best effort modelinin başarısını üç nedene bağladı. Bu kısmın bir bölümü altyazıda bozuk çıktı.

- <!-- BELİRSİZ: birinci neden altyazıda okunmuyor (00:31:15-00:31:53); ders kitabında büyük olasılıkla mekanizmanın basitliğidir. --> Birinci neden altyazıda net değildir.
- Normal koşullarda paket kaybı yoktur; yeterli bant genişliği sağlandığında etkileşimli ses ve video gibi gerçek zamanlı uygulamaların başarımı "yeterince iyi" olur.
- <!-- BELİRSİZ: üçüncü nedenin başı altyazıda bozuk (00:32:08-00:32:36). --> Tıkanıklık denetimi mekanizmaları ve hizmetler de yardımcı olur.

Bu nedenlerle best effort hizmet modelinin başarısıyla tartışmak zordur.

## 5. Yönlendirici Mimarisi ve Giriş Portu

### 5.1 Genel mimari

Veri düzleminde önce bir yönlendiricinin içinde ne olduğu incelendi (ekrandan, 00:35:00). Genel bir yönlendiricide şunlar bulunur:

- Solda N tane giriş portu. Slayttaki farklı renkli kutular farklı datagramları gösterir.
- Sağda N tane çıkış portu.
- Arada, gelen datagramları ilgili çıkış portuna yönlendiren yüksek hızlı anahtarlama dokusu (high-speed switching fabric).
- Yönlendirme algoritmasını çalıştıran yönlendirme işlemcisi (routing processor).

Kesikli çizginin altı iletme/veri düzlemidir; donanımda çalışır ve nanosaniye mertebesinde işler. Hoca bunun yüksek hızlı anahtarlama teknolojisi sayesinde tek saat çevriminde yapıldığını söyledi. Çizginin üstü yönlendirme ve yönetim, yani kontrol düzlemidir; tamamen yazılımdır, yönlendirme işlemcisinde çalışır ve milisaniye mertebesinde işler.

### 5.2 Giriş portu işlevleri

Yönlendiricinin her portu bir fiziksel kabloya (fiber, bakır) ya da kablosuz ortama bağlıdır. Giriş portunda sırasıyla şunlar olur:

- Hat sonlandırma (line termination): sinyal bit düzeyinde gelir; bu fiziksel katmandır.
- Bağlantı katmanı protokolü: ör. Ethernet. Bu konu dönemin sonunda 6. bölümde işlenecek.
- Ağ katmanı kısmı: arama (lookup), iletme ve çok sayıda datagram geldiği için kuyruklama.

Merkezi olmayan anahtarlamada (decentralized switching) başlık alanı değeri ve arama tablosu kullanılarak datagramın gideceği çıkış portu bulunur. Hoca bunu "eşleştir + eylem" (match plus action) diye özetledi: başlık değeri alınır, arama tablosuna bakılır ve eşleşme varsa datagram çıkış portuna iletilir.

Hedef, giriş portu işlemini hat hızında (line speed) tamamlamaktır. Hat hızı şudur: datagram hangi hızda geliyorsa o hızda doğrudan çıkışa iletilmelidir, yani işlem gerçek zamanlı ya da ona çok yakın olmalıdır. Bu her zaman mümkün değildir. Datagramlar anahtarlama dokusuna iletilebilecekleri hızdan daha hızlı gelirse tampona alınmalı ve kuyruğa konmalıdır.

İki iletme türü vardır:

- **Hedefe dayalı iletme (destination-based forwarding):** yalnız hedef IP adresine göre iletir.
- **Genelleştirilmiş iletme (generalized forwarding):** herhangi bir başlık alanı değerine bakarak iletir.

## 6. Hedefe Dayalı İletme ve En Uzun Önek Eşleştirme

### 6.1 Adres aralıklarıyla iletme tablosu

Hoca hedefe dayalı iletmeyi bir iletme tablosuyla gösterdi (ekrandan, 00:40:00). Tablo, ağın birçok parçaya bölündüğü varsayımıyla hedef adres aralıklarını bağlantı arayüzlerine eşler:

| Hedef adres aralığı | Arayüz |
|---|---|
| `11001000 00010111 00010000 00000000` ile `11001000 00010111 00010111 11111111` arası | 0 |
| `11001000 00010111 00010000 00000100` ile `11001000 00010111 00010000 00000111` arası | 3 |
| `11001000 00010111 00011000 00000000` ile `11001000 00010111 00011000 11111111` arası | 1 |
| `11001000 00010111 00011001 00000000` ile `11001000 00010111 00011111 11111111` arası | 2 |
| diğer her şey | 3 |

İlk sürümde yalnız 0, 1, 2 numaralı aralıklar ve "diğer" satırı vardır. Hoca, bölmeyi daha ince yapmak istersek ne olacağını sordu: arayüz 0'a giden aralığın içinden küçük bir alt aralığı ayırıp başka bir arayüze yönlendirmek isteyebiliriz. Slaytta pembe ile işaretlenen satır budur: arayüz 0 aralığının içindeki dört adreslik küçük bir alt aralık arayüz 3'e gönderilir. Bu tür alt bölmeler arttıkça aralık tablosunu yönetmek zorlaşır.

> **Ek bilgi (derste anlatılmadı):** Bitler ondalığa çevrildiğinde `11001000` = 200 ve `00010111` = 23 eder. Python ile kontrol edildiğinde arayüz 0 aralığı 200.23.16.0–200.23.23.255 (bir /21 bloğu), arayüz 3'e ayrılan alt aralık 200.23.16.4–200.23.16.7 (bir /30 bloğu), arayüz 1 aralığı 200.23.24.0–200.23.24.255 (bir /24 bloğu) olur. Arayüz 2 aralığı (200.23.25.0–200.23.31.255) tek bir önekle ifade edilemez, birkaç önekin birleşimidir.

### 6.2 En uzun önek eşleştirme

Çözüm, en uzun önek eşleştirme (longest prefix matching) tekniğidir (ekrandan, 00:45:00). Verilen bir hedef adres için iletme tablosunda girdi aranırken, hedef adresle eşleşen **en uzun** adres öneki kullanılır. Birden fazla girdi eşleşebilir, ama hedefi belirlemek için en uzun olan dikkate alınır.

Hoca örnek bir iletme tablosu üzerinden ilerledi. Tablodaki yıldızlar "herhangi bir bit" anlamına gelir. Hocanın anlatımına göre girdilerin önek uzunlukları sırasıyla 21, 24 ve 21 bittir ve bunlar 0, 1 ve 2 numaralı arayüzlere gider; geri kalan her şey 3 numaralı arayüze gider. <!-- BELİRSİZ: örnek tablo ve iki örnek adres karelerde görünmüyor (kareler 00:45:00 ve 00:50:00'de alınmış); aşağıdaki bit değerleri altyazıdaki önek uzunluklarına uyan ders kitabı tablosundan büyük olasılıkla alınmıştır. -->

| Önek | Arayüz |
|---|---|
| `11001000 00010111 00010*** ********` | 0 |
| `11001000 00010111 00011000 ********` | 1 |
| `11001000 00010111 00011*** ********` | 2 |
| diğer her şey | 3 |

İki örnek adres incelendi:

- **Birinci datagram:** başlık değerine bakıldığında yalnız birinci girdiyle eşleşir. Tek eşleşme olduğu için en uzun eşleşme de odur ve datagram arayüz 0'a iletilir.
- **İkinci datagram:** iki satırla eşleşir. Eşleşenlerden en uzun önek seçilir ve datagram arayüz 1'e iletilir.

Hoca, en uzun önek eşleştirmenin neden kullanıldığını adreslemeyi işlerken daha iyi göreceğimizi söyledi. Bu bağlantı 14. bölümde (hiyerarşik adresleme) kurulur.

### 6.3 TCAM ile donanımda eşleştirme

En uzun önek eşleştirme çoğunlukla üçlü içerik adreslemeli bellekler (ternary content addressable memory, TCAM) ile yapılır. Bu donanım sayesinde eşleştirme tek saat çevriminde tamamlanır. Hoca, Cisco Catalyst yönlendiricilerinde TCAM'de yaklaşık 1 milyon yönlendirme tablosu girdisi tutulabildiğini ve bu girdilerin hepsinin tek saat çevriminde kontrol edilebildiğini söyledi.

> **Ek bilgi (derste anlatılmadı):** "Üçlü" (ternary) denmesinin nedeni, bellekteki her bitin 0, 1 ya da "önemsiz" (yıldız) değerini alabilmesidir. Böylece önekli girdiler doğrudan saklanır ve aranan adres bütün girdilerle paralel karşılaştırılır.

## 7. Anahtarlama Dokusu

Anahtarlama dokusu paketi giriş bağlantısından uygun çıkış bağlantısına aktarır. Anahtarlama hızı (switching rate), paketlerin giriş portlarından çıkış portlarına aktarılabildiği hızdır ve çoğunlukla giriş/çıkış hat hızının katı olarak verilir. N girişli bir yönlendiricide, anahtarlamayı gerçek zamanlı ya da ona yakın yapmak için anahtarlama hızının hat hızının N katı olması istenir.

Anahtarlama dokusunda üç teknik kullanılır: bellek, veri yolu (bus) ve ara bağlantı ağları (interconnection networks).

### 7.1 Bellek üzerinden anahtarlama

Birinci kuşak yönlendiricilerde kullanılır (ekrandan, 00:50:00). Bunlar anahtarlamanın doğrudan CPU denetiminde yapıldığı geleneksel bilgisayarlardır. Paket giriş portundan sistem belleğine kopyalanır, oradan çıkış portuna gönderilir. Bilgisayar açısından bu, paketin bir hattan başka bir hatta aktarılmasıdır. Hız bellek bant genişliğiyle sınırlıdır; her datagram sistem veri yolundan iki kez geçer (ekrandan, 00:50:00). Her şey bellekte ve işlemci tarafından yapıldığı için yeterince hızlı değildir.

### 7.2 Veri yolu üzerinden anahtarlama

Datagram, giriş portu belleğinden çıkış portu belleğine paylaşılan bir veri yolu üzerinden aktarılır. Hoca, öğrencilerin veri yolu (bus) topolojisini zaten bildiğini hatırlattı. Ana sorun veri yolu çekişmesidir (bus contention): veri yolu giriş ve çıkış portları arasında paylaşıldığı için anahtarlama hızı veri yolunun bant genişliğiyle sınırlıdır. Hoca 32 Gbps'lik bir veri yolunun erişim yönlendiricileri için yeterli hız sağladığını söyledi. <!-- BELİRSİZ: hocanın verdiği Cisco model adı altyazıda bozuk ("Cisco 500,600 switch", "Cisco 5000 series"). -->

### 7.3 Ara bağlantı ağları üzerinden anahtarlama

En yeni yöntemdir. Çapraz çubuk (crossbar), Clos ağları ve diğer ara bağlantı ağları başlangıçta çok işlemcili sistemlerde işlemcileri birbirine bağlamak için geliştirilmiştir. Kapasiteyi artırmak için N×N tek bir crossbar anahtar yerine çok katlı (multistage) anahtarlar kullanılabilir. Hocanın gösterdiği örnekte 8×8'lik bir anahtar yerine daha küçük anahtarlardan oluşan katlar kullanılır. <!-- BELİRSİZ: küçük anahtarların boyutu altyazıda bozuk ("for 242 and for 2x2 switches"). --> Böylece paralellikten yararlanılır: giriş portlarından birine gelen bir paket birçok parçaya bölünebilir, ara katlardaki anahtarlara dağıtılabilir ve sonda yeniden birleşir.

Ölçekleme için birden çok anahtarlama düzlemi (switching plane) paralel kullanılır; paralellik hem hızı hem ölçeği büyütür. Hoca örnek olarak Cisco CRS yönlendiricisini verdi: 8 temel anahtarlama düzlemi vardır, her düzlem 3 katlı bir ara bağlantı ağıdır ve paralellik sayesinde 100 Tbps mertebesinde anahtarlama kapasitesine ulaşılır.

## 8. Giriş ve Çıkış Portu Kuyruklaması

### 8.1 Giriş portu kuyruklaması ve HOL engellemesi

Anahtarlama dokusu giriş portlarından daha yavaşsa giriş portlarında kuyruk oluşur. Hocanın örneğinde üç giriş ve üç çıkış portu vardır. Kırmızı datagramlar kırmızı çıkışa, mavi datagram mavi çıkışa, yeşil datagram yeşil çıkışa gidecektir.

- Çıkış portu çekişmesi: aynı anda yalnız bir kırmızı datagram kırmızı çıkışa aktarılabilir. Alttaki kırmızı datagram engellenir.
- Sonraki adımda mavi datagram maviye aktarılır, üçüncü girişteki datagram bir kez daha engellenir.

Kuyruğun başındaki datagram beklediği için arkasındaki, aslında boş bir çıkışa gidebilecek datagramlar da bekler. Buna satır başı engellemesi (head-of-the-line blocking, HOL) denir.

### 8.2 Çıkış portu kuyruklaması

Datagramlar anahtarlama dokusunun iletebileceğinden hızlı gelebildiği için giriş tarafında tampon gerekir. Ama çıkış tarafında da tampon gerekir, çünkü çıkış bağlantısının kapasitesi sınırlıdır. Slayttaki çıkış portunda sırasıyla datagram tamponu (kuyruk), bağlantı katmanı protokolü (gönderme) ve hat sonlandırma vardır; anahtarlama dokusu çıkışa NR hızında datagram getirir, çıkış bağlantısının hızı R'dir (ekrandan, 00:55:00).

Datagramlar anahtarlama dokusundan bağlantının iletim hızından daha hızlı gelirse tamponlama gerekir. Boş tampon kalmazsa hangi datagramların atılacağına bir "atma politikası" (drop policy) karar verir (ekrandan, 00:55:00). Tıkanıklıkta çıkış bağlantısı ve çıkış tamponu dolarsa anahtarlama dokusu gelen datagramı çıkış kuyruğuna koyamaz; bu da paket kaybına yol açar.

Bu yüzden kuyruktaki datagramlar arasından iletilecek olanı seçen bir zamanlama disiplini (scheduling discipline) gerekir. Zamanlama varsa öncelikten de söz edilmelidir: yüksek öncelikli datagramlara en iyi başarım verilmelidir. Hoca bunu "çok önemli" diye vurguladı. Anahtarlama hızı çıkış hattı hızını aştığında çıkış kuyruğunda gecikme ve kayıp oluşur; tampon taşması (buffer overflow) yaşanabilir.

## 9. Tampon Boyutu, Tampon Yönetimi ve Paket Zamanlaması

### 9.1 Ne kadar tampon?

Çıkış bağlantısına ne kadar tampon ayrılmalıdır? RFC 3439'daki temel kurala (rule of thumb) göre ortalama tampon miktarı, "tipik" bir RTT (gidiş-dönüş süresi, ör. 250 ms) ile bağlantı kapasitesi C'nin çarpımına eşit olmalıdır (ekrandan, 01:15:00). Hoca bunun deneysel (ampirik) bir formül olduğunu söyledi.

$$B = RTT \cdot C$$

Örnek: $RTT = 250\ \text{ms}$ ve $C = 10\ \text{Gbps}$ için

$$B = 0{,}25\ \text{s} \times 10 \times 10^{9}\ \text{bit/s} = 2{,}5 \times 10^{9}\ \text{bit} = 2{,}5\ \text{Gbit}$$

olur; slayttaki değer de 2,5 Gbit'tir (ekrandan, 01:15:00).

Daha yeni öneriye göre N akış varsa tampon miktarı şöyledir (ekrandan, 01:15:00):

$$B = \frac{RTT \cdot C}{\sqrt{N}}$$

Tampon çok fazla olursa gecikme artar; bu özellikle ev yönlendiricilerinde görülür. Uzun RTT'ler gerçek zamanlı uygulamalarda kötü başarıma ve ağır (sluggish) TCP tepkisine yol açar. Hoca burada gecikme tabanlı tıkanıklık denetimini de hatırlattı. Sonuç olarak tampon "dolu olmalı ama aşırı dolu olmamalı"dır; en iyi iletim böyle sağlanır.

### 9.2 Tampon yönetimi

Datagramlar anahtarlama dokusundan gelir; bağlantı kapasitesi R gelen bütün datagramları tüketecek kadar yüksek değilse datagramlar kuyrukta bekler. Kuyruğu yönetecek bir mekanizma gerekir. Tampon dolunca bazı datagramlar atılmalıdır ve hangisinin atılacağına karar verilmelidir. İki yaklaşım vardır:

- **Kuyruk sonundan atma (tail drop):** <!-- BELİRSİZ: hocanın tail drop açıklaması altyazıda kısmen kayıp (01:17:13-01:17:25). --> Gelen paket atılır.
- **Önceliğe göre atma:** kuyruktaki bütün önceliklere bakılır, en düşük öncelikli paket atılır.

Bu arada alıcı ve gönderici tarafları tıkanıklık hakkında bilgilendirmek için işaretleme yapılmalıdır. Hoca bunların tıkanıklık denetimi konusunda tartışılan türden bayraklar olduğunu ve bu paketlerin en yüksek önceliği alması gerektiğini söyledi.

### 9.3 Paket zamanlaması

Kuyrukta bekleyen birçok paket varsa bağlantıdan sıradaki hangi paketin gönderileceğine karar vermek gerekir. Dört yaklaşım işlendi.

**İlk gelen ilk hizmet alır (FCFS):** paketler çıkış portuna geliş sırasıyla iletilir. İlk giren ilk çıkar (FIFO) olarak da bilinir. Hoca bunun gündelik hayattaki kuyrukların gerçek bir örneği olduğunu belirtti.

**Öncelik (priority):** bir kuyruk en yüksek öncelik, bir kuyruk en düşük öncelik için ayrılır (ekrandan, 01:20:00). Gelen trafik sınıflandırılır ve sınıfına göre kuyruğa konur; sınıflandırma için herhangi bir başlık alanı kullanılabilir. Paket, tamponda paketi olan en yüksek öncelikli kuyruktan gönderilir; her öncelik sınıfının kendi içinde FCFS uygulanır. Yüksek öncelikli kuyruk düşük öncelikli kuyruktan önce hizmet alır.

Hocanın anlattığı örnek şöyledir:

- 1 numaralı paket yüksek önceliklidir ve gönderilir.
- Bu sırada 2 numaralı (düşük öncelikli) ve 3 numaralı paket gelir. 2, 3'ten önce gelmiş olmasına rağmen önce 3 gider, sonra 2 gider.
- Ardından 4 numaralı (yüksek öncelikli) ve 5 numaralı (düşük öncelikli) paket gelir. 5 gönderilecekken yüksek öncelik kuyruğunda bekleyen datagram yoksa 5 geçer.

<!-- BELİRSİZ: örnekteki 3 ve 4 numaralı paketlerin sırası altyazıdan tam çıkmıyor; ilgili animasyon karede yalnız 1 numaralı paket aşamasında görünüyor (01:20:00). -->

**Round robin:** birçok sınıf kuyruğu oluşturulur; datagramlar sınıflandırılıp ilgili kuyruklara konur. Sunucu sınıf kuyruklarını döngüsel olarak, tekrar tekrar tarar. Her sınıftan, varsa, bir tam paket gönderir; yoksa sıradaki sınıfa geçer.

**Ağırlıklı adil kuyruklama (weighted fair queuing, WFQ):** genelleştirilmiş round robin'dir, ama her sınıfa bir ağırlık verilir. Bu bir tür önceliktir; round robin bu ağırlıklara göre çalışır. WFQ her sınıfa en düşük bant genişliği garantisi verir.

## 10. Ağ Tarafsızlığı

Hoca önce ağ tarafsızlığının (network neutrality) ne olduğunu tanımladı. İki bakış açısı vardır:

- **Teknik açı:** bir ISP'nin kaynaklarını müşterileri arasında nasıl paylaştırması ya da ayırması gerektiği. Teknik olarak paket zamanlama, tampon yönetimi ve benzeri mekanizmalarla yönetilir.
- **Sosyal ve ekonomik ilkeler:** herkes ağa serbestçe ulaşabilmelidir. Bu ifade özgürlüğünü korur, yeniliği ve rekabeti teşvik eder. Ağ serbest bir alandır.

Farklı ülkelerde farklı yasalar uygulanır; bazı ülkelerde yasaklanan bir uygulama bazılarında serbesttir. ABD'de 2015 FCC kararı, "Order on Protecting and Promoting an Open Internet", üç "açık ve kesin" kural koyar (ekrandan, 01:25:00):

- **Engelleme yok (no blocking):** "makul ağ yönetimine tabi olarak yasal içerik, uygulama, hizmet ya da zararsız cihazlar engellenmeyecek."
- **Kısma yok (no throttling):** "makul ağ yönetimine tabi olarak, internet içeriği, uygulaması ya da hizmeti ya da zararsız bir cihazın kullanımı temelinde yasal internet trafiği bozulmayacak ya da yavaşlatılmayacak."
- **Ücretli önceliklendirme yok (no paid prioritization):** kimse parayla öncelik kazanamaz.

Ancak bazı "sisli" alanlar vardır. ISP bir telekomünikasyon hizmeti sağlayıcısı mıdır, yoksa bir bilgi hizmeti sağlayıcısı mı? Cevap düzenleme açısından önemlidir. Telekomünikasyon Yasası (1934 ve 1996) telekomünikasyon hizmetlerine "ortak taşıyıcı" (common carrier) yükümlülükleri getirir; bilgi hizmetlerinde ortak taşıyıcı yükümlülüğü yoktur. Hoca bu alanın henüz düzenlenmediğini söyledi.

> **Ders sonrası not:** Hoca yasa yıllarını önce "2034 ve 2036" diye söyledi, hemen ardından "1934 ve 1996" diye düzeltti; doğrusu 1934 ve 1996'dır.

## 11. IP: Ağ Katmanının Bileşenleri ve IPv4 Datagram Biçimi

### 11.1 Ağ katmanının bileşenleri

Yönlendiricinin içini inceledikten sonra adreslemeye geçildi; önce datagram biçimi, sonra her datagramın nasıl adreslendiği. Taşıma katmanından (TCP, UDP) gelen segment ağ katmanına iner; bağlantı katmanı ve fiziksel katman daha sonra işlenecek. Ağ katmanında şunlar vardır:

- Yol seçimi için yönlendirme protokolleri: OSPF, BGP ya da SDN denetleyicisi. Bunların hepsi iletme tablosunu güncellemek içindir.
- IP protokolü: datagram biçimi, adresleme ve paket işleme kuralları.

<!-- BELİRSİZ: slaytta büyük olasılıkla ICMP protokolü de yer alıyor; altyazıda bu kısım bozuk (01:28:39-01:29:06). -->

### 11.2 IPv4 datagram alanları

IPv4 datagramı 32 bit genişliğinde satırlar halinde çizilir (ekrandan, 01:30:00). Alanlar ve hocanın açıklamaları şöyledir:

- **Sürüm (ver):** IP protokol sürüm numarası, 4 ya da 6.
- **Başlık uzunluğu (head. len):** başlığın uzunluğunu ölçer; toplam uzunluğu değil.
- **Hizmet türü (type of service):** bir bayttır. Diferansiyel hizmet (0-5. bitler) ve tıkanıklık bildirimi (6-7. bitler) için kullanılır.
- **Uzunluk (length):** başlık artı yük verisi dahil datagramın toplam uzunluğu (bayt). Hangi değerin seçileceği datagramı taşıyan teknolojiye bağlıdır.
- **16 bitlik tanımlayıcı, bayraklar (flgs) ve parça ofseti (fragment offset):** mesajı birden çok datagrama bölmek ve alıcıda nasıl birleştirileceğini belirlemek için kullanılır.
- **Yaşam süresi (time to live, TTL):** kalan en fazla atlama (hop) sayısıdır; her yönlendiricide bir azaltılır. Sıfıra ulaştığında paket atılır.
- **Üst katman (upper layer):** taşıma katmanındaki hangi protokolün (TCP ya da UDP) taşındığını gösterir.
- **Başlık sağlama toplamı (header checksum):** başlığın doğru alınıp alınmadığını kontrol eden internet sağlama toplamı.
- **Kaynak IP adresi ve hedef IP adresi:** her biri 32 bit.
- **Seçenekler (options, varsa):** zaman damgası, izlenen yolun kaydı gibi alanlar.
- **Yük verisi (payload):** değişken uzunluktadır, genelde bir TCP ya da UDP segmentidir.

Datagramın uzunluğu en fazla 64 KB, tipik olarak 1500 bayt ya da daha azdır (ekrandan, 01:30:00).

> **Ders sonrası not:** Hoca TTL için "16 bit" dedi. Slayttaki biçimde TTL ve üst katman alanları 32 bitlik satırın yarısını, yani 16 biti birlikte paylaşır; TTL 8 bittir (ekrandan, 01:30:00).

Ek yük konusunda hoca TCP/IP paketleri için toplam 40 bayt artı uygulama katmanı ek yükü olduğunu söyledi.

> **Ders sonrası not:** Hoca ek yükü "TCP için 20 bayt, IP için 25 bayt, toplam 40 bayt" diye söyledi. Toplamın 40 bayt olması için IP başlığının da 20 bayt olması gerekir; doğrusu büyük olasılıkla seçeneksiz IPv4 başlığının 20 bayt olmasıdır.

## 12. IPv4 Adresleme, Alt Ağlar ve CIDR

### 12.1 IP adresi ve arayüz

IPv4 adresi, her ana bilgisayar ya da yönlendirici **arayüzüyle** ilişkilendirilen 32 bitlik bir tanımlayıcıdır. Hoca burada vurgu yaptı: adres ana bilgisayara değil arayüze verilir. Bir ana bilgisayarın birden çok arayüzü varsa her arayüzün kendi IP adresi olur. Arayüz, ana bilgisayar ya da yönlendirici ile fiziksel bağlantı arasındaki bağlantı noktasıdır.

- Yönlendiricilerin genelde birden çok arayüzü vardır; slayttaki yönlendiricide üç arayüz bulunur.
- Ana bilgisayarlarda genelde bir ya da iki arayüz bulunur: kablolu Ethernet ve kablosuz.

IP adresleri 32 bittir ama noktalı ondalık gösterimle yazılır, ör. 223.1.1.1. İkilik 32 bit, her biri 8 bitlik dört parçaya bölünür ve her parça ondalık yazılır.

Arayüzler birbirine nasıl bağlanır? Bu, bağlantı katmanı ve fiziksel katman bölümlerinde ayrıntılı işlenecek. Kablolu Ethernet arayüzleri Ethernet anahtarlarıyla, kablosuz arayüzler bir Wi-Fi baz istasyonuyla bağlanabilir. Şimdilik bir arayüzün diğerine nasıl bağlandığını düşünmek gerekmez; önemli olan araya bir yönlendiricinin girmemesidir.

### 12.2 Alt ağlar

Alt ağ (subnet), araya bir yönlendirici girmeden birbirine fiziksel olarak ulaşabilen cihaz arayüzleridir (ekrandan, 01:35:00). IP adreslerinin bir yapısı vardır:

- **Alt ağ kısmı:** aynı alt ağdaki cihazlar ortak yüksek mertebeli bitlere sahiptir ve araya yönlendirici girmeden haberleşebilir.
- **Ana bilgisayar kısmı:** kalan düşük mertebeli bitler.

Alt ağları bulmanın tarifi şudur: her arayüzü ana bilgisayarından ya da yönlendiricisinden ayırın; böylece yalıtılmış adalar, yalıtılmış ağlar oluşur. Bu yalıtılmış ağların her biri bir alt ağdır.

Slayttaki ağ 3 alt ağdan oluşur (ekrandan, 01:35:00):

| Alt ağ | Ana bilgisayar arayüzleri | Yönlendirici arayüzü |
|---|---|---|
| 223.1.1.0/24 | 223.1.1.1, 223.1.1.2, 223.1.1.3 | 223.1.1.4 |
| 223.1.2.0/24 | 223.1.2.1, 223.1.2.2 | 223.1.2.9 |
| 223.1.3.0/24 | 223.1.3.1, 223.1.3.2 | 223.1.3.27 |

Hoca 223.1.3.0/24 alt ağını şöyle açıkladı: /24, ilk 24 bitin alt ağ kısmı olduğunu gösterir. Kalan 8 bit değişebilir; bu yüzden alt ağ adresinin son baytı 0 yazılır. Bu alt ağdaki adresler 3.1, 3.2 ve 3.27 diye biter; değişen yalnız son 8 bittir, ilk 24 bit sabittir. 223.1.1.0/24 alt ağında da ilk 24 bit sabittir; ana bilgisayarlar 1.1, 1.2, 1.3, yönlendiricinin bağlantısı 1.4'tür.

/24 değeri alt ağ maskesidir (subnet mask): yüksek mertebeli 24 bit alt ağ kısmı, kalan düşük mertebeli 8 bit ana bilgisayar kısmıdır.

> **Ders sonrası not:** Hoca bir yerde "kalan en düşük mertebeli 8 bit ağ kısmıdır" dedi; doğrusu ana bilgisayar (host) kısmıdır.

### 12.3 CIDR

IP adreslemesinde CIDR (Classless InterDomain Routing, "sayder" diye okunur) kullanılır. Adresin alt ağ kısmı herhangi bir uzunlukta olabilir. Adres biçimi a.b.c.d/x'tir; x, adresin alt ağ kısmındaki bit sayısıdır. Hoca, ana bilgisayar kısmının ihtiyacımıza göre büyütülebileceğini söyledi; 8 bitlik ana bilgisayar kısmı zorunlu değildir. <!-- BELİRSİZ: slayttaki CIDR örnek adresi altyazıda kayıp (01:37:56-01:38:22) ve karelerde görünmüyor. -->

## 13. DHCP

### 13.1 Adres nasıl alınır?

Burada aslında iki soru vardır: bir ana bilgisayar kendi ağı içinde IP adresini nasıl alır, ve bir ağ kendisi için IP adreslerini nasıl alır? Birinci sorunun iki cevabı vardır:

- Sistem yöneticisinin bir yapılandırma dosyasına elle yazması (hard-coded).
- DHCP ile dinamik olarak bir sunucudan alınması; bu "tak ve çalıştır" (plug and play) yöntemidir.

DHCP'nin amacı, ana bilgisayarın ağa katılırken ağdaki sunucudan dinamik olarak IP adresi almasıdır. Ayrıca:

- Ana bilgisayar kullanmakta olduğu adresin kirasını (lease) yenileyebilir.
- Adreslerin yeniden kullanımına izin verir.
- Ağa girip çıkan mobil kullanıcıları destekler.

DHCP'de dört tür mesaj vardır: DHCP discover, DHCP offer, DHCP request ve DHCP ACK.

### 13.2 İstemci-sunucu senaryosu

Senaryodaki ağ, alt ağlar örneğindeki ağdır; DHCP sunucusu 223.1.2.5 adresindedir (ekrandan, 01:40:00). Ağa yeni gelen bir mobil istemci IP adresi ister. İstemci 68 numaralı portu kullanır, DHCP sunucusu 67 numaralı portu dinler.

**DHCP discover:** İstemci DHCP sunucusunun IP adresini bilmez. Bu yüzden "burada bir DHCP sunucusu var mı?" diye yayın (broadcast) mesajı gönderir.

- Kaynak adres 0.0.0.0'dır, çünkü istemcinin henüz IP adresi yoktur.
- Hedef adres yayın adresidir.
- yiaddr ("your IP address") alanı da 0'dır, çünkü henüz verilen bir adres yoktur.
- Mesaja bir işlem kimliği (transaction ID) konur.

**DHCP offer:** Sunucu yine yayınla cevap verir: "Ben DHCP sunucusuyum, seni gördüm, işte IP adresin."

- Kaynak adres DHCP sunucusunun IP adresidir; kaynak port 67'dir (sunucu 67, istemci 68 kullanır).
- Hedef adres yine yayındır, çünkü istemcinin henüz IP adresi yoktur.
- yiaddr alanına verilen adres yazılır; bu örnekte 223.1.2.4.
- Discover mesajındaki işlem kimliğinin aynısı konur.
- Bu adresin ne kadar süre geçerli olduğu (lifetime) da eklenir.

**DHCP request:** Hoca bu mesajı, istemcinin önceden aldığı bir adresi kullanmak istediği durumla anlattı. İstemcinin IP adresi yine ayarlanmamıştır, hedef yine yayındır, ama yiaddr alanında önerilen IP adresi vardır. İşlem kimliği mesajın kimliğidir ve bu kez bir süre (lifetime) de bulunur. İstemci, DHCP sunucusuna bu IP adresini şu kadar saniye kullanmak istediğini bildirir.

**DHCP ACK:** Adres uygunsa sunucu "tamam, kullanabilirsin" der. Kaynak adres DHCP sunucusunun adresi, hedef yine yayın, yiaddr istemcinin önerdiği adresin aynısı, işlem kimliği mesajın kimliği ve süre belirlenen süredir.

> **Ders sonrası not:** Hoca request ve ACK'i, daha önce adres almış bir istemcinin discover/offer adımlarını atlayarak kullanabileceği ayrı bir senaryo gibi anlattı. Standart dört mesajlık akışta request, istemcinin offer'da önerilen adresi kabul ettiğini bildiren mesajdır; akış büyük olasılıkla discover → offer → request → ACK sırasındadır. Önceden alınmış adresin yenilenmesinde discover/offer adımlarının atlanması da büyük olasılıkla mümkündür.

### 13.3 DHCP yalnız adres vermez

DHCP, alt ağda ayrılan IP adresinden fazlasını döndürebilir:

- İstemcinin ilk atlama yönlendiricisinin (ağ geçidi, gateway) adresi.
- DNS sunucusunun adı ve IP adresi.
- Adresin ağ ve ana bilgisayar kısımlarını gösteren ağ maskesi.

### 13.4 DHCP örneği

Bu örnekte, evdeki yönlendiriciye benzer şekilde, DHCP sunucusu yönlendiricinin içine gömülüdür (ekrandan, 01:45:00). Bağlanan dizüstü bilgisayar IP adresini, ilk atlama yönlendiricisinin adresini ve DNS sunucusunun adresini almak için DHCP kullanır. İstemcinin DHCP mesajı aşağı katmanlara iner: önce taşıma katmanı protokolü UDP'ye, sonra ağ katmanı IP'ye kapsüllenir, ardından Ethernet ve fiziksel katmandan yönlendiriciye gönderilir (ekrandan, 01:45:00). Yönlendirici kapsülü açar, bunun bir DHCP mesajı olduğunu görür; DHCP sunucusu cevap verir ve cevap aynı yolla istemciye iner. Artık istemcinin yalnız IP adresi değil, DNS sunucusunun adı, ağ geçidinin IP adresi ve ilk atlama yönlendiricisi gibi bilgileri de vardır.

## 14. Hiyerarşik Adresleme ve Adres Bloklarının Dağıtımı

### 14.1 ISP bloğunun bölünmesi

İkinci soruya, yani bir ağın adres bloğunu nasıl aldığına geçildi. Bir ISP'nin bir IP bloğu olduğunu varsayalım; blok /20'dir. Bu, ilk 20 bitin alt ağ alanı, kalan bitlerin ana bilgisayar alanı olduğu anlamına gelir. 32 − 20 = 12 bit ana bilgisayar kısmı kaldığından bu ISP $2^{12} = 4096$ adres dağıtabilir.

ISP alt ağını birçok müşteriye bölmek ister ve bunun için 3 bit daha ayırır. Böylece 20 + 3 = 23 bitlik önekler oluşur ve $2^3 = 8$ müşteri kuruluşuna birer /23 bloğu verilebilir. Her kuruluşa 32 − 23 = 9 bit, yani $2^9 = 512$ adres düşer (ara adım eklendi). <!-- BELİRSİZ: bu kısmın slaytı karelerde görünmüyor ve altyazı 01:46:37-01:47:04 arasında bozuk; hocanın okuduğu adresler altyazıda "223.16.0/20" ve "223.18.0/23". Ders kitabı örneğinde büyük olasılıkla ISP bloğu 200.23.16.0/20, kuruluşlar 200.23.16.0/23, 200.23.18.0/23, ... dır. -->

### 14.2 Kuruluş ISP değiştirince

Bu yapı çok basittir: dışarıya tek bir /20 ilan edilir. Şimdi kuruluşlardan birinin başka bir ISP'ye geçtiğini varsayalım. Bu durumda /20 ilanı o kuruluşun adresleri için artık doğru değildir. İnternetin yönlendirme tablosunda yeni ISP, kuruluşun /23'lük bloğunu da ilan eder. Gelen bir paket için en uzun önek eşleştirme uygulanır: /23, /20'den daha uzun olduğu için paket yeni ISP'ye yönlendirilir. Hocanın 6. bölümde "neden en uzun önek eşleştirme" sorusuna verdiği cevap budur.

> **Ek bilgi (derste anlatılmadı):** Bu yaklaşıma rota birleştirme (route aggregation) denir. ISP'nin tek bir önek ilan etmesi internet yönlendirme tablolarını küçük tutar; daha özel (daha uzun) önekler yalnız istisnalar için eklenir.

### 14.3 ISP adres bloğunu nereden alır?

Adres bloklarını dağıtmaktan sorumlu kuruluş ICANN'dir (Internet Corporation for Assigned Names and Numbers). ICANN:

- IP adreslerini beş bölgesel kayıt kuruluşu (regional registry) üzerinden dağıtır.
- Tek tek üst düzey alan adlarının (.com, .edu vb.) devri dahil DNS kök bölgesini yönetir.

Hoca, IPv4 adreslerinin bittiğini ve yeni adres kalmadığını söyledi; bu konuda 2011 yılını andı. <!-- BELİRSİZ: bu bölüm altyazıda büyük ölçüde bozuk (01:48:42-01:49:04). --> Adres yetersizliğine karşı iki yol vardır: IP adreslerinin kullanımını genişletmek için NAT (ağ adresi dönüştürme) kullanmak ya da IPv6'ya geçmek.

> **Ek bilgi (derste anlatılmadı):** 2011'de büyük olasılıkla IANA'nın son boş IPv4 bloklarını bölgesel kayıt kuruluşlarına dağıttığı kastedilmiştir. NAT, bir ağdaki çok sayıda cihazın dışarıya tek bir genel IPv4 adresiyle çıkmasını sağlar; IPv6 ise 128 bitlik adreslerle sorunu kökten çözer.

## Örnek Sorular

### Soru 1 (ekrandan, 00:25:00)

Bir yönlendiricinin yerel iletme tablosu şöyledir: `0100` → 3, `0110` → 2, `0111` → 2, `1001` → 1. Başlığında `0111` değeri olan bir paket hangi çıkış portuna iletilir?

**Çözüm (derste verildi):** Tabloda `0111` değeri üçüncü satırla birebir eşleşir. Paket 2 numaralı çıkış portuna iletilir.

### Soru 2 (derste sözlü, 00:46:13)

İletme tablosu: `11001000 00010111 00010*** ********` → 0, `11001000 00010111 00011000 ********` → 1, `11001000 00010111 00011*** ********` → 2, diğer → 3. En uzun önek eşleştirmeyle iki datagramın hangi arayüze gideceğini bulun. <!-- BELİRSİZ: tablo ve adresler karede görünmüyor; değerler büyük olasılıkla ders kitabı örneğidir (önek uzunlukları 21, 24, 21 altyazıyla uyumlu). Örnek adresler büyük olasılıkla 11001000 00010111 00010110 10100001 ve 11001000 00010111 00011000 10101010'dur. -->

**Çözüm (derste verildi):** Birinci datagram yalnız birinci girdiyle (21 bit) eşleşir; arayüz 0'a gider. İkinci datagram hem 1 numaralı girdiyle (24 bit) hem 2 numaralı girdiyle (21 bit) eşleşir; daha uzun olan 24 bitlik önek seçilir ve datagram arayüz 1'e gider. Yukarıdaki olası adreslerle python kontrolü aynı sonucu verir.

### Soru 3 (ekrandan, 01:15:00)

RFC 3439 temel kuralına göre tipik RTT 250 ms ve bağlantı kapasitesi 10 Gbps ise ortalama tampon ne olmalıdır? N akış için daha yeni öneri nedir?

**Çözüm (derste verildi):** $B = RTT \cdot C = 0{,}25\ \text{s} \times 10^{10}\ \text{bit/s} = 2{,}5 \times 10^{9}$ bit, yani 2,5 Gbit. N akış için öneri $B = RTT \cdot C / \sqrt{N}$'dir.

### Soru 4 (ekrandan, 01:35:00)

Slayttaki ağda kaç alt ağ vardır ve her alt ağın adresi nedir?

**Çözüm (derste verildi):** Her arayüz ana bilgisayarından ya da yönlendiricisinden ayrılınca üç yalıtılmış ada kalır: 223.1.1.0/24 (223.1.1.1-3 ve yönlendirici 223.1.1.4), 223.1.2.0/24 (223.1.2.1, 223.1.2.2 ve yönlendirici 223.1.2.9), 223.1.3.0/24 (223.1.3.1, 223.1.3.2 ve yönlendirici 223.1.3.27). Ağ 3 alt ağdan oluşur.

### Soru 5 (derste sözlü, 01:45:43)

Bir ISP'nin /20'lik adres bloğu vardır. ISP kaç adres dağıtabilir? 3 bit daha ayırarak bloğu böldüğünde kaç müşteriye hangi büyüklükte blok verebilir?

**Çözüm (derste verildi, son adım eklendi):** Ana bilgisayar kısmı 32 − 20 = 12 bittir, yani $2^{12} = 4096$ adres vardır. 3 bit daha ayrılınca önek /23 olur ve $2^3 = 8$ müşteri kuruluşuna birer /23 verilir. Her /23 bloğunda $2^{9} = 512$ adres bulunur (ara adım eklendi; python ile kontrol edildi).

## Dersin Toparlaması

Bu derste ağ katmanının iki bölümünden ilki olan veri düzlemi işlendi. İletme tek bir yönlendiricide gelen datagramı doğru çıkış portuna taşımak, yönlendirme ise kaynaktan hedefe yolu planlamaktır. Kontrol düzlemi geleneksel yaklaşımda her yönlendiricide, SDN'de uzak bir denetleyicide çalışır. İnternet en iyi çaba hizmeti verir. Yönlendiricinin içinde giriş portları başlığa göre arama yapar ve hedefe dayalı iletmede en uzun önek eşleştirmeyi (donanımda TCAM ile) kullanır. Anahtarlama dokusu bellek, veri yolu ya da ara bağlantı ağıyla kurulur. Giriş tarafında HOL engellemesi, çıkış tarafında tampon taşması görülür; bu yüzden tampon boyutlandırma (RTT·C ve RTT·C/√N), atma politikaları ve FCFS, öncelik, round robin ve WFQ gibi zamanlama disiplinleri gerekir. Ağ tarafsızlığı bu mekanizmaların toplumsal ve hukuki boyutu olarak ele alındı.

Dersin ikinci yarısında IP'ye geçildi: IPv4 datagram biçimi, arayüz başına 32 bitlik adresler, alt ağlar ve CIDR gösterimi, DHCP ile dinamik adres alma ve ISP bloklarının hiyerarşik bölünmesi. Hiyerarşik adreslemede bir kuruluş ISP değiştirdiğinde en uzun önek eşleştirmenin neden gerektiği görüldü. Ders, IPv4 adreslerinin tükendiği ve buna karşı NAT ya da IPv6 kullanıldığı bilgisiyle kapandı; bu iki konu ağ katmanı anlatımının devamıdır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
