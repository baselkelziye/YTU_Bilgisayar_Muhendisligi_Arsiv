# Ders 5 Çalışma Özeti

## Genel Konular

- Nesneye Yönelik Çözümleme Süreci: Sınıfların Belirlenmesi ve 3 Seçim Kuralı
  - Kullanıcı gereksinimleri belgesindeki ve kullanım senaryolarındaki (*use case* metinlerindeki) **isimlerin (*nouns*)** taranarak aday sınıfların elde edilmesi; her adayın şu **3 kuraldan en az birini** sağlayıp sağlamadığının sınanması (ekrandan, 00:14:30):
    1. **Saklanan bilgi:** Sistemin çalışması süresince bu varlığın durumu saklanmalıdır.
    2. **Gereksinim duyulan hizmetler:** Bu varlığın hizmetlerine ihtiyaç duyan başka varlıklar vardır.
    3. **Gerekli varlıklar:** Problemin çözümü ile ilgili bilgi üreten (hesaplama yapan) veya problemin çözümü için bilgi tüketen (hesaplamaya girdi sağlayan) varlıklar.
  - Bu üç kuraldan hiçbirini sağlayamayan adayların elenmesi veya başka bir sınıfın **üye alanı (*attribute*)** olarak değerlendirilmesi (ekrandan, 00:14:30).
- *NextGenPOS* Örneğinde Aday Sınıfların Elenmesi ve Alan Modeli (*Domain Model*) Oluşturulması
  - *NextGenPOS* metninden ve *Satış İşlemi* kullanım öyküsünden çıkarılan 18 adayın değerlendirilmesi sonucunda **7 çekirdek sınıfın** seçilmesi: **`Şube`**, **`Kasa`**, **`Satış`**, **`Satış Kalemi`**, **`Ürün`**, **`Ödeme`** ve **`Kasiyer`** (`Şirket` sınıfının merkezi stok yönetimi kapsam dışı bırakıldığı için bu aşamada dışarıda tutulması; `Müşteri`nin *Loyalty Card* gereksinimi olmadığı için, `Fiş`in ise diğer varlıklardan türetilen bir çıktı olduğu ve ürün garanti takibi bulunmadığı için elenmesi; `KDV`, `barkod`, `ürün tanımı`, `ürün fiyatı` ve `toplam bedel` adaylarının ise üye alan yapılması) (ekrandan, 00:52:00).
  - **Alan Modelinin (*Domain Model*)** *Violet UML Editor* üzerinde **UML Sınıf Şeması (*Class Diagram*)** olarak çizilmesi: çözümleme aşaması **"Ne?"** sorusuna odaklandığı için şemada yalnızca **sınıflar, üye alanlar ve sınıflar arası ilişkiler (çokluk/kardinalite değerleriyle)** yer alır; **"Nasıl?"** sorusuna karşılık gelen **üye metotlar** tasarım aşamasına bırakılır (ekrandan, 01:40:00; ekrandan, 01:50:30).
  - **`Satış` ile `Ürün` arasına `Satış Kalemi` (*SalesLineItem*) sınıfının konulması:** Aynı üründen birden fazla adet alındığında `adet` bilgisini `Ürün` veya `Satış` sınıfında tutmanın imkânsızlığı; `Satış` içinde paralel `ürünler[]` ve `adetler[]` dizileri tutmanın ise nesneye yönelim doğasına aykırı **İlkel Veri Tipi Takıntısı (*Primitive Obsession*)** kusuruna yol açması nedeniyle `Satış (1) ---> (1..*) Satış Kalemi (1) ---> (1) Ürün` yapısının kurulması (ekrandan, 01:40:00).
  - Çözümleme sürecinin belgelendirilmesinde üretilen yapıtlar (*artefacts*): **UML Kullanım Şemaları**, **Kullanım Senaryoları**, **UML Sınıf Şemaları (Alan Modeli)** ve veritabanı işlemleri yapılacaksa **E-R (*Entity-Relationship*) Diyagramı** (veya tablo/anahtar şeması) (ekrandan, 02:10:00).
- Nesneye Yönelik Tasarım Sürecine Giriş ve Tasarım Ölçütleri
  - Tasarım sürecinin **"Nasıl?"** sorusuna yanıt araması ve analiz modelini yardımcı nesnelerle zenginleştirmesi; iki ana işlem grubu olarak **Nesne Tasarımı** (problem alanı ile ilgili nesneler) ve **Sistem Tasarımı** (altyapıyı ve gereçleri oluşturan nesneler: yazılım mimarisi [istemci-sunucu, eşler arası / *peer-to-peer*, olay tabanlı vb.], kullanıcı arayüzü, veri yönetimi, ağ programlama; çoğunlukla sıfırdan yazılmayıp hazır *framework* kullanımı) (ekrandan, 02:13:00).
  - Alternatif tasarımlar arasında nesnel seçim yapmayı sağlayan **5 Tasarım Ölçütü (ekrandan, 02:18:00):**
    1. **Ayrılabilirlik (*Decomposability*):** Problemin alt problemlere bölünebildiği düzeyde tasarımın da anlamlı parçalara (sınıf/sınıf grubu) ayrıştırılabilmesi.
    2. **Birleştirilebilirlik (*Composability*):** Bir parçanın başka tasarımlarda da kullanılabilecek (yeniden kullanılabilir / *reusable*) şekilde diğer parçalarla birleştirilebilmesi.
    3. **Anlaşılabilirlik (*Understandability*):** Bir parçanın diğer parçalar hakkında bilgiye gerek duyulmadan anlaşılabilmesi (ilişkili sınıf sayısı ve kod satırı sayısı [*LOC*] ile ters orantılı).
    4. **Süreklilik (*Continuity*):** Yapılacak küçük değişikliklerin etkilerinin en az sayıda parçaya (tercihen tek sınıfa) yayılması.
    5. **Koruma (*Protection*):** Olası hataların düzeltilmesine yönelik büyük değişikliklerin etkilerinin geniş bir alana yayılmasının önlenmesi.
- Düşük Bağlaşım (*Low Coupling*) ve Yüksek Uyum (*High Cohesion*) İlkeleri
  - **Bağlaşım (*Coupling*):** Bir parçanın (sınıf, alt sistem, paket) diğer parçalara bağımlılık oranı (bir sınıfın diğerinin hizmetlerinden yararlanması, iç yapısından veya çalışma prensiplerinden haberdar olması ya da kalıtım ilişkisi) (ekrandan, 02:24:30). İyi tasarımda **düşük bağlaşım (*low coupling*)** hedeflenir; bağlaşım nesne çokluğuna (`1` veya `*`) değil, **ilişkide bulunulan sınıf sayısına** bağlıdır ve doğrudan bağlaşımın yanı sıra geçişli (**dolaylı**) bağlaşım da ($0{,}5$ ağırlıkla) hesaba katılabilir (ekrandan, 02:39:30).
  - **Uyum (*Cohesion*):** Bir parçanın sorumluluklarının birbiriyle yakın/uyumlu görevlerle ilgili olma oranı. İyi tasarımda **yüksek uyum (*high cohesion*)** hedeflenir; düşük uyum bakım ve anlaşılabilirliği zorlaştırır.
  - **Katmanlı Mimari ve Bağlaşım-Uyum Dengesi:** İş katmanı sınıflarının (`A, B, C`) veritabanı (`VT`) okuma/yazma işlemlerini kendi içlerinde yapması (II. Tasarım) bağlaşımı düşük tutsa da hem iş mantığı hem sistem görevi yüklediği için **uyumu düşürür**; veritabanı işlemlerini ayrı bir **`V` sınıfına** devretmek (I. Tasarım) ise bağlaşımı artırsa da **yüksek uyum ve katmanlı mimari** (İş Katmanı / Sistem Katmanı ayrımı) sağlayarak veritabanı değişimlerinde (*MS SQL* $\rightarrow$ *MySQL* veya ilişkisel $\rightarrow$ NoSQL) `A, B, C` sınıflarını korur (ekrandan, 03:00:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Alan Modelinde (Çözümleme Aşamasında) Metotların Yer Almaması
  - Çözümleme aşamasında çizilen UML Sınıf Şeması (**Alan Modeli**), problem alanındaki **"Ne?"** sorusunu yanıtlar: hangi sınıflar vardır, bu sınıfların hangi bilgileri (üye alanları) saklanır ve sınıflar arasındaki ilişkiler nelerdir. İşin **"Nasıl?"** yapılacağını gösteren **üye metotlar** analiz aşamasındaki alan modeline yazılmaz; tasarım aşamasında sorumluluklar dağıtılırken eklenir.
- Sorumluluk Atama İlkesi (Bilgi Uzmanı) ve Yalnızca Gerekli Yönlerde İlişki Kurma
  - Bir sorumluluk, o sorumluluğu yerine getirmek için gereken veriye en çok sahip olan sınıfa atanmalıdır (ör. fiş basma ve toplam satışları tutma sorumluluğunun `Satış` yerine `Kasa` sınıfına verilmesi) ve hiçbir sınıf tamamen üye alansız veya diğer sınıflardan kopuk bir "adacık" hâlinde olmamalıdır.
  - Çift yönlü (*bidirectional*) sahiplik ilişkileri ek tutarlılık kontrolleri ve kodlama yükü getirdiğinden, alan modelinde **yalnızca problem çözümü için zorunlu olan yönlerde** ok çizilmelidir (ör. `Kasa` yapılan `Satış`ları bilmelidir ancak `Satış`ın `Kasa`yı bilmesine gerek yoktur; `Şube` sattığı `Ürün`leri bilmelidir ki barkod sorgulanabilsin, ancak `Ürün`ün hangi `Şube`de satıldığını bilmesine gerek yoktur) (ekrandan, 01:40:00).
- `Satış Kalemi` Sınıfının Zorunluluğu ve *Primitive Obsession* Kusuru
  - Bir satışta birden fazla üründen farklı adetlerde alındığında, `Satış` sınıfı içinde `ürünler: Ürün[]` ve `adetler: int[]` şeklinde iki ayrı dizi tanımlayıp *"aynı indisteki elemanlar birbirine karşılık gelir"* demek, nesneye yönelik tasarıma aykırı olan **İlkel Veri Tipi Takıntısı (*Primitive Obsession*)** kusurudur. Bunun doğru çözümü, araya `adet: int` ve `ürün: Ürün` alanlarını birleştiren **`Satış Kalemi`** sınıfını koymaktır (ekrandan, 01:40:00).
- Bağlaşım (*Coupling*) Hesabında Çokluğun Değil, Sınıf Sayısının Önemi ve Maksimum Bağlaşım
  - İki sınıf arasında UML şemasında bir ok varsa, ilişkinin çokluğu ister `1..1` ister `1..*` (binlerce nesne) olsun, bağlaşım açısından değeri **`1` sınıf bağımlılığıdır**; çünkü o sınıfı başka bir projeye taşımak için hedef sınıfın koduna her iki durumda da ihtiyaç vardır (ekrandan, 02:24:30).
  - İki alternatif tasarımın (`A -> B -> C` ile `A -> B, A -> C`) toplam doğrudan bağlaşımı eşit ($\text{topBağ} = 2$) olsa bile, tek bir sınıfın üzerindeki en kötü bağımlılık yükünü gösteren **maksimum bağlaşım ($\text{bağ}_{\max}$)** ölçütüne (ve $0{,}5$ ağırlıklı dolaylı bağlaşım hesabına) göre `A -> B -> C` tasarımı ($\text{bağ}_{\max} = 1$, dolaylıyla $1{,}5 < 2$) tercih edilir (ekrandan, 02:39:30).
- Veritabanı İşlemlerinin Ayrı Sınıfa (`V`) Ayrılması (Uyumun Bağlaşıma Üstünlüğü)
  - Normalde düşük bağlaşım ve yüksek uyum birlikte hareket eder; ancak veritabanı erişimi örneğinde olduğu gibi ikisi çeliştiğinde, problem alanı sınıflarına (`A, B, C`) veritabanı okuma/yazma görevi yükleyerek uyumu bozmak ("şizofrenik / çoklu kişilikli sınıf" yaratmak) yerine, veritabanı işlemlerini ayrı bir sistem katmanı sınıfına (`V`) toplamak gerekir. Böylece veritabanı sistemi değiştiğinde (*MS SQL*'den *MySQL*'e veya ilişkiselden ilişkisel olmayana geçişte) iş katmanındaki `A, B, C` sınıflarına hiç dokunulmadan yalnız `V` sınıfı güncellenir (ekrandan, 03:00:00).

## Kısa Tekrar Notları

- **Sınıf belirlemede 3 kural:** 1) **Saklanan bilgi** (durumu saklanmalı), 2) **Gereksinim duyulan hizmetler** (başka varlıklar hizmetine ihtiyaç duyar), 3) **Gerekli varlıklar** (çözüm için bilgi üretir veya tüketir). Hiçbirini sağlamayan aday **üye alan (*attribute*)** olur (ekrandan, 00:14:30).
- **Dilbilgisel ipucu:** Metindeki **isimler (*nouns*)** aday sınıfları, **sıfatlar/niteleyiciler** üye alanları, **fiiller (*verbs*)** ise (tasarım aşamasında eklenecek) üye metotları işaret eder.
- **NextGenPOS Alan Modeli sınıfları ve üye alanları (ekrandan, 01:50:30):**
  - `Şube`: `- ad, adres : String`, `- vergiNo : int`
  - `Kasa`: `- şubesi : Şube`, `- satışlar : Satış[]`
  - `Satış`: `- kalemler : SatışKalemi[]`, `- ödeme : Ödeme`, `- kasiyer : Kasiyer`, `- toplamBedel : double` (hesaplanabilir olduğu için tasarımda silinebilir), `- tarihSaat : Date`
  - `Satış Kalemi`: `- adet : int` (slaytta `miktar : int`), `- ürün : Ürün`
  - `Ürün`: `- barkod, tanım : String` (barkod baştaki `0`'ları ve `X` kontrol karakterini korumak için `String` tutulur), `- KDV, fiyat : double`
  - `Ödeme`: `- miktar : double`
  - `Kasiyer`: `- ad, ID : String`
- **Primitive Obsession (İlkel Veri Tipi Takıntısı):** Yeni bir kavramsal sınıf (`Satış Kalemi`) oluşturmak yerine paralel ilkel diziler (`ürünler[]` ve `adetler[]`) kullanma hatası.
- **Çözümleme aşaması yapıtları (*artefacts*):** Doğal dil gereksinimler belgesi, Kullanım senaryoları (*use cases*), UML Kullanım şemaları (*use case diagrams*), UML Sınıf şemaları (Alan modeli) ve varsa E-R diyagramı (ekrandan, 02:10:00).
- **Tasarımın 2 ana işlem grubu:** **Nesne tasarımı** (problem alanı nesneleri) ve **Sistem tasarımı** (mimari, GUI, veri yönetimi, ağ programlama; hazır *framework* kullanımı) (ekrandan, 02:13:00).
- **5 Tasarım ölçütü:** **Ayrılabilirlik**, **Birleştirilebilirlik**, **Anlaşılabilirlik**, **Süreklilik**, **Koruma** (ekrandan, 02:18:00).
- **Temel tasarım hedefi:** **Düşük Bağlaşım (*Low Coupling*)** ve **Yüksek Uyum (*High Cohesion*)** (ekrandan, 02:24:30).
- **Bağlaşım (*Coupling*) formülü (dersteki örnek):** Doğrudan ilişkili her sınıf $+1$, iki adım uzaktaki dolaylı ilişkili her sınıf $+0{,}5$ puan; tasarım seçiminde önce **maksimum sınıf bağlaşımının ($\text{bağ}_{\max}$) küçüklüğüne** bakılır (ekrandan, 02:39:30).

## Detaylı Açıklamalar

### 1. Sınıfların Belirlenmesi ve NextGenPOS Aday Varlık Analizi

Nesneye yönelik çözümleme sürecinde kullanım senaryoları ve kullanım şemaları tamamlandıktan sonra, problem alanındaki varlıkları yazılım dünyasına taşıyan **Alan Modeli (*Domain Model*)** oluşturulur. Bunun için önce kullanıcı gereksinimleri belgesi ve kullanım senaryosu metinleri baştan sona okunarak içindeki **isimler (*nouns*)** listelenir ve **aday sınıflar** elde edilir (ekrandan, 00:14:30). Ardından her aday şu **3 kurala** göre sınanır (ekrandan, 00:14:30):
1. **Saklanan bilgi:** Sistemin çalışması süresince bu varlığın durumu saklanmalıdır.
2. **Gereksinim duyulan hizmetler:** Bu varlığın hizmetlerine ihtiyaç duyan başka varlıklar vardır.
3. **Gerekli varlıklar:** Problemin çözümü ile ilgili bilgi üreten veya problemin çözümü için bilgi tüketen varlıklar.

Bir aday bu üç kuraldan **birini bile** sağlıyorsa alan modeline **sınıf (*class*)** olarak dahil edilir; hiçbirini sağlamıyorsa ya kapsam dışı bırakılır ya da uygun bir sınıfın **üye alanı (*attribute*)** olarak değerlendirilir (ekrandan, 00:14:30).

Hoca derste *NextGenPOS* gereksinim paragrafını ve *Satış İşlemi* kullanım öyküsünü tarayarak Not Defteri'nde şu 18 adayı çıkarmış ve tek tek değerlendirmiştir (ekrandan, 00:52:00; ekrandan, 01:40:00):

| Aday Varlık (İsim) | Karar | Mühendislik Gerekçesi (3 Kurala Göre Değerlendirme) |
| :--- | :---: | :--- |
| **Kasa** | **`+` (Sınıf)** | Satış işlemlerini koordine eder, yapılan satışları saklar, barkod bilgisini alıp şubeden sorgular ve fiş basar (3 kuralı da sağlar). |
| **Alış-veriş işlemi** | **`-` (Eş anlamlı)** | Perakende markette ürün girişi/tedariki bu senaryonun konusu olmadığından **`Satış`** ile eş anlamlıdır; isim olarak `Satış` tercih edilmiştir. |
| **mali bilgiler** | **`-` (Yuvarlak ifade)** | Çok genel bir ifadedir; içerdiği somut veriler (ürün fiyatı, KDV, toplam bedel, ödeme miktarı) zaten aşağıda ayrı adaylar olarak yer almaktadır. |
| **mal** | **`-` (Eş anlamlı)** | **`Ürün`** ile aynı kavramdır; daha uygun bir terim olan `Ürün` tercih edilmiştir. |
| **müşteri** | **`-` (Elendi)** | Fiziksel eylemlerin tamamı kasiyer aracılığıyla sisteme girilir. Gereksinim metninde **müşteri sadakat kartı (*loyalty card*)** ve müşteri alışveriş geçmişi takibi bulunmadığından sistemde müşteri durumu saklanmaz. |
| **fiş** | **`-` (Türetilen varlık)** | Fiş üzerindeki tüm bilgiler (şube adı/adresi/vergi no, tarih, ürünler, adetler, KDV, toplam bedel, kasiyer adı) zaten diğer varlıklarda saklanmaktadır. Mağazada elektronik eşya **ürün garanti takibi** de yapılmadığından fiş ayrı bir sınıf olarak saklanmaz, kasanın fiş basma fonksiyonu tarafından üretilen bir çıktı olur. |
| **satış** | **`+` (Sınıf)** | Yapılan her satış işleminin tarihi, satılan kalemleri, ödemesi ve kasiyeri sistemde saklanmalı ve gün sonu raporlarında kullanılmalıdır. |
| **KDV** | **`-` (Üye alan)** | Saklanması ve hesaplanması zorunludur ancak tek başına bağımsız bir varlık değildir; her ürünün KDV oranı (%1, %8, %18 vb.) farklı olduğundan **`Ürün` sınıfına bağlı bir üye alandır**. |
| **Şirket** | **`+` (Şimdilik alınmadı)** | Normalde geçerli bir sınıftır ancak merkezi stok yönetimi ve şubeler arası veri aktarımı sistem katmanı / sonraki aşama konusu olduğundan çekirdek modelde dışarıda bırakılmıştır. |
| **Şube** | **`+` (Sınıf)** | Fişte basılacak şube adı, adresi ve vergi numarasını tutar; ayrıca kasaları barındırır ve şubede satılan ürünlerin kataloğunu tutarak barkod sorgusuna yanıt verir. |
| **Kasiyer** | **`+` (Sınıf)** | Kasiyerin kimlik doğrulaması (kullanıcı hesabı) vardır ve fiş üzerinde satışı yapan kasiyerin adı/ID'si yer alır (1. kural: saklanan bilgi). |
| **Ödeme** | **`+` (Sınıf)** | Gün sonunda kasa açığı olup olmadığını denetlemek için satışın hesaplanan toplam bedelinden ayrı olarak fiilen tahsil edilen ödeme miktarının (ve ileride nakit/kart/yemek kartı detaylarının) saklanması gerekir. |
| **ürün** | **`+` (Sınıf)** | Barkodu, tanımı, birim fiyatı ve KDV oranı saklanır ve satış/fiş hesaplamalarına girdi sağlar. |
| **barkod** | **`-` (Üye alan)** | **`Ürün` sınıfına bağlı tekil tanımlayıcı (*ID*) üye alandır** (baştaki sıfırların kaybolmaması ve EAN/UPC standartlarında kontrol basamağının `X` [10] olabilmesi nedeniyle `String` tipinde tutulur). |
| **Satış kalemi** | **`+` (Sınıf)** | Bir satışta hangi üründen kaç adet alındığını (`adet` ve `ürün`) tutan ara sınıftır. |
| **ürün tanımı** | **`-` (Üye alan)** | **`Ürün` sınıfına bağlı bir üye alandır** (`tanım : String`). |
| **ürün fiyatı** | **`-` (Üye alan)** | **`Ürün` sınıfına bağlı bir üye alandır** (`fiyat : double`). |
| **Toplam bedel** | **`-` (Üye alan)** | **`Satış` sınıfına bağlı bir üye alandır** (`toplamBedel : double`; satış kalemlerinden kolayca hesaplanabildiği için tasarım aşamasında metot hâline getirilip üye alandan çıkarılabilir). |

### 2. Alan Modelinin (UML Sınıf Şeması) Çizilmesi ve İlişkilerin Kurulması

Seçilen 7 sınıf ve üye alanları *Violet UML Editor* üzerinde bir araya getirilerek *NextGenPOS* **Alan Modeli** oluşturulmuştur (ekrandan, 01:40:00; ekrandan, 01:50:30):

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

Şemadaki ilişkilerin ve çokluk (*multiplicity*) değerlerinin tasarım gerekçeleri şunlardır (ekrandan, 01:40:00; ekrandan, 01:50:30):
1. **`Şube <>--- (1..*) Kasa` (Parça-Bütün / *Aggregation*):** Kasalar şubenin demirbaşıdır ve bir şubede satış yapılabilmesi için **en az 1 kasa (`1..*`)** bulunmalıdır (`0` kasalı şube olamaz). Öte yandan `Kasa` da fiş basarken şubenin adını, adresini ve vergi numarasını bilmek zorunda olduğundan ilişki çift yönlüdür; UML'de içi boş elmas (`<>`, *aggregation*) hem parça-bütün ilişkisini hem de elmas yönüne doğru olan referansı (`- şubesi : Şube`) ifade eder.
2. **`Şube (1) ---> (*) Ürün` (Sahiplik / *Association*):** Kasiyer bir ürünün barkodunu okuttuğunda `Kasa`, bu barkodun hangi `Ürün` nesnesine karşılık geldiğini ve o şubede satılıp satılmadığını **`Şube`'nin ürün listesinden** sorgular (`stoklanır`). Buna karşılık bir `Ürün` nesnesinin hangi şubede satıldığını bilmesine gerek yoktur; bu nedenle ok yalnızca `Şube`'den `Ürün`'e doğrudur.
3. **`Kasa (1) ---> (*) Satış` (`kaydeder`):** Gün sonu raporu almak ve kasa açığını denetlemek için her kasa kendi üzerinde yapılan satışları (`- satışlar : Satış[]`) tutar. Kasa sabah ilk açıldığında veya gün sonunda kayıtlar merkezi sunucuya aktarılıp sıfırlandığında kasada henüz `0` satış bulunabileceği için çokluk `1..*` değil **`*` (`0..*`)** olarak bırakılmıştır. Fiş basma sorumluluğu `Kasa`'da olduğu için `Satış`'ın `Kasa`'yı bilmesine gerek yoktur (tek yönlü ok).
4. **`Satış (1) ---> (1) Kasiyer` ve `Satış (1) ---> (1) Ödeme`:** Bir kasada gün içinde farklı kasiyerler oturum açıp kapatabileceği için `Kasiyer` doğrudan `Kasa` ile değil, gerçekleştirdiği `Satış` ile (`1..1`) ilişkilendirilir. Aynı şekilde her satışın (`1..1`) bir `Ödeme` nesnesi vardır.
5. **`Satış (1) ---> (1..*) Satış Kalemi (1) ---> (1) Ürün` ve *Primitive Obsession* Uyarısı:**
   - Müşteri aynı üründen (ör. 0,5 L su) 3 adet, başka bir müşteri ise 2 adet alabilir. Eğer `adet` bilgisi `Ürün` sınıfına konulursa her satış için aynı üründen yeni nesneler üretmek veya marketteki binlerce şişenin her biri için ayrı nesne açmak gerekir ki bu belleği şişirir.
   - Eğer `adet` bilgisi doğrudan `Satış` sınıfına tek bir tam sayı olarak konulursa, bir satışta birden fazla ürün çeşidi (su, şeker, kalem) alındığında hangi adedin hangi ürüne ait olduğu tutulamaz.
   - `Satış` içinde `ürünler : Ürün[]` ve `adetler : int[]` şeklinde iki paralel dizi tutup *"0. indisteki ürünün adedi 0. indisteki tam sayıdır"* şeklinde kod yazmak ise nesneye yönelim felsefesine aykırı olan **İlkel Veri Tipi Takıntısı (*Primitive Obsession*)** tasarım kusurudur.
   - Doğru nesneye yönelik çözüm, araya **`Satış Kalemi`** sınıfını koymaktır: her `Satış` en az bir `Satış Kalemi` (`1..*`) içerir ve her `Satış Kalemi` tam olarak `1` `Ürün` referansı ile o üründen kaç tane alındığını gösteren `adet : int` bilgisini bir arada kapsüller.

### 3. Nesneye Yönelik Tasarım Süreci ve 5 Tasarım Kalite Ölçütü

Çözümleme süreci; **UML Kullanım Şemaları**, **Kullanım Senaryoları**, **UML Sınıf Şemaları (Alan Modeli)** ve veritabanı kullanılacaksa **E-R Diyagramı** (veya tablo birincil/yabancı anahtar [*PK/FK*] şemaları) adlı yapıtların (*artefacts*) üretilmesiyle tamamlanır (ekrandan, 02:10:00) ve **"Nasıl?"** sorusuna yanıt arayan **Nesneye Yönelik Tasarım Sürecine** geçilir (ekrandan, 02:13:00).

Tasarım aşamasında analizden gelen alan modeli yardımcı nesnelerle zenginleştirilir ve çalışmalar iki ana işlem grubuna ayrılır (ekrandan, 02:13:00):
- **Nesne Tasarımı:** Doğrudan problem alanı ile ilgili nesnelerin sorumluluklarının ve üye metotlarının tasarlanması (dersin ana odak noktası).
- **Sistem Tasarımı:** Altyapıyı ve gereçleri oluşturan nesnelerin tasarlanması. Sistem katmanında dört temel bileşen grubu bulunur (ekrandan, 02:13:00):
  1. *Yazılım mimarisi:* İstemci-sunucu (*client-server* — iş yükünün ne kadarının sunucuda ne kadarının istemcide yapılacağı), eşler arası (*peer-to-peer* — ör. *blockchain* ağındaki gibi her düğümün kendi kayıt deposunu tutup komşularıyla senkronize olması) veya olay tabanlı (*event-driven*) mimari seçimi,
  2. *Kullanıcı arayüzü (GUI)*,
  3. *Veri yönetimi*,
  4. *Ağ programlama*.
  Sistem katmanı çoğunlukla sıfırdan oluşturulmaz; hazır altyapı kütüphaneleri (**framework**) kullanılır (ekrandan, 02:13:00).

Aynı problemi çözen birden fazla tasarım alternatifinden hangisinin "daha iyi" olduğunu öznel yorumlarla değil, nesnel ölçütlerle belirlemek için **5 Tasarım Ölçütü** tanımlanmıştır (ekrandan, 02:18:00):
1. **Ayrılabilirlik (*Decomposability*):** Anlamlı parçalara (sınıf veya sınıf grubu) ayrılabilme yeteneğidir. Üstünde çalıştığımız problem hangi düzeyde alt problemlere bölünebiliyorsa, tasarımımız da aynı düzeyde ayrıştırılabilmelidir (ekrandan, 02:18:00).
2. **Birleştirilebilirlik (*Composability*):** Bir parçanın başka tasarımlarda da kullanılabilecek şekilde diğer parçalarla birleştirilebilmesidir (yazılımın yeniden kullanılabilirliğini [*reusability*] teşvik eder; bir sınıfı eski projeden yeni projeye taşırken beraberinde taşınması gereken bağımlı sınıf sayısı ve değiştirilmesi gereken metot sayısı ne kadar azsa birleştirilebilirlik o kadar yüksektir) (ekrandan, 02:18:00).
3. **Anlaşılabilirlik (*Understandability*):** Bir parçanın diğer parçalar hakkında bilgiye gerek duyulmadan anlaşılabilmesidir (sınıfın bağımlı olduğu diğer sınıf sayısı ve toplam kod satırı sayısı [*Line of Code — LOC*] ile ters orantılıdır; ayrıca girintileme ve *CamelCase* isimlendirme kurallarına uyum anlaşılabilirliği artırır) (ekrandan, 02:18:00).
4. **Süreklilik (*Continuity*):** Yapılacak küçük değişikliklerin etkilerinin en az sayıda parçaya (tercihen tek sınıfa) yayılmasıdır (ekrandan, 02:18:00).
5. **Koruma (*Protection*):** Olası hataların düzeltilmesine yönelik büyük değişikliklerin etkilerinin geniş bir alana yayılmasının önlenmesidir (ekrandan, 02:18:00).

### 4. Düşük Bağlaşım (Low Coupling) ve Yüksek Uyum (High Cohesion)

Yukarıdaki beş tasarım ölçütünün tamamını doğrudan belirleyen en temel iki nesneye yönelik tasarım ilkesi **Düşük Bağlaşım (*Low Coupling*)** ve **Yüksek Uyumdur (*High Cohesion*)** (ekrandan, 02:24:30). Genelde düşük bağlaşım yüksek uyumu, yüksek uyum da düşük bağlaşımı beraberinde getirir.

#### 4.1 Düşük Bağlaşım (Low Coupling)

**Bağlaşım (*Coupling*)**, bir parçanın (sınıf, alt sistem veya paket) diğer parçalara bağımlılık oranıdır (ekrandan, 02:24:30). Bir sınıfın diğer bir sınıfa **bağımlı** olması şu dört durumdan biriyle ortaya çıkar (ekrandan, 02:24:30):
- Hizmetlerinden yararlanması,
- İç yapısından haberdar olması,
- Çalışma prensiplerinden haberdar olması,
- Özelleşmiş veya genelleşmiş hâli olması (kalıtım / *inheritance* ilişkisi).

Özetle UML sınıf şemasında bir sınıftan diğerine herhangi bir ok (sahiplik, kullanma veya kalıtım) çıkıyorsa arada yönlü bir bağlaşım vardır. Örneğin alan modelinde `Satış Kalemi`nden `Ürün`e doğru bağlaşım vardır (`Satış Kalemi` ürünü tanır), ancak `Ürün`den `Satış Kalemi`ne doğru bağlaşım yoktur. Bağlaşım oranını artıran şey ilişkili nesne adedi (`1` veya `*`) değil, **ilişkide bulunulan diğer sınıfların sayısıdır** (ekrandan, 02:24:30).

**Düşük Bağlaşımın Yararları (ekrandan, 02:24:30):**
1. Bir sınıfta yapılan değişikliğin geri kalan sınıfların daha azını etkilemesi (Süreklilik ve Koruma),
2. Yeniden kullanılabilirliğin (*reusability*) artması (Birleştirilebilirlik).

#### 4.2 Yüksek Uyum (High Cohesion)

**Uyum (*Cohesion*)**, bir parçanın (sınıfın) üstlendiği sorumlulukların birbiriyle ne kadar yakın ve uyumlu görevlerle ilgili olduğunun ölçüsüdür. Hoca bunu günlük hayattan iki benzetmeyle açıklamıştır:
- Bir kıyafet kombininde şapka, kravat veya kolyenin kıyafetin geri kalanıyla uyumsuz olması gibi, bir sınıfa kendi alt problem alanıyla ilgisiz görevler yüklenmesi uyumu bozar.
- Bir Bilgisayar Mühendisliği öğretim üyesinin doğal sorumlulukları ders vermek, sınav yapmak ve adil değerlendirme yapmaktır; aynı öğretim üyesine personel maaş bordrosu hesaplama veya mediko-sosyal biriminin uzmanlık alanı olan psikolojik danışmanlık görevi yüklenirse sorumluluklar birbiriyle uyumsuz hâle gelir.

Aynı anda birbirinden kopuk pek çok işi yapmaya çalışan düşük uyumlu bir sınıf, psikolojideki "çoklu kişilik sendromu / şizofreni" gibi davranır ve Nesneye Yönelik Programlamanın **"Böl, Parçala, Yönet"** felsefesine aykırı düşer (İzlenebilirlik tablosunda tek bir sınıfın sütununda çok fazla gereksinimde $\checkmark$ işareti olması da o sınıfın aşırı fazla iş üstlendiğinin ve uyumunun düşük olduğunun habercisidir).

**Yüksek Uyumun Yararları:**
1. Sınıf tek bir odaklanmış işi yaptığı için anlaşılması ve bakımı kolaylaşır; hata çıktığında nokta atışı müdahale edilir,
2. Odaklanmış sınıf başka projelerde kolayca yeniden kullanılabilir.

## Örnek Sorular

### Soru 1: İki Alternatif Sınıf Tasarımının Doğrudan ve Dolaylı Bağlaşım Açısından Karşılaştırılması (Ekrandan, 02:39:30)

**Soru:** Aynı problemi çözen aşağıdaki iki alternatif sınıf tasarımını inceleyiniz (ekrandan, 02:39:30):

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

*(Derste yapılan canlı ankette öğrencilerin 15'i II. Tasarımı, 9'u I. Tasarımı seçmiştir.)*
Doğrudan bağlaşım (doğrudan ok $= 1$ puan) ve dolaylı bağlaşım (iki adım uzaktaki geçişli bağımlılık $= 0{,}5$ puan) ölçütlerini kullanarak **hangi tasarımın seçilmesi gerektiğini** matematiksel olarak gösteriniz.

**Cevap (derste verildi):**
1. **Yalnızca Doğrudan Bağlaşımlar Dikkate Alındığında (ekrandan, 02:39:30):**
   - **I. Tasarım:** $\text{bağ}(A) = 1$ ($B$'ye bağımlı), $\text{bağ}(B) = 1$ ($C$'ye bağımlı), $\text{bağ}(C) = 0$.
     - Toplam bağlaşım: $\text{topBağ}_1 = 1 + 1 + 0 = 2$.
     - Maksimum bağlaşım (en kötü durumdaki sınıfın yükü): $\text{bağ}_{\max, 1} = \max(1, 1, 0) = \mathbf{1}$.
   - **II. Tasarım:** $\text{bağ}(A) = 2$ (hem $B$'ye hem $C$'ye bağımlı), $\text{bağ}(B) = 0$, $\text{bağ}(C) = 0$.
     - Toplam bağlaşım: $\text{topBağ}_2 = 2 + 0 + 0 = 2$.
     - Maksimum bağlaşım: $\text{bağ}_{\max, 2} = \max(2, 0, 0) = \mathbf{2}$.
   - *Değerlendirme:* Toplam bağlaşımlar eşit ($2 = 2$) olmasına rağmen, II. Tasarımda $A$ sınıfının maksimum bağlaşımı $2$ iken I. Tasarımda hiçbir sınıfın bağlaşımı $1$'i geçmemektedir ($\text{bağ}_{\max, 1} = 1 < \text{bağ}_{\max, 2} = 2$). Bu nedenle **I. Tasarım** tercih edilir.

2. **Dolaylı Bağlaşımlar da ($0{,}5$ Katsayısıyla) Dikkate Alındığında (ekrandan, 02:39:30):**
   - I. Tasarımda $A$ sınıfı $B$'ye, $B$ de $C$'ye bağımlı olduğu için $A$'yı başka bir projeye taşımak istediğimizde $B$ üzerinden $C$'yi de taşımamız gerekir; yani $A$ dolaylı olarak $C$'ye bağımlıdır ($+0{,}5$).
   - **I. Tasarım (Dolaylı dahil):** $\text{bağ}(A) = 1 + 0{,}5 = 1{,}5$, $\text{bağ}(B) = 1$, $\text{bağ}(C) = 0 \implies \text{bağ}_{\max, 1} = \mathbf{1{,}5}$, $\text{topBağ}_1 = 2{,}5$.
   - **II. Tasarım (Dolaylı dahil):** Dolaylı ilişki yoktur; $\text{bağ}(A) = 2$, $\text{bağ}(B) = 0$, $\text{bağ}(C) = 0 \implies \text{bağ}_{\max, 2} = \mathbf{2}$, $\text{topBağ}_2 = 2$.
   - *Sonuç:* Dolaylı bağlaşım katıldığında bile I. Tasarımdaki $A$ sınıfının maksimum bağlaşımı ($1{,}5$), II. Tasarımdaki $A$ sınıfının doğrudan bağlaşımından ($2$) daha düşüktür ($1{,}5 < 2$). Her iki hesaplama yönteminde de doğru tercih **I. Tasarımdır** (problem alanı doğası aksini zorunlu kılmadığı sürece).

---

### Soru 2: Veritabanı Erişiminde Katmanlı Tasarım — Bağlaşım ve Uyum Çatışması (Ekrandan, 03:00:00)

**Soru:** Soru 1'de seçilen `A -> B -> C` iş katmanı sınıflarından üretilecek nesnelerin bir `VT` veritabanı paketinde saklanması ve geri yüklenmesi gerekmektedir. Bunun için iki tasarım önerilmiştir (ekrandan, 03:00:00):
- **I. Tasarım:** Veritabanına okuma/yazma işlemlerinden sorumlu ayrı bir **`V` sınıfı** oluşturulur (`V` sınıfı `A, B, C` sınıflarını ve `VT` paketini kullanır).
- **II. Tasarım:** Ek sınıf oluşturulmaz; `A, B, C` sınıflarının her biri kendisini doğrudan `VT` paketine yazıp okumaktan sorumludur.

```text
          I. TASARIM (Katmanlı)                      II. TASARIM
   (Turuncu: İş Katmanı | Yeşil: Sistem)
         +-----+        +-----+                 +-----+        +-----+
         |  A  |------->|  B  |                 |  A  |------->|  B  |
         +-----+        +-----+                 +-----+        +-----+
            ^  ..          |                       :            : |
            :    ..        v                       :          ..  v
 +-----+    :      ..   +-----+                    :        .. +-----+
 |  V  |....:........:->|  C  |                    :      ..   |  C  |
 +-----+                +-----+                    v    ..     +-----+
    :                                           +----+..          :
    v                                           | VT |<...........'
 +----+                                         +----+
 | VT |
 +----+
```

*(Dersteki ankette 15 oy II. Tasarıma, 12 oy I. Tasarıma verilmiştir.)*
Bu iki tasarımı **Bağlaşım (*Coupling*)** ve **Uyum (*Cohesion*)** açısından karşılaştırınız ve hangisinin seçilmesi gerektiğini açıklayınız.

**Cevap (derste verildi):**
- **I. Tasarımın Analizi:** `V` sınıfı hem `A, B, C` sınıflarıyla hem de `VT` ile ilişki kurduğu için **bağlaşım yüksektir `(-)`**; ancak `A, B, C` sınıfları yalnızca kendi problem alanı (iş mantığı) sorumluluklarıyla ilgilenip sistem düzeyindeki veritabanı işlerini `V` sınıfına bıraktığı için **uyum yüksektir `(+)`** (ekrandan, 03:00:00). Böylece **İş Katmanı** (`A, B, C`) ile **Sistem Katmanı** (`V` ve `VT`) birbirinden temiz biçimde ayrılmıştır.
- **II. Tasarımın Analizi:** Yeni bir `V` sınıfı eklenmediği için **bağlaşım düşüktür `(+)`**; ancak `A, B, C` sınıflarına hem problem alanı görevleri hem de veritabanı okuma/yazma (sistem tasarımı) görevleri birlikte yüklendiği için **uyum düşüktür `(-)`** (ekrandan, 03:00:00).
- **Karar ve Bakım Senaryosu:** Bu örnek, bağlaşım ile uyumun zıtlaştığı istisnai bir durumdur ve burada **Uyum (I. Tasarım)** tercih edilmelidir. Çünkü ileride ilişkisel veritabanından ilişkisel olmayan (NoSQL / ağ / coğrafi) bir veritabanına geçilmek istendiğinde veya *MS SQL* kullanan kurumsal müşterilerin yanında lisans maliyeti istemeyen KOBİ müşteriler için *MySQL* desteği gerektiğinde:
  - **II. Tasarımda** veritabanı mantığı tüm iş sınıflarına yayıldığı için `A`, `B` ve `C` sınıflarının tamamının kodu değiştirilmek zorunda kalır.
  - **I. Tasarımda** ise problem alanı sınıflarına (`A, B, C`) **hiç dokunulmaz**; yalnızca sistem katmanındaki `V` sınıfı (`V_MSSQL` / `V_MySQL`) güncellenerek değişiklik tek noktada izole edilir (ekrandan, 03:00:00).

## Dersin Toparlaması

Bu derste önce **Nesneye Yönelik Çözümleme** aşamasının en önemli çıktılarından biri olan **Alan Modeli (*Domain Model*)** oluşturulması adım adım uygulanmıştır. Gereksinim metinlerindeki isimlerin taranmasıyla elde edilen aday sınıfların **Saklanan Bilgi, Gereksinim Duyulan Hizmetler** ve **Gerekli Varlıklar** kurallarıyla nasıl elendiği, kuralları sağlamayan adayların nasıl üye alana dönüştüğü ve *Primitive Obsession* kusuruna düşmemek için `Satış Kalemi` gibi ara sınıfların neden zorunlu olduğu *NextGenPOS* örneği üzerinde gösterilmiştir.

Dersin ikinci bölümünde **"Nasıl?"** sorusuna yanıt arayan **Nesneye Yönelik Tasarım Sürecine** geçilmiş; nesne tasarımı ve sistem tasarımı ayrımı ile iyi bir tasarımın beş kalite ölçütü (**Ayrılabilirlik, Birleştirilebilirlik, Anlaşılabilirlik, Süreklilik, Koruma**) incelenmiştir. Son olarak bu ölçütlerin temelini oluşturan **Düşük Bağlaşım (*Low Coupling*)** ve **Yüksek Uyum (*High Cohesion*)** ilkeleri iki etkileşimli sınıf şeması problemi üzerinde nicel ve mimari açıdan karşılaştırılmıştır. Bir sonraki derste sorumluluk güdümlü tasarım ve **GRASP / Gang of Four (GoF) tasarım kalıpları** ile devam edilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
