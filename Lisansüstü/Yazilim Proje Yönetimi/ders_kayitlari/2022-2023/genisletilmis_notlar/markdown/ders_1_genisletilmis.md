# Ders 1 Genişletilmiş Notu: Yazılım Proje Yönetimine Giriş, 3P, Gereksinim Analizi ve Çevik Yaklaşımlar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Yazılım proje yönetiminin üç halkası
- 2. Etkin proje yönetimi: 3P
- 3. Yazılım geliştirme sürecinde esas ve destek işlemler
- 4. Gereksinim türleri
- 5. Yapısal yaklaşımla gereksinim analizi
- 6. Süreç modelleri ve çevik yaklaşımlar
- 7. Zamanlama, WBS ve proje planına giriş
- 8. Yazılım proje yönetimi literatürü
- Örnek Sorular

## 1. Yazılım proje yönetiminin üç halkası

Ders, yazılım proje yönetiminin hangi bilgi alanlarından beslendiğini gösteren bir şemayla başlar. Ekrandaki Venn şemasında üç daire vardır: "Proje yönetimi bilgi ve deneyimi", "Genel yönetim bilimi" ve "Yazılım mühendisliği teknikleri". Üç dairenin kesiştiği kırmızı bölge "Yazılım proje yönetimi" olarak işaretlenmiştir (ekrandan, 00:40:00).

```text
          Proje yönetimi bilgi ve deneyimi
                     /        \
                    / [YPY]    \
     Genel yönetim bilimi ---- Yazılım mühendisliği teknikleri

YPY: üç alanın ortak kesişimi = yazılım proje yönetimi
```

Hocanın açıklamasına göre:

- **Proje yönetimi bilgi ve deneyimi:** zaman planı, kaynak planı, kapsam yönetimi gibi projenin daha iyi yönetilmesi için gereken bilgilerdir.
- **Genel yönetim bilimi:** proje yöneticisi, ekibindeki kişilerle ilişkisi açısından yönetim bilgisine sahip olmalıdır. Bu, işletme ve endüstri mühendisliği bölümlerinde öğretilen yönetim alanıdır.
- **Yazılım mühendisliği teknikleri:** proje ve yönetim işlerinin bir yazılım projesinde hangi tekniklerle gerçekleştirileceğini belirler.

İlk iki halka genel proje yönetimi derslerinde de verilir. Yazılım proje yönetimini ayıran, bunların yazılım mühendisliği teknikleriyle birleştirilmesidir. Etkin bir yazılım projesi yönetimi için üç alanın birlikte kullanılması gerekir.

## 2. Etkin proje yönetimi: 3P

"Etkin proje yönetimi" slaytında üç başlık vardır (ekrandan, 01:05:00). İngilizcede bunlara 3P denir: People, Problem, Process. Hoca, bazı kaynaklarda dördüncü bir P'nin de eklendiğini, ama standart olarak 3P'nin düşünülebileceğini söyledi.

### 2.1 İnsan kaynakları (People)

Slayttaki tanım: "Seçim, performans yönetimi, eğitim, kariyer geliştirme, organizasyon ve iş tasarımı, ekip kültürü geliştirme konuları üzerinde durulmalıdır." (ekrandan, 01:05:00)

Hoca bunu sorularla açtı: Ekibe elemanlar nasıl seçilecek? Performansları nasıl takip edilecek? Eğitim ve kariyer gelişimleri nasıl sağlanacak? Organizasyon içindeki iş tasarımı nasıl kurulacak? Ekip kültürü nasıl oluşturulacak? Hoca People'ı listenin en üstüne koyduğunu özellikle belirtti.

### 2.2 Problem

Slayttaki tanım: "Bir proje planlanmadan önce amacı ve alanı belirlenmeli, alternatif çözümler düşünülmeli, teknik ve yönetim kısıtları tanımlanmalıdır." (ekrandan, 01:05:00)

Hoca problemi bir hastane bilgi sistemi örneğiyle anlattı. Alan hastane bilgi sistemidir, ama sistem nasıl bir hastane için geliştiriliyor ve o hastaneye nasıl uygulanmalı? Alternatif çözümler nelerdir: sıfırdan bir hastane bilgi sistemi mi yazılmalı, yoksa satılan ürünlerden biri mi uyarlanmalı? Her alternatif için teknik ve yönetim kısıtları nelerdir? Hazır satılan yazılım maliyet ve teknik güç açısından uygun mu, yönetim kısıtlarını karşılıyor mu? Bu sorular açığa çıkarılıp hedef ve alan buna göre belirlenir. Hocanın özetiyle: problemi doğru koymak, doğru çözüm yollarını düşünmek ve alternatifler arasından en uygununa karar vermek.

Bir işletmenin alt birimi olarak çalışan bir yazılım geliştirme biriminde, birimin yürüttüğü yazılım projelerinin nasıl sıralanacağı da problem tanımının bir parçasıdır.

### 2.3 Süreç (Process)

Slayttaki tanım: "Yazılım geliştirme sürecinde gerçekleştirilen işlemler, esas işlemler ve bunların gerçekleşmesini destekleyen işlemlerden oluşur." (ekrandan, 01:05:00)

Süreç kavramı yazılım mühendisliğinden bilinir: gereksinim süreci, tasarım süreci, yazılım geliştirme süreci. İşler bir süreç içinde yürür ve bu süreçteki işlemler gruplara ayrılır. Bu gruplar bir sonraki bölümün konusudur.

## 3. Yazılım geliştirme sürecinde esas ve destek işlemler

Hoca bu bölümü öğrencilere soru sorarak işledi (bkz. Örnek Sorular). Bir öğrenci önce planlamayı esas, testi destek işlem olarak tahmin etti. Hoca planlamanın da tanımlamanın içinde olduğunu, ama asıl sorunun "yazılımı geliştirirken neler yaparız, birdenbire kod mu yazarız?" olduğunu söyledi. Başka bir öğrenci analiz, tasarım, geliştirme, test ve ürün sürümü çıkarma sırasını verdi; hoca bunu onayladı.

**Esas (temel) işlemler:**

- **Gereksinim analizi:** gerçek hayatta işin nasıl yürüdüğü, müşterinin istekleri ve bu isteklere karşılık gelen gereksinimler belirlenir.
- **Tasarım:** gereksinimlerin nasıl modelleneceği, yani yazılıma nasıl aktarılacağı belirlenir.
- **Gerçekleştirme:** kodlama ve veritabanının oluşturulması.
- **Test:** test de esas işlemlerden biridir.

**Destek işlemler:** proje yönetimi, kalite yönetimi, risk yönetimi, konfigürasyon yönetimi. Bunlar temel işlemleri destekleyen aktivitelerdir.

> **Hocanın vurgusu:** Test, destek işlem değil temel işlemlerden biridir. Proje yönetimi ise temel işlemleri destekleyen işlemler arasındadır.

## 4. Gereksinim türleri

Hoca, gereksinim analizinde gereksinimlerin nasıl gruplandığını sordu. Bir öğrencinin cevabı "işlevsel (functional) ve işlevsel olmayan (non-functional)" oldu; hoca onayladı.

- **İşlevsel gereksinimler (functional requirements):** problem alanıyla ilgili tanımlamalardır. Örneğin bir hastane bilgi sisteminde neler olmalı, sistem neleri yapmalı? Bunlar fonksiyonlarla ilgili gereksinimlerdir.
- **İşlevsel olmayan gereksinimler (non-functional requirements):** yazılım kalite özellikleridir. Her yazılımdan beklenir, ama yazılıma göre bazılarının daha yüksek düzeyde karşılanması gerekir. Hocanın örnekleri: eş zamanlılık, yedekleme ve kurtarma (backup/recovery), erişilebilirlik, çevrim içi erişim hızı. Bazı yazılımlarda güvenlik, bazılarında güvenilirlik, bazılarında hepsi birden çok yüksek seviyede karşılanmalıdır.

Bu bilgiler proje yönetimine şöyle bağlanır: proje yöneticisi projenin isteklerini bilmeli, böylece kapsamı daha iyi belirler. İstenen özelliklerin geçerli olup olmadığı, yani programa aktarılabilir istekler olup olmadığı netleştirilir. Sonra ekip doğru kurulur, ekip üzerinden zaman ve kaynak planı yapılır. İnsan kaynakları doğru seçilmeli, performans doğru izlenmeli, kariyer gelişimi, iş tasarımı ve ekip kültürü doğru oluşturulmalıdır. Problem doğru konmalı; sistem analizi ve tasarımı dersindeki fizibilite analiziyle alternatif çözümlerden hangisinin yapılabilir olduğuna karar verilmeli ve süreç doğru kurulmalıdır.

## 5. Yapısal yaklaşımla gereksinim analizi

Aradan sonra hoca, "Gereksinim Analizi — Yapısal Yaklaşım ile" başlıklı sunuma geçti.

### 5.1 Gereksinim analizi modelinin amaçları

Gereksinim analizinde işlevsel ve işlevsel olmayan gereksinimleri karşılamak üzere bir gereksinim analizi modeli kurulur. Modelin üç amacı vardır:

- Müşteri ihtiyaçlarını açıklamak.
- Yazılım tasarımının nasıl oluşturulacağına dair bir temel hazırlamak.
- Yazılım oluşturulduktan sonra belirlenen ihtiyaçları karşılayıp karşılamadığını doğrulamak için ölçüt ortaya koymak.

Bu amaçlarla yapısal bir analiz modeli çıkarılır; temel ihtiyaçlar bu modelden ortaya çıkar ve tasarım bunun üzerine kurulur.

### 5.2 Modelin yapısı

Ekrandaki şema iç içe halkalardan oluşur (ekrandan, 01:35:00):

```text
Merkez        : Veri Sözlüğü
Orta halka    : Varlık İlişki Diyagramı | Veri Akış Diyagramı | Durum Geçiş Diyagramı
Dış halka     : Veri Nesne Tanımı      | Süreç Spesifikasyonu | Kontrol Spesifikasyonu
(Her dış etiket, altındaki diyagramla aynı dilimdedir.)
```

- **Veri sözlüğü:** modelin merkezindedir; yazılımın kullandığı ve ürettiği tüm nesneleri tanımlar.
- **Varlık ilişki diyagramı (ERD):** veritabanı dersinden bilinen entity relationship diyagramıdır. Hakkında bilgi tutulacak varlıkları ve aralarındaki ilişkileri gösterir; veri nesne tanımına karşılık gelir. Tasarımda veritabanı modelinin çıkarılmasına temel olur.
- **Veri akış diyagramı (DFD):** sistemde her verinin nasıl taşındığını ve bu akışı sağlayan fonksiyonları, alt fonksiyonları gösterir; süreç spesifikasyonuna karşılık gelir.
- **Durum geçiş diyagramı:** durum geçişlerinin nasıl gerçekleştiğini gösterir; kontrol spesifikasyonuna karşılık gelir.

Hastane örneğine dönülürse: hastanede hangi varlıklar hakkında bilgi tutulacak, hangi işler gerçekleşiyor, bu işlerin akışı nasıl, akışta kimler söz sahibi, sistemin ürettiği bilgi kimin işine yarayacak ve bilgi hangi noktalardan akmalı? Bunlar gereksinim analizi sırasında belirlenir.

Hoca, nesneye yönelik modellemede veri akış diyagramları yerine use case diyagramlarının da kullanıldığını belirtti. Veri akış diyagramlarının özelliği genelden ayrıntıya inen bir gösterim sunmasıdır: önce bir özet (taslak) diyagram, sonra daha ayrıntılı bir diyagram, en sonunda tek bir işin nasıl yapılacağını gösteren ayrıntılı diyagram.

### 5.3 Örnek 1: Öğrenci bilgi sistemi

**Taslak diyagram:** dış varlıklar öğrenci ve öğretim üyeleridir; ortada tek bir işlem vardır: "Öğrenci Bilgi Sistemi".

**Birinci seviye diyagram** ("Şekil 3. Örnek birinci seviye diyagram", ekrandan, 01:40:00):

| Kaynak | Veri akışı | Hedef |
|---|---|---|
| Öğrenci | Ders Seçimi | Ders Seç |
| Ders Seç | Öğrenci-seçilen ders bilgileri | Sınav sonuçlarını sisteme ekle |
| Ders Seç | Öğrenci-seçilen dersler bilgisi | Öğrenci-Ders veritabanı tablosu |
| Sınav sonuçlarını sisteme ekle | Sınıf listesi | Öğretim Üyeleri |
| Öğretim Üyeleri | Sınav sonuçları | Sınav sonuçlarını sisteme ekle |
| Sınav sonuçlarını sisteme ekle | Sınav sonuçları | Öğrenci-Not veritabanı tablosu |
| Sınav sonuçlarını sisteme ekle | Öğrenci – not bilgisi | Sınav sonucu görüntüle |
| Öğrenci-Not veritabanı tablosu | Sınav sonuçları | Sınav sonucu görüntüle |
| Sınav sonucu görüntüle | Sınav sonuçları | Öğrenci |

Taslak diyagramdaki tek "Öğrenci Bilgi Sistemi" işlemi burada üç alt işleme ayrılmıştır: ders seçimi, öğretim üyesinin sınav sonuçlarını sisteme girmesi ve sınav sonucunun görüntülenmesi. Ayrıca iki veri saklama ortamı (Öğrenci-Ders ve Öğrenci-Not veritabanı tabloları) gösterilmiştir.

### 5.4 Örnek 2: Doktor muayenehanesi faturalama sistemi

Bu örnek bir hastaneye genişletilerek de düşünülebilir.

**Taslak diyagram:** dış varlıklar doktor, hasta ve sigorta şirketidir; tek işlem "Faturalama Sistemi"dir.

**Birinci seviye diyagram:** faturalama sistemi dört alt işleme ayrılır:

- Muayene kaydının incelenmesi ve ücret hesabı,
- Faturanın hazırlanması (hasta ve sigorta bilgileriyle eşleştirilmesi dahil),
- Hasta ödemelerinin işlenmesi,
- Sigorta ödemelerinin işlenmesi (ödemeler muhasebe kayıtlarına aktarılır).

Bu diyagramda ilgili veri saklama ortamları da gösterilir. <!-- BELİRSİZ: Birinci seviye faturalama diyagramının karesi yok; işlem adları altyazıdan alındı. -->

**İkinci seviye diyagram (2.0 fatura hazırlama işleminin ayrıntısı)** (ekrandan, 01:45:00):

```text
İşlem 2.0 içindeki alt işlemler:
  2.1 Hastanın Sigorta Durumunun İncelenmesi
  2.2 Listelenen Miktarla Faturayı Kıyaslama
  2.3 Hastanın Ödemesi Gereken Tutarı Faturalama

Veri akışları:
  Hasta                         --Sigorta Formu-->                  2.1
  1.0 Muayene Kaydı İnceleme
      ve Ücret Hesabı           --Doğrulanmış Ücret-->              2.1
  2.1                           --Sigorta ve Ücret Bilgisi-->       2.2
  D3 Sigorta Şirketleri         --Sigorta Şirketi Adı ve Adresi-->  2.2
  2.2                           --Sigorta Faturası-->               Sigorta Şirketi
  2.2                           --Hastanın Ödemesi Gereken Tutar--> 2.3
  D2 Hastalar                   --Hasta Adresi-->                   2.3
  2.3                           --Hasta Faturası-->                 Hasta
```

Numaralandırma, her alt işlemin hangi üst işlemden geldiğini gösterir: 2.0 işlemi 2.1, 2.2 ve 2.3'e ayrılır. D2 ve D3 veri depolarıdır (hastalar ve sigorta şirketleri).

### 5.5 Genel değerlendirme

Gereksinim analizi üç şey üretir:

- **Veri modeli:** hakkında bilgi tutulacak ve saklanacak varlıklar belirlenir, aralarındaki ilişkiler kurulur.
- **Süreç modeli:** işlemler genelden ayrıntıya alt işlemlere ayrıştırılır; akışı etkileyen ve akıştan etkilenen kişiler ile veri saklama ortamları gösterilir.
- **Maddeler halinde gereksinimler:** modellerden çıkan gereksinim listesi.

Hoca veri akış diyagramlarını, daha basit oldukları ve süreç akışını daha iyi gösterdikleri için seçtiğini söyledi. Aynı akış, nesneye yönelik yaklaşımda use case diyagramlarıyla da gösterilebilir; birçok üniversitede yazılım mühendisliği dersinde gereksinim analizi nesneye yönelik yaklaşımla işlenir, ama iki yaklaşımda da veri akış diyagramları kullanılabilir.

## 6. Süreç modelleri ve çevik yaklaşımlar

### 6.1 Sıralı ve sıralı olmayan modeller

Analiz, tasarım, gerçekleştirme ve test adımları genelde biri bitince diğeri başlayacak şekilde sıralı gösterilir. Bu sıralı hal şelale (waterfall) modelidir ve süreci basit anlatmak için kullanılır. Ama süreç her zaman böyle akmaz:

- **Spiral model:** döngüsel olarak ilerler.
- **Prototip model:** analiz ve tasarım bir döngü içinde ilerler, sonra düz akışla devam edilir.
- **RAD modeli:** birkaç koldan paralel olarak yazılım geliştirilir.

### 6.2 Çevik yaklaşımlar

Slayttaki tanım: "Çevik yaklaşımlar, artan müşteri taleplerini daha hızlı karşılamak amacıyla geleneksel sistem geliştirme modellerine alternatif olarak ortaya çıkmıştır. Çevik yaklaşımlar, yazılım geliştirme safhasında geç ortaya çıkan gereksinim değişikliklerini çabuk karşılamayı esas alan modellere verilen genel bir isimdir." (ekrandan, 01:50:00)

Hoca çevik yaklaşımların 2000'lerin başından, özellikle 2002'den sonra yaygınlaştığını söyledi. Sektördeki hızlı sonuç alma isteği ve müşteri taleplerini daha hızlı karşılama ihtiyacıyla hem bir alternatif hem de bir zorunluluk olarak ortaya çıktılar. Çünkü ilk belirlenen gereksinimler sabit kalmaz; müşteri geliştirme sürerken de değişiklik ister. Çevik yaklaşımlar, araya fazla zaman koymadan kodun hızlı geliştirilmesine dayanır. Sektörde en çok Scrum ve Kanban olarak görülür. Sunumun içindekilerde XP (eXtreme Programming) ve test güdümlü yazılım geliştirme (TDD) başlıkları da yer alır.

"Geleneksel yazılım geliştirme süreç modellerine göre çevik modellerde" slaytı (ekrandan, 01:55:00):

- Dinamik kalite değerlendirme statik değerlendirmeden daha fazla uygulanır.
- Kalite ile ilgili işlemler sürecin daha erken adımlarında başlar.
- Kalite ile ilgili aktiviteler daha az aralıklarla yapılır.
- Çevik yaklaşımlarda kullanıcı hikayeleri, birim testler ve müşteri geri beslemesi ile doğruluk ve süreklilik sağlanmaktadır.

Hoca, tanımlamanın daha sık yapıldığını ve yazılım kalite dersinde görülen test güdümlü geliştirme (test driven development) yaklaşımının da çevik modellerle birlikte ortaya çıktığını ekledi.

### 6.3 Çevik projelerde proje yönetimi

Süreç modelleri klasik ve çevik diye ayrılır ve çevik modellerde proje yönetimi açısından da farklılıklar vardır; literatürde "Agile Project Management" ve "Agile Software Project Management" yaklaşımları görülür. Çevik modellerin uygulamada nasıl kullanıldığı ve projelerin sonuçları akademik sempozyumlarda da değerlendirilmektedir.

Sık rastlanan bir düşünce, çevik projelerde proje yöneticisi olmadığı, yalnız bir proje koordinatörü olduğu ve ekip yapısının tamamen farklı olduğudur. Hocaya göre sektörde çevik projelerin çoğunda da projeden sorumlu bir proje yöneticisi vardır. Çevik projelerin en önemli yanı herkesin birbirine karşı sorumlu olması ve birbirini denetlemesidir. Yine de üst yönetimle alt ekip arasındaki iletişimi ve yönetişimi sağlayan, projeden sorumlu bir kişi tanımlanır; bazı yerlerde proje koordinatörü, bazı yerlerde proje yöneticisi denir.

Çevik projeler için yazılım ölçümlemesinde de farklılıklar ve yeni düzenlemeler vardır. Ama proje yönetimi evreleri çevik projelerde de, çevik metodolojiye uyarlanarak uygulanır.

> **Hocanın vurgusu:** Çevik yaklaşımlarla yazılım geliştirmede de proje yönetimi kavramı vardır; yalnızca bazı yönleri farklıdır.

## 7. Zamanlama, WBS ve proje planına giriş

Hoca dersin sonunda üç halkayı yeniden hatırlattı: proje yönetim teknikleri, yönetim teknikleri ve yazılım mühendisliği. Yazılım mühendisliğinden gereksinim analizi ve temel evreler görüldü; etkin proje yönetimi için kaynak planlama ve süreç planlamanın da önemli olduğu belirtildi.

### 7.1 Zamanlama

Zamanlama şu soruları yanıtlar:

- Yazılım projesi hangi durak noktalarında onaya sunulacak, hangi tarihlerde ne yapılacak?
- Projenin tamamlanma süresi nedir?
- Aradaki işler bitiş süresini nasıl etkiler?
- Hangi alt işlemin beklemeye tahammülü yoktur?
- Hangi alt işlem ne zaman başlamalıdır?

Proje zamanlaması şematik olarak PERT ve Gantt çizelgeleriyle gösterilir. Bunların nasıl kullanılacağı sonraki derslerde ele alınacaktır.

### 7.2 WBS örneği

Ekranda şelale modeline göre bir iş kırılım yapısı (Work Breakdown Structure, WBS) örneği gösterildi (ekrandan, 02:00:00):

```text
1.0 Analiz
    1.1 Bilgi Toplama
    1.2 Modelleme
    1.3 SRS Hazırlama
2.0 Tasarım
    2.1 Mimari Tasarım
    2.2 Ayrıntılı Tasarım
3.0 Gerçekleme
    3.1 Kodlama
    3.2 Veri Tabanı Oluşturma
4.0 Test
    4.1 Bütünlük Test
    4.2 Sistem Test
    4.3 Kullanıcı Test
```

Hoca, WBS'nin alt adımlar şeklinde nasıl kurulduğunu, bunun Gantt diyagramına nasıl uygulandığını ve spiral modelde bu adımların nasıl göründüğünü sonraki derste ayrıntılı işleyeceğini söyledi.

> **Ek bilgi (derste anlatılmadı):** "Bütünlük test" büyük olasılıkla tümleştirme (entegrasyon) testine karşılık gelir; bileşenler birleştirildikten sonra aralarındaki arayüzlerin sınandığı test düzeyidir.

### 7.3 Proje planının içeriği

Ekrandaki "Proje Planı" slaytı, bir yazılım proje planında bulunması gereken başlıkları listeler (ekrandan, 02:05:00):

- Proje Kapsamı: proje hedefleri ve sınırları
- Projede Yazılım Geliştirme Modeli
- Proje Risk Analizi
- Varsayım ve Kısıtlar
- Alt Aktiviteler: WBS (Work Breakdown Structure)
- Zaman Çizelgesi
- Aktiviteler Arası İlişkiler
- İşgücü Belirleme
- Görev Atama
- Proje Ekip Yapısı
- Bütçe
- Proje Kalite Planı
- Yazılım Gereksinim Spesifikasyonu (SRS)

Hoca, proje plan dokümanının IEEE'de tanımlanmış bir yapısı olduğunu da belirtti. Bir proje planında zaman planının, kaynak planının, ekip yapısının ve risklerin nasıl belirlenip takip edileceğinin belli standartlara uygun olarak raporlanması beklenir.

## 8. Yazılım proje yönetimi literatürü

Hoca, yazılım proje yönetimi konusunda güncel çalışmaların izlenebileceği temel süreli yayınlar olarak şunları saydı:

- **IEEE Software:** konuyla ilgili daha genel bilgiler ve daha kısa makaleler.
- **IEEE Transactions on Software Engineering:** daha kapsamlı makaleler; genellikle bir vaka çalışmasının ya da araştırma projesinin sonuçlarını içerir.
- **IEEE Transactions on Engineering Management:** daha çok endüstri mühendisliği ve mühendislik yönetimiyle ilgili yazılar; genel proje yönetimi ve yazılım proje yönetimi makaleleri de bulunur.

Bunların dışında ACM ve Elsevier'in süreli yayınları ile konferans kitapları da kaynak olabilir. Hoca, yazılım proje yönetimi alanında son yıllarda yapay zeka ve yapay sinir ağı yöntemleriyle proje yönetiminin iyileştirilmesi, süreç modellerinin ekip yapısına ve zaman yönetimine etkisi gibi konularda çalışmalar bulunduğunu belirtti. Konunun özünün üç halkanın (yönetim bilimi, proje yönetimi, yazılım mühendisliği teknikleri) birleşimi ve bunlara yeni teknolojilerle getirilen yorumlar olduğunu vurguladı.

## Örnek Sorular

**Soru 1** (derste sözlü, 01:09:53): Yazılım geliştirme sürecindeki temel (esas) işlemler nelerdir, bunları destekleyen işlemler nelerdir?

> **Çözüm (derste verilen):** Esas işlemler gereksinim analizi, tasarım, gerçekleştirme (kodlama ve veritabanı oluşturma) ve testtir. Destek işlemler proje yönetimi, kalite yönetimi, risk yönetimi ve konfigürasyon yönetimidir. Planlama tanımlamanın içinde düşünülür; test ise destek değil esas işlemdir.

**Soru 2** (derste sözlü, 01:14:54): Gereksinim analizinde gereksinimler hangi türlere ayrılır?

> **Çözüm (derste verilen):** İşlevsel (functional) ve işlevsel olmayan (non-functional) gereksinimler. İşlevsel gereksinimler problem alanına özgüdür (sistemin ne yapması gerektiği); işlevsel olmayan gereksinimler eş zamanlılık, yedekleme ve kurtarma, erişilebilirlik, erişim hızı, güvenlik, güvenilirlik gibi kalite özellikleridir.

## Dersin Toparlaması

Bu derste yazılım proje yönetiminin proje yönetimi bilgi ve deneyimi, genel yönetim bilimi ve yazılım mühendisliği tekniklerinin kesişiminde durduğu görüldü. Etkin proje yönetimi 3P ile özetlendi: insan kaynakları, problemin doğru konması ve sürecin doğru kurulması. Yazılım mühendisliği bilgisi hatırlatıldı: esas ve destek işlemler, işlevsel ve işlevsel olmayan gereksinimler, yapısal gereksinim analizi modeli (veri sözlüğü, ERD, DFD, durum geçiş diyagramı) ve genelden ayrıntıya inen veri akış diyagramı örnekleri. Ardından şelale, spiral, prototip ve RAD modellerinden çevik yaklaşımlara geçildi ve çevik projelerde de proje yönetiminin sürdüğü vurgulandı.

Dersin sonunda zamanlama kavramına, PERT ve Gantt çizelgelerine, WBS örneğine ve proje planının içeriğine giriş yapıldı. Hoca sonraki derste yazılım proje planının nasıl düzenlendiği, WBS'nin alt adımlarla nasıl kurulduğu ve Gantt diyagramına nasıl uygulandığı üzerinde duracağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
