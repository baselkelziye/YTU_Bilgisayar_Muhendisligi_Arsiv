# Ders 11 Çalışma Özeti

## Genel Konular

- Yazılım Proje Yönetimine Giriş, Odak Alanları ve Planlama İlkeleri
  - Yazılım projelerinin başarısızlık nedenleri (*yazılım geliştirmedeki zorluklar, yazılım/kişi ölçeği büyüklüğü, kestirim zorlukları, insanlarla çalışma zorlukları, teknoloji/gereksinim/kurum içi politik/mali değişimler*) ve proje yönetiminin önem sırasına göre dört ilgi alanı: **1) Kişiler (*People*)**, **2) Ürün (*Product*)**, **3) Süreç (*Process*)**, **4) Proje (*Project*)** (ekrandan, 00:06:30).
  - Yazılım proje yönetiminin **yazılım mühendisliği**, **genel mühendislik proje yönetimi** ve **idari yönetim bilimi** olmak üzere üç disiplinin kesişiminde yer alması; projelerin insan kaynağı ve süreye göre **çok küçük** (1–2 kişi, 1–2 ay), **küçük** (2–3 kişi, 2–3 ay), **orta** (4–6 ay) ve **büyük** (5–20+ kişi, 1,5–3 yıl) ölçekli olarak ayrılması.
  - Planlamada üç temel yaklaşım (**Geleneksel / ayrıntılı yol haritası yaklaşımı**, **Basitlik yaklaşımı**, **Çevik / dengeli yaklaşım**) ve temel planlama ilkeleri: *projenin sınırlarını belirleme (Charles Babbage'ın Analitik Makinesi örneği), müşteriyi planlamaya katma (öncelik, sınır ve zamanlamayı müşterinin belirlemesi, gerçekçiliği korumak için yazılım ekibinin pazarlık yapması), planın yinelemeli doğası ("plan asla taşa yazılmaz"), plan ölçeği ile vadesinin ters orantılı olması (kısa vadede ayrıntılı, uzun vadede genel plan), yazılımcının "süpermen veya robot" olmadığını gözetme (%10–15 esneme sınırı), kalite güvence ve risk değerlendirmesini plana ekleme* (ekrandan, 00:20:00).
- Proje Yönetiminde Kişi Etkenleri, Takım Yapıları ve Haberleşme
  - **Takım Yöneticisi vs. Proje Yöneticisi Modelleri:** Takım yöneticisinin aynı zamanda proje yöneticisi olduğu tekli model ile teknik olmayan ancak idari yetkinliği yüksek bir proje yöneticisinin aynı anda 2–4 projede takvim sapmalarını ve riskleri izlediği ikili model; iyi bir teknik yöneticinin özellikleri (*motivasyon, süreç/ekip uyarlama, yaratıcılığı teşvik, teşhis ve alternatif plan kurabilen sorun çözücülük, sorumluluk alma*) ve takım ruhunu bozan etkenler (*telaşlı iş ortamı, sık başarısızlık/suçlama, hep aynı başarılı ekibe en zor işlerin yüklenmesi, belirsiz rol ve yetkiler*).
  - **Dört Temel Takım Yapılanması (ekrandan, 01:00:00; ekrandan, 01:06:00):**
    1. **Kapalı Yaklaşım:** Geleneksel yetki hiyerarşisi ve kontrol mekanizmaları; geçmiş deneyimlere benzer projelerde ve şelale modelinde başarılıdır, ancak yaratıcı fikirler ve yeni problem alanları için uygun değildir (ekrandan, 01:00:00).
    2. **Rastgele (*Random* / Serbest) Yaklaşım:** Takım üyelerinin bireysel ve teknik yeteneklerine göre kendi aralarında yapı kurması; Ar-Ge ve yaratıcı fikirler için en uygun yaklaşımdır ancak disiplin sağlamak zordur (ekrandan, 01:00:00).
    3. **Açık Yaklaşım:** Kapalı ve rastgele yaklaşım arasında, kontrol mekanizmaları bulunan ancak yapılanması serbest demokratik yapı; karmaşık sorunların çözümü için uygundur ancak ortak karar alma tartışmaları nedeniyle etkinliği (*efficiency*) sağlamak zor olabilir (ekrandan, 01:00:00).
    4. **Eşzamanlı (*Synchronous*) Yaklaşım:** Problemin bağımsız alt parçalara ayrılabildiği durumlarda (*RAD* benzeri) alt takımların kendi içlerinde yoğun, birbirleriyle az etkileşimle paralel çalışması (ekrandan, 01:06:00).
  - **Haberleşme Yolları:** **Resmi (*Formal*) yollar** (yazılı, zamanlı mesajlaşma, kurallı ve gündemi/zamanı önceden belirlenmiş toplantılar) ve **Gayri resmi (*Informal*) yollar** (sözlü iletişim, kişisel etkileşimler, gün içinde gerektikçe) (ekrandan, 01:06:00).
- Proje ve Süreç Ölçümleri, Kalite Etkenleri ve Maliyet Tahmin Yöntemleri
  - **Proje Ölçümü** (teknik odak, iç kalite) vs. **Süreç Ölçümü** (yönetimsel odak, dış kalite ve sürecin iyileştirilmesi); ölçütlerin gizlilik düzeyleri, tehdit veya tek başına ödül aracı yapılmaması, **GQM (*Goal–Question–Metric*)** yaklaşımı ve **Hata Giderme Etkinliği ($\text{HGE}$)** formülü (ekrandan, 01:30:00):
    $$\text{HGE} = \frac{\text{TÖ}}{\text{TÖ} + \text{TS}} \qquad \text{veya ardışıl adımlarda} \qquad \text{HGE}_i = \frac{A_i}{A_i + A_{i+1}}$$
  - **Maliyet Tahmin Yöntemleri (ekrandan, 01:45:30; ekrandan, 01:50:00; ekrandan, 02:10:00; ekrandan, 02:15:00; ekrandan, 02:20:00):**
    1. **Bilirkişi Takdiri (*Expert Judgment*):** Geçmiş projelerin maliyet ve süreleriyle karşılaştırma.
    2. **Delphi Yöntemi:** Koordinatör yönetiminde bilirkişilerin birbirinden habersiz yazılı tahmin vermesi, ortanca ve aykırı (*outlier*) değerlerin paylaşılıp ortak değere yakınsayana dek yinelenmesi (ekrandan, 01:45:30).
    3. **Analiz Yöntemi (Aşağıdan Yukarıya / *Bottom-Up*):** Ürün analiz kartıyla alt öğelerin giderlerinin takdir edilip toplanması ve üç noktalı ağırlıklı ortalama formülü: $E = \frac{a + 4m + b}{6}$ (ekrandan, 01:50:00).
    4. **İstatistiksel Modeller ($y = a \cdot x^b$):** **Walston-Felix Modeli** (60 proje üzerinden $H, T, I, B$ formülleri), **COCOMO (*Constructive Cost Model*)** (Boehm'in 63 proje üzerinden *Uygulama, Yardımcı, Sistem* yazılımları için Temel/Orta/İleri COCOMO formülleri) ve **PNR (*Putnam-Norden-Rayleigh*) Modeli** ($H = \text{KLOC}^3 / (C_k^3 t^4)$) (ekrandan, 02:10:00; ekrandan, 02:15:00; ekrandan, 02:20:00).
- İleri Sınama Konuları: Kodu Kim Sınar, Tümleştirme/Geçerleme/Sistem Sınamaları ve Resmi Gözden Geçirme (IEEE 1028)
  - **Sınama Amaçlı Yapılanma:** Bir bileşenin önce onu en iyi bilen **yazarı (programcısı)** tarafından (*white-box*), ardından psikolojik sahiplenme (*"kuzguna yavrusu şahin görünür"*) ve sınamanın **"yıkıcı" (*destructive*)** doğası gereği **bağımsız bir sınama ekibi (*ITG — Independent Test Group*)** veya çapraz rotasyonla ($A \to B \to C \to D \to A$) başka geliştiriciler ve son olarak müşteriler tarafından sınanması (ekrandan, 02:35:00).
  - **Tümleştirme Sınamaları:** **Tahribat Sınaması (*Smoke testing*)** (*showstopper* / sistemi kilitleyen hataları yakalama; Windows 95 lansmanı PS/2 mavi ekran örneği) ve **Gerileme Sınaması (*Regression testing*)**.
  - **Geçerleme (*Validation*) Sınamaları:** **Alfa Sınaması** (yazılım evinde, simüle edilen ortamda kullanıcı tarafından, *gayri resmi/anlık* bildirimle) ve **Beta Sınaması** (müşterinin kendi gerçek ortamında, paralel çalışmayla, *resmi/form tabanlı* bildirimle).
  - **Sistem Sınamaları:** **Kurtarma sınaması (*Recovery testing* — $\text{MTTR}: \text{Mean Time to Repair}$)**, **Güvenlik sınaması** (EFT ve eliptik eğri şifrelemesinin işlem süresinden uzun dayanması örneği), **Zorlama sınaması (*Stress testing*)** ve **Başarım sınaması (*Performance testing*)**.
  - **Resmi Yazılım Gözden Geçirme (*Formal Software Review* — IEEE 1028):** Kodlama öncesinde de uygulanabilen 7 adımlı inceleme süreci (*Değerlendirme başlangıcı, Yönetimin hazırlanması, Prosedürlere genel bakış, Bireysel hazırlık, Grup incelemesi, Düzenleme, Sonlandırma*) (ekrandan, 03:05:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Proje Yönetiminde Birinci Önceliğin "Kişiler (İnsan Faktörü)" Olması ve Ölçütlerin Kötüye Kullanılmaması
  - Teknoloji, bütçe ve süreç ne kadar iyi olursa olsun, kişiler doğru yönlendirilip motive edilemez ve takım ruhu korunamazsa proje `%100` başarısızlığa uğrar; bu nedenle proje yönetiminin önem sıralamasında **Kişiler 1. sırada**, **Proje ise 4. (son) sırada** yer alır (ekrandan, 00:06:30).
  - Bireysel düzeyde toplanan kalite/hata ölçütleri (ör. kişi başına `Hata/KLOC`) yalnızca çalışanın kendisine ve takım liderine görünür olmalı, diğer ekip üyelerine kapalı tutulmalıdır. Bu ölçütler çalışanı **utandırmak, tehdit etmek veya tek başına ödül/prim kriteri yapmak** için kullanılmamalıdır; aksi hâlde çalışanlar müşteri için doğru ürünü üretmeyi bırakıp yalnızca o metriği manipüle etmeye odaklanırlar.
- Sınamanın Psikolojik Boyutu ("Yıkıcı" Eylem) ve Bağımsız Sınama
  - Programcılar yazdıkları kodu bir sanat eseri gibi sahiplenirler ve çıkarları kodun zamanında/hatasız bitmesini gerektirdiğinden kendi kodlarının *"hatalarını bulmaya değil, doğru çalıştığını ispatlamaya"* yönelik testler yazma eğilimindedirler. Oysa sınama psikolojik açıdan **"yıkıcı" (*destructive*)** bir eylemdir (*"bu kodda mutlaka bir hata var ve onu bulacağım"* yaklaşımı gerektirir). Bu yüzden her bileşen mutlaka yazarı dışındaki kişilerce de (*ITG* veya dairesel rotasyon: $A \to B \to C \to D \to A$) sınanmalıdır (ekrandan, 02:35:00).
  - Sınama ve hata ayıklama bir "angarya" olarak görülüp yalnızca stajyerlere veya acemi personele bırakılmamalıdır; bir işin doğru yapılıp yapılmadığını sınamak o işi yapmaktan bir kat daha zor olduğundan sınama ekibinde mutlaka deneyimli personel yer almalıdır.
- Alfa ve Beta Sınamaları Arasındaki Ortam ve İletişim Farkı
  - **Alfa sınaması**, **yazılım evinin kendi mekânında** yapay olarak simüle edilmiş bir ortamda müşteri temsilcisi tarafından yapılır ve bulunan hatalar aynı odadaki geliştiricilere **gayri resmi (*informal*) ve sözlü/anlık** olarak bildirilir. **Beta sınaması** ise **müşterinin kendi gerçek çalışma ortamında** yürütülür ve bulunan hatalar ekran görüntüleri ve adım adım tekrarlama bilgileriyle **resmi (*formal*) hata bildirim formları** üzerinden iletilir.

## Kısa Tekrar Notları

- **Proje Yönetimi İlgi Alanları Sırası (ekrandan, 00:06:30):** `1. Kişiler` $\rightarrow$ `2. Ürün` $\rightarrow$ `3. Süreç` $\rightarrow$ `4. Proje`.
- **Plan Ölçeği – Vade İlişkisi:** Planın ayrıntı ölçeği ile planın vadesi **ters orantılı** olmalıdır (yakın vade ayrıntılı, uzak vade genel hatlarıyla planlanır).
- **Hata Giderme Etkinliği ($\text{HGE}$) (ekrandan, 01:30:00):**
  $$\text{HGE} = \frac{\text{TÖ}}{\text{TÖ} + \text{TS}}, \qquad \text{Ardışıl fazlar için: } \text{HGE}_i = \frac{A_i}{A_i + A_{i+1}}$$
  ($\text{TÖ}$: teslimden önce bulunan hata sayısı, $\text{TS}$: teslimden sonra [bakım aşamasında] bulunan hata sayısı, $A_i$: $i$. aşamada bulunan hata sayısı, $A_{i+1}$: bir sonraki aşamada bulunan $i$. aşama kaynaklı hata sayısı).
- **GQM (*Goal–Question–Metric*):** `1. Goal (Hedef)` $\rightarrow$ `2. Question (Hedefe ulaşılıp ulaşılmadığını yoklayan soru)` $\rightarrow$ `3. Metric (Soruyu yanıtlayacak ölçüt)`.
- **Analiz Yöntemi Ağırlıklı Çaba Formülü (ekrandan, 01:50:00):** $E = \dfrac{a + 4m + b}{6}$ ($a$: en kötü/kötümser tahmin, $m$: en olası/ortalama tahmin, $b$: en iyimser tahmin).
- **Walston-Felix, COCOMO ve PNR Formülleri (ekrandan, 02:10:00; ekrandan, 02:15:00; ekrandan, 02:20:00):**
  - **Walston-Felix:** $H = 5{,}2 \cdot \text{KLOC}^{0{,}91}$, $\quad T = 4{,}1 \cdot \text{KLOC}^{0{,}36} = 2{,}47 \cdot H^{0{,}35}$, $\quad I = 0{,}54 \cdot H^{0{,}06}$, $\quad B = 49 \cdot \text{KLOC}^{1{,}01}$.
  - **Temel COCOMO:** $H = a \cdot \text{KLOC}^b$, $\quad T = c \cdot H^d$ (*Uygulama*: $a=2{,}4, b=1{,}05, c=2{,}5, d=0{,}38$; *Yardımcı*: $a=3{,}0, b=1{,}12, c=2{,}5, d=0{,}35$; *Sistem*: $a=3{,}6, b=1{,}20, c=2{,}5, d=0{,}32$). **Orta COCOMO:** Çaba düzeltme çarpanı (*EAF*: $0{,}90 - 1{,}40$) eklenir.
  - **PNR Modeli:** $H = \dfrac{\text{KLOC}^3}{C_k^3 \cdot t^4}$ ($C_k \in \{2000, 8000, 12000\}$ teknoloji katsayısı, $t$: yıl cinsinden süre).
- **IEEE 1028 Resmi Gözden Geçirme Adımları (ekrandan, 03:05:00):** `1. Değerlendirme başlangıcı` $\rightarrow$ `2. Yönetimin hazırlanması` $\rightarrow$ `3. Gözden geçirme prosedürlerine genel bakış` $\rightarrow$ `4. Bireysel hazırlık` $\rightarrow$ `5. Grup incelemesi` $\rightarrow$ `6. Düzenleme` $\rightarrow$ `7. Sonlandırma`.

## Detaylı Açıklamalar

### 1. Yazılım Proje Yönetimi İlkeleri, Kişi Etkenleri ve Takım Yapıları

Klasik süreçlerle yürütülen yazılım projelerinde başarı oranı yaklaşık `%50` iken çevik süreçlerde `%75–80` bandına çıkmaktadır. Proje yönetimi; yazılım geliştirmenin doğasından, ölçek büyüklüğünden (*yazılım ölçeği, kişi ölçeği*), kestirim (*estimation*) zorluklarından, insan dinamiklerinden ve teknoloji, gereksinim, kurum içi politika ile mali koşullardaki değişimlerden kaynaklanan zorlukları çözmeye odaklanır (ekrandan, 00:06:30).

**Planlama İlkeleri (Slayt 130) (ekrandan, 00:20:00):**
- **Projenin sınırlarını belirleyin:** Nereye gideceğinizi bilmezseniz kaybolursunuz (Charles Babbage 1800'lü yıllarda ilk programlanabilir bilgisayar tasarımını sürekli yeni özellikler ekleyip sınırlarını belirleyemediği için fiziksel olarak tamamlayamamıştır).
- **Müşteriyi planlama eylemlerine katın:** Öncelikleri, sınırları ve zamanlamayı müşteri belirler (bu sırada); ancak gerçekçiliği korumak amacıyla yazılım ekibi pazarlık yapar (aksi sırada) (ekrandan, 00:20:00).
- **Planlamanın doğası yinelemelidir:** Plan asla taşa yazılmaz; planın ölçeği ile vadesi ters orantılıdır (kısa vadeli planlar ayrıntılı, uzun vadeli planlar genel hatlarıyla yapılır).
- **Bildiklerinizi kullanarak kestirimlerde bulunun**, **planın her aşamasına risk değerlendirmesini (*teknik, mali, kişisel, politik*) ve kalite güvence eylemlerini ekleyin** ve **gerçekçi olun** (*"Yazılımcı süpermen veya robot değildir"* — çalışma kapasitesi en fazla `%10–15` esnetilebilir, `%30–50` artırılamaz) (ekrandan, 00:20:00).

**Takım Yapıları ve Haberleşme (Slayt 134–135) (ekrandan, 01:00:00; ekrandan, 01:06:00):**

| Takım Yapısı | Temel Özellikleri ve Karar Mekanizması | Uygun Olduğu Durumlar / Avantajı | Dezavantajı / Kısıtı |
| :--- | :--- | :--- | :--- |
| **Kapalı Yaklaşım** | Geleneksel yetki hiyerarşisi ve net kontrol mekanizmaları vardır. | Geçmiş deneyimlere benzer projelerde ve şelale modelinde başarılıdır; disiplin sorunu yoktur. | Yaratıcı fikirler ortaya çıkarmak ve yeni problem alanları için uygun değildir. |
| **Rastgele (*Random*) Yaklaşım** | Serbest yaklaşım; üyeler bireysel/teknik yeteneklerine göre kendi aralarında yapı kurar. | Yaratıcı fikirler üretmek ve Ar-Ge projeleri için en uygun yaklaşımdır. | Disiplin elde etmek zor olabilir. |
| **Açık Yaklaşım** | Kapalı ve rastgele arasında; kontrol mekanizmaları vardır ancak yapılanma serbesttir (demokratik yapı). | Karmaşık sorunların çözümü için uygundur. | Ortak karar alma tartışmaları uzayabileceğinden etkinliği (*efficiency*) sağlamak zor olabilir. |
| **Eşzamanlı (*Synchronous*) Yaklaşım** | Takım kendi içinde problemin bağımsız alt parçalarını paylaşır; alt takımlar arası etkileşim azdır. | Problemin paralel yürütülebilecek alt parçalara ayrılabildiği (*RAD* vb.) durumlar. | Her problem bağımsız alt parçalara bölünmeye uygun değildir. |

### 2. Süreç Ölçütleri ve Maliyet Tahmin Modelleri (Delphi, Analiz, Walston-Felix, COCOMO, PNR)

**Proje Yönetiminde Süreç Ölçütleri (Slayt 138) (ekrandan, 01:30:00):**
- **Hata Giderme Etkinliği ($\text{HGE}$):** Değişiklik maliyeti yaşam döngüsü ilerledikçe üstel arttığından hataların müşteriye teslimden önce (veya hatanın doğduğu aşamada) yakalanma oranını ölçer:
  $$\text{HGE} = \frac{\text{TÖ}}{\text{TÖ} + \text{TS}}, \qquad \text{HGE}_i = \frac{A(i)}{A(i) + A(i+1)}$$
  Örneğin çözümleme aşamasının hata giderme etkinliği için $A(i)$ çözümlemede bulunan hata sayısı, $A(i+1)$ ise tasarımda bulunan çözümleme kaynaklı hata sayısıdır (ekrandan, 01:30:00).
- Diğer süreç ölçütleri: **Doğruluk** (bulunan hata sayısının `LOC`/`FP` proje boyutuna oranı), **Bakım kolaylığı** (bir hatanın bulunması ile giderilmesi arasında geçen zaman), **Güvenlik** (bulunan güvenlik açıkları ve ciddilik düzeyleri) (ekrandan, 01:30:00).

**Maliyet Tahmin Yöntemleri:**
- Gereksinim mühendisliği tamamlandıktan hemen sonra projenin kaç adam-ay çaba ve kaç ay süre gerektireceğini tahmin etmek, projenin yapılabilirliğini ve ihale/pazar kârlılığını görmek için zorunludur.
  - **Ders sonrası not:** Hoca maliyet tahmininin önemini anlatırken `240 adam-ay` çaba gerektiren bir projede 3 kişiyle $240 / 3 = 80\text{ ay}$ süreceğini belirttikten sonra, *"hedefimiz 3 ay olacaksa 240'ı kaça böldüğümüzde 3 çıkar, ancak 8'e böldüğümüzde 3 çıkar"* demiştir (01:39:25); $240 / 8 = 30\text{ ay}$ (veya $240 / 3\text{ ay} = 80\text{ kişi}$, ya da $24\text{ adam-ay} / 8\text{ kişi} = 3\text{ ay}$) olduğundan burada sözlü anlatımda bir sıfır/bölme sürçmesi olmuştur.
1. **Bilirkişi Takdiri ve Delphi Yöntemi (Slayt 142) (ekrandan, 01:45:30):**
   - Delphi yönteminde koordinatör bilirkişilere *"sistemi tanımlama"* belgelerini ve birer *"tahmin formu"* verir. Bilirkişiler birbirinden habersiz, nedenleri ile birlikte tahminlerini yazılı olarak koordinatöre bildirir (ör. `30`, `50`, `60`, `90` adam-ay). Koordinatör ortanca (`50–60`) ve aykırı (`30` ve `90`) tahmin sonuçlarını bilirkişilere vererek yeni tahminde bulunmalarını ister; ortak bir değere yaklaşıncaya kadar bu işlem yinelenir (ekrandan, 01:45:30).
2. **Analiz Yöntemi (Slayt 144) (ekrandan, 01:50:00):**
   - Ürün analiz kartı ile alt basamaktaki öğelerin giderleri `LOC`/`FP` ve $(\text{kişi} \times \text{ay})$ ölçülerine dayanarak takdir edilir ve aşağıdan yukarıya doğru toplamları alınır. Birden fazla tahmin varsa her gider kalemi için beklenen çaba ($E$) ağırlıklı ortalama ile hesaplanır (ekrandan, 01:50:00):
     $$E = \frac{a + 4m + b}{6}$$
     ($a$: en kötü tahmin, $m$: en olası tahmin, $b$: en iyimser tahmin).
3. **İstatistiksel Modeller ($y = f(x) = a \cdot x^b$):**
   - **Walston-Felix Modeli (Slayt 146) (ekrandan, 02:10:00):** `4000–467000` satır kodlu `60` yazılım projesi sonuçlarına dayanarak kurulan fonksiyonlar:
     $$\text{İş hacmi (adam-ay): } H = 5{,}2 \cdot \text{KLOC}^{0{,}91}$$
     $$\text{Proje süresi (ay): } T = 4{,}1 \cdot \text{KLOC}^{0{,}36} \quad \text{veya} \quad T = 2{,}47 \cdot H^{0{,}35}$$
     $$\text{İşgücü talebi (kişi): } I = 0{,}54 \cdot H^{0{,}06}, \qquad \text{Belge hacmi (sayfa): } B = 49 \cdot \text{KLOC}^{1{,}01}$$
   - **COCOMO (*Constructive Cost Model* — Slayt 148) (ekrandan, 02:15:00):** Barry Boehm'in `63` yazılım projesinin sonuç değerlerine dayanarak ve Delphi yöntemini uygulayarak saptadığı modeldir. **Temel COCOMO**'da $H = a \cdot \text{KLOC}^b$ ve $T = c \cdot H^d$ formülleri ürün çeşidine göre şu katsayıları alır (ekrandan, 02:15:00):
     - **Uygulama programı için:** $H = 2{,}4 \cdot \text{KLOC}^{1{,}05}$, $\quad T = 2{,}5 \cdot H^{0{,}38}$
     - **Yardımcı programlar için:** $H = 3{,}0 \cdot \text{KLOC}^{1{,}12}$, $\quad T = 2{,}5 \cdot H^{0{,}35}$
     - **Sistem yazılımları için:** $H = 3{,}6 \cdot \text{KLOC}^{1{,}20}$, $\quad T = 2{,}5 \cdot H^{0{,}32}$
     - **Orta COCOMO:** Temel formüle $0{,}90$ ile $1{,}40$ arasında değişen **Çaba Düzeltme Çarpanı (*EAF — Effort Adjustment Factor*)** ekler. **İleri COCOMO:** Yazılım geliştirme sürecinin her alt aşaması için ayrı fonksiyonlar kullanır.
   - **PNR (*Putnam-Norden-Rayleigh*) Modeli (Slayt 150) (ekrandan, 02:20:00):** Yıllık iş hacmi ($H$, yılda işgücü); bin kod sayısı ($\text{KLOC}$), teknoloji katsayısı ($C_k$) ve yıl olarak geliştirme sürecine ($t$) bağlıdır (ekrandan, 02:20:00):
     $$H = \frac{\text{KLOC}^3}{C_k^3 \cdot t^4}$$
     Burada $C_k$ teknoloji katsayısı; düşük teknoloji ortamında `2000`, iyi teknoloji ortamında `8000`, otomatik/tümleşik yazılım araçlarının kullanıldığı ortamda (ör. modelden koda çift yönlü dönüşüm, otomatik sınama ve *Jira* gibi iş kalemi izleme [*work item tracking*] araçlarıyla tümleşik çalışan *IBM Rational Application Developer* veya *Microsoft Team System / TFS / Azure DevOps* ekosistemlerinde) `12000` alınır. PNR modeli, işgücü ihtiyacının zamana ($t$) göre Rayleigh/normal dağılıma benzer sağa çarpık bir eğri izlediğini kabul eder (ekrandan, 02:20:00).

### 3. Sınama Amaçlı Yapılanma, Sınama Basamakları ve Resmi Gözden Geçirme (IEEE 1028)

1. **Sınama Amaçlı Yapılanma (Slayt 162) (ekrandan, 02:35:00):**
   - Bir bileşen ilk olarak onu en iyi bilen **hazırlayan programcı** tarafından (*white-box*) sınanır.
   - Ancak psikolojik açıdan sınama **"yıkıcı"** bir eylem olduğundan ve geliştiriciler kendi programlarının hatalarını bulmaya değil doğru çalıştığını ispatlamaya eğilim gösterdiğinden, her bileşen **yazarı dışındaki kişilerce** de sınanır: Yazılım evinin **bağımsız bir sınama ekibi (*ITG: Independent Test Group*)** bulunabilir; aksi hâlde farklı ekipler veya aynı projenin üyeleri dairesel rotasyonla ($A \to B \to C \to D \to A$) birbirlerinin kodlarını sınar (ekrandan, 02:35:00).
   - **Kod Kapsama Alanı (*Code Coverage*):** `%100` kod kapsamasına ulaşmak projenin kendisi kadar maliyetli olduğundan pratik değildir; ancak teknik riski yüksek projelerde hedef kapsama oranı (ör. `%70`'ten `%80`'e) yükseltilir.
2. **Tümleştirme, Geçerleme ve Sistem Sınamaları:**
   - **Tümleştirme Sınamaları:** **Tahribat sınaması (*Smoke testing*)**, tüm yazılım ve donanım elemanları birleştirildiğinde sistemi tamamen durduran (*showstopper*) hataları yakalamak için diğer tümleştirme testlerinden önce yapılır. **Gerileme sınaması (*Regression testing*)** ise yeni işlev veya hata düzeltmesi sonrasında yan etkileri yakalamak için testlerin tekrarlanmasıdır.
   - **Geçerleme Sınamaları (*Validation* — Son Kullanıcı):** **Alfa sınaması** yazılım evinde simüle edilen ortamda gayri resmi/anlık iletişimle; **Beta sınaması** müşterinin gerçek ortamında resmi hata bildirim formlarıyla yürütülür.
   - **Sistem Sınamaları:** **Kurtarma sınaması (*Recovery testing* — $\text{MTTR}$)**, **Güvenlik sınaması** (şifrelemenin işlem geçerlilik süresinden uzun dayanması), **Zorlama sınaması (*Stress testing*)** ve **Başarım sınaması (*Performance testing*)**.
3. **Resmi Yazılım Gözden Geçirme Çalışmaları (IEEE 1028 Standardı — Slayt 174) (ekrandan, 03:05:00):**
   - Kodlama öncesinde (gereksinim/SRS, çözümleme ve tasarım belgeleri üzerinde) uygulanabilen ve koda dayalı sınamalara göre hata başına çok daha az çaba gerektiren resmi inceleme toplantısı süreci 7 adımdan oluşur (ekrandan, 03:05:00):
     1. **Değerlendirme başlangıcı:** Değerlendirme yöneticisi standart bir *checklist* kullanarak verimli bir toplantı için gerekli koşulları sağlar.
     2. **Yönetimin hazırlanması:** Sorumlu yönetim gözden geçirme için gerekli kaynakları (belgeler, salon vb.) hazırlar ve toplantının standartlara uygun yürütülmesini sağlar.
     3. **Gözden geçirme prosedürlerine genel bakış:** Değerlendirme yöneticisi tüm değerlendiricilerin gözden geçirmenin amaçlarını ve prosedürlerini anladığından (eğitim aldığından) emin olur.
     4. **Bireysel hazırlık:** Değerlendiriciler birbirinden bağımsız olarak inceleme toplantısına hazırlanır ve malzemede hataya yol açabilecek olası bozuklukları (*anomaly* — ör. *use case* metni ile şema veya alan modeli arasındaki uyumsuzlukları) arar.
     5. **Grup incelemesi:** Bireysel hazırlıkların sonuçları önceden belirlenen yer ve zamandaki toplantıda bir araya getirilir, tartışılır ve sonuç raporu üzerinde uzlaşıya varılır.
     6. **Düzenleme:** İncelenen çalışmanın yazar(lar)ı veya atanacak bir başka kişi/ekip, önceki adımda belirlenen noktaları düzeltir.
     7. **Sonlandırma:** Değerlendirme yöneticisi düzeltmelerin yeterliliğini inceler ve onaylar (ekrandan, 03:05:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
