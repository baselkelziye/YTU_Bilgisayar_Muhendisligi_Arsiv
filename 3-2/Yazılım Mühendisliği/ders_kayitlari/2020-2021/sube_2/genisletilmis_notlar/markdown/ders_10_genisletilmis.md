# Ders 10 Genişletilmiş Notu: Risk Yönetimi, Yazılım Sınama Teknikleri ve JUnit ile Birim Sınaması Uygulaması

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Yazılım Proje Yönetimi: Risk Yönetimi (Risk Management)
- 2. Yazılım Sınama Teknikleri (Software Testing) ve Birim Sınamaları
- 3. JUnit (3.x ve 4.x) Çatısı ile Birim Sınaması Mimarisi
- 4. Video Kaset Kiralama Uygulaması Üzerinde JUnit Birim Testleri ve Hata Ayıklama
- 5. Proje Raporu ve Birim Sınaması Hakkında Öğrenci Soruları
- Örnek Sorular
- Dersin Toparlaması

## 1. Yazılım Proje Yönetimi: Risk Yönetimi (Risk Management)

Bu derste, dönem sonu proje ödevinin son iki bileşeni olan **Risk Analizi (Risk Yönetimi)** ve **Birim Sınamaları (*Unit Testing*)** konuları ele alınmıştır.

### 1.1 Risk Tanımı: Reaktif (Sonradan) ve Proaktif (Önceden) Yaklaşımlar

Literatürde riskin farklı etkenlerine odaklanan çeşitli tanımları bulunmakla birlikte, üzerinde uzlaşılan iki temel bileşen vardır: **1) Belirli bir gerçekleşme olasılığı (kesin olmama)** ve **2) Gerçekleştiğinde doğuracağı istenmeyen sonuç/kayıp**. Bu iki bileşenden yola çıkarak **risk**, *"ortaya çıktığında istenmeyen sonuç ve kayıplar doğuran, ancak ortaya çıkması belirli bir olasılık dâhilinde olup kesin olmayan olumsuz durumlar"* olarak tanımlanır.

Risk ile iki farklı yaklaşımla uğraşılabilir:
1. **Reaktif (Sonradan) Yaklaşım:** Risk gerçekleşip sorun ortaya çıktıktan sonra, oluşan zararı gidermeye veya en aza indirmeye çalışmaktır.
2. **Proaktif (Önceden) Yaklaşım:** Risk henüz gerçekleşmeden, ortaya çıkmasını önlemeye veya gerçekleşirse yaratacağı etkiyi önceden azaltmaya çalışmaktır.
   - *Günlük Hayat Benzetmeleri:* Hoca proaktif yaklaşımı akılda kalıcı kılmak için önce Nasreddin Hoca'nın çeşmeye su doldurmaya göndereceği kızını testi kırılmadan önce uyarması fıkrasını, ardından da **bir binadaki yangın riski** örneğini vermiştir: Yangın çıktıktan sonra itfaiyenin gelip yangını söndürmeye çalışması **reaktif (sonradan)** bir uğraştır. Buna karşılık yangın elektrik tesisatından kaynaklanıyorsa; binanın elektrik dağıtım planını hazırlayan mühendisin hesapları doğru yapması, işçilerin kabloları doğru monte etmesi ve güneşte erimeyecek standartlara uygun plastik kanallar kullanması yangın riskini daha ortaya çıkmadan engelleyen **proaktif (önceden)** yaklaşımdır. Yazılım mühendisliğinde hedefimiz proaktif risk yönetimidir.

### 1.2 Yazılım Geliştirme Sürecinde Üç Genel Risk Kategorisi

IEEE, ISO ve ANSI gibi standart kuruluşlarının farklı sınıflandırmaları bulunmakla birlikte, yazılım mühendisliğinde riskler en temel hâliyle üç ana kategoride incelenir (ekrandan, 00:10:00):

1. **Proje Riskleri:**
   - **Proje planını tehdit eder.** Gerçekleşirse zamanlama ileri tarihlere sarkar ve maliyet artar (ekrandan, 00:10:00).
   - Bir yazılım projesinin başarılı sayılması için üç temel ayağın (**önceden belirlenen zamanlama**, **önceden belirlenen bütçe/maliyet** ve **önceden belirlenen işlevler/kapsam**) birlikte sağlanması gerekir. Bu üç ayaktan herhangi birindeki hedefe ulaşılmasını doğrudan engelleyen *bütçe riskleri, zaman riskleri ve personel riskleri* (örneğin kilit öneme sahip personelin işten ayrılması, hastalanması veya sınama personeli sayısının azalması) proje riskleri altında gruplandırılır (ekrandan, 00:10:00).
2. **Teknik Riskler:**
   - **Üretilen yazılımın kalitesini ve zamanında bitirilmesini etkiler.** Gerçekleşirse yazılımı gerçekleme (*implementation*) zorlaşır veya imkânsızlaşır (ekrandan, 00:10:00).
   - Doğrudan doğruya yazılım geliştirme yaşam döngüsünün temel teknik aşamaları olan **çözümleme (analiz), tasarım, gerçekleme (kodlama) ve bakım** aşamalarıyla ilgili risklerdir (ekrandan, 00:10:00).
   - **Örnek — "Son Teknoloji" (*Cutting-Edge*) Ürünlerin ve Çatıların (*Frameworks*) Kullanımı:** Projede nispeten yeni çıkmış veya ekibin daha önce kullanım tecrübesi olmayan bir *framework* / kütüphane seçildiğinde şu dört teknik soru büyük risk oluşturur (ekrandan, 00:10:00):
     1. *Bug'lar var mı?* (Yeni sürümde henüz keşfedilmemiş hatalar bulunabilir.)
     2. *Dokümantasyonu tam mı?* (Hızlı geliştirilen yeni çatılarda önce özellikler eklenip teknik dokümantasyon sonradan yazılabildiği için ekibin kaynak kod okuyarak işi çözmeye çalışması gerekebilir.)
     3. *Tam anlayabildik mi bu teknolojiyi?* (Ekibin tecrübesizliği yüzünden forumlarda soru sorup yanıt beklemek süreci yavaşlatır.)
     4. *Yarın da bu teknoloji hayatta olacak mı?* (İlgili topluluk [*community*] birkaç ay sonra o *framework*'ü geliştirmeyi durdurursa, projenin ortasında eksik kalan bir özelliği geliştirici ekibin kendi başına kodlaması veya sonraki sürümlerde kütüphaneyi tamamen değiştirmesi gerekir.)

> **Hocanın vurgusu (Teknik Risk ile Proje Riskini Karıştırmama ve Brooks Yasası):**
> Bir teknik risk gerçekleştiğinde (örneğin kullanılan *framework*'teki bir sorun veya eski projelerdeki kodları **yeniden kullanım [*reuse*]** oranının planlanan `%30` seviyesinin altında kalması yüzünden ek kod yazılması gerektiğinde), bunun doğal yan etkisi olarak projenin tamamlanma tarihi sarkar. Ancak burada **kök neden** kullanılan kodlama aracı, yazılım bileşeni veya teknik süreç olduğu için bu durum proje riski değil, **teknik risk** olarak sınıflandırılmalıdır (ekrandan, 00:10:00). Ayrıca geciken süreyi telafi etmek için projeye sonradan yeni programcı eklenmemelidir; çünkü projeye sonradan katılanların o ana kadar yapılan işleri öğrenmesi gerekeceğinden proje süresi kısalmak yerine daha da uzar. Bunun yerine örneğin ilk kez kullanılan bir araç varsa 3 haftalık *sprint* süresi proaktif biçimde 4 haftaya çıkarılabilir.

3. **İşletme (İş / Ticari) Riskleri:**
   - Geliştirilen ürünün ticari başarısını ve sürdürülebilirliğini tehdit eden, yönetim bilişim sistemleri (*MIS*) ve işletme yüksek lisansı (*MBA*) kapsamındaki risklerdir (ekrandan, 00:10:00):
     - **Pazar Riskleri (*Ürüne talep olur mu?*):** Ortaya çıkarılan ürüne pazarda gerçekten ihtiyaç duyulup duyulmamasıdır. Hoca bunu **tıraş bıçağı – tıraş makinesi** örneğiyle açıklamıştır: Pazarda az sayıda tıraş makinesi üreticisi olduğunu görüp bu alana yatırım yapan bir girişimci, hedef kitlenin büyük çoğunluğunun tıraş makinesi yerine tıraş bıçağı kullanmayı tercih ettiğini fark ederse beklediğinden çok daha dar bir pazarla karşılaşır ve yeterli gelir elde edemez (ekrandan, 00:10:00). Yazılımda da hedeflenen pazar payına (*pazar penetrasyonuna*) yeterince hızlı ulaşılamaması veya eski sürümden yeni sürüme geçecek müşteri tahminlerinin tutmaması birer pazar riskidir.
     - **Satış Riskleri (*Pazarlama ekibi ürünü nasıl satacağını biliyor mu?*):** Özellikle küçük *start-up* veya KOBİ ölçeğindeki yazılım firmalarında ayrı bir satış ekibinin bulunmaması ya da mevcut satış personelinin üretilen yeni yazılımı nasıl pazarlayacağı konusunda deneyimsiz olmasıdır (ekrandan, 00:10:00).

### 1.3 Proaktif Risk Yönetimi Adımları: Risk Tablosu, Etki–Olasılık Grafiği ve Risk Bilgi Sayfası

Proaktif risk yönetimi üç ardışık etkinlikle yürütülür: **1) Risk tablosu oluşturma**, **2) Risk değerlendirme (Etki–Olasılık grafiği)** ve **3) Risk izleme (Risk bilgi sayfaları)**.

#### 1. Özet Risk Tablosu Oluşturma ve Geniş Katılım İlkesi

Risklerin belirlenmesi tek bir kişiye bırakılmamalıdır; proje yöneticisi, yazılım geliştiriciler, sınama ekibi, satış/pazarlama temsilcisi ve problem alanındaki konu uzmanı (*domain expert*) dâhil olmak üzere farklı eğitim ve sorumluluklara sahip tüm paydaşların katıldığı bir beyin fırtınası (*brainstorming*) ile yürütülmelidir. Böylece hem proje hem teknik hem de iş kategorilerindeki riskler eksiksiz yakalanabilir.

Her risk için kolay konuşulup grafik üzerinde kompakt gösterilebilmesini sağlayan sıralı bir **`Risk ID`** (`01, 02, ...`), açıklayıcı bir **ad**, **tür/grup** (*Proje, Teknik, İş*), gerçekleşirse yaratacağı **etki büyüklüğü** (3'lü skala: *Küçük, Orta, Büyük* veya 5'li skala) ve **gerçekleşme olasılığı** (*Düşük, Orta, Yüksek*) belirlenerek **Özet Risk Tablosu** oluşturulur (ekrandan, 00:27:30):

| Risk ID | Adı *(Slaytta kısa, raporda uzun yazılmalı)* | Türü, Grubu | Etkisi | Olasılık |
| :--- | :--- | :--- | :--- | :--- |
| `01` | Organizasyon | Proje | Orta | Yüksek |
| `02` | Tahmin | Proje | Büyük | Düşük |
| `03` | Kullanışlılık *(Ör. Kullanışlılığın düşük olması)* | Teknik | Büyük | Düşük |
| `04` | Doğruluk | Teknik | Orta | Düşük |
| `05` | Güvenilirlik | Teknik | Büyük | Düşük |
| `06` | Personel *(Ör. Kilit personelin ayrılması/hastalanması)* | Proje | Küçük | Düşük |
| `07` | Araçlar | Teknik | Orta | Orta |
| `08` | Metot | Teknik | Orta | Orta |
| `09` | Pazarlama *(Ör. Hedef pazar payına hızlı ulaşılamaması)* | İş | Büyük | Yüksek |

- Hoca slayta sığması için risk adlarını *Kullanışlılık*, *Personel*, *Pazarlama* gibi tek kelimeyle yazdığını; ancak gerçek projelerde ve proje ödevinde risk adlarının tek kelimeyle bırakılmayıp neyi ifade ettiğini açıkça anlatan birer cümle/ifade (*"Kilit öneme sahip personelin işten ayrılması"*, *"Sınama personeli sayısının azalması"* vb.) olarak yazılması gerektiğini vurgulamıştır. Ayrıca etki derecelendirmesini anlatırken Nasreddin Hoca'nın *"küçük kıyamet – büyük kıyamet"* nüktesini örnek vererek her olumsuz durumun kurum üzerindeki yıkıcılığının aynı olmadığını belirtmiştir.

#### 2. Etki–Olasılık Grafiği (4 Kadran Analizi) (ekrandan, 00:27:30)

Proaktif risk izleme başlı başına zaman ve iş gücü gerektiren maliyetli bir etkinlik olduğundan tablodaki **tüm riskler izlenmez**. Hangi risklerin izleneceğine karar vermek için X ekseninde **Olasılık**, Y ekseninde **Etki** bulunan 4 bölmeli (*4 quadrant*) bir grafik çizilir ve riskler `Risk ID` numaralarıyla grafiğe yerleştirilir (ekrandan, 00:27:30):

```text
  Etkisi
    ▲
    │   2          │        9
  Büyük     5      │   (SAĞ ÜST: Mutlaka
    │   3          │    proaktif işlenir)
    ├──────────────┼──────────────────────
    │     4   7  8 │
  Küçük            │        1
    │   6          │
    │ (SOL ALT:    │
    │  İzlenmez)   │
    └──────────────┴──────────────────────► Olasılığı
       Düşük                Yüksek
```

- **Sağ Üst Kadran (Yüksek Olasılık – Büyük Etki, ör. `9`):** Hem gerçekleşme olasılığı yüksek hem de zararı büyük olduğu için **mutlaka proaktif olarak izlenmeli ve işlenmelidir** (ekrandan, 00:27:30).
- **Sol Alt Kadran (Düşük Olasılık – Küçük/Orta Etki, ör. `4, 6, 7, 8`):** Gerçekleşme olasılığı düşük, gerçekleşse bile etkisi küçük olduğu için izleme çabasına değmez; **`4, 6, 7, 8.` risklerin izlenmesine gerek yoktur** (dikey kesme çizgisi biraz sola kaydırılırsa `8` numaralı risk sağ alt kadrana da dahil edilebilir) (ekrandan, 00:27:30).
- **Sol Üst (`2, 3, 5` — Düşük Olasılık, Büyük Etki) ve Sağ Alt (`1` — Yüksek Olasılık, Küçük/Orta Etki) Kadranlar:** Bu iki kadrandaki risklerin izlenip izlenmeyeceği **üst yönetimin vereceği stratejik bir karardır**. Örneğin sol üst kadrandaki risklerin olasılığı düşüktür ama gerçekleşirse firmayı sarsacak yıkıcı bir etki (*Büyük etki*) doğuracaktır; kurum bu yıkıcı darbeyi göze alamıyorsa sol üst kadranı da izlemeye alır (slayttaki sonuç kısmında `4, 6, 7, 8` dışındaki diğer riskler için ayrıntılı risk bilgi sayfaları oluşturulması kararlaştırılmıştır) (ekrandan, 00:27:30).

#### 3. Ayrıntılı Risk Bilgi Sayfası (Slayt 157) (ekrandan, 00:33:00)

İzlenmesine karar verilen her risk için yine tüm paydaşların katılımıyla; riskin açıklamasını, gerçekleşmeye yaklaştığını haber veren **erken uyarı işaretlerini** (*"kaza geliyorum der"*) ve alınacak **proaktif önlemleri** içeren bir **Risk Bilgi Sayfası** hazırlanır (ekrandan, 00:33:00):

```text
+---------------------------------------------------------------------------------+
| RİSK #09: Pazarlama                                                             |
| Olasılık: Yüksek          Etki: Büyük          Türü: Ticari                     |
|                                                                                 |
| Açıklama: Firmamız sadece yazılım geliştiricilerden oluşan çekirdek kadroyla    |
| çalışmaktadır. Ortaya çıkaracağımız yazılımın piyasada çok fazla alternatifi    |
| vardır.                                                                         |
|                                                                                 |
| İşaretleri:                                                                     |
| 1. Müşteri adayları ile görüşmede dinleyicilerin ilgisizliği ve "Biz zaten X    |
|    yazılımını kullanıyoruz. Neden sizi seçelim?" türü yorumları.                |
| 2. Bakım aşamasının ilk altı aylık süresince ürünümüzün kendisini amorti etme   |
|    oranının %50'nin altında kalması.                                            |
|                                                                                 |
| Önlemler:                                                                       |
| 1. Bir programcımıza MBA yaptırmak.                                             |
| 2. Gereksinim mühendisliği aşamasında konu uzmanlığı odaklı danışmanlık         |
|    hizmeti almak.                                                               |
| 3. Bir ya da iki firma ile pilot uygulama yapmak ve bu firmalara ürünü özel     |
|    indirim ile satmak.                                                          |
+---------------------------------------------------------------------------------+
```

- **Önlemlerin Değerlendirilmesi:**
  - *1. Önlem (Programcıya MBA yaptırmak):* En az iki dönem (Eylül–Haziran arası ~10 ay) süreceği için **uzun vadeli** bir önlemdir; hemen sonuç vermez ama şirketin gelecekteki ticari yetkinliği için değerlidir.
  - *2. Önlem (Konu uzmanı danışmanlığı):* Gereksinim ve analiz aşamasında hemen uygulanabilecek **kısa vadeli** bir önlemdir.
  - *3. Önlem (Bir ya da iki firma ile pilot uygulama yapmak ve ürünü özel indirimle satmak):* Hoca özellikle Teknopark firmalarında bu yöntemin çok sık ve başarıyla uygulandığını vurgulamıştır. Gereksinim belirlemeden sınamaya kadar gerçek bir müşteriyle sahada yakın çalışmak, yazılımcıların başlangıçta öngöremediği eksikliklerin ve faydalı işlevlerin erkenden keşfedilmesini sağlar; ürün gerçek saha koşullarında denendiği için çok daha az hatayla çıkar, rakiplerden sıyrılır ve pilot müşteri de ayırdığı zaman/emek karşılığında ürünü indirimli alarak **kazan-kazan (*win-win*)** durumu oluşur (ekrandan, 00:33:00).

## 2. Yazılım Sınama Teknikleri (Software Testing) ve Birim Sınamaları

### 2.1 Sınamanın Amacı, Erken Sınama İlkesi ve Sınama Türleri

Yazılım geliştirme karmaşık bir süreç olduğundan hataların ortaya çıkması kaçınılmazdır:
- **Yazılım Sınaması (*Software Testing*):** Yazılımdaki **hataları keşfetmeye (bulmaya)** yönelik yapılan etkinliklerdir.
- **Hata Ayıklama (*Debugging*):** Sınama sonucunda bulunan **hataların düzeltilmesi (giderilmesi)** işlemidir; sınama ile aynı işlem değildir ancak her sınama sürecinin ayrılmaz devamıdır.
- **Yaşam Döngüsünün Her Aşamasında Sınama:** Yazılım geliştirme sürecinde ilerledikçe değişiklik yapmanın maliyeti üstel (*exponential*) olarak arttığından, hatalar ne kadar erken bulunup düzeltilirse maliyet o kadar düşük olur. Bu nedenle sınama yalnızca kodlama bittikten sonra yapılmaz; daha **gereksinim belirleme, çözümleme (analiz) ve tasarım** aşamalarında da (ilerleyen derslerde işlenecek olan **Biçimsel Teknik İnceleme — *Formal Technical Review [FTR]*** yöntemiyle) sınama etkinlikleri yürütülür.
- **Sınama Çabası Oranı:** Sınama etkinlikleri de ciddi emek ve maliyet gerektirir. Proje planında toplam çabanın/zamanının belirli bir oranı (örneğin **`%10`'u**) sınamaya ayrılır ve bu bütçenin aşılmamasına çalışılır.

Sınama türleri **yaklaşım tarzlarına** ve **yürütülme sıralarına** göre iki eksende sınıflandırılır (ekrandan, 01:00:05):

1. **Yaklaşım Tarzlarına Göre Sınama Türleri (ekrandan, 01:00:05):**
   - **Kara Kutu Sınaması (*Black-box testing*):** Sınanacak birimin iç işleyişi (kaynak kodu) bilinmez veya göz önünde bulundurulmaz; sadece birimin beklenen geçerli girdilere karşı beklenen doğru çıktıları üretip üretmediğine bakılır. Daha az çaba gerektirdiği için kısıtlı süre ve bütçelerde oldukça yeterli ve kabul gören bir yaklaşımdır.
   - **Beyaz Kutu Sınaması (*White-box testing*):** Sınanacak birimin iç işleyişi (kaynak kodu, `if-else` ve `switch-case` dallanmaları, döngüleri) bilinir ve yapılacak sınamalar kod içindeki tüm olası denetim akışlarından (*code coverage*) geçecek çeşitlilikte belirlenir. Hata yakalama gücü daha yüksektir ancak daha fazla emek gerektirir (ekrandan, 01:00:05).
2. **Yürütülme Sıralarına (Yaşam Döngüsündeki Yerine) Göre Sınama Türleri (ekrandan, 01:00:05):**
   - **Doğrulama Sınamaları (*Verification tests*):** **Yazılım ekibi** tarafından yürütülür; kendi içinde sırasıyla ikiye ayrılır:
     1. **Birim Sınamaları (*Unit testing*)**
     2. **Tümleştirme Sınamaları (*Integration testing*)**
   - **Geçerleme Sınamaları (*Validation tests*):** **Son kullanıcılar** tarafından yürütülür; kendi içinde sırasıyla ikiye ayrılır:
     3. **Alfa Sınaması (*Alpha testing*)**
     4. **Beta Sınaması (*Beta testing*)**

### 2.2 Birim Sınamaları (Unit Testing), TDD ve Vekil Kod (Stub / Dummy)

**Birim sınaması (*unit testing*)**, teknik ekibin yaptığı en küçük yazılım bileşeninin sınanmasıdır; nesneye yönelik programlamada (**NYP**) **bireysel sınıfların ve metotlarının** sınanmasına karşılık gelir (ekrandan, 01:10:00).

- **Birim Sınamaları Ne Zaman Tasarlanır? (ekrandan, 01:10:00):**
  1. **Kodlamadan Önce — Çevik Yaklaşım (TDD: *Test Driven Design*):**
     - Çevik süreçlerde tercih edilen bu yaklaşımda önce sınıfın birim sınamaları (test senaryoları) yazılır, ardından yalnızca bu testlerden geçecek kod yazılır.
     - **TDD'nin Temel Felsefesi:** İyi bir tasarımın ölçütlerinden biri, *problem alanının alt kırılımlara ayrıldığı düzeyde tasarımın da alt kırılımlara ayrılabilmesidir*. TDD savunucularına göre, eğer bir bileşeni daha kodlamadan önce tekil sorumluluklar bazında yeterince ince kırılımda sınayamıyorsanız (bir testi koşturduğunuzda 2–3 farklı işi aynı anda sınamak zorunda kalıyorsanız), **tasarımınızda hata yapmışsınız (tasarımınız kaba kalmış) demektir**. Kod yazmadan önce test tasarlamak, bu tasarım kusurunu henüz kodlama başlamadan yakalamayı sağlar (ekrandan, 01:10:00).
  2. **Kodlama Sırasında:** Sınıfın birkaç metodu yazılır, hemen testleri hazırlanır; sonra diğer metotlar yazılıp testleri eklenir.
  3. **Kodlamanın Ardından:** Özellikle beyaz kutu (*white-box*) sınaması yapılacaksa kod tamamlandıktan sonra tüm dalları kapsayacak testler yazılır. Birim sınamalarının **yürütülmesi (koşturulması)** ise doğal olarak kodlama sırasında veya kodlamanın ardından yapılır (ekrandan, 01:10:00).

- **Bağlaşım (*Coupling*) Sorunu ve Vekil / Sahte Sınıf (*Stub, Dummy, Surrogate, Proxy*) Kullanımı (ekrandan, 01:10:00):**
  - Sıfır bağlaşımlı bir sistem olamayacağından, bir sınıfın tek başına yürütemediği sorumlulukları sınarken o metodun çağırdığı diğer sınıfların henüz kodlanmamış olması sınamayı kilitleyebilir. Tüm sınıfların bitmesini beklemek yerine, ihtiyaç duyulan diğer sınıfların yerine geçecek **vekil, sahte, yalancı kod/sınıf (*stub, dummy, surrogate, proxy*)** yazılır (ekrandan, 01:10:00).
  - Vekil sınıflar sadece ihtiyaç duyulan gerçek sınıflar kodlanana dek kullanılır ve ek kodlama yükünü azaltmak için **çok basit tutulur**: Örneğin çağrılan metot `boolean` döndürüyorsa gövdesine yalnızca `return true;` (işlemin her zaman başarılı olduğu varsayımı) veya sayısal bir metotsa sabit bir sayı dönüşü yazılır. Çağrılan metodun `false` döndürmesi durumunda oluşacak karmaşık etkileşim ve yan etkileri sınamak birim sınamasının değil, bir sonraki aşama olan **tümleştirme sınamalarının (*integration testing*)** görevidir (ekrandan, 01:10:00).

- **Birim Sınamalarında Aranacak Tipik Kodlama Hataları:**
  - Kalıtım hiyerarşisi ve çok biçimlilik (*polymorphism*) kaynaklı hatalar,
  - Karmaşık mantıksal ifadelerde `AND`, `OR`, `NOT` (`&&`, `||`, `!`) işleçlerinin birbirinin yerine yanlış kullanılması veya parantezleme / işlem önceliği hataları,
  - Sınır koşulu karşılaştırmalarında `<=` yerine `<` kullanılması sonucu döngülerin bir adım erken/geç bitmesi veya sonsuz döngüye girmesi,
  - Değişkenlere ilk değerlerin atanmaması veya hatalı atanması.

## 3. JUnit (3.x ve 4.x) Çatısı ile Birim Sınaması Mimarisi

Birim sınamalarını `main` metodu içinde uzun `if-else` ve `System.out.println("Test başarılı/başarısız")` bloklarıyla elle yazmak yerine, her programlama dili için geliştirilmiş **xUnit** ailesi çatıları (Java için **JUnit**, C# için **csUnit** / **NUnit**) kullanılır. JUnit, Eclipse ve NetBeans gibi IDE'lerle tümleşik olarak gelir.

### 3.1 JUnit Sürüm 3.x Mimarisi (Slayt 176) (ekrandan, 01:16:30)

JUnit 3.x sürümünde birim testi hazırlamanın kuralları ve sınıf ilişkileri şöyledir (ekrandan, 01:16:30):

```text
+-----------------------------------------------+     +---------------------------------------------+
| junit.framework                               |     | myPackage                                   |
|  +-----------------------------------------+  |     |  +----------------+       +---------------+ |
|  |                TestCase                 |  |     |  | TestAppClass1  | - - > |   AppClass1   | |
|  +-----------------------------------------+  |     |  +----------------+       +---------------+ |
|  | # setup()                               |<----------| + testXXX()    |<--+                     |
|  +-----------------------------------------+  |     |  +----------------+   |   +---------------+ |
|                       |                       |     |                       +---|    TestAll    | |
|                       v                       |     |  +----------------+   |   +---------------+ |
|  +-----------------------------------------+  |     |  | TestAppClass2  |<--+   | + suite():Test| |
|  |                 Assert                  |  |     |  +----------------+       +---------------+ |
|  +-----------------------------------------+  |     |  | + testYYY()    | - - > +---------------+ |
|  | + assertEquals(beklenen, sonuc: Object) |  |     |  +----------------+       |   AppClass2   | |
|  | + assertNotEquals(Object, Object)       |  |     |                           +---------------+ |
|  | + assertTrue(boolean)                   |  |     +---------------------------------------------+
|  | + assertFalse(boolean)                  |  |
|  | + assertNull(Object)                    |  |
|  | + assertNotNull(Object)                 |  |
|  +-----------------------------------------+  |
+-----------------------------------------------+
```

1. **Test Sınıfları ve Kalıtım Zorunluluğu:** Uygulama paketimizdeki (`myPackage`) her iş sınıfı (`AppClass1`, `AppClass2`) için adı büyük `T` ile **`Test`** kelimesiyle başlayan ayrı bir test sınıfı (`TestAppClass1`, `TestAppClass2`) oluşturulur ve bu sınıflar **`junit.framework.TestCase`** sınıfından kalıtımla (`extends TestCase`) türetilir (ekrandan, 01:16:30).
2. **`testXXX()` Metotları ve `Assert` Sınıfı:** Test sınıflarının içine adı küçük **`test`** ile başlayan `public void testXXX()` metotları yazılır. Bu metotların içinde `junit.framework.Assert` sınıfının statik doğrulama (*assertion*) metotları çağrılır (ekrandan, 01:16:30):
   - **`assertEquals(beklenen, sonuc : Object)`:** İlk parametre **beklenen (olması gereken)** sonucu, ikinci parametre ise sınanan metottan **elde edilen** sonucu alır; ikisi eşitse test başarılı olur.
   - **`assertNotEquals(Object, Object)`:** İki nesnenin birbirine eşit olmamasını sınar.
   - **`assertTrue(boolean)` / `assertFalse(boolean)`:** Verilen mantıksal ifadenin `true` veya `false` olmasını sınar.
   - **`assertNull(Object)` / `assertNotNull(Object)`:** Bir nesne referansının `null` olup olmadığını sınar.
   - *İsteğe Bağlı Açıklama Parametresi:* Tüm `assert...` metotları aşırı yüklenmiştir (*overloaded*); ilk parametre olarak `String` tipinde bir hata açıklama mesajı alabilirler (test başarısız olursa bu mesaj raporlanır).
3. **`# setUp()` Metodu ile Sahneyi Hazırlama:** Bir testi çalıştırmadan önce nesneleri oluşturmak ve aralarındaki ortak ilişkileri kurmak ("sahneyi hazırlamak") gerekir. `TestCase` sınıfından miras alınan `# setUp()` metodu ezilerek (*override* edilerek) bu ortak hazırlık kodları içine yazılır. **`TestCase.setUp()` metodu, sınıftaki her bir `testXXX()` metodu çalışmadan önce sıfırdan yeniden çalıştırılır**; böylece bir testin nesneler üzerinde yaptığı değişiklikler sonraki testi etkilemez (ekrandan, 01:16:30).
4. **`TestAll.suite()` ile Testleri Birleştirme:** Birden fazla test sınıfını (`TestAppClass1`, `TestAppClass2`) tek seferde çalıştırmak için `TestAll` sınıfında **`public static Test suite()`** metodu tanımlanır, `TestSuite` nesnesi oluşturulup `suite.addTestSuite(TestAppClass1.class)` ile sınıflar eklenir (ekrandan, 01:16:30).

### 3.2 JUnit Sürüm 4.x Yenilikleri: Notasyon (Annotation) ve İstisna (Exception) Desteği (Slayt 177)

JUnit 4.x (ve 5.x) sürümlerinde geriye dönük uyumluluk korunmakla birlikte (3.x kodları yine çalışır), iki önemli yetenek eklenmiştir (ekrandan, 01:23:30):
1. **Notasyon (*Annotation*) Desteği (`@Before`, `@Test`):**
   - Notasyonlar (`@...`), derleyici için yorum (*comment*) gibi davranan ancak kaynak kod üzerinde çalışan üçüncü parti araçlara ve çatılara (ör. JUnit'e) direktif ileten büyük/küçük harf duyarlı (*case-sensitive*) işaretlerdir.
   - Artık test sınıflarının `TestCase` sınıfından kalıtımla türetilmesi gerekmez.
   - Sınama metotlarının adlarını `test` kelimesi ile başlatmak zorunlu değildir; ilgili metotların başına **`@Test`** notasyonu koymak yeterlidir.
   - `setUp` adlı metodun yerine ise **`@Before`** notasyonu gelmiştir (başına `@Before` konulan herhangi bir metot her `@Test` metodundan önce otomatik çalışır) (ekrandan, 01:23:30).
2. **İstisna (*Exception*) Sınaması Desteği (`@Test(expected=...)`):**
   - JUnit 3.x sürümünde test sırasında bir *exception* fırlatılırsa program akışı kesiliyor ve bir metodun hatalı girdide gerçekten beklenen istisnayı fırlatıp fırlatmadığı doğrudan sınanamıyordu.
   - JUnit 4.x ile birlikte `@Test` notasyonuna `expected` parametresi verilerek beklenen istisnanın fırlatılıp fırlatılmadığı sınanabilir; istisna fırlatılırsa test **başarılı** sayılır ve akış kesilmeden bir sonraki test metoduna geçilir (ekrandan, 01:23:30):

```java
@Before
public void setUp() { /* Preparations */ }

@Test
public void testSomething() { /* Do test */ }

@Test(expected=SomeException.class)
public void testTheException() throws Exception {
    doSomethingThatCreatesTheException();
}
```

## 4. Video Kaset Kiralama Uygulaması Üzerinde JUnit Birim Testleri ve Hata Ayıklama

Hoca, Martin Fowler'ın *Refactoring: Improving the Design of Existing Code* (Addison-Wesley, 1999) kitabından aldığı **Video Kaset Kiralama** örneği (9. yeniden düzenleme adımındaki `fowler_09` paketi) üzerinden JUnit testlerinin nasıl yazıldığını ve Eclipse üzerinde nasıl koşturulduğunu göstermiştir (ekrandan, 01:31:40).

### 4.1 Video Kaset Kiralama Tasarımı (`Customer`, `Rental`, `Movie`) ve Sıralama Şeması

Sistemde müşteriler (`Customer`) çeşitli filmleri (`Movie`) belirli gün sayılarıyla kiralarlar (`Rental`). Tıpkı *NextGenPOS* örneğinde `Satış` ile `Ürün` arasına `SatışKalemi` sınıfının konulması gibi, burada da `Customer` ile `Movie` arasına kiralama işlemini temsil eden **`Rental`** sınıfı konulmuştur (ekrandan, 01:31:40):

```text
+------------------------------------------+
|                  Movie                   |
+------------------------------------------+
| - _priceCode : int                       |
+------------------------------------------+
| + getCharge( daysRented : int ) : double |
| + getBonus( daysRented : int ) : int     |
+------------------------------------------+
                     ^ 1
                     |
                     | 1
+------------------------------------------+
|                  Rental                  |
+------------------------------------------+
| - _daysRented : int                      |
+------------------------------------------+
| + getCharge() : double                   |
| + getBonus() : int                       |
| + getMovieTitle() : String               |
+------------------------------------------+
                     ^ *
                     |
                     | 1
+------------------------------------------+
|                 Customer                 |
+------------------------------------------+
|                                          |
+------------------------------------------+
| + statement()                            |
| + getTotalCharge() : double              |
| + getTotalBonus() : int                  |
+------------------------------------------+
```

**`Customer.statement()` Sıralama Şeması (Slayt 178) ve Tasarım İlkeleri (ekrandan, 01:31:40):**
1. **`Customer` ile `Movie` Arasında Bağlaşımı (*Coupling*) Düşürme:**
   - `Kullanıcı` $\rightarrow$ `aCustomer.statement()` metodunu çağırdığında, müşteri nesnesi tüm kiralama kayıtları için (`*[for all rentals]`) önce `aRental.getMovieTitle()` metodunu çağırır, `aRental` da `aMovie.getTitle()` metodunu çağırarak film adını döndürür; ardından `aCustomer` $\rightarrow$ `aRental.getCharge()` $\rightarrow$ `aMovie.getCharge(_daysRented)` zinciriyle o kiralamanın ücretini alır ve makbuz satırını oluşturur (ekrandan, 01:31:40).
   - *Neden `aCustomer` doğrudan `aRental.getMovie().getTitle()` çağırmıyor?* Eğer `Customer` sınıfı `Movie` nesnesini alıp onun metodunu doğrudan çağırsaydı, `Customer` sınıfından `Movie` sınıfına doğrudan bir kullanma (`<<uses>>` bağımlılık) oku doğacak ve **bağlaşım (*coupling*) yükselecekti**. Erişimi `Rental` üzerinden katmanlı yapmak bağlaşımı düşürür.
2. **Geçici Değişken (*Temporary Variable*) Kullanmama vs. Performans Dengesi:**
   - İlk döngüde her bir kiralama satırı oluşturulurken `getCharge()` zaten çağrıldığı hâlde, döngü bittikten sonra toplam borcu hesaplamak için `getTotalCharge()` içinde tüm kiralamalar için `getCharge()` ikinci kez çağrılır ve ardından `getTotalBonus()` içinde tüm kiralamalar için `getBonus()` çağrılır (ekrandan, 01:31:40).
   - *Refactoring* yaklaşımında metotların uzamasını önlemek ve *"böl-parçala-yönet"* ilkesini korumak için ara sonuçları geçici değişkenlerde biriktirmek yerine ayrı metotlara (`getTotalCharge()`, `getTotalBonus()`) bölmek tercih edilir. Aynı bilgisayar belleğinde yapılan basit çarpma/toplama işlemlerinin iki kez çalışması mikroişlemci için ihmal edilebilir düzeydedir; ancak işlemler ağ (*network*) üzerinden uzak bir sunucuya veya banka servisine gidip geliyorsa ağ gecikmesi (*network latency*) darboğaz yaratacağı için o durumda geçici değişken kullanılmalıdır.

### 4.2 Uygulama Sınıflarının (`Customer.java`, `Rental.java`, `Movie.java`) Kaynak Kodları

Hoca basılı kitaplarda sözdizimi renklendirmesi (*syntax highlighting*) olmadığı için Martin Fowler'ın üye alanları yerel değişkenlerden ve parametrelerden ilk bakışta ayırt etmek amacıyla C/C++ geleneğindeki gibi alt çizgi (`_name`, `_rentals`, `_daysRented`, `_priceCode`) ile başlattığını açıklamıştır (ekrandan, 01:40:00).

**1. `Customer.java` (ekrandan, 01:40:00):**
```java
package fowler_09;
import java.util.*;

public class Customer {
    private String _name;
    private Vector<Rental> _rentals = new Vector<Rental>();
    public Customer (String name){
        _name = name;
    }
    public void addRental(Rental arg) {
        _rentals.addElement(arg);
    }
    public String getName (){
        return _name;
    }
    public String statement( ) {
        Enumeration<Rental> rentals = _rentals.elements();
        String result = "Rental Record for " + getName() + "\n";
        while (rentals.hasMoreElements()) {
            Rental aRental = (Rental) rentals.nextElement();
            //show figures for this rental
            result += "\t" + aRental.getMovieTitle()+ "\t" +
                String.valueOf(aRental.getCharge()) + "\n";
        }
        //add footer lines
        result += "Amount owed is " + String.valueOf(getTotalCharge()) + "\n";
        result += "You earned " + String.valueOf(getTotalBonus()) +
            " frequent renter points";
        return result;
    }
    public double getTotalCharge() {
        double result = 0;
        Enumeration<Rental> rentals = _rentals.elements();
        while (rentals.hasMoreElements()) {
            Rental each = (Rental) rentals.nextElement();
            result += each.getCharge();
        }
        return result;
    }
    public int getTotalBonus() {
        int result = 0;
        Enumeration<Rental> rentals = _rentals.elements();
        while (rentals.hasMoreElements()) {
            Rental each = (Rental) rentals.nextElement();
            result += each.getBonus();
        }
        return result;
    }
}
```

**2. `Movie.java` ve Kira/Bonus Kuralları (ekrandan, 01:45:40):**
- Sistemde üç tür film fiyat kodu (`public static final int`) vardır: **`REGULAR = 0`** (Normal film), **`NEW_RELEASE = 1`** (Yeni çıkan film) ve **`CHILDRENS = 2`** (Çocuk filmi). Yeni çıkan bir film birkaç ay sonra normal film kategorisine düşürülebileceği için `setPriceCode(int)` metodu da bulunur (ancak hoca `switch-case` yerine `Movie` üst sınıfından `Regular`, `NewRelease`, `Childrens` alt sınıflarını türetip çok biçimlilik [*polymorphism*] kullanmanın en iyi tasarım olacağını belirtmiştir) (ekrandan, 01:45:40):

```java
package fowler_09;

public class Movie {
    public static final int CHILDRENS = 2;
    public static final int REGULAR = 0;
    public static final int NEW_RELEASE = 1;
    private String _title;
    private int _priceCode;

    public Movie(String title, int priceCode) {
        _title = title;
        _priceCode = priceCode;
    }
    public int getPriceCode() { return _priceCode; }
    public void setPriceCode(int arg) { _priceCode = arg; }
    public String getTitle (){ return _title; }

    public double getCharge( int daysRented ) {
        double result = 0;
        switch ( getPriceCode() ) {
            case Movie.REGULAR:
                result += 2;
                if (daysRented > 2)
                    result += (daysRented - 2) * 1.5;
                break;
            case Movie.NEW_RELEASE:
                result += daysRented * 3;
                break;
            case Movie.CHILDRENS:
                result += 1.5;
                if (daysRented > 3)
                    result += (daysRented - 3) * 1.5;
                break;
        }
        return result;
    }

    public int getBonus( int daysRented ) {
        if ((getPriceCode() == Movie.NEW_RELEASE) && daysRented > 1)
            return 2;
        else
            return 1;
    }
}
```

- **Ücret ve Bonus Kurallarının Özeti (ekrandan, 01:45:40):**
  1. **Normal Film (`REGULAR = 0`):** İlk 2 gün için sabit **`2.0` birim**; 2 günü aşan her ek gün için **`1.5` birim/gün** (`2 + (daysRented - 2) * 1.5`).
  2. **Yeni Çıkan Film (`NEW_RELEASE = 1`):** Kiralanan her gün için **`3.0` birim/gün** (`daysRented * 3`).
     > **Ders sonrası not:** Hoca kodu sözlü anlatırken `NEW_RELEASE` filmler için *"kiraladığımız her gün için 2 lira yazılıyor"* demiştir (01:46:28); ancak ekrandaki `Movie.java` kodunun 31. satırında `result += daysRented * 3;` yazılıdır ve `TestCustomer.java` içindeki tüm beklenen test değerleri de günlük **`3.0` birim** üzerinden hesaplanmıştır (ekrandan, 01:45:40; ekrandan, 01:58:30; ekrandan, 02:00:00).
  3. **Çocuk Filmi (`CHILDRENS = 2`):** İlk 3 gün için sabit **`1.5` birim**; 3 günü aşan her ek gün için **`1.5` birim/gün** (`1.5 + (daysRented - 3) * 1.5`).
  4. **Bonus Puanı (`getBonus`):** Her kiralama işlemi standart olarak **`1` puan** kazandırır; yalnızca film **`NEW_RELEASE`** ise ve **1 günden uzun (`daysRented > 1`)** kiralanmışsa **`2` puan** kazandırır.

### 4.3 JUnit Test Sınıfları (`TestMovie`, `TestCustomer`, `TestAll`) ve Adım Adım Hesaplamalar

1. **`TestMovie.java`:** Üç farklı türde film oluşturup (*The Matrix* — `REGULAR`, *Monsters, Inc.* — `CHILDRENS`, *Surrogates* — `NEW_RELEASE`) fiyat kodlarının birbirinden farklı olduğunu `assertTrue("...", matrix.getPriceCode() != monster.getPriceCode())` gibi üç `assertTrue` çağrısıyla sınar.
2. **`TestCustomer.java` (ekrandan, 01:58:30; ekrandan, 02:00:00):**
   - `setUp()` metodunda `yunus = new Customer("Yunus Emre Selçuk");` müşterisi ile 4 adet film nesnesi (`matrix` — `REGULAR`, `monster` — `CHILDRENS`, `surrogate` — `NEW_RELEASE`, `terminator` — `NEW_RELEASE`) ilklendirilir. Kiralama (`addRental`) işlemleri her test senaryosunda farklı olduğu için `setUp()` içine konulmaz; her `test...()` metodunun kendi başında yapılır:

```java
package fowler_09;
import junit.framework.TestCase;

public class TestCustomer extends TestCase {
    private Customer yunus;
    private Movie matrix, monster, surrogate, terminator;

    protected void setUp() {
        yunus = new Customer("Yunus Emre Selçuk");
        matrix = new Movie("The Matrix", Movie.REGULAR);
        monster = new Movie("Monsters, Inc.", Movie.CHILDRENS);
        surrogate = new Movie("Surrogates", Movie.NEW_RELEASE);
        terminator = new Movie("Terminator Salvation", Movie.NEW_RELEASE);
    }

    public void testGetName() {
        String sonuc = yunus.getName();
        assertEquals("Yunus Emre Selçuk", sonuc);
    }

    public void testStatementWhenEmpty( ) {
        String sonuc = yunus.statement();
        String beklenen = "Rental Record for Yunus Emre Selçuk\n";
        beklenen += "Amount owed is 0.0\n";
        beklenen += "You earned 0 frequent renter points";
        assertEquals(beklenen, sonuc);
    }

    public void testStatementWithMoviesLongRent( ) {
        yunus.addRental( new Rental(matrix, 3) );
        yunus.addRental( new Rental(monster, 4) );
        yunus.addRental( new Rental(surrogate, 2) );
        String sonuc = yunus.statement();
        String beklenen = "Rental Record for Yunus Emre Selçuk\n";
        beklenen += "\tThe Matrix\t3.5\n";
        beklenen += "\tMonsters, Inc.\t3.0\n";
        beklenen += "\tSurrogates\t6.0\n";
        beklenen += "Amount owed is 12.5\n";
        beklenen += "You earned 4 frequent renter points";
        assertEquals(beklenen, sonuc);
    }

    public void testStatementWithMoviesShortRent( ) {
        yunus.addRental( new Rental(matrix, 1) );
        yunus.addRental( new Rental(monster, 1) );
        yunus.addRental( new Rental(surrogate, 1) );
        String sonuc = yunus.statement();
        String beklenen = "Rental Record for Yunus Emre Selçuk\n";
        beklenen += "\tThe Matrix\t2.0\n";
        beklenen += "\tMonsters, Inc.\t1.5\n";
        beklenen += "\tSurrogates\t3.0\n";
        beklenen += "Amount owed is 6.5\n";
        beklenen += "You earned 3 frequent renter points";
        assertEquals(beklenen, sonuc);
    }

    public void testNewReleaseRentalBonus( ) {
        yunus.addRental( new Rental(surrogate, 2) );
        yunus.addRental( new Rental(terminator, 1) );
        String sonuc = yunus.statement();
        String beklenen = "Rental Record for Yunus Emre Selçuk\n";
        beklenen += "\tSurrogates\t6.0\n";
        beklenen += "\tTerminator Salvation\t3.0\n";
        beklenen += "Amount owed is 9.0\n";
        beklenen += "You earned 3 frequent renter points";
        assertEquals(beklenen, sonuc);
    }
}
```

- **Test Senaryolarının Sayısal Doğrulaması (ekrandan, 01:58:30; ekrandan, 02:00:00):**
  - `testGetName()`: Çok basit görünse de müşteri adında Türkçe karakterler (`ü, ç, ş`) geçtiği için çalışma platformunun Türkçe karakter kodlamasını doğru destekleyip desteklemediğini de sınar.
  - `testStatementWithMoviesLongRent()` (Eşik gün sayılarını aşan uzun kiralamalar):
    - *The Matrix* (`REGULAR`, 3 gün): $2{,}0 + (3 - 2) \times 1{,}5 = 3{,}5$, bonus $= 1$.
    - *Monsters, Inc.* (`CHILDRENS`, 4 gün): $1{,}5 + (4 - 3) \times 1{,}5 = 3{,}0$, bonus $= 1$.
    - *Surrogates* (`NEW_RELEASE`, 2 gün): $2 \times 3{,}0 = 6{,}0$, bonus $= 2$ (`daysRented > 1`).
    - Toplam borç $= 3{,}5 + 3{,}0 + 6{,}0 = 12{,}5$; toplam bonus $= 1 + 1 + 2 = 4$ puan (ekrandan, 01:58:30).
  - `testStatementWithMoviesShortRent()` (Eşik gün sayılarını aşmayan 1'er günlük kısa kiralamalar):
    - *The Matrix* (1 gün $\le 2$): $2{,}0$ (bonus $1$); *Monsters, Inc.* (1 gün $\le 3$): $1{,}5$ (bonus $1$); *Surrogates* (1 gün): $1 \times 3{,}0 = 3{,}0$ (bonus $1$, çünkü `daysRented > 1` değil).
    - Toplam borç $= 2{,}0 + 1{,}5 + 3{,}0 = 6{,}5$; toplam bonus $= 1 + 1 + 1 = 3$ puan (ekrandan, 02:00:00).
  - `testNewReleaseRentalBonus()` (Yeni çıkan filmlerde 1 gün vs. 2 gün bonus farkı):
    - *Surrogates* (2 gün): ücret $= 2 \times 3{,}0 = 6{,}0$, bonus $= 2$; *Terminator Salvation* (1 gün): ücret $= 1 \times 3{,}0 = 3{,}0$, bonus $= 1$.
    - Toplam borç $= 6{,}0 + 3{,}0 = 9{,}0$; toplam bonus $= 2 + 1 = 3$ puan (ekrandan, 02:00:00).

3. **`TestAll.java` ile Test Suite Oluşturma ve Eclipse'te Çalıştırma:**
   - `TestAll` sınıfında `public static Test suite()` metodu içinde `TestSuite suite = new TestSuite("...");`, `suite.addTestSuite(TestMovie.class);` ve `suite.addTestSuite(TestCustomer.class);` çağrıları yapılarak `return suite;` döndürülür.
   - Eclipse'te projeye sağ tıklanıp `Build Path -> Configure Build Path -> Libraries -> Classpath -> Add Library -> JUnit` seçilerek JUnit kütüphanesi eklendikten sonra `TestAll.java` üzerinde `Run As -> JUnit Test` çalıştırıldığında 6 testin tamamı (`5` tanesi `TestCustomer`, `1` tanesi `TestMovie` içinde) yeşil çubukla (**Green Bar**) geçer.

### 4.4 Kasıtlı Hata (Bug) Ekleme, Failure Trace Analizi ve Gerileme Sınaması (Regression Testing)

Hoca JUnit'in hata yakalama gücünü göstermek için `Movie.java` içindeki `REGULAR` film hesaplamasında `(daysRented - 2) * 1.5` satırındaki `1.5` katsayısını kasıtlı olarak **`1`** yapmıştır:
- `TestAll` tekrar çalıştırıldığında JUnit çubuğu **kırmızıya** dönmüş ve 6 testten yalnızca **`testStatementWithMoviesLongRent`** testinin başarısız olduğunu göstermiştir.
- `Failure Trace` penceresinde `junit.framework.ComparisonFailure` hatasına çift tıklandığında, JUnit beklenen metin ile elde edilen metin arasındaki farkın başladığı yeri köşeli parantez içinde doğrudan işaretlemiştir:
  - *The Matrix* için beklenen `[3.5]` iken `[3.0]`, toplam borç için beklenen `[12.5]` iken `[12.0]` üretilmiştir.
- Buradan hatanın `REGULAR` filmlerin 2 günü aşan kiralama hesaplamasında olduğu anında tespit edilip `1` katsayısı tekrar `1.5` olarak düzeltilmiştir.
- **Gerileme Sınaması (*Regression Testing*):** Bir hata düzeltildikten sonra bu düzeltmenin başka bir yeri bozup bozmadığını doğrulamak için yapılan geriye dönük testlere **gerileme sınaması (*regression testing*)** denir. Yüzlerce test senaryosu olan büyük projelerde tüm testlerin çalışması saatler sürebileceğinden, düzeltme sonrasında önce yalnızca ilgili sınıfın testleri (`TestCustomer`) koşturulur, ardından tüm paket (`TestAll`) çalıştırılır.

## 5. Proje Raporu ve Birim Sınaması Hakkında Öğrenci Soruları

**Soru:** Proje raporunda *"Proje Alan Tanımı"* ve *"Kabul ve Kısıtlar"* diye iki ayrı bölüm isteniyor; bunların farkı nedir?

**Cevap:** **Proje Alan Tanımı**, proje föyünde size verilen temel gereksinimler metnidir. **Kabul ve Kısıtlar** ise grupların kendi projelerini zenginleştirmek, kullanım senaryosu metinlerinde **alternatif senaryolar** üretebilmek ve etkinlik/durum/sıralama şemalarında düz bir akış yerine döngü ve dallanmalar (*branching*) gösterebilmek amacıyla temel gereksinimlere ek olarak kendi tanımladıkları ek gereksinimler ve varsayımlardır.

**Soru:** Birim sınamasında (*unit test*) sınadığımız bir fonksiyonun veritabanı sorgusu (*database query*) çalıştırmasında bir sakınca var mıdır ve nasıl test edilir?

**Cevap:** Hiçbir sakınca yoktur. İki şekilde sınanabilir:
1. Sorgudan dönen kayıtların (*record*'ların) alanları bir `String` içinde birleştirilerek `sonuc` dizgesi oluşturulur; beklenen kayıt bilgileriyle elle oluşturulan `beklenen` dizgesiyle `assertEquals(beklenen, sonuc)` üzerinden karşılaştırılır.
2. Sorgudan dönen ilk kayıt nesnesi ile kurucu/*setter* metotları kullanılarak elle oluşturulan beklenen kayıt nesnesi doğrudan `assertEquals(beklenenNesne, sonucNesne)` ile karşılaştırılır (bunun doğru çalışması için ilgili sınıfın `equals` metodunun ezilmesi [*override* edilmesi] gerekebilir).

**Soru:** Tasarım aşamasında çizeceğimiz en az bir etkinlik (*activity*), bir durum (*state*) ve bir sıralama (*sequence*) diyagramının farklı kullanım senaryolarına mı ait olması gerekiyor?

**Cevap:** Evet, farklı kullanım senaryolarına ait olması hem senaryoların farklı yönlerini görmeyi sağlar hem de öğrencinin avantajınadır: Örneğin bir kullanım senaryosunda durumları tespit etmek zorsa onun için etkinlik veya sıralama şeması çizilir, durumların çok daha net görüldüğü başka bir kullanım senaryosu için ise durum şeması çizilir.

## Örnek Sorular

### Soru 1: Teknik Risk ile Proje Riski Ayrımı ve Etki–Olasılık Grafiği (derste sözlü ve ekrandan, 00:10:00; 00:27:30)

**Soru:**
a) Bir yazılım projesinde yeni çıkmış bir *framework* kullanılması veya eski kodların yeniden kullanım (*reuse*) oranının beklenenden düşük çıkması sonucunda proje bitiş tarihinin sarkması bir *proje riski* midir yoksa *teknik risk* midir? Neden?
b) Risk değerlendirmede oluşturulan 4 kadranlı Etki–Olasılık grafiğinde hangi kadran kesinlikle izlenir, hangi kadran kesinlikle izlenmez ve diğer iki kadran için nasıl karar verilir?

**Çözüm (derste verilen):**
- **a)** Her iki durumda da sonuç olarak proje takvimi sarksa bile, **kök neden** kullanılan yazılım geliştirme aracı/bileşeni ve kodlama süreci olduğu için bunlar proje riski değil, **teknik risk** olarak sınıflandırılır (ekrandan, 00:10:00).
- **b)** Sağ üst kadrandaki (**Olasılığı Yüksek – Etkisi Büyük**) riskler mutlaka proaktif olarak izlenir ve işlenir. Sol alt kadrandaki (**Olasılığı Düşük – Etkisi Küçük**) riskler ise izleme maliyetine değmeyeceği için kesinlikle izlenmez. Sol üst (**Olasılığı Düşük – Etkisi Büyük**) ve sağ alt (**Olasılığı Yüksek – Etkisi Küçük**) kadranların izlenip izlenmeyeceğine kurumun risk toleransına göre üst yönetim stratejik olarak karar verir (ekrandan, 00:27:30).

### Soru 2: Video Kiralama Sisteminde `statement()` Çıktısının ve JUnit `assertEquals` Değerinin Hesaplanması (ekrandan, 01:45:40; 01:58:30; 02:00:00)

**Soru:** `Movie` sınıfındaki kurallara göre (`REGULAR`: ilk 2 gün `2.0`, sonraki her gün `+1.5`; `NEW_RELEASE`: gün başına `3.0`; `CHILDRENS`: ilk 3 gün `1.5`, sonraki her gün `+1.5`; bonus puanı her kiralama için `1`, yalnızca 1 günden fazla kiralanan `NEW_RELEASE` için `2` puan):
Bir müşteri 3 günlüğüne *The Matrix* (`REGULAR`), 4 günlüğüne *Monsters, Inc.* (`CHILDRENS`) ve 2 günlüğüne *Surrogates* (`NEW_RELEASE`) kiraladığında `testStatementWithMoviesLongRent()` birim testinde `assertEquals` ile kontrol edilen her bir filmin ücreti, toplam borç (`Amount owed`) ve toplam bonus puanı (`frequent renter points`) kaç olur? Eğer `REGULAR` filmlerin ek gün katsayısı kodda yanlışlıkla `1.5` yerine `1` yazılırsa JUnit `Failure Trace` hangi değerlerde fark raporlar?

**Çözüm (derste verilen):**
1. **Doğru Kodla Beklenen Değerler (ekrandan, 01:58:30):**
   - *The Matrix* (`REGULAR`, 3 gün): $2{,}0 + (3 - 2) \times 1{,}5 = 3{,}5$, bonus $= 1$.
   - *Monsters, Inc.* (`CHILDRENS`, 4 gün): $1{,}5 + (4 - 3) \times 1{,}5 = 3{,}0$, bonus $= 1$.
   - *Surrogates* (`NEW_RELEASE`, 2 gün): $2 \times 3{,}0 = 6{,}0$, bonus $= 2$ ($2 > 1$ olduğu için).
   - **Toplam Borç (`Amount owed`):** $3{,}5 + 3{,}0 + 6{,}0 = 12{,}5$.
   - **Toplam Bonus:** $1 + 1 + 2 = 4$ puan.
2. **Hatalı Kodda (`1.5` yerine `1` yazıldığında) `Failure Trace` Çıktısı:**
   - *The Matrix* ücreti $2{,}0 + (3 - 2) \times 1 = 3{,}0$ olarak hesaplanır ve toplam borç $3{,}0 + 3{,}0 + 6{,}0 = 12{,}0$ olur. JUnit `ComparisonFailure` ekranında *The Matrix* satırında beklenen `[3.5]` iken `[3.0]`, toplam borç satırında ise beklenen `[12.5]` iken `[12.0]` üretildiğini köşeli parantezle işaretler.

## Dersin Toparlaması

Bu derste ilk olarak **Risk Yönetimi** kapsamında reaktif ve proaktif yaklaşımlar, yazılımda **proje riskleri, teknik riskler ve işletme riskleri**, geniş katılımlı **Özet Risk Tablosu**, 4 kadranlı **Etki–Olasılık Grafiği** ve erken uyarı işaretleri ile önlemleri içeren **Risk Bilgi Sayfası** incelenmiştir. İkinci bölümde **Yazılım Sınama Teknikleri**ne geçilerek kara kutu / beyaz kutu sınamaları ile doğrulama (*birim, tümleştirme*) ve geçerleme (*alfa, beta*) sınamaları tanımlanmış; **Birim Sınamaları (*Unit Testing*)**, **Sınama Odaklı Tasarım (TDD)** ve bağımlılıkları izole etmek için kullanılan **vekil/sahte kod (*stub, dummy, surrogate, proxy*)** kavramları açıklanmıştır. Son bölümde **JUnit 3.x ve 4.x** çatılarının mimarisi (`TestCase`, `Assert`, `setUp/@Before`, `testXXX/@Test`, `suite()`, `@Test(expected=...)`) gösterilmiş ve Martin Fowler'ın **Video Kaset Kiralama** örneği üzerinde birim testlerinin yazılması, çalıştırılması, `Failure Trace` ile hata ayıklama ve **gerileme sınaması (*regression testing*)** uygulamalı olarak gerçekleştirilmiştir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
