# Ders 5 Genişletilmiş Notu: Alan Modeli Oluşturulması, Nesneye Yönelik Tasarım Ölçütleri, Bağlaşım (Coupling) ve Uyum (Cohesion)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Nesneye Yönelik Çözümleme Süreci: Sınıfların Belirlenmesi ve 3 Seçim Kuralı
- 2. NextGenPOS Örneğinde Aday Varlıkların Elenmesi ve Sınıf/Üye Alan Kararları
- 3. Alan Modelinin (UML Sınıf Şeması) Çizilmesi, Satış Kalemi ve Primitive Obsession
- 4. Çözümleme Sürecinin Belgelendirilmesi (Artefact'ler)
- 5. Nesneye Yönelik Tasarım Sürecine Giriş ve 5 Tasarım Kalite Ölçütü
- 6. Düşük Bağlaşım (Low Coupling) ve Yüksek Uyum (High Cohesion)
- Örnek Sorular
- Dersin Toparlaması

## 1. Nesneye Yönelik Çözümleme Süreci: Sınıfların Belirlenmesi ve 3 Seçim Kuralı

Bir önceki derste doğal dille yazılmış gereksinimler belgesinden **kullanım öyküsü (*use case*)** metinlerinin ve **UML kullanım şemalarının (*use case diagrams*)** nasıl çıkarıldığı incelenmişti. Aslında kullanım senaryosu metni yazma, use case şeması çizme ve alan modeli oluşturma çalışmaları tek yönlü katı bir sırayla değil, birbirini besleyen **yinelemeli (*iterative*)** adımlar hâlinde yürütülür: şemayı çizerken fark edilen bir eksiklik senaryo metnine eklenir, senaryodaki adımlar ise alan modelindeki sınıfları şekillendirir.

**Alan Modeli (*Domain Model*)**, gerçek dünyadaki problem alanında bulunan varlıkların ve aralarındaki ilişkilerin yazılım dünyasına bir **UML Sınıf Şeması (*Class Diagram*)** olarak aktarılmasıdır. Çözümleme (analiz) aşaması **"Ne?"** sorusuna yanıt aradığı için, alan modelinde yalnızca **sınıflar, nesneler, üye alanlar (*attributes*) ve sınıflar arası ilişkiler** yer alır; işin **"Nasıl?"** yapılacağını belirten **üye metotlar (*methods*)** alan modelinde yer almaz, bir sonraki aşama olan tasarım aşamasına bırakılır.

Kullanıcı gereksinimleri belgesinden ve kullanım senaryolarından sınıfları elde etmek için şu pratik rehber (*rule of thumb*) uygulanır (ekrandan, 00:14:30):
1. **İsimlerin Taranarak Aday Sınıfların Elde Edilmesi:** Gereksinim paragrafı ve kullanım öyküsü metinleri cümle cümle okunarak içindeki **isimler (*nouns*)** listelenir; bunların her biri birer **aday sınıf (nesne adayı)** olur (dilbilgisel olarak isimler çoğunlukla varlık/nesnelere, sıfatlar üye alanlara, fiiller/eylemler ise tasarım aşamasında belirlenecek üye metotlara karşılık gelir) (ekrandan, 00:14:30).
2. **Üç Seçim Kuralı ile Sınama:** Listelenen her aday sınıf aşağıdaki **3 kuraldan en az birini** sağlamalıdır (ekrandan, 00:14:30):
   - **Kural 1 — Saklanan bilgi:** Sistemin çalışması süresince bu varlığın durumu (*state*) saklanmalıdır.
   - **Kural 2 — Gereksinim duyulan hizmetler:** Bu varlığın hizmetlerine ihtiyaç duyan başka varlıklar vardır.
   - **Kural 3 — Gerekli varlıklar:** Problemin çözümü ile ilgili bilgi üreten (hesaplama yapıp sonuç üreten) veya problemin çözümü için bilgi tüketen (bir hesaplama işlemine girdi sağlayan) varlıklardır.
3. **Üye Alan Olarak Değerlendirme:** Yukarıdaki üç kuraldan **birini bile** sağlayan adaylar alan modelimize gerçek bir **sınıf (*class*)** olarak dahil edilir; hiçbirini sağlayamayan adaylar ise ya kapsam dışı bırakılır ya da **bir başka sınıfın üye alanı (*attribute*)** olarak değerlendirilir (ekrandan, 00:14:30).

> **Ek bilgi (derste anlatılmadı):** Metinlerdeki isimleri (*nouns*) aday sınıflara, sıfatları niteliklere (*attributes*) ve fiilleri (*verbs*) metotlara eşleyerek nesneye yönelik model çıkarma tekniği, yazılım mühendisliği literatüründe büyük olasılıkla Russell J. Abbott (1983) ve Grady Booch tarafından popülerleştirilen **Dilbilgisel Analiz (*Grammatical / Noun-Phrase Analysis*)** yöntemi olarak bilinir.

## 2. NextGenPOS Örneğinde Aday Varlıkların Elenmesi ve Sınıf/Üye Alan Kararları

Hoca derste geçen hafta incelenen *NextGenPOS Perakende Satış Programı* gereksinim paragrafını ve *Satış İşlemi* kullanım öyküsünü (Giriş, Ana Öykü ve Alternatif Öyküler) baştan sona okuyarak isimleri Not Defteri'ne listelemiş, ardından her adayı yukarıdaki 3 kurala göre sınıf mı (`+`), üye alan mı yoksa elenecek mi (`-`) diye tartışmıştır (ekrandan, 00:52:00):

*(Not: Gereksinim metnindeki "yazılım", "program" ve "sistem" kelimeleri de birer isimdir ancak bizzat tasarladığımız sistemin kendisini ifade ettikleri için aday listesine alınmazlar. Benzer şekilde "harici bütçe sistemi", "harici envanter sistemi", "merkezi sunucu" ve "rapor" kavramları sistem katmanını ve ileri aşamaları ilgilendirdiği için çekirdek iş mantığına odaklanan bu ilk alan modeline dahil edilmemiştir.)*

Ekrandaki Not Defteri listesinde yer alan **18 adayın** tek tek analizi şöyledir (ekrandan, 00:52:00; ekrandan, 01:40:00):

1. **`Kasa` $\rightarrow$ `+` (Sınıf olarak alındı):**
   - *Değerlendirme:* Kasa birçok işlemi koordine eder: barkod okuyucudan gelen barkod bilgisi kasaya gider, ürün silme tuşuna kasada basılır, kasiyer market kapısından girerken değil kasanın başına geçtiğinde kasadaki yazılıma *login* olarak kimliğini doğrular ve yapılan tüm alışveriş işlemleri kasanın içinde saklanır. Ayrıca fiş basmak ve gün sonu hesaplamalarını yapmak için kasada tutulan satış kayıtlarına başvurulduğundan Kasa **üç kuralın üçünü de** sağlar.
2. **`Alış-veriş işlemi` $\rightarrow$ `-` (`Satış` ile eş anlamlı):**
   - *Değerlendirme:* Yapılan işlemlerin ve içindeki ürün/fiyat bilgilerinin saklanması şarttır (3 kuralı da sağlar). Ancak "alışveriş" kelimesi hem alış hem satış anlamı taşır; markete ana depodan veya yerel fırından ürün girişi (tedarik) gereksinimlerimizde yer almadığı ve odak noktamız müşteriye yapılan **satış** olduğu için bu kavram aşağıda geçen **`Satış`** adayı ile eş anlamlıdır. Modelde isim olarak `Satış` tercih edilmiş, mükerrer olmaması için `Alış-veriş işlemi` elenmiştir.
3. **`mali bilgiler` $\rightarrow$ `-` (Gerekli bilgiler aşağıda var):**
   - *Değerlendirme:* "Mali (parasal) bilgiler" çok yuvarlak ve genel bir ifadedir. Açılımı düşünüldüğünde ürünün fiyatı, ürünün KDV'si, satışın toplam bedeli ve tahsil edilen ödeme miktarını kapsadığı görülür; bunların tamamı listede zaten ayrı adaylar olarak yer aldığı için elenmiştir.
4. **`mal` $\rightarrow$ `-` (`Ürün` ile aynı):**
   - *Değerlendirme:* Aşağıda geçen **`Ürün`** adayı ile eş anlamlıdır; modelde daha kibar ve standart bir terim olan `Ürün` tercih edilmiştir.
5. **`müşteri` $\rightarrow$ `-` (*Loyalty card* vb. uygulama yok):**
   - *Değerlendirme:* Müşteri kasaya ürünlerle gelir, bazen bir ürünü çıkartmak ister, ödemeyi yapar ve ayrılır. Ancak dikkat edilirse müşterinin fiziksel olarak yaptığı her eylem sistemde **kasiyer** tarafından yürütülür (ürünü tezgâhtan alıp okutan, silen, nakit parayı veya kredi kartını alıp kasaya/POS'a geçiren hep kasiyerdir). Müşterinin kendisi sistemde bilgi üretmez, tüketmez ve mevcut gereksinim metninde müşterinin alışveriş örüntülerini takip eden bir **müşteri sadakat kartı (*loyalty card*)** uygulaması geçmemektedir. Bu nedenle `Müşteri` 1, 2 ve 3. kuralların hiçbirini sağlamaz ve **sınıf olarak alınmaz** (eğer gereksinimlerde *Loyalty Card* olsaydı müşteri bilgileri saklanacağı için alınırdı).
6. **`fiş` $\rightarrow$ `-` (Ürün garanti vb. işlemleri yok — türetilen varlık):**
   - *Değerlendirme:* Bir market fişinin üzerinde ne yazdığı incelendiğinde; en üstte firma ve **şube** adı, şube adresi, vergi numarası, alışverişin **tarihi/saati**, satışı yapan **kasiyerin** adı, alınan her **ürünün** tanımı, adedi (**satış kalemi**), fiyatı, **KDV** oranı ve en altta **toplam bedel** yer aldığı görülür. Yani fişin üzerindeki bütün bilgiler aslında diğer varlıklardan toplanıp belirli bir şablona göre kağıda basılan **türetilmiş (*derived*)** bilgilerdir; fişin kendine özgü bağımsız bir verisi yoktur. Eğer mağaza elektronik eşya satıyor olsaydı ve ileride **ürün garanti / fatura doğrulama** işlemleri için fişin kendisini sorgulamak gerekseydi saklanabilirdi; ancak mevcut gereksinimlerde garanti takibi olmadığından fiş ayrı bir sınıf yapılmaz, `Kasa` sınıfının içindeki bir fiş basma fonksiyonuna gömülür.
7. **`satış` $\rightarrow$ `+` (Sınıf olarak alındı):**
   - *Değerlendirme:* Yukarıda `Alış-veriş işlemi` maddesinde tartışıldığı üzere her satışın durumu saklanmalı ve raporlanmalıdır; temel sınıflarımızdan biridir.
8. **`KDV` $\rightarrow$ `-` (Ürüne bağlı bir bilgi — üye alan):**
   - *Değerlendirme:* KDV oranı saklanması ve fişte/hesaplamalarda kullanılması gereken çok önemli bir bilgidir (eskiden çalışanlar ve emekliler fiş toplayıp KDV/vergi iadesi alırdı; bugün de firmalar topladıkları KDV'yi hazineye öder). Ancak problem alanında tek başına bağımsız bir "KDV nesnesi" yoktur; KDV **ürüne bağlı bir bilgidir** (örneğin kağıt mendilin KDV'si %8 veya %18 iken pırlantanın KDV'si %1 olabilmektedir). Bu nedenle `KDV` ayrı bir sınıf yapılmaz, **`Ürün` sınıfının bir üye alanı (*attribute*)** olarak alınır.
9. **`Şirket` $\rightarrow$ `+` (Şimdilik alınmadı — merkezi stok yönetimi düşünülmüyor):**
   - *Değerlendirme:* Normalde geçerli bir sınıftır; ancak şubeler arası merkezi stok yönetimi işlemleri bu aşamada kapsam dışı bırakıldığı için çekirdek alan modeline eklenmemiştir.
10. **`Şube` $\rightarrow$ `+` (Sınıf olarak alındı):**
    - *Değerlendirme:* Fişin üzerine basılacak şube adı, adresi ve vergi numarası bilgilerini saklar; ayrıca içindeki kasaları ve o şubede satılan ürünlerin listesini barındırır.
11. **`Kasiyer` $\rightarrow$ `+` (Sınıf olarak alındı):**
    - *Değerlendirme:* Kasiyer fiziksel olarak barkod okutmada bir aracı olsa da, satış öncesinde kimlik doğrulaması (*login*) yapılması zorunludur ve basılan her fişin üzerinde o satışı hangi kasiyerin yaptığı yazar. Dolayısıyla kasiyerin durum bilgisi (`ad`, `ID` / sicil numarası) sistemde saklanmalıdır (1. kuralı sağlar). *(Hoca ders notundaki hazır şemada `Kasiyer` sınıfının yer almadığını, ancak bu analiz sonucunda derste çizilen şemaya `Kasiyer` sınıfını da eklediklerini belirtmiştir.)*
12. **`Ödeme` $\rightarrow$ `+` (Sınıf olarak alındı):**
    - *Değerlendirme:* İlk bakışta ödeme yalnızca satışın toplam bedeli gibi görünse de, kullanım öyküsünün ilgi alanlarında *"kasa açığı kasiyerin maaşından kesilir"* kuralı yer almaktadır. Kasiyer para üstünü yanlış vermiş veya POS cihazına tutarı hatalı girmiş olabilir; gün sonu raporunda yapılan satışların toplam bedeli ile kasadaki fiili ödemelerin (nakit ve kart sliplerinin) birbirini tutup tutmadığını karşılaştırmak için **tahsil edilen ödemenin** ayrı bir varlık olarak saklanması şarttır.
13. **`ürün` $\rightarrow$ `+` (Sınıf olarak alındı):**
    - *Değerlendirme:* Ürünün barkodu, tanımı, fiyatı ve KDV oranı saklanmalı ve hem satış kalemi oluşturmada hem de toplam bedel/fiş hesaplamalarında kullanılmalıdır (3 kuralı da sağlar).
14. **`barkod` $\rightarrow$ `-` (Ürüne bağlı bir bilgi — üye alan):**
    - *Değerlendirme:* KDV gibi barkod da **`Ürün` sınıfına bağlı bir üye alandır** ve ürünün tekil tanımlayıcısıdır (*primary key / ID*).
15. **`Satış kalemi` $\rightarrow$ `+` (Sınıf olarak alındı):**
    - *Değerlendirme:* Kullanım öyküsünün 4. adımında *"Sistem bir satış kalemi maddesi oluşturur"* denilerek açıkça belirtilmiştir; bir satışta hangi üründen kaç adet alındığını tutmak ve ara toplamları hesaplamak için zorunlu bir sınıftır.
16. **`ürün tanımı` $\rightarrow$ `-` (Ürüne bağlı bir bilgi — üye alan):**
    - *Değerlendirme:* "Hamidiye Su 0.5 L" gibi metinsel açıklama bilgisidir; **`Ürün` sınıfının üye alanıdır**.
17. **`ürün fiyatı` $\rightarrow$ `-` (Ürüne bağlı bir bilgi — üye alan):**
    - *Değerlendirme:* Ürünün birim fiyatıdır; **`Ürün` sınıfının üye alanıdır**.
18. **`Toplam bedel` $\rightarrow$ `-` (Satış işlemine bağlı bilgi — üye alan):**
    - *Değerlendirme:* **`Satış` sınıfının bir üye alanı** olarak eklenir (ancak tasarım aşamasında üye alan olarak kalıp kalmaması ayrıca tartışılmıştır).

## 3. Alan Modelinin (UML Sınıf Şeması) Çizilmesi, Satış Kalemi ve Primitive Obsession

Elde edilen 7 sınıf (**`Kasa`, `Satış`, `Şube`, `Kasiyer`, `Ödeme`, `Ürün`, `Satış Kalemi`**) ve üye alanları *Violet UML Editor* üzerinde birleştirilerek alan modeli oluşturulmuştur (ekrandan, 01:40:00; ekrandan, 01:50:30):

```text
+-----------------------+ 1          1 +------------------------+
|     Satış Kalemi      |------------->|          Ürün          |
+-----------------------+              +------------------------+
| - adet : int          |              | - barkod, tanım:String |
| - ürün : Ürün         |              | - KDV, fiyat : double  |
+-----------------------+              +------------------------+
           ^                                       ^
      1..* | (içerir)                            * | (stoklanır)
           |                                       |
         1 |                                     1 |
+-----------------------+              +------------------------+
|         Satış         | *          1 |          Şube          |
+-----------------------+<-------------|------------------------+
| - kalemler :          |  (kaydeder)  | - ad, adres : String   |
|     SatışKalemi[]     |       |      | - vergiNo : int        |
| - ödeme : Ödeme       |       |      +------------------------+
| - kasiyer : Kasiyer   |       |                  <>
| - toplamBedel: double |       |                  |
| - tarihSaat : Date    |       |             1..* | (yer alır)
+-----------------------+       |                  |
      1 |         1 |           |      +------------------------+
        |           |           '------|          Kasa          |
      1 v         1 v                  +------------------------+
+-------------+ +---------------+      | - şubesi : Şube        |
|    Ödeme    | |    Kasiyer    |      | - satışlar : Satış[]   |
+-------------+ +---------------+      +------------------------+
| - miktar :  | | - ad, ID :    |
|     double  | |     String    |
+-------------+ +---------------+
```

### 3.1 Üye Alanların Veri Tipleri ve Hesaplanan Alan Tartışması

- **`Şube` Sınıfı:** Fişe basılacak `- ad, adres : String` ve `- vergiNo : int` (veya üzerinde matematiksel işlem yapılmadığı için `String`) alanlarını içerir (ekrandan, 01:40:00).
- **`Kasiyer` Sınıfı:** `- ad, ID : String` alanlarını içerir. `ID` alanı sicil numarası olabileceği gibi harf içeren bir kısaltma da (örneğin bölümde öğretim üyelerinin isim baş harfleriyle `YES`, `OK` şeklinde kodlanması gibi) olabileceği için `String` seçilmiştir (ekrandan, 01:40:00).
- **`Ürün` Sınıfı:** `- barkod, tanım : String` ve `- KDV, fiyat : double` alanlarını içerir.
  > **Hocanın vurgusu (`barkod` neden `int` değil `String`?):** Barkodlar rakamlardan oluşuyor gibi görünse de iki nedenden ötürü sayısal değil **`String`** olarak tutulmalıdır: 1) Barkodun ilk basamağı `0` olabilir ve tam sayı (`int`/`long`) tipinde tutulduğunda baştaki sıfırlar kaybolur, 2) `EAN` ve `UPC` gibi barkod standartlarında en sondaki tutarlılık/geçerlilik kontrol basamağı (*checksum digit*) `10` çıkabilir ve tek karakterde `10` değerini göstermek için `X` harfi kullanılır.
- **`Satış` Sınıfında `- tarihSaat : Date` ve `- toplamBedel : double`:**
  - Fiş üzerinde satışın yapıldığı gün ve saat yer aldığı için `Satış` sınıfına `- tarihSaat : Date` alanı eklenmiştir (ekrandan, 01:50:30).
  - `toplamBedel` alanı analiz aşamasında `Satış` sınıfına yazılabilir (veya veresiye/senetle eksik ödeme alınan senaryolarda satış tutarını görmek için tutulabilir). Ancak tüm `Satış Kalemi` nesnelerinin alt toplamları (`adet * fiyat * (1 + KDV)`) toplanarak saniyenin milyonda biri sürede hesaplanabildiği için —bir müşteri tek seferde en fazla ~100 kalem ürün alır— tasarım aşamasında `toplamBedelCalcula()` gibi bir metot yazılıp bu üye alan bellekten kaldırılabilir.

### 3.2 `Satış Kalemi` Sınıfının Zorunluluğu ve *Primitive Obsession* Kusuru

Kullanım senaryosu metninde *"Sistem bir satış kalemi oluşturur"* diye açıkça yazmasaydı bile, `Satış` ile `Ürün` arasındaki ilişkiyi kurarken **`Satış Kalemi`** sınıfının varlığını kendimiz keşfetmek zorunda kalırdık. Hoca bunun nedenini üç adımlı bir düşünce deneyiyle kanıtlamıştır:
1. **Yanlış Yaklaşım 1 (`adet` alanını `Ürün` sınıfına koymak):** Bir müşteri 0,5 L sudan 3 adet, başka bir müşteri 2 adet, bir diğeri 1 adet alabilir. Eğer `adet` bilgisini `Ürün` sınıfının içine koyarsak, her satış işlemi için aynı su ürününden yeni bir nesne oluşturmamız veya market rafındaki 1000 şişe suyun her biri için bellekte ayrı bir nesne tutmamız gerekir ki bu nesne sayısını milyonlara çıkarır. Oysa sistemde her ürün çeşidi için yalnızca **tek bir `Ürün` nesnesi** (katalog kaydı) bulunmalıdır.
2. **Yanlış Yaklaşım 2 (`adet` alanını doğrudan `Satış` sınıfına koymak):** Bir satış işleminde müşteri yalnızca su almaz; 3 şişe su, 2 paket şeker ve 1 adet kalem alır. `Satış` sınıfına tek bir `adet : int` alanı koyarsak bunun suya mı, şekere mi yoksa kaleme mi ait olduğu bilinemez.
3. **Yanlış Yaklaşım 3 (`Satış` içinde paralel `ürünler[]` ve `adetler[]` dizileri tutmak — *Primitive Obsession*):**
   Eğer bir geliştirici `Satış` sınıfının içine:
   ```java
   Ürün[] ürünler;
   int[] adetler;
   ```
   şeklinde iki ayrı dizi koyup *"ürünler dizisinin $i$. indisindeki ürünün adedi, adetler dizisinin $i$. indisindeki tam sayıdır"* mantığıyla kod yazarsa, bu yapı Nesneye Yönelik Programlamanın doğasına tamamen aykırıdır ve literatürde **İlkel Veri Tipi Takıntısı (*Primitive Obsession*)** olarak adlandırılan tasarım kusuruna (*code smell*) yol açar.
4. **Doğru Nesneye Yönelik Çözüm (`Satış Kalemi` ara sınıfı):** `Satış` ile `Ürün` arasına **`Satış Kalemi`** sınıfı yerleştirilir (eğer müşteri bu terimi söylemeyi unuttuysa bu bir *beklenen gereksinimdir* ve müşteriye sorularak terminolojisi doğrulanır). Bir `Satış` nesnesi `1..*` adet `Satış Kalemi` içerir; her `Satış Kalemi` ise yalnız `1` `Ürün` nesnesine işaret eder ve o üründen kaç tane alındığını kendi `- adet : int` alanında tutar (ekrandan, 01:40:00).

### 3.3 Sınıflar Arası İlişkilerin Yönü ve Çokluk (Multiplicity) Kuralları

> **Hocanın vurgusu:** Alan modelinde hiçbir sınıf diğerlerinden kopuk, ilişkisiz bir "adacık" olarak kalamaz ve hiçbir sınıf tamamen üye alansız olamaz (sırf metotlardan oluşan bir sınıf varsa sorumluluk yanlış yere atanmış demektir; sorumluluk, o işi yapmak için gereken veriye en çok sahip olan sınıfa verilmelidir).

Öte yandan çift yönlü (*bidirectional*) sahiplik ilişkileri nesneye yönelik programlamada ek tutarlılık kontrolleri ve kodlama yükü getirdiğinden, **yalnızca problem çözümü için zorunlu olan yönlerde** ok kurulmalıdır:
- **`Şube <>--- (1..*) Kasa`:** Bir şubede en az 1 kasa olmak zorundadır (`0` kasalı şube olamaz, bu yüzden `*` değil `1..*` yazılır). Kasa şubenin demirbaşı olduğu için **parça-bütün (*aggregation*, içi boş elmas `<>`)** ilişkisi kurulmuştur. Elmas sembolü aynı zamanda `Kasa`'dan `Şube`'ye doğru da bir ok olduğu anlamına gelir; çünkü `Kasa` fiş basarken şube adını ve adresini `Şube` nesnesinden (`- şubesi : Şube`) okuyacaktır.
- **`Kasa (1) ---> (*) Satış` (`kaydeder`):** Kasa kendi üzerinden yapılan satışları (`- satışlar : Satış[]`) kaydeder. Gün sonunda veriler merkezi sunucuya aktarılıp kasa sıfırlandığında veya sabah kasa ilk açıldığında henüz hiç satış yapılmamış (`0` satış) olabileceği için satış tarafının çokluğu `1..*` değil **`*` (`0..*`)** olarak bırakılır. Fiş basma sorumluluğu `Kasa`'ya verildiği için `Satış`ın `Kasa`yı bilmesine gerek yoktur (tek yönlü ok).
- **`Satış (1) ---> (1) Kasiyer` ve `Satış (1) ---> (1) Ödeme`:** Gün içinde aynı kasada farklı kasiyerler *login/logoff* olabileceği için `Kasiyer` doğrudan `Kasa`ya değil, yaptığı `Satış`a (`1..1`) bağlanır. Her satışın `1..1` ödemesi vardır.
- **`Şube (1) ---> (*) Ürün` (`stoklanır`):** Kasiyer barkodu okuttuğunda `Kasa`, bu barkodun hangi `Ürün` nesnesine ait olduğunu nereden öğrenecektir? Şubede satılan ürünlerin listesi `Şube` sınıfında tutulduğu için `Kasa` bunu `Şube`ye sorar. Bu nedenle `Şube`den `Ürün`e doğru `1`'e `*` sahiplik oku çizilir; ancak bir `Ürün`ün hangi şubelerde satıldığını bilmesine gerek olmadığı için elmas veya ters yönlü ok konulmaz (ekrandan, 01:40:00; ekrandan, 01:50:30).
- **İlişki Etiketleri ve Okuma Yönü İşaretleri:** Slayt 79'daki örnek şemada görüldüğü üzere okların yanına ilişkinin problem alanındaki anlamı (`içerir V`, `< kaydeder`, `yer alır ^`, `stoklanır ^`) yazılabilir; buradaki `V`, `<`, `>` ve `^` karakterleri özellikle çift yönlü ilişkilerde fiilin hangi sınıftan hangi sınıfa doğru okunacağını gösterir (ekrandan, 01:50:30).

## 4. Çözümleme Sürecinin Belgelendirilmesi (Artefact'ler)

Bir nesneye yönelik programın çözümleme (analiz) sürecinin belgelendirilmesinde yer alan önemli yapıtlar (**artefact**) şunlardır (ekrandan, 02:10:00):
- **Doğal dille yazılmış gereksinimler belgesi** (kullanım senaryoları yazıldıktan sonra da silinmez; tüm gereksinimlerin modele eksiksiz aktarılıp aktarılmadığını kontrol etmek için belgede korunur),
- **UML Kullanım Şemaları (*Use Case Diagrams*)**,
- **Kullanım Senaryoları (*Use Case Narratives*)**,
- **UML Sınıf Şemaları (Alan Modeli)**,
- **Veritabanı işlemleri yapılacaksa bunlara ek olarak: E-R (*Entity-Relationship*) Diyagramı** (veya ağır sıklet bir E-R diyagramı çizilmese bile en azından tabloları, birincil anahtarları [*primary key*] ve yabancı anahtarları [*foreign key*] gösteren bir veritabanı şeması) (ekrandan, 02:10:00).

Ayrıca bu aşamadan itibaren sınıflar, üye alanlar ve ilişkiler belli olduğu için çevik süreçlerde kullanılan **CRC (*Class-Responsibility-Collaborator*) kartları** da oluşturulmaya başlanabilir.

## 5. Nesneye Yönelik Tasarım Sürecine Giriş ve 5 Tasarım Kalite Ölçütü

Çözümleme aşamasında **"Ne?"** sorusunu yanıtlayıp problem alanındaki varlıkları ve ilişkileri anladıktan sonra, **"Nasıl?"** sorusuna yanıt arayan **Nesneye Yönelik Tasarım Sürecine (*Object-Oriented Design*)** geçilir (ekrandan, 02:13:00). Tasarım aşamasında doğrudan problem alanı ile ilgili nesnelerden oluşan analiz modeli, yardımcı nesnelerle ve üye metotlarla (sorumluluklarla) zenginleştirilir (ekrandan, 02:13:00).

Tasarım çalışmaları iki ana işlem grubuna ayrılır (ekrandan, 02:13:00):
1. **Nesne Tasarımı:** Problem alanı ile ilgili nesnelerin ve metotlarının tasarımı (yazılım mühendisliği dersinin odak noktası).
2. **Sistem Tasarımı:** Altyapıyı ve gereçleri oluşturan nesnelerin tasarımı. Sistem katmanında bulunabilecek bileşenler şunlardır (ekrandan, 02:13:00):
   - **Yazılım mimarisi:** İstemci-sunucu (*client-server* — hesaplamaların ne kadarının sunucuda ne kadarının istemcide yapılacağı), eşler arası (*peer-to-peer* — örneğin *blockchain* ağlarında her düğümün başlı başına bir kayıt deposu olup iletişimdeki diğer düğümlerle senkronize olması) veya olay tabanlı (*event-driven*) mimari seçimi,
   - **Kullanıcı arayüzü (GUI)**,
   - **Veri yönetimi**,
   - **Ağ programlama**.
   Sistem katmanını çoğunlukla kendimiz sıfırdan oluşturmayız; hazır altyapı programlarını (**framework**) kullanırız (ekrandan, 02:13:00).

### 5.1 Tasarım Ölçütleri (Design Criteria)

Aynı problemi çözen birden fazla tasarım seçeneği arasından hangisinin "daha iyi" olduğunu öznel (*sübjektif*) beğenilerle değil, nesnel (*objektif*) ölçütlerle değerlendirmek için 5 temel **tasarım ölçütü** kullanılır (ekrandan, 02:18:00):

1. **Ayrılabilirlik (*Decomposability*):** Anlamlı parçalara (sınıf veya sınıf grubu) ayrılabilme özelliğidir. Hoca burada çok sevdiği şu ilkeyi vurgulamıştır: *"Üstünde çalıştığımız problem hangi düzeyde alt problemlere bölünebiliyorsa, tasarımımız da aynı düzeyde ayrıştırılabilmelidir."* (ekrandan, 02:18:00).
2. **Birleştirilebilirlik (*Composability*):** Bir parçanın başka tasarımlarda da kullanılabilecek şekilde diğer parçalarla birleştirilebilmesidir (ekrandan, 02:18:00). Yazılımın **yeniden kullanılabilirliğini (*reusability*)** doğrudan belirler. Somut ölçütü: eski bir projedeki bir sınıfı yeni projeye taşırken onunla birlikte taşımak zorunda kaldığımız bağımlı sınıf sayısı ve değiştirmek zorunda kaldığımız metot sayısı ne kadar azsa, birleştirilebilirlik o kadar yüksektir.
3. **Anlaşılabilirlik (*Understandability*):** Bir parçanın diğer parçalar hakkında bilgiye gerek duyulmadan anlaşılabilmesidir (ekrandan, 02:18:00). Somut ölçütü: bir sınıfın anlaşılabilirliği, ilişkide olduğu diğer sınıf sayısı ve kendi kod uzunluğu (**LOC — *Line of Code***) ile **ters orantılıdır**; ayrıca girintileme, boşluk bırakma ve *CamelCase* isimlendirme kurallarına uyum anlaşılabilirliği artırır.
4. **Süreklilik (*Continuity*):** Gereksinim değişimi gibi nedenlerle yapılacak küçük değişikliklerin etkilerinin en az sayıda parçaya (tercihen tek sınıfa) yayılmasıdır (ekrandan, 02:18:00).
5. **Koruma (*Protection*):** Olası hataların (*bug*) düzeltilmesine yönelik büyük değişikliklerin etkilerinin geniş bir alana yayılmasının önlenmesidir (ekrandan, 02:18:00).

> **Ek bilgi (derste anlatılmadı):** Modüler tasarım kalitesini tanımlayan bu beş ölçüt (*Decomposability, Composability, Understandability, Continuity, Protection*), yazılım mühendisliği literatüründe büyük olasılıkla Bertrand Meyer'in *Object-Oriented Software Construction* kitabında tanımladığı **Beş Modülerlik Ölçütü (*Five Criteria for Modularity*)** çerçevesine dayanmaktadır.

## 6. Düşük Bağlaşım (Low Coupling) ve Yüksek Uyum (High Cohesion)

Yukarıdaki beş tasarım ölçütünün tamamını kontrol eden en temel iki nesneye yönelik tasarım ilkesi **Bağlaşım (*Coupling*)** ve **Uyumdur (*Cohesion*)** (ekrandan, 02:24:30). İyi bir nesneye yönelik tasarımda **Düşük Bağlaşım (*Low Coupling*)** ve **Yüksek Uyum (*High Cohesion*)** hedeflenir. Normal koşullarda bu iki ilke birbirini olumlu yönde destekler: düşük bağlaşım yüksek uyumu, yüksek uyum da düşük bağlaşımı getirir (tersine yüksek bağlaşım düşük uyuma, düşük uyum da yüksek bağlaşıma yol açar).

### 6.1 Düşük Bağlaşım (Low Coupling)

**Bağlaşım (*Coupling*)**, bir parçanın (sınıf, alt sistem veya paket) diğer parçalara bağımlılık oranıdır (ekrandan, 02:24:30). Bir sınıfın diğer bir sınıfa **bağımlı** olması şu dört durumdan en az birinin varlığıyla oluşur (ekrandan, 02:24:30):
1. Hizmetlerinden yararlanması,
2. İç yapısından haberdar olması,
3. Çalışma prensiplerinden haberdar olması,
4. Özelleşmiş veya genelleşmiş hâli olması (kalıtım / *inheritance* ilişkisi).

Kısacası bir UML sınıf şemasında `X` sınıfından `Y` sınıfına doğru herhangi bir ok (sahiplik, kullanma/bağımlılık veya kalıtım) varsa, `X`'ten `Y`'ye doğru yönlü bir bağlaşım vardır. Örneğin alan modelimizde `Satış Kalemi` sınıfından `Ürün` sınıfına doğru bir bağlaşım vardır (`Satış Kalemi` ürünün barkod, fiyat, KDV yapısından haberdardır ve başka projeye taşınırken `Ürün` sınıfını da yanında ister); ancak `Ürün` sınıfından `Satış Kalemi`ne doğru bağlaşım yoktur.

> **Hocanın vurgusu:** Bağlaşım oranını artıran şey ilişkideki nesne sayısı (çokluğun `1..1` mi yoksa `1..*` mi olduğu) **değildir**; **ilişkide bulunulan diğer sınıfların sayısıdır** (ekrandan, 02:24:30). İster `Satış Kalemi ---> (1) Ürün` olsun, ister `Şube ---> (*) Ürün` olsun, her iki ok da bağlaşım hesabında **`1` birim sınıf bağımlılığı** olarak sayılır (`Şube <>--- Kasa` gibi çift yönlü elmas ilişkisinde ise hem `Şube`nin `Kasa`ya `1`, hem de `Kasa`nın `Şube`ye `1` bağlaşımı vardır).

**Düşük Bağlaşımın Yararları (ekrandan, 02:24:30):**
- Bir sınıfta yapılan değişikliğin geri kalan sınıfların daha azını etkilemesi,
- Yeniden kullanılabilirliğin artması.

### 6.2 Yüksek Uyum (High Cohesion)

**Uyum (*Cohesion*)**, bir parçanın (sınıfın) sorumluluklarının kendi içinde birbiriyle ne kadar yakın ve uyumlu görevlerle ilgili olduğunun oranıdır. Hoca uyum kavramını iki somut benzetmeyle açıklamıştır:
1. **Kıyafet Uyumu Benzetmesi:** Giydiğiniz kıyafetin bir parçası (taktığınız şapka, saat, kravat veya kolye) kıyafetin geri kalanıyla anlamsal ve görsel olarak uyumsuzsa nasıl sırıtıyorsa, bir sınıfın içindeki sorumluluklardan biri o sınıfın alt problem alanıyla ilgisiz olduğunda da tasarım uyumsuz olur.
2. **Öğretim Üyesi Görev Tanımı Benzetmesi:** Bir Bilgisayar Mühendisliği öğretim üyesinin birbiriyle uyumlu doğal sorumlulukları ders vermek, sınav yapmak ve öğrencileri adil/şeffaf biçimde değerlendirmektir. Eğer aynı öğretim üyesine personel maaş hesabı yapma sorumluluğu veya üniversitenin mediko-sosyal biriminin uzmanlık alanına giren "psikolojik danışmanlık verme" görevi yüklenirse, bu sorumluluklar öğretim üyesinin uzmanlık alanıyla bağdaşmaz ve uyumu düşürür.

Farklı problem alanlarına ait çok sayıda görevi tek başına üstlenen düşük uyumlu bir sınıf, psikolojik açıdan "çoklu kişilik sendromu / şizofreni" gibi davranır ve Nesneye Yönelik Programlamanın **"Böl, Parçala, Yönet"** ile **Kapsülleme (*Encapsulation*)** ilkelerini ihlal eder. Gereksinim mühendisliğindeki **İzlenebilirlik Tablosuna (*Traceability Table*)** bakıldığında tek bir sınıfın sütununda çok fazla sayıda gereksinimde işaret ($\checkmark$) görülmesi de o sınıfın tek başına aşırı fazla iş yapmaya çalıştığının (düşük uyum ve yüksek bağlaşımın) açık göstergesidir.

**Yüksek Uyumun Yararları:**
- Sınıf tek ve odaklanmış bir alt problemi çözdüğü için anlaşılabilirliği ve **bakım kolaylığı** artar; bir hata (*bug*) çıktığında hangi sınıfa müdahale edileceği nokta atışıyla bulunur,
- Sınıfın başka projelerde **yeniden kullanılabilirlik** olasılığı artar.

## Örnek Sorular

### Soru 1: Sınıf Şemalarında Doğrudan ve Dolaylı Bağlaşım Hesabı ile Tasarım Seçimi (Ekrandan, 02:39:30)

**Soru:** Aynı problemi çözdüğü varsayılan aşağıdaki iki alternatif sınıf şemasını inceleyiniz (ekrandan, 02:39:30):

```text
       I. TASARIM                                  II. TASARIM
+-----+        +-----+                      +-----+        +-----+
|  A  |------->|  B  |                      |  A  |------->|  B  |
+-----+        +-----+                      +-----+        +-----+
                  |                            |
                  |                            |           +-----+
                  v                            '---------->|  C  |
               +-----+                                     +-----+
               |  C  |
               +-----+
```

1. Yalnızca **doğrudan bağlaşımları** (her doğrudan ok $= 1$) dikkate alarak her iki tasarımda $A$, $B$, $C$ sınıflarının bağlaşım değerlerini, maksimum bağlaşımı ($\text{bağ}_{\max}$) ve toplam bağlaşımı ($\text{topBağ}$) hesaplayınız.
2. İki adım uzaktaki **dolaylı bağlaşımları** da $0{,}5$ ağırlık katsayısıyla dikkate alarak hesaplamayı tekrarlayınız ve hangi tasarımın tercih edilmesi gerektiğini gerekçesiyle açıklayınız.

**Cevap (derste verildi):**

| Ölçüt | I. Tasarım (Yalnız Doğrudan) | II. Tasarım (Yalnız Doğrudan) | I. Tasarım (Dolaylı Dahil, $+0{,}5$) | II. Tasarım (Dolaylı Dahil, $+0{,}5$) |
| :--- | :---: | :---: | :---: | :---: |
| $\text{bağ}(A)$ | $1$ ($B$) | $2$ ($B, C$) | $1 + 0{,}5 = 1{,}5$ ($B$ doğrudan, $C$ dolaylı) | $2$ ($B, C$ doğrudan; dolaylı yok) |
| $\text{bağ}(B)$ | $1$ ($C$) | $0$ | $1$ ($C$) | $0$ |
| $\text{bağ}(C)$ | $0$ | $0$ | $0$ | $0$ |
| **Maksimum Bağlaşım ($\text{bağ}_{\max}$)** | **$1$** | **$2$** | **$1{,}5$** | **$2$** |
| **Toplam Bağlaşım ($\text{topBağ}$)** | $2$ | $2$ | $2{,}5$ | $2$ |

- **Değerlendirme ve Sonuç:** Doğrudan bağlaşımda her iki tasarımın toplam bağlaşımı eşit ($\text{topBağ} = 2$) olsa da, en kötü durumdaki sınıfın bağımlılık yükünü gösteren **maksimum bağlaşım ($\text{bağ}_{\max}$)** I. Tasarımda $1$, II. Tasarımda ise $2$'dir. $A$'nın $B$ üzerinden $C$'ye olan dolaylı bağımlılığı ($0{,}5$) hesaba katıldığında bile I. Tasarımın maksimum bağlaşımı ($1{,}5$), II. Tasarımın maksimum bağlaşımından ($2$) daha düşüktür ($1{,}5 < 2$). Bu nedenle **I. Tasarım** tercih edilmelidir (ekrandan, 02:39:30).

---

### Soru 2: Veritabanı Erişiminde Katmanlı Mimari — Bağlaşım ve Uyum Çatışması (Ekrandan, 03:00:00)

**Soru:** Soru 1'de seçilen `A -> B -> C` sınıflarından oluşturulacak nesnelerin bir `VT` veritabanında saklanması ve geri yüklenmesi gerekmektedir. Aşağıdaki iki tasarım seçeneğinden hangisi tercih edilmelidir? Bağlaşım, uyum ve veritabanı değişikliği (bakım) açısından tartışınız (ekrandan, 03:00:00):
- **I. Tasarım:** `A, B, C` nesnelerini `VT` veritabanına yazıp okumaktan sorumlu ayrı bir **`V` sınıfı** tanımlanır (`V` sınıfı `A, B, C` ve `VT` ile kullanma/bağımlılık ilişkisine girer).
- **II. Tasarım:** Ayrı bir `V` sınıfı tanımlanmaz; `A`, `B` ve `C` sınıflarının her biri kendi veritabanı okuma/yazma işlemlerini doğrudan `VT` paketiyle iletişim kurarak kendisi yapar.

**Cevap (derste verildi):**
1. **Bağlaşım ve Uyum Karşılaştırması (ekrandan, 03:00:00):**
   - **I. Tasarım:** Yeni eklenen `V` sınıfı hem `A, B, C` hem de `VT` ile bağımlılık kurduğu için **bağlaşım yüksektir `(-)`**; buna karşılık `A, B, C` sınıfları yalnızca problem alanı (iş mantığı) sorumluluklarını yürüttüğü ve veritabanı işlemleri `V` sınıfında toplandığı için **uyum yüksektir `(+)`**. Böylece tasarım **İş Katmanı** (`A, B, C` — turuncu bölge) ve **Sistem Katmanı** (`V, VT` — yeşil bölge) olarak iki temiz katmana ayrılmıştır.
   - **II. Tasarım:** Ekstra bir `V` sınıfı olmadığı için **bağlaşım düşüktür `(+)`**; ancak `A, B, C` sınıflarına hem kendi problem alanı görevleri hem de veritabanı okuma/yazma (sistem katmanı) görevleri yüklendiği için **uyum düşüktür `(-)`**.
2. **Bakım Senaryosu ve Nihai Karar:** Bağlaşım ile uyumun zıtlaştığı bu istisnai durumda **yüksek uyumu sağlayan I. Tasarım seçilmelidir**. Çünkü ileride ilişkisel veritabanından ilişkisel olmayan (NoSQL / ağ / coğrafi) bir veritabanına geçilmesi gerektiğinde veya *MS SQL* kullanan müşterilerin yanında lisans ücreti ödemek istemeyen KOBİ müşteriler için *MySQL* desteği eklendiğinde; II. Tasarımda veritabanı kodları tüm iş sınıflarına dağıldığı için `A`, `B` ve `C` sınıflarının tamamını değiştirmek gerekir. Oysa **I. Tasarımda** iş katmanındaki `A, B, C` sınıflarına hiç dokunulmaz; yalnızca sistem katmanındaki `V` sınıfı (`V_MSSQL` $\rightarrow$ `V_MySQL`) değiştirilerek sorun tek noktada çözülür (ekrandan, 03:00:00).

## Dersin Toparlaması

Bu derste ilk olarak **Nesneye Yönelik Çözümleme** aşamasının çekirdeğini oluşturan **Alan Modeli (*Domain Model*)** çıkarma yöntemi *NextGenPOS* örneği üzerinde baştan sona uygulanmıştır: gereksinim ve kullanım öyküsü metinlerindeki isimlerin taranması, aday sınıfların **Saklanan Bilgi, Gereksinim Duyulan Hizmetler ve Gerekli Varlıklar** kurallarıyla elenmesi, elenen adayların üye alana dönüştürülmesi ve *Primitive Obsession* hatasına düşmemek için `Satış Kalemi` ara sınıfının modele eklenmesi gösterilmiştir.

Dersin ikinci bölümünde **"Nasıl?"** sorusuna odaklanan **Nesneye Yönelik Tasarım Sürecine** giriş yapılmış; nesne tasarımı ile sistem tasarımı ayrımı ve beş tasarım kalite ölçütü (**Ayrılabilirlik, Birleştirilebilirlik, Anlaşılabilirlik, Süreklilik, Koruma**) açıklanmıştır. Son olarak bu ölçütlerin temelini oluşturan **Düşük Bağlaşım (*Low Coupling*)** ve **Yüksek Uyum (*High Cohesion*)** ilkeleri iki etkileşimli tasarım problemi üzerinde incelenmiş; özellikle iş katmanı ile veritabanı (sistem) katmanını ayırmanın yüksek uyum ve bakım kolaylığı açısından neden vazgeçilmez olduğu ortaya konulmuştur. Bir sonraki derste sorumlulukların sınıflara atanması ve tasarım kalıpları (*design patterns*) ile devam edilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
