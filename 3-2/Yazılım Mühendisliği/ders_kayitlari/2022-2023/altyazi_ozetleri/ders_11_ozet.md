# Ders 11 Çalışma Özeti

## Genel Konular

- Kayıt 10 Mayıs 2023 Çarşamba günü online yapılan derse ait, yaklaşık 2 saat 6 dakika sürüyor.
- Dersin ilk yarısı geçen haftanın tekrarı: yazılım mühendisliği tanımı, yazılım kalite faktörleri, McCall kalite modeli, kaliteyi sağlama yolları ve test aşamaları.
- İkinci yarıda yeni konu yazılım proje yönetimi (software project management): proje yönetiminin aşamaları, ölçüm (measurement), proje planının içeriği, iş kırılım yapısı (Work Breakdown Structure, WBS), Gantt diyagramı, kilometre taşları (milestones).
- Risk yönetimi (risk management): riskin tanımı, risk türleri, risk tablosu, olasılık ve etki matrisi, risk bilgi sayfası ve önlemlerin maliyeti.
- Ayrıntılı proje planı şablonu: kabuller ve kısıtlar, iş planı, bütçe, ekip organizasyonu, alan (kapsam) yönetimi, iletişim ve kalite yönetim planları.
- Ders sonunda sınav ağırlıkları, proje sunumları ve gelecek haftanın uygulama dersi duyuruldu.

## Hocanın Özellikle Vurguladığı Kısımlar

- Yazılım mühendisliğinin üç anahtar kavramı: **kaliteli yazılım**, **en ekonomik şekilde elde etme** ve **mühendislik araç ve yöntemlerini kullanma**.
- Mühendisliğin iki temel kavramı **tasarım** ve **ölçüm**dür. "Ölçemediğinizi yönetemezsiniz."
- Kaliteyi sağlamanın yolları sırasıyla:
  - Bir süreç modeli seçip kurallı uygulamak (waterfall, Scrum vb.).
  - Kilometre taşlarında gözden geçirme (review) yapmak.
  - Aralarda daha kurallı ve yoğun inceleme (inspection) yapmak.
  - Test (sınama) yapmak.
- Test yalnızca hatayı ve yerini bulur. Hatayı düzeltmek (debug) testin parçası değildir.
- Birim testini kodu yazan geliştirici yapar, test ekibi yapmaz.
- **Proje yönetimi, proje planlamaya eşit değildir.** Planlama, proje yönetiminin yalnızca bir aşamasıdır. Aşamalar: başlatma, tanımlama, planlama, yürütme/takip ve kapanış.
- Plan dinamiktir. Milestone'larda hedeflerin tutup tutmadığı kontrol edilir ve gerekirse plan değiştirilir.
- Müşteri değişiklik isteyecektir. Değişikliğin hangi koşullarla kabul edileceği ve yeni maliyetin nasıl hesaplanacağı planda yazılı olmalıdır.
- Risk yönetimi için en çok gereken bilim dalı **olasılık ve istatistik**tir. Hoca bunu derste sınıfa sordu.
- Projelerde bir risk tablosu, WBS ve Gantt diyagramı istenecek.

## Kısa Tekrar Notları

- **Yazılım kalite faktörleri (derste sayılanlar):** doğruluk, güvenirlik (reliability), verimlilik, güvenlik/bütünlük (integrity), kullanışlılık (usability), hata bulma kolaylığı, esneklik, sınama kolaylığı, taşınabilirlik, tekrar kullanılabilirlik (reusability), birlikte çalışabilirlik (interoperability).
- **McCall modelinin üç bakış açısı:**
  - Kullanıcı (ürün işletimi): doğruluk, güvenirlik, verimlilik, güvenlik, kullanışlılık.
  - Ürün geçişi: birlikte çalışabilirlik, taşınabilirlik, tekrar kullanılabilirlik.
  - Bakım (ürün revizyonu): sınama kolaylığı, esneklik, hata bulma kolaylığı.
- Kalite faktörü metriklerle tahmin edilir: $F_q = c_1 m_1 + c_2 m_2 + \dots + c_n m_n$.
- **Test sırası:** birim testi, bütünleştirme (integration) testi, sistem testi, onaylama (kabul, acceptance) testi.
- **Saydam kutu (white box):** iç yapı; temel yol testi, döngü testi. **Kara kutu (black box):** dış davranış; eşdeğer bölümleme (equivalence partitioning), sınır değer analizi (boundary value analysis).
- **Risk:** gelecekte olabilecek, olasılığa bağlı, gerçekleşirse kayıp getiren olay.
- **Risk türleri:** proje riskleri (bütçe, zaman, personel), teknik riskler (yeni CASE aracı, yeni dil), iş riskleri (pazar, satış).
- **Risk önemi** = olasılık × etki.
- **WBS:** işin süreç modeline göre hiyerarşik olarak alt işlere bölünmesi.
- **Milestone:** iş akışındaki dönüm noktası. Gantt diyagramında eşkenar dörtgenle gösterilir.

## Detaylı Açıklamalar

### Kalite tekrarı

- Yazılım mühendisliği tanımı: kaliteli yazılımı en ekonomik şekilde elde etmek için mühendislik yaklaşımını, araçlarını ve yöntemlerini kullanan bilim dalı.
- "En ekonomik" kısmı bu dersin konusu olan proje yönetimiyle ilgilidir: maliyet-fayda analizi ve işin istenen zamanda, istenen kapsamda bitmesi.
- Hata ne kadar erken yakalanırsa o kadar ucuza düzeltilir. Bu yüzden gözden geçirmeler erken aşamalardan başlar.
- Üretim aşamasındaki kontrole kalite kontrolü denir. Kimlerin katılacağı ve ne zaman yapılacağı önceden planlanır.
- Test helezonu: en içte kodlama ve birim testi, sonra tasarım ve bütünleştirme testi, sonra gereksinimler ve onaylama testi, en dışta sistem ve sistem testi. Bütünleştirme testi artırmalı (incremental) yapılır.
- Sistem testinde güvenlik, dayanıklılık ve performans testleri yapılır. Sistemin veritabanı yönetim sistemi ve işletim sistemiyle ilişkisi de denenir.
- Kara kutu testinde girdiler sisteme verilir ve çıktılar beklenenle karşılaştırılır; iç yapı görülmez. Eşdeğer bölümlemede girdi uzayı bölümlere ayrılır ve her bölümden bir değer denenir. Sınır değer analizinin dayanağı, hataların genellikle sınırlarda çıkmasıdır.

### Yazılım mühendisliğinin bölümleri

- Temel kaynaklar: Roger Pressman ve Ian Sommerville'in kitapları.
  - Giriş: yazılım, yazılım mühendisliği, CMMI gibi olgunluk modelleri, süreç modelleri.
  - Analiz, tasarım, gerçekleştirme: bu derste nesneye yönelik analiz ve tasarımla işlendi.
  - Kalite yönetimi ve test.
  - Proje yönetimi.
- 2000'li yıllardan itibaren başarısız yazılım projelerinin çokluğu proje yönetimini öne çıkardı.
- PMI (Project Management Institute) toplantılarına en çok yazılımcılar ve inşaat mühendisleri katılıyor. PMP (Project Management Professional) sertifikasının yanında çevik (agile) projeler için ayrı bir sertifika da var.

### Yazılım proje yönetimi

- Önce hangi süreç modelinin projeye uygun olduğuna, sonra hangi ölçümlerin yapılacağına karar verilir.
- Yazılım projelerinde ekipman maliyeti azdır, insan gücü öndedir. Bu yüzden personel yönetimi ve personel riskleri daha önemlidir.
- Planlama ilkeleri:
  - Önce kapsamı ve sınırları belirle. Gereksiz ayrıntıya girme.
  - Müşteriyi planlamaya kat ve adım adım onay al.
  - Geçmiş bilgilerle gerçekçi tahminler yap. Risk değerlendirmesi yap.
  - Büyük projede önce genel yapıyı kur, sonra her maddeyi ayrıntılandır.
  - Planın içinde bir kalite planı ve gözden geçirme noktaları olsun.
- Ölçüm iki açıdan yapılır:
  - **Süreç ölçütleri:** hata sayısı, hata giderme etkinliği, doğruluk (hata sayısı / proje boyutu), bakım kolaylığı (hatayı bulup gidermek için geçen süre).
  - **Proje/ürün ölçütleri:** yazılımın iç yapısına ilişkin özellikler.
  - Kaliteyi etkileyen etkenler: kişiler, ürün, teknoloji, çevre koşulları ve müşteri.
- Ölçüt (metrik) ölçmenin birimidir. Yazılımda karmaşıklık ve büyüklük ölçütleri vardır; örneğin kod satırı sayısı.
- Ölçme iki amaçla yapılır: mevcut işin ve personelin kalitesini değerlendirmek; gelecekteki projelerin maliyet ve büyüklük tahminlerini daha doğru yapmak.

### Proje planının içeriği

- Projenin amacı, kapsamı ve teslim edilecekler.
- Süreç modeline göre belirlenen iş aktiviteleri ve WBS.
- Zaman planı, kaynak planı, milestone'lar. Bunlar MS Project veya Gantt diyagramıyla takip edilir.
- Kalite planı, risk planı, kabuller (varsayımlar) ve kısıtlar.
- Bir yazılım proje planında hangi başlıkların olacağını tarif eden bir IEEE standardı vardır.
- WBS örneği (waterfall), öğrenci sorusu üzerine verildi:

```
1.0 Analiz (gereksinim analizi)
    1.1 Veri toplama
    1.2 Modelleme
    1.3 Rapor yazma
2.0 Tasarım
    2.1 Genel (ön) tasarım
    2.2 Ayrıntılı tasarım
        2.2.1 Girdi tasarımı
        2.2.2 Çıktı tasarımı
        2.2.3 Veritabanı tasarımı
        2.2.4 İşlem / arabirim tasarımı
3.0 Gerçekleştirme
```

- Scrum gibi bir modelde iş listesi farklı kurulur. İş önce parçalara bölünür, her parça kendi içinde ilerler.

### Ayrıntılı proje planı şablonu

- Giriş, amaç, proje alanı, teslim edilecekler, finansal beklentiler, tamamlanma kriteri (her zaman gerekmez).
- **Kabuller ve kısıtlar:** kabuller, proje geliştirilirken doğru varsayılan şeylerdir. Kısıtlar proje veya teknik sınırlamalardır; örneğin personel kısıtı.
- İş planı: WBS, zaman listesi, milestone'lar, zaman ve kaynak tahmini, nakit akışı analizi.
- Proje organizasyonu ve görevlendirme. Ekip yapıları:
  - Şeflik sistemi: az kişi varsa uygun.
  - Demokratik yapı.
  - Hiyerarşik yapı: hocaya göre yaklaşık 10 kişiden sonra daha doğru.
- Görevlendirme gereksinimleri: sistem analisti, yazılım geliştirici, test eden gibi rollerden hangi yetenekler bekleniyor.
- **Alan yönetimi:** müşterinin sonradan istediği değişikliklerin nasıl onaylanacağı.
- **İş listesi yönetimi:** zaman kayması olursa ne yapılacağı.
- Maliyet yönetim planı (bütçe) ve risk yönetim planı.
- **İletişim yönetimi:** özellikle kötü bir durum olduğunda haberin önceden ve kademeli olarak nasıl ileteceği.
- **Kalite yönetim planı:** gözden geçirmelerin zamanı, kimlerin katılacağı, kalite hedefleri ve ölçüleri.
- Satın alma ve alt yüklenicilerle faturalandırma kuralları.
- Hocaya göre mutlaka olması gerekenler: amaç, alan, teslim edilecekler, kabul ve kısıtlar, WBS, Gantt diyagramı, alan değişikliği yönetimi, kayma yönetimi, bütçe, risk planı, kalite gözden geçirmeleri ve ekip organizasyonu.

### Risk yönetimi

- Riskin üç öğesi: **olasılık**, **kayıp** ve **gelecek**. Şu anda olmayan, %100 kesin olmayan ama olursa kayıp getirecek olay.
- Risklerle iki şekilde başa çıkılır: önceden önlem almak veya gerçekleşince uygulanacak bir B planı hazırlamak.
- İş riskleri son yıllarda öne çıktı. Yazılım firmalarında pazarlama bilgisi olan kişilere de ihtiyaç var.
- Risk tablosu kurulurken: risk tanımlanır, kategorisi belirlenir, olasılığı ve etkisi (düşük/orta/yüksek) tahmin edilir. İkisinin birleşimi riskin büyüklüğünü verir.
- Slayttaki örnek özet risk tablosu (kareden alındı):

| No | Ad | Tür | Etki | Olasılık |
| --- | --- | --- | --- | --- |
| 01 | Organizasyon | Proje | Orta | Yüksek |
| 02 | Tahmin | Proje | Büyük | Düşük |
| 03 | Kullanışlılık | Teknik | Büyük | Düşük |
| 04 | Doğruluk | Teknik | Orta | Düşük |
| 05 | Güvenirlik | Teknik | Büyük | Düşük |
| 06 | Personel | Proje | Küçük | Düşük |
| 07 | Araçlar | Teknik | Orta | Orta |
| 08 | Metot | Teknik | Orta | Orta |
| 09 | Pazarlama | İş | Büyük | Yüksek |

- Slaytın sonucu: 4, 6, 7 ve 8 numaralı risklerin izlenmesine gerek yok. Diğerleri için ayrıntılı risk bilgi sayfası hazırlanmalı.
- Etkisi küçük ve olasılığı düşük riskler izlenmez. Etkisi büyük ya da olasılığı yüksek olanlar milestone'larda yeniden değerlendirilir: olasılık değişti mi, hangi önlem gerekiyor?
- Örnek risk bilgi sayfası: pazarlama riski.
  - Durum: firmada yalnızca yazılımcılardan oluşan bir çekirdek kadro var, ürünün piyasada çok alternatifi var.
  - İşaretler: ürün satılamıyor, fiyatlandırma iyi yapılmıyor.
  - Önlemler: bir yazılımcıya pazarlama alanında MBA yaptırmak, gereksinim aşamasında alan uzmanından danışmanlık almak, bir iki firmayı pilot müşteri olarak uygun fiyatla almak.
- Her önlemin bir maliyeti vardır. Hangi önlemin alınacağına maliyetine bakılarak karar verilir.

### Gantt diyagramı ve araçlar

- Gantt diyagramında WBS'deki işler satırlarda görülür. Alt kırılımı olan işler koyu renkte, milestone'lar eşkenar dörtgenle gösterilir.
- MS Project dışında birçok açık kaynaklı proje yönetimi aracı var. Bu araçlar Gantt ve PERT diyagramlarını çizer, planla gerçekleşeni ve kaynakları takip eder.
- Büyüklük ölçüm yöntemleri bu dönem işlenmedi. Hoca bunları proje sunumları sırasında anlatabileceğini söyledi.

### Duyurular

- Gelecek hafta asistanın yapacağı bir uygulama dersi var. Ondan sonraki iki hafta proje sunumları yapılacak. Bu yüzden bu ders konu anlatımının son dersi.
- Sunumlar online veya sınıfta yapılabilir. Devam zorunluluğu yok ama grubun bütün üyeleri sunuma katılmalı ve soruları cevaplamalı.
- İlk sunum haftasında sunmak isteyen gruplar hocaya e-posta atmalı. Gönüllü gruplara biraz daha fazla puan verilecek; diğerleri rastgele iki haftaya bölünecek.
- Not dağılımı: ara dönem notu %60 (yaklaşık yarısı proje, yarısı vize; oran öğrencilerin lehine değişebilir), final %40.
- Final yüz yüze yapılacak ve büyük olasılıkla test olmayacak; modelleme soruları yazılı çözülecek. Final programı bölüm tarafından gelecek hafta açıklanacak.

### Ders sonrası notlar

- Altyazıdaki "MacCall/Maccol" doğru yazımıyla **McCall** (Jim McCall, 1977). Modelin üç bakış açısının adları ürün işletimi (product operation), ürün geçişi (product transition) ve ürün revizyonudur (product revision). Hocanın "operatörlerin bakış açısı" dediği grup aslında yazılımın başka ortamlara aktarılmasıyla ilgili ürün geçişidir.
- Hocanın "ISO 9126'da görebiliyoruz" diyerek saydığı liste daha çok McCall faktörlerine karşılık geliyor. ISO/IEC 9126 altı ana özellik tanımlar: işlevsellik, güvenilirlik, kullanılabilirlik, verimlilik, bakım yapılabilirlik ve taşınabilirlik. Bu standardın yerini 2011'de ISO/IEC 25010 aldı.
- "Ayn Summerville" doğru yazımıyla **Ian Sommerville**. "SMMI" ise **CMMI** (Capability Maturity Model Integration).
- PMI'ın açılımı Project Management Institute. Çevik projeler için verilen sertifikanın adı PMI-ACP (Agile Certified Practitioner).
- Hocanın andığı IEEE standardı IEEE 1058 (Software Project Management Plans). Bu standart bugün ISO/IEC/IEEE 16326 içinde yer alıyor.
- PMI'ın PMBOK rehberi proje yönetimini beş süreç grubuna ayırır: başlatma, planlama, yürütme, izleme ve kontrol, kapanış. Hocanın "dört ya da beş adım" dediği yapı budur.
- Slayttaki tabloda 7 ve 8 numaralı risklerin etkisi ve olasılığı "Orta" olarak yazılmış. Ancak aynı slayttaki grafikte küçük etki-düşük olasılık bölgesine konmuşlar ve "izlenmesine gerek yok" denmiş. Tablo ile grafik bu iki riskte tutarsız.
- Hocanın "şeflik sistemi" dediği yapı literatürde baş programcı ekibi (chief programmer team), "demokratik" dediği ise egosuz (egoless) ekip olarak geçer.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
