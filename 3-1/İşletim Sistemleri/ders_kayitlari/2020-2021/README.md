# İşletim Sistemleri Ders Kayıtları & Çalışma Özetleri

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.

### 📋 Genel Bilgiler
* **Ders:** İşletim Sistemleri
* **Hoca:** Ali Gökhan Yavuz
* **Dönem:** Güz
* **Akademik Yıl:** 2020-2021

Bu dizin, ilgili ders kayıtlarının altyazı özetlerini, çalışma notlarını ve PDF kaynaklarını içermektedir.

## 📚 Ders Müfredatı ve Belge Dizini

Aşağıdaki tabloda her bir dersin konusu, kaynak markdown dosyası ve doğrudan indirilebilir PDF formatındaki derlenmiş halleri listelenmiştir.

| Ders No | Ders İçeriği / Konu Başlıkları | Kaynak Notlar (Markdown) | Çalışma Dosyası (PDF) |
| :---: | :--- | :---: | :---: |
| **Ders 1** | İşletim Sistemine Giriş: Tanım, Bilgisayar Organizasyonu, Tarihsel Gelişim | [Özet](altyazi_ozetleri/ders_1_ozet.md) | [PDF (İndir)](ders_1_ozet.pdf) |
| **Ders 3** | OS Temel Kavramlar: Servisler, Process Kavramı, Scheduling | [Özet](altyazi_ozetleri/ders_3_ozet.md) | [PDF (İndir)](ders_3_ozet.pdf) |
| **Ders 4** | OS Yapıları: Sistem Çağrıları, API, Kernel Mimarileri | [Özet](altyazi_ozetleri/ders_4_ozet.md) | [PDF (İndir)](ders_4_ozet.pdf) |
| **Ders 5** | Process Yönetimi: PCB, State, Context Switch | [Özet](altyazi_ozetleri/ders_5_ozet.md) | [PDF (İndir)](ders_5_ozet.pdf) |
| **Ders 6** | CPU Scheduling: Kriterler, Algoritmalar, Dispatcher | [Özet](altyazi_ozetleri/ders_6_ozet.md) | [PDF (İndir)](ders_6_ozet.pdf) |
| **Ders 6 Lab** | Shell Temelleri: Komutlar, İzinler, Script Yazımı | [Özet](altyazi_ozetleri/ders_6_lab_ozet.md) | [PDF (İndir)](ders_6_lab_ozet.pdf) |
| **Ders 7** | Thread Kavramı: Modeller, Kütüphaneler, Multi-core | [Özet](altyazi_ozetleri/ders_7_ozet.md) | [PDF (İndir)](ders_7_ozet.pdf) |
| **Ders 7 Lab** | Shell İleri: tr, awk, bc, Döngüler | [Özet](altyazi_ozetleri/ders_7_lab_ozet.md) | [PDF (İndir)](ders_7_lab_ozet.pdf) |
| **Ders 9** | CPU Scheduling Detay: Algoritmalar, Multi-Processor, OS Örnekleri | [Özet](altyazi_ozetleri/ders_9_ozet.md) | [PDF (İndir)](ders_9_ozet.pdf) |
| **Ders 9 Lab** | Processler Arası İletişim: Shared Memory, Message Passing, Producer-Consumer | [Özet](altyazi_ozetleri/ders_9_lab_ozet.md) | [PDF (İndir)](ders_9_lab_ozet.pdf) |
| **Ders 10** | Proses Senkronizasyonu: Mutex, Semafor, Klasik Problemler | [Özet](altyazi_ozetleri/ders_10_ozet.md) | [PDF (İndir)](ders_10_ozet.pdf) |
| **Ders 10 Lab** | Senkronizasyon Lab: Message Queue, Shared Memory, Monitör | [Özet](altyazi_ozetleri/ders_10_lab_ozet.md) | [PDF (İndir)](ders_10_lab_ozet.pdf) |
| **Ders 11** | Senkronizasyon Problemleri: Bounded-Buffer, Readers-Writers, Dining-Philosophers | [Özet](altyazi_ozetleri/ders_11_ozet.md) | [PDF (İndir)](ders_11_ozet.pdf) |
| **Ders 12** | Deadlock: Dört Koşul, Graf Analizi, Çözüm Yöntemleri | [Özet](altyazi_ozetleri/ders_12_ozet.md) | [PDF (İndir)](ders_12_ozet.pdf) |
| **Ders 14** | Ana Bellek Yönetimi: Base/Limit, MMU, Binding, Swapping | [Özet](altyazi_ozetleri/ders_14_ozet.md) | [PDF (İndir)](ders_14_ozet.pdf) |

> [!NOTE]
> Müfredat akışına göre *Ders 2* (13 Ekim 2020), *Ders 8* (24 Kasım 2020) ve *Ders 13* (29 Aralık 2020) kayıt altına alınmamıştır. Bu haftalarda ders yapılmamış veya kayıtlar paylaşılmamış olabilir.

## 🎯 Derslerin Detaylı Özetleri ve Kazanımları

### 🔹 Ders 1: İşletim Sistemine Giriş: Tanım, Bilgisayar Organizasyonu, Tarihsel Gelişim
* **Genel Konular:**
  - Dersin Tanıtımı ve İşleyişi
    - Ders iki grup halinde işlenir; iki hoca birlikte (Cihan ve Gökhan) dönüşümlü olarak anlatır. Aynı ders içeriği iki gruba da uygulanır, kayıtlar paylaşılır. Final ortaktır.
    - Kaynak olarak öncelikli olarak Silberschatz'un (Operating System Concepts) 8. baskısı kullanılır, ek olarak Stallings ve Tanenbaum/Bağman referans verilir. Konular Silberschatz'un ana çatısı üzerinden ilerler.
    - Dersin içeriği: storage management, process management, I/O management, memory management, protection and security, kernel data structures, computing environments, open source operating systems.
    - Bilgisayar sistemi dört ana bileşenden oluşur: donanım (CPU, bellek, G/Ç cihazları), işletim sistemi, sistem programları, uygulama programları.
    - İşletim sistemi, kullanıcı ile bilgisayar sistemi (donanım) arasındaki ara yüzü sağlayan program parçasıdır.
    - İşletim sisteminin iki temel rolü: kontrol programı (kaynak yönetimi) ve kolay kullanılabilir hale getirme.
  - İşletim Sisteminin Tanımı
    - Kullanıcı ile donanım arasındaki arayüz, bağlantıyı sağlayan program parçası.
    - Sistem iki açıdan ele alınabilir: kaynak yöneticisi (resource manager) ve kontrol programı (control program).
    - İşletim sisteminin başlıca hedefleri: programların çalıştırılması, kullanıcı problemlerinin çözümünün kolaylaştırılması, sistem kaynaklarının verimli kullanımı, kullanıcıyı donanım karmaşıklığından soyutlama.
  - Bilgisayar Sistem Organizasyonu
    - Tek bir CPU'nun temel bileşenleri: aritmetik-mantık birimi (ALU), register seti, kontrol birimi, veri yolu.
    - Her bir çevre biriminin bir denetleyicisi (controller) vardır; her cihaz kendi controller'ı aracılığıyla işlemciyle iletişir.
    - Bellek paylaşımlı bir yapıdadır; CPU, register'lar aracılığıyla belleğe yüklenir ve orada işlenir, sonuçlar tekrar belleğe yazılır.
    - Çok portlu bellek (multi-port memory) ile birden fazla cihaz aynı anda belleğe erişebilir.
  - Modern İşletim Sistemlerinin Tarihsel Gelişimi
    - Firmware: donanımın içine gömülü yazılım; BIOS bu örnektir. Anakart üzerinde bulunur, sistem açılışında çalışır.
    - Bootstrap: sistemin açılış süreci. BIOS, donanımı test edip bootloader'ı çalıştırır; bootloader ise işletim sistemini yükler.
    - İşletim sistemi çekirdeği (kernel): tüm temel bileşenlerin bir arada bulunduğu, donanımla etkileşen, sistem yönetimini sağlayan program.
* **Hocanın Vurgusu:**
  - İşletim Sisteminin İki Farklı Perspektiften Tanımı
    - Hoca özellikle vurgular: İşletim sistemi hem bir kontrol programı (kullanıcının donanımı doğrudan ve uygunsuz şekilde kullanmasını engelleyen) hem de bir kaynak yöneticisidir. Bu iki tanımı birleştirmek önemlidir.
    - "İşletim sistemi bir programdır" vurgusu tekrarlanır. Donanım seviyesinde de (firmware, embedded) yazılabilir; uygulama seviyesinde de (sistem uygulamaları) yazılabilir.
  - Veri Yapıları ve Algoritmaların Önemi
    - "İşletim sistemlerinin dayandığı iki temelden biri veri yapıları, diğeri algoritmalardır" cümlesi özellikle vurgulanır. Yönetilecek çok sayıda kaynak ve veri olduğundan uygun veri yapısı seçimi kritiktir.
    - Bu nedenle bu dersin kapsamında ilerleyen konularda (bellek yönetimi, süreç yönetimi, dosya sistemleri) sürekli veri yapılarına atıf yapılacaktır.
  - Kavram Karmaşası: Kernel, İşletim Sistemi, Sistem Programları
    - Hoca, "kernel" ile "işletim sistemi" kavramlarının sıklıkla karıştırıldığını vurgular. Kernel, donanımı çevreleyen ve sistem yönetimini sağlayan çekirdek programdır. İşletim sistemi ise kernel + sistem programlarını kapsayan daha geniş bir kavramdır.
* **Detaylı Açıklamalar:** Ders 1, 2020-2021 Güz dönemi İşletim Sistemleri dersinin ilk dersidir. Bu derste henüz ağırlıklı bir akademik içerik anlatılmaz; dersin tanıtımı, işleyişi, kaynakları ve işletim sisteminin temel kavramları üzerinde durulur. Hocalar, dersin pandemi nedeniyle uzaktan yürütüleceğini, kayıtların paylaşılacağını, iki grubun birleştirilerek işleneceğini açıklarlar. İşletim sisteminin tanımı birden fazla açıdan yapılır: kullanıcı ile donanım arasındaki arayüz, kaynak yöneticisi (CPU, bellek, G/Ç cihazları yönetimi), kontrol programı (kullanıcının uygunsuz erişimlerini engelleyen). İşletim sisteminin kendisinin de bir program olduğu, donanım seviyesinden uygulama seviyesine kadar farklı katmanlarda yazılabileceği belirtilir. Bilgisayar sistemi organizasyonu detaylı şekilde anlatılır: CPU, bellek (data + address bus), her çevre birimi için ayrı bir denetleyici (controller) ve cihaz, yerel tampon bellek. Çok portlu bellek yapılarıyla eşzamanlı erişim sağlanabildiği, dual-channel bellek teknolojisinin bu mantıkla çalıştığı açıklanır. İşletim sisteminin tarihsel gelişimi içerisinde firmware (BIOS) ve bootstrap süreçleri, kernel (çekirdek) kavramı, shell (kabuk) kavramı, sistem çağrıları gibi temel kavramlar tanıtılır. Hocalar, derste iki temel yaklaşımı vurgular: (1) Kavramların nereden geldiğini anlamak (tarihsel gelişim), (2) Uygulama geliştirirken arka planda nelerin döndüğünü bilmek (performans ve uyumluluk için). Veri yapıları ve algoritmaların OS'nin temel taşı olduğu vurgulanır; bu nedenle bilgisayar mühendisliği öğrencilerinin bu alanlardaki bilgilerinin kritik olduğu belirtilir. Dersin sonunda yıl içi değerlendirme hakkında bilgi verilir: iki vize (büyük olasılıkla test şeklinde), ödevler, lab çalışmaları ve bir proje olacağı belirtilir. Derslere %80 devam zorunluluğu vardır.

### 🔹 Ders 3: OS Temel Kavramlar: Servisler, Process Kavramı, Scheduling
* **Genel Konular:**
  - Bilgisayar Sistemi Bileşenleri
    - Bir bilgisayar sistemi dört ana bileşenden oluşur: donanım, işletim sistemi, sistem programları, uygulama programları (kullanıcılar).
    - Kullanıcılar yalnızca etten kemikten oluşmaz; artık makine-makine (M2M), uçtan uca (end-to-end), IoT, sensör ağları, dağıtık hesaplama kavramları da kullanıcı kapsamındadır.
    - Yazılımlar yazılımlarla konuşur; altta çalışan bir donanım vardır.
  - İşletim Sisteminin Katmanlı Yapısı
    - En içte donanım (computer hardware), onu çevreleyen işletim sistemi, etrafında sistem ve uygulama programları, en dışta kullanıcılar.
    - Her işlem içinde en az bir thread (akış) vardır; thread oluşturulması için tek bir akış gerekir (kod, data, register, state).
  - İşletim Sisteminin Tanımı (Çoklu Bakış Açısı)
    - Dıştan bakış: kullanıcı kolay kullanım ister; altta kaynakların etkin kullanımı yatar.
    - İçten bakış: bilgisayar sistemini oluşturan kaynakları yöneten yapı. Bu kaynaklar CPU, bellek, G/Ç cihazları, veri depolama alanları, network'tür.
  - İşletim Sisteminin Temel Hizmetleri
    - User Interface (UI): Batch modu, Command Line Interface (Shell/Kabuk), Grafik User Interface (GUI), Touch Screen arayüzler.
    - Program Execution: Programın belleğe yüklenmesi, veri yapılarının oluşturulması, instruction'ların çalıştırılması, hata/sonlanma durumunun yönetimi.
    - I/O Operations: Dosya okuma/yazma, network üzerinden bilgi aktarımı, kullanıcı ile etkileşim.
    - File System Manipulation: Dosya/dizin oluşturma, okuma, yazma, silme, arama, listeleme.
    - Communications: Aynı sistemdeki prosesler arası (paylaşımlı bellek, mesajlaşma) veya farklı sistemler arası (ağ üzerinden) iletişim.
    - Error Detection: Donanım/yazılım hatalarının tespiti, debug imkânı.
    - Resource Allocation: CPU, bellek, dosya sistemi, G/Ç cihazları gibi kaynakların prosesler arasında adil dağıtımı.
    - Accounting: Hangi kullanıcının/programın ne kadar CPU, bellek, disk, network kullandığının kaydı (muhasebe/monitoring).
    - Protection and Security: Kullanıcıların birbirinin kaynaklarına izinsiz erişiminin engellenmesi, sistemin dış tehditlere karşı korunması.
  - Kernel (Çekirdek) Kavramı
    - Kernel, donanımı çevreleyen ve onu yöneten temel program parçasıdır.
    - İşletim sistemi sadece kernel'dan ibaret değildir; kernel + sistem uygulamaları + diğer bileşenlerden oluşur.
    - Kernel yüklenir ve aktif olduğu sürece, donanım çalıştığı sürece kernel aktiftir.
* **Hocanın Vurgusu:**
  - Proses = "Programın Canlı Çalışan Hali"
    - Hoca özellikle vurgular: "Program pasif bir yapıdır, işlem ise aktif bir yapı, çalışan bir yapı." Bu ayrım dersin geri kalanında sürekli kullanılacaktır.
  - Process State (İşlem Durumu) Kavramı
    - New, Ready, Running, Waiting, Terminated. Hoca özellikle "Terminated" durumunu vurgular: Proses sonlanmadan hemen sistemden çıkmaz; parent process exit kodunu okuyabilmelidir.
  - Process Control Block (PCB) İçeriği
    - Process state, program counter, CPU register'ları, scheduling bilgisi, memory management bilgisi, accounting bilgisi, I/O durumu. Hoca bu yapının OS'nin her proses için tuttuğu "sicil" gibi olduğunu vurgular.
  - Scheduling ve Context Switch
    - Process'ler arasında geçiş yapılmasının (context switch) sebebi CPU utilization'ı artırmaktır. Her context switch sırasında PCB güncellenir (program counter, register değerleri vb.). Bu süre "context switch time" olarak adlandırılır ve mümkün olduğunca düşük olmalıdır.
  - İşletim Sisteminin Kaynak Yöneticisi Rolü
    - Hoca, "CPU ve bellek en temel iki kaynaktır" der. Bu iki kaynağın yönetimi her işletim sistemi kitabının temel konularındandır. İşletim sistemi CPU ve belleği yönetir; diğer kaynaklar da bu çerçevede ele alınır.
  - Queue (Kuyruk) Yapıları
    - OS'de kuyruk yapıları çok önemlidir. Ready queue, I/O device kuyrukları (her cihaz için ayrı) liste (linked list) şeklinde tutulur. Linux'ta task_struct yapısı süreçler arası bağlantıyı sağlar.
* **Detaylı Açıklamalar:** Ders 3, işletim sisteminin temel kavramlarını ve sağladığı servisleri ele alır. Bilgisayar sisteminin dört katmanlı yapısı (donanım, OS, sistem programları, uygulamalar) tanıtılır. Modern sistemlerde "kullanıcı" kavramının yalnızca son kullanıcı değil, aynı zamanda makineler, sensörler, IoT cihazları ve diğer yazılımlar olduğu vurgulanır. İşletim sisteminin ne olduğu, katmanlı yapıda nasıl konumlandığı detaylı şekilde anlatılır. En içte donanım, onu sarmalayan işletim sistemi (kernel), dışta sistem ve uygulama programları, en dışta kullanıcılar bulunur. Her process'in içinde en az bir thread (akış) vardır. Bir process çalışmaya başladığında bile tek bir thread ile başlayabilir; bu thread daha sonra yeni thread'ler oluşturabilir. İşletim sisteminin sağladığı temel hizmetler dokuz başlıkta ele alınır: (1) User Interface (komut satırı, GUI, dokunmatik), (2) Program Execution (yükleme, çalıştırma, hata yönetimi), (3) I/O Operations (dosya, ağ, kullanıcı etkileşimi), (4) File System (CRUD operasyonları), (5) Communications (süreçler arası iletişim), (6) Error Detection (hata tespiti, debug), (7) Resource Allocation (kaynak tahsisi), (8) Accounting (kullanım takibi), (9) Protection & Security (güvenlik). Process kavramı derinlemesine anlatılır. Process, programın çalışan halidir; diskte duran program pasif, çalışan process aktif yapıdır. Her process'in bir Process Control Block'ı (PCB) vardır; bu yapıda process'in tüm durumu tutulur. Linux'ta bu yapıya "task_struct" adı verilir. Process state'leri (New, Ready, Running, Waiting, Terminated) detaylı şekilde açıklanır. Scheduling kavramı ele alınır: CPU'yı hangi process'in ne zaman kullanacağına karar veren mekanizmadır. Process'ler arası geçişte context switch yapılır; bu sırada register değerleri, program counter saklanır/geri yüklenir. Context switch süresi mümkün olduğunca düşük olmalıdır. İşletim sistemi bu amaçla ready queue, I/O device kuyrukları gibi kuyruk yapılarını yönetir. Linux'ta bu kuyruklar linked list ile implemente edilir. Hocanın vurguladığı önemli bir nokta: Process ve thread kavramları sıklıkla karıştırılır. Process = programın çalışan hali; thread = process içindeki bağımsız akış. Bir process birden fazla thread barındırabilir; her thread aynı process'in kaynaklarını paylaşır.

### 🔹 Ders 4: OS Yapıları: Sistem Çağrıları, API, Kernel Mimarileri
* **Genel Konular:**
  - İşletim Sistemlerinin Yapıları
    - Bu ders "yapı" kavramını geniş anlamda ele alır: donanım yapıları, veri yapıları ve kavramlar.
    - İşletim sisteminin tarihsel gelişimi boyunca benimsenen mimariler ve yapılar (monolithic, microkernel, hybrid, modular).
  - İşletim Sisteminin Sağladığı Servisler (Hatırlatma)
    - User Interface, Program Execution, I/O Operations, File System Manipulation, Communications, Error Detection, Resource Allocation, Accounting, Protection and Security.
  - Kullanıcı ile İşletim Sistemi Arasındaki Arayüz
    - Command Line Interface (Shell/Kabuk): klavyeyle komut satırı üzerinden etkileşim. Unix ve türevlerinde Shell olarak adlandırılır. Script dili olarak da kullanılır (if, for, while yapıları, dallanmalar).
    - Grafik User Interface (GUI): İlk olarak Xerox firması tarafından geliştirilmiş; Steve Jobs Xerox'u ziyaret ederek bu konsepti Apple'a taşımış. MIT'de aynı dönemde X-Windows sistemi geliştirilmiş.
    - Touch Screen Interface: Dokunmatik ekran; mouse yerine parmak hareketleri (gesture) kullanılır.
  - Sistem Çağrıları (System Calls)
    - İşletim sisteminin hizmet sunduğu en temel arayüz. Sistem çağrıları, donanım ile uygulama arasındaki sınırı belirler.
    - User mode (sistem çağrısının üstü) ve kernel mode (sistem çağrısının altı) ayrımı vardır.
    - Sistem çağrıları C ve C++ ile yazılır; iki parçadan oluşur: çağrının kendisi (eylem) ve kütüphanedeki fonksiyon/metod (çağrılabilmesini sağlayan).
  - Standart API'ler
    - Win32 API (Windows), POSIX API (Unix/Linux/macOS), Java API (JVM üzerinden).
    - POSIX = Portable Operating System Interface; bir standarttır.
  - Sistem Çağrılarının Çalışma Mekanizması
    - Uygulama bir kütüphane fonksiyonu çağırır (örn. printf → write sistem çağrısı). Kütüphane parametreleri alır, sistem çağrısı formatına dönüştürür.
    - Software interrupt (syscall, int instruction) oluşturulur; kontrol işletim sistemine geçer. İşletim sistemi işlemi yapar, iret ile kütüphaneye döner, kütüphane normal return ile uygulamaya döner.
    - Kernel güncellenirse libc/libc++ da güncellenmelidir (aradaki geçişi sağlarlar).
  - Sistem Çağrılarının Tipleri (Kategorileri)
    - Process Control: end, abort, load, execute, create/terminate process, wait, signal, allocate/free memory.
    - File Management: create, delete, open, close, read, write, reposition, get/set attributes.
    - Device Management: request, release, read, write, attach, detach.
    - Information Maintenance: get/set time/date, get/set system data, get/set process attributes.
    - Communications: create/delete communication connection, send/receive messages, transfer status.
  - Sistem Çağrılarına Parametre Aktarım Yöntemleri
    - En basit: register'lar üzerinden. Sınır: register sayısı.
    - Daha iyi: parametreler bellekte bir bloğa konur, bloğun adresi register'da geçirilir.
    - En esnek (kernel seçimli): OS uygun gördüğü yöntemi kullanır.
  - İşletim Sistemi Yapıları
    - Basit Yapı (MS-DOS): kernel ve sistem programları sınırları belirsiz, monolithic.
    - Daha İyi Yapı (UNIX): kernel modülleri (file subsystem, process control, memory management vb.), ancak yine sınırlar belirsiz.
    - Layered Approach: Her katman sadece altındaki katmanın fonksiyonlarını kullanır. Avantaj: yapı ve hata ayıklama kolaylığı. Dezavantaj: katmanların tanımlanması zor, verim düşer.
    - Microkernel: Kernel minimumda tutulur; sadece temel hizmetler (process management, memory management, iletişim). Diğer servisler (file system, device driver) user mode'da çalışır. Avantaj: genişletilebilirlik, güvenlik, taşınabilirlik. Dezavantaj: user-kernel geçişlerinden performans kaybı.
    - Modular Approach: Modern işletim sistemleri (Solaris, Linux, macOS) çekirdeğin modüller halinde yüklenmesine izin verir. Microkernel ile monolitik arasında orta yol.
* **Hocanın Vurgusu:**
  - Sistem Çağrılarının Önemi
    - Hoca özellikle vurgular: "Sistem çağrılarını aklınızın bir köşesinde tutun." Bütün programlar işletim sisteminden hizmet alırken bu arayüzden geçmek zorundadır. Modern OS'lerde başka yol yoktur.
  - System Call ile API Ayrımı
    - API (kütüphane fonksiyonu) ile sistem çağrısı (kernel'daki implementasyon) farklı kavramlardır. Uygulama geliştirici API ile etkileşir; asıl işi kernel yapar. printf → write sistem çağrısına dönüşür.
  - Unlink ve Process İlişkisi
    - Hoca vurgular: Bir process (örn. Excel) bittiğinde sistemden tamamen çıkmaz; çünkü kendisini oluşturan parent process (Explorer.exe) hâlâ çalışıyordur. Bu yüzden sistemde "ölü" process'ler kısa süreyle bulunabilir; bu durum normaldir.
  - Protection ve Security Ayrımı
    - Hoca, protection ile security'nin farklı kavramlar olduğunu vurgular: Protection = koruma (process'in kendi sınırları içinde kalmasını sağlama); Security = dış tehditlere karşı koruma (kullanıcı kimlik doğrulama, yetkilendirme, bütünlük).
    - Protection işletim sisteminin temel görevidir; security daha çok bilişim güvenliği dersinin konusudur.
  - Tüm Programlar Neden "Ödev" Olarak Değerlendirilir
    - Hoca, işletim sistemi dersinin ödevlerini özellikle vurgular: "Milyon tane zilyon tane soru sorulan bir ders"tir. Kopyala-yapıştır yapılamaz; kaynak araştırması, başkalarının kodlarına bakma teşvik edilir, ancak körü körüne kopyalama cezalandırılır (MOSS gibi benzerlik tespit araçları).
* **Detaylı Açıklamalar:** Ders 4, işletim sistemi yapılarını, sistem çağrılarını ve OS bileşenlerini detaylı şekilde ele alır. "Yapı" kavramı geniş anlamda ele alınır: donanım yapıları, veri yapıları, kavramlar. Geçen haftalardan hatırlatma yapılarak başlanır: OS servisleri, process kavramı, donanım-yazılım ilişkisi. Kullanıcı arayüzleri (UI) detaylı şekilde anlatılır. Command Line Interface (Shell), 1960-70'lerde kullanıcıların bilgisayarla etkileşimini sağlayan temel yöntemdi. Shell bir programlama dili olarak da kullanılabilir (if/else, for, while, değişkenler, fonksiyonlar). GUI'nin tarihi Xerox firması ile başlar; SteveJobs'un Xerox'u ziyareti ve MIT'de geliştirilen X-Windows sistemi anlatılır. Modern dokunmatik arayüzler (gesture) ise mouse yerine parmak hareketlerine dayanır. Sistem çağrıları (System Calls) dersin ana konusudur. Sistem çağrıları, uygulama programlarının işletim sistemi hizmetlerine eriştiği arayüzdür. Modern OS'lerde user mode (sınırlı yetki) ve kernel mode (tam yetki) ayrımı vardır. Sistem çağrıları bu iki mod arasındaki geçişi sağlar. Sistem çağrıları genellikle C/C++ ile yazılır ve iki parçadan oluşur: çağrının kendisi (kernel'da) ve kütüphanedeki fonksiyon (çağrılabilmesi için). Sistem çağrılarının çalışma mekanizması detaylı şekilde anlatılır: Uygulama bir API fonksiyonu (örn. printf) çağırır. Kütüphane fonksiyonu parametreleri alır, sistem çağrısı formatına dönüştürür, software interrupt (syscall/int instruction) oluşturur. İşletim sistemi bu interrupt'ı yakalar, gerekli işlemi yapar, sonucu döndürür. Kütüphane normal return ile uygulamaya döner. Bu nedenle kernel güncellendiğinde libc/libc++ da güncellenmelidir; aradaki bağlantıyı bunlar sağlar. Sistem çağrıları beş ana kategoride sınıflandırılır: Process Control (fork, exec, wait, exit, kill, signal), File Management (open, close, read, write, lseek, stat), Device Management (ioctl, read, write), Information Maintenance (getpid, gettimeofday, setrlimit), Communications (pipe, socket, send, recv, bind, listen, accept). İşletim sistemi yapıları (OS Structures) bölümünde farklı yaklaşımlar karşılaştırılır: Monolithic (MS-DOS, klasik UNIX), Layered (her katman sadece altındakini kullanır), Microkernel (sadece temel hizmetler kernel'da, diğerleri user mode'da) ve Modular (modern yaklaşım, yüklenebilir modüller). Her yapının avantaj ve dezavantajları tartışılır. Microkernel'in genişletilebilirlik, güvenlik ve taşınabilirlik açısından avantajlı olduğu, ancak user-kernel geçişlerinin performans kaybına yol açtığı vurgulanır. Hoca, OS hizmetlerinin nasıl sunulduğunu şekilsel olarak gösterir: Hardware → Operating System (services) → System Calls (arayüz) → Kullanıcı. Bu yapı modern tüm OS'lerde aynıdır.

### 🔹 Ders 5: Process Yönetimi: PCB, State, Context Switch
* **Genel Konular:**
  - Process (İşlem) Kavramı
    - Process = programın çalışan hali. Diskte duran program pasif, çalışmaya başladığında process oluşur.
    - Bir program birden fazla process oluşturabilir (tersi mümkün değil).
    - Process'in çalışabilmesi için: programın belleğe yüklenmesi, çalışma anında eriştiği kaynaklar, çalıştıracağı bir sonraki komutun yeri, ürettiği veri vb. bilgilerin tutulması gerekir.
    - Tarihsel olarak: task, job, process terimleri birbirinin yerine kullanılmıştır (interchangeable).
  - Process'in Bileşenleri
    - Text section: Programın kodu (instruction'lar).
    - Program Counter: Hangi instruction'da olduğumuz.
    - Stack: Fonksiyon çağrı/return, lokal değişkenler, interrupt'tan dönüş adresleri.
    - Data section: Global değişkenler.
    - Heap: Dinamik bellek tahsisi (malloc/new ile).
  - Process Memory Organizasyonu
    - Her process'e tüm bellek kendisine aitmiş gibi gösterilir (sanal bellek).
    - Text (kod), data (global değişkenler), stack (yukarı doğru büyür), heap (aşağı doğru büyür) birbirine doğru genişler.
  - Process State (İşlem Durumu)
    - New: Process oluşturuluyor.
    - Ready: CPU atanmasını bekliyor.
    - Running: İşlemci tarafından çalıştırılıyor.
    - Waiting: Bir olayın gerçekleşmesini bekliyor (I/O tamamlanması, event vb.).
    - Terminated: İşini bitirdi, sonlanıyor.
    - "Terminated" durumu önemli: Process hemen sistemden çıkmaz, parent process exit kodunu okuyabilmelidir.
  - Process Control Block (PCB)
    - İşletim sisteminin her process için tuttuğu veri yapısı ("process'in sicili").
    - İçeriği: Process state, Program Counter, CPU register'ları, Scheduling bilgisi, Memory management bilgisi, Accounting bilgisi, I/O durumu, Açık dosyaların listesi.
    - Linux'ta bu yapıya "task_struct" adı verilir.
  - Scheduling ve Context Switch
    - Scheduling: Ready queue'dan bir process'in seçilip CPU'ya atanması.
    - Context Switch: Bir process'in CPU'dan alınıp diğerinin verilmesi. PCB güncellenir (register'lar, program counter saklanır/geri yüklenir).
    - Context switch sırasında arada boşluk (idle) oluşur; bu süre az olmalıdır.
    - Context switch'i hızlandırmak için bazı işlemcilerde birden fazla register seti bulunur (ör. Sun işlemcilerinde 32 register seti). Pointer değiştirilerek hızlıca geçiş yapılabilir.
  - Kuyruk Yapıları
    - Ready queue: CPU atanmasını bekleyen process'ler.
    - I/O device queues: Her cihaz için ayrı kuyruk.
    - Parent-child ilişkisi: Process'ler ağaç yapısında organize edilir.
    - Listeler genellikle linked list olarak implemente edilir.
* **Hocanın Vurgusu:**
  - Process'in Yaşam Döngüsünde Terminate Durumu
    - Hoca özellikle vurgular: "Niye öyle bir state var diye düşünebilirsiniz." Process işini bitirdiğinde hemen silinmez; çünkü parent process'in exit kodunu okuması gerekir. Eğer terminate state olmasaydı, child'ın sonucu okunamadan kaybolurdu.
  - Program vs Process Ayrımı
    - Hoca "Program pasif, işlem aktif" vurgusunu yapar. Nesne yönelimli programlamadan örnek verir: Sınıfınız (class) = program; oluşturduğunuz objeler = process'ler.
  - Context Switch Performansı
    - Hoca, context switch zamanının mümkün olduğunca düşük olması gerektiğini vurgular. Sürekli 0-1 arasında geçiş yapılırsa, gerçek işler için zaman kalmaz. Birden fazla register seti gibi donanımsal çözümler olsa da sınırsız değildir.
  - Stack ve Register Yapısı
    - Hoca, register'ların "anlık erişilen fiziksel register'lar" olduğunu, ancak bir process durdurulup başka process'e geçileceği zaman bu değerlerin kenara saklanması gerektiğini vurgular. Bu saklama alanı aslında PCB içindeki register alanıdır.
* **Detaylı Açıklamalar:** Ders 5, process (işlem) kavramını derinlemesine ele alır. Bu ders, geçen haftalarda "program" kavramından "process" kavramına geçişi somutlaştırır. Process = programın çalışan hali; diskte duran program pasif, çalışmaya başladığında aktif hale geçer. Process'in yapısal bileşenleri detaylı şekilde açıklanır: Text section (programın kodu, normalde değişmez), Program Counter (hangi instruction'dayız), Stack (fonksiyon çağrı/return adresleri, lokal değişkenler, interrupt'tan dönüş), Data section (global değişkenler), Heap (dinamik bellek tahsisi). Stack yukarı doğru büyür, heap aşağı doğru büyür; birbirlerine doğru genişler. Process state'leri (yeni, hazır, çalışıyor, bekliyor, sonlanmış) detaylı şekilde anlatılır. State'ler arası geçişler, scheduler'ın hangi durumda devreye girdiği, I/O işlemi başlatan process'in waiting state'e geçmesi gibi detaylar tartışılır. "Terminate" durumunun neden var olduğu özellikle açıklanır: Parent process, child'ın çıkış kodunu (exit code) okuyabilmelidir. Bu olmadan çocuk process'in ürettiği sonuç kaybolur. Process Control Block (PCB), OS'nin her process için tuttuğu veri yapısıdır. İçinde process'in tüm durum bilgisi (program counter, register değerleri, açık dosyalar, scheduling bilgisi, accounting bilgisi vb.) yer alır. Linux'ta bu yapı "task_struct" adını alır ve süreçler arası bağlantıyı (parent-child) linked list şeklinde tutar. Default olarak her process'in 3 file descriptor'ı vardır: 0 (stdin), 1 (stdout), 2 (stderr). Scheduling ve Context Switch kavramları detaylı anlatılır. Scheduling, ready queue'dan uygun process'i seçip CPU'ya atama işlemidir. Context switch ise bir process'in CPU'dan alınıp diğerine geçilmesi sürecidir. Bu sırada register değerleri, program counter saklanır ve yeni process için yüklenir. Context switch süresi verimliliği doğrudan etkiler; çok sık context switch yapılması "thrashing" etkisi yaratır. Çözüm olarak bazı işlemciler birden fazla register seti içerir (Sun işlemcilerinde 32 set), pointer değiştirilerek hızlı geçiş sağlanır. Hoca, process'ler arası parent-child ilişkisini ağaç yapısı şeklinde açıklar. İlk process (init/systemd) kök process'tir; tüm diğer process'ler bu yapıdan türetilir. Bu ilişki sayesinde çocuk process'ler sonlandığında parent'a haber verilir. Kuyruk yapıları OS'nin temel veri yapılarından biridir. Ready queue, I/O device queues (her cihaz için ayrı) linked list olarak implemente edilir. Process'ler kuyruklara eklenir, uygun koşul sağlandığında kuyruktan çıkarılır. Multi-core sistemlerde her core için ayrı ready queue olabilir; bu durum senkronizasyon problemlerini beraberinde getirir.

### 🔹 Ders 6: CPU Scheduling: Kriterler, Algoritmalar, Dispatcher
* **Genel Konular:**
  - CPU Scheduling'e Giriş
    - Her sistemde scheduling vardır. Scheduling kriterleri, sistem türüne (batch, interactive, real-time) göre değişir.
    - Bu ders genel kavramlar, kriterler ve algoritmalar üzerinde durur. Sonraki derslerde thread scheduling, multi-processor scheduling ve işletim sistemi örnekleri işlenir.
  - CPU ve I/O Burst (Patlama) Kavramı
    - Process'in çalışması CPU burst ve I/O burst'lerden oluşur. Her iki tür zamanla birbirini takip eder.
    - CPU-bound process: Daha fazla CPU burst (uzun hesaplama).
    - I/O-bound process: Daha fazla I/O burst (bekleme, giriş/çıkış).
    - Gerçek hayatta çoğu CPU burst kısa süreli olur; uzun CPU burst'ler sayıca azdır.
  - Scheduling Türleri
    - Long-term scheduler: Hangi programlar memory'ye alınacak (admission).
    - Short-term scheduler: Ready queue'dan hangi process CPU'ya alınacak. Çok hızlı olmalı.
    - Medium-term scheduler: Swap out/in ile process'leri memory'ye alıp çıkartır.
  - Scheduling Anları (Ne Zaman Devreye Girer)
    - 1) Process running'den waiting'e geçerse (I/O başlatma, wait).
    - 2) Process running'den terminate'a geçerse.
    - 3) Process running'den ready'e geçerse (interrupt, time quantum).
    - 4) Process waiting'den ready'e geçerse (I/O tamamlandı).
    - 1 ve 2 → Non-preemptive.
    - 3 ve 4 → Preemptive.
  - Scheduling Kriterleri
    - CPU utilization: İşlemci ne kadar meşgul. Çok yüksek olmamalı (%100 = acil durum, müdahale alanı kalmaz).
    - Throughput: Birim zamanda tamamlanan iş sayısı.
    - Turnaround time: Process'in sisteme girmesinden tamamlanmasına kadar geçen süre.
    - Waiting time: Ready queue'da geçen toplam süre.
    - Response time: İlk sonuç üretme zamanı.
    - Batch sistemlerde throughput; interaktif sistemlerde response time önemlidir.
  - Scheduling Algoritmaları
    - **FCFS (First Come First Served)**: İlk gelen ilk servis alır. Non-preemptive. Basit ama convoy effect oluşabilir (uzun process arkaya kuyruk olur, tıpkı düğün konvoyu).
    - **SJF (Shortest Job First)**: En kısa burst time'a sahip process önce çalışır. Non-preemptive versiyonu optimaldir (minimum average waiting time) ama burst time'ı bilmek gerekir.
    - **SRTF (Shortest Remaining Time First)**: SJF'nin preemptive versiyonu. Kalan en kısa süreli process seçilir.
    - **Priority Scheduling**: Her process'e bir öncelik değeri atanır. Düşük değer = yüksek öncelik (veya tersi). Starvation (açlık) problemi olabilir; çözüm: aging (öncelik yaşla büyür).
    - **Round Robin (RR)**: Her process'e eşit zaman quantum (time slice) verilir (tipik 10-100 ms). Preemptive. Ready queue circular (FIFO) olarak gezilir. Quantum çok küçükse context switch fazla, çok büyükse FCFS'ye yaklaşır.
    - **Multilevel Queue**: Ready queue birden fazla alt kuyruğa bölünür (foreground/interactive, background/batch). Her kuyruğun kendi scheduling algoritması olabilir. Process'ler kuyruklar arası taşınmaz.
    - **Multilevel Feedback Queue**: Process'ler davranışına göre kuyruklar arası taşınabilir. CPU-bound process aşağı, I/O-bound yukarı. En genel algoritma.
* **Hocanın Vurgusu:**
  - Dispatch Latency Kavramı
    - Hoca özellikle vurgular: Dispatcher'ın seçtiği process'i mümkün olan en kısa sürede CPU'da çalıştırmaya başlatması gerekir. Context switch, user mode'a geçiş, uygun yere atlama için harcanan süre "dispatch latency"dir. Bu süre az olmalıdır.
  - CPU Utilization'ın %100 Olmaması Gerektiği
    - Hoca, "%100 CPU kullanımı tercih edilir" denilmesine rağmen, %100 olmaması gerektiğini vurgular. Çünkü bir pay bırakılmalı; acil durum, güncelleme, yeni iş gelmesi gibi durumlar için alan lazım. Otomobil örneği: 220 yapabilen araçta sürekli 220 ile gitmek, acil durumda hızlanma şansı bırakmaz.
  - Convoy Effect (Konvoy Etkisi)
    - Hoca, FCFS'nin uzun process'in arkasında kısa process'ler yığılması durumunu "konvoy" örneğiyle açıklar: Düğün alayında arabaların sağdan soldan geçememesi gibi, kısa işler de uzun işin bitmesini bekler.
  - Tıkanıklık ve Performans
    - Çok fazla context switch sistemi yavaşlatır; optimum bir nokta vardır. Quantum çok küçükse overhead fazla, çok büyükse cevap süresi artar.
  - Preemption Getirdiği Problemler
    - Hoca vurgular: Preemption iyi bir şey ama paylaşılan veriye erişim sırasında problem yaratır. Bir process veri üzerinde değişiklik yaparken preemptive olarak kesilirse, başka process aynı veriye erişip tutarsızlık yaratabilir. Senkronizasyon gerekir.
* **Detaylı Açıklamalar:** Ders 6, CPU scheduling kavramını derinlemesine ele alır. Scheduling, OS'nin en temel görevlerinden biridir; kaynakların etkin paylaşımını sağlar. Ders, kavramlar, kriterler ve klasik algoritmalar üzerinde yoğunlaşır. Process'lerin yaşam döngüsü boyunca CPU ve I/O burst'leri sırayla gerçekleşir. CPU-bound process daha çok hesaplama yapar, I/O-bound process daha çok bekler. Bu özellik scheduling kararlarını etkiler. Short-term scheduler, ready queue'dan hangi process'in CPU'ya alınacağına karar verir. Hızlı olmalıdır (milisaniyeler mertebesinde). Scheduling kararları 4 farklı anda verilir: (1) Running → Waiting (non-preemptive), (2) Running → Terminated (non-preemptive), (3) Running → Ready (preemptive), (4) Waiting → Ready (preemptive). Scheduling kriterleri sistem türüne göre farklı ağırlıklandırılır. Batch sistemlerde throughput, interaktif sistemlerde response time, gerçek zamanlı sistemlerde deadline'a uyum önemlidir. FCFS (First Come First Served) en basit algoritmadır; non-preemptive'tir. Dezavantajı convoy effect: uzun bir process CPU'da iken kısa process'ler kuyrukta bekler. Ortalama waiting time optimal değildir. SJF (Shortest Job First) her seferinde en kısa burst time'a sahip process'i seçer. Non-preemptive versiyonu minimum ortalama waiting time verir (optimal). Dezavantajı: burst time'ın önceden bilinmesi gerekir, uzun process'ler starvation'a uğrayabilir. SRTF (Shortest Remaining Time First) SJF'nin preemptive versiyonudur. Yeni process geldiğinde, kalan süresi mevcut process'in kalan süresinden az ise preempt yapılır. Priority Scheduling'de her process'e bir öncelik değeri atanır. Düşük değer yüksek öncelik anlamına gelir (Unix'te olduğu gibi). Dezavantajı starvation: düşük öncelikli process'ler uzun süre bekleyebilir. Çözüm: aging (process yaşlandıkça önceliği artar). Round Robin her process'e eşit zaman quantum (time slice) verir. Quantum sonunda process preempt yapılır, ready queue'nun sonuna eklenir. Quantum çok küçükse context switch overhead fazla, çok büyükse cevap süresi artar. Tipik değer 10-100 ms arasındadır. RR, time-sharing sistemler için idealdir. Multilevel Queue, process'leri öncelik kategorilerine göre farklı kuyruklara ayırır (ör. system, interactive, batch). Her kuyruğun kendi scheduling algoritması olabilir. Process'ler kuyruklar arası taşınmaz. Multilevel Feedback Queue, en genel algoritmadır. Process'ler CPU-bound ise alt kuyruğa, I/O-bound ise üst kuyruğa taşınır. Bu sayede I/O-bound process'ler hızlı cevap alır, CPU-bound process'ler arka planda çalışır. Convoy effect (FCFS) ve starvation (priority scheduling) algoritmaların tipik problemleridir. Aging ve uygun quantum seçimi bunlara karşı geliştirilen tekniklerdir.

### 🔹 Ders 6 Lab: Shell Temelleri: Komutlar, İzinler, Script Yazımı
* **Genel Konular:**
  - Shell Nedir?
    - Shell, kernel (çekirdek) üzerinde çalışan, işletim sistemi servislerine erişilebilen bir program parçasıdır. Kernel komutlarını ve daha fazlasını yapmayı sağlayan programlama dili/kabuk olarak da tanımlanabilir.
    - Farklı shell çeşitleri vardır: Bourne Shell (sh), C Shell, Korn Shell, Bash (Bourne Again Shell), Windows'ta PowerShell.
  - Temel Dosya ve Dizin İşlemleri
    - `mkdir`: Yeni dizin oluşturur.
    - `cd`: Dizin değiştirir.
    - `ls`: Dosya ve dizinleri listeler.
    - `rmdir`: Boş dizini siler (dolu dizini silemez).
    - `touch`: Boş bir text dosyası oluşturur.
    - `rm`: Dosya siler.
    - `mv`: Dosya taşıma/yeniden adlandırma.
    - `cat`: Dosya içeriğini terminale yazdırır.
    - `nano`: Terminal tabanlı metin editörü.
    - `man`: Komut için kılavuz (manual) sayfası açar.
  - Dosya İzinleri (Permissions)
    - `chmod`: Dosya izinlerini değiştirir.
    - Üç aktör vardır: Dosya sahibi (owner/user), grup (group), diğerleri (others).
    - Üç izin türü: Read (r=4), Write (w=2), Execute (x=1).
    - Örnek: `chmod 777 dosya` → tüm kullanıcılar için tüm izinler.
    - Örnek: `chmod 644 dosya` → sahip rw, grup r, diğerleri r.
    - Dosya tipi: `-` (dosya), `d` (dizin), `l` (sembolik link).
    - SUID bit ile dosya sahibinin yetkileriyle çalıştırma.
    - SGID bit ile grup yetkileriyle çalıştırma.
    - Sticky bit ile sadece sahibi veya root dosyayı silebilir (`/tmp` gibi).
  - Pipe ve Yönlendirme
    - `|` (pipe): Bir komutun çıktısını diğerine girdi olarak verir. `ls | grep .txt`
    - `>` (yönlendirme): Çıktıyı dosyaya yazar (üzerine yazar).
    - `>>`: Çıktıyı dosyaya ekler.
    - `<`: Dosyayı komuta girdi olarak verir.
  - Kullanıcı ve Grup İşlemleri
    - `sudo useradd`: Yeni kullanıcı oluşturur.
    - `sudo userdel -r`: Kullanıcıyı ev diziniyle birlikte siler.
    - `sudo usermod`: Kullanıcı özelliklerini değiştirir (yetki, grup).
    - `sudo groupadd/groupdel`: Grup oluşturur/siler.
  - Shell Script Temelleri
    - `#!/bin/bash`: Shebang satırı, script'in bash ile çalıştırılacağını belirtir.
    - Değişken atama: `degisken=deger` (boşluk olmadan).
    - Erişim: `$degisken` veya `${degisken}`.
    - Özel değişkenler: `$1`, `$2`, ... komut satırı argümanları; `$#` argüman sayısı; `$@` tüm argümanlar; `$?` son komutun çıkış kodu.
    - Koşul ifadeleri: `if [ koşul ]; then ... fi`
    - Karşılaştırma operatörleri: `-eq`, `-ne`, `-gt`, `-lt`, `-ge`, `-le`, `-f` (dosya), `-d` (dizin), `-r` (okunabilir), `-w` (yazılabilir), `-x` (çalıştırılabilir).
    - Döngüler: `for`, `while`, `until`.
    - Backtick (`): Komut çıktısını değişkene atar.
  - `echo` Komutu
    - Terminale yazı yazdırır. `echo "Merhaba Dünya"`
    - Çift ve tek tırnak farkı: Çift tırnakta değişkenler yorumlanır, tek tırnakta düz metin olarak alınır.
* **Hocanın Vurgusu:**
  - `rm -rf` Komutunun Tehlikesi
    - Hoca özellikle uyarır: `rm -rf /` komutu root dizininde çalıştırılırsa sistemdeki her şeyi siler. "Mesela şu an rm -rf'yi alsam her şeyim gidecek. Bütün ekran da kapanacak. O yüzden çok tehlikeli bir komut. Kullanırken dikkat edin."
  - `chmod` ile İzin Verme
    - "Permission denied" hatası alındığında çözüm `chmod`'dur. Dosya sahibi bile olsa, okuma/yazma hakkı yoksa erişemez.
  - `~` (Tilde) İşareti
    - Home dizinini temsil eder. Tilde tuşu (Alt+ı, Türkçe klavyede) ile yazılır. Kullanıcının home dizinine hızlıca gitmek için kullanılır.
  - Türkçe Karakter Sorunu
    - Hoca vurgular: Sunumdaki tırnaklar ile Linux'taki tırnaklar farklıdır. Sunumdan kopyalayıp yapıştırmak hata verebilir. Düz çift tırnak (`"`) yerine eğri çift tırnak kullanmamaya dikkat edin.
  - Shell vs Tarayıcı
    - JS dosyaları tarayıcıda çalışır, shell'de doğrudan çalışmaz. Shell'de tarayıcı açıp JS çalıştırılabilir ama uğraştırır.
  - `touch` Komutu
    - Hoca açıklar: `touch` text dosyası oluşturur (binary değil). Uzantı belirtilmezse uzantısız dosya oluşur, yine de text dosyasıdır.
* **Detaylı Açıklamalar:** Ders 6 Lab, shell programlamaya giriş niteliğindedir. İki haftaya yayılan içeriğin ilk haftasıdır. Lab asistanı, Linux üzerinde (sanal makinede Ubuntu/Kubuntu) shell komutlarını uygulamalı olarak gösterir. Temel dizin ve dosya işlemleri uygulamalı olarak gösterilir. `mkdir sample_dir` ile yeni dizin oluşturulur, `cd sample_dir` ile dizine geçilir, `touch sample.txt` ile boş dosya oluşturulur. `ls -l` ile detaylı liste alınır; dosya izinleri, sahibi, boyutu görülür. `cat dosya` ile içerik okunur, `nano dosya` ile düzenlenir. `cd ..` ile üst dizine çıkılır. `rmdir` ile boş dizin silinir, dolu dizin için `rm -rf` kullanılır (dikkatli!). Dosya izinleri detaylı şekilde anlatılır. Her dosya/dizin için 3 aktör (sahip, grup, diğerleri) × 3 izin (read, write, execute) söz konusudur. `chmod` ile izinler değiştirilir. Sayısal gösterimde: r=4, w=2, x=1, toplamları yazılır. Örneğin `chmod 777` tüm izinler, `chmod 644` ise sahip için rw (6), grup ve diğerleri için r (4) anlamına gelir. `ls -l` çıktısında dosya tipi ilk karakterde görülür: `-` (normal dosya), `d` (dizin), `l` (sembolik link). Kullanıcı yönetimi komutları açıklanır. `sudo useradd kullanici` yeni kullanıcı oluşturur, `sudo passwd kullanici` şifre atar, `sudo userdel -r kullanici` kullanıcıyı ev dizini ile birlikte siler. Her kullanıcının UID'si vardır; root kullanıcının UID'si 0'dır. `/etc/passwd` dosyası kullanıcı bilgilerini, `/etc/shadow` şifre hash'lerini tutar. `usermod -aG grup kullanici` ile kullanıcı gruba eklenir. Pipe ve yönlendirme kavramları açıklanır. `|` operatörü bir komutun çıktısını diğerine girdi olarak bağlar. Örneğin `ls | wc -l` dosya sayısını verir, `cat dosya | grep "arama"` dosyada arama yapar. `>` çıktıyı dosyaya yönlendirir (üzerine yazar), `>>` ekler. `<` dosyayı komuta girdi olarak verir. Shell script'in temelleri ele alınır. `#!/bin/bash` shebang satırı, `echo "mesaj"` ekrana yazar, `degisken="deger"` atama yapar, `$degisken` ile erişilir. `if [ koşul ]; then ... fi` koşul yapısıdır. Koşul ifadelerinde `[ ]` kullanılır. `if [ $# -gt 3 ]` argüman sayısı 3'ten büyük mü kontrol eder. `if [ -f dosya ]` dosya var mı kontrol eder. `if [ -d dizin ]` dizin var mı kontrol eder.

### 🔹 Ders 7: Thread Kavramı: Modeller, Kütüphaneler, Multi-core
* **Genel Konular:**
  - Thread (İş Parçacığı) Kavramı
    - Bir process içinde birden fazla bağımsız akış (thread) oluşturma mekanizmasıdır. Thread, process'in temel bileşenlerinden (kod, data, register, stack) paylaşımlı olup sadece register ve stack ayrıdır.
    - Thread'in temel motivasyonları:
      - CPU utilization artırmak.
      - Uygulamanın farklı parçalarını paralel yürütmek.
      - İnteraktif yapıyı geliştirmek (UI thread + worker thread).
      - Kodu basitleştirmek ve modüler hale getirmek.
  - Thread vs Process
    - Process: Kendi adres alanı vardır. Oluşturma maliyeti yüksek (kod, data, register, stack hepsi kopyalanır).
    - Thread: Aynı process'in adres alanını paylaşır. Sadece register ve stack ayrıdır. Oluşturma maliyeti düşük.
    - Bir process birden fazla thread barındırabilir; tüm thread'ler aynı kod, data ve dosya alanını paylaşır.
  - Thread Modelleri (User vs Kernel Threads)
    - User threads: Uygulama geliştiricinin thread kütüphaneleri (POSIX pthreads, Windows threads, Java threads) ile oluşturduğu thread'ler.
    - Kernel threads: İşletim sistemi tarafından doğrudan desteklenen ve yönetilen thread'ler. Modern OS'ler (Linux, Windows, Solaris, macOS) varsayılan olarak kernel thread kullanır.
    - Üç eşleme modeli:
      - **Many-to-One (N:1)**: Birçok user thread tek bir kernel thread'e eşlenir. Bir user thread blocking call yaparsa tüm kernel thread (ve bağlı tüm user thread'ler) bloke olur. Ekonomik ama esnek değil.
      - **One-to-One (1:1)**: Her user thread için bir kernel thread oluşturulur. Blocking call'lar problem olmaz; ancak kaynak kullanımı fazladır.
      - **Many-to-Many (N:M)**: Birçok user thread, daha az (eşit veya daha fazla olmayan) sayıda kernel thread'e eşlenir. Her iki modelin avantajlarını birleştirir.
      - **Two-level**: Kritik thread'ler 1:1, diğerleri N:M şeklinde.
  - Thread Kütüphaneleri
    - POSIX pthreads: Unix/Linux için thread standardı. Fonksiyonlar: `pthread_create`, `pthread_exit`, `pthread_join`, `pthread_detach`, `pthread_self`, `pthread_equal`.
    - Windows threads: Win32 API ile.
    - Java threads: `Thread` sınıfı veya `Runnable` arayüzü ile; JVM tarafından yönetilir.
  - Thread Avantajları
    - Ekonomi: Process oluşturmaktan daha ucuz; bellek ve kaynak paylaşımı.
    - Modülerlik: Karmaşık uygulamaları parçalara ayırma.
    - Hız: Context switch process'ler arası context switch'ten daha hızlı.
    - İletişim: Aynı process'teki thread'ler doğrudan paylaşımlı bellek üzerinden haberleşir (IPC maliyeti yok).
  - Thread Dezavantajları
    - Senkronizasyon karmaşıklığı: Paylaşımlı kaynaklara erişim senkronize edilmelidir (race condition).
    - Test ve debug zorluğu: Multi-threaded uygulamaları test etmek ve debug etmek tek thread'li uygulamalardan çok daha zordur.
    - Kernel desteği gereksinimi: Modern OS'ler kernel seviyesinde thread desteği sağlar.
  - Multi-core Sistemler ve Threading
    - Multi-core işlemciler, gerçek anlamda paralel çalışma sağlar. Ancak bir uygulamanın multi-core'dan yararlanabilmesi için multi-threaded olması gerekir.
    - Intel çekirdek başına 2 thread (Hyper-Threading); RISC tabanlı işlemcilerde 4-8 thread/core olabilir.
    - ALU (Aritmetik-Logic Unit) birden fazla olursa, aynı anda farklı aritmetik işlemler yapılabilir.
* **Hocanın Vurgusu:**
  - Thread Kütüphanesi Implementasyonu
    - Hoca iki yöntem açıklar: (1) Kütüphane tamamen user seviyesinde (user-mode thread library), (2) Kütüphane kernel seviyesinde (kernel-mode thread library). POSIX standart olarak thread davranış modelini tanımlar; implementasyonu sisteme bırakır.
  - 8 Çekirdek 16 Thread Meselesi
    - Hoca bir soruya cevap verir: "8 çekirdek 16 thread" ifadesindeki thread sayısı, işlemcinin kaç tane fiziksel register seti barındırdığına bağlıdır. Intel her çekirdek için 2 register seti (2 thread) sağlar; RISC tabanlı işlemcilerde 4-8 thread/core olabilir. ALU birden fazlaysa aynı anda farklı aritmetik işlemler yapılabilir.
  - Multi-threaded Server Mimarisi
    - Hoca, web sunucu örneğini verir: Apache varsayılan olarak 5 process × 30 thread = 150 thread ile başlar. Multi-process ana yapıyı, multi-thread istek işlemeyi sağlar. Bir thread'te hata olursa sadece o thread etkilenir, tüm process çökmez.
  - Debug Zorluğu
    - Hoca özellikle vurgular: "printf bile debug için yazdırılsa kimin tarafından yazdırıldığı sorusu ortaya çıkıyor." Multi-threaded uygulamada printf, kernel'ı bloke edebilir, threadler arası sırayı değiştirebilir. Bu yüzden test ve debug oldukça sıkıntılı olabilir.
  - Thread'lerin Çalışma Hakkında Karar
    - Hoca vurgular: Thread'ler CPU-bound (çok hesaplama) ve I/O-bound (çok I/O) olabilir. Bir thread I/O bloğuna girerse diğer thread'ler çalışabilir. Bu yüzden tek core'da bile threading anlamlı olabilir.
* **Detaylı Açıklamalar:** Ders 7, thread (iş parçacığı) kavramını derinlemesine ele alır. Thread, modern işletim sistemlerinin temel yapı taşlarından biridir. Bir process içinde birden fazla bağımsız akış (thread) oluşturma imkânı sağlar. Thread'in temel motivasyonu CPU utilization'ı artırmaktır. Process'ler arası context switch maliyetli olduğundan, bir process içinde birden fazla thread oluşturmak daha ekonomiktir. Bunun dışında: uygulamanın farklı parçalarını paralel yürütmek, interaktif yapıyı geliştirmek (UI thread + arka plan worker thread), kodu modüler hale getirmek. Thread vs Process farkı detaylı şekilde açıklanır. Process = kendi adres alanı olan bağımsız çalışma birimi. Oluşturulması maliyetli (kod, data, register, stack kopyalanır). Thread = process'in adres alanını paylaşan bağımsız akış. Sadece register ve stack ayrıdır. Oluşturulması ucuz, context switch hızlı. Thread modelleri (user vs kernel threads) detaylı şekilde anlatılır. Üç eşleme modeli vardır: Many-to-One (N:1): Çok sayıda user thread tek bir kernel thread'e eşlenir. Thread library user space'tedir. Avantaj: ekonomik (kernel kaynağı az kullanılır). Dezavantaj: Bir user thread blocking call yaptığında tüm kernel thread bloke olur, bağlı tüm user thread'ler etkilenir. One-to-One (1:1): Her user thread için ayrı bir kernel thread oluşturulur. Blocking call problemi yoktur. Avantaj: paralellik yüksek. Dezavantaj: her thread için kernel kaynağı gerekir, oluşturma maliyeti yüksek. Many-to-Many (N:M): Çok sayıda user thread, daha az sayıda kernel thread'e eşlenir. Her iki modelin avantajlarını birleştirir. Bir thread blocking call yaparsa diğerleri devam edebilir. Two-level: Kritik thread'ler için 1:1, normal thread'ler için N:M. Hoca, thread kütüphanelerinin implementasyonunu açıklar: (1) Tamamen user space'te (kullanıcı thread'leri yönetir, kernel haberdar değildir), (2) Tamamen kernel space'te (kernel thread'leri oluşturur ve yönetir), (3) Hibrit yaklaşım. Thread avantajları detaylı sıralanır: Ekonomi (process oluşturmaktan ucuz, kaynak paylaşımı), Modülerlik (karmaşık uygulamaları parçalara ayırma), Hız (context switch process'ler arası context switch'ten hızlı), İletişim (aynı process'teki thread'ler doğrudan paylaşımlı bellek üzerinden haberleşir). Thread dezavantajları da önemlidir: Senkronizasyon karmaşıklığı (paylaşımlı kaynaklara erişim senkronize edilmelidir), Test ve debug zorluğu (multi-threaded uygulamalar tek thread'li uygulamalardan çok daha zor test edilir, çünkü thread'lerin çalışma sırası belirsizdir). Multi-core sistemler ve threading konusu da vurgulanır. Modern işlemcilerde Hyper-Threading teknolojisi ile her fiziksel çekirdek 2 mantıksal thread (iki register seti) barındırır. Bu sayede bir thread I/O veya bellek erişimi için beklerken, diğer thread hesaplama yapabilir. ALU birden fazlaysa (4-8), aynı anda farklı aritmetik işlemler yapılabilir.

### 🔹 Ders 7 Lab: Shell İleri: tr, awk, bc, Döngüler
* **Genel Konular:**
  - tr (Translate) Komutu
    - Metin editörlerindeki replace (değiştirme) işlemlerini komut satırında yapar.
    - Case-sensitive/insensitive dönüşümü, karakter değiştirme, karakter silme gibi işlemler yapabilir.
    - Kullanım: `cat dosya | tr 'a-z' 'A-Z'` (küçük harfleri büyüğe çevirir).
    - `tr ';' ','` (noktalı virgülü virgüle çevirir).
    - `tr -d ';'` (noktalı virgülü siler).
  - awk Komutu
    - CSV gibi yapılandırılmış dosyaları parse etmek için kullanılır.
    - Alanlara göre filtreleme, dönüştürme yapabilir.
    - `awk -F';' '$2 > 3 {print $0}' dosya` (noktalı virgülle ayrılmış, ikinci kolonu 3'ten büyük olan satırları yazdır).
    - `$1` birinci kolon, `$2` ikinci kolon, `$0` tüm satır.
    - `awk -F'delim' 'şart {eylem}' dosya` temel sözdizimi.
  - bc (Basic Calculator) Komutu
    - Komut satırında hesap makinesi olarak çalışır.
    - `bc` yazıp Enter ile hesap makinesi açılır; çıkmak için `quit`.
    - Karşılaştırma operatörleri: `3 > 1` (doğruysa 1, yanlışsa 0 döner).
    - Atama: `x = 5`, `x = x + 1`.
    - Mantıksal operatörler: `&&` (ve), `||` (veya), `!` (değil).
    - `echo "scale=4; 22/7" | bc` pipe ile kullanım.
    - Logaritma, üstel fonksiyonlar için `-l` bayrağı (`bc -l`).
  - Shell Script Argümanları
    - `$1`, `$2`, ..., `$9`: Komut satırı argümanları.
    - `$#`: Argüman sayısı.
    - `$@`: Tüm argümanlar.
    - `$?`: Son komutun çıkış kodu (exit code).
    - `$$`: Shell'in PID'si.
  - if Koşul Yapıları
    - `if [ koşul ]; then ... elif [ koşul ]; then ... else ... fi` temel yapısı.
    - Karşılaştırma operatörleri: `-eq` (eşit), `-ne` (eşit değil), `-gt` (büyük), `-lt` (küçük), `-ge` (büyük eşit), `-le` (küçük eşit).
    - Dosya testleri: `-f` (dosya), `-d` (dizin), `-r` (okunabilir), `-w` (yazılabilir), `-x` (çalıştırılabilir).
    - `if [ -f dosya ]` dosya var mı, `if [ -d dizin ]` dizin var mı.
    - Mantıksal operatörler: `&&` (ve), `||` (veya).
    - Tek satır if: `[ $# -gt 3 ] && echo "..."`
  - Döngüler (Loops)
    - `for` döngüsü:
      - `for i in 1 2 3 4 5; do echo $i; done` (1'den 5'e kadar).
      - `for i in {1..5}; do echo $i; done` (range ile).
      - `for i in {1..10..2}; do echo $i; done` (1, 3, 5, 7, 9 - 2'şer artarak).
      - `for dosya in $(ls); do echo $dosya; done` (ls çıktısı üzerinde).
      - `for dosya in *; do ... done` (mevcut dizindeki tüm dosyalar).
    - `while` döngüsü:
      - `while [ koşul ]; do ... done` (koşul doğru olduğu sürece).
    - `until` döngüsü:
      - `until [ koşul ]; do ... done` (koşul yanlış olduğu sürece).
  - Dosya Tipleri ve İzinler
    - `ls -la`: Detaylı liste.
    - Dosya tipi: `-` (dosya), `d` (dizin), `l` (link), `b` (block), `c` (character), `p` (pipe), `s` (socket).
    - `-F` veya `ls -d` ile dizinleri belirginleştirme.
  - awk ile Veri İşleme
    - `awk -F';' '{print $1, $2}'` belirli kolonları yazdırır.
    - `awk -F';' 'NR==1 {print $1}'` belirli satırdaki veriyi alır.
    - `awk` içinde `printf` ile formatlı çıktı.
    - `awk` ile toplam, ortalama hesaplama.
    - `awk -F';' '{sum += $2} END {print sum}'` toplam hesaplar.
* **Hocanın Vurgusu:**
  - tr Komutunun Kullanım Alanları
    - Hoca vurgular: tr komutu normal editörde yapılan replace işlemlerini (bul-değiştir, büyük-küçük harf dönüşümü, silme) komut satırında yapmayı sağlar. Script içinde otomasyon için çok kullanışlıdır.
  - awk'ın Gücü
    - "awk komutunda farklı parametreler de var. Bu find parametresi. Noktalı bilgilerle delimetr'i ayrıca belirtmemiz gerekiyor. Delimetrimiz noktalı virgül. Daha sonra noktalı virgülden parçaları her bir parçayı bir değişken atıyor." Hoca awk'ın parse yeteneğini vurgular.
  - $# ile Argüman Sayısı Kontrolü
    - "Number of anlamına gelir. Bir şeyin sayısıdır aslında. Polar da koyduğunuz zaman bu aslında programa gönderdiğiniz argümanların sayısı. Parametrelerin sayısı demek." Hoca $# değişkeninin önemini vurgular.
  - if Koşul Yapısının Sözdizimi
    - Hoca açıkça ifade eder: "if'ten sonra bir `den` gelmesi gerekiyor. if condition'ımız, den, gerek komutlarımız, as, gerek komutlarımız ve fi ile bitiyor. Çünkü parantez olmadığı için if'in bitişini fi ile bitiriyoruz."
  - Döngü Sözdizimi Kolaylığı
    - "C'de değişken hatırlamamız gerekiyor, sonra condition geliyor, sonra da artırım ifadesi geliyor. Şu 13. satırda verilen condition gibi. Ama Shell'de çok daha basit bir söz dizimi söz konusu. For e in 1-2-3-4-5 demek 1'den 5'e kadar dönmek, döngü başlatmak demek."
  - JS Shell'de Çalışmaz
    - "JS dosyasını çalıştırmak için bir browser ihtiyacın olacaktır. Çünkü JS dosyaları browser tarafından tanımlanıyor, browser tarafından çalıştırılıyor. Bir browser ihtiyacın olacaktır. Ama Shell ile bir browser açıp o browserdan da JS dosyasını çalıştırabilirsin."
  - -V Bayrağı (Verbose)
    - Hoca açıklar: "Çizgi V var. Writeable, readable demek. Eğer bir dosya okunabilirse çizgi V ile bu şekilde kontrol edebilirsiniz."
* **Detaylı Açıklamalar:** Ders 7 Lab, shell script programlamanın ileri konularını ele alır. Geçen haftaki temel komutlardan sonra, metin işleme, koşul yapıları ve döngüler anlatılır. `tr` (translate) komutu, metin üzerinde karakter bazlı dönüşüm yapar. `tr 'a-z' 'A-Z'` tüm küçük harfleri büyüğe çevirir. `tr ';' ','` noktalı virgülü virgüle değiştirir. `tr -d ';'` noktalı virgülü siler. Pipe ile birlikte kullanıldığında çok güçlüdür: `cat dosya | tr 'a-z' 'A-Z'` dosyadaki tüm küçük harfleri büyüğe çevirir. `awk` komutu, yapılandırılmış metin dosyalarını (özellikle CSV) işlemek için kullanılır. `-F` bayrağı ile alan ayracı belirlenir (`-F';'` noktalı virgül için). `$1` birinci alan, `$2` ikinci alan, `$0` tüm satır anlamına gelir. Koşullu ifadeler: `awk -F';' '$2 > 3 {print $0}'` ikinci alanı 3'ten büyük olan satırları yazdırır. `END {print sum}` blok ile toplam hesaplanır. `bc` (basic calculator) komutu, komut satırında hesap makinesi olarak çalışır. `bc` yazıp Enter ile hesap makinesi açılır. `3 > 1` ifadesi true (1) döner, `4 > 3` ifadesi false (0) döner. Atama operatörü `=` ile yapılır. `bc -l` ile logaritma, üstel fonksiyonlar gibi matematik fonksiyonlar etkinleşir. `echo "scale=4; 22/7" | bc` pipe ile 22/7'yi 4 ondalık hassasiyetle hesaplar. Shell script argümanları önemli bir konudur. `$1`, `$2`, ... gibi değişkenler komut satırında verilen argümanlara erişim sağlar. `$#` toplam argüman sayısını verir. `$@` tüm argümanları liste olarak verir. `$?` son komutun çıkış kodunu verir (0 = başarılı, 0'dan farklı = hata). if koşul yapıları detaylı açıklanır. `if [ koşul ]; then ... elif [ koşul ]; then ... else ... fi` yapısı C'deki if-else yapısına benzer, ancak `[ ]` test komutu yerine kullanılır. Sayısal karşılaştırma operatörleri: `-eq` (eşit), `-ne` (eşit değil), `-gt` (büyük), `-lt` (küçük), `-ge` (büyük eşit), `-le` (küçük eşit). Dosya testleri: `-f` (dosya var mı), `-d` (dizin var mı), `-r` (okunabilir mi), `-w` (yazılabilir mi), `-x` (çalıştırılabilir mi). Döngüler (loops) shell'in güçlü özelliklerindendir. `for` döngüsü: `for i in 1 2 3 4 5; do echo $i; done` (1'den 5'e kadar yazdır). `for i in {1..5}` range sözdizimi daha okunabilir. `{1..10..2}` step sözdizimi (2'şer artarak). `while` döngüsü koşul doğru olduğu sürece tekrarlanır. `until` koşul yanlış olduğu sürece tekrarlanır. `for dosya in $(ls); do ... done` komut çıktısı üzerinde döngü kurar.

### 🔹 Ders 9: CPU Scheduling Detay: Algoritmalar, Multi-Processor, OS Örnekleri
* **Genel Konular:**
  - CPU Scheduling'e Giriş
    - Scheduling kriterleri, algoritmaları, multi-processor scheduling, thread scheduling, OS örnekleri.
    - Process'ler CPU-bound (yoğun hesaplama) veya I/O-bound (yoğun giriş/çıkış) olabilir. Her process CPU burst ve I/O burst'lerden oluşur.
    - Burst süreleri öngörülemez; istatistik ve tahmin yöntemleri kullanılabilir.
  - Scheduling Türleri
    - Long-term scheduler: Programları memory'ye alır (admission).
    - Short-term scheduler: Ready queue'dan CPU'ya process seçer (CPU scheduling).
    - Medium-term scheduler: Swap out/in ile process'leri memory'ye alıp çıkarır (swapping).
  - Scheduling Zamanlamaları
    - 4 durum: (1) Running → Waiting (non-preemptive), (2) Running → Terminated (non-preemptive), (3) Running → Ready (preemptive), (4) Waiting → Ready (preemptive).
    - Sadece 1 ve 4 durumlarında scheduling yapılırsa non-preemptive.
    - 3 ve 4 durumlarında da yapılırsa preemptive.
  - Dispatcher
    - Scheduler'ın seçtiği process'i CPU'da çalıştırmaya başlatan modül.
    - Dispatch latency: Context switch + user mode'a geçiş + uygun yere atlama için harcanan süre. Bu süre az olmalıdır.
  - Scheduling Kriterleri
    - CPU Utilization: İşlemci meşguliyet oranı. Çok yüksek olmamalı.
    - Throughput: Birim zamanda tamamlanan iş sayısı. Maksimize edilmeli.
    - Turnaround Time: Process'in sisteme girmesinden çıkmasına kadar geçen süre. Minimize edilmeli.
    - Waiting Time: Ready queue'da geçen toplam süre. Minimize edilmeli.
    - Response Time: İlk cevap üretme süresi. Minimize edilmeli.
  - Scheduling Algoritmaları
    - **FCFS (First Come First Served)**: Basit, kuyruk bazlı. Convoy effect oluşabilir. Non-preemptive.
    - **SJF (Shortest Job First)**: Burst time'a göre sırala. Optimal ortalama waiting time. Non-preemptive.
    - **SRTF (Shortest Remaining Time First)**: SJF'nin preemptive versiyonu. Yeni gelen daha kısa ise preempt.
    - **Priority Scheduling**: Önceliğe göre seçim. Starvation olabilir. Aging çözüm.
    - **Round Robin (RR)**: Time quantum ile sıralı. Preemptive. Fair.
    - **Multilevel Queue**: Birden fazla kuyruk, her birinin kendi algoritması. Geçiş yok.
    - **Multilevel Feedback Queue**: Kuyruklar arası geçiş var. En genel.
  - Multi-Processor Scheduling
    - Birden fazla işlemci olduğunda scheduling daha karmaşık hale gelir.
    - Asymmetric multiprocessing: Sadece bir işlemci scheduling yapar, diğerleri sadece çalışır.
    - Symmetric multiprocessing (SMP): Her işlemci kendi scheduling kararını verebilir.
    - Processor affinity: Process'in belirli bir işlemcide çalışma isteği (cache reuse için).
    - Load balancing: İşlemciler arası yük dağılımı.
  - Thread Scheduling
    - User-level thread: Library tarafından yönetilir, kernel habersiz.
    - Kernel-level thread: Kernel tarafından yönetilir. Modern OS'lerde tercih edilir.
    - Many-to-one, one-to-one, many-to-many modelleri.
  - Algoritma Örnekleri
    - Linux: CFS (Completely Fair Scheduler), CFS'nin yerine artık EEVDF (Earliest Eligible Virtual Deadline First) kullanılıyor.
    - Windows: Multilevel feedback queue, 32 seviyeli öncelik.
    - Solaris: Multilevel feedback queue, çok sayıda kuyruk.
* **Hocanın Vurgusu:**
  - CPU Utilization'da %100'den Kaçınılması
    - Hoca, "tabii ki utilization'ın 1 olmasını yani %100 olmasını da tercih etmem. Çünkü biraz payı olabilmeli" der. Araba örneği: 220 hız yapabilen araçta sürekli 220 ile gitmek acil durumda hızlanma şansı bırakmaz.
  - Convoy Effect
    - FCFS'de uzun process arkasında kısa process'ler birikir. Düğün alayı örneği: önde düğün alayı arabaları, arkadakiler geçemiyor.
  - Preemption Getirdiği Problemler
    - Hoca vurgular: "Eğer kullandığımız yapı ya da yaptığımız iş belli bir önümüzdeyse tabi ki kullanılabilecek bir model." Ancak preemption paylaşılan veriye erişim sırasında senkronizasyon problemleri yaratır. Mutex ve senkronizasyon gerekir.
  - Preemption Kernel Modundayken Olmamalı
    - "Bir tane daha şey: kernel modundayken preemption oluşması. Bunların her birinde aslında ne sıkıntısı var teknik olarak bakacak olursanız. Siz bir veri üzerinde değişiklik yapıyordunuz. O sırada sistemin preemptive olduğu için çalışmanız durduruldu kenara alındınız." Hoca bu durumun ortalığı ciddi şekilde karıştırabileceğini vurgular.
  - Starvation ve Deadlock
    - Hoca, preemption'un düzgün çözümlenmediğinde starvation ve deadlock'a yol açabileceğini belirtir.
  - Dispatcher vs Scheduler Ayrımı
    - Hoca vurgular: "Scheduler aslında demeyin ki slide'in en başında yazan şey olarak özetleyebilirsiniz. Ready queue'dan bir işlemin CPU'da çalıştırılmak üzere seçilmesi durumu. Neye göre? Belirlenmiş olan kritere göre." Dispatcher ise seçilen process'i CPU'da çalıştıran, kernel mode'dan user mode'a geçen modüldür.
* **Detaylı Açıklamalar:** Ders 9, CPU scheduling kavramını kriterler ve algoritmalar üzerinden derinlemesine ele alır. Bu ders, geçen haftalarda giriş yapılan scheduling konusunu detaylandırır. Process'ler CPU-bound ve I/O-bound olabilir. Her process'in çalışması CPU burst ve I/O burst'lerden oluşur. Burst süreleri önceden bilinemez; istatistiksel yöntemlerle tahmin edilebilir. Tipik bir sistemde kısa CPU burst'ler daha sık görülür, uzun CPU burst'ler daha nadirdir. Scheduling kriterleri sistem türüne göre farklı ağırlıklandırılır. Batch sistemlerde throughput (birim zamanda tamamlanan iş sayısı) önemlidir. İnteraktif sistemlerde response time (ilk cevap süresi) önemlidir. Genel olarak CPU utilization yüksek, turnaround/waiting/response time düşük olmalıdır. FCFS (First Come First Served) en basit algoritmadır. Process'ler geliş sırasına göre çalıştırılır. Non-preemptive'tir. Dezavantajı convoy effect: uzun process CPU'dayken kısa process'ler kuyrukta birikir. Ortalama waiting time optimal değildir. SJF (Shortest Job First) her seferinde en kısa burst time'a sahip process'i seçer. Non-preemptive versiyonu optimal ortalama waiting time verir. Dezavantajı: burst time'ı önceden bilmek gerekir, uzun process'ler starvation'a uğrayabilir. SRTF (Shortest Remaining Time First) SJF'nin preemptive versiyonudur. Yeni gelen process'in burst time'ı, mevcut process'in kalan süresinden az ise preempt yapılır. Priority Scheduling'de her process'e bir öncelik değeri atanır. Düşük değer yüksek öncelik anlamına gelir. Dezavantajı starvation: düşük öncelikli process'ler uzun süre bekleyebilir. Çözüm: aging (process yaşlandıkça önceliği artar). Round Robin her process'e eşit zaman quantum (time slice) verir. Quantum sonunda process preempt yapılır, ready queue'nun sonuna eklenir. Quantum çok küçükse context switch overhead fazla, çok büyükse cevap süresi artar. Multilevel Queue, process'leri öncelik kategorilerine göre farklı kuyruklara ayırır. Her kuyruğun kendi scheduling algoritması olabilir. Process'ler kuyruklar arası taşınmaz. Multilevel Feedback Queue, en genel algoritmadır. Process'ler CPU-bound ise alt kuyruğa, I/O-bound ise üst kuyruğa taşınır. Bu sayede I/O-bound process'ler hızlı cevap alır, CPU-bound process'ler arka planda çalışır. Multi-processor scheduling, birden fazla işlemci olduğunda devreye girer. Asymmetric multiprocessing'de sadece bir işlemci scheduling yapar. Symmetric multiprocessing'de (SMP) her işlemci kendi kararını verebilir. Processor affinity, process'in belirli bir işlemcide kalma isteğidir (cache reuse için). Load balancing, işlemciler arası yük dağılımıdır.

### 🔹 Ders 9 Lab: Processler Arası İletişim: Shared Memory, Message Passing, Producer-Consumer
* **Genel Konular:**
  - Prosesler Arası İletişim (IPC - Inter-Process Communication) Giriş
    - Bir işletim sistemi içinde process'ler bağımsız (independent) veya işbirlikçi (cooperating) olabilir.
    - Bağımsız process'ler birbirinden izole çalışır; birbirini etkilemez.
    - İşbirlikçi process'ler birbirinin çalışmasını etkiler; veri paylaşır, haberleşir.
    - İşbirliğinin avantajı: bilgi paylaşımı, computation hızlandırma (paralelleştirme), modülerlik.
    - Örnek: Web tarayıcılar (Chrome) - main process, renderer process, plugin process olarak ayrı çalışır. Bir tab'da hata olursa diğerleri etkilenmez.
  - IPC İki Temel Modeli
    - **Shared Memory (Paylaşımlı Bellek)**: İki process aynı fiziksel bellek alanı üzerinden haberleşir. Process'lere ait bellek alanları normalde korunur; ancak shared memory'de her iki process de okuma/yazma yapabilir. OS sadece paylaşılan belleği tahsis eder; haberleşmenin yönetimi process'lere aittir.
    - **Message Passing (Mesajlaşma)**: Process'ler arasında mesaj aktarımı ile haberleşme. Doğrudan veya dolaylı olabilir. Paylaşılan alan yoktur; mesajlar aktarılır.
  - Shared Memory ve Message Passing Karşılaştırması
    - Shared memory: Daha hızlı (kernel arada değil, doğrudan bellek erişimi). Haberleşme yönetimi process'lere ait.
    - Message passing: Daha yavaş (kernel dahil), ama distributed sistemlerde de çalışabilir. Mesaj boyutu sınırları, link kapasitesi gibi kısıtlamalar var.
    - Aynı fiziksel sistemde aynı OS üzerinde: shared memory daha hızlı.
    - Farklı sistemlerde: message passing gerekli.
  - Producer-Consumer Problemi
    - Temel senkronizasyon problemi. Producer veri üretir, consumer tüketir.
    - Buffer alanı: Bounded buffer (sınırlı) - gerçekçi, gerçek sistemde sınırsız bellek yok.
    - Buffer durumu: in (eklenecek index), out (çıkarılacak index) pointer'ları.
    - Üretici, boş yer yoksa (in == out, buffer dolu) bekler; tüketici, boş yer yoksa (in == out, buffer boş) bekler.
    - Buffer size = 10 örneği verilir.
  - Direct vs Indirect Communication
    - **Direct Communication**: Process'ler birbirini açıkça adresler. `send(P, message)` ve `receive(Q, message)`.
    - **Indirect Communication**: Mesajlar mailbox (posta kutusu) üzerinden aktarılır. Process'ler mailbox'ı paylaşır.
  - Mailbox (Posta Kutusu) Modeli
    - Her mailbox bir kuyruktur. Mesajlar mailbox'a bırakılır, alıcı mailbox'tan alır.
    - Mailbox kapasitesi: sıfır (randevu) veya sınırlı (buffer).
    - Mesaj önceliği: yüksek öncelikli mesaj önce alınır.
    - "Mailbox'a bırakılan mesaj alındıysa sonsuza kadar alınmış demektir" (tek alıcı varsayımı).
  - Buffer Kapasitesi ve Mesaj Boyutu
    - Link kapasitesi sıfır: Mesaj gönderilemez, alıcı bekliyorsa gönderilir (randevu).
    - Link kapasitesi sınırlı: Belirli sayıda mesaj kuyrukta bekleyebilir.
    - Link kapasitesi sınırsız: Ütopik, gerçekte yok.
    - Mesaj boyutu: Sabit (implementasyon kolay) veya değişken (process açısından kolay).
* **Hocanın Vurgusu:**
  - Shared Memory vs Message Passing Performansı
    - Hoca vurgular: "İkisi de aynı fiziksel sistem üzerinde aynı işletim sistemi üzerinde ise evet zaten hani büyük ihtimalle shared memory çok daha hızlı olacak. Ama zaten farklı sistemlerden bahsediyorsak da yine shared memory'nin kafadan daha iyi olacağını daha hızlı olacağını söyleyebiliriz."
    - Ancak distributed memory şeklinde birbirine bağlıysa shared memory daha hızlı; uzak sisteme başka türlü erişim şansı yoksa message passing.
  - Yönetim Sorumluluğu
    - "Shared memory'deki message passing'e göre önemli farklardan biri kernel işletim sistemi aradaki paylaşılan belleği verdikten sonra haberleşmenin yönetimi işine girmiyor. Bu haberleşmenin yönetimini haberleşen uygulamaların kendisinin yapması lazım."
    - "Halbuki message passing'te az önce hocanızın da söylediği gibi soruya verilen cevapta da söylendiği gibi öyle veya böyle kernel işin içine dahil oluyor."
  - Producer-Consumer Senkronizasyonu
    - Buffer dolu: Üretici bekler. Boş: Tüketici bekler. in == out ise: Hem dolu hem boş olabilir (count değişkeni ile ayırt edilir).
    - "Çünkü onlar bir önceki turdan diğer filozoflar tarafından alınmış olacak." (her philosopher durumu)
  - Link Kurulumu Kararları
    - İki process arasında kaç link? Birden fazla link olabilir (özellikle uni-directional ise).
    - Link kapasitesi ne olacak? Sıfır, sınırlı, sınırsız.
    - Mesaj boyutu sabit mi değişken mi?
    - Uni-directional (tek yön) mi bidirectional (çift yön) mi?
  - Multi-producer / Multi-consumer Yanlış Terim
    - Hoca düzeltir: "Multi producer, multi consumer diye bir terim yok. Producer consumer var. Producer consumer'ın içinde bir tane producer, bir tane consumer; bir tane producer, bir tane consumer; en tane producer, en tane consumer şeklinde kombinasyonları var."
* **Detaylı Açıklamalar:** Ders 9 Lab, process'ler arası iletişim (IPC) kavramını derinlemesine ele alır. Geçen haftaki süreç yönetimi konusundan sonra, process'lerin birbirleriyle nasıl haberleştiği anlatılır. IPC'nin neden gerekli olduğu açıklanır: Process'ler bağımsız çalışabilir (izole), ancak bazen işbirliği yapmaları gerekir. İşbirliğinin avantajları: bilgi paylaşımı, modülerlik, computation hızlandırma. Örnek olarak Chrome tarayıcı verilir: her tab için ayrı renderer process, bir tab çökerse diğerleri etkilenmez. İki temel IPC modeli detaylı şekilde anlatılır: **Shared Memory**: İki process aynı fiziksel bellek alanı üzerinden haberleşir. Normal şartlarda her process'in bellek alanı korunur; ancak shared memory'de her iki process de okuma/yazma yapabilir. OS sadece paylaşılan belleği tahsis eder; haberleşmenin yönetimi process'lere aittir. Avantaj: hızlı (kernel arada değil, doğrudan bellek erişimi). Dezavantaj: senkronizasyon karmaşıklığı process'lere ait. **Message Passing**: Process'ler arasında mesaj aktarımı ile haberleşme. Doğrudan (direct) veya dolaylı (indirect, mailbox üzerinden) olabilir. Avantaj: distributed sistemlerde çalışır. Dezavantaj: kernel dahil olduğu için yavaş; mesaj boyutu sınırları, link kapasitesi gibi kısıtlamalar var. Producer-Consumer problemi detaylı şekilde açıklanır. Bu problem, IPC algoritmalarını test etmek için klasik bir örnek olarak kullanılır. Buffer alanı bounded (sınırlı) olmalıdır çünkü gerçek sistemlerde sınırsız bellek yoktur. Üretici (producer) buffer'a veri ekler; tüketici (consumer) buffer'dan veri alır. Buffer dolu ise üretici bekler; buffer boş ise tüketici bekler. `in` (eklenecek index) ve `out` (çıkarılacak index) pointer'ları buffer'ı yönetir. `in == out` durumu hem "dolu" hem "boş" anlamına gelebilir; bu durumu çözmek için `count` değişkeni kullanılır. Direct vs Indirect Communication karşılaştırması yapılır. Direct communication'da process'ler birbirini açıkça adresler (`send(P, message)`, `receive(Q, message)`); iki process arasında tipik olarak tek link kurulur. Indirect communication'da mesajlar mailbox üzerinden aktarılır; process'ler mailbox'ı paylaşır, böylece birden fazla process aynı mailbox'a yazabilir/okuyabilir. Mailbox (Posta Kutusu) modeli detaylı açıklanır. Mailbox bir kuyruktur; mesajlar mailbox'a bırakılır, alıcı mailbox'tan alır. Mailbox'ın kapasitesi, öncelik yönetimi, mesaj sıralaması gibi tasarım kararları vardır. Kapasite sıfır ise "randevu" modeli uygulanır: gönderici ve alıcı aynı anda hazır olmalıdır. Kapasite sınırlı ise belirli sayıda mesaj kuyrukta bekleyebilir.

### 🔹 Ders 10: Proses Senkronizasyonu: Mutex, Semafor, Klasik Problemler
* **Genel Konular:**
  - Proses Senkronizasyonu (Process Synchronization) Giriş
    - Process'ler ortak kaynaklara (global değişken, veri yapısı, dosya) eşzamanlı eriştiğinde tutarsızlıklar oluşabilir.
    - Senkronizasyon, paylaşılan kaynaklara erişimi düzenleyerek tutarlılık sağlar.
    - İki temel kavram: Critical Section (Kritik Bölge) ve Race Condition (Yarış Durumu).
  - Critical Section (Kritik Bölge)
    - Bir process'in paylaşılan kaynağa erişip değişiklik yaptığı bölge.
    - Örnek: `counter++` operasyonu aslında 3 instruction'dan oluşur (read, modify, write).
    - Process kritik bölgede iken kesilirse (preempt) ve başka process aynı veriye erişirse, tutarsızlık oluşur.
    - Çözüm: Process kritik bölgede iken kesintiye uğramamalı (mantıksal olarak).
  - Race Condition (Yarış Durumu)
    - Birden fazla process aynı veriye eşzamanlı eriştiğinde, sonucun erişim sırasına bağlı olması.
    - Örnek: counter=5 iken P1 ve P2 aynı anda counter'ı arttırıp eksiltmek isterse, sonuç 5 (P1 önce), 4 (P1 sonra, P2 önce) veya 3 (P2 sonra) olabilir.
    - Her çalıştırmada farklı sonuç çıkabilir; tanımlı değil.
  - Mutual Exclusion (Karşılıklı Dışlama)
    - Bir process kritik bölgede iken başka process'ler o bölgeye giremez.
    - 4 şart sağlanmalı: Mutual exclusion, Progress, Bounded waiting, No preemption (kesintisiz çalışma).
  - Peterson Çözümü (Yazılımsal)
    - İki process arasındaki karşılıklı dışlama için yazılımsal çözüm.
    - `flag[]` dizisi: Her process kritik bölgeye girmek isteğini belirtir.
    - `turn` değişkeni: Sıranın kimde olduğunu gösterir.
    - Basit ama ölçeklenebilir değil; modern sistemlerde donanım desteği kullanılır.
  - Donanımsal Çözümler
    - **Memory Barriers (Bellek Engelleri)**: Memory modeline uygun sıralama garantisi.
    - **Hardware Instructions (Test-and-Set, Compare-and-Swap)**: Atomik donanım instruction'ları.
      - `test_and_set`: Hedefi 1 yapar, eski değeri döndürür.
      - `compare_and_swap`: Hedef beklenen değere eşitse yeni değerle değiştirir, eski değeri döndürür.
    - Atomik = kesintisiz, tek instruction olarak çalışır.
  - Mutex Locks (Karşılıklı Dışlama Kilitleri)
    - Basit kilit mekanizması. `acquire()` ile kilit alınır, `release()` ile bırakılır.
    - Kritik bölgeye girmeden önce `acquire()`, çıkarken `release()`.
    - Dezavantaj: Busy waiting (kilit açılana kadar CPU harcar).
  - Semaphores (Semaforlar)
    - Synchronization için kullanılan tamsayı değerli değişken + bekleme kuyruğu.
    - İki tür:
      - **Binary Semaphore (Mutex)**: Değer 0 veya 1. Karşılıklı dışlama için.
      - **Counting Semaphore**: Değer 0-N. Belirli sayıda kaynağa erişim için.
    - İki operasyon:
      - `wait()` (P): Değer ≤ 0 ise bloklan; > 0 ise azalt.
      - `signal()` (V): Değeri arttır, bekleyen process'i uyandır.
    - Kritik bölgelerde `wait(mutex)` ve `signal(mutex)` ile korunur.
  - Senkronizasyon Problemleri
    - **Bounded-Buffer (Sınırlı Tampon) Problem**: Producer-consumer. 3 semafor: `mutex` (1), `full` (0), `empty` (N).
    - **Readers-Writers Problem**: Birden fazla okuyucu aynı anda okuyabilir, ama yazıcı tek başına çalışmalı. `rw_mutex` ve `mutex` semaforları.
    - **Dining-Philosophers Problem**: 5 filozof, 5 çubuk (chopstick). Her filozofun yemek yemesi için 2 çubuk gerekir. Deadlock olabilir.
* **Hocanın Vurgusu:**
  - Semafor Değerinin Sıfır Olamaması
    - Hoca vurgular: "Semaforun değeri hiçbir zaman sıfır olamaz diyoruz. Neden? Çünkü sıfır olduğu durumda semafor hiç yok. Ve process'ler semaforun eğer varlığı varsa kaynağa erişebiliyor ya. Integer değeri 1 ise mesela. O 1 değerini gördüğü zaman kaynağa erişebiliyor ve aynı zamanda semaforun değerini sıfıra çekiyor."
  - Mesaj Kuyruğunda Unlink Gerekliliği
    - Hoca vurgular: "Mesaj queue unlink fonksiyonuyla ilişkisi kopartılmamış hiçbir kuyruk edilemez. Bu fonksiyon ile sonlandırılamaz demişiz. Unlink fonksiyonu silmek üzere işaretliyorum, işim bitti artık benim bu semaforla deyip artık silecek olan fonksiyona benim işim bitti deyip bildiri veriyorduk."
  - Sem_open/Sem_close/Sem_unlink
    - "Bütün process'ler işaretledi benim bu semaforla işim kalmadı diye daha sonra da eminim ki ben process'ler kullanmayacak semaforu. O zaman semclose ile bu semaforu silebilirim."
  - Priority-Based Message Queue Okuma
    - Hoca vurgular: "Mesaj kuyruğunu da en öne geçti bu mesaj. Priority'si 110 aldığı için." Yani priority alanı yüksek olan mesaj önce okunur.
  - Fork Sonrası Message Queue Aktarılamaz
    - "Fork'la yarattığımız process'lere bu message queue'larımızı aktaramıyoruz." Çünkü mesaj kuyruğu process'in sahip olduğu bir kaynak değildir. Message queue'yu tekrar open etmek gerekir.
  - Protection Bayrakları
    - `PROT_READ`: Belleği okuyabilir.
    - `PROT_WRITE`: Belleğe yazabilir.
    - `PROT_EXEC`: Belleği execute edebilir.
    - `PROT_NONE`: Belleğe hiç erişim yok.
    - `MAP_SHARED`: Değişiklikleri paylaş.
    - `MAP_PRIVATE`: Değişiklikleri paylaşma (copy-on-write).
    - `MAP_FIXED`: Adresi sabit.
* **Detaylı Açıklamalar:** Ders 10, proses senkronizasyonunu derinlemesine ele alır. Bu ders, IPC konusunun devamı niteliğindedir: process'ler arası iletişimde veri tutarlılığı nasıl sağlanır? Process'ler ortak kaynaklara (global değişken, veri yapısı, dosya) eriştiğinde tutarsızlıklar oluşabilir. Örnek: iki process aynı `counter` değişkenini arttırmak istiyor. Her biri `counter++` yapar. Bu operasyon aslında 3 instruction'dan oluşur: register'a oku (read), register'ı arttır (modify), register'ı belleğe yaz (write). Eğer P1 read yaptıktan sonra preempt edilir ve P2 read-modify-write yaparsa, P1 modify-write yaptığında eski değer üzerine yazılmış olur; bir arttırma kaybolur. Race condition, birden fazla process aynı veriye eşzamanlı eriştiğinde sonucun erişim sırasına bağlı olmasıdır. Her çalıştırmada farklı sonuç çıkabilir; bu kabul edilebilir değildir. Senkronizasyon bu sorunu çözmek için gereklidir. Critical section problemi, bir process'in paylaşılan kaynağa eriştiği kod bölgesinin korunmasıdır. Bir process kritik bölgede iken başka process'ler o bölgeye girememelidir (mutual exclusion). Bu problemi çözmek için çeşitli yaklaşımlar vardır: **Peterson Çözümü**: İki process arasındaki karşılıklı dışlama için yazılımsal çözümdür. `flag[]` dizisi (her process kritik bölgeye girme isteğini belirtir) ve `turn` değişkeni (sıranın kimde olduğu) kullanılır. Basit ama ölçeklenebilir değildir. **Donanımsal Çözümler**: Modern işlemciler atomik (kesintisiz) instruction'lar sağlar. `test_and_set` hedefi 1 yapar ve eski değeri döndürür. `compare_and_swap` üç parametre alır: hedef, beklenen değer, yeni değer; eşitse değiştirir. Bu instruction'lar atomiktir, kesilmez. **Mutex Locks**: Basit kilit mekanizması. `acquire()` ile kilit alınır, `release()` ile bırakılır. Dezavantajı: busy waiting (kilit açılana kadar CPU harcamak). Bu nedenle modern sistemlerde semaforlar tercih edilir. **Semaphores**: Senkronizasyon için en yaygın kullanılan yapıdır. Tamsayı değer ve bekleme kuyruğundan oluşur. İki operasyonu vardır: `wait(P)` (değer ≤ 0 ise bloklan, > 0 ise azalt) ve `signal(V)` (değeri arttır, bekleyen process'i uyandır). Binary semaphore (mutex) değeri 0 veya 1; counting semaphore değeri 0-N olur. Üç klasik senkronizasyon problemi detaylı şekilde anlatılır: **Bounded-Buffer (Producer-Consumer)**: 3 semafor kullanılır: `mutex` (1, karşılıklı dışlama), `full` (0, dolu slot sayısı), `empty` (N, boş slot sayısı). Producer: `wait(empty)` - `wait(mutex)` - üret - `signal(mutex)` - `signal(full)`. Consumer: `wait(full)` - `wait(mutex)` - tüket - `signal(mutex)` - `signal(empty)`. full + empty = N her zaman. **Readers-Writers**: Veritabanı problemine benzer. Birden fazla okuyucu aynı anda okuyabilir, ama yazıcı tek başına çalışmalı. `readcount` (okuyucu sayısı), `rw_mutex` (yazıcılar için), `mutex` (readcount koruması). **Dining-Philosophers**: 5 filozof, 5 çubuk. Her filozof düşünür veya yer. Yemek için 2 çubuk gerekir. Klasik çözüm deadlock'a yol açar. Asimetrik çözüm: tek numaralı filozoflar önce sol, çift numaralılar önce sağ çubuğu alır. Bu da kaynak dengesizliğine yol açar. Daha iyi çözüm: sırayı değiştirmek.

### 🔹 Ders 10 Lab: Senkronizasyon Lab: Message Queue, Shared Memory, Monitör
* **Genel Konular:**
  - Process Synchronization'a Giriş
    - Modern OS'ler thread yapısı üzerine kurulu (1:1 mapping).
    - Process senkronizasyonu içinde thread senkronizasyonu da girer; ikisi birlikte düşünülmelidir.
    - Bu ders kritik bölge, senkronizasyon çözümleri (yazılımsal, donanımsal), senkronizasyon mekanizmaları (mutex, semafor, monitör) ve klasik senkronizasyon problemlerini kapsar.
  - Critical Section (Kritik Bölge) Problemi
    - Birden fazla process ortak bir alana (global değişken, veri yapısı, dosya) eşzamanlı erişirse tutarsızlıklar oluşur.
    - Aynı processler aynı kodla her seferinde farklı sonuç üretiyorsa, elde edilmesi gereken sonuç net, kesin, değişmez olmalı.
    - Senkronizasyon bunun içindir: race condition oluşmasını engellemek, çalışmayı belirli bir sıraya senkronlamak.
  - Race Condition (Yarış Durumu)
    - Örnek: counter değişkeni üzerinde iki process'in arttırma-eksiltme işlemi. İkisi de okur (5), biri arttırır (6), diğeri eksiltir (4); sonuç farklı olabilir.
    - Bölünmeler, kesintiler olduğunda iç içe geçmiş çalışma sonucu farklı sonuçlar çıkar.
    - Race: yarış demek. Yarışı kimin kazanacağı belirsiz; her çalıştırmada farklı sonuç.
  - Kritik Bölgede Modifikasyon
    - Ortak kaynak üzerinde yapılan modifikasyonun (arttırma, eksiltme, çarpma, bölme, değiştirme) yapıldığı bölge kritik bölgedir.
    - Bir process bu bölgede iken kesintiye uğramamalı (rahatsız edilmemeli).
    - Fiziksel olarak interrupt'ları disable etmek çözüm değildir (OS interrupt-driven çalışır).
  - Çözüm Yöntemlerinin Seviyeleri
    1. Yazılımsal çözümler (Peterson).
    2. Donanımsal çözümler (memory barriers, hardware instructions).
    3. Üst seviye yapılar (mutex lock, semafor, monitör).
  - Peterson Çözümü
    - İki process'in kritik bölgeye girmesini yazılımsal olarak engelleyen algoritma.
    - `flag[i]` = process i kritik bölgeye girmek istiyor mu?
    - `turn` = sıra kimde?
    - Basit ama ölçeklenebilir değil.
  - Donanımsal Çözümler
    - **Memory Barriers**: Memory modeline uygun sıralama garantisi.
    - **Hardware Instructions**: Atomik (kesintisiz) instruction'lar.
      - `test_and_set(&lock)`: lock'u 1 yapar, eski değeri döndürür.
      - `compare_and_swap(&value, expected, new)`: değer expected'a eşitse new ile değiştirir, eski değeri döndürür.
    - Bu instruction'lar kesilemez.
  - Mutex Locks
    - Basit kilit mekanizması. `acquire()` ile kilit al, `release()` ile bırak.
    - Dezavantaj: busy waiting (kilit açılana kadar CPU harcamak).
    - Kilit açılana kadar spin eder.
  - Semaforlar
    - Tamsayı değer + bekleme kuyruğu.
    - `wait(P)`: Değer ≤ 0 ise bloklan, > 0 ise 1 azalt.
    - `signal(V)`: Değeri 1 arttır, bekleyeni uyandır.
    - **Binary Semaphore (Mutex)**: Değer 0 veya 1.
    - **Counting Semaphore**: Değer 0-N.
  - Semafor Örneği (C Kodu)
    ```c
    sem_t mutex;
    sem_init(&mutex, 0, 1);
    sem_wait(&mutex);
    // kritik bölge
    sem_post(&mutex);
    ```
  - Mesaj Kuyruğu (Message Queue)
    - Process'ler arası mesaj alışverişi için.
    - Fonksiyonlar: `mq_open`, `mq_send`, `mq_receive`, `mq_close`, `mq_unlink`.
    - Özellikler: max message, message size, current message count.
    - Mesaj formatı: descriptor, pointer, length, priority.
    - Yüksek öncelikli mesaj önce okunur.
    - Kalıcıdır: kuyruk kapatılsa bile mesajlar silinmez.
    - Writer ve reader aynı anda kuyruğu açmak zorunda değildir.
  - Shared Memory (Paylaşımlı Bellek)
    - Fonksiyonlar: `shm_open`, `shm_unlink`, `mmap`, `munmap`, `ftruncate`, `shm_close`.
    - `mmap`: Paylaşılan belleği process'in adres alanına eşler.
    - `ftruncate`: Dosyanın boyutunu ayarlar.
    - Protection: PROT_READ, PROT_WRITE, PROT_EXEC, PROT_NONE.
    - Flag'ler: MAP_SHARED, MAP_PRIVATE, MAP_FIXED.
    - Fork ile aktarılamaz; tekrar `shm_open` gerekir.
* **Hocanın Vurgusu:**
  - Semafor Kullanım Kuralları
    - Hoca vurgular: "Semaforları çok güzel, çok iyi. Ancak semaforları kullanırken, kullanım kurallarına dikkat etmez ise otomatikman problemlere sebep oluyoruz. Şeyi hatırlayın, size bunu üzerine basa basa söyledik. İşletim sistemleri Deadlock için çok özel bir çözüm üretmiyorlar."
    - "Çünkü Deadlock çözünmesiyle alakalı gerçekleştirecek olan algoritmaların karmaşıklığı yüksek. Onlar için harcanacak olan işlem gücü, boşa harcanmış olan bir işlem gücü."
  - Sinyal/Wait Yanlış Sıra
    - "Eğer aynen bu noktada signal, weight, mutex derseniz bu sırayla kullanırsanız, critical section, herkesin girebileceği bir critical section'a dönüşüyor. Yani critical section olmaktan çıkıyor. Weight, mutex, weight, mutex derseniz siz girebiliyorsunuz critical section'a ama siz çıkamıyorsunuz."
    - "Veya signal'ın bir tanesini veya iki tanesini unutmak ve kullanmamak daha sıkıntılı başka şu anda doğrudan aklımıza gelmese bile problem olacak durumlara yol uçuyor."
  - Monitör Yapısı
    - "Monitorda herhangi bir anda sadece bir proses aktif olabilir. O zaman bakın monitorun girişinde bir kuyruk var. Sadece bir tanesi aktif olduğuna göre, ben de bu kuyruğu sıralı bir kuyruk olarak modelleyebilirim."
    - "Yani monitorun yapısına girdiğinizde bununla ilgili ayrıntıları incelediğinizde aslında monitor bir klas oldu. O monitor kullanılarak synchronizasyon sağlanacağı zaman da o klasdan bir instance, bir objekt oluşturulduğunu göreceğiz."
  - Programcıya Bırakılan Sorumluluk
    - "Burada tabi ki vurgun nereye yapılıyor? Program geliştiren kişinin bunun çok dikkatli kullanmasına yapılıyor. Şimdi sizler bu iş için mühendisi olarak, bunun eğitimini aldığınız için tabi ki her şart altında weight ve signal mekanizmasını, ve ki bounded buffer problemini gördünüz, reader's writers problemini gördünüz, dining closed buffer problemini gördünüz, her şart altında doğru kullanmanız lazım."
* **Detaylı Açıklamalar:** Ders 10 Lab, proses senkronizasyonu konusunu yazılımsal ve donanımsal bakış açısıyla ele alır. Bu ders, IPC konusunun devamıdır: process'ler arası veri paylaşımında tutarlılık nasıl sağlanır? Process'ler ortak kaynaklara (global değişken, veri yapısı, dosya) eriştiğinde tutarsızlıklar oluşabilir. Race condition örneği verilir: iki process aynı `counter` değişkenini değiştirmek istiyor. İkisi de okur (5), biri arttırır (6), diğeri eksiltir (4); sonuç farklı olabilir. Bu tanımlı değildir. Senkronizasyon bunu engellemek için vardır. Kritik bölge (critical section) kavramı detaylı açıklanır. Process'in paylaşılan kaynağa erişip değişiklik yaptığı kod bölgesi kritik bölgedir. Process bu bölgede iken kesilmemelidir. Fiziksel olarak interrupt'ları disable etmek bir çözüm gibi görünür ama OS interrupt-driven çalıştığı için bu kabul edilemez. Çözüm yöntemleri üç seviyede incelenir: **Yazılımsal Çözümler**: Peterson çözümü iki process için tasarlanmış yazılımsal bir algoritmadır. `flag[]` dizisi (her process kritik bölgeye girme isteğini belirtir) ve `turn` değişkeni kullanılır. Basit ama ölçeklenebilir değildir. **Donanımsal Çözümler**: Modern işlemciler atomik (kesintisiz) instruction'lar sağlar. `test_and_set` hedefi 1 yapar ve eski değeri döndürür. `compare_and_swap` üç parametre alır. Bu instruction'lar atomiktir; kesilmezler. **Üst Seviye Yapılar**: Mutex lock'lar (basit ama busy waiting), Semaforlar (wait/signal ile senkronizasyon), Monitörler (klas-tabanlı, paylaşılan değişken ve prosedürler içerir). Üç klasik senkronizasyon problemi detaylı anlatılır: Bounded-Buffer: Producer-consumer. 3 semafor: mutex, full, empty. Readers-Writers: Veritabanı senaryosu. rw_mutex ve mutex. Dining-Philosophers: 5 filozof, 5 çubuk. Deadlock ve starvation riski. Monitör kavramı detaylı açıklanır. Monitör, bir sınıf (class) benzeri yapıdır: paylaşılan veri + bu veri üzerinde çalışan prosedürler içerir. Monitörde herhangi bir anda sadece bir proses aktif olabilir; bu mutual exclusion'ı otomatik sağlar. Koşul değişkenleri (condition variables) ile prosesler senkronize edilebilir. `wait` ve `signal` operasyonları monitör için tanımlıdır. `wait(x)` ile proses bloklanır, başka proses `signal(x)` ile uyandırır. Monitör, semaforların kullanım hatalarını ortadan kaldırır. C kod örnekleri üzerinden mesaj kuyruğu ve paylaşımlı bellek kullanımı gösterilir. `mq_open`, `mq_send`, `mq_receive`, `mq_close` fonksiyonları ile message queue kullanımı; `shm_open`, `mmap`, `ftruncate` fonksiyonları ile shared memory kullanımı açıklanır.

### 🔹 Ders 11: Senkronizasyon Problemleri: Bounded-Buffer, Readers-Writers, Dining-Philosophers
* **Genel Konular:**
  - Senkronizasyon Mekanizmalarının Değerlendirilmesi
    - Bir senkronizasyon mekanizması ortaya atıldığında, işlerliğini ölçmek ve test etmek gerekir.
    - Temel özellikler: Mutual exclusion sağlamalı, Bounded waiting (sınırlı bekleme) sağlamalı, gereksiz beklemenin önüne geçmeli.
  - Klasik Senkronizasyon Problemleri
    - Bu problemler, bir senkronizasyon mekanizmasının uygunluğunu ölçen test problemleridir.
    - Gerçek hayatta da uygulama gerçekleştirirken karşılaşılan senaryolara denk düşer.
  - Bounded-Buffer (Sınırlı Tampon) Problemi
    - Adı üzerinde sınırları belirli bir buffer var. Her slot bir item (karakter, integer, struct, object) tutar.
    - Toplam N item tutulabilir.
    - **Çözüm**: 3 semafor kullanılır.
      - `mutex` (1): Karşılıklı dışlama. Binary semaphore (1 ile başlatılır).
      - `full` (0): Dolu slot sayısı. 0 ile başlatılır.
      - `empty` (N): Boş slot sayısı. N ile başlatılır.
    - **Producer**:
      ```
      while (true) {
        wait(empty);
        wait(mutex);
        // üret, buffer'a ekle
        signal(mutex);
        signal(full);
      }
      ```
    - **Consumer**:
      ```
      while (true) {
        wait(full);
        wait(mutex);
        // tüket, buffer'dan al
        signal(mutex);
        signal(empty);
      }
      ```
    - **Önemli özellik**: `full + empty = N` her zaman. Çünkü dolu + boş = toplam.
    - Bu yapı, istediğiniz sayıda consumer process çalıştırmanıza izin verir; hepsi aynı kod parçasını çalıştırır.
  - Readers-Writers (Okuyucular-Yazıcılar) Problemi
    - Veritabanı modeli: SELECT (okuma), INSERT/UPDATE/DELETE (yazma).
    - Reader: Sadece okur, değişiklik yapmaz.
    - Writer: Hem okur hem yazabilir.
    - **Problem**: Okuma isteği varsa bekletilmemeli (okuma veri değiştirmez). Ancak yazma devam ediyorsa okuma beklemeli.
    - **Çözüm**: 2 semafor + 1 integer değişken.
      - `rw_mutex`: Yazıcıların kendi aralarındaki karşılıklı dışlama.
      - `mutex`: `readcount`'u korumak için.
      - `readcount` (0): Aktif okuyucu sayısı.
    - **Reader**:
      ```
      while (true) {
        wait(mutex);
        readcount++;
        if (readcount == 1) wait(rw_mutex);
        signal(mutex);
        // oku
        wait(mutex);
        readcount--;
        if (readcount == 0) signal(rw_mutex);
        signal(mutex);
      }
      ```
    - **Writer**:
      ```
      while (true) {
        wait(rw_mutex);
        // yaz
        signal(rw_mutex);
      }
      ```
    - **Varyasyonlar**: Reader-priority (yazıcılar starvation'a uğrayabilir) veya Writer-priority (okuyucular starvation'a uğrayabilir).
    - Bazı OS'lerde reader-writer lock'ları doğrudan implement edilmiştir (POSIX, Windows).
  - Dining-Philosophers (Yemek Yiyen Filozoflar) Problemi
    - 5 filozof yuvarlak masada. Her filozofun sağında ve solunda birer chopstick (çubuk) var.
    - Hayat döngüsü: Düşün → Acık → Yer → Düşün. Düşünme = ready, yeme = running, açlık = waiting.
    - Yemek yemek için 2 çubuk (sol + sağ) gerekir.
    - **Naif Çözüm (Deadlock!)**: Her filozof önce sol, sonra sağ çubuğu alır. Tüm filozoflar aynı anda sol çubuğu alırsa, hiçbirinin sağ çubuğu kalmaz → deadlock.
    - **Asimetrik Çözüm**: Tek numaralılar önce sol, çift numaralılar önce sağ. Ancak 0,2,4 = 3 kişi, 1,3 = 2 kişi; dengesizlik. Kaynaklar eşit paylaşılmıyor.
    - **İyileştirilmiş Asimetrik Çözüm**: Her turda 0,2,4 sağdan, 1,3 soldan alır; sonraki turda tersi. Bu sayede iki tam turda eşit pirinç dağıtılır.
    - **Kaynak Sıralama (Resource Hierarchy)**: Çubukları numaralandır. Her filozof artan sırada istesin. Bu circular wait'i engeller.
  - Monitörler
    - Semaforlardan daha üst seviye, daha soyut bir senkronizasyon yapısı.
    - Programcıya yakın; kullanım hatalarını azaltır.
    - **Özellikler**:
      - High level abstraction: Kolay ve etkili senkronizasyon.
      - Sadece bir proses aynı anda aktif olabilir (otomatik mutual exclusion).
      - Kütüphane olarak hazır kullanılabilir.
    - **Yapı**:
      - Shared variables (paylaşılan değişkenler).
      - Procedures (prosedürler, metotlar).
      - Initialization code (constructor).
    - **Condition Variables**: `wait` ve `signal` operasyonları. Semaforlardan farklıdır (değer sayılmaz).
      - `x.wait()`: Proses bloklanır.
      - `x.signal()`: Bekleyen prosesi uyandırır (yoksa etkisiz).
    - **Avantaj**: Programcının yanlış kullanma riski azalır.
    - **Dezavantaj**: Her senkronizasyon problemi için yazılan monitör kodu yeterince etkili olmayabilir.
* **Hocanın Vurgusu:**
  - Klasik Problemlerin Test Amaçlı Kullanımı
    - Hoca vurgular: "Bu problemler aslında ortaya atılan bir sinkronizasyon mekanizmasının sinkronizasyon için uygunluğunu ölçen problemler. Üç tane temel problemimiz var. Bunlar bilişim dünyasında da uygulama gerçekleştirirken, uygulamaların birbirleriyle iletişimi veya uygulama içerisindeki alt parçaların, uygulamaya ayrılmış kaynakları kullanımı ile alakalı senaryolarda da karşımıza çıkıyor."
  - Mutex Semaphore'unun Önemi
    - "Mutex adında bir semaforum var. Wait ile bu Mutex üzerinde bekleme yapıyoruz. Eğer semaforun değeri sıfırdan büyükse ben kritik bölgeye gireceğim ve işlemimi yapacağım."
  - Reader-Writer'da readcount'un Kritik Rolü
    - "Bütün prosesler, okuma yazmak isteyen bütün prosesler readcount'u bir arttıracaklar. İşlemleri bittiği zaman da bir eksilecekler. Read count'u bir arttırıyorum. Eğer read count'u bir ise, yani okuma yapacak ilk proses o ise, o zaman bu prosesin neyi beklemesi lazım? Writer'ları."
  - Dining Philosophers'ta Deadlock
    - Hoca vurgular: "Bu yapı eğer dikkatli bir şekilde gerçekleştirilmez ise büyük problemlere yol açar. Şimdi bir örnek vermiştim. Hani buradaki şu anda anlattığımız çözüm üzerine olan çözüm görülecek. Ve bakın önce konuştuğumuz şey, önce chopstick i'yi alıyor. What is the problem with this algorithm? Nedir? Otomatikman deadlock."
  - Semaforların Doğru Kullanımı
    - Hoca vurgular: "Semaforları çok güzel, çok iyi. Ancak semaforları kullanırken, kullanım kurallarına dikkat etmez ise otomatikman problemlere sebep oluyoruz."
  - Monitörün Yapısal Özelliği
    - "Monitorda herhangi bir anda sadece bir proses aktif olabilir dedik ya, o zaman bakın monitorun girişinde bir kuyruk var. Sadece bir tanesi aktif olduğuna göre, ben de bu kuyruğu sıralı bir kuyruk olarak modelleyebilirim."
* **Detaylı Açıklamalar:** Ders 11, senkronizasyon konularının devamında klasik senkronizasyon problemlerini ve monitör yapılarını ele alır. Bu ders, geçen haftaki semafor ve mutex konularının pratik uygulamalarını gösterir. Senkronizasyon mekanizmalarının işlerliğini test etmek için üç klasik problem kullanılır: **Bounded-Buffer (Producer-Consumer) Problemi**: Bir üretici (producer) ve bir tüketici (consumer) arasında sınırlı bir buffer üzerinden veri alışverişi yapılır. Üç semafor kullanılır: `mutex` (binary, 1 ile başlar), `full` (counting, 0 ile başlar, dolu slot sayısı), `empty` (counting, N ile başlar, boş slot sayısı). Producer önce `empty`'yi bekler (boş yer var mı), sonra `mutex`'a girer, üretir, çıkar, sonra `full`'ı arttırır. Consumer ise `full`'ı bekler (dolu item var mı), sonra `mutex`'a girer, tüketir, çıkar, sonra `empty`'yi arttırır. Önemli özellik: `full + empty = N` her zaman. **Readers-Writers Problemi**: Birden fazla okuyucu aynı anda veri okuyabilir, ancak yazıcı tek başına çalışmalıdır (okuyucu veya başka yazıcı olamaz). Reader, veri değiştirmez; writer hem okur hem yazar. Çözümde `readcount` (aktif okuyucu sayısı) değişkeni, `rw_mutex` (yazıcılar için) ve `mutex` (readcount'u korumak için) semaforları kullanılır. İlk okuyucu `rw_mutex`'i bekler; son okuyucu onu serbest bırakır. **Dining-Philosophers Problemi**: 5 filozof yuvarlak masada yemek yer. Her filozofun sağında ve solunda birer chopstick (çubuk) var. Yemek yemek için 2 çubuk gerekir. Naif çözüm (her filozof önce sol, sonra sağ) deadlock'a yol açar. Asimetrik çözümler veya kaynak sıralama ile çözülür. Bu problem, deadlock'un klasik örneğidir ve dört deadlock koşulunun (mutual exclusion, hold and wait, no preemption, circular wait) hepsinin birden sağlandığını gösterir. **Monitörler**, semaforlardan daha üst seviye bir senkronizasyon yapısıdır. Semaforlarla doğru kullanım sorunları vardır (sıra karıştırma, unutma). Monitör, sınıf (class) benzeri bir yapıdır: paylaşılan değişkenler + bu değişkenler üzerinde çalışan prosedürler içerir. Monitörde herhangi bir anda sadece bir proses aktif olabilir; bu mutual exclusion'ı otomatik sağlar. Koşul değişkenleri (condition variables) ile senkronizasyon sağlanır.

### 🔹 Ders 12: Deadlock: Dört Koşul, Graf Analizi, Çözüm Yöntemleri
* **Genel Konular:**
  - Deadlock (Kilitlenme) Kavramı
    - Karşılıklı kilitlenme: Process'lerin birbirlerini beklemesi sonucu ilerlemenin durması.
    - Process kaynakları ayrılmış durumdadır ancak instruction'ları çalıştırılamıyor. "Ölü" pozisyonda.
  - Kaynak Yönetimi Modeli
    - İşletim sisteminin yönettiği her şey bir kaynaktır: İşlemci, işlemci cycle'ları, bellek alanı, G/Ç cihazları.
    - Bir kaynaktan N kopya olabilir (2 çekirdekli işlemci, 4 disk sürücüsü vb.).
    - Kaynak yönetimi: Request (talep), Use (kullan), Release (serbest bırak) prensibi.
    - Tüm kaynaklar OS üzerinden tahsis edilir; process'ler bypass edemez.
  - Deadlock İçin Dört Gerekli Koşul
    - Dört koşulun hepsi aynı anda sağlanmalıdır (AND/VE ilişkisi).
    1. **Mutual Exclusion (Karşılıklı Dışlama)**: Kaynak aynı anda sadece bir process tarafından kullanılabilir.
    2. **Hold and Wait (Tut ve Bekle)**: Process bir kaynağı tutarken başka kaynaklar için bekliyor.
    3. **No Preemption (Zorla Alma Yok)**: Kaynak, process kendisi serbest bırakmadıkça zorla alınamaz.
    4. **Circular Wait (Döngüsel Bekleme)**: P0 → P1 → P2 → ... → P0 şeklinde bir bekleme döngüsü.
  - Resource Allocation Graph (Kaynak Atama Grafiği)
    - **Vertexler**: Process'ler (daire) ve Kaynaklar (kare, içinde nokta = kopya sayısı).
    - **Kenarlar (yönlü)**:
      - Request edge: Process → Kaynak (talep).
      - Assignment edge: Kaynak → Process (atanmış).
    - **Analiz**:
      - Kapalı çevrim YOKSA → Deadlock YOK.
      - Kapalı çevrim VARSA ve her kaynak tek kopya ise → Deadlock VAR.
      - Kapalı çevrim VARSA ve birden fazla kopya varsa → Deadlock OLABİLİR (kesin değil).
    - Örnek: P1, R2'yi tutuyor + R1'i istiyor; P2, R1'i tutuyor + R3'ü istiyor; P3, R3'ü tutuyor + R2'yi istiyor → Döngüsel bekleme → Deadlock.
  - Deadlock ile Başa Çıkma Yöntemleri
    - **Deadlock Prevention (Önleme)**: Dört koşuldan en az birini ortadan kaldır.
      - Mutual exclusion'ı kaldırmak: Mümkün değil (paylaşılamaz kaynaklar var).
      - Hold and wait'i kaldırmak: Tüm kaynakları önceden talep et (low resource utilization, starvation).
      - No preemption'ı kaldırmak: Kaynağı zorla al (sadece işlemci için mümkün, dosya için değil).
      - Circular wait'i kaldırmak: Kaynakları numaralandır, artan sırayla talep et.
    - **Deadlock Avoidance (Kaçınma)**: Sistemin safe state'te kalmasını sağla.
      - Her process başlamadan önce maksimum ihtiyacını belirtir.
      - Banker algoritması: Safe sequence varsa kaynak tahsis et.
      - Safe state: Tüm process'lerin bir sırayla (P1, P2, ..., Pn) ihtiyaçlarını karşılayabileceği durum.
      - Unsafe state: Deadlock olabilir ama olmak zorunda değil.
    - **Deadlock Detection (Tespit)**: Deadlock oluşmasına izin ver, sonra tespit et.
      - Resource allocation graph + wait-for graph.
      - Maliyetli: Algoritma karmaşıklığı yüksek.
    - **Deadlock Recovery (Kurtarma)**: Deadlock tespit edildikten sonra çöz.
      - Process termination: Deadlock'a dahil process'leri sonlandır.
      - Resource preemption: Kaynakları zorla al, başka process'e ver.
    - **Ostrich Algorithm (Deve Kuşu Algoritması)**: Deadlock'u görmezden gel.
      - Modern OS'lerde en yaygın yaklaşım.
      - Sebep: Algoritma maliyeti yüksek, deadlock nadir oluşuyor.
* **Hocanın Vurgusu:**
  - Dört Koşulun Birlikte Sağlanması
    - Hoca vurgular: "Bu dört şartın dördü de aynı anda geçerli olmalı. Aralarında or veya ilişkisi yok. Aralarında and ve ilişkisi var. Yani bu şartlardan herhangi bir tanesi geçerli değil ise herhangi bir anda o zaman deadlock oluşamaz. Deadlock'ın oluşabilmesi için bu dört şartın dördünün de aynı anda geçerli olması lazım."
  - Resource Allocation Graph Analizi
    - "Kapalı çevrim olmaması, deadlock olmaması anlamına geliyor. Güzel bir şey. Şimdi arada gidip geleceğiz dedim ya, hemen bakın bir tane ok ekledik. Yaptığımız şey çok masum gözüküyor. P3 R2'yi kullanmak istiyor. Şimdi bakın, önce kapalı çevrim hesabı yapmadan, onun takibini yapmadan genel olarak bir düşünelim."
  - Kapalı Çevrim = Deadlock İhtimali
    - "Kapalı çevrim olması demek, deadlock ihtimali çok yüksek demek. Ancak her kapalı çevrim mutlaka ve mutlaka deadlock anlamına gelmiyor. Bunu da unutmamak lazım."
  - Tasarım Hataları Deadlock'a Yol Açar
    - Hoca vurgular: "Deadlock neden oluşur dedik arkadaşlar? Az önce söyledik. Yanlış kullanımdan, yanlış senaryolardan, yanlış itlendirmelerden. Yani aslında tasarımı yapan, programı geliştirenlerin bir şeylere atlamasında."
  - Ostrich (Deve Kuşu) Yaklaşımının Popülerliği
    - "İşletim sistemi deadlock engellemek, deadlock'tan kaçınmak veya deadlock çözmek için eğer kabul edilen sınırların, edilebilecek sınırların dışında işlem gücü harcıyorsa memoriye ihtiyaç duyuyorsa o zaman bunun bir anlamı kalmayacak. Geldiğimiz nokta bu."
  - Aslında İşletim Sisteminin Garantisi
    - Hoca vurgular: "İşletim sistemi üreticileri, yazarları diyorlar ki bir işletim sisteminin içerisinde deadlock olmadığını garanti ediyoruz. Ona göre kodladık. Ona göre test ettik. Hatalarını ayıkladık. Yani kernel'ın içerisinde deadlock yok. Ama işletim sisteminin sunduğu servisleri yanlış kullanırsanız, programlama mantığınız yanlışsa, itlendirmeniz hatalıysa, konküransi seviyesi arttığında gerekli tedbirlere almadıysanız, o zaman kendi başınasınız."
  - Temel Bileşen Sayısı Önemli
    - "En basitinden Cihan Hoca'nız geçen haftalarda da söylemişti, bir Apache Web Server'ı düşündüğünüzde Apache Web Server başladığında kendinden on tane proses oluşturuyor, o proseslerin içinde de diyelim ki beşer tane thread oluyor, oluyor size bir anda elli tane kopya. Bunların birbirleriyle etkileşmemesi mümkün değil."
* **Detaylı Açıklamalar:** Ders 12, deadlock (kilitlenme) kavramını derinlemesine ele alır. Bu ders, senkronizasyon konularının doğal bir uzantısıdır: process'ler senkronizasyon hataları yüzünden sonsuza kadar birbirlerini bekleyebilir. Deadlock, process'lerin birbirlerini beklemesi sonucu ilerlemenin durmasıdır. Process kaynakları ayrılmış durumdadır ancak instruction'ları çalıştırılamıyor. Bu "ölü" pozisyondan çıkmak için dış müdahale gerekir. Deadlock'un oluşabilmesi için dört koşulun hepsinin aynı anda sağlanması gerekir: 1. **Mutual Exclusion (Karşılıklı Dışlama)**: Kaynak aynı anda sadece bir process tarafından kullanılabilir. Bazı kaynaklar doğası gereği paylaşılamaz (yazıcı, dosya). 2. **Hold and Wait (Tut ve Bekle)**: Process bir kaynağı tutarken başka kaynaklar için bekliyor. Örnek: process disk'i tutuyor, yazıcı bekliyor. 3. **No Preemption (Zorla Alma Yok)**: Kaynak, process kendisi serbest bırakmadıkça zorla alınamaz. İşlemci dışında bu genellikle mümkün değil. 4. **Circular Wait (Döngüsel Bekleme)**: P0 → P1 → P2 → ... → P0 şeklinde bir bekleme döngüsü. Her process bir sonrakini bekliyor. Resource Allocation Graph, deadlock analizi için kullanılan grafiksel araçtır. Process'ler daire, kaynaklar kare ile gösterilir (kare içindeki noktalar kopya sayısını gösterir). Request edge (process → kaynak) talebi, assignment edge (kaynak → process) atamayı gösterir. Kapalı çevrim yoksa deadlock yoktur. Kapalı çevrim varsa ve her kaynak tek kopya ise deadlock vardır. Kapalı çevrim olup birden fazla kopya varsa deadlock olabilir ama kesin değildir. Deadlock ile başa çıkma yöntemleri dört kategoride incelenir: **Prevention (Önleme)**: Dört koşulun en az birini ortadan kaldırmak. Ancak her koşul kaldırılamaz: mutual exclusion'ı kaldırmak çoğu kaynak için mümkün değildir; hold and wait'i kaldırmak tüm kaynakları önceden talep etmeyi gerektirir (kaynak israfı); no preemption'ı kaldırmak sadece bazı kaynaklar için mümkündür; circular wait'i kaldırmak en pratik yöntemdir (kaynakları numaralandırma). **Avoidance (Kaçınma)**: Sistemin safe state'te kalmasını sağlamak. Her process başlamadan önce maksimum ihtiyacını belirtir. Banker algoritması safe sequence arar. Safe state: tüm process'lerin bir sırayla ihtiyaçlarını karşılayabileceği durum. Unsafe state: deadlock olabilir ama zorunda değil. Safe → kesin deadlock yok; Unsafe → deadlock olasılığı. **Detection (Tespit)**: Deadlock oluşmasına izin ver, sonra tespit et. Resource allocation graph + wait-for graph kullanılır. Algoritma karmaşıklığı yüksektir. **Recovery (Kurtarma)**: Deadlock tespit edildikten sonra çözmek. Process termination: deadlock'a dahil process'leri sonlandır. Resource preemption: kaynakları zorla al. **Ostrich Algorithm (Deve Kuşu)**: Deadlock'u görmezden gelmek. Modern OS'lerde en yaygın yaklaşımdır çünkü deadlock nadir oluşur, algoritma maliyeti yüksektir ve kernel seviyesinde deadlock olmadığı garanti edilir. Sorun ancak uygulama seviyesinde yanlış kullanımdan doğar. Hoca, modern OS'lerin bu konudaki yaklaşımını açıklar: "İşletim sistemi deadlock engellemek, deadlock'tan kaçınmak veya deadlock çözmek için eğer kabul edilen sınırların dışında işlem gücü harcıyorsa, o zaman bunun bir anlamı kalmayacak. Geldiğimiz nokta bu."

### 🔹 Ders 14: Ana Bellek Yönetimi: Base/Limit, MMU, Binding, Swapping
* **Genel Konular:**
  - Main Memory (Ana Bellek) Yönetimine Giriş
    - İşlemci olmadan programlar çalışamaz, ama programlar bellekte durmalıdır. Bellek, işlemcinin doğrudan eriştiği temel yapı taşıdır.
    - Bu ders: Bellek yönetiminin temelleri, segmentasyon, sayfalama (paging), sanal bellek girişi.
    - İki temel kavram: Spatial locality (mekan yerellik) ve Temporal locality (zamansal yerellik).
  - Belleğin Temel Rolü
    - İşlemci veriyi (data) ve instruction'ları register'lardan ve bellekten alır.
    - Bellek, CPU'nun doğrudan erişebildiği iki temel yapıdan biridir (diğeri register'lar).
    - Cache, CPU ile bellek arasında transparan (şeffaf) bir ara katman olarak çalışır; CPU doğrudan load/store yapar, cache hız kazandırır.
  - Bellek Controller
    - Bellek için de bir controller vardır (diğer çevre birimleri gibi).
    - İşlemciden sürekli okuma/yazma istekleri gelir; her isteğin adres ve data kısmı vardır.
    - Okuma: adres gönderilir, sonuç data olarak döner.
    - Yazma: adres ve data beraber gönderilir.
  - Bellek Hızı Sorunu
    - 2004'te Pentium 3.8 GHz'de çalışıyordu; bugün bile bellek birimleri 2 GHz'e bile yaklaşamıyor.
    - Bu nedenle cache yapısı zorunludur.
  - Protection (Koruma) Kavramı
    - Prosesler adres alanı olarak bellekte izoledir.
    - Aynı kullanıcının iki proses'i bile OS'nin belirlediği kurallar olmadan birbirinin belleğine erişemez.
    - Protection, bir process'in kendi bellek alanı dışına erişiminin donanım seviyesinde engellenmesidir.
  - Base ve Limit Register
    - İşlemci mimarilerinde bellek koruması için iki özel register tanımlanır.
    - Base register: Process'in bellekteki başlangıç adresi.
    - Limit register: Process'in maksimum erişebileceği bellek boyutu.
    - Her bellek erişiminde: `base ≤ adres < base + limit` kontrolü yapılır. Aksi durumda trap (software interrupt) oluşur.
  - Adres Binding (Adres Bağlama)
    - Process'in belleğe yükleneceği yer önceden bilinmez (hangi adreste boş yer varsa oraya).
    - Programcı adres belirleyemez, derleyici de bilemez.
    - Çözüm: Tüm programlar sıfır adresinden başlayacak şekilde derlenir. Relocation (yeniden konumlandırma) ile gerçek yükleme adresine göre offset eklenir.
    - Relocatable: Program sıfır adresine göre derlenir; yüklendiğinde relocation offset eklenir.
  - Binding Zamanları
    - **Compile time (Derleme zamanı)**: Mutlak adresler kullanılır (sistem programı, gömülü sistem). Değiştirilemez.
    - **Load time (Yükleme zamanı)**: Loader programı belleğe yüklerken her adrese offset ekler. Relocatable.
    - **Execution time (Çalışma zamanı)**: Dinamik binding. Shared library, shared object (.so), DLL'ler. Çalışma sırasında adresler bağlanır.
  - Mantıksal vs Fiziksel Adres
    - Mantıksal (logical/virtual) adres: Programın ürettiği, CPU'nun gördüğü adres. Sıfırdan başlar.
    - Fiziksel (physical) adres: Bellek pinlerinde görünen gerçek adres.
    - MMU (Memory Management Unit): Mantıksal adresi fiziksel adrese dönüştüren donanım birimi.
    - Relocation register: MMU'da tutulan, mantıksal adrese eklenen değer.
  - Statik vs Dinamik Linking
    - **Statik Linking**: Program derlenirken tüm kütüphane fonksiyonları programa eklenir. Program boyutu büyür.
    - **Dinamik Linking**: Kütüphane çalışma sırasında programa bağlanır. Unix'te .so (shared object), Windows'ta .dll.
  - Swapping
    - Uzun süre I/O yapacak veya bekleyecek bir process'i bellekten daha iyi yararlanmak için ikinci belleğe (disk) transfer etme.
    - Process control block bellekte kalır; process'in state'i swap out edilmiş duruma getirilir; process'in belleği olduğu gibi diske yazılır.
    - Bekleme bittiğinde swap in: diskten belleğe geri okunur.
    - Roll out/roll in: Öncelik tabanlı scheduling'de düşük öncelikli process çıkarılıp yüksek öncelikli process alınırsa.
    - Backing store: Diskin process'lerin tutulduğu alan.
    - Swapping maliyetli: Process'in tüm belleği dışarı yazılıp tekrar okunmalı.
    - Relocation ile hızlandırılabilir (tek bir relocation register güncellemesi yeterli).
    - Modern OS'lerde normalde kullanılmaz; sadece acil durumlarda (bellek %80-85 dolduğunda) devreye girer.
* **Hocanın Vurgusu:**
  - Programcının Adres Bilmemesi
    - Hoca vurgular: "Ben bir prosesi çalıştırırken daha doğrusu bir programı çalıştırmak için oluşturacağım prosesi memory de hangi adreste oluşturacağımı önceden biliyor muyum? Hayır bilmiyorum. O zaman program yazarı bu programı hangi adrese göre yazacak? Onun da bilebilmesine imkan yok."
  - Sıfır Adres Kuralı
    - Hoca vurgular: "O zaman en akıllıca olan adres bütün programların sıfır adresinden başlaması. Çünkü sıfır adresinden başladığımız zaman programın içerisindeki diğer bütün adresler sıfıra göre relatif adresler olacak. Yani eğer ben bu programı gerçek sistemde sıfır adresinden değil de bin adresinden başlatmak zorunda kalırsam, ki olabilir az önceki örneği gördünüz, o zaman bütün adreslere ne yapmam lazım? Bin değerini eklemem lazım ve bir çırpıda tüm adresler düzelir."
  - Static vs Dinamik Linking Farkı
    - Hoca vurgular: "Eğer static linking yaparsanız programınıza matematik kütüphanesi olduğu gibi eklenecek yani programınızın boyutu büyüyecek. Halbuki siz onun içerisinden sadece neyi kullandınız? Cosunius'u kullandınız. Yani static linking sırasında bir kütüphanenin içerisinden sadece programın ihtiyaç duyduğu fonksiyonu metodu alayım onu programa ekleyeyim. Geri kalanını dışarıda bırakayım gibi bir şey söz konusu değil ne yazık ki. O kütüphanenin tamamen programın içerisinde gömülmesi gerekiyor."
  - Cheat Engine Sorusuna Cevap
    - Hoca açıklar: "Bir debugger mı? Bir şey mi? Simülatör mü? Nedir bu? Tam olarak bilmiyorum da oradan istediğimiz başka bir programı seçip onun memory'sinde arama yapıp değiştirebiliyoruz. Çalışma esnasında mı yoksa offline'da mı? Çalışma esnasında da offline fark etmiyor. Yani offline'de yaparsın zaten. Loader'ın yaptığı gibi ne olacak ki girersin işte bütün adres referansları her türlü şey belirli şey yapabilirsin."
  - Windows Swapping Problemi
    - Hoca, Windows'un %80-85 bellek doluluğunda swapping'i tetiklediğini vurgular: "Sizin 16 GB memory'niz var ancak %80'i 12 GB yani 12 GB doldurduktan sonra son 4 GB kullanmak için aslında ciddi bir yer olmasına rağmen işletim sisteminin yapısından ötürü inanılmaz bir Swapping yapıyorsunuz."
  - Relocation Avantajı
    - Hoca vurgular: "Ancak relocation register'ımız varsa ve bir memory management unit kullanıyorsak, yapmamız gereken yeni adresin, yeni başlangıç adresinin bu process'i memory'de yerleştirdiğimiz yeni başlangıç adresinin değerini relocation register'a vermek. Yani tek bir değeri update ederek devam edebiliyoruz."
* **Detaylı Açıklamalar:** Ders 14, main memory (ana bellek) yönetimine giriş niteliğindedir. Bu ders, dönemin son dersidir ve bellek yönetiminin temellerini ele alır. İşlemci olmadan programlar çalışamaz; ancak programlar da bellekte durmalıdır. İşlemci, register'lar ve bellek üzerinde çalışır. Cache, CPU ile bellek arasında transparan bir ara katmandır; CPU load/store yaparken cache hız kazandırır. Bellek controller'ı, işlemciden gelen okuma/yazma isteklerini yönetir. Bellek hızı, işlemci hızının çok altındadır. 2004'te Pentium 3.8 GHz'de çalışıyordu; bugün bile bellek birimleri 2 GHz'e bile yaklaşamıyor. Bu nedenle cache yapısı zorunludur. Bellek koruması (protection), proseslerin birbirlerinin bellek alanlarına izinsiz erişimini engeller. Base ve limit register'lar bu amaçla kullanılır. Base, process'in bellekteki başlangıç adresini; limit, process'in maksimum erişebileceği bellek boyutunu tutar. Her bellek erişiminde donanım seviyesinde `base ≤ adres < base + limit` kontrolü yapılır. İhlal durumunda trap (software interrupt) oluşur ve OS müdahale eder. Adres binding, mantıksal adreslerin fiziksel adreslere bağlanması sürecidir. Programcı adres belirleyemez (hangi adreste boş yer olacağını bilemez); derleyici de bilemez. Çözüm: tüm programlar sıfır adresinden başlayacak şekilde derlenir (relocatable). Yükleme sırasında relocation offset eklenir. Üç binding zamanı vardır: compile time (mutlak adresler, gömülü sistemler), load time (loader offset ekler, relocatable), execution time (dinamik, paylaşımlı kütüphaneler). Mantıksal (logical/virtual) adres, programın ürettiği CPU'nun gördüğü adrestir. Fiziksel (physical) adres, bellek pinlerinde görünen gerçek adrestir. MMU (Memory Management Unit), mantıksal adresi fiziksel adrese dönüştüren donanım birimidir. Relocation register, MMU'da tutulan, mantıksal adrese eklenen değerdir. Statik linking'de program derlenirken tüm kütüphane fonksiyonları programa eklenir. Dinamik linking'de ise kütüphane çalışma sırasında programa bağlanır; Unix'te .so (shared object), Windows'ta .dll olarak adlandırılır. Dinamik linking program boyutunu küçültür ve kütüphane güncellemelerini kolaylaştırır. Swapping, bellek yönetiminin temel tekniklerinden biridir. Uzun süre I/O yapacak veya bekleyecek bir process'in belleği diske yazılır; process kontrol blok bellekte kalır. Bekleme bittiğinde process geri yüklenir. Swapping maliyetlidir (tüm bellek dışarı yazılıp okunmalı); relocation ile hızlandırılabilir. Modern OS'lerde normalde kullanılmaz; sadece bellek doluluğu eşik değeri aşıldığında (örn. %80-85) devreye girer.

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek ders üzerinde daha verimli çalışabilirsiniz.
