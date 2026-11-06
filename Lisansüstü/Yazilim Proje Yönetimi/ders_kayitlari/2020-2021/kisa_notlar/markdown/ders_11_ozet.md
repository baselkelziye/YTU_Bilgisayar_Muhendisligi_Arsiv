# Ders 11 Çalışma Özeti

## Genel Konular

- Ders 25 Mayıs 2021'de yapıldı.
- Dersin başında hoca online sisteme tanımladığı üç ödevi açıkladı.
- Dersin geri kalanı öğrencilerin makale sunumlarıyla geçti. Beş sunum yapıldı:
  - 1. sunum: büyük ölçekli sistemlerde yazılım risk yönetimi tekniklerinin eleştirel analizi.
  - 2. sunum: kazanılan plan (earned schedule), kalite ve riskin kazanılan değer yönetimine (Earned Value Management, EVM) entegrasyonu.
  - 3. sunum: graf renklendirme (graph coloring) ile kaynak planlama ve çatışma yönetimi.
  - 4. sunum: küresel yazılım geliştirmede (global software development) proje yönetimi risklerini bütünleştiren bir çerçeve.
  - 5. sunum: dağıtık ekiplerde çevik (agile) ve Scrum kullanımı.
- Dersin sonunda hoca vize sonuçlarını ve uygulama projesindeki birim test (unit test) beklentisini açıkladı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Online sistemde üç ödev tanımlandı:
  - Makale sunum dosyası. Daha önce sunum yapanlar da yüklemeli.
  - Sunulan konunun IEEE formatında 4-5 sayfalık yazılı makalesi. Son haftaya tanımlandı.
  - Uygulama projesi.
- Sunum dosyalarının yükleme tarihi 26 Mayıs olarak tanımlandı. Bir öğrencinin aktardığına göre saat 17.15.
- Hoca not vermeye zaman kalsın diye teslimlerin önceden yapılmasını istiyor.
- Slaytlar uzun metin blokları olmamalı. Makaleyi okur gibi sunulmamalı. Kısa maddeler ve hatırlatıcılar kullanılmalı, sunucu konuyu özetleyerek anlatmalı.
- Sunum başında hangi makalenin, hangi yıl ve hangi dergi ya da konferansta yayımlandığı gösterilmeli. Hoca 3. sunumda bunu yapılmasını olumlu buldu.
- Sunum planlaması e-postayla değil derste yapılır. Hoca bu yüzden sunum sırasıyla ilgili e-postalara cevap vermedi.
- Kazanılan değer yönetimi derste fizibilite analizinde, ekonomik fizibilite kavramları arasında geçmişti.
- Ekonomik göstergeler (kazanılan değer vb.) üzerine sunum yapan az olmuş. Çoğu sunum başka konularda toplanmış.
- Uygulama projesinde:
  - Öğrenci üzerinde çalışacağı yazılımı kendisi seçer, kodunu kendisi yazmaz.
  - Seçilen yazılımın kaynak koduna erişebilmeli. Bu kod üzerinde en az bir birim test örneği hazırlanmalı.
  - Bir gereksinim belgesi hazırlanmalı.
  - Konu daha önce bildirilmediyse e-posta atmaya gerek yok.

## Kısa Tekrar Notları

- Risk yönetimi süreci: risk tanımlama, analiz, önceliklendirme, azaltma planlaması, izleme ve raporlama, iletişim ve geri bildirim, belgeleme.
- Büyük ölçekli sistemlerde risk: bileşenler karmaşık ve birbirine bağımlı, gereksinimler sık değişir.
- EVM'nin üç temel bileşeni:
  - Planlanan değer (Planned Value, PV): değerlendirilen zaman için ayrılan bütçe.
  - Kazanılan değer (Earned Value, EV): yapılan işin bütçelenmiş maliyeti.
  - Gerçekleşen maliyet (Actual Cost, AC): yapılan işin gerçek maliyeti.
- Göstergeler:
  - $CV = EV - AC$, $CPI = EV / AC$.
  - $SV = EV - PV$, $SPI = EV / PV$.
  - Fark pozitif veya oran 1'den büyükse proje bütçenin altında ya da planın ilerisindedir.
- Klasik EVM'nin zayıflıkları: proje sonuna doğru zaman göstergeleri bozulur, kalite ölçüsü yoktur, tek risk ölçüsü vardır.
- Graf renklendirmede komşu iki düğüm aynı rengi alamaz. En az renk sayısı kromatik sayıdır.
- Kaynak çatışması grafında kromatik sayı ne kadar küçükse bekleme turu o kadar azdır.
- Leavitt'in organizasyonel değişim modeli: görev, yapı, teknoloji, aktörler (insanlar).
- Dağıtık ekiplerde Scrum of Scrums, farklı saat dilimlerindeki ekiplerin ortak bir zamanda bilgi paylaşmasını sağlar.
- Vize notları 68 ile 100 arasında.

## Detaylı Açıklamalar

### Ödevler ve teslimler

- Son iki hafta uygulama projeleri için ayrılmıştı. Önceki haftalarda makale sunumlarının bitmesi planlanmıştı.
- Hoca uygulamaların sınıfta kısa kısa anlatılmasına karar verdiğini söyledi.
- Bu hafta sunuma yetişemeyenler önümüzdeki hafta sunabilir. Ama sunum dosyası tanımlanan tarihte sisteme yüklenmeli.
- Sunumunu önümüzdeki haftaya erteleyen bir öğrenciden, dosyasını yine de ertesi gün yüklemesi istendi.

### 1. sunum: büyük ölçekli sistemlerde yazılım risk yönetimi

- **Konu:** büyük ölçekli sistemlerde yazılım risk yönetimi tekniklerinin eleştirel analizi. Makale Yıldız Teknik Üniversitesi kütüphanesinden seçilmiş. Sunucu dergi adını hatırlayamadı.
- **Temel kavramlar:**
  - Risk yönetiminin amacı riskleri oluşmadan önce tespit edip kontrol altına almaktır.
  - Riskler sistematik (genel) ve sistematik olmayan (spesifik) diye ayrılır.
  - Risk türlerine örnekler: virüsler, hackleme, veri kaybı.
- **Büyük ölçekli sistemler:**
  - Temel sorunlar: yönetilemezlik, uygun gereksinimlerin olmaması, gereksinimlerin sık değişmesi.
  - Araştırmacılar sistemin karşılıklı bağımlılığına, riskin bileşenler arasında geçişine ve uzun geliştirme sürelerine odaklanıyor.
  - Sistemi küçük parçalara bölmek riski azaltır.
- **Risk değerlendirme çerçevesi:** risk tanımlama, kategorize etme ve önceliklendirme, etki hesabı, yüksek etkili risklerin analizi, azaltma planı, izleme ve raporlama. Yeni boşluk bulunursa süreç tanımlamadan yeniden başlar.
- **Karşılaştırılan modeller:**
  - SRE (Software Risk Evaluation): risk tespiti ve analizi için uygun. Yalnız ekip üyelerini içerir, tüm paydaşları kapsamaz.
  - TRM (Team Risk Management): tüm bireylerin ve paydaşların katılımıyla sürekli bir döngüde riskleri yönetir.
  - SoftRisk: belgelemeye dayanır, büyük kayıplara yol açan risklere öncelik verir. Grafik ve renk kodlaması kullanır (yüksek risk kırmızı, düşük risk yeşil).
  - Riskit: nitel risk analizine dayanır ve tüm paydaşları içerir. Bu da başarısızlık nedenlerini azaltabilir.
- **Önerilen yöntem:** riskler kullanıcı, gereksinim, planlama, analiz, tasarım, uygulama ve bakım seviyelerine ayrılır.
  - Üst yönetim rol ve sorumlulukları yeteneklere göre atar.
  - Kuruluşa uygun risk azaltma modelini üst yönetim seçer.
  - Sözleşmeler ve yasal belgeler hazırlanır.
  - Kullanıcı seviyesindeki riskler (düşük katılım, yeni teknoloji bilgisinin yetersizliği) için kullanıcılar eğitilir ve iletişim planları yapılır.
  - Gereksinim seviyesindeki riskler gereksinim yönetimiyle ele alınır. Müşteriden düzenli geri bildirim alınır.
  - Risk azaltmadan sonra risk değerlendirmesi düzeltilir: kontrol önlemleri gözden geçirilir, yeniden planlanır, belgeler güncellenir.
  - Tüm sürece nitel (grafik, çizelge) ve nicel (anket, mülakat) analiz uygulanır.
- **Sonuç:** her modelin farklı özellikleri var ve farklı ortamlarda uygulanabilir. Karşılaştırma tablosu kuruluşa uygun modeli seçmeye yardım eder.
- **Hocanın geri bildirimi:** slaytlarda çok uzun metin var ve sunum okunarak yapılıyor. Önemli noktalar özetlenmeli. Planlama, analiz ve tasarım seviyelerindeki riskler derste görüldüğü için atlandı.

### 2. sunum: kazanılan plan, kalite ve riskin EVM'ye entegrasyonu

- **Makale:** 2019, IEEE dergisi. İki öğrenci sundu.
- **Klasik EVM:**
  - Projenin mevcut durumunu ve ilerleyişini zaman, maliyet ve kapsam açısından ölçen bir performans ve geri bildirim aracıdır.
  - Maliyet varyansı $CV = EV - AC$: pozitifse proje bütçenin altında, sıfırsa bütçeye uygun, negatifse bütçenin üzerindedir.
  - Maliyet performans endeksi $CPI = EV / AC$: 1'den büyükse bütçenin altında, 1'e eşitse uygun, 1'den küçükse bütçenin üzerindedir.
  - Zaman çizelgesi varyansı $SV = EV - PV$: pozitifse planın ilerisinde, negatifse gerisindedir.
  - Zaman çizelgesi performans endeksi $SPI = EV / PV$: 1'den büyükse planın ilerisinde, 1'den küçükse gerisindedir.
  - Örnek grafikte AC, EV'nin üzerinde olduğu için proje bütçeyi aşmış. PV, EV'nin üzerinde olduğu için proje planın gerisinde.
- **Klasik EVM'nin zayıflıkları:**
  - Proje ilerledikçe zaman göstergeleri bozulur. Proje sonunda $EV$ ile $PV$ eşitlenir ve $SV$ sıfır olur. Proje gecikmiş olsa bile zamanındaymış gibi görünür.
  - Kalite maliyetleri ve ölçülmemiş risklerin maliyetleri gösterilmez.
  - Tek risk ölçüsü tamamlanmadaki varyanstır (Variance at Completion). Maliyet, zamanlama ve performans riskleri ayrı ayrı görülmez.
  - Kalite metrikleri yoktur. Kalite gereksinimleri karşılanmazsa yeniden çalışma (rework) maliyeti ve süresi doğar.
- **Önerilen model:** kazanılan plan, kalite ve risk ölçütleri eş zamanlı olarak EVM'ye eklenir. Sunuculara göre literatürde bunu eş zamanlı yapan başka çalışma yok.
  - Zaman ölçütleri:
    - Planlanan süre: kilometre taşlarını tamamlamak için beklenen toplam süre.
    - Gerçek zaman: projenin o ana kadar sürdüğü toplam süre.
    - Kazanılan plan (earned schedule): $ES = C + I$. $C$ tamamlanan periyot sayısı, $I$ eksik periyodun tamamlanan kısmı.
    - Plan varyansı ve zamanlama performans endeksi bu süreler üzerinden hesaplanır. Varyans sıfırdan büyükse proje planın ilerisindedir.
  - Kalite ölçütleri:
    - Kalite gereksinimleri: her kilometre taşının çıktısı için planlama aşamasında paydaşlarca belirlenen özellikler. Net olmaları kapsam kaymasını (scope creep) önler.
    - Kalite indeks numarası: bir kilometre taşı çıktısındaki kalite gereksinimi puanlarının ortalaması.
    - Kazanılan kalite değeri: tamamlanan her kilometre taşının EV'si ile kalite indeks numarasının çarpımı. Kilometre taşı sürerken EV'ye eşit varsayılır.
    - Kalite varyansı: EV'nin yeniden işlenmesi gereken kısmı.
    - Kalite performans endeksi: yeniden çalışmalar hesaba katıldığında ilk seferde doğru yapılan işlerin oranı.
    - Tahmini yeniden çalışma maliyeti ve tahmini yeniden çalışma süresi etkisi. Yeniden çalışma gereken kilometre taşı kritik yolda değilse ve yeterli bolluk (slack) varsa bitiş tarihini etkilemez.
  - Risk ölçütleri:
    - Yeniden çalışma maliyeti etki oranı: maliyet etkisi bölü gerçekleşen maliyet. Maliyet etkisi, gerçekleşen yeniden çalışma maliyetinin kümülatif değeri ile tahmini yeniden çalışma maliyetinin toplamıdır.
    - Yeniden çalışma süresi etki oranı: zaman etkisinin gerçek süreye oranı.
    - Maliyet riski değeri ve zaman çizelgesi risk değeri: mevcut performansa göre projenin toplam maliyet ve zaman farkının ne olacağını ölçer.
    - Maliyet risk indeksi ve zaman çizelgesi risk indeksi: maliyet ve zaman riskinin ne kadar kritik olduğunu gösterir.
- **Hocanın geri bildirimi:** ekonomik göstergeler üzerine sunum yapan az olmuştu. Bu sunum bu açıdan farklı.

### 3. sunum: graf renklendirme ile kaynak planlama ve çatışma yönetimi

- **Makale:** IEEE, 2020'de Hindistan'da yapılan uluslararası bir teknoloji ve inovasyon konferansı bildirisi. İki yazarlı.
- **Problem:** bir kuruluş sınırlı kaynaklarla birden fazla proje yürütür. Aynı kaynağa birden fazla görev ihtiyaç duyar. Kaynakların yeniden tahsisi ve günlük iş gücü tahmini için doğru araçlar gerekir.
- **Graf teorisi temelleri:**
  - Königsberg köprüleri problemi: yedi köprünün her birinden yalnız bir kez geçerek başlangıç noktasına dönmek mümkün mü? Düğümler kara bölgelerini, kenarlar köprüleri gösterir.
  - Graf $G = (V, E)$: $V$ boş olmayan sonlu bir düğüm kümesi, $E$ düğüm çiftlerinden oluşan kenar kümesi.
  - Graflar ağırlıklı ve yönlü olabilir. Gezgin satıcı problemi, ağ ve devre tasarımı gibi alanlarda kullanılır.
  - Graf renklendirme: yönsüz bir grafın düğümlerini, komşu iki düğüm aynı renkte olmayacak şekilde en az renkle boyamak. En az renk sayısı kromatik sayıdır. Kromatik sayısı $k$ olan graf $k$-kromatiktir.
- **Literatür:** Goldratt'ın kritik zincir proje yönetimi (Critical Chain Project Management, CCPM), karınca kolonisi optimizasyonu, zaman çizelgesi planlama teknikleri.
- **Terimler:** planlama, görev planı, proje yönetimi, kaynak yönetimi, kritik yol yöntemi (Critical Path Method, CPM).
  - PMI'ya göre proje yönetimi aşamaları: başlatma, planlama, yürütme, izleme ve kapanış.
  - Kritik yol: projenin bitiş tarihine kadar tamamlanması gereken en uzun aktivite dizisi. Kritik yoldaki bir aktivite, öncülü bitmeden başlayamaz.
- **Önerilen yöntem:**
  - Her takım ya da görev bir düğümle gösterilir.
  - İki görev aynı kaynağa ihtiyaç duyuyorsa aralarına kenar çizilir ve farklı renk almaları gerekir.
  - Düğüm ağırlıkları görev önceliğini gösterir.
  - Gerektiğinde bir görevden kaynak çıkarılarak ya da göreve kaynak eklenerek çatışma çözülür.
- **Örnek:**
  - Yedi takım (A-G) ve onların ihtiyaç duyduğu kaynaklar var. Bazı kaynaklar birden fazla takımda yer alıyor; örneğin bir takım lideri birden fazla takımı yönetiyor.
  - Graf en az 4 renkle boyanabiliyor, kromatik sayı 4. Proje en az 4 turda yürütülebilir.
  - Bir takım lideri dört takımda yer aldığı için aşırı yükleniyor. D takımından çıkarılınca grafın kromatik sayısı 2'ye iniyor. Proje 2 turda, daha az beklemeyle yürütülebiliyor.
- **Uygulama önerileri:** mevcut araçlara (örneğin Gantt şeması kullanan araçlara) ek bir API olarak ya da bağımsız bir uygulama olarak geliştirilebilir.
- **Sonuç:** yöntem çatışmaları daha iyi temsil ediyor. CPM, CCPM ve Gantt tekniklerini tamamlayabilir. Kromatik sayının düşürülmesi bekleme süresini büyük ölçüde azaltıyor. Görev ve öğe sayısı arttıkça yöntem karmaşıklaşıyor.
- Hoca sunum sırasında kromatik sayının yol sayısı olup olmadığını sordu. Sunucu en az renk sayısı olduğunu açıkladı.

### 4. sunum: küresel yazılım geliştirmede proje yönetimi riskleri

- **Makale:** 2016, proje yönetimi alanında bir konferans bildirisi. Yayın yerinin adı altyazıda bozuk geçiyor.
- **Küresel yazılım geliştirme:** paydaşların zaman, coğrafya ve sosyo-kültürel açıdan dağıldığı yazılım üretimi. Şirketler bunu maliyeti ve teslim süresini azaltmak, müşteriye yakın olmak ve esnek kalmak için benimser.
- **Amaç:** proje yönetimi faaliyetlerindeki zorlukları belirlemek ve bunları kapsayan bütünleştirici bir çerçeve sunmak.
- **Yöntem:**
  - Sistematik literatür incelemesi (arama stratejisi, çalışma seçimi, veri çıkarma ve analiz) ile 39 risk faktörü belirlenmiş.
  - Risk, bir olayın gerçekleşme olasılığı ile proje üzerindeki etkisinin birleşimi olarak tanımlanmış.
  - Riskler Leavitt'in organizasyonel değişim modeline göre sınıflandırılmış. Model dört bileşenden oluşur: görev, yapı, teknoloji, aktörler. Bir bileşendeki değişiklik diğerlerini de etkiler.
  - Bileşen çiftleri arasındaki karşılıklı bağımlılıklardan altı kategori çıkarılmış.
- **Kategoriler:**
  - Görev-aktör: dil ve terminoloji farkları, bilgi seviyesi farkları, etkisiz iletişim, gerçek zamanlı iletişim kuramama, görev belirsizliği, kötü belgeler, sınırlı deneyim.
  - Görev-yapı (en çok risk faktörü bu kategoride): zamansal ve coğrafi dağılım, zayıf risk ve kalite yönetimi, sürümlerin ve izlenebilirliğin kötü yönetimi, sınırlı yüz yüze etkileşim, yetersiz ayrıntılı planlama, belirsiz roller, etkisiz koordinasyon, yetersiz izleme ve kontrol, yasal konuların kötü yönetimi.
  - Görev-teknoloji: araçların uyumsuzluğu, tüm yaşam döngüsünü kapsayan araçların eksikliği.
  - Aktör-yapı: kültürel çeşitlilik, çalışma kültürü farkları, kültürel önyargı, çatışma yönetimi, iş kaybı korkusu.
  - Aktör-teknoloji: iletişim ve iş birliği araçlarında eğitim eksikliği, araçları kullanmada sınırlı deneyim.
  - Yapı-teknoloji: uygun olmayan bilgi ve iletişim teknolojisi seçimi, zayıf iş birliği altyapısı, ağ güvenliği ve yetkisiz erişim.
- **Sonuç:** çerçeve yalnız risk tanımlama için temel oluşturur ve her projeye uyarlanmalıdır. Gelecekte aynı yöntemle risk azaltma stratejileri çerçevesi geliştirilebilir.

### 5. sunum: dağıtık ekiplerde çevik ve Scrum

- **Konu:** ofiste bir arada olmayan, farklı şehir, ülke ve kıtalardaki (Amerika ve Avrupa) ekiplerde çevik ve Scrum ile proje yönetimi. Çalışma pandemiden önce yapılmış.
- **Ön çalışma:** PMI raporlarında 23 kuruluştan 4 yıl boyunca düzenli raporlar incelenmiş.
  - Kendi kendine oluşan, öz sorumluluğu olan takımlar daha iyi sonuç veriyor.
  - Deneyimli üyelerin çevik yöntemi yeni üyelere aktarması sonucu iyileştiriyor.
  - Proje yöneticisi ve Scrum Master dışında mentor, koordinatör, destekleyici ve kontrolör gibi roller de gerekiyor.
- **Tartışma noktaları:**
  - Yakın ve uzak lokasyonlardaki dağıtık çalışma.
  - Çoklu takım, çoklu iş modeli, çoklu lokasyon ve çoklu saat dilimi.
  - Çevik ile yinelemeli-artımlı (iterative-incremental) geliştirmenin karşılaştırılması.
  - Uzaktan çalışmada öne çıkan sorunlar: projenin amacının eksik belirlenmesi, karar süreçlerinin tanımsızlığı, projenin bağlamından kopması.
  - Takım büyüklüğü, iş yükünün bölgelere eşit dağıtılması, eşli programlama (pair programming), iş aktarımı, zaman ve kültür farkları.
- **Vaka:** ABD, Kanada ve Almanya'da paydaşları olan bir yıllık bir telekom projesi.
  - Müşterinin gönderdiği GUI ön tasarımlarının 2 haftada olgunlaşması bekleniyordu, eksik belgeler yüzünden 4 hafta sürdü. Bu sürede yeni fikirler de çıktı.
  - Plan: planlama 2 ayda, proje 8-12 ayda biter. Test, gözden geçirme ve bakım sonra gelir.
  - Ekip düzeni dağıtık ve kısmen dağınık (partially dispersed). Ekipler arası iletişim çoğu zaman alt gruplar üzerinden yürüyor.
- **Toplantılar:**
  - Her takım kendi günlük Scrum toplantısını yapıyor (15 dakika: dün ne yapıldı, bugün ne yapılacak, engel var mı).
  - Bazı haftalarda günlük toplantıdan sonra yarım saatlik bir backlog gözden geçirmesi eklenmiş.
  - Scrum of Scrums: farklı saat dilimlerindeki ekiplerin ortak bir zamanda bilgi aktarması ve kopukluğu önlemesi için.
  - Sprint planlama ve değerlendirme toplantıları ekiplerin ortak zaman diliminde yapılıyor.
- **İletişim etkinliği (PMI grafiği):** aynı lokasyonda yüz yüze ve beyaz tahta ile en yüksek etkinlik sağlanıyor. Bu mümkün değilse video konferans gerekiyor. Ayrıca yapılanların kaydı için kalıcı dokümantasyon gerekiyor.
- **Başarı oranları:** aynı lokasyondaki ekiplerde yaklaşık %79-80, yakın lokasyonda %73-74, uzak lokasyonda %55-59. Ortalama başarı yaklaşık %70.
- **Çıkarılan dersler:**
  - Dağıtık ekiplerin çevik çalışmaya alışkın olması gerekir. Alışkın değillerse risk daha da artar.
  - Planda küçük sapmalar hep olur. Ana yüklenici, alt yüklenicilere bu sapmaların uzaktan yönetimin doğal sonucu olduğunu plan üzerinden sakince anlatmalı.
  - Bütçe uygunsa proje yöneticisi ve Scrum Master gibi kişiler belli aralıklarla (3, 6 ya da 12 ayda bir) diğer lokasyonlardaki ekipleri ziyaret etmeli.
  - Çok büyük takımlar global takım yapısına yaklaşır. Farklı ülkelerde yetenek bulmak zaman ve maliyet ister. Ülkelerin kuralları ve uyum süreçleri baştan incelenmeli.
- **Sonuçlar:**
  - Çözümde tüm ekiplerin fikri alınmalı. Toplantılar mümkün olduğunca kameralar açık yapılmalı.
  - Bir ekip gereksinim dokümanını hazırlayıp diğerinden yalnız çalışan kod beklerse süreç çevik olmaktan çıkar, yinelemeli-artımlı bir sürece döner. Beyin fırtınası toplantıları gerekir.
  - Sık sürüm çıkarılmalı, böylece en küçük değişiklik bile test edilebilir.
  - Gereksinimler ayrıntılı belirlenmeli.
  - Doğru araçlar (Teams, Zoom, kod entegrasyon araçları) seçilmeli. Takımlar birbirine sık demo yapmalı.

### Sınav sonuçları ve uygulama projesi

- Hoca sınav kâğıtlarını okudu ve sonuçları öğrenci bilgi sistemine girdi. Notlar 68 ile 100 arasında.
- Bir öğrenci uygulama projesinde kod yazılıp yazılmayacağını sordu:
  - Öğrenci üzerinde çalışacağı yazılımı seçer, kodunu yazmaz.
  - Birim test yapılacağı için seçilen yazılımın koduna erişilebilmelidir.
  - Kod üzerinde bir birim test örneği hazırlanır.
- Kaynak kodu erişilebilir ve gereksinim belgesi yazılabilecek herhangi bir proje seçilebilir.
- Önemli olan yapılan testler ve gereksinim belgesidir.
- Hoca bu hafta makale sunumlarının bitmesini planlamıştı. Önümüzdeki hafta kalan makale sunumları ve uygulama projeleri anlatılabilecek.

### Ders sonrası notlar

- 1. sunumda büyük ölçekli sistemlerdeki bileşenlerin "birbirinden bağımsız" olduğu söylendi. Sunumun geri kalanıyla tutarlı olan ifade "birbirine bağımlı" olmalıdır; zorluk da bu karşılıklı bağımlılıktan gelir.
- 1. sunumda altyazıda geçen "SR", "TLM", "Soft Risk" ve "Risk kit" adları SRE (Software Risk Evaluation), TRM (Team Risk Management), SoftRisk ve Riskit modelleridir.
- 2. sunumda yeniden çalışma süresi etki oranı "zaman etkisi bölü gerçek maliyet" diye okundu. Oran süreyle ilgili olduğu için payda gerçek süre olmalıdır.
- 3. sunumda Königsberg problemini ortaya atan kişi altyazıda "öyle" diye geçiyor; bu büyük olasılıkla Euler'dir. Euler büyük olasılıkla problemi ortaya atmamış, 1736'da çözmüş ve çözümün olmadığını göstermiştir.
- 3. sunumda takım lideri 3'ün dört takımda olduğu ve D takımından çıkarılınca kromatik sayının 2'ye indiği söylendi. Lider C, E ve F'de kalıyorsa bu üç takım hâlâ ortak kaynak paylaşır ve kromatik sayı en az 3 olur. Graf görülemediği için kesin değil; takım dağılımı büyük olasılıkla sunumda eksik aktarılmıştır.
- 3. sunumda CPM "Critical Path Management" diye açıldı. Doğrusu Critical Path Method'dur.
- 4. sunumdaki "Levit" modeli Harold Leavitt'in organizasyonel değişim modelidir (Leavitt's diamond).
- Altyazıda "Ecal", "Ejel", "heyecan" diye geçen terim "agile" (çevik) olmalıdır.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
