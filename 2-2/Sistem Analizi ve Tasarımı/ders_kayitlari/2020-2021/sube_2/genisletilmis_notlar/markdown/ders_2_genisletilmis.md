# Ders 2 Genişletilmiş Notu: Bilgi Sistemi Türleri, Bilgi Sistemi Tarafları ve Geliştirme Süreci

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin planı ve bilgi sistemi tanımının tekrarı
- 2. Bilgi sistemi türleri
- 3. Bilgi sistemi türlerinin ayrıntıları
- 4. Bilgi sistemi türleri arasındaki ilişki
- 5. Bilgi sistemi tarafları: kullanıcı ve yönetici
- 6. Sistem analisti
- 7. Sistem tasarımcıları ve yazılım mimarı
- 8. Yazılımcılar ve destek personeli
- 9. Bilgi sistemi geliştirme süreci
- 10. Örnek Sorular

## 1. Dersin planı ve bilgi sistemi tanımının tekrarı

Önceki derste dersin kapsamı ve hedefleri tanıtılmıştı. Bu derste sistem analizi ve tasarımı safhalarına girmeden önce bir bilgi sistemi projesinin baştan sona nasıl yürütüldüğünü, hangi adımlardan geçildiğini, neden bu sırayla yapıldığını ve bu sürecin hangi modelleri olduğunu konuşmak hedefleniyor. Bunun için üç başlık işlenir: bilgi sistemi türleri, bilgi sisteminin tarafları (paydaşları) ve bilgi sistemi geliştirme süreci. Süreç modellerine yalnız hızlı bir bakış yapılır; ayrıntıları sonraki derse kalır.

Önce bilgi sisteminin tanımı hatırlatılır. Her sistemin mutlaka bir amacı vardır; amacı olmayan sistem olamaz. Bilgi sistemleri de girdi, işlem ve çıktı şeklinde çalışan süreçlerden oluşan çözümlerdir. Slayttaki tanım şöyledir (ekrandan, 00:10:00):

- Amaç: problemlerin analizi, yeni ürün oluşturulması, karmaşık nesnelerin canlandırılmasında kontrolü ve koordinasyonu sağlayarak karar almaya destek olmak.
- Girdi: her türlü bilginin toplanması.
- İşlem: bilginin işlenmesi, saklanması, dağıtılması.
- Çıktı: işlenmiş ve ilişkilendirilmiş bilgi.

Bir bilgi sistemi bu amaçlardan yalnız birine hizmet edebileceği gibi birkaçını bir arada da barındırabilir: yeni bir ürün oluşturmak, karmaşık bir sürecin kontrolünü ya da koordinasyonunu sağlamak ya da bir kararın alınması için destekleyici çıktılar üretmek gibi. Bu amaçları girdi-işlem-çıktı zinciriyle işleyerek sonuç üreten sistemlere bilgi sistemi denir.

## 2. Bilgi sistemi türleri

Bilgi sistemleri temelde altı başlıkta incelenir. Hoca bunları bir piramit üzerinde, tabandan (işlevsel kademeler) başlayıp yukarıya, yönetim kademesine doğru anlattı. Piramit yukarı çıktıkça daralır. Slayttaki şema metin olarak şöyledir (ekrandan, 00:15:00):

```text
Stratejik Seviye Sistemleri          -> Üst Yönetim Bilgi Sistemleri (ÜBS)
  5 Yıllık Satış Tahmini, 5 Yıllık Plan, 5 Yıllık Bütçe Planlama,
  Kar Planlama, İşgücü Planlaması

Yönetim Seviyesindeki Sistemler      -> Yönetim Bilgi Sistemleri (YBS)
                                        Karar Destek Sistemleri (DDS)
  Satış Yönetimi, Envanter Kontrolü, Yıllık Bütçeleme, Yatırım Analizi,
  Satış Bölge Analizi, Üretim Programlama, Maliyet Analizi, Fiyat/Kar Analizi

Bilgi Seviyesindeki Sistemler        -> Bilgi Tabanlı İş Sistemleri (BTİS)
                                        Ofis Otomasyon Sistemleri (OOS)
  Bilgisayar Destekli Tasarım/Üretim, Simülasyon, Sanal Gerçeklik,
  Kelime İşlem, Döküman Yönetimi, Elektronik Takvim

İşlemsel Seviyedeki Sistemler        -> İşlemsel Bilgi Sistemleri (İBS)
  Sipariş Takibi, Sipariş İşleme, Makine Kontrolü, Tesis/Fabrika Programlama,
  Hammadde Hareketleri Kontrolü, Nakit Yönetimi, Bordro Yönetimi,
  Borçlar Muhasebesi, Alacaklar Muhasebesi, Tazminat, Eğitim & Geliştirme,
  İşçi Kaydı Tutma

Taban (işlevsel birimler): Satış ve Pazarlama | Üretim | Finans | Muhasebe | İnsan Kaynakları
```

> **Ders sonrası not:** Slaytta karar destek sistemleri için "DDS" kısaltması yazılıdır. Hoca bunun yanlış yazıldığını, İngilizce adı Decision Support Systems olduğu için "DSS" olması gerektiğini söyledi.

Türlerin İngilizce adlarıyla özet listesi: Executive Information Systems (EIS), Management Information Systems (MIS), Decision Support Systems (DSS), Knowledge Based Systems, Office Automation Systems (OAS) ve Transaction Processing Systems (TPS).

## 3. Bilgi sistemi türlerinin ayrıntıları

### 3.1 İşlemsel bilgi sistemleri (TPS)

İlk tür işlemsel bilgi sistemleridir (İBS, İngilizcesi Transaction Processing Systems, TPS). Piramitte pembe renkle gösterilen en alt kademededir. "İşlem" (transaction) bir işin yerine getirilmesi demektir; bu sistemler işlerin bilgisayarın işlem kapasitesi ve gücü kullanılarak yapılmasını sağlar. Hoca bu kademeyi "işin mutfağı" olarak niteledi.

Bir fabrika örneği üzerinden farklı birimlerdeki işlemsel sistemler şöyle anlatıldı:

- Satış ve pazarlama: satışçı müşteri ilişkilerini bir bilgi sistemiyle takip eder. E-ticaret uygulamaları da işlemsel bilgi sistemidir: müşteri ürünü seçer, kredi kartıyla öder ve sipariş üreticinin ya da dağıtıcının önüne düşer. Ürün depoda varsa çekilip sevk edilir, yoksa üretilmesi sağlanır; teslim süresi içinde teslimatın gerçekleşmesi takip edilir. Bu bilgilerin saklanması ve işlenmesi işlemsel bilgi sisteminin işidir.
- Üretim: makinenin ne zaman, hangi hızda çalışacağını denetleyen bir kontrol sistemi, amaçlarından biri kontrol olan bir işlemsel bilgi sistemidir.
- Finans: ortaklar, yatırımcılar, borsa işlemleri, siparişlerden gelen ödemeler, vadeli (çek, taksit) ödemeler ve hammadde için yapılan ödemeler takip edilir; kayıtları tutulur, denetlenebilir ve mali raporları oluşturulabilir. Hoca bunları "sıkıcı ama düzenli, doğru yapılması gereken işler" olarak niteledi.
- Muhasebe: çalışanların bordrosu başlı başına bir iştir. Kaç gün çalışıldığı (insan kaynaklarından), rapor süresi (bu kısmı sigorta sistemi öder), avans ve kesintiler, gelir vergisi, borç ve alacaklar, işçinin kategorisi, fazla mesai süresi ve katmanlı fazla mesai kuralları gibi birçok kaynaktan veri toplanıp hesaplanır. Üretilen bordro kâğıda basılabilir, e-arşive kaydedilebilir, ödeme için finansa gönderilebilir ve üst yönetime "bu ay şu bölümdeki personele şu kadar harcandı, şurada artış var" gibi çıktılar olarak verilebilir. Yani sistem hem işi yapar hem de başka sistemleri besleyecek çıktılar üretir.
- İnsan kaynakları: çalışanların aldığı eğitimler, sertifikalar, tazminat durumu ve kullandığı izin günleri takip edilir.

Üniversiteden bir örnek de verildi: öğrencinin ders planına tabi olması, ders seçmesi, derslere devam etmesi, notlarının girilmesi, harf notlarının hesaplanması, dönem ve genel not ortalamalarının hesaplanması, stajların takibi, ders listelerinin, günlerinin, saatlerinin ve sınıflarının sisteme girilmesi. Bütün bu öğrenci işleri ve ders yönetimi işlerini yürüten sistem (üniversitenin öğrenci bilgi sistemi) bir işlemsel bilgi sistemidir.

İşlemsel bilgi sistemleri girdi-işlem-çıktı düzenini işletir:

- Girdi: veri toplama, veri girişi, verilerin hazırlanması ya da değiştirilmesi; olaylar, işlemler, maddeler.
- İşlem: verileri saklama, geri çağırma, sınıflama, sıralama, güncelleme, üzerinde hesap yapma.
- Çıktı: raporlar, listeler, özetler, sorgu cevapları, başka sistemlere girdi olacak veriler; hatta bir ürün.

**Turnike örneği.** Kartlı turnikede kartın okunması girdidir. Kişinin geçip geçemeyeceğinin kontrolü, kontrol sonrasında turnikenin yeşil ışık yakıp kilidini açması, turnike döndüyse kişinin "içeri girdi" diye işaretlenmesi işlemdir. Böyle bir sistem "şu tarihte sabah 8 ile akşam 17 arasında kaç kişi, nereye girdi" ya da "şu anda içeride kaç kişi var" gibi raporlar üretebilir ve bunlarla bir yönetim bilgi sistemini ya da karar destek sistemini besleyebilir. Bu örnek, işlemsel bilgi sistemlerinin yalnız veri kaydedip geri çağıran sistemler olmadığını, donanım bileşenleriyle de etkileşerek gerçek işlevsellik sağlayabildiğini gösterir.

### 3.2 Ofis otomasyon sistemleri (OAS)

Ofis otomasyon sistemlerinin piramitte tam bir yeri yoktur, çünkü her kademede kullanılabilirler; genellikle pembe (işlemsel) ve yeşil (bilgi) seviyeler arasında gösterilirler. Bilgi seviyesindeki sistemler işlemsel sistemlerin ürettiği çıktılardan yararlanarak çalışır; ancak ofis otomasyon sistemleri için bunun tam olarak geçerli olduğu söylenemez.

Bunlar genellikle Microsoft Office, LibreOffice, OpenOffice gibi paketler halinde bulunur ve gündelik ofis işlerini yürütür. Günümüzde elektronik takvim uygulamaları e-posta ve video konferans araçlarıyla bütünleşik çalışır; ders, toplantı ve proje görüşmeleri takvimde görülebilir. Bu açıdan bakıldığında ofis uygulamaları da farklı bilgi sistemlerinden veri çekiyor olabilir.

Slayttaki büro işlemleri listesi (ekrandan, 00:40:00):

- Kelime işlemciler
- Belge hazırlama, kopyalama, saklama, düzenleme, yazdırma vb.
- Tablolama
- Grafik çizimi
- Elektronik posta
- Faks
- Sunumlar
- Telekonferans

Faks, bir belgenin taranıp telefon hattı üzerinden başka bir cihaza iletilerek orada termal kâğıda basılmasıdır; 90'larda çok yaygındı, günümüzde neredeyse kalmadı. Hoca, uzaktan çalışmanın yaygınlaştığı dönemde ofislerin evlere taşındığını, video konferans uygulamalarının da artık bir ofis otomasyon sistemi sayılabileceğini söyledi: bir şirket toplantısı gibi ofiste yapılan işlerin sanal ortamda bir araya gelerek yapılmasını sağlarlar.

### 3.3 Bilgi tabanlı iş sistemleri

Bilgi tabanlı iş sistemleri (BTİS) de işlemsel bilgi sistemleriyle bir arada çalışır; işlemsel sistemlerin sonuçlarını alır ve bunları işe dönüştürür. Slayttaki maddeler (ekrandan, 00:45:00):

- İnsanların yerini almaz.
- Çalışma ve araştırma sonuçlarını bilgi sistemiyle birleştirir.
- CAD/CAM sistemleri.
- MR sistemleri.

Örnekler:

- Simülasyon: üretim hattındaki veriler alınarak ne kadar hatalı ürün üretileceği tahmin edilebilir. Sistem işlemsel bilgi sistemlerinden veri toplayarak beslenir.
- Bilgisayar destekli tasarım ve üretim (CAD/CAM): siparişlerden hangi parçadan kaç tane üretileceğini alır ve torna gibi tezgâhlarda üretilmesini sağlar.
- MR sistemleri: sistem hasta bilgi sisteminden çekimin vücudun hangi bölgesine (kafa, bacak vb.), hangi açıdan yapılacağı gibi bilgileri alır ve görüntüleme cihazının ayarlarının buna göre yapılmasını sağlar.
- Sanal gerçeklik uygulamaları.

Bu sistemleri "alıp bir şeyleri çalıştıran ya da ürettiren" sistemler olarak düşünmek mümkündür. Bilgi tabanlı iş sistemlerini uzmanlar ve teknik personel kullanır.

### 3.4 Yönetim bilgi sistemleri (MIS)

Piramitte bir üst kademeye (mavi) çıkıldığında yönetim seviyesine, yani birimlerin yönetildiği orta kademeye gelinir. Burada iki tür vardır: yönetim bilgi sistemleri ve karar destek sistemleri. Hoca, bazı üniversitelerde "yönetim bilişim sistemleri" (MIS) adıyla bölümler olduğunu hatırlattı; bilgisayar mühendisliği açısından yönetim bilgi sistemi, bilgi sisteminin belirli bir amaca yönelik bir alt türüdür. Sağladığı hizmet yönetimi beslemek ve işlerin yürütülebilir olmasını sağlamaktır.

Yönetim bilgi sistemleri bütün işlemsel bilgi sistemlerini ve bilgi tabanlı iş sistemlerini kullanabilir; buralardan aldıkları verilerle yönetimin bilgilenmesini sağlarlar. Gösterge panoları (dashboard), grafikler, ibreler, çubuk ve pasta grafikleri, anlık izleme ekranları bu sistemlerin tipik çıktılarıdır. Örnek göstergeler: son bir haftadaki siparişlerin gidişatı, üretimdeki fire miktarının gün ya da saat bazında seyri, toplam kullanılan izin, personelin fazla mesaisi, birim ya da çalışan başına verimlilik oranı. Alttaki verileri süzerek yönetimin istediği rapor ya da gözlemler haline getiren sistemlere yönetim bilgi sistemi denir.

Yönetim bilgi sistemleri farklı boyutlardan incelenebilir:

- İşlem boyutu: yöneticilere rapor, analiz ve (karar destek sistemiyse) karar desteği sağlar. Bunun için alt sistemlerin verilerini ve çıktılarını, veri tabanlarını ve veri ambarlarını kullanır.
- Yönetim boyutu: işlemleri kontrol etmek, kaynakları kontrollü ve dengeli paylaştırmak; üst yönetim bilgi sistemi ise stratejik planlama ve hedef belirleme.
- Yönetim işlevi boyutu: kurumsal açıdan birimler arasındaki bilgilerin bir araya getirilmesi; yönetim katmanı daraldıkça (genel müdüre doğru gidildikçe) bilgi daha çok birleştirilir.

### 3.5 Karar destek sistemleri (DSS) ve uzman sistemler

İşin içine analiz ve tahmin girdiğinde artık yönetim bilgi sisteminden değil karar destek sisteminden söz edilir. Örneğin sistem "bu gidişle stoklar üç ay sonra bitecek, çünkü hammadde gelişi azalıyor ve siparişler artıyor" analizini yaparsa yönetici yeni bir tedarikçi bulma kararı verebilir; sistem bu karara destek olmuş olur. Maliyet, fiyat-kâr, üretim programlama, satış ve stok tahmini gibi konularda çalışan sistemler karar destek sistemidir.

Hoca üniversiteden de bir örnek verdi: öğrenci bilgi sisteminde her dönem hangi dersin açıldığı, kaç öğrencinin aldığı ve hangi ortalamalarla geçtiği bilgisi vardır. Sistem bu verilerden "bu gidişle üç yıl sonra bu dersi alan öğrenci sayısı 200'ü geçecek" diye bir grafik gösterirse yönetim dersi iki yerine üç grup açma kararını verebilir. Benzer şekilde dekanın ya da bölüm başkanının önünde bütün derslerin devam ve başarı durumlarını, öğretim üyelerinin proje ve ödev sayılarını gösteren bir ekran yönetim bilgi sistemidir; aynı sistem "şu derslerde gidişat kötü, böyle devam ederse başarı düşecek" gibi analizler üretiyorsa karar destek sistemi haline gelir. Bir bilgi sistemi bu parçaların birkaçını birden içerebilir, ama alt sistemler yine türlere ayrılabilir.

**Karar destek sistemi ile uzman sistem farkı.** Karar destek sistemi analiz ve simülasyon yapar, ama karar almaz; çıktıları inceleyip kararı veren insandır. Uzman sistemler de karar destek sistemi kategorisinde görülür (slaytta soru işaretiyle gösterilen kısım), ama kararı uygulamaktan da sorumludurlar. Hoca bunu akıllı buzdolabı örneğiyle anlattı: buzdolabı raftaki süt miktarını izler, günlük tüketim hızını ve haftalık dalgalanmayı takip eder, sonra "her çarşamba 1 litre, her cumartesi 2 litre süt sipariş et" gibi bir karar verip siparişi kendisi oluşturur. Bir fabrikada da sistem tedarikçilerin bilgi sistemlerine kendisi sipariş geçiyorsa uzman sistemdir. Sistem yalnız gözlemleyip öneriyor ve kararı insan veriyorsa (insan "bunu yapmak istemiyorum" diyebiliyorsa) karar destek sistemidir.

### 3.6 Üst yönetim bilgi sistemleri (EIS)

Piramidin en üstündeki (turuncu) stratejik seviyede tek bir tür vardır: üst yönetim bilgi sistemleri (Executive Information Systems). Hoca bunu birçok işletmesi ya da birimi olan bir holding yöneticisine benzetti. Sistem altta birçok yerden beslenir ve stratejik seviyede tahmin ve karar almayı sağlayacak çıkarımlar üretir.

Diğer bütün türlerden farklı olarak üst yönetim bilgi sistemleri yalnız kurum içinden beslenmez; dış sistemleri de kullanır: borsa, döviz, haberler, başka sektörlerin veri ve metrikleri. Bunları harmanlayarak beş yıllık satış planlaması ya da "beş ya da on yıl içinde şu dönüşümü yapmalıyız, şunları üretmeli ya da şunlardan vazgeçmeliyiz" gibi stratejik kararları destekleyen çıktılar üretir.

Bu sistemlerde veri madenciliği, OLAP uygulamaları, drill-down analizleri ve günümüzde daha popüler olan tahminleme, makine öğrenmesi ve derin öğrenme teknikleri sıklıkla kullanılır. Böylece işin içine yapay zekâ da katılarak stratejik kararlar desteklenir.

> **Ek bilgi (derste anlatılmadı):** OLAP (Online Analytical Processing), çok boyutlu veri küpleri üzerinde hızlı özet sorgular çalıştırmayı sağlayan analiz yaklaşımıdır. Drill-down, özet bir değerden (örneğin yıllık satış) daha ayrıntılı kırılımlara (çeyrek, ay, bölge) inme işlemidir.

### 3.7 Kim ne alır, kim kullanır

Hoca türleri bir tablo üzerinden özetledi (tablonun slaytı karelerde yok; içerik altyazıdan kuruldu): <!-- BELİRSİZ: Türlerin girdi, işlem, çıktı ve kullanıcılarını özetleyen tablo karelerde görünmüyor; aşağıdaki liste yalnız anlatımdan alındı. -->

- Üst yönetim bilgi sistemleri: içeriden ve dışarıdan beslenir; grafikler, simülasyonlar, etkileşimli analizler ve makine öğrenmesi yöntemleri kullanır; çıktıları görsel sunumlar ya da sorgu cevaplarıdır; kullanıcısı üst yönetimdir.
- Yönetim bilgi sistemleri: analitik uygulamalar ve gösterge panoları; çıktısı raporlar ve sorgu cevaplarıdır; kullanıcısı orta kademe yöneticilerdir.
- Karar destek sistemleri: analiz ve simülasyon yapar; kullanıcıları uzmanlar ve yöneticilerdir.
- Bilgi tabanlı iş sistemleri: kullanıcıları uzmanlar ve teknik personeldir.
- Ofis otomasyon sistemleri: neredeyse herkes kullanır, ama en çok sekreter, muhasebeci ve alt kademe yöneticiler kullanır.
- İşlemsel bilgi sistemleri: kullanıcısı işletim personeli, yani çalışan personeldir; girdileri olaylar, işlemler ve verilerdir; çıktıları rapor, liste, özet, iş ya da başka sistemi tetikleyen verilerdir.

Hoca ayrıca slaytta bazı adların İngilizce bazılarının Türkçe yazıldığını ve karar destek sistemi satırında "decision support" ifadesinin karıştığını belirtti.

Kullanım açısından en çok karşılaşılan sistemler alt kademelerdeki sistemlerdir. Üst kademelerdeki sistemler ise genellikle kuruma özeldir: büyük işletmelerde, kurum içindeki bilgi teknolojileri grupları ya da yazılımcılar tarafından üretilirler. Pazarda hazır çözüm bulmak zordur; dışarıya proje olarak yaptırılabilirler, ama çoğunlukla kurum içinde geliştirilip kullanılırlar.

## 4. Bilgi sistemi türleri arasındaki ilişki

Türlerin birbirini nasıl beslediği bir şema üzerinden anlatıldı. Şemada altı tür için beş halka vardır, çünkü bilgi tabanlı iş sistemleri ve ofis otomasyon sistemleri tek halkada "bilgi sistemleri" olarak birleştirilmiştir. <!-- BELİRSİZ: Etkileşim şemasının slaytı karelerde yok; ok yönleri altyazıdaki anlatımdan kuruldu. -->

- Üst yönetim bilgi sistemi: hiçbir türe çıktı vermez, yalnız üst yönetim kullanır. Alttaki türlerden ve (şemada gösterilmese de) dış kaynaklardan beslenir.
- Yönetim bilgi sistemi: alttaki her şeyden (bilgi tabanlı iş sistemleri, ofis otomasyon sistemleri, işlemsel bilgi sistemleri) veri alır. Üst yönetimi besler; bir bilgi tabanlı iş sistemine ya da bir ofis otomasyon uygulamasına da çıktı üretebilir.
- Karar destek sistemi: orta kademe kullanıcılarına hitap eder. Alttakilerden ve yönetim bilgi sisteminin analitiklerinden, izlenen raporlarından beslenir (üç ok girer); çıktısını üst yönetim bilgi sistemine verir.
- İşlemsel bilgi sistemleri: hoca bunları "çalışan emekçi sistemler" diye niteledi. Herkesi beslerler. Üst yönetimi de dolaylı olarak beslerler, ama bu diğer sistemlerin üzerinden gittiği için şemada üst yönetime doğrudan ok çizilmez.
- Bilgi tabanlı iş sistemleri ve ofis otomasyon sistemleri: üst kademeleri besler, çalışmak için işlemsel bilgi sistemlerinden girdi bekler.

**Türlere neden ayırıyoruz?** Hepsi birer bilgi sistemidir ve hepsi girdi-işlem-çıktı sıralamasıyla çalışır; ama amaçları, hedef kitleleri ve hizmet ettikleri uçlar farklıdır. Bir sistem şunları yapıyorsa işlemsel bilgi sistemi, şöyle çalışıyorsa bilgi tabanlı iş sistemi, çıktısını şunlara veriyor ve şunlardan besleniyorsa yönetim bilgi sistemi denir. Kategorizasyon bu özel halleri adlandırmak içindir.

## 5. Bilgi sistemi tarafları: kullanıcı ve yönetici

Bilgi sisteminin tarafları (paydaşları) altı kategoride incelenir; bazılarının alt dalları vardır (ekrandan, 00:50:00):

- Kullanıcı
- Yönetici
- Sistem analisti
- Sistem tasarımcıları
- Yazılımcı
- Destek personeli

### 5.1 Kullanıcı

Slayttaki maddeler (ekrandan, 01:05:00): sistemin varoluş sebebi, en önemli parça; MÜŞTERİ; sistemden beklentileri TAM belirlenmeli; sistemin nasıl başarıya ulaşacağı tespit edilmeli; teknik değil, işlev ve kullanım önemli.

Kullanıcı (bir başka deyişle müşteri) sistemin varoluş sebebidir. Kullanıcı ya da isteyen yoksa bilgi sistemi de yoktur, sistemin olmasının bir amacı kalmaz. Bu açıdan sistemin en önemli parçasıdır.

Kullanıcı sisteme kapalı kutu (kara kutu) gibi bakar. İçeride hangi programlama dilinin, hangi sürümünün ya da hangi kütüphanelerin kullanıldığıyla genellikle ilgilenmez; onun için önemli olan işlevsellik, kullanım tarzı ve kullanım olanaklarıdır.

Kullanıcıya "isteklerini yerine getirdim, beklentilerini karşılayan sistem budur" diyebilmek için başarı kriterlerinin önceden tespit edilmiş olması gerekir: sistem hangi durumda ya da hangi şartlar altında başarılı, hangi durumda başarısız sayılacak? Ayrıca kullanıcının sistemden beklentilerinin tam olarak belirlenmesi gerekir. Beklentiler baştan kesinleştirilmemişse geliştirme süreci sancılı geçer. İstekler sürekli değişiyor ya da tam anlatılamamışsa analiz ve tasarım modeli düzgün olmaz, sürekli değişir ve kalitesiz bir ürün ortaya çıkar. Bu nedenle kullanıcı, "siz benim için sistemi gerçekleştireceksiniz" dese bile ne beklediğini açıklayabilmeli, sistemin hangi durumda başarılı hangi durumda başarısız olduğunu baştan net olarak ifade edebilmelidir.

### 5.2 Yönetici

İki çeşit yönetici vardır:

- **Üst düzey yönetici:** proje bütçesini finanse eden, sistemin geliştirilmesi için gerekli bütün kaynakları sağlayan taraftır. Sisteme maliyet fayda analizi açısından, yani fiyat performans dengesi açısından bakar: ne kadar para, zaman ve iş gücü harcanıyor, karşılığında ne alınıyor? Sistem verimi mi, kârı mı artıracak, işlem süresini mi kısaltacak, müşteri sayısını mı artıracak; artıracaksa ne kadar? Hoca bunu "attığım taş ürküttüğüm kuşa değecek mi" sorusuyla özetledi.
- **Proje yöneticisi:** sistemi geliştiren takımın içinde ya da başında yer alan kişidir; projenin yürütücüsüdür. Kullanıcının "başarılı" diyebileceği bir ürünün ya da hizmetin geliştirilmesinden birebir sorumludur. Proje ekibinin ya da ekiplerinin sevk ve idaresini yapar: işlerin takibini, her şeyin düzgün yürütülmesini ve istenenlerin yerine getirilmesini sağlar. Proje yöneticisinin gözüyle bir bilgi sisteminde en önemli şeyler işlevsellik ve plana uygunluktur: zaman planına, bütçe planına, nakit akışına ve varsa diğer planlanmış kriterlere uygun ilerlemek.

Özetle iki yönetici türü vardır: patron (üst düzey yönetici) ve proje yöneticisi (ekip lideri).

## 6. Sistem analisti

### 6.1 Analistin rolü

Slayttaki maddeler (ekrandan, 01:10:00):

- Dersimizin odak noktası
- Projelerin kilit üyesi
- Hem işletme yönetimi, hem bilgi sistemi bilgisi olmalı
- İşletmenin sorunları, ihtiyaçları, iş akışlarını belirlemeli
- Bilgi sistemi ile çözümünü sağlatmalı, uygulamaya karar vermeli
- Problemi görüp anlamalı, çözüm için bilgi sistemini metodolojiye uygun olarak oluşturmalı

Ders "sistem analizi ve tasarımı" olduğuna göre sistem analisti dersin odak noktasıdır; hem bütün bilgi sistemi projelerinin hem de ders kapsamındaki projenin kilit üyesidir. Hoca, bu işin sıklıkla farklı mühendislik dallarından (örneğin matematik mühendisliği, bazen elektronik mühendisliği) gelenlerce yapıldığını, bilgisayar mühendislerinin ise sistem analistliğini biraz hafife aldığını söyledi. Oysa yönetici tarafına yükselmesi en olası rollerden biri sistem analistliğidir.

> **Hocanın vurgusu:** Sistem analisti aslında bir tercümandır. Terazinin bir kefesinde iş tarafı (müşteri, kullanıcı), diğer kefesinde teknik ekip (analistler, tasarımcılar, yazılımcılar, test ekibi, hatta bir yere kadar destek personeli) vardır. Analist bu iki grup arasında dil, konuşma ve işlev dönüşümünü yapar; bu yüzden iki tarafın dilini de bilmelidir.

Bu nedenle analist hem işletme yönetimini, işin nasıl yapıldığını bilmeli (bilmiyorsa öğrenebilecek açık görüşlülükte olmalı), hem de işin teknik dilini, teknolojileri, hangi ortamda hangi çözümün daha doğru olacağını bilmelidir.

Kullanıcı işlevselliği belirlemelidir, ama her zaman bunu kendi başına söyleyemez. Analist ihtiyaçların ortaya çıkarılmasında bir katalizör gibi çalışır, bu işi hızlandırır ve kolaylaştırır. İş akışlarını da belirleyebilmelidir; iş akışı bütün bilgi sistemlerindeki akışların temelini oluşturur, çünkü gerçek hayatta iş nasıl işliyorsa bilgisayar ortamında da öyle işlemesi beklenir (bilgisayar ortamında daha hızlı, daha kaliteli, daha doğru olarak). İşi, iş akışını, ihtiyaçları ve sorunları anlayan analist bunları süzüp bir bilgi sistemi çözümüne dönüştürür ve teknik ekibin anlayacağı dile çevirir: "bu iş aslında şu demek; şu kayıtları oluşturmamız, şu şekilde güncellememiz gerekiyor" gibi.

Hoca, bilgisayar mühendislerinin kütüphanelerle, API'lerle, algoritmalarla uğraşmayı daha zevkli bulduğunu, ama bunların çalışabilmesi için önce işin anlaşılması, aktarılması ve problemin kavranması gerektiğini; sistem analistinin bu anlama ve dönüştürme işinden sorumlu olduğunu vurguladı.

### 6.2 Bir analistin problem çözümü

Slayttaki akış (ekrandan, 01:15:00):

```text
Problemi araştırmak ve anlamak
  -> Çözümün maliyetine karşılık faydaları belirlemek
  -> Çözümün ihtiyaçlarını belirlemek
  -> Alternatif çözümleri belirlemek
  -> En iyi çözümü belirlemek
  -> Seçilen çözümün ayrıntılarını belirlemek
  -> Çözümü uygulamak
  -> İstenilen sonuçların elde edildiğinden emin olmak için izlemek
```

Hoca bu akışta çok özel bir şey olmadığını söyledi. Analist problemi araştırıp anlamalı; çözüm için temel bir maliyet fayda analizi yapabilmeli (çok ayrıntılı olması gerekmez); gereksinimleri belirleyebilmeli; "ben bunu böyle çözerim, ama alternatifleri şunlardır" diyebilmeli; bu alternatifleri ortam, bütçe ve zaman gibi kısıtlara göre değerlendirip en iyisini seçebilmeli; seçilen çözümün ayrıntılarını oluşturup uygulayabilmeli ve sonuçların istekleri karşılayıp karşılamadığını, kurduğu modelin probleme uygun olup olmadığını izleyebilmelidir.

### 6.3 Analistin beceri ve görevleri

Slayttaki maddeler (ekrandan, 01:20:00):

- Analitik düşünme bilgi ve becerisi
  - Problemi belirleyip tanımlayabilmeli
  - Sistemin parçalarını inceleyip ilişkileri ortaya koyabilmeli
  - Çözüm alternatifleri sunup değerlendirebilmeli
- Teknik bilgi ve beceri
  - Donanım, programlama dilleri, işletim sistemleri, VTYS, haberleşme protokolleri gibi konularda temelleri bilmeli
  - Farklı teknolojilerin kullanım amaçlarını, nasıl kullanıldığını, nasıl entegre edilebileceklerini bilmeli
  - Bilgi sistemi geliştirme sürecinin tamamı hakkında bilgi sahibi olmalı

Analitik düşünme mühendislik formasyonuyla ilgilidir: problemi doğru tanımlamak, sistemi parçalara ayırmak (hangi modüller, hangi hizmetler olmalı, aralarındaki ilişkiler neler) ve alternatif çözümler üretmek. Teknik bilgi olmadan çözüm önerilemez; bu yüzden analistin donanım, programlama ortamları, işletim sistemleri, veri tabanları (günümüzde büyük veri tabanları dahil) ve haberleşme protokollerinin temellerini bilmesi, modern teknolojileri takip etmesi, hibrit çözümlerdeki entegrasyonların nasıl yapılacağını bilmesi beklenir. Bilmediğini araştırarak öğrenebilmelidir.

Anlatımda bunlara iki beceri grubu daha eklendi: <!-- BELİRSİZ: Aşağıdaki iki grubun yer aldığı slayt karelerde yok; maddeler altyazıdan alındı. -->

- **Yönetim ve iş bilgisi:** analist iş birimleriyle ve müşteriyle görüştüğü için işlerin nasıl yürüdüğünü, organizasyon yapısını, kimin hangi rolü olduğunu anlayabilmeli; kurumun hedeflerini, sektörünü ve değerlerini bilmeli ya da bulabilmelidir. Kaynak, proje ve risk yönetimi ile değişim ve konfigürasyon yönetimi konusunda bilgisi olmalıdır.
- **İnsan ilişkileri ve iletişim:** müşteriyle onun dilinden konuşabilmeli, işi nasıl yaptığını gözlemleyerek ortaya koyabilmeli; iş tarafındaki çalışanların becerileri ve kullandıkları teknolojiler hakkında fikir sahibi olmalı; rahat iletişim kurabilmeli, dinlemeyi bilmeli, sorunları anlayıp aktarabilmeli. Bunların hepsini belgeleyip raporlayabilmeli ve projenin diğer paydaşlarıyla paylaşabilmelidir.

Hoca bu listeye bakınca böyle her şeyi bilen birinin bulunmasının zor olduğunu, bunun neredeyse "full stack" bir profile benzediğini esprili bir dille söyledi.

### 6.4 İş analisti ve sistem analisti

Sistem analistliği tek bir kişiden oluşmak zorunda değildir; günümüzde bu rol ikiye bölünmüştür:

- **İş analisti:** iş tarafını daha iyi anlayan ya da iş tarafına yakın olan roldür. İşin anlaşılması, problemin öğrenilmesi ve bunun formal biçimde belgelenmesinden sorumludur. Bu işte farklı disiplinlerden kişiler çalışabilir.
- **Sistem analisti:** iş analistinin ürettiği çıktıları kullanarak daha teknik analizler yapar ve analiz modelini oluşturur; örneğin kavramsal bir nesne modeli kurar. Ders kapsamında da basit örneklerle bu işin nasıl yapıldığı öğrenilecektir.

Projenin boyutuna ve işin karmaşıklığına göre bu iki rol ayrı kişilerde olabileceği gibi tek bir analist rolünde de birleşebilir. <!-- BELİRSİZ: 01:20:42-01:21:22 arasında kayıtta bağlantı kesintisi var; rolün ikiye bölünmesinin ilk anlatımı altyazıda eksik; sistem analistinin hangi olanakları kullandığını anlatan cümle de (01:23:09) bozuk. -->

## 7. Sistem tasarımcıları ve yazılım mimarı

### 7.1 Tasarımcılar

Dördüncü taraf sistem tasarımcılarıdır; sistem tasarımı tarafında çalışan bütün rolleri kapsar. Slayttaki liste (ekrandan, 01:25:00):

- **Veritabanı yöneticileri:** verilerin saklandığı ortamların nasıl olması gerektiğini kurgular, yapılarını tasarlar ve işlevsel kalmaları için yönetir. Hoca, verinin boyutu, hızı, üzerinde yapılan işlemlerin ve sorguların doğası değiştiği için ilişkisel veri tabanlarının yanında NoSQL veri tabanlarının yaygınlaştığını ve bu rolün büyük veri tarafına da kaydığını söyledi.
- **Ağ mimarları:** bilgi sisteminin iletişim altyapısını tasarlar: bant genişliği, bağlantı türü gibi.
- **Web mimarları:** web arayüzünün nasıl olması gerektiğini (UI, UX tarafı) tasarlar.
- **Grafik sanatçıları:** butonlar, temalar, arka plan rengi, yazılar, sayfa geçiş efektleri gibi görsel tasarımları yapar.
- **Güvenlik uzmanları:** erişim güvenliği, modül güvenliği, yetkilendirme, bunların takibi, raporlanması, kayıt altına alınması ve gerektiğinde müdahale edilmesiyle ilgili tasarımları yapar. Hoca bilişim sistemleri güvenliğinin artık başlı başına bir alan olduğunu belirtti.
- **Teknolojik uzmanlar:** projeye özel teknolojilerle ilgili tasarımları yapar; örneğin termal yazıcı entegrasyonu ya da stok deposunda ışıklarla yönlendirilen bir robot kolunun entegrasyonu.

### 7.2 Yazılım mimarı

Altı başlığın hiçbirinde yazılımın kendisinden söz edilmediğini hatırlatan hoca, sistem tasarımcıları arasında bir de yazılım mimarı (Software Architect) rolü olduğunu söyledi. Slayttaki maddeler (ekrandan, 01:30:00):

- Gereksinimleri belirlenmiş sistemin bilişim modelini kurgular
- Yazılım mimarilerine hâkim olmalı
- Ağ ve donanım kaynaklarını iyi bilmeli
- Veri yönetimi konusunda deneyimli olmalı

Analiz tamamlanıp analiz modeli oluştuğunda ve gereksinimler ortaya çıktığında, yazılım mimarı bu gereksinimler altında diğer tasarımcıların yapacağı işleri de göz önüne alarak bilgi sisteminin bütün bilişim modelini kurgular. Yazılım mühendisliğinde ortaya konmuş çeşitli mimariler vardır; yazılım mimarı bunlara hâkim olmalı, gereksinimleri bir mimari içinde çalışacak hale dönüştürmeli ve yazılım altyapısıyla ilgili kararları vermelidir.

**MVC örneği.** MVC çok standart, belki farkında olmadan kullanılan bir mimaridir. Bu mimaride görünüm, görünümün kontrolü, iş katmanı ve veri birbirinden ayrılır; amaç her birini diğerlerinden bağımsız değiştirebilmektir. Hoca örneği üniversite üzerinden kurdu:

- Lisans öğrencilerine ve yüksek lisans öğrencilerine yönelik hizmetlerin iş modelleri farklıdır. Lisansta dört yıllık kredi, staj ve not ortalaması yükümlülükleri; yüksek lisansta tez, seminer ve sunum gibi yükümlülükler takip edilir. Bu yüzden iş katmanları ayrı olmalı ve yanlarına yenileri eklenebilmelidir.
- Yarın değişim (Erasmus) öğrencileri için ayrı süreçlerle çalışan yeni bir hizmet gerekirse yeni bir iş katmanı oluşturulur; arka plandaki veri katmanı aynı kalır.
- Ön yüzler de farklı olabilir: lisans için yalnız web, yüksek lisans için yalnız kiosk, değişim öğrencileri için yalnız mobil. Mobil ön yüz yalnız kendi iş katmanıyla, o iş katmanı da veriyle konuşur.
- Sonradan değişim öğrencileri için bir web arayüzü de istenirse mevcut mobil arayüze dokunmadan yanına bir web arayüzü eklenir; iki arayüz aynı iş modeliyle ayrı kanallardan konuşur.

Böylece ön yüz, iş modeli (süreçler) ve veriler birbirinden ayrı tutulmuş olur. Bu ayrımı yapan, modüllerin nasıl ayrışacağına, hangi veriyle nasıl haberleşileceğine, ön yüzlerin ne olacağına karar veren kişi yazılım mimarıdır.

> **Ek bilgi (derste anlatılmadı):** MVC, Model-View-Controller'ın kısaltmasıdır. Model veri ve iş mantığını, View kullanıcıya gösterilen arayüzü, Controller ise kullanıcı isteklerini alıp modeli ve görünümü yöneten katmanı ifade eder.

**Servis tabanlı mimari ve mikroservisler.** İş katmanı servis tabanlı bir yapıya da dönüştürülebilir: öğrenci bilgilerini sorgulayan bir servis, notları hesaplayan başka bir servis, dersleri sorgulayan bir servis, ders seçimi için ayrı bir servis. Bu servislerin daha atomik hallerine mikroservis denir. Ancak parçalara bölmek yeni problemler doğurur: servisler nasıl yönetilecek, nasıl birleştirilecek, hangi sırayla işletilecek, verileri ne olacak, biri veriyi yazarken diğeri bozarsa ne olacak? Yazılım mimarı bu problemler için yöntem geliştirmelidir; iş yalnız bilinen bir kalıbı uygulamaktan ibaret değildir.

**Ağ ve donanım bilgisi neden gerekir?** Ders seçimi modülü belirli bir sürede (örneğin bir dakikada on binden fazla istek geldiğinde) çökebilir. Bu modül mikroservis olarak ve çoğaltılabilir konteynerler halinde modellenirse, ders seçimi başlamadan önce normal yükü karşılayan sayının on katı kopya ayağa kaldırılabilir. Her kopya 5000 kişiye hizmet verebiliyorsa:

$$10 \times 5000 = 50000$$

istek karşılanabilir. Ama bunun için ağ tarafının da yapılandırılabilmesi ve donanımın sınırlarının bilinmesi gerekir.

**Veri yönetimi neden gerekir?** Kopyalar mimarinin doğası gereği birbirinden habersiz çalışır. Kontenjanı 30 olan bir ders için 50 kopyanın her birine birer istek gelirse ve her kopya isteği onaylarsa 50 öğrenciye ders seçtirilmiş olur; kontenjan $50 - 30 = 20$ kişi aşılır. Bu tür kısıtların nasıl denetleneceği, bunun için hangi mekanizmaların gerektiği ve servislerin nasıl tanımlanacağı da yazılım mimarının sorumluluğundadır. Hoca, yazılım mimarlığının bilgisayar mühendisleri için çekici bir kariyer yolu olduğunu da ekledi.

## 8. Yazılımcılar ve destek personeli

### 8.1 Yazılımcı

Slayttaki maddeler (ekrandan, 01:40:00):

- Sistemi yazanlar
- İş süreçleri ve problem gereksinimlerini bilgisayar diline çevirir
- Analist (tasarımcı) girdilerini kullanır
- Sistemin çalışan halini üretir
- CASE araçları ile kod üretimi kolaylaştı
- Kod optimizasyonu ve entegrasyon önemli
- Sistem programcıları
- Veritabanı programcıları
- Test personeli

Yazılım geliştiriciler sistemi kodlayan, gerçekleyen kişilerdir. Süreçleri, problem gereksinimlerini, analiz ve tasarımın ürettiklerini kullanarak sistemin çalışan halini ortaya koyarlar; bunu yazılım mimarının tasarımına uygun yapmaları gerekir, bu yüzden mimariler hakkında fikir sahibi olmalıdırlar. Yazılım geliştirdikçe mimarilere hâkim olan bir geliştirici mimari tarafa geçebilir; yazılım mimarları çoğunlukla yazılım geliştire geliştire bu role gelir.

Günümüzde CASE (Computer Aided Software Engineering) araçları ve IDE'ler (Integrated Development Environment, tümleşik geliştirme ortamları) kod üretimini kolaylaştırdı; iskeleti (framework) çıkaran araçlar sayesinde geliştirici yalnız metotları doldurur ve algoritmaları gerçekler. Bu sayede kod kalitesi de arttı. Bir yazılım geliştirici için en önemli konular kod optimizasyonu (karmaşıklığın düşük, performansın yüksek olması) ve entegrasyon, yani birlikte çalışabilirliktir.

Yazılımcılar başlığı altında üç alt rol daha vardır:

- **Sistem programcıları:** işletim sistemi ile bilgi sistemi arasında, bilgi sisteminin çalışabilmesini sağlayan ara uygulamaları yönetir. Örneğin Java ile yazılmış, web arayüzüyle çalışan bir öğrenci bilgi sistemi Tomcat gibi bir uygulama sunucusu üzerinde koşar. Bu sunucuyu kuran, istenen girdi ve çıktıları sağlayacak şekilde yapılandıran, gerekirse özel kodlama ve değişiklikleri yapan kişi sistem programcısıdır.
- **Veritabanı programcıları:** veri üzerindeki bazı işlemler doğrudan veri tabanında çözülebilir. Bu, eskiden kullanılan ve günümüzde pek tercih edilmeyen veri güdümlü (data-driven) bir tasarım yaklaşımıydı. Yine de saklı yordamlar (stored procedure) ve fonksiyonlarla işlem yapmak gerekebilir. Bu işlemleri yazan, tabloları, tetikleyicileri (trigger) ve indeksleri gerçekleyen kişiler veritabanı programcısıdır.
- **Test personeli (test mühendisi):** herkes kendi yazdığı kodu (birim testleriyle) test eder, ama test personeli birimlerden modüllere, modüllerden daha büyük yapılara, servislerden servis gruplarına kadar bütün parçaların gereksinimleri karşılayıp karşılamadığını ve başka yönlerden doğruluğunu test eder. Test personeli farklı disiplinlerden de gelebilir. Günümüzde test otomasyonu önemli bir konudur; ama otomasyon araçları her şeyi yapamadığı için test personeline yine ihtiyaç vardır.

### 8.2 Destek personeli

Altıncı taraf destek personelidir. Geliştirilmiş ve devreye alınmış bir bilgi sisteminin hayatı boyunca çalışır halde kalmasını ve sürekliliğini sağlarlar:

- Ağın düzgün çalışmasını ve iletişimin sağlanmasını; arıza varsa giderilmesini, giderilemiyorsa (geliştirme gerekiyorsa) geliştirme ekibine geri bildirim verilmesini sağlarlar.
- Sunucuların ve diğer donanımların ayakta kalmasını ve işlemesini sağlarlar.
- Yazılımın ve parametrelerin doğru ayarlanmasını sağlarlar.
- Sistem yeni bir müşteriye kurulurken kurulumu, devreye almayı ve yapılandırmayı yaparlar; çıktıları düzenleyebilirler.
- Kullanıcı desteği verirler: "bunu nasıl yapacağım, nasıl çözeceğim" sorularını yanıtlayan çağrı merkezi benzeri birimler de destek personelidir.
- Güvenliği izler, gerektiğinde önlem alırlar.
- Dış sistemlerle entegrasyon için gereken işleri yaparlar.

Kısacası destek personeli sistemi hayatta ve işlevsel tutar; kullanıcılara bilgi ve eğitim verir, bir sorun olduğunda danışılan kişilerdir.

**Tarafları neden kategorize ediyoruz?** Her tarafın görevleri, yetkileri, sorumlulukları, yapması ve bilmesi gerekenler birbirinden farklıdır. Bu yüzden paydaşlar roller halinde ayrılır: kullanıcı kimdir, yönetici türleri nelerdir, sistem analisti nasıl bölünür, tasarımcı denince hangi alt roller vardır, yazılım geliştirme ve destek altında neler vardır.

## 9. Bilgi sistemi geliştirme süreci

Bu konu derste yalnız genel hatlarıyla başlatıldı, devamı sonraki derse kaldı.

Bir bilgi sisteminin geliştirilmesi için atılması gereken adımlar, bu adımların hangi sırayla yapılacağı ve bunun için önerilen süreç ve metodolojiye (yol, yöntem) bilgi sistemi geliştirme süreci denir. Bu tanım yalnız bilgi sistemleri için değil, ürün çıkarılan bütün proje süreçleri için de kullanılabilir.

Bütün süreç modelleri temel adımları bir şekilde evirip çevirir: bazılarını birleştirir, bazılarını dışarıda tutar ya da döngü halinde tekrar tekrar yapar. Ama sonunda her süreçte bu adımlardan geçilir. Slayttaki tablo (ekrandan, 01:50:00):

| Adım | İşlem | Çıktılar |
|---|---|---|
| Problemin tanımı | Problemi ortaya koymak | İhtiyaçlar belirlenir |
| Fizibilite çalışması | Projenin kapsamı ve hedefleri ortaya konarak olabilirliğini belirlemek | Fizibilite çalışması raporu |
| Analiz | Problemin çözümlerini ortaya koymak | Çözümün lojik modeli |
| Genel tasarım | Sistemin nasıl gerçekleştirileceğini belirleme | Sistemin maliyeti ve üst düzey dizaynı |
| Ayrıntılı tasarım | Genel tasarımda belirlenen sisteme ait alt sistemlerin tanımlanması | Sistemin özellikleri ve ayrıntılı tasarım |
| Gerçekleştirme | Programı yazma, yükleme ve test | Çalışan sistem ve dokümantasyon |
| Bakım | Sistemin bakımını yaparak desteklemek | Çalışan sistem |

Adımların anlatımı:

- **Problemin tanımı:** problemi anlamak, ortaya koymak ve ihtiyaçları belirlemek; ayrıca "bu işi yapalım mı, yapmayalım mı" kararını vermek.
- **Fizibilite çalışması:** iş yapılabilir mi, yapılması için neler gerekir, hangi alternatiflerle gerçekleştirilebilir, hangi şartlar altında hangisi daha iyidir sorularını yanıtlamak. Çıktısı fizibilite çalışması raporudur.
- **Analiz:** problem uzayını ve problemin çözümünü ortaya koymak. Çıktısı çözümün lojik modelidir.
- **Tasarım:** çözümün nasıl gerçekleştirileceğini ve nasıl çalışacağının ayrıntılarını belirlemek. Çıktısı tasarım modelidir; genel ve ayrıntılı tasarım olarak iki seviyede yapılır.
- **Gerçekleştirme:** programların yazılması. Yalnız tek bir dilde modül yazmak değil, sistem, veri tabanı, servisler ve entegrasyonlar gibi farklı ortamlarda kod yazıp bir araya getirmek gerekir. Yükleme ve testler de bu aşamada yapılır. Çıktısı çalışan sistem ve dokümantasyondur.
- **Bakım:** sistem bakım yapılarak sürekli desteklenir; çıktı yaşayan, çalışan bir sistemdir.

### 9.1 Sistem geliştirme yaşam döngüsü

Aynı adımlar bir yaşam döngüsü olarak da okunabilir: <!-- BELİRSİZ: Yaşam döngüsü şemasının slaytı karelerde yok; adım adları altyazıdan alındı. -->

```text
Kapsam ve planlama (problem tanımı, fizibilite)
  -> Gereksinim analizi
  -> Tasarım
  -> Gerçekleştirme ve test
  -> Kurulum ve dağıtım (devreye alma)
  -> Operasyon (işletme) ve bakım
  -> (yeni ihtiyaçlar) -> Kapsam ve planlama ...
```

İki gösterimde isimler biraz farklıdır (birinde fizibilite, analiz, tasarım; diğerinde kapsam, planlama, kurulum, dağıtım), ama adımlar özünde aynıdır. Operasyon ve bakım sırasında gelen bilgiler yeni kapsam, yeni plan ve yeni değişiklikler olarak döngünün başına döner; bunların analizi, tasarımı, gerçekleştirmesi ve dağıtımı yapılır.

> **Hocanın vurgusu:** Sistem geliştirme yaşam döngüsü bir sonsuz döngü şeklinde devam eder. Süreç düzgün işletiliyorsa döngü ancak operasyon ve bakımdan sonra sistem kullanımdan kaldırıldığında biter.

### 9.2 Süreç modellerine bakış

Derste son olarak süreç modellerinin listesi ekranda gösterildi (ekrandan, 01:55:00); ayrıntıları sonraki derste işlenecektir:

- Klasik süreç (Waterfall)
- Model oluşturma
- Evrimsel süreçler
  - Artımlı model
  - Spiral model
- RUP modeli
- Aykırı programlama
- Çevik süreçler

Hoca bu modellerin ayrıntılı anlatımının birkaç hafta süreceğini, bu derste yalnız farkındalık amacıyla ele alınacağını, ayrıntılarının yazılım mühendisliği dersinde öğrenileceğini söyledi. Sonraki adım ön inceleme ve fizibilite çalışmalarıdır.

> **Ek bilgi (derste anlatılmadı):** "Aykırı programlama" İngilizce Extreme Programming (XP) yönteminin Türkçe karşılığı olarak kullanılır; RUP ise Rational Unified Process'in kısaltmasıdır.

## 10. Örnek Sorular

**Soru 1** (derste sözlü, 00:49:33): Bilgi sistemlerini neden türlere ayırıyoruz?

> **Cevap (derste verildi):** Hepsi girdi-işlem-çıktı sıralamasıyla çalışan bilgi sistemleridir, ama amaçları, beslendikleri kaynaklar, çıktılarını verdikleri yerler ve hedef kitleleri birbirinden farklıdır. Türlere ayırmak bu özel halleri adlandırmayı sağlar: bir sistem gündelik işleri yürütüyorsa işlemsel bilgi sistemi, alttaki verileri süzerek yönetimin izlemesini sağlıyorsa yönetim bilgi sistemi, analizle karara destek oluyorsa karar destek sistemi denir.

**Soru 2** (derste sözlü, 01:20:32): Sistem analizi rolü tek bir kişiden mi oluşur?

> **Cevap (derste verildi):** Hayır. Böyle her şeyi bilen biri zor bulunduğu için günümüzde rol ikiye bölünmüştür: iş tarafına yakın, işi ve problemi anlayıp formal olarak belgeleyen iş analisti ve bu çıktıları kullanarak teknik analiz modelini (örneğin kavramsal nesne modelini) kuran sistem analisti. Projenin boyutuna ve karmaşıklığına göre iki rol tek kişide de birleşebilir.

**Soru 3** (derste sözlü, 01:27:47): Yazılım mimarı nedir, ne yapar?

> **Cevap (derste verildi):** Gereksinimleri belirlenmiş sistemin bütün bilişim modelini, diğer tasarımcıların işlerini de göz önüne alarak kurgulayan sistem tasarımcısıdır. Bilinen yazılım mimarilerine (örneğin MVC, servis tabanlı mimari, mikroservisler) hâkim olmalı, gereksinimleri bir mimari içinde çalışacak hale getirmeli, parçalara bölmenin doğurduğu yönetim, ölçeklenme ve veri tutarlılığı problemlerini çözmeli; bunun için ağ, donanım ve veri yönetimi bilgisine sahip olmalıdır.

**Soru 4** (derste sözlü, 01:37:13): Ders seçimi mikroservisinin birbirinden habersiz çalışan 50 kopyasına, kontenjanı 30 olan bir ders için aynı anda birer istek gelirse ve her kopya isteği onaylarsa ne olur?

> **Cevap (derste verildi):** 50 öğrenciye ders seçtirilmiş olur ve kontenjan $50 - 30 = 20$ kişi aşılır. Bu, veri yönetiminde kısıtların aşılması problemidir; yazılım mimarı bu tür kısıtları denetleyecek mekanizmaları ve servis tanımlarını tasarlamalıdır.

## Dersin Toparlaması

Bu derste bilgi sistemleri dört seviyeli bir piramit üzerinde altı türe ayrıldı: işlemsel seviyede işlemsel bilgi sistemleri; bilgi seviyesinde bilgi tabanlı iş sistemleri ve ofis otomasyon sistemleri; yönetim seviyesinde yönetim bilgi sistemleri ve karar destek sistemleri (uzman sistemler dahil); stratejik seviyede üst yönetim bilgi sistemleri. Türlerin birbirini nasıl beslediği gösterildi: işlemsel sistemler herkesi besler, üst yönetim bilgi sistemi ise iç ve dış kaynaklardan yalnız beslenir. Ardından bir bilgi sisteminin altı tarafı (kullanıcı, yönetici, sistem analisti, sistem tasarımcıları, yazılımcı, destek personeli) görevleri, bakış açıları ve gereken becerileriyle incelendi; özellikle iş ve teknik taraf arasında tercüman olan sistem analisti ile mimari kararları veren yazılım mimarı üzerinde duruldu.

Son olarak bilgi sistemi geliştirme sürecinin temel adımları (problem tanımı, fizibilite, analiz, genel ve ayrıntılı tasarım, gerçekleştirme, bakım) ve bunların sonsuz bir yaşam döngüsü olarak işleyişi tanıtıldı. Sonraki derste klasik süreç (waterfall) ve alternatif süreç modelleri ele alınacak, ardından ön inceleme ve fizibilite çalışmalarına geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
