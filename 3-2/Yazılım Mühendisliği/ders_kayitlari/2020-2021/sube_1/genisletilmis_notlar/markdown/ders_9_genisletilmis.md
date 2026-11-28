# Ders 9 Genişletilmiş Notu: Tasarım Kalıpları, Kuaför Sınav Sorusunun Çözümü ve McCall Yazılım Kalite Modeli

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Nesneye Yönelik Tasarım Süreci
- 2. Tasarımın Belgelendirilmesi
- 3. Tasarım Kalıpları: Genel Bakış
- 4. Sorumluluk Atama Kalıpları
- 5. Sınav Uygulama Sorusu: e-kuaförüm.com Bilgi Sistemi
- 6. Nesne Modelleme Tekrarı: Kahve Sitesi
- 7. Tasarım Diyagramlarında Kalıpların Kullanımı
- 8. Etkinlik Şemaları Tekrarı
- 9. Yazılım Kalitesi ve Kalite Modelleri
- 10. Kalite ile Tasarım Kalıpları Arasındaki İlişki

## 1. Nesneye Yönelik Tasarım Süreci

Nesneye yönelik analiz konusu önceki derslerde tamamlanmıştı; bir önceki derste de tasarımda hangi diyagramların kullanıldığı üzerinde hızlıca durulmuştu. Bu derste yazılım mimarisini de içine alan tasarım kalıpları konusuna geçildi.

Yazılım geliştirmede analizden sonraki aşama tasarımdır. Hocanın sistem analizinden de hatırlattığı ayrım şudur: **analizde "ne?"** sorusuna, **tasarımda "nasıl?"** sorusuna yanıt aranır (ekrandan, 00:15:00).

Nesne modeli analizden tasarıma taşınır: doğrudan problem alanıyla ilgili nesnelerden oluşan model, tasarımda **yardımcı nesnelerle zenginleştirilir**. Tasarımdaki ana işlem grupları ikidir:

- **Nesne tasarımı:** problem alanıyla ilgili nesneler. Problem alanının ne olduğu ve bu alandaki nesnelerin neler olduğu analizden sonra tasarımda iyice netleştirilir.
- **Sistem tasarımı:** alt yapıyı ve gereçleri oluşturan nesneler.

Sistem katmanında bulunabilecek bileşenler slaytta şöyle sıralanır (ekrandan, 00:15:00):

- Yazılım mimarisi: istemci-sunucu, eşler arası, olay tabanlı vb.
- Kullanıcı arayüzü
- Veri yönetimi
- Ağ programlama

Hoca, use case diyagramından başlayarak nesnelerin belirlendiğini, sınıf diyagramının ilk halinden sonra bu diyagramın tamamlandığını, nesneler arasındaki ilişkilerin ve özellikle her nesnenin kullanacağı işlemlerin (prosedürlerin) tasarımda tanımlandığını anlattı. Mimari, kullanıcı arayüzü, veri yönetimi ve ağ programlama gibi parçalar bir yazılım gerçekleştirilirken sıfırdan oluşturulmaz: **hazır bir altyapı (framework) kullanılır** ve tanımlamalar bunun üzerinde geliştirilir. Tasarım aşamasında, fizibilitede seçilen altyapı yazılımları uygulamaya konacak hale getirilir.

## 2. Tasarımın Belgelendirilmesi

Bir nesneye yönelimli programın tasarım sürecinin belgelendirilmesinde yer alan önemli belgeler slaytta şöyle verilir (ekrandan, 00:20:00):

- Ayrıntılı UML sınıf şemaları: **vazgeçilmez**.
- Tasarımın ihtiyaçlarına göre şu belgelerin çeşitli bileşimleri de kullanılabilir:
  - Sözleşmeler
  - UML etkileşim şemaları (interaction diagrams)
    - Sıralama şemaları (sequence diagrams)
    - İşbirliği şemaları (collaboration diagrams)
  - UML etkinlik şemaları (activity diagrams)
  - UML durum diyagramları (state diagrams)

Sınıf diyagramları tasarım aşamasında tamamlanır. Etkileşim şemalarından hoca sequence diyagramlarını daha kullanışlı bulduklarını söyledi. **Sıralama şemaları** hangi nesnenin sırayla işleme girdiğini ve hangi işlemlerin gerçekleştiğini, işleme giren nesneler ve gerçekleştirilen işlemler üzerinden sırasıyla gösterir. **İşbirliği şemalarında** ise sıra yerine nesnelerin birbiriyle nasıl ilişkili olarak işleme girdiği gösterilir. **Etkinlik şemalarında** özellikle eş zamanlı etkinlikler daha iyi gösterilebilir; bu yüzden bir yazılımın tasarımı tanımlanırken hem sequence hem de aktivite diyagramları kullanılır. **Durum (state) diyagramları** da tasarımın belgelendirilmesinde kullanılır.

## 3. Tasarım Kalıpları: Genel Bakış

### 3.1 Tanım

Tasarım sırasında tanımlanması gereken bir başka unsur tasarım kalıplarıdır (design patterns); bunlar yazılım mimarisi kapsamında belirtilmelidir. Sorumlulukların atanmasında tasarım kalıpları yaygın olarak kullanılır ve nesne tasarımında sınıfları ve sorumlulukları belirlemeden önce tasarım kalıplarının incelenmesi gerekir.

**Tasarım kalıbı**, sıklıkla karşılaşılan, tanımlanabilir bir probleme sistematik bir çözüm getiren prensiplerdir. Hoca bunu "aklın yolu birdir" sözüyle açıkladı: çözülmüş bir problem varsa, bu problemin en mantıklı çözüm yolu bir tasarım kalıbında tanımlanır. Çok sayıda yazılımda kullanılan bir problem çözümü, genel kullanılan bir tasarım kalıbı olarak kaydedilir. Tasarım kalıplarına, probleme getirdiği çözümü belirten, kolay hatırlanan ve iletişimi kolaylaştıran isimler verilir.

### 3.2 Gang of Four ve Larman

Tasarım kalıplarının ilk başlangıcını Gamma, Helm, Johnson ve Vlissides gerçekleştirmiştir. Bu dört uzmanın ortaya koyduğu kalıplar **Gang of Four (GoF) kalıpları** olarak bilinir ve başlangıçta toplam **23** tanedir. Hoca, derste nesnelere sorumlulukları atarken temel alınan **genel sorumluluk atama prensipleri** üzerinde durulacağını ve bunun için özellikle Larman'ın kitabının temel alındığını söyledi; bu kitap nesneye yönelik yaklaşımın ilk ve en temel bilgilerini veren kaynak olarak anıldı.

<!-- BELİRSİZ: Whisper adları "Willisides", "Larmann/Lerman" diye yazmış; bağlamdan Vlissides ve Larman olarak düzeltildi. Slaytın küçük resmi okunamadı. -->

> **Ders sonrası not:** Hoca derste işlenen dokuz kalıptan "GoF kalıpları" diye söz etti. Yaratıcı, Bilginin Uzmanı, Az Bağımlılık, Denetçi, İyi Uyum, Çok Şekillilik, Yapay Sınıf, Dolaylılık ve Değişimlerden Korunma aslında Larman'ın **GRASP** (General Responsibility Assignment Software Patterns, genel sorumluluk atama kalıpları) adıyla topladığı kalıplardır. GoF'un 23 kalıbı ise Singleton, Factory Method, Observer, Adapter gibi kalıplardır. Hocanın "genel sorumluluk atama prensipleri" ifadesi büyük olasılıkla GRASP'a karşılık gelir.

### 3.3 Yeniden kullanılabilirlik bağlantısı

Hoca, yeniden kullanılabilirliğin (reusability) yazılım kalite faktörlerinin önemli biri olduğunu hatırlattı. Yazılımın tümünün ya da parçalarının başka yazılımlarda da kullanılabilmesi için yazılım kütüphaneleri ve paket programlar oluşturulur. Tasarım kalıpları da bunu destekler: çözülmüş bir problem tekrar tekrar düşünülmez. Nesneye yönelik yaklaşım zaten yeniden kullanılabilirliği desteklemek için oluşmuştur; tasarım kalıpları, alan modelleme ve alana özgü diller bu yaklaşımın yeniden kullanılabilirliği destekleyen kavramlarıdır.

## 4. Sorumluluk Atama Kalıpları

Bütün kalıplar, derste ve slaytlarda bir kahve satış sitesi örneği üzerinden açıklandı. Bu örnek, sistem analizi dersinin temel kitabında da yer alan kahve sitesi örneğidir.

### 4.1 Yaratıcı (Creator)

Slayttaki tanım (ekrandan, 00:25:00): Yaratıcı, bir sınıftan nesne yaratma sorumluluğunun kime verileceğini belirleyen kalıptır. Nesneye yönelik sistemlerde nesne yaratımı sıklıkla yapılan işlemlerden biridir; bu yüzden ilk kullanılan kalıplardandır. Yaratıcı kalıbına uygun davranıldığında tasarım **az bağımlı, daha anlaşılır ve yeniden kullanılabilir** olur.

Aşağıdaki koşullar geçerli olduğunda B sınıfına A sınıfından nesne yaratma sorumluluğu verilir:

- B, A nesnelerini içeriyorsa (kümeleme ilişkisi dahil)
- B, A nesnelerinin kaydını tutuyorsa
- B, A nesnelerini sıkı bir biçimde kullanıyorsa
- A'nın yaratılması için gerekli verilere B sahipse (B, A'nın yaratılmasında bilginin uzmanıysa)

**Örnek:** Kahve sitesinde Sipariş Kalemi nesnesini kimin yaratacağı sorulabilir. Uygulama modeli incelenirse bir Siparişin birçok Sipariş Kalemi içerdiği görülür. Bu yüzden **sipariş kalemlerini yaratma sorumluluğu Siparişindir**. Hoca bunu günlük hayatla ilişkilendirdi: bir alışveriş yaptığınızda bir siparişe karşılık bir fatura alırsınız; bu tek siparişin içerdiği satırların her biri bir sipariş kalemidir.

### 4.2 Bilginin Uzmanı (Expert)

Slayttaki tanım (ekrandan, 00:30:00): Nesnelere sorumlulukları atamanın temel prensibidir. Bir sorumluluğun o bilginin uzmanına, yani onu yerine getirecek veriye sahip olan sınıfa atanmasını tanımlar. Bir sorumluluğun atanmasında öncelikle uzman kalıbına uygun olarak bu bilgiye sahip olan yazılım sınıfı aranır. Henüz böyle bir sınıf yoksa kavramsal sınıflar incelenir ve uygun sınıf tasarım modeline alınır.

**Örnek:** Kahve sitesinde bir siparişin toplam bedelinin bilinmesi sorumluluğunu almak için en uygun sınıf **Sipariş** sınıfıdır. Ancak Sipariş tek başına bu bilgiye sahip değildir: sipariş kalemlerinin toplam bedellerini bilme sorumlulukları kalemlerin kendisindedir. Bir sipariş kaleminde birden fazla kahve yer alabilir; bu durumda Sipariş Kalemi, kendi bedelini hesaplayabilmek için **Kahve** nesneleriyle işbirliği yapmalıdır. Kısacası sorumluluk, onu yerine getirebilecek özelliğe sahip olan sınıfa verilir ve bu karar modelden alınan bilgiyle verilir.

### 4.3 Az Bağımlılık (Low Coupling)

Yapısal yaklaşımda modüller ve modüller arası ilişkiler, nesneye yönelik yaklaşımda ise nesneler arası ilişkiler önemlidir. Slayttaki tanım (ekrandan, 00:35:00): Az bağımlılık, diğer sınıflarda olabilecek değişimlerden etkilenmemeyi ve tekrar kullanılabilirliği tanımlayan tasarım kalıbıdır. **Bağımlılık**, bir birimin diğerlerine ne kadar bağlı olduğunu, haklarında ne kadar bilgi sahibi olduğunu ve işleri yerine getirebilmek için ne kadar diğer birimlere bağlı olduğunu gösteren bir ölçüttür. Fazla bağımlılık şu sebeplerle tercih edilmez:

- Bir sınıftaki değişim bağımlı diğer sınıfları da etkiler.
- Sınıfları birbirlerinden ayrı olarak (izole) anlamak zordur.
- Bağımlılıktan ötürü sınıfı yeniden kullanmak zordur.

Hoca modüller için örnek verdi: bir modülden diğerine çok fazla veri gönderiliyorsa, ortak veri kullanılıyorsa ya da modüller arasındaki parametre listesi çok uzuyorsa bu iyi değildir; veri gidiş gelişi en az olmalıdır. Aynı kural nesneler için de geçerlidir.

> **Ders sonrası not:** Altyazıda hoca "nesnelerin veya modüllerin birbiriyle çok sıkı ilişkide olmasını isteriz" diyor; bağlam ve slayt, modüller/nesneler **arası** sıkı ilişkinin istenmediğini gösterir. Büyük olasılıkla "istemeyiz" denmek istendi.

**Örnek (ekrandan, 00:35:00):** Kahve sitesi incelendiğinde hem Siparişin hem de Ödemenin Müşteri ile ilişkili olduğu görülür; gerçek dünyada da durum böyledir. Yaratıcı kalıbına göre Ödemeyi Müşterinin yaratması gerekir. Ancak bu durumda Müşteri, Ödeme hakkında bilgiye sahip olmalıdır. Oysa bu sorumluluk **Sipariş** sınıfına atanırsa bağımlılık azaltılmış olur. Bir çözümün uygulanması diğer bir kalıba tam olarak uygun olmayabilir; tasarım kalıpları birlikte kullanılarak en uygun tasarım çözümü oluşturulmalıdır.

### 4.4 Denetçi (Controller)

Denetçi, kullanıcı arabiriminin arkasında durarak sistem olaylarını alma ve kontrol etme sorumluluğunu alacak bir sınıf için belirlenir. Her bir kullanım senaryosunu temsil eden bir sınıf denetçi olarak atanabilir. Uygulamalardaki window, applet, frame gibi yapılar denetçi sınıf **değildir**; bunlar yalnızca sistem olaylarını ilgili denetçiye aktarır. Denetçi nesneleri sistem olaylarını algıladıktan ve kontrol işlemlerini yaptıktan sonra olayları ilgili işleri yapacak nesnelere yönlendirir.

<!-- BELİRSİZ: Bu slayt ana ekranda karede yakalanmadı; metin altyazıdan ve slayt küçük resminden kuruldu. Altyazıdaki "window, update, frame" ifadesi küçük resimden "window, applet, frame" olarak düzeltildi. -->

### 4.5 İyi Uyum (High Cohesion)

Coupling ve cohesion iyi tasarımın kurallarındandır ve birlikte çok kullanılır. Modüler yaklaşımda modüllerin kendi içindeki elemanlar arasında sıkı, modüller arasında zayıf ilişki olması istenir. Aynı şey nesneler için de geçerlidir: nesnelerin özellikleri ve gerçekleştirdikleri işlemler birbiriyle sıkı ilişkide olmalı, nesneler arasındaki ilişki ise temel işlemi gerçekleştirecek şekilde, çok karmaşık olmadan kurulmalıdır.

Slayttaki tanım (ekrandan, 00:40:00): Nesneye yönelik bir programda nesneler, kendilerine atanan sorumlulukları yerine getirmekle yükümlüdür. Bir sınıfa atanan sorumlulukların birbiriyle ilgili olması ve belirli bir konuya yoğunlaşması beklenir. Eğer bir sınıf çok fazla iş yapıyorsa ve sorumlulukları birbirinden farklıysa sınıfta uyum kötüdür. Bu durumda sınıfın anlaşılırlığı azalır, tekrar kullanımı zorlaşır; birlikte çalıştığı çok fazla sınıf olacağı için sınıf değişimlerinden daha çok etkilenir. Karmaşıklığın idare edilebilmesi için sorumluluklar, sınıf içinde iyi uyum olacak şekilde atanmalıdır.

**Örnek (ekrandan, 00:40:00):** Az bağımlılık kalıbında incelenen durum iyi uyum kalıbı için de geçerlidir. Gerçek hayatta ödemeyi Müşteri gerçekleştirir. Ancak uygulama açısından bakıldığında Ödeme hakkında bilginin uzmanı Sipariş sınıfıdır. Müşterinin Ödeme ile ilgili sorumlulukları taşıması yerine, zaten bilgiye sahip olan Sipariş sınıfının bu sorumluluğu taşıması iyi uyum kalıbına uygun olacaktır.

> **Hocanın vurgusu:** "High cohesion, low coupling" olarak aklınızda kalabilir; bunlar iyi tasarımın kurallarıdır ve tasarım kalıplarıyla kontrol altına alınması öğütlenir.

### 4.6 Çok Şekillilik (Polymorphism)

Birbiriyle ilgili ancak tiplere göre değişiklik gösteren davranışları tasarlarken çok şekilli metotlar kullanmak, değişen durumlara kolaylıkla uyum sağlayabilecek bileşenler yaratmayı sağlar. Tiplere bağlı alternatif durumlarda ilgili metot koşullu deyimlerle test edilerek de çağrılabilir; çok şekillilik kalıbında ise davranışın değişebileceği tiplere sorumluluk çok şekilli metotlar kullanılarak atanır.

**Örnek:** Bir alışveriş sitesinde kredi kartından onay almak için farklı programlar kullanılabilir ve gelecekte sisteme yeni bir kredi kartı tipi de eklenebilir. Onay programları arasında bir arayüz oluşturulur; tüm kredi kartı tiplerinde yer alan ve aslında aynı işi yapan onay fonksiyonları çok şekillidir. Sistem tek bir kredi kartı sistemi kullansaydı çok şekilliliğe gerek kalmazdı.

### 4.7 Yapay Sınıf (Pure Fabrication)

Slayttaki tanım (ekrandan, 00:45:00): Daha önce bahsedilen uzman kalıbının getirdiği çözümler, iyi uyum ve az bağımlılık kavramlarıyla çelişebilir. Bu durumda bağımlılıkları azaltıyorsa ve tekrar kullanılabilirliği artırıyorsa, gerçek dünyada var olmayan yapay sınıflar yazılımda yer alabilir.

Gerçek dünyadaki varlıklar ile onları yazılımda temsil eden unsurlar arasında benzerlik vardır. Bazı durumlarda sorumlulukların atanması diğer kalıplara ters düşebilir; böyle durumlarda temel olarak birbirine benzeyen işlevler bir sınıf olarak toplanarak gerçek dünyada var olmayan yapay sınıflar yaratılabilir.

Nesneye yönelik sistem tasarımında yazılım sınıflarını tasarlamak için gerçek dünyadaki kavramlardan yararlanılır. Ancak uyum ve bağımlılık gibi problemlerin üstesinden gelmek için benzer işlevler, gereğinden fazla kullanılmamak şartıyla bir sınıf içinde toplanabilir. Slayta göre işlevsel programcılar sistemi gerçek dünya varlıklarına ayırmak yerine işlevlere göre ayırır. Çok fazla kullanılan yapay sınıflar yazılımı gerçek dünyadan uzaklaştırır ve anlaşılırlığını azaltır; ayrıca sınıflar arası bağımlılığı da artırır.

> **Hocanın vurgusu:** Yapay sınıfları gereğinden fazla kullanmamak esastır.

### 4.8 Dolaylılık (Indirection)

Dolaylılık, ara birim kavramıdır; kolaylıkla değişebilecek yapılar arasında yeniden kullanılabilirliği artırır. Bileşenler ya da servisler arasındaki sorumluluklar bir **ara birim nesnesine** atanarak dolaylı (indirect) bir yapı sağlanır. Uygulamalarda bu dolaylılığı ara birim nesneleri sağlar; çok şekillilik özelliği de olan bu nesneler dış değişimlerden etkilenmemeyi sağlar.

**Örnek:** Kahve sitesinde kredi kartı onaylama hizmeti dışarıdan alınır ve farklı kredi kartlarının farklı onay mekanizmaları vardır. Sistem, onay işini dolaylı olarak başka bir servise, başka bir bileşene aktarmış olur.

### 4.9 Değişimlerden Korunma (Protected Variation)

Slayttaki tanım (ekrandan, 01:40:00): Dikkat edilmesi gereken tasarım prensiplerinin sonuncusu değişimlerden korunmayı esas alır. Bir sistemdeki her bir alt sistemde, hatta her bir nesnede değişimler ve kararsızlıklar olabilir; bunların diğer birimlere etkisi minimum seviyede tutulmalıdır. Birimlerdeki değişikliklerin birbirlerini en az etkilediği tasarım, değişimlere açık ve kararsız noktaların etrafında **sorumlulukların ara yüzlere atanmasıdır**. Bu sayede birimler değişimlerden korunabilir, kararlı sistemler oluşturulabilir.

**Örnek:** Dolaylılık kalıbında örnek olarak verilen çok şekilli arabirim nesneleri, kahve sitesi sistemini dışta olabilecek değişimlere karşı korur. Kredi kartı onay sistemleri değişse de, yenileri de eklense de tasarlanan sistem bu değişimlerden etkilenmeyecektir; sistem için gerekli olan onay alma sorumluluğu gerçekleştirilecektir.

### 4.10 Bölümün özeti

Hoca tasarım sırasında oluşturulması gereken belgeleri tekrar sıraladı: UML etkileşim şemalarından sequence diyagramları, aktivite diyagramları ve state diyagramlarının kullanılması öğütlenir; veri açısından da tasarım sınıf diyagramlarının hazırlanmış olması gerekir. Yeniden kullanılabilirliği sağlamak için tasarım kalıplarının kullanılması öğütlenir. İşlenen kalıplar: yaratıcı, bilginin uzmanı, az bağımlılık, denetçi (sistem olaylarını algılayıp kontrol işlerini yaptıktan sonra olayları ilgili nesnelere yönlendiren kalıp), iyi uyum (nesnenin kendi içindeki uyumu), çok şekillilik, yapay sınıf, dolaylılık ve değişimlerden korunma.

## 5. Sınav Uygulama Sorusu: e-kuaförüm.com Bilgi Sistemi

Aradan sonra sınavda sorulan, analizle ilişkili uygulama sorusunun çözümü üzerinden geçildi. İstenen çıktılar: use case diyagramı, use case belgesi ve kavramsal sınıf diyagramı. Sorunun metni ve çözümü aşağıdaki "Örnek Sorular" bölümünde ayrıntılı verilmiştir. Hoca, çözümün akla gelebilecek karmaşık bir yapı olmadığını, en basit halin çözüm olarak karşımıza çıktığını vurguladı.

**Soru:** Bir öğrenci, sınıf diyagramında berber ve kuaför gibi sınıfların içine metot olarak ne yazacağını bilemediğini söyledi. **Cevap:** Hoca, kavramsal sınıf diyagramında metotların olmadığını, yalnız sınıfın adının, özelliklerinin ve sınıflar arasındaki ilişkilerin gösterildiğini; işlemlerin tasarımda netleştirildiğini söyledi.

## 6. Nesne Modelleme Tekrarı: Kahve Sitesi

### 6.1 Nesneye yönelik analizin hatırlatılması

Unified Process modelinde nesneye yönelik yaklaşım kullanılır. UML sınıf diyagramlarında sınıfın adı, özellikleri ve sınıfta gerçekleşen işlemler (metotlar) belirtilir; sınıflar arasındaki ilişkiler (bağlantı/association) ve bağlantının tipi gösterilir. Kümeleme türlerinden aggregation ve composition ayrımı, elemanların tek başına bir anlamı olup olmamasına (yoksa ancak bütünün içinde mi anlam taşıdıklarına) göre yapılır. Genelleştirmeye örnek olarak daha önce kurumsal müşteri ve şahsi müşterinin müşteri olarak genelleştirilmesi verilmişti; kuaför örneğinde de kuaför, kalfa ve çırak çalışan olarak genelleştirildi.

Kullanım senaryosunda aktörlerin sistemi nasıl kullanacağı belirtilir. Bütün ayrıntıları tek bir kullanım senaryosunda göstermek yerine genel bir senaryo yapılıp alt ayrıntılar ayrı senaryolarda gösterilebilir. **Aktör**, senaryoyla etkileşime geçen kimse ya da şeydir: sistemin kullanıcısı bir insan ya da başka bir sistem olabilir ve senaryodan kullanılabilecek bir sonuç bekler. Aktörler use case diyagramında çöp adamla gösterilir; aktör özellik ve işlemlere de sahip olabileceği için normal bir sınıf şeklinde de gösterilebilir (ekrandan, slayt küçük resmi, 01:30:00). Bir senaryo başka bir senaryoyla ilişkili olabilir; kullanım senaryoları arasındaki ilişkiler include, extend ve özelleştirmedir.

### 6.2 Kahve sitesi problemi

Slayttaki problem tanımı (ekrandan, 01:30:00): İnternette alışveriş için uygulamanın yapısı, teknik altyapısı ve alışveriş sırasında gerçekleştirilen işlemler üzerinde durulmuştur. Sitenin genel yapısı:

- Site, kahve satışı yapmaktadır.
- Hazır kahveler satın alınabileceği gibi, müşteri dilediği çeşitleri harmanlayarak özel kahve siparişi de verebilmektedir.
- Bir alışverişte birden fazla çeşit kahve siparişi verilebilir.
- Siparişi tamamlamak için müşteri teslimat ve ödeme formlarını doldurur.
- Kredi kartı ve banka havalesi ile ödeme yapılabilir.
- Arka planda müşterinin bilgileri ve ödemesi doğrulanır.
- İstenen özelliklerdeki sipariş, kahve sağlayan depodan alınır, fatura basılır ve müşteriye gönderilir.

Adımlar şöyle anlatıldı: müşteri bir hazır kahve seçer (özellikleri ve fiyatı sitede görülebilir) ya da istediği kahveleri harmanlayarak özel kahve oluşturur; alışveriş tekrarlanarak devam eder; müşteri siparişini verir, teslimat ve fatura bilgilerini girer ve ödeme ayrıntılarını içeren formu doldurur; istenen kahve depodan alınır, faturası basılır ve müşteriye gönderilir.

### 6.3 Kullanım senaryosu ve senaryo belgesi

Hocanın sözlü anlatımına göre kullanım senaryosu diyagramında Müşteri ve Depo aktörleri vardır. Müşteri önce bilgi girişiyle kendini tanıtır, kahve seçimini yapar ve sipariş verir; sipariş verme bilgi girişini içerir (include). Özel kahve oluşturma, kahve seçimine bağlı bir uzantı (extend) işlemidir. Sipariş teslimatında Depo devreye girer ve sipariş teslimatıyla fatura basılır.

<!-- BELİRSİZ: Kahve sitesinin use case diyagramı karede yakalanmadı; ilişkiler altyazıdan aktarıldı. -->

"Sipariş verme" senaryo belgesi (sözlü): birincil aktör müşteri; kahve sitesi ve depo diğer aktörler (ilgililer). Ön koşul: müşteri alışveriş sitesine girebilmeli. Son koşul: ödeme ve teslimat bilgileri doğrulanmıştır. Akış: müşteri sipariş etmek istediğini bildirir, teslimat bilgilerini girer, ödeme şeklini seçer ve bunlar müşteri hesap bilgileriyle birlikte kaydedilir.

### 6.4 Kavramsal sınıf diyagramı

Hocanın anlatımına göre Müşteri ile Kahve Sitesi arasında ilişki vardır. Sipariş kalemi bir ya da daha çok kahveden oluşur; sipariş kalemi özel kalem ya da standart kalem olabilir. Bir sipariş en az bir sipariş kaleminden oluşur. Bir siparişi mutlaka bir müşteri vermiş olmalıdır (sıfır olamaz), ama bir müşteri hiç sipariş vermemiş olabilir. Siparişle fatura arasında ve siparişle ödeme arasında da ilişki vardır.

> **Ders sonrası not:** Hoca Müşteri-Sipariş ilişkisinde sipariş tarafının "sıfırdan bire kadar" olduğunu söyledi. Bir müşteri birden çok sipariş verebildiğine göre, büyük olasılıkla sipariş tarafındaki çokluk `0..*` (sıfırdan çoka) olmalıdır; müşteri tarafı `1`'dir.

### 6.5 Tasarım sınıf diyagramı

Kahve sitesinin tasarım sınıf diyagramı karede şöyle görünür (ekrandan, 01:35:00):

| Sınıf | Özellikler | İşlemler |
|---|---|---|
| KahveSitesi | adres : String, isim : String | |
| KahveKatalog | | tanimAl() |
| Kahve | tanim : String, fiyat : Money, id : int | bul() |
| Denetçi | | kahveEkle() |
| Sipariş | tamamlandı : boolean | tamamlan(), siparişEkle(), ödemeYap(), toplamAl(), faturaBas() |
| SiparişKalemi (soyut, italik) | miktar : int | |
| StandartKalem | stdFiyat : Money | altToplamAl() |
| ÖzelKalem | newAttr : int | altToplamAl() |
| Fatura | id : int, tarih : Date | |
| Ödeme | miktar : Money, tarih : Date | |

İlişkiler:

- KahveSitesi -> KahveKatalog (1); KahveKatalog -> Kahve (1..*).
- KahveSitesi -> Denetçi (1); Denetçi -> Sipariş (1..*).
- Sipariş -> SiparişKalemi (1..*); SiparişKalemi -> Kahve (1).
- StandartKalem ve ÖzelKalem, SiparişKalemi'nin alt sınıflarıdır (genelleştirme).
- Sipariş -> Fatura (1); Sipariş -> Ödeme (1).
- Denetçi ve Sipariş'ten Kahve'ye kesikli (bağımlılık) oklar vardır.

Kahveye uygulanacak işlemler de belirtilir: standart kalem için alt toplamı alma, özel kalem için alt işlemler. Kavramsal diyagramdan farklı olarak burada **Denetçi** yeni bir sınıf olarak eklenmiştir: bu bir tasarım kalıbıdır ve tasarım sırasında kullanılması gerektiği için tasarım diyagramına konmuştur.

### 6.6 Etkileşim diyagramları

**Etkileşim**, bir nesnenin üzerine düşen sorumluluğu yerine getirmek için diğer bir nesneye mesaj göndermesidir. Etkileşim diyagramları denince collaboration ve sequence diyagramları akla gelir; etkileşim diyagramı olarak daha çok sequence diyagramları kullanılır. Ardışıl (sequence) diyagramlarda mesajlar sıralı gösterilir: önce bir nesne işleme girer, şu mesajlarla şu işlemler gerçekleşir, sonra ikinci nesne için şu işlemler gerçekleşir. Analiz ve tasarım sırasında gerçekleştirilen yapıların tümü nesne modeli olarak tanımlanır.

Özel kahve siparişinin ardışıl diyagramında da gerçekleşen işlemleri kontrol eden bir Denetçi vardır. Özel kahve siparişi verildiğinde her bir sipariş için sipariş kalemleri oluşur; burada bir döngü vardır ve kahve katalogda işlem gerçekleşir.

<!-- BELİRSİZ: Özel kahve siparişinin ardışıl diyagramı karede ana ekranda yakalanmadı; yalnız anlatım aktarıldı. -->

## 7. Tasarım Diyagramlarında Kalıpların Kullanımı

Hoca, ürün ekleme (sipariş verme sırasında kahve ekleme) işleminde üç tasarım kalıbının kullanıldığını gösterdi: **Denetçi, Uzman, Yaratıcı**. Kahve ekleme işlemi denetçi tarafından denetlenir; kahve tanımı kahve kataloğundan alınır; sipariş, sipariş kalemini yaratır.

"Ürün ekleme işleminin ardışıl diyagramı" karede şöyle görünür (ekrandan, 00:55:00):

- Nesneler (soldan sağa): `:Denetçi`, `:KahveKatalog`, `:Map<Kahve>`, `:Sipariş`, `siparişKalemleri: List<SiparişKalemi>`.
- Mesajlar:

```text
kahveEkle(id, miktar)            dışarıdan  -> :Denetçi
2: tanim = tanimAl(id)           :Denetçi    -> :KahveKatalog
3: tanim = bul(id)               :KahveKatalog -> :Map<Kahve>
4: siparişEkle(tanim, miktar)    :Denetçi    -> :Sipariş
5: yarat(tanim, miktar)          :Sipariş    -> sk: SiparişKalemi (yeni nesne)
6: ekle(sk)                      :Sipariş    -> siparişKalemleri
```

- Diyagramdaki notlar: "Denetçi" notu ilk mesaja (kahveEkle), "Uzman" notu tanimAl/bul adımlarına, "Yaratıcı" notu siparişEkle ve yarat adımlarına bağlanmıştır.

Hocanın anlatımıyla: denetçi (controller) devrededir; her eklenen kahvenin miktarı alınır ve fiyatı kahve kataloğundan alınır. Siparişe bir kalem eklendiğinde Yaratıcı kalıbı devreye girer ve sipariş kalemleri ile sipariş sınıfı arasında bir döngü şeklinde işlem gerçekleşir. Siparişin yaratılması sırasında da yaratıcı kalıbı kullanılır.

## 8. Etkinlik Şemaları Tekrarı

### 8.1 Semboller

Slayttaki "Çizim kuralları ve örnek çizim" (ekrandan, 01:45:00):

| Sembol | Anlamı |
|---|---|
| Ok | Denetim akışı |
| Dolu daire | Etkinlik başlangıcı |
| Girintili beşgen (bayrak) | Sinyal alma / olay (event) kabul etme |
| Köşeleri yuvarlatılmış dikdörtgen | Eylem |
| Eşkenar dörtgen | Karar verme (if) |
| Kalın çizgi | Eşgüdüm |
| Halka içinde dolu daire | Etkinlik sonu |
| Çıkıntılı beşgen | Sinyal gönderme |

### 8.2 Havalimanı check-in örneği

Karedeki diyagramın akışı (ekrandan, 01:45:00):

```text
[Sinyal alma] Yolcu check-in bankosuna gelir.
   -> [Eylem] Yolcu check-in yapar.
   -> [Karar] [else] -> Etkinlik sonu
              [check-in başarılı] -> Eşgüdüm (fork)
                   -> Yolcu uçağa biner        (paralel)
                   -> Bagajlar uçağa yüklenir  (paralel)
              -> Eşgüdüm (join)
   -> [Eylem] Uçak piste yönelir
   -> Etkinlik sonu
```

Yeni bir yolcunun check-in bankosuna gelmesi bir sinyal alma, yani olayın kabulüdür. Yolcunun check-in yapması bir eylemdir. Ardından bir karar vardır: check-in başarılı değilse etkinlik sona erer (tekrar başlanacaktır). Başarılıysa yolcu bagajını verir; bagaj uçağa yüklenirken yolcu da uçağa binmek için gerekli işlemleri yapar. Bu iki iş aynı anda yürür ve kalın eşgüdüm çizgisiyle paralel bölümlere ayrılır. İki iş de bittiğinde (bagajlar yüklendi, yolcular bindi) uçak kapısı kapanır, uçak piste yönelir ve etkinlik sona erer.

Kurallar:

- Etkinlik diyagramında bir başlangıç işareti olmalıdır; bu örnek sinyal alma işlemiyle başlar.
- Sinyal alma sembolünde akış, sinyali alana kadar bekler; zamanlı olaylar da bununla gösterilebilir.
- Eşgüdüm çizgisine varan akış, çizgiyi geçmeden önce diğer akışların hepsini bekler. Örneğin yolcuların hepsi bindiği halde bagaj yüklemesi bitmemişse, o da bitene kadar sonraki aşamaya geçilmez. **Fork** ve **join**, eşgüdümün başlangıcı ve bitişidir.
- Birden fazla aktör ve aktörler arası bilgi akışı gösterilmek isteniyorsa farklı alanlar (kulvarlar) oluşturulabilir; örneğin yer hizmetleri bölümünde ve müşteri hizmetleri bölümünde gerçekleşen işlemler ayrı alanlarda gösterilir.

> **Hocanın vurgusu:** Kendi uygulamalarınız (projeleriniz) için de mutlaka aktivite diyagramı çizmeniz gerekir.

## 9. Yazılım Kalitesi ve Kalite Modelleri

### 9.1 Yazılım kalitesi nedir?

Bu bölümde "Yazılım Kalite Yönetiminde Yeni Yaklaşımlar ve Araştırma Alanları" başlıklı bir sunum kullanıldı (ekrandan, 01:50:00). Sunumun kapağında konular yazılım kalite yönetimi ve kalite özellikleri, yazılım risk yönetimi (risk belirleme ve risk önleme) ve yazılım konfigürasyon yönetimi olarak sıralanır; derste yalnız kalite özellikleri ve ölçütleri işlendi.

Hoca yazılım kalitesini şöyle açıkladı: faydalı bir ürün yaratmışsak ve bu ürünün belirli değerleri için ölçülebilir özelliklerini tanımlayabiliyorsak yazılım kalitesinden söz edebiliriz. Geliştirilen ürünün ne büyüklükte olduğu, yeniden kullanılabilirlik özelliği, ne kadar kullanışlı olduğu, hangi işi gerçekleştirdiği, hangi alanda hizmet verdiği, performansı gibi sorulara ölçütlerle (metriklerle) cevap verebiliyorsak yazılım kalitesinden söz edilir. Slaytta İngilizce tanım da yer alır: yazılım kalitesi, onu üretenlere ve kullananlara ölçülebilir değer sağlayan faydalı bir ürün yaratacak biçimde uygulanan etkin bir yazılım sürecidir (ekrandan, slayt küçük resmi, 01:50:00).

### 9.2 McCall'un kalite üçgeni

McCall'un kalite üçgeni (McCall's Triangle of Quality) üç bakış açısını ayırır (ekrandan, 01:55:00 ve 02:00:00):

| Bakış açısı | Kalite özellikleri |
|---|---|
| Ürün işletimi (Product Operation) | Correctness (doğruluk), Reliability (güvenirlik), Efficiency (etkinlik), Integrity (bütünlük), Usability (kullanışlılık) |
| Ürün revizyonu (Product Revision) | Maintainability (bakım yapılabilirlik), Flexibility (esneklik), Testability (test edilebilirlik) |
| Ürün geçişi (Product Transition) | Portability (taşınabilirlik), Reusability (yeniden kullanılabilirlik), Interoperability (birlikte çalışabilirlik) |

**Ürün işletimi**, yazılım çalıştığı anda kullanıcının baktığı taraftır:

- **Doğruluk (correctness):** aldığım yazılım ürünü doğru işi yapıyor mu?
- **Güvenirlik (reliability):** bu doğruluk ne kadar güvenilirdir? Hoca bunun güvenlik değil **güvenirlik** olduğunu vurguladı; belli bir kullanım süresindeki hata oranı olarak düşünülebilir (örneğin ürün %99 hatasızlık seviyesiyle mi, %95 seviyesiyle mi çalışıyor).
- **Kullanışlılık (usability):** ürün kullanıcı dostu (user friendly) mu, kullanıcı özelliklerine uygun mu?
- **Bütünlük (integrity):** ne kadar güvenli, bütünlüğü ne kadar sağlıyor?
- **Etkinlik (efficiency):** performans, cevap süresi, etkin veri kullanımı gibi değerler.

Hoca bu özelliklerin hepsinin ölçülebilir olmadığını, çoğunun tanımsal olduğunu belirtti: ürün doğru, ama ne kadar ve ne anlamda doğru? Kullanım kolaylığı var, ama bu sayısallaştırılabiliyor mu?

**Ürün geçişi**, ürünü bir yerden bir yere taşırken önemli olan özelliklerdir: taşınabilirlik, yeniden kullanılabilirlik ve birlikte çalışabilirlik. Birlikte çalışabilirliğe (interoperability) hoca şu örneği verdi: bir kurumda bir muhasebe programı varken sonradan bir ERP yazılımı alındığında, muhasebe programı bu yazılımla birlikte çalışabilecek mi? Bu özellikler ürünün çalıştırılmasını sağlayanlar için önemlidir.

**Ürün revizyonu**, ürüne bakım yapacak kişiler için önemlidir: yazılımın kurallarında değişiklik olduğunda ya da yazılıma eklemeler yapılacağında bakım yapılabilirlik, esneklik ve test edilebilirlik önem kazanır.

### 9.3 Diğer kalite modelleri

**ISO 9126** yazılım kalite özelliklerini de tanımlar. Hoca McCall modelini daha çok kullanmalarının sebebini, bu modelin özellikleri kullanıcı, çalıştırıcı ve bakım yapan açısından bölümlemesi olarak açıkladı. ISO 9126 ise kalite özelliklerini **iç** ve **dış** kalite özellikleri diye ayırır: dış kalite özellikleri dışarıdan, kullanıcılar tarafından bakılan özelliklerdir; iç kalite özellikleri ise yazılımın çalıştırılmasını sağlayanlar ve bakım yapanlar gibi içeriden bakanları ilgilendirir. Bu standartta bütün kalite özellikleri sıralanır ve açıklanır.

David Garvin'in önerdiği kalite boyutları (slayttaki "Quality Dimensions" listesi, ekrandan, slayt küçük resmi, 01:50:00): performans kalitesi (performance quality), özellik kalitesi (feature quality), güvenirlik (reliability), uyumluluk (conformance), sağlamlık (durability), servis yeteneği (serviceability), görünüş (aesthetics) ve algı (perception). Hoca görünüşü ergonomik özellikler, renkler ve ekran yapılarının özellikleri gibi örneklerle açıkladı. Derste ağırlıklı olarak ISO 9126 ve McCall'un kalite üçgeni üzerinde durulacağı söylendi.

> **Ek bilgi (derste anlatılmadı):** ISO 9126 standardının yerini büyük olasılıkla 2011'de yayımlanan ISO/IEC 25010 (SQuaRE serisi) almıştır. Bu yeni modelde de kalite, ürün kalitesi ve kullanımdaki kalite gibi bakış açılarına göre özelliklere ayrılır.

### 9.4 McCall kalite modeli: özellikler ve ölçütler

McCall'a göre kalite özelliklerinin çoğu tanımsaldır ve bunları sayısal bir ölçeğe getirmek zordur. Bu yüzden her kalite özelliği, yazılımı daha sayısal olarak ölçebilen **kalite ölçütleriyle (kriterleriyle)** eşleştirilir. Bir ölçüt birden fazla özelliği etkileyebilir. Bir özellik, ilişkili ölçütlerin o özellikteki önemine göre farklı katsayılarla çarpılıp toplanmasıyla hesaplanır. Hocanın sözlü örneği: etkinlik kalite özelliğine $Q_1$ denirse ve bu özellik çalışma etkinliği ($M_1$) ile bellek etkinliğine ($M_2$) bağlıysa,

$$Q_1 = c_1 M_1 + c_2 M_2$$

biçiminde, ölçütlerin yüzdeleri (ağırlıkları) kadar bir toplam oluşturulur. Katsayıların değerleri derste verilmedi.

Karedeki "Figure 1.5 McCall's quality model" şekli sol tarafta özellikleri, sağ tarafta ölçütleri gösterir (ekrandan, 02:05:00). Hocanın anlatımı ve şekil birlikte okunduğunda eşleşme şöyledir:

| Kalite özelliği | İlişkili ölçütler |
|---|---|
| Correctness (doğruluk) | Traceability (izlenebilirlik), Completeness (tamlık), Consistency (tutarlılık) |
| Reliability (güvenirlik) | Consistency, Accuracy (kesinlik), Error tolerance (hata toleransı) |
| Efficiency (etkinlik) | Execution efficiency (çalışma etkinliği), Storage efficiency (bellek etkinliği) |
| Integrity (bütünlük) | Access control (erişim kontrolü), Access audit (erişim denetimi) |
| Usability (kullanışlılık) | Operability (işletilebilirlik), Training (eğitim), Communicativeness (iletişim) |
| Maintainability (bakım yapılabilirlik) | Consistency, Simplicity (basitlik), Conciseness (özlülük), Self-descriptiveness (kendini açıklama), Modularity (modülerlik) |
| Testability (test edilebilirlik) | Simplicity, Instrumentation, Self-descriptiveness, Modularity |
| Flexibility (esneklik) | Self-descriptiveness, Expandability (genişletilebilirlik), Generality (genelleştirilebilirlik), Modularity |
| Portability (taşınabilirlik) | Self-descriptiveness, Modularity, Software system independence, Machine independence |
| Reusability (yeniden kullanılabilirlik) | Self-descriptiveness, Generality, Modularity, Software system independence, Machine independence |
| Interoperability (birlikte çalışabilirlik) | Modularity, Communications commonality, Data commonality |

<!-- BELİRSİZ: Şekildeki oklar yoğun ve kesişiyor; tablodaki bazı eşleşmeler (özellikle Reliability, Maintainability, Testability, Flexibility ve Portability satırlarındaki tek tek oklar) şeklin genel görünümü, hocanın anlatımı ve McCall modelinin bilinen hali birlikte değerlendirilerek yazıldı. -->

Hocanın açıklamalarından öne çıkanlar:

- **Doğruluk:** istenilenlerin tamamını yapıyor mu (tamlık), tutarlı mı, izlenebilir mi ve istenenlere uyumlu mu?
- **Güvenirlik:** yine tutarlılık, hata toleransı ve kesinlik (doğruluk) ile ilişkilidir: istenen işi yapıyor mu, hata toleransı nedir?
- **Etkinlik:** çalışma etkinliği (performans) ve bellek etkinliği olmak üzere iki ölçüte bağlıdır.
- **Bütünlük:** erişim kontrolü ve erişim denetimi; yetkisiz kişiler sisteme girebiliyor mu?
- **Kullanışlılık:** istenen işlemleri gerçekleştirebilme (işletilebilirlik), kullanıcıların rahat kullanması için eğitim verilmesi, öğrenilebilirlik ve iletişim.
- **Bakım yapılabilirlik:** yazılımın mümkün olduğunca basit hazırlanmış olması, kendi kendini tanımlayabilmesi (örneğin açıklamaların bulunması), modülerlik ve tutarlılık.
- **Test edilebilirlik:** yine basitlik, kendi içindeki açıklamalar ve modülerlik gerekir. Hoca, bakım yapılabilirliğin test edilebilirliği de içerdiğini söyledi.
- **Esneklik:** genelleştirilebilirlik ve modülerlik esnekliği getirir.
- **Yeniden kullanılabilirlik:** başka yerlerde de kullanılabilmesi için yazılım basit olmalı, çok karmaşık algoritmalar içermemeli; genelleştirilebilirlik, modülerlik, yazılım sisteminden bağımsızlık ve makineden (donanımdan) bağımsızlık gerekir.
- **Birlikte çalışabilirlik:** başka yazılımlarla çalışabilmek için iletişim ve veri ortaklığı (genelleştirilmiş iletişim değerleri) ve modülerlik gerekir.

**Soru:** Bir öğrenci bu ölçütlerin nesnel değil öznel göründüğünü, örneğin basitliğin kişiye göre değişebileceğini sordu. **Cevap:** Hoca bunun doğru olduğunu, bu ölçütlerin de tam sayısal olmadığını, bu yüzden başka ölçümlerle sayısallaştırıldıklarını söyledi; örneğin basitlik algoritma karmaşıklığı ya da döngüsel karmaşıklık ile ölçülebilir.

> **Ek bilgi (derste anlatılmadı):** Döngüsel karmaşıklık (cyclomatic complexity), McCabe'in önerdiği ve bir programın kontrol akış çizgesindeki bağımsız yolların sayısını veren ölçüttür; $V(G) = E - N + 2P$ formülüyle hesaplanır ($E$ kenar, $N$ düğüm, $P$ bağlı bileşen sayısı). Değer arttıkça kodun anlaşılması ve test edilmesi zorlaşır.

## 10. Kalite ile Tasarım Kalıpları Arasındaki İlişki

**Soru:** Bir öğrenci, kalite özelliklerinin tasarım kalıplarıyla da ilişkili olup olmadığını, tasarım kalıpları kullanılınca kalitenin artıp artmadığını sordu. **Cevap:** Hoca, tasarım kalıplarının kullanılmasının kaliteyi iyi yönde etkilediğini, ama ölçütlerle doğrudan bir ilişkisi olmadığını söyledi. Bir yazılımın kalitesini ölçmek için ölçütlere bakılır; bu ölçütlerin iyi olmasını sağlamak için de tasarım kalıpları kullanılır. Tasarım kalıpları yazılım kalitesini iyileştirici niteliktedir.

Hoca ardından sınıfa, tasarım kalıplarını anlatırken hangi kalite özelliğinden sürekli bahsettiğini sordu (sorunun çözümü "Örnek Sorular" bölümündedir). Cevap **yeniden kullanılabilirlik (reusability)** idi. Tasarım kalıpları ve daha genel olarak nesneye yönelik yaklaşım yazılımın yeniden kullanılabilirliğini artırır. Yeniden kullanılabilirliği artırmak için tasarım kalıpları kullanılır; bunun öncesinde nesneye yönelik yaklaşım kullanılır, alan modelleme yapılır ve alana özgü diller geliştirilir.

**Soru:** Bir öğrenci, yeniden kullanılabilirlik arttıkça bakım yapılabilirliğin de arttığını düşündüğünü söyledi. **Cevap:** Hoca katıldı: McCall yeniden kullanılabilirliği ürün geçişi tarafına koymuştur, ama bu özellik ürünün bakımını yapabilmek için ürün revizyonu tarafında da yer alabilir. Yeniden kullanılabilirlik varsa bakım yapılabilirlik de iyileşir. Hoca, slayttaki şekli hazır aldığını, tahtada çizerken yeniden kullanılabilirliği her iki tarafa da yazdığını belirtti.

## Örnek Sorular

### Soru 1: e-kuaförüm.com web sitesi ve bilgi sistemi (sınav uygulama sorusu)

Kaynak: (ekrandan, 01:15:00)

Soru metni (slayttan):

> Yeni açtığımız unisex kuaför için web sitesi de olan bir bilgi sistemi kurulmasına ihtiyacımız vardır. Erkek ve kadın bölümlerimiz ayrı olup, erkek bölümünde berberlerimiz, kadın bölümünde kuaförlerimiz çalışmaktadır. Ancak biz bunların hepsine "saç tasarım uzmanı" diyoruz. Uzmanlarımızın yanı sıra, kalfalarımız ve çıraklarımız da vardır. Kalfalar yoğun zamanlarda fön yapma ve dip boya yapma gibi kısıtlı işlemler yapsalar da kesim ve gelin başı gibi zor işlemler yapmamaktadır. Çıraklar ise hiçbir şekilde işlem yapmamakta, ancak getir-götür işleri gibi görevler üstlenmektedir.
>
> Müşterilerimizin İnternet'ten randevu alabilmelerini isteriz. Çalışan sayımız zamanla artıp azalmakta, ancak berber/kuaför koltuğu sayımız sabit kalmaktadır. Elbette zamanla dükkânımızı genişletebiliriz ama çalışan sirkülasyonumuz daha yoğundur. Fakat dükkân sahibi tek kişidir ve müdürümüz olarak çalışmaktadır. Her çalışanımız belli bir süre öncesinden istediği bir gün için izin talebinde bulunabilir, ancak müdürümüz bu talebi onaylamamışsa izine çıkamaz. Bu gibi işlerde tek yetkili müdürdür.
>
> Müşterilerimizin İnternet'ten değişik saç stillerini kendi üzerlerinde sanal olarak deneyebilmelerini de sağlamak istiyoruz. Bunun için kullanıcı vesikalık bir resmini sisteme yükleyebilmeli, bunun üzerine sistemde kayıtlı hazır modeller bindirilerek müşteriye gösterilebilmelidir.

İstenenler: use case diyagramı, use case belgesi ve kavramsal sınıf diyagramı.

**Çözüm (derste verildi):**

**a) Use case diyagramı (ekrandan, 01:20:00).** Aktörler: Müşteri, Çalışan, Yönetici. Use case diyagramında çalışanın tipleri (kuaför, kalfa, çırak) ayrılmaz.

- Müşteri: Stil Deneme, Randevu Alma.
- Yönetici: Stil Yükleme, Çalışan İşlemleri, Koltuk İşlemleri.
- Çalışan: Talep Bildirme.
- İlişkiler:
  - Stil Deneme --«include»--> Resim Yükleme
  - Kayıt Oluşturma --«extend»--> Randevu Alma
  - Randevu Alma --«include»--> Çalışan İzin Günleri Sorgulama
  - Çalışan İşlemleri --«include»--> İzin İşlemleri
  - Çalışan İşlemleri --«include»--> Kayıt Ekle / Sil / Güncelle
  - İzin İşlemleri --«include»--> Çalışan İzin Günleri Sorgulama
  - İzin İşlemleri --«include»--> Talep Bildirme
  - İzin İşlemleri --«include»--> Talep Onaylama

Hocanın açıklaması: yönetici koltuk ve stil yükleme gibi işlemleri yapar. Müşteri web sitesinden stil deneme ve randevu alma yapar; öncelikle müşteri kaydı oluşturur. Stil deneme gerçekleştirilirken resim yükleme de buna dahildir. Çalışan izin işlemi için talep bildirir; talep kabul ya da reddedilir (talep onaylama); çalışan izin günlerini istediği zaman sorgulayabilir. İlişkiler çoğunlukla include şeklindedir: bir işlemi yaparken daha önce başka bir işlemin yapılmış olması gerekiyorsa ya da bir işlem yapılırken altta başka bir işlemin de içerildiği belirtilmek isteniyorsa include kullanılır.

> **Ders sonrası not:** Hoca anlatırken stil deneme ile resim yükleme arasında "extend" olduğunu söyledi, ama karedeki diyagramda bu ilişki «include» olarak çizilmiştir. Resim yüklemeden stil denenemeyeceği için diyagramdaki «include» doğrudur.

**b) Use case belgesi: Randevu Alma (derste sözlü, 01:20:00 - 01:21:30).**

- Birincil aktör: Müşteri.
- İlgililer: Müşteri kolayca randevu almak ister, sırada beklemek istemez.
- Ön koşul: Müşteri önce web sitesini ziyaret etmelidir.
- Son koşul: Randevu kaydı oluşturulmuştur.
- Ana akış:
  1. Müşteri kendi kullanıcısı ile web sitesine bağlanır.
  2. Randevu al bağlantısına tıklar; sistem müşterinin cinsiyetine göre otomatik olarak kuaför ya da berber salonu için randevu ekranını açar.
  3. Müşteri randevu almak istediği günü girer.
  4. Sistem izin kayıtlarına ve boş koltuk sayılarına bakarak o gün için uygun randevu saatlerini listeler.
  5. Kullanıcı istediği saati seçer ve onaylar.
- Alternatif akışlar:
  - Müşteri sisteme giriş (login) yapamamışsa giriş sayfasına tekrar yönlendirilir.
  - Müşteri kullanıcı hesabı oluşturmamışsa yeni kullanıcı oluştur sayfasına yönlendirilir (randevu alma, kayıt oluşturmayla genişletilir).
  - Kullanıcı sistemin önerdiği saatleri beğenmezse günlere yeniden bakmak için geri döner.

<!-- BELİRSİZ: Belge slaytı karede ana ekranda yakalanmadı; adımlar altyazıdan kuruldu. Hoca alternatif akışta "dördüncü adıma" dönüldüğünü söyledi; adım numaralandırması slayttakiyle birebir olmayabilir. -->

**c) Kavramsal sınıf diyagramı (ekrandan, 01:25:00).** Kavramsal diyagramda işlemler yoktur; yalnız sınıf adları, özellikler ve ilişkiler gösterilir.

| Sınıf | Özellikler |
|---|---|
| İşlem | isim : String, ucret : double |
| Çalışan | (alt sınıflar: Kuaför, Kalfa, Çırak) |
| Bölüm | koltukSayisi : int |
| «Enum» Cinsiyet | KADIN, ERKEK |
| Randevu | date : Date, time : Time |
| Müşteri | |
| BilgiSistemi | |
| Yönetici | |
| Resim | |
| Model | |

İlişkiler:

- Çalışan (1) --yapabilir--> İşlem (*): bir işlemi mutlaka bir çalışan yapar, bir çalışan çok sayıda işlem yapabilir.
- Kuaför, Kalfa ve Çırak -> Çalışan (genelleştirme).
- Bölüm (1) --içerir--> Çalışan (*).
- Bölüm (1) -- Cinsiyet (1): bölüm cinsiyete göre kadın ya da erkek bölümüdür.
- Bölüm -- Randevu -- Müşteri: randevu, koltuk sayısına göre hangi bölümden alınacaksa o bölüm için tarih ve saatle belirlenir.
- Müşteri (1) -- Cinsiyet (1).
- BilgiSistemi -> Resim (*), Model (*), İşlem (*), Çalışan (*), Bölüm (*), Randevu (*), Müşteri (*), Yönetici (1).

Hocanın açıklaması: İşlem sınıfı hangi işlemlerin hangi ücretle yapılabildiğini ve hangi çalışanın bu işlemi yapabildiğini tutar; bazı işleri kalfalar yapabilir, bazılarını gerçek kuaförlerin yapması gerekir. Çalışan diye genelleştirilen sınıfın alt elemanları kuaför, kalfa ya da çıraktır. Bölüm sınıfı koltuk sayısını ve cinsiyete göre kadın/erkek bölümünü tutar (kuaför ve berber bu şekilde ayrılmıştır). Müşterinin yüklediği resim ve sistemde kayıtlı modeller bilgi sistemine kaydedilir; yönetici bu işleri gerçekleştirir.

> **Hocanın vurgusu:** Çalışan ile İşlem arasındaki ilişkide çokluğun doğru gösterilmesi (bir tarafta mutlak bir, diğer tarafta yıldız) ve Kuaför/Kalfa/Çırak için genelleştirme kullanılması beklenir. Mantıklı farklılıklar kabul edilebilir.

### Soru 2: Tasarım kalıpları hangi kalite özelliğini destekler?

Kaynak: (derste sözlü, 02:12:28)

Soru: Tasarım kalıplarını incelerken (ve genel olarak nesneye yönelik yaklaşımda) sürekli hangi yazılım kalite özelliğinden bahsedildi; tasarım kalıpları hangi kalite özelliğini sağlamaya yöneliktir?

**Çözüm (derste verildi):** Yeniden kullanılabilirlik (reusability). Derste "düşük bağlaşım, yüksek uyum" ve "yaratıcı" cevapları da verildi; hoca bunların tasarım kalıplarının kendisi ya da tasarım kuralları olduğunu, sorulanın ise McCall listesindeki bir kalite özelliği olduğunu belirtti. Tasarım kalıpları, nesneye yönelik yaklaşım, alan modelleme ve alana özgü diller yeniden kullanılabilirliği artırır; bunun sonucunda bakım yapılabilirlik de iyileşir.

## Dersin Toparlaması

Bu derste nesneye yönelik tasarımın "nasıl?" sorusuna yanıt arayan bir aşama olduğu, nesne tasarımı ve sistem tasarımından oluştuğu ve ayrıntılı sınıf şemalarının yanında sequence, activity ve state diyagramlarıyla belgelendirildiği hatırlatıldı. Ardından nesnelere sorumluluk atamada kullanılan dokuz tasarım kalıbı (Yaratıcı, Bilginin Uzmanı, Az Bağımlılık, Denetçi, İyi Uyum, Çok Şekillilik, Yapay Sınıf, Dolaylılık, Değişimlerden Korunma) kahve sitesi örneği üzerinden işlendi; kalıpların birbiriyle çelişebileceği ve birlikte değerlendirilmesi gerektiği vurgulandı. Sınavdaki kuaför bilgi sistemi sorusunun use case diyagramı, randevu alma belgesi ve kavramsal sınıf diyagramı çözüldü; kahve sitesinin tasarım sınıf diyagramı ve ürün ekleme ardışıl diyagramı üzerinden Denetçi, Uzman ve Yaratıcı kalıplarının tasarıma nasıl yansıdığı gösterildi; etkinlik şemalarının sembolleri check-in örneğiyle tekrarlandı.

Son bölümde yazılım kalitesine geçildi: McCall'un kalite üçgeni (ürün işletimi, revizyonu ve geçişi), kalite özelliklerinin ölçütlerle ağırlıklı olarak sayısallaştırılması, ISO 9126'nın iç/dış kalite ayrımı ve Garvin'in kalite boyutları anlatıldı. Tasarım kalıplarının kaliteyi, özellikle yeniden kullanılabilirliği ve dolaylı olarak bakım yapılabilirliği iyileştirdiği, ama kalite ölçütleriyle doğrudan ilişkili olmadığı belirtildi. Test, kalite etkinlikleri ve proje yönetimi konularının sonraki derslerde ele alınacağı söylendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
