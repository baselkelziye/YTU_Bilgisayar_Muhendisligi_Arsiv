# Ders 7 Çalışma Özeti

## Genel Konular

- Nesneye Yönelik Çözümleme Uygulaması: Süreli Yayın Yönetim Yazılımı Problemi
  - Doğal dille tanımlanmış bir kütüphane **Süreli Yayın Yönetim Yazılımı** senaryosu üzerinden üç temel çözümleme yapıtının üretilmesi: 1) **Kullanım Senaryosu Metni (*Use Case*)**, 2) **UML Kullanım Şeması (*Use Case Diagram*)**, 3) **Alan Modeli (*Domain Model* — Metotsuz UML Sınıf Şeması)** (ekrandan, 00:30:00).
  - Problem alanı kuralları:
    - Süreli yayınların (dergilerin) aylık, üç aylık veya dört aylık periyotlarla yayımlanması, her derginin bir yayın adı ve 8 karakterli tekil bir **ISSN** numarası (ilk 7 karakteri `0-9` arası rakam, 8. kontrol karakteri `0-9` veya `10` değerini simgeleyen `X`; ör. *Nature* dergisi için `09534563`) taşıması (ekrandan, 00:30:00).
    - Aboneliklerin **yalnızca basılı**, **yalnızca elektronik** veya **hem basılı hem elektronik** olabilmesi; elektronik yayınlar için tek bir erişim adresi (`URL`) ve geriye dönük kaç yıllık arşive erişilebildiği (`backfile`, sınır yoksa `0`) bilgisinin tutulması; basılı yayınlar için ise her sayının `yıl`, `sayı` ve `durum` (`Geldi` veya `Bekleniyor`) bilgilerini içeren kutucuklar (**check-in kartı**) hâlinde gösterilmesi ve kütüphanecinin kutucuğa tıklayarak durumu güncelleyebilmesi (ekrandan, 00:30:00).
- Kullanım Senaryosu (*Use Case*) Metni Tasarımı ve Öğrenci Çözümlerinin Değerlendirilmesi
  - **Yeni Sayı Girişi (*Check-in*)** kullanım senaryosunun üç ana bölümle kurgulanması (ekrandan, 01:01:00; ekrandan, 01:04:00):
    1. **Giriş Bölümü:** *Birincil Aktör* (`Kütüphaneci`), *Diğer İlgililer* (`Yok` veya teslimat belgesi onayı isteyen `Kurye`), *İlgi Alanları* (kütüphanecinin yeni ve eski her dergi sayısını hatasız işlemek istemesi), *Ön Koşullar* (her zaman geçerli "joker" ön koşul olarak kütüphanecinin sisteme giriş [*login*] yapmış olması) ve *Son Koşullar* (süreli yayın ve sayı kayıtlarının sisteme girilmiş ve/veya güncellenmiş olması — tamamlanmış iş kipinde) (ekrandan, 00:56:00; ekrandan, 01:01:00).
    2. **Ana Senaryo (`1..5`):** Kütüphanelerde mevcut aboneliklere yeni sayı gelmesi sıfırdan yeni dergi aboneliği açılmasından çok daha sık gerçekleştiği için **kayıtlı bir derginin yeni sayısının işlenmesinin** ana senaryo olarak seçilmesi (1. ISSN girişi, 2. Basılı abonelikte ad/ISSN/periyot gösterimi, 3. Bu yıla ait sayı kutucuklarının mevcut durumlarıyla ve gelecek sayıların `Bekleniyor` olarak çizilmesi, 4. Elektronik abonelik varsa `URL` ve `backfile` gösterimi, 5. Kütüphanecinin bilgileri güncelleyip onaylaması) (ekrandan, 01:01:00).
    3. **Alternatif Senaryolar (`1a`, `3a`):** Ana senaryodaki `if-else` dallanmalarının `else` kollarının alternatif senaryoya taşınması: **`1a. Yeni abonelik`** (1. adımda girilen ISSN sistemde bulunamadığında yeni abonelik oluşturulması, ad/ISSN/periyot, elektronikse `URL`/`backfile`, basılıysa `yıl`/`sayı` alınması ve durumun `Geldi` yapılması) ve **`3a. Önceki yıla ait sayı işlemi`** (3. adımda bu yıl yerine geçmiş bir yılın kutucuklarının istenmesi) (ekrandan, 01:04:00).
- UML Kullanım Şeması (*Use Case Diagram*) Tasarımı ve Granülerlik (Kırılım) İlkeleri
  - Kullanım şemasında **aşırı ince kırılımdan kaçınma**: tek bir veri alanı girmek (`URL belirlenmesi`, `Backfile belirlenmesi`, `Durumun geldi yapılması`) gibi 1–2 adımlık atomik işlemlerin ayrı birer *use case* elipsi yapılmaması; her *use case* elipsinin kendi içinde anlamlı bir adımlar bütününe karşılık gelmesi gerektiği (ekrandan, 01:33:00).
  - **`<<extend>>` ve `<<include>>` ayrımları:** Bir dergiye yalnızca basılı, yalnızca elektronik veya her ikisi birden abone olunabildiği için (`varsa` koşulu), `Basılı Abonelik` ve `Elektronik Abonelik` senaryolarının `Yeni Abonelik` (veya `Yeni Sayı Gelişi`) senaryosuna `<<include>>` ile değil, **`<<extend>>`** ile bağlanması; `Yeni Abonelik` ve `Önceki Yıla Ait Sayının İşlenmesi` alternatiflerinin de `Yeni Sayı Gelişi`'ne **`<<extend>>`** ile bağlanması; buna karşılık her yeni sayı gelişinde zorunlu olan **`Sayı Kutucukları Çizimi (Check-in Kartı Gösterimi)`** işlevinin **`<<include>>`** ile bağlanması (ekrandan, 01:48:00; ekrandan, 01:58:00; ekrandan, 02:00:00).
  - İkinci bir aktör (`Okuyucu`) eklendiğinde, `Check-in Kartı Gösterimi`nin hem `Kütüphaneci` hem `Okuyucu` tarafından kullanılması, ancak kart üzerindeki durumu değiştirme (`Check-in Kartı Düzenlemesi`) işlevinin `Check-in Kartı Gösterimi`ne **`<<extend>>`** olarak bağlanması (ekrandan, 01:58:00).
- Alan Modeli (*Domain Model*) Alternatifleri: Sahiplik/Parça-Bütün vs. Kalıtım Karşılaştırması
  - Problem alanındaki varlıkların (`SüreliYayın`, `Sayı` / `BasılıSayı`, `ElektronikDergi`) üç farklı UML Sınıf Şeması ile modellenmesi ve nesneye yönelik tasarım kalitesi açısından sıralanması (ekrandan, 02:35:00):
    1. **1. Tercih — Kalıtımsız (Sahiplik ve Parça-Bütün Odaklı) Tasarım:** `SüreliYayın` sınıfının `- isim, ISSN: String`, `- periyot: int`, `- sayılar[]: Sayı` ve `- e_dergi: ElektronikDergi` alanlarını tutması; `Sayı` (`- sayiNo, yil: int`, `- durum: String`) ile parça-bütün (`<>--- *`), `ElektronikDergi` (`- URL: String`, `- backfile: int`) ile `1`'e `0..1` sahiplik ilişkisi kurması (ekrandan, 02:35:00).
    2. **2. Tercih — Soyut Üst Sınıf ve İki Alt Sınıflı Kalıtım Tasarımı:** `«abstract» SüreliYayın` (`- isim, ISSN: String`, `- periyot: int`) üst sınıfından `BasılıSayı` ve `ElektronikDergi` alt sınıflarının türetilmesi (veya `Basılı` alt sınıfının `Sayı` nesnelerini barındırması) (ekrandan, 02:30:00; ekrandan, 02:35:00).
    3. **3. Tercih — Tek Alt Sınıflı Kalıtım Tasarımı:** `SüreliYayın` üst sınıfının doğrudan basılı dergiyi (`- sayılar[]: Sayı`) temsil etmesi ve `ElektronikDergi`nin onun alt sınıfı olması (yalnızca elektronik olan aboneliklerde üst sınıftan miras alınan `sayılar[]` dizisi hiç kullanılmayacağı için tasarım kusuru oluşturur) (ekrandan, 02:35:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Kullanım Senaryosu Metni ile UML Kullanım Şeması Arasındaki Çapraz Tutarlılık
  - Kullanım senaryosu (*use case*) metninin **Ana Senaryo** bölümündeki `if-else` koşullarının `else` dalları **Alternatif Senaryolar** bölümünü oluşturur; kullanım senaryosu metninde alternatif senaryo olarak yazılan (veya metinde *"basılı aboneliği varsa"*, *"elektronik aboneliği varsa"* şeklinde koşullu geçen) çok adımlı işlevler UML Kullanım Şemasında **`<<extend>>`** okuyla, ana senaryoda her seferinde zorunlu çalışan alt işlevler ise **`<<include>>`** okuyla gösterilmelidir (ekrandan, 01:48:00; ekrandan, 02:00:00).
  - Hiçbir `<<include>>` veya `<<extend>>` ilişkisi içermeyen, yalnızca aktör ve düz çizgilerden oluşan bir kullanım şeması eksik kabul edilir; öte yandan tek adımlık basit veri girişleri (ör. yalnız URL girmek veya yalnız `backfile` için `0` girmek) ayrı bir *use case* elipsi yapılmamalıdır (ekrandan, 01:33:00).
- Alan Modelinde (UML Sınıf Şemasında) Kapsülleme (`-`) ve Çokluk Gösterimi
  - Sınıf şemasında veri gizleme (*encapsulation*) ilkesi gereği tüm üye alanların başına **`-` (*private*)** erişim belirleyicisi konulmalı, düz sahiplik oklarında ok ucu ve her iki uçtaki **çokluk (*multiplicity*: `1`, `0..1`, `*`, `1..*`)** değerleri açıkça yazılmalıdır (ekrandan, 02:30:00; ekrandan, 02:35:00).
- Kalıtım (*Inheritance*) Yerine Sahiplik/Parça-Bütün (*Composition/Aggregation*) Tercihi
  - **Kalıtım**, derleme zamanında **sınıf düzeyinde** tanımlanan ağır sıklet (*heavyweight*) ve katı bir ilişkidir; bir dergiye hem basılı hem elektronik abone olunduğunda kalıtım kullanan tasarımda aynı ISSN'e sahip iki ayrı nesne (`Basılı` ve `Elektronik`) oluşturmak ve ekleme metodunda `instanceof` / *type casting* ile tip kontrolü yapmak gerekir.
  - Buna karşılık **parça-bütün ve sahiplik ilişkileri nesne düzeyindedir** ve çalışma zamanında (*runtime*) esnekçe değiştirilebilir: derginin elektronik aboneliği yoksa `e_dergi` referansı `null` yapılır (`0..1`), elektronik abonelik eklendiğinde nesne bağlanır; yeni basılı sayı geldikçe `sayılar[]` listesine eklenir. Bu nedenle deneyimli tasarımcılar kalıtım yerine mümkün olduğunca parça-bütün/sahiplik ilişkisini (1. Tasarım) tercih ederler (ekrandan, 02:35:00).

## Kısa Tekrar Notları

- **ISSN (*International Standard Serial Number*) yapısı:** 8 karakterli `String` (ilk 7 karakteri `0-9` rakam, 8. karakteri mod 11 üzerinden hesaplanan kontrol basamağı [*checksum digit*]: `0-9` veya `10` yerine `X` karakteri) (ekrandan, 00:30:00).
- **Backfile:** Elektronik bir derginin geriye dönük kaç yıllık sayılarına erişim hakkı olduğunu gösteren tam sayı (`int`; sınırsız erişim varsa `0` tutulur) (ekrandan, 00:30:00; ekrandan, 02:35:00).
- **Check-in kartı:** Basılı süreli yayınların yıla ait sayılarının (`yıl`, `sayı`, `durum: Geldi / Bekleniyor`) kutucuklar hâlinde gösterildiği, kütüphanecinin tıklayarak durumu değiştirebildiği, okuyucuların ise salt okunur (*read-only*) görebildiği ekran (ekrandan, 00:30:00; ekrandan, 01:58:00).
- **Kullanım senaryosunda "Joker" ön koşul:** Metinde özel bir ön koşul belirtilmemişse *"Kullanıcı (kütüphaneci) sisteme giriş (login) yapmıştır"* ifadesi her zaman geçerli bir ön koşul olarak yazılabilir (ekrandan, 01:01:00).
- **Kütüphane terim uyarısı:** Süreli yayın senaryosunda yeni gelen materyal için *"kitap"* (ISBN) veya *"periyot"* değil, **"süreli yayın / dergi"** (ISSN) ve **"sayı"** terimleri kullanılmalıdır (`periyot`, derginin kaç ayda bir çıktığını gösteren tam sayıdır) (ekrandan, 00:56:00; ekrandan, 01:33:00).
- **Alan Modelinde 3 Tasarım Alternatifinin Sıralaması (ekrandan, 02:35:00):**
  1. **En İyi (1. Tercih):** Kalıtımsız tasarım (`SüreliYayın` $\rightarrow$ `0..1 ElektronikDergi` ve `<>--- * Sayı`).
  2. **2. Tercih:** Soyut üst sınıflı kalıtım (`«abstract» SüreliYayın` $\leftarrow$ `BasılıSayı` / `Basılı` ve `ElektronikDergi`).
  3. **3. Tercih (Kusurlu):** Tek alt sınıflı kalıtım (`SüreliYayın` içinde `sayılar[]: Sayı` tutulup `ElektronikDergi`'nin alt sınıf yapılması — yalnızca elektronik abonelikte `sayılar[]` dizisi miras alınıp boş kalır).

## Detaylı Açıklamalar

### 1. Süreli Yayın Yönetim Yazılımı Gereksinimleri ve Kullanım Senaryosu Metni

Uygulama çalışmasında ele alınan **Süreli Yayın Yönetim Yazılımı** probleminde (ekrandan, 00:30:00):
- Kütüphanenin abone olduğu süreli yayınlar (dergiler) aylık, 3 aylık, 4 aylık gibi belirli periyotlarla (`periyot: int`) yayımlanır ve her derginin bir yayın adı (`isim: String`) ile 8 karakterlik bir **ISSN** numarası (`ISSN: String` — ilk 7 karakter `0-9`, son karakter mod 11 kontrol basamağı olarak `0-9` veya `X`) vardır.
- Dergilere **yalnızca basılı**, **yalnızca elektronik** veya **hem basılı hem elektronik** olarak abone olunabilir. Elektronik yayınlar için tüm sayılara erişilen tek bir `URL` ve geriye dönük kaç yıllık arşive erişilebildiğini belirten `backfile` (sınırsızsa `0`) saklanır. Basılı yayınlar için ise her sayının `yıl`, `sayı` ve `durum` (`Geldi` veya `Bekleniyor`) bilgileri kutucuklar (**check-in kartı**) içinde gösterilir; gelecek sayıların durumu sistem tarafından tarihe ve periyoda göre `Bekleniyor` olarak belirlenir, sayı ulaştığında kütüphaneci kutucuğa tıklayarak durumu `Geldi` yapar.
- Gelen bir dergi sayısının sistemde kaydı yoksa kütüphaneci önce derginin ISSN, ad ve periyot bilgilerini, ardından abonelik türüne göre basılı ve/veya elektronik bilgilerini girerek yeni kayıt oluşturur ve sayıyı `Geldi` olarak işler (ekrandan, 00:30:00).

**A Şıkkı Çözümü — Kullanım Senaryosu: Yeni Sayı Girişi (*Check-in*) (ekrandan, 01:01:00; ekrandan, 01:04:00):**
- **Birincil Aktör:** Kütüphaneci.
- **Diğer İlgililer:** Yok (veya dergiyi teslim edip alındı kaşesi bekleyen *Kurye* eklenebilir).
- **İlgi Alanları:** Kütüphaneci, yeni ve eski her dergi sayısının bilgilerini doğru olarak işleyebilmeyi ister.
- **Ön Koşullar:** Kütüphaneci sisteme girmiştir (*login* olmuştur).
- **Son Koşullar:** Süreli yayın ve sayı kayıtları sisteme girilmiş ve/veya güncellenmiştir.
- **Ana Senaryo (Mevcut Abonelik İçin Sayı Girişi):**
  1. Kütüphaneci kütüphaneye yeni gelen derginin ISSN'ini girer.
  2. Derginin basılı aboneliği varsa; ad, ISSN ve periyot bilgileri gösterilir.
  3. Derginin basılı aboneliği varsa, bu yıla ait sayıları kutucuklar şeklinde gösterilir. Mevcut sayıların durumu sistemden elde edilir, gelecek sayıların durumu `'Bekleniyor'` olarak gösterilir.
  4. Derginin elektronik aboneliği varsa, `URL` ve `backfile` bilgileri de gösterilir.
  5. Kütüphaneci ekranda sunulan tüm bilgileri gereken şekilde günceller ve onay düğmesine basar.
- **Alternatif Senaryolar (ekrandan, 01:04:00):**
  - **1a.** Yeni abonelik (1. adımda girilen ISSN sistemde bulunamadığında):
    1. Sistem derginin ISSN'ini bulamamıştır, kütüphaneciye yeni abonelik oluşturmayı önerir.
    2. Kütüphaneci öneriyi onaylarsa sistem kütüphaneciden derginin adını, ISSN'ini ve periyodunu alır.
    3. Derginin elektronik aboneliği varsa `URL` ve `backfile` bilgileri kütüphaneciden alınır.
    4. Derginin basılı aboneliği varsa `yıl` ve `sayı` bilgileri kütüphaneciden alınır.
    5. Sistem girilen sayının durumunu `'Geldi'` olarak atar.
  - **3a.** Kütüphaneci önceki yıla ait bir sayının işlemini yapmak ister (ör. gecikmeli gelen geçmiş yıl sayısı veya stajyer hatasının düzeltilmesi):
    1. Kütüphaneci görmek istediği yılı belirtir.
    2. Sistem girilen yılın kutucuklarını çizerek sayıların durumlarını veritabanından alır.

### 2. UML Kullanım Şeması (Use Case Diagram) Çözümleri

Hoca hem canlı yayında *Violet UML* üzerinde doğaçlama çizdiği şemayı hem de çözüm belgesindeki şemaları karşılaştırarak şu ilkeleri açıklamıştır (ekrandan, 01:48:00; ekrandan, 01:58:00; ekrandan, 02:00:00):

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
   +--------- |  Check-in Kartı         | ------------- /|\
              |  Gösterimi              |               / \
              | (Sayı Kutucukları Çiz.) |             Okuyucu
              '-------------------------'
                           ^
                           | <<extend>>
              .-------------------------.
              |  Check-in Kartı         |
              |  Düzenlemesi            |
              '-------------------------'
```

- **Neden `Basılı` ve `Elektronik` Abonelik `<<include>>` Değil `<<extend>>` Olmalıdır?** Gereksinim metninde *"basılı aboneliği varsa"*, *"elektronik aboneliği varsa"* ifadeleri geçmektedir; yani bir dergiye yalnızca basılı, yalnızca elektronik veya her ikisi şeklinde 3 farklı biçimde abone olunabilir. Bu yüzden `Yeni sayı gelişi`nden `Basılı` ve `Elektronik` use case'lerine `<<include>>` çizmek kütüphanecilik kurallarına göre yanlıştır; bunlar koşullu varyasyon olduğu için `Abonelik` (veya `Yeni sayı gelişi`) use case'ine **`<<extend>>`** ile bağlanmalıdır (ekrandan, 01:48:00; ekrandan, 02:00:00).
- **Ek Paragraf (`Check-in Kartı` ve `Okuyucu` Aktörü) (ekrandan, 01:58:00):** Gereksinimlere *"Kütüphanecinin içerisine tıklayarak değiştirebileceği, okuyucuların ise değiştiremeden sadece içeriğini görebilme yetkisine sahip olduğu ekrana derginin check-in kartı denilir"* paragrafı eklendiğinde; `Yeni sayı gelişi` her seferinde **`Check-in kartı gösterimi`**ni içerir (`<<include>>`), `Okuyucu` aktörü yalnızca `Check-in kartı gösterimi` ile etkileşir, kütüphanecinin kutucuklara tıklayarak durumu değiştirmesi ise her görüntülemede yapılmadığı için `Check-in kartı düzenlemesi ----<<extend>>---> Check-in kartı gösterimi` olarak modellenir (ekrandan, 01:58:00).

### 3. Alan Modeli (Metotsuz UML Sınıf Şemaları) ve 3 Tasarım Alternatifi

Gereksinim metnindeki ve kullanım senaryosundaki isimler incelendiğinde üç temel varlık/kavram öne çıkar: **Süreli Yayın**, **Basılı Sayı (Sayı)** ve **Elektronik Dergi**. Çözüm belgesinde bu varlıkları modelleyen **üç farklı Alan Modeli (metotsuz UML sınıf şeması)** karşılaştırılmıştır (ekrandan, 02:35:00):

```text
================================================================================
1. TASARIM (HOCANIN 1. TERCİHİ: KALITIMSIZ — SAHİPLİK VE PARÇA-BÜTÜN İLİŞKİLİ)
================================================================================
+--------------------+          +-------------------------------+
|        Sayı        | *        |         Süreli Yayın          |
+--------------------+---------<>-------------------------------+
| - sayiNo, yil: int |          | - isim, ISSN : String         |
| - durum : String   |          | - periyot : int               |
+--------------------+          | - sayılar[] : Sayı            |
                                | - e_dergi : ElektronikDergi   |
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
2. TASARIM (HOCANIN 2. TERCİHİ: SOYUT ÜST SINIF VE İKİ ALT SINIFLI KALITIM)
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
  (Alternatif: Basılı alt sınıfı <>--- (1..*) Sayı parça-bütün ilişkisi kurar)

================================================================================
3. TASARIM (HOCANIN 3. TERCİHİ: TEK ALT SINIFLI KALITIM — KUSURLU)
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

**Üç Tasarımın Nesneye Yönelik Karşılaştırması (ekrandan, 02:30:00; ekrandan, 02:35:00):**
1. **Neden 3. Tasarım En Zayıftır?** 3. Tasarımda `Süreli Yayın` üst sınıfı basılı dergiyi temsil etmekte ve içinde `- sayılar[]: Sayı` dizisini barındırmaktadır; `ElektronikDergi` ise ondan kalıtımla türetilmiştir. Dergi yalnızca basılı olduğunda (`Süreli Yayın` nesnesi) veya hem basılı hem elektronik olduğunda (`ElektronikDergi` nesnesi) sorun çıkmaz; ancak dergi **yalnızca elektronik** olduğunda, oluşturulan `ElektronikDergi` nesnesi üst sınıftan hiç kullanmayacağı `- sayılar[]: Sayı` dizisini miras alır. Bir alt sınıfa hiç kullanmayacağı üye alanların kalıtımla geçmesi nesneye yönelik tasarımda önemli bir **kusurdur**.
2. **2. Tasarımın Özellikleri ve `instanceof` Zorluğu:** 2. Tasarımda ortak alanlar (`isim, ISSN, periyot`) soyut **`«abstract» Süreli Yayın`** üst sınıfına çekilmiş, basılı ve elektronik özellikler iki ayrı alt sınıfa (`Basılı` / `BasılıSayı` ve `ElektronikDergi`) ayrılmıştır. Böylece bütün yayınlar çok biçimlilik (*polymorphism*) sayesinde tek bir `SüreliYayın[]` listesinde tutulabilir ve örneğin `ekBilgiGöster()` gibi ortak bir soyut metot tanımlanarak basılı dergide check-in kartı, elektronik dergide `URL/backfile` gösterilebilir. Ancak bir dergiye **hem basılı hem elektronik** abone olunduğunda, aynı ISSN'e sahip bir `Basılı` nesnesi ve bir `ElektronikDergi` nesnesi (toplam 2 nesne) oluşturmak gerekir; yeni yayın eklerken de aynı ISSN kontrolünde doğrudan reddetmeyip `instanceof` (*type casting*) ile mevcut nesnenin elektronik mi basılı mı olduğunu denetleyen karmaşık kodlar yazmak gerekir.
3. **Neden 1. Tasarım (Kalıtımsız Tasarım) En İyisidir?** Kalıtım **sınıf düzeyinde** tanımlanan ağır sıklet (*heavyweight*) ve statik bir ilişkidir; oysa parça-bütün (`<>`) ve sahiplik (`--->`) ilişkileri **nesne düzeyindedir** ve çalışma zamanında (*runtime*) dinamik olarak değiştirilebilir. 1. Tasarımda her dergi için tek bir `Süreli Yayın` nesnesi vardır:
   - Derginin elektronik aboneliği yoksa `- e_dergi` referansı `null` olur (`0..1`); sonradan elektronik abonelik alınırsa çalışma zamanında bir `ElektronikDergi` nesnesi oluşturulup `e_dergi` alanına bağlanır.
   - Derginin basılı aboneliği varsa yeni sayılar geldikçe `Sayı` nesneleri `- sayılar[]` listesine eklenir (yırtılan/kaybolan sayı olursa listeden silinir); basılı abonelik yoksa `sayılar[]` boş kalır.
   Bu esneklik nedeniyle deneyimli yazılım tasarımcıları kalıtım yerine parça-bütün ve sahiplik ilişkilerini kullanan **1. Tasarımı** tercih ederler (ekrandan, 02:35:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
