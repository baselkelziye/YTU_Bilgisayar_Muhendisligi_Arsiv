# Ders 2 Çalışma Özeti

## Genel Konular

- Dersin işleyişi: makale tartışması
  - Bu derste ekran paylaşımı yapılmadı; ders, haftalık okunan makalelerin hoca soruları ve öğrenci yorumlarıyla tartışılması biçiminde işlendi.
  - Tartışılan makaleler: donanımda koruma halkaları (Multics), süper sayfalar için şeffaf işletim sistemi desteği ve Hoare'un "Communicating Sequential Processes" makalesi.
- Donanımda koruma halkaları (Hardware Architecture for Implementing Protection Rings)
  - Koruma halkaları daha önce yazılımda vardı; makale bu mekanizmanın Multics için donanımda nasıl gerçekleştirileceğini anlatır.
  - Tasarımın sağlaması gereken dört ölçüt: işlevsel yetenek (functional capability), ekonomi, basitlik ve programlama genelliği.
  - Sekiz halka önerilmiştir: 0 en yetkili, 7 en yetkisiz halkadır. Sekiz sayısı zorunlu değildir, başka sistemlerde farklı olabilir.
  - Halka seviyesi; bellek ve sistem kaynaklarına erişimi, okuma/yazma/yürütme yetkilerini belirler.
  - Daha yetkisiz halkadan daha yetkili halkadaki bir işleve geçiş yalnızca kapılar (gate) üzerinden yapılır; hangi işlevin çağrılabileceğini kapılar belirler.
- Süper sayfalar (Practical, Transparent Operating System Support for Superpages)
  - Motivasyon: bellek boyutları hızla büyürken TLB küçük kaldı; TLB ıskaları arttı.
  - TLB, sanal-fiziksel adres dönüşümünü yapan sayfa tablosunun önbelleğidir.
  - Sayfa boyutu sabitken sayfa tablosu bellek boyutuyla doğrusal büyür; tablo belleğin büyük bir kısmını kaplayabilir.
  - Süper sayfa, taban sayfadan (base page) büyük sayfadır. Örnek mimariler: Alpha (8 KB taban; 64 KB, 512 KB, 4 MB süper sayfa), i386 (4 KB ve 4 MB), Itanium (4 KB'tan 256 MB'a on farklı boyut).
  - Süper sayfa kısıtları: boyutun işlemci/TLB tarafından desteklenmesi, sanal ve fiziksel bellekte bitişiklik (contiguous), başlangıç adresinin süper sayfa boyutunun tam katı olması, tek TLB girdisi (tek referans biti, tek kirli bit, tek koruma özniteliği).
  - Promotion (taban sayfaları birleştirip süper sayfa yapma), demotion (süper sayfayı daha küçük parçalara bölme), eviction (belleği boşaltmak için sayfayı ikincil belleğe taşıma).
  - Population map: her bellek nesnesinde hangi taban sayfaların ayrıldığını izleyen yapı.
- Communicating Sequential Processes (Hoare)
  - Çok işlemcili makinelerin tek işlemcili görünen makinelerden daha güçlü, kapasiteli, güvenilir ve ekonomik olabileceği öngörüsü; bunun için bileşen işlemcilerin haberleşip eşzamanlanması gerekir.
  - Önceki yaklaşımlar (Fortran alt programları, Algol 60 prosedürleri, PL/I girişleri, Unix eş yordamları, Simula 67 sınıfları, Concurrent Pascal süreç ve monitörleri, CLU kümeleri) olaya farklı açılardan bakar; Hoare konuyu programlama tekniği açısından ele alır.
  - Dijkstra'nın korumalı komutları (guarded commands) temel alınır; anahtar kavram nondeterminizmdir.
  - Makaledeki maddelerin çoğu girdi (input) komutlarıyla ilgilidir: haberleşmede asıl zorluk çıktıyı alıp işlemektir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Makaledeki ölçütler tarihsel olarak başlangıç noktasıdır
  - Bugün olağan sayılan bu ölçütler, mekanizma ilk kez donanımda gerçekleştirilirken konulmuş gereksinimlerdir.
  - Ekonomi: mekanizmanın ağırlığı hissedilmemeli, sistemi yavaşlatmamalı, kullanıcıya şeffaf olmalı.
- Halkaların çekirdek içinde kullanımı
  - Aygıt sürücüleri çekirdekten farklı bir halkaya konursa sürücüdeki bir programlama hatası ya da güvenlik açığı bütün çekirdeği çökertmez.
  - Modern işletim sistemleri uzun yıllardır yalnızca iki seviye kullanır (çekirdek ve kullanıcı); çekirdekteki her şey aynı yetkiye sahip olduğundan bir bölümdeki hata diğerlerini de etkileyebilir.
  - Intel işlemciler dört halkayı (0-3) destekler ama gerçekleştirme zorluğu nedeniyle pratikte ikisi kullanılır. Bazı gömülü, güvenlik açısından kritik sistemlerde daha fazla halka kullanılır.
- TLB'nin neden küçük olduğu
  - TLB'deki bütün girdiler gelen adresi aynı saat çevriminde, eşzamanlı olarak karşılaştırır; bu, yazmaçtan bile pahalı özel bir önbellek yapısıdır ve işlemci frekansında çalışmalıdır.
- Hizalama kısıtının amacı
  - Başlangıç adresi süper sayfa boyutunun tam katı olunca sanal adresten fiziksel adrese geçiş basit AND/OR maskeleme ve kaydırma ile yapılır; donanım karmaşıklığı azalır.
- Demotion gerekçesi iç parçalanmadır
  - Süper sayfanın yalnızca küçük bir kısmı kullanılıyorsa geri kalanı boşa gider; süper sayfa daha küçük süper sayfalara ya da taban sayfalara bölünmelidir.
- Nondeterminizm ve yarış durumu (race condition)
  - Sonuç, çalışmanın tek ya da çok işlemcide olmasından bağımsız olarak belirli olmalıdır.
- Eski fikirler bugün de kullanılıyor
  - 1960-70'lerde ortaya atılan kavramlar bugün hâlâ kullanılır; yeni görünen birçok şey aslında eskiden yapılmıştır.

## Kısa Tekrar Notları

- Multics koruma halkaları: 8 halka, 0 en yetkili; geçiş kapılarla.
- Dört ölçüt: işlevsel yetenek, ekonomi, basitlik, programlama genelliği; hepsi aynı anda tam karşılanamaz, aralarında ödünleşim vardır.
- Unix ve modern sistemler: iki seviye (kernel mode/user mode). x86: dört halka, ikisi kullanılır.
- TLB = sayfa tablosunun önbelleği; tam ilişkili, tek çevrimde karşılaştırma, bu yüzden küçük.
- Sayfa tablosu bellekle doğrusal büyür, üstel değil.
- Süper sayfa kısıtları: desteklenen boyut, bitişiklik, boyuta hizalı başlangıç adresi, tek TLB girdisi (kaba koruma çözünürlüğü).
- Promotion: taban sayfalar → süper sayfa (artımlı yapılabilir). Demotion: süper sayfa → küçük parçalar (iç parçalanma). Eviction: ikincil belleğe taşıma.
- Population map: ayrılmış taban sayfaları izler; promotion/demotion kararları, yeniden ayırmayı ve çakışmayı önleme.
- CSP: Dijkstra'nın korumalı komutları, nondeterminizm, girdi komutlarının önemi.

## Detaylı Açıklamalar

- **Koruma halkaları.** Halka mekanizması kullanıcıların ve süreçlerin birbirlerinin verisine ya da sistem kaynaklarına doğrudan erişmesini engeller. Bir kullanıcı sistem kaynağına erişmek istediğinde daha yetkili (daha düşük numaralı) bir halkadaki işleve geçmesi gerekir; bu geçiş kapılar aracılığıyla, denetimli biçimde yapılır. Bir öğrencinin önerdiği benzetmeyle halka mekanizması bir tür sarmalama (encapsulation) sağlar: her halka üst katmanlara yalnızca açmayı seçtiği arayüzü gösterir; hoca bu yorumu kabul etti. Çekirdek, kullanıcıların donanıma doğrudan erişmesini engeller ve kaynakları onlara paylaştırır; hocanın sorusu, bu mekanizmanın çekirdeğin içinde nerede işe yarayacağıydı. Cevap aygıt sürücüleridir: sürücüler çekirdekten ayrı bir halkada çalışırsa hatalı bir sürücü çekirdeğin tamamını devre dışı bırakamaz.
- **Multics, Unix ve Intel.** Hocaya göre Multics, Unix'in atasıdır; Unix adı, Multics'teki "Multi" yerine "Uni" konarak türetilmiştir. Multics'teki sekiz seviyeli yaklaşım Unix'te kolaylık için iki seviyeye indirgenmiştir. Intel işlemciler zamanla (4004, 8008, 8080, 8088, 8086...) işlemciyi sıradan bir ürün haline getirirken o günün entegre devre olanaklarıyla sekiz halkayı karmaşık bulmuş, dört halka desteklemiştir. Çekirdeği daha güvenli yapmak için diğer halkaları da devreye sokan bazı farklı gerçekleştirmeler ve yamalar vardır; diğer işlemcilerde de halka adı verilmese bile ek bellek koruma özellikleri bulunur.
  - Ders sonrası not: Hoca, Intel işlemcisinin Multics'in geliştirildiği MIT'deki donanımın kopyası olduğunu söyledi. Büyük olasılıkla daha doğru ifade, x86 halka yapısının Multics'ten esinlendiğidir; Multics'in donanım halkaları Honeywell 6180 gibi ticari makinelerde gerçekleştirilmiştir.
- **Süper sayfaların motivasyonu.** Bellek büyürken sayfa boyutu sabit kalırsa sayfa tablosundaki girdi sayısı çok artar; tablo belleğin büyük kısmını kaplar, hatta sığmayabilir. TLB ise küçük kaldığı için kapsadığı bellek oranı düşer ve TLB ıskaları artar. Süper sayfa tek bir TLB girdisiyle büyük bir bellek bölgesini kapsar.
  - Ders sonrası not: Hoca, sayfa dönüşüm tablosunun bellekte fiziksel olarak bitişik olması gerektiğini söyledi. Bu, tek seviyeli doğrusal tablo için geçerlidir; büyük olasılıkla çok seviyeli tablolarda her seviye ayrı sayfalara dağılabilir.
- **Süper sayfa kısıtları ve çözünürlük.** Tek TLB girdisi kullanıldığı için süper sayfanın bütünü için tek referans biti, tek kirli bit ve tek koruma özniteliği vardır. Taban sayfalarla çalışırken koruma çözünürlüğü (granülarite) 4 KB iken, süper sayfa kullanıldığında çözünürlük süper sayfanın boyutuna (ör. 64 KB ya da 256 MB) çıkar. Hizalama kısıtı sanal ve fiziksel adreslerin aynı olmasını gerektirmez; ikisinin de süper sayfa boyutunun tam katı olması yeterlidir.
- **Promotion, demotion, eviction.** Promotion, bitişik taban sayfaları bir araya getirip süper sayfa yapmaktır; bir süper sayfa boyutuna ulaşıldıktan sonra arkasında bitişik taban sayfalar birikmeye devam ederse bir sonraki desteklenen boyuta artımlı olarak yükseltilebilir. Demotion, süper sayfayı yeniden daha küçük süper sayfalara ya da taban sayfalara bölmektir; gerekçesi iç parçalanmadır. Hocanın örneği: 256 MB'lık süper sayfanın yalnızca 128 MB'tan az bir kısmı doluysa diğer 128 MB'ın süper sayfanın içinde boş durmasına gerek yoktur; sayfa iki 128 MB'lık parçaya ya da taban sayfalara bölünmelidir. En kötü durumda süper sayfanın yalnızca 1 baytı kullanılır ve 256 MB − 1 bayt boşa gider. Eviction ise bellekte yer kalmadığında sayfaların ikincil belleğe taşınması ve gerektiğinde geri getirilmesidir; normal sayfalamadaki eviction'dan farkı yoktur. Bu yönetim donanıma yakın, hızlı ve proaktif yapılmalıdır; bellek dolduktan sonra başlamak geç kalabilir.
- **Population map.** Her bellek nesnesinde ayrılmış taban sayfaları izler. Sayfa hatasında işletim sistemi bu harita ile sanal adrese karşılık gelen rezerve edilmiş çerçeveyi bulur; böylece zaten ayrılmış bir sayfa için yeniden yer ayırmaz. Boşalan ve dolan sayfaların farkına varılarak demotion ve promotion kararları alınır. Paylaşım açılmadıkça eşlemelerin çakışmaması da bu harita ile denetlenir.
- **Neden Alpha.** Alpha 8 KB taban sayfanın yanında üç süper sayfa boyutu (64 KB, 512 KB, 4 MB) destekler; i386 yalnızca 4 KB ve 4 MB destekler. Itanium daha esnektir ama makalenin yazıldığı dönemde yaygın değildi ve hiçbir zaman yeterince popüler olmadı. Bu yüzden deneyler Alpha üzerinde yapılmıştır.
- **CSP.** Hoare'un amacı, altyapı birden fazla işlemciden oluşsa bile kullanıcı seviyesinden tek bir bütünleşik sistem görülmesini sağlayan, haberleşme ve eşzamanlamayı programlama tekniği açısından ele alan bir yapı kurmaktır. Dijkstra'nın kontrol yapıları kullanılmadan süreçler kendi haline bırakılırsa çalışma nondeterministik olur; bunun işletim sistemlerindeki adı yarış durumudur. Hocanın benzetmesiyle hilesiz bir yarışı aynı yarışçılarla üç kez koşturursanız üç farklı sonuç alabilirsiniz. Haberleşmede çıktı göndermek büyük sorun değildir; asıl zorluk, bir sürecin çıktısını girdi olarak alacak sürecin bekletilmesi ve zamanlamanın yönetilmesidir. Makalede ardışık ve eşzamanlı program yapıları (tekrarlama, seçim, ardışık birleştirme), girdideki ardışık iki yıldızı yukarı okla değiştiren bir süreç örneği, sınırlı tampon, tamsayı semaforu ve yemek yiyen filozoflar gibi problemlerin çözüm taslakları bulunur.
  - Ders sonrası not: Hoca, Dijkstra'nın korumalı komutlarının nondeterminizmi ortadan kaldırmak için kullanıldığını söyledi. Büyük olasılıkla CSP'de korumalı komutlar nondeterminizmi tamamen kaldırmaz; onu açıkça ifade eden ve denetleyen araçtır (birden fazla koruma doğruysa hangisinin seçileceği belirlenmemiştir).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
