# Ders 26 Genişletilmiş Notu: İşletim Sistemleri (Paging, Boot, Süreç Yönetimi) ve Bilgisayar Ağları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Planı ve Çekirdeğin Görevleri
- 2. Sayfalama ve Sanal Bellek
- 3. Firmware
- 4. Açılış Süreci
- 5. Makinenin Etkinliklerinin Koordinasyonu
- 6. Kilitlenme (Deadlock)
- 7. Çok Çekirdek, Güvenlik ve Kullanıcı Yönetimi
- 8. Süreç Geçişi, Çok Çekirdek ve 32/64 Bit Üzerine Sorular
- 9. Ara Sırasında Gelen İki Soru: Konuşmadan Yazıya ve Rastgele Sayı
- 10. Bilgisayar Ağları ve Ölçeğe Göre Sınıflandırma
- 11. Ağ Topolojileri
- 12. Ağları Büyüten Cihazlar: Repeater, Bridge, Switch
- 13. Router ve Switch ile Farkı
- 14. Protokoller ve OSI Modeli
- 15. Forwarding Table ve İnternet Trafiği
- 16. Süreçler Arası İletişim
- 17. Bulut Bilişim
- 18. İnternet, İntranet ve Servis Sağlayıcılar
- 19. IP Adresleri ve Alan Adı Sistemi
- 20. Dersin Sonundaki Sorulardan C Dili Notları

## 1. Dersin Planı ve Çekirdeğin Görevleri

Hoca bu derste önce işletim sistemi konusuna devam edeceğini, ardından ağ ve internet konusuna geçeceğini söyledi. Bu konularda kısa kısa bilgi verileceğini, bilgilerin bir kısmını daha önce ilgi duyanların biliyor olabileceğini, ama herkesin bilmediği bir şeyler de öğreneceğini ekledi.

Önceki derste çekirdekte (kernel) kalınmıştı. Temel görevlerin hepsini aslında çekirdek yürütür:

- Süreç yönetimi (process management)
- Bellek yönetimi (memory management)
- Dosya yönetimi (file management)
- Giriş-çıkış yönetimi (I/O management)
- Ağ yönetimi (network management)
- Aygıt sürücüleriyle (device driver) iletişim

## 2. Sayfalama ve Sanal Bellek

### 2.1 RAM Yetmediğinde Ne Olur?

Donanım olarak RAM'iniz yeterli olmadığında bir sanal bellek (virtual memory) yaratılır. Bu sanal bellek, ikincil depolama (secondary storage) tarafında oluşturulur ve sayfalama (paging) yaklaşımıyla çalışır.

Hocanın örneği şöyledir:

- **Verilen:** Elinizde 4 GB'lık bir RAM var. Açmaya çalıştığınız program, ilgili dosyalarıyla birlikte 8 GB'lık bir alan gerektiriyor.
- **İşlem:** 8 GB'ın bir kısmı RAM'e yüklenir, bir kısmı ikincil depolamada saklanır. RAM en fazla 4 GB alabildiği için en az $8 - 4 = 4$ GB'lık kısım her an RAM'in dışındadır (ara adım eklendi).
- **Sonuç:** RAM ile ikincil depolama arasında sürekli bilgi alışverişi yapılarak 8 GB'lık program RAM üzerinden çalıştırılabilir.

Bu mekanizma olmasaydı, elinizdeki RAM kapasitesinden büyük programların hiçbirini çalıştıramazdınız.

> **Hocanın vurgusu:** RAM'den büyük programların çalıştırılabilmesini sağlayan bu mekanizma önemlidir.

Bu işlemi yürütmek bellek yöneticisinin (memory manager) görevlerinden biridir. Yönteme sayfalama denmesinin sebebi, verinin sayfalara (page) bölünmesidir. Sayfalar genelde birkaç yüz byte ya da birkaç kilobyte büyüklüğündedir ve RAM ile ikincil depolama arasında sürekli taşınır. Programın ilgili bölümü çalıştırılacağı zaman o bölüm RAM'e gelir. Böylece RAM'in boyutu yetmese bile iş gerçekleştirilmiş olur.

<!-- BELİRSİZ: 00:07:33'te altyazı "birkaç yüz ya da birkaç kilovayt" diyor; "birkaç yüz" sözündeki birim söylenmemiş, kısa nottaki gibi byte kabul edildi. -->

### 2.2 Disk Dolunca Gelen Yavaşlama Sayfalama mıdır?

**Soru:** Sabit diskin sistem bölümünde boş alan yüzde 10'un altına düştüğünde bütün makine yavaşlıyor. Bu da sayfalama olarak mı tanımlanır?

**Cevap:** Hoca bunu sayfalama olarak yorumlamamak gerektiğini söyledi. Büyük bir dosya açıyorsanız elbette sayfalamayla ilgisi vardır. Ama buradaki asıl mesele, giriş-çıkış işlemi yaparken diskin çok dolmuş olmasıdır. Programların diske yerleşimi dağınık hâle gelir. Mekanik bir diskte erişim, kafanın bir noktadan başka bir noktaya hareketine bağlı olduğu için bu hareket uzun sürer ve yavaşlama olur. Veriler parçalar (chunk) hâlinde saklandığı için eski mekanik disklerde bu yavaşlama görülürdü. SSD'de ise bu durum pek yaşanmaz.

Soruyu soran öğrenci, kendi makinesinde 120 GB'lık bir SSD'nin dolmaya yaklaştığında yavaşladığını, boşaltınca düzeldiğini ve 16 GB RAM olduğunu aktardı. Hoca, RAM miktarının yüksek olduğunu ve sorunun RAM'den kaynaklanmadığını düşündüğünü, diskte böyle bir sayfalama yapısı bilmediğini, kendi SSD'li cihazında belirgin bir yavaşlamaya rastlamadığını, ama konuya bakacağını söyledi.

> **Ek bilgi (derste anlatılmadı):** İşletim sistemi sanal bellek için ayırdığı alanı büyük olasılıkla sistem bölümünde tutar, bu yüzden o bölüm çok dolduğunda bu alan da daralabilir. SSD'ler de büyük olasılıkla çok dolu hâlde yazma işlemlerinde yavaşlayabilir, çünkü yeni veri yazmadan önce boş blok hazırlamaları gerekir. Dolayısıyla öğrencinin gözlemi büyük olasılıkla mekanik kafa hareketinden kaynaklanmıyordur.

## 3. Firmware

### 3.1 Tanım

Hoca firmware'in ne olduğunu sınıfa sordu. Öğrencilerden "sistemlerin içindeki parçaların çalışmasını sağlayan temel yazılım" gibi cevaplar geldi. Hoca bu tabirlerin çok yanlış olmadığını söyleyip tanımı şöyle netleştirdi: Firmware, işletim sistemi olmadan cihazın temel giriş-çıkış (basic I/O) etkinliklerini gerçekleştirebilmesini ve açılış (boot) sırasında, yani işletim sistemini yüklerken gereken temel işleri yapabilmesini sağlayan yazılımdır.

<!-- BELİRSİZ: 00:11:17'de hoca "şu tanımı da yazalım" diyerek bir tanım yazıyor; yazılan metin altyazıda yok. -->

### 3.2 Firmware Güncellemesi

**Soru:** Firmware güncellemesi cihazlarda ne işimize yarar?

**Cevap:** Bir öğrenci, daha önce var olan donanımın bazı kabiliyetlerinden faydalanılamadığını, güncellemeyle aynı donanımın daha fazla kabiliyetinden faydalanıldığını söyledi. Hoca bunu çok güzel bir tanım olarak kabul etti: Donanımda zaten bulunan ama kullanamadığınız yetenekleri yeni bir firmware güncellemesinden sonra kullanabilirsiniz.

Örnek olarak akıllı televizyonlara zaman zaman gelen firmware güncellemelerini verdi. Bir başka örnek Android'di: Çoklu dokunma (multi-touch) donanım olarak destekleniyordu, ama bu yetenek sisteme henüz kazandırılmamıştı. Firmware güncellemeleri PC'lerde de yaşanır, ama farkı daha etkin biçimde gömülü sistemlerde görürüz. Güncelleme sonunda donanımsal kabiliyeti yazılımla birlikte gerçek hayata uyarlamış olursunuz.

### 3.3 BIOS ve Diğer Firmware Sistemleri

Bilgisayardaki bilinen en temel firmware sistemi BIOS'tur (Basic Input Output System). Zaman içinde başka firmware'ler de ortaya çıkmıştır:

- Extensible Firmware Interface (EFI)
- Sun'ın, bugün Oracle'ın ürünü olan Open Firmware
- Common Firmware Environment

Hoca, PC'lerde ağırlıklı olarak BIOS kullanıldığını söyledi. BIOS sayesinde cihaz işletim sistemi olmadan açılır ve temel görevlerini yerine getirir. Hangi aygıttan açılacağının sırası burada belirlenir. RAM ve işlemciyle ilgili ayarlar yapılacaksa bu da BIOS üzerinden gerçekleştirilir.

> **Ders sonrası not:** Hoca PC'lerde ağırlıklı olarak BIOS kullanıldığını söyledi; yeni PC'lerde bugün büyük olasılıkla EFI'nin devamı olan UEFI kullanılmaktadır. Görevleri bu bölümde anlatılanlarla büyük olasılıkla aynı temel amaca hizmet eder.

> **Hocanın vurgusu:** Firmware bir cihaz için çok önemlidir.

## 4. Açılış Süreci

Açılış sürecine (booting process) açık hâliyle önyükleme (bootstrapping) denir. Hocanın çizdiği şekilde ana bellek (main memory) iki ayrı parça gibi düşünülür, yanında da disk bulunur:

- **ROM (Read Only Memory):** Açılışı yapılandıran önyükleyici (bootloader) burada durur.
- **Uçucu bellek (volatile memory):** Elektrikle çalışır, bilgiyi yalnızca elektrik olduğu sürece saklar.
- **Disk (disk storage):** İşletim sistemi her zaman burada yüklü durur.

Açılış başladığında işletim sistemi ikincil depolamadan belleğe aktarılır. Bundan sonra bütün işlemler bellekteki işletim sistemi üzerinden yönetilir.

### 4.1 ROM Gerçekten Salt Okunur mu?

Read Only Memory, adı üstünde üzerine yazılamayan ve bir kez oluşturulan bir birimdir. Fakat günümüzde kullanılanlar silinip yeniden programlanabilen türdendir (Erasable Programmable Read Only Memory). Böylece önyükleyicide, belirli bir yazma sayısı kadar değişiklik yapılabilir. Eskiden bu mümkün değildi. Yine de RAM'e istediğiniz zaman yazıp tekrar kullandığınız gibi sürekli yazılamaz, çünkü yazma sayısı sınırlıdır. Bu, şu anda flash bellek (flash memory) tekniğiyle uygulanır. Yani ROM ihtiyaç olduğunda belirli miktarda yeniden değiştirilebilir. ROM'da yapılan güncellemelere genelde firmware güncellemesi (firmware update) denir.

> **Ders sonrası not:** Altyazıda hoca "EPROM" ve "Erasable Programmable Read Only Memory" diyor, kısa notta ise tahtada "EEPROM" yazdığı kaydedilmiş. Flash tekniğiyle yeniden yazılabilen bellek büyük olasılıkla elektrikle silinebilen EEPROM ailesindendir; EPROM ise büyük olasılıkla morötesi ışıkla silinen eski türdür.

<!-- BELİRSİZ: 00:21:01-00:21:27 arasında tahtaya yazılan kısaltmanın EPROM mu EEPROM mu olduğu altyazıdan kesinleştirilemiyor. -->

### 4.2 İşletim Sistemi Neden ROM'da Tutulmaz?

Hoca şu soruyu kendisi ortaya attı: Madem bu yükleme mekanik disklerde uzun sürüyor (SSD'lerde kısa sürüyor), çünkü bütün programın depolamadan belleğe alınmasını gerektiriyor, neden işletim sistemini ROM'da tutmuyoruz da her seferinde diskten belleğe yüklüyoruz?

İki sebebi vardır. Birincisi, ROM belirli bir boyuta sahiptir. İkincisi, işletim sistemi zaman içinde sürekli değişir: Yeni yetenekler kazanır ve güvenlik açıklarını gidermek için güncellenir. Böyle bir yazılımı ROM bölgesinde tutmak doğru değildir.

Gömülü sistemlerde ise bu mantıklı olabilir. Orada işletim sistemi ya da işletim sistemi gibi çalışacak program doğrudan ROM'a konur. Cihaz kendiliğinden buradan çalışmaya başlar ve uçucu bellek üzerinden görev alır.

## 5. Makinenin Etkinliklerinin Koordinasyonu

### 5.1 Süreç ve Süreç Durumları

Bir programın işlemci tarafından çalıştırılacak hâle dönüştürülmüş versiyonuna süreç (process) denir. Örneğin Word bir programdır. Onu çalıştırılabilir hâle getirdiğinizde bir etkinliğe dönüştürmüş olursunuz ve bu artık süreç olarak adlandırılır.

Her sürecin bir durumu (process state) vardır. Temel olarak iki konumdan söz edilir:

- **Hazır (ready):** İşlem görmeye hazırdır. İşlemci müsait olduğunda bu süreçleri alır ve kullanır.
- **Bekleyen (waiting):** Bir cevap bekliyordur. Bu cevap giriş-çıkıştan, ağdan ya da başka bir süreçten gelebilir. Bu durumdaki süreçler işlemci tarafından işleme alınacak durumda değildir.

### 5.2 Süreç Tablosu

İşletim sisteminin süreçleri takip ettiği yapı süreç tablosudur (process table). Bu tabloda sürece ait tüm bilgiler, yani hangi noktada kalındığı ve en son hangi değerlere sahip olduğu saklanır. İşlemci bu sürece tekrar geldiğinde işe nereden devam edeceğini buradan bilir. Bu bilgiler bir yerde saklanmasaydı, süreçleri yarıda bırakıp başka bir sürece geçme şansımız olmazdı.

### 5.3 Süreç Geçişi ve Zaman Dilimi

Süreçler arası geçişe süreç geçişi (process switch) ya da bir başka adıyla bağlam geçişi (context switch) denir. İşlemci, milisaniye ya da mikrosaniye düzeyindeki zaman dilimlerini (time slice) kullanarak birden fazla programı aynı anda çalıştırma yeteneğine sahiptir. Geçiş algılayamayacağınız kadar hızlı olduğu için programların kesintisiz çalıştığını düşünürsünüz. Aslında bilgisayarınızda açık olan bütün programlar süreç olarak işlemcide sürekli geçiş yapar. Siz aradaki kesintiyi anlamadan müziği dinler, yazdığınız yazıyı ekranda görür ve arka planda bir şey indirmeye devam edersiniz.

Çok fazla ve sık süreç geçişi performansı belli oranda düşürür. Çünkü her geçişte süreç tablosuna yükleme yapmanız ve tablodan son hâli almanız gerekir.

Hoca bunu hayatımızla karşılaştırdı: İşler arasında ne kadar çok geçiş yaparsanız verimliliğiniz o oranda düşer. Herkes aynı derecede etkilenmeyebilir, ama çoğu insan tek bir işe konsantre olduğunda daha başarılı olur. Elinde 20 iş olan biri sürekli aralarında geçiş yaptığında en son nerede kaldığını hatırlamak ve düşünce sistemini yeni işe göre evirmek zorundadır. Bu yüzden bağlam geçişinin çok fazla olması sevdiğimiz bir durum değildir.

### 5.4 Dağıtıcı

Kuyruktaki süreçler, zaman dilimi değiştikçe kuyruk yönetimini (queue management) yapan bir dağıtıcı (dispatcher) tarafından alınır ve işlemciye aktarılır.

### 5.5 Kesme

Böyle bir düzende her zaman diliminde bir kesme (interrupt) oluşturulması gerekir.

**Soru:** Kesme nedir?

**Cevap:** Bir öğrenci, işlemcide çalışan bir işlemin kesintiye uğraması olduğunu söyledi. Hoca onayladı.

**Soru:** İşlemcideki bir işlemin kesintiye uğramasına neden ihtiyaç duyulur?

**Cevap:** Aynı öğrenci, işlem kesintiye uğramazsa başka bir işleme geçilemeyeceğini ve işlerin aynı anda yürütülemeyeceğini söyledi. Hoca bu cevabı da onayladı.

Hoca klavye örneğini verdi: Klavyeden girilen değerin okunması gerekir. Kesmeleri karşılayan mekanizmaya kesme işleyici (interrupt handler) denir. İşlemciye bu kesme gönderilmezse, klavyeden bilgi giren kişi bastığı tuşun kaydedilmediğini ve işlenmediğini görür. Benzer şekilde dağıtıcı süreçleri değiştirecektir, ama kesme gönderilmezse işlemci elindeki işi bırakmaz. Fare tıklaması da kesme oluşturan bir eylem olarak düşünülebilir.

İşlemci bir kesme sinyali aldığında (farklı kesme sinyalleri vardır) şu sırayla davranır:

1. Elindeki döngüyü (cycle) tamamlar. Örneğin bir toplama işlemi 3 döngü sürüyorsa, o 3 döngüyü bitirir ve komut işini tamamlar.
2. Nerede kaldığını süreç tablosuna işaretler.
3. Kesme işleyici aracılığıyla yeni kesmeye karşılık verir ve ilgili işin yapılmasını sağlar.

Çoklu programlama (multi-programming) genellikle bu şekilde ilerler: Bir bağlam geçişi mekanizması ve kesmeler vardır, zaman dilimleri de farklı süreçler tarafından kullanılır.

Kısa nota göre hocanın bu noktada tahtaya yazdığı tanım şudur: "Interrupts provide an important tool for coordinating a computer's actions with its environment."

<!-- BELİRSİZ: 00:32:22-00:33:05 arasında tahtaya yazılan metin altyazıda yok; yukarıdaki cümle kısa nottan alındı. -->

## 6. Kilitlenme (Deadlock)

Süreçler aynı kaynağa ihtiyaç duyduğunda ya da birbirlerinin sahip olduğu kaynağı kullanmak istediğinde kilitlenme (deadlock) oluşabilir. Hoca çok ayrıntı vermeyeceğini söyleyip şu örneği kullandı: Bir süreç yazıcıyı (printer), diğer süreç CD oynatıcıyı (CD player) kullanıyor olsun. Aynı anda yazıcıyı kullanan CD oynatıcıyı, CD oynatıcıyı kullanan yazıcıyı isterse kilitlenme oluşur. İkisi de bir sonraki adımda diğer kaynağa ihtiyaç duyduğu için elindeki kaynağı bırakmaz ve sistem tıkanır.

Bu yüzden paylaşılan kaynakların kilitlenme oluşturmayacak şekilde yönetilmesini sağlayan bir mekanizma olması gerekir. Hoca bu mekanizmalar hakkında ileride daha fazla bilgi sahibi olunacağını söyledi.

> **Hocanın vurgusu:** Kilitlenme kavramı önemlidir: İki süreç birbirinin elindeki kaynağa ihtiyaç duyar, ikisi de kendi kaynağını bırakmaz ve sistem tıkanır.

## 7. Çok Çekirdek, Güvenlik ve Kullanıcı Yönetimi

İşlemciler çok çekirdekli (multi-core) hâle geldiği için çok çekirdekli işletim sistemleri ortaya çıkmaktadır. Tek çekirdekteki süreç yönetimi ile çok çekirdekteki süreç yönetimi aynı değildir, çünkü süreçlerin farklı çekirdekler arasındaki bilgi değişiminin de koordine edilmesi gerekir. Bu yeni donanımsal yapıya uygun işletim sistemleri zaman içinde geliştirilmektedir.

Hoca, güvenlikle ilgili çok önemli noktalar olduğunu, ama bunun ayrı bir konu olduğu için girmeyeceğini söyledi.

İşletim sistemleri kullanıcı yönetiminden de sorumludur. Bir PC'de birden fazla kullanıcı hesabı olabilir. Bu hesapların dosyaları birbirinden bağımsız hâle getirilir ve kullanıcıların birbirinin yaptığı işi görmesi engellenir, ama hoca bu hesapların aynı anda aktif olamadığını söyledi. Sunucularda ise birden fazla kullanıcı aynı anda bilgisayarın kaynaklarını aktif olarak kullanabilir. Bunu yönetmek ayrı bir işletim sistemi tasarımı gerektirir. PC işletim sistemleri ile sunucu işletim sistemleri bu anlamda birbirinden ayrılır.

> **Ders sonrası not:** Hoca PC'de aynı anda yalnızca bir kullanıcının aktif olabildiğini söyledi; bu büyük olasılıkla tipik masaüstü kullanımını anlatan bir sadeleştirmedir, çünkü güncel PC işletim sistemleri büyük olasılıkla birden fazla açık oturumu aynı anda tutabilir. Sunucuda "herkesin tüm kaynaklara erişmesi" de büyük olasılıkla yalnızca verilmiş yetkiler çerçevesinde geçerlidir.

## 8. Süreç Geçişi, Çok Çekirdek ve 32/64 Bit Üzerine Sorular

**Soru:** Süreç geçişine bir daha değinebilir misiniz?

**Cevap:** İşlemci bir zaman diliminde bir süreci çalıştırırken, o süreç tamamlanmadan başka bir zaman dilimine geçilebilir. Çoklu görev (multitasking) özelliğini sağlamak için diğer sürecin kaldığı yer süreç tablosundan okunur, mevcut sürecin o andaki durumu da tabloya kaydedilir. Bu sırada gerçekleşen işlemlere bağlam geçişi ya da süreç geçişi denir.

**Soru:** Başka bir pencereye geçtiğimizde arkadaki penceredeki işlem devam ediyor mu, yoksa bırakıldığı yerde mi duruyor?

**Cevap:** Hoca, işlemcinin diyelim ki o anda bir toplama işlemi yaptığını anlattı. Toplama bitince o döngü tamamlandığı için işlemci o zaman diliminde süreci bırakır ve kuyruktaki sıradaki süreci alır. O sırada bahsedilen süreç müzik çalmaysa müzik çalma, Word'de metin yazmaysa metin yazma, bir editörde yazıyorsanız o yazma işi durur. Bu duraklamalar milisaniye ya da mikrosaniye düzeyinde olduğu için algılanamaz. Siz fark edene kadar süreç yeniden çalışmış olur. Böylece kesintisiz bir hizmet alırsınız.

> **Ders sonrası not:** Hoca toplama bitince zaman diliminin bittiğini ve işlemcinin süreci bıraktığını söyledi; doğrusu büyük olasılıkla, bir zaman diliminde çok sayıda komut çalışır ve zaman dilimi kesmeyle sona erer. Komutun tamamlanması, Bölüm 5.5'te anlatıldığı gibi işlemcinin kesmeye karşılık verebildiği noktadır, tek başına zaman dilimini bitiren olay değildir.

**Soru:** Bilgisayarda ya da telefonda kullandığımız modern işletim sistemleri işlemcinin çok çekirdek kabiliyetinden faydalanıyor mu?

**Cevap:** Faydalanıyor. Son yıllarda ortaya çıkan işletim sistemleri bu yetenekleri kullanacak şekilde tasarlanıyor. Hoca, asıl vurgulamak istediği şeyin bu olduğunu söyledi. Eskiden işletim sistemlerinin çok çekirdek yetenekleri yoktu. Var olan yetenekleriyle donanımı kullanabiliyorlardı, ama tam bir çok çekirdekli yapıda çalışmadıkları için performansları düşük oluyordu.

Hoca bunu 32/64 bit ilişkisine benzetti. Önce konuyu ters söylediğini fark edip düzeltti. Doğru ifade şöyledir: 64 bit donanım üzerinde 32 bit işler yapabilirsiniz, ama 32 bit donanım üzerinde 64 bit yazılımla iş yapma şansınız yoktur. Hoca bir ara böyle bir geçiş dönemi olduğunu, artık bunların tamamen ayrıldığını, 32 bit üzerinde 32 bit işletim sistemi, 64 bit üzerinde de 64 bit işletim sistemi kullanılması gerektiğini ekledi.

> **Ders sonrası not:** Hoca 64 bit donanımda 64 bit işletim sistemi kullanılması gerektiğini söyledi. Bu, yukarıdaki "64 bit donanımda 32 bit iş yapılabilir" cümlesiyle birlikte okunmalıdır: 64 bit işletim sistemi bu donanımdan tam yararlanmak için büyük olasılıkla doğru seçimdir, ama birçok 64 bit işlemcide 32 bit yazılım ve 32 bit işletim sistemi de büyük olasılıkla çalışabilir.

## 9. Ara Sırasında Gelen İki Soru: Konuşmadan Yazıya ve Rastgele Sayı

### 9.1 Konuşmadan Yazıya

Ara sırasındaki bir konuşmada klavyesiz yazma konusu açıldı. Hoca, konuştuğunuzda birçok uygulamanın sizin için konuşmadan yazıya çevirme (speech to text) yaptığını söyledi. Bunun Siri'nin dışında, birçok uygulamanın desteklediği ayrı bir özellik olduğunu, Siri ile karıştırılmaması gerektiğini ekledi.

### 9.2 Rastgele Sayı Üretimi

**Soru:** Random fonksiyonu nasıl çalışır, neye bağlıdır? Bilgisayar rastgele bir şey üretmekte zorlanmaz mı?

**Cevap:** Hoca önce bu kanının nereden geldiğini sordu ve rastgele sayı üretmek için çok farklı yöntemler olduğunu söyledi. Üretimin bir şeye bağlı olması gerekir, bunun için bir başlangıç noktası belirlersiniz. Bu başlangıç noktası genelde zamandır (time): O andaki zaman değerini alırsınız. Bu başlangıç noktası ile örneğin asal sayılar (prime number) üzerinden rastgele sayılar üretilebilir. Hoca bu konunun daha ayrıntılı anlatılması gerektiğini ve hatırlatılırsa önümüzdeki hafta konuşulabileceğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Bu şekilde üretilen sayılara büyük olasılıkla sözde rastgele (pseudo-random) sayılar denir. Üretim bir algoritmayla yapıldığı için aynı başlangıç noktası büyük olasılıkla aynı sayı dizisini verir. Öğrencinin "bilgisayar rastgele üretmekte zorlanır" sezgisi büyük olasılıkla bu belirlenimli yapıdan gelir.

## 10. Bilgisayar Ağları ve Ölçeğe Göre Sınıflandırma

Bilgisayarın kendi iç işlerini ve donanım parçalarını kontrol etmek için işletim sistemi olduğundan bahsedilmişti. Ama bilgisayarlar yalnızca kendi içlerinde iş yapmaz. Uzunca bir süredir yaptıkları işlerin sonuçlarını birbirleriyle paylaşırlar. Bunun için haberleşmeleri gerekir ve hocaya göre bu çok önemli bir yetenektir. İlk etapta iki bilgisayarı birbirine bağlayıp konuşturabilirsiniz. Ama hedef iki bilgisayarın değil, dünyadaki bütün bilgisayarların birbiriyle konuşabilmesidir.

Bilgisayarları veri paylaşımı için birbirine bağladığımız bu yapıya ağ (network), bilgisayar ağları için de computer networks denir.

<!-- BELİRSİZ: 01:10:59'da hoca "bunu da define edelim" diyerek tahtaya bir tanım yazıyor; yazılan metin altyazıda yok. -->

Ağlar ölçeğe göre küçükten büyüğe şöyle sınıflandırılır:

- **PAN (Personal Area Network):** En küçük ölçektir. Birkaç metrelik çapta kısa mesafeli haberleşme (short range communication) yapılır. Bir ağın bu adı alması, kullanılan protokollere de bağlıdır.
- **LAN (Local Area Network):** Daha çok bir bina içinde ya da birbirine yakın binaların bağlı olduğu kampüs ortamlarında kullanılır.
- **MAN (Metropolitan Area Network):** Orta ölçektir (intermediate size). Genelde bir şehir boyutunda ifade edilir.
- **WAN (Wide Area Network):** Genelde tüm dünyada oluşturulan ağa verilen addır.

**Soru:** Bunların birbirinden farkı nedir?

**Cevap:** Bir öğrenci farkın alan genişliği olduğunu söyledi: PAN'da kendi bilgisayarımızla, LAN'da mesela kendi evimizde iş yaparız, MAN tüm şehri etkiler, WAN bir ülke gibidir. Hoca bunun genel olarak doğru olduğunu söyleyip yukarıdaki ölçekleri açıkladı.

Bu ağlar üzerindeki haberleşmeyi genellikle açık ağ (open network) olarak kullanırız. Bazı özel kuruluşlar ise kapalı ağlar (closed network) oluşturarak kendi bilgisayar bağlantılarında kendi kurallarını uygulayabilir.

## 11. Ağ Topolojileri

Ağların bir de topolojik yerleşimi, yani bilgisayarların birbirine nasıl bağlı olduğu vardır. Hoca bilinen iki topolojiyi anlattı ve ayrıntısının bilgisayar ağları dersinde görüleceğini söyledi:

- **Bus topolojisi:** Bilgisayarlar birbirine bir hat üzerinden bağlıdır ve bilgiyi bu hat üzerinden gönderir.
- **Star topolojisi:** Merkezde haberleşmenin sorumluluğunu taşıyan bir bilgisayar vardır. Haberleşme bu bilgisayar üzerinden gerçekleşir.

**Soru:** Bus ve star topolojisini kullandığımız birer örnek verebilir misiniz?

**Cevap:** Bir öğrenci star için evdeki modemi, etrafındaki cihazlar olarak da bilgisayar ve telefonu örnek verdi. Hoca kablosuz erişim noktalarını (wireless access point) ekledi: Evdeki modem bu görevi görür. Üniversitede de herkes belirli bir erişim noktası üzerinden kablosuz bağlanır ve bağlantıyı o erişim noktası yönetir. Radyo sinyalleri erişim noktasına gider, bilgi onun üzerinden aktarılır. Bu yapı kablosuz ağlarda çok sık kullanılır.

Bus için hoca, Ethernet protokolünü kullanan ve üniversitelerde de bilgisayarların birbirine bağlandığı yapıyı örnek verdi. 1990'lardan itibaren kullanılan Ethernet'in hâlâ en yaygın ağlardan biri olduğunu, bus yapısını kullandığını ve bilgisayarların bir hat üzerinden bağlı olduğunu söyledi.

> **Ders sonrası not:** Hoca Ethernet'i bus yapısına örnek verdi ve 1990'lardan itibaren kullanıldığını söyledi. Ethernet büyük olasılıkla 1970'lerde geliştirilmiştir. İlk yıllarında bilgisayarlar büyük olasılıkla gerçekten ortak bir hatta bağlanıyordu; bugünkü Ethernet ağlarında ise büyük olasılıkla bilgisayarlar bir switch'e bağlanır ve fiziksel yapı daha çok star'a benzer.

## 12. Ağları Büyüten Cihazlar: Repeater, Bridge, Switch

Gönderilen sinyalin gücü belirli bir mesafeden sonra düşer. Sinyali bir sonraki ağa hatasız taşımak ve küçük bus ağlarından büyük bir bus ağı kurmak için hatlarda ek cihazlar kullanılır. Hocanın çiziminde bir Network 1 ve bir Network 2 vardı. Soru, ikisini birleştirerek daha büyük bir bus ağı oluşturan cihazın ne olduğuydu. Bir öğrencinin "switch" cevabına hoca "switch değil, daha basit bir versiyonu" dedi: repeater.

### 12.1 Repeater

Aynı ağda bulunan, ama çok sayıda bilgisayardan ve uzun mesafeden oluşan bir yapınız varsa, repeater gelen ve gücünü kaybetmiş sinyali yeniden oluşturarak iletir. Böylece güç kaybından kaynaklanan sıkıntı giderilir ve sinyal karşı tarafa kayıpsız ulaşır. Repeater her türlü sinyali aktarır.

### 12.2 Bridge

Bridge, repeater'dan biraz daha karmaşıktır. Amacı bütün mesajları diğer bus'a aktarmak değildir, yalnızca diğer ağa gitmesi gereken sinyalleri aktarır. Hocanın örneğinde A ve B aynı tarafta, F ise diğer taraftadır:

- A'dan F'ye gidecek mesajı bridge diğer tarafa aktarır.
- A'dan B'ye gidecek mesaj yayın (broadcast) şeklinde gönderildiği için bridge'e de ulaşır. Ama B diğer tarafta olmadığı için bridge bu mesajı aktarmaz.

### 12.3 Switch

Switch, ikiden fazla bus yapısını birleştirmek için kullanılır. Ağlar daha karmaşık hâle geldiği için günümüzde ağırlıklı olarak switch kullanılır. Hoca çizime aşağı doğru bir bus daha ekledi: Ağ büyüdüğü için üç farklı bus yapısını araya bir switch koyarak yönetmeye başlarsınız. Switch'in iki faydası vardır: İkiden fazla bus'ı birleştirme şansı verir ve mesajı gerektiği yere yönlendirir.

- A, kendi yerel bus'ında olmayan E'ye gönderiyorsa, mesaj switch'ten geçer. Switch, E'nin yerel bus'ta olmadığını anlar ve paketi diğer tarafa gönderir.
- A, C'ye gönderiyorsa, switch paketi diğer bus'lara göndermez.

Genel olarak bus topolojisinde hat uzadıkça araya repeater, bridge ya da switch koymak gerekir. Repeater basit bir çözümdür. Bridge yalnızca iki bus yapısını birleştirme kapasitesine sahiptir. Switch birden çok bus'ı desteklediği için günümüzde çok sık kullanılır.

<!-- BELİRSİZ: 01:23:36'da altyazı "günümüzde artık çok sık kullanılıyor bridge" diyor; "kullanılmıyor" olabilir, bu yüzden bridge'in güncel yaygınlığı yazılmadı. -->

## 13. Router ve Switch ile Farkı

### 13.1 Router Nedir?

Hoca router'ın ne olduğunu sordu. Bir öğrenci, gelen verileri ilgili alan içinde doğru cihaza gönderen cihaz olduğunu, router'ın ağ içinde, switch'in ise ağlar arasında yönlendirme yaptığını söyledi. Hoca bunun yanlış olduğunu, aslında tam tersinin geçerli olduğunu belirtti.

Router, birbirinden farklı, aynı adres bloğunda ya da aynı konumda bulunmayan ağların haberleşmesini sağlamak ve paketleri iletmek (forward) için kullanılan yapıdır. Örneğin bir Ethernet ağından bir Wi-Fi ağına ya da uzaktaki başka bir Ethernet ağına bilgi aktarmak istiyorsanız, router gerekir.

Hocanın çizdiği örnekte paket şöyle ilerler:

1. Ethernet ağından çıkan bilgi router'a geldiğinde adres kontrolü yapılır.
2. Router kendi arama tablosuna (lookup table) bakarak paketin nereye gitmesi gerektiğini belirler ve bir sonraki router'a iletip iletmeyeceğine karar verir.
3. Paketi alan router da aynı kontrolü yapar ve sonraki seçeneklerden hangisine gideceğini belirler.
4. Paket son router'a ulaştığında bu router, paketin kendi yerel alan ağında hangi bilgisayara gideceğini paketin içeriğine bakarak anlar.
5. Paket hedefe ulaşır ve taşıma sona erer.

### 13.2 O Hâlde Switch Ne Yapıyor?

**Soru:** Router'ın ne olduğunu anladım, burada switch'in görevi nedir?

**Cevap:** Switch, Ethernet ağı içinde aynı ağda olan, farklı uzaklıklarda bulunan cihazlarla çalışır ve farklı sanal alanlar yaratmanızı sağlar. Örneğin bilgi işlem cihazlarının bulunduğu bir alan olsun. Bu alandaki bilgisayarların, öğrencilerin ya da öğretim üyelerinin bulunduğu alandaki bilgisayarlarla aynı yerel alan ağında olmasını istemiyorsanız switch kullanırsınız.

> **Ek bilgi (derste anlatılmadı):** Hocanın "sanal alan" dediği yapıya büyük olasılıkla VLAN (Virtual LAN) denir. Bu özellik büyük olasılıkla her switch'te bulunmaz, yönetilebilir switch'lerde bulunur.

**Soru:** Router ağlar arasında yönlendirme yapıyor, switch de teknik olarak aynısını yapmıyor mu? Router daha büyük ağları yönetiyor, switch daha küçük ya da sanal ağlar arasındaki alışverişi sağlıyor diyebilir miyiz?

**Cevap:** Hoca bunu söyleyebileceğimizi kabul etti ve şöyle tamamladı: Yapısal olarak birbirinden farklı ağların bağlanmasını ve uzak noktalardaki ağların haberleşmesini router sağlar.

### 13.3 Ağ Geçidi ve Kampüs Örneği

Router'lar bir bakıma ağ geçidi (gateway) olarak da adlandırılır. Router, bulunduğunuz ağın dünyadaki diğer ağlara bağlantı noktasıdır.

Hoca kendi kampüsünü örnek verdi. Davutpaşa kampüsünün çıkış noktasında bir router vardır. Kampüs kendi içinde switch'lerle yönetilir: Fakültenin bir ana switch'i vardır, onun altında bölümler arasında, hatta bölümlerin içinde de switch'ler bulunur. Örneğin bir switch bir kata ayrılabilir. Ya da bir switch, alan adı sunucusu (domain server) ve web sunucusu (web server) gibi özel erişim gerektiren bilgisayarların bulunduğu alana ayrılabilir.

Böylece switch ile belirli paketlerin kendi içinde dolaşmasını, diğer bilgisayarların koruma altındaki bölgelere erişememesini teknik olarak sağlamaya çalışırsınız. Haberleşme de hızlanır ve yönetilebilir olur. Hoca bir şeyi daha hatırlattı: Arada switch olmasa o kadar uzun mesafede bir yerel alan ağı oluşturamazsınız. O zaman repeater ya da bridge kullanmak zorunda kalırsınız, ama bunlarla çoklu bağlantı sağlayamazsınız.

> **Hocanın vurgusu:** Birbirinden farklı ağ tiplerini router ile, aynı tip ağ içindeki cihazları daha çok switch ile bağlarsınız.

## 14. Protokoller ve OSI Modeli

### 14.1 Haberleşme Protokolleri

Bir ağ içindeki cihazların haberleşmesi için belirli kurallara ihtiyaç vardır. Bu kurallara protokol denir. Hoca kullanılan haberleşme cihazlarındaki protokolleri sorduğunda öğrencilerden Wi-Fi, Bluetooth ve NFC cevapları geldi. Hoca Ethernet üzerinden haberleşmenin de bir protokol gerektirdiğini ekledi.

Bu protokoller bilginin hangi kurallar çerçevesinde taşınacağını belirler. Ethernet üzerinde kablolu, Wi-Fi, Bluetooth ve NFC ile kablosuz taşıma yapılır.

**Soru:** SMTP (Simple Mail Transfer Protocol) de bir protokol sayılır mı?

**Cevap:** Hoca, SMTP'nin internet uygulamalarının haberleşme protokolü olduğunu ve onu ayrı tuttuğunu söyledi. Protokol adı altında, kurallar bütünü olarak elbette sayılabilir. Ama burada konuşulan, bilginin taşınmasıyla ilgili haberleşme protokolleridir. Hoca bu ayrımda dikkatli olmak gerektiğini belirtti.

### 14.2 OSI Modeli

Bir öğrencinin yazılı olarak paylaştığı bilgi üzerine hoca, bunun bir protokol olarak değerlendirilmemesi gerektiğini, bunun OSI katmanları olduğunu söyledi. Verinin bir bilgisayardan diğerine aktarılırken kullandığı 7 katmanlı bir model vardır:

1. Application
2. Presentation
3. Session
4. Transport
5. Network
6. Data Link
7. Physical

Her katmanın veriyi aktarmak için bir görevi vardır. Uygulama seviyesinde HTTP, FTP, SSH ve DNS gibi protokoller bulunur. Bunlar ilgili mesajların nasıl taşınacağını belirler.

### 14.3 TCP ve UDP

Alta inip bilginin taşınması noktasına geldiğimizde, internet üzerinden haberleşmede TCP ve UDP kullanılır.

- **TCP:** İki bilgisayar haberleşirken bir oturum (session) kurulur. Bu oturumda paketler gönderildikçe, "paketi aldım" diyen bir alındı (acknowledgement) mesajı gönderilir. Güvenilirdir, ama belirli yükler altında performansı düşer.
- **UDP:** Böyle bir mekanizma yoktur. Paketi gönderirsiniz ve ulaşmama ihtimalini de göz önünde bulundurursunuz. Daha hızlıdır, ama daha az güvenilirdir.

> **Hocanın vurgusu:** Bu protokolleri hangi uygulamada kullanacağınız çok çok önemlidir.

> **Ders sonrası not:** Hoca TCP ve UDP için "iki IP protokolü" dedi; doğrusu büyük olasılıkla, bunlar IP'nin üzerinde çalışan taşıma katmanı (transport layer) protokolleridir.

Hoca, protokollerin sayısının çok fazla olduğunu ve konuya ayrıntılı girmeyeceğini ekledi.

## 15. Forwarding Table ve İnternet Trafiği

Router konusuna dönersek, router'ın üzerinde bir yönlendirme tablosu (forwarding table) vardır. Router, kendisine gelen mesajı nereye aktaracağını bu tabloyla bilir. Router'ların birbirine nasıl bağlı olduğu tanımlıdır. Paketlerin hangi tarafa yönlendirileceğine IP adreslerini kullanarak router'lar karar verir.

Dünyadaki bütün internet trafiği router'lar üzerinden gerçekleşir. Kampüsten çıkıp Beşiktaş kampüsüne giderken bile router çıkışı gerekir. Bazen de kampüsten çıkıp Amerika'ya kadar birçok router üzerinden geçer ve oradan bilgi getirirsiniz. Her router'ın, gelen paketin adresine bağlı olarak veriyi bir sonraki noktada nereye aktaracağını bildiğini düşünebilirsiniz. MAN, LAN ve WAN'daki IP adreslerinin kullanımı da burada devreye girer.

## 16. Süreçler Arası İletişim

### 16.1 Dağıtık Hesaplama

Şimdiye kadar bilginin taşınmasından bahsedildi. Süreçler farklı kaynaklar üzerinde çalıştığında nasıl haberleşir? Birden fazla etkinlik, bir ağ üzerindeki farklı bilgisayarlarda çalışabilir. Yani dağıtık hesaplama (distributed computing) yapıyor olabilirsiniz: Bir işin alt parçalarını, süreçleri ya da iş parçacıklarını (thread) farklı cihazlara yönlendirirsiniz. Farklı cihazlarda çalışıp bu cihazlardan elde edilen verilerin birleştirilmesiyle gerçekleşen işlere süreçler arası iletişim (interprocess communication) denir.

### 16.2 İstemci-Sunucu Mimarisi

Süreçler arası iletişim önce istemci-sunucu (client-server) mimarisine dayanır. İstemciler sunucudan talepte bulunur ve birden fazla istemci aynı sunucudan hizmet alır.

Hocanın iki örneği şöyledir:

- **Yazıcı sunucusu (print server):** Yazıcıya bir doküman gönderdiğinizde bilgisayarınız istemcidir. Ağa bağlı yazıcı sunucusu ağdan gelen istekleri dinler. İsteğinizi alır, kuyruğa koyar ve basım işlemini tamamlar. Aynı anda o ağdaki farklı kişiler de sunucudan basım talep edebilir. Bu durum aynı bilgisayar üzerinde de olabilir, ama burada konuşulan farklı bilgisayarlar arasındaki durumdur.
- **Dosya sunucusu (file server):** Hoca üniversitedeki sunucu odasında böyle bir sunucu olduğunu söyledi. İşler bir sunucuda yapılırken bilgiler ayrı bir dosya sunucusunda saklanır. Bir istemci dokümana ulaşmak istediğinde, dosya sunucusu ilgili dosyayı açıp o istemciye gönderir.

### 16.3 Eşler Arası Mimari

İstemci-sunucudan farklı olarak bir de eşler arası (peer-to-peer) mimari vardır.

**Soru:** Eşler arası mimari nedir?

**Cevap:** Bir öğrenci, herhangi bir sunucu olmadan bir bilgisayardan diğerine veri gönderen uçtan uca bir iletişim yöntemi olduğunu söyledi. Hoca bunu çok güzel bularak, her iki bilgisayarın bir bakıma hem sunucu hem istemci olarak hizmet verdiğini ekledi.

Günlük hayattan örnekler şunlardır:

- **Bluetooth:** Telefonlar arasında medya gönderirken her iki taraftaki yazılım hem istemci hem sunucu modunda çalışır.
- **Torrent:** Bir film indirmek istediğinizde dosyanın çeşitli bilgisayarlarda olduğunu bilirsiniz. Hangi bilgisayarlarda olduğu bilgisi size geldikten sonra eşler arası haberleşme başlar ve dosyaların sizin tarafınıza aktarılması işlemi yürür.
- **Çevrim içi oyunlar:** Ağ yapısı eşler arası tasarlanmışsa, örneğin PlayStation'da oturum açtığınızda herkesin IP'si sunucuda saklıdır. Eşleşme tamamlandıktan sonra oyun doğrudan oynanır. Veriler merkezi bir noktaya aktarılmaz, doğrudan bilgisayarlarınız arasında taşınır.

**Soru:** Eskiden "ne kadar paylaşırsan o kadar alırsın" mantığı vardı. Hâlâ öyle mi?

**Cevap:** Hoca farklı mekanizmalar olduğunu, bazılarının hâlâ böyle çalıştığını ve paylaştığınız kadar aldığınızı söyledi. Yukarıdaki oyun örneğinde ise böyle bir mekanizma yoktur.

### 16.4 Anlık Mesajlaşma Eşler Arası mıdır?

**Soru:** WhatsApp gibi anlık mesajlaşma uygulamaları eşler arası sayılır mı?

**Cevap:** Hoca çok emin olmadığını ve mekanizmasını bilmediğini söyledi. Bildiği kadarıyla bir sunucu mekanizması vardır ve mesaj sunucuya aktarılır. Birinci tikin mesajın karşı tarafa gittiğini, ikinci tikin okunduğunu gösterdiğini, sonradan mavi rengin geldiğini de hatırlattı. Kendi bildiğine göre bu eşler arası değildir, ama iddialı bir yorum yapamayacağını ve konuya bakmak gerektiğini ekledi. Bir sunucu yalnızca konum bilginizi ve IP'nizi tutuyor, mesajları tutmuyorsa, mesajlarda eşler arası haberleşiyor olabilirsiniz. Ama bu bilgileri saklayan kısım mutlaka bir sunucu üzerinden çalışır.

**Soru:** Uçtan uca şifreleme yazıyor. Bu, iki kişi yazışırken eşler arası haberleşme olduğu anlamına gelebilir mi?

**Cevap:** Hoca önce öyle olması gerektiğini, mesajların doğrudan aktarılması gerektiğini düşündü. Bir öğrenci, mesajın yine sunucudan ve internetten geçtiğini, yalnızca başkasının okuyamadığını araştırdığını aktardı.

**Soru:** Eşler arası olsaydı grup sohbetinde sorun olmaz mıydı? Grup için bir sunucu gerekmez mi?

**Cevap:** Hoca grup sohbetinin farklı olduğunu, ilk etapta istemci-sunucu mimarisi kullanıldığını bildiğini, ama şu anda emin olamadığını söyledi. Yanlış bir şey söylememek için okuduktan sonra cevap vermek istediğini belirtti.

> **Ders sonrası not:** Hoca konudan emin olmadığını söyledi. Uçtan uca şifreleme büyük olasılıkla, mesaj sunucudan geçse bile yalnızca iki uç tarafından okunabilmesi demektir, eşler arası iletim anlamına gelmez. WhatsApp'ta büyük olasılıkla tek tik mesajın sunucuya ulaştığını, çift tik alıcının cihazına ulaştığını, mavi çift tik ise okunduğunu gösterir.

## 17. Bulut Bilişim

Son dönemde çıkan bir kavram da bulut bilişimdir (cloud computing). Bulut bilişim, dağıtık sistemlerin ya da dağıtık hesaplama mantığının bir versiyonunu hayatımıza sokmuştur. Bulut üzerinden, biraz önceki dosya sunucusu mantığıyla hizmet alırsınız. Ama hizmet yalnızca dosya saklama değildir:

- Yazılım hizmeti (Software as a Service): Bir programın kullanımıyla ilgili hizmet alınır.
- Bir bilgisayarın ya da işletim sisteminin size doğrudan tahsis edilmesi.
- Sunucu kiralama gibi cihaz hizmetleri.

Bulut bilişim hem verilerin merkezi bir noktada saklanmasını, hem de bütün cihazlardan bu veriye erişilmesini sağlar. Böylece her cihaz için yedek (backup) alma ve bir cihazda yapılan işi diğerine aktarma süreci geride kalır. Hocanın günlük hayat örneği şöyleydi: Eskiden evde bir iş yapar, USB'ye koyar, iş yerine götürür, orada değiştirir ve USB'yi tekrar eve taşırdınız. Artık bu ortadan kalkmıştır. Bu model, dağıtık sistemler başlığı altında incelenmesi gereken ayrı bir konudur.

## 18. İnternet, İntranet ve Servis Sağlayıcılar

### 18.1 İnternet ve İntranet

**Soru:** İnternet ve intranet nedir?

**Cevap:** Bir öğrenci, internetin küresel ağ bağlantısı, intranetin ise bir merkezde bulunan bilgisayar ve ağların bağlanması olduğunu söyledi. Hoca bunun genel olarak doğru olduğunu belirtti.

İnternet, tüm dünyaya açık bir ağın içindeki bilgisayarların haberleşmesini sağlayan altyapıdır. Herkesin bir IP adresi ve bir alan adı (domain name) vardır, bilgisayarlar bunlar üzerinden haberleşir. İntranet ise daha çok şirketlerin kendi iç ağlarında haberleşmesini sağlayan bağımsız bir yapıdır. Önemli nokta, erişimin belirli bir ağ içinde sınırlı olmasıdır. İnternetwork dediğimizde ise dünya çapındaki bilgisayarların oluşturduğu bağlantıyı kastederiz.

<!-- BELİRSİZ: 01:49:00-01:50:26 arasında altyazı "intranet" ile "internet" kelimelerini karıştırıyor; hangi cümlenin hangisini anlattığı bağlamdan çıkarıldı. -->

> **Ders sonrası not:** Hoca herkesin bir IP adresi ve alan adı olduğunu söyledi; alan adı büyük olasılıkla her cihazda bulunmaz, daha çok sunucular gibi adla erişilen sistemler için alınır. Bölüm 19'daki "her cihazın benzersiz bir IP'si olması isteniyor" ifadesi de büyük olasılıkla genel internet adresleri için geçerlidir, çünkü ev ve kurum ağlarındaki cihazlar büyük olasılıkla özel adreslerle ortak bir çıkış adresini paylaşır.

### 18.2 Servis Sağlayıcılar ve Host

İnternet servis sağlayıcıları (internet service provider) katmanlıdır. En üst seviyede Tier 1, onun altında Tier 2, en son noktada ise son sistemler (end systems) denen kullanıcılar bulunur. Her birine host denir.

Bir host başka bir hostla şöyle haberleşir:

- Aynı ağdaysa ilgili switch üzerinden gitmeden haberleşir.
- Yan ağdaysa switch üzerinden haberleşir.
- Farklı bir ağdaysa router üzerinden, servis sağlayıcıların altyapısı kullanılarak haberleşir.

### 18.3 Kablolu ve Kablosuz Bağlantı

Bağlantı genelde bakır kablolarla alınır, ama son dönemde fiber kablolar öne çıkmıştır. Fiber üzerinden bilgi taşınımı dış şartlardan çok daha az etkilenir ve çok daha hızlıdır. Bu yüzden fiber kablolama çalışmaları devam etmektedir.

Bilgiyi kablolu taşımak her zaman bir avantajdır. Kablosuz taşıma, hem bilginin güvenliği hem de bozulabilirliği açısından önemli bir sıkıntıdır. Yine de kablosuz haberleşme günümüzde çok yaygındır ve hızı oldukça ilerlemiştir.

## 19. IP Adresleri ve Alan Adı Sistemi

### 19.1 IP Adresi

Her cihazın benzersiz (unique) bir IP'si olması istenir. Hoca bunun için ne kadarlık bir alan kullanıldığını sordu ve bir öğrenci 4 byte cevabını verdi.

- **Verilen:** IP adresleri 32 bit uzunluğundadır.
- **İşlem:** $32 \text{ bit} \div 8 \text{ bit/byte} = 4 \text{ byte}$ (ara adım eklendi).
- **Örnek:** `192.207.177.133`. Noktalarla ayrılan dört sayı vardır ve her biri bir byte'a karşılık gelir: $4 \times 8 = 32$ bit (ara adım eklendi).

Bu sayıların her birinin farklı bir amacı vardır, ama hoca bunun bu dersin konusu olmadığını söyledi.

> **Ders sonrası not:** Derste anlatılan 32 bitlik adresler büyük olasılıkla IPv4 adresleridir. Bugün büyük olasılıkla 128 bitlik IPv6 adresleri de kullanılmaktadır.

### 19.2 Alan Adı Sistemi

İnternette gezinirken bu rakamları kullanarak haberleşmeyiz, bir alan adı sistemi (domain name system) kullanırız. Hocanın örneği üniversitenin adresidir: `yildiz.edu.tr`. Bu adresi yazdığımızda bir alan adı sunucusu (domain name server) adı, sitenin barındırıldığı bilgisayarın adresine dönüştürür ve sorgu o adrese gönderilir. Bu sistem olmasaydı her bilgisayarın adresini ezbere bilmemiz gerekirdi.

**Soru:** Router'lar hangi IP'nin hangi alan adına ait olduğunu nasıl biliyor? Alan adı sunucuları router'ların üzerinde mi, başka bir yerde mi?

**Cevap:** Hoca, router'ların alan adı sunucularına sorduğunu, DNS arama tabloları (lookup table) olduğunu söyledi. Adın tabloda olup olmadığına bakılır, yoksa alan adı sunucusuna sorulur. Öğrencinin "alan adları değişebileceği için tablolar sürekli güncelleniyor mu?" sorusuna da evet cevabını verdi: Alan adı sunucuları ve arama tabloları sürekli güncellenir.

> **Ders sonrası not:** Hoca router'ların alan adını DNS arama tablolarından bulduğunu söyledi. Doğrusu büyük olasılıkla, adın IP'ye çevrilmesi paket yola çıkmadan önce bilgisayar ve DNS sunucusu arasında yapılır, ara router'lar ise paketi yalnızca Bölüm 15'teki yönlendirme tablosu ve IP adresiyle iletir. Ev modemi gibi bazı cihazlar büyük olasılıkla DNS sonuçlarını kendi üzerinde de saklayabilir.

## 20. Dersin Sonundaki Sorulardan C Dili Notları

Dersin sonundaki sorularda C diliyle ilgili birkaç akademik nokta konuşuldu.

### 20.1 Standart C ve Taşınabilirlik

Hoca, kodun farklı platformlarda çalışabilmesini önemsediğini söyledi. Sebebi, kod yazarken olabildiğince standartlara uymanızdır. Böylece bir platformdan diğerine geçtiğinizde sorun yaşamazsınız. Her platform için ayrı ayrı kod yazmak gerekmez, standartlara uygun yazmak gerekir. Önemli olan temel C kodunun her yerde çalışabilmesidir. Çıktıya renk vermek gibi görsellik katan işler ve bunlar için kullanılan kütüphaneler ise her yerde çalışmayabilir.

<!-- BELİRSİZ: 01:57:35'te altyazı "ağız isim standartları" diyor; kastedilen standardın adı altyazıdan net değil (ANSI olabilir). -->

### 20.2 C'de String Tipi Yoktur

**Soru:** İki boyutlu bir "string dizisi" oluşturabilir miyiz? Her hücreye örneğin birden fazla karakterden oluşan bir etiket yazmak istiyoruz.

**Cevap:** Hoca, karakter dizisi ile string'in aynı şey olduğunu, C'de string diye ayrı bir tip olmadığını söyledi. C'de karakter dizisi vardır ve ona string deriz. Yani bir karakter matrisinin tek bir gözüne birden fazla karakter yazılamaz.

Bir matris gözünde bir adı tutmak istiyorsanız, o karakter dizisinin başlangıç adresini saklayabilirsiniz. Yani pointer ile, adresi matris içinde tutabilirsiniz. Yazdırırken de bu adresi kullanırsınız. Hoca, bu yapının karmaşık olduğunu ve henüz öğretilmediğini söyledi.

Bir öğrenci alternatif önerdi: Her hücreye bir indis koymak ve asıl metinleri ayrı bir karakter dizisinde tutmak. Hoca bunun olabileceğini onayladı.

### 20.3 Karakter Matrisi, Tamsayı Matrisi ve Biçim Belirteçleri

Hücrelerde 11, 12 gibi iki basamaklı sayılar göstermek isteyen bir öğrenciye hoca, matrisi karakter değil tamsayı tanımlarsa bunları yazdırabileceğini söyledi. Karakter tanımlarsa 11'i yazdıramayacağını belirtti.

> **Ders sonrası not:** Hoca karakter matrisinde 11'in yazdırılamayacağını söyledi. Bu, "1" ve "1" diye iki ayrı karakteri tek göze koymak açısından doğrudur. Ama `char` büyük olasılıkla küçük bir tamsayı da saklayabildiği için, gözde 11 değeri tutulup `%d` ile yazdırılabilir (bu davranış derleyiciyle denendi).

Ayrıca `%d` ve `%c` yalnızca yazdırma biçimidir. Aynı değerin o andaki ASCII tablosu karşılığını ya da karakter karşılığını yazdırmanızı sağlar. Fakat bir matrisin belirli bir kısmını karakter, diğer kısmını tamsayı olarak saklayamazsınız. Ya hepsi karakter ya da hepsi tamsayı olarak saklanır.

### 20.4 Saklamak ve Göstermek Ayrı İşlerdir

Tamsayı matrisi kullanıldığında sıfırlarla dolu bir oyun tahtasının ekranda karışık görüneceğini söyleyen bir öğrenciye hoca şunu söyledi: Tahtayı saklamak ile ekranda göstermek birbirinden farklıdır. Ekrandaki gösterim saklama yapısıyla aynı olmak zorunda değildir ve farklı gösterim yöntemleri vardır.

> **Hocanın vurgusu:** Tahtayı saklamak ayrı, ekrana göstermek ayrı bir iştir. Bu ikisini oturtmaya çalışın.

## Dersin Toparlaması

Bu derste önce işletim sisteminin kalan konuları görüldü. RAM'den büyük programlar sanal bellek ve sayfalama ile çalıştırılır. Firmware cihazın işletim sistemi olmadan açılmasını sağlar, ROM'daki önyükleyici de işletim sistemini diskten belleğe taşır. Süreçler süreç tablosu, bağlam geçişi, dağıtıcı ve kesmeler sayesinde aynı işlemciyi paylaşır. Kaynaklar iyi yönetilmezse kilitlenme oluşur.

İkinci yarıda bilgisayarların birbiriyle konuşmasına geçildi. Ağlar ölçeğe göre PAN'dan WAN'a kadar sınıflandırıldı, bus ve star topolojileri görüldü. Repeater, bridge, switch ve router'ın görevleri ayrıldı. Protokoller, OSI modeli ve TCP-UDP farkı anlatıldı. Süreçler arası iletişimde istemci-sunucu ve eşler arası mimariler karşılaştırıldı, bulut bilişim, internetin katmanlı yapısı, IP adresleri ve DNS ile ders tamamlandı. Hoca bu konunun kalan birkaç noktasını ve binary search algoritmasını bir sonraki derste anlatacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
