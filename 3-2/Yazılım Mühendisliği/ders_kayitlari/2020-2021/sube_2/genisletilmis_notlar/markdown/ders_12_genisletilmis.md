# Ders 12 Genişletilmiş Notu: Kütüphane Bilgi Sistemi (Kiosk Otomasyonu) Proje Sunumları Üzerinden Risk Analizi, UML Modelleme ve Birim Sınaması Değerlendirmeleri

*Bu genişletilmiş ders notu, `ders_12.srt` altyazısı ve ders videosu kareleri üzerinden hazırlanmıştır. Dönemin bu son dersinde proje grupları, dönem projesi olan **Özel Aydınlık Üniversitesi Kütüphane Bilgi Sistemi (Kiosk Otomasyonu)** için hazırladıkları risk analizlerini, UML diyagramlarını ve birim sınaması (*unit test*) kodlarını sunmuş; ders sorumlusu Dr. Yunus Emre Selçuk her bir tasarım kararını yazılım mühendisliği ilkeleri doğrultusunda incelemiş ve geri bildirim vermiştir. Bu notta yalnızca akademik içerik, modelleme ilkeleri ve tasarım eleştirileri derlenmiş olup sunum yapanlar "bir grup" veya "bir öğrenci" olarak anılmıştır.*

---

## İçindekiler

1. Proje Problem Alanı: Özel Aydınlık Üniversitesi Kütüphane Kiosk Otomasyonu
2. Risk Analizi, RMMM Tabloları ve Teknik Borç (*Technical Debt*)
3. Davranışsal UML Diyagramlarında Tasarım İlkeleri ve Sık Yapılan Hatalar
4. Yapısal Tasarım: Sınıf Şemaları, Kalıtım Kararları ve Singleton Örüntüsü
5. Eşzamanlılık (*Concurrency*), Sıralama Şemaları ve Katmanlı Mimari Tutarlılığı
6. Birim Sınaması (*Unit Testing*) Uygulamaları ve Duman Testi (*Smoke Test*)
7. Örnek Sorular
8. Dersin Toparlaması

---

## 1. Proje Problem Alanı: Özel Aydınlık Üniversitesi Kütüphane Kiosk Otomasyonu

Dönem projesi olarak tüm gruplara aynı problem tanımı verilmiş ve gruplardan bu problemi nesne yönelimli analiz/tasarım yöntemleriyle modelleyip çekirdek iş mantığını birim testleriyle doğrulamaları istenmiştir.

### 1.1. Sistem Gereksinimleri ve İş Kuralları

**Özel Aydınlık Üniversitesi Kütüphane Bilgi Sistemi**, kütüphane içindeki self-servis **kiosk cihazları** ve kütüphane görevlisi ekranları üzerinden çalışan bir otomasyon sistemidir:

1. **Kullanıcı Rolleri (Aktörler):**
   - **Üyeler (*Members*):** Üniversitenin **Öğrenci** ve **Akademisyen** (Öğretim Üyesi / Personel) kadrosundan oluşur. Üye türüne göre ödünç alınabilecek azami kitap sayısı (kota) ve ödünç tutma süresi değişmektedir (örneğin öğrenciler için en fazla 3 kitap / 15 gün; akademisyenler için en fazla 5 kitap / 30 gün).
   - **Kütüphane Görevlisi (*Librarian / Admin*):** Sisteme yeni kitap ekleme, mevcut kitabı silme/güncelleme, yeni üye tanımlama, üyelik iptali ve gerektiğinde ceza tahsilatı/onayı işlemlerini yürütür.
2. **Temel Kiosk İşlevleri:**
   - **Kimlik Doğrulama (*Login*):** Üye numarası/kartı ve parola ile kioska giriş yapılması.
   - **Kitap Arama (*Search*):** Kitap adı, yazar, ISBN veya kategoriye göre katalogda arama yapılması ve kitabın mevcut durumunun (`Rafta`, `Ödünçte`, `Rezerve`) görüntülenmesi.
   - **Kitap Ödünç Alma (*Borrow*):**
     - Kitap `Rafta` (veya ilgili üye adına `Rezerve`) olmalıdır.
     - Üyenin aktif kitap sayısı kendi kotasının altında olmalıdır.
     - Üyenin ödünç almayı engelleyen ödenmemiş bir gecikme cezası veya cezalı durumu bulunmamalıdır.
   - **Kitap İade Etme (*Return*) ve Gecikme Cezası (*Fine*):**
     - İade tarihinde gecikme varsa gün bazında gecikme cezası hesaplanır.
     - İade edilen kitap için bekleyen bir rezervasyon kuyruğu varsa kitabın durumu `Rezerve Edildi` olarak güncellenir; yoksa `Rafta (Mevcut)` durumuna döner.
   - **Süre Uzatma (*Renew*):**
     - Üye, elindeki kitabın teslim tarihini uzatmak istediğinde kitabın başka bir üye tarafından **rezerve edilmemiş olması** ve üyenin uzatma hakkının bitmemiş olması kontrol edilir.
   - **Kitap Ayırtma / Rezervasyon (*Reserve*):**
     - O anda başka bir üyede ödünçte bulunan bir kitap için sıraya girilmesi işlemidir.

---

## 2. Risk Analizi, RMMM Tabloları ve Teknik Borç (*Technical Debt*)

Dersin önceki haftalarında işlenen **Risk Yönetimi (*Risk Management*)** ve **RMMM (*Risk Mitigation, Monitoring, and Management*)** ilkelerinin proje raporlarına nasıl yansıtıldığı grupların sunumları üzerinden değerlendirilmiştir.

### 2.1. Genel Riskler vs. Projeye Özgü Teknik Riskler

Grupların risk tablolarında sıklıkla *"ekip üyelerinden birinin hastalanması"*, *"bilgisayarın bozulması"* veya *"teslim tarihinin yetişmemesi"* gibi her yazılım projesinde görülebilecek genel riskler yer almıştır. Hoca, bu genel risklerin yanı sıra **kiosk tabanlı bir kütüphane otomasyonuna özgü teknik ve iş alanı risklerinin** mutlaka düşünülmesi gerektiğini vurgulamıştır:

| Risk Kategorisi | Projeye Özgü Somut Risk Örneği | Önleme (*Mitigation*) ve Yönetim (*Management*) Stratejisi |
|---|---|---|
| **Donanım / Entegrasyon Riski** | Kiosk cihazındaki barkod/RFID okuyucu veya kart okuyucu sürücülerinin yazılımla uyumsuz çalışması | Donanım soyutlama katmanı (*interface/adapter*) kullanmak; donanım gelmeden önce sahte (*mock/stub*) okuyucu sınıflarıyla sınama yapmak. |
| **Eşzamanlılık (*Concurrency*) Riski** | Kütüphanedeki iki ayrı kiosktan iki üyenin aynı anda aynı kitabın son kopyasını ödünç almaya veya rezerve etmeye çalışması | Veritabanı düzeyinde işlem (*transaction*) ve iyimser/kötümser kilitleme (*optimistic/pessimistic locking*) mekanizması uygulamak. |
| **Güvenlik ve Veri İhlali Riski** | Kiosk ekranında açık unutulan oturumlar veya üye parolalarının veritabanında açık metin (*plaintext*) tutulması sonucu sızdırılması | Belirli süre işlem yapılmadığında otomatik oturum kapatma (*timeout*); parolaları tuzlanmış özet (*salted hash*) olarak saklamak. |
| **Performans / Ağ Riski** | Merkez kütüphane veritabanı sunucusu ile kiosk arasındaki yerel ağ bağlantısının kopması | Bağlantı koptuğunda kioskun kullanıcıya anlamlı hata vermesi ve yarım kalan işlemi geri alması (*rollback*). |

### 2.2. Teknik Borç (*Technical Debt*) Kavramı

Bir grubun risk yönetimi tablosunda *"Proje takvimi sıkışırsa bazı tasarım kurallarını esnetip kodu hızlıca çalışır hale getiririz, sonra düzeltiriz"* şeklinde bir ifade yer alması üzerine hoca **Teknik Borç (*Technical Debt*)** kavramını açıklamıştır:

- Ward Cunningham tarafından ortaya atılan **Teknik Borç (*Technical Debt*)** metaforuna göre, yazılım geliştirirken hızlı teslimat uğruna doğru mimariden, temiz kod ilkelerinden veya birim testlerinden ödün vermek **faizli borç almaya** benzer.
- Kısa vadede işlev tamamlanmış gibi görünse de, yazılım büyüdükçe bu "kestirme" kodun üzerine yeni özellik eklemek zorlaşır; her değişiklik başka bir yeri bozar ve ödenmesi gereken **faiz (bakım maliyeti ve harcanan ekstra efor)** katlanarak artar.
- Borcun anaparası ise ilgili modülün baştan doğru tasarımla yeniden yazılması (*refactoring*) ile kapatılabilir. Bu nedenle RMMM planında *"önce özensiz yazıp sonra düzeltmek"* bir risk önleme stratejisi değil, bilakis yeni bir teknik risk kaynağıdır.

### 2.3. Veri İhlalleri ve `Have I Been Pwned` Örneği

Güvenlik riskleri tartışılırken hoca, kullanıcıların farklı platformlarda aynı parolayı kullanmasının doğurduğu risklere değinmiş ve **Have I Been Pwned (`haveibeenpwned.com`)** servisini örnek göstermiştir:
- Bu servis, dünyadaki büyük veri sızıntılarında (*data breaches*) ele geçirilen milyarlarca e-posta ve parola kaydını indeksler.
- Sistem tasarımcıları kimlik doğrulama modülü geliştirirken hem kullanıcı parolalarını kriptografik özet (*hash*) fonksiyonlarıyla saklamalı hem de bilinen sızdırılmış parolaların kullanımını engelleyecek güvenlik politikalarını dikkate almalıdır.

---

## 3. Davranışsal UML Diyagramlarında Tasarım İlkeleri ve Sık Yapılan Hatalar

Proje sunumlarında en çok tartışılan konu, UML diyagramlarının birbirleriyle karıştırılması ve notasyon kurallarının ihlal edilmesidir.

### 3.1. Kullanım Senaryosu (*Use Case*) Şeması İlkeleri

Grupların *Use Case* diyagramları incelenirken hocanın vurguladığı temel kurallar şunlardır:

1. **Aktörlerin Rol Ayrımı ve Genelleştirme (*Generalization*):**
   - Kiosk sistemini kullanan `Üye` (Öğrenci / Akademisyen) ile `Kütüphane Görevlisi` farklı yetkilere sahiptir.
   - Örneğin `Kitap Ekle`, `Kitap Sil`, `Üye Kaydet` senaryoları yalnızca `Kütüphane Görevlisi` aktörüne bağlı olmalıdır; normal bir üyenin kiosktan kütüphane envanterine kitap eklemesi mümkün değildir.
   - Eğer `Kütüphane Görevlisi` de bir üye gibi kitap arayabiliyor ve ödünç alabiliyorsa, görevliden tüm üye senaryolarına tek tek çizgi çekmek yerine `Kütüphane Görevlisi` aktöründen `Üye` aktörüne içi boş üçgen uçlu **kalıtım/genelleştirme oku** çizilir.

2. **`<<include>>` ve `<<extend>>` İlişkilerinin Doğru Kullanımı:**
   - **`<<include>>` (Dahil Etme):** Ana kullanım senaryosunun tamamlanabilmesi için **her seferinde zorunlu olarak** çalıştırılan ortak alt adımları gösterir. Ok yönü **Ana Senaryo $\rightarrow$ Dahil Edilen Alt Senaryo** şeklindedir.
     - *Örnek:* `Kitap Ödünç Al`, `Süre Uzat` ve `Kitap Ayırt` senaryolarının hepsi kullanıcının kimliğinin doğrulanmasını gerektiriyorsa, bu senaryolardan `Kimlik Doğrula (Giriş Yap)` senaryosuna `<<include>>` oku çizilir.
   - **`<<extend>>` (Genişletme):** Ana senaryonun normal akışında her zaman çalışmayan, yalnızca **belirli bir koşul (extension point) sağlandığında opsiyonel olarak** devreye giren davranışları gösterir. Ok yönü **Opsiyonel Uzantı Senaryosu $\rightarrow$ Ana Senaryo** şeklindedir.
     - *Örnek:* `Kitap İade Et` işlemi yapılırken yalnızca teslim tarihi geçmişse devreye giren `Gecikme Cezası Öde` (veya `Ceza Hesapla`) senaryosu, `Kitap İade Et` senaryosuna `<<extend>>` okuyla bağlanır.

```text
  [Üye] ──────► ( Kitap Ödünç Al ) ────── <<include>> ──────► ( Giriş Yap )
    │                                                              ▲
    │                                                              │ <<include>>
    └─────────► ( Kitap İade Et  ) ────────────────────────────────┘
                        ▲
                        │ <<extend>> [teslim tarihi geçmişse]
                ( Gecikme Cezası Öde )
```

3. **Kullanım Senaryosu Şemasında İş Akışı (Sıra) Gösterilmez:**
   - *Use Case* diyagramı sistemin dışarıya sunduğu işlevlerin (**"Ne yapar?"**) haritasıdır; *"önce giriş yapılır, oradan arama ekranına geçilir, sonra ödünç alınır"* gibi adım adım algoritma akışı (*flowchart*) *Use Case* şemasında senaryolar birbirine oklarla bağlanarak **gösterilmez**. Akış sırası **Faaliyet (*Activity*)** veya **Sıralama (*Sequence*)** şemasının konusudur.

---

### 3.2. Faaliyet (*Activity*) Şeması İlkeleri

Faaliyet şemaları incelenirken gruplarda görülen başlıca eksiklik **karar düğümlerinin (*decision nodes*) tek taraflı bırakılması** olmuştur:

- **Kural:** Bir faaliyet şemasında karar baklavası (`<>`) kullanıldığında, baklavadan en az iki koşullu ok (`[koşul doğru]` ve `[koşul yanlış / else]`) çıkmalıdır.
- Örneğin *"Kitap ödünç alınabilir durumda mı?"*, *"Üyenin kitap limiti doldu mu?"* veya *"Üyenin gecikme cezası var mı?"* kontrolünden sonra yalnızca `[Uygun]` dalını devam ettirip `[Uygun Değil]` dalını çizmemek diyagramı eksik bırakır.
- Alternatif dalda kullanıcıya ilgili uyarı mesajının (`"Kitap kotanız dolmuştur"`, `"Ödenmemiş cezanız bulunmaktadır"`) gösterildiği bir eylem kutusu yer almalı ve akış bir birleşme (*merge*) düğümüne veya sonlanma düğümüne (*final node*) bağlanmalıdır.

---

### 3.3. Durum (*State*) Şeması İlkeleri: Faaliyet Şeması İle Karıştırılmaması

Ders boyunca hocanın **en çok üzerinde durduğu modelleme hatası**, öğrencilerin Durum Şeması (*State Machine Diagram*) başlığı altında yeniden Faaliyet Şeması (*Activity Diagram*) çizmeleridir:

| Özellik | Faaliyet Şeması (*Activity Diagram*) | Durum Şeması (*State Machine Diagram*) |
|---|---|---|
| **Odak Noktası** | Bir iş sürecinin veya kullanım senaryosunun adım adım **eylem akışı** (*"Kullanıcı kartı okutur $\rightarrow$ Kitabı seçer $\rightarrow$ Onaylar"*). | Tek bir **sınıf/nesne örneğinin** (ör. bir `Kitap` nesnesinin) yaşam döngüsü boyunca bulunduğu **durumlar** (*states*). |
| **Düğümler (Kutular)** | Yapılan **fiilleri / eylemleri** temsil eder (`Kitap Ara`, `Ceza Hesapla`). | Nesnenin o anki **sıfatını / statüsünü** temsil eder (`Rafta`, `Ödünç Verildi`, `Rezerve Edildi`, `Kayıp`). |
| **Oklar (Geçişler)** | Bir eylem bittiğinde sıradaki eyleme geçişi gösterir. | Nesneyi bir durumdan diğerine geçiren **olayı (*event*)**, **[koşulu (*guard*)]** ve **/eylemi (*action*)** gösterir. |

#### `Kitap` Nesnesi İçin Doğru Durum Şeması Modeli

Kütüphane otomasyonunda durum şeması çizilecek en ideal nesne **`Kitap` (veya `KitapKopyası`)** nesnesidir:

1. **Başlangıç Durumu:** Kütüphane envanterine yeni eklenen bir kitap **`Rafta (Mevcut)`** durumuna girer.
2. **`Rafta` $\rightarrow$ `Ödünçte` Geçişi:** `ödünçAl()` olayı tetiklendiğinde (`[üye uygun]` koşuluyla) kitabın durumu **`Ödünçte`** olur.
3. **`Ödünçte` Durumu İçindeki Geçişler:**
   - Süresi içinde `süreUzat()` çağrılır ve `[rezervasyonYok]` ise kitap **`Ödünçte`** kalmaya devam eder (teslim tarihi güncellenir).
   - Başka bir üye `rezerveEt()` çağırırsa kitap **`Ödünçte (Rezerve Bekliyor)`** durumuna geçebilir veya rezervasyon kuyruğu oluşur.
   - Teslim tarihi aşılırsa `süreDoldu()` zaman olayı ile **`Gecikmiş (Overdue)`** durumuna geçer.
4. **İade Geçişi (`iadeEt()`):**
   - `iadeEt() [bekleyen rezervasyon yok]` $\rightarrow$ tekrar **`Rafta (Mevcut)`** durumuna döner.
   - `iadeEt() [bekleyen rezervasyon var]` $\rightarrow$ **`Rezerve Edildi (Sıradaki Üyeyi Bekliyor)`** durumuna geçer.
5. **Envanterden Çıkış:** Kitap kullanılamaz hale gelirse veya silinirse `sil() / kayıpBildir()` ile **`Arşivlendi / Silindi`** durumuna geçerek yaşam döngüsünü tamamlar.

---

## 4. Yapısal Tasarım: Sınıf Şemaları, Kalıtım Kararları ve Singleton Örüntüsü

Grupların **Sınıf Şemaları (*Class Diagrams*)** incelenirken nesne yönelimli tasarımın temel ilkeleri (*kapsülleme, kalıtım, çok biçimlilik, sorumlulukların ayrılması ve tasarım örüntüleri*) somut örneklerle tartışılmıştır.

### 4.1. `Üye` Modellemesi: Kalıtım (*Inheritance*) mı, Tür Niteliği (*Enum*) mi?

Kütüphanede farklı kurallara tabi üye grupları (`Öğrenci`, `Akademisyen`, `Personel`) bulunduğunda iki farklı tasarım yaklaşımı ortaya çıkmıştır:

#### Yaklaşım 1: Kalıtım (*Inheritance*) Kullanımı
```text
              ┌───────────────────────────┐
              │           Üye             │
              ├───────────────────────────┤
              │ - üyeNo : String          │
              │ - adSoyad : String        │
              │ - şifre : String          │
              │ - aktifKitapSayısı : int  │
              ├───────────────────────────┤
              │ + maksKitapLimiti() : int │
              │ + ödünçSüresiGün() : int  │
              │ + cezaHesapla(gün) : double│
              └─────────────┬─────────────┘
                            △
               ┌────────────┴────────────┐
               │                         │
   ┌───────────┴───────────┐ ┌───────────┴───────────┐
   │        Öğrenci        │ │      Akademisyen      │
   ├───────────────────────┤ ├───────────────────────┤
   │ - bölüm : String      │ │ - unvan : String      │
   ├───────────────────────┤ ├───────────────────────┤
   │ + maksKitapLimiti(): 3│ │ + maksKitapLimiti(): 5│
   │ + ödünçSüresiGün(): 15│ │ + ödünçSüresiGün(): 30│
   └───────────────────────┘ └───────────────────────┘
```

#### Yaklaşım 2: Tek `Üye` Sınıfı İçinde `ÜyeTürü` (Enum / Parametre) Kullanımı
```text
   ┌────────────────────────────────────┐
   │                Üye                 │
   ├────────────────────────────────────┤
   │ - üyeNo : String                   │
   │ - adSoyad : String                 │
   │ - üyeTürü : ÜyeTürü {ÖĞRENCİ, AKD} │
   │ - maksKitapLimiti : int            │
   │ - ödünçSüresiGün : int             │
   └────────────────────────────────────┘
```

#### Hocanın Tasarım Değerlendirmesi
- Eğer `Öğrenci` ve `Akademisyen` arasındaki **tek fark** alabilecekleri kitap sayısı (`3` vs. `5`) gibi sabit sayılardan ibaretse ve bu sınıfların kendine özgü farklı nitelikleri veya farklı çalışan metotları yoksa, sırf sayı farkı için alt sınıf türetmek gereksiz karmaşıklık yaratabilir; tek bir `Üye` sınıfında kurucu metotla veya `ÜyeTürü` (*enum*) ile bu limitleri atamak yeterlidir.
- Buna karşılık, `Öğrenci` ve `Akademisyen` sınıflarının **kendilerine özgü öznitelikleri** varsa (öğrencinin danışmanı/bölümü, akademisyenin unvanı/fakültesi) veya **davranışları (metot algoritmaları)** değişiyorsa (örneğin akademisyenler için farklı bir ceza/uzatma politikası uygulanıyorsa), **kalıtım (*inheritance*)** kullanmak **Açık-Kapalı İlkesi (*Open-Closed Principle*)** açısından çok daha güçlüdür. Sisteme ileride `MezunÜye` eklendiğinde mevcut `if-else` bloklarını değiştirmeden yeni bir alt sınıf eklemek yeterli olur.
- **Önemli Uyarı:** Bir grup hem `Üye` sınıfının içine `üyeTürü : String` koyup hem de altına `Öğrenci` ve `Akademisyen` alt sınıfları çizdiğinde hoca bunun **tasarım tekrarı (*redundancy*)** olduğunu belirtmiştir: Kalıtım kullanılıyorsa nesnenin türü zaten kendi sınıfından (*polymorphism*) bellidir; ayrıca bir `tür` değişkeni tutup `if (tür == "Öğrenci")` kontrolü yapmak nesne yönelimli programlamanın amacına aykırıdır.

---

### 4.2. Singleton (Tek Nesne) Tasarım Örüntüsünün Doğru Uygulanması

Bazı gruplar sistemin merkezi yöneticisi olan `Kütüphane` veya `VeritabanıBağlantısı` sınıfında **Singleton** tasarım örüntüsü kullandıklarını belirtmişlerdir. Hoca, sınıf şemasında ve kodda bir sınıfın gerçekten *Singleton* olabilmesi için gereken **üç zorunlu bileşeni** sorgulamıştır:

```java
public class KutuphaneSistemi {
    // 1. Sınıfın kendi türünden private static tekil referansı
    private static KutuphaneSistemi instance = null;

    // 2. Dışarıdan 'new KutuphaneSistemi()' çağrısını engelleyen PRIVATE kurucu!
    private KutuphaneSistemi() {
        // Başlangıç listeleri / veritabanı bağlantısı hazırlanır
    }

    // 3. Tekil nesneye küresel erişim sağlayan public static metot
    public static synchronized KutuphaneSistemi getInstance() {
        if (instance == null) {
            instance = new KutuphaneSistemi();
        }
        return instance;
    }
}
```

- **Sık Yapılan Hata:** Sınıf şemasında `+ getInstance() : KutuphaneSistemi` metodunu yazıp kurucu metodu `public` (`+ KutuphaneSistemi()`) bırakmak veya `- instance : KutuphaneSistemi` statik değişkenini göstermemek, Singleton örüntüsünün eksik uygulanmasıdır. Kurucu metot `private` (`-`) yapılmazsa başka bir geliştirici `new` anahtar sözcüğüyle ikinci bir kütüphane nesnesi oluşturabilir.

---

### 4.3. Sınıf Şemasında İlişkiler, Çokluk (*Multiplicity*) ve Ara Sınıflar

- **Çokluk (*Multiplicity*) Sayıları:** İlişki çizgilerinin iki ucuna mutlaka çokluk değerleri (`1`, `0..1`, `0..*`, `1..3`) yazılmalıdır. Örneğin bir kitabın birden fazla yazarı olabileceği (`Kitap "0..*" --- "1..*" Yazar`) veya bir üyenin aynı anda belirli sayıda ödünç işlemi yapabileceği diyagramdan okunabilmelidir.
- **`Ödünçİşlemi` (*Loan / BorrowRecord*) Ara Sınıfı:**
  - `ödünçAlmaTarihi`, `sonTeslimTarihi`, `iadeTarihi` ve `cezaTutarı` gibi bilgiler doğrudan `Üye` sınıfının içine yazılırsa, üye 3 farklı kitap aldığında hangi tarihin hangi kitaba ait olduğu karışır.
  - Bu bilgiler doğrudan `Kitap` sınıfının içine yazılırsa, kitabın geçmiş ödünç alma tarihçesi (*history*) tutulamaz.
  - Doğru nesne yönelimli çözüm, `Üye` ile `Kitap` arasında **`ÖdünçKaydı` (*Loan*)** (ve benzer şekilde **`Rezervasyon`**) adında bir ilişki/işlem sınıfı tanımlamaktır:

```text
  ┌──────────┐ 1          0..* ┌──────────────────────┐ 0..*         1 ┌──────────┐
  │   Üye    │─────────────────│      ÖdünçKaydı      │────────────────│  Kitap   │
  └──────────┘                 ├──────────────────────┤                └──────────┘
                               │ - alışTarihi : Date  │
                               │ - teslimTarihi : Date│
                               │ - iadeEdildiMi : bool│
                               ├──────────────────────┤
                               │ + gecikmeGünü() : int│
                               │ + cezaHesapla() : TL │
                               └──────────────────────┘
```

---

## 5. Eşzamanlılık (*Concurrency*), Sıralama Şemaları ve Katmanlı Mimari Tutarlılığı

### 5.1. Diyagramlar Arası Tutarlılık (*Consistency*)

Hocanın proje incelemelerinde dikkat çektiği en önemli kalite ölçütlerinden biri **diyagramlar arası izlenebilirlik ve tutarlılıktır**:
1. *Use Case* diyagramındaki temel senaryolar (ör. `Kitap Ödünç Al`), *Sıralama (Sequence)* diyagramında nesneler arası mesajlaşma olarak detaylandırılmalıdır.
2. *Sıralama* diyagramının üst kısmındaki yaşam çizgisi (*lifeline*) kutularında yer alan sınıflar (`:KioskEkranı`, `:ÖdünçYöneticisi`, `:Üye`, `:Kitap`), *Sınıf (Class)* diyagramında aynı isimle bulunmalıdır.
3. *Sıralama* diyagramında A nesnesinden B nesnesine gönderilen her `mesaj()` oku, *Sınıf* diyagramında **B sınıfının (mesajı alan hedef sınıfın!)** bir metodu olarak tanımlanmış olmalıdır.

### 5.2. Çoklu Kiosk Ortamında Eşzamanlılık (*Concurrency*) Sorunu

Bir grubun sıralama ve sınıf diyagramları incelenirken hoca şu mimari soruyu yöneltmiştir:
> *"Kütüphanede 5 tane kiosk cihazı var. Rafta tek kopyası kalan bir kitabı iki farklı öğrenci iki ayrı kiosktan aynı saniyede ödünç almaya çalışırsa sisteminiz nasıl davranır?"*

- Eğer sistem önce `if (kitap.musaitMi())` kontrolü yapıp, araya başka işlemler girdikten sonra `kitap.durumAyarla(ODUNCTE)` çağrısı yapıyorsa ve bu iki adım **atomik (*atomic*)** değilse, her iki kiosk da kitabı `"Müsait"` görür ve aynı kitabı iki farklı kişiye ödünç verir (**Yarış Durumu / *Race Condition***).
- **Çözüm:**
  - Uygulama katmanında kritik bölge (*critical section*) kilitlemesi (`synchronized` / `lock`) veya
  - Veritabanı katmanında **ACID işlem (*transaction*)** ve satır kilitleme (*row-level locking* / `SELECT ... FOR UPDATE` veya iyimser kilitleme *version* kontrolü) kullanılarak ilk işlemi başlatan kioskun kaydı kilitlemesi, ikinci kioska ise `"Kitap şu anda başka bir işlemde / ödünç alındı"` uyarısının döndürülmesi gerekir.

---

## 6. Birim Sınaması (*Unit Testing*) Uygulamaları ve Duman Testi (*Smoke Test*)

Dersin son aşamasında her grup kendi geliştirdiği kütüphane sınıfları üzerinde **birim sınaması (*unit test*)** kodlarını (Java JUnit, C# MSTest/NUnit veya Python `unittest` ile) çalıştırmıştır.

### 6.1. Etkili Birim Sınaması Yazım İlkeleri

Sunulan test kodları üzerinden hocanın yaptığı teknik düzeltmeler şunlardır:

1. **`print` Değil `assert` Kullanımı:**
   - Birim testinin amacı, bir insanın konsol ekranını okuyup *"evet doğru çalışmış"* demesi değil; test çerçevesinin (*JUnit* vb.) beklenen değer ile gerçek çıktıyı karşılaştırarak testi otomatik geçirmesi (`Pass` - Yeşil) veya bırakmasıdır (`Fail` - Kırmızı).
   - Bu nedenle her test metodu mutlaka `assertEquals(expected, actual)`, `assertTrue(condition)` veya `assertFalse(condition)` içermelidir.

2. **Pozitif, Negatif ve Sınır Değer (*Boundary*) Testlerinin Birlikte Yazılması:**
   - Yalnızca başarılı ödünç alma işlemini sınayan tek bir test yetersizdir. Bir kütüphane otomasyonu için örnek birim testi kümesi şu senaryoları kapsamalıdır:

```java
import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;

public class KutuphaneBirimTesti {
    private KutuphaneSistemi sistem;
    private Uye ogrenci;
    private Kitap kitap1, kitap2, kitap3, kitap4;

    @Before
    public void setUp() {
        sistem = new KutuphaneSistemi();
        ogrenci = new Ogrenci("101", "Test Ogrenci"); // Limit: 3 kitap
        kitap1 = new Kitap("ISBN-1", "Yazilim Muhendisligi");
        kitap2 = new Kitap("ISBN-2", "Veri Yapilari");
        kitap3 = new Kitap("ISBN-3", "Algoritmalar");
        kitap4 = new Kitap("ISBN-4", "Isletim Sistemleri");
        sistem.uyeEkle(ogrenci);
        sistem.kitapEkle(kitap1);
        sistem.kitapEkle(kitap2);
        sistem.kitapEkle(kitap3);
        sistem.kitapEkle(kitap4);
    }

    @Test
    public void testBasariliKitapOduncAlma() {
        boolean sonuc = sistem.oduncAl(ogrenci, kitap1);
        assertTrue("Raftaki kitap engelsiz ogrenciye verilmeli", sonuc);
        assertEquals(KitapDurumu.ODUNCTE, kitap1.getDurum());
        assertEquals(1, ogrenci.getAktifKitapSayisi());
    }

    @Test
    public void testOdunctekiKitabinTekrarOduncAlinamamasi() {
        Uye baskaOgrenci = new Ogrenci("102", "Ikinci Ogrenci");
        sistem.uyeEkle(baskaOgrenci);

        sistem.oduncAl(ogrenci, kitap1);
        // Ayni kitabi baska bir uye odunc almaya calisiyor (Negatif Test)
        boolean ikinciSonuc = sistem.oduncAl(baskaOgrenci, kitap1);
        assertFalse("Oduncte olan kitap ikinci kez odunc verilemez", ikinciSonuc);
    }

    @Test
    public void testKitapKotasiAsildigindaOduncEngelleme() {
        // Ogrenci 3 kitap limitini dolduruyor (Sinir Deger Testi)
        assertTrue(sistem.oduncAl(ogrenci, kitap1));
        assertTrue(sistem.oduncAl(ogrenci, kitap2));
        assertTrue(sistem.oduncAl(ogrenci, kitap3));

        // 4. kitabi almaya calistiginda reddedilmeli
        boolean dorduncuKitapSonucu = sistem.oduncAl(ogrenci, kitap4);
        assertFalse("Kota doluyken 4. kitap odunc alinamaz", dorduncuKitapSonucu);
        assertEquals(3, ogrenci.getAktifKitapSayisi());
    }

    @Test
    public void testGecikmeCezasiHesaplama() {
        // Gunluk gecikme cezasi 2.0 TL varsayimiyla:
        assertEquals(0.0, sistem.cezaHesapla(0), 0.001); // Gecikme yok
        assertEquals(10.0, sistem.cezaHesapla(5), 0.001); // 5 gun gecikme
    }
}
```

3. **Sahte Nesneler (*Stub / Mock / Dummy*) ve Veritabanından Bağımsızlık:**
   - Birim sınaması yapılırken gerçek bir SQL veritabanı sunucusunun ayakta olmasına veya kullanıcıdan klavyeyle (`Scanner` / `Console.ReadLine`) girdi beklenmesine gerek olmamalıdır.
   - Birim testleri bellek içi (*in-memory*) nesneler veya sahte (*stub*) veri kaynakları üzerinde milisaniyeler içinde otomatik çalışmalıdır; kullanıcıdan konsol girdisi bekleyen testler otomasyon akışını kilitler.

---

### 6.2. Duman Testi (*Smoke Testing*) Nedir?

Bir grubun sunumunda yaptıkları temel doğrulama testlerini **Duman Testi (*Smoke Test*)** olarak adlandırması üzerine hoca bu kavramın kökenini ve yazılım sınamasındaki yerini açıklamıştır:

- **Kökeni:** Elektronik ve donanım mühendisliğinde yeni monte edilen bir devre kartına ilk kez elektrik verildiğinde *"devreden duman çıkıyor mu?"* diye yapılan ilk kontrolden adını alır. Duman çıkıyorsa ayrıntılı ölçümlere geçmeye gerek kalmadan fiş çekilir.
- **Yazılım Mühendisliğindeki Karşılığı (*Build Verification Testing*):**
  - Yazılımın yeni bir sürümü (*build*) derlendiğinde veya entegre edildiğinde, ayrıntılı ve uzun süren birim/entegrasyon/sistem testlerine geçmeden önce **"Sistem ayağa kalkıyor mu? Ana ekran açılıyor mu? En temel işlevler (ör. giriş yapma, katalog listeleme) çökmeden çalışıyor mu?"** sorularını yanıtlayan hızlı ve yüzeysel ön testtir.
  - Dolayısıyla *Smoke Test*, kapsamlı birim sınamasının (*Unit Testing*) alternatifi değil; test sürecinin en başında bozuk derlemeleri (*broken builds*) erken yakalamak için koşulan bir kapı bekçisi (*gatekeeper*) testidir.

---

## Örnek Sorular

### Soru 1 (Durum Şeması vs. Faaliyet Şeması ve Nesne Yaşam Döngüsü)
Bir kütüphane otomasyonu projesinde bir öğrenci, **Durum Şeması (*State Diagram*)** başlığı altında şu kutuları birbirine bağlamıştır:
`[Kioska Giriş Yap] -> [Kitap Barkodunu Okut] -> [Ödünç Alma Onayı Ver] -> [Fiş Yazdır]`.
1. Bu diyagram neden geçerli bir UML Durum Şeması değildir? Hangi UML diyagramı türüne karşılık gelir?
2. Aynı sistemdeki bir **`Kitap`** nesnesi için ödünç alma, süre uzatma, rezerve edilme ve iade edilme olaylarını kapsayan doğru durumları (*states*) ve geçiş koşullarını (*guards*) tanımlayınız.

**Çözüm:**
1. Çizilen diyagramdaki kutular bir nesnenin durumlarını (sıfatlarını) değil, bir iş sürecinde art arda gerçekleştirilen eylemleri (fiilleri) göstermektedir. Bu nedenle çizilen şema bir **Faaliyet Şeması (*Activity Diagram*)**'dır. Durum şeması, sistemin genel iş akışını değil, **tek bir nesnenin** (örneğin `Kitap` nesnesinin) olaylara tepki olarak zaman içinde değişen durumlarını modellemelidir.
2. **`Kitap` Nesnesi İçin Doğru Durumlar ve Geçişler:**
   - **Durumlar:** `Rafta (Mevcut)`, `Ödünçte`, `Gecikmiş (Süresi Dolmuş)`, `Rezerve Edildi`.
   - **Geçişler:**
     - `Başlangıç` $\rightarrow$ `Rafta`: `kitapEkle()`
     - `Rafta` $\rightarrow$ `Ödünçte`: `ödünçAl() [üye kotası uygun VE üye cezasız]`
     - `Ödünçte` $\rightarrow$ `Ödünçte` (öz-geçiş): `süreUzat() [bekleyen rezervasyon yok VE uzatma hakkı var]`
     - `Ödünçte` $\rightarrow$ `Gecikmiş`: `teslimTarihiGeçti()`
     - `Ödünçte` (veya `Gecikmiş`) $\rightarrow$ `Rafta`: `iadeEt() [bekleyen rezervasyon yok]`
     - `Ödünçte` (veya `Gecikmiş`) $\rightarrow$ `Rezerve Edildi`: `iadeEt() [bekleyen rezervasyon var]`
     - `Rezerve Edildi` $\rightarrow$ `Ödünçte`: `ödünçAl() [işlemi yapan üye == rezervasyon sahibi]`
     - `Rezerve Edildi` $\rightarrow$ `Rafta`: `rezervasyonSüresiDoldu()` veya `rezervasyonİptal()`

---

### Soru 2 (Use Case İlişkileri ve Sınıf Tasarımı)
Kütüphane Kiosk Sisteminde:
- Her `Kitap Ödünç Al` ve `Kitap Süre Uzat` işleminde kullanıcının kimliğinin doğrulanması (`Kimlik Doğrula`) zorunludur.
- `Kitap İade Et` işlemi sırasında ise yalnızca kitabın teslim tarihi geçmişse `Gecikme Cezası Tahsil Et` senaryosu çalışmaktadır.

1. Bu senaryolar arasındaki UML Use Case ilişkilerini (`<<include>>` / `<<extend>>`) ve **ok yönlerini** belirtiniz.
2. Sınıf diyagramında `KütüphaneYöneticisi` sınıfının sistem genelinde yalnızca **tek bir nesne örneğine (*Singleton*)** sahip olması istenmektedir. Bu sınıfın UML kutusunu (nitelik, kurucu ve metot görünürlük işaretleriyle: `+`, `-`, `static`) çiziniz.

**Çözüm:**
1. **Use Case İlişkileri ve Ok Yönleri:**
   - Zorunlu alt adımlar için `<<include>>` kullanılır ve ok ana senaryodan alt senaryoya doğrudur:
     - `(Kitap Ödünç Al) - - <<include>> - - > (Kimlik Doğrula)`
     - `(Kitap Süre Uzat) - - <<include>> - - > (Kimlik Doğrula)`
   - Koşula bağlı opsiyonel davranışlar için `<<extend>>` kullanılır ve ok uzantı senaryosundan ana senaryoya doğrudur:
     - `(Gecikme Cezası Tahsil Et) - - <<extend>> [teslim tarihi aşıldıysa] - - > (Kitap İade Et)`
2. **`KütüphaneYöneticisi` Singleton UML Sınıf Kutusu:**
   *(Not: UML'de `static` üyelerin altı çizilir veya `{static}` ile belirtilir; kurucu metot mutlaka `-` yani `private` olmalıdır.)*

```text
   ┌────────────────────────────────────────────────────────┐
   │                   KütüphaneYöneticisi                  │
   ├────────────────────────────────────────────────────────┤
   │ - instance : KütüphaneYöneticisi {static}              │
   ├────────────────────────────────────────────────────────┤
   │ - KütüphaneYöneticisi()                                │
   │ + getInstance() : KütüphaneYöneticisi {static}         │
   │ + ödünçVer(üye: Üye, kitap: Kitap) : boolean           │
   │ + iadeAl(kitap: Kitap) : double                        │
   └────────────────────────────────────────────────────────┘
```

---

### Soru 3 (Birim Sınaması Tasarımı ve Sınır Değer Analizi)
Kütüphane sisteminde `boolean sureUzat(Uye uye, Kitap kitap)` metodu şu kurallara göre çalışmaktadır:
- Kitap ilgili üyede ödünçte değilse `false` döner.
- Kitap başka bir üye tarafından rezerve edilmişse `false` döner.
- Bir kitabın süresi en fazla **2 kez** uzatılabilir (`uzatmaSayisi < 2`); 3. kez uzatılmak istenirse `false` döner.
- Yukarıdaki engeller yoksa teslim tarihi 15 gün uzatılır, `uzatmaSayisi` 1 artırılır ve `true` döner.

Bu metodu eksiksiz sınamak için yazılması gereken **en az 4 farklı birim testi (*unit test*) senaryosunu** ve her birinde hangi `assert` doğrulamasının yapılacağını açıklayınız.

**Çözüm:**
1. **`testBasariliIlkSureUzatma` (Pozitif Test):**
   - *Kurulum:* Kitap üyeye ödünç verilir (`uzatmaSayisi == 0`, `rezerve == false`).
   - *Eylem:* `sistem.sureUzat(uye, kitap)` çağrılır.
   - *Doğrulama:* `assertTrue(sonuc)` ve `assertEquals(1, kitap.getUzatmaSayisi())`.
2. **`testRezerveEdilmisKitabinSuresiUzatilamaz` (Negatif Test - Rezervasyon Engeli):**
   - *Kurulum:* Kitap `uye1`'de ödünçteyken `uye2` kitabı rezerve eder (`kitap.isRezerve() == true`).
   - *Eylem:* `sistem.sureUzat(uye1, kitap)` çağrılır.
   - *Doğrulama:* `assertFalse(sonuc)` ve `assertEquals(0, kitap.getUzatmaSayisi())`.
3. **`testMaksimumUzatmaLimitiAsimi` (Sınır Değer Testi - 2 Uzatma Sınırı):**
   - *Kurulum:* Kitap ödünç alınır; arka arkaya iki kez `sureUzat` çağrılır (`assertTrue` ile 1. ve 2. uzatmanın başarılı olduğu doğrulanır, `uzatmaSayisi == 2` olur).
   - *Eylem:* 3. kez `sistem.sureUzat(uye, kitap)` çağrılır.
   - *Doğrulama:* `assertFalse(sonuc)` ve `assertEquals(2, kitap.getUzatmaSayisi())`.
4. **`testBaskasindaVeyaRaftaOlanKitabinSuresiUzatilamaz` (Negatif Test - Yetkisiz/Geçersiz Durum):**
   - *Kurulum:* Kitap henüz `Rafta` durumundadır (veya başka bir üyede ödünçtedir).
   - *Eylem:* `sistem.sureUzat(uye, kitap)` çağrılır.
   - *Doğrulama:* `assertFalse(sonuc)`.

---

## Dersin Toparlaması

1. **Analizden Sınamaya Bütüncül Bakış:** Bu ders, dönem boyunca işlenen **Risk Yönetimi**, **Kullanım Senaryosu (Use Case)**, **Faaliyet (Activity)**, **Durum (State)**, **Sıralama (Sequence)**, **Sınıf (Class)** diyagramları ve **Birim Sınaması (Unit Testing)** konularının gerçek bir proje ("Kütüphane Kiosk Otomasyonu") üzerinde nasıl bir bütün oluşturduğunu göstermiştir.
2. **Diyagramların Amacına Uygun Kullanımı:**
   - *Use Case* diyagramı sistemin dış aktörlere sunduğu işlevleri,
   - *Faaliyet* diyagramı algoritmik iş akışını ve karar dallarını,
   - *Durum* diyagramı tek bir nesnenin (`Kitap`) yaşam döngüsü durumlarını,
   - *Sıralama* diyagramı nesneler arası zaman sıralı mesajlaşmayı,
   - *Sınıf* diyagramı ise statik mimariyi, kalıtım hiyerarşisini ve tasarım örüntülerini (*Singleton* vb.) temsil eder; bu diyagramlar birbirinin yerine kullanılmamalı ve birbirleriyle çelişmemelidir.
3. **Kalite Güvencesi ve Sınama:** İyi bir tasarım, teknik borçtan (*technical debt*) kaçınarak ve hem pozitif hem de negatif/sınır durumları otomatik `assert` ifadeleriyle denetleyen bağımsız **birim testleri** yazılarak güvence altına alınır.

---

*Not: Bu genişletilmiş ders notunu Google Gemini NotebookLM veya benzeri bir çalışma aracına yükleyerek kendi kendinize sınav soruları üretebilir, UML tasarım kuralları ve birim testi senaryoları üzerine etkileşimli tekrar yapabilirsiniz.*
