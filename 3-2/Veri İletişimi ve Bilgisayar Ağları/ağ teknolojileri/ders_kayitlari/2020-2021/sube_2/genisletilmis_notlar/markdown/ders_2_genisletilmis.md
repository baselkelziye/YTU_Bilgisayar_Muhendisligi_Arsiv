# Ders 2 Genişletilmiş Notu: Derse Giriş ve Ağ Katmanı Tasarım Konuları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Kaynağı ve Kapsamı
- 2. Eski Yöntemleri Neden Öğreniyoruz?
- 3. Katmanlı Model ve Ağ Katmanının Yeri
- 4. Store-and-Forward Packet Switching
- 5. Connectionless ve Connection-Oriented Servis: Genel Bakış
- 6. Router, Host ve ISP
- 7. Connectionless Servis: Datagramlar
- 8. Connection-Oriented Servis: Sanal Devreler
- 9. Sanal Devre ve Datagram Karşılaştırması
- Dersin Toparlaması

## 1. Dersin Kaynağı ve Kapsamı

Bu kayıt, dönemin ilk dersidir. Kaydın ilk yarısı tanışma ve dersin işleyişine ayrılmıştır; akademik anlatım yaklaşık 00:31:40'tan sonra slaytlarla başlar. Ders iki şube için ortak yürütülür ve iki öğretim üyesi aynı oturumda dönüşümlü anlatım yapar; bu notta ikisi de "hoca" diye anılır.

Ders kitabı Andrew S. Tanenbaum'ın (ve David Wetherall'ın) *Computer Networks* kitabının 5. baskısıdır. Ders kitabın ağ katmanı bölümünden (5. bölüm) başlar ve taşıma ile uygulama katmanlarına doğru ilerler. Hocalar slaytların kitaba göre çok kısa olduğunu, bir slaytın kitapta 15-20 sayfaya karşılık gelebildiğini, bu yüzden yalnız slaytlara güvenilmemesi gerektiğini vurguladı. Slaytlar İngilizcedir, terimler İngilizce kullanılır, anlatım Türkçedir.

Ağ katmanı bölümünün başlıkları slaytta şöyledir (ekrandan, 00:35:00):

- Design Issues
- Routing Algorithms
- Congestion Control
- Quality of Service
- Internetworking
- Network Layer of the Internet

Hoca her konuda önce olayın teorik kısmının, sonra bunun bugünkü pratik uygulamasının inceleneceğini söyledi. Tarih boyunca farklı üreticilerin ve akademik kurumların çok sayıda ağ protokolü ortaya attığını, sonunda bugün dünya çapında kullanılan TCP/IP yapısının genel standart haline geldiğini anlattı. Son başlığın ("Network Layer of the Internet") bu yüzden ayrıca yer aldığını belirtti.

> **Ek bilgi (derste anlatılmadı):** Hocalar kitabın 6. baskısının da çıkmış olduğunu konuştu. Kitabın 6. baskısı büyük olasılıkla 2020'lerin başında yayımlandı; 5. baskı 2010-2011 tarihlidir (slaytların altbilgisinde 2011 yazmaktadır).

Hoca hücresel ağlar anlatılırken kitabın 3G gibi kuşaklardan bahsettiğini, derste ise 4G ve 5G'den de söz edileceğini ekledi.

## 2. Eski Yöntemleri Neden Öğreniyoruz?

Hoca, tarihsel gelişime göre anlatılan bazı yöntemlerin "zaten denenmiş, bitmiş, kenara kaldırılmış" diye önemsenmeyebileceğini, ama bunun yanlış bir düşünce olduğunu söyledi. Kenara kaldırılan yöntemler genellikle her yeni teknoloji çıktığında yeniden denenir. "History repeats itself" durumu yaşanır.

Verilen örnekler:

- RFID ortaya çıktığında, uzun süre önce kullanılıp bırakılmış olan ALOHA yeniden popüler oldu; ilk denenen yöntem o oldu.
- Distance vector routing normal bilgisayar ağlarında kenara konmuştu, ama sensör ağları ilk ortaya çıktığında "bunu burada deneyebilir miyiz" diye yeniden gündeme geldi.

> **Ders sonrası not:** Hoca ALOHA için "sene 1960'da kullanılmış" dedi. ALOHAnet büyük olasılıkla 1970-1971 yıllarında Hawaii Üniversitesi'nde geliştirildi; yani 1970'lerin başına aittir.

Bu yöntemler bugün kullanılan pek çok algoritmanın, yöntemin ve tekniğin temelini oluşturur; onları bilmek yenilerini anlamayı kolaylaştırır. İkinci hoca buna mühendislik açısından bir gerekçe ekledi: daha önce karşılaşılmamış ve hazır çözümü olmayan bir problemle karşılaşan mühendisin yapacağı ilk iş, geçmişte benzer durumlarda hangi çözümlerin uygulandığına bakmak ve bunların yeni probleme uygulanıp uygulanamayacağını değerlendirmektir. Hocaya göre yalnız "bugün İnternet şöyle çalışır, TCP/IP budur, adres böyledir" diye anlatılsa konu iki üç haftalık hızlı bir kursla bitirilebilirdi; dersin asıl değeri bu tarihsel arka plandadır.

## 3. Katmanlı Model ve Ağ Katmanının Yeri

Slaytta beş katmanlı model gösterilir ve ağ katmanı vurgulanır (ekrandan, 00:40:00):

| Katman |
|---|
| Application |
| Transport |
| **Network** (vurgulu) |
| Link |
| Physical |

Physical ve Link katmanları veri haberleşmesi (Datacom) dersinde işlenmiştir; bu derste onların var olduğu ve bilindiği kabul edilir. Öğrencinin OSI referans modelini ve yedi katmanını, TCP/IP referans modelinin dört katmanını bilmesi beklenir. Kitap, OSI'deki session ve presentation katmanlarını çıkararak beş katmanlı bir yapı kullanır. Hocalar bu katmanların kısmen politik nedenlerle modelde yer aldığını ve içlerinin pek dolu olmadığını söyledi. Bu derste beş katmanın üstteki üçü (Network, Transport, Application) anlatılır. Katman, servis ve arayüz (interface) kavramlarında eksik hissedenler kitabın 1. bölümünü gözden geçirmelidir.

### 3.1 Ağ katmanının görevi

Slayttaki tanım (ekrandan, 00:40:00): "Responsible for delivering packets between endpoints over multiple links." Yani ağ katmanı, paketleri uç noktalar arasında birden fazla link üzerinden uçtan uca taşımaktan ve teslim etmekten sorumludur.

Hoca bunu alt katmanla karşılaştırarak açıkladı: link katmanında iletişim iki nokta arasında ve tek atlamalıdır; ağ katmanında ise uçtan uca ve çok atlamalıdır. Ağ katmanı mevcut linklerle sağlanmış bağlantıyı genişletir, topolojiyi büyütür ve bilginin uzak bir uçtan öteki uca "sakla-gönder" (store-and-forward) mantığıyla aktarılmasını sağlar.

## 4. Store-and-Forward Packet Switching

Hoca ağ katmanının tasarım konularını slayttan sıraladı (ekrandan, 00:45:00):

- Store-and-forward packet switching
- Connectionless service – datagrams
- Connection-oriented service – virtual circuits
- Comparison of virtual-circuits and datagrams

Hoca bu kavramların ciddi kavramlar olduğunu, başta ezberlense bile kullanıldıkça doğal hale geleceğini söyledi.

### 4.1 Store and forward

Bir veriyi işleyebilmek için onu bellekte tutmak gerekir. Ağdan gelen bir verinin o noktada ya da bir sonraki noktada kullanılabilmesi için önce yerel belleğe alınması (store), hedef orası değilse ağ üzerinden başka bir noktaya yönlendirilmesi (forward) gerekir. Buna store-and-forward yapısı denir. Ağ açısından üzerinde işlem yapılan veri yapısının adı pakettir.

### 4.2 Message switching ve packet switching

İkinci hoca bu kavramların Datacom dersinde de konuşulduğunu hatırlattı. Elinizde bütün bir mesaj olduğunu ve onu A'dan D'ye, B ve C üzerinden aktarmak istediğinizi düşünün:

- Bütün mesaj önce A'dan B'ye, sonra B'den C'ye, sonra C'den D'ye bütün olarak aktarılıyorsa bu **message switching**'dir.
- Mesaj ağ açısından daha anlamlı küçük parçalara, yani paketlere bölünerek aktarılıyorsa bu **packet switching**'dir.

Store-and-forward'ın anlamı şudur: bir düğüm, paketin tamamı tamponuna gelip belleğe yazılmadan onu iletmeye başlayamaz. Örneğin A'nın göndermeye başladığı paketin ilk 10 baytı B'ye ulaştığında B bu baytları C'ye aktarmaya başlamaz. Paketin tamamı (100 bayt ya da 1000 bayt, boyu ne ise) B'ye gelir, paket tamamlanır, ondan sonra iletim devam eder.

### 4.3 Telgraf örneği

Hoca, telgraf operatörlerinin çalışma biçiminin de bir sakla-gönder olduğunu anlattı. Bir telgraf operatörü mesajı bir başka operatöre cümle cümle aktarır; her cümlenin sonunda "stop" denir (filmlerde duyulan "stop" sözcüğü buradan gelir). Karşı operatör o cümleyi alıp bir sonraki noktaya aktarır. Kelime bazında aktarım da yapılabilirdi, ama o zaman kelimenin kaç kez geçtiği, cümlenin başı ya da sonu olup olmadığı gibi bir çerçeve (frame) yapısı kurmak gerekirdi; bu yüzden cümle birimi kullanılır. Cümleler bir araya gelince mesajı oluşturur. Hoca bunun message switching olmadığını vurguladı: mesajın tamamı önce bir yere aktarılıp sonra oradan bütün olarak ileri gitmez, parçalar (cümleler) ayrı ayrı ilerler.

Hoca ayrıca Mors alfabesine değindi: A'dan Z'ye harfler nokta ve çizgilerin farklı birleşimleriyle kodlanır. Nokta 0, çizgi 1 gibi düşünülürse bu, ikili kodun farklı bir biçimidir. İkinci hoca bunun bir tür Huffman kodlaması olduğunu ekledi: sık kullanılan harflere kısa, seyrek kullanılanlara uzun kod verilir. Hoca, bilinçli olarak öyle adlandırılmasa da Mors kodunun Huffman kodlamasının başlangıç noktalarından sayılabileceğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Mors alfabesi 1830-1840'larda, Huffman kodlaması ise büyük olasılıkla 1952'de ortaya çıktı. Huffman kodu önek-özgürdür (hiçbir kod başka bir kodun öneki değildir); Mors kodunda ise harfler arasındaki boşluk ayırıcı olarak kullanılır.

## 5. Connectionless ve Connection-Oriented Servis: Genel Bakış

Hoca bu konunun üzerinde çok durulacağını, çünkü analog ya da dijital haberleşmenin en başından beri var olan bir soru olduğunu söyledi: verilecek servis connectionless mı olacak, connection-oriented mı?

Bugün dijital haberleşmenin bu kadar yaygınlaştığı noktada neredeyse her şey connectionless servis üzerinden verilmektedir, çünkü TCP/IP kullanılmaktadır. Ama hoca bunun connectionless'ın tek yol ya da her senaryoda tek doğru olduğu anlamına gelmediğini vurguladı.

Akılda kalması için verilen benzetme:

- **Connectionless servis mektuba benzer.** Bir gün posta kutunuzda bir zarf bulursunuz, açarsınız, bir arkadaşınızdan mektup geldiğini görürsünüz. Öncesinde kimse "sana bir haber göndereceğim" diye uyarmaz; önceden bir etkileşim yoktur.
- **Connection-oriented servis telefona benzer.** Birini ararsınız, telefonu çalar, açar, aranızda bir bağlantı kurulur, sonra bu bağlantı üzerinden konuşursunuz. Karşı taraf arandığını bilir; telefonu rastgele zamanlarda kaldırıp "acaba arayan var mı" diye kontrol etmez.

İkinci hoca, "datagram" sözcüğündeki "gram" ekinin telegramdan (telgraftan) geldiğini belirtti.

### 5.1 Her katman ayrı değerlendirilir

Connectionless ya da connection-oriented olma özelliği yalnız ağ katmanına ait değildir; her katmanda verilen servis iki türden biri olabilir. TCP/IP'nin ağ katmanı (IP) connectionless'tır, ama bir üst katmanda TCP kullanıldığında servis connection-oriented hale gelir. Alt katmanlarda ise kullanılan teknolojiye göre iki türden biri olabilir. Bu yüzden servis türü katman katman ayrı ayrı değerlendirilir.

Hoca, TCP/IP'nin connectionless tasarlanmasının temel sebeplerinden birinin hata anında esneyebilme, yani ağın bir kısmı çökse bile iletişimin sürebilmesi ihtiyacı olduğunu söyledi.

## 6. Router, Host ve ISP

### 6.1 Topoloji

Slayttaki şekil (ekrandan, 00:50:00), "Hosts send packets into the network; packets are forwarded by routers" cümlesiyle birlikte şu topolojiyi gösterir:

- Gri elips: ISP's equipment (servis sağlayıcının ekipmanı).
- Elipsin içindeki routerlar: A, B, C, D, E.
- Routerlar arası bağlantılar: A–B, A–C, B–D, C–D, C–E, D–E.
- Sol tarafta Host H1, üzerinde Process P1; H1 doğrudan A'ya bağlıdır.
- Sağ tarafta H2, üzerinde P2; H2 bir LAN ile F'ye bağlıdır, F de elipsin dışındadır ve E'ye bağlıdır.
- A ile C arasındaki linkte bir paket (Packet) işaretlidir.

Hoca routerların, hostların ve aralarındaki bağlantıların düzleme indirgendiğinde bir graf oluşturduğunu, bu grafın topoloji olduğunu söyledi.

### 6.2 ISP ve router

ISP, Internet Service Provider (İnternet servis sağlayıcı) demektir. Topolojide bir paketin hedefine taşınmasından sorumlu olan, ama paketin son noktası olmayan, aktarım sağlayan sistemlere **router** (yönlendirici) denir. "Route" yol demektir; router yol bulucudur. Bir yoldan gelen paketin hangi yoldan devam etmesi gerektiğine karar veren yapıdır ve bu karar bir algoritmayla verilir; router üzerinde de bir program, bir süreç çalışır.

Gri alandaki yönlendiriciler ve aralarındaki hatlar bu bağlamda bir **subnet** olarak adlandırılır.

> **Hocanın vurgusu:** Buradaki "subnet" kavramını ileride konuşulacak TCP/IP'deki subnetting (alt ağlara bölme) ile karıştırmayın.

### 6.3 Ağa bağlanma biçimleri

H1 ile H2'nin ISP'ye bağlanma biçimleri farklıdır. H1 doğrudan gri alandaki A'ya bağlıdır; H2 ise gri alanın dışındaki F'ye bağlıdır. Bu şu anlama gelir: ağa bağlanırken bir parçası kullanıcının tarafında olan bir cihaz kullanılabilir (H2 örneği; örneğin evde kullanılan ADSL modem), ya da kullanıcı yalnız bir hat ucunu, örneğin bir metro Ethernet ucunu kullanıyor olabilir (H1 örneği).

### 6.4 Router kararını nasıl verir?

Şekilde A'dan C'ye giden bir paket vardır. C, paketin tamamını aldıktan sonra paketi alternatifler arasından hangi linkten göndereceğine karar verir. Bu karar çeşitli metriklere göre verilebilir:

- hedefe olan yakınlık,
- hatların maliyeti,
- hatların doluluğu ya da bant genişliği kapasitesi.

ISP'nin kendi içinde maliyet büyük olasılıkla belirleyici değildir. Ama İnternet farklı ISP'lerden oluşur ve İnternetin birbirine bağlı olabilmesi için bu ISP'lerin routerlarını birbirine bağlaması gerekir. Bu bağlantılar **Internet Exchange Point (IXP)** denilen noktalarda yapılır. Orada farklı firmalara ait routerlar birbirine bağlıdır; bir firma, paketini B firması üzerinden gönderdiğinde başka, C firması üzerinden gönderdiğinde başka bir ücret ödüyor olabilir. Bunun dışında şirket politikası ya da gizlilik gereği bir paketin geçmesi gereken ya da geçmemesi gereken noktalar olabilir. Router'ın kararı bu ve benzeri kısıtlara göre verilir.

Ev ağında ise seçim şansı yoktur: ev routerının veriyi nereye göndereceği bellidir, her şey ISP'ye gider. Oradaki en büyük karmaşa port forwarding gibi ayarlarla dışarıdan gelen paketin içeride nereye gönderileceğidir; bu da statik yönlendirmedir.

### 6.5 Ağ katmanı da bir süreçtir

İkinci hoca, ağ katmanının kendisinin ve ağ uygulamalarının birer süreç (process) olduğunu vurguladı ve işletim sistemleri dersinin bilindiğini varsaydı. Ağ katmanı yalnız çağrıldığında etkinleşen fonksiyonlardan oluşmaz. Ağdan o anda bir servis istenmese bile, ağın ayakta kalabilmesi için routerlar kendi iç düzenleriyle ilgili mesajlaşmalar yapmak zorundadır. Bu da routerlarda süreçler ve bu süreçlerin içinde iş parçacıkları (thread) çalıştığı anlamına gelir: paket alırlar, paket verirler, kontrol bilgisi değiş tokuş ederler. Web sunucusu, e-posta sunucusu, web istemcisi, sohbet istemcisi gibi bütün ağ uygulamaları da birer süreçtir.

**Host** sözcüğü "ev sahibi" anlamından gelir: işletim sistemi bu tür ağ uygulamalarına ev sahipliği yapar. Host, üzerinde işletim sistemi yüklü olan, bir ağın aktif parçası olan ve bu ağ üzerinden başka uygulamalarla mesaj ve paket alışverişi yapabilen bilgisayar sistemidir.

## 7. Connectionless Servis: Datagramlar

Slayt (ekrandan, 01:00:00): "Packet is forwarded using destination address inside it. Different packets may take different paths." Yani paket, içindeki hedef adrese göre iletilir; farklı paketler farklı yollardan gidebilir.

### 7.1 Şekildeki paketler

Şekilde P1'den P2'ye giden dört paket vardır. Hocanın anlatımına göre 1, 2 ve 3 numaralı paketler kuvvetle muhtemel aynı yoldan, A–C–E–F yolundan gider. 4 numaralı paket ise farklı bir yoldan gider: A'dan B'ye, oradan D'ye, sorun olmazsa D'den E'ye ve E'den F'ye. Ama D'den C'ye, C'den E'ye ve oradan F'ye gitmesi de seçenekler arasındadır.

Hoca bu tür yapılarda döngü oluşabileceğini de vurguladı: bir paket örneğin E'den D'ye, oradan A'ya geri dönebilir. Bu bir şaka değil, gerçek bir olasılıktır ve önüne geçilmesi gerekir.

### 7.2 Yönlendirme tabloları

Slayttaki tablolar (ekrandan, 01:00:00) her router için "Dest." (hedef) ve "Line" (çıkış hattı) sütunlarından oluşur. Boş hücre, hedefin routerın kendisi olduğunu gösterir.

| Dest. | A's table (initially) | A's table (later) | C's Table | E's Table |
|---|---|---|---|---|
| A | – | – | A | C |
| B | B | B | A | D |
| C | C | C | – | C |
| D | B | B | E | D |
| E | C | D | E | – |
| F | C | D | E | F |

A'nın tablosu zamanla değişmiştir: başta E ve F hedefli paketler C hattına gönderilirken, sonradan başka bir hatta gönderilmektedir. Şekildeki 4 numaralı paketin A'dan B'ye gitmesi bu değişikliğin sonucudur.

> **Ders sonrası not:** Slaytta A'nın sonraki tablosunda E ve F için çıkış hattı "D" yazılıdır. Oysa şekilde A'nın D ile doğrudan bağlantısı yoktur; A'nın komşuları yalnız B ve C'dir. Kitaptaki özgün şekilde bu iki hücre büyük olasılıkla "B" olarak yer alır ve 4 numaralı paketin B üzerinden gitmesiyle de bu tutarlıdır.

### 7.3 Artı ve eksiler

Farklı paketlerin farklı yollardan gidebilmesi büyük bir avantajdır. Hoca bunu trafiğe benzetti: iki nokta arasında tek bir yol varsa, yol tıkandığında herkes o tıkalı yolda beklemek zorundadır; ara sokaklar ve yan yollar varsa tıkalı yerden kaçınılabilir.

Dezavantajı ise sıradır. Paketler farklı yollardan gittiği ve bir bütünü oluşturdukları için (telgraf örneğinde cümlelerin paragrafı oluşturması gibi) geliş sıraları önemlidir. İzlenen yolların açıklığına, tıkanıklığına ve diğer parametrelere bağlı olarak önce gelmesi gereken paket sonra, sonra gelmesi gereken paket önce gelebilir; paketler sırasız (out of order) ulaşabilir. Bu durumda H2'deki P2 süreci paketleri bir şekilde sıraya sokmak zorundadır.

## 8. Connection-Oriented Servis: Sanal Devreler

Slayt (ekrandan, 01:05:00): "Packet is forwarded along a virtual circuit using tag inside it. Virtual circuit (VC) is set up ahead of time." Yani paket, içindeki etikete (tag) göre bir sanal devre boyunca iletilir; sanal devre önceden kurulur.

### 8.1 Telefon santrali benzetmesi

Hoca eski filmlerdeki telefon görüşmelerini hatırlattı: biri telefon edeceği zaman telefonu kaldırır, santrale ulaşır ve bağlantı ister. İstanbul'daki biri Ankara'yı aramak isterse önce yerel telefon ofisine bağlanır; oradaki operatör onu bir üst seviyedeki ofise, o da bir üst seviyeye bağlar. Hocaya göre telefon sisteminde en fazla beş seviye vardır. Sonunda Ankara'daki yerel ofise, oradan da aranan eve ulaşılır. Aranan tarafa "İstanbul'dan bir arayan var, görüşmek istiyor musunuz?" diye sorulur; kabul edilirse bağlantı kurulur. Bu bir bağlantı kurulumu (connection setup) durumudur.

Sanal devre yapısı da böyledir. Datagram örneğinde P1'in gönderdiği paketler ağın içinde farklı sıralarla farklı yerlerden gidebiliyordu. Burada ise önce biriyle haberleşmek istendiği bildirilir, o kişiye ulaşırken adım adım hangi düğümlerin izleneceği belirlenip bir yol oluşturulur ve bundan sonra bütün paketler bu yol üzerinden gider. Yolda bir arıza olursa yol devre dışı kalır ve yeniden kurulması gerekir. "Bu paket nereden gidecek?" sorusu yoktur.

### 8.2 Önceden planlama

Bağlantı kurulumu yapıldığı için, herhangi bir anda bir düğümden ötekine o kanal üzerinden geçecek veri miktarı hakkında aşağı yukarı önceden fikir sahibi olunur. Her zaman kesin olmasa da kurulum sırasında "burada ses aktaracağım, bant genişliği gereksinimim şu" denebilir ve buna göre planlama yapılabilir. İyi tarafı önceden planlama ve hazırlıktır. Kötü tarafı ise ayrılıp kullanılmayan, boşa harcanan bant genişliğidir: biri "bana 10 megabit, 100 megabit lazım" deyip sonra saatlerce hiçbir şey göndermeyebilir. Bu da yeni bağlantıların kurulmasını zorlaştırabilir.

### 8.3 Fiziksel devreden sanal devreye

Hoca "circuit" sözcüğünün devre demek olduğunu hatırlattı: iki nokta arasındaki bağlantı ve o bağlantı üzerinden akan elektrik akımı. Telefon santrallerinde bu devreler eskiden rölelerle kurulurdu. Büyük semtlerde 5.000, 10.000, hatta 20.000 abone kapasiteli santraller vardı ve santralin yakınından geçenler binlerce rölenin çekip bırakma seslerini duyardı. Sonra röleler elektronik anahtarlar ve çoklayıcılarla (multiplexer) yer değiştirdi.

Sanal devrede (virtual circuit) ise anahtarlama kod çalıştırılarak yapılır. Her paketin başında, hangi devreye ait olduğunu gösteren bir tanımlayıcı (identifier) vardır. Router bu değere bakarak paketi hangi çıkış kuyruğuna göndereceğine karar verir. Bu da bir anahtarlamadır, ama fiziksel olarak bir kabloyu bir deliğe takarak ya da bir rölenin uçlarını çektirerek değil, tamamen yazılımsal olarak, paketi tanımlayıcısına göre bir giriş kuyruğundan bir çıkış kuyruğuna aktararak yapılır. "Sanal devre" adı buradan gelir.

### 8.4 Şekil ve tablolar

Şekilde (ekrandan, 01:05:00) bu kez A'ya iki host bağlıdır: H1 (Process P1) ve H3 (P3). Dört paket A–C–E–F yolunu izler. Her routerın tablosunun solunda giriş (In: Line, Tag), sağında çıkış (Line, Tag: Out) yer alır:

| Router | Giriş hattı | Giriş etiketi | Çıkış hattı | Çıkış etiketi |
|---|---|---|---|---|
| A | H1 | 1 | C | 1 |
| A | H3 | 1 | C | 2 |
| C | A | 1 | E | 1 |
| C | A | 2 | E | 2 |
| E | C | 1 | F | 1 |
| E | C | 2 | F | 2 |

H1 ve H3, A'ya aynı etiketle (1) gelir. A ikisini aynı çıkış hattına (C) gönderir, ama karışmamaları için H3'ün bağlantısına çıkışta 2 numaralı etiketi verir. C ve E de etiketlere göre paketleri aynı yol boyunca iletir.

> **Ek bilgi (derste anlatılmadı):** Bir routerın gelen etiketi çıkışta başka bir etiketle değiştirmesine etiket değiştirme (label switching) denir. Böylece her host etiketini ağın geri kalanından bağımsız seçebilir; MPLS bu fikrin bugünkü örneklerinden biridir.

## 9. Sanal Devre ve Datagram Karşılaştırması

Slayttaki tablo (ekrandan, 01:10:00):

| Issue | Datagram network | Virtual-circuit network |
|---|---|---|
| Circuit setup | Not needed | Required |
| Addressing | Each packet contains the full source and destination address | Each packet contains a short VC number |
| State information | Routers do not hold state information about connections | Each VC requires router table space per connection |
| Routing | Each packet is routed independently | Route chosen when VC is set up; all packets follow it |
| Effect of router failures | None, except for packets lost during the crash | All VCs that passed through the failed router are terminated |
| Quality of service | Difficult | Easy if enough resources can be allocated in advance for each VC |
| Congestion control | Difficult | Easy if enough resources can be allocated in advance for each VC |

### 9.1 Devre kurulumu ve yönlendirme

Datagram ağında devre kurulumu gerekmez, çünkü paketler birbirinden bağımsız aktarılır ve her paket için hangi bağlantıdan ilerleyeceği yeniden kararlaştırılır (cihazın birden fazla bağlantısı olduğu varsayılarak). Sanal devre ağında ise kurulum yapılmalıdır ki bütün paketler aynı yoldan aynı biçimde aktarılabilsin.

### 9.2 Adresleme

Mektup örneğinde olduğu gibi her mektubun üzerine gönderici ve alıcı yazılır. Datagram ağında da paketler bağımsız yönlendirildiği için her pakette göndericinin ve alıcının tam adresi bulunmak zorundadır; yoksa paketin hangi yöne gideceği bilinemez. Bunun bedeli, adres kaç bayt ise o kadar bilginin her pakete gömülmesidir. Sanal devrede ise pakete yalnız kısa bir etiket (VC numarası) basılır.

### 9.3 Durum bilgisi

Datagramda her paket bağımsız yönlendirildiği için router paketi bir çıkışa gönderdiği anda onu unutur; başka bir şeyle ilgilenmez. Sanal devrede ise önceden bir devre kurulur ve bu devrenin ayakta tutulması için her routerda hangi yoldan gelen paketin hangi yola gideceğini ilişkilendiren bir bağlantı tablosu tutulur. Paketler tanımlayıcılarına göre bu tabloya uygun çıkış yollarına yönlendirilir. Bu, bütün routerlarda durum (state) bilgisi tutulduğu anlamına gelir.

### 9.4 Router arızasının etkisi

Datagram ağında bir router çökerse yalnız o anda routerda çıkışa gönderilmeyi bekleyen paketler kaybolur. Sanal devrede ise aradaki router gittiğinde, alternatif yol olmadığı ve bütün paketler aynı yoldan gitmek zorunda olduğu için o routerdan geçen sanal devreler kopar, otomatik olarak sonlanır.

### 9.5 Hizmet kalitesi (QoS)

Hoca bu satırın bugün çok önemli olduğunu söyledi, çünkü ağ artık yalnız e-posta ya da doküman indirmek için değil, sesli ve görüntülü görüşme için de kullanılmaktadır. Sesin ve görüntünün kalitesi, eş zamanlı gitmesi ve rahatsız etmeyecek bir gecikmeyle ulaşması önemlidir. Bunların hepsine birlikte hizmet kalitesi (Quality of Service) denir.

Datagramda her paket ötekilerden bağımsız ayrı bir yoldan gidiyorsa, bu tür kuralları işletip kaliteyi istenen sınırlar içinde tutmak çok zordur. Sanal devrede ise kurulum sırasında "bunun üzerinden ses ve görüntü aktaracağız, kabul edebileceğimiz en büyük gecikme bu, sahip olmamız gereken en küçük bant genişliği bu" denebilir. Servis sağlayıcı da bunu karşılığında bir ücret alarak sağlar. Bu nedenle sanal devrede QoS'u yönetmek daha kolaydır.

### 9.6 Tıkanıklık denetimi

Sanal devrede tıkanıklığın oluşması, yanlış bir planlama yapılmadıysa çok zordur, çünkü kaynak, parametreleri önceden verilen trafiğe göre ayrılır. Kullanıcı bir arayüz üzerinden bağlı olduğu için servis sağlayıcı bu arayüzü filtreleyerek kullanıcıyı söz verdiği parametrelere zorlayabilir. Kullanıcı söz verdiğinden fazla trafik göndermeye kalkarsa tıkanıklık kullanıcının kendi tarafında oluşur, paket dışarı çıkamaz; ağın geri kalanı etkilenmez. Hocalar alternatif olarak ISP'nin fazla trafiğe izin verip karşılığında daha fazla ücret alabileceğini de söyledi.

Datagramda ise tıkanıklık çok kolay oluşur. Hoca bunu "vahşi batı"ya benzetti: her paket her yoldan gidebilir, paketler arasında öncelik ya da sıra gözetilmez, servis sağlayıcılar paketleri birbirinden bağımsız işler. Denetim olmadığı için kapasitenin üzerinde trafik oluşması her zaman mümkündür.

Ama tıkanıklık oluştuktan sonra onu çözmek açısından durum tersine döner. Datagram ağında tıkanıklığı gidermek çok kolaydır: router yeniden başlatılır, girişinde ve çıkışında bekleyen paketler kaybolur. İkinci hoca bunu işletim sistemlerindeki deadlock konusuna benzetti: deadlock'a karşı ya önlemeye çalışılır (avoidance), ya oluşunca çözülmeye uğraşılır, ya da görmezden gelinip devam edilir. Tıkanıklıkta tam olarak görmezden gelinmez, ama tıkanıklığı önlemeye çalışmak da ek yük getirip kapasiteyi azalttığı için kendi başına tıkanıklığa yol açabilecek etkenlerden biridir.

Sanal devrede ise tıkanıklık varsa ciddi bir sorun var demektir: ya servis sağlayıcı söz verdiğinin dışında yanlış bir şey yapıyordur, ya da servisi alan taraf parametrelere uymuyordur. Sanal devrede oluşan tıkanıklığı çözmek datagrama göre çok daha zordur.

## Dersin Toparlaması

Bu derste dersin kaynağı ve kapsamı tanıtıldıktan sonra ağ katmanına giriş yapıldı. Ağ katmanının, paketleri uç noktalar arasında birden fazla link üzerinden taşıyan katman olduğu, store-and-forward packet switching ile çalıştığı anlatıldı. Router, host ve ISP kavramları bir örnek topoloji üzerinden açıklandı; routerların yönlendirme kararını yakınlık, maliyet, bant genişliği ve politika gibi metriklere göre verdiği belirtildi.

Ardından ağ katmanının sunabileceği iki servis türü karşılaştırıldı: her paketin tam adresle bağımsız yönlendirildiği connectionless (datagram) servis ve önceden kurulan bir yol üzerinde kısa etiketlerle iletimin yapıldığı connection-oriented (sanal devre) servis. Durum bilgisi, router arızası, hizmet kalitesi ve tıkanıklık açısından artı ve eksiler tartışıldı. Bir sonraki konu, ağ katmanının kalbi olan yönlendirme (routing) algoritmalarıdır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
