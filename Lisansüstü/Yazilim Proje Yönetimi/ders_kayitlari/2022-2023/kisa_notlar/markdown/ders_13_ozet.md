# Ders 13 Çalışma Özeti

## Genel Konular

- Bu derste öğrenciler önce makale sunumlarını tamamladı, sonra dönem projelerinin proje planlarını sunmaya başladı. Hoca sunumların arasında sorular sordu ve kısa yorumlar yaptı. Sunumların teknik içeriği aşağıda ders sırasıyla verilmiştir.
- Start-up'larda yazılım mühendisliği hedefleri, zorlukları ve uygulamaları için bir ilerleme modeli (sunucuya göre IEEE Transactions on Software Engineering, 2019)
  - Yazılım start-up'ları yazılım odaklı ürün geliştirip pazarlayan küçük şirketlerdir. Ürün kalitesi yerine pazara çıkış süresine öncelik verirler, ekipleri küçüktür, mühendislik uygulamaları gayriresmîdir.
  - Başarısızlık oranları yüksektir; sunumda Avrupa için %77 ile %90 arası bir oran verildi. Önceki çalışmalar start-up'ların en iyi mühendislik uygulamalarını izlemediğini, rastgele bir yaklaşım benimsediğini göstermektedir.
  - Yaşam döngüsü modeli dört aşamadan oluşur (ekrandan, 00:10:00):
    - Başlangıç: ürün fikrinden ilk müşteriye ilk ürün sürümünün verilmesine kadar. İlk sürümün çok kaliteli olması gerekmez, müşterinin kullanabileceği kadar işlevi olması yeter.
    - Stabilizasyon: ilk sürümden ölçeklenmeye hazırlığa kadar. Ürünün ek çaba gerektirmeden kullanılabilir olması hedeflenir.
    - Büyüme: istenen pazar payına ve büyüme hızına ulaşma.
    - Olgunluk: pazar payını koruma, operasyonları optimize etme, kurumsal bir yapıya dönüşme.
    - Her aşamada start-up aktif kalmaya, bir sonraki aşamaya geçmeye ve hissedarlara kâr için başka bir şirket tarafından satın alınmaya çalışır. Herhangi bir aşamada durdurulabilir ya da kapatılabilir. İncelenen start-up'lar aktif, duraklatılmış, satın alınmış ve kapatılmış diye dört gruba ayrılmıştır.
  - Araştırma yöntemi: vaka anketi (case survey) yöntemi teori oluşturma yöntemiyle birleştirilmiştir. Anket iç inceleme (yazarlar arasında) ve dış inceleme (Software Startup Research Network'ün 10 üyesi) ile hazırlanmıştır (ekrandan, 00:15:00).
  - Anket 10 bölüm, 85 üst düzey soru ve 285 alt sorudan oluşur. 369 katılımcı yanıtlamaya başlamış, 84 yanıt geçerli sayılmıştır (yanıt oranı %23) (ekrandan, 00:20:00).
  - İstatistik: değişkenler arasındaki ilişkilerin şansa bağlı olmadığını sınamak için ki-kare testi; Tip I hatayı önlemek için 10 000 örnek tabloya dayanan Monte Carlo kesin testi ($p < 0{,}05$); ilişkinin gücü için Cramér'in V katsayısı (ekrandan, 00:20:00):
    - $V = \sqrt{\dfrac{\chi^2}{n\,(k-1)}}$; burada $k$, iki değişkenden daha az kategorisi olanın kategori sayısı, $n$ toplam kayıt sayısıdır.
  - Bulgular hedef (G), zorluk (C) ve uygulama (P) olarak kodlanmış, altı süreç alanında ve dört yaşam döngüsü aşamasında bir şema üzerinde gösterilmiştir. Süreç alanları: takım, gereksinim mühendisliği, değer, kalite güvencesi, mimari ve tasarım, proje yönetimi.
  - Geçerlilik sorunları: her bölümün sonunda "Bir dahaki sefere neyi farklı yapardın?" diye sorulmuştur. Katılımcı yanlılığı vardır, çünkü yanıtların kalitesi katılımcının hafızasına bağlıdır (ekrandan, 00:25:00).
  - Süreç alanlarından çıkarılan dersler:
    - Takım: takım kurmak erken aşamada yapılması gereken bir faaliyettir; mühendislik ve alan uzmanlığı ile takım içi iletişim önemlidir.
    - Gereksinim mühendisliği: start-up'lar farklı gereksinim kaynakları kullanır, müşteri taleplerini daha çok gözlem ve görüşmeyle toplar; müşteri ziyaretleri ve anketler daha az kullanılır (ekrandan, 00:30:00). Hangi özelliğin ne zaman ekleneceği, kaç müşteriye fayda sağlayacağına bakılarak belirlenir.
    - Değer: baskın görüş müşteri perspektifidir; başlangıçta müşteri ve pazar değeri, olgunlukta finansal değer ve farklılaşma öne çıkar.
    - Kalite: erken benimseyenler kusurlara daha toleranslıdır; bakım yaşam döngüsü boyunca artan bir endişe kaynağıdır.
    - Mimari ve tasarım: kararlı teknolojiler seçmek ve bunların en iyi uygulamalarını izlemek teknik riski azaltır. Çok yeni bir teknoloji belgelendirme azlığı yüzünden ters risk yaratır.
    - Proje yönetimi: PMBOK tanımına göre planlama ve kontrol, kaynak kullanımı ve hedeflere ulaşmayla ilgilenir. Planlama ve kontrol eksikliği bütçe ve zaman aşımına yol açar.
- Balık kılçığı (fishbone, Ishikawa) yöntemiyle yazılım sektöründeki risklerin değerlendirilmesi (sunucuya göre 2019 konferans bildirisi)
  - Balık kılçığı diyagramı bir problemin ya da riskin olası nedenlerini ve aralarındaki ilişkiyi görsel olarak gösteren bir sebep-sonuç diyagramıdır. Yalnız ana nedene değil, yandaki ikincil nedenlere de bakmayı sağlar.
  - Klasik ana başlıklar: insan, metot, araçlar/makine, malzeme. Bunlar bir şablondur; alana göre yeni ana başlık (örneğin kalite çalışmasında "ölçüm") eklenebilir.
  - Uygulama adımları (ekrandan, 00:40:00): ok çizilir, okun başına problem yazılır; ekip beyin fırtınasıyla ana başlıkları belirler; kılçıklara ana sebepler, altlarına alt sebepler yazılır; çözümler bulunur; asıl sebep ekipçe belirlenir. Örnek: "benzin israfı" problemi metot, makine, insan, malzeme başlıklarıyla incelenmiştir.
  - Makalede risk yönetimi sürecinin yalnız ilk üç adımı işlenir: risk tanımlama, sınıflandırma, değerlendirme.
  - Risk sınıfları: zaman (schedule), bütçe, operasyonel, teknik ve diğer kaçınılmaz riskler. Bunların nedenleri yazılım geliştirme için bir balık kılçığı diyagramına yerleştirilmiştir (ekrandan, 00:50:00).
  - Pakistan'daki yazılım şirketlerine yapılan ankette projelerin %56,6'sında takvim, %64,2'sinde bütçe değişmiş; %62,3'ünde operasyonel, %69,8'inde teknik risk sorunu yaşanmıştır (ekrandan, 00:45:00).
  - Riskler olasılık × etki ile nicel olarak değerlendirilir. Sunucunun önerdiği öncelik sırası: önce teknik riskler, sonra operasyonel ve bütçe riskleri, en son zaman riskleri.
- Küçük ölçekli bir yazılım şirketinde çevik süreçlerin ölçülmesi ve iyileştirilmesi (IEEE Access, Nisan 2020; ekrandan, 01:10:00)
  - Avrupa Birliği destekli Q-Rapids (Quality-aware rapid software development) projesi üç araştırma ortağı ve dört şirketle yürütülmüş bir endüstri-akademi iş birliğidir. Yazılım havuzları, proje yönetim araçları, sistem kullanımı ve hizmet kalitesi verilerini toplayıp analiz eder; sonuçları bir stratejik gösterge panelinde karar vericiye sunar.
  - Çalışma bir eylem araştırmasıdır. Polonya merkezli, 70-90 çalışanlı bir şirketin depo ve üretim kontrol yazılımı geliştiren Scrum ekibi (7-10 geliştirici, haftalık sprint) incelenmiştir.
  - Hedef-Soru-Metrik (GQM) yaklaşımıyla süreç metrikleri tanımlanmıştır. Veri kaynağı GitLab'dır; veriler Elasticsearch'te saklanır, Kibana ve Q-Rapids paneliyle görselleştirilir (ekrandan, 01:15:00).
  - Temel kavramlar: görev (task), iş kaydı ve hata (issue/bug), efor, geliştirme durumları arasındaki geçişler. 25 aday metrik genel, görev tahmini, görev uygulama, hata düzeltme, test ve diğer kategorilerine ayrılmıştır.
  - Sonuçlar: süreç performansı iyileşmiş, yeni özellikler eklenmesine rağmen ürün kalitesi sabit kalmıştır; görevlerin canlı izlenmesi sprint planlamasındaki tahminleri iyileştirmiştir.
- Proje planı sunumu 1: e-ticaret web uygulaması
  - Kapsam: kullanıcı ve yönetici olmak üzere iki tip kullanıcı; kayıt, ürün, satın alma ve yönetici modülleri (ekrandan, 01:30:00). İşlevsel olmayan gereksinimler: performans ve sürekli erişilebilirlik, eşzamanlı kullanıcı, farklı tarayıcılarda çalışma, güvenlik, kullanılabilirlik, yasal gereksinimler.
  - Süreç modeli şelale; gerekçe: anlaşılması ve uygulanması kolay, küçük projelere uygun, müşteriye prototip sunma zorunluluğu yok. Her adımda izleme ve kontrol yapılır (ekrandan, 01:35:00).
  - İş kırılım yapısı şelale aşamalarına göre kurulmuştur, toplam 80 gün: gereksinimler, analiz (zaman, ekonomik, teknik fizibilite), tasarım (ön ve ayrıntılı), gerçekleştirme (veri tabanı ve arayüz), test (birim, bütünleştirme, sistem, kullanıcı), bakım. Gantt şeması bu listeden çıkarılmıştır.
  - Risk tablosunda önem = olasılık × etki hesaplanmıştır (ekrandan, 01:40:00).
- Proje planı sunumu 2: kozmetik ürün içeriklerini analiz eden bir mobil uygulama
  - Barkod/QR ile okutulan kozmetik ürünlerin içeriklerini listeleyen, ürünleri kıyaslayan ve kişisel tercihlere göre öneri veren bir uygulama. Veri kaynağı Sağlık Bakanlığı'nın ürün takip sistemidir.
  - İşlevsel gereksinimler ekrandan alınmıştır (ekrandan, 01:45:00); işlevsel olmayanlar: hızlı ve oyunlaştırılmış arayüz, kişisel ve medikal verilerin şifreli saklanması, iOS ve Android uyumu.
  - SWOT analizi, çevik yöntem (Extreme Programming, iki haftalık sprintler, test odaklı geliştirme), ekip rolleri, proje planı, risk tablosu, bütçe ve sürdürülebilirlik (gelir modelleri) planlanmıştır (ekrandan, 01:55:00).
- Yazılım proje yönetiminde makine öğrenmesi (iki öğrencinin üç makalesi)
  - Bir tarama çalışması makine öğrenmesinin yazılım proje değerlendirmesine faydalarını dört grupta toplar: maliyet tahmini modeli, risk yönetimi, küresel yazılım geliştirme (GSD) ve uzman tabanlı ölçümler (ekrandan, 02:10:00).
  - Atropos modeli: geçmiş proje ve risk verilerinden benzerlik analiziyle yeni projeye risk önerir (ekrandan, 02:15:00).
  - GSD risk tahmini: 140 projeden toplanan 18 faktör (gereksinim, yönetim, teknik, kültürel) ile lojistik regresyon, karar ağacı, random forest, SVM, KNN ve Naive Bayes karşılaştırılmış; lojistik regresyon ve random forest en yüksek doğruluğu vermiştir (ekrandan, 02:20:00).
  - Etiyopya'daki projelerde proje yönetimi bilgi alanlarının başarısızlığını tahmin eden çalışma: 443 kayıt, 9 öznitelik; en iyi sonuç SVM ile %92,13 doğruluktur (ekrandan, 02:25:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Kabuller ve kısıtlar ayrı ayrı yazılmalıdır
  - Kabul (varsayım) olumlu bir öngörüdür: "şu problemin çıkmayacağını varsayıyoruz" gibi. Kısıt ise projenin sınırıdır: "ekipte beş kişi var ama biri şu tarihten itibaren izinli olacak" gibi. Proje planında iki ayrı liste olarak verilmelidir.
- Start-up'larda proje yönetiminin ihmal edilmesi
  - Hoca, start-up'ların çoğunlukla az sayıda teknik kişiden oluştuğunu, büyük projelerdeki ekip yapısı, zaman ve kaynak planı yerine "algoritmayla başlayıp ürünü çıkaralım" kaygısıyla hareket ettiğini, bunun da başarısızlığa katkı yaptığını belirtti.
- Ankette tutarsız yanıtların elenmesi
  - Hoca ki-kare testinin, birbiriyle ilişkili iki soruya çelişkili yanıt veren katılımcıların güvenilirliğini sınamak için kullanılıp kullanılmadığını sordu; sunucu bunu doğruladı.
- Balık kılçığında nedenlerin önceliklendirilmesi
  - Hoca, nedenlerin etki büyüklüğüne göre sıralanıp sıralanmayacağını sordu; sunucu nedenlerin önce yerleştirilip sonra puanlanarak önceliklendirildiğini söyledi.
- SVM'nin diğer yöntemlerden farkı
  - Hoca, sunulan makalede en iyi sonucu veren destek vektör makinesinin ne olduğunu ve diğerlerinden üstünlüğünü sordu.

## Kısa Tekrar Notları

- Start-up yaşam döngüsü: başlangıç, stabilizasyon, büyüme, olgunluk. Her aşamada aktif kalmak ve bir sonrakine geçmek hedeflenir.
- Start-up çalışmasındaki altı süreç alanı: takım, gereksinim mühendisliği, değer, kalite güvencesi, mimari ve tasarım, proje yönetimi.
- Ki-kare: ilişkinin şansa bağlı olmadığını sınar. Cramér'in V: ilişkinin gücünü ölçer.
- Balık kılçığı = sebep-sonuç diyagramı. Problem okun başında, ana nedenler kılçıklarda, alt nedenler dallarda.
- Yazılım risk sınıfları: zaman, bütçe, operasyonel, teknik, diğer kaçınılmaz riskler.
- Risk önemi = olasılık × etki.
- Q-Rapids: GitLab gibi kaynaklardan süreç verisi toplayıp GQM ile metrik tanımlayan, panelde gösteren araç.
- Kabul ile kısıt farklıdır: biri varsayım, öteki sınır.
- Şelale küçük ve gereksinimi net projelere; XP ve kısa sprintler belirsiz, hızlı değişen ürünlere uygundur.
- Makine öğrenmesiyle risk tahmininde lojistik regresyon, random forest ve SVM öne çıkan yöntemlerdir; doğruluk, kesinlik, duyarlılık ve F1 ile karşılaştırılır.

## Detaylı Açıklamalar

- **Start-up ilerleme modeli:** Çalışma, start-up'ların hangi yazılım mühendisliği uygulamalarını kullandığını ve bu uygulamaların yaşam döngüsü boyunca nasıl değiştiğini anlamayı amaçlar. Hedefler bir çabanın yöneldiği sonuçlardır, uygulamalar start-up'ın aşamalarda ilerlemesine yardım eden mühendislik faaliyetleridir, zorluklar ise bu uygulamaları gerçekleştirirken ve aşamalarda ilerlerken karşılaşılan güçlüklerdir. Şemada her bulgunun sağ üst köşesinde onu destekleyen vaka sayısı yazar. Bir hedef ve bir uygulama aynı yerde görünüyorsa uygulamanın hedefe ulaşmayla ilişkili olduğu düşünülür; bir zorluk ve bir uygulama örtüşüyorsa o uygulamanın denenip zor bulunduğu anlaşılır. Çalışmada proje yönetimi diğer alanları kapsayan genel bir çatı olarak değil, ayrı bir süreç alanı olarak ele alınmıştır.
- **Balık kılçığı ile risk analizi:** Yazılım geliştirme için kurulan diyagramda (ekrandan, 00:50:00) zaman riskinin nedenleri zaman tahmini, kaynak tahsisi, proje karmaşıklığı ve proje kapsamıdır. Bütçe riskinin nedenleri bütçe tahmini, maliyet aşımı ve kapsam genişlemesidir. Kapsamın genişlemesi hem zamanı hem bütçeyi etkiler. Operasyonel riskin nedenleri yanlış süreç uygulaması, çelişen öncelikler, iletişim eksikliği ve yetersiz eğitimdir. Teknik riskin nedenleri değişen gereksinimler, teknoloji eksikliği ve ödünleşim (trade-off) kararlarıdır. Diğer kaçınılmaz risklerin nedenleri devlet politikası, müşteri değişimi, rekabet ve dış kaynak kullanımıdır. Makale riskleri tanımlayıp anketle değerlendirmiş, ama sonuçları diyagram üzerine yerleştirmemiştir; sunucu bu adımı kendi projesinde uygulamayı önerdi.
- **Çevik süreç metrikleri:** GitLab süreç panosunda görevler etiketlerle sütunlara ayrılır: açık, sprint birikimi, üzerinde çalışılan, birleştirme isteği, hazır, test, sprintte kapanan ve kapalı (ekrandan, 01:20:00). Kırmızı etiketler hataları (bug), yeşil etiketler sprintte biten görevleri gösterir. Panelde test bekleyen iş yoğunluğu, hata olmayan iş yoğunluğu, son yedi günde çözülen iş sayısı ve tahmin girilmiş geliştirme işlerinin yoğunluğu gibi metrikler zaman serisi olarak izlenir (ekrandan, 01:15:00).
- **Proje planı içeriği:** İki proje planı sunumu, bir proje planının tipik bölümlerini örnekledi: tanım ve amaç, kapsam, işlevsel ve işlevsel olmayan gereksinimler, arayüz taslakları, ekip yapısı ve görevler, kabuller ve kısıtlar, süreç modeli ve gerekçesi, gözden geçirme kuralları, iş kırılım yapısı ve Gantt şeması, bütçe, kullanım durumu diyagramları, risk planı ve projenin kapatılması. Projenin kapatılmasında başlangıçtaki tahminler gerçekleşenlerle karşılaştırılır, gelecekteki tahminler için maliyet, zaman ve kaynak verileri saklanır.
- **Makine öğrenmesiyle başarısızlık tahmini:** Etiyopya çalışmasında özellikler literatür taramasıyla belirlenmiş, belirsizlik, tutarlılık, ölçülebilirlik ve uygulanabilirlik ölçütleriyle elenmiştir. Model proje yöneticisi, proje ve şirket bağlamı olmak üzere üç faktör içerir. Veriye gürültü giderme ve eksik değer işleme uygulanmış; KNN, lojistik regresyon, SVM, karar ağacı ve Naive Bayes doğruluk, kesinlik ve duyarlılıkla karşılaştırılmıştır. Gelecek çalışma olarak derin öğrenmeyle birden fazla başarısız proje veri kümesinin analizi önerilmiştir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
