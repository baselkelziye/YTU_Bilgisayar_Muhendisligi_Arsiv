# Ders 6 Çalışma Özeti

## Genel Konular

- Dersin biçimi: sanallaştırma makalelerinin soru-cevapla tartışılması
  - Ders slayt anlatımı değil, önceden okunması istenen makaleler üzerinden yürütülen bir tartışmadır. Hoca her makale için sorular sorar, öğrenciler cevaplar, hoca cevapları düzeltir ve tamamlar.
  - Bu derste dört makale ele alındı: Xen (sanallaştırma sanatı), Disco (ölçeklenebilir çok işlemcilerde ticari işletim sistemleri), VMware Workstation'da G/Ç cihazlarının sanallaştırılması ve sanal makineler ile Linux konteynerlerinin performans karşılaştırması.
- Xen ve paravirtualization
  - Xen, yazıldığı dönemdeki diğer sanal makine monitörleriyle (VMM) karşılaştırılarak tanıtılan bir sanallaştırma ortamıdır.
  - Makale kendini önceki bir çalışma olan Denali ile karşılaştırır. Derste okunan farklar:
    - Denali mevcut ABI'leri (Application Binary Interface) hedeflemez; bu yüzden bazı mimari özellikleri VMM arayüzünden çıkarabilir.
    - Denali'de her sanal makine tek kullanıcılı, tek uygulamalı, korumasız bir işletim sistemi barındırır; Xen'de ise tek bir sanal makine, değiştirilmemiş binlerce kullanıcı seviyesi süreci çoğullayabilen gerçek bir işletim sistemi çalıştırır.
    - Denali'de sanallaştırma katmanındaki bellek yönetimi eksikliği yüzünden bütün sayfalama (paging) işlemlerini VMM diskten yapar; bu bir performans sorunudur.
  - Tam sanallaştırma ile paravirtualization farkı:
    - Tam (full) sanallaştırma: bir donanım yazılımla birebir taklit edilir ve işletim sistemine sunulur; işletim sistemi bir yazılımla konuştuğunu anlamaz. Maliyeti yüksektir.
    - Paravirtualization: konuk işletim sisteminden gelen G/Ç isteği basit bir çeviriden geçirilip VMM'in (ya da üzerinde çalıştığı ana işletim sisteminin) zaten sahip olduğu sürücüye aktarılır. Maliyeti daha düşüktür.
  - ABI ve ikili uyumluluk: Xen yazarlarının temel kaygılarından biri, uygulamaların derlenmiş ikili dosyalarının değiştirilmeden çalışmasıdır. Aksi hâlde kaynak kodu yeniden derlemek ya da çalıştırılabilir dosyayı çevirmek gerekir.
  - Bir işletim sistemini Xen'e taşıma (porting) maliyeti: işletim sisteminin Xen altında çalışabilmesi için yapılması gerekenlerdir; örneğin sanal aygıt sürücüleri sağlamak ya da işletim sisteminin bellek yönetimini değiştirmek.
- Disco: ölçeklenebilir çok işlemcilerde ticari işletim sistemleri
  - Ticari (commodity) işletim sistemi: ikili ve kurulabilir biçimde sunulan, satın alınabilen ya da indirilebilen, kullanıcının üzerinde değişiklik yapması gerekmeyen işletim sistemidir.
  - Sorun: ölçeklenebilir çok işlemcili donanım yazılımdan daha hızlı gelişmiştir. Mevcut işletim sistemlerini bu donanımda dağıtık hâle getirmek ciddi değişiklik gerektirir.
  - Disco'nun önerisi: işletim sistemini değiştirmek yerine donanımın üzerine bir sanal makine monitörü katmanı koymak ve üstünde birden çok (az işlemcili SMP ya da küçük) ticari işletim sistemi kopyası çalıştırmak.
  - Mimari (makalenin Şekil 1'i, sözlü anlatım): altta yerel belleği olan birçok işlem elemanı (PE), bunları bağlayan bir ara bağlantı ve NUMA bellek yapısı; ortada Disco; üstte kutular hâlinde SMP ya da küçük işletim sistemleri.
  - Sanal makine monitörü yaklaşımının sorunları: ek yük (overhead), kaynak yönetimi, sanal makineler arası iletişim ve veri paylaşımı.
  - Kaynak yönetimi sorununun örneği: VMM, konuk işletim sisteminin ne yaptığını bilmez; konuk boşta bir meşgul döngü (busy loop) çalıştırırken VMM bu komutları çalıştırmak için gerçek işlemciyi boşa harcar.
- VMware Workstation'da G/Ç cihazlarının sanallaştırılması (2001)
  - Barındırılan (hosted) mimari: ana işletim sistemi üzerinde bir uygulama gibi kurulan VMware Workstation, işlemciyi konuk işletim sistemleri arasında paylaştırır.
  - G/Ç tarafında donanımı yazılımla taklit etmek yerine, konuğa kendi kolay destekledikleri bir sürücü yüklenir ve G/Ç gerçekte ana işletim sistemindeki sürücülerle yapılır.
  - Bileşenler: VMM, ana işletim sistemindeki VMDriver ve yardımcı uygulama VMApp. Bu üçü birbirine iş aktarabilir.
  - Bir ağ paketinin gönderilmesi ve alınması yolu, bir OUT komutu ile başlar ve VMM, VMDriver, VMApp ve ana sistemin ağ sürücüsü üzerinden gerçek karta ulaşır; dönüşte kesme ters yönde konuğa sanal bir kesme olarak yansıtılır.
  - Bu yolun maliyeti mikrosaniyelerle ölçülmüştür (733 MHz işlemci).
- Sanal makineler ile Linux konteynerlerinin performans karşılaştırması
  - Katkı: yerel (native), sanal makine ve konteyner karşılaştırmasına güncel bir sürüm eklemek; Docker ile KVM'yi CPU, bellek bant genişliği ve gecikmesi, ağ ve G/Ç bant genişliği gibi ölçütlerle sınamak.
  - KVM, Xen'den farklı olarak işlemcideki donanım sanallaştırma desteğini kullanır; Xen ortaya çıktığında işlemcilerde bu destek yoktu.
  - HPC (yüksek başarımlı hesaplama) yükü de incelenmiştir (Linpack).
  - Sonuç: konteynerler hemen hemen yerel performansı verir; ayarlanmış KVM de hesaplama yoğun yüklerde çok az kayıp yaşar. Sıkıştırma (PXZ) gibi sıradan yüklerde KVM'nin kaybı daha büyüktür.

## Hocanın Özellikle Vurguladığı Kısımlar

- Tam sanallaştırma ile paravirtualization ayrımı
  - Donanımı yazılımla birebir çoğaltıp işletim sisteminden gizliyorsanız tam sanallaştırmadır; isteği çevirip var olan bir sürücüye aktarıyorsanız paravirtualization'dır. Hoca aynı tanımı tersinden soru olarak sorup ayrımın gerçekten anlaşılıp anlaşılmadığını sınadı.
- Disco makalesinin anahtar kavramı
  - Hoca makalenin özetini değil, makalenin dayandığı anahtar fikri istedi: ölçeklenebilir çok işlemcili mimaride işletim sistemini dağıtık hâle getirmek (çok ciddi değişiklik) yerine, bir sanal makine monitörüyle var olan ticari işletim sistemlerini hızlıca kullanmak.
  - Simetrik çok işlemcili (SMP) sistemler iki, dört gibi az işlemcilidir; burada ise çok daha fazla işlem elemanı söz konusudur.
- Kaynak yönetiminin anlamı
  - VMM'in, konuğun boşta beklediğini fark edememesi kaynak israfına yol açar. Bunu fark edip ona göre davranabilmek, paravirtualization'ın devreye girdiği noktalardan biridir.
- Sanallaştırma ve HPC
  - Normalde sanallaştırma HPC'nin "baş düşmanı" sayılır, çünkü araya bir katman girer. Makaledeki Linpack sonucuna göre ayarlanmış KVM'de kayıp yalnızca yaklaşık %2'dir; yani HPC için illa çıplak donanım (bare metal) gerekmez.
  - Nedeni: sanallaştırma katmanı ayrıcalıklı, bellek ve G/Ç erişimiyle ilgili komutlarda devreye girer; aritmetik, mantık ve kayan nokta işlemlerinde girmez.

## Kısa Tekrar Notları

- Tam sanallaştırma: donanımın birebir yazılım taklidi, konuk fark etmez, pahalı.
- Paravirtualization: isteği çevirip var olan sürücüye aktarma, ucuz; konuğun işbirliğine dayanır.
- Xen'in temel kaygısı: ABI uyumluluğu, yani uygulama ikili dosyalarının değiştirilmeden çalışması.
- Porting maliyeti: işletim sistemini Xen altında çalıştırmak için yapılması gereken değişiklikler (sanal sürücüler, bellek yönetimi).
- Denali'den farklar: ABI hedeflememe, tek uygulamalı konuklar, VMM'in bütün sayfalamayı kendisinin yapması.
- Commodity OS: hazır, ikili biçimde alınıp kurulan işletim sistemi.
- Disco: NUMA tabanlı ölçeklenebilir çok işlemcide, OS'yi dağıtık yapmak yerine VMM üstünde birden çok küçük OS kopyası.
- VMM sorunları: ek yük, kaynak yönetimi, iletişim ve veri paylaşımı.
- VMware hosted G/Ç: VMM + VMDriver + VMApp; G/Ç gerçekte ana sistemde yapılır, sonuç VMM üzerinden konuğa yansıtılır.
- x86'da IN/OUT ayrıcalıklı komutlardır; konuk OUT çalıştırınca VMM'e tuzak (trap) olur.
- KVM işlemcinin donanım sanallaştırma desteğini kullanır; Xen'in ilk sürümlerinde bu destek yoktu.
- Linpack: Docker yerel ile aynı, ayarlanmış KVM yaklaşık %2 kayıp; PXZ sıkıştırmada KVM kaybı belirgin.

## Detaylı Açıklamalar

- **Xen ve Denali.** Xen makalesi, kendinden önceki Denali çalışmasından farklarını maddeler hâlinde verir. Denali, mevcut uygulama ikili arayüzlerini (ABI) desteklemeyi hedeflemediği için VMM arayüzünden bazı mimari özellikleri çıkarabilir. Denali'deki her sanal makine tek kullanıcılı, tek uygulamalı ve korumasız bir işletim sistemi çalıştırırken, Xen'de bir sanal makine binlerce değiştirilmemiş kullanıcı süreci çalıştıran tam bir işletim sistemini barındırabilir. Ayrıca Denali'de sanallaştırma katmanının bellek yönetimindeki eksikler yüzünden bütün sayfalama işlemleri VMM tarafından diskten yapılır; derste dile getirilen "performans farkı"nın asıl noktası budur.

- **Tam sanallaştırma ve paravirtualization.** Hoca bir G/Ç cihazı örneği verdi: cihazın bütün donanımsal özellikleri yazılımla üst katmana yansıtılır ve üst katman bir yazılımla muhatap olduğunu bilmez. Bu tam sanallaştırmadır ve işletim sisteminin bunu fark etmemesi için her türlü tedbirin alınması gerektiğinden maliyeti yüksektir. Öte yandan konuk işletim sisteminden gelen G/Ç isteği alınıp basit bir çeviriden geçirilerek VMM'in ya da ana işletim sisteminin zaten sahip olduğu aygıt sürücüsüne aktarılıyorsa bu paravirtualization'dır. Burada bir istek, aynı kategoride benzer özellikler taşıyan başka bir isteğe dönüştürülür ve iş daha ucuza yürür.

- **ABI ve taşıma maliyeti.** ABI, derlenmiş çalıştırılabilir dosyanın işletim sistemi ve donanımla kurduğu ikili arayüzdür; yalnız DLL'lerle sınırlı değildir. Xen yazarları ikili uyumluluğu korumayı temel hedef olarak almıştır; aksi hâlde kaynak kodun yeniden derlenmesi ya da çalıştırılabilir dosyanın çevrilmesi gerekir. Uygulamalar değişmezken işletim sisteminin kendisi Xen'e taşınırken değiştirilir: sanal aygıt sürücüleri sağlanması ve bellek yönetiminin değiştirilmesi bu taşıma maliyetinin örnekleridir.

- **Disco.** Ölçeklenebilir çok işlemcili makinelerde donanım yazılımdan önde gider; uygun sistem yazılımı geç gelir ve donanımdan yeterince yararlanılamaz. İşletim sistemlerini bu mimaride dağıtık hâle getirmek ciddi değişiklik ister. Disco yazarları bunun yerine donanımın üzerine bir sanal makine monitörü koyar. Makalenin mimari şeklinde altta yerel belleği olan çok sayıda işlem elemanı ve onları bağlayan ara bağlantı (NUMA), ortada Disco, üstte birden çok SMP ya da küçük işletim sistemi bulunur. Derste bir öğrenci makalede konuk işletim sistemi olarak IRIX'in kullanıldığını söyledi. Bu yaklaşım ölçeklenebilir donanımı hızlıca kullanmayı sağlar, ama ek yük, kaynak yönetimi, iletişim ve veri paylaşımı sorunlarını getirir. Kaynak yönetimi sorununda VMM, arka arkaya gelen komutların konuktaki boş bir meşgul döngüye karşılık geldiğini bilemez ve gerçek işlemciyi boşuna harcar.
  <!-- BELİRSİZ: Hocanın "Disco bellek yönetiminde NUMA'yı nasıl ele alıyor" sorusuna beklediği cevap altyazıda anlaşılmıyor (00:33:00-00:35:30). -->

- **VMware hosted G/Ç yolu.** Konuk işletim sistemi bir G/Ç portuna OUT komutuyla eriştiğinde, OUT ayrıcalıklı bir komut olduğu için VMM'e yakalanır. VMM isteği ana sistemdeki VMDriver'a, o da yardımcı uygulama VMApp'e aktarır; VMApp isteği ana sistemin ilgili sürücüsüne (örnekte Ethernet) yönlendirir ve gerçek kartta işlem yapılır. Dönüşte kartın kesmesi ana sistemdeki Ethernet sürücüsünü, o VMNet sürücüsünü, o da VMApp'i tetikler; VMApp veriyi tampondan belleğe alır ve VMM'e iletir, VMM konukta bir kesme üretir. Konuk bunu kendi IN/OUT komutunun sonucunda oluşmuş bir kesme sanır. Hocanın aktardığı ölçüme göre (733 MHz işlemcide) bir OUT komutunun bu yoldan geçmesi yaklaşık 31,63 mikrosaniye sürmektedir; bunun 4,45 mikrosaniyesi bağlam değiştirmeye, 17,55 mikrosaniyesi VMNet sürücüsüne gider. <!-- BELİRSİZ: Sayılar altyazıdan alındı; ekranda makale gösterilmediği için karelerden doğrulanamadı. -->

- **Konteyner ve KVM karşılaştırması.** Makale Docker ile KVM'yi yerel çalışmayla karşılaştırır. Linpack (HPC) sonuçlarına göre yerel ile Docker hemen hemen aynıdır, ayarlanmamış KVM belirgin biçimde geride, ayarlanmış KVM ise yaklaşık %2 geridedir. PXZ sıkıştırma yükünde (1 GB'lık Wikipedia dökümü, 32 iş parçacığı) KVM yaklaşık %22, Docker yaklaşık %4 daha düşük performans verir. Rastgele erişim ve STREAM (add, copy, scale, triad) vektör işlemlerinde fark yok denecek kadar azdır. Sanallaştırma katmanı yalnız ayrıcalıklı, bellek ve G/Ç ile ilgili komutlarda devreye girdiği için saf hesaplama yükleri az etkilenir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
