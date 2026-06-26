# Ders 3 Çalışma Özeti

## Genel Konular

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

## Hocanın Özellikle Vurguladığı Kısımlar

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

## Kısa Tekrar Notları

- İşletim sistemi = donanım + sistem programları + uygulamalar arasındaki katman.
- Process = programın çalışan hali; thread = process içindeki bağımsız akış.
- Temel OS servisleri: UI, program execution, I/O, file system, communication, error detection, resource allocation, accounting, protection/security.
- PCB: Process state + PC + register + scheduling + memory + I/O + accounting bilgileri.
- Process state'leri: New → Ready → Running → Waiting → Terminated.
- Context switch: Bir process'in CPU'dan alınıp diğerinin verilmesi; PCB güncellemesi gerekir.
- 0, 1, 2 numaralı file descriptor'lar: stdin, stdout, stderr.
- Kuyruklar linked list ile implemente edilir.

## Detaylı Açıklamalar

Ders 3, işletim sisteminin temel kavramlarını ve sağladığı servisleri ele alır. Bilgisayar sisteminin dört katmanlı yapısı (donanım, OS, sistem programları, uygulamalar) tanıtılır. Modern sistemlerde "kullanıcı" kavramının yalnızca son kullanıcı değil, aynı zamanda makineler, sensörler, IoT cihazları ve diğer yazılımlar olduğu vurgulanır.

İşletim sisteminin ne olduğu, katmanlı yapıda nasıl konumlandığı detaylı şekilde anlatılır. En içte donanım, onu sarmalayan işletim sistemi (kernel), dışta sistem ve uygulama programları, en dışta kullanıcılar bulunur. Her process'in içinde en az bir thread (akış) vardır. Bir process çalışmaya başladığında bile tek bir thread ile başlayabilir; bu thread daha sonra yeni thread'ler oluşturabilir.

İşletim sisteminin sağladığı temel hizmetler dokuz başlıkta ele alınır: (1) User Interface (komut satırı, GUI, dokunmatik), (2) Program Execution (yükleme, çalıştırma, hata yönetimi), (3) I/O Operations (dosya, ağ, kullanıcı etkileşimi), (4) File System (CRUD operasyonları), (5) Communications (süreçler arası iletişim), (6) Error Detection (hata tespiti, debug), (7) Resource Allocation (kaynak tahsisi), (8) Accounting (kullanım takibi), (9) Protection & Security (güvenlik).

Process kavramı derinlemesine anlatılır. Process, programın çalışan halidir; diskte duran program pasif, çalışan process aktif yapıdır. Her process'in bir Process Control Block'ı (PCB) vardır; bu yapıda process'in tüm durumu tutulur. Linux'ta bu yapıya "task_struct" adı verilir. Process state'leri (New, Ready, Running, Waiting, Terminated) detaylı şekilde açıklanır.

Scheduling kavramı ele alınır: CPU'yı hangi process'in ne zaman kullanacağına karar veren mekanizmadır. Process'ler arası geçişte context switch yapılır; bu sırada register değerleri, program counter saklanır/geri yüklenir. Context switch süresi mümkün olduğunca düşük olmalıdır. İşletim sistemi bu amaçla ready queue, I/O device kuyrukları gibi kuyruk yapılarını yönetir. Linux'ta bu kuyruklar linked list ile implemente edilir.

Hocanın vurguladığı önemli bir nokta: Process ve thread kavramları sıklıkla karıştırılır. Process = programın çalışan hali; thread = process içindeki bağımsız akış. Bir process birden fazla thread barındırabilir; her thread aynı process'in kaynaklarını paylaşır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
