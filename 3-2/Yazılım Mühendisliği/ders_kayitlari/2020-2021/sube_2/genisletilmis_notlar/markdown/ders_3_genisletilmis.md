# Ders 3 Genişletilmiş Notu: Klasik Yinelemeli Süreçler, Çevik Süreçler (XP ve Scrum), Süreç Sertifikasyonu (CMMI) ve Gereksinim Mühendisliğine Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Klasik Yinelemeli Süreç Modelleri: Sarmal Model ve Kazan-Kazan Modeli
- 2. Çevik (Agile) Süreçler: Çevik Manifesto ve Temel İlkeler
- 3. Çevik Süreci Yürütecek Ekibin Özellikleri ve Kendi Kendini Düzenleme
- 4. Çevik Süreçlerin Dezavantajları ve Sınırları
- 5. Çevik Süreç Örneği 1: Aşırı Programlama (XP: Extreme Programming)
- 6. Çevik Süreç Örneği 2: Scrum ve Çevik Modelleme İlkeleri
- 7. Süreç Sertifikasyonu ve Güncel Standartlar (CMMI, PMI, ISO 9001, ISO/IEC 90003)
- 8. Yazılım Yeterlilik Olgunluk Modeli (CMMI): Düzeyler, Tarihçe ve CASE İlişkisi
- 9. Gereksinim Mühendisliğine Giriş, SRS Standartları ve Yapıt (Artifact) Kavramı
- Dersin Toparlaması

## 1. Klasik Yinelemeli Süreç Modelleri: Sarmal Model ve Kazan-Kazan Modeli

Bir önceki derste şelale (*waterfall*) modeli ile ön ürün (*prototip*) modelinin güçlü yönlerini birleştirip zayıf yönlerini geride bırakmayı amaçlayan **artımsal (*incremental*) ve yinelemeli (*iterative*)** süreç modellerinin genel mantığına giriş yapılmıştı. Bu derste ilk olarak bu ailenin literatürdeki iki klasik temsilcisi olan **Sarmal Model (*Spiral Model*)** ve **Kazan-Kazan Modeli (*Win-Win Model*)** incelenmiştir. Şelale modeli dışındaki bu klasik modeller bugün sektörde doğrudan kullanılmasa da, yazılım mühendisliğine kazandırdıkları kritik kavramlar güncel süreçlerin içine yerleşmiştir.

### 1.1 Sarmal Model (Spiral Model)

Sarmal modelde süreç, merkezdeki başlangıç noktasından (en içteki koyu halkadan) başlayarak dışa doğru genişleyen bir sarmal eğri boyunca ilerler (ekrandan, 00:05:00). Her bir tam sarmal dönüş bir çevrimi (ilk turlarda genellikle yeni işlev ekleyen bir *artımı*, bazı turlarda ise iyileştirme yapan bir *iterasyonu*) temsil eder ve yazılımın hacmi her turda büyür. Sarmal düzlem 6 dilime (adıma) bölünmüştür (ekrandan, 00:05:00):

```text
               Planlama: Kaynaklar,           Risk Analizi:
               zamanlama, yapılacaklar, vb.   Teknik, mali ve politik riskler
                            \               /
                             \   (2)     (3)
     Müşteri ile İletişim:    \     .---.   /
     Gereksinimlerin     (1)   \  /  ---  \/    (4)  Çözümleme
     Belirlenmesi        ------- (  ( o )  ) ------- ve Tasarım
                         (6)   /  \  ---  /\    (5)
     Müşteri Tarafından       /    '-----'  \
     Ürünün                  /               \
     Değerlendirilmesi      /                 Gerçekleme ve Kurulum:
                                              Kullanıcı eğitimi, dokümantasyon, vb. dahil.
```

1. **Müşteri ile İletişim (Gereksinimlerin Belirlenmesi):** Çevrimin başında müşteriyle görüşülerek gereksinimler belirlenir (ekrandan, 00:05:00).
2. **Planlama (Kaynaklar, zamanlama, yapılacaklar vb.):** İlgili çevrimde kullanılacak insan kaynakları, yazılım geliştirme araçları, lisanslar, alınacak danışmanlık veya dış kaynak (*outsource*) hizmetleri ile hangi işin ne zaman yapılacağı ayrıntılı olarak planlanır (ekrandan, 00:05:00).
3. **Risk Analizi (Teknik, mali ve politik riskler):** Sarmal modelin literatüre en büyük katkısı, **risk analizinin bir kez yapılıp bırakılan bir iş değil, her çevrimde sürekli yapılması ve izlenmesi gereken bir etkinlik olduğunu** ortaya koymasıdır (ekrandan, 00:05:00). Hoca bu adımda üç temel risk türünü örneklerle açıklamıştır:
   - **Teknik riskler:** Yazılım geliştirme süreciyle ilgili her türlü teknik belirsizliktir. Örneğin kullanılacak programlama yaklaşımında deneyimli insan kaynağının bulunmaması veya müşterinin mevcut bir sistemiyle zorunlu bir tümleştirme (*integration*) yapılacak olmasına rağmen ekibin o sistemle daha önce hiç çalışmamış olması birer teknik risktir.
   - **Mali riskler:** İşletmenin finansal öz kaynaklarıyla ilgilidir. Örneğin öz kaynakları sınırlı olan bir yazılım evi, projenin Ar-Ge niteliğine güvenerek TÜBİTAK'ın TEYDEB destek programlarından birine başvurmuş olabilir; eğer destek çıkmazsa projeye hiç başlayamayacak veya sürdüremeyecek olması mali bir risktir.
   - **Politik riskler:** Ülke siyasetinden ziyade, yazılım evinin kendi içindeki veya müşteri kurumla arasındaki kurumsal/politik dinamiklerdir (ayrıca kamu politikalarında sağlık ve ulaşım gibi belirli sektörlere öncelik verilirken projenin öncelik verilmeyen bir alanda kalması da bu kapsamda değerlendirilebilir).
4. **Çözümleme ve Tasarım:** Nesneye yönelik analiz ve tasarım etkinlikleri yürütülür (ekrandan, 00:05:00).
5. **Gerçekleme ve Kurulum (Kullanıcı eğitimi, dokümantasyon vb. dahil):** Tasarlanan kısım kodlanır; ancak yazılım yalnızca kod olmadığı için teknik dokümantasyon ve son kullanıcı belgeleri de hazırlanır, ürün kullanıcı veya test ortamına kurulur ve kullanıcı eğitimi verilir (ekrandan, 00:05:00).
6. **Müşteri Tarafından Ürünün Değerlendirilmesi:** Müşteri kurulan ürünü dener; eksikleri, hataları ve memnun kaldığı noktaları geri bildirim olarak sunar. Ardından sarmalın bir üst halkasına geçilerek yeni gereksinimler ve geri bildirimlerle aynı 6 adım tekrarlanır (ekrandan, 00:05:00).

> **Ek bilgi (derste anlatılmadı):** Sarmal model (*Spiral Model*) ve onun paydaş odaklı uzantısı olan Kazan-Kazan Sarmal Modeli (*WinWin Spiral Model*), yazılım mühendisliği literatüründe büyük olasılıkla Barry Boehm tarafından (sırasıyla 1988 ve 1998 yıllarında) önerilmiştir.

### 1.2 Kazan-Kazan Modeli (Win-Win Model)

Sarmal modelin bir uzantısı olan **Kazan-Kazan Modeli (*Win-Win Model*)**, yazılım geliştirme sürecine **paydaş (*stakeholder*)** kavramını kazandırmıştır (hoca buradaki "kazan" kelimesinin yeniçerilerin kazan kaldırması değil, İngilizce *win* [kazanmak] anlamında olduğunu espriyle belirtmiştir) (ekrandan, 00:12:00).

- **Paydaş (*Stakeholder*):** Yazılımın başarısı ve başarısızlığının (olumlu veya olumsuz) etkileyeceği kişi ve kurumlardır (ekrandan, 00:12:00).

Tek bir müşteri kurum için özel bir yazılım geliştiriliyor olsa bile, o kurumun içinde farklı departmanlar, yöneticiler ve kullanıcı grupları vardır; ayrıca yazılımı geliştiren yazılım evinin üst yönetimi ve çalışanları da ayrı birer paydaştır. Yazılımın belirli bir işlevi bir paydaşa büyük kazanç ve kolaylık sağlarken, başka bir paydaşın iş yükünü artırabilir. Hiçbir çatışma olmasa bile, farklı paydaşlar yazılımın hangi bölümünün veya hangi kullanım senaryosunun (*use case*) daha öncelikli olduğu konusunda birbirleriyle çelişirler (*"önce bizim istediğimiz modül yapılsın"*).

Kazan-Kazan modeli bu çelişkileri yönetmek için her sarmal çevrimde şu 6 adımı izler (ekrandan, 00:12:00):
1. **İlgililerin (paydaşların) belirlenmesi,**
2. **Kazanma durumlarının belirlenmesi** (her paydaşın ne beklediği ve hangi koşulda kendini "kazanmış" sayacağı),
3. **Uzlaşma ve seçeneklerin belirlenmesi** (çelişen beklentileri uzlaştıracak alternatif çözüm seçeneklerinin çıkarılması),
4. **Seçeneklerin değerlendirilmesi ve risklerin çözülmesi** (tüm paydaşların toplamda optimum kazanç elde edeceği veya maliyet odaklıysa en düşük maliyetle uzlaşı sağlayacak seçeneğin seçilmesi ve risk analizi yapılması),
5. **Gerçekleme ve kurulum** (analiz ve tasarım etkinliklerini de içerir),
6. **İlgililer tarafından değerlendirmeler** (tüm paydaşların ürünü deneyip sonraki çevrim için geri bildirim vermesi) (ekrandan, 00:12:00).

## 2. Çevik (Agile) Süreçler: Çevik Manifesto ve Temel İlkeler

İlk derste incelenen proje başarı istatistiklerinde (*Dr. Dobb's Journal* ve *UYMS*), yazılım projelerinin başarı oranını geleneksel süreçlerdeki %50 düzeyinden %65–70 düzeyine çıkaran süreç ailesinin **Çevik (*Agile*) Süreçler** olduğu görülmüştü. Slaytta çevik süreçlerin tanımı şöyle verilmiştir (ekrandan, 00:20:00):

- **Çevik (*Agile*) Süreçler:** Değişen gereksinimler, teknik riskler gibi önceden belirlenemeyen durumlara ve yazılım ürününü etkileyebilecek her tür değişikliğe karşı **esneklik sağlayan** (artımsal) süreçlerdir (ekrandan, 00:20:00).

Çevik süreç ailesinin (bu derste ayrıntısıyla göreceğimiz **XP** ve **Scrum** dahil) ortak felsefesini anlamak için, bir yazılım geliştirme sürecinde etkili olan sekiz kavramın iki sütun hâlinde karşılaştırıldığı **Çevik Manifesto** ilkelerine bakmak gerekir (ekrandan, 00:20:00):

```text
   ÖNCELİKLİ OLANLAR (Sol Sütun)              YARARI KABUL EDİLENLER (Sağ Sütun)
   -----------------------------              ----------------------------------
• Bireyler ve etkileşimler                 >  • Süreçler ve gereçler
• Çalışan yazılım                          >  • Ayrıntılı belgeler
• Müşterinin sürece katılımı               >  • Sözleşme pazarlığı
• Değişikliklere uyum sağlamak             >  • Bir planı izlemek
```

> **Hocanın vurgusu:** Çevik süreçler, sağ taraftaki maddelerin yararını ve gerekliliğini kabul etmekle birlikte, **sol taraftaki maddelere daha çok önem vermektedir** (ekrandan, 00:20:00).

Hoca bu dört karşılaştırmanın altında yatan mühendislik gerçeğini şöyle açıklamıştır:

1. **Bireyler ve etkileşimler vs. Süreçler ve gereçler:** Yazılım mühendisliği yalnızca kod yazma veya makinelerle uğraşma işi değil, her şeyden önce bir **insan işidir**. Ekip üyeleri teknik açıdan ne kadar yetenekli olursa olsun, hem yazılım evi hem de müşteri tarafındaki bireyler birbirleriyle açık, net ve verimli iletişim kurup bir ekip olarak kenetlenemiyorsa proje başarısız olur. İyi tanımlanmış süreçler başarı şansını artırsa da **amaç bireyleri katı bir sürece uydurmak değildir**. Örneğin katı hiyerarşik bir kurumda bir kişiden görüş almak için resmi form doldurup ertesi gün yanıt beklemek yerine, kahve makinesi önünde yüz yüze ya da anlık mesajlaşmayla *"şu iş nasıl yapılıyor?"* diye sorup dakikalar içinde çözebilmek gerekir.
2. **Çalışan yazılım vs. Ayrıntılı belgeler:** İlk derste vurgulandığı üzere yazılım yalnızca çalışan kod değildir, belgelendirme de şarttır. Ancak zaman ve emek sınırlı olduğunda ayrıntılı belgeler üretmek ile doğru çalışan yazılım üretmek arasında bir denge kurulmalı ve birincil ağırlık çalışan yazılıma verilmelidir.
3. **Müşterinin sürece katılımı vs. Sözleşme pazarlığı:** Değişiklik maliyeti zamanla üstel arttığı için, özellikle gereksinim ve analiz aşamalarında müşterinin (veya problem alanı uzmanının) sürece aktif katılması hayati önem taşır. Elbette projenin başında yazılım gereksinimleri belgesi ortaya çıktıktan sonra süre, bütçe ve ödeme koşullarını belirleyen bir sözleşme imzalanır; ancak süreç boyunca her değişiklik talebinde sözleşme maddelerini tarafların kendi lehine yontmaya çalıştığı kısır pazarlıklar yerine müşteriyle işbirliği yapmak esastır.
4. **Değişikliklere uyum sağlamak vs. Bir planı izlemek:** Problem alanı, iş kuralları ve yönetmelikler değiştiği için gereksinim değişikliği kaçınılmazdır. Haritasız yola çıkılamayacağı için mutlaka bir ana plan yapılır; ancak başarı için katı planı körü körüne izlemek değil, ortaya çıkan değişikliklere uyum sağlamak önceliklidir.

Bununla birlikte slaytta çok kritik bir denge uyarısı yer alır (ekrandan, 00:20:00):
- **Bir ilerleme olmaksızın yalnızca sürekli uyum sağlamak başarı değildir.** Bu nedenle çevik süreçlerde üç temel ilke birlikte yürütülür (ekrandan, 00:20:00):
  1. **Yazılımın artımsal gelişimi,**
  2. **Müşteriye erken ve sık ürün teslimi** (müşterinin ürünü erkenden deneyip değerlendirebilmesi),
  3. **Başarımın birincil ölçütü doğru çalışan yazılımdır** (zamanlamada, bütçede veya bazı gereksinimlerde değişiklikler olsa bile müşteriye doğru çalışan bir yazılım teslim etmek en önemli başarı ölçütüdür).

## 3. Çevik Süreci Yürütecek Ekibin Özellikleri ve Kendi Kendini Düzenleme

Çevik süreçler bireylere ve etkileşimlere dayandığı için, bu süreçlerle çalışacak ekibin belirli niteliklere sahip olması zorunludur. Hoca, *"Eğer bu özelliklere sahip değilsek veya kazanamıyorsak çevik süreçler bizim için uygun değildir, nokta; o zaman klasik süreçlerle çalışırız"* diyerek şu sekiz özelliği sıralamıştır (ekrandan, 00:27:00):

1. **Yüz yüze görüşme, en etkili bilgi aktarım yoludur:** İki kişi arasındaki etkileşim öncelikle yüz yüze ve sözlü olarak kurulmalıdır (ekrandan, 00:27:00).
2. **Takım üyeleri çevik yaklaşım hakkında eğitilmelidir** (ekrandan, 00:27:00).
3. **Ekip üyelerinin ortak amacı, çalışan yazılım üreterek müşteriye zamanında teslim etmek olmalıdır** (ekrandan, 00:27:00).
4. **Ekip üyeleri birbirleriyle ve müşteriyle işbirliği içinde olmalıdır:** Müşteri sürecin başından sonuna kadar ekiple birlikte çalışmayı şekillendirir (ekrandan, 00:27:00).
5. **Ekip üyeleri karşılıklı saygı ve güven içerisinde olmalıdır** (ekrandan, 00:27:00).
6. **Ekipler hem teknik, hem de tüm proje hakkında kararlar verebilmelidir:** Müşterinin de dahil olduğu yazılım ekibine belirli bir otonomi (özerklik) tanınmalıdır (ekrandan, 00:27:00).
7. **Boşuna harcanan çaba yoktur:** Çözülen bir sorun sonradan gereksizleşse (veya müşteri o özellikten vazgeçse) bile, çözüm sürecinde edinilen deneyim ekibe ileri aşamalarda yararlı olabilir (ekrandan, 00:27:00).
8. **Kendi kendini düzenleme (*Self-organization*) (ekrandan, 00:27:00):**
   - **Ekibin kendisini yapılacak işe göre uyarlaması:** Geleneksel bir ekipte ekip lideri, analist, geliştiriciler (*developers*) ve testçiler (*testers*) şeklinde sabit bir hiyerarşi vardır. Ancak ekip daha önce hiç deneyimlemediği bir **Ar-Ge projesine** girdiğinde hiyerarşik yapı verimsizleşir; çünkü ekip liderinin bilmediği o yeni konuyu, işe geçen yıl girmiş ama yüksek lisans tezini tam o alanda yapmış bir ekip üyesi çok daha iyi biliyor olabilir. Böyle bir durumda ekip, hiyerarşik yapıdan **eşler arası (*peer-to-peer*) matris organizasyona** geçebilmeli ve rolleri değiştirebilmelidir.
   - **Ekibin kullanacağı süreci yerel ortama uyarlaması:** Örneğin standart öneri 3 haftalık artımlar olsa bile, eldeki iş kalemleri daha küçük veya riskliyse ekip çevrim süresini 2 haftaya çekebilmelidir.
   - **Üstünde çalışılan artımsal yazılım parçasını teslim etmek için gerekli çalışma zamanlamasını ekibin kendisinin belirlemesi:** Zor bir problemi çözerken ekip kendi kararıyla 2–3 hafta boyunca akşam 6 yerine 8–9'a kadar mesaiye kalabilmeli; buna karşılık sonraki çevrim daha kolaysa akşam 4–5'te çıkabilmeli veya sabah 9 yerine 10'da gelebilmelidir. *"Sabah 9.00'da kart basacaksın, akşam 17.30'dan önce basarsan maaşından keserim"* diyen katı mesai düzeni çevik süreçlerle bağdaşmaz.

## 4. Çevik Süreçlerin Dezavantajları ve Sınırları

Çevik süreçler sihirli bir değnek veya her projede başarının garantisi değildir. Slaytta çevik süreçlerin dört temel dezavantajı ve sınırı belirtilmiştir (ekrandan, 00:35:00):

1. **Uygun olmayan ekiple (veya kurum kültürüyle) çevik çalışılamamaktadır:** Hem yazılım ekibi hem de yazılım evinin ve müşterinin kurumsal yapısı çevik ilkeleri benimsemiyorsa bu süreçler uygulanamaz (ekrandan, 00:35:00).
2. **Kalabalık ekip veya büyük ölçekli projeler için uygun görülmemektedir:** Hoca bunu **en önemli dezavantaj** olarak vurgulamıştır. Buradaki "ölçek" hem **kişi/paydaş sayısı** hem de **yazılımın büyüklüğü** anlamına gelir:
   - *Kişi ve lokasyon ölçeği:* 5–8 kişilik bir ekipte herkes birbiriyle sürekli yüz yüze görüşebilir; ancak 20 kişilik bir ekipte veya farklı şehirlerdeki (ör. İstanbul ve Gaziantep) ya da farklı ülkelerdeki ve zaman dilimlerindeki (ör. Ankara, 3 saat fark olan Lizbon ve 10 saat fark olan Washington ofislerindeki) ekiplerde anlık yüz yüze iletişim kurmak imkânsızdır.
   - *Yazılım büyüklüğü ölçeği:* Çok büyük bir yazılımda işlevleri 3 haftalık kullanıcı öykülerine böldüğünüzde ortaya çıkan öykü sayısı yönetilemeyecek kadar büyür.
3. **Bir dış denetleyicinin dahil olduğu ve ayrıntılı kuralların gerektiği, denetlemelerin zorunlu olduğu projelerde yetersiz kalmaktadır:** Bankacılık ve finans yazılımları gibi ağır yasal mevzuatlara, yönetmeliklere ve dış denetime tabi projelerde ayrıntılı belgelendirme zorunludur ve ekip ya da müşteri yasal olarak zorunlu olan işlevlerden vazgeçemez. Bu tip finansal projeler aynı zamanda büyük ölçekli olma eğiliminde olduğundan buralarda genellikle klasik süreçler kullanılır (ekrandan, 00:35:00).
4. **Çevik çalışmak disiplinsizlik olarak yorumlanmamalıdır:** Üst yönetim çevik esnekliği "kuralsızlık/disiplinsizlik" olarak görmemeli, teknik ekip de bu esnekliği suistimal ederek disiplinsizliğe dönüştürmemelidir (ekrandan, 00:35:00).

Bu dört engel söz konusu değilse proje başarı oranını yükselttiği için ilk tercih çevik süreçler olmalı; bunlardan biri bile varsa klasik süreçler tercih edilmelidir.

## 5. Çevik Süreç Örneği 1: Aşırı Programlama (XP: Extreme Programming)

Çevik süreç ailesinin ilk önemli örneği **Aşırı Programlama (*XP: Extreme Programming*)** modelidir (ekrandan, 00:35:00). XP; **Planlama $\rightarrow$ Tasarım $\rightarrow$ Kodlama $\rightarrow$ Sınama** adımlarından oluşan kısa çevrimlerle ilerler ve her çevrimin sonunda müşteriye çalışan bir artımsal ürün teslim edilir.

### 5.1 Planlama ve Kullanıcı Öyküleri (User Stories)

XP'de planlama aşaması **kullanıcı öykülerine (*user stories*)** dayanır:
- **Kullanıcı öyküsü (*user story*):** Müşterinin işine yarayacak, müşteri için anlamlı bir işlevdir. Koca bir modül büyüklüğünde değil, yaklaşık **3 hafta ($\pm 1$ hafta)** gibi kısa bir çevrimde gerçeklenebilecek "yutulabilir bir hap" büyüklüğünde olmalıdır.
- **Derecelendirme ve Bölme:** Kullanıcı öykülerini analiz ekibinin geri bildirimleriyle **müşteri (kullanıcı)** belirler ve kendi iş ihtiyaçlarına göre **önceliklendirir (önem derecesi verir)**. **Yazılım ekibi** ise her öyküyü **teknik zorluk ve risk** açısından derecelendirir. Eğer bir öykü 3 haftada bitirilemeyecek kadar geniş/kaba (*coarse-grained*) ise — örneğin 6 veya 9 hafta sürecekse — müşteriden bu öyküyü 2 veya 3 alt öyküye bölmesi istenir.
- **Sıralama Stratejileri:** Öykülerin çevrimlere hangi sırayla alınacağına müşteri ve teknik ekip birlikte karar verir. İki ana yaklaşım (veya bunların melezi/*hibrit* bir çözüm) uygulanabilir:
  1. **Önce yüksek teknik riskli öykülerin gerçeklenmesi:** Değişiklik maliyeti zamanla üstel arttığı için, en zor ve riskli kısımları en başta kodlamak olası hataları ve darboğazları erkenden yakalamayı sağlar. Hatta o işin eldeki kısıtlarla yapılamayacağı veya sözleşmede büyük bir revizyon gerektiği ortaya çıkacaksa, çok fazla yatırım yapmadan en başta başarısız olmak (***fail fast***) çok daha az zarar verir.
  2. **Önce müşteri için yüksek öncelikli öykülerin gerçeklenmesi:** İlerleyen aşamalarda yüksek riskli bir öykü yüzünden süre biterse, kalan riskli öykülerden karşılıklı anlaşmayla vazgeçilir ve müşterinin elinde en azından en temel ihtiyaçlarını karşılayan çalışan bir ürün kalır. Hoca bunu **A noktasından B noktasına ulaşım** benzetmesiyle açıklamıştır: Hedefimiz B sınıfı bir otomobil üretmek olsa bile, süre yetmediğinde müşteriye yürümekten çok daha az çabayla A'dan B'ye gitmesini sağlayacak bir **motosiklet, bisiklet veya paten** teslim edebilmek hiç ürün teslim edememekten çok daha iyidir.
- **Proje Hızının (*Velocity*) Ölçülmesi ve Dinamik Planlama:** Artımsal teslimatlar projenin ilerleme hızını ölçmeyi de sağlar. Örneğin 3 hafta öngörülen 10 çevrimin 7–8 tanesi 4 haftada tamamlanmışsa, çevrimleri 3 haftadan 4 haftaya çıkarmak proje süresinin **%33 uzaması** demektir. Bu durumda müşteriyle görüşülerek ya bitiş tarihi uzatılır ya da orijinal tarihe yetişmek için müşteri bazı öykülerden vazgeçer (sonradan ekip tekrar hızlanırsa vazgeçilen öyküler yeniden plana alınabilir). Proje tamamlanana kadar müşteri uzlaşmayla yeni öykü ekleyebilir, öncelik değiştirebilir veya öyküleri bölebilir.

### 5.2 Tasarım: KISS İlkesi, CRC Kartları, Spike Solution ve Refactoring

XP'nin tasarım aşamasında dört temel ilke ve araç öne çıkar:

1. **KISS İlkesi (*Keep It Simple, Stupid*):** Tasarımda karmaşıklıktan kaçınılmalı, her zaman en basit çalışan tasarım seçilmelidir. Bir işi olması gerekenden daha karmaşık tasarlamak hatadır.
2. **CRC Kartları (*Class-Responsibility-Collaborator* — Sınıf-Sorumluluk-İşbirlikçi):** XP, UML sınıf şemalarını bile zorunlu tutmaz (hoca şahsi görüş olarak en azından genel bir UML sınıf şeması çizilmesini önerse de); yalnızca CRC kartları hazırlanmasını yeterli görür. Zira CRC kartlarını hazırlayan bir ekip buradan UML sınıf şemasını neredeyse otomatik olarak çıkarabilir. Slaytta gösterilen örnek **`Satış`** sınıfı CRC kartı şöyledir (ekrandan, 01:08:00):

| **Sınıf: Satış** | |
| :--- | :--- |
| Kasada yapılan ödemeyi simgeleyen sınıf. | |
| **Üst Sınıf(lar):** Yok | |
| **Alt Sınıf(lar):** Yok | |
| **Sorumluluk:** | **İşbirlikçi:** *(Sınıf adları)* |
| Satışın yapıldığı tarih ve saati saklamak | |
| Yapılan ödeme tutarını saklamak | `Ödeme` |
| Satılan malların listesine erişim | `Mal` |

   - **Kartın Üst Bölümü:** Sınıfın adı (`Satış`), neyi modellediği (*"Kasada yapılan ödemeyi simgeleyen sınıf"*) ve kalıtım ilişkisi varsa **Üst Sınıf(lar)** ile **Alt Sınıf(lar)** yazılır (güncel nesneye yönelik diller çoklu kalıtımı [*multiple inheritance*] sakıncaları nedeniyle desteklemediğinden genellikle tek üst sınıf olur, ancak birden fazla alt sınıf olabilir) (ekrandan, 01:08:00).
   - **Sorumluluk ve İşbirlikçi Sütunları:** Sol sütuna sınıfa yüklenen sorumluluklar, sağ sütuna ise o sorumluluğu yerine getirmek için ilişkili olduğu diğer sınıflar yazılır. Örneğin *"Satışın yapıldığı tarih ve saati saklamak"* sorumluluğu için başka bir sınıfla işbirliği gerekmez; bu doğrudan sınıfın içindeki bir üye alana (ör. Java'da `java.util.Date` türünden bir alana) dönüşür. *"Yapılan ödeme tutarını saklamak"* için `Ödeme` sınıfıyla, *"Satılan malların listesine erişim"* için `Mal` sınıfıyla işbirliği yapılır; bunlar da UML sınıf şemasındaki birliktelik/sahiplik/kullanım oklarına karşılık gelir (ekrandan, 01:08:00).
   - **Ekip İçi Tasarım Gözden Geçirme:** Hazırlanan tüm CRC kartları ekip üyelerine eşit sayıda dağıtılır (örneğin 50 sınıf varsa 5 kişilik ekipte herkese 10'ar kart verilir). Her üye elindeki kartları inceler; bir eksiklik veya hata görürse dile getirir. Ekip tartışarak gerçekten sorun varsa kartı düzeltir, sorun yoksa soruyu soran üyeyi ikna eder. Ardından **herkes elindeki kart destesini yanındaki arkadaşına verir**. Bu döngü tamamlandığında ekipteki herkes projenin tüm sınıflarını ayrıntısıyla incelemiş ve onaylamış olur.
3. **Ön Gerçekleme (*Spike Solution* / *Proof of Concept*):** Eğer problemin bir parçasında karmaşık bir tasarımdan kaçınılamıyorsa, bu tasarımın geçerli olup olmadığını sınamak için sadece o kısma odaklanan küçük bir işlevsel ön gerçekleme (birkaç sınıf/metot ölçeğinde kavram kanıtı / *proof of concept* prototipi) yazılır; buna XP literatüründe **Spike Solution** denir.
4. **Yeniden Düzenleme (*Refactoring*):** Yeni bir kullanıcı öyküsünü eklerken mevcut tasarımın iç yapısını değiştirmek kodlamayı daha verimli hâle getirecekse (veya çevrimde beklenenden hızlı ilerlenip zaman kazanılmışsa), dış arayüzleri ve testleri bozmadan tasarımı iyileştirmek (*refactoring*) sürekli teşvik edilir.

### 5.3 Kodlama ve Sınama: Test Güdümlü Geliştirme (TDD) ve Eşli Programlama (Pair Programming)

XP'ye "aşırı (*extreme*)" adını veren asıl uygulamalar kodlama aşamasındadır:

1. **Önce Birim Sınamalarının (*Unit Test*) Hazırlanması — Test Güdümlü Tasarım (*Test-Driven Design / Development* - TDD):**
   Nesneye yönelik programlamada en temel birim **sınıftır**; dolayısıyla birim sınaması (*unit test*) bireysel sınıfların sınanmasıdır. XP, daha kodu yazmaya başlamadan **önce birim testlerinin yazılmasını** önerir. Eğer bir sınıfın testini yazmakta zorlanıyorsanız, o sınıfı eksik veya esnek olmayan bir biçimde tasarlamışsınız demektir.
2. **Yalnızca Sınamayı Geçmeye Yarayan Kodun Yazılması:**
   Programcı *"acaba ileride müşteri şöyle bir değişiklik isterse diye şimdiden daha genel ve karmaşık bir kod yazayım"* düşüncesine kapılmamalıdır; çünkü müşteri belki o öyküden tamamen vazgeçecek veya bambaşka bir değişiklik isteyecektir ve harcanan ekstra emek çöpe gidecektir. Bu nedenle **sadece o anki birim testini geçecek kadar kod** yazılır (bununla birlikte ekip TDD ile rahat edemiyorsa testleri kodla paralel veya koddan hemen sonra da yazabilir).
3. **Çift Kişiyle / Eşli Programlama (*Pair Programming*):**
   Hoca bu pratiği **tüplü dalış (*scuba diving*)** benzetmesiyle açıklamıştır: Su altı insan doğası için ölümcül tehlikeler (keskin taşların giysiyi yırtması, oksijen hortumunun dolanması, bayılma, hızlı çıkışta vurgun yeme) barındırdığından asla tek başına tüplü dalış yapılmaz; mutlaka iki kişi birbirinin **dalış eşi (*buddy*)** olarak dalar ve sürekli birbirinin tüpünü, gaz kaçağını, çevreyi ve çıkış hızını denetler.
   XP'deki **eşli programlamada (*pair programming*)** da **tek bir bilgisayarın başında iki yazılımcı birlikte çalışır**:
   - **Birinci kişi:** Klavye ve fareyi kullanarak kodu yazar.
   - **İkinci kişi:** Yazılan kodu anlık olarak denetler; kodun genel tasarıma, kararlaştırılan kalite ölçütlerine ve kodlama standartlarına (girintileme / *pretty printing*, bir satıra 5–6 zincirleme işlem sıkıştırıp karmaşıklığı artırmama vb.) uygunluğunu kontrol eder. Böylece kod yazan kişi ayrıntılara gömülmüşken ikinci kişi **"büyük resmi"** ve ana proje planını kaçırmamayı sağlar; ayrıca eşlerden biri daha kıdemliyse doğal bir usta-çırak bilgi aktarımı gerçekleşir.
   *(Not: Küçük bir KOBİ yazılım evinde her bilgisayara iki kişi oturtacak insan kaynağı yoksa, çevik uyarlama ilkesi gereği eşli programlama atlanabilir veya Scrum modeli tercih edilebilir.)*
4. **Sınama:** Hazırlanan birim sınamaları otomatik test araçlarıyla (ör. Java'da **`JUnit`**) sürekli koşturulur, kök neden analizli hata raporları incelenir ve çevrim sonunda müşteri artımsal ürünü dener.

## 6. Çevik Süreç Örneği 2: Scrum ve Çevik Modelleme İlkeleri

### 6.1 Scrum Süreci ve Günlük Toplantılar

İkinci çevik süreç modeli olan **Scrum**, adını Amerikan futbolundan farklı olarak koruyucu kıyafetler olmadan oynanan **ragbi (*rugby*)** sporundaki bir taktikten alır: topu alan oyuncunun etrafında takımın geri kalan oyuncuları neredeyse etten bir duvar oluşturarak rakibi ezip geçecek bir sürü hâlinde hedefe koşar.

Scrum süreci üç ana adımdan oluşan bir çevrimdir (ekrandan, 01:28:00):

- **Adımlar:** `Görev Listesi -> Koşu -> İşlev Gösterimi` (ve tekrar `Görev Listesi`'ne dönüş) (ekrandan, 01:28:00).
- **Görev Listesi:** XP'deki **kullanıcı öykülerinin** birebir karşılığıdır; önem ve önceliğe göre sıralanmıştır (ekrandan, 01:28:00).
- **Koşu (*Sprint*):** Görev listesinin maddelerinden biri (veya birkaçı) seçilir ve önceden belirlenmiş kısa bir süre içerisinde (**ör. 1–4 hafta**; Scrum süreyi 1 haftaya kadar indirebilmektedir) gerçeklenir (ekrandan, 01:28:00). Scrum'ın XP'den en önemli farkı, eşli programlama şartı koşmaması ve bunun yerine **koşu süresince ekibin her gün yaptığı kısa (ör. 15 dakikalık) toplantılar** önermesidir (ekrandan, 01:28:00):
  - Toplantılar resmi ve uzun değil, tüm ekibin katıldığı 15 dakikalık yüz yüze sözlü toplantılardır.
  - Toplantıyı dağılmaması için **proje lideri (ekip lideri)** yönetir.
  - Proje lideri kendisi de dahil olmak üzere herkese şu **üç ana soruyu** yöneltir (ekrandan, 01:28:00):
    1. **Son toplantıdan bu yana (dünden beri) ne yaptınız?**
    2. **Karşılaştığınız engeller nelerdir?**
    3. **Yarınki toplantıda neleri başarmayı hedefliyorsunuz?**
  Bu üç soru sayesinde ekipteki herkes birbirinin ilerlemesinden ve takıldığı engellerden her gün haberdar olur.
- **İşlev Gösterimi:** Müşterinin en yeni işlevi veya o ana dek gerçeklenen tüm işlevleri sınamasıdır (ekrandan, 01:28:00).

**Pre-Scrum (*Kick-off*) ve Post-Scrum Aşamaları:** Hoca, bu üç adımlı hızlı çevrimlerin en başına ve en sonuna iki ek aşama konulmasının önerildiğini belirtmiştir:
1. **Pre-Scrum (*Kick-off* / Başlama Vuruşu):** Gereksinim mühendisliği ve ilk risk analizi çalışmalarını koşuların hızlı temposuna sıkıştırıp aceleye getirmemek için, görev listesi oluşturulmadan önce ayrıntılı gereksinim ve risk analizinin yapıldığı başlangıç aşaması.
2. **Post-Scrum:** Proje tamamlanmaya yaklaştığında eksik kalan teknik/kullanıcı belgelendirmelerinin tamamlanması ve son kullanıcı eğitimlerinin verilmesi gibi işlerin ayrı birer koşu yerine toplu olarak yürütüldüğü kapanış aşaması.

### 6.2 Çevik Modelleme ve Araç Kullanımı İçin Tavsiyeler

Hoca çevik süreçler konusunu bağlarken modelleme ve araç kullanımına dair üç önemli ilke vurgulamıştır:
- **Hedef kitleye göre modelleme:** Çizilen bir şema veya belge kime anlatılacaksa o paydaşın anlayacağı düzeyde olmalıdır. Teknik ekibe ayrıntılı sınıf ve metot şemaları çizilebilir; ancak sınıflardan ve metotlardan anlamayan bir konu alanı uzmanına (müşteriye) sunum yaparken vakit kaybedip ağır teknik şemalar çizmek yerine yalnızca iş akışını özetleyen yalın modeller kullanılmalıdır.
- **Sunumdan ziyade içerik önemlidir:** Bir model görsel olarak ne kadar kusursuz çizilirse çizilsin, aktarılması gereken bilgiyi içermiyorsa işe yaramaz.
- **Araçlara önceden hâkimiyet (*Hands-on experience*):** Çevik süreçler çok hızlı bir tempoda akar; koşu başladıktan sonra *"bu CASE aracı nasıl kullanılıyordu, `JUnit`'te test nasıl koşturuluyordu?"* diye araç öğrenmeye vakit harcanamaz. Ekibin kullanacağı modelleme ve test araçları hakkında önceden uygulamalı deneyime (*hands-on experience*) sahip olması şarttır.

## 7. Süreç Sertifikasyonu ve Güncel Standartlar (CMMI, PMI, ISO 9001, ISO/IEC 90003)

İyi bir yazılım geliştirme sürecine sahip olmak tek başına yeterli değildir; süreci doğru ve verimli uygulamak gerekir. Bir yazılım firması, süreçlerinin yeterliliğini ve bu süreçleri düzgün yürüttüğünü **bağımsız kurumlara denetletip onaylatmayı (süreç sertifikasyonu / akreditasyonu)** seçebilir (ekrandan, 01:45:00).

- **Gerekli Olduğu Durumlar:** Birinci neden firmanın kendini sürekli iyileştirme isteğidir; ancak asıl büyük güdüleyici etken, **büyük kurumsal müşterilerin, bakanlıkların ve askeri kurumların yüksek bütçeli yazılım ihalelerine katılabilmek için bile belirli bir düzeyde süreç sertifikasyonunu şart koşmasıdır** (ekrandan, 01:45:00). Hoca bunu günlük hayattan bir benzetmeyle açıklamıştır: Nasıl ki tüm iş sürecinizi bağlayacağınız bir ERP yazılımını pazardan elma seçer gibi veya rastgele bir hırdavatçıya girip ustalık/kalfalık belgesine bakmadan elektrik tesisatı teslim eder gibi alamazsanız, büyük kurumlar da kritik projelerini yalnızca liyakati ve süreç olgunluğu bağımsızca belgelendirilmiş yazılım evlerine teslim ederler.
- **Gereksiz Olduğu Durumlar:** **Çok küçük şirketler (KOBİ'ler) ve/veya küçük ölçekli projeler için süreç sertifikasyonu gereksiz bir ek yüktür** (ekrandan, 01:45:00). Çünkü sertifikasyon denetimlerine hazırlanmak ve kanıt belgeleri üretmek ciddi bir zaman, insan gücü ve para maliyeti gerektirir; küçük bir projeye kendi hacmi kadar sertifikasyon masrafı yüklemek mantıksızdır (hatta akredite büyük bir firma bile çok küçük bir iç proje yaparken ağır akredite süreç adımlarını işletmeyebilir).

Slaytta süreç sertifikasyonu alanında öne çıkan **üç ana model ve standart ailesi** tanıtılmıştır (ekrandan, 01:45:00):

1. **CMMI (*Capability Maturity Model Integration*):**
   - ABD'deki **Carnegie Mellon Üniversitesi** bünyesinde bulunan **SEI (*Software Engineering Institute*)** tarafından önerilmiştir (ekrandan, 01:45:00).
   - **Kurumsal** bir akreditasyondur (bireylere değil kurumlara verilir).
2. **PMI (*Project Management Institute*):**
   - ABD kökenli genel amaçlı bir proje yönetimi yaklaşımıdır (son yıllarda yazılım projelerine özel alt dalları da eklenmiştir) (ekrandan, 01:45:00).
   - CMMI ve ISO'dan farklı olarak hem **bireysel** hem de **kurumsal** akreditasyonları vardır (ekrandan, 01:45:00).
3. **ISO 9001:2015 ve ISO/IEC 90003:2018 Standartları:**
   - **`ISO 9001:2015`:** Uluslararası Standartlar Organizasyonu'nun (*International Organization for Standardization*) **genel amaçlı** ve **kurumsal** kalite yönetim standardıdır (iki noktadan sonraki `2015` sayısı standardın son güncellendiği yılı gösterir; standartlar genellikle 5–10 yılda bir güncellenir) (ekrandan, 01:45:00).
   - **`ISO/IEC 90003:2018`:** Genel amaçlı `ISO 9001` standardı yazılım mühendisliği etkinlikleri için fazla soyut kalır (hoca slaytta bunu **"Genel vs. Özel (Peynir mi üretiyoruz?)"** ifadesiyle vurgulamıştır). Bu nedenle yazılım geliştirmeye özel kurumsal standart olarak **`ISO/IEC 90003:2018`** tanımlanmıştır (ekrandan, 01:45:00).
   - **Ulusal Otorite ve Belgelendirme:** Türkiye'de tüm ISO standartları için ulusal kamu otoritesi **TÜRKAK (Türkiye Akreditasyon Kurumu)**'dur; yazılım alanında **Denetik**, diğer mühendislik alanlarında **Türk Loydu** gibi TÜRKAK tarafından yetkilendirilmiş belgelendirici firmalar rapor incelemesi ve yerinde denetim yaparak 1–4 yıllık sürelerle akreditasyon verir (ekrandan, 01:45:00).

> **Ders sonrası not:** Hoca konuşması sırasında yazılım firmalarının `ISO 90003` dışında veri güvenliği gibi alanlarda da standart alabileceğini belirtirken *"veri güvenliğine yönelik neydi, 14001 miydi, unuttum"* demiştir (01:47:14). ISO'nun bilgi ve veri güvenliği yönetim sistemi standardı büyük olasılıkla **`ISO/IEC 27001`**'dir (`ISO 14001` çevre yönetim sistemleri standardıdır).

## 8. Yazılım Yeterlilik Olgunluk Modeli (CMMI): Düzeyler, Tarihçe ve CASE İlişkisi

### 8.1 CMMI Olgunluk Düzeyleri (0'dan 5'e)

`ISO 9001` gibi standartlar "var veya yok" şeklinde ikili (*binary*) yapıda iken, **CMMI** kademeli bir olgunluk modeli sunar. CMMI başlı başına bir uzmanlık ve kariyer alanıdır; büyük kurumlarda yalnızca bu süreç olgunluğunu yöneten ayrı kalite departmanları bulunur ve modelin `http://www.sei.cmu.edu/cmmi/` adresinden ücretsiz indirilebilen ana dokümanı **700'den fazla sayfadır** (ekrandan, 02:10:00).

CMMI'da her düzeyin bir önceki düzeyin üzerine yeni süreç alanları koyarak ilerlediği **birikimli (*kümülatif*) 6 düzey (0–5)** tanımlanmıştır (ekrandan, 02:10:00):

- **0. Düzey — Yürütülmeyen (*Level 0: Incomplete*):** Hiçbir süreç adımı tanımlı değildir veya yürütülmemektedir (ekrandan, 02:10:00).
- **1. Düzey — Giriş Düzeyi (*Level 1: Initial / Performed*):** Yazılım geliştirme etkinliklerinin tümü yürütülüyor olsa da bunların tanımlanması ve denetlenmesi için hiçbir sistematik girişim yoktur; her projede farklılaşabilirler. **İş şansa ve anahtar kişilere (kahramanlara) kalmıştır**; ekipteki kilit bir kişinin işten ayrılması veya sağlık sorunu yaşaması projeyi tamamen durdurur (ekrandan, 02:10:00).
- **2. Düzey — Yönetilen / Yinelenebilir (*Level 2: Managed / Repeatable*):** 1. düzeyin üzerine **temel proje planlama ve izleme yöntemleri** eklenir. Bu yöntemler sayesinde daha önceki projelerde elde edilen başarılar yeni projelerde de tekrarlanabilir (ekrandan, 02:10:00).
- **3. Düzey — Tanımlanmış (*Level 3: Defined*):** 2. düzeydeki temel planlama ve izlemenin üzerine **kişi yönetimi** (bireyler arası etkileşimlerin yönetimi ve kanıt belgeleri) ile **risk yönetimi** eklenir; tüm organizasyonda standart süreçler tanımlanmıştır ve uygulanmaktadır (ekrandan, 02:10:00).

> **Hocanın vurgusu:** **CMMI Level 3** en kritik eşiktir. Büyük kurumsal müşteriler ve savunma sanayii kurumları çalışacakları yazılım evlerinde **en az CMMI Level 3** sertifikası ararlar (ekrandan, 02:10:00). Hoca ayrıca öğrencilere kariyer tavsiyesi olarak, CMMI Level 3 akreditasyonuna sahip bir yazılım evinden veya BT departmanından iş teklifi aldıklarında o kurumun süreçlerinin çok düzenli olduğundan emin olabileceklerini ve teklifi kabul etmelerini önermiştir. Ayrıca **çevik (*agile*) süreçler CMMI Level 3'e kadar tam uyumluluk sağlayabilmektedir** (ancak Level 4 ve 5 çevik süreçlerle pek örtüşmez).

- **4. Düzey — Nicel Yönetilen (*Level 4: Quantitatively Managed*):** **Süreç ve yazılım ölçütleri (metrikler)** kullanılarak kalite yönetimine geçilir. Projedeki ilerleme metriklerle sürekli izlenir; bütçe, zaman ve kod/ürün kalitesi hedeflerinden sapma sinyalleri erkenden belirlenerek **o proje içinde gerekli düzeltici önlemler** alınır (ekrandan, 02:10:00).
- **5. Düzey — İyileştirilmiş (*Level 5: Optimized*):** 4. düzeyde proje içinde kullanılan metrik ve deneyimlerin, bir geri besleme döngüsüyle **sonraki projelerde de süreç yönetimini sürekli iyileştirmek üzere** kullanılmasıdır (ekrandan, 02:10:00).

CMMI firmalara *"şu adımı tek bir kalıpla şu şekilde yapacaksınız"* diye dayatmaz; firmanın kendi yöntemlerinin ilgili düzeyin süreç alanlarını karşılayıp karşılamadığını denetler.

### 8.2 CMMI Tarihçesi ve Türkiye'den Akredite Kurum Örnekleri

- **1987:** Modelin temelleri **CMM (*Capability Maturity Model*)** adıyla atılmıştır.
- **1998:** Süreç adımlarının birbiriyle tümleşik çalışması vurgulanarak model **CMMI (*Capability Maturity Model Integration*)** adını almıştır. Eskiden kurumların faaliyet alanına göre üç ayrı alt model bulunmaktaydı:
  1. **`CMMI-DEV` (*Development*):** Yazılım geliştirme süreçleri için.
  2. **`CMMI-SVC` (*Services*):** Hizmet sunumu ve yönetimi (ör. başka firmalara dış kaynak/*outsource* hizmeti veren firmalar) için.
  3. **`CMMI-ACQ` (*Acquisition*):** Ürün ve hizmet alımı (yoğun olarak alt yüklenicilere iş dağıtan firmaların bu alımları doğru yönettiğini kanıtlaması) için.
  Ayrıca yalnızca belirli süreç alanlarında kısmi olgunluğu gösteren ***Continuous*** ve tüm alanlarda bütüncül olgunluğu gösteren (daha değerli olan) ***Staged*** ayrımı vardı.
- **2010 (CMMI v1.3):** Çevik (*agile*) süreçler resmi olarak desteklenmeye başlanmış ve çevik ekiplerin CMMI Level 3 alabilmesinin yolu açılmıştır.
- **2018 (CMMI v2.0):** Büyük bir yeniden yapılanmayla `DEV`, `SVC`, `ACQ` ayrımı ve *Continuous / Staged* ayrımı kaldırılarak hepsi tek bir bütüncül model altında birleştirilmiştir.

Slaytta Türkiye'de **CMMI Level 3 ve üzeri** sertifika almış kamu ve özel sektör kurumlarından şu örnekler verilmiştir (güncel liste `https://sas.cmmiinstitute.com/pars/pars.aspx` veya `/pars/` adresinden ülkeye ve düzeye göre sorgulanabilmektedir) (ekrandan, 02:20:00):
- **Level 5 Kurumlar:** **MilSoft** (askeri yazılım çözümleri), **TÜBİTAK BİLGEM Yazılım Teknolojileri Araştırma Enstitüsü (YTE)**, **Huawei Türkiye** *(hoca derste canlı sorgulama yaptığında MilSoft ve TÜBİTAK BİLGEM'in aktif Level 5 göründüğünü, Huawei Türkiye'nin ise o anki listede süresinin dolmuş/yenilenme aşamasında olabileceğini gözlemlemiştir)*.
- **Level 3 Kurumlar:** **ASELSAN**, **Cybersoft** (finans ve kurumsal yazılımlar), **Havelsan** (hava elektroniği ve gömülü/kontrol yazılımları), **Koç Sistem**, **Etiya**, **ICTerra**, **OBSS (*Open Source Business Software Solutions*)** (açık kaynak yazılım çözümleri üzerinden gelir elde eden model örneği), ayrıca canlı sorguda görülen **Akınsoft / Akın Robotics (Akın Computer)**, **Altay Yazılım**, **Başarsoft**, **BİTES** vb. (ekrandan, 02:20:00).

### 8.3 CMMI Düzeylerinde CASE Araçlarının Kullanımı

CMMI akreditasyonu için CASE araçlarını kullanmak zorunlu olmasa da, CASE araçları CMMI süreç alanlarını doğrudan destekler. Her bir CMMI olgunluk düzeyinin CASE araçları açısından karşılığı şöyledir (ekrandan, 02:30:00):

- **Düzey 1 (Başlangıç düzeyi):** CASE araçları yazılım ölçütlerinin hesaplanmasına destek sağlasa da bu destek kullanılmaz veya araçlar firma genelinde tutarlı ve aynı olgunlukta kullanılmaz; yazılımın yeniden kullanımı (*reuse*) yoktur veya çok azdır.
- **Düzey 2 (Tekrarlanabilir düzey):** CASE araçlarının kullanımına yönelik kurum içi standartlar tanımlanmıştır ve çalışanlar bu araçlar konusunda eğitimli ve uygulamalı deneyime (*hands-on experience*) sahiptir. CASE gereçleri iş atama ve proje izleme yazılımlarıyla tümleşiktir; yeniden kullanım bir miktar iyileşmiştir.
- **Düzey 3 (Tanımlanmış düzey) (ekrandan, 02:30:00):**
  - Yazılım araçlarının erişebildiği, organizasyona ait merkezi **veri deposu (*repository*)** oluşturulmuştur.
  - **Ortak tekrar kullanım kütüphanesi** oluşturulmuştur ve yeniden kullanım hedeflerine önemli ölçüde ulaşılmıştır.
  - Organizasyon standartlarına bağlı olarak **yazılım ölçütleri (metrikler)** toplanmaktadır.
  - Ölçütler, eğilimler ve profillerin belirlenmesi gibi işlemlerde kullanılmak üzere organizasyona ait veritabanında saklanmaktadır.
- **Düzey 4 (Yönetilebilir düzey):** Yazılım ölçütlerinin analizi ile süreç gelişimi oluşturulmuştur (ekrandan, 02:30:00).
- **Düzey 5 (Optimize edilmiş düzey):** Yeni çıkan yazılım araçları, mimariler ve modeller dahil olmak üzere tüm gereçler, teknikler ve proje yönetim süreçleri incelenip değerlendirilmekte ve sürekli iyileştirmeye tabi tutulmaktadır (ekrandan, 02:30:00).

> **Ders sonrası not:** Slaytta (Slayt 49) Düzey 4 için *"Yazılım ölçütlerinin niteliksel analizi ile süreç gelişimi oluşturulmuştur"* yazmakta ve hoca da slaytı okurken *"niteliksel"* ifadesini kullanmaktadır (ekrandan, 02:30:00); ancak Slayt 45'te (ekrandan, 02:10:00) belirtildiği üzere CMMI 4. Düzey **Nicel Yönetilen (*Quantitatively Managed*)** düzeydir ve metriklerin istatistiksel/**nicel (*quantitative*)** analizine dayanır.

## 9. Gereksinim Mühendisliğine Giriş, SRS Standartları ve Yapıt (Artifact) Kavramı

Yazılım geliştirme süreç modelleri tamamlandıktan sonra, dersin son bölümünde yazılım yaşam döngüsünün ilk ana mühendislik etkinliği olan **Gereksinim Mühendisliğine (*Requirements Engineering*)** giriş yapılmıştır.

### 9.1 Gereksinim Mühendisliğinin Amacı ve Fizibilite (Yapılabilirlik) Çalışması

**Gereksinim mühendisliği**, üzerinde çalışmaya başlanacak olan projenin **amaçlarını, boyutlarını ve etkilerini** belirlemeye yönelik çalışmalar bütünüdür. Hatta bu çalışmalar tamamlandığında projeye **hiç başlamama** kararı da çıkabilir; çünkü gereksinim mühendisliği **yapılabilirlik (*feasibility* — fizibilite)** çalışmasına en temel girdiyi sağlar:
- Bu proje bize hangi maliyet kalemlerini doğuracak?
- Projenin yapılabilirliğini engelleyen veya uyulması gereken kanun, yönetmelik ve yasal yükümlülükler var mı?
- Gerekli insan kaynağı, teknik deneyim ve yazılım lisansları elimizde mevcut mu; yoksa kiralama, eğitim, danışmanlık veya dış kaynak (*outsourcing*) ile mi karşılanacak?
- Proje ne kadar sürecek ve ticari bir kurum olan yazılım evi bu projeden ne kadar sürede kâra geçebilecek?

Gereksinim mühendisliği yapılmadan fizibilite çalışması yapılamaz. Ayrıca ilk derste müşteri yanılgılarında görüldüğü üzere müşterinin kafasında başlangıçta yalnızca kaba bir fikir vardır; ayrıntılar belirsiz ve yoruma açıktır (*"şeytan ayrıntıda gizlidir"*).

> **Hocanın vurgusu:** Yanlış veya eksik işi yapan "mükemmel" bir yazılım diye bir şey yoktur; bu bir oksimorondur (çelişkidir). Bir yazılım ne kadar hızlı çalışırsa çalışsın, arayüzü ne kadar kolay olursa olsun, müşterinin istediği işi yanlış veya eksik yapıyorsa hiçbir işe yaramaz. Bize gereken **"eksik işi yapan mükemmel çözüm" değil, "doğru işi yapan iyi çözümdür"**.

### 9.2 SRS (Software Requirements Specification) Belgesi ve Uluslararası Standartlar

Gereksinim mühendisliği çalışmalarının sonunda ortaya çıkan resmi teknik belgeye **SRS (*Software Requirements Specification* — Yazılım Gereksinimler Belgesi)** adı verilir (Türkçe kısaltması olan YGB sektörde pek kullanılmaz, özgün kısaltması olan **SRS** kullanılır) (ekrandan, 02:40:00).

SRS raporunun nasıl hazırlanacağına ve gereksinim mühendisliği süreçlerine yönelik başlıca iki uluslararası standart şunlardır (ekrandan, 02:40:00):

1. **`IEEE 830-1998`:** Doğrudan **SRS odaklı** standarttır (`IEEE` standardı yayımlayan kurumu, `830` standart numarasını, `1998` ise yayımlandığı yılı gösterir) (ekrandan, 02:40:00).
2. **`ISO/IEC/IEEE 29148:2011`:** *Systems and Software Engineering – Life Cycle Processes – Requirements Engineering* (Sistem ve yazılım mühendisliği yaşam döngüsü süreçleri kapsamında gereksinim mühendisliği standardı; kırılımlarıyla birlikte bir standartlar ailesidir) (ekrandan, 02:40:00).

Özellikle küçük ölçekli bir yazılım evi bu standartların tamamına harfiyen uymak zorunda değildir (çünkü standartları öğrenmek ve uygulamak ek maliyet getirir); bunun yerine **en çok zorlandığı, ayağının en çok takıldığı ve en çok hata yaptığı süreç alanına** yönelik standardı önceliklendirerek uygulamalıdır.

### 9.3 Yapıt (Artifact / Artefact) Kavramı

SRS belgesi içinde çeşitli metinler, tablolar ve şemalar yer alır. Slaytta yazılım mühendisliğinin en temel terimlerinden biri olan **yapıt (*artifact / artefact*)** şöyle tanımlanmıştır (ekrandan, 02:40:00):

- **Artifact (*Artefact* / Yapıt):** Yazılım geliştirme sırasında **kod dışında ortaya çıkardığımız her türlü metin ve şemaya "artefact"** denilmektedir (ekrandan, 02:40:00).

Uygulamanın kendi çalışması için gereken yapılandırma dosyaları kodun bir parçası sayılsa bile, kaynak kodu belirli bir hedef platform için derleme ve bağlama (*build & link*) işlemlerini yöneten bir derleme yöneticisinin (*build manager*) XML yapılandırma dosyaları bile birer *artifact* olarak değerlendirilebilir. Bu dersin gereksinim mühendisliği ve analiz bölümlerinde SRS belgesinde yer alabilecek en yaygın *artifact* türleri üzerinde çalışılacaktır (ekrandan, 02:40:00).

## Dersin Toparlaması

Bu derste ilk olarak klasik yinelemeli süreç modelleri olan **Sarmal Model (*Spiral Model*)** ve **Kazan-Kazan Modeli (*Win-Win Model*)** incelenmiş; sarmal modelin sürekli risk analizi (teknik, mali, politik riskler) yaklaşımı ile kazan-kazan modelinin farklı paydaşların (*stakeholders*) çelişen önceliklerini uzlaştırma felsefesi ele alınmıştır. Ardından değişen gereksinimlere esneklik sağlayan **Çevik (*Agile*) Süreçler** ailesine geçilerek Çevik Manifesto'nun dört öncelik ilkesi, çevik ekibin kendi kendini düzenleme (*self-organization*) özellikleri ve çevik süreçlerin büyük ölçekli veya ağır dış denetime tabi projelerdeki sınırları tartışılmıştır. Çevik süreçlerin iki ana örneği olarak **Aşırı Programlama (XP)** (kullanıcı öyküleri, KISS ilkesi, `Satış` sınıfı örneği üzerinden CRC kartları, *spike solution*, test güdümlü geliştirme [TDD] ve tüplü dalış *buddy* benzetmesiyle eşli programlama [*pair programming*]) ile **Scrum** (Görev Listesi, 1–4 haftalık Koşu, günlük 15 dakikalık 3 sorulu toplantı, İşlev Gösterimi ve *Pre/Post-Scrum*) ayrıntılı biçimde karşılaştırılmıştır.

Dersin üçüncü bölümünde büyük yazılım ihalelerinde ön şart olan **süreç sertifikasyonu** modelleri (**CMMI**, **PMI**, **ISO 9001:2015** ve yazılıma özel **ISO/IEC 90003:2018**) tanıtılmış; CMMI modelinin 0'dan 5'e kadar olan olgunluk düzeyleri, Düzey 3 (*Defined*) eşiğinin önemi ve çevik süreçlerle uyumu, CMMI v2.0 dönüşümü, Türkiye'deki CMMI Level 3 ve Level 5 kurumlar ile CASE araçlarının CMMI düzeylerindeki yeri açıklanmıştır. Son olarak **Gereksinim Mühendisliğine** giriş yapılarak fizibilite ilişkisi, **SRS (*Software Requirements Specification*)** belgesi standartları (**`IEEE 830-1998`** ve **`ISO/IEC/IEEE 29148:2011`**) ve kod dışındaki her türlü metin/şemayı ifade eden **yapıt (*artifact*)** kavramı tanımlanmıştır. Bir sonraki derste gereksinim mühendisliğinin yedi genel adımından devam edilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
