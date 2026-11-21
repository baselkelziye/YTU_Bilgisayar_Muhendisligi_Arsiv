# Ders 9 Genişletilmiş Notu: NextGenPOS Tasarım Modeli (Durum, Tasarım Sınıf ve Sıralama Şemaları) ve Yazılım Ölçütlerine Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. NextGenPOS Kasa Varlığı İçin UML Durum Şeması (State Diagram) Tasarımı
- 2. Alan Modelinden Tasarım Sınıf Şemasına (Design Class Diagram) ve Sıralama Şemalarına Geçiş
- 3. Yazılım Kalitesi ve Yazılım Ölçütlerine (Software Metrics) Giriş
- Örnek Sorular
- Dersin Toparlaması

## 1. NextGenPOS Kasa Varlığı İçin UML Durum Şeması (State Diagram) Tasarımı

Önceki derslerde *NextGenPOS* yazar kasa senaryosunun kullanım senaryosu (*use case*) metni, etkinlik şeması (*activity diagram*) ve analiz aşamasındaki alan modeli (*domain model*) oluşturulmuştu. Bu dersin ilk bölümünde tasarım etkinliklerine devam edilerek sistemin **UML Durum Şeması (*State Diagram*)** çizilmiş, ardından alan modelinden **Tasarım Sınıf Şeması (*Design Class Diagram*)** ve **Sıralama Şemaları (*Sequence Diagrams*)** üretilmiştir.

### 1.1 Durum Şemasında Odak Varlığın, Durumların ve Olayların Belirlenmesi

Bir durum şeması çizerken izlenmesi gereken temel adımlar ve ilkeler şunlardır:
1. **Odak Varlığın Seçilmesi:** Durum şeması tüm sistem için soyut biçimde değil, uygulama mantığının üzerinde yoğunlaştığı belirli bir varlık (sınıf/nesne) için çizilir. *NextGenPOS* senaryosunda kasiyerin veya ürünlerin durum şemasını çizmenin fazla bir anlamı yoktur; uygulama mantığı ağırlıklı olarak **`Kasa`** üzerinde kodlandığı için durum şeması **`Kasa`** varlığı için çizilir.
2. **Önce Durumların (*States*), Sonra Olayların (*Events*) Tespit Edilmesi:** Uygulamada en sık yapılan hata, neyin **durum**, neyin **olay (geçiş)** olduğunun karıştırılmasıdır. Bu yüzden kullanım senaryosu metnindeki **ana öykü**, **alternatif akışlar** ve varsa **ön koşullar** okunarak önce varlığın içinde bulunabileceği durumlar belirlenmeli, ardından bu durumlar arasındaki geçişleri tetikleyen olaylar yerleştirilmelidir. Doğal dilde serbestçe yazılmış gereksinim maddeleri durum geçişlerini çıkarmak için pek elverişli değildir; bu iş için en verimli kaynak **kullanım senaryosu metnidir**.
3. **Karşılıklı Dışlamalı (*Mutually Exclusive*) Durumlar İlkesi:** Klasik programlarda iç içe (*nested*) veya kuantum fiziğindeki süperpozisyon gibi aynı anda birden fazla durumda bulunma hâli söz konusu değildir; bir varlık belirli bir anda **yalnızca tek bir durumda** bulunabilir.
4. **Durum Kavramının Pasif Bekleyişle Sınırlı Olmaması:** Bir varlığın belirli bir "durumda" olması, o varlığın hiçbir iş yapmadan pasif/edilgen biçimde beklediği anlamına gelmez. Hoca bunu günlük hayattan şu benzetmeyle açıklamıştır: Bir öğretmenin *"ders verme durumunda"* olması, 40–50 dakikalık ders süresi dolup mola vakti gelene (olay gerçekleşene) kadar aktif olarak ders anlatmayı sürdürmesi, mola ziliyle birlikte *"dinlenme durumuna"* geçmesi demektir. Dolayısıyla durumlar, **yeni bir olay gerçekleşmedikçe bölünmeyen bir etkinlik veya çalışma modu** olarak düşünülmelidir (örneğin kasanın `Satış kaydetme` durumunda yeni barkod girişini dinleyip kaydetmesi veya `Fiş verme` durumunda başka girdi kabul etmeyip makbuz basması).

### 1.2 Canlı Derste Çizilen Kasa Durum Şeması ve Tasarım Kararları

Hoca *Violet UML Editor* üzerinde kullanım senaryosu adımlarını (1'den 9'a kadar ana senaryo ve alternatif senaryolar) adım adım takip ederek `Kasa` için aşağıdaki durum şemasını oluşturmuştur (ekrandan, 00:30:00; ekrandan, 00:36:15):

```text
 (●) ── «M»Güç açıldı/ ──> [ Boşta bekleme ] ── «M»Kasiyer login/ ──> [ Satış bekleme ]
                                  │                                        │      ▲
                                  └── «M»Güç kapandı/ ──> (◉) <────────────┘      │
                                                   «M»Güç kapandı/                │
                                                                                  │ (otomatik)
                                                                                  │
                                             [ Satış bekleme ]                    │
                                                    │                             │
                                          «M»Satış başlatma/                      │
                                                    ▼                             │
                                            [ Satış kaydetme ] ──┐                │
                                              │     ▲      ▲     │ «M»Barkod      │
                   «M»Başka ürün kalmadı/     │     │      └─────┘    girişi/     │
                                              │     │                             │
                                              │     │ «M»Barkod                   │
                                              │     │    girişi/                  │
                                              │     │                             │
                                              │     └── [ Satıştan bir ]          │
                                              │         [  ürün silme  ]          │
                                              │                ▲                  │
                                              │                │ «M»Ürün iptal    │
                                              │                │ düğmesine basıldı/
                                              ▼                │
     [ Fiş verme ] <── (otomatik) ── [ Harici sistemlere ] <── [ Ödeme bekleme ]
           │                         [  bilgi aktarımı   ]     «M»Ödeme alındı
           └──────────────────────────────────────────────────────────────────────┘
```

Şemanın kuruluşundaki kritik noktalar şunlardır (ekrandan, 00:30:00; ekrandan, 00:36:15):
- **Violet UML'de `«M»` Stereotipi İpucu:** Durum şemasında olay geçişlerinde kullanılan `«M»` (mesaj/olay) stereotipindeki çift açılı tırnak (`«»`) karakterleri klavyede doğrudan bulunmadığından, boş bir sınıf şemasında geçici bir `«interface»` oluşturulup oradaki `«interface»` metni kopyalanarak durum şemasındaki ok etiketlerine yapıştırılabilir ve içerisi `«M»` olarak değiştirilebilir. Etiketlerin sonuna, ileride geçiş anında çalıştırılacak eylem/kod satırları eklenebilmesi için `/` işareti konulur.
- **Başlangıç, `Boşta bekleme` ve `Satış bekleme` Durumları:** Başlangıç düğümünden (`●`) ilk duruma geçişte bir olay yazılması zorunlu değildir (varlık oluşur oluşmaz ilk duruma otomatik geçebilir); ancak yazar kasanın güç düğmesine basılması mantıklı bir olay olduğundan geçişe `«M»Güç açıldı/` yazılmıştır. Kasa ilk açıldığında henüz kasiyer giriş yapmadığı için `Boşta bekleme` durumundadır; `«M»Kasiyer login/` olayı gerçekleştiğinde `Satış bekleme` durumuna geçer (ekrandan, 00:30:00).
- **`Satış kaydetme` ve Öz Geçiş (*Self-Transition*):** Kasiyer yeni bir satış başlattığında (`«M»Satış başlatma/`), kasa `Satış kaydetme` durumuna geçer. Kullanım senaryosunun 3. adımından 7. adımına (ödeme isteme adımına) kadar normal akışta her barkod okutulduğunda kasa yeni bir duruma geçmez; ürünü kaydedip yine `Satış kaydetme` durumunda kalır. Bu nedenle `Satış kaydetme` durumundan kendi kendisine dönen bir ok (**öz geçiş / *self-transition***) çizilir ve üzerine `«M»Barkod girişi/` yazılır (ekrandan, 00:30:00).
- **Alternatif Senaryo: `Satıştan bir ürün silme` Durumu ve Aynı Olay Adının Korunması:** Müşteri bir ürünü almaktan vazgeçtiğinde (`3-7a` alternatif akışı), kasiyerin okutacağı barkodun satışa eklenmek yerine satıştan düşülmesi için önce kasada bir iptal tuşuna basılması (veya yetkili kartı okutulması) gerekir.
  - Burada önemli bir tasarım kararı verilmelidir: *İptal tuşuna basıldığında kasa sürekli ürün silme modunda mı kalacak, yoksa tek bir ürün barkodu okutulur okutulmaz otomatik olarak tekrar `Satış kaydetme` moduna mı dönecek?* Kullanım senaryosunda her seferinde bir kalem malın çıkarılması öngörüldüğü için durumun adı **`Satıştan bir ürün silme`** olarak konulmuştur (ekrandan, 00:30:00).
  - `Satış kaydetme` durumundayken `«M»Ürün iptal düğmesine basıldı/` olayı gerçekleştiğinde kasa `Satıştan bir ürün silme` durumuna geçer. Ardından ürünün barkodu okutulduğunda (`«M»Barkod girişi/`), o ürün listeden silinir ve kasa doğrudan `Satış kaydetme` durumuna geri döner.

> **Hocanın vurgusu (Aynı Olay İçin Aynı İsim Kullanımı):**
> `Satış kaydetme` durumunun kendi üzerindeki `«M»Barkod girişi/` olayı ile `Satıştan bir ürün silme` durumundan `Satış kaydetme` durumuna geri dönen `«M»Barkod girişi/` olayı fiziksel olarak **tamamen aynı olaydır** (barkod okuyucudan barkod okutulması). Birine *"Barkod girişi"*, diğerine *"Barkod okutulması"* gibi farklı isimler verilmemelidir; ikisi aynı olay olduğu için aynı isimle yazılmalı, yalnızca **önceki durumları ve sonraki durumları farklı** olmalıdır (ekrandan, 00:30:00).

- **`Ödeme bekleme`, `Harici sistemlere bilgi aktarımı` ve `Fiş verme` (Otomatik Geçişler):** Alınacak başka ürün kalmadığında (`«M»Başka ürün kalmadı/`), kasa toplam tutarı şifre terminaline (*Pinpad* / POS cihazına) bildirir ve Pinpad'den ödeme onayı gelmesini beklediği **`Ödeme bekleme`** durumuna geçer. Ödeme başarıyla gerçekleştiğinde (`«M»Ödeme alındı`), kasa önce muhasebe ve stok sistemlerini bilgilendirdiği **`Harici sistemlere bilgi aktarımı`** durumuna, bu aktarım tamamlanır tamamlanmaz dışarıdan yeni bir olay beklemeden **otomatik olarak** (üzerinde etiket olmayan okla) **`Fiş verme`** durumuna, fiş basımı biter bitmez de yine **otomatik olarak** (kasiyer hâlâ *login* durumda olduğu için `Boşta bekleme`ye değil) **`Satış bekleme`** durumuna geri döner (ekrandan, 00:30:00).

### 1.3 Öğrenci Sorusu (Bitiş Durumu) ve Ders Notlarındaki Şema ile Karşılaştırma

Canlı çizim tamamlandıktan sonra bir öğrenci sohbet ekranından şemanın nerede sonlandığını sormuştur:

**Soru:** Senaryonun sonu (bitiş durumu) nerede oluyor?

**Cevap:** Çok yerinde bir soru; hiçbir sistem sonsuza kadar çalışmaz, gün sonunda kasiyer çıkış (*logoff*) yapar veya kasanın elektriği/güç düğmesi kapatılır. Kasa hem hiç *login* olunmamışken (`Boşta bekleme` durumundayken) hem de kasiyer *login* olmuş satış beklerken (`Satış bekleme` durumundayken) kapatılabilir. Bu nedenle her iki durumdan da **bitiş düğümüne (`◉` — *Scenario end*)** giden `«M»Güç kapandı/` geçişleri eklenmelidir (ekrandan, 00:30:00; ekrandan, 00:36:15).

Ardından hoca canlı çizilen şemayı kendi ders notlarındaki (Slayt 104) durum şemasıyla karşılaştırmıştır (ekrandan, 00:36:15):
1. **Koruma Koşulu (*Guard Condition*) Kullanımı (`[kasiyer login olmuş ise]`):** Ders notlarındaki şemada `Kasiyer login` ayrı bir durum olarak gösterilmemiş, yalnızca `Boşta bekleme` durumu kullanılmıştır (ekrandan, 00:36:15):
   - Başlangıç (`●`) $\xrightarrow{\text{Güç açıldı /}}$ `Boşta bekleme` $\xrightarrow{\text{«M» Satış başlatıldı /}}$ `Satış kaydetme`
   - `Boşta bekleme` $\xrightarrow{\text{«M» Kapatma düğmesine basıldı /}}$ Bitiş (`◉`)
   - Hoca, eğer `Satış bekleme` durumu ayrı çizilmeyecekse kullanım senaryosundaki *"Kasiyer sisteme giriş yapmıştır"* ön koşulunu sağlamak için `Boşta bekleme`den `Satış kaydetme`ye giden okun üzerine köşeli parantez içinde bir **koruma koşulu (*guard*)** eklenmesinin çok yararlı olacağını göstermiştir: **`«M»Satış başlatma [kasiyer login olmuş ise]/`** (ekrandan, 00:36:15).
2. **Durum Geçişlerinde Üye Alan Güncellemeleri (`/` Sonrası Eylemler):** Dersin ilerleyen kısmında tasarım sınıf şeması çizilirken `Kasa` sınıfına kasanın o anki durumunu takip etmek üzere `- bostaBekleme: boolean` ve `- satisBekleme: boolean` adında iki mantıksal (*boolean*) üye alan eklenmiştir. Hoca tekrar durum şemasına dönerek olay etiketlerindeki `/` işaretinin sağ tarafına bu bayrakları güncelleyen kodların yazıldığını göstermiştir:
   - `«M»Güç açıldı/` geçişinde: `bostaBekleme = true; satisBekleme = false;`
   - `«M»Kasiyer login/` geçişinde: `bostaBekleme = false; satisBekleme = true;`

## 2. Alan Modelinden Tasarım Sınıf Şemasına (Design Class Diagram) ve Sıralama Şemalarına Geçiş

Dersin ikinci ve üçüncü bölümlerinde, analiz aşamasında oluşturulan metotsuz **Alan Modeli (*Domain Model*)** alınarak, kullanım senaryosu metnindeki her bir eylemi gerçekleyecek metotlar, veri yapıları ve yardımcı sıralama şemaları (*sequence diagrams*) adım adım tasarlanmıştır.

### 2.1 `Kasa`, `Şube`, `Satış`, `SatışKalemi`, `Ürün` ve `Ödeme` Sınıflarının Zenginleştirilmesi

Hoca kullanım senaryosu adımlarını baştan sona tarayarak sınıfların üye alanlarını ve metotlarını şu tasarım kararlarıyla oluşturmuştur (ekrandan, 02:20:00; ekrandan, 02:21:35):

1. **`Kasa` Sınıfının Üye Alanları, Kurucusu ve `satışBaşlat()` Metodu:**
   - **Üye Alanlar ve Koleksiyon Seçimi (`LinkedList` vs. Dizi):** Analiz modelinde `Kasa` ile `Şube` arasında parça-bütün, `Kasa` ile `Satış` arasında ise `1`'e `*` (*kaydeder*) ilişkisi vardır. Kod aşamasına geçileceği için bu ilişkilerin sınıf içinde hangi üye alan adlarıyla ve hangi veri yapılarıyla tutulacağı açıkça yazılmalıdır:
     - Kasanın ait olduğu şubeyi bilmesi için: **`- şube : Şube`** (ve bunu ilkleyen kurucu metot: **`+ Kasa(Şube)`**).
     - Kasada gün içinde kaç satış yapılacağı önceden belli olmadığından ve belleği verimli kullanmak gerektiğinden sabit boyutlu dizi yerine jenerik bağlı liste tercih edilir: **`- satışlar : LinkedList<Satış>`** (ders notlarındaki şemada `Vector<Satis>` kullanılmıştır).
     - `satışBaşlat()` metodu içinde oluşturulan yeni `Satış` nesnesine daha sonra çağrılacak `barkodGir()`, `toplamBedelHesapla()` gibi metotlardan da erişilebilmesi için yerel değişken yetmez; o an yürütülen satışı tutan **`- mevcutSatış : Satış`** (ders notlarında `- sonSatis : Satis`) üye alanı eklenir (ekrandan, 02:20:00).
     - Kasanın durum şemasındaki modunu bilmesi için: **`- bostaBekleme : boolean`** ve **`- satisBekleme : boolean`**.
   - **`+ satışBaşlat() : boolean` Metodu:** Kullanım senaryosunun 1. adımı (*"Müşteri kasaya alacağı ürünlerle gelir"*) yazılımda bir metot çağrısına karşılık gelmez; 2. adım (*"Kasiyer yeni bir satış işlemi başlatır"*) ise `Kasa` sınıfındaki `+ satışBaşlat()` metoduyla gerçeklenir. Bu metodun parametre almasına gerek yoktur; ancak kasiyer henüz *login* olmamışsa veya hâlihazırda devam eden bir satış varken kasiyer yanlışlıkla yeni satış başlatma düğmesine dokunmuşsa mevcut satışı sıfırlamamak için işlemin başarılı olup olmadığını döndüren **`boolean`** dönüş tipine sahip olması gerekir (ekrandan, 02:20:00).

2. **Barkod Veri Tipi, `barkodGir()` Metotlarının Aşırı Yüklenmesi (*Overloading*) ve `uyarıVer()`:**
   - **Neden `barkod : String`?** Kullanım senaryosunun 3. adımında kasiyer ürünün barkodunu girer. Barkodlar çoğunlukla rakamlardan oluşsa bile kitapların ISBN numaralarında (veya dergilerin ISSN numaralarında) `X` karakteri bulunabileceği ya da bir barkodun **`0` rakamıyla başlayabileceği** (tam sayı `int` tipinde baştaki sıfır kaybolacağı) için barkod parametresi `int` değil **`String`** olarak tanımlanır: **`+ barkodGir(barkod : String) : boolean`** (ekrandan, 02:20:00).
   - **Çoklu Ürün Girişi İçin *Method Overloading*:** Müşteri aynı kalemden 3 adet aldığında kasiyer ya barkodu 3 kez art arda okutur (`barkodGir(barkod)` 3 kez çağrılır) ya da tuş takımından `3 x` tuşlayıp barkodu 1 kez okutur (adetli satış). Her iki durumu da desteklemek için `barkodGir` metodu aşırı yüklenir (*overloaded*):
     - **`+ barkodGir(barkod : String) : boolean`**
     - **`+ barkodGir(barkod : String, adet : int) : boolean`** (ekrandan, 02:20:00).
   - **Geçersiz Barkod (`3-4a` Alternatif Akışı) ve `Şube.ürünSorgula()`:** Girilen barkodun geçerli bir ürüne karşılık gelip gelmediğini anlamak için ürünlerin stoklandığı `Şube` sınıfına **`+ ürünSorgula(barkod : String) : Ürün`** metodu eklenir (bulunamazsa `null` döndürür). Ürün `null` dönerse kasanın bip sesi çıkarıp ekrana hata mesajı basması için `Kasa` sınıfına dışarıdan doğrudan çağrılmaması gereken özel (**`-` *private***) **`- uyarıVer()`** metodu eklenir ve `barkodGir` metodu `false` döndürür (ekrandan, 01:35:25; ekrandan, 02:20:00).

3. **Sorumluluk Atama: `SatışKalemi` Nesnesini `Kasa` mı Yoksa `Satış` mı Oluşturmalı?**
   - Kullanım senaryosunun 4. adımında *"Sistem yeni bir satış kalemi maddesi oluşturur"* denmektedir. Hoca önce *"Böl, parçala, yönet"* ilkesi gereği `barkodGir` metodunun aşırı uzamaması için alt adımların ayrı metotlara bölünmesi gerektiğini vurgulamış, ancak yeni bir satış kalemi oluşturmanın yalnızca `SatışKalemi` kurucusunu (`new SatışKalemi(ürün, adet)`) çağırmaktan ibaret olduğunu belirterek bunun hangi sınıfta yapılacağını tartışmıştır.
   - Satış kalemlerinin listesini (`- satışKalemleri : LinkedList<SatışKalemi>`) tutan sınıf **`Satış`** sınıfıdır. Dolayısıyla `Kasa` sınıfı `Şube`'den sorguladığı `ürün` nesnesini ve `adet` bilgisini `mevcutSatış` nesnesinin **`+ ürünEkle(ürün : Ürün, adet : int)`** metoduna devretmeli; `SatışKalemi` nesnesini oluşturup listeye ekleme sorumluluğu **`Satış`** sınıfında olmalıdır (ekrandan, 01:35:25; ekrandan, 02:20:00).

4. **Performans ve Tasarım Kararı: Aynı Ürünün Farklı Anlarda Tekrar Okutulması vs. Ürün Silme:**
   - Müşteri önce bir kalem, ardından silgi, sonra **aynı kalemden bir tane daha** aldığında iki tasarım seçeneği vardır:
     1. Her `barkodGir` çağrısında mevcut `satışKalemleri` listesini baştan sona tarayıp o ürün daha önce alınmışsa mevcut `SatışKalemi` nesnesinin miktarını `1` artırmak (`miktarArttır`).
     2. Listede arama yapmadan doğrudan yeni bir `SatışKalemi` nesnesi oluşturup listeye eklemek.
   - **Canlı Dersteki Performans Kararı:** Her barkod okutulduğunda mevcut satış kalemleri listesini baştan sona taramak yazar kasaya fazladan işlem yükü getireceği ve işi yavaşlatacağı için hoca canlı derste **2. seçeneği** tercih etmiştir: aynı ürün farklı zamanlarda iki kez ayrı ayrı okutulursa fişte iki ayrı `SatışKalemi` satırı olarak yer alır (ancak hoca ders notlarını hazırlarken 1. seçeneği de düşünerek `SatışKalemi` sınıfına `+ miktarArttır(int)` metodunu eklediğini, canlı dersteki karar doğrultusunda buna gerek olmadığını belirtmiştir) (ekrandan, 02:20:00).
   - **Alışverişten Ürün Çıkarma (`3-7a` Alternatif Akışı):** Buna karşılık müşteri sepetindeki bir ürünü (veya `2 x` olarak okutulmuş iki kalemden birini) **iptal etmek** istediğinde, o ürünün sepette gerçekten var olup olmadığını bulmak zorunludur. Bu amaçla:
     - `Satış` sınıfına **`+ ürünSil(ürün : Ürün)`** ve yardımcı arama metodu olarak **`- satışKalemiAra(ürün : Ürün) : SatışKalemi`** eklenir.
     - `SatışKalemi` sınıfına ise miktarı 1 azaltan **`+ ürünüBirEksilt()`** ile **`+ getÜrün() : Ürün`** ve **`+ getMiktar() : int`** (sıralama şemasında `getAdet()`) metotları eklenir (ekrandan, 01:49:35; ekrandan, 02:20:00).

> **Hocanın vurgusu (Kendi Kendini Belgeleyen Kod / Metot Adlandırma):**
> Hoca ilk başta metodu `ürünAzalt()` olarak adlandırıp yanına *"miktarı 1 azaltır (--)"* şeklinde bir UML not kutusu (*annotation*) eklemiş, ardından bir programcının sınıf şemasına baktığında metotların ne yaptığını anlamak için çok sayıda sıralama şeması veya not kutusu arasında kaybolmaması gerektiğini belirterek not kutusunu silmiş ve metodun adını doğrudan **`ürünüBirEksilt()`** yapmıştır. Metot adları mümkün olduğunca ne iş yaptığını kendi kendine açıklayan (*self-documenting*) biçimde seçilmelidir (ekrandan, 01:49:35).

   - **Adet Sıfırlanınca Kalemin Listeden Silinmesi:** Bir ürünün adedi `ürünüBirEksilt()` sonrasında `0`'a düşerse, fiş basılırken `0` adetli kalemlerin görünmemesi için o `SatışKalemi` nesnesi listeden tamamen çıkarılmalıdır. `SatışKalemi` sınıfından `Satış` sınıfına doğru ters yönde ok (referans) bulunmadığı için `SatışKalemi` kendi kendini listeden silemez; bu nedenle `Satış` nesnesi `kalem.getAdet()` (veya `getMiktar()`) ile kalan adedi kontrol eder ve **`[adet == 0]` ise kalemi kendi `satışKalemleri` listesinden siler** (ekrandan, 01:49:35).

5. **Toplam Bedel, KDV Hesaplama ve Fiş Gövde Metni Sorumluluğu:**
   - Kullanım senaryosunun 6. ve 7. adımlarında toplam bedelin KDV ile birlikte hesaplanması ve müşteriye bildirilmesi yer alır. Fiyatlar küsuratlı olabileceği için dönüş tipi `double` seçilir ve gerçek yazar kasa fişlerinde hem **Toplam KDV** hem **Genel Toplam** ayrı ayrı yazıldığı için hem `Kasa` hem `Satış` sınıflarına **`+ toplamBedelHesapla() : double`** ve **`+ toplamKDVHesapla() : double`** metotları; `SatışKalemi` sınıfına ise ara toplamları hesaplayan **`+ bedelHesapla() : double`** ve **`+ KDVHesapla() : double`** metotları eklenir (ekrandan, 02:20:00).
   - **Fiş Gövde Metninin Hazırlanması (`+ getFişGövdeMetni() : String`):** Fiş basılırken her bir satış kaleminin adını, adetini, birim fiyatını ve ara toplamını birleştirip metin hâline getirme sorumluluğu `Kasa` sınıfına verilmemelidir (`getKalemler()` ile `LinkedList<SatışKalemi>` listesini `Kasa`'ya döndürüp döngüyü `Kasa` içinde kurmak tasarım ilkelerine aykırıdır). **Sorumluluk, ilgili bilgiye en çok sahip olan sınıfa (`Satış`) verilmelidir**; bu nedenle `Satış` sınıfına **`+ getFişGövdeMetni() : String`** metodu eklenir (ekrandan, 02:21:35).
   - Son olarak `Kasa` sınıfına ödeme ve kapanış adımları için **`+ ödemeTahsili()`**, **`+ fişVer()`** ve dışarıdan zamansız çağrılmaması için *private* yapılan **`- satışBitir()`** metotları eklenir (ekrandan, 02:21:35).

### 2.2 Tamamlanmış Tasarım Sınıf Şeması ve Ders Notlarıyla Karşılaştırma

Canlı derste oluşturulan **Tasarım Sınıf Şeması (`tasMod.class.violet`)** aşağıdadır (ekrandan, 02:20:00; ekrandan, 02:21:35):

```text
+---------------------------------------+          +----------------------------------+
|             SatışKalemi               |          |               Ürün               |
+---------------------------------------+  içerir  +----------------------------------+
| - miktar : int                        | 1      1 | - tanim : String                 |
| - ürün : Ürün                         |--------->| - fiyat, kdv : double            |
+---------------------------------------+          | - barkod : String                |
| + SatışKalemi(ürün: Ürün, adet: int)  |          +----------------------------------+
| + getÜrün() : Ürün                    |          | Not: Tüm üyeleri alan constructor|
| + getMiktar() : int                   |          |      Tüm getter ve setter'lar    |
| + ürünüBirEksilt()                    |          +----------------------------------+
| + bedelHesapla() : double             |                           ^
| + KDVHesapla() : double               |                           | *
+---------------------------------------+                           | stoklanır
                   ^                                                | 1
                   | 1..*                          +----------------------------------+
                   |                               |               Şube               |
                   ◆ 1                             +----------------------------------+
+---------------------------------------+          | - ad, adres : String             |
|                 Satış                 |          +----------------------------------+
+---------------------------------------+          | + ürünSorgula(barkod:String):Ürün|
| - tarih : Date                        |          +----------------------------------+
| - satışKalemleri :                    |                           ◆ 1
|     LinkedList<SatışKalemi>           |                           |
| - ödeme : Ödeme                       |                           v
+---------------------------------------+          +----------------------------------+
| + Satış()                             | kaydeder |               Kasa               |
| + ürünEkle(ürün: Ürün, adet: int)     | *        +----------------------------------+
| + ürünSil(ürün: Ürün)                 |<---------| - şube : Şube                    |
| - satışKalemiAra(ürün:Ürün):          |          | - satışlar : LinkedList<Satış>   |
|     SatışKalemi                       |          | - mevcutSatış : Satış            |
| + toplamBedelHesapla() : double       |          | - bostaBekleme : boolean         |
| + toplamKDVHesapla() : double         |          | - satisBekleme : boolean         |
| + getFişGövdeMetni() : String         |          +----------------------------------+
+---------------------------------------+          | + Kasa(Şube)                     |
                   | 1                             | + satışBaşlat() : boolean        |
                   | içerir                        | + barkodGir(barkod:String):boolean|
                   v 1                             | + barkodGir(barkod:String,       |
+---------------------------------------+          |     adet:int) : boolean          |
|                 Ödeme                 |          | + toplamBedelHesapla() : double  |
+---------------------------------------+          | + toplamKDVHesapla() : double    |
| - miktar : double                     |          | - uyarıVer()                     |
+---------------------------------------+          | + ödemeTahsili()                 |
| + Ödeme(double)                       |          | + fişVer()                       |
| + getÖdeme() : double                 |          | - satışBitir()                   |
+---------------------------------------+          +----------------------------------+
```

> **Ders sonrası not:** Hoca canlı derste `SatışKalemi` sınıfına `+ getÜrün()` ve `+ getMiktar()` metotlarını peş peşe yazarken `+ getÜrün() : int` şeklinde yazım hatası yapmıştır (ekrandan, 02:20:00; ekrandan, 02:21:35); `ürün` üye alanı `Ürün` nesnesi olduğundan (ve hocanın sağ pencerede açtığı ders notu şemasında da görüldüğü üzere) dönüş tipi **`+ getÜrün() : Ürün`** olmalıdır.

**Ders Notlarındaki Şemada Yer Alan `Katalog` Sınıfı Farkı:**
Hoca ders notlarındaki sınıf şemasını açtığında, orada `Şube` ile `Ürün` arasına **`Katalog`** adında ek bir sınıf koyduğunu göstermiştir. Bunun gerekçesi **uyumu (*cohesion*) yükseltmektir**: Eğer `Şube` sınıfının personel yönetimi, kira, muhasebe gibi pek çok başka metodu olacaksa, ürün tanımlarını tutma ve barkodla ürün arama sorumluluğunu `Şube`'den ayırıp `Katalog` sınıfına (`Şube ◆── 1 Katalog ◆── * Ürün`, `Şube` ile `Ürün` arasında ise kesikli `<<kullanır>>` bağımlılık oku) vermek daha yüksek uyumlu bir tasarımdır; ancak `Şube` sınıfında başka metot yoksa doğrudan `Şube` üzerinde kalması da sorun oluşturmaz.

### 2.3 Üç Temel İşlem İçin UML Sıralama Şemaları (Sequence Diagrams)

Tasarım kararlarının yazılımcılar tarafından farklı yorumlanmasını önlemek amacıyla üç temel metodun nesneler arası etkileşimi **UML Sıralama Şeması (*Sequence Diagram*)** ile modellenmiştir:

#### 1. `barkodGir(barkod: String)` Sıralama Şeması (ekrandan, 01:35:25)

```text
  [ : ]                  [:Kasa]                  [şube : Şube]         [mevcutSatış]        [:SatışKalemi]
    │                       │                           │                     │                    │
    │── barkodGir(barkod:   │                           │                     │                    │
    │     String) ─────────>│                           │                     │                    │
    │                       │── ürünSorgula(barkod:     │                     │                    │
    │                       │     String) ─────────────>│                     │                    │
    │                       │< - - - - - ürün - - - - - │                     │                    │
    │                       │                           │                     │                    │
    │                       │──┐ [ürün == null]         │                     │                    │
    │                       │  │ uyarıVer();            │                     │                    │
    │                       │<─┘ return false;          │                     │                    │
    │                       │                           │                     │                    │
    │                       │── ürünEkle(ürün, 1) ───────────────────────────>│                    │
    │                       │                           │                     │── new(ürün, adet) >│
    │                       │                           │                     │< - - - - - - - - - │
    │                       │< - - - - - - - - - - - - - - - - - - - - - - - -│                    │
```

**Soru:** `SatışKalemi` nesnesi `new` ile oluşturulurken, nesne kutusunun yukarıda diğerleriyle aynı hizada başlamak yerine `new` okunun gittiği yerde (daha aşağıda) başlaması gerekmez mi?

**Cevap:** Evet, *Violet UML Editor*'de ok doğrudan yukarıdaki `:SatışKalemi` başlık kutusunun üzerine çekildiğinde araç bunu otomatik olarak `«create»` şeklinde aşağıya indirerek nesnenin yaşam çizgisinin o anda başladığını göstermeyi desteklemektedir. Hem yukarıda tutup `new(ürün, adet)` yazmak hem de doğrudan kutuya çekip `«create»` kullanmak sınavda ve projede kabul edilir.

#### 2. `ürünSil(ürün: Ürün)` Sıralama Şeması (ekrandan, 01:49:35)

```text
  [ : ]                      [:Satış]                       [kalem: SatışKalemi]
    │                            │                                    │
    │── ürünSil(ürün : Ürün) ───>│                                    │
    │                            │──┐ satışKalemiAra(ürün : Ürün)     │
    │                            │<─┘                                 │
    │                            │──┐ [kalem == null] return;         │
    │                            │<─┘                                 │
    │                            │── ürünüBirEksilt() ───────────────>│
    │                            │< - - - - - - - - - - - - - - - - - │
    │                            │── getAdet() ──────────────────────>│
    │                            │< - - - - - - adet - - - - - - - - -│
    │                            │──┐ [adet==0]                       │
    │                            │  │ «kalemi listeden sil»           │
    │                            │<─┘                                 │
```

#### 3. `toplamBedelHesapla()` Sıralama Şeması (ekrandan, 02:09:25)

```text
  [ : ]                  [:Kasa]                 [mevcutSatış]          [:SatışKalemi]          [:Ürün]
    │                       │                          │                       │                   │
    │── toplamBedelHesapla()│                          │                       │                   │
    │──────────────────────>│── toplamBedelHesapla() ─>│                       │                   │
    │                       │                          │── * bedelHesapla() ──>│                   │
    │                       │                          │                       │── getFiyat() ────>│
    │                       │                          │                       │< - - fiyat - - - -│
    │                       │                          │< - toplam +=          │                   │
    │                       │                          │    adet * fiyat - - - │                   │
    │                       │< - - - - toplam - - - - -│                       │                   │
```

- `mevcutSatış` nesnesinden `:SatışKalemi` nesnesine giden çağrının başındaki **`*`** işareti (`* bedelHesapla()`), bu çağrının listedeki tüm satış kalemleri için bir `for` döngüsü içinde tekrarlandığını (çokluk) gösterir; `toplam = 0` gibi ilkel değişken ilklemeleri ise sıralama şemasında gösterilmez (ekrandan, 02:09:25).

## 3. Yazılım Kalitesi ve Yazılım Ölçütlerine (Software Metrics) Giriş

Dersin son bölümünde **Yazılım Kalitesi ve Yazılım Ölçütleri** konusuna giriş yapılmıştır. Kalite kavramı farklı paydaşlar için farklı anlamlar taşıdığından, yazılım kalitesini öznel (*subjektif*) görüşlerden kurtarıp nesnel (*objektif*) olarak değerlendirebilmek için mutlaka **ölçme** etkinlikleri yapılmalıdır (ekrandan, 02:30:00).

### 3.1 Ölçme (Measuring), Ölçüt (Metric) ve Ölçüm (Measurement) Kavramları

1. **Ölçme (*Measuring*):** Somut veya soyut bir varlığın sahip olduğu bir özelliğini **sayısal** veya **derecelendirilmiş** bir veri olarak ifade etme eylemidir (ekrandan, 02:30:00).
   - *Örnekler:* Bir insanın boyunun santimetre cinsinden ifade edilmesi veya *"Hava bugün 22 santigrat derecedir"* cümlesi somut varlıkların **sayısal** verilerle ölçülmesidir; *"İlk ara sınav çok zordu"* (veya *"Sevgi zor iştir"*) ifadesi ise *çok kolay, kolay, normal, zor, çok zor* şeklindeki 5 dereceli bir skala üzerinden **derecelendirilmiş** veriyle ölçmedir (ekrandan, 02:30:00).
2. **Ölçüt (*Metric*):** Varlığın ölçülecek özelliğini **ölçme biçimidir** (ekrandan, 02:30:00).
   - *Örnek 1 (Birim Farkı):* Boyu santimetre, metre, *feet/inch* veya karış ile ölçmek; sıcaklığı Santigrat ($^\circ\text{C}$) veya Fahrenheit ($^\circ\text{F}$) ile ölçmek (örneğin `22` sayısı Santigrat ölçeğinde ılık bir havayı gösterirken, Fahrenheit ölçeğinde sıfırın altında çok soğuk bir havayı gösterir).
   - *Örnek 2 (Yöntem Farkı — Şehir Izgarası / Labirent Uzaklığı):* Cetvelle çizilmiş gibi ızgara planlı bir şehirde A binasından 2 blok yatay, 2 blok dikey uzaklıktaki B binasına gitmek istediğimizde ölçü birimimiz **blok** olsa bile iki farklı ölçme biçimi (ölçüt) tanımlanabilir (ekrandan, 02:30:00):
     - **Sokakları (Blokları) Takip Eden Mesafe:** Yürüyerek veya araçla binaların etrafından dolaşıldığında $2 + 2 = 4\text{ blok}$ yol gidilir.
     - **Kuş Uçuşu Mesafe (Pisagor Teoreminden):** Helikopterle doğrudan A'dan B'ye uçulduğunda Pisagor teoreminden $\sqrt{2^2 + 2^2} = \sqrt{4 + 4} = \sqrt{8} \approx 2{,}83 \approx 3\text{ blok}$ yol gidilir.
     - Daha önce işlenen **bağlaşım (*coupling*)** ve **uyum (*cohesion*)** hesaplarında da dolaylı ilişkilerin hesaba katılıp katılmamasına göre iki farklı ölçüt tanımlanması bunun yazılım tasarımındaki karşılığıdır.

> **Ders sonrası not:** Slayt 108'de *"Mesafe ölçütleri: Bir labirentteki Öklid ölçütü (Pisagor teoreminden) ve kuş uçuşu ölçütü"* yazmakta olup hoca da anlatım sırasında Pisagor teoremiyle hesaplanan uzaklığa mı yoksa blokları takip eden uzaklığa mı Öklid dendiğinde tereddüt etmiştir (ekrandan, 02:30:00). Matematikte Pisagor teoremiyle hesaplanan doğrusal ($\sqrt{\Delta x^2 + \Delta y^2}$) kuş uçuşu uzaklık **Öklid uzaklığı (*Euclidean distance*)**, ızgara/labirent blokları boyunca dik açılarla alınan ($|\Delta x| + |\Delta y|$) uzaklık ise **Manhattan (şehir bloğu / *city-block* veya *taxicab*) uzaklığı**dır.

3. **Ölçüm (*Measurement*):** Belli bir ölçüte göre yapılan ölçme eyleminin **sonucudur** (ekrandan, 02:30:00).
   - Türkçede *ölçme* (eylem), *ölçüt* (ölçme biçimi/kriteri) ve *ölçüm* (sonuç isim) kelimeleri birbirine çok benzediği için günlük kullanımda sıkça karıştırılır; İngilizcede ise `-ing` ve `-ment` son ekleriyle *Measuring*, *Metric* ve *Measurement* olarak ayrılır (ekrandan, 02:30:00).

### 3.2 Yorumlama Engeli (Intelligence Barrier)

Gerçek dünyayla ilgili işimize yarayacak **anlamlı sonuçlar (bilgi)** elde etmek için ölçme yaparız; ancak ölçmenin sonucu aradığımız bilgiye ulaşmak için her zaman doğrudan bir yol sunmayabilir ya da yapılacak yorumlama çok zor olabilir. Buna **Yorumlama Engeli (*Intelligence Barrier*)** adı verilir (hoca *Intelligence Barrier* terimini birebir *"zeka engeli"* diye çevirmenin yanlış anlaşılacağını belirterek Türkçeye **"yorumlama engeli"** olarak çevirmiştir) (ekrandan, 02:40:00).

- ***Otostopçunun Galaksi Rehberi* Örneği:** Douglas Adams'ın ünlü bilimkurgu serisinde, gelişmiş bir uygarlık evrendeki en güçlü süper bilgisayarı inşa edip ona *"Hayatın anlamı nedir?"* sorusunu sorar. Bilgisayar uzun süre çalıştıktan sonra **`42`** yanıtını üretir; ancak `42` sayısının ne anlama geldiğini kimse yorumlayamaz (ekrandan, 02:40:00).
- **Yorumlama Engelini Aşma Akışı (Slayt 109) (ekrandan, 02:40:00):**
  - Yüksekteki bir projeksiyon düğmesine basmak için iki kalemin boyunu karşılaştırıp uzun olanı seçmek veya kapı kapanmasın diye kalın kalemi seçmek gibi çok basit problemlerde doğrudan sonuca ulaşılabilir; ancak yazılım kalitesi ve proje yönetimi gibi karmaşık problemlerde **Soyut veya somut varlıklardan** doğrudan **Anlamlı sonuçlara** inen yol **Yorumlama engeli** tarafından kesilmiştir:

```text
  +-----------------------+       ölçme        +-------------------------------+
  |      Soyut veya       | -----------------> |    Veriler (Sayısal veya      |
  |    somut varlıklar    |                    |      derecelendirilmiş)       |
  +-----------------------+                    +-------------------------------+
              |                                                |
     ==================                                        | matematik,
     | Yorumlama engeli|                                       | istatistik
     ==================                                        v
              v                                     +---------------------+
  +-----------------------+       yorumlama         |   Sayısal sonuçlar  |
  |    Anlamlı sonuçlar   | <---------------------- |                     |
  +-----------------------+                         +---------------------+
```

### 3.3 Yazılım Ölçümü Biçimleri: Doğrudan ve Dolaylı Ölçümler

Yazılımı hem **ürün kalitesini değerlendirmek** hem de **proje yönetimi** (yapılacak işin büyüklüğünü, kaç adam-ay çaba gerektiğini, projenin yüzde kaçının tamamlandığını ve takvimden sapma riskini belirlemek) amacıyla ölçeriz. Yazılımda iki temel ölçüm biçimi vardır (ekrandan, 02:50:15):

1. **Doğrudan Ölçümler:** Başka bir değişkene bağlı olmadan doğrudan sayılabilen veya ölçülebilen niceliklerdir:
   - **Gider (*Cost*):** Yazılımın maliyeti.
   - **Süre:** Yazılımın tamamlanma süresi.
   - **Komut satırı (*Lines of Code*):** Yazılan toplam kod satırı sayısı (proje bittikten sonra doğrudan sayılır; proje başında tahmin edilmesi ise gelecek derste işlenecek yöntemlerle yapılır).
   - **Hız:** Belirli bir metodun belirli bir donanımda kaç milisaniyede çalıştığı.
   - **Bellek / Bant genişliği:** İhtiyaç duyulan MB/GB bellek miktarı.
   - **Hata miktarı:** Belirli bir aşamaya kadar ortaya çıkan toplam yazılım hatası sayısı (ciddiyet derecelerine göre alt kırılımlara da ayrılabilir) (ekrandan, 02:50:15).
2. **Dolaylı Ölçümler:** Doğrudan tek bir sayısal birimi olmayan, çalışma ortamına, sürece veya başka değişkenlere bağlı olarak dolaylı yoldan değerlendirilen özelliklerdir:
   - **İşlev (*Functionality*):** Yazılımın sahip olacağı işlevler (*use case*'ler ile modellenir; ancak çevik süreçlerde 3 haftalık küçük *use case*'ler yazılırken ardışık/şelale süreçlerde çok büyük *use case*'ler yazılabildiği için tek başına *use case* sayısı sabit bir birim değildir).
   - **Nitelik (*Quality*) ve Karmaşıklık (*Complexity*):** Neye göre karmaşık olduğu farklı yorumlanabildiğinden dolaylı ölçüttür.
   - **Etkinlik (*Efficiency*):** Sistem kaynaklarını mümkün olduğunca az ve verimli kullanmaktır. Örneğin en optimal algoritmayı yazmış olsak bile algoritma 2 GB bellek gerektiriyorsa, 1 GB RAM'e sahip küçük bir bilgisayarda (ör. *Raspberry Pi*) işletim sistemi diski sanal bellek olarak kullanacağı (*paging* / sayfalama yapacağı) için disk erişimi yüzünden yavaş çalışacak, 4 GB RAM'li bilgisayarda ise hızlı çalışacaktır.
   - **Güvenirlik (*Reliability*) ve Dayanıklılık (*Robustness*):** Olası hatalı veri girişlerine rağmen sistemin çökmeden çalışmaya devam edebilmesidir; girdi veri kümesine göre değiştiği için dolaylı ölçüttür (ekrandan, 02:50:15).

### 3.4 Doğrudan Ölçülen Niceliklerden Tanımlanan Temel Ölçütler (LOC ve KLOC Formülleri)

Ortak amacımız yazılımda **verimlilik, kalite, gider ve belgelemenin** hesaplanmasıdır. Kod satırı sayısı (**LOC — *Line of Code***) büyük projelerde bin satır (**KLOC — *Kilo Line of Code***) birimiyle ifade edilir ve temel ölçütler yazılım hacmine (`KLOC`) bölünerek normalize edilir (ekrandan, 02:50:15):

$$\text{LOC} = \text{Line of Code (Kod satırı sayısı)}$$
$$\text{KLOC} = 1000 \times \text{LOC} \quad (\text{K: Kilo})$$

1. **Verimlilik Ölçütü:**
   $$\text{Verimlilik} = \frac{\text{KLOC}}{\text{kişi} \times \text{ay}}$$
   - Yazılımın toplam büyüklüğünün (`KLOC`), projede çalışan kişi sayısı ile proje süresinin (ay) çarpımına (yani toplam **kişi-ay / adam-ay** çabaya) oranıdır; birim kişi-ay başına üretilen kod hacmi arttıkça verimlilik yüksek kabul edilir (ekrandan, 02:50:15).
2. **Kalite Ölçütü (Birim Hacim Başına Hata Oranı):**
   $$\text{Kalite} = \frac{\text{Hata}}{\text{KLOC}}$$
   - Belirli bir $T$ anına (örneğin yazılım tesliminden sonraki ilk 6 aya) kadar ortaya çıkan toplam hata sayısının yazılım hacmine (`KLOC`) oranıdır.
   - *Sayısal Yorumlama Örneği:* Bir yazılımın eski versiyonunda ilk 6 ayda **`200` hata**, yeni versiyonunda ise ilk 6 ayda **`100` hata** çıkmış olsun. Yalnızca hata sayılarına bakılırsa yeni versiyon iki kat daha iyi görünür; ancak yeni versiyon eski versiyonun **dörtte biri ($1/4$) kadar kod (`KLOC`)** içeriyorsa, birim kod başına düşen hata yoğunluğu yeni versiyonda aslında iki katına çıkmıştır ($\frac{100}{0{,}25 \cdot X} = \frac{400}{X} > \frac{200}{X}$) ve yeni versiyonun kalitesi düşmüştür (ekrandan, 02:50:15).
3. **Gider Ölçütü:**
   $$\text{Gider} = \frac{\text{Toplam gider}}{\text{KLOC}}$$
   - Örneğin yazılımın yeni versiyonu eski versiyona göre `%15` daha pahalıya mal olmuşsa, ancak kod hacmi (`KLOC`) eski versiyonun **2 katı** ise birim KLOC başına maliyet düşmüştür ve gider açısından başarılı bir sonuç elde edilmiştir (ekrandan, 02:50:15).
4. **Belgeleme Ölçütü (Belgeleme Yeterliliği):**
   $$\text{Belgeleme} = \frac{\text{Belge sayfası}}{\text{KLOC}}$$
   - Hoca ilk başta bunu "belgeleme maliyeti" diye ağzından kaçırmış, hemen ardından düzelterek bu ölçütün **belgelemenin ne kadar yeterli olduğunu** ölçtüğünü vurgulamıştır.
   - *Sayısal Yorumlama Örneği:* Eski versiyonda belirli bir kod hacmi için **`500` sayfa** belgelendirme varken, yeni versiyonda **`600` sayfa** belgelendirme üretilmiş olsun. Sayfa sayısı artmış görünse de eğer yeni versiyon eski versiyondan **5 kat daha geniş (`5x KLOC`)** bir yazılımsa, birim kod başına düşen belge sayfası oranı ciddi biçimde azalmıştır; bu durum bakım masraflarını artıracağı için proje yöneticisinin belgelendirme çalışmalarına ek personel (ör. 2–3 kişi) yönlendirmesi gerekir (ekrandan, 02:50:15).

## Örnek Sorular

### Soru 1: Kasa Durum Şemasında Aynı Olayın Farklı Durumlardaki Etkisi ve Bitiş Durumu (derste sözlü ve ekrandan, 00:20:06; 00:28:34; 00:36:15)

**Soru:** *NextGenPOS* yazar kasa durum şemasında:
a) `«M»Barkod girişi/` olayı şemada hangi iki durum geçişinde yer alır ve neden ikisine farklı olay adları verilmez?
b) Kasiyerin *login* olma durumu şemada ayrı bir durum (`Satış bekleme`) olarak çizilmezse, `Boşta bekleme` durumundan `Satış kaydetme` durumuna geçişte kullanım senaryosu ön koşulu nasıl gösterilir?
c) Durum şemasının sonlanması (*scenario end*) hangi durumlardan ve hangi olayla gerçekleşir?

**Çözüm (derste verilen):**
- **a)** `«M»Barkod girişi/` olayı hem `Satış kaydetme` durumunun kendi üzerindeki öz geçişte (*self-transition* — okutulan ürünü satışa ekleyip aynı durumda kalma) hem de `Satıştan bir ürün silme` durumundan `Satış kaydetme` durumuna geri dönüş geçişinde (okutulan tek ürünü satıştan silip normal kayıt moduna dönme) yer alır. Fiziksel olay her iki durumda da barkod okuyucudan barkod okutulması olduğu için aynı olay adı korunur; fark olayın adında değil, kasanın o an bulunduğu başlangıç ve bitiş durumlarındadır (ekrandan, 00:30:00).
- **b)** `Boşta bekleme` durumundan `Satış kaydetme` durumuna giden `«M»Satış başlatma` olayının yanına köşeli parantez içinde bir koruma koşulu (*guard condition*) eklenir: **`«M»Satış başlatma [kasiyer login olmuş ise]/`** (ekrandan, 00:36:15).
- **c)** Kasa hem henüz kasiyer giriş yapmamışken (`Boşta bekleme`) hem de kasiyer giriş yapmış yeni müşteri beklerken (`Satış bekleme`) kapatılabileceği için her iki durumdan da bitiş düğümüne (`◉`) giden **`«M»Güç kapandı/`** (veya `«M»Kapatma düğmesine basıldı /`) geçişi çizilir (ekrandan, 00:36:15).

### Soru 2: Sıralama Şemasında `ürünSil(ürün: Ürün)` Akışı ve `0` Adetli Kalemin Silinmesi (derste sözlü ve ekrandan, 01:47:26; 01:49:35)

**Soru:** Bir satıştan ürün silinirken (`ürünSil(ürün: Ürün)`), ürünün miktarı `1` azaltıldıktan sonra miktar `0`'a düşerse bu `SatışKalemi` nesnesini listeden silme işlemini neden `SatışKalemi` nesnesinin kendisi yapamaz ve bu işlem sıralama şemasında nasıl modellenir?

**Çözüm (derste verilen):**
- Tasarım sınıf şemasında `Satış` sınıfından `SatışKalemi` sınıfına doğru `1`'e `1..*` parça-bütün oku vardır (`Satış` sınıfı `- satışKalemleri: LinkedList<SatışKalemi>` listesini tutar), ancak `SatışKalemi` sınıfından `Satış` sınıfına doğru ters yönde bir referans oku yoktur. Dolayısıyla `SatışKalemi` hangi `Satış` nesnesinin listesinde bulunduğunu bilmez ve kendi kendini listeden silemez.
- Bu nedenle `:Satış` nesnesi, `kalem: SatışKalemi` üzerinde önce `ürünüBirEksilt()` metodunu, hemen ardından `getAdet()` metodunu çağırır; dönen `adet` değerini kontrol ederek **`[adet == 0]` ise `«kalemi listeden sil»`** işlemini kendi üzerinde yürütür (ekrandan, 01:49:35).

### Soru 3: Kalite ve Belgeleme Ölçütlerinin Versiyonlar Arası Karşılaştırılması (derste sözlü ve ekrandan, 02:50:15)

**Soru:** Bir yazılımın 1. versiyonu ile 2. versiyonu karşılaştırılırken:
a) İlk 6 ayda 1. versiyonda `200` hata, 2. versiyonda ise `100` hata tespit edilmiştir. Ancak 2. versiyonun kod satırı sayısı (`KLOC`), 1. versiyonun dörtte biri ($1/4$) kadardır. Kalite ölçütüne ($\text{Kalite} = \text{Hata} / \text{KLOC}$) göre hangi versiyon daha kalitelidir?
b) 1. versiyonda `500` sayfa, 2. versiyonda ise `600` sayfa belgelendirme yapılmıştır; ancak 2. versiyonun kod hacmi (`KLOC`) 1. versiyonun `5` katıdır. Belgeleme ölçütüne ($\text{Belgeleme} = \text{Belge sayfası} / \text{KLOC}$) göre 2. versiyonun durumu nedir?

**Çözüm (derste verilen):**
- **a)** 1. versiyonun hacmine $V\text{ KLOC}$ dersek, 1. versiyonun hata yoğunluğu $\frac{200}{V}\text{ hata/KLOC}$ iken, 2. versiyonun hacmi $0{,}25\,V\text{ KLOC}$ olduğundan hata yoğunluğu $\frac{100}{0{,}25\,V} = \frac{400}{V}\text{ hata/KLOC}$ olur. Dolayısıyla mutlak hata sayısı yarıya inmiş görünse de birim kod başına düşen hata sayısı iki katına çıktığı için **2. versiyonun kalitesi 1. versiyona göre daha düşüktür** (ekrandan, 02:50:15).
- **b)** 1. versiyonda birim hacim başına belgeleme $\frac{500}{V}\text{ sayfa/KLOC}$ iken, $5V\text{ KLOC}$ hacmindeki 2. versiyonda $\frac{600}{5V} = \frac{120}{V}\text{ sayfa/KLOC}$ düzeyine düşmüştür. Toplam sayfa sayısı `500`'den `600`'e çıkmış olsa bile yazılım 5 kat büyüdüğü için **2. versiyonun belgelemesi yetersiz kalmıştır** ve bakım maliyetlerini artırmaması için belgelendirmeye ek kaynak ayrılmalıdır (ekrandan, 02:50:15).

## Dersin Toparlaması

Bu derste ilk olarak *NextGenPOS* yazar kasa senaryosunun tasarım modeli kapsamında **`Kasa` varlığı için UML Durum Şeması (*State Diagram*)** çizilmiş; durumların karşılıklı dışlamalı olduğu, pasif bekleyiş dışında aktif çalışma modlarını da temsil edebildiği, aynı olayın (`«M»Barkod girişi/`) farklı durumlarda farklı geçişlere yol açabileceği ve şemada mutlaka bir sonlanma durumu (`◉`) bulunması gerektiği gösterilmiştir. İkinci adımda analiz aşamasındaki metotsuz alan modeli; koleksiyon yapıları (`LinkedList`), kurucular, aşırı yüklenmiş (*overloaded*) `barkodGir` metotları, sorumlulukların bilgi uzmanına (`Satış`) atanması ve `barkodGir`, `ürünSil`, `toplamBedelHesapla` işlemleri için çizilen **UML Sıralama Şemaları (*Sequence Diagrams*)** ile tam bir **Tasarım Sınıf Şemasına (*Design Class Diagram*)** dönüştürülmüştür.

Dersin son bölümünde **Yazılım Kalitesi ve Yazılım Ölçütleri** konusuna giriş yapılarak **ölçme (*measuring*), ölçüt (*metric*) ve ölçüm (*measurement*)** kavramları, karmaşık sistemlerde doğrudan anlamlı sonuçlara ulaşmayı zorlaştıran **Yorumlama Engeli (*Intelligence Barrier*)**, yazılımda **doğrudan ve dolaylı ölçümler** ile **LOC / KLOC** tabanlı **verimlilik, kalite, gider ve belgeleme** ölçütleri incelenmiştir. Gelecek derste (Slayt 112'den itibaren) hesaplanması daha ayrıntılı olan diğer yazılım ölçütleri ile devam edilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
