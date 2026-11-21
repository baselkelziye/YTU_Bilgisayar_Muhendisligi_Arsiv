# Ders 7 Genişletilmiş Notu: Nesneye Yönelik Çözümleme Uygulaması (Süreli Yayın Yönetim Yazılımı: Kullanım Senaryosu, Use Case Şeması ve Alan Modeli)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Uygulama Problemi: Süreli Yayın Yönetim Yazılımı Gereksinimleri
- 2. Kullanım Senaryosu (Use Case) Metninin Hazırlanması ve Öğrenci Çözümlerinin Değerlendirilmesi
- 3. UML Kullanım Şemasının (Use Case Diagram) Çizilmesi ve Kırılım İlkeleri
- 4. Alan Modelinin (Metotsuz UML Sınıf Şeması) Oluşturulması ve 3 Tasarım Alternatifinin Karşılaştırılması
- Örnek Sorular
- Dersin Toparlaması

## 1. Uygulama Problemi: Süreli Yayın Yönetim Yazılımı Gereksinimleri

Bu ders, gereksinim mühendisliği ve nesneye yönelik çözümleme (*Object-Oriented Analysis*) aşamalarında öğrenilen üç temel yapıtın —**Kullanım Senaryosu Metni**, **UML Kullanım Şeması (*Use Case Diagram*)** ve **Alan Modeli (*Domain Model*)**— uçtan uca bir problem üzerinde uygulandığı ve öğrenci çözümleriyle alternatif hoca çözümlerinin karşılaştırıldığı bir laboratuvar/uygulama dersidir.

Uygulama konusu olarak seçilen **Süreli Yayın Yönetim Yazılımı** probleminin gereksinimleri özetle şöyledir (ekrandan, 00:30:00):
- **Süreli Yayın (*Periodical*) ve ISSN Yapısı:** Kütüphanenin abone olduğu süreli yayınlar (dergiler); yeni sayılarının aylık, üç aylık veya dört aylık gibi belirli periyotlarla (`periyot`) çıktığı ve her birinin bir yayın adına (`isim`) sahip olduğu yayınlardır. Her süreli yayını diğerlerinden ayırt eden **8 karakterlik bir ISSN (*International Standard Serial Number*)** numarası vardır: ilk 7 karakteri `0-9` arası rakamlardan oluşur, 8. (son) karakteri ise `0-9` arası bir rakam ya da `10` değerini temsil eden `X` karakteridir (örneğin aylık bir dergi olan *Nature* dergisinin ISSN'i `09534563` olarak verilmiştir) (ekrandan, 00:30:00).
  - Hoca derste ISSN'in 8. basamağının bir tutarlılık kontrol basamağı (*checksum digit*) olduğunu, ilk 7 basamağın belirli ağırlıklarla çarpılıp toplamının **mod 11**'ine göre hesaplandığını ve mod 11'de kalan `10` çıktığında tek karakterle göstermek için `X` harfinin kullanıldığını açıklamıştır (ancak gereksinim metninde bu *checksum* algoritması açıkça istenmediği için şemalara "ISSN geçerlilik kontrolü" adında ayrı bir işlev eklenmesine gerek olmadığını vurgulamıştır).
- **Üç Tür Abonelik Modeli:** Kütüphane süreli yayınlara bazen **yalnızca basılı**, bazen **yalnızca elektronik**, bazen de **hem elektronik hem basılı** olarak abone olmaktadır (ekrandan, 00:30:00):
  1. **Elektronik Yayınlar:** Derginin bütün sayılarına erişmek için kullanılan tek bir web adresi (**`URL`**) ve kütüphanenin o derginin geriye dönük kaç yıllık arşiv sayılarına erişim hakkı olduğunu gösteren **`backfile`** bilgisi saklanır (bazı elektronik dergilerde ise geriye dönük erişim sınırı bulunmamaktadır; bu durumda `backfile` değeri `0` olarak tutulur).
  2. **Basılı Yayınlar ve *Check-in* Kartı:** Kütüphanede bulunan her basılı dergi sayısı için **`yıl`**, **`sayı`** ve **`durum`** bilgileri saklanır. Kütüphaneci yeni gelen bir basılı dergi sayısını sisteme gireceği (*check-in* yapacağı) zaman, derginin mevcut sayılarının her biri ekranda birer kutucuk (**check-in kartı**) içerisinde yıl, sayı ve durum bilgileriyle gösterilir. Olası durumlar **`Geldi`** ve **`Bekleniyor`**dur: sistem o anki tarihe ve derginin periyoduna göre gelecek sayıların durumunu otomatik olarak `'Bekleniyor'` şeklinde belirler (arada kütüphaneye ulaşmamış geciken sayılar da `'Bekleniyor'` kalır); kütüphaneci ise ilgili kutucuğa tıklayarak o sayının durumunu `'Geldi'` olarak değiştirebilir (ekrandan, 00:30:00).
- **Yeni Gelen Sayının İşlenmesi Akışı:** Kütüphaneye bir süreli yayın sayısı ulaştığında, eğer sistemde o yayının kaydı henüz yoksa kütüphaneci önce derginin ISSN, ad ve periyot bilgilerini, ardından aboneliğin basılı ve/veya elektronik olmasına göre gerekli bilgileri girerek kaydı oluşturur; yayının kaydı zaten mevcutsa yukarıda belirtilen şekilde sayıyı sisteme `'Geldi'` olarak işler (ekrandan, 00:30:00).

## 2. Kullanım Senaryosu (Use Case) Metninin Hazırlanması ve Öğrenci Çözümlerinin Değerlendirilmesi

Uygulamanın ilk adımında ("a şıkkı"), kütüphaneye yeni gelen süreli yayınlar ile ilişkili **Kullanım Senaryosu Metninin** yazılması istenmiştir. Önce iki gönüllü öğrencinin çözümü incelenmiş, ardından hocanın örnek çözümü üzerinden kurallar pekiştirilmiştir.

### 2.1 Öğrenci Çözümleri Üzerinden Kritik Geri Bildirimler

1. **Serbest Notlardan Standart 3 Bölümlü Formata Geçiş (1. Öğrenci Çözümü) (ekrandan, 00:50:00):**
   - Bir öğrenci ekranda *"Süreli yayın kayıtlıysa"*, *"Yeni bir dergi girildiyse"* ve *"Girilmiş yayın URL'si backfile süresini doldurmuşsa"* başlıklarıyla maddeler hâlinde bir taslak paylaşmıştır (ekrandan, 00:50:00).
   - **Hocanın Değerlendirmesi:** Çıkarılan malzeme doğru olmakla birlikte, bir kullanım senaryosu metni serbest başlıklarla bırakılamaz; mutlaka **1) Giriş Bölümü** (*Birincil Aktör, İlgililer ve İlgi Alanları, Ön Koşullar, Son Koşullar*), **2) Ana Senaryo** (`1`'den `N`'ye numaralı adımlar) ve **3) Alternatif Senaryolar** (`1a`, `3a` gibi numaralı adımlar) formatına dönüştürülmelidir.
   - **Hangisi Ana Senaryo, Hangisi Alternatif Senaryo Olmalı?** Kütüphanelerde mevcut dergi abonelikleri sürekli değişmez ve sıfırdan yeni bir derginin çıkmaya başlaması nispeten nadirdir; buna karşılık abone olunan mevcut dergilerin yeni sayıları her ay düzenli olarak gelir. Bu nedenle **kayıtlı bir süreli yayının yeni sayısının girilmesi Ana Senaryo**, sistemde **kayıtlı olmayan yeni bir dergi aboneliğinin oluşturulması ise Alternatif Senaryo** olarak seçilmelidir (ancak sınavda tersini seçip tutarlı kurgulayan bir öğrenciden de puan kırılmaz).
2. **Ön Koşul, Son Koşul Kipi ve Terim Doğruluğu (2. Öğrenci Çözümü) (ekrandan, 00:56:00):**
   - İkinci öğrenci 3 bölümlü şablona uygun bir metin paylaşmış; ilgililere `Kurye`yi eklemiş, `Ön Koşullar: Ön koşul yok` yazmış, `Son Koşullar`da ve adımlarda ise *"yeni gelmiş kitabın kaydı"*, *"yayının ISBN numarası"* ve *"durumunu uygun şekilde ayarlar"* ifadelerini kullanmıştır (ekrandan, 00:56:00).
   - **Hocanın Değerlendirmesi:**
     - **Joker Ön Koşul:** Ön koşul kısmına asla *"Ön koşul yok"* yazılmamalıdır. Metinde özel bir ön koşul göze çarpmıyorsa bile her bilgi sisteminde geçerli olan **"Joker" ön koşul** yazılmalıdır: *"Kütüphaneci sisteme giriş (login) yapmıştır"* (veya *"Yayının kütüphaneye fiziksel olarak ulaşmış olması"* da ön koşul yapılabilir).
     - **Son Koşulda Zaman Kipi:** Son koşul, ana senaryo tamamlandıktan sonraki sistem durumunu anlattığı için *"var olması"* yerine tamamlanmış iş bildiren **edilgen geçmiş zaman kipiyle** (*"Süreli yayın ve sayı kayıtları sisteme girilmiş ve/veya güncellenmiştir"*) yazılması daha uygundur.
     - **Problem Alanı Terminolojisi (Kitap/ISBN vs. Süreli Yayın/ISSN):** Problem alanında kitaplarla değil **süreli yayınlarla (dergilerle ve sayılarıyla)** çalışılmaktadır; kitapların numarası ISBN iken süreli yayınların numarası **ISSN**'dir. Müşterinin dilinden konuşmak için metinde kitap/ISBN değil, süreli yayın/dergi ve ISSN terimleri kullanılmalıdır.
     - **Belirsiz İfadelerden Kaçınma:** 4. adımda *"durumunu uygun şekilde ayarlar"* ifadesi üstü kapalıdır; parantez içinde olası durumlar (`'Geldi'` veya `'Bekleniyor'`) açıkça belirtilmelidir.
     - **Alternatif Senaryoda "Bir Şey Yapılmaz" Durumu:** Öğrencinin `3-4a` alternatifinde yazdığı *"Eğer bu yayının bu periyodu (sayısı) zaten mevcut ise kayıtlarda bir şeyin değişmesi gerekmez"* maddesi, başka alternatif senaryosu az olan metinlerde `if-else` yapısını tamamlamak için geçerli ve akıllıca bir yaklaşımdır.

### 2.2 Hocanın Örnek Kullanım Senaryosu Çözümü

Çözüm belgesinde yer alan **Yeni Sayı Girişi (*Check-in*)** kullanım senaryosunun tam yapısı şöyledir (ekrandan, 01:01:00; ekrandan, 01:04:00):

- **Giriş Bölümü (ekrandan, 01:01:00):**
  - **Birincil Aktör:** Kütüphaneci.
  - **Diğer İlgililer:** Yok.
  - **İlgi Alanları:** Kütüphaneci, yeni ve eski her dergi sayısının bilgilerini doğru olarak işleyebilmeyi ister.
  - **Ön Koşullar:** Kütüphaneci sisteme girmiştir.
  - **Son Koşullar:** Süreli yayın ve sayı kayıtları sisteme girilmiş ve/veya güncellenmiştir.
- **Ana Senaryo (ekrandan, 01:01:00):**
  1. Kütüphaneci kütüphaneye yeni gelen derginin ISSN'ini girer.
  2. Derginin basılı aboneliği varsa; ad, ISSN ve periyot bilgileri gösterilir.
  3. Derginin basılı aboneliği varsa, bu yıla ait sayıları kutucuklar şeklinde gösterilir. Mevcut sayıların durumu sistemden elde edilir, gelecek sayıların durumu `'Bekleniyor'` olarak gösterilir.
  4. Derginin elektronik aboneliği varsa, `URL` ve `backfile` bilgileri de gösterilir.
  5. Kütüphaneci ekranda sunulan tüm bilgileri gereken şekilde günceller ve onay düğmesine basar.
- **Alternatif Senaryolar (ekrandan, 01:04:00):**
  - **1a. Yeni abonelik** *(Ana senaryonun 1. adımında ISSN arandığında kayıt bulunamaması durumu)*:
    1. Sistem derginin ISSN'ini bulamamıştır, kütüphaneciye yeni abonelik oluşturmayı önerir.
    2. Kütüphaneci öneriyi onaylarsa sistem kütüphaneciden derginin adını, ISSN'ini ve periyodunu alır.
    3. Derginin elektronik aboneliği varsa `URL` ve `backfile` bilgileri kütüphaneciden alınır.
    4. Derginin basılı aboneliği varsa `yıl` ve `sayı` bilgileri kütüphaneciden alınır.
    5. Sistem girilen sayının durumunu `'Geldi'` olarak atar.
  - **3a. Kütüphaneci önceki yıla ait bir sayının işlemini yapmak ister** *(Ana senaryonun 3. adımında bu yılın kutucukları gösterildiğinde, gecikmeli gelen geçen yıla ait bir sayıyı veya stajyerin yanlış girdiği eski bir kaydı düzeltmek istemesi durumu)*:
    1. Kütüphaneci görmek istediği yılı belirtir.
    2. Sistem girilen yılın kutucuklarını çizerek sayıların durumlarını veritabanından alır.

### 2.3 Kullanım Senaryosu Hakkında Öğrenci Soruları ve Cevaplar

**Soru:** Sınavlarda ve projelerde kullanım senaryosu metninde mutlaka bulunmasını istediğiniz üç kısım neydi?

**Cevap:** 1) **Giriş Bölümü** (kullanım senaryosunun adı, *Birincil Aktör*, *İlgililer ve İlgi Alanları*, *Ön Koşullar*, *Son Koşullar*), 2) **Ana Senaryo** (`1, 2, ...` şeklinde numaralandırılmış adımlar), 3) **Alternatif Senaryolar** (ana senaryonun hangi adımında gerçekleştiğini gösteren `1a`, `3a` gibi iki bileşenli anlamlı kodlarla ve kendi alt adım numaralarıyla yazılmış en az bir alternatif akış) (ekrandan, 01:01:00; ekrandan, 01:04:00). Buradaki `1a` "birinci alternatif" demek değildir; **"ana senaryonun 1. adımındaki ilk (`a`) alternatif"** demektir; değerlendirmede `1a` yazıldığında gerçekten 1. adımın alternatifi olup olmadığı kontrol edilir.

**Soru:** Ana senaryoda `if-else` gelebilecek her durumda `if` (normal) kolunu ana senaryoya, `else` kolunu ise aşağıda alternatif senaryoya bir koşul olarak yazıyoruz, değil mi?

**Cevap:** Aynen öyle. Ana senaryodaki her dallanmanın `else` (istisna veya farklı varyasyon) kolu, alternatif senaryo oluşturmamızı sağlar.

## 3. UML Kullanım Şemasının (Use Case Diagram) Çizilmesi ve Kırılım İlkeleri

Uygulamanın ikinci adımında, hem doğal dildeki gereksinimler belgesi hem de yukarıda yazılan kullanım senaryosu metni dikkate alınarak **UML Kullanım Şeması (*Use Case Diagram*)** çizilmiştir.

### 3.1 Öğrenci Şeması Üzerinden "İnce Kırılım (Granularity)" Eleştirisi

Bir öğrenci *Violet UML Editor* üzerinde çizdiği şemada `Kütüphaneci` ve `Kütüphane Sistemi` aktörlerini koymuş; elips olarak `Yayının gelen periyodunun eklenmesi`, `Yayının yıl ve sayısının oluşturulması` (`<<extend>>`), `Yayın sayısının durumunun geldi olarak değiştirilmesi` (`<<include>>`), `Yayın kaydının oluşturulması` (`<<extend>>`), `Backlog miktarının belirlenmesi` (`<<extend>>`) ve `URL'in belirlenmesi` (`<<extend>>`) olmak üzere 6 adet *use case* tanımlamıştır (ekrandan, 01:33:00).

> **Hocanın vurgusu (Use Case Kırılım / Ayrıntı Düzeyi):**
> 1. **Tek Adımlık İşlemler *Use Case* Yapılmaz:** Öğrencinin şemasındaki `URL'in belirlenmesi`, `Backlog (backfile) miktarının belirlenmesi` veya `Durumun geldi olarak değiştirilmesi` gibi elipsler çok ince kırılımlıdır (*fine-grained*); bunların her biri kendi başına 5–6 adımlı birer kullanım senaryosu değil, `Yeni Abonelik` veya `Yeni Sayı Girişi` senaryosunun içindeki **1–2 satırlık tekil adımlardır**. Bir *use case* elipsi, kendi içinde en az 3–4 adımdan oluşan ve mümkünse kendi alternatif akışları olabilen anlamlı bir işlev bütününü temsil etmelidir.
> 2. **Proje Ödevinde Şema–Metin Eşleşmesi:** Proje ödevinde UML kullanım şemasında 6 tane *use case* elipsi çizilmişse, raporda bu 6 *use case*'in her biri için ayrı bir kullanım senaryosu metni bulunup bulunmadığına bakılır (sınavda ise süre kısıtı nedeniyle şemadaki tüm elipslerin değil, yalnızca soruda istenen ana *use case*'in metni yazılır).
> 3. **Terim Dikkati:** *"Yayının gelen periyodunun eklenmesi"* ifadesindeki "periyot" kelimesi yanlış kullanılmıştır; periyot derginin kaç ayda bir çıktığıdır, kütüphaneye gelen şey ise derginin yeni **sayısıdır**.
> 4. **İnsan Olmayan Aktör Gösterimi:** `Kütüphane Sistemi` zaten tasarladığımız sistemin kendisi olduğu için aktör olarak çizilmez; eğer harici bir sistem aktör olarak çizilecekse normalde `<<actor>>` stereotipli dikdörtgen kullanılır (ancak *Violet UML Editor*'de dikdörtgen aktör sembolü bulunmadığı için çöp adam kullanılmasından puan kırılmaz).

**Soru:** Bir `<<extend>>` durumu oluşturduğumuzda, ana *use case* ile onu genişleten `<<extend>>` *use case*'inin kullanım senaryosu metninde iki ayrı metin olarak mı bulunması gerekir, yoksa ikisi aynı kullanım senaryosu metninin içinde (biri Ana Senaryo, diğeri Alternatif Senaryo olarak) bulunabilir mi?

**Cevap:** Biri kullanım senaryosu metninin **Ana Senaryo** kısmında, diğeri aynı metnin **Alternatif Senaryolar** kısmında (ör. `1a. Yeni abonelik`) yer alabilir; bunda hiçbir sıkıntı yoktur.

### 3.2 Hocanın Doğaçlama Şeması ve Çözüm PDF'indeki 4 Şema Alternatifi

Hoca önce *Violet UML* üzerinde kullanım senaryosu metniyle birebir örtüşen şu şemayı oluşturmuş, ardından çözüm PDF'indeki 4 şema alternatifini değerlendirmiştir (ekrandan, 01:48:00; ekrandan, 01:58:00; ekrandan, 02:00:00):

```text
   O          .-------------------.    <<extend>>   .-----------------------.
  /|\ ------- |   Yeni Abonelik   | < - - - - - - - |    Basılı Abonelik    |
  / \         '-------------------'                 '-----------------------'
Kütüphaneci        |         ^                                  ^
   |               |          \        <<extend>>               :
   |               |           '- - - - - - - - - - .-----------------------.
   |               | <<extend>>                     |  Elektronik Abonelik  |
   |               v                                '-----------------------'
   |          .-------------------.    <<extend>>   .-----------------------.
   +--------- | Yeni Sayı Gelişi  | < - - - - - - - | Önceki Yıla Ait       |
   |          '-------------------'                 | Sayının İşlenmesi     |
   |                    |                           '-----------------------'
   |                    | <<include>>
   |                    v
   |          .-------------------------.                O
   +--------- |  Sayı Kutucukları Çiz.  | ------------- /|\
              | (Check-in Kartı Göster.)|               / \
              '-------------------------'             Okuyucu
                           ^
                           | <<extend>>
              .-------------------------.
              |  Check-in Kartı         |
              |  Düzenlemesi            |
              '-------------------------'
```

Çözüm PDF'indeki şemalar üzerinden vurgulanan kritik noktalar şunlardır (ekrandan, 01:58:00; ekrandan, 02:00:00):
1. **İlişkisiz Şemalardan Kaçınma:** Yalnızca `Kütüphaneci` aktörünü `Abonelik` ve `Yeni sayı gelişi` elipslerine düz çizgiyle bağlayıp hiçbir `<<include>>` veya `<<extend>>` oku içermeyen bir şema tam not alamaz; sınavda ve projede hem `<<include>>` hem `<<extend>>` ilişkilerinin doğru kullanıldığı gösterilmelidir.
2. **`Basılı` ve `Elektronik` Neden `<<include>>` Değil `<<extend>>` Olmalıdır? (ekrandan, 02:00:00):**
   - Çözüm PDF'inin sağ üst köşesindeki hatalı örnekte `Yeni sayı gelişi`nden `Basılı` ve `Elektronik` elipslerine `<<include>>` oku çizilmiştir.
   - Hoca bu şemanın yanına düştüğü uyarı notunda; bir dergiye **yalnızca basılı**, **yalnızca elektronik** veya **basılı + elektronik** olarak 3 şekilde abone olunabildiğini, metindeki *"basılı aboneliği varSA, elektronik aboneliği varSA"* ifadelerinin bunların zorunlu değil koşullu olduğunu gösterdiğini, dolayısıyla `<<include>>` yerine **`<<extend>>`** kullanılması gerektiğini vurgulamıştır (ekrandan, 02:00:00).
3. **Soru: `Basılı Abonelik` ve `Elektronik Abonelik` Neden Ayrı Birer *Use Case* Elipsi Olarak Düşünüldü?**
   - Bir öğrenci *"Ben basılı ve elektronik aboneliği ayrı birer use case olarak düşünmezdim, neden ayrı elips yaptık?"* diye sormuştur.
   - **Cevap:** Çünkü her ikisi de tek adımlık birer veri girişi değildir; elektronik abonelikte `URL` girilmesi, `backfile` sınırının girilmesi (sınırsızsa `0` girilmesi alternatifi), basılı abonelikte ise periyot, yıl, sayı ve kutucukların oluşturulması gibi kendi içinde birden fazla adımdan oluşan alt süreçler vardır.
4. **Gereksinimlere "Check-in Kartı ve Okuyucu" Paragrafı Eklendiğinde (ekrandan, 01:58:00):**
   - Eğer gereksinim belgesine *"Kütüphanecinin içerisine tıklayarak değiştirebileceği, okuyucuların ise değiştiremeden sadece içeriğini görebilme yetkisine sahip olduğu yukarıda anlatılan ekrana derginin check-in kartı denilir"* cümlesi eklenirse:
   - `Yeni sayı gelişi` her çalıştığında bu kart ekrana geldiği için `Yeni sayı gelişi ----<<include>>---> Check-in kartı gösterimi` ilişkisi kurulur (önceki yıla ait sayı işleminde veya abonelikte ise koşullu olduğu için `<<extend>>` olabilir).
   - `Okuyucu` aktörü yalnızca `Check-in kartı gösterimi`ne bağlanır; kartın üzerindeki kutucuklara tıklayarak durumu güncelleme işi ise her gösterimde yapılmadığı (yalnızca kütüphaneci tarafından yapılabildiği) için `Check-in kartı düzenlemesi ----<<extend>>---> Check-in kartı gösterimi` olarak bağlanır (ekrandan, 01:58:00).

## 4. Alan Modelinin (Metotsuz UML Sınıf Şeması) Oluşturulması ve 3 Tasarım Alternatifinin Karşılaştırılması

Uygulamanın üçüncü adımında ("b/c şıkkı"), metindeki isimler ve nitelikler analiz edilerek metotsuz UML Sınıf Şeması (**Alan Modeli**) oluşturulmuştur.

### 4.1 Öğrenci Sınıf Şemasının İncelenmesi

Bir öğrenci ekranda `Yayınlar <>--- Süreli Yayın`, `Süreli Yayın` (`ISSN: String`, `isim: String`) üst sınıfından kalıtımla türeyen `Elektronik` (`URL: String`, `backlog: int`) ve `Basılı` alt sınıfları, ayrıca `Basılı <*>--- Sayı` (`yıl: Date`, `sayı: int`, `durum: boolean`) şeklinde bir sınıf şeması paylaşmıştır (ekrandan, 02:30:00).

Hoca bu şema üzerinden şu önemli kuralları hatırlatmıştır:
1. **Veri Gizleme (*Encapsulation*) İçin `-` (*Private*) İşareti:** Sınıf kutularında üye alanlar yazılırken başlarına mutlaka **`-`** işareti konulup bir boşluk bırakılmalıdır (`- ISSN: String`, `- isim: String`). Bu işaret üye alanların `private` olduğunu ve kapsülleme ilkesine uyulduğunu gösterir.
2. **İlişki Okları ve Çokluklar (*Multiplicity*):** Öğrenci `Yayınlar <>--- Süreli Yayın` ve `Basılı <*>--- Sayı` ilişkilerinde elmas (parça-bütün) kullandığı için yön ve çokluk örtük olarak anlaşılır; ancak elmas yerine düz çizgi kullanılsaydı mutlaka **ok ucu** ve her iki uca **çokluk (`1` ve `1..*` veya `*`)** değerleri yazılmalıydı.
3. **Kalıtım ve Çok Biçimlilik (*Polymorphism*) Değerlendirmesi:**
   - `Süreli Yayın` sınıfının iki alt sınıfı (`Basılı` ve `Elektronik`) olduğu ve sistemde ne basılı ne elektronik olan soyut bir dergi bulunamayacağı için, `Süreli Yayın` üst sınıfının **`«abstract»` (soyut sınıf)** olarak tanımlanması gerekir (arayüz [*interface*] yapılamaz çünkü içinde `- isim, ISSN: String` üye alanları vardır).
   - İleride tasarım aşamasına geçildiğinde tüm yayınları çok biçimli (*polymorphic*) olarak listelemek için üst sınıfa `ekBilgiGöster()` gibi bir metot konulabilir: bu metot `Elektronik` alt sınıfında `URL` ve `backfile` bilgilerini gösterirken, `Basılı` alt sınıfında tüm sayıların *check-in* kartını gösterir.

### 4.2 Hocanın Çözüm Belgesindeki 3 Alan Modeli Alternatifinin Karşılaştırılması

Çözüm belgesinde problem alanını modelleyen **3 farklı Alan Modeli** verilmiş ve tasarım kalitesi açısından **1. Tercih (En İyi), 2. Tercih ve 3. Tercih** olarak sıralanmıştır (ekrandan, 02:35:00):

```text
================================================================================
1. TASARIM (1. TERCİH — EN İYİ): KALITIMSIZ (SAHİPLİK VE PARÇA-BÜTÜN İLİŞKİLİ)
================================================================================
+--------------------+          +-------------------------------+
|        Sayı        | *        |         Süreli Yayın          |
+--------------------+---------<>-------------------------------+
| - sayiNo, yil: int |          | - isim, ISSN : String         |
| - periyot : int               |
| - durum : String   |          | - sayılar[] : Sayı            |
+--------------------+          | - e_dergi : ElektronikDergi   |
                                +-------------------------------+
                                 (Not: periyot = kaç ayda bir  | 1
                                  çıktığını gösteren sayı)     |
                                                               | 0..1
                                                               v
                                                +----------------------+
                                                |   ElektronikDergi    |
                                                +----------------------+
                                                | - URL : String       |
                                                | - backfile : int     |
                                                +----------------------+
                                                 (Not: backfile sınırsız
                                                  ise 0 olur)

================================================================================
2. TASARIM (2. TERCİH): SOYUT ÜST SINIF VE İKİ ALT SINIFLI KALITIM
================================================================================
                         +------------------------+
                         |      «abstract»        |
                         |      Süreli Yayın      |
                         +------------------------+
                         | - isim, ISSN : String  |
                         | - periyot : int        |
                         +------------------------+
                                     ^
                                    /_\ (Kalıtım)
                                     |
                        +------------+------------+
                        |                         |
            +----------------------+  +----------------------+
            |      BasılıSayı      |  |   ElektronikDergi    |
            +----------------------+  +----------------------+
            | - sayiNo, yil : int  |  | - URL : String       |
            | - durum : String     |  | - backfile : int     |
            +----------------------+  +----------------------+
  Not: Sistemde aynı ISSN'li bir tek ElektronikDergi örneği, birden fazla
       BasılıSayı örneği bulunur. SüreliYayın sınıfı soyut olabilir.

================================================================================
3. TASARIM (3. TERCİH — KUSURLU): TEK ALT SINIFLI KALITIM
================================================================================
             +-------------------------+ 1          * +--------------------+
             |      Süreli Yayın       |------------->|        Sayı        |
             +-------------------------+              +--------------------+
             | - isim, ISSN : String   |              | - sayiNo, yil: int |
             | - periyot : int         |              | - durum : String   |
             | - sayılar[] : Sayı      |              +--------------------+
             +-------------------------+
                          ^
                         /_\ (Kalıtım)
                          |
             +-------------------------+
             |     ElektronikDergi     |
             +-------------------------+
             | - URL : String          |
             | - backfile : int        |
             +-------------------------+
```

> **Hocanın vurgusu (3 Tasarımın Mimari Karşılaştırması):**
> 1. **Neden 3. Tasarım (Alttaki Kalıtım) En Zayıf Tercihtir?**
>    3. Tasarımda `Süreli Yayın` sınıfı basılı dergiyi temsil edecek şekilde `- sayılar[]: Sayı` dizisini içermekte, `ElektronikDergi` ise onun alt sınıfı olmaktadır. Eğer dergi *yalnızca basılı* ise (`Süreli Yayın` nesnesi) veya *hem basılı hem elektronik* ise (`ElektronikDergi` nesnesi) `- sayılar[]` dizisi kullanılır. Ancak dergi **yalnızca elektronik** ise, oluşturulan `ElektronikDergi` nesnesi üst sınıftan hiç kullanmayacağı `- sayılar[]: Sayı` üye alanını miras alır! Üst sınıftan alt sınıfa hiç kullanılmayacak bir üye alanın kalıtımla geçmesi nesneye yönelik tasarımda önemli bir **kusurdur** (ekrandan, 02:35:00).
> 2. **2. Tasarımın (Soyut Üst Sınıflı Kalıtım) Dezavantajı Nedir?**
>    2. Tasarımda (ve öğrencinin çizdiği şemada) `«abstract» Süreli Yayın` üst sınıfından `Basılı` (`BasılıSayı`) ve `ElektronikDergi` alt sınıfları türetilmiştir; böylece kullanılmayan üye alan miras alınmaz. Ancak kütüphane bir dergiye **hem basılı hem elektronik** olarak abone olduğunda, aynı dergi için biri `Basılı`, diğeri `ElektronikDergi` türünden **aynı ISSN'e sahip iki ayrı nesne** oluşturmak zorunda kalırız. Normalde ISSN tekil tanımlayıcıdır (*ID*); sisteme yeni yayın ekleyen `yayınEkle()` metodunda mükerrer ISSN kontrolü yaparken aynı ISSN'i gördüğümüzde hemen reddedemeyiz, `instanceof` (*type casting*) kullanarak *"mevcut nesne `Elektronik` ise ve yeni eklenen `Basılı` ise izin ver"* şeklinde karmaşık ve çirkin tip kontrolü kodları yazmamız gerekir.
> 3. **Neden 1. Tasarım (Sol Üstteki Kalıtımsız Tasarım) En İyi Tercihtir?**
>    **Kalıtım (*inheritance*)**, sınıf düzeyinde tanımlanan ağır sıklet (*heavyweight*) ve statik bir ilişkidir; bir kez tanımlandığında tüm nesneleri bağlar. Buna karşılık **sahiplik (*association*) ve parça-bütün (*aggregation/composition*)** ilişkileri **nesne düzeyindedir** ve çalışma zamanında (*runtime*) dinamik olarak değiştirilebilir:
>    - 1. Tasarımda her dergi için yalnızca **tek bir `Süreli Yayın` nesnesi** oluşturulur.
>    - Derginin elektronik aboneliği yoksa `- e_dergi : ElektronikDergi` üye alanı `null` değerini alır (çokluk: `0..1`); elektronik abonelik varsa `1` adet `ElektronikDergi` nesnesine işaret eder.
>    - Derginin basılı aboneliği varsa gelen her sayı için `Sayı` nesnesi oluşturulup `- sayılar[] : Sayı` listesine (`<>--- *`) eklenir (sayı yırtılır veya kaybolursa listeden silinir); yalnızca elektronik abonelikse `sayılar[]` dizisi boş kalır.
>    Bu nedenle deneyimli tasarımcılar kalıtım yerine parça-bütün ve sahiplik ilişkisiyle çözülebilen durumlarda her zaman **1. Tasarımı** tercih ederler (ekrandan, 02:35:00).

## Örnek Sorular

### Soru 1: Süreli Yayın Yönetim Yazılımı — Kullanım Senaryosu, Use Case Şeması ve Alan Modeli (Ekrandan, 00:30:00 – 02:35:00)

**Soru (1. Vize Uygulama Sorusu Prova Çalışması):** Bölüm 1'de gereksinimleri verilen **Süreli Yayın Yönetim Yazılımı** için:
1. **(a)** Kütüphaneye yeni gelen süreli yayınlar ile ilişkili **Kullanım Senaryosu Metnini** (*Giriş, Ana Senaryo, Alternatif Senaryolar* bölümleriyle) yazınız.
2. **(b)** Problemin **Alan Modelini** (metotsuz UML Sınıf Şemasını) kalıtım kullanmadan (sahiplik ve parça-bütün ilişkileriyle) çiziniz ve kalıtımlı tasarımlara göre neden daha avantajlı olduğunu açıklayınız.
3. **(c)** Sistemin **UML Kullanım Şemasını (*Use Case Diagram*)** (`<<include>>` ve `<<extend>>` ilişkilerini doğru yönleriyle kullanarak) çiziniz.

**Cevap (derste verildi):**
1. **(a) Kullanım Senaryosu Metni:** Bölüm 2.2'de tam metni verilen **Yeni Sayı Girişi (*Check-in*)** kullanım senaryosudur (Birincil aktör: `Kütüphaneci`; Ön koşul: `Kütüphaneci sisteme girmiştir`; Son koşul: `Süreli yayın ve sayı kayıtları sisteme girilmiş ve/veya güncellenmiştir`; Ana senaryo: `1..5` adımlarıyla mevcut derginin ISSN ile bulunup basılı sayı kutucuklarının ve elektronik `URL/backfile` bilgilerinin gösterilip güncellenmesi; Alternatif senaryolar: `1a. Yeni abonelik` ve `3a. Önceki yıla ait bir sayının işlemini yapmak ister`) (ekrandan, 01:01:00; ekrandan, 01:04:00).
2. **(b) Alan Modeli (1. Tercih — Kalıtımsız Sınıf Şeması):** Bölüm 4.2'deki 1. Tasarım şemasıdır (ekrandan, 02:35:00):
   - `Süreli Yayın` sınıfı: `- isim, ISSN : String`, `- periyot : int`, `- sayılar[] : Sayı`, `- e_dergi : ElektronikDergi`.
   - `Sayı` sınıfı: `- sayiNo, yil : int`, `- durum : String` (`Süreli Yayın <>--- (*) Sayı` parça-bütün ilişkisi).
   - `ElektronikDergi` sınıfı: `- URL : String`, `- backfile : int` (`Süreli Yayın (1) ---> (0..1) ElektronikDergi` sahiplik ilişkisi).
   - *Avantajı:* Kalıtım sınıf düzeyinde statik bir ilişki iken sahiplik/parça-bütün nesne düzeyinde dinamik bir ilişkidir; hem basılı hem elektronik abonelikte aynı ISSN'li iki ayrı nesne oluşturup `instanceof` kontrolü yapma zorunluluğunu ve yalnızca elektronik abonelikte kullanılmayan dizi miras alma kusurunu ortadan kaldırır.
3. **(c) UML Kullanım Şeması:** Bölüm 3.2'de çizilen şemadır (ekrandan, 01:48:00; ekrandan, 01:58:00): `Kütüphaneci` aktörü `Yeni Sayı Gelişi` ve `Yeni Abonelik` ile etkileşir; `Yeni Sayı Gelişi ----<<include>>---> Sayı Kutucukları Çizimi (Check-in Kartı Gösterimi)`; buna karşılık `Yeni Abonelik`, `Önceki Yıla Ait Sayının İşlenmesi`, `Basılı Abonelik`, `Elektronik Abonelik` ve `Check-in Kartı Düzenlemesi` senaryoları ilgili ana senaryolara **`<<extend>>`** okuyla bağlanır.

## Dersin Toparlaması

Bu uygulama dersinde, birinci vize sınavının 50 puanlık uygulama bölümüne hazırlık amacıyla **Süreli Yayın Yönetim Yazılımı** problemi üzerinde nesneye yönelik çözümleme (*analiz*) adımları uçtan uca uygulanmıştır. İlk aşamada doğal dildeki gereksinimlerden **Kullanım Senaryosu Metni** yazılmış; giriş bölümünde "joker" ön koşul kullanımı (`sisteme login olma`), son koşullarda tamamlanmış zaman kipi, ana senaryo ile alternatif senaryo (`1a`, `3a`) ayrımı ve problem alanı terminolojisine (`ISSN`, `sayı`, `periyot`, `backfile`, `check-in kartı`) sadık kalmanın önemi öğrenci çözümleri üzerinde gösterilmiştir.

İkinci aşamada **UML Kullanım Şeması (*Use Case Diagram*)** çizilmiş; 1–2 adımlık atomik işlemlerin ayrı birer *use case* yapılmaması (uygun kırılım düzeyi) ve *"basılı aboneliği varsa / elektronik aboneliği varsa"* gibi koşullu durumların `<<include>>` değil **`<<extend>>`** ile modellenmesi gerektiği vurgulanmıştır. Son aşamada ise problemin **Alan Modeli (metotsuz UML Sınıf Şeması)** için üç farklı tasarım (kalıtımsız parça-bütün/sahiplik tasarımı, soyut üst sınıflı iki alt sınıf kalıtımı ve tek alt sınıflı kalıtım) karşılaştırılmış; sınıf düzeyinde katı bir bağ kuran kalıtım yerine nesne düzeyinde çalışma zamanı esnekliği sağlayan **parça-bütün ve sahiplik odaklı tasarımın (1. Tasarım)** neden en iyi mühendislik tercihi olduğu kanıtlanmıştır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
