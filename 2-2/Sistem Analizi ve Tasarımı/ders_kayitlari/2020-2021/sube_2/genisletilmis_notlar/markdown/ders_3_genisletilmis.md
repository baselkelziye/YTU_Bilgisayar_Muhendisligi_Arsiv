# Ders 3 Genişletilmiş Notu: Süreç Modelleri, Ön İnceleme ve Fizibilite Çalışması

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki dersin tekrarı: sistem geliştirme yaşam döngüsü
- 2. Süreç modelleri
- 3. Ön inceleme
- 4. Fizibilite çalışması ve türleri
- 5. Teknik fizibilite
- 6. Sosyal, yönetim ve yasal fizibilite
- 7. Fizibilitenin önemi ve kapsamı
- 8. Ekonomik fizibilite ve değerlendirme yöntemleri
- Örnek Sorular

## 1. Önceki dersin tekrarı: sistem geliştirme yaşam döngüsü

Ders, önceki haftada yetişmeyen konularla başladı. Hoca önce geçen haftanın konularını hatırlattı: bilgi sistemlerinin hangi türlere ayrıldığı, bu türler arasında nasıl bir girdi-çıktı ve hizmet ilişkisi olduğu, hangi özelliklere sahip bir sistemin hangi türe girdiği; ardından bilgi sistemi geliştirme sürecinin tarafları (paydaşları), rolleri ve aralarındaki bağıntılar.

Bütün bunların ortak sonucu şuydu: bir bilgi sistemi, özellikle büyük ve karmaşık bir problem için kurulan bir sistem, "hadi oturalım kodlayalım" diye birdenbire ortaya çıkmaz. Uzun, tanımlı ve tutarlı süreçler sonunda geliştirilir. Bu sürece **sistem geliştirme yaşam döngüsü** adı verilir. Slayttaki döngü şu adımlardan oluşur (ekrandan, 00:05:00):

```text
Kapsam ve Planlama → Gereksinim Analizi → Tasarım → Gerçekleştirme ve Test
        ↑                                                      ↓
Operasyon ve Bakım  ←  Kurulum ve Dağıtım  ←───────────────────┘
```

Problemi tanımlamak ve yapılabilirliğine bakmak (kapsam ve planlama; fizibilite bu adımdadır), problemi anlamak (gereksinim analizi), nasıl çözüleceğini ortaya koymak (tasarım), çalışan sistemi inşa etmek ve test etmek, sistemi devreye almak ve hayatı boyunca isterleri karşılayacak biçimde bakımını yapmak bu döngünün adımlarıdır. Yeni istekler, değişiklikler, güncellemeler ya da hatalar ortaya çıktıkça döngü tekrar tekrar işletilir.

## 2. Süreç modelleri

Hoca bu döngünün hangi yollarla işletilebileceğini, geçmişte neler kullanıldığını ve bugün nelerin yaygın olduğunu ayrıntıya girmeden tanıttı. Süreç modellerinin ayrıntısı yazılım mühendisliği dersinde işlenecek; bu derste klasik (geleneksel) süreç modeli olan şelale modeli izlenecek. Slaytta sayılan modeller şunlardır (ekrandan, 00:10:00):

- Klasik Süreç (Waterfall)
- Model Oluşturma
- Evrimsel Süreçler
  - Artımlı Model
  - Spiral Model
- RUP Modeli
- Aykırı Programlama
- Çevik Süreçler

### 2.1 Klasik süreç: Waterfall (şelale) modeli

Waterfall modeli aslında bilişimden değil, inşaattan doğmuştur. Mühendislik çözümlerinde bir adım bitmeden diğerinin yapılamadığı durumları yönetmek için ortaya konmuştur. Hocanın benzetmesi: bir bina yapılacaksa önce zemin etüdü yapılır, sonra temel kazılır ve hazırlanır, etrafı doldurulur, katlar adım adım çıkılır, ardından elektrik, su, asansör, kaplama, dış ve iç cephe, kapı ve pencereler yapılır; gerekirse dayanıklılık, sarsıntı ve rüzgâr testleri yapılır ve en sonunda bina devreye alınır. Bakım da binanın ömrü boyunca sürer: cam kırılır değiştirilir, tesisatta arıza olur onarılır.

Bilgi sisteminde de aşamalar mantıksal olarak birbirini izler: bir faz bitince onun çıktılarıyla beslenen sonraki faz başlar. Gereksinim analizi, tasarım, gerçekleştirme, test ve bakım bu sırayla bitirilerek ilerlenirse süreç şelale modeliyle işletilmiş olur. Slaytta iki gösterim vardır (ekrandan, 00:15:00):

- Requirements analysis → Design → Implementation → Testing → Maintenance
- Requirement Collection → Feasibility Study → Design → Coding → Testing → Installation → Maintenance

Adım sayısının illa beş olması gerekmez; adımlar daha da ayrıntılandırılabilir. Hoca ikinci gösterimde gereksinim toplamanın fizibiliteden önce yazıldığını, kendilerinin fizibiliteyi genellikle önce yapmayı tercih ettiğini belirtti.

Modelin adı şelaleden akan sudan gelir: su yukarı çıkamaz, yani bir faz tamamen bittikten sonra sonrakine geçilir ve süreçte geri dönüş tanımlı değildir. Bir sonraki fazda önceki bir hata fark edilirse ne olur? Kötü olur. Bu yüzden bu yaklaşımda her kutunun, her süreç adımının hatasız işletilip çıktılarının düzgün üretilmesi esastır.

Waterfall eskimiş gibi görünse de bazı projelerde hâlâ en uygun modeldir. Örneğin devletin açtığı bir ihalede ya da askerî bir projede gereksinimler harfi harfine tanımlıdır: ekranda kaç düğme olacağı, veri tabanında okumanın 3 ms, yazmanın 8 ms süreceği, hangi tablo yapısının kullanılacağı bellidir. Bu tür kontratlı projelerde waterfall uygundur; faz sonlarında kontrol yapılmasını ve "buraya kadar beklentileri karşıladınız, şu kadar ödemeyi alabilirsiniz" gibi hak edişlerin takibini kolaylaştırır.

> **Hocanın vurgusu:** Waterfall 70'lerden kalma ve demode görünse de bazı projelerde hâlâ en uygun süreç modeli olabilir; ders de temel süreç modeli olan bu yoldan ilerleyecek.

### 2.2 İteratif (artımlı) waterfall

Waterfall'un eksiği geri dönememektir. İteratif waterfall bu eksiği giderir. Hoca bunu şelalenin altına konmuş bir su pompasına (hidrofor) benzetti: bir şeyin tasarıma kadar geri gitmesi gerekiyorsa pompa suyu yukarı basar ve akış oradan yeniden başlar. Adımlara kesin geri dönülemez değil, geri dönme imkânı sunan bir iyileştirmedir.

### 2.3 Model (prototip) oluşturma

Bu yaklaşım da waterfall'dan türetilmiştir. Önce gereksinim analizi yapılır, ardından bir prototip (taslak tasarım) oluşturulur ve bir modele dönüştürülür. Prototipin istekleri ne kadar karşıladığına bakılır ve üretim yapılır. Sonra prototip tekrar tekrar geliştirilir (sürüm 0.1, 0.2 gibi); işlevler eklenerek bütün gereksinimler karşılanır ve sonunda yazılımın tamamı ortaya çıkar. Yani bir modelden ya da prototipten başlayıp son ürüne doğru evrilmektir.

### 2.4 Evrimsel süreçler ve spiral model

Zamanla bilgi sistemi geliştirmenin, gereksinimler değiştikçe doğal olarak değişmeyi ve yenilik getirmeyi gerektiren bir akış olduğu görüldü; evrimsel süreçler bu yüzden yaygınlaştı. Slaytta şöyle özetlenir (ekrandan, 00:20:00):

- Artımlı: İteratif olarak waterfall uygulanır.
- Spiral: Prototipten versiyona doğru evrim ilerler.

Spiral modelin şeklinde düzlem altı bölgeye ayrılmıştır: Müşteri İletişim, Planlama, Risk Analizi, Mühendislik, Yapım ve Değişim, Müşteri Değerlendirme. İçteki çekirdekten dışa doğru halkalar şunlardır: kavram geliştirme projesi, yeni ürün geliştirme projesi, ürün zenginleştirme projesi, ürün bakım projesi (ekrandan, 00:20:00).

Her turda önce müşteriyle iletişim kurulur (iş analizi), sonra planlama yapılır, ardından risk analizi gelir. Spiral modelde riskler ön plandadır: riskli işler önce yapılmaya çalışılır ki ileride daha büyük hatalara yol açmasın. Mühendislik aşamasında tasarım gözden geçirilir, yapım ve değişim aşamasında gerçekleştirme yapılır. Sonra müşteri değerlendirmesi gelir: neyin olduğu, neyin eksik ya da fazla olduğu tartışılır ve dıştaki bir sonraki döngüye geçilir. Ürün devreye alındıktan sonra bakımda da aynı iletişim, değişiklik ve geri besleme döngüsü sürer.

### 2.5 Unified Process (RUP)

Nesneye yönelik yazılım geliştirme yerleşip standart hâle gelince, Rational firması nesneye yönelik analiz ve tasarım yaklaşımlarını temel alan tümleştirilmiş bir süreç modeli tanımladı: Unified Process. Bu modelde kullanım senaryoları (use case) ön plandadır, genel mimari merkeze alınır ve önceki deneyimlerden çıkan artımlı ve iteratif çalışma uygulanır.

Model iki boyutlu bir matristir. Bir boyutta fazlar (Inception, Elaboration, Construction, Transition), diğer boyutta iş akışları (Requirements, Analysis, Design, Implementation, Test) vardır. Matristeki yoğunluk, harcanan iş yükünü (saat, gün) gösterir ve sol üstten sağ alta doğru kayar:

- Başlarda, Inception ve Elaboration'da gereksinim işi yoğundur.
- Elaboration'da analiz modeli de oluşturulur.
- Construction'da önce tasarım ağırlaşır, iterasyonlar ilerledikçe tasarımın yükü azalır, gerçekleştirmenin (kodlamanın) yükü artar.
- Sonda testler ve devreye alma (Transition) gelir.

Her fazda birden çok iterasyon olabilir; matristeki her satır bir iterasyon gibi düşünülebilir. İterasyonların sabit sürelerde yapılması önerilir. Her faza bir model karşılık gelir: kullanım senaryosu modeli, analiz modeli, tasarım modeli, barındırma (dağıtım) modeli (bileşenlerin fiziksel olarak nerede ve nasıl duracağı, yazılım mimarisi) ve test modeli. Böylece süreç model güdümlü, diyagramlar ve tasarımla ilerletilir. Hoca, Unified Process'in çok kalın bir kitabı olduğunu ve yaklaşık 20 yıllık bir yaklaşım olduğunu söyledi.

### 2.6 Aykırı programlama (Extreme Programming)

Unified Process'in açtığı yol aykırı programlama manifestosuna götürdü. Bu yaklaşım eski alışkanlıkların terk edilmesini, ekip olarak çalışırken temel değerlerin gözetilmesini ve önerilen pratiklerin uygulanmasını söyler. Slayttaki değer ve pratikler (ekrandan, 00:25:00):

| 4 temel değer | 12 pratik |
|---|---|
| İletişim | Sistem metaforu |
| Basitlik | Ekip üyesi müşteri |
| Geri besleme | Kısa aralıklı yayımlar |
| Cesaret | Planlama oyunu |
| | Basit tasarım |
| | Ortak kod mülkiyeti |
| | Kodlama standartları |
| | Eşli programlama |
| | Test |
| | Sürekli tümleştirme |
| | Devamlı yeniden tasarım |
| | Devam ettirilebilir hız: 40 saat/hafta |

Değerlerin anlamı: iletişim ekip içindeki iletişimdir; basitlik problemi küçük, "yutulabilir" parçalara bölmektir; geri besleme hem müşteriyle hem ekiple "olmuş, olmamış" diye konuşarak ilerlemektir; cesaret korkmadan problemin üzerine gitmektir.

Hoca pratiklerden bazılarını açıkladı:

- Önceki modellerden en çok ayrılan yanı, müşterinin (ya da temsilcisinin) ekibin üyesi olarak geliştirmeye katılmasıdır.
- Çok kısa aralıklarla sürüm çıkarılır; yani iteratif ve artımlı çalışılır.
- Tasarım mümkün olduğunca basit tutulur, çok fazla doküman yüküyle uğraşılmaz.
- Kodun ya da ürünün mülkiyeti ortaktır: "bu modülü şu kişi yazmıştı" diye suç başkasına atılmaz, bütün sorumluluk ortaktır.
- Eşli programlamada iki kişi tek bilgisayarda kod üretir; iki beynin birlikte çalışmasının, tek beyinden ya da iki ayrı beynin paralel çalışmasından daha verimli ve düzgün sonuç vereceği öngörülür.
- Test asla ihmal edilmez.
- Kod sürekli tümleştirilir, ayrı tutulmaz; ortak bir sürüm kontrol deposunda bir arada tutulur.
- Sabit hızla çalışılır: örneğin haftada 40 saat, ama her hafta 40 saat. Gece gündüz çalışıp tükenen bir ekip istenmez.

Hoca çevik manifestoya da değinip öğrencilerden Extreme Programming ve Agile Manifesto'yu araştırmalarını istedi.

### 2.7 Çevik süreçler ve Scrum

Çevik süreçler bu temellere dayanır, farklı yönleriyle değişerek ilerler ve günümüzde en yaygın kullanılan süreç modelleridir. Scrum çok popüler bir çevik yöntemdir:

- Ekipler küçüktür ve her gün kısa bir toplantıyla başlarlar.
- Daha büyük bir çevrim tamamlandığında daha geniş bir değerlendirme toplantısı yapılır ve geri besleme mekanizması işletilir.
- Görev dağılımı bir pano üzerinde (kâğıtla ya da bilgisayar ortamında) izlenir: kimin hangi işi ne kadar ilerlettiği, işin hangi faza geldiği görülür.
- Küçük ve büyük çevrim bir aradadır; aşırı dokümantasyon yapılmaz ama kullanım senaryolarına benzeyen kullanıcı hikâyeleri (user story) gereksinim dokümanı olarak kullanılır.
- Sabit aralıklarla sürüm çıkarılır, yeni özellikler eklenerek artımlı ilerlenir.

## 3. Ön inceleme

Bu bölümden itibaren süreç modelindeki adımların her birinde ne yapılması gerektiğinin ayrıntısına girilir. Bu dersin ve sonraki dersin konusu ön inceleme ve fizibilite (yapılabilirlik etüdü) çalışmasıdır.

### 3.1 Ön incelemenin amacı

Size bir iş, bir istek geldiğini düşünün: bir müşteri ya da büyük bir holdingin bilgi teknolojileri birimiyseniz bir pazarlama ya da stok ekibi "şöyle bir sisteme ihtiyacımız var" diye talepte bulunuyor. Ön inceleme fizibilitenin ilk adımıdır (Unified Process'teki Inception'a benzer). Burada tek bir soru genel hatlarıyla incelenir: bu projeyi kabul edip devam mı edeceğiz, yoksa "yapamayız" mı diyeceğiz? Ayrıntılara fizibilitede girilir. Slayttaki sorular (ekrandan, 00:35:00):

- Projenin olabilirliği belirlenir:
  - Projeye (yeni sisteme) gerçekte ihtiyaç var mı?
  - Sistemin gerçekleştirilmesi için neye ihtiyaç var?
  - Ne kadar süreye ihtiyaç var?
  - Tahmini bütçe nedir?
  - Faydaları ve zorlukları nelerdir?
- Kısaca: Tamam mı? Devam mı?

İlk soru, talebin gerçek bir ihtiyaç mı yoksa boş bir hayal mi olduğunu sorgular. İkinci soru kaynaklarla ilgilidir: zaman, iş gücü (insan gücü), bilgi birikimi ve fiziksel ya da maddi imkânlar kabaca düşünülür.

### 3.2 Ön inceleme örnekleri

- **Maddi kaynak:** İşin yürümesi için 4 grafik kartı gerekiyor ve tanesi yaklaşık 1000 dolar olsun. Toplam 4000 dolar, o günkü kurla yaklaşık 32 bin lira eder. Şirketin sermayesi 10 bin lira ise bu kaynak karşılanamaz; proje doğrudan reddedilebilir.
- **İhale şartları:** Bütün üniversiteler için bir ders kayıt sistemi ihalesi açıldığını düşünün. İhale belli sayıda tamamlanmış proje, belli büyüklükte ve yetkinlikte bir ekip ve büyük bir teminat isteyebilir. Bunlardan biri ya da birkaçı karşılanamıyorsa ihaleye girilemez.
- **Zaman:** Çok sayıda sistemle tümleşmesi, birçok işlem yapıp rapor üretmesi gereken bir işlem bilgi sistemi bir ay içinde isteniyor; ekip 5 kişi ve başka projeler de yürütüyor. Bu durumda da proje yapılamaz sayılabilir. Bu aşamada süre ayrıntılı kestirilemez, ama bu kadar bariz durumlar görülebilir.
- **Bütçe:** Gerçekten para, sermaye ya da finans kaynağı (yatırımcı, kredi, hibe) bulunabiliyor mu?

Son olarak projenin faydaları ve zorlukları, yani kabaca bir maliyet-fayda dengesi değerlendirilir ve eldeki ya da elde edilebilecek imkânlarla işin yapılıp yapılamayacağına karar verilir.

### 3.3 Kapsam tanımlama dokümanı (Project Charter)

Ön incelemenin sonunda genellikle bir rapor hazırlanır: **kapsam dokümanı**; yapılan işe de **kapsam tanımlama** denir. Kurumlar, hatta aynı kurumun birimleri farklı biçimler kullanabilir; tek bir doğru biçim yoktur. Genel olarak şunlar yazılır:

- **Ürün:** Bizden ne isteniyor?
- **Kalite tanımları:** Ne kadar iyi olmalı? Performans, kod kalitesi, birim zamanda desteklenecek işlem miktarı; askerî bir yazılımsa belli bir askerî standarda uygunluk gibi.
- **Zaman:** Ne kadar süre verildiği ve kabaca nasıl bir zaman planı olabileceği.
- **Maliyet:** Neye mal olacağı ya da ne kadar bütçe verildiği ve nasıl dağıtılacağı.
- **Kaynaklar:** Hangi ekipler, çalışanlar, sunucular, geliştirme ortamları kullanılacak.

Bunlar ayrıntıya girmeden, ana hatlarıyla belirlenir. Bu dokümanın diğer adı **Project Charter**'dır. Kabaca bir duyuru, bir niyet beyanıdır: "Bizden şu ürün bekleniyor; şu kaliteleri karşılayacak; şu kadar zamanda, şu bütçeyle, şu kaynakları kullanarak yapacağız."

## 4. Fizibilite çalışması ve türleri

Ön incelemeden sonra artık sürecin içine girilir. Temel süreçteki ilk adım bir yapılabilirlik etüdüdür: **fizibilite çalışması**. Ürün çıkaran bütün projelerde en başta yapılması gereken çalışmadır. Hoca, özellikle ekonomik tarafta kullanılan araçların bilişime özgü olmadığını, işletme ve iktisat alanlarının çalışma konusu olduğunu belirtti.

Slayttaki tanım (ekrandan, 00:40:00):

- **Amaç:** Projenin olabilirliğinin araştırılması.
- **Çıktı:** Genel hatlarıyla proje planı ve tahmini bütçe.

Amaç, projenin yapılabilir olup olmadığını araştırmak, hangi kaynaklara ne kadar ihtiyaç olduğunu net olarak ortaya koymak ve hangi yoldan yüründüğünü alternatifleriyle birlikte belirlemenin temellerini atmaktır. Fizibilitenin sonunda bir proje planı, iş-zaman planı ve iş kırılım yapısı oluşur; bütçe ve kaynak gereksinimleri belirlenir. Sonuçta bir **fizibilite dokümanı** yazılır. Alternatifler olduğu için karşılaştırma genellikle tablo ile yapılır.

Bir bilgi sistemi geliştirirken incelenmesi gereken toplam 6 fizibilite türü vardır:

1. **Teknik fizibilite:** İşin içinde çok fazla bilişim olduğu için temel türdür; alt parçalara bölünür.
2. **Zaman fizibilitesi:** Sonraki derste bir vaka çalışmasıyla işlenecek.
3. **Sosyal fizibilite:** Sistemin taraflarının, özellikle kullanıcı ve müşteri tarafının sistemi kabul edip etmeyeceği; kabul görmesi için neyin nasıl olması gerektiği. Yapılan sistem müşterinin beklentilerine ya da çalışma şekline uygun olmayabilir.
4. **Yönetim fizibilitesi:** Yönetim kademesi bunu kabul edecek mi? "Bu kadar para harcıyoruz, bize ne fayda sağlayacak?" sorusu; örneğin verimlilik artışının incelenmesi.
5. **Yasal fizibilite:** Hocanın "hep yanlış yapılan" diye üzerinde özellikle durduğu tür.
6. **Ekonomik fizibilite:** Her şey bir katsayıyla çarpılarak parasal karşılığa çevrilebilir (sosyal kabul gibi bazı şeyler hariç). Ne kadar kaynak harcanacağı, her kaynağın maliyeti, sistemle ne kazanılacağı (satış, verimlilik artışı) ve ne zaman kâra geçileceği incelenir.

Bu derste zaman fizibilitesi atlanıp sonraki derse bırakıldı; diğer türler sırayla işlendi.

## 5. Teknik fizibilite

Teknik fizibilite, geliştirilecek bilgi sistemiyle ilgili her türlü teknik olanağın yapılabilir olup olmadığının ve nasıl yapılabileceğinin belirlenmesidir. Slayt (ekrandan, 00:45:00):

- Sistemin her türlü teknik olanaklarının belirlenmesi. Örneğin:
  - Yazılım Fizibilitesi: İşletim Sistemi, Yazılım Geliştirme Ortamı, VTYS, Uygulama Sunucu, Destek Yazılımlar, ...
  - Donanım Fizibilitesi: Geliştirme ihtiyaçları, kısa-orta vadeli büyüyecek ihtiyaçlar, ...
  - İletişim Fizibilitesi: Haberleşme ihtiyaçları, protokoller, ...
- Riskler göz önünde tutulmalı.
- Teknik yetersizlikler tamamlanmalı.

### 5.1 Yazılım fizibilitesi

Her yazılım kalemi için alternatifler artıları ve eksileriyle karşılaştırılır. Bütün alternatifler değil, en az 2-3 aday karşılaştırılmalıdır.

- **İşletim sistemi:** Hocanın uç örneği: konteyner mimarisinde mikro servislerle çalışacak bir altyapı isteniyor. Windows kullanılabilir, ama lisans bedeli, bakım ve güncelleme sorunları, konteyner ortamının kararlı ve genişletilebilir çalışmasıyla ilgili problemler çıkabilir. Linux kullanılırsa yetkin eleman bulmak zor olabilir. BSD gibi bir başka işletim sistemi de düşünülebilir.
- **Yazılım geliştirme ortamı:** .NET ve Visual Studio, bir IBM ürün ailesi ya da Eclipse gibi açık kaynak araçlar, Java için belli geliştirme ortamları. Hangisi biliniyor, hangisi kaça mal olur, eğitim gerekiyor mu, deneyim var mı, topluluk desteği var mı, projedeki işlemleri kolaylaştırıyor mu?
- **Veri tabanı yönetim sistemi, uygulama sunucuları, sistem ve destek yazılımları:** Sistemde kullanılması gereken her yazılım kaynağı için aynı karşılaştırma yapılır.

### 5.2 Donanım fizibilitesi

> **Hocanın vurgusu:** Öğrenci projelerinde en büyük yanlış, donanım fizibilitesini yalnız geliştirme için gereken bilgisayarların karşılaştırılması sanmaktır.

Örneğin 8 GB RAM'li, Intel Core i7 işlemcili bir dizüstü ile M1 işlemcili, 16 GB RAM'li bir MacBook'u fiyat ve özellikleriyle karşılaştırıp bırakmak donanım fizibilitesi değildir; yalnız onun küçük bir parçasıdır. Sistem geliştirildikten sonra devreye alınır, işletilir, bakımı yapılır ve destek personeliyle çalışır hâlde tutulur. Bu yüzden yalnız geliştirme ihtiyaçları değil, işletme ve devrede tutma için gereken bütün donanım ihtiyaçları karşılaştırılmalıdır:

- Sistem adanmış (dedicated) bir sunucuda mı duracak, barındırma firmasından alınan paralelleştirilebilir sanal sunucular yeterli mi, yoksa hipervizör mimarisinde sanal makineler mi kullanılacak?
- Sistem kısa ve orta vadede ne kadar hacim ve trafik karşılayacak? Bugün bin kullanıcı varsa yarın on bin, yüz bin kullanıcı olabilir. Bu büyümede ihtiyaçlar nasıl değişir, beş yıl sonra hangi sunuculara ve sistem kaynaklarına gerek olur?
- Stok takibi yapan bir depo sisteminde ürünler barkodla mı, lazer okuyucuyla mı, tabletin kamerasıyla mı okutulacak? Bunların da artısı ve eksisi tartılır.

Hoca, geçmiş dönemlerden kopyalanan fizibilite raporlarında "iki dizüstü, bir tablet yaz geç" gibi bir yaklaşım gördüklerini ve bunun fizibilite olmadığını söyledi. Donanım fizibilitesinde sistemin bütün hizmet ömrü boyunca gereken teknik donanım ihtiyaçları göz önüne alınmalıdır.

### 5.3 İletişim (ağ) fizibilitesi

Yazılım ve donanımda söylenenlerin ağ tarafında da karşılığı vardır. "100 megabit fiber internet kodlama için yeter" demek iletişim fizibilitesi değildir. Bin kullanıcıda ne kadar bant genişliği gerektiği ve on bin kullanıcıda bunun neye çıkacağı, haberleşmenin nasıl olması gerektiği, yedekli hat gerekip gerekmediği, bir felaket ya da kesinti durumunda sistemin nasıl davranacağı değerlendirilir. Hangi protokollerin kullanılacağı da alternatifleriyle karşılaştırılır; örneğin dosya transferi doğrudan FTP ile mi yoksa başka bir yöntemle mi yapılacak.

### 5.4 Riskler ve yetersizlikler

Teknik fizibilite; geliştirme, çalışma ve devrede tutma süresince, yani yaşam ömrü boyunca gereken ihtiyaçların alternatifleriyle karşılaştırılmasıdır. Riskler her zaman ön planda tutulmalıdır: yüksek risk tehlike demektir; seçimlerde riski düşük olan tercih edilir. Belli konularda yetersizlik görülürse fizibilite çalışması sırasında bu yetersizliklerin giderilmesine çalışılır.

## 6. Sosyal, yönetim ve yasal fizibilite

### 6.1 Sosyal (operasyonel) fizibilite

Slayt (ekrandan, 00:55:00):

- Oluşturulacak sistemin hedef kitlesi tarafından kabul edilip edilemeyeceğinin araştırılması.
- Sistemden direkt olarak etkilenecek kullanıcı grupları incelenip kontrol edilir.
- İstekleri karşılaması önemli.
- Operasyonel fizibilite olarak da görebilirsiniz.

Hedef kitle sistemi kabullenecek mi; kabullenmeyecekse neler yapılabilir, alternatifler nelerdir? Sistemin nasıl bir arayüzü ve etkileşim noktaları olmalı, ne çıktılar üretmeli, hangi işlemleri yapmalı? Bunlar kullanıcı kabulü açısından incelenir.

Son kullanıcıya yönelik bir ürün yapılıyorsa potansiyel kullanıcılar incelenir. Belli bir müşteri ya da iş birimi için çalışılıyorsa yalnız doğrudan etkilenecek gruplar incelenir: stokla ilgili bir sistem için muhasebe departmanını incelemeye gerek yoktur. En önemlisi, isteklerin insanların kabul edip kullanabileceği biçimde karşılanmasıdır.

Bir bilgi sistemi yapılıp devreye alındığı hâlde işletmenin belli bir biriminde pek kullanılmayabilir, dirençle karşılaşabilir. Kullanıcılar her şeyi doğrudan kabul etmeyebilir: "bu sistem çok karışık, ekranlarında kayboluyorum, şunu işaretlemeyi unutunca bir şeyler yanlış oluyor" gibi şikâyetler duyuluyorsa sosyal fizibilite düzgün yapılmamıştır.

Bu türün diğer adı **operasyonel fizibilitedir**: sistemin işletim (operation) anlamında kabulüne yönelik karşılaştırmalı incelemelerdir.

### 6.2 Yönetim fizibilitesi

Slayt (ekrandan, 01:10:00):

- Geliştirilecek olan sistem yönetimi nasıl etkiliyor?
- Yönetim sistemden ne kadar fayda sağlayacak?

Burada kullanıcıların değil, yönetimin sistemi kabul edip etmeyeceği incelenir. Yeni sistem yönetimi ne kadar, nasıl ve hangi yönde etkiliyor; parasal açıdan ve kârlılık açısından neye yol açıyor? Orta ve üst yönetim kademesinin sistemden ne kadar fayda sağlayacağı tartışılır; kısaca "patronlar ya da müdürler bunu kabul eder mi?" sorusudur. Yönetim bilgi sistemi (MIS), karar destek sistemi (DSS) ya da üst yönetim bilgi sistemi gibi yönetime hizmet eden bir sistem yapılıyorsa yönetim fizibilitesi çok önemli hâle gelir; hangi raporların ya da gösterge panolarının (dashboard) nasıl olacağı alternatifleriyle karşılaştırılır.

### 6.3 Yasal fizibilite

Slayt (ekrandan, 01:15:00):

- Sistem kanun ve yönetmeliklere uygun mu?
- Mevcut patent ve fikri sınai hakları ihlal ediyor mu?
- Belli kaynakların kullanımı için özel izinlere – lisanslara gerek var mı?
- Sistem işletmenin yaptığı anlaşmalara uygun mu?

> **Hocanın vurgusu:** Kopyala-yapıştır fizibilite raporlarında "bu bilgi sistemi herhangi bir kanunu ihlal etmemektedir" cümlesi görülür. Bu yasal fizibilite değildir; bir kanunu ihlal etmek zaten suçtur.

Yasal fizibilite, sistemin çalışma şeklinin kanun ve yönetmeliklerle belirlenmiş şekillere uygun olup olmadığının ve uymak için neyin değişmesi gerektiğinin tartışılmasıdır.

**Örnek: ders notu paylaşım sistemi.** Öğrencilerin ders notlarını paylaştığı bir sistem yapıldığını düşünün. Burada incelenmesi gereken kanunlar vardır (benzerleri Avrupa Birliği'nde ve ABD'de de bulunur): kişisel verilerin korunması kanunu ve fikri ve sınai mülkiyet hakları. Bir kişinin emek vererek hazırladığı ders notu izinsiz olarak herkese açık şekilde gösteriliyorsa onun fikri hakkı ihlal edilmiş olur. Bir kişinin bilgisi rızası olmadan kullanılır, yayılır ya da işlenirse bu da hukuka aykırıdır.

**Örnek: müşteri bilgisi tutan sistem.** Kişisel verilerin korunması kanunu gereği yükümlülükler vardır:

- Kullanıcı sözleşmelerinin ("okudum, onaylıyorum") gösterilmesi, işaretlenmesi ve işaretlenmeden kullanıma izin verilmemesi.
- Kullanıcı talep ederse verilerinin silinmesi; bu, sisteme mutlaka eklenmesi gereken yeni bir gereksinim ve işlevdir.

Bu yükümlülükler yerine getirilmezse yaptırım ve cezalar doğar; bunlar da ekonomik tarafa girdi olur. Kanun yüzünden tasarlanan sistemde, bilginin tutulma biçiminde değişiklik yapmak, belki bir şifreleme cihazı kullanmak gerekebilir. Bu, teknik fizibiliteye ek bir kalem, maliyete ek bir yük ve geliştirme süresine ek süre getirir. Yasal fizibilite yapılarak "böyle yaparsam ne olur, yapmazsam ne olur" incelemesiyle gelen ek yükler (ya da kurtulunan yükler) ortaya konur ve tartılır.

**Patent ve fikri haklar.** Kullanılan bir yöntem, algoritma ya da çözüm başkasının patentiyle korunuyor olabilir. Birinin müzik ya da video üretimini izinsiz kopyalamak ve dağıtmak da hak ihlalidir.

**Lisanslar.** Kullanılan bileşenlerde lisans ödenmesi gereken, özel izinle kullanılabilen şeyler var mı? Varsa bedel bir kez mi ödenecek (bütün sistem için tek seferlik), işlem başına mı, yoksa aylık ya da yıllık abonelikle mi? Bu yükler tartılır ve alternatifler değerlendirilir: başka bir sürüm, açık lisanslı bir seçenek ya da başka bir bileşen.

**İşletmenin anlaşmaları.** İşletmenin imzaladığı anlaşmalara aykırı bir sistem üretilmemelidir. Hocanın uydurduğu örnek: işletme temiz ve yeşil çevreyle ilgili bir anlaşma imzalamışsa belli bir güç tüketiminin üzerinde sunucu kullanamıyor olabilir. Böyle bir anlaşmayı ihlal eden bir yan var mı, bu neye mal oluyor, yasal fizibilitede incelenir.

> **Hocanın vurgusu:** En sık yapılan iki hata, donanım fizibilitesini (teknik fizibilitenin altında) ve yasal fizibiliteyi baştan savma yapmaktır: "bir cep telefonu yaz geç", "hiçbir yasayı ihlal etmemektedir yaz geç". Teknik ve yasal fizibilite, anlatılan çerçevede, "yapılırsa şuna mal olur" sonucunu verecek şekilde yapılmalıdır.

### 6.4 Donanım fizibilitesine dair soru-cevap ve bir vaka

**Soru:** Donanım fizibilitesine örnek verebilir misiniz? Bir yazılım geliştiriyorsak bilgisayardan başka bir donanım aklıma gelmiyor. **Cevap:** Sistemi dizüstü bilgisayarında geliştirdin; peki bu sistem nerede çalışacak, nerede hizmet sunacak? Akıllı telefonlarda çalışan, Instagram benzeri bir fotoğraf beğeni uygulaması düşünelim. Verileri bir yerde tutmak gerekir, yani büyük bir veri depolama ortamına ve büyük olasılıkla bir içerik dağıtım ağına (CDN) ihtiyaç olur; çünkü dünyanın her yerinden sürekli içerik gelir, gider ve kaydedilir. Belki dağıtık yapıda büyük bir veri tabanı, içerik dağıtımı ve yük dengeleme (load balancing) için ayrı sistem yazılımları gerekir. Bugün bin kullanıcı için belli özelliklerde bir uygulama sunucusu yeterlidir, ama yarın bir milyon kullanıcı olursa sunucu gereksinimi ne kadar artar? Sunucuları satın almak mı, bir bulut sağlayıcısından kiralamak mı daha iyidir? Donanımda yalnız geliştirme değil, sistemin 5 ya da 10 yıl gibi öngörülen bütün verimli ömrü için gereken kaynaklar planlanmalıdır.

Hoca bir vaka da anlattı: birkaç yıl önce çok popüler olan, belli saatlerde canlı videolu bilgi yarışması yapan bir mobil uygulama vardı. Az kullanıcıyla başladı ve iyi gidiyordu; büyük ödüller verilmeye başlanınca kullanıcı sayısı bir anda milyonlara çıktı. Ağ altyapısı ve donanım fizibilitesi, büyüme projeksiyonlarıyla düzgün yapılmadığı için sistem çöktü: kullanıcılar cevap gönderemedi, gecikmeler oldu, video kimine ulaştı kimine ulaşmadı.

## 7. Fizibilitenin önemi ve kapsamı

Ders projelerinde bu sorunlar pek hissedilmeyebilir; ama büyüyebilen, son kullanıcıya hizmet veren sistemlerde ön inceleme ve fizibilite aşamalarında alternatiflerin dikkatle değerlendirilmesi ileride baş ağrısını önler. Bir hata tasarımda ya da daha sonraki aşamalarda fark edilirse çok büyük bir geri dönüş yapıp pek çok şeyi değiştirmek gerekir. Hata başa ne kadar yakın görülürse o kadar az sorun yaşanır. Hocanın benzetmesi: kar topuyken içindeki taşı çıkarmak kolaydır; çığ ya da kardan adam olduktan sonra içindeki taşı bulmak zordur.

Fizibilite çalışmaları özellikle gerçek dünya uygulamalarında, son kullanıcıya hizmet veren, yüksek hacim ve trafikli sistemlerde önem kazanır. Bilinen bir problemi çözen basit bir işlem sistemi için bu kadar ağır bir çalışmaya gerek olmayabilir.

Altı fizibilite türünün hepsinin her projede yapılması gerekmez. Kurum içi (in-house) bir işte yasal, sosyal ya da ekonomik fizibilite yapılmayabilir; müşteriye ya da geniş kitleye yönelik işlerde dört-beş türü yapmak gerekebilir. Sözleşmeli işlerde bu çalışmalar daha resmî hâle getirilir. Kısacası her zaman hepsi yapılmaz, ama gerektiğinde gerektiği kadarı mutlaka yapılır. Hoca, dönem projesinde deneyim kazanmak için hepsinin biraz biraz yapılmasını, "bizim projede ekonomik taraf yok" denmemesini tavsiye etti.

## 8. Ekonomik fizibilite ve değerlendirme yöntemleri

Ekonomik fizibilite, bütün fizibilitelerin bir şekilde çıktı sağladığı yerdir; hocanın deyişiyle "dönüp dolaşıp gelinen kürkçü dükkânı"dır. Bütün sistemin maliyetleri ve diğer fizibilitelerden (donanım, sosyal, yasal, zaman) doğan maliyetler bir araya getirilip bir maliyet-fayda analizi, yani bir fiyat-performans karşılaştırması yapılır. Yapılabilirlik etüdünün sonucu bu yüzden doğrudan ekonomik fizibiliteye bağlıdır. Örneğin zaman açısından ekip yetmiyorsa projeye 10 kişi daha eklenerek plan yapılabilir hâle getirilebilir, ama bu 10 kişinin proje boyunca maaşı ekonomik bir yük getirir. Belli sunucuların kullanılması gerekiyorsa bu da bir yüktür; bu yüklerin beklenen kârlılığı nasıl etkileyeceği burada incelenir.

Temel yaklaşım şudur: bugün bir birim yatırım yapılıyor; bu yatırım gelecekte kaç birime dönüşecek, ne kadar fayda sağlanacak? Bunun için 4 değerlendirme yöntemi vardır:

1. Bugünkü değer yöntemi
2. İç verim oranı yöntemi
3. Başa baş noktası yöntemi
4. Geri ödeme süresi yöntemi

### 8.1 Bugünkü değer yöntemi

Slayt (ekrandan, 01:30:00):

- Projenin bütün nakit giriş ve çıkışları bugünkü değere indirilip karşılaştırılır.
- Net nakit girişleri > Yatırım harcamaları?
  - Evet: Proje kabul
  - Hayır: Proje red
- Bugünkü değere indirgemek için iskonto oranı kullanılır.
  - Farklı yöntemleri mevcuttur.
  - En pratiği: piyasadaki ağırlıklı sektörlerin uyguladığı faiz oranlarının ortalaması.
- $Q$ yıl, $i$ iskonto oranı, $V$ indirgenmiş nakit akışı toplamı ise:

$$V = Q_0 \frac{Q_n}{(1+i)^n}$$

> **Ders sonrası not:** Slayttaki formül büyük olasılıkla eksik yazılmıştır. İndirgenmiş nakit akışı toplamı genellikle $V = \sum_{n=0}^{N} \frac{Q_n}{(1+i)^n}$ biçiminde yazılır; $Q_n$, $n$. yıldaki nakit akışıdır ve her yılın akışı $(1+i)^n$ ile bölünerek bugüne indirgenir.

Gelecekteki değerler bugüne çekilir. Hoca bunu döviz kuru üzerinden anlattı: bugün dolar 8 lira iken 5 yıl sonra 15 lira olacağı düşünülüyorsa gelecekteki 15 lira bugünkü 8 liraya "projekte" edilir. Değerler genellikle zamanla arttığı için "indirgeme" kelimesi kullanılır. Bugüne çekilmiş nakit girişleri yatırım harcamalarından büyükse kâr vardır ve proje yapılır; değilse daha çok harcanıp daha az kazanılıyordur ve proje yapılmaz ya da başka bir yoldan yapılmalıdır.

İskonto oranı enflasyon gibi düşünülebilir: her yıl belli bir oranda (%3, %5, %10, %15 gibi) indirgenerek her yılın nakit akışı bugüne çekilir. Hocanın sözlü örneği:

- Bugün 10 lira harcanıyor, iki yıl sonra 20 lira kazanılıyor. Görünüşte 10 lira kâr var.
- Ama iki yıl sonraki 20 lira bugünün 8 lirasına denk geliyorsa, bugüne indirgenince 10 lira harcayıp 8 lira kazanıldığı görülür.
- Yani aslında 2 lira zarar edilmektedir ve bu iş yapılmamalıdır.

Hoca ayrıca "1 liranın bugünkü değeri" tablosunu sözlü olarak anlattı: sabit bir iskonto oranıyla 1 liranın değeri yıllar geçtikçe azalır. Yıllık %1 için değer 100 kuruştan yaklaşık 99, 98, 97, 96 kuruşa iner. Hocanın 9 yıl sonrası için verdiği değerler ve $1/(1+i)^9$ ile hesaplanan değerler (python ile hesaplandı):

| Yıllık oran | Hocanın söylediği | $1/(1+i)^9$ |
|---|---|---|
| %1 | 87 kuruş | 0,914 |
| %2 | 84 kuruş | 0,837 |
| %3 | 77 kuruş | 0,766 |
| %4 | 70 kuruş | 0,703 |
| %5 | 65 kuruş | 0,645 |

<!-- BELİRSİZ: Tablo karede görünmüyor. %2-%5 değerleri 9 yıllık indirgemeyle uyuşuyor; %1 için söylenen 87 kuruş hesapla uyuşmuyor (yaklaşık 91 kuruş olmalı). Altyazıda oranlar "%10, %20, %30, %40" diye de geçiyor, ama bağlamdan bunların %1-%4 olduğu anlaşılıyor. -->

Yorum: %5 oranla 9 yıl sonra kazanılan 1 liranın bugünkü alım gücü 65 kuruştur. Bugün 80 kuruş harcayıp 9 yıl sonra 1 lira kazanmak (bugünkü değeriyle 65 kuruş) yanlıştır; 30 kuruş harcayıp aynı kazancı elde etmek ise iyi bir kârdır.

### 8.2 İç verim oranı yöntemi

Slayt (ekrandan, 01:35:00):

- Paranın zaman değeri ve yatırımın ekonomik ömrü dikkate alınır.
- İVO: Nakit girişleri ile yatırım maliyetini eşitleyen iskonto oranı.
- $T$: yatırımın ömür yılı, $x$: toplam maliyet, $R_t$: $t$ yılındaki net getiri, $d$: iskonto oranı için

$$x = \sum_{t=1}^{T} \frac{R_t}{(1+d)^t}$$

Slaytta toplamın alt sınırı karede kesik görünüyor; hoca $t$'nin 1'den toplam yıla kadar gittiğini söyledi (örneğin 10 yıllık bir yatırım ömrü).

Bu yöntem soruya ters yönden bakar. Bugünkü değer tablosunda farklı oranlarla değerin nasıl azaldığına bakılmıştı; iç verim oranında ise getirilerin bugünkü değerini toplam maliyete eşitleyen iskonto oranı $d$ bulunur. Bu oran beklentinin altındaysa yatırım verimli sayılmaz ve vazgeçilebilir; beklentiyi karşılıyorsa proje kabul edilebilir. Hoca hesabın ayrıntısına girmedi; formülün çözümünü ve örnekleri kaynaklardan incelemeyi önerdi.

> **Ek bilgi (derste anlatılmadı):** Bu denklemin $d$ için kapalı bir çözümü genellikle yoktur; $d$ deneme-yanılma ya da sayısal yöntemlerle (örneğin hesap tablosu programlarının IRR işleviyle) bulunur.

### 8.3 Başa baş noktası yöntemi

Sistem işletmeye alındıktan sonra toplam gelirlerin ve toplam giderlerin eşitlendiği bir nokta vardır. Harcamalar ve kazançlar aynı grafikte çizilir; iki eğrinin (ya da doğrunun) kesiştiği yer **başa baş noktasıdır** ve bu noktadan sonra kâr artmaya başlar. Hocanın anlattığı grafikte yatay eksen üretim hacmi (ya da zaman), düşey eksen maliyet ve hasılattır:

- **Sabit maliyetler** yatay bir doğrudur. Örnekler: her ay ödenen bir patent ya da lisans ücreti (örneğin aylık 100 dolar), bir bulut sağlayıcısına aylık 1000 dolar sunucu gideri, bakım personelinin maaşları.
- **Üretim maliyetleri** (geliştirme ve sonradan yapılan değişiklikler) sıfırdan değil, sabit maliyet düzeyinden başlayarak artar. Artış doğrusal, azalarak ya da artarak olabilir; artarak artması kötüdür.
- **Toplam kazanç** sıfırdan başlayarak artar.

Gider ve gelir eğrilerinin kesiştiği noktada "harcanan ile kazanılan denkleşir"; hocanın deyişiyle sol cepten verilen ile sağ cebe konan eşitlenir. Bu noktadan sonra kâr elde edilir. Önemli olan bu noktanın projenin başlangıcına ne kadar yakın olduğudur: üç ay mı, bir yıl mı, beş yıl mı, on yıl mı? Nokta sıfıra ne kadar yakınsa o kadar çabuk kâra geçilir. Mesafe tatmin ediciyse proje kabul edilir; "8 yıl sonra kâra geçsem ne olur" deniyorsa reddedilir. Karar kriterleri projeden beklenen mali sonuçlara göre değişir.

### 8.4 Geri ödeme süresi yöntemi

Slayt (ekrandan, 01:40:00):

- Gerekli yatırım ve yıllık yarar arası ilişki.
- Yıllık yararın yatırım miktarına bölünmesi ile geri ödeme süresi bulunur.
- Başlangıçtaki nakit yatırımların kaç yılda elde edilebileceğini belirler.

Bir yatırım yapılır ve yıllık yararlar elde edilir; yapılan yatırımın kaç yılda geri kazanılacağına (amorti edileceğine) bakılır ve bu sürenin yeterli olup olmadığı değerlendirilir. Hoca bunu başa baş noktasının yıllara dağıtılmış hâli, "pastanın dilim dilim yapılmış hâli" olarak anlattı.

> **Ders sonrası not:** Slaytta "yıllık yararın yatırım miktarına bölünmesi" yazıyor. Yıl cinsinden geri ödeme süresi büyük olasılıkla tersine, yatırım miktarının yıllık yarara bölünmesiyle bulunur: $\text{geri ödeme süresi} = \frac{\text{yatırım}}{\text{yıllık yarar}}$. Slayttaki oran ise yıllık getiri oranını verir.

Hoca, kendilerinin genellikle başa baş noktasını tercih ettiklerini, ama dört yöntemden herhangi birinin seçilebileceğini söyledi. Bazen kâra çabuk geçmek önemlidir (süre), bazen toplamda çok kâr elde etmek; yönteme bu amaca göre karar verilir.

Ekonomik fizibiliteden sonra fizibilite alternatiflerinin nasıl karşılaştırılıp değerlendirileceği ve zaman fizibilitesinin ayrıntıları sonraki derse bırakıldı.

## Örnek Sorular

**Soru 1** (derste sözlü, 01:18:48): Bir yazılım geliştiriyorsak, donanım fizibilitesinde geliştirme bilgisayarından başka hangi donanımlar düşünülmelidir? Örnek veriniz.

> **Çözüm (derste verilen cevap):** Sistemin hizmet vereceği ve bütün işletme ömrü boyunca çalışacağı ortam düşünülmelidir. Instagram benzeri bir mobil fotoğraf uygulamasında verileri tutacak büyük bir depolama ortamı, büyük olasılıkla bir içerik dağıtım ağı (CDN), dağıtık bir veri tabanı, yük dengeleme için sistem yazılımları ve uygulama sunucuları gerekir. Kullanıcı sayısı bin kişiden bir milyona çıkarsa sunucu ihtiyacının ne kadar artacağı, sunucuların satın alınması ile bulut sağlayıcısından kiralanması karşılaştırılmalı ve 5-10 yıllık işletme ömrü için kaynak planlanmalıdır.

**Soru 2** (derste sözlü, 01:31:45): Bugün 10 lira harcanıp iki yıl sonra 20 lira kazanılacaksa ve iki yıl sonraki 20 lira bugünün 8 lirasına denk geliyorsa bu yatırım yapılmalı mıdır?

> **Çözüm (derste verilen cevap):** Bugünkü değer yöntemine göre gelecekteki kazanç bugüne indirgenir: 20 lira bugünün 8 lirasıdır. Harcama 10 lira, indirgenmiş kazanç 8 lira olduğundan $8 - 10 = -2$ lira, yani 2 lira zarar vardır. Net nakit girişleri yatırım harcamasından küçük olduğu için proje reddedilir.

**Soru 3** (derste sözlü, 01:33:34): Yıllık %5 değer kaybıyla 9 yıl sonra kazanılacak 1 liranın bugünkü değeri yaklaşık kaç kuruştur? Bugün 80 kuruş harcayıp 9 yıl sonra 1 lira kazanmak mantıklı mıdır?

> **Çözüm (derste verilen cevap, sayı python ile doğrulandı):** $1/(1{,}05)^9 \approx 0{,}645$, yani yaklaşık 65 kuruş. Bugün 80 kuruş harcayıp bugünkü değeri 65 kuruş olan bir kazanç elde etmek zarardır; 30 kuruş harcanıyorsa kârlıdır.

## Dersin Toparlaması

Ders, önceki haftadan kalan süreç modelleriyle başladı: sıralı ve geri dönüşsüz waterfall, geri dönüşe izin veren iteratif waterfall, prototipten son ürüne evrilen model oluşturma, risk odaklı spiral model, fazları ve iş akışlarını bir matriste birleştiren Unified Process, dört değer ve on iki pratiğe dayanan aykırı programlama ve günümüzde en yaygın olan çevik süreçler (Scrum). Ardından sistem geliştirme yaşam döngüsünün ilk adımına geçildi. Ön inceleme, projenin kabaca "tamam mı, devam mı" sorusunu cevaplar ve kapsam dokümanı (Project Charter) ile sonuçlanır. Fizibilite çalışması ise projenin olabilirliğini alternatifleriyle araştırır ve genel hatlarıyla proje planı ve tahmini bütçe üretir.

Altı fizibilite türünden teknik (yazılım, donanım, iletişim), sosyal (operasyonel), yönetim, yasal ve ekonomik fizibilite işlendi. Hoca, donanım fizibilitesinin bütün işletme ömrünü ve büyümeyi kapsaması, yasal fizibilitenin de kanunların getirdiği yükümlülükleri ve maliyetleri tartması gerektiğini özellikle vurguladı. Ekonomik fizibilitede dört değerlendirme yöntemi (bugünkü değer, iç verim oranı, başa baş noktası, geri ödeme süresi) tanıtıldı. Sonraki derste zaman fizibilitesi bir vaka çalışmasıyla işlenecek ve fizibilite alternatiflerinin tablo ve matrislerle nasıl karşılaştırılıp değerlendirileceği görülecek; ardından analiz modeline geçilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
