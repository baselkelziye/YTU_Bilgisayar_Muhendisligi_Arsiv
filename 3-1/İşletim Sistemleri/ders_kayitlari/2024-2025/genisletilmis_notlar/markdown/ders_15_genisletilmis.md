# Ders 15 Genişletilmiş Notu: Dosya Sistemi Arayüzü (Dosya Kavramı, Erişim Yöntemleri, Dizin Yapıları, Paylaşım ve Koruma) ve Dosya Sistemi Gerçeklemesi (Katmanlı Mimari, FCB, Blok Tahsis Yöntemleri ve Boş Alan Yönetimi)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dosya Kavramı (File Concept), Dosya Yapısı ve Dosya Öznitelikleri (File Attributes)
- 2. Dosya İşlemleri (File Operations), Açık Dosya Tabloları ve Dosya Türleri
- 3. Dosya Erişim Yöntemleri: Sıralı, Doğrudan (Bağıl) ve İndeksli Erişim
- 4. Dizin Yapısı (Directory Structure), Disk Bölümleri ve Dizin Mimarileri
- 5. Dosya Paylaşımı (File Sharing) ve Koruma Mekanizmaları (`chmod` / Erişim Listeleri)
- 6. Dosya Sistemi Gerçeklemesi: Katmanlı Mimari, FCB, Açık Dosya Tabloları ve VFS
- 7. Disk Blok Tahsis Yöntemleri: Bitişik (Contiguous), Bağlı (Linked / FAT) ve İndeksli (Indexed / UFS) Tahsis
- 8. Boş Alan Yönetimi (Free-Space Management): Bit Vektörü ve Bağlı Boş Alan Listesi
- Örnek Sorular
- Dersin Toparlaması

---

## 1. Dosya Kavramı (File Concept), Dosya Yapısı ve Dosya Öznitelikleri (File Attributes)

### 1.1 Yığın Depolamanın Fiziksel Boyutundan Mantıksal Dosya Sistemine Geçiş

Önceki derslerde işletim sisteminin işlemci yönetimi (CPU zamanlama, senkronizasyon, kilitlenme), ana bellek yönetimi (`Main Memory`) ve sanal bellek yönetimi (`Virtual Memory`) bileşenleri incelenmiş, ardından ikincil depolama (`Mass Storage`) aygıtlarında okuma/yazma kafasının hareketini en aza indiren fiziksel disk zamanlama algoritmaları (`FCFS`, `SSTF`, `SCAN`, `C-SCAN`, `C-LOOK`) ele alınmıştı.

Bu derste ise kalıcı verilerin saklandığı disk yapılarına **mantıksal açıdan** nasıl bakıldığı, yani verilerin **dosyalar (`files`)** ve **dizinler/klasörler (`directories`)** halinde nasıl organize edildiği, çok kullanıcılı ortamlarda erişim ve korumanın (`protection`) nasıl sağlandığı ve işletim sisteminin dosya sistemini disk üzerinde nasıl gerçeklediği (`File-System Interface` ve `File-System Implementation` — Silberschatz Bölüm 11 ve Bölüm 12) incelenmektedir.

### 1.2 Dosya Kavramı (File Concept) ve Başlık-İçerik-Altbilgi Yapısı

**Dosya (`File`)**, ikincil depolama (disk) üzerinde mekansal açıdan süreklilik ifade eden **mantıksal ve bitişik (`contiguous`) bir adres alanıdır**. Kullanıcı açısından kalıcı depolamanın en küçük mantıksal birimi dosyadır; herhangi bir veriyi (kelime işlemci belgesi, müzik, görüntü veya çalıştırılabilir kod) diskte saklamak için mutlaka bir dosya içine yazmak gerekir.

Dosyalarda tutulan içerik genel olarak iki ana gruba ayrılır:
1. **Veri (`Data`) Dosyaları:** Sayısal (`numeric`), karakter (`character`) veya ikilik (`binary`) verilerden oluşur. Kendi içinde ikiye ayrılır:
   - **Yapısal (`Structured`) Veriler:** Belirli bir şablon veya sütun/satır mantığıyla düzenlenmiş, doğrudan okunup işlenebilen verilerdir (örneğin **CSV** dosyaları veya tablo yapıları).
   - **Yapısal Olmayan (`Unstructured`) / Serbest Biçimli Veriler:** Doğrudan tablosal bir alanı olmayan belgeler ve ortam dosyalarıdır (örneğin **PDF** belgeleri, **MP3** ses dosyaları, görüntü dosyaları). Hoca, örneğin bir makine öğrenmesi uygulamasında yapısal olmayan PDF veya MP3 dosyalarından anlamlı veri elde etmek için önce öznitelik çıkarımı (`feature extraction`) yapılması gerektiğini belirtti.
2. **Program (`Program`) Dosyaları:** Kaynak kod dosyaları (`.c`, `.java` vb.) ve makine diline derlenmiş çalıştırılabilir (`executable` — `.exe`, `.com`, `.bin`, `.bat`, `.jar`) dosyalardır.

> **Hocanın vurgusu:** Yapısal olmayan dosyalar dahil olmak üzere hemen her dosya formatının kendine özgü bir iç organizasyonu vardır ve çoğu dosya üç temel bölümden oluşur:
> 1. **Başlık (`Header`):** Dosyanın türü, bellekte ne kadar yer tutacağı ve nasıl yorumlanacağına dair öznitelikleri barındırır.
> 2. **İçerik (`Content` / `Context`):** Dosyanın asıl veri yükünü (örneğin piksellerin sayısal matris değerlerini veya sıkıştırılmış ses örneklerini) tutar.
> 3. **Altbilgi (`Footer`):** Gerektiğinde dosyanın sonunu veya doğrulama/kontrol bilgilerini belirten kapanış kısmıdır.

Örneğin bir **görüntü dosyasını (`PNG`, `BMP` vb.)** açmak istediğimizde içerik kısmında yalnızca piksellerin sayısal parlaklık/renk değerleri yer alır. Görüntüleme yazılımının bu sayıları ekranda doğru bir matris olarak çizebilmesi için $x$ ekseninde kaç piksel, $y$ ekseninde kaç piksel bulunduğunu ve her pikselin **renk derinliğinin (`color depth`)** kaç bit olduğunu bilmesi gerekir. İşte bu boyut ve renk derinliği bilgileri dosyanın **`header`** kısmında tutulur; benzer şekilde bir MP3 dosyasının başlığında da sesin süresi ve sıkıştırma parametreleri yer alır.

### 1.3 Dosya Öznitelikleri (File Attributes)

Bir işletim sistemi, yönettiği her dosya için (kullanıcının dosyaya sağ tıklayıp *"Özellikler / Properties"* veya macOS'ta *"Get Info"* dediğinde bir kısmını görebildiği) şu temel öznitelikleri tutmak zorundadır:
- **Ad (`Name`):** Dosyanın insanlar tarafından okunabilir biçimde tutulan tek bilgisidir; kullanıcılar aramalarını genellikle dosya adıyla yapar.
- **Tanımlayıcı (`Identifier`):** Dosya sistemi içinde dosyayı tekil (*unique*) olarak tanımlayan sayısal etikettir (örneğin UNIX'teki `inode` numarası). Kullanıcıların görmediği, işletim sisteminin içeride dosyaya erişirken kullandığı benzersiz kimliktir.
- **Tür (`Type`):** Farklı dosya türlerini destekleyen sistemler için dosyanın biçimini (PDF, PNG, BMP, çalıştırılabilir program vb.) belirten bilgidir. İşletim sistemi bir PDF dosyasına çift tıklandığında müzik çalar yerine PDF okuyucu yazılımı açmayı bu öznitelik sayesinde bilir.
- **Konum (`Location`):**
  - *Mantıksal konum:* Kullanıcının anladığı biçimde dosyanın hangi diskin hangi klasöründe olduğudur (örneğin `C:\DersNotlarim\IsletimSistemi\chapter15.ppt`).
  - *Fiziksel konum:* İşletim sisteminin tuttuğu, dosyanın hangi aygıtta ve o diskin hangi silindir/iz/sektör veya blok adresinde bulunduğunu gösteren **işaretçi (`pointer`)** bilgisidir.
- **Boyut (`Size`):** Dosyanın mevcut boyutu (bayt, KB, MB cinsinden kapladığı alan).
- **Koruma (`Protection`):** Kimlerin bu dosyayı okuyabileceğini, yazabileceğini veya çalıştırabileceğini denetleyen erişim kontrol bilgisidir.
- **Zaman, Tarih ve Kullanıcı Kimliği (`Time, date, and user identification`):** Dosyanın ne zaman oluşturulduğu (`created`), en son ne zaman değiştirildiği (`modified`), en son ne zaman erişildiği ve hangi kullanıcı tarafından oluşturulduğu/değiştirildiği bilgileridir. Koruma (`protection`), güvenlik (`security`) ve kullanım izleme/kayıt (`logging`) amacıyla arka planda tutulur.

Bu özniteliklerin tamamı disk üzerinde kalıcı olarak saklanan **dizin yapısı (`directory structure`)** ve dosya kontrol blokları içinde tutulur.

---

## 2. Dosya İşlemleri (File Operations), Açık Dosya Tabloları ve Dosya Türleri

### 2.1 Soyut Veri Tipi Olarak Dosya ve Temel Dosya İşlemleri

Dosya, işletim sistemi açısından bir **soyut veri tipidir (`Abstract Data Type — ADT`)**. İşletim sistemi dosyalar üzerinde şu altı temel sistem çağrısını / işlemi sağlar:
1. **Dosya oluşturma (`Creating a file`):** Önce dosya sisteminde dosya için yer ayrılır, ardından dizin yapısına (`directory`) yeni dosya için bir kayıt (`entry`) eklenir.
2. **Dosyaya yazma (`Writing a file`):** Dosya adı ve yazılacak veri belirtilerek sistem çağrısı yapılır. İşletim sistemi dosya içindeki mevcut yazma konumunu gösteren bir **yazma işaretçisi (`write pointer`)** tutar ve her yazma işleminden sonra bu işaretçiyi günceller.
3. **Dosyadan okuma (`Reading a file`):** Okunacak dosya adı ve verinin bellekte konulacağı adres belirtilir. İşletim sistemi bir **okuma işaretçisi (`read pointer`)** tutar (çoğu sistemde okuma ve yazma için tek bir **mevcut dosya konumu işaretçisi / `current-file-position pointer`** kullanılır).
4. **Dosya içinde yeniden konumlanma (`Repositioning within a file` / `seek`):** Dizin taranır ve mevcut dosya konumu işaretçisi verilen yeni değere taşınır. Fiziksel bir G/Ç (okuma/yazma) işlemi gerektirmez; C programlamadaki `fseek()` fonksiyonunun karşılığıdır.
5. **Dosya silme (`Deleting a file`):** Dizinde ilgili dosya aranır, bulunduğunda dosyanın kapladığı tüm disk blokları başka dosyalarda kullanılabilmesi için serbest bırakılır ve dizin kaydı silinir.
6. **Dosyayı kırpma / içini boşaltma (`Truncating a file`):** Dosyanın öznitelikleri (adı, izinleri, sahibi vb.) korunurken yalnızca içindeki veriler silinir ve dosya uzunluğu sıfırlanır (`0` yapılır).

Bu işlemlerin her seferinde dizin yapısını baştan sona aramasını önlemek için çoğu işletim sistemi dosyayı kullanmadan önce **`open(Fi)`** sistem çağrısıyla açmayı (dizin kaydını ve özniteliklerini diskten ana belleğe taşımayı) ve iş bittiğinde **`close(Fi)`** ile kapatmayı (bellekteki güncel bilgileri diske geri yazmayı) zorunlu tutar.

### 2.2 Açık Dosyaların Yönetimi (Open Files) ve Dosya Kilitleme (File Locking)

Açık dosyaları (`open files`) yönetmek için işletim sistemi çekirdeği şu beş temel veriyi tutar:
- **Açık Dosya Tablosu (`Open-file table`):** O anda sistemde açık olan tüm dosyaların kaydını tutan tablodur.
- **Dosya İşaretçisi (`File pointer`):** Dosyayı açan her proses için en son okuma veya yazma yapılan konumu (C dilindeki *file position indicator*) ayrı ayrı takip eden işaretçidir.
- **Açık Dosya Sayacı (`File-open count`):** Bir dosyanın aynı anda kaç farklı proses tarafından açıldığını sayan sayaçtır. Bir proses `close()` çağırdığında sayaç bir azaltılır; yalnızca sayaç **`0`** olduğunda dosyanın açık dosya tablosundaki kaydı kaldırılır.
- **Dosyanın Disk Konumu (`Disk location of the file`):** Her okuma/yazmada diske tekrar sormamak için dosyanın disk üzerindeki konum bilgilerinin bellekte tutulan önbelleğidir (`cache`).
- **Erişim Hakları (`Access rights`):** Her prosesin dosyayı hangi modda (salt okuma, yazma, okuma-yazma vb.) açtığını belirten bilgidir.

Ayrıca birden fazla prosesin aynı dosyaya eşzamanlı eriştiği durumlarda işletim sistemleri **dosya kilitleme (`File locking`)** mekanizması sunar. Senkronizasyon konusunda görülen **Okuyucu-Yazıcı Kilitlerine (`Reader-Writer Locks`)** birebir benzeyen bu yapıda:
- **Paylaşımlı Kilit (`Shared lock`):** Okuyucu kilidi (*reader lock*) gibidir; birden fazla proses aynı anda paylaşımlı kilit alarak dosyayı okuyabilir.
- **Dışlayıcı Kilit (`Exclusive lock`):** Yazıcı kilidi (*writer lock*) gibidir; bir proses dosyaya yazmak için dışlayıcı kilit aldığında başka hiçbir proses o dosyaya erişemez.
- Kilitler işletim sisteminin davranışına göre **zorunlu (`mandatory` — işletim sistemi kilidi ihlal eden erişimi doğrudan engeller)** veya **tavsiye niteliğinde (`advisory` — kilit durumunu kontrol edip uymak uygulama geliştiricinin sorumluluğundadır)** olabilir.

### 2.3 Dosya Türleri (File Types) ve İç Dosya Yapıları (File Structure)

Slaytta (ekrandan, 00:19:05) özetlenen başlıca dosya türleri, uzantıları ve işlevleri şunlardır:

| Dosya Türü (`file type`) | Yaygın Uzantılar (`usual extension`) | İşlevi (`function`) |
|---|---|---|
| **executable** | `exe, com, bin` veya uzantısız (`none`) | Çalışmaya hazır makine dili programı |
| **object** | `obj, o` | Derlenmiş makine dili kodu, henüz bağlanmamış (*not linked*) |
| **source code** | `c, cc, java, pas, asm, a` | Çeşitli dillerde yazılmış kaynak kod |
| **batch** | `bat, sh` | Komut yorumlayıcısına (*shell*) verilen toplu komutlar (Windows'ta `.bat`, Linux'ta `.sh`) |
| **text** | `txt, doc` | Metin verileri, dokümanlar |
| **word processor** | `wp, tex, rtf, doc` | Çeşitli kelime işlemci formatları |
| **library** | `lib, a, so, dll` | Programcılar için rutin/fonksiyon kütüphaneleri |
| **print or view** | `ps, pdf, jpg` | Yazdırma veya görüntüleme formatındaki ASCII veya ikilik dosya |
| **archive** | `arc, zip, tar` | Arşivleme/depolama için tek dosyada gruplanmış (bazen sıkıştırılmış) dosyalar |
| **multimedia** | `mpeg, mov, rm, mp3, avi` | Ses veya görüntü/video bilgisi içeren ikilik dosya |

Dosyanın kendi iç yapısına (`File Structure`) bakıldığında ise bir dosya:
- **Yapısız (`None`):** Kelimelerin veya baytların düz bir dizisi (*sequence of words, bytes*) olabilir.
- **Basit kayıt yapısı (`Simple record structure`):** Verilerin satır satır (`lines`), **sabit uzunluklu (`fixed length`)** kayıtlar halinde veya başlık/kontrol bilgileriyle ayrılan **değişken uzunluklu (`variable length`)** kayıtlar halinde tutulmasıdır.
- **Karmaşık yapılar (`Complex structures`):** Biçimlendirilmiş belgeler (`formatted document`) veya çalışma zamanında yeniden konumlandırılabilir yükleme dosyaları (`relocatable load file`) olabilir. Tüm bu karmaşık yapılar, işletim sistemi düzeyinde uygun **kontrol karakterleri (`control characters`)** (protein sentezindeki başlatma ve bitirme kodonları gibi başlık, içerik ve altbilgi sınırlarını belirten özel işaretçiler) eklenerek bayt dizileri üzerinde simüle edilebilir.

---

## 3. Dosya Erişim Yöntemleri: Sıralı, Doğrudan (Bağıl) ve İndeksli Erişim

Dosyada saklanan bilgilere erişmek için üç temel yöntem kullanılır:

### 3.1 Sıralı Erişim (Sequential Access)

En basit ve en yaygın erişim yöntemidir (manyetik teyp modeline dayanır). Dosyadaki bilgiler kayıt kayıt (veya bayt bayt) sırayla işlenir:

```text
          mevcut konum (current position)
                       |
                       v
+----------------------+-----------------------+
| <----- rewind ------ | ---> okuma / yazma    |
+----------------------+-----------------------+
baslangic (beginning)                    son (end)
```

- **`read next`:** Dosyanın mevcut konumundaki bir sonraki kaydı okur ve dosya işaretçisini otomatik olarak ileri taşır.
- **`write next`:** Dosyanın sonuna/mevcut konumuna yazar ve işaretçiyi yeni sona ilerletir.
- **`reset` / `rewind`:** Geriye doğru doğrudan okuma yapılamadığı için, önceki bir kayda dönülmek istendiğinde dosya işaretçisi en başa (`beginning`) sarılır ve istenen konuma kadar tekrar ileri okunur.
- **Dezavantajı:** Sıralı bir dosyada aradaki bir kaydı güncellemek istediğinizde, eğer yeni yazacağınız verinin boyutu eski kaydın boyutunu aşarsa hemen arkasından gelen bir sonraki kaydın alanına taşar (üzerine yazar).

### 3.2 Doğrudan Erişim (Direct Access / Relative Access)

Disk modeline dayanan bu yöntemde dosya, **sabit uzunluklu mantıksal kayıtların (`fixed-length logical records`)** numaralandırılmış bir dizisi olarak görülür. Programlar herhangi bir sıra gözetmeksizin istedikleri bloğu doğrudan okuyup yazabilirler (örneğin önce blok `14`'ü okuyup, sonra blok `53`'ü okuyup, ardından blok `7`'ye yazabilirler).
- İşlemler blok numarası $n$'yi parametre olarak alır: **`read n`**, **`write n`**, **`position to n`**. Burada $n$, dosyanın başlangıcına göre verilen **bağıl blok numarasıdır (`relative block number`: $0, 1, 2, \dots$)**.

### 3.3 Diğer Erişim Yöntemleri: İndeksli ve Bağıl Dosyalar (Index and Relative Files)

Doğrudan erişim mekanizması üzerine **indeksli erişim (`indexed access`)** katmanı inşa edilebilir (ekrandan, 00:25:15). Büyük bir dosyada kayıtları baştan sona aramak yerine bellekte veya diskte **indeks dosyası (`index file`)** adı verilen bir tablo tutulur. Bu indeks tablosu, ana veri dosyasındaki (**bağıl dosya / `relative file`**) bloklara işaret eden **mantıksal kayıt numaralarını (`logical record number`)** içerir:

```text
   Index File (Indeks Dosyasi)            Relative File (Bagil Veri Dosyasi)
+-----------+--------------------+      +-------------------------------------+
| last name | logical record no. |      |                  ...                |
+-----------+--------------------+      +--------------+-----------------+----+
|  Adams    |                    |   +->| smith, john  | social-security |age |
+-----------+--------------------+   |  +--------------+-----------------+----+
|  Arthur   |                    |   |  |                  ...                |
+-----------+--------------------+   |  |                  ...                |
|  Asher    |                    |   |  +-------------------------------------+
+-----------+--------------------+   |
|    ...    |        ...         |   |
+-----------+--------------------+   |
|  Smith    |        o-----------+---+
+-----------+--------------------+
```

Slayttaki örnekte (`00:25:15`) kişiler soyadlarına (`last name`) göre indekslenmiştir. `"Smith"` soyadlı kişinin bilgilerini bulmak için önce küçük ve sıralı olan **indeks dosyasında** arama yapılır (bir çırpı/hash tablosu veya ikili arama gibi), buradan `"Smith"` kaydının **mantıksal kayıt numarası** alınır ve doğrudan **bağıl dosyanın (`relative file`)** ilgili satırına gidilerek `smith, john`, sosyal güvenlik numarası (`social-security`) ve yaş (`age`) bilgileri tek adımda okunur.

---

## 4. Dizin Yapısı (Directory Structure), Disk Bölümleri ve Dizin Mimarileri

### 4.1 Dizin (Directory) Kavramı ve Disk Bölümleme (Partitions / Volumes)

**Dizin (`Directory` / Klasör / `Folder`)**, birden fazla dosyayı mantıksal olarak gruplayan ve dosya isimleriyle o dosyaların disk üzerindeki fiziksel konumlarını eşleştiren bir sembol tablosudur.

> **Hocanın vurgusu:** Bir klasörün (örneğin `D:\A` klasörünün) altında `A1, A2, ..., A10` dosyalarının görünmesi, bu dosyaların disk üzerinde fiziksel olarak yan yana durduğu anlamına gelmez! Klasörün içinde tutulan şey dosyanın kendisi değil, dosyanın diskteki gerçek fiziksel adresini gösteren bir **işaretçidir (`pointer`)**.
> - Bu yüzden **aynı disk bölümü içinde** (örneğin `D:` diskindeki bir klasörden `D:` diskindeki başka bir klasöre) dosya taşıdığınızda işletim sistemi veriyi fiziksel olarak kopyalamaz; yalnızca dizin içindeki adres bağlantısını (işaretçiyi) günceller.
> - Ancak **farklı disk bölümleri arasında** (örneğin `C:` diskinden `D:` diskine) kopyalama/taşıma yaptığınızda veri kaynaktan okunup hedefe fiziksel olarak yeniden yazılır.

**Disklerin Bölümlere (`Partitions`) Ayrılması:**
Bir sabit disk (`HDD`) veya `SSD` kendi içinde `C:`, `D:` gibi mantıksal **bölümlere (`partitions` / `volumes` / `minidisks`)** ayrılabilir veya bazen birden fazla fiziksel disk birleştirilerek tek bir bölüm (`Partition C`) gibi gösterilebilir (`00:29:10`).
- **Neden bölümleme yapılır?** Tek bir fiziksel diski tek bir bölüm halinde kullanırsanız, işletim sistemi çekirdeği (`kernel`) zarar gördüğünde (sistem çöktüğünde) kullanıcı verilerini kurtarmak çok zor veya imkansız hale gelebilir. Oysa işletim sistemi çekirdeği bir bölüme (`C:`), kullanıcının kişisel dosyaları ise ayrı bir bölüme (`D:`) yerleştirildiğinde, işletim sistemi çökse bile diğer bölümdeki veriler güvenle korunur.

### 4.2 Dizin Üzerinde Yapılan İşlemler ve Dizin Kullanım Amaçları

Hem grafik arayüzde hem de komut satırında (`cmd` altında `dir`, PowerShell/Linux altında `ls` vb.) dizinler üzerinde şu altı temel işlem gerçekleştirilir:
1. **Dosya arama (`Search for a file`):** Dosya adına veya joker karakter kalıbına (örneğin ilk ve üçüncü karakteri bilinen dosyalar) göre dizin ağacında **Genişlik Öncelikli Arama (`BFS — Breadth-First Search`)** veya **Derinlik Öncelikli Arama (`DFS — Depth-First Search`)** algoritmalarıyla arama yapılması.
2. **Dosya oluşturma (`Create a file`):** Dizine yeni dosya kaydı eklenmesi.
3. **Dosya silme (`Delete a file`):** Dosya kaydının dizinden çıkarılması.
4. **Dizin listeleme (`List a directory`):** Dizindeki dosyaların ve özniteliklerinin listelenmesi.
5. **Dosya yeniden adlandırma (`Rename a file`):** Dosyanın dizin içindeki adının (veya konumunun) değiştirilmesi.
6. **Dosya sisteminde gezinme (`Traverse the file system`):** Yedekleme veya tarama amacıyla dizin ağacının tüm düğümlerinin dolaşılması.

Dizin yapısı şu üç temel hedefi sağlar:
- **Verimlilik (`Efficiency`):** İstenen bir dosyanın hızlıca bulunması.
- **İsimlendirme (`Naming`):** Kullanıcılar için anlamlı isimlendirme; iki farklı kullanıcının aynı dosya adını kullanabilmesi veya aynı dosyaya farklı isimlerle erişilebilmesi.
- **Gruplama (`Grouping`):** Dosyaların özelliklerine göre (örneğin tüm Java programları, tüm oyunlar, ders notları) mantıksal olarak bir araya toplanması.

### 4.3 Dört Temel Dizin Mimarisi

#### 1. Tek Seviyeli Dizin (`Single-Level Directory`)
Tüm kullanıcılar için yalnızca **tek bir dizin** vardır ve sistemdeki bütün dosyalar bu tek dizinin içinde yer alır:

```text
Dizin: [ cat | bo | a | test | data | mail | cont | hex | records ]
          |    |    |    |      |      |      |      |       |
         (o)  (o)  (o)  (o)    (o)    (o)    (o)    (o)     (o)  <-- Dosyalar
```

> **Ders sonrası not:** Hoca slayt 11.24'teki tek seviyeli dizin şemasını ilk açıklarken *"Örneğin cat isminde bir directory var. Onun altında bir tane dosya olacak şekilde, bo adında. Yani her directory, single directory bir tane dosyayla ilişkilendirilir şekilde"* (00:31:57) demiş, hemen ardından *"Direktörüsü ve o direktör altında dosyaları var, kimin dosyası kimdedir..."* (00:32:39) diyerek düzeltmiştir. Büyük olasılıkla Silberschatz kitabındaki (Bölüm 11.3.1) şemada üstteki `cat`, `bo`, `a`, `test`, `data`, `mail`, `cont`, `hex`, `records` kutuları ayrı birer dizin değil, **tüm sistemdeki tek dizinin dosya kayıtlarıdır (`directory entries`)** ve alttaki daireler de bu kayıtların işaret ettiği dosyalardır.

- **Sorunları:**
  - **İsimlendirme problemi (`Naming problem`):** Tüm dosyalar aynı dizinde olduğu için her dosyanın adı benzersiz olmak zorundadır; iki farklı kullanıcı aynı isimli (`test.c` gibi) dosya oluşturamaz.
  - **Gruplama problemi (`Grouping problem`):** Dosyaları konularına veya sahiplerine göre alt gruplara ayırmak mümkün değildir.

#### 2. İki Seviyeli Dizin (`Two-Level Directory`)
Kullanıcılar arasındaki isim çakışmasını çözmek için en üstte bir **Ana Dosya Dizini (`Master File Directory — MFD`)** oluşturulur ve her kullanıcıya (`user 1`, `user 2`, `user 3`, `user 4`) kendine ait ayrı bir **Kullanıcı Dosya Dizini (`User File Directory — UFD`)** verilir:

```text
Ana Dizin (MFD):   [ user 1 | user 2 | user 3 | user 4 ]
                       |        |        |        |
                       v        v        v        v
user 1 UFD: [cat|bo|a]    user 2 UFD: [a|test|data]   ...
```

- **Özellikleri:** Her dosyanın bir **yol adı (`path name` — örn. `/user2/test`)** vardır. Farklı kullanıcılar artık aynı dosya adına (örneğin hem `user 1` hem `user 2` kendi dizininde `a` ve `test` adlı dosyalara) sahip olabilir ve arama işlemi yalnız ilgili kullanıcının dizininde yapıldığı için daha verimlidir. Ancak bir kullanıcının kendi dosyalarını kendi içinde alt klasörlere ayırma (**gruplama / `grouping`**) yeteneği hâlâ yoktur.

#### 3. Ağaç Yapılı Dizinler (`Tree-Structured Directories`, ekrandan, 00:35:00)
İki seviyeli dizin yapısının doğal bir genellemesidir; en üstte bir **kök (`root`)** dizin bulunur ve her dizin kendi içinde hem dosyaları (yapraklar) hem de yeni **alt dizinleri (`subdirectories`)** barındırabilir:

```text
                         root: [ spell | bin | programs ]
                                  /       |         \
              +------------------+        |          +------------------+
              v                           v                             v
    [ stat | mail | dist ]    [ find | count | hex | reorder ]   [ p | e | mail ]
       |      |       |          |       |      |       |         /    |     \
      (o)     |      (o)        (o)     (o)    (o)     (o)       /     |     (o)
              v                                                 v      v
    [ prog | copy | prt | exp ]                  [ reorder|list|find ] [ hex|count ]
       |      |      |     |                          |     |    |        |    |
       v      v      v    (o)                        (o)   (o)  (o)      (o)  (o)
  [list|obj|spell] [all] [last|first]
```

- **Geçerli Dizin (`Current Directory` / Çalışma Dizini):** Kullanıcının o an içinde bulunduğu aktif dizindir (`cd` komutuyla değiştirilir).
- **Mutlak ve Göreceli Yol Adları (`Absolute and Relative Path Names`):**
  - **Mutlak Yol (`Absolute path name`):** Kökten (`root`) başlayarak hedef dosyaya kadar tüm dizin adlarını içeren tam yoldur (örneğin `/spell/mail/prt/first` veya `/spell/mail/prt/last`).
  - **Göreceli Yol (`Relative path name`):** Kullanıcının o an bulunduğu **geçerli dizine (`current directory`)** göre tanımlanan kısa yoldur. Örneğin geçerli dizin `/spell/mail` ise aynı dosyaya yalnızca `prt/first` yazarak erişilir; `mkdir count` komutu çalıştırıldığında `/spell/mail/count` alt dizini oluşturulur. Eğer `/spell/mail` içindeyken `bin/hex` altında bir klasör oluşturulmak istenirse mutlak yol (`/bin/hex/...`) yazılmalıdır.
- **Dizin Silme (`Deleting a directory`):** `rm -r mail` gibi bir komutla dolu bir dizin silindiğinde, o dizinin altındaki tüm alt dizinler ve dosyalar (alt ağaç) özyinelemeli olarak yok edilir.

#### 4. Çevrimsiz Çizge (`Acyclic-Graph`) ve Genel Çizge (`General Graph`) Dizinleri
Saf ağaç yapısında bir dosya veya alt dizin iki farklı dizin tarafından **paylaşılamaz**. Oysa ortak bir projede çalışan iki kullanıcının aynı alt dizine kendi dizin ağaçları altından erişmesi gerekebilir. **Çevrimsiz çizge dizinleri (`Acyclic-Graph Directories`)**, döngü (*cycle*) oluşturmamak şartıyla dosyaların ve alt dizinlerin birden fazla dizin tarafından paylaşılmasına (**`shared subdirectories and files`**) izin verir (örneğin `/dict/count` ile `/spell/count` kayıtlarının aynı fiziksel `count` alt dizinini göstermesi).
- **Silme Problemi:** Paylaşılan bir dosya bir kullanıcı tarafından silindiğinde diğer kullanıcının işaretçisi geçersiz bir adresi gösterirse **sallanan işaretçi (`dangling pointer`)** oluşur; bunu önlemek için dosyaya kaç bağlantının işaret ettiğini tutan bir referans sayacı (`reference count`) kullanılır ve sayaç `0` olmadan dosya diskten silinmez.
- **Genel Çizge Dizinleri (`General Graph Directories`):** Çizgede döngülere (`cycles`) izin verilirse dizin tarama (`traverse`) işlemleri sonsuz döngüye girebilir ve referans sayacı hiçbir zaman `0` olmayabilir. Döngüleri yönetmek veya engellemek için:
  1. Dizinlere değil, **yalnızca dosyalara bağ (`link`) verilmesine** izin verilebilir.
  2. Boşta kalan döngüsel yapıları temizlemek için **çöp toplama (`garbage collection`)** çalıştırılabilir.
  3. Her yeni bağ eklendiğinde bir **çevrim sezimi (`cycle detection`)** algoritması çalıştırılarak döngü oluşup oluşmadığı denetlenebilir.

Son olarak, bir dosya sisteminin dizin ağacındaki bir noktaya (**`mount point`**) bağlanarak kullanıma açılması işlemine **bağlama (`file system mounting`)** adı verilir.

---

## 5. Dosya Paylaşımı (File Sharing) ve Koruma Mekanizmaları (`chmod` / Erişim Listeleri)

### 5.1 Çok Kullanıcılı Sistemlerde Dosya Paylaşımı

Çok kullanıcılı bir bilgisayarda veya ağ ortamında dosyaların paylaşılması; koruma, güvenlik ve kaynak paylaşımı açısından işletim sisteminin temel görevlerinden biridir:
- **Kullanıcı Kimlikleri (`User IDs — UID`):** Her kullanıcıyı tekil olarak tanımlar; hangi kullanıcının hangi dosyaya erişebileceği UID bazında denetlenebilir.
- **Grup Kimlikleri (`Group IDs — GID`):** Kullanıcı sayısı çok fazla olduğunda (hoca örnek olarak YTÜ OBS sistemindeki 40.000 öğrenciyi verdi) her kullanıcıya tek tek yetki tanımlamak imkansızlaşır. Bunun yerine kullanıcılar rollere/kategorilere (**gruplara**) ayrılır ve erişim hakları grup kimliği (`Group ID`) üzerinden tek bir tıklamayla açılıp kapatılır.
- **Ağ Üzerinde Paylaşım:** Dosyalar yalnız yerel bilgisayarda değil, geniş alan ağları (`WAN` / İnternet) üzerinde **FTP (`File Transfer Protocol`)**, dağıtık dosya sistemleri (`DFS` / istemci-sunucu mimarileri) veya eşler arası (**`Peer-to-Peer — P2P`**) ağlar üzerinden de paylaşılabilir.

### 5.2 Dosya Koruması (Protection) ve UNIX/Linux Erişim Listeleri (`chmod`)

Bir dosyanın sahibi (`owner` / `creator`), dosya üzerinde **kimlerin (`who`)** **neler (`what`)** yapabileceğini belirleme yetkisine sahip olmalıdır. Denetlenebilen başlıca işlem türleri şunlardır:
- **Okuma (`Read`)**, **Yazma (`Write`)**, **Çalıştırma (`Execute`)**, **Sona Ekleme (`Append`)**, **Silme (`Delete`)** ve **Listeleme (`List`)**.

UNIX ve Linux işletim sistemlerinde erişim denetim listelerini (`ACL`) hem esnek hem de az yer kaplayacak biçimde gerçeklemek için **3 erişim modu** ve **3 kullanıcı sınıfı** birleştirilir (ekrandan, 00:45:55):
- **Erişim Modları (`Mode of access`):** **`R`** (`Read` — Okuma, $2^2 = 4$), **`W`** (`Write` — Yazma, $2^1 = 2$), **`X`** (`Execute` — Çalıştırma, $2^0 = 1$).
- **Kullanıcı Sınıfları (`Three classes of users`):**

```text
                                      Sekizlik / Sayisal       Ikilik (Binary)
                                                                 R   W   X
a) owner access  (Dosya Sahibi)   :         7             =>     1   1   1
b) group access  (Calisma Grubu)  :         6             =>     1   1   0
c) public access (Diger Herkes)   :         1             =>     0   0   1
```

Slayttaki örnekte (`00:45:55`):
1. Dosya sahibine (`owner`) okuma (`1`), yazma (`1`) ve çalıştırma (`1`) yetkilerinin tamamı verilmiştir: `111` $= \mathbf{7}$.
2. Çalışma grubuna (`group`) okuma (`1`) ve yazma (`1`) yetkisi verilmiş, çalıştırma (`0`) kapatılmıştır: `110` $= \mathbf{6}$.
3. Genel kullanıcılara (`public`) okuma (`0`) ve yazma (`0`) kapatılmış, yalnız çalıştırma (`1`) yetkisi verilmiştir: `001` $= \mathbf{1}$.

`game` adlı bir dosyaya bu izinleri tanımlamak ve dosyayı `G` adlı gruba atamak için kabukta şu iki komut çalıştırılır:

```bash
chmod 761 game
chgrp G game
```

> **Ders sonrası not:** Hoca derste `111 -> 7`, `110 -> 6`, `001 -> 1` dönüşümünü anlatırken *"Buradaki binary datayı desimale çevirdiğinizde, ondalık sayıya çevirdiğinizde"* (00:46:03) ifadesini kullanmıştır. 3 bitlik her bir grup $0..7$ aralığında değer aldığı için tek bir basamak olarak ondalık ve sekizlik tabanda aynı görünse de, `chmod 761` komutundaki üç basamaklı gösterim büyük olasılıkla teknik olarak **sekizlik taban (`octal representation`)** gösterimidir.

Windows sistemlerinde ise dosya koruması grafik arayüzde dosyaya sağ tıklanıp *Properties $\to$ Security* sekmesinden kullanıcı veya gruplar (örneğin `Guest` kullanıcısı) seçilerek `Full control`, `Modify`, `Read & execute`, `Read`, `Write` kutucuklarına `Allow` (İzin ver) veya `Deny` (Reddet) işaretlenerek yönetilir.

---

## 6. Dosya Sistemi Gerçeklemesi: Katmanlı Mimari, FCB, Açık Dosya Tabloları ve VFS

### 6.1 Katmanlı Dosya Sistemi Mimarisi (Layered File System)

Dosya sisteminin ikincil bellek (sabit disk veya SSD) üzerinde gerçeklenmesi, tıpkı bilgisayar ağlarındaki OSI referans modelinde olduğu gibi **katmanlı (`layered`)** ve modüler bir yapıyla gerçekleştirilir (ekrandan, 00:50:00). Her katman bir üst katmandan gelen isteği alır, kendi görevini yerine getirir ve bir alt katmandan hizmet talep eder:

```text
+-----------------------------------+
|       application programs        |  <-- Kullanici Katmani (User)
+-----------------------------------+
                  |
                  v
+-----------------------------------+  ---
|        logical file system        |    |
+-----------------------------------+    |
                  |                      |
                  v                      |
+-----------------------------------+    |-- Isletim Sistemi Servisleri (OS)
|     file-organization module      |    |
+-----------------------------------+    |
                  |                      |
                  v                      |
+-----------------------------------+    |
|         basic file system         |  ---
+-----------------------------------+
                  |
                  v
+-----------------------------------+  ---
|            I/O control            |    |
+-----------------------------------+    |-- Donanim ve Surucu Katmani (Hardware)
                  |                      |
                  v                      |
+-----------------------------------+    |
|              devices              |  ---
+-----------------------------------+
```

> **Ders sonrası not:** Hoca katmanlı mimari mantığını açıklarken ağlardaki 7 katmanlı OSI modelini örnek vermiş ve katmanları yukarıdan aşağıya yazarken önce `Application`, altına `Session`, onun altına `Presentation` ve `Transportation` yazmıştır (00:51:25–00:51:45). Büyük olasılıkla standart ISO/OSI 7 katmanlı referans modelinde yukarıdan aşağıya sıralama **7-Application (Uygulama), 6-Presentation (Sunum), 5-Session (Oturum), 4-Transport (Taşıma), 3-Network (Ağ), 2-Data Link (Veri Bağı), 1-Physical (Fiziksel)** şeklindedir; yani `Presentation` katmanı `Session` katmanının üstündedir.

Dosya sisteminin katmanlarının görevleri (aşağıdan yukarıya ve yukarıdan aşağıya) şunlardır:
1. **`Devices` (Donanım Aygıtları):** En altta bulunan fiziksel sabit disk (`HDD` — genellikle $512\text{ bayt}$'lık sektörlerden oluşur) veya `SSD` aygıtıdır.
2. **`I/O Control` (G/Ç Kontrol Katmanı):** Aygıt sürücüleri (`device drivers`) ve kesme işleyicilerinden (`interrupt handlers`) oluşur. Üst katmandan gelen yüksek seviyeli blok okuma isteklerini donanım denetleyicisinin anlayacağı düşük seviyeli sinyallere ve yazmaç komutlarına dönüştürür (örneğin *"Drive 1, silindir 72, iz 2, sektör 10'u oku ve ana bellekte 1060 adresine aktar"*).
3. **`Basic File System` (Temel Dosya Sistemi):** Uygun aygıt sürücüsüne sayısal blok adresleriyle genel komutlar gönderir (örneğin *"Blok 123'ü getir"*). Ayrıca disk bloklarını tutan bellek tamponlarını (`buffers`) ve önbellekleri (`caches`) yönetir.
4. **`File-Organization Module` (Dosya Organizasyon Modülü):** Dosyanın mantıksal blok numaralarını ($0, 1, \dots, N$) fiziksel disk blok adreslerine çevirir (**mantıksal $\to$ fiziksel adres dönüşümü**) ve diskteki boş alanları (`free-space management`) yönetir.
5. **`Logical File System` (Mantıksal Dosya Sistemi):** Dosyanın asıl verisi dışındaki tüm **üstverileri (`metadata`)** ve dizin yapısını yönetir. Uygulama programından sembolik dosya adını (örneğin `deneme.doc`) alır, dizini tarar ve bu dosyanın **Dosya Kontrol Bloğunu (`File Control Block — FCB` / UNIX'te `inode`)** bularak alt katmana gerekli bilgileri iletir; ayrıca koruma (`protection`) denetimini yapar.
6. **`Application Programs` (Uygulama Programları):** Kullanıcının C veya başka bir dilde yazdığı, `fopen()`, `fread()` gibi çağrılar yapan programlardır.

### 6.2 Disk Üzerindeki ve Bellekteki Veri Yapıları (FCB ve Açık Dosya Tabloları)

Bir dosya sistemini gerçeklemek için **disk üzerinde (`on-disk`)** şu yapılar tutulur:
- **Önyükleme Kontrol Bloğu (`Boot Control Block`):** Eğer o disk bölümü (`volume`) bir işletim sistemi içeriyorsa, sistemi başlatmak için gereken önyükleme bilgilerini tutar (genellikle bölümün ilk bloğudur; UNIX UFS'te *boot block*, NTFS'te *Partition Boot Sector*).
- **Bölüm Kontrol Bloğu (`Volume Control Block`):** Bölümdeki toplam blok sayısı, boş blok sayısı, blok boyutu ve boş blok işaretçileri gibi bölüm detaylarını tutar (UFS'te *superblock*, NTFS'te *Master File Table*).
- **Dizin Yapısı (`Directory Structure`):** Dosya isimlerini ve ilgili FCB/`inode` numaralarını organize eder.
- **Dosya Kontrol Bloğu (`File Control Block — FCB`, ekrandan, 00:54:25):** Tıpkı proses yönetimindeki PCB (*Process Control Block*) gibi, her dosya için bir tane bulunan ve dosyanın tüm yönetim detaylarını (üstverilerini) tutan veri yapısıdır:

```text
+----------------------------------------------------+
| file permissions (dosya erisim izinleri)           |
+----------------------------------------------------+
| file dates (create, access, write tarihleri)       |
+----------------------------------------------------+
| file owner, group, ACL (sahip, grup, erisim list.) |
+----------------------------------------------------+
| file size (dosya boyutu)                           |
+----------------------------------------------------+
| file data blocks or pointers to file data blocks   |
| (veri bloklari veya veri bloklarinin isaretcileri) |
+----------------------------------------------------+
```

> **Ders sonrası not:** Hoca slayt 12.11'deki *"NFTS stores into in master file table using relational DB structures"* maddesini açıklarken slayttaki yazım hatasından dolayı *"Burada NFTC demiş, NTFS değil arkadaşlar bu. Bir işte relational database yapısıyla ne yapılıyor? Bir dosya tablosu oluşturmuş"* (00:54:34) demiştir. Büyük olasılıkla Silberschatz kitabının (9. baskı, Bölüm 12.2.1) orijinal metninde bu ifade Windows'un **NTFS (`New Technology File System`)** dosya sistemini anlatmaktadır ve slaytta `NTFS` kısaltması dizgi hatasıyla `NFTS` olarak yazılmıştır; NTFS dosya sisteminde tüm FCB bilgileri **Master File Table (MFT)** içinde ilişkisel veritabanı tablolarına benzer satırlar halinde saklanır.

**Ana Bellekteki (`In-Memory`) Dosya Sistemi Yapıları (ekrandan, 00:56:15):**
Bir dosyanın açılması (`open`) ve okunması (`read`) sırasında kullanıcı uzayı (`user space`), çekirdek belleği (`kernel memory`) ve ikincil depolama (`secondary storage`) arasındaki etkileşim iki adımda gerçekleşir:

```text
(a) Dosya Acma: open(file name)
   User Space                 Kernel Memory                  Secondary Storage
+---------------+       +-----------------------+       +-------------------------+
|               |       |  [               ]    |       |  [x] [ ]  directory     |
| open(file name)------>|  [xxxxxxxxxxxxxxx]<---|-------|  [ ] [ ]  structure     |
|               |       |  [               ]    |       |                         |
+---------------+       |  directory structure  |       |  [x] <-- file-control   |
                        +-----------+-----------+       |          block (FCB)    |
                                    |                   +-------------------------+
                                    +----------------------------^

(b) Dosya Okuma: read(index)
   User Space                 Kernel Memory                  Secondary Storage
+---------------+       +-------------+  +-------------+    +---------------------+
|               | index |  [       ]  |  |  [       ]  |    | [ ] [ ][ ] data     |
|  read(index) -|------>|  [xxxxxxx]--|->|  [xxxxxxx]--|--->| [ ]    [ ] blocks   |
|               |       |  [       ]  |  |  [       ]  |    |                     |
+---------------+       +-------------+  +-------------+    | [x] file-control    |
                          per-process      system-wide      |     block (FCB)     |
                        open-file table  open-file table    +---------------------+
```

1. **Dosya Açma (`open(file name)`, Şekil a):** Kullanıcı prosesi `open()` çağırdığında çekirdek bellekteki dizin yapısını kontrol eder (gerekirse diskten okur), diskteki **FCB (`file-control block`)** bloğunu bularak çekirdek belleğindeki **sistem çapında açık dosya tablosuna (`system-wide open-file table`)** kopyalar ve prosesin kendi tablosunda buna işaret eden bir girdi oluşturup indisini (`index` / *file descriptor*) kullanıcıya döndürür.
2. **Dosya Okuma (`read(index)`, Şekil b):** Dosya açıldıktan sonra artık dosya adıyla arama yapılmaz! Kullanıcı prosesi `read(index)` çağırdığında, **`per-process open-file table`** içindeki `index` doğrudan **`system-wide open-file table`** içindeki FCB kaydına gider ve oradaki blok işaretçileri üzerinden diskteki **`data blocks`** okunur.

### 6.3 Sanal Dosya Sistemi (Virtual File System — VFS) ve Dizin Gerçekleme

Bir işletim sisteminin aynı anda hem yerel farklı dosya sistemlerini (`ext4`, `NTFS`, `FAT32`, `UFS`) hem de ağ üzerindeki dosya sistemlerini (`NFS`) tek bir standart sistem çağrısı arayüzüyle (`open()`, `read()`, `write()`) destekleyebilmesi için çekirdekte **Sanal Dosya Sistemi (`Virtual File System — VFS`)** katmanı kullanılır. Nesne yönelimli (`object-oriented`) bir yaklaşımla tasarlanan VFS'te her dosya **`vnode`** adlı genel bir nesneyle temsil edilir; VFS arayüzü gelen çağrıyı alttaki gerçek dosya sisteminin (yerel disk veya ağ) ilgili fonksiyonuna yönlendirir.

**Dizinlerin Gerçeklenmesi (`Directory Implementation`):**
1. **Doğrusal Liste (`Linear List`):** Dosya adları ve veri bloğu işaretçileri düz bir bağlı liste olarak tutulur. Programlaması çok basittir ancak bir dosyayı aramak doğrusal zaman (**$\mathcal{O}(n)$**) alır. Bunu hızlandırmak için dizin kayıtları sıralı tutulabilir veya dengeli ağaç yapıları (**B-ağacı / `B-tree`**) kullanılabilir.
2. **Çırpı Tablosu (`Hash Table`):** Doğrusal listenin yanına bir hash veri yapısı eklenir. Dosya adı bir hash fonksiyonundan geçirilerek işaretçiye doğrudan ulaşılır ve arama süresi en iyi durumda **$\mathcal{O}(1)$** seviyesine iner; ancak çakışmaların (`collisions`) zincirleme veya taşma alanlarıyla çözülmesi gerekir.

---

## 7. Disk Blok Tahsis Yöntemleri: Bitişik (Contiguous), Bağlı (Linked / FAT) ve İndeksli (Indexed / UFS) Tahsis

Bir dosyanın veri bloklarının disk üzerinde nasıl yerleştirileceği ve takip edileceği konusunda üç temel tahsis yöntemi vardır:

### 7.1 Bitişik Tahsis (Contiguous Allocation)

Ana bellekteki bitişik tahsise benzer şekilde, her dosya disk üzerinde **birbirini izleyen ardışık bloklar (`contiguous blocks`)** kümesi olarak saklanır (ekrandan, 01:00:30):

```text
Mantıksal -> Fiziksel Adres Eşlemesi:       Dizin Tablosu (Directory):
                                            +-------+-------+--------+
            +--- Q (Bölüm / Quotient)       | file  | start | length |
           /                                +-------+-------+--------+
   LA / 512                                 | count |   0   |   2    | (Blok 0, 1)
           \                                | tr    |  14   |   3    | (Blok 14, 15, 16)
            +--- R (Kalan / Remainder)      | mail  |  19   |   6    | (Blok 19..24)
                                            | list  |  28   |   4    | (Blok 28..31)
Erişilecek Blok = Q + starting address      | f     |   6   |   2    | (Blok 6, 7)
Blok İçi Ofset  = R                         +-------+-------+--------+
```

- **Çalışma Mantığı:** Dizin kaydında her dosya için yalnızca **başlangıç bloğu (`start`)** ve **uzunluk (`length` — kaç blok kapladığı)** bilgisini tutmak yeterlidir. Örneğin `mail` dosyası `19.` bloktan başlar ve `6` blok (`19, 20, 21, 22, 23, 24`) sürer.
- **Mantıksal Adresin Fiziksel Adrese Dönüştürülmesi:** Bir disk bloğunun (sektörünün) boyutu **$512\text{ bayt}$** olsun. Dosya içindeki mantıksal bayt adresi **`LA`** (`Logical Address`), `512`'ye bölünür:
  - Bölüm **`Q`**: Dosyanın kaçıncı bloğunda olduğumuzu verir $\implies \text{Fiziksel Blok Numarası} = Q + \text{starting address}$.
  - Kalan **`R`**: O bloğun içindeki bayt kaymasını (`displacement into block`) verir.
- **Avantajları ve Dezavantajları:**
  - *Avantajı:* Okuma kafasının hareketi minimumdur ve hem sıralı hem de doğrudan erişim (`start + Q`) çok hızlıdır.
  - *Dezavantajı:* Yeni bir dosya için yeterli büyüklükte bitişik boş alan bulmak zordur (ilk uyum / en iyi uyum problemi), dosyanın sonradan ne kadar büyüyeceğini önceden tahmin etmek güçtür ve dosyalar silinip eklendikçe diskte **dış parçalanma (`external fragmentation`)** oluşur.
  - **Sıkıştırma (`Compaction` / Defragmentation):** Dış parçalanmayı gidermek için bloklar birleştirilebilir (`compaction`). Hoca, disk üzerindeki sıkıştırmanın ana bellekteki sıkıştırma kadar kritik bir sorun olmadığını; çünkü RAM'de sıkıştırma yaparken çalışan prosesleri dondurmak gerekirken, disk üzerinde arka planda blokların yerini değiştirmenin çalışan prosesleri aynı şekilde durdurmadığını vurguladı.

### 7.2 Bağlı Tahsis (Linked Allocation) ve Dosya Tahsis Tablosu (FAT)

Bitişik tahsisin dış parçalanma ve boyut büyütme sorunlarını çözmek için **Bağlı Tahsis (`Linked Allocation`)** yönteminde her dosya, disk bloklarının bir **bağlı listesi (`linked list`)** olarak tutulur; bloklar diskin herhangi bir yerinde dağınık olarak durabilir:
- Dizin kaydında dosyanın yalnızca **ilk bloğu (`start`)** ve **son bloğu (`end`)** tutulur.
- Her disk bloğunun son birkaç baytı, dosyanın **bir sonraki bloğunun adresini gösteren bir işaretçiye (`pointer`)** ayrılır; son bloğun işaretçisi ise listenin bittiğini belirten **`nil` (`-1`)** değerini tutar.
- Örneğin slayttaki `jeep` dosyası için dizinde `start = 9` ve `end = 25` kayıtlıdır. Blokların birbirine bağlanma sırası şöyledir (`01:02:04`):
  $$\text{start} \to \mathbf{9} \to \mathbf{16} \to \mathbf{1} \to \mathbf{2} \to \mathbf{25}\text{ (end, işaretçisi } -1\text{)}$$
- **Avantajı:** **Dış parçalanma (`external fragmentation`) yoktur**; herhangi bir boş blok herhangi bir dosyaya eklenebilir ve dosya boyutu önceden bildirilmek zorunda değildir.
- **Dezavantajları:**
  1. **Doğrudan erişim (`direct access`) verimsizdir:** Dosyanın $i$. bloğuna ulaşmak için baştan (`start`) başlayarak $i$ adet disk bloğunu tek tek okumak ve işaretçileri takip etmek gerekir.
  2. **Alan kaybı:** Her blokta işaretçi (`pointer`) için yer harcanır (bunu azaltmak için bloklar tek tek değil, **küme / `cluster`** adı verilen 4'lü-8'li blok grupları halinde tahsis edilir; bu da iç parçalanmayı biraz artırır).
  3. **Güvenilirlik (`Reliability`) problemi:** Diskteki bloklardan birinin içindeki işaretçi bozulursa veya kaybolursa bağlı liste zinciri kopar ve dosyanın geri kalanına ulaşılamaz.

#### Dosya Tahsis Tablosu (`File-Allocation Table — FAT`, ekrandan, 01:03:20)
Bağlı tahsisin doğrudan erişim yavaşlığını ve blok içi işaretçi sorununu çözmek için MS-DOS ve Windows sistemlerinde kullanılan **FAT (`FAT`, `FAT32`)** yapısında, tüm blok işaretçileri veri bloklarının içinden çıkarılarak diskin (bölümün) en başında yer alan **tek bir tabloda (`FAT`)** toplanır (ekrandan, 01:03:20):

```text
Dizin Kaydı (Directory Entry):
+------+-----+-----------+
| test | ... |    217    | ----+
+------+-----+-----------+     |
  name        start block      |      FAT (File-Allocation Table)
                               |           0 +---------+
Hocanın Çizdiği Dizi Örneği:   |             |   ...   |
                               +-------> 217 +---------+
  İndis:   0     1     2     3               |   618   | ---+
         +-----+-----+-----+-----+           +---------+    |
  Değer: |  1  | -1  |  0  |  2  |       339 |   EOF   |<---|---+
         +-----+-----+-----+-----+           +---------+    |   |
  Başlangıç (h = 3):                     618 |   339   |<---+   |
  3 -> 2 -> 0 -> 1 -> -1 (Bitiş)             +---------+--------+
                                          -1 |   ...   |
                                             +---------+
```

- Slayttaki örnekte `test` dosyası **`217`** numaralı bloktan başlamaktadır:
  - FAT tablosunun `217.` indisine bakılır $\implies$ bir sonraki blok **`618`**'dir.
  - FAT tablosunun `618.` indisine bakılır $\implies$ bir sonraki blok **`339`**'dur.
  - FAT tablosunun `339.` indisinde dosya sonu işareti vardır $\implies$ zincir tamamlanır (`217 -> 618 -> 339`).
- Hoca ayrıca bu yapıyı Veri Yapıları dersindeki dizi tabanlı bağlı liste (`array-based linked list`) ile somutlaştırdı (`01:03:08`): 4 elemanlı bir dizide başlangıç `h = 3` ise; `dizi[3] = 2`, `dizi[2] = 0`, `dizi[0] = 1` ve `dizi[1] = -1` (null) olduğunda erişim sırası `3 -> 2 -> 0 -> 1` olur. FAT tablosu ana bellekte önbelleğe (`cache`) alındığında disk kafasını gezdirmeden zincir bellekte hızlıca takip edilebilir.

### 7.3 İndeksli Tahsis (Indexed Allocation) ve Birleşik Şema (UNIX UFS)

Bağlı tahsiste işaretçilerin zincir halinde dağılması yerine, **İndeksli Tahsis (`Indexed Allocation`)** yönteminde her dosyanın tüm veri bloğu işaretçileri o dosyaya ait özel bir **indeks bloğu (`index block`)** içinde tek bir dizi olarak toplanır (ekrandan, 01:04:05):

```text
Dizin (Directory):                  İndeks Bloğu (Blok 19):
+------+-------------+              +------+
| file | index block |              |   9  | ---> Veri Bloğu 9
+------+-------------+              |  16  | ---> Veri Bloğu 16
| jeep |     19      | -----------> |   1  | ---> Veri Bloğu 1
+------+-------------+              |  10  | ---> Veri Bloğu 10
                                    |  25  | ---> Veri Bloğu 25
                                    |  -1  | (Boş)
                                    |  -1  | (Boş)
                                    |  -1  | (Boş)
                                    +------+
```

- Slayttaki örnekte (`01:04:05`) `jeep` dosyasının dizin kaydı **`index block = 19`** değerini tutar. `19` numaralı indeks bloğunun içinde dosyanın sırasıyla `0., 1., 2., 3., 4.` veri bloklarının fiziksel adresleri olan **`9, 16, 1, 10, 25`** numaraları ve kullanılmayan girişler için **`-1`** değerleri yer alır.
- **Avantajı:** Hem dış parçalanma olmaz hem de dosyanın $i$. bloğuna gitmek için indeks bloğunun $i$. satırına doğrudan (`O(1)`) bakılması yeterlidir.
- **İndeks Bloğu Boyutu Problemi ve Çözümleri:** Küçük bir dosya (1-2 blokluk) için bile koca bir indeks bloğu ayırmak alan israfıdır; öte yandan çok büyük bir dosyada tek bir indeks bloğunun içine sığabilecek işaretçi sayısı yetmeyebilir. Büyük dosyalar için üç çözüm kullanılır:
  1. **Bağlı Şema (`Linked scheme`):** Birden fazla indeks bloğu birbirine bağlı liste gibi bağlanır.
  2. **Çok Seviyeli İndeks (`Multilevel index`):** İki seviyeli sayfa tablosuna benzer şekilde, bir **dış indeks bloğu (`outer-index`)** iç indeks bloklarına (`index table`), iç indeks blokları da veri bloklarına işaret eder.
  3. **Birleşik Şema (`Combined Scheme: UNIX UFS`, ekrandan, 01:05:30):** UNIX dosya sisteminde (`UFS`) bir dosyanın `inode` yapısında (4 KB blok boyutu ve 32 bit blok adresleriyle) şu işaretçiler bir arada tutulur:

```text
UNIX UFS inode Yapısı (4K bytes per block, 32-bit addresses):
+-------------------+
|       mode        |
+-------------------+
|    owners (2)     |
+-------------------+
|  timestamps (3)   |
+-------------------+
| size block count  |
+-------------------+
|                   | ---> [ data ] (Doğrudan veri bloğu 1)
|   direct blocks   | ---> [ data ] (Doğrudan veri bloğu 2)
|  (ilk 12 işaretçi)| ---> [ data ] ...
|                   | ---> [ data ]
+-------------------+
|  single indirect  | ---> [ İndeks Bloğu ] ---> [ data ]
+-------------------+
|  double indirect  | ---> [ Dış İndeks ] ---> [ İç İndeks ] ---> [ data ]
+-------------------+
|  triple indirect  | ---> [ 1. İndeks ] ---> [ 2. İndeks ] ---> [ 3. İndeks ] ---> [ data ]
+-------------------+
```

Bu birleşik şema sayesinde:
- **Küçük dosyalar** ek bir indeks bloğu okumaya gerek kalmadan doğrudan **`direct blocks`** işaretçileriyle çok hızlı açılır ve okunur.
- Dosya büyüdükçe sırasıyla **tekli dolaylı (`single indirect`)**, **ikili dolaylı (`double indirect`)** ve **üçlü dolaylı (`triple indirect`)** indeks ağaçları devreye girerek devasa boyutlardaki dosyaların adreslenebilmesini sağlar.

---

## 8. Boş Alan Yönetimi (Free-Space Management): Bit Vektörü ve Bağlı Boş Alan Listesi

Dosya sistemi yalnızca dolu blokları (dosyaları) değil, yeni bir dosya oluşturulacağında veya mevcut bir dosyaya veri ekleneceğinde nereye yazılacağını bilmek için diskteki **boş blokları (`free-space list`)** da takip etmek zorundadır. Bunun için başlıca iki yöntem kullanılır:

### 8.1 Bit Vektörü / Bit Haritası (Bit Vector / Bit Map)

Disk üzerinde $n$ adet blok (`0, 1, 2, ..., n-1`) varsa, boş alan listesi $n$ bitlik bir **bit haritası (`bit map` / `bit vector`)** olarak tutulur (ekrandan, 01:06:55):
$$\text{bit}[i] = \begin{cases} 1 \implies \text{block}[i]\text{ boş (free)} \\ 0 \implies \text{block}[i]\text{ dolu (occupied)} \end{cases}$$

Örneğin ilk blokların durumu şöyleyse:
`0011110011111100...` $\implies$ Blok `0` ve `1` dolu (`0`), blok `2, 3, 4, 5` boş (`1`), blok `6, 7` dolu (`0`) demektir.

**İlk Boş Bloğun Numarasını Hesaplama Formülü (ekrandan, 01:06:55):**
İşlemciler bit haritasını bit bit değil, kelime kelime (`word` — örneğin 8 bit, 32 bit veya 64 bit) tarar ve bir kelimenin içindeki ilk `1` bitinin konumunu (`offset`) bulan özel donanım komutlarına sahiptir. Tamamen dolu olan kelimelerin değeri `0`'dır (`0-value words`). İlk boş bloğun diskteki numarası şu formülle hesaplanır:
$$\text{Blok Numarası} = (\text{Kelime başına bit sayısı}) \times (\text{0-değerli kelime sayısı}) + (\text{İlk '1' bitinin kelime içi ofseti})$$
$$\text{Block number} = (\text{number of bits per word}) \times (\text{number of 0-value words}) + \text{offset of first 1 bit}$$

### 8.2 Disk Üzerinde Bağlı Boş Alan Listesi (Linked Free Space List on Disk)

İkinci yöntemde tüm boş disk blokları birbirine işaretçilerle bağlanarak bir **bağlı liste (`linked list`)** oluşturur (`01:07:15`). İşletim sistemi yalnızca **ilk boş bloğun işaretçisini (`free-space list head`)** özel bir konumda (veya bellekte) tutar:
- Örneğin slayttaki (`12.37`) bağlı boş alan listesinde başlangıç işaretçisi blok **`2`**'yi gösterir; blok `2`'nin içindeki işaretçi bir sonraki boş blok olan **`3`**'ü gösterir ve zincir tüm boş bloklar üzerinden (`2 -> 3 -> 4 -> 5 -> 8 -> 9 -> 10 -> 11 -> 12 -> 13 -> 17 -> 18 -> 20 -> 26 -> 27 ...`) devam eder.
- Yeni bir blok gerektiğinde listenin başındaki ilk boş blok alınır, G/Ç maliyetini azaltmak için tek blok yerine boş blok kümeleri de birlikte yönetilebilir.

---

## Örnek Sorular

### Soru 1: UNIX/Linux Dosya Erişim İzinleri (`chmod`) ve İkilik-Sekizlik Kodlama (ekrandan, 00:45:55)

**Soru:** Bir UNIX/Linux sisteminde `game` adlı bir dosya ve `G` adlı bir kullanıcı grubu bulunmaktadır. Dosya sahibi (`owner`) bu dosya üzerinde **okuma, yazma ve çalıştırma** yetkilerinin tamamına; `G` grubundaki kullanıcılar **okuma ve yazma** yetkisine (çalıştırma hariç); sistemdeki diğer tüm kullanıcılar (`public`) ise yalnızca **çalıştırma** yetkisine sahip olsun istenmektedir.
a) Her kullanıcı sınıfı için 3 bitlik `RWX` ikilik (`binary`) ve sayısal/sekizlik (`octal`) karşılıklarını bulunuz.
b) Bu izinleri `game` dosyasına atayan ve dosyayı `G` grubuna bağlayan kabuk (`shell`) komutlarını yazınız.

**Çözüm (derste verildi):**
- **a)** `R` (Read $= 4$), `W` (Write $= 2$), `X` (Execute $= 1$) olmak üzere:
  - **Dosya sahibi (`owner access`):** Okuma (`1`), Yazma (`1`), Çalıştırma (`1`) $\implies \text{RWX} = \mathbf{111_2 = 7}$
  - **Grup (`group access`):** Okuma (`1`), Yazma (`1`), Çalıştırma (`0`) $\implies \text{RWX} = \mathbf{110_2 = 6}$
  - **Genel (`public access`):** Okuma (`0`), Yazma (`0`), Çalıştırma (`1`) $\implies \text{RWX} = \mathbf{001_2 = 1}$
- **b)** İlgili kabuk komutları:
  ```bash
  chmod 761 game
  chgrp G game
  ```

### Soru 2: Bitişik Tahsiste (Contiguous Allocation) Mantıksal-Fiziksel Blok Adresi Hesabı (ekrandan, 01:00:30)

**Soru:** Disk blok boyutunun **$512\text{ bayt}$** olduğu bir dosya sisteminde bitişik tahsis (`contiguous allocation`) kullanılmaktadır ve dizin tablosunda `mail` dosyasının başlangıç bloğu **`start = 19`**, uzunluğu ise **`length = 6`** blok olarak kayıtlıdır.
a) `mail` dosyası disk üzerinde hangi fiziksel blokları kaplamaktadır?
b) Bir proses `mail` dosyasının içindeki **$1200.$ mantıksal bayta (`LA = 1200`)** erişmek isterse hangi fiziksel disk bloğuna ve o bloğun içindeki kaçıncı bayt ofsetine (`displacement`) erişilir?

> **Çözüm (derste verilmedi):**
> - **a)** `mail` dosyası `19.` bloktan başlayıp ardışık `6` blok kapladığından fiziksel olarak **`19, 20, 21, 22, 23 ve 24`** numaralı bloklarda yer alır.
> - **b)** Slayttaki (`01:00:30`) $\text{LA} / 512 \implies (Q, R)$ formülüne göre $\text{LA} = 1200$ değeri $512$'ye bölünür:
>   $$1200 = 2 \times 512 + 176 \implies Q = 2,\quad R = 176$$
>   - **Erişilecek fiziksel blok:** $Q + \text{starting address} = 2 + 19 = \mathbf{21.\text{ blok}}$
>   - **Blok içi ofset (`displacement`):** $R = \mathbf{176.\text{ bayt}}$

### Soru 3: Boş Alan Yönetiminde Bit Vektörü (Bit Vector) ile İlk Boş Blok Hesabı (ekrandan, 01:06:55)

**Soru:** Boş alan yönetimini **bit vektörü (`bit map` — `1: boş`, `0: dolu`)** ile yapan bir dosya sisteminde işlemci kelime uzunluğu (**`number of bits per word`**) **$8\text{ bit}$** (1 bayt) olsun. Bit haritasının ilk kelimeleri sırasıyla şöyle verilmiştir:
`00000000  00000000  00010110 ...`
Slayttaki (`01:06:55`) blok numarası formülünü kullanarak diskteki **ilk boş bloğun numarasını** (`0` tabanlı indislemeyle) hesaplayınız.

> **Çözüm (derste verilmedi):**
> Slaytta verilen formül:
> $$\text{Block number} = (\text{number of bits per word}) \times (\text{number of 0-value words}) + \text{offset of first 1 bit}$$
> - Kelime başına bit sayısı (`number of bits per word`) $= \mathbf{8}$.
> - Tamamı `0` olan (dolu) kelime sayısı (`number of 0-value words`): İlk iki kelime `00000000` olduğundan $= \mathbf{2}$.
> - Üçüncü kelime olan `00010110` içinde ilk `'1'` bitinin kelime içi ofseti (`0.` bitten başlayarak: `bit 0 = 0, bit 1 = 0, bit 2 = 0, bit 3 = 1`) $= \mathbf{3}$.
> - İlk boş blok numarası:
>   $$\text{Block number} = 8 \times 2 + 3 = \mathbf{19.\text{ blok}}$$

---

## Dersin Toparlaması

İşletim Sistemleri dersinin bu son haftasında kalıcı depolama yönetiminin mantıksal ve gerçekleme katmanları olan **Dosya Sistemi Arayüzü (`File-System Interface`)** ve **Dosya Sistemi Gerçeklemesi (`File-System Implementation`)** konuları tamamlanmıştır. İlk bölümde dosyanın soyut veri tipi (`ADT`) olarak tanımı, `header-content-footer` yapısı, dosya öznitelikleri (`Name, Identifier, Type, Location, Size, Protection, Timestamps`), açık dosya tabloları, dosya kilitleme, sıralı (`sequential`), doğrudan (`direct`) ve indeksli (`indexed`) erişim yöntemleri, dört temel dizin mimarisi (`Single-Level`, `Two-Level`, `Tree-Structured`, `Acyclic/General Graph`) ve UNIX `chmod` (`RWX`) koruma izinleri incelenmiştir. İkinci bölümde ise katmanlı dosya sistemi mimarisi, **Dosya Kontrol Bloğu (`FCB` / `inode` / `MFT`)**, `open()` ve `read()` sistem çağrılarının çekirdek belleğindeki açık dosya tablolarıyla çalışması, **Sanal Dosya Sistemi (`VFS`)**, disk üzerinde **Bitişik (`Contiguous`)**, **Bağlı (`Linked / FAT`)** ve **İndeksli (`Indexed / UNIX UFS`)** blok tahsis yöntemleri ile **Bit Vektörü (`Bit Vector`)** ve **Bağlı Boş Alan Listesi (`Linked Free-Space List`)** yapıları ele alınarak dönem müfredatı tamamlanmıştır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
