# Ders 3 Çalışma Özeti

## Genel Konular

- Dersin kapsamı ve konu akışı
  - Bilgisayar mühendisinin kim olduğu ve ne yaptığı, bilgisayarın ne olduğu ve neler yapabildiği, işletim sistemi, yazılım ve donanım kavramları ile bilgisayarın iç birimleri ele alınır.
  - Dersin en önemli konusu algoritmadır: algoritmanın ne olduğu, nasıl tasarlandığı, bir problemin nasıl çözüldüğü ve bilgisayara bir işin nasıl yaptırıldığı.
  - Konu sırası: bilgisayarın tarihçesi ve hesaplama makineleri → verinin saklanması, ikili (binary) sistem ve sayı sistemleri (2, 8, 10, 16 tabanları) → bilgisayar mimarisi, tam sayı ve kesirli sayıların saklanması → algoritma ve gösterim biçimleri → girdi/çıktı, döngüler (iteratif işlemler) → C ile kodlama → diziler, karakter dizileri (string), çok boyutlu diziler (matris) → işletim sistemleri ve bilgisayar ağları → arama ve sıralama algoritmaları.
  - Ders kitabı: J. G. Brookshear, "Computer Science: An Overview". Yardımcı kaynak: Fahri Vatansever, "Algoritma Geliştirme ve Programlamaya Giriş" (ekrandan, 00:19:20).
- Algoritma gösterim biçimleri ve analiz
  - Akış diyagramı (flowchart) algoritmayı şekillerle, sözde kod (pseudocode) ise yazıyla ifade eder.
  - Algoritmayı tasarlamak kadar doğru çalıştığını göstermek de önemlidir. Çizilen akış diyagramı, verilen girdi için istenen çıktıyı üretip üretmediğine bakılarak analiz edilir.
- Bilgisayar biliminin hedefi
  - Bilgisayar bilimi, insanın yaptığı işlerin mümkün olduğunca bilgisayar tarafından yapılabilir hâle getirilerek otomatikleştirilmesini hedefler.
  - Örnek 1: Binaya girişte kimliği bir insanın kontrol etmesi yerine bugün retina tarama, parmak izi okuma ve yüz tanıma (Face ID) gibi sistemler kullanılır.
  - Örnek 2: Trafik bilgisi önce telefonla sorularak öğreniliyordu. Sonra haritada renklerle yoğunluk gösterildi. Bugün en kısa yol ve varış süresi yüksek doğrulukla hesaplanıyor.
  - Bilgisayarın gücü, veriyi otomatik olarak işleyerek problemi çözmesidir. Bunun için önce verinin toplanması gerekir.
  - Bilgisayar biliminin merkezinde algoritmalar, veri yapıları ve hesaplama kuramı yer alır.
- Elektronik cihaz çeşitleri
  - Bilgisayar kavramının yanında akıllı telefonlar, tabletler, sunucular, kişisel bilgisayarlar, dizüstü bilgisayarlar ve nesnelerin interneti (IoT) cihazları vardır.
  - Akıllı hâle gelen eşyalar, arabalar ve akıllı evler genellikle gömülü sistem (embedded system) olarak sınıflandırılır. Bunların bazılarında işletim sistemi vardır, bazılarında yoktur.
- Bilgisayarın tarihçesi (slaytlardan)
  - Abaküs: M.Ö. yaklaşık 300 yıllarında Babil döneminde boncuklarla toplama-çıkarma yapılan araç. Hesaplamanın (computation) ilk adımı sayılır.
  - Charles Babbage (1791-1871): 1821'de logaritmik tablo gibi tabloları hesaplayabilen Difference Engine (Fark Makinesi) tasarladı, ancak tamamlanamadı. Daha sonra ev büyüklüğünde, 6 buhar makinesiyle beslenen ve programlanabilen Analytic Engine'i tasarladı. Veri girişi ve çıkışı delikli kartlarla (punched card) yapılıyordu (ekrandan, 01:11:00).
  - Analytic Engine'de bilginin saklandığı bir alan ve hesaplamanın yapıldığı bir alan vardı. Bu iki alan zamanla bellek birimi (memory unit) ve merkezi işlem birimi (CPU) olarak adlandırıldı.
  - Ada Byron: Babbage'ın makinesi üzerinde çalışan ilk programları yazdı (1842-1843). Dünyanın ilk programcısı olarak kabul edilir (ekrandan, 01:25:40).
  - ABC computer: Atanasoff ve Berry tarafından geliştirilen ilk elektronik bilgisayar. 1939'da ilk prototip, 1941'de ilk üretim (Iowa State Üniversitesi fizik binası bodrumu). İkincisi Colossus Mark I'dir (1943) (ekrandan, 01:27:15).
  - ENIAC (Electronic Numerical Integrator and Calculator): 1946'da ABD ordusu için geliştirilen ilk genel amaçlı bilgisayar. 30 ton, 167 m², 500.000 dolar maliyet. Matematiksel hesaplar, hava tahmini ve atom enerjisi hesapları yaptı. Veri girişi delikli kartlarla, programlama ise kabloların ve anahtarların elle değiştirilmesiyle yapılıyordu. Ondalık (decimal) veri kullanıyordu. Aynı anda yalnızca tek bir problem üzerinde çalışabiliyordu (ekrandan, 01:29:00).
  - Mainframe'ler (1950-1970'ler): yüksek işlem kapasitesine sahip büyük bilgisayarlar. Bugün hâlâ özellikle bankalarda kullanılır. Birbirine bağlı işlemleri bölünmeden, atomik olarak gerçekleştirirler. Sanallaştırma yokken bile tek fiziksel makinede birden fazla işletim sistemi çalıştırabiliyorlardı. Yedekler manyetik şerit teyplere alınırdı.
  - Kişisel bilgisayarlar: ilk kişisel bilgisayar 1965'te Olivetti tarafından üretildi (dört işlem yapabilen, 3200 dolarlık bir cihaz). 1976'da Apple'ın 666 dolarlık basit kişisel bilgisayarı çıktı. Kişisel bilgisayarlar 1980'lerden itibaren yaygınlaştı.
  - Süper bilgisayarlar: karmaşık problemler için birden fazla işlemcinin paralel ve eş zamanlı çalıştığı bilgisayar kümeleri. Örneğin bir resim dört parçaya bölünüp parçalar paralel işlenebilir.
- Analog ve dijital veri
  - Analog veri süreklidir (continuous): bir bilgiyi ifade ederken sonsuz sayıda değer kullanılabilir. Bir sinüs/kosinüs eğrisi sonsuz küçük parçalara bölünebilir.
  - Dijital veri ayrıktır (discrete): bilgi sıfır ve birlerle ifade edilir.
  - Siyah-beyaz bir resim her piksel için 0 ve 1 ile ifade edilir. 8 bit gri seviyede ise siyahtan beyaza 256 ton vardır. Bit sayısı arttıkça ayrıntı artar.
  - Analog bilgi kaset, teyp şeridi ve film şeridi gibi fiziksel bir materyalde saklanır. Kopyalamak için yeni fiziksel kopya üretmek ve taşımak gerekir.
  - Dijital bilgi kolayca kopyalanıp dağıtılabilir. Buna karşılık manipülasyona açıktır ve orijinal olup olmadığının doğrulanması gerekir. Bu durum bilgi güvenliği ve siber güvenliği önemli hâle getirmiştir.
- von Neumann mimarisi
  - Günümüz bilgisayar mimarisinin temelidir. Temel birimler: giriş birimi (input device), merkezi işlem birimi (CPU), bellek ve çıkış birimi (output device).
  - CPU iki alt birimden oluşur: aritmetik ve mantık işlemlerini yapan birim ile işlem adımlarını yöneten kontrol birimi.
  - Program ve veri aynı belleği paylaşır. Giriş/çıkış, bellek ve aritmetik birim merkezi işlem birimi tarafından yönetilir. Mimari ikili (binary) veriyle çalışır (ekrandan, 02:28:55).
  - Kuantum bilgisayarlarda bir veri aynı anda birden fazla durumda (state) bulunabilir. Bugünkü bilgisayarlarda ise veri "var ya da yok" mantığıyla tek bir durumdadır.
- Donanım ve yazılım
  - Donanım: bilgisayarın fiziksel birimleridir. Monitör, klavye, fare, entegre devreler, ana kart, GPU, bellek, sabit disk, SSD, kablolar, kablosuz modüller, dokunmatik ekran, mikrofon ve kamera bunlara örnektir.
  - Standart GPU ana kart üzerinde olabilir. Daha güçlü GPU'lar ayrı bir kart olarak slota takılır. Dizüstü bilgisayarlarda birimler genellikle tek kart üzerine entegre edilir.
  - Yazılım: donanımı kullanmak için üretilen kodlardır. Firmware ve sürücüler (driver) cihazların işletim sistemiyle uyumlu çalışmasını sağlar. Sistem yazılımları (işletim sistemi başta olmak üzere) ve kullanıcı programları yazılımın parçalarıdır.
- İşletim sistemi
  - İşletim sistemi, bilgisayarın kaynak yönetimini yapan sistem yazılımıdır.
  - Kaynak yönetimi CPU, bellek ve giriş/çıkış birimlerinin kullanımını yönetmek demektir. İşletim sistemi bu birimleri kullanmak için bir arayüz de sunar.
  - Kullanıcı ile donanım arasında köprü görevi görür.
  - Bugün işletim sistemleri genellikle grafik kullanıcı arayüzü (GUI) sunar. MS-DOS gibi eski sistemlerde GUI yoktu. Sunucularda performans için GUI kurulmadan komut satırı (terminal) ile yönetim yaygındır.
- Bellek türleri
  - Ana bellek (main memory): daha az kapasiteli ve daha hızlıdır. Elektrik kesilince içindeki bilgi kaybolur. CPU içindeki register'lar ve cache de bu türdendir.
  - İkincil bellek (secondary storage): daha büyük kapasiteli ve daha yavaştır. Elektrik kesilse de bilgiyi saklar. Sabit disk, USB bellek, CD-ROM ve DVD-ROM örnektir.
  - İkisi arasındaki temel fark, elektrik kesildiğinde bilginin korunup korunmamasıdır.
- Giriş ve çıkış birimleri, sensörler
  - Giriş birimleri: klavye, fare, mikrofon, kamera, tarayıcı (scanner), dokunmatik ekran.
  - Çıkış birimleri: ekran, hoparlör, kulaklık, yazıcı, projektör, bildirim LED'leri. Yazıcı tarayıcı olarak kullanılıyorsa giriş birimi işlevi de görür.
  - Sensörler, elektronik cihazların dış dünyayla etkileşimini sağlar. GPS, jiroskop ve ivmeölçer (accelerometer) örnektir. Akıllı telefonlarda dizüstü bilgisayarlardan çok daha fazla sensör bulunur.

## Hocanın Özellikle Vurguladığı Kısımlar

- Algoritma tasarımı, dersin asıl amacıdır
  - Dönem sonunda öğrenciden verilen problemi anlaması, sınırlarını belirlemesi, algoritmasını tasarlaması, algoritmayı analiz etmesi ve kodunu yazabilmesi beklenir.
  - C dili bu derste yalnızca tasarlanan algoritmayı bilgisayara anlatacak kadar öğretilir. Dilin tüm özellikleri sonraki dönemde Yapısal Programlama dersinde görülür.
- İngilizce terimlerin doğrusunu öğrenmek
  - Öğrencilerin notlarında "cache" gibi terimlerin yanlış yazıldığı görülmüştür. Terimlerin hem İngilizce hem Türkçe karşılıkları doğru öğrenilmelidir.
- Özel donanım, genel amaçlı donanımdan daha hızlı ve güvenlidir
  - Şifreleme algoritmaları yazılımla (standart CPU/GPU üzerinde) ya da donanımla gerçeklenebilir. Bankalarda kullanılan HSM (Hardware Security Module), şifreleme ve şifre çözmeye ayrılmış özel donanımdır.
  - Bir iş için tasarlanmış donanım, standart donanımdaki yazılım çözümünden genellikle daha hızlı ve daha güvenlidir. Donanım da sonuçta bir yazılımla desteklenmelidir.
  - Örnek: iOS belirli donanımlar için tasarlandığından, birçok farklı donanımda çalışmak üzere tasarlanan Android'e göre daha düşük donanımla benzer performans gösterebilir.
- Bilgisayar ile insan arasındaki karar verme farkı
  - Bilgisayarlar kuralları belli problemlerde tüm olasılıkları insanın yapamayacağı hızda hesaplar. Bu yüzden satrançta dünya şampiyonunu yenebilmiştir.
  - İnsan ise bağlam farkındalığı ve geçmiş deneyimleriyle karar verir. Otonom araçlar gibi parametre sayısı çok yüksek, bağlamı karmaşık problemlerde insan hâlâ daha başarılıdır.
  - Tekrar eden hesaplamaya dayalı işlerde bilgisayar, bağlamı karmaşık problemlerde insan daha başarılıdır. Bilgisayarlar çok iyi karar destek sistemleridir.
- Sanallaştırma ve paralel işlem
  - Sanallaştırma (virtualization), boşta duran CPU, bellek ve ağ bant genişliğini verimli kullanmanın en iyi yoludur. Paralel işlem de işleri hızlandırmanın yollarından biridir.
- Teknolojiyi sorumlulukla kullanmak
  - Her keşfin potansiyel bir tehlikesi vardır. Mühendis, doğaya ve insana saygıyı gözeterek, teknolojiyi insanlığın yararına kullanacak kararlar almalıdır.

## Kısa Tekrar Notları

- Bilgisayar biliminin hedefi: insan işlerini otomatikleştirmek. Merkezinde algoritma, veri yapıları ve hesaplama kuramı vardır.
- Akış diyagramı = şekillerle, pseudocode = yazıyla algoritma gösterimi. Algoritma mutlaka girdi-çıktı üzerinden analiz edilir.
- Tarihçe: Abaküs → Babbage (Difference Engine 1821, Analytic Engine) → Ada Byron (ilk programcı, 1842-43) → ABC (1939, ilk elektronik) → Colossus Mark I (1943) → ENIAC (1946, ilk genel amaçlı) → mainframe (1950-70) → kişisel bilgisayar (1965 Olivetti, 1976 Apple, 1980'ler yaygınlaşma) → süper bilgisayar (paralel işlem).
- Analog = sürekli, sonsuz değer, fiziksel ortam. Dijital = ayrık, 0/1, kolay kopyalanır ama güvenlik sorunu doğurur.
- von Neumann: giriş + CPU (aritmetik-mantık + kontrol) + bellek + çıkış. Program ve veri aynı bellekte, ikili veri.
- İşletim sistemi = kaynak yönetimi yapan sistem yazılımı (CPU, bellek, G/Ç).
- Ana bellek: hızlı, küçük, elektrik kesilince silinir. İkincil bellek: yavaş, büyük, kalıcı.
- Sensörler: GPS, jiroskop, ivmeölçer. Cihazın dış dünyayla etkileşimi.
- Özel donanım (örn. HSM) genel amaçlı donanımdaki yazılım çözümünden hızlı ve güvenlidir.

## Detaylı Açıklamalar

Bu derste önce dersin kapsamı ve konu sırası açıklanır, ardından bilgisayarın tarihçesine ve temel bileşenlerine geçilir. Dersin hedefi, öğrencinin dönem sonunda bir problemi anlayıp sınırlarını belirleyebilmesi, bu problem için algoritma tasarlayabilmesi, tasarladığı algoritmanın doğru çalıştığını analiz edebilmesi ve sonunda kodunu yazabilmesidir. Algoritmalar akış diyagramı (şekillerle) ya da sözde kod (yazıyla) ile gösterilir. Bu derste ağırlıklı olarak akış diyagramı kullanılır. Bir algoritmanın analizi, verilen girdi için beklenen çıktının üretilip üretilmediğinin adım adım kontrol edilmesidir. C programlama dili bu derste dilin kendisini öğretmek için değil, tasarlanan algoritmaları bilgisayara aktarmak için kullanılır.

Bilgisayar biliminin temel hedefi, insanın yaptığı işlerin bilgisayar tarafından yapılabilir hâle getirilmesi, yani otomasyondur. Bina girişindeki kimlik kontrolünün yerini retina tarama, parmak izi ve yüz tanıma sistemlerinin alması ya da trafik bilgisinin telefonla sorulmaktan anlık rota ve süre hesaplamasına evrilmesi bunun örnekleridir. Bilgisayar bu problemleri veriyi işleyerek çözer. Bu yüzden önce verinin toplanması, sonra işlenip sonucun insana geri sunulması gerekir. Günümüzde yalnızca bilgisayarlardan değil; akıllı telefonlar, tabletler, sunucular ve nesnelerin interneti (IoT) cihazlarından da söz edilir. Akıllı eşyaların çoğu gömülü sistemlerdir.

Tarihçede ilk adım abaküstür: boncuklarla sayıların temsil edilip toplama-çıkarma yapılması hesaplamanın başlangıcı sayılır. Uzun süre büyük bir değişiklik olmaz. Asıl kırılma Charles Babbage ile gelir. Babbage 1821'de tabloları hesaplayabilen Difference Engine'i tasarlar, ancak makine tamamlanamaz. Daha sonra tasarladığı Analytic Engine ev büyüklüğündedir, 6 buhar makinesiyle beslenir ve programlanabilir. Bu makinede bilginin saklandığı bir bölge ve hesaplamanın yapıldığı bir bölge vardır. Bu iki bölge bugünkü bellek ve CPU kavramlarının atasıdır. Veriler delikli kartlarla girilir ve sonuçlar yine delikli kartlarla alınır. Ada Byron bu makine için ilk programları yazar ve ilk programcı olarak kabul edilir. Hoca burada elektronik/donanım tasarımı ile bilgisayar mühendisliğinin kesiştiği noktayı vurgular: biri cihazı ve devreyi tasarlar, bilgisayar mühendisi ise donanımı iyi tanıyıp ona uygun yazılımlarla cihazı "akıllı" hâle getirir.

Elektronik bilgisayarlar 1940'larda ortaya çıkar. Atanasoff ve Berry'nin ABC bilgisayarı ilk elektronik bilgisayardır (1939 prototip, 1941 üretim). Colossus Mark I (1943) bunu izler. Hoca, bu dönemdeki araştırmaların merkezinde askeri ihtiyaçların olduğunu, ilk bilgisayarların ateşleme tabloları gibi uzun hesapları yapmak için kullanıldığını belirtir. 1946'da ABD ordusu için geliştirilen ENIAC ilk genel amaçlı bilgisayardır: 30 ton ağırlığında, 167 m² alan kaplayan ve 500.000 dolara mal olan bir cihazdır. Matematiksel hesaplar, hava tahmini ve atom enerjisi hesaplarında kullanılır. Programlama, kabloların ve anahtarların bir operatör tarafından elle yeniden düzenlenmesiyle yapılır. Makine aynı anda yalnızca tek bir problem üzerinde çalışabilir ve çalışırken müdahale edilemez.

1950-1970 arasında mainframe'ler gelişir. Bunlar yüksek işlem kapasitesine sahip, işlemleri atomik olarak (birbirine bağlı işler bölünmeden) yapan büyük sistemlerdir. Milyonlarca müşterisi olan bankalar için bugün de vazgeçilmezdir. Mainframe'ler, kişisel bilgisayarlarda sanallaştırma yokken bile tek bir fiziksel ortamda birden fazla işletim sistemi çalıştırabiliyordu. 1965'te Olivetti ilk kişisel bilgisayarı üretir. 1976'da Apple'ın basit kişisel bilgisayarı çıkar. 1980'lerden itibaren kişisel bilgisayarlar yaygınlaşır. Ardından süper bilgisayarlar gelir: çok sayıda işlemcinin eş zamanlı ve paralel çalıştığı kümelerle büyük problemler parçalara bölünerek çözülür. Bilgisayarın satrançta dünya şampiyonunu yenmesi, kuralları belli bir problemde tüm olasılıkları hesaplayabilmesinin sonucudur. Ancak otonom araçlar gibi bağlamı karmaşık problemlerde insanın deneyime dayalı karar verme yeteneği hâlâ üstündür. Bilgisayarlar bu alanlarda daha çok güçlü karar destek sistemleri olarak görülür.

Analog ve dijital ayrımı ayrıntılı ele alınır. Analog veri süreklidir: bir eğri sonsuz küçük parçalara bölünebilir, yani sonsuz sayıda değer alabilir. Dijital veri ise ayrıktır ve 0-1 ile ifade edilir. Siyah-beyaz bir resimde her piksel 0 ya da 1'dir. 8 bit gri seviyede 256 ton vardır. Bit sayısı arttıkça dijital görüntünün ayrıntısı artar ve analoga yaklaşır. Analog bilgi kaset, teyp ve film şeridi gibi fiziksel bir ortamda saklanır. Kopyalamak için yeni fiziksel kopya üretmek ve taşımak gerekir. Dijital bilgi ise saniyeler içinde kopyalanıp dünyanın her yerine dağıtılabilir. Bu avantajın bedeli güvenliktir: dijital bilgi manipülasyona açıktır ve orijinalliğinin doğrulanması gerekir. Bu nedenle bilgi güvenliği ve siber güvenlik günümüzün en önemli konuları arasındadır.

Temel bilgisayar mimarisi von Neumann mimarisiyle açıklanır. Bir bilgisayar için olmazsa olmaz birimler; veriyi dışarıdan alan giriş birimi, veriyi işleyen ve geçici olarak saklayan merkezi işlem birimi ile bellek, ve sonucu dışarıya aktaran çıkış birimidir. CPU, aritmetik-mantık işlemlerini yapan birim ile işlemlerin adımlarını yöneten kontrol biriminden oluşur. Program ve veri aynı belleği paylaşır, sistem ikili veriyle çalışır. Hoca, gelecekte kuantum bilgisayarların bu yaklaşımı aşabileceğini ve bu bilgisayarlarda bir verinin aynı anda birden fazla durumda bulunabileceğini belirtir.

Bilgisayar organizasyonu donanım ve yazılım olarak ikiye ayrılır. Donanım fiziksel birimlerdir: giriş/çıkış aygıtları, ana kart üzerindeki entegre devreler, GPU, bellek, diskler, kablolar ve kablosuz modüller. Yazılım ise bu donanımı kullanmak için üretilen kodlardır. En alt seviyede firmware ve sürücüler, onların üzerinde sistem yazılımları ve en üstte kullanıcı programları bulunur. İşletim sistemi bilgisayarın kaynak yönetimini yapan sistem yazılımıdır: CPU, bellek ve giriş/çıkış birimlerinin kullanımını yönetir ve kullanıcıya bu birimleri kullanması için bir arayüz sunar. Bugün çoğu işletim sistemi grafik arayüz sunar, ancak sunucularda performans için komut satırıyla yönetim yaygındır.

Bellekler elektrik kesildiğinde bilgiyi koruyup korumamalarına göre ayrılır. Ana bellek (ve CPU içindeki register ile cache) hızlıdır ama elektrik kesilince bilgiyi kaybeder. İkincil bellek (sabit disk, USB, CD/DVD) daha yavaştır ama bilgiyi kalıcı olarak saklar. Giriş birimleri (klavye, fare, mikrofon, kamera, tarayıcı, dokunmatik ekran) bilgisayara veri aktarır. Çıkış birimleri (ekran, hoparlör, yazıcı, projektör, LED) sonucu insana iletir. Günümüz elektronik cihazlarında bunlara ek olarak GPS, jiroskop ve ivmeölçer gibi sensörler bulunur. Sensörler, cihazın tıpkı insanın beş duyusu gibi dış dünyayı algılamasını sağlar.

Son olarak şifreleme örneği üzerinden yazılım ve donanım çözümleri karşılaştırılır. Şifreleme bir CPU/GPU üzerinde yazılımla yapılabileceği gibi, bankalarda kullanılan HSM gibi yalnızca bu iş için tasarlanmış özel donanımlarla da yapılabilir. Özel donanım standart bir mimari kullanmadığı için hem daha güvenli hem de daha hızlıdır. iOS ile Android karşılaştırması bu ilkeyi gösterir: belirli donanımlar için yazılan iOS, çok farklı donanımlarda çalışması gereken Android'e göre daha düşük donanımla benzer performans verebilir. Sonuç olarak, mümkünse bir iş için özel donanım kullanmak işi hızlandırır ve daha güvenli bir çözüm sağlar.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
