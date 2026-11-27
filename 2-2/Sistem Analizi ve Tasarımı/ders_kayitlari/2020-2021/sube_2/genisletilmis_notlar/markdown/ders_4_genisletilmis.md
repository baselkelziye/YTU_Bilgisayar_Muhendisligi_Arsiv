# Ders 4 Genişletilmiş Notu: Zaman Fizibilitesi (Gantt, PERT) ve Fizibilite Matrisi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Giriş: fizibilitenin hatırlatılması ve zaman fizibilitesi
- 2. Gantt çizelgesi
- 3. Örnek Gantt şeması: kitap satış web sitesi
- 4. WBS, tarihleme ve çalışma takvimi
- 5. Faaliyetler arası ilişkiler
- 6. Kritik yol
- 7. Kilometre taşları ve bolluk
- 8. Kaynak atamaları
- 9. MS Project uygulaması
- 10. PERT
- 11. Süre tahmini (effort estimation)
- 12. Çözüm önerilerinin değerlendirilmesi ve fizibilite matrisi
- Örnek Sorular

## 1. Giriş: fizibilitenin hatırlatılması ve zaman fizibilitesi

Ders, önceki haftada başlanan fizibilite konusunun tamamlanmasıyla başladı. Bilgi sistemi geliştirme sürecinin ilk adımı olan ön incelemede neler yapıldığı ve çıktısının ne olduğu, ardından fizibilite çalışmasının alt başlıkları (teknik, sosyal, yasal, yönetim ve ekonomik fizibilite) daha önce işlenmişti. Zaman fizibilitesi ise geçen hafta yalnız slaytlarda hızlıca geçilmiş, ayrıntısı bu haftaya bırakılmıştı. Bu haftanın iki ana başlığı vardır: zaman fizibilitesinin ayrıntıları ve altı başlıkta yapılan fizibilite çalışmalarından nasıl bir sonuç çıkarılıp raporlanacağı.

Fizibilitenin Türkçesi **yapılabilirlik etüdüdür**. Diğer fizibilite türlerinde "Bu projeyi yapabilmek için teknik olarak, yönetim açısından, karşılayacak kitle açısından, yasal ve ekonomik açıdan neler lazım?" sorularına bakılmıştı. Zaman fizibilitesinde sorulan soru şudur: **Ben bu projeyi yapabilmek için nasıl bir zaman ve iş planına ihtiyaç duyarım?** Slayttaki tanım (ekrandan, 00:05:00):

- Belirlenen zaman içinde projenin nasıl tamamlanacağı belirlenir.
- Gantt ve PERT teknikleri kullanılır.

Bu iki teknik birbirinin tümleyeni sayılabilir; biri diğerinden türetilebilir. Gantt bir kişinin soyadıdır, PERT ise (büyük harfle yazılmasından da anlaşılacağı gibi) bir kısaltmadır.

## 2. Gantt çizelgesi

Gantt diyagramı ya da daha Türkçe adıyla Gantt çizelgesi, 1910'larda proje planlama ve gidişatın kontrolü için Henry Gantt tarafından önerilmiştir; adını da önerenin soyadından alır. Slayttaki tanım (ekrandan, 00:10:00):

- Gantt çizelgesi; 1910'larda proje planlama ve kontrolü için Henry Gantt tarafından önerilmiş bir diyagramdır.
- Gantt çizelgesinde projenin işlem adımları faaliyet olarak isimlendirilir. Her bir faaliyetin süresi, başlangıç-bitiş zamanları, hangi kaynakların bu faaliyet için kullanılacağı diyagramdan çıkarılabilecek verilerdir.

### 2.1 İş paketi, faaliyet, alt faaliyet

Projede yapılması gereken işlerin farklı adları olabilir. Örneğin TÜBİTAK gibi kurumların desteklediği projelerde, zaman içindeki gidişatın ve ara çıktıların izlenebilmesi için birbiriyle ilgili bir grup iş bir araya getirilip **iş paketi** adı verilir; hediye paketi gibi bir grup işi tek bir faaliyet grubu olarak paketlemek diye düşünülebilir. İş paketinin içinde yapılması beklenen işler vardır, bunlara **faaliyet** denir. Bir faaliyeti yapmak için başka küçük faaliyetler de gerekebilir; bunlar **alt faaliyetlerdir**. Böylece ağaç yapısında bir kırılımla projede yapılacak işlem adımları faaliyetler olarak belirlenir ve adlandırılır. Her faaliyetin ne kadar süreceği, ne zaman başlayıp biteceği ve hangi kaynakları kullanacağı bu diyagramla planlanır.

### 2.2 Kaynak ve efor

Kaynak yalnız insan değildir; makine kaynağı ya da başka dış kaynaklar da olabilir. Ama kaynak planlaması denince genelde anlaşılan, faaliyette ekipte kimlerin yer alacağı, ne kadar çalışacağı ve ne kadar efor harcayacağıdır. Efor genellikle **adam-ay** (man-month) cinsinden ölçülür. Hoca bu konuya meraklı olanlara "The Mythical Man-Month" kitabını önerdi.

Bunun nedeni, her şeyin sonunda maliyete ve ekonomik fizibiliteye bağlanmasıdır: zaman bir para harcama noktasıdır. Birilerini bir hafta çalıştırmak, onların bir haftalık ücreti demektir. Kurumda birden fazla proje paralel yürüyorsa kimin hangi projede, hangi rolde, ne kadar efor harcayacağı dengelenmelidir.

Hocanın örneği: bir şirkette A, B ve C olmak üzere üç proje eş zamanlı yürüsün ve bir analist haftada iki gün A, bir gün B, iki gün C projesinde çalışsın. Haftalık 5 günlük emek 2-1-2 olarak paylaştırılmıştır; A projesine eforun $2/5 = \%40$'ı atanmıştır. Bu analist A projesine 0,4 adam-haftadan fazla yazılırsa **aşırı yüklenme** (overloading), yani fazla mesai oluşur. Bazen 0,5'e çıkmak gerekebilir; bu durumda haftada 2,5 gün çalışmış, yani yarım gün fazla mesai yapmış olur. Günümüzdeki araçlar bu durumda kaynağı kırmızıyla işaretleyip "kapasitesinin üzerine çıktı" uyarısı verir.

### 2.3 Gantt ile neler elde edilir

Özetle Gantt diyagramı, zaman planını ve kaynak atamalarını yönetmeyi sağlayan bir araçtır. Slaytta şunlar yazar (ekrandan, 00:15:00):

- Problem tanımından işletime kadar süredeki tüm aktivitelerin zamanları ve ilişkileri gösterilir.
- Durak noktaları belirlenebilir.
- Microsoft Project gibi araçlarla; proje verisi işlem ağı olarak verildiğinde
  - Yapılacak işleri tarih sırası ile gösteren, durak yerlerini ve iş yoğunluğunun az olduğu işlemleri belirleyen bir Gantt çizelgesi,
  - Yöneticinin proje sürecini izleyebilmesi için her işlemin süresini, en erken ve en geç başlama ve bitme tarihlerini gösteren bir görev durumu çizelgesi,
  - İşlem sırasına göre görev paylaşımını gösteren bir çizelge,
  - Üzerinde kritik yolu koyu çizgilerle belirleyen bir işlem ağı
- otomatik olarak elde edilir.

En bilinen araç Microsoft Project'tir. Açık kaynaklı ve web tabanlı pek çok uygulama da vardır (OpenGantt gibi). Trello gibi uygulamalarda ve ortak çalışma ortamlarında bile iş-zaman planı üretme ve izleme artık standart modül olarak yer alır.

En erken ve en geç başlama tarihleri, yöneticiye bir işin ne kadar öne çekilebileceğini ya da geciktirilebileceğini gösterir: bir hafta geç başlamak projeyi "öldürebilir" ya da sonraki iş zaten 10 gün sonra başlayacağı için hiç önemli olmayabilir. Kaynak ataması da yalnız insanlar için değildir. Bir inşaat projesinde "temel atma" faaliyetinde kalıp ustası gibi insan kaynaklarının yanında kepçe, dozer, üç kamyon gibi makine kaynakları da atanır. Yazılım tarafında hangi donanımın ya da sunucunun hangi faaliyette ne kadar kullanılacağı da böyle planlanabilir.

## 3. Örnek Gantt şeması: kitap satış web sitesi

Slaytta, kitap satışı yapılacak bir web sitesinin tasarlanmasından kullanıma sunulmasına kadar olan süreç Microsoft Project ile hazırlanmış bir Gantt şeması olarak verildi (ekrandan, 00:20:00). Proje waterfall süreç modeliyle yürütülmektedir: önce analiz, sonra tasarım, sonra geliştirme ve test, en sonda teslim.

| ID | WBS | Faaliyet | Süre | Başlangıç | Bitiş | Öncül | Kaynak |
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

Tabloda 0'dan 15'e kadar 16 faaliyet vardır; her satır Excel'deki gibi bağımsız bir faaliyettir. Kalın yazılanlar (Analiz, Tasarım, Geliştirme&Test) **özet faaliyetlerdir**, yani iş paketleridir; diyagramda düz çizgi olarak görünürler. 0 numaralı satır projenin tamamıdır. Düz yazılanlar gerçek faaliyetlerdir: birilerinin oturup bu iş için gerçekten çalışması ve sonuç üretmesi gerekir.

**Analiz (6 gün).** Elde iki analist vardır. Birinci analist 24 Mart'ta fizibilite çalışmasına başlar ve 4 günde, 29 Mart'ta bitirir. İkinci analist 25 Mart'ta gereksinimlerin belirlenmesine başlar ve 31 Mart'ta bitirir (5 gün). Aralarındaki `2SS+1 day` ilişkisi, 3 numaralı işin 2 numaralı işin başlangıcından bir gün sonra başlayacağını söyler. İki iş kısmen paralel yürüdüğü için analiz 4 + 5 = 9 değil 6 iş günü sürer. Analiz bitiminde bir toplantı vardır; 0 gün olduğu için çubuk değil nokta olarak görünür. Bu tür gözden geçirme toplantıları **kilometre taşı** (milestone) olarak adlandırılan durak noktalarıdır. Toplantının yapılması için analizin bitmesi gerekir (öncül 3).

Faaliyetlere kaynak olarak bir analist ya da iki analist atanabilir; atama %100, %80 ya da %10 eforla yapılabilir. Bu tamamen proje yönetim planına bağlıdır.

**Tasarım (7 gün).** Ön tasarım 1 Nisan'dan 5 Nisan'a 3 gün, ayrıntılı tasarım 6 Nisan'dan 9 Nisan'a 4 gün sürer. Ön tasarım Yazılımcı-1'e, ayrıntılı tasarım Yazılımcı-2'ye atanmıştır. Yazılımcı-2'nin başlayabilmesi için Yazılımcı-1'in işini bitirmesi gerekir; diyagramdaki ok bunu gösterir. Fareyle ayrıntılı tasarımı öne çekip proje süresini kısaltmak mümkün değildir, çünkü ön tasarım bitmeden ayrıntılı tasarıma geçilemez. 3 + 4 = 7 gün araç tarafından otomatik hesaplanır; tasarım sonunda yine bir toplantı vardır.

**Geliştirme ve test (14 gün).** Ön yüz (front-end) geliştirme 8 gün, arka plan (back-end) geliştirme 10 gündür. İkisinin de öncülü 8'dir, yani tasarım bitimi toplantısı. Bu toplantı bitmeden geliştirmeye başlanamaz, dolayısıyla bu işler öne çekilemez. Birinci yazılımcının işiyle test uzmanının işi arasında yalnız başlangıç ilişkisi vardır, bitişleri arasında ilişki tanımlanmamıştır. Bu yüzden yazılımcının bir gün geç başlayıp bir gün geç bitirmesi projeyi geciktirmeyebilir; bu esnekliğe ileride **bolluk** denecektir. Birim test, test uzmanı tarafından yazılım süresince 10 gün boyunca yapılır. Bitmesiyle sistem testi ve kullanıcı testleri başlar. 29 Nisan'da projenin teslim toplantısı (ya da devreye alma) bir kilometre taşı olarak tanımlanmıştır.

Sonuçta projede geçilmesi gereken adımlar, bitirilmesi gereken faaliyetler ve süreleri tanımlanmış; tarihler başlama-bitiş ilişkilerine ve sürelere göre otomatik yerleşmiştir.

## 4. WBS, tarihleme ve çalışma takvimi

Slayttaki açıklamalar (ekrandan, 00:30:00):

- WBS (work breakdown structure) ifadesi ile her bir faaliyet alt faaliyet kırılımlarına sahip olup numaralandırılır.
- Faaliyetler için başlangıç tarihi ve süresi belirtildiğinde otomatik olarak bitiş tarihi hesaplanır.
- Bir işin başlangıç zamanı başka bir işe bağlı olabilir (öncül tanımlama).

### 4.1 Work Breakdown Structure

WBS, yani iş kırılım yapısı, her faaliyet ve alt faaliyet için bir ağaç yapısı oluşturan numaralandırmadır: 0, 1, 1.1, 1.2 ... Kitaplardaki bölüm, kısım, alt kısım (chapter, section, subsection) ayrımı gibi hiyerarşik bir yapı kurar.

### 4.2 Göreli ve elle sabitlenmiş tarihler

**Task Mode** sütunu, faaliyetin başlangıç tarihi ve süresine göre otomatik mi yerleşeceğini, yoksa elle bir tarihe "çivi gibi çakılarak" mı sabitleneceğini belirler; yani göreli mi (relatif) mutlak mı bir tarihleme yapılacağını seçer. Örneğin sözleşme gereği kodlamanın kesin bir tarihte başlaması gerekiyorsa o faaliyet elle sabitlenir, geri kalanlar ona göre göreli dağılır.

Kesin bir son tarih (hard deadline) de olabilir: proje belli bir günde teslim edilmezse büyük bir ceza ödenecektir. Bu durumda teslim tarihi elle sabitlenir ve göreli faaliyetler geriye doğru planlanır. Örneğin teslim uzak bir tarihse ve elde bir buçuk yıllık bir iş varsa, geriye doğru plan oturtulduğunda projeye en geç ne zaman başlanması gerektiği görülür; daha geç başlanırsa teslim tarihi yetiştirilemez. Bu çıkarım da Gantt üzerinden yapılabilir.

### 4.3 Çalışma takvimi

Bitiş tarihi hesaplanırken araçlar çalışma takvimini kullanır. Örneğin pazartesiden cumaya sabah 8'den öğlen 12'ye ve 13'ten 17'ye, yani günde 8 saat çalışılır; cumartesi 4 ya da 5 saat çalışılabilir, pazar tatildir. Bayram, kar tatili, resmî izinler ya da şirketin iki hafta kapatıldığı zorunlu izin dönemleri de takvimde işaretlenir.

Bu yüzden iş günü ile takvim günü farklıdır. Perşembe başlayan 3 günlük bir iş, cuma tatil ve cumartesi yarım gün tanımlandıysa ancak sonraki haftanın pazartesi ya da salısında biter; gerçek takvimde 3 iş günü 7-8 takvim gününe karşılık gelebilir. Benzer tanımlar kişiler için de yapılır: bir yazılımcının yıllık izni ya da hastalık izni yüzünden iki haftalık kesinti takvimine girilebilir. Bu durumda işin süresi uzayabilir ya da başka bir kaynak atamak gerekebilir.

## 5. Faaliyetler arası ilişkiler

Bir işin başlaması başka bir işe bağlı olabilir; bu bağımlılıklar öncül sütunundan tanımlanır (**öncül tanımlama**, predecessor definition). Örneğin ayrıntılı tasarımın başlaması için ön tasarımın bitmesi, tasarım toplantısının yapılması için ayrıntılı tasarımın bitmesi gerekir. İki faaliyet arasında, her birinin başlangıcı ve bitişi olmak üzere iki değişken olduğu için dört ilişki kombinasyonu vardır:

- **Finish to Start (FS, bitiş-başlangıç):** Bir faaliyetin başlaması, bağlı olduğu faaliyetin tamamlanmasına bağlıdır; ilk faaliyet bitmeden ikinci başlayamaz. Örnek: analiz bitmeden tasarım, tasarım bitmeden kodlama başlamaz. En temiz ve en sık kullanılan ilişkidir; özellikle iş paketleri (özet faaliyetler) arasında genelde bu ilişki kullanılır. Yine de duruma göre paralel çalışılabilir.
- **Start to Start (SS, başlangıç-başlangıç):** Bir faaliyet başlıyorsa bağlı faaliyet de onunla birlikte başlar. Örnek: bir modülün analizi ile başka bir modülün ya da bir web servisinin tasarımı aynı anda başlayabilir. İnşaattan örnek: evin pencereleri takılırken aynı ustaya apartman ya da bahçe kapısı da taktırılabilir. Bu ilişki paralelleştirmeyi sağlar. Birim testlere başlamak için geliştirmenin başlamış olması beklenirse de SS tanımlanır.
- **Finish to Finish (FF, bitiş-bitiş):** Bir faaliyetin tamamlanması için bağlı faaliyetin de tamamlanmış olması gerekir. Örnek: birim testler kodu test ettiği için kodlama bitmeden birim testler bitemez.
- **Start to Finish (SF, başlangıç-bitiş):** Bir faaliyetin tamamlanması için başka bir faaliyetin başlamış olması gerekir; FS ilişkisinin ters yönden okunması gibi düşünülebilir.

Kitap satış örneğindeki Birim Test satırının öncülü `11FF;10SS`'dir: Ön Yüz Geliştirme (10) ile aynı anda başlar, Arka Plan Geliştirme (11) ile birlikte biter (ekrandan, 00:20:00).

## 6. Kritik yol

Çok sayıda faaliyet ve aralarında birçok başlangıç-bitiş ilişkisi tanımlandığında, projenin hangi tarihte başlarsa hangi tarihte biteceği görülür (örnekte 29 Nisan). Bazı faaliyetler öyledir ki gecikmeleri teslim tarihinin ötelenmesine yol açar. Bağlantılı işler bir faaliyet zinciri oluşturur. Slayttaki tanım (ekrandan, 00:35:00):

- Kritik yol, projenin belirlenen zamanda tamamlanması için bu yol üzerindeki tüm faaliyetlerin zamanında gerçekleşmesi gerektiğini ifade eder. Diğer bir deyişle kritik yol üzerindeki faaliyetlerden biri X gün ertelenirse, projenin bitiş tarihi de en az X gün ertelenmiş olur.
- Kritik yol üzerinde bulunan faaliyetler kritik faaliyetler olarak isimlendirilir. Gantt çizelgesinde kırmızı ile gösterilmektedirler.

Kritik yol analizi yapıldığında araç bu faaliyetleri kırmızıya boyar ("kızartır"); kızarmış faaliyet zinciri kritik yoldur. Örneğin ikinci analist hastalanıp bir hafta işe gelemezse ve işi yapacak başka kaynak yoksa, sonraki faaliyetler FS bağlantılarıyla zincirlendiği için projenin tamamı da bir hafta kayar. Bunu önlemek için o işe takviye bir analist atanabilir; kaynak tekil ve vazgeçilmezse gecikme kabul edilir.

Örnekte faaliyet sayısı az olduğu için neredeyse hepsi kritik yol üzerindedir. Kritik olmayan tek faaliyet **sistem testidir**: 2 gün sürer, paralelindeki kullanıcı testleri 4 gündür ve teslim toplantısı yalnız kullanıcı testlerine bağlıdır. Sistem testi biraz kaysa da kullanıcı testlerinden kısa olduğu için projeyi geciktirmez. Hoca ayrıca şunu belirtti: sistem testi teslime bağlanmadığı için, aşırı kayarsa proje teslim edildikten sonra yapılmış gibi bir durum bile oluşabilir. Bir faaliyeti sona bağlamamak ona esneklik kazandırır.

## 7. Kilometre taşları ve bolluk

### 7.1 Kilometre taşı (milestone)

Proje süresinde tanımlanan 0 günlük işlere **durak noktası**, **kilometre taşı** ya da asıl adıyla **milestone** denir. Kritik yol üzerinde olmaları gerekmez. Önemli tarihleri ya da olayları işaretlerler: analiz safhası bitip bir toplantı yapılması ya da projenin ekiple teslim edildiği toplantı birer kilometre taşıdır. Gantt diyagramında içi dolu eşkenar dörtgen (diamond) olarak, belli olsun diye düz noktadan farklı gösterilirler. Faaliyet tablosuna 0 gün olarak girilirler; süreleri olmadığı için projenin kaymasına yol açmazlar.

**Soru:** Toplantı 0 gün tanımlandı ama iki-üç saat sürmeyecek mi, efor almayacak mı? **Cevap (hocanın kendi sorusu):** Evet, sürecek. Gerekiyorsa izleme için oraya bir milestone konur, yanına da iki-üç saatlik bir toplantı faaliyeti eklenir.

### 7.2 Bolluk (slack)

Kritik yolda kızaran faaliyetlerin yanında mavi kalan faaliyetler de vardır: 3 ya da 5 gün kaysalar da teslim tarihini doğrudan etkilemezler. Hoca İngilizce terimi deliğinde sallanan bir vidaya benzetti; Türkçede bolluk denir ama "slack" olarak bilinmesi önerildi. Slayttaki tanım (ekrandan, 00:40:00):

- Bolluk (slack) kavramı kritik yol üzerinde bulunmayan esnek faaliyetlerin zamanlamasında yapılabilecek kayma miktarını ifade etmektedir.
- Kritik olmayan faaliyetler mavi renk ile gösterilir. Bu faaliyetlerde, proje süresini etkilemeden yapılacak öteleme miktarı olan bolluk, gri uzun çizgi ile ifade edilmektedir.

Slayttaki şekilde sistem testi "kritik olmayan iş" olarak, yanındaki gri çizgi de "bolluk miktarı" olarak işaretlenmiştir. Hocanın örneği: bir yazılımcının işi kritik yoldan çıkarılmışsa ve 6 günlük bolluğu varsa, 3 gün geç başlaması sorun olmaz; ama 7 gün geç başlarsa projeyi geciktirir. Kısaca bolluk, proje süresini etkilemeden yapılabilecek en büyük öteleme miktarıdır.

## 8. Kaynak atamaları

Slayttaki tanım (ekrandan, 00:45:00):

- Kaynak, proje faaliyetlerinin ilerleyebilmesi için ihtiyaç duyulan her şeydir. İnsan, ekipman, para gibi projenin tamamlanması için gerekli olan her şey kaynağı ifade etmektedir.
- Kaynakların doğru ve etkin bir biçimde kullanılması projenin başarılı bir şekilde yönetilmesi ile doğru orantılıdır. Özellikle sınırlı kaynakların projelerde öncelikli olarak doğru bir şekilde kullanılması önemlidir. Bunun için Gantt çizelgesi, kritik yol gibi analizler kaynak kullanımı konusunda önemli bilgiler vermektedir.

Kaynaklar faaliyetlerle ilişkilendirilmeli, yani faaliyetlere atanmalıdır. Atamanın izlenmesi verimlilik için önemlidir. Hocanın örneği: bir yazılımcıya bir hafta iş verilip sonraki üç hafta hiç iş verilmezse, maaşını aylık aldığı hâlde bir aylık sürede yalnız bir hafta etkin çalıştırılmış olur:

$$\text{kullanım oranı} = \frac{1 \text{ hafta}}{4 \text{ hafta}} = \%25$$

İş planları düzgün yapılırsa şirketteki herkesin toplam proje ve iş yükü izlenir, çalışanlar maaşlarının karşılığını verecek biçimde kullanılır. Hoca ayrıca, 5 günlük iş verilen birinin işi 3 günde bitirip kalan 2 günü boş geçirebildiğine dikkat çekti.

Sınırlı kaynaklarda darboğaz yaşanabilir. Örneğin tek bir sunucu hem bir simülasyonda hem de görüntü işlemedeki eğitim işlemlerinde kullanılacaksa ve ikisi aynı anda yapılamıyorsa bu iki iş paralelleştirilemez. Hangisinin önce yapılacağı ve bu işlerin başka hangi faaliyetlere bağlı olduğu düşünülerek sunucu daha etkin kullanılır. Gantt ve kritik yol analizleri hangi kaynağın az ya da çok kullanıldığını, kime çok yüklenildiğini, kimin boşta kaldığını görsel olarak ya da rapor biçiminde verir; bu yüzden proje yönetiminde vazgeçilmez bir yöntemdir.

### 8.1 Kaynak tablosu

MS Project'te faaliyetler gibi kaynaklar da bir tabloda tanımlanır. Kaynak adı (Analist-1, Yazılımcı-2, Test Uzmanı ...), türü (iş gücü, yani Labor; ya da barındırma hizmeti gibi bir malzeme / hizmet), kısa adı, malzemeyse ayrıntısı (sunucu, grafik tablet ...), grubu, en büyük kullanım yüzdesi ve ücreti girilir.

Örnekte herkes %100 tanımlanmıştı. Hocaya göre daha gerçekçi ve insancıl uygulamalarda insanları **%80'e kadar** tanımlamak daha doğrudur: telefon, e-posta, müşteri talepleri, bir arkadaşa yardım, çay ya da tuvalet molası gibi kesintiler yüzünden kimse %100 eforla çalışamaz; yapılan analizlerde verim yaklaşık %80 çıkar.

Ücret tarafında, örneğin bir analistin bir saatlik çalışması belli bir maliyet yaratır. Saatlik ücret, aylık maliyetin aylık çalışma saatine (örneğin 180 saat) bölünmesiyle bulunur. Danışman ya da dış kaynak saat başına fatura kesiyorsa o tutar doğrudan girilir; böylece o kaynağın ne kadar pahalı olduğu ve faaliyetin toplam bütçede ne kadar yer kapladığı analiz edilebilir. Sabit ücretli kaynaklar da tanımlanabilir. İş gücü, malzeme ve makine kaynakları limitleri ve ücretleriyle tanımlandıktan sonra faaliyetlere belli yüzdelerle atanır.

### 8.2 Daha büyük bir örnek

Hoca 2013-2014'ten kalma, 167 günlük eski bir projenin Gantt çizelgesini gösterdi (ekrandan, 00:50:00). Kısaltılmış yapısı:

```text
0  Proje (167 gün)
1    İş Paketi 1: Problem Analizi (26 gün)
2      Ürün isterleri analizi (10 gün)
3      Literatür taraması (10 gün)
4      Rakip çözümlerin ayrıntılı değerlendirilmesi, kıyaslama (5 gün, öncül 3)
5      Mevcut veri kaynaklarının ve formatının analizi (6 gün)
6      İş akışlarının belirlenmesi (10 gün)
7      Potansiyel müşterilerle görüşme ve istek alımı (15 gün)
8    İş Paketi 2: Kavramsal Tasarım (43 gün, öncül 1)
9      Modüler yapı tasarımı (6 gün)
10     Veri yapıları tasarımı (6 gün)
11     İlk rotalama algoritması tasarımı (16 gün)
12       Algoritma tasarımı (16 gün, öncül 10)
13       Deneysel kodlama (5 gün)
14     Dinamik rotalama algoritması tasarımı (16 gün)
15       Algoritma tasarımı (16 gün, öncül 12)
16       Deneysel kodlama (5 gün)
17     Arayüz-ekran tasarımları (5 gün)
18   İş Paketi 3: Kodlama ve Bütünleme (90 gün)
19     Modüllerin gerçeklenmesi (70 gün, öncül 16)
20       Veri giriş modüllerinin kodlanması (5 gün)
21       Sonuç-gösterim-raporlama modüllerinin kodlanması (5 gün, öncül 20)
```

Bu çizelgede örneğin potansiyel müşterilerle görüşme faaliyeti hiçbir işe bağlanmamıştır. İş paketi toplam 26 gün, bu faaliyet 15 gün olduğu için 11 günlük bir bolluğu vardır; paket içinde 11 gün "yüzebilir". İş paketlerinin içinde de iç içe özet işler tanımlanabilir. Bu projede hiç milestone tanımlanmamıştır; proje kapanışı bile bir günlük bir faaliyet olarak girilmiştir. Oysa milestone'ların eşkenar dörtgen olarak görünmesi gerekirdi.

## 9. MS Project uygulaması

Hoca slaytlardaki ekran görüntülerinin alındığı MS Project dosyasını açıp canlı olarak gösterdi (ekrandan, 00:55:00).

**Görev ekleme.** Ön tasarım ile ayrıntılı tasarım arasına "insert task" ile yeni bir görev eklendi. Araç WBS numarasını 2.2 olarak verdi ve görevin elle mi otomatik mi zamanlanacağını sordu; otomatik seçildi. Görevin adı "Arabirim Tasarımı", süresi 2 gün yapıldı. Görev bilgisi penceresinden tamamlanma yüzdesi, öncüller, atanan kaynaklar, kısıtlar ve proje yönetimi notları da girilebilir.

**Öncül.** Öncül verilmeden önce görev, hiçbir bağımlılığı olmadığı için projenin başlangıcına yerleşti. Elle kaydırılınca tatil gününe denk geldiği için araç uyarı verdi ve bir sonraki iş gününe aldı. Ardından öncül olarak 4 numaralı iş (Analiz Bitimi Toplantısı) verildi ve ok otomatik bağlandı.

**Kaynak ve aşırı yüklenme.** Göreve önce Yazılımcı-1 ve Yazılımcı-2 birlikte atandı. Resource sekmesindeki **Team Planner** görünümünde Yazılımcı-1 kırmızıya döndü, çünkü aynı tarihlerde Ön Tasarım'a %100 eforla atanmıştı. Çözüm için ya yüzdeler azaltılır (%50-%50), ya da iş üzerinde fazla yük olan kişiden alınıp başkasına verilir. Görev yalnız Yazılımcı-2'ye bırakıldı; Yazılımcı-2 o tarihlerde boşta olduğu için kızarma ortadan kalktı. Aynı kaynaklar ortak kaynak havuzundan (shared resource pool) başka projelerde de kullanılıyorsa araç diğer projelerdeki yükleri de hesaba katıp uyarır; böylece projeler bir arada yönetilebilir.

Team Planner'da test uzmanının da aynı anda sistem testine ve kullanıcı testlerine %100 eforla atandığı, yani aşırı yüklendiği görüldü. Ayrıca test uzmanının 12 Nisan'dan önce bu projede hiç işi yoktur; bu süre başka projelerde değerlendirilebilir ki uzman boşta kalmasın.

**Task Usage.** Task Usage görünümünde her işte toplam kaç saat çalışılacağı ve bu saatlerin günlere nasıl bölündüğü izlenir; aşırı çalışmalar burada da görülür (ekrandan, 01:00:00). Ekrandaki toplamlar:

| Özet faaliyet | Toplam iş | Ayrıntı |
|---|---|---|
| Analiz | 72 saat | Fizibilite 32 saat (Analist-1) + Gereksinimler 40 saat (Analist-2) |
| Tasarım | 72 saat | Ön Tasarım 24 + Arabirim Tasarımı 16 + Ayrıntılı Tasarım 32 saat |
| Geliştirme&Test | 272 saat | Ön Yüz 64 + Arka Plan 80 + Birim Test 80 + Sistem Testi 16 + Kullanıcı Testleri 32 saat |
| Proje | 416 saat | 72 + 72 + 272 |

Günde 8 saatle 4 günlük fizibilite $4 \times 8 = 32$ saat, 5 günlük gereksinim çalışması 40 saattir.

Hoca MS Project'in sürümünün önemli olmadığını, eski ve yeni sürümlerde menülerin yeri ve görünüşü dışında mantığın aynı olduğunu söyledi. Örnek (dummy) bir proje kurup işleri bağlamayı, kaynak atamayı, farklı ilişki türlerini denemeyi ve Gantt diyagramının nasıl değiştiğini kurcalayarak öğrenmeyi önerdi. Zoom out ile projenin baştan sona özet görünümü alınabilir; Gantt görünümündeki yeşil çizgi bugünü gösterir.

## 10. PERT

Gantt'ın alternatifi PERT'tir. Slayttaki tanım (ekrandan, 01:15:00):

- PERT (Program Evaluation and Review Techniques, Program Geliştirme ve Gözden Geçirme Tekniği), proje yönetimi ve analizi için kullanılan istatistiksel bir araçtır.
- Zaman, araç, maliyet, kontrol gereklerini cevaplar.
- Sistemin oluşmasını sağlayan pek çok faaliyet arasındaki ilişki ve tarih sayesinde ağ şeklinde düzene konulmasını sağlar.
- PERT diyagramı graf temelli bir yöntemdir. Projedeki faaliyetler düğümlerle (nodes) ve faaliyetler arasındaki bağlantılar kenarlarla (edges) gösterilir.
- Olayların mantıksal bir süre izleyeceği, bir olaya ancak önceki işlemler bitince ulaşacağı kabul edilir.
- Gantt çizelgesi faaliyetlerin paralelliğini göstermek için başarılıdır; ancak faaliyetler arasındaki etkileşimi (hangi faaliyetin hangi faaliyetlere dolaylı olarak bağlı olduğunu) göstermekte yetersizdir.

> **Ders sonrası not:** Kısaltmanın açılımı "Program Evaluation and Review Technique"tir; "evaluation" değerlendirme demektir. Bu yüzden Türkçesi büyük olasılıkla daha doğru biçimde "Program Değerlendirme ve Gözden Geçirme Tekniği" olur. Slayttaki ve hocanın söylediği çeviri "Program Geliştirme ve Gözden Geçirme Tekniği"dir.

PERT, faaliyetler arasındaki ilişkileri bir zaman akışı gibi, paralel ve seri düğümlerden oluşan bir ağ olarak gösterir. Gantt yaygın kullanılır, ama bir faaliyetin bağlı olduğu faaliyetin de başka faaliyetlere bağlı olduğu uzun zincirlerde takibi zorlaşır. Hoca bunu ön koşullu derslere benzetti: bitirme projesini almak için ara projeyi, onun için başka bir dersi, onun için de daha önceki dersleri almış olmak gerekir. Zincirin başındaki bir dersten kalmanın etkisi ileriye doğru yayılır. PERT bir ağ diyagramı olduğu için bu zincirler daha düzgün izlenir.

### 10.1 MS Project'te ağ diyagramı

MS Project aynı veriyi PERT olarak da çizebilir, ama buna PERT değil **Network Diagram** der. Ağ diyagramında da kritik görevler izlenir: paralel işler, iki işin birden bir işe bağlanması, kritik yol üzerinde olmadığı için mavi kalan ve bolluğu olan görevler görülür. Her düğümde faaliyetin adı, ID'si, başlangıç ve bitiş zamanı, süresi ve atanan kaynaklar yer alır. Özet işler (faz geçişleri) kenarları uzatılmış altıgen biçiminde gösterilir. View menüsünden takvim görünümü (proje ajandası), Gantt görünümü ve ağ diyagramı arasında geçilebilir.

Canlı gösterimde kritik yol şöyle izlendi: analiz bitimindeki toplantı, ön tasarım, ayrıntılı tasarım, tasarım bitimindeki toplantı; bu toplantıdan sonra ön yüz ve arka plan geliştirmeleri paralelleşiyor. Daha önce eklenen Arabirim Tasarımı hiçbir yere bağlanmadığı için ağda boşta kalmıştı. Gantt görünümüne dönülüp tasarım bitimi toplantısına (FS ile) bağlandı; böylece arabirim tasarımı ile ayrıntılı tasarım aynı anda bu toplantıya bağlı oldu (ekrandan, 01:20:00). Bu görevin bolluğu şöyle hesaplandı:

- Paralel kol: ön tasarım (3 gün) + ayrıntılı tasarım (4 gün) = 7 gün.
- Arabirim tasarımı: 2 gün.
- Bolluk: $7 - 2 = 5$ gün.

Yani arabirim tasarımı proje süresini etkilemeden 5 güne kadar kaydırılabilir.

Slaytta bir başka PERT diyagramı daha gösterildi: planlama, seçim, ister analizi, prototip adımlarından sonra mantıksal tasarım ile tasarımın aynı anda başladığı bir paralelleşme vardı. Hoca PERT'i, Gantt ile birebir aynı bilgileri düğümler ve düğümler arasındaki bağlantılarla ifade eden bir zaman fizibilitesi yöntemi olarak özetledi. <!-- BELİRSİZ: Bu son PERT diyagramının (yaklaşık 01:33:00) karesi yok; düğümlerin tam listesi altyazıdan çıkarılamadı. -->

## 11. Süre tahmini (effort estimation)

PERT ve Gantt'ta bir sıkıntı vardır: tasarımın 7, geliştirmenin 14, projenin 27 gün süreceği daha proje ortada yokken, yalnız bir ön inceleme ve niyet beyanı yapılmışken nasıl söylenebilir? Fizibilite projenin ilk adımıdır; bu safhada "bu iş 3 gün, şu iş 5 gün" demek zordur. Bu, yazılım mühendisliği disiplininde hâlâ üzerinde çalışılan bir alandır: **effort estimation**, yani efor kestirimi, iş gücü planlaması ya da iş gücü tahmini. Soru şudur: bu iş kaç kişiyle ne kadar sürede yapılır ve iş yapılmadan bu nasıl kestirilir? Literatürde zaman içinde pek çok yöntem önerilmiştir.

### 11.1 Yöntemler

- **Kafadan atmak:** "3 gün olsun, 5 gün olsun" demek. Bilimsel bir yöntem değildir.
- **Uzmana danışmak:** Bu işi ya da benzerini daha önce yapmış deneyimli bir ekip arkadaşına ya da proje yöneticisine sorulur; "3 gün, 5 gün sürer" diyebilir.
- **Delphi gibi yöntemler** ve **ortalama alma yöntemi** (aşağıda).
- **Katsayısal yöntemler:** İşin büyüklüğünü kod satırı sayısıyla ölçüp formüle eden COCOMO ve COCOMO II gibi modeller ("şu katsayı çarpı şu kadar kod satırı üzeri şu katsayı" biçiminde, ekip boyutunu da hesaba katarak bir işin kaç adam-gün süreceğini verir).
- **Function point türevi yöntemler:** İşin bileşenleri ağırlıklandırılıp toplanır; temel birim efor değerleri önceki projelerden çıkarılır.
- **Öğrenen modeller:** Önceki benzer projelerden öğrenilmiş bir model, yeni bir görev için ekran sayısı, veritabanı erişimi, form alanı, dış sistemlerle servis haberleşmesi gibi özellikler girilince "bu görev 3 adamla 5 günde, toplam 15 adam-günde yapılır" gibi tahminler yapar (yapay zekâ, makine öğrenmesi tabanlı yöntemler).

### 11.2 Ortalama alma (PERT süre tahmini)

Slayttaki tanım (ekrandan, 01:25:00):

- Süre tahminleri: $S_b = \dfrac{S_i + 4 \cdot S_e + S_k}{6}$
  - İyimser süre ($S_i$): İşlemlerde gecikme ve aksama olmadan tamamlanmayı sağlayan en kısa süre
  - Kötümser süre ($S_k$): Gecikme ve aksamaları dikkate alan en uzun süre
  - En yaklaşık süre ($S_e$): Normal gecikme ve aksamaları değerlendirir

Hocanın anlattığı uygulama şöyledir. Ekip olarak her faaliyet için üç tahmin yapılır:

1. **İyimser tahmin:** "Bu modülün analizini ya da kodlamasını hiçbir gecikme, aksama, sıkıntı olmadan, her şey yolundayken yapsam ne kadar sürer?" Beş kişilik ekipte herkes bir tahmin verir (1 gün, 2 gün, 3 gün gibi) ve ortalaması alınır.
2. **Kötümser tahmin:** Araya başka işlerin girmesi, kesintiler, bilgisayarın bozulması gibi aksamalar düşünülerek yapılır (1 gün diyen 3, 2 gün diyen 5 diyebilir). Bunun da ortalaması alınır.
3. **Ortalama (en yaklaşık) tahmin:** "Kabaca 2 ya da 3 günde yaparım" gibi; ortalaması örneğin 2,5 gün çıkabilir.

Ortalama değere 4, iyimser ve kötümser değerlere 1'er ağırlık verilir; toplam 6 değer toplanıp 6'ya bölünür. Bu ağırlıklı ortalama, o faaliyetin tahmini süresidir ve Gantt ya da PERT diyagramına faaliyet süresi olarak girilir.

> **Ders sonrası not:** Hoca bir yerde "iyimsere 4 ağırlık" dedi, hemen ardından "pardon, ortalamaya 4 ağırlık" diye düzeltti. Doğrusu slayttaki formüldür: 4 ağırlık en yaklaşık süreye verilir.

### 11.3 Kaynak eklemek süreyi her zaman kısaltmaz

Tahmin 5 adam-gün çıktıysa, "beş kişiyiz, beşimizi de atayalım, bir günde bitirelim" denebilir mi? Bazen evet, çoğu zaman hayır. Bir işçi bir duvarı 10 günde örüyorsa 10 işçi bir günde örebilir mi? Bazı durumlarda evet, çoğu durumda hayır. En çarpıcı örnek: bir anne bebeği 9 ayda doğurur; 9 anne ayarlayıp bir ayda doğurtmak mümkün değildir. Bazı işlerin mutlaka geçmesi gereken bir süreci vardır ve tek bir kaynakla yapılabilir. Bu yüzden "iki yazılımcı yazalım, süre yarıya insin" demek her zaman doğru değildir; karar işin doğasına göre verilmelidir.

> **Hocanın vurgusu:** Süre tahmini kolay bir konu değildir ve hâlâ aktif araştırma alanıdır. Plan, "bu projeyi bu ekiple ve bu kaynaklarla bu zaman planı içinde yapılabilir görüyoruz" diyen bir niyet beyanıdır. Proje ilerledikçe 3 gün denen iş 5 gün sürerse Gantt'ta güncellenmeli, etkileri izlenmeli; tamamlanma yüzdeleri girilerek proje takip edilmelidir. "Yaz oraya 3 gün" diye geçiştirilecek bir konu değildir.

> **Ek bilgi (derste anlatılmadı):** Hocanın önerdiği "The Mythical Man-Month" kitabı Fred Brooks'a aittir ve "geciken bir yazılım projesine insan eklemek onu daha da geciktirir" ilkesiyle (Brooks yasası) bilinir. Kitapta "dokuz kadın bir bebeği bir ayda doğuramaz" benzetmesi de geçer. Bunun nedeni, yeni katılanların işi öğrenme süresi ve kişi sayısı arttıkça iletişim yükünün hızla büyümesidir.

### 11.4 Zaman fizibilitesinin özeti

Hoca zaman fizibilitesinde şu anahtar kavramların üzerinden geçildiğini söyledi: iş-zaman planı, iş kırılım yapısı (WBS), kaynak ve kaynak ataması, faaliyet ve alt faaliyetlerin ilişkilendirilmesi, başlangıç ve bitişler arasındaki bağıntılar ve bunların neye yol açtığı, kritik yol, bolluk sahibi (kaydırılabilir) işler, kilometre taşı.

## 12. Çözüm önerilerinin değerlendirilmesi ve fizibilite matrisi

Altı fizibilite türünden işin doğasına göre üçü, beşi ya da altısı birden yapılmış olabilir. Bu çalışmalarda alternatifler de ortaya konmuştur: farklı donanımlar, farklı zaman planı ve kaynak dağılımları, farklı modeller. Her biri ayrı bir çözüm önerisidir. Hangisi ya da hangi kombinasyonun seçileceğine karar vermek için öneriler bir arada değerlendirilir; bunun en iyi yolu bir matris kurmaktır.

### 12.1 Aday sistemler matrisi

Slayt (ekrandan, 01:35:00): "Her çözüm için fizibilite çalışması gerçekleştirilir. Aday sistemler matrisi ile alternatifler karşılaştırılır." Slayttaki örnek matrisin satırları:

| Ölçüt | Önerilen Sistem 1 | Önerilen Sistem 2 | Önerilen Sistem 3 |
|---|---|---|---|
| Teknoloji: sistemin teknik alt yapısı | | | |
| Ara birim: sistemin kullanıcılarla ve diğer sistemlerle olan iletişimi | | | |
| Veri: sisteme hangi verilerin nasıl gireceği ve buna göre elde edilen çıktılar | | | |
| İşlemler: sistemdeki veriler üzerinde hangi işlemlerin gerçekleştirileceği | | | |
| Coğrafik yapı: işlemlerin ve verilerin sistem içinde nasıl dağıtıldığı | | | |

Hoca satırdaki başlıkların bire bir önemli olmadığını, bunların yerine yapılan fizibilite çalışmalarının (gerekirse alt kırılımlarıyla) yazılacağını, her sütunun da ayrı bir tasarım ya da çözüm önerisi olacağını söyledi.

### 12.2 Fizibilite matrisi

Slayt (ekrandan, 01:40:00): "Yapılan çalışmalar değerlendirilir. Yüzde ağırlıklarla puanlandırma yapılır."

| Fizibilite (ağırlık) | Önerilen Sistem 1 | Önerilen Sistem 2 | Önerilen Sistem 3 |
|---|---|---|---|
| Teknik Fizibilite %V | | | |
| Ekonomik Fizibilite %W | | | |
| Zaman Fizibilitesi %X | | | |
| Sosyal Fizibilite %Y | | | |
| Yönetim Fizibilitesi %Z | | | |
| Sıralama | | | |

Bu örnekte yasal fizibilite yapılmamıştır. Her fizibilite türüne, projedeki önemine göre bir yüzde ağırlık verilir:

- Sağlam bir altyapı kurmak her şeyden önemliyse teknik fizibiliteye (yazılım, donanım, ağ) %50-%60 verilebilir.
- En önemli şey çok az harcamayla bitirmekse ekonomik fizibilitenin ağırlığı yükseltilir.
- Müşteri "kaynak sorun değil, bütün ekipleri vereyim, yeter ki en kısa sürede bitsin" diyorsa zaman fizibilitesi önem kazanır.
- Son kullanıcıya yönelik bir mobil oyun yapılıyorsa kabul görmesi kritik olduğu için sosyal fizibilitenin ağırlığı yükseltilir.

Ağırlıklar duruma, probleme ve zamanın koşullarına göre değişir.

### 12.3 Puanlama

Her satırdaki 100 puan alternatiflere dağıtılır. Hocanın teknik fizibilite örneği: birinci öneri Linux tabanlı bir sunucu, ikinci öneri Windows tabanlı bir sunucu, üçüncü öneri Amazon Web Services üzerinde bulut, dördüncü öneri Microsoft Azure olsun (alternatif sayısı 3 olmak zorunda değildir). Diyelim ki yasal fizibilite (KVKK) yüzünden veri yurt dışındaki bir buluta çıkarılamıyor; bu durumda bulut çözümlerinin puanı çok düşük olur (3-5 puan), yerel çözümler yüksek puan alır. Güvenlik açıkları dikkate alınarak Windows tabanlı çözüme 50, Linux tabanlı çözüme 60-70 puan verilebilir.

Aynı şey diğer satırlarda da yapılır. Örneğin zaman fizibilitesinde, ekibin diğer projeleri düşünüldüğünde daha uygun olan iş planına 60, analist sıkıntısı yaratabilecek plana 30, mantıklı olmayan plana 10 puan verilebilir (ya da 50-50-0, 45-50-5 gibi). Sonra puanlar satır ağırlıklarıyla çarpılıp sütun sütun toplanır. Hoca bunu bir dersin not hesabındaki ağırlıklı ortalamaya benzetti: her sınavın notu kendi yüzdesiyle çarpılıp toplanır.

Her öneri için bir ağırlıklı toplam puan çıkar. Ardından bir sıralama (ranking) yapılır; en yüksek puanlı öneri seçilen çözüm olur. Proje o önerinin teknik seçenekleri, iş planı ve ekonomik fizibilitesiyle devam eder:

$$P_j = \sum_{t} w_t \cdot p_{t,j}, \qquad \text{seçilen öneri} = \arg\max_j P_j$$

Burada $w_t$ fizibilite türü $t$'nin ağırlığı, $p_{t,j}$ de $j$. önerinin o türdeki puanıdır.

### 12.4 Slayttaki örnek

Slaytta doldurulmuş bir örnek matris de gösterildi. Altyazıya göre bu örnekte teknik, zaman ve sosyal fizibilite eşit önemli sayılıp ağırlıklar %30-30-30 olarak verilmişti. Hoca, satır puanlarının toplamının 100 olacak biçimde dağıtılmasının daha doğru olacağını, örnekte puanların "bol keseden" verildiğini belirtti. Önerilerin ağırlıklı toplamları 60, 92 ve 83 çıkmıştı. İlk sıradaki ikinci öneri Visual Basic kullanan, 9-12 ay süren ve fizibiliteye göre kullanıcının bütün ihtiyaçlarını karşılayan sistemdi. Son sıradaki öneri C++ ile yapılacaktı: ekip bu dili bilmediği için eleman alınması ve eğitim gerekecekti, yatırımın geri dönüşü de diğerlerinin yaklaşık 3,3-3,5 yılına karşı 4,5 yıl gibi uzun bir süreydi. Çok kısa sürede yapılabilen ama bazı işlevleri eksik kalan ve kabul görmeyebilecek öneri ise 60 puanda kaldı. <!-- BELİRSİZ: Doldurulmuş matris slaytının karesi yok. Altyazıda ağırlıklar hem "%30-30-30" hem de "zaman fizibilitesi %10" olarak geçiyor; hangi satırın %10 olduğu ve hücre puanları doğrulanamadı. Önerilerin puanlarla eşleşmesi de altyazıdan tam çıkmıyor. -->

Seçilen öneriyle, onun zaman planı ve teknik ayrıntılarıyla yola devam edilir; projenin geri kalanı bu çerçevede işletilir.

## Örnek Sorular

**Soru 1** (ekrandan ve derste sözlü, 00:37:00) Kitap satış web sitesi örneğinde (bkz. bölüm 3) neden Sistem Testi kritik yol üzerinde değildir ve bolluğu ne kadardır?

> **Çözüm:** Sistem Testi (2 gün, 26.04 - 27.04) ve Kullanıcı Testleri (4 gün, 26.04 - 29.04) birim testin bitişine bağlıdır ve aynı gün başlar. Proje Teslim Toplantısı'nın öncülü yalnız Kullanıcı Testleri'dir (14). Sistem testi daha kısa olduğu ve teslime bağlanmadığı için gecikmesi projeyi uzatmaz. Bolluğu $4 - 2 = 2$ iş günüdür; slaytta mavi çubuk ve gri bolluk çizgisiyle gösterilmiştir.

**Soru 2** (ekrandan ve derste sözlü, 01:20:41) 2 gün süren Arabirim Tasarımı, Analiz Bitimi Toplantısı'ndan sonra başlıyor ve Tasarım Bitimi Toplantısı'na bağlanıyor. Paralelinde 3 günlük Ön Tasarım ve ondan sonra 4 günlük Ayrıntılı Tasarım var. Arabirim tasarımının bolluğu nedir?

> **Çözüm:** Paralel kolun süresi $3 + 4 = 7$ gün, arabirim tasarımının süresi 2 gündür. Bolluk $7 - 2 = 5$ gündür; görev proje süresini etkilemeden 5 güne kadar kaydırılabilir.

**Soru 3** (derste sözlü, 00:44:30) Bir yazılımcıya bir aylık sürede yalnız bir hafta iş atanmış, kalan üç hafta iş verilmemiştir. Bu kaynağın kullanım oranı nedir?

> **Çözüm:** $1/4 = \%25$. Kalan süre başka işlerle doldurulmazsa çalışanın maaşının dörtte üçü karşılıksız kalır.

**Soru 4** (derste sözlü, 01:30:53) Bir işçi bir duvarı 10 günde tamamlıyorsa, 10 işçi verip duvarın bir günde bitmesi beklenebilir mi?

> **Çözüm:** Bazı durumlarda evet, çoğu durumda hayır. İşin bölünebilirliği, kaynakların birbirini beklemesi ve koordinasyon gereği süreyi sınırlar. Hocanın örneğiyle: bir anne bebeği 9 ayda doğurur, 9 anne ile bir ayda doğmaz. Kaynak ekleme kararı işin doğasına göre verilmelidir.

**Soru 5** (ekrandan, 01:25:00) Slayttaki PERT ağında oklar üzerinde faaliyet süreleri verilmiştir: 1→2 ($S_a=5$), 2→5 ($S_b=4$), 5→7 ($S_c=6$), 7→8 ($S_d=4$), 1→4 ($S_e=3$), 3→4 ($S_f=1$), 4→6 ($S_g=4$), 6→7 ($S_h=4$). Kritik yol ve proje süresi nedir?

> **Çözüm (derste verilmedi):** 8 numaralı düğüme varan yollar: 1-2-5-7-8: $5+4+6+4 = 19$; 1-4-6-7-8: $3+4+4+4 = 15$; 3-4-6-7-8: $1+4+4+4 = 13$. En uzun yol 1-2-5-7-8'dir (19 birim); bu kritik yoldur ve proje süresi 19 birimdir. Üst kol (1-2-5) 7 numaralı düğüme 15. birimde ulaşır. Alt kolda 4 numaralı düğüme en erken 3. birimde varılır ($\max(3, 1)$), 7'ye ise $3+4+4 = 11$'de ulaşılır. Bu yüzden 1→4, 4→6 ve 6→7 faaliyetlerinin $15 - 11 = 4$ birim bolluğu vardır; 3→4 faaliyetinin bolluğu ise 2 birim daha fazladır ($4 + 2 = 6$).

> **Ders sonrası not:** Slayttaki bu PERT örneğinde faaliyetler oklar üzerinde gösterilmiştir (activity-on-arrow). Slayt metnindeki "faaliyetler düğümlerle gösterilir" tanımı ve MS Project'in ağ diyagramı ise faaliyetleri düğümlerde gösterir (activity-on-node). İki gösterim büyük olasılıkla aynı bilgiyi farklı biçimde verir.

## Dersin Toparlaması

Bu derste fizibilite çalışmasının son türü olan zaman fizibilitesi işlendi. Gantt çizelgesiyle faaliyetler, WBS numaralandırması, süreler, öncül ilişkileri (FS, SS, FF, SF), kritik yol, kilometre taşları, bolluk ve kaynak atamaları bir kitap satış web sitesi örneği üzerinden incelendi; aynı örnek MS Project'te canlı olarak değiştirilip aşırı yüklenen kaynaklar ve bolluk gösterildi. Ardından aynı bilgileri graf olarak gösteren PERT tanıtıldı ve faaliyet sürelerini kestirmek için iyimser, en yaklaşık ve kötümser tahminlerin ağırlıklı ortalaması $(S_i + 4S_e + S_k)/6$ verildi. Kaynak eklemenin süreyi her zaman kısaltmadığı vurgulandı. Son olarak farklı fizibilite çalışmalarından çıkan çözüm önerilerinin, yüzde ağırlıklı bir fizibilite matrisiyle puanlanıp sıralanarak nasıl seçileceği anlatıldı.

Fizibilitenin ardından gelecek konu gereksinim analizidir: iş analizi ve modelleme, kullanım senaryoları, müşteriden ya da iş biriminden bilgi sistemini geliştirmek için gereken bilgilerin nasıl toplanacağı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
