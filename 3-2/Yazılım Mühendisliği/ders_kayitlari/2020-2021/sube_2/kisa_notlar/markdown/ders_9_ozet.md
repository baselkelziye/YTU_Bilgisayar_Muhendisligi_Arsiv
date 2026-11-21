# Ders 9 Çalışma Özeti

## Genel Konular

- NextGenPOS Tasarım Modeli: Kasa İçin UML Durum Şeması (*State Diagram*) Tasarımı
  - Kullanım senaryosu (*use case*) metnindeki ana öykü ve alternatif akışlar üzerinden sistemin odak varlığı olan **`Kasa`** nesnesinin durumlarının (*states*) ve durum geçişlerini tetikleyen olayların (*events*) belirlenmesi (ekrandan, 00:30:00; ekrandan, 00:36:15).
  - Durumların karşılıklı dışlamalı (*mutually exclusive*) olması ilkesi: bir varlığın aynı anda yalnızca tek bir durumda bulunabilmesi ve bir durumun her zaman pasif bekleyiş anlamına gelmeyip bir olay gerçekleşene kadar bölünmeden süren aktif bir etkinliği (ör. `Satış kaydetme`, `Harici sistemlere bilgi aktarımı`, `Fiş verme`) de temsil edebilmesi.
  - Canlı çizilen durum şeması ile ders notlarındaki durum şemasının karşılaştırılması: `Boşta bekleme` ve `Satış bekleme` durumlarını ayırma veya tek bir `Boşta bekleme` durumundan `[kasiyer login olmuş ise]` koruma koşuluyla (*guard condition*) `«M»Satış başlatıldı /` geçişi yapma; olay geçişlerinde `/` sonrasına durum bayraklarını güncelleyen eylemlerin (`bostaBekleme = true; satisBekleme = false;`) eklenmesi (ekrandan, 00:36:15).
- Alan Modelinden Tasarım Sınıf Şemasına (*Design Class Diagram*) ve Sıralama Şemalarına (*Sequence Diagrams*) Geçiş
  - Analiz aşamasında oluşturulan metotsuz **Alan Modelinin (*Domain Model*)**, kullanım senaryosu adımlarını gerçekleyecek metotlar, erişim belirleyicileri (`+`/`-`), koleksiyon veri yapıları (`LinkedList<Satış>`, `LinkedList<SatışKalemi>` veya `Vector<SatisKalemi>`), kurucu metotlar (*constructors*) ve durum/referans üye alanları (`mevcutSatış: Satış`, `bostaBekleme: boolean`, `satisBekleme: boolean`) ile zenginleştirilerek **Tasarım Sınıf Şemasına** dönüştürülmesi (ekrandan, 02:20:00; ekrandan, 02:21:35).
  - Karmaşık metotların iç işleyişini ve nesneler arası mesajlaşmayı kesinleştirmek amacıyla üç temel senaryo adımı için **UML Sıralama Şeması (*Sequence Diagram*)** çizilmesi:
    1. **`barkodGir(barkod: String)` Sıralama Şeması:** Kasanın `şube: Şube` nesnesinden `ürünSorgula(barkod: String)` ile ürünü sorgulaması, `[ürün == null]` ise `uyarıVer(); return false;` çalıştırması, ürün geçerliyse `mevcutSatış`'ın `ürünEkle(ürün, 1)` metodunu çağırması ve `mevcutSatış`'ın `new(ürün, adet)` ile `:SatışKalemi` oluşturması (ekrandan, 01:35:25).
    2. **`ürünSil(ürün: Ürün)` Sıralama Şeması:** `:Satış` nesnesinin kendi içinde `satışKalemiAra(ürün: Ürün)` çağırması, `[kalem == null] return;` kontrolü, bulunan `kalem: SatışKalemi` üzerinde `ürünüBirEksilt()` ve `getAdet()` çağırması, `[adet == 0]` ise `«kalemi listeden sil»` işlemini yürütmesi (ekrandan, 01:49:35).
    3. **`toplamBedelHesapla()` Sıralama Şeması:** `:Kasa` $\rightarrow$ `mevcutSatış.toplamBedelHesapla()` $\rightarrow$ tüm `:SatışKalemi` nesneleri üzerinde döngüyle `* bedelHesapla()` $\rightarrow$ `:Ürün.getFiyat()` çağrısı ve `toplam += adet * fiyat` kümülatif toplamının hesaplanıp döndürülmesi (ekrandan, 02:09:25).
- Yazılım Kalitesi ve Yazılım Ölçütlerine (*Software Metrics*) Giriş
  - **Ölçme (*Measuring*)**, **Ölçüt (*Metric*)** ve **Ölçüm (*Measurement*)** kavramlarının tanımları, sayısal ve derecelendirilmiş veriler, mesafe ölçütleri örneği (blok/şehir içi yürüme mesafesi vs. Pisagor teoremiyle kuş uçuşu mesafe) (ekrandan, 02:30:00).
  - **Yorumlama Engeli (*Intelligence Barrier*):** Soyut veya somut varlıklardan doğrudan anlamlı sonuçlara ulaşmayı engelleyen yorumlama zorluğu (*Otostopçunun Galaksi Rehberi*'ndeki `42` örneği) ve bu engelin **Ölçme $\rightarrow$ Veriler $\rightarrow$ Matematik/İstatistik $\rightarrow$ Sayısal Sonuçlar $\rightarrow$ Yorumlama $\rightarrow$ Anlamlı Sonuçlar** dolaylı yoluyla aşılması (ekrandan, 02:40:00).
  - Yazılımda **Doğrudan Ölçümler** (*gider, süre, komut satırı, hız, bellek genişliği, hata miktarı*) ve **Dolaylı Ölçümler** (*işlev, nitelik, karmaşıklık, etkinlik, güvenirlik, dayanıklılık*); **LOC** (*Line of Code*) ve **KLOC** ($1000 \times \text{LOC}$) tabanlı temel ölçütler: **Verimlilik**, **Kalite**, **Gider** ve **Belgeleme** (ekrandan, 02:50:15).

## Hocanın Özellikle Vurguladığı Kısımlar

- Durum Şemasında Durum (*State*) ile Olay (*Event*) Ayrımı ve Sonlanma Durumu
  - Durum şeması çizerken en sık yapılan hata neyin **durum**, neyin **olay (geçiş)** olduğunun karıştırılmasıdır; önce odak varlığın (`Kasa`) durumları belirlenmeli, ardından bu durumlar arasındaki geçişleri tetikleyen olaylar (`«M».../`) yerleştirilmelidir.
  - Aynı olay (örneğin `«M»Barkod girişi/`) kasanın o an bulunduğu duruma göre farklı geçişlere yol açabilir: kasa `Satış kaydetme` durumundayken `«M»Barkod girişi/` olayı yeni ürünü satışa ekleyip kasanın yine `Satış kaydetme` durumunda kalmasını (öz geçiş / *self-transition*) sağlarken, kasa `Satıştan bir ürün silme` durumundayken aynı `«M»Barkod girişi/` olayı okutulan ürünü silip kasanın `Satış kaydetme` durumuna dönmesini sağlar. Aynı olay için farklı isimler uydurulmamalı, aynı olay adı kullanılmalıdır (ekrandan, 00:30:00).
  - Hiçbir sistem sonsuza dek açık kalmayacağı için durum şemasında mutlaka bir **bitiş durumu (*scenario end*)** bulunmalı ve uygun bekleme durumlarından `«M»Güç kapandı/` (veya `«M»Kapatma düğmesine basıldı /`) olayıyla bitiş durumuna geçiş gösterilmelidir (ekrandan, 00:36:15).
- Tasarım Sınıf Şemasında Böl-Parçala-Yönet, Sorumluluk Atama (Bilgi Uzmanı) ve Kendi Kendini Belgeleyen Kod
  - Metotlar aşırı uzun ve karmaşık kodlanmamalı, alt iş adımları ayrı metotlara bölünmelidir; ancak tek satırlık bir kurucu çağrısı (`new SatışKalemi(ürün, adet)`) için gereksiz sarmalayıcı metot açılmasına da gerek yoktur.
  - **Sorumluluğun Bilgiye Sahip Olana Verilmesi (Uyum / *Cohesion*):** Bir sorumluluk, o iş için gereken veriyi bünyesinde barındıran sınıfa atanmalıdır. Örneğin satış kalemlerini oluşturma ve tutma sorumluluğu `Kasa` yerine `Satış` sınıfına (`ürünEkle`); fişin gövde metnini (kalemlerin dökümünü) hazırlama sorumluluğu da `LinkedList<SatışKalemi>` listesini dışarıya açmak yerine `Satış` sınıfındaki `+ getFişGövdeMetni(): String` metoduna verilmelidir (ekrandan, 02:21:35).
  - Şemalara karmaşık açıklama notları (*annotation*) eklemek yerine metotlara ne iş yaptığını doğrudan anlatan isimler (örneğin `ürünAzalt` + açıklayıcı not yerine doğrudan **`ürünüBirEksilt()`**) verilerek kendi kendini belgeleyen (*self-documenting*) tasarım yapılmalıdır (ekrandan, 01:49:35).
- Yazılım Ölçütlerinin Tek Başına Değil, Hacimle (`KLOC`) Normalize Edilerek Yorumlanması
  - Bir yazılımın yeni sürümünde çıkan toplam hata sayısının (ör. `100 hata`), eski sürümdeki hata sayısından (`200 hata`) az olması yeni sürümün daha kaliteli olduğunu tek başına kanıtlamaz; eğer yeni sürüm eski sürümün dörtte biri kadar kod (`KLOC`) içeriyorsa birim kod başına hata oranı ($\text{Kalite} = \text{Hata} / \text{KLOC}$) yükselmiş, yani kalite düşmüştür. Benzer şekilde toplam gider ve belge sayfası sayısı da mutlaka yazılım hacmine (`KLOC`) bölünerek değerlendirilmelidir (ekrandan, 02:50:15).

## Kısa Tekrar Notları

- **Violet UML'de `«M»` stereotipi ipucu:** Durum şemasında olay oklarına `«M»` (mesaj/olay) stereotipi yazmak için geçici bir sınıf şemasında `«interface»` oluşturup `«»` guillemet karakterleri panoya kopyalanabilir (ekrandan, 00:30:00).
- **Durum şemasında etiketsiz ok:** İki durum arasındaki geçiş okunun üzerinde hiçbir olay yazmıyorsa (`Harici sistemlere bilgi aktarımı` $\rightarrow$ `Fiş verme` $\rightarrow$ `Satış bekleme`), kaynak durumdaki etkinlik tamamlanır tamamlanmaz dış bir olay beklenmeden **otomatik geçiş (*triggerless transition*)** yapıldığı anlamına gelir (ekrandan, 00:30:00).
- **Barkod veri tipi seçimi:** Barkodlar yalnız rakamlardan oluşsa bile `0` ile başlayabileceği veya ISBN/ISSN benzeri kodlarda `X` gibi alfanümerik karakterler içerebileceği için `int` yerine **`String`** olarak modellenir (ekrandan, 02:20:00).
- **Aynı üründen birden fazla alınması:** Kasiyerin `3 x` tuşlayıp barkodu bir kez okutması aşırı yüklenmiş (*overloaded*) `+ barkodGir(barkod: String, adet: int): boolean` metoduyla; aynı ürünü farklı anlarda tek tek okutması ise `+ barkodGir(barkod: String): boolean` metoduyla modellenir. Performans kararı olarak her tekil okutmada mevcut kalem listesini baştan sona aramak yerine yeni bir `SatışKalemi` nesnesi eklenmesi tercih edilmiştir (ekrandan, 01:35:25; ekrandan, 02:20:00).
- **Ölçme – Ölçüt – Ölçüm üçlüsü (ekrandan, 02:30:00):**
  - **Ölçme (*Measuring*):** Varlığın bir özelliğini sayısal veya derecelendirilmiş veri olarak ifade etme eylemi.
  - **Ölçüt (*Metric*):** Özelliği ölçme biçimi / birimi (ör. santimetre, Fahrenheit, blok mesafesi, kuş uçuşu mesafe).
  - **Ölçüm (*Measurement*):** Belli bir ölçüte göre yapılan ölçme eyleminin sonucu.
- **Doğrudan ölçüt formülleri (ekrandan, 02:50:15):**
  - $\text{LOC} = \text{Line of Code (Kod satırı sayısı)}$, $\quad \text{KLOC} = 1000 \times \text{LOC}$
  - $\text{Verimlilik} = \dfrac{\text{KLOC}}{\text{kişi} \times \text{ay}}$, $\quad \text{Kalite} = \dfrac{\text{Hata}}{\text{KLOC}}$, $\quad \text{Gider} = \dfrac{\text{Toplam gider}}{\text{KLOC}}$, $\quad \text{Belgeleme} = \dfrac{\text{Belge sayfası}}{\text{KLOC}}$

## Detaylı Açıklamalar

### 1. NextGenPOS Kasa Durum Şeması (State Diagram)

NextGenPOS yazar kasa sisteminde uygulama mantığı ağırlıklı olarak `Kasa` varlığı üzerinde çalıştığı için durum şeması **`Kasa`** nesnesi için çizilmiştir.

**Canlı Derste Çizilen Durum Şeması (`NextGenPosKasa.state.violet`) (ekrandan, 00:30:00; ekrandan, 00:36:15):**

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

- **Ders Notlarındaki Şema ile Farklar (ekrandan, 00:36:15):**
  1. Ders notlarındaki şemada `Kasiyer login` durumu ayrı bir durum olarak çizilmemiş; `Boşta bekleme` durumundan `Satış kaydetme` durumuna geçerken koruma koşulu (*guard*) kullanılması önerilmiştir: `«M»Satış başlatma [kasiyer login olmuş ise]/` (ekrandan, 00:36:15).
  2. Ders notlarında `Harici sistemlere bilgi aktarımı` durumu atlanarak `Ödeme bekleme` durumundan `«M»Ödeme alındı /` olayıyla doğrudan `Makbuz verme` durumuna geçilmiştir (ekrandan, 00:36:15).
  3. Tasarım sınıf şemasında `Kasa` sınıfına eklenen `- bostaBekleme: boolean` ve `- satisBekleme: boolean` alanlarının durum geçişlerinde nasıl güncellendiği `/` işaretinden sonra eylem (*action*) olarak belirtilir: `«M»Güç açıldı/` geçişinde `bostaBekleme = true; satisBekleme = false;`, `«M»Kasiyer login/` geçişinde ise `bostaBekleme = false; satisBekleme = true;` atanır.

### 2. Alan Modelinden Tasarım Sınıf Şemasına ve Sıralama Şemalarına Geçiş

Analiz aşamasındaki metotsuz alan modeli, tasarım aşamasında veri yapıları (`LinkedList` / `Vector`), görünürlük belirleyicileri (`+` *public*, `-` *private*) ve kullanım senaryosu adımlarını yürüten metotlarla zenginleştirilmiştir (ekrandan, 02:20:00; ekrandan, 02:21:35):

```text
+---------------------------------------+          +----------------------------------+
|             SatışKalemi               |          |               Ürün               |
+---------------------------------------+  içerir  +----------------------------------+
| - miktar : int                        | 1      1 | - tanim : String                 |
| - ürün : Ürün                         |--------->| - fiyat, kdv : double            |
+---------------------------------------+          | - barkod : String                |
| + SatışKalemi(ürün: Ürün, adet: int)  |          +----------------------------------+
| + getÜrün() : Ürün                    |          | (Tüm üyeleri alan constructor,   |
| + getMiktar() : int                   |          |  tüm getter ve setter'lar)       |
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

- **Ders sonrası not:** Hoca canlı çizimde `SatışKalemi` sınıfına `+ getÜrün()` metodunu eklerken dönüş tipini sehven `+ getÜrün() : int` olarak yazmıştır (ekrandan, 02:20:00; ekrandan, 02:21:35); `ürün` üye alanı `Ürün` tipinde olduğundan ve sağdaki ders notu şemasında da görüldüğü üzere doğrusu `+ getÜrün() : Ürün` olmalıdır.
- **Ders Notlarındaki Tasarım Sınıf Şemasında Ek `Katalog` Sınıfı:** Hoca ders notlarındaki çözümde yüksek uyum (*high cohesion*) sağlamak amacıyla `Şube` ile `Ürün` arasına `Katalog` (`- urunler: HashMap<String, Urun>`, `+ urunBul(barkod: String): Urun`) sınıfını yerleştirmiş, `Şube`'nin `Katalog` ile parça-bütün (`◆`), `Ürün` ile ise kesikli ok (`<<kullanır>>` bağımlılık) ilişkisi kurduğunu göstermiştir.

**Sıralama Şemaları (*Sequence Diagrams*):**
1. **`barkodGir(barkod: String)` Sıralama Şeması (ekrandan, 01:35:25):**
   - Aktör/çağıran $\rightarrow$ `:Kasa` üzerinde `barkodGir(barkod: String)` çağırır.
   - `:Kasa` $\rightarrow$ `şube: Şube` üzerinde `ürünSorgula(barkod: String)` çağırır ve `ürün` referansını alır.
   - `:Kasa` kendi üzerinde `[ürün == null] uyarıVer(); return false;` öz çağrısını (*self-call*) yapar.
   - Ürün `null` değilse `:Kasa` $\rightarrow$ `mevcutSatış` üzerinde `ürünEkle(ürün, 1)` çağırır; `mevcutSatış` da `:SatışKalemi` üzerinde `new(ürün, adet)` kurucusunu çağırarak yeni satış kalemini oluşturur (ekrandan, 01:35:25).
2. **`ürünSil(ürün: Ürün)` Sıralama Şeması (ekrandan, 01:49:35):**
   - Çağıran $\rightarrow$ `:Satış` üzerinde `ürünSil(ürün: Ürün)` çağırır.
   - `:Satış` kendi üzerinde (*self-call*) `satışKalemiAra(ürün: Ürün)` çağırır; ardından `[kalem == null] return;` kontrolünü yapar.
   - Kalem bulunmuşsa `:Satış` $\rightarrow$ `kalem: SatışKalemi` üzerinde önce `ürünüBirEksilt()`, ardından `getAdet()` çağırır ve `adet` değerini alır.
   - `:Satış` kendi üzerinde `[adet==0] «kalemi listeden sil»` işlemini çalıştırır (ekrandan, 01:49:35).
3. **`toplamBedelHesapla()` Sıralama Şeması (ekrandan, 02:09:25):**
   - Çağıran $\rightarrow$ `:Kasa.toplamBedelHesapla()` $\rightarrow$ `mevcutSatış.toplamBedelHesapla()`.
   - `mevcutSatış`, bünyesindeki tüm `:SatışKalemi` nesneleri için döngüsel olarak (`* bedelHesapla()`) çağrı yapar.
   - Her `:SatışKalemi` kendi `:Ürün` nesnesinden `getFiyat()` ile birim `fiyat` değerini alır ve `mevcutSatış`'a `toplam += adet * fiyat` olarak döndürür; `mevcutSatış` da biriken `toplam` değerini `:Kasa`'ya döndürür (ekrandan, 02:09:25).

### 3. Yazılım Kalitesi, Ölçme Kavramları ve Doğrudan/Dolaylı Ölçütler

Kalite kavramını öznel (*subjektif*) yorumlardan kurtarıp nesnel (*objektif*) olarak değerlendirebilmek için ölçme etkinlikleri yapılır (ekrandan, 02:30:00; ekrandan, 02:40:00; ekrandan, 02:50:15):
- **Temel Kavramlar (ekrandan, 02:30:00):**
  - **Ölçme (*Measuring*):** Somut veya soyut bir varlığın sahip olduğu bir özelliğini sayısal (ör. `22 santigrat derece`) veya derecelendirilmiş (ör. `İlk ara sınav çok zordu` — *çok kolay, kolay, normal, zor, çok zor* 5'li skalası) bir veri olarak ifade etmektir.
  - **Ölçüt (*Metric*):** Varlığın ölçülecek özelliğini ölçme biçimidir (ör. sıcaklık için Santigrat ve Fahrenheit; şehir ızgarasında A binasından B binasına giderken blokları takip eden $2 + 2 = 4\text{ blok}$ mesafe ölçütü ile Pisagor teoreminden hesaplanan $\sqrt{2^2 + 2^2} = \sqrt{8} \approx 3\text{ blok}$ kuş uçuşu mesafe ölçütü).
  - **Ders sonrası not:** Slaytta *"Bir labirentteki Öklid ölçütü (Pisagor teoreminden) ve kuş uçuşu ölçütü"* ifadesi yer almakta olup hoca da anlatım sırasında hangisine Öklid dendiğinde tereddüt etmiştir (ekrandan, 02:30:00); matematikte Pisagor teoremiyle hesaplanan doğrusal ($\sqrt{\Delta x^2 + \Delta y^2}$) kuş uçuşu uzaklık **Öklid uzaklığı (*Euclidean distance*)**, ızgara/labirent blokları boyunca dik açılarla gidilen ($|\Delta x| + |\Delta y|$) uzaklık ise **Manhattan (şehir bloğu / *city-block*) uzaklığı**dır.
  - **Ölçüm (*Measurement*):** Belli bir ölçüte göre yapılan ölçme eyleminin sonucudur.
- **Yorumlama Engeli (*Intelligence Barrier*) (ekrandan, 02:40:00):**
  - Ölçmenin sonucu, aradığımız anlamlı sonuçları elde etmek için her zaman doğrudan bir yol sunmayabilir ya da yapılacak yorumlama zor olabilir (Douglas Adams'ın *Otostopçunun Galaksi Rehberi* eserinde süper bilgisayarın *"Hayatın anlamı nedir?"* sorusuna `42` yanıtını üretmesi ancak `42`'nin ne anlama geldiğinin yorumlanamaması örneği).
  - Bu engeli aşmak için **Soyut veya somut varlıklar** doğrudan yorumlanmaya çalışılmaz; önce **ölçme** ile **Veriler (Sayısal veya derecelendirilmiş)** elde edilir, bu veriler **matematik ve istatistik** yöntemleriyle **Sayısal sonuçlara** dönüştürülür ve son aşamada **yorumlama** yapılarak **Anlamlı sonuçlara** ulaşılır (ekrandan, 02:40:00).
- **Yazılım Ölçümü Biçimleri ve Temel Formüller (ekrandan, 02:50:15):**
  1. **Doğrudan Ölçümler:** Gider (*cost*), süre, komut satırı sayısı, hız, bellek/bant genişliği, hata miktarı.
  2. **Dolaylı Ölçümler:** İşlev (ör. *use case* sayısı ve büyüklüğü), nitelik, karmaşıklık, etkinlik (*efficiency* — sistem kaynaklarını az kullanma; ör. 2 GB bellek isteyen algoritmanın 1 GB RAM'li bilgisayarda *paging* yüzünden yavaş çalışması), güvenirlik (*reliability*), dayanıklılık (*robustness* — hatalı girdilere rağmen çökmeden çalışabilme).
  3. **Doğrudan Ölçülen Niceliklerden Tanımlanan Ölçütler (ekrandan, 02:50:15):**
     $$\text{LOC} = \text{Line of Code (Kod satırı sayısı)}, \qquad \text{KLOC} = 1000 \times \text{LOC}$$
     $$\text{Verimlilik} = \frac{\text{KLOC}}{\text{kişi} \times \text{ay}}, \qquad \text{Kalite} = \frac{\text{Hata}}{\text{KLOC}}, \qquad \text{Gider} = \frac{\text{Toplam gider}}{\text{KLOC}}, \qquad \text{Belgeleme} = \frac{\text{Belge sayfası}}{\text{KLOC}}$$

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
