# Ders 1 Çalışma Özeti

## Genel Konular

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

## Hocanın Özellikle Vurguladığı Kısımlar

- İşletim Sisteminin İki Farklı Perspektiften Tanımı
  - Hoca özellikle vurgular: İşletim sistemi hem bir kontrol programı (kullanıcının donanımı doğrudan ve uygunsuz şekilde kullanmasını engelleyen) hem de bir kaynak yöneticisidir. Bu iki tanımı birleştirmek önemlidir.
  - "İşletim sistemi bir programdır" vurgusu tekrarlanır. Donanım seviyesinde de (firmware, embedded) yazılabilir; uygulama seviyesinde de (sistem uygulamaları) yazılabilir.

- Veri Yapıları ve Algoritmaların Önemi
  - "İşletim sistemlerinin dayandığı iki temelden biri veri yapıları, diğeri algoritmalardır" cümlesi özellikle vurgulanır. Yönetilecek çok sayıda kaynak ve veri olduğundan uygun veri yapısı seçimi kritiktir.
  - Bu nedenle bu dersin kapsamında ilerleyen konularda (bellek yönetimi, süreç yönetimi, dosya sistemleri) sürekli veri yapılarına atıf yapılacaktır.

- Kavram Karmaşası: Kernel, İşletim Sistemi, Sistem Programları
  - Hoca, "kernel" ile "işletim sistemi" kavramlarının sıklıkla karıştırıldığını vurgular. Kernel, donanımı çevreleyen ve sistem yönetimini sağlayan çekirdek programdır. İşletim sistemi ise kernel + sistem programlarını kapsayan daha geniş bir kavramdır.

## Kısa Tekrar Notları

- İşletim sistemi = donanım ile kullanıcı arasındaki arayüz programı.
- Temel kavramlar: kernel, shell, firmware, bootstrap, bootloader.
- Bilgisayar sistemi = donanım + işletim sistemi + sistem programları + uygulama programları.
- Veri yapıları ve algoritmalar, OS tasarımının iki temel ayağıdır.
- İşletim sisteminin iki temel rolü: kontrol programı + kaynak yöneticisi.
- Linux'ta "task" yapısı process control block'a karşılık gelir; process = programın çalışan hali.
- Firmware donanıma gömülü, işletim sistemi ise donanımın üzerinde çalışan yazılımdır.

## Detaylı Açıklamalar

Ders 1, 2020-2021 Güz dönemi İşletim Sistemleri dersinin ilk dersidir. Bu derste henüz ağırlıklı bir akademik içerik anlatılmaz; dersin tanıtımı, işleyişi, kaynakları ve işletim sisteminin temel kavramları üzerinde durulur. Hocalar, dersin pandemi nedeniyle uzaktan yürütüleceğini, kayıtların paylaşılacağını, iki grubun birleştirilerek işleneceğini açıklarlar. Sistem programcılığı açısından işletim sistemi kavramının neden kritik olduğunu, bilgisayar mühendisliği eğitiminin temel taşlarından biri olduğunu vurgularlar.

İşletim sisteminin tanımı birden fazla açıdan yapılır: kullanıcı ile donanım arasındaki arayüz, kaynak yöneticisi (CPU, bellek, G/Ç cihazları yönetimi), kontrol programı (kullanıcının uygunsuz erişimlerini engelleyen). İşletim sisteminin kendisinin de bir program olduğu, donanım seviyesinden uygulama seviyesine kadar farklı katmanlarda yazılabileceği belirtilir.

Bilgisayar sistemi organizasyonu detaylı şekilde anlatılır: CPU, bellek (data + address bus), her çevre birimi için ayrı bir denetleyici (controller) ve cihaz, yerel tampon bellek. Çok portlu bellek yapılarıyla eşzamanlı erişim sağlanabildiği, dual-channel bellek teknolojisinin bu mantıkla çalıştığı açıklanır. İşletim sisteminin tarihsel gelişimi içerisinde firmware (BIOS) ve bootstrap süreçleri, kernel (çekirdek) kavramı, shell (kabuk) kavramı, sistem çağrıları gibi temel kavramlar tanıtılır.

Hocalar, derste iki temel yaklaşımı vurgular: (1) Kavramların nereden geldiğini anlamak (tarihsel gelişim), (2) Uygulama geliştirirken arka planda nelerin döndüğünü bilmek (performans ve uyumluluk için). Veri yapıları ve algoritmaların OS'nin temel taşı olduğu vurgulanır; bu nedenle bilgisayar mühendisliği öğrencilerinin bu alanlardaki bilgilerinin kritik olduğu belirtilir.

Dersin sonunda yıl içi değerlendirme hakkında bilgi verilir: iki vize (büyük olasılıkla test şeklinde), ödevler, lab çalışmaları ve bir proje olacağı belirtilir. Derslere %80 devam zorunluluğu vardır. Tüm değerlendirme detayları ilerleyen haftalarda netleşecektir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
