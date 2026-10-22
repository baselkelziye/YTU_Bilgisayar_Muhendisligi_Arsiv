# Ders 4 Çalışma Özeti

## Genel Konular

- Merkezi işlem birimi (CPU) ve GPU
  - CPU iki birimden oluşur: kontrol birimi ve aritmetik-mantık birimi (ALU).
  - Kontrol birimi iş akışını yönetir: gelen komutun ne olduğunu, ne yapılacağını ve sonra nereye gidileceğini belirler.
  - ALU işin kendisini yapar: dört işlem, karşılaştırma ve karar verme gibi aritmetik ve mantık işlemleri.
  - GPU (Graphical Processing Unit) ekran kartı görevini ve görüntü/video işleme işlerini yürütür. Çok sayıda çekirdeği olduğu için işleri paralelleştirme potansiyeli yüksektir. Bu yüzden derin öğrenmenin yaygınlaşmasıyla yoğun hesaplamalar GPU'ya devredilmeye başlanmıştır.
  - Merkezde yine CPU vardır: işleri GPU'ya delege eden ve GPU'dan dönen sonuçları işleyen CPU'dur.
- Bellek hiyerarşisi
  - Piramidin üstüne çıktıkça maliyet ve hız artar, kapasite azalır (ekrandan, 00:08:30).
  - En üst katman, kart üzerindeki bellek (inboard memory): register, cache, ana bellek (main memory).
  - Orta katman, harici depolama (outboard storage): manyetik disk, CD-ROM, CD-RW, DVD+RW, DVD-RAM.
  - En alt katman, çevrim dışı depolama (off-line storage): manyetik teyp, MO, WORM.
- Register, cache ve ana bellek
  - Register (Türkçesi yazmaç): CPU içinde bulunan, bilinen en hızlı, en pahalı ve en düşük kapasiteli bellek. CPU işlem yapmadan önce veriyi bellekten ya da cache'ten register'a alır.
  - Cache (ön bellek): o anda çalışan programın sık erişilen bilgilerini CPU'ya yakın tutar. Böylece ana belleğe gitmeden daha hızlı erişim sağlanır. L1, L2 ve L3 olmak üzere kademeli seviyeleri vardır.
  - Ana bellek (RAM, Random Access Memory): register ve cache'ten sonra gelir. Bu üç bellek türü de elektrik varken çalışır, elektrik kesilince içlerindeki bilgi kaybolur.
  - Hız sıralaması: register > cache > ana bellek.
- Ana belleğin yapısı (ekrandan, 00:33:30)
  - Ana bellek her biri 1 byte'lık hücrelerden oluşur. Her hücrenin bir adresi vardır.
  - Hücrelerde veri ya da komut saklanır. Saklanan bilgiler 0 ve 1'lerden oluşur.
  - Hücreye byte bazında erişilir, sonra üzerinde bit bazında işlem yapılabilir.
  - Birden fazla byte kaplayan değişkenler (örneğin 4 byte'lık bir tam sayı) bellekte ardışık hücrelere yerleşir. İşlemci bunları otomatik olarak okuyup register'a alır.
  - Bellek adresleri genellikle onaltılık (hexadecimal) sayılarla ifade edilir. İkili sistemle yazılsaydı adresler çok uzun olurdu.
  - Çalıştırılan program ikinci bellekten ana belleğe yüklenir. Hangi komutun çalışacağı ve kullanılacak veriler de ana bellekte yer alır.
- Bit, byte ve bilgi boyutları
  - Bit (binary digit), bilgisayardaki en küçük birimdir. 0 ya da 1 değerini alır.
  - 1 byte = 8 bit.
  - İkili sistem kullanıldığı için birimler 2'nin kuvvetleriyle ilerler (ekrandan, 00:52:30):
    - 1 kilobyte = 1024 byte (2^10)
    - 1 megabyte = 1.048.576 byte (2^20) = 1024 kilobyte
    - 1 gigabyte = 1.073.741.824 byte (2^30)
    - 1 terabyte = 1.099.511.627.776 byte (2^40)
  - Terabyte'tan sonra petabyte, exabyte, zettabyte ve yottabyte gelir.
- Volatile ve non-volatile bellek
  - Volatile (uçucu) bellek: bilgisayar kapatıldığında bilgiler silinir. Ana bellek böyledir.
  - Non-volatile (kalıcı) bellek: bilgisayar kapatıldığında bilgiler korunur. İkincil bellekler böyledir.
  - Kaydedilmemiş bir belgedeki değişiklikler ana bellekte durduğu için elektrik kesilince kaybolur. Otomatik kaydetme (auto save) özellikleri bu riski azaltır.
- Sanal bellek (virtual memory)
  - Ana bellek yetmediğinde işletim sistemi ikinci belleğin bir kısmını ana bellekmiş gibi kullanır. Veri, sayfalama (paging) yaklaşımıyla parça parça ana bellek ile ikinci bellek arasında yer değiştirir (swap).
  - Böylece program, bellek yetersiz olsa da çalışabilir. Dezavantajı yavaşlamadır, çünkü veri sürekli diskle bellek arasında taşınır.
- İkincil bellekler
  - Manyetik disk (hard disk): veri dönen manyetik plakalar üzerinde saklanır. Plakalar üzerinde hareket eden bir kol ile veriye ulaşılır. Mekanik olduğu için ses çıkarabilir.
    - Dönüş hızı RPM (dakikadaki dönüş sayısı) ile ifade edilir: kişisel bilgisayarlarda 5400, 7200 ve 10.000 RPM. Daha yüksek devirli SCSI diskler sunucularda tercih edilir. <!-- BELİRSİZ: sunucu diskleri için söylenen değer altyazıda "15400" olarak geçiyor; muhtemelen 15.000 RPM -->
    - Veriler sektörlerde saklanır. Birbiriyle ilişkili veriler aynı bölgede tutulursa kol hareketi ve erişim süresi azalır.
  - SSD (Solid State Disk): tamamen elektronik devrelerden oluşur, mekanik hareket yoktur. Bu yüzden çok daha hızlıdır ama daha pahalıdır ve genellikle kapasitesi daha küçüktür. Bilgisayarlarda hibrit yapı da kullanılır: sık erişilen bilgiler SSD'de, yedek niteliğindeki büyük veriler manyetik diskte tutulur.
    - SSD ve flash belleklerin her bir hücresi için sınırlı bir okuma-yazma ömrü vardır (yüz binler mertebesinde). Ancak bu sınır her hücre için ayrı geçerli olduğundan, pratikte normal kullanımda bu sayıya ulaşmak çok zordur.
  - Optik sürücüler (CD-ROM, DVD, Blu-ray): lazer ışığıyla okunur. Yüzeydeki çukurlar ve düz alanlar 1 ve 0 olarak okunur.
    - Kapasiteler: CD yaklaşık 700 MB, DVD 4,7 GB, Blu-ray yaklaşık 25 GB.
    - Kapasite farkı kullanılan katman sayısından ve lazerin dalga boyundan kaynaklanır.
    - Yeniden yazılabilir (rewritable) disklerin de sınırlı yazma sayısı vardır.
  - Disketler (floppy disk): manyetik yapı kullanan, çok az veri saklayabilen eski bellekler.
  - Flash bellekler: USB bellekler, SD kartlar. Küçük boyutta büyük miktarda veri saklayabilir. Telefonlarda ve fotoğraf makinelerinde de kullanılır.
  - Harici hard diskler: içi manyetik hard disk olan ama veriyi USB portu üzerinden aktaran disklerdir.
  - Manyetik teypler: eskiden büyük verilerin yedeklenmesinde sık kullanılırdı.
- Seri ve paralel veri aktarımı
  - Dahili diskten belleğe veri aktarımı SATA (seri) ya da PATA (paralel) gibi arayüzlerle yapılır.
  - Paralel aktarımda veri aynı anda birden fazla hat üzerinden (örneğin 8 hat) gider. Seri aktarımda veri tek hat üzerinden gider.
  - Paralel aktarım her zaman daha hızlı değildir, çünkü iki yöntemin aktarım protokolleri farklıdır. Günümüzde birçok cihaz seri haberleşme kullanır.
- Rastgele ve sıralı erişim
  - Rastgele (doğrudan, direct access) erişim: istenen konuma adres verilerek doğrudan gidilir. RAM ve manyetik disk böyledir. Veri yapılarında dizi buna örnektir.
  - Sıralı erişim: istenen bilgiye ulaşmak için önceki bilgilerin hepsinden adım adım geçmek gerekir. Veri yapılarında bağlı liste (linked list) buna örnektir.
  - Rastgele erişim sıralı erişime göre çok daha hızlıdır.
- ROM ve firmware
  - ROM (Read Only Memory), bilgisayarın ilk açılışında çalışacak komutları ve BIOS (Basic Input Output System) ayarlarını saklar. Örneğin işletim sisteminin hangi bellek bölgesinden ve ne kadar veri yüklenerek başlatılacağı burada kayıtlıdır.
  - Klasik ROM yalnızca okunur. Daha sonra belirli sayıda yazılıp silinebilen (erasable) ROM türleri geliştirilmiştir.
  - Firmware, donanımın yeteneklerini kullanmayı sağlayan, ROM üzerine yazılan yazılımdır. Firmware güncellemesiyle cihaza yeni yetenekler kazandırılabilir (örneğin akıllı televizyonlar). Donanımın kapasitesi yetmediği noktadan sonra üretici güncelleme göndermeyi bırakır.
  - Analog veriyi dijitale çeviren birim ADC'dir (Analog to Digital Converter). Kamera ve mikrofondan gelen analog veri ADC ile dijitale dönüştürülür.
- Bilgisayar organizasyonu katmanları
  - En altta donanım (ekran kartı, ses kartı, ana kart, işlemci, bellekler) vardır.
  - Donanımın üzerinde makine dili vardır. Bilgisayar 0 ve 1'lerden oluşan makine dilini anlar.
  - Makine diline en yakın dil assembly dilidir (alt seviye programlama dili). Farklı işlemci mimarilerinin farklı komut setleri vardır.
  - Makine dilinin üzerinde işletim sistemi, onun üzerinde sistem yazılımları (derleyiciler, yorumlayıcılar, editörler, veritabanları) ve en üstte uygulama yazılımları vardır.
- İşlemci mimarileri ve komut setleri
  - x86 mimarisi ağırlıklı olarak kişisel bilgisayarlarda (Intel), ARM mimarisi ağırlıklı olarak mobil cihazlarda kullanılır.
  - İşlemciler komutlarla çalışır, bu komutlar komut setini oluşturur. İki temel tür vardır:
    - RISC (Reduced Instruction Set): daha basit komutlar vardır. Karmaşık işler basit komutların birleştirilmesiyle yapılır.
    - CISC (Complex Instruction Set): daha fazla ve daha karmaşık komut vardır. Karmaşık işler doğrudan karmaşık komutlarla yapılır.
  - Yazılımlar (işletim sistemi dahil) işlemci mimarisine uygun olmalıdır. Uygun olmayan bir işletim sistemi kurulmaya çalışıldığında hata alınır.
- İşletim sisteminin görevleri
  - İşletim sistemi bilgisayardaki en temel sistem yazılımıdır ve kaynak yönetiminden sorumludur.
  - Görevleri: süreç yönetimi (process management), bellek yönetimi (memory management), dosya yönetimi, cihaz yönetimi ve giriş/çıkış yönetimi.
- Yazılım türleri
  - Sistem yazılımları: sistemi doğrudan ilgilendiren yazılımlardır. İşletim sistemi, derleyiciler (yazılan programı makine diline çevirir) ve yorumlayıcılar (interpreter) bu gruptadır.
  - Uygulama yazılımları: belirli bir alana (domain) özel, kullanıcıların ihtiyaçlarına yönelik yazılımlardır. Oyunlar, eğitim uygulamaları, çizim (CAD) uygulamaları, istatistik paketleri, müzik/video oynatıcılar, Word ve Excel örnektir.
- Programlama dillerinin nesilleri (ekrandan, 01:18:25)
  - 1\. nesil: makine kodu (machine code). Komutlar 0 ve 1'lerle ifade edilir. Okuması zordur ve hata yapmak kolaydır.
  - 2\. nesil: assembly diller (1950'ler). İkili sayı yerine anlaşılır kısaltmalar kullanılır. Örnek: `ADD AX, BX` (AX ve BX register'larındaki değerleri topla). Alt seviye (low level) diller olarak geçer. Assembly kodunu makine koduna (object code) çeviren programa assembler denir.
  - 3\. nesil: yöntemsel (procedural) diller. İngilizce komutlar kullanan ileri seviye (high level) dillerdir: Fortran, Algol, Pascal, C, Java (ekrandan, 01:24:10).
  - 4\. nesil: uygulamaya özel diller.
  - 5\. nesil: kısıtlı diller.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bellek hiyerarşisi mutlaka bilinmeli
  - Hangi belleğin en hızlı, en pahalı ve en düşük kapasiteli olduğu sorusu önemlidir. Yukarı çıktıkça hız ve maliyet artar, kapasite azalır.
- 1 kilobyte 1000 değil 1024 byte'tır
  - Bellek ikili sisteme göre çalıştığı için birimler 2'nin kuvvetleriyle hesaplanır. 1 megabyte = 1024 kilobyte.
- Volatile ve non-volatile terimleri not alınmalı
  - Elektrik kesilince silinen bellek volatile, silinmeyen bellek non-volatile olarak adlandırılır.
- Kullanıcı hatalarını öngören yazılım geliştirmek
  - Bilgisayar mühendisinin görevlerinden biri, kullanıcı tarafında oluşabilecek hataları öngörerek program yazmaktır. Örnek: form doldururken bağlantı koparsa yazılanların kaybolmaması için cevapları otomatik kaydetmek.
- Assembly'nin sınırları ve yüksek seviye dillere geçiş
  - Assembly'de basit bir iş bile çok satır gerektirir. Her işlemci mimarisinin farklı komut seti olduğu için her mimari için ayrı komut seti öğrenmek gerekir. Hoca bunu her ülkenin dilini ayrı ayrı öğrenmeye benzetir. Yüksek seviye diller ise araya giren bir çevirmen (derleyici ya da yorumlayıcı) sayesinde tek dille çalışmayı sağlar.
- Çeviricinin kalitesi performansı doğrudan etkiler
  - Dil seviyesi yükseldikçe daha az komutla daha çok iş yapılır. Örneğin Python'da 3 satırlık bir iş C'de 15-20 satır sürebilir. Ancak kötü bir derleyici kodu verimsiz makine koduna çevirirse program yavaş çalışır.

## Kısa Tekrar Notları

- CPU = kontrol birimi (iş akışı) + ALU (aritmetik/mantık işlemleri). GPU paralel işlemde güçlüdür, ama koordinasyon CPU'dadır.
- Bellek piramidi (yukarıdan aşağı): register → cache (L1/L2/L3) → ana bellek → manyetik disk / optik disk → manyetik teyp. Yukarı çıktıkça hız ve maliyet artar, kapasite azalır.
- Ana bellek: 1 byte'lık adreslenebilir hücreler. Adresler hexadecimal yazılır.
- Bit = binary digit. 1 byte = 8 bit. 1 KB = 2^10 byte = 1024 byte. 1 MB = 2^20, 1 GB = 2^30, 1 TB = 2^40 byte.
- Volatile = kapatınca silinir (RAM). Non-volatile = kalıcıdır (disk, flash).
- Sanal bellek: RAM yetmeyince disk RAM gibi kullanılır (paging/swap). Bedeli yavaşlamadır.
- HDD: mekanik, RPM, sektör. SSD: elektronik, hızlı, pahalı, hücre başına yazma ömrü vardır.
- CD ≈ 700 MB, DVD = 4,7 GB, Blu-ray ≈ 25 GB. Fark katman sayısından ve lazer dalga boyundan gelir.
- SATA = seri, PATA = paralel. Paralel her zaman daha hızlı değildir.
- Rastgele erişim (dizi, RAM) > sıralı erişim (bağlı liste) hız bakımından.
- ROM: açılış komutları ve BIOS. Firmware ROM'a yazılır.
- ADC: analog veriyi dijitale çevirir.
- RISC = az ve basit komut. CISC = çok ve karmaşık komut. x86 → PC, ARM → mobil.
- Dil nesilleri: makine kodu → assembly → yöntemsel (C, Java...) → uygulamaya özel → kısıtlı.

## Detaylı Açıklamalar

Ders, bir önceki derste başlanan bilgisayar birimleri konusunun devamıdır. Merkezi işlem birimi iki parçadan oluşur. Kontrol birimi işlerin hangi sırayla yapılacağını yönetir: gelen komutun ne olduğunu çözer ve bir sonraki adımı belirler. Aritmetik-mantık birimi ise dört işlem, karşılaştırma, karar verme gibi işlerin kendisini yapar. Son yıllarda GPU da önemli bir işlem birimi hâline gelmiştir. Grafik ve video işlemleri için tasarlanan GPU, çok sayıda çekirdeğe sahip olduğundan paralel işlemde çok güçlüdür. Bu nedenle özellikle derin öğrenme gibi yoğun hesaplamalarda iş GPU'ya devredilir. Ancak bu işleri dağıtan ve sonuçlarını toplayan yine CPU'dur.

Bellekler bir piramit olarak düşünülür. Piramidin tepesindeki register'lar CPU'nun içindedir, en hızlı ve en pahalı bellektir ama kapasitesi en düşüktür. CPU herhangi bir işlem yapmadan önce veriyi register'a almak zorundadır. Register'ın altında cache (ön bellek) gelir. O an çalışan programın sık eriştiği bilgiler ana bellek yerine cache'te tutulursa işlemci bunlara çok daha hızlı ulaşır. Cache L1, L2 ve L3 olarak kademelidir. Ardından ana bellek, yani RAM gelir. Bu üç bellek türü elektrik olduğu sürece bilgiyi tutar. Elektrik kesilince bilgi kaybolur, bu yüzden volatile (uçucu) bellek olarak adlandırılır. Kapasiteleri ikincil belleklere göre düşük, maliyetleri ve hızları yüksektir.

Ana bellek 1 byte'lık hücrelerden oluşur ve her hücrenin bir adresi vardır. Bu hücrelerde hem veri hem de komutlar saklanabilir. Bir program çalıştırıldığında ikinci bellekten ana belleğe bir kopyası yüklenir, hangi komutun çalışacağı ve kullanılacak veriler de buradan okunur. Birden fazla byte kaplayan veriler, örneğin 4 byte'lık bir tam sayı, ardışık hücrelere yerleşir ve işlemci bunları tek seferde okuyabilir. Adresler genellikle onaltılık sayılarla yazılır, çünkü ikili gösterim çok uzun olur. Metin, resim, ses ve sayı gibi her türlü bilgi sonunda 0 ve 1'ler olarak saklanır. Dış dünyadan gelen analog veri (kamera görüntüsü, mikrofon sesi) ADC ile dijitale çevrilir.

Bilginin en küçük birimi bittir (binary digit) ve 0 ya da 1 değerini alır. 8 bit bir byte eder. Bellek ikili sisteme göre çalıştığı için üst birimler 2'nin kuvvetleriyle ilerler: 1 kilobyte 1000 değil 1024 byte'tır (2^10), 1 megabyte 1024 kilobyte'tır (2^20). Gigabyte (2^30) ve terabyte (2^40) bunu izler, ardından petabyte, exabyte, zettabyte ve yottabyte gelir. Bir öğrencinin sorusu üzerine, depolama üreticilerinin kapasiteyi 1000'in katlarıyla verdiği için işletim sisteminde daha düşük göründüğü konuşulur. Hoca bunun nedeni konusunda kesin bilgi vermez, kullanıcı algısının etkili olabileceğini söyler.

Ana belleğin yetmediği durumlarda işletim sistemi sanal bellek kullanır. Örneğin 4 GB RAM'in 2 GB'ı boşken 4 GB'lık veriyle çalışan bir program açılırsa, işletim sistemi veriyi sayfalar hâlinde ana bellek ile disk arasında taşır (paging/swap). Program çalışır, ama disk erişimi yavaş olduğu için performans düşer.

İkincil bellekler kalıcıdır (non-volatile). Manyetik diskte veri dönen plakalarda saklanır ve mekanik bir kol ile okunur. Dönüş hızı RPM ile ölçülür, devir arttıkça erişim hızlanır. İlişkili verilerin aynı bölgede tutulması kolun daha az hareket etmesini sağlar. SSD'de mekanik parça yoktur. Tamamen elektronik olduğu için çok hızlıdır ama daha pahalıdır. Bu yüzden bazı bilgisayarlarda sık kullanılan veriler SSD'de, büyük yedekler manyetik diskte tutulur. SSD ve flash bellek hücrelerinin sınırlı bir yazma ömrü vardır, ancak bu sınır hücre bazında olduğu için pratikte normal kullanımda bu sınıra ulaşmak çok zordur. CD, DVD ve Blu-ray gibi optik diskler lazer ile okunur: yüzeydeki çukur ve düz alanlar 1 ve 0 olarak yorumlanır. DVD ve Blu-ray'in daha yüksek kapasitesi daha fazla katman kullanılmasından ve lazerin dalga boyundan gelir. Bunlara ek olarak USB flash bellekler, SD kartlar, harici hard diskler ve büyük yedekler için manyetik teypler kullanılır. Diskten belleğe veri aktarımı SATA (seri) gibi arayüzlerle yapılır. Paralel aktarım aynı anda birden fazla hat kullanır, ancak protokoller farklı olduğu için paralel her zaman daha hızlı değildir.

Erişim türleri ikiye ayrılır. Rastgele (doğrudan) erişimde istenen konuma adres verilerek hemen gidilir, RAM böyle çalışır. Sıralı erişimde ise bir bilgiye ulaşmak için ondan önceki tüm bilgilerden geçmek gerekir. Veri yapılarında dizi rastgele erişime, bağlı liste sıralı erişime örnektir. ROM ise bilgisayarın açılışında çalışacak komutları ve BIOS ayarlarını saklar. Eskiden yalnızca okunabilen ROM'lar bugün belirli sayıda silinip yazılabilmektedir. Bu sayede firmware güncellemeleriyle donanıma yeni yetenekler kazandırılabilir. Donanım yeni yazılımı kaldıramaz hâle geldiğinde üretici güncellemeyi keser.

Bilgisayar organizasyonu katmanlı bir yapıdır. En altta donanım, onun üzerinde makine dili, ardından işletim sistemi, sistem yazılımları (derleyiciler, yorumlayıcılar, editörler, veritabanları) ve en üstte uygulama yazılımları bulunur. İşlemciler komut setleriyle çalışır. RISC mimarisinde az sayıda basit komut vardır ve karmaşık işler bu komutların birleşimiyle yapılır. CISC mimarisinde çok sayıda karmaşık komut vardır. x86 mimarisi çoğunlukla kişisel bilgisayarlarda, ARM mimarisi çoğunlukla mobil cihazlarda kullanılır. Yazılımlar işlemci mimarisine göre derlendiği için uygun olmayan bir işletim sistemi kurulamaz. İşletim sistemi en temel sistem yazılımıdır ve süreç, bellek, dosya, cihaz ve giriş/çıkış yönetiminden sorumludur.

Son olarak programlama dillerinin nesilleri ele alınır. Birinci nesil makine kodunda komutlar doğrudan 0 ve 1'lerle yazılır. Bilgisayar için yorumlaması kolaydır, ama insan için okumak ve hatasız yazmak çok zordur. İkinci nesil assembly dilleri 1950'lerde ortaya çıkar. `ADD AX, BX` gibi kısaltmalarla makine koduna en yakın, ancak insanın okuyabileceği komutlar kullanılır. Assembly kodu bir assembler tarafından makine koduna çevrilir. Assembly'de de basit işler çok satır gerektirir ve her mimari için ayrı komut seti öğrenmek gerekir. Bu sorunu üçüncü nesil yöntemsel (yüksek seviye) diller çözer: Fortran, Algol, Pascal, C ve Java gibi diller İngilizceye yakın komutlarla az kodla çok iş yapmayı sağlar. Bu dillerde yazılan kod bir derleyici ya da yorumlayıcı ile makine koduna çevrilir. Çevirmenin kalitesi programın performansını doğrudan etkiler. Dördüncü nesil uygulamaya özel diller ve beşinci nesil kısıtlı diller ileriki derslerde ayrıntılı ele alınacaktır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
