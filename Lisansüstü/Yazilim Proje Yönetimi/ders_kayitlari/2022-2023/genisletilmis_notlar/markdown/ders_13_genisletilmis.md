# Ders 13 Genişletilmiş Notu: Makale ve Proje Planı Sunumları: Start-up'larda Yazılım Mühendisliği, Balık Kılçığı ile Risk Analizi, Çevik Süreç Metrikleri ve Makine Öğrenmesiyle Risk Tahmini

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

Bu derste öğrenciler önce kalan makale sunumlarını yaptı, ardından dönem projelerinin proje planlarını sunmaya başladı. Proje planı sunumları, bir bitirme projesinin ya da yürütülen bir projenin proje planı ve gereksinim analizi belgesinin hazırlanması biçimindeydi. Hoca sunumların arasında sorular sordu ve kısa yorumlar yaptı. Aşağıda sunumlar ders sırasıyla verilmiştir. Sunum yapanlar "bir öğrenci" diye anılır.

## İçindekiler

- 1. Start-up'larda yazılım mühendisliği: hedefler, zorluklar ve uygulamalar için bir ilerleme modeli
- 2. Balık kılçığı yöntemiyle yazılım sektöründeki risklerin değerlendirilmesi
- 3. Küçük ölçekli bir şirkette çevik süreçlerin ölçülmesi ve iyileştirilmesi (Q-Rapids)
- 4. Proje planı sunumu: e-ticaret web uygulaması
- 5. Proje planı sunumu: kozmetik içerik analizi mobil uygulaması
- 6. Yazılım proje yönetiminde makine öğrenmesi
- Örnek Sorular

## 1. Start-up'larda Yazılım Mühendisliği: Hedefler, Zorluklar ve Uygulamalar İçin Bir İlerleme Modeli

İlk sunumda yazılım start-up'larının yazılım mühendisliği hedeflerini, zorluklarını ve uygulamalarını yaşam döngüsü boyunca inceleyen bir makale anlatıldı. Sunucuya göre makale IEEE Transactions on Software Engineering'de 2019'da yayımlanmıştır. Sunum altı bölümden oluşuyordu: giriş, start-up yaşam döngüsü modeli, araştırma yöntemi, veri toplama ve analizi, sonuçların analizi ve sonuç.

### 1.1 Yazılım start-up'ları

Yazılım start-up'ları yazılım odaklı ürünler geliştiren ve pazarlayan küçük şirketlerdir. Makale, start-up'ların farklı mühendislik süreç alanlarını nasıl kullandığını ve bu uygulamaların yaşam döngüsü boyunca nasıl değiştiğini anlamayı, start-up'ların temel alabileceği bir model geliştirmeyi amaçlar.

Start-up'ların bazı ortak özellikleri vardır:

- Ürün kalitesi yerine pazara çıkış süresine öncelik verirler.
- Ekipler, özellikle başlangıçta, küçüktür ve zamanla büyür.
- Ekipler kendi kendini motive eder, mühendislik uygulamaları gayriresmîdir.
- Başarısızlık oranları yüksektir. Sunumda Avrupa'da gözlenen başarısızlık oranı için %77 ile %90 arası bir aralık verildi. Bu oran sınırlı kaynaklar ve yazılım geliştirmenin zorluğuyla ilişkilendirilir.

Önceki çalışmalar start-up'ların genellikle en iyi mühendislik uygulamalarını izlemediğini, mühendisliğe rastgele bir yaklaşım benimsediğini göstermektedir. Belirli bir yazılım proje yönetimi olmadan, yalnız bir ürün çıkarmak amacıyla kurulup sonra nasıl ilerleyeceğini bilemediği için kapanan çok sayıda start-up vardır.

Hoca burada bir yorum yaptı: start-up'lar genellikle az sayıda teknik kişinin bir araya gelmesiyle kurulur. Büyük projelerde bir ekip yapısı, proje yönetimi, zaman planı ve kaynak planı oluşturulurken burada "teknik algoritmamızla başlayalım, ürünü çıkaralım" kaygısı öne çıkar. Sunucu da kurucuların çalıştığı alanın etkili olduğunu, yazılımcı olmayan ama yazılımla bağlantısı olan kurucuların da bulunduğunu ekledi.

### 1.2 Start-up yaşam döngüsü modeli

Makalede start-up'ın yaşam döngüsü dört aşamalı bir süreç olarak modellenir (ekrandan, 00:10:00):

- **Başlangıç:** ürün fikrinden ilk müşteriye ilk ürün sürümünün verilmesine kadar olan aşama. İlk sürümün çok kaliteli olması gerekmez; müşterinin görüp kullanabileceği kadar işlevselliğe sahip olması yeterlidir.
- **Stabilizasyon:** ilk ürün sürümünden ölçeklenmeye hazırlığa kadar olan aşama. Ürünün ek çaba gerektirmeden kullanılabilir hale gelmesi amaçlanır.
- **Büyüme:** istenen pazar payına ve büyüme hızına ulaşmaya yönelik aşama.
- **Olgunluk:** start-up'ın pazar payını korumak ve operasyonlarını optimize etmek amacıyla kurumsal bir yapıya dönüştüğü aşama.

Bu dört aşamadaki bir start-up aktif kalmaya, bir sonraki aşamaya ilerlemeye ve hissedarlara kâr sağlamak için başka bir şirket tarafından satın alınmaya çalışır (ekrandan, 00:10:00). Satın alınma her zaman olmak zorunda değildir, olgunlukta hedeflenen sonuçlardan biridir. Start-up herhangi bir aşamada durdurulabilir ya da kapatılabilir. Çalışmada incelenen start-up'lar aktif, duraklatılmış, satın alınmış ve kapatılmış olarak dört gruba ayrılmıştır; kapatılmış start-up'lar da çalışmaya dahildir.

Modelin şemasında beyaz baloncuklar iyi ve istenen durumları, gölgeli baloncuklar istenmeyen durumları, oklar durumlar arasındaki olası geçişleri gösterir. Noktalı oklar çalışmada gözlenmeyen ama olabileceği düşünülen senaryolardır. Baloncuklardaki sayılar o durumda gözlenen şirket sayısıdır; örneğin stabilizasyonda 18 şirket gözlenmiştir. Başlangıçta odak daha dar iken sonraki aşamalarda pazarlama, büyüme ve bakım odağı artar.

### 1.3 Araştırma yöntemi ve soruları

Çalışmada vaka anketi (case survey) yöntemi kullanılmıştır. Bu yöntem genel anketlere göre daha zengin veri toplama ve daha çok durumu inceleme olanağı sağlar; ancak toplanan veri anket aracının kapsamıyla sınırlıdır. Vaka anketi teori oluşturma yöntemiyle birleştirilmiştir.

Araştırma soruları start-up'larda hangi yazılım mühendisliği örüntülerinin (pattern) bulunduğunu ve bunları şekillendiren hedef ve zorlukları sorar. Bu sorunun sorulmasının nedeni, start-up'ların hangi mühendislik uygulamalarını kullandığı ve bunları kullanma ya da kullanmama motivasyonu hakkında çok az bilgi olmasıdır. Start-up'lar kuruluşta genellikle belgelendirme yapmadığından "başlangıçta neyi izlemeliyiz" sorusunun cevabı yoktur; çalışmanın bir amacı da böyle bir model oluşturmaktır. Hedeflerin ve zorlukların anlaşılması şunlar için önemlidir:

- yaygın uygulamaların uygunluğunu değerlendirmek,
- belirli zorlukları aşmak ve belirli hedeflere ulaşmak için yeni mühendislik uygulamaları tasarlamak,
- start-up bağlamında yazılım yoğun ürün mühendisliğinin bir resmini sunmak.

Makale start-up'ları hedefler, zorluklar ve uygulamalar olmak üzere üç temel kategoriye göre ele alır; bunlara göre start-up'ları birbirinden ayırır ve ortak yönlerini bulmaya çalışır.

### 1.4 Veri toplama ve analizi

Anket iki incelemeden geçirilmiştir (ekrandan, 00:15:00):

- **İç inceleme:** soruların kapsamını ve akışını belirlemek için yazarlar arasında yapılmıştır.
- **Dış inceleme:** Yazılım Start-up Araştırma Ağı'nın (Software Startup Research Network) 10 üyesi tarafından yapılmıştır.

Anket 10 bölüm, 85 üst düzey soru ve 285 alt soru içerir. Soru kategorileri: start-up demografisi, ürün demografisi, katılımcı demografisi, takım demografisi, gereksinim mühendisliği, yazılım mimarisi, kullanıcı arayüzü tasarımı, geliştirme pratikleri, kalite güvencesi ve proje yönetimi.

Toplam 369 katılımcı anketi yanıtlamaya başlamıştır. Ancak anket tek seferlik değil, bir süreç olarak yürütüldüğünden bazı katılımcılar devam etmemiş, bazıları da yanıtları doğru vermemiştir. Anketin yanıt oranı %23'tür; 369 yanıttan 84'ü geçerli kabul edilmiştir (ekrandan, 00:20:00). Sunucu, büyümekte olan start-up'lara "başlangıçta ne yaptınız" gibi sorular sorulduğunda belgelendirme olmadığından yalnız hafızadan cevap verildiğini, bunun da geçerliliği etkilediğini belirtti. Hoca, soru sayısı çok olduğu için tamamının cevaplanmamasının doğal olduğunu ekledi.

İstatistiksel analiz şöyle yapılmıştır (ekrandan, 00:20:00):

- Değişkenler arasındaki ilişkilerin şansa bağlı olmadığını sınamak için **ki-kare testi** kullanılır.
- Tip I hataları önlemek için kesin testler, özellikle 10 000 örnek tabloya dayanan ve $p < 0{,}05$ varsayımına dayanan istatistiksel anlamlılık **Monte Carlo testi** kullanılır.
- İlişkilerin gücünü incelemek için **Cramér'in V** katsayısı kullanılır. Slayttaki adımlar: en az kategoriye sahip alanı belirle; bu alanın kategori sayısından 1 çıkar; sonucu toplam kayıt sayısıyla çarp; ki-kare değerini bu sonuca böl; karekökünü al. Yani

$$V = \sqrt{\frac{\chi^2}{n\,(k-1)}}$$

burada $n$ toplam kayıt sayısı, $k$ daha az kategoriye sahip değişkenin kategori sayısıdır.

**Soru:** Ki-kare ile sorular arasındaki ilişkiye mi bakılıyor? İki ilişkili sorudan birine olumlu, öbürüne olumsuz cevap verildiyse anketi dolduranın yanıtlarına güvenilmiyor mu? **Cevap:** Sunucu, makalenin bu konuda ayrıntı vermediğini, ama yanıtların ki-kare ile sınandığını, belirli bir değerin altında kalan yanıtların geçerli sayılmayıp elendiğini, üstündekilerin modele alındığını söyledi. Bazı start-up'lar 3-4 kişilik ekiplerden oluştuğu ve konuyu tam anlamadan cevap verebildiği için böyle bir baraj konduğunu ekledi.

> **Ek bilgi (derste anlatılmadı):** Ki-kare bağımsızlık testi, iki kategorik değişkenin çapraz tablosundaki gözlenen frekansları bağımsızlık varsayımı altında beklenen frekanslarla karşılaştırır. Cramér'in V ise 0 ile 1 arasında değer alır; 0 ilişki olmadığını, 1'e yakın değerler güçlü ilişkiyi gösterir. Ki-kare değeri örneklem büyüklüğüyle büyüdüğü için ilişkinin gücünü karşılaştırmak amacıyla V gibi normalleştirilmiş bir ölçü kullanılır.

### 1.5 Hedefler, zorluklar ve uygulamalar

Makalede bulgular üç türde kodlanır:

- **Hedefler (G, goal):** bir çabanın yöneldiği, arzu edilen sonucu tanımlayan örüntüler.
- **Uygulamalar (P, practice):** start-up'ın yaşam döngüsü aşamalarında ilerlemesine yardım eden mühendislik faaliyetleri.
- **Zorluklar (C, challenge):** yazılım mühendisliği uygulamalarını gerçekleştirirken ve aşamalarda ilerlerken karşılaşılan güçlükler.

Bu bulgular bir şemada süreç alanları ve yaşam döngüsü aşamalarına göre yerleştirilmiştir. Şemada siyah gösterilenler hedefler, kareler uygulamalar, yuvarlaklar zorluklardır. Her öğenin sağ üst köşesinde onu destekleyen vaka (şirket) sayısı yazar. Bir hedef ile bir uygulama aynı yerde görünüyorsa (örneğin "dahili ekip performans metriklerini kullanın") uygulamanın kullanımıyla hedefe ulaşma arasında bir ilişki olduğu düşünülür. Bir zorluk ile bir uygulama örtüşüyorsa (örneğin "bir geri bildirim döngüsü oluşturun, müşteri geliştirme çalışmasını yönlendirsin") o uygulamanın denendiği ama zor bulunduğu anlaşılır.

### 1.6 Geçerlilik sorunları ve katılımcı profili

Her bölümün sonunda uygulayıcıların öğrendikleri en önemli dersleri yakalamak için "Bir dahaki sefere neyi farklı yapardın?" diye sorulmuştur (ekrandan, 00:25:00). Katılımcı yanlılığı önemli bir geçerlilik sorunudur: yanıtların kalitesi büyük ölçüde katılımcıların hafızasına ve geçmiş olayları yeniden kurma yeteneğine bağlıdır. Yanıtların çoğu nispeten yeni deneyimleri içerir.

Anket, deneyimleri yakalamak ve yanlış anlaşılma olasılığını azaltmak için çoktan seçmeli sorular, Likert ölçekli sorular ve serbest metin alanlarının bir karışımını kullanır. Katılımcıların bir kısmı yazılımla ilgili, bir kısmı yazılım dışı mühendislik alanlarından gelmektedir. Start-up'ların çoğu Avrupa ve Güney Amerika'dandır; Kuzey Amerika ve Asya'daki start-up'lar temsil edilmemiştir.

### 1.7 Sonuçların analizi

Sunucuya göre incelenen start-up'lar 2004 ile 2011 arasında kurulmuştur ve çoğu operasyoneldir. 9 start-up yanıtları yetersiz olduğu için çıkarılmıştır. Anket sırasında çoğunluk ürünü üzerinde aktif olarak çalışırken 24'ü kapanmış, duraklatılmış ya da satın alınmıştır. Start-up'ların yönetimi çoğunlukla kuruculardan oluşur. <!-- BELİRSİZ: kuruluş yılı aralığı altyazıda "2004 ile 2011" olarak geçiyor; slayt karesi yok. -->

Sonuçlar altı süreç alanında yapılandırılmıştır: takım, gereksinim mühendisliği, değer, kalite güvencesi, mimari ve tasarım, proje yönetimi. Anket yapısı SWEBOK (Software Engineering Body of Knowledge) ve start-up'lardaki mühendislik uygulamaları taksonomisinden türetilmiştir. Hoca sunucuya süresinin dolduğunu hatırlattığı için alanlar özetle anlatıldı:

- **Takım:** başlangıçta 4-8 kişilik bir ekip olup zamanla takımı büyütmek hedeflenir. Takım kurarken belirli alanlardaki uzmanları almak gerekir. Bir zorluk örneği olarak bir start-up'ın bütün kurucularının başka işleri olduğu ve iletişim eksikliği yaşandığı aktarıldı. İki senaryo vardır: ortak deneyimi olmayan kişilerden yeni bir ekip kurmak ya da daha önce birlikte çalışmış bir ekibi yeniden toplamak. Çıkarılan ders: takım oluşturmak erken aşamada yapılması gereken bir faaliyettir; verimli takım çalışması için mühendislik ve alan uzmanlığı önemlidir.
- **Gereksinim mühendisliği:** hedef minimum işlevli ürünün kapsamını belirlemektir. Aktif ve kapanmış start-up'lar karşılaştırıldığında beyin fırtınası ve gereksinimlerin "icat edilmesi" en popüler gereksinim kaynaklarıdır. Yanıtlar start-up'ların farklı gereksinim kaynakları kullandığını, müşterilerden talepleri toplamak için gözlem ve görüşmeler yaptığını, müşteri ziyaretlerinin ve anketlerin daha az kullanıldığını gösterir (ekrandan, 00:30:00). Çıkarılan ders: gereksinim analizi, bir özelliğin kaç müşteri tarafından faydalı bulunacağına odaklanarak özelliğin ne zaman ekleneceğini belirlemek için yürütülür.
- **Değer:** bu alan bir uygulama ya da zorluktan değil, hedeflerin belirlenmesinden söz eder. Baskın görüş müşteri perspektifidir. En az iki değer perspektifinin önemli olduğu görülür: başlangıçta müşteri değeri ve pazar değeri, olgunlukta finansal değer ve farklılaşma.
- **Kalite güvencesi ve test:** potansiyel olarak küçük ürünler ve kusurlara daha toleranslı erken benimseyenler nedeniyle kalite başlangıçta önemli bir endişe kaynağı değildir. Bakım ise yaşam döngüsü boyunca artan bir endişedir; stabilizasyondan başlayıp özellikle olgunlukta önem kazanır.
- **Mimari ve tasarım:** kullanılan teknolojiye ve ekibin uzmanlığına ilişkindir. Çıkarılan ders: start-up'lar kararlı teknolojiler seçerek ve bunların en iyi uygulamalarını izleyerek teknik riski azaltır. Kullanıcı arayüzü tasarımı önemli bir faaliyettir. Bazı start-up'lar "ne kadar yeni bir programlama dili kullanırsak müşteriye o kadar erken ulaşırız" düşüncesiyle başlamış, ama dilin yeniliği belgelendirme azlığı ve başka sorunlar yaratmıştır. Çok yeni bir teknoloji seçmek ters yönde bir risktir.
- **Proje yönetimi:** tanım PMBOK (Project Management Body of Knowledge) kitabından alınmıştır: planlama ve kontrol, kaynak kullanımı, optimizasyon ve belirli hedeflere ulaşma; mühendislik faaliyetlerinin planlanması ve kontrolüyle ilgilenir. Çıkarılan ders: net hedefler koymak, kaynakları ve takvimi kontrol etmek start-up yaşam döngüsü boyunca ilerlemeyi izlemek için önemlidir. Planlama ve kontrol eksikliği bütçe ve zaman aşımına yol açar.

Sonuç olarak makale 84 yazılım start-up'ı ile çalışmış ve start-up'lardaki yazılım mühendisliği uygulamalarının kurumsal ortamdan temel farkının, bütün süreç alanlarında uygulamaların gelişiminin küçük bir hata payıyla yönetilmesi gerektiği olduğunu ileri sürmüştür.

## 2. Balık Kılçığı Yöntemiyle Yazılım Sektöründeki Risklerin Değerlendirilmesi

İkinci sunumda, sunucuya göre 2019'da yayımlanmış bir konferans bildirisi anlatıldı. Bildiri balık kılçığı yöntemini tanıtır, yazılım sektöründeki riskleri tanımlayıp sınıflandırır ve anket verileriyle değerlendirir. Sunum PowerPoint düzenleme görünümünde yapıldı (ekrandan, 00:40:00).

### 2.1 Balık kılçığı diyagramı

Balık kılçığı diyagramı (fishbone diagram, fishbone analizi) Türkçede balık kılçığı ya da sebep-sonuç diyagramı olarak da bilinir. Sunucunun tanımıyla, bir problemin ya da riskin olası nedenlerini tanımlamak için kullanılan görsel bir araçtır; problemin bütün nedenlerini ve aralarındaki ilişkiyi açık biçimde belirlemeye yarar.

Diyagramın temel özelliği şudur: bir problemin ana nedenini bulmak elbette önemlidir, ama çevrede kalan ikincil nedenleri de görmek gerekir. Balık kılçığı bunu görsel olarak sunar. Klasik ana başlıklar (kılçıklar) insan faktörü, metot, araçlar/makineler ve malzemelerdir. Bu başlıklar diyagram ortaya çıktığında herkesin bir şablon üzerinde ilerlemesi için konmuştur; her sektörde aynılarını kullanmak gerekmez. Örneğin bir kalite değerlendirmesinde "ölçüm" diye yeni bir ana başlık açılabilir, çünkü kalitenin amacı ölçüm yapmaktır.

> **Ek bilgi (derste anlatılmadı):** Bu diyagram, Japon kalite uzmanı Kaoru Ishikawa'nın adıyla Ishikawa diyagramı olarak da anılır. İmalatta sık kullanılan ana başlık seti "6M" (man, method, machine, material, measurement, mother nature/çevre) olarak bilinir.

### 2.2 Uygulama adımları ve örnek

Slayttaki uygulama adımları şunlardır (ekrandan, 00:40:00):

- Bir ok çizilir ve okun başına problem yazılır.
- Problemi ortaya çıkaran sebeplerle ilgili tartışılır ve ana başlıklar belirlenir.
- Çizilen balığın kılçıklarına belirlenen ana sebepler yazılır.
- Her kategori için beyin fırtınası yapılarak probleme sebep olan etkenler belirlenir ve ana başlığın altına yazılır.
- Tespit edilen problemlere çözümler bulunur.
- Problemin asıl sebebi ekip tarafından belirlenir.
- Problemin çözümü için beyin fırtınası yapılmaya devam edilir.

Örnekte problem "benzin israfı"dır ve dört ana başlık kullanılır (ekrandan, 00:40:00):

- **Metot:** yanlış vites, çok hızlı araç sürmek, hep geç kalmak, sabırsızlık; motoru duymamak, bunun nedeni olarak duyma özrü ve çok gürültülü müzik.
- **Makine:** benzin karışımı zengin, mekanikerin bilgisi yok, karbüratör ayarı, standart basınç bilinmiyor, sönük lastikler, kötü dizayn, iç lastik problemi.
- **İnsan:** kötü bakım, dikkatsizlik, yetersiz eğitim, kişilik problemi, kötü sürme alışkanlıkları.
- **Malzeme:** yanlış oktanlı benzin, kullanım kılavuzunda bilgi yok, tavsiye edilen benzin, yanlış yağ, yağ değişimi yapılmıyor, uygun olmayan yağlama, doğru yağ bilinmiyor.

Nedenler dallanarak ilerler: benzin israfının bir nedeni yanlış vites kullanımıdır; bunun nedeni motoru duymamaktır; bunun nedeni de çok gürültülü müziktir. Bu dallanma bir yerde kesilmelidir, yoksa sonu gelmez. Alt başlıklar oluşturulduktan sonra ekip nedenleri değerlendirir, beyin fırtınası yapar ve geriye doğru çözerek analizi tamamlar.

**Soru:** Nedenleri etki faktörü en büyük olandan başlayarak mı sıralayacağız? **Cevap:** Sunucu, nedenlerin önce diyagram üzerine yerleştirildiğini, sonra puanlanarak önceliklendirildiğini ve değerlendirildiğini söyledi; örneğin benzin israfının en büyük nedeni makine kategorisindeyse ona yüksek bir puan verilir. Bildiri bu puanlamayı kendi verisi için yapmamıştır.

Yöntemin asıl faydası, bir probleme tek bir noktadan bakmak yerine esnek yaklaşmak, farklı çözümler aramaktır. Yalnız ana sebebe değil, diğer sebeplere de bakılır ve çözülebiliyorsa onlara da çözüm üretilir.

### 2.3 Risk yönetimi süreci ve risk sınıfları

Bildiride risk yönetimi sürecinin yalnız ilk kısmı işlenir: risklerin tanımlanması, sınıflandırılması ve değerlendirilmesi. Önceliklendirme, çözüm, izleme ve takip gibi sonraki adımlar işlenmez. Yazarlar riskleri tanımlayıp belirli bir kalıba göre sınıflandırmış, sonra Pakistan'daki yazılım şirketlerine anket göndermiştir. Risk sınıfları ve nedenleri şunlardır:

- **Zaman (schedule) riskleri:** yanlış görev tahmini ya da planlama nedeniyle işin beklenen sürede gerçekleşmemesi. Nedenleri: zaman tahmini, kaynak tahsisi (takıma yeterli kaynak ayrılmaması), proje karmaşıklığının artması, proje kapsamının değişmesi ve genişlemesi.
- **Bütçe riskleri:** gerçekçi olmayan bütçe tahmini, maliyet aşımı ve kapsam genişlemesi. Planlama aşamasından kaynaklanan hatalı bütçe tahmini bu riski oluşturur. Kapsamın genişlemesi hem zamanı hem bütçeyi etkiler.
- **Operasyonel riskler:** süreç standartlarından ya da süreçlerin izlenmesinden kaynaklanır. Nedenleri: yanlış süreç uygulaması, çelişen öncelikler, iletişim eksikliği, yetersiz eğitim. Yanlış süreç uygulaması proje yönetiminin yetersizliğinden, uygun olmayan modellerin seçilmesinden ya da önceliklerin belirlenmemesinden doğar.
- **Teknik riskler:** değişen müşteri gereksinimleri, teknoloji eksikliği ve ödünleşim (trade-off) kararları.
- **Diğer kaçınılmaz riskler:** devlet politikası, müşteri değişimi, rekabet, dış kaynak kullanımı.

Bu nedenler, kafasında "yazılım geliştirme" yazan bir balık kılçığı diyagramına yerleştirilmiştir. Diyagramın kılçıkları operasyonel risk, bütçe riski, zaman riski, teknik risk ve diğer kaçınılmaz risklerdir (ekrandan, 00:50:00).

### 2.4 Anket verileri

Ankette şirketlere riskleri kendi projelerinde yaşayıp yaşamadıkları sorulmuştur. Sonuçlar (ekrandan, 00:45:00):

| Soru | Evet | Hayır |
|---|---|---|
| Geliştirilen projede takvim (schedule) değişti mi? | %56,6 | %43,4 |
| Belirlenen bütçe değişti mi? | %64,2 | %35,8 |
| Operasyonel risk sorunu oldu mu? | %62,3 | %37,7 |
| Teknik risk sorunu oldu mu? | %69,8 | %30,2 |

Sunucunun en çok dikkatini çeken teknik riskin yüksek oranıydı. Takvim değişikliği oranını ise kendi gözlemine göre düşük buldu. <!-- BELİRSİZ: sunucu takvim değişikliği oranını sözlü olarak "16.6" diye okudu; karede %56,6 görünüyor, tabloda kare değeri kullanıldı. -->

Sonra her risk türünün kök nedeni (root cause) sorulmuştur. Yanıtlar 100 üzerinden olasılık olarak verilmiş ve her risk için en çok ve en az etkili neden belirlenmiştir. Sunucu, planlama aşaması iyi yapılırsa proje riskinin azalma olasılığının yüksek olduğunu vurguladı. <!-- BELİRSİZ: 00:46:00-00:48:10 arasında sunucunun bağlantısı koptuğu için kök neden tablolarındaki değerler (6,7; 3,0; 7,6 gibi) altyazıda bozuk ve hangi nedene ait oldukları anlaşılmıyor; bu aralığın karesi yok. -->

### 2.5 Nicel değerlendirme

Bildiride riskler son olarak nicel olarak değerlendirilmiştir: her risk için bir olasılık düzeyi ve bir etki düzeyi vardır, risk değeri bunların çarpımıdır. Bu, proje yönetiminde kullanılan standart bir yaklaşımdır. Bildiri sonuçları balık kılçığı diyagramı üzerine yerleştirmemiştir; sunucu bu adımı kendi projesinde uygulamayı düşündüğünü söyledi. Sunucunun çıkardığı sonuca göre önce teknik riskler, sonra operasyonel ve bütçe riskleri, en son zaman riskleri ele alınmalıdır. <!-- BELİRSİZ: 00:50:16-00:51:08 arasında nicel değerler ("0.75", "%7" gibi) altyazıda bozuk. -->

## 3. Küçük Ölçekli Bir Şirkette Çevik Süreçlerin Ölçülmesi ve İyileştirilmesi (Q-Rapids)

Üçüncü sunumu iki öğrenci birlikte yaptı. Makale "küçük ölçekli bir yazılım geliştirme şirketinde çevik süreçlerin ölçülmesi ve iyileştirilmesi" başlığını taşır ve Nisan 2020'de IEEE Access'te yayımlanmıştır (ekrandan, 01:10:00).

### 3.1 Motivasyon

Çevik geliştirme yöntemleri bugün her türden yazılım şirketi tarafından yaygın olarak benimsenmektedir. Sektör araştırmaları neredeyse bütün kuruluşların çevik yöntemleri bir dereceye kadar kullandığını, yarısından fazlasının yazılım geliştirme yaklaşımının çevik olduğunu gösterir. Çevik projelerin yönetimi, özellikle KOBİ'ler söz konusu olduğunda zorlayıcıdır. Ürün sahibi (Product Owner) ve Scrum Master için zorluk iki yönlüdür: yazılım ürün kalitesini güvence altına almak ve ekip süreçlerinin etkinliğini korumak.

Makalenin kapsamı, bir KOBİ'de çevik yazılım geliştirme sürecini ölçen bir metrik setini ve bu metriklerin ticari bir ürünün geliştirilmesinde Scrum ekibine nasıl yardım ettiğini tartışmaktır. Metrikler, AB tarafından desteklenen Q-Rapids projesinin araştırma ekibi ile Polonyalı küçük bir yazılım şirketinin ticari bir ürün üzerindeki ortak çalışması sırasında oluşturulmuştur; yani makale bir eylem araştırmasının (action research) ürünüdür.

### 3.2 Q-Rapids projesi ve aracı

Q-Rapids (Quality-aware rapid software development) üç araştırma ortağı ve dört şirketin yer aldığı bir endüstri-akademi iş birliği projesidir. Çevik yazılım metodolojisinin yazılım ve proje yönetim süreçlerini iyileştirmek için yenilikçi yöntemler ve araçlar önermiştir. Yaklaşım çeşitli kaynaklardan (yazılım havuzları, proje yönetim araçları, sistem kullanımı ve hizmet kalitesi) veri toplanmasına ve analiz edilmesine dayanır (ekrandan, 01:10:00).

Slayttaki şemada akış şöyledir: karar verici (decision maker) ürün birikimini (product backlog) yönetir; geliştirme süreci yazılım sistemini üretir ve son kullanıcıya ulaştırır. Yazılım ve proje havuzları ile çalışma zamanı verileri (kullanım, hizmet kalitesi) madencilikle işlenir (mined data) ve stratejik gösterge paneline (strategic dashboard) aktarılır. Panel karar vericiye gereksinim değerlendirmesi sunar; karar verici de karar kuralları ve kısıtlar tanımlar.

Proje sonunda ortaya çıkan Q-Rapids aracının ana modülleri veri toplama, veri modelleme ve analiz, stratejik karar vermedir. Stratejik karar verme modülü proje yöneticilerine bir görselleştirme sunar. Veri sağlayıcılar arasında SonarQube (statik analiz), Jenkins ve Jira gibi araçlar vardır.

### 3.3 İncelenen şirket ve araştırma hedefi

Çalışma, 70-90 çalışanı olan Polonya merkezli bir yazılım şirketinin depo ve üretim süreçlerinin kontrolü için geliştirdiği yazılım üzerinde yapılmıştır. Şirket Scrum kullanır; her gün 7-10 geliştirici yazılımın dağıtımı ve yeni özellikler üzerinde çalışır. Sprintler haftalıktır; sprintin son gününde sprint gözden geçirme, geçmişe dönük değerlendirme (retrospektif) ve sonraki sprintin planlaması yapılır.

Scrum ekibinin ihtiyaçları ekibin süreç performansını izlemek, yeni özellikler eklerken ürün kalitesini korumak ve sprint planlamasındaki görev tahminlerini iyileştirmektir. Araştırmanın hedefi, Hedef-Soru-Metrik (GQM, Goal-Question-Metric) yaklaşımını uygulayarak süreç metriklerini tanımlamak ve KOBİ'lerde Scrum ekibinin çevik süreç performansını izleyip analiz etmektir.

Veri kaynağı olarak GitLab seçilmiştir. GitLab, havuz yönetimi ve iş kaydı (issue) takibine odaklanarak yazılım geliştirme yaşam döngüsünün tamamını destekleyen, açık kaynak tabanlı bir araçtır. Şirketin bütün projelerinde yaygın olarak kullanılır ve Scrum ekibi, geliştirme sürecini en iyi yansıtan aracın bu olduğunu onaylamıştır. Hoca burada GitLab'ın bir anlamda yazılım geliştirme ortamı olduğunu belirtti. Pilot uygulamada araştırmacılar, ekibin GitLab'a girdiği verileri Q-Rapids ile görselleştirmeyi önermiştir.

### 3.4 Veri akışı ve görselleştirme

GitLab'da yazılım yaşam döngüsü boyunca veri toplanır: açılan görevler, bu görevlere atanan kişiler, görevlerin başlangıç ve bitiş zamanları, tahmin edilen süreler. Bu veriler Elasticsearch'te saklanır, Q-Rapids aracına aktarılır ve Elasticsearch'ün bir aracı olan Kibana ile görselleştirilir. Grafiklerde görevlerin hangi aşamada ne kadar süre beklediği izlenir.

Slaytta Q-Rapids ile görselleştirilen dört metrik zaman serisi olarak gösterildi (ekrandan, 01:15:00): test bekleyen iş kayıtlarının yoğunluğu (density of tickets pending testing), hata olmayan iş kayıtlarının yoğunluğu (density of non-bug tickets), son yedi günde çözülen iş kayıtlarının ortalama çıktısı (average resolved issues' throughput) ve son yedi günde tahmin girilmiş geliştirme kayıtlarının yoğunluğu (density of estimated dev. tickets). Metrikler 0 ile 1 arasında normalleştirilmiş değerlerdir.

### 3.5 Süreç metriklerinin tanımı

Eylem araştırma döngüsünün eylem alma aşamasında Scrum ekibi ve araştırma ekibi, çevik geliştirme süreçlerini değerlendirmek için GitLab tabanlı aday süreç metriklerini tartışmıştır. Scrum ekibine göre ilerlemeyi izlemek için kullanılan temel kavramlar şunlardır:

- **Görevler (task):** yazılım geliştirme sürecinde belirli kişilere atanan işler.
- **İş kayıtları ve hatalar (issue, bug):** yeni görevlerin oluşturulması ve açılan hata kayıtları.
- **Efor:** tahminle ilgilidir; ekibin kaynak planlamasındaki doğruluğu ve bu doğruluğun iyileştirilmesini hedefler.
- **Geliştirme durumları arasındaki geçişler:** görevlerin açılma, tamamlanma ve kapanma durumları.

Bu kavramlar sayısal ve zamansal olmak üzere iki boyutta analiz edilir; metriklerin GitLab verileriyle ölçülebilir olması gerekir. Bu ilkelere göre ekip 25 aday metrik önermiştir. Eylem araştırma ekibi bunları kategorilere ayırmıştır: genel metrikler, görev tahmin metrikleri, görev uygulama metrikleri, hata düzeltme metrikleri, test metrikleri ve diğerleri. Metrik seti, Scrum Master, projeden bir geliştirici ve Q-Rapids'ten üç araştırmacının katıldığı bir oturumda kesinleştirilmiştir.

Metriklerin kullanımının üç araştırma sorusuna etkisi raporlanmıştır: süreç performansının izlenmesi, ürün kalitesi düzeyinin korunması ve sprint planlamasında görev tahminlerinin iyileştirilmesi. Grafiklerde süreç performansında iyileşme görülürken ürün kalitesi sabit kalmıştır. Araştırma ekibi bunu normal bulmuştur: yeni özellikler eklenirken bir yandan kod kalitesi iyileştirilmeye çalışıldığından kalite düşmemiş, sabit kalmıştır.

### 3.6 Süreç panosu

GitLab'daki süreç panosunda görevler etiketlerle sütunlara ayrılır (ekrandan, 01:20:00): açık (open), sprint birikimi (sprint backlog), üzerinde çalışılan (work in progress), birleştirme isteği (merge request), hazır (ready), test (testing), sprintte kapanan (sprint closed) ve kapalı (closed).

**Soru:** Kırmızılar bitmiş olanlar mı, yoksa bir problemi mi işaret ediyor? **Cevap:** Kırmızı etiketler hata (bug) kayıtlarını gösterir. Yeni özellikler açık sütununa düşer; pano görevleri ve hataları etiketlere göre kategorilere ayırır.

**Soru:** Yeşiller bitmiş olanlar mı? **Cevap:** Evet, yeşiller sprint içinde bitmiş görevlerdir.

### 3.7 Sonuçlar

Çalışmanın en önemli katkısı, çok ihtiyaç duyulan bir çözüm olarak yazılım geliştirme sürecinin her aşamasının performansını izlemektir. Şirket için en büyük fayda, yeni özellikler eklenirken çözümün sistemin istikrarı üzerindeki olumlu etkisidir: kod büyümesine rağmen kod kalitesi korunmuştur. Üçüncü katkı, görev tahminlerini iyileştiren mekanizmalardır; örneğin görevlerin canlı izlenmesiyle Scrum ekibi bütün görevlerin hangi aşamada olduğunu görebilir, tamamlanan görevleri analiz edip sonraki görev atamalarını daha tutarlı yapabilir.

## 4. Proje Planı Sunumu: E-ticaret Web Uygulaması

Makale sunumlarından sonra proje planı sunumlarına geçildi. İlk proje planı bir e-ticaret web uygulaması içindi. Belge bir Word dosyası olarak gösterildi.

### 4.1 Tanım, amaç ve kapsam

Uygulama, kullanıcıların çevrimiçi alışveriş yapmasını sağlayan bir web sistemidir. Ürünlerin kataloglanmasıyla hızlı ve kolay alışveriş, kolay ödeme ve iade işlemleri, zaman tasarrufu ve ulaşım sorunlarından kurtulma gibi amaçları vardır.

Sistemde iki tip kullanıcı vardır: yönetici (admin) ve normal kullanıcı. Yönetici sisteme kullanıcı adı ve parolayla girer; ürün ekler, siler, günceller, kullanıcı kayıtlarını ve ürün değerlendirmelerini onaylar. Normal kullanıcılar ürünleri inceleyebilir, ama satın almak için kayıt olmaları gerekir. Kayıtlı kullanıcılar ürün inceleme, sepet oluşturma, satın alma ve ürün değerlendirme işlemlerini yapar. Proje sıfırdan başlayan, başka bir projenin devamı olmayan bir projedir.

### 4.2 İşlevsel gereksinimler

Gereksinimler modüllere ayrılmıştır (ekrandan, 01:30:00):

- **Kullanıcı kayıt modülü:** sepet oluşturmak ve satın almak için kayıt zorunludur. Ad, soyad, e-posta, doğum tarihi ve adres istenir.
- **Ürün modülü:** ürünler kategorilere ayrılarak ana sayfada listelenir; tür, marka, fiyat gibi özelliklere göre filtrelenebilir. Kullanıcı adet, tür ve fiyat seçeneklerini belirleyip sepete ekler; sepette ürünler adetleriyle ve toplam ücretle listelenir.
- **Satın alma modülü:** satın alma başlatılınca ödeme sayfasına yönlendirilir. Kullanıcı teslimat adresi ve kredi kartı bilgilerini girer. Fatura oluşturulur ve kullanıcının e-posta adresine gönderilir.
- **Yönetici modülü:** ürün ekleme (girdiler: ürün adı, kategori, fiyat, ürün resmi; ürüne eşsiz bir ürün kodu atanır), ürün silme (eşsiz kodla), ürün değerlendirmesi onaylama (uygunsuz değerlendirmelerin engellenmesi için) ve kullanıcı ekleme/silme yetkisi.

### 4.3 İşlevsel olmayan gereksinimler

- **Performans:** sistem yılda 365 gün, günde 24 saat kullanıma hazır olmalı; birden çok kullanıcıya aynı anda güvenli hizmet vermeli; yeterince hızlı yanıt vermeli; veri tabanındaki değişiklikler anlık güncellenmeli.
- **Görünüm ve kullanım:** basit ve sade bir arayüz; farklı tarayıcılarda düzgün çalışma.
- **Güvenlik:** parola unutulursa e-posta adresi gerektiren bir sıfırlama mekanizması; veri tabanı güncellemelerine yalnız yetkili personelin ve sistem yöneticisinin erişebilmesi.
- **Kullanılabilirlik:** tutarlı, kullanıcı dostu ve kendi kendini açıklayan bir arayüz; hata yapmayı önlemeye yardım eden tasarım; çoğu kullanıcı tarayıcılara aşina olduğundan özel eğitim gerekmez.
- **Operasyonel:** farklı tarayıcılarla ve yaygın veri tabanlarıyla uyum.
- **Yasal:** kişisel bilgilerin korunması, e-ticaret standartlarına uyum.

Ardından arayüz taslakları (ana sayfa, ürün bilgisi, sipariş detayı, alışveriş sepeti, yönetici paneli ve sipariş durumu güncelleme) gösterildi.

### 4.4 Ekip yapısı, kabuller ve kısıtlar

Proje tek kişi tarafından geliştirilmiş olsa da daha büyük bir proje varsayılarak bir ekip tablosu hazırlanmıştır: proje yöneticisi (proje planı, paydaşlarla görüşme), grafik ve tasarım uzmanı, programcı (kodlama ve analiz) ve test ekibi.

Proje planının kabul ve kısıtları şöyle listelenmiştir: sistem proje başlangıcından en geç 3 ay sonra son kullanıcıya açılmalı; geliştirme mevcut ekiple tamamlanmalı; sistem güvenliği en üst düzeyde olmalı; kullanıcıların adları ve parolaları bulunmalı; kaydı olmayan kullanıcı sepete ürün eklemek isterse kayıt sayfasına yönlendirilmeli; aynı anda en fazla 10-15 ürün satın alınabilmeli; sistem aynı anda 10 bin kullanıcıya hizmet verebilmeli; ödeme yalnız kredi kartıyla yapılmalı; uygulama platformdan bağımsız çalışmalı.

> **Hocanın vurgusu:** Kabuller ve kısıtlar ayrı ayrı söylenmelidir. Kabullerde olumlu olarak "şöyle olduğunu varsayıyoruz, bir problem çıkmayacağını varsayıyoruz" denir. Kısıtlarda ise projenin sınırları yazılır: konu açısından ya da teknik olanaklar açısından sınırlarımız; örneğin "ekibimizde beş kişi var ama bir kişinin şu tarihten itibaren izinli olacağını biliyoruz". İkisi ayrı listelenir.

### 4.5 Süreç modeli ve iş kırılım yapısı

Yazılım geliştirme süreç modeli olarak şelale seçilmiştir. Gerekçe: anlaşılması ve uygulanması kolaydır, küçük projeler için idealdir ve müşteriye prototip sunma zorunluluğu yoktur. Gözden geçirme kuralı olarak her adımda (analiz, tasarım, gerçekleştirme, test) izleme ve kontrol yapılacak, sonuçlar raporlanacaktır (ekrandan, 01:35:00).

İş kırılım yapısı şelale modeline göre oluşturulmuştur. Tablonun görünen ilk satırları (ekrandan, 01:35:00):

| WBS | Görev | Süre | Başlangıç | Bitiş |
|---|---|---|---|---|
| 0 | E-Ticaret Sistemi | 80 gün | 01.03.2023 | 20.06.2023 |
| 1 | Gereksinimlerin Belirlenmesi | 7 gün | 01.03.2023 | 09.03.2023 |
| 2 | Analiz | 7 gün | 10.03.2023 | 20.03.2023 |
| 2.1 | Fizibilite | 7 gün | 10.03.2023 | 20.03.2023 |
| 2.1.1 | Zaman Fizibilitesi | 2 gün | 10.03.2023 | 13.03.2023 |

Tablodaki süreler iş günü cinsindendir (ara adım eklendi: 01.03.2023 ile 20.06.2023 arası takvim olarak 80 günden uzundur; hafta sonları sayılmamıştır). Yapının devamında analiz altında zaman, ekonomik ve teknik fizibilite; tasarım altında ön tasarım ve ayrıntılı tasarım; gerçekleştirme altında veri tabanı modelleme ve arayüz modelleme (arka uç ve ön uç), ardından kodlama; test altında birim, bütünleştirme, sistem ve kullanıcı testleri; en sonda bakım yer alır. Bu liste bir Gantt şemasına dökülmüştür; her alt adım bir öncekinin bitişinden sonra başlar.

### 4.6 Bütçe, kullanım durumları ve risk planı

Bütçe kalemleri bilgisayar (40 bin lira), sunucu kiralama, personel ve yazılım ihtiyaçları (50 bin lira) olarak verilmiş, toplam 135 bin lira olarak belirtilmiştir. <!-- BELİRSİZ: sunucu ve personel kalemlerinin tutarı altyazıda geçmiyor, bu anın karesi yok. -->

Kullanım durumu diyagramlarında kullanıcının kayıt oluşturması (ad, soyad, e-posta, adres, telefon) ve yöneticinin kaydı onaylaması; kullanıcının satın alması (teslimat adresi, kredi kartı, ödeme onayı); kullanıcının ürün değerlendirmesinin yönetici onayıyla listelenmesi gösterildi. Genel diyagramda kullanıcı üye olma, giriş yapma, sepete ekleme, satın alma ve değerlendirme; yönetici kullanıcı kaydı doğrulama, ürün ekleme, silme, güncelleme ve değerlendirme onaylama işlemlerini yapar.

Risk planında her risk için olasılık, etki (1-5 arası), önem (olasılık × etki) ve önlem verilmiştir (ekrandan, 01:40:00):

| Risk | Olasılık (%) | Etki | Önem | Önlem |
|---|---|---|---|---|
| Çalışan ayrılması | 20 | 4 | %20 × 4 | Proje başında yedek çalışan bulundurulması |
| Bütçe yetersizliği | 10 | 3 | %10 × 3 | Olası yatırımcılarla görüşmeler |
| Sistemin az sayıda kişi tarafından kullanılması | 60 | 4 | %60 × 4 | Reklam çalışmalarına önem verilmesi, pazarlama bütçesinin genişletilmesi |
| Alt yüklenici (hosting servisi) problemleri | 5 | 5 | %5 × 5 | Sistemin yedeklenmesi, alternatif hosting servislerinin belirlenmesi |

En büyük risk, sistemin az sayıda kişi tarafından kullanılmasıdır. Hosting servisi problemlerinin olasılığı düşük, etkisi yüksektir.

### 4.7 Projenin kapatılması

Proje kapatılırken başlangıçtaki tahminler gerçekleşen sonuçlarla karşılaştırılacak; gelecek projelerde daha iyi tahmin ve planlama yapmak için elde edilen bütün veriler (maliyet, zaman, kaynak, veri tabanı vb.) saklanacak; çalışanların performans analizi raporları oluşturulacaktır (ekrandan, 01:40:00).

## 5. Proje Planı Sunumu: Kozmetik İçerik Analizi Mobil Uygulaması

İkinci proje planı, kozmetik ürünlerin içeriklerini analiz eden bir mobil uygulama içindi. Bu plan, ders kapsamında geliştirilmiş bir proje fikriydi. Belge bir PDF olarak gösterildi.

### 5.1 Amaç ve kapsam

Kimyasal maddeler her gün çevremizdedir ve çoğunu farkında olmadan kullanırız. Özellikle kozmetik ürünlerin içeriklerini tam bilmediğimiz için cildimize ne sürdüğümüzün de farkında değilizdir. Uygulama, barkodu ya da QR kodu okutulan ürünlerin içeriklerini listeler, ürünleri kıyaslar ve kişisel tercihlere göre kişiselleştirilebilir.

Veri kaynağı Sağlık Bakanlığı'nın ürün takip sistemidir. Türkiye'de yasal yoldan piyasaya sürülen her kozmetik ürün bu sistemde bulunmak zorundadır; sistemde ürünlerin ambalajları, barkodları ve içindekiler bölümünün görüntüsü vardır. Hedef, bilinçsiz kullanımın önüne geçmek ve alerjisi olan ya da özel durumu nedeniyle bazı içerikleri kullanmaması gereken kişilere yardım etmektir. İçeriklerin hangisinin faydalı, hangisinin zararlı olduğu ve kimlerin kullanabileceği için bir dermatologdan danışmanlık alınacaktır.

### 5.2 Gereksinimler

İşlevsel gereksinimler (ekrandan, 01:45:00):

- Kozmetik ürünlerin içeriklerinin listelenmesi: bütün içerikler ayrıştırılarak veri tabanında uygun içerikle eşleştirilir.
- Fayda ve zararların açıklanması: içerikler faydalı, zararlı, olası alerjen ve kullanım şekli açısından listelenir.
- Ürünlerin kıyaslanması: aynı kategorideki farklı ürünler karşılaştırılır (örneğin iki üç güneş kremi).
- Kullanıcı profili oluşturma: kullanıcı kendi tercih ve ihtiyaçlarına göre profil oluşturup güncelleyebilir.
- Öneride bulunma: cilt tipi, özel ihtiyaçlar ve bilinen alerjiler göz önüne alınarak ürün önerilir.
- Yorum yapma ve başkalarının yorumlarını değerlendirme: bir forum gibi kullanıcılar deneyimlerini paylaşır, ürünleri puanlar.
- Arayüzün kişiselleştirilmesi: dijital bir makyaj çantası ya da banyo dolabı gibi her kullanıcının kendi profili.
- Favori ürünlerin kaydedilmesi.

İşlevsel olmayan gereksinimler: kolay ve hızlı bir arayüz; oyunlaştırılmış, örneğin makyaj rafı görünümünde bir arayüz; kişisel ve medikal verilerin şifreli ve ilgili prosedürlere uygun saklanması; iOS ve Android uyumu.

### 5.3 SWOT analizi ve yöntem

Kısa bir SWOT analizi yapılmıştır:

- **Güçlü yanlar:** hızlı aksiyon alan ve mobil geliştirmede deneyimli bir kadro.
- **Zayıf yanlar:** ürün takip sistemindeki içerik görüntüleri OCR ile ayrıştırılacağı için ekipte bu konuda deneyim eksikliği.
- **Fırsatlar:** Türkiye pazarında rakip yok; yurt dışında benzer bir uygulama var ama Türkiye'de satılan ürünleri içermiyor; konunun trend olması.
- **Tehditler:** kur dengesizliği; teknoloji ve maaş maliyetlerini artırır.

Yöntem olarak çevik bir metodoloji, örneğin Extreme Programming önerilmiştir. İki haftalık kısa sprintlerle ön uç ve arka uç ekipleri ayrı çalışacak, her sprint sonunda değerlendirme toplantısı ve testler yapılacaktır. Böylece sürekli bir geliştirme ortamı sağlanır, hatalar erken fark edilir ve düzeltme maliyeti düşer. Test odaklı geliştirme sayesinde hataların canlı ortama geçmeden giderilmesi öngörülür.

### 5.4 Ekip ve proje planı

Ekip proje yöneticisi, mobil yazılım geliştiriciler, arka uç ve ön uç geliştiriciler, tasarım uzmanı, veri tabanı yöneticisi, pazarlama uzmanı ve iş analistinden oluşur. Görevler (ekrandan, 01:50:00):

- Proje yöneticisi: proje planı, sponsor, iş birliği ve reklam görüşmeleri, toplantıların planlanması.
- Mobil geliştirici: yayınlanacak mobil platformların gereksinimlerini belirleme ve uygulamayı geliştirme.
- Arka uç geliştirici: kullanıcı taleplerini ve verileri işleyen arka plan, API'ler ve entegrasyonlar, hata ayıklama ve test.
- Ön uç geliştirici: kullanıcı arayüzü, farklı cihaz ve ekranlara uyum, kullanıcı deneyiminin optimize edilmesi.
- Tasarım uzmanı: ekran ve arayüz tasarımı, prototip, kullanıcı deneyimi.
- Veri tabanı yöneticisi: tablolar ve ilişkiler, veri tabanı kurulumu, performans optimizasyonu.
- Pazarlama uzmanı: rekabet ve rakip ürün analizi, pazarlama stratejisi, kampanyalar.
- İş analisti: gereksinim, süreç ve sistem analizi.

Proje aşamaları: başlangıç ve analiz (gereksinim analizi, kapsam belirleme, rakip ürün analizi, başlangıç toplantısı); tasarım (web ve mobil arayüz, veri tabanı; 8 hafta); geliştirme (ön ve arka uç, veri tabanı entegrasyonu; 12 hafta); test (birim ve entegrasyon testleri, hata düzeltme); lansman (canlıya alma, geri bildirim); pazarlama; bakım ve onarım (yeni özellikler, performans iyileştirmeleri). Sunucu başlangıç ve analiz aşamasını en önemli aşama saydı: gereksinim ve rakip analizi verimli yapılırsa geliştirme ve test daha kolay geçer. <!-- BELİRSİZ: başlangıç ve analiz aşamasının süresi altyazıda bozuk ("10 anı, tahtalık"). -->

### 5.5 Risk planı

Risk tablosunda her risk için açıklama, düzey, önleme ve toparlama önlemleri verilmiştir (ekrandan, 01:55:00):

- **Veri sızıntısı:** kişisel ve medikal veri olduğu için etkisi yüksektir. Toparlama: yedeklerden geri dönme; önleme: daha sağlam veri güvenliği ve şifreleme politikaları.
- **Kullanıcıların yanlış bilgilendirilmesi:** yüksek risk; tıp geliştikçe doğru bilinenler değişebilir. Referans kaynaklar ve uzmanlar titizlikle seçilmeli, sürekli yeniden değerlendirilmeli, geri bildirime önem verilmelidir.
- **Pazarlamada hedef kitleye ulaşılamaması:** orta düzey; hedef kitle 18-60 yaş kadınlardır. Pazarlama stratejisi gözden geçirilir, sosyal medya, dijital reklamcılık ve marka iş birliklerine ağırlık verilir.
- **Ürün özelliklerinin kullanıcı beklentilerini karşılamaması:** orta düzey. Daha fazla filtreleme ve kişiselleştirme sunulur, bir chatbot aracılığıyla geri bildirim alınır.
- **Teknik sorunlar:** düşük düzey (donma, kesilme, hata verme). Felaket kurtarma senaryoları hazır ve güncel tutulur; sürekli ve düzenli testlerle hatalar canlıya geçmeden düzeltilir.
- **Proje maliyetinin %10 aşılması:** düşük düzey; öngörülemeyen donanım ya da test maliyetleri. Sponsorluk ve marka iş birlikleriyle gelir artırılır; başarısız olunursa premium kullanıcı ücretleri %5 artırılır.

### 5.6 Bütçe ve sürdürülebilirlik

Bütçe tablosu (ekrandan, 01:55:00):

| İhtiyaç | İhtiyaç duyulan | Sahip olunan | Fiyat |
|---|---|---|---|
| Bilgisayar (notebook) | 6 | 0 | 240.000 TL |
| Sunucu maliyeti | 4 | 0 | 200.000 TL |
| Maaşlar | 8 | 0 | 2.160.000 TL |
| Danışmanlık | 1 | 0 | 100.000 TL |
| Toplam | | | 2.700.000 TL |

Toplam doğrudur: $240.000 + 200.000 + 2.160.000 + 100.000 = 2.700.000$ TL. En büyük gider 8 kişinin maaşlarıdır; dermatolog danışmanlığı başlangıçta bir kez alınacak, ileriki fazlarda tekrarlanabilir.

Sürdürülebilirlik için beş gelir modeli düşünülmüştür:

- Premium üyelik ücretleri: kapsamlı filtreleme ve kişiselleştirme istedikçe ücret artar.
- Marka iş birlikleri: kozmetik firmalarıyla reklam kampanyaları.
- Reklam yerleştirme: kullanıcı deneyimini azalttığı için çok tercih edilmez.
- Anonimleştirilmiş verilerin araştırmalarda kullanılması: veriler anonimleştirildiği sürece üçüncü taraflarla paylaşılabilir, ama dikkatli olunmalıdır.
- Uzmanlarla (dermatolog, makyaj sanatçısı, cilt bakım uzmanı) çevrimiçi ya da yüz yüze etkinlikler düzenlemek.

## 6. Yazılım Proje Yönetiminde Makine Öğrenmesi

Son sunumu iki öğrenci birlikte yaptı ve yazılım proje yönetiminde makine öğrenmesi kullanımı üzerine üç makale anlattı. Birinci makale genel bir tarama, ikincisi makine öğrenmesiyle risk analizi, üçüncüsü proje yönetimi bilgi alanlarının başarısızlığının tahminidir.

### 6.1 Makine öğrenmesinin yazılım proje değerlendirmesine faydaları

İlk makalenin araştırma soruları, proje yönetimi planlama değerlendirmesinde makine öğrenmesi tekniklerini kullanan mevcut çalışmaların neler olduğu ve bu tekniklerin ne derece etkili ve verimli kullanılabildiğidir. Makale 60-70 çalışmayı bir tabloda karşılaştırmış, kullanılan yöntemleri ve katkıları belgelemiştir. Hoca ayrıntılı tablo yerine özet istedi.

Slayttaki şekil (2020 8th International Conference on Information Technology and Multimedia, ICIMU) faydaları dört grupta toplar (ekrandan, 02:10:00):

- **Tahmin maliyeti değerlendirme modeli:** hata tahmin modelleri, yazılım kalite güvencesi.
- **Risk yönetimi:** efor tahmini, risk yönetimi, risk değerlendirme ve risk kontrolü.
- **Küresel yazılım geliştirme (GSD):** yazılım geliştirmede iş birliği, çevik uygulamalar, yönetim ve koordinasyon.
- **Uzman tabanlı ölçümler:** eforu tahmin etmede uzmanlık, uzman tabanlı ölçümler.

Makine öğrenmesiyle risk değerlendirmesi ve kontrolü daha yönetilebilir ve öngörülebilir hale gelir; kalite güvencesi artar; farklı lokasyonlarda yürütülen projelerde koordinasyon daha hızlı ve sağlıklı ilerler.

Literatürde proje başarısı ve başarısızlığının tanımı da tartışılmıştır. Bir çalışmaya göre başarılı bir proje, üzerinde anlaşılmış bir zaman çizelgesi olan, istenen sonuçları net, sınırları çizilmiş ve kaynakları tanımlanmış bir projedir. Bir başka çalışma, proje sonucunun kalitesini gerekli özellik ve işlevlere bağlar; sınırları net, paydaşları ve ihtiyaçları iyi belirlenmiş, takvimi, riskleri ve yedek planları net bir proje planının daha başarılı olacağını savunur. Çalışmaların bir kısmı veriyi anketle toplamış, bir kısmı mevcut verilerdeki parametreleri deneysel olarak değiştirerek modellerin doğruluk, ROC ve F1 değerlerini karşılaştırmıştır.

Bu makalede ayrıca 66 çalışmadan altı önemli parametre çıkarılmıştır: proje paydaşlarını belirleyip görüşlerini almak, ihtiyaçları belirlemek, proje sınırlarını belirlemek, gereksinimler için standart şablonlar hazırlamak, gereksinimlerin standartlara uyup uymadığını kontrol etmek ve her ihtiyacı benzersiz biçimde tanımlamak. Ankete dayalı bölümde 56 uzman yer almıştır.

### 6.2 Atropos modeli

Atropos modeli geçmiş projelerden yararlanarak yeni projeye risk öneren döngüsel bir modeldir (ekrandan, 02:15:00). Bileşenleri:

- **Veri:** projeler, riskler ve tespit edilen problemler.
- **Özelliklere göre benzerlik:** proje özelliklerine (alan, metodoloji, büyüklük, evrim) göre benzerlik analizi.
- **Bağlam geçmişleri:** bağlamları yakalayıp bağlam geçmişi oluşturma.
- **Bağlam geçmişlerine göre benzerlik:** zaman içindeki evrime göre benzerlik, projeler ve riskler arası benzerlik.
- **Öneri:** projeye yeni risklerin önerilmesi.
- **Risk yönetimi:** tanımlama, nitel analiz, nicel analiz, yanıt ve izleme süreçleri.

Model bir finans şirketinin 153 yazılım projesinden toplanan verilere dayanır. Değerlendirmede %73 kabul oranı ve %83 doğruluk elde edilmiş, sonuçlar 18 uzman tarafından da değerlendirilmiştir.

### 6.3 Küresel yazılım geliştirmede risk tahmini

İkinci makale iki soruya cevap arar: küresel yazılım geliştirme (GSD) için hangi risk faktörleri önemlidir ve risk tahminini önemli ölçüde etkiler; GSD'de risk tahmini için en iyi makine öğrenmesi teknikleri hangileridir. Amaç, bir yazılım projesinin genel başarısını ya da başarısızlığını etkileyen en önemli faktörleri deneysel veri analiziyle belirlemek ve lojistik regresyon, karar ağacı, random forest, destek vektör makinesi (SVM), K en yakın komşu (KNN) ve Naive Bayes ile risk tahmin modelleri geliştirip karşılaştırmaktır. Sunucuya göre makale International Journal of Advanced Computer Science dergisinde yayımlanmıştır.

Çalışmanın fazları literatür taraması, veri kümesi seçimi, ön işleme, modelleme, deneysel değerlendirme ve risk tahmin sonuçlarıdır. Literatür birleştirme, filtreleme ve kategorizasyon adımlarıyla taranmıştır. Veri seti, dış kaynak kullanımında deneyimli ve GSD uygulayan kuruluşlara odaklanan bir anket ve görüşmelerle toplanmış, 140 yazılım projesinden oluşmaktadır.

Risk faktörleri dört grupta 18 faktördür (ekrandan, 02:20:00):

- **Gereksinim faktörleri:** gereksinim belirsizliği, gereksinim değişiklikleri, gereksinim kapsamı, yeni teknolojiler, proje büyüklüğü.
- **Yönetim faktörleri:** proje yöneticisinin yetkinlik düzeyi, planlama yapılmaması ya da yetersiz planlama, paydaşların düşük bağlılığı, ilerleme ölçümü, maliyet dengesi, rol ve sorumlulukların eksikliği, ekip büyüklüğü.
- **Teknik faktörler:** personelin gerekli becerilere sahip olmaması, istikrarsız organizasyon ortamı, izlenen metodoloji, iletişim altyapısı ve süreci.
- **Kültürel faktörler:** dil ve kültür, saat dilimi farkı.

Hoca bu faktörlerin risk faktörleri olup olmadığını sordu; sunucu, parametrelerin risk faktörleri olarak belirlenip tabloya döküldüğünü doğruladı. <!-- BELİRSİZ: sunucu sözlü olarak "1800 parametre" dedi; bağlama ve kareye göre doğrusu 18 faktördür. -->

Yöntem: ön işleme, özellik dönüşümü, özellik seçimi; veri %80 eğitim, %20 test olarak bölünmüş; modeller eğitilip test edilmiş, doğruluk ve F1 değerleri karşılaştırılmıştır. Sonuçta lojistik regresyon ve random forest en yüksek doğruluğu vermiştir. Sunucunun hatırladığına göre bu değerler sırasıyla yaklaşık %89 ve %85'tir. <!-- BELİRSİZ: bu doğruluk değerleri slaytta görülmedi, sunucunun hatırladığı değerlerdir. --> Gelecek çalışma olarak veri setinin büyütülmesi, bulguların genelleştirilmesi ve algoritmaların doğruluğunun artırılması önerilmiştir.

### 6.4 Proje yönetimi bilgi alanlarının başarısızlığının tahmini

Üçüncü makale Etiyopya'daki gerçek proje verilerine dayanır. Etiyopya'da yazılım projelerinin işlevselliği, zamanlaması, bütçesi ve riskleri, proje yönetimi bilgi alanları hakkındaki bilgi eksikliği nedeniyle düzgün yönetilememektedir. Başarısızlığı önlemenin bir yolu, proje yöneticilerinin beceri boşluklarını dolduracak bilgi birikimini artırmaktır, çünkü bilgi alanları yazılım proje yönetiminin kilit konularıdır. Çalışma, proje yöneticilerine belirli bir projede hangi bilgi alanının başarısız olacağını tahmin etmede yardım etmeyi amaçlar.

Özellikler literatür taramasıyla belirlenmiş, sonra belirsizlik, tutarlılık, ölçülebilirlik ve uygulanabilirlik ölçütleriyle değerlendirilmiştir. Model üç bağlam içerir: proje yöneticisi bağlamı, proje bağlamı ve şirket bağlamı. Toplam 443 kayıt ve 9 öznitelik kullanılmış; veri kümesine gürültü giderme ve eksik değer işleme uygulanmıştır (ekrandan, 02:25:00). Modeller karar ağaçları, lojistik regresyon, Naive Bayes, KNN ve SVM'dir; performans doğruluk, kesinlik (precision) ve duyarlılıkla (recall) ölçülmüş, sonuçlar 9 öznitelik ve 10 bilgi alanını içeren gerçek verilerle karşılaştırılmıştır.

Test verileri üzerindeki karşılaştırma (ekrandan, 02:25:00):

| Algoritma | Doğru tahmin | Yanlış tahmin | Doğruluk (%) |
|---|---|---|---|
| K en yakın komşu (KNN) | 78 | 11 | 87,64 |
| Lojistik regresyon (LR) | 68 | 21 | 76,4 |
| Destek vektör makinesi (SVM) | 82 | 7 | 92,13 |
| Karar ağaçları (DT) | 80 | 9 | 90 |
| Naive Bayes (NB) | 58 | 31 | 66 |

Her model 89 test örneği üzerinde değerlendirilmiştir ($78+11 = 89$). Doğruluk = doğru tahmin / toplam; örneğin SVM için $82/89 \approx 0{,}9213$. En yüksek doğruluk SVM'dedir.

> **Ders sonrası not:** Sunucu SVM'nin "%82 doğru tahmin ettiğini" söyledi; 82 doğru tahmin sayısıdır, doğruluk %92,13'tür. Ayrıca tablodaki Naive Bayes değeri $58/89 \approx \%65{,}17$ olarak hesaplanır; slayttaki 66 büyük olasılıkla yuvarlama ya da aktarım farkıdır. Karar ağacı için $80/89 \approx \%89{,}89$, slaytta 90'a yuvarlanmıştır.

**Soru:** Destek vektör makinesi nedir, diğerlerinden farkı ve üstünlüğü nedir? **Cevap:** Sunucu, SVM'nin sınıflandırma problemlerinde kullanılan gözetimli öğrenme yöntemlerinden biri olduğunu ve küçük ve orta büyüklükteki veri setleri için diğerlerine göre daha uygun olduğunu söyledi.

> **Ek bilgi (derste anlatılmadı):** SVM, iki sınıfı ayıran ve sınıflara en yakın noktalara (destek vektörleri) uzaklığı en büyük olan hiper düzlemi arar. Bu "en geniş marj" ilkesi, az veriyle bile iyi genelleme yapmasını sağlar. Doğrusal ayrılamayan verilerde çekirdek (kernel) fonksiyonlarıyla veriyi daha yüksek boyutlu bir uzaya taşıyarak çalışır.

Gelecek çalışma olarak, derin öğrenme yaklaşımlarıyla birden fazla başarısız proje veri kümesini derleyip analiz etmek ve sonuçları bu çalışmanın sonuçlarıyla karşılaştırmak önerilmiştir (ekrandan, 02:30:00). Ampirik araştırmalar gerçek dünya verilerine dayanarak projelerin farklı bilgi alanlarında ne kadar başarılı olduğunu analiz eden çalışmalardır; süreçlerin etkinliğini değerlendirmek, iyileştirme fırsatlarını belirlemek ve gelecekteki projeler için öngörüde bulunmak amacıyla yapılır. Derin öğrenme yaklaşımları karmaşık veri setlerindeki kalıpları öğrenerek risk, zaman, maliyet ya da kalite yönetimi gibi bilgi alanlarının başarısızlıkla ilişkisini belirleyebilir. Böylece proje yöneticilerine bir projede hangi bilgi alanlarının zayıf olduğunu ve hangi alanlara odaklanmaları gerektiğini önceden bildirmek hedeflenir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:19:24 ve 00:20:11): Bir ankette ki-kare testi ne amaçla kullanılır? İlişkili iki soruya çelişkili yanıt veren bir katılımcının yanıtlarına güvenilmemesiyle ilgisi nedir?

> **Çözüm:** Ki-kare testi kategorik değişkenler arasındaki ilişkinin şansa bağlı olmadığını sınar. Sunulan çalışmada yanıtlar bu testle sınanmış, belirli bir değerin altında kalan yanıtlar geçerli sayılmayıp elenmiştir. İlişkinin gücü ise Cramér'in V katsayısıyla ölçülür: $V = \sqrt{\chi^2 / (n(k-1))}$.

**Soru 2** (derste sözlü, 00:39:40): Balık kılçığı diyagramında nedenler etki faktörü en büyük olandan başlayarak mı sıralanır?

> **Çözüm:** Nedenler önce ana başlıklar ve alt başlıklar altında diyagrama yerleştirilir, sonra ekipçe puanlanarak önceliklendirilir ve değerlendirilir. En yüksek puanı alan neden asıl sebep olarak ele alınır.

**Soru 3** (derste sözlü, 01:19:43 ve 01:20:09): Q-Rapids çalışmasında gösterilen GitLab süreç panosunda kırmızı ve yeşil etiketler neyi gösterir?

> **Çözüm:** Kırmızı etiketler hata (bug) kayıtlarını, yeşil etiketler sprint içinde bitmiş görevleri gösterir. Pano görevleri etiketlere göre açık, sprint birikimi, üzerinde çalışılan, birleştirme isteği, hazır, test, sprintte kapanan ve kapalı sütunlarına ayırır.

**Soru 4** (derste sözlü, 01:35:14): Bir proje planında "kabuller ve kısıtlar" nasıl yazılmalıdır?

> **Çözüm:** Ayrı iki liste olarak yazılmalıdır. Kabuller olumlu varsayımlardır ("bir problem çıkmayacağını varsayıyoruz"). Kısıtlar projenin konu ya da teknik olanaklar açısından sınırlarıdır ("ekipte beş kişi var, biri şu tarihten itibaren izinli olacak").

**Soru 5** (ekrandan, 01:40:00): E-ticaret projesinin risk tablosunda önem = olasılık × etki olarak verilmiştir. Dört riskin önem değerlerini hesaplayıp sıralayın.

> **Çözüm (derste verilmedi):** Çalışan ayrılması $0{,}20 \times 4 = 0{,}8$; bütçe yetersizliği $0{,}10 \times 3 = 0{,}3$; sistemin az kişi tarafından kullanılması $0{,}60 \times 4 = 2{,}4$; hosting servisi problemleri $0{,}05 \times 5 = 0{,}25$. Sıralama: az kullanım (2,4) > çalışan ayrılması (0,8) > bütçe yetersizliği (0,3) > hosting problemleri (0,25). Sunucu da en büyük riskin az kullanım olduğunu söylemişti.

**Soru 6** (derste sözlü, 02:25:33): Destek vektör makinesi nedir, diğer sınıflandırma yöntemlerinden farkı nedir?

> **Çözüm:** Derste verilen cevaba göre SVM sınıflandırma problemlerinde kullanılan gözetimli bir öğrenme yöntemidir ve küçük ile orta büyüklükteki veri setlerinde diğer yöntemlere göre daha uygundur. Sunulan çalışmada 89 test örneğinin 82'sini doğru sınıflandırarak en yüksek doğruluğu (%92,13) vermiştir.

## Dersin Toparlaması

Bu derste makale sunumları tamamlandı ve proje planı sunumlarına başlandı. Makaleler yazılım proje yönetiminin farklı yüzlerini gösterdi: start-up'larda mühendislik uygulamalarının yaşam döngüsü aşamalarına göre nasıl değiştiği, riskleri balık kılçığı diyagramıyla tanımlayıp sınıflandırma, çevik bir ekipte GitLab verilerinden GQM ile süreç metrikleri türetip Q-Rapids paneliyle izleme ve makine öğrenmesiyle proje riski ya da başarısızlığı tahmin etme. Bu çalışmaların ortak noktası, planlama ve kontrol eksikliğinin bütçe ve zaman aşımına yol açtığı ve ölçmenin, izlemenin ve geçmiş verilerden öğrenmenin proje başarısını artırdığıdır.

Proje planı sunumları ise bir proje planının bölümlerini somutlaştırdı: kapsam ve gereksinimler, ekip yapısı, kabuller ve kısıtlar, süreç modeli seçimi ve gerekçesi, iş kırılım yapısı ve Gantt şeması, bütçe, risk planı (olasılık × etki) ve projenin kapatılması. Hocanın kabuller ile kısıtların ayrı listelenmesi gerektiği uyarısı proje planı hazırlarken dikkat edilmesi gereken bir noktadır. Sonraki derste diğer öğrencilerin proje planı sunumlarına devam edileceği belirtildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
