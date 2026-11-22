# Ders 4 Genişletilmiş Notu: Proje Planlama, Fizibilite Analizi, Gantt ve PERT Diyagramları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin amacı
- 2. Proje ekibi ve proje yönetimi
- 3. Proje planlama aşaması ve problemin tanımı: RMO örneği
- 4. Fizibilite türleri
- 5. Maliyetler, faydalar ve fizibilite çalışmasının yürütülmesi
- 6. İş kırılım yapısı ve proje takvimi
- 7. Gantt şeması: kitap satış web sitesi örneği
- 8. Faaliyetler arası ilişkiler
- 9. Kritik yol, kilometre taşı ve bolluk
- 10. Kaynak atamaları ve MS Project
- 11. PERT diyagramı ve CPM
- Örnek Sorular

## 1. Dersin amacı

Ders, önceki haftada başlanan proje planlama, ön inceleme ve fizibilite analizi konusunun devamıdır. Hoca bu dersi aslında yalnız uygulamaya, yani önceki derste adı geçen Gantt ve PERT diyagramlarının bir örnek üzerinde gösterilmesine ayırdığını söyledi. Uygulamanın anlaşılabilmesi için önce önceki haftanın slaytları üzerinden hızlıca geçildi. Dersin ilk bölümünde İngilizce ders slaytları (RMO örneği), aradan sonraki bölümünde Türkçe uygulama slaytları (kitap satış web sitesi örneği) kullanıldı.

**Soru:** Geçen hafta aynı konuları işlemiştik; şimdi daha mı ayrıntılı işliyoruz? **Cevap:** Bu ders geçen hafta anlatılanların örneği, yani Gantt diyagramı yapılacak. Uygulamayı anlayabilmek için önceki konuların üzerinden geçiliyor.

## 2. Proje ekibi ve proje yönetimi

### 2.1 Proje ekibi

Ekranda gösterilen slayta göre proje ekibi bir "cerrahi ekip" gibidir: ekibin her üyesi bütün için kritik olan özel bir görevi yerine getirir (ekrandan, 00:05:00). Ekip, proje liderliği gibi projenin süresi boyunca değişir:

- Planlama sırasında ekip yalnız birkaç kişiden oluşur, örneğin proje yöneticisi ve birkaç analist.
- Analiz aşamasında ekibe sistem analistleri ve iş analistleri eklenir.
- Tasarım sırasında teknik uzmanlığa sahip başka uzmanlar gelebilir, örneğin veri tabanı ya da ağ tasarımcıları.
- Gerçekleştirme (implementasyon) sırasında programcılar ve kalite kontrol çalışanları eklenir.

Hoca, öğrencilerin dönem projelerinde de ekip yapısını bu şekilde, kimin hangi görevi ya da görevleri üstleneceğini belirleyerek kurmalarını istedi. Örneğin müşteri rolüne daha az iş düşüyorsa o kişiye başka işler verilebilir; rol paylaşımında ekip serbesttir.

### 2.2 Proje yöneticisi, müşteri ve kullanıcı

Proje yöneticisi ekibin bütün işlevlerinden sorumludur. Proje yönetimi, önceden hesaplanmış iş listesi ve bütçe çerçevesinde planlanmış sonucu gerçekleştirmek üzere ekipteki diğer insanları organize etme ve yönlendirme işidir. İyi bir yönetici planı nasıl yapacağını, nasıl işleteceğini ve bir sorunla karşılaştığında planı ayarlayarak bu sorunu nasıl aşacağını bilir.

Müşteri, projenin desteğini ve parasını sağlayan kişi ya da gruptur. Kullanıcı ise sistemi doğrudan kullanacak gruptur. Küçük projelerde sistem analisti aynı zamanda proje yöneticisi olabilir.

Proje yöneticisinin görevleri şunlardır:

- Planlama, organizasyon, yönlendirme ve yürütme.
- Projenin kontrolü: hangi önemli noktalarda, yani kilometre taşlarında değerlendirme yapılacağını önceden tanımlamak.
- Kaynakları düzenlemek ve rolleri, yani kimin hangi işi yapacağını belirlemek.
- Raporlama sırasında herkesin yapacağı işi organize etmek.

### 2.3 Projenin başlangıcında yapılanlar

Proje planlama aşamasında önce problem tanımlanır, sonra projenin fizibilitesi oluşturulur, projede görev alacak kişiler belirlenir ve son olarak projenin değerlendirilmesi ve uygulamaya konması konusunda kararlar verilir.

## 3. Proje planlama aşaması ve problemin tanımı: RMO örneği

### 3.1 Problemin tanımı

Problemin tanımlanması üç adımdan oluşur:

- Problem hangi iş ihtiyacından ortaya çıkıyor ve hangi faydaları sağlaması bekleniyor? Bu kısa bir paragrafla verilir.
- Bu faydaları sağlamak için yeni sistemden beklenen yetenekler nelerdir? Bu, projenin kapsamını tanımlar.
- Gerekirse kapsamı açıklamak için bir bağlam (context) diyagramı, yani taslak bir diyagram çizilir.

### 3.2 RMO müşteri destek sistemi

Örnek, katalog satışı yapan bir dış giyim şirketidir: Rocky Mountain Outfitters (RMO). Ekranda gösterilen tanıma göre RMO'da katalog satışı küçük bir deneme olarak başlamış, kısa sürede şirketin hızla büyüyen bir bölümü olmuştur. Destek başlangıçta elle yürütülen işlemler ve sipariş alma için basit hazır programlarla sağlanmıştır. Pazardaki fırsatlar üzerine RMO kapsamlı bir stratejik planlama başlatmış; bu planın bir parçası satış, müşteri desteği ve envanter için yeni bilgi sistemleri geliştirmektir. Yeni müşteri destek sistemi, kurulacak kritik sistemlerin ilkidir (ekrandan, 00:10:00).

Ekranda gösterilen beklenen iş faydaları (Anticipated Business Benefits) şunlardır (ekrandan, 00:10:00):

- Elle sipariş işlemeden kaynaklanan hataları azaltmak.
- Daha hızlı sipariş işleyerek siparişlerin karşılanmasını hızlandırmak.
- Posta ve telefonla sipariş işlemedeki personel düzeyini korumak ya da azaltmak.
- İnternet üzerinden yeni bir satış kanalı açmak.
- Popüler ve yavaş satan ürünlerin satışlarını izleyerek devir hızını artırmak.
- Kapsamlı müşteri desteği ve bilgiyle müşteri sadakatini artırmak.

Hoca bu faydaları sağlamak için sistemden beklenen yetenekleri şöyle anlattı: iadelerde daha uygun işlem yapılması ve ürün almanın kolaylaşması; sistemin hem internet müşterilerine hem de diğer siparişlere açık olması; pazar analizi için geçmiş bilginin saklanması (örneğin geçen yıl aynı dönemde hangi satışların olduğu) ve bu arşiv verisine kolay erişim, bunun için de veri tabanının bu özelliği sağlaması; daha büyük veri miktarlarıyla işlem yapılabilmesi; internet uygulaması üzerinden kesintisiz sipariş alınması; gönderimlerin birden fazla depodan yapılabilmesi ve sistemin bunu koordine etmesi.

### 3.3 Bağlam diyagramı

Hoca, varlık diyagramları ve veri akış diyagramlarının henüz görülmediğini, veri akış diyagramlarının ileride kademe kademe daha ayrıntılı işleneceğini söyledi. Bağlam diyagramı bunun en özet, en genel halidir: içinde işlem ayrıntısı yoktur. Yalnız yapılacak sistem (müşteri destek sistemi) ve bu sistemin hangi birimlere hangi veriyi gönderdiği, hangi birimlerden hangi bilgiyi aldığı gösterilir.

Ekrandaki RMO bağlam diyagramında (Figure 2-8) ortada "0" numaralı Customer support system süreci, çevresinde dış varlıklar vardır (ekrandan, 00:15:00):

| Dış varlık | Sisteme gelen akış | Sistemden giden akış |
|---|---|---|
| Customer | New order, Item return info, Customer change notice | Back order notice, Shipment BOL |
| Merchandising (sales) | Catalog updates | Sales reports, Performance reports |
| Management | | Fulfillment reports, Sales reports, Activity reports |
| Shipping | Order fulfillment, Back order notice | Order details |
| Bank | | Deposit information |
| Credit bureau | Credit verification (karşılıklı) | |
| Marketing | Prospective Cust Info, Promotion package info | |

<!-- BELİRSİZ: Marketing akışlarının ve Credit verification akışının ok yönleri karede net okunmuyor; tabloda yalnız akış adları kesindir. -->

Hoca, öğrencilerin kendi projelerinde de problemi tanıtırken bu sırayı izlemelerini istedi: önce hangi problemin çözüleceği, sonra bu problemi çözmenin işletme açısından faydaları (maddeler halinde), sonra sistemin bu işleri yapabilmesi için hangi yeteneklere sahip olması gerektiği. Diyagram kısmı henüz görülmediği için atlanabilir, ama sistemin kurumdaki hangi varlıklarla ilişkili olduğu ve bunlarla hangi veri alışverişinin olduğu yine değerlendirilmelidir.

## 4. Fizibilite türleri

Problem tanımlandıktan sonra projenin fizibilitesi oluşturulur. Fizibilite yapılabilirlik ya da olurluluk demektir: bu işin bir oluru var mı, projeden çıkan sonuç gerçekten fayda sağlayacak mı? Fizibilite türleri şunlardır:

- **Ekonomik fizibilite:** maliyet-fayda analizi (cost-benefit analysis). Maliyet ile fayda kıyaslanır.
- **Kurumsal ve kültürel fizibilite:** her kurumun bir işleyişi ve alışkın olduğu bir iş düzeni vardır; geliştirilen sistem buna uyacak mı?
- **Teknolojik fizibilite:** önerilen teknolojik gereksinimler ve bunların gerektirdiği uzmanlık düzeyi.
- **Zaman (schedule) fizibilitesi:** iş listesindeki işler zamanında bitebilecek mi?
- **Kaynak fizibilitesi:** ekip üyelerinin sağlanabilirliği; ekipteki herkes projeye yeterince destek verebiliyor mu?

> **Hocanın vurgusu:** Birçok öğrenci "ekonomik fizibiliteyi çıkar" denince yalnız maliyeti çıkarıyor. Ekonomik fizibilite maliyetin ve faydanın kıyaslanmasıdır. Sembolik bir projede maliyeti dışarıdan tahmin etmek kolay değildir, ama farkındalık için yine de anlaşılıp tarif edilmelidir.

Hoca ayrıca bazen projelere fayda sırasına göre girme kararı alındığını belirtti.

## 5. Maliyetler, faydalar ve fizibilite çalışmasının yürütülmesi

### 5.1 Maliyetler

Ekrandaki slayta göre maliyetler iki gruptur (ekrandan, 00:20:00):

- **Geliştirme maliyetleri:** maaşlar ve ücretler, ekipman ve kurulum, yazılım ve lisanslar, danışmanlık ücretleri ve üçüncü taraflara ödemeler, eğitim, tesisler, altyapı ve araçlar, destek personeli, seyahat ve diğer giderler.
- **Süren işletim maliyetleri:** bağlantı, ekipman bakımı, bilgisayar işletimi, programlama desteği, ekipman amortismanı, eğitim ve süren yardım (help desk), sarf malzemeleri.

Hoca geliştirme maliyetini, sistemi geliştiren herkesin (proje yöneticisinden programcıya kadar) ücreti, fazla mesai ücreti, alınan cihazlar ve kurulumları, yazılım paketleri ve lisansları, danışmanlık ücreti, üçüncü parti kurumlardan alınan hizmetler, eğitim ve sistemi kurarken yapılan seyahatler olarak açıkladı. İşletim maliyeti ise hazır sistemin çalışabilmesi için gereken internet bağlantısı, bilgisayarların bakımı ve işletimi, programlama desteği ve eğitim gibi giderlerdir.

### 5.2 Faydalar

Faydalar sayılabilir ve sayılamayan olarak ikiye ayrılır. Fayda doğrudan paraya dökülebiliyorsa sayılabilir faydadır (tangible benefit). Hocanın örnekleri:

- Otomasyona geçildiği için çalışan ücretlerinin ya da çalışan sayısının azalması.
- Müşteri giriş, çıkış ve değişiklik bilgilerinin bakımının kolaylaşması ve işletim harcamalarının azalması.
- Hata oranlarının azalması: otomasyon sisteminde işler kişinin göz kontrolüyle değil makinelerle yapıldığı için hatalar azalır.

Paraya dökülemeyen faydalar ise sayılamayan faydalardır (intangible benefit): müşteri memnuniyeti, kullanıcıların sisteme daha çok güvenmesi gibi.

### 5.3 Fizibilite çalışmasının yürütülmesi

Ekrandaki "Conducting the feasibility study" slaytındaki adımlar şunlardır (ekrandan, 00:30:00):

- Her maliyet kategorisi tahmin edilir.
- Maaşlar ve ücretler personel ihtiyacına göre hesaplanır.
- Ekipman, yazılım lisansları ve eğitim gibi diğer maliyetler de tahmin edilir.
- Geliştirme maliyetlerinin ve yıllık işletim maliyetlerinin bir özeti çıkarılır.
- Faydaların bir özeti çıkarılır.
- Fayda ve maliyetlerin bugünkü değeri olan net bugünkü değer (NPV), örneğin 5 yıllık bir dönem için hesaplanır.
- Projeye devam edilip edilmeyeceğine karar verilir.

Ücretler hesaplanırken projenin hangi bölümünde, kimin, ne kadar süre çalıştığına ve o kişinin ücretine bakılır. Hoca, görevlilerin bir projede zamanlarının her zaman %100'ünü kullanmadığını vurguladı: bir kişi projeye 0,5 adam-ay ya da 0,3 adam-ay ayırmış olabilir ya da tamamen bu projeye adanmış olabilir.

Net bugünkü değer (net present value), sistemin gelecekte sağlayacağı faydanın (örneğin iki yıl sonra sağlayacağı faydanın) bugünkü para birimine çevrilerek ifade edilmesidir. Bu sayede üzerinde çalışılmaya değer bir proje olup olmadığı değerlendirilir.

### 5.4 RMO maliyet ve fayda örneği

Hoca RMO için maliyet tablosu üzerinden geçti: proje yöneticisi maliyeti, 9 ay boyunca çalışan 3 sistem analisti (yıllık ücret 75 bin), 7 ay çalışan 6 programcı (yıllık ücret 50 bin), ağ için çalışan kişiler; böylece tüm ekip üyelerinin ücreti toplanır. Bu değerlerle hesap şöyle olur (ara adım eklendi):

- Sistem analistleri: $3 \times 75000 \times \frac{9}{12} = 168750$
- Programcılar: $6 \times 50000 \times \frac{7}{12} = 175000$

<!-- BELİRSİZ: Maliyet tablosunun slaytı karelerde yok; değerler altyazıdan alındı, para birimi ve diğer satırlar doğrulanamadı. -->

Fayda tarafında sipariş departmanının ve telefonla sipariş biriminin daha etkin çalışması, buna bağlı olarak personel ihtiyacının azalması gibi kalemler gösterildi; tabloda net bugünkü değer ve geri ödeme süresi de yer alıyordu. <!-- BELİRSİZ: Fayda tablosunun değerleri karelerde yok; altyazıda NPV ve payback'ten sonra bir üçüncü ölçüt (büyük olasılıkla ROI) anılıyor ama anlaşılmıyor. -->

**Geri ödeme süresi (payback period):** kazanç ve giderin başa baş geldiği noktaya ne kadar süre sonra ulaşılacağıdır. Yani kurulan bilgi sistemi ne kadar süre sonra kendini karşılamış olacaktır?

## 6. İş kırılım yapısı ve proje takvimi

Fizibiliteden sonra iş listesi oluşturulur: her aktivite, süresi ve kaç kaynak kullanacağı belirtilir. Ekranda RMO projesinin planlama aşaması için iş kırılım yapısı (Figure 2-9) gösterildi (ekrandan, 00:35:00):

| No | Görev | Süre (gün) | Kaynak sayısı |
|---|---|---|---|
| 1.1 | Define the problem | | |
| 1.1.1 | Meet with users | 2 | 2 |
| 1.1.2 | Determine scope | 2 | 2 |
| 1.1.3 | Write statement of business benefits | 1 | — |
| 1.1.4 | Write statement of need | 1 | — |
| 1.1.5 | Define statement of system capabilities | 1 | — |
| 1.1.6 | Develop context diagram | 1 | — |
| 1.2 | Produce the project schedule | | |
| 1.2.1 | Develop work breakdown schedule | 3 | 2 |
| 1.2.2 | Estimate resources, durations, and predecessors | 2 | 2 |
| 1.2.3 | Develop PERT chart and Gantt chart | 2 | 2 |
| 1.3 | Confirm project feasibility | | |
| 1.3.1 | Identify intangible costs and benefits | 1 | 2 |
| 1.3.2 | Estimate tangible costs | 3 | 2 |
| 1.3.3 | Estimate tangible benefits and do cost/benefit | 2 | 2 |
| 1.3.4 | Evaluate organizational and cultural feasibility | 1 | 1 |
| 1.3.5 | Evaluate technical feasibility | 2 | 1 |
| 1.3.6 | Evaluate schedule feasibility | 2 | 2 |
| 1.3.7 | Evaluate resource availability | 1 | 1 |
| 1.4 | Staff the project | | |
| 1.4.1 | Develop a project resource plan | 1 | 2 |
| 1.4.2 | Identify and request tech staff | 1 | 1 |
| 1.4.3 | Meet with users, identify staff | 2 | 1 |
| 1.4.4 | Organize project team | 1 | 1 |
| 1.4.5 | Conduct team-building exercises | 3 | 2 |
| 1.5 | Launch the project | | |
| 1.5.1 | Prepare presentation materials | 1 | 1 |
| 1.5.2 | Make executive presentation | 1 | 1 |
| 1.5.3 | Set up project facilities and support resources | 3 | 2 |
| 1.5.4 | Conduct official kickoff meeting | 1 | 1 |

Hoca listedeki ilk işlemleri (kullanıcılarla görüşme, kapsamın saptanması, faydaların ve gereksinimlerin net ifade edilmesi) ve ardından bağlam diyagramının oluşturulmasını vurguladı. Daha sonra PERT diyagramı çıkarılır. Ekranda gösterilen PERT slaytına göre görevler dikdörtgenlerle gösterilir; paralel yollardaki görevler eş zamanlı yapılabilir; kritik yol bağımlı görevlerin en uzun yoludur, bu yolda izin verilen bolluk yoktur, diğer yollarda ise takvimi etkilemeden kayabilecek bolluk süresi olabilir (ekrandan, 00:40:00).

Bu noktada bağlantı sorunları nedeniyle ders kısa bir süre kesildi; derse uygulama slaytlarıyla devam edildi.

## 7. Gantt şeması: kitap satış web sitesi örneği

### 7.1 Gantt şemasının mantığı

Gantt şemasında projedeki her iş adımı bir faaliyet olarak gösterilir; başlangıç ve bitiş zamanları ile kullanılacak kaynaklar belirlenir. Örnek, kitap satışı yapılacak bir web sitesinin tasarlanmasından kullanıma sunulmasına kadar olan süreçtir: analiz, tasarım, geliştirme ve test birlikte ele alınmıştır (ekrandan, 00:50:00).

Ekranda gösterilen MS Project görünümü şöyledir (ekrandan, 00:50:00):

| Satır | WBS | Görev | Süre | Başlangıç | Bitiş | Öncül | Kaynak |
|---|---|---|---|---|---|---|---|
| 0 | 0 | KİTAP SATIŞ WEB SİTESİ | 27 gün | Çar 24.03.21 | Per 29.04.21 | | |
| 1 | 1 | Analiz | 6 gün | Çar 24.03.21 | Çar 31.03.21 | | |
| 2 | 1.1 | Fizibilite Çalışması | 4 gün | Çar 24.03.21 | Pzt 29.03.21 | | Analist-1 |
| 3 | 1.2 | Gereksinimlerin Belirlenmesi | 5 gün | Per 25.03.21 | Çar 31.03.21 | 2SS+1 day | Analist-2 |
| 4 | 1.3 | Analiz Bitimi Toplantı | 0 gün | Çar 31.03.21 | Çar 31.03.21 | 3 | |
| 5 | 2 | Tasarım | 7 gün | Per 1.04.21 | Cum 9.04.21 | | |
| 6 | 2.1 | Ön Tasarım | 3 gün | Per 1.04.21 | Pzt 5.04.21 | 4 | Yazılımcı-1 |
| 7 | 2.2 | Ayrıntılı Tasarım | 4 gün | Sal 6.04.21 | Cum 9.04.21 | 6 | Yazılımcı-2 |
| 8 | 2.3 | Tasarım Bitimi Toplantı | 0 gün | Cum 9.04.21 | Cum 9.04.21 | 7 | |
| 9 | 3 | Geliştirme&Test | 14 gün | Pzt 12.04.21 | Per 29.04.21 | | |
| 10 | 3.1 | Ön Yüz Geliştirme | 8 gün | Pzt 12.04.21 | Çar 21.04.21 | 8 | Yazılımcı-1 |
| 11 | 3.2 | Arka Plan Geliştirme | 10 gün | Pzt 12.04.21 | Cum 23.04.21 | 8 | Yazılımcı-2 |
| 12 | 3.3 | Birim Test | 10 gün | Pzt 12.04.21 | Cum 23.04.21 | 11FF;10SS | Test Uzmanı |
| 13 | 3.4 | Sistem Testi | 2 gün | Pzt 26.04.21 | Sal 27.04.21 | 12 | Test Uzmanı |
| 14 | 3.5 | Kullanıcı Testleri | 4 gün | Pzt 26.04.21 | Per 29.04.21 | 12 | Test Uzmanı |
| 15 | 4 | Proje Teslim Toplantısı | 0 gün | Per 29.04.21 | Per 29.04.21 | 14 | |

Sağdaki zaman çizelgesinde her faaliyet bir çubukla, yanında kaynağın adıyla (Analist-1, Analist-2, Yazılımcı-1, Yazılımcı-2, Test Uzmanı) gösterilir. Kilometre taşları eşkenar dörtgen işaretiyle ve tarihleriyle (31.03, 9.04, 29.04) görünür.

Tablodaki süreler iş günüdür; hafta sonları sayılmaz. Örneğin Fizibilite Çalışması Çarşamba başlayıp 4 iş günü sürünce (Çar, Per, Cum, Pzt) Pazartesi biter. Analiz 6, Tasarım 7, Geliştirme&Test 14 iş günü sürer; toplam $6 + 7 + 14 = 27$ iş günüdür ve bu da projenin 27 günlük süresiyle tutarlıdır. Tablodaki bütün başlangıç ve bitiş tarihleri python ile iş günü sayılarak kontrol edildi ve tutarlı bulundu.

### 7.2 Hiyerarşi ve kilometre taşı

Faaliyetler hiyerarşik yazılır. Örneğin Analiz'in altında fizibilite çalışması ve gereksinimlerin belirlenmesi, en altta da analiz bitimi toplantısı vardır. Bu toplantının süresi 0 gündür, çünkü analizin bitiş gününde yapılan bir değerlendirme toplantısıdır; çizelgedeki eşkenar dörtgen burada bir kilometre taşı (milestone) olduğunu gösterir.

Analiz'de iki kaynak çalışır: Analist-1 4 gün boyunca fizibilite çalışmasında, Analist-2 gereksinimlerin belirlenmesinde çalışır. Gereksinimlerin belirlenmesi 3. satırdaki aktivitedir ve öncülü "2SS+1 day"dir: 2. satırdaki işlemin başlangıcıyla (start-start) bağlıdır, ama bir gün sonra başlar. Analiz tamamlanınca bir değerlendirme toplantısı yapılır, yani oraya bir kilometre taşı konmuş olur.

İkinci adım tasarımdır ve ön tasarım ile ayrıntılı tasarım alt faaliyetlerine ayrılır. Ön tasarımın öncülü 4 numaralı işlemdir: analiz bitimi toplantısı bittikten sonra başlar. Ayrıntılı tasarım (7. satır) 6. satırdaki ön tasarım bittikten sonra başlar. Burada ilişki türü yazılmamıştır, çünkü bitiş-başlangıç (finish-start) varsayılan ilişkidir.

### 7.3 WBS numarası ve satır numarası

Ön tasarım, iş kırılım yapısında (Work Breakdown Structure, WBS) 2.1 numarasını taşır, ama tabloda 6. satırdadır. Öncül sütununda satır numarası kullanılır. WBS ile her faaliyet alt faaliyet kırılımlarına sahip olup hiyerarşik olarak numaralandırılır: 1 Analiz, 1.1 Fizibilite Çalışması, 1.2 Gereksinimlerin Belirlenmesi, 1.3 kilometre taşı olan son toplantı gibi. Bu örnek ikinci düzeye kadar ayrıntılandırılmış bir uygulamadır.

Ekrandaki slayta göre (ekrandan, 00:55:00):

- WBS ifadesi ile her faaliyet alt faaliyet kırılımlarına sahip olup numaralandırılır.
- Faaliyetler için başlangıç tarihi ve süresi belirtildiğinde bitiş tarihi otomatik olarak hesaplanır.
- Bir işin başlangıç zamanı başka bir işe bağlı olabilir (öncül tanımlama).

Yani Gantt şeması oluşturulurken hangi işin kaç gün sürdüğü, başlangıç tarihi ve hangi işle ilişkili olduğu yazılır; bitiş tarihleri bundan hesaplanır.

> **Hocanın vurgusu:** Bir bilgi sistemi kurmak için gereken işlerin doğru kademelendirilmesi gerekir: analizin, tasarımın, geliştirme ve testin altında hangi işlemler var? Sistem analizi ve tasarım dersi özümsenmişse bu adımlar doğru yazılır. Sonra Gantt şemasında her işin gün sayısı ve hangi aktiviteyle ilişkili olduğu, bir işin başlaması için hangi aktivitenin bitmiş ya da başlamış olması gerektiği kuralları da doğru tasarlanmalıdır.

## 8. Faaliyetler arası ilişkiler

Faaliyetler arasında dört tür ilişki vardır:

- **Bitiş-Başlangıç (Finish-to-Start, FS):** varsayılan ilişkidir. Bir faaliyetin başlaması için bağlantılı olan başka bir faaliyetin tamamlanmış olması gerekir. Örnek: tasarımın başlaması için analizin bitmiş olması gerekir.
- **Başlangıç-Başlangıç (Start-to-Start, SS):** bir faaliyetin başlaması için bağlantılı başka bir faaliyetin de başlamış olması gerekir. Örnek: birim testlerin başlaması için geliştirme aşamasının da başlamış olması gerekir.
- **Bitiş-Bitiş (Finish-to-Finish, FF):** bir faaliyetin bitmesi için diğerinin bitmiş olması gerekir. Örnek: birim testlerin bitmesi için kodlamanın bitmiş olması gerekir; kodlama bitmeden test bitti denemez, çünkü bütün kod değerlendirilecektir.
- **Başlangıç-Bitiş (Start-to-Finish, SF):** bir işin bitişi diğerinin başlamasına bağlıdır. Hoca bunun biraz zorlama olduğunu, yazılımdan tam örnek vermenin güç olduğunu söyledi.

Örnekteki Birim Test satırının öncülü "11FF;10SS" bu ilişkilerin ikisini birlikte gösterir: birim test, 11. satırdaki arka plan geliştirmeyle bitiş-bitiş, 10. satırdaki ön yüz geliştirmeyle başlangıç-başlangıç ilişkisindedir.

> **Ders sonrası not:** Altyazıda SF ilişkisi bir yerde "bir işin başlaması için diğerinin bitmiş olması gerekir" diye geçiyor; bu tanım FS'ye aittir. SF ilişkisinde, hocanın daha önce söylediği gibi, bir işin bitişi diğerinin başlamasına bağlıdır.

## 9. Kritik yol, kilometre taşı ve bolluk

### 9.1 Kritik yol

Ekranda gösterilen tanıma göre kritik yol, projenin belirlenen zamanda tamamlanması için bu yol üzerindeki tüm faaliyetlerin zamanında gerçekleşmesi gerektiğini ifade eder. Kritik yoldaki faaliyetlerden biri X gün ertelenirse projenin bitiş tarihi de en az X gün ertelenir (ekrandan, 01:00:00). Hocanın örneğiyle, kritik yoldaki bir faaliyet üç gün ertelenirse proje de en az üç gün ertelenir. Kritik yol, aralarında hiç bolluk olmayan faaliyet geçişlerinden oluşur.

Kritik yol üzerindeki faaliyetlere kritik faaliyetler denir ve Gantt çizelgesinde kırmızıyla gösterilir. Hoca bunu "burada herhangi bir oynama yapmayın, yoksa bütün proje gecikir" diye yorumladı. Ekrandaki kritik yol görünümünde analiz, tasarım ve geliştirme faaliyetlerinin hepsi kırmızıdır; yalnız 2 günlük Sistem Testi mavi görünür (ekrandan, 01:00:00).

### 9.2 Kilometre taşı

Kilometre taşı (milestone) günlük hayatta da kullanılan bir kavramdır ("hayatın kilometre taşları"). Proje planı için önemli olan tarihleri ya da olayları belirtir. Örnekte üç kilometre taşı vardır: analiz aşamasının bitişi, tasarım aşamasının bitişi ve projenin genel olarak bitişi. Kilometre taşı olan faaliyetin süresi Gantt şemasında 0 gün olarak gösterilir.

### 9.3 Bolluk (slack)

Ekrandaki slayta göre bolluk (slack) kavramı, kritik yol üzerinde bulunmayan esnek faaliyetlerin zamanlamasında yapılabilecek kayma miktarını ifade eder. Kritik olmayan faaliyetler mavi renkle gösterilir; bu faaliyetlerde proje süresini etkilemeden yapılabilecek öteleme miktarı olan bolluk gri uzun çizgiyle ifade edilir (ekrandan, 01:35:00).

Örnekte analiz ve tasarımdan sonra yazılım geliştirme ve test aşamasında Yazılımcı-1, Yazılımcı-2 ve Test Uzmanı çalışır. Test aşamasındaki mavi iş kritik yol üzerinde değildir; slayttaki oklar "kritik olmayan iş" ve "bolluk miktarı"nı gösterir. Sistem Testi ile Kullanıcı Testleri aynı öncüle (Birim Test) bağlıdır ve aynı gün başlar. Kullanıcı Testleri 4 gün, Sistem Testi 2 gün sürdüğü ve proje Kullanıcı Testleri bitince bittiği için Sistem Testi'nin bolluğu $4 - 2 = 2$ iş günüdür (ara adım eklendi).

## 10. Kaynak atamaları ve MS Project

### 10.1 Kaynak kavramı

Ekrandaki tanıma göre kaynak, proje faaliyetlerinin ilerleyebilmesi için ihtiyaç duyulan her şeydir. İnsan, ekipman, para gibi projenin tamamlanması için gerekli olan her şey kaynaktır. Kaynakların doğru ve etkin biçimde kullanılması, projenin başarılı bir şekilde yönetilmesiyle doğru orantılıdır. Özellikle sınırlı kaynakların öncelikli olarak doğru kullanılması önemlidir; bunun için Gantt çizelgesi ve kritik yol gibi analizler kaynak kullanımı konusunda önemli bilgiler verir (ekrandan, 01:40:00). Hoca en önemli kaynağın insan, yani personel olduğunu vurguladı.

Kaynak ataması, projede hangi kaynakların bulunduğunun dökümünü almak ve her faaliyete kaynak bağlamaktır. Kaynak bir kişi, bir malzeme ya da bir bilgisayar olabilir. Proje maliyet tahmini de bu kaynak atamasından yararlanılarak geliştirilir. Örnek Gantt şemasında her faaliyetin yanında o işi gerçekleştiren kaynak yazılıdır: analiz aşamasında Analist-1 ve Analist-2, tasarım sırasında Yazılımcı-1 ve Yazılımcı-2 çalışır.

### 10.2 MS Project

MS Project, Microsoft Office'in yan programlarından biridir. Diyagramları daha kolay çizmeyi ve kontrolü daha iyi yapmayı sağlayan bir paket programdır. Aktivite listesini ve sonuçtaki beklentileri yönetir.

> **Hocanın vurgusu:** MS Project bir yazılım geliştirme aracı değildir. Hangi proje olursa olsun projenin yönlendirilmesini yapan bir yazılımdır.

**Soru:** MS Project ücretli; alternatif bir program kullanılabilir mi? **Cevap:** Olur. Microsoft Office birçok kişi tarafından kullanıldığı için onun yan programı tercih edildi; bölüm laboratuvarında eski bir sürümü yüklü olduğu için alıştırmalarda o kullanılıyor. Ama amaç, iş kırılım yapısını takip edebilen, yanında Gantt diyagramını çizebilen ve bunun için arka planda PERT diyagramını oluşturan bir paket programdır; bu hedefe uygun açık kaynaklı başka yazılımlar da kullanılabilir.

Hoca bu çalışmanın anlamını şöyle bağladı: öğrenciler ilk kez, o zamana kadar aldıkları derslerin çerçevesinde bir bilgi sistemi geliştirmeyi bir proje olarak ele alıyor ve ekip içinde çalışıyor. Bilgi sistemini sıfırdan çalışır hale getirmek için hangi faaliyetlerin olduğunu iş kırılım yapısıyla hiyerarşik olarak tanımlamak, sonra Gantt diyagramı çerçevesinde her faaliyetin ne kadar süreceğini, faaliyetler arasındaki ilişkileri ve buna göre her faaliyetin ne zaman başlayıp biteceğini belirlemek gerekir.

MS Project'te ayrıca genel takvim tanımları yapılır: cumartesi günlerinin iş günü sayılıp sayılmayacağı, günlük çalışma süresinin (örneğin 7 saat) ne olacağı, proje sırasında resmi tatillerin dikkate alınması gibi.

### 10.3 Kaynak tablosu

Ekrandaki kaynak tablosu şöyledir (ekrandan, 01:10:00):

| Kaynak adı | Tip | Kısaltma | Maks. | Standart ücret |
|---|---|---|---|---|
| Analist-1 | Work | A | %100 | 30,00 ₺/saat |
| Analist-2 | Work | A | %100 | 30,00 ₺/saat |
| Yazılımcı-1 | Work | Y | %100 | 50,00 ₺/saat |
| Yazılımcı-2 | Work | Y | %100 | 50,00 ₺/saat |
| Test Uzmanı-1 | Work | T | %100 | 30,00 ₺/saat |
| Test Uzmanı-2 | Work | T | %100 | 30,00 ₺/saat |
| Test Uzmanı-3 | Work | T | %100 | 30,00 ₺/saat |
| Hosting Service | Material | H | | 1.000,00 ₺ |

Slayta göre MS Project ile faaliyetler ve proje geneli için ayrıntılı kaynak ataması yapılabilir; kaynaklar kişiler ya da materyaller olabilir. Kişiler için saat başı ücretler girilir ve proje maliyet tahmini bu şekilde yapılır (ekrandan, 01:10:00). Kişilerin kaynak tipi Work (iş) olur; hosting servisi bir materyal, bilgisayar da bir donanım malzemesi olarak kaydedilir. Hoca saat ücretlerinin örnekte çok düşük yazıldığını belirtti.

Kısaltmalar (analist için A, yazılımcı için Y, test uzmanı için T, hosting servisi için H) Gantt şemasında isim yerine kullanılabilir; örneğin A1, A2, Y1, Y2 gibi.

> **Hocanın vurgusu:** Tabloda bütün kişiler %100 yazılmış, ama bu gerçekçi değildir. Her çalışanın bütün iş hayatı bu proje değildir; örneğin test uzmanı başka projeleri de test ediyor olabilir. Bazı kaynaklara %80 ya da %60 gibi oranlar verilebilir.

Önce kaynaklar tanıtılır; sonra Gantt diyagramında her kaynak ne kadar çalıştıysa ona göre parası ve dolayısıyla maliyeti hesaplanır.

> **Ek bilgi (derste anlatılmadı):** MS Project'te Work tipi kaynakların maliyeti, büyük olasılıkla atanan çalışma saati ile standart saat ücretinin çarpımından hesaplanır; Material tipi kaynaklar ise birim başına maliyetle hesaplanır.

## 11. PERT diyagramı ve CPM

### 11.1 Gantt ile PERT'in farkı

Hoca, Gantt ve PERT yöntemlerinin her türlü projenin planlanması ve takibi için uzun zamandır kullanıldığını söyledi. Ekrandaki slayta göre PERT (Program Evaluation and Review Technique, Program Geliştirme ve Gözden Geçirme Tekniği), proje yönetimi ve analizi için kullanılan istatistiksel bir araçtır. PERT diyagramı graf temelli bir yöntemdir: projedeki faaliyetler düğümlerle (nodes), faaliyetler arasındaki bağlantılar kenarlarla (edges) gösterilir. Gantt çizelgesi faaliyetlerin paralelliğini göstermek için başarılıdır; ancak faaliyetler arasındaki etkileşimi (hangi faaliyetin hangi faaliyetlere dolaylı olarak bağlı olduğunu) göstermekte yetersizdir (ekrandan, 01:20:00). Bu bağımlılıklarda PERT daha öne çıkar.

> **Ders sonrası not:** Hoca PERT'in açılımını bir yerde "Project Evaluation and Review", bir yerde benzer bir bozuk biçimde söyledi; doğrusu slayttaki gibi Program Evaluation and Review Technique'tir.

> **Ek bilgi (derste anlatılmadı):** Hocanın değindiği "Gantt ve PERT'in Birinci Dünya Savaşı öncesinden beri kullanılması" yalnız Gantt için büyük olasılıkla doğrudur: Gantt şeması 1910'larda geliştirilmiştir. PERT ise büyük olasılıkla 1950'lerin sonunda ABD donanmasının bir projesi için geliştirilmiştir.

### 11.2 MS Project'te ağ diyagramı

MS Project'te ağ diyagramı (network diagram) seçeneği tıklandığında Gantt çizelgesinin PERT diyagramı olarak ifadesi görülür. Kırmızı kutular kritik görevleri gösterir; kilometre taşları farklı biçimde gösterilir. Ekrandaki slayta göre her bir düğümde faaliyetler için ayrıntılı bilgiler görülebilir (ekrandan, 01:25:00). Gösterilen düğümler şunlardır:

```text
[Fizibilite Çalışması]          -> [Gereksinimlerin Belirlenmesi] -> <Analiz Bitimi Toplantı>
 Start: Wed 24.03.21  ID: 2         Start: Thu 25.03.21  ID: 3        Milestone Date: Wed 31.03.21
 Finish: Mon 29.03.21 Dur: 4 days   Finish: Wed 31.03.21 Dur: 5 days  ID: 4
 Res: Analist-1                     Res: Analist-2
        |
        v
[Ön Tasarım]                    -> [Ayrıntılı Tasarım]            -> <Tasarım Bitimi Toplantı>
 Start: Thu 1.04.21   ID: 6         Start: Tue 6.04.21   ID: 7        Milestone Date: Fri 9.04.21
 Finish: Mon 5.04.21  Dur: 3 days   Finish: Fri 9.04.21  Dur: 4 days  ID: 8
 Res: Yazılımcı-1                   Res: Yazılımcı-2
```

Köşeli parantezler dikdörtgen görev kutularını, açılı parantezler altıgen biçimli kilometre taşı kutularını gösterir; Ön Tasarım'a gelen ok Analiz Bitimi Toplantı'dan çıkar. Ekranda yalnız analiz ve tasarım evreleri görünür. Hoca, PERT'te kilometre taşlarının altıgene benzer bir biçimle, Gantt diyagramında ise eşkenar dörtgenle gösterildiğini belirtti. İkinci evrede ön tasarım, ayrıntılı tasarım ve tasarım bitimi toplantısı yer alır.

### 11.3 PERT'te süre belirsizliği ve CPM

PERT'te süreler kesin değildir. Örneğin fizibilite çalışması bir projede 4 gün, başka bir projede 7 gün sürebilir; bu yüzden PERT belirsizlik durumunda bir değerlendirme yapar. CPM (Critical Path Method, kritik yol yöntemi) ise PERT'ten daha basittir, çünkü süreler kesin verilir ve bu belirsizlik yoktur.

Örnekte fizibilite çalışması için 4 gün yazılmıştır, ama bunun bir hesaplamayla bulunduğu varsayılır. Benzer projelere bakılarak:

- En kötümser durumda fizibilite çalışması 7 günden fazla sürmez.
- En iyimser durumda 3 günden az sürmez.
- En olası süre, şimdiye kadar biten projelerde fizibiliteye ortalama ne kadar süre harcandığından bulunur.

En kötü durum bir kez, en iyi durum bir kez, en olası durum 4 ile çarpılarak alınır ve ağırlıklı ortalama hesaplanır; bu örnekte süre 4 gün bulunmuştur. CPM'e göre daha fazla belirsizlik olduğu için böyle bir hesaplama yoluna gidilir.

> **Ders sonrası not:** Derste ağırlıklı toplamın neye bölündüğü açıkça söylenmedi. Bilinen PERT formülü $t_e = \frac{a + 4m + b}{6}$ biçimindedir ($a$ iyimser, $m$ en olası, $b$ kötümser süre). Derste en olası süre sayı olarak verilmedi; $a = 3$, $b = 7$ ile $t_e = 4$ gün çıkması için $m = 3{,}5$ gün olmalıdır: $\frac{3 + 4 \times 3{,}5 + 7}{6} = \frac{24}{6} = 4$ (python ile kontrol edildi).

## Örnek Sorular

Ders sonunda hoca öğrencilere konuyla ilgili sözlü sorular sordu.

**Soru 1** (derste sözlü, 01:29:25): Milestone nedir?

> **Cevap (derste verildi):** Kilometre taşıdır. Projenin önemli tarihlerinin belirtildiği noktalardır ve süresi 0 gün olarak ifade edilir; değerlendirme (review) için konan noktalar gibidir. Gantt diyagramında eşkenar dörtgenle, örnekteki PERT diyagramında altıgene benzer bir kutuyla gösterilir.

**Soru 2** (derste sözlü, 01:31:48): Kritik yol nedir?

> **Cevap (derste verildi):** Kritik yoldaki bir iş aksarsa projenin tamamı aynı oranda aksar. Bu yüzden kritik yol üzerindeki aktivitelerin hiçbirinin aksamaması gerekir; kritik yolda bolluk yoktur.

**Soru 3** (derste sözlü, 01:31:03 ve 01:32:30): PERT diyagramında bolluk nedir?

> **Cevap (derste verildi):** Bolluk, bir işlemin kendisine ayrılan daha uzun süre diliminde istenen zamanda gerçekleştirilebilmesidir; bu işler kritik yol üzerinde değildir. Örnekte Sistem Testi'nin bolluğu, aynı anda başlayan 4 günlük Kullanıcı Testleri'ne göre 2 gündür.

**Soru 4** (derste sözlü, 01:35:10): Kaynak ataması nedir? Bilgi sistemi projelerinde kaynak nedir; personel dışında hangi kaynaklar olabilir?

> **Cevap (derste verildi):** Kaynaklar insanlar ve materyallerdir. Analistler, yazılımcılar gibi kişilerin yönetilmesi kaynak yönetimidir. Personel en önemli kaynaktır; bunun dışında bilgisayarlar (program geliştirme boyunca şu kadar bilgisayar kullanılacak gibi), kullanılan programlar, ofis gibi yerler ve barındırma (hosting) hizmeti de kaynaktır. Önce kaynaklar tanıtılır; sonra Gantt diyagramında her kaynağın ne kadar çalıştığına göre maliyeti hesaplanır.

## Dersin Toparlaması

Bu derste önce proje planlama aşamasının adımları tekrar edildi: proje ekibinin aşamalara göre değişen yapısı, proje yöneticisinin görevleri, problemin tanımı (iş faydaları, sistemden beklenen yetenekler ve bağlam diyagramı), beş fizibilite türü, geliştirme ve işletim maliyetleri, sayılabilir ve sayılamayan faydalar, net bugünkü değer ve geri ödeme süresi. Bunlar RMO müşteri destek sistemi örneği ve onun iş kırılım yapısı üzerinden gösterildi.

Dersin ikinci bölümünde bir kitap satış web sitesi projesi üzerinden Gantt şemasının nasıl kurulduğu anlatıldı: WBS ile hiyerarşik iş kırılımı, süre ve öncül tanımları, dört faaliyet ilişkisi (FS, SS, FF, SF), kritik yol, kilometre taşı, bolluk ve MS Project'te kaynak atamaları. Son olarak Gantt şemasının arka planındaki PERT ağ diyagramı, PERT'in olasılıklı süre tahmini ve süreleri kesin kabul eden CPM'den farkı ele alındı. Hoca, veri akış diyagramları gibi diyagramların sonraki haftalardan itibaren ayrıntılı olarak kullanılacağını belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
