# Ders 2 Genişletilmiş Notu: Koruma Halkaları ve Donanımla Erişim Denetimi (Multics Makalesi)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Biçimi: Makale Tartışması
- 2. Makalenin Kurduğu Sistem: Ölçütler ve Segmentli Sanal Bellek
- 3. Makalenin Ana Motivasyonu: Erişim Denetimi
- 4. 1972'den Bugüne: Intel Korumalı Kipi ve Linux Halkaları
- 5. Bu Yapıdan Önce Erişim Denetimi
- 6. Bir Makale Nasıl Okunmalı?
- 7. Halka ve Kapı Yapısı
- 8. Genelleme ve Makalenin Çözdüğü Üç Problem
- 9. Yalıtım Dereceleri: System Call Interposition ve SFI
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Biçimi: Makale Tartışması

Bu ders, hocanın önceden gönderdiği bir bilimsel makalenin sınıfta tartışılmasıyla geçti. Hoca derse "Bu makalenin içeriği nedir, amacı nedir?" sorusuyla başladı ve öğrencilerden makaleyi kısaca özetlemelerini istedi. Dersin ilk haftasında söylendiği gibi, bu derste işletim sistemlerinin temelini oluşturan bazı klasik makaleler okunacaktır; bu makale de onlardan biridir. Kayıt boyunca ekranda slayt ya da makale paylaşılmadı; bu yüzden aşağıdaki bütün bilgiler sözlü anlatımdan alınmıştır.

Tartışılan makale, Multics işletim sisteminde koruma halkalarının (protection rings) donanımla gerçeklenmesini anlatır. Hocanın aktardığı anahtar kelimeler şunlardır: *protection*, *protection rings*, *protection hardware*, *access control* ve *hardware access control*.

> **Ek bilgi (derste anlatılmadı):** Derste makalenin adı ve yazarları söylenmedi. Anlatılan içerik ve yıl, büyük olasılıkla M. D. Schroeder ve J. H. Saltzer'in 1972'de Communications of the ACM'de yayımlanan "A Hardware Architecture for Implementing Protection Rings" makalesine karşılık gelir.

## 2. Makalenin Kurduğu Sistem: Ölçütler ve Segmentli Sanal Bellek

Söz alan bir öğrenci, makalenin halka mekanizmasının donanımda nasıl gerçekleneceğini anlattığını söyledi. Öğrenciye göre makale, böyle bir sistem kurulurken gözetilmesi gereken dört ölçütle başlar:

- **Functional capability** (işlevsel yetenek)
- **Economy** (ekonomi, maliyet)
- **Simplicity** (basitlik)
- **Programming generality** (programlama genelliği)

Makale bu dört ölçütten yola çıkarak bir sistem kurar. Öğrencinin aktardığı yapı taşları şunlardır:

- **Segmentli sanal bellek:** Bellek, kelime dizilerinden (*array of words*) oluşan segmentler halinde düzenlenir.
- **Sanal adresten gerçek adrese çeviri:** Sanal bellek ile gerçek bellek arasındaki bağlantı bir tablo üzerinden kurulur; tabloda segmentin adres bilgisi tutulur ve oradan gerçek belleğe gidilir. <!-- BELİRSİZ: altyazıda "soft table" geçiyor; büyük olasılıkla segment tablosu ya da tanımlayıcı (descriptor) tablosu kastedildi -->
- **Segment başına izinler:** Her segmentin okuma (*read*), yazma (*write*) ve çalıştırma (*execute*) izni vardır; bu izinler bir denetim mekanizmasıyla uygulanır.

Hoca öğrencinin hevesini takdir etti, ama ayrıntılara girmeden önce makalenin temel sorusunun ne olduğunu sordu. Bu soru bir sonraki bölümün konusudur.

## 3. Makalenin Ana Motivasyonu: Erişim Denetimi

**Soru:** Bu makale ne için yazılmış, ana araştırma noktası ya da motivasyonu nedir?

**Cevap (öğrenci):** Prosedür çağrıları farklı bir bellek segmentine geçerken donanım seviyesinde izin kısıtlamaları koymak; her prosesin her yere erişmesini engellemek.

Hoca bu cevabın doğru yönde olduğunu, ama makalenin girişinde çok daha basit bir cümlenin bulunduğunu söyledi ve o cümleyi okudu:

> "The topic of this paper is the control of access to stored information in a computer utility."

Yani makalenin konusu, bir bilgisayar hizmetinde (*computer utility*) depolanan bilgiye erişimin denetimidir. Makalenin ana amacı erişimi nasıl denetimli hale getirebileceğimizdir; yazarlar bunu nasıl başarabileceklerini araştırmışlardır. Segmentler, izinler ve halkalar bu amaca hizmet eden araçlardır.

> **Hocanın vurgusu:** Bir makaleyi okurken önce ana motivasyon bulunmalı, ayrıntılar sonra gelmelidir. Bu makalede ana motivasyon girişte tek bir cümleyle yazılıdır: erişim denetimi (access control).

## 4. 1972'den Bugüne: Intel Korumalı Kipi ve Linux Halkaları

Hoca makalenin yılını sordu; bir öğrenci 1970'ler dedi, hoca 1972 olduğunu belirtti. Makalede ortaya konan yapı, Honeywell 645 işlemcisi (o zamanki adlandırmayla bir sistem; neredeyse oda büyüklüğünde bir makine) üzerinde çalışan Multics işletim sistemi bağlamında geliştirilmiştir. Hoca ardından bu yapının günümüzde hâlâ yaşayıp yaşamadığını sordu.

### 4.1 Linux'ta Ring 0 ve Ring 3

Bir öğrenci Linux örneğiyle cevap verdi. Linux'ta iki halka kullanılır:

- **Ring 0:** Çekirdek (kernel) kodu burada çalışır. Donanıma yalnız çekirdek erişir.
- **Ring 3:** Kullanıcı programları burada çalışır.

Öğrenci geçişi bir örnekle anlattı: Bir program yazıp içinde `printf` çağırdığınızı düşünün. `printf`, `write` sistem çağrısını çağırır. Bu çağrı bir yazılım kesmesi (*software interrupt*) üretir ve denetim çekirdeğe geçer; yani Ring 3'ten Ring 0'a geçilir. Bu sırada aygıt sürücüsü (*device driver*) de işin içine girer ve ardından çekirdek Ring 0'da çalışır.

> **Ek bilgi (derste anlatılmadı):** Klasik 32 bit Linux'ta sistem çağrısı için `int 0x80` yazılım kesmesi kullanılır; günümüz x86-64 sistemlerinde ise bunun yerine büyük olasılıkla `syscall` komutu kullanılır. Her iki yolda da işlemci kullanıcı halkasından çekirdek halkasına denetimli bir giriş noktasından geçer.

### 4.2 Hangi Mimari?

Hoca, Ring 0 ve Ring 3 ayrımının günümüzdeki hangi işlemci mimarisine dayandığını sordu; cevap Intel oldu. Hoca bunu şöyle bağladı: Intel'in 286 ile birlikte korumalı kip (*protected mode*) olarak getirdiği, ardından 386, 486, Pentium ve günümüzdeki i3, i5, i7 ailelerinde süren yapının temelinde aslında 1972'de yazılmış bu makale vardır. Intel mühendisleri sıfırdan yeni bir şey düşünmemiş; Honeywell 645 ve Multics üzerinde yapılan ve bu makalede anlatılan deneylerden yola çıkarak Intel işlemcisindeki koruma, yani erişim denetimi mekanizmasını tanımlamışlardır.

Hoca, yaklaşık 50 yıl önce ortaya atılan bir yapının hâlâ sürdüğüne dikkat çekti. Benzer yapılar bugün kullanılmaya devam eden ya da kullanımı azalmış veya tamamen kalkmış başka işlemci mimarilerinde de görülür. Bu nedenle makale, erişim denetimi mekanizmalarının kurulması açısından çok temel ve çok önemli bir yayındır. Protection ve protection rings anahtar kelimeleri de Intel'deki "protected mode" adıyla doğrudan ilişkilidir.

## 5. Bu Yapıdan Önce Erişim Denetimi

Hoca ardından şu soruyu sordu: Honeywell 645 üzerinde kurulan bu yapıdan önce erişim denetimi nasıl sağlanıyordu?

Bir öğrenci, makalenin proseslerin segmentli belleği nasıl kullanabileceğinden söz ettiğini, örneğin A prosesinin B prosesinin bulunduğu bir yere erişmek istemesi durumunu ve birden fazla kullanıcı varken kurulabilecek erişim denetimlerini anlattığını söyledi. Makaleye göre önceki yöntemler dört ölçütle (işlevsel yetenek, ekonomi, basitlik, genellik) uyuşmadığı için halka seviyesi getirilmiştir. Hoca, "erişim denetiminin" zaten yapılan işin genel adı olduğunu, sorunun bunun daha önce hangi araçla yapıldığı olduğunu hatırlattı. Başka bir öğrenci segmentlerin okuma/yazma/çalıştırma haklarından söz etmeye başlayınca hoca bunun makaledeki yapının kendisi olduğunu, sorunun ise ondan öncesini hedeflediğini belirtti.

Hocanın verdiği cevap şöyledir:

1. **Yazılımla erişim denetimi:** İşin başında erişim denetimi yazılımla çözülmeye çalışılmıştır. Bu doğal olarak başarısız olur: donanım denetimi olmadan, çalışan bir programın bellekte nereye erişip nereye erişmeyeceğini kısıtlamak mümkün değildir.
2. **Basit donanım mimarileri:** Daha sonra basit bir donanım mimarisiyle bu iş yapılmaya çalışılmıştır. Ancak bu yaklaşımlar da makalenin başındaki dört ölçütü karşılamamıştır: ekonomik değildir ya da yeterince etkili değildir, aynı anda birden fazla prosesin çalışmasına uyumlu değildir ve sanal bellek yapısını tam desteklemez.

Makaledeki halka mimarisi, bu eksiklikleri gidermek için önerilmiştir.

## 6. Bir Makale Nasıl Okunmalı?

Hoca, bu dersin neden makale okuma biçiminde yürütüldüğünü açıkladı. Bu makaleleri uzun yıllardır öğrencilerle birlikte değerlendirdiğini, dolayısıyla içeriklerini iyi bildiğini, ama önemli olanın öğrencilerin öğrenmesi olduğunu söyledi. Bilimsel bir yayını inceleyebilmek, ondan ana fikri ve önemli bilgileri ayıklayabilmek ve aradaki ilişkileri kurabilmek çok değerli becerilerdir.

Bir makale okunurken şu sorular sorulmalıdır:

- Çalışmanın amacı nedir?
- Kapsamı nedir?
- Hangi teorik ve pratik çalışmalar yapılmıştır?
- Hangi sonuçlar elde edilmiştir?
- İleride incelenmesi gereken kısımlar nelerdir?

Hoca bu soruların bilimin ilerlemesini sağlayan temel sorular olduğunu belirtti.

> **Hocanın vurgusu:** Bugün masaüstü bilgisayarlarda, sunucularda ve tabletlerde kullanılan işlemcilerin donanım yapısının ve onların üzerinde çalışan Linux, Windows gibi modern işletim sistemlerinin ana yapısının 70'li yıllarda ortaya atıldığını bilmek ve 50 yılda bu kadar az değişmesine şaşırıp hayranlık duymak önemlidir. Bunun farkına varılmalıdır.

## 7. Halka ve Kapı Yapısı

Hoca, makaledeki her satırı ve her cümleyi bilmenin gerekmediğini, ama şu soruların cevabının nedenleriyle birlikte bilinmesinin beklendiğini söyledi:

- Halka (*ring*) yapısı nedir?
- Kapı (*gate*) yapısı nedir ve ona neden ihtiyaç duyulur?
- Daha düşük koruma seviyesinden daha yüksek koruma seviyesine geçiş ile daha yüksek koruma seviyesinden daha düşük koruma seviyesine geçiş nasıl karşılaştırılır; bu geçişlerde neler olmalı, neler olmamalı?

Hoca bunu bir örnekle somutlaştırdı: Bir `call` ve bir `return` çok basit görünür. Bir adresi çağırırsınız, oraya gidersiniz, geri dönersiniz. Ama gittiğiniz adres aynı halkada, aynı segmentte değilse ne olur? İşte bu noktada araya kapı yapısı girer. Halkalar arası geçiş, denetimsiz bir sıçrama olamaz; ancak tanımlı giriş noktalarından yapılabilir.

> **Ek bilgi (derste anlatılmadı):** Kapı, daha ayrıcalıklı bir halkadaki kodun dışarıdan çağrılabilecek tanımlı giriş noktasıdır. Daha az ayrıcalıklı koddan daha ayrıcalıklı koda yapılan çağrı yalnız kapılar üzerinden kabul edilir; böylece çağıran, çekirdeğin içinde istediği bir adrese atlayamaz. Intel korumalı kipindeki "call gate" kavramı büyük olasılıkla bu fikrin doğrudan karşılığıdır.

## 8. Genelleme ve Makalenin Çözdüğü Üç Problem

Hoca makalenin bir başka güzel yanının genelleme (*generalization*) olduğunu söyledi. O güne kadar var olan supervisor/user iki seviyeli ayrım, makalede farklı ve daha genel bir biçimde ele alınır. Mimari paylaşılan sanal belleği (*shared virtual memory*) ve segmentasyonu destekler. 50 yıl sonra bu yapının hâlâ kullanıldığını, Intel'in korumalı kipi gerçeklerken onu temel kabul ettiğini ve başka mimarilerde de benzer yapıların bulunduğunu görmek, yazarların genelleme konusunda ne kadar başarılı ve ileriye dönük bir iş yaptığını gösterir.

Hoca, makalede halka mimarisinin üç temel problemi çözdüğünün yazdığını belirtip bunları okudu:

1. **"Users can create arbitrary but protected subsystems for use by others."** Kullanıcılar, başkalarının kullanabileceği keyfi ama korumalı alt sistemler oluşturabilir.
2. **"The supervisor can be implemented in layers which are enforced."** Supervisor, yani işletim sisteminin çekirdeği, zorlanan katmanlar halinde, diğer parçalardan yalıtılmış ve daha korumalı biçimde gerçeklenebilir. Hoca bunun güvenlikteki *compartmentalization* (parçalara bölme, parçaları birbirinden yalıtma) kavramının temeli olduğunu söyledi.
3. **"The user can protect himself while debugging his own (or borrowed) programs."** Kullanıcı, kendi ya da ödünç aldığı programları hata ayıklarken kendini koruyabilir; yani sistem kullanıcıyı kendisinden korur.

> **Hocanın vurgusu:** Üçüncü madde, yani kullanıcının kendisinden korunması, çok çok önemlidir; yalıtımın (isolation) temelidir.

## 9. Yalıtım Dereceleri: System Call Interposition ve SFI

Hoca üçüncü problemden yola çıkarak bilgisayar güvenliğinde yalıtımın farklı dereceleri olduğunu belirtti:

- **Prosesler arası yalıtım:** Farklı proseslerin birbirinden yalıtılmasıdır. Hoca bu bağlamda *system call interposition* adını verdi.
- **Proses içi yalıtım:** Aynı prosesin içindeki parçaların birbirinden yalıtılmasıdır. Buna *software fault isolation* (SFI) denir. Makaledeki "kullanıcı kendi ya da ödünç aldığı programları hata ayıklarken kendini koruyabilir" fikri, kullanıcıyı kendinden koruması bakımından SFI'nin temelidir.

> **Ek bilgi (derste anlatılmadı):** System call interposition, bir prosesin yaptığı sistem çağrılarının araya giren bir izleyici tarafından denetlenip gerekirse engellenmesidir. SFI ise aynı adres uzayında çalışan güvenilmeyen bir modülün belleğin yalnız kendisine ayrılmış bölgesine erişmesini, kodu yeniden yazarak ya da denetim komutları ekleyerek sağlayan bir tekniktir.

Hoca, makaleye bu gözle bakılmasını umduğunu söyledi.

## Örnek Sorular

Kayıtta ekranda soru ya da slayt gösterilmedi; aşağıdaki sorular hocanın derste sözlü sorduğu sorulardır.

**Soru 1** (derste sözlü, 00:10:32): Makalenin ana araştırma noktası ya da ana motivasyonu nedir?

> **Cevap (derste verildi):** Depolanan bilgiye erişimin denetimi (access control). Girişte "The topic of this paper is the control of access to stored information in a computer utility." diye yazılıdır.

**Soru 2** (derste sözlü, 00:11:49): Makale hangi tarihte yazılmıştır?

> **Cevap (derste verildi):** 1972.

**Soru 3** (derste sözlü, 00:12:16): Makalede Honeywell 645 ve Multics üzerinde ortaya konan yapı günümüzde hâlâ yaşıyor mu?

> **Cevap (derste verildi):** Evet. Intel'in 286 ile getirdiği ve günümüz işlemcilerinde süren korumalı kip bu yapıya dayanır. Linux bunun iki halkasını kullanır: çekirdek için Ring 0, kullanıcı programları için Ring 3. Kullanıcı kodu `printf` ile `write` sistem çağrısını çağırdığında yazılım kesmesiyle Ring 3'ten Ring 0'a geçilir.

**Soru 4** (derste sözlü, 00:13:00): Ring 0 ve Ring 3 ayrımı günümüzdeki hangi işlemci mimarisine dayanır?

> **Cevap (derste verildi):** Intel mimarisi (286 ile gelen korumalı kip; 386, 486, Pentium, i3/i5/i7).

**Soru 5** (derste sözlü, 00:15:41 ve 00:19:29): Bu makaledeki yapıdan önce erişim denetimi nasıl sağlanmaya çalışılıyordu?

> **Cevap (derste verildi):** Önce yazılımla erişim denetimi denendi; donanım desteği olmadan bir programın bellekte nereye erişeceğini kısıtlamak mümkün olmadığı için başarısız oldu. Sonra basit donanım mimarileri denendi; bunlar ekonomik ve etkili değildi, çoklu proses çalışmasına ve sanal belleğe tam uyum sağlamıyordu, yani makalenin dört ölçütünü karşılamıyordu.

**Soru 6** (derste sözlü, 00:28:09): Makaleye göre halka mimarisi hangi üç temel problemi çözer?

> **Cevap (derste verildi):** (1) Kullanıcılar başkaları için keyfi ama korumalı alt sistemler oluşturabilir. (2) Supervisor zorlanan katmanlar halinde gerçeklenebilir. (3) Kullanıcı kendi ya da ödünç aldığı programları hata ayıklarken kendini koruyabilir.

## Dersin Toparlaması

Bu derste Multics işletim sistemi bağlamında 1972'de yazılmış koruma halkaları makalesi tartışıldı. Makalenin ana konusu, depolanan bilgiye erişimin denetimidir. Yazarlar, işlevsel yetenek, ekonomi, basitlik ve programlama genelliği ölçütlerini karşılayan, segmentli sanal bellek ve segment başına okuma/yazma/çalıştırma izinleri üzerine kurulu bir donanım halka mimarisi önermiştir. Bu yapıdan önce erişim denetimi önce yazılımla, sonra basit donanımla denenmiş, ikisi de yetersiz kalmıştır. Makalenin önerdiği yapı supervisor/user ayrımını genelleştirir; korumalı alt sistemler, katmanlı bir supervisor ve kullanıcının kendini koruması gibi üç temel problemi çözer.

Hoca, bu yapının 50 yıl sonra Intel'in korumalı kipinde ve Linux, Windows gibi işletim sistemlerinde yaşadığını vurguladı. Halkalar arası çağrıda kapı yapısının neden gerektiği, yüksek ve düşük koruma seviyeleri arasındaki geçişlerin farkı ve bu fikirlerin bugünkü compartmentalization, system call interposition ve SFI gibi yalıtım kavramlarına nasıl bağlandığı, makaleden çıkarılması beklenen temel bakış açısıdır. Tartışmanın bir sonraki derste aynı makaleden sürdürülmesi planlandı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
