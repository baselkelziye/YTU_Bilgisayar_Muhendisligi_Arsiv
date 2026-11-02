# Ders 4 Çalışma Özeti

## Genel Konular

- Önceki derslerin özeti: yazılım proje yönetiminin bileşenleri, 3P, proje planının içeriği.
- Sorunun tanımlanmasında koşullar, kısıtlar ve varsayımlar (örneklerle).
- Kabul kriterleri ve çözüm yolunun kararlaştırılması (tekrar).
- Analiz aşamasının alt adımları ve WBS'nin süreç modeline göre oluşturulması.
- Yazılım risk yönetimi: risk kategorileri ayrıntılı (ürün büyüklüğü, işletmecilik, müşteri, süreç, teknik, personel).
- Risk tablosu: olasılık, etki ve risk derecesi. Tablonun sadeleştirilmesi.
- Gantt diyagramı: örnek bir kitap satış web sitesi projesi, WBS düzeyleri, kilometre taşları.
- Faaliyetler arası ilişkiler: finish-start, start-start, finish-finish, start-finish. Kritik yol.
- Proje planlama araçları: MS Project ve alternatifler.
- Makale önerileri hakkında duyurular.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kabul kriterleri ayrıntılı anlatılmalı ve kayda geçirilmelidir. Yoksa taraflardan biri memnun kalmaz ve iş bilirkişiye kadar gidebilir.
- Seçilen çözüm yolunun neden seçildiği, diğerlerinin neden reddedildiği hem bu proje hem de sonraki projelerin bilgi arşivi için yazılmalıdır.
- Risklerin tamamı her projede çıkmaz. Önce her riskin olasılığı ve etkisi belirlenmelidir.
- Büyük risk tablosu her gözden geçirmede izlenemez. Olasılığı ve etkisi büyük olanlar öne alınır ve her kilometre taşında denetlenir.
- WBS seçilen süreç modeline uygun olmalıdır.
- Gantt şemasında bir işin başlangıç tarihi çoğu zaman doğrudan verilmez. Öncelik-sonralık ilişkisiyle tanımlanır.
- MS Project bir CASE aracı veya yazılım geliştirme aracı değildir. Her türlü proje (inşaat, mimari, kimya) için kullanılan bir proje yönetimi aracıdır.
- Çok büyük olmayan projelerde WBS çok alt düzeylere indirilirse planın kullanımı zorlaşır.
- Makale önerilerinde Scrum ve çevik projelerle ilgili çok fazla benzer konu var. Konular birbirine benzememeli.

## Kısa Tekrar Notları

- Kısıt örneği: "Projede fazla mesai yapılmayacak." "Network uzmanı yalnızca şu tarihlerde ve saatlerde destek verecek."
- Varsayım örneği: "Proje süresince kimsenin rapor almayacağı varsayılmıştır. Bir problem olursa plana eklenecektir."
- Kabul kriteri: Müşterinin teslim alırken kontrol edeceği yazılım özellikleri.
- Analiz aşamasının genel alt adımları: bilgi toplama, modelleme, modellerin yorumlanması.
- Risk özellikleri: belirsizlik ve kayıp. Risk kaynakları: gelecek, değişim, seçim.
- Risk derecesi = olasılık × etki. Olasılık ve etki yüksek, orta, düşük olarak veya sayısal aralıklarla verilebilir.
- Risk tablosu sütunları: risk numarası, risk adı, türü veya kategorisi, etki, olasılık, derece.
- Gantt diyagramı: aktivitelerin süreleri, başlangıç-bitiş zamanları ve kaynakları. 1910'larda önerilmiştir.
- Kilometre taşları Gantt şemasında eşkenar dörtgenle gösterilir.
- Faaliyetler arası ilişki türleri: finish-start (FS), start-start (SS), finish-finish (FF), start-finish (SF).
- Kritik yol için Gantt şeması PERT çalışmasıyla desteklenmelidir.

## Detaylı Açıklamalar

### Proje planı içeriğinin özeti

- Plan "ne, ne kadar, ne zaman" sorularını yanıtlamalıdır.
- **Konu:** Amaç, hedefler, ana işlevler, özellikler, geliştirme süreci (hangi model, neden).
- **Kaynaklar:** İnsanlar (kullanıcılar, müşteriler, yazılım geliştiriciler), donanım, yazılım, zaman.
- **Risk yönetimi:** Riskler, kısıtlar ve varsayımlar.
- **Gider:** Kaynaklara bağlı olarak hesaplanır.
- **Çizelgeler:** Ağırlıklı olarak PERT ve Gantt.
- IEEE proje planı standardı daha ayrıntılıdır. Derste daha kısa bir yapı kullanılıyor.

### Sorunun tanımlanması

- Müşterinin hedefi belirlenir: Ör. maaş bordrosu, envanter, trafik kontrolü.
- Beklentiler, kullanılacak algoritmalar, veri tabanı ilişkileri, müşteriye verilecek bilgi ve belgeler belirlenir.
- Plan müşteriyle birlikte tekrar gözden geçirilir.
- Gereksiz teknik ayrıntıya girilmemelidir. Sorun müşterinin anlayacağı şekilde özlü tanımlanmalıdır.

#### Koşullar, kısıtlar ve varsayımlar

- **Proje kaynaklarıyla ilgili varsayım:** Proje süresince kimsenin rapor almayacağı varsayılarak çalışılır. Sorun olursa plana eklenir.
- **Proje kısıtı:** Herkes mesai saatleri içinde çalışacak, fazla mesai öngörülmüyor.
- **Kaynak kısıtı:** Network soruları için uzman gerekiyor ama uzman yalnızca belirli tarih ve saatlerde destek verecek.
- **Teknik veya problemle ilgili kısıtlar:** Geliştirilecek yazılımın konusu olan olayla ilgili sınırlamalar ve varsayımlar.

#### Gereksinimler ve kilometre taşları

- Gereksinimler hem gereksinim analizindeki işlevsel gereksinimleri hem de araç gereç, yazılım ve donanım kaynak gereksinimlerini kapsar.
- Geliştirme sürecinin dönüm noktaları belirlenir: gereksinim analizi, tasarım, sınama, bakım işlemlerinin bitişleri birer kilometre taşı olabilir.
- Her kilometre taşında gözden geçirme (review) yapılacağı plana yazılır.

#### Kabul kriterleri

- Yazılım geliştiriciler donanım, yazılım ve kullanıcı öğelerinin işlevlerini, kısıtlarını ve uyumunu belirler.
- Hedefler ve gereksinimler üst düzeyden belirlenir.
- Kabul kriteri örneği: Yazılım bittiğinde hangi olanaklara sahip olacağı ve müşterinin teslim alırken neleri kontrol edeceği.

### Çözüm yolunun kararlaştırılması

- Fizibilite aşamasında probleme getirilebilecek çözüm alternatifleri belirlenir. Her biri için yapılabilirlik analizi yapılır ve karşılaştırılır.
- Karar ekip hâlinde, tartışılarak verilir. Her çözüm yolu teknik ve ekonomik olarak değerlendirilir.
- Değerlendirmede kurumun kaynakları, teknoloji düzeyi ve istenen süre dikkate alınır.
- Fizibilite erken evrelerde de yapılabilir. Ama veri toplayarak yapmak gerçekçiliği artırır.
- Yöntemler: durum incelemesi, en kötü durum analizi, simülasyon, model oluşturma.
- Seçilen ve reddedilen çözümlerin gerekçeleri yazılır.
- Üretimin öncelik sırası liste olarak verilir. Gereksinim uyumsuzluklarını gidermek için önce bunlar listelenir. İşler şirket stratejisine göre sıralanmalıdır. Öncelik sırası yoksa yanlış kararlar alınabilir.
- Hoca fizibilite çalışmalarını yol haritası tamamlandıktan sonra daha ayrıntılı anlatacağını söyledi.

### Geliştirme sürecinin planlanması

- Önce geliştirme süreci modeli seçilir.
- Konfigürasyon yönetimi ve kalite kontrolünün nasıl yapılacağı planlanır.
- Kullanılacak yazılım araçları, yöntemler ve gösterim şekilleri belirlenir.
- Gider tahmini ve zamanlama programı yapılır.
- Sistemin işletilmesi ve bakımı için gereken kaynaklar tahmin edilir.
- Yazılım ölçümü ileriki haftalarda işlenecek.

### Planın diğer bölümleri

- Risk analizinden sonra alt aktiviteler (WBS), zaman çizelgesi, aktiviteler arası ilişkiler, iş gücü belirleme, görev atama, bütçe belirlenir.
- İş gücü tahmininde benzer projeleri daha önce geliştirmiş kişilerin tahmininden yararlanılabilir.
- **Kalite planı:** Hangi gözden geçirmelerin hangi takvimle yapılacağı ve kimlerin katılacağı. Kalite planını yazılım geliştiren ekip oluşturur.
- Bu çalışmaların sonunda SRS (Software Requirements Specification) ortaya çıkar.

### Analiz aşamasının alt adımları

- Pressman'ın kitabında ayrıntılı alt başlıklar vardır.
- Genelleştirilmiş hâli üç temel adımdır:
  1. Bilgi toplama.
  2. Modelleme.
  3. Modellerin yorumlanması.
- Bu üç adım akılda tutulursa ayrıntılı adımları saymak kolaylaşır.

### WBS ve süreç modeli

- Örnek sınav tipi soru: "Spiral modelin WBS yapısını 3. düzeye kadar ayrıntıyla yazınız."
  - Önce spiral modele göre yazılım geliştirmenin alt başlıkları belirlenir.
  - Sonra bunlara göre Gantt şeması çizilir.
- WBS madde madde numaralandırılarak veya blok diyagramla gösterilebilir. İnceleyen açısından fark yoktur. Önemli olan hiyerarşinin işle anlamlı olmasıdır.
- Zaman çizelgesinde her iş kırılımının ne zaman başlayacağı, hangi işlerle ilişkili olduğu ve bağlantının kuralı belirtilir. Böylece Gantt şeması ortaya çıkar.

### Yazılım risk yönetimi

- Risk şu anda problem değildir, gelecekte problem olabilir.
- Neden gelecekte olur? Çünkü değişim vardır: müşteri gereksinimleri, geliştirme teknolojileri, projeye bağlı varlıklar değişebilir.
- Seçimler de risk getirebilir: kullanılacak yöntem ve araçlar, çalışacak kişi sayısı, önem verilecek kalite ölçütleri.
- Kalite ölçütü örnekleri: yazılımın bağımsızlığı, yeniden kullanılabilirlik (reusability). Başka projelerde geliştirilip kütüphaneye konmuş alt ürünler kullanılacak mı? Bu belirtilmelidir.
- Genel kategoriler: proje riskleri, teknik riskler, işletmecilik riskleri.
- Ayrıntılı alt sınıflar Pressman'ın önceki baskılarından alınmıştır: ürün büyüklüğü, işletmecilik, müşteri, süreç, teknoloji, geliştirme ortamı, personel.

#### Ürün büyüklüğü riski

- Tahmin edilen büyüklük: satır sayısı veya function point, program sayısı, dosya sayısı.
- Ekibin önceki ürünlerinin ortalama büyüklüğünden ne kadar sapıyor? Ekip alışmadığı büyüklükte bir yazılım geliştiriyorsa risk vardır.
- Veri tabanı büyüklüğü: Önceki ürünlerin veri tabanlarından büyükse risk olabilir.
- Kullanıcı sayısı ve aynı anda kullanacak kişi sayısı: Daha önce böyle bir deneyim yoksa risktir.
- Yeniden kullanılan yazılım oranı: Geliştirmeyi hızlandırır. Ama bilgi sahibi olmadan kullanılırsa kritik hata nedeni olabilir.

#### İşletmecilik riski

- Ürünün şirket geliri üzerindeki etkisi. Yeni kurulan bir şirket bu ürüne göre değerlendirilecekse geliştiricilerde stres yaratır.
- Dağıtım tarihinin uygunluğu.
- Birlikte çalışacak diğer ürün ve sistemlerin sayısı.
- Son kullanıcıların düzeyi.
- Dağıtım gecikirse maliyet ve yaptırımlar.
- Müşteriye verilecek belgelerin istenen kalitesi ve miktarı.
- Ürünü pazarlayacak firmaların doğru seçilip seçilmediği.

#### Müşteriyle ilişkili risk

- Müşteriler gereksinimleri, kişilikleri ve satıcıyla ilişkileri açısından farklıdır. Bir risk kontrol listesi kullanılır.
- Bu müşteriyle daha önce çalışıldı mı?
- Müşterinin gereksinimleri hakkında somut fikri var mı?
- Ara kontrollere ve gözden geçirmelere katılmaya istekli mi? Kilometre taşında değerlendirme yapmazsa süreç boşuna gecikir.
- Değerlendirici olarak seçilen kişi ürün alanında teknik bilgili mi? Yazılım geliştirme sürecinden habersizse mümkün olmayan şeyler isteyebilir.
- Çoğu soruya "hayır" cevabı varsa müşteri riski vardır.
- Daha önce çalışılmış ama zor bir müşteri olduğu biliniyorsa "daha önce çalışıldı" cevabı riski azaltmaz.

#### Süreç riski

- Analiz, tasarım ve test rastgele mi, yoksa bir süreç modeline göre mi yapılıyor?
- Yazılım sürecinin yazılı tanımı ve alt başlıkları belirlendi mi?
- Çalışanlar belgeleme yapmaya istekli mi? (Hoca slayttaki "dokümanı kullanmaya istekli mi" ifadesini bu şekilde düzeltti.)
- Süreç tanımı başka projelerde kullanıldı mı? Ör. şirket önce waterfall kullanmış, XP denemiş, sonra Scrum'a geçmiş. Bu Scrum'la yapılan ilk proje mi?
- Yöneticilere ve teknik personele yazılım mühendisliği eğitimi verildi mi? Belgelemeye teşvik eden eğitim var mı?
- Yazılım mühendisliği standartları (ör. IEEE) biliniyor mu?
- Gereksinim analizi, tasarım ve kodlamada düzenli teknik gözden geçirmeler yapılıyor ve belgeleniyor mu?
- Konfigürasyon yönetimi yapılıyor mu? Konfigürasyon yönetimi yazılımdaki tüm değişikliklerin takip edildiği yapıdır.

#### Teknik risk

- Müşteri ile geliştirici arasındaki iletişime yardım eden spesifikasyon teknikleri kullanılıyor mu?
- Kod için belgeleme ve açıklama var mı?
- Tasarımda belirli bir yöntem var mı? Ör. nesneye yönelik UML veya klasik yaklaşımlar.
- Test case tasarımı için yöntem var mı?
- Analiz ve tasarımda CASE araçları kullanılıyor mu? CASE araçları rutin işi hızlandırır ve hatayı azaltır. Ama kullananların araç hakkında bilgili olması gerekir; bu da kayda geçirilmelidir.
- Prototip için hızlı geliştirme araçları kullanılıyor mu?
- Tüm projeler için kalite ölçütleri belirlendi mi?

#### Personel riski

- SEI'ın sorularından:
  - İnsanlar yeteneklerine göre mi kullanılıyor?
  - Yeterli çalışan var mı?
  - Personel çalışma süresinin ne kadarını projeye ayırıyor? Aynı anda birkaç proje varsa yarı zamanlı mı?
  - Verilen işler beklentileri karşılıyor mu? İşi severek mi, angarya olarak mı görüyorlar?
  - Personel kullanacağı araç ve yaklaşımlar konusunda eğitim aldı mı?
- Çoğuna "hayır" cevabı varsa personel riski vardır.
- Hocanın eklediği soru: Kritik görevlerdeki çalışanların projenin en yoğun zamanında işten ayrılma tehlikesi var mı? Bunun için bir önlem (ör. anlaşma) alındı mı?

### Risk değerlendirme ve risk tablosu

- Her projede bütün riskler çıkmaz. Önce riskin derecesi anlaşılmalıdır:
  - Riskin olma olasılığı nedir?
  - Riskin projeye etkisi nedir?
- Olasılık ile etkinin çarpımı riskin derecesini verir.
- **Örnek:** Proje yöneticisinin işten ayrılması.
  - Etkisi yüksektir.
  - Kuvvetli olmayan bir anlaşma yapılmışsa olasılık %30-50 olabilir.
  - İkisinin birleşimi risk derecesini verir.
- Risk tablosu oluşturma:
  1. Olası riskleri tüm ekip adlandırır.
  2. Kategoriler belirlenir.
  3. Herkes uzman olduğu risk üzerinde olasılık ve etkiyi değerlendirir.
  4. Tablo oluşturulur.
  5. Tablo sadeleştirilir.
- Risklerin olasılık ve etkisi zamanla değişebilir. Tablo sürekli izlenmelidir.

**Örnek risk tablosu (slayttaki örneğe göre):**

| Risk | Tür | Etki | Olasılık |
|------|-----|------|----------|
| Proje organizasyonunun yanlış kurulması | Proje riski | Orta | Yüksek |
| Büyüklük ve maliyet tahmininin hatalı olması | Proje riski | Büyük | Düşük |
| Sonuçların güvenilir modellenememesi | Teknik risk | - | - |
| CASE aracı kullanımı ve eğitimi | Teknik risk | - | - |
| Pazarlama riski (ilk ürününü satmaya çalışan yeni şirket) | İşletmecilik riski | Büyük | Yüksek |

- Hoca bazı satırların çok gerçekçi olmadığını, örnek olarak yazıldığını belirtti. Altyazıda bazı satırların değerleri net değil; tabloda "-" ile gösterildi.
- **Sadeleştirme:**
  - Etkisi ve olasılığı küçük veya orta olan riskler sürekli incelenmez. Daha aralıklı bakılır.
  - İlk tablo çok büyük çıkar ve kısa aralıklarla izlenmesi zordur.
  - Olasılık-etki öncelik grafiği yapılır. Etkisi ve olasılığı büyük olanlar küçültülmüş risk tablosunda tutulur.
  - Küçültülmüş tablodaki her risk her kilometre taşında değerlendirilir ve önlem alınır.
- **Riski azaltma örnekleri:**
  - Mazeret süresi koymak: Donanım kurulum siparişi için iki ay verilmişse, bitimine bir ay kala satış sorumlusuna durum sorulur.
  - Talep izleme: Projenin bağlı olduğu teslimatlar varsa sağlayıcı tarafından takip edilmesi.
  - İnsan iletişimine destek olmak.

### Gantt diyagramı

- Gantt şemasından önce WBS oluşturulmalıdır: aktiviteler hiyerarşik sıralanır, zaman bilgisi doldurulur, ilişkiler netleştirilir.
- Gantt çizelgesi her faaliyetin süresini, başlangıç-bitiş zamanlarını ve kullanacağı kaynakları gösterir.
- Planlamada oluşturulur. Yürütme aşamasında gerçek durumun plana uygunluğunu takip etmek için kullanılır.
- 1910'larda önerilmiştir. Bugün Gantt ve PERT çizen pek çok yazılım vardır. En yaygını MS Project'tir.

#### Örnek: Kitap satış web sitesi projesi

```text
1 Analiz
  1.1 Fizibilite çalışması
  1.2 Gereksinimlerin belirlenmesi (5 gün; fizibiliteden 1 gün sonra başlar, SS)
  1.3 Analiz bitimi toplantısı (kilometre taşı)
2 Tasarım
  2.1 Ön tasarım
  2.2 Ayrıntılı tasarım
  2.3 Tasarım bitimi toplantısı (kilometre taşı)
3 Geliştirme ve test
  ...
  Birim test (geliştirme bitince biter, FF)
Proje bitişi
```

- Gantt şemasında zaman ekseni haftalık verilmiş. Ör. fizibilite çalışması 21-29 Mart arasında.
- Analiz bitimi ve tasarım bitimi toplantıları değerlendirme (gözden geçirme) içindir. Kilometre taşları eşkenar dörtgenle gösterilir.
- **Soru:** Hangi süreç modeli, kaçıncı düzey?
  - Bir öğrenci "dördüncü düzey" dedi. Doğru cevap ikinci düzeydir. Birinci düzey analiz, tasarım, geliştirme ve test; ikinci düzey bunların alt başlıklarıdır. Ayrıntılı tasarımın altına inilmemiştir.
  - Model waterfall'dur. Analiz bitince tasarım, tasarım bitince geliştirme ve test başlıyor. Spiral veya çevik değildir. Çevik yaklaşım aktiviteleri daha bütünleşik gösterir.
- Bir işin başlangıcı çoğu zaman tarih olarak değil, ilişkiyle verilir. Ör. "Analiz bittikten sonra tasarım başlar."
- Projeye bir başlangıç tarihi verilir. Toplam süre aktiviteler arası ilişkilerden hesaplanır.

#### WBS kaç düzey olmalı?

- Ekibin projeyi ne kadar yakından takip etmek istediğine bağlıdır. Sıkı takip için alt başlıklara kadar inilebilir.
- Waterfall için ikinci düzeye rahatça gelinir, üçüncü düzeye de inilebilir. Zorlayarak alt başlık üretilmemelidir.
- Üçüncü düzey örnekleri:
  - Fizibilite çalışması: alternatif çözüm yollarını belirleme, her biri için teknik ve ekonomik fizibilite.
  - Ayrıntılı tasarım: veri tabanı tasarımı, ekran tasarımı, program tasarımı, tasarım raporu oluşturma.
- Çok büyük olmayan projelerde çok alt adımlara inmek planın kullanımını zorlaştırır.

### Faaliyetler arası ilişkiler

- **Finish-Start (FS):** Önceki iş bitince sonraki başlar. Ör. analiz bitince tasarım başlar.
- **Start-Start (SS):** İki iş aynı zamanda yürüyebilir. Örnekte fizibilite başladıktan 1 gün sonra gereksinim belirleme başlar.
- **Finish-Finish (FF):** Bir işin bitmesi diğerinin bitmesine bağlıdır. Örnekte birim testin bitmesi 11 numaralı geliştirme aktivitesinin bitmesine bağlı.
- **Start-Finish (SF):** Bir işin bitişi diğerinin başlamasına bağlıdır.
- **Kritik yol:** Projenin tamamlanması için yol üzerindeki faaliyetlerin süreleri. Gantt şemasında doğru gösterilmesi için PERT ile sıralama ve dengeleme yapılmalıdır.

### Proje planlama araçları

- Gantt ve PERT elle, kareli kâğıda da çizilebilir. Ama bugün araç kullanılır.
- MS Project en yaygın araçtır. Laboratuvarda Microsoft ürünleriyle yüklüdür ve iş yerlerinde yaygındır. Başka araçlar da kullanılabilir.
- Bir öğrenci iş yerinde MS Project lisansının yalnızca proje yöneticilerine verildiğini söyledi. Hoca öğrencilerin erişimini asistanlara soracağını söyledi.

### Makale önerileri ve duyurular

- Hoca gönderilen makale önerilerini inceliyor. Uygun bulduklarına hemen cevap veriyor.
- Cevap verilmeyenlerin bir kısmı uygun değil, dersin konuları içinde zaten var veya başka önerilere çok benziyor.
- Çevik projeler ve Scrum'u farklı açılardan karşılaştıran çok sayıda öneri geldi. Bu konuda öneri verenler yeniden araştırma yapmalı.
- Ölçüt: Konu dersin kapsamına girmeli. IEEE Transactions on Engineering Management kullanılabilir ama tamamen farklı bir alandaki proje yönetimi uygulamaları uygun değildir.
- Uygun olmayanlar önümüzdeki haftaya kadar hocanın notlarına göre yenilenmiş teklif göndermeli. Olmazsa hoca bir makaleden veya kitaptan konu atayacak.
- Onay alanlar çalışmaya başlayabilir. Erken hazırlananların sunumu öne alınabilir.
- Seçilen makaleler İngilizce olacak. Hazırlanacak bildiri veya makale Türkçe olacak. Erasmus öğrencisi için İngilizce bir konu verilecek.
- Birkaç hafta daha temel konular işlenecek. Sonra ara sınav, ardından makale sunumları yapılacak.
- Hiç katılmayan öğrenciler devamsız sayılacak. Derslere asgari katılım gerekli.

### Gelecek ders

- Zaman planlaması, WBS ve proje planlama araçları üzerinde durulacak.

### Ders sonrası notlar

- Yaklaşık 00:15:57-00:22:14 arasında hocanın sesi ve ekran paylaşımı kesildi. Hoca derse yeniden bağlanıp konuyu tekrar anlattı.
- Gantt şemasındaki düzey sorusunda bir öğrencinin "dördüncü düzey" cevabını hoca düzeltti. Doğrusu ikinci düzeydir.
- Hoca, slayttaki "dokümanı projede kullanmaya istekli mi" ifadesinin hatalı olduğunu, doğrusunun "belgeleme yapmaya istekli mi" olduğunu söyledi.
- Gantt diyagramı Henry Gantt tarafından 1910'larda geliştirilmiştir; hocanın verdiği tarih doğrudur.
- Altyazıdaki "Dant şaması", "gaz şavası" Gantt şemasıdır. "Kaze aracı" CASE aracıdır.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
