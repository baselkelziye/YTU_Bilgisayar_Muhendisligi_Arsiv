# Ders 7 Genişletilmiş Notu: Kalite Ölçütleri, Test Yönetimi, Risk ve Konfigürasyon Yönetimi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Yazılım Ölçümünün Tekrarı
- 2. Yazılım Kalite Ölçütleri ve Kalite Modelleri
- 3. Ölçme, Ölçüt ve Ölçüm
- 4. Ölçme İlkeleri
- 5. Nesneye Yönelik Ölçütler: CK Ölçütleri
- 6. Ölçütlerin Akademik Önemi
- 7. Test Yönetimi
- 8. Yazılım Risk Yönetimi
- 9. Yazılım Konfigürasyon Yönetimi
- 10. Yazılım Bakımı ve Bakım Yapılabilirlik
- Örnek Sorular
- Dersin Toparlaması

## 1. Yazılım Ölçümünün Tekrarı

Dersin ilk bölümünde önceki haftalarda başlanan "Kalite Ölçüm ve Değerlendirmeleri" konusu toparlandı. Slaytın bölüm hedefleri yazılım kalite ölçütlerinin incelenmesi, yazılım ölçütlerinin test adımlarında kullanımının anlaşılması ve kalite güvenirliğinin kestirimi ile modellerinin tanınmasıdır (ekrandan, 00:15:00). Hoca, ölçümün yazılım mühendisleri için anlamını şöyle özetledi: ölçüm, yaptıkları işin kalitesini izlemelerini ve bir sonraki adımda hem maliyet hem de iş gücü için yeni kestirimler yapmalarını sağlar.

### 1.1 Halstead ölçütü

İlk hatırlatılan ölçüt Halstead ölçütüdür. Bu ölçütte programdaki işleç ve işlenen sayıları sayılır ve bunlardan program gücü hesaplanır. Ayrıntılı formüller önceki derste işlendiği için bu derste yalnız ana fikir hatırlatıldı.

### 1.2 McCabe döngüsel karmaşıklığı

İkinci ölçüt McCabe'in döngüsel karmaşıklığıdır (cyclomatic complexity). Bu ölçütte akış grafı kullanılır: her kontrol deyimi bir düğüm, düğümleri birleştiren akışlar birer kenar olarak çizilir. Düğüm ve kenar sayılarından ya da graf çizildikten sonra kapalı bölgeler sayılarak modüldeki temel yol sayısı bulunur. Bu sayı, programın akabileceği kaç farklı yol olduğunu gösterir.

Her temel yolun anlamı şudur: o yolun sınanması için ayrı bir veri grubu gerekir ve bu veri grubu test durumu (test case) olarak karşımıza çıkar. Yazılıma dışarıdan bakıldığında da bu yolların her birine sapılmasını sağlayan farklı senaryolar vardır; kara kutu testinde bu senaryolar kurulup değer verilir. Dolayısıyla McCabe ölçütü, bir algoritmada kaç temel yol olduğunu ve en az kaç test durumu gerektiğini bulmak için kullanılır.

Slaytta McCabe ölçüsünün ek bir kullanımı da yazılıydı (ekrandan, 00:25:00):

- McCabe ölçüsü en yüksek modül büyüklüğünü saptamakta da kullanılabilir.
- Çok sayıda programlama projesinden derlenen bilgilere göre modül büyüklüğünün en çok $V(G) = 10$ olması gerektiği belirlenmiştir.
- Döngü karmaşıklığı bu sayıyı aşarsa modülün sınanması büyük ölçüde zorlaşır.

### 1.3 Büyüklük ölçütü

Slaytta olmasa da hoca büyüklük ölçütünü de hatırlattı. Yazılımın ne büyüklükte olduğunu bulmanın en basit yolu satır ya da komut saymaktır. Bu ölçütün haklı eleştirileri vardır: çok objektif değildir; bir program daha az komutla yazılmış olabilir ama daha çok düşünce emeği gerektirmiş olabilir. Bir diğer sorun programlama dilleri arasındaki farktır; bu sorun dönüşüm tabloları oluşturularak giderilmiştir.

### 1.4 Fonksiyon noktası

Doğrudan sayım yerine dolaylı ölçüm de yapılabilir: farklı ölçümler yapılır ve bunların birleşiminden tek bir sayısal değer bulunur. Fonksiyon noktası (Function Point) böyle bir ölçüttür; dosya sayısı, girdi sayısı, çıktı sayısı ve sorgu sayısı gibi değerler kullanılır. Ticari yazılımlarda girdi, çıktı, olabildiğince çok bilgi saklama ve saklanan bilginin raporlanması ağır bastığı için fonksiyon noktasının çıkış noktası ticari yazılımlar olmuştur. Function Point Users Group, ölçütün yazılım teknolojisindeki gelişmelere ayak uydurması için çalışmalar yapmaktadır; ticari yazılımlara uygun olsa da gerçek zamanlı uygulamalarda daha iyi çalışması için de çaba harcanmıştır.

### 1.5 Yazılım güvenirliği ve güvenirlik modelleri

Kalite özelliklerinden biri de sonucun ne kadar güvenilir olduğudur. Bunun için istatistiksel modeller kurulur: yazılımın ne kadar süredir hatasız çalıştığı, toplam hata sayısı, hangi güvenirlik düzeyinde çalıştığı gibi değerler elde edilir. Güvenirlik modelleri istatistiksel verilere dayanan analizlerdir.

Slaytta güvenirlik modellerinin nasıl değerlendirileceği yazılıydı (ekrandan, 00:30:00). Bir yazılım birden fazla modele göre test edilmeli ve sonuçlar karşılaştırılmalıdır. Model değerlendirilirken şu sorulara cevap aranır:

- Modele göre yazılım ne kadar geçerlidir?
- Modeli kullanarak yazılımın güvenirliğinin ölçümü ne kadar kolaydır?
- Modeli kullanmak için yazılımın ne kadarına ihtiyaç vardır?
- Model yazılım ölçümünde kullanmak için kolay ve anlaşılır mı?
- Model dış etkenlerden etkileniyor mu?

## 2. Yazılım Kalite Ölçütleri ve Kalite Modelleri

Hoca ardından başka bir slayt dosyasına geçerek kalite ölçütlerini sayısal olarak, yani kalite metrikleri olarak ele aldı. Farklı kalite özelliklerini farklı biçimlerde ölçmeye çalışan çeşitli yaklaşımlar vardır. Önceki haftalarda görülen CK (Chidamber-Kemerer) metrikleri nesneye yönelik uygulamalarda kaliteye ilişkin bilgi verir; kalite modeli olarak ise şimdiye kadar yalnız McCall modeli görülmüştü.

### 2.1 Üç yaklaşımın karşılaştırılması

Slayta göre nicel kalite ölçütleri farklı kişilerce farklı biçimlerde öbeklenmekte ve farklı dallara ayrılmaktadır (ekrandan, 00:35:00):

| Yaklaşım | Gruplar ve ölçütler (slayttaki haliyle) |
|---|---|
| ISO 9126 | İşlevsellik (uygunluk, doğruluk, güvenlik, ...), Güvenilirlik (olgunluk, hata bağışıklığı, ...), Kullanılabilirlik, Verimlilik/Etkinlik, Bakım kolaylığı, Taşınabilirlik |
| McCall ve arkadaşları | İşlevsel ölçütler: doğruluk, güvenilirlik, bütünlük, kullanılabilirlik, verimlilik. Değiştirilme ölçütleri: bakım kolaylığı, esneklik, sınanabilirlik. Taşınma ölçütleri: taşınabilirlik, yeniden kullanılabilirlik, birlikte çalışabilirlik |
| McConnell | İç kalite ölçütleri, dış kalite ölçütleri |

McCall modeli bir üçgen üzerinde kullanıcının (çalıştıranın), bakım yapanın ve taşıyanın bakış açılarıyla hangi özelliklerin önemli olduğunu ve bunların nasıl hesaplandığını gösteriyordu; metriklerle kalite faktörleri arasında ilişki kuruluyordu. Hocaya göre McCall ile ISO 9126 arasında kaliteyi ölçecek metrikler açısından çok yakın bir ilişki vardır. ISO 9126 özellikleri sınıflara ayırmış, kaliteyi belirleyen özellikleri genel olarak sıralamış ve her sınıftaki faktörü farklı metriklerle ilişkilendirmiştir.

Hocanın vardığı sonuç şudur: ISO 9126, McCall ve McConnell aslında çok farklı şeyleri ölçmez, yalnız sınıflandırmaları farklıdır. McCall üç bakış açısıyla sınıflama yapıp bunları metriklerle ilişkilendirerek daha karmaşık ve kapsamlı bir model kurar. Metrik değerlerini farklı ağırlık katsayılarıyla çarpıp toplayarak bir kalite faktörü formülü verir.

> **Ek bilgi (derste anlatılmadı):** McCall modelindeki bu formül genellikle $F_q = c_1 m_1 + c_2 m_2 + \dots + c_n m_n$ biçiminde yazılır. Burada $F_q$ kalite faktörü, $m_i$ o faktörü etkileyen metrikler, $c_i$ ise ağırlık katsayılarıdır. Derste formül yalnız sözlü anlatıldı; bu gösterim kaynaklardaki yaygın biçimdir.

McConnell ise McCall kadar ayrıntılı bir sınıflama yapmaz. Kalite ölçütlerini iki gruba ayırır: yazılımı geliştirenler için önemli olan ve onların doğrudan müdahale edebileceği iç ölçütler ile yazılıma dışarıdan bakan kullanıcıların isteyeceği dış ölçütler.

### 2.2 Dış kalite ölçütleri

Dış kalite ölçütleri yazılımı kullananları ilgilendiren ölçütlerdir. Slayttaki tanımlar şöyledir (ekrandan, 01:10:00):

- **Doğruluk (Correctness):** Yazılımın hata içermemesi, gereksinimlerde belirtildiği şekilde çalışması.
- **Etkinlik (Efficiency):** Bellek ve işlemci gibi sistem kaynaklarının en az oranda kullanımı.
- **Güvenilirlik (Reliability):** Sistemin her koşulda istenildiği gibi çalışması, hatalar arasındaki ortalama zaman aralığının (MTBF) yüksek olması.
- **Güvenlik (Security):** İzinsiz ve yetkisiz işlemlerin mümkün olmaması.
- **Bütünlük (Integrity):** Veriler ve işlemler arasındaki tutarlılığın korunması.
- **Uyarlanabilirlik (Adaptability):** Sistemin değişik uygulamalar veya ortamlarda kullanılabilmesi için mümkün olduğunca az değişiklik gerektirmesi.
- **Hassaslık (Accuracy):** Sistemin kendisinden beklenen işi mümkün olduğunca iyi yapabilmesi.
- **Sağlamlık (Robustness):** Aykırı girişlere veya güç çalışma ortamlarına karşı sistemin çalışmayı sürdürebilmesi.
- **Kullanılabilirlik (Usability):** Yazılımın kolay kullanılabilir olması.

Hoca güvenilirlik üzerinde biraz durdu. MTBF, yani hatalar arasındaki ortalama zaman aralığı güvenirlikte önemli bir kavramdır. Ayrıca hataların sınıflamasına bakılır: ortaya çıkan hatalar kritik ya da büyük boyutta değilse bu iyi bir işarettir. Bütünlüğün özellikle veri tabanlarında en önemli özelliklerden biri olduğunu da vurguladı. Slaytın son maddesine göre bu ölçütler örtüşebilir; bazı durumlarda birbirinden daha iyi ya da daha zor ayrılabilir.

### 2.3 İç kalite ölçütleri

İç kalite ölçütleri yazılımı geliştirenleri ilgilendirir (ekrandan, 00:40:00):

- **Yeniden kullanılabilirlik (Reusability):** Sistemin parçalarının başka sistemlerde kullanılabilmesinin kolaylığı.
- **Bakım kolaylığı (Maintainability):** Yazılıma yeni yetenekler eklemenin, hataları gidermenin veya başarımı artırmanın mümkün olduğunca kolay olması.
- **Esneklik (Flexibility):** Yazılımın orijinal olarak tasarlandığı uygulamanın dışında çalışabilmesi için gereken değişikliklerin olabildiğince az olması.
- **Taşınabilirlik (Portability):** Yazılımın farklı donanım ve işletim sistemleri gibi değişik ortamlara kolayca aktarılabilmesi.
- **Okunabilirlik (Readability):** Kaynak kodun incelenmesinin kolay olması. Hoca bunu kaynak kodun programlama dili standartlarına uygun hazırlanmış ve izlenebilir olması diye açıkladı.
- **Anlaşılabilirlik (Understandability):** Yazılımın sistem, bileşen ve kod düzeylerinde anlaşılabilirliğinin kolay olması. Okunabilirlik yalnız kod düzeyinde anlaşılabilirliği sağlar.
- **Sınanabilirlik (Testability):** Sistemin istenen gereksinimleri karşılayıp karşılamadığının bileşen ve tüm sistem çapında sınanabilmesi.

Hoca bu ölçütlerin de örtüştüğünü hatırlattı: sınanabilirlik izlenebilirlik, anlaşılabilirlik ve okunabilirlikle ilişkilidir; sınanabilirlik ile bakım yapılabilirlik de birbiriyle örtüşür.

## 3. Ölçme, Ölçüt ve Ölçüm

Hoca, bilinen kavramlar olsa da tekrar etmekte fayda gördüğü üç tanımı slayttan verdi (ekrandan, 00:45:00):

- **Ölçme (Measuring):** Somut veya soyut bir varlığın sahip olduğu bir özelliğini sayısal veya derecelendirilmiş bir veri olarak ifade etmek. Slayttaki örnek "İlk ara sınav çok zordu" cümlesidir; burada derecelendirilmiş bir değer vardır.
- **Ölçüt (Metric):** Varlığın ölçülecek özelliğini ölçme biçimi. Sıcaklık ölçütü olarak santigrat ve Fahrenhayt verilir.
- **Ölçüm (Measurement):** Belli bir ölçüte göre yapılan ölçme eyleminin sonucu.

Hoca kavramları yazılım üzerinden örnekledi. Yazılımın büyüklüğünü ölçerken ölçüt olarak KLOC (bin kod satırı) kullanılabilir. Bir projede satırlar sayılıp 8000 satır bulunduysa yazılım 8 KLOC büyüklüğündedir; burada ölçüt KLOC, 8 KLOC ise ölçüm sonucudur. Benzer biçimde bir veri tabanı projesi için fonksiyon noktası hesaplanıp bir değer bulunduğunda (hoca 3,2 fonksiyon noktası gibi bir değer söyledi) birim, yani ölçüt fonksiyon noktasıdır; bulunan değer ölçüm sonucudur. Değerlerin sayılıp üzerinde hesap yapılması da ölçme işlemidir.

> **Ders sonrası not:** Hocanın söylediği 3,2 değeri kavramı göstermek için verilmiş varsayımsal bir sayıdır. Gerçek projelerde fonksiyon noktası değerleri büyük olasılıkla onlarca ya da yüzlerce düzeyindedir; bir veri tabanı projesi için 3,2 gerçekçi bir büyüklük değildir.

Slayta göre neden ölçtüğümüzün cevabı, gerçek dünya ile ilgili, işimize yarayacak anlamlı sonuçlar elde etmektir. Hoca yazılımı ölçmenin zor olduğunu, çünkü yazılımın karmaşık ve ölçütlerin sayısal yapısının kolay olmadığını söyledi. Yine de şu amaçlarla ölçeriz:

- Ne kadar iyi bir ürün ortaya çıkardığımızı anlamak.
- Ne kadar zaman ve para harcayacağımızı ya da şimdiye kadar harcadığımızı anlamak.
- Ne büyüklükte ve ne kadar karmaşık bir iş yaptığımızı görmek.

> **Hocanın vurgusu:** Ölçemediğimiz her ilerlemeyi daha sonra yönetmemiz zor olacaktır.

## 4. Ölçme İlkeleri

Bir yazılım üzerinde ölçme yapmaya karar verildiğinde izlenecek adımlar slaytta şöyleydi (ekrandan, 00:50:00):

1. **Tanımlama (Formulation):** Ölçütler, ölçülecek yazılıma uygun bir biçimde tanımlanır. Bunun için kullanılan yaklaşım (yapısal programlama, nesneye yönelik programlama vb.) ve yazılımın türü (gerçek zamanlı, gömülü, uygulama vb.) dikkate alınır. Önce neyi ölçmek istediğimize, sonra bunu hangi ölçütle ölçeceğimize karar veririz.
2. **Toplama (Collection):** Tarif edilen ölçütlerin gerektirdiği veriler elde edilir. Örneğin fonksiyon noktası seçildiyse girdi, çıktı, sorgu ve dosya sayıları gidilip sayılır.
3. **Hesaplama (Analysis):** Ölçütler hesaplanır, yani ölçümler elde edilir. Matematiksel araçlar kullanılabilir ve hesaplama olabildiğince otomatik yapılmalıdır. Her ölçüt dolaylı değildir; doğrudan ölçme yapıldıysa bu adım atlanabilir.
4. **Yorumlama (Interpretation):** Elde edilen ölçüm değerlerinden yararlı anlamlar çıkarılır. Örneğin bulunan fonksiyon noktası değerinin küçük, orta ya da büyük yazılım olarak tanımlanan aralıklardan hangisine düştüğüne bakılır; ekibin şimdiye kadar geliştirdiği yazılımlardan büyük mü küçük mü olduğu, ortalamaya düşüp düşmediği değerlendirilir.
5. **Geri besleme/Kullanma (Feedback):** Çıkarılan sonuçlar yazılım ekibine bildirilir ve ekip sonuçları kullanarak yazılımı iyileştirir.

Hoca geri beslemeyi McCabe örneğiyle açıkladı. Bir hesaplamada döngüsel karmaşıklık 11 ya da 12 çıktıysa ve modüllerin birçoğu 10'un üzerindeyse, ekibe modülleri bölerek karmaşıklığı azaltmaları, böylece daha iyi sonuç alacakları söylenebilir. Bu, bölüm 1.2'deki $V(G) = 10$ üst sınırıyla tutarlıdır.

## 5. Nesneye Yönelik Ölçütler: CK Ölçütleri

Hoca nesneye yönelik yaklaşımda analiz ile tasarım arasındaki geçişin kesintisiz olduğunu vurguladı. Yapısal yaklaşımda gereksinim analizinde veri akış diyagramları çizilir, tasarımda bunlar yapı diyagramlarına aktarılır. Nesneye yönelik yaklaşımda ise sınıflar ve aralarındaki ilişkiler belirlenip geliştirilir; ardışıl (sequence) diyagramlar daha analiz sırasında çizilmeye başlanır. Bu süreklilik nedeniyle aynı ölçütler hem çözümlemede hem kodlama aşamasında kullanılabilir.

Nesneye yönelik yaklaşımda en çok kullanılan ölçüt grubu olduğu için CK ölçüt kümesinin altı ölçütüne yeniden bakıldı; uyum eksikliği (Lack of Cohesion) gibi değerler önceki derste işlenmişti. Slayttaki WMC örneği şöyledir (ekrandan, 00:55:00):

- **WMC:** C1 sınıfının M1...Mn metotlarının karmaşıklıkları c1...cn'dir (sınıfın WMC değeri bu karmaşıklıklardan elde edilir).
- **Eleştiriler:** Metot karmaşıklığı neye göre belirlenecek? Belirlemedeki öznellik güçlü yön mü, zayıf yön mü?
- **Ölçütün rehberliği:** Bir sınıfın karmaşıklığını belirler. Çok sayıda metodu olan bir sınıf çok fazla sorumluluk yüklenmiştir ve dağıtılması uygun olabilir. Yüksek uyumun olup olmadığına tekrar bakılmalıdır. Böyle bir sınıf uygulamaya özeldir ve yeniden kullanılabilirliği düşüktür.

> **Ek bilgi (derste anlatılmadı):** WMC (Weighted Methods per Class) genellikle $WMC = \sum_{i=1}^{n} c_i$ olarak tanımlanır. Tüm metot karmaşıklıkları 1 alınırsa WMC sınıftaki metot sayısına eşit olur.

Hoca uygulamalarda başka nesneye yönelik metrik grupları da bulunduğunu belirtti. <!-- BELİRSİZ: altyazıda "moon metriği" geçiyor; büyük olasılıkla MOOD metrik kümesi kastediliyor. -->

## 6. Ölçütlerin Akademik Önemi

Aradan sonra hoca kalite ölçütleri konusunun neden ayrıca önemli olduğunu anlattı. Yazılım mühendisliğindeki ilk akademik araştırmalar ölçütler üzerine yapılmıştır; çünkü sayma ve hesaplama işlemleri içerdiği için mühendislik çalışmalarına en yakın konudur. Daha sonra yazılım ölçüm sonuçlarını maliyet tahmininde ve maliyet analizlerinde kullanmak için yapay zeka tekniklerinden, örneğin yapay sinir ağlarından yararlanan araştırmalar yapılmıştır. Metriklerle ilişkili test sayısı ve testteki hata sayısı gibi güvenirlik konuları da akademik ortamda çok çalışılan konular arasındadır.

## 7. Test Yönetimi

### 7.1 Test yönetiminin adımları ve test spesifikasyonu

Test yönetiminin adımları hatırlatıldı: test metodolojisi ortaya konur, test planı yapılır, test tasarımı hazırlanır ve test gerçekleştirilir. Aynı dönemde testin gerçekleşme raporu ve sonuç raporu oluşturulur.

Slayta göre test kapsamındaki işlemler planlama, tasarım ve gerçekleştirme adımlarıyla yürütülür. Yazılım testlerini tanımlamak, planlamak, düzenlemek ve belgelemek için **test spesifikasyonu** adı verilen bir belge düzenlenir. Bu belge genel hatlarıyla şunları içerir (ekrandan, 01:25:00):

- **Test planları:** test şekilleri, zamanlama, gider, ortam ve kaynaklar.
- **Test senaryoları.**
- **Test işlemleri:** her testin tanımlanması (bütünleme biçimi, amacı ve test edilen modüller, özel araç ve teknikler, gideri, test programı verisi) ve beklenen sonuçlar.
- **Gerçek test sonuçları.**
- **Referans.**
- **Ekler.**

Hoca bunları kısaca açıkladı: planda hangi tür testlerin yapılacağı, zaman planı, gider ve kullanılacak ortam ve kaynaklar belirlenir. Senaryolar test tasarımında yapılan işe karşılık gelir: testin nasıl tasarlandığı ve test verisinin nasıl hazırlanacağı. Test işlemlerinde testin hedefi, nasıl bir bütünlük testi kurulduğu, hangi modüllerin hangi tekniklerle test edildiği, kullanılan test verisi ve testten beklenen sonuçlar yazılır. Test yönetimi için test belgesinin nasıl hazırlanacağını anlatan bir IEEE standardı vardır. <!-- BELİRSİZ: standart numarası yalnız slayt önizlemesinde küçük olarak görünüyor; "(829-1998) IEEE Standard for Software Test Doc." okunuyor (ekrandan, 01:25:00). -->

### 7.2 Test spesifikasyonu geliştirme adımları

Test spesifikasyonu yazılım konfigürasyonuna giren belgelerden biridir. Slayttaki "Şekil 7.2. Test Spesifikasyonu geliştirme adımları" şu akışı gösterir (ekrandan, 01:30:00):

```text
Test Spesifikasyonu yaz -> Test Spesifikasyonu incele -> İncelemeye Dayalı Düzeltme -> Baseline
        ^                                                       |
        +------------------- (geri dönüş) ---------------------+
```

Belge yazılır, incelenir, gerekirse incelemeye dayalı düzeltilir; bu döngü tamamlandığında hangi aşamada yapıldıysa o aşamanın baseline'ı olarak tanımlanır. Baseline kavramı konfigürasyon yönetiminde ayrıca ele alınacak bir yapıdır.

### 7.3 Test planı

Önceki hafta işlenen test planının içeriği tekrar sayıldı:

- Test stratejisi ve test edilecek öğeler.
- Doğrulama yöntemleri.
- Testlerin tamamlanma kriterleri (testin bittiği nereden anlaşılacak).
- Hata ve test sonuç raporlama.
- Test sorumlulukları (testten kim sorumlu, testi kim gerçekleştirdi).
- Test ortamı.
- Eleman ve eğitim ihtiyacı.
- Test takvimi: proje takvimi gibi bir Gantt şemasıyla gösterilir.
- Risk yönetimi.
- Testin çıktıları.

Hoca risk yönetimini burada açtı: test planı normal koşullarda ilerleyecek biçimde hazırlanır, ama test sırasında riskler ortaya çıkabilir; bu risklerin tarif edilmesi gerekir (bölüm 8). Plan her başlık için çok ayrıntılı olmak zorunda değildir, ama bu yapı yaklaşık olarak kurulmalıdır.

### 7.4 Test senaryosu belgesi

Gerçekleştirilecek her test için test verisinin hangi senaryoya göre hazırlandığını gösteren bir test senaryosu belgesi oluşturulur. Belgenin alanları şunlardır:

- Test senaryosunun adı ve kimliği.
- Senaryonun yazarı ve tarihi.
- İlgili gereksinim ya da (iç test ise) testin amacı; örneğin algoritmadaki hangi yolun denendiği.
- Ön koşul ve varsayımlar.
- Test girdileri.
- Test senaryosu adımları.
- Beklenen sonuçlar.

Hocanın örneği bir öğrenci işleri uygulamasıdır: senaryonun adı "üniversiteye ilk gelen öğrencilerin giriş bilgilerinin alındığı uygulamanın kullanıcı testi" olabilir. Bu senaryo, gereksinim analizindeki use case'lerden birinin test edilmesidir. Belge kaydedilir ve test spesifikasyonunun bir elemanı olarak yazılım konfigürasyonuna yerleştirilir. Böylece test spesifikasyonunun içindeki iki belgeye (test planı ve test senaryosu) örnek verilmiş oldu.

### 7.5 Test çalışma ekibi yapısı

Slayttaki "7.1.3 Test Çalışma Ekibi Yapısı" maddeleri şöyledir (ekrandan, 01:35:00):

- Yazılımın sınanması sürecinde, sınamada bağımsızlık özelliğinin sağlanması için yazılımın sınanmasından sorumlu olan kişiler yazılımı tasarlayan ve oluşturan gruptan olmamalıdır.
- Test ekibinin görevi, planlarda belirtilen testler için gerekli test hazırlıklarını yapmak, testleri yürütmek, testlerde bulunan hataları yazılımcıya bildirmek, izlemek ve test sonuçlarını raporlamaktır.
- İyi bir testçi ne zaman mükemmele ulaşılamayacağını ve iyinin yeterli olacağını bilir. Her yazılım projesindeki optimum test miktarı farklıdır (Şekil 7.3).

Hoca, sektörde birçok kurumda ayrı bir test ekibi bulunduğunu ve sektörde bu alana ciddi bir ihtiyaç olduğunu anlattı. Optimum test miktarı da çok araştırılan bir konudur, çünkü sayısal işlere dayanır. Kaçırılan hata (bug) sayısı mutlaka sıfırdan büyük olacaktır, ama en aza indirilmesi hedeflenir; öte yandan test maliyetinin de çok yükselmemesi istenir. Bu iki eğrinin kesiştiği nokta optimum test miktarıdır. Bu noktayı tahmin etmek için yapay zeka yöntemlerinden yararlanan araştırmalar da vardır.

### 7.6 Yaşam döngüsü içinde test

Test etkinlikleri yalnız yaşam döngüsünün sonunda yer almaz:

- **Planlama:** yukarıdan bakılarak sistem test planı ve kalite planı oluşturulur.
- **Gereksinim analizi:** alt sistemlerin test planları hazırlanır; use case senaryoları belirlenirken bir yandan da onların test senaryoları oluşturulmaya başlanır.
- **Tasarım:** modüllerin test planları ve test tanımları yapılır.
- **Gerçekleme:** birim testi ve bütünlük testi yapılır, ardından sistem testi uygulanır.

## 8. Yazılım Risk Yönetimi

### 8.1 Riskle uğraşma taktikleri

Slayttaki taktikler şunlardır (ekrandan, 01:40:00):

- **Sonradan (Reactive):** Risk gerçekleşince çaresine bakmak.
- **Önceden (Proactive):** Riskleri daha gerçekleşmeden önlemeye çalışmak.
- Derste proaktif yaklaşım işlendi.

Hoca farkı şöyle açıkladı: reaktif yaklaşımda baştan bir "B planı" yapılır ve risk ortaya çıktığında bu plan uygulanır. Proaktif yaklaşımda ise risk maddeleri belirlenir ve problemin ortaya çıkabileceği ortamın oluşup oluşmadığı sürekli izlenerek riskin gerçekleşmesi önlenmeye çalışılır.

### 8.2 Riskin tanımı

Riskin tanımında üç kavram vardır:

- **Olasılık:** Belirli bir risk ortaya çıkabilir veya çıkmayabilir; hiçbir risk %100 olasılıkla ortaya çıkacak diye bir şey yoktur. Olasılık %100 olsaydı problem zaten şu an karşımızda olurdu ve reaktif duruma geçilirdi.
- **Kayıp:** Risk ortaya çıktığında istenmeyen sonuçlar ve kayıplar doğurur. Örneğin test için yapılan planlara ne kadar zarar vereceği değerlendirilir.
- **Gelecek:** Slaytta yazmayan üçüncü kavramdır. Problem şu an yoktur; ne kadar sonra ortaya çıkabileceğine dair geleceğe yönelik tahminler yapılır.

Slayta göre genel risk çeşitleri proje riskleri, teknik riskler ve iş riskleridir; farklı risk sınıflandırmaları ve risk işleme önerileri için SEI, ISO, ANSI, makaleler ve kitaplara bakılabilir.

### 8.3 Pressman'ın risk sınıflaması

Hoca, Roger Pressman'ın Software Engineering kitabının eski baskılarındaki ayrıntılı sınıflamayı aktardı:

- **Müşteriyle ilişkili riskler:** Müşteri birlikte çalışıyor mu, verilenleri kontrol ediyor mu, ekibin içinde yer alıyor mu?
- **Süreçle ilişkili riskler:** Seçilen süreç modeli ilk kez mi kullanılıyor, uygulamaya uygun mu? Çevik bir süreçte çevikliğin özelliğinden, şelale modelinde ise o modelden kaynaklanan farklı riskler olabilir.
- **Yazılım geliştirme ortamıyla ilişkili riskler.**
- **Teknik riskler:** donanım ve altyapıyla ilişkili riskler; örneğin son teknoloji bir geliştirme ortamı ya da daha önce kullanılmamış bir CASE aracı problem yaratabilir.
- **Personelle ilişkili riskler:** Hocaya göre bu alanın en önemli ve tek gerçek kaynağı insandır. Test için örnekler: test ekibinin en önemli üyesinin işten ayrılması, test ekibiyle geliştirme ekibinin koordineli çalışamaması.
- **İşletmecilik riskleri:** Bu yazılım şimdiye kadar geliştirilenlerden farklı mı? Şirketin hayatta kalma nedeni mi olacak? Ürüne talep olacak mı, pazarlama ekibi satış taktiğini biliyor mu?
- **Olağanüstü durum riskleri:** Yangın, sel, deprem gibi tüm işleri etkileyebilecek durumlar. Bunlar olasılığı düşük ama gerçekleştiğinde kaybı yüksek risklerdir.

### 8.4 Risk tablosu

Riskler belirlendikten sonra risk tablosu oluşturulur. Slayttaki adımlar şöyledir (ekrandan, 01:50:00):

1. Tüm ekip veya risk işleme ekibinin tüm üyeleri olası riskleri adlandırsın.
2. Risklerin çeşitlerini belirleyin (proje, teknik, iş).
3. Herkes kendi uzmanı olduğu risk alanında riskleri alt türlere ayırsın. Örnek, teknik: planlanandan daha düşük yeniden kullanım, kullanılan gereçlerde deneyimsizlik vb.
4. Risklerin gerçekleşme olasılıklarını belirleyin: düşük, orta, yüksek gibi kategoriler.
5. Risklerin etkilerinin büyüklüğünü değerlendirin.
6. Bu bilgilerden bir tablo yapın: ID, ad, çeşit, olasılık, etki. Listeyi bir yerden sonra kesin (düşük olasılık ve etkileri atın).
7. Ele alacağınız riskler için risk bilgi sayfaları oluşturun. Bu sayfa risk hakkında bilgiler ve önleme yollarını içersin.

Hoca olasılığın yüzde olarak (%10, %30 gibi) ya da düşük, orta, yüksek kategorileriyle verilebileceğini söyledi. Riskin önemi olasılık ile etkinin çarpımıyla belirlenir; önem de yüksek, orta, düşük diye sınıflanır. Düşük olanlar listeden çıkarılır, önemi yüksek ve orta olanlar takibe alınır.

### 8.5 Risk takibi ve önlem

Takibe alınan her risk için ayrı bir sayfa açılır. Projedeki (ya da test adımlarındaki) kilometre taşlarında riskin olasılığının, etkisinin ve önem derecesinin değişip değişmediğine bakılır. Her risk için bir önlem tablosu hazırlanır: riskin önlemi nedir, yani nasıl bir önlem alınırsa risk ortaya çıkmaz?

Hocanın örneği test ekibindeki bir personelin işten ayrılması riskidir. Önlem olarak test ekibindeki diğer kişilerden bir yardımcı yetiştirmek ya da kilit kişinin ayrılmaması için anlaşmalar yapmak (örneğin ücretini artırmak) düşünülebilir. Her önlemin bir maliyeti vardır ve bu maliyet de tabloya yazılır. Bazen bir riske birkaç önlem yazılır, bazen aynı önlem farklı riskler için kullanılır. Böylece proje planındaki risk yönetimi test sürecine de yayılmış olur. Hoca, proje yönetiminde risk yönetiminin çok önem kazandığını belirtti.

## 9. Yazılım Konfigürasyon Yönetimi

### 9.1 Yazılım nedir?

Konfigürasyon yönetimine geçmeden önce yazılımın ne olduğu soruldu. Yazılım yalnız program değildir: yazılım mühendisliğinin ürünü olan yazılım programlar, belgeler ve veri yapılarından oluşur. Bir uygulamadaki veri tabanı ve tabloları, gereksinim belgesi, tasarım belgesi, test spesifikasyonu, kullanıcı belgeleri ve el kitapları ile program kodu yazılıma dahildir.

Yazılıma ait bu maddelerin bütününe **yazılım konfigürasyonu** denir. Hoca "konfigürasyon" sözcüğünü "düzen" olarak Türkçeleştirdi: yazılımın düzeninde hangi elemanlar varsa (programlar, belgeler, veri yapıları) bunlar konfigürasyonu oluşturur. Konfigürasyon yönetimi işlerinin uygulandığı her bir maddeye **yazılım konfigürasyon maddesi** (software configuration item, SCI) denir.

### 9.2 Konfigürasyon yönetimi etkinlikleri

Slayt önizlemesinde "7.2.2 Yazılım Konfigürasyonu" başlığı altında konfigürasyon tanımı, değişiklik kontrolü, denetimi ve raporlama etkinlikleri görünmektedir; hoca bunları şöyle anlattı:

- **Konfigürasyon tanımı (identification):** Bir veri tabanı uygulaması gibi, her elemanla ilgili tanımlar kaydedilir. Örneğin bir tablonun hangi tarihte yaratıldığı, en son hangi tarihte bilgi girildiği, hangi kolonları ve özellikleri olduğu, hangi uygulamaların bu tabloyu kullandığı. Bir program modülü için ilgili gereksinim ayrıntısı, tasarım bilgisi ve kullandığı tablolar kaydedilir; yani hem tanım hem ilişkilendirme yapılır. Bu kayıtlar elle girilmez; yazılım geliştirme platformları ve proje yönetim araçları her sürümde bu tanımları kendileri kaydeder.
- **Konfigürasyon değişiklik kontrolü:** Her yeni sürümde modüllerde ya da veri tabanında değişiklik olabilir. Değişikliğin hangi aşamada yapıldığı, kaçıncı sürüm olduğu ve nerelerde değişiklik yapıldığı izlenir.
- **Konfigürasyon denetimi ve raporlama.**

### 9.3 Standartlar

Yazılım konfigürasyon yönetiminde planlar için standartlar vardır. Slayt önizlemesinde şunlar okunur (ekrandan, 01:50:00):

- IEEE-STD-828: IEEE Standard for SCM Plans.
- IEEE-STD-1042: IEEE Guide for SCM Plans.
- ISO 9004 Quality Management & Quality System Elements, Part 6.

### 9.4 Sürüm yönetimi

Yazılım konfigürasyon yönetimi ile sürüm yönetimi (release management) birbiriyle ilişkilidir ve birlikte kullanılır. Release, ürünün kullanıma alınması ya da yeni bir sürüme geçilmesidir; sürüm yönetimi bu geçişin nasıl olacağını ve kurallarını belirler. Klasik süreçlerle çevik süreçler arasında bu konuda farklar vardır; çevik yaklaşımlarda sürüm yönetimi farklı işleyebilir. Hoca sürüm yönetimine ayrı bir başlık olarak sonra döneceğini söyledi.

## 10. Yazılım Bakımı ve Bakım Yapılabilirlik

Önceki hafta işlenen yazılım bakımına kısaca dönüldü. Bakım maliyetini azaltmak için bakım yapılabilirlik (maintainability) özelliği kullanılır. Bu özellik şunlarla sağlanır:

- Anlaşılabilir bir sistem yapısı.
- Belgelerin standartlara uygun geliştirilmesi.
- Standart programlama dili yapılarının kullanılması.
- Test programlarından yararlanılması.
- Tasarım aşamasında hata bulma ve düzeltme işlemlerinin yapılması.

Yazılımın bakım ve onarıma elverişliliği sınanabilirlik, basitlik, değiştirilebilirlik ve taşınabilirlik gibi özelliklerle ölçülür; bu özellikleri belirten metriklerden yazılımın bakım yapılabilirliği ortaya çıkar. Slayt önizlemesinde bu listede güvenilirlik ve etkinlik de yer almaktadır (ekrandan, 01:40:00).

## Örnek Sorular

**Soru 1** (derste sözlü, 02:06:22): Bir uygulama ya da test uygulaması için bir riskin önemini nasıl anlarız? Neye bakarak buluruz?

Derste ilk cevap riskin projeye etkisiydi; ardından riskin kategorisi (performans, maliyet, takvim gibi hangi alanı etkilediği) söylendi. Hoca başka bir faktör olduğunu belirterek cevabı tamamlattı.

> **Çözüm (derste verildi):** Riskin önemi, gerçekleşme olasılığı ile etkisinin çarpımıyla belirlenir. Olasılığı çok düşük bir riskin etkisi büyük olsa da göz ardı edilebilir. Riskler bu önem değerine göre sıralanır; hepsini izlemek mümkün olmadığından en önemlileri (yüksek ve orta) takibe alınır ve her biri için önlem ile önlemin maliyeti belirlenir.

**Soru 2** (derste sözlü, 02:11:49): Yazılım konfigürasyonu nedir? Yazılımın elemanları nelerdir, yazılım yalnız program kodu mudur?

Derste bir cevap, konfigürasyon yönetiminin yazılımdaki değişiklikleri izleme ve kontrol etme işi olduğuydu. Elemanlar sorusuna verilen "planlama, tasarım, gerçekleme" cevabını hoca bunların yazılım geliştirme adımları olduğunu söyleyerek düzeltti.

> **Çözüm (derste verildi):** Yazılım yalnız program kodu değildir. Program kodu, veri tabanı ve belgeler (gereksinim belgesi, tasarım belgesi, kullanıcı el kitabı, test planı, test tasarımı ve senaryoları ile test sonuç raporunu içeren test spesifikasyonu) birlikte yazılımı oluşturur. Bu elemanların bütününe yazılım konfigürasyonu, her birine yazılım konfigürasyon maddesi denir.

## Dersin Toparlaması

Bu derste önce yazılım ölçümü toparlandı: Halstead, McCabe, büyüklük ve fonksiyon noktası ölçütleri ile güvenirlik modelleri hatırlatıldı; McCabe değerinin modül başına 10 ile sınırlanması gerektiği vurgulandı. ISO 9126, McCall ve McConnell kalite modellerinin aynı kalite özelliklerini farklı biçimlerde sınıflandırdığı gösterildi ve McConnell'in iç ve dış kalite ölçütleri tek tek tanımlandı. Ölçme, ölçüt ve ölçüm kavramları ayrıştırıldı ve ölçme eyleminin tanımlama, toplama, hesaplama, yorumlama ve geri besleme adımları işlendi. CK ölçütlerinden WMC eleştirileriyle birlikte tekrar ele alındı.

İkinci bölümde test yönetimine geçildi: test spesifikasyonunun içeriği ve geliştirme adımları, test planı, test senaryosu belgesi, bağımsız test ekibi ve optimum test miktarı ile test etkinliklerinin yaşam döngüsündeki yeri anlatıldı. Test planının bir parçası olarak proaktif risk yönetimi, riskin olasılık, kayıp ve gelecek bileşenleri, risk sınıflamaları, risk tablosu ve önlem takibi işlendi. Son olarak yazılımın program, belge ve veri yapılarından oluştuğu hatırlatılarak yazılım konfigürasyonu, konfigürasyon yönetimi etkinlikleri, ilgili standartlar ve sürüm yönetimiyle ilişkisi tanıtıldı; konfigürasyon ve sürüm yönetiminin sonraki derslerde ayrıntılandırılacağı belirtildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
