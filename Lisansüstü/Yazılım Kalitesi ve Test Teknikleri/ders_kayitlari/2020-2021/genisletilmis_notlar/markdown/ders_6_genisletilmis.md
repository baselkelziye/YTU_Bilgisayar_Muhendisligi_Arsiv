# Ders 6 Genişletilmiş Notu: Yazılım Ölçümü Tekrarı, Test Planlama ve Yönetimi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Yazılım Ölçümü: Neden ve Kimin İçin
- 2. Halstead Ölçütleri
- 3. McCabe Döngüsel Karmaşıklığı
- 4. Büyüklük Ölçütleri: LOC ve Function Point
- 5. Yazılım Güvenirlik Modelleri
- 6. Nesneye Yönelik Ölçütler: CK Metrik Kümesi
- 7. Test Planlama ve Yönetimi
- 8. Test Planı ve Test Senaryosu
- 9. Test Çalışma Ekibi ve Optimum Test Miktarı
- 10. Yazılım Yaşam Döngüsü Boyunca Sınama Etkinlikleri
- 11. Teslim Sonrası Kalite Sağlama: Yazılım Bakımı
- 12. Yazılım Konfigürasyon Yönetimi
- Örnek Sorular
- Dersin Toparlaması

## 1. Yazılım Ölçümü: Neden ve Kimin İçin

Dersin ilk yarısı, bir önceki haftada işlenen "Kalite Ölçüm ve Değerlendirmeleri" bölümünün tekrarıdır. Bölümün hedefleri slaytta üç madde olarak verilir: yazılım kalite ölçütlerinin incelenmesi, yazılım ölçütlerinin test adımlarında kullanımının anlaşılması ve kalite güvenirliğinin kestirimini ve modellerini tanıma (ekrandan, 00:15:00).

Yazılım ölçümü (software metrics) yazılım mühendisliğinin önemli konularından biridir ve yazılım kalitesiyle iç içedir. Yazılım proje yönetiminde de ölçümden söz edilir; orada amaç daha çok biten projelerden bir arşiv verisi oluşturmak ve bu bilgi birikimini yeni bir projeye başlarken büyüklük, maliyet, iş gücü ve süre tahmininde kullanmaktır.

Hoca konuya bütün metrik alanları için geçerli olan klişe bir cümleyle girer: **ölçemediğinizi kontrol edemezsiniz.** Ölçme, hendese biliminin temelini oluşturur; mühendis de ölçme işlemini gerçekleştiren kişi olarak tanımlanır. Mühendisliğin iki zorunluluğu vardır: tasarım ve ölçüm. Yazılım mühendisliğinde "tasarım yapmadan programa geçmeyelim" denir; ölçüm de bu tasarımın denetlenmesini sağlar.

Ölçümün kime ne kazandırdığı iki açıdan ele alınır:

- **Yöneticiler için:** yazılım üretiminin maliyetine karar vermek, farklı bölüm çalışanlarının ücretlerini belirlemek, personel verimliliğini ölçmek ve altyapıda kullanılan yazılım ürünlerini kıyaslayabilmek.
- **Yazılım mühendisleri için:** sistemin kalitesini izlemek; tasarım süresince yapılan değişikliklerde, gözden geçirmelerde ve test adımlarında yararlanmak; kalite ve performans gereksinimlerini daha ölçülebilir terimlerle belirlemek; sertifika çalışmalarında ölçütlerle tanımlama yapmak. İyi bir yazılımın ne kadar koddan ve kaç modülden oluştuğu, karmaşıklık derecesinin büyüklüğü nasıl etkilediği gibi değerler kullanılır.
- Ayrıca var olan ürünler ve uygulanan süreçlerden yararlanarak gelecekteki ürünler için tahmin yapılabilmesi gerekir.

## 2. Halstead Ölçütleri

Halstead ölçütleri, kaynak programın kalite güvencesini kestirmek üzere önerilmiştir. Diğer derslerden de bilindiği gibi programdaki işleçler (operatörler) ve işlenenler (operandlar) sayılır; bu işlemlerin döngüler içinde kaç kez yinelendiği de hesaba katılır. Slayttaki tanımlar şöyledir (ekrandan, 00:20:00):

- $m$: programda bulunan farklı işleç (operatör) sayısı
- $k$: programda bulunan farklı işlenen (operand) sayısı
- $M$: işleç yinelenmelerinin toplamı
- $K$: işlenen yinelenmelerinin toplamı

Bu değerler saptanarak aşağıdaki ölçütlerin kullanılması önerilir. Slayta göre oransal hacmin daima birden küçük bir sayı olarak bulunması gerekir.

$$\text{Program uzunluğu: } U = m\log_2 m + \log_2 k$$

$$\text{Program hacmi: } H = (M+K)\log_2(m+k)$$

$$\text{Program gücü (program effort): } G = H/O$$

Bu değerlerle program uzunluğu, hacmi ve gücü hakkında değerlendirme yapılabilir; yani Halstead ölçütleri programdaki aritmetik işlemlerin yoğunluğu konusunda bilgi verir.

> **Ders sonrası not:** Slayttaki uzunluk formülü $U = m\log_2 m + \log_2 k$ olarak yazılmıştır. Halstead'in tahmini program uzunluğu formülünde ikinci terim de katsayılıdır; doğrusu büyük olasılıkla $U = m\log_2 m + k\log_2 k$ olmalıdır. Slaytta $O$ (oransal hacim, program düzeyi) için ayrı bir formül görünmüyor.

## 3. McCabe Döngüsel Karmaşıklığı

### 3.1 Program grafı ve bölge sayma

McCabe ölçütü, programın kontrol akışı biçiminde gösterimine dayanarak karmaşıklık derecesini belirler. Program grafı ya da akış grafı (program graph, flow graph) adı verilen çizim kontrol akışını gösterir; içinde harf yazılı her daire bir ya da çok sayıda kaynak program deyiminden oluşan bir görevi temsil eder. McCabe, bir modülün yazılım karmaşıklığını ölçerken program grafındaki döngü karmaşıklığını esas alır (ekrandan, 00:25:00).

Hesap için graf içindeki kapalı bölgeler ile graf dışında kalan bölge sayılır; bu sayı modülün karmaşıklığını verir. Slayttaki örnekte bölgeler R1..R5 olarak gösterilmiş ve $V(G) = 5$ bulunmuştur (ekrandan, 00:25:00). <!-- BELİRSİZ: örneğin akış grafı şekli karelerde görünmüyor; yalnız sonuç (R1..R5, V(G)=5) slayt metninde var -->

Akış grafı çizilirken deyimler düğüm olarak kullanılır. Kapalı alanları belirleyen, akışı etkileyen düğümler kontrol deyimlerinin bulunduğu düğümlerdir. Deyimler ile kontrol deyimleri birleştirilip tek bir düğüm olarak gösterilse de aynı sonuç elde edilir: düğüm sayısı arttıkça kenar sayısı da artar, ama kapalı bölge sayısı değişmez. Bu yüzden döngüsel karmaşıklık, düğüm sayısı ile kenar sayısı arasında bir işlem yapılarak da hesaplanabilir.

> **Ek bilgi (derste anlatılmadı):** Düğüm ve kenar sayısından hesap büyük olasılıkla $V(G) = E - N + 2$ formülüyle yapılır ($E$ kenar, $N$ düğüm sayısı). Karar düğümü sayısı $P$ ise $V(G) = P + 1$ formülü de aynı sonucu verir.

### 3.2 Temel yol testiyle ilişkisi

Döngüsel karmaşıklık, iki ders önce görülen saydam kutu (beyaz kutu) testiyle doğrudan ilişkilidir. Saydam kutu test tiplerinden ikisi döngü testi ve temel yol testidir. Temel yol testinde McCabe değeri programdaki bağımsız yol sayısını verir. Bütün yolları denemek için en az bu sayı kadar test durumu (test case) oluşturulmalıdır.

**Soru:** Temel yol testinde döngüsel karmaşıklık bize neyi verir? **Cevap:** Bir öğrenci önce dal kapsamını (branch coverage) bulmaya yaradığını, sonra kaç test durumunun gerektiğini bulmaya yaradığını söyler. Hoca ikinci cevabı onaylar: döngüsel karmaşıklık sayısı kadar en az test durumu olmalıdır ki bütün yollar denensin.

### 3.3 Modül büyüklüğü sınırı

McCabe ölçüsü yalnız testte değil tasarım sırasında da kullanılır; en yüksek modül büyüklüğünü saptamakta da işe yarar. Çok sayıda programlama projesinden derlenen bilgilere göre modül büyüklüğünün en çok $V(G) = 10$ olması gerektiği belirlenmiştir. Döngü karmaşıklığının bu sayıyı aşması halinde modülün sınanması büyük ölçüde zorlaşır (ekrandan, 00:30:00).

McCabe dışında, algoritmalar dersinden bilinen algoritmik karmaşıklık da tasarlanan algoritmanın ne kadar karmaşık olduğu konusunda fikir verir.

## 4. Büyüklük Ölçütleri: LOC ve Function Point

Bu kısım slaytta yoktur; hoca yazılım mühendisliği derslerinden hatırlatır. "Ne büyüklükte bir yazılım geliştireceğiz?" ya da "Geliştirilmiş yazılımın büyüklüğü nedir?" sorusuna cevap ararken iki yaklaşım vardır: doğrudan ölçmek ve dolaylı ölçmek.

### 4.1 Doğrudan ölçüm: satır sayısı

Doğrudan ölçmek, yazılımla ilgili tek bir değeri sayıp büyüklüğü bulmaktır. İlk akla gelen kod satır sayısıdır; birimi LOC (Line of Code) ya da bin satır için KLOC'tur. En kolay ölçülen şey olduğu için büyüklükle ilgili ilk akla gelen ölçümdür. Programın etkinliğine ve programlama diline bağlı olduğu için öznel (sübjektif) kalır, ama yine de fikir verir. Daha kullanışlı olması için programlama dilleri arasında bir çevrim sistemi oluşturulmuştur; böylece diller arasında denklik kurulabilir. Bu yüzden LOC ve KLOC, tam objektif olmasa da yorum yaparken halen kullanılır.

### 4.2 Dolaylı ölçüm: işlev noktası (function point)

**Soru:** Function point nedir? **Cevap:** Bir öğrenci bunun toplam fonksiyon sayısı olarak düşünülebileceğini söyler. Hoca açılımı şöyle verir: amaç projenin büyüklüğünü bir sayıya dökmektir. Satır sayısı doğrudan ölçümdür; function point ise ekranların büyüklüğü, girdi sayısı, çıktı sayısı, ekran ve arayüz sayısı, oluşturulan sorgu sayısı, dosya (tablo) sayısı ve ara birim sayısı gibi sayılabilir değerleri bir tabloya yerleştirir.

Bu değerler belli ağırlıklarla toplanır; hepsinin ağırlığı aynı değildir. Örneğin bir programın büyüklüğü için dosya sayısı, girdi sayısından daha ağırlıklı bir etkendir. Ancak bu toplam tek başına yeterli değildir. Function point ilk oluşturulurken 14 soru sorulmuş ve bunlara 0'dan 5'e kadar ağırlıklı değerler verilmiştir. Bu sorulara göre bir düzeltme faktörü uygulanır ve bütün bileşenlerle function point değeri hesaplanır.

Tek bir şey ölçülüp büyüklük söylenmediği, birden çok değer birleştirildiği için bu bir **dolaylı ölçümdür**. Sayılan büyüklükler (girdi, çıktı, ara birim, ekran, sorgu) ticari yazılımlarda önemlidir: ticari yazılımda girdi-çıktı, güzel raporlar ve çok veri kullanmak öne çıkar. Function point de yıllar önce ticari yazılımlarda büyüklük yorumu yapmak için çıkarılmış ve çok kullanım alanı bulmuştur.

## 5. Yazılım Güvenirlik Modelleri

Güvenirlik (reliability) kalite özelliklerinde görülen bir kavramdır. Yazılımın doğru sonuç vermesi istenir; güvenirlik bu doğru sonuca ne kadar güvenilebileceğini, hata yüzdesinin ne olduğunu belirtir. Yazılım güvenirliği geçmiş bilgilere ve teste dayalı olarak hesaplanır: toplam işletim süresinde ne kadar başarılı sonuç verildiği, başarı oranının ne olduğu, bir düzeltme yapıldıktan sonraki hata sayısı gibi değerler kullanılır. Kullanım süresi içinde bulunan toplam hata sayısından istatistiksel değerlendirmeyle güvenirlik düzeyleri oluşturulur.

Farklı uzmanların geliştirdiği yüze yakın güvenirlik modeli vardır. Hangisinin kullanılacağına karar vermek için modeller değerlendirilir. Slayta göre bir yazılım birden fazla modele göre test edilmeli ve sonuçlar karşılaştırılmalıdır. Model değerlendirilirken şu sorulara cevap aranır (ekrandan, 00:40:00):

- Modele göre yazılım ne kadar geçerlidir?
- Modeli kullanarak yazılımın güvenirliğinin ölçümü ne kadar kolaydır?
- Modeli kullanmak için yazılımın ne kadarına ihtiyaç vardır (tamamı mı, bir bölümü yeterli mi)?
- Modeli yazılım ölçümünde kullanmak kolay ve anlaşılır mı?
- Model dış etkenlerden etkileniyor mu?

Bu sorular modelin uygulamaya ne kadar uygun olduğunu belirler.

## 6. Nesneye Yönelik Ölçütler: CK Metrik Kümesi

Nesneye dayalı uygulamalarda CK metrikleri ve MOOD metrikleri gibi farklı ölçüt kümeleri vardır; nesneye dayalı programlama ve tasarım derslerinden de bilinir. Bu ölçütler diğer yazılımlarda üzerinde durulmayan, nesneye yönelik yaklaşımda var olan sınıflara bağlı özellikleri sayısal hale dönüştürür. Derste Chidamber ve Kemerer'in tanımladığı CK metrik kümesi tekrar edilir (ekrandan, 00:45:00 ve 00:50:00).

### 6.1 WMC: Sınıfın ağırlıklı metot sayısı

Weighted Methods per Class (WMC), bir sınıfın tüm metotlarının karmaşıklığının toplamıdır. Tüm metotların karmaşıklığı 1 kabul edilirse sınıfın metot sayısına eşit olur. Metot sayısı ve karmaşıklığı, sınıfın geliştirilmesine ve bakımına ne kadar zaman harcanacağı hakkında fikir verir ve yeniden kullanılabilirliği etkiler. Metot sayısı çok olan taban sınıflar çocuk düğümlerde daha çok etki bırakır, çünkü tanımlanan tüm metotlar türetilen sınıflarda da yer alır. Metot sayısı çok olan sınıfların uygulamaya (alana) özgü olma ihtimali yüksektir; bu nedenle tekrar kullanılabilirlikleri düşer.

### 6.2 DIT: Kalıtım ağacının derinliği

Depth of Inheritance Tree (DIT), sınıfın kalıtım ağacının köküne uzaklığıdır. Hiçbir sınıftan türetilmemiş sınıflar için 0'dır. Çoklu kalıtım varsa en uzak köke olan uzaklık alınır. Kalıtım hiyerarşisinde daha derinde olan sınıflar daha çok metot türettiği için davranışlarını tahmin etmek zordur; derin kalıtım ağaçları daha fazla tasarım karmaşıklığı oluşturur.

### 6.3 NOC: Alt sınıf sayısı

Number of Children (NOC), sınıftan doğrudan türetilmiş alt sınıfların sayısıdır. Bir sınıfın çok fazla alt sınıfı varsa bu, kalıtımın yanlış kullanıldığının bir göstergesi olabilir. Alt sınıf sayısı sınıfın tasarımdaki potansiyel etkisi hakkında fikir verir. Çok alt sınıfı olan sınıfların metotları daha çok test gerektirdiği için bu metrik, sınıfı test etmek için ayrılacak bütçe ve iş gücü hakkında bilgi verir.

### 6.4 CBO: Nesne sınıfları arasındaki bağımlılık

Bağımlılık (coupling) hem CK metrikleri hem de diğer nesneye yönelik metrik kümelerinde yer alır; yapısal yaklaşımda da modüller arası bağlılık olarak geçer ve tasarımda bağlılığın çok olmamasına dikkat edilmesi istenir. CK'de bir sınıfın bağımlı olduğu sınıf sayısı olarak tanımlanır. Hocanın anlatımına göre burada sayılan bağımlılık, aralarında kalıtım ilişkisi olmayan iki sınıf arasındaki bağımlılıktır.

Aşırı bağımlılık tasarıma zarar verir. Nesneye yönelik yaklaşım büyük ölçüde yeniden kullanılabilirlik için tercih edilir; sınıfların birbirine çok bağlı olması yeniden kullanımı azaltır. Bir sınıf ne kadar bağımsızsa başka uygulamalarda o kadar yeniden kullanılabilir. Bağımlılıktaki artış bakımı da zorlaştırır ve tasarımın farklı parçalarının test edilmesinin ne kadar karmaşık olacağı hakkında fikir verir; yani test maliyeti de artar.

### 6.5 RFC: Sınıfın tetiklediği metot sayısı

Response For a Class (RFC), verilen sınıftan bir nesnenin metotları çağrıldığında bu nesnenin tetikleyebileceği tüm metotların sayısıdır. Sınıfın test maliyeti hakkında fikir verir: bir mesajın çok sayıda metodun çağrılmasını tetiklemesi, sınıfın testinin ve hata ayıklamasının zorlaşması demektir. Bir sınıftan fazla sayıda metodun çağrılması, sınıfın karmaşıklığının yüksek olduğunun işaretidir (ekrandan, 00:50:00).

### 6.6 LCOM: Metotların uyumluluğu

Lack of Cohesion in Methods (LCOM) sınıftaki iç bağlılığı (iç uyumu) gösterir. Slayta göre bu metriğin birden çok tanımı vardır (ekrandan, 00:50:00):

- **İlk tanım (Chidamber ve Kemerer):** $C_1$ sınıfının $M_1, M_2, \ldots, M_n$ metotları olduğu ve $\{I_i\}$ kümesinin $M_i$ metodunda kullanılan nitelik değişkenleri kümesi olduğu kabul edilsin. LCOM, bu $n$ kümenin kesişiminden oluşan ayrık kümelerin sayısıdır.
- **Yenilenmiş tanım:** $P$ hiçbir ortak nitelik değişkeni paylaşmayan metot çiftlerinin kümesi, $Q$ en az bir ortak nitelik değişkeni paylaşan metot çiftlerinin kümesi olsun.

$$LCOM = \begin{cases} |P| - |Q| & |P| > |Q| \text{ ise} \\ 0 & \text{aksi durumda} \end{cases}$$

Özetle uyum (cohesion), sınıfın niteliklerinin ve metotlarının birbiriyle ne kadar uyumlu olduğunu, yani yalnız o sınıfa ait bir sorumluluğu ne kadar birlikte taşıdığını gösterir.

### 6.7 Ölçütlerin genel değerlendirmesi

Halstead gibi ölçütler bütün programlarda aritmetik işlemlerin yoğunluğu hakkında bilgi verir; LOC ve function point büyüklüğü verir; McCabe ise yalnız döngüleri değil bütün kontrol deyimlerini sayarak tasarımdaki algoritmik yol sayısını verir ve test ile tasarımda önemlidir. Bu ölçütler yazılım geliştirmeyi yalnız bir sanat olmaktan çıkarıp ölçmeyle birleşmiş bir mühendislik uygulamasına dönüştürür. Tasarım sırasında bu değerler ölçülerek daha iyi yazılım geliştirilir; işlevsel olmayan gereksinimlerden biri olan güvenirlik de istatistiksel modellerle iyileştirilir.

## 7. Test Planlama ve Yönetimi

Aradan sonra yeni bölüme geçilir: "Yazılım Test Planlama ve Yönetim". Bölümde test spesifikasyonu belgesinin nasıl hazırlandığı, test planının içeriği, test senaryolarının hazırlanması, test yönetimi, bakım çalışması ve kısaca konfigürasyon yönetiminin tanımı ele alınır; konfigürasyon yönetiminin ayrıntısına girilmez.

### 7.1 Test adımları

Test yönetimi, test kapsamında gerçekleştirilen işlemlerin sıralanmasıdır. Slayttaki blok diyagram dört adımı sırayla verir (ekrandan, 01:15:00):

```text
Test Metodolojisi
      |
      v
Test Planlama
      |
      v
Test Dizaynı (tasarımı)
      |
      v
Testin Gerçekleştirilmesi
```

Önce test metodolojisine karar verilir: test ederken hangi sıra uygulanacak, hangi işlemler yapılacak ve bunlar hangi modele göre yapılacak. Ardından planlama, sonra testin tasarımı gelir; test ancak bunlardan sonra gerçekleştirilir.

### 7.2 Test spesifikasyonu

Yazılım testlerini tanımlamak, planlamak, düzenlemek ve belgelemek için **test spesifikasyonu** adı verilen bir belge düzenlenir. Belgenin genel hatları şunlardır (ekrandan, 01:55:00):

- **Test planları:** test şekilleri, zamanlama, gider, ortam ve kaynaklar.
- **Test senaryoları:** test verisi olarak kullanılan senaryolar.
- **Test işlemleri:** her testin tanımlanması (bütünleme biçimi, amacı ve test edilen modüller, özel araç ve teknikler, gideri, test programı verisi) ve beklenen sonuçlar.
- **Gerçek test sonuçları.**
- **Referans.**
- **Ekler.**

Test işlemlerinde testin nasıl ve hangi ortamda yapıldığı, beklenen sonuçlarla gerçek sonuçların ne olduğu yazılır. Standartlardaki belgenin tamamı yerine daha özet ve basit bir sürümü de aynı yapıda hazırlanabilir.

Test yönetimi geri beslemeli bir süreçtir. Testteki hata mesajları da doküman testi içinde ele alınır; hata mesajı içeriği de belge olarak test edilir ve doğru mesajın görüntülenmesi için kod testi yapılır. Yazılım test belgelemesi (Software Test Documentation) için bir IEEE standardı test spesifikasyonunu tanımlar. Test spesifikasyonu önce yazılır, üzerinden gidilerek incelenir, incelemeye dayalı düzeltmelerle yenilenir ve böylece sürekli yaşayan bir belge haline getirilir.

> **Ders sonrası not:** Slaytta standart "(830-1993) - IEEE Standard for Software Test Doc." olarak yazılmıştır; hoca da numaranın yanlış olduğunu, 830'un gereksinim belgesi standardının numarası olduğunu söyledi. Yazılım test belgelemesi standardı büyük olasılıkla IEEE 829'dur.

## 8. Test Planı ve Test Senaryosu

### 8.1 Test planının içeriği

Slayta göre test planı şu başlıklarla hazırlanmalıdır; ancak plandaki ayrıntılar değişebilir (ekrandan, 01:20:00):

- Test stratejisi ve test edilecek öğeler
- Doğrulama yöntemleri
- Testlerin tamamlanma kriterleri
- Hata ve test sonuç raporlama
- Test sorumlulukları
- Test ortamı
- Eleman ve eğitim ihtiyacı
- Test takvimi
- Risk yönetimi
- Test çıktıları

Hoca başlıkları tek tek açıklar:

- **Test stratejisi:** hangi süreç modeli kullanıldığı burada belirtilir. Örneğin çevik (agile) bir süreç modeli ya da test güdümlü geliştirme (test driven development) uygulandıysa test stratejisi buna göre yazılır. Hangi modüllerin test edileceği, yazılımın bütünü test edilecekse kapsamın ne olduğu da burada yer alır.
- **Testlerin tamamlanma kriterleri:** testin ne zamana kadar sürdürüleceğini belirler; örneğin belirli bir hata oranına inilene ya da belirli sayıda hata giderilene kadar.
- **Test sorumlulukları:** bir test ekibi varsa ekibin görevleri; hangi testlerin yazılım geliştiriciler, hangilerinin test grubunun hangi elemanları tarafından yapıldığı.
- **Test ortamı:** hangi test araçlarının (tool) hangi amaçla kullanılacağı. Özellikle sistem testi ve birim testi için yazılıma uygun test araçlarının araştırılması gerekir.
- **Eleman ve eğitim ihtiyacı:** örneğin kullanıcı testi için ayrıca bir testçi alınıp alınmayacağı.
- **Test takvimi:** proje planında olduğu gibi bir Gantt diyagramıyla hangi testin hangi tarihte uygulanıp ne zaman biteceği.
- **Risk yönetimi:** test planlandığı gibi gitmezse riskli durumlarla nasıl başa çıkılacağı.
- **Test çıktıları:** testten elde edilecek çıktılar.

Daha az maddeyle de yazılabilir, ama test stratejisi ve test edilecek öğeler, tamamlanma kriteri, hata ve sonuçların nasıl raporlanacağı, test ortamı, takvim ve sorumluluklar ile risk durumları bir test planında mutlaka bulunmalıdır.

### 8.2 Test senaryosu

Test planından sonra test senaryosu hazırlanır. Test senaryosu test veri gruplarıdır; özellikle kullanıcı testinde hangi durumların (case) sınanacağını tanımlar. Bir test senaryosunda şunlar bulunur:

- Senaryonun adı (hangi test olduğu)
- Yazarı ve tarihi (kimin ne zaman oluşturduğu)
- İlgili gereksinimler ya da testin amacı
- Ön koşullar ve varsayımlar
- Test girdileri
- Test senaryosu adımları
- Beklenen sonuçlar

Test senaryoları saklanan yazılım belgeleri arasında yer alır. Sonradan bir modülde hata çıktığında, o modülün daha önce hangi verilerle test edildiğine ve hatanın neden bulunamadığına geri dönülebilir.

**Soru:** Test planı, yazılım geliştirme süreç modeline göre mi seçilir? **Cevap:** Evet, test metodolojisi yazılım geliştirme süreç modeline (örneğin şelale ya da çevik) göre belirlenir. Örneğin test güdümlü geliştirme yapılıyorsa test planı ve testler daha erken oluşturulur, test tasarımları farklı olur. Yapılacak testlerin türü (birim testi, sistem testi, kullanıcı testi) değişmez; fark, süreç modeline göre test metodolojisindeki sıralamadadır ve raporda bu belirtilir.

## 9. Test Çalışma Ekibi ve Optimum Test Miktarı

### 9.1 Test ekibinin yapısı ve görevi

Yazılımın sınanması sürecinde bağımsızlık sağlanmalıdır. Bu yüzden yazılımın sınanmasından sorumlu kişiler, yazılımı tasarlayan ve oluşturan gruptan olmamalıdır (ekrandan, 01:25:00). Böyle ayrı bir ekip kurulabiliyorsa test daha doğru olur; orta ve büyük yazılım şirketlerinde genellikle ayrı bir test ekibi bulunur.

Test ekibinin görevi, planlarda belirtilen testler için gerekli hazırlıkları yapmak, testleri yürütmek, testlerde bulunan hataları yazılımcıya bildirmek, izlemek ve test sonuçlarını raporlamaktır.

### 9.2 Optimum test miktarı

Slayta göre iyi bir testçi mükemmele ulaşılamayacağını, iyinin yeterli olacağını bilir; her yazılım projesindeki optimum test miktarı farklıdır (ekrandan, 01:25:00). Hoca bunu bir grafikle açıklar: kaçırılan hata (bug) sayısı kırmızı, test maliyeti mavi eğriyle gösterilir. Başta test maliyeti yoktur ve test miktarı arttıkça maliyet yükselir. Kaçırılan hata sayısı başta yüksektir ve test arttıkça azalır. İki eğrinin kesişim noktası optimum test miktarını verir; bu noktadan sonra ihmal edilebilir sayıda hata kalır ve maliyet artık önem kazanır. <!-- BELİRSİZ: grafik (Şekil 7.3) karelerde açık görünmüyor; eksen ve değerler yalnız anlatımdan -->

Test ekibinin işi bu optimum noktayı doğru yakalamaktır. Yazılım kalitesiyle uğraşan akademik camiada optimum test miktarının nasıl bulunacağı, ideal test sayısının ne olduğu ve hangi yöntemlerle bulunabileceği üzerine makaleler vardır; konu halen çalışılmaktadır.

## 10. Yazılım Yaşam Döngüsü Boyunca Sınama Etkinlikleri

Yaşam döngüsü farklı süreç modellerinde değişebilir, ama genel olarak test etkinlikleri evrelere şöyle dağılır (ekrandan, 01:30:00):

| Evre | Sınama etkinlikleri |
|---|---|
| Planlama | Sistem test planı, yazılım kalite planı |
| Gereksinim analizi | Alt sistem sınama planları |
| Tasarım | Modül test planı, test tanımları, test eğitim el kitapları |
| Gerçekleme | Birim test, bütünlük testi, sistem test |
| Kurulum | Kullanıcı testi, test raporları |

Planlamada sistemle ilgili test planının yanında yazılım kalite planı da hazırlanır; kalite planında hangi kalite özelliklerinin nasıl sağlanacağı ve standartlar planlanır. Gereksinim analizinde alt sistemlerin test planları ve nasıl test edilecekleri belirtilir. Tasarımda modüllerin test planı ve test tanımları oluşturulur, bir yandan da eğitim el kitapları hazırlanır. Gerçeklemede kodlamayı yapan kişi birim testini yapar; biten modüller arttıkça bütünleme (entegrasyon) testi yapılır. Sistem testi modül aşamasında da bir modül üzerinde yapılabilir; bütünlük testinden sonra da bütün sistemin sistem testi yapılır. Kurulumda kullanıcı testi yapılır ve test raporu oluşturulur.

Bütün bu işler, testin nasıl yapıldığını anlatan test spesifikasyonu belgesinde toplanır: test planları, test senaryoları, test işlemleri ve beklenen sonuçlar ile gerçek test sonuçları.

## 11. Teslim Sonrası Kalite Sağlama: Yazılım Bakımı

### 11.1 Bakımın gerekliliği

Yazılım sisteminin geliştirilmesi, ürünün müşteriye teslimi ve kullanılmaya başlanmasıyla tamamlanır. Kullanım süresinde de bakımı ve korunması, onarılması ve geliştirilmesi gerekir (ekrandan, 01:40:00). Bu, yazılım bakımı (software maintenance) sürecidir.

### 11.2 Bakım türleri

Bakım üç tür işten oluşur. Hocanın anlatımına göre en büyük pay uyarlamadadır; hata düzeltme ile iyileştirme kalan payı kendi aralarında yaklaşık yarı yarıya paylaşır. <!-- BELİRSİZ: slayttaki yüzde değerleri karelerde okunamadı -->

- **Hata düzeltme:** müşteriye teslimden sonra test sırasında bulunamamış işlem, performans ya da tasarım hataları ortaya çıkabilir ve düzeltilmeleri gerekir. Bu hatalar müşterinin yazılım geliştiriciye güveninin azalmasına yol açar; bu yüzden hatalar teslimden önce mümkün olduğunca en aza indirilmeye çalışılır.
- **İyileştirme:** yazılımın yeteneğini ve performansını iyileştirmek, kullanımını kolaylaştırmak için programa eklemeler yapılır. Gereksinim analizi, tasarım ve gerçekleştirme süreci çerçevesinde yeni eklemeler gerekebilir.
- **Uyarlama:** müşterinin başta farkına varmadığı ama sonradan yazılımdan elde edilebileceğini anladığı değişiklikler ya da müşterinin iş sürecindeki değişikliklerin yazılıma yansıtılması.

### 11.3 Bakımın maliyeti ve azaltılması

Bakım maliyetlidir; geliştirme maliyetinden bile fazla olabilir. Çünkü bakımda yazılım geliştirme sürecinin aynısı uygulanır: hata gereksinim analizinde, tasarımda ya da kodlamada olabilir. Hata gereksinimdeyse en başa dönülür ve buna bağlı birçok şeyin de değiştirilmesi gerekir.

Slayta göre bakım ve onarım giderini en aza indirmek için yazılım ürünü "bakım ve onarıma elverişli" (maintainability) nitelikte oluşturulmalıdır. Bunun için şunlar gerekir (ekrandan, 01:45:00):

- Yetenekli ve deneyimli yazılım mühendisleri görevlendirmek
- Anlaşılabilir bir sistem yapısı ve kolay işletilebilir bir sistem tasarlamak
- Standart programlama dilleri ve işletim sistemleri kullanmak, belgeleri standart biçimde düzenlemek
- Test programlarından yararlanmak
- Tasarım aşamasında hata bulma ve düzeltme kolaylıkları sağlamak

Yazılımı baştan kolay bakım yapılabilir biçimde tasarlamak sonraki bakım maliyetini belirler.

### 11.4 Bakım ve onarıma elverişlilik

Bakım ve onarıma elverişlilik, yazılımın diğer kalite faktörlerinden sınama kolaylığı, basitlik, değiştirilebilirlik, taşınabilirlik, güvenirlik ve esneklik özelliklerinin bileşkesi olarak ortaya çıkar. Kolay test edilebilmesi için yazılımın modüler ve kolay izlenebilir olması, tasarımın çok karmaşık yapılmaması gerekir; takip edilebilirlik için de basitlik gerekir. Değiştirilebilirlik de aynı amaca hizmet eder.

## 12. Yazılım Konfigürasyon Yönetimi

Teslim sonrasında yapılacak bir diğer iş, yazılım konfigürasyonunu ve konfigürasyon yönetimini sürdürmektir. Slayttaki tanımlar şöyledir (ekrandan, 01:50:00):

- Yazılım mühendisliğinin ürünleri programlar, belgeler ve veri yapılarıdır. Bu ürünlere ait bütün maddelere topluca **yazılım konfigürasyonu** (yazılım düzeni) denir.
- **Yazılım konfigürasyon maddesi** (software configuration item), YKY (yazılım konfigürasyon yönetimi) işlemlerinin uygulandığı yazılım modülüdür; incelenen modül tanımlarıyla birlikte bir bütün olarak gösterilir.

YKY etkinlikleri dört aşamada gerçekleştirilir:

- **Konfigürasyon tanımı (Configuration Identification):** her yazılım elemanının özelliklerini belirterek saklamak.
- **Konfigürasyon değişiklik kontrolü (Configuration Control):** yazılımda yapılan bir değişikliğin konfigürasyon belgelerine de yansıtılması. Sürüm yönetiminde her yeni sürümdeki temel değişiklikler bu yapıya yerleştirilir.
- **Konfigürasyon denetimi (Configuration Auditing):** her adımın standartlara uygun yapılıp yapılmadığının kontrol edilerek değerlendirilmesi.
- **Konfigürasyon raporlama (Configuration Status Accounting):** herhangi bir durumda farklı kriterlere göre yazılım parçalarıyla ilgili bilgi alınabilecek bir yapının oluşturulması.

Yazılım konfigürasyonu, sektörde son zamanlarda önem kazanan sürüm yönetimiyle (software release management) iç içedir. Yeni bir teslim aşamasında konfigürasyonun ne durumda olduğunu ve hangi değişikliklerin yapıldığını kaydetmek bu iki işin birlikte yürümesini gerektirir.

Konfigürasyon yönetimi de standartlara bağlı yapılır. Yazılım konfigürasyon yönetimi planının nasıl oluşturulacağı IEEE 828 ve IEEE 1042 standartlarında anlatılır; ISO 9004 kalite yönetimi ve kalite sistem elemanları standardında da yazılım konfigürasyon yönetimine ilişkin tanımlamalar vardır (ekrandan, 01:50:00).

## Örnek Sorular

**Soru 1** (derste sözlü, 00:23:00): McCabe döngüsel karmaşıklığı akış grafından bulunur. Saydam kutu testinin temel yol testinde bu değer bize neyi verir?

> **Cevap (derste verildi):** Programdaki bağımsız yol sayısını verir. Bütün yolları denemek için oluşturulması gereken en az test durumu (test case) sayısı bu değere eşittir.

**Soru 2** (derste sözlü, 00:30:37): Function point (işlev noktası) nedir, büyüklüğü nasıl ölçer?

> **Cevap (derste verildi):** Projenin büyüklüğünü sayıya dökmek için girdi, çıktı, sorgu, dosya (tablo), ekran ve ara birim sayıları farklı ağırlıklarla toplanır; 0-5 arası puanlanan 14 soruyla bir düzeltme faktörü uygulanır. Birden çok değer birleştirildiği için dolaylı bir büyüklük ölçümüdür ve ticari yazılımlar için geliştirilmiştir.

**Soru 3** (derste sözlü, 00:36:35): Güvenirlik (reliability) modelleri hakkında ne söyleyebiliriz?

> **Cevap (derste verildi):** Güvenirlik, yazılımın verdiği doğru sonuca ne kadar güvenilebileceğini gösteren bir kalite özelliğidir. Geçmiş bilgilere ve teste dayalı olarak işletim süresindeki başarı oranı ve düzeltmeden sonraki hata sayısı gibi değerlerle istatistiksel olarak kestirilir. Yüze yakın model vardır; yazılım birden fazla modelle test edilip sonuçlar karşılaştırılır ve model; geçerlilik, ölçüm kolaylığı, gereken yazılım miktarı, anlaşılırlık ve dış etkenlerden etkilenme açısından değerlendirilir (ekrandan, 00:40:00).

**Soru 4** (derste sözlü, 01:36:17): Test planı, kullanılan yazılım geliştirme süreç modeline göre mi belirlenir?

> **Cevap (derste verildi):** Test metodolojisi süreç modeline göre belirlenir. Örneğin test güdümlü geliştirmede test planı ve test tasarımları daha erken oluşturulur. Yapılan test türleri (birim, sistem, kullanıcı testi) aynı kalır; değişen, metodolojideki sıralamadır.

## Dersin Toparlaması

Dersin ilk yarısında yazılım ölçümü tekrar edildi: Halstead ölçütleri işleç ve işlenen sayılarından program uzunluğu, hacmi ve gücünü; McCabe döngüsel karmaşıklığı akış grafındaki bölgelerden bağımsız yol sayısını ve dolayısıyla temel yol testindeki en az test durumu sayısını verir. Büyüklük için doğrudan ölçüm olan LOC/KLOC ile dolaylı ölçüm olan function point karşılaştırıldı; güvenirlik modellerinin nasıl değerlendirileceği ve nesneye yönelik yazılımlar için CK metrik kümesi (WMC, DIT, NOC, CBO, RFC, LCOM) hatırlatıldı. Bu ölçütlerin ortak katkısı, yazılım geliştirmeyi ölçmeye dayalı bir mühendislik uygulamasına dönüştürmeleridir.

İkinci yarıda test planlama ve yönetimine geçildi. Test; metodoloji, planlama, tasarım ve gerçekleştirme sırasıyla yürütülür ve test planı, test senaryoları, test işlemleri, beklenen ve gerçek sonuçlardan oluşan test spesifikasyonunda belgelenir. Test ekibinin bağımsızlığı, maliyet ile kaçırılan hata arasındaki optimum test miktarı ve test etkinliklerinin yaşam döngüsü evrelerine dağılımı ele alındı. Son olarak teslim sonrası kaliteyi sürdüren iki etkinlik, yazılım bakımı (hata düzeltme, iyileştirme, uyarlama; bakım yapılabilirlik) ve yazılım konfigürasyon yönetimi (tanım, değişiklik kontrolü, denetim, raporlama) tanıtıldı; konfigürasyon yönetiminin sürüm yönetimiyle ilişkisinin ileride ele alınacağı belirtildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
