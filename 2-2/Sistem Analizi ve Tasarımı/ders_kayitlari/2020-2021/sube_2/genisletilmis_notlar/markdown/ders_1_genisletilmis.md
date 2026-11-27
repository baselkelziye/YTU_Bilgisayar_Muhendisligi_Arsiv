# Ders 1 Genişletilmiş Notu: Giriş, Sistem Kavramı ve Bilgi Sistemleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Konu Akışı
- 2. Sistem Kelimesinin Anlamı
- 3. Bilgi: En Önemli Kaynak
- 4. Bilgi Sistemi ile Bilgisayar Programının Farkı
- 5. Sistemin Tanımı
- 6. Sistemin Temel Özellikleri
- 7. Sistem ve Ortam
- 8. Sistem Örnekleri: Ev Sineması ve Restoran
- 9. Bilgi Sistemi ve Bileşenleri
- 10. Bilgi Sistemi Örnekleri: Fabrika ve Öğrenci Bilgi Sistemi
- 11. Genel Sistem Teorisi
- 12. Kendi Başına İnceleme ve Dersin Bakış Açısı
- Örnek Sorular

## 1. Dersin Konu Akışı

Dersin ilk yarısı tanıtımla geçti. Hoca dönem boyunca işlenecek konuları iki tablo halinde gösterdi (ekrandan, 00:15:00 ve 00:20:00). Tarih ve sınav satırları dışarıda bırakılınca konu sırası şöyledir:

| Sıra | Konu |
|---|---|
| 1 | Giriş, ders planı, genel bilgiler, sistem tanımı |
| 2 | Sistem tipleri, tarafları, sistem geliştirme süreci (Waterfall) |
| 3 | Ön inceleme, fizibilite çalışmaları |
| 4 | Fizibilite çalışmaları, zaman fizibilitesi |
| 5 | Sistem analizi: veri toplama, iş analizi, kullanım senaryoları |
| 6 | Sistem analizi: veri modelleme, fonksiyonel çözümleme |
| 7 | Sistem analizi: nesneye yönelik çözümleme |
| 8 | Sistem tasarımı: mimari tasarım (yapı diyagramları, ardışıl diyagramlar) |
| 9 | Sistem tasarımı: girdi, çıktı, veri yapısı, arabirim tasarımları |
| 10 | Veritabanı tasarımı, kodlama, test süreçleri, yeni sisteme geçiş, bakım, destek süreçleri |
| 11 | Sistem analizi ve tasarımı örnek vaka çalışması |

Hoca konuları şöyle açtı:

- **Sistem tipleri ve taraflar:** Ne tür sistemler vardır, neden kategorize edilirler, birbirlerinden farkları nedir, kimlere hizmet ederler, kimlerden hizmet beklerler? Bilgi sisteminin tarafları (paydaşları) kimlerdir, ne alırlar, ne verirler, rolleri ve sorumlulukları nelerdir?
- **Sistem geliştirme süreci:** Bir bilgi sistemi geliştirirken doğrudan kodlamaya mı girilir, yoksa öncesinde ve sonrasında başka işler mi yapılmalıdır; bu işler hangi mantıksal sırayla birbirini izlemelidir? Bu derste temel olarak şelale (waterfall) modeli incelenir; alternatiflerine kısaca değinilir, ayrıntıları yazılım mühendisliği dersinin konusudur.
- **Ön inceleme ve fizibilite:** Bu sistem yapılabilir mi, mevcut kaynaklarla yapılabilir mi, nelerin eklenmesi ya da değiştirilmesi gerekir? Bu sorular farklı fizibilite (yapılabilirlik etüdü) başlıkları altında incelenir. Bunlardan biri, bütün süreci en baştan kestirmeye ve modellemeye çalışan zaman fizibilitesidir; bir vaka çalışması üzerinden uygulamalı olarak görülecektir.
- **Sistem analizi:** Veri ve bilgi kaynakları nasıl toplanır? Çözülecek iş nedir, onu dijital ya da daha iyi hale getirmek için önce nasıl anlarız (iş analizi)? Anlaşılan iş ekip ve diğer paydaşlarla nasıl paylaşılır? Nesneye yönelik geliştirmede bu iş use case'lerle (kullanım senaryolarıyla) modellenir.
- **Analiz modeli:** Problem uzayı ve veri nasıl modellenir? Geleneksel (ör. C gibi dillerle) bir süreçte işlevsel (fonksiyonel) çözümleme yapılır ve **veri akış diyagramları** kullanılır. Hoca bunun algoritma akış diyagramı olmadığını, daha üst seviyeli ve soyut bir kavram olduğunu belirtti. Nesneye yönelik çözümlemede ise bir modelleme dili ve onun diyagramları kullanılır.
- **Tasarım:** Mimari tasarım hem geleneksel hem nesneye yönelik yaklaşımla yapılır; ardından girdi ve çıktı tasarımı, veri yapılarının tasarımı, diğer sistemlerle ve paydaşlarla konuşan arabirimlerin ve ön yüzlerin tasarımı gelir.
- **Gerçekleştirme ve sonrası:** Bu ders kapsamında yetecek kadar veritabanı tasarımına giriş; kodlamada dikkat edilecekler; test süreçleri (yapılanın doğruluğu nasıl gösterilir, hangi test neyi karşılar); yeni sistemin devreye alınması (mevcut bir sistemin yerine geçiş ya da sıfırdan başlama); bakım ve destek süreçleri.
- **Vaka çalışması:** Örnek bir problem alınıp önce fizibilitesi (belki zaman fizibilitesi de), sonra iş analizi, analiz modeli ve tasarımı birlikte yapılacaktır.

## 2. Sistem Kelimesinin Anlamı

Asıl konuya "Sistem nedir?" sorusuyla girildi. Hoca önce sözlüğe baktı. Sözlükte sistem Fransızca kökenli bir isimdir ve şu anlamları vardır:

- **Düzen:** Bir sonuç elde etmeye yarayan yöntemler düzeni. Demek ki bir şeyler bir araya gelir ve bir düzen içinde olurlar.
- **Yol, yöntem.**
- **Bir aracı oluşturan düzen, düzenek, tertibat:** Sözlükteki örnek "fren sistemi"dir. Arabada fren sistemi birlikte çalışan bir düzenektir ve belli bir iş yapar: fren yapıldığında arabayı yavaşlatır ve durdurur.
- **Model, tip.**
- **Dizge:** Sıralama, arka arkaya gelen olaylar silsilesi.

<!-- BELİRSİZ: Sözlük slaytının karesi yok; anlamlar altyazıdan alındı. -->

Bu anlamlardan çıkan ortak fikir şudur: sistem, bir düzen içinde çalışan, çeşitli parçalardan oluşan, bir işe yarayan, bir çıktı üreten ya da bir sorunu çözen, bir hizmet veren yapıdır.

## 3. Bilgi: En Önemli Kaynak

Hoca "Giriş" slaytını şöyle anlattı (ekrandan, 00:40:00):

- İnsan ve hammadde kaynakları önemlidir.
- Günümüzde bilgi en önemli kaynaktır.
- Bilginin doğru kullanımı rekabet gücünü artırır.
  - Bilgi üretimi, dağıtımı, işlenmesi, güvenliği, depolanması önemlidir.
  - İnternet, elle üretilen verinin çok daha fazlasını üretiyor.
  - Verilerin organizasyonu, kullanım maliyetleri arttı.
- Çözüm? → Bilgi sistemleri.
- Bilgisayar programından farkı ne?

Elinizde bilgi olsa bile onu doğru kullanmıyorsanız faydasını görmezsiniz. Hem bilgiye sahip olmak hem onu doğru kullanmak, benzerlerinizle karşılaştırıldığınızda sizi öne çıkarır.

### 3.1 Bilginin üretimi ve veri-bilgi farkı

Bilgiyi bilen kaynaklar elle üretebilir; ama artık makineler de üretir. Nesnelerin İnterneti (IoT) ile sürekli veri üretilir. Burada veri ile bilgi arasındaki fark önemlidir: **anlamlandırılmış veriye bilgi**, anlamlandırılmamış olana **veri** denir.

Hoca bunu bir hava istasyonu örneğiyle açıkladı. İstasyon saniye saniye sıcaklık, nem, rüzgâr gibi parametreleri gönderir; bir saatte 3600 sıcaklık ve nem değeri gelir. Bu veri üretilmiş ve internet üzerinden dağıtılmıştır. Bunları ekranda yalnızca "arttı, azaldı" diye bir grafik olarak göstermek, sistem çözümü olarak çok bir şey ortaya koymaz. Ama gidişata bakıp "nem böyle artıyor, yarın yağmur yağabilir" ya da "yarın kuvvetli rüzgâr çıkabilir, tarım yapıyorsanız önleminizi alın" gibi amaca yönelik uyarılar üretirseniz, veriyi işlemiş, bilgiye dönüştürmüş ve doğru kullanmış olursunuz.

### 3.2 Güvenlik, depolama ve maliyet

Bilginin güvenliği her zaman sağlanmalıdır. Özellikle insanlarla ilgili verilerle çalışılıyorsa kişisel verilerin korunması ve bunun kanunla gelen yaptırımları (KVKK) önem kazanır. Depolama da ayrı bir problemdir: veri yerelde mi, bulutta mı, kopyalı mı kopyasız mı, nasıl bir ortamda tutulacak?

Elle çok veri üretiriz (sosyal medyaya fotoğraf ve yazı girmek gibi), ama makineler ve sensörler bundan çok daha fazlasını otomatik üretir. Bunun bir maliyeti vardır. Hoca bulut hizmetlerinde maliyetin katlanarak arttığını, kullanımı iki katına çıkarınca harcamanın iki katından fazla arttığını söyledi.

> **Ders sonrası not:** Hoca bulutta kullanım iki katına çıkınca maliyetin iki katından fazla arttığını söyledi. Bulut fiyatlandırması büyük olasılıkla çoğu hizmette kullanımla doğrusal ya da hacim indirimiyle daha yavaş artar; maliyetin hızlı büyümesi daha çok veri hacminin ve ek hizmetlerin (yedekleme, veri aktarımı vb.) artmasından kaynaklanır.

Sonuç: bilgiyi doğru kullanmak için onu **bilgi sistemleriyle** işlemek ve hizmet sunan modüller ya da yapılar halinde kullanıma sunmak gerekir.

## 4. Bilgi Sistemi ile Bilgisayar Programının Farkı

Önceki derslerde (bilgisayar bilimlerine giriş, yapısal programlama, veri yapıları gibi) bir problem için algoritma geliştirilip belirli veri yapılarıyla birleştirilerek küçük bir problemi çözen programlar yazıldı. O halde bilgi sistemi geliştirmek, bir program yazmaktan neyle ayrılır?

En basit fark **boyuttur**. Bir algoritma ve onun kodu, verilen tekil bir problemi çözer; belki 100 ya da 1000 satır kodla iş görülür. Bilgi sistemi ise çok daha bütüncül, hizmet sunan büyük bir yapıdır: binlerce, milyonlarca satır kod, onlarca, yüzlerce algoritma gerekir ve bunların bir arada doğru çalışması sağlanmalıdır. Modüler, yeni modüllerin eklenebileceği bir yapı tasarlanmalı; veri belki ortak, belki ayrı ayrı kullanılmalıdır.

Yani hem boyut hem de çözülen problemin **çok yönlülüğü** açısından bilgi sistemi, bir program yazmaktan çok daha fazlasıdır ve bir **süreç yönetimi** gerektirir. Çok daha büyük problemler ancak bilgi sistemleriyle çözülebilir.

## 5. Sistemin Tanımı

Hoca tanımı slayttan verdi ve anahtar kelimelerin altını çizdi (ekrandan, 00:50:00):

> Belli bir **amacı** gerçekleştirmek için, bir arada çalışan, birbiriyle **ilişkili** olan **parçalardan** oluşan, **girdi** ve **çıktıları** olan, **sınırları** belirlenmiş bir bütün yapı/oluşum/çözüm.

Buna göre bir şeyi sistem olarak tanımlayabilmek için:

- Girdileri ve çıktıları olmalı ve bunlar bir amaç doğrultusunda alınıp verilmelidir.
- Bu amacı gerçekleştirmek için bir arada çalışan, birbiriyle ilişkili parçaları olmalıdır.
- Sınırları mutlaka belirlenmiş olmalıdır.

> **Hocanın vurgusu:** Sınırın belirlenmesi belki de en önemli hususlardan biridir. Neyin sistemin içinde, neyin dışında olduğunu belirlemek, sistemi tasarlarken en başta karar verilmesi gereken noktalardan biridir.

### 5.1 Sistem şekli

Slayttaki şekil, akılda kalsın diye bir sistemi "amorf bir hayvan" gibi çizer (ekrandan, 00:50:00). Şekildeki etiketler ve anlamları:

- **ORTAM:** Kapalı eğrinin dışı. Sistemler her zaman bir ortamda yer alır.
- **SINIR:** Kapalı eğrinin kendisi; çizginin içindeki kısım sistemdir.
- **GİRDİ:** Ortamdan sisteme giren kalın ok. Ortamdan alınanlar girdidir.
- **ÇIKTI:** Sistemden ortama çıkan kalın ok. Ortama sunulanlar çıktıdır.
- **BİLEŞEN:** Sınırın içindeki küçük şekiller; birbiriyle ilişki içinde bir arada çalışan parçalar.
- **İLİŞKİ:** Bileşenler arasındaki çift yönlü ok.
- **ARABİRİM:** Sistemin ortamla ya da başka sistemlerle iletişime geçtiği, bir şeyler alıp verdiği noktalar.

Arabirim her sistemde olmak zorunda değildir, ama özellikle bilgi sistemlerinde artık olmazsa olmaz parçalardan biridir. Sınırın dışında kalan bir bileşen, sistemin bileşeni değildir; sistem ondan ancak bir arabirim aracılığıyla hizmet alabilir.

## 6. Sistemin Temel Özellikleri

Hoca temel özellikleri tek tek tanımladı (ekrandan, 00:55:00):

| Özellik | Slayttaki tanım |
|---|---|
| Bileşenler | Sistemi oluşturan parçalar |
| Değişkenler | Değişik değer alan özellikler |
| Parametreler | Sabit değerler |
| İlişkiler | İlk üç madde arasındaki bağlantılar |
| Sınır | Sistem için ortam ayracı |
| Arabirim | Ortam veya alt sistemlerle karşılaşma noktası |
| Kısıtlar | Değişken değerleri ve kaynak tahsis sınırlamaları |
| Ölçüt | Hedef-amaçların değerlendirme standardı |
| Ortam | Sistem dışındaki her şey |
| Geri besleme | Çıktı kontrolü ve ölçme-değerlendirme ile girdiler ve sistem üzerinde iyileştirme yapma aracı |

Açıklamalar:

- **Bileşenler** sistemin içinde işleyen parçacıklar, alt parçalardır.
- **Değişkenler** programlama dillerindeki değişkenlerle aynı mantıktadır: sistemde farklı değerler alabilen ve bunları tutan özelliklerdir.
- **Parametreler** sistemdeki parametrik tanımlar, yani değişmeyen sabit değerlerdir.
- **İlişkiler** bileşenlerin değişkenlerle ve parametrelerle olan bağlantılarıdır.
- **Sınır** sistemi ortamdan ayıran çizgidir: sistemin nerede başlayıp nerede bittiğini, neleri kapsadığını, neleri (ör. bir arabirimden alınan hizmetleri) dışarıda bıraktığını belirler.
- **Arabirim** ortamla, alt sistemlerle ya da dış sistemlerle karşılaşılan, bilgi ya da veri alışverişi yapılan noktalardır.
- **Kısıtlar** değişkenlerin alabileceği değerleri sınırlayabilir: "yalnız belirli dosya tipleriyle çalışırım, başka dosya tipini girdi olarak kabul etmem." Kaynak tahsisiyle ilgili de olabilir: "sistem 1024 MB'den fazla bellek kullanmayacaktır."
- **Ölçüt** sistemin amacına, hedeflerine ne kadar eriştiğini, performansını değerlendirmek için konan standartlardır. Örneğin bir öğrenci ya da ders kayıt sisteminin saniyede 100 kayıt mı, 1 milyon kayıt mı işleyeceği. Sistemin "hedeflendiği gibi çalışıyor" ya da "beklentiyi karşılamıyor" kararının verildiği eşik değerleridir.
- **Ortam** sistemin tümleyenidir: sistem dışındaki her şey.
- **Geri besleme** çıktıların kontrol edilip ölçme-değerlendirme yöntemleriyle girdiler ya da sistemin kendi işlemleri (bileşenleri) üzerinde iyileştirme yapılmasıdır. Hizmet ya da çıktı kalitesini artırır, sistemin daha yüksek ölçütlere erişecek şekilde kendini değiştirmesini ve geliştirmesini sağlar.

> **Hocanın vurgusu:** Kısıtlar ileride işlevsel olmayan gereksinimlerimizi oluşturacak; bunların tasarımı nasıl zorladığı ve etkilediği analiz safhasında tartışılacaktır.

> **Hocanın vurgusu:** Geri besleme her kaynakta temel özellik olarak kabul edilmez, ama hocaya göre artık olmazsa olmazlardan biridir.

## 7. Sistem ve Ortam

Slayttaki maddeler (ekrandan, 01:00:00):

- Sistem ortama bağlıdır.
  - Aralarında doğrudan veya dolaylı ilişki vardır.
- Sistem ortamda değişiklik yapabilir.

Sistem bulunduğu ortamı iyi yönde de, kötü yönde de değiştirebilir. Slayttaki şekil iç içe kutulardan oluşur:

```text
ŞEHİR
└── CADDE
    └── BİNA
        ├── ISITMA SİSTEMİ
        ├── ENERJİ SİSTEMİ
        ├── GÜVENLİK SİSTEMİ
        ├── AYDINLATMA SİSTEMİ
        └── SU SİSTEMİ
```

Hoca bunu fakülte binası üzerinden anlattı:

- **Bina** bir sistemdir; içinde alt sistemler vardır.
- **Isıtma sistemi** kendi içinde birçok bileşene sahiptir. Ortamdan doğalgaz alır; bunu aslında başka bir sistemden, bir arabirim üzerinden alır. Suyu ısıtır, dolaştırır ve çıktı olarak ısı verir. Böylece ortamında, yani üst sistemi olan binada değişiklik yapar.
- **Güvenlik sistemi:** Duman dedektörleri ortamdaki dumanı girdi olarak alır, çıktı olarak alarm çalar: "Tehlike var, binayı boşaltın."
- **Enerji sistemi:** Aydınlatma sistemi elektrik sisteminin alt sistemi olarak düşünülebilir; prizler, jeneratör, kesintisiz güç kaynağı (UPS) gibi alt sistemler de onun içindedir. Hoca slayttaki çizimin bu açıdan tartışılabileceğini söyledi.
- **Su sistemi:** Musluklardan su akmasını sağlar. Bu sistemin bileşenlerinin, kullanıcılardan gelen geri beslemelerle iyileştirilmesi geri beslemenin gerçek bir örneğidir.

Binanın kendisi de bir hizmet verir: barınma ya da eğitim için gereken altyapıyı sağlama. Birkaç bina (A, B, C, D blok gibi) bir araya gelip bir fakülteyi oluşturur; fakültenin girdileri aslında alt sistemlerinin girdileridir. Fakülteler bir araya gelip kampüsü oluşturur. Bu zincir istendiği kadar yukarı çıkarılabilir: kampüs bir ilçede, ilçe bir şehirde, şehir bir bölgede, bölge bir ülkede, ülke bir kıtada, kıta dünyada, dünya güneş sisteminde.

Özetle her ortam, kapsadığı sistemler için bir ortamdır ve alt sistem-üst sistem şeklinde **hiyerarşik** bir yapı vardır.

## 8. Sistem Örnekleri: Ev Sineması ve Restoran

### 8.1 Ev sinema sistemi

Slaytta televizyon, hoparlörler, oynatıcılar ve iki koltuk bulunan bir oda fotoğrafı vardır (ekrandan, 01:05:00).

- **Bileşenler:** televizyon ya da görüntü monitörü, amfi, DVD ve başka bir oynatıcı, hoparlörler, koltuklar.
- **Sınır:** Odanın duvarları. (Hoca "120 desibel demeyin" diye şaka yaptı: sınır bir ses düzeyi değil, odanın kendisidir.)
- **Odadaki başka bir sistem:** Tavandaki spot lambalar, odada bir aydınlatma sistemi de olduğunu gösterir.

**Soru:** Koltuk bir sistem olarak düşünülebilir mi? **Cevap:** Olabilir (bir öğrenci "konfor sistemi" dedi), ama bu modelde koltuk sistem olarak modellenmeyecek kadar küçük bir parçadır; ev sinema sisteminin bir **bileşenidir**.

Buna karşılık görüntü sistemi hem bir bileşen hem de kendi içinde tam bir sistemdir: LED ekranı, ekranı süren sürücü kartı, gelen sinyali işleyen başka bir kartı vardır. Oynatıcı da öyledir:

- **Girdi:** elektrik, DVD ya da Blu-ray disk.
- **İşlem:** kodlamayı çözer, görüntü sinyaline dönüştürür, belli bir formatta kabloya verir.
- **Çıktı:** ürettiği sinyal; bunu bir arabirimle (ör. HDMI) başka bir sistem olan görüntü sistemine aktarır.

Hoparlörler elektrik sinyalini girdi olarak alır, ses sinyaline dönüştürür. Bileşenleri (kolon, tiz ve bas hoparlörleri, vidalar, ayaklar, duvara/tavana asma aparatları) modelden modele değişir. Yapı yine hiyerarşiktir ve parçalar arabirimlerle konuşur.

İzleyici de bu sistemin bir tarafıdır: sesi ve görüntüyü alır, işler; çıktısı filme göre gözyaşı ya da kahkaha olabilir. Aynı anda izleyicinin kendi içindeki sistemler de çalışır (elindeki patlamış mısırı girdi olarak alıp işler). Yani bir sistemin tarafı, eş zamanlı olarak başka bir sistemin içinde de taraf olabilir ve sistemler paralel çalışabilir.

### 8.2 Sistem alternatifleri ve gereksinimler

Büyük televizyon bileşeni çıkarılıp yerine **projeksiyon ve perde** bileşenleri konabilir. Bu, aynı işi yapan ama farklı alt sistemlerle işleyen bir sistem alternatifidir. Her işi yapan tek bir sistem olmak zorunda değildir.

Hangi alternatifin seçileceğini **gereksinimler** belirler. "Ekran 65 inç ve arkadan aydınlatmalı olacak" diye bir gereksinim varsa televizyon kullanılmak zorundadır; "görüntü olabilecek en büyük boyutta olacak" deniyorsa projeksiyon tercih edilebilir. İstekler değiştikçe oluşturulan sistem ve bileşenleri de değişir.

### 8.3 Restoran

<!-- BELİRSİZ: Restoran slaytının karesi yok; aşağıdaki liste altyazıdan alındı. -->

Hemen her mekanizma bir sistem olarak modellenebilir. Restoran örneğinde:

- **Bileşenler:** depo, mutfak, büro, müşteri hizmetleri, yemek salonu.
- **Girdiler:** malzemeler (sebze, meyve, et), para, işletilen aletler.
- **Çıktı:** yiyecekler.
- **Taraflar:** içeride yöneticiler, aşçılar, garsonlar, müşteri hizmetleri çalışanları (vale, yer gösteren); dışarıda tedarikçiler ve müşteriler.

Herhangi bir yapı girdileri, çıktıları, bileşenleri, sınırı ve arabirimleriyle modellenirse bir sistem olarak modellenmiş olur; ama mutlaka **amacı** ve **hizmeti** de söylenmelidir.

## 9. Bilgi Sistemi ve Bileşenleri

### 9.1 Tanım

Slayttaki tanım (ekrandan, 01:10:00):

> İşletmenin ihtiyaçlarını desteklemek için veri toplayan, işleyen, depolayan; insan, veri, süreçler ve bilgi teknolojilerinin etkileşimde bulunduğu yapı.

Bilgi sistemleri genellikle işletme (business) odaklıdır, ama her zaman öyle olmak zorunda değildir. **Süreçler**, belli bir sırayla yapılan işler, yani iş akışlarıdır. Bilgi teknolojileri her türlü teknoloji olabilir. İnsan, veri, süreç ve bilgi teknolojileri bileşen olarak alınıp etkileşime sokulduğunda ve veriler toplanıp işlenip depolanarak hizmet ya da çıktı üretildiğinde bir bilgi sistemi ortaya çıkar. Kısaca: veri alıp bilgi üreten, temeli bilgi olan sistemlere bilgi sistemi denir.

### 9.2 Beş bileşen ailesi

Slayttaki liste (ekrandan, 01:15:00):

- **Donanım kaynakları:** Sunucu, bilgisayar, monitör, klavye, yazıcı, tablet vs. sayısal ürünler.
- **Yazılım kaynakları:** Veri düzenleme, işleme, analiz programları; bunlara ait süreçler ve yordamlar.
- **İnsan kaynakları:** Bilgi sistemi sahibi, tasarlayanlar, kuranlar, kullananlar.
- **Veri kaynakları:** Sistemin kullandığı ve ürettiği verileri tutan veritabanı ve bilgi tabanı.
- **Ağ kaynakları:** İşletme içi ve dışı birimlerin bilgi sistemine bağlanma yapıları.

Ayrıntılar:

- **Donanım:** Bilgisayarlar ve bağlı cihazlar, tabletler, barkod okuyucular, yazıcılar. Bilgi sistemi denince yalnız yazılım anlaşılmamalıdır; yazılımla birlikte çalışan donanım da sistemin içindedir.
- **Yazılım:** Yalnız bizim yazdığımız modüller ve kodlar değil; veriyi düzenlemek, işlemek, analiz etmek için kullanılan hazır uygulamalar, servisler, paketler, kütüphaneler, hatta hazır bir sistem de bilgi sisteminin bileşeni ya da alt sistemi olabilir.
- **İnsan:** Bilgi sisteminin tarafları: sahibi, işletenleri, tasarlayanları, kuranları, kullananları, bakımını yapanları. Bazı insan görevleri yazılım ya da donanım bileşenleriyle yer değiştirebilir. Örneğin sistemin işlemci, bellek kullanımını ve ağ trafiğini bir kişi izleyebilir; ya da bu iş kural tabanlı veya yapay zekâ destekli bir yazılım bileşenine verilebilir. Ağ trafiği normalde yaklaşık 10 megabit/saniye civarında, 8-13 megabit/saniye arasında dalgalanıyorsa ve bir anda 50 megabit/saniyeye çıkarsa, bu bileşen bir sorun olabileceğini düşünüp alarm üretebilir.
- **Veri:** Sistemin kullandığı ya da ürettiği verileri tutan, okunan ve yazılan yerler: bilgi tabanı, veritabanı, NoSQL, büyük veri ortamları; bulut da sonuçta bir veri ya da bilgi tabanıdır.
- **Ağ:** Alt sistemlerin, dış sistemlerin ve bileşenlerin birbiriyle konuştuğu bağlantılar; hem işletme içindeki hem dışındaki birimlerin bilgi sistemine bağlandığı yapılar.

> **Hocanın vurgusu:** Bilgi sistemi denince yalnız kod, yalnız bir program ya da yalnız bir yazılım anlaşılmamalıdır. Donanım, yazılım, insan, veri ve ağ taraflarının hep birlikte bir bilgi sistemini oluşturduğu göz ardı edilmemelidir.

## 10. Bilgi Sistemi Örnekleri: Fabrika ve Öğrenci Bilgi Sistemi

### 10.1 Fabrika bilgi sistemi

Slayttaki şekil (ekrandan, 01:20:00) beş alt sistemi ve aralarındaki akışları gösterir:

```text
Sipariş alt sistemleri ----(Sipariş)------------> Ürün stok alt sistemi
Sipariş alt sistemleri ----(Sipariş Karşılama)--> Ürün stok alt sistemi
Ürün stok alt sistemi -----(Siparişleri Yerine Koyma)--> Ürün planlama alt sistemi
Ürün planlama alt sistemi --(Program)---------> Üretim alt sistemi
Üretim alt sistemi --------(Bulunabilirlik)---> Ürün planlama alt sistemi
Ürün planlama alt sistemi --(Talep)-----------> Ürün ve hammadde stok alt sistemi
Ürün ve hammadde stok alt sistemi --(Bulunabilirlik)--> Ürün planlama alt sistemi
```

Bir fabrikada gelen siparişleri yönetmek, üretilen ürünleri depolamak, üretimi planlamak, üretimi kontrol edip izlemek ve sürekliliğini sağlamak, hammaddeleri depolamak ya da istemek için ayrı alt sistemler olabilir. Her biri kendi içinde bir bilgi sistemi olabilir; birlikte, birer bileşen gibi çalışarak fabrika yönetim sistemini oluştururlar. Hoca şekildeki ayrıntılara "neden böyle" diye fazla takılmamayı, ana fikrin bu olduğunu söyledi.

### 10.2 Üniversite öğrenci bilgi sistemi

Hoca, öğrencilerin kullandığı üniversite öğrenci bilgi sistemini "tam bir bilgi sistemi" olarak örnekledi, çünkü:

- Donanım, yazılım, insan, veri ve ağ kaynaklarının hepsi vardır.
- Girdileri (kullanıcıların ekranlardan girdiği veriler), çıktıları (raporlar), bileşenleri (modüller) ve hizmetleri vardır.
- İhtiyaçları desteklemek için birçok bileşen bir arada çalışır.

Bu sistem dönem boyunca örnek olarak sık kullanılacaktır; beklentileri karşılayıp karşılamadığı, ölçütlerle hizmet kalitesinin nasıl ölçüldüğü ve işlevsel olmayan gereksinimler bu sistem üzerinden konuşulacaktır.

Alt sistemleri:

- **Giriş/kimlik doğrulama alt sistemi:** Kullanıcıyı tanır, yetkilendirir ve hangi modülleri kullanabileceğini seçip gösterir. Girişte kullanılan "robot değilim" doğrulaması (kutuyu işaretleyip resimleri seçme) bir dış sistemden arabirim aracılığıyla alınan bir hizmettir.
- **Ders seçimi alt sistemi** ve **not girişi alt sistemi:** Yetkiye göre ayrılır. Öğrenci ders seçebilir ama not giremez; öğretim üyesi not girebilir ama ders seçemez.

Not girişi için başka alt sistemlerden veri gerekir: dersin öğretim üyesine tanımlanmış olması gerekir, bunu ancak bölüm yönetimi kendi ders tanımlama modülüyle yapabilir. Öğrencilerin ders kayıt bilgileri de alınır. Ardından ara sınav ve final notları girilir, bağıl not hesaplama süreçleri çalışır ve bir çıktı üretilir. Öğrenciye ise yalnız kendi notları gösterilir.

> **Hocanın vurgusu:** Bir bilgi sistemi aynı verileri kullanarak farklı taraflara farklı çıktılar üretebilir.

Lisansüstü öğrenciler için aynı işi gören ayrı bir lisansüstü öğrenci bilgi sistemi vardır.

## 11. Genel Sistem Teorisi

Dersin özeti olarak hoca genel sistem teorisinin ilkelerini verdi (ekrandan, 01:25:00):

- **Sistem; girdiyi çıktıya dönüştürür.**
  - Bilgi sisteminde veri → bilgi.
- **Sistemler disiplinler arasıdır.**
  - Bir daldaki ürün başka dalda kullanılabilir.
- **Sistem elemanları arası etkileşim vardır.**
  - Bir parçadaki etki diğer parçaları da etkiler.
- **Sistemler farklı elemanlardan oluşur.**
  - Taşımacılık → demiryolu, denizyolu, havayolu..
- **Sistemler hiyerarşiktir.**
  - Her sistem alt ve üstünde sistemler vardır.
- **Sistem ortama göre düzenlenmelidir.**
  - Entropi ortamla ilişkiyi belirler.
- **Sistem amaç yönelimlidir.**
  - Her sistemin belli bir amacı vardır.

### 11.1 Girdi-işlem-çıktı

Sistemler girdi, işlem, çıktı mantığıyla çalışır: girdiyi işleyerek çıktıya dönüştürür. Bilgi sistemleri veriyi alır, işler, hizmet sunar ve bilgiye dönüştürür; yani veriyle beslenir, bilgi üretir ve bilgiyle hizmet sunar.

### 11.2 Disiplinler arasılık

Tek bir disipline ait sistem yoktur. Bir daldaki ürün ya da sistem başka dalda kullanılabilir; bir sistem başka dallardan pek çok hizmeti ya da sistemi kullanabilir. Bilgi sistemi de donanım, yazılım, ağ ve insan gibi farklı disiplinleri bir araya getirir.

### 11.3 Etkileşim

Problem gitgide küçük parçalara bölünür; her bileşen belirli bir problemi çözecek, belirli bir hizmeti ya da çıktıyı üretecek şekilde ayrılır. Bu parçaların bir arada düzgün çalışması sağlanmalıdır. Bir parça değişir ya da bozulursa bu diğer parçaların çalışmasını da etkiler.

### 11.4 Farklı elemanlar: taşımacılık örneği

30×30 boyutunda, 5 kilogramlık bir koliyi A noktasından B noktasına taşımak bir hizmettir. Bin tane koli olduğunu düşünün: bir kısmı trenle, bir kısmı gemiyle, bir kısmı uçakla ya da hepsi tek bir yolla gönderilebilir. Seçim gereksinimlere bağlıdır: demiryolu her yere gitmeyebilir; uzak mesafede ucuzluk isteniyorsa deniz yolu, hız isteniyorsa maliyetine katlanarak hava yolu seçilir. Bunlar hibrit olarak birlikte de kullanılabilir.

### 11.5 Hiyerarşi

Fakülteden kampüse, oradan evrene kadar çıkılan örnekteki gibi, her sistemin altında ve üstünde sistemler vardır. Sistemi oluşturan alt parçaların en küçüklerine bileşen denir.

### 11.6 Ortama göre düzenlenme ve entropi

Hoca "her ortamda çalışır" (cross platform) iddiasının tam olarak doğru olmadığını söyledi. Entropiyi kabaca "sistemin ortamla olan ilişkisinin katsayısı" diye tanımladı. Bir işletim sistemi için yazılmış bir bilgi sistemi, doğal olarak başka bir işletim sisteminde çalışmaz: dosya sistemi, ağ ve G/Ç sistemleri farklıdır. Bu dönüşümlerin yapılması ya da araya adaptörler, arabirimler konması gerekir. Benzer şekilde tek bir sunucuda çalışan monolitik bir uygulama ile bulutta ya da konteyner mimarisinde çalışacak bir sistem farklı düzenlenmelidir; paralelleştirmenin nasıl yapılacağına göre modelleme, tasarım ve gerçekleştirme tamamen farklı olur.

> **Ek bilgi (derste anlatılmadı):** Genel sistem teorisinde entropi, bir sistemin düzensizliğe ve bozulmaya doğru gitme eğilimini anlatır. Ortamıyla girdi-çıktı alışverişi yapan açık sistemler, geri besleme ve ortamdan aldıkları enerji/bilgiyle bu eğilime karşı koyabilir. Hocanın "ortamla ilişki" vurgusu bu açık sistem fikrine dayanır.

### 11.7 Amaç yönelimlilik

Geliştirilen her sistemin bir amacı olmalıdır. Ne yapacağı belli olmadan bir sistem tasarlamak ya da gerçekleştirmek söz konusu değildir: "Bir şey yaptım ama hiçbir şey yapmıyor" olamaz.

## 12. Kendi Başına İnceleme ve Dersin Bakış Açısı

Hoca kavramların oturması için bir inceleme önerdi (ekrandan, 01:30:00):

- Örnek bir sistem nedir, bileşenleri, ortamı, sınırları, arabirimleri, ... nelerdir?
- Nasıl işler?
- Ders kaynağında hastane sistemi örneği.

Bir örnek sistem seçilip bileşenleri, ortamı, sınırı, arabirimleri, alt ve üst sistemleri, ne işlediği, nasıl işlediği ve hangi hizmetleri sunduğu okunarak, yazılarak ya da sözlü olarak incelenebilir. Hastane, öğrenci bilgi sistemi ya da bambaşka bir sistem seçilebilir; yeter ki bir bilgi sistemi ya da genel bir sistem olsun.

> **Hocanın vurgusu:** Bu derste artık yalnız bir algoritma geliştirmiyor, yalnız bir algoritmanın kodunu yazmıyoruz. Bir işin yapılabilirliğinden başlayıp ne olduğunu anlamaya, nasıl çözüleceğini tasarlamaya ve gerçekleştirmeye kadar giden, çalışan ve hizmet veren bütüncül çözümleri öğreniyoruz. Akış diyagramları ve algoritmalar artık bileşenlerin ya da modüllerin içindeki küçük parçaların nasıl çalışacağını tasarladığımız yerler olarak kalacak; burada büyük resim görülüp modellenecek.

## Örnek Sorular

**Soru 1** (ekrandan, 00:40:00): Bilgi sisteminin bir bilgisayar programından farkı nedir?

> **Cevap (derste verildi):** En basit fark boyuttur: program tekil bir problemi bir algoritmayla çözer, bilgi sistemi ise binlerce-milyonlarca satır kod ve onlarca-yüzlerce algoritmanın bir arada doğru çalışmasını gerektirir. Ayrıca çözülen problem çok yönlüdür; modüler, genişletilebilir bir yapı, ortak ya da ayrı veri kullanımı ve bir süreç yönetimi gerekir.

**Soru 2** (derste sözlü, 01:02:25): Fotoğraftaki ev sinema sisteminin sınırı nedir? Koltuk bir sistem olarak düşünülebilir mi?

> **Cevap (derste verildi):** Sınır odanın duvarlarıdır. Koltuk sistem olarak modellenebilir, ama bu model için çok küçük bir parça olduğundan ev sinema sisteminin bir bileşeni sayılır. Buna karşılık görüntü sistemi ve oynatıcı hem bileşen hem de kendi içinde tam birer sistemdir.

**Soru 3** (derste sözlü, 01:13:58): Üniversitenin öğrenci bilgi sistemi neden "tam bir bilgi sistemi"dir?

> **Cevap (derste verildi):** Donanım, yazılım, insan, veri ve ağ kaynaklarının hepsine sahiptir; girdileri (ekranlardan girilen veriler), çıktıları (raporlar), bileşenleri (modüller) ve hizmetleri vardır; ihtiyaçları desteklemek için bu bileşenler bir arada çalışır.

**Soru 4** (ekrandan, 01:30:00): Örnek bir sistem seçin (ders kaynağında hastane sistemi örneği önerilir). Bileşenleri, ortamı, sınırları ve arabirimleri nelerdir, nasıl işler?

> **Çözüm (derste verilmedi):** Hastane sistemi için olası bir inceleme:
>
> - **Amaç:** hastaları teşhis ve tedavi etmek.
> - **Girdiler:** hastalar, ilaç ve tıbbi malzeme, personel, bütçe. **Çıktılar:** tedavi edilmiş ya da sevk edilmiş hastalar, raporlar, faturalar.
> - **Bileşenler/alt sistemler:** hasta kabul, poliklinikler, laboratuvar, radyoloji, ameliyathane, eczane, faturalama.
> - **Sınır:** hastanenin sunduğu hizmetler; laboratuvar dışarıdan hizmet olarak alınıyorsa sınırın dışında kalır.
> - **Arabirimler:** sigorta kurumu sistemi, ilaç tedarikçileri, ambulans ve sevk sistemi.
> - **Ortam:** hastalar ve aileleri, sağlık bakanlığı, diğer hastaneler.
> - **Ölçütler:** bekleme süresi, yatak doluluk oranı. **Geri besleme:** hasta memnuniyet anketlerine göre süreçlerin iyileştirilmesi.

## Dersin Toparlaması

Bu derste "sistem" kavramı sözlük anlamından başlayarak tanımlandı: belli bir amaç için bir arada çalışan, birbiriyle ilişkili parçalardan oluşan, girdi ve çıktıları olan, sınırları belirlenmiş bütün. Sistemin temel özellikleri (bileşen, değişken, parametre, ilişki, sınır, arabirim, kısıt, ölçüt, ortam, geri besleme), sistem-ortam ilişkisi ve hiyerarşi bina, ev sineması, restoran ve taşımacılık örnekleriyle somutlaştırıldı. Bilgi sisteminin bir programdan farkı, tanımı ve beş bileşen ailesi (donanım, yazılım, insan, veri, ağ) fabrika ve öğrenci bilgi sistemi örnekleriyle gösterildi; ders genel sistem teorisinin yedi ilkesiyle bağlandı.

Sonraki derste sistem tipleri, bilgi sisteminin tarafları ve rolleri ile temel sistem geliştirme süreç modeli (şelale) ele alınacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
