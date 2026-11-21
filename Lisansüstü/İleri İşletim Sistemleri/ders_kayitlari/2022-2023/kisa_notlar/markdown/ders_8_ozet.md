# Ders 8 Çalışma Özeti

## Genel Konular

- Sanallaştırma türleri ve ESX Server'ın yeri
  - Derste "Memory Resource Management in VMware ESX Server" makalesi soru-cevapla tartışıldı. Ekran paylaşımı yapılmadı, anlatım tamamen sözlüydü.
  - Java Virtual Machine (JVM) gibi yaklaşımlar sanal bir işlemci mimarisi tanımlar. Kendi genel komutlarını (move, add, increment, decrement, compare) alttaki gerçek işlemcinin (Intel, ARM, PowerPC) komutlarına çevirir. Böylece kod, yeniden derlenmeden farklı mimarilerde çalışır.
  - ESX Server'daki sanallaştırma bundan farklıdır: donanımın sanal kopyalarını oluşturur, işlemci mimarisini değiştirmez. Alttaki donanım Intel ise üstte çalışan her işletim sistemi Intel için yazılmış olmalıdır.
  - Amaç, aynı donanım üzerinde birden çok işletim sisteminin birbirinden habersiz, her biri donanımın tek sahibiymiş gibi çalışmasıdır. CPU, bellek ve çevre birimleri (disk, ağ) bu açıdan yalıtılır.
  - Hoca üç sanallaştırma türü saydı: tam sanallaştırma (full virtualization), para-sanallaştırma (paravirtualization) ve işletim sistemi seviyesinde sanallaştırma (OS-level virtualization).
- Hosted mimari ile ESX Server farkı
  - VMware Workstation bir hosted mimaridir: var olan bir işletim sisteminin (örneğin Linux) üzerinde çalışır. Sanal makinenin sanal diskinden okuma isteği, sanal makine monitörü (VMM) tarafından yakalanır ve alttaki Linux'a bir `read` sistem çağrısı olarak iletilir.
  - ESX Server ise donanımı doğrudan yönetir. Bu, daha yüksek G/Ç başarımı ve kaynak yönetimi üzerinde tam denetim sağlar. ESX, amacı sanallaştırma olan bir işletim sistemidir.
- Üç adres kavramı: sanal, fiziksel, makine adresi
  - Sanal adres prosesten (CPU'nun ürettiği adres olarak) çıkar.
  - Fiziksel adres, prosesin çalıştığı konuk işletim sisteminin sayfa tablosuyla ürettiği adrestir. Sanallaştırma yoksa doğrudan RAM'e gider.
  - Makine adresi, VMM'nin fiziksel adresi bir kez daha çevirmesiyle elde edilen gerçek bellek adresidir. Makalede sanal sayfa numarası, fiziksel sayfa numarası (PPN) ve makine sayfa numarası (MPN) olarak geçer.
  - İkinci çevirinin nedeni: her işletim sistemi de bir programdır ve adreslerinin sıfırdan başladığını görmek ister. Sistemde gerçek sıfır adresi tektir; bu yüzden her konuğa "sıfırdan başlayan" bir fiziksel adres uzayı verilir ve bu uzay makine adreslerine eşlenir.
- Balonlama (ballooning)
  - VMM'nin bir konuktan bellek geri alması gerekir. VMM sayfaları kendisi diske çıkarırsa "double paging" sorunu doğar ve konuğun hangi sayfayı az kullandığını bilemez. Konuk işletim sistemi de değiştirilmek istenmez.
  - Çözüm: konuğa yüklenen küçük bir çekirdek modülü ya da aygıt sürücüsü (balon sürücüsü). Bu, konuğu değiştirmek sayılmaz; çekirdek bu yapıyı zaten sunar.
  - Şişirme (inflate): sürücü konuktan sabitlenmiş (pinned) fiziksel sayfalar ister. Konuk belleğin bittiğini sanır ve kendi algoritmasıyla kullanılmayan sayfaları dışarı çıkarır (page stealing / page out). Balonun tuttuğu sayfalar VMM'ye devredilmiş olur.
  - Söndürme (deflate): sürücü sayfaları serbest bırakır, konuk belleği arttı sanır ve sayfa çalmayı bırakır.
  - Sürücüler (Linux, FreeBSD, Windows için) sunucuyu saniyede bir yoklayarak hedef balon boyutunu öğrenir ve konuğu zorlamamak için tahsis hızını uyarlamalı olarak sınırlar. Sayfa tahsisinde standart çekirdek arayüzleri kullanılır (Linux'ta `get_free_page`, Windows'ta `MmAllocatePagesForMdl` ya da `MmProbeAndLockPages`).
  - Makale yazıldığında işletim sistemleri çalışırken bellek eklemeyi (hot-pluggable memory) desteklemiyordu. Makale bunun ileride kaba taneli (coarse-grained) bir balonlama biçimi sağlayabileceğini söyler. Hoca, bugün sunucularda çalışır durumdayken bellek takılabildiğini ekledi.
- Şeffaf sayfa paylaşımı (transparent page sharing)
  - "Şeffaf", konuk işletim sistemlerinin haberi olmadan, onlara sorulmadan ve çalışmaları değişmeden yapılan paylaşım demektir.
  - Konuklar birbirinden habersiz olduğu için aynı içerikli sayfaları kendileri paylaşamaz. Bunu bir üst seviyeden bakan VMM yapar. Örnek: aynı sürümdeki iki konuğun yüklediği libc paylaşılan nesnesi (Windows'ta DLL) bellekte tek kopya tutulur.
- İçerik tabanlı sayfa paylaşımı (content-based page sharing)
  - VMM konuğun sistem çağrılarını izlemek ya da konuk kodunu kancalamak (örneğin bcopy kancalama) istemez. Bunun yerine sayfaların içeriğine bakıp aynı olanları bulur.
  - Her sayfayı her sayfayla karşılaştırmak $O(n^2)$ maliyetlidir. Bunun yerine her sayfanın özeti (hash) hesaplanıp bir özet tablosunda aranır.
  - Özet eşleşince çakışma (collision) olasılığına karşı sayfalar ayrıca tam olarak karşılaştırılır.
  - Paylaşılan sayfaya bir konuk yazmak isterse yazma anında kopyası çıkarılır: copy-on-write. Hoca bunu depolamadaki tekilleştirmeye (deduplication) benzetti.
  - Makalede taranan her sayfa için hızlı, yüksek kaliteli bir fonksiyonla 64 bitlik özet üretilir. Bu güvenli (secure) bir özet değildir.
- Sayfa paylaşımı başarımı
  - Eşzamanlı sanal makine sayısı arttıkça paylaşımla kazanılan bellek yaklaşık doğrusal artar. Hoca 10 sanal makinede yaklaşık 400 MB kazanç okudu.
  - Hoca, sanal makine belleğinin yaklaşık %67'sinin tekilleştirilebildiğini, böylece bir sanal makinenin belleğin yaklaşık üçte biriyle çalışabildiğini söyledi.
  - Gerçek kurulumlarda (Figure 5): A senaryosunda (Windows NT, 2 GB) yaklaşık %43, B senaryosunda (Linux, 1846 MB) yaklaşık %29, C senaryosunda (Linux, 1658 MB) yaklaşık %10 paylaşım. C'de geri kazanılan bellek yaklaşık %7, yani 120 MB'tır; bunun 25 MB'ı sıfır sayfalardan (tahsis edilmiş ama hiç yazılmamış sayfalar) gelir.
- Boşta bellek vergisi (idle memory tax)
  - Bir sanal makine ayırdığı belleğin çoğunu kullanmıyorsa, boşta tuttuğu bellek için daha fazla "vergi" öder. Bu bir ceza fonksiyonuna (penalty function) dayanır; tahsis ve geri alma bu fonksiyona göre yapılır.
  - ESX Server'da vergi oranı ayarlanabilir bir parametredir ve öntanımlı değeri %75'tir. Bu oran sistemdeki boşta belleğin çoğunun geri alınmasını sağlarken çalışma kümesinin hızlı büyümesine karşı tampon bırakır ve balonlama ile takas gibi geri alma işlemlerinin gecikmesini gizler.

## Hocanın Özellikle Vurguladığı Kısımlar

- Tek bir sanallaştırma türü yok
  - JVM'nin sanal işlemci oluşturması ile ESX'in donanımın sanal kopyalarını oluşturması farklı kategorilerdir. İkisine de sanallaştırma denir.
- Sanal, fiziksel ve makine adresi
  - Hoca bu üç kavramın önemli olduğunu vurguladı. Fiziksel adres işletim sisteminden, makine adresi VMM'den çıkar. İkinci çeviri, her konuğa sıfırdan başlayan bir adres uzayı yanılsaması vermek içindir.
- Balonlama işletim sistemini "kandırır"
  - Sürücü gereksiz yere bellek isteyerek konuğa belleğin bittiği izlenimini verir ve sayfa çalmayı konuğun kendi algoritmasına yaptırır. Konuğun iç yapısına dokunulmaz.
  - Sürekli sayfa çıkarıp geri almak (thrashing) zaman maliyetlidir; gerek yokken balon küçültülür.
- Özetle karşılaştırma neden hızlı
  - Özet yoksa bir sayfa her sayfayla kelime kelime karşılaştırılır ve her kelime için bir karşılaştırma (if) gerekir. Özet hesaplaması XOR, toplama, OR gibi basit işlemlerden oluşan bir döngüdür ve sonunda sayfanın tamamı için tek bir karşılaştırma yapılır.
- Güvenli özet ile hızlı özet farkı
  - Güvenli özette tek bir bit değişse bile özet değişmeli, çakışma pratikte olmamalıdır; bu yüzden karmaşıklığı yüksektir. Sayfa paylaşımında çakışmaya düşük oranda izin veren hızlı bir özet yeterlidir, çünkü eşleşmeler ayrıca doğrulanır.
- Makaleyi okurken arkasındaki mekanizmayı düşünmek
  - Pratikte bilmeden yapılan işlerin (sanal makineye bellek verme, bulutta kaynak kiralama) arkasında bu mekanizmalar vardır.

## Kısa Tekrar Notları

- ESX Server: donanımı doğrudan yöneten, sanallaştırma amaçlı işletim sistemi. Workstation: hosted, var olan işletim sisteminin üzerinde.
- Sanal adres → (konuk sayfa tablosu) → fiziksel adres → (VMM) → makine adresi.
- Sanallaştırma yoksa fiziksel adres doğrudan RAM'e gider.
- Balon şişer: konuk sayfa çalar, sayfalar VMM'ye geçer. Balon söner: konuk belleği geri alır.
- Pinned page: yeri sabitlenmiş, diske çıkarılmayan sayfa.
- Şeffaf paylaşım: konukların haberi olmadan aynı sayfaların tek kopyası.
- İçerik tabanlı paylaşım: 64 bitlik hızlı özet, özet tablosu, eşleşmede tam karşılaştırma, yazmada copy-on-write.
- Sıfır sayfaları da paylaşımla geri kazanılır.
- Boşta bellek vergisi: öntanımlı %75, ceza fonksiyonu mantığı, balonlamadan daha düşük gecikme.

## Detaylı Açıklamalar

- Sanallaştırmada bellek yönetimi, işletim sisteminin zaten yaptığı işin bir üst seviyesidir. İşletim sistemi ortak belleği prosesler arasında paylaştırır. Sanallaştırmada ise her proses bir işletim sistemi gibi düşünülür ve "sanki" kaldırılır: gerçekten birer işletim sistemidirler. Bu durumda CPU, bellek ve çevre birimleri açısından her biri donanıma tek başına sahipmiş gibi görmeli ve buna inanmalıdır. Makale 2002 tarihlidir ve o tarihe kadarki deneyimlerin özetidir.
- Adres çevirisinin iki katmanı şöyle düşünülebilir. Programcının işini kolaylaştırmak için her prosesin adresleri sıfırdan başlar. İşletim sistemi de bir programdır ve gerçek bir işlemci üzerinde çalışacağını varsaydığı için belleğini sıfır adresinden başlatır. Sanallaştırılmış ortamda konuğa gerçek sıfır adresi verilemez, çünkü sistemde tek bir sıfır adresi vardır. Bu yüzden konuğun ürettiği fiziksel adres, VMM tarafından bir kez daha çevrilerek makine adresine dönüştürülür. Makalede bu eşleme PPN'den MPN'ye yapılır.
- Balonlama, konuk işletim sisteminin bellek baskısı altında zaten yapacağı şeyi tetikler. Tek başına çalışan bir işletim sistemi bellek bittiğinde ve yeni bir program başlatılacağında, proseslerin kullanmadığı sayfaları diske yazıp yer açar. Balon sürücüsü şiştikçe bellek ister, konuk boş belleğin bittiğini görür ve sayfa çalmaya başlar. Bu sırada balonun elindeki sayfalar VMM'ye geçer ve ESX bu belleği başka bir sanal makine için kullanabilir. ESX'in belleğe ihtiyacı yoksa balon küçültülür, böylece konuk gereksiz yere sayfa çıkarıp almakla vakit kaybetmez. Sürücünün tek görevi VMM ile haberleşmek ve istenen boyuta göre bellek ayırıp bırakmaktır.
- İçerik tabanlı paylaşımda yazılabilir bir sayfa paylaşıldıktan sonra konuklardan biri ona yazarsa, öteki konuklar değişikliği kabul etmemelidir, yoksa yanlış çalışırlar. Bu yüzden yazma anında yazan konuğa özel bir kopya oluşturulur (copy-on-write). Hocanın örneğinde yüz konuktan üçü sayfayı değiştirirse doksan yedisi tek kopyayı kullanmaya devam eder, üçü kendi özel kopyasını alır. Hepsi değiştiriyorsa o sayfa zaten bu yolla paylaşılamaz.
- Hoca, özet fonksiyonları arasındaki hız farkını canlandırmak için yaklaşık değerler verdi: SHA-256 günümüz işlemcilerinde saniyede yaklaşık 2000 milyon özet hesaplayabilirken bcrypt yaklaşık 45 bin özet hesaplar. Güvenli olmak için tasarlanmış yavaş bir özet yerine sayfa paylaşımında hızlı bir özet kullanılır.
- Boşta bellek vergisinde hoca bulut kiralamasına benzetme yaptı: daha çok para verip daha çok bellek ayırtan ama bunun çoğunu kullanmayan bir kullanıcı, boşta tuttuğu bellek için daha yüksek vergi öder. Bu mekanizma balonlamadan daha hızlı tepki verir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
