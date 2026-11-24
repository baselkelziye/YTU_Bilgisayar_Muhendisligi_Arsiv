# Ders 2 Çalışma Özeti

## Genel Konular

- Yazılımı etkileyen eğilimler (ekrandan, 00:20:00)
  - Yaygınlaşan bilgi işlem: Hesaplama gücü giderek küçülen alanlara sığdırılıyor. Böylece bilişim günlük yaşamla daha kolay bütünleşiyor.
  - Yaygınlaşan haberleşme ağı: Kablosuz ve mobil ağlar (3G, 4G, 5G) her yerde. Bilgi işlem kaynakları sürekli birbiriyle iletişimde. Örnekler: mobil bankacılık, uzaktan çalışma, saatlik araç ya da skuter kiralama.
  - Bu eğilimler birbirini besler ve bir sinerji oluşturur. Ortaya çıkan etki, parçaların tek tek etkilerinin toplamından büyüktür.
  - Özgür ve açık kaynak yazılım:
    - Açık kaynak yazılımda (open source) kaynak kodu herkes inceleyebilir, ama kullanım lisans kurallarına bağlıdır. Farklı lisanslar farklı izinler verir (ör. ticari gelir elde edilmiyorsa değiştirip kullanma, değişiklikleri toplulukla aynı lisansla paylaşma şartı).
    - Firmalar açık kaynak bileşenleri birleştirip arada kendi ara katman yazılımlarını yazarak kurumsal çözümler sunabilir.
    - Açık kaynak projeleri "gevşek bir ekip" tarafından geliştirilir: farklı yaş, kültür ve zaman dilimlerinden kişiler, paralel çalışmak zorunda olmadan, sürüm sürüm katkı yapar.
    - Bu yüzden iyi tasarım, kodlama standartları ve eksiksiz, güncel teknik belgelendirme çok daha önemlidir. Açık kaynak bir yazılımın kalitesinde belirleyici etken, hızlı yanıt veren ve belgelendirmeyi sağlam tutan bir topluluğun olmasıdır.
  - Ayrıca: takım çalışması zorunluluğu, küreselleşme, ekonomik krizler.
    - Takım çalışması: Yazılım artık tek kişinin işi değil. Çok disiplinli ekipler ve konu uzmanları birlikte çalışır.
    - Küreselleşme (ekonomik ve lojistik anlamda): Alt bileşenler dünyanın her yerinden temin edilebilir, tedarik zinciri yönetimi önem kazanır. Yazılım ihraç edilirse farklı dillere, kanunlara, mevzuata ve pazar eğilimlerine uyum gerekir. Ekipler de çok uluslu olabilir.
    - Ekonomik krizler: Kurumlar tasarrufa ilk önce bilgi işlem departmanından ve yazılım projelerinden başlar. Öte yandan aynı işi daha verimli ve ucuza yapan yazılımlar üreten firmalar bu dönemlerde avantaj kazanır.
- Yazılım hakkındaki yanılgılar: müşteri açısından (ekrandan, 00:40:00)
  - "Amaçları genel olarak belirlemek yeter, ayrıntılar sonra kararlaştırılır, nasıl olsa yazılım esnektir." Belirsiz gereksinimler çürük atılmış temele benzer.
  - "Yazılım esnektir, değişen gereksinimler kolayca uyarlanır." Yazılım yaşam döngüsünde ilerledikçe değişiklik yapmanın bedeli üstel olarak artar.
  - Sonuç: Yazılım oyun hamuru gibi değil, kil ya da cam gibi esnektir. Çevik süreçler esnekliği artırmayı hedefler.
  - Yazılımın başarısı: önceden belirlenen süre içinde, önceden belirlenen bütçeyle, önceden belirlenen bütün işlevleri karşılamak.
- Yazılım hakkındaki yanılgılar: programcı açısından (ekrandan, 00:45:00)
  - "Yazılımı teslim edince işimiz biter." Çabanın yarısından fazlası ilk teslimattan sonra, bakım aşamasında harcanır.
  - "Yazılımı tamamlamadan kalitesini ölçemem." Kalite güvence yöntemleri yaşam döngüsünün her aşamasında uygulanabilir. Çözümleme aşamasında bile kullanılabilecek kalite ölçütleri vardır.
  - "Yazılım eşittir program." Gereksinim analizi, belgelendirme, sınama ve tümleştirme (entegrasyon) de başlı başına emektir.
  - "Yazılım mühendisliğinin gereklerini uygulayarak boşuna çaba harcıyoruz." Haritası olmayan yolunu kaybeder. Kalite için harcanan çaba ileride fazlasıyla geri döner. Küresel ölçekte projelerin yaklaşık %50'si başarısız olur.
- Yazılım projelerinin başarı oranları (ekrandan, 00:55:00 ve 01:00:00)
  - Başarılı (yeşil): süre, bütçe ve işlevin üçü de tutturulmuş. Zorlanılmış (sarı): bu üç yönden en az birinde başarısızlık. Başarısız (kırmızı).
  - Geleneksel ve ad hoc süreçlerde tam başarı yaklaşık %50, çevik, yinelemeli ve yalın süreçlerde daha yüksek.
  - Türkiye'de çevik projelerin başarı oranı anketinde (35 yanıt) %75 ve üstü başarı %31, %50 ve üstü başarı %68'dir.
- Yazılım hakkındaki yanılgılar: idari açıdan (ekrandan, 01:20:00)
  - "İşler yetişmiyorsa takıma yeni programcılar ekleriz." Yeni elemanların yazılıma hakim olması üstel olarak zorlaşır, işler daha da gecikir.
  - "Yazılımı tamamen ya da kısmen fason yaptırırım." İlerlemesini kendi içinde denetleyemeyen firma dışarıya verdiği işi hiç izleyemez.
  - "Açık kaynak yazılım üretirsem kâr edemem." Danışmanlık, bakım ve hizmet anlaşmalarıyla kâr edilebilir. Başka iş modelleri de vardır.
- Yazılım süreçlerinin genel adımları (ekrandan, 01:30:00)
  - Çözümleme (Analysis), Tasarım (Design), Gerçekleme (Implementation), Sınama (Testing), Bakım (Maintenance).
  - Çözümleme: Bir şeyi anlayabilmek için parçalarına ayırmak. Gerçeklenecek sistemi anlamaya yönelik çalışmalar (uygulama alanı, kullanıcı gereksinimleri, program parçaları arasındaki üst düzey ilişkiler) ve üst düzey planlama (süre, maliyet, adam-ay, kaynaklar). "Bir sorunu anlamadan çözemezsiniz."
  - Tasarım: Çözümlemede "ne" yapılacağı, tasarımda "nasıl" yapılacağı belirlenir. Sorun "kağıt üzerinde" (aslında teknik belgelendirme araçlarıyla) çözülür. Yazılımda tasarım şemaları (NYP'de UML şemaları), elektronikte devre şemaları, mimaride kat planlarıyla eşleşir.
  - Gerçekleme: Tasarım bir programlama diliyle kodlanır. Tasarım, seçilen programlama yaklaşımı düşünülerek yapılır.
  - Sınama: Hataların kökeni çoğu zaman gereksinim ya da tasarım aşamasına uzanır. Bu yüzden sınamaya erken başlanmalı ve sık yapılmalı, bunu kolaylaştıran süreç ve araçlar kullanılmalıdır.
  - Bakım (ekrandan, 01:40:00): Yazılım faaliyete geçtikten sonraki değişiklikler. Kodlama, tasarım (!) ve gereksinim-analiz (!!) hatalarının düzeltilmesi, işlev ekleme/çıkarma, farklı ortama taşıma (programlama dili, işletim sistemi, donanım, iklim; porting).
  - Yeniden mühendislik (refactoring, software reengineering) de bakım etkinliğidir: Yazılımın işlevlerini ve arayüzlerini değiştirmeden iç yapısını değiştirmek. Tersine mühendislikle karıştırılmamalıdır.
- CASE sistemleri (ekrandan, 01:45:00, 01:50:00, 01:55:00)
  - CASE (Computer Aided Software Engineering): Yazılım mühendisliği görevlerinin bilgisayar yardımıyla "otomatik" (ünlemli) gerçekleştirilmesi. Avrupa'da IPSE (Integrated Programming Support Environments, bütünleşik programlama desteği ortamı) adı da verilir.
  - Üç öğe: işlemler (süreci düzenleyen yöntem bilimi), yöntemler (standart tasarım teknikleri ve yöntemleri), bütünleşik otomatik yazılım geliştirme araçları. Bilgiler ve her basamağın sonuçları ansiklopedik arşivde saklanır.
  - Bölümler: üst CASE (diyagram çizimi ve tanımlama araçları, iş mantığını betimler), orta CASE (sistem analizi ve tasarımı), alt CASE (kod üretimi, kod çevirici). Orta ve alt bölümlerde ölçüm, belgelendirme ve hata ayıklama araçları da otomatik çalışır.
  - Ansiklopedik arşiv: fonksiyonlar, işlevler, veri modelleri, veri sözlüğü.
  - İş süreci modelleme standartları: BPMN ve BPEL.
  - CASE kalıcı yaygınlık kazanmadı. Bugün takım odaklı bütünleşik geliştirme ortamları (Azure DevOps, IBM Rational) yaygındır.
- Dördüncü kuşak teknikleri (ekrandan, 02:05:00)
  - Dil kuşakları: 1. makine dili, 2. assembly, 3. BASIC, Pascal, Fortran, C, C++, Java gibi diller, 4. 4GL.
  - 4GL dilleri doğal dile ya da problem alanına yakındır. 4GT gereçleri şema ve akış diyagramı gibi gösterimlerden kaynak kod üretir. Şema ile kod arasında çift yönlü dönüşüm vardır.
  - Örnekler: SQL, ERP platformlarının kendi 4GL dilleri.
  - Programlama bilmeyen konu uzmanlarının sisteme müdahalesini vaat eder, ama algoritmik düşünme yeteneği yine gereklidir. Bugün yalnız bazı özel alanlarda sınırlı kullanılır.
- Yazılım geliştirme süreç modelleri
  - Süreç: önceden belirlenmiş adımlardan oluşan iş akışı. Süreç modeli bu adımları ve yapıyı belirler. Her modelin artı ve eksileri vardır. Projeye en uygun modeli seçmek mühendisin sorumluluğudur.
  - Şelale (ardışıl, klasik) modeli (ekrandan, 02:30:00): Çözümleme → Tasarım → Kodlama → Sınama → Bakım. Bir adım bitmeden diğerine geçilmez. Hata bulununca bir önceki adıma dönülür.
  - Ön ürün (prototip) modeli (ekrandan, 02:40:00): Müşteriyi dinle → ön ürün oluştur → müşteri dener → tekrar dinle. Müşteri memnun olana kadar döngü sürer.
  - Hızlı uygulama geliştirme (RAD) (ekrandan, 02:45:00): Kısa geliştirme çevrimlerine dayanan artımsal model. Yaklaşık 3 aylık, birbirine az bağımlı ve paralel yürütülebilen bölümler gerekir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Temel dinamik: Yaşam döngüsünde ilerledikçe değişiklik ve hata düzeltme maliyeti üstel olarak artar.
  - Hoca bunu x ekseni zaman, y ekseni maliyet olan bir grafikle çizdi (ekrandan, 00:40:00). Bütün yanılgıların kökü bu dinamiği bilmemektir. Ders boyunca bu nokta defalarca tekrarlandı.
- Sosyal yetenekler ve takım çalışması
  - Bilgisayar mühendisi yalnız bilgisayarla değil insanlarla da çalışır. Bireysel oyuncu değil takım oyuncusu olmak gerekir.
- Takıma eleman eklemek gecikmeyi çözmez
  - Süre yetişmiyorsa ya bazı işlevlerden vazgeçilir ya da süre uzatılır.
- Yazılım yalnız koddan ibaret değildir
  - Teknik ve son kullanıcı belgelendirmesi yazılımın önemli bir parçasıdır. Kodlayan ve bakımı yapan ekipler farklı olabildiği için eksik belgelendirme bakım maliyetini çok artırır.
- Rapid Application Development bir süreçtir, ürün değildir
  - 1990'lar ve 2000'lerde Visual Basic, Delphi, C++ Builder gibi sürükle bırak ortamları "RAD aracı" diye pazarlandı. Bunlar RAD sürecinde kullanılabilir, ama RAD'ın kendisi değildir.
- Prototip kodu atılmalıdır
  - Prototip başlı başına model olarak kullanılmamalı, olgun bir modelin analiz aşamasında gereksinim belirleme aracı olmalıdır. Tercihen nihai üründen farklı bir dil ya da platformda yazılır.
- Kavramların İngilizce karşılıklarını bilmek gerekir
  - Güncel ve kapsamlı literatür büyük ölçüde İngilizcedir.

## Kısa Tekrar Notları

- Yazılımı etkileyen eğilimler: yaygın bilgi işlem, yaygın haberleşme ağı, özgür/açık kaynak yazılım, takım çalışması, küreselleşme, ekonomik krizler.
- Açık kaynak ile özgür yazılım aynı şey değildir. Açık kaynakta kod incelenebilir ama lisans kuralları vardır.
- Gevşek ekip → belgelendirme ve kodlama standartları daha da önemli.
- Başarı = süre + bütçe + işlev. Biri eksikse "zorlanılmış başarı".
- Projelerin yaklaşık yarısı tam başarıya ulaşamaz. Çevik süreçlerin başarı oranı geleneksel süreçlerden yüksektir.
- Değişiklik maliyeti zamanla üstel artar. Yazılım kil ya da cam gibidir.
- Çabanın yarıdan fazlası bakımda harcanır.
- Kalite güvence bir şemsiye etkinliktir, her aşamada uygulanır.
- Geciken projeye eleman eklemek gecikmeyi artırır.
- Açık kaynak yazılımla danışmanlık ve bakım anlaşmaları üzerinden kâr edilir.
- Genel adımlar: çözümleme (ne?), tasarım (nasıl?), gerçekleme, sınama, bakım.
- Yeniden mühendislik: işlev değişmeden iç yapı değişir. Tersine mühendislik: hazır ürünü inceleyip benzerini üretmek.
- CASE: üst (diyagram), orta (analiz/tasarım), alt (kod üretimi) bölümler ve ansiklopedik arşiv.
- 4GL: doğal dile yakın dil, 4GT: şemadan kod üreten gereç, çift yönlü dönüşüm, ör. SQL.
- Şelale: sıralı, iyi tanımlı, ama ürün geç çıkar, rutin projelere uygun.
- Prototip: gereksinimleri iyi çıkarır, ama olgunlaşmadan kullanıma alınma riski var ("build and fix").
- RAD: 3 aylık paralel bölümler, yüksek teknik riske uygun değil, prototiplemede ya da fikirleri başka süreçlere aktararak kullanılır.

## Detaylı Açıklamalar

- Değişiklik maliyetinin üstel artışı neden bu kadar önemli? Analiz aşamasında bir kullanım durumu (use case) şemasına yeni bir elips eklemek ya da bir aktörün ilişkisini başka bir kullanım durumuna taşımak birkaç tıklamalık iştir. Aynı değişiklik tasarıma, sonra koda geçildikten sonra yapılmak istenirse çok daha fazla iş gerektirir. Hoca bunu kil ve cam benzetmesiyle anlattı. Oyun hamuruna her an istediğiniz şekli verebilirsiniz. Kil ya da cam ise ancak işlenirken şekil alır, sertleştikten sonra yalnız kozmetik değişiklik (boyama gibi) yapılabilir. Şekli değiştirmek için seramiği kırıp yeni malzemeyle baştan başlamak, camı ise yeniden eritmek gerekir. Yazılım da düşünüldüğü kadar esnek değildir.
- Bakım aşamasının çabanın yarısından fazlasını alması üç kaynaktan gelir. Teslimattan önce ne kadar test yapılsa da bazı hatalar ancak sahada ortaya çıkar. Problem alanı, mevzuat ve müşterinin üst yönetiminin öncelikleri zamanla değişir. Bu değişiklikler de üstel maliyet eğrisinin ileri bir noktasında yapılır. Kodlayan ekiple bakım ekibinin farklı olması ve eksik teknik belgelendirme bu maliyeti daha da artırır.
- Takıma yeni programcı eklemek duvar örmeye benzemez. Bir işçinin on günde ördüğü duvarı on işçi bir günde örebilir, yazılımda bu orantı yoktur. Yeni katılan kişi o zamana kadar yapılanları öğrenmeden anlamlı katkı veremez. Gecikme de genelde projenin ikinci yarısında fark edilir, o noktada öğrenilmesi gereken bilgi birikimi çok büyüktür ve bu bilgiyi özümsemek doğrusal değil üstel biçimde zorlaşır. Eksik kısımların hazır ya da açık kaynak bileşenlerle karşılanması da düşük olasılıktır ve uyarlama çabası ayrıca risk getirir.
- Açık kaynak iş modeli: Linux dağıtımları ücretsizdir. Ama 7/24 çalışan, ayrıntılı raporlama ve anlık izleme gerektiren bir sistemde ölçek artırma ya da sorun giderme gibi işler için kurumun kendi kaynakları yetmeyebilir. O yazılımı en iyi bilen, onu üreten kurumdur. Bu yüzden bakım ve hizmet anlaşmaları yapılır, açık kaynak üreten firmalar da bu yolla düzenli gelir elde eder.
- Şelale modelinde belli bir anda proje yalnız bir aşamadadır. Diğer uzmanlar boş durmaz, örneğin tasarımcılar çözümleme çalışmalarını izler. Böylece tasarıma geçildiğinde çözümlemede alınan kararları bilirler. Tasarımda bir hata çözümlemeden kaynaklanıyorsa tasarım durdurulur, çözümlemeye dönülür, hata ve etkileri düzeltilir, sonra tasarıma geri gelinir. Artıları: en eski ve yaygın model, adımları iyi tanımlanmış ve belgelenmiş. Eksileri: müşteri çalışan bir ürünü ancak kodlamanın sonlarında görür, geri dönüşler ilerlemeyi geciktirir, müşteriler gereksinimlerini çoğu zaman eksiksiz ve kesin belirtemez. Sonuç: hiç model kullanmamaktan iyidir. Daha önce başarıyla yapılmış işlere benzeyen rutin projelere uygundur. Yeni bir problem alanında ya da Ar-Ge ağırlıklı projelerde dezavantajlıdır.
- Prototip modeli şelalenin "çalışan ürün geç çıkar" sorununa odaklanır. Kullanıcı ürünü erkenden dener ve neyin doğru, eksik ya da yanlış olduğunu projenin olabilecek en erken zamanında söyler. Ama ön ürün nihai ürün değildir. Zaman ya da maliyet baskısıyla müşteri "bu da idare eder" diyebilir ve olgunlaşmamış ürün kullanıma alınır. Bu, ürünün düzeltmenin en pahalı olduğu bakım aşamasına geçmesi demektir. Bu yüzden modele alaycı biçimde "build and fix" de denir. Doğru kullanım, prototipi başka bir modelin analiz aşamasında gereksinim belirleme aracı olarak kullanmak ve kodunu atmaktır. Hocanın örneğinde nihai ürün Java ile yazılacaksa ekran ve iş akışlarını göstermek için prototip .NET'in sürükle bırak araçlarıyla hızla hazırlanır. Farklı platformda olduğu için prototip kodunun nihai ürüne karışma olasılığı kalmaz.
- RAD modelinde ideal durumda 12 aylık bir iş 3 aylık 4 bağımsız bölüme ayrılıp paralel yürütülürse 3 ayda biter. Gerçekte problemler böyle bağımsız parçalara ayrılamaz, parçalar arası bağımlılık kazancı azaltır. Hoca gerçekçi kazancı %10-20 dolaylarında verdi (12 ay yerine yaklaşık 10 ya da 9 ay). Paralel bölümlerde çalışacak yeterli insan kaynağı da gerekir, her çalışan da bu hıza uyum sağlayamaz. Yüksek teknik riske uygun değildir: Bölümlerden biri çözülemeyen ya da makul sürede çözülemeyen bir sorunla karşılaşırsa diğer üç bölüm bitse bile ürün pazara zamanında çıkamaz ve proje pazar başarısızlığına uğrar. Hazır bileşenlerin (kara kutu olarak değiştirmeden kullanılabilen component'lerin) bulunması RAD'ı kolaylaştırır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
