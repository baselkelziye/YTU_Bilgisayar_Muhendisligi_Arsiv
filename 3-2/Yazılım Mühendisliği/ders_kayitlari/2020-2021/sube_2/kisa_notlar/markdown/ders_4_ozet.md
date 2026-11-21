# Ders 4 Çalışma Özeti

## Genel Konular

- Akademik Veritabanlarına ve Standartlara Uzaktan Erişim (VETİS ve IEEE Xplore)
  - Üniversite kütüphanesi üzerinden **VETİS** (Kampüs Dışı Erişim Sistemi) aracılığıyla **IEEE Xplore Digital Library** gibi akademik veritabanlarına ve standartlara (ör. **IEEE Std 830-1998** — *IEEE Recommended Practice for Software Requirements Specifications*) erişim sağlanması; standartların olgunlaşma ve revizyon döngüsü (1993 sürümünden 1998 revizyonuna geçiş) ve kurumsal abonelikle indirilen kaynakların kurum dışı kişilerle paylaşılmaması yönündeki mesleki etik kuralı.
- Gereksinim Mühendisliği (*Requirements Engineering*) Süreci ve 7 Adımı
  - Gereksinim mühendisliğinin kendi içinde ardışık (şelale benzeri) veya problem alanı yeniyse artımsal/yinelemeli (*agile*) yürütülebilen **7 adımlı** bir süreç olması (ekrandan, 00:18:10):
    1. **Başlangıç (*Inception*):** Yazılım projesinin ilk aşamalarının başlatılıp başlatılmamasına karar verilmesi; projenin müşteri kaynaklı (yeni iş gereksinimi, mevcut süreçlerdeki güçlükler/verimsizlikler) veya yazılım şirketi kaynaklı (yeni pazar/hizmet farkındalığı, pilot uygulama ortaklığı) doğması ve **paydaşların (*stakeholders*)**, bakış açılarının ve kazanma durumlarının belirlenmesi (ekrandan, 00:18:10).
    2. **Bilgi Toplama (*Elicitation*):** Belirlenen paydaşların etkin katılımıyla gereksinimlerin toplanması; yüz yüze toplantılarda ön hazırlık, esnek gündem (beyin fırtınasını [*brainstorming*] engellemeyecek ama konuyu da dağıtmayacak denge) ve tıkanıklıkları çözecek oturum başkanı (*Robert's Rules of Order* ilkeleri) kullanımı.
    3. **İşleme (*Elaboration*):** Toplanan ham verilerin işlenerek bilgiye dönüştürülmesi, kullanıcı-yazılım etkileşimlerinin *storyboarding* (hikâye tahtası / ekran akış taslakları) ve kullanım senaryolarıyla modellenmesi, gereksiz ayrıntıların özetlenmesi ve eksik kalan noktaların genişletilmesi; gereksinimlerin **işlevsel (*functional*) / işlevsel olmayan (*non-functional*)** ve **normal / beklenen (*expected*) / heveslendirici (*exciting*)** olarak sınıflandırılması (ekrandan, 00:30:00).
    4. **Pazarlık (*Negotiation*):** Paydaşların birbiriyle çelişen gereksinimlerinin ve önceliklerinin, ayrıca yazılım evinin zaman, bütçe ve insan kaynağı kısıtlarının uzlaştırılması; tüm paydaşların razı olduğu gerçekçi bir gereksinim listesinin elde edilmesi.
    5. **Tanımlama (*Specification*):** Doğal konuşma dilinin belirsizliğinden uzaklaşmak amacıyla gereksinimlerin standart metinler, **kullanım öyküleri (*use case narratives*)**, **UML kullanım şemaları (*use case diagrams*)**, *storyboard*/prototipler ve görev kritik (*mission-critical*) sistemlerde **formel (matematiksel) modeller** (ör. **Z dili**) ile belgelendirilmesi.
    6. **Doğrulama (*Validation*):** Tanımlanan gereksinimlerin belirsizlik, çelişki, hata, eksiklik ve gerçekçilik açısından sınanması; bu amaçla **Resmi Teknik Değerlendirme (*Formal Technical Review* — FTR)** toplantılarının yapılması (ekrandan, 00:50:00).
    7. **Yönetim (*Management*):** Tüm yazılım yaşam döngüsü boyunca süren şemsiye etkinlik; doğrulanmış SRS belgesinin sözleşmeye temel oluşturması ve gereksinimlerin/değişikliklerin **İzlenebilirlik Tabloları (*Traceability Tables*)** ile modül, paket ve sınıf düzeyinde takip edilmesi (ekrandan, 00:55:30).
- Nesneye Yönelik Çözümleme (*Object-Oriented Analysis*) ve Uygulama Alanı Analizi (*Domain Analysis*)
  - Çözümleme aşamasının temel olarak **"Ne?"** sorusuna yanıt araması: uygulama alanının (*problem domain*), alandaki varlıkların, niteliklerin ve ilişkilerin anlaşılması, kullanıcı gereksinimlerinin netleştirilmesi ve üst düzey planlama yapılması.
  - Uygulama alanı hakkında bilgi kaynakları: **teknik literatür** (standartlar dahil), **mevcut uygulamalar** (demo incelemeleri), **müşteri anketleri**, **uzman tavsiyeleri** (problem alanı uzmanı danışmanlığı) ve **mevcut/gelecekteki gereksinimler** (ekrandan, 01:20:00).
  - Problem alanı terminolojisine (jargonuna) hâkim olarak **"müşterinin dilinden konuşma"** ve tüm yapıtları (*artifacts*) bu terminolojiyle üretme zorunluluğu (ekrandan, 01:20:00).
- Kullanım Öyküleri (*Use Case* Metinleri) ve *NextGenPOS* Örneği
  - Doğal dille yazılmış örnek gereksinimler belgesinden (**NextGenPOS Perakende Satış Programı**) yapılandırılmış kullanım öykülerine geçiş (ekrandan, 01:26:00).
  - Bir kullanım öyküsü metninin 3 ana bölümü ve yazım kuralları:
    1. **Giriş Bölümü:** **Birincil Aktör (*Primary Actor*)**, **İlgililer ve İlgi Alanları (*Stakeholders and Interests*)**, **Ön Koşullar (*Preconditions*)** ve **Son Koşullar (*Postconditions*)** alt bölümleri (ekrandan, 01:33:00).
    2. **Ana Öykü (*Main Success Scenario*):** Her şeyin yolunda gittiği normal akışın `1`'den `N`'ye kadar **numaralandırılmış** ve öznesi belli **etken (*active*)** cümlelerle adım adım yazılması; döngülerin adım numaralarına referans verilerek kurulması (ekrandan, 01:36:30).
    3. **Alternatif Öyküler (*Extensions / Alternative Flows*):** Ana akıştaki dallanma (`if-else`) ve istisna durumlarının, ilgili adım veya adım aralığına göre (`3a`, `3-7a`, `3-7b` vb.) numaralandırılarak ve kendi içinde tekrar `1, 2, ...` alt adımlarına ayrılarak yazılması (ekrandan, 01:40:00).
- UML Kullanım Şemaları (*Use Case Diagrams*) ve *Violet UML Editor* Uygulaması
  - Kullanım öykülerinin özet ve bütüncül grafik gösterimi olan **UML Use Case Şemalarının** bileşenleri: **Use Case** (elips), **İnsan Aktör** (çöp adam), **İnsan Olmayan Aktör** (`<<actor>>` stereotipli dikdörtgen), **Etkileşim/Kullanım** (düz çizgi) ve **Use Case'ler Arası İlişkiler** (kesikli ve ucu açık ok) (ekrandan, 02:13:00).
  - **`<<includes>>` (veya `<<include>>`) ilişkisi:** Ana öykünün her çalışmasında zorunlu olarak içerilen alt işlev veya ön koşul (ok yönü: ana use case'den içerilen use case'e doğru, ör. `Satış ----<<include>>---> Ödeme`) (ekrandan, 02:13:00; ekrandan, 02:36:00).
  - **`<<extends>>` (veya `<<extend>>`) ilişkisi:** Alternatif senaryoda belirli koşullarda devreye giren çeşitleme/istisna işlevi (ok yönü: alternatif use case'den ana use case'e doğru, ör. `Ürün Silme ----<<extend>>---> Satış`, `Geçersiz Barkod ----<<extend>>---> Satış`, `Provizyon ----<<extend>>---> Ödeme`) (ekrandan, 02:13:00; ekrandan, 02:36:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Beklenen (*Expected*) ve Heveslendirici (*Exciting*) Gereksinimlerin Yönetimi
  - **Beklenen gereksinimler** o problem alanında herkesçe bilindiği varsayılan çok temel özelliklerdir (ör. kütüphane otomasyonunda ödünç süresi ve gecikme cezası); müşteri bunları söylemeyi unutabileceği için yazılım ekibi en ufak şüphede mutlaka soru sorarak bu gizli gereksinimleri ilk aşamada ortaya çıkarmalıdır (ekrandan, 00:30:00).
  - **Heveslendirici gereksinimler** ise olmazsa olmaz olmayan "lüks" özelliklerdir; bunların doğru etiketlenmesi, projede süre veya bütçe sıkışıklığı yaşandığında temel işlevlerden ödün vermeden hangi özelliklerden vazgeçilebileceğini bilmek açısından kritik önem taşır (ekrandan, 00:30:00).
- İşlevsel (*Functional*) ve İşlevsel Olmayan (*Non-Functional*) Gereksinim Ayrımı
  - Sistemin problem alanı kuralları çerçevesinde **ne iş yapacağını** belirten gereksinimler (ör. kütüphanede öğrenciye 2 hafta, akademisyene 4 hafta ödünç verilmesi; gecikme cezasının öğrenci için günlük 1 TL, akademisyen için 5 TL olması; perakende satışta KDV hesaplanıp fiş kesilmesi) **işlevsel gereksinimlerdir**.
  - Bu işlevlerin **hangi sistem düzeyi kısıtlar, performans hedefleri veya platform özellikleri** altında çalışacağını belirten gereksinimler ise (ör. verilerin lisans maliyeti çıkarmamak için *MySQL* ilişkisel veritabanında tutulması, 1000 kayıtlık raporun 1 saniyenin altında üretilmesi, sistemin kütüphanenin yerel sunucusunda ve *Red Hat Linux 12.0* üzerinde çalışması) **işlevsel olmayan gereksinimlerdir**.
- İzlenebilirlik Tablolarının (*Traceability Tables*) Değişiklik ve Hata Ayıklamadaki Rolü
  - Satırlarda gereksinimlerin ($G_1, G_2, \dots$), sütunlarda ise sisteme ait bakış açılarının ($B_1, B_2, \dots$ — modüller, paketler veya sınıflar) yer aldığı izlenebilirlik matrisleri, yalnızca hangi gereksinimin nerede gerçeklendiğini takip etmeye yaramaz; bir gereksinim değiştiğinde veya bir *bug* (hata) çıktığında **arama uzayını doğrudan ilgili sınıflara ($B_1, B_3$ vb.) daraltarak** bakım ve hata düzeltme maliyetini büyük ölçüde düşürür (ekrandan, 00:55:30).
- Kullanım Öyküsü Metinlerinde Numaralandırma, Etken Cümle Yapısı ve Alternatif Senaryo Zorunluluğu
  - Ana öyküde tüm adımlar `1`'den başlayarak numaralandırılmalı, alternatif öykülerde ise ana adıma atıf yapan iki parçalı kodlama (`3a`, `3-7a`, `3-7b` vb.) ve kendi içinde `1, 2, ...` alt numaralandırması kullanılmalıdır; hiçbir döngü olmasa bile gelecekteki değişikliklere hazırlık için numaralandırma şarttır (ekrandan, 01:36:30; ekrandan, 01:40:00).
  - Tüm adımlar **edilgen değil, etken (*active*) cümlelerle** yazılmalıdır (*"Yeni satış işlemi başlatılır"* yerine *"Kasiyer yeni bir satış işlemi başlatır"*); çünkü eylemi kasiyerin mi yoksa yürüyen bandı algılayan sistemin mi başlattığı belirsiz bırakılamaz.
  - Tüm işlemler ana öyküye sıkıştırılmamalı; koşullu (`if-else`) durumlar mutlaka alternatif öykülere ayrılmalıdır.
- UML Use Case Şemalarının Amacı ve `<<includes>>` / `<<extends>>` Ok Yönleri
  - Use Case şeması **bir akış şeması (*flowchart*) değildir** (işlem sırasını göstermez; bunun için *sequence* ve *activity* diyagramları kullanılır) ve **bir kullanıcı yetki şeması da değildir**; amacı sistemin işlevlerine ve birincil aktörlerine kuşbakışı bir genel görünüm sunmaktır.
  - Ok yönleri İngilizce okunuş sırasını izler: ana senaryo alt senaryoyu içerdiği için **`A ----<<includes>>---> C`** (*Use Case A includes Use Case C*); alternatif senaryo ise ana senaryoyu genişlettiği için **`B ----<<extends>>---> A`** (*Use Case B extends Use Case A*) yönünde, **kesikli çizgi ve ucu açık okla** çizilir (ekrandan, 02:13:00).

## Kısa Tekrar Notları

- **IEEE 830-1998:** Yazılım Gereksinimler Belgesi (*Software Requirements Specification* — SRS) önerilen uygulama standardı.
- **Gereksinim mühendisliğinin 7 adımı:** 1) Başlangıç (*Inception*), 2) Bilgi Toplama (*Elicitation*), 3) İşleme (*Elaboration*), 4) Pazarlık (*Negotiation*), 5) Tanımlama (*Specification*), 6) Doğrulama (*Validation*), 7) Yönetim (*Management*) (ekrandan, 00:18:10).
- **Prototip vs. Pilot uygulama:** **Prototip** tam işlevsel olmayan ön üründür; **pilot uygulama** ise tamamlanmış (veya ilk sürümü çıkmış) ürünün gerçek çalışma ortamında ilk kez bir müşteride denenmesidir.
- **Verimli toplantının 3 kriteri (Bilgi Toplama):** 1) Ön hazırlık ve katılım kuralları, 2) Çok katı olmayan ama dağılmayı önleyen gündem, 3) Tıkanıklıkları çözen oturum başkanı (*Robert's Rules of Order*).
- **Gereksinim sınıfları (Kano / İşleme):** **Normal gereksinimler** (açıkça talep edilen işlevsel ve işlevsel olmayan özellikler), **Beklenen (*expected*) gereksinimler** (müşterinin söylemeye gerek duymadığı çok temel özellikler), **Heveslendirici (*exciting*) gereksinimler** (beklentinin ötesinde, süre/bütçe yetmezse vazgeçilebilecek lüks özellikler) (ekrandan, 00:30:00).
- **Formel modeller:** Görev kritik (*mission-critical*) sistemlerde (uçuş kontrol, afet erken uyarı, savunma sanayii) gereksinimlerin matematiksel/mantıksal teoremlerle tanımlanıp kodlamadan önce ispatlanması (ör. **Z dili**).
- **Doğrulama (*Validation*) aracı:** **FTR (*Formal Technical Review* — Resmi Teknik Değerlendirme)** toplantısı (ekrandan, 00:50:00).
- **İzlenebilirlik Tablosu (*Traceability Table*):** Satırlarda gereksinimler ($G_1, G_2, \dots$), sütunlarda sistem bakış açıları ($B_1, B_2, \dots$: modüller, paketler, sınıflar) bulunan, değişiklik ve hata takibi sağlayan matris (ekrandan, 00:55:30).
- **Çözümleme (*Analysis*) vs. Tasarım (*Design*) temel soruları:** Çözümleme **"Ne?"** sorusuna (problem alanındaki varlıklar ve ilişkiler), Tasarım ise **"Nasıl?"** sorusuna yanıt arar.
- **Kullanım öyküsü (*Use Case*) 3 bölümü:** 1) **Giriş** (Birincil Aktör, İlgililer ve İlgi Alanları, Ön Koşullar, Son Koşullar), 2) **Ana Öykü** (`1..N` numaralı etken adımlar), 3) **Alternatif Öyküler** (`3a`, `3-7a`, `3-7b` kodlu istisna ve varyasyonlar) (ekrandan, 01:33:00; ekrandan, 01:36:30; ekrandan, 01:40:00).
- **Aktör türleri:** **İnsan aktör** (çöp adam ile çizilir) ve **İnsan olmayan aktör** (harici yazılım/donanım sistemi; `<<actor>>` stereotipli dikdörtgen ile çizilir) (ekrandan, 02:13:00).
- **UML Use Case ilişkileri:**
  - `Ana Use Case ----<<includes>>---> Alt Use Case` (her seferinde zorunlu içerme / ön koşul).
  - `Alternatif Use Case ----<<extends>>---> Ana Use Case` (koşullu alternatif akış / istisna) (ekrandan, 02:13:00).

## Detaylı Açıklamalar

### 1. Gereksinim Mühendisliği Adımları (7 Aşamalı Süreç)

Gereksinim mühendisliği yedi adımdan oluşur ve projenin doğasına göre ardışık (şelale gibi) ya da tanıdık olunmayan yeni bir problem alanında artımsal/yinelemeli (*agile*) olarak yürütülebilir; her iki durumda da müşterinin sürece aktif katılımı şarttır (ekrandan, 00:18:10):

1. **Başlangıç (*Inception*):** Yazılım projesinin ilk aşamalarının (gereksinim mühendisliği ve yapılabilirlik çalışmasının) başlatılıp başlatılmamasına karar verilen adımdır (ekrandan, 00:18:10). Fikir müşteri tarafından (yeni bir iş gereksinimi, mevcut süreçlerdeki verimsizlikler veya yöneticiler ile çalışanlar arasındaki kısa bir konuşma) ya da yazılım şirketi tarafından (yeni bir pazarın/hizmetin fark edilmesi veya teknik ekiple üst yönetimin görüşmesi) ortaya atılabilir (ekrandan, 00:18:10). Genel amaçlı bir uygulama geliştirilecekse bile temel gereksinimleri belirlemek ve ilk **pilot uygulamayı** yapmak üzere bir müşteriyle anlaşılabilir (pilot uygulama tam işlevsel ilk sürümün sahada denenmesidir; müşteri olası ilk kullanım aksaklıkları riskini üstlenirken karşılığında hızlı destek ve fiyat indirimi elde eder, yazılım evi ise değerli saha verisi kazanır). Bu adımda yapılan **en önemli etkinlik paydaşların (*stakeholders*), bakış açılarının ve kazanma durumlarının belirlenmesidir**.
2. **Bilgi Toplama (*Elicitation*):** Birinci adımda belirlenen paydaşlarla genellikle yüz yüze toplantılar yapılarak gereksinimler hakkında ayrıntılı ham bilgi toplanır. Verimli bir toplantı için üç kural uygulanır: 1) Katılım kuralları ve ön hazırlık olmalı, 2) Gündem önceden belirlenmeli ancak beyin fırtınasını (*brainstorming*) ve yaratıcılığı baltalayacak kadar katı olmamalı (tamamen ucu açık bırakılarak ayrıntıda boğulmaya da izin verilmemeli), 3) Paydaşlar arası çelişkilerden doğacak tıkanıklıkları çözecek bir **oturum başkanı** bulunmalıdır (literatürde parlamenter toplantı düzeni için klasik kaynak **Robert's Rules of Order** kitabıdır).
3. **İşleme (*Elaboration*):** Bilgi toplama aşamasında elde edilen ham veriler işlenerek yapılandırılmış bilgiye dönüştürülür (ekrandan, 00:30:00). Son kullanıcının ve diğer paydaşların yazılımla nasıl etkileşeceği belirlenir; ekran tasarımları ve geçişleri sinema/çizgi film sektöründen esinlenen **hikâye tahtaları (*storyboarding*)** veya hızlı GUI çizim araçlarıyla (*Visual Basic* vb. sürükle-bırak ortamlar) görselleştirilir, etkileşimler kullanım senaryolarına dökülür (ekrandan, 00:30:00). Tekrarlayan veya aşırı ayrıntılı veriler özetlenirken, yetersiz bilgi toplanmış işlevler için ilgili paydaşlarla ek görüşmeler yapılarak bilgi genişletilir. Ardından gereksinimler iki farklı eksende sınıflandırılır (ekrandan, 00:30:00):
   - **Teknik doğasına göre:** Sistemin iş mantığı çerçevesinde yapacağı işler **işlevsel gereksinimler (*functional requirements*)** (ör. kütüphanede kullanıcı türüne göre ödünç süreleri ve gecikme cezaları, raporda yer alacak bilgiler); bu işlerin hangi sistem kısıtları ve başarım ölçütleriyle yapılacağı ise **işlevsel olmayan gereksinimler (*non-functional requirements*)** (ör. lisans maliyeti olmaması için *MySQL* kullanılması, 1000 kayıtlık raporun 1 saniye altında hazırlanması, sistemin yerel sunucuda *Red Hat Linux 12.0* üzerinde çalışması) olarak ayrılır.
   - **Müşteri beklenti düzeyine göre (ekrandan, 00:30:00):**
     - *Normal gereksinimler:* Müşterinin açıkça ifade ettiği işlevsel ve işlevsel olmayan gereksinimler.
     - *Beklenen gereksinimler (Expected requirements):* O kadar temeldir ki müşteri herkesin bildiğini varsayarak söylemeyi unutabilir (ör. kütüphane otomasyonunda ödünç alınan kitabın bir iade süresi ve gecikme cezası olması). İlk aşamada keşfedilmezse ileride üstel artan değişiklik maliyeti doğuracağı için çok tehlikelidir; ekip en ufak belirsizlikte müşteriye soru sormalıdır.
     - *Heveslendirici gereksinimler (Exciting requirements):* Müşteri beklentilerinin ötesinde, varlığında müşteriyi çok memnun edecek ancak olmazsa olmaz olmayan "lüks" özelliklerdir. Süre veya bütçe sıkıştığında vazgeçilebilecek ilk grubu oluşturduğu için ayrı işaretlenmesi her iki tarafı da rahatlatır.
4. **Pazarlık (*Negotiation*):** Farklı paydaşların çelişen istekleri ve öncelikleri ile yazılım evinin zaman, bütçe ve insan gücü kısıtları bir araya getirilir. Yazılım evi de tutabileceği gerçekçi bir söz vermek zorunda olan bir paydaş olarak masadadır. Aşamanın sonunda tüm paydaşların uzlaştığı ve altına imza atabileceği bir gereksinimler listesi ortaya çıkar.
5. **Tanımlama (*Specification*):** Doğal konuşma dilinin belirsizliğini en aza indirmek için gereksinimler standart yazılı belgelere, **kullanım öyküsü metinlerine**, **UML kullanım şemalarına (*use case diagrams*)**, *storyboard*/prototiplere ve eğer uçuş kontrol yazılımı, afet erken uyarı sistemi veya savunma sanayii gibi can ve mal güvenliği açısından **görev kritik (*mission-critical*)** bir sistem geliştiriliyorsa **Z dili** gibi matematiksel teorem ve ispatlara dayalı **formel modellere** dökülür.
6. **Doğrulama (*Validation*):** Tanımlanan gereksinimlerin tutarsızlıklara karşı sağlaması yapılır (ekrandan, 00:50:00): *"Gereksinimler açıkça ve yoruma yer bırakmayacak şekilde tanımlanmış mı?"*, *"Birbiri ile çelişen gereksinimler var mı?"*, *"Gereksinimlerde hatalar ve eksikler var mı?"*, *"Eksik (hiç keşfedilmemiş) gereksinimler var mı?"*, *"Gerçekçi olmayan gereksinimler var mı?"* (ekrandan, 00:50:00). Bunun için önerilen temel yöntem, sınama teknikleri arasında yer alan **Resmi Teknik Değerlendirme (*Formal Technical Review* — FTR)** toplantısıdır (ekrandan, 00:50:00).
7. **Yönetim (*Management*):** Doğrulamadan geçen SRS belgesi resmi sözleşmenin ayrılmaz parçası olarak imzalanır (çevik süreçlerde daha hafif sıklet, ardışık süreçlerde daha ağır sıklet sözleşme). Ancak yönetim tek seferlik bir adım değil, proje boyunca süren bir şemsiye etkinliktir. Gereksinimlerin gerçeklenmesi ve değişikliklerin etkisi **İzlenebilirlik Tabloları (*Traceability Tables*)** ile izlenir (ekrandan, 00:55:30):

| | **B1** | **B2** | **B3** | **...** |
| :--- | :---: | :---: | :---: | :---: |
| **G1** | $\checkmark$ | | $\checkmark$ | |
| **G2** | | $\checkmark$ | | |
| **G3** | $\checkmark$ | | | |
| **...** | | | | |

   Burada satırlar gereksinimleri ($G_1, G_2, \dots$), sütunlar ise sisteme çeşitli bakış açılarını ($B_1, B_2, \dots$: modüller tablosu, paketler tablosu, sınıflar tablosu vb.) gösterir (ekrandan, 00:55:30). Örneğin $G_1$ gereksinimi $B_1$ ve $B_3$ sınıflarıyla ilişkilidir; ileride $G_1$'de bir değişiklik istendiğinde veya $G_1$ ile ilgili bir *bug* çıktığında geliştirici tüm kodu taramak yerine doğrudan $B_1$ ve $B_3$'e odaklanır.

### 2. Nesneye Yönelik Çözümleme, Kullanım Öyküleri ve NextGenPOS Örneği

**Nesneye Yönelik Çözümleme (*Object-Oriented Analysis*)** süreci, problemi parçalara ayırarak anlamayı, uygulama alanındaki (*domain*) varlıkları, niteliklerini, eylemlerini ve aralarındaki ilişkileri keşfederek **alan modeline (*domain model* / analiz modeli)** taşımayı ve üst düzey planlama yapmayı kapsar (ekrandan, 01:20:00). Çözümleme aşaması temel olarak **"Ne?"** sorusunu yanıtlar. Uygulama alanı hakkında bilgi edinmek için **teknik literatür** (ve standartlar), **mevcut rakip uygulamalar**, **müşteri anketleri**, **uzman tavsiyeleri** (özellikle özel bir müşteri veya pilot kurum yoksa konu alanı uzmanı danışmanlığı) ve **mevcut/gelecekteki gereksinimler** incelenir (ekrandan, 01:20:00). Bu sayede problem alanının jargonu öğrenilerek **"müşterinin dilinden konuşulur"** ve tüm belgeler ile ekranlarda müşterinin aşina olduğu terimler kullanılır (ekrandan, 01:20:00).

Ders boyunca ve izleyen haftalarda örnek olarak kullanılacak doğal dille yazılmış **NextGenPOS Perakende Satış Programı** gereksinimler belgesi şöyledir (ekrandan, 01:26:00):
> *"Eski yazılım ihtiyaçlarımızı karşılayamadığından, yenilenecek donanımla birlikte perakende satış programımızın da yenilenmesine gerek duyuyoruz. Program kasada yapılan alış-veriş işlemlerine yardımcı olmalıdır. Yapılan her işlem program tarafından saklanmalı; mali bilgiler harici bütçe sistemine, mal çıkış bilgileri ise harici envanter sistemine iletilmelidir. Saklanan işlemler üzerinde daha sonra raporlamalar ve analizler yapılabilmelidir. Sistem yapılan alış-verişler karşılığında müşteriye fiş vermelidir. Yapılan her satış için KDV de hesaplanarak ayrıca belirtilmelidir. Şirketimizin birden fazla şubesi olup tüm şubelerdeki işlemler merkezi sunucuya iletilmelidir."* (ekrandan, 01:26:00).

Bu doğal dil metninden yola çıkılarak hazırlanan **Satış İşlemi Kullanım Öyküsü (*Use Case*)** üç bölümden oluşur (ekrandan, 01:33:00; ekrandan, 01:36:30; ekrandan, 01:40:00):

1. **Giriş Bölümü (ekrandan, 01:33:00):**
   - **Birincil Aktör:** Kasiyer (sistemle etkileşen insan veya harici yazılım/donanım varlıklarına *aktör* denir; işin odağındaki aktör birincil aktördür).
   - **İlgililer ve İlgi Alanları:**
     - *Kasiyer:* Doğru ve hızlı giriş ister, kasa açığı maaşından kesildiğinden ödeme hataları istemez.
     - *Satıcı:* Satış komisyonlarının güncellenmesini ister.
     - *Müşteri:* En az çaba ile hızlı hizmet ister. Ürün iadesinde kullanmak üzere fiş ister.
   - **Ön Koşullar:** Kasiyerin kimliği doğrulanır (ana öykü başlamadan önce sistemin içinde bulunması gereken durum; kimlik doğrulama başlı başına ayrı bir kullanım öyküsüdür).
   - **Son Koşullar:** Ödeme tahsil edilir. Satış kaydedilir. Fiş yazılır (ana öykü bittiğinde sistemin durumu).
2. **Ana Öykü (*Main Success Scenario*) (ekrandan, 01:36:30):**
   1. Müşteri kasaya alacağı ürünlerle gelir.
   2. Kasiyer yeni bir satış işlemi başlatır.
   3. Kasiyer ürünün barkodunu girer.
   4. Sistem bir satış kanalı maddesi oluşturur. Bu maddede ürün tanımı, fiyatı ve toplam bedel (aynı maldan birden fazla alınmış olabilir) yer alır.
   5. Kasiyer 3. ve 4. adımları müşterinin alacağı tüm ürünler için tekrarlar.
   6. Sistem toplam bedeli KDV (slaytta sehven *"vergi iadesi"* yazılmış, hoca derste *"KDV"* olarak düzeltmiştir) ile birlikte hesaplar.
   7. Kasiyer müşteriye toplamı bildirir ve ödeme ister.
   8. Müşteri ödemeyi yapar ve sistem ödemeyi tahsil eder.
   9. Sistem tamamlanan işlemin kaydını tutmayı tamamlar ve harici envanter ile mali sistemlere gerekli bilgileri gönderir.
   10. Sistem fiş verir.
   11. Müşteri ürünlerle birlikte ayrılır.
3. **Alternatif Öyküler (*Alternative Flows / Extensions*) (ekrandan, 01:40:00):**
   - **3a.** Geçersiz barkod (ana öykünün 3. adımındaki ilk alternatif):
     1. Sistem uyarı mesajı verir ve kayıt girişini reddeder.
   - **3-7a.** Müşteri bir kalem malı alışverişten çıkartmak ister (ana öykünün 3. ila 7. adımları arasında gerçekleşebilecek ilk alternatif; aynı aralıkta ikinci bir alternatif olsaydı `3-7b` olarak numaralandırılırdı):
     1. Kasiyer satıştan çıkarmak üzere ürünün barkodunu okutur.
     2. Sistem güncel toplamı bildirir.

### 3. UML Kullanım Şemaları (Use Case Diagrams)

Kullanım öyküleri ayrıntılı ve uzun metinler olduğundan, sistemin işlevlerini ve aktörlerle ilişkilerini tek bakışta özetlemek için **UML Kullanım Şemaları (*Use Case Diagrams*)** çizilir (ekrandan, 01:40:00; ekrandan, 02:13:00):

```text
   O                     .-------------------.
  /|\ -------------------|    Use Case A     |
  / \                    |-------------------|
Kişi türü adı            | Extension Points  |
(İnsan Aktör)            |  Adım K, Adım L   |
                         '-------------------'
                             ^            \
                <<extends>> /              \ <<includes>>
                           /                v
                  .--------------.    .--------------.      .------------------.
                  |  Use Case B  |    |  Use Case C  |------|     <<actor>>    |
                  '--------------'    '--------------'      |  HW/SW Element   |
                                                            '------------------'
```

- **Bileşenler (ekrandan, 02:13:00):** İşlevler (**Use Case**) elips ile; **insan aktörler** çöp adam ile; harici envanter/mali sistem gibi **insan olmayan aktörler** ise sınıf şemasındaki sınıflarla karışmaması için üstünde `<<actor>>` stereotipi bulunan dikdörtgen ile gösterilir. Şemayı karmaşıklaştırmamak adına her use case yalnızca **birincil aktörü** ile düz çizgiyle birleştirilir.
- **`<<includes>>` ve `<<extends>>` İlişkileri (ekrandan, 02:13:00; ekrandan, 02:36:00):**
  - **`<<includes>>` (`<<include>>`):** Bir ana öykünün her yürütülüşünde mutlaka çalışan ortak bir alt senaryoyu veya ön koşulu ifade eder. Ok yönü İngilizce okunuşa (*Use Case A includes Use Case C*) uygun olarak **ana use case'den alt use case'e doğrudur**. Örneğin `Satış` işlemi her zaman `Ödeme` işlemini içerir (`Satış ----<<include>>---> Ödeme`) ve ön koşul olan `Kimlik Doğrulama`'yı içerir (`Satış ----<<include>>---> Kimlik Doğrulama`).
  - **`<<extends>>` (`<<extend>>`):** Yalnızca belirli koşullarda (`if-else`) devreye giren **alternatif senaryoları** ifade eder (Java'daki kalıtım anahtar kelimesi olan `extends` ile hiçbir ilgisi yoktur). Ok yönü İngilizce okunuşa (*Use Case B extends Use Case A*) uygun olarak **alternatif use case'den ana use case'e doğrudur**. Örneğin `Geçersiz Barkod`, `Ürün Silme` ve perakende mağazadaki isteğe bağlı müşteri sadakat kartı (`Loyalty Card`) senaryoları `Satış` use case'ini genişletir (`Ürün Silme ----<<extend>>---> Satış`); kredi/banka/yemek kartıyla ödemede yapılan banka `Provizyon` sorgusu ise `Ödeme` use case'ini genişletir (`Provizyon ----<<extend>>---> Ödeme`) (ekrandan, 02:36:00). Eğer *Metro Gross Market* gibi sadakat kartının zorunlu ön koşul olduğu bir toptancı mağazası modelleniyorsa veya `config.xml` ayarıyla bu zorunlu kılınıyorsa, `Loyalty Card` ilişkisi `Satış ----<<include>>---> Loyalty Card` hâline döner (ekrandan, 02:36:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
