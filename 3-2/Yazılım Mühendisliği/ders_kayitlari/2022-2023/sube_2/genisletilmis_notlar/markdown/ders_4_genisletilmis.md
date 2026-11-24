# Ders 4 Genişletilmiş Notu: Süreç Sertifikasyonu (CMMI), Gereksinim Mühendisliği ve Kullanım Öyküleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Süreç Sertifikasyonu
- 2. PMI, ISO ve Sertifikaların Sürdürülmesi
- 3. CMMI Düzeyleri
- 4. CMMI İlgi Alanları, Tarihçe ve Çevik Süreçler
- 5. CMMI ve CASE Araçları
- 6. Gereksinim Mühendisliğine Giriş
- 7. Gereksinim Mühendisliğinin Adımları
- 8. İzlenebilirlik Tabloları
- 9. Nesneye Yönelik Çözümleme Süreci ve Uygulama Alanının Çözümlenmesi
- 10. Gereksinimler Belgesi ve Kullanım Öyküleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Süreç Sertifikasyonu

Ders, bir önceki haftada konuşulan yazılım geliştirme süreçlerinin devamı olarak süreç sertifikasyonu ile başlar. Önceki derste doğru tanımlanmış bir çalışma biçimiyle üretilen yazılımda hem projenin başarılı olma şansının hem de ürünün kalitesinin arttığı konuşulmuştu. Buradan çıkan soru şudur: Bir yazılım evi olgun bir süreç yürüttüğünü nasıl kanıtlar? Yanıt, süreçlerinin yeterliliğini bağımsız kuruluşlara onaylatmaktır.

Slayttaki ilkeler şunlardır (ekrandan, 00:15:00):

- Olgunlaşmış bir yazılım geliştirme sürecine sahip olmayan bir yazılım firması, projelerini başarı ile sonuçlandıramaz.
- Bir yazılım firması, süreçlerinin yeterliliğini bağımsız kurumlara onaylatmayı seçebilir.
- Gerekli olduğu durumlar: bazı büyük müşteriler sertifikalı yazılım firmaları ile çalışmayı şart koşarlar.
- Gereksiz olduğu durumlar: çok küçük şirketler ve/veya projeler için ek yük olarak görülebilir.

### 1.1 Ne Zaman Gerekir?

Büyük müşterilerle çalışmak isteniyorsa sertifikasyon gereklidir. Bu müşteriler genelde bakanlıklar, silahlı kuvvetler gibi büyük devlet kurumları (kendi ülkenizde ya da başka ülkelerde) ya da çok büyük kurumsal firmalardır. Bu tür müşteriler çoğu zaman belirli bir sertifikasyon yönteminde belirli bir düzeyin üstünde derecelendirilmiş yazılım evleriyle çalışmayı açıkça şart koşar.

### 1.2 Ne Zaman Gereksizdir?

Sertifikasyon bir maliyettir. Hoca bu maliyetin araç gereçle değil, insan kaynağıyla ilgili olduğunu vurgular: yazılım projesi için gereken yazılım ve donanım zaten kullanılmaktadır, ek yük süreçleri oluşturmak ve belgelemek için harcanan zaman ve emektir. Küçük bir şirket bu yükü kaldıramayabilir.

Büyük bir kurum da olsanız, çok kısa sürede tamamlanacak küçük bir proje için bu ağırlıkta süreçleri işletmek istemeyebilirsiniz. Hoca bunu bir oranla anlatır: proje maliyeti 100 bin lira iken sertifikasyon etkinliklerinin sabit bir başlangıç maliyeti 40-50 bin liraya çıkıyorsa, yani projenin üçte biri ya da yarısı kadar ek maliyet getiriyorsa, "atılan taş ürkütülen kurbağaya değmeyecektir".

### 1.3 Güncel Model ve Standartlar

Slayttaki liste (ekrandan, 00:15:00):

- CMMI: Capability Maturity Model Integration. SEI (Software Engineering Institute of Carnegie-Mellon University) tarafından önerilmiştir. Kurumsal düzeyde alınır.
- PMI: Genel amaçlı bir proje yönetimi yaklaşımı. Bireysel ve kurumsal düzeyde alınabilir.
- ISO 9001:2015 standartları: Genel, kurumsal.
  - ISO/IEC 90003:2018: Yazılım geliştirmeye özel, kurumsal.
  - Ulusal belgelendirici firma: Denetik (ulusal otorite: TÜRKAK, kamu).
- Genel vs. Özel (Peynir mi üretiyoruz?)

Sertifikasyon için "sertifika almak" ve "akredite olmak" ifadeleri birbirinin yerine kullanılabilir. Hoca, üniversite bölümlerinin eğitim programları için MÜDEK akreditasyonu aldığını, orada "akreditasyon" sözcüğünün tercih edildiğini örnek verir.

## 2. PMI, ISO ve Sertifikaların Sürdürülmesi

### 2.1 PMI

PMI (Project Management Institute) Amerika kökenli ama küresel bir kuruluştur. Yaklaşımı genel amaçlı bir proje yönetimi standardıdır; mühendislik projeleri, yazılım projeleri gibi alt alanları vardır ama hepsi üst çatıdaki ana PMI süreçlerinin özelleştirilmesidir. Yaklaşım bir bilgi birikimi kitabında (Body of Knowledge) anlatılır.

PMI sertifikası bireysel ya da kurumsal düzeyde alınabilir. Bireysel olarak kitap edinilip iyice çalışılır ve sertifika sınavına girilir; kurumsal olarak PMI'nin yetkilendirdiği bir denetçiye başvurulur ve denetimden geçilir. Sınav ve değerlendirme ücretlidir; hakemlerin gelip yapılan işi incelemesi ciddi bir emektir.

Sertifika alındıktan sonra boş durulamaz. Bireysel sertifika sahibi aktif olarak çalışmayı sürdürmeli ve bunu belgelemelidir. PMI'nin düzenlediği etkinliklere, kurslara (çevrim içi ya da yüz yüze) pasif katılım belli bir puan, aktif katılım (seminer vermek, konuşmacı olmak) daha fazla puan getirir. Bu puan tabanlı sistemde puanlar biriktirilmezse sertifika iptal edilir.

CMMI'da ise akreditasyon alındıktan sonra belirli yıllarda (kurallara göre 3, 4, 5 yıl gibi) yeniden değerlendirmeden geçilir; şartlar sağlanıyorsa akreditasyon yenilenir.

> **Ders sonrası not:** Hoca kitabı "Body of Knowledge ya da Book of Knowledge" diye andı; PMI'nin kitabının adı büyük olasılıkla "A Guide to the Project Management Body of Knowledge (PMBOK Guide)" olarak geçer.

### 2.2 ISO

ISO'nun genelden özele çeşitli standartları vardır. ISO 9001 genel ve kurumsal düzeyli bir kalite yönetim standardıdır; son revizyonu 2015'tedir. Bir kalite yönetim sistemi kurulup düzenlenmiş olmalıdır. Herkes başvurabilir: bir üniversite, bir tekstil firması, bir lokanta ya da bir market. Standart bazı etkinlikleri ve bunların temel kurallarını dikte eder; bu kurallara uyulduğu sürece süreçler istenildiği gibi tanımlanabilir. Önemli olan bir kalite döngüsünün işletildiğini gösterebilmektir. Yazılım kalitesi ileride ayrıca konuşulacaktır.

ISO'nun yazılım geliştirmeye özel sertifika standardı ISO/IEC 90003:2018'dir. Hoca, standartların zaman içinde yeni sürümlerinin çıkabileceğini, yeni sürümlerin genelde eskiyi genişlettiğini ya da bazı tanımları kullanımdan kaldırdığını, ama çok köklü değişmediğini; yeni sürümlerin başında genelde bir öncekinden farkları anlatan bir bölüm olduğunu söyler. Önceki derste görülen hazır ticari yazılım (commercial off-the-shelf) geliştirmeye yönelik standart önerisi gibi alt standartlar da vardır; ancak bunlara uyum ayrıca belgelendirilmez, 90003 ise ayrıca sertifikası alınan bir standarttır.

Türkiye'de özel firmalar ISO'dan yetkili Denetik'e, kamu kurumları ulusal otorite TÜRKAK'a (Türk Akreditasyon Kurumu) başvurur. Başvurudan önce süreçler oturtulmuş ve belgelenmiş olmalı, standardın gerektirdiği etkinliklerin geçmiş dönemlere ait kanıtları biriktirilmiş olmalıdır; "hadi başvuralım" denip hemen başvurulamaz.

Bu sertifikasyonların her biri ayrı bir uzmanlık gerektirir; hem başvuranlar hem denetleyiciler için ciddi emek gerekir. Bu yüzden bu süreçleri sürdüren kurumlarda bu işe ayrılmış departmanlar ya da komisyonlar bulunabilir.

### 2.3 Genel mi, Özel mi?

Slayttaki "Peynir mi üretiyoruz?" sorusu bu tartışmayı özetler. Hoca özel standartlara yönelme taraftarıdır: peynir üreten bir firma ile yazılım üreten bir firmanın dinamikleri ve çalışma biçimleri farklı olmalıdır. Her şeyi kapsayan standartlar eylemleri fazla genel hatlarla tanımladığı için başarıya çok katkı sağlamayabilir. Ana ilkelere uymak mutlaka yarar sağlar, ama en fazla yarar çalışılan alana özel bir standartla elde edilir. Alana özel bir standart yoksa ISO 9001 gibi genel standartlar elbette tercih edilebilir.

## 3. CMMI Düzeyleri

CMMI'da beş düzey vardır; aslında sıfırıncı düzey de sayılırsa altı düzey olur. Hoca, saymanın bilgisayarlardaki gibi 0'dan başlamasının modelin yazılıma özgü olduğunu gösterdiğini şakayla söyler. Her CMMI düzeyi, bir önceki düzeyin etkinliklerinin üstüne yeni etkinlikler eklenerek tanımlanır: örneğin Düzey 3, Düzey 2'deki etkinliklerin üstüne yenilerini katar.

Slayttaki tanımlar (ekrandan, 00:35:00):

- 0. Düzey: Yürütülmeyen (Level 0: Incomplete).
- 1. Düzey: Giriş düzeyi (Level 1: Initial/Performed). İş şansa ve anahtar kişilere kalmış. Etkinliklerin tümü yürütülüyor ama bunların tanımlanması için hiçbir sistematik girişim yoktur, her seferinde farklılaşabilirler.
- 2. Düzey: Yönetilen/Yinelenebilir (Managed/Repeatable). Temel planlama ve izleme yöntemleri kullanılarak, önceki projelerdeki başarılar yeni projelerde tekrarlanabilir.
- 3. Düzey: Tanımlanmış (Defined). Kişi ve risk yönetimi ile projenin yönetimi iyileştirilir. Tüm organizasyonda standart süreçler tanımlanmıştır.
  - Büyük müşteriler en az bu düzey yazılım evleri ile çalışmak ister.
- 4. Düzey: Nicel Yönetilen (Quantitatively Managed). Süreç ve yazılım ölçütleri kullanılarak kalite yönetimine geçilir. İlerleme sürekli izlenir, bütçe ve zaman hedeflerinden sapmalar erkenden belirlenerek gerekli önlemler alınır.
- 5. Düzey: İyileştirilmiş (Optimized). Süreç yönetimi geçmiş deneyimlerin ışığında sürekli iyileştirilir.

### 3.1 Düzey 1: Şansa ve Anahtar Kişilere Kalmış İş

Bu düzeyde belirli bir başarı yakalanmış olabilir, üst düzeylerde istenen etkinlikler de yapılıyor olabilir. Ama bunların nasıl yapılacağına dair hiçbir tanım ya da düzenleme yoktur; yalnız ana hatlarıyla "şu yapılır" denir. Firmaya yeni gelen bir çalışan ne yapacağını bilmez; ancak mevcut çalışanların yanında bir süre çalışarak işin nasıl yapıldığını öğrenebilir. Çalışanlar o kadar kritiktir ki bir anahtar kişinin bir iki hafta görevinin başında olamaması kaosa yol açabilir. Etkinliklerin kuralları her seferinde farklılaşabilir.

### 3.2 Düzey 2: Yönetilen ya da Yinelenebilir

Bu düzeyde temel proje planlama ve izleme yöntemleri kullanılır; böylece önceki projelerdeki başarılar yeni projelerde tekrarlanabilir. Bir iş planlama yöntemi vardır; bunun için özel bir yazılım bile şart değildir, bir Excel dosyası üstünden plan yapılıyor olabilir (tercih edilmez ama mümkündür). Planın doğru yürüyüp yürümediğini izleyen kişi yazılım ekibinin bir üyesi olabilir ya da işi proje yönetimi olan profesyonel bir yönetici olabilir. Hoca kişisel tercihinin yazılım mesleği eğitimi almış birinin yönetici olması olduğunu, ama öteki türlü de işlerin iyi yürüyebildiğini söyler; bu konu yazılım proje yönetimi bölümünde tartışılacaktır.

Hoca, slaytta "Managed" sözcüğünü vurguladığını, ama aslında "Repeatable" adının daha iyi olabileceğini söyler: 4. düzeyin adı da "Quantitatively Managed" olduğundan, "Managed" sözcüğü 2. ve 4. düzeyin karıştırılmasına yol açabilir.

### 3.3 Düzey 3: Tanımlanmış

İşin içine kişi yönetimi ve risk yönetimi girer; proje yönetimi etkinlikleri daha derin bir düzeyde yürütülür. Her işin hangi ilkeler çerçevesinde yapılacağı belgelenmiştir. Böylece şirkette hangi görevde olursa olsun yeni başlayan biri ya da bir stajyer, kendi görevinde neyi nasıl yapacağını ve kimlerle hangi kurallar çerçevesinde etkileşeceğini, kimsenin söylemesine gerek kalmadan kurumsal eğitim kaynaklarından öğrenebilir. Çalıştıkça deneyim kazanır ama ilk başta "sudan çıkmış balık gibi" olmaz.

> **Hocanın vurgusu:** Ulaşılmaya çalışılan temel nokta bu düzeydir. Büyük müşteriler en azından bu düzeyde çalışan yazılım evleriyle iş yapmak ister; örneğin bir ihalede "CMMI Level 3 ya da üstü akreditasyona sahip yazılım evleri başvurabilir" şartı konabilir. Ne kadar yetenekli olunursa olunsun, başarıların şansa mı yoksa çalışma disiplinine mi bağlı olduğundan emin olunamayacağı için bu akreditasyon yoksa başvurulamaz.

### 3.4 Düzey 4 ve 5

Düzey 4'te süreç ölçütleri ve yazılım ölçütleri devreye girer; bunlar kullanılarak kalite yönetimi etkinliği yapılmaya başlanır. Hem projenin ilerlemesi hem çalışma yöntemlerinin metrikleri sürekli izlenir; bütçe ve zaman hedeflerinden sapma olasılığı varsa erkenden belirlenip önlem alınır.

Düzey 5 tam olgun bir kalite çevriminin kapatılmasını ister: 4. düzeyde yapılan süreç yönetimi geçmiş deneyimlerin ışığında sürekli iyileştirilir. 4. düzeyde "yönetim" işleri yoluna koymak anlamında kullanılırken, 5. düzeyde çalışma biçimini sürekli iyileştirmek anlamındadır.

## 4. CMMI İlgi Alanları, Tarihçe ve Çevik Süreçler

Slayttaki bilgiler (ekrandan, 00:45:00):

- CMMI, her düzeyde belli süreç alanlarının kapsanıyor olmasını ister.
  - Süreç alanları belli hedeflere ulaşmak için beklenen uygulamalardır.
  - Her firma gerekli süreç alanlarını kendine özgü süreçlerle kapsar.
- CMMI ilgi alanları:
  - CMMI-DEV (Development): Yazılım geliştirme
  - CMMI-SVC (Service): Hizmet sunumu ve yönetimi
  - CMMI-ACQ (Acquisition): Ürün ve hizmet alımı
  - Bu üç alan, CMMI v2.0 ile (2018) tek bir olgunluk modeli altında birleştirilmiştir.
- Tarihçe:
  - 1987-1997: CMM
  - 1998-2009: CMMI
  - 2010: CMMI v1.3, çevik süreçler desteklenmeye başladı
  - 2018: CMMI v2.0
    - Continuous (kısmi, sadece bazı süreç etkinliklerini kapsayan) ve Staged (bütüncül, daha değerli) ayrımı kaldırılıp tüm süreç etkinliklerini kapsayacak içerikte birleştirildi.
    - Kaynakları ücretli/abonelik tabanlı hale geldi.

### 4.1 Süreç Alanları

CMMI "illa şöyle yapacaksınız" demez, "şunu yapacaksınız" der. Firma "biz bunu şöyle yapıyoruz" der ve kendi çalışma biçiminin standarttaki temel isterleri karşıladığını kanıtlamak durumundadır; kanıtlarsa akredite olur.

### 4.2 Üç İlgi Alanı

CMMI-DEV yazılım geliştirme alanıdır ve modelin temel çekirdeğidir. Daha az kapsayıcı iki alan daha vardı. Örneğin daha büyük kurumlara ya da daha büyük yazılım evlerine bazı hizmetler sunan ya da yöneten küçük bir yazılım evi, büyük ölçekli CMMI-DEV yerine (onun gerektirdiği çabaya ayıracak kaynağı yoksa) CMMI-SVC'ye başvurabiliyordu. Alt yüklenicilerle çok sık çalışan bir yazılım evi ise alt yüklenicilerinin iyi iş yapıp yapmadığını, onlarla çalışma biçiminin yeterli düzeyde olduğunu CMMI-ACQ'ye başvurarak kanıtlayabiliyordu. 2018'den itibaren bu alanlar birleşmiştir.

### 4.3 Tarihçe

Model 1987'de oluşturuldu ve yaklaşık on yıl boyunca CMM (Capability Maturity Model) olarak anıldı; "Integration" sözcüğünün baş harfi olan "I" 1998'den sonra eklendi. Bu yüzden eski kaynaklarda CMM adı görülebilir.

### 4.4 CMMI ve Çevik Süreçler

Çevik çalışmanın gereksinimleri ile ayrıntılı belgelendirme ve ayrıntılı süreç yönetimi arasında bir çelişki olabiliyordu; bu çelişki 2010 öncesi CMM ve CMMI modellerinde çok belirgindi. Çevik süreçlerin başarısı kendini kanıtlayıp yaygınlaşınca, çevik süreçlerle de belirli bir kalite düzeyine ulaşılabileceği kabul edildi ve 2010'da çıkan v1.3 ile çevik süreçler desteklenmeye başladı. XP ya da Scrum gibi herhangi bir çevik süreci belirli bir olgunluğun üstünde işleten her yazılım evi CMMI'ya başvurup en azından Level 3 akreditasyon alabilir; bunun için gereken ek çaba en aza inmiştir.

Hoca, Microsoft'un geliştirme ortamının ve IBM Rational'ın daha önce konuşulan büyük CASE araçları gibi tüm süreç etkinliklerini kapsadığını, Microsoft'un ortamında yeni bir proje başlatırken kullanılabilecek hazır şablonlar arasında CMMI Level 3 ve çevik çalışmaya uygun şablonlar gördüğünü söyler; yani bu tür çalışma "kutudan çıktığı gibi" desteklenmektedir. <!-- BELİRSİZ: altyazıda ürün adları bozuk ("Azoz", "Azor", "Rachel"); Azure DevOps ve IBM Rational olarak yorumlandı, şablonun tam adı anlaşılmıyor. -->

### 4.5 Continuous ve Staged

Hoca bu ayrımı şöyle anlatır: Örneğin 4. düzey, 1., 2. ve 3. düzeylerin etkinlikleri artı proje ölçütleri gibi etkinlikler gerektirir. Bir kurum 4. düzeyin gerektirdiği etkinliklerin neredeyse tamamını karşılıyor ama 3. düzeyde tanımlanan bazı etkinlikleri yeterince yapamıyorsa, yani ufak eksikleri varsa "continuous" olarak akredite olur. Eksik etkinlikleri de standardın gerektirdiği şekilde yapmaya başladığında "staged" (bütüncül) duruma geçebilir; staged, her adımdaki her alt etkinliğin tamamen ve yeterli düzeyde karşılandığı anlamına gelir ve daha değerlidir. Slayta göre v2.0 ile bu ayrım kaldırılmıştır (ekrandan, 00:45:00).

v2.0 ile CMMI iyice ağır bir yönteme dönüşmüş, kaynakları da ücretli ya da abonelik tabanlı hale gelmiştir. Hoca 2018 öncesinde CMMI kitabının ücretsiz indirilebildiğini, artık bunun mümkün olmadığını; belgenin binlerce sayfalık olduğunu ve başlı başına bir uzmanlık alanı oluşturduğunu söyler.

### 4.6 Akredite Kurumların Sorgulanması

Bir firmanın akreditasyon iddiasının doğru olup olmadığı kontrol edilebilmelidir. CMMI Institute'un değerlendirme (appraisal) sistemi sayfasında akredite kurumların listesine ulaşılabilir (ekrandan, 00:55:00). Derste önce slayttaki, Şubat 2020 itibarıyla CMMI Level 3 ve üstü sertifika almış birkaç Türk kuruluşu örneği verilir (örneğin Milsoft ve TÜBİTAK BİLGEM Level 5; ASELSAN, HAVELSAN, KoçSistem gibi kurumlar Level 3), sonra sayfada Türkiye için güncel arama yapılır ve 5 sayfada 25 kurum listelenir. Kayıtlarda kurum adı, değerlendirme takımı lideri, model/alan (örneğin "CMMI Development V2.0 (CMMI-DEV)"), geçerlilik tarihleri ve düzey (örneğin ML3) görünür (ekrandan, 01:00:00). <!-- BELİRSİZ: slayttaki kurum listesinin karesi okunmadı; adların bir kısmı altyazıda bozuk. -->

Hoca, yurt dışından ya da yurt içinden bir iş teklifi alındığında firmanın CMMI ya da ISO akreditasyonu olup olmadığına bakılmasını önerir. Yazılım projelerine özgü bir standart olduğu için CMMI akreditasyonu belirli bir düzeyin üstünde olan bir firmada kariyere başlamanın ve ilerlemenin değeri daha yüksek olacaktır.

## 5. CMMI ve CASE Araçları

Bu bölümün sorusu şudur: CMMI'da belli bir düzeye erişebilmek için CASE (Computer Aided Software Engineering) araçları kullanılabilir mi, hangi düzeyde ve ölçekte? Hoca bunu yalnız klasik CASE araçlarıyla sınırlamaz; Microsoft'un ya da IBM'in Rational platformu gibi modern araçlar da düşünülebilir.

Slayttaki ilk iki düzey (ekrandan, 01:05:00):

- Düzey 1. Başlangıç düzeyi:
  - Yazılım araçlarının kullanımına dair hiçbir standart yoktur.
  - Yazılım ölçütleri kullanılmaz.
  - Yeniden kullanılabilirlik yoktur veya minimal düzeydedir.
- Düzey 2. Tekrarlanabilir düzey:
  - Yazılım aracı kullanımına yönelik proje standartları vardır.
  - Çalışanlara yazılım araçlarının kullanımına yönelik eğitim verilmiştir.
  - Bazı takım tabanlı yazılım araçları, diğer yazılım araçları ile tümleştirilmiştir (entegrasyon).
  - Tasarım ve kodun bir kısmı sınırlı olarak yeniden kullanılabilir.

### 5.1 Düzey 1

Başlangıç düzeyinde araç kullanımına dair bir standart, yazılım ölçütü ve yeniden kullanım yoktur. Hoca CASE araçlarının yeniden kullanılabilirliği artırdığını hatırlatır: her projede elde edilen dersler, yapılan değerlendirmeler, oluşturulan modeller, varlıklar ve ilişkiler CASE bilgi tabanında saklanıp tekrar kullanılabilir. Başlangıç düzeyinde buna hiç gerek duyulmaz.

### 5.2 Düzey 2 ve Tümleştirme Örnekleri

Temel proje standart şablonları tanımlanmış, çalışanlara araç eğitimi verilmiş olmalıdır. Takım tabanlı araçların birbiriyle tümleştirilmesine hoca iki örnek verir:

- Görev yönetimi yazılımında bir gözden geçirme (review) toplantısı görevi tanımlandığında, Zoom, Teams gibi bir toplantı yazılımında otomatik olarak toplantı oluşturulur ve ilgili kullanıcıların hesaplarına davetler gider, toplantı takvimlerine eklenir.
- Bir hatanın düzeltilmesiyle ilgili kod tamamlanıp kod havuzuna gönderildiğinde otomatik gözden geçirme çalışmaları yürütülür; takım lideri sonucu gözden geçirip onaylamadan kod havuza kabul edilmez. Araçlar ayrıysa aralarında tümleştirme kurulmalıdır: ilgili yöneticiye "şu gözden geçirme sonucunu inceleyin" iletisi gider, yönetici iletideki bağlantıya tıklayıp ilgili aracı ya da tarayıcıyı açar, sonucu görür ve onay ya da red kararını verir.

Yalnız kodun değil, tasarımın da yeniden kullanılabilirliği önemlidir: veri modeline yönelik şemalar ya da nesneye yönelik tasarımın sınıf şemaları sınırlı da olsa yeniden kullanılabilir.

### 5.3 Düzey 3, 4 ve 5

Bu düzeyler altyazıdan aktarılmıştır. <!-- BELİRSİZ: bu düzeylerin slayt karesi okunmadı. -->

Hocaya göre asgari hedef Düzey 3 olmalıdır. Bu düzeyde bütün yazılım araçlarının erişebildiği, organizasyona ait bir veri deposu ve bir yeniden kullanım kütüphanesi oluşturulmuştur; her yeni projede bunlara kolayca ve tümleşik biçimde erişilebilmelidir. Çeşitli yazılım ölçütleri toplanmaya başlanmıştır. Hangi ölçütlerin toplanacağı serbesttir: amaca yönelik ölçütler kullanılması gerektiğinden ve her projenin amacı farklı olabileceğinden (ilk derste farklı yazılım türleri konuşulmuştu) "mutlaka şunlar toplanacak" denemez. Ölçütler yalnız toplanmakla kalmaz, üst düzeylerde kullanılmak üzere bir veri tabanında saklanır. Yazılım ölçütleri ileride ayrıca tartışılacaktır.

Düzey 4'te bu ölçütlerin analizi yapılır. <!-- BELİRSİZ: altyazıda "iletişimsel analizi" geçiyor; büyük olasılıkla "istatistiksel analiz". --> Düzey 5'te ise mevcut ve yeni eklenecek gereksinimler, kullanılan bütün teknikler ve bütün proje yönetimi süreçleri sürekli değerlendirilir. Buradaki metrikler yalnız kod metrikleri değil, proje metrikleri de olacaktır. Hepsi değerlendirilir ve sürekli iyileştirmeye tabi tutulur: "Nerede geri kalıyoruz, bunu nasıl daha iyi yapabiliriz?"

## 6. Gereksinim Mühendisliğine Giriş

Aradan sonra yeni bir alan olan gereksinim mühendisliğine geçilir. Hoca, konu hâlâ biraz teorik olsa da artık pratik etkinliklerin yürütüleceği aşamalara yaklaşıldığını söyler.

Slayttaki tanım ve tartışma (ekrandan, 02:10:00):

- Üzerinde çalışılmaya başlanacak projenin amaçlarını, boyutlarını ve etkilerini belirlemeye yönelik çalışmalardır.
  - Genel amaçlı proje yönetimi faaliyetleri arasında yer alan yapılabilirlik (feasibility) çalışmasına bir girdi olarak düşünülebilir.
- Müşteri ne istediğini bilmez mi? Gereksinimler zaten belli değil mi?
  - Çoğunlukla müşterinin kafasında sadece genel bir fikir vardır.
  - Yoruma açık ve ayrıntıları kesin çizgilerle belirlenmemiş gereksinimler projenin başarısızlığına davetiye çıkarır.
  - Kesin belirlenmiş gereksinimler bile zaman içerisinde değişebilir.
- Deyişler:
  - Şeytan ayrıntıda gizlidir.
  - Yanlış veya eksik işi yapan mükemmel yazılım değil, doğru işi yapan iyi çözüm gereklidir.
  - SONUÇ: Gereksinim mühendisliği (Requirements Engineering) gerekli bir etkinliktir.

Hoca "feasibility" için yaygın Türkçe karşılık yerine "yapılabilirlik" demeyi tercih eder.

### 6.1 SRS Belgesi ve Standartlar

Slayttaki bilgiler (ekrandan, 01:30:00):

- Gereksinimler, SRS (Software Requirements Specification) belgesi altında toplanır.
- SRS raporuna yönelik çeşitli standartlar mevcuttur.
  - IEEE 830-1998: SRS odaklı
  - ISO/IEC/IEEE 29148:2011 Systems and Software Engineering – Life Cycle Processes – Requirements Engineering
  - Ders kapsamında, gereksinim mühendisliği ve analiz bölümlerinde bu belgede yer alabilecek artefact'ların en yaygınları üzerinde çalışılacaktır.
  - Yazılım geliştirme sırasında kod dışında ortaya çıkardığımız her türlü metin ve şemaya "artefact" denilmektedir.

> **Hocanın vurgusu:** SRS belgesini bilmek hem ders hem de meslek hayatı açısından önemlidir. Bu standartların önerdiği yöntemler, problemin, insan kaynaklarının ve şirketin çalışma süreçlerine uygun olduğu ölçüde çalışmalara katıldıkça yarar sağlar.

29148 standardı, yazılım yaşam döngüsü içinde yapılan gereksinim mühendisliği etkinliklerinin nasıl yapılacağını daha geniş olarak anlatır. Artefact (hocanın deyişiyle "artifakt") için kod dışında ortaya çıkan her şey örnek verilir: kullanım öyküsü metinleri, UML şemaları (bir kısmı nesneye yönelik programlama dersinde görülmüştür, kalanı bu derste görülecek), yapılandırma dosyaları, mimari şemalar, sunum olarak hazırlanmış özetler, yapılan teknik gözden geçirmelerin sonuç belgeleri. Hoca, sözcük için net bir Türkçe karşılık bulamadığını söyler.

> **Ek bilgi (derste anlatılmadı):** IEEE 830-1998, büyük olasılıkla 2011'de yayımlanan ISO/IEC/IEEE 29148 tarafından yerini bırakmış (superseded) bir standarttır; 29148 daha sonra yeniden de güncellenmiştir. Bu yüzden güncel kaynaklarda SRS içeriği çoğu zaman 29148'e göre anlatılır.

## 7. Gereksinim Mühendisliğinin Adımları

Gereksinim mühendisliğinde üzerinde uzlaşılan çalışma biçimi, ardışık yürütülen yedi adımdan oluşur. Farklı varyasyonlar önerilebilir, ama bunlar yazılım geliştirme süreçleri kadar ayrıntılı ve büyük ölçekli değildir.

Slayttaki adımlar (ekrandan, 01:35:00):

- Gereksinim mühendisliğinin genel adımları:
  - Başlangıç (Inception)
  - Bilgi Toplama (Elicitation)
  - İşleme (Elaboration)
  - Pazarlık (Negotiation)
  - Tanımlama (Specification)
  - Doğrulama (Validation)
  - Yönetim (Management)
- Gereksinim mühendisliği adımları gerçeklenecek yazılımın doğasına ve kullanılan sürece göre düzenlenmelidir.
- Gereksinim mühendisliği adımları süresince yazılım ekibi ve müşteri birlikte çalışmalıdır.
  - Müşterinin bir ekibinin, yazılım geliştirme sürecinin mümkün olduğunca çok adımının bir parçası olması yararlıdır.

### 7.1 Müşterinin Katılımı

> **Hocanın vurgusu:** Gereksinim mühendisliği aşamasında yazılım ekibinin müşteriyle birlikte çalışması çok kritiktir. Gereksinimlerin net ve doğru olarak belirlenmesi yazılım projesinin başarısı için en önemli etkenlerden biridir; projenin başındaki ve süreci yönetecek kişileri birinci sıraya koysanız bile, müşterinin katılımı ona çok yakın bir önemdedir.

Müşterinin katılımı sağlanamıyorsa ya da genel amaçlı bir ürün hazırlanıyorsa, en azından pilot uygulama yapılacak bir müşteri bulunmalıdır. Bu müşteriyi isteklendirmek için yazılım indirimli bir fiyata sunulabilir; böyle bir müşteri sürecin mümkün olduğunca çok aşamasında yer alırsa katkısı daha da büyük olur. O da olmuyorsa problem alanındaki bir konu uzmanının desteği danışmanlık hizmeti olarak alınmalıdır; yoksa başarılı olunamaz. Çünkü yazılım projeleri birilerinin işini kolaylaştırmak ya da daha verimli hale getirmek için hazırlanır; bu nedenler yeterli nitelik ve nicelikte karşılanamıyorsa proje başarılı olmaz.

Sonraki slaytlarda adım listesi hep üst tarafta kalır, alt tarafta o anda tartışılan adımın ayrıntıları yer alır; hoca adımların sırasının akılda kalmasını ister.

### 7.2 Başlangıç (Inception)

Başlangıç, yazılım projesinin, yani gereksinim mühendisliğinin sonraki adımlarının ve yaşam döngüsünün diğer adımlarının başlatılmasına karar verilen adımdır; işin ilk kıvılcımı burada çıkar. Fikir müşteriden de, yazılım evinden de gelebilir. Yeni bir projenin gerekli ve yararlı olabileceğini düşündüren olaylar şunlar olabilir:

- Yeni bir iş gereksiniminin belirlenmesi.
- Mevcut iş süreçlerinde güçlüklerle karşılaşılması.
- Müşterinin ya da yazılım evinin üst düzey karar vericileri arasında geçen kısa bir konuşma ya da toplantı. Hoca, bir çalışanın kafede, su makinesinin başında ya da asansörde bir üst yöneticiyle karşılaştığında kısa sürede onun ilgisini çekebilirse "düşündüklerini bana bir gönder" yanıtıyla bir projenin başlayabileceğini anlatır.
- Yeni bir pazarın ya da hizmetin fark edilmesi (özellikle uygulama yazılımları için); bunu genelde büyük resmi gören üst düzey yöneticiler fark eder.

Slayttaki paydaş tanımı (ekrandan, 01:40:00):

- Başlangıç aşamasında paydaşlar belirlenmelidir.
  - Paydaş: Gerçeklenecek sistemden doğrudan veya dolaylı olarak yararlanabilecek ve etkilenebilecek herkes.
    - Her paydaş sisteme farklı bir açıdan bakar.
    - Projenin başarısı veya başarısızlığı paydaşları farklı şekillerde etkiler.
    - Paydaşlara sorulacak sorularla belirlenmesi gerekenler: paydaşların bakış açıları, paydaşları etkileyebilecek nedenler, söz konusu etkilerin sonuçları.

Paydaş (stakeholder) kavramı kazan-kazan (WinWin) modelinde de konuşulmuştu. Etki olumlu da olabilir, olumsuz da. Amaç paydaşların çıkarlarını keşfedip uzlaştırarak mümkün olan en geniş tatmini sağlamaktır.

> **Hocanın vurgusu:** Paydaşlar başlangıç aşamasında belirlenir; sonra değil, gereksinim mühendisliğinin ilk adımında. Sonraki adımlar buna bağlanır.

### 7.3 Bilgi Toplama (Elicitation)

Gereksinimler hakkında olabildiğince ayrıntılı bilgi toplanır. Bir analiz ekibinin her paydaşa tek tek ve ayrı ayrı gitmesi yerine, tüm paydaşların birlikte katıldığı toplantılar en doğrusudur; en çok bilgi böyle ortaya çıkar. Böyle büyük bir toplantıda:

- Hazırlık ve katılım kuralları belirlenmelidir.
- Gündem belirlenmelidir: önemli konuları atlamayacak kadar sıkı, ama yaratıcılığı ve beyin fırtınasını engellemeyecek kadar açık.
- Düzeni sağlayacak ve tıkanıklığı çözecek bir oturum başkanı olmalıdır.

Toplantı yönetmek deneyimle kazanılan ve keskinleşen bir sanattır, ama yararlı kaynaklardan ön çalışma yapılabilir. Hoca örnek olarak "Robert's Rules of Order" kitabını önerir; kitap edinilemese bile onu anlatan açık web kaynaklarına bakılabilir.

### 7.4 İşleme (Elaboration)

Slayttaki içerik (ekrandan, 01:45:00):

- Bilgi toplama aşamasında toplanan "ham" bilgilerin "işlenmesi".
- Son kullanıcının ve diğer paydaşların yazılımla nasıl etkileşimde bulunacağının belirlenmesi ve ayrıntılandırılmasını amaçlar.
- Etkileşimler, kullanım senaryoları ile gösterilir (ileride anlatılacak).
- İşleme kimi bilgilerin genişletilmesi, kimi bilgilerin özetlenmesi şeklinde gerçekleşir.
- Gereksinimlerin sınıflandırılması: normal gereksinimler, beklenen gereksinimler, heveslendirici gereksinimler.

Bu aşamada kullanım senaryosu metinleri hazırlanmaya, aktörler arasındaki ilişkiler kullanım senaryosu şemalarıyla çizilmeye başlanır. İşlerken bazı alanlarda bilginin eksik olduğu, bazılarında ise aşırı ayrıntılı ve tekrarlı olduğu keşfedilebilir. Eksik bilgiler, artık bütün paydaşlarla değil, ilgili paydaşlarla yapılacak görüşmelerle ayrıntılandırılır.

Fazla bilgi kendi başına zararlı değildir. Ama aynı şey birkaç farklı biçimde ya da birkaç eş anlamlı sözcükle anlatılıyorsa belirsizlik doğar. Hocanın ipucu: Bir kavramın birden fazla eş anlamlı karşılığı varsa, gereksinimler belgesinin ön bölümlerinden birinde bir sözlük bölümü açılır, eş anlamlılar orada birlikte verilir ve belgenin geri kalanında bunlardan yalnız biri seçilip tutarlı biçimde kullanılır. Böylece anlaşılabilirlik artar.

### 7.5 Gereksinimlerin Sınıflandırılması

**Normal gereksinimler**, kullanıcıların ve paydaşların sistemden istedikleri, yani sistemin yapması gereken işlerdir.

**Beklenen gereksinimler** (expected requirements) tehlikelidir: o kadar temeldir ki kullanıcı bunları söylemeyi bile unutabilir. İşleme aşamasında "burada oturmayan bir şey var, şu adımda bir belirsizlik var" sorusu akla gelmezse bu gereksinimler keşfedilmeden sonraki aşamalara geçilir ve yazılımın temel dinamiği gereği sonradan daha pahalıya mal olur.

Hocanın örnekleri kütüphane alanındandır:

- Kütüphaneden ödünç alınan kitap belli bir sürede iade edilmelidir. Bu, bir kütüphaneci için o kadar bariz bir olgudur ki bilgi sistemi için gereksinimleri anlatırken söylemeyi unutabilir; ama bu alanda ilk kez çalışan yazılım ekibi için bariz olmayabilir.
- Her kitap ödünç verilmez: 5, 10, 20 ciltlik ansiklopediler gibi temel başvuru kaynaklarına çok kişinin sık bakma ihtiyacı olduğundan bunlardan yalnız kütüphanede yararlanılır.

Alanda daha önce çalışılmışsa deneyimle bu beklenen gereksinimler ekip tarafından çıkarılıp paydaşlara teyit ettirilebilir. İlk kez çalışılıyorsa, gereksinim çalışmalarına başlamadan önce problem alanı hakkındaki bilgi birikimini genişletmek yararlıdır; en değerli kaynak teknik literatürdür (basılı yayınlar, elektronik kaynaklar, videolar).

**Heveslendirici gereksinimler** müşterinin temel beklentilerinin ötesindedir; gerçeklenirse müşteri sevinir. Sistemin temel işlevleri dışında kalan yan ve ikinci düzey gereksinimlerdir. Hocanın örneği: İngilizlerin lüks otomobil markalarından birinde (Rolls-Royce ya da Bentley olarak anıyor) arka kapıda, kapı açılınca ortaya çıkan bir şemsiye tutacağı vardır; yağmurlu bir ülkede yolcu ya da şoför kapıyı açınca hemen şemsiyeyi alabilir. Otomobilin performansı ve konforu açısından çok daha önemli başka işlevler vardır; bu özellik hoş ama çekirdek ihtiyaç için gerekli değildir.

Heveslendirici gereksinimlerin ayrıca belirlenmesinin yararı şudur: zaman ya da bütçe sıkıntısıyla karşılaşılırsa bunlar proje planından kolayca çıkarılabilir.

### 7.6 Pazarlık (Negotiation)

Farklı paydaşların gereksinimleri birbiriyle çelişebilir ya da farklı önem düzeylerinde görülebilir. Ayrıca müşterinin istekleri gerekli, yararlı ve doğru olsa bile eldeki insan kaynakları, bütçe ve zaman kısıtları çerçevesinde karşılanamayabilir; bazen ekip daha kalabalık olsa bile istenen sürede bitirmek olanaksızdır. Bu durumda isteklerin makul seviyeye çekilmesi, gereksinim mühendisliği etkinliğini yürüten teknik ekibin sorumluluğundadır: bazı gereksinimler işin yapılabilirliğine yönelik daha "ayakları yere basan" hale çevrilir.

Bu aşama, tüm paydaşların razı olduğu bir gereksinimler listesi elde edildiğinde tamamlanır ve tanımlama aşamasına geçilir.

### 7.7 Tanımlama (Specification)

Slayttaki içerik (ekrandan, 01:55:00):

- Gereksinimler tanımlama aşamasında, pazarlık sonucu üzerinde uzlaşılan haliyle kağıda dökülür.
- Tanımlama araçları:
  - Konuşma dili ile yazılmış belgeler
  - Kullanıcı senaryoları: Görülecek
  - Kullanım şemaları: Görülecek
  - Formel modeller (Matematiksel gösterim, işlenilmeyecek)
  - Bir ön ürün
- Birden fazla tanımlama aracı birlikte kullanılabilir.

Uzlaşma "söz uçar, yazı kalır" ilkesiyle kağıda (bugün elektronik belgeye) dökülür; istenirse çıktısı alınıp her sayfası paraflanabilir. Bu tanımlama artefact'ları SRS belgesinde yer alır.

Konuşma diliyle yazılmış paragraflardan tamamen kaçınılamaz, çünkü insanlar ilk başta konuşarak anlaşır. Ama gereksinimlerin olabildiğince açık, net, tartışmaya yer bırakmayacak biçimde belgelenmesi gerekir ve konuşma dili doğası gereği belirsizlik içerir; bu yüzden ne kadar az kullanılırsa o kadar iyidir ve diğer tanımlama araçları ağırlıklı kullanılmalıdır. Kullanıcı senaryoları ve UML kullanım (use case) şemaları derste görülecektir. Matematiksel gösterime dayanan formel modeller ders kapsamında değildir; ayrı bir uzmanlık alanıdır. Bir ön ürün (prototip) bile tanımlama aracı olabilir. Her kısım onu en iyi anlatan araçla ya da araçların bir birleşimiyle yazılır.

### 7.8 Doğrulama (Validation)

Slayttaki içerik (ekrandan, 02:00:00):

- Tanımlanmış gereksinimlerin tutarsızlıklara karşı sağlaması yapılır.
  - Gereksinimler açıkça ve yoruma yer bırakmayacak şekilde tanımlanmış mı?
  - Birbiri ile çelişen gereksinimler var mı?
  - Gereksinimlerde hatalar ve eksikler var mı?
  - Eksik gereksinimler var mı?
  - Gerçekçi olmayan gereksinimler var mı?
- Doğrulama yapma için önerilen temel yol teknik değerlendirmedir (Formal technical review, sınama teknikleri arasında anlatılacak).

Ortaya çıkarılan belge, bir anlamda test edilir: "Doğru bir iş mi yaptık, yaptığımız iş kendi içinde tutarlı mı?" sorularına olumlu yanıt verildiğinden emin olunmalıdır. Formal technical review (resmi teknik değerlendirme) ile hatalar ve tutarsızlıklar bulunur ve hemen düzeltilir. "Eksik gereksinim" maddesi hem tümüyle unutulmuş bir gereksinimi hem de eklenmiş ama hatalı ya da eksik eklenmiş bir gereksinimi kapsar; "gerçekçi olmayan gereksinim" ise pazarlıkta gözden kaçmış olabilir.

Hoca doğrulamanın neden gerekli olduğunu bir benzetmeyle anlatır: konu uzmanı bazen "fazla hipermetrop" olabilir, çok yakınındakini gözden kaçırır. Konuyu iyi bildiği için okuduğu cümle ona açık gelir, ama başka biri aynı netlikte bir resim göremeyebilir; aynı meslekten olup daha az deneyimli biri bile. Belgeyi okuyan kişi yazılımı gerçekleyen ekipteyse, belirsizliği kendi kafasına göre netleştirip ona göre kodlar; bu, deneyimli kişinin kastettiğinden farklı ve belki hatalı bir gerçekleme demektir ve sonradan düzeltme çabası gerektirir. Bu yüzden herkesin aynı biçimde anlayabileceği bir gereksinimler belgesi gerekir.

### 7.9 Yönetim (Management)

Yönetim "yaptık, bitti" denen bir adım değildir; gereksinim mühendisliğinin bütün yazılım sürecini kapsayan şemsiye adımıdır.

Proje sürerken gereksinimler değişebilir. "Gereksinimler üstünde anlaştık, sözleşmeyi imzaladınız, ürünü bu haliyle alacaksınız, değişiklikleri yeni sürümlerde ek anlaşmalarla yaparız" diyen katı bir sözleşme müşteri açısından tercih edilmez; müşteri büyük olasılıkla daha esnek yazılım evleriyle çalışmayı seçer. Çevik süreçlerde kullanıcı öykülerinin sürekli eklenmesi, silinmesi, gruplanmasının değiştirilmesi gibi esneklikler görülmüştü; böyle bir esneklik sağlanıyorsa onun yürütülmesine yönelik etkinlikler bu adımda değerlendirilir.

Esneklik olmasa bile hatalar mutlaka olacaktır; zor ve karmaşık bir iş yapılmaktadır. Bir hata ortaya çıktığında hangi gereksinimle ilgili olduğuna kadar geriye gidilebilmeli, böylece koddaki olası yerleri nokta atışıyla belirlenebilmelidir. Bunun için izlenebilirlik tabloları kullanılır.

Gereksinim değişikliklerinin sürece nasıl dahil edileceği (hangi tür ve ölçekte değişikliklerin, hangi şartlarla projeye alınacağı) bu aşamada belirlenmeli ve sözleşmenin parçası yapılmalıdır; bunun izlenmesi ve yürütülmesi yönetim aşamasının etkinliğidir. Ayrıca "projede şu an hangi aşamadayız, hangi gereksinimleri ne oranda gerçekleyebildik, plana, zamanlamaya ve bütçeye uygun mu, uygunsuzluk varsa nasıl düzenleme yapılmalı?" soruları da burada izlenir.

## 8. İzlenebilirlik Tabloları

Slayttaki içerik (ekrandan, 02:05:00):

- Yönetim (devam):
  - Yazılım geliştirme süreci içerisinde gereksinimlerin gerçeklenmesinin (ve varsa gereksinimlerdeki değişikliklerin) izlenmesi gerekir.
  - İzleme tablolar aracılığı ile yapılır: İzlenebilirlik tabloları (Tracebility table).
- G1,2,...: Gereksinimler
- B1,2,...: Sisteme çeşitli bakış açıları (Modüller, Paketler, Sınıflar, vb.)

Slayttaki örnek tablo (slayttaki onay işaretleri burada "X" ile gösterilmiştir):

| | B1 | B2 | B3 | ... |
|---|---|---|---|---|
| G1 | X | | X | |
| G2 | | X | | |
| G3 | X | | | |
| ... | | | | |

Hoca bu tekniği "basit bir fikir olmakla birlikte pek keşfedilmemiş" diye tanıtır; anlattığı kişilerin "çok güzel bir fikirmiş, biz de uygulayalım" dediğini, bildiği en basit ve en sade yöntemin bu olduğunu söyler.

Satırlarda gereksinimler bulunur. Her gereksinimin bir kimliği (ID) olur; kullanım senaryolarının adları da olabilir, ama tablolarda ya da şemalardaki elipslerde ad kullanmak yeri büyüttüğü için kimlik üzerinden gitmek daha yararlıdır. Sütunlar sisteme bir bakış açısıdır ve her bakış açısı için ayrı tablo oluşturulur: bir tablo hangi gereksinimin hangi modüllerle, ikincisi hangi paketlerdeki sınıflarla, bir diğeri hangi sınıflarla gerçeklendiğini tutabilir. Böylece küçükten büyüğe farklı çözünürlüklerde tablolar oluşturulur, güncellenir ve sürdürülür.

### 8.1 Tablonun Kullanımı

Tablolar sınama ve bakım aşamalarında yararlıdır. Örnek akış:

- Bir hatayla karşılaşıldı. Hata hangi gereksinimle ilgili? Diyelim ki G1 ile.
- G1 hangi bileşenlerle gerçekleniyor? Tabloya göre B1 ve B3 ile.
- Binlerce sınıf arasından yalnız işaretli birkaçına bakılır ve hatanın kaynağına hızla yönelinir.

Kodu yazan kişi ilgili yeri belki daha hızlı bulur. Ama yazılımı yalnız kodlayan sınamaz (yazılım sınaması ileride ayrıntılı konuşulacak) ve düzeltmeyi yapacak kişi kodu yazan kişi olmayabilir: o kişi işten ayrılmış ya da aynı projede daha acil bir görev üstünde çalışıyor olabilir, iş o an boşta olan başka birine atanabilir. Bu kişi hatanın nereden kaynaklandığını rahatça bilemez; izlenebilirlik tabloları ilk yönlendirmeyi yapıp önemli çaba tasarrufu sağlar.

Tabloyu ilk kurmak belli bir çaba ister. Ama CRC kartları (önceki derste görülmüştü) hazırlanıyorsa, sınıf düzeyindeki tablo için gereken bilgi zaten vardır: gereksinimler sorumluluklar düzeyinde bellidir, sınıflar bellidir; hangi karttaki hangi sınıfta hangi gereksinimle ilgili sorumluluk varsa matristeki ilgili göze işaret konur.

## 9. Nesneye Yönelik Çözümleme Süreci ve Uygulama Alanının Çözümlenmesi

İkinci aradan sonra çözümleme etkinliklerine geçilir (slayt kapağı "Nesneye Yönelik Çözümleme Süreci", ekrandan, 02:20:00). Hoca, buraya kadar görülenlerin nispeten teorik ve ezbere dayalı olduğunu, buradan tasarım aşamasının sonuna kadar uygulamalı ağırlıklı içeriğin geleceğini, ardından yeniden teorik konulara dönüleceğini söyler.

### 9.1 Çözümleme Nedir?

Çözümlemenin sözlük anlamı, bir şeyi anlayabilmek için parçalarına ayırmaktır. Bu aşamada sistemi anlamaya yönelik çalışmalar ve üst düzey planlama eylemleri yürütülür:

- Uygulama alanını anlamaya çalışmak.
- Kullanıcı gereksinimlerini gereksinim mühendisliği çabalarıyla elde etmek.
- Koddaki sınıfları, nesneleri ve aralarındaki üst düzey etkileşimleri belirlemek; yani çözümleme modelini oluşturmak.

Anlaşılmayan bir sorun çözülemez. Nesneye yönelik olmayan bir yaklaşımda da benzer çalışma yapılır; o zaman sınıflar yerine veri yapıları, kayıtlar ve aralarındaki ilişkiler, kalıcılık varsa veri tabanı tabloları ve ilişkileri, daha ciddi bir çalışmada ER şemalarındaki varlıklar ve ilişkiler düşünülür. Bu aşamada işin "nasıl"ı değil "ne"si anlaşılmaya çalışılır.

### 9.2 Uygulama Alanının Çözümlenmesi (Domain Analysis)

Slayttaki içerik (ekrandan, 02:25:00):

- Amaç, uygulama alanını anlamak ve elde edilen bilgileri analiz modeline taşımaktır.
- Uygulama alanı hakkında bilgi edinilebilecek kaynaklar: teknik literatür, mevcut uygulamalar, müşteri anketleri, uzman tavsiyeleri, mevcut ve gelecekteki gereksinimler.
- Problem alanı hakkında bilgi edinmeden "müşterinin dilinden konuşamazsınız".

Hocaya göre en önemli kaynak teknik literatürdür: kitaplar, dergiler gibi basılı ya da elektronik kaynaklar, ücretli ya da ücretsiz eğitimler, videolar. İkincil kaynaklar, elde edilen bilginin geçerliliğini sınamak için de kullanılabilir:

- Mevcut uygulamalar: rakipler ne yapmış? Bizim farkımız ne olacak, neden bizim yazılımımız tercih edilsin? Yalnız fiyat avantajıyla tercih edilmek uzun vadede sürdürülebilir değildir.
- Müşteri anketleri: kendimiz yapabilir ya da yapılmış olanları inceleyebiliriz; böylece müşterilerin en çok neye ihtiyaç duyduğu anlaşılır.
- Uzman tavsiyeleri.
- Mevcut ve gelecekteki gereksinimler: pazar analizleri ya da popüler yayınlardan elde edilen bilgiler de yok sayılmamalıdır.

### 9.3 Müşterinin Dilinden Konuşmak

> **Hocanın vurgusu:** Kullanılan terimler müşterinin bu problem alanında kullandığı terminoloji ve jargonla aynı olmalıdır. Bu yalnız belgelerde değil, kullanıcı arayüzlerinde ve oluşturulan raporlarda da geçerlidir; yoksa kullanıcının memnun olmayacağı bir ürün ortaya çıkar.

Hocanın örnekleri:

- Biz "dergi" deyip geçebiliriz, ama kütüphaneciler "süreli yayın" der. Çünkü "dergi" denince aylık bir yayın akla gelebilir; oysa süreli yayınların bazıları haftalık, bazıları iki ayda bir, bazıları üç ayda bir çıkar, bazıları yıllık rapordur.
- Lojistik sektöründe "multimodal taşımacılık" kavramı vardır: bir ürünün bir noktadan diğerine ulaştırılmasında farklı ayaklarda farklı ulaşım araçlarının birlikte kullanılması; örneğin fabrikadan limana trenle, limandan diğer limana gemiyle, oradan distribütörlere kamyonla. Bu alanda çalışırken bu kavrama bu adla denmelidir.

## 10. Gereksinimler Belgesi ve Kullanım Öyküleri

### 10.1 Örnek Gereksinimler Belgesi: NextGenPOS

Gereksinimler belgesi, müşterinin programdan beklentilerini anlatan, doğal konuşma diliyle yazılmış ama onunla sınırlı kalmayıp daha net araçların da kullanıldığı belgedir. Dersin ilerleyen aşamalarında hep aynı örnek üzerinden çalışılacaktır: bu birkaç cümlelik paragraf üzerinde önce analiz, sonra tasarım çalışmaları yapılacak, sanki gerçek bir yazılım geliştiriliyormuş gibi ilerlenecektir. İçerik Craig Larman'ın kitabından alınmıştır.

Slayttaki örnek (ekrandan, 02:50:00):

> **NextGenPOS Perakende Satış Programı.** Eski yazılım ihtiyaçlarımızı karşılayamadığından, yenilenecek donanımla birlikte perakende satış programımızın da yenilenmesine gerek duyuyoruz. Program kasada yapılan alış-veriş işlemlerine yardımcı olmalıdır. Yapılan her işlem program tarafından saklanmalı; mali bilgiler harici bütçe sistemine, mal çıkış bilgileri ise harici envanter sistemine iletilmelidir. Saklanan işlemler üzerinde daha sonra raporlamalar ve analizler yapılabilmelidir. Sistem yapılan alış-verişler karşılığında müşteriye fiş vermelidir. Yapılan her satış için KDV de hesaplanarak ayrıca belirtilmelidir. Şirketimizin birden fazla şubesi olup tüm şubelerdeki işlemler merkezi sunucuya iletilmelidir.

Doğal dille yazılmış gereksinimler belgesinden kullanım öykülerine geçilir; bu, yapılacak ilk çalışmadır.

### 10.2 Kullanım Öyküleri ve Amaçları

Slayttaki içerik (ekrandan, 02:30:00):

- Kullanım öyküleri: Programın yapacağı işleri ayrıntılı adımlarla ve belli kurallara uyarak anlatan belgeler.
- Kullanım öykülerinin oluşturulmasındaki amaç:
  - Ürünün sağlaması beklenen işlevleri ve ürünün çalışma ortamını belirlemek,
  - Son kullanıcı ve yazılım ekibi arasında bir anlaşma zemini belirlemek,
  - Son kullanıcı ve sistemin birbirleri ile nasıl etkileşimde bulunacağını açık ve belirsizlikten uzak olarak tanımlamak,
  - Doğrulama testleri için bir zemin oluşturmak.
- Bir kullanım öyküsünün bölümleri:
  - Giriş bölümü: Sistemin neyi hangi koşullar ve sınırlar içerisinde yapması gerektiğini anlatır.
  - Ana senaryo / Ana başarılı akış: Her şeyin yolunda gitmesi halinde yürütülecek eylemler.
  - Alternatif senaryolar: Bir aksilik olması halinde yapılacak işlemler.

"Anlaşma zemini" hem paydaşlar arasındaki çıkar çatışmalarının uzlaştırılması hem de "şu işler şu maliyetle yapılacak" diye bir sözleşme anlamında düşünülebilir. Müşteri sonradan "ben bunu böyle istememiştim" derse, yazılım ekibi "siz böyle demiştiniz, biz buna göre ilerledik; değişiklik süreyi uzatacaksa yeni sözleşme yapılmalı ya da masraf yansıtılmalı" diyebilir; kullanım öyküleri ekibin elini güçlendirir.

Sınama aşamasında birim sınamalarının yanında geçerleme ve doğrulama sınamaları da yapılacaktır. Sistemin nasıl çalışması gerektiği kullanım öyküleriyle bellidir: "böyle yapınca bu olacak, sonra şu olacak" diye adım adım denenir; çalışmıyorsa düzeltilmelidir. Bu yüzden kullanım öyküleri sınamaya önemli katkı sağlar.

Alternatif senaryolar, ana başarılı akıştan herhangi bir sapma, aksilik ya da varyasyon olduğunda neyin nasıl yapılacağını anlatır.

> **Hocanın vurgusu:** Kullanım öyküsü kurallarına hem sınavda hem de proje çalışmalarında tam olarak uyulması beklenir.

### 10.3 Satış İşlemi: Giriş Bölümü

Her kullanım öyküsünün bir adı olur; bu örnekte "Satış İşlemi". Bu ad, kullanım şemaları çizilirken elipslerin içinde yer alacaktır. Bir kimlik (ID) eklemek de yararlıdır, örneğin "Kullanım Öyküsü 25: Satış İşlemi"; özellikle izlenebilirlik tablolarında işe yarar.

Slayttaki giriş bölümü (ekrandan, 02:35:00):

- Birincil Aktör: Kasiyer.
- İlgililer ve İlgi Alanları:
  - Kasiyer: Doğru ve hızlı giriş ister, kasa açığı maaşından kesildiğinden ödeme hataları istemez.
  - Satıcı: Satış komisyonlarının güncellenmesini ister.
  - Müşteri: En az çaba ile hızlı hizmet ister. Ürün iadesinde kullanmak üzere fiş ister.
  - ...
- Ön Koşullar: Kasiyerin kimliği doğrulanır.
- Son Koşullar: Ödeme tahsil edilir. Satış kaydedilir. Fiş yazılır.
- Dikkat: Kullanım öyküsünde yer alacak her şey, verilen ilgi alanlarına giren şeyler olmalıdır.
- Aktör: Sistem ile etkileşimde bulunan varlıklar: insan; yazılım veya donanım.

Bu kullanım öyküsünde yer alan her şey bu senaryonun ilgi alanına girmelidir; gereksinimlerin bütünü göz önünde tutulur ama alakasız şeyler eklenmez.

**Aktör**, sistemle etkileşimde bulunan varlıklardır: insanlar olabileceği gibi, sistemin bir parçası olan ya da tümleşik çalışacağı başka sistemlerdeki yazılım veya donanım bileşenleri de olabilir. Bir senaryoda birden fazla aktör bulunabilir; bunlardan biri birincil aktör olarak belirlenmelidir. Birincil aktör senaryonun odak noktasındaki, senaryoda anlatılanların en fazlasını yapan aktördür (bu bir yazılım da olabilir). Hocanın önerisi: ana akış ve alternatif akışlar yazıldıktan sonra hepsini gözden geçirip olayın göbeğindeki aktörü o zaman kesinleştirmek; önce bir tahmin yazılıp sonra değiştirilebilir.

**İlgililer ve ilgi alanları** kısmında birincil aktör dahil bütün aktörler ve bu senaryodaki birincil çıkarları ya da öncelikli istekleri yazılır. Olumlu ve olumsuz yönde etkileyebilecek her şey yazılır, ama yalnız bu senaryoyla ilgili olanlar.

**Ön koşullar** bölümünde, ana akış başlamadan önce yapılmış olması gereken işler ya da sistemin içinde bulunması gereken durum anlatılır. Buradaki ön koşul kasiyerin kimliğinin doğrulanmasıdır: kasiyer satış yapmak için kasada oturum açmış olmalıdır. Bunun nasıl yapılacağı burada yazılmaz; ayrı bir kullanım öyküsünde ayrıntılandırılır ve en doğrusu ona bir referans vermektir (örneğin "Kullanım Öyküsü 28: Oturum Açma").

**Son koşullar** bölümünde, ana başarılı akış tamamlandıktan sonra sistemin içinde bulunduğu durum anlatılır: ödeme tahsil edilmiş, satış kaydedilmiş, fiş yazılmıştır.

Giriş bölümünün bütün alt alanlarının bulunması gerekir.

### 10.4 Satış İşlemi: Ana Öykü

Ana öykü, herhangi bir dallanma olmadan, her şeyin varsayılan ve en temel biçimde yürüdüğü, hikayenin başarıyla tamamlandığı akışı anlatır.

Slayttaki ana öykü (ekrandan, 02:40:00):

```text
Ana Öykü:
1.  Müşteri kasaya alacağı ürünlerle gelir.
2.  Kasiyer yeni bir satış işlemi başlatır.
3.  Kasiyer ürünün barkodunu girer.
4.  Sistem bir satış kanalı maddesi oluşturur. Bu maddede ürün tanımı,
    fiyatı ve toplam bedel (aynı maldan birden fazla alınmış olabilir) yer alır.
5.  Kasiyer 3. ve 4. adımları müşterinin alacağı tüm ürünler için tekrarlar.
6.  Sistem toplam bedeli KDV ile birlikte hesaplar.
7.  Kasiyer müşteriye toplamı bildirir ve ödeme ister.
8.  Müşteri ödemeyi yapar ve sistem ödemeyi tahsil eder.
9.  Sistem tamamlanan işlemin kaydını tutmayı tamamlar ve harici envanter
    ile mali sistemlere gerekli bilgileri gönderir.
10. Sistem fiş verir.
11. Müşteri ürünlerle birlikte ayrılır.
```

> **Ders sonrası not:** Slaytta 4. adımda "satış kanalı maddesi" yazıyor; örneğin kaynağındaki karşılığı ve maddenin içeriği (ürün tanımı, fiyat, miktara göre toplam bedel) düşünüldüğünde büyük olasılıkla "satış kalemi" (sale line item) kastedilmektedir.

> **Hocanın vurgusu:** Ana öykünün her maddesi mutlaka numaralandırılmalıdır; Word'deki gibi madde imleriyle (bullet) yazılmamalıdır. Bunun iki nedeni vardır: bir adımdan başka bir adıma geçiş (genelde döngü) yazılabilmesi ve alternatif akışların ana öyküdeki adım numarasına referans vermesi. Senaryoda döngü olmasa bile numaralar beklenir; hem standart bunu ister hem de değerlendirmede buna bakılır.

5. adım bir döngü kurar: alınacak ürün olduğu sürece 3. ve 4. adımlar tekrarlanır, ürün kalmayınca 6. adıma geçilir. Numara verilmeden bu döngü yazılamaz.

4. adımdaki maddede toplam bedelin de bulunmasının nedeni aynı maldan birden fazla alınmış olabilmesidir. Hoca bu ayrıntının gerekliliğinin analiz ve tasarım aşamalarında daha çok konuşulacağını, alan bilgisi olmasa bile nesneye yönelik modelleme bilgisiyle hissedilebilecek bir ayrıntı olduğunu söyler.

2. adım ("yeni bir satış işlemi başlatır") nasıl yapılır, bir tuşa mı basılır? Bu yazılabilir, ama fazla teknik olacaksa burada yazılmaz; gerekirse sıra (sequence) ya da etkinlik (activity) şeması çizilip buradan ona bağlantı verilir.

**Etken cümleler.** Ana öyküdeki bütün cümleler etken, yani öznesi belli cümlelerdir; edilgen cümle yoktur. Çünkü her adımın hangi aktör tarafından yapılacağı net ve kesin olarak belirtilmelidir. "Yeni bir satış işlemi başlatılır" yazılırsa "kim başlatır?" sorusu açıkta kalır; burada kasiyer başlatır. Self-servis bir kasa olsaydı müşteri başlatırdı, ama o ayrı bir kullanım öyküsünün konusudur.

### 10.5 Satış İşlemi: Alternatif Öyküler

Ana öyküdeki adımlar her zaman böyle yürümez; olabilecek varyasyonlar ana öyküye yazılmamalı, alternatif öykülerde yazılmalıdır. Buradaki numaralandırma bir adım daha karmaşıktır ve uyulması zorunludur.

Slayttaki alternatif öyküler (ekrandan, 02:45:00):

```text
Alternatif Öyküler:
3a. Geçersiz barkod
    1. Sistem uyarı mesajı verir ve kayıt girişini reddeder.
3-7a. Müşteri bir kalem malı alışverişten çıkartmak ister.
    1. Kasiyer satıştan çıkarmak üzere ürünün barkodunu okutur.
    2. Sistem güncel toplamı bildirir.
...
```

Numaraların okunuşu:

- "3a": ana senaryonun 3. adımında (kasiyerin barkodu girmesi) gerçekleşebilecek, alfabenin ilk harfiyle gösterilen ilk alternatif. "a" harfi birinci öncelikli olduğu anlamına gelmez, numarayla birlikte okunur. Barkod tanınmazsa ne olacağı burada anlatılır.
- "3-7a": ana senaryonun 3. ile 7. adımları arasında (ikisi de dahil) herhangi bir adım sırasında olabilecek ilk alternatif.
- Aynı adımda başka bir alternatif varsa "3b", aynı aralıkta başka bir alternatif varsa "3-7b", 4. ile 6. adımlar arasında olabilecek bir alternatif varsa "4-6a" yazılır.

3a'daki tek alt adım iki adıma da bölünebilirdi ("1. Sistem uyarı mesajı verir. 2. Sistem kayıt girişini reddeder."). Tek bir alt adım bile olsa numaralandırılmalıdır, çünkü alternatifin içinde birden fazla işlem olabilir.

3-7a için hocanın günlük hayattan örnekleri: kasiyer bir ürünü okutur ve müşteri "üç tane su istemiyordum, birini iptal edelim" der; kasanın yanındaki ürünlerden biri (örneğin bir paket mendil) düşmüş, kasiyer onu da alacağınızı sanıp okutmuştur; ya da toplam söylendiğinde müşterinin yanındaki para ya da kart limiti yetmez ve bazı kalemleri çıkarıp yeni toplamı ödemeye karar verir. Bunların hepsinde ne yapılacağı kullanım öyküsünde eksiksiz yer almalıdır.

Slaytta ayrıca kullanım öykülerinin grafik gösterimine geçiş yer alır (ekrandan, 02:45:00): kullanım öyküleri ayrıntılı ve uzun belgelerdir; yazılımın yapacağı işlerin özet gösterimi için kullanım şemaları (use-case diagrams) çizilir.

### 10.6 Kullanım Öyküsü Yazarken İpuçları

> **Hocanın vurgusu:** Bir öykü yazarken her şeyi ana öyküye doldurmayın; mutlaka alternatif öykü yazmanız ve numaralandırma kuralına uymanız beklenir, hem sınavda hem projede.

Sınavda ve projede, birkaç paragraflık bir metin ve "şunlar yapılmalıdır" maddelerinden yola çıkarak kullanım öyküleri yazılacaktır. Ana öyküde hiçbir varyasyon bulunamazsa, her adım için "bu adımda farklı ne olabilir?" diye düşünülmelidir; bunu if-else gibi düşünmek işe yarar. Gereksinim metninde çoğu zaman bir ipucu yakalanır; yakalanamazsa makul bir varsayım eklenip alternatif yazılabilir. Projede bu tür varsayımlar ayrıca "kabuller ve kısıtlar" bölümüne yazılır; bu, farklı kişilerin ve grupların yanıtlarını da birbirinden ayırır.

Hoca, giriş bölümündeki her alanın (birincil aktörün belirlenmesi ve doğru belirlenmesi, ilgililer ve ilgi alanları, ön ve son koşullar), ana öykünün ve numaralandırılmasının, alternatif akışın ve onun numaralandırılmasının ayrı ayrı değerlendirildiğini, çünkü gerçek bir proje belgesinde hepsinin önemli olduğunu söyler.

## Örnek Sorular

**Soru 1** (ekrandan, 02:10:00): Müşteri ne istediğini bilmez mi? Gereksinimler zaten belli değil mi?

> **Çözüm (derste verildi):** Çoğunlukla müşterinin kafasında yalnız genel bir fikir vardır; bunun ayrıntılı biçimde açığa çıkarılması gerekir. Yoruma açık, ayrıntıları kesin çizgilerle belirlenmemiş gereksinimler projenin başarısızlığına davetiye çıkarır ve kesin belirlenmiş gereksinimler bile zamanla değişebilir. Bu yüzden gereksinim mühendisliği gerekli bir etkinliktir.

**Soru 2** (derste sözlü, 01:30:16): Artefact (artifakt) ne demektir?

> **Çözüm (derste verildi):** Yazılım geliştirme sırasında kod dışında ortaya çıkarılan her türlü metin ve şemadır: kullanım öyküsü metinleri, UML şemaları, yapılandırma dosyaları, mimari şemalar, sunum olarak hazırlanmış özetler, teknik gözden geçirme sonuç belgeleri vb.

**Soru 3** (derste sözlü, 01:54:36): Pazarlık aşaması ne zaman biter?

> **Çözüm (derste verildi):** Tüm paydaşların razı olduğu bir gereksinimler listesi elde edildiğinde tamamlanır; ardından tanımlama (specification) aşamasına geçilir.

**Soru 4** (derste sözlü, 01:02:01): CMMI'da belli bir düzeye erişebilmek için CASE araçları kullanılabilir mi, hangi düzeyde?

> **Çözüm (derste verildi):** Düzey 1'de araç kullanımına dair standart, yazılım ölçütü ve yeniden kullanım yoktur. Düzey 2'de araç kullanımına yönelik proje standartları, araç eğitimi, takım tabanlı araçların tümleştirilmesi ve sınırlı tasarım/kod yeniden kullanımı vardır (ekrandan, 01:05:00). Düzey 3'te organizasyona ait ortak veri deposu, yeniden kullanım kütüphanesi ve toplanıp saklanan ölçütler; Düzey 4'te ölçütlerin analizi; Düzey 5'te her şeyin sürekli değerlendirilip iyileştirilmesi beklenir.

**Soru 5** (ekrandan, 02:45:00): Satış İşlemi alternatif öykülerinde "3a" ve "3-7a" numaraları ne anlama gelir?

> **Çözüm (derste verildi):** "3a", ana öykünün 3. adımında (barkod girilmesi) olabilecek ilk alternatiftir (geçersiz barkod). "3-7a", ana öykünün 3. ile 7. adımları arasında (dahil) herhangi bir adımda olabilecek ilk alternatiftir (müşterinin bir kalemi alışverişten çıkarmak istemesi). Aynı yer için ikinci alternatifler "3b" ve "3-7b" diye, 4. ile 6. adımlar arasındaki bir alternatif "4-6a" diye yazılır.

## Dersin Toparlaması

Ders, yazılım geliştirme süreçlerinin olgunluğunun bağımsız kurumlarca nasıl belgelendiğiyle başladı. CMMI, PMI, ISO 9001:2015 ve yazılıma özel ISO/IEC 90003:2018 karşılaştırıldı; CMMI'nın 0-5 arası düzeyleri, CMMI-DEV/SVC/ACQ alanlarının v2.0 ile birleşmesi, v1.3 ile çevik süreçlerin desteklenmesi ve her düzeyin CASE araçlarından beklentisi ele alındı. Büyük müşterilerin asgari beklentisinin Düzey 3 olduğu vurgulandı.

İkinci bölümde gereksinim mühendisliğine geçildi: SRS belgesi ve standartları, yedi adım (başlangıç, bilgi toplama, işleme, pazarlık, tanımlama, doğrulama, yönetim), normal/beklenen/heveslendirici gereksinimler ve izlenebilirlik tabloları anlatıldı. Son bölümde nesneye yönelik çözümlemeye başlandı: uygulama alanının çözümlenmesi ve müşterinin dilinden konuşmanın önemi tartışıldı, Craig Larman'ın NextGenPOS örneği üzerinden "Satış İşlemi" kullanım öyküsünün giriş bölümü, numaralı ana öyküsü ve alternatif öyküleri incelendi. Sonraki aşamada kullanım öykülerinin grafik gösterimi olan kullanım şemalarına (use-case diagrams) ve aynı örnek üzerinden çözümleme ve tasarım çalışmalarına devam edilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
