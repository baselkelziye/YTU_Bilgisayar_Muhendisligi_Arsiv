# Ders 8 Genişletilmiş Notu: Kalite İyileştirme (CMMI, People CMM) ve Genel Tekrar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kalite İyileştirme ve Sertifika Sistemleri
- 2. CMMI: Süreç Odaklı Kalite
- 3. CMMI Yeterlik Düzeyleri
- 4. CMMI Anahtar Süreç Alanları
- 5. Sertifikasyonun Kuruma ve Ekibe Yansıması
- 6. People CMM: Çalışanlar Yetenek Modeli
- 7. Genel Tekrar: Yazılım Mühendisliği ve Kalite
- 8. Genel Tekrar: Doğrulama, Geçerleme ve V Model
- 9. Genel Tekrar: Test Süreci ve Test Tipleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Kalite İyileştirme ve Sertifika Sistemleri

Ders, ara sınavdan önceki son ders olduğu için iki bölümde işlendi: önce haftanın yeni konusu olan **kalite iyileştirme**, ardından o güne kadarki bütün konuların genel tekrarı.

Bölümün slayttaki başlığı "8. Kalite İyileştirme"dir ve hedefleri dört maddedir (ekrandan, 00:10:00):

- Yazılım iyileştirme sürecini anlamak.
- CMMI süreç modeli yeterlik düzeylerini incelemek.
- Yazılım geliştirme süreci ile anahtar süreç alanları ilişkisini özetlemek.
- Çalışanlar yetenek modelini incelemek.

Hoca konuyu önceki haftalarla bağladı. Yazılım kalitesini sağlamak için yapılan aktiviteler konuşulurken standartlar üzerinde durulmuştu; standartlar, yazılımı gerçekleştirirken uyulması gereken kurallardır. Kalite iyileştirmede ise bunlara ek olarak, yazılımı (daha doğrusu yazılım üretim sürecini) iyileştirmek için **yazılım evinin sağlaması gereken koşullar** gündeme gelir. Bu koşulları tanımlayan yapılar **sertifika programlarıdır**. Bir yazılım evi ya da bir kurumun içindeki yazılım geliştirme birimi, sağladığı koşullara göre bir sertifika programına başvurur ve koşulları sağladığını göstererek sertifika alır.

Sertifikanın pratik yararı, bazı ihalelere girişte ön koşul sağlamasıdır. Örneğin bir ihalede "CMMI 3 sahibi olmak" ya da "CMMI 2 sahibi olmak" şartı konabilir; özellikle askerî projelerdeki yazılımlar için CMMI 3 sertifikası zorunlu tutulabilir.

Slaytta "Süreç İyileştirme" başlığı altında yazılım geliştirme ortamı sertifika sistemleri şöyle sıralanır: CMM, CMMI, SPICE, ISO (ekrandan, 00:15:00).

- **CMM ve CMMI:** Yetenek ve Olgunluk Modeli (Capability Maturity Model, CMM) zamanla CMMI'ye dönüştü. "I" harfi entegrasyonu (integration) ifade eder: CMMI hem teknik işleri hem proje yönetimi işlerini bir arada, bütünleşik olarak değerlendiren bir sertifika sistemidir. Çalışma ABD'de Carnegie Mellon Üniversitesi'nde başladı; sertifika veren kurum hâlâ orasıdır (üniversiteye bağlı Software Engineering Institute, SEI). Sertifika almak isteyen firma bu kuruma bir ücret ödeyerek başvurur ve gerekleri yerine getirerek sertifikayı almaya hak kazanır. Birden beşe kadar düzeyler vardır; firma hangi düzeyi sağlıyorsa o düzeyin sertifikasını alır.
- **SPICE:** Avrupa'da kullanılan, CMMI'ye benzeyen bir yetkinlik düzeyi modelidir. Türk Standartları Enstitüsü de SPICE'ı özümseyip model alarak bir iyileştirme sertifika sistemi oluşturmaya çalışmaktadır.

Derste CMMI üzerinden gidildi, çünkü daha yaygındır: daha fazla kurum buradan yetkinlik belgesi alır ve ihalelerde belirtilen koşullar daha çok CMMI düzeyleri üzerinden konur.

> **Ek bilgi (derste anlatılmadı):** SPICE (Software Process Improvement and Capability dEtermination), büyük olasılıkla ISO/IEC 15504 standardı olarak yayımlanan süreç değerlendirme çerçevesidir; bu standart daha sonra ISO/IEC 330xx serisine dönüşmüştür.

## 2. CMMI: Süreç Odaklı Kalite

### 2.1 Temel fikir

"8.1. CMMI" slaytının ilk maddesi şudur: yazılım sektöründe ürünün kalitesini ağırlıkla onu üreten sürecin kalitesi belirler ve süreç odaklı bir kalite yaklaşımı vardır (ekrandan, 00:15:00). Hoca bunu doğrulama ve geçerleme tanımlarıyla ilişkilendirdi: standartların çoğu ürün yönelimli değil süreç yönelimlidir; ürünün kalitesini anlamak için süreç standartlaştırılır. CMMI değerlendirmesinde sorulan sorular da bu türdendir:

- Gereksinim analizi yapılmış mı? Gereksinim belgesi IEEE 830 standardına uygun hazırlanmış mı?
- Tasarım spesifikasyonu gerçekleştirilmiş mi, belgelenmiş mi, nasıl belgelenmiş?
- Konfigürasyon yönetimi yapılmış mı? Risk yönetimi yapılmış mı?

İkinci madde CMMI'nin tanımıdır: CMMI, etkin bir yazılım sürecinin anahtar elemanlarını tanımlayan bir çerçeve model ve yazılım sürecinin olgunluğunu değerlendirmek için bir ölçüm aracıdır. Yukarıdaki sorular, işte bu "anahtar elemanların" örnekleridir.

### 2.2 Süreç iyileştirme döngüsü

Modelin nasıl işletildiği slaytta "Şekil 8.1. Süreç İyileştirme Döngüsü" ile gösterilir (ekrandan, 00:20:00). Döngü üç adımlıdır:

```text
ÖLÇÜM  ->  ANALİZ  ->  DEĞİŞİM  ->  (yeniden) ÖLÇÜM ...
```

Önce kurumda bir ölçüm yapılır. Sonra bu ölçüm analiz edilir: kurum hangi düzeyin koşullarını sağlıyor? Sağlamıyorsa kurum içinde bir değişim gerçekleştirilir ve eksik yetkinlikler sağlanmaya çalışılır; ardından döngü yeniden ölçümle başlar.

## 3. CMMI Yeterlik Düzeyleri

"CMMI Yeterlik Düzeyleri" slaytına göre CMMI modeli süreçler için beş yeterlik düzeyi tanımlar: başlangıç, yönetilebilir, tanımlı, sayısal yönetilebilir ve eniyilenebilir (ekrandan, 00:25:00). Hoca her düzeyde ne yapıldığını tek tek anlattı.

### 3.1 Başlangıç düzeyi (Initial Level)

Bu giriş seviyesidir; yazılım evinde standartlaşmış hiçbir durum yoktur. Slayttaki maddeler (ekrandan, 00:25:00):

- Yazılım süreci gelişigüzel ve kaotiktir; başarı kişisel gayretlere bağlıdır.
- Kriz durumunda var olan planlar terk edilir. (Yazılım geliştirmeye başlamadan önce belki bazı planlar yapılmıştır, ama ilk krizde bırakılır.)
- Yazılım süreç yetenekleri önceden kestirilemez.

Hoca, hiçbir şey yokken neden buna yine de "birinci seviye" dendiğini şöyle açıkladı: kurum bir şeyleri iyileştirmeye niyetlenmiştir ve sertifika için bu niyet çerçevesinde hazırlıklara başlayacaktır.

### 3.2 Yönetilebilir düzey (Managed Level)

İkinci düzeyde proje yönetimi sağlanır. Hoca, CMMI öncesinde projenin evreleri boyunca proje yönetimi açısından yapılanlara, teknik olarak yapılanlara (kullanılan süreç modeli, teknoloji, CASE araçları) ve ürüne ayrı ayrı bakıldığını, CMMI'de ise hepsine birden bakıldığını hatırlattı. Slayttaki maddeler (ekrandan, 00:25:00):

- Proje yönetimi kontrolleri kurulmuştur; projeler belgelenen planlara uygun şekilde gerçekleştirilir ve yönetilir.
- Yazılım gereksinimleri yönetilir; gereksinimlerle ilişkili ürünler oluşturulur ve denetlenir.
- Proje yönetim sistemi proje sürecini etkin biçimde kontrol eder; projeler planlı, başarımı ölçülmüş ve kontrol edilmiştir.
- Ürün ve hizmetler, onlara özel gereksinim, standart ve hedefleri sağlar.

Yani bu kurumda yürütülen bütün projelerde bir proje yönetimi fikri vardır: projeler belgelenir, planlar oluşturulur ve projeler bu planlara göre yönetilir. Süreçte ölçümler yapılmaya da çalışılır.

### 3.3 Tanımlı düzey (Defined Level)

Slayttaki maddeler (ekrandan, 00:25:00):

- Süreçler iyi tanımlanmış ve iyi anlaşılmıştır; standartlar, prosedürler, araçlar ve metotlarla anlatılmıştır.
- Standart süreç tanımları ile organizasyonel boyutta tutarlılık sağlanır.
- Tüm projelerde standart yazılım geliştirme sürecinin uyarlanmış hali kullanılır.

Hoca son maddeyi şöyle açtı: projeler için hangi yazılım geliştirme süreç modeli seçilmişse o uygulanır. Kurumun standartları, prosedürleri, araçları ve metotları vardır ve bunlar her projede uygulanır.

### 3.4 Niceliksel yönetilen düzey (Quantitatively Managed Level)

Slayttaki maddeler (ekrandan, 00:30:00):

- Sürecin başarımı için önemli alt süreçler seçilir ve bu alt süreçler istatistiksel ve diğer nicel ölçüm teknikleri kullanılarak kontrol edilir.
- Kalite ve süreç performansının nicel hedefleri tesis edilir ve süreçlerin yönetiminde bir kriter olarak kullanılır.
- Süreçler ölçülür ve ölçülebilen sınırlar içinde işler gerçek veriler baz alınarak tahmin edilebilir.

Hoca burada bir soruyu öne çıkardı: ikinci düzeyde de süreçte ölçümler yapılabildiğini söylemiştik; o halde dördüncü düzeyin farkı nedir? Cevap: dördüncü düzeyde **proje yönetimi ölçümlere göre yapılır**. Bitmiş projelerden bir ölçüm arşivi varsa ve yeni başlayan projelerde maliyet tahmini, iş gücü planlaması ve süre planlaması bu arşivdeki ölçüm verisine dayanılarak yapılıyor ve bu kanıtlanabiliyorsa kurum dördüncü düzeydedir.

Arşivde neler olabilir? Önceki haftalarda tekrar edilen ölçüm sistemleri: function point ya da satır sayısı gibi büyüklük ölçümleri, karmaşıklık ölçümleri; ayrıca projede kaç kişinin, hangi türde kaç kişinin çalıştığı, hangi geliştirme aşamasında ne kadar iş gücü harcandığı ve riskle ilişkili bilgiler. Böyle bir arşivden yararlanılarak yeni proje için tahminler yürütülebilir.

Bundan çıkan önemli sonuç şudur: yeni başlayan bir firma hemen dördüncü düzeyde olamaz, çünkü önce ölçümler yapılarak tamamlanmış projelerinin olması gerekir. Hoca bunu modelin adıyla bağladı: Capability Maturity Model, hem yeteneğin (çalışan portföyü ve bitmiş projelerin yetenekleri) hem de belirli bir olgunluk seviyesinin bulunmasını gerektirir.

### 3.5 En iyileştirilmiş düzey (Optimizing Level)

Slayttaki maddeler (ekrandan, 00:30:00):

- Süreçten gelen sayısal geri beslemeler ve teknolojilerden yararlanılarak sürekli süreç iyileştirmesi yapılır. Yazılım süreç yeteneği sürekli iyileşen olarak tanımlanabilir.
- 5. ve 4. düzey arasındaki önemli bir ayrım, adreslenen süreçlerin değişme derecesidir.

Beşinci düzeyde hep önceki çalışmalardan geri besleme alınarak süreç yeteneği geliştirilir. Hocaya göre dördüncü ile beşinci düzeyi ayıran soru şudur: kurumda bir yenilikçilik ve yaratıcılık planlaması var mı?

> **Hocanın vurgusu:** Dördüncü düzeyi ikinciden ayıran, ölçümlerin proje yönetiminde ve yeni projelerin tahmininde kullanılmasıdır; beşinciyi dördüncüden ayıran ise süreçlerin değişme derecesi, yani planlı yenilikçiliktir.

## 4. CMMI Anahtar Süreç Alanları

### 4.1 Kavram

Anahtar süreç alanı (key process area), yazılım geliştirme sürecindeki hangi aşamada hangi kurallara ve standartlara uyulmasının kurumu CMMI'de hangi düzeye taşıyacağını gösteren eşleştirmedir. Gereksinim yönetimi, proje planlama, proje izleme, konfigürasyon yönetimi gibi temel aktivitelerin ve destek aktivitelerinin (umbrella activities) hangi düzeyde gerçekleştirildiği anahtar süreç alanlarıyla açıklanır.

Slayta göre: etkin bir yazılım süreci geliştirmek için tanımlanan anahtar süreç alanlarının düzeylere göre dağılımı belirtilir; **birinci düzeyde anahtar süreç alanı yoktur** (ekrandan, 00:45:00).

### 4.2 II. düzey (Yönetilen)

Slayttaki liste (ekrandan, 00:45:00):

- Gereksinimlerin yönetimi
- Proje planlama
- Proje izleme ve kontrol
- Tedarikçi sözleşme yönetimi
- Ölçümleme ve analiz
- Süreç ve ürün kalite güvence
- Konfigürasyon yönetimi

Hocanın açıklamasıyla ikinci düzeydeki bir firmada bütün projelerde gereksinim analizi yapılır, proje planı oluşturulur, projeler izlenir ve kontrol edilir, ürün alınan ya da iş yaptırılan tedarikçilerle sözleşme yönetimi yürütülür, ölçümler yapılır, süreç için kalite tanımı yapılır ve konfigürasyon yönetimi uygulanır. Ancak projeden projeye farklılıklar olabilir; bazı projelerde bazı süreçlerde eksiklikler bulunabilir. Hangi alt uygulamanın hangi seviyede yapıldığı gibi ayrıntılar CMMI kitaplarında bulunabilir.

### 4.3 III. düzey (Tanımlı)

Slayttaki liste yalnız küçük önizlemede okunabildi; anlatımla birlikte şu maddelerden oluşur (ekrandan, 00:50:00):

- Gereksinimlerin geliştirilmesi
- Teknik çözüm
- Ürün entegrasyonu
- Doğrulama (verifikasyon)
- Kurumsal süreç tanımlama ve odaklanma
- Kurumsal eğitim
- Bütünleşik ürün ve süreç geliştirme için bütünleşik proje yönetimi
- Risk yönetimi
- Entegrasyon için kurumsal altyapı

<!-- BELİRSİZ: III. düzey slaytının tam yazımı (özellikle 4.-5. maddeler ve bütünleşik proje yönetimi maddesi) küçük önizlemeden kesin okunamadı -->

Hoca üçüncü düzeyi şöyle anlattı: gereksinimlerin belirlenmesi ve tanımlanması daha gelişmiştir; süreçte teknik çözümler vardır; ürün bütünleştirme aşama aşama yapılır; verifikasyon, yani test aşaması oluşturulmuştur. Her adımda kurumsal süreçler tanımlıdır: kurumun hangi tür projede hangi tür süreci kullanacağı belirlenmiştir. Kurumsal eğitim, bütünleşik ürün ve süreç geliştirme, tümleşik proje yönetimi ve kurumsal bir altyapı (bütün uygulamaların veri tabanı yapısı dahil) vardır. Kısacası ikinci düzeyde bahsedilen her şeyin bütün projelerde, kurumsal bir yapı içinde gerçekleştirilmesi tanımlı düzeyin en önemli belirtisidir.

İkinci düzeyde görülmeyen bir ekleme de **risk yönetimidir**: üçüncü düzeyde bütün projeler için proje yönetimi çerçevesinde risk yönetimi yapılır.

### 4.4 IV. ve V. düzey

Slayttaki liste (ekrandan, 00:50:00):

- IV. Düzey (Niceliksel Yönetilen): organizasyonel süreç başarımı; niceliksel proje yönetimi.
- V. Düzey (En iyileştirilmiş): organizasyonel yenilenme ve yaygınlaştırma; nedensel analizler ve çözümleme.

Dördüncü düzeyde, üçüncü düzeyi izleyecek şekilde kurumsal süreç tanımı bütün projelere yansıtılmış ve bu projelerden bir başarım arşivi oluşturulmuştur. Hem yönetim hem teknik kişiler açısından bitmiş projelerde yapılan işler ölçülüp bir ölçüm arşivine dönüştürülmüştür; yeni projelerde bu arşiv kullanılarak sayısal tahminler yapılır. Ayrıca eski projelerde üretilen yazılımların teknik tasarım ölçütleri, yeni projelerdeki tasarım kararlarının daha gerçekçi yapılmasını sağlar.

En iyileştirilmiş düzeyde ise kurumsal boyutta yeni fikir oluşturma, bu fikirlerin uygulanıp bütün kuruma yayılması ve önceki proje sonuçlarının nedenlerinin daha iyi analiz edilmesi vardır; özellikle proje çözümlerinde yenilikçi yaklaşımlar bütün kuruma yayılır.

### 4.5 CMMI'de süreç alanı grupları

"CMMI'da Süreç Alanları" slaytına göre süreç alanları dört grupta toplanır ve gruplar arasında etkileşim vardır (ekrandan, 00:55:00):

- Süreç yönetimi
- Proje yönetimi
- Mühendislik
- Destek

Destek süreç alanları iki grupta adreslenir:

- Temel destek süreç alanları: ölçümleme ve analiz, kalite sağlama, konfigürasyon yönetimi.
- İleri destek süreç alanları: organizasyonel entegrasyon altyapısı, nedensel analiz ve çözümleme, karar analizi ve çözümleme.

Hoca, CMMI'deki "bütünleşik" kavramını bu gruplarla açıkladı: CMM döneminde süreç yönetimi, proje yönetimi, mühendislik ve destek alanları için ayrı ayrı düzey çalışmaları yürütülüyordu. CMMI bunları birleştirir; kurum bir bütün olarak görülür ve bütün bu açılardan bakıldığında kurumun kaçıncı düzeyde olduğu belirlenir.

## 5. Sertifikasyonun Kuruma ve Ekibe Yansıması

Hoca, iş hayatında olan öğrencilere çalıştıkları kurumlarda CMMI ya da başka bir sertifikasyon çalışmasını izleyip izleyemediklerini sordu. Bir öğrencinin aktardığı deneyim ve hocanın yorumundan şu akademik noktalar çıktı:

- CMMI sertifikalı bir yapıda, test ekibinden ayrı bir **kalite birimi** bu işleri yürütür. Kalite birimi bütün ekiplerden sertifikanın koşullarını sağlayacak belgeleri ister.
- Örneğin test tasarım dokümanları yazılırken risk analizi ve kaçabilecek hata sayısı gibi konularda metrikler ve standartlar belirlenir; ekipler bu metriklere uymaya çalışır, kalite birimi de sürekli metrik toplar ve raporlar. Düzeyin korunması için süreçler sürekli yenilenir ve raporlanır.
- Hocanın yorumuyla sertifikasyonun yazılım ekibine yansıması tam olarak budur: geliştirme grubu "ben böyle tasarladım, böyle yapıyorum" deyip geçemez, belli bir standarda göre çalışmak zorundadır; test ekibi için de aynısı geçerlidir.

Hoca ayrıca, kendi verdiği bilgiye göre, yurt içinde savunma alanında yıllardır beşinci düzeyde kalan ve dördüncü düzeyde olan firmalar bulunduğunu, bankacılık yazılımlarında da dördüncü düzeyde olanlar olduğunu söyledi; bu bilgilerin zamanla değişebileceğini ve güncellenmesi gerektiğini de ekledi. Uluslararası projelerde çalışmak, belirli ihaleleri almak isteyen ya da askerî yazılım geliştiren firmalarda bu sertifikasyon hedefi bulunur.

Hoca sertifikasyonu üniversitelerin akreditasyonuna benzetti. Bölümler sayfalarında MÜDEK ya da ABET sertifikası olduğunu belirtir. Bunun için de kuruma bir ücret yatırılır ve "biz iyi bir üniversiteyiz, öğrencilerimiz iyi yerlerde çalışıyor" demek yetmez: yapılan çalışmaları, sınavları, disiplinlerarası çalışmaları belgelemek gerekir. Yazılım firmalarındaki sertifikasyon da aynı mantıkla, iddiayı belgelerle kanıtlamaya dayanır.

## 6. People CMM: Çalışanlar Yetenek Modeli

### 6.1 SEI ve güncel kaynaklar

CMMI kavramları Carnegie Mellon Üniversitesi'ne bağlı Software Engineering Institute'te geliştirildi ve hâlâ bu enstitü tarafından düzenlenir; sertifikasyon başvuruları ve ücretlendirme de burada yapılır. Hoca, yazılım mühendisliği alanındaki yeni düzenlemelerin en güncel halinin bu kurumun sitesinde bulunabileceğini söyledi: temel bilgiler kitaplardan alınır, ama kendimizi yazılım mühendisliği açısından güncellemek için bu siteye bakmak iyi olur. Proje yönetimiyle ilgili güncel bilgi için de Project Management Body of Knowledge (PMBOK) önerildi.

### 6.2 P-CMM'in tanımı

"8.1.4. People CMM" slaytındaki maddeler (ekrandan, 01:05:00):

- P-CMM kavramları 1992 yılında SEI tarafından projelendirildi. Organizasyonlar performanslarını artırmak için birbiriyle ilişkili insan, süreç ve teknoloji kavramları üzerinde odaklanmalıdır.
- İnsanlarla ilişkili konuları tanımlayıp iyileştirmek isteyen organizasyonlar için geliştirilen P-CMM, CMM'in genel yapısına benzeyen bir olgunluk çerçevesidir.
- Bir yazılım ve bilgi sistemleri organizasyonunun insan değerlerinin yönetimini ve geliştirilmesini yönlendirir.

Yazılım geliştiren kurumlarda People CMM sertifikası eskiden ayrıca alınıyordu. Hocaya göre artık ayrıca incelenmesi gerekmiyor, çünkü People CMM bütünleşik CMM'in (CMMI) içine katıldı ve onun gereklerinden biri oldu.

### 6.3 Temel hedefler

"P-CMM" slaytında temel hedefler şöyle sıralanır (ekrandan, 01:05:00):

- Yazılım geliştirme yeteneğini tanımlamak ve sağlamak.
- İş gücünün yeteneklerini artırarak organizasyonun yeteneklerini artırmak ve iyileştirmek.
- Her bir çalışanın ve organizasyonun hedeflerini birlikte tutmak.
- İnsan değerlerini elinde tutmak.

### 6.4 P-CMM düzeyleri

Düzey adları eski CMM düzeyleridir: başlangıç, tekrarlanabilir, tanımlı, yönetilen ve en iyileşen. Slaytlardaki içerik (ekrandan, 01:10:00 ve 01:15:00):

| Düzey | Süreç alanları |
|---|---|
| 1. Başlangıç | (yok) |
| 2. Tekrarlanabilir | Tazminat, eğitim, performans yönetimi, personel sağlama, iletişim, çalışma ortamı |
| 3. Tanımlı | Katılımcı kültür, yeteneğe dayalı pratikler, kariyer geliştirme, yetenek geliştirme, iş gücü planlama, bilgi ve becerilerin analizi |
| 4. Yönetilen | Organizasyonel performans ayarlama, organizasyonel yetenek yönetimi, takım temelli pratikler, takım kurma, danışmanlık |
| 5. En iyileşen | Sürekli iş gücü inovasyonu, koçluk, kişisel yetenek geliştirme |

Hocanın açıklamaları:

- **Başlangıç düzeyi:** Daha yeni bir karar verilmiştir; çalışanların hakları ve yetkinliklerinin nasıl geliştirildiğiyle ilgili durumlar gözlenir ve düzeltilmeye çalışılır.
- **Tekrarlanabilir düzey:** Çalışanların tazminat ve eğitim bilgileri tutulur, eğitimlerin sürekliliği sağlanır, performansları yönetilir (bunun için performans ölçümü de gerekir). Farklı kademeler arasında iletişim sağlanır, çalışma ortamları düzenlenir. İşe alım (personel sağlama) ve ekip kurma tekrarlanabilir kurallara bağlanır: her personel alımında yeni kural eklemek yerine belirli bir kural çerçevesinde işe alım yapılır.
- **Tanımlı düzey:** İkinci düzeydeki her şeye ek olarak katılımcı bir kültür vardır; çalışanlar proje önerisi verebilir. Çalışanların kariyerleri kurumun ihtiyaçlarıyla paralel biçimde geliştirilir. Tekrarlanabilir düzeyde yalnız eğitimlerin açılması yeterliyken, üçüncü düzeydeki firmanın yetenek geliştirme planları ve buna bağlı eğitim planları olmalıdır. Yalnız alım sisteminde süreklilik değil, iş gücü planlaması da yapılmalıdır.
- **Yönetilen düzey:** Kurumsal performans düzeyleri belirlenir, kurumsal yetenek yönetimi oluşturulur, ekip temelli pratikler kurulur; proje ekipleri yeteneğe dayalı ve daha iyi çalıştırılabilir hale gelir. Takım kurma ve danışmanlık hizmetleri bu düzeyde yer alır.
- **En iyileşen düzey:** CMMI'nin beşinci düzeyinde olduğu gibi burada da inovasyon ve yaratıcılık gerekir. Koçluk ve kişisel yetenek geliştirme ile, kurumsal bir hedef olmakla birlikte kişilere tek tek bakılarak yetenek geliştirme yoluna gidilir.

Böylece haftanın konusu olarak sertifikasyon programları, en yaygın örnek olan CMMI ve ekipte çalışanların durumuna göre yapılan sertifikasyon olarak People CMM tamamlandı.

## 7. Genel Tekrar: Yazılım Mühendisliği ve Kalite

Dersin ikinci bölümü, bir sonraki hafta yapılacak klasik sınava hazırlık için o güne kadarki konuların tekrarıdır. Hoca tekrarı kendi slaytlarının özetinden yaptı ve derslerin dinlenerek bu özete ayrıntı eklenebileceğini söyledi.

### 7.1 Yazılım mühendisliğinin katmanlı yapısı

"Şekil 1.1. Yazılım Mühendisliği Katmanlı Yapısı" alttan üste şu katmanlardan oluşur (ekrandan, 01:20:00):

```text
YAZILIM ARAÇLARI
YÖNTEMLER
SÜREÇLER
KALİTE BAKIŞ AÇISI   (temel)
```

Yazılım mühendisliğinde her şey kalite bakış açısına dayanır. Yazılım mühendisliği, mühendislik yaklaşımını yazılım geliştirme süreçlerinde kullanarak mühendislik yöntemleriyle yeni yazılımlar geliştirme amacıyla yapılan çalışmalardır. Hoca katmanların ilişkisini şöyle ekledi: bir yazılım aracı seçerken ona uygun yöntem ve süreçleri kullanırız; ancak araç bunlarla uyumlu olursa başarılı oluruz.

### 7.2 Kalite faktörleri ve McCall modeli

Kaliteli yazılım üretmeye çalışıldığı için önce kaliteli yazılımın tanımı yapılmıştı. McCall'un kalite üçgeni kalite faktörlerini üç bakış açısıyla sınıflar:

- **Ürün kullanımı (kullanıcılar açısından):** doğruluk, güvenirlik, kullanışlılık, bütünlük.
- **Ürün değişikliği (bakım ve değişiklik yapanlar açısından):** bakım yapılabilirlik, esneklik, test edilebilirlik.
- **Ürün geçişi (ürünü başka ortama taşıyanlar açısından):** taşınabilirlik, yeniden kullanılabilirlik, birlikte çalışabilirlik.

McCall yazılım kalite modelinde sol tarafta kalite faktörleri, sağ tarafta kalite metrikleri vardır. Her kalite faktörü, daha kolay ölçülebilen metriklerin ağırlıklı toplamıyla hesaplanabilir. Modelin hedefi budur: kalite faktörleri tanımsaldır; metriklerle ifade edilerek sayısal hale getirilirler.

> **Ek bilgi (derste anlatılmadı):** McCall modelinde bu ilişki genellikle $F_q = c_1 m_1 + c_2 m_2 + \dots + c_n m_n$ biçiminde yazılır; burada $F_q$ kalite faktörü, $m_i$ o faktörü etkileyen metrikler, $c_i$ ise ağırlık katsayılarıdır.

### 7.3 Kaliteyi sağlama aktiviteleri ve hatanın maliyeti

Kaliteli yazılımı sağlamak için yapılan aktiviteler: standartları kullanmak, doğrulama ve geçerleme (verification and validation), gözden geçirme ve denetim, test, hata ve kusur analizi, değişim yönetimi, konfigürasyon yönetimi, eğitim ve risk yönetimi. Bunların bazıları yazılım geliştirmeye başlamadan konan kurallardır, bazıları geliştirme sırasında, bazıları da geliştirdikten sonra yapılır.

Bu aktivitelerin bir maliyeti vardır, ama hata ne kadar erken bulunup düzeltilirse o kadar faydalıdır. "Şekil 2.3. Yazılım geliştirme süreci ile hata bulma gideri ve hata bulma olasılığı ilişkisi" iki eğri gösterir (ekrandan, 01:25:00):

- (a) Hata bulma gideri (TL), süreç ilerledikçe giderek ve hızlanarak artar.
- (b) Hata bulma olasılığı (P), süreç ilerledikçe düşer.

Hatayı önleme maliyeti olarak kalite planlanır, formal teknik gözden geçirme yapılır, testler oluşturulur, eğitim verilir. Bunların hepsi maliyettir, ama yazılımı hatayla teslim etmek daha maliyetlidir.

### 7.4 Standartlar

Yazılım mühendisliğinde kaliteyi sağlamak için standartlar kullanılır. Standartlar iki açıdan sınıflanabilir:

- **Yazılım geliştirme aşamasına göre:** proje yönetiminde geçerli standartlar, gereksinim spesifikasyonu standartları, tasarım standartları gibi.
- **Kaynağına göre:** ISO tarafından mı, IEEE tarafından mı geliştirildiği.

Bazen bir standart hem kaynağı hem aşamasıyla ifade edilir. Örneğin IEEE 830, IEEE'nin belirlediği gereksinim spesifikasyonu standardıdır; gereksinim spesifikasyonunun nasıl yapılacağını anlatır. Kalite yönetim sistemi açısından da bir kurumun standardı ve projelerin standardı ayrı ayrı olur.

## 8. Genel Tekrar: Doğrulama, Geçerleme ve V Model

### 8.1 Doğrulama ve geçerleme

Hoca tekrar sırasında slayttaki Türkçe karşılıkları düzeltti: **doğrulama** verification'a, **geçerleme** validation'a verilen Türkçe isimdir.

- **Geçerleme (validation):** Doğru yazılım üretildi mi?
- **Doğrulama (verification):** Yazılım doğru yolla üretildi mi?

> **Hocanın vurgusu:** Geçerleme ile "doğru yazılım üretildi mi?", doğrulama ile "yazılım doğru yolla üretildi mi?" sorusuna cevap aranır.

### 8.2 V model

V model, yazılım geliştirme süreciyle karşılıklı ilişkisi olan yazılım test sürecini gösterir. Test süreci şu adımlara ayrılır: birim testi, bileşen testi, bütünlük testi, sistem testi ve işlemsel kullanım (onaylama testi). Doğrulama ve geçerleme açısından:

| Test adımı | Yapılan |
|---|---|
| Birim testi | Doğrulama |
| Bütünlük testi | Doğrulama |
| Sistem testi | Doğrulama ve geçerleme |
| İşlemsel kullanım | Geçerleme |

### 8.3 Gözden geçirme ve onaylama

"3.3. Gözden Geçirme ve Onaylama" slaytına göre yazılım geliştirme sürecini oluşturan her basamak tamamlanınca durak noktalarında yapılan işler gözden geçirilir ve gerekli düzeltmeler yapılır (ekrandan, 01:30:00). Amaç, geliştirme sürecindeki hataları zamanında düzeltmektir.

İnceleme (inspection) ile test arasındaki fark da hatırlatıldı: inceleme gereksinim spesifikasyonu, tasarım, ayrıntılı tasarım ve program gibi bütün ara ürünlere uygulanabilir. Test ise çalıştırılarak yapıldığı için yalnız prototip ya da program üzerinde yapılabilir. Test aşamasında fonksiyonel test, performans testi, dayanıklılık testi ve yapısal test gibi testlerle hatalar bulunmaya çalışılır.

## 9. Genel Tekrar: Test Süreci ve Test Tipleri

### 9.1 Kabul, alfa, beta ve regresyon testleri

Kabul testi, alfa testi ve beta testi farklı test tipleridir. Alfa testi kullanıcı testinin gerçekleştirilmesidir, beta testi ise bu testin potansiyel kullanıcılara yaptırılmasıdır. Bütünlük testinden sonra alttaki elemanlarda değişiklik olduğunda regresyon testi uygulanır. <!-- BELİRSİZ: 01:31:56 civarında alfa testinin tanımı altyazıda kesik başlıyor; alfa testinin nerede ve kimle yapıldığı bu kayıttan okunamadı -->

### 9.2 Birim testi, test case, sürücü ve koçan

Birim testi, yazılım tasarımının en küçük modülü üzerinde yapılan testtir ve genellikle saydam kutu testi olarak gerçekleştirilir; her algoritma yolu üzerinden gidilerek bulunan sonucun doğru olup olmadığı denenir.

**Test case** (test senaryosu), belirli bir program yolunu işletmek ya da özel bir gereksinimi test etmek için düzenlenen veri ve bununla ilişkili işlemlerdir.

Modül bağımsız değilse, yani bir yerden çağrılıyor ve başka bir modülü çağırıyorsa, **test sürücü (test driver)** ve **test koçanı (test stub)** gerekir. Sürücü, test edilen modülü çağıran ara programdır; koçan ise test edilen modülün çağırdığı alt programı temsil eden kukla (dummy) alt programdır.

### 9.3 Bütünleme testi

Bütünleme testi yukarıdan aşağı (top-down) ve aşağıdan yukarı (bottom-up) olarak yapılır; ikisinin birlikte kullanılmasına sandviç test (sandwich testing) denir. Hoca, uygulamada aşağıdan yukarı bütünlemenin daha çok yapıldığını söyledi. <!-- BELİRSİZ: 01:34:43'te hangi yaklaşımın "daha sağlıklı" bulunduğu altyazıdan net çıkmıyor -->

"Şekil 5.5. Aşağıdan Yukarı Bütünleme Testi" şu yapıyı gösterir (ekrandan, 01:35:00):

```text
                     Module 10            (BU4)
          /              |               \
     Module 7        Module 8          Module 9
       |   (BU1)    /    |    \ (BU2)   /    \ (BU3)
   Module 1   Module 2 Module 3 Module 4  Module 5 Module 6
```

- BU1: Module 1 → Module 7
- BU2: Module 2, 3, 4 → Module 8
- BU3: Module 5, 6 → Module 9
- BU4: Module 7, 8, 9 → Module 10

Aşağıdan yukarı bütünlemede en alttaki modüllerin önceden test edilmiş olması gerekir; bunlar yukarıya doğru birleştirilir ve her birleştirilen yapı, istenen işi yapıp yapmadığı açısından yeniden test edilir.

### 9.4 Regresyon, sistem ve kabul testi

Regresyon testi, test edilmiş bir programda değişiklik yapıldığında uygulanır. Sistem testi kapsamında güvenlik testi, dayanıklılık testi, yetenek testi ve performans testi yapılabilir.

Bütünleme sonunda yazılım hazırlanmış olur ve sıra kullanıcının onaylamasına, yani müşterinin kabul testine gelir. Burada şu sorular sorulur: Yazılım tam mı, bütün yazılım elemanları hazırlanmış mı? Konfigürasyon yönetimi yapılmış mı, teslim alınabilir mi? Kullanıcı belgeleri ve programın çalışır haldeki kopyası istenenleri yerine getiriyor mu? Kabul testi bu nedenle konfigürasyon testi (incelemesi) ve kabul muayenesi (onaylama testi) olarak iki parçadan oluşur.

### 9.5 Saydam kutu ve kara kutu testi

Test sürecinin adımlarının (test stratejisi) yanında, bu adımlarda hangi testlerin yapıldığını gösteren test tipleri vardır.

**Saydam kutu testi (white box testing)** iç yapının kontrol edilmesidir; temel yol testi bunun başlıca yöntemidir ve temel yol sayısını bulmak için McCabe ölçüsü kullanılır. Tekrar slaytları arasında, önceki derslerde McCabe karmaşıklığının ortalama alma yöntemiyle anlatıldığı akış grafı da (Şekil 6.1) kısaca geçildi (ekrandan, 02:05:00); bu örnek derste yeniden çözülmedi.

**Kara kutu testi** slaytta şöyle tanımlanır (ekrandan, 01:45:00): kara kutu testi, yazılımın bütünlenmesi sırasında uygulanan ve yazılım arabirimi üzerinde yapılan bir sınamadır. Bu sınama ile yazılım işlevlerinin yerine getirildiği, girdilerin kabul edildiği, çıktıların doğru olarak bütünlüğün sağlandığı gösterilir. Kara kutu testinde yazılımın mantıksal iç yapısından çok temel sistem modeli denenmiş olur. Bu nedenle kara ve saydam kutu testleri birlikte uygulanarak yazılım arabiriminin geçerliği onaylanır ve yazılımın iç işlerliğinin doğruluğu kısmen güvence altına alınır.

Hocanın vurguladığı noktalar: kara kutu testi bütünleme ve sistem testi sırasında uygulanır, kullanıcı testinde de kara kutu testi yapılır. Girdiler yalnız dışarıdan, iç yapı bilinmeden verilir ve istenen çıktıların alınıp alınmadığına bakılır. Ayrıca anormal veri girişi yapılarak yazılımın anormal davranışa yol açıp açmadığı da görülmek istenir. İki test tipi birbirinin alternatifi değildir, birlikte uygulanır.

**Keşif testi (smoke test):** ürün spesifikasyonu ya da gereksinim belgesi olmadan, ürünün kendisi çalıştırılarak yapılan genel bir sınamadır.

Kara kutu test tipleri olarak iki yöntem hatırlatıldı:

- **Eşdeğer bölümleme (equivalence partitioning):** kara kutu teste gönderilecek veri uzayı sınıflara ayrılır ve test aşamasında her sınıfın nasıl denenebileceği belirlenir.
- **Sınır değer analizi (boundary value analysis):** hataların daha çok sınırlarda çıktığı düşüncesiyle sınırların kontrol edilmesidir.

<!-- BELİRSİZ: 01:45:20 civarında gereksinim hatalarının azaldığına dair cümle bağlamsız kaldı; ardından bağlantı koptuğu için 01:45-02:00 arası anlatım kayıtta yok -->

### 9.6 Tekrar slaytlarının kapsamı

Bağlantı yeniden kurulduktan sonra hoca tekrar slaytlarını hızlıca geçti ve kapsamı şöyle özetledi: güvenirlik modelleri, yazılım ölçümü ve büyüklük ölçümü (function point, KLOC; bunlar sözlü anlatılmış, slaytta yer almıyor), test planlama ve yönetimi (test senaryoları, test çalışma ekibi), yazılım bakımı, konfigürasyon yönetiminin özeti (ayrıntısı daha sonra ele alınacak), risk yönetimi ve bu derste anlatılan kalite iyileştirme konuları.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:25:19): CMMI'nin ikinci düzeyinde de süreçte ölçümler yapıldığı söylenir. O halde dördüncü düzeyi (niceliksel yönetilen düzey) ikinci düzeyden ayıran nedir? Yeni kurulmuş bir firma doğrudan dördüncü düzeyde olabilir mi?

> **Çözüm (derste verilen):** Dördüncü düzeyde ölçümler proje yönetiminde kullanılır. Bitmiş projelerden oluşturulmuş bir ölçüm arşivi (function point, satır sayısı, iş gücü, süre, risk bilgileri) vardır ve yeni projelerin maliyet, iş gücü ve süre tahminleri bu arşive dayanılarak yapılıp kanıtlanabilir. Bu yüzden yeni kurulmuş bir firma hemen dördüncü düzeyde olamaz; önce ölçümlerle tamamlanmış projeleri olmalıdır.

**Soru 2** (derste sözlü, 00:53:09): Yeni CMMI'nin bünyesine katılan People CMM ile ayrıca ne hedeflenir?

> **Çözüm (derste verilen):** İnsan, süreç ve teknoloji kavramlarına birlikte odaklanarak yazılım geliştirme yeteneğini tanımlamak ve sağlamak; iş gücünün yeteneklerini artırarak kurumun yeteneklerini artırmak; çalışanın ve kurumun hedeflerini birlikte tutmak; insan değerlerini kurumda tutmak.

## Dersin Toparlaması

Dersin ilk bölümünde kalite iyileştirme ele alındı. Standartlar yazılımı geliştirirken uyulacak kuralları verirken, CMMI ve People CMM gibi sertifika sistemleri yazılım evinin süreç olgunluğunu ölçüp belgeleyen çerçevelerdir. CMMI ürün kalitesini süreç kalitesine bağlar, ölçüm, analiz ve değişimden oluşan bir iyileştirme döngüsüyle işler ve başlangıç, yönetilebilir, tanımlı, niceliksel yönetilen ve en iyileştirilmiş olmak üzere beş düzey tanımlar. Her düzeyin anahtar süreç alanları, kurumun hangi aktiviteleri hangi olgunlukta yürüttüğünü gösterir: ikinci düzeyde proje yönetimi, üçüncüde kurumsal süreç tanımı ve risk yönetimi, dördüncüde ölçüm arşivine dayalı niceliksel yönetim, beşincide kurumsal yenilikçilik ve nedensel analiz. People CMM aynı olgunluk mantığını insan kaynağına uygular ve bugün CMMI'nin içinde yer alır.

İkinci bölümde ara sınav öncesi bütün dönem tekrar edildi: yazılım mühendisliğinin katmanlı yapısı, McCall kalite modeli, kaliteyi sağlama aktiviteleri ve hatanın erken bulunmasının önemi, standartlar ve IEEE 830, doğrulama ile geçerlemenin farkı, V model, gözden geçirme ve inceleme, birim ve bütünleme testleri, sürücü ve koçan, regresyon, sistem ve kabul testleri ile saydam kutu ve kara kutu test teknikleri. Konfigürasyon yönetiminin daha ayrıntılı ele alınacağı belirtildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
