# Ders 2 Çalışma Özeti

## Genel Konular

- Bilgisayar Bilimlerine Giriş dersinin amacı ve kapsamı
  - Derste bilgisayar mühendisliğinin çalışma alanları, bilgisayar biliminin ne olduğu ve mezuniyet sonrası karşılaşılacak konular ele alınır.
  - Bir bilgisayarın hangi parçalardan oluştuğu öğretilir.
  - Asıl hedef, bir bilgisayarın problem çözmek için nasıl programlanacağını ve bilgisayara izleteceğimiz yolun nasıl tasarlanacağını öğrenmektir.
  - Algoritma tasarımı öğrenildikten sonra tasarlanan algoritmalar C programlama diliyle kodlanır.
- Algoritma kavramına ilk bakış
  - Bir problemi çözmek için izlenen genel adımlara algoritma denir.
  - Önce verilen bir problemin bilgisayarda hangi adımlarla çözüleceği tasarlanır, ardından bu adımlar kodlanır.
  - Algoritmalar akış diyagramı ile çizilerek ifade edilir. Bu nedenle derste kâğıt-kalemle çizim yapmak gerekir.
- Bilgisayar mühendisliğinin çalışma alanları
  - Bilgisayar mühendisliği temelde yazılım ve donanım olmak üzere iki ana başlığa ayrılır.
  - Büyük veri, derin öğrenme, veritabanı, işletim sistemleri ve ağlar (network) bu alanın örnek çalışma konularıdır.
  - Bilgisayar mühendisliği, yazılım mühendisliği gibi alt alanlarda uzmanlaşmış bölümlere göre "resmin bütününü" görmeyi hedefler. Mezunun donanım hakkında da belli düzeyde bilgi sahibi olması beklenir.
- Programlama dili seçimi ve C dilinin rolü
  - Bölüm derslerinde en sık karşılaşılan dil C'dir. 4-5 derste C kullanılır.
  - C sistem seviyesinde bir dildir ve birçok dilin atası konumundadır. Python'ın yorumlayıcısı da C ile yazılmıştır.
  - İşletim sistemleri C ile yazıldığı için C ile sistem seviyesi dahil yazılamayacak bir program yoktur. Yine de C her problem için doğru dil değildir.
  - C, donanım seviyesine en fazla hâkim olunabilen en üst seviye dil olduğu için bilgisayar bilimlerini temsil eden dil olarak seçilmiştir.
  - İleriki yıllarda nesneye dayalı programlama için Java görülür. Python ise genellikle bilgisayar projesi, bitirme projesi ve stajlarda öğrenilir.
- Dil bilmek ile algoritma tasarlamak arasındaki fark
  - Önemli olan dil bilmek değil, problemi çözecek algoritmayı tasarlayabilmektir.
  - Bir problem için uygun dili seçebilmek de önemlidir: alternatifler değerlendirilir ve probleme uygun olanı tercih edilir. Uygunsuz dille kodlanan iyi bir tasarım da anlamını yitirebilir.
- Biçimsel (formal) diller ve doğal diller
  - Programlama dilleri biçimsel dillerdir. Her ifade tek ve net bir anlama karşılık gelir.
  - Doğal dillerde bir ifadenin birden çok anlamı olabilir. Biçimsel dillerde ise belirsizlik ve bulanıklık yoktur.
  - C'nin sözdizimi (syntax) birçok dilin temelinde olduğu için C öğrenmek diğer dillere geçişi kolaylaştırır.
- Derleyici (compiler) ve geliştirme ortamı (IDE)
  - C kodları için GNU C derleyicisi GCC kullanılabilir.
  - Derleyici ile geliştirme ortamı farklı kavramlardır. IDE (Integrated Development Environment), kodun yazıldığı ve yönetildiği bütünleşik ortamdır.
- Güncel diller ve kullanım alanları
  - JavaScript özellikle ön yüz (front-end) geliştirmede yaygındır. Python ise daha çok veri bilimi ve veri işleme tarafında öne çıkar.
  - İki dilin hedefleri farklıdır, farklı alanlarda uzmanlaşmışlardır.
- Akreditasyon kavramı
  - Akreditasyon, bir kurumun belirlenmiş kurallar ve standartlar çerçevesinde hizmet verdiğini gösteren belgeyi alma sürecidir. TSE'nin ürün ve işletmeler için verdiği belgeler buna benzer bir örnektir.
  - Mühendislik eğitiminde Türkiye'de MÜDEK, yurt dışında ABET bu tür akreditasyon kurumlarıdır.
  - Kurum başvurur, akreditasyon kuruluşu yerinde denetler. Standartlar sağlanıyorsa belirli bir süre için akreditasyon verilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bu dersin temel bilgileri ileriki yılların temelidir
  - BBG başta kolay görünebilir. Ancak buradaki temel doğru edinilirse 2. ve 3. sınıf dersleri çok daha rahat geçer.
- Öğrenmek için yazmak ve tekrar etmek gerekir
  - Sadece bakarak, görerek ya da dinleyerek iyi öğrenilmez. En iyi öğrenme yolu öğrenileni yapmak ve tekrar etmektir.
  - Derste not almak ve sonra yazarak tekrar etmek, problemin çözüm mantığını oturtmayı sağlar. Bu, matematik problemlerinde de böyledir.
  - Ders dışında derste çözülen örnekler, çözümlerine bakmadan tekrar çözülmelidir.
- Sunum yerine tahta mantığı
  - Algoritma ve akış diyagramı gibi konular sunumdan izlenince anlaşılır görünse de öğrenme açısından yetersiz kalır. Bu nedenle ders, adım adım yazılan bir tahta mantığıyla anlatılır.
- Hatalı çözümler de öğreticidir
  - Öğrencilerin yaptığı hatalar genelde sınıfın büyük kısmında ortaktır. Bu çözümler üzerinden konuşmak herkesin öğrenmesine katkı sağlar.
- Algoritmik düşünme bir yetenektir ve geliştirilebilir
  - Ders, programlama ve algoritma hiç bilmeyen bir öğrenci varsayılarak planlanmıştır.
  - Algoritmik düşünmeyi kavrama süresi kişiden kişiye değişir: bir haftadan birkaç aya kadar uzayabilir. Pes etmeden soruları kendi başına çözmeye çalışmak bu farkı kapatır.
- İngilizce kaynak takibi
  - Bilgisayar mühendisliğindeki yenilikler çoğunlukla İngilizce kaynaklarda ortaya çıkar. Güncel bilgiyi takip etmek için İngilizce kaynak okumak ve dinlemek önemlidir.
- Alan seçerken geleceğe bakmak
  - Mezuniyete kadar geçecek 4-5 yılda doygunluğa ulaşacak konular yerine yeni yeni ilgi çeken ve ileride popüler olacak konulara yönelmek tavsiye edilir.

## Kısa Tekrar Notları

- Algoritma: bir problemi çözmek için izlenen genel adımlar dizisi.
- Ders akışı: problem → algoritma tasarımı (akış diyagramı) → C ile kodlama.
- C: sistem seviyesi, donanıma en yakın üst seviye dil. Birçok dilin atası ve sözdizimi kaynağı.
- Programlama dilleri biçimsel dillerdir: her ifadenin tek bir anlamı vardır.
- Derleyici (GCC) ≠ geliştirme ortamı (IDE).
- Dil bilmekten önce problemi çözecek algoritmayı tasarlayabilmek gelir.
- Bilgisayar mühendisliği = yazılım + donanım. Alt alanlar: büyük veri, derin öğrenme, veritabanı, işletim sistemi, ağlar.
- Akreditasyon: standartlara uygunluğun denetlenip belgelenmesi (MÜDEK, ABET).
- Öğrenme yöntemi: not al, yazarak tekrar et, örnekleri çözüme bakmadan yeniden çöz.

## Detaylı Açıklamalar

Bu ders, dönemin ilk buluşması olarak dersin ve bölümün genel bir tanıtımı niteliğindedir. Hoca, Bilgisayar Bilimlerine Giriş dersinin bilgisayar mühendisliği eğitiminin temel taşlarından biri olduğunu belirtir. Dersin içeriği üç ana eksende ilerler. Birincisi, bilgisayar mühendisliği ve bilgisayar biliminin ne olduğu ve mezunların hangi alanlarda çalıştığıdır. İkincisi, bir bilgisayarın temel bileşenleridir. Üçüncüsü ve en önemlisi, bir problemin bilgisayar tarafından çözülebilmesi için gereken adımların, yani algoritmanın tasarlanmasıdır.

Algoritma, bir problemi çözmek için izlenen genel adımların bütünü olarak tanımlanır. Derste önce günlük hayattan problemler ele alınacak ve bilgisayarın bu problemleri nasıl çözdüğü incelenecektir. Ardından öğrencilerin kendilerine verilen bir problem için çözüm adımlarını tasarlaması beklenir. Bu adımlar akış diyagramlarıyla çizilir ve daha sonra C programlama diliyle kodlanır. Hoca, akış diyagramı gibi görsel çözümlerin sunumdan izlenerek değil, çizerek öğrenildiğini vurgular. Bu yüzden kâğıt-kalem ya da tablet hazır bulundurmak gerekir.

C dilinin seçilmesinin gerekçesi ayrıntılı açıklanır. C, sistem seviyesinde çalışabilen ve işletim sistemlerinin yazıldığı bir dildir. Bu sayede C ile yazılamayacak bir program türü yoktur. Ancak bu, C'nin her problem için en uygun dil olduğu anlamına gelmez. Her dilin en iyi çözdüğü problem türleri vardır. C'nin bilgisayar bilimlerini temsil etmek için seçilmesinin nedeni, donanım seviyesine en fazla hâkim olunabilen en üst seviye dil olmasıdır. Python gibi popüler dillerin yorumlayıcısının da C ile yazıldığı hatırlatılır. Bölüm müfredatında C'den sonra nesneye dayalı programlama için Java gelir. Python ise genellikle proje ve staj süreçlerinde öğrenilir.

Hoca, dil öğrenme kaygısına kapılmamak gerektiğini söyler. Bilgisayar mühendisliğinde öncelik tasarımdır: bir problem doğru tasarlanabiliyorsa herhangi bir dille kodlamak zor değildir. Programlama dilleri biçimsel dillerdir. Doğal dillerdeki gibi bir ifadenin birden çok anlamı yoktur, ne yazılıyorsa o anlama gelir. Ayrıca C'nin sözdizimi birçok dile temel oluşturduğu için C'yi iyi öğrenen öğrenci diğer dillerin yapısını kolayca tanır. Bununla birlikte her dilin kendine özgü yeteneklerini öğrenmek ayrıca çaba ister.

Pratik bir soru üzerine derleyici ile geliştirme ortamı arasındaki fark açıklanır. C kodlarını derlemek için GNU C derleyicisi (GCC) yeterlidir. IDE ise kodun yazıldığı, düzenlendiği ve çalıştırıldığı bütünleşik ortamdır. İkisi farklı kavramlardır.

Bilgisayar mühendisliğinin kapsamı açıklanırken alanın yazılım ve donanım olmak üzere iki ana kola ayrıldığı belirtilir. Büyük veri, derin öğrenme, veritabanı, işletim sistemleri ve ağlar gibi birçok çalışma alanı vardır. Mezunlar zamanla bunlardan birinde uzmanlaşır. Bilgisayar mühendisliğinin farkı, öğrenciye resmin bütününü göstermesidir. Bu yüzden derslerden seçici davranmadan hepsinden temel bilgileri almak, ileride uzmanlık alanı dışındaki problemlerde de fark yaratmayı sağlar.

Güncel diller hakkında JavaScript'in özellikle ön yüz geliştirmede, Python'ın ise veri bilimi ve veri işlemede öne çıktığı belirtilir. İki dilin farklı hedeflere yönelik olduğu, birinin diğerinden önemsiz sayılamayacağı vurgulanır.

Son olarak akreditasyon kavramı açıklanır. Akreditasyon, bir kurumun belirlenmiş standartlara uygun hizmet verdiğinin bağımsız bir kuruluş tarafından denetlenip belgelenmesidir. Ürün ve işletmelerde TSE'nin verdiği belgeler buna benzer. Mühendislik eğitiminde Türkiye'de MÜDEK, uluslararası alanda ABET bu rolü üstlenir. Kurum başvuru yapar, akreditasyon kuruluşu yerinde inceleme yapar ve standartlar sağlanıyorsa belirli bir süre için akreditasyon verir. Hoca, akreditasyonun önemli ama tek başına belirleyici olmadığını, asıl önemli olanın kalite anlayışını kurum kültürü hâline getirmek olduğunu belirtir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
