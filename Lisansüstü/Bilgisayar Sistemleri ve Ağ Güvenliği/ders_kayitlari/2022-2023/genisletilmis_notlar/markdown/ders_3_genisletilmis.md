# Ders 3 Genişletilmiş Notu: BT Güvenlik Yönetimi ve Risk Değerlendirmesi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Yapısı ve Yönetim Sorunları Bölümü
- 2. BT Güvenlik Yönetimine Genel Bakış
- 3. ISO/IEC 27000 Standart Ailesi
- 4. BT Güvenlik Yönetiminin Tanımı ve İşlevleri
- 5. Güvenlik Yönetimi Süreci ve Çevrimi
- 6. Kurumsal Bağlamda Güvenlik Politikası
- 7. Risk Değerlendirme Yaklaşımları
- 8. Ayrıntılı Risk Analizi Süreci
- 9. Terimler: Varlık, Tehdit, Güvenlik Açığı, Risk
- 10. Tehditlerin ve Güvenlik Açıklarının Belirlenmesi
- 11. Risklerin Analizi ve Mevcut Kontroller
- 12. Olasılık, Sonuç ve Risk Seviyeleri
- 13. Risk Kaydı
- 14. Risk Çözümleme Alternatifleri
- 15. Vaka Çalışması: Gümüş Yıldız Madenleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Yapısı ve Yönetim Sorunları Bölümü

Hoca derse, bu lisansüstü dersin lisans programındaki bilgisayar güvenliği dersinin üzerine kurulduğunu hatırlatarak başladı. Lisans dersinde anlatılan konuların bilinmesi varsayılıyor; bu dersin konuları onların üzerine eklenecek.

Ders üç ana bölümden oluşuyor:

- Bilgisayar sistemlerinin güvenliğiyle ilgili yönetimsel konular. Bu bölümde altı alt başlık (altı bölüm) vardır.
- Şifreleme: açık anahtarlı şifreleme, mesaj güvenliği ve bilgi güvenliği.
- Güvenlik protokolleri.

Yönetim Sorunları bölümünün içeriği slaytta şöyleydi (ekrandan, 00:05:00):

- 2.1 BT Güvenlik Yönetimi ve Risk Değerlendirmesi
- 2.2 BT Güvenlik Kontrolleri, Planları ve Prosedürleri
- 2.3 Fiziksel ve Altyapı Güvenliği
- 2.4 İnsan Kaynakları Güvenliği
- 2.5 Güvenlik Denetimi
- 2.6 Bilişim Güvenliğinde Yasal ve Etik Hususlar

Hoca bu sıralamanın mantığını şöyle kurdu. Güvenlikten söz ederken bütüncül bir sistem düşünülür: kenardaki sunuculardan kablolu cihazlara ve bilgisayarlara kadar bütün donanım; örneğin bir üniversitenin bütün sistemi ya da çalışılan bir firmanın genel güvenliği. Böyle bir sistemi güvenlik altına almanın birinci yolu, güvenlikle ilgili risklerin belirlenmesi ve değerlendirilmesidir. Riskler bilinmezse güvenlik doğru ve yeterli şekilde sağlanamaz.

Riskler değerlendirildikten sonra üç tür karar verilir:

- Bazı riskler göze alınır.
- Bazı riskler için yatırım yapılır ve önlem alınır.
- Bazı riskler devredilir.

Devretmeye örnek olarak e-posta sunucusu verildi. E-posta sunucusunun riskini kurum içinde taşımak yerine bu hizmet büyük bir bulut sağlayıcısından alınabilir.

Riskler belirlendikten sonra güvenliğin nasıl sağlanacağı planlanır ve prosedürleri belirlenir (2.2). Hoca burada önemli bir uyarı yaptı: bilişim güvenliği denince herkesin aklına mantıksal (lojik) önlemler geliyor. Güvenlik duvarı (firewall) kurulur, IDS ve IPS alınır. Ama bu yetmez. Biri fiziksel olarak gelip yangın çıkarırsa, diski alırsa, kabloyu çekerse ya da fiber optik kabloyu keserse sistem artık güvende değildir. Bu yüzden fiziksel ve altyapı güvenliği (2.3) de toplam sistem güvenliğinin parçasıdır. Bilgisayar sistemini kullanan, bakımını yapan ve güvenliğini sağlayan insan olduğu için insan kaynakları güvenliği (2.4) ayrı bir konudur.

> **Hocanın vurgusu:** Güvenlik anahtar teslim edilip "yap ve unut" denecek bir iş değildir. 7/24 denetlenmesi ve denetim mekanizmalarının kurulması gerekir (2.5).

Son olarak bir güvenlik olayı yaşandığında bunun yasal sonuçları, yasal takibi ve etik boyutu ele alınır (2.6).

Bu dersin içeriği ise şöyle sıralandı: BT güvenlik yönetimine genel bakış, kurumsal bağlamda güvenlik politikaları, güvenlik risk değerlendirmesi, ayrıntılı güvenlik risk analizi ve bir vaka çalışması (Gümüş Yıldız / Silver Star maden şirketi için risk değerlendirmesi).

## 2. BT Güvenlik Yönetimine Genel Bakış

Slaytın başlığı "BT Güvenlik Yönetimine Genel Bakış" idi ve soruları cevaplamanın resmi süreci üç kutu ile gösteriliyordu (ekrandan, 00:10:00):

```text
Hangi varlıkların korunması gerekir?
        -->  Bu varlıklar nasıl tehdit ediliyor?
                -->  Bu tehditlere karşı ne yapılabilir?
```

Hocaya göre bilgisayar sistemlerinin güvenliği aslında bu üç soruya verilen cevapların bir sürecidir.

- **Hangi varlıklar korunmalı?** Bir firmada ya da kurumda her varlığın korunmasına ya da her varlık için yatırım yapılmasına gerek yoktur. Önce korunması gereken varlıklar belirlenir.
- **Bu varlıklara hangi tehditler var?**
- **Bu tehditlere karşı ne yapılabilir?** Korumak için hangi tedbirler alınabilir?

Slayttaki maddeler bu sürecin sonucunu özetliyordu:

- Kritik varlıkların uygun maliyetli bir şekilde yeterince korunmasını sağlar.
- Kuruluşta koruma gerektiren her varlık için güvenlik riski değerlendirmesi gereklidir. Yani o varlığa hangi riskler var ve bu risklerin olma olasılığı nedir?
- Belirlenen riskleri azaltmak için hangi yönetimsel, operasyonel ve teknik kontrollerin gerekli olduğuna karar vermek için gerekli bilgileri sağlar.

### 2.1 Uygun maliyet: sigorta benzetmesi

Hoca "uygun maliyet" kavramını bir benzetmeyle açtı. Korumanın maliyeti varlığın kendisinden büyükse korumanın anlamı yoktur; "kaybolsun, yenisini alırım" denir. Bir araba aldığınızı düşünün. Kasko yaptırmak istiyorsunuz ama kaskonun bedeli arabanın değerinin önemli bir kısmı kadar. Kapalı bir otoparkınız varsa ve iyi bir sürücü olduğunuzu düşünüyorsanız bu parayı vermeye değmeyeceğine karar verebilirsiniz. Güvenlikte de varlık, maliyetine uygun düzeyde, yeterince korunmalıdır.

## 3. ISO/IEC 27000 Standart Ailesi

Hoca güvenlik yönetiminin de bir standardı olduğunu söyledi: ISO 27000 serisi. Anlattığı standartlar şunlardı:

| Standart | Konu |
|---|---|
| ISO 27000 | Bilgi güvenliği yönetim sistemlerine (BGYS) genel bakış ve terimler |
| ISO 27001 | BGYS gereksinimleri: belgelenmiş bir BGYS'nin kurulması, uygulanması, işletilmesi, izlenmesi, gözden geçirilmesi, sürdürülmesi ve iyileştirilmesi |
| ISO 27002 | Bilgi güvenliği yönetimi için uygulama kuralları; eskiden ISO 17799 olarak biliniyordu, sonra 27002 olarak yeniden adlandırıldı |
| ISO 27003 | BGYS uygulama kılavuzu: spesifikasyon ve tasarımın başlangıcından uygulama planlarının üretilmesine kadar olan süreç |
| ISO 27004 | Bilgi güvenliği yönetimi ölçme: BGYS süreç ve kontrollerinin etkinliğinin ölçülmesi ve raporlanması için rehberlik |
| ISO 27005 | Bilgi güvenliği risk yönetimi; ISO 13335'in 3. ve 4. bölümlerinin yerini aldı |
| ISO 27006 | BGYS denetimi ve belgelendirmesi yapan kuruluşlar için gereklilikler |

Hoca standartların yayın yıllarını da söyledi: 27000 için 2016, 27001 için 2013, 27002 için 2013, 27003 için 2010, 27005 için 2011, 27006 için 2015.

<!-- BELİRSİZ: Standart slaytı karelerde yok; numaralar ve yıllar altyazıdan alındı ve altyazıda bozuk yazılmış ("İstor 27.000", "2027.001", "13.335'e 3 ve 4"). -->

> **Ek bilgi (derste anlatılmadı):** Bu standartların çoğu sonradan güncellendi; örneğin ISO/IEC 27001 ve 27002'nin 2022 sürümleri yayımlandı. Derste söylenen yıllar büyük olasılıkla ders kitabının baskısındaki sürümlerdir.

Bu standartların belgelerine internet üzerinden ayrıntılı olarak ulaşılabilir.

## 4. BT Güvenlik Yönetiminin Tanımı ve İşlevleri

Slayttaki tanım şöyleydi (ekrandan, 00:15:00):

> BT güvenlik yönetimi: Uygun düzeyde gizlilik, bütünlük, kullanılabilirlik, hesap verebilirlik, özgünlük ve güvenilirlik elde etmek ve sürdürmek için kullanılan bir süreçtir.

Hoca tanımdaki iki fiile dikkat çekti: bu özellikler önce elde edilir, sonra sürdürülür. Güvenlik yönetimi bunun için kullanılan süreçler bütünüdür.

BT güvenlik yönetimi işlevleri slaytta sekiz sütunla verilmişti (ekrandan, 00:15:00):

- Kurumsal BT güvenlik hedeflerinin, stratejilerinin ve politikalarının belirlenmesi. Hoca bunu "üst akıl" olarak niteledi: yönetimsel olarak önce stratejiler ve politikalar belirlenir.
- Kurumsal BT güvenlik gereksinimlerinin belirlenmesi.
- Kuruluş içindeki BT varlıklarına yönelik güvenlik tehditlerini belirleme ve analiz etme.
- Riskleri belirleme ve analiz etme.
- Uygun güvenlik önlemlerinin belirtilmesi.
- Kuruluş içindeki bilgi ve hizmetleri maliyet etkin bir şekilde korumak için gerekli olan koruma önlemlerinin uygulanmasının ve işleyişinin izlenmesi.
- Bir güvenlik farkındalık programı geliştirme ve uygulama.
- Olayları algılama ve tepki verme.

Farkındalık programı üzerinde hoca ayrıca durdu. Bütün çalışanlar güvenlik stratejilerinden, politikalarından ve risklerden haberdar edilmeli; güvenliğin önemini kavramalı ve kendilerine düşen görevleri bilmelidir. Ancak o zaman üzerine düşeni yapmayan biri sorumlu tutulabilir ve sonuçlarına katlanır.

Son işlev, bütün tedbirlere rağmen bir güvenlik olayı yaşanırsa bunu algılamak ve ona karşı tepki (reaksiyon) vermektir.

> **Hocanın vurgusu:** Güvenlik yönetimi yukarıdan aşağıya (top-down) bir süreçtir; en tepeden en alta kadar güvenlikle ilgili her süreci içine alır.

## 5. Güvenlik Yönetimi Süreci ve Çevrimi

Hoca güvenlik yönetimi sürecini bir akış olarak anlattı:

```text
Girdi: güvenlik politikaları ve organizasyonel bağlam (politikalar, stratejiler)
  -> Risk analizi seçeneği: temel, gayri resmi, formal (ayrıntılı) ya da bütünleşik
  -> Önlemlerin belirlenmesi
  -> Gerçekleme (uygulama)
  -> Takip: bakım, güvenlik güncellemelerinde değişim yönetimi, olay müdahalesi
```

Ardından bunun bir çevrim olduğunu gösterdi. İlgili taraflar (paydaşlar) ve bilgi güvenliği ihtiyaçları girdidir. Bu ihtiyaçlara ve ilgili taraflardan gelen girdilere göre bir güvenlik planı yapılır. Plan icra edilir, sonra kontrol edilir. Kontrol sonuçlarına göre yönetim düzeyinde gerekli değişiklikler yapılır; bu bir yönetmelik değişikliği de olabilir, bir yönetimsel emir de. Uygulamada çıkan sonuçlara göre yeniden planlama, yeniden icra yapılır ve çevrim sürekli devam eder.

<!-- BELİRSİZ: Çevrim diyagramının slaydı karelerde yok; aşamalar altyazıdaki anlatımdan kuruldu. -->

> **Ek bilgi (derste anlatılmadı):** Bu çevrim ISO 27001'de kullanılan Planla-Uygula-Kontrol Et-Önlem Al (Plan-Do-Check-Act, PDCA) modeline karşılık gelir. Girdisi ilgili tarafların bilgi güvenliği gereksinimleri, çıktısı yönetilen bilgi güvenliğidir.

## 6. Kurumsal Bağlamda Güvenlik Politikası

Slayt (ekrandan, 00:20:00) politikanın iki özelliğini veriyordu:

- Düzenli olarak sürdürülür ve güncellenir:
  - Periyodik güvenlik incelemeleri kullanılır. Tedbirler alındıktan sonra da süreç içinde sorun olup olmadığı periyodik olarak incelenir.
  - Değişen teknik ve risk ortamları yansıtılır. Teknoloji ve riskler değiştikçe politika da güncellenir.
- BT sistemlerinin organizasyondaki rolü ve önemi incelenir.

Slaytın sağ tarafında "Önce kuruluşun BT güvenliğini inceleyin" başlığı altında üç kutu vardı:

- **Hedefler:** istenen BT güvenliği sonuçları. Bilgi güvenliği olarak hangi hedeflere ulaşmak istiyoruz?
- **Stratejiler:** hedeflere nasıl ulaşılır.
- **Politikalar:** yapılması gerekenler.

### 6.1 Güvenlik politikasının ele alması gereken konular

Hoca güvenlik politikasında çözüm bulunması (adreslenmesi) gereken konuları şöyle sıraladı:

- Politikanın amacı ve kapsamı. Hedeflerin iş, yasal ve düzenleyici gerekliliklerle ilişkisi de buna dahildir; yani yapılan iş ve bu işi bağlayan kanunlar, yönetmelikler, yönergeler.
- BT güvenliği gereksinimleri.
- Sorumlulukların belirlenmesi.
- Risk yönetimi yaklaşımı: temel mi, gayri resmi mi, formal mi, bütünleşik mi?
- Güvenlik farkındalığı ve gerekli eğitimler.
- Genel personel konuları ve yasal yaptırımlar.
- Güvenliğin sistem geliştirmeye entegrasyonu.
- Bilgilerin sınıflandırılması. Hoca nedenini açıkladı: bir güvenlik ihlalinin sonuçları, bilginin türüne bağlı olarak farklı olur.
- Acil durum ve iş sürekliliği planlaması.
- Olay algılama ve işleme süreçleri.
- Politikanın nasıl ve ne zaman gözden geçirileceği ve değişikliklerin nasıl kontrol edileceği.

> **Hocanın vurgusu:** Güvenlik çalışmalarında birinci şart yönetim desteğidir. BT güvenlik politikası üst yönetim tarafından desteklenmelidir.

## 7. Risk Değerlendirme Yaklaşımları

Aradan sonra hoca, güvenlik yönetiminin riskin belirlenmesi ve değerlendirilmesiyle başladığını hatırlattı. Risk değerlendirmesi sürecin kritik bileşenidir. Kurumsal olarak her varlık için güvenlik önlemi almak gerekmeyebilir; bu yüzden varlıkların üzerindeki riskler değerlendirilmelidir.

Bu kısmın slaytı ders arasında hocanın ekranında görünüyordu (ekrandan, 00:25:00): "Güvenlik Riski Değerlendirmesi" başlığı altında "Sürecin kritik bileşeni", "İdeal olarak her kurumsal varlığı inceleyin", "Pratikte pek mümkün değil" ve "Bir kuruluşun BT altyapısına yönelik riskleri belirleme ve azaltmaya yönelik yaklaşımlar" kutuları; yaklaşımlar listesi: Temel, Gayri resmi, Ayrıntılı risk, Bütünleşik.

İdeal olan kurumdaki her varlığın incelenmesidir, ama bu pratikte pek mümkün değildir. Bu yüzden dört yaklaşım vardır.

### 7.1 Temel (baseline) yaklaşım

Amaç, en yaygın bilinen tehditlere karşı koruma sağlamak için üzerinde anlaşmaya varılmış, yaygın kontrolleri uygulamaktır.

- Daha fazla güvenlik önlemi için iyi bir temel oluşturur; bir başlangıçtır.
- Endüstrinin en iyi uygulamalarını (best practice) kullanır.
- Ucuz ve kolaydır.
- Yaygınlaştırılabilir: aynı en iyi uygulamalar başka yerlere de uygulanabilir.
- Kuruluşun riske maruz kalma biçimindeki farklılıklara özel önlem vermez. Genel en iyi uygulamaları içerdiği için bazı kurumlarda yeterli, bazılarında çok az güvenlik sağlayabilir.
- Daha yapılandırılmış yaklaşımlar için kaynağı olmayan küçük kuruluşlara önerilir.

### 7.2 Gayri resmi (informal) yaklaşım

Slayttaki maddeler (ekrandan, 00:40:00):

- Kuruluşun BT sistemleri üzerinde resmi olmayan, pragmatik bir risk analizi yürütmeyi içerir.
- Analistin bilgi ve uzmanlığından yararlanır.
- Oldukça hızlı ve ucuzdur.
- Temel yaklaşımın ele almadığı güvenlik açıkları ve riskler hakkında yargıda bulunulabilir.
- Bazı riskler yanlış değerlendirilebilir.
- Analistin görüşlerine göre çarpık olabilir, zamana göre değişir.
- BT sistemlerinin zorunlu olmadığı küçük ve orta ölçekli kuruluşlar için uygundur.

Hoca bu yaklaşımı temel yaklaşımla karşılaştırdı. Temel yaklaşım gibi genel en iyi uygulamalara dayanmaz, kuruma daha özel yapılabilir. Ama gayri resmi olduğu için analistin bilgi ve uzmanlığıyla sınırlıdır. Bu yüzden o da küçük ve orta ölçekli kuruluşlara önerilir.

### 7.3 Ayrıntılı (detaylı) risk analizi

En kapsamlı yaklaşımdır. Resmi, yapılandırılmış bir süreç kullanılarak değerlendirilir. Varlıklara yönelik tehditlerin ve güvenlik açıklarının belirlenmesi, riskin oluşma olasılığının ve sonuçlarının tanımlanması gibi ayrıntıları içerir.

- Zaman alır.
- Maddi kaynak ve farklı alanlarda uzmanlık gerektirir; temel ve gayri resmi yaklaşıma göre maliyetlidir.
- BT sistemlerinin güvenlik risklerinin en doğru değerlendirmesini sağlar, ama en yüksek maliyetlidir.

Ne zaman gerekir? Varlıkların değeri ya da yapılan iş nedeniyle. Hocanın örnekleri bir e-ticaret sitesi, bir banka, bir internet servis sağlayıcısı (ISS) ve mobil telekom operatörleriydi. Bu tür kuruluşlarda yasal gereklilikler de vardır. Ayrıntılı analiz çoğu zaman devlet kurumları ya da ilgili düzenleyiciler tarafından zorunlu tutulur; örneğin bankalar için minimum güvenlik gereksinimleri nedeniyle kanuni bir zorunluluk olarak istenir.

### 7.4 Bütünleşik (combined) yaklaşım

Temel, gayri resmi ve ayrıntılı risk analizi yaklaşımlarının unsurlarını birleştirir. Amaç, önemli sistemlerde uygulanan koruma kontrollerini incelemek ve ayarlamaktır.

- Yaklaşım, bütün sistemlerde uygun temel güvenlik önlemlerinin uygulanmasıyla başlar.
- Ardından yüksek risk seviyelerine maruz kalan ya da organizasyonun iş hedefleri için kritik olan sistemler, yüksek seviyeli bir risk değerlendirmesiyle belirlenir.
- Bu kritik sistemlerde ayrıntılı analiz yapılır. Bu değerlendirme, kontrolleri gereksinimleri daha doğru yansıtacak şekilde hızlıca uyarlamak için kritik sistemler üzerinde hemen bir gayri resmi değerlendirme yapma kararında da kullanılabilir.

Hoca bunu "yöntemlerin bütünleşiği" olarak özetledi.

## 8. Ayrıntılı Risk Analizi Süreci

Ayrıntılı risk analizi şunları içerir:

- Varlıkların belirlenmesi.
- Tehditlerin belirlenmesi.
- Bu tehditlere göre varlıkların zayıflıklarının (güvenlik açıklarının) belirlenmesi.
- Bu zayıflıklar kullanılarak bir güvenlik ihlaline maruz kalma olasılığının belirlenmesi.
- İhlal olursa kuruma getireceği etkinin belirlenmesi.
- Buna göre risklerin derecelendirilmesi ve gerekli tedbirlerin alınması.

Slayttaki şekil "Figure 14.3 Risk Assessment Process" idi (ekrandan, 00:45:00):

```text
Step 1: Prepare for Assessment (Derived from Organizational Aspects)
   |
   v
Step 2: Conduct Risk Analysis
   - Identify Threat Sources and Events
   - Identify Vulnerabilities and Predisposing Conditions
   - Determine Likelihood of Occurance
   - Determine Magnitude of Impact
   - Determine Risk

Step 3: Communicate Results   <-->  Step 2  <-->  Step 4: Maintain Assessment
```

Yani değerlendirmeye hazırlık kuruluşa ait özelliklerden türetilir. Risk analizinin kendisi tehdit kaynakları ve olaylarını, güvenlik açıkları ve elverişli koşulları, gerçekleşme olasılığını, etkinin büyüklüğünü ve sonuçta riski belirler. Sonuçların iletilmesi ve değerlendirmenin sürdürülmesi analizle sürekli etkileşim içindedir.

### 8.1 Bağlamın oluşturulması

Bağlam oluşturmanın ilk adımı, risk değerlendirmesinin temel parametrelerini belirlemek ve sonra incelenecek varlıkları tanımlamaktır.

- Kuruluşun faaliyet gösterdiği siyasi ve sosyal ortam araştırılır.
- Yasal ve düzenleyici kısıtlamalar (kanunlar, yönetmelikler, yönergeler) ile firmanın misyonu, politikaları ve stratejileri belirlenir.
- Kuruluşun riske maruz kalması için bir temel oluşturulur: risk gerçekleşirse ne olacağının bağlamı kurulur ve güvenlik tedbiri buna göre alınır.
- Kuruluşun kabul edilebilir gördüğü risk seviyesi belirlenir. Bazı riskler için hiç yatırıma gerek görülmeyebilir, bazıları devredilebilir, bazıları için yatırım yapılabilir.

Hoca kurumsal riski sektörlere göre bir yelpaze olarak anlattı: daha az zafiyetli olandan daha çok zafiyetli olana doğru. Tarım, eğitim, inşaat gibi sektörler daha az riskli tarafta; bankacılık ve finans, devlet kurumları, iletişim, sağlık ve üretim gibi sektörler ise riske ve saldırıya karşı daha duyarlı tarafta.

<!-- BELİRSİZ: Sektör yelpazesinin slaydı karelerde yok; altyazıda bazı sektörler (ticaret, iletişim, medya) iki tarafta da geçiyor, tam sıralama belirsiz. -->

### 8.2 Varlıkların belirlenmesi

Amaç, kurumun sahip olduğu varlıklara karşı oluşabilecek riskleri en aza indirmektir. Bu yüzden önce varlık tanımlanmalıdır. Bizim için değerli olan, korunması gereken şey varlıktır. Bağlam oluşturmanın son bileşeni incelenecek varlıkları belirlemektir.

- Önemli varlıkları belirlemek için organizasyonun ilgili alanlarındaki kişilerin uzmanlığından yararlanılır. Hangi personelden yararlanılacağı da belirlenmelidir.
- Bir şeyin varlık sayılması, kuruluş için bir değeri olması ve kuruluşun hedeflerine başarıyla ulaşmasına katkı yapmasındandır.

## 9. Terimler: Varlık, Tehdit, Güvenlik Açığı, Risk

Güvenlik risk analizinde kullanılacak terimler slaytta şöyleydi (ekrandan, 00:50:00):

- **Varlık (asset):** Koruma gerektiren, sahibine değer katan bir sistem kaynağı veya yeteneği.
- **Tehdit (threat):** Bir tehdit kaynağının, bazı varlıklardaki bir güvenlik açığından yararlanma potansiyeli; bu, meydana gelmesi durumunda varlığın güvenliğini tehlikeye atabilir ve varlığın sahibine zarar verebilir.
- **Güvenlik açığı (vulnerability):** Bir varlığın tasarımında, uygulamasında veya işletiminde ve yönetiminde bazı tehditler tarafından kullanılabilecek bir kusur veya zayıflık.
- **Risk:** Belirli bir tehdidin bir varlığa yönelik bazı açıklardan yararlanma olasılığı ile varlığın sahibine yol açan zararlı sonuçların büyüklüğünün birleşimi olarak hesaplanan kayıp potansiyeli.

## 10. Tehditlerin ve Güvenlik Açıklarının Belirlenmesi

### 10.1 Tehdit

Varlığı ve analiz yöntemini belirledikten sonra sıra tehditlere gelir. Tehdit, bir varlığın uygun düzeyde temel güvenlik hizmeti sunmasını engelleyecek herhangi bir şeydir. Tehdit; varlığın gizliliğine, bütünlüğüne, kullanılabilirliğine, hesap verebilirliğine, özgünlüğüne ya da güvenilirliğine yönelik olabilir. Bu altı özelliği bozabilecek her şey tehdit olarak tanımlanabilir.

Tehdidin kaynakları:

- **Doğal:** Bir veri merkezinin deprem, sel ya da şiddetli kış nedeniyle zarar görmesi.
- **İnsan yapımı:** Birinin yangın çıkarması gibi. İnsan kaynaklı tehdit kasıtlı da olabilir, kazara da.

İnsan kaynaklı tehditler değerlendirilirken dikkate alınanlar:

- **Motivasyon:** Kişi bunu neden yapıyor?
- **Yetenek:** Saldırganın kabiliyeti.
- **Kaynaklar:** Saldırıyı yaparken ne tür araçlar ve yazılımlar kullanıyor?
- **Saldırmaya değer bulma ve caydırıcılık:** "Bunu yaparsam sonuçları ne olur?" Sonuçlar kişiyi vazgeçirecek kadar caydırıcı mı?
- **Önceki saldırı deneyimi:** Kuruluşun daha önce yaşadığı saldırılar dikkate alınarak hem değerlendirme hem güncellemeler buna göre yapılır.

### 10.2 Güvenlik açığı

Güvenlik açığının tanımlanması, kuruluşun BT sistemlerindeki ya da süreçlerindeki istismar edilebilir kusurların ve zayıflıkların bulunmasıdır. Bunları bilmek gerekir ki ortadan kaldırılabilsin.

- Güvenlik açıkları, bir tehdidin kuruluşa uygulanabilirliğini ve önemini belirler.
- Bir varlık üzerinde risk oluşması için tehdit ve güvenlik açığı kombinasyonu gerekir: bir varlık olacak, o varlığa bir tehdit olacak ve tehdidi gerçekleştirecek kişinin kullanacağı bir güvenlik açığı olacak.
- Bu adımın çıktısı, tehditlerin ve güvenlik açıklarının, nasıl ve nereden gelebileceklerine dair kısa açıklamalarla birlikte bir listesidir.

## 11. Risklerin Analizi ve Mevcut Kontroller

Slayttaki maddeler (ekrandan, 00:55:00):

- Mevcut kontroller göz önüne alındığında, varlığa yönelik olarak tanımlanan her tehdidin gerçekleşme olasılığını belirtin.
- Tehdit meydana geldiğinde sonucu belirtin.
- Her tehdit için genel risk derecesini türetin:
  - Risk = olasılık tehdidi oluşur × kuruluş için maliyet
- Kesin olasılıkları ve gerçekçi maliyet sonuçlarını belirlemek zor.
- Niceliksel değil niteliksel derecelendirmeler kullanın.

Slayttaki formül, yazımı düzeltilerek şöyle okunabilir:

$$\text{Risk} = P(\text{tehdidin gerçekleşmesi}) \times \text{kuruluş için maliyet}$$

Hoca, kesin olasılıkları ve gerçekçi maliyetleri belirlemek her zaman mümkün olmasa da analizde tahmini değerler bulunması gerektiğini söyledi; bunun için sayısal değil, kademeli (niteliksel) değerlendirmeler kullanılır.

> **Ders sonrası not:** Hoca niteliksel değerlendirmeyi bir yerde "yani kuantatif" diye açıkladı; doğrusu "kalitatif"tir. Niteliksel = qualitative, niceliksel = quantitative.

### 11.1 Mevcut kontrollerin analizi

Tehditleri en aza indirmek için zaten kullanılan kontroller tanımlanır. Güvenlik kontrolleri şunları içerir:

- Yönetimsel kontroller
- Operasyonel kontroller
- Teknik kontroller
- Süreçler ve prosedürler

Bu bilgiyi toplamak için kontrol listeleri kullanılır ve kuruluşun kilit personeliyle görüşülür.

## 12. Olasılık, Sonuç ve Risk Seviyeleri

### 12.1 Risk olasılığı (beş kademe)

| Derece | Olasılık | Açıklama (hocanın anlatımı) |
|---|---|---|
| 1 | Nadiren | Yalnız istisnai durumlarda ortaya çıkabilir; olursa "şanssızlık" olarak görülür. |
| 2 | Olası olmayan | Mevcut kontroller ve koşullar altında beklenmez, ama "Murphy kuralı" gereği bazen olabilir. |
| 3 | Mümkün | Bir süre sonra ortaya çıkabilir; olma ve olmama olasılığı yaklaşık eşittir. Dış etkiler yüzünden oluşumunu kontrol etmek zordur. |
| 4 | Büyük ihtimalle | Bazı durumlarda ortaya çıkar; gerçekleşirse şaşırmamak gerekir. |
| 5 | Neredeyse kesin | Çoğu durumda ve er geç gerçekleşmesi beklenen riskler için kullanılır. |

<!-- BELİRSİZ: Olasılık tablosunun slaydı karelerde yok; tanımlar altyazıdan alındı. -->

### 12.2 Risk sonuçları (altı kademe)

Slayttaki tablo (ekrandan, 01:00:00):

| Derece | Sonuç | Genişletilmiş tanım |
|---|---|---|
| 1 | Önemsiz | Genellikle tek bir alanda küçük bir güvenlik ihlalinin sonucudur. Etki muhtemelen birkaç günden az sürecektir ve düzeltilmesi için yalnızca küçük harcamalar gerekir. Genellikle kuruluşa somut bir zararla sonuçlanmaz. |
| 2 | Küçük | Bir veya iki alanda güvenlik ihlalinin sonucudur. Etki muhtemelen bir haftadan az sürecektir, ancak yönetim müdahalesi olmaksızın segment veya proje düzeyinde ele alınabilir. Genellikle proje veya ekip kaynakları dahilinde düzeltilebilir. Kuruluş için somut zarara yol açmaz, ancak geriye dönüp bakıldığında kaybedilen fırsatları veya verimlilik eksikliğini gösterebilir. |
| 3 | Orta | Sınırlı sistemik (ve muhtemelen devam eden) güvenlik ihlalleri. Etki muhtemelen 2 haftaya kadar sürecektir ve genellikle yönetim müdahalesi gerektirecektir, ancak yine de proje veya ekip düzeyinde ele alınabilmelidir. Bazı devam eden uyum maliyetleri gerekecektir. Müşteriler veya halk sınırlı bilgiye sahip olabilir. |
| 4 | Ciddi | Devam eden sistemik güvenlik ihlali. Etki muhtemelen 4-8 hafta sürecek ve önemli yönetim müdahalesi ve kaynakları gerektirecektir. Üst yönetim olay süresince doğrudan yönetimi sürdürmek zorundadır; uyum maliyetlerinin önemli olması beklenir. Müşteriler veya halk olaydan haberdar olur. İş veya organizasyonel sonuçların kaybı mümkündür, ancak özellikle bir defaya mahsus ise beklenmez. |
| 5 | Katastrofik (felaket) | Büyük sistemik güvenlik ihlali. Etki 3 ay veya daha fazla sürecek ve eksikliklerin giderilmesi için üst yönetimin etkinlik süresince müdahale etmesi gerekecektir. Uyum maliyetlerinin çok yüksek olması beklenir. Müşteri iş kaybı veya kuruluşa diğer önemli zararlar beklenir. Önemli kamu tartışmaları ve güven kaybı, ilgili personele karşı olası cezai veya disiplin cezası muhtemeldir. |
| 6 | Kıyamet günü | Büyük sistemik güvenlik ihlallerinin birden çok örneği. Etki süresi belirlenemez ve üst yönetimin şirketi gönüllü yönetime veya diğer büyük yeniden yapılandırma biçimlerine tabi tutması gerekecektir. Üst yönetime karşı cezai takibat beklenir; önemli ölçüde iş kaybı ve kurumsal hedeflere ulaşılamaması kaçınılmazdır. Uyum maliyetleri, muhtemelen organizasyonun tasfiyesiyle birlikte, bazı yıllar için yıllık kayıplarla sonuçlanır. |

Hoca katastrofik seviyede üst yönetimin ya bilgilendirilmesi ya da doğrudan müdahale etmesi gerektiğini, sonucun iş kaybı ve ciddi zarar olabileceğini söyledi. Kıyamet gününde ise "dükkanı kapatıp gitmek" gibi bir sonuç da mümkündür: şirket kayyuma ya da büyük bir yeniden yapılandırmaya gidebilir.

### 12.3 Risk seviyesi ve gerektirdiği yönetim

Olasılık ve sonuç birleştirilince risk dört seviyede tanımlanır:

| Risk seviyesi | Gereken yönetim |
|---|---|
| Ekstrem | Bir yönetici ya da direktör tarafından ayrıntılı araştırma ve yönetim planlaması gerekir. |
| Yüksek | Yönetimin dikkati gerekir; ancak yönetim ve planlama üst düzey proje ve ekip liderlerince yapılabilir. |
| Orta | Mevcut özel izleme ve müdahale prosedürleriyle yönetilebilir. |
| Düşük | Rutin prosedürlerle yönetilebilir. |

### 12.4 Risk seviyesi matrisi

Hocanın sözlü anlatımına göre matris şöyledir:

| Olasılık \ Sonuç | Kıyamet günü | Katastrofik | Ciddi | Orta | Küçük | Önemsiz |
|---|---|---|---|---|---|---|
| Neredeyse kesin | Ekstrem | Ekstrem | Ekstrem | Ekstrem | Yüksek | Yüksek |
| Büyük ihtimalle | Ekstrem | Ekstrem | Ekstrem | Yüksek | Yüksek | Orta |
| Mümkün | ? | ? | ? | ? | ? | ? |
| Olası olmayan | ? | ? | ? | ? | ? | ? |
| Nadiren | Ekstrem | Yüksek | Yüksek | Orta | Düşük | Düşük |

<!-- BELİRSİZ: Matris slaydı karelerde yok. Hoca "mümkün" satırının "büyük ihtimalle" ile aynı olduğunu söyledi, "olası olmayan" satırını anlatmadı. Ancak aynı dersteki vaka risk kaydında "mümkün + küçük = orta" verilmiş; bu, "büyük ihtimalle" satırıyla (küçük = yüksek) çelişiyor. -->

> **Ek bilgi (derste anlatılmadı):** Dersin kaynak kitabındaki matriste "mümkün" satırı büyük olasılıkla ekstrem, ekstrem, ekstrem, yüksek, orta, düşük; "olası olmayan" satırı ise ekstrem, ekstrem, yüksek, orta, düşük, düşük biçimindedir. Bu satırlar derste ve karelerde doğrulanmadı; vaka çalışmasındaki "mümkün + küçük = orta" sonucu ilk satırla uyumludur.

## 13. Risk Kaydı

Her varlık için bir risk kaydı (risk register) tutulur. Kayıtta varlık, tehdit ya da güvenlik açığı, mevcut kontroller, olma olasılığı, sonuç, risk seviyesi ve risk önceliği yer alır. Hoca iki satırlık bir örnek anlattı (derste sözlü, 01:02:20):

| Varlık | Tehdit / açık | Mevcut kontrol | Olasılık | Sonuç | Risk seviyesi | Öncelik |
|---|---|---|---|---|---|---|
| İnternet yönlendiricisi | Dışarıdan saldırgan (hacker) saldırısı | Yalnız yönetici parolası | Mümkün | Orta | Yüksek | 1 |
| Veri merkezi | Kaza sonucu yangın ya da su baskını | Felaket kurtarma planı yok | Olası olmayan | Ciddi | Yüksek | ? |

<!-- BELİRSİZ: Bu tablonun slaydı karelerde yok; değerler altyazıdan alındı. İkinci satırın önceliği altyazıda söylenmeden kesildi. -->

Hocanın gerekçeleri şöyleydi:

- **Yönlendirici:** Giriş kullanıcı adı ve parolayla yapılıyor. Basit parolalar ya da birden çok kullanıcının aynı parolayı kullanması durumunda parola kırma algoritmalarıyla erişim mümkündür; bu yüzden olasılık "mümkün". Yönlendirici bozulursa internet erişimi bozulur, ama doğrudan işe bağlı olmadığı için sonuç "orta". Risk seviyesi yüksek; yani yönetim bilgilendirilir ama ekip liderleri çözebilir. Olasılığı daha sık ve etkisi yüksek olduğu için önceliği birinci.
- **Veri merkezi:** Kaza sonucu yangın, deprem ya da su baskını tehdittir. Bazı önlemler (yangın söndürme cihazları, su baskınına karşı tedbirler) olabilir, ama bir felaket kurtarma planı yoktur; veri merkezine bir şey olursa sistemi başka bir yere aktarma imkanı yoktur. Olasılık çok düşük, sonuç ciddi, risk seviyesi yüksek.

Risk yönetimi değerlendirilirken risk seviyesi ile önlem maliyeti birlikte düşünülür. Risk düşükse daha az maliyetli önlemler yeterlidir. Risk yüksek ya da ekstremse önlemin (treatment) uygulanması gerekir ve maliyet yukarı doğru artar. Bu yüzden risk yönetiminde bir optimum maliyet hesabı gerekir.

## 14. Risk Çözümleme Alternatifleri

Slayttaki beş alternatif (ekrandan, 01:05:00):

| Alternatif | Slayttaki tanım | Hocanın örneği |
|---|---|---|
| Risk kabulü | İş nedenleriyle normalden daha yüksek bir risk düzeyini kabul etmeyi seçmek | Veri merkezi için yangına karşı ek tedbir almamak; bir web sitesindeki anket, forum ya da çerezler için önlem almamak |
| Riskten kaçınma | Bu riski oluşturan faaliyet veya sistemle devam etmemek | E-postayla ilgili risk varsa e-posta hizmeti vermemek; dosya paylaşımıyla ilgili risk varsa dosya paylaşmamak |
| Risk transferi | Riskin sorumluluğunu üçüncü bir tarafla paylaşmak | Sigorta yaptırmak; bir güvenlik firmasıyla anlaşmak; ağ yönetimini dışarıdan bir firmaya vermek |
| Sonucu azaltma | Riskin gerçekleşmesi durumunda kuruluş üzerindeki etkiyi azaltmak için risk altındaki varlıkların yapısını veya kullanımını değiştirmek | Dosya paylaşım sistemi kurulur, ama gizli dosyalar o sisteme konmaz |
| Olasılığı azaltma | Güvenlik açığından yararlanma olasılığını azaltmak için uygun kontroller uygulamak | |

## 15. Vaka Çalışması: Gümüş Yıldız Madenleri

### 15.1 Senaryo

Slayttaki maddeler (ekrandan, 01:10:00):

- Küresel madencilik şirketinin hayali operasyonu.
- Geniş BT altyapısı:
  - Hem yaygın hem de özel yazılım.
  - Bazıları doğrudan sağlık ve güvenlikle ilgilidir.
  - Önceden izole edilmiş sistemler artık ağa bağlı.
- Bütünleşik yaklaşıma karar verildi.
- Madencilik endüstrisi, spektrumun daha az riskli tarafında.
- Yasal/düzenleyici gerekliliklere tabi.
- Yönetim orta veya düşük riski kabul ediyor.

Hoca senaryoyu şöyle açtı. Şirket maden çıkarıp pazarlıyor. Yaygın yazılımlar (e-posta, sunucular, muhasebe programları, ERP) yanında özel yazılımlar da var: SCADA tabanlı yazılımlar, raylı sistemler, kontrol sistemleri, aydınlatma ve havalandırma. Havalandırma sistemi, asansör kontrolleri ve elektrik doğrudan sağlık ve güvenlikle ilgilidir. Bu sistemler önceden izole, kapalı bir ağda çalışıyordu; gerekli tedbirler alınırsa tek ağda çalışabileceklerine karar verildi.

Detaylı risk analizi yerine temel, gayri resmi ve formal yaklaşımları birleştiren bütünleşik yaklaşım seçildi. Madencilikte ticari işlem yükü olmadığı ve donanıma özel yazılımlar kullanıldığı için sektör daha az riskli taraftadır. Ama madende bir göçük ya da havalandırma arızası olursa yasal yükümlülükler doğar. Yönetim orta ve düşük riskleri kabul ediyor, yüksek riskler için harcama yapmak istiyor. Analistlerden istenen, riskleri seviyelendirip önceliğe göre sıralayan bir risk analizi raporudur.

### 15.2 Varlıklar

İlgili taraflarla görüşülerek belirlenen varlıklar:

- SCADA düğümlerinin ve ağın güvenilirliği ve bütünlüğü. Bu sistemler önceden harici (ayrı) bir ağdaydı, şimdi ortak ağdadır.
- Depolanan dosya ve veritabanı bilgilerinin bütünlüğü. Hangi müşteriye ne kadar ürün satıldığı, personel kayıtları, sağlık bilgileri ve mali bilgiler burada tutulur.
- Finansal sistemin kullanılabilirliği ve bütünlüğü (availability ve integrity).
- Tedarik sisteminin mevcudiyeti ve bütünlüğü.
- Bakım/üretim sisteminin kullanılabilirliği ve bütünlüğü.
- Posta hizmetlerinin kullanılabilirliği, bütünlüğü ve gizliliği.

Ders sırasında ekranda görünen slayt notunda e-postanın önemli bir varlık sayılma gerekçesi yazıyordu: e-posta şirketin bütün iş alanlarında bir iş aracı olarak kullanılıyor, yazışmaların büyük kısmı e-posta biçiminde ve şirketin uzak konumu nedeniyle e-postanın önemi normalden fazla (ekrandan, 01:15:00).

### 15.3 Risk kaydı

Gümüş Yıldız Madenleri risk kaydı (ekrandan, 01:15:00):

| Varlık | Tehdit / güvenlik açığı | Var olan kontroller | Olma olasılığı | Sonuç | Risk seviyesi | Risk önceliği |
|---|---|---|---|---|---|---|
| SCADA düğümlerinin ve ağın güvenilirliği ve bütünlüğü | Kontrol sisteminde yetkisiz değişiklik | Katmanlı güvenlik duvarları ve sunucular | Nadiren | Ciddi | Yüksek | 1 |
| Depolanan dosya ve veritabanı bilgilerinin bütünlüğü | Bozulma, hırsızlık ve bilgi kaybı | Güvenlik duvarı ve politikalar | Mümkün | Ciddi | Ekstrem | 2 |
| Finansal sistemin kullanılabilirliği ve bütünlüğü | Sistemi etkileyen saldırılar/hatalar | Güvenlik duvarı ve politikalar | Mümkün | Ciddi | Yüksek | 3 |
| Tedarik sisteminin mevcudiyeti ve bütünlüğü | Sistemi etkileyen saldırılar/hatalar | Güvenlik duvarı ve politikalar | Mümkün | Orta | Yüksek | 4 |
| Bakım/üretim sisteminin kullanılabilirliği ve bütünlüğü | Sistemi etkileyen saldırılar/hatalar | Güvenlik duvarı ve politikalar | Mümkün | Küçük | Orta | 5 |
| Posta hizmetlerinin kullanılabilirliği, bütünlüğü ve gizliliği | Sistemi etkileyen saldırılar/hatalar | Güvenlik duvarı, harici posta ağ geçidi | Neredeyse kesin | Küçük | Yüksek | 6 |

Hocanın satır satır yorumu:

- **SCADA:** Katmanlı güvenlik duvarı ve katmanlı sunucular, kullanıcı adı ve parola koruması olduğu için olasılık "nadiren". Ama sonuç ciddi ve şirketin asıl işi madencilik olduğu için risk seviyesi yüksek; öncelikle çözülmesi gereken konu budur.
- **Depolanan dosya ve veritabanı:** Tehdit bozulma, hırsızlık ve bilgi kaybıdır. Yalnız güvenlik duvarı var; olasılık "mümkün", sonuç ciddi, risk seviyesi ekstrem (en yüksek). Veriler kaybolursa kime ne kadar ürün verildiği bile bilinmez ve bu ciddi bir sorun yaratır.
- **Finansal sistem:** ERP sisteminin kullanılabilirliği. Tehdit dışarıdan saldırılar ya da kullanıcı hatalarıdır. Olasılık mümkün, sonuç ciddi, risk yüksek, öncelik üçüncü. Hoca önceliğin tamamen o firmanın durumuna bağlı olduğunu söyledi.
- **Bakım/üretim sistemi:** Üretim bandını etkileyen doğrudan saldırılar mümkündür, ama sonuç küçüktür; iş yavaşlayabilir ya da bir iş durabilir. Risk seviyesi orta.
- **Posta hizmetleri:** Çalışanların güvenlik farkındalık düzeyi düşük olduğu için olasılık neredeyse kesin. Ama e-postalarda şirketle ilgili ayrıntılı bilgi yoksa sonuç küçüktür. Risk yüksek.

Hoca tedarik sistemi satırını ayrıca yorumlamadı; satır yalnız slayttan alındı.

> **Ders sonrası not:** Risk matrisine göre "mümkün + ciddi" birleşimi ekstrem olmalıdır; nitekim depolanan dosya satırında öyledir. Finansal sistem satırında aynı birleşim için "yüksek" yazılması tutarsızdır. Büyük olasılıkla kaynakta bu satırın sonucu "orta"dır (mümkün + orta = yüksek) ve slayttaki "ciddi" bir aktarma hatasıdır; hoca da satırı slayttaki gibi okudu.

Bu seviyelendirme şirket yöneticilerine sunulur. Yöneticiler seviyelere bakarak hangi risklere yatırım yapacaklarına, hangilerini göze alacaklarına karar verir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:08:35): Bir kuruluşun bilgisayar sistemlerinin güvenliği sağlanırken cevaplanması gereken üç temel soru nedir?

> **Çözüm:** Hangi varlıkların korunması gerekir? Bu varlıklar nasıl tehdit ediliyor? Bu tehditlere karşı ne yapılabilir? (ekrandan, 00:10:00)

**Soru 2** (derste sözlü, 00:22:22): Güvenlikle ilgili çalışmalarda birinci şart nedir?

> **Çözüm:** Yönetimin desteği. BT güvenlik politikası üst yönetim tarafından desteklenmelidir.

**Soru 3** (derste sözlü, 00:04:00): Bir sistemi (örneğin bir üniversitenin ya da bir firmanın bütün sistemini) güvenlik altına almanın birinci yolu nedir?

> **Çözüm:** Güvenlikle ilgili risklerin belirlenmesi ve bu risklerin değerlendirilmesi. Riskler bilinmezse güvenlik doğru ve yeterli şekilde sağlanamaz.

## Dersin Toparlaması

Bu derste "Yönetim Sorunları" bölümünün ilk konusu olan BT güvenlik yönetimi ve risk değerlendirmesi işlendi. Güvenlik yönetimi, hangi varlıkların korunacağı, bu varlıklara hangi tehditlerin bulunduğu ve bunlara karşı ne yapılabileceği sorularına cevap arayan, yukarıdan aşağıya işleyen ve sürekli dönen bir süreç olarak tanımlandı. ISO 27000 standart ailesi bu sürecin çerçevesini çizer. Kurumsal güvenlik politikası hedef, strateji ve politikalardan oluşur, düzenli olarak gözden geçirilir ve üst yönetim tarafından desteklenmelidir.

Risk değerlendirmesi için temel, gayri resmi, ayrıntılı ve bütünleşik yaklaşımlar karşılaştırıldı. Ayrıntılı analizde varlık, tehdit, güvenlik açığı ve risk tanımlandı; risk, olasılık ve sonucun birleşimi olarak beş olasılık ve altı sonuç kademesiyle niteliksel biçimde derecelendirildi ve ekstrem, yüksek, orta, düşük seviyelerine ayrıldı. Riskler bir risk kaydında toplanır ve kabul, kaçınma, transfer, sonucu azaltma ya da olasılığı azaltma seçeneklerinden biriyle ele alınır. Gümüş Yıldız Madenleri vakası bu adımların bütünleşik yaklaşımla nasıl uygulandığını gösterdi. Bir sonraki konu, bu risklere karşı alınacak BT güvenlik kontrolleri, planları ve prosedürleridir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
