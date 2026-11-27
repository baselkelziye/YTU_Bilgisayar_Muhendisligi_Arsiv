# Ders 7 Genişletilmiş Notu: Problem Uzayının Modellenmesi ve Kavramsal Sınıf Diyagramı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Tekrar: gereksinim analizine iki yol
- 2. Problem uzayının modellenmesi
- 3. Kavramsal sınıf diyagramı
- 4. Analiz modelinden tasarıma: öğrenci ve ders örneği
- 5. Kavramsal sınıfların bulunması
- 6. Örnek: senaryoda isim işaretleme
- 7. Gereksiz sınıfların elenmesi
- 8. Betimleme (description, specification) sınıfı
- 9. UML'de sınıf gösterimi
- 10. Bağlantıların belirlenmesi
- 11. Gereksiz bağlantıların elenmesi ve örnek bağlantılar
- 12. Satış sisteminin kavramsal modeli
- 13. Özelliklerin belirlenmesi
- 14. Özellik ayrıntıları: görünürlük, türetilmiş nitelik, sabit, opsiyonel değer
- 15. Tamamlanmış model ve tek doğru olmaması
- 16. Use case modeli, alan modeli ve tasarım modeli
- Örnek Sorular

## 1. Tekrar: gereksinim analizine iki yol

Ders, şimdiye kadar işlenenlerin kısa bir tekrarıyla başladı. Önce bilgi sistemlerinin genel tanımları, sınıflandırması, tarafları ve rolleri; ardından bilgi sistemi geliştirme sürecinin genel adımları görülmüştü. Ön inceleme ve fizibilite çalışmasında neler yapıldığı, hangi fizibilitenin neden yapıldığı ve bunların nasıl karşılaştırıldığı işlenmişti. Sonra sistem analizi safhasına geçilmişti. Bu safha iki kısma ayrılmıştı: önce işin nasıl yapıldığının öğrenilmesi, verinin kaynağından toplanması ve bunun iş gereksinimleri belgesiyle (business requirements document) raporlanması; ardından yazılım dünyasındaki teknik kişilerin çözmeleri gereken problemi anlamalarını sağlayacak dönüşüm, yani gereksinim analizi.

Gereksinim analizinde ilk olarak **işlevsel çözümleme** (işlevsel modeller) işlenmişti. Gereksinim analizi modelinde süreçlerin, verinin ve kontrolün nasıl modelleneceğinden söz edilmiş, ağırlık süreç modellemesine, yani veri akış diyagramlarına verilmişti. Veri (nesne) modelini oluşturacak varlık ilişki modeli tasarımla birlikte işlenecek, kontrol spesifikasyonunun ayrıntısına ise bu derste girilmeyecektir. Veri akış diyagramlarının ardından süreç formları ve bunların içindeki yapısal dil (pseudocode), karar ağacı ve karar tablosu gibi yapılarla işin teknik bir tanımının nasıl yapılacağı öğrenilmişti.

Bu bir yoldu. İkinci yol, işlevsel çözümleme yerine **nesneye yönelik çözümleme** (nesneye yönelik modelleme) yapmaktır. Hoca gereksinim analizini, işin anlaşılmasını ve tercüme edilmesini "problemin modellenmesi" ya da "problem uzayının modellenmesi" diye adlandırdığını söyledi. "Problem uzayı" dediğinde nesneye yönelik, "işlevsel" dediğinde veri akış diyagramları üzerinden yapılan çözümlemeden söz ettiği anlaşılmalıdır.

## 2. Problem uzayının modellenmesi

Veri akış diyagramlarında sistem işlevsel parçalara (kabaca modüllere) bölünüyordu: kayıt işlemleri, hesaplama işlemleri, fatura oluşturma işlemleri, hastane bilgi sisteminde tahlil ya da muayene işlemleri gibi. Nesneye yönelik çözümlemede ise problem farklı bir mantıkla çözülür. Slayttaki maddeler şunlardır (ekrandan, 00:10:00):

- Amaç gerçek dünyanın (problemin) doğru, anlaşılır, sınanabilir modelini oluşturmak
- Problemin anlaşılması aşamasıdır
- Teknik yorumdan çok müşteri isterleri ön plandadır
- İsteklerin modellenmesi nesneye dayalı değildi, burası ise nesneye dayalı
- Gerçek dünyadaki kavramsal sınıflar ve nesneler yer alır (nesneler, o anda görülen özellikleri, aralarındaki ilişkiler (bağlantılar)). Yazılım nesneleri henüz düşünülmez
- UML ile görselleştirilir
- Oluşacak sistem anlaşılır
- Tasarıma girdi sağlar (sorumlulukları atamak üzere)

Temel fikir, yazılımdaki nesneleri gerçek hayattan bulup çıkarmak, gerçek hayat nesnelerini yazılımın içine koymak ve onları gerçek hayatta çalıştıkları hâlleriyle kullanmaya çalışmaktır. Yani çözümleme işlev bazlı değil, gerçek dünya nesneleri bazında yapılır. Analiz aşamasında yalnız problem anlaşılır ve tanımlanır; müşteri ve müşteri istekleri ön plandadır. Daha önce işlenen use case'ler isteklerin modellenmesi için iyi bir yöntemdi ama nesneye dayalı değildi; bu derste o senaryolardan yola çıkarak nesneye dayalı bir çözümlemenin nasıl yapılacağı öğrenilecektir.

Gerçek dünyadaki kavramlar **kavramsal sınıflar** olarak modellenir; bu sınıflardan türetilen nesneler de yazılımda yaşatılmaya çalışılır. Nesne, bir sınıf şablonundan türetilen, görünen özellikleri ve aralarında ilişkileri olan yapısal birimlerdir. Bu aşamada yazılım nesneleri düşünülmez, kavramsal nesnelere bakılır. Bir iş analizi yapılmış, use case'ler bulunmuş, kullanım senaryosu belgeleri oluşturulmuştur; bu belgelerin üzerinden geçilerek gerçekten işleyen parçalar, yani gerçek nesneler bulunur. Bunu görselleştirmek için kullanılacak modelleme dili UML'dir (Unified Modeling Language).

Bu aşamada sorulan sorular şunlardır: problem sonucunda nasıl bir sistem üretilmeli, bu sistemde ne gibi kavramlar olmalı, bu kavramların aralarındaki ilişkiler ve özellikleri neler olmalı? Özetle analizde **"ne?"** sorusunun cevabı aranır: ne var, ne oluyor, ne kavramlar var? Tasarım aşamasında ise bu "ne"lerin **"nasıl"**ları çözülür: nasıl çalışır, nasıl hizmet sunar, problemi nasıl çözer? Bu, sorumlulukların nesnelere atanması diye de adlandırılabilir.

## 3. Kavramsal sınıf diyagramı

Hoca bir örnek slayt gösterdi (ekrandan, 00:15:00). Bu bir **sınıf diyagramıdır**, çünkü nesneye yönelik modelleme yapılıyorsa sonunda yazılım sınıflarına ulaşılmak istenir; sınıfları ve aralarındaki ilişkileri göstermek için UML'de sınıf diyagramı kullanılır. Sıfatı "kavramsal"dır: sınıf diyagramının analiz modelini gösteren özel bir hâlidir.

Slayttaki diyagram bir market satış sistemidir. Diyagramdaki öğeler notlarla işaretlenmiştir: kavramsal sınıf (Concept or Domain object), bağlantı (Association), çoğullama (Multiplicity), nitelikler (Attributes).

| Sınıf | Nitelikler |
|---|---|
| SalesLineItem | quantity |
| Item | (yok) |
| Sale | date, time |
| Store | address, name |
| Payment | amount |
| Register | (yok) |

| Bağlantı | Bir uç | Diğer uç |
|---|---|---|
| Records-sale-of | SalesLineItem 0..1 | Item 1 |
| Contained-in | SalesLineItem 1..* | Sale 1 |
| Stocked-in | Item * | Store 1 |
| Houses | Store 1 | Register 1..* |
| Captured-on | Sale 0..1 | Register 1 |
| Paid-by | Sale 1 | Payment 1 |

Hoca bu modelin nasıl kurulduğunu bir market gözlemiyle anlattı. Markete gidilir, çalışma şekli incelenir ve bir satış senaryosu gözlenerek yazılır. Bir dükkân vardır, kasa vardır ve kasa satış senaryosunda önemli bir rol oynar. Ürünler vardır. Satışın kendine has özellikleri olduğu için ayrı bir kavram olarak modellenir. Ödeme de bir kavramdır, çünkü en azından bir tutarı vardır.

Müşteri de bu diyagrama konabilirdi, ama aktör olduğu için dışarıda tutuldu. Senaryolardaki aktörler (birincil aktörler gibi) yazılımda genellikle sınıf olarak modellenir; bu yüzden yazılımda büyük olasılıkla bir müşteri sınıfı da olacaktır. Ancak senaryodaki kavramların anlaşılır kalması için **kavramsal sınıf diyagramında aktörler genellikle konmaz**. Gözleme sepet kavramı da eklenebilirdi: müşteri, sepet ve "ürünler sepetin içindedir" gibi bir ilişki.

Gözlenen senaryo şöyledir: kasiyer kasada oturur, ürünü barkod okuyucudan okutur, gerekirse klavyeden "3 x" gibi bir miktar girer. Ekranda ve sonunda fişte her ürün satır satır görünür (örneğin 3 adet bir çikolatalı bisküvi, 5 adet başka bir bisküvi, ekmek). Her satırın kendine has özellikleri vardır ve vergi (KDV) hesabı için bunların tutulması gerekir. Kasiyer genel toplam ya da kapat tuşuna basar, ödeme alınır, müşteri ürünleri torbaya koyup gider. Bu gözlemde bulunanlar ve aralarındaki ilişkiler basit bir sınıf diyagramıyla gösterilir. Bunlara **kavramsal sınıf**, conceptual class, domain object ya da domain class denir.

Kavramsal sınıflar adaydır; yazılım bunların üzerine kurulmaya başlanır. Değişebilirler, burada olmayanlar eklenebilir. Yazılım sınıflarında çok daha fazlası gelir: başka hiçbir şey olmasa arayüzler, veri tabanı haberleşmesi için başka nesneler gerekir. Ama bunlar problem uzayında değil, yazılım uzayındadır; bu aşamada onlara girilmez.

Bağlantılardaki sayılara **çoğullama** denir. Satış ile ödeme arasında 1-1 bir ilişki vardır: bir satışta bir ödeme vardır, bir satış iki farklı ödemeyle alınamaz.

**Soru:** Bir kısmı nakit, bir kısmı kredi kartıyla ödeme yapılamaz mı? **Cevap:** Yapılabilir, ama o ayrı bir senaryodur. Gözlenen yer yalnız nakit ödeme alan basit bir bakkaldır; bu yüzden her satış bir ödemeyle alınır.

Bir satışın içinde bir ya da daha fazla **satış satırı** (satış kalemi) oluşur: faturada en az bir kalem olmalıdır, ama n tane de olabilir. Görülebildiği kadarıyla özellikler de eklenir: satış satırında miktar vardır (3 adet bisküvi örneğindeki 3 gibi, hakkında veri tutulması gerekir); satışın tarihi ve zamanı vardır (faturada yazar). Bu, senaryonun son hâli değildir; ilerleyen slaytlarda model olgunlaştırılacaktır. Analist bunları tasarıma ve yazılım gerçekleştirmeye temel oluşturmak için, yazılım dünyasına bir çıktı üretmek için yapar.

## 4. Analiz modelinden tasarıma: öğrenci ve ders örneği

Hoca, analiz modelinin ileride neye dönüşeceğini bir öğrenci bilgi sistemi örneğiyle anlattı. Analizde "öğrenci" ve "ders" diye iki kavram bulunmuş olsun. Bir öğrencinin n tane ders aldığı bilinsin. Dersin bir kodu (course number), öğrencinin bir adı olsun (basit tutmak için öğrenci numarası gibi diğer özellikler yazılmadı).

Tasarım aşamasında büyük olasılıkla bundan `Student` adlı gerçek bir yazılım sınıfı üretilir. `name` özelliği `String` ve private olur. Sınıfın artık davranışları da olur: örneğin öğrenci ortalamasını kendisi hesaplayabilir (`getAverage()`). Problem uzayında tek bir çizgiyle gösterilen "öğrenciler dersleri alır" ilişkisi, tasarımda bir bağlantıya dönüşür. `getAverage()` davranışının çalışması için başka bir sınıftan türeyen nesnelerle ilgili bilgi toplamak gerekir: öğrencinin bir ders listesi (my courses) olur, listedeki her ders için `getGrade()` çağrılır, notlar toplanıp listenin boyuna bölünür. Bunlar davranışlardır ve analiz aşamasında henüz görülmez.

Tasarımda bir de `Course` sınıfı olur ve `courseNumber` büyük olasılıkla `String` olur, çünkü ders kodu (BLM2042 gibi) yalnız sayılardan oluşmaz. Dersin bir notu da olmalıdır: private bir `grade` özelliği ve bunu dış dünyaya hizmet olarak sunan `getGrade()`. Not içeride 100 üzerinden tutulabilir; `getGrade()` çağrılma şekline göre harf karşılığı (eski AA, BA, BB ... sistemi gibi), 10'luk ya da 4'lük karşılık döndürebilir. Veri gizli ve özeldir, ama dış dünyaya verilen hizmetler farklılaşabilir. Bu ayrıntılar tasarım aşamasında işlenecektir. Analiz modeli, tasarımda ve gerçekleştirmede kullanılacak gerçek dünya nesnelerini ve sınıf şablonlarını şimdiden bulup yol gösterir.

## 5. Kavramsal sınıfların bulunması

Slayttaki yaklaşımlar şunlardır (ekrandan, 00:25:00):

- Gerçek dünyadaki somut/soyut varlıklar
- **Kategori listesi:** Deneyim sonucu sık karşılaşılan kategoriler. Zaten görülen sınıfları bulur. Gözden kaçırma olasılığı yüksek.
- **Senaryolardaki isimler (isim tamlamaları):** Senaryolardaki tüm isim ve tamlamalar aday sınıf olarak alınır. Çoğunlukla fazla sınıf çıkar, elenir.
- **Varolan model güncellemesi:** Yayımlanmış modellerin uyarlaması yapılır.

Her şey somut olmak zorunda değildir; soyut varlıklar da kavramsal sınıf olabilir. Üniversite ya da hastane bilgi sistemlerinde sık karşılaşılan kategoriler (ders, öğrenci, not, sınıf) zaten görünen sınıfları bulur. Ama uygulama uzayına özel sınıfları gözden kaçırma olasılığı yüksektir. Örneğin market modelindeki satış satırı (satış kalemi) standart bir kavram değildir; hazır listeyle dükkân, ürün, kasa, ödeme bulunabilir ama böyle alana özgü (domain specific) kavramlar bulunamaz.

Bu yüzden elde olan senaryolar kullanılır. İş analizi yapılmış, raporlanmış ve müşteriyle uzlaşılmıştır; müşteri "gerçekten işleri böyle yapıyoruz" demiş ya da süreçleri güncelletmiştir. Bu senaryolar işlenir ve ortaokuldaki dil bilgisi derslerine dönülerek senaryolardaki **isimler ve isim tamlamaları** işaretlenir. Bunların hepsi problem uzayındaki aday sınıflardır. Hepsi sınıf olabilir ama genellikle olmaz; çok fazla sınıf çıkar ve elemek gerekir, çünkü senaryolar her şeyi tam ve net yazmayabilir. Örneğin bir yerde "kişi kasaya gelir", başka yerde "müşteri ödemeyi yapar" yazılmış olabilir; inceleyince ikisinin aynı kavram olduğu görülür ve daha özel tanımlayan "müşteri" seçilir, senaryolar da buna göre güncellenir. "Kasa ödemenin tutarını gösterir" cümlesindeki "tutar" da hemen bir sınıf yapılmamalıdır; birkaç iterasyon sonra büyük olasılıkla ödeme nesnesinin bir özelliği olur. Her isim kavramsal sınıf olmak zorunda değildir. Yine de bu iyi bir yöntemdir ve probleme özgü kavramların da yakalanmasını sağlar.

Var olan model güncellemesinde daha önce yapılmış işler ya da yayımlanmış kavramsal modeller uyarlanır ("iki sene önce şu firmaya benzer bir çözüm geliştirmemiş miydik? Şunu değiştir, şunu çıkar, şunu ekle"). Ama bu da emek ister ve işi her zaman kolaylaştırmaz. İlk kez görülen, tanınmayan bir iş uzayında en doğru yol kavramsal sınıfları senaryolardan başlayarak bulmaktır.

## 6. Örnek: senaryoda isim işaretleme

Hoca, kitaptan alınmış İngilizce bir senaryoda isimleri işaretledi (ekrandan, 00:30:00). Senaryonun metni şudur:

```text
Main Success Scenario (or Basic Flow):
1. Customer arrives at a POS checkout with goods and/or services to purchase.
2. Cashier starts a new sale.
3. Cashier enters item identifier.
4. System records sale line item and presents item description, price,
   and running total. Price calculated from a set of price rules.
Cashier repeats steps 3-4 until indicates done.
5. System presents total with taxes calculated.
6. Cashier tells Customer the total, and asks for payment.
7. Customer pays and System handles payment.
8. System logs completed sale and sends sale and payment information to the
   external Accounting system (for accounting and commissions) and Inventory
   system (to update inventory).
9. System presents receipt.
10. Customer leaves with receipt and goods (if any).
Extensions:
7a. Paying by cash:
1. Cashier enters the cash amount tendered.
2. System presents the balance due.
```

Slaytta kalın yazılan isimler aday sınıflardır: Customer, POS checkout, goods, services, Cashier, sale, item identifier, sale line item, item description, price, total, taxes, payment, Accounting, commissions, Inventory, receipt, amount tendered, balance due. Hoca işaretlerken şu noktalara dikkat çekti:

- "purchase", "starts" gibi kelimeler eylemdir, işaretlenmez.
- "new sale" ifadesinde "new" sıfattır; yalnız "sale" işaretlenir. Bir kez işaretlenen isim (cashier, customer, goods) yeniden işaretlenmez.
- "item identifier" barkod numarasıdır. İncelenen sistem çok basittir: okuyucu yoktur, kasiyer barkodu sayısal klavyeden elle girip Enter'a basar.
- "System" de bir isimdir, ama çözülmeye çalışılan problemin kendisi olduğu için işaretlenmesine gerek yoktur. Hoca bunun ileride büyük olasılıkla statik `main` metodunun duracağı yer olacağını söyledi.
- "sale line item" için "sale" ile "line item" ayrı ayrı da çizilebilir; ilk seferde her şeyin doğru bulunması beklenmez. "running total" birlikte ya da "total" ayrı işaretlenebilir. "price rules" da işaretlenebilir.
- 8\. adımda satış ve ödeme bilgisi dış muhasebe sistemine (muhasebe ve komisyonlar için) ve envanter (stok) sistemine gönderilir. Hoca bunu, formların bir tüpe konup borularla gönderildiği sistemlere benzetti.
- Nakit ödeme uzantısında (7a) "cash", "amount tendered" (verilen miktar) ve "balance due" (kalan tutar) işaretlenebilir.

Bütün senaryoların üzerinden geçilip isimler işaretlendiğinde birçok gereksiz aday sınıf bulunur: bazıları özellik olur, bazıları ilgilendirmez, bazıları aynı kavramı tanımlar.

## 7. Gereksiz sınıfların elenmesi

Slayttaki eleme ölçütleri şunlardır (ekrandan, 00:35:00):

- **Fazlalık sınıflar:** aynı unsuru ifade edenlerden, daha tanımlayıcı olan. Kişi-müşteri: Müşteri
- **İlgisiz sınıflar:** çözümle ilgisi olmayan ya da o aşamada ilgilenmeyeceğimiz sınıflar: Kredi Kartı
- **Belirsiz sınıflar:** sınırları iyi çizilmemiş, kaba-geniş tanımlı sınıflar. Genellikle birden fazla sınıftan oluşmuşlardır ya da başka sınıfın parçasıdır: Muhasebe Sistemi
- **Nitelikler:** kendi başına varlığı anlamlı olmayanlar, sınıfların özellikleridir: Miktar
- **İşlemler:** Sadece nesnelere uygulanan işlemler sınıf olmaz. Kendi nitelikleri olmalı ve hizmet alışverişi yapmalıdır: Ödeme(miktar, para birimi, tarih, ...)
- **Roller:** Sınıflar arası ilişki olan roller sınıf olamaz.
- **Gerçekleme Elemanları:** Yazılım sınıfları bu uzayda yer almaz.

Hocanın açıklamaları şöyledir. **Fazlalık sınıflarda** bir yerde müşteri, bir yerde kişi, bir yerde ziyaretçi denmiş olabilir; daha tanımlayıcı olan "müşteri" kullanılır ve mümkünse senaryolar da geri dönülüp güncellenir. **İlgisiz sınıflar** senaryonun sınırları dışında kalanlardır: yalnız nakit ödeme senaryosu çözülürken kredi kartıyla ilgili işaretlenenler silinebilir. Bunlar başka bir senaryo için ilgili olabilir, ama o anda çalışılan senaryo için ilgisizdir. **Belirsiz sınıflar** genellikle kompozit yapılardır: muhasebe sistemi koskoca bir sistemdir ve içinde pek çok parça vardır; belki onun genelinden değil yalnız bir arayüzünden söz ediliyordur, bunun daha iyi belirlenmesi gerekir. **Nitelikler** kendi başına anlamlı değildir: "amount tendered" (miktar) için "kendi başına bir anlam ifade ediyor mu, hakkında veri tutmam gerekiyor mu, ondan birden fazla nesne üretebilir miyim?" diye sorulur; bu bir ödemenin özelliğidir. **İşlemler** sınıf olmamalıdır, çünkü tasarımda davranış (metot) hâline gelecektir. **Roller**, yani sınıflar arasındaki ilişkiler sınıf yapılmamalıdır (çok nadiren, örneğin bazı ilişkileri çözmek için yapılabilir). **Gerçekleme elemanları** da bu uzayda yer almaz: arayüzdeki bir düğme burada bulunmamalıdır; yalnız iş ve kavramlar modellenir.

Slayttaki sınıf testi soruları şunlardır:

- Kavramla ilgili veri saklanması gerekiyor mu?
- Değişik değerler alabilecek farklı özellikleri var mı?
- Kavramdan birçok nesne türeyebilir mi?
- Uygulamanın kapsama alanı içinde mi?
- Sınırları iyi çizilmiş mi, tanımı yapılabiliyor mu?

Bir kavramın kendine has birden çok özelliği yoksa o tekil bir niteliktir. Birden fazla müşteri ya da farklı ürün nesnesiyle muhatap olunabilir, bu yüzden bunlar sınıftır. **Toplam tutar** ise o anda oluşan ve hangi üründen kaç tane alındığına göre değişen bir miktardır; ondan birçok nesne türemez, bu yüzden ayrı bir sınıf olarak modellenmez. Muhasebe ve envanter ayrıntıları da o anki odak (satış senaryosu) dışındadır; modelde "inventory item" gibi bir şey görülmemelidir. Belki bütün senaryolar bir araya geldiğinde gerekir, ama şimdilik gerekmez. Tanımı düzgün yapılamayan, muğlak kavramlar da gereksiz ve belirsiz sınıftır. Böylece senaryolardaki isimlerin üzerinden geçilip gereksizler silinir ve daha temiz bir kavram uzayı elde edilir.

## 8. Betimleme (description, specification) sınıfı

Bazen gerçek dünyada olmayan, hayali kavramlar yaratmak gerekir. Bunlara **betimleme** ya da **tanımlama sınıfı** (description ya da specification class) denir. Slaytın metni şudur (ekrandan, 00:40:00):

- Satış yaparken nesneler ürünleri tutsun.
- Bir cinsten tüm malzeme satılırsa, nesne kalmaz. Bilgi kaybı olur.
- Bu yüzden özellikleri ayrı bir sınıf olarak tutmak gerekebilir.

Senaryoda işaretlenen "item" (ürün) gerçekten bir nesnedir: bisküvi, makarna, süt, sabun, bulaşık deterjanı, her birinden bir nesne üretilebilir. Her birinin ağırlığı, boyutu, tutarı, KDV oranı gibi özellikleri vardır, bu yüzden ürün bir kavramsal sınıftır. Ancak hoca şu durumu düşündürdü: dükkândaki her ekmek için bir nesne yaratılmış olsun, dolapta 50 ekmek olsun ve her biri benzersiz bir nesne olsun. Satış yapıldıkça bunlar envanterden düşülür. 50 ekmeğin hepsi satıldığında elde hiç ekmek nesnesi kalmaz; ekmeği tanımlayan hiçbir veri kalmamıştır, veri yok edilmiştir. Bilgi kaybı olacak böyle durumlarda bir şablon sınıfı, yani **ürün tanımı** sınıfı yaratılır. Gerçek dünyada "ürün tanımı" diye bir kavram yoktur, ama burada kullanmak gerekir.

İlk model ile düzeltilmiş model şöyledir (ekrandan, 00:40:00):

```text
İlk model:
  Item [description, price, serial number, itemID]

Düzeltilmiş model:
  ProductSpecification [description, price, itemID]  1 --Describes-- *  Item [serial number]
```

Üründe yalnız seri numarası tutulur; kaybolursa veri kaybına yol açacak bütün özellikler (ürünün tanımı, fiyatı, kodu, stok kodu) ürün tanımına taşınır. Ürün satıldığında seri numarasıyla bir işi kalmaz. Bir tanım, raftaki n tane aynı ürünü tanımlar; aralarındaki fark seri numaralarıdır.

Bu her satış sisteminde %100 böyle olmak zorunda değildir. Örneğin bilgisayar ya da elektronik eşya satan bir yer, ürünleri garanti için üç yıl boyunca seri numaralarıyla izlemek zorunda olabilir; o zaman "servis takibi" gibi başka bir kavram yaratılıp seri numarası orada da tutulabilir. Kavramlar, çözülen işe ve senaryolara göre farklı bulunur; amaç gerçek dünyaya yakın kalmak ve gerçek kavramları yazılımda sürdürmektir.

## 9. UML'de sınıf gösterimi

Hoca tahtada sınıf kutusunu çizdi (ekrandan, 00:45:00). Sınıf diyagramlarındaki sınıflar genellikle **üç bölmeli** çizilir: en üstte sınıfın adı, ortada özellikler, altta metotlar. Kavramsal sınıflarda ise yalnız iki bölme kullanılır (ad ve öz nitelikler), çünkü davranışlar, yani üçüncü bölme henüz eklenmez.

Ek bilgi olarak hoca, sınıf diyagramlarının üç bölmeli olmak zorunda olmadığını söyledi. Beş bölmeli de yapılabilir: öz nitelikler, metotlar, istisnalar (exception) ve tetiklenmesi gereken başka şeyler ayrı bölmelerde verilebilir. UML esnek bir dildir; şablonu kullanıcı belirleyebilir, şemasına eklenti yapılabilir. Herkesin standart olarak kullandığı üç bölmeli yapı yerine dört ya da beş bölmeli bir sınıf görülürse yanlış sanılmamalıdır.

## 10. Bağlantıların belirlenmesi

Bağlantılar kavramsal sınıflar arasındaki ilişkilerdir. Slaytın metni şudur (ekrandan, 00:45:00):

- Bir nesnenin kaç tane nesneyle ilişki içinde olacağı çoğullama ile gösterilir.
- Bağlantılara doğru isimler verilmelidir. Tip-fiil-tip
- Bazı bağlantıların unutulması tasarımı çok etkilemez.
- Kavramsal sınıfların doğru bulunması daha önemlidir.
- Fazla bağlantı anlaşılırlığı azaltır.
- Yaygın bağlantılar listesinden yararlanılabilir:
  - Fiziksel barındırma, mantıksal barındırma, kayıt ilişkisi, kullanım ilişkisi, tanım, sahiplik, ...
  - Kullanım senaryolarındaki fiillerden yararlanılabilir.

Bağlantıları bulmak için senaryoya dönülür ve bu kez **fiiller** başka renkte (örneğin koyu yeşil) bir kalemle işaretlenir. "Customer arrives at a POS checkout" cümlesinden müşteri ile kasa arasında bir ilişki, "Cashier starts a new sale" cümlesinden kasiyer ile satış arasında bir bağlantı çıkar. Kasiyer ile müşteri arasında anlatma (tells) ve ödeme isteme (asks for payment) ilişkileri vardır. Bağlantılar genellikle **tip-fiil-tip** biçiminde adlandırılır: "Öğrenci alır Ders".

Bağlantıların hepsi bulunamayabilir; bu olabilir. Fazla ve gereksiz bağlantılar da çizilebilir, ama ne kadar çok bağlantı çizilirse modelin anlaşılırlığı o kadar azalır. Bağlantılardan çok kavramları doğru bulmaya özen göstermek daha iyidir. Unutulan bağlantılar tasarımı büyük ölçüde etkilemez ve ileride güncellenebilir. Yaygın bağlantı listesi kullanılabilir, ama daha doğru yol probleme özgü senaryolardaki fiilleri işaretlemektir.

## 11. Gereksiz bağlantıların elenmesi ve örnek bağlantılar

Slayttaki ölçütler şunlardır (ekrandan, 00:50:00):

- Elenen sınıflar arası bağlantılar gereksizdir
- Sistemin amacı dışındaki bağlantılar gereksizdir
- Gerçeklemeyi ilgilendiren bağlantılar gereksizdir
- Faaliyetler bağlantı değil, etkileşimdir. (ATM kredi kartı kabul eder)
- Üçlü bağlantılar ikili hale çevrilmelidir. Memur hesapla ilgili işlemleri girer → memur işlemleri girer. İşlemler hesapla ilgilidir.

Elenen sınıflar arasındaki bağlantılar da elenir. Amaç dışındaki bağlantılar gerekmez: müşteri ile kasiyer konuştu diye ikisini ilişkili göstermek gerekmez. Çok bağlantı yüksek bağımlılık demektir; oysa az bağımlılık tercih edilir. Bir işi yapmak için mümkün olduğunca az haberleşmek ve alakasız işler yapmamak için bağlantılar sınırlı tutulur; bunlar tasarım ilkeleri olarak da düşünülebilir. Uygulamaya (implementasyona) yönelik bağlantılar da gereksizdir.

**Faaliyetler** etkileşim olarak modellenmelidir: "ATM kredi kartı kabul eder" ifadesi ATM ile kredi kartı arasında bir iştir ve ileride büyük olasılıkla bir metot çağrısına dönüşür. Bu yüzden bağlantı olarak tip-fiil-tip üçlüleri aranır.

**Üçlü bağlantılar** çoğunlukla senaryoların iyi yazılmamasından kaynaklanır. "Memur hesapla ilgili işlemleri girer" cümlesinde memur, hesap ve işlem kavramları bir aradadır ve üçünü bir noktada birleştiren bir bağlantı sevilen bir durum değildir. Bunun yerine iki ayrı cümle yazılmalıdır: "Memur işlemleri girer" ve "İşlemler hesapla ilgilidir". Böylece iki ikili bağlantı elde edilir:

```text
Memur --girer-- İşlem --ilgilidir-- Hesap
```

Başlangıçta bunu görmek kolay değildir, ama zamanla fark edilir; senaryolar yazılırken "X eylem Y" biçiminde cümleler kurmak daha doğrudur.

Hoca ardından örnek bağlantıları gösterdi (ekrandan, 00:55:00). Slaytın başlığındaki görev: "Tasarımı ilgilendiren bağlantıları ortaya çıkarın. Tip-fiil-tip doğru isim ataması yapın."

| Bir uç | Bağlantı | Diğer uç | Okunuşu |
|---|---|---|---|
| Store 1 | Contains | Register 1..* | Dükkân barındırır kasa |
| Register 1 | Captures | Sale 1..* | Kasa kaydeder satışı |
| Sale 1 | Paid-by | Payment 1 | Satış ödenir ödeme ile |
| Airline 1 | Employs | Person 1..* | Havayolu çalıştırır kişileri |
| Person 1..* | Assigned-to | Flight * | Kişiler ilişkilidir (atanmıştır) uçuşlarla |
| Flight * | Assigned-to | Plane 1 | Uçak atanmıştır uçuşa |
| Person 1 | Supervises | Person * | Bir kişi yönetir başka kişileri |

Son bağlantı bir sınıfın kendisiyle ilişkisidir: bir kişi aynı zamanda başka kişilerin yöneticisi (manager) olabilir ve bu, bağlantıdan anlaşılır. Hoca İngilizce adlandırmanın daha akıcı olduğunu, ama Türkçe de kullanılabileceğini söyledi.

Aradan sonra hoca bağlantılarla ilgili bir noktayı vurguladı: sadece o anki odak noktasıyla ilgili ve uygulamanın ileride gerçeğe dönüşecek tasarımına yönelik bağlantılar belirlenmelidir. Ayrıca bulunan her bağlantıya mutlaka bir ad verilmelidir; "dükkânla kasayı birbirine bağladım, bitti" yeterli değildir. Bu bağlantı neden vardır, eylemi (fiili) nedir? Bu bilgi ileride tasarımda yardımcı olur.

> **Hocanın vurgusu:** Bağlantının adı yazılamıyorsa o bağlantı büyük olasılıkla gereksizdir.

## 12. Satış sisteminin kavramsal modeli

Buraya kadar yapılanlar şöyle özetlendi: önce senaryolardaki isimlerin altı çizildi; bunların bir kısmı gereksiz olduğu için eleme yapıldı; sonra kavramların birbiriyle bağlantıları senaryolardaki fiillerden yola çıkarak, adları da yazılarak bulundu. Bu adımların sonunda ortaya çıkan model şudur (ekrandan, 01:10:00):

| Bir uç | Bağlantı | Diğer uç |
|---|---|---|
| ProductCatalog 1 | Contains | ProductSpecification 1..* |
| ProductCatalog 1 | Used-by | Store * |
| ProductSpecification 1 | Describes | Item * |
| Store 1 | Stocks | Item * |
| Store 1 | Houses | Register 1..* |
| Ledger 1 | Records-accounts-for | Store 1 |
| Ledger 1 | Logs-completed | Sale * |
| SalesLineItem 1..* | Contained-in | Sale 1 |
| SalesLineItem 0..1 | Records-sale-of | Item (karede "1..*") |
| Sale 0..1 | Captured-on | Register 1 |
| Sale 1 | Paid-by | Payment 1 |
| Sale 1 | Is-for | Customer 1 |
| Register 1 | Works-on (ok Cashier'dan Register'a okunur) | Cashier 1 |

<!-- BELİRSİZ: Records-sale-of bağlantısının Item ucundaki çoğullama karede "1..*" okunuyor, ürün tanımı kutusunun üstünde ayrıca bir "1" var; basit diyagramda (00:15:00) aynı uç "1" idi. -->

Hoca modeli şöyle okudu. Merkezde dükkân (Store) vardır. Dükkân ürünleri stoklar (Store stocks Item). Ürünlerin belirli tanımları vardır (ProductSpecification describes Item) ve bu ilişki 1'e n'dir: tek bir tanımla raftaki n tane aynı ürün tanımlanır, farkları seri numaralarıdır.

Bu probleme özgü olarak dükkânın tek tek ürün tanımlarına doğrudan erişmemesi, tanımların hepsinin bir **ürün kataloğunda** (bir klasör gibi) tutulması ve dükkânın bu kataloğa sahip olması tercih edilmiştir. Bu kavram büyük olasılıkla senaryolarda ürün tanımlarının bir yerde bütün hâlinde saklanması gerektiğine dair bir gereksinim görüldüğü için eklenmiştir. Ama zorunlu değildir: doğrudan "Store contains (ya da uses) ProductSpecification" bağlantısı da kurulabilirdi. Bu da yanlış bir analiz değil, farklı bir çözüm olurdu. Bunlar kesin kurallar değildir; problemin türüne ve barındırdığı kavram ailesine göre değişir.

Başka senaryolarda bir muhasebe sistemiyle konuşulduğu görülmüştü; bu yüzden bütün sistemin modeline `Ledger` eklenmiştir. Bir dükkânda bir ya da n tane kasa vardır. Kasiyer kasada çalışır; ilişkinin okuma yönü, bağlantı adının yanındaki küçük okla gösterilebilir. Kasiyer müşteriye fiyatı söylüyordu, ama kasiyeri fiyata bağlamaya başlarsak her şey birbirine bağlanır ve model fazla karmaşıklaşır. Bu bilgi zaten kasa ve satış üzerinden akabilir, bu yüzden ek bağlantı çizilmez.

Satış tarafında: satış ile kasa arasında 0..1 vardır (satış olmayabilir de). Her satışın bir ödemesi ve tek bir müşterisi vardır; her satışta bir ile n arasında satış kalemi bulunur. Satış kalemi ürünle "Records-sale-of" bağlantısıyla bağlanır. Böylece modelde dükkân, kasa, kasiyer, müşteri, satış, muhasebe defteri, ürün tanımı gibi kavramlar; bunların hangilerinin ilişkili olduğu ve çoğullamaları görülür. Hoca son örnek olarak çoğullamayı "bir muhasebe kaydı n tane satışın kaydını tutar" diye okudu.

> **Ders sonrası not:** Hoca `Ledger` sınıfından "muhasebeci" diye söz etti. `Ledger` büyük olasılıkla bir kişi değil, muhasebe defteri (hesap kayıt defteri) kavramıdır; satışların kaydını tutan budur.

Bu model, senaryolar üzerinden bir, iki, üç, belki dört iterasyonla tekrar tekrar gözden geçirilir: atlanan, eksik kalan ya da yanlış modellenen bir şey var mı? Model gerçek hayatı ve senaryolardaki akışları mümkün olduğunca yansıtmalıdır. Teknik olmayan biri de bu diyagrama bakıp kavramları anlayabilir; en fazla yıldızın ne demek olduğunu sorar ("n", yani bir ya da n tane). Düzeltme de önerebilir: "bizim kasalarımızda iki kasiyer çalışıyor" ya da "aynı anda birkaç çeşit ödeme alabiliyorum" diyebilir. O zaman ödemenin özelleşmiş hâlleri modellenir ve bir **genelleştirme** ilişkisi eklenir. Hoca bunu tahtada çizdi:

```text
Payment
  ├── CashPayment
  ├── CreditCardPayment
  └── CouponPayment
```

Model bu tür eklemelere, atlananları eklemeye ve fazla bulunanları çıkarmaya açık olmak için görselleştirilir. Bir yazılımcının önüne konduğunda da yazılımcının kafasında hemen tasarım oluşmaya başlar: "şu sınıflar zaten belli, ama kayıtları tutmak, veri tabanına yazmak için şu sınıflara da ihtiyaç duyarım" diyerek yazılım sınıfları eklemeye başlar. Kavramsal sınıf diyagramı teknik ve teknik olmayan tarafı ortak bir paydada buluşturan bir çeviri aracıdır.

## 13. Özelliklerin belirlenmesi

Kavramlar ve bağlantılar (çoğullamalarıyla) belirlendikten sonra son adım **özelliklerin** (nitelik, öz nitelik, attribute) belirlenmesidir. Slaytın metni şudur (ekrandan, 01:20:00):

- Özellik: nesne yaratıldığında nesneye özgü değer alabilen veri.
- Senaryolarla ilgili nitelikler bulunmalıdır.
- Basit veri tipleri ile ifade edilirler.
  - birimleri varsa doğru değil. (para gibi)
- Karmaşık tipteyse, başka bir sınıf olma olasılığı yüksektir.
  - birden fazla alansa (tel no, ad soyad)
  - işlem yapılıyorsa (kredi kartı ve doğrulama)
  - kendi nitelikleri varsa (fiyat: geçerlilik tarihi)

Özellik, bir nesnenin veri depolarıdır. Bir özelliğin birimi varsa büyük olasılıkla o da başka bir sınıftır: örneğin para için bir `Currency` (para birimi) kavramı olmalıdır ve kavram tanıtılmadan kullanılması doğru olmaz. Telefon numarası ya da ad soyad tek bir özellik gibi görünse de birden fazla alan taşır; bu yüzden büyük olasılıkla ayrı bir sınıftır. İşlem yapılıyorsa (kredi kartı ve doğrulama) doğrulama büyük olasılıkla başka bir sınıfın işidir.

Kendi nitelikleri olan özellik için hoca tahtada bir örnek çizdi: ürün tanımında fiyat tutuluyor, ama fiyatın bir geçerlilik tarihi var. O zaman fiyat ürün tanımından çıkarılır ve ayrı bir kavramsal sınıf olur:

```text
ProductSpecification 1 --describes-- 1 Price [validDate]
```

(Hocanın tahtada çizdiği ek; bağlantı adı ve uçlardaki 1-1 değerleri hocanın elle yazdıklarıdır.) Böylece model büyüyebilir; bu tamamen probleme özeldir.

Slayttaki ikinci örnek kasiyerdir (ekrandan, 01:20:00):

```text
Yanlış:  Cashier [name, currentRegister]     ("Basit bir özellik değil")
Doğru:   Cashier [name]  1 --Uses-- 1  Register [number]
```

Kasiyerin adı basit bir özelliktir. Ama kasiyerin kasası, fiyat örneğinde olduğu gibi kendine has özellikleri olan bir kavramdır; bu yüzden özellik olarak değil, ayrı bir nesne olarak modellenir, aradaki bağlantı kurulur, adı ve çoğullamaları yazılır. Bu yapıldığında daha doğru bir kavramsal modelleme yapılmış olur.

## 14. Özellik ayrıntıları: görünürlük, türetilmiş nitelik, sabit, opsiyonel değer

Slaytın metni: "Analizde kavramsal sınıf özellikleri hakkında detay bilgi varsa, tasarıma kaynak olması için bunlar da belirtilebilir." (ekrandan, 01:25:00). Analiz modelinde bu kadar ayrıntı normalde beklenmez, çünkü yalnız problem modellenir; ama kesin bilgi varsa eklemek sorun yaratmaz. Slayttaki üç örnek sınıf şudur:

```text
Sale
  - dateTime : Date
  - / total : Money

Math
  + pi : Real = 3.14 {readOnly}

Person
  firstName
  middleName : [0..1]
  lastName
```

- **Görünürlük:** `-` işareti private görünürlük demektir (slayttaki not: "Private visibility attributes"). Bu özellikler dışarıya sunulmaz; yalnız sınıfın içinde ya da metotları üzerinden kullanılır. `+` işareti public görünürlük demektir.
- **Tipler:** `Date` ve `Money` gibi tipler normalde ayrı kavram olarak gösterilmelidir. Diyagramı sade tutmak için bunlar bir kenarda bir kez gösterilip özelliklerin tipi olarak yazılabilir: tarih bir `Date` sınıfından, toplam `Money` cinsinden olur; `Money`'nin de belki bir para birimi olur.
- **Türetilmiş nitelik:** Başında `/` olan özellik türetilmiş (derived) niteliktir. Doğrudan elde tutulmaz, diğer nitelikler kullanılarak hesaplanır (slayttaki not: "Derived attribute. Diğer nitelikler kullanılarak hesaplanır.").
- **Stereotip ve sabit:** `{readOnly}` bir stereotiptir (özel tanımlama). Değerin sabit olduğunu, değiştirilemeyeceğini söyler; bir dilde `final`, başka bir dilde `const` denen şeyin genel UML karşılığıdır. `Math` örneğinde `pi` public, tipi `Real`, değeri 3.14 ve sabittir: herkes `Math.pi` diye erişebilir ve 3.14 değerini alır (slayttaki not: "Public visibility readonly attribute with initialization").
- **Seçime bağlı (opsiyonel) değer:** `[0..1]` çoğullaması opsiyonel değeri gösterir. Kişi kavramının ilk adı, orta adı ve soyadı vardır; orta ad tanımlanmayabilir (slayttaki not: "Optional value").

Bunlar tasarıma kaynak olur. Zorunlu değildir, ama görülüyorsa ve gösterilmek isteniyorsa kavramsal sınıf diyagramına konabilir.

## 15. Tamamlanmış model ve tek doğru olmaması

Hoca adımları şöyle özetledi: senaryolardan yola çıkıldı, sınıflar aday sınıflardan süzülerek bulundu; aralarındaki bağlantılar sade ve tasarıma yönelik olacak biçimde keşfedildi; çoğullamalar görülebildiği kadarıyla yazıldı; son olarak analiz aşamasında görülebilen bütün özellikler ve varsa tasarıma yönelik yönlendirmeler eklendi.

Satış senaryosunun son modeli öncekinin daha büyük ve daha net çizilmiş hâlidir (ekrandan, 01:30:00). Bağlantılar 12. bölümdeki tabloyla aynıdır; eklenen özellikler şunlardır:

| Sınıf | Özellikler |
|---|---|
| ProductSpecification | itemID, description, price |
| Store | name, address |
| Register | id |
| Cashier | id |
| Payment | amount |
| SalesLineItem | quantity |
| Sale | date, time, / total |
| ProductCatalog, Ledger, Item, Customer | (yok) |

Fiyat kompozit bir yapıysa ayrı bir nesne olarak modellenebilir ya da tipi `Money` diye belirtilebilir. Kasaların ve kasiyerin kimlikleri, ödemelerin tutarı, dükkânın adı ve adresi senaryoda geçtiği için önemlidir. Satış satırındaki miktar da kullanılacaktır: ürün tanımından gelen fiyat bilgisi ürün üzerinden satış satırına taşınır ve satıştaki `/ total` hesaplanır. Başındaki `/` bunun türetilmiş olduğunu gösterir: n tane satış satırı vardır, her birinde belirli miktarda ve belirli fiyatta ürün vardır ve toplam bunlardan hesaplanır. Senaryodaki işleri yerine getirmek için gereken özellikler modelde görülmelidir; görülmezse model eksik kalır.

Her seferinde tam doğru ve eksiksiz bir model bulmak olası değildir; bu yaptıkça alışılan bir iştir. Farklı analistler farklı kavram çıktıları elde edebilir; **tek bir doğru yoktur**, birden fazla çözüm aynı problemi modelleyebilir. Varsayımlar, görülenler ve görülmeyenler, sistemin içinde bırakılanlar ve dışına atılanlar modeli değiştirir. Hoca bunu modelden parçalar silerek gösterdi: biri "muhasebe kısmı benim sistemimi ilgilendirmiyor" deyip `Ledger` tarafını tamamen atabilir; biri "müşteri yalnız satışta adı geçen bir kavram, modeli karıştırıyor" diyebilir; biri "kasiyer yalnız ürün okutuyor, tuşa basıyor" deyip kasiyeri çıkarabilir, bir başkası kasiyerin kalması gerektiğini savunabilir. Bunların hepsi varsayımlar altında doğru sayılabilir. Ama senaryolarda kasiyerin üstlendiği sorumluluklar ve aktör olarak rolleri varsa, müşterinin ödeme yapma, ürünleri alıp koyma gibi rolleri varsa, muhasebe sistemiyle vergi hesapları yapmak gerekiyorsa, bunlar modelde bulunmalıdır.

> **Hocanın vurgusu:** Gördüğünüz ayrıntı gerekliyse kavramsal modelinizde barındırmak zorundasınız.

Kavramsal modelde neyin olmadığına da dikkat çekildi: sınıfların **üçüncü bölmesi**, yani metotlar ve davranışlar yoktur. Çünkü burada kavramların ne olduğu, bağlantıları ve ilişkileri bulunur; hep "ne?" diye sorulur. Örneğin satışın toplamının hesaplanacağı söylendi; tasarımda bunun için bir `getTotal()` metodu olacaktır. Ama bu, işin nasıl yapılacağının ayrıntısıdır: bir algoritma gerekir, algoritma büyük olasılıkla bir döngüde her satış satırına `getSubTotal()` sorar, alt toplamlar için de `getPrice()` ile fiyatlar alınır. Tek bir hesap için üç metot ortaya çıkmıştır; belki de iş böyle yapılmayacak, bir liste süzülerek yapılacaktır. Bu "nasıl" ayrıntıları analiz aşamasında bilinmez ve ilgilenilmez. Hoca bu metotları tahtada yazdıktan sonra sildi: kavramsal modelde nasıl sorusunun cevabı yoktur, ama "bu problem uzayında neler var, kavramlar birbiriyle nasıl ve ne kadar bağlantılı?" sorularının cevabı görsel olarak alınır ve problem modelini ifade etmek için bu sınıf diyagramı yeterlidir.

## 16. Use case modeli, alan modeli ve tasarım modeli

Son olarak hoca modeller ve uzaylar arasındaki bağıntıyı bir şemayla gösterdi (ekrandan, 01:40:00). Şemada üç katman vardır:

- **Domain Model (alan modeli):** `Sale [date, ...]` 1 -- 1..* `SalesLineItem [quantity]` -- `...`
- **Use-Case Model:** use case'ler (Process Sale: "1. Customer arrives ... 3. Cashier enters item identifier ..."), sistem sıralama diyagramları (System Sequence Diagrams: `:Cashier` aktöründen `:System`'e sistem olayları `makeNewSale()`, `enterItem(id, quantity)`, `endSale()`, `makePayment(amount)`) ve sözleşmeler (Contracts: "Operation: makeNewSale, Post-conditions: ..."; "Operation: enterItem, Post-conditions: A SalesLineItem instance sli was created ...").
- **Design Model (tasarım modeli):** `:Register`, `:ProductCatalog` ve `:Sale` nesneleri arasında bir sıralama diyagramı.

Şemadaki oklar ve açıklamalar şöyledir: use case'lerdeki adımlar sistem olaylarına dönüşür; alan nesneleri (domain objects) use case'lerden çıkar; sözleşmelerdeki ardıl koşullar "durum değişikliğine uğrayan alan nesnelerini, niteliklerini ve bağlantılarını" anlatır; sözleşmeler use case'lere ek olarak yazılım tasarımının karşılaması gereken gereksinimlerdir; alan modeli de bir okla tasarım modelini besler.

Hocanın anlatımıyla: mor alan iş analizidir, yani iş gereksinimleri ve use case'lerdir. Use case'ler önce alan modelinin oluşmasını sağlar: senaryolar okunup işlenir ve "bu problemin çözümü için gereken kavramlar bunlardır" denir (satış, satış kalemi ...). Sonra alan modeli tasarım modelini besler: kavramsal sınıflardan yola çıkılarak gerçek yazılım sınıfları oluşturulur. Bu da sıralama (sequence) ve aktivite diyagramlarıyla ifade edilecektir.

Tasarım modelindeki sıralama şudur:

```text
       enterItem(itemID, quantity)
  ---------------------------------> :Register
  :Register --spec := getProductSpec(itemID)--> :ProductCatalog
  :Register --addLineItem(spec, quantity)-----> :Sale
  ...
```

Use case'teki "Cashier enters item identifier" adımı `enterItem` adlı bir metoda dönüşür. Kasiyer bu metoda ürün kodunu (barkod numarası) ve miktarı (örneğin 3 adet bisküvi) parametre olarak verir. Kasa bunları alır (alan modelinde kasa satışla ilişkiliydi), ürün kataloğundan o ürünün bilgilerini ister; adını, tutarını ve vergisini öğrendikten sonra satışa satırı ekler (örneğin 3 adet, tanesi 2 liradan 6 lira). Burada artık gerçek nesneler vardır: katalog, satış ve kasa birer yazılım nesnesi olmuştur. Kasanın bir metodu vardır ve onu bir aktör (kasiyer) çağırır; metot kendi içinde başka nesnelerden bilgi alır, başka nesnelere yazar. Farklı nesneler alan modelindeki temel üzerinden etkileşerek çalışan bir nesneye yönelik yazılım oluşturur.

Bu yalnız tek bir eylemdir; bir senaryoda bunlardan birkaç tane olabilir ve her sorumluluk için ayrı bir diyagram çizmek gerekir. Hoca sistem sıralama diyagramları gösterimini kullanmayacağını, kafa karıştırmamak için doğrudan use case'lerden alan modeline, alan modelinden tasarım modeline gideceklerini söyledi. Tasarım modeli bir yandan use case'lerden de beslenir, çünkü sorumluluklar orada yazılıdır. Böylece süreç iş analizinden kavram oluşturmaya, kavramdan çözüm geliştirmeye, çözümden de kodlamaya (gerçekleştirmeye) doğru ilerler.

## Örnek Sorular

**Soru 1** (ekrandan, 00:30:00): Aşağıdaki "Process Sale" ana başarı senaryosunda aday kavramsal sınıf olabilecek isimleri ve isim tamlamalarını işaretleyin.

```text
1. Customer arrives at a POS checkout with goods and/or services to purchase.
2. Cashier starts a new sale.
3. Cashier enters item identifier.
4. System records sale line item and presents item description, price,
   and running total. Price calculated from a set of price rules.
5. System presents total with taxes calculated.
6. Cashier tells Customer the total, and asks for payment.
7. Customer pays and System handles payment.
8. System logs completed sale and sends sale and payment information to the
   external Accounting system (for accounting and commissions) and Inventory
   system (to update inventory).
9. System presents receipt.
10. Customer leaves with receipt and goods (if any).
7a. Paying by cash: 1. Cashier enters the cash amount tendered.
    2. System presents the balance due.
```

> **Çözüm (derste verildi):** Customer, POS checkout, goods, services, Cashier, sale, item identifier, sale line item, item description, price, (running) total, price rules, taxes, payment, Accounting (system), commissions, Inventory (system), receipt, cash, amount tendered, balance due. "System" çözülen problemin kendisi olduğu için işaretlenmez; daha önce işaretlenen isim yeniden işaretlenmez, "new sale" ifadesinde yalnız "sale" alınır. Eleme aşamasında örneğin "amount tendered" ödemenin özelliği olur, kredi kartı nakit senaryosunda ilgisizdir, muhasebe sistemi belirsiz bir sınıftır.

**Soru 2** (ekrandan, 00:55:00): Tasarımı ilgilendiren bağlantıları ortaya çıkarın ve tip-fiil-tip biçiminde doğru isim ataması yapın: (a) Store, Register, Sale, Payment; (b) Airline, Person, Flight, Plane.

> **Çözüm (derste verildi, slayttaki model):** (a) Store 1 --Contains-- 1..* Register; Register 1 --Captures-- 1..* Sale; Sale 1 --Paid-by-- 1 Payment. (b) Airline 1 --Employs-- 1..* Person; Person 1..* --Assigned-to-- * Flight; Flight * --Assigned-to-- 1 Plane; Person 1 --Supervises-- * Person (bir kişi aynı zamanda yönetici olabilir).

**Soru 3** (derste sözlü, 00:38:30): Satıştaki toplam tutar ayrı bir kavramsal sınıf olarak modellenmeli mi?

> **Cevap (derste verildi):** Hayır. Toplam tutar o anda oluşan ve hangi üründen kaç tane alındığına göre değişen bir değerdir; ondan birçok nesne türetilmez. Satışın türetilmiş bir özelliği (`/ total`) olarak gösterilir.

**Soru 4** (derste sözlü, 00:50:42): "Memur hesapla ilgili işlemleri girer" cümlesindeki üçlü bağlantı nasıl modellenmelidir?

> **Cevap (derste verildi):** Üçlü bağlantı ikili hâle çevrilir: "Memur işlemleri girer" ve "İşlemler hesapla ilgilidir". Böylece Memur --girer-- İşlem ve İşlem --ilgilidir-- Hesap bağlantıları elde edilir.

## Dersin Toparlaması

Bu derste nesneye yönelik bir sistem analizi safhasının nasıl yürütüldüğü işlendi. Önce use case'ler yazılır ve use case diyagramı çizilir. Ardından senaryolardaki isimler işaretlenerek aday kavramsal sınıflar bulunur ve fazlalık, ilgisiz, belirsiz sınıflar, nitelikler, işlemler, roller ve gerçekleme elemanları elenir; gerektiğinde bilgi kaybını önlemek için betimleme sınıfları eklenir. Sonra senaryolardaki fiillerden bağlantılar bulunur, tip-fiil-tip biçiminde adlandırılır, çoğullamaları yazılır ve gereksizleri elenir. Son olarak özellikler basit veri tipleriyle belirlenir; karmaşık özellikler ayrı sınıflara dönüştürülür ve gerekirse görünürlük, türetilmiş nitelik, sabit ve opsiyonel değer gibi ayrıntılar eklenir. Sonuç, metotları olmayan, iki bölmeli sınıflardan oluşan bir kavramsal sınıf diyagramıdır (alan modeli). Bu model hem müşteriye hem yazılım ekibine gösterilebilir ve tek bir doğrusu yoktur.

Alan modeli, tasarım modelinin temelidir. Sonraki konu sistem tasarımıdır: veri akış diyagramlarından ya da nesneye yönelik modelden başlayarak sıralama diyagramlarının nasıl çizileceği, çıktı tasarımı, veri yapısı tasarımı (varlık ilişki diyagramlarına dönüşle) ve arabirim tasarımı işlenecek, ardından gerçekleştirme, test, devreye alma ve bakım aşamalarına geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
