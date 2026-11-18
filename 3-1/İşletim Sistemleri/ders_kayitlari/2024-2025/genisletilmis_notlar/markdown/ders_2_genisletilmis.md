# Ders 2 Genişletilmiş Notu: Önyükleme, Bilgisayar Sistemi Organizasyonu, Kesmeler, Depolama Hiyerarşisi, Çok İşlemcili Sistemler ve İşletim Sistemi Görevleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Geçen Dersin Özeti
- 2. Önyükleme (Bootstrap) ve Firmware
- 3. Bilgisayar Sistemi Organizasyonu
- 4. Kesmeler, Kesme Vektörü ve Zaman Paylaşımı
- 5. Depolama Yapısı ve Hiyerarşisi
- 6. Doğrudan Bellek Erişimi (DMA)
- 7. Çok İşlemcili, Çok Çekirdekli ve Küme Sistemleri
- 8. İşletim Sistemi Yapısı: Çoklu Programlama ve Çok Görevlilik
- 9. İkili Mod: Kullanıcı Modu ve Çekirdek Modu
- 10. İşletim Sisteminin Görevleri
- 11. Çekirdek Veri Yapıları
- 12. Hesaplama Ortamları
- Örnek Sorular
- Dersin Toparlaması

## 1. Geçen Dersin Özeti

Hoca derse geçen haftanın özetiyle başladı. İşletim sistemi bir kontrol ve koordinasyon yazılımıdır: Donanım ile bilgisayarın diğer bileşenleri, donanım ile kullanıcı ve bilgisayarlar arasında iletişimi sağlar. Ana görevi bilgisayarın kaynaklarını optimize biçimde yönetmektir. İki temel rolü vardır: kaynakları tahsis eden bir **kaynak tahsis edici (resource allocator)** ve sistemin kullanımında aksaklık çıkmamasını sağlayan bir **kontrol programı (control program)**.

## 2. Önyükleme (Bootstrap) ve Firmware

### 2.1 İşletim sistemi belleğe nasıl yüklenir?

İşletim sisteminin bir çekirdeği (kernel) vardır ve bilgisayar açıldığında ilk çalışan odur. Bilgisayarda bir program çalıştığında bellekte ona yer ayrılır. İşletim sistemi de bir program olduğuna göre ona da bellekte yer verilmeli ve o da baştan sona adım adım çalıştırılmalıdır. Bir programa çift tıkladığımızda, işletim sistemi o program için bellekte yer ayırır; hoca bunu belleğin bir yerinde oturan işletim sistemi (OS) ve yanına yerleşen P programı olarak çizdi. Bu, bilgisayar açıldıktan sonraki durumdur. Peki düğmeye basıp bilgisayarı açtığımızda işletim sisteminin kendisi belleğe nasıl yüklenir? Bunun için ayrı bir mekanizma gerekir.

Elektrik verildiği anda **bootstrap programı** belleğe yüklenir. "Strap" ayakkabı bağcığıdır; ayakkabını bağlayıp dışarı çıkmaya hazırlanmak gibi, bootstrap da bilgisayarı hazırlayan bir programdır. Görevi işletim sistemini başlatmaktır. Ana bellekten kastımız genellikle RAM'dir (random access memory) ve elektrik verilmeden önce RAM'de hiçbir şey yoktur. Bu yüzden bootstrap başka bir yerde, ROM'da tutulur; açılışta ROM'dan ana belleğe bir geçiş olur. Bootstrap ayrıca klavye, fare, USB aygıtları, ekran, ses gibi donanımları başlatır, ardından işletim sisteminin çekirdeğini belleğe yükler ve çalıştırmaya başlar.

Bilgisayarı açtığınızda genellikle siyah bir ekranda BIOS ya da UEFI ile ilgili yazılar görürsünüz, sonra Windows'a ya da Linux'a geçersiniz. Windows'u görene kadarki bu geçiş süreci bootstrap programının işidir.

### 2.2 Firmware

Bu sabit programa **firmware** denir. Hoca kelimeyi şöyle açıkladı: "Firm" sıkı, "ware" yazılım demektir; yani "sıkı yazılım". Elbette bir yazılımdır, ama mümkünse bir kez yazılıp bilgisayarın ROM'unda ya da BIOS'unda saklı kalması amaçlanır; her zaman kolayca değiştirilebilir değildir.

Hocanın anlatımıyla tarihçe şöyledir: İlk ROM'lar hiç değiştirilemezdi; yazılım zarar görürse bilgisayar çöpe giderdi. Sonra bir kez değiştirilebilir hâle getirildi, ardından EPROM'lar geldi. Bunlar da yetmedi, çünkü yeni donanım eklendiğinde ya da yeni işletim sistemi kurulduğunda BIOS güncellemesi gerekir. Günümüzde **EEPROM** (electrically erasable programmable read-only memory) kullanılır. ROM "yalnız okunabilir bellek" demektir; normalde buradan yalnızca okuma yapılır (sistemi başlatmak için), ama güncelleme gerektiğinde silinip üzerine yeniden yazılabilir. Hoca eskiden bozulan bir entegrenin sökülüp sağlam bir bilgisayardan alınan entegreyle değiştirildiğini, bunun bir "organ nakli" gibi olduğunu anlattı.

> **Ders sonrası not:** Hoca EPROM'un elektrikle değiştirilebildiğini ve "zannediyorum bir defa" değiştirme hakkı olduğunu söyledi. Bir kez programlanabilen bellek PROM'dur. EPROM morötesi (UV) ışıkla silinip birçok kez yeniden programlanabilir; elektrikle silinebilen tür ise EEPROM'dur.

### 2.3 Dual boot

Bilgisayarda iki işletim sistemi kuruluysa, BIOS üzerindeki bootstrap iki seçenek görür ve bir ana ekranda hangi işletim sistemiyle açılmak istendiğini sorar. Bu, bootstrap'e eklenmiş ek bir özelliktir (dual boot). Bu ekranlar genellikle DOS benzeri, siyah komut istemi ekranlarıdır; zengin bir kullanıcı arayüzü görülmez.

> **Hocanın vurgusu:** Programlar çalıştığında belleğe yüklenir; ama ana programımız olan işletim sistemini belleğe yükleme görevi başka bir program, yani bootstrap tarafından yapılmalıdır. Programların kökeni ROM'dadır.

## 3. Bilgisayar Sistemi Organizasyonu

Hoca üç kavramı ayırdı: Bilgisayar organizasyonu (bir sistemde kaç bitlik verilerin kullanılacağı gibi konular), bilgisayar mimarisi (bunun daha derin hâli) ve bilgisayar sistemi organizasyonu. Bilgisayar sistemi organizasyonu, bilgisayarı bir sistem olarak düşündüğümüzde hangi bileşenlerin bulunabileceği ve bunların birbiriyle nasıl haberleşeceğiyle ilgilenir.

Her bilgisayar sisteminde bir CPU bulunmak zorundadır; programları ancak onunla çalıştırır (run), verileri onunla işleriz (process). Bunların bir belleğe ihtiyacı vardır (geçen hafta Harvard ve Von Neumann mimarileri olarak görüldü). Bunun dışında her aygıtın kendine ait yapıları vardır. Diskten okuma yazma, fareden komut verme ya da monitöre çıktı gönderme gibi işlerin her birinin ayrı bir denetimi vardır; çünkü işlemciyi ya da belleği kullanmak için hep aynı ortak yolu (bus) kullanırız. Bir işlem başlatıldığında ilgili aygıtın denetleyicisi devreye girer: Yol müsaitse okuma yazma işlemini başlatır; müsait değilse veriler aygıtın yerel buffer'ında (geçici belleğinde) bir süre bekletilir, sonra kullanıma alınır.

### 3.1 Bilgisayar sistemi işleyişi

Bir bilgisayarda birden fazla CPU ve birden fazla aygıt olabilir. Her aygıtın kendine ait denetleyicisi vardır ve hepsi bus üzerinden tek bir belleği paylaşır. Belleğin "tek" olması, iki RAM takılamayacağı anlamına gelmez; mantıksal olarak tek bir RAM vardır ve uçucudur (volatile): Elektrik yoksa içinde hiçbir şey kalmaz.

Eş zamanlı çalışma (concurrent execution) zorunludur. Yazdığımız bir program sürekli CPU'da bulunmaz; belli aralıklarla CPU'yu, belli aralıklarla G/Ç'yi kullanır. G/Ç yapılırken CPU'nun boşta durmaması için başka bir programın CPU'dan faydalanmasını isteriz. Bus yapıları da öyle düzenlenir ki G/Ç yapan aygıt kendi işiyle meşgulken CPU başka bir programa hizmet edebilir. Bir program çalışırken yazıcıdan çıktı alabilmemiz, hocanın konuşurken aynı anda ekran görüntüsünün de karşıya gitmesi bu sayededir. Bu olmasaydı etkileşim (interaktivite) düşük olurdu: Fare yavaş hareket eder, ekran geç gelir, donmalar olur. İnternet bağlantısını dışarıda tutarsak, bu tür durumlar işletim sistemiyle ilgili bir sorundan kaynaklanabilir.

Slayttaki "Computer-System Operation" maddeleri şunlardır (ekrandan, 00:21:30):

- G/Ç aygıtları ve CPU eş zamanlı çalışabilir.
- Her aygıt denetleyicisi belli bir aygıt türünden sorumludur.
- Her aygıt denetleyicisinin yerel bir buffer'ı vardır.
- CPU veriyi ana bellek ile yerel buffer'lar arasında taşır.
- G/Ç, aygıttan denetleyicinin yerel buffer'ına doğrudur.
- Aygıt denetleyicisi işini bitirdiğini bir kesme (interrupt) üreterek CPU'ya bildirir.

### 3.2 Aygıt denetleyicisi ve aygıt sürücüsü

Her aygıt denetleyicisi aygıtın türüne özgüdür: USB için USB denetleyicisi, ekran için ekran denetleyicisi gibi. Bilgisayara bir ekran kartı bağladığımızda işletim sisteminin onun nasıl çalıştığını bilmesi gerekir; ama çok farklı donanımlar bağlanabilir. Arada bir yazılım, yani **aygıt sürücüsü (device driver)** bulunur ve bu yapı katmanlıdır: İşletim sistemi denetleyiciyi nasıl kullanacağını bilir, denetleyici de aradaki yazılımı kullanır. Denetleyici olmasaydı her donanım için işletim sistemine ayrı yazılım takmak gerekirdi; ekran kartı değiştiğinde ya da güncellendiğinde sistemi baştan kurmak gibi zahmetli ve sürdürülemez bir durum ortaya çıkardı.

### 3.3 Yerel buffer ve `scanf` örneği

Yerel buffer neden vardır? Klavyeden bir tuşa bastığımızda bus ve bellek müsait olmayabilir. Tuşa yeniden basmak gerekseydi olaylar karışır, ciddi bir senkronizasyon sorunu çıkardı. Bu yüzden veri geçici olarak yerel buffer'da saklanır.

Hoca bunu C'de karşılaşılan bir durumla gösterdi. Slaydın üzerine elle şu iki satırı yazdı (ekrandan, 00:21:30):

```c
scanf("%d",&x);
scanf("%c",&y);
```

İkinci `scanf` ile bir karakter okumak istediğimizde program karakteri beklemeden alt satıra geçer. Bunun nedeni şudur: Birinci satır bir tamsayı okur. Örneğin `123` girip Enter'a bastığımızda, okunan şey bir dizgi gibi alınır; Enter'a kadarki `123` tamsayıya dönüştürülüp belleğe yerleştirilir. Enter'ın kendisi ayrı bir karakterdir ve buffer'da tutulur. İkinci `scanf` bir giriş istediğinde buffer'da bekleyen Enter'ı alır ve `y`'ye atar; `y` yazdırılırsa Enter'ın ASCII karşılığı görülür. Bu sorunu önlemek için `" %c"` biçiminde başa bir boşluk koymak ya da standart giriş buffer'ını boşaltan bir komut kullanmak gerekir. Böylece ardışık girişler arasında karışıklık olmaz. Sorun, yerel buffer'da verinin beklemesinden kaynaklanır.

> **Ek bilgi (derste anlatılmadı):** Hocanın "flush standard input" diye andığı `fflush(stdin)` kullanımı C standardında tanımsız davranıştır; bazı derleyicilerde çalışır, bazılarında çalışmaz. Taşınabilir çözüm `" %c"` biçimini kullanmak ya da satır sonuna kadar karakterleri `getchar()` ile okuyup atmaktır.

Verinin ana bellek ile yerel buffer arasında taşınmasında CPU'nun da görevi vardır. G/Ç ise aygıttan yerel buffer'a yapılan okuma ya da yazmadır. USB, disk ya da grafik denetleyicisi gibi bir denetleyici CPU'ya "veri aktarımı yapmak istiyorum" ya da "işim bitti" bilgisini gönderir. Bu bilgiyle olan olaya **kesme (interrupt)** denir; çünkü program akışı kesilecek ve G/Ç işlemi yapılacaktır.

## 4. Kesmeler, Kesme Vektörü ve Zaman Paylaşımı

### 4.1 Kesmelerin genel işlevi

Modern işletim sistemleri kesme güdümlüdür (interrupt driven): Bir program çalışırken yarıda kesilebilir ve başka bir programa söz verilebilir. Hoca bunu bir toplulukta konuşmanın mikrofonla yönetilmesine benzetti. CPU bir mikrofondur; kimde mikrofon varsa o konuşur, kimde CPU varsa o çalışır. Herkes eşit haklara sahip olsun diye mikrofon zaman zaman birinden alınıp diğerine verilir.

Belki onlarca program aynı anda çalışır; işlemciye girmek isteyen bir kesme üretir. **Kesme vektörü (interrupt vector)** adlı bir yapı, kesmeyle ilgili işlem yapacak programa yönlendirmeyi sağlar. Örneğin A programından B programına geçilecekse, kesmenin kim tarafından gönderildiği çözülür ve vektör üzerinden B ile ilgili işleme sıra verilir: Mikrofon A'dan alınıp B'ye götürülür.

Yeni çalışacak program parçasına **kesme servis rutini (interrupt service routine, ISR)** denir. Bu basbayağı bir fonksiyondur. Normal bir fonksiyonu, adını program içinde yazarak çağırırız (`f(x)` gibi; buna fonksiyon çağrısı, function call ya da invoke denir). ISR ise kod yazılarak çağrılmaz. Örneğin bir düğmeye basmak bir kesmedir; düğmeye basıldığında yapılacak işi bir fonksiyon olarak tarif edersiniz ve kesme vektörü o fonksiyona yönlendirme yapar. Fonksiyon çağrılarında olduğu gibi burada da yığın kullanılır: `main`'den `f`'ye geçildiğinde o ana kadarki değişken değerleri işlemcinin yığınında saklanır; aynısı kesme için de geçerlidir. Fark şudur: Birinde fonksiyonu bilerek çağırırız, diğerinde anlık bir uyarıcı çağırır.

> **Hocanın vurgusu:** Kesme edilecek komutlarla ilgili adreslerin tutulması kesme mimarisinin en önemli mekanizmalarından biridir. Örneğin klavyede bir şeye basılınca A, fareyle ilgili bir şey olunca B, ekranla ilgili bir şey olunca C rutini çalışır; sistem kesmenin kaynağına bakıp doğru rutine yönlendirir.

Hoca mikroişlemciler dersinde görülecek basit bir uygulamayı örnek verdi: Tek bir buton ve 0, 1, 2, 3, 4 diye artan bir sayaç. Butona ne zaman basılacağı belli değildir; basıldığı anda sisteme sahip olunur ve sayaç bir artar. Bu, kesmelerle kodlanır.

### 4.2 Trap ve exception

Kesme dışında bir yazılım durduk yere bir **trap** ya da **exception** da üretebilir. Örneğin sıfıra bölme (division by zero) bir exception'dır. İşletim sistemi işlemciyi tahsis eder ve CPU kullanımı önemlidir; bu yüzden böyle bir sorun yakalanmalı, program devam edemeyeceği için başka bir programa imkân tanınmalıdır. Benzer şekilde `scanf` ya da `printf` gerçekleşene kadar da bir kesme üretilir ve başka bir programa söz verilir. İşletim sistemi bu kesmelerle sürekli uyarılarak programlar arasında geçiş yapar.

> **Ders sonrası not:** Hoca sıfıra bölmeyi "sonsuz tane çıkarma işlemi" olarak açıkladı. Matematiksel sezgi olarak böyle düşünülebilir, ama işlemci sonsuz çıkarma yapmaz: Bölme komutu böleni sıfır bulduğunda donanım hemen bir istisna (exception) üretir ve denetim işletim sistemine geçer.

### 4.3 Zaman paylaşımı

Bu geçişler **zaman paylaşımı (time sharing)** esasına göre yönetilir. Tek bir işlemci çekirdeği varsa, A programı $t_0$ ile $t_1$ arasında çalışıyorsa B programı $t_1$ ile $t_2$ arasında çalışır; zamanlar arasında örtüşme (overlap) olmaz. Örneğin 0 ile 1. saniye arasında A, 1 ile 2 arasında B işlemciyi kullanır. Hoca bunu bir zaman ekseni üzerinde art arda gelen P1, P2, P3 dilimleri olarak çizdi; geçişler kesmelerle olur.

**Soru:** Sinyal ve sistemler dersinde zaman ve frekans görüldü. Zaman paylaşımı olabiliyorsa frekans paylaşımı da olamaz mı? Örneğin P1 bir frekansta, P2 başka bir frekansta çalışsa? **Cevap:** O zaman işlemciye farklı frekanslarda çalışabilme görevi yüklemek gerekir. İşlemci zaten fetch, decode, execute işlerini yapıyor; buna ek olarak içine farklı frekanslarda çalışan birimler koymak, her biri için çalışma frekans aralığı belirlemek ve süreçleri de o frekanslara dönüştürmek gerekirdi. Bu, bir anlamda analog dünyaya geri dönmek demektir. Oysa dijitale geçişin amacı daha hızlı ve hatadan daha arınmış işler yapmaktır. Bu yüzden frekans paylaşımı tercih edilmemiş, zaman paylaşımı kullanılmıştır.

### 4.4 Kesmelerin işlenmesi ve kesme gecikmesi

Bir kesme isteği geldiğinde ona yanıt olarak bir işlem yapılmalıdır; bu bağlantı kesme vektörüyle kurulur. Olası bütün kesmelerin bulunduğu yapıya hoca "havuz" dedi ve "interrupt polling" terimini andı. Kesmelerin yapacağı işler bildiğimiz program komutlarıdır. Örneğin bir arayüzde yazdırma butonuna basmak (Ctrl+P) ile basıldıktan sonra yapılacak iş arasındaki bağlantıyı kesme işleme (interrupt handling) mekanizması sağlar.

**Soru:** P1'den P2'ye geçiş anlık mı olur, örneğin 5. saniyede P1 bittiyse 5,001. saniyede P2 mi başlar? **Cevap:** Hayır. Arada bir karar verme aşaması vardır: Kesme gönderilir, çözülür, kesmenin çalıştıracağı program parçasına girilir. Arada geçen zamana **kesme gecikmesi (interrupt latency)** denir.

Slayttaki "Interrupt Timeline" çiziminde (ekrandan, 00:35:30) yatay eksen zamandır. Üst satırda CPU'nun iki durumu ("user process executing" ve "I/O interrupt processing"), alt satırda G/Ç aygıtının iki durumu ("idle" ve "transferring") vardır. Başta kullanıcı süreci çalışmaktadır ve G/Ç aygıtı boştadır. Bir G/Ç isteği (I/O request) gelince aygıt aktarıma geçer; aktarım bittiğinde (transfer done) CPU kısa bir süre G/Ç kesmesini işler ve sonra kullanıcı sürecine döner. Bu durum ikinci bir G/Ç isteğiyle tekrar eder. Örneğin ekran kartına veri gönderilecekse, sistemin kesmenin ne olduğunu anlaması gerekir; kesme "adı üstünde" yazmaz, 0 ve 1'lerden oluşur ve çözülmesi (decode edilmesi) gerekir. Kesmeyi işleme süresi bu yüzden vardır.

Geçen haftaki komut çevrimi diyagramında bir komut tamamen çalıştırılana kadar kesme olmayacağını, komut bitince kesme kontrolü yapıldığını görmüştük. G/Ç başladıktan sonra denetim G/Ç'ye geçer, iş bitince kullanıcı programına döner. G/Ç sürerken programın komutları CPU'da bir sonraki kesme gelene kadar bekler; birden fazla program olduğundan programa yeniden sıra gelmesi gerekir. Burada bir bekleme döngüsü vardır.

### 4.5 Sistem çağrıları ve aygıt durum tablosu

G/Ç'nin başlaması ile bitmesi arasında yazılımsal olarak **sistem çağrıları** devrededir. `printf` bir C fonksiyonudur ve "gideyim ekrana bir şey yazayım" diye donanıma doğrudan erişme yetkisine sahip değildir. `printf` bir çıkış işlemidir; bununla ilgili bir kesme gerçekleşir ve `printf` bir sistem çağrısıyla ilişkilendirilir. Bu sistem çağrısı `write`'tır; etkinleştirilir, kesme gerçekleşir ve yazdırılacak şey ekrana yazılır. `printf`'in çok fazla yetkisi yoktur; yalnızca sistem çağrısını çağırmakla görevli küçük bir fonksiyondur. Bilgisayar biliminde ağlarda da işletim sistemlerinde de hep böyle katmanlı yapılardan söz edilir. Sistem çağrıları gelecek derste ayrıntılı ele alınacak.

Bu işlemler yapılırken hangi aygıtın boşta, hangisinin kullanımda olduğunun, kimde ne kadar bellek ve erişim olduğunun muhasebesi tutulmalıdır. Bunu her G/Ç aygıtı için belli değerleri tutan **aygıt durum tablosu (device status table)** yapar. İşletim sistemi bu tabloyla hangi aygıtın boşta olduğunu, hangisinin kime atandığını, hangi sürecin hangi aygıtı talep ettiğini izler.

## 5. Depolama Yapısı ve Hiyerarşisi

### 5.1 Ana bellek ve ikincil bellek

Ana belleğin bir özelliği uçucu olmasıdır; diğer özelliği **rastgele erişimli (random access)** olmasıdır. Bir adres hesaplayıp belleğin kaçıncı hücresine erişmek istiyorsak doğrudan oraya gidebiliriz. Sıralı erişim olsaydı bağlı listede gezinmeye benzerdi: Önce baş düğümü (head) bilmek, sonra `next`, `next` diye ilerlemek gerekirdi; bu verimli değildir. Ana belleğin dezavantajları uçucu olması ve kapasitesinin yetersiz kalmasıdır.

Daha yüksek kapasite için ana belleğin uzantısı olan **ikincil bellek (secondary storage)** kullanılır: sabit diskler, SSD'ler. Bunlar her zaman rastgele erişim mantığıyla çalışmaz ve okuma yazma özellikleri farklıdır. CPU gigahertz düzeyinde, RAM'ler örneğin 800 MHz gibi frekanslarda çalışır; disk düzeyinde hız çok daha düşer. Burada tam bir ödünleşim (trade-off) vardır: Daha fazla veri saklamak için disk, SSD, CD, teyp gerekir; ama bunlara erişim yavaştır. Disk denetleyicileri bunları yönetir.

### 5.2 Hiyerarşi ve önbellek

Depolama hiyerarşisi bellek kapasitesi, hız ve uçuculuk açısından kurulabilir. İki bellek birimi düşünelim: CPU'daki register'lar ve RAM. CPU çok hızlı, RAM ona göre belki yüz kat yavaştır. Sürekli bellekten okuma yazma yapmak maliyetli ve gecikmeye yol açtığından, aradaki dengeyi kurmak için **önbellek (cache, Türkçede cep bellek)** kullanılır. Önbellekte bellekten sık getirilen veriler tutulur.

Register'lar işlemcinin içindedir; geçen dönem flip-floplarla nasıl tasarlandıkları görüldü. Bir flip-flop bir bit saklar; dört bit saklamak için dört flip-flop gerekir. Register'lar çok hızlıdır ama kapasiteleri sınırlıdır, çok fazla register konamaz. Register'lar 16 bit, 32 bit gibi bit düzeyindedir (AX, BX gibi); ana bellek gigabayt düzeyindedir. Araya megabayt düzeyinde bir önbellek konarak denge sağlanır. Önbellek transistörlerle tasarlanan bir donanım olduğundan çok büyük yapılamaz; RAM'lerde 4-8 GB görülürken önbellek megabaytlar düzeyindedir.

Ana bellek yetmediğinde sabit disk (günümüzde artık çoğunlukla SSD) devreye girer. Bunlar da yetmezse, örneğin bir bankanın sürekli veri yedeklemesi gibi çok yüksek kapasite gerektiğinde, manyetik ve optik teypler kullanılır. Hiyerarşide aşağı indikçe kapasite artar, hız azalır. Maliyet ise değişkendir; ekonomiye göre bazen register, bazen manyetik teyp daha pahalı olabilir.

### 5.3 Aygıt sürücüsü ve sabit sistem çağrıları

Her G/Ç aygıtını yönetmek için bir aygıt sürücüsü vardır. Sürücü, denetleyici ile çekirdek arasında iletişimi sağlayan bir arayüzdür. İşletim sistemi aygıtı doğrudan kullanamaz; denetleyiciyi kullanır, denetleyici de aygıt sürücüsüyle haberleşir. Her türden ekran kartı için ayrı denetleyici yazmak mantıklı değildir. Sistem çağrıları sabittir (okuma, yazma); ister ağa, ister yazıcıya, ister başka bir yere yazılsın aynıdır. Denetleyiciler sürücülerle haberleşerek ekrana yazacaksa ekrana, ağa yazacaksa ağa yazma işlemini gerçekleştirir.

### 5.4 Depolama seviyelerinin başarımı

Slayttaki tablo (ekrandan, 01:35:30) şöyledir:

```text
Seviye          1                 2                3              4                 5
Ad              registers         cache            main memory    solid state disk  magnetic disk
Tipik boyut     < 1 KB            < 16 MB          < 64 GB        < 1 TB            < 10 TB
Teknoloji       custom memory     on-chip or       CMOS SRAM      flash memory      magnetic disk
                with multiple     off-chip
                ports CMOS        CMOS SRAM
Erişim (ns)     0.25 - 0.5        0.5 - 25         80 - 250       25,000 - 50,000   5,000,000
Bant (MB/s)     20,000 - 100,000  5,000 - 10,000   1,000 - 5,000  500               20 - 150
Yöneten         compiler          hardware         operating sys. operating sys.    operating sys.
Yedeklendiği    cache             main memory      disk           disk              disk or tape
```

Slaytın altında "Depolama hiyerarşisinin seviyeleri arasındaki hareket açık (explicit) ya da örtük (implicit) olabilir" yazar. Hoca özellikle "yöneten" satırına dikkat çekti: Register'ları derleyici, önbelleği donanım, ana belleği ve katı hal disklerini işletim sistemi yönetir. Yedekleme yukarıdan aşağıya yapılır: Register önbelleğe, önbellek ana belleğe, ana bellek diske, diskler de en son teybe yedeklenir. Ana bellekteki bir veriyi gidip önbelleğe yedeklemeyiz; önbellek CPU'da kullanılmak üzere hazırda tutulan, çok sık kullanılan verilerin yeridir. Ana bellek çalışan süreçlerin işlenmiş ya da işlenmeye hazır verilerini tutar; bunlar kalıcı saklanacaksa diske yedeklenir.

### 5.5 Verinin diskten register'a yolculuğu

Bir A verisinin diskten register'a gelmesi gerektiğini düşünelim. Register işlemcinin içindedir ve işlemciye en fazla işletim sistemi erişebilir. Örneğin bir görüntü işleme programı çalıştırıyoruz ve görüntü sabit diskte. Görüntü önce ana belleğe alınır, oradan CPU'ya gider. Araya kesmeler girip çıktığı için görüntünün bir kopyasının arada önbellekte tutulması gerekebilir. Önbellekten donanım register'larına alınır ve `MOV`, `SUB`, `ADD` gibi komutlar genellikle register'lar üzerinde işlem yapar.

Çok görevli bir sistemde P1 süreci bu görüntü üzerinde çalışırken bir kesme gelir, P1 çıkarılır, P2 girer; görüntü önbellekte ya da ana bellekte saklanabilir. Çok işlemcili bir sistemde ise durum daha karmaşıktır: Görüntü diskten ana belleğe gelmiş, CPU 1'deki P1 sürecine verilmiştir. CPU 1'in ve CPU 2'nin kendi önbellekleri vardır. Kesme gelince işlem yarıda kalır; süreç daha sonra aynı CPU'ya geri dönmezse iki önbellek arasında tutarsızlık oluşabilir. Hoca bunu bölümün iki sekreteri benzetmesiyle anlattı: Bir işiniz için sekreterlerden biriyle konuşup belgeleri hazırlamaya gidersiniz; döndüğünüzde o kişi yoktur ve diğer sekreter "ben seni bilmiyorum" der, her şeyi baştan anlatmanız gerekir. Buna **önbellek tutarlılığı (cache coherence)** problemi denir: Önbellekteki verinin diğer tarafa kopyalanması ya da başka bir çözüm gerekir. Günümüzde **snoopy cache** ("koklayan önbellek") mekanizmasıyla çözülür: CPU'ya gelindiğinde önceki işlemle ilgili bilgi kendi önbelleğinde yoksa yandaki önbelleğe bakılır ve veri oradan aktarılır; böylece işlemler baştan başlatılmaz.

Tek işlemcide veri basit bir yol izler; çok işlemcide simetrik ya da asimetrik yapıya göre karar verilir; dağıtık ve bulut sistemlerde ise her sisteme göre ayrı bir işletim sistemi mekanizması gerekir.

## 6. Doğrudan Bellek Erişimi (DMA)

İlk sistemlerde aygıtlar arasındaki veri akışı CPU üzerinden olurdu. Örneğin diskteki bir resmi ekrana yansıtmak ya da bir veriyi yazıcıya göndermek CPU üzerinden yapılırdı. Bu anlamlı değildir; CPU devreden çıkarılmalı, donanımlar gerektiğinde istedikleri donanıma doğrudan erişebilmelidir. Hoca `scanf` örneğini verdi: Girdi klavyeden gelir, önce CPU'ya, sonra belleğe gider. Hedef zaten bellek olduğuna göre CPU'dan geçmeye gerek yoktur. **Doğrudan bellek erişimi (Direct Memory Access, DMA)** ile veri doğrudan belleğe okunur ya da yazılır.

Slayttaki maddeler (ekrandan, 00:48:30):

- Bellek hızına yakın hızda bilgi aktarabilen yüksek hızlı G/Ç aygıtları için kullanılır.
- Aygıt denetleyicisi veri bloklarını buffer'dan CPU müdahalesi olmadan doğrudan ana belleğe aktarır.
- Her bayt için bir kesme yerine her blok için yalnız bir kesme üretilir.

Hoca ayrıca n çekirdekli bir CPU, m tane G/Ç aygıtı ve bir bellekten oluşan bir Von Neumann mimarisi şemasını gösterdi; DMA yoksa belleğe bütün erişimler CPU üzerinden olur.

## 7. Çok İşlemcili, Çok Çekirdekli ve Küme Sistemleri

### 7.1 Çok işlemcili sistemler

İlk mimarilerde fetch, decode, execute yapan tek bir genel amaçlı işlemci vardı. Daha sonra **çok işlemcili (multiprocessor)** sistemler çıktı: Aynı işlemciden iki, dört ya da sekiz tane bulunur. Bunlara paralel sistemler ya da sıkı bağlı (tightly coupled) sistemler denir. Avantajı daha çok komut işleyebilmek, daha çok veri üzerinde işlem yapabilmektir. Dezavantajı ise simetrik ve asimetrik çok işlemcilik sorunudur.

İki CPU ve n program düşünelim. P1 birinci CPU'da çalışıyor; P1 çıkıyor, P5 geliyor ve yine bu işlemciye düşüyor. P1 geri geldiğinde hangi işlemciye gitmeli? Önceki işlemcisinden devam etmesi daha mantıklıdır, ama başka bir işlemcide de devam edebilir; sonuçta işlemci komut çalıştıracaktır.

- **Asimetrik çok işlemcilik:** Her işlemci belli bir göreve atanır. Hocanın örneğinde P1 her zaman işlemci 1'de, P2 işlemci 2'de çalışır.
- **Simetrik çok işlemcilik:** Her işlemci her türlü işi yapabilir. Slayttaki şemada birbirinden bağımsız üç CPU (CPU0, CPU1, CPU2) vardır; herkes her işi yapabildiği için her işlemcinin kendi register'ları (AX, BX, CX gibi genel ve özel amaçlı register'lar) ve önbelleği vardır.

Hoca sekreter benzetmesini burada da kullandı: Bir süreç bir işlemcide başlayıp geri geldiğinde başka bir işlemciye giderse, önceki bilgilerin yeniden düzenlenmesi gerekir.

> **Ders sonrası not:** Hoca sekreter benzetmesini anlatırken bunun "asimetrik durumun" sorunu olduğunu söyledi, ama hemen ardından "herkes her işlemciyi kullanabilmek noktasında özgür" dedi. Sürecin her seferinde farklı bir işlemciye düşüp önceki bağlamını kaybetmesi, her işlemcinin her işi yapabildiği simetrik yapının sorunudur. Ayrıca kitaptaki tanımda asimetrik çok işlemcilik, her işlemciye belirli bir görevin atandığı (çoğu zaman bir ana işlemcinin diğerlerine iş dağıttığı) yapıdır; belirli bir sürecin hep aynı işlemcide çalıştırılması ise ayrı bir kavramdır (işlemci yakınlığı, processor affinity).

Çok işlemcili sistemlerin avantajları:

- **Verim (throughput):** Birim zamanda yapılan iş sayısı artar.
- **Ölçeklenebilirlik (scalability):** Bir işi 10 saatte yapan bir işçinin yerine aynı kapasitede iki işçi 5 saatte yapar. Aynı kapasitedeki işlemci sayısını artırarak birim zamanda yapılan işi artırabilir, bir işin tamamlanma süresini azaltabilirsiniz.
- **Güvenilirlik:** Artar; ama simetrik/asimetrik meselesi yüzünden ek hatalar da doğabilir. Bir işlemcide başlayıp geri gelen bir süreç için her şeyi baştan başlatmak ya da yapılandırmaları yeniden yapmak gerekebilir, sorunlu yapılandırmalar oluşabilir.

Hangi sistemde hangisinin kullanılacağı işletim sisteminin değil, sistemi kuranın tercihidir.

### 7.2 Çok çekirdekli yongalar

**Çift çekirdekli (dual core)** ya da genel olarak çok çekirdekli yapılarda tek bir işlemci içinde birden fazla çekirdek çalışır. Ölçekleme mantığı aynıdır, ama ayrı ayrı işlemciler yoktur. Günümüz bilgisayarlarının çoğunda 4, 8, 16 çekirdek görülür.

Faydası şudur: Ayrı CPU'lu yapıda her CPU daha fazla bus ve bağlantı gerektirir. Bus sayısının artması iletkenlerin artması, bu da ısının ve dirençsel (rezistif) etkinin artması demektir. **Soru:** Tellerin arasını açsak? **Cevap:** Aralık açılınca dirençsel etki ve ısı azalabilir; ama bu kez iki iletken arasında bir yalıtkan bulunduğu için bir kondansatör oluşur, yani sığasal (kapasitif) etki ortaya çıkar. Bu etkiler bozulmalara yol açabilir. Bu yüzden tek yonga altında çok sayıda çekirdek çok daha ekonomiktir.

### 7.3 Küme sistemleri

**Küme (cluster) sistemleri**, çok işlemcili yapıdaki gibi birbiriyle ortaklaşa çalışan çok sayıda bilgisayardan oluşur. Her birinin kendi RAM'i, G/Ç'si, işlemcisi ve işletim sistemi vardır; bu koca sistemi yöneten bir işletim sistemi de vardır. Hoca bunu buzdolabı büyüklüğünde 50 bilgisayar gibi düşünmemizi istedi; soğutma çok önemlidir. Kümeler genellikle verileri saklamak (storage) için kullanılır; asimetrik ve simetrik türleri vardır. Veri saklamanın yanında amaç yüksek başarımlı hesaplamadır (high performance computing); örneğin derin öğrenme gibi işlemlerin paralelleştirilmesi gerektiğinde bunlardan faydalanılır. Soyut olarak birkaç bilgisayar ve hepsinin kullandığı ortak bir depolama birimi olarak çizilebilir; bilgisayarlar arasında haberleşme olabilir.

## 8. İşletim Sistemi Yapısı: Çoklu Programlama ve Çok Görevlilik

Aradan sonra hoca işletim sistemi yapılarına geçti. Günümüz işletim sistemleri **çoklu programlama (multiprogramming)** yapısında çalışır: Sistem açıldığında bilgisayarı kullanacak birden fazla program olabilir (slaytta bu yapı batch sistem olarak anılır). Eskiden tek bir anda tek bir program çalışabilirdi; bir program bitmeden diğerine geçilmezdi. Çoklu programlamada her program bir iş (job) olarak anılır ve her işin kendi kodu ve verisi vardır. İşletim sisteminin görevi bu işlerin zaman planlamasını, yani **iş zamanlamasını (job scheduling)** yapmaktır: Biri işlemciyi, biri G/Ç aygıtlarını kullanırken işletim sistemi aralarındaki geçişleri sağlar.

Bunun ileri versiyonu **çok görevlilik (multitasking)** sistemleridir; mantık olarak çoklu programlamanın iyileştirilmiş hâlidir. CPU işler arasında o kadar hızlı paylaştırılır ki hepsinin paralel çalıştığını hissederiz. CPU gigahertzlerle çalıştığı için işten işe çok kısa aralıklarla zaman paylaşımı yapılır ve gerçek anlamda paralel işlem yapılıyormuş gibi görünür. Etkileşim çok yüksektir. Yanıt süresinin (response time) bir saniyenin altında olması beklenir; çünkü göz ve kulak bir saniyenin altındaki aralıkları pek hissedemez ("bin bir, bin iki" diye sayılan aralıklar).

Zaman paylaşımlı sistemlerde farklı kullanıcılar da vardır ve her kullanıcının bellekte çalışan en az bir programı vardır; bunlara artık **süreç (process)** denir. Aynı anda çalışmaya hazır birden çok iş varsa aralarında planlama yapılır (CPU zamanlama). Süreçlere CPU gibi bellek de tahsis edilir; sistem hem belleği hem CPU'yu alıp verir. Bir süreç belleğe sığmıyorsa **takas (swap)** mekanizmasıyla başka süreçler bellekten çıkarılabilir. Bu da yetmezse ilerleyen bölümlerde görülecek **sanal bellek (virtual memory)** mekanizması kullanılır; bellekten çıkarılan süreç geçici olarak orada saklanır.

Çoklu programlı bir sistemin bellek yerleşiminde (memory layout) işletim sistemi için bir yer mutlaka vardır. İşletim sistemi buraya bootstrap ya da bootloader ile, sistem açılır açılmaz yüklenir. Kullanıcılar süreçlerini çalıştırdıkça onlara da yer verilir.

Birden fazla süreç varsa işletim sistemi kesme güdümlü çalışır. Kesmeler donanım kaynaklı (örneğin bir G/Ç işlemiyle ilgili sinyal) ya da yazılım kaynaklı olabilir. Yazılım kaynaklı kesmelere örnek: sıfıra bölme, dosyanın uygun olmayan bir yerine erişim, yetkiniz olmayan bir yere ya da işleme erişim, işletim sistemi servislerinden doğan kesmeler, diğer süreçlerin ürettiği kesmeler. Bunların hepsi işletim sisteminin dikkate alması gereken isteklerdir.

## 9. İkili Mod: Kullanıcı Modu ve Çekirdek Modu

İşletim sisteminin bir görevi de korumadır. İşletim sisteminin çekirdeği ayrıca korunmalıdır; süreçlerin de kendi bellek alanları vardır. İşletim sistemi istediğinde Job1, Job2, Job3, Job4'ün bellek alanlarına erişebilir ve onları değiştirebilir; ama Job2'nin Job4'e, Job3'ün Job1'e erişememesi gerekir. Bunu kontrol etmek için **ikili mod (dual mode)** işlem vardır. Bu, bir bitlik bir **mod biti** ile, donanım desteğiyle sağlanır.

- **Kullanıcı modu:** Yetkiler kısıtlıdır; belleğin her yerine erişilemez, sistemde değişiklik yapılamaz.
- **Çekirdek modu (kernel mode):** Çok daha fazla ayrıcalık (privilege) vardır. Bazı komutlar yalnız çekirdek modunda donanım üzerinde değişiklik yapabilir.

Örneğin kesmeler etkileşimi sağlamak için güzel bir araçtır, ama zaman zaman kapatılmaları gerekebilir. Kullanıcı olarak benim programım kesmeleri kapatabilmemelidir; yoksa "bindiği dalı keser": Program kesmeleri kapatırsa kendi G/Ç ihtiyacına bile yanıt verilemez, sistem tıkanır. İşletim sistemi ise gerektiğinde kesmeleri kapatıp açabilir. Bu yetki kullanıcıya kapalı, işletim sistemine açıktır; kullanıcı modu ile çekirdek modu arasındaki fark budur. Bu iki mod arasında geçiş sistem çağrılarıyla sağlanır. Sanal makine yöneticileri (VMM) de bunun bir tür simülasyonunu sağlayabilir; hoca bu konuya şimdilik girmedi.

Hoca C'den bir örnek verdi: Bir pointer değişkenine 0 değerini atayın (belleğin sıfırıncı gözü gibi) ve gösterdiği yere bir değer yazmaya çalışın; yazamamanız gerekir, program kapatılır. Ya da bir `for` döngüsüyle 1'den bir milyona kadar pointer'ı birer birer artırıp gösterdiği yeri sıfırlamaya çalışın; bir yere kadar izin verilir, ama bir noktadan sonra program kapatılır, çünkü size ait olmayan, hakkınız olmayan bir bellek bölgesine erişiyorsunuzdur.

Bellek bölgesine erişim yalnızca Job1'den Job2'ye erişim değildir. Job1'in kendi içinde de farklı bellek bölgeleri vardır: heap, stack, programın kod kısmı, ortam değişkenlerinin (environment variables) bulunduğu kısım. Bunlar da her yerde değişikliğe izin vermeyecek şekilde yapılandırılmalıdır; örneğin stack'ten heap'e gidip istediğiniz gibi veri yazamamalısınız.

Kullanıcı modundan çekirdek moduna geçiş slayttaki şemada gösterilir (ekrandan, 01:23:00). Kullanıcı süreci çalışırken (user mode, mode bit = 1) bir sistem çağrısı yapar. Bu bir kesme oluşturur; buna **trap** denir. Mod biti 0'a çekilir (kernel mode) ve sistem çağrısı çalıştırılır. Dönüşte (return) mod biti yeniden 1 yapılır ve süreç sistem çağrısından döner. Bu geçiş için o yetkiye sahip olmak gerekir. Kesmelerin açılıp kapanması ya da çekirdek moduna geçişler gibi işler **ayrıcalıklı komutlardır (privileged instructions)** ve her sürecin sahip olmadığı şeylerdir.

## 10. İşletim Sisteminin Görevleri

### 10.1 Süreç yönetimi

**Süreç (process)**, bir programın çalışma (execution) hâlindeki durumunun adıdır. Yazdığınız program derlenip çalıştırılabilir dosya hâline getirilmiş ve masaüstünde duruyorsa çalışmıyordur. Çift tıkladığınızda programın bir kopyası (sureti) belleğe yüklenir ve işlemci bu yüklenen kısmı satır satır çalıştırır. Çalışır durumdaki programın terminolojik adı süreçtir. Masaüstünde duran program hiçbir şey yapmaz; hocanın ifadesiyle bir MP3 dosyasından farkı yoktur. Çalıştırıldığında sıfırıncı satırdan n'inci satıra doğru bir yürütme akışı (execution flow) oluşur ve program sayacı birer birer artar. Bu yüzden programa **pasif varlık (passive entity)**, sürece **aktif varlık (active entity)** denir.

Süreçler ilk satırdan son satıra kadar çalıştırılır ve iş bitince sonlandırılır (terminate). Tek iş parçacıklı (single thread) ya da çok iş parçacıklı (multi thread) süreçler olabilir: Program bir yere kadar tek akışla, bir yerden sonra eş zamanlı birden çok akışla ilerleyebilir (Java'da görüldüğü gibi). İşletim sistemi süreci yönetirken, çok iş parçacığı varsa onları da senkronizasyon ve işlemlerin sağlığı açısından yönetmelidir.

Hoca Windows Görev Yöneticisi'ni açarak gösterdi: Microsoft Edge, Opera, PowerPoint gibi uygulamaların her biri tek bir program olarak çalıştırılsa da arka planda 3-5 farklı süreç ve onların içinde farklı iş parçacıkları çalışır. Ayrıntılarda iş parçacığı sayısı görülebilir; örneğin bir sistem süreci altında 162 iş parçacığı çalışıyordu.

Süreç yönetiminin temel etkinlikleri:

- Süreci oluşturma (create) ve sonlandırma; gerektiğinde öldürme (kill) ya da silme.
- Süreci beklemeye alma, askıya alma (suspend) ve askıdan sonra devam ettirme (resume).
- Süreçler arası senkronizasyon mekanizmalarını sağlama.
- Süreçler arası iletişim (interprocess communication).
- Süreçlerde ölümcül kilitlenme (deadlock) olduğunda bunu çözme.

Hocaya göre bu başlıklar yaklaşık altı bölüm boyunca görülecek konulardır.

### 10.2 Bellek yönetimi

İşlemci tek başına işe yaramaz; mutlaka bellek de olmalıdır. Bir sürece yalnızca işlemci tahsis etmek yetmez, bellek de tahsis edilmelidir. Birden fazla süreç olduğunda kime hangi belleğin verileceğine karar verilir. Hoca bunu sınıf tahsisine benzetti: Bu ders bu sınıfta yapılıyor, çünkü kapasite gibi kriterlere göre verildi; daha az öğrenci olsaydı daha küçük bir sınıfa gidilecekti.

Bir program süreç hâline geldiyse komutları mutlaka bellekte olmalıdır; en azından çalışan kısmı bellekte olacak, çalışacak kısmı da bellekten getirilmek üzere bir yerde tutulacaktır (sanal bellek konusu). Komutların dışında sürecin işleyeceği veriler de ana bellekte tutulur. CPU kullanımı gibi **bellek kullanımı (memory utilization)** da önemlidir.

İşletim sistemi şunları yapmalıdır:

- Hangi sürece hangi bellek bölgesini tahsis ettiğini (allocate) ve hangi bölgelerin boş olduğunu izlemek. Hoca bunu otopark yönetimine benzetti: Şu araç şurada, bu araç burada, şuralar boş.
- Hangi bellek bölgelerinin boşaltılabileceğine, hangi süreçlerin dışarı çıkarılabileceğine karar vermek.
- `malloc`, `realloc`, `free` ile kullandığımız türden bellek ayırma (allocation) ve geri verme (deallocation) işlemlerini sağlamak.

### 10.3 Depolama yönetimi

Depolama birimleri daha fazla veri saklar ama okuma yazma nispeten yavaştır. İşletim sistemi sabit diskten mi SSD'den mi okuma yapacağını pek bilmez; ama depolama yönetimiyle ilgili temel algoritmalara sahiptir. Burada veri tek tek rastgele erişimle değil, bloklar hâlinde gidip gelir; blok veri aktarımı işlemleri yapılır.

Disklerimizi C sürücüsü, D sürücüsü, ödevler ve ders notları klasörleri gibi düzenleriz; bu düzeni işletim sistemi sağlar. Bir klasör açtığımızda ya da dosya kopyaladığımızda diskte hangi yere kopyalandığını bilmeyiz; buna işletim sistemi karar verir. Karar verirken belli büyüklükteki dosyayı nereye koyarsa belleği en verimli kullanacağına bakar; boşluk kalmamalı, silme gerektiğinde fazladan çöp oluşmamalıdır. İşletim sistemi bunun için soyutlamalara sahiptir; bu soyutlamaya genellikle **dosya** denir. Disk sürücüsü, teyp sürücüsü gibi aygıtların yönetimine ilişkin fonksiyonlar da işletim sistemindedir.

Dosya sistemi yönetimi de bunun içindedir: dosya oluşturma, silme, dosya üzerindeki değişikliklerin denetimi, izinlerin kontrolü, depolama ve yedekleme işlemleri. **Yığın depolama (mass storage)** söz konusu olduğunda da işletim sisteminin görevleri vardır. Ana bellek yetmeyince disklere, diskler de yetmeyince ek depolama birimlerine (ağ üzerinden ya da başka yollarla) ihtiyaç duyulur; sonuçta hiçbir şey sınırsız değildir ama veri sınırsızdır. Bu donanımların yönetilmesi, optimize edilmesi ve zamanlanması ayrı problemlerdir.

### 10.4 G/Ç alt sistemi

Dış dünyadan veri okuyup yazmak zorunda olduğumuz için CPU'nun, ana belleğin ve aygıtların bu kullanımı da işletim sistemince yönetilmelidir. Slayttaki ifadeye göre işletim sisteminin bir amacı, donanım aygıtlarının tuhaflıklarını ve karmaşıklığını kullanıcıdan gizlemektir. Bir ekran kartının ya da sabit diskin veya SSD'nin nasıl çalıştığını bilmek zorunda değiliz. G/Ç alt sistemi bellek yönetimi ve CPU yönetimiyle ilişki içinde önbellekleri ve bus sistemlerini yönetir, aygıt sürücüleriyle haberleşir ve sistemin aksamadan yürümesini sağlar.

### 10.5 Koruma ve güvenlik

**Koruma (protection)**, kaynakların işletim sistemi tarafından güvenli biçimde yönetilmesine dayanır: Bir sürecin bellek alanı kendisine özgüdür, başka bir sürecin bellek alanına erişemez; bir süreç işlemcideyken başka bir süreç "sen çık, işlemciyi ben kullanacağım" diyemez.

**Güvenlik (security)** ise sistemin iç ve dış saldırılara karşı korunmasıdır. Eskiden tek kullanıcılı bilgisayarlar vardı, internet yoktu ve dışarıdan saldırı pek söz konusu değildi. Artık bunlar sıradanlaştı; özellikle internet kaynaklı virüs, worm, aldatma yazılımları gibi tehditler var. Hoca, Windows 98 ve XP döneminde koruma yazılımlarının pek olmadığını, virüslerin USB bellekten ya da internetten kolayca bulaştığını anlattı. Yaygın bir virüs flash diskteki bütün dosyaları gizli hâle getirirdi (dosyalar silinmez ama görünmez); bir başka tür dosyaları sıkıştırıp şifreler ve "para verirsen şifreni söylerim" der. Günümüzde bir USB takıldığında sistem onu otomatik tarar ve sorunlu bir şey görürse engeller. Yeni virüsleri tanımak için Defender gibi yazılımlar sürekli güncellenen bir virüs imzası (signature) veri bankası kullanır; benzer bir şey bulunca USB'yi kilitler ya da çalıştırmaz.

Birden fazla kullanıcı varsa kullanıcı kimliklerine ve dosyalarına ait veriler de gizli tutulmalıdır; yani sistem yalnız virüse karşı değil insanlara karşı da korunmalıdır. Kullanıcıların birbirinin dosyalarına erişimi kısıtlanır, kullanıcılar gruplanır. Sistemin en üst düzey yetkilisi (admin) ve normal kullanıcılar vardır; yetkilerin verilmesi (grant) ya da yükseltilmesi (escalation) gibi düzenlemeler de işletim sisteminin görevlerindendir.

## 11. Çekirdek Veri Yapıları

Windows gibi işletim sistemlerinin on milyon satırlık yazılımlar olduğu söylenir. Bu çekirdekler nasıl oluşur? Aslında veri yapıları ve algoritmalarla. Hocaya göre veri yapıları ve algoritmalar bilgisayar mühendisliğinin en önemli derslerinden biridir; programlama dersleri bunların uygulamasıdır, sistem tarafında ise işletim sistemi ve ondan türeyen ağlar ve dağıtık sistemler gelir.

Örneğin bellekte hangi bölgelerin boş olduğunu ve hangi bölgelerin hangi süreçlere atandığını (P1'e şuradan şuraya, P2'ye buradan buraya) tutmak istiyoruz. Bu bilgiler işletim sisteminin çekirdeğinde durur; çekirdek de bellekte durur. Yani iç içe geçmiş bir yapı vardır: Bellekte işletim sistemini tutuyoruz, işletim sisteminin verileri de belleğin kim tarafından kullanıldığını tutuyor. Bunun için farklı veri yapıları kullanılır:

- **Tek yönlü bağlı liste:** Ekleme ve çıkarma kolaydır; dizilerdeki gibi kaydırma (shift) gerekmez, yeni düğüm öncekiyle sonrakinin arasına girerek eklenir.
- **Çift yönlü bağlı liste:** İleri ve geri gidilebilir.
- **Dairesel bağlı liste:** Sondaki eleman baştaki elemanı gösterir.
- **Ağaçlar:** İki boyutlu düşünülebilir, ama nihayetinde her şey tek boyutludur, çünkü bellek tek boyutludur.

> **Hocanın vurgusu:** Ağaçlar, bağlı listeler, diziler ana bellekte tutulur, diskte değil. Dördüncü sınıfa gelip hâlâ ağaçların ve grafların diskte tutulduğunu iddia edenler var; böyle bir şey yok. Bunlar ana bellek veri yapılarıdır; disk veri yapıları ayrıdır.

**İkili arama ağacı (binary search tree)** verileri sıralı biçimde tutar: Kökün sağındakiler kökten büyük, solundakiler küçüktür. Bu, arama, ekleme ve çıkarmayı daha düşük karmaşıklıkla yapmayı sağlar. **Soru:** İkili arama ağacında arama karmaşıklığı en iyi durumda ne olur? **Cevap:** En iyi durumda aranan bir adımda bulunabilir. En kötü durumda ağaç dengeliyse $O(\log n)$, dengesizse $O(n)$'e kadar çıkar. Örneğin veriler 1, 2, 3, 4, 5 sırasıyla eklenirse her düğüm bir öncekinin sağ çocuğu olur ve ağacın bağlı listeden farkı kalmaz. Bu yüzden çekirdek yapıları yerine göre AVL ağacı ya da red-black ağacı gibi dengeli ağaçlar kullanır; böylece en kötü durum $O(\log n)$'e iner.

**Hash yapıları**, özellikle hangi sürece hangi bellek bölgesinin verildiğini ya da neyin boşta durduğunu tutmakta çok işe yarar. Hash ile arama karmaşıklığı idealde $O(1)$'e iner; çakışmalar (collision) olursa biraz artar. Dizilerden, hatta ağaçlardan bile daha iyi olabilir. Hash bir ara geçiş fonksiyonu kullanır. Bu fonksiyon karmaşık olmamalıdır; aramayı $O(n)$'den $O(1)$'e indirelim derken çok karmaşık bir fonksiyon yazılırsa kazanç kalmaz. Genellikle mod alma işlemi ve asal sayılar kullanılır.

Slayttaki "Kernel Data Structures" sayfasında (ekrandan, 01:51:30) `hash_function(key)` ile 0'dan n'e kadar indisli bir hash haritasına (hash map) gidilip bir değere (value) ulaşılması gösterilir. Ayrıca **bitmap** "n öğenin durumunu gösteren n ikili basamaklık dizi" olarak tanımlanır. Linux veri yapıları `<linux/list.h>`, `<linux/kfifo.h>` ve `<linux/rbtree.h>` başlık dosyalarında tanımlıdır (bağlı liste, kuyruk ve red-black ağacı). İşletim sistemine sistem çağrısı yazılacaksa genellikle C kullanılır ve bu hazır yapılar kullanılabilir.

## 12. Hesaplama Ortamları

### 12.1 Geleneksel ve mobil ortamlar

İşletim sistemleri farklı cihazlarda bulunur: genel amaçlı makineler, ağ bilgisayarları (thin client), kablosuz haberleşmeli mobil bilgisayarlar ve yüksek kapasiteli yönlendirme (routing) cihazları. Bir yönlendiricide güvenlikle ilgili güvenlik duvarı (firewall) gibi özellikler gerekir. Tek bir işletim sistemi mantığı yoktur; işletim sistemine kullanılacağı cihaza uygun özellikler eklenir.

Mobil tarafta en yaygın örnekler Apple iOS ve Google Android'dir. Bunlar düşük batarya kapasitesine, görece daha düşük bellek ve işlemci özelliklerine sahip küçük cihazlardır; cep telefonunda yüksek başarımlı hesaplama yapılmaz. Arduino gibi gömülü sistemlerin de kendi özellikleri ve buna uygun işletim sistemleri vardır.

### 12.2 Dağıtık sistemler, istemci-sunucu ve eşler arası

Ağ işletim sistemleri (network operating systems) ve dağıtık sistemlerde ağ bir binanın yerel ağı, bir kampüs ya da bütün internet olabilir; bunlar gelecek dönem ağ dersinde görülecek. Hesaplama yapılacaksa işletim sistemi bunlara yönelik rutin ve özellikleri sağlamalıdır.

**İstemci-sunucu (client-server)** mimarisi internetin ta kendisidir. İnternetten bir dosya indirmek de bir haberleşme protokolüyle verinin bilgisayarınıza gelmesidir; tarayıcıdan istediyseniz verinin yine tarayıcıya düşmesi gerekir. Bunun için uygulamalar arası haberleşme mekanizmaları gerekir ve işletim sisteminin bunlar için birçok servisi vardır.

Hoca Windows "Hizmetler" listesinde DHCP servisini gösterdi. Bilgisayarı internete bağladığınızda bir IP adresiniz olmalıdır ve bunu kendiniz belirleyemezsiniz. İşletim sistemindeki DHCP servisi kabloyu bağladığınız anda okulun IP dağıtan sunucusuna bir istek gönderir; sunucu "senin IP adresin bu, bunu bilgisayarındaki ilgili yerlere yaz" diye yanıt verir. Sonra bir tarayıcıdan bir yere bağlanıp dosya indirdiğinizde bir paket oluşturulur ve sizin IP adresiniz paketin içine yazılır: "Bu isteğe yanıt geldiğinde bu adres üzerinden bana gönder." Tarayıcının da kendine ait bir kimliği vardır; buna **port** denir. Gelen paket Opera'dan istediyseniz Opera'ya, Edge'den istediyseniz Edge'e gider. Telefondaki WhatsApp için de aynısı geçerlidir: Telefon DHCP servisiyle IP alır, WhatsApp'ın da bir port numarası vardır. **IP adresi ile port numarası birleşerek soket (socket) yapısını oluşturur** ve istemci-sunucu mimarisi bu yapıyla çalışır. Bu bir ağ konusu olsa da işletim sistemi olayın tam göbeğindedir.

**Eşler arası (peer-to-peer)** yapılar karşılıklı ikili haberleşmeyi sağlar ve eskiden çok kullanılırdı: Bilgisayarınızdaki bir dosyayı paylaşıma açarsınız, başkası bunu görür ve dosya yönlendirme yapılarak doğrudan sizin bilgisayarınızdan onunkine gelir. İşletim sisteminin bu mimariye uygun görevleri vardır.

### 12.3 Sanallaştırma ve emülasyon

Hocaya göre sanallaştırma çok önemlidir. En basit örnek bellek yönetimindedir: Ana bellek kapasitesi yetmediğinde sanal belleğe ihtiyaç duyulur; işletim sistemi sabit diski ya da SSD'yi ana bellekmiş gibi kullanır. Fiziksel olarak disktir ama mantıksal kullanımı tamamen ana bellek mantığındadır. **Emülasyon** ise örneğin bu dönem kullanılacak emu8086 gibi, CPU'nun çalışma mantığını yazılımla taklit etmektir.

Klasik yapıda donanımın üzerinde çekirdek ve onun üzerinde süreçler vardır. **Sanal makine yöneticileri (Virtual Machine Manager, VMM)** ile, örneğin VMware gibi yazılımlarla, tek bir donanım üzerinde birden fazla işletim sistemi aynı anda çalıştırılabilir. Her işletim sisteminin kendi çekirdeği vardır ve VMM bütün işletim sistemlerini ayrı ayrı denetler.

### 12.4 Bulut, gerçek zamanlı ve açık kaynak sistemler

**Bulut bilişim (cloud computing):** Bulutu çoğumuz Google Drive ya da OneDrive gibi veri paylaşımı için kullanırız, ama Google Cloud gibi ortamlarda program yazıp çalıştırmak da mümkündür. Veri ve kod paylaşılabilir, herkese açık (public) ya da özel (private) yapılabilir; bunların yönetimi buluta uygun işletim sistemi işlevleriyle olur. Hocaya göre bulut bilişim, dağıtık işletim sistemleri ve gömülü sistemler günümüzde ayrı birer derstir.

**Gerçek zamanlı sistemler:** Örneğin otonom bir araç engellere ve diğer araçlara çarpmadan güvenli bir sürüş yapmalıdır. Araç dış dünyadan veri alır, işler ve ona göre bir eylemde bulunur; bu tam bir dijital sinyal işleme uygulamasıdır. Kaynakları yöneten bir gerçek zamanlı işletim sistemi (real-time operating system) vardır ve zamanlama ve kesme mekanizmaları geleneksel bilgisayarlara göre çok daha katıdır. Geçen derste bir komut çalışırken kesmenin beklediği, komutun tamamlanmasının beklendiği söylenmişti; gerçek zamanlı ve kontrol sistemlerinde bu kural göz ardı edilebilir ve anında kesme yanıtı (immediate interrupt response) verilir.

> **Hocanın vurgusu:** Hiçbir şey kesin değildir; duruma göre değişebilir.

**Açık kaynak (open source) işletim sistemleri:** Kaynak koduna ulaşabildiğimiz sistemlerdir; kapalı kaynak sistemlerde işletim sisteminin nasıl yazıldığını bilemeyiz. Linux, Türkiye'deki Pardus gibi birçok farklı işletim sistemine taban oluşturur. Açık kaynak olan çekirdektir; Ubuntu'nun belli bir sürümünü indirip bütün kodunu doğrudan bulamayabilirsiniz. Açık çekirdeğin üzerine ek yazılımlar geliştirilerek Pardus, Ubuntu, Xubuntu gibi dağıtımlar (distribution) oluşturulur. GNU, Unix, Linux, BSD Unix gibi aileler vardır; macOS da bunlardan türetilmiş bir işletim sistemidir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:21:30): Aşağıdaki kodda kullanıcı ilk girişte `123` yazıp Enter'a basarsa ikinci `scanf` ne okur? Sorun nasıl giderilir?

```c
scanf("%d",&x);
scanf("%c",&y);
```

> **Çözüm:** İlk `scanf` `123`'ü tamsayıya çevirip `x`'e yazar; Enter karakteri (`'\n'`) giriş buffer'ında kalır. İkinci `scanf` yeni giriş beklemeden bu karakteri `y`'ye okur; `y` yazdırılırsa Enter'ın ASCII karşılığı görülür. Çözüm, ikinci satırı `scanf(" %c",&y);` biçiminde yazmak (boşluk, beyaz boşluk karakterlerini atlar) ya da giriş buffer'ını boşaltmaktır.

**Soru 2** (derste sözlü, 00:32:00): Tek işlemcide programlar arasında zaman paylaşımı yerine frekans paylaşımı yapılamaz mı?

> **Çözüm:** İşlemcinin farklı frekanslarda çalışan birimler içermesi, her biri için frekans aralığı belirlenmesi ve süreçlerin bu frekanslara dönüştürülmesi gerekirdi. Bu, analog dünyaya geri dönmek demektir; dijitale geçişin hız ve doğruluk kazancını kaybettirir. Bu yüzden zaman paylaşımı kullanılır.

**Soru 3** (derste sözlü, 00:34:00): Bir süreç 5. saniyede kesildiğinde sonraki süreç hemen 5,001. saniyede mi başlar?

> **Çözüm:** Hayır. Kesmenin çözülmesi, kesme vektörü üzerinden ilgili servis rutininin bulunması ve ona geçilmesi zaman alır. Bu süreye kesme gecikmesi (interrupt latency) denir.

**Soru 4** (derste sözlü, 00:56:00): Çok sayıda ayrı CPU'nun gerektirdiği bus tellerinin arası açılarak ısı ve dirençsel etki azaltılamaz mı?

> **Çözüm:** Aralık açılınca dirençsel etki ve ısı azalabilir; ama iki iletken arasındaki yalıtkan bir kondansatör oluşturur ve sığasal etki ortaya çıkar. Bu etkiler de bozulmalara yol açar. Bu yüzden çok çekirdekli tek yonga daha ekonomiktir.

**Soru 5** (ekrandan, 01:23:00): Bir kullanıcı süreci sistem çağrısı yaptığında mod biti nasıl değişir?

> **Çözüm:** Kullanıcı modunda mod biti 1'dir. Sistem çağrısı bir trap üretir ve mod biti 0 (çekirdek modu) yapılır; çekirdek sistem çağrısını çalıştırır. Dönüşte mod biti yeniden 1 yapılır ve süreç kullanıcı modunda devam eder.

**Soru 6** (derste sözlü, 01:49:00): Bir ikili arama ağacında arama karmaşıklığı en iyi ve en kötü durumda nedir?

> **Çözüm:** En iyi durumda aranan ilk karşılaştırmada (kökte) bulunur, $O(1)$. En kötü durumda ağaç dengeliyse $O(\log n)$, dengesizse (örneğin 1, 2, 3, 4, 5 sırasıyla eklenmişse ağaç bir bağlı listeye dönüşür) $O(n)$ olur. Çekirdekler bu yüzden AVL ya da red-black gibi dengeli ağaçlar kullanır.

**Soru 7** (derste sözlü, 01:51:00): Hash yapısı arama karmaşıklığını kaça kadar indirebilir?

> **Çözüm:** İdealde $O(1)$'e. Çakışmalar olursa artar. Hash fonksiyonu basit olmalıdır (genellikle mod alma ve asal sayılar); karmaşık bir fonksiyon kazancı ortadan kaldırır.

## Dersin Toparlaması

Bu derste işletim sisteminin bilgisayar açılırken bootstrap programıyla nasıl belleğe yüklendiği, ardından bilgisayar sisteminin bileşenlerinin (CPU, ortak bus, tek ana bellek, yerel buffer'lı aygıt denetleyicileri ve aygıt sürücüleri) nasıl birlikte çalıştığı görüldü. Kesmeler, kesme vektörü ve kesme servis rutinleri üzerinden zaman paylaşımının nasıl yürüdüğü, `printf`'in `write` sistem çağrısına dayandığı, depolama hiyerarşisi ve önbelleğin rolü, DMA, çok işlemcili ve çok çekirdekli sistemler ile önbellek tutarlılığı sorunu ele alındı.

Dersin ikinci yarısında işletim sistemi yapısı (çoklu programlama, çok görevlilik, takas ve sanal bellek), kullanıcı modu ile çekirdek modu ayrımı ve işletim sisteminin süreç, bellek, depolama, G/Ç, koruma ve güvenlik görevleri özetlendi. Çekirdeğin bağlı liste, dengeli ağaç ve hash gibi veri yapılarına dayandığı vurgulandı ve geleneksel, mobil, dağıtık, sanallaştırılmış, bulut ve gerçek zamanlı ortamlarla ders tamamlandı. Hoca sistem çağrılarının sonraki derste ayrıntılı ele alınacağını belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
