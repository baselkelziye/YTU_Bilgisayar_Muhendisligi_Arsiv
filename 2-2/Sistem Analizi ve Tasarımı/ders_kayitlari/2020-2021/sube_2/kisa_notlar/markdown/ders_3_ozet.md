# Ders 3 Çalışma Özeti

## Genel Konular

- Sistem geliştirme yaşam döngüsünün tekrarı (ekrandan, 00:05:00)
  - Döngü şu adımlardan oluşur: Kapsam ve Planlama → Gereksinim Analizi → Tasarım → Gerçekleştirme ve Test → Kurulum ve Dağıtım → Operasyon ve Bakım → yeniden Kapsam ve Planlama.
  - Büyük ve karmaşık bir bilgi sistemi "oturup kodlayalım" diye yapılamaz; tanımlı ve tutarlı süreçlerle geliştirilir.
  - Yeni istekler, değişiklikler, güncellemeler ve hatalar döngünün tekrar tekrar işletilmesine yol açar.
- Süreç modelleri (ekrandan, 00:10:00)
  - Slaytta sayılan modeller: Klasik Süreç (Waterfall), Model Oluşturma, Evrimsel Süreçler (Artımlı Model, Spiral Model), RUP Modeli, Aykırı Programlama, Çevik Süreçler.
  - Ders kapsamında klasik süreç (şelale) modeli izlenir; modellerin ayrıntısı yazılım mühendisliği dersinde işlenir.
- Klasik süreç (Waterfall, şelale) modeli (ekrandan, 00:15:00)
  - Kökeni inşaat mühendisliğidir: bir adım bitmeden sonraki başlayamaz (zemin etüdü, temel, katlar, tesisat, test, bakım).
  - Slayttaki iki gösterim: Requirements analysis → Design → Implementation → Testing → Maintenance ve Requirement Collection → Feasibility Study → Design → Coding → Testing → Installation → Maintenance.
  - Her faz bir öncekinin çıktısıyla beslenir; geri dönüş tanımlı değildir (su şelaleden yukarı çıkamaz).
  - Gereksinimleri çok katı ve ayrıntılı tanımlı, kontratlı projelerde (devlet ihalesi, askeri proje) hâlâ uygun bir modeldir; faz sonlarında kontrol ve hak ediş takibini kolaylaştırır.
- İteratif (artımlı) waterfall
  - Waterfall'un geri dönememe eksiğini giderir: önceki adımlara geri dönülüp akış yeniden işletilebilir.
- Model (prototip) oluşturma
  - Gereksinim analizinden sonra bir prototip (taslak tasarım) oluşturulur, isteklere ne kadar cevap verdiği değerlendirilir, sürüm sürüm (0.1, 0.2 ...) işlev eklenerek son ürüne doğru geliştirilir.
- Evrimsel süreçler ve spiral model (ekrandan, 00:20:00)
  - Slayt: "Artımlı: İteratif olarak waterfall uygulanır", "Spiral: Prototipten versiyona doğru evrim ilerler".
  - Spiral modelin bölgeleri: Müşteri İletişim, Planlama, Risk Analizi, Mühendislik, Yapım ve Değişim, Müşteri Değerlendirme.
  - Halkalar içten dışa: kavram geliştirme projesi, yeni ürün geliştirme projesi, ürün zenginleştirme projesi, ürün bakım projesi.
  - Risk analizi öne çıkar: riskli işler önce yapılır ki ileride daha büyük hatalar doğmasın.
- Unified Process (RUP)
  - Nesneye yönelik analiz ve tasarımı temel alan, kullanım senaryolarını (use case) ve mimariyi merkeze koyan, artımlı ve iteratif tümleştirilmiş süreç modeli.
  - İki boyutlu bir matristir: fazlar (Inception, Elaboration, Construction, Transition) ve iş akışları (Requirements, Analysis, Design, Implementation, Test).
  - Başlarda gereksinim yükü, Elaboration'da analiz modeli, Construction'da önce tasarım sonra gerçekleştirme yükü ağırlaşır, sonda test ve devreye alma gelir. Her fazda birden çok iterasyon olabilir; iterasyonların sabit sürede yapılması önerilir.
  - Her faza bir model karşılık gelir: kullanım senaryosu modeli, analiz modeli, tasarım modeli, barındırma (dağıtım) modeli, test modeli.
- Aykırı programlama (Extreme Programming) (ekrandan, 00:25:00)
  - 4 temel değer: İletişim, Basitlik, Geri besleme, Cesaret.
  - 12 pratik: Sistem metaforu, Ekip üyesi müşteri, Kısa aralıklı yayımlar, Planlama oyunu, Basit tasarım, Ortak kod mülkiyeti, Kodlama standartları, Eşli programlama, Test, Sürekli tümleştirme, Devamlı yeniden tasarım, Devam ettirilebilir hız: 40 saat/hafta.
- Çevik süreçler ve Scrum
  - Küçük ekipler, her gün kısa bir toplantı, büyük çevrim sonunda değerlendirme toplantısı ve geri besleme.
  - Görevler bir pano üzerinde izlenir; az dokümantasyon, gereksinimler için kullanıcı hikâyeleri (user story), sabit aralıklarla sürüm çıkarma.
- Ön inceleme (ekrandan, 00:35:00)
  - Fizibilitenin ilk aşamasıdır; projenin olabilirliği kabaca belirlenir.
  - Sorular: Projeye (yeni sisteme) gerçekte ihtiyaç var mı? Sistemin gerçekleştirilmesi için neye ihtiyaç var? Ne kadar süreye ihtiyaç var? Tahmini bütçe nedir? Faydaları ve zorlukları nelerdir?
  - Kısaca: "Tamam mı? Devam mı?"
  - Çıktısı kapsam tanımlama dokümanıdır (Project Charter): ürün, kalite tanımları, zaman, maliyet ve kaynaklar ana hatlarıyla yazılır.
- Fizibilite (yapılabilirlik etüdü) çalışması (ekrandan, 00:40:00)
  - Amaç: projenin olabilirliğinin araştırılması.
  - Çıktı: genel hatlarıyla proje planı (iş-zaman planı, iş kırılım yapısı) ve tahmini bütçe; alternatifler genellikle tablo ile karşılaştırılır.
  - 6 fizibilite türü: teknik, zaman, sosyal (operasyonel), yönetim, yasal, ekonomik.
- Teknik fizibilite (ekrandan, 00:45:00)
  - Sistemin her türlü teknik olanağının belirlenmesi.
  - Yazılım fizibilitesi: işletim sistemi, yazılım geliştirme ortamı, VTYS, uygulama sunucusu, destek yazılımlar.
  - Donanım fizibilitesi: geliştirme ihtiyaçları ve kısa-orta vadede büyüyecek ihtiyaçlar.
  - İletişim fizibilitesi: haberleşme ihtiyaçları, protokoller.
  - Riskler göz önünde tutulmalı, teknik yetersizlikler tamamlanmalı.
- Sosyal (operasyonel) fizibilite (ekrandan, 00:55:00)
  - Oluşturulacak sistemin hedef kitlesi tarafından kabul edilip edilmeyeceğinin araştırılması; sistemden doğrudan etkilenecek kullanıcı grupları incelenir; isteklerin karşılanması önemlidir.
- Yönetim fizibilitesi (ekrandan, 01:10:00)
  - Geliştirilecek sistem yönetimi nasıl etkiliyor? Yönetim sistemden ne kadar fayda sağlayacak?
  - MIS, DSS gibi yönetime hizmet eden sistemlerde özellikle önemlidir.
- Yasal fizibilite (ekrandan, 01:15:00)
  - Sistem kanun ve yönetmeliklere uygun mu? Mevcut patent ve fikri sınai hakları ihlal ediyor mu? Belli kaynakların kullanımı için özel izinlere ve lisanslara gerek var mı? Sistem işletmenin yaptığı anlaşmalara uygun mu?
- Ekonomik fizibilite
  - Bütün fizibilitelerden doğan maliyetler bir araya getirilir ve maliyet-fayda analizi yapılır.
  - 4 değerlendirme yöntemi: bugünkü değer, iç verim oranı, başa baş noktası, geri ödeme süresi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Donanım fizibilitesi yalnız geliştirme bilgisayarlarının karşılaştırılması değildir
  - Sistemin bütün işletme ömrü boyunca çalışması, devrede tutulması ve büyümesi için gereken sunucu, depolama, sanallaştırma, okuyucu cihaz gibi ihtiyaçlar alternatifleriyle karşılaştırılmalıdır.
  - Bugün bin kullanıcıya hizmet eden sistem yarın on bin, yüz bin kullanıcıya çıkabilir; beş yıllık plan düşünülmelidir.
- Yasal fizibilite "sistem hiçbir yasayı çiğnememektedir" cümlesi değildir
  - Kanunların (örneğin kişisel verilerin korunması, fikri ve sınai mülkiyet) getirdiği yükümlülüklerin sisteme ne eklediği, ne kadar teknik, zaman ve maliyet yükü getirdiği alternatifleriyle tartılmalıdır.
  - Patent, lisans (tek seferlik, işlem başına, abonelik) ve işletmenin mevcut anlaşmaları da incelenir.
- Hatalar ne kadar erken bulunursa o kadar az sorun çıkar
  - Ön inceleme ve fizibilitede yapılan dikkatli değerlendirme, ileride büyük geri dönüşleri önler ("kar topuyken içindeki taşı almak").
- Her projede altı fizibilitenin hepsi gerekmeyebilir
  - Kurum içi bir işte yasal ya da sosyal fizibilite gerekmeyebilir; müşteriye yönelik ve sözleşmeli işlerde çoğu gerekir. Dönem projesinde deneyim kazanmak için hepsinin yapılması tavsiye edildi.
- Waterfall eski gibi görünse de katı gereksinimli kontratlı projelerde hâlâ en uygun model olabilir.

## Kısa Tekrar Notları

- Yaşam döngüsü: Kapsam ve Planlama → Gereksinim Analizi → Tasarım → Gerçekleştirme ve Test → Kurulum ve Dağıtım → Operasyon ve Bakım.
- Waterfall: sıralı, geri dönüşsüz; iteratif waterfall geri dönüşe izin verir.
- Prototip modeli: prototipten başlayıp sürüm sürüm son ürüne evrilir.
- Spiral: müşteri iletişimi, planlama, risk analizi, mühendislik, yapım, müşteri değerlendirme döngüleri.
- RUP: fazlar (Inception, Elaboration, Construction, Transition) × iş akışları (Requirements, Analysis, Design, Implementation, Test).
- XP: 4 değer (iletişim, basitlik, geri besleme, cesaret), 12 pratik.
- Ön inceleme: "Tamam mı? Devam mı?"; çıktısı kapsam dokümanı (Project Charter).
- Fizibilite türleri: teknik, zaman, sosyal (operasyonel), yönetim, yasal, ekonomik.
- Teknik fizibilite = yazılım + donanım + iletişim fizibilitesi.
- Ekonomik değerlendirme: bugünkü değer, iç verim oranı, başa baş noktası, geri ödeme süresi.
- Bugünkü değer: net nakit girişleri > yatırım harcamaları ise proje kabul, değilse red.
- Başa baş noktası: toplam gider ve toplam gelir eğrilerinin kesiştiği nokta; sıfıra ne kadar yakınsa o kadar iyi.

## Detaylı Açıklamalar

- Süreç modellerinin gelişimi
  - Waterfall'da her faz tamamen bitirilir ve sonraki faza geçilir. Hoca bunu inşaata benzetti: zemin etüdü yapılmadan temel kazılmaz, temel bitmeden kat çıkılmaz. Bilgi sisteminde de gereksinim analizi, tasarım, gerçekleştirme, test ve bakım bu sırayla yapılır; adım sayısı (örneğin gereksinim toplama ve fizibilite ayrı yazılarak) artırılabilir. Hoca slayttaki ikinci gösterimde gereksinim toplamanın fizibiliteden önce yazıldığını, kendilerinin fizibiliteyi genellikle önce yapmayı tercih ettiğini söyledi. Sonraki bir fazda önceki bir hatanın fark edilmesi bu modelde "kötü olur"; bu yüzden her adımın hatasız tamamlanması esastır.
  - İteratif waterfall'u hoca şelalenin altına konmuş bir su pompasına benzetti: gerekirse su (iş) tasarıma kadar geri basılıp yeniden akıtılır.
  - Prototip modelinde gereksinim analizinden sonra taslak bir tasarım ve model kurulur, isteklere ne kadar cevap verdiğine bakılır, işlevler eklenerek gereksinimlerin hepsi karşılanana kadar geliştirilir.
  - Spiral model evrimsel süreçlerdendir: içteki çekirdekten (kavram geliştirme) başlanır, her turda müşteri iletişimi, planlama, risk analizi, mühendislik, yapım ve müşteri değerlendirmesinden geçilerek dışa doğru (yeni ürün, ürün zenginleştirme, ürün bakım) ilerlenir.
  - Unified Process, Rational firmasının nesneye yönelik analiz ve tasarım yaklaşımlarına dayanan, önceki modellerin iyi yanlarını birleştiren bir modeldir. Matriste sol üstten sağ alta doğru iş yoğunluğunun kaydığı görülür. Her faza karşılık bir model üretilir ve süreç modellere (diyagramlara) dayalı yürütülür.
  - Extreme Programming eski alışkanlıkları bırakmayı önerir. Müşteri ekibin üyesi olur, kısa aralıklarla sürüm çıkarılır, tasarım basit tutulur, kodun mülkiyeti ortaktır (suç bir kişiye atılmaz), iki kişi tek bilgisayarda eşli programlama yapar, test ihmal edilmez, kod sürekli tümleştirilir (ortak bir sürüm kontrol deposunda tutulur), haftada 40 saat gibi sabit ve sürdürülebilir bir hızla çalışılır.
  - Scrum'da küçük ekipler, günlük kısa toplantılar, büyük çevrim sonunda değerlendirme toplantısı, panoda görev takibi ve kullanıcı hikâyeleri kullanılır.
- Ön inceleme
  - Bir iş birimi ya da müşteri yeni bir sistem talep ettiğinde, ayrıntıya girmeden "bu projeyi kabul ediyor muyuz?" sorusu cevaplanır. Kaynaklar (zaman, iş gücü, bilgi birikimi, maddi imkân) kabaca değerlendirilir.
  - Hocanın örneği: proje 4 adet yaklaşık 1000 dolarlık grafik kartı (toplam 4000 dolar, o günkü kurla yaklaşık 32 bin lira) gerektiriyor ama şirketin sermayesi 10 bin lira ise proje reddedilir.
  - Bir başka örnek: büyük bir ihalede istenen proje deneyimi, ekip yetkinliği ya da teminat sağlanamıyorsa ihaleye girilmez. Çok sayıda sistemle tümleşik bir işlem sistemi 5 kişilik, başka projelerle meşgul bir ekipten bir ayda istenirse yapılamaz.
  - Kapsam tanımlama dokümanının tek bir doğru biçimi yoktur; ürün, kalite (performans, kod kalitesi, birim zamanda işlem miktarı, gerekirse askeri standartlar), zaman, maliyet ve kaynaklar ana hatlarıyla yazılır. Bu bir niyet beyanıdır.
- Teknik fizibilite
  - Yazılım fizibilitesinde her yazılım kalemi için 2-3 aday karşılaştırılır. Örneğin konteyner ve mikro servis mimarisinde Windows lisans, bakım ve kararlılık sorunları getirebilir; Linux'ta yetkin eleman bulmak zor olabilir; BSD gibi bir seçenek de düşünülebilir. Geliştirme ortamı (.NET ve Visual Studio, IBM ürün ailesi, Eclipse gibi açık kaynak araçlar), VTYS, uygulama sunucusu ve destek yazılımları için de maliyet, eğitim ihtiyacı, deneyim ve topluluk desteği karşılaştırılır.
  - Donanım fizibilitesinde yalnız iki geliştirme dizüstü bilgisayarını karşılaştırmak yetmez. Sistemin nerede çalışacağı (adanmış sunucu, kiralanan sanal sunucu, hipervizör üzerinde sanal makineler), trafik büyüdüğünde ihtiyacın nasıl değişeceği, hatta stok takibinde barkod, lazer okuyucu ya da tablet kamerası seçenekleri değerlendirilir.
  - İletişim fizibilitesinde bant genişliğinin kullanıcı sayısıyla nasıl artacağı, yedekli hat, felaket ve kesinti durumunda davranış ve protokol seçimi (örneğin dosya transferinde FTP ya da başka bir yöntem) değerlendirilir.
  - Yüksek risk tehlike demektir; seçimlerde riski düşük olan tercih edilir, eksik kalan yetkinlikler giderilmeye çalışılır.
- Sosyal, yönetim ve yasal fizibilite
  - Sosyal fizibilitede yalnız sistemden doğrudan etkilenecek gruplar incelenir (stokla ilgili bir sistem için muhasebe incelenmez). Kullanıcılardan "ekranlarda kayboluyorum" gibi şikâyetler geliyorsa sosyal fizibilite iyi yapılmamıştır. Bu türün diğer adı operasyonel fizibilitedir.
  - Yönetim fizibilitesi orta ve üst yönetimin sistemden ne kadar fayda sağlayacağını ve sistemi kabul edip etmeyeceğini tartar.
  - Yasal fizibilitede, örneğin öğrencilerin ders notlarını paylaştığı bir sistemde fikri haklar ve kişisel verilerin korunması incelenir. Kişisel veri işleyen bir sistemde kullanıcı sözleşmesinin onaylatılması ve kullanıcının isteği üzerine verilerinin silinmesi gibi yeni işlevler gerekir; şifreleme gibi ek teknik çözümler teknik, zaman ve maliyet tarafına da yük getirir. Lisansların ödeme biçimi ve işletmenin imzaladığı anlaşmalar (örneğin belli bir güç tüketiminin üstünde sunucu kullanmamayı gerektiren bir çevre anlaşması) da bu başlıkta incelenir.
- Ekonomik fizibilite
  - Bugünkü değer yöntemi (ekrandan, 01:30:00): projenin bütün nakit giriş ve çıkışları bugünkü değere indirilip karşılaştırılır. Net nakit girişleri > yatırım harcamaları ise proje kabul, değilse red. İndirgemek için iskonto oranı kullanılır; en pratiği piyasadaki ağırlıklı sektörlerin uyguladığı faiz oranlarının ortalamasıdır. Slayttaki formül: $Q$ yıl, $i$ iskonto oranı, $V$ indirgenmiş nakit akışı toplamı ise $V = Q_0 \frac{Q_n}{(1+i)^n}$.
  - Ders sonrası not: Slayttaki formül büyük olasılıkla eksik yazılmıştır. İndirgenmiş nakit akışı toplamının yaygın yazımı $V = \sum_{n=0}^{N} \frac{Q_n}{(1+i)^n}$ biçimindedir; burada $Q_n$, $n$. yılın nakit akışıdır.
  - Hocanın sözlü örneği: bugün 10 lira harcayıp iki yıl sonra 20 lira kazanmak kârlı görünür, ama o 20 lira bugünün 8 lirasına denk geliyorsa aslında 2 lira zarar edilir.
  - Hoca, 1 liranın 9 yıl sonraki bugünkü değerini yıllık oranlara göre sözlü olarak verdi: %2 için yaklaşık 84, %3 için 77, %4 için 70, %5 için 65 kuruş. Bu değerler $1/(1+i)^9$ ile uyuşur (python ile doğrulandı). <!-- BELİRSİZ: Hoca %1 için 87 kuruş dedi; 1/(1,01)^9 ≈ 0,914 çıkar. Tablo karede görünmediği için slayttaki değer doğrulanamadı. -->
  - İç verim oranı (ekrandan, 01:35:00): paranın zaman değeri ve yatırımın ekonomik ömrü dikkate alınır. İVO, nakit girişleri ile yatırım maliyetini eşitleyen iskonto oranıdır. $T$ yatırımın ömür yılı, $x$ toplam maliyet, $R_t$ $t$ yılındaki net getiri, $d$ iskonto oranı için $x = \sum_{t=1}^{T} \frac{R_t}{(1+d)^t}$ eşitliğini sağlayan $d$ bulunur. Bulunan oran beklentiden düşükse yatırım verimli sayılmaz.
  - Başa baş noktası: sabit maliyetler (lisans, sunucu kirası, bakım personeli maaşı gibi) yatay bir doğru, üretim maliyetleri sabitten başlayarak artan bir eğri, toplam gelir sıfırdan başlayarak artan bir eğri olarak çizilir. Gider ve gelir eğrilerinin kesiştiği nokta başa baş noktasıdır; bu noktadan sonra kâr başlar. Nokta başlangıca ne kadar yakınsa o kadar iyidir. Hoca bu yöntemi daha çok tercih ettiklerini söyledi.
  - Geri ödeme süresi (ekrandan, 01:40:00): gerekli yatırım ile yıllık yarar arasındaki ilişkiye bakılır; başlangıçtaki nakit yatırımlarının kaç yılda geri kazanılacağı belirlenir. Hoca bunu başa baş noktasının yıllara dağıtılmış hali olarak anlattı.
  - Ders sonrası not: Slaytta "Yıllık yararın yatırım miktarına bölünmesi ile geri ödeme süresi bulunur" yazıyor; yıl cinsinden geri ödeme süresi büyük olasılıkla yatırım miktarının yıllık yarara bölünmesiyle bulunur ($\text{süre} = \frac{\text{yatırım}}{\text{yıllık yarar}}$).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
