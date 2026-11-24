# Ders 14 Çalışma Özeti

## Genel Konular

- Ölçme, ölçüt ve ölçüm kavramları
  - Ölçme (measuring): somut ya da soyut bir varlığın bir özelliğini sayısal veya derecelendirilmiş bir veri olarak ifade etmektir. Örnekler: bir kişinin boyunu santimetre ile söylemek, havanın 22 santigrat derece olduğunu söylemek, bir sınavın zorluğunu beşli Likert ölçeğiyle derecelendirmek (ekrandan, 00:10:00).
  - Ölçüt (metric): varlığın ölçülecek özelliğini ölçme biçimidir. Aynı mesafe Öklid (Pisagor) ölçütüyle ya da kuş uçuşu ölçütüyle; aynı sıcaklık santigrat ya da Fahrenhayt ile ölçülebilir.
  - Ölçüm (measurement): belli bir ölçüte göre yapılan ölçme eyleminin sonucudur.
  - Üç kavram isim, sıfat ve eylem olarak ayrılırsa karışmaz; İngilizcede (measuring, metric, measurement) karışıklık daha fazladır.
- Yorumlama engeli (intelligence barrier)
  - Ölçme sonucu aradığımız anlamlı sonuca doğrudan bir yol sunmayabilir ya da yorumlama zor olabilir.
  - Akış: varlıklar → (ölçme) → sayısal/derecelendirilmiş veriler → (matematik, istatistik) → sayısal sonuçlar → (yorumlama) → anlamlı sonuçlar (ekrandan, 00:15:00).
  - Örnek: Otostopçunun Galaksi Rehberi'nde süper bilgisayarın "hayatın anlamı" sorusuna verdiği "42" yanıtı.
  - Yazılımda yorumlama engeli yüksektir; ölçütler nitel ya da öznel kalırsa yorumlama daha da zorlaşır.
- Yazılımı neden ölçeriz?
  - Ürünün ne kadar iyi olduğunu anlamak, ne kadar iş yapılacağını, dolayısıyla ne kadar zaman ve para harcanacağını kestirmek.
  - Proje yönetimi için: ölçülemeyen ilerleme yönetilemez.
- Doğrudan ve dolaylı ölçüm
  - Doğrudan: gider, süre, komut satırı, hız, bellek genişliği, hata miktarı.
  - Dolaylı: işlev, nitelik, karmaşıklık, etkinlik, güvenilirlik, dayanıklılık.
  - Ortak amaç verimlilik, kalite, gider ve belgelemenin hesaplanmasıdır (ekrandan, 00:20:00).
- LOC tabanlı ölçütler (ekrandan, 00:20:00)
  - LOC: kod satırı sayısı; büyük yazılımlarda KLOC (bin satır) kullanılır.
  - Verimlilik = KLOC / (kişi × ay); Kalite = Hata / KLOC; Gider = Toplam gider / KLOC; Belgeleme = Belge sayfası / KLOC.
  - Ders sonrası not: Slaytta "KLOC = 1000 * LOC" yazıyor ve hoca da "bin çarpı" diye okudu; doğrusu 1 KLOC = 1000 LOC, yani KLOC = LOC / 1000.
- Fonksiyon noktası (FP, Function Point) yöntemi
  - Dolaylı bir ölçüm örneğidir; LOC'un dile bağımlılığına alternatif olarak önerilmiştir.
  - Tablo 1: beş bileşen (kullanıcı girişi, çıktı, sorgulama, kütük, dış arabirim) sayılır; her biri basit/orta/karmaşık ağırlık faktörüyle çarpılır, $FP_i = S \times AF$ toplanır (ekrandan, 00:25:00).
  - Tablo 2: 14 yazılım parametresi (ör. güvenli yedekleme ve geri yükleme, iletişim altyapısı, dağıtılmış işleme fonksiyonları) 0 (yok) ile 5 (en karmaşık) arasında puanlanıp toplanır ($\sum F_i$).
  - Formül büyük olasılıkla $FP = \sum FP_i \times (0{,}65 + 0{,}01 \times \sum F_i)$ biçimindedir. <!-- BELİRSİZ: formül slaytının karesi yok; altyazıda "toplam FP çarpı 0,65 ... sigma Fi" duyuluyor, 0,01 katsayısı duyulmuyor. -->
  - Sonra verimlilik, kalite, gider ve belgeleme ölçütlerinde KLOC yerine FP kullanılır.
- LOC ve FP kıyaslaması (ekrandan, 00:30:00)
  - LOC: programlama diline (kısmen) bağımlı; iyi tasarlanmış ama kısa yazılımları yeterince değerlendiremez; işlemsel olmayan dillere kolay uyarlanamaz.
  - FP: dilden bağımsız (artı); öznel; doğrudan fiziksel bir ölçüt değil; veri toplaması güç.
- Kalite ölçütü sınıflandırmaları
  - ISO 9126: işlevsellik, güvenilirlik, kullanılabilirlik, verimlilik, bakım kolaylığı, taşınabilirlik ve bunların alt başlıkları.
  - McCall: işlevsel ölçütler (doğruluk, güvenilirlik, bütünlük, kullanılabilirlik, verimlilik), değiştirme ölçütleri (bakım kolaylığı, esneklik, sınanabilirlik), taşınma ölçütleri (taşınabilirlik, yeniden kullanılabilirlik, birlikte çalışabilirlik).
  - İç/dış ayrımı: dış kalite ölçütleri yazılımı kullananları, iç kalite ölçütleri yazılımı geliştirenleri ilgilendirir. <!-- BELİRSİZ: bu ayrımı öneren yazarın adı altyazıda "MacDonald" diye geçiyor, slayt karesi yok. -->
- Dış kalite ölçütleri (ekrandan, 00:40:00)
  - Doğruluk, etkinlik, güvenilirlik (MTBF yüksek olmalı), güvenlik, bütünlük, uyarlanabilirlik, hassaslık, sağlamlık, kullanılabilirlik. Bu ölçütler örtüşebilir.
- İç kalite ölçütleri (ekrandan, 00:55:00)
  - Yeniden kullanılabilirlik, bakım kolaylığı, esneklik, taşınabilirlik, okunabilirlik, anlaşılabilirlik, sınanabilirlik.
- Ölçme ilkeleri
  - Ölçme beş adımlı bir süreçtir: tanımlama (formulation), toplama (collection), hesaplama (analysis), yorumlama (interpretation), geri besleme/kullanma (feedback) (ekrandan, 01:25:00).
  - Ölçütün arzu edilen özellikleri: anlamlı bir ölçekte olmalı (ör. 0-1 arası) ya da bir değerlendirme aralığı verilmeli; doğru ya da ters orantılı olmalı; deneysel olarak doğrulanabilmeli ve doğrulandıktan sonra kullanılmalı (ekrandan, 01:20:00).
- Nesneye yönelik ölçütler ve CK (Chidamber ve Kemerer) ölçütleri (ekrandan, 01:30:00)
  - WMC, DIT, NOC, RFC, CBO, LCOM.
  - RFC için: iyi [0,50], orta [51,100], kötü >100. LCOM için: iyi 0, orta [1-20], kötü >20.
- WMC ayrıntısı (ekrandan, 01:35:00)
  - $WMC = \sum_{i=1}^{n} c_i$; $c_i$, $M_i$ metodunun karmaşıklığıdır.
  - Eleştiri: metot karmaşıklığı neye göre belirlenecek, belirlemedeki öznellik güçlü yön mü zayıf yön mü?
  - Yüksek WMC: sınıfa fazla sorumluluk yüklenmiş olabilir, dağıtılmalı; uyuma tekrar bakılmalı; uygulamaya özeldir, yeniden kullanılabilirliği düşüktür.
- Diğer ölçütler ve "Ne yapılabilir?" (ekrandan, 01:40:00)
  - Bağlaşım: COMIAS, CBMC. Sınanabilirlik: Halstead ölçütleri (tartışmalı), Binder'in seçtiği ölçütler. Bakım kolaylığı: IEEE Std. 982.1-1998'de yazılım olgunluk ölçütü.
  - Ölçütler mükemmel değildir ama bir rehber olarak kullanılmalıdır; tabulaştırılmamalıdır.
- Kitaptan eşik değerleri ve görselleştirme
  - "Object-Oriented Metrics in Practice" kitabında 45 Java ve 37 C++ sistemi üzerinden eşik değerleri çıkarılmıştır (ekrandan, 01:50:00).
  - Sınıfları dikdörtgenlerle gösteren polimetrik görünümler, refactoring adaylarını bir bakışta bulmaya yarar (ekrandan, 01:55:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Ölçme, ölçüt ve ölçüm birbirine karıştırılmamalıdır.
  - Kitaplarda bile karıştırılabildiği için isim/sıfat/eylem ayrımıyla akılda tutulması önerildi.
- Güvenilirlik (reliability) ile güvenlik (security) karıştırılmamalıdır.
  - Türkçe adları birbirine yakın olduğu için özellikle uyarıldı. Güvenilirlik hataların seyrek olması (MTBF yüksek), güvenlik yetkisiz işlemlerin mümkün olmamasıdır.
- Yeniden kullanılabilirlik ile esneklik farklıdır.
  - Yeniden kullanılabilirlikte anahtar kelime "sistemin parçaları"dır; esneklikte yazılımın tamamı başka bir uygulama alanına taşınır.
- Uyarlanabilirlik, taşınabilirlik değildir.
  - Taşınabilirlik bir iç kalite ölçütüdür; uyarlanabilirlik dış kalite ölçütü olarak yapılabilecek uyarlama eylemleriyle ilgilidir.
- Okumak ve anlamak farklıdır.
  - Okunabilirlik yalnız kaynak kod düzeyindedir; anlaşılabilirlik bileşen ve sistem düzeyinde de geçerlidir.
- Ölçme tek başına bir şey kazandırmaz.
  - Kazanç, yorumların ardından gereken eylemleri (ör. refactoring) yürütmekten gelir.
- Ölçütler amaç değil araçtır.
  - "Mükemmel, iyinin düşmanıdır"; kusurlu bir ölçüt bile hiç kullanmamaktan iyidir.
- Ölçüm sonucunun sıfır çıkması şüphe uyandırmalıdır.
  - Ölçütün hesaplanamadığını ya da aracın bir hatasını gösterebilir; ikinci bir araçla ya da küçük sınıflarda elle sağlama yapılabilir.

## Kısa Tekrar Notları

- Ölçme = eylem, ölçüt = ölçme biçimi, ölçüm = sonuç.
- Yorumlama engeli: veri → sayısal sonuç → anlamlı sonuç geçişindeki zorluk; yazılımda yüksektir.
- Doğrudan ölçüm: gider, süre, LOC, hız, bellek, hata. Dolaylı ölçüm: işlev, nitelik, karmaşıklık, güvenilirlik.
- Verimlilik = KLOC/(kişi·ay), Kalite = Hata/KLOC, Gider = Toplam gider/KLOC, Belgeleme = Sayfa/KLOC.
- FP: 5 bileşen × ağırlık (Tablo 1) + 14 parametre 0-5 (Tablo 2); LOC'a göre dilden bağımsız ama öznel.
- Dış kalite = kullanıcıyı, iç kalite = geliştiriciyi ilgilendirir.
- MTBF: hatalar arasındaki ortalama süre; yüksekse sistem güvenilirdir.
- Ölçme süreci: tanımlama → toplama → hesaplama → yorumlama → geri besleme.
- CK ölçütleri: WMC, DIT, NOC, RFC, CBO, LCOM. LCOM düşük olmalıdır (uyum eksikliği).
- $WMC = \sum c_i$; metot karmaşıklığı için çevrimsel karmaşıklık (cyclomatic complexity) kullanılırsa öznellik ortadan kalkar.

## Detaylı Açıklamalar

- Ölçme ve yorumlama
  - Ölçmenin amacı gerçek dünyayla ilgili, işe yarayacak anlamlı sonuçlar elde etmektir. Basit durumlarda yorum kolaydır: iki kalemden daha kalın olanı pencereyi açık tutmak için destek yapmak, daha uzun olanı tavandaki bir düğmeye uzanmak için kullanmak gibi. Yazılım gibi karmaşık işlerde ise ölçme verileri önce matematiksel ve istatistiksel yöntemlerle sayısal sonuçlara çevrilir, sonra bu yöntemlerin verdiği ipuçlarıyla yorumlanır. Yazılım zihinsel yoğunluk gerektiren, zor problemleri çözen bir iş olduğu için yorumlama engeli yüksektir.
- Doğrudan ölçülen niceliklerden türetilen ölçütler
  - LOC'tan yola çıkarak verimlilik (KLOC/kişi·ay), kalite (bin satırdaki hata sayısı), gider (bin satır başına toplam masraf) ve belgeleme (bin satır başına belge sayfası) tanımlanır. Gider kalemlerine çalışan masrafı, lisans bedelleri, sunucu ve bulut (ör. Amazon Web Services) masrafları, amortisman gibi bütün kalemler eklenir. Belgeleme ölçütü bir masraf değil, belgelemeye verilen ağırlığın göstergesidir.
- LOC'un sorunları
  - Programlama diline bağımlıdır; farklı dillerde yazılmış projeleri kıyaslamak "elmalarla armutları karşılaştırmak" olur. Aynı dilde bile ölçüm belirsizdir: açılış parantezinin ayrı satıra yazılması, noktalı virgüllerin sayılıp sayılmaması, `for` döngüsünün başlık bölümlerinin nasıl sayılacağı gibi sorular vardır ve farklı araçlar LOC'u farklı hesaplayabilir. Bu nedenle mümkünse hep aynı "cetvel" ile ölçülmelidir. Böl-parçala-yönet yaklaşımıyla uzun bir metodu alt metotlara bölmek LOC'u artırır ama anlaşılırlığı yükseltir.
- FP'nin sorunları
  - Değerleri kimin, neye göre atadığı belirsizdir; kişinin deneyimine bağlıdır. Bu öznellik Delphi yöntemiyle azaltılabilir. Ayrıca girdi, çıktı, sorgu ve kütük sayıları ancak analiz tamamlanıp tasarım belli bir yere geldiğinde netleşir; bu yüzden ilk tahminler proje ilerledikçe tekrarlanıp netleştirilmelidir.
- Dış kalite ölçütlerinin örnekleri
  - Etkinlik: kaynakların verimli kullanımı toplam sahiplik maliyetini (total cost of ownership) düşürür, kaynak ve enerji israfını önler.
  - Güvenilirlik: MTBF, belli bir dönemdeki arızalar arasındaki doğru çalışma sürelerinin ortalamasıdır.
  - Güvenlik: "hırsıza kilit dayanmaz"; kırılamayan önlem yoktur ama kırılması yeterince zor olmalıdır. Tek kullanımlık parolayla (one time password) korunan bir para transferi işlemi birkaç dakikada biterken parolanın kırılması saatler sürüyorsa saldırgan işten geçtikten sonra bilgiyi elde etmiş olur.
  - Bütünlük: A hesabından B hesabına 1000 lira gidiyorsa sonunda A'dan 1000 lira eksilmiş, B'ye 1000 lira eklenmiş olmalıdır. Hareketin (transaction) bir alt adımı başarısız olursa sistem en son tutarlı duruma geri döndürülebilmelidir.
  - Hassaslık: para birimlerinde virgülden sonra iki basamak anlamlıdır, ama döviz kuru ve bankalar arası işlemlerde 8-10 basamağa kadar hassasiyet gerekir; pi sayısının kaç basamağının kullanıldığı çevre ve alan sonucunun gerçeğe yakınlığını belirler.
  - Sağlamlık: sistemin aynı anda kaç kullanıcıyı ya da saniyede kaç işlemi kaldırabildiğini ve nerede çalışmayı bıraktığını bilmek, donanım genişletme kararları için gereklidir.
  - Kullanılabilirlik: kullanılamayan yazılım erken terk edilir; değişime karşı direnç nedeniyle daha yetenekli bir sistem bile kullanıcıların ayak diremesiyle karşılaşabilir.
- İç kalite ölçütlerinin örnekleri
  - Bakım kolaylığı: yaşam döngüsünde ilerledikçe değişiklik maliyeti üstel artar ve toplam çabanın büyük kısmı bakım aşamasında harcanır.
  - Taşınabilirlik: Java, .NET, Python gibi sanal makine tabanlı ortamlar "bir yerde yaz, her yerde çalıştır" yaklaşımıyla geniş kitleye ulaşmayı kolaylaştırır. Aynı IDE, derleyici ve işletim sistemine sahip iki bilgisayarda aynı programın birinde çalışıp ötekinde çökmesi gibi durumlar taşınabilirlik sorunlarının ne kadar zor olabileceğini gösterir.
  - Sınanabilirlik: test güdümlü tasarımın temel savı, rahatça sınanamayan bir şeyin büyük ihtimalle doğru tasarlanmamış olduğudur.
- Ölçme süreci ve GQM
  - Tanımlama adımında önce literatürdeki hazır ölçütler kullanılır; yeni ölçüt ancak hiçbiri ihtiyacı karşılamıyorsa önerilir. Ölçüt, kullanılan yaklaşıma (ör. DIT yalnız nesneye yönelik yazılımda anlamlıdır) ve yazılımın türüne (gerçek zamanlı sistemde yanıt süresi, gömülü sistemde az kaynak kullanımı) uygun olmalıdır. Hangi ölçütün seçileceğine GQM (Goal-Question-Metric) yaklaşımıyla karar verilir. Toplama ve hesaplama mümkün olduğunca otomatik yapılmalıdır. Geri besleme adımında, ör. uzun metotlardan oluşan sınıfların metotları bölünür, fazla sorumluluk yüklenmiş sınıfların sorumlulukları yeni sınıflara dağıtılır.
- CK ölçütleri
  - CK ölçütleri en eski ve en çok geçerleme çalışması yapılmış nesneye yönelik ölçütlerdir. Bağlaşım ölçütleri analiz aşamasının sonundaki sınıf şemasından itibaren hesaplanabilir; ölçüm değerleri tasarım değiştikçe değişeceği için proje boyunca izlenmelidir. LCOM uyum eksikliğini ölçtüğü için düşük olması iyidir. LCOM'un tanım belirsizlikleri nedeniyle hem Chidamber ve Kemerer hem de başka araştırmacılar alternatif sürümler önermiştir.
- WMC'nin yorumu
  - Metot karmaşıklığını kişiye göre belirlemek öznellik getirir; hoca bu öznelliği zayıf yön olarak görür ve kaynak koddan somut olarak hesaplanan çevrimsel karmaşıklığın (beyaz kutu bir ölçüt) kullanılmasını önerir. WMC için kesin bir iyi/kötü aralığı yoktur; aynı proje içinde göreceli değerlendirilir ve refactoring için ayrılan zamanda en yüksek WMC'li sınıflardan başlanır. Bazı problem alanlarında (ör. karmaşık hesaplamalar gerektiren uygulamalar) WMC'nin yüksek olması doğaldır.
- Geçerleme sorunu
  - Akademisyenler ölçüt önermeyi sever ama geçerleme çalışmaları zordur; yazılım şirketleri kaynak kodlarını açmaktan ve kalite değerlerinin kötü çıkmasından çekinir. Firma adı gizlense bile az sayıda üreticinin olduğu bir alanda firma tahmin edilebilir. Açık kaynak projeler bir alternatiftir ama dinamikleri ticari yazılımlardan farklıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
