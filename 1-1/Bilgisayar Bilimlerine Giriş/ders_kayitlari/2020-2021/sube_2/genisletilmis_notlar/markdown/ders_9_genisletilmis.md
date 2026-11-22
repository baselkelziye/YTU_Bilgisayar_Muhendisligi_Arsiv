# Ders 9 Genişletilmiş Notu: Sanallaştırma, Ubuntu Linux Kurulumu ve Linux Dosya Sistemi Hiyerarşisi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Laboratuvarın Amacı ve Bilgisayar Sisteminin Katmanları
- 2. Sanallaştırma
- 3. Dual Boot ile Sanal Makinenin Karşılaştırılması
- 4. VMware Workstation Player Kurulumu
- 5. Yeni Bir Sanal Makine Oluşturmak
- 6. Sanal Disk, Bellek ve Ağ Ayarları
- 7. Sanal Makineyi ISO İmajından Başlatmak
- 8. Ubuntu 20.04 Kurulumu
- 9. Disk Bölümleme ve Dosya Sistemleri
- 10. Linux Dosya Sistemi Hiyerarşisine Giriş
- 11. Linux'ta Kullanıcılar ve Root
- 12. Kurulumun Tamamlanması ve İlk Açılış
- 13. Terminal ve Kök Klasörlerin Görevleri
- 14. Neden Linux?
- Örnek Sorular
- Dersin Toparlaması

## 1. Laboratuvarın Amacı ve Bilgisayar Sisteminin Katmanları

Bu oturum bir laboratuvar dersidir. Öğrencilerden önceden iki yazılım indirmeleri istenmişti: VMware Workstation Player'ın Windows sürümü ve Ubuntu işletim sisteminin kurulum imajı. Derste önce yapılacak işin ne olduğu açıklandı, sonra kurulum adım adım ekranda gösterildi.

Bir bilgisayar sistemine bakıldığında en altta **donanım katmanı** vardır: işlemci, bellek, disk ve benzeri. Bu donanımı yöneten ve kullanmamızı sağlayan **işletim sistemi** onun üzerindedir. İşletim sisteminin üzerinde de **uygulamalar** çalışır. Bu derste yapılan şey, bu katmanlı yapının tamamını sanal bir ortamda çalıştırmayı sağlayacak düzeni kurmaktır.

> **Hocanın vurgusu:** Laboratuvarın amacı belirli bir Ubuntu sürümünü kurdurmak değil, Linux'a adım atmayı sağlamaktır. Ubuntu 16, 18 ya da 20 olması, VMware ya da VirtualBox kullanılması önemli değildir. Önemli olan temel işleri yapabileceğiniz bir Linux ortamının bulunmasıdır; ilerideki laboratuvarlarda C programlarının bu Linux ortamında nasıl yazılıp çalıştırılacağı anlatılacaktır.

## 2. Sanallaştırma

Sanallaştırma günümüzde çok duyulan bir kavramdır. Bir bakıma, aslında fiziksel olarak ayrıca bulunmayan kaynakları birilerine ayırmak (allocate etmek) demektir; "sanal" ifadesi buradan gelir.

Sanallaştırma farklı katmanlarda yapılabilir:

- **Donanım (fiziksel) seviyesi:** Donanımın özelliklerine bağlı olarak, tek bir makinedeki örneğin sekiz işlemci ve bir terabaytlık bellek, donanım seviyesinde ayrı makinelermiş gibi bölünebilir. Bu özellik masaüstünde değil, daha çok sunucu sistemlerinde görülür. IBM'in P serisi denen RISC makinelerinde uzun zamandır vardır. Intel tabanlı (x86) CISC mimarili sunucularda da yaygın olarak yapılabilir.
- **İşletim sistemi seviyesi:** Bir üst seviyede sanallaştırma yapılabilir.
- **Uygulama seviyesi:** İşletim sistemi üzerinde çalışan bir uygulama sanallaştırmayı yapar. Derste bu yol izlendi.

Uygulama seviyesinde sanallaştırma şu anlama gelir: çalışan makinenin üzerinde, istenen fiziksel özelliklere sahip yeni bir makine tanımlamayı sağlayan bir ortam kurulur ve bu yeni makineye uygun bir işletim sistemi yüklenir. Bu kurulumların sonunda bilgisayarda teknik olarak ikinci bir işletim sistemi bulunmaz; işletim sistemi, bilgisayar üzerinde oluşturulan sanal makinenin içine kurulur.

## 3. Dual Boot ile Sanal Makinenin Karşılaştırılması

Linux, Windows'un yanına **dual boot** olacak şekilde, yani açılışta seçilen ikinci bir işletim sistemi olarak da kurulabilir. Hoca bu aşamada öğrencilerin bu yola girmesini istemedi, çünkü riskleri vardır:

- Kurulum sırasında bir sorun çıkması yalnızca kullanıcı hata yaptığı için değil, işletim sistemlerinin yapılandırması ya da farklı seçenekler yüzünden de olabilir. Makine bir anda kullanılamaz hale gelebilir.
- Dual boot'ta iki işletim sisteminden yalnız biri bir anda kullanılabilir: biri boot edilir, diğerine geçmek için yeniden başlatmak gerekir.

Sanallaştırmayla yapıldığında ise çalışmakta olan Windows'un içinde sanal makineyi oluşturan yazılım çalışır, onun içinde de konuk (guest) Linux çalışır. Böylece iki sistem bir anlamda aynı anda, aynı makine üzerinde çalışır.

- **Artısı:** Farklı bir işletim sistemi bir uygulama gibi çalıştırılıp sonra kapatılabilir.
- **Eksisi:** Sanal da olsa makine arka tarafta fiziksel kaynakları kullanır. Bilgisayarın kaynakları yeterince fazla değilse ikisini aynı anda çalıştırmak zaman zaman zorlayabilir ya da sorun çıkarabilir.

## 4. VMware Workstation Player Kurulumu

### 4.1 VMware ürün ailesi

VMware normalde profesyonel, lisanslı sanallaştırma ürünleri satar; bunları ücretsiz kullandırmaz. Ürün adları zamanla ve platformlara göre değişti: sunucu tarafında kullanılan ESX Server, masaüstünde Workstation ve onun Player sürümü. Eskiden yalnız "Player" adında bir sürüm vardı, şimdi adı Workstation Player'dır. Player'ın güzel tarafı, ticari olmayan kullanımda birden fazla sanal makine oluşturmaya, bunlara sistem yüklemeye izin vermesidir. macOS için VMware'in karşılığı Fusion'dır; derste bakıldığında Fusion 12'nin Player sürümünün kişisel kullanım lisansıyla (bir hesap açıp indirerek) ticari olmayan amaçla ücretsiz kullanılabildiği görüldü. Alternatif olarak Oracle VirtualBox da kullanılabilir. VMware'in desteklemediği eski bir Windows sürümünde de VirtualBox gibi başka bir sanallaştırma yazılımına geçmek çözümdür.

> **Hocanın vurgusu:** Hangi sanallaştırma ortamının kullanıldığı önemli değildir. Önemli olan kullandığınız ortamın sisteminizle uyumlu olması ve performansınızı bozmadan çalışmasıdır.

### 4.2 Kurulum adımları

Kurulum sihirbazı "Welcome to the VMware Workstation 16 Player Setup Wizard" ekranıyla açılır (ekrandan, 00:15:00). Hocanın bilgisayarında Workstation 15 kurulu olduğu için sihirbaz yükseltme (upgrade) yaptı; temiz bir bilgisayarda bunun yerine normal kurulum (install) seçeneği görünür. Kurulumda teknik olarak bilinmedik bir şey yoktur; yalnız bir iki onay kutusu değiştirildi. Bunlardan biri VMware'in kullanıcı deneyimi programına katılımdı; boşuna bilgi toplanıp gönderilmesin diye işaret kaldırıldı. Kurulum ilerlerken "Installing VMware Workstation 16 Player" ekranı görünür (ekrandan, 00:20:00).

Kurulum bitince bilgisayarın yeniden başlatılması istenir. Yeniden başlatılmazsa program bütün işlevlerini düzgün yerine getiremeyebilir. Hoca dersi kesmemek için yeniden başlatmadı; eski sürümün dosyalarının yerine yenisi konduğu için program şans eseri çalıştı. Yeni kurulumda ek kütüphaneler ve çalıştırılabilir dosyalar da yüklendiği için bu herkeste böyle olmayabilir; sistem yeniden başlatma istiyorsa yeniden başlatılmalıdır. Program ilk açıldığında ticari kullanım için lisans anahtarı ister; ticari olmayan kullanım seçilirse hiçbir şey girmeden devam edilir.

## 5. Yeni Bir Sanal Makine Oluşturmak

VMware Workstation ve diğer birçok sanallaştırma uygulamasında benzer bir yapı vardır. Sol tarafta hazır kurulmuş ya da oluşturulmuş makineler görünür. Bir makinenin üzerine gelindiğinde durumu görünür: hangi işletim sisteminin yüklü olduğu, hangi Workstation sürümüyle oluşturulduğu, ne kadar bellek ayrıldığı. Makine düzenlenerek işlemci sayısından bellek miktarına, USB denetleyicisinden ekrana kadar her şey değiştirilebilir.

Yeni makine Player > File menüsünden oluşturulur. "New Virtual Machine Wizard" penceresinde üç kurulum kaynağı seçeneği vardır (ekrandan, 00:25:00):

- **Installer disc:** fiziksel bir kurulum CD/DVD'si.
- **Installer disc image file (iso):** Eskiden fiziksel olarak alınan CD ve DVD'lerin artık imajları vardır ve bu imajlar ISO biçimindedir. İndirilen Ubuntu 20.04 dosyası aslında bir kurulum DVD'sinin imajıdır.
- **I will install the operating system later:** sanal makine boş bir sabit diskle oluşturulur.

ISO dosyası seçildiğinde sihirbaz "Ubuntu 64-bit 20.04.1 detected. This operating system will use Easy Install." uyarısını gösterir (ekrandan, 00:25:00). Easy Install'da bir kullanıcı adı, şifre, ad soyad gibi birkaç bilgi verilir ve işletim sistemi neredeyse hiçbir soru sormadan kendi kendine kurulur. Normalde bir Linux kurulumu bir grup soru sorar ve derste bu soruların tek tek görülmesi istendi. Bu yüzden Easy Install kullanılmadı; arka planda neyin nasıl seçildiğini bilerek ve konuşarak ilerlemek için "I will install the operating system later" seçildi (ekrandan, 00:30:00).

Sihirbazın sonraki adımlarında:

- Konuk işletim sistemi olarak Linux, sürüm olarak Ubuntu 64-bit seçilir; indirilen imaj da 64 bitliktir.
- Makineye bir ad verilir; adın önemi yoktur (derste kısa bir ders kısaltması verildi).
- Makine oluşturulurken onunla ilgili çeşitli dosyalar oluşturulur. Program bunların yerini kendisi önerir: Documents altında Virtual Machines klasöründe, makine adıyla bir klasör. Disk alanı ya da disk erişim hızı gibi nedenlerle bu yer değiştirilebilir.

## 6. Sanal Disk, Bellek ve Ağ Ayarları

### 6.1 Disk boyutu ve disk dosyaları

"Specify Disk Capacity" adımında en büyük disk boyutu sorulur; Ubuntu 64-bit için önerilen boyut 20 GB'dır (ekrandan, 00:35:00). Hoca kabaca en az 8 GB alan gerektiğini, rahat hareket etmek için biraz daha fazlasının iyi olacağını söyledi; 10, 16, 18 ya da 20 GB seçmek kişiye kalmıştır. Sihirbazdaki açıklamaya göre sanal makinenin sabit diski ana bilgisayarın fiziksel diskinde bir ya da daha fazla dosya olarak saklanır; bu dosyalar küçük başlar, uygulama ve veri eklendikçe büyür.

Aynı adımda sanal diskin tek dosya mı ("Store virtual disk as a single file"), birden çok dosya mı ("Split virtual disk into multiple files") olacağı seçilir:

- 20 GB'lık bir disk tek dosya olarak tutulursa, makineyi bir yerden bir yere taşımak için o büyüklükte bir ortam gerekir. Disk daha küçük parçalara bölünürse taşıma daha küçük ortamlarla da yapılabilir.
- Bu seçim alttaki sistemin nasıl çalıştığıyla, kaç disk olduğuyla ve disklere nasıl erişildiğiyle de ilgilidir. Depolamayı parçalara bölmek zaman zaman erişimi daha hızlı ve rahat hale getirebilir.

Derste birden çok dosya seçeneği işaretlendi (ekrandan, 00:35:00).

### 6.2 Bellek, işlemci ve ağ

VMware bazı değerleri kendisi belirledi: 4 GB bellek, iki işlemci çekirdeği ve ağ bağdaştırıcısında NAT (Network Address Translation). Bilgisayarın kendisinin bir ağ bağlantısı vardır, ama içeride oluşturulan sanal makinenin teknik olarak bir ağ bağlantısı yoktur. Sanal makinenin dış dünyaya bağlanması için VMware ve diğer sanallaştırma ortamları birkaç yol sunar:

- Fiziksel ağ kartını sanal makineye sanki orada da bir ağ kartı varmış gibi tanıtmak. Böylece sanal makine de doğrudan fiziksel ağa çıkıyormuş gibi olur (bridge).
- İçeride sanal bir switch oluşturmak. Switch'in bir ucuna fiziksel bilgisayarın internet bağlantısı, diğer uçlarına oluşturulan sanal makineler konur ve içerideki ağ trafiği istenildiği gibi yönetilir (NAT).

Makinenin donanım ayarlarında ağ bağlantısının bridge mi NAT mı olacağı ve daha farklı iç ağ ayarları görülebilir. Derste varsayılan ayarlar yeterli bulundu.

## 7. Sanal Makineyi ISO İmajından Başlatmak

Sanal makine oluşturulup çalıştırıldığında, normal bir fiziksel makinenin açılışında görülen BIOS mesajlarına benzer mesajlar görünür. Ama diskte hiçbir şey olmadığı için makinenin boot etmesi mümkün değildir. Makine "Shutdown Guest" ile kapatılır.

Ardından makinenin ayarlarında CD-ROM aygıtına gelinir, "ISO dosyasını kullan" seçilir ve indirilen Ubuntu imajı verilir. Makine yeniden çalıştırıldığında CD'den boot etmeyi dener. Açılış menüsünde şu seçenekler vardır:

- Ubuntu'yu kurmadan denemek (farklı grafik ayarlarıyla deneme dahil).
- Ubuntu'yu kurmak.
- Bellek testi yapmak: imaj sanal bir makinede çalıştığını bilmez; fiziksel makinelerde yapılan kontrollerden biri belleğin düzgün olup olmadığıdır.
- Kurulum yapılmayacaksa, sabit diskte zaten yüklü bir sistem varsa onu boot etmek.

Derste "Install Ubuntu" seçildi.

### 7.1 ISO dosyasının "mount" edilmesi

Bir öğrencinin bilgisayarında indirdiği Ubuntu imajı VMware'de "Installer disc" seçeneğinde, yani fiziksel bir disk gibi görünüyordu. Bunun nedeni imajın işletim sistemine bağlanmış (mount edilmiş) olmasıdır: indirirken "aç" denmiş ya da dosyaya çift tıklanmış olabilir. "Bu bilgisayar" altında CD-ROM sürücüsü gibi görünen bu imaj sağ tıklanıp bağlantısı kaldırılırsa (unmount) VMware'de yeniden disk imajı dosyası olarak görünür. Bağlı haliyle de ISO'ya erişilebilir.

## 8. Ubuntu 20.04 Kurulumu

Kurulum başlarken sistem önce CD imajındaki dosya sistemini denetler, yani kurulum ortamının sağlam (intact) olup olmadığını kontrol eder. Bu kontrol Ctrl+C ile iptal edilebilir; derste iptal edildi.

Kurulum adımları:

- **Dil:** Kurulum İngilizce sürdürüldü.
- **Klavye düzeni:** Turkish (Türkçe Q) seçildi. Alttaki deneme kutusuna Türkçe karakterler yazılıp her şeyin yerinde olduğu kontrol edilebilir.
- **Kurulum türü:** Seçenekler zaman zaman değişir; normal kurulum seçildi.
- **Güncellemeler:** Kurulum çok uzun sürmesin diye kurulum sırasında güncellemelerin indirilmesi seçilmedi.

Bundan sonraki adım sanal diski biçimlendirmektir. Bu, diski bölümlere (partition) ayırmak ve her bölümün hangi biçimde ve hangi boyutta olacağını söylemek demektir.

## 9. Disk Bölümleme ve Dosya Sistemleri

### 9.1 Otomatik ve elle bölümleme

"Erase disk and install Ubuntu" seçilirse Ubuntu, makineye atanan 20 GB'lık sanal diski kendi bildiği gibi bölüp kullanır. Arka planda ne olduğunu görebilmek için önce "Something else" seçildi.

Yeni sanal disk, fiziksel bir bilgisayar için dışarıdan alınmış yeni bir iç disk kadar temizdir; üzerinde hiçbir şey yoktur. Bu yüzden önce diskin nasıl parçalanacağını tutan bir **bölüm tablosu (partition table)** oluşturulur. Bölüm tablosu oluşturulunca 20 GB'a, aslında biraz daha fazlasına karşılık gelen bir boş alan (free space) görünür; ekranda 21.5 GB yazıyordu (ekrandan, 00:45:00).

> **Ek bilgi (derste anlatılmadı):** Sanallaştırma yazılımlarındaki "GB" çoğunlukla ikili önekle (GiB, $2^{30}$ bayt) hesaplanır, kurulum programları ise ondalık GB ($10^9$ bayt) gösterir. "20 GB biraz daha fazlasına karşılık geliyor" görüntüsünün nedeni büyük olasılıkla budur.

> **Ders sonrası not:** Python ile hesap: $20 \times 1024^3 = 21\,474\,836\,480$ bayt $\approx 21.47$ GB; $20 \times 1024 = 20480$ MiB $\approx 21474.8$ MB. Ekranda görülen 21.5 GB ve 21475 MB değerleri bununla uyumludur.

### 9.2 Bölüm oluşturma penceresi

Boş alan seçilip "+" düğmesine basıldığında "Create partition" penceresi açılır (ekrandan, 00:45:00). Pencere şunları sorar:

- **Size:** bölümün boyutu (ekranda 21475 MB, yani boş alanın tamamı).
- **Type for the new partition:** bölümün birincil (Primary) mi mantıksal (Logical) mı olacağı.
- **Location for the new partition:** verilen boyuttaki bölümün boş alanın başına mı (Beginning of this space) sonuna mı (End of this space) yerleşeceği.
- **Use as:** bölümün dosya sistemi; ekranda "Ext4 journaling file system" seçiliydi.
- **Mount point:** bölümün bağlanacağı nokta; ekranda `/`.

Dosya sistemi listesinde ext2, ext3, ext4 gibi pek çok seçenek vardır. Bir şey değiştirilmezse varsayılan ext4'tür. XFS, Btrfs ve benzerleri de kullanılabilir; bunlar Linux ve Unix'in doğasında olan dosya sistemleridir. FAT16 ve FAT32 eski Windows sistemlerinin kullandığı dosya sistemleridir; burada onlarla devam etmenin bir anlamı yoktur.

<!-- BELİRSİZ: Altyazıda "CFS, XFS, BTRFS" geçiyor; ilk ad büyük olasılıkla JFS'dir, karede bu liste görünmüyor. -->

### 9.3 Kaç bölüm, hangi bağlama noktası?

Burada iki soru vardır: kaç bölüm oluşturulacak ve her birine ne atanacak? En basit kurulum şudur: tek bir bölüm oluşturulur, bağlama noktası kök (`/`) seçilir, dosya sistemi ext4 yapılır ve devam edilir. Bu bir yöntemdir. Ama "Change" ile bakıldığında oluşturulan bölüme atanabilecek farklı bağlama noktaları olduğu görülür. Ekrandaki listede `/`, `/boot`, `/home`, `/tmp`, `/usr`, `/var`, `/srv`, `/opt`, `/usr/local` vardı (ekrandan, 00:50:00).

## 10. Linux Dosya Sistemi Hiyerarşisine Giriş

### 10.1 Windows ile karşılaştırma

Dosya sistemi, diski kullanmayı sağlayan mantıksal, hiyerarşik bir düzendir. Windows'ta bölümler genelde C, D, E, F gibi harflerle görünür. C bölümündeki bir klasöre ulaşmak için `C:` ile başlayıp `Users` ve kullanıcı klasörü üzerinden ilerleyen hiyerarşik bir yol yazılır.

Unix ve Linux'ta dosya sistemi kökten (root, `/`) başlar. `/` dosya sisteminin kökü, en başlangıç noktasıdır ve altında belli bir yapı vardır. Kök noktası bir bölüme atandığında, kökün altında `boot`, `home`, `tmp`, `usr`, `var`, `srv`, `opt`, `sbin`, `lib`, `etc` gibi klasörleri içeren hiyerarşik bir yapı oluşur.

### 10.2 Klasörleri ayrı bölümlere bağlamak

Linux'ta şöyle bir esneklik vardır: kökün altındaki, hatta kökün altındaki herhangi bir klasörün içindeki başka bir klasör ayrı bir bölüme bağlanabilir. Kurulumda örneğin bir kök bölümünün yanında ayrı bir `boot` bölümü, bir `swap` bölümü ya da başka bölümler oluşturulabilir. Bunun nedeni, dosya sistemindeki her noktanın farklı bir amacının olmasıdır.

**`/var` örneği:** `var`, "variable" kelimesinin kısaltmasıdır ve sürekli değişen bir yerdir. Bunun nedeni `var/log` altında sistemin ve birçok uygulamanın bütün loglarının durmasıdır; oraya sürekli yazılır. Her şey tek bir kök bölümüne konursa ve bu düşünülmezse, bir bakarsınız disk dolmuş, komutların yarısı çalışıyor yarısı çalışmıyor; makine bir yandan canlı, bir yandan ölü gibidir.

**`/home` örneği:** `home`, sistemdeki kullanıcıların kendi ürettikleri belgelerin durduğu yerdir. Kurulumda bir kullanıcı oluşturulur; ileride ikinci, beşinci, yirminci kullanıcılar da oluşturulabilir ve her biri için `home` altında yeni bir klasör açılır. Bu kullanıcılar kişisel bir bilgisayarın kullanıcıları değil de bir sunucudan hizmet alan kullanıcılar olsaydı, ürettikleri bilgi ve belgeler önemli olurdu; belki bunlara daha hızlı erişilmesi ve yazılması istenirdi. O zaman `home` ayrı bir bölüm yapılıp fiziksel olarak başka bir diske atanabilirdi: `sda1` yerine `sdb` ya da `sdc` gibi bambaşka bir diske.

**`/boot` örneği:** `boot` altındakiler açılış anında çalışması gereken dosyalardır; normalde buraya kullanıcı bir şey yazmaz. Özellikle sunucu kurulumlarında `boot` ayrı bir bölüm olarak ve salt okunur oluşturulur, yalnız açılış anında okunsun ve kimse yazamasın diye korunur. Böylece açılışla ilgili bir saldırı ya da işlem olursa etkilenmemesi sağlanır.

**`/bin` ve `/sbin`:** `bin`, sistemin çalıştırılabilir programlarının (binary) durduğu yerdir. `sbin` ise süper kullanıcının, yani root'un programlarının durduğu klasördür.

## 11. Linux'ta Kullanıcılar ve Root

Linux'ta kullanıcılar hiyerarşik bir yapıdadır; haklar ve gruplar düzeyinde bir organizasyon vardır. Windows'ta genelde Administrator ya da admin görülür. Linux'ta her zaman bir **root** kullanıcısı vardır ve sistemdeki her türlü yetki ona aittir.

Ubuntu kurulumu root kullanıcısını oluşturtmaz; bir kullanıcı oluşturtur ve ona yönetici hakkı verir. Genel olarak Linux'ta, özellikle masaüstü sürümlerinde, root kullanıcısıyla sisteme girilmesi istenmez. Çünkü root her şeyi yapma hakkına sahiptir: yanlışlıkla `bin` klasörünü silebilirsiniz ve kimse buna engel olmaz, çünkü root olarak bunu yapma hakkınız vardır, belki de yapmanız gerekiyordur. Ters bir hareket ya da anlık yanlış bir kararla sistem bir anda çalışmaz hale gelebilir. Bu yüzden özellikle grafik girişlerde sistem sizi sıradan bir kullanıcıyla içeri alır.

Özel bir şey çalıştırmak gerektiğinde root yetkisi almanın iki yolu vardır: `su` ile root kullanıcısına geçilir (kullanıcı değiştirilir) ya da `sudo` ile bir program veya komut sanki root kullanıcısıymışsınız gibi çalıştırılır. Bu geçiş sırasında bir şifre sorulur. Nitekim kurulumdan sonra açılan terminalde de "To run a command as administrator (user "root"), use "sudo <command>"." mesajı görünür (ekrandan, 01:10:00).

> **Ders sonrası not:** Hoca, kurulumda verilen şifrenin sistemdeki root kullanıcısının da şifresi olacağını ve geçişte root'un şifresinin sorulacağını söyledi. Ubuntu'da root hesabı varsayılan olarak kilitlidir; kurulumda oluşturulan kullanıcı `sudo` grubuna eklenir ve `sudo` kullanıcının kendi şifresini sorar. `su` ise hedef kullanıcının (root'un) şifresini ister.

> **Ders sonrası not:** Hoca `sbin` içindeki programların yalnız root tarafından görülebildiğini söyledi. `sbin` klasörü normal kullanıcılar tarafından da görülebilir; içindeki programlar çoğunlukla yönetici yetkisi gerektiren sistem programlarıdır.

## 12. Kurulumun Tamamlanması ve İlk Açılış

Bu açıklamalardan sonra bölümleri tek tek oluşturmak yerine geri dönülüp "Erase disk and install Ubuntu" seçildi; amaç, kurulum bittikten sonra Ubuntu'nun neyi nasıl yaptığını birlikte görmekti. Kurulum, diske yazılacağı ve daha önce yazılmış bir şey varsa silineceği konusunda uyarır; bölüm tablosunun ve iki bölümün oluşturulacağını bildirip onay ister.

Sonraki adımlar:

- **Konum ve saat dilimi:** Sistemin saatini ayarlamak için önemlidir; haritadan seçilebilir ya da yazılabilir.
- **Kullanıcı bilgileri:** ad, bilgisayar adı, kullanıcı adı ve şifre verilir. Kullanıcı adı sisteme girişte kullanılacaktır.

> **Hocanın vurgusu:** Kurulumda verdiğiniz şifreyi unutmayın; daha sonra kullanılacaktır.

Seçimler yapılırken kurulum arka planda dosyaları kopyalamaya başlar ("Copying files..."), ardından donanımı yapılandırır ("Configuring hardware...") (ekrandan, 00:55:00 ve 01:00:00).

Kurulum bitince işletim sistemi yeniden başlatma ister. Bu yalnız sanal makinenin yeniden başlatılmasıdır, bu yüzden sakıncası yoktur; "Restart now" denir. Kurulum başında sanal makinenin CD-ROM'u ISO imajına bağlanmıştı. Yeniden başlatmada sistem "Please remove the installation medium, then press ENTER:" mesajını verir (ekrandan, 01:05:00). Kurulum için kullanılan çıkarılabilir aygıt VMware menüsünden bağlanıp çıkarılabilir (connect/disconnect); derste yalnız Enter'a basıldı ve VMware bağlantıyı kendisi kopardı. Ardından belirlenen şifreyle grafik oturuma girildi.

İlk girişte çevrimiçi hesaplar gibi birkaç tanıtım ekranı geçilir. Grafik ekran sanal makine penceresinde küçük görünebilir; bu ayarlanabilir: Settings > Displays altından çözünürlük, uygun olan değere çevrilir. Masaüstü yapısı Windows'a çok benzer: dosya sisteminde gezinmek için klasörlere tıklanır, Documents, Music gibi klasörler vardır.

## 13. Terminal ve Kök Klasörlerin Görevleri

### 13.1 Terminali açmak ve gezinmek

Alt ve F2 tuşlarına birlikte basıldığında bir komut çalıştırma kutusu açılır. Buraya `gnome-terminal` yazıldığında bir komut istemi (terminal) açılır; bu, işletim sistemi komutlarının çalıştırılabildiği alandır.

Ekranda yapılanlar (ekrandan, 01:15:00):

```text
$ pwd
/home/<kullanıcı>
$ cd /
$ ls
bin    dev   lib    libx32      mnt   root  snap      sys  var
boot   etc   lib32  lost+found  opt   run   srv       tmp
cdrom  home  lib64  media       proc  sbin  swapfile  usr
```

`pwd` komutu dosya sistemi üzerinde hangi klasörde bulunulduğunu gösterir: kökün altında `home`, onun altında kullanıcının klasörü. `cd /` (change directory) ile kök klasöre geçilir, `ls` ile içindekiler listelenir. Kurulum sırasında konuşulan farklı klasörler burada görünür.

### 13.2 Kök klasörlerin görevleri

- **`bin`:** sistemin çalıştırılabilir programları (binary'ler).
- **`boot`:** önyükleyici (boot loader) ile ilgili dosyalar.
- **`cdrom`:** her dağıtımda bulunmak zorunda değildir, isteğe bağlıdır; `mnt` ya da `media` altında da olabilir.
- **`dev`:** Linux'ta bütün donanımlar aygıttır (device): takılan USB bellek, harici disk, disk ve diğerleri. Aygıt sisteme bağlandığında ilgili sürücü yüklenir; sürücü `dev` altında bir dosya oluşturur. Bu dosya karakter ya da blok aygıt türündedir. Aygıtla bu dosyaya yazıp ondan okuyarak iletişim kurulur.
- **`etc`:** Bazı kaynaklarda "Everything To Configure" diye açıklanır. Sistemde çalışan bütün uygulamaların ve servislerin yapılandırma dosyaları buradadır; sistemin yapılandırması genel olarak buradan yapılır.
- **`home`:** sistemdeki kullanıcıların klasörleri. Herkesin kendi klasörü vardır; bir kullanıcı, özel yetkisi yoksa diğerinin bilgilerine erişemez.
- **`lib`:** sistemdeki uygulamaların kullanacağı kütüphaneler (library). `lib32`, `lib64` gibi sürümleri vardır; bu dağıtıma bağlıdır.
- **`media`:** genel amaçlı bir klasördür. Altına klasörler açılıp harici disk ya da USB gibi ortamların bağlama noktası burası yapılır. Bazı dağıtımlarda bu iş `mnt` altında, bazılarında her ikisinde görülür.
- **`proc`:** sanal bir yapıdır, sistemle ilgili bilgileri tutar: işlemcinin ne olduğu, üzerindeki firmware, donanım seviyesi, belleğin durumu ve benzeri.
- **`opt`:** "optional" kısaltması. Dağıtımla gelen paketler `bin`, `sbin` ve başka yerlere kurulur. Dışarıdan kaynak kodu getirilip derlenen ya da dağıtımla gelmeyen, paketlenmiş yazılımlar ise `opt`'a kurulur.
- **`root`:** root kullanıcısının ev klasörü. Root'un da bir ev klasörü olmalıdır, ama diğer kullanıcılarla birlikte `home` altında tutulmaz.
- **`run`:** eskiden beri gelen bir klasör değildir, sonradan eklenmiştir. Sistem servislerinin ve süreçlerin çalışırken oluşturdukları geçici bilgilerin tutulduğu yerdir.
- **`sbin`:** süper kullanıcıya (root) yönelik programlar.
- **`srv`:** sistem bir servis verecekse (örneğin web sitesi barındırma ya da DNS) bununla ilgili dosyaların tutulduğu yer.
- **`tmp`:** yalnız sizin değil, bütün kullanıcıların ve çalışan servislerin, uygulamaların geçici amaçla oluşturduğu bilgilerin yeri.
- **`sys`:** `proc` ve `dev` gibi sanal klasörlerden biridir; bağlı aygıtlarla ilgili temel bilgileri gösterir.
- **`var`:** "variable" kısaltması. `/var/log` listelendiğinde yalnız log dosyaları görülür: yetkilendirme logu (`auth.log`), `boot.log`, `bootstrap.log`, sistemin açılışındaki mesajlar (`dmesg`) ve sistem mesajlarının döküldüğü `syslog`.

<!-- BELİRSİZ: /var/log listesi karede görünmüyor; dosya adları altyazıdan ("authorization log, bootlog, bootstrap log, d messages, syslog") alındı. -->

> **Ek bilgi (derste anlatılmadı):** `etc` adının "Everything To Configure" açılımı sonradan uydurulmuş bir açıklamadır; ad büyük olasılıkla Latince "et cetera" (ve diğerleri) ifadesinden gelir. Erken Unix sistemlerinde başka bir yere sığmayan dosyalar bu klasöre konuyordu.

## 14. Neden Linux?

Dersin sonundaki soru-cevapta Linux'un diğer işletim sistemlerine göre avantajları soruldu. Hoca, işletim sistemlerinin tek tek karşılaştırılmasının bir işletim sistemleri kitabının konusu olduğunu, soruyu bir bilgisayar mühendisliği öğrencisi açısından Windows ile karşılaştırarak cevaplayacağını söyledi.

- **Windows:** Masaüstünde pazar payı ve kullanım alışkanlığı bakımından çok yaygındır, ama hocaya göre birçok yönden sorunlu ve genel olarak çok kararlı olmayan bir işletim sistemidir. Bu, tarihsel gelişimi bilinince daha iyi anlaşılır: Windows 3.1, NT, ME, XP, 7, 10 gibi masaüstü sürümleri ve NT ile başlayan sunucu sürümleri vardır. Sunucu sürümleri daha sağlam ve kararlı sayılsa da Windows'un zaman zaman yaptığını söylediği şeyi gerçekten yapamadığı, belirtilen özelliklerde çalışmadığı görülür. Ayrıntıları ileriki yılların konusudur.
- **Unix/Linux:** Çıkış noktası, yapısı ve topluluk desteği nedeniyle genellikle sunucu sistemlerinde çalışır. Masaüstü sürümü, sunucu sürümünün biraz kırpılmış, biraz da eklenmiş halidir (örneğin grafik arayüz eklenmiştir). Grafik arayüz sistemi bile sunucu olarak çalışmak üzere tasarlanmıştır: arka planda bir X Window servisi (X sunucusu) vardır ve ona yerelden bağlanan bir pencere yöneticisi (window manager) ve oturum yöneticisi (session manager) vardır. Standart olarak X sunucusu çok sayıda kullanıcıya hizmet verebilir. Windows'ta son on yıl içinde yaygınlaşan uzak masaüstü erişimi, Linux'ta ilk sürümlerden beri yapılabiliyordu.
- **Linux'un dezavantajı:** Windows daha yaygındır. Oyun ya da multimedya işleri için Windows'ta daha çok uygulama ve eğitim kaynağı bulunur ve bunlar daha rahat kullanılır.

> **Hocanın vurgusu:** Bilgisayar mühendisliği öğrencisi ilk dakikadan itibaren bir Linux işletim sistemi kullanıyor olmalıdır. Bir işletim sisteminin ne yapması gerektiği tarif edildiğinde, bu tariflerin yüzde 90-95'ini yerine getiren işletim sistemi Linux'tur; Windows'ta kaynak yönetimi ve korumalı çalışma gibi özelliklerin büyük kısmı yoktur. İleride ne iş yapılırsa yapılsın, iş bir şekilde Linux'a ulaşacaktır.

<!-- BELİRSİZ: Windows sürüm listesinde altyazıda "3.1, 5, NT, MI" geçiyor; "5" büyük olasılıkla Windows 95, "MI" Windows ME'dir. -->

## Örnek Sorular

**Soru 1** (derste sözlü, 00:26:50): İndirdiğim Ubuntu imajı VMware'in yeni makine sihirbazında "Installer disc" kısmında, yani bir disk olarak görünüyor. Neden?

> **Cevap (derste verildi):** ISO dosyası işletim sistemine bağlanmış (mount edilmiş) olduğu için. İndirirken açılmış ya da çift tıklanmışsa Windows imajı bir CD sürücüsü gibi bağlar ve "Bu bilgisayar" altında CD-ROM olarak görünür. Sağ tıklanıp bağlantısı kaldırılırsa (unmount) VMware'de yeniden "Installer disc image file (iso)" olarak seçilebilir.

**Soru 2** (derste sözlü, 00:56:12): Bölümleme adımında bağlama noktası (mount point) olarak ne seçildi?

> **Cevap (derste verildi):** Hiçbir bağlama noktası seçilmedi. "Create partition" penceresi yalnız seçenekleri göstermek için açıldı; sonra geri dönülüp "Erase disk and install Ubuntu" seçildi ve bölümlemeyi Ubuntu kendisi yaptı. Elle yapılacaksa en basit düzen, tek bir ext4 bölümü ve bağlama noktası olarak `/` seçmektir.

**Soru 3** (derste sözlü, 01:18:58): Linux kullanmanın diğer işletim sistemlerine göre avantajları nedir?

> **Cevap (derste verildi):** Linux, bir işletim sisteminden beklenen işlevlerin yüzde 90-95'ini (kaynak yönetimi, korumalı çalışma vb.) karşılar. Sunucu kökenlidir; grafik arayüzü bile çok kullanıcıya hizmet veren bir X sunucusu üzerine kuruludur ve uzak erişim ilk sürümlerden beri vardır. Windows ise masaüstünde yaygın olduğu için oyun ve multimedya uygulamaları ve eğitim kaynakları bakımından avantajlıdır. Bilgisayar mühendisliği öğrencisi için Linux önerilir.

**Soru 4** (derste sözlü, 01:23:55): Kurduğumuz sanal makinedeki işletim sisteminde kablosuz bağlantı kullanılabilir mi?

> **Cevap (derste verildi):** Evet, mümkündür.

> **Ek bilgi (derste anlatılmadı):** Sanal makine genellikle kablosuz kartı doğrudan görmez; ana bilgisayarın (kablolu ya da kablosuz) bağlantısını NAT ya da bridge üzerinden sanal bir ağ kartı olarak kullanır. Konuk sistem bu bağlantıyı büyük olasılıkla kablolu bir ağ gibi görür.

## Dersin Toparlaması

Bu laboratuvarda bilgisayar sisteminin donanım, işletim sistemi ve uygulama katmanlarından yola çıkılarak sanallaştırma kavramı tanıtıldı ve uygulama seviyesi sanallaştırmayla, Windows üzerinde çalışan VMware Workstation 16 Player içinde Ubuntu 20.04 kuruldu. Sanal makinenin oluşturulmasında Easy Install yerine boş diskle başlanarak disk boyutu, disk dosyalarının bölünmesi, bellek, işlemci ve ağ (NAT, bridge) ayarları, ISO imajından boot etme ve Ubuntu kurulum adımları tek tek görüldü. Bölümleme sırasında bölüm tablosu, birincil ve mantıksal bölümler, ext4 gibi dosya sistemleri ve bağlama noktaları açıklandı; bu vesileyle Linux dosya sistemi hiyerarşisi ve `/var`, `/home`, `/boot` gibi klasörlerin neden ayrı bölümlere konabildiği tartışıldı. Root kullanıcısının neden günlük işlerde kullanılmadığı ve `su`/`sudo` ile nasıl yetki alındığı anlatıldı. Kurulumdan sonra terminalde `pwd`, `cd`, `ls` komutlarıyla kök klasörler tek tek gezildi.

Sonraki laboratuvarda bu sistemin kullanımına devam edileceği, komut satırında kullanılabilecek komutların, ne işe yaradıklarının ve sistemde tarayıcı gibi programların nasıl kullanılacağının konuşulacağı söylendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
