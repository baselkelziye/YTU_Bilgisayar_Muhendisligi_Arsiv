# Ders 3 Çalışma Özeti

## Genel Konular

- Klasik Yinelemeli Süreç Modelleri: Sarmal Model ve Kazan-Kazan Modeli
  - **Sarmal Model (*Spiral Model*):** İçten dışa doğru büyüyen her sarmal çevrimde 6 adımın yürütülmesi: 1) Müşteri ile iletişim (gereksinimlerin belirlenmesi), 2) Planlama (kaynaklar, zamanlama, yapılacaklar), 3) Risk analizi (teknik, mali ve politik riskler), 4) Çözümleme ve tasarım, 5) Gerçekleme ve kurulum (kullanıcı eğitimi ve dokümantasyon dahil), 6) Müşteri tarafından ürünün değerlendirilmesi (ekrandan, 00:05:00).
  - **Kazan-Kazan Modeli (*Win-Win Model*):** Sürece **paydaş (*stakeholder*)** (yazılımın başarısı ve başarısızlığının etkileyeceği kişi ve kurumlar) kavramını katması; her sarmal çevrimde 1) İlgililerin (paydaşların) belirlenmesi, 2) Kazanma durumlarının belirlenmesi, 3) Uzlaşma ve seçeneklerin belirlenmesi, 4) Seçeneklerin değerlendirilmesi ve risklerin çözülmesi, 5) Gerçekleme ve kurulum, 6) İlgililer tarafından değerlendirmeler adımlarının izlenmesi (ekrandan, 00:12:00).
- Çevik (*Agile*) Süreçler: Temel İlkeler, Ekip Özellikleri ve Dezavantajlar
  - Değişen gereksinimler ve teknik riskler gibi önceden belirlenemeyen durumlara karşı esneklik sağlayan süreç ailesi; Çevik Manifesto'nun dört temel değer karşılaştırması (**Bireyler ve etkileşimler** $>$ Süreçler ve gereçler; **Çalışan yazılım** $>$ Ayrıntılı belgeler; **Müşterinin sürece katılımı** $>$ Sözleşme pazarlığı; **Değişikliklere uyum sağlamak** $>$ Bir planı izlemek) (ekrandan, 00:20:00).
  - Çevik başarının ölçütleri: yazılımın artımsal gelişimi, müşteriye erken ve sık ürün teslimi, başarımın birincil ölçütünün doğru çalışan yazılım olması (ekrandan, 00:20:00).
  - Çevik ekibin özellikleri: yüz yüze iletişim, çevik eğitim, ortak amaç, işbirliği, karşılıklı saygı ve güven, teknik ve proje genelinde karar alma yetkisi, *"boşuna harcanan çaba yoktur, edinilen deneyim vardır"* anlayışı ve **kendi kendini düzenleme** (işe göre yapılanma / Ar-Ge projelerinde hiyerarşik yerine eşler arası [*peer-to-peer*] matris yapı, süreci yerel ortama uyarlama, esnek çalışma saatleri) (ekrandan, 00:27:00).
  - Çevik süreçlerin dezavantajları: uygun olmayan ekiple/kurumla çalışılamaması, kalabalık ekip veya büyük ölçekli (çok ofisli, farklı saat dilimli, çok fazla kullanıcı öykülü) projelere uygun olmaması, dış denetleyicinin ve katı yasal kuralların olduğu projelerde (ör. finans) yetersiz kalması ve disiplinsizlik olarak yorumlanma tehlikesi (ekrandan, 00:35:00).
- Çevik Süreç Örnekleri: Aşırı Programlama (*XP: Extreme Programming*) ve *Scrum*
  - **XP (Aşırı Programlama)** adımları: Planlama $\rightarrow$ Tasarım $\rightarrow$ Kodlama $\rightarrow$ Sınama çevrimi.
    - *Planlama:* ~3 haftalık ($\pm 1$ hafta) **kullanıcı öyküleri (*user stories*)**, müşterinin öncelik derecelendirmesi ve ekibin teknik risk/zorluk derecelendirmesi, büyük (*coarse-grained*) öykülerin alt öykülere bölünmesi, önce yüksek riskli (*fail fast*) veya önce yüksek öncelikli öykülerin seçilmesi, çevrim hızının (*velocity*) ölçümü.
    - *Tasarım:* Basit tasarım (**KISS** — *Keep It Simple, Stupid*), **CRC (*Class-Responsibility-Collaborator*) kartları** (ör. `Satış` sınıfı kartı: sınıf adı, tanımı, üst/alt sınıflar, sorumluluk ve işbirlikçi sütunları) ile tüm ekibin tasarımı gözden geçirmesi, karmaşık kısımlar için **ön gerçekleme (*spike solution* / *proof of concept*)** ve **yeniden düzenleme (*refactoring*)** (ekrandan, 01:08:00).
    - *Kodlama ve Sınama:* Önce birim sınamalarının (*unit test*) hazırlanması (**Test Güdümlü Tasarım / Geliştirme — TDD**), yalnızca sınamayı geçecek kadar kod yazılması, **çift kişiyle / eşli programlama (*pair programming*)** (tüplü dalıştaki *buddy* benzetmesi) ve otomatik birim test araçlarıyla (*JUnit* vb.) sınama.
  - **Scrum** süreci: Ragbi (*rugby*) oyunundaki takım kenetlenmesi taktiğinden esinlenen **Görev Listesi $\rightarrow$ Koşu (*Sprint*) $\rightarrow$ İşlev Gösterimi** çevrimi; koşu (1–4 hafta) boyunca her gün yapılan 15 dakikalık ayaküstü toplantıda cevaplanan 3 soru (*"Son toplantıdan bu yana ne yaptınız?"*, *"Karşılaştığınız engeller nelerdir?"*, *"Yarınki toplantıda neleri başarmayı hedefliyorsunuz?"*) ve isteğe bağlı **Pre-Scrum (*Kick-off*)** ile **Post-Scrum** aşamaları (ekrandan, 01:28:00).
  - Modelleme ve araç kullanımı ilkeleri: hedef kitleye uygun ayrıntıda modelleme, sunumdan ziyade içeriğin önemi, geliştirme ve test araçlarına (*hands-on*) hâkimiyet.
- Süreç Sertifikasyonu ve Yazılım Yeterlilik Olgunluk Modeli (CMMI)
  - Süreç sertifikasyonunun amacı, büyük müşterilerin/kamu ve savunma kurumlarının ihale şartı olması, küçük firmalar (KOBİ) ve küçük projeler için ek yük oluşturması (ekrandan, 01:45:00).
  - Güncel model ve standartlar: **CMMI** (*Capability Maturity Model Integration*, Carnegie Mellon Üniversitesi SEI, kurumsal), **PMI** (bireysel ve kurumsal proje yönetimi), **ISO 9001:2015** (genel kurumsal kalite), **ISO/IEC 90003:2018** (yazılım geliştirmeye özel kurumsal standart; Türkiye'de ulusal otorite **TÜRKAK**, belgelendirici kuruluş örneği **Denetik**) (ekrandan, 01:45:00).
  - **CMMI Olgunluk Düzeyleri (0–5):** Düzey 0 (*Incomplete* / Yürütülmeyen), Düzey 1 (*Initial / Performed* / Giriş), Düzey 2 (*Managed / Repeatable* / Yönetilen-Yinelenebilir), Düzey 3 (*Defined* / Tanımlanmış — kişi ve risk yönetimi, büyük müşteriler için kritik eşik, çevik süreçlerin ulaşabildiği üst sınır), Düzey 4 (*Quantitatively Managed* / Nicel Yönetilen) ve Düzey 5 (*Optimized* / İyileştirilmiş) (ekrandan, 02:10:00).
  - CMMI tarihçesi (1987 CMM $\rightarrow$ 1998 CMMI $\rightarrow$ 2010 v1.3 Çevik desteği $\rightarrow$ 2018 v2.0 ile `CMMI-DEV`, `CMMI-SVC`, `CMMI-ACQ` alanlarının ve *continuous/staged* ayrımının tek bütüncül yapıda birleşmesi), Türkiye'den CMMI Level 3 ve Level 5 kurum örnekleri (ekrandan, 02:20:00) ve CASE araçlarının CMMI düzeyleriyle (1–5) ilişkisi (ekrandan, 02:30:00).
- Gereksinim Mühendisliğine Giriş, SRS ve Yapıt (*Artifact*) Kavramı
  - Gereksinim mühendisliğinin (*Requirements Engineering*) projenin amaçlarını, boyutlarını ve etkilerini belirlemesi ve **yapılabilirlik (*feasibility*)** çalışmasına temel girdi sağlaması.
  - **SRS (*Software Requirements Specification* — Yazılım Gereksinimler Belgesi)** standartları: **`IEEE 830-1998`** (SRS odaklı) ve **`ISO/IEC/IEEE 29148:2011`** (*Systems and Software Engineering – Life Cycle Processes – Requirements Engineering*) (ekrandan, 02:40:00).
  - **Yapıt (*Artifact / Artefact*):** Yazılım geliştirme sırasında kaynak kod dışında ortaya çıkarılan her türlü metin, şema ve derleme/yapılandırma (*build configuration*) dosyası (ekrandan, 02:40:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Sarmal Modelin ve Kazan-Kazan Modelinin Kalıcı Katkıları
  - Sarmal model ve kazan-kazan modeli bugün sektörde doğrudan kullanılmasa da, sarmal modelin **risk analizini (teknik, mali, politik) her çevrimde sürekli yapılan bir etkinlik** hâline getirmesi ve kazan-kazan modelinin **farklı paydaşların (*stakeholders*) çelişen önceliklerini uzlaştırma** kavramını getirmesi güncel süreçlere miras kalmıştır (ekrandan, 00:05:00; ekrandan, 00:12:00).
- Çevik Süreçlerin Merkezinde İnsan ve İletişimin Yer Alması
  - Yazılım mühendisliği yalnızca makine veya kod işi değil, bir **insan işidir**; çevik süreçler sağ sütundaki öğeleri (süreçler, belgeler, sözleşme, plan) reddetmez ancak sol sütundaki öğelere (**bireyler ve etkileşimler, çalışan yazılım, müşteri katılımı, değişikliğe uyum**) öncelik verir (ekrandan, 00:20:00).
  - Çevik çalışmak **disiplinsizlik** demek değildir; üst yönetim bunu kuralsızlık sanmamalı, teknik ekip de süreci disiplinsizliğe dönüştürmemelidir (ekrandan, 00:35:00).
- XP'de Eşli Programlama (*Pair Programming*) ve Test Güdümlü Geliştirme (*TDD*)
  - Tıpkı tüplü dalışta tek başına dalmanın hayati tehlike taşıması ve iki dalgıcın birbirinin *buddy*'si (dalış eşi) olarak tüp basıncını, çevreyi ve çıkış hızını sürekli denetlemesi gibi, XP'de de iki programcı tek bilgisayar başında çalışır: biri klavye/fare ile kodu yazarken diğeri kodun genel tasarıma, kalite ölçütlerine ve kodlama standartlarına uygunluğunu denetleyerek "büyük resmi" korur.
  - Kodlamadan önce birim testlerin (*unit test*) yazılması (TDD), tasarım eksikliklerini henüz kod yazmadan ortaya çıkarır; kod yazılırken de gelecekte değişebilecek varsayımsal özellikler için değil, **yalnızca mevcut testi geçecek kadar** basit kod (**KISS**) yazılmalıdır.
- CMMI Düzey 3 (*Defined*) Eşiği ve Çevik Süreçlerle Uyum
  - CMMI **3. Düzey (Tanımlanmış / *Defined*)**, temel proje planlamasının üzerine **kişi yönetimi ve risk yönetimini** ekler ve tüm organizasyonda standart süreçler tanımlar; büyük kurumsal müşteriler ve savunma sanayii ihaleleri en az **CMMI Level 3** şartı arar (ekrandan, 02:10:00).
  - 2010'daki CMMI v1.3 güncellemesinden itibaren çevik (*agile*) süreçlerle çalışan firmalar da CMMI Level 3 sertifikası alabilmektedir (ancak nicel metrik yönetimi gerektiren Level 4 ve 5 çevik süreçlerle doğrudan örtüşmeyebilir).
- Doğru İşi Yapan İyi Çözüm vs. Eksik/Yanlış İşi Yapan Mükemmel Çözüm
  - Müşterinin gerçek ihtiyaçlarını karşılamayan, yanlış veya eksik işi yapan bir yazılım ne kadar hızlı ya da kullanıcı dostu olursa olsun hiçbir işe yaramaz ("eksik işi yapan mükemmel çözüm" bir oksimorondur); asıl hedef **doğru işi yapan iyi çözümdür** ve bunun temeli sağlam bir gereksinim mühendisliği ile **SRS** belgesidir.

## Kısa Tekrar Notları

- **Sarmal (*Spiral*) modelin 3 risk türü:** **Teknik riskler** (deneyimsizlik, ilk kez yapılacak tümleştirme), **Mali riskler** (öz kaynak yetersizliği, TÜBİTAK TEYDEB desteğine bağımlılık), **Politik riskler** (kurum içi/kurumlar arası dinamikler ve sektörel öncelikler) (ekrandan, 00:05:00).
- **Paydaş (*stakeholder*):** Yazılımın başarısından veya başarısızlığından olumlu ya da olumsuz etkilenecek her türlü kişi, grup, departman ve kurum (yazılım evinin yönetimi ve çalışanları dahil) (ekrandan, 00:12:00).
- **Çevik Manifesto öncelikleri:** Bireyler ve etkileşimler $>$ Süreçler ve gereçler; Çalışan yazılım $>$ Ayrıntılı belgeler; Müşterinin sürece katılımı $>$ Sözleşme pazarlığı; Değişikliklere uyum sağlamak $>$ Bir planı izlemek (ekrandan, 00:20:00).
- **Kullanıcı öyküsü (*user story*):** Müşteri için anlamlı, yaklaşık **3 haftada** ($\pm 1$ hafta) gerçeklenebilecek büyüklükteki iş birimi. Önceliği **müşteri**, teknik riski/zorluğu **yazılım ekibi** belirler.
- **Öykü sıralama stratejileri:** 1) Önce yüksek riskli öyküler (*fail fast* — olası engelleri erken görmek), 2) Önce müşteri için yüksek öncelikli öyküler (süre yetmezse bile müşterinin elinde temel işini gören çalışan bir ürün — otomobil yerine motosiklet — kalması), 3) Melez (*hibrit*) yaklaşım.
- **KISS ilkesi:** *Keep It Simple, Stupid* — tasarımda gereksiz karmaşıklıktan kaçınma, en basit çalışan tasarımı seçme.
- **CRC kartı (*Class-Responsibility-Collaborator*):** Üstte sınıf adı, açıklaması, üst/alt sınıfları; altta sol sütunda **Sorumluluk** (üye alan ve metotlara dönüşür), sağ sütunda **İşbirlikçi** (ilişkili sınıflar) yer alan tasarım ve ekip içi gözden geçirme kartı (ekrandan, 01:08:00).
- **Spike solution (Ön gerçekleme):** Karmaşık bir tasarım kararının geçerliliğini doğrulamak için yapılan küçük ölçekli kavram kanıtı (*proof of concept*) kodu.
- **Scrum döngüsü:** Görev Listesi (*Product/Sprint Backlog*) $\rightarrow$ Koşu (*Sprint*, 1–4 hafta) $\rightarrow$ İşlev Gösterimi. Koşu boyunca her gün **15 dakikalık** toplantıda 3 soru: 1) Dünden beri ne yaptınız? 2) Karşılaştığınız engeller nelerdir? 3) Yarınki toplantıya kadar ne başarmayı hedefliyorsunuz? (ekrandan, 01:28:00).
- **Süreç sertifikasyon standartları:** **CMMI** (SEI, kurumsal, 0–5 seviye), **PMI** (bireysel ve kurumsal proje yönetimi), **ISO 9001:2015** (genel kalite, ikili: var/yok), **ISO/IEC 90003:2018** (yazılım geliştirmeye özel kalite; Türkiye otoritesi **TÜRKAK**) (ekrandan, 01:45:00).
- **CMMI düzeyleri:** `0: Incomplete` (Yürütülmeyen), `1: Initial/Performed` (Giriş — şansa ve anahtar kişilere bağlı), `2: Managed/Repeatable` (Yönetilen — temel planlama/izleme), `3: Defined` (Tanımlanmış — kişi ve risk yönetimi, organizasyonel standart; büyük ihale eşiği), `4: Quantitatively Managed` (Nicel yönetilen — metriklerle kalite yönetimi), `5: Optimized` (İyileştirilmiş — geçmiş deneyimlerle sürekli süreç iyileştirme) (ekrandan, 02:10:00).
- **SRS (*Software Requirements Specification*) standartları:** **`IEEE 830-1998`** ve **`ISO/IEC/IEEE 29148:2011`** (ekrandan, 02:40:00).
- **Yapıt (*Artifact*):** Yazılım geliştirme sürecinde kaynak kod dışında üretilen her türlü belge, şema ve derleme yapılandırma dosyası (ekrandan, 02:40:00).

## Detaylı Açıklamalar

### 1. Klasik Yinelemeli Süreç Modelleri: Sarmal Model ve Kazan-Kazan Modeli

Geçen derste giriş yapılan artımsal (*incremental*) ve yinelemeli (*iterative*) yaklaşımın literatürdeki ilk iki klasik temsilcisi **Sarmal Model (*Spiral Model*)** ve **Kazan-Kazan Modelidir (*Win-Win Model*)**:

1. **Sarmal Model (*Spiral Model*):** İçteki en koyu halkadan başlayarak dışa doğru genişleyen bir sarmal üzerinde ilerler; her bir tam tur bir çevrimi (iterasyonu) temsil eder ve 6 dilimden oluşur (ekrandan, 00:05:00):
   - **Müşteri ile İletişim:** Gereksinimlerin belirlenmesi çalışmaları yapılır.
   - **Planlama:** İnsan kaynakları, yazılım araçları/lisansları, danışmanlık veya dış kaynak (*outsource*) ihtiyaçları ve zamanlama planlanır.
   - **Risk Analizi:** Sarmal modelin literatüre en büyük katkısı, **risk analizinin her çevrimde sürekli yapılması gereken bir etkinlik olduğunu** vurgulamasıdır. Üç tür risk incelenir:
     - *Teknik riskler:* Kullanılacak teknoloji veya dilde deneyimli personel olmaması, müşterinin mevcut bir sistemiyle ilk kez tümleştirme yapılacak olması vb.
     - *Mali riskler:* Firmanın öz kaynaklarının sınırlı olup projeye başlayabilmek için TÜBİTAK TEYDEB gibi bir Ar-Ge desteğinin çıkmasına bağımlı olması vb.
     - *Politik riskler:* Şirket içi veya müşteri kurumla olan güç dinamikleri ya da sağlık/ulaşım gibi stratejik öncelik alanlarının dışında kalma riski.
   - **Çözümleme ve Tasarım:** İlgili çevrimde gerçeklenecek kısmın analiz ve tasarımı yapılır.
   - **Gerçekleme ve Kurulum:** Kodlama, teknik ve son kullanıcı dokümantasyonu, sistemin kullanıcı/test ortamına kurulması ve kullanıcı eğitimi gerçekleştirilir.
   - **Müşteri Tarafından Ürünün Değerlendirilmesi:** Müşteri ürünü dener, geri bildirim verir ve sarmalın bir sonraki dış halkasına geçilerek yazılımın hacmi büyütülür (ekrandan, 00:05:00).
2. **Kazan-Kazan Modeli (*Win-Win Model*):** Sarmal modeli temel alır ancak merkezine **paydaş (*stakeholder*)** kavramını yerleştirir (ekrandan, 00:12:00). **Paydaş**, yazılım projesinin başarısından veya başarısızlığından olumlu ya da olumsuz etkilenecek her türlü kişi, departman ve kurumdur (müşteri kurum içindeki farklı birimler, son kullanıcılar, yazılım evinin üst yönetimi ve geliştiricileri ayrı birer paydaştır). Bir özellik bir departmanın işini kolaylaştırırken başka bir departmanın iş yükünü artırabilir; dolayısıyla paydaşların öncelikleri sıkça çelişir. Bu nedenle Kazan-Kazan modelinde her çevrim şu 6 adımdan oluşur (ekrandan, 00:12:00):
   1. **İlgililerin (paydaşların) belirlenmesi,**
   2. **Kazanma durumlarının belirlenmesi** (her paydaşın beklentisi ve önceliği),
   3. **Uzlaşma ve seçeneklerin belirlenmesi,**
   4. **Seçeneklerin değerlendirilmesi ve risklerin çözülmesi** (tüm paydaşların toplam faydasını eniyileyen veya en düşük maliyetli uzlaşı seçeneğinin seçilmesi),
   5. **Gerçekleme ve kurulum** (analiz ve tasarım dahil),
   6. **İlgililer tarafından değerlendirmeler** (ekrandan, 00:12:00).

### 2. Çevik (*Agile*) Süreçler: Manifesto, Ekip Yapısı ve Sınırlar

**Çevik süreçler (*Agile processes*)**, değişen gereksinimler ve teknik riskler gibi önceden kestirilemeyen durumlara ve yazılım ürününü etkileyebilecek her türlü değişikliğe karşı esneklik sağlayan artımsal süreçlerdir (ekrandan, 00:20:00). Çevik Manifesto'da süreçteki sekiz önemli etken iki sütun hâlinde karşılaştırılır (ekrandan, 00:20:00):

| Öncelik Verilen (Sol Sütun) | Yararı Kabul Edilen (Sağ Sütun) |
| :--- | :--- |
| **Bireyler ve etkileşimler** | Süreçler ve gereçler |
| **Çalışan yazılım** | Ayrıntılı belgeler |
| **Müşterinin sürece katılımı** | Sözleşme pazarlığı |
| **Değişikliklere uyum sağlamak** | Bir planı izlemek |

Çevik süreçler sağ taraftaki maddelerin yararını ve gerekliliğini kabul etmekle birlikte **sol taraftaki maddelere daha çok önem verir** (ekrandan, 00:20:00). Örneğin resmi toplantı formları doldurup günlerce onay beklemek yerine kahve makinesi önünde veya anlık mesajlaşmayla sorunu çözmek; müşteriyle sürekli sözleşme maddesi tartışmak yerine müşteriyi sürece katmak; katı bir plana körü körüne bağlı kalmak yerine değişen gereksinimlere uyum sağlamak esastır. Ancak **bir ilerleme olmaksızın yalnızca sürekli uyum sağlamak başarı değildir**; bu yüzden yazılım artımsal gelişir, müşteriye erken ve sık ürün teslim edilir ve **başarımın birincil ölçütü doğru çalışan yazılımdır** (ekrandan, 00:20:00).

**Çevik Süreci Yürütecek Ekibin Özellikleri (ekrandan, 00:27:00):**
- Yüz yüze görüşme en etkili bilgi aktarım yoludur.
- Takım üyeleri çevik yaklaşım hakkında eğitilmelidir.
- Ortak amaç, çalışan yazılım üreterek müşteriye zamanında teslim etmektir.
- Ekip üyeleri birbirleriyle ve müşteriyle sıkı işbirliği içinde, karşılıklı saygı ve güven içerisinde olmalıdır.
- Ekipler hem teknik hem de tüm proje hakkında kararlar verebilmelidir (otonomi).
- **Boşuna harcanan çaba yoktur:** Çözülen bir sorun sonradan gereksizleşse veya o özellikten vazgeçilse bile, çözüm sürecinde edinilen deneyim ekibe ileri aşamalarda yararlı olur (ekrandan, 00:27:00).
- **Kendi kendini düzenleme (*self-organization*) (ekrandan, 00:27:00):**
  1. *Ekibin kendisini yapılacak işe göre uyarlaması:* Örneğin ilk kez çalışılan bir Ar-Ge projesinde ekip liderinin bilmediği bir konuyu yüksek lisans tezinde çalışmış genç bir ekip üyesi daha iyi biliyor olabilir; bu durumda katı hiyerarşik yapı yerine **eşler arası (*peer-to-peer*) matris organizasyona** geçilebilir.
  2. *Ekibin kullanacağı süreci yerel ortama uyarlaması:* Örneğin standart 3 haftalık çevrimler yerine projenin doğasına göre 2 haftalık çevrimler seçilebilir.
  3. *Çalışma zamanlamasını ekibin kendisinin belirlemesi:* Zor bir çevrimde akşam 8–9'a kadar mesai yapılırken, rahat bir çevrimde sabah 10'da gelip akşam 4–5'te çıkabilme esnekliği tanınmalıdır; katı kart basma ve maaş kesintisi kuralları çevik çalışmaya uymaz.

**Çevik Süreçlerin Dezavantajları (ekrandan, 00:35:00):**
1. **Uygun olmayan ekiple (veya bürokratik kurum kültürüyle) çevik çalışılamaz.**
2. **Kalabalık ekip veya büyük ölçekli projeler için uygun görülmemektedir:** 5–8 kişilik aynı ofisteki bir ekipte yüz yüze iletişim kolayken, 20 kişilik veya farklı şehir/ülkelerdeki (ör. Ankara, Lizbon ve aralarında 10 saat fark olan Washington ofislerindeki) ekiplerde anlık yüz yüze iletişim imkânsızlaşır. Ayrıca çok büyük yazılımlarda 3 haftalık kullanıcı öykülerinin sayısı yönetilemeyecek kadar büyür.
3. **Bir dış denetleyicinin dahil olduğu ve ayrıntılı kuralların/denetlemelerin zorunlu olduğu projelerde yetersiz kalmaktadır:** Bankacılık ve finans gibi ağır yasal mevzuatlara ve dış denetime tabi alanlarda ayrıntılı belgelendirme zorunludur ve öykülerden keyfî olarak vazgeçilemez; bu nedenle bu alanlarda çoğunlukla klasik süreçler tercih edilir.
4. **Çevik çalışmak disiplinsizlik olarak yorumlanmamalıdır (ve disiplinsizliğe dönüşmemelidir).**

### 3. Çevik Süreç Örnekleri: XP (Extreme Programming) ve Scrum

#### 3.1 Aşırı Programlama (XP: Extreme Programming)

XP; **Planlama $\rightarrow$ Tasarım $\rightarrow$ Kodlama $\rightarrow$ Sınama** adımlarından oluşan hızlı çevrimlerle ilerler:

- **Planlama ve Kullanıcı Öyküleri (*User Stories*):** Planlama, müşteri için anlamlı bir işlevi ifade eden ve yaklaşık **3 haftada ($\pm 1$ hafta)** gerçeklenebilecek **kullanıcı öykülerine** dayanır. Öyküleri analiz ekibinin desteğiyle müşteri belirler; **önem/öncelik derecesini müşteri**, **teknik zorluk ve risk derecesini ise yazılım ekibi** verir. Eğer bir öykü 3 haftayı aşıyorsa (ör. 6 veya 9 haftalık kaba/*coarse-grained* bir öyküyse) müşteriyle birlikte 2 veya 3 alt öyküye bölünür. Öykülerin hangi sırayla gerçekleneceğine müşteri ve ekip birlikte karar verir; iki temel strateji vardır:
  1. *Önce yüksek riskli öyküleri gerçeklemek:* Olası teknik darboğazları ve hataları yaşam döngüsünün en başında, değişiklik maliyeti düşükken görmek ve proje eldeki kısıtlarla yapılamayacaksa bile erkenden fark etmek (***fail fast***).
  2. *Önce müşteri için yüksek öncelikli öyküleri gerçeklemek:* İleride yüksek riskli bir öykü yüzünden süre biterse bile müşterinin elinde temel ihtiyaçlarını karşılayan çalışan bir ürün kalmasını sağlamak (A noktasından B noktasına gitmek için B sınıfı otomobil yetiştirilemese bile yürümekten çok daha iyi olan bir motosiklet veya bisiklet teslim edebilmek).
  Teslim edilen artımlar aynı zamanda **projenin hızını (*velocity*)** ölçmekte kullanılır: örneğin 3 hafta planlanan 10 çevrimin 8'i 4 haftada bitiyorsa proje süresi %33 uzayacak demektir; bu durumda müşteriyle uzlaşılarak ya bitiş tarihi uzatılır ya da bazı düşük öncelikli öykülerden vazgeçilir. Müşteri süreç boyunca yeni öykü ekleyebilir, öncelik değiştirebilir veya öykü silebilir.
- **Tasarım, CRC Kartları ve Spike Solution:** Tasarımda **KISS (*Keep It Simple, Stupid*)** ilkesi geçerlidir: basit tasarım karmaşık gösterimden her zaman üstündür. XP, ayrıntılı UML şemalarını zorunlu tutmaz; yalnızca **CRC (*Class-Responsibility-Collaborator* — Sınıf-Sorumluluk-İşbirlikçi) kartları** ve gerekiyorsa **Spike Solution** oluşturulmasını yeterli görür. Slaytta gösterilen örnek `Satış` sınıfı CRC kartı şöyledir (ekrandan, 01:08:00):

| **Sınıf: Satış** | |
| :--- | :--- |
| Kasada yapılan ödemeyi simgeleyen sınıf. | |
| **Üst Sınıf(lar):** Yok | |
| **Alt Sınıf(lar):** Yok | |
| **Sorumluluk:** | **İşbirlikçi:** *(Sınıf adları)* |
| Satışın yapıldığı tarih ve saati saklamak | *(Yok — ör. `java.util.Date` üye alanı)* |
| Yapılan ödeme tutarını saklamak | `Ödeme` |
| Satılan malların listesine erişim | `Mal` |

  Hazırlanan CRC kartları ekip üyelerine eşit dağıtılır (ör. 50 sınıf 5 kişiye 10'ar kart olarak verilir); herkes elindeki kartları inceleyip olası eksikleri/hataları tartışır, ardından kartını yanındakine devreder. Böylece tüm ekip tüm tasarımı gözden geçirmiş olur. Eğer bir problem parçasında karmaşık bir tasarımdan kaçınılamıyorsa, tasarımın geçerliliğini doğrulamak için birkaç sınıf/metot ölçeğinde işlevsel bir ön gerçekleme (*proof of concept*) yazılır; buna **Spike Solution** denir. Ayrıca mevcut tasarımı iyileştirmek için **yeniden düzenleme (*refactoring*)** sürekli teşvik edilir.
- **Kodlama (TDD ve Eşli Programlama) ve Sınama:** XP'ye "aşırı (*extreme*)" niteliğini veren iki temel kodlama pratiği vardır:
  1. **Test Güdümlü Tasarım/Geliştirme (*Test-Driven Design/Development* - TDD):** Kod yazmaya başlamadan **önce birim sınamaları (*unit test* — nesneye yönelik programlamada her bir sınıfın testi)** hazırlanır. Bir sınıfın birim testini yazarken zorlanılıyorsa o sınıf eksik veya esnek olmayan biçimde tasarlanmış demektir. Ardından gelecekteki olası değişiklikler için fazladan karmaşık kod yazılmaz; **yalnızca o anki sınamayı geçmeye yetecek kadar kod** yazılır (ancak ekip isterse testleri kodla paralel veya koddan sonra da yazabilir).
  2. **Çift Kişiyle / Eşli Programlama (*Pair Programming*):** Hoca bunu **tüplü dalış (*scuba diving*)** benzetmesiyle açıklamıştır: Su altı insan için tehlikeli bir ortam olduğundan asla tek başına dalış yapılmaz; iki dalgıç birbirinin *buddy*'si (dalış eşi) olarak birbirinin oksijen tüpünü, hortumunu, çevreyi ve vurgun yememek için çıkış hızını sürekli gözetir. Eşli programlamada da **tek bir bilgisayarın başında iki programcı** çalışır: birinci kişi klavye ve fareyle kodu yazarken, ikinci kişi kodun genel tasarıma, kalite ölçütlerine, kodlama standartlarına (*pretty printing*, girintileme, tek satıra 5-6 zincirleme işlem sıkıştırmama vb.) uygunluğunu denetler ve ayrıntılar içinde "büyük resmin" kaçırılmamasını sağlar (ayrıca biri kıdemliyse doğal bir usta-çırak bilgi aktarımı gerçekleşir). İnsan kaynağı kısıtlı bir KOBİ ise eşli programlamayı uyarlayıp atlayabilir veya Scrum seçebilir.
  Sınama aşamasında ise birim testler *JUnit* gibi araçlarla otomatik koşturulur ve müşteri artımsal ürünü dener.

#### 3.2 Scrum

Adını ragbi (*rugby*) sporunda topu taşıyan oyuncunun etrafında tüm takımın etten bir duvar oluşturarak hedefe birlikte yüklenmesi taktiğinden alan **Scrum**, üç adımlı bir çevrimle çalışır (ekrandan, 01:28:00):

```text
                       +-----------------------------------------------+
                       |                                               |
                       v                                               |
(Pre-Scrum) ---> [ Görev Listesi ] ---> [ Koşu (1-4 hafta) ] ---> [ İşlev Gösterimi ] ---> (Post-Scrum)
```

1. **Görev Listesi:** XP'deki kullanıcı öykülerinin karşılığıdır; önceliklendirilmiştir (ekrandan, 01:28:00).
2. **Koşu (*Sprint*):** Görev listesinden seçilen maddelerin önceden belirlenmiş kısa bir sürede (**ör. 1–4 hafta**) gerçeklenmesidir (ekrandan, 01:28:00). Koşu süresince ekibin **her gün yaptığı kısa (ör. 15 dakikalık)** sözlü ve yüz yüze toplantılar Scrum'ın en ayırt edici özelliğidir. Toplantıyı **proje lideri** yönetir ve kendisi dahil herkese şu **üç ana soruyu** sorar (ekrandan, 01:28:00):
   - *Son toplantıdan bu yana ne yaptınız?*
   - *Karşılaştığınız engeller nelerdir?*
   - *Yarınki toplantıda neleri başarmayı hedefliyorsunuz?*
   Böylece ekipteki herkes birbirinin durumundan ve engellerden her gün haberdar olur.
3. **İşlev Gösterimi:** Müşterinin en yeni işlevi veya o ana dek gerçeklenen tüm işlevleri sınamasıdır (ekrandan, 01:28:00).

Hoca ayrıca bu döngünün başına gereksinim ve risk analizini aceleye getirmeden ayrıntılı yapmak üzere bir **Pre-Scrum (*Kick-off* / Başlama vuruşu)** aşaması, projenin sonuna ise eksik belgelendirmeyi tamamlamak ve kullanıcı eğitimlerini vermek üzere bir **Post-Scrum** aşaması eklenmesinin önerildiğini vurgulamıştır.

**Çevik Modelleme ve Araç İlkeleri:** Modelleme yapılırken şemanın kime anlatılacağı gözetilmelidir (konu uzmanına karmaşık sınıf/metot şemaları çizilmez, yalnız gereken düzeyde özet şema çizilir); sunumun süsünden ziyade **içerik** önemlidir; ayrıca hızlı çevrimlerde vakit kaybetmemek için geliştirme ve test araçlarına (*JUnit* vb.) önceden uygulamalı (*hands-on*) hâkim olunmalıdır.

### 4. Süreç Sertifikasyonu ve CMMI (Yazılım Yeterlilik Olgunluk Modeli)

Bir yazılım firması süreçlerini çok iyi yürüttüğünü iddia edebilir; ancak bu iddianın geçerli sayılması için süreç yeterliliğinin bağımsız kurumlarca denetlenip onaylanması (**süreç sertifikasyonu / akreditasyonu**) gerekir (ekrandan, 01:45:00). Küçük şirketler (KOBİ'ler) ve küçük projeler için sertifikasyon ciddi bir zaman, insan ve maliyet yükü olduğundan gereksizdir; ancak büyük kurumsal müşteriler, bakanlıklar ve askeri kurumlar yüksek bütçeli ihalelerde (tıpkı tesisatçı seçerken ustalık/kalfalık belgesi aranması gibi) belirli bir akreditasyon düzeyini ön şart olarak koşarlar (ekrandan, 01:45:00).

Slaytta başlıca güncel model ve standartlar şöyle karşılaştırılmıştır (ekrandan, 01:45:00):
- **CMMI (*Capability Maturity Model Integration*):** Carnegie Mellon Üniversitesi bünyesindeki **SEI (*Software Engineering Institute*)** tarafından önerilmiş kurumsal yazılım süreç olgunluk modelidir (700'den fazla sayfalık dokümanı `http://www.sei.cmu.edu/cmmi/` adresinde açıktır) (ekrandan, 01:45:00; ekrandan, 02:10:00).
- **PMI (*Project Management Institute*):** Genel amaçlı (son yıllarda yazılıma özel alt dalları da olan), hem **bireysel hem kurumsal** sertifikasyon sunan proje yönetimi yaklaşımıdır (ekrandan, 01:45:00).
- **ISO 9001:2015 ve ISO/IEC 90003:2018:** `ISO 9001:2015` genel amaçlı kurumsal kalite standardıdır (ikili [*binary*] yapıdadır: sertifika ya vardır ya yoktur). Ancak hoca slayttaki *"Genel vs. Özel (Peynir mi üretiyoruz?)"* notuyla genel standardın yazılım için soyut kaldığını, yazılım evleri için yazılıma özel kurumsal standart olan **`ISO/IEC 90003:2018`** standardının (ve veri güvenliği gibi ek standartların) esas alınması gerektiğini vurgulamıştır (ekrandan, 01:45:00). Türkiye'de ISO standartları için ulusal kamu otoritesi **TÜRKAK (Türkiye Akreditasyon Kurumu)** olup Denetik ve Türk Loydu gibi yetkilendirilmiş belgelendirici firmalar denetim yapar (ekrandan, 01:45:00).

> **Ders sonrası not:** Hoca konuşmasında veri güvenliği standardına değinirken *"14001 miydi, unuttum"* demiştir (01:47:14); ISO'nun bilgi/veri güvenliği yönetim sistemi standardı büyük olasılıkla **`ISO/IEC 27001`**'dir (`ISO 14001` çevre yönetim sistemi standardıdır).

#### CMMI Olgunluk Düzeyleri (0–5) ve CASE Araçlarıyla İlişkisi

CMMI birikimli (*kümülatif*) 6 düzey tanımlar (her düzey bir öncekinin gerekliliklerini de kapsar) (ekrandan, 02:10:00; ekrandan, 02:30:00):

| Düzey | Adı (İngilizce / Türkçe) | Süreç Özellikleri | CASE Araçlarının Kullanım Durumu |
| :--- | :--- | :--- | :--- |
| **0. Düzey** | **Incomplete** (Yürütülmeyen) | Süreç adımları tanımlı değil veya yürütülmüyor. | — |
| **1. Düzey** | **Initial / Performed** (Giriş düzeyi) | Etkinlikler yürütülür ancak sistematik tanımlama yoktur; başarı şansa ve **anahtar kişilere** bağlıdır (o kişi ayrılırsa proje durur). | CASE araçları firma genelinde tutarlı kullanılmaz; yazılım ölçütleri desteği ve yeniden kullanım (*reuse*) yoktur veya çok azdır. |
| **2. Düzey** | **Managed / Repeatable** (Yönetilen / Yinelenebilir) | Temel proje planlama ve izleme yöntemleri kullanılır; önceki projelerdeki başarılar yeni projelerde tekrarlanabilir. | CASE kullanım standartları tanımlıdır, çalışanlar eğitimlidir (*hands-on*); CASE araçları iş/proje yönetimi yazılımlarıyla entegredir, yeniden kullanım biraz iyileşmiştir. |
| **3. Düzey** | **Defined** (Tanımlanmış) | **Kişi ve risk yönetimi** ile proje yönetimi iyileştirilir; tüm organizasyonda standart süreçler tanımlanmıştır. **Büyük müşteriler en az bu düzeyi şart koşar; çevik süreçler bu düzeye kadar çıkabilir.** | Organizasyona ait ortak veri deposu (*repository*) ve tekrar kullanım kütüphanesi aktif kullanılır; yazılım ölçütleri (metrikler) toplanıp eğilim/profil belirlemek üzere veritabanında saklanır. |
| **4. Düzey** | **Quantitatively Managed** (Nicel Yönetilen) | Süreç ve yazılım ölçütleri kullanılarak kalite yönetimine geçilir; ilerleme sürekli izlenir, bütçe ve zaman sapmaları erkenden belirlenip önlem alınır. | Yazılım ölçütlerinin analizi ile süreç gelişimi ve o projedeki düzeltici önlemler oluşturulur. |
| **5. Düzey** | **Optimized** (İyileştirilmiş) | Süreç yönetimi geçmiş projelerin deneyimlerinin ışığında (geri besleme döngüsüyle) sonraki projeler için sürekli iyileştirilir. | Yeni yazılım araçları dahil tüm gereçler, teknikler ve proje yönetim süreçleri değerlendirilip sürekli iyileştirmeye tabi tutulur. |

**CMMI Tarihçesi ve Türkiye'den Kurum Örnekleri:** 1987'de *CMM* olarak başlayan model, 1998'de *CMMI* adını almış, 2010'daki **CMMI v1.3** ile çevik süreçleri desteklemeye başlamış, 2018'deki **CMMI v2.0** ile de eskiden ayrı olan üç alt alanı (`CMMI-DEV` [yazılım geliştirme], `CMMI-SVC` [hizmet/dış kaynak sunumu] ve `CMMI-ACQ` [ürün/hizmet alımı ve alt yüklenici yönetimi]) ve kısmi (*continuous*) / bütüncül (*staged*) ayrımını tek bir bütüncül çatı altında birleştirmiştir. Slaytta Türkiye'den CMMI Level 3+ sertifikalı kurum örnekleri olarak **MilSoft (Level 5)**, **TÜBİTAK BİLGEM YTE (Level 5)**, **Huawei Türkiye (Level 5)**, **ASELSAN (Level 3)**, **Cybersoft (Level 3)**, **Havelsan (Level 3)**, **Koç Sistem (Level 3)**, **Etiya (Level 3)**, **ICTerra (Level 3)** ve **OBSS (Level 3)** listelenmiş ve güncel listenin `https://sas.cmmiinstitute.com/pars/pars.aspx` (yeni arayüzünde `/pars/`) adresinden sorgulanabildiği gösterilmiştir (ekrandan, 02:20:00).

### 5. Gereksinim Mühendisliğine Giriş, SRS ve Yapıt (*Artifact*) Kavramı

Dersin son bölümünde yazılım yaşam döngüsünün ilk teknik halkası olan **Gereksinim Mühendisliğine (*Requirements Engineering*)** giriş yapılmıştır:

- **Amacı ve Fizibilite İlişkisi:** Üzerinde çalışılacak projenin amaçlarını, boyutlarını ve etkilerini belirleme çalışmalarıdır. Gereksinim mühendisliği aynı zamanda **yapılabilirlik (*feasibility*)** çalışmasına temel girdi sağlar: yasal/yönetmelik engelleri, insan kaynağı ve lisans maliyetleri, dış kaynak veya eğitim ihtiyacı ve projenin ne kadar sürede kâra geçeceği gereksinimler ortaya çıktıktan sonra hesaplanır; kârlı veya yapılabilir değilse projeye hiç başlanmaması kararı verilebilir.
- **Neden Zorunludur?** Müşterinin zihninde başlangıçta yalnızca genel bir fikir vardır ve ayrıntılar yoruma açıktır (*"şeytan ayrıntıda gizlidir"*). Yanlış veya eksik işi yapan "mükemmel" bir yazılım hiçbir işe yaramaz; önemli olan **doğru işi yapan iyi çözümdür**.
- **SRS (*Software Requirements Specification* — Yazılım Gereksinimler Belgesi) ve Standartlar (ekrandan, 02:40:00):** Gereksinim mühendisliği sonunda tüm gereksinimler **SRS** belgesi altında toplanır. Başlıca iki uluslararası standart vardır:
  1. **`IEEE 830-1998`:** Doğrudan SRS belgesinin oluşturulmasına odaklı standart (tire sonrası sayı yayın yılını gösterir) (ekrandan, 02:40:00).
  2. **`ISO/IEC/IEEE 29148:2011`:** *Systems and Software Engineering – Life Cycle Processes – Requirements Engineering* (Sistem ve yazılım mühendisliği yaşam döngüsü süreçleri kapsamında gereksinim mühendisliği standardı) (ekrandan, 02:40:00).
  Kaynakları sınırlı olan bir yazılım evi tüm standartlara aynı anda uymak zorunda değildir; en çok zorlandığı ve hata yaptığı süreç alanına yönelik standardı önceliklendirerek uygulamalıdır.
- **Yapıt (*Artifact / Artefact*) Tanımı:** Yazılım geliştirme sırasında **kaynak kod dışında ortaya çıkardığımız her türlü metin ve şemaya "artefact" (*artifact* / yapıt)** denir (SRS içindeki metinler, UML şemaları ve hatta bir derleme yöneticisinin [*build manager*] hedef platform derleme/bağlama yapılandırma XML dosyaları birer *artifact* olarak değerlendirilir) (ekrandan, 02:40:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
