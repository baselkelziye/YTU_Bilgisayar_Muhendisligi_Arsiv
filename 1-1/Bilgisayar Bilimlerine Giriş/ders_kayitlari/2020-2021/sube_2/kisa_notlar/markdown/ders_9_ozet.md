# Ders 9 Çalışma Özeti

## Genel Konular

- Bilgisayar sisteminin katmanları ve sanallaştırma fikri
  - En altta donanım katmanı (işlemci, bellek, disk) vardır. Onu yöneten ve kullanmamızı sağlayan işletim sistemi, onun üzerinde de uygulamalar çalışır.
  - Sanallaştırma, aslında fiziksel olarak ayrı bulunmayan kaynakları birilerine ayırmak (allocate etmek) demektir. Bu derste amaç, bu katmanlı yapıyı sanal bir ortamda kurmaktır.
- Sanallaştırmanın yapılabildiği katmanlar
  - Donanım (fiziksel) seviyesi: tek bir makinedeki işlemciler ve bellek, donanım desteğiyle ayrı makinelermiş gibi bölünebilir. Bu daha çok sunucularda görülür: IBM'in P serisi RISC makinelerinde uzun zamandır vardır; Intel tabanlı (x86, CISC) sunucularda da yaygındır.
  - İşletim sistemi seviyesi.
  - Uygulama seviyesi: işletim sistemi üzerinde çalışan bir uygulama, istenen donanım özelliklerinde sanal bir makine tanımlar. Derste bu yol izlendi (VMware Workstation 16 Player).
- Dual boot ile sanal makinenin karşılaştırılması
  - Dual boot'ta iki işletim sistemi aynı diske kurulur, açılışta biri seçilir; aynı anda yalnız biri çalışır. Kurulum sırasındaki bir hata ya da yapılandırma sorunu makineyi kullanılamaz hale getirebilir.
  - Sanal makinede konuk (guest) Linux, çalışan Windows içindeki bir uygulamanın içinde çalışır. İkisi aynı anda kullanılabilir; konuk sistem bir uygulama gibi açılıp kapatılır.
  - Eksisi: sanal makine de arka planda fiziksel kaynakları kullanır. Bilgisayarın kaynakları azsa ikisini aynı anda çalıştırmak zorlayabilir.
- VMware ürünleri ve kurulum
  - VMware profesyonel, lisanslı sanallaştırma ürünleri satar: sunucu tarafında ESX Server, masaüstünde Workstation ve onun ücretsiz Player sürümü. Player, ticari olmayan (non-commercial) kullanımda lisans istemeden birden fazla sanal makine oluşturmaya izin verir.
  - Kurulum sihirbazında birkaç onay kutusu dışında özel bir ayar yoktur (ekrandan, 00:15:00). Kurulumdan sonra bilgisayarın yeniden başlatılması gerekir.
  - Hangi sanallaştırma yazılımının kullanıldığı önemli değildir (VirtualBox gibi alternatifler de olur). macOS için VMware Fusion'ın kişisel kullanım lisansı ya da VirtualBox önerildi.
- Yeni sanal makine oluşturma (ekrandan, 00:25:00 ve 00:30:00)
  - Kurulum kaynağı seçenekleri: fiziksel kurulum diski, kurulum disk imajı (ISO) ya da "işletim sistemini sonra kuracağım" (boş sabit diskle makine oluşturulur).
  - ISO seçilirse VMware "Ubuntu 64-bit 20.04.1 detected" der ve Easy Install kullanır: kullanıcı adı ve şifre verilir, kurulum soru sormadan biter. Kurulumdaki seçimleri görmek için Easy Install kullanılmadı, makine boş diskle oluşturuldu.
  - Konuk işletim sistemi: Linux, Ubuntu 64-bit. Makine adı serbesttir. Makine dosyaları varsayılan olarak Documents altındaki Virtual Machines klasöründe tutulur.
- Sanal disk ve donanım ayarları
  - Ubuntu için önerilen disk boyutu 20 GB'dır (ekrandan, 00:35:00). Hoca kabaca en az 8 GB gerektiğini söyledi.
  - Sanal disk tek dosya ya da birden çok dosya olarak saklanabilir. Birden çok dosya, makineyi başka bilgisayara taşımayı kolaylaştırır ve alttaki depolama yapısına göre erişimi hızlandırabilir. Derste "Split virtual disk into multiple files" seçildi.
  - VMware varsayılan olarak 4 GB bellek, 2 işlemci çekirdeği ve NAT ağ bağlantısı atadı.
  - Ağ bağlantısı yolları: fiziksel ağ kartını sanal makineye doğrudan tanıtmak (bridge) ya da içeride sanal bir switch kurup bir ucuna bilgisayarın internet bağlantısını, diğer uçlarına sanal makineleri bağlamak (NAT).
  - Boş diskli makine açılınca BIOS mesajları görünür ama boot edilecek bir şey yoktur. Makine kapatılır, ayarlardan CD-ROM'a ISO dosyası bağlanır ve yeniden başlatılır.
- Ubuntu 20.04 kurulumu
  - Açılış menüsünde: kurmadan deneme, kurulum, bellek testi ve sabit diskten açılış seçenekleri vardır. Başta kurulum medyasının bütünlüğü denetlenir; Ctrl+C ile atlanabilir.
  - Kurulum dili İngilizce, klavye düzeni Turkish (Türkçe Q) seçildi. Normal kurulum seçildi; kurulum uzamasın diye güncellemeler indirilmedi.
  - Disk biçimlendirme: diski bölümlere (partition) ayırmak, her bölümün boyutunu ve dosya sistemini belirlemektir. "Erase disk and install Ubuntu" diski otomatik böler; "Something else" elle bölümlemeye izin verir.
  - Boş bir diskte önce bölüm tablosu (partition table) oluşturulur, sonra boş alandan bölüm eklenir. Bölüm oluşturma penceresi boyut, birincil/mantıksal (Primary/Logical), boş alanın başı/sonu, dosya sistemi ve bağlama noktası (mount point) sorar (ekrandan, 00:45:00).
  - Dosya sistemi seçenekleri: ext2, ext3, ext4 (varsayılan), XFS, Btrfs ve benzeri Linux/Unix dosya sistemleri. FAT16 ve FAT32 eski Windows dosya sistemleridir, burada kullanılmaz.
  - En basit kurulum: tek bölüm, bağlama noktası `/` (kök), dosya sistemi ext4. Derste sonunda otomatik bölümleme seçildi.
  - Saat dilimi seçilir, sonra kullanıcı adı, bilgisayar adı ve şifre verilir.
  - Kurulum bitince sanal makine yeniden başlatılır; "kurulum medyasını çıkarıp Enter'a basın" mesajı gelir (ekrandan, 01:05:00).
- Linux dosya sistemi hiyerarşisi
  - Windows'ta bölümler C, D, E gibi harflerle görünür ve yol `C:\Users\...` biçimindedir. Linux'ta hiyerarşi kökten (`/`) başlar.
  - Kökün ya da kök altındaki herhangi bir klasörün ayrı bir bölüme bağlanabilmesi esneklik sağlar. Kurulumda bağlama noktası listesinde `/`, `/boot`, `/home`, `/tmp`, `/usr`, `/var`, `/srv`, `/opt`, `/usr/local` vardı (ekrandan, 00:50:00).
  - Kurulumdan sonra `pwd` ile bulunulan klasör (`/home/<kullanıcı>`), `cd /` ile köke geçiş, `ls` ile kök klasörleri gösterildi (ekrandan, 01:15:00).
- Linux'ta kullanıcılar ve root
  - Her Linux'ta bütün yetkilere sahip bir root kullanıcısı vardır. Masaüstü sürümlerde root ile grafik oturum açılması istenmez; kurulum sıradan bir kullanıcı oluşturur ve ona yönetici hakkı verir.
  - Özel bir işlem için `su` ile root kullanıcısına geçilir ya da `sudo` ile bir komut root yetkisiyle çalıştırılır.
- Linux'un avantajları (soru-cevap)
  - Linux, işletim sisteminden beklenen işlevlerin büyük kısmını (kaynak yönetimi, korumalı çalışma) karşılar. Sunucu kökenli olduğu için grafik arayüzü bile istemci-sunucu yapısındadır (X Window sunucusu, pencere ve oturum yöneticisi); uzak masaüstü erişimi ilk sürümlerden beri vardır.
  - Windows masaüstünde yaygındır, oyun ve multimedya için daha çok uygulama ve kaynak bulunur. Hoca, bilgisayar mühendisliği öğrencisinin ilk günden Linux kullanması gerektiğini söyledi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Laboratuvarın amacı belirli bir Ubuntu sürümünü kurmak değil, Linux'a adım atmaktır
  - Ubuntu 16, 18 ya da 20, VMware ya da VirtualBox fark etmez. Önemli olan temel işleri yapabilecek bir Linux ortamının olmasıdır; sonraki laboratuvarlarda C programlama bu ortamda yapılacaktır.
- Dual boot yerine sanal makine
  - Dual boot kurulumunda yapılacak bir hata ya da yapılandırma sorunu bilgisayarı kullanılamaz hale getirebilir. Sanal makinede bu risk yoktur, ama kaynak paylaşımı vardır.
- Kurulumu Easy Install ya da otomatik ayarlarla geçmemek
  - Arka planda neyin nasıl seçildiğini görmek için kurulum adım adım ve konuşularak yapıldı.
- `/var` gibi sürekli yazılan klasörlerin ayrı bölümde tutulması
  - Her şey tek bir kök bölümündeyse loglar diski doldurduğunda sistem yarı çalışır hale gelebilir.
- Root ile oturum açmamak
  - Root her şeyi yapabilir; yanlışlıkla `bin` klasörünü silmek gibi bir hata sistemi anında çalışmaz hale getirir. Bu yüzden normal kullanıcıyla çalışılır, gerektiğinde root yetkisi alınır.
- Kurulumda verilen şifreyi unutmamak
  - Bu şifre sonradan sisteme girişte ve yönetici işlemlerinde kullanılacaktır.

## Kısa Tekrar Notları

- Katmanlar: donanım, işletim sistemi, uygulamalar.
- Sanallaştırma seviyeleri: donanım, işletim sistemi, uygulama. Derste uygulama seviyesi (VMware Workstation 16 Player) kullanıldı.
- Sanal makine: konuk sistem ana sistemle aynı anda çalışır; dezavantajı ortak fiziksel kaynak kullanımıdır.
- Yeni sanal makine: "I will install the operating system later", Linux / Ubuntu 64-bit, 20 GB disk, birden çok dosyaya bölünmüş disk, 4 GB bellek, 2 çekirdek, NAT.
- ISO, CD/DVD imajıdır; sanal makinenin CD-ROM'una bağlanarak boot edilir.
- Kurulum: Turkish klavye, normal kurulum, güncelleme indirmeden; "Erase disk and install Ubuntu" ya da "Something else" ile elle bölümleme.
- Bölüm oluştururken: boyut, Primary/Logical, boş alanın başı/sonu, dosya sistemi (varsayılan ext4), mount point.
- Kök klasörler: `bin`, `boot`, `dev`, `etc`, `home`, `lib`, `media`, `mnt`, `opt`, `proc`, `root`, `run`, `sbin`, `srv`, `sys`, `tmp`, `usr`, `var`.
- `/etc` yapılandırma dosyaları, `/home` kullanıcı klasörleri, `/root` root kullanıcısının ev klasörü, `/var/log` log dosyaları, `/dev` aygıt dosyaları, `/proc` ve `/sys` sanal klasörler.
- Komutlar: `pwd`, `cd /`, `ls`, `ls /var/log`. Alt+F2 ile `gnome-terminal` açılır.
- Root her yetkiye sahiptir; günlük işte normal kullanıcı kullanılır, gerektiğinde `su`/`sudo`.

## Detaylı Açıklamalar

- **Sanallaştırma neden ve nasıl?** Bir bilgisayar sistemi donanım, işletim sistemi ve uygulama katmanlarından oluşur. Sanallaştırma bu katmanlardan birinde yapılabilir. Donanım seviyesinde (IBM P serisi RISC sunucuları, x86 sunucular) bir makinenin işlemcileri ve belleği donanım desteğiyle ayrı makineler gibi bölünür. Derste kullanılan uygulama seviyesi sanallaştırmada ise Windows üzerinde çalışan VMware, istenen işlemci, bellek, disk ve ağ özelliklerine sahip sanal bir makine tanımlar; Linux bu sanal makineye kurulur. Bu durumda bilgisayarda teknik olarak ikinci bir işletim sistemi kurulmuş olmaz; işletim sistemi sanal makinenin içine kurulur.

- **Sanal makinenin oluşturulması.** VMware Player'da sol tarafta mevcut sanal makineler listelenir; seçilen makinenin işletim sistemi, bellek miktarı gibi bilgileri görünür ve ayarlardan işlemci sayısı, bellek, USB denetleyicisi, ekran gibi her şey değiştirilebilir. Yeni makine sihirbazında ISO dosyası doğrudan verilirse VMware Ubuntu 20.04.1'i tanır ve Easy Install ile kurulumu kendisi yapar. Derste kurulum adımlarını görebilmek için "işletim sistemini sonra kuracağım" seçeneğiyle boş diskli bir makine oluşturuldu (ekrandan, 00:30:00). Disk için önerilen 20 GB kabul edildi ve disk birden çok dosyaya bölündü (ekrandan, 00:35:00). Boş diskli makine açıldığında fiziksel bir makinedeki gibi BIOS mesajları göründü, ama boot edilecek bir ortam olmadığı için makine kapatıldı; ayarlardan CD-ROM'a Ubuntu ISO dosyası bağlanıp makine yeniden başlatıldı.

- **Bölümleme ve dosya sistemi.** Yeni sanal disk, kutusundan yeni çıkmış bir disk gibi boştur. "Something else" seçildiğinde önce bir bölüm tablosu oluşturulur; ardından yaklaşık 21.5 GB'lık boş alan görünür. Bölüm oluşturma penceresinde boyut 21475 MB, tür Primary, konum "Beginning of this space", dosya sistemi "Ext4 journaling file system" ve bağlama noktası `/` görünüyordu (ekrandan, 00:45:00). Linux'ta kök altındaki herhangi bir klasör ayrı bir bölüme bağlanabilir. Örneğin `/home` ayrı bir bölüm, hatta ayrı bir disk (`sda` yerine `sdb`, `sdc`) yapılabilir; sunucularda kullanıcı verisine daha hızlı erişim için böyle yapılır. `/boot` sunucularda bazen ayrı ve salt okunur bir bölüm olarak kurulur, böylece bir saldırıda açılış dosyaları korunur. Derste bu seçenekler anlatıldıktan sonra geri dönülüp "Erase disk and install Ubuntu" seçildi ve bölümlemeyi Ubuntu otomatik yaptı.

> **Ders sonrası not:** Sihirbazdaki "20 GB" ikili önekle 20 GiB'dir: $20 \times 1024 = 20480$ MiB $= 21\,474\,836\,480$ bayt $\approx 21.47$ GB. Ubuntu kurulumunda 21.5 GB ve 21475 MB görünmesi bundandır (python ile hesaplandı).

- **Kök klasörlerin görevleri.** Kurulumdan sonra terminalde `ls /` çıktısında şu girdiler görüldü: `bin`, `boot`, `cdrom`, `dev`, `etc`, `home`, `lib`, `lib32`, `lib64`, `libx32`, `lost+found`, `media`, `mnt`, `opt`, `proc`, `root`, `run`, `sbin`, `snap`, `srv`, `swapfile`, `sys`, `tmp`, `usr`, `var` (ekrandan, 01:15:00).
  - `bin`: sistemin çalıştırılabilir programları. `sbin`: sistem yöneticisi (root) için olan programlar.
  - `boot`: önyükleyici (boot loader) ile ilgili dosyalar.
  - `cdrom`: her dağıtımda bulunmaz; CD bağlama noktası `mnt` ya da `media` altında da olabilir.
  - `dev`: Linux'ta her donanım (USB bellek, disk vb.) bir aygıttır. Aygıt takılınca sürücüsü yüklenir ve `dev` altında karakter ya da blok aygıt dosyası oluşur; aygıtla bu dosyaya yazıp okuyarak konuşulur.
  - `etc`: sistemde çalışan bütün uygulama ve servislerin yapılandırma dosyaları.
  - `home`: her kullanıcının kendi klasörü; kullanıcı, özel yetkisi yoksa diğerinin bilgisine erişemez.
  - `lib`, `lib32`, `lib64`: uygulamaların kullandığı kütüphaneler (dağıtıma göre değişir).
  - `media`, `mnt`: harici disk, USB gibi ortamların bağlama noktaları.
  - `opt`: dağıtımla gelmeyen, dışarıdan derlenen ya da paket olarak kurulan yazılımlar.
  - `proc`: işlemci, firmware, bellek durumu gibi sistem bilgilerini tutan sanal yapı. `sys`: bağlı aygıtlarla ilgili temel bilgileri gösteren sanal klasör.
  - `root`: root kullanıcısının ev klasörü; diğer kullanıcılarla birlikte `home` altında tutulmaz.
  - `run`: sonradan eklenmiş bir klasör; servislerin ve süreçlerin çalışırken oluşturduğu geçici bilgiler.
  - `srv`: web sitesi barındırma ya da DNS gibi bir servis verilecekse onun dosyaları.
  - `tmp`: bütün kullanıcıların ve servislerin geçici dosyaları.
  - `var`: "variable" kısaltması; sürekli değişen veriler. `/var/log` altında `auth.log`, `boot.log`, `bootstrap.log`, `dmesg` (açılış mesajları), `syslog` gibi log dosyaları vardır.

> **Ders sonrası not:** Hoca `sbin` içindeki programların yalnız root tarafından görülebildiğini söyledi; `sbin` normal kullanıcılar tarafından da görülebilir, içindeki programlar çoğunlukla yönetici yetkisi gerektiren sistem programlarıdır. Hoca kurulumda verilen şifrenin root kullanıcısının da şifresi olacağını söyledi; Ubuntu'da root hesabı varsayılan olarak kilitlidir, kurulumda oluşturulan kullanıcı `sudo` grubuna eklenir ve `sudo` kullanıcının kendi şifresini sorar.

- **Grafik arayüz ve terminal.** Kurulumdan sonra grafik masaüstüne girilir. Ekran küçük görünürse Settings > Displays altından çözünürlük değiştirilir. Alt+F2 ile açılan komut çalıştırma kutusuna `gnome-terminal` yazılarak terminal açılır; terminal, işletim sistemi komutlarının çalıştırıldığı alandır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
