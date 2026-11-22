# Ders 5 Genişletilmiş Notu: MS Project ile Proje Planlama ve Analiz Aşamasında Modelleme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. MS Project ile iş akış planı: Gantt şemasının tekrarı
- 2. Kritik yol, bolluk ve kaynak atamaları
- 3. PERT diyagramı ve süre tahmini
- 4. MS Project menüleri ve proje planlama adımları
- 5. Fizibilite türlerinin tekrarı
- 6. Analiz aşaması: analiz ile tasarımın farkı
- 7. Modeller ve modelleme
- 8. Olayların belirlenmesi ve olay tablosu
- 9. Varlıklar, nitelikler, ilişkiler ve nesneler
- 10. Müşteri destek sistemi örneği
- 11. Bağlam diyagramı ve veri akış diyagramı paketi
- 12. Bilgi toplama yolları
- 13. Örnek Sorular

## 1. MS Project ile iş akış planı: Gantt şemasının tekrarı

Önceki derste fizibilite analizinin bir parçası olarak Gantt ve PERT diyagramları bir uygulama üzerinden anlatılmıştı. Bu ders önce o konuyu hızlıca tekrar etti, MS Project'in menülerini tanıttı, sonra asıl konu olan analiz aşamasına geçti.

Gantt çizelgesi 1900'lerin başından beri kullanılan bir planlama aracıdır. Bir iş planı yapılırken iş faaliyetlere ayrılır; her faaliyetin kaç günde tamamlanacağı, ne zaman başlayıp ne zaman bitmesi gerektiği ve hangi faaliyetle ilişkili olduğu tanımlanır. Amaç projeyi zamanında bitirebilmektir.

### 1.1 Örnek proje: kitap satış web sitesi

Slayttaki örnek, kitap satışı yapılacak bir web sitesinin tasarlanmasından kullanıma sunulmasına kadar olan süreçtir (ekrandan, 00:05:00). Gantt tablosu şöyledir:

| WBS | Faaliyet | Süre | Başlangıç | Bitiş | Öncül |
|---|---|---|---|---|---|
| 0 | KİTAP SATIŞ WEB SİTESİ | 27 gün | 24.03.21 | 29.04.21 | |
| 1 | Analiz | 6 gün | 24.03.21 | 31.03.21 | |
| 1.1 | Fizibilite Çalışması | 4 gün | 24.03.21 | 29.03.21 | |
| 1.2 | Gereksinimlerin Belirlenmesi | 5 gün | 25.03.21 | 31.03.21 | 2SS+1 day |
| 1.3 | Analiz Bitimi Toplantısı | 0 gün | 31.03.21 | 31.03.21 | 3 |
| 2 | Tasarım | 7 gün | 1.04.21 | 9.04.21 | |
| 2.1 | Ön Tasarım | 3 gün | 1.04.21 | 5.04.21 | 4 |
| 2.2 | Ayrıntılı Tasarım | 4 gün | 6.04.21 | 9.04.21 | 6 |
| 2.3 | Tasarım Bitimi Toplantısı | 0 gün | 9.04.21 | 9.04.21 | 7 |
| 3 | Geliştirme&Test | 14 gün | 12.04.21 | 29.04.21 | |
| 3.1 | Ön Yüz Geliştirme | 8 gün | 12.04.21 | 21.04.21 | 8 |
| 3.2 | Arka Plan Geliştirme | 10 gün | 12.04.21 | 23.04.21 | 8 |
| 3.3 | Birim Test | 10 gün | 12.04.21 | 23.04.21 | 11FF;10SS |
| 3.4 | Sistem Testi | 2 gün | 26.04.21 | 27.04.21 | 12 |
| 3.5 | Kullanıcı Testleri | 4 gün | 26.04.21 | 29.04.21 | 12 |
| 4 | Proje Teslim Toplantısı | 0 gün | 29.04.21 | 29.04.21 | 14 |

Öncül sütunundaki sayılar tablonun satır numaralarıdır (satır 0 projenin kendisi, satır 2 fizibilite çalışması vb.). Şemanın çubuk tarafında atanan kaynaklar yazılıdır: fizibilitede Analist-1, gereksinimlerde Analist-2, tasarım adımlarında Yazılımcı-1 ve Yazılımcı-2, geliştirmede Yazılımcı-1 ve Yazılımcı-2, testlerde Test Uzmanı.

Süreler iş günü olarak sayılır, hafta sonları atlanır. Python ile kontrol edildi: analiz 24-31 Mart arası 6 iş günü, tasarım 1-9 Nisan arası 7 iş günü, geliştirme ve test 12-29 Nisan arası 14 iş günü, toplam $6+7+14=27$ iş günüdür; alt faaliyetlerin süreleri de tarihlerle tutarlıdır.

Bu süreler, hocanın deyişiyle, daha önceki işlere göre yapılmış tahminlerdir (fizibilite 4 gün, gereksinimlerin belirlenmesi 5 gün gibi).

### 1.2 İş kırılım yapısı (WBS)

Tablodaki hiyerarşik numaralandırma iş kırılım yapısıdır (Work Breakdown Structure). Seviyelendirme yapılmadığında sıfırıncı iş "kitap satış web sitesinin hazırlanması"dır. Birinci temel iş analizdir ve üç alt başlığı vardır: 1.1 fizibilite, 1.2 gereksinimlerin belirlenmesi, 1.3 analiz sonucundaki rapor ve toplantı. İkinci temel iş tasarımdır (ön tasarım, ayrıntılı tasarım, tasarım bitim toplantısı) ve bunu geliştirme ve test izler.

Bu örnekte faaliyetler yazılım geliştirme sürecinin aşamalarına göre belirlenmiştir. Hoca, kırılımın ürüne göre de yapılabileceğini anlattı: ürün modül modül geliştirilecekse, örneğin bir öğrenci bilgi sisteminde birinci modül öğrencilerin sınav sonuçlarından gelen bilgilerinin girilmesi, ikinci modül derslerin tanımlanıp bilgilerinin kaydedilmesi ve güncellenmesi, üçüncü modül öğrencilerin ders alma işlemleri olabilir. Faaliyetler o zaman bu modüllere göre hiyerarşik olarak bölünür.

Faaliyet için başlangıç tarihi ve süre girildiğinde bitiş tarihi otomatik hesaplanır; bitiş tarihi elle girilmez.

### 1.3 Kilometre taşları

Analizin bitişi ve tasarımın bitişi projede birer dönüm noktasıdır. Bu noktalarda birer toplantı ve değerlendirme yapılır. Bunlara kilometre taşı denir; süreleri sıfır gün olarak tanımlanır ve Gantt şemasında eşkenar dörtgenle gösterilir (şemada 31.03 ve 9.04 noktaları).

### 1.4 Faaliyetler arası bağlantı tipleri

Bir işin başlangıç zamanı başka bir işe bağlı olabilir. Bu bağımlılık öncül tanımlarıyla verilir: bu faaliyetten önce hangi faaliyet bitmiş ya da başlamış olmalıdır?

- Finish-Start (bitiş-başlangıç): bir işin başlaması için diğerinin bitmiş olması gerekir. Örneğin tasarımın başlaması için analizin bitmiş olması gerekir. En sık görülen tiptir ve varsayılandır; bu yüzden öncül sütununda ayrıca "FS" yazılmaz, yalnız satır numarası yazılır.
- Start-Start (başlangıç-başlangıç): bir işin başlaması için diğerinin başlamış olması gerekir. Örnekteki `2SS+1 day`, gereksinimlerin belirlenmesinin fizibilite çalışması başladıktan bir gün sonra başlayacağını söyler. Hocanın verdiği bir başka örnek: bilgi toplama başlamış olmalı ki ona bağlı iş başlasın.
- Finish-Finish (bitiş-bitiş): bir işin bitmesi için diğerinin bitmiş olması gerekir. Örneğin birim testlerin bitebilmesi için kodlamanın bitmiş olması gerekir. Örnekteki birim testin öncülü `11FF;10SS`'dir: arka plan geliştirme (satır 11) ile birlikte biter, ön yüz geliştirme (satır 10) ile birlikte başlar.
- Start-Finish (başlangıç-bitiş): bir işin bitmesi için diğer işin başlamış olması gerekir. Hoca bu konuda örneğin biraz zorlama olacağını söyledi.

Gantt şeması okunurken bir işe birden fazla finish-start bağı gelebilir: analizin bütün alt adımları bittikten sonra tasarım başlar.

## 2. Kritik yol, bolluk ve kaynak atamaları

### 2.1 Kritik yol

Slayttaki tanım (ekrandan, 00:10:00): kritik yol, projenin belirlenen zamanda tamamlanması için bu yol üzerindeki tüm faaliyetlerin zamanında gerçekleşmesi gerektiğini ifade eder. Diğer bir deyişle kritik yol üzerindeki faaliyetlerden biri X gün ertelenirse projenin bitiş tarihi de en az X gün ertelenmiş olur. Kritik yol üzerindeki faaliyetlere kritik faaliyetler denir ve Gantt çizelgesinde kırmızı ile gösterilir.

Örnek proje şelale modeline göre (fizibilite, gereksinim analizi, tasarım, geliştirme, test) hazırlandığı için işler aynı yol üzerinde ardışık ilerler. Bu yüzden faaliyetlerin neredeyse hepsi kritik yoldadır. Şemada yalnız bir faaliyet mavi çizilmiştir: sistem testi.

> **Ek bilgi (derste anlatılmadı):** Diğer yazılım geliştirme süreç modellerinin (artımlı, spiral, çevik vb.) yazılım mühendisliği dersinde ele alınacağı derste söylendi. Bu modellerde faaliyetler daha fazla örtüştüğü için kritik yol dışında kalan faaliyet sayısı büyük olasılıkla artar.

### 2.2 Bolluk süresi

Kritik yolda olmayan faaliyet, proje süresini etkilemeden ötelenebilir. Örnekte sistem testi 26-27 Nisan'da yapılır, ama proje 29 Nisan'da biter (kullanıcı testleri 29 Nisan'a kadar sürer). Bu yüzden 27 Nisan'da bitmesi gereken sistem testi iki gün daha kayabilir, 29 Nisan'da bitse de proje gecikmez. Bu iki güne bolluk miktarı ya da bolluk süresi (slack) denir. Gantt şemasında mavi çubuğun ardındaki ince tek çizgi bu bolluğu gösterir.

Hesap (ara adım eklendi): sistem testinin bitişi 27.04 (salı), projenin bitişi 29.04 (perşembe). Aradaki iş günleri 28.04 ve 29.04, yani bolluk 2 iş günüdür.

**Soru:** Kritik olan işlerde böyle bir kavram (bolluk) söz konusu değil, öyle mi?
**Cevap:** Evet. Kritik yoldaki işlerden birinin aksaması bütün projeyi geciktirir. Kritik yolda olmayan bir iş (örneğin testlerden biri) bolluk içerebilir, ama kritik yoldaki iş ne kadar gecikirse projenin bitişi de 29 Nisan yerine o kadar gecikir.

### 2.3 Kaynak atamaları

Kaynak, bir faaliyeti yapmak için gereken her şeydir: insan, ekipman, para. Kaynak ataması projenin sınırlı kaynaklarını doğru kullanmak içindir. Gantt diyagramı hazırlanmadan önce kaynaklar MS Project'te tanımlanmalıdır.

Slayttaki kaynak tablosu (ekrandan, 00:15:00):

| Kaynak | Tür | Kısaltma | En fazla | Standart ücret |
|---|---|---|---|---|
| Analist-1 | Work | A | %100 | 30,00 TL/saat |
| Analist-2 | Work | A | %100 | 30,00 TL/saat |
| Yazılımcı-1 | Work | Y | %100 | 50,00 TL/saat |
| Yazılımcı-2 | Work | Y | %100 | 50,00 TL/saat |
| Test Uzmanı-1 | Work | T | %100 | 30,00 TL/saat |
| Test Uzmanı-2 | Work | T | %100 | 30,00 TL/saat |
| Test Uzmanı-3 | Work | T | %100 | 30,00 TL/saat |
| Hosting Service | Material | H | | ?000,00 TL |

<!-- BELİRSİZ: Hosting Service tutarının ilk hanesi karede imleçle örtülü. -->

Slayttaki açıklamaya göre kaynaklar kişiler veya materyaller olabilir; örnekte kişiler için saat başı ücretler görülmektedir ve proje maliyet tahminleri bu şekilde yapılabilir.

"En fazla %100", kaynağın çalışma süresinin tamamını bu projeye ayırdığını gösterir; bu durumda kişi projeye adanmış çalışıyor demektir. Hoca bunun çoğu zaman gerçekçi olmadığını vurguladı: bir test uzmanı aynı anda iki projenin kullanıcı testini yapabilir, o zaman %70 ya da %50 yazılabilir. Ücret büyük projelerde saat yerine gün üzerinden de verilebilir (günde 8 saat çalışma ya da günlük ücret); birim TL/saat ya da TL/gün diye yazılır. Hosting hizmeti gibi bir malzemenin de ne kadar ve ne zaman kullanılacağı belirtilir. Maliyet ya da bütçe hesabında kişinin ne kadar çalıştığı ve ücreti üzerinden bütçedeki maliyet çıkarılır.

Kaynaklar tanımlandıktan sonra faaliyetlere atanır. "Analist-1, Analist-2" yazmak görevin rolünü ve o rolün ücretini gösterir. Kişilere özel bir görev planı dağıtmak istendiğinde rol yerine kişinin adı yazılır; böylece herkes görevini bilir. Gantt şeması tersten de okunabilir: bir çalışana "bu projedeki takvimin" diye yalnız kendi faaliyetleri verilebilir.

## 3. PERT diyagramı ve süre tahmini

### 3.1 PERT ağ diyagramı

PERT (Program Evaluation and Review Technique), programın, planın geliştirilmesi ve gözden geçirilmesi tekniğidir. Graf temelli bir yöntemdir: düğümlerde faaliyetler, kenarlarda faaliyetler arası bağlantılar vardır. MS Project'te "Network Diagram" seçeneği seçilince her düğümde faaliyetin adı, başlangıç ve bitiş tarihi, süresi ve atanan kaynak görülür (örneğin fizibilite çalışması, toplantı, ön tasarım, ayrıntılı tasarım, tekrar toplantı). Kritik yol yine pembe-kırmızıyla, Gantt'taki değerlendirme kilometre taşları eşkenar dörtgenle gösterilir. Örnekte yalnız bir düğüm mavidir ve kritik yolda olmayan, alternatifi olan işi gösterir.

### 3.2 Belirsiz süreler ve üç noktalı tahmin

Planlama adımlarında faaliyetler girildikten sonra her birinin ne kadar sürede tamamlanacağı girilir. Hoca burada "gizli bir işlem" olduğunu belirtti: yazılım geliştirme gibi bir işte bir projede analiz 3 gün sürer, başka bir projede 6 ya da 7 gün sürer. Bu süre daha önce benzer bir projenin yapılmış olmasına, analiz süreçlerinin ne kadar anlaşıldığına ve yerinde incelemenin ne kadar karmaşık olduğuna bağlıdır. Bu yüzden süreler başta belirgin şekilde verilmez, projelerde bir belirsizlik vardır ve süreler PERT yöntemiyle hesaplanır.

Her faaliyet için üç tahmin yapılır:

- $A$: en kötümser süre (iş en geç ne kadar sürede biter),
- $B$: en iyimser süre (iş en hızlı ne kadar sürede biter),
- $C$: en olası süre.

Hocanın verdiği formüller:

$$T = \frac{A + 4C + B}{6} \qquad \text{ya da} \qquad T = \frac{A + 2C + B}{4}$$

> **Ders sonrası not:** Klasik PERT'te beklenen süre $\dfrac{A+4C+B}{6}$ formülüyle hesaplanır (beta dağılımı varsayımı). Hocanın ikinci olarak söylediği $\dfrac{A+2C+B}{4}$ büyük olasılıkla en olası süreye daha az ağırlık veren basitleştirilmiş bir ağırlıklandırmadır; standart PERT formülü birincisidir.

Süreleri belli olan otomasyon süreçlerinde bu hesaba gerek yoktur. Örneğin bir kimya prosesinde birinci adımın, ikinci adımın süresi ya da fabrikadaki bir bantta makinelerin çalışma süresi bellidir. Yazılım projelerinde ise bu hesap gerekir.

## 4. MS Project menüleri ve proje planlama adımları

### 4.1 Uygulamanın tanıtılması

Hoca MS Project'in eski bir sürümünün menülerini anlatan bir sunum açtı (ekrandan, 00:20:00). Slayta göre Microsoft Project yazılımının menüsünden yararlanarak:

1. Faaliyetler takvim üzerinde gösterilebilir (Calendar).
2. Gantt şeması çizdirilebilir (Gantt Chart).
3. Ağ diyagramı çizdirilebilir (PERT Chart).
4. Faaliyetlerde kullanılan kaynaklar görülebilir (Task Usage).
5. Kaynak kullanım yüzdeleri ve atıl kaynaklar analiz edilebilir.
6. Kaynak maliyetleri analiz edilebilir (Resource Graph).

Ayrıca "Analizler" menüsünden yararlanılarak farklı analizler yapılabilir. Takvimde projenin başlangıç zamanı ve cumartesi-pazar dışındaki tatil günleri gibi projeyle ilgili genel tanımlar verilir.

### 4.2 Gantt diyagramından elde edilen çıktılar

- Her faaliyetin süresi, başlangıç ve bitiş tarihleri,
- Faaliyetler arasındaki bağımlılıklar,
- Faaliyetin kritik yol üzerinde olup olmadığı,
- Kritik yolda olmayan faaliyetlerin bolluğu,
- Projenin başlama tarihinden yola çıkarak toplam süresi ve bitiş tarihi.

### 4.3 Proje planlamasında izlenecek yollar

Slayttaki "Microsoft Project Map" şeması (ekrandan, 00:25:00) dört büyük aşama ve on numaralı adımdan oluşur:

```text
Define the project (projeyi tanımla)
Build the plan (planı oluştur)
  1 Set a project start date   (başlangıç tarihini belirle)
  2 Enter tasks                (görevleri gir)
  3 Enter durations            (süreleri gir)
  4 Assign resources           (kaynakları ata)
  5 Link tasks                 (görevleri bağla)
  6 Print the plan             (planı yazdır)
  7 Fine-tune the plan         (planda ince ayar yap)
Track and manage (izle ve yönet)
  8 Set a baseline             (taban planı kaydet)
  9 Enter actuals              (gerçekleşenleri gir)
  10 Adjust the plan           (planı ayarla)
Close the project (projeyi kapat)
```

Önce proje tanımlanır: proje takvimi, projenin durumu ve genel bilgiler. Sonra plan oluşturulur: başlangıç tarihi, faaliyetler, süreler (bölüm 3.2'deki tahminle), kaynaklar ve görevlerle bağlantıları girilir; plan çıkarılır ve üzerinde ayarlamalar yapılır.

Plan tamamlandıktan sonra gerçek uygulama izlenerek plan yönetilir. Bunun için bir baseline (taban plan) kaydedilir. Baseline ile sorulan soru şudur: plan ilk haliyle duruyor mu? Gerçekleşenlerle plan arasında fark varsa plan güncellenir ve yeni bir taban oluşturulur. Bu, proje bitene kadar sürer. Plan bilgisinde proje planının kaç kez, hangi adımlarda ve nasıl değiştiği de kaydedilir.

### 4.4 Görev türleri ve görev bağlılıkları

Görev türleri (kaynakların sabit olması, iş miktarının sabit olması vb.) slaytta yer aldı, ama hoca bu tanımların çok kullanılmadığını söyledi. Görev bağlılıkları (finish-to-start, start-to-start vb.) bir menüden seçilerek tanımlanır. Gantt şemasında kritik yoldaki yollar kırmızıyla gösterilir; bazı faaliyetlerde bolluk (slack time) vardır, bazılarında yoktur.

### 4.5 Projeyle ilgili genel bilgiler ve takvim seçenekleri

Projenin başında para birimi, görev türü, takvim, önceliklerin nasıl oluşturulacağı gibi genel bilgiler girilir. Slayttaki ekran (ekrandan, 00:30:00) Tools > Options > Calendar seçeneğini gösterir; burada haftanın ve yılın başlama zamanı ile çalışma süreleri girilir:

| Seçenek | Değer |
|---|---|
| Week starts on | Monday |
| Fiscal year starts in | January |
| Default start time | 08:00 |
| Default end time | 17:00 |
| Hours per day | 8,00 |
| Hours per week | 40,00 |
| Days per month | 20 |

Hoca, normal bir projede takvimin ocak ayından başladığını, ama maliye ile ilgili bir projede mali yılın farklı bir aydan başlayabileceğini söyledi. Haftanın başlangıç günü pazartesidir. Günlük çalışma süresi ve ne kadardan sonrasının fazla mesai sayılacağı da bu başlangıç bilgilerinde verilir.

> **Ders sonrası not:** Hoca maliye ile ilgili bir projede mali yılın mart ayında başlayacağını söyledi. Türkiye'de mali yıl büyük olasılıkla takvim yılıyla aynıdır (ocakta başlar); mali yılın başlangıç ayı ülkeye ve kuruma göre değişir. Buradaki asıl nokta, bu ayarın projeye göre değiştirilebilmesidir.

### 4.6 Ekip haberleşmesi, atama bilgileri ve filtreleme

Proje yönetim yazılımlarında ekip içindeki haberleşme ve kişilere görev ataması da düzenlenir. Hoca bunun bugün Microsoft Teams gibi uygulamalarla da yapıldığını, MS Project'te bu özelliğin küçük ölçüde bulunduğunu söyledi. Atama bilgisi, kaynak bilgisi bölümünden hangi faaliyete hangi çalışanın atanacağını, ne kadar çalışacağını ve kalan işin kaç saat olduğunu gösterir.

Project menüsündeki filtreleme seçenekleriyle (ekrandan, 00:35:00) bütün görevlere, tamamlanmış görevlere, tamamlanmamış görevlere ve kritik yola (Critical) göre filtreleme yapılabilir. Menüde ayrıca Milestones, Summary Tasks, Date Range gibi filtreler de görünür.

## 5. Fizibilite türlerinin tekrarı

Analize geçmeden önce fizibilite analizi kısaca tekrar edildi. Fizibilitede bir problemin farklı çözüm olanakları değerlendirilir:

- Teknik fizibilite (teknik olurluluk): istenen çözümün teknolojik yapısı nedir, teknik olarak yapılabilir mi?
- Ekonomik fizibilite: çözümün maliyeti ve getirisi nedir; yapılan harcamalar alınan sonuçlara değiyor mu?
- Kullanılabilirlik fizibilitesi: çok iyi bir çözüm bulunmuş olabilir, ama hazırlanan yazılım kullanıcılarına ve onların iş hayatına uygun mu, kullanıcı bu çözümü kabul eder mi?
- Alternatif fizibilite: projenin farklı çözümlerinin her biri teknik, ekonomik ve kullanışlılık açısından ayrı ayrı değerlendirilir.
- Yasal fizibilite: çözüm hukuki bir problem çıkarıyor mu, kullanılan veri açısından sorun var mı?

Fizibilite, yapılabilirlik ya da olurluluk anlamına gelir.

## 6. Analiz aşaması: analiz ile tasarımın farkı

### 6.1 Sınıfa sorulan soru

Hoca analiz aşamasına geçerken sınıfa sordu: analizde ne yapıyoruz, tasarımda ne yapıyoruz?

Bir öğrenci analiz aşamasını, bilgi sisteminin hangi özellikleri olması gerektiğini anlama ve bunları detaylandırma aşaması olarak tanımladı: sistemin özellikleri ve hangi amaca hizmet edeceği hakkında ayrıntılı bir analiz. Hoca bunu şöyle tamamladı: burada yazılımın nasıl yapılacağı konusu değil, yazılımı hazırlanması istenen sistem tanınmaya çalışılır.

### 6.2 Öğrenci bilgi sistemi örneği

Bir öğrenci bilgi sistemi kurulacaksa, analizde "nasıl bir teknik altyapı kurmalıyız, hangi veritabanını kullanmalıyız" gibi sorulardan önce şunlar sorulur:

- Bu sistem hangi işleri gerçekleştirecek, hangi alt başlıkları var?
- Kimler kullanacak, nasıl bir ortamda çalışacak?
- Farklı bakış açılarına sahip kullanıcılar kimler?

Öğretim üyeleri kendi açılarından bakar: notlarını rahat girebiliyorlar mı, öğrencilerini rahat görebiliyorlar mı? Öğrencilerin bakış açısı farklıdır: notlarını görebiliyorlar mı, bilgilerini kolay girebiliyorlar mı? Öğrenci işleri ise ders alma dilekçelerinin ve ders seçimlerinin kolay ve güvenli yapılıp yapılamadığına bakar. Her birinin bakış açısından sistemde gerçekleşen işlemler belirlenir.

### 6.3 Fizibiliteyi kim yapar?

**Soru:** Fizibilite analizi kimin görevi?
**Cevap:** Bu, sektörde çalışılan proje ekibinin büyüklüğüne bağlıdır. Proje yöneticisi varsa fizibiliteyi o yürütür; yoksa birçok işi birlikte yapan sistem analisti hazırlar. Proje yöneticisi hangi çözümün iyi olduğuna karar verirken ağ uzmanına, yazılım tasarımcılarına, yazılım geliştiricilere ve veritabanı uzmanlarına danışır; ama işi yapan proje yöneticisidir, böyle bir rol tanımlı değilse sistem analistidir.

### 6.4 Sistem analizi: yukarıdan aşağıya ayrıntı

Fizibilite analizinden sonra gereksinim analizi ya da sistem analizi gelir. Sistem analizinde yapılan işin en ince ayrıntıları öğrenilmeye çalışılır, ama yukarıdan aşağıya doğru: önce büyük resim, yani öğrenci bilgi sisteminin hedefleri kaybedilmeden, ayrıntıya boğulmadan, planlı olarak ilerlenir. Sistemin çalışmasını doğru planlayabilmek için her muhataptan sistemle ilgili bilgi toplanmalıdır.

### 6.5 Tasarım nedir?

Bir öğrenci tasarımı şöyle tanımladı: analizde ortaya konan problemlerin çözümlerini nasıl gerçekleştireceğimizi planladığımız aşama; önce genel tasarım, sonra alt sistemlerin ve her problemin o sistem içinde nasıl çözüleceğinin ayrıntılı tasarımı. Yani tanıdığımız problemi, gerçekte uygulamadan, nasıl çözeceğimizi belirlemek. Hoca bunu onayladı: analiz iyi yapılmış ve sistemin ne yapması gerektiği anlaşılmışsa, bunun bilgisayar sistemine nasıl aktarılacağına da daha doğru karar verilir.

> **Hocanın vurgusu:** Sistem analizi, gerçekleştirilecek bilgi sisteminin ne olduğunu ve ne yaptığını anlamamızı sağlar. Tasarım ise bunu bilgisayar ortamına nasıl aktaracağımızı belirler. İkisinin arasındaki fark budur.

## 7. Modeller ve modelleme

Bu bölümden sonra hoca Satzinger, Jackson ve Burd'ün "Systems Analysis and Design in a Changing World" kitabının 5. bölüm slaytlarını kullandı.

### 7.1 Modeller ve modelleme

Slayttaki maddeler (ekrandan, 00:40:00):

- Analist, bilgi sistemi gereksinimlerini bir model kümesiyle anlatır.
- Karmaşık sistemler birden fazla model türü gerektirir.
- Modeller, inşa edilen sistemin bir yönünü temsil eder.

Üzerine bilgi sistemi geliştirilmek istenen sistemler karmaşık olabilir ve farklı bakış açıları içerebilir; bir model bunların hepsini görüntüleyebilmelidir. Modelleme sonucunda önce sistemin ne yaptığı öğrenilir.

### 7.2 Modellemenin nedenleri

Hocanın slayt üzerinden anlattığı nedenler:

- Soyutlama yapmak, yani özetlemelerle karmaşıklığı azaltmak. Bu, büyük resmi kaybetmeden sırayla ve planlı şekilde ayrıntılara geçmek demektir.
- Tüm ayrıntıları sırayla incelemek.
- Geliştirme ekibi üyeleriyle iletişim kurmak. Fizibiliteden başlayarak kararları doğru vermek ve sistem analizinde olayları iyi anlamak için hem müşteriyle hem ekip üyeleriyle iletişimde olmak gerekir.
- Kullanıcı ve paydaşlarla iletişim kurmak.
- Gelecekte bakım yapabilmek için belgeleme oluşturmak.

### 7.3 Model türleri

Analiz aşamasında önce bilgi toplanır, sonra toplanan bilgi modellenir. Slayttaki model türleri:

- Matematiksel modeller: sistemin teknik yönlerini anlatan formüller.
- Tanımsal (descriptive) modeller: sistemin yönlerini anlatan anlatı metinleri, raporlar, listeler; hocanın örnekleriyle kullanım durumu belgeleri, hikayeler (story).
- Grafik modeller: sistemin bir yönünün diyagram ve şematik gösterimi; örneğin kullanım durumu diyagramları, veri akış diyagramları.

Hoca, bu dersin konusunun da gerçek hayat hikayelerinin nasıl modelleneceği olduğunu söyledi.

### 7.4 Analiz ve tasarımda kullanılan modeller

Slayttaki karşılaştırma:

- Analiz aşaması, "sistem gereksinimlerini tanımla" etkinliğidir ve mantıksal modeller kullanır. Mantıksal modeller belirli bir teknolojiden bağımsız olarak ayrıntı verir.
- Tasarım aşaması fiziksel modeller kullanır. Fiziksel modeller teknik ayrıntıları verir ve mantıksal modelleri genişletir.

## 8. Olayların belirlenmesi ve olay tablosu

### 8.1 Sistemi etkileyen olaylar

Bir olayı anlamak için o olayı etkileyen başka hangi işlemlerin olduğuna bakılır. Hocanın örneği bir müşteriye fatura verme işlemidir: para alınacak, fatura verilecek. Farklı kullanıcılar hangi işleri yapıyor (faturaya karşılık ödeme yapma, adres bilgisini güncelleme), bu işlemler hangi zamanda ve hangi sırayla gerçekleşiyor? Önce bunlar yerleştirilir. Sonra bu olayların nasıl ve hangi koşullarda gerçekleştiği ve sistem akışının nasıl olduğu tanımlanır.

Aradan sonra hoca olayların sırasını doğru belirlemenin önemini alışveriş örnekleriyle açıkladı:

- Müşteri mağazaya gider, ürünü inceler ve dener, satın alır; fatura ve ödeme bu sırada yapılır.
- Web sitesinden alışverişte önce siteye bağlanır, ürünleri inceler, hangisini alacağına karar verir, sepete ekler, sepette son değişiklikleri yapar, ödemeye geçer ve ödeme bilgilerini kaydeder.
- Telefonla sipariş veren müşteri için de gerçekleşen işlemlerin hangileri olduğu ve sırası belirlenmelidir.

Her durumda farklı işlemler vardır ve bunların bir sıraya sokulması gerekir. Analizde hangi işlemlerin gerçekleşeceğine ve bunlarla ilgili kullanıcıların kimler olduğuna bakılır. Bu olay sıraları sonra tasarıma aktarılır; veritabanı kullanılıp kullanılmayacağı ya da geri ödeme işlemi için veritabanının hangi olanaklara sahip olması gerektiği tasarımın sorusudur, analizde bu aşamaya geçilmez.

### 8.2 Olayları belirlemek

Slayttaki maddeler (ekrandan, 00:50:00):

- Olayları belirlemek zor olabilir.
- Olaylar çoğu zaman koşullar ve yanıtlarla karıştırılır.
- Bir işlemin (transaction) yaşam döngüsünü izlemek yararlı olabilir.
- Bazı olaylar tasarım aşamasına bırakılır:
  - Sistem kontrolleri,
  - Kusursuz teknoloji varsayımı (perfect technology assumption).

> **Ek bilgi (derste anlatılmadı):** Kusursuz teknoloji varsayımı, analizde donanım arızası, yedekleme, oturum açma gibi teknolojinin kusurlu olmasından doğan olayların dikkate alınmaması, yalnız işin kendisinden doğan olayların modellenmesi demektir. Bu tür olaylar büyük olasılıkla tasarımda sistem kontrolleri olarak ele alınır.

### 8.3 Olay tablosu

Her olay için toplanan bilgi bir olay tablosuna yazılır (ekrandan, 01:05:00, kitaptaki Figure 5-14). Slayttaki örnek satır ve sütun açıklamaları:

| Event | Trigger | Source | Activity/Use Case | Response | Destination |
|---|---|---|---|---|---|
| Customer wants to check item availability | Item inquiry | Customer | Look up item availability | Item availability details | Customer |

- Event (olay): sistemin bir şey yapmasına neden olan olay. Örnekte müşteri bir ürünün mevcut olup olmadığını öğrenmek istiyor.
- Trigger (tetikleyici): sistem olayın gerçekleştiğini nasıl bilir? Dış olaylarda bu, sisteme giren veridir; zamana bağlı olaylarda sistemin işlemesini tetikleyen zaman noktasının tanımıdır. Örnekte ürün sorgusu.
- Source (kaynak): dış olaylarda sisteme giren verinin kaynağı olan dış etken ya da aktör. Örnekte müşteri.
- Activity/Use Case (etkinlik/kullanım durumu): olay gerçekleşince sistem ne yapar? Örnekte ürün mevcudiyetine bakmak.
- Response (yanıt): sistem hangi çıktıyı (varsa) üretir? Örnekte ürün mevcudiyet ayrıntıları.
- Destination (hedef): çıktıyı hangi dış etken alır? Örnekte müşteri.

## 9. Varlıklar, nitelikler, ilişkiler ve nesneler

### 9.1 Varlıklar ve sistem gereksinimleri

Sistem gereksinimlerine bakarken sorulacak soru şudur: sistemde saklanması gereken bilgiler nelerdir? Slayta göre bunun sonucu sistemin anlaşılması ve bir model kümesidir. Bu olayla ilişkili farklı tipteki varlıklar önce listelenir; sistem hakkındaki gerekli bilgilerin kategorileri doğru belirlenir, yapılan varsayımlar da doğru belirlenmelidir.

Öğrenci sistemi örneğinde varlıklar öğretim üyesi, öğrenci, öğrenci bürosu ya da bölüm memurları gibi görevliler, dersler ve ders programı yapılırken sınıflardır. Analizde bu varlıklar, aralarındaki ilişkiler ve varlıkların özellikleri ortaya çıkarılır; bunlar daha sonra veritabanı yapısında da kullanılacaktır. Örneğin bir öğretim üyesi için hangi bölüme ait olduğu (bölüm ile kişi ilişkisi), üniversitede tanımlı kimlik bilgileri ve hangi dersleri verdiği (derslerle ilişkisi) önemlidir. Bu uygulamada gereksiz özellikler elenmelidir.

### 9.2 Nitelikler ve değerler

Bir müşteri için hangi özellikler gerekir? Slayttaki örnekte müşteri numarası (customer ID), ad (first name), soyad (last name) ve telefon nitelikleri vardır. Bunlar niteliklerdir (attribute); her müşteri için bu niteliklere atanan bilgiler de değerdir. Örnekte 101 numaralı müşteri John Smith, 102 numaralı müşteri Mary Jones'tur ve her birinin telefon bilgisi bulunur.

Varlıklar arasındaki ilk temel ilişkilendirme de sistem analizi sırasında yapılır: örneğin müşteri ürün alacaksa hangi birimlerle ilişkili işlemler gerçekleşir?

### 9.3 Basit varlık-ilişki diyagramı

Slayt değişimi sırasında ekranda kalan basit varlık-ilişki diyagramı (ekrandan, 01:15:00, Figure 5-22; derste ayrıca anlatılmadı) iki varlık arasındaki bir ilişkiyi gösterir:

```text
[Customer] -|-----------O< [Order]
```

- Bir müşteri sıfır ya da daha fazla sipariş verebilir (Order tarafındaki daire ve çatal "sıfır ya da çok" anlamındadır).
- Bir sipariş tam olarak bir müşteri tarafından verilmelidir (Customer tarafındaki dik çizgi "tam olarak bir" anlamındadır).

Hoca veritabanı yapıları ve varlıklar arası ilişkiler üzerinde ilerleyen derslerde duracaklarını söyledi.

### 9.4 Nesneler

Nesne tarafından bakıldığında soru, sistemdeki bilgilerin nasıl saklanacağı, nesnelerin hangi davranışlarda bulunduğu, hangi özelliklere sahip olduğu ve hangi sınıfa ait olduğudur. Slayttaki maddeler (ekrandan, 01:10:00):

- Nesneler sistemdeki işi yapar ve bilgi saklar.
- Davranışları ve nitelikleri vardır.
- Sınıf (class): şeyin türü.
- Nesne (object): belirli bir şey.
- Metotlar (methods): nesnelerin davranışları.

Nesne tanımında bir nesneyle ilişkili veri özellikleri, bu veri üzerinde işlem yapan metotlar ve bu metotların hangi mesajlarla etkin hale getirildiği belirlenmelidir.

### 9.5 Veri varlıkları ile nesnelerin karşılaştırılması

Geleneksel yaklaşımda bir veri varlığı tanımlanır ve bu varlığın hangi işlemlere (proseslere) uğradığına bakılır. Veri ile süreç ayrıdır: süreç dışarıdan girdi alır, veritabanında tutulan varlıkla ilgili işlem yapar ve çıktı üretir. Nesneye yönelik yaklaşımda ise veri ile onu işleyen metotlar nesnenin içinde birlikte bulunur ve metotlar mesajlarla çağrılır.

> **Ek bilgi (derste anlatılmadı):** Satzinger ve arkadaşlarının kitabında veri varlıkları varlık-ilişki diyagramıyla (ERD) modellenir ve genellikle ilişkisel veritabanı geliştirmede kullanılır; nesneler ise sınıf diyagramıyla modellenir. Ders slaytlarının sonunda sınıf diyagramı örnekleri de bulunuyordu, ama bunlar bu derste anlatılmadı.

## 10. Müşteri destek sistemi örneği

Hoca bu bölümde, daha önce fizibilite konusunda kısaca gösterdiği başka bir sunuma geçti. Analiz aşamasına başlarken ilk soru sistemin işletmecilik faydalarının ne olacağı, ne beklendiğidir.

### 10.1 Şirketin hedefleri

Örnekte bir şirketin müşteri destek sistemi iyileştirilecektir. Şirket stratejik planlama çalışmaları sırasında uzun vadede satışları, müşteri desteğini ve envanteri iyileştirmek istiyor ve yeni bir müşteri destek sistemi kurulacak. Hocanın anlattığı kritik hedefler:

- Siparişlerden gelen hataları azaltmak,
- Sipariş işlemeyi hızlandırmak,
- Web sayfasından siparişi de içerecek şekilde bütün siparişleri karşılamak ve sipariş işlemede çalışan sayısının artmasını sınırlamak,
- İnternet sayesinde yeni satış kanallarını daha etkin kullanmak,
- Ürünleri takip ederek satışları hareketlendirmek,
- Müşteri sadakatini artırmak.

Hoca, kaçan müşterilerin takibi ve müşteri sadakatinin ölçülüp artırılması gibi çalışmaların özellikle veri madenciliğinde çok önemli olduğunu ekledi.

<!-- BELİRSİZ: Çalışan seviyeleriyle ilgili hedefin tam ifadesi altyazıda bozuk ("belli bir sesle içinde çalışmalarını azaltmak"). -->

### 10.2 Sistemin yetenekleri

Bu hedefleri karşılamak için sistemin sahip olması gereken yetenekler slayttaki listeyle verildi (ekrandan, 01:20:00, Figure 2-7). Müşteri destek sistemi şu hedefleri karşılamalıdır:

- Çevrim içi müşteri, sipariş, geri sipariş (back order) ve iade bilgisi sunan yüksek destekli bir sistem olmak.
- Hızlı giriş ekranlarıyla geleneksel telefon ve posta kataloğu satışlarını desteklemek.
- Satın alma ve sipariş takibi dahil, internetten müşteri ve katalog satış yeteneği içermek.
- Pazar analizini desteklemek için yeterli veritabanı ve geçmiş bilgisini korumak.
- Müşteri sorguları için müşteri işlemlerinin geçmişini sağlamak.
- Hacimdeki büyük artışları (yüzde 300 ya da daha fazla) performans düşmeden karşılayabilmek.
- Yeni siparişlerin 24 saat içinde gönderimini desteklemek.
- Birden çok depodan sipariş gönderimini koordine etmek.
- Satış analizi ve pazar talebi tahmini için geçmişi saklamak.

Hocanın açıklamalarına göre sistem hem web ekranından hızlı sipariş vermeyi hem de eski yöntemle telefondan sipariş vermek isteyenleri desteklemeli, yani sipariş verme yelpazesi geniş olmalıdır. "Siparişim nerede?" diye soran internet müşterisine cevap verilebilmelidir. "Son iki senede hangi üründen ne kadar satış yaptık?" gibi pazar analizi sorgularını desteklemek için arşiv verisi kullanılabilmeli, müşterinin yaptığı işlemler tarihsel olarak tutulmalıdır.

Bu bilgiler analizde ortaya çıkarılır. Her biri tasarım sırasında veritabanı ya da ağ ile ilgili bir teknik gerekliliğe dönüşür. Talep tahmini, satış analizi, arşiv verisi ve pazar analizi gibi gereksinimler veri madenciliği problemleri ve çözüm alternatifleri olarak karşımıza çıkar.

> **Hocanın vurgusu:** Analiz aşamasında sistemin işletmecilik gereksinimleri ve bu gereksinimlerin sistemde hangi yeteneklerle sağlanacağı çıkarılır.

## 11. Bağlam diyagramı ve veri akış diyagramı paketi

### 11.1 Veri akış diyagramı paketi

Analiz aşamasında müşteri destek sisteminin bir yapısı da çıkarılır; bu bir veri akış diyagramıdır (data flow diagram, DFD). Veri akış diyagramları bir paket, bir silsile halinde kullanılır ve üç kademeden oluşur:

1. Bağlam (context) diyagramı ya da taslak/özet veri akış diyagramı: yalnız dış varlıklar ve tek bir süreç (istenen işi gerçekleştiren genel sistem) bulunur. Bu sistemle varlıklar arasındaki iletişimin nasıl yürüdüğü, nereden nereye bilgi ya da veri gittiği tanımlanır.
2. Birinci düzey ayrıntılı veri akış diyagramı: sistemin içi açılır; tek süreç yerine sistemin bütün alt süreçleri gösterilir.
3. İkinci düzey ayrıntılı veri akış diyagramı: genel sistemin her bir alt parçası için ayrı ayrı çizilir.

> **Hocanın vurgusu:** Bağlam diyagramında tek süreç vardır: müşteri destek sistemi. Sistemin alt parçaları ve alt sistemleri gösterilmez; yalnız sistemin hangi varlıklarla ilişkili olduğu gösterilir.

### 11.2 Müşteri destek sisteminin bağlam diyagramı

Slayttaki diyagram (ekrandan, 01:25:00, Figure 2-8, "Context diagram for the RMO customer support system") ortada 0 numaralı "Customer support system" sürecini ve çevresinde yedi dış varlığı gösterir. Oklara göre veri akışları şöyledir:

| Dış varlık | Varlıktan sisteme | Sistemden varlığa |
|---|---|---|
| Marketing (pazarlama) | Promotion package info | Prospective Cust Info |
| Customer (müşteri) | New order, Item return info, Customer change notice | Back order notice, Shipment BOL |
| Bank (banka) | | Deposit information |
| Credit bureau (kredi bürosu) | Credit verification (kırık çizgi) | |
| Merchandising (sales) (satış) | Catalog updates | Sales reports, Performance reports |
| Management (yönetim) | | Fulfillment reports, Sales reports, Activity reports |
| Shipping (ürün gönderme) | Order fulfillment, Back order notice | Order details |

<!-- BELİRSİZ: Credit verification akışının yönü karede şimşek biçimli çizgiden net okunmuyor; hoca yalnız kredilerin doğrulanması için bir kontrol hakkı olduğunu söyledi. -->

Hocanın açıklamaları:

- Pazarlama birimi hangi promosyonların olduğunu girer; sistem pazarlamaya olası (potansiyel) müşteri bilgisini verir.
- Müşteri, sipariş verdiğinde, siparişi geri gönderdiğinde (iade), bilgilerinde değişiklik bildirdiğinde ve siparişi kendisine geldiğinde sistemle ilişkilidir.
- Bankaya sistemden ödeme bilgileri gider.
- Sistem ürün gönderme birimine sipariş ayrıntılarını gönderir; gönderme birimi de siparişin karşılandığı bilgisini ve geri sipariş bildirimini verir.
- Yönetimden sisteme bilgi gelmez; sistem yönetime belli aralıklarla sipariş karşılama raporlarını, satış raporlarını ve aktivite raporlarını gönderir.
- Satış birimi sistemden satış raporlarını ve performans raporlarını alır; kataloglarda değişiklik varsa (yeni ürün eklendiyse ya da bir ürün artık üretilmiyorsa) bunları katalog güncellemesi olarak sisteme aktarır.

**Soru:** Kredi bürosu kısmındaki bağlantı neden diğerlerinden farklı çizilmiş? Özel bir sebebi var mı?
**Cevap:** Bu, uzaktan bağlantıyı gösterir. Banka da dahil diğer varlıklar şirketin birlikte çalıştığı birimlerdir; kredi bürosuyla bağlantı ise kırık çizgiyle uzaktan bağlantı olarak çizilmiştir.

## 12. Bilgi toplama yolları

Hoca, bilgi toplama yollarına bu derste ayrıntılı girmediğini, olayların ve nesnelerin nasıl dinleneceği gibi modelleme için gereken ön bilgilerin nasıl sağlandığını gördüklerini söyledi. Bilgi toplama yolları şunlardır:

- Anket düzenlemek,
- Görüşme (interview) yapmak,
- Toplantılar yapmak,
- Yerinde incelemek,
- Aynı ya da benzer sistemi kullanan başka kullanıcıların sistemlerini incelemek.

Analiz aşaması bilgi toplama, modelleme ve analiz raporunun oluşturulup değerlendirilmesi adımlarından oluşur.

## 13. Örnek Sorular

**Soru 1** (derste sözlü, 00:36:58): Analiz ve tasarım aşamalarına baktığımızda analizde yaptığımız iş nedir, tasarımda yaptığımız işler nelerdir?

> **Cevap (derste verildi):** Analizde, yazılımı hazırlanacak sistemin ne olduğu ve ne yaptığı anlaşılır: hangi işleri yaptığı, kimlerin hangi bakış açısıyla kullandığı, hangi ortamda çalıştığı. Teknik altyapı ve veritabanı seçimi gibi sorular sorulmaz. Tasarımda ise analizde anlaşılan sistemin bilgisayar ortamına nasıl aktarılacağı belirlenir: önce genel tasarım, sonra alt sistemlerin ayrıntılı tasarımı.

**Soru 2** (derste sözlü, 00:13:06): Kritik yol üzerindeki işlerde bolluk süresi olabilir mi?

> **Cevap (derste verildi):** Hayır. Kritik yol üzerindeki bir faaliyetin her gecikmesi projenin bitişini aynı miktarda geciktirir. Bolluk yalnız kritik yolda olmayan faaliyetlerde bulunur; örnekte sistem testinin 27.04'ten 29.04'e kadar 2 iş günü bolluğu vardır.

**Soru 3** (derste sözlü, 00:39:49): Fizibilite analizi kimin görevidir?

> **Cevap (derste verildi):** Ekip büyüklüğüne bağlıdır. Proje yöneticisi varsa o yürütür ve kararları ağ uzmanı, yazılım tasarımcısı, geliştirici ve veritabanı uzmanına danışarak verir; böyle bir rol yoksa birçok işi birlikte yapan sistem analisti yürütür.

**Soru 4** (derste sözlü, 01:32:41; diyagram ekrandan, 01:25:00): Müşteri destek sisteminin bağlam diyagramında kredi bürosuyla bağlantı neden diğerlerinden farklı çizilmiştir?

> **Cevap (derste verildi):** Kırık (şimşek biçimli) çizgi uzaktan bağlantıyı gösterir; diğer varlıklar şirketin birlikte çalıştığı birimlerdir.

**Soru 5** (ekrandan, 00:05:00 ve 00:10:00): Kitap satış web sitesi Gantt şemasında sistem testinin bolluk süresi kaç gündür?

> **Cevap (derste verildi):** Sistem testi 26.04-27.04 arasında yapılır, proje 29.04'te biter. Aradaki 28.04 ve 29.04 iş günleri nedeniyle sistem testi projeyi geciktirmeden 2 iş günü kayabilir; bolluk 2 gündür (python ile iş günü sayılarak doğrulandı).

## Dersin Toparlaması

Ders, önceki haftanın konusu olan proje planlamayı MS Project üzerinden tamamladı: iş kırılım yapısıyla faaliyetlerin tanımlanması, faaliyetler arası bağlantı tipleri, kritik yol ve bolluk, kaynak atamaları ve maliyet, PERT ağ diyagramı ve belirsiz sürelerin üç noktalı tahmini, baseline ile planın izlenmesi. Ardından fizibilite türleri hatırlatılarak analiz aşamasına geçildi. Analizin "ne", tasarımın "nasıl" sorusu olduğu vurgulandı; analizde bilginin toplanıp modellendiği, modellerin matematiksel, tanımsal ve grafik olabileceği, analizde mantıksal, tasarımda fiziksel modellerin kullanıldığı anlatıldı. Olayların belirlenmesi ve olay tablosu, varlıklar, nitelikler, ilişkiler ve nesne kavramı kitabın slaytları üzerinden gösterildi.

Son olarak bir müşteri destek sistemi örneğinde şirketin işletme hedeflerinden sistem yeteneklerine geçildi ve sistemin bağlam diyagramı incelendi. Sonraki derste veri akış diyagramlarının kuralları ve yapısı, birinci ve ikinci düzey ayrıntılı diyagramların çizimi, bilgi toplama yolları ve nesneye yönelik analiz ele alınacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
