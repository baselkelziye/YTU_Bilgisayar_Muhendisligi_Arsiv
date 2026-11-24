# Ders 3 Çalışma Özeti

## Genel Konular

- Bileşen tabanlı (component-based) uygulama geliştirme
  - Uygulamanın mümkün olduğunca hazır yazılım bileşenlerinden oluşturulmasını öngörür (ekrandan, 00:35:00).
  - Aşamaları: konu alanı mühendisliği (domain engineering), aday bileşenlerin sınıflandırılması ve seçilmesi (qualification), seçilen bileşenlerin kendi yazılımımıza uyarlanması (adaptation), bileşenlerin bir araya getirilmesi (composition).
  - Artısı yeniden kullanımın özendirilmesidir; eksileri uygun bileşenin her zaman bulunamaması ve bileşen uyarlamanın göründüğü kadar kolay olmamasıdır.
  - Ana fikirleri, özellikle hızlı uygulama geliştirme (RAD) olmak üzere başka süreçlere uygulanabilir.
- Artımsal / yinelemeli modeller (incremental / iterative)
  - Analiz, tasarım, kodlama ve sınama adımları çevrimsel olarak yürütülür; bütün gereksinimler gerçeklenince yazılım bakım aşamasına geçer (ekrandan, 00:45:00).
  - Yeni bir işlev eklemek artım, hata düzeltme ya da değişen gereksinimi karşılamak için yapılan çevrim yinelemedir.
  - Gereksinimler önemlerine ve birbirine bağımlılıklarına göre sıralanır, her yinelemede bir kısmı tamamlanır.
  - Ön ürün modeli ile ardışıl modelin güçlü yönlerini birleştirir ve nesneye yönelik programlamayla uyumludur.
  - Eksisi: küçük artımlara fazla yoğunlaşıp sistemin bütününü gözden kaçırma ("miyopi", ağaçlara bakarken ormanı görmemek).
- Sarmal (spiral) model
  - Altı aşama: müşteri ile iletişim (gereksinimlerin belirlenmesi), planlama (kaynaklar, zamanlama, yapılacaklar), risk analizi (teknik, mali, politik), mühendislik (çözümleme ve tasarım), gerçekleme ve kurulum (kullanıcı eğitimi ve dokümantasyon dahil), müşteri tarafından ürünün değerlendirilmesi (ekrandan, 00:50:00).
  - Literatüre katkısı risk yönetiminin her çevrimde sürekli yapılmasıdır.
- Kazan-kazan (WinWin) modeli
  - Aşamalar: ilgililerin (paydaşların) belirlenmesi, kazanma durumlarının belirlenmesi, uzlaşma ve seçeneklerin belirlenmesi, seçeneklerin değerlendirilmesi ve risklerin çözülmesi, gerçekleme ve kurulum, ilgililer tarafından değerlendirmeler (ekrandan, 01:00:00).
  - Paydaş (stakeholder): yazılımın başarısı ve başarısızlığının etkileyeceği kişi ve kurumlar.
  - Katkısı paydaş kavramı ve çatışan paydaş çıkarları arasında denge kurma gerekliliğidir.
- Çevik (agile) süreçler
  - Değişen gereksinimler, teknik riskler gibi önceden belirlenemeyen durumlara ve yazılımı etkileyebilecek her tür değişikliğe karşı esneklik sağlayan süreçlerdir (ekrandan, 01:25:00).
  - Çevik Manifesto: bireyler ve etkileşimler (süreçler ve gereçlere karşı), çalışan yazılım (ayrıntılı belgelere karşı), müşterinin sürece katılımı (sözleşme pazarlığına karşı), değişikliklere uyum sağlamak (bir planı izlemeye karşı). Sağdakilerin yararı kabul edilir ama soldakilere daha çok önem verilir.
  - İlerleme olmadan yalnız uyum sağlamak başarı değildir: artımsal gelişim, erken ve sık teslim, başarının birincil ölçütü olarak doğru çalışan yazılım; bu yüzden sınama ve test güdümlü tasarım (TDD) önerilir.
  - Çevik ekibin özellikleri ve çevik süreçlerin dezavantajları (ekrandan, 01:40:00 ve 01:50:00).
- Aşırı Programlama (XP: Extreme Programming)
  - Adımlar: planlama, tasarım, kodlama, sınama; her çevrim sonunda artımsal ürün (ekrandan, 02:00:00).
  - Planlama: müşteri kullanıcı öykülerini yazar ve önemine göre derecelendirir; yaklaşık 3 haftada gerçeklenemeyecek öyküler alt öykülere bölünür; sıralama ya yüksek riskli ya yüksek öncelikli öykülerle başlar.
  - İlk artımsal ürün proje hızını ölçmek için de kullanılır (ekrandan, 02:05:00).
  - Tasarım: KISS ilkesi, CRC (Class-Responsibility-Collaboration) kartları, gerekirse spike solution, refactoring (ekrandan, 02:10:00).
  - Kodlama: önce birim sınamaları, yalnız sınamayı geçecek kadar kod, çift kişiyle kodlama (pair programming) (ekrandan, 02:20:00).
  - Sınama: birim sınamalarının otomatik çalıştırılması ve müşterinin artımsal ürünü denemesi.
- Scrum
  - Adımlar: görev listesi, koşu (sprint), işlev gösterimi; isteğe bağlı pre-scrum ve post-scrum aşamaları (ekrandan, 02:25:00 ve 02:30:00).
  - Koşu süresince her gün yaklaşık 15 dakikalık, proje liderinin yönettiği kısa toplantılar ve üç ana soru.
- Çevik modelleme
  - Bir amaç için modelleme, içeriğin sunumdan önemli olması, araçların iyi öğrenilmesi ve dengenin korunması (ekrandan, 02:35:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Bileşen tabanlı modelde sınıflandırma ve seçme aşaması
  - Farklı bileşenlerin işlevleri farklı biçimlerde örtüşür; bir bileşeni seçmek diğer seçimleri kısıtlar. Bu aşamadaki yanlış kararlar önemli teknik riskler doğurur.
  - Hoca, okuduğu araştırmalara göre yeniden kullanımın sağladığı tasarrufun en fazla %30 civarında kaldığını, çünkü yeniden kullanılabilir bileşen geliştirmenin ek çaba gerektirdiğini aktardı.
- Artımsal modellerin en önemli riski "miyopi"dir
  - Küçük işlere fazla odaklanmak bütüncül bakışı kaybettirir; bunu önleyen ek adımlar uygulanırsa model vaatlerini yerine getirir.
- Risk analizi bir şemsiye etkinliktir
  - Sarmal modelde her çevrimde risk yeniden değerlendirilir; değişiklik olmasa bile problem alanı, mevzuat ve pazar izlenir.
- Çevik çalışmak belgelendirmeyi bırakmak değildir
  - Önce kodu yazıp belgelendirmeyi sonra yapmak teknik personelin en önemli yanılgılarından biridir; çevik süreçlerde teknik belgelendirme daha da önemli olabilir.
- Test edilemeyen bir şey büyük olasılıkla iyi tasarlanmamıştır
  - Bir iş başka işlerle birlikte test edilmek zorundaysa veri ve sorumluluk ayrımı iyi yapılmamıştır.
- Çevik süreçler sihirli değnek değildir
  - Uygun ekip ve kurum kültürü yoksa, ölçek büyükse ya da dış denetimin zorunlu olduğu (finans, bankacılık, sigorta gibi) projelerde çevik süreçler yetersiz kalır.
  - Çevik çalışmak disiplinsizlik demek değildir.
- Çift kişiyle kodlama, artımsal süreçlerin bütüncül bakışı kaybetme zayıflığını giderir
  - Biri eldeki soruna, diğeri sistemin bütününe ve kalite ölçütlerine odaklanır.

## Kısa Tekrar Notları

- Bileşen tabanlı geliştirme: domain engineering, qualification, adaptation, composition.
- Artım = yeni işlev; yineleme = düzeltme ya da değişiklik için çevrim.
- Artımsal modellerin eksisi: sistemin geneline bakmayı unutmak.
- Spiral modelin katkısı: sürekli risk yönetimi. WinWin modelinin katkısı: paydaşlar ve çıkar dengesi.
- Paydaş: yazılımın başarısı ya da başarısızlığından etkilenen kişi ve kurumlar.
- Çevik Manifesto'nun dört karşıtlığı: bireyler/süreçler, çalışan yazılım/belgeler, müşteri katılımı/sözleşme, değişime uyum/plan.
- Çevik ekipte yüz yüze iletişim, ortak amaç, işbirliği, güven, karar verebilme, "boşuna harcanan çaba yoktur", kendi kendini düzenleme.
- Çevik dezavantajlar: uygun olmayan ekip ve kültür, ölçek, dış denetim zorunluluğu; disiplinsizlik değildir.
- XP: planlama-tasarım-kodlama-sınama; kullanıcı öyküleri, yaklaşık 3 hafta (±1) çevrim, KISS, CRC kartı, spike solution, refactoring, önce birim testi, pair programming.
- Scrum: görev listesi (= kullanıcı öyküleri), koşu (1-4 hafta), günlük 15 dakikalık toplantı ve üç soru, işlev gösterimi.
- Çevik modelleme: neyi kime hangi düzeyde anlatacağını bil; gerekli bilgiyi içermeyen hatasız model işe yaramaz.

## Detaylı Açıklamalar

- Bileşen tabanlı geliştirmede ilk aşama problem alanını, alandaki varlıkları ve bu varlıklarla yapılacak işleri iyice anlamaktır. İkinci aşamada bu işleri hangi bileşenlerin karşılayacağına karar verilir. Örneğin bir bileşen A, B, C işlevlerini, bir başkası B, C, E işlevlerini karşılıyorsa, hangisi seçilirse seçilsin açıkta kalan işlev için başka bir bileşen gerekir ve seçimler birbirini etkiler. Değerlendirmede gereken değişiklik düzeyi ve maliyeti, yeni bileşen için ön ödeme (upfront cost) ve kalite puanları ağırlıklandırılarak bileşen setlerinin toplam değeri karşılaştırılır. Açık kaynaklı bileşenlerde kaynak kodu değiştirmek mümkündür ama bu en önemli maliyetlerden biridir; özellikle kodu başkası yazdıysa kolay değildir.
- Artımsal ve yinelemeli modellerde bir miktar analiz yapılır, sonucu tasarlanır, kodlanır, sınanır ve döngü yeniden başlar. Bütün gereksinimler gerçeklenince yazılım kullanıma alınır ve bakım başlar. İlerleme çoğunlukla artımlarla sağlanır; gereksinim değişiklikleri ve yanlış anlamalar yineleme çevrimlerini gerektirir.
- Sarmal modelde her tur: müşteriyle konuşup gereksinimlerin bir kısmını belirlemek, insan ve kod kaynaklarıyla zaman planını çıkarmak, teknik, mali ve politik riskleri olabildiğince geniş ve farklı alanlardan katılımla değerlendirmek, asıl teknik planlama olan çözümleme ve tasarımı yapmak, kodlayıp kullanıcı eğitimi ve dokümantasyonla birlikte kurmak ve müşterinin değerlendirmesini almaktır. Her çevrim sonunda kullanıcının deneyebileceği bir ürün çıktığı için gereksinim yanlış anlamaları şelale modeline göre çok daha erken fark edilir. Sonraki turda planlama müşteri geri bildirimine göre güncellenir ve risk analizi yeniden yapılır.
- Kazan-kazan modelinde paydaşlar müşterinin alt grupları, düzenleyici kurumlar ve yazılım evinin kendi birimleri (üst yönetim, yazılımcılar, sınama ekibi) olabilir. Hocanın örneğinde banka kullanıcıları kullanım kolaylığı ve performans isterken düzenleyici kurum ek kayıt, günlük dosyası ve rapor gibi denetim gereksinimleri ister; bu sisteme yük getirir. Model, çatışmaları keşfedip uzlaşma seçeneklerini belirlemeyi, değerlendirip risklerle birlikte karar vermeyi önerir.
- Çevik Manifesto'nun her maddesinde sağ taraf da önemlidir ama çelişkide sol taraf seçilir. Yazılım bir "insan işi"dir (people job); doğru kişilerle doğru biçimde çalışılmazsa diğer bileşenler ne kadar iyi olursa olsun proje başarısız olur. Sözleşme kanuni bir temel olarak gereklidir ama müşterinin sözleşmeden sonra süreçten çekilmesi istenmez, çünkü değişikliklerin kaynağı çoğunlukla müşteridir. Plan yapılmalıdır ama plan taşa yazılmaz; koşullar değiştikçe revize edilir.
- Test güdümlü tasarımda, tasarlanacak kısmın doğru çalışıp çalışmadığını nasıl sınayacağınızı önce tasarlarsınız. Bir iş tek başına test edilemiyorsa görev ve sorumluluk ayrımı iyi yapılmamıştır. Hoca, testler önce ya da bir alt birim tasarlandıktan sonra tasarlanabilir ama mutlaka tasarlanmalıdır, dedi.
- XP planlamasında müşteri öyküleri (örneğin 5'li Likert ölçeğiyle) derecelendirir, teknik ekip de öyküleri teknik risk ve karmaşıklığa göre derecelendirir. Yüksek riskliyi önce yapmak "başarısız olacaksan erken başarısız ol" mantığına dayanır; yüksek öncelikliyi önce yapmak ise riskli bir öykü gerçeklenemese bile müşteriye işe yarar bir ürün bırakır. Son söz müşterinindir. Hocanın örneğinde 10 öykü, 3 haftalık çevrimlerle 30 hafta (kaba hesapla ayda 4 haftadan yaklaşık 7 ay) sürecekken çevrimler 4 haftaya çıkınca 40 hafta (yaklaşık 10 ay) olur. Bu durumda ya plan uzatılır ya müşteri bazı öykülerden vazgeçer ya da ikisinin arasında bir uzlaşma bulunur.
- CRC kartı tek bir sınıf içindir: başlıkta sınıf adı, altında sınıfın temel sorumluluğu, varsa üst ve alt sınıfları, sol sütunda sorumluluklar, sağ sütunda bu sorumluluk için birlikte çalıştığı sınıflar yazılır. Ekip kartları paylaşır, her üye kendi destesini inceleyip itirazlarını tartışır, sonra desteler el değiştirir. Böylece bütün tasarımı herkes gözden geçirir ve kendisinin kodlamayacağı kısımlardan da haberdar olur.
- Çift kişiyle kodlamada klavyedeki programcı eldeki soruna odaklanır, yanındaki ise kodun genel tasarıma, kalite ve kodlama standartlarına ve nesneye yönelik ilkelere uygunluğunu denetler. Hoca bunu tüplü dalışta iki kişinin birbirini kollamasına benzetti.
- Scrum'da görev listesi XP'nin kullanıcı öyküleriyle aynı şekilde yönetilir. Koşu 1-4 hafta sürer. Günlük toplantıda proje lideri herkese şunları sorar: son toplantıdan bu yana ne yaptınız, ne gibi engellerle karşılaştınız, bir sonraki toplantıya kadar neyi başarmayı hedefliyorsunuz. Net yanıt veremeyenlerle toplantıdan sonra ayrıca ilgilenilir. Pre-scrum aşamasında ön analiz, risk analizi, başarı ve kalite ölçütlerinin belirlenmesi gibi işler, post-scrum aşamasında belgelendirmenin tamamlanması ve proje sonu kutlaması gibi etkinlikler tanımlanabilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
