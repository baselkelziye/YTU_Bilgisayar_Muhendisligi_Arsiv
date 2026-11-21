# Ders 12 Genişletilmiş Notu: Xen ve Paravirtualization; Disco'ya Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Biçimi ve Tartışılan Makale
- 2. Tam Sanallaştırmanın Sıkıntıları: ESX Server'dan Hatırlatma
- 3. Paravirtualization Fikri ve Hypercall'lar
- 4. ABI'ye Dokunmamak
- 5. Bellek Sanallaştırması ve TLB
- 6. CPU Sanallaştırması: Halkalar, Kesme Tablosu ve Sistem Çağrıları
- 7. Kontrol ve Yönetim
- 8. ESX ile Xen'in Temel Farkı ve Tablo 2
- 9. Disco'ya Giriş
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Biçimi ve Tartışılan Makale

Bu ders de önceki haftalar gibi, öğrencilerin önceden okuduğu makalelerin soru-cevap biçiminde tartışılmasıyla geçti. Kayıt kısadır, yaklaşık yirmi dakikalık bir tartışmadır. Ekranda slayt ya da makale paylaşılmadı. Aşağıdaki bütün bilgiler sözlü anlatımdan alınmıştır, yazılı bir kaynaktan doğrulanmamıştır. Bu haftanın ana makalesi Xen'di. Tartışmayı önce bir öğrenci makaleyi özetleyerek başlattı, sonra hoca ESX ile Xen arasındaki temel farkı sorup kendisi bağladı. Dersin sonunda bir sonraki makale olan Disco'ya kısaca girildi.

> **Ek bilgi (derste anlatılmadı):** Derste makalenin tam adı ve yazarları söylenmedi. Tartışılan makale büyük olasılıkla P. Barham ve arkadaşlarının 2003'te SOSP'ta yayımlanan "Xen and the Art of Virtualization" makalesidir. Karşılaştırma için anılan önceki makale büyük olasılıkla C. A. Waldspurger'ın 2002 tarihli "Memory Resource Management in VMware ESX Server" makalesi, sonraki makale ise büyük olasılıkla E. Bugnion, S. Devine ve M. Rosenblum'un 1997'de SOSP'ta yayımlanan "Disco: Running Commodity Operating Systems on Scalable Multiprocessors" makalesidir.

## 2. Tam Sanallaştırmanın Sıkıntıları: ESX Server'dan Hatırlatma

Sunan öğrenci, Xen'in neyi farklı yaptığını anlamak için önce bir önceki makaledeki VMware ESX Server'ı hatırlattı. ESX tam sanallaştırma (full virtualization) yapar. Bu yapıda üç tür adres vardır:

- Sanal adres: misafir işletim sisteminin (guest OS) süreçlerinin kullandığı adres.
- Fiziksel adres: misafirin kendi belleği sandığı, sıfırdan başlayan adres.
- Makine adresi (machine address): gerçek RAM'deki adres.

ESX bu soyutlamayı sayfa tablolarıyla sağlar. Misafir kendi sayfa tablosunu değiştirdiğinde ESX'in de buna karışması gerekir. Bu yüzden ESX, misafirin sayfa tablosuna yaptığı her yazmayı yakalar (intercept). Ayrıca sanal adresten doğrudan makine adresine giden gölge sayfa tabloları (shadow page tables) tutar. Xen makalesine göre bunun ilk sıkıntısı maliyettir: her sayfa tablosu yazmasını yakalamak zaman alır.

İkinci sıkıntı süper sayfalardır (super pages). Öğrenci, süper sayfa makalesinden hatırladığı bir kısıtı vurguladı: süper sayfayı oluşturan sayfaların fiziksel olarak bitişik olması gerekir. O makalede işletim sistemi sayfaların büyüdüğünü görünce onları fiziksel olarak tek bir yerde süper sayfa haline getiriyordu ve bunun için iki farklı yöntem vardı (biri yer değiştirmeye, relocation'a dayalıydı). Tam sanallaştırmada ise misafirin "fiziksel" sandığı belleğin gerçek makine belleğindeki yerleşimini ESX belirler. Bu yüzden misafirin süper sayfa olarak birleştirdiği sayfaların makine belleğinde de bitişik düşmesi zordur.

## 3. Paravirtualization Fikri ve Hypercall'lar

Xen bu sıkıntılara paravirtualization (para-sanallaştırma) ile çözüm getirir. Öğrenci "para" önekini "yanında, birlikte" anlamında yorumladı: misafir işletim sistemi, sanallaştırma katmanıyla birlikte, onun üzerinde çalıştığının farkında olarak çalışır.

ESX'te durum böyle değildir. Misafir belleğin sıfır adresinden başlamasını bekler. ESX bunu sağladığında misafir hiçbir şeyin farkında olmaz. Xen'de ise misafir işletim sisteminin kaynak kodu değiştirilir. Değiştirilen misafir çekirdek artık ring 0'da bile çalışmaz. Ring 0'da Xen oturur, misafir daha az ayrıcalıklı bir halkaya iner.

Misafirin ayrıcalık gerektiren işleri yapabilmesi için Xen'de bir hypercall arayüzü yazılmıştır. Hypercall, misafir çekirdekten Xen'e yapılan bir çağrıdır. Öğrencinin benzetmesiyle bu, kullanıcı alanından (user space) çekirdek alanına (kernel space) sistem çağrılarıyla geçmemize benzer. Xen'de hem bu arayüz yazılmış hem de işletim sistemleri bu arayüzle haberleşecek şekilde değiştirilmiştir. Makalede işletim sisteminin Xen'e nasıl taşındığı (port edildiği) da anlatılır.

## 4. ABI'ye Dokunmamak

Makale, misafir çekirdeği değiştirirken Uygulama İkili Arayüzüne (ABI, Application Binary Interface) karışmadıklarını söyler. Öğrenci ABI'yi kendi okuduklarından yola çıkarak açıkladı. Bu kısım öğrencinin makale dışı yorumudur; hoca da bir süre sonra sunumun makaleye daha bağlı kalmasını istedi (bkz. Bölüm 6 sonu).

Öğrenci, assembly ile program yazarken karşılaşılan durumları örnek verdi. Fonksiyon çağrısında bazen base pointer gibi değerleri çağıran (caller) saklar, bazen çağrılan (callee) saklar. Parametreler bazen register üzerinden, bazen yığın (stack) üzerinden geçirilir. Verinin nasıl yerleştirileceği de belirlenmelidir. Kısacası her mimarinin bir kuralı vardır ve ABI bu kuralları tanımlar:

- Hangi register'ları çağıranın, hangilerini çağrılanın bozmaması gerektiği.
- Parametrelerin ve dönüş değerlerinin nasıl geçirileceği.
- Bellek yerleşimi (memory layout).

Öğrenciye göre ABI'nin bir tarafı derleyiciye, bir tarafı işletim sistemine bakar. Derleyici makine kodu üretir ve bu kod ABI'ye uymak zorundadır. ABI değişseydi derleyicilerin ve onların ürettiği uygulamaların da değişmesi gerekirdi. Xen'in ABI'yi korumaya özen göstermesi bu yüzden önemlidir: misafir çekirdek değişse bile üzerindeki kullanıcı uygulamaları değişmeden çalışır.

## 5. Bellek Sanallaştırması ve TLB

Öğrenciye göre makale sanallaştırmayı üç alt sistemde ele alır: CPU, bellek ve G/Ç aygıtları (I/O devices).

Bellek kısmında TLB öne çıkar. Öğrenci, süper sayfa makalesinden TLB'nin bütün girdilerine tek bir işlemci çevriminde bakabildiğini, yani aranan sayfa için gerçek çerçeve numarasının orada olup olmadığını tek seferde bulduğunu hatırlattı.

Makale, Intel mimarisinde TLB'nin yazılımla doldurulamadığını ve değiştirilemediğini anlatır. TLB tamamen donanımla yönetilir; öğrencinin yorumuyla TLB'yi güncelleyecek bir komut kümesi yoktur. Bunun sanallaştırmada önemi şudur: her adres alanının (address space) kendi çevirileri vardır. Adres alanları arasında geçiş yapıldığında TLB ya yazılımla denetlenip değiştirilmeli ya da tamamen boşaltılmalıdır (flush).

Bazı TLB'ler girdilerine bir de etiket koyabilir: bu girdinin hangi adres alanına ait olduğunu gösteren adres alanı tanımlayıcısı (address space identifier tag). Böyle bir etiket varsa farklı adres alanlarının girdileri TLB'de yan yana durabilir. Yoksa adres alanı geçişlerinde TLB'yi boşaltmak zorunludur.

> **Ek bilgi (derste anlatılmadı):** Makalede bu sorun için büyük olasılıkla şu çözüm anlatılır: x86'da etiketli TLB olmadığı için Xen kendini her adres alanının en üstündeki küçük bir bölgeye (64 MB) yerleştirir; böylece misafirden Xen'e geçişte TLB boşaltılmaz. Misafir sayfa tablolarını doğrudan okuyabilir, ama güncellemeleri Xen'e hypercall ile gönderir; Xen bunları doğrular ve toplu (batch) olarak uygular. Bu, ESX'teki gölge sayfa tablolarından farklı bir yaklaşımdır.

## 6. CPU Sanallaştırması: Halkalar, Kesme Tablosu ve Sistem Çağrıları

### 6.1 Ayrıcalık halkaları

Xen en ayrıcalıklı halkada, ring 0'da çalışır. Normalde işletim sisteminin çekirdek alanı ring 0'dadır, ama Xen varken çekirdek orada olamaz. Öğrenci iki durumu ayırdı:

- Mimari yalnız iki ayrıcalık düzeyi destekliyorsa birini Xen alır. Misafir çekirdek ile kullanıcı uygulamaları aynı düzeyi paylaşır. Makaleye göre bu durumda misafir çekirdek farklı bir adres alanı kullanarak kendini kullanıcı alanından ayırabilir.
- Intel'de dört halka vardır, bu yüzden böyle bir sıkıntı yoktur. Linux normalde yalnız 0 ve 3'ü kullanır. Xen 0'a oturur, misafir çekirdek ara halkalardan (1 ya da 2) birine yerleşebilir.

> **Ders sonrası not:** Öğrenci misafir çekirdeğin 1 ya da 2'den "hangisini isterse" oraya yerleşebileceğini söyledi. Makalede x86 için büyük olasılıkla misafir çekirdeğin ring 1'de, uygulamaların ring 3'te çalıştığı belirtilir.

### 6.2 Açılış ve kesme tablosu

Öğrenci açılış (boot) sürecinden bir gözlem aktardı. İşlemci açıldığında belli bir adresten komut okumaya başlar, BIOS çipindeki kod yüklenir, sonra denetim önyükleyiciye ve işletim sistemine geçer. Bu noktada işletim sistemi gerçek moddadır (real mode). Henüz korumalı moda (protected mode) geçilmemiştir, çekirdek alanı ve sanal bellek kavramları yoktur. İşletim sistemi bu sırada kesme tablosunu (interrupt table) kendisi kurar.

Xen varken bu mümkün değildir. Xen ring 0'da, misafir çekirdek ring 1'de çalışıyorsa misafir kesme tablosunu kendisi ayarlayamaz, çünkü bulunduğu halka buna izin vermez. Bu iş de hypercall'larla yapılır: Xen bunun için bir API sunar ve misafir kesme tablosunu bu API üzerinden değiştirir.

### 6.3 Sistem çağrılarının misafire iletilmesi

Bir misafir işletim sisteminin üzerinde bir kullanıcı programı çalıştığını düşünelim. Program sistem çağrısı yaptığında bir yazılım kesmesi (software interrupt) oluşur. Kesme tablosunda bu kesmenin karşılığını kim koyduysa denetim ona geçer, yani Xen'e. Oysa bu çağrının bir üstteki misafir işletim sistemine ulaşması gerekir. Xen'de çağrıyı misafire çıkaran bir mekanizma vardır.

Öğrenci bunu daha önce tartışılan thread makalesine benzetti. O makalede çekirdek, sanal işlemcilere ilişkin olayları ve kesmeleri kullanıcı alanındaki thread kütüphanesine iletiyordu; işi kullanıcı alanı hallediyordu. Öğrenci, hocanın o derste "paravirtualization buradan başlıyor" dediğini de hatırlattı. Xen'de de benzer biçimde olay bir üst katmana, misafir işletim sistemine çıkarılır.

> **Ek bilgi (derste anlatılmadı):** Makalede büyük olasılıkla, misafirin kesme ve istisna işleyicilerini bir tablo olarak Xen'e kaydettiği anlatılır. Sistem çağrıları için ayrıca "hızlı işleyici" (fast handler) yolu vardır: Xen bu işleyiciyi doğruladıktan sonra sistem çağrıları her seferinde Xen'den geçmeden doğrudan misafirin ring 1'deki işleyicisine gider. Sayfa hatası gibi diğer istisnalar ise Xen üzerinden iletilir. Derste anılan thread makalesi büyük olasılıkla Anderson ve arkadaşlarının "Scheduler Activations" makalesidir.

## 7. Kontrol ve Yönetim

Makalenin bir diğer konusu kontrol ve yönetimdir (control and management). Xen'de yönetim işlevleri (bir alanı oluşturma, çalıştırma, yeni bir şey ekleme gibi) Xen'in kendi çekirdeğinden çıkarılmıştır. Bu işlevler, kullanıcı arayüzlü bir kontrol paneli olarak ayrı bir misafir işletim sisteminde çalışır. Böylece Xen'in çekirdeği küçük kalır, yönetim ise sıradan bir misafir alanın içinde yürütülür.

Bu noktada hoca araya girdi. Sunumun önemli konulara değindiğini, ama makaleye daha bağlı anlatılmasını tercih edeceğini söyledi. Makalede olmayan kişisel yorumların ve "şu şöyleydi, bu böyleydi" türünden aktarmaların araya karıştırılmamasını istedi. Ardından başka yorum yapmak isteyen olup olmadığını sordu.

## 8. ESX ile Xen'in Temel Farkı ve Tablo 2

### 8.1 Öğrencilerin yorumları

Başka bir öğrenci, bu makalenin önceki sanallaştırma çalışmalarından farkının, tanımladığı paravirtualization yöntemini gerçekten gerçekleştirmiş olması olduğunu söyledi. Hoca buna yöntemin hem gerçekleştirildiğini hem de değerlendirmesinin yapıldığını ekledi. Öğrenci şunu da ekledi: Xen işletim sistemlerine müdahale eder ve ek kod getirir, ama bunun sayesinde diğer yaklaşımların eksik kaldığı yerleri giderir.

**Soru (hocadan):** Şu ana kadar gördüğümüz ESX'teki sanallaştırma mantığına göre burada uygulanan sanallaştırma mantığının temel farkı nedir?

**Cevap (öğrenci):** ESX Server'da misafir işletim sistemi bir sanallaştırma yazılımının üzerinde çalıştığının farkında değildi; belleği tamamen kendi belleği sanıyordu. Xen'de ise farkındadır ve değiştirilmiştir; içinde Xen ile haberleşmeyi sağlayacak kodlar vardır.

### 8.2 Hocanın bağlaması

Hoca farka yalnız bellek açısından bakılmaması gerektiğini, her açıdan bakılması gerektiğini söyledi. İki yaklaşımı şöyle karşılaştırdı:

- Tam sanallaştırma (ESX): fiziksel makinenin işlemcisinin, belleğinin ve çevre birimlerinin birebir bir kopyası yazılımda oluşturulur ve işletim sistemine sunulur. İşletim sistemi değiştirilmez.
- Paravirtualization (Xen): işletim sisteminin yardımı alınarak sanallaştırma daha kolay ve daha verimli hale getirilir. Bunun sayesinde performans kazanılır.

Hoca bunu makaledeki Tablo 2 ile örnekledi. Tablo, Intel x86 mimarisi için Linux'ta ve makalenin yazıldığı dönemdeki Windows XP'de yapılan değişiklikleri kod satırı cinsinden verir. Hocanın sözlü aktarımına göre:

| Değişiklik | Linux | Windows XP |
|---|---|---|
| Mimariye bağlı değişiklik (satır) | 78 | 1299 |

Linux'a ayrıca bir sanal ağ sürücüsü (virtual network driver) ve bir sanal blok aygıt sürücüsü (virtual block device driver) eklenir. Sürücüler dışında da Xen'e özgü değişiklikler yapılır. Bu değişiklikler sayesinde işletim sistemi sanal bir platformda çalıştığının farkındadır, ama daha performanslı ve daha uyumlu çalışır. Sanallaştırma için harcanan emek ve ek yük (overhead) azalır, performans artar.

> **Ek bilgi (derste anlatılmadı):** Makaledeki Tablo 2'nin tamamı büyük olasılıkla şöyledir: Linux için mimariden bağımsız 78, sanal ağ sürücüsü 484, sanal blok aygıt sürücüsü 1070, Xen'e özgü (sürücü dışı) 1363 satır, toplam 2995 satır (x86 kod tabanının yaklaşık %1,36'sı). Windows XP için 1299 ve 3321 satır, toplam 4620 satır (yaklaşık %0,04). Hocanın aktardığı 78 ve 1299 değerleri bu tablonun ilk satırıyla uyumludur; toplamlar python ile doğrulandı. Tabloda XP'nin bu satırı "mimariden bağımsız" olarak geçer.

### 8.3 Mavi hap ve kırmızı hap benzetmesi

Hoca iki yaklaşımı Matrix'teki "mavi hap" ve "kırmızı hap" benzetmesiyle de anlattı. Bir yaklaşımda misafir, altında ne olduğundan tamamen bağımsız ve farkında olmadan çalışır. Öbüründe ise Xen'deki gibi olayın farkındadır. <!-- BELİRSİZ: Altyazıda hangi hapın hangi yaklaşıma karşılık geldiği kendi içinde çelişiyor ("red pill'de farkında olmadan" ve "red pill'de farkındasın" birlikte geçiyor). Filmdeki anlama göre kırmızı hap "farkına varmak" olduğundan, Xen büyük olasılıkla kırmızı hap tarafıdır. -->

> **Hocanın vurgusu:** Xen makalesi, paravirtualization'ın günümüz işletim sistemlerine etkin biçimde uygulandığı ve sanallaştırmanın sağlandığı ortamlardan birini anlattığı için önemlidir. Bir tarafta işlemcisiyle, belleğiyle ve çevre birimleriyle makineyi birebir taklit eden (emüle eden) bir yazılım yapısı, diğer tarafta yazılımdan yardım alarak sanallaştırmayı daha kolay ve daha verimli yapan bir yapı vardır.

## 9. Disco'ya Giriş

Hoca sonraki makale olan Disco'ya bakılıp bakılmadığını sordu. Bu makale derste tartışılamadı; hoca makalenin önemini kısaca anlattı ve bir sonraki derste üzerinden geçileceğini söyledi. ESX ve Xen'den sonra Disco'nun yapısının da görülmesi gerektiğini belirtti.

Makalenin başlığı "Running Commodity Operating Systems on Scalable Multiprocessors"dır. Hoca başlığı şöyle açtı: commodity işletim sistemi, herhangi bir yerden alınabilen, herkese açık ve erişilebilir işletim sistemidir. Bugün için Microsoft Windows ya da Linux gibi düşünülebilir; makalenin yazıldığı dönemin hazır işletim sistemleri kastedilir. Makalenin amacı bu işletim sistemlerini ölçeklenebilir çok işlemcili (scalable multiprocessor) ortamlarda çalıştırabilmektir.

> **Hocanın vurgusu:** Disco "hakikaten önemli" bir makaledir. Ölçeklenebilirlik, mesajlaşma, performans ve sanallaştırma bu makalede yine bir aradadır.

Hoca, Disco'nun bir işletim sistemi gibi karşımıza çıksa da aslında bir sanal makine izleyicisi (Virtual Machine Monitor), yani sanallaştırma ortamı sağlayan özel bir yazılım olduğunu söyledi.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:14:20): VMware ESX Server'daki sanallaştırma mantığına göre Xen'de uygulanan sanallaştırma mantığının temel farkı nedir?

Derste verilen cevap: ESX'te misafir işletim sistemi değiştirilmez ve bir sanallaştırma katmanının üzerinde çalıştığının farkında değildir; fiziksel makinenin işlemcisi, belleği ve çevre birimlerinin birebir kopyası yazılımda oluşturulup ona sunulur. Xen'de misafir işletim sistemi değiştirilmiştir, sanallaştırma katmanının farkındadır ve Xen ile hypercall'larla haberleşir. Bu sayede sanallaştırma daha kolay olur, ek yük azalır ve performans artar. Hoca, farka yalnız bellek açısından değil, işlemci ve çevre birimleri dahil her açıdan bakılması gerektiğini vurguladı.

**Soru 2** (derste sözlü, 00:18:09): Disco makalesinin amacı nedir ve Disco nasıl bir yazılımdır?

Derste öğrencilerden cevap gelmedi; hoca kendisi kısaca açıkladı: Disco, herkesin erişebildiği hazır (commodity) işletim sistemlerini ölçeklenebilir çok işlemcili makinelerde çalıştırmayı amaçlar. İşletim sistemi gibi görünse de bir sanal makine izleyicisidir (VMM). Makalede ölçeklenebilirlik, mesajlaşma, performans ve sanallaştırma bir aradadır.

## Dersin Toparlaması

Bu derste Xen makalesi üzerinden paravirtualization tartışıldı. ESX'in tam sanallaştırmasında misafir işletim sistemi değiştirilmez ve sanallaştırmanın farkında değildir. Bunun bedeli, her sayfa tablosu yazmasının yakalanması, gölge sayfa tablolarının tutulması ve süper sayfaların bitişikliğinin zor sağlanmasıdır. Xen ise misafir çekirdeği az miktarda değiştirir, onu ring 0'dan indirir ve ayrıcalıklı işlerini hypercall'larla Xen'e yaptırır. ABI'ye dokunulmadığı için uygulamalar değişmeden çalışır. CPU, bellek ve G/Ç ayrı ayrı sanallaştırılır; etiketsiz TLB'lerde adres alanı geçişlerinin maliyeti, kesme tablosunun Xen üzerinden kurulması ve sistem çağrılarının misafire iletilmesi bu tasarımın başlıca konularıdır. Yönetim işlevleri ayrı bir misafir alana çıkarılmıştır. Tablo 2'deki küçük satır sayıları, bu müdahalenin az olduğunu ve karşılığında performans kazanıldığını gösterir.

Ders, ESX ve Xen'den sonra görülecek Disco makalesine kısa bir girişle bitti. Disco, hazır işletim sistemlerini ölçeklenebilir çok işlemcilerde bir sanal makine izleyicisi aracılığıyla çalıştırma fikrini ele alır ve bir sonraki derste üzerinden geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
