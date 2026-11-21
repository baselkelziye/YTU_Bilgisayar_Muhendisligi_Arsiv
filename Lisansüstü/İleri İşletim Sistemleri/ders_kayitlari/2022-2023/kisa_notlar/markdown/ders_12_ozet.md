# Ders 12 Çalışma Özeti

## Genel Konular

- Bu haftanın makale tartışması: Xen ve paravirtualization (para-sanallaştırma)
  - Ders kısa bir kayıttır ve ekranda slayt ya da makale paylaşılmamıştır. İçerik sözlü tartışmadan alınmıştır.
  - Tartışma, bir önceki makalede görülen VMware ESX Server'ın tam sanallaştırma (full virtualization) yaklaşımıyla karşılaştırma üzerinden yürütüldü.
- Tam sanallaştırmanın iki sıkıntısı
  - ESX Server'da üç katmanlı adres yapısı vardır: sanal adres, misafir işletim sisteminin gördüğü "fiziksel" adres ve gerçek RAM adresi olan makine adresi (machine address).
  - ESX, misafirin sayfa tablosuna yaptığı her yazmayı yakalar (intercept) ve sanal adresten doğrudan makine adresine giden gölge sayfa tabloları (shadow page tables) tutar. Her sayfa tablosu yazmasını yakalamak zaman alır.
  - Süper sayfalar (super pages) fiziksel olarak bitişik yer ister. Bellek yerleşimini ESX yönettiği için, tam sanallaştırmada misafirin süper sayfalarının makine belleğinde bitişik düşmesi zordur.
- Paravirtualization fikri
  - Misafir işletim sistemi (guest OS) bir sanallaştırma katmanının üzerinde çalıştığının farkındadır ve bunun için kaynak kodu değiştirilir.
  - ESX'te misafir, belleği sıfır adresinden başlıyormuş gibi görür ve hiçbir şeyin farkında olmaz. Xen'de ise misafir değiştirilmiştir ve artık ring 0'da çalışmaz.
  - Misafirin Xen'e ayrıcalıklı istekleri hypercall'larla yapılır. Bu, kullanıcı alanından çekirdeğe sistem çağrısıyla (system call) geçişe benzer.
- Uygulama İkili Arayüzüne (ABI) dokunulmaması
  - Xen, misafir çekirdeği değiştirir ama ABI'yi değiştirmez. Bu yüzden misafirin üzerindeki kullanıcı uygulamaları değişmeden çalışır.
  - Sunan öğrencinin yorumuyla ABI; çağırma kuralları (parametrenin register'la mı yığınla mı geçeceği, hangi register'ları çağıranın, hangilerini çağrılanın koruyacağı) ve bellek yerleşimi gibi kuralları tanımlar. Bir tarafı derleyiciye, bir tarafı işletim sistemine bakar.
- Sanallaştırılan üç alt sistem: CPU, bellek ve G/Ç aygıtları
  - Bellek: x86'da TLB donanımla yönetilir, yazılımla doldurulamaz. Girdilerinde adres alanı etiketi (address space identifier tag) olan TLB'lerde adres alanları ayrılabilir. Bu etiket yoksa adres alanı geçişlerinde TLB boşaltılmak (flush) zorundadır.
  - CPU: Xen en ayrıcalıklı halkada (ring 0) çalışır. Intel'de 4 halka vardır; Linux normalde 0 ve 3'ü kullanır, bu yüzden misafir çekirdek boştaki ara halkalardan birine yerleşebilir. Yalnız iki ayrıcalık düzeyi olan mimarilerde misafir çekirdek ile kullanıcı uygulamaları aynı düzeyde olur ve ayrı adres alanlarıyla birbirinden ayrılır.
  - Kesme tablosu: ring 0'da olmayan misafir çekirdek kesme tablosunu kendisi kuramaz. Bunu Xen'e hypercall ile yaptırır.
  - Sistem çağrısı (yazılım kesmesi) önce kesme tablosuna adresini koyan Xen'e gelir, Xen bunu üstteki misafir işletim sistemine iletir. Öğrenci bunu thread makalesinde çekirdeğin olayları kullanıcı alanındaki thread kütüphanesine iletmesine benzetti.
- Kontrol ve yönetim (control and management)
  - Yönetim işlevleri (alan oluşturma, çalıştırma, ekleme) Xen'in çekirdeğinden çıkarılmış, kullanıcı arayüzlü bir kontrol paneli olarak ayrı bir misafir işletim sisteminde çalıştırılmıştır.
- Değiştirilen kod miktarı (makaledeki Tablo 2, hocanın sözlü aktarımı)
  - Mimariye bağlı değişiklik Linux'ta 78 satır, Windows XP'de 1299 satır.
  - Linux'a ayrıca sanal ağ sürücüsü (virtual network driver) ve sanal blok aygıt sürücüsü (virtual block device driver) eklenmiş, sürücüler dışında Xen'e özgü değişiklikler yapılmıştır.
- Disco makalesine giriş
  - Makalenin başlığı derste okundu: "Running Commodity Operating Systems on Scalable Multiprocessors".
  - Amaç: herkesin erişebildiği hazır (commodity) işletim sistemlerini ölçeklenebilir çok işlemcili makinelerde çalıştırmak. Disco bir sanal makine izleyicisidir (Virtual Machine Monitor).

## Hocanın Özellikle Vurguladığı Kısımlar

- ESX ile Xen arasındaki temel fark
  - Tam sanallaştırmada fiziksel makinenin işlemcisi, belleği ve çevre birimlerinin birebir bir kopyası yazılımda oluşturulup işletim sistemine sunulur.
  - Paravirtualization'da işletim sistemi değiştirilir ve sanallaştırma yazılımın yardımıyla daha kolay ve daha verimli hale gelir. Ek yük (overhead) azalır, performans artar.
  - Farka yalnız bellek açısından bakılmamalıdır. İşlemci ve çevre birimleri de dahil her açıdan bakılmalıdır.
- Kod değişikliğinin küçüklüğü
  - Tablo 2'deki satır sayıları, işletim sistemine yapılan müdahalenin az olduğunu ve karşılığında performans kazanıldığını gösterir.
- Xen makalesinin önemi
  - Xen, paravirtualization'ın günümüz işletim sistemlerine etkin biçimde uygulandığı ortamlardan biridir.
- Disco'nun önemi
  - Hoca Disco'nun "hakikaten önemli" olduğunu söyledi. Ölçeklenebilirlik, mesajlaşma, performans ve sanallaştırma bu makalede bir araya gelir.
- Makale anlatım üslubu
  - Hoca, sunumun makaleye bağlı kalmasını, makalede olmayan kişisel yorumların araya karıştırılmamasını istedi.

## Kısa Tekrar Notları

- Tam sanallaştırma (ESX): misafir değiştirilmez, farkında değildir. Gölge sayfa tabloları ve sayfa tablosu yazmalarının yakalanması gerekir.
- Paravirtualization (Xen): misafir çekirdek değiştirilir ve farkındadır. Ayrıcalıklı işler hypercall'la yapılır.
- ABI değişmez, kullanıcı uygulamaları değişmeden çalışır.
- Sanallaştırılan alt sistemler: CPU, bellek, G/Ç.
- Xen ring 0'da, misafir çekirdek daha az ayrıcalıklı bir halkada çalışır. Kesme tablosu Xen üzerinden kurulur.
- Etiketsiz TLB'de adres alanı geçişi TLB boşaltmayı gerektirir.
- Yönetim, kullanıcı arayüzlü ayrı bir misafir alana çıkarılmıştır.
- Linux'ta mimariye bağlı değişiklik 78 satır, Windows XP'de 1299 satır.
- Disco: commodity işletim sistemlerini ölçeklenebilir çok işlemcilerde çalıştıran bir VMM.

## Detaylı Açıklamalar

Bu dersin tamamı, öğrencilerin önceden okuduğu Xen makalesinin tartışmasına ayrıldı. Sunan öğrenci önce bir önceki makaledeki VMware ESX Server'ı hatırlattı. ESX, misafirin gördüğü fiziksel adresleri gerçek RAM'deki makine adreslerine eşlemek için sayfa tablolarını kullanır. Misafirin sayfa tablosuna yaptığı her yazmayı yakalar ve sanal adresten doğrudan makine adresine giden gölge sayfa tabloları tutar. Xen makalesi bunu bir sıkıntı olarak görür, çünkü her sayfa tablosu yazmasını yakalamak zaman alır. İkinci sıkıntı süper sayfalardır. Süper sayfa fiziksel olarak bitişik bir alan gerektirir. Tam sanallaştırmada makine belleğinin yerleşimini sanallaştırma katmanı belirlediği için, misafirin süper sayfa olarak düşündüğü sayfaların gerçekte bitişik düşmesi zorlaşır.

Paravirtualization'da misafir işletim sistemi bir sanallaştırma katmanının üzerinde çalıştığını bilir. Bunu sağlamak için misafirin kaynak kodu değiştirilir. ESX'te misafir belleğin sıfır adresinden başladığını sanır ve hiçbir şeyin farkında olmaz. Xen'de ise misafir çekirdek artık ring 0'da çalışmaz. Ring 0'da Xen oturur. Misafir, ayrıcalık gerektiren bir işi Xen'den hypercall ile ister. Bu mekanizma, kullanıcı alanındaki bir programın sistem çağrısıyla çekirdeğe geçmesine benzer. Makalede hypercall arayüzü ve misafir işletim sistemlerinin bu arayüze nasıl taşındığı (port edildiği) anlatılır. Çekirdek değişse de ABI'ye dokunulmamıştır. Böylece uygulamaların ve derleyicinin ürettiği kodun değişmesi gerekmez.

Bellek tarafında TLB konusu öne çıkar. x86'da TLB tamamen donanımla yönetilir ve yazılımla güncellenemez. Her adres alanının kendi çevirileri vardır. Bu yüzden adres alanları arasında geçerken TLB ya yazılımla denetlenmeli ya da tamamen boşaltılmalıdır. Bazı TLB'ler girdilerine hangi adres alanına ait olduklarını gösteren bir etiket koyabilir. Bu etiket varsa adres alanları birbirinden ayrılabilir, yoksa geçişlerde TLB boşaltmak zorunludur.

İşlemci tarafında Xen en ayrıcalıklı halkada çalışır. Yalnız iki ayrıcalık düzeyi olan mimarilerde birini Xen alır, misafir çekirdek ile kullanıcı uygulamaları ise aynı düzeyi paylaşır ve ayrı adres alanlarıyla birbirinden ayrılır. Intel'de dört halka olduğu için böyle bir sıkıntı yoktur. Linux normalde 0 ve 3'ü kullanır, Xen 0'a oturunca misafir çekirdek ara halkalardan birine yerleşebilir. Öğrenci açılış (boot) sürecine de değindi. İşlemci açılışta korumalı moda geçmeden çalışır ve işletim sistemi kesme tablosunu kendisi kurar. Misafir ring 0'da olmadığında bunu doğrudan yapamaz, kesme tablosunu Xen'in sunduğu hypercall arayüzüyle kurar. Bir kullanıcı programı sistem çağrısı yaptığında yazılım kesmesi oluşur. Bu kesme, kesme tablosuna adresini koyan Xen'e gider. Xen de kesmeyi üstteki misafir işletim sistemine iletir. Öğrenci bunu thread makalesindeki, çekirdeğin olayları kullanıcı alanındaki thread kütüphanesine iletmesine benzetti. Yönetim işlevleri de Xen çekirdeğinden çıkarılmış ve kullanıcı arayüzlü ayrı bir misafir işletim sistemine konmuştur.

Hoca farkı şöyle bağladı: tam sanallaştırmada fiziksel makinenin işlemcisi, belleği ve çevre birimlerinin birebir kopyası yazılımda oluşturulur. Paravirtualization'da işletim sistemi az miktarda değiştirilir ve sanallaştırma kolaylaşır. Makalenin Tablo 2'sine göre mimariye bağlı değişiklik Linux'ta 78 satır, Windows XP'de 1299 satırdır. Linux'a ayrıca sanal ağ ve sanal blok aygıt sürücüleri eklenmiştir. Hoca bu iki yaklaşımı "mavi hap" ve "kırmızı hap" benzetmesiyle de anlattı: bir tarafta misafir altta ne olduğunun farkında değildir, öbür tarafta Xen'deki gibi farkındadır. <!-- BELİRSİZ: Altyazıda hangi hapın hangi yaklaşıma karşılık geldiği kendi içinde çelişiyor; burada yalnız Xen'in "farkında olan" taraf olduğu net. -->

Dersin sonunda bir sonraki makale olan Disco'ya kısaca girildi. Başlığı "Running Commodity Operating Systems on Scalable Multiprocessors"dır. Amacı, o dönemde herkesin erişebildiği hazır işletim sistemlerini ölçeklenebilir çok işlemcili makinelerde çalıştırmaktır. Hocaya göre bu makalede ölçeklenebilirlik, mesajlaşma, performans ve sanallaştırma bir aradadır. Disco, işletim sistemi gibi görünse de aslında sanallaştırma ortamı sunan bir sanal makine izleyicisidir (VMM).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
