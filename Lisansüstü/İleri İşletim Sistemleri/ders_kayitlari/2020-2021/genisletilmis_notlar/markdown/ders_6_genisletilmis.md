# Ders 6 Genişletilmiş Notu: Sanallaştırma Makaleleri Tartışması: Xen, Disco, VMware G/Ç ve Konteyner-KVM Karşılaştırması

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

> Bu ders, önceden okunması istenen makalelerin soru-cevapla tartışıldığı bir oturumdur. Ekranda slayt ya da makale paylaşılmamıştır; bu yüzden makalelerdeki şekil ve sayılar hocanın sözlü aktarımından alınmıştır.

## İçindekiler

- 1. Xen and the Art of Virtualization
- 2. Disco: Ölçeklenebilir Çok İşlemcilerde Ticari İşletim Sistemleri
- 3. VMware Workstation'da G/Ç Cihazlarının Sanallaştırılması
- 4. Sanal Makineler ile Linux Konteynerlerinin Performans Karşılaştırması
- Örnek Sorular
- Dersin Toparlaması

## 1. Xen and the Art of Virtualization

Listedeki ilk makale (10 numara) Xen sanallaştırma ortamını anlatır. Makale, Xen'i yazıldığı dönemde var olan diğer sanallaştırma ortamlarıyla, yani diğer sanal makine monitörleriyle (Virtual Machine Monitor, VMM) karşılaştırır; benzerlikleri ve farkları ortaya koyar, ama doğal olarak daha çok Xen'in avantajları üzerinden gider.

### 1.1 Denali ile farklar

Makalenin literatür kısmında referans alınan bir başka çalışma Denali'dir ve makale Denali'den farklarını birkaç maddede vurgular. Hoca bu farkları sordu.

İlk cevaplarda iki nokta öne çıktı: Xen'in ticari (commodity) işletim sistemlerine destek vermesi ve bunu performanstan ve kullanışlılıktan taviz vermeden yapmayı hedeflemesi. Hoca bunların makalenin girişinde geçtiğini, ama temelde dört farktan söz edildiğini ve performansla ilgili farkın daha özgül biçimde anlatıldığını belirtti.

Bir başka öğrencinin not aldığı dört madde aslında Xen'in tasarım ilkeleridir: yüksek performans için paravirtualization, kaynak dağıtımı, sanallaştırmanın üstteki işletim sisteminden tamamen gizlenmesi meselesi ve uygulamaların Xen altında (değiştirilmeden) çalışabilmesi. Hoca bunların Xen geliştirilirken temel tasarım ilkesi olarak ele alınan noktalar olduğunu, Denali karşılaştırmasının da hemen hemen bu maddeler üzerinden yürüdüğünü söyledi.

Son olarak makalenin ilgili bölümü okunarak farklar netleşti:

- Denali mevcut ABI'leri hedeflemez; bu nedenle bazı mimari özellikleri VMM arayüzünden çıkarabilir.
- Denali, tek bir konuk işletim sistemi içinde uygulama çoğullama ya da çoklu adres alanı desteği sorununu ele almaz. Her sanal makine tek kullanıcılı, korumasız bir işletim sistemi barındırır. Xen'de ise tek bir sanal makine, değiştirilmemiş binlerce kullanıcı seviyesi süreci çoğullayabilir.
- Denali'de sanallaştırma katmanındaki bellek yönetimi eksiklikleri yüzünden VMM bütün sayfalama (paging) işlemlerini diskten kendisi yapar.

Hoca üçüncü maddenin, daha önce dile getirilen "performans farkının" asıl noktası olduğunu vurguladı.

> **Ek bilgi (derste anlatılmadı):** Xen makalesinde büyük olasılıkla dördüncü bir fark da sayılır: Denali'de VMM makine kaynaklarına "sanal" adlar verir, Xen'de ise konuk işletim sistemleri donanım düzeyindeki ayrıntılara (örneğin gerçek makine adreslerine) güvenli biçimde erişebilir. Bu madde derste okunmadı.

### 1.2 Paravirtualization nedir?

Makale paravirtualization'a özellikle önem verilmesi gerektiğini söyler. Hoca paravirtualization'ın ne olduğunu sordu.

Bir öğrenci iki tür sanallaştırmadan söz edildiğini anlattı: tam (full ya da true) sanallaştırma ve paravirtualization. Öğrencinin ilk açıklaması, tam sanallaştırmada donanımın olduğu gibi sanal makinelere yansıtıldığı, paravirtualization'da ise donanımın farklılaştırılarak, örneğin belleğin parçalara bölünüp her sanal makineye bir kısmının gösterilerek aktarıldığı yönündeydi. Hoca açıklamanın doğru yolda olduğunu ama bir örnekle netleşmesi gerektiğini söyleyip şu soruyu sordu:

**Soru:** Bir giriş-çıkış cihazının bütün donanımsal özelliklerini yazılımla üst katmana yansıtıyorum. Üst katman aslında bir yazılımla muhatap olduğunun farkında değil, onu fiziksel bir donanım gibi kullanıyor. Bu hangi kategoriye girer, tam mı, para mı?

**Cevap:** Öğrenci önce "para" dedi; hocanın cevabı **tam sanallaştırma** oldu. Hoca, öğrencinin kendi tanımını tersine çevirerek soru hâline getirdiğini, bu yüzden cevabın tam sanallaştırma olması gerektiğini açıkladı.

Hocanın toparladığı ayrım şöyledir:

- **Tam sanallaştırma:** Bir donanım yazılımla birebir çoğaltılır (replike edilir) ve işletim sistemine sunulur. İşletim sisteminin bunun bir yazılım olduğunu anlamaması için her türlü tedbir alınır. Bunun maliyeti çok yüksektir.
- **Paravirtualization:** Konuk işletim sisteminden bir cihaz için gelen G/Ç isteği alınır, basit bir çeviriden (translation) geçirilir ve VMM'in ya da VMM'in üzerinde çalıştığı ana (host) işletim sisteminin zaten sahip olduğu aygıt sürücüsüne aktarılır (map edilir). Bir istek, aynı kategoride farklı ama benzer özellikler taşıyan başka bir isteğe dönüştürülür. Maliyeti daha düşüktür, iş daha kolay ilerler.

> **Hocanın vurgusu:** Yazılımla bir donanımı birebir taklit edip işletim sisteminden gizliyorsanız tam sanallaştırma; isteği çevirip var olan bir sürücüye paslıyorsanız paravirtualization.

### 1.3 Application Binary Interface (ABI)

Xen'in kullanımında önemli noktalardan biri ABI'dir (Application Binary Interface). Hoca ABI'nin ne olduğunu ve neden önemli olduğunu sordu.

Bir öğrenci, kodu derleyince elde edilen dinamik kütüphanelerin (DLL) Xen sistemince tanınması ve derlenmiş uygulamaların bu dosyalarının değiştirilmemesi gerektiği şeklinde cevap verdi. Hoca bunu düzeltti: ABI yalnız DLL'lerle (dinamik yüklenen kütüphaneler) sınırlı değildir, **ikili uyumluluk** (binary compatibility) anlamına gelir. Kaynak kodu derlersiniz ve ikili bir çalıştırılabilir dosya elde edersiniz; ABI bu çalıştırılabilir dosyanın uyduğu arayüzdür.

Yazarların temel kaygılarından biri bu uyumluluğu korumaktır. Aksi hâlde ya kaynak kodu yeniden derleyip başka bir çalıştırılabilir dosya elde etmek ya da çalıştırılabilir dosyayı çevirmek (retranslate) gerekir.

### 1.4 Bir işletim sistemini Xen'e taşıma maliyeti

Makalede bir işletim sisteminin Xen ortamına aktarılmasının (porting) maliyetinden de söz edilir. Bir öğrenci makalenin amacından başlayarak Xen altında Windows XP, Linux ve NetBSD gibi farklı işletim sistemlerinin çalıştırıldığını anlattı.

Hoca maliyetin anlamını şöyle netleştirdi: burada maliyet, işletim sisteminin Xen altında çalışabilmesi için yapılması gerekenlerdir. Örneğin sanal aygıt sürücüleri sağlamak ya da işletim sisteminde bellek yönetiminin yapılış biçimini değiştirmek.

## 2. Disco: Ölçeklenebilir Çok İşlemcilerde Ticari İşletim Sistemleri

İkinci makale (11 numara) "Disco: Running Commodity Operating Systems on Scalable Multiprocessors" başlığını taşır.

### 2.1 Commodity işletim sistemi

**Soru:** Commodity operating system nedir?

**Cevap:** Bir öğrenci "ticari olarak kabul görmüş, güvenilir işletim sistemleri" diye cevap verdi. Hoca bunu tamamladı: ikili ve kurulabilir (install edilebilir) biçimde sunulan, kutusunda satın alınabilen ya da internetten indirilebilen, kullanıcının üzerinde herhangi bir değişiklik yapmak zorunda olmadığı işletim sistemidir.

### 2.2 Makalenin amacı ve anahtar kavram

Hoca, ticari işletim sistemlerini ölçeklenebilir çok işlemcilerde (scalable multiprocessor) çalıştırmanın neyi sağlayacağını, makalenin neyi incelediğini sordu.

Gelen cevaplar makalenin özetine yakındı: makale, büyük bilgisayarlar için sistem yazılımı kurmada mevcut işletim sistemlerinde kapsamlı değişiklik yapmak yerine alternatif bir yol önerir; bir sanal makine monitörü katmanı birden çok ticari işletim sistemi kopyasını çalıştırır. Bir başka öğrenci, ölçeklenebilir bilgisayarlarda donanımın yazılımdan önde gittiğini, uygun yazılımların geç geliştirildiğini ve bu yüzden donanım yeniliklerinden yeterince yararlanılamadığını anlattı. Bu gecikmeyi önlemek için Disco adlı bir sanal makine monitörü geliştirilmiştir; üzerinde konuk olarak IRIX işletim sistemi çalışır ve amaç, güncel yazılımları değiştirilmeden bu donanımda çalıştırmaktır.

Hoca, cevapların doğru olduğunu ama makalenin dayandığı kritik bir anahtar kavramın söylenmediğini belirtti ve özet değil bu kavramı istediğini vurguladı. Ortak bellek, NUMA, ölçeklenebilirlik ve FLASH (makalede geçen makine) gibi cevaplardan sonra hoca kendisi açıkladı: makalede **dağıtık işletim sistemi** fikrine alternatif sunulmaktadır.

İşletim sistemlerini bu ölçeklenebilir çok işlemcili mimaride dağıtık hâle getirmek için mevcut işletim sistemlerinde çok ciddi değişiklik yapmak gerekir. Oysa oturmuş işletim sistemleri vardır, ama bunlar tek işlemcili ya da bu kadar büyük ölçeklenebilir ortamlar için tasarlanmamıştır. Yazarların önerisi bunun yerine bir sanallaştırma katmanı kullanmaktır.

### 2.3 Disco mimarisi

Hoca makalenin Şekil 1'ini (Architecture of Disco) sözlü olarak anlattı:

- **Alt katman:** Çok sayıda işlem elemanı (processing element, PE). Bunlar bir ara bağlantı (interconnect) ile birbirine bağlıdır ve yapı doğal olarak NUMA mimarisidir: her işlem elemanının kendi yerel belleği vardır, diğer belleklere de erişebilir ama bu erişim aynı hızda değildir.
- **Orta katman:** Disco, yani sanallaştırma katmanı.
- **Üst katman:** Kutular hâlinde işletim sistemleri: OS, SMP OS (simetrik çok işlemcili işletim sistemi) ya da küçük (thin) OS.

Hoca simetrik çok işlemcili sistemlerin iki, dört gibi az sayıda işlemciyle çalıştığını, SMP'de onlu ya da yüzlü işlemci sayılarının telaffuz edilmediğini hatırlattı. Disco'nun hedefi, çok daha fazla işlem elemanı olan ve rahatça ölçeklenebilen bir donanımın hızlıca kullanılabilmesini (utilize edilmesini) sağlamaktır. Bunun için de daha önce var olan sanal makine monitörü kavramına başvurulur.

### 2.4 Sanal makine monitörü yaklaşımının sorunları

Sanal makine monitörü bir yandan ölçeklenebilir çok işlemcili ortamı hızlıca ve kolayca kullanmamızı sağlar, öte yandan çözülmesi gereken sorunlar da getirir. Hoca bunları başlık şeklinde istedi. Kabul edilen cevap şu başlıklardı:

- Ek yük (overhead), yani sanallaştırmanın getirdiği ek maliyet
- Kaynak yönetimi (resource management)
- İletişim ve veri paylaşımı (communication and sharing)

Kaynak yönetiminin ne anlama geldiği konusunda daha somut bir cevap istendi; bir öğrenci "CPU diyebilir miyiz" diye sordu. Hoca açıkladı:

Kaynak CPU, bellek ya da G/Ç olabilir; mesele şudur: sanal makine monitörü, çalıştırdığı işletim sisteminin ne yaptığını bilmez. Komutlar gelir; ya doğrudan çalıştırılır ya da sanallaştırmanın gereğine göre değiştirilerek çalıştırılır. Ancak arka arkaya çalıştırılan komutların aslında üstteki işletim sisteminde bir meşgul döngüye (busy loop) karşılık geldiği ortaya çıkabilir. Yani işletim sisteminin o anda yapacak hiçbir işi yoktur, boşta meşgul bekleme (idle busy wait) yapmaktadır. VMM ise bunu çalıştırmak için kaynak tüketir. Konuk boşa vakit geçirdiğinden bu iş hiç yapılmayabilirdi.

VMM bunun farkına varmadığında, ya da farkına varmasını sağlayacak bir mekanizma olmadığında, alttaki işlemci kaynağı boşa harcanır ve VMM de boşuna çalışmış olur. Yazarların kaynak yönetimiyle kastettiği budur.

> **Hocanın vurgusu:** Bunu fark edip ona göre davranabilmek, paravirtualization'ın devreye girme noktalarından biridir.

### 2.5 Disco'da bellek yönetimi

Hoca, Şekil 1'de NUMA mimarisinden söz edildiğini hatırlatıp Disco'nun bellek yönetiminde nasıl bir yaklaşım izlediğini ve özellikle neye önem verdiğini sordu. Bir öğrenci makalenin sonuç kısmından şunu aktardı: Disco, DMA motorunun yenilikçi bir öykünmesi ile standart dağıtık dosya sistemi protokollerini birleştirerek bütün sanal makineler arasında saydam biçimde paylaşılan küresel bir tampon önbelleği (global buffer cache) destekler; bu yaklaşım büyük makinelerin sistem yazılımının karşılaştığı ölçeklenebilirlik, güvenilirlik ve NUMA bellek yönetimi sorunlarına basit bir çözüm sunar. Hoca bunun genel bir anlatım olduğunu belirtti.

<!-- BELİRSİZ: Hocanın bu soruya beklediği asıl cevap altyazıda anlaşılmıyor (yaklaşık 00:33:00-00:35:30 arası bozuk). -->

> **Ek bilgi (derste anlatılmadı):** Disco makalesi büyük olasılıkla NUMA'yı konuk işletim sisteminden gizlemek için dinamik sayfa göçü (page migration) ve sayfa çoğaltma (page replication) kullanır: sık erişilen sayfalar, onlara erişen işlemcinin yerel belleğine taşınır ya da salt okunur sayfaların yerel kopyaları oluşturulur. Böylece NUMA farkında olmayan bir ticari işletim sistemi de makul bir yerellikle çalışabilir.

## 3. VMware Workstation'da G/Ç Cihazlarının Sanallaştırılması

Üçüncü makale "Virtualizing I/O Devices on VMware Workstation's Hosted Virtual Machine Monitor" başlığını taşır ve 2001 tarihlidir; hocanın deyişiyle bundan yaklaşık 20 yıl öncesine aittir.

### 3.1 Barındırılan (hosted) mimari

Bir öğrenci makaleyi, VMware Workstation'ın yüklü işletim sistemini değiştirmek yerine kullanıcı düzeyinde bir VMM olarak çalıştığını, sanal makinenin bilgisayarda herhangi bir uygulama gibi açılabildiğini söyleyerek özetledi.

Hoca bunu açtı. Workstation kurulduğunda bir sanal makine monitörü yüklenir. Bu, işlemciyi sanallaştırmaya, yani işlemciyi farklı konuk işletim sistemleri arasında bölümlendirmeye yarar. Öte yandan Workstation bir de uygulama sunar; bu uygulama ana işletim sistemine yüklenmiş ek aygıt sürücülerinin sanal makineler tarafından kullanılabilmesini sağlar. Böylece bir tarafta CPU sanallaştırması, diğer tarafta G/Ç tarafında paravirtualization'a benzeyen bir yaklaşım vardır; ikisi bir aradadır.

Makalenin asıl konusu G/Ç cihazlarının sanallaştırılmasıdır. Yazarlar mevcut donanımın sanal bir karşılığını yazılımla işletim sistemine sunmak yerine, kendilerinin daha rahat destekleyebildiği bir aygıt sürücüsünü konuk işletim sistemine yükletir. Bu sürücü, makalenin Şekil 2'sinde görüldüğü gibi, ana işletim sistemindeki sürücüleri doğrudan kullanabilir hâle gelir.

### 3.2 Bileşenler

Şekil 2'deki bileşenler:

- **VMM (Virtual Machine Monitor):** Konuk işletim sistemini çalıştıran katman.
- **VMDriver:** Ana işletim sistemine yüklenen sürücü.
- **VMApp:** Ana işletim sisteminde çalışan yardımcı uygulama (helper application). Sanallaştırmaya yardımcı olur ve ana sistemdeki sürücülere onların anlayacağı dille, daha kolay erişir.

Hoca şekilde VMM, VMDriver ve VMApp'in aynı renkle (yeşil) işaretlendiğine dikkat çekti: bu üçü birbirine iş aktarabilir (paslaşabilir).

### 3.3 Ağ paketinin gönderilme ve alınma yolu (Şekil 4)

Şekil 4 bir ağ paketinin gönderilmesinde ve alınmasında izlenen yolu gösterir. Konuk işletim sistemi Intel mimarisindedir; Intel mimarisinde G/Ç portlarına IN ve OUT komutlarıyla erişilir.

Gönderme yolu:

```text
1. Konuk OS bir G/Ç portuna OUT komutu yürütür.
2. OUT ayrıcalıklı (privileged) bir komut olduğu için VMM'e yakalanır (trap).
3. VMM isteği ana sistemdeki VMDriver'a aktarır.
4. VMApp isteği alır ve ana sistemin ilgili sürücüsüne yönlendirir.
5. İlgili sürücü (örnekte Ethernet) OUT işlemini gerçek Ethernet kartında yapar.
```

Alma yolu:

```text
1. Ethernet donanımından kesme (interrupt) gelir.
2. Ana sistemde Ethernet sürücüsü devreye girer ve VMNet sürücüsünü tetikler.
3. VMNet sürücüsü VMApp'i tetikler.
4. VMApp gerekli işleri yapar (veriyi tampondan belleğe almak gibi) ve VMM'e aktarır.
5. VMM konuk OS'de bir kesme oluşturur.
6. Konuk OS bunu kendi IN/OUT komutunun ardından oluşmuş bir kesme sanır.
```

Konuk bir sonraki IN ya da OUT komutunu yürüttüğünde aynı yol izlenir. Özetle G/Ç gerçekte ana sistem tarafında, ana sistemdeki bir sürücü ve onunla birlikte çalışan bir uygulama tarafından yapılır; sonuç VMM üzerinden konuk işletim sistemine, ya da tersi yönde konuktan ana sisteme yansıtılır.

### 3.4 Gecikme ölçümü (Şekil 5)

Makalenin Şekil 5'i, 733 MHz'lik bir işlemcide konuk işletim sisteminin sanal bir AMD Lance ağ kartına verdiği ve fiziksel bir paket gönderimini başlatan OUT komutunun ana sistem ve VMM dünyalarında geçen yol boyunca harcadığı mikrosaniyeleri gösterir. Hocanın aktardığı değerler:

| Aşama (hocanın anlatımıyla) | Süre (µs) |
|---|---|
| OUT başlangıcından sonlanmasına kadar toplam | 31,63 |
| Bağlam değiştirme (context switch) | 4,45 |
| VMApp'in gerekli işleri | 1,23 |
| VMNet sürücüsü | 17,55 |
| Dönüşte VMApp'in diğer işleri | 2,97 |
| VMM'e girilip geri dönülmesi | 0,57 |

<!-- BELİRSİZ: Değerler altyazıdan alındı; ekranda makale gösterilmediği için karelerden doğrulanamadı. -->

Hoca, normalde bir OUT komutunun çok çok daha hızlı olduğunu, bu yolda ise toplam 31,63 mikrosaniyelik bir gecikme oluştuğunu belirtti. VMM'e girilip çıkılması ise bir mikrosaniyenin altındadır.

> **Ders sonrası not:** Tabloda sayılan beş kalemin toplamı $4{,}45+1{,}23+17{,}55+2{,}97+0{,}57 = 26{,}77$ µs'dir; 31,63 µs'lik toplamın kalanı büyük olasılıkla derste sayılmayan başka aşamalara aittir.

Makalede ayrıca toplam zamanın yüzde kaçının nerede harcandığı ve farklı paket boyutları için yerel ile sanal makine arasındaki iş hacmi (throughput) farkı gösterilmiştir.

## 4. Sanal Makineler ile Linux Konteynerlerinin Performans Karşılaştırması

Dördüncü makale sanal makineler ile Linux konteynerleri arasında bir performans karşılaştırmasıdır.

### 4.1 Makalenin katkıları

**Soru:** Bu makalenin katkıları neler?

**Cevap:** Öğrencilerin cevabına göre makale, yerel (native) ve sanal makine karşılaştırmalarına güncel bir sürüm eklemek amacıyla yazılmıştır. Konteyner tabanlı yaklaşım (Docker) ile sanal makine yaklaşımı karşılaştırılır; görev yalıtımı ve iş yükleri arasında kaynak dağıtımı incelenir. CPU, bellek, depolama ve ağ kaynakları farklı iş yükleriyle sınanmış ve konteynerlerin sanal makinelere eşit ya da onlardan daha iyi olduğu sonucuna varılmıştır.

### 4.2 KVM ve Xen farkı

Makalede sanallaştırma ortamı olarak Linux üzerinde KVM kullanılır. Hoca KVM'nin Xen'den farkını sordu. Öğrenci, makalede KVM'nin Linux üzerinde çalışan bir hipervizör olarak tanımlandığını, konuk işletim sistemlerinin değiştirilmeden çalıştırılabildiğini ve KVM'nin karmaşıklığı ve ek yükü azaltmak için işlemcideki donanım sanallaştırma desteğini kullandığını söyledi. Hoca bunu doğruladı: Xen ortaya çıktığında işlemcilerde henüz sanallaştırma desteği yoktu.

> **Ek bilgi (derste anlatılmadı):** Donanım sanallaştırma desteği Intel'de VT-x, AMD'de AMD-V adıyla 2005-2006 civarında büyük olasılıkla yaygınlaştı. Bu destek sayesinde konuk çekirdeği değiştirmeden, ayrıcalıklı komutların donanım tarafından VMM'e yönlendirilmesiyle tam sanallaştırma verimli yapılabilir; Xen'in ilk sürümü ise bu destek olmadığı için paravirtualization'a dayanıyordu.

### 4.3 Karşılaştırma kategorileri ve HPC

Karşılaştırma CPU, bellek bant genişliği, bellek gecikmesi, ağ bant genişliği ve G/Ç bant genişliği gibi ölçütlerle yapılır. Hoca bunlara ek olarak farklı bir yük tipinin de incelendiğini sordu; cevap HPC (High Performance Computing, yüksek başarımlı hesaplama) idi.

> **Hocanın vurgusu:** Normalde sanallaştırma HPC'nin baş düşmanıdır; araya bir katman koyarsınız ve işler öyle ya da böyle yavaşlar. Makale bunu da hesaba katıp incelemiştir.

HPC yükü olarak Linpack kullanılmıştır. Hocanın aktardığı sonuçlar:

| Ortam | Linpack sonucu |
|---|---|
| Yerel (native) | 290,8 |
| Docker | 290,9 |
| KVM, ayarlanmamış (untuned) | 241,3 |
| KVM, ayarlanmış (tuned) | 284,2 |

<!-- BELİRSİZ: Değerler altyazıdan alındı; ekranda gösterilmediği için karelerden doğrulanamadı. Birim derste söylenmedi (makalede büyük olasılıkla GFLOPS). -->

Yerel ile Docker arasındaki fark (290,8 ile 290,9) istatistiksel ölçüm oynamasıdır. Ayarlanmış KVM'de kayıp $1 - 284{,}2/290{,}8 \approx \%2{,}3$, yani hocanın söylediği gibi yaklaşık %2'dir. Ayarlanmamış KVM'de kayıp $1 - 241{,}3/290{,}8 \approx \%17$'dir (ara adım eklendi).

> **Hocanın vurgusu:** Bu, sanal ortamlarda da yüksek başarımlı hesaplama yapılabileceği anlamına gelir; bunun için illa çıplak donanıma (bare metal) ihtiyaç yoktur.

Nedeni şudur: sanallaştırma katmanı özel (ayrıcalıklı) komutlarda, bellek erişimi ve G/Ç erişimiyle ilgili komutlarda devreye girer. Aritmetik, mantık ve kayan nokta işlemlerinde devreye girmez. Bu yüzden matematiksel işlem yoğun yüklerde konteyner kullanılırsa hiç, KVM kullanılırsa çok az (yaklaşık %2) etkilenilir.

### 4.4 PXZ, rastgele erişim ve STREAM

**Soru:** PXZ neye karşılık geliyor?

**Cevap:** PXZ paralel bir sıkıştırma aracıdır (sıkıştırma ve açma işi). Hoca bunun, o dönemde bulut iş yüklerinde yapılan incelemelerde bol miktarda görülen sıradan bir iş yükü olduğunu söyledi.

Deneyde 1 GB'lık bir Wikipedia dökümü 32 iş parçacığıyla sıkıştırılmıştır. Sonuç, hocanın deyişiyle "esas çarpıcı" kısımdır: KVM'de oransal olarak yaklaşık %22 daha düşük performans, Docker'da yaklaşık %4'lük bir düşüş elde edilmiştir. Hoca bu sırada önce "yüzde puan" deyip kendini düzeltti: yüzde puan olarak fark 14, oransal fark %22'dir.

<!-- BELİRSİZ: PXZ değerleri ekranda gösterilmedi; yüzde puan ve oran açıklaması altyazıdan, karelerden doğrulanamadı. -->

Rastgele bellek erişiminde (Random Access) ortamlar hemen hemen aynıdır. STREAM ölçümlerinde de (Intel işlemcilerde vektör ve matris işlemlerinin hızlı yapılmasıyla ilgili add, copy, scale, triad işlemleri) neredeyse hiç fark yoktur; KVM ayarlanmadan bile sonuçlar aynı çıkmıştır. Hocanın aktardığına göre ayarlanmış KVM'de burada ters bir sonuç alınmış, ayarlanmamış sürümün sonuçları ise yerel ile hemen hemen aynı çıkmıştır. Makalede ayrıca ağ yapılandırmaları da gösterilmiştir.

> **Ek bilgi (derste anlatılmadı):** STREAM, bellek bant genişliğini dört basit vektör çekirdeğiyle ölçen bir kıyaslama testidir: copy ($a_i = b_i$), scale ($a_i = q\,b_i$), add ($a_i = b_i + c_i$) ve triad ($a_i = b_i + q\,c_i$).

## Örnek Sorular

Derste ekranda soru gösterilmedi; aşağıdaki sorular hocanın sözlü olarak sorduğu sorulardır.

1. (derste sözlü, 00:02:07) Xen makalesine göre Xen'in Denali'den farkları nelerdir?
   > **Cevap (derste):** Denali mevcut ABI'leri hedeflemez; tek bir konuk içinde uygulama çoğullama ve çoklu adres alanı desteğini ele almaz (her sanal makine tek kullanıcılı, korumasız bir OS barındırır, Xen'de ise binlerce kullanıcı süreci çalışabilir); Denali'de VMM bütün sayfalamayı diskten kendisi yapar.

2. (derste sözlü, 00:07:01) Paravirtualization nedir?
   > **Cevap (derste):** Konuktan gelen isteğin basit bir çeviriyle VMM'in ya da ana sistemin var olan sürücüsüne aktarılmasıdır; donanımın birebir yazılım taklidi olan tam sanallaştırmadan daha ucuzdur.

3. (derste sözlü, 00:08:46) Bir G/Ç cihazının bütün donanımsal özelliklerini yazılımla üst katmana yansıtıyorum ve üst katman bir yazılımla muhatap olduğunu bilmiyor. Bu tam sanallaştırma mı, paravirtualization mı?
   > **Cevap (derste):** Tam sanallaştırma.

4. (derste sözlü, 00:11:17) ABI nedir, Xen için önemi nedir?
   > **Cevap (derste):** İkili uyumluluktur; uygulamaların derlenmiş çalıştırılabilir dosyalarının değiştirilmeden çalışması. Korunmazsa yeniden derleme ya da ikili çeviri gerekir.

5. (derste sözlü, 00:14:28) Bir işletim sisteminin Xen'e taşınma maliyeti ne demektir?
   > **Cevap (derste):** İşletim sisteminin Xen altında çalışması için yapılması gereken değişikliklerdir; örneğin sanal aygıt sürücüleri sağlamak, bellek yönetimini değiştirmek.

6. (derste sözlü, 00:17:42) Commodity işletim sistemi nedir?
   > **Cevap (derste):** İkili, kurulabilir biçimde sunulan, satın alınıp ya da indirilip değişiklik yapmadan kullanılan işletim sistemidir.

7. (derste sözlü, 00:21:05) Disco makalesinin anahtar kavramı nedir? Disco neye alternatif sunar?
   > **Cevap (derste):** Ölçeklenebilir çok işlemcili mimaride işletim sistemlerini dağıtık hâle getirmeye (çok ciddi değişiklik gerektirir) alternatif olarak, VMM üstünde var olan ticari işletim sistemlerini çalıştırmak.

8. (derste sözlü, 00:26:11) Sanal makine monitörü yaklaşımının çözülmesi gereken sorunları nelerdir? Kaynak yönetimi sorunu neyi kasteder?
   > **Cevap (derste):** Ek yük, kaynak yönetimi, iletişim ve veri paylaşımı. Kaynak yönetiminde VMM, konuğun boşta meşgul döngü çalıştırdığını bilemediği için gerçek işlemciyi boşa harcar.

9. (derste sözlü, 00:49:20) Sanal makine ve Linux konteyner karşılaştırması makalesinin katkıları nelerdir, hangi sanallaştırma ortamı kullanılmıştır, KVM'nin Xen'den farkı nedir?
   > **Cevap (derste):** Docker ile KVM'nin yerel çalışmayla CPU, bellek, ağ ve G/Ç ölçütleriyle güncel karşılaştırması; ortam KVM'dir; KVM işlemcinin donanım sanallaştırma desteğini kullanır, Xen ortaya çıktığında bu destek yoktu.

10. (derste sözlü, 00:52:54) Makalede bu ölçütlerin dışında hangi farklı yük tipi incelenmiştir?
    > **Cevap (derste):** HPC (Linpack). Ayarlanmış KVM'de kayıp yaklaşık %2'dir.

## Dersin Toparlaması

Bu derste dört sanallaştırma makalesi tartışıldı. Xen makalesi üzerinden tam sanallaştırma ile paravirtualization ayrımı, ABI uyumluluğunun önemi ve bir işletim sistemini sanallaştırma ortamına taşımanın maliyeti ele alındı. Disco makalesinde, NUMA tabanlı ölçeklenebilir çok işlemcili makinelerde işletim sistemini dağıtık hâle getirmek yerine bir sanal makine monitörü üstünde birden çok ticari işletim sistemi çalıştırma fikri ve bu yaklaşımın ek yük, kaynak yönetimi, iletişim ve paylaşım sorunları incelendi. VMware Workstation makalesinde, barındırılan mimaride G/Ç'nin VMM, VMDriver ve VMApp iş birliğiyle ana sistemin sürücüleri üzerinden yapıldığı ve bunun mikrosaniye düzeyindeki maliyeti görüldü.

Son makalede konteynerlerin hemen hemen yerel performans verdiği, ayarlanmış KVM'nin hesaplama yoğun HPC yüklerinde bile çok az kayıp yaşadığı, sıkıştırma gibi bellek ve G/Ç ağırlıklı yüklerde ise sanallaştırma kaybının belirginleştiği anlatıldı. Ortak ders şudur: sanallaştırma katmanının maliyeti, ayrıcalıklı komutların, bellek ve G/Ç erişimlerinin ne sıklıkla araya giren katmana uğradığına bağlıdır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
